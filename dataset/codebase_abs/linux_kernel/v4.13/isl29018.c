static int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
unsigned int V_4 ;
int V_5 ;
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
unsigned int V_4 ;
int V_5 ;
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
V_33 = F_5 ( V_2 ,
V_35 ) ;
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
V_39 = F_5 ( V_2 ,
V_40 ) ;
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
V_39 = F_5 ( V_2 ,
V_40 ) ;
if ( V_39 < 0 )
return V_39 ;
if ( V_43 >= V_39 )
* V_42 = V_43 - V_39 ;
else
* V_42 = 0 ;
return 0 ;
}
static T_1 F_15
( struct V_25 * V_26 , struct V_47 * V_48 ,
char * V_49 )
{
struct V_50 * V_51 = F_16 ( V_26 ) ;
struct V_1 * V_2 = F_17 ( V_51 ) ;
unsigned int V_4 ;
int V_52 = 0 ;
F_18 ( & V_2 -> V_53 ) ;
for ( V_4 = 0 ; V_4 < F_2 ( V_14 [ V_2 -> V_6 ] ) ; ++ V_4 )
V_52 += sprintf ( V_49 + V_52 , L_6 ,
V_14 [ V_2 -> V_6 ] [ V_4 ] . V_15 ,
V_14 [ V_2 -> V_6 ] [ V_4 ] . V_16 ) ;
F_19 ( & V_2 -> V_53 ) ;
V_49 [ V_52 - 1 ] = '\n' ;
return V_52 ;
}
static T_1 F_20
( struct V_25 * V_26 , struct V_47 * V_48 ,
char * V_49 )
{
struct V_50 * V_51 = F_16 ( V_26 ) ;
struct V_1 * V_2 = F_17 ( V_51 ) ;
unsigned int V_4 ;
int V_52 = 0 ;
for ( V_4 = 0 ; V_4 < F_2 ( V_8 [ V_2 -> type ] ) ; ++ V_4 )
V_52 += sprintf ( V_49 + V_52 , L_7 ,
V_8 [ V_2 -> type ] [ V_4 ] ) ;
V_49 [ V_52 - 1 ] = '\n' ;
return V_52 ;
}
static T_1 F_21
( struct V_25 * V_26 , struct V_47 * V_48 ,
char * V_49 )
{
struct V_50 * V_51 = F_16 ( V_26 ) ;
struct V_1 * V_2 = F_17 ( V_51 ) ;
return sprintf ( V_49 , L_8 , V_2 -> V_54 ) ;
}
static T_1 F_22
( struct V_25 * V_26 , struct V_47 * V_48 ,
const char * V_49 , T_2 V_55 )
{
struct V_50 * V_51 = F_16 ( V_26 ) ;
struct V_1 * V_2 = F_17 ( V_51 ) ;
int V_56 ;
if ( F_23 ( V_49 , 10 , & V_56 ) )
return - V_9 ;
if ( ! ( V_56 == 0 || V_56 == 1 ) )
return - V_9 ;
F_18 ( & V_2 -> V_53 ) ;
V_2 -> V_54 = V_56 ;
F_19 ( & V_2 -> V_53 ) ;
return V_55 ;
}
static int F_24 ( struct V_50 * V_51 ,
struct V_57 const * V_58 ,
int V_56 ,
int V_59 ,
long V_60 )
{
struct V_1 * V_2 = F_17 ( V_51 ) ;
int V_5 = - V_9 ;
F_18 ( & V_2 -> V_53 ) ;
if ( V_2 -> V_61 ) {
V_5 = - V_62 ;
goto V_63;
}
switch ( V_60 ) {
case V_64 :
if ( V_58 -> type == V_65 ) {
V_2 -> V_36 = V_56 ;
V_2 -> V_37 = V_59 ;
V_5 = 0 ;
}
break;
case V_66 :
if ( V_58 -> type == V_65 && ! V_56 )
V_5 = F_1 ( V_2 , V_59 ) ;
break;
case V_67 :
if ( V_58 -> type == V_65 )
V_5 = F_4 ( V_2 , V_56 , V_59 ) ;
break;
default:
break;
}
V_63:
F_19 ( & V_2 -> V_53 ) ;
return V_5 ;
}
static int F_25 ( struct V_50 * V_51 ,
struct V_57 const * V_58 ,
int * V_56 ,
int * V_59 ,
long V_60 )
{
int V_5 = - V_9 ;
struct V_1 * V_2 = F_17 ( V_51 ) ;
F_18 ( & V_2 -> V_53 ) ;
if ( V_2 -> V_61 ) {
V_5 = - V_62 ;
goto V_68;
}
switch ( V_60 ) {
case V_69 :
case V_70 :
switch ( V_58 -> type ) {
case V_65 :
V_5 = F_12 ( V_2 , V_56 ) ;
break;
case V_71 :
V_5 = F_13 ( V_2 , V_56 ) ;
break;
case V_72 :
V_5 = F_14 ( V_2 ,
V_2 -> V_54 ,
V_56 ) ;
break;
default:
break;
}
if ( ! V_5 )
V_5 = V_73 ;
break;
case V_66 :
if ( V_58 -> type == V_65 ) {
* V_56 = 0 ;
* V_59 = V_8 [ V_2 -> type ] [ V_2 -> V_6 ] ;
V_5 = V_74 ;
}
break;
case V_67 :
if ( V_58 -> type == V_65 ) {
* V_56 = V_2 -> V_15 . V_15 ;
* V_59 = V_2 -> V_15 . V_16 ;
V_5 = V_74 ;
}
break;
case V_64 :
if ( V_58 -> type == V_65 ) {
* V_56 = V_2 -> V_36 ;
* V_59 = V_2 -> V_37 ;
V_5 = V_74 ;
}
break;
default:
break;
}
V_68:
F_19 ( & V_2 -> V_53 ) ;
return V_5 ;
}
static int F_26 ( struct V_1 * V_2 )
{
int V_22 ;
struct V_25 * V_26 = F_6 ( V_2 -> V_10 ) ;
if ( V_2 -> type == V_75 ) {
unsigned int V_76 ;
V_22 = F_10 ( V_2 -> V_10 , V_77 , & V_76 ) ;
if ( V_22 < 0 ) {
F_8 ( V_26 ,
L_9 ,
V_22 ) ;
return V_22 ;
}
V_76 = ( V_76 & V_78 ) >> V_79 ;
if ( V_76 != V_80 )
return - V_81 ;
V_22 = F_3 ( V_2 -> V_10 ,
V_77 ,
V_82 , 0 ) ;
if ( V_22 < 0 )
return V_22 ;
}
V_22 = F_7 ( V_2 -> V_10 , V_83 , 0x0 ) ;
if ( V_22 < 0 ) {
F_8 ( V_26 , L_10 ,
V_22 ) ;
return V_22 ;
}
V_22 = F_7 ( V_2 -> V_10 , V_27 , 0 ) ;
if ( V_22 < 0 ) {
F_8 ( V_26 , L_11 ,
V_22 ) ;
return V_22 ;
}
F_27 ( 1000 , 2000 ) ;
V_22 = F_4 ( V_2 , V_2 -> V_15 . V_15 ,
V_2 -> V_15 . V_16 ) ;
if ( V_22 < 0 ) {
F_8 ( V_26 , L_12 ) ;
return V_22 ;
}
V_22 = F_1 ( V_2 ,
V_8 [ V_2 -> type ] [ V_2 -> V_6 ] ) ;
if ( V_22 < 0 )
F_8 ( V_26 , L_12 ) ;
return V_22 ;
}
static bool F_28 ( struct V_25 * V_26 , unsigned int V_84 )
{
switch ( V_84 ) {
case V_30 :
case V_31 :
case V_27 :
case V_83 :
case V_77 :
return true ;
default:
return false ;
}
}
static const char * F_29 ( struct V_25 * V_26 , int * V_85 )
{
const struct V_86 * V_76 ;
V_76 = F_30 ( V_26 -> V_87 -> V_88 , V_26 ) ;
if ( ! V_76 )
return NULL ;
* V_85 = ( int ) V_76 -> V_89 ;
return F_31 ( V_26 ) ;
}
static int F_32 ( struct V_90 * V_91 ,
const struct V_92 * V_76 )
{
struct V_1 * V_2 ;
struct V_50 * V_51 ;
int V_93 ;
const char * V_94 = NULL ;
int V_95 = 0 ;
V_51 = F_33 ( & V_91 -> V_26 , sizeof( * V_2 ) ) ;
if ( ! V_51 )
return - V_96 ;
V_2 = F_17 ( V_51 ) ;
F_34 ( V_91 , V_51 ) ;
if ( V_76 ) {
V_94 = V_76 -> V_94 ;
V_95 = V_76 -> V_89 ;
}
if ( F_35 ( & V_91 -> V_26 ) )
V_94 = F_29 ( & V_91 -> V_26 , & V_95 ) ;
F_36 ( & V_2 -> V_53 ) ;
V_2 -> type = V_95 ;
V_2 -> V_36 = 1 ;
V_2 -> V_37 = 0 ;
V_2 -> V_6 = V_97 ;
V_2 -> V_15 = V_14 [ V_2 -> V_6 ] [ 0 ] ;
V_2 -> V_61 = false ;
V_2 -> V_10 = F_37 ( V_91 ,
V_98 [ V_95 ] . V_99 ) ;
if ( F_38 ( V_2 -> V_10 ) ) {
V_93 = F_39 ( V_2 -> V_10 ) ;
F_8 ( & V_91 -> V_26 , L_13 , V_93 ) ;
return V_93 ;
}
V_93 = F_26 ( V_2 ) ;
if ( V_93 )
return V_93 ;
V_51 -> V_100 = V_98 [ V_95 ] . V_101 ;
V_51 -> V_102 = V_98 [ V_95 ] . V_102 ;
V_51 -> V_103 = V_98 [ V_95 ] . V_103 ;
V_51 -> V_94 = V_94 ;
V_51 -> V_26 . V_104 = & V_91 -> V_26 ;
V_51 -> V_105 = V_106 ;
return F_40 ( & V_91 -> V_26 , V_51 ) ;
}
static int F_41 ( struct V_25 * V_26 )
{
struct V_1 * V_2 = F_17 ( F_42 ( V_26 ) ) ;
F_18 ( & V_2 -> V_53 ) ;
V_2 -> V_61 = true ;
F_19 ( & V_2 -> V_53 ) ;
return 0 ;
}
static int F_43 ( struct V_25 * V_26 )
{
struct V_1 * V_2 = F_17 ( F_42 ( V_26 ) ) ;
int V_93 ;
F_18 ( & V_2 -> V_53 ) ;
V_93 = F_26 ( V_2 ) ;
if ( ! V_93 )
V_2 -> V_61 = false ;
F_19 ( & V_2 -> V_53 ) ;
return V_93 ;
}
