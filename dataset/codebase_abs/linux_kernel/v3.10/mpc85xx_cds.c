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
static void F_11 ( struct V_9 * V_10 )
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
static T_3 F_19 ( int V_18 , void * V_36 )
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
static void F_33 ( void )
{
#ifdef F_34
struct V_41 * V_42 ;
if ( V_49 )
return;
V_42 = F_35 ( NULL , L_9 ) ;
while ( ( V_49 = F_36 ( V_42 ) ) ) {
F_30 ( V_42 ) ;
V_42 = V_49 ;
if ( ( F_26 ( V_42 , L_10 ) ||
F_26 ( V_42 , L_11 ) ) &&
F_37 ( V_42 ) )
return;
}
#endif
}
static void T_2 F_38 ( void )
{
struct V_41 * V_42 ;
int V_50 ;
if ( V_51 . V_52 )
V_51 . V_52 ( L_12 , 0 ) ;
V_42 = F_39 ( NULL , NULL , L_13 ) ;
if ( ! V_42 ) {
F_40 ( L_14 ) ;
return;
}
V_53 = F_41 ( V_42 , 0 ) ;
F_30 ( V_42 ) ;
if ( ! V_53 ) {
F_40 ( L_15 ) ;
return;
}
if ( V_51 . V_52 ) {
char V_54 [ 40 ] ;
V_50 = ( ( F_42 ( & V_53 -> V_55 ) >> 6 ) & 0x3 ) + 1 ;
snprintf ( V_54 , 40 , L_16 ,
F_42 ( & V_53 -> V_56 ) , V_50 ) ;
V_51 . V_52 ( V_54 , 0 ) ;
}
#ifdef F_34
V_51 . V_57 = F_9 ;
V_51 . V_58 = F_1 ;
#endif
F_33 () ;
F_43 () ;
}
static void F_44 ( struct V_59 * V_60 )
{
T_4 V_61 , V_62 , V_63 ;
V_61 = F_45 ( V_64 ) ;
V_62 = F_45 ( V_65 ) ;
F_46 ( V_60 , L_17 ) ;
F_46 ( V_60 , L_18 ,
F_42 ( & V_53 -> V_56 ) ) ;
F_46 ( V_60 , L_19 , V_61 ) ;
F_46 ( V_60 , L_20 , V_62 ) ;
V_63 = F_45 ( V_66 ) ;
F_46 ( V_60 , L_21 , ( ( V_63 >> 24 ) & 0x3f ) ) ;
}
static int T_2 F_47 ( void )
{
unsigned long V_67 = F_48 () ;
return F_49 ( V_67 , L_22 ) ;
}
