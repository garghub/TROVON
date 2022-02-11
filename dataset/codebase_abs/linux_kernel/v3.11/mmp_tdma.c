static void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
F_2 ( V_3 , V_2 -> V_4 + V_5 ) ;
F_2 ( F_3 ( V_2 -> V_4 + V_6 ) | V_7 ,
V_2 -> V_4 + V_6 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
F_2 ( V_8 , V_2 -> V_4 + V_9 ) ;
F_2 ( F_3 ( V_2 -> V_4 + V_6 ) | V_10 ,
V_2 -> V_4 + V_6 ) ;
V_2 -> V_11 = V_12 ;
}
static void F_5 ( struct V_1 * V_2 )
{
F_2 ( F_3 ( V_2 -> V_4 + V_6 ) & ~ V_10 ,
V_2 -> V_4 + V_6 ) ;
F_2 ( 0 , V_2 -> V_4 + V_9 ) ;
V_2 -> V_11 = V_13 ;
}
static void F_6 ( struct V_1 * V_2 )
{
F_2 ( F_3 ( V_2 -> V_4 + V_6 ) | V_10 ,
V_2 -> V_4 + V_6 ) ;
V_2 -> V_11 = V_12 ;
}
static void F_7 ( struct V_1 * V_2 )
{
F_2 ( F_3 ( V_2 -> V_4 + V_6 ) & ~ V_10 ,
V_2 -> V_4 + V_6 ) ;
V_2 -> V_11 = V_14 ;
}
static int F_8 ( struct V_1 * V_2 )
{
unsigned int V_15 ;
F_5 ( V_2 ) ;
if ( V_2 -> V_16 == V_17 )
V_15 = V_18 | V_19 ;
else if ( V_2 -> V_16 == V_20 )
V_15 = V_21 | V_22 ;
if ( V_2 -> type == V_23 ) {
V_15 |= V_24 ;
switch ( V_2 -> V_25 ) {
case 4 :
V_15 |= V_26 ;
break;
case 8 :
V_15 |= V_27 ;
break;
case 16 :
V_15 |= V_28 ;
break;
case 32 :
V_15 |= V_29 ;
break;
case 64 :
V_15 |= V_30 ;
break;
case 128 :
V_15 |= V_31 ;
break;
default:
F_9 ( V_2 -> V_32 , L_1 ) ;
return - V_33 ;
}
switch ( V_2 -> V_34 ) {
case V_35 :
V_15 |= V_36 ;
break;
case V_37 :
V_15 |= V_38 ;
break;
case V_39 :
V_15 |= V_40 ;
break;
default:
F_9 ( V_2 -> V_32 , L_2 ) ;
return - V_33 ;
}
} else if ( V_2 -> type == V_41 ) {
V_15 |= V_42 ;
V_15 |= V_43 ;
}
F_2 ( V_15 , V_2 -> V_4 + V_6 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
T_2 V_44 = F_3 ( V_2 -> V_4 + V_45 ) ;
if ( V_44 & V_46 ) {
V_44 &= ~ V_46 ;
F_2 ( V_44 , V_2 -> V_4 + V_45 ) ;
return 0 ;
}
return - V_47 ;
}
static T_3 F_11 ( int V_48 , void * V_49 )
{
struct V_1 * V_2 = V_49 ;
if ( F_10 ( V_2 ) == 0 ) {
V_2 -> V_50 = ( V_2 -> V_50 + V_2 -> V_51 ) % V_2 -> V_52 ;
F_12 ( & V_2 -> V_53 ) ;
return V_54 ;
} else
return V_55 ;
}
static T_3 F_13 ( int V_48 , void * V_49 )
{
struct V_56 * V_57 = V_49 ;
int V_58 , V_59 ;
int V_60 = 0 ;
for ( V_58 = 0 ; V_58 < V_61 ; V_58 ++ ) {
struct V_1 * V_2 = V_57 -> V_2 [ V_58 ] ;
V_59 = F_11 ( V_48 , V_2 ) ;
if ( V_59 == V_54 )
V_60 ++ ;
}
if ( V_60 )
return V_54 ;
else
return V_55 ;
}
static void F_14 ( unsigned long V_62 )
{
struct V_1 * V_2 = (struct V_1 * ) V_62 ;
if ( V_2 -> V_63 . V_64 )
V_2 -> V_63 . V_64 ( V_2 -> V_63 . V_65 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
struct V_66 * V_67 ;
int V_68 = V_2 -> V_69 * sizeof( struct V_70 ) ;
V_67 = F_16 ( L_3 ) ;
if ( V_2 -> V_71 )
F_17 ( V_67 , ( unsigned long ) V_2 -> V_71 ,
V_68 ) ;
V_2 -> V_71 = NULL ;
return;
}
static T_4 F_18 ( struct V_72 * V_73 )
{
struct V_1 * V_2 = F_19 ( V_73 -> V_74 ) ;
F_1 ( V_2 , V_2 -> V_75 ) ;
return 0 ;
}
static int F_20 ( struct V_76 * V_74 )
{
struct V_1 * V_2 = F_19 ( V_74 ) ;
int V_59 ;
F_21 ( & V_2 -> V_63 , V_74 ) ;
V_2 -> V_63 . V_77 = F_18 ;
if ( V_2 -> V_48 ) {
V_59 = F_22 ( V_2 -> V_32 , V_2 -> V_48 ,
F_11 , V_78 , L_4 , V_2 ) ;
if ( V_59 )
return V_59 ;
}
return 1 ;
}
static void F_23 ( struct V_76 * V_74 )
{
struct V_1 * V_2 = F_19 ( V_74 ) ;
if ( V_2 -> V_48 )
F_24 ( V_2 -> V_32 , V_2 -> V_48 , V_2 ) ;
F_15 ( V_2 ) ;
return;
}
struct V_70 * F_25 ( struct V_1 * V_2 )
{
struct V_66 * V_67 ;
int V_68 = V_2 -> V_69 * sizeof( struct V_70 ) ;
V_67 = F_16 ( L_3 ) ;
if ( ! V_67 )
return NULL ;
V_2 -> V_71 = ( void * ) F_26 ( V_67 , V_68 ) ;
if ( ! V_2 -> V_71 )
return NULL ;
V_2 -> V_75 = F_27 ( V_67 ,
( unsigned long ) V_2 -> V_71 ) ;
return V_2 -> V_71 ;
}
static struct V_72 * F_28 (
struct V_76 * V_74 , T_1 V_79 , T_5 V_52 ,
T_5 V_51 , enum V_80 V_81 ,
unsigned long V_82 , void * V_83 )
{
struct V_1 * V_2 = F_19 ( V_74 ) ;
struct V_70 * V_63 ;
int V_84 = V_52 / V_51 ;
int V_58 = 0 , V_85 = 0 ;
if ( V_2 -> V_11 != V_13 )
return NULL ;
if ( V_51 > V_86 ) {
F_9 ( V_2 -> V_32 ,
L_5 ,
V_51 , V_86 ) ;
goto V_87;
}
V_2 -> V_11 = V_12 ;
V_2 -> V_69 = V_84 ;
V_63 = F_25 ( V_2 ) ;
if ( ! V_63 )
goto V_87;
while ( V_85 < V_52 ) {
V_63 = & V_2 -> V_71 [ V_58 ] ;
if ( V_58 + 1 == V_84 )
V_63 -> V_88 = V_2 -> V_75 ;
else
V_63 -> V_88 = V_2 -> V_75 +
sizeof( * V_63 ) * ( V_58 + 1 ) ;
if ( V_81 == V_17 ) {
V_63 -> V_89 = V_79 ;
V_63 -> V_90 = V_2 -> V_91 ;
} else {
V_63 -> V_89 = V_2 -> V_91 ;
V_63 -> V_90 = V_79 ;
}
V_63 -> V_92 = V_51 ;
V_79 += V_51 ;
V_85 += V_51 ;
V_58 ++ ;
}
V_2 -> V_52 = V_52 ;
V_2 -> V_51 = V_51 ;
V_2 -> V_50 = 0 ;
return & V_2 -> V_63 ;
V_87:
V_2 -> V_11 = V_93 ;
return NULL ;
}
static int F_29 ( struct V_76 * V_74 , enum V_94 V_95 ,
unsigned long V_96 )
{
struct V_1 * V_2 = F_19 ( V_74 ) ;
struct V_97 * V_98 = ( void * ) V_96 ;
int V_59 = 0 ;
switch ( V_95 ) {
case V_99 :
F_5 ( V_2 ) ;
break;
case V_100 :
F_7 ( V_2 ) ;
break;
case V_101 :
F_6 ( V_2 ) ;
break;
case V_102 :
if ( V_98 -> V_81 == V_20 ) {
V_2 -> V_91 = V_98 -> V_89 ;
V_2 -> V_25 = V_98 -> V_103 ;
V_2 -> V_34 = V_98 -> V_104 ;
} else {
V_2 -> V_91 = V_98 -> V_90 ;
V_2 -> V_25 = V_98 -> V_105 ;
V_2 -> V_34 = V_98 -> V_106 ;
}
V_2 -> V_16 = V_98 -> V_81 ;
return F_8 ( V_2 ) ;
default:
V_59 = - V_107 ;
}
return V_59 ;
}
static enum V_108 F_30 ( struct V_76 * V_74 ,
T_4 V_109 , struct V_110 * V_111 )
{
struct V_1 * V_2 = F_19 ( V_74 ) ;
F_31 ( V_111 , V_2 -> V_52 - V_2 -> V_50 ) ;
return V_2 -> V_11 ;
}
static void F_32 ( struct V_76 * V_74 )
{
struct V_1 * V_2 = F_19 ( V_74 ) ;
F_4 ( V_2 ) ;
}
static int F_33 ( struct V_112 * V_113 )
{
struct V_56 * V_57 = F_34 ( V_113 ) ;
F_35 ( & V_57 -> V_114 ) ;
return 0 ;
}
static int F_36 ( struct V_56 * V_57 ,
int V_115 , int V_48 , int type )
{
struct V_1 * V_2 ;
if ( V_115 >= V_61 ) {
F_9 ( V_57 -> V_32 , L_6 ) ;
return - V_33 ;
}
V_2 = F_37 ( V_57 -> V_32 , sizeof( * V_2 ) , V_116 ) ;
if ( ! V_2 ) {
F_9 ( V_57 -> V_32 , L_7 ) ;
return - V_117 ;
}
if ( V_48 )
V_2 -> V_48 = V_48 ;
V_2 -> V_32 = V_57 -> V_32 ;
V_2 -> V_74 . V_114 = & V_57 -> V_114 ;
V_2 -> V_115 = V_115 ;
V_2 -> type = type ;
V_2 -> V_4 = ( unsigned long ) V_57 -> V_118 + V_115 * 4 ;
V_2 -> V_11 = V_13 ;
V_57 -> V_2 [ V_2 -> V_115 ] = V_2 ;
F_38 ( & V_2 -> V_53 , F_14 , ( unsigned long ) V_2 ) ;
F_39 ( & V_2 -> V_74 . V_119 ,
& V_57 -> V_114 . V_120 ) ;
return 0 ;
}
static int F_40 ( struct V_112 * V_113 )
{
enum V_121 type ;
const struct V_122 * V_123 ;
struct V_56 * V_57 ;
struct V_124 * V_125 ;
int V_58 , V_59 ;
int V_48 = 0 , V_60 = 0 ;
int V_126 = V_61 ;
V_123 = F_41 ( V_127 , & V_113 -> V_32 ) ;
if ( V_123 )
type = (enum V_121 ) V_123 -> V_62 ;
else
type = F_42 ( V_113 ) -> V_128 ;
V_57 = F_37 ( & V_113 -> V_32 , sizeof( * V_57 ) , V_116 ) ;
if ( ! V_57 )
return - V_117 ;
V_57 -> V_32 = & V_113 -> V_32 ;
for ( V_58 = 0 ; V_58 < V_126 ; V_58 ++ ) {
if ( F_43 ( V_113 , V_58 ) > 0 )
V_60 ++ ;
}
V_125 = F_44 ( V_113 , V_129 , 0 ) ;
if ( ! V_125 )
return - V_33 ;
V_57 -> V_118 = F_45 ( & V_113 -> V_32 , V_125 ) ;
if ( F_46 ( V_57 -> V_118 ) )
return F_47 ( V_57 -> V_118 ) ;
F_48 ( & V_57 -> V_114 . V_120 ) ;
if ( V_60 != V_126 ) {
V_48 = F_43 ( V_113 , 0 ) ;
V_59 = F_22 ( & V_113 -> V_32 , V_48 ,
F_13 , V_78 , L_4 , V_57 ) ;
if ( V_59 )
return V_59 ;
}
for ( V_58 = 0 ; V_58 < V_126 ; V_58 ++ ) {
V_48 = ( V_60 != V_126 ) ? 0 : F_43 ( V_113 , V_58 ) ;
V_59 = F_36 ( V_57 , V_58 , V_48 , type ) ;
if ( V_59 )
return V_59 ;
}
F_49 ( V_130 , V_57 -> V_114 . V_131 ) ;
F_49 ( V_132 , V_57 -> V_114 . V_131 ) ;
V_57 -> V_114 . V_32 = & V_113 -> V_32 ;
V_57 -> V_114 . V_133 =
F_20 ;
V_57 -> V_114 . V_134 =
F_23 ;
V_57 -> V_114 . V_135 = F_28 ;
V_57 -> V_114 . V_136 = F_30 ;
V_57 -> V_114 . V_137 = F_32 ;
V_57 -> V_114 . V_138 = F_29 ;
V_57 -> V_114 . V_139 = V_140 ;
F_50 ( & V_113 -> V_32 , F_51 ( 64 ) ) ;
F_52 ( V_113 , V_57 ) ;
V_59 = F_53 ( & V_57 -> V_114 ) ;
if ( V_59 ) {
F_9 ( V_57 -> V_114 . V_32 , L_8 ) ;
return V_59 ;
}
F_54 ( V_57 -> V_114 . V_32 , L_9 ) ;
return 0 ;
}
