static int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_4 , T_1 V_5 , T_1 V_6 )
{
T_1 V_7 = V_4 ;
int V_8 ;
struct V_9 * V_10 = F_2 ( F_3 ( V_2 ) ) ;
if ( V_3 < V_11 ) {
V_7 = V_10 -> V_12 [ V_3 ] ;
V_7 &= ~ V_5 ;
V_7 |= V_4 << V_6 ;
}
V_8 = F_4 ( V_2 , V_3 , V_7 ) ;
if ( V_8 ) {
F_5 ( & V_2 -> V_13 , L_1 , V_8 ) ;
} else {
if ( V_3 < V_11 )
V_10 -> V_12 [ V_3 ] = V_7 ;
}
return V_8 ;
}
static int F_6 ( struct V_1 * V_2 , unsigned long V_14 ,
unsigned int * V_15 )
{
static const unsigned long V_16 [] = { 1000 , 4000 , 16000 , 64000 } ;
int V_17 ;
for ( V_17 = 0 ; V_17 < F_7 ( V_16 ) ; ++ V_17 ) {
if ( V_14 <= V_16 [ V_17 ] ) {
* V_15 = ( unsigned int ) V_16 [ V_17 ] ;
break;
}
}
if ( V_17 >= F_7 ( V_16 ) )
return - V_18 ;
return F_1 ( V_2 , V_19 ,
V_17 , V_20 , V_21 ) ;
}
static int F_8 ( struct V_1 * V_2 ,
unsigned long V_22 , unsigned int * V_23 )
{
static const unsigned long V_24 [] = { 16 , 12 , 8 , 4 } ;
int V_17 ;
for ( V_17 = 0 ; V_17 < F_7 ( V_24 ) ; ++ V_17 ) {
if ( V_22 >= V_24 [ V_17 ] ) {
* V_23 = ( unsigned int ) V_24 [ V_17 ] ;
break;
}
}
if ( V_17 >= F_7 ( V_24 ) )
return - V_18 ;
return F_1 ( V_2 , V_19 ,
V_17 , V_25 ,
V_26 ) ;
}
static int F_9 ( struct V_1 * V_2 , int V_27 )
{
int V_28 ;
int V_29 ;
int V_30 ;
V_28 = F_1 ( V_2 , V_31 ,
V_27 , V_32 , V_33 ) ;
if ( V_28 ) {
F_5 ( & V_2 -> V_13 , L_2 ) ;
return V_28 ;
}
F_10 ( V_34 ) ;
V_29 = F_11 ( V_2 , V_35 ) ;
if ( V_29 < 0 ) {
F_5 ( & V_2 -> V_13 , L_3 ) ;
return V_29 ;
}
V_30 = F_11 ( V_2 , V_36 ) ;
if ( V_30 < 0 ) {
F_5 ( & V_2 -> V_13 , L_4 ) ;
return V_30 ;
}
F_12 ( & V_2 -> V_13 , L_5 , V_30 , V_29 ) ;
return ( V_30 << 8 ) | V_29 ;
}
static int F_13 ( struct V_1 * V_2 , int * V_37 )
{
int V_38 ;
struct V_9 * V_10 = F_2 ( F_3 ( V_2 ) ) ;
V_38 = F_9 ( V_2 ,
V_39 ) ;
if ( V_38 < 0 )
return V_38 ;
* V_37 = ( V_38 * V_10 -> V_14 * V_10 -> V_40 ) >> V_10 -> V_41 ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 , int * V_42 )
{
int V_43 ;
V_43 = F_9 ( V_2 , V_44 ) ;
if ( V_43 < 0 )
return V_43 ;
* V_42 = V_43 ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 , int V_45 ,
int * V_46 )
{
int V_28 ;
int V_47 = - 1 ;
int V_43 = - 1 ;
V_28 = F_1 ( V_2 , V_19 ,
V_45 , V_48 , V_49 ) ;
if ( V_28 ) {
F_5 ( & V_2 -> V_13 , L_2 ) ;
return V_28 ;
}
V_47 = F_9 ( V_2 ,
V_50 ) ;
if ( V_47 < 0 )
return V_47 ;
if ( V_45 == 1 ) {
* V_46 = V_47 ;
return 0 ;
}
V_43 = F_9 ( V_2 ,
V_44 ) ;
if ( V_43 < 0 )
return V_43 ;
if ( V_47 >= V_43 )
* V_46 = V_47 - V_43 ;
else
* V_46 = 0 ;
return 0 ;
}
static T_2 F_16 ( struct V_51 * V_13 ,
struct V_52 * V_53 , char * V_54 )
{
struct V_55 * V_56 = F_17 ( V_13 ) ;
struct V_9 * V_10 = F_2 ( V_56 ) ;
return sprintf ( V_54 , L_6 , V_10 -> V_14 ) ;
}
static T_2 F_18 ( struct V_51 * V_13 ,
struct V_52 * V_53 , const char * V_54 , T_3 V_57 )
{
struct V_55 * V_56 = F_17 ( V_13 ) ;
struct V_9 * V_10 = F_2 ( V_56 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
int V_28 ;
unsigned long V_58 ;
unsigned int V_15 ;
if ( F_19 ( V_54 , 10 , & V_58 ) )
return - V_18 ;
if ( ! ( V_58 == 1000UL || V_58 == 4000UL ||
V_58 == 16000UL || V_58 == 64000UL ) ) {
F_5 ( V_13 , L_7 ) ;
return - V_18 ;
}
F_20 ( & V_10 -> V_59 ) ;
V_28 = F_6 ( V_2 , V_58 , & V_15 ) ;
if ( V_28 < 0 ) {
F_21 ( & V_10 -> V_59 ) ;
F_5 ( V_13 , L_8 ) ;
return V_28 ;
}
V_10 -> V_14 = V_15 ;
F_21 ( & V_10 -> V_59 ) ;
return V_57 ;
}
static T_2 F_22 ( struct V_51 * V_13 ,
struct V_52 * V_53 , char * V_54 )
{
struct V_55 * V_56 = F_17 ( V_13 ) ;
struct V_9 * V_10 = F_2 ( V_56 ) ;
return sprintf ( V_54 , L_6 , V_10 -> V_41 ) ;
}
static T_2 F_23 ( struct V_51 * V_13 ,
struct V_52 * V_53 , const char * V_54 , T_3 V_57 )
{
struct V_55 * V_56 = F_17 ( V_13 ) ;
struct V_9 * V_10 = F_2 ( V_56 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
int V_28 ;
unsigned long V_58 ;
unsigned int V_60 ;
if ( F_19 ( V_54 , 10 , & V_58 ) )
return - V_18 ;
if ( ! ( V_58 == 4 || V_58 == 8 || V_58 == 12 || V_58 == 16 ) ) {
F_5 ( V_13 , L_9 ) ;
return - V_18 ;
}
F_20 ( & V_10 -> V_59 ) ;
V_28 = F_8 ( V_2 , V_58 , & V_60 ) ;
if ( V_28 < 0 ) {
F_21 ( & V_10 -> V_59 ) ;
F_5 ( V_13 , L_10 ) ;
return V_28 ;
}
V_10 -> V_41 = V_60 ;
F_21 ( & V_10 -> V_59 ) ;
return V_57 ;
}
static T_2 F_24 ( struct V_51 * V_13 ,
struct V_52 * V_53 , char * V_54 )
{
struct V_55 * V_56 = F_17 ( V_13 ) ;
struct V_9 * V_10 = F_2 ( V_56 ) ;
return sprintf ( V_54 , L_11 , V_10 -> V_61 ) ;
}
static T_2 F_25 ( struct V_51 * V_13 ,
struct V_52 * V_53 , const char * V_54 , T_3 V_57 )
{
struct V_55 * V_56 = F_17 ( V_13 ) ;
struct V_9 * V_10 = F_2 ( V_56 ) ;
unsigned long V_58 ;
if ( F_19 ( V_54 , 10 , & V_58 ) )
return - V_18 ;
if ( ! ( V_58 == 0UL || V_58 == 1UL ) ) {
F_5 ( V_13 , L_12 ) ;
return - V_18 ;
}
F_20 ( & V_10 -> V_59 ) ;
V_10 -> V_61 = ( int ) V_58 ;
F_21 ( & V_10 -> V_59 ) ;
return V_57 ;
}
static int F_26 ( struct V_55 * V_56 ,
struct V_62 const * V_63 ,
int V_4 ,
int V_64 ,
long V_5 )
{
struct V_9 * V_10 = F_2 ( V_56 ) ;
int V_8 = - V_18 ;
F_20 ( & V_10 -> V_59 ) ;
if ( V_5 == ( 1 << V_65 ) &&
V_63 -> type == V_66 ) {
V_10 -> V_40 = V_4 ;
V_8 = 0 ;
}
F_21 ( & V_10 -> V_59 ) ;
return 0 ;
}
static int F_27 ( struct V_55 * V_56 ,
struct V_62 const * V_63 ,
int * V_4 ,
int * V_64 ,
long V_5 )
{
int V_8 = - V_18 ;
struct V_9 * V_10 = F_2 ( V_56 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
F_20 ( & V_10 -> V_59 ) ;
switch ( V_5 ) {
case 0 :
switch ( V_63 -> type ) {
case V_66 :
V_8 = F_13 ( V_2 , V_4 ) ;
break;
case V_67 :
V_8 = F_14 ( V_2 , V_4 ) ;
break;
case V_68 :
V_8 = F_15 ( V_2 ,
V_10 -> V_61 , V_4 ) ;
break;
default:
break;
}
if ( ! V_8 )
V_8 = V_69 ;
break;
case ( 1 << V_65 ) :
if ( V_63 -> type == V_66 ) {
* V_4 = V_10 -> V_40 ;
V_8 = V_69 ;
}
break;
default:
break;
}
F_21 ( & V_10 -> V_59 ) ;
return V_8 ;
}
static int F_28 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_2 ( F_3 ( V_2 ) ) ;
int V_28 ;
int V_60 ;
unsigned int V_15 ;
memset ( V_10 -> V_12 , 0 , sizeof( V_10 -> V_12 ) ) ;
V_28 = F_1 ( V_2 , V_70 , 0 ,
V_71 , V_72 ) ;
if ( V_28 < 0 ) {
F_5 ( & V_2 -> V_13 , L_13
L_14 , V_28 ) ;
return V_28 ;
}
V_28 = F_1 ( V_2 , V_31 , 0 ,
0xff , 0 ) ;
if ( V_28 < 0 ) {
F_5 ( & V_2 -> V_13 , L_15
L_14 , V_28 ) ;
return V_28 ;
}
F_10 ( 1 ) ;
V_28 = F_6 ( V_2 , V_10 -> V_14 , & V_15 ) ;
if ( V_28 < 0 ) {
F_5 ( & V_2 -> V_13 , L_16 ) ;
return V_28 ;
}
V_28 = F_8 ( V_2 , V_10 -> V_41 ,
& V_60 ) ;
return 0 ;
}
static int T_4 F_29 ( struct V_1 * V_2 ,
const struct V_73 * V_74 )
{
struct V_9 * V_10 ;
struct V_55 * V_56 ;
int V_75 ;
V_56 = F_30 ( sizeof( * V_10 ) ) ;
if ( V_56 == NULL ) {
F_5 ( & V_2 -> V_13 , L_17 ) ;
V_75 = - V_76 ;
goto exit;
}
V_10 = F_2 ( V_56 ) ;
F_31 ( V_2 , V_56 ) ;
V_10 -> V_2 = V_2 ;
F_32 ( & V_10 -> V_59 ) ;
V_10 -> V_40 = 1 ;
V_10 -> V_14 = 1000 ;
V_10 -> V_41 = 16 ;
V_75 = F_28 ( V_2 ) ;
if ( V_75 )
goto V_77;
V_56 -> V_78 = & V_79 ;
V_56 -> V_80 = V_81 ;
V_56 -> V_82 = F_7 ( V_81 ) ;
V_56 -> V_83 = V_74 -> V_83 ;
V_56 -> V_13 . V_84 = & V_2 -> V_13 ;
V_56 -> V_85 = V_86 ;
V_75 = F_33 ( V_56 ) ;
if ( V_75 ) {
F_5 ( & V_2 -> V_13 , L_18 ) ;
goto V_77;
}
return 0 ;
V_77:
F_34 ( V_56 ) ;
exit:
return V_75 ;
}
static int T_5 F_35 ( struct V_1 * V_2 )
{
struct V_55 * V_56 = F_3 ( V_2 ) ;
F_36 ( & V_2 -> V_13 , L_19 , V_87 ) ;
F_37 ( V_56 ) ;
F_34 ( V_56 ) ;
return 0 ;
}
static int T_6 F_38 ( void )
{
return F_39 ( & V_88 ) ;
}
static void T_7 F_40 ( void )
{
F_41 ( & V_88 ) ;
}
