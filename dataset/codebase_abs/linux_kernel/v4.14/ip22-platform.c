static int T_1 F_1 ( void )
{
int V_1 ;
V_2 . V_3 = & V_4 -> V_5 ;
V_2 . V_6 = ( unsigned char * ) V_4 -> V_7 ;
V_1 = F_2 ( & V_8 ) ;
if ( V_1 )
return V_1 ;
if ( ! F_3 () )
return 0 ;
V_9 . V_3 = & V_4 -> V_10 ;
V_9 . V_6 = ( unsigned char * ) V_4 -> V_11 ;
return F_2 ( & V_12 ) ;
}
static int T_1 F_4 ( void )
{
unsigned int T_2 V_13 ;
int V_1 , V_14 ;
V_15 . V_16 = V_4 ;
V_15 . V_17 = V_18 ;
#define F_5 250
for ( V_14 = 0 ; V_14 < 3 ; V_14 ++ ) {
unsigned short V_19 = F_6 ( F_5 / 2 + V_14 ) ;
V_15 . V_20 [ 2 * V_14 ] = V_19 >> 8 ;
V_15 . V_20 [ 2 * V_14 + 1 ] = V_19 & 0xff ;
}
V_1 = F_2 ( & V_21 ) ;
if ( V_1 )
return V_1 ;
if ( F_3 () ||
F_7 ( T_2 , ( unsigned int * ) & V_22 -> T_2 [ 1 ] ) )
return 0 ;
V_23 -> V_24 |= V_25 | V_26 |
V_27 ;
V_22 -> V_28 [ 0 ] [ 0 ] = 0x3ffff ;
V_22 -> V_29 [ 0 ] [ 0 ] = 0x30 ;
V_30 . V_16 = V_22 ;
V_30 . V_17 = V_31 ;
#define F_5 250
for ( V_14 = 0 ; V_14 < 3 ; V_14 ++ ) {
unsigned short V_19 = F_8 ( & V_22 -> V_32 ,
F_5 / 2 + V_14 ) ;
V_30 . V_20 [ 2 * V_14 ] = V_19 >> 8 ;
V_30 . V_20 [ 2 * V_14 + 1 ] = V_19 & 0xff ;
}
return F_2 ( & V_33 ) ;
}
static int T_1 F_9 ( void )
{
return F_10 ( F_11 ( L_1 , 0 , NULL , 0 ) ) ;
}
static int T_1 F_12 ( void )
{
if ( F_3 () )
return 0 ;
return F_10 ( F_11 ( L_2 , - 1 , NULL , 0 ) ) ;
}
static int T_1 F_13 ( void )
{
struct V_34 V_1 ;
memset ( & V_1 , 0 , sizeof( V_1 ) ) ;
V_1 . V_35 = V_36 + F_14 ( struct V_37 , V_38 ) ;
V_1 . V_39 = V_1 . V_35 + sizeof( V_4 -> V_38 ) - 1 ;
V_1 . V_40 = V_41 ;
return F_10 ( F_11 ( L_3 , - 1 ,
& V_1 , 1 ) ) ;
}
