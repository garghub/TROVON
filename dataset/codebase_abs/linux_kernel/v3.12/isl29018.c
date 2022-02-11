static int F_1 ( struct V_1 * V_2 , unsigned long V_3 ,
unsigned int * V_4 )
{
static const unsigned long V_5 [] = { 1000 , 4000 , 16000 , 64000 } ;
int V_6 ;
for ( V_6 = 0 ; V_6 < F_2 ( V_5 ) ; ++ V_6 ) {
if ( V_3 <= V_5 [ V_6 ] ) {
* V_4 = ( unsigned int ) V_5 [ V_6 ] ;
break;
}
}
if ( V_6 >= F_2 ( V_5 ) )
return - V_7 ;
return F_3 ( V_2 -> V_8 , V_9 ,
V_10 , V_6 << V_11 ) ;
}
static int F_4 ( struct V_1 * V_2 ,
unsigned long V_12 , unsigned int * V_13 )
{
static const unsigned long V_14 [] = { 16 , 12 , 8 , 4 } ;
int V_6 ;
for ( V_6 = 0 ; V_6 < F_2 ( V_14 ) ; ++ V_6 ) {
if ( V_12 >= V_14 [ V_6 ] ) {
* V_13 = ( unsigned int ) V_14 [ V_6 ] ;
break;
}
}
if ( V_6 >= F_2 ( V_14 ) )
return - V_7 ;
return F_3 ( V_2 -> V_8 , V_9 ,
V_15 ,
V_6 << V_16 ) ;
}
static int F_5 ( struct V_1 * V_2 , int V_17 )
{
int V_18 ;
unsigned int V_19 ;
unsigned int V_20 ;
V_18 = F_6 ( V_2 -> V_8 , V_21 ,
V_17 << V_22 ) ;
if ( V_18 ) {
F_7 ( V_2 -> V_23 ,
L_1 , V_18 ) ;
return V_18 ;
}
F_8 ( V_24 ) ;
V_18 = F_9 ( V_2 -> V_8 , V_25 , & V_19 ) ;
if ( V_18 < 0 ) {
F_7 ( V_2 -> V_23 ,
L_2 , V_18 ) ;
return V_18 ;
}
V_18 = F_9 ( V_2 -> V_8 , V_26 , & V_20 ) ;
if ( V_18 < 0 ) {
F_7 ( V_2 -> V_23 ,
L_3 , V_18 ) ;
return V_18 ;
}
F_10 ( V_2 -> V_23 , L_4 , V_20 , V_19 ) ;
return ( V_20 << 8 ) | V_19 ;
}
static int F_11 ( struct V_1 * V_2 , int * V_27 )
{
int V_28 ;
unsigned int V_29 , V_30 ;
V_28 = F_5 ( V_2 , V_31 ) ;
if ( V_28 < 0 )
return V_28 ;
V_29 = V_28 * V_2 -> V_3 ;
V_30 = V_29 * V_2 -> V_32 ;
V_30 += V_29 / 1000 * V_2 -> V_33 / 1000 ;
* V_27 = V_30 >> V_2 -> V_34 ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 , int * V_35 )
{
int V_36 ;
V_36 = F_5 ( V_2 , V_37 ) ;
if ( V_36 < 0 )
return V_36 ;
* V_35 = V_36 ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 , int V_38 ,
int * V_39 )
{
int V_18 ;
int V_40 = - 1 ;
int V_36 = - 1 ;
V_18 = F_3 ( V_2 -> V_8 , V_9 ,
V_41 ,
V_38 << V_42 ) ;
if ( V_18 ) {
F_7 ( V_2 -> V_23 , L_5 ) ;
return V_18 ;
}
V_40 = F_5 ( V_2 ,
V_43 ) ;
if ( V_40 < 0 )
return V_40 ;
if ( V_38 == 1 ) {
* V_39 = V_40 ;
return 0 ;
}
V_36 = F_5 ( V_2 , V_37 ) ;
if ( V_36 < 0 )
return V_36 ;
if ( V_40 >= V_36 )
* V_39 = V_40 - V_36 ;
else
* V_39 = 0 ;
return 0 ;
}
static T_1 F_14 ( struct V_44 * V_23 ,
struct V_45 * V_46 , char * V_47 )
{
struct V_48 * V_49 = F_15 ( V_23 ) ;
struct V_1 * V_2 = F_16 ( V_49 ) ;
return sprintf ( V_47 , L_6 , V_2 -> V_3 ) ;
}
static T_1 F_17 ( struct V_44 * V_23 ,
struct V_45 * V_46 , const char * V_47 , T_2 V_50 )
{
struct V_48 * V_49 = F_15 ( V_23 ) ;
struct V_1 * V_2 = F_16 ( V_49 ) ;
int V_18 ;
unsigned long V_51 ;
unsigned int V_4 ;
if ( F_18 ( V_47 , 10 , & V_51 ) )
return - V_7 ;
if ( ! ( V_51 == 1000UL || V_51 == 4000UL ||
V_51 == 16000UL || V_51 == 64000UL ) ) {
F_7 ( V_23 , L_7 ) ;
return - V_7 ;
}
F_19 ( & V_2 -> V_52 ) ;
V_18 = F_1 ( V_2 , V_51 , & V_4 ) ;
if ( V_18 < 0 ) {
F_20 ( & V_2 -> V_52 ) ;
F_7 ( V_23 ,
L_8 , V_18 ) ;
return V_18 ;
}
V_2 -> V_3 = V_4 ;
F_20 ( & V_2 -> V_52 ) ;
return V_50 ;
}
static T_1 F_21 ( struct V_44 * V_23 ,
struct V_45 * V_46 , char * V_47 )
{
struct V_48 * V_49 = F_15 ( V_23 ) ;
struct V_1 * V_2 = F_16 ( V_49 ) ;
return sprintf ( V_47 , L_6 , V_2 -> V_34 ) ;
}
static T_1 F_22 ( struct V_44 * V_23 ,
struct V_45 * V_46 , const char * V_47 , T_2 V_50 )
{
struct V_48 * V_49 = F_15 ( V_23 ) ;
struct V_1 * V_2 = F_16 ( V_49 ) ;
int V_18 ;
unsigned long V_51 ;
unsigned int V_53 ;
if ( F_18 ( V_47 , 10 , & V_51 ) )
return - V_7 ;
if ( ! ( V_51 == 4 || V_51 == 8 || V_51 == 12 || V_51 == 16 ) ) {
F_7 ( V_23 , L_9 ) ;
return - V_7 ;
}
F_19 ( & V_2 -> V_52 ) ;
V_18 = F_4 ( V_2 , V_51 , & V_53 ) ;
if ( V_18 < 0 ) {
F_20 ( & V_2 -> V_52 ) ;
F_7 ( V_23 , L_10 ) ;
return V_18 ;
}
V_2 -> V_34 = V_53 ;
F_20 ( & V_2 -> V_52 ) ;
return V_50 ;
}
static T_1 F_23 ( struct V_44 * V_23 ,
struct V_45 * V_46 , char * V_47 )
{
struct V_48 * V_49 = F_15 ( V_23 ) ;
struct V_1 * V_2 = F_16 ( V_49 ) ;
return sprintf ( V_47 , L_11 , V_2 -> V_54 ) ;
}
static T_1 F_24 ( struct V_44 * V_23 ,
struct V_45 * V_46 , const char * V_47 , T_2 V_50 )
{
struct V_48 * V_49 = F_15 ( V_23 ) ;
struct V_1 * V_2 = F_16 ( V_49 ) ;
unsigned long V_51 ;
if ( F_18 ( V_47 , 10 , & V_51 ) )
return - V_7 ;
if ( ! ( V_51 == 0UL || V_51 == 1UL ) ) {
F_7 ( V_23 , L_12 ) ;
return - V_7 ;
}
F_19 ( & V_2 -> V_52 ) ;
V_2 -> V_54 = ( int ) V_51 ;
F_20 ( & V_2 -> V_52 ) ;
return V_50 ;
}
static int F_25 ( struct V_48 * V_49 ,
struct V_55 const * V_56 ,
int V_57 ,
int V_58 ,
long V_59 )
{
struct V_1 * V_2 = F_16 ( V_49 ) ;
int V_60 = - V_7 ;
F_19 ( & V_2 -> V_52 ) ;
if ( V_59 == V_61 && V_56 -> type == V_62 ) {
V_2 -> V_32 = V_57 ;
V_2 -> V_33 = V_58 ;
V_60 = 0 ;
}
F_20 ( & V_2 -> V_52 ) ;
return V_60 ;
}
static int F_26 ( struct V_48 * V_49 ,
struct V_55 const * V_56 ,
int * V_57 ,
int * V_58 ,
long V_59 )
{
int V_60 = - V_7 ;
struct V_1 * V_2 = F_16 ( V_49 ) ;
F_19 ( & V_2 -> V_52 ) ;
if ( V_2 -> V_63 ) {
F_20 ( & V_2 -> V_52 ) ;
return - V_64 ;
}
switch ( V_59 ) {
case V_65 :
case V_66 :
switch ( V_56 -> type ) {
case V_62 :
V_60 = F_11 ( V_2 , V_57 ) ;
break;
case V_67 :
V_60 = F_12 ( V_2 , V_57 ) ;
break;
case V_68 :
V_60 = F_13 ( V_2 ,
V_2 -> V_54 , V_57 ) ;
break;
default:
break;
}
if ( ! V_60 )
V_60 = V_69 ;
break;
case V_61 :
if ( V_56 -> type == V_62 ) {
* V_57 = V_2 -> V_32 ;
* V_58 = V_2 -> V_33 ;
V_60 = V_70 ;
}
break;
default:
break;
}
F_20 ( & V_2 -> V_52 ) ;
return V_60 ;
}
static int F_27 ( struct V_1 * V_2 )
{
int V_18 ;
int V_53 ;
unsigned int V_4 ;
V_18 = F_6 ( V_2 -> V_8 , V_71 , 0x0 ) ;
if ( V_18 < 0 ) {
F_7 ( V_2 -> V_23 , L_13
L_14 , V_18 ) ;
return V_18 ;
}
V_18 = F_6 ( V_2 -> V_8 , V_21 , 0 ) ;
if ( V_18 < 0 ) {
F_7 ( V_2 -> V_23 , L_15
L_14 , V_18 ) ;
return V_18 ;
}
F_8 ( 1 ) ;
V_18 = F_1 ( V_2 , V_2 -> V_3 , & V_4 ) ;
if ( V_18 < 0 ) {
F_7 ( V_2 -> V_23 , L_16 ) ;
return V_18 ;
}
V_18 = F_4 ( V_2 , V_2 -> V_34 ,
& V_53 ) ;
return 0 ;
}
static bool F_28 ( struct V_44 * V_23 , unsigned int V_72 )
{
switch ( V_72 ) {
case V_25 :
case V_26 :
case V_21 :
case V_71 :
return true ;
default:
return false ;
}
}
static int F_29 ( struct V_73 * V_74 ,
const struct V_75 * V_76 )
{
struct V_1 * V_2 ;
struct V_48 * V_49 ;
int V_77 ;
V_49 = F_30 ( & V_74 -> V_23 , sizeof( * V_2 ) ) ;
if ( V_49 == NULL ) {
F_7 ( & V_74 -> V_23 , L_17 ) ;
return - V_78 ;
}
V_2 = F_16 ( V_49 ) ;
F_31 ( V_74 , V_49 ) ;
V_2 -> V_23 = & V_74 -> V_23 ;
F_32 ( & V_2 -> V_52 ) ;
V_2 -> V_32 = 1 ;
V_2 -> V_33 = 0 ;
V_2 -> V_3 = 1000 ;
V_2 -> V_34 = 16 ;
V_2 -> V_63 = false ;
V_2 -> V_8 = F_33 ( V_74 , & V_79 ) ;
if ( F_34 ( V_2 -> V_8 ) ) {
V_77 = F_35 ( V_2 -> V_8 ) ;
F_7 ( V_2 -> V_23 , L_18 , V_77 ) ;
return V_77 ;
}
V_77 = F_27 ( V_2 ) ;
if ( V_77 )
return V_77 ;
V_49 -> V_80 = & V_81 ;
V_49 -> V_82 = V_83 ;
V_49 -> V_84 = F_2 ( V_83 ) ;
V_49 -> V_85 = V_76 -> V_85 ;
V_49 -> V_23 . V_86 = & V_74 -> V_23 ;
V_49 -> V_87 = V_88 ;
V_77 = F_36 ( V_49 ) ;
if ( V_77 ) {
F_7 ( & V_74 -> V_23 , L_19 ) ;
return V_77 ;
}
return 0 ;
}
static int F_37 ( struct V_73 * V_74 )
{
struct V_48 * V_49 = F_38 ( V_74 ) ;
F_39 ( & V_74 -> V_23 , L_20 , V_89 ) ;
F_40 ( V_49 ) ;
return 0 ;
}
static int F_41 ( struct V_44 * V_23 )
{
struct V_1 * V_2 = F_16 ( F_42 ( V_23 ) ) ;
F_19 ( & V_2 -> V_52 ) ;
V_2 -> V_63 = true ;
F_20 ( & V_2 -> V_52 ) ;
return 0 ;
}
static int F_43 ( struct V_44 * V_23 )
{
struct V_1 * V_2 = F_16 ( F_42 ( V_23 ) ) ;
int V_77 ;
F_19 ( & V_2 -> V_52 ) ;
V_77 = F_27 ( V_2 ) ;
if ( ! V_77 )
V_2 -> V_63 = false ;
F_20 ( & V_2 -> V_52 ) ;
return V_77 ;
}
