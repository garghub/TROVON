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
struct V_5 * V_6 = F_42 ( V_87 ) ;
int V_13 ;
V_13 = F_43 ( V_6 -> V_21 , V_6 -> V_22 + V_88 ,
V_89 , V_89 ) ;
if ( V_13 )
F_10 ( V_6 -> V_17 , L_11 ) ;
return V_13 ;
}
static int F_44 ( struct V_86 * V_87 )
{
struct V_5 * V_6 = F_42 ( V_87 ) ;
int V_13 ;
V_13 = F_43 ( V_6 -> V_21 , V_6 -> V_22 + V_88 ,
V_89 , 0 ) ;
if ( V_13 )
F_10 ( V_6 -> V_17 , L_11 ) ;
return V_13 ;
}
static int F_45 ( struct V_86 * V_87 )
{
struct V_5 * V_6 = F_42 ( V_87 ) ;
unsigned int V_90 = 0 ;
int V_13 ;
V_13 = F_11 ( V_6 -> V_21 , V_6 -> V_22 + V_88 , & V_90 ) ;
if ( V_13 )
F_10 ( V_6 -> V_17 , L_12 ) ;
return ! ! ( V_90 & V_89 ) ;
}
static int F_46 ( struct V_91 * V_92 )
{
struct V_93 V_94 = {} ;
struct V_93 V_95 = {} ;
struct V_93 V_96 = {} ;
struct V_5 * V_6 ;
struct V_97 V_98 = { } ;
int V_13 , V_99 ;
V_6 = F_47 ( & V_92 -> V_17 , sizeof( * V_6 ) , V_100 ) ;
if ( ! V_6 )
return - V_101 ;
V_6 -> V_17 = & V_92 -> V_17 ;
F_48 ( & V_6 -> V_33 ) ;
V_6 -> V_21 = F_49 ( V_92 -> V_17 . V_102 , NULL ) ;
if ( ! V_6 -> V_21 ) {
F_10 ( & V_92 -> V_17 , L_13 ) ;
return - V_103 ;
}
V_13 = F_17 ( V_92 -> V_17 . V_26 , L_14 , & V_6 -> V_22 ) ;
if ( V_13 ) {
F_10 ( & V_92 -> V_17 , L_15 ) ;
return V_13 ;
}
V_13 = F_11 ( V_6 -> V_21 , V_6 -> V_22 + V_104 , & V_6 -> V_105 ) ;
if ( V_13 ) {
F_10 ( & V_92 -> V_17 , L_16 ) ;
return V_13 ;
}
V_6 -> V_105 += 1 ;
if ( V_6 -> V_105 != 2 && V_6 -> V_105 != 3 ) {
F_10 ( & V_92 -> V_17 , L_17 ) ;
return - V_103 ;
}
F_50 ( & V_92 -> V_17 , L_18 , V_6 -> V_105 ) ;
V_6 -> V_42 = F_51 ( V_92 -> V_17 . V_26 , L_19 ) ;
for ( V_99 = 0 ; V_99 < V_106 ; ++ V_99 ) {
V_13 = F_16 ( V_6 , V_99 ) ;
if ( V_13 ) {
F_10 ( & V_92 -> V_17 , L_20 ) ;
return V_13 ;
}
}
V_94 . V_107 = V_6 ;
V_94 . V_26 = V_92 -> V_17 . V_26 ;
V_6 -> V_49 = F_52 ( & V_92 -> V_17 ,
& V_108 ,
& V_94 ) ;
if ( F_53 ( V_6 -> V_49 ) ) {
F_10 ( & V_92 -> V_17 , L_21 ) ;
return F_54 ( V_6 -> V_49 ) ;
}
V_95 . V_107 = V_6 ;
V_95 . V_109 = V_110 ;
V_95 . V_111 = F_55 ( V_110 ) ;
V_6 -> V_39 = F_52 ( & V_92 -> V_17 ,
& V_112 ,
& V_95 ) ;
if ( F_53 ( V_6 -> V_39 ) ) {
F_10 ( & V_92 -> V_17 , L_22 ) ;
return F_54 ( V_6 -> V_39 ) ;
}
V_6 -> V_37 = F_56 ( & V_92 -> V_17 , V_113 ) ;
if ( F_53 ( V_6 -> V_37 ) ) {
F_10 ( & V_92 -> V_17 , L_23 ) ;
return - V_101 ;
}
V_13 = F_57 ( & V_92 -> V_17 , V_6 -> V_37 ) ;
if ( V_13 < 0 ) {
F_10 ( & V_92 -> V_17 , L_24 ) ;
return V_13 ;
}
if ( ! V_6 -> V_42 ) {
V_96 . V_107 = V_6 ;
V_96 . V_109 = V_110 ;
V_96 . V_111 = F_55 ( V_110 ) ;
V_6 -> V_43 = F_52 ( & V_92 -> V_17 ,
& V_114 ,
& V_96 ) ;
if ( F_53 ( V_6 -> V_43 ) ) {
F_10 ( & V_92 -> V_17 , L_25 ) ;
return F_54 ( V_6 -> V_43 ) ;
}
}
for ( V_99 = 0 ; V_99 < F_55 ( V_115 ) ; ++ V_99 ) {
int V_28 ;
V_28 = F_58 ( V_92 , V_115 [ V_99 ] . V_18 ) ;
if ( V_28 < 0 ) {
F_10 ( & V_92 -> V_17 , L_26 ,
V_115 [ V_99 ] . V_18 ) ;
return V_28 ;
}
V_115 [ V_99 ] . F_59 ( V_28 , V_6 ) ;
V_13 = F_60 ( & V_92 -> V_17 , V_28 , NULL ,
V_115 [ V_99 ] . F_59 , V_116 ,
V_115 [ V_99 ] . V_18 , V_6 ) ;
if ( V_13 ) {
F_10 ( & V_92 -> V_17 , L_27 ,
V_115 [ V_99 ] . V_18 ) ;
return V_13 ;
}
}
V_6 -> V_117 . V_118 = - 1 ;
V_6 -> V_117 . V_18 = L_28 ;
V_6 -> V_117 . V_119 = & V_120 ;
V_6 -> V_117 . V_121 = V_122 ;
V_6 -> V_117 . type = V_123 ;
V_6 -> V_117 . V_124 = L_29 ;
V_6 -> V_117 . V_125 = L_28 ;
V_98 . V_17 = & V_92 -> V_17 ;
V_98 . V_126 = V_6 ;
V_6 -> V_127 = F_61 ( & V_92 -> V_17 , & V_6 -> V_117 ,
& V_98 ) ;
if ( F_53 ( V_6 -> V_127 ) )
return F_54 ( V_6 -> V_127 ) ;
V_6 -> V_128 = F_51 ( V_92 -> V_17 . V_26 ,
L_30 ) ;
V_13 = F_43 ( V_6 -> V_21 , V_6 -> V_22 + V_129 ,
V_130 | V_131 ,
V_6 -> V_128 ?
V_130 :
V_131 ) ;
if ( V_13 ) {
F_10 ( & V_92 -> V_17 ,
L_31 ,
V_6 -> V_128 ? L_32 : L_33 ) ;
return V_13 ;
}
for ( V_99 = 0 ; V_99 < F_55 ( V_132 ) ; ++ V_99 ) {
const struct V_133 * V_134 = & V_132 [ V_99 ] ;
if ( V_134 -> V_135 & F_62 ( V_6 -> V_105 ) )
continue;
V_13 = F_43 ( V_6 -> V_21 , V_6 -> V_22 + V_134 -> V_136 ,
V_134 -> V_137 , V_134 -> V_90 ) ;
if ( V_13 ) {
F_10 ( & V_92 -> V_17 ,
L_34 ) ;
return V_13 ;
}
}
F_63 ( V_92 , V_6 ) ;
return 0 ;
}
static int F_64 ( struct V_91 * V_92 )
{
struct V_5 * V_6 ;
V_6 = F_65 ( V_92 ) ;
F_43 ( V_6 -> V_21 , V_6 -> V_22 + V_138 , V_139 , 0 ) ;
return 0 ;
}
