static inline void F_1 ( void )
{
unsigned int V_1 ;
V_1 = F_2 ( V_2 ) ;
V_3 [ V_1 ] . V_4 [ 0 ] = F_3 ( V_5 ) ;
}
static inline void F_4 ( void )
{
unsigned int V_1 ;
V_1 = F_2 ( V_6 ) ;
V_3 [ V_1 ] . V_4 [ 0 ] = F_3 ( V_7 ) ;
}
static inline void F_5 ( T_1 V_8 )
{
unsigned int V_9 = 16384 ;
unsigned int V_10 = ( unsigned int ) & V_11 [ 0 ] ;
unsigned int V_12 = sizeof( V_11 ) ;
unsigned int V_13 = 0 ;
unsigned int V_14 = 0x24 ;
F_6 ( V_15 , V_9 ) ;
F_6 ( V_16 , V_8 . V_17 [ 0 ] ) ;
F_6 ( V_18 , V_10 ) ;
F_6 ( V_19 , V_12 ) ;
F_6 ( V_20 , V_13 ) ;
F_6 ( V_21 , V_14 ) ;
}
static inline void F_7 ( void )
{
unsigned int V_1 ;
V_1 = F_2 ( V_22 ) ;
V_3 [ V_1 ] . V_23 = F_8 () ;
}
static inline void F_9 ( void )
{
unsigned int V_1 ;
V_1 = F_2 ( V_24 ) ;
V_3 [ V_1 ] . V_4 [ 0 ] = F_3 ( V_25 ) ;
}
static inline void F_10 ( void )
{
unsigned int V_1 ;
V_1 = F_2 ( V_26 ) ;
V_3 [ V_1 ] . V_4 [ 0 ] = F_3 ( V_27 ) ;
}
static inline void F_11 ( T_1 V_8 )
{
unsigned int V_9 = ( unsigned int ) & V_3 [ 0 ] ;
unsigned int V_12 = sizeof( V_3 ) ;
unsigned int V_13 = 0 ;
unsigned int V_14 = 0x20 ;
F_6 ( V_15 , V_9 ) ;
F_6 ( V_16 , V_8 . V_17 [ 0 ] ) ;
F_6 ( V_18 , V_8 . V_17 [ 1 ] ) ;
F_6 ( V_19 , V_12 ) ;
F_6 ( V_20 , V_13 ) ;
F_6 ( V_21 , V_14 ) ;
}
static inline void F_12 ( T_1 V_8 )
{
unsigned int V_13 = 0 ;
unsigned int V_14 = 0xCC ;
F_6 ( V_20 , V_13 ) ;
F_6 ( V_21 , V_14 ) ;
}
static inline void F_13 ( void )
{
F_14 ( V_28 ) ;
}
int main ()
{
T_1 V_8 ;
V_8 . V_17 [ 0 ] = F_3 ( V_29 ) ;
V_8 . V_17 [ 1 ] = F_3 ( V_30 ) ;
F_1 () ;
F_4 () ;
F_15 () ;
F_16 () ;
F_17 ( V_8 ) ;
F_5 ( V_8 ) ;
F_7 () ;
F_9 () ;
F_10 () ;
F_18 ( V_8 ) ;
F_11 ( V_8 ) ;
F_12 ( V_8 ) ;
F_19 () ;
F_20 () ;
F_21 () ;
F_13 () ;
return 0 ;
}
