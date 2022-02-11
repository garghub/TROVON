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
F_3 ( V_4 , - 1 ) ;
V_4 -> V_17 = - 1 ;
}
V_4 -> V_19 = V_20 ;
V_4 -> V_21 = 0 ;
V_4 -> V_22 = 0 ;
return 0 ;
}
static int
F_4 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( V_4 -> V_9 == V_23 )
return - V_24 ; else {
if ( ( F_5 ( V_4 ) == V_16 )
&& ( V_4 -> V_17 == V_18 ) )
return 0 ;
}
return - V_24 ;
}
static void
F_6 ( struct V_1 * V_2 , struct V_25 * V_26 )
{
struct V_27 * V_27 = F_7 ( V_2 ) ;
struct V_28 * V_29 ;
unsigned long V_30 ;
strcpy ( V_26 -> V_31 , V_32 ) ;
strcpy ( V_26 -> V_33 , V_34 ) ;
V_29 = F_8 ( sizeof( * V_29 ) , V_35 ) ;
if ( V_29 ) {
F_9 ( & V_27 -> V_36 , V_30 ) ;
F_10 ( & V_27 -> V_37 . V_38 . V_39 , V_29 ) ;
F_11 ( & V_27 -> V_36 , V_30 ) ;
strncpy ( V_26 -> V_40 , V_29 -> V_41 . V_42 ,
sizeof( V_26 -> V_40 ) - 1 ) ;
F_12 ( V_29 ) ;
}
strncpy ( V_26 -> V_43 , F_13 ( V_27 -> V_44 ) , V_45 ) ;
}
static void
F_14 ( struct V_1 * V_2 , struct V_46 * V_47 )
{
V_47 -> V_5 = 0 ;
V_47 -> V_48 = 0 ;
}
static int
F_15 ( struct V_1 * V_2 , struct V_49 * V_50 )
{
struct V_27 * V_27 = F_7 ( V_2 ) ;
unsigned long V_30 ;
F_9 ( & V_27 -> V_36 , V_30 ) ;
V_50 -> V_51 =
( V_27 -> V_52 & V_53 ) ? true : false ;
F_11 ( & V_27 -> V_36 , V_30 ) ;
V_50 -> V_54 = V_27 -> V_55 *
V_56 ;
V_50 -> V_57 = V_27 -> V_58 *
V_56 ;
V_50 -> V_59 = V_60 ;
return 0 ;
}
static int
F_16 ( struct V_1 * V_2 , struct V_49 * V_50 )
{
struct V_27 * V_27 = F_7 ( V_2 ) ;
unsigned long V_30 ;
int V_61 = 0 ;
if ( V_50 -> V_54 == 0 ||
V_50 -> V_54 >
V_62 * V_56 )
return - V_63 ;
if ( V_50 -> V_57 == 0 ||
V_50 -> V_57 >
V_62 * V_56 )
return - V_63 ;
F_17 ( & V_27 -> V_64 ) ;
F_9 ( & V_27 -> V_36 , V_30 ) ;
if ( V_50 -> V_51 ) {
if ( ! ( V_27 -> V_52 & V_53 ) ) {
V_27 -> V_52 |= V_53 ;
F_18 ( V_27 ) ;
}
} else {
if ( V_27 -> V_52 & V_53 ) {
V_27 -> V_52 &= ~ V_53 ;
if ( V_27 -> V_52 & V_53 &&
F_19 ( V_65 ,
& V_27 -> V_66 ) ) {
F_20 ( V_65 ,
& V_27 -> V_66 ) ;
V_61 = 1 ;
}
F_11 ( & V_27 -> V_36 , V_30 ) ;
if ( V_61 )
F_21 ( & V_27 -> V_67 ) ;
F_9 ( & V_27 -> V_36 , V_30 ) ;
F_22 ( V_27 ) ;
}
}
if ( V_27 -> V_58 != V_50 -> V_57 /
V_56 ) {
V_27 -> V_58 = V_50 -> V_57 /
V_56 ;
F_23 ( V_27 ) ;
}
if ( V_27 -> V_55 != V_50 -> V_54 /
V_56 ) {
V_27 -> V_55 = V_50 -> V_54 /
V_56 ;
if ( ! ( V_27 -> V_52 & V_53 ) )
F_22 ( V_27 ) ;
}
F_11 ( & V_27 -> V_36 , V_30 ) ;
F_24 ( & V_27 -> V_64 ) ;
return 0 ;
}
static void
F_25 ( struct V_1 * V_2 ,
struct V_68 * V_69 )
{
struct V_27 * V_27 = F_7 ( V_2 ) ;
V_69 -> V_70 = V_71 ;
V_69 -> V_72 = V_73 ;
V_69 -> V_74 = V_27 -> V_75 ;
V_69 -> V_76 = V_27 -> V_77 ;
}
static int
F_26 ( struct V_1 * V_2 ,
struct V_68 * V_69 )
{
int V_78 , V_79 , V_80 = 0 ;
struct V_27 * V_27 = F_7 ( V_2 ) ;
unsigned long V_30 ;
F_17 ( & V_27 -> V_64 ) ;
if ( V_69 -> V_74 == V_27 -> V_75 &&
V_69 -> V_76 == V_27 -> V_77 ) {
F_24 ( & V_27 -> V_64 ) ;
return 0 ;
}
if ( V_69 -> V_74 < V_81 ||
V_69 -> V_74 > V_71 ||
! F_27 ( V_69 -> V_74 ) ) {
F_24 ( & V_27 -> V_64 ) ;
return - V_63 ;
}
if ( V_69 -> V_76 < V_81 ||
V_69 -> V_76 > V_73 ||
! F_27 ( V_69 -> V_76 ) ) {
F_24 ( & V_27 -> V_64 ) ;
return - V_63 ;
}
if ( V_69 -> V_74 != V_27 -> V_75 ) {
V_27 -> V_75 = V_69 -> V_74 ;
if ( ! F_28 ( V_2 ) ) {
F_24 ( & V_27 -> V_64 ) ;
return 0 ;
}
for ( V_78 = 0 ; V_78 < V_27 -> V_82 ; V_78 ++ ) {
if ( ! V_27 -> V_83 [ V_78 ] . V_84 )
continue;
F_29 ( V_27 , V_78 ) ;
V_79 = F_30 ( V_27 , V_78 ) ;
if ( V_79 && ! V_80 )
V_80 = V_79 ;
}
if ( ! V_80 && V_27 -> V_83 [ 0 ] . V_84 ) {
F_31 ( V_27 , 0 ) ;
F_32 ( V_27 ) ;
F_9 ( & V_27 -> V_36 , V_30 ) ;
F_33 ( V_27 , V_2 -> V_85 ) ;
F_11 ( & V_27 -> V_36 , V_30 ) ;
V_27 -> V_52 &= ~ ( V_86 |
V_87 ) ;
F_34 ( V_2 ) ;
}
}
if ( V_69 -> V_76 != V_27 -> V_77 ) {
V_27 -> V_77 = V_69 -> V_76 ;
if ( ! F_28 ( V_2 ) ) {
F_24 ( & V_27 -> V_64 ) ;
return 0 ;
}
for ( V_78 = 0 ; V_78 < V_27 -> V_88 ; V_78 ++ ) {
if ( ! V_27 -> V_89 [ V_78 ] . V_90 )
continue;
F_35 ( V_27 , V_78 ) ;
V_79 = F_36 ( V_27 , V_78 ) ;
if ( V_79 && ! V_80 )
V_80 = V_79 ;
}
}
F_24 ( & V_27 -> V_64 ) ;
return V_80 ;
}
static void
F_37 ( struct V_1 * V_2 ,
struct V_91 * V_92 )
{
struct V_27 * V_27 = F_7 ( V_2 ) ;
V_92 -> V_9 = 0 ;
V_92 -> V_93 = V_27 -> V_37 . V_94 . V_95 . V_93 ;
V_92 -> V_96 = V_27 -> V_37 . V_94 . V_95 . V_96 ;
}
static int
F_38 ( struct V_1 * V_2 ,
struct V_91 * V_92 )
{
struct V_27 * V_27 = F_7 ( V_2 ) ;
struct V_97 V_95 ;
unsigned long V_30 ;
if ( V_92 -> V_9 == V_23 )
return - V_63 ;
F_17 ( & V_27 -> V_64 ) ;
if ( V_92 -> V_93 != V_27 -> V_37 . V_94 . V_95 . V_93 ||
V_92 -> V_96 != V_27 -> V_37 . V_94 . V_95 . V_96 ) {
V_95 . V_93 = V_92 -> V_93 ;
V_95 . V_96 = V_92 -> V_96 ;
F_9 ( & V_27 -> V_36 , V_30 ) ;
F_39 ( & V_27 -> V_37 . V_94 , & V_95 , NULL ) ;
F_11 ( & V_27 -> V_36 , V_30 ) ;
}
F_24 ( & V_27 -> V_64 ) ;
return 0 ;
}
static void
F_40 ( struct V_1 * V_2 , T_1 V_98 , T_2 * string )
{
struct V_27 * V_27 = F_7 ( V_2 ) ;
int V_78 , V_99 , V_100 ;
T_1 V_101 ;
F_17 ( & V_27 -> V_64 ) ;
switch ( V_98 ) {
case V_102 :
for ( V_78 = 0 ; V_78 < V_103 ; V_78 ++ ) {
F_41 ( ! ( strlen ( V_104 [ V_78 ] ) <
V_105 ) ) ;
memcpy ( string , V_104 [ V_78 ] ,
V_105 ) ;
string += V_105 ;
}
V_101 = F_42 ( & V_27 -> V_37 ) ;
for ( V_78 = 0 ; V_101 ; V_78 ++ ) {
if ( V_101 & 1 ) {
sprintf ( string , L_1 , V_78 ) ;
string += V_105 ;
sprintf ( string , L_2 , V_78 ) ;
string += V_105 ;
sprintf ( string , L_3 , V_78 ) ;
string += V_105 ;
sprintf ( string , L_4 , V_78 ) ;
string += V_105 ;
sprintf ( string , L_5 , V_78 ) ;
string += V_105 ;
sprintf ( string , L_6 , V_78 ) ;
string += V_105 ;
sprintf ( string , L_7 , V_78 ) ;
string += V_105 ;
sprintf ( string , L_8 , V_78 ) ;
string += V_105 ;
sprintf ( string , L_9 , V_78 ) ;
string += V_105 ;
sprintf ( string , L_10 , V_78 ) ;
string += V_105 ;
sprintf ( string , L_11 , V_78 ) ;
string += V_105 ;
sprintf ( string , L_12 , V_78 ) ;
string += V_105 ;
}
V_101 >>= 1 ;
}
V_101 = F_43 ( & V_27 -> V_37 ) ;
for ( V_78 = 0 ; V_101 ; V_78 ++ ) {
if ( V_101 & 1 ) {
sprintf ( string , L_13 , V_78 ) ;
string += V_105 ;
sprintf ( string , L_14 , V_78 ) ;
string += V_105 ;
sprintf ( string , L_15 , V_78 ) ;
string += V_105 ;
sprintf ( string , L_16 , V_78 ) ;
string += V_105 ;
sprintf ( string , L_17 , V_78 ) ;
string += V_105 ;
sprintf ( string , L_18 , V_78 ) ;
string += V_105 ;
sprintf ( string , L_19 , V_78 ) ;
string += V_105 ;
sprintf ( string , L_20 , V_78 ) ;
string += V_105 ;
sprintf ( string , L_21 , V_78 ) ;
string += V_105 ;
sprintf ( string , L_22 , V_78 ) ;
string += V_105 ;
}
V_101 >>= 1 ;
}
V_100 = 0 ;
for ( V_78 = 0 ; V_78 < V_27 -> V_82 ; V_78 ++ ) {
if ( ! V_27 -> V_83 [ V_78 ] . V_84 )
continue;
for ( V_99 = 0 ; V_99 < V_27 -> V_106 ; V_99 ++ ) {
sprintf ( string , L_23 , V_100 ) ;
string += V_105 ;
sprintf ( string , L_24 , V_100 ) ;
string += V_105 ;
sprintf ( string , L_25 ,
V_100 ) ;
string += V_105 ;
sprintf ( string , L_26 , V_100 ) ;
string += V_105 ;
sprintf ( string , L_27 , V_100 ) ;
string += V_105 ;
sprintf ( string , L_28 , V_100 ) ;
string += V_105 ;
sprintf ( string , L_29 , V_100 ) ;
string += V_105 ;
sprintf ( string , L_30 , V_100 ) ;
string += V_105 ;
V_100 ++ ;
}
}
V_100 = 0 ;
for ( V_78 = 0 ; V_78 < V_27 -> V_82 ; V_78 ++ ) {
if ( ! V_27 -> V_83 [ V_78 ] . V_84 )
continue;
for ( V_99 = 0 ; V_99 < V_27 -> V_106 ; V_99 ++ ) {
sprintf ( string , L_31 , V_100 ) ;
string += V_105 ;
sprintf ( string , L_32 , V_100 ) ;
string += V_105 ;
sprintf ( string , L_33 ,
V_100 ) ;
string += V_105 ;
sprintf ( string , L_34 , V_100 ) ;
string += V_105 ;
sprintf ( string , L_35 , V_100 ) ;
string += V_105 ;
sprintf ( string , L_36 , V_100 ) ;
string += V_105 ;
V_100 ++ ;
if ( V_27 -> V_83 [ V_78 ] . V_107 [ V_99 ] . V_108 &&
V_27 -> V_83 [ V_78 ] . V_107 [ V_99 ] . V_108 ->
V_109 [ 1 ] &&
V_27 -> V_83 [ V_78 ] . V_107 [ V_99 ] . V_108 ->
V_109 [ 1 ] -> V_110 ) {
sprintf ( string , L_31 , V_100 ) ;
string += V_105 ;
sprintf ( string , L_32 , V_100 ) ;
string += V_105 ;
sprintf ( string ,
L_33 , V_100 ) ;
string += V_105 ;
sprintf ( string , L_34 ,
V_100 ) ;
string += V_105 ;
sprintf ( string , L_35 ,
V_100 ) ;
string += V_105 ;
sprintf ( string , L_36 ,
V_100 ) ;
string += V_105 ;
V_100 ++ ;
}
}
}
V_100 = 0 ;
for ( V_78 = 0 ; V_78 < V_27 -> V_88 ; V_78 ++ ) {
if ( ! V_27 -> V_89 [ V_78 ] . V_90 )
continue;
for ( V_99 = 0 ; V_99 < V_27 -> V_111 ; V_99 ++ ) {
sprintf ( string , L_37 , V_100 ) ;
string += V_105 ;
sprintf ( string , L_38 , V_100 ) ;
string += V_105 ;
sprintf ( string , L_39 , V_100 ) ;
string += V_105 ;
sprintf ( string , L_40 , V_100 ) ;
string += V_105 ;
sprintf ( string , L_41 ,
V_100 ) ;
string += V_105 ;
V_100 ++ ;
}
}
break;
default:
break;
}
F_24 ( & V_27 -> V_64 ) ;
}
static int
F_44 ( struct V_1 * V_2 )
{
struct V_27 * V_27 = F_7 ( V_2 ) ;
int V_78 , V_99 , V_112 = 0 , V_113 = 0 , V_114 = 0 ;
T_1 V_101 ;
V_101 = F_42 ( & V_27 -> V_37 ) ;
for ( V_78 = 0 ; V_101 ; V_78 ++ ) {
if ( V_101 & 1 )
V_114 ++ ;
V_101 >>= 1 ;
}
V_101 = F_43 ( & V_27 -> V_37 ) ;
for ( V_78 = 0 ; V_101 ; V_78 ++ ) {
if ( V_101 & 1 )
V_113 ++ ;
V_101 >>= 1 ;
}
V_112 = V_103 +
V_114 * V_115 +
V_113 * V_116 ;
for ( V_78 = 0 ; V_78 < V_27 -> V_82 ; V_78 ++ ) {
if ( ! V_27 -> V_83 [ V_78 ] . V_84 )
continue;
V_112 += V_27 -> V_106 * V_117 ;
V_112 += V_27 -> V_106 * V_118 ;
for ( V_99 = 0 ; V_99 < V_27 -> V_106 ; V_99 ++ )
if ( V_27 -> V_83 [ V_78 ] . V_107 [ V_99 ] . V_108 &&
V_27 -> V_83 [ V_78 ] . V_107 [ V_99 ] . V_108 -> V_109 [ 1 ] &&
V_27 -> V_83 [ V_78 ] . V_107 [ V_99 ] . V_108 -> V_109 [ 1 ] -> V_110 )
V_112 += V_118 ;
}
for ( V_78 = 0 ; V_78 < V_27 -> V_88 ; V_78 ++ ) {
if ( ! V_27 -> V_89 [ V_78 ] . V_90 )
continue;
V_112 += V_27 -> V_111 * V_119 ;
}
return V_112 ;
}
static int
F_45 ( struct V_27 * V_27 , T_3 * V_120 , int V_121 )
{
int V_78 , V_99 ;
struct V_122 * V_109 = NULL ;
struct V_123 * V_124 = NULL ;
for ( V_78 = 0 ; V_78 < V_27 -> V_82 ; V_78 ++ ) {
if ( ! V_27 -> V_83 [ V_78 ] . V_84 )
continue;
for ( V_99 = 0 ; V_99 < V_27 -> V_106 ; V_99 ++ )
if ( V_27 -> V_83 [ V_78 ] . V_107 [ V_99 ] . V_108 &&
V_27 -> V_83 [ V_78 ] . V_107 [ V_99 ] . V_108 -> V_109 [ 0 ] &&
V_27 -> V_83 [ V_78 ] . V_107 [ V_99 ] . V_108 -> V_109 [ 0 ] -> V_110 ) {
V_120 [ V_121 ++ ] = V_27 -> V_83 [ V_78 ] . V_107 [ V_99 ] .
V_108 -> V_125 ;
V_120 [ V_121 ++ ] = 0 ;
V_120 [ V_121 ++ ] = * ( V_27 -> V_83 [ V_78 ] . V_107 [ V_99 ] .
V_108 -> V_126 ) ;
V_120 [ V_121 ++ ] = V_27 -> V_83 [ V_78 ] .
V_107 [ V_99 ] . V_127 ;
V_120 [ V_121 ++ ] = V_27 -> V_83 [ V_78 ] .
V_107 [ V_99 ] . V_128 ;
V_120 [ V_121 ++ ] = V_27 -> V_83 [ V_78 ] .
V_107 [ V_99 ] . V_129 ;
V_120 [ V_121 ++ ] = V_27 -> V_83 [ V_78 ] .
V_107 [ V_99 ] . V_130 ;
V_120 [ V_121 ++ ] = V_27 -> V_83 [ V_78 ] .
V_107 [ V_99 ] . V_131 ;
}
}
for ( V_78 = 0 ; V_78 < V_27 -> V_82 ; V_78 ++ ) {
if ( ! V_27 -> V_83 [ V_78 ] . V_84 )
continue;
for ( V_99 = 0 ; V_99 < V_27 -> V_106 ; V_99 ++ )
if ( V_27 -> V_83 [ V_78 ] . V_107 [ V_99 ] . V_108 ) {
if ( V_27 -> V_83 [ V_78 ] . V_107 [ V_99 ] . V_108 -> V_109 [ 0 ] &&
V_27 -> V_83 [ V_78 ] . V_107 [ V_99 ] . V_108 ->
V_109 [ 0 ] -> V_110 ) {
V_109 = V_27 -> V_83 [ V_78 ] . V_107 [ V_99 ] .
V_108 -> V_109 [ 0 ] ;
V_120 [ V_121 ++ ] = V_109 -> V_110 -> V_132 ;
V_120 [ V_121 ++ ] = V_109 -> V_110 -> V_133 ;
V_120 [ V_121 ++ ] = V_109 -> V_110 ->
V_134 ;
V_120 [ V_121 ++ ] = V_109 -> V_110 ->
V_135 ;
V_120 [ V_121 ++ ] = V_109 -> V_125 ;
V_120 [ V_121 ++ ] = V_109 -> V_136 ;
}
if ( V_27 -> V_83 [ V_78 ] . V_107 [ V_99 ] . V_108 -> V_109 [ 1 ] &&
V_27 -> V_83 [ V_78 ] . V_107 [ V_99 ] . V_108 ->
V_109 [ 1 ] -> V_110 ) {
V_109 = V_27 -> V_83 [ V_78 ] . V_107 [ V_99 ] .
V_108 -> V_109 [ 1 ] ;
V_120 [ V_121 ++ ] = V_109 -> V_110 -> V_132 ;
V_120 [ V_121 ++ ] = V_109 -> V_110 -> V_133 ;
V_120 [ V_121 ++ ] = V_109 -> V_110 ->
V_134 ;
V_120 [ V_121 ++ ] = V_109 -> V_110 ->
V_135 ;
V_120 [ V_121 ++ ] = V_109 -> V_125 ;
V_120 [ V_121 ++ ] = V_109 -> V_136 ;
}
}
}
for ( V_78 = 0 ; V_78 < V_27 -> V_88 ; V_78 ++ ) {
if ( ! V_27 -> V_89 [ V_78 ] . V_90 )
continue;
for ( V_99 = 0 ; V_99 < V_27 -> V_111 ; V_99 ++ )
if ( V_27 -> V_89 [ V_78 ] . V_124 [ V_99 ] &&
V_27 -> V_89 [ V_78 ] . V_124 [ V_99 ] -> V_137 ) {
V_124 = V_27 -> V_89 [ V_78 ] . V_124 [ V_99 ] ;
V_120 [ V_121 ++ ] = V_124 -> V_137 -> V_138 ;
V_120 [ V_121 ++ ] = V_124 -> V_137 -> V_139 ;
V_120 [ V_121 ++ ] = V_124 -> V_125 ;
V_120 [ V_121 ++ ] = V_124 -> V_136 ;
V_120 [ V_121 ++ ] = * ( V_124 -> V_140 ) ;
}
}
return V_121 ;
}
static void
F_46 ( struct V_1 * V_2 , struct V_141 * V_142 ,
T_3 * V_120 )
{
struct V_27 * V_27 = F_7 ( V_2 ) ;
int V_78 , V_99 , V_121 ;
unsigned long V_30 ;
struct V_143 * V_144 ;
T_3 * V_145 ;
T_1 V_101 ;
F_17 ( & V_27 -> V_64 ) ;
if ( F_44 ( V_2 ) != V_142 -> V_146 ) {
F_24 ( & V_27 -> V_64 ) ;
return;
}
F_9 ( & V_27 -> V_36 , V_30 ) ;
V_121 = 0 ;
memset ( V_120 , 0 , V_142 -> V_146 * sizeof( T_3 ) ) ;
V_144 = (struct V_143 * ) V_120 ;
F_47 ( V_27 , V_144 ) ;
F_48 ( V_27 , V_144 ) ;
V_121 = sizeof( * V_144 ) / sizeof( T_3 ) ;
V_27 -> V_142 . V_147 . V_148 = V_148 ( V_2 ) ;
V_145 = ( T_3 * ) & V_27 -> V_142 . V_147 ;
for ( V_78 = 0 ; V_78 < sizeof( struct V_149 ) / sizeof( T_3 ) ; V_78 ++ )
V_120 [ V_121 ++ ] = V_145 [ V_78 ] ;
V_145 = ( T_3 * ) & V_27 -> V_142 . V_150 -> V_151 ;
for ( V_78 = 0 ;
V_78 < F_49 ( struct V_152 , V_153 [ 0 ] ) /
sizeof( T_3 ) ;
V_78 ++ )
V_120 [ V_121 ++ ] = V_145 [ V_78 ] ;
V_101 = F_42 ( & V_27 -> V_37 ) ;
for ( V_78 = 0 ; V_101 ; V_78 ++ ) {
if ( V_101 & 1 ) {
V_145 = ( T_3 * ) & V_27 -> V_142 . V_150 ->
V_151 . V_154 [ V_78 ] ;
for ( V_99 = 0 ; V_99 < sizeof( struct V_155 ) /
sizeof( T_3 ) ; V_99 ++ )
V_120 [ V_121 ++ ] = V_145 [ V_99 ] ;
}
V_101 >>= 1 ;
}
V_101 = F_43 ( & V_27 -> V_37 ) ;
for ( V_78 = 0 ; V_101 ; V_78 ++ ) {
if ( V_101 & 1 ) {
V_145 = ( T_3 * ) & V_27 -> V_142 . V_150 ->
V_151 . V_153 [ V_78 ] ;
for ( V_99 = 0 ; V_99 < sizeof( struct V_156 ) /
sizeof( T_3 ) ; V_99 ++ )
V_120 [ V_121 ++ ] = V_145 [ V_99 ] ;
}
V_101 >>= 1 ;
}
V_121 = F_45 ( V_27 , V_120 , V_121 ) ;
F_11 ( & V_27 -> V_36 , V_30 ) ;
F_24 ( & V_27 -> V_64 ) ;
}
static int
F_50 ( struct V_1 * V_2 , int V_157 )
{
switch ( V_157 ) {
case V_102 :
return F_44 ( V_2 ) ;
default:
return - V_24 ;
}
}
void
F_51 ( struct V_1 * V_2 )
{
F_52 ( V_2 , & V_158 ) ;
}
