static int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_4 , T_1 V_5 , T_1 V_6 )
{
T_1 V_7 ;
int V_8 = 0 ;
struct V_9 * V_10 = F_2 ( V_2 ) ;
V_7 = V_10 -> V_11 [ V_3 ] ;
V_7 &= ~ V_5 ;
V_7 |= V_4 << V_6 ;
V_8 = F_3 ( V_2 , V_3 , V_7 ) ;
if ( V_8 ) {
F_4 ( & V_2 -> V_12 , L_1 , V_8 ) ;
return V_8 ;
}
V_10 -> V_11 [ V_3 ] = V_7 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , unsigned long V_13 ,
unsigned int * V_14 )
{
static const unsigned long V_15 [] = { 1000 , 4000 , 16000 , 64000 } ;
int V_16 ;
for ( V_16 = 0 ; V_16 < F_6 ( V_15 ) ; ++ V_16 ) {
if ( V_13 <= V_15 [ V_16 ] ) {
* V_14 = ( unsigned int ) V_15 [ V_16 ] ;
break;
}
}
if ( V_16 >= F_6 ( V_15 ) )
return - V_17 ;
return F_1 ( V_2 , V_18 ,
V_16 , V_19 , V_20 ) ;
}
static int F_7 ( struct V_1 * V_2 ,
unsigned long V_21 , unsigned int * V_22 )
{
static const unsigned long V_23 [] = { 16 , 12 , 8 , 4 } ;
int V_16 ;
for ( V_16 = 0 ; V_16 < F_6 ( V_23 ) ; ++ V_16 ) {
if ( V_21 >= V_23 [ V_16 ] ) {
* V_22 = ( unsigned int ) V_23 [ V_16 ] ;
break;
}
}
if ( V_16 >= F_6 ( V_23 ) )
return - V_17 ;
return F_1 ( V_2 , V_18 ,
V_16 , V_24 ,
V_25 ) ;
}
static int F_8 ( struct V_1 * V_2 , int V_26 )
{
int V_27 ;
int V_28 ;
int V_29 ;
V_27 = F_1 ( V_2 , V_30 ,
V_26 , V_31 , V_32 ) ;
if ( V_27 ) {
F_4 ( & V_2 -> V_12 , L_2 ) ;
return V_27 ;
}
F_9 ( V_33 ) ;
V_28 = F_10 ( V_2 , V_34 ) ;
if ( V_28 < 0 ) {
F_4 ( & V_2 -> V_12 , L_3 ) ;
return V_28 ;
}
V_29 = F_10 ( V_2 , V_35 ) ;
if ( V_29 < 0 ) {
F_4 ( & V_2 -> V_12 , L_4 ) ;
return V_29 ;
}
F_11 ( & V_2 -> V_12 , L_5 , V_29 , V_28 ) ;
return ( V_29 << 8 ) | V_28 ;
}
static int F_12 ( struct V_1 * V_2 , int * V_36 )
{
int V_37 ;
struct V_9 * V_10 = F_2 ( V_2 ) ;
V_37 = F_8 ( V_2 ,
V_38 ) ;
if ( V_37 < 0 )
return V_37 ;
* V_36 = ( V_37 * V_10 -> V_13 ) >> V_10 -> V_39 ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 , int * V_40 )
{
int V_41 ;
V_41 = F_8 ( V_2 , V_42 ) ;
if ( V_41 < 0 )
return V_41 ;
* V_40 = V_41 ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 , int V_43 ,
int * V_44 )
{
int V_27 ;
int V_45 = - 1 ;
int V_41 = - 1 ;
V_27 = F_1 ( V_2 , V_18 ,
V_43 , V_46 , V_47 ) ;
if ( V_27 ) {
F_4 ( & V_2 -> V_12 , L_2 ) ;
return V_27 ;
}
V_45 = F_8 ( V_2 ,
V_48 ) ;
if ( V_45 < 0 )
return V_45 ;
if ( V_43 == 1 ) {
* V_44 = V_45 ;
return 0 ;
}
V_41 = F_8 ( V_2 ,
V_42 ) ;
if ( V_41 < 0 )
return V_41 ;
if ( V_45 >= V_41 )
* V_44 = V_45 - V_41 ;
else
* V_44 = 0 ;
return 0 ;
}
static T_2 F_15 ( struct V_49 * V_12 , char * V_50 , int V_26 )
{
struct V_51 * V_52 = F_16 ( V_12 ) ;
struct V_9 * V_10 = V_52 -> V_53 ;
struct V_1 * V_2 = V_10 -> V_2 ;
int V_54 = 0 ;
int V_27 ;
F_17 ( & V_10 -> V_55 ) ;
switch ( V_26 ) {
case V_48 :
V_27 = F_14 ( V_2 ,
V_10 -> V_56 , & V_54 ) ;
break;
case V_38 :
V_27 = F_12 ( V_2 , & V_54 ) ;
break;
case V_42 :
V_27 = F_13 ( V_2 , & V_54 ) ;
break;
default:
F_4 ( & V_2 -> V_12 , L_6 , V_26 ) ;
F_18 ( & V_10 -> V_55 ) ;
return - V_57 ;
}
if ( V_27 < 0 ) {
F_4 ( & V_2 -> V_12 , L_7 ) ;
F_18 ( & V_10 -> V_55 ) ;
return V_27 ;
}
F_18 ( & V_10 -> V_55 ) ;
return sprintf ( V_50 , L_8 , V_54 ) ;
}
static T_2 F_19 ( struct V_49 * V_12 ,
struct V_58 * V_59 , char * V_50 )
{
struct V_51 * V_52 = F_16 ( V_12 ) ;
struct V_9 * V_10 = V_52 -> V_53 ;
return sprintf ( V_50 , L_9 , V_10 -> V_13 ) ;
}
static T_2 F_20 ( struct V_49 * V_12 ,
struct V_58 * V_59 , const char * V_50 , T_3 V_60 )
{
struct V_51 * V_52 = F_16 ( V_12 ) ;
struct V_9 * V_10 = V_52 -> V_53 ;
struct V_1 * V_2 = V_10 -> V_2 ;
int V_27 ;
unsigned long V_61 ;
unsigned int V_14 ;
if ( F_21 ( V_50 , 10 , & V_61 ) )
return - V_17 ;
if ( ! ( V_61 == 1000UL || V_61 == 4000UL ||
V_61 == 16000UL || V_61 == 64000UL ) ) {
F_4 ( V_12 , L_10 ) ;
return - V_17 ;
}
F_17 ( & V_10 -> V_55 ) ;
V_27 = F_5 ( V_2 , V_61 , & V_14 ) ;
if ( V_27 < 0 ) {
F_18 ( & V_10 -> V_55 ) ;
F_4 ( V_12 , L_11 ) ;
return V_27 ;
}
V_10 -> V_13 = V_14 ;
F_18 ( & V_10 -> V_55 ) ;
return V_60 ;
}
static T_2 F_22 ( struct V_49 * V_12 ,
struct V_58 * V_59 , char * V_50 )
{
struct V_51 * V_52 = F_16 ( V_12 ) ;
struct V_9 * V_10 = V_52 -> V_53 ;
return sprintf ( V_50 , L_9 , V_10 -> V_39 ) ;
}
static T_2 F_23 ( struct V_49 * V_12 ,
struct V_58 * V_59 , const char * V_50 , T_3 V_60 )
{
struct V_51 * V_52 = F_16 ( V_12 ) ;
struct V_9 * V_10 = V_52 -> V_53 ;
struct V_1 * V_2 = V_10 -> V_2 ;
int V_27 ;
unsigned long V_61 ;
unsigned int V_62 ;
if ( F_21 ( V_50 , 10 , & V_61 ) )
return - V_17 ;
if ( ! ( V_61 == 4 || V_61 == 8 || V_61 == 12 || V_61 == 16 ) ) {
F_4 ( V_12 , L_12 ) ;
return - V_17 ;
}
F_17 ( & V_10 -> V_55 ) ;
V_27 = F_7 ( V_2 , V_61 , & V_62 ) ;
if ( V_27 < 0 ) {
F_18 ( & V_10 -> V_55 ) ;
F_4 ( V_12 , L_13 ) ;
return V_27 ;
}
V_10 -> V_39 = V_62 ;
F_18 ( & V_10 -> V_55 ) ;
return V_60 ;
}
static T_2 F_24 ( struct V_49 * V_12 ,
struct V_58 * V_59 , char * V_50 )
{
struct V_51 * V_52 = F_16 ( V_12 ) ;
struct V_9 * V_10 = V_52 -> V_53 ;
return sprintf ( V_50 , L_8 , V_10 -> V_56 ) ;
}
static T_2 F_25 ( struct V_49 * V_12 ,
struct V_58 * V_59 , const char * V_50 , T_3 V_60 )
{
struct V_51 * V_52 = F_16 ( V_12 ) ;
struct V_9 * V_10 = V_52 -> V_53 ;
unsigned long V_61 ;
if ( F_21 ( V_50 , 10 , & V_61 ) )
return - V_17 ;
if ( ! ( V_61 == 0UL || V_61 == 1UL ) ) {
F_4 ( V_12 , L_14 ) ;
return - V_17 ;
}
F_17 ( & V_10 -> V_55 ) ;
V_10 -> V_56 = ( int ) V_61 ;
F_18 ( & V_10 -> V_55 ) ;
return V_60 ;
}
static T_2 F_26 ( struct V_49 * V_12 ,
struct V_58 * V_63 , char * V_50 )
{
return F_15 ( V_12 , V_50 , V_38 ) ;
}
static T_2 F_27 ( struct V_49 * V_12 ,
struct V_58 * V_63 , char * V_50 )
{
return F_15 ( V_12 , V_50 , V_42 ) ;
}
static T_2 F_28 ( struct V_49 * V_12 ,
struct V_58 * V_63 , char * V_50 )
{
return F_15 ( V_12 , V_50 , V_48 ) ;
}
static int F_29 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
int V_27 ;
int V_62 ;
unsigned int V_14 ;
memset ( V_10 -> V_11 , 0 , sizeof( V_10 -> V_11 ) ) ;
V_27 = F_5 ( V_2 , V_10 -> V_13 , & V_14 ) ;
if ( V_27 < 0 ) {
F_4 ( & V_2 -> V_12 , L_15 ) ;
return V_27 ;
}
V_27 = F_7 ( V_2 , V_10 -> V_39 ,
& V_62 ) ;
return 0 ;
}
static int T_4 F_30 ( struct V_1 * V_2 ,
const struct V_64 * V_65 )
{
struct V_9 * V_10 ;
int V_66 ;
V_10 = F_31 ( sizeof( struct V_9 ) , V_67 ) ;
if ( ! V_10 ) {
F_4 ( & V_2 -> V_12 , L_16 ) ;
V_66 = - V_68 ;
goto exit;
}
F_32 ( V_2 , V_10 ) ;
V_10 -> V_2 = V_2 ;
F_33 ( & V_10 -> V_55 ) ;
V_10 -> V_13 = 1000 ;
V_10 -> V_39 = 16 ;
V_66 = F_29 ( V_2 ) ;
if ( V_66 )
goto V_69;
V_10 -> V_52 = F_34 ( 0 ) ;
if ( ! V_10 -> V_52 ) {
F_4 ( & V_2 -> V_12 , L_17 ) ;
goto V_69;
}
V_10 -> V_52 -> V_70 = & V_71 ;
V_10 -> V_52 -> V_72 = V_65 -> V_72 ;
V_10 -> V_52 -> V_12 . V_73 = & V_2 -> V_12 ;
V_10 -> V_52 -> V_53 = ( void * ) ( V_10 ) ;
V_10 -> V_52 -> V_74 = V_75 ;
V_66 = F_35 ( V_10 -> V_52 ) ;
if ( V_66 ) {
F_4 ( & V_2 -> V_12 , L_18 ) ;
goto V_76;
}
return 0 ;
V_76:
F_36 ( V_10 -> V_52 ) ;
V_69:
F_37 ( V_10 ) ;
exit:
return V_66 ;
}
static int T_5 F_38 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
F_39 ( & V_2 -> V_12 , L_19 , V_77 ) ;
F_40 ( V_10 -> V_52 ) ;
F_37 ( V_10 ) ;
return 0 ;
}
static int T_6 F_41 ( void )
{
return F_42 ( & V_78 ) ;
}
static void T_7 F_43 ( void )
{
F_44 ( & V_78 ) ;
}
