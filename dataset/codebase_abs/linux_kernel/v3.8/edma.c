static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static inline struct V_5 * F_3 ( struct V_6 * V_7 )
{
return F_2 ( V_7 , struct V_5 , V_8 . V_9 ) ;
}
static inline struct V_10
* F_4 ( struct V_11 * V_12 )
{
return F_2 ( V_12 , struct V_10 , V_13 . V_12 ) ;
}
static void F_5 ( struct V_14 * V_13 )
{
F_6 ( F_2 ( V_13 , struct V_10 , V_13 ) ) ;
}
static void F_7 ( struct V_5 * V_15 )
{
struct V_14 * V_13 = F_8 ( & V_15 -> V_8 ) ;
struct V_10 * V_16 ;
int V_17 ;
if ( ! V_13 ) {
V_15 -> V_16 = NULL ;
return;
}
F_9 ( & V_13 -> V_18 ) ;
V_15 -> V_16 = V_16 = F_4 ( & V_13 -> V_12 ) ;
for ( V_17 = 0 ; V_17 < V_16 -> V_19 ; V_17 ++ ) {
F_10 ( V_15 -> V_20 [ V_17 ] , & V_16 -> V_21 [ V_17 ] ) ;
F_11 ( V_15 -> V_8 . V_9 . V_22 -> V_23 ,
L_1
L_2
L_3
L_4
L_5
L_6
L_7
L_8
L_9
L_10
L_11 ,
V_17 , V_15 -> V_24 , V_15 -> V_20 [ V_17 ] ,
V_16 -> V_21 [ V_17 ] . V_25 ,
V_16 -> V_21 [ V_17 ] . V_26 ,
V_16 -> V_21 [ V_17 ] . V_27 ,
V_16 -> V_21 [ V_17 ] . V_28 ,
V_16 -> V_21 [ V_17 ] . V_29 ,
V_16 -> V_21 [ V_17 ] . V_30 ,
V_16 -> V_21 [ V_17 ] . V_31 ,
V_16 -> V_21 [ V_17 ] . V_32 ) ;
if ( V_17 != ( V_16 -> V_19 - 1 ) )
F_12 ( V_15 -> V_20 [ V_17 ] , V_15 -> V_20 [ V_17 + 1 ] ) ;
else
F_12 ( V_15 -> V_20 [ V_17 ] , V_15 -> V_33 -> V_34 ) ;
}
F_13 ( V_15 -> V_24 ) ;
}
static int F_14 ( struct V_5 * V_15 )
{
unsigned long V_35 ;
F_15 ( V_36 ) ;
F_16 ( & V_15 -> V_8 . V_37 , V_35 ) ;
if ( V_15 -> V_16 ) {
V_15 -> V_16 = NULL ;
F_17 ( V_15 -> V_24 ) ;
}
F_18 ( & V_15 -> V_8 , & V_36 ) ;
F_19 ( & V_15 -> V_8 . V_37 , V_35 ) ;
F_20 ( & V_15 -> V_8 , & V_36 ) ;
return 0 ;
}
static int F_21 ( struct V_5 * V_15 ,
struct V_38 * V_39 )
{
if ( ( V_39 -> V_40 > V_41 ) ||
( V_39 -> V_42 > V_41 ) )
return - V_43 ;
if ( V_39 -> V_44 == V_45 ) {
if ( V_39 -> V_46 )
V_15 -> V_47 = V_39 -> V_46 ;
if ( V_39 -> V_42 )
V_15 -> V_48 = V_39 -> V_42 ;
if ( V_39 -> V_49 )
V_15 -> V_50 = V_39 -> V_49 ;
} else if ( V_39 -> V_44 == V_51 ) {
if ( V_39 -> V_52 )
V_15 -> V_47 = V_39 -> V_52 ;
if ( V_39 -> V_40 )
V_15 -> V_48 = V_39 -> V_40 ;
if ( V_39 -> V_53 )
V_15 -> V_50 = V_39 -> V_53 ;
}
return 0 ;
}
static int F_22 ( struct V_6 * V_9 , enum V_54 V_55 ,
unsigned long V_56 )
{
int V_57 = 0 ;
struct V_38 * V_39 ;
struct V_5 * V_15 = F_3 ( V_9 ) ;
switch ( V_55 ) {
case V_58 :
F_14 ( V_15 ) ;
break;
case V_59 :
V_39 = (struct V_38 * ) V_56 ;
V_57 = F_21 ( V_15 , V_39 ) ;
break;
default:
V_57 = - V_60 ;
}
return V_57 ;
}
static struct V_11 * F_23 (
struct V_6 * V_9 , struct V_61 * V_62 ,
unsigned int V_63 , enum V_64 V_44 ,
unsigned long V_65 , void * V_66 )
{
struct V_5 * V_15 = F_3 ( V_9 ) ;
struct V_22 * V_23 = V_9 -> V_22 -> V_23 ;
struct V_10 * V_16 ;
struct V_61 * V_67 ;
int V_17 ;
int V_68 , V_69 , V_29 , V_26 , V_27 , V_70 ;
int V_71 , V_72 , V_73 , V_74 ;
if ( F_24 ( ! V_15 || ! V_62 || ! V_63 ) )
return NULL ;
if ( V_15 -> V_48 == V_75 ) {
F_25 ( V_23 , L_12 ) ;
return NULL ;
}
if ( V_63 > V_76 ) {
F_25 ( V_23 , L_13 ,
V_63 , V_76 ) ;
return NULL ;
}
V_16 = F_26 ( sizeof( * V_16 ) + V_63 *
sizeof( V_16 -> V_21 [ 0 ] ) , V_77 ) ;
if ( ! V_16 ) {
F_11 ( V_23 , L_14 ) ;
return NULL ;
}
V_16 -> V_19 = V_63 ;
F_27 (sgl, sg, sg_len, i) {
if ( V_15 -> V_20 [ V_17 ] < 0 ) {
V_15 -> V_20 [ V_17 ] =
F_28 ( F_29 ( V_15 -> V_24 ) ,
V_78 ) ;
if ( V_15 -> V_20 [ V_17 ] < 0 ) {
F_25 ( V_23 , L_15 ) ;
return NULL ;
}
}
V_68 = V_15 -> V_48 ;
if ( V_15 -> V_50 == 1 ) {
V_16 -> V_79 = false ;
V_29 = F_30 ( V_67 ) / V_68 / ( V_80 - 1 ) ;
V_69 = F_30 ( V_67 ) / V_68 - V_29 * ( V_80 - 1 ) ;
if ( V_69 )
V_29 ++ ;
else
V_69 = V_80 - 1 ;
V_70 = V_68 ;
} else {
V_16 -> V_79 = true ;
V_69 = V_15 -> V_50 ;
V_29 = F_30 ( V_67 ) / ( V_68 * V_69 ) ;
if ( V_29 > ( V_80 - 1 ) ) {
F_25 ( V_23 , L_16 ) ;
return NULL ;
}
V_70 = V_68 * V_69 ;
}
if ( V_44 == V_45 ) {
V_26 = F_31 ( V_67 ) ;
V_27 = V_15 -> V_47 ;
V_71 = V_68 ;
V_73 = V_70 ;
V_72 = 0 ;
V_74 = 0 ;
} else {
V_26 = V_15 -> V_47 ;
V_27 = F_31 ( V_67 ) ;
V_71 = 0 ;
V_73 = 0 ;
V_72 = V_68 ;
V_74 = V_70 ;
}
V_16 -> V_21 [ V_17 ] . V_25 = F_32 ( F_33 ( V_15 -> V_24 ) ) ;
if ( V_16 -> V_79 )
V_16 -> V_21 [ V_17 ] . V_25 |= V_81 ;
if ( V_17 == V_63 - 1 )
V_16 -> V_21 [ V_17 ] . V_25 |= V_82 ;
V_16 -> V_21 [ V_17 ] . V_26 = V_26 ;
V_16 -> V_21 [ V_17 ] . V_27 = V_27 ;
V_16 -> V_21 [ V_17 ] . V_30 = ( V_72 << 16 ) | V_71 ;
V_16 -> V_21 [ V_17 ] . V_31 = ( V_74 << 16 ) | V_73 ;
V_16 -> V_21 [ V_17 ] . V_28 = V_69 << 16 | V_68 ;
V_16 -> V_21 [ V_17 ] . V_29 = V_29 ;
V_16 -> V_21 [ V_17 ] . V_32 = 0xffffffff ;
}
return F_34 ( & V_15 -> V_8 , & V_16 -> V_13 , V_65 ) ;
}
static void F_35 ( unsigned V_24 , T_1 V_83 , void * V_84 )
{
struct V_5 * V_15 = V_84 ;
struct V_22 * V_23 = V_15 -> V_8 . V_9 . V_22 -> V_23 ;
struct V_10 * V_16 ;
unsigned long V_35 ;
F_17 ( V_15 -> V_24 ) ;
switch ( V_83 ) {
case V_85 :
F_11 ( V_23 , L_17 , V_24 ) ;
F_16 ( & V_15 -> V_8 . V_37 , V_35 ) ;
V_16 = V_15 -> V_16 ;
if ( V_16 ) {
F_7 ( V_15 ) ;
F_36 ( & V_16 -> V_13 ) ;
}
F_19 ( & V_15 -> V_8 . V_37 , V_35 ) ;
break;
case V_86 :
F_11 ( V_23 , L_18 , V_24 ) ;
break;
default:
break;
}
}
static int F_37 ( struct V_6 * V_9 )
{
struct V_5 * V_15 = F_3 ( V_9 ) ;
struct V_22 * V_23 = V_9 -> V_22 -> V_23 ;
int V_57 ;
int V_87 ;
F_15 ( V_88 ) ;
V_87 = F_38 ( V_15 -> V_24 , F_35 ,
V_9 , V_89 ) ;
if ( V_87 < 0 ) {
V_57 = - V_90 ;
goto V_91;
}
if ( V_87 != V_15 -> V_24 ) {
F_25 ( V_23 , L_19 ,
F_29 ( V_15 -> V_24 ) ,
F_33 ( V_15 -> V_24 ) ) ;
V_57 = - V_90 ;
goto V_92;
}
V_15 -> V_93 = true ;
V_15 -> V_20 [ 0 ] = V_15 -> V_24 ;
F_39 ( V_23 , L_20 ,
F_29 ( V_15 -> V_24 ) , F_33 ( V_15 -> V_24 ) ) ;
return 0 ;
V_92:
F_40 ( V_87 ) ;
V_91:
return V_57 ;
}
static void F_41 ( struct V_6 * V_9 )
{
struct V_5 * V_15 = F_3 ( V_9 ) ;
struct V_22 * V_23 = V_9 -> V_22 -> V_23 ;
int V_17 ;
F_17 ( V_15 -> V_24 ) ;
F_42 ( & V_15 -> V_8 ) ;
for ( V_17 = 1 ; V_17 < V_94 ; V_17 ++ ) {
if ( V_15 -> V_20 [ V_17 ] >= 0 ) {
F_43 ( V_15 -> V_20 [ V_17 ] ) ;
V_15 -> V_20 [ V_17 ] = - 1 ;
}
}
if ( V_15 -> V_93 ) {
F_40 ( V_15 -> V_24 ) ;
V_15 -> V_93 = false ;
}
F_39 ( V_23 , L_21 , V_15 -> V_24 ) ;
}
static void F_44 ( struct V_6 * V_9 )
{
struct V_5 * V_15 = F_3 ( V_9 ) ;
unsigned long V_35 ;
F_16 ( & V_15 -> V_8 . V_37 , V_35 ) ;
if ( F_45 ( & V_15 -> V_8 ) && ! V_15 -> V_16 )
F_7 ( V_15 ) ;
F_19 ( & V_15 -> V_8 . V_37 , V_35 ) ;
}
static T_2 F_46 ( struct V_10 * V_16 )
{
int V_17 ;
T_2 V_95 ;
if ( V_16 -> V_79 )
for ( V_95 = V_17 = 0 ; V_17 < V_16 -> V_19 ; V_17 ++ )
V_95 += ( V_16 -> V_21 [ V_17 ] . V_28 & 0xffff ) *
( V_16 -> V_21 [ V_17 ] . V_28 >> 16 ) *
V_16 -> V_21 [ V_17 ] . V_29 ;
else
V_95 = ( V_16 -> V_21 [ 0 ] . V_28 & 0xffff ) *
( V_16 -> V_21 [ 0 ] . V_28 >> 16 ) +
( V_16 -> V_21 [ 0 ] . V_28 & 0xffff ) *
( V_80 - 1 ) * V_16 -> V_21 [ 0 ] . V_29 ;
return V_95 ;
}
static enum V_96 F_47 ( struct V_6 * V_9 ,
T_3 V_97 ,
struct V_98 * V_99 )
{
struct V_5 * V_15 = F_3 ( V_9 ) ;
struct V_14 * V_13 ;
enum V_96 V_57 ;
unsigned long V_35 ;
V_57 = F_48 ( V_9 , V_97 , V_99 ) ;
if ( V_57 == V_100 || ! V_99 )
return V_57 ;
F_16 ( & V_15 -> V_8 . V_37 , V_35 ) ;
V_13 = F_49 ( & V_15 -> V_8 , V_97 ) ;
if ( V_13 ) {
V_99 -> V_101 = F_46 ( F_4 ( & V_13 -> V_12 ) ) ;
} else if ( V_15 -> V_16 && V_15 -> V_16 -> V_13 . V_12 . V_97 == V_97 ) {
struct V_10 * V_16 = V_15 -> V_16 ;
V_99 -> V_101 = F_46 ( V_16 ) ;
} else {
V_99 -> V_101 = 0 ;
}
F_19 ( & V_15 -> V_8 . V_37 , V_35 ) ;
return V_57 ;
}
static void T_4 F_50 ( struct V_1 * V_33 ,
struct V_2 * V_102 ,
struct V_5 * V_103 )
{
int V_17 , V_104 ;
for ( V_17 = 0 ; V_17 < V_105 ; V_17 ++ ) {
struct V_5 * V_15 = & V_103 [ V_17 ] ;
V_15 -> V_24 = F_51 ( V_33 -> V_106 , V_17 ) ;
V_15 -> V_33 = V_33 ;
V_15 -> V_8 . V_107 = F_5 ;
F_52 ( & V_15 -> V_8 , V_102 ) ;
F_53 ( & V_15 -> V_18 ) ;
for ( V_104 = 0 ; V_104 < V_94 ; V_104 ++ )
V_15 -> V_20 [ V_104 ] = - 1 ;
}
}
static void F_54 ( struct V_1 * V_33 , struct V_2 * V_102 ,
struct V_22 * V_23 )
{
V_102 -> V_108 = F_23 ;
V_102 -> V_109 = F_37 ;
V_102 -> V_110 = F_41 ;
V_102 -> V_111 = F_44 ;
V_102 -> V_112 = F_47 ;
V_102 -> V_113 = F_22 ;
V_102 -> V_23 = V_23 ;
F_53 ( & V_102 -> V_114 ) ;
}
static int F_55 ( struct V_115 * V_116 )
{
struct V_1 * V_33 ;
int V_57 ;
V_33 = F_56 ( & V_116 -> V_23 , sizeof( * V_33 ) , V_117 ) ;
if ( ! V_33 ) {
F_25 ( & V_116 -> V_23 , L_22 ) ;
return - V_118 ;
}
V_33 -> V_106 = V_116 -> V_119 ;
V_33 -> V_34 = F_28 ( V_33 -> V_106 , V_78 ) ;
if ( V_33 -> V_34 < 0 ) {
F_25 ( & V_116 -> V_23 , L_23 ) ;
return - V_120 ;
}
F_57 ( V_33 -> V_4 . V_121 ) ;
F_58 ( V_122 , V_33 -> V_4 . V_121 ) ;
F_54 ( V_33 , & V_33 -> V_4 , & V_116 -> V_23 ) ;
F_50 ( V_33 , & V_33 -> V_4 , V_33 -> V_123 ) ;
V_57 = F_59 ( & V_33 -> V_4 ) ;
if ( V_57 )
goto V_124;
F_60 ( V_116 , V_33 ) ;
F_39 ( & V_116 -> V_23 , L_24 ) ;
return 0 ;
V_124:
F_43 ( V_33 -> V_34 ) ;
return V_57 ;
}
static int F_61 ( struct V_115 * V_116 )
{
struct V_22 * V_23 = & V_116 -> V_23 ;
struct V_1 * V_33 = F_62 ( V_23 ) ;
F_63 ( & V_33 -> V_4 ) ;
F_43 ( V_33 -> V_34 ) ;
return 0 ;
}
bool F_64 ( struct V_6 * V_9 , void * V_125 )
{
if ( V_9 -> V_22 -> V_23 -> V_126 == & V_127 . V_126 ) {
struct V_5 * V_15 = F_3 ( V_9 ) ;
unsigned V_128 = * ( unsigned * ) V_125 ;
return V_128 == V_15 -> V_24 ;
}
return false ;
}
static int F_65 ( void )
{
int V_57 = F_66 ( & V_127 ) ;
if ( V_57 == 0 ) {
V_129 = F_67 ( & V_130 ) ;
if ( F_68 ( V_129 ) ) {
F_69 ( & V_127 ) ;
V_57 = F_70 ( V_129 ) ;
goto V_131;
}
}
if ( V_132 == 2 ) {
V_133 = F_67 ( & V_134 ) ;
if ( F_68 ( V_133 ) ) {
F_69 ( & V_127 ) ;
F_71 ( V_129 ) ;
V_57 = F_70 ( V_133 ) ;
}
}
V_131:
return V_57 ;
}
static void T_5 F_72 ( void )
{
F_71 ( V_129 ) ;
if ( V_133 )
F_71 ( V_133 ) ;
F_69 ( & V_127 ) ;
}
