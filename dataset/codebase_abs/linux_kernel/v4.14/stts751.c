static int F_1 ( T_1 V_1 )
{
return V_1 * 125 / 32 ;
}
static T_2 F_2 ( int V_2 )
{
return F_3 ( V_2 , 125 ) * 32 ;
}
static int F_4 ( struct V_3 * V_4 )
{
T_3 V_5 ;
switch ( V_4 -> V_6 ) {
case 9 :
V_5 = 0 ;
break;
case 8 :
V_5 = 1 ;
break;
default:
V_5 = 3 ;
break;
}
if ( V_4 -> V_5 == V_5 )
return 0 ;
V_4 -> V_7 &= ~ V_8 ;
V_4 -> V_7 |= V_5 << V_9 ;
F_5 ( & V_4 -> V_10 -> V_11 , L_1 ,
V_5 , V_4 -> V_7 ) ;
V_4 -> V_5 = V_5 ;
return F_6 ( V_4 -> V_10 ,
V_12 , V_4 -> V_7 ) ;
}
static int F_7 ( struct V_3 * V_4 )
{
T_2 V_13 , V_14 , V_15 ;
V_13 = F_8 ( V_4 -> V_10 , V_16 ) ;
if ( V_13 < 0 ) {
F_5 ( & V_4 -> V_10 -> V_11 ,
L_2 , V_13 ) ;
return V_13 ;
}
V_15 = F_8 ( V_4 -> V_10 , V_17 ) ;
if ( V_15 < 0 ) {
F_5 ( & V_4 -> V_10 -> V_11 ,
L_3 , V_15 ) ;
return V_15 ;
}
V_14 = F_8 ( V_4 -> V_10 , V_16 ) ;
if ( V_14 < 0 ) {
F_5 ( & V_4 -> V_10 -> V_11 ,
L_4 , V_14 ) ;
return V_14 ;
}
if ( V_13 != V_14 ) {
V_15 = F_8 ( V_4 -> V_10 ,
V_17 ) ;
if ( V_15 < 0 ) {
F_5 ( & V_4 -> V_10 -> V_11 ,
L_5 ,
V_15 ) ;
return V_15 ;
}
}
V_4 -> V_18 = F_1 ( ( V_13 << 8 ) | V_15 ) ;
return 0 ;
}
static int F_9 ( struct V_3 * V_4 , int V_18 ,
T_3 V_19 , T_3 V_20 )
{
T_2 V_21 ;
int V_22 ;
V_21 = F_2 ( V_18 ) ;
V_22 = F_6 ( V_4 -> V_10 , V_19 , V_21 >> 8 ) ;
if ( V_22 )
return V_22 ;
return F_6 ( V_4 -> V_10 , V_20 , V_21 & 0xff ) ;
}
static int F_10 ( struct V_3 * V_4 , int V_18 , T_3 V_23 )
{
T_2 V_21 ;
V_21 = F_2 ( V_18 ) ;
return F_6 ( V_4 -> V_10 , V_23 , V_21 >> 8 ) ;
}
static int F_11 ( struct V_3 * V_4 , int * V_18 ,
T_3 V_19 , T_3 V_20 )
{
int integer , V_15 ;
integer = F_8 ( V_4 -> V_10 , V_19 ) ;
if ( integer < 0 )
return integer ;
V_15 = F_8 ( V_4 -> V_10 , V_20 ) ;
if ( V_15 < 0 )
return V_15 ;
* V_18 = F_1 ( ( integer << 8 ) | V_15 ) ;
return 0 ;
}
static int F_12 ( struct V_3 * V_4 , int * V_18 , T_3 V_23 )
{
int integer ;
integer = F_8 ( V_4 -> V_10 , V_23 ) ;
if ( integer < 0 )
return integer ;
* V_18 = F_1 ( integer << 8 ) ;
return 0 ;
}
static int F_13 ( struct V_3 * V_4 )
{
int V_22 ;
bool V_24 ;
int V_25 = F_14 ( V_26 [ V_4 -> V_6 ] ) ;
V_25 += V_25 / 10 ;
V_22 = F_8 ( V_4 -> V_10 , V_27 ) ;
if ( V_22 < 0 )
return V_22 ;
F_5 ( & V_4 -> V_10 -> V_11 , L_6 , V_22 ) ;
V_24 = V_22 & ( V_28 | V_29 ) ;
if ( F_15 ( V_30 , V_4 -> V_31 + V_25 ) ||
V_24 || ! V_4 -> V_32 ) {
V_4 -> V_33 = false ;
V_4 -> V_34 = false ;
V_4 -> V_32 = true ;
V_4 -> V_31 = V_30 ;
F_5 ( & V_4 -> V_10 -> V_11 , L_7 ) ;
}
V_4 -> V_33 |= ! ! ( V_22 & V_28 ) ;
V_4 -> V_34 |= ! ! ( V_22 & V_29 ) ;
V_4 -> V_35 = ! ! ( V_22 & V_36 ) ;
F_5 ( & V_4 -> V_10 -> V_11 , L_8 ,
V_4 -> V_33 , V_4 -> V_34 , V_4 -> V_35 ) ;
return 0 ;
}
static void F_16 ( struct V_37 * V_10 ,
enum V_38 type , unsigned int V_39 )
{
int V_22 ;
struct V_3 * V_4 = F_17 ( V_10 ) ;
if ( type != V_40 )
return;
F_5 ( & V_10 -> V_11 , L_9 ) ;
F_18 ( & V_4 -> V_41 ) ;
V_22 = F_13 ( V_4 ) ;
if ( V_22 < 0 ) {
V_4 -> V_33 = true ;
V_4 -> V_34 = true ;
F_19 ( V_4 -> V_11 ,
L_10 ) ;
}
if ( V_4 -> V_33 ) {
if ( V_4 -> V_42 )
F_20 ( V_4 -> V_11 , L_11 ) ;
V_4 -> V_42 = false ;
F_21 ( & V_4 -> V_11 -> V_43 , NULL , L_12 ) ;
}
if ( V_4 -> V_34 ) {
if ( V_4 -> V_44 )
F_20 ( V_4 -> V_11 , L_13 ) ;
V_4 -> V_44 = false ;
F_21 ( & V_4 -> V_11 -> V_43 , NULL , L_14 ) ;
}
if ( V_4 -> V_34 || V_4 -> V_33 )
F_22 ( & V_4 -> V_11 -> V_43 , V_45 ) ;
F_23 ( & V_4 -> V_41 ) ;
}
static int F_24 ( struct V_3 * V_4 )
{
int V_22 ;
int V_25 = F_14 ( V_26 [ V_4 -> V_6 ] ) ;
if ( F_15 ( V_30 , V_4 -> V_46 + V_25 ) ||
! V_4 -> V_47 ) {
V_22 = F_7 ( V_4 ) ;
if ( V_22 )
return V_22 ;
V_22 = F_13 ( V_4 ) ;
if ( V_22 )
return V_22 ;
V_4 -> V_47 = true ;
V_4 -> V_46 = V_30 ;
}
return 0 ;
}
static T_4 F_25 ( struct V_48 * V_11 , struct V_49 * V_50 ,
char * V_51 )
{
int V_22 ;
struct V_3 * V_4 = F_26 ( V_11 ) ;
F_18 ( & V_4 -> V_41 ) ;
V_22 = F_24 ( V_4 ) ;
if ( ! V_22 )
V_4 -> V_42 = true ;
F_23 ( & V_4 -> V_41 ) ;
if ( V_22 < 0 )
return V_22 ;
return snprintf ( V_51 , V_52 - 1 , L_15 , V_4 -> V_33 ) ;
}
static T_4 F_27 ( struct V_48 * V_11 , struct V_49 * V_50 ,
char * V_51 )
{
int V_22 ;
struct V_3 * V_4 = F_26 ( V_11 ) ;
F_18 ( & V_4 -> V_41 ) ;
V_22 = F_24 ( V_4 ) ;
if ( ! V_22 )
V_4 -> V_44 = true ;
F_23 ( & V_4 -> V_41 ) ;
if ( V_22 < 0 )
return V_22 ;
return snprintf ( V_51 , V_52 - 1 , L_15 , V_4 -> V_34 ) ;
}
static T_4 F_28 ( struct V_48 * V_11 , struct V_49 * V_50 ,
char * V_51 )
{
int V_22 ;
struct V_3 * V_4 = F_26 ( V_11 ) ;
F_18 ( & V_4 -> V_41 ) ;
V_22 = F_24 ( V_4 ) ;
F_23 ( & V_4 -> V_41 ) ;
if ( V_22 < 0 )
return V_22 ;
return snprintf ( V_51 , V_52 - 1 , L_15 , V_4 -> V_18 ) ;
}
static T_4 F_29 ( struct V_48 * V_11 , struct V_49 * V_50 ,
char * V_51 )
{
struct V_3 * V_4 = F_26 ( V_11 ) ;
return snprintf ( V_51 , V_52 - 1 , L_15 , V_4 -> V_53 ) ;
}
static T_4 F_30 ( struct V_48 * V_11 , struct V_49 * V_50 ,
const char * V_51 , T_5 V_54 )
{
int V_22 ;
long V_18 ;
struct V_3 * V_4 = F_26 ( V_11 ) ;
if ( F_31 ( V_51 , 10 , & V_18 ) < 0 )
return - V_55 ;
V_18 = F_32 ( V_18 , - 64000 , 127937 ) ;
F_18 ( & V_4 -> V_41 ) ;
V_22 = F_10 ( V_4 , V_18 , V_56 ) ;
if ( V_22 )
goto exit;
F_5 ( & V_4 -> V_10 -> V_11 , L_16 , V_18 ) ;
V_4 -> V_57 = V_18 - ( V_4 -> V_53 - V_4 -> V_57 ) ;
V_4 -> V_53 = V_18 ;
exit:
F_23 ( & V_4 -> V_41 ) ;
if ( V_22 )
return V_22 ;
return V_54 ;
}
static T_4 F_33 ( struct V_48 * V_11 , struct V_49 * V_50 ,
char * V_51 )
{
struct V_3 * V_4 = F_26 ( V_11 ) ;
return snprintf ( V_51 , V_52 - 1 , L_15 , V_4 -> V_57 ) ;
}
static T_4 F_34 ( struct V_48 * V_11 , struct V_49 * V_50 ,
const char * V_51 , T_5 V_54 )
{
int V_22 ;
long V_18 ;
struct V_3 * V_4 = F_26 ( V_11 ) ;
if ( F_31 ( V_51 , 10 , & V_18 ) < 0 )
return - V_55 ;
F_18 ( & V_4 -> V_41 ) ;
V_18 = F_32 ( V_18 , - 64000 , V_4 -> V_53 ) ;
V_4 -> V_57 = V_18 ;
F_5 ( & V_4 -> V_10 -> V_11 , L_17 , V_18 ) ;
V_18 = V_4 -> V_53 - V_18 ;
V_22 = F_10 ( V_4 , V_18 , V_58 ) ;
F_23 ( & V_4 -> V_41 ) ;
if ( V_22 )
return V_22 ;
return V_54 ;
}
static T_4 F_35 ( struct V_48 * V_11 ,
struct V_49 * V_50 , char * V_51 )
{
int V_22 ;
struct V_3 * V_4 = F_26 ( V_11 ) ;
F_18 ( & V_4 -> V_41 ) ;
V_22 = F_24 ( V_4 ) ;
F_23 ( & V_4 -> V_41 ) ;
if ( V_22 < 0 )
return V_22 ;
return snprintf ( V_51 , V_52 - 1 , L_15 , V_4 -> V_35 ) ;
}
static T_4 F_36 ( struct V_48 * V_11 , struct V_49 * V_50 ,
char * V_51 )
{
struct V_3 * V_4 = F_26 ( V_11 ) ;
return snprintf ( V_51 , V_52 - 1 , L_15 , V_4 -> V_59 ) ;
}
static T_4 F_37 ( struct V_48 * V_11 , struct V_49 * V_50 ,
const char * V_51 , T_5 V_54 )
{
int V_22 ;
long V_18 ;
struct V_3 * V_4 = F_26 ( V_11 ) ;
if ( F_31 ( V_51 , 10 , & V_18 ) < 0 )
return - V_55 ;
F_18 ( & V_4 -> V_41 ) ;
V_18 = F_32 ( V_18 , V_4 -> V_60 , 127937 ) ;
V_22 = F_9 ( V_4 , V_18 ,
V_61 , V_62 ) ;
if ( V_22 )
goto exit;
F_5 ( & V_4 -> V_10 -> V_11 , L_18 , V_18 ) ;
V_4 -> V_59 = V_18 ;
V_22 = V_54 ;
exit:
F_23 ( & V_4 -> V_41 ) ;
return V_22 ;
}
static T_4 F_38 ( struct V_48 * V_11 , struct V_49 * V_50 ,
char * V_51 )
{
struct V_3 * V_4 = F_26 ( V_11 ) ;
return snprintf ( V_51 , V_52 - 1 , L_15 , V_4 -> V_60 ) ;
}
static T_4 F_39 ( struct V_48 * V_11 , struct V_49 * V_50 ,
const char * V_51 , T_5 V_54 )
{
int V_22 ;
long V_18 ;
struct V_3 * V_4 = F_26 ( V_11 ) ;
if ( F_31 ( V_51 , 10 , & V_18 ) < 0 )
return - V_55 ;
F_18 ( & V_4 -> V_41 ) ;
V_18 = F_32 ( V_18 , - 64000 , V_4 -> V_59 ) ;
V_22 = F_9 ( V_4 , V_18 ,
V_63 , V_64 ) ;
if ( V_22 )
goto exit;
F_5 ( & V_4 -> V_10 -> V_11 , L_19 , V_18 ) ;
V_4 -> V_60 = V_18 ;
V_22 = V_54 ;
exit:
F_23 ( & V_4 -> V_41 ) ;
return V_22 ;
}
static T_4 F_40 ( struct V_48 * V_11 , struct V_49 * V_50 ,
char * V_51 )
{
struct V_3 * V_4 = F_26 ( V_11 ) ;
return snprintf ( V_51 , V_52 - 1 , L_15 ,
V_26 [ V_4 -> V_6 ] ) ;
}
static T_4 F_41 ( struct V_48 * V_11 , struct V_49 * V_50 ,
const char * V_51 , T_5 V_54 )
{
unsigned long V_2 ;
int V_65 ;
int V_22 = V_54 ;
struct V_3 * V_4 = F_26 ( V_11 ) ;
if ( F_42 ( V_51 , 10 , & V_2 ) < 0 )
return - V_55 ;
V_65 = F_43 ( V_2 , V_26 ,
F_44 ( V_26 ) ) ;
F_5 ( & V_4 -> V_10 -> V_11 , L_20 ,
V_2 , V_65 , V_26 [ V_65 ] ) ;
F_18 ( & V_4 -> V_41 ) ;
if ( V_4 -> V_6 == V_65 )
goto exit;
if ( V_4 -> V_6 < V_65 ) {
F_5 ( & V_4 -> V_10 -> V_11 , L_21 ) ;
V_4 -> V_6 = V_65 ;
V_22 = F_4 ( V_4 ) ;
if ( V_22 )
goto exit;
}
V_22 = F_6 ( V_4 -> V_10 , V_66 , V_65 ) ;
if ( V_22 )
goto exit;
if ( V_4 -> V_6 != V_65 ) {
F_5 ( & V_4 -> V_10 -> V_11 , L_22 ) ;
V_4 -> V_6 = V_65 ;
V_22 = F_4 ( V_4 ) ;
if ( V_22 )
goto exit;
}
V_22 = V_54 ;
exit:
F_23 ( & V_4 -> V_41 ) ;
return V_22 ;
}
static int F_45 ( struct V_37 * V_67 ,
struct V_68 * V_69 )
{
struct V_70 * V_71 = V_67 -> V_71 ;
const char * V_72 ;
int V_73 ;
if ( ! F_46 ( V_71 , V_74 ) )
return - V_75 ;
V_73 = F_8 ( V_67 , V_76 ) ;
if ( V_73 != V_77 )
return - V_75 ;
V_73 = F_8 ( V_67 , V_17 ) ;
if ( V_73 & 0xf )
return - V_75 ;
V_73 = F_8 ( V_67 , V_62 ) ;
if ( V_73 & 0xf )
return - V_75 ;
V_73 = F_8 ( V_67 , V_64 ) ;
if ( V_73 & 0xf )
return - V_75 ;
V_73 = F_8 ( V_67 , V_78 ) ;
if ( V_73 & 0x7f )
return - V_75 ;
V_73 = F_8 ( V_67 , V_79 ) ;
switch ( V_73 ) {
case V_80 :
V_72 = L_23 ;
break;
case V_81 :
V_72 = L_24 ;
break;
default:
return - V_75 ;
}
F_5 ( & V_67 -> V_11 , L_25 , V_72 ) ;
F_47 ( V_69 -> type , V_82 [ 0 ] . V_72 , V_83 ) ;
return 0 ;
}
static int F_48 ( struct V_3 * V_4 )
{
int V_22 ;
int V_73 ;
V_22 = F_8 ( V_4 -> V_10 , V_12 ) ;
if ( V_22 < 0 )
return V_22 ;
V_4 -> V_7 = V_22 ;
V_4 -> V_5 = ( V_22 & V_8 ) >> V_9 ;
V_22 = F_8 ( V_4 -> V_10 , V_66 ) ;
if ( V_22 < 0 )
return V_22 ;
if ( V_22 >= F_44 ( V_26 ) ) {
F_49 ( V_4 -> V_11 , L_26 , V_22 ) ;
return - V_75 ;
}
V_4 -> V_6 = V_22 ;
V_22 = F_11 ( V_4 , & V_4 -> V_59 ,
V_61 , V_62 ) ;
if ( V_22 )
return V_22 ;
V_22 = F_11 ( V_4 , & V_4 -> V_60 ,
V_63 , V_64 ) ;
if ( V_22 )
return V_22 ;
V_22 = F_12 ( V_4 , & V_4 -> V_53 , V_56 ) ;
if ( V_22 )
return V_22 ;
V_22 = F_12 ( V_4 , & V_73 , V_58 ) ;
if ( V_22 )
return V_22 ;
V_4 -> V_57 = V_4 -> V_53 - V_73 ;
return 0 ;
}
static int F_50 ( struct V_37 * V_10 ,
const struct V_84 * V_85 )
{
struct V_3 * V_4 ;
int V_22 ;
bool V_86 ;
int V_87 ;
V_4 = F_51 ( & V_10 -> V_11 , sizeof( * V_4 ) , V_88 ) ;
if ( ! V_4 )
return - V_89 ;
V_4 -> V_10 = V_10 ;
V_4 -> V_42 = true ;
V_4 -> V_44 = true ;
F_52 ( V_10 , V_4 ) ;
F_53 ( & V_4 -> V_41 ) ;
if ( F_54 ( & V_10 -> V_11 ,
L_27 ) ) {
V_86 = F_55 ( & V_10 -> V_11 ,
L_27 ) ;
V_22 = F_6 ( V_10 , V_78 ,
V_86 ? 0 : 0x80 ) ;
if ( V_22 )
return V_22 ;
}
V_87 = F_8 ( V_10 , V_90 ) ;
if ( V_87 < 0 )
return - V_75 ;
if ( V_87 != 0x1 ) {
F_5 ( & V_10 -> V_11 , L_28 ,
V_87 ) ;
}
V_22 = F_48 ( V_4 ) ;
if ( V_22 )
return V_22 ;
V_4 -> V_7 &= ~ ( V_91 | V_92 ) ;
V_22 = F_6 ( V_10 , V_12 , V_4 -> V_7 ) ;
if ( V_22 )
return V_22 ;
V_4 -> V_11 = F_56 ( & V_10 -> V_11 ,
V_10 -> V_72 , V_4 ,
V_93 ) ;
return F_57 ( V_4 -> V_11 ) ;
}
