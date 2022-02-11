static int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_4 , T_1 V_5 , T_1 V_6 )
{
T_1 V_7 ;
int V_8 = 0 ;
struct V_9 * V_10 = F_2 ( F_3 ( V_2 ) ) ;
V_7 = V_10 -> V_11 [ V_3 ] ;
V_7 &= ~ V_5 ;
V_7 |= V_4 << V_6 ;
V_8 = F_4 ( V_2 , V_3 , V_7 ) ;
if ( V_8 ) {
F_5 ( & V_2 -> V_12 , L_1 , V_8 ) ;
return V_8 ;
}
V_10 -> V_11 [ V_3 ] = V_7 ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , unsigned long V_13 ,
unsigned int * V_14 )
{
static const unsigned long V_15 [] = { 1000 , 4000 , 16000 , 64000 } ;
int V_16 ;
for ( V_16 = 0 ; V_16 < F_7 ( V_15 ) ; ++ V_16 ) {
if ( V_13 <= V_15 [ V_16 ] ) {
* V_14 = ( unsigned int ) V_15 [ V_16 ] ;
break;
}
}
if ( V_16 >= F_7 ( V_15 ) )
return - V_17 ;
return F_1 ( V_2 , V_18 ,
V_16 , V_19 , V_20 ) ;
}
static int F_8 ( struct V_1 * V_2 ,
unsigned long V_21 , unsigned int * V_22 )
{
static const unsigned long V_23 [] = { 16 , 12 , 8 , 4 } ;
int V_16 ;
for ( V_16 = 0 ; V_16 < F_7 ( V_23 ) ; ++ V_16 ) {
if ( V_21 >= V_23 [ V_16 ] ) {
* V_22 = ( unsigned int ) V_23 [ V_16 ] ;
break;
}
}
if ( V_16 >= F_7 ( V_23 ) )
return - V_17 ;
return F_1 ( V_2 , V_18 ,
V_16 , V_24 ,
V_25 ) ;
}
static int F_9 ( struct V_1 * V_2 , int V_26 )
{
int V_27 ;
int V_28 ;
int V_29 ;
V_27 = F_1 ( V_2 , V_30 ,
V_26 , V_31 , V_32 ) ;
if ( V_27 ) {
F_5 ( & V_2 -> V_12 , L_2 ) ;
return V_27 ;
}
F_10 ( V_33 ) ;
V_28 = F_11 ( V_2 , V_34 ) ;
if ( V_28 < 0 ) {
F_5 ( & V_2 -> V_12 , L_3 ) ;
return V_28 ;
}
V_29 = F_11 ( V_2 , V_35 ) ;
if ( V_29 < 0 ) {
F_5 ( & V_2 -> V_12 , L_4 ) ;
return V_29 ;
}
F_12 ( & V_2 -> V_12 , L_5 , V_29 , V_28 ) ;
return ( V_29 << 8 ) | V_28 ;
}
static int F_13 ( struct V_1 * V_2 , int * V_36 )
{
int V_37 ;
struct V_9 * V_10 = F_2 ( F_3 ( V_2 ) ) ;
V_37 = F_9 ( V_2 ,
V_38 ) ;
if ( V_37 < 0 )
return V_37 ;
* V_36 = ( V_37 * V_10 -> V_13 * V_10 -> V_39 ) >> V_10 -> V_40 ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 , int * V_41 )
{
int V_42 ;
V_42 = F_9 ( V_2 , V_43 ) ;
if ( V_42 < 0 )
return V_42 ;
* V_41 = V_42 ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 , int V_44 ,
int * V_45 )
{
int V_27 ;
int V_46 = - 1 ;
int V_42 = - 1 ;
V_27 = F_1 ( V_2 , V_18 ,
V_44 , V_47 , V_48 ) ;
if ( V_27 ) {
F_5 ( & V_2 -> V_12 , L_2 ) ;
return V_27 ;
}
V_46 = F_9 ( V_2 ,
V_49 ) ;
if ( V_46 < 0 )
return V_46 ;
if ( V_44 == 1 ) {
* V_45 = V_46 ;
return 0 ;
}
V_42 = F_9 ( V_2 ,
V_43 ) ;
if ( V_42 < 0 )
return V_42 ;
if ( V_46 >= V_42 )
* V_45 = V_46 - V_42 ;
else
* V_45 = 0 ;
return 0 ;
}
static T_2 F_16 ( struct V_50 * V_12 ,
struct V_51 * V_52 , char * V_53 )
{
struct V_54 * V_55 = F_17 ( V_12 ) ;
struct V_9 * V_10 = F_2 ( V_55 ) ;
return sprintf ( V_53 , L_6 , V_10 -> V_13 ) ;
}
static T_2 F_18 ( struct V_50 * V_12 ,
struct V_51 * V_52 , const char * V_53 , T_3 V_56 )
{
struct V_54 * V_55 = F_17 ( V_12 ) ;
struct V_9 * V_10 = F_2 ( V_55 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
int V_27 ;
unsigned long V_57 ;
unsigned int V_14 ;
if ( F_19 ( V_53 , 10 , & V_57 ) )
return - V_17 ;
if ( ! ( V_57 == 1000UL || V_57 == 4000UL ||
V_57 == 16000UL || V_57 == 64000UL ) ) {
F_5 ( V_12 , L_7 ) ;
return - V_17 ;
}
F_20 ( & V_10 -> V_58 ) ;
V_27 = F_6 ( V_2 , V_57 , & V_14 ) ;
if ( V_27 < 0 ) {
F_21 ( & V_10 -> V_58 ) ;
F_5 ( V_12 , L_8 ) ;
return V_27 ;
}
V_10 -> V_13 = V_14 ;
F_21 ( & V_10 -> V_58 ) ;
return V_56 ;
}
static T_2 F_22 ( struct V_50 * V_12 ,
struct V_51 * V_52 , char * V_53 )
{
struct V_54 * V_55 = F_17 ( V_12 ) ;
struct V_9 * V_10 = F_2 ( V_55 ) ;
return sprintf ( V_53 , L_6 , V_10 -> V_40 ) ;
}
static T_2 F_23 ( struct V_50 * V_12 ,
struct V_51 * V_52 , const char * V_53 , T_3 V_56 )
{
struct V_54 * V_55 = F_17 ( V_12 ) ;
struct V_9 * V_10 = F_2 ( V_55 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
int V_27 ;
unsigned long V_57 ;
unsigned int V_59 ;
if ( F_19 ( V_53 , 10 , & V_57 ) )
return - V_17 ;
if ( ! ( V_57 == 4 || V_57 == 8 || V_57 == 12 || V_57 == 16 ) ) {
F_5 ( V_12 , L_9 ) ;
return - V_17 ;
}
F_20 ( & V_10 -> V_58 ) ;
V_27 = F_8 ( V_2 , V_57 , & V_59 ) ;
if ( V_27 < 0 ) {
F_21 ( & V_10 -> V_58 ) ;
F_5 ( V_12 , L_10 ) ;
return V_27 ;
}
V_10 -> V_40 = V_59 ;
F_21 ( & V_10 -> V_58 ) ;
return V_56 ;
}
static T_2 F_24 ( struct V_50 * V_12 ,
struct V_51 * V_52 , char * V_53 )
{
struct V_54 * V_55 = F_17 ( V_12 ) ;
struct V_9 * V_10 = F_2 ( V_55 ) ;
return sprintf ( V_53 , L_11 , V_10 -> V_60 ) ;
}
static T_2 F_25 ( struct V_50 * V_12 ,
struct V_51 * V_52 , const char * V_53 , T_3 V_56 )
{
struct V_54 * V_55 = F_17 ( V_12 ) ;
struct V_9 * V_10 = F_2 ( V_55 ) ;
unsigned long V_57 ;
if ( F_19 ( V_53 , 10 , & V_57 ) )
return - V_17 ;
if ( ! ( V_57 == 0UL || V_57 == 1UL ) ) {
F_5 ( V_12 , L_12 ) ;
return - V_17 ;
}
F_20 ( & V_10 -> V_58 ) ;
V_10 -> V_60 = ( int ) V_57 ;
F_21 ( & V_10 -> V_58 ) ;
return V_56 ;
}
static int F_26 ( struct V_54 * V_55 ,
struct V_61 const * V_62 ,
int V_4 ,
int V_63 ,
long V_5 )
{
struct V_9 * V_10 = F_2 ( V_55 ) ;
int V_8 = - V_17 ;
F_20 ( & V_10 -> V_58 ) ;
if ( V_5 == ( 1 << V_64 ) &&
V_62 -> type == V_65 ) {
V_10 -> V_39 = V_4 ;
V_8 = 0 ;
}
F_21 ( & V_10 -> V_58 ) ;
return 0 ;
}
static int F_27 ( struct V_54 * V_55 ,
struct V_61 const * V_62 ,
int * V_4 ,
int * V_63 ,
long V_5 )
{
int V_8 = - V_17 ;
struct V_9 * V_10 = F_2 ( V_55 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
F_20 ( & V_10 -> V_58 ) ;
switch ( V_5 ) {
case 0 :
switch ( V_62 -> type ) {
case V_65 :
V_8 = F_13 ( V_2 , V_4 ) ;
break;
case V_66 :
V_8 = F_14 ( V_2 , V_4 ) ;
break;
case V_67 :
V_8 = F_15 ( V_2 ,
V_10 -> V_60 , V_4 ) ;
break;
default:
break;
}
if ( ! V_8 )
V_8 = V_68 ;
break;
case ( 1 << V_64 ) :
if ( V_62 -> type == V_65 ) {
* V_4 = V_10 -> V_39 ;
V_8 = V_68 ;
}
break;
default:
break;
}
F_21 ( & V_10 -> V_58 ) ;
return V_8 ;
}
static int F_28 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_2 ( F_3 ( V_2 ) ) ;
int V_27 ;
int V_59 ;
unsigned int V_14 ;
memset ( V_10 -> V_11 , 0 , sizeof( V_10 -> V_11 ) ) ;
V_27 = F_6 ( V_2 , V_10 -> V_13 , & V_14 ) ;
if ( V_27 < 0 ) {
F_5 ( & V_2 -> V_12 , L_13 ) ;
return V_27 ;
}
V_27 = F_8 ( V_2 , V_10 -> V_40 ,
& V_59 ) ;
return 0 ;
}
static int T_4 F_29 ( struct V_1 * V_2 ,
const struct V_69 * V_70 )
{
struct V_9 * V_10 ;
struct V_54 * V_55 ;
int V_71 ;
V_55 = F_30 ( sizeof( * V_10 ) ) ;
if ( V_55 == NULL ) {
F_5 ( & V_2 -> V_12 , L_14 ) ;
V_71 = - V_72 ;
goto exit;
}
V_10 = F_2 ( V_55 ) ;
F_31 ( V_2 , V_55 ) ;
V_10 -> V_2 = V_2 ;
F_32 ( & V_10 -> V_58 ) ;
V_10 -> V_39 = 1 ;
V_10 -> V_13 = 1000 ;
V_10 -> V_40 = 16 ;
V_71 = F_28 ( V_2 ) ;
if ( V_71 )
goto V_73;
V_55 -> V_74 = & V_75 ;
V_55 -> V_76 = V_77 ;
V_55 -> V_78 = F_7 ( V_77 ) ;
V_55 -> V_79 = V_70 -> V_79 ;
V_55 -> V_12 . V_80 = & V_2 -> V_12 ;
V_55 -> V_81 = V_82 ;
V_71 = F_33 ( V_55 ) ;
if ( V_71 ) {
F_5 ( & V_2 -> V_12 , L_15 ) ;
goto V_73;
}
return 0 ;
V_73:
F_34 ( V_55 ) ;
exit:
return V_71 ;
}
static int T_5 F_35 ( struct V_1 * V_2 )
{
struct V_54 * V_55 = F_3 ( V_2 ) ;
F_36 ( & V_2 -> V_12 , L_16 , V_83 ) ;
F_37 ( V_55 ) ;
return 0 ;
}
static int T_6 F_38 ( void )
{
return F_39 ( & V_84 ) ;
}
static void T_7 F_40 ( void )
{
F_41 ( & V_84 ) ;
}
