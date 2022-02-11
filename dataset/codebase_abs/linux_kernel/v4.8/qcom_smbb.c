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
F_23 ( V_6 -> V_37 , V_38 ,
V_6 -> V_34 & V_36 ) ;
F_24 ( V_6 -> V_39 ) ;
return V_40 ;
}
static T_1 F_25 ( int V_28 , void * V_35 )
{
struct V_5 * V_6 = V_35 ;
F_18 ( V_6 , V_28 , V_41 ) ;
if ( ! V_6 -> V_42 )
F_24 ( V_6 -> V_43 ) ;
return V_40 ;
}
static T_1 F_26 ( int V_28 , void * V_35 )
{
struct V_5 * V_6 = V_35 ;
unsigned int V_2 ;
int V_13 ;
V_13 = F_11 ( V_6 -> V_21 , V_6 -> V_22 + V_44 , & V_2 ) ;
if ( V_13 )
return V_40 ;
F_20 ( & V_6 -> V_33 ) ;
if ( V_2 & V_45 ) {
V_6 -> V_34 |= V_46 ;
} else {
V_6 -> V_34 &= ~ V_46 ;
if ( V_2 & V_47 )
V_6 -> V_34 |= V_48 ;
}
F_21 ( & V_6 -> V_33 ) ;
F_24 ( V_6 -> V_49 ) ;
return V_40 ;
}
static T_1 F_27 ( int V_28 , void * V_35 )
{
struct V_5 * V_6 = V_35 ;
F_18 ( V_6 , V_28 , V_50 ) ;
F_24 ( V_6 -> V_49 ) ;
return V_40 ;
}
static T_1 F_28 ( int V_28 , void * V_35 )
{
struct V_5 * V_6 = V_35 ;
F_18 ( V_6 , V_28 , V_51 ) ;
F_24 ( V_6 -> V_49 ) ;
return V_40 ;
}
static T_1 F_29 ( int V_28 , void * V_35 )
{
struct V_5 * V_6 = V_35 ;
F_18 ( V_6 , V_28 , V_52 ) ;
F_24 ( V_6 -> V_49 ) ;
F_24 ( V_6 -> V_39 ) ;
if ( ! V_6 -> V_42 )
F_24 ( V_6 -> V_43 ) ;
return V_40 ;
}
static T_1 F_30 ( int V_28 , void * V_35 )
{
struct V_5 * V_6 = V_35 ;
F_18 ( V_6 , V_28 , V_53 ) ;
F_24 ( V_6 -> V_49 ) ;
return V_40 ;
}
static T_1 F_31 ( int V_28 , void * V_35 )
{
struct V_5 * V_6 = V_35 ;
F_18 ( V_6 , V_28 , V_54 ) ;
F_24 ( V_6 -> V_49 ) ;
return V_40 ;
}
static int F_32 ( struct V_55 * V_56 ,
enum V_57 V_58 ,
union V_59 * V_2 )
{
struct V_5 * V_6 = F_33 ( V_56 ) ;
int V_13 = 0 ;
switch ( V_58 ) {
case V_60 :
F_20 ( & V_6 -> V_33 ) ;
V_2 -> V_61 = ! ( V_6 -> V_34 & V_52 ) &&
( V_6 -> V_34 & V_36 ) ;
F_21 ( & V_6 -> V_33 ) ;
break;
case V_62 :
V_2 -> V_61 = V_6 -> V_25 [ V_63 ] ;
break;
case V_64 :
V_2 -> V_61 = 2500000 ;
break;
default:
V_13 = - V_19 ;
break;
}
return V_13 ;
}
static int F_34 ( struct V_55 * V_56 ,
enum V_57 V_58 ,
const union V_59 * V_2 )
{
struct V_5 * V_6 = F_33 ( V_56 ) ;
int V_13 ;
switch ( V_58 ) {
case V_62 :
V_13 = F_9 ( V_6 , V_63 ,
V_2 -> V_61 ) ;
break;
default:
V_13 = - V_19 ;
break;
}
return V_13 ;
}
static int F_35 ( struct V_55 * V_56 ,
enum V_57 V_58 ,
union V_59 * V_2 )
{
struct V_5 * V_6 = F_33 ( V_56 ) ;
int V_13 = 0 ;
switch ( V_58 ) {
case V_60 :
F_20 ( & V_6 -> V_33 ) ;
V_2 -> V_61 = ! ( V_6 -> V_34 & V_52 ) &&
( V_6 -> V_34 & V_41 ) ;
F_21 ( & V_6 -> V_33 ) ;
break;
case V_62 :
V_2 -> V_61 = V_6 -> V_25 [ V_65 ] ;
break;
case V_64 :
V_2 -> V_61 = 2500000 ;
break;
default:
V_13 = - V_19 ;
break;
}
return V_13 ;
}
static int F_36 ( struct V_55 * V_56 ,
enum V_57 V_58 ,
const union V_59 * V_2 )
{
struct V_5 * V_6 = F_33 ( V_56 ) ;
int V_13 ;
switch ( V_58 ) {
case V_62 :
V_13 = F_9 ( V_6 , V_65 ,
V_2 -> V_61 ) ;
break;
default:
V_13 = - V_19 ;
break;
}
return V_13 ;
}
static int F_37 ( struct V_55 * V_56 ,
enum V_57 V_58 )
{
return V_58 == V_62 ;
}
static int F_38 ( struct V_55 * V_56 ,
enum V_57 V_58 ,
union V_59 * V_2 )
{
struct V_5 * V_6 = F_33 ( V_56 ) ;
unsigned long V_34 ;
int V_13 = 0 ;
F_20 ( & V_6 -> V_33 ) ;
V_34 = V_6 -> V_34 ;
F_21 ( & V_6 -> V_33 ) ;
switch ( V_58 ) {
case V_66 :
if ( V_34 & V_52 )
V_2 -> V_61 = V_67 ;
else if ( ! ( V_34 & ( V_41 | V_36 ) ) )
V_2 -> V_61 = V_67 ;
else if ( V_34 & V_51 )
V_2 -> V_61 = V_68 ;
else if ( ! ( V_34 & V_46 ) )
V_2 -> V_61 = V_67 ;
else if ( V_34 & ( V_53 | V_54 ) )
V_2 -> V_61 = V_69 ;
else
V_2 -> V_61 = V_67 ;
break;
case V_70 :
if ( V_34 & V_46 )
V_2 -> V_61 = V_71 ;
else if ( V_34 & V_48 )
V_2 -> V_61 = V_72 ;
else
V_2 -> V_61 = V_73 ;
break;
case V_74 :
if ( V_34 & V_53 )
V_2 -> V_61 = V_75 ;
else if ( V_34 & V_54 )
V_2 -> V_61 = V_76 ;
else
V_2 -> V_61 = V_77 ;
break;
case V_78 :
V_2 -> V_61 = ! ! ( V_34 & V_50 ) ;
break;
case V_79 :
V_2 -> V_61 = V_6 -> V_25 [ V_80 ] ;
break;
case V_81 :
V_2 -> V_61 = V_6 -> V_25 [ V_82 ] ;
break;
case V_83 :
V_2 -> V_61 = V_84 ;
break;
case V_85 :
V_2 -> V_61 = 3000000 ;
break;
default:
V_13 = - V_19 ;
break;
}
return V_13 ;
}
static int F_39 ( struct V_55 * V_56 ,
enum V_57 V_58 ,
const union V_59 * V_2 )
{
struct V_5 * V_6 = F_33 ( V_56 ) ;
int V_13 ;
switch ( V_58 ) {
case V_79 :
V_13 = F_9 ( V_6 , V_80 , V_2 -> V_61 ) ;
break;
case V_81 :
V_13 = F_9 ( V_6 , V_82 , V_2 -> V_61 ) ;
break;
default:
V_13 = - V_19 ;
break;
}
return V_13 ;
}
static int F_40 ( struct V_55 * V_56 ,
enum V_57 V_58 )
{
switch ( V_58 ) {
case V_79 :
case V_81 :
return 1 ;
default:
return 0 ;
}
}
static int F_41 ( struct V_86 * V_87 )
{
struct V_88 V_89 = {} ;
struct V_88 V_90 = {} ;
struct V_88 V_91 = {} ;
struct V_5 * V_6 ;
int V_13 , V_92 ;
V_6 = F_42 ( & V_87 -> V_17 , sizeof( * V_6 ) , V_93 ) ;
if ( ! V_6 )
return - V_94 ;
V_6 -> V_17 = & V_87 -> V_17 ;
F_43 ( & V_6 -> V_33 ) ;
V_6 -> V_21 = F_44 ( V_87 -> V_17 . V_95 , NULL ) ;
if ( ! V_6 -> V_21 ) {
F_10 ( & V_87 -> V_17 , L_11 ) ;
return - V_96 ;
}
V_13 = F_17 ( V_87 -> V_17 . V_26 , L_12 , & V_6 -> V_22 ) ;
if ( V_13 ) {
F_10 ( & V_87 -> V_17 , L_13 ) ;
return V_13 ;
}
V_13 = F_11 ( V_6 -> V_21 , V_6 -> V_22 + V_97 , & V_6 -> V_98 ) ;
if ( V_13 ) {
F_10 ( & V_87 -> V_17 , L_14 ) ;
return V_13 ;
}
V_6 -> V_98 += 1 ;
if ( V_6 -> V_98 != 2 && V_6 -> V_98 != 3 ) {
F_10 ( & V_87 -> V_17 , L_15 ) ;
return - V_96 ;
}
F_45 ( & V_87 -> V_17 , L_16 , V_6 -> V_98 ) ;
V_6 -> V_42 = F_46 ( V_87 -> V_17 . V_26 , L_17 ) ;
for ( V_92 = 0 ; V_92 < V_99 ; ++ V_92 ) {
V_13 = F_16 ( V_6 , V_92 ) ;
if ( V_13 ) {
F_10 ( & V_87 -> V_17 , L_18 ) ;
return V_13 ;
}
}
V_89 . V_100 = V_6 ;
V_89 . V_26 = V_87 -> V_17 . V_26 ;
V_6 -> V_49 = F_47 ( & V_87 -> V_17 ,
& V_101 ,
& V_89 ) ;
if ( F_48 ( V_6 -> V_49 ) ) {
F_10 ( & V_87 -> V_17 , L_19 ) ;
return F_49 ( V_6 -> V_49 ) ;
}
V_90 . V_100 = V_6 ;
V_90 . V_102 = V_103 ;
V_90 . V_104 = F_50 ( V_103 ) ;
V_6 -> V_39 = F_47 ( & V_87 -> V_17 ,
& V_105 ,
& V_90 ) ;
if ( F_48 ( V_6 -> V_39 ) ) {
F_10 ( & V_87 -> V_17 , L_20 ) ;
return F_49 ( V_6 -> V_39 ) ;
}
V_6 -> V_37 = F_51 ( & V_87 -> V_17 , V_106 ) ;
if ( F_48 ( V_6 -> V_37 ) ) {
F_10 ( & V_87 -> V_17 , L_21 ) ;
return - V_94 ;
}
V_13 = F_52 ( & V_87 -> V_17 , V_6 -> V_37 ) ;
if ( V_13 < 0 ) {
F_10 ( & V_87 -> V_17 , L_22 ) ;
return V_13 ;
}
if ( ! V_6 -> V_42 ) {
V_91 . V_100 = V_6 ;
V_91 . V_102 = V_103 ;
V_91 . V_104 = F_50 ( V_103 ) ;
V_6 -> V_43 = F_47 ( & V_87 -> V_17 ,
& V_107 ,
& V_91 ) ;
if ( F_48 ( V_6 -> V_43 ) ) {
F_10 ( & V_87 -> V_17 , L_23 ) ;
return F_49 ( V_6 -> V_43 ) ;
}
}
for ( V_92 = 0 ; V_92 < F_50 ( V_108 ) ; ++ V_92 ) {
int V_28 ;
V_28 = F_53 ( V_87 , V_108 [ V_92 ] . V_18 ) ;
if ( V_28 < 0 ) {
F_10 ( & V_87 -> V_17 , L_24 ,
V_108 [ V_92 ] . V_18 ) ;
return V_28 ;
}
V_108 [ V_92 ] . F_54 ( V_28 , V_6 ) ;
V_13 = F_55 ( & V_87 -> V_17 , V_28 , NULL ,
V_108 [ V_92 ] . F_54 , V_109 ,
V_108 [ V_92 ] . V_18 , V_6 ) ;
if ( V_13 ) {
F_10 ( & V_87 -> V_17 , L_25 ,
V_108 [ V_92 ] . V_18 ) ;
return V_13 ;
}
}
V_6 -> V_110 = F_46 ( V_87 -> V_17 . V_26 ,
L_26 ) ;
V_13 = F_56 ( V_6 -> V_21 , V_6 -> V_22 + V_111 ,
V_112 | V_113 ,
V_6 -> V_110 ?
V_112 :
V_113 ) ;
if ( V_13 ) {
F_10 ( & V_87 -> V_17 ,
L_27 ,
V_6 -> V_110 ? L_28 : L_29 ) ;
return V_13 ;
}
for ( V_92 = 0 ; V_92 < F_50 ( V_114 ) ; ++ V_92 ) {
const struct V_115 * V_116 = & V_114 [ V_92 ] ;
if ( V_116 -> V_117 & F_57 ( V_6 -> V_98 ) )
continue;
V_13 = F_56 ( V_6 -> V_21 , V_6 -> V_22 + V_116 -> V_118 ,
V_116 -> V_119 , V_116 -> V_120 ) ;
if ( V_13 ) {
F_10 ( & V_87 -> V_17 ,
L_30 ) ;
return V_13 ;
}
}
F_58 ( V_87 , V_6 ) ;
return 0 ;
}
static int F_59 ( struct V_86 * V_87 )
{
struct V_5 * V_6 ;
V_6 = F_60 ( V_87 ) ;
F_56 ( V_6 -> V_21 , V_6 -> V_22 + V_121 , V_122 , 0 ) ;
return 0 ;
}
