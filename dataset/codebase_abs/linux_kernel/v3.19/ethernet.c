static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_3 / 2 ) ;
if ( ! F_3 ( & V_4 ) )
F_4 ( V_5 ,
& V_6 , V_7 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_6 ( V_2 ,
struct V_8 ,
V_10 . V_2 ) ;
if ( V_9 -> V_11 )
V_9 -> V_11 ( V_12 [ V_9 -> V_13 ] ) ;
V_12 [ V_9 -> V_13 ] -> V_14 -> V_15 (
V_12 [ V_9 -> V_13 ] ) ;
if ( ! F_3 ( & V_4 ) )
F_4 ( V_5 ,
& V_9 -> V_10 , V_7 ) ;
}
static void F_7 ( void )
{
F_8 () ;
F_9 ( V_16 , V_17 ,
V_3 ) ;
F_9 ( V_18 , V_19 ,
V_3 ) ;
if ( V_20 != V_16 )
F_9 ( V_20 ,
V_21 , 128 ) ;
if ( V_22 )
F_10 ( V_3 / 4 ,
V_3 / 8 ) ;
}
int F_11 ( void * V_23 )
{
T_1 * V_2 = V_23 ;
int V_24 = V_2 -> V_25 . V_26 . V_27 ;
union V_28 V_29 = V_2 -> V_30 ;
while ( V_24 -- ) {
union V_28 V_31 = * (union V_28 * )
F_12 ( V_29 . V_26 . V_32 - 8 ) ;
if ( F_13 ( ! V_29 . V_26 . V_33 ) )
F_14 ( F_15 ( V_29 ) ,
V_29 . V_26 . V_34 ,
F_16 ( V_17 /
128 ) ) ;
V_29 = V_31 ;
}
F_14 ( V_2 , V_18 , F_16 ( 1 ) ) ;
return 0 ;
}
static struct V_35 * F_17 ( struct V_36 * V_37 )
{
T_2 V_38 ;
T_3 V_39 ;
struct V_8 * V_9 = F_18 ( V_37 ) ;
if ( V_9 -> V_13 < V_40 ) {
if ( F_19 () ) {
memset ( & V_38 , 0 , sizeof( V_38 ) ) ;
memset ( & V_39 , 0 , sizeof( V_39 ) ) ;
} else {
F_20 ( V_9 -> V_13 , 1 , & V_38 ) ;
F_21 ( V_9 -> V_13 , 1 , & V_39 ) ;
}
V_9 -> V_41 . V_42 += V_38 . V_43 ;
V_9 -> V_41 . V_44 += V_39 . V_45 ;
V_9 -> V_41 . V_46 += V_38 . V_47 ;
V_9 -> V_41 . V_48 += V_39 . V_49 ;
V_9 -> V_41 . V_50 += V_38 . V_51 ;
V_9 -> V_41 . V_52 += V_38 . V_53 ;
V_9 -> V_41 . V_54 += V_38 . V_55 ;
#ifdef F_22
F_23 ( V_38 . V_56 ,
( V_57 * ) & V_9 -> V_41 . V_58 ) ;
#else
F_24 ( V_38 . V_56 ,
( V_59 * ) & V_9 -> V_41 . V_58 ) ;
#endif
}
return & V_9 -> V_41 ;
}
static int F_25 ( struct V_36 * V_37 , int V_60 )
{
struct V_8 * V_9 = F_18 ( V_37 ) ;
int V_61 = F_26 ( V_9 -> V_13 ) ;
int V_62 = F_27 ( V_9 -> V_13 ) ;
#if F_28 ( V_63 ) || F_28 ( V_64 )
int V_65 = 4 ;
#else
int V_65 = 0 ;
#endif
if ( ( V_60 + 14 + 4 + V_65 < 64 )
|| ( V_60 + 14 + 4 + V_65 > 65392 ) ) {
F_29 ( L_1 ,
64 - 14 - 4 - V_65 , 65392 - 14 - 4 - V_65 ) ;
return - V_66 ;
}
V_37 -> V_67 = V_60 ;
if ( ( V_61 < 2 )
&& ( F_30 ( V_61 ) !=
V_68 ) ) {
int V_69 = V_60 + 14 + 4 + V_65 ;
if ( F_31 ( V_70 )
|| F_31 ( V_71 ) ) {
F_32 ( F_33 ( V_62 , V_61 ) ,
V_69 ) ;
} else {
union V_72 V_73 ;
V_73 . V_74 = 0 ;
V_73 . V_26 . V_75 = 64 ;
V_73 . V_26 . V_76 = V_69 ;
F_32 ( F_34 ( V_61 ) ,
V_73 . V_74 ) ;
}
F_32 ( F_35 ( V_62 , V_61 ) ,
( V_69 + 7 ) & ~ 7u ) ;
}
return 0 ;
}
static void F_36 ( struct V_36 * V_37 )
{
union V_77 V_78 ;
struct V_8 * V_9 = F_18 ( V_37 ) ;
int V_61 = F_26 ( V_9 -> V_13 ) ;
int V_62 = F_27 ( V_9 -> V_13 ) ;
if ( ( V_61 < 2 )
&& ( F_30 ( V_61 ) !=
V_68 ) ) {
union V_79 V_80 ;
V_80 . V_74 = 0 ;
V_80 . V_26 . V_81 = 1 ;
if ( ! F_37 ( V_37 ) || ( V_37 -> V_82 & V_83 ) ||
( V_37 -> V_82 & V_84 ) )
V_80 . V_26 . V_85 = 2 ;
else
V_80 . V_26 . V_85 = 1 ;
if ( V_37 -> V_82 & V_84 )
V_80 . V_26 . V_86 = 0 ;
else
V_80 . V_26 . V_86 = 1 ;
V_78 . V_74 =
F_38 ( F_39 ( V_62 , V_61 ) ) ;
F_32 ( F_39 ( V_62 , V_61 ) ,
V_78 . V_74 & ~ 1ull ) ;
F_32 ( F_40 ( V_62 , V_61 ) ,
V_80 . V_74 ) ;
if ( V_37 -> V_82 & V_84 )
F_32 ( F_41
( V_62 , V_61 ) , 0 ) ;
else
F_32 ( F_41
( V_62 , V_61 ) , 1 ) ;
F_32 ( F_39 ( V_62 , V_61 ) ,
V_78 . V_74 ) ;
}
}
static int F_42 ( struct V_36 * V_37 )
{
struct V_8 * V_9 = F_18 ( V_37 ) ;
union V_77 V_78 ;
int V_61 = F_26 ( V_9 -> V_13 ) ;
int V_62 = F_27 ( V_9 -> V_13 ) ;
if ( ( V_61 < 2 )
&& ( F_30 ( V_61 ) !=
V_68 ) ) {
int V_33 ;
T_4 * V_87 = V_37 -> V_88 ;
T_5 V_89 = 0 ;
for ( V_33 = 0 ; V_33 < 6 ; V_33 ++ )
V_89 = ( V_89 << 8 ) | ( T_5 ) V_87 [ V_33 ] ;
V_78 . V_74 =
F_38 ( F_39 ( V_62 , V_61 ) ) ;
F_32 ( F_39 ( V_62 , V_61 ) ,
V_78 . V_74 & ~ 1ull ) ;
F_32 ( F_43 ( V_62 , V_61 ) , V_89 ) ;
F_32 ( F_44 ( V_62 , V_61 ) ,
V_87 [ 0 ] ) ;
F_32 ( F_45 ( V_62 , V_61 ) ,
V_87 [ 1 ] ) ;
F_32 ( F_46 ( V_62 , V_61 ) ,
V_87 [ 2 ] ) ;
F_32 ( F_47 ( V_62 , V_61 ) ,
V_87 [ 3 ] ) ;
F_32 ( F_48 ( V_62 , V_61 ) ,
V_87 [ 4 ] ) ;
F_32 ( F_49 ( V_62 , V_61 ) ,
V_87 [ 5 ] ) ;
F_36 ( V_37 ) ;
F_32 ( F_39 ( V_62 , V_61 ) ,
V_78 . V_74 ) ;
}
return 0 ;
}
static int F_50 ( struct V_36 * V_37 , void * V_32 )
{
int V_90 = F_51 ( V_37 , V_32 ) ;
if ( V_90 )
return V_90 ;
return F_42 ( V_37 ) ;
}
int F_52 ( struct V_36 * V_37 )
{
struct V_8 * V_9 = F_18 ( V_37 ) ;
const T_6 * V_89 = NULL ;
if ( V_9 -> V_91 )
V_89 = F_53 ( V_9 -> V_91 ) ;
if ( V_89 )
F_54 ( V_37 -> V_88 , V_89 ) ;
else
F_55 ( V_37 ) ;
if ( ( V_92 != - 1 )
&& ( V_93 || strstr ( V_94 , V_37 -> V_95 ) ) )
V_9 -> V_96 = - 1 ;
if ( V_9 -> V_96 != - 1 ) {
V_37 -> V_97 |= V_98 ;
if ( V_99 )
V_37 -> V_97 |= V_100 ;
}
V_37 -> V_97 |= V_101 ;
V_37 -> V_102 = & V_103 ;
F_42 ( V_37 ) ;
V_37 -> V_14 -> V_104 ( V_37 , V_37 -> V_67 ) ;
memset ( V_37 -> V_14 -> V_15 ( V_37 ) , 0 ,
sizeof( struct V_35 ) ) ;
return 0 ;
}
void F_56 ( struct V_36 * V_37 )
{
struct V_8 * V_9 = F_18 ( V_37 ) ;
if ( V_9 -> V_105 )
F_57 ( V_9 -> V_105 ) ;
}
static struct V_106 * F_58 (
const struct V_106 * V_107 , int V_108 )
{
struct V_106 * V_109 = NULL ;
int V_110 ;
const T_7 * V_32 ;
for (; ; ) {
V_109 = F_59 ( V_107 , V_109 ) ;
if ( ! V_109 )
break;
V_32 = F_60 ( V_109 , L_2 , & V_110 ) ;
if ( V_32 && ( F_61 ( * V_32 ) == V_108 ) )
break;
}
return V_109 ;
}
static struct V_106 * F_62 ( struct V_106 * V_111 ,
int V_61 , int V_13 )
{
struct V_106 * V_112 , * V_113 ;
V_112 = F_58 ( V_111 , V_61 ) ;
if ( ! V_112 )
return NULL ;
V_113 = F_58 ( V_112 , V_13 ) ;
F_63 ( V_112 ) ;
return V_113 ;
}
static int F_64 ( struct V_114 * V_115 )
{
int V_116 ;
int V_61 ;
int V_117 = V_118 ;
int V_119 ;
struct V_106 * V_111 ;
F_65 () ;
F_66 ( L_3 , V_120 ) ;
V_111 = V_115 -> V_37 . V_91 ;
if ( ! V_111 ) {
F_29 ( L_4 ) ;
return - V_66 ;
}
V_5 = F_67 ( L_5 ) ;
if ( V_5 == NULL ) {
F_29 ( L_6 ) ;
return - V_121 ;
}
F_7 () ;
F_68 () ;
V_116 = F_69 () ;
for ( V_61 = 0 ; V_61 < V_116 ; V_61 ++ ) {
int V_122 = F_70 ( V_61 ) ;
int V_13 ;
for ( V_13 = F_71 ( V_61 , 0 ) ;
V_13 < F_71 ( V_61 , V_122 ) ;
V_13 ++ ) {
union V_123 V_124 ;
V_124 . V_74 =
F_38 ( F_72 ( V_13 ) ) ;
V_124 . V_26 . V_125 = V_126 ;
F_32 ( F_72 ( V_13 ) ,
V_124 . V_74 ) ;
}
}
F_73 () ;
memset ( V_12 , 0 , sizeof( V_12 ) ) ;
F_74 ( V_118 , 0 ) ;
F_74 ( V_127 , 0 ) ;
if ( ( V_92 != - 1 ) ) {
struct V_36 * V_37 ;
F_75 ( L_7 ) ;
V_37 = F_76 ( sizeof( struct V_8 ) ) ;
if ( V_37 ) {
struct V_8 * V_9 = F_18 ( V_37 ) ;
V_37 -> V_14 = & V_128 ;
V_9 -> V_129 = V_130 ;
V_9 -> V_13 = V_40 ;
V_9 -> V_96 = - 1 ;
strcpy ( V_37 -> V_95 , L_8 ) ;
for ( V_119 = 0 ; V_119 < 16 ; V_119 ++ )
F_77 ( & V_9 -> V_131 [ V_119 ] ) ;
if ( F_78 ( V_37 ) < 0 ) {
F_29 ( L_9 ) ;
F_79 ( V_37 ) ;
} else {
V_12 [ V_40 ] = V_37 ;
F_75 ( L_10 ,
V_37 -> V_95 , V_92 ,
V_126 ) ;
}
} else {
F_29 ( L_11 ) ;
}
}
V_116 = F_69 () ;
for ( V_61 = 0 ; V_61 < V_116 ; V_61 ++ ) {
T_8 V_129 =
F_30 ( V_61 ) ;
int V_122 = F_70 ( V_61 ) ;
int V_13 ;
int V_132 ;
for ( V_132 = 0 ,
V_13 = F_71 ( V_61 , 0 ) ;
V_13 < F_71 ( V_61 , V_122 ) ;
V_132 ++ , V_13 ++ ) {
struct V_8 * V_9 ;
struct V_36 * V_37 =
F_76 ( sizeof( struct V_8 ) ) ;
if ( ! V_37 ) {
F_29 ( L_12 ,
V_13 ) ;
continue;
}
V_9 = F_18 ( V_37 ) ;
V_9 -> V_133 = V_37 ;
V_9 -> V_91 = F_62 ( V_111 , V_61 ,
V_132 ) ;
F_80 ( & V_9 -> V_10 ,
F_5 ) ;
V_9 -> V_129 = V_129 ;
V_9 -> V_13 = V_13 ;
V_9 -> V_96 = F_81 ( V_9 -> V_13 ) ;
V_9 -> V_117 = V_117 - F_82 ( V_13 ) * 4 ;
for ( V_119 = 0 ; V_119 < 16 ; V_119 ++ )
F_77 ( & V_9 -> V_131 [ V_119 ] ) ;
for ( V_119 = 0 ; V_119 < F_82 ( V_13 ) ;
V_119 ++ )
F_74 ( V_9 -> V_117 + V_119 * 4 , 0 ) ;
switch ( V_9 -> V_129 ) {
case V_130 :
case V_134 :
case V_135 :
break;
case V_136 :
V_37 -> V_14 = & V_137 ;
strcpy ( V_37 -> V_95 , L_13 ) ;
break;
case V_138 :
V_37 -> V_14 = & V_139 ;
strcpy ( V_37 -> V_95 , L_14 ) ;
break;
case V_140 :
V_37 -> V_14 = & V_137 ;
strcpy ( V_37 -> V_95 , L_15 ) ;
break;
case V_141 :
V_37 -> V_14 = & V_142 ;
strcpy ( V_37 -> V_95 , L_16 ) ;
break;
case V_68 :
V_37 -> V_14 = & V_143 ;
strcpy ( V_37 -> V_95 , L_17 ) ;
break;
case V_144 :
case V_145 :
V_37 -> V_14 = & V_146 ;
strcpy ( V_37 -> V_95 , L_16 ) ;
break;
}
if ( ! V_37 -> V_14 ) {
F_79 ( V_37 ) ;
} else if ( F_78 ( V_37 ) < 0 ) {
F_29 ( L_18 ,
V_61 , V_9 -> V_13 ) ;
F_79 ( V_37 ) ;
} else {
V_12 [ V_9 -> V_13 ] = V_37 ;
V_117 -=
F_82 ( V_9 -> V_13 ) *
sizeof( V_147 ) ;
F_4 ( V_5 ,
& V_9 -> V_10 , V_7 ) ;
}
}
}
F_83 () ;
F_84 () ;
V_148 = 150 * ( F_85 () / 1000000 ) ;
F_4 ( V_5 , & V_6 , V_7 ) ;
return 0 ;
}
static int F_86 ( struct V_114 * V_115 )
{
int V_13 ;
F_32 ( F_87 ( V_126 ) , 0 ) ;
F_88 () ;
F_89 ( V_149 + V_126 , V_12 ) ;
F_90 ( & V_4 ) ;
F_91 ( & V_6 ) ;
F_92 () ;
F_93 () ;
F_94 () ;
for ( V_13 = 0 ; V_13 < V_150 ; V_13 ++ ) {
if ( V_12 [ V_13 ] ) {
struct V_36 * V_37 = V_12 [ V_13 ] ;
struct V_8 * V_9 = F_18 ( V_37 ) ;
F_91 ( & V_9 -> V_10 ) ;
F_95 ( V_37 ) ;
F_96 ( V_37 ) ;
F_79 ( V_37 ) ;
V_12 [ V_13 ] = NULL ;
}
}
F_97 ( V_5 ) ;
F_98 () ;
F_99 () ;
F_100 ( V_16 , V_17 ,
V_3 ) ;
F_100 ( V_18 , V_19 ,
V_3 ) ;
if ( V_20 != V_16 )
F_100 ( V_20 ,
V_21 , 128 ) ;
return 0 ;
}
