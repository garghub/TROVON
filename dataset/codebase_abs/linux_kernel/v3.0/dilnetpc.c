static inline void F_1 ( int V_1 , unsigned char V_2 )
{
F_2 ( V_1 , V_3 ) ;
F_2 ( V_2 , V_4 ) ;
}
static inline unsigned char F_3 ( int V_1 )
{
F_2 ( V_1 , V_3 ) ;
return ( F_4 ( V_4 ) ) ;
}
static inline void F_5 ( int V_1 , unsigned char V_2 )
{
F_2 ( V_1 , V_5 ) ;
F_2 ( V_2 , V_6 ) ;
}
static inline unsigned char F_6 ( int V_1 )
{
F_2 ( V_1 , V_5 ) ;
return ( F_4 ( V_6 ) ) ;
}
static void F_7 ( unsigned long V_7 , unsigned long V_8 )
{
unsigned long V_9 = V_7 + V_8 - 1 ;
F_1 ( V_10 , F_3 ( V_10 ) | 0x2 ) ;
F_1 ( V_11 , F_3 ( V_11 ) & ~ 1 ) ;
F_5 ( V_12 , ( V_7 >> 12 ) & 0xff ) ;
F_5 ( V_13 , ( V_7 >> 20 ) & 0x3f ) ;
F_5 ( V_14 , ( V_9 >> 12 ) & 0xff ) ;
F_5 ( V_15 , ( V_9 >> 20 ) & 0x3f ) ;
F_5 ( V_16 , ( ( 0 - V_7 ) >> 12 ) & 0xff ) ;
F_5 ( V_17 , ( ( 0 - V_7 ) >> 20 ) & 0x3f ) ;
F_1 ( V_18 , F_3 ( V_18 ) & ~ 0x11 ) ;
F_1 ( V_19 , F_3 ( V_19 ) & ~ 0x03 ) ;
F_5 ( V_20 , F_6 ( V_20 ) | 0x02 ) ;
F_1 ( V_10 , F_3 ( V_10 ) & ~ 0x2 ) ;
}
static void F_8 ( void )
{
F_1 ( V_10 , F_3 ( V_10 ) | 0x2 ) ;
F_5 ( V_20 , F_6 ( V_20 ) & ~ 0x02 ) ;
F_1 ( V_10 , F_3 ( V_10 ) & ~ 0x2 ) ;
}
static void F_9 ( struct V_21 * V_22 , int V_23 )
{
F_10 ( & V_24 ) ;
if ( V_23 )
{
if( ++ V_25 == 1 )
F_1 ( V_26 , F_3 ( V_26 ) & ~ 0x4 ) ;
}
else
{
if( -- V_25 == 0 )
F_1 ( V_26 , F_3 ( V_26 ) | 0x4 ) ;
else
F_11 ( V_25 < 0 ) ;
}
F_12 ( & V_24 ) ;
}
static void F_13 ( struct V_21 * V_22 , int V_23 )
{
F_10 ( & V_24 ) ;
if ( V_23 )
{
if( ++ V_25 == 1 )
F_1 ( V_26 , F_3 ( V_26 ) & ~ 0x8 ) ;
}
else
{
if( -- V_25 == 0 )
F_1 ( V_26 , F_3 ( V_26 ) | 0x8 ) ;
else
F_11 ( V_25 < 0 ) ;
}
F_12 ( & V_24 ) ;
}
static int F_14 ( void )
{
char * V_27 , V_28 = - 1 ;
V_27 = ( char * ) F_15 ( V_29 , 16 ) ;
if( V_27 )
{
if( ! strcmp ( V_27 , V_30 ) )
V_28 = 1 ;
else if( ! strcmp ( V_27 , V_31 ) )
V_28 = 0 ;
}
F_16 ( ( void * ) V_27 ) ;
return ( V_28 ) ;
}
static int T_1 F_17 ( void )
{
int V_32 ;
if( ( V_32 = F_14 () ) < 0 )
return - V_33 ;
if( V_32 )
{
int V_34 ;
V_35 . V_36 = V_37 ;
V_35 . V_38 = F_9 ;
V_39 [ 2 ] . V_36 = 0xf0000 ;
++ V_35 . V_40 ;
for( V_34 = 0 ; V_34 < V_41 ; V_34 ++ )
++ V_39 [ V_34 ] . V_40 ;
V_42 [ 1 ] . V_36 = V_37 -
V_43 - 0x20000 ;
for( V_34 = 0 ; V_34 < V_44 ; V_34 ++ )
++ V_42 [ V_34 ] . V_40 ;
}
F_18 ( V_45 L_1 ,
V_32 ? L_2 : L_3 , V_35 . V_36 , ( unsigned long long ) V_35 . V_46 ) ;
V_35 . V_47 = F_19 ( V_35 . V_46 , V_35 . V_36 ) ;
F_7 ( V_35 . V_46 , V_35 . V_36 ) ;
if ( ! V_35 . V_47 ) {
F_18 ( L_4 ) ;
return - V_48 ;
}
F_20 ( & V_35 ) ;
F_18 ( L_5 , V_35 . V_47 ) ;
V_49 = F_21 ( L_6 , & V_35 ) ;
if ( ! V_49 )
V_49 = F_21 ( L_7 , & V_35 ) ;
if ( ! V_49 )
if( ( V_49 = F_21 ( L_8 , & V_35 ) ) )
V_49 -> V_50 = 0x10000 ;
if ( ! V_49 ) {
F_16 ( V_35 . V_47 ) ;
return - V_33 ;
}
V_49 -> V_51 = V_52 ;
V_39 [ 0 ] . V_53 = & V_54 [ 0 ] ;
V_39 [ 1 ] . V_53 = & V_54 [ 2 ] ;
V_39 [ 2 ] . V_53 = & V_54 [ 1 ] ;
V_39 [ 3 ] . V_53 = & V_54 [ 3 ] ;
F_22 ( V_49 , V_39 , V_41 ) ;
V_55 = F_23 ( V_54 , V_41 , L_9 ) ;
if( V_55 )
{
F_22 ( V_55 , V_42 ,
V_44 ) ;
}
return 0 ;
}
static void T_2 F_24 ( void )
{
if( V_55 ) {
F_25 ( V_55 ) ;
F_26 ( V_55 ) ;
}
if ( V_49 ) {
F_25 ( V_49 ) ;
F_27 ( V_49 ) ;
}
if ( V_35 . V_47 ) {
F_16 ( V_35 . V_47 ) ;
F_8 () ;
V_35 . V_47 = NULL ;
}
}
