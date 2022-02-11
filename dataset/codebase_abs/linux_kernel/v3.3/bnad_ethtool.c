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
F_8 ( V_26 -> V_31 , V_32 , sizeof( V_26 -> V_31 ) ) ;
F_8 ( V_26 -> V_33 , V_34 , sizeof( V_26 -> V_33 ) ) ;
V_29 = F_9 ( sizeof( * V_29 ) , V_35 ) ;
if ( V_29 ) {
F_10 ( & V_27 -> V_36 , V_30 ) ;
F_11 ( & V_27 -> V_37 . V_38 . V_39 , V_29 ) ;
F_12 ( & V_27 -> V_36 , V_30 ) ;
F_8 ( V_26 -> V_40 , V_29 -> V_41 . V_42 ,
sizeof( V_26 -> V_40 ) ) ;
F_13 ( V_29 ) ;
}
F_8 ( V_26 -> V_43 , F_14 ( V_27 -> V_44 ) ,
sizeof( V_26 -> V_43 ) ) ;
}
static void
F_15 ( struct V_1 * V_2 , struct V_45 * V_46 )
{
V_46 -> V_5 = 0 ;
V_46 -> V_47 = 0 ;
}
static int
F_16 ( struct V_1 * V_2 , struct V_48 * V_49 )
{
struct V_27 * V_27 = F_7 ( V_2 ) ;
unsigned long V_30 ;
F_10 ( & V_27 -> V_36 , V_30 ) ;
V_49 -> V_50 =
( V_27 -> V_51 & V_52 ) ? true : false ;
F_12 ( & V_27 -> V_36 , V_30 ) ;
V_49 -> V_53 = V_27 -> V_54 *
V_55 ;
V_49 -> V_56 = V_27 -> V_57 *
V_55 ;
V_49 -> V_58 = V_59 ;
return 0 ;
}
static int
F_17 ( struct V_1 * V_2 , struct V_48 * V_49 )
{
struct V_27 * V_27 = F_7 ( V_2 ) ;
unsigned long V_30 ;
int V_60 = 0 ;
if ( V_49 -> V_53 == 0 ||
V_49 -> V_53 >
V_61 * V_55 )
return - V_62 ;
if ( V_49 -> V_56 == 0 ||
V_49 -> V_56 >
V_61 * V_55 )
return - V_62 ;
F_18 ( & V_27 -> V_63 ) ;
F_10 ( & V_27 -> V_36 , V_30 ) ;
if ( V_49 -> V_50 ) {
if ( ! ( V_27 -> V_51 & V_52 ) ) {
V_27 -> V_51 |= V_52 ;
F_19 ( V_27 ) ;
}
} else {
if ( V_27 -> V_51 & V_52 ) {
V_27 -> V_51 &= ~ V_52 ;
if ( V_27 -> V_51 & V_52 &&
F_20 ( V_64 ,
& V_27 -> V_65 ) ) {
F_21 ( V_64 ,
& V_27 -> V_65 ) ;
V_60 = 1 ;
}
F_12 ( & V_27 -> V_36 , V_30 ) ;
if ( V_60 )
F_22 ( & V_27 -> V_66 ) ;
F_10 ( & V_27 -> V_36 , V_30 ) ;
F_23 ( V_27 ) ;
}
}
if ( V_27 -> V_57 != V_49 -> V_56 /
V_55 ) {
V_27 -> V_57 = V_49 -> V_56 /
V_55 ;
F_24 ( V_27 ) ;
}
if ( V_27 -> V_54 != V_49 -> V_53 /
V_55 ) {
V_27 -> V_54 = V_49 -> V_53 /
V_55 ;
if ( ! ( V_27 -> V_51 & V_52 ) )
F_23 ( V_27 ) ;
}
F_12 ( & V_27 -> V_36 , V_30 ) ;
F_25 ( & V_27 -> V_63 ) ;
return 0 ;
}
static void
F_26 ( struct V_1 * V_2 ,
struct V_67 * V_68 )
{
struct V_27 * V_27 = F_7 ( V_2 ) ;
V_68 -> V_69 = V_70 ;
V_68 -> V_71 = V_72 ;
V_68 -> V_73 = V_27 -> V_74 ;
V_68 -> V_75 = V_27 -> V_76 ;
}
static int
F_27 ( struct V_1 * V_2 ,
struct V_67 * V_68 )
{
int V_77 , V_78 , V_79 = 0 ;
struct V_27 * V_27 = F_7 ( V_2 ) ;
unsigned long V_30 ;
F_18 ( & V_27 -> V_63 ) ;
if ( V_68 -> V_73 == V_27 -> V_74 &&
V_68 -> V_75 == V_27 -> V_76 ) {
F_25 ( & V_27 -> V_63 ) ;
return 0 ;
}
if ( V_68 -> V_73 < V_80 ||
V_68 -> V_73 > V_70 ||
! F_28 ( V_68 -> V_73 ) ) {
F_25 ( & V_27 -> V_63 ) ;
return - V_62 ;
}
if ( V_68 -> V_75 < V_80 ||
V_68 -> V_75 > V_72 ||
! F_28 ( V_68 -> V_75 ) ) {
F_25 ( & V_27 -> V_63 ) ;
return - V_62 ;
}
if ( V_68 -> V_73 != V_27 -> V_74 ) {
V_27 -> V_74 = V_68 -> V_73 ;
if ( ! F_29 ( V_2 ) ) {
F_25 ( & V_27 -> V_63 ) ;
return 0 ;
}
for ( V_77 = 0 ; V_77 < V_27 -> V_81 ; V_77 ++ ) {
if ( ! V_27 -> V_82 [ V_77 ] . V_83 )
continue;
F_30 ( V_27 , V_77 ) ;
V_78 = F_31 ( V_27 , V_77 ) ;
if ( V_78 && ! V_79 )
V_79 = V_78 ;
}
if ( ! V_79 && V_27 -> V_82 [ 0 ] . V_83 ) {
F_32 ( V_27 , 0 ) ;
F_33 ( V_27 ) ;
F_10 ( & V_27 -> V_36 , V_30 ) ;
F_34 ( V_27 , V_2 -> V_84 ) ;
F_12 ( & V_27 -> V_36 , V_30 ) ;
V_27 -> V_51 &= ~ ( V_85 |
V_86 ) ;
F_35 ( V_2 ) ;
}
}
if ( V_68 -> V_75 != V_27 -> V_76 ) {
V_27 -> V_76 = V_68 -> V_75 ;
if ( ! F_29 ( V_2 ) ) {
F_25 ( & V_27 -> V_63 ) ;
return 0 ;
}
for ( V_77 = 0 ; V_77 < V_27 -> V_87 ; V_77 ++ ) {
if ( ! V_27 -> V_88 [ V_77 ] . V_89 )
continue;
F_36 ( V_27 , V_77 ) ;
V_78 = F_37 ( V_27 , V_77 ) ;
if ( V_78 && ! V_79 )
V_79 = V_78 ;
}
}
F_25 ( & V_27 -> V_63 ) ;
return V_79 ;
}
static void
F_38 ( struct V_1 * V_2 ,
struct V_90 * V_91 )
{
struct V_27 * V_27 = F_7 ( V_2 ) ;
V_91 -> V_9 = 0 ;
V_91 -> V_92 = V_27 -> V_37 . V_93 . V_94 . V_92 ;
V_91 -> V_95 = V_27 -> V_37 . V_93 . V_94 . V_95 ;
}
static int
F_39 ( struct V_1 * V_2 ,
struct V_90 * V_91 )
{
struct V_27 * V_27 = F_7 ( V_2 ) ;
struct V_96 V_94 ;
unsigned long V_30 ;
if ( V_91 -> V_9 == V_23 )
return - V_62 ;
F_18 ( & V_27 -> V_63 ) ;
if ( V_91 -> V_92 != V_27 -> V_37 . V_93 . V_94 . V_92 ||
V_91 -> V_95 != V_27 -> V_37 . V_93 . V_94 . V_95 ) {
V_94 . V_92 = V_91 -> V_92 ;
V_94 . V_95 = V_91 -> V_95 ;
F_10 ( & V_27 -> V_36 , V_30 ) ;
F_40 ( & V_27 -> V_37 . V_93 , & V_94 , NULL ) ;
F_12 ( & V_27 -> V_36 , V_30 ) ;
}
F_25 ( & V_27 -> V_63 ) ;
return 0 ;
}
static void
F_41 ( struct V_1 * V_2 , T_1 V_97 , T_2 * string )
{
struct V_27 * V_27 = F_7 ( V_2 ) ;
int V_77 , V_98 , V_99 ;
T_1 V_100 ;
F_18 ( & V_27 -> V_63 ) ;
switch ( V_97 ) {
case V_101 :
for ( V_77 = 0 ; V_77 < V_102 ; V_77 ++ ) {
F_42 ( ! ( strlen ( V_103 [ V_77 ] ) <
V_104 ) ) ;
memcpy ( string , V_103 [ V_77 ] ,
V_104 ) ;
string += V_104 ;
}
V_100 = F_43 ( & V_27 -> V_37 ) ;
for ( V_77 = 0 ; V_100 ; V_77 ++ ) {
if ( V_100 & 1 ) {
sprintf ( string , L_1 , V_77 ) ;
string += V_104 ;
sprintf ( string , L_2 , V_77 ) ;
string += V_104 ;
sprintf ( string , L_3 , V_77 ) ;
string += V_104 ;
sprintf ( string , L_4 , V_77 ) ;
string += V_104 ;
sprintf ( string , L_5 , V_77 ) ;
string += V_104 ;
sprintf ( string , L_6 , V_77 ) ;
string += V_104 ;
sprintf ( string , L_7 , V_77 ) ;
string += V_104 ;
sprintf ( string , L_8 , V_77 ) ;
string += V_104 ;
sprintf ( string , L_9 , V_77 ) ;
string += V_104 ;
sprintf ( string , L_10 , V_77 ) ;
string += V_104 ;
sprintf ( string , L_11 , V_77 ) ;
string += V_104 ;
sprintf ( string , L_12 , V_77 ) ;
string += V_104 ;
}
V_100 >>= 1 ;
}
V_100 = F_44 ( & V_27 -> V_37 ) ;
for ( V_77 = 0 ; V_100 ; V_77 ++ ) {
if ( V_100 & 1 ) {
sprintf ( string , L_13 , V_77 ) ;
string += V_104 ;
sprintf ( string , L_14 , V_77 ) ;
string += V_104 ;
sprintf ( string , L_15 , V_77 ) ;
string += V_104 ;
sprintf ( string , L_16 , V_77 ) ;
string += V_104 ;
sprintf ( string , L_17 , V_77 ) ;
string += V_104 ;
sprintf ( string , L_18 , V_77 ) ;
string += V_104 ;
sprintf ( string , L_19 , V_77 ) ;
string += V_104 ;
sprintf ( string , L_20 , V_77 ) ;
string += V_104 ;
sprintf ( string , L_21 , V_77 ) ;
string += V_104 ;
sprintf ( string , L_22 , V_77 ) ;
string += V_104 ;
}
V_100 >>= 1 ;
}
V_99 = 0 ;
for ( V_77 = 0 ; V_77 < V_27 -> V_81 ; V_77 ++ ) {
if ( ! V_27 -> V_82 [ V_77 ] . V_83 )
continue;
for ( V_98 = 0 ; V_98 < V_27 -> V_105 ; V_98 ++ ) {
sprintf ( string , L_23 , V_99 ) ;
string += V_104 ;
sprintf ( string , L_24 , V_99 ) ;
string += V_104 ;
sprintf ( string , L_25 ,
V_99 ) ;
string += V_104 ;
sprintf ( string , L_26 , V_99 ) ;
string += V_104 ;
sprintf ( string , L_27 , V_99 ) ;
string += V_104 ;
sprintf ( string , L_28 , V_99 ) ;
string += V_104 ;
sprintf ( string , L_29 , V_99 ) ;
string += V_104 ;
sprintf ( string , L_30 , V_99 ) ;
string += V_104 ;
V_99 ++ ;
}
}
V_99 = 0 ;
for ( V_77 = 0 ; V_77 < V_27 -> V_81 ; V_77 ++ ) {
if ( ! V_27 -> V_82 [ V_77 ] . V_83 )
continue;
for ( V_98 = 0 ; V_98 < V_27 -> V_105 ; V_98 ++ ) {
sprintf ( string , L_31 , V_99 ) ;
string += V_104 ;
sprintf ( string , L_32 , V_99 ) ;
string += V_104 ;
sprintf ( string , L_33 ,
V_99 ) ;
string += V_104 ;
sprintf ( string , L_34 , V_99 ) ;
string += V_104 ;
sprintf ( string , L_35 , V_99 ) ;
string += V_104 ;
sprintf ( string , L_36 , V_99 ) ;
string += V_104 ;
V_99 ++ ;
if ( V_27 -> V_82 [ V_77 ] . V_106 [ V_98 ] . V_107 &&
V_27 -> V_82 [ V_77 ] . V_106 [ V_98 ] . V_107 ->
V_108 [ 1 ] &&
V_27 -> V_82 [ V_77 ] . V_106 [ V_98 ] . V_107 ->
V_108 [ 1 ] -> V_109 ) {
sprintf ( string , L_31 , V_99 ) ;
string += V_104 ;
sprintf ( string , L_32 , V_99 ) ;
string += V_104 ;
sprintf ( string ,
L_33 , V_99 ) ;
string += V_104 ;
sprintf ( string , L_34 ,
V_99 ) ;
string += V_104 ;
sprintf ( string , L_35 ,
V_99 ) ;
string += V_104 ;
sprintf ( string , L_36 ,
V_99 ) ;
string += V_104 ;
V_99 ++ ;
}
}
}
V_99 = 0 ;
for ( V_77 = 0 ; V_77 < V_27 -> V_87 ; V_77 ++ ) {
if ( ! V_27 -> V_88 [ V_77 ] . V_89 )
continue;
for ( V_98 = 0 ; V_98 < V_27 -> V_110 ; V_98 ++ ) {
sprintf ( string , L_37 , V_99 ) ;
string += V_104 ;
sprintf ( string , L_38 , V_99 ) ;
string += V_104 ;
sprintf ( string , L_39 , V_99 ) ;
string += V_104 ;
sprintf ( string , L_40 , V_99 ) ;
string += V_104 ;
sprintf ( string , L_41 ,
V_99 ) ;
string += V_104 ;
V_99 ++ ;
}
}
break;
default:
break;
}
F_25 ( & V_27 -> V_63 ) ;
}
static int
F_45 ( struct V_1 * V_2 )
{
struct V_27 * V_27 = F_7 ( V_2 ) ;
int V_77 , V_98 , V_111 = 0 , V_112 = 0 , V_113 = 0 ;
T_1 V_100 ;
V_100 = F_43 ( & V_27 -> V_37 ) ;
for ( V_77 = 0 ; V_100 ; V_77 ++ ) {
if ( V_100 & 1 )
V_113 ++ ;
V_100 >>= 1 ;
}
V_100 = F_44 ( & V_27 -> V_37 ) ;
for ( V_77 = 0 ; V_100 ; V_77 ++ ) {
if ( V_100 & 1 )
V_112 ++ ;
V_100 >>= 1 ;
}
V_111 = V_102 +
V_113 * V_114 +
V_112 * V_115 ;
for ( V_77 = 0 ; V_77 < V_27 -> V_81 ; V_77 ++ ) {
if ( ! V_27 -> V_82 [ V_77 ] . V_83 )
continue;
V_111 += V_27 -> V_105 * V_116 ;
V_111 += V_27 -> V_105 * V_117 ;
for ( V_98 = 0 ; V_98 < V_27 -> V_105 ; V_98 ++ )
if ( V_27 -> V_82 [ V_77 ] . V_106 [ V_98 ] . V_107 &&
V_27 -> V_82 [ V_77 ] . V_106 [ V_98 ] . V_107 -> V_108 [ 1 ] &&
V_27 -> V_82 [ V_77 ] . V_106 [ V_98 ] . V_107 -> V_108 [ 1 ] -> V_109 )
V_111 += V_117 ;
}
for ( V_77 = 0 ; V_77 < V_27 -> V_87 ; V_77 ++ ) {
if ( ! V_27 -> V_88 [ V_77 ] . V_89 )
continue;
V_111 += V_27 -> V_110 * V_118 ;
}
return V_111 ;
}
static int
F_46 ( struct V_27 * V_27 , T_3 * V_119 , int V_120 )
{
int V_77 , V_98 ;
struct V_121 * V_108 = NULL ;
struct V_122 * V_123 = NULL ;
for ( V_77 = 0 ; V_77 < V_27 -> V_81 ; V_77 ++ ) {
if ( ! V_27 -> V_82 [ V_77 ] . V_83 )
continue;
for ( V_98 = 0 ; V_98 < V_27 -> V_105 ; V_98 ++ )
if ( V_27 -> V_82 [ V_77 ] . V_106 [ V_98 ] . V_107 &&
V_27 -> V_82 [ V_77 ] . V_106 [ V_98 ] . V_107 -> V_108 [ 0 ] &&
V_27 -> V_82 [ V_77 ] . V_106 [ V_98 ] . V_107 -> V_108 [ 0 ] -> V_109 ) {
V_119 [ V_120 ++ ] = V_27 -> V_82 [ V_77 ] . V_106 [ V_98 ] .
V_107 -> V_124 ;
V_119 [ V_120 ++ ] = 0 ;
V_119 [ V_120 ++ ] = * ( V_27 -> V_82 [ V_77 ] . V_106 [ V_98 ] .
V_107 -> V_125 ) ;
V_119 [ V_120 ++ ] = V_27 -> V_82 [ V_77 ] .
V_106 [ V_98 ] . V_126 ;
V_119 [ V_120 ++ ] = V_27 -> V_82 [ V_77 ] .
V_106 [ V_98 ] . V_127 ;
V_119 [ V_120 ++ ] = V_27 -> V_82 [ V_77 ] .
V_106 [ V_98 ] . V_128 ;
V_119 [ V_120 ++ ] = V_27 -> V_82 [ V_77 ] .
V_106 [ V_98 ] . V_129 ;
V_119 [ V_120 ++ ] = V_27 -> V_82 [ V_77 ] .
V_106 [ V_98 ] . V_130 ;
}
}
for ( V_77 = 0 ; V_77 < V_27 -> V_81 ; V_77 ++ ) {
if ( ! V_27 -> V_82 [ V_77 ] . V_83 )
continue;
for ( V_98 = 0 ; V_98 < V_27 -> V_105 ; V_98 ++ )
if ( V_27 -> V_82 [ V_77 ] . V_106 [ V_98 ] . V_107 ) {
if ( V_27 -> V_82 [ V_77 ] . V_106 [ V_98 ] . V_107 -> V_108 [ 0 ] &&
V_27 -> V_82 [ V_77 ] . V_106 [ V_98 ] . V_107 ->
V_108 [ 0 ] -> V_109 ) {
V_108 = V_27 -> V_82 [ V_77 ] . V_106 [ V_98 ] .
V_107 -> V_108 [ 0 ] ;
V_119 [ V_120 ++ ] = V_108 -> V_109 -> V_131 ;
V_119 [ V_120 ++ ] = V_108 -> V_109 -> V_132 ;
V_119 [ V_120 ++ ] = V_108 -> V_109 ->
V_133 ;
V_119 [ V_120 ++ ] = V_108 -> V_109 ->
V_134 ;
V_119 [ V_120 ++ ] = V_108 -> V_124 ;
V_119 [ V_120 ++ ] = V_108 -> V_135 ;
}
if ( V_27 -> V_82 [ V_77 ] . V_106 [ V_98 ] . V_107 -> V_108 [ 1 ] &&
V_27 -> V_82 [ V_77 ] . V_106 [ V_98 ] . V_107 ->
V_108 [ 1 ] -> V_109 ) {
V_108 = V_27 -> V_82 [ V_77 ] . V_106 [ V_98 ] .
V_107 -> V_108 [ 1 ] ;
V_119 [ V_120 ++ ] = V_108 -> V_109 -> V_131 ;
V_119 [ V_120 ++ ] = V_108 -> V_109 -> V_132 ;
V_119 [ V_120 ++ ] = V_108 -> V_109 ->
V_133 ;
V_119 [ V_120 ++ ] = V_108 -> V_109 ->
V_134 ;
V_119 [ V_120 ++ ] = V_108 -> V_124 ;
V_119 [ V_120 ++ ] = V_108 -> V_135 ;
}
}
}
for ( V_77 = 0 ; V_77 < V_27 -> V_87 ; V_77 ++ ) {
if ( ! V_27 -> V_88 [ V_77 ] . V_89 )
continue;
for ( V_98 = 0 ; V_98 < V_27 -> V_110 ; V_98 ++ )
if ( V_27 -> V_88 [ V_77 ] . V_123 [ V_98 ] &&
V_27 -> V_88 [ V_77 ] . V_123 [ V_98 ] -> V_136 ) {
V_123 = V_27 -> V_88 [ V_77 ] . V_123 [ V_98 ] ;
V_119 [ V_120 ++ ] = V_123 -> V_136 -> V_137 ;
V_119 [ V_120 ++ ] = V_123 -> V_136 -> V_138 ;
V_119 [ V_120 ++ ] = V_123 -> V_124 ;
V_119 [ V_120 ++ ] = V_123 -> V_135 ;
V_119 [ V_120 ++ ] = * ( V_123 -> V_139 ) ;
}
}
return V_120 ;
}
static void
F_47 ( struct V_1 * V_2 , struct V_140 * V_141 ,
T_3 * V_119 )
{
struct V_27 * V_27 = F_7 ( V_2 ) ;
int V_77 , V_98 , V_120 ;
unsigned long V_30 ;
struct V_142 * V_143 ;
T_3 * V_144 ;
T_1 V_100 ;
F_18 ( & V_27 -> V_63 ) ;
if ( F_45 ( V_2 ) != V_141 -> V_145 ) {
F_25 ( & V_27 -> V_63 ) ;
return;
}
F_10 ( & V_27 -> V_36 , V_30 ) ;
V_120 = 0 ;
memset ( V_119 , 0 , V_141 -> V_145 * sizeof( T_3 ) ) ;
V_143 = (struct V_142 * ) V_119 ;
F_48 ( V_27 , V_143 ) ;
F_49 ( V_27 , V_143 ) ;
V_120 = sizeof( * V_143 ) / sizeof( T_3 ) ;
V_27 -> V_141 . V_146 . V_147 = V_147 ( V_2 ) ;
V_144 = ( T_3 * ) & V_27 -> V_141 . V_146 ;
for ( V_77 = 0 ; V_77 < sizeof( struct V_148 ) / sizeof( T_3 ) ; V_77 ++ )
V_119 [ V_120 ++ ] = V_144 [ V_77 ] ;
V_144 = ( T_3 * ) & V_27 -> V_141 . V_149 -> V_150 ;
for ( V_77 = 0 ;
V_77 < F_50 ( struct V_151 , V_152 [ 0 ] ) /
sizeof( T_3 ) ;
V_77 ++ )
V_119 [ V_120 ++ ] = V_144 [ V_77 ] ;
V_100 = F_43 ( & V_27 -> V_37 ) ;
for ( V_77 = 0 ; V_100 ; V_77 ++ ) {
if ( V_100 & 1 ) {
V_144 = ( T_3 * ) & V_27 -> V_141 . V_149 ->
V_150 . V_153 [ V_77 ] ;
for ( V_98 = 0 ; V_98 < sizeof( struct V_154 ) /
sizeof( T_3 ) ; V_98 ++ )
V_119 [ V_120 ++ ] = V_144 [ V_98 ] ;
}
V_100 >>= 1 ;
}
V_100 = F_44 ( & V_27 -> V_37 ) ;
for ( V_77 = 0 ; V_100 ; V_77 ++ ) {
if ( V_100 & 1 ) {
V_144 = ( T_3 * ) & V_27 -> V_141 . V_149 ->
V_150 . V_152 [ V_77 ] ;
for ( V_98 = 0 ; V_98 < sizeof( struct V_155 ) /
sizeof( T_3 ) ; V_98 ++ )
V_119 [ V_120 ++ ] = V_144 [ V_98 ] ;
}
V_100 >>= 1 ;
}
V_120 = F_46 ( V_27 , V_119 , V_120 ) ;
F_12 ( & V_27 -> V_36 , V_30 ) ;
F_25 ( & V_27 -> V_63 ) ;
}
static int
F_51 ( struct V_1 * V_2 , int V_156 )
{
switch ( V_156 ) {
case V_101 :
return F_45 ( V_2 ) ;
default:
return - V_24 ;
}
}
static T_1
F_52 ( struct V_27 * V_27 , T_1 V_157 ,
T_1 * V_158 )
{
struct V_159 * V_160 ;
struct V_161 V_162 ;
T_1 V_77 , V_163 = 0 , V_164 ;
unsigned long V_30 = 0 ;
V_160 = F_9 ( sizeof( struct V_159 ) , V_35 ) ;
if ( ! V_160 )
return 0 ;
V_162 . V_27 = V_27 ;
V_162 . V_165 = 0 ;
F_53 ( & V_162 . V_166 ) ;
F_10 ( & V_27 -> V_36 , V_30 ) ;
V_164 = F_54 ( & V_27 -> V_37 . V_167 , V_160 ,
V_168 , & V_162 ) ;
if ( V_164 != V_169 ) {
F_12 ( & V_27 -> V_36 , V_30 ) ;
F_13 ( V_160 ) ;
return 0 ;
}
F_12 ( & V_27 -> V_36 , V_30 ) ;
F_55 ( & V_162 . V_166 ) ;
V_164 = V_162 . V_165 ;
if ( V_164 == V_169 ) {
for ( V_77 = 0 ; V_77 < V_160 -> V_170 ; V_77 ++ ) {
if ( V_157 >= V_160 -> V_171 [ V_77 ] . V_172 &&
V_157 < ( V_160 -> V_171 [ V_77 ] . V_172 +
V_160 -> V_171 [ V_77 ] . V_173 ) ) {
V_163 = V_160 -> V_171 [ V_77 ] . V_174 ;
* V_158 = V_160 -> V_171 [ V_77 ] . V_172 ;
break;
}
}
}
F_13 ( V_160 ) ;
return V_163 ;
}
static int
F_56 ( struct V_1 * V_2 )
{
return V_175 ;
}
static int
F_57 ( struct V_1 * V_2 , struct V_176 * V_177 ,
T_2 * V_178 )
{
struct V_27 * V_27 = F_7 ( V_2 ) ;
struct V_161 V_162 ;
T_1 V_163 = 0 , V_158 = 0 ;
unsigned long V_30 = 0 ;
int V_164 = 0 ;
if ( V_177 -> V_179 != ( V_27 -> V_44 -> V_180 |
( V_27 -> V_44 -> V_181 << 16 ) ) )
return - V_182 ;
V_163 = F_52 ( V_27 ,
V_177 -> V_157 , & V_158 ) ;
if ( V_163 == 0 )
return - V_182 ;
V_162 . V_27 = V_27 ;
V_162 . V_165 = 0 ;
F_53 ( & V_162 . V_166 ) ;
F_10 ( & V_27 -> V_36 , V_30 ) ;
V_164 = F_58 ( & V_27 -> V_37 . V_167 , V_163 ,
V_27 -> V_183 , V_178 , V_177 -> V_184 ,
V_177 -> V_157 - V_158 ,
V_168 , & V_162 ) ;
if ( V_164 != V_169 ) {
F_12 ( & V_27 -> V_36 , V_30 ) ;
goto V_185;
}
F_12 ( & V_27 -> V_36 , V_30 ) ;
F_55 ( & V_162 . V_166 ) ;
V_164 = V_162 . V_165 ;
V_185:
return V_164 ;
}
static int
F_59 ( struct V_1 * V_2 , struct V_176 * V_177 ,
T_2 * V_178 )
{
struct V_27 * V_27 = F_7 ( V_2 ) ;
struct V_161 V_162 ;
T_1 V_163 = 0 , V_158 = 0 ;
unsigned long V_30 = 0 ;
int V_164 = 0 ;
if ( V_177 -> V_179 != ( V_27 -> V_44 -> V_180 |
( V_27 -> V_44 -> V_181 << 16 ) ) )
return - V_62 ;
V_163 = F_52 ( V_27 ,
V_177 -> V_157 , & V_158 ) ;
if ( V_163 == 0 )
return - V_182 ;
V_162 . V_27 = V_27 ;
V_162 . V_165 = 0 ;
F_53 ( & V_162 . V_166 ) ;
F_10 ( & V_27 -> V_36 , V_30 ) ;
V_164 = F_60 ( & V_27 -> V_37 . V_167 , V_163 ,
V_27 -> V_183 , V_178 , V_177 -> V_184 ,
V_177 -> V_157 - V_158 ,
V_168 , & V_162 ) ;
if ( V_164 != V_169 ) {
F_12 ( & V_27 -> V_36 , V_30 ) ;
goto V_185;
}
F_12 ( & V_27 -> V_36 , V_30 ) ;
F_55 ( & V_162 . V_166 ) ;
V_164 = V_162 . V_165 ;
V_185:
return V_164 ;
}
void
F_61 ( struct V_1 * V_2 )
{
F_62 ( V_2 , & V_186 ) ;
}
