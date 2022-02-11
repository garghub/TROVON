static int T_1 F_1 ( const struct V_1 * V_2 )
{
F_2 ( L_1 , V_2 -> V_3 ) ;
return 1 ;
}
static struct V_4 *
F_3 ( struct V_5 * V_6 )
{
return F_4 ( V_6 , struct V_4 , V_6 ) ;
}
static struct V_4 * F_5 ( char * V_7 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < F_6 ( V_9 ) ; V_8 ++ ) {
if ( strcmp ( V_9 [ V_8 ] . V_7 , V_7 ) )
continue;
return & V_9 [ V_8 ] ;
}
return NULL ;
}
static void F_7 ( struct V_5 * V_6 ,
T_2 V_10 , T_2 V_11 )
{
struct V_4 * V_12 = F_3 ( V_6 ) ;
T_2 V_13 ;
V_13 = F_8 ( V_14 + V_10 ) ;
if ( V_11 )
V_13 |= ( 1 << V_12 -> V_15 ) ;
else
V_13 &= ~ ( 1 << V_12 -> V_15 ) ;
F_9 ( V_13 , V_14 + V_10 ) ;
}
static void F_10 ( struct V_5 * V_6 ,
T_2 V_10 , T_2 V_11 )
{
F_11 ( & V_16 ) ;
F_7 ( V_6 , V_10 , V_11 ) ;
F_12 ( & V_16 ) ;
}
static T_2 F_13 ( struct V_5 * V_6 , T_2 V_10 )
{
struct V_4 * V_12 = F_3 ( V_6 ) ;
T_2 V_17 ;
F_11 ( & V_16 ) ;
V_17 = F_8 ( V_14 + V_10 ) ;
F_12 ( & V_16 ) ;
if ( V_17 & ( 1 << V_12 -> V_15 ) )
return 1 ;
return 0 ;
}
static void F_14 ( struct V_5 * V_6 ,
enum V_18 V_19 )
{
T_2 V_20 = 0 ;
if ( V_19 >= V_21 )
V_20 = 1 ;
F_11 ( & V_16 ) ;
if ( V_19 == 0 )
F_7 ( V_6 , V_22 , 0 ) ;
F_7 ( V_6 , V_23 , V_20 ) ;
F_12 ( & V_16 ) ;
}
static int F_15 ( struct V_5 * V_6 ,
unsigned long * V_24 ,
unsigned long * V_25 )
{
T_2 V_20 = 1 ;
if ( ! ( * V_24 == 0 && * V_25 == 0 ) &&
! ( * V_24 == 500 && * V_25 == 500 ) )
return - V_26 ;
* V_24 = 500 ;
* V_25 = 500 ;
F_10 ( V_6 , V_22 , V_20 ) ;
return 0 ;
}
static int F_16 ( struct V_27 * V_28 )
{
int V_8 ;
T_2 V_29 = 0 ;
T_2 V_30 = 0 ;
for ( V_8 = 0 ; V_8 < F_6 ( V_9 ) ; V_8 ++ )
V_30 |= ( 1 << V_9 [ V_8 ] . V_15 ) ;
F_11 ( & V_16 ) ;
V_29 = F_8 ( V_14 + V_31 ) ;
F_17 ( V_28 , L_2 , V_29 ) ;
V_29 |= V_30 + V_32 ;
F_9 ( V_29 , V_14 + V_31 ) ;
V_29 = F_8 ( V_14 + V_31 ) ;
F_17 ( V_28 , L_3 , V_29 ) ;
V_29 = F_8 ( V_14 + V_33 ) ;
F_17 ( V_28 , L_4 ,
V_29 ) ;
V_29 &= ~ V_30 ;
V_29 |= V_32 ;
F_9 ( V_29 , V_14 + V_33 ) ;
V_29 = F_8 ( V_14 + V_33 ) ;
F_17 ( V_28 , L_5 , V_29 ) ;
V_29 = F_8 ( V_14 + V_23 ) ;
F_17 ( V_28 , L_6 , V_29 ) ;
V_29 = F_8 ( V_14 + V_22 ) ;
F_17 ( V_28 , L_7 , V_29 ) ;
V_29 = F_8 ( V_14 + V_34 ) ;
F_17 ( V_28 , L_8 , V_29 ) ;
F_12 ( & V_16 ) ;
return 0 ;
}
static void F_18 ( struct V_27 * V_28 )
{
if ( V_35 ) {
F_17 ( V_28 , L_9 ) ;
F_19 ( V_14 , V_36 ) ;
V_35 = NULL ;
}
}
static int F_20 ( struct V_37 * V_28 ,
const struct V_38 * V_2 )
{
int V_39 ;
T_2 V_40 = 0 ;
V_39 = F_21 ( V_28 ) ;
if ( V_39 ) {
F_22 ( & V_28 -> V_28 , L_10 ) ;
return - V_41 ;
}
V_42 = V_28 ;
V_39 = F_23 ( V_28 , V_43 , & V_44 ) ;
if ( V_39 )
goto V_45;
V_44 &= 0x00000ff80 ;
V_39 = F_23 ( V_28 , V_46 , & V_40 ) ;
if ( ! ( V_47 & V_40 ) ) {
V_39 = - V_48 ;
F_24 ( & V_28 -> V_28 ,
L_11 ) ;
goto V_45;
}
V_39 = F_23 ( V_28 , V_49 , & V_14 ) ;
if ( 0 > V_39 ) {
F_24 ( & V_28 -> V_28 , L_12 ) ;
goto V_45;
}
F_17 ( & V_28 -> V_28 , L_13 , V_14 ) ;
V_14 &= 0x00000ffc0 ;
V_35 = F_25 ( V_14 , V_36 ,
V_50 ) ;
if ( NULL == V_35 ) {
F_24 ( & V_28 -> V_28 ,
L_14 ) ;
V_39 = - 1 ;
goto V_45;
}
F_16 ( & V_28 -> V_28 ) ;
V_45:
if ( V_39 ) {
F_18 ( & V_28 -> V_28 ) ;
F_26 ( V_28 ) ;
}
return V_39 ;
}
static void F_27 ( struct V_37 * V_28 )
{
F_18 ( & V_28 -> V_28 ) ;
F_26 ( V_28 ) ;
}
static struct V_5 * F_28 ( int V_51 )
{
struct V_4 * V_52 = & V_9 [ V_51 ] ;
struct V_5 * V_12 = & V_52 -> V_6 ;
return V_12 ;
}
static void F_29 ( void )
{
struct V_4 * V_53 = F_5 ( L_15 ) ;
struct V_4 * V_54 = F_5 ( L_16 ) ;
if ( ! V_53 || ! V_54 )
return;
F_30 ( L_17 ) ;
F_14 ( & V_54 -> V_6 , V_55 ) ;
F_14 ( & V_53 -> V_6 , V_56 ) ;
}
static T_3 F_31 ( struct V_27 * V_28 ,
struct V_57 * V_58 , char * V_59 )
{
struct V_5 * V_12 = F_32 ( V_28 ) ;
int V_60 = 0 ;
if ( F_13 ( V_12 , V_22 ) )
V_60 = 1 ;
return sprintf ( V_59 , L_18 , V_60 ) ;
}
static T_3 F_33 ( struct V_27 * V_28 ,
struct V_57 * V_58 ,
const char * V_59 , T_4 V_61 )
{
int V_62 ;
struct V_5 * V_12 = F_32 ( V_28 ) ;
unsigned long V_63 ;
V_62 = F_34 ( V_59 , 10 , & V_63 ) ;
if ( V_62 )
return V_62 ;
F_10 ( V_12 , V_22 , V_63 ) ;
return V_61 ;
}
static int F_35 ( int V_64 )
{
int V_62 ;
struct V_4 * V_52 = & V_9 [ V_64 ] ;
struct V_5 * V_12 = F_28 ( V_64 ) ;
V_12 -> V_7 = V_52 -> V_7 ;
V_12 -> V_19 = V_55 ;
if ( F_13 ( V_12 , V_23 ) )
V_12 -> V_19 = V_56 ;
V_12 -> V_65 = F_14 ;
V_12 -> V_66 = F_15 ;
V_62 = F_36 ( & V_42 -> V_28 , V_12 ) ;
if ( V_62 )
return V_62 ;
V_62 = F_37 ( V_12 -> V_28 , & V_67 ) ;
if ( V_62 )
F_38 ( V_12 ) ;
return V_62 ;
}
static void F_39 ( int V_64 )
{
struct V_5 * V_12 = F_28 ( V_64 ) ;
F_38 ( V_12 ) ;
F_40 ( V_12 -> V_28 , & V_67 ) ;
}
static int T_1 F_41 ( void )
{
int V_8 ;
int V_62 = 0 ;
int V_68 = 0 ;
V_68 = F_42 ( V_69 ) ;
if ( V_70 ) {
F_2 ( L_19 ) ;
F_2 ( L_20 ) ;
V_68 ++ ;
}
if ( V_68 <= 0 ) {
F_2 ( L_21 ) ;
return - V_71 ;
}
F_2 ( L_22 ) ;
V_62 = F_43 ( & V_72 ) ;
if ( V_62 )
return V_62 ;
for ( V_8 = 0 ; V_8 < F_6 ( V_9 ) ; V_8 ++ ) {
V_62 = F_35 ( V_8 ) ;
if ( V_62 )
goto V_73;
}
F_29 () ;
return 0 ;
V_73:
for ( V_8 -- ; V_8 >= 0 ; V_8 -- )
F_39 ( V_8 ) ;
F_44 ( & V_72 ) ;
return V_62 ;
}
static void T_5 F_45 ( void )
{
int V_8 ;
F_2 ( L_23 ) ;
for ( V_8 = 0 ; V_8 < F_6 ( V_9 ) ; V_8 ++ )
F_39 ( V_8 ) ;
F_44 ( & V_72 ) ;
}
