/*
  Structures for generic tests.
*/
typedef struct collection_st collection_st;
typedef struct test_st test_st;

struct test_st {
  char *name;
  unsigned int requires_flush;
  void (*function)(memcached_st *memc);
};

struct collection_st {
  char *name;
  memcached_return (*pre)(memcached_st *memc);
  memcached_return (*post)(memcached_st *memc);
  test_st *tests;
};

/* How we make all of this work :) */
collection_st *gets_collections(void);