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
void F_14 ( void )
{
T_3 V_46 ;
V_47 = ( void * ) F_6 ( V_21 ,
V_48 ) ;
F_15 ( 0x0 , V_47 + V_49 ) ;
V_46 = F_16 ( V_47 + V_50 ) ;
F_15 ( ( 0x80 | V_46 ) , V_47 + V_50 ) ;
F_15 ( 0x18 , V_47 + V_51 ) ;
F_15 ( V_46 , V_47 + V_50 ) ;
F_17 ( 0x3600 , V_47 + V_52 * 4 ) ;
F_15 ( 0x8 , V_47 + V_53 ) ;
F_15 ( 0x7 , V_47 + V_49 ) ;
F_15 ( 0x3 , V_47 + V_50 ) ;
F_16 ( V_47 + V_54 ) ;
F_16 ( V_47 + V_55 ) ;
F_16 ( V_47 + V_56 ) ;
F_16 ( V_47 + V_57 ) ;
F_15 ( 0x7 , V_47 + V_49 ) ;
}
static void F_18 ( char V_58 )
{
unsigned int V_38 = 10000 ;
T_3 V_59 ;
while ( -- V_38 ) {
V_59 = F_16 ( V_47 + V_54 ) ;
if ( V_59 & V_60 )
break;
F_19 ( 1 ) ;
}
if ( V_38 )
F_15 ( V_58 , V_47 + V_61 ) ;
}
static void F_20 ( struct V_42 * V_43 , const char * V_44 , unsigned V_45 )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < V_45 && * V_44 ; V_9 ++ ) {
if ( * V_44 == '\n' )
F_18 ( '\r' ) ;
F_18 ( * V_44 ) ;
V_44 ++ ;
}
}
