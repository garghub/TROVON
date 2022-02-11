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
void F_12 ( struct V_22 * V_3 )
{
struct V_9 * V_10 = V_3 -> V_23 ;
struct V_24 * V_25 = V_3 -> V_24 [ 0 ] ;
if ( V_10 != NULL &&
V_10 -> V_15 == V_26 &&
V_10 -> V_16 == V_27 ) {
if ( V_25 ) {
V_25 -> V_28 = 0 ;
V_25 -> V_29 = 0x1fff ;
V_25 -> V_30 = V_31 ;
F_13 ( L_1 ) ;
F_13 ( L_2 , V_25 ) ;
}
}
F_14 ( V_3 ) ;
}
static void F_15 ( unsigned int V_18 ,
struct V_32 * V_33 )
{
unsigned int V_34 = F_16 () ;
if ( V_34 != V_35 )
F_17 ( V_34 ) ;
F_18 ( V_18 , V_33 ) ;
}
static T_4 F_19 ( int V_18 , void * V_36 )
{
return V_37 ;
}
static void T_2 F_20 ( void )
{
struct V_38 * V_38 ;
V_38 = F_21 ( NULL , 0 , V_39 ,
0 , 256 , L_3 ) ;
F_22 ( V_38 == NULL ) ;
F_23 ( V_38 ) ;
}
static int F_24 ( void )
{
int V_40 ;
struct V_41 * V_42 = NULL ;
struct V_41 * V_43 = NULL ;
int V_34 ;
F_25 (np, L_4 )
if ( F_26 ( V_42 , L_5 ) ) {
V_43 = V_42 ;
break;
}
if ( V_43 == NULL ) {
F_27 ( V_44 L_6 ) ;
return - V_45 ;
}
V_34 = F_28 ( V_43 , 0 ) ;
if ( V_34 == V_35 ) {
F_27 ( V_46 L_7 ) ;
return - V_47 ;
}
F_29 ( V_43 , 0 ) ;
F_30 ( V_43 ) ;
if ( ( V_40 = F_31 ( V_34 , & V_48 ) ) ) {
F_27 ( V_46 L_8 ) ;
return V_40 ;
}
F_32 ( V_34 , F_15 ) ;
return 0 ;
}
static void T_2 F_33 ( void )
{
struct V_41 * V_42 ;
int V_49 ;
if ( V_50 . V_51 )
V_50 . V_51 ( L_9 , 0 ) ;
V_42 = F_34 ( NULL , NULL , L_10 ) ;
if ( ! V_42 ) {
F_35 ( L_11 ) ;
return;
}
V_52 = F_36 ( V_42 , 0 ) ;
F_30 ( V_42 ) ;
if ( ! V_52 ) {
F_35 ( L_12 ) ;
return;
}
if ( V_50 . V_51 ) {
char V_53 [ 40 ] ;
V_49 = ( ( F_37 ( & V_52 -> V_54 ) >> 6 ) & 0x3 ) + 1 ;
snprintf ( V_53 , 40 , L_13 ,
F_37 ( & V_52 -> V_55 ) , V_49 ) ;
V_50 . V_51 ( V_53 , 0 ) ;
}
#ifdef F_38
F_25 (np, L_14 ) {
if ( F_26 ( V_42 , L_15 ) ||
F_26 ( V_42 , L_16 ) ) {
struct V_24 V_56 ;
F_39 ( V_42 , 0 , & V_56 ) ;
if ( ( V_56 . V_28 & 0xfffff ) == 0x8000 )
F_40 ( V_42 , 1 ) ;
else
F_40 ( V_42 , 0 ) ;
}
}
V_50 . V_57 = F_9 ;
V_50 . V_58 = F_1 ;
#endif
}
static void F_41 ( struct V_59 * V_60 )
{
T_5 V_61 , V_62 , V_63 ;
V_61 = F_42 ( V_64 ) ;
V_62 = F_42 ( V_65 ) ;
F_43 ( V_60 , L_17 ) ;
F_43 ( V_60 , L_18 ,
F_37 ( & V_52 -> V_55 ) ) ;
F_43 ( V_60 , L_19 , V_61 ) ;
F_43 ( V_60 , L_20 , V_62 ) ;
V_63 = F_42 ( V_66 ) ;
F_43 ( V_60 , L_21 , ( ( V_63 >> 24 ) & 0x3f ) ) ;
}
static int T_2 F_44 ( void )
{
unsigned long V_67 = F_45 () ;
return F_46 ( V_67 , L_22 ) ;
}
