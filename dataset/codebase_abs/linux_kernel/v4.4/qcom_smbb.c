static int F_1 ( unsigned int V_1 )
{
return 2100000 + V_1 * 100000 ;
}
static int F_2 ( unsigned int V_1 )
{
if ( V_1 > 42 )
return 5600000 + ( V_1 - 43 ) * 200000 ;
return 3400000 + V_1 * 50000 ;
}
static int F_3 ( unsigned int V_1 )
{
return 3240000 + V_1 * 10000 ;
}
static int F_4 ( unsigned int V_1 )
{
return 3240000 + V_1 * 20000 ;
}
static int F_5 ( unsigned int V_1 )
{
if ( V_1 < 2 )
return 100000 + V_1 * 50000 ;
return V_1 * 100000 ;
}
static int F_6 ( unsigned int V_1 )
{
return V_1 * 50000 ;
}
static unsigned int F_7 ( unsigned int V_2 , int (* F_8)( unsigned int ) )
{
unsigned int V_3 ;
unsigned int V_4 ;
for ( V_3 = V_4 = 0 ; (* F_8)( V_3 ) <= V_2 ; ++ V_3 )
V_4 = V_3 ;
return V_4 ;
}
static int F_9 ( struct V_5 * V_6 ,
enum V_7 V_8 , unsigned int V_2 )
{
const struct V_9 * V_10 ;
unsigned int V_11 ;
unsigned int V_12 ;
int V_13 ;
V_10 = & V_14 [ V_8 ] ;
if ( V_2 > V_10 -> V_15 || V_2 < V_10 -> V_16 ) {
F_10 ( V_6 -> V_17 , L_1 ,
V_10 -> V_18 , V_10 -> V_16 , V_10 -> V_15 ) ;
return - V_19 ;
}
if ( V_10 -> V_20 ) {
V_13 = F_11 ( V_6 -> V_21 ,
V_6 -> V_22 + V_10 -> V_20 , & V_11 ) ;
if ( V_13 ) {
F_10 ( V_6 -> V_17 ,
L_2 ,
V_10 -> V_18 ) ;
return V_13 ;
}
V_11 = V_10 -> V_23 ( V_11 ) ;
if ( V_2 > V_11 ) {
F_12 ( V_6 -> V_17 ,
L_3 ,
V_10 -> V_18 , V_11 ) ;
V_2 = V_11 ;
}
}
V_11 = F_7 ( V_2 , V_10 -> V_23 ) ;
V_13 = F_13 ( V_6 -> V_21 , V_6 -> V_22 + V_10 -> V_24 , V_11 ) ;
if ( V_13 ) {
F_10 ( V_6 -> V_17 , L_4 , V_10 -> V_18 ) ;
return V_13 ;
}
V_12 = V_10 -> V_23 ( V_11 ) ;
if ( V_12 != V_2 ) {
F_12 ( V_6 -> V_17 ,
L_5 ,
V_10 -> V_18 , V_12 ) ;
}
F_14 ( V_6 -> V_17 , L_6 , V_10 -> V_18 , V_12 ) ;
V_6 -> V_25 [ V_8 ] = V_12 ;
return 0 ;
}
static int F_15 ( struct V_5 * V_6 ,
enum V_7 V_8 )
{
const struct V_9 * V_10 ;
unsigned int V_2 ;
int V_13 ;
V_10 = & V_14 [ V_8 ] ;
V_13 = F_11 ( V_6 -> V_21 , V_6 -> V_22 + V_10 -> V_24 , & V_2 ) ;
if ( V_13 ) {
F_10 ( V_6 -> V_17 , L_7 , V_10 -> V_18 ) ;
return V_13 ;
}
V_2 = V_10 -> V_23 ( V_2 ) ;
F_14 ( V_6 -> V_17 , L_8 , V_10 -> V_18 , V_2 ) ;
V_6 -> V_25 [ V_8 ] = V_2 ;
return 0 ;
}
static int F_16 ( struct V_5 * V_6 ,
enum V_7 V_8 )
{
const struct V_9 * V_10 ;
unsigned int V_2 ;
int V_13 ;
V_10 = & V_14 [ V_8 ] ;
V_13 = F_17 ( V_6 -> V_17 -> V_26 , V_10 -> V_18 , & V_2 ) ;
if ( V_13 == 0 ) {
V_13 = F_9 ( V_6 , V_8 , V_2 ) ;
if ( ! V_13 || ! V_10 -> V_27 )
return V_13 ;
}
return F_15 ( V_6 , V_8 ) ;
}
static void F_18 ( struct V_5 * V_6 , int V_28 , int V_29 )
{
bool V_30 ;
int V_31 ;
V_31 = F_19 ( V_28 , V_32 , & V_30 ) ;
if ( V_31 < 0 ) {
F_10 ( V_6 -> V_17 , L_9 ) ;
return;
}
F_20 ( & V_6 -> V_33 ) ;
if ( V_30 )
V_6 -> V_34 |= V_29 ;
else
V_6 -> V_34 &= ~ V_29 ;
F_21 ( & V_6 -> V_33 ) ;
F_14 ( V_6 -> V_17 , L_10 , V_6 -> V_34 ) ;
}
static T_1 F_22 ( int V_28 , void * V_35 )
{
struct V_5 * V_6 = V_35 ;
F_18 ( V_6 , V_28 , V_36 ) ;
F_23 ( V_6 -> V_37 ) ;
return V_38 ;
}
static T_1 F_24 ( int V_28 , void * V_35 )
{
struct V_5 * V_6 = V_35 ;
F_18 ( V_6 , V_28 , V_39 ) ;
if ( ! V_6 -> V_40 )
F_23 ( V_6 -> V_41 ) ;
return V_38 ;
}
static T_1 F_25 ( int V_28 , void * V_35 )
{
struct V_5 * V_6 = V_35 ;
unsigned int V_2 ;
int V_13 ;
V_13 = F_11 ( V_6 -> V_21 , V_6 -> V_22 + V_42 , & V_2 ) ;
if ( V_13 )
return V_38 ;
F_20 ( & V_6 -> V_33 ) ;
if ( V_2 & V_43 ) {
V_6 -> V_34 |= V_44 ;
} else {
V_6 -> V_34 &= ~ V_44 ;
if ( V_2 & V_45 )
V_6 -> V_34 |= V_46 ;
}
F_21 ( & V_6 -> V_33 ) ;
F_23 ( V_6 -> V_47 ) ;
return V_38 ;
}
static T_1 F_26 ( int V_28 , void * V_35 )
{
struct V_5 * V_6 = V_35 ;
F_18 ( V_6 , V_28 , V_48 ) ;
F_23 ( V_6 -> V_47 ) ;
return V_38 ;
}
static T_1 F_27 ( int V_28 , void * V_35 )
{
struct V_5 * V_6 = V_35 ;
F_18 ( V_6 , V_28 , V_49 ) ;
F_23 ( V_6 -> V_47 ) ;
return V_38 ;
}
static T_1 F_28 ( int V_28 , void * V_35 )
{
struct V_5 * V_6 = V_35 ;
F_18 ( V_6 , V_28 , V_50 ) ;
F_23 ( V_6 -> V_47 ) ;
F_23 ( V_6 -> V_37 ) ;
if ( ! V_6 -> V_40 )
F_23 ( V_6 -> V_41 ) ;
return V_38 ;
}
static T_1 F_29 ( int V_28 , void * V_35 )
{
struct V_5 * V_6 = V_35 ;
F_18 ( V_6 , V_28 , V_51 ) ;
F_23 ( V_6 -> V_47 ) ;
return V_38 ;
}
static T_1 F_30 ( int V_28 , void * V_35 )
{
struct V_5 * V_6 = V_35 ;
F_18 ( V_6 , V_28 , V_52 ) ;
F_23 ( V_6 -> V_47 ) ;
return V_38 ;
}
static int F_31 ( struct V_53 * V_54 ,
enum V_55 V_56 ,
union V_57 * V_2 )
{
struct V_5 * V_6 = F_32 ( V_54 ) ;
int V_13 = 0 ;
switch ( V_56 ) {
case V_58 :
F_20 ( & V_6 -> V_33 ) ;
V_2 -> V_59 = ! ( V_6 -> V_34 & V_50 ) &&
( V_6 -> V_34 & V_36 ) ;
F_21 ( & V_6 -> V_33 ) ;
break;
case V_60 :
V_2 -> V_59 = V_6 -> V_25 [ V_61 ] ;
break;
case V_62 :
V_2 -> V_59 = 2500000 ;
break;
default:
V_13 = - V_19 ;
break;
}
return V_13 ;
}
static int F_33 ( struct V_53 * V_54 ,
enum V_55 V_56 ,
const union V_57 * V_2 )
{
struct V_5 * V_6 = F_32 ( V_54 ) ;
int V_13 ;
switch ( V_56 ) {
case V_60 :
V_13 = F_9 ( V_6 , V_61 ,
V_2 -> V_59 ) ;
break;
default:
V_13 = - V_19 ;
break;
}
return V_13 ;
}
static int F_34 ( struct V_53 * V_54 ,
enum V_55 V_56 ,
union V_57 * V_2 )
{
struct V_5 * V_6 = F_32 ( V_54 ) ;
int V_13 = 0 ;
switch ( V_56 ) {
case V_58 :
F_20 ( & V_6 -> V_33 ) ;
V_2 -> V_59 = ! ( V_6 -> V_34 & V_50 ) &&
( V_6 -> V_34 & V_39 ) ;
F_21 ( & V_6 -> V_33 ) ;
break;
case V_60 :
V_2 -> V_59 = V_6 -> V_25 [ V_63 ] ;
break;
case V_62 :
V_2 -> V_59 = 2500000 ;
break;
default:
V_13 = - V_19 ;
break;
}
return V_13 ;
}
static int F_35 ( struct V_53 * V_54 ,
enum V_55 V_56 ,
const union V_57 * V_2 )
{
struct V_5 * V_6 = F_32 ( V_54 ) ;
int V_13 ;
switch ( V_56 ) {
case V_60 :
V_13 = F_9 ( V_6 , V_63 ,
V_2 -> V_59 ) ;
break;
default:
V_13 = - V_19 ;
break;
}
return V_13 ;
}
static int F_36 ( struct V_53 * V_54 ,
enum V_55 V_56 )
{
return V_56 == V_60 ;
}
static int F_37 ( struct V_53 * V_54 ,
enum V_55 V_56 ,
union V_57 * V_2 )
{
struct V_5 * V_6 = F_32 ( V_54 ) ;
unsigned long V_34 ;
int V_13 = 0 ;
F_20 ( & V_6 -> V_33 ) ;
V_34 = V_6 -> V_34 ;
F_21 ( & V_6 -> V_33 ) ;
switch ( V_56 ) {
case V_64 :
if ( V_34 & V_50 )
V_2 -> V_59 = V_65 ;
else if ( ! ( V_34 & ( V_39 | V_36 ) ) )
V_2 -> V_59 = V_65 ;
else if ( V_34 & V_49 )
V_2 -> V_59 = V_66 ;
else if ( ! ( V_34 & V_44 ) )
V_2 -> V_59 = V_65 ;
else if ( V_34 & ( V_51 | V_52 ) )
V_2 -> V_59 = V_67 ;
else
V_2 -> V_59 = V_65 ;
break;
case V_68 :
if ( V_34 & V_44 )
V_2 -> V_59 = V_69 ;
else if ( V_34 & V_46 )
V_2 -> V_59 = V_70 ;
else
V_2 -> V_59 = V_71 ;
break;
case V_72 :
if ( V_34 & V_51 )
V_2 -> V_59 = V_73 ;
else if ( V_34 & V_52 )
V_2 -> V_59 = V_74 ;
else
V_2 -> V_59 = V_75 ;
break;
case V_76 :
V_2 -> V_59 = ! ! ( V_34 & V_48 ) ;
break;
case V_77 :
V_2 -> V_59 = V_6 -> V_25 [ V_78 ] ;
break;
case V_79 :
V_2 -> V_59 = V_6 -> V_25 [ V_80 ] ;
break;
case V_81 :
V_2 -> V_59 = V_82 ;
break;
case V_83 :
V_2 -> V_59 = 3000000 ;
break;
default:
V_13 = - V_19 ;
break;
}
return V_13 ;
}
static int F_38 ( struct V_53 * V_54 ,
enum V_55 V_56 ,
const union V_57 * V_2 )
{
struct V_5 * V_6 = F_32 ( V_54 ) ;
int V_13 ;
switch ( V_56 ) {
case V_77 :
V_13 = F_9 ( V_6 , V_78 , V_2 -> V_59 ) ;
break;
case V_79 :
V_13 = F_9 ( V_6 , V_80 , V_2 -> V_59 ) ;
break;
default:
V_13 = - V_19 ;
break;
}
return V_13 ;
}
static int F_39 ( struct V_53 * V_54 ,
enum V_55 V_56 )
{
switch ( V_56 ) {
case V_77 :
case V_79 :
return 1 ;
default:
return 0 ;
}
}
static int F_40 ( struct V_84 * V_85 )
{
struct V_86 V_87 = {} ;
struct V_86 V_88 = {} ;
struct V_86 V_89 = {} ;
struct V_5 * V_6 ;
int V_13 , V_90 ;
V_6 = F_41 ( & V_85 -> V_17 , sizeof( * V_6 ) , V_91 ) ;
if ( ! V_6 )
return - V_92 ;
V_6 -> V_17 = & V_85 -> V_17 ;
F_42 ( & V_6 -> V_33 ) ;
V_6 -> V_21 = F_43 ( V_85 -> V_17 . V_93 , NULL ) ;
if ( ! V_6 -> V_21 ) {
F_10 ( & V_85 -> V_17 , L_11 ) ;
return - V_94 ;
}
V_13 = F_17 ( V_85 -> V_17 . V_26 , L_12 , & V_6 -> V_22 ) ;
if ( V_13 ) {
F_10 ( & V_85 -> V_17 , L_13 ) ;
return V_13 ;
}
V_13 = F_11 ( V_6 -> V_21 , V_6 -> V_22 + V_95 , & V_6 -> V_96 ) ;
if ( V_13 ) {
F_10 ( & V_85 -> V_17 , L_14 ) ;
return V_13 ;
}
V_6 -> V_96 += 1 ;
if ( V_6 -> V_96 != 2 && V_6 -> V_96 != 3 ) {
F_10 ( & V_85 -> V_17 , L_15 ) ;
return - V_94 ;
}
F_44 ( & V_85 -> V_17 , L_16 , V_6 -> V_96 ) ;
V_6 -> V_40 = F_45 ( V_85 -> V_17 . V_26 , L_17 ) ;
for ( V_90 = 0 ; V_90 < V_97 ; ++ V_90 ) {
V_13 = F_16 ( V_6 , V_90 ) ;
if ( V_13 ) {
F_10 ( & V_85 -> V_17 , L_18 ) ;
return V_13 ;
}
}
V_87 . V_98 = V_6 ;
V_87 . V_26 = V_85 -> V_17 . V_26 ;
V_6 -> V_47 = F_46 ( & V_85 -> V_17 ,
& V_99 ,
& V_87 ) ;
if ( F_47 ( V_6 -> V_47 ) ) {
F_10 ( & V_85 -> V_17 , L_19 ) ;
return F_48 ( V_6 -> V_47 ) ;
}
V_88 . V_98 = V_6 ;
V_88 . V_100 = V_101 ;
V_88 . V_102 = F_49 ( V_101 ) ;
V_6 -> V_37 = F_46 ( & V_85 -> V_17 ,
& V_103 ,
& V_88 ) ;
if ( F_47 ( V_6 -> V_37 ) ) {
F_10 ( & V_85 -> V_17 , L_20 ) ;
return F_48 ( V_6 -> V_37 ) ;
}
if ( ! V_6 -> V_40 ) {
V_89 . V_98 = V_6 ;
V_89 . V_100 = V_101 ;
V_89 . V_102 = F_49 ( V_101 ) ;
V_6 -> V_41 = F_46 ( & V_85 -> V_17 ,
& V_104 ,
& V_89 ) ;
if ( F_47 ( V_6 -> V_41 ) ) {
F_10 ( & V_85 -> V_17 , L_21 ) ;
return F_48 ( V_6 -> V_41 ) ;
}
}
for ( V_90 = 0 ; V_90 < F_49 ( V_105 ) ; ++ V_90 ) {
int V_28 ;
V_28 = F_50 ( V_85 , V_105 [ V_90 ] . V_18 ) ;
if ( V_28 < 0 ) {
F_10 ( & V_85 -> V_17 , L_22 ,
V_105 [ V_90 ] . V_18 ) ;
return V_28 ;
}
V_105 [ V_90 ] . F_51 ( V_28 , V_6 ) ;
V_13 = F_52 ( & V_85 -> V_17 , V_28 , NULL ,
V_105 [ V_90 ] . F_51 , V_106 ,
V_105 [ V_90 ] . V_18 , V_6 ) ;
if ( V_13 ) {
F_10 ( & V_85 -> V_17 , L_23 ,
V_105 [ V_90 ] . V_18 ) ;
return V_13 ;
}
}
V_6 -> V_107 = F_45 ( V_85 -> V_17 . V_26 ,
L_24 ) ;
V_13 = F_53 ( V_6 -> V_21 , V_6 -> V_22 + V_108 ,
V_109 | V_110 ,
V_6 -> V_107 ?
V_109 :
V_110 ) ;
if ( V_13 ) {
F_10 ( & V_85 -> V_17 ,
L_25 ,
V_6 -> V_107 ? L_26 : L_27 ) ;
return V_13 ;
}
for ( V_90 = 0 ; V_90 < F_49 ( V_111 ) ; ++ V_90 ) {
const struct V_112 * V_113 = & V_111 [ V_90 ] ;
if ( V_113 -> V_114 & F_54 ( V_6 -> V_96 ) )
continue;
V_13 = F_53 ( V_6 -> V_21 , V_6 -> V_22 + V_113 -> V_115 ,
V_113 -> V_116 , V_113 -> V_117 ) ;
if ( V_13 ) {
F_10 ( & V_85 -> V_17 ,
L_28 ) ;
return V_13 ;
}
}
F_55 ( V_85 , V_6 ) ;
return 0 ;
}
static int F_56 ( struct V_84 * V_85 )
{
struct V_5 * V_6 ;
V_6 = F_57 ( V_85 ) ;
F_53 ( V_6 -> V_21 , V_6 -> V_22 + V_118 , V_119 , 0 ) ;
return 0 ;
}
