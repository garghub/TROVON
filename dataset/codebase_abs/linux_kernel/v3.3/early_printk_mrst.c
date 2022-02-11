static void F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 ,
const char * V_5 , unsigned long V_6 ,
const char * V_7 , unsigned long V_8 )
{
int V_9 ;
F_2 () ;
for ( V_9 = 0 ; V_9 < V_6 ; V_9 ++ )
V_10 . V_11 ( & V_10 , V_5 + V_9 , 1 ) ;
for ( V_9 = 0 ; V_9 < V_8 ; V_9 ++ )
V_10 . V_11 ( & V_10 , V_7 + V_9 , 1 ) ;
}
static void F_3 ( void )
{
T_1 V_12 ;
V_12 = 0xc001 ;
F_4 ( V_13 , V_14 , V_12 ) ;
}
static void F_5 ( char V_15 )
{
T_1 V_16 ;
V_16 = 0x8000 | V_15 ;
F_4 ( V_13 , V_14 , V_16 ) ;
}
void F_2 ( void )
{
T_2 V_17 = 0 ;
T_2 V_18 ;
T_2 V_19 ;
V_20 = ( void * ) F_6 ( V_21 ,
V_22 ) ;
V_18 = ( ( * V_20 ) & 0xe00 ) >> 9 ;
V_19 = 100000000 / ( V_18 + 1 ) ;
if ( F_7 () == V_23 )
V_24 = V_25 ;
V_13 = ( void * ) F_6 ( V_21 ,
V_24 ) ;
F_4 ( V_13 , V_26 , 0 ) ;
V_17 = F_8 ( V_13 , V_27 ) ;
V_17 &= 0xfcc0 ;
V_17 |= 0xf | ( V_28 << V_29 )
| ( V_30 << V_31 ) ;
F_4 ( V_13 , V_27 , V_17 ) ;
F_4 ( V_13 , V_32 , V_19 / 100000 ) ;
F_4 ( V_13 , V_33 , 0x0 ) ;
F_4 ( V_13 , V_34 , 0x2 ) ;
F_4 ( V_13 , V_26 , 0x1 ) ;
F_3 () ;
if ( ! V_35 ) {
V_36 . V_37 = F_1 ;
F_9 ( & V_36 ) ;
V_35 = 1 ;
}
}
static void F_10 ( char V_15 )
{
unsigned int V_38 ;
T_2 V_39 ;
V_38 = V_40 ;
while ( -- V_38 ) {
V_39 = F_8 ( V_13 , V_39 ) ;
if ( ! ( V_39 & V_41 ) )
F_11 () ;
else
break;
}
if ( ! V_38 )
F_12 ( L_1 ) ;
else
F_5 ( V_15 ) ;
}
static void F_13 ( struct V_42 * V_43 , const char * V_44 , unsigned V_45 )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < V_45 && * V_44 ; V_9 ++ ) {
if ( * V_44 == '\n' )
F_10 ( '\r' ) ;
F_10 ( * V_44 ) ;
V_44 ++ ;
}
}
void F_14 ( const char * V_46 )
{
unsigned long V_47 , V_48 = 0 ;
T_3 V_49 ;
if ( * V_46 && ! F_15 ( V_46 , 10 , & V_48 ) )
V_48 = F_16 ( V_48 , 0 , 2 ) ;
V_47 = V_50 + V_48 * 0x80 ;
V_51 = ( void * ) F_6 ( V_21 , V_47 ) ;
F_17 ( 0x0 , V_51 + V_52 ) ;
V_49 = F_18 ( V_51 + V_53 ) ;
F_17 ( ( 0x80 | V_49 ) , V_51 + V_53 ) ;
F_17 ( 0x18 , V_51 + V_54 ) ;
F_17 ( V_49 , V_51 + V_53 ) ;
F_19 ( 0x3600 , V_51 + V_55 * 4 ) ;
F_17 ( 0x8 , V_51 + V_56 ) ;
F_17 ( 0x7 , V_51 + V_52 ) ;
F_17 ( 0x3 , V_51 + V_53 ) ;
F_18 ( V_51 + V_57 ) ;
F_18 ( V_51 + V_58 ) ;
F_18 ( V_51 + V_59 ) ;
F_18 ( V_51 + V_60 ) ;
F_17 ( 0x7 , V_51 + V_52 ) ;
}
static void F_20 ( char V_61 )
{
unsigned int V_38 = 10000 ;
T_3 V_62 ;
while ( -- V_38 ) {
V_62 = F_18 ( V_51 + V_57 ) ;
if ( V_62 & V_63 )
break;
F_21 ( 1 ) ;
}
if ( V_38 )
F_17 ( V_61 , V_51 + V_64 ) ;
}
static void F_22 ( struct V_42 * V_43 , const char * V_44 , unsigned V_45 )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < V_45 && * V_44 ; V_9 ++ ) {
if ( * V_44 == '\n' )
F_20 ( '\r' ) ;
F_20 ( * V_44 ) ;
V_44 ++ ;
}
}
