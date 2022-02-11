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
struct V_29 V_30 ;
struct V_31 * V_32 = NULL ;
V_32 = F_18 ( V_32 , L_1 ) ;
if ( V_32 == NULL ) {
F_19 ( V_33 L_2 ) ;
return;
}
if ( F_20 ( V_32 , 0 , & V_30 ) ) {
F_19 ( V_33 L_3 ) ;
F_21 ( V_32 ) ;
return;
}
V_28 = F_22 ( V_32 , V_30 . V_34 ,
V_35 | V_36 | V_37 ,
0 , 256 , L_4 ) ;
F_23 ( V_28 == NULL ) ;
F_21 ( V_32 ) ;
F_24 ( V_28 ) ;
}
static int F_25 ( void )
{
int V_38 ;
struct V_31 * V_32 = NULL ;
struct V_31 * V_39 = NULL ;
int V_24 ;
F_26 (np, L_5 )
if ( F_27 ( V_32 , L_6 ) ) {
V_39 = V_32 ;
break;
}
if ( V_39 == NULL ) {
F_19 ( V_40 L_7 ) ;
return - V_41 ;
}
V_24 = F_28 ( V_39 , 0 ) ;
if ( V_24 == V_25 ) {
F_19 ( V_33 L_8 ) ;
return - V_42 ;
}
F_29 ( V_39 , 0 ) ;
F_21 ( V_39 ) ;
if ( ( V_38 = F_30 ( V_24 , & V_43 ) ) ) {
F_19 ( V_33 L_9 ) ;
return V_38 ;
}
F_31 ( V_24 , F_12 ) ;
return 0 ;
}
static void T_2 F_32 ( void )
{
#ifdef F_33
struct V_31 * V_32 ;
#endif
if ( V_44 . V_45 )
V_44 . V_45 ( L_10 , 0 ) ;
V_46 = F_34 ( V_47 , V_48 ) ;
V_49 = ( ( V_46 [ V_50 ] >> 6 ) & 0x3 ) + 1 ;
if ( V_44 . V_45 ) {
char V_51 [ 40 ] ;
snprintf ( V_51 , 40 , L_11 ,
V_46 [ V_52 ] , V_49 ) ;
V_44 . V_45 ( V_51 , 0 ) ;
}
#ifdef F_33
F_26 (np, L_12 ) {
if ( F_27 ( V_32 , L_13 ) ||
F_27 ( V_32 , L_14 ) ) {
struct V_29 V_53 ;
F_20 ( V_32 , 0 , & V_53 ) ;
if ( ( V_53 . V_34 & 0xfffff ) == 0x8000 )
F_35 ( V_32 , 1 ) ;
else
F_35 ( V_32 , 0 ) ;
}
}
V_44 . V_54 = F_9 ;
V_44 . V_55 = F_1 ;
#endif
}
static void F_36 ( struct V_56 * V_57 )
{
T_5 V_58 , V_59 , V_60 ;
V_58 = F_37 ( V_61 ) ;
V_59 = F_37 ( V_62 ) ;
F_38 ( V_57 , L_15 ) ;
F_38 ( V_57 , L_16 , V_46 [ V_52 ] ) ;
F_38 ( V_57 , L_17 , V_58 ) ;
F_38 ( V_57 , L_18 , V_59 ) ;
V_60 = F_37 ( V_63 ) ;
F_38 ( V_57 , L_19 , ( ( V_60 >> 24 ) & 0x3f ) ) ;
}
static int T_2 F_39 ( void )
{
unsigned long V_64 = F_40 () ;
return F_41 ( V_64 , L_20 ) ;
}
static int T_2 F_42 ( void )
{
return F_43 ( NULL , V_65 , NULL ) ;
}
