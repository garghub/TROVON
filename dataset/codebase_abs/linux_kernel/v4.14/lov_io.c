static void F_1 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 )
{
if ( V_6 -> V_7 ) {
if ( V_6 -> V_8 ) {
F_2 ( V_6 -> V_9 , V_6 -> V_7 ) ;
V_6 -> V_8 = 0 ;
V_4 -> V_10 -- ;
}
if ( V_6 -> V_11 == V_4 -> V_12 )
V_4 -> V_12 = - 1 ;
else if ( ! V_6 -> V_13 )
F_3 ( V_6 -> V_7 ) ;
V_6 -> V_7 = NULL ;
}
if ( ! F_4 ( V_6 -> V_9 ) ) {
if ( ! V_6 -> V_13 )
F_5 ( V_6 -> V_9 , & V_6 -> V_14 ) ;
V_6 -> V_9 = NULL ;
}
}
static void F_6 ( struct V_15 * V_16 , struct V_3 * V_4 ,
int V_17 , T_1 V_18 , T_1 V_19 )
{
struct V_20 * V_21 = V_4 -> V_22 -> V_23 ;
struct V_15 * V_24 = V_4 -> V_25 . V_26 ;
switch ( V_16 -> V_27 ) {
case V_28 : {
V_16 -> V_29 . V_30 . V_31 = V_24 -> V_29 . V_30 . V_31 ;
V_16 -> V_29 . V_30 . V_32 =
V_24 -> V_29 . V_30 . V_32 ;
V_16 -> V_29 . V_30 . V_33 = V_24 -> V_29 . V_30 . V_33 ;
V_16 -> V_29 . V_30 . V_34 = V_17 ;
V_16 -> V_29 . V_30 . V_35 =
V_24 -> V_29 . V_30 . V_35 ;
if ( F_7 ( V_16 ) ) {
T_1 V_36 = V_24 -> V_29 . V_30 . V_31 . V_37 ;
V_36 = F_8 ( V_21 , V_36 , V_17 ) ;
V_16 -> V_29 . V_30 . V_31 . V_37 = V_36 ;
}
break;
}
case V_38 : {
V_16 -> V_29 . V_39 . V_40 = 0 ;
V_16 -> V_29 . V_39 . V_41 =
V_24 -> V_29 . V_39 . V_41 ;
break;
}
case V_42 : {
struct V_43 * V_44 = V_24 -> V_45 ;
T_1 V_46 = F_9 ( V_44 , V_24 -> V_29 . V_47 . V_48 ) ;
V_16 -> V_29 . V_47 = V_24 -> V_29 . V_47 ;
V_46 = F_8 ( V_21 , V_46 , V_17 ) ;
V_16 -> V_29 . V_47 . V_48 = F_10 ( V_44 , V_46 ) ;
break;
}
case V_49 : {
V_16 -> V_29 . V_50 . V_51 = V_18 ;
V_16 -> V_29 . V_50 . V_52 = V_19 ;
V_16 -> V_29 . V_50 . V_53 = V_24 -> V_29 . V_50 . V_53 ;
V_16 -> V_29 . V_50 . V_54 = V_24 -> V_29 . V_50 . V_54 ;
break;
}
case V_55 :
case V_56 : {
V_16 -> V_29 . V_57 . V_58 = F_11 ( V_24 ) ;
if ( F_12 ( V_24 ) ) {
V_16 -> V_29 . V_57 . V_59 = 1 ;
} else {
V_16 -> V_29 . V_60 . V_61 = V_18 ;
V_16 -> V_29 . V_60 . V_62 = V_19 - V_18 ;
}
break;
}
default:
break;
}
}
static int F_13 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_63 * V_64 = V_4 -> V_22 ;
struct V_15 * V_7 ;
struct V_43 * V_65 ;
struct V_15 * V_16 = V_4 -> V_25 . V_26 ;
int V_17 = V_6 -> V_11 ;
int V_66 ;
F_14 ( ! V_6 -> V_7 ) ;
F_14 ( ! V_6 -> V_9 ) ;
F_14 ( V_6 -> V_11 < V_4 -> V_67 ) ;
if ( F_15 ( ! F_16 ( V_64 ) -> V_68 [ V_17 ] ) )
return - V_69 ;
V_6 -> V_8 = 0 ;
V_6 -> V_13 = 0 ;
V_6 -> V_9 = F_17 ( & V_6 -> V_14 ) ;
if ( F_18 ( V_6 -> V_9 ) ) {
V_66 = F_19 ( V_6 -> V_9 ) ;
goto V_70;
}
if ( V_4 -> V_10 == 0 ) {
V_6 -> V_7 = & V_4 -> V_71 ;
V_4 -> V_12 = V_17 ;
} else {
V_6 -> V_7 = F_20 ( sizeof( * V_6 -> V_7 ) ,
V_72 ) ;
if ( ! V_6 -> V_7 ) {
V_66 = - V_73 ;
goto V_70;
}
}
V_65 = F_21 ( F_16 ( V_64 ) -> V_68 [ V_17 ] ) ;
V_7 = V_6 -> V_7 ;
V_7 -> V_45 = V_65 ;
V_7 -> V_74 = 0 ;
V_7 -> V_75 = V_16 ;
V_7 -> V_76 = V_16 -> V_76 ;
V_7 -> V_27 = V_16 -> V_27 ;
V_7 -> V_77 = V_16 -> V_77 ;
V_7 -> V_78 = V_16 -> V_78 ;
V_66 = F_22 ( V_6 -> V_9 , V_7 , V_16 -> V_27 , V_65 ) ;
if ( V_66 >= 0 ) {
V_4 -> V_10 ++ ;
V_6 -> V_8 = 1 ;
V_66 = 0 ;
}
V_70:
if ( V_66 )
F_1 ( V_2 , V_4 , V_6 ) ;
return V_66 ;
}
struct V_5 * F_23 ( const struct V_1 * V_2 ,
struct V_3 * V_4 , int V_17 )
{
int V_66 ;
struct V_5 * V_6 = & V_4 -> V_79 [ V_17 ] ;
F_14 ( V_17 < V_4 -> V_67 ) ;
if ( ! V_6 -> V_8 ) {
V_6 -> V_11 = V_17 ;
V_66 = F_13 ( V_2 , V_4 , V_6 ) ;
} else {
V_66 = 0 ;
}
if ( V_66 < 0 )
V_6 = F_24 ( V_66 ) ;
return V_6 ;
}
int F_25 ( const struct V_80 * V_81 )
{
const struct V_82 * V_83 ;
V_83 = F_26 ( V_81 , & V_84 ) ;
F_14 ( V_83 -> V_85 ) ;
return F_27 ( V_83 ) -> V_86 ;
}
static int F_28 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_15 * V_16 )
{
struct V_20 * V_21 ;
int V_87 ;
F_14 ( V_4 -> V_22 ) ;
V_21 = V_4 -> V_22 -> V_23 ;
V_4 -> V_79 =
F_29 ( V_21 -> V_88 *
sizeof( V_4 -> V_79 [ 0 ] ) ,
V_72 ) ;
if ( V_4 -> V_79 ) {
V_4 -> V_89 = V_4 -> V_67 ;
V_4 -> V_12 = - 1 ;
V_4 -> V_10 = 0 ;
V_87 = 0 ;
} else {
V_87 = - V_73 ;
}
return V_87 ;
}
static int F_30 ( struct V_3 * V_4 , struct V_63 * V_44 ,
struct V_15 * V_16 )
{
V_16 -> V_74 = 0 ;
V_4 -> V_22 = V_44 ;
V_4 -> V_67 = V_44 -> V_23 -> V_88 ;
switch ( V_16 -> V_27 ) {
case V_55 :
case V_56 :
V_4 -> V_90 = V_16 -> V_29 . V_60 . V_61 ;
V_4 -> V_91 = V_16 -> V_29 . V_60 . V_61 + V_16 -> V_29 . V_60 . V_62 ;
V_4 -> V_92 = V_4 -> V_91 ;
if ( F_12 ( V_16 ) ) {
F_14 ( V_16 -> V_27 == V_56 ) ;
if ( F_15 ( V_44 -> V_23 -> V_93 &
V_94 ) )
return - V_69 ;
V_4 -> V_90 = 0 ;
V_4 -> V_91 = V_95 ;
}
break;
case V_28 :
if ( F_7 ( V_16 ) )
V_4 -> V_90 = V_16 -> V_29 . V_30 . V_31 . V_37 ;
else
V_4 -> V_90 = 0 ;
V_4 -> V_91 = V_95 ;
break;
case V_38 :
V_4 -> V_90 = 0 ;
V_4 -> V_91 = V_95 ;
break;
case V_42 : {
T_2 V_96 = V_16 -> V_29 . V_47 . V_48 ;
V_4 -> V_90 = F_9 ( V_16 -> V_45 , V_96 ) ;
V_4 -> V_91 = F_9 ( V_16 -> V_45 , V_96 + 1 ) ;
break;
}
case V_49 : {
V_4 -> V_90 = V_16 -> V_29 . V_50 . V_51 ;
V_4 -> V_91 = V_16 -> V_29 . V_50 . V_52 ;
break;
}
case V_97 :
V_4 -> V_90 = 0 ;
V_4 -> V_91 = V_95 ;
break;
default:
F_31 () ;
}
return 0 ;
}
static void F_32 ( const struct V_1 * V_2 , const struct V_98 * V_99 )
{
struct V_3 * V_4 = F_33 ( V_2 , V_99 ) ;
struct V_63 * V_64 = F_34 ( V_99 -> V_100 ) ;
int V_101 ;
if ( V_4 -> V_79 ) {
for ( V_101 = 0 ; V_101 < V_4 -> V_89 ; V_101 ++ )
F_1 ( V_2 , V_4 , & V_4 -> V_79 [ V_101 ] ) ;
F_35 ( V_4 -> V_79 ) ;
V_4 -> V_89 = 0 ;
}
F_14 ( F_36 ( & V_64 -> V_102 ) > 0 ) ;
if ( F_37 ( & V_64 -> V_102 ) )
F_38 ( & V_64 -> V_103 ) ;
}
static T_3 F_39 ( T_3 V_104 , int V_105 )
{
if ( V_104 != V_95 )
V_104 += V_105 ;
return V_104 ;
}
static int F_40 ( const struct V_1 * V_2 ,
const struct V_98 * V_99 )
{
struct V_3 * V_4 = F_33 ( V_2 , V_99 ) ;
struct V_20 * V_21 = V_4 -> V_22 -> V_23 ;
struct V_5 * V_6 ;
T_3 V_106 ;
T_3 V_18 ;
T_3 V_19 ;
int V_17 ;
int V_66 = 0 ;
V_106 = F_39 ( V_4 -> V_91 , - 1 ) ;
for ( V_17 = 0 ; V_17 < V_4 -> V_67 ; V_17 ++ ) {
if ( ! F_41 ( V_21 , V_17 , V_4 -> V_90 ,
V_106 , & V_18 , & V_19 ) )
continue;
if ( F_15 ( ! F_16 ( V_4 -> V_22 ) -> V_68 [ V_17 ] ) ) {
if ( V_99 -> V_26 -> V_27 == V_55 ||
V_99 -> V_26 -> V_27 == V_56 ||
V_99 -> V_26 -> V_27 == V_42 )
return - V_69 ;
continue;
}
V_19 = F_39 ( V_19 , 1 ) ;
V_6 = F_23 ( V_2 , V_4 , V_17 ) ;
if ( F_18 ( V_6 ) ) {
V_66 = F_19 ( V_6 ) ;
break;
}
F_6 ( V_6 -> V_7 , V_4 , V_17 , V_18 , V_19 ) ;
V_66 = F_42 ( V_6 -> V_9 , V_6 -> V_7 ) ;
if ( V_66 ) {
F_43 ( V_6 -> V_9 , V_6 -> V_7 ) ;
break;
}
F_44 ( V_107 , L_1 ,
V_17 , V_18 , V_19 ) ;
F_45 ( & V_6 -> V_108 , & V_4 -> V_109 ) ;
}
return V_66 ;
}
static int F_46 ( const struct V_1 * V_2 ,
const struct V_98 * V_99 )
{
struct V_3 * V_4 = F_33 ( V_2 , V_99 ) ;
struct V_15 * V_16 = V_99 -> V_26 ;
struct V_20 * V_21 = V_4 -> V_22 -> V_23 ;
T_4 V_18 = V_16 -> V_29 . V_60 . V_61 ;
T_1 V_110 ;
unsigned long V_111 = V_21 -> V_112 ;
F_14 ( V_16 -> V_27 == V_55 || V_16 -> V_27 == V_56 ) ;
if ( V_4 -> V_89 != 1 && ! F_12 ( V_16 ) ) {
F_47 ( V_18 , V_111 ) ;
V_110 = ( V_18 + 1 ) * V_111 ;
if ( V_110 <= V_18 * V_111 )
V_110 = ~ 0ull ;
V_16 -> V_113 = V_110 < V_4 -> V_92 ;
V_16 -> V_29 . V_60 . V_62 = F_48 ( T_1 , V_4 -> V_92 ,
V_110 ) - V_16 -> V_29 . V_60 . V_61 ;
V_4 -> V_90 = V_16 -> V_29 . V_60 . V_61 ;
V_4 -> V_91 = V_16 -> V_29 . V_60 . V_61 + V_16 -> V_29 . V_60 . V_62 ;
F_44 ( V_107 , L_2 ,
( T_4 ) V_18 , V_4 -> V_90 , V_4 -> V_91 ,
( T_4 ) V_4 -> V_92 ) ;
}
return F_40 ( V_2 , V_99 ) ;
}
static int F_49 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
int (* F_50)( const struct V_1 * , struct V_15 * ) )
{
struct V_15 * V_24 = V_4 -> V_25 . V_26 ;
struct V_5 * V_6 ;
int V_66 = 0 ;
F_51 (sub, &lio->lis_active, sub_linkage) {
V_66 = F_50 ( V_6 -> V_9 , V_6 -> V_7 ) ;
if ( V_66 )
break;
if ( V_24 -> V_74 == 0 )
V_24 -> V_74 = V_6 -> V_7 -> V_74 ;
}
return V_66 ;
}
static int F_52 ( const struct V_1 * V_2 , const struct V_98 * V_99 )
{
return F_49 ( V_2 , F_33 ( V_2 , V_99 ) , V_114 ) ;
}
static int F_53 ( const struct V_1 * V_2 , const struct V_98 * V_99 )
{
return F_49 ( V_2 , F_33 ( V_2 , V_99 ) , V_115 ) ;
}
static int F_54 ( const struct V_1 * V_2 , struct V_15 * V_16 )
{
if ( V_16 -> V_116 == V_117 )
F_55 ( V_2 , V_16 ) ;
else
V_16 -> V_116 = V_118 ;
return 0 ;
}
static void
F_56 ( const struct V_1 * V_2 , const struct V_98 * V_99 )
{
struct V_3 * V_4 = F_33 ( V_2 , V_99 ) ;
struct V_15 * V_24 = V_4 -> V_25 . V_26 ;
struct V_5 * V_6 ;
F_51 (sub, &lio->lis_active, sub_linkage) {
F_54 ( V_2 , V_6 -> V_7 ) ;
V_24 -> V_29 . V_39 . V_40 +=
V_6 -> V_7 -> V_29 . V_39 . V_40 ;
if ( ! V_24 -> V_74 )
V_24 -> V_74 = V_6 -> V_7 -> V_74 ;
}
}
static int F_57 ( const struct V_1 * V_2 , struct V_15 * V_16 )
{
F_43 ( V_2 , V_16 ) ;
return 0 ;
}
static int F_58 ( const struct V_1 * V_2 , struct V_15 * V_16 )
{
F_59 ( V_2 , V_16 ) ;
return 0 ;
}
static void F_60 ( const struct V_1 * V_2 , const struct V_98 * V_99 )
{
int V_66 ;
V_66 = F_49 ( V_2 , F_33 ( V_2 , V_99 ) , F_54 ) ;
F_14 ( V_66 == 0 ) ;
}
static void F_61 ( const struct V_1 * V_2 ,
const struct V_98 * V_99 )
{
struct V_3 * V_4 = F_33 ( V_2 , V_99 ) ;
int V_66 ;
V_66 = F_49 ( V_2 , V_4 , F_57 ) ;
F_14 ( V_66 == 0 ) ;
while ( ! F_62 ( & V_4 -> V_109 ) )
F_63 ( V_4 -> V_109 . V_110 ) ;
}
static void F_64 ( const struct V_1 * V_2 ,
const struct V_98 * V_99 )
{
int V_66 ;
V_66 = F_49 ( V_2 , F_33 ( V_2 , V_99 ) , F_58 ) ;
F_14 ( V_66 == 0 ) ;
}
static int F_65 ( const struct V_1 * V_2 ,
const struct V_98 * V_99 ,
T_2 V_18 , struct V_119 * V_120 )
{
struct V_3 * V_4 = F_33 ( V_2 , V_99 ) ;
struct V_63 * V_121 = V_4 -> V_22 ;
struct V_43 * V_44 = F_66 ( V_121 ) ;
struct V_122 * V_123 = F_16 ( V_121 ) ;
unsigned int V_124 ;
struct V_5 * V_6 ;
T_2 V_125 ;
T_1 V_126 ;
int V_17 ;
int V_66 ;
V_17 = F_67 ( V_121 -> V_23 , F_9 ( V_44 , V_18 ) ) ;
if ( F_15 ( ! V_123 -> V_68 [ V_17 ] ) )
return - V_69 ;
V_6 = F_23 ( V_2 , V_4 , V_17 ) ;
if ( F_18 ( V_6 ) )
return F_19 ( V_6 ) ;
F_68 ( V_121 -> V_23 , F_9 ( V_44 , V_18 ) , V_17 , & V_126 ) ;
V_66 = F_69 ( V_6 -> V_9 , V_6 -> V_7 ,
F_10 ( F_21 ( V_123 -> V_68 [ V_17 ] ) , V_126 ) ,
V_120 ) ;
F_44 ( V_127 , V_128 L_3 ,
F_70 ( F_71 ( F_72 ( V_121 ) ) ) , V_120 -> V_129 , V_123 -> V_130 , V_66 ) ;
if ( V_66 )
return V_66 ;
if ( V_123 -> V_130 == 1 )
return 0 ;
V_125 = V_120 -> V_129 ;
if ( V_125 != V_131 )
V_125 = F_73 ( V_121 -> V_23 , V_125 , V_17 ) ;
V_124 = V_121 -> V_23 -> V_112 >> V_132 ;
F_44 ( V_127 , V_128 L_4 ,
F_70 ( F_71 ( F_72 ( V_121 ) ) ) , V_125 , V_124 ,
V_121 -> V_23 -> V_112 , V_17 , V_18 ) ;
V_120 -> V_129 = F_48 ( T_2 , V_125 , V_18 + V_124 - V_18 % V_124 - 1 ) ;
return 0 ;
}
static int F_74 ( const struct V_1 * V_2 ,
const struct V_98 * V_99 ,
enum V_133 V_134 , struct V_135 * V_136 )
{
struct V_137 * V_138 = & V_136 -> V_139 ;
struct V_3 * V_4 = F_33 ( V_2 , V_99 ) ;
struct V_5 * V_6 ;
struct V_137 * V_140 = & F_75 ( V_2 ) -> V_141 ;
struct V_80 * V_81 ;
int V_17 ;
int V_66 = 0 ;
if ( V_4 -> V_10 == 1 ) {
int V_142 = V_4 -> V_12 ;
F_14 ( V_142 < V_4 -> V_89 ) ;
V_6 = F_23 ( V_2 , V_4 , V_142 ) ;
F_14 ( ! F_18 ( V_6 ) ) ;
F_14 ( V_6 -> V_7 == & V_4 -> V_71 ) ;
V_66 = F_76 ( V_6 -> V_9 , V_6 -> V_7 ,
V_134 , V_136 ) ;
return V_66 ;
}
F_14 ( V_4 -> V_79 ) ;
F_77 ( V_140 ) ;
while ( V_138 -> V_143 > 0 ) {
struct V_135 * V_144 = & F_75 ( V_2 ) -> V_145 ;
F_78 ( V_144 ) ;
V_81 = F_79 ( V_138 ) ;
F_80 ( & V_144 -> V_139 , V_138 , V_81 ) ;
V_17 = F_25 ( V_81 ) ;
while ( V_138 -> V_143 > 0 ) {
V_81 = F_79 ( V_138 ) ;
if ( V_17 != F_25 ( V_81 ) )
break;
F_80 ( & V_144 -> V_139 , V_138 , V_81 ) ;
}
V_6 = F_23 ( V_2 , V_4 , V_17 ) ;
if ( ! F_18 ( V_6 ) ) {
V_66 = F_76 ( V_6 -> V_9 , V_6 -> V_7 ,
V_134 , V_144 ) ;
} else {
V_66 = F_19 ( V_6 ) ;
}
F_81 ( & V_144 -> V_139 , V_140 ) ;
F_81 ( & V_144 -> V_146 , & V_136 -> V_146 ) ;
F_82 ( V_2 , V_144 ) ;
if ( V_66 != 0 )
break;
}
F_81 ( V_140 , V_138 ) ;
F_83 ( V_2 , V_140 ) ;
return V_66 ;
}
static int F_84 ( const struct V_1 * V_2 ,
const struct V_98 * V_99 ,
struct V_137 * V_136 , int V_147 , int V_148 ,
T_5 V_149 )
{
struct V_137 * V_140 = & F_75 ( V_2 ) -> V_141 ;
struct V_3 * V_4 = F_33 ( V_2 , V_99 ) ;
struct V_5 * V_6 ;
struct V_80 * V_81 ;
int V_66 = 0 ;
if ( V_4 -> V_10 == 1 ) {
int V_142 = V_4 -> V_12 ;
F_14 ( V_142 < V_4 -> V_89 ) ;
V_6 = F_23 ( V_2 , V_4 , V_142 ) ;
F_14 ( ! F_18 ( V_6 ) ) ;
F_14 ( V_6 -> V_7 == & V_4 -> V_71 ) ;
V_66 = F_85 ( V_6 -> V_9 , V_6 -> V_7 , V_136 ,
V_147 , V_148 , V_149 ) ;
return V_66 ;
}
F_14 ( V_4 -> V_79 ) ;
F_77 ( V_140 ) ;
while ( V_136 -> V_143 > 0 ) {
int V_150 = V_148 ;
int V_17 ;
F_14 ( V_140 -> V_143 == 0 ) ;
V_81 = F_79 ( V_136 ) ;
F_80 ( V_140 , V_136 , V_81 ) ;
V_17 = F_25 ( V_81 ) ;
while ( V_136 -> V_143 > 0 ) {
V_81 = F_79 ( V_136 ) ;
if ( V_17 != F_25 ( V_81 ) )
break;
F_80 ( V_140 , V_136 , V_81 ) ;
}
if ( V_136 -> V_143 > 0 )
V_150 = V_151 ;
V_6 = F_23 ( V_2 , V_4 , V_17 ) ;
if ( ! F_18 ( V_6 ) ) {
V_66 = F_85 ( V_6 -> V_9 , V_6 -> V_7 ,
V_140 , V_147 , V_150 , V_149 ) ;
} else {
V_66 = F_19 ( V_6 ) ;
break;
}
if ( V_140 -> V_143 > 0 )
break;
V_147 = 0 ;
}
F_14 ( F_86 ( V_66 == 0 , V_140 -> V_143 == 0 ) ) ;
while ( V_140 -> V_143 > 0 ) {
V_81 = F_87 ( V_140 ) ;
F_88 ( V_136 , V_140 , V_81 ) ;
}
return V_66 ;
}
static int F_89 ( const struct V_1 * V_2 ,
const struct V_98 * V_99 )
{
struct V_152 * V_153 ;
struct V_3 * V_4 ;
struct V_5 * V_6 ;
V_153 = & V_99 -> V_26 -> V_29 . V_47 ;
V_4 = F_33 ( V_2 , V_99 ) ;
V_6 = F_23 ( V_2 , V_4 , F_25 ( V_153 -> V_154 ) ) ;
if ( F_18 ( V_6 ) )
return F_19 ( V_6 ) ;
V_6 -> V_7 -> V_29 . V_47 . V_155 = V_153 -> V_155 ;
return F_53 ( V_2 , V_99 ) ;
}
static void F_90 ( const struct V_1 * V_2 ,
const struct V_98 * V_99 )
{
struct V_3 * V_4 = F_33 ( V_2 , V_99 ) ;
struct V_5 * V_6 ;
unsigned int * V_156 = & V_99 -> V_26 -> V_29 . V_50 . V_157 ;
* V_156 = 0 ;
F_51 (sub, &lio->lis_active, sub_linkage) {
struct V_15 * V_158 = V_6 -> V_7 ;
F_54 ( V_6 -> V_9 , V_158 ) ;
if ( V_158 -> V_74 == 0 )
* V_156 += V_158 -> V_29 . V_50 . V_157 ;
}
}
static void F_91 ( const struct V_1 * V_2 ,
const struct V_98 * V_99 )
{
struct V_63 * V_64 = F_34 ( V_99 -> V_100 ) ;
if ( F_37 ( & V_64 -> V_102 ) )
F_38 ( & V_64 -> V_103 ) ;
}
static int F_92 ( const struct V_1 * V_2 ,
const struct V_98 * V_99 ,
enum V_133 V_134 , struct V_135 * V_136 )
{
return - V_159 ;
}
static void F_93 ( const struct V_1 * V_2 ,
struct V_98 * V_99 )
{
F_31 () ;
}
int F_94 ( const struct V_1 * V_2 , struct V_43 * V_44 ,
struct V_15 * V_16 )
{
struct V_3 * V_4 = F_95 ( V_2 ) ;
struct V_63 * V_64 = F_34 ( V_44 ) ;
F_96 ( & V_4 -> V_109 ) ;
V_16 -> V_74 = F_30 ( V_4 , V_64 , V_16 ) ;
if ( V_16 -> V_74 == 0 ) {
V_16 -> V_74 = F_28 ( V_2 , V_4 , V_16 ) ;
if ( V_16 -> V_74 == 0 ) {
F_97 ( V_16 , & V_4 -> V_25 , V_44 , & V_160 ) ;
F_98 ( & V_64 -> V_102 ) ;
}
}
return V_16 -> V_74 ;
}
int F_99 ( const struct V_1 * V_2 , struct V_43 * V_44 ,
struct V_15 * V_16 )
{
struct V_63 * V_64 = F_34 ( V_44 ) ;
struct V_3 * V_4 = F_95 ( V_2 ) ;
int V_87 ;
V_4 -> V_22 = V_64 ;
switch ( V_16 -> V_27 ) {
default:
F_31 () ;
case V_97 :
case V_55 :
V_87 = 0 ;
break;
case V_49 :
case V_28 :
case V_38 :
V_87 = 1 ;
break;
case V_56 :
V_87 = - V_159 ;
break;
case V_42 :
V_87 = - V_161 ;
F_100 ( L_5 V_128 L_6 ,
F_70 ( F_71 ( & V_44 -> V_162 ) ) ) ;
break;
}
if ( V_87 == 0 ) {
F_97 ( V_16 , & V_4 -> V_25 , V_44 , & V_163 ) ;
F_98 ( & V_64 -> V_102 ) ;
}
V_16 -> V_74 = V_87 < 0 ? V_87 : 0 ;
return V_87 ;
}
int F_101 ( const struct V_1 * V_2 , struct V_43 * V_44 ,
struct V_15 * V_16 )
{
struct V_63 * V_64 = F_34 ( V_44 ) ;
struct V_3 * V_4 = F_95 ( V_2 ) ;
int V_87 ;
F_14 ( V_64 -> V_23 ) ;
V_4 -> V_22 = V_64 ;
switch ( V_16 -> V_27 ) {
default:
F_102 ( 0 , L_7 , V_16 -> V_27 ) ;
V_87 = - V_164 ;
break;
case V_97 :
case V_49 :
case V_38 :
V_87 = 1 ;
break;
case V_28 :
if ( F_7 ( V_16 ) ) {
V_16 -> V_165 = 1 ;
V_87 = - V_166 ;
} else {
V_87 = 1 ;
}
break;
case V_55 :
case V_56 :
case V_42 :
V_16 -> V_165 = 1 ;
V_87 = - V_166 ;
break;
}
if ( V_87 == 0 ) {
F_97 ( V_16 , & V_4 -> V_25 , V_44 , & V_163 ) ;
F_98 ( & V_64 -> V_102 ) ;
}
V_16 -> V_74 = V_87 < 0 ? V_87 : 0 ;
return V_87 ;
}
