static void F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
static char line [ 1024 ] ;
T_1 V_5 ;
F_2 () ;
while ( F_3 ( V_2 , true , line , sizeof( line ) , & V_5 ) )
V_6 . V_7 ( & V_6 , line , V_5 ) ;
}
static void F_4 ( void )
{
T_2 V_8 ;
V_8 = 0xc001 ;
F_5 ( V_9 , V_10 , V_8 ) ;
}
static void F_6 ( char V_11 )
{
T_2 V_12 ;
V_12 = 0x8000 | V_11 ;
F_5 ( V_9 , V_10 , V_12 ) ;
}
void F_2 ( void )
{
T_3 V_13 = 0 ;
T_3 V_14 ;
T_3 V_15 ;
V_16 = ( void * ) F_7 ( V_17 ,
V_18 ) ;
V_14 = ( ( * V_16 ) & 0xe00 ) >> 9 ;
V_15 = 100000000 / ( V_14 + 1 ) ;
if ( F_8 () == V_19 )
V_20 = V_21 ;
V_9 = ( void * ) F_7 ( V_17 ,
V_20 ) ;
F_5 ( V_9 , V_22 , 0 ) ;
V_13 = F_9 ( V_9 , V_23 ) ;
V_13 &= 0xfcc0 ;
V_13 |= 0xf | ( V_24 << V_25 )
| ( V_26 << V_27 ) ;
F_5 ( V_9 , V_23 , V_13 ) ;
F_5 ( V_9 , V_28 , V_15 / 100000 ) ;
F_5 ( V_9 , V_29 , 0x0 ) ;
F_5 ( V_9 , V_30 , 0x2 ) ;
F_5 ( V_9 , V_22 , 0x1 ) ;
F_4 () ;
if ( ! V_31 ) {
V_32 . V_33 = F_1 ;
F_10 ( & V_32 ) ;
V_31 = 1 ;
}
}
static void F_11 ( char V_11 )
{
unsigned int V_34 ;
T_3 V_35 ;
V_34 = V_36 ;
while ( -- V_34 ) {
V_35 = F_9 ( V_9 , V_35 ) ;
if ( ! ( V_35 & V_37 ) )
F_12 () ;
else
break;
}
if ( ! V_34 )
F_13 ( L_1 ) ;
else
F_6 ( V_11 ) ;
}
static void F_14 ( struct V_38 * V_39 , const char * V_40 ,
unsigned V_41 )
{
int V_42 ;
for ( V_42 = 0 ; V_42 < V_41 && * V_40 ; V_42 ++ ) {
if ( * V_40 == '\n' )
F_11 ( '\r' ) ;
F_11 ( * V_40 ) ;
V_40 ++ ;
}
}
void F_15 ( const char * V_43 )
{
unsigned long V_44 , V_45 = 0 ;
T_4 V_46 ;
if ( * V_43 && ! F_16 ( V_43 , 10 , & V_45 ) )
V_45 = F_17 ( V_45 , 0 , 2 ) ;
V_44 = V_47 + V_45 * 0x80 ;
V_48 = ( void * ) F_7 ( V_17 , V_44 ) ;
F_18 ( 0x0 , V_48 + V_49 ) ;
V_46 = F_19 ( V_48 + V_50 ) ;
F_18 ( ( 0x80 | V_46 ) , V_48 + V_50 ) ;
F_18 ( 0x18 , V_48 + V_51 ) ;
F_18 ( V_46 , V_48 + V_50 ) ;
F_20 ( 0x3600 , V_48 + V_52 * 4 ) ;
F_18 ( 0x8 , V_48 + V_53 ) ;
F_18 ( 0x7 , V_48 + V_49 ) ;
F_18 ( 0x3 , V_48 + V_50 ) ;
F_19 ( V_48 + V_54 ) ;
F_19 ( V_48 + V_55 ) ;
F_19 ( V_48 + V_56 ) ;
F_19 ( V_48 + V_57 ) ;
F_18 ( 0x7 , V_48 + V_49 ) ;
}
static void F_21 ( char V_58 )
{
unsigned int V_34 = 10000 ;
T_4 V_59 ;
while ( -- V_34 ) {
V_59 = F_19 ( V_48 + V_54 ) ;
if ( V_59 & V_60 )
break;
F_22 ( 1 ) ;
}
if ( V_34 )
F_18 ( V_58 , V_48 + V_61 ) ;
}
static void F_23 ( struct V_38 * V_39 , const char * V_40 , unsigned V_41 )
{
int V_42 ;
for ( V_42 = 0 ; V_42 < V_41 && * V_40 ; V_42 ++ ) {
if ( * V_40 == '\n' )
F_21 ( '\r' ) ;
F_21 ( * V_40 ) ;
V_40 ++ ;
}
}
