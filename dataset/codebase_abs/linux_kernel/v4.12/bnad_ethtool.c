static int
F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_1 V_5 , V_6 ;
V_5 = V_7 ;
V_6 = V_8 ;
V_4 -> V_9 . V_10 = V_11 ;
V_5 |= V_12 ;
V_6 |= V_13 ;
V_4 -> V_9 . V_14 = V_15 ;
V_4 -> V_9 . V_16 = 0 ;
if ( F_2 ( V_2 ) ) {
V_4 -> V_9 . V_17 = V_18 ;
V_4 -> V_9 . V_19 = V_20 ;
} else {
V_4 -> V_9 . V_17 = V_21 ;
V_4 -> V_9 . V_19 = V_22 ;
}
F_3 ( V_4 -> V_23 . V_5 ,
V_5 ) ;
F_3 ( V_4 -> V_23 . V_6 ,
V_6 ) ;
return 0 ;
}
static int
F_4 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
if ( V_4 -> V_9 . V_10 == V_24 )
return - V_25 ;
if ( ( V_4 -> V_9 . V_17 == V_18 ) &&
( V_4 -> V_9 . V_19 == V_20 ) )
return 0 ;
return - V_25 ;
}
static void
F_5 ( struct V_1 * V_2 , struct V_26 * V_27 )
{
struct V_28 * V_28 = F_6 ( V_2 ) ;
struct V_29 * V_30 ;
unsigned long V_31 ;
F_7 ( V_27 -> V_32 , V_33 , sizeof( V_27 -> V_32 ) ) ;
F_7 ( V_27 -> V_34 , V_35 , sizeof( V_27 -> V_34 ) ) ;
V_30 = F_8 ( sizeof( * V_30 ) , V_36 ) ;
if ( V_30 ) {
F_9 ( & V_28 -> V_37 , V_31 ) ;
F_10 ( & V_28 -> V_38 . V_39 . V_40 , V_30 ) ;
F_11 ( & V_28 -> V_37 , V_31 ) ;
F_7 ( V_27 -> V_41 , V_30 -> V_42 . V_43 ,
sizeof( V_27 -> V_41 ) ) ;
F_12 ( V_30 ) ;
}
F_7 ( V_27 -> V_44 , F_13 ( V_28 -> V_45 ) ,
sizeof( V_27 -> V_44 ) ) ;
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
struct V_28 * V_28 = F_6 ( V_2 ) ;
unsigned long V_31 ;
F_9 ( & V_28 -> V_37 , V_31 ) ;
V_50 -> V_51 =
( V_28 -> V_52 & V_53 ) ? true : false ;
F_11 ( & V_28 -> V_37 , V_31 ) ;
V_50 -> V_54 = V_28 -> V_55 *
V_56 ;
V_50 -> V_57 = V_28 -> V_58 *
V_56 ;
V_50 -> V_59 = V_60 ;
return 0 ;
}
static int
F_16 ( struct V_1 * V_2 , struct V_49 * V_50 )
{
struct V_28 * V_28 = F_6 ( V_2 ) ;
unsigned long V_31 ;
int V_61 = 0 ;
if ( V_50 -> V_54 == 0 ||
V_50 -> V_54 >
V_62 * V_56 )
return - V_63 ;
if ( V_50 -> V_57 == 0 ||
V_50 -> V_57 >
V_62 * V_56 )
return - V_63 ;
F_17 ( & V_28 -> V_64 ) ;
F_9 ( & V_28 -> V_37 , V_31 ) ;
if ( V_50 -> V_51 ) {
if ( ! ( V_28 -> V_52 & V_53 ) ) {
V_28 -> V_52 |= V_53 ;
F_18 ( V_28 ) ;
}
} else {
if ( V_28 -> V_52 & V_53 ) {
V_28 -> V_52 &= ~ V_53 ;
if ( V_28 -> V_52 & V_53 &&
F_19 ( V_65 ,
& V_28 -> V_66 ) ) {
F_20 ( V_65 ,
& V_28 -> V_66 ) ;
V_61 = 1 ;
}
F_11 ( & V_28 -> V_37 , V_31 ) ;
if ( V_61 )
F_21 ( & V_28 -> V_67 ) ;
F_9 ( & V_28 -> V_37 , V_31 ) ;
F_22 ( V_28 ) ;
}
}
if ( V_28 -> V_58 != V_50 -> V_57 /
V_56 ) {
V_28 -> V_58 = V_50 -> V_57 /
V_56 ;
F_23 ( V_28 ) ;
}
if ( V_28 -> V_55 != V_50 -> V_54 /
V_56 ) {
V_28 -> V_55 = V_50 -> V_54 /
V_56 ;
if ( ! ( V_28 -> V_52 & V_53 ) )
F_22 ( V_28 ) ;
}
F_11 ( & V_28 -> V_37 , V_31 ) ;
F_24 ( & V_28 -> V_64 ) ;
return 0 ;
}
static void
F_25 ( struct V_1 * V_2 ,
struct V_68 * V_69 )
{
struct V_28 * V_28 = F_6 ( V_2 ) ;
V_69 -> V_70 = V_71 ;
V_69 -> V_72 = V_73 ;
V_69 -> V_74 = V_28 -> V_75 ;
V_69 -> V_76 = V_28 -> V_77 ;
}
static int
F_26 ( struct V_1 * V_2 ,
struct V_68 * V_69 )
{
int V_78 , V_79 , V_80 = 0 ;
struct V_28 * V_28 = F_6 ( V_2 ) ;
unsigned long V_31 ;
F_17 ( & V_28 -> V_64 ) ;
if ( V_69 -> V_74 == V_28 -> V_75 &&
V_69 -> V_76 == V_28 -> V_77 ) {
F_24 ( & V_28 -> V_64 ) ;
return 0 ;
}
if ( V_69 -> V_74 < V_81 ||
V_69 -> V_74 > V_71 ||
! F_27 ( V_69 -> V_74 ) ) {
F_24 ( & V_28 -> V_64 ) ;
return - V_63 ;
}
if ( V_69 -> V_76 < V_81 ||
V_69 -> V_76 > V_73 ||
! F_27 ( V_69 -> V_76 ) ) {
F_24 ( & V_28 -> V_64 ) ;
return - V_63 ;
}
if ( V_69 -> V_74 != V_28 -> V_75 ) {
V_28 -> V_75 = V_69 -> V_74 ;
if ( ! F_28 ( V_2 ) ) {
F_24 ( & V_28 -> V_64 ) ;
return 0 ;
}
for ( V_78 = 0 ; V_78 < V_28 -> V_82 ; V_78 ++ ) {
if ( ! V_28 -> V_83 [ V_78 ] . V_84 )
continue;
F_29 ( V_28 , V_78 ) ;
V_79 = F_30 ( V_28 , V_78 ) ;
if ( V_79 && ! V_80 )
V_80 = V_79 ;
}
if ( ! V_80 && V_28 -> V_83 [ 0 ] . V_84 ) {
F_31 ( V_28 , 0 ) ;
F_32 ( V_28 ) ;
F_9 ( & V_28 -> V_37 , V_31 ) ;
F_33 ( V_28 , V_2 -> V_85 ) ;
F_11 ( & V_28 -> V_37 , V_31 ) ;
V_28 -> V_52 &= ~ ( V_86 |
V_87 ) ;
F_34 ( V_2 ) ;
}
}
if ( V_69 -> V_76 != V_28 -> V_77 ) {
V_28 -> V_77 = V_69 -> V_76 ;
if ( ! F_28 ( V_2 ) ) {
F_24 ( & V_28 -> V_64 ) ;
return 0 ;
}
for ( V_78 = 0 ; V_78 < V_28 -> V_88 ; V_78 ++ ) {
if ( ! V_28 -> V_89 [ V_78 ] . V_90 )
continue;
F_35 ( V_28 , V_78 ) ;
V_79 = F_36 ( V_28 , V_78 ) ;
if ( V_79 && ! V_80 )
V_80 = V_79 ;
}
}
F_24 ( & V_28 -> V_64 ) ;
return V_80 ;
}
static void
F_37 ( struct V_1 * V_2 ,
struct V_91 * V_92 )
{
struct V_28 * V_28 = F_6 ( V_2 ) ;
V_92 -> V_10 = 0 ;
V_92 -> V_93 = V_28 -> V_38 . V_94 . V_95 . V_93 ;
V_92 -> V_96 = V_28 -> V_38 . V_94 . V_95 . V_96 ;
}
static int
F_38 ( struct V_1 * V_2 ,
struct V_91 * V_92 )
{
struct V_28 * V_28 = F_6 ( V_2 ) ;
struct V_97 V_95 ;
unsigned long V_31 ;
if ( V_92 -> V_10 == V_24 )
return - V_63 ;
F_17 ( & V_28 -> V_64 ) ;
if ( V_92 -> V_93 != V_28 -> V_38 . V_94 . V_95 . V_93 ||
V_92 -> V_96 != V_28 -> V_38 . V_94 . V_95 . V_96 ) {
V_95 . V_93 = V_92 -> V_93 ;
V_95 . V_96 = V_92 -> V_96 ;
F_9 ( & V_28 -> V_37 , V_31 ) ;
F_39 ( & V_28 -> V_38 . V_94 , & V_95 ) ;
F_11 ( & V_28 -> V_37 , V_31 ) ;
}
F_24 ( & V_28 -> V_64 ) ;
return 0 ;
}
static void
F_40 ( struct V_1 * V_2 , T_1 V_98 , T_2 * string )
{
struct V_28 * V_28 = F_6 ( V_2 ) ;
int V_78 , V_99 , V_100 ;
T_1 V_101 ;
F_17 ( & V_28 -> V_64 ) ;
switch ( V_98 ) {
case V_102 :
for ( V_78 = 0 ; V_78 < V_103 ; V_78 ++ ) {
F_41 ( ! ( strlen ( V_104 [ V_78 ] ) <
V_105 ) ) ;
strncpy ( string , V_104 [ V_78 ] ,
V_105 ) ;
string += V_105 ;
}
V_101 = F_42 ( & V_28 -> V_38 ) ;
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
V_101 = F_43 ( & V_28 -> V_38 ) ;
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
for ( V_78 = 0 ; V_78 < V_28 -> V_82 ; V_78 ++ ) {
if ( ! V_28 -> V_83 [ V_78 ] . V_84 )
continue;
for ( V_99 = 0 ; V_99 < V_28 -> V_106 ; V_99 ++ ) {
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
for ( V_78 = 0 ; V_78 < V_28 -> V_82 ; V_78 ++ ) {
if ( ! V_28 -> V_83 [ V_78 ] . V_84 )
continue;
for ( V_99 = 0 ; V_99 < V_28 -> V_106 ; V_99 ++ ) {
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
sprintf ( string , L_37 , V_100 ) ;
string += V_105 ;
V_100 ++ ;
if ( V_28 -> V_83 [ V_78 ] . V_107 [ V_99 ] . V_108 &&
V_28 -> V_83 [ V_78 ] . V_107 [ V_99 ] . V_108 ->
V_109 [ 1 ] &&
V_28 -> V_83 [ V_78 ] . V_107 [ V_99 ] . V_108 ->
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
sprintf ( string , L_37 ,
V_100 ) ;
string += V_105 ;
V_100 ++ ;
}
}
}
V_100 = 0 ;
for ( V_78 = 0 ; V_78 < V_28 -> V_88 ; V_78 ++ ) {
if ( ! V_28 -> V_89 [ V_78 ] . V_90 )
continue;
for ( V_99 = 0 ; V_99 < V_28 -> V_111 ; V_99 ++ ) {
sprintf ( string , L_38 , V_100 ) ;
string += V_105 ;
sprintf ( string , L_39 , V_100 ) ;
string += V_105 ;
sprintf ( string , L_40 , V_100 ) ;
string += V_105 ;
sprintf ( string , L_41 , V_100 ) ;
string += V_105 ;
sprintf ( string , L_42 ,
V_100 ) ;
string += V_105 ;
V_100 ++ ;
}
}
break;
default:
break;
}
F_24 ( & V_28 -> V_64 ) ;
}
static int
F_44 ( struct V_1 * V_2 )
{
struct V_28 * V_28 = F_6 ( V_2 ) ;
int V_78 , V_99 , V_112 = 0 , V_113 = 0 , V_114 = 0 ;
T_1 V_101 ;
V_101 = F_42 ( & V_28 -> V_38 ) ;
for ( V_78 = 0 ; V_101 ; V_78 ++ ) {
if ( V_101 & 1 )
V_114 ++ ;
V_101 >>= 1 ;
}
V_101 = F_43 ( & V_28 -> V_38 ) ;
for ( V_78 = 0 ; V_101 ; V_78 ++ ) {
if ( V_101 & 1 )
V_113 ++ ;
V_101 >>= 1 ;
}
V_112 = V_103 +
V_114 * V_115 +
V_113 * V_116 ;
for ( V_78 = 0 ; V_78 < V_28 -> V_82 ; V_78 ++ ) {
if ( ! V_28 -> V_83 [ V_78 ] . V_84 )
continue;
V_112 += V_28 -> V_106 * V_117 ;
V_112 += V_28 -> V_106 * V_118 ;
for ( V_99 = 0 ; V_99 < V_28 -> V_106 ; V_99 ++ )
if ( V_28 -> V_83 [ V_78 ] . V_107 [ V_99 ] . V_108 &&
V_28 -> V_83 [ V_78 ] . V_107 [ V_99 ] . V_108 -> V_109 [ 1 ] &&
V_28 -> V_83 [ V_78 ] . V_107 [ V_99 ] . V_108 -> V_109 [ 1 ] -> V_110 )
V_112 += V_118 ;
}
for ( V_78 = 0 ; V_78 < V_28 -> V_88 ; V_78 ++ ) {
if ( ! V_28 -> V_89 [ V_78 ] . V_90 )
continue;
V_112 += V_28 -> V_111 * V_119 ;
}
return V_112 ;
}
static int
F_45 ( struct V_28 * V_28 , T_3 * V_120 , int V_121 )
{
int V_78 , V_99 ;
struct V_122 * V_109 = NULL ;
struct V_123 * V_124 = NULL ;
for ( V_78 = 0 ; V_78 < V_28 -> V_82 ; V_78 ++ ) {
if ( ! V_28 -> V_83 [ V_78 ] . V_84 )
continue;
for ( V_99 = 0 ; V_99 < V_28 -> V_106 ; V_99 ++ )
if ( V_28 -> V_83 [ V_78 ] . V_107 [ V_99 ] . V_108 &&
V_28 -> V_83 [ V_78 ] . V_107 [ V_99 ] . V_108 -> V_109 [ 0 ] &&
V_28 -> V_83 [ V_78 ] . V_107 [ V_99 ] . V_108 -> V_109 [ 0 ] -> V_110 ) {
V_120 [ V_121 ++ ] = V_28 -> V_83 [ V_78 ] . V_107 [ V_99 ] .
V_108 -> V_125 ;
V_120 [ V_121 ++ ] = 0 ;
V_120 [ V_121 ++ ] = * ( V_28 -> V_83 [ V_78 ] . V_107 [ V_99 ] .
V_108 -> V_126 ) ;
V_120 [ V_121 ++ ] = V_28 -> V_83 [ V_78 ] .
V_107 [ V_99 ] . V_127 ;
V_120 [ V_121 ++ ] = V_28 -> V_83 [ V_78 ] .
V_107 [ V_99 ] . V_128 ;
V_120 [ V_121 ++ ] = V_28 -> V_83 [ V_78 ] .
V_107 [ V_99 ] . V_129 ;
V_120 [ V_121 ++ ] = V_28 -> V_83 [ V_78 ] .
V_107 [ V_99 ] . V_130 ;
V_120 [ V_121 ++ ] = V_28 -> V_83 [ V_78 ] .
V_107 [ V_99 ] . V_131 ;
}
}
for ( V_78 = 0 ; V_78 < V_28 -> V_82 ; V_78 ++ ) {
if ( ! V_28 -> V_83 [ V_78 ] . V_84 )
continue;
for ( V_99 = 0 ; V_99 < V_28 -> V_106 ; V_99 ++ )
if ( V_28 -> V_83 [ V_78 ] . V_107 [ V_99 ] . V_108 ) {
if ( V_28 -> V_83 [ V_78 ] . V_107 [ V_99 ] . V_108 -> V_109 [ 0 ] &&
V_28 -> V_83 [ V_78 ] . V_107 [ V_99 ] . V_108 ->
V_109 [ 0 ] -> V_110 ) {
V_109 = V_28 -> V_83 [ V_78 ] . V_107 [ V_99 ] .
V_108 -> V_109 [ 0 ] ;
V_120 [ V_121 ++ ] = V_109 -> V_110 -> V_132 ;
V_120 [ V_121 ++ ] = V_109 -> V_110 -> V_133 ;
V_120 [ V_121 ++ ] = V_109 -> V_110 ->
V_134 ;
V_120 [ V_121 ++ ] = V_109 -> V_110 ->
V_135 ;
V_120 [ V_121 ++ ] = V_109 -> V_110 -> V_136 ;
V_120 [ V_121 ++ ] = V_109 -> V_125 ;
V_120 [ V_121 ++ ] = V_109 -> V_137 ;
}
if ( V_28 -> V_83 [ V_78 ] . V_107 [ V_99 ] . V_108 -> V_109 [ 1 ] &&
V_28 -> V_83 [ V_78 ] . V_107 [ V_99 ] . V_108 ->
V_109 [ 1 ] -> V_110 ) {
V_109 = V_28 -> V_83 [ V_78 ] . V_107 [ V_99 ] .
V_108 -> V_109 [ 1 ] ;
V_120 [ V_121 ++ ] = V_109 -> V_110 -> V_132 ;
V_120 [ V_121 ++ ] = V_109 -> V_110 -> V_133 ;
V_120 [ V_121 ++ ] = V_109 -> V_110 ->
V_134 ;
V_120 [ V_121 ++ ] = V_109 -> V_110 ->
V_135 ;
V_120 [ V_121 ++ ] = V_109 -> V_110 -> V_136 ;
V_120 [ V_121 ++ ] = V_109 -> V_125 ;
V_120 [ V_121 ++ ] = V_109 -> V_137 ;
}
}
}
for ( V_78 = 0 ; V_78 < V_28 -> V_88 ; V_78 ++ ) {
if ( ! V_28 -> V_89 [ V_78 ] . V_90 )
continue;
for ( V_99 = 0 ; V_99 < V_28 -> V_111 ; V_99 ++ )
if ( V_28 -> V_89 [ V_78 ] . V_124 [ V_99 ] &&
V_28 -> V_89 [ V_78 ] . V_124 [ V_99 ] -> V_138 ) {
V_124 = V_28 -> V_89 [ V_78 ] . V_124 [ V_99 ] ;
V_120 [ V_121 ++ ] = V_124 -> V_138 -> V_139 ;
V_120 [ V_121 ++ ] = V_124 -> V_138 -> V_140 ;
V_120 [ V_121 ++ ] = V_124 -> V_125 ;
V_120 [ V_121 ++ ] = V_124 -> V_137 ;
V_120 [ V_121 ++ ] = * ( V_124 -> V_141 ) ;
}
}
return V_121 ;
}
static void
F_46 ( struct V_1 * V_2 , struct V_142 * V_143 ,
T_3 * V_120 )
{
struct V_28 * V_28 = F_6 ( V_2 ) ;
int V_78 , V_99 , V_121 = 0 ;
unsigned long V_31 ;
struct V_144 V_145 ;
T_3 * V_146 ;
T_1 V_101 ;
F_17 ( & V_28 -> V_64 ) ;
if ( F_44 ( V_2 ) != V_143 -> V_147 ) {
F_24 ( & V_28 -> V_64 ) ;
return;
}
F_9 ( & V_28 -> V_37 , V_31 ) ;
memset ( & V_145 , 0 , sizeof( V_145 ) ) ;
F_47 ( V_28 , & V_145 ) ;
F_48 ( V_28 , & V_145 ) ;
V_120 [ V_121 ++ ] = V_145 . V_132 ;
V_120 [ V_121 ++ ] = V_145 . V_139 ;
V_120 [ V_121 ++ ] = V_145 . V_133 ;
V_120 [ V_121 ++ ] = V_145 . V_140 ;
V_120 [ V_121 ++ ] = V_145 . V_148 ;
V_120 [ V_121 ++ ] = V_145 . V_149 ;
V_120 [ V_121 ++ ] = V_145 . V_150 ;
V_120 [ V_121 ++ ] = V_145 . V_151 ;
V_120 [ V_121 ++ ] = V_145 . V_152 ;
V_120 [ V_121 ++ ] = V_145 . V_153 ;
V_120 [ V_121 ++ ] = V_145 . V_154 ;
V_120 [ V_121 ++ ] = V_145 . V_155 ;
V_120 [ V_121 ++ ] = V_145 . V_156 ;
V_120 [ V_121 ++ ] = V_145 . V_157 ;
V_28 -> V_143 . V_158 . V_159 = V_159 ( V_2 ) ;
V_146 = ( T_3 * ) & V_28 -> V_143 . V_158 ;
for ( V_78 = 0 ; V_78 < sizeof( struct V_160 ) / sizeof( T_3 ) ; V_78 ++ )
V_120 [ V_121 ++ ] = V_146 [ V_78 ] ;
V_146 = ( T_3 * ) & V_28 -> V_143 . V_161 -> V_162 ;
for ( V_78 = 0 ;
V_78 < F_49 ( struct V_163 , V_164 [ 0 ] ) /
sizeof( T_3 ) ;
V_78 ++ )
V_120 [ V_121 ++ ] = V_146 [ V_78 ] ;
V_101 = F_42 ( & V_28 -> V_38 ) ;
for ( V_78 = 0 ; V_101 ; V_78 ++ ) {
if ( V_101 & 1 ) {
V_146 = ( T_3 * ) & V_28 -> V_143 . V_161 ->
V_162 . V_165 [ V_78 ] ;
for ( V_99 = 0 ; V_99 < sizeof( struct V_166 ) /
sizeof( T_3 ) ; V_99 ++ )
V_120 [ V_121 ++ ] = V_146 [ V_99 ] ;
}
V_101 >>= 1 ;
}
V_101 = F_43 ( & V_28 -> V_38 ) ;
for ( V_78 = 0 ; V_101 ; V_78 ++ ) {
if ( V_101 & 1 ) {
V_146 = ( T_3 * ) & V_28 -> V_143 . V_161 ->
V_162 . V_164 [ V_78 ] ;
for ( V_99 = 0 ; V_99 < sizeof( struct V_167 ) /
sizeof( T_3 ) ; V_99 ++ )
V_120 [ V_121 ++ ] = V_146 [ V_99 ] ;
}
V_101 >>= 1 ;
}
V_121 = F_45 ( V_28 , V_120 , V_121 ) ;
F_11 ( & V_28 -> V_37 , V_31 ) ;
F_24 ( & V_28 -> V_64 ) ;
}
static int
F_50 ( struct V_1 * V_2 , int V_168 )
{
switch ( V_168 ) {
case V_102 :
return F_44 ( V_2 ) ;
default:
return - V_25 ;
}
}
static T_1
F_51 ( struct V_28 * V_28 , T_1 V_169 ,
T_1 * V_170 )
{
struct V_171 * V_172 ;
struct V_173 V_174 ;
T_1 V_78 , V_175 = 0 , V_176 ;
unsigned long V_31 = 0 ;
V_172 = F_8 ( sizeof( struct V_171 ) , V_36 ) ;
if ( ! V_172 )
return 0 ;
V_174 . V_28 = V_28 ;
V_174 . V_177 = 0 ;
F_52 ( & V_174 . V_178 ) ;
F_9 ( & V_28 -> V_37 , V_31 ) ;
V_176 = F_53 ( & V_28 -> V_38 . V_179 , V_172 ,
V_180 , & V_174 ) ;
if ( V_176 != V_181 ) {
F_11 ( & V_28 -> V_37 , V_31 ) ;
F_12 ( V_172 ) ;
return 0 ;
}
F_11 ( & V_28 -> V_37 , V_31 ) ;
F_54 ( & V_174 . V_178 ) ;
V_176 = V_174 . V_177 ;
if ( V_176 == V_181 ) {
for ( V_78 = 0 ; V_78 < V_172 -> V_182 ; V_78 ++ ) {
if ( V_169 >= V_172 -> V_183 [ V_78 ] . V_184 &&
V_169 < ( V_172 -> V_183 [ V_78 ] . V_184 +
V_172 -> V_183 [ V_78 ] . V_185 ) ) {
V_175 = V_172 -> V_183 [ V_78 ] . V_186 ;
* V_170 = V_172 -> V_183 [ V_78 ] . V_184 ;
break;
}
}
}
F_12 ( V_172 ) ;
return V_175 ;
}
static int
F_55 ( struct V_1 * V_2 )
{
return V_187 ;
}
static int
F_56 ( struct V_1 * V_2 , struct V_188 * V_189 ,
T_2 * V_190 )
{
struct V_28 * V_28 = F_6 ( V_2 ) ;
struct V_173 V_174 ;
T_1 V_175 = 0 , V_170 = 0 ;
unsigned long V_31 = 0 ;
int V_176 = 0 ;
V_189 -> V_191 = V_28 -> V_45 -> V_192 | ( V_28 -> V_45 -> V_193 << 16 ) ;
V_175 = F_51 ( V_28 ,
V_189 -> V_169 , & V_170 ) ;
if ( V_175 == 0 )
return - V_194 ;
V_174 . V_28 = V_28 ;
V_174 . V_177 = 0 ;
F_52 ( & V_174 . V_178 ) ;
F_9 ( & V_28 -> V_37 , V_31 ) ;
V_176 = F_57 ( & V_28 -> V_38 . V_179 , V_175 ,
V_28 -> V_195 , V_190 , V_189 -> V_196 ,
V_189 -> V_169 - V_170 ,
V_180 , & V_174 ) ;
if ( V_176 != V_181 ) {
F_11 ( & V_28 -> V_37 , V_31 ) ;
goto V_197;
}
F_11 ( & V_28 -> V_37 , V_31 ) ;
F_54 ( & V_174 . V_178 ) ;
V_176 = V_174 . V_177 ;
V_197:
return V_176 ;
}
static int
F_58 ( struct V_1 * V_2 , struct V_188 * V_189 ,
T_2 * V_190 )
{
struct V_28 * V_28 = F_6 ( V_2 ) ;
struct V_173 V_174 ;
T_1 V_175 = 0 , V_170 = 0 ;
unsigned long V_31 = 0 ;
int V_176 = 0 ;
if ( V_189 -> V_191 != ( V_28 -> V_45 -> V_192 |
( V_28 -> V_45 -> V_193 << 16 ) ) )
return - V_63 ;
V_175 = F_51 ( V_28 ,
V_189 -> V_169 , & V_170 ) ;
if ( V_175 == 0 )
return - V_194 ;
V_174 . V_28 = V_28 ;
V_174 . V_177 = 0 ;
F_52 ( & V_174 . V_178 ) ;
F_9 ( & V_28 -> V_37 , V_31 ) ;
V_176 = F_59 ( & V_28 -> V_38 . V_179 , V_175 ,
V_28 -> V_195 , V_190 , V_189 -> V_196 ,
V_189 -> V_169 - V_170 ,
V_180 , & V_174 ) ;
if ( V_176 != V_181 ) {
F_11 ( & V_28 -> V_37 , V_31 ) ;
goto V_197;
}
F_11 ( & V_28 -> V_37 , V_31 ) ;
F_54 ( & V_174 . V_178 ) ;
V_176 = V_174 . V_177 ;
V_197:
return V_176 ;
}
static int
F_60 ( struct V_1 * V_2 , struct V_198 * V_199 )
{
struct V_28 * V_28 = F_6 ( V_2 ) ;
struct V_173 V_174 ;
const struct V_200 * V_201 ;
int V_176 = 0 ;
V_176 = F_61 ( & V_201 , V_199 -> V_202 , & V_28 -> V_45 -> V_203 ) ;
if ( V_176 ) {
F_62 ( V_2 , L_43 , V_199 -> V_202 ) ;
goto V_204;
}
V_174 . V_28 = V_28 ;
V_174 . V_177 = 0 ;
F_52 ( & V_174 . V_178 ) ;
F_63 ( & V_28 -> V_37 ) ;
V_176 = F_59 ( & V_28 -> V_38 . V_179 , V_205 ,
V_28 -> V_195 , ( T_2 * ) V_201 -> V_202 , V_201 -> V_206 , 0 ,
V_180 , & V_174 ) ;
if ( V_176 != V_181 ) {
F_64 ( V_2 , L_44 , V_176 ) ;
V_176 = - V_207 ;
F_65 ( & V_28 -> V_37 ) ;
goto V_204;
}
F_65 ( & V_28 -> V_37 ) ;
F_54 ( & V_174 . V_178 ) ;
if ( V_174 . V_177 != V_181 ) {
V_176 = - V_207 ;
F_64 ( V_2 ,
L_45 ,
V_174 . V_177 ) ;
}
V_204:
F_66 ( V_201 ) ;
return V_176 ;
}
void
F_67 ( struct V_1 * V_2 )
{
V_2 -> V_208 = & V_209 ;
}
