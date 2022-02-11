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
static int F_3 ( struct V_8 * V_9 ,
unsigned long V_10 , void * V_11 )
{
struct V_12 * V_13 ;
T_1 V_14 ;
if ( ( V_13 = F_4 ( V_15 , V_16 ,
NULL ) ) ) {
F_5 ( V_13 , 0x47 , & V_14 ) ;
F_6 ( V_13 , 0x47 , V_14 | 1 ) ;
F_5 ( V_13 , 0x47 , & V_14 ) ;
F_7 ( V_13 ) ;
}
return V_17 ;
}
static int F_8 ( void )
{
static struct V_8 V_18 ;
V_18 . V_19 = F_3 ;
V_18 . V_20 = 192 ;
return F_9 ( & V_18 ) ;
}
static void T_2 F_10 ( struct V_12 * V_13 )
{
T_1 V_21 ;
if ( V_13 -> V_22 == V_15 ) {
switch ( V_13 -> V_23 ) {
case V_24 :
F_5 ( V_13 , 0x40 , & V_21 ) ;
V_21 |= 0x03 ;
F_6 ( V_13 , 0x40 , V_21 ) ;
V_13 -> V_25 = 14 ;
F_6 ( V_13 , V_26 , V_13 -> V_25 ) ;
break;
case V_27 :
if ( F_11 ( V_13 -> V_4 ) == 3 )
V_13 -> V_25 = 11 ;
else
V_13 -> V_25 = 10 ;
F_6 ( V_13 , V_26 , V_13 -> V_25 ) ;
default:
break;
}
}
}
static void F_12 ( struct V_12 * V_13 )
{
V_13 -> V_28 = 0x7f ;
}
void F_13 ( struct V_29 * V_3 )
{
struct V_12 * V_13 = V_3 -> V_30 ;
struct V_31 * V_32 = V_3 -> V_31 [ 0 ] ;
if ( V_13 != NULL &&
V_13 -> V_22 == V_33 &&
V_13 -> V_23 == V_34 ) {
if ( V_32 ) {
V_32 -> V_35 = 0 ;
V_32 -> V_36 = 0x1fff ;
V_32 -> V_37 = V_38 ;
F_14 ( L_1 ) ;
F_14 ( L_2 , V_32 ) ;
}
}
F_15 ( V_3 ) ;
}
static void F_16 ( struct V_39 * V_40 )
{
unsigned int V_41 = F_17 () ;
if ( V_41 )
F_18 ( V_41 ) ;
F_19 ( V_40 ) ;
}
static T_3 F_20 ( int V_25 , void * V_42 )
{
return V_43 ;
}
static void T_2 F_21 ( void )
{
struct V_44 * V_44 ;
V_44 = F_22 ( NULL , 0 , V_45 ,
0 , 256 , L_3 ) ;
F_23 ( V_44 == NULL ) ;
F_24 ( V_44 ) ;
}
static int F_25 ( void )
{
int V_46 ;
struct V_47 * V_48 = NULL ;
struct V_47 * V_49 = NULL ;
int V_41 ;
F_26 (np, L_4 )
if ( F_27 ( V_48 , L_5 ) ) {
V_49 = V_48 ;
break;
}
if ( V_49 == NULL ) {
F_28 ( V_50 L_6 ) ;
return - V_51 ;
}
V_41 = F_29 ( V_49 , 0 ) ;
if ( ! V_41 ) {
F_28 ( V_52 L_7 ) ;
return - V_53 ;
}
F_30 ( V_49 , 0 ) ;
F_31 ( V_49 ) ;
if ( ( V_46 = F_32 ( V_41 , & V_54 ) ) ) {
F_28 ( V_52 L_8 ) ;
return V_46 ;
}
F_33 ( V_41 , F_16 ) ;
return 0 ;
}
static void F_34 ( void )
{
#ifdef F_35
struct V_47 * V_48 ;
if ( V_55 )
return;
V_48 = F_36 ( NULL , L_9 ) ;
while ( ( V_55 = F_37 ( V_48 ) ) ) {
F_31 ( V_48 ) ;
V_48 = V_55 ;
if ( ( F_27 ( V_48 , L_10 ) ||
F_27 ( V_48 , L_11 ) ) &&
F_38 ( V_48 ) )
return;
}
#endif
}
static void T_2 F_39 ( void )
{
struct V_47 * V_48 ;
int V_56 ;
if ( V_57 . V_58 )
V_57 . V_58 ( L_12 , 0 ) ;
V_48 = F_40 ( NULL , NULL , L_13 ) ;
if ( ! V_48 ) {
F_41 ( L_14 ) ;
return;
}
V_59 = F_42 ( V_48 , 0 ) ;
F_31 ( V_48 ) ;
if ( ! V_59 ) {
F_41 ( L_15 ) ;
return;
}
if ( V_57 . V_58 ) {
char V_60 [ 40 ] ;
V_56 = ( ( F_43 ( & V_59 -> V_61 ) >> 6 ) & 0x3 ) + 1 ;
snprintf ( V_60 , 40 , L_16 ,
F_43 ( & V_59 -> V_62 ) , V_56 ) ;
V_57 . V_58 ( V_60 , 0 ) ;
}
#ifdef F_35
V_57 . V_63 = F_10 ;
V_57 . V_64 = F_1 ;
#endif
F_34 () ;
F_44 () ;
}
static void F_45 ( struct V_65 * V_66 )
{
T_4 V_67 , V_68 , V_69 ;
V_67 = F_46 ( V_70 ) ;
V_68 = F_46 ( V_71 ) ;
F_47 ( V_66 , L_17 ) ;
F_47 ( V_66 , L_18 ,
F_43 ( & V_59 -> V_62 ) ) ;
F_47 ( V_66 , L_19 , V_67 ) ;
F_47 ( V_66 , L_20 , V_68 ) ;
V_69 = F_46 ( V_72 ) ;
F_47 ( V_66 , L_21 , ( ( V_69 >> 24 ) & 0x3f ) ) ;
}
static int T_2 F_48 ( void )
{
return F_49 ( L_22 ) ;
}
