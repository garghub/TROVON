static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
* ( V_5 * ) & V_4 -> V_6 [ 0 ] = 0x6a09e667f3bcc908ULL ;
* ( V_5 * ) & V_4 -> V_6 [ 2 ] = 0xbb67ae8584caa73bULL ;
* ( V_5 * ) & V_4 -> V_6 [ 4 ] = 0x3c6ef372fe94f82bULL ;
* ( V_5 * ) & V_4 -> V_6 [ 6 ] = 0xa54ff53a5f1d36f1ULL ;
* ( V_5 * ) & V_4 -> V_6 [ 8 ] = 0x510e527fade682d1ULL ;
* ( V_5 * ) & V_4 -> V_6 [ 10 ] = 0x9b05688c2b3e6c1fULL ;
* ( V_5 * ) & V_4 -> V_6 [ 12 ] = 0x1f83d9abfb41bd6bULL ;
* ( V_5 * ) & V_4 -> V_6 [ 14 ] = 0x5be0cd19137e2179ULL ;
V_4 -> V_7 = 0 ;
V_4 -> V_8 = V_9 ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 , void * V_10 )
{
struct V_3 * V_11 = F_2 ( V_2 ) ;
struct V_12 * V_13 = V_10 ;
V_13 -> V_7 [ 0 ] = V_11 -> V_7 ;
V_13 -> V_7 [ 1 ] = 0 ;
memcpy ( V_13 -> V_6 , V_11 -> V_6 , sizeof( V_13 -> V_6 ) ) ;
memcpy ( V_13 -> V_14 , V_11 -> V_14 , sizeof( V_13 -> V_14 ) ) ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , const void * V_15 )
{
struct V_3 * V_11 = F_2 ( V_2 ) ;
const struct V_12 * V_16 = V_15 ;
if ( F_5 ( V_16 -> V_7 [ 1 ] ) )
return - V_17 ;
V_11 -> V_7 = V_16 -> V_7 [ 0 ] ;
memcpy ( V_11 -> V_6 , V_16 -> V_6 , sizeof( V_16 -> V_6 ) ) ;
memcpy ( V_11 -> V_14 , V_16 -> V_14 , sizeof( V_16 -> V_14 ) ) ;
V_11 -> V_8 = V_9 ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
* ( V_5 * ) & V_4 -> V_6 [ 0 ] = 0xcbbb9d5dc1059ed8ULL ;
* ( V_5 * ) & V_4 -> V_6 [ 2 ] = 0x629a292a367cd507ULL ;
* ( V_5 * ) & V_4 -> V_6 [ 4 ] = 0x9159015a3070dd17ULL ;
* ( V_5 * ) & V_4 -> V_6 [ 6 ] = 0x152fecd8f70e5939ULL ;
* ( V_5 * ) & V_4 -> V_6 [ 8 ] = 0x67332667ffc00b31ULL ;
* ( V_5 * ) & V_4 -> V_6 [ 10 ] = 0x8eb44a8768581511ULL ;
* ( V_5 * ) & V_4 -> V_6 [ 12 ] = 0xdb0c2e0d64f98fa7ULL ;
* ( V_5 * ) & V_4 -> V_6 [ 14 ] = 0x47b5481dbefa4fa4ULL ;
V_4 -> V_7 = 0 ;
V_4 -> V_8 = V_9 ;
return 0 ;
}
static int T_1 F_7 ( void )
{
int V_18 ;
if ( ! F_8 ( V_9 , V_19 ) )
return - V_20 ;
if ( ( V_18 = F_9 ( & V_21 ) ) < 0 )
goto V_10;
if ( ( V_18 = F_9 ( & V_22 ) ) < 0 )
F_10 ( & V_21 ) ;
V_10:
return V_18 ;
}
static void T_2 F_11 ( void )
{
F_10 ( & V_21 ) ;
F_10 ( & V_22 ) ;
}
