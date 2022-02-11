static int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
int V_4 , V_5 ;
unsigned int V_6 , V_7 ;
for ( V_4 = 0 ; V_4 < F_2 ( V_8 [ V_2 -> type ] ) ; ++ V_4 ) {
if ( V_3 == V_8 [ V_2 -> type ] [ V_4 ] ) {
V_7 = V_4 ;
break;
}
}
if ( V_4 >= F_2 ( V_8 [ V_2 -> type ] ) )
return - V_9 ;
V_5 = F_3 ( V_2 -> V_10 , V_11 ,
V_12 ,
V_4 << V_13 ) ;
if ( V_5 < 0 )
return V_5 ;
V_6 = V_2 -> V_6 ;
for ( V_4 = 0 ; V_4 < F_2 ( V_14 [ V_6 ] ) ; ++ V_4 ) {
if ( V_2 -> V_15 . V_15 == V_14 [ V_6 ] [ V_4 ] . V_15 &&
V_2 -> V_15 . V_16 == V_14 [ V_6 ] [ V_4 ] . V_16 ) {
V_2 -> V_15 = V_14 [ V_7 ] [ V_4 ] ;
break;
}
}
V_2 -> V_6 = V_7 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , int V_15 , int V_16 )
{
int V_4 , V_5 ;
struct V_17 V_18 ;
for ( V_4 = 0 ; V_4 < F_2 ( V_14 [ V_2 -> V_6 ] ) ; ++ V_4 ) {
if ( V_15 == V_14 [ V_2 -> V_6 ] [ V_4 ] . V_15 &&
V_16 == V_14 [ V_2 -> V_6 ] [ V_4 ] . V_16 ) {
V_18 = V_14 [ V_2 -> V_6 ] [ V_4 ] ;
break;
}
}
if ( V_4 >= F_2 ( V_14 [ V_2 -> V_6 ] ) )
return - V_9 ;
V_5 = F_3 ( V_2 -> V_10 , V_11 ,
V_19 ,
V_4 << V_20 ) ;
if ( V_5 < 0 )
return V_5 ;
V_2 -> V_15 = V_18 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , int V_21 )
{
int V_22 ;
unsigned int V_23 ;
unsigned int V_24 ;
struct V_25 * V_26 = F_6 ( V_2 -> V_10 ) ;
V_22 = F_7 ( V_2 -> V_10 , V_27 ,
V_21 << V_28 ) ;
if ( V_22 ) {
F_8 ( V_26 ,
L_1 , V_22 ) ;
return V_22 ;
}
F_9 ( V_29 ) ;
V_22 = F_10 ( V_2 -> V_10 , V_30 , & V_23 ) ;
if ( V_22 < 0 ) {
F_8 ( V_26 ,
L_2 , V_22 ) ;
return V_22 ;
}
V_22 = F_10 ( V_2 -> V_10 , V_31 , & V_24 ) ;
if ( V_22 < 0 ) {
F_8 ( V_26 ,
L_3 , V_22 ) ;
return V_22 ;
}
F_11 ( V_26 , L_4 , V_24 , V_23 ) ;
return ( V_24 << 8 ) | V_23 ;
}
static int F_12 ( struct V_1 * V_2 , int * V_32 )
{
int V_33 ;
unsigned int V_34 ;
V_33 = F_5 ( V_2 , V_35 ) ;
if ( V_33 < 0 )
return V_33 ;
V_34 = V_33 * V_2 -> V_15 . V_15 +
V_33 * V_2 -> V_15 . V_16 / 1000000 ;
* V_32 = V_34 * V_2 -> V_36 +
V_34 * V_2 -> V_37 / 1000000 ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 , int * V_38 )
{
int V_39 ;
V_39 = F_5 ( V_2 , V_40 ) ;
if ( V_39 < 0 )
return V_39 ;
* V_38 = V_39 ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 , int V_41 ,
int * V_42 )
{
int V_22 ;
int V_43 = - 1 ;
int V_39 = - 1 ;
struct V_25 * V_26 = F_6 ( V_2 -> V_10 ) ;
V_22 = F_3 ( V_2 -> V_10 , V_11 ,
V_44 ,
V_41 << V_45 ) ;
if ( V_22 ) {
F_8 ( V_26 , L_5 ) ;
return V_22 ;
}
V_43 = F_5 ( V_2 ,
V_46 ) ;
if ( V_43 < 0 )
return V_43 ;
if ( V_41 == 1 ) {
* V_42 = V_43 ;
return 0 ;
}
V_39 = F_5 ( V_2 , V_40 ) ;
if ( V_39 < 0 )
return V_39 ;
if ( V_43 >= V_39 )
* V_42 = V_43 - V_39 ;
else
* V_42 = 0 ;
return 0 ;
}
static T_1 F_15 ( struct V_25 * V_26 ,
struct V_47 * V_48 , char * V_49 )
{
struct V_50 * V_51 = F_16 ( V_26 ) ;
struct V_1 * V_2 = F_17 ( V_51 ) ;
int V_4 , V_52 = 0 ;
for ( V_4 = 0 ; V_4 < F_2 ( V_14 [ V_2 -> V_6 ] ) ; ++ V_4 )
V_52 += sprintf ( V_49 + V_52 , L_6 ,
V_14 [ V_2 -> V_6 ] [ V_4 ] . V_15 ,
V_14 [ V_2 -> V_6 ] [ V_4 ] . V_16 ) ;
V_49 [ V_52 - 1 ] = '\n' ;
return V_52 ;
}
static T_1 F_18 ( struct V_25 * V_26 ,
struct V_47 * V_48 , char * V_49 )
{
struct V_50 * V_51 = F_16 ( V_26 ) ;
struct V_1 * V_2 = F_17 ( V_51 ) ;
int V_4 , V_52 = 0 ;
for ( V_4 = 0 ; V_4 < F_2 ( V_8 [ V_2 -> type ] ) ; ++ V_4 )
V_52 += sprintf ( V_49 + V_52 , L_7 ,
V_8 [ V_2 -> type ] [ V_4 ] ) ;
V_49 [ V_52 - 1 ] = '\n' ;
return V_52 ;
}
static T_1 F_19 ( struct V_25 * V_26 ,
struct V_47 * V_48 ,
char * V_49 )
{
struct V_50 * V_51 = F_16 ( V_26 ) ;
struct V_1 * V_2 = F_17 ( V_51 ) ;
return sprintf ( V_49 , L_8 , V_2 -> V_53 ) ;
}
static T_1 F_20 ( struct V_25 * V_26 ,
struct V_47 * V_48 ,
const char * V_49 , T_2 V_54 )
{
struct V_50 * V_51 = F_16 ( V_26 ) ;
struct V_1 * V_2 = F_17 ( V_51 ) ;
int V_55 ;
if ( F_21 ( V_49 , 10 , & V_55 ) )
return - V_9 ;
if ( ! ( V_55 == 0 || V_55 == 1 ) ) {
F_8 ( V_26 , L_9 ) ;
return - V_9 ;
}
F_22 ( & V_2 -> V_56 ) ;
V_2 -> V_53 = V_55 ;
F_23 ( & V_2 -> V_56 ) ;
return V_54 ;
}
static int F_24 ( struct V_50 * V_51 ,
struct V_57 const * V_58 ,
int V_55 ,
int V_59 ,
long V_60 )
{
struct V_1 * V_2 = F_17 ( V_51 ) ;
int V_5 = - V_9 ;
F_22 ( & V_2 -> V_56 ) ;
switch ( V_60 ) {
case V_61 :
if ( V_58 -> type == V_62 ) {
V_2 -> V_36 = V_55 ;
V_2 -> V_37 = V_59 ;
V_5 = 0 ;
}
break;
case V_63 :
if ( V_58 -> type == V_62 ) {
if ( V_55 ) {
F_23 ( & V_2 -> V_56 ) ;
return - V_9 ;
}
V_5 = F_1 ( V_2 , V_59 ) ;
}
break;
case V_64 :
if ( V_58 -> type == V_62 )
V_5 = F_4 ( V_2 , V_55 , V_59 ) ;
break;
default:
break;
}
F_23 ( & V_2 -> V_56 ) ;
return V_5 ;
}
static int F_25 ( struct V_50 * V_51 ,
struct V_57 const * V_58 ,
int * V_55 ,
int * V_59 ,
long V_60 )
{
int V_5 = - V_9 ;
struct V_1 * V_2 = F_17 ( V_51 ) ;
F_22 ( & V_2 -> V_56 ) ;
if ( V_2 -> V_65 ) {
F_23 ( & V_2 -> V_56 ) ;
return - V_66 ;
}
switch ( V_60 ) {
case V_67 :
case V_68 :
switch ( V_58 -> type ) {
case V_62 :
V_5 = F_12 ( V_2 , V_55 ) ;
break;
case V_69 :
V_5 = F_13 ( V_2 , V_55 ) ;
break;
case V_70 :
V_5 = F_14 ( V_2 ,
V_2 -> V_53 ,
V_55 ) ;
break;
default:
break;
}
if ( ! V_5 )
V_5 = V_71 ;
break;
case V_63 :
if ( V_58 -> type == V_62 ) {
* V_55 = 0 ;
* V_59 = V_8 [ V_2 -> type ] [ V_2 -> V_6 ] ;
V_5 = V_72 ;
}
break;
case V_64 :
if ( V_58 -> type == V_62 ) {
* V_55 = V_2 -> V_15 . V_15 ;
* V_59 = V_2 -> V_15 . V_16 ;
V_5 = V_72 ;
}
break;
case V_61 :
if ( V_58 -> type == V_62 ) {
* V_55 = V_2 -> V_36 ;
* V_59 = V_2 -> V_37 ;
V_5 = V_72 ;
}
break;
default:
break;
}
F_23 ( & V_2 -> V_56 ) ;
return V_5 ;
}
static int F_26 ( struct V_1 * V_2 )
{
int V_22 ;
unsigned int V_73 ;
struct V_25 * V_26 = F_6 ( V_2 -> V_10 ) ;
V_22 = F_10 ( V_2 -> V_10 , V_74 , & V_73 ) ;
if ( V_22 < 0 ) {
F_8 ( V_26 ,
L_10 ,
V_22 ) ;
return V_22 ;
}
V_73 = ( V_73 & V_75 ) >> V_76 ;
if ( V_73 != V_77 )
return - V_78 ;
return F_3 ( V_2 -> V_10 , V_74 ,
V_79 , 0 ) ;
}
static int F_27 ( struct V_1 * V_2 )
{
int V_22 ;
struct V_25 * V_26 = F_6 ( V_2 -> V_10 ) ;
if ( V_2 -> type == V_80 ) {
V_22 = F_26 ( V_2 ) ;
if ( V_22 < 0 )
return V_22 ;
}
V_22 = F_7 ( V_2 -> V_10 , V_81 , 0x0 ) ;
if ( V_22 < 0 ) {
F_8 ( V_26 , L_11 ,
V_22 ) ;
return V_22 ;
}
V_22 = F_7 ( V_2 -> V_10 , V_27 , 0 ) ;
if ( V_22 < 0 ) {
F_8 ( V_26 , L_12 ,
V_22 ) ;
return V_22 ;
}
F_28 ( 1000 , 2000 ) ;
V_22 = F_4 ( V_2 , V_2 -> V_15 . V_15 ,
V_2 -> V_15 . V_16 ) ;
if ( V_22 < 0 ) {
F_8 ( V_26 , L_13 ) ;
return V_22 ;
}
V_22 = F_1 ( V_2 ,
V_8 [ V_2 -> type ] [ V_2 -> V_6 ] ) ;
if ( V_22 < 0 ) {
F_8 ( V_26 , L_13 ) ;
return V_22 ;
}
return 0 ;
}
static bool F_29 ( struct V_25 * V_26 , unsigned int V_82 )
{
switch ( V_82 ) {
case V_30 :
case V_31 :
case V_27 :
case V_81 :
case V_74 :
return true ;
default:
return false ;
}
}
static const char * F_30 ( struct V_25 * V_26 , int * V_83 )
{
const struct V_84 * V_73 ;
V_73 = F_31 ( V_26 -> V_85 -> V_86 , V_26 ) ;
if ( ! V_73 )
return NULL ;
* V_83 = ( int ) V_73 -> V_87 ;
return F_32 ( V_26 ) ;
}
static int F_33 ( struct V_88 * V_89 ,
const struct V_90 * V_73 )
{
struct V_1 * V_2 ;
struct V_50 * V_51 ;
int V_91 ;
const char * V_92 = NULL ;
int V_93 = 0 ;
V_51 = F_34 ( & V_89 -> V_26 , sizeof( * V_2 ) ) ;
if ( ! V_51 ) {
F_8 ( & V_89 -> V_26 , L_14 ) ;
return - V_94 ;
}
V_2 = F_17 ( V_51 ) ;
F_35 ( V_89 , V_51 ) ;
if ( V_73 ) {
V_92 = V_73 -> V_92 ;
V_93 = V_73 -> V_87 ;
}
if ( F_36 ( & V_89 -> V_26 ) )
V_92 = F_30 ( & V_89 -> V_26 , & V_93 ) ;
F_37 ( & V_2 -> V_56 ) ;
V_2 -> type = V_93 ;
V_2 -> V_36 = 1 ;
V_2 -> V_37 = 0 ;
V_2 -> V_6 = V_95 ;
V_2 -> V_15 = V_14 [ V_2 -> V_6 ] [ 0 ] ;
V_2 -> V_65 = false ;
V_2 -> V_10 = F_38 ( V_89 ,
V_96 [ V_93 ] . V_97 ) ;
if ( F_39 ( V_2 -> V_10 ) ) {
V_91 = F_40 ( V_2 -> V_10 ) ;
F_8 ( & V_89 -> V_26 , L_15 , V_91 ) ;
return V_91 ;
}
V_91 = F_27 ( V_2 ) ;
if ( V_91 )
return V_91 ;
V_51 -> V_98 = V_96 [ V_93 ] . V_99 ;
V_51 -> V_100 = V_96 [ V_93 ] . V_100 ;
V_51 -> V_101 = V_96 [ V_93 ] . V_101 ;
V_51 -> V_92 = V_92 ;
V_51 -> V_26 . V_102 = & V_89 -> V_26 ;
V_51 -> V_103 = V_104 ;
V_91 = F_41 ( & V_89 -> V_26 , V_51 ) ;
if ( V_91 ) {
F_8 ( & V_89 -> V_26 , L_16 ) ;
return V_91 ;
}
return 0 ;
}
static int F_42 ( struct V_25 * V_26 )
{
struct V_1 * V_2 = F_17 ( F_43 ( V_26 ) ) ;
F_22 ( & V_2 -> V_56 ) ;
V_2 -> V_65 = true ;
F_23 ( & V_2 -> V_56 ) ;
return 0 ;
}
static int F_44 ( struct V_25 * V_26 )
{
struct V_1 * V_2 = F_17 ( F_43 ( V_26 ) ) ;
int V_91 ;
F_22 ( & V_2 -> V_56 ) ;
V_91 = F_27 ( V_2 ) ;
if ( ! V_91 )
V_2 -> V_65 = false ;
F_23 ( & V_2 -> V_56 ) ;
return V_91 ;
}
