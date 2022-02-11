static int
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
V_4 -> V_5 = V_6 ;
V_4 -> V_7 = V_8 ;
V_4 -> V_9 = V_10 ;
V_4 -> V_5 |= V_11 ;
V_4 -> V_7 |= V_12 ;
V_4 -> V_13 = V_14 ;
V_4 -> V_15 = 0 ;
if ( F_2 ( V_2 ) ) {
F_3 ( V_4 , V_16 ) ;
V_4 -> V_17 = V_18 ;
} else {
F_3 ( V_4 , V_19 ) ;
V_4 -> V_17 = V_20 ;
}
V_4 -> V_21 = V_22 ;
V_4 -> V_23 = 0 ;
V_4 -> V_24 = 0 ;
return 0 ;
}
static int
F_4 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( V_4 -> V_9 == V_25 )
return - V_26 ; else {
if ( ( F_5 ( V_4 ) == V_16 )
&& ( V_4 -> V_17 == V_18 ) )
return 0 ;
}
return - V_26 ;
}
static void
F_6 ( struct V_1 * V_2 , struct V_27 * V_28 )
{
struct V_29 * V_29 = F_7 ( V_2 ) ;
struct V_30 * V_31 ;
unsigned long V_32 ;
F_8 ( V_28 -> V_33 , V_34 , sizeof( V_28 -> V_33 ) ) ;
F_8 ( V_28 -> V_35 , V_36 , sizeof( V_28 -> V_35 ) ) ;
V_31 = F_9 ( sizeof( * V_31 ) , V_37 ) ;
if ( V_31 ) {
F_10 ( & V_29 -> V_38 , V_32 ) ;
F_11 ( & V_29 -> V_39 . V_40 . V_41 , V_31 ) ;
F_12 ( & V_29 -> V_38 , V_32 ) ;
F_8 ( V_28 -> V_42 , V_31 -> V_43 . V_44 ,
sizeof( V_28 -> V_42 ) ) ;
F_13 ( V_31 ) ;
}
F_8 ( V_28 -> V_45 , F_14 ( V_29 -> V_46 ) ,
sizeof( V_28 -> V_45 ) ) ;
}
static void
F_15 ( struct V_1 * V_2 , struct V_47 * V_48 )
{
V_48 -> V_5 = 0 ;
V_48 -> V_49 = 0 ;
}
static int
F_16 ( struct V_1 * V_2 , struct V_50 * V_51 )
{
struct V_29 * V_29 = F_7 ( V_2 ) ;
unsigned long V_32 ;
F_10 ( & V_29 -> V_38 , V_32 ) ;
V_51 -> V_52 =
( V_29 -> V_53 & V_54 ) ? true : false ;
F_12 ( & V_29 -> V_38 , V_32 ) ;
V_51 -> V_55 = V_29 -> V_56 *
V_57 ;
V_51 -> V_58 = V_29 -> V_59 *
V_57 ;
V_51 -> V_60 = V_61 ;
return 0 ;
}
static int
F_17 ( struct V_1 * V_2 , struct V_50 * V_51 )
{
struct V_29 * V_29 = F_7 ( V_2 ) ;
unsigned long V_32 ;
int V_62 = 0 ;
if ( V_51 -> V_55 == 0 ||
V_51 -> V_55 >
V_63 * V_57 )
return - V_64 ;
if ( V_51 -> V_58 == 0 ||
V_51 -> V_58 >
V_63 * V_57 )
return - V_64 ;
F_18 ( & V_29 -> V_65 ) ;
F_10 ( & V_29 -> V_38 , V_32 ) ;
if ( V_51 -> V_52 ) {
if ( ! ( V_29 -> V_53 & V_54 ) ) {
V_29 -> V_53 |= V_54 ;
F_19 ( V_29 ) ;
}
} else {
if ( V_29 -> V_53 & V_54 ) {
V_29 -> V_53 &= ~ V_54 ;
if ( V_29 -> V_53 & V_54 &&
F_20 ( V_66 ,
& V_29 -> V_67 ) ) {
F_21 ( V_66 ,
& V_29 -> V_67 ) ;
V_62 = 1 ;
}
F_12 ( & V_29 -> V_38 , V_32 ) ;
if ( V_62 )
F_22 ( & V_29 -> V_68 ) ;
F_10 ( & V_29 -> V_38 , V_32 ) ;
F_23 ( V_29 ) ;
}
}
if ( V_29 -> V_59 != V_51 -> V_58 /
V_57 ) {
V_29 -> V_59 = V_51 -> V_58 /
V_57 ;
F_24 ( V_29 ) ;
}
if ( V_29 -> V_56 != V_51 -> V_55 /
V_57 ) {
V_29 -> V_56 = V_51 -> V_55 /
V_57 ;
if ( ! ( V_29 -> V_53 & V_54 ) )
F_23 ( V_29 ) ;
}
F_12 ( & V_29 -> V_38 , V_32 ) ;
F_25 ( & V_29 -> V_65 ) ;
return 0 ;
}
static void
F_26 ( struct V_1 * V_2 ,
struct V_69 * V_70 )
{
struct V_29 * V_29 = F_7 ( V_2 ) ;
V_70 -> V_71 = V_72 ;
V_70 -> V_73 = V_74 ;
V_70 -> V_75 = V_29 -> V_76 ;
V_70 -> V_77 = V_29 -> V_78 ;
}
static int
F_27 ( struct V_1 * V_2 ,
struct V_69 * V_70 )
{
int V_79 , V_80 , V_81 = 0 ;
struct V_29 * V_29 = F_7 ( V_2 ) ;
unsigned long V_32 ;
F_18 ( & V_29 -> V_65 ) ;
if ( V_70 -> V_75 == V_29 -> V_76 &&
V_70 -> V_77 == V_29 -> V_78 ) {
F_25 ( & V_29 -> V_65 ) ;
return 0 ;
}
if ( V_70 -> V_75 < V_82 ||
V_70 -> V_75 > V_72 ||
! F_28 ( V_70 -> V_75 ) ) {
F_25 ( & V_29 -> V_65 ) ;
return - V_64 ;
}
if ( V_70 -> V_77 < V_82 ||
V_70 -> V_77 > V_74 ||
! F_28 ( V_70 -> V_77 ) ) {
F_25 ( & V_29 -> V_65 ) ;
return - V_64 ;
}
if ( V_70 -> V_75 != V_29 -> V_76 ) {
V_29 -> V_76 = V_70 -> V_75 ;
if ( ! F_29 ( V_2 ) ) {
F_25 ( & V_29 -> V_65 ) ;
return 0 ;
}
for ( V_79 = 0 ; V_79 < V_29 -> V_83 ; V_79 ++ ) {
if ( ! V_29 -> V_84 [ V_79 ] . V_85 )
continue;
F_30 ( V_29 , V_79 ) ;
V_80 = F_31 ( V_29 , V_79 ) ;
if ( V_80 && ! V_81 )
V_81 = V_80 ;
}
if ( ! V_81 && V_29 -> V_84 [ 0 ] . V_85 ) {
F_32 ( V_29 , 0 ) ;
F_33 ( V_29 ) ;
F_10 ( & V_29 -> V_38 , V_32 ) ;
F_34 ( V_29 , V_2 -> V_86 ) ;
F_12 ( & V_29 -> V_38 , V_32 ) ;
V_29 -> V_53 &= ~ ( V_87 |
V_88 ) ;
F_35 ( V_2 ) ;
}
}
if ( V_70 -> V_77 != V_29 -> V_78 ) {
V_29 -> V_78 = V_70 -> V_77 ;
if ( ! F_29 ( V_2 ) ) {
F_25 ( & V_29 -> V_65 ) ;
return 0 ;
}
for ( V_79 = 0 ; V_79 < V_29 -> V_89 ; V_79 ++ ) {
if ( ! V_29 -> V_90 [ V_79 ] . V_91 )
continue;
F_36 ( V_29 , V_79 ) ;
V_80 = F_37 ( V_29 , V_79 ) ;
if ( V_80 && ! V_81 )
V_81 = V_80 ;
}
}
F_25 ( & V_29 -> V_65 ) ;
return V_81 ;
}
static void
F_38 ( struct V_1 * V_2 ,
struct V_92 * V_93 )
{
struct V_29 * V_29 = F_7 ( V_2 ) ;
V_93 -> V_9 = 0 ;
V_93 -> V_94 = V_29 -> V_39 . V_95 . V_96 . V_94 ;
V_93 -> V_97 = V_29 -> V_39 . V_95 . V_96 . V_97 ;
}
static int
F_39 ( struct V_1 * V_2 ,
struct V_92 * V_93 )
{
struct V_29 * V_29 = F_7 ( V_2 ) ;
struct V_98 V_96 ;
unsigned long V_32 ;
if ( V_93 -> V_9 == V_25 )
return - V_64 ;
F_18 ( & V_29 -> V_65 ) ;
if ( V_93 -> V_94 != V_29 -> V_39 . V_95 . V_96 . V_94 ||
V_93 -> V_97 != V_29 -> V_39 . V_95 . V_96 . V_97 ) {
V_96 . V_94 = V_93 -> V_94 ;
V_96 . V_97 = V_93 -> V_97 ;
F_10 ( & V_29 -> V_38 , V_32 ) ;
F_40 ( & V_29 -> V_39 . V_95 , & V_96 ) ;
F_12 ( & V_29 -> V_38 , V_32 ) ;
}
F_25 ( & V_29 -> V_65 ) ;
return 0 ;
}
static void
F_41 ( struct V_1 * V_2 , T_1 V_99 , T_2 * string )
{
struct V_29 * V_29 = F_7 ( V_2 ) ;
int V_79 , V_100 , V_101 ;
T_1 V_102 ;
F_18 ( & V_29 -> V_65 ) ;
switch ( V_99 ) {
case V_103 :
for ( V_79 = 0 ; V_79 < V_104 ; V_79 ++ ) {
F_42 ( ! ( strlen ( V_105 [ V_79 ] ) <
V_106 ) ) ;
memcpy ( string , V_105 [ V_79 ] ,
V_106 ) ;
string += V_106 ;
}
V_102 = F_43 ( & V_29 -> V_39 ) ;
for ( V_79 = 0 ; V_102 ; V_79 ++ ) {
if ( V_102 & 1 ) {
sprintf ( string , L_1 , V_79 ) ;
string += V_106 ;
sprintf ( string , L_2 , V_79 ) ;
string += V_106 ;
sprintf ( string , L_3 , V_79 ) ;
string += V_106 ;
sprintf ( string , L_4 , V_79 ) ;
string += V_106 ;
sprintf ( string , L_5 , V_79 ) ;
string += V_106 ;
sprintf ( string , L_6 , V_79 ) ;
string += V_106 ;
sprintf ( string , L_7 , V_79 ) ;
string += V_106 ;
sprintf ( string , L_8 , V_79 ) ;
string += V_106 ;
sprintf ( string , L_9 , V_79 ) ;
string += V_106 ;
sprintf ( string , L_10 , V_79 ) ;
string += V_106 ;
sprintf ( string , L_11 , V_79 ) ;
string += V_106 ;
sprintf ( string , L_12 , V_79 ) ;
string += V_106 ;
}
V_102 >>= 1 ;
}
V_102 = F_44 ( & V_29 -> V_39 ) ;
for ( V_79 = 0 ; V_102 ; V_79 ++ ) {
if ( V_102 & 1 ) {
sprintf ( string , L_13 , V_79 ) ;
string += V_106 ;
sprintf ( string , L_14 , V_79 ) ;
string += V_106 ;
sprintf ( string , L_15 , V_79 ) ;
string += V_106 ;
sprintf ( string , L_16 , V_79 ) ;
string += V_106 ;
sprintf ( string , L_17 , V_79 ) ;
string += V_106 ;
sprintf ( string , L_18 , V_79 ) ;
string += V_106 ;
sprintf ( string , L_19 , V_79 ) ;
string += V_106 ;
sprintf ( string , L_20 , V_79 ) ;
string += V_106 ;
sprintf ( string , L_21 , V_79 ) ;
string += V_106 ;
sprintf ( string , L_22 , V_79 ) ;
string += V_106 ;
}
V_102 >>= 1 ;
}
V_101 = 0 ;
for ( V_79 = 0 ; V_79 < V_29 -> V_83 ; V_79 ++ ) {
if ( ! V_29 -> V_84 [ V_79 ] . V_85 )
continue;
for ( V_100 = 0 ; V_100 < V_29 -> V_107 ; V_100 ++ ) {
sprintf ( string , L_23 , V_101 ) ;
string += V_106 ;
sprintf ( string , L_24 , V_101 ) ;
string += V_106 ;
sprintf ( string , L_25 ,
V_101 ) ;
string += V_106 ;
sprintf ( string , L_26 , V_101 ) ;
string += V_106 ;
sprintf ( string , L_27 , V_101 ) ;
string += V_106 ;
sprintf ( string , L_28 , V_101 ) ;
string += V_106 ;
sprintf ( string , L_29 , V_101 ) ;
string += V_106 ;
sprintf ( string , L_30 , V_101 ) ;
string += V_106 ;
V_101 ++ ;
}
}
V_101 = 0 ;
for ( V_79 = 0 ; V_79 < V_29 -> V_83 ; V_79 ++ ) {
if ( ! V_29 -> V_84 [ V_79 ] . V_85 )
continue;
for ( V_100 = 0 ; V_100 < V_29 -> V_107 ; V_100 ++ ) {
sprintf ( string , L_31 , V_101 ) ;
string += V_106 ;
sprintf ( string , L_32 , V_101 ) ;
string += V_106 ;
sprintf ( string , L_33 ,
V_101 ) ;
string += V_106 ;
sprintf ( string , L_34 , V_101 ) ;
string += V_106 ;
sprintf ( string , L_35 , V_101 ) ;
string += V_106 ;
sprintf ( string , L_36 , V_101 ) ;
string += V_106 ;
V_101 ++ ;
if ( V_29 -> V_84 [ V_79 ] . V_108 [ V_100 ] . V_109 &&
V_29 -> V_84 [ V_79 ] . V_108 [ V_100 ] . V_109 ->
V_110 [ 1 ] &&
V_29 -> V_84 [ V_79 ] . V_108 [ V_100 ] . V_109 ->
V_110 [ 1 ] -> V_111 ) {
sprintf ( string , L_31 , V_101 ) ;
string += V_106 ;
sprintf ( string , L_32 , V_101 ) ;
string += V_106 ;
sprintf ( string ,
L_33 , V_101 ) ;
string += V_106 ;
sprintf ( string , L_34 ,
V_101 ) ;
string += V_106 ;
sprintf ( string , L_35 ,
V_101 ) ;
string += V_106 ;
sprintf ( string , L_36 ,
V_101 ) ;
string += V_106 ;
V_101 ++ ;
}
}
}
V_101 = 0 ;
for ( V_79 = 0 ; V_79 < V_29 -> V_89 ; V_79 ++ ) {
if ( ! V_29 -> V_90 [ V_79 ] . V_91 )
continue;
for ( V_100 = 0 ; V_100 < V_29 -> V_112 ; V_100 ++ ) {
sprintf ( string , L_37 , V_101 ) ;
string += V_106 ;
sprintf ( string , L_38 , V_101 ) ;
string += V_106 ;
sprintf ( string , L_39 , V_101 ) ;
string += V_106 ;
sprintf ( string , L_40 , V_101 ) ;
string += V_106 ;
sprintf ( string , L_41 ,
V_101 ) ;
string += V_106 ;
V_101 ++ ;
}
}
break;
default:
break;
}
F_25 ( & V_29 -> V_65 ) ;
}
static int
F_45 ( struct V_1 * V_2 )
{
struct V_29 * V_29 = F_7 ( V_2 ) ;
int V_79 , V_100 , V_113 = 0 , V_114 = 0 , V_115 = 0 ;
T_1 V_102 ;
V_102 = F_43 ( & V_29 -> V_39 ) ;
for ( V_79 = 0 ; V_102 ; V_79 ++ ) {
if ( V_102 & 1 )
V_115 ++ ;
V_102 >>= 1 ;
}
V_102 = F_44 ( & V_29 -> V_39 ) ;
for ( V_79 = 0 ; V_102 ; V_79 ++ ) {
if ( V_102 & 1 )
V_114 ++ ;
V_102 >>= 1 ;
}
V_113 = V_104 +
V_115 * V_116 +
V_114 * V_117 ;
for ( V_79 = 0 ; V_79 < V_29 -> V_83 ; V_79 ++ ) {
if ( ! V_29 -> V_84 [ V_79 ] . V_85 )
continue;
V_113 += V_29 -> V_107 * V_118 ;
V_113 += V_29 -> V_107 * V_119 ;
for ( V_100 = 0 ; V_100 < V_29 -> V_107 ; V_100 ++ )
if ( V_29 -> V_84 [ V_79 ] . V_108 [ V_100 ] . V_109 &&
V_29 -> V_84 [ V_79 ] . V_108 [ V_100 ] . V_109 -> V_110 [ 1 ] &&
V_29 -> V_84 [ V_79 ] . V_108 [ V_100 ] . V_109 -> V_110 [ 1 ] -> V_111 )
V_113 += V_119 ;
}
for ( V_79 = 0 ; V_79 < V_29 -> V_89 ; V_79 ++ ) {
if ( ! V_29 -> V_90 [ V_79 ] . V_91 )
continue;
V_113 += V_29 -> V_112 * V_120 ;
}
return V_113 ;
}
static int
F_46 ( struct V_29 * V_29 , T_3 * V_121 , int V_122 )
{
int V_79 , V_100 ;
struct V_123 * V_110 = NULL ;
struct V_124 * V_125 = NULL ;
for ( V_79 = 0 ; V_79 < V_29 -> V_83 ; V_79 ++ ) {
if ( ! V_29 -> V_84 [ V_79 ] . V_85 )
continue;
for ( V_100 = 0 ; V_100 < V_29 -> V_107 ; V_100 ++ )
if ( V_29 -> V_84 [ V_79 ] . V_108 [ V_100 ] . V_109 &&
V_29 -> V_84 [ V_79 ] . V_108 [ V_100 ] . V_109 -> V_110 [ 0 ] &&
V_29 -> V_84 [ V_79 ] . V_108 [ V_100 ] . V_109 -> V_110 [ 0 ] -> V_111 ) {
V_121 [ V_122 ++ ] = V_29 -> V_84 [ V_79 ] . V_108 [ V_100 ] .
V_109 -> V_126 ;
V_121 [ V_122 ++ ] = 0 ;
V_121 [ V_122 ++ ] = * ( V_29 -> V_84 [ V_79 ] . V_108 [ V_100 ] .
V_109 -> V_127 ) ;
V_121 [ V_122 ++ ] = V_29 -> V_84 [ V_79 ] .
V_108 [ V_100 ] . V_128 ;
V_121 [ V_122 ++ ] = V_29 -> V_84 [ V_79 ] .
V_108 [ V_100 ] . V_129 ;
V_121 [ V_122 ++ ] = V_29 -> V_84 [ V_79 ] .
V_108 [ V_100 ] . V_130 ;
V_121 [ V_122 ++ ] = V_29 -> V_84 [ V_79 ] .
V_108 [ V_100 ] . V_131 ;
V_121 [ V_122 ++ ] = V_29 -> V_84 [ V_79 ] .
V_108 [ V_100 ] . V_132 ;
}
}
for ( V_79 = 0 ; V_79 < V_29 -> V_83 ; V_79 ++ ) {
if ( ! V_29 -> V_84 [ V_79 ] . V_85 )
continue;
for ( V_100 = 0 ; V_100 < V_29 -> V_107 ; V_100 ++ )
if ( V_29 -> V_84 [ V_79 ] . V_108 [ V_100 ] . V_109 ) {
if ( V_29 -> V_84 [ V_79 ] . V_108 [ V_100 ] . V_109 -> V_110 [ 0 ] &&
V_29 -> V_84 [ V_79 ] . V_108 [ V_100 ] . V_109 ->
V_110 [ 0 ] -> V_111 ) {
V_110 = V_29 -> V_84 [ V_79 ] . V_108 [ V_100 ] .
V_109 -> V_110 [ 0 ] ;
V_121 [ V_122 ++ ] = V_110 -> V_111 -> V_133 ;
V_121 [ V_122 ++ ] = V_110 -> V_111 -> V_134 ;
V_121 [ V_122 ++ ] = V_110 -> V_111 ->
V_135 ;
V_121 [ V_122 ++ ] = V_110 -> V_111 ->
V_136 ;
V_121 [ V_122 ++ ] = V_110 -> V_111 -> V_137 ;
V_121 [ V_122 ++ ] = V_110 -> V_126 ;
V_121 [ V_122 ++ ] = V_110 -> V_138 ;
}
if ( V_29 -> V_84 [ V_79 ] . V_108 [ V_100 ] . V_109 -> V_110 [ 1 ] &&
V_29 -> V_84 [ V_79 ] . V_108 [ V_100 ] . V_109 ->
V_110 [ 1 ] -> V_111 ) {
V_110 = V_29 -> V_84 [ V_79 ] . V_108 [ V_100 ] .
V_109 -> V_110 [ 1 ] ;
V_121 [ V_122 ++ ] = V_110 -> V_111 -> V_133 ;
V_121 [ V_122 ++ ] = V_110 -> V_111 -> V_134 ;
V_121 [ V_122 ++ ] = V_110 -> V_111 ->
V_135 ;
V_121 [ V_122 ++ ] = V_110 -> V_111 ->
V_136 ;
V_121 [ V_122 ++ ] = V_110 -> V_111 -> V_137 ;
V_121 [ V_122 ++ ] = V_110 -> V_126 ;
V_121 [ V_122 ++ ] = V_110 -> V_138 ;
}
}
}
for ( V_79 = 0 ; V_79 < V_29 -> V_89 ; V_79 ++ ) {
if ( ! V_29 -> V_90 [ V_79 ] . V_91 )
continue;
for ( V_100 = 0 ; V_100 < V_29 -> V_112 ; V_100 ++ )
if ( V_29 -> V_90 [ V_79 ] . V_125 [ V_100 ] &&
V_29 -> V_90 [ V_79 ] . V_125 [ V_100 ] -> V_139 ) {
V_125 = V_29 -> V_90 [ V_79 ] . V_125 [ V_100 ] ;
V_121 [ V_122 ++ ] = V_125 -> V_139 -> V_140 ;
V_121 [ V_122 ++ ] = V_125 -> V_139 -> V_141 ;
V_121 [ V_122 ++ ] = V_125 -> V_126 ;
V_121 [ V_122 ++ ] = V_125 -> V_138 ;
V_121 [ V_122 ++ ] = * ( V_125 -> V_142 ) ;
}
}
return V_122 ;
}
static void
F_47 ( struct V_1 * V_2 , struct V_143 * V_144 ,
T_3 * V_121 )
{
struct V_29 * V_29 = F_7 ( V_2 ) ;
int V_79 , V_100 , V_122 ;
unsigned long V_32 ;
struct V_145 * V_146 ;
T_3 * V_147 ;
T_1 V_102 ;
F_18 ( & V_29 -> V_65 ) ;
if ( F_45 ( V_2 ) != V_144 -> V_148 ) {
F_25 ( & V_29 -> V_65 ) ;
return;
}
F_10 ( & V_29 -> V_38 , V_32 ) ;
V_122 = 0 ;
memset ( V_121 , 0 , V_144 -> V_148 * sizeof( T_3 ) ) ;
V_146 = (struct V_145 * ) V_121 ;
F_48 ( V_29 , V_146 ) ;
F_49 ( V_29 , V_146 ) ;
V_122 = sizeof( * V_146 ) / sizeof( T_3 ) ;
V_29 -> V_144 . V_149 . V_150 = V_150 ( V_2 ) ;
V_147 = ( T_3 * ) & V_29 -> V_144 . V_149 ;
for ( V_79 = 0 ; V_79 < sizeof( struct V_151 ) / sizeof( T_3 ) ; V_79 ++ )
V_121 [ V_122 ++ ] = V_147 [ V_79 ] ;
V_147 = ( T_3 * ) & V_29 -> V_144 . V_152 -> V_153 ;
for ( V_79 = 0 ;
V_79 < F_50 ( struct V_154 , V_155 [ 0 ] ) /
sizeof( T_3 ) ;
V_79 ++ )
V_121 [ V_122 ++ ] = V_147 [ V_79 ] ;
V_102 = F_43 ( & V_29 -> V_39 ) ;
for ( V_79 = 0 ; V_102 ; V_79 ++ ) {
if ( V_102 & 1 ) {
V_147 = ( T_3 * ) & V_29 -> V_144 . V_152 ->
V_153 . V_156 [ V_79 ] ;
for ( V_100 = 0 ; V_100 < sizeof( struct V_157 ) /
sizeof( T_3 ) ; V_100 ++ )
V_121 [ V_122 ++ ] = V_147 [ V_100 ] ;
}
V_102 >>= 1 ;
}
V_102 = F_44 ( & V_29 -> V_39 ) ;
for ( V_79 = 0 ; V_102 ; V_79 ++ ) {
if ( V_102 & 1 ) {
V_147 = ( T_3 * ) & V_29 -> V_144 . V_152 ->
V_153 . V_155 [ V_79 ] ;
for ( V_100 = 0 ; V_100 < sizeof( struct V_158 ) /
sizeof( T_3 ) ; V_100 ++ )
V_121 [ V_122 ++ ] = V_147 [ V_100 ] ;
}
V_102 >>= 1 ;
}
V_122 = F_46 ( V_29 , V_121 , V_122 ) ;
F_12 ( & V_29 -> V_38 , V_32 ) ;
F_25 ( & V_29 -> V_65 ) ;
}
static int
F_51 ( struct V_1 * V_2 , int V_159 )
{
switch ( V_159 ) {
case V_103 :
return F_45 ( V_2 ) ;
default:
return - V_26 ;
}
}
static T_1
F_52 ( struct V_29 * V_29 , T_1 V_160 ,
T_1 * V_161 )
{
struct V_162 * V_163 ;
struct V_164 V_165 ;
T_1 V_79 , V_166 = 0 , V_167 ;
unsigned long V_32 = 0 ;
V_163 = F_9 ( sizeof( struct V_162 ) , V_37 ) ;
if ( ! V_163 )
return 0 ;
V_165 . V_29 = V_29 ;
V_165 . V_168 = 0 ;
F_53 ( & V_165 . V_169 ) ;
F_10 ( & V_29 -> V_38 , V_32 ) ;
V_167 = F_54 ( & V_29 -> V_39 . V_170 , V_163 ,
V_171 , & V_165 ) ;
if ( V_167 != V_172 ) {
F_12 ( & V_29 -> V_38 , V_32 ) ;
F_13 ( V_163 ) ;
return 0 ;
}
F_12 ( & V_29 -> V_38 , V_32 ) ;
F_55 ( & V_165 . V_169 ) ;
V_167 = V_165 . V_168 ;
if ( V_167 == V_172 ) {
for ( V_79 = 0 ; V_79 < V_163 -> V_173 ; V_79 ++ ) {
if ( V_160 >= V_163 -> V_174 [ V_79 ] . V_175 &&
V_160 < ( V_163 -> V_174 [ V_79 ] . V_175 +
V_163 -> V_174 [ V_79 ] . V_176 ) ) {
V_166 = V_163 -> V_174 [ V_79 ] . V_177 ;
* V_161 = V_163 -> V_174 [ V_79 ] . V_175 ;
break;
}
}
}
F_13 ( V_163 ) ;
return V_166 ;
}
static int
F_56 ( struct V_1 * V_2 )
{
return V_178 ;
}
static int
F_57 ( struct V_1 * V_2 , struct V_179 * V_180 ,
T_2 * V_181 )
{
struct V_29 * V_29 = F_7 ( V_2 ) ;
struct V_164 V_165 ;
T_1 V_166 = 0 , V_161 = 0 ;
unsigned long V_32 = 0 ;
int V_167 = 0 ;
V_180 -> V_182 = V_29 -> V_46 -> V_183 | ( V_29 -> V_46 -> V_184 << 16 ) ;
V_166 = F_52 ( V_29 ,
V_180 -> V_160 , & V_161 ) ;
if ( V_166 == 0 )
return - V_185 ;
V_165 . V_29 = V_29 ;
V_165 . V_168 = 0 ;
F_53 ( & V_165 . V_169 ) ;
F_10 ( & V_29 -> V_38 , V_32 ) ;
V_167 = F_58 ( & V_29 -> V_39 . V_170 , V_166 ,
V_29 -> V_186 , V_181 , V_180 -> V_187 ,
V_180 -> V_160 - V_161 ,
V_171 , & V_165 ) ;
if ( V_167 != V_172 ) {
F_12 ( & V_29 -> V_38 , V_32 ) ;
goto V_188;
}
F_12 ( & V_29 -> V_38 , V_32 ) ;
F_55 ( & V_165 . V_169 ) ;
V_167 = V_165 . V_168 ;
V_188:
return V_167 ;
}
static int
F_59 ( struct V_1 * V_2 , struct V_179 * V_180 ,
T_2 * V_181 )
{
struct V_29 * V_29 = F_7 ( V_2 ) ;
struct V_164 V_165 ;
T_1 V_166 = 0 , V_161 = 0 ;
unsigned long V_32 = 0 ;
int V_167 = 0 ;
if ( V_180 -> V_182 != ( V_29 -> V_46 -> V_183 |
( V_29 -> V_46 -> V_184 << 16 ) ) )
return - V_64 ;
V_166 = F_52 ( V_29 ,
V_180 -> V_160 , & V_161 ) ;
if ( V_166 == 0 )
return - V_185 ;
V_165 . V_29 = V_29 ;
V_165 . V_168 = 0 ;
F_53 ( & V_165 . V_169 ) ;
F_10 ( & V_29 -> V_38 , V_32 ) ;
V_167 = F_60 ( & V_29 -> V_39 . V_170 , V_166 ,
V_29 -> V_186 , V_181 , V_180 -> V_187 ,
V_180 -> V_160 - V_161 ,
V_171 , & V_165 ) ;
if ( V_167 != V_172 ) {
F_12 ( & V_29 -> V_38 , V_32 ) ;
goto V_188;
}
F_12 ( & V_29 -> V_38 , V_32 ) ;
F_55 ( & V_165 . V_169 ) ;
V_167 = V_165 . V_168 ;
V_188:
return V_167 ;
}
static int
F_61 ( struct V_1 * V_2 , struct V_189 * V_190 )
{
struct V_29 * V_29 = F_7 ( V_2 ) ;
struct V_164 V_165 ;
const struct V_191 * V_192 ;
int V_167 = 0 ;
V_167 = F_62 ( & V_192 , V_190 -> V_193 , & V_29 -> V_46 -> V_194 ) ;
if ( V_167 ) {
F_63 ( V_2 , L_42 , V_190 -> V_193 ) ;
goto V_195;
}
V_165 . V_29 = V_29 ;
V_165 . V_168 = 0 ;
F_53 ( & V_165 . V_169 ) ;
F_64 ( & V_29 -> V_38 ) ;
V_167 = F_60 ( & V_29 -> V_39 . V_170 , V_196 ,
V_29 -> V_186 , ( T_2 * ) V_192 -> V_193 , V_192 -> V_197 , 0 ,
V_171 , & V_165 ) ;
if ( V_167 != V_172 ) {
F_65 ( V_2 , L_43 , V_167 ) ;
V_167 = - V_198 ;
F_66 ( & V_29 -> V_38 ) ;
goto V_195;
}
F_66 ( & V_29 -> V_38 ) ;
F_55 ( & V_165 . V_169 ) ;
if ( V_165 . V_168 != V_172 ) {
V_167 = - V_198 ;
F_65 ( V_2 ,
L_44 ,
V_165 . V_168 ) ;
}
V_195:
F_67 ( V_192 ) ;
return V_167 ;
}
void
F_68 ( struct V_1 * V_2 )
{
V_2 -> V_199 = & V_200 ;
}
