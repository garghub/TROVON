static T_1
F_1 ( T_2 V_1 , enum V_2 V_3 )
{
T_3 V_4 = 0 ;
T_3 V_5 = 0 ;
struct V_6 * V_7 = NULL ;
if ( V_1 < V_8 || V_1 > V_9 )
V_1 = V_8 ;
switch ( V_3 ) {
case V_10 :
V_7 = V_11 ;
V_5 = F_2 ( V_11 ) ;
break;
case V_12 :
V_7 = V_13 ;
V_5 = F_2 ( V_13 ) ;
break;
default:
F_3 () ;
break;
}
while ( V_4 < V_5 && V_1 < V_7 [ V_4 ] . V_14 )
V_4 ++ ;
V_4 = F_4 ( V_4 , V_5 - 1 ) ;
return V_7 [ V_4 ] . V_4 ;
}
static void
F_5 ( struct V_15 * V_16 )
{
V_16 -> V_17 = 0 ;
V_16 -> V_18 = 0 ;
V_16 -> V_19 = - 1 ;
V_16 -> V_20 = 0 ;
V_16 -> V_21 = V_22 ;
V_16 -> V_23 = 0 ;
}
static int
F_6 ( struct V_24 * V_25 )
{
int V_26 = 0 ;
int V_27 ;
unsigned long V_28 ;
struct V_29 * T_4 V_30 = V_25 -> T_4 ;
for ( V_27 = 0 ; V_27 < V_31 ; V_27 ++ ) {
if ( ! V_25 -> V_16 [ V_27 ] . V_20 )
continue;
F_7 ( & V_25 -> V_32 , V_28 ) ;
if ( F_8 ( V_33 , V_25 -> V_16 [ V_27 ] . V_23 + V_34 ) ) {
F_9 ( L_1 L_2 ,
V_25 -> V_16 [ V_27 ] . V_20 , V_27 ) ;
F_5 ( & V_25 -> V_16 [ V_27 ] ) ;
} else
V_26 ++ ;
F_10 ( & V_25 -> V_32 , V_28 ) ;
}
return V_26 ;
}
static void
F_11 ( unsigned long V_17 )
{
struct V_24 * V_25 = ( void * ) V_17 ;
struct V_29 * T_4 V_30 = V_25 -> T_4 ;
int V_26 = 0 ;
unsigned long V_28 ;
T_3 V_35 , V_36 , V_37 ;
F_9 ( L_3 ) ;
V_26 = F_6 ( V_25 ) ;
F_7 ( & V_25 -> V_32 , V_28 ) ;
V_35 = ( V_25 -> V_38 - V_25 -> V_39 ) + 1 ;
V_25 -> V_39 = V_25 -> V_38 + 1 ;
if ( V_26 ) {
V_36 =
F_12 ( V_33 - V_25 -> V_40 ) ;
F_9 ( L_4 , V_35 , V_36 ) ;
if ( V_36 )
V_37 = ( V_35 * 1000 ) / V_36 ;
else
V_37 = 0 ;
if ( V_37 ) {
V_36 = ( V_41 * 1000 ) / V_37 ;
if ( V_36 < V_42 )
V_36 = V_42 ;
else if ( V_36 > V_43 )
V_36 = V_43 ;
} else
V_36 = V_43 ;
V_25 -> V_44 = F_13 ( V_36 ) ;
F_9 ( L_5 , V_36 ,
V_35 ) ;
F_14 ( & V_25 -> V_45 ,
V_33 + V_25 -> V_44 ) ;
V_25 -> V_40 = V_33 ;
} else {
V_25 -> V_44 = V_46 ;
V_25 -> V_47 = 0 ;
}
V_25 -> V_48 = V_33 ;
F_10 ( & V_25 -> V_32 , V_28 ) ;
F_9 ( L_6 ) ;
}
static void
F_15 ( struct V_24 * V_25 ,
struct V_15 * V_16 , int V_49 ,
int V_50 , int V_4 )
{
unsigned long V_28 ;
T_2 V_51 ;
struct V_29 * T_4 V_30 = V_25 -> T_4 ;
if ( ! V_50 ) {
F_9 ( L_7 ) ;
return;
}
F_7 ( & V_25 -> V_32 , V_28 ) ;
while ( V_50 > 0 ) {
if ( V_16 -> V_20 >= V_52 ) {
V_16 -> V_20 = V_52 - 1 ;
if ( V_16 -> V_17 & ( 1ULL << ( V_52 - 1 ) ) ) {
V_16 -> V_17 &= ~ ( 1ULL << ( V_52 - 1 ) ) ;
V_16 -> V_18 -- ;
}
}
V_16 -> V_20 ++ ;
V_16 -> V_17 <<= 1 ;
if ( V_49 > 0 ) {
V_16 -> V_18 ++ ;
V_16 -> V_17 |= 0x1 ;
V_49 -- ;
}
V_50 -- ;
}
if ( V_16 -> V_20 > 0 )
V_16 -> V_19 =
128 * ( 100 * V_16 -> V_18 ) / V_16 -> V_20 ;
else
V_16 -> V_19 = V_22 ;
V_51 = V_16 -> V_20 - V_16 -> V_18 ;
if ( V_51 >= V_53 ||
V_16 -> V_18 >= V_54 )
V_16 -> V_21 =
( ( V_16 -> V_19 * V_25 -> V_55 [ V_4 ] +
64 ) / 128 ) ;
else
V_16 -> V_21 = V_22 ;
V_16 -> V_23 = V_33 ;
F_10 ( & V_25 -> V_32 , V_28 ) ;
}
void
F_16 ( struct V_29 * T_4 , struct V_56 * V_57 , T_1 V_58 )
{
struct V_59 * V_60 = T_4 -> V_60 ;
struct V_61 * V_62 = & T_4 -> V_60 -> V_62 ;
struct V_63 * V_64 ;
struct V_24 * V_25 ;
struct V_65 * V_66 ;
int V_27 ;
F_17 ( L_3 ) ;
if ( V_58 == T_4 -> V_67 . V_68 )
goto V_69;
V_64 = (struct V_63 * ) V_57 -> V_70 ;
V_25 = & V_64 -> V_25 ;
V_66 = V_60 -> V_71 -> V_72 [ V_62 -> V_73 . V_74 -> V_3 ] ;
V_25 -> T_4 = T_4 ;
V_25 -> V_75 = V_76 ;
V_25 -> V_55 = V_77 ;
V_25 -> V_40 = V_33 ;
V_25 -> V_48 = V_33 ;
V_25 -> V_44 = V_46 ;
V_25 -> V_39 = 0 ;
V_25 -> V_45 . V_17 = ( unsigned long ) V_25 ;
V_25 -> V_45 . V_78 = F_11 ;
for ( V_27 = 0 ; V_27 < V_31 ; V_27 ++ )
F_5 ( & V_25 -> V_16 [ V_27 ] ) ;
for ( V_27 = V_66 -> V_79 - 1 ; V_27 >= 0 ; V_27 -- ) {
if ( V_57 -> V_80 [ V_66 -> V_3 ] & ( 1 << V_27 ) ) {
V_25 -> V_81 = V_27 ;
break;
}
}
T_4 -> V_82 . V_83 = V_57 -> V_80 [ V_66 -> V_3 ] ;
if ( V_66 -> V_3 == V_12 ) {
V_25 -> V_81 += V_84 ;
T_4 -> V_82 . V_83 <<= V_84 ;
}
V_69:
T_4 -> V_85 [ V_58 ] . V_86 &= ~ V_87 ;
F_17 ( L_6 ) ;
}
static void *
F_18 ( struct V_59 * V_60 , struct V_88 * V_89 )
{
return V_60 -> V_90 ;
}
static void
F_19 ( void * T_4 )
{
}
static void *
F_20 ( void * V_29 , struct V_56 * V_57 , T_5 V_91 )
{
struct V_24 * V_25 ;
struct V_63 * V_64 = ( void * ) V_57 -> V_70 ;
struct V_29 * T_4 V_30 = V_29 ;
F_9 ( L_3 ) ;
V_25 = & V_64 -> V_25 ;
F_21 ( & V_25 -> V_32 ) ;
F_22 ( & V_25 -> V_45 ) ;
F_9 ( L_6 ) ;
return V_25 ;
}
static void
F_23 ( void * V_29 , struct V_56 * V_57 , void * V_92 )
{
struct V_24 * V_25 = V_92 ;
F_24 ( & V_25 -> V_45 ) ;
}
static void
F_25 ( void * V_93 , struct V_65 * V_66 ,
struct V_56 * V_57 , void * V_92 ,
struct V_94 * V_95 )
{
T_6 V_50 = 0 , V_96 ;
int V_97 , V_98 , V_99 ;
unsigned long V_28 ;
struct V_29 * T_4 = (struct V_29 * ) V_93 ;
struct V_24 * V_25 = V_92 ;
struct V_100 * V_101 = F_26 ( V_95 ) ;
F_9 ( L_3 ) ;
V_50 = V_101 -> V_102 . V_103 [ 0 ] . V_104 ;
if ( V_50 > V_105 )
V_50 = V_105 ;
V_98 = V_66 -> V_106 [ V_101 -> V_102 . V_103 [ 0 ] . V_4 ] . V_107 ;
if ( V_98 < 0 || V_98 >= V_31 ) {
F_9 ( L_8 , V_98 ) ;
return;
}
if ( ! V_92 ) {
F_9 ( L_9 ) ;
return;
}
if ( ! V_25 -> T_4 ) {
F_9 ( L_10 ) ;
return;
}
V_25 -> V_38 ++ ;
V_97 = V_98 ;
V_99 = V_98 ;
while ( V_50 > 1 ) {
if ( ( V_50 - 1 ) < T_4 -> V_108 ) {
V_96 = ( V_50 - 1 ) ;
V_99 = V_97 ;
} else {
V_96 = T_4 -> V_108 ;
V_99 = F_27 ( T_4 , V_97 ) ;
}
F_15 ( V_25 , & V_25 -> V_16 [ V_97 ] , 0 ,
V_96 , V_97 ) ;
F_9 ( L_11 , V_97 ,
V_96 ) ;
V_50 -= V_96 ;
V_97 = V_99 ;
}
F_9 ( L_12 , V_99 ,
( V_101 -> V_28 & V_109 ) ? L_13 : L_14 ) ;
F_15 ( V_25 , & V_25 -> V_16 [ V_99 ] ,
V_101 -> V_28 & V_109 , 1 ,
V_99 ) ;
F_7 ( & V_25 -> V_32 , V_28 ) ;
if ( ! V_25 -> V_47 &&
F_8 ( V_33 , V_25 -> V_48 + V_25 -> V_44 ) ) {
V_25 -> V_40 = V_33 ;
V_25 -> V_47 = 1 ;
F_14 ( & V_25 -> V_45 ,
V_33 + V_25 -> V_44 ) ;
}
F_10 ( & V_25 -> V_32 , V_28 ) ;
F_9 ( L_6 ) ;
}
static T_7
F_28 ( struct V_24 * V_25 , T_1 V_4 , T_7 V_110 ,
enum V_2 V_3 )
{
T_1 V_111 = V_76 ;
T_1 V_112 = V_76 ;
struct V_29 * T_4 V_30 = V_25 -> T_4 ;
if ( F_29 ( V_3 == V_12 ) ) {
int V_27 ;
T_3 V_113 ;
V_27 = V_4 - 1 ;
for ( V_113 = ( 1 << V_27 ) ; V_27 >= 0 ; V_27 -- , V_113 >>= 1 ) {
if ( V_110 & V_113 ) {
V_112 = V_27 ;
break;
}
}
V_27 = V_4 + 1 ;
for ( V_113 = ( 1 << V_27 ) ; V_27 < V_31 ; V_27 ++ , V_113 <<= 1 ) {
if ( V_110 & V_113 ) {
V_111 = V_27 ;
break;
}
}
return ( V_111 << 8 ) | V_112 ;
}
V_112 = V_4 ;
while ( V_112 != V_76 ) {
if ( V_25 -> V_114 )
V_112 = V_115 [ V_112 ] . V_116 ;
else
V_112 = V_115 [ V_112 ] . V_117 ;
if ( V_112 == V_76 )
break;
if ( V_110 & ( 1 << V_112 ) )
break;
F_9 ( L_15 , V_112 ) ;
}
V_111 = V_4 ;
while ( V_111 != V_76 ) {
if ( V_25 -> V_114 )
V_111 = V_115 [ V_111 ] . V_118 ;
else
V_111 = V_115 [ V_111 ] . V_119 ;
if ( V_111 == V_76 )
break;
if ( V_110 & ( 1 << V_111 ) )
break;
F_9 ( L_16 , V_111 ) ;
}
return ( V_111 << 8 ) | V_112 ;
}
static void
F_30 ( void * V_120 , struct V_56 * V_57 , void * V_92 ,
struct V_121 * V_122 )
{
struct V_65 * V_66 = V_122 -> V_66 ;
struct V_94 * V_95 = V_122 -> V_95 ;
T_1 V_112 = V_76 ;
T_1 V_111 = V_76 ;
T_7 V_123 ;
int V_4 ;
struct V_24 * V_25 = V_92 ;
struct V_15 * V_16 = NULL ;
int V_124 = V_22 ;
int V_125 = V_22 ;
int V_126 = V_22 ;
T_3 V_51 ;
T_6 V_127 = 0 ;
unsigned long V_28 ;
T_7 V_110 ;
T_6 V_128 = - 1 ;
struct V_29 * T_4 V_30 = (struct V_29 * ) V_120 ;
struct V_100 * V_101 = F_26 ( V_95 ) ;
F_9 ( L_3 ) ;
if ( V_25 && ! V_25 -> T_4 ) {
F_9 ( L_17 ) ;
V_92 = NULL ;
}
if ( F_31 ( V_57 , V_92 , V_122 ) )
return;
V_110 = V_57 -> V_80 [ V_66 -> V_3 ] ;
V_128 = V_122 -> V_128 ;
if ( V_66 -> V_3 == V_12 && V_128 != - 1 )
V_128 += V_84 ;
if ( V_128 < 0 || V_128 >= V_129 )
V_128 = - 1 ;
V_4 = F_4 ( V_25 -> V_81 & 0xffff , V_31 - 1 ) ;
if ( V_66 -> V_3 == V_12 )
V_110 = V_110 << V_84 ;
F_7 ( & V_25 -> V_32 , V_28 ) ;
if ( V_25 -> V_75 != V_76 ) {
if ( V_25 -> V_75 < V_4 &&
( V_110 & ( 1 << V_25 -> V_75 ) ) )
V_4 = V_25 -> V_75 ;
V_25 -> V_75 = V_76 ;
}
if ( V_128 != - 1 && V_128 < V_4 ) {
if ( V_110 & ( 1 << V_128 ) )
V_4 = V_128 ;
}
V_16 = & ( V_25 -> V_16 [ V_4 ] ) ;
V_51 = V_16 -> V_20 - V_16 -> V_18 ;
if ( V_51 < V_53 &&
V_16 -> V_18 < V_54 ) {
F_10 ( & V_25 -> V_32 , V_28 ) ;
F_9 ( L_18
L_19
L_20 , V_4 , V_16 -> V_20 ,
V_16 -> V_18 ,
V_25 -> V_55 ? L_21 : L_22 ) ;
V_16 -> V_21 = V_22 ;
goto V_69;
}
V_124 = V_16 -> V_21 ;
V_123 =
F_28 ( V_25 , V_4 , V_110 , V_66 -> V_3 ) ;
V_112 = V_123 & 0xff ;
V_111 = ( V_123 >> 8 ) & 0xff ;
if ( V_128 != - 1 && V_128 < V_111 )
V_111 = V_76 ;
if ( V_112 != V_76 )
V_125 = V_25 -> V_16 [ V_112 ] . V_21 ;
if ( V_111 != V_76 )
V_126 = V_25 -> V_16 [ V_111 ] . V_21 ;
F_10 ( & V_25 -> V_32 , V_28 ) ;
V_127 = 0 ;
if ( V_16 -> V_19 < V_130 || ! V_124 ) {
F_9 ( L_23 ) ;
V_127 = - 1 ;
} else if ( V_125 == V_22 && V_126 == V_22 ) {
if ( V_111 != V_76 &&
V_16 -> V_19 >= V_131 )
V_127 = 1 ;
else if ( V_112 != V_76 )
V_127 = 0 ;
} else if ( V_125 != V_22 && V_126 != V_22
&& V_125 < V_124 && V_126 < V_124 ) {
F_9 ( L_24
L_25 , V_125 , V_126 , V_124 ) ;
V_127 = 0 ;
} else {
if ( V_126 != V_22 ) {
if ( V_126 > V_124 &&
V_16 -> V_19 >= V_131 )
V_127 = 1 ;
else {
F_9 ( L_26 ) ;
V_127 = 0 ;
}
} else if ( V_125 != V_22 ) {
if ( V_125 > V_124 ) {
F_9 ( L_27 ) ;
V_127 = - 1 ;
} else if ( V_16 -> V_19 >= V_131 ) {
V_127 = 1 ;
}
}
}
if ( V_127 == - 1 && V_112 != V_76 &&
( V_16 -> V_19 > V_132 ||
V_124 > 100 * V_25 -> V_55 [ V_112 ] ) )
V_127 = 0 ;
switch ( V_127 ) {
case - 1 :
if ( V_112 != V_76 )
V_4 = V_112 ;
break;
case 1 :
if ( V_111 != V_76 )
V_4 = V_111 ;
break;
case 0 :
default:
break;
}
F_9 ( L_28 , V_4 , V_127 ,
V_112 , V_111 ) ;
V_69:
if ( V_66 -> V_3 == V_12 ) {
if ( F_32 ( V_4 < V_84 ) )
V_4 = V_84 ;
V_25 -> V_81 = V_4 ;
V_101 -> V_133 . V_103 [ 0 ] . V_4 = V_4 - V_84 ;
} else {
V_25 -> V_81 = V_4 ;
V_101 -> V_133 . V_103 [ 0 ] . V_4 = V_25 -> V_81 ;
}
V_101 -> V_133 . V_103 [ 0 ] . V_104 = 1 ;
F_9 ( L_29 , V_4 ) ;
}
static T_8
F_33 ( struct V_134 * V_134 , char T_9 * V_135 ,
T_10 V_104 , T_11 * V_136 )
{
char * V_137 ;
int V_138 = 0 ;
int V_139 ;
T_8 V_140 ;
struct V_24 * V_141 = V_134 -> V_142 ;
V_137 = F_34 ( 1024 , V_143 ) ;
if ( ! V_137 )
return - V_144 ;
V_138 +=
sprintf ( V_137 + V_138 ,
L_30
L_31 , V_141 -> V_38 ,
V_141 -> V_81 , V_141 -> V_75 ,
F_12 ( V_141 -> V_44 ) ) ;
for ( V_139 = 0 ; V_139 < V_31 ; V_139 ++ ) {
V_138 +=
sprintf ( V_137 + V_138 , L_32 ,
V_141 -> V_16 [ V_139 ] . V_20 ,
V_141 -> V_16 [ V_139 ] . V_18 ,
V_141 -> V_16 [ V_139 ] . V_19 ) ;
}
V_140 = F_35 ( V_135 , V_104 , V_136 , V_137 , V_138 ) ;
F_36 ( V_137 ) ;
return V_140 ;
}
static void
F_37 ( void * T_4 , void * V_92 , struct V_88 * V_145 )
{
struct V_24 * V_141 = V_92 ;
V_141 -> V_146 =
F_38 ( L_33 , 0600 , V_145 , V_141 ,
& V_147 ) ;
}
static void
F_39 ( void * T_4 , void * V_92 )
{
struct V_24 * V_141 = V_92 ;
F_40 ( V_141 -> V_146 ) ;
}
static void
F_41 ( void * V_120 , struct V_65 * V_66 ,
struct V_148 * V_73 ,
struct V_56 * V_57 , void * V_92 )
{
}
void
F_42 ( struct V_59 * V_60 , T_2 V_58 )
{
struct V_29 * T_4 = V_60 -> V_90 ;
T_2 V_1 = 0 ;
unsigned long V_28 ;
struct V_24 * V_25 ;
struct V_56 * V_57 ;
struct V_63 * V_64 ;
F_9 ( L_3 ) ;
F_43 () ;
V_57 = F_44 ( T_4 -> V_149 , T_4 -> V_85 [ V_58 ] . V_57 . V_57 . V_150 ) ;
if ( ! V_57 ) {
F_9 ( L_34 ) ;
F_45 () ;
return;
}
V_64 = ( void * ) V_57 -> V_70 ;
V_25 = & V_64 -> V_25 ;
F_7 ( & V_25 -> V_32 , V_28 ) ;
V_25 -> V_114 = 0 ;
switch ( T_4 -> V_3 ) {
case V_10 :
if ( T_4 -> V_151 . V_28 & V_152 ) {
V_25 -> V_114 = 1 ;
V_25 -> V_55 = V_153 ;
} else
V_25 -> V_55 = V_154 ;
break;
case V_12 :
V_25 -> V_55 = V_155 ;
break;
default:
F_3 () ;
break;
}
F_10 ( & V_25 -> V_32 , V_28 ) ;
V_1 = T_4 -> V_82 . V_156 ;
if ( V_1 == 0 )
V_1 = V_8 ;
F_9 ( L_35 , V_1 ) ;
V_25 -> V_75 = F_1 ( V_1 , T_4 -> V_3 ) ;
F_9 ( L_36 L_37 , V_1 ,
V_25 -> V_75 , V_115 [ V_25 -> V_75 ] . V_157 ) ;
F_45 () ;
}
int
F_46 ( void )
{
return F_47 ( & V_158 ) ;
}
void
F_48 ( void )
{
F_49 ( & V_158 ) ;
}
