static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 )
{
if ( ( V_3 == 1 ) && ( F_2 ( V_4 ) == V_5 ) )
return V_6 ;
if ( ( V_3 == 0 ) && ( F_2 ( V_4 ) == V_5 ) )
return V_6 ;
else
return V_7 ;
}
static void F_3 ( char * V_8 )
{
struct V_9 * V_10 ;
T_1 V_11 ;
if ( ( V_10 = F_4 ( V_12 , V_13 ,
NULL ) ) ) {
F_5 ( V_10 , 0x47 , & V_11 ) ;
F_6 ( V_10 , 0x47 , V_11 | 1 ) ;
F_5 ( V_10 , 0x47 , & V_11 ) ;
F_7 ( V_10 ) ;
}
F_8 ( NULL ) ;
}
static void T_2 F_9 ( struct V_9 * V_10 )
{
T_1 V_14 ;
if ( V_10 -> V_15 == V_12 ) {
switch ( V_10 -> V_16 ) {
case V_17 :
F_5 ( V_10 , 0x40 , & V_14 ) ;
V_14 |= 0x03 ;
F_6 ( V_10 , 0x40 , V_14 ) ;
V_10 -> V_18 = 14 ;
F_6 ( V_10 , V_19 , V_10 -> V_18 ) ;
break;
case V_20 :
if ( F_10 ( V_10 -> V_4 ) == 3 )
V_10 -> V_18 = 11 ;
else
V_10 -> V_18 = 10 ;
F_6 ( V_10 , V_19 , V_10 -> V_18 ) ;
default:
break;
}
}
}
static void T_3 F_11 ( struct V_9 * V_10 )
{
V_10 -> V_21 = 0x7f ;
}
static void F_12 ( unsigned int V_18 ,
struct V_22 * V_23 )
{
unsigned int V_24 = F_13 () ;
if ( V_24 != V_25 )
F_14 ( V_24 ) ;
F_15 ( V_18 , V_23 ) ;
}
static T_4 F_16 ( int V_18 , void * V_26 )
{
return V_27 ;
}
static void T_2 F_17 ( void )
{
struct V_28 * V_28 ;
V_28 = F_18 ( NULL , 0 ,
V_29 | V_30 ,
0 , 256 , L_1 ) ;
F_19 ( V_28 == NULL ) ;
F_20 ( V_28 ) ;
}
static int F_21 ( void )
{
int V_31 ;
struct V_32 * V_33 = NULL ;
struct V_32 * V_34 = NULL ;
int V_24 ;
F_22 (np, L_2 )
if ( F_23 ( V_33 , L_3 ) ) {
V_34 = V_33 ;
break;
}
if ( V_34 == NULL ) {
F_24 ( V_35 L_4 ) ;
return - V_36 ;
}
V_24 = F_25 ( V_34 , 0 ) ;
if ( V_24 == V_25 ) {
F_24 ( V_37 L_5 ) ;
return - V_38 ;
}
F_26 ( V_34 , 0 ) ;
F_27 ( V_34 ) ;
if ( ( V_31 = F_28 ( V_24 , & V_39 ) ) ) {
F_24 ( V_37 L_6 ) ;
return V_31 ;
}
F_29 ( V_24 , F_12 ) ;
return 0 ;
}
static void T_2 F_30 ( void )
{
#ifdef F_31
struct V_32 * V_33 ;
#endif
if ( V_40 . V_41 )
V_40 . V_41 ( L_7 , 0 ) ;
V_42 = F_32 ( V_43 , V_44 ) ;
V_45 = ( ( V_42 [ V_46 ] >> 6 ) & 0x3 ) + 1 ;
if ( V_40 . V_41 ) {
char V_47 [ 40 ] ;
snprintf ( V_47 , 40 , L_8 ,
V_42 [ V_48 ] , V_45 ) ;
V_40 . V_41 ( V_47 , 0 ) ;
}
#ifdef F_31
F_22 (np, L_9 ) {
if ( F_23 ( V_33 , L_10 ) ||
F_23 ( V_33 , L_11 ) ) {
struct V_49 V_50 ;
F_33 ( V_33 , 0 , & V_50 ) ;
if ( ( V_50 . V_51 & 0xfffff ) == 0x8000 )
F_34 ( V_33 , 1 ) ;
else
F_34 ( V_33 , 0 ) ;
}
}
V_40 . V_52 = F_9 ;
V_40 . V_53 = F_1 ;
#endif
}
static void F_35 ( struct V_54 * V_55 )
{
T_5 V_56 , V_57 , V_58 ;
V_56 = F_36 ( V_59 ) ;
V_57 = F_36 ( V_60 ) ;
F_37 ( V_55 , L_12 ) ;
F_37 ( V_55 , L_13 , V_42 [ V_48 ] ) ;
F_37 ( V_55 , L_14 , V_56 ) ;
F_37 ( V_55 , L_15 , V_57 ) ;
V_58 = F_36 ( V_61 ) ;
F_37 ( V_55 , L_16 , ( ( V_58 >> 24 ) & 0x3f ) ) ;
}
static int T_2 F_38 ( void )
{
unsigned long V_62 = F_39 () ;
return F_40 ( V_62 , L_17 ) ;
}
