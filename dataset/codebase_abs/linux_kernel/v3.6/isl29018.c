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
V_28 = F_5 ( V_2 , V_29 ) ;
if ( V_28 < 0 )
return V_28 ;
* V_27 = ( V_28 * V_2 -> V_3 * V_2 -> V_30 ) >> V_2 -> V_31 ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 , int * V_32 )
{
int V_33 ;
V_33 = F_5 ( V_2 , V_34 ) ;
if ( V_33 < 0 )
return V_33 ;
* V_32 = V_33 ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 , int V_35 ,
int * V_36 )
{
int V_18 ;
int V_37 = - 1 ;
int V_33 = - 1 ;
V_18 = F_3 ( V_2 -> V_8 , V_9 ,
V_38 ,
V_35 << V_39 ) ;
if ( V_18 ) {
F_7 ( V_2 -> V_23 , L_5 ) ;
return V_18 ;
}
V_37 = F_5 ( V_2 ,
V_40 ) ;
if ( V_37 < 0 )
return V_37 ;
if ( V_35 == 1 ) {
* V_36 = V_37 ;
return 0 ;
}
V_33 = F_5 ( V_2 , V_34 ) ;
if ( V_33 < 0 )
return V_33 ;
if ( V_37 >= V_33 )
* V_36 = V_37 - V_33 ;
else
* V_36 = 0 ;
return 0 ;
}
static T_1 F_14 ( struct V_41 * V_23 ,
struct V_42 * V_43 , char * V_44 )
{
struct V_45 * V_46 = F_15 ( V_23 ) ;
struct V_1 * V_2 = F_16 ( V_46 ) ;
return sprintf ( V_44 , L_6 , V_2 -> V_3 ) ;
}
static T_1 F_17 ( struct V_41 * V_23 ,
struct V_42 * V_43 , const char * V_44 , T_2 V_47 )
{
struct V_45 * V_46 = F_15 ( V_23 ) ;
struct V_1 * V_2 = F_16 ( V_46 ) ;
int V_18 ;
unsigned long V_48 ;
unsigned int V_4 ;
if ( F_18 ( V_44 , 10 , & V_48 ) )
return - V_7 ;
if ( ! ( V_48 == 1000UL || V_48 == 4000UL ||
V_48 == 16000UL || V_48 == 64000UL ) ) {
F_7 ( V_23 , L_7 ) ;
return - V_7 ;
}
F_19 ( & V_2 -> V_49 ) ;
V_18 = F_1 ( V_2 , V_48 , & V_4 ) ;
if ( V_18 < 0 ) {
F_20 ( & V_2 -> V_49 ) ;
F_7 ( V_23 ,
L_8 , V_18 ) ;
return V_18 ;
}
V_2 -> V_3 = V_4 ;
F_20 ( & V_2 -> V_49 ) ;
return V_47 ;
}
static T_1 F_21 ( struct V_41 * V_23 ,
struct V_42 * V_43 , char * V_44 )
{
struct V_45 * V_46 = F_15 ( V_23 ) ;
struct V_1 * V_2 = F_16 ( V_46 ) ;
return sprintf ( V_44 , L_6 , V_2 -> V_31 ) ;
}
static T_1 F_22 ( struct V_41 * V_23 ,
struct V_42 * V_43 , const char * V_44 , T_2 V_47 )
{
struct V_45 * V_46 = F_15 ( V_23 ) ;
struct V_1 * V_2 = F_16 ( V_46 ) ;
int V_18 ;
unsigned long V_48 ;
unsigned int V_50 ;
if ( F_18 ( V_44 , 10 , & V_48 ) )
return - V_7 ;
if ( ! ( V_48 == 4 || V_48 == 8 || V_48 == 12 || V_48 == 16 ) ) {
F_7 ( V_23 , L_9 ) ;
return - V_7 ;
}
F_19 ( & V_2 -> V_49 ) ;
V_18 = F_4 ( V_2 , V_48 , & V_50 ) ;
if ( V_18 < 0 ) {
F_20 ( & V_2 -> V_49 ) ;
F_7 ( V_23 , L_10 ) ;
return V_18 ;
}
V_2 -> V_31 = V_50 ;
F_20 ( & V_2 -> V_49 ) ;
return V_47 ;
}
static T_1 F_23 ( struct V_41 * V_23 ,
struct V_42 * V_43 , char * V_44 )
{
struct V_45 * V_46 = F_15 ( V_23 ) ;
struct V_1 * V_2 = F_16 ( V_46 ) ;
return sprintf ( V_44 , L_11 , V_2 -> V_51 ) ;
}
static T_1 F_24 ( struct V_41 * V_23 ,
struct V_42 * V_43 , const char * V_44 , T_2 V_47 )
{
struct V_45 * V_46 = F_15 ( V_23 ) ;
struct V_1 * V_2 = F_16 ( V_46 ) ;
unsigned long V_48 ;
if ( F_18 ( V_44 , 10 , & V_48 ) )
return - V_7 ;
if ( ! ( V_48 == 0UL || V_48 == 1UL ) ) {
F_7 ( V_23 , L_12 ) ;
return - V_7 ;
}
F_19 ( & V_2 -> V_49 ) ;
V_2 -> V_51 = ( int ) V_48 ;
F_20 ( & V_2 -> V_49 ) ;
return V_47 ;
}
static int F_25 ( struct V_45 * V_46 ,
struct V_52 const * V_53 ,
int V_54 ,
int V_55 ,
long V_56 )
{
struct V_1 * V_2 = F_16 ( V_46 ) ;
int V_57 = - V_7 ;
F_19 ( & V_2 -> V_49 ) ;
if ( V_56 == V_58 && V_53 -> type == V_59 ) {
V_2 -> V_30 = V_54 ;
V_57 = 0 ;
}
F_20 ( & V_2 -> V_49 ) ;
return 0 ;
}
static int F_26 ( struct V_45 * V_46 ,
struct V_52 const * V_53 ,
int * V_54 ,
int * V_55 ,
long V_56 )
{
int V_57 = - V_7 ;
struct V_1 * V_2 = F_16 ( V_46 ) ;
F_19 ( & V_2 -> V_49 ) ;
switch ( V_56 ) {
case V_60 :
case V_61 :
switch ( V_53 -> type ) {
case V_59 :
V_57 = F_11 ( V_2 , V_54 ) ;
break;
case V_62 :
V_57 = F_12 ( V_2 , V_54 ) ;
break;
case V_63 :
V_57 = F_13 ( V_2 ,
V_2 -> V_51 , V_54 ) ;
break;
default:
break;
}
if ( ! V_57 )
V_57 = V_64 ;
break;
case V_58 :
if ( V_53 -> type == V_59 ) {
* V_54 = V_2 -> V_30 ;
V_57 = V_64 ;
}
break;
default:
break;
}
F_20 ( & V_2 -> V_49 ) ;
return V_57 ;
}
static int F_27 ( struct V_1 * V_2 )
{
int V_18 ;
int V_50 ;
unsigned int V_4 ;
V_18 = F_6 ( V_2 -> V_8 , V_65 , 0x0 ) ;
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
V_18 = F_4 ( V_2 , V_2 -> V_31 ,
& V_50 ) ;
return 0 ;
}
static bool F_28 ( struct V_41 * V_23 , unsigned int V_66 )
{
switch ( V_66 ) {
case V_25 :
case V_26 :
case V_21 :
case V_65 :
return true ;
default:
return false ;
}
}
static int T_3 F_29 ( struct V_67 * V_68 ,
const struct V_69 * V_70 )
{
struct V_1 * V_2 ;
struct V_45 * V_46 ;
int V_71 ;
V_46 = F_30 ( sizeof( * V_2 ) ) ;
if ( V_46 == NULL ) {
F_7 ( & V_68 -> V_23 , L_17 ) ;
V_71 = - V_72 ;
goto exit;
}
V_2 = F_16 ( V_46 ) ;
F_31 ( V_68 , V_46 ) ;
V_2 -> V_23 = & V_68 -> V_23 ;
F_32 ( & V_2 -> V_49 ) ;
V_2 -> V_30 = 1 ;
V_2 -> V_3 = 1000 ;
V_2 -> V_31 = 16 ;
V_2 -> V_8 = F_33 ( V_68 , & V_73 ) ;
if ( F_34 ( V_2 -> V_8 ) ) {
V_71 = F_35 ( V_2 -> V_8 ) ;
F_7 ( V_2 -> V_23 , L_18 , V_71 ) ;
goto exit;
}
V_71 = F_27 ( V_2 ) ;
if ( V_71 )
goto V_74;
V_46 -> V_75 = & V_76 ;
V_46 -> V_77 = V_78 ;
V_46 -> V_79 = F_2 ( V_78 ) ;
V_46 -> V_80 = V_70 -> V_80 ;
V_46 -> V_23 . V_81 = & V_68 -> V_23 ;
V_46 -> V_82 = V_83 ;
V_71 = F_36 ( V_46 ) ;
if ( V_71 ) {
F_7 ( & V_68 -> V_23 , L_19 ) ;
goto V_74;
}
return 0 ;
V_74:
F_37 ( V_46 ) ;
exit:
return V_71 ;
}
static int T_4 F_38 ( struct V_67 * V_68 )
{
struct V_45 * V_46 = F_39 ( V_68 ) ;
F_40 ( & V_68 -> V_23 , L_20 , V_84 ) ;
F_41 ( V_46 ) ;
F_37 ( V_46 ) ;
return 0 ;
}
