static T_1 F_1 ( T_2 V_1 , enum V_2 V_3 )
{
T_3 V_4 = 0 ;
T_3 V_5 = 0 ;
struct V_6 * V_7 = NULL ;
if ( ( V_1 < V_8 ) || ( V_1 > V_9 ) )
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
while ( ( V_4 < V_5 ) && ( V_1 < V_7 [ V_4 ] . V_14 ) )
V_4 ++ ;
V_4 = F_4 ( V_4 , ( V_5 - 1 ) ) ;
return V_7 [ V_4 ] . V_4 ;
}
static void F_5 ( struct V_15 * V_16 )
{
V_16 -> V_17 = 0 ;
V_16 -> V_18 = 0 ;
V_16 -> V_19 = - 1 ;
V_16 -> V_20 = 0 ;
V_16 -> V_21 = V_22 ;
V_16 -> V_23 = 0 ;
}
static int F_6 ( struct V_24 * V_25 )
{
int V_26 = 0 ;
int V_27 ;
unsigned long V_28 ;
struct V_29 * T_4 V_30 = V_25 -> T_4 ;
for ( V_27 = 0 ; V_27 < V_31 ; V_27 ++ ) {
if ( ! V_25 -> V_32 [ V_27 ] . V_20 )
continue;
F_7 ( & V_25 -> V_33 , V_28 ) ;
if ( F_8 ( V_34 , V_25 -> V_32 [ V_27 ] . V_23 +
V_35 ) ) {
F_9 ( T_4 , L_1
L_2 ,
V_25 -> V_32 [ V_27 ] . V_20 , V_27 ) ;
F_5 ( & V_25 -> V_32 [ V_27 ] ) ;
} else
V_26 ++ ;
F_10 ( & V_25 -> V_33 , V_28 ) ;
}
return V_26 ;
}
static void F_11 ( unsigned long V_17 )
{
struct V_24 * V_25 = ( void * ) V_17 ;
struct V_29 * T_4 V_30 = V_25 -> T_4 ;
int V_26 = 0 ;
unsigned long V_28 ;
T_3 V_36 , V_37 , V_38 ;
F_9 ( T_4 , L_3 ) ;
V_26 = F_6 ( V_25 ) ;
F_7 ( & V_25 -> V_33 , V_28 ) ;
V_36 = ( V_25 -> V_39 - V_25 -> V_40 ) + 1 ;
V_25 -> V_40 = V_25 -> V_39 + 1 ;
if ( V_26 ) {
V_37 =
F_12 ( V_34 - V_25 -> V_41 ) ;
F_9 ( T_4 , L_4 ,
V_36 , V_37 ) ;
if ( V_37 )
V_38 = ( V_36 * 1000 ) / V_37 ;
else
V_38 = 0 ;
if ( V_38 ) {
V_37 = ( V_42 * 1000 ) / V_38 ;
if ( V_37 < V_43 )
V_37 = V_43 ;
else if ( V_37 > V_44 )
V_37 = V_44 ;
} else
V_37 = V_44 ;
V_25 -> V_45 = F_13 ( V_37 ) ;
F_9 ( T_4 , L_5 ,
V_37 , V_36 ) ;
F_14 ( & V_25 -> V_46 , V_34 +
V_25 -> V_45 ) ;
V_25 -> V_41 = V_34 ;
} else {
V_25 -> V_45 = V_47 ;
V_25 -> V_48 = 0 ;
}
V_25 -> V_49 = V_34 ;
F_10 ( & V_25 -> V_33 , V_28 ) ;
F_9 ( T_4 , L_6 ) ;
}
static void F_15 ( struct V_24 * V_25 ,
struct V_15 * V_16 ,
int V_50 , int V_51 , int V_4 )
{
unsigned long V_28 ;
T_2 V_52 ;
struct V_29 * T_4 V_30 = V_25 -> T_4 ;
if ( ! V_51 ) {
F_9 ( T_4 , L_7 ) ;
return;
}
F_7 ( & V_25 -> V_33 , V_28 ) ;
while ( V_51 > 0 ) {
if ( V_16 -> V_20 >= V_53 ) {
V_16 -> V_20 = V_53 - 1 ;
if ( V_16 -> V_17 & ( 1ULL << ( V_53 - 1 ) ) ) {
V_16 -> V_17 &= ~ ( 1ULL << ( V_53 - 1 ) ) ;
V_16 -> V_18 -- ;
}
}
V_16 -> V_20 ++ ;
V_16 -> V_17 <<= 1 ;
if ( V_50 > 0 ) {
V_16 -> V_18 ++ ;
V_16 -> V_17 |= 0x1 ;
V_50 -- ;
}
V_51 -- ;
}
if ( V_16 -> V_20 > 0 )
V_16 -> V_19 = 128 * ( 100 * V_16 -> V_18 )
/ V_16 -> V_20 ;
else
V_16 -> V_19 = V_22 ;
V_52 = V_16 -> V_20 - V_16 -> V_18 ;
if ( ( V_52 >= V_54 ) ||
( V_16 -> V_18 >= V_55 ) )
V_16 -> V_21 = ( ( V_16 -> V_19 *
V_25 -> V_56 [ V_4 ] + 64 ) / 128 ) ;
else
V_16 -> V_21 = V_22 ;
V_16 -> V_23 = V_34 ;
F_10 ( & V_25 -> V_33 , V_28 ) ;
}
void F_16 ( struct V_29 * T_4 , struct V_57 * V_58 , T_1 V_59 )
{
struct V_60 * V_61 = T_4 -> V_61 ;
struct V_62 * V_63 = & T_4 -> V_61 -> V_63 ;
struct V_64 * V_65 ;
struct V_24 * V_25 ;
struct V_66 * V_67 ;
int V_27 ;
F_17 ( T_4 , L_3 ) ;
if ( V_59 == T_4 -> V_68 [ V_69 ] . V_70 )
goto V_71;
V_65 = (struct V_64 * ) V_58 -> V_72 ;
V_25 = & V_65 -> V_25 ;
V_67 = V_61 -> V_73 -> V_74 [ V_63 -> V_75 -> V_3 ] ;
V_25 -> T_4 = T_4 ;
V_25 -> V_76 = V_77 ;
V_25 -> V_56 = V_78 ;
V_25 -> V_41 = V_34 ;
V_25 -> V_49 = V_34 ;
V_25 -> V_45 = V_47 ;
V_25 -> V_40 = 0 ;
V_25 -> V_46 . V_17 = ( unsigned long ) V_25 ;
V_25 -> V_46 . V_79 = F_11 ;
for ( V_27 = 0 ; V_27 < V_31 ; V_27 ++ )
F_5 ( & V_25 -> V_32 [ V_27 ] ) ;
for ( V_27 = V_67 -> V_80 - 1 ; V_27 >= 0 ; V_27 -- ) {
if ( V_58 -> V_81 [ V_67 -> V_3 ] & ( 1 << V_27 ) ) {
V_25 -> V_82 = V_27 ;
break;
}
}
T_4 -> V_83 . V_84 = V_58 -> V_81 [ V_67 -> V_3 ] ;
if ( V_67 -> V_3 == V_12 ) {
V_25 -> V_82 += V_85 ;
T_4 -> V_83 . V_84 = T_4 -> V_83 . V_84 <<
V_85 ;
}
V_71:
T_4 -> V_86 [ V_59 ] . V_87 &= ~ V_88 ;
F_17 ( T_4 , L_6 ) ;
}
static void * F_18 ( struct V_60 * V_61 , struct V_89 * V_90 )
{
return V_61 -> T_4 ;
}
static void F_19 ( void * T_4 )
{
return;
}
static void * F_20 ( void * V_29 , struct V_57 * V_58 , T_5 V_91 )
{
struct V_24 * V_25 ;
struct V_64 * V_65 = ( void * ) V_58 -> V_72 ;
struct V_29 * T_4 V_30 = V_29 ;
F_9 ( T_4 , L_3 ) ;
V_25 = & V_65 -> V_25 ;
F_21 ( & V_25 -> V_33 ) ;
F_22 ( & V_25 -> V_46 ) ;
F_9 ( T_4 , L_6 ) ;
return V_25 ;
}
static void F_23 ( void * V_29 , struct V_57 * V_58 ,
void * V_92 )
{
struct V_24 * V_25 = V_92 ;
F_24 ( & V_25 -> V_46 ) ;
}
static void F_25 ( void * V_93 , struct V_66 * V_67 ,
struct V_57 * V_58 , void * V_92 ,
struct V_94 * V_95 )
{
T_6 V_51 = 0 , V_96 ;
int V_97 , V_98 , V_99 ;
unsigned long V_28 ;
struct V_29 * T_4 = (struct V_29 * ) V_93 ;
struct V_24 * V_25 = V_92 ;
struct V_100 * V_101 = F_26 ( V_95 ) ;
F_9 ( T_4 , L_3 ) ;
V_51 = V_101 -> V_102 . V_103 [ 0 ] . V_104 ;
if ( V_51 > V_105 )
V_51 = V_105 ;
V_98 = V_67 -> V_106 [ V_101 -> V_102 . V_103 [ 0 ] . V_107 ] . V_108 ;
if ( ( V_98 < 0 ) || ( V_98 >= V_31 ) ) {
F_9 ( T_4 , L_8 , V_98 ) ;
return;
}
if ( ! V_92 ) {
F_9 ( T_4 , L_9 ) ;
return;
}
if ( ! V_25 -> T_4 ) {
F_9 ( T_4 , L_10 ) ;
return;
}
V_25 -> V_39 ++ ;
V_97 = V_98 ;
V_99 = V_98 ;
while ( V_51 > 1 ) {
if ( ( V_51 - 1 ) < T_4 -> V_109 ) {
V_96 = ( V_51 - 1 ) ;
V_99 = V_97 ;
} else {
V_96 = T_4 -> V_109 ;
V_99 = F_27 ( T_4 ,
V_97 ) ;
}
F_15 ( V_25 ,
& V_25 -> V_32 [ V_97 ] ,
0 , V_96 , V_97 ) ;
F_9 ( T_4 , L_11 ,
V_97 , V_96 ) ;
V_51 -= V_96 ;
V_97 = V_99 ;
}
F_9 ( T_4 , L_12 ,
V_99 ,
( V_101 -> V_28 & V_110 ) ?
L_13 : L_14 ) ;
F_15 ( V_25 ,
& V_25 -> V_32 [ V_99 ] ,
V_101 -> V_28 & V_110 , 1 , V_99 ) ;
F_7 ( & V_25 -> V_33 , V_28 ) ;
if ( ! V_25 -> V_48 &&
F_8 ( V_34 , V_25 -> V_49 +
V_25 -> V_45 ) ) {
V_25 -> V_41 = V_34 ;
V_25 -> V_48 = 1 ;
F_14 ( & V_25 -> V_46 ,
V_34 + V_25 -> V_45 ) ;
}
F_10 ( & V_25 -> V_33 , V_28 ) ;
F_9 ( T_4 , L_6 ) ;
}
static T_7 F_28 ( struct V_24 * V_25 ,
T_1 V_4 , T_7 V_111 , enum V_2 V_3 )
{
T_1 V_112 = V_77 ;
T_1 V_113 = V_77 ;
struct V_29 * T_4 V_30 = V_25 -> T_4 ;
if ( F_29 ( V_3 == V_12 ) ) {
int V_27 ;
T_3 V_114 ;
V_27 = V_4 - 1 ;
for ( V_114 = ( 1 << V_27 ) ; V_27 >= 0 ; V_27 -- , V_114 >>= 1 ) {
if ( V_111 & V_114 ) {
V_113 = V_27 ;
break;
}
}
V_27 = V_4 + 1 ;
for ( V_114 = ( 1 << V_27 ) ; V_27 < V_31 ;
V_27 ++ , V_114 <<= 1 ) {
if ( V_111 & V_114 ) {
V_112 = V_27 ;
break;
}
}
return ( V_112 << 8 ) | V_113 ;
}
V_113 = V_4 ;
while ( V_113 != V_77 ) {
if ( V_25 -> V_115 )
V_113 = V_116 [ V_113 ] . V_117 ;
else
V_113 = V_116 [ V_113 ] . V_118 ;
if ( V_113 == V_77 )
break;
if ( V_111 & ( 1 << V_113 ) )
break;
F_9 ( T_4 , L_15 , V_113 ) ;
}
V_112 = V_4 ;
while ( V_112 != V_77 ) {
if ( V_25 -> V_115 )
V_112 = V_116 [ V_112 ] . V_119 ;
else
V_112 = V_116 [ V_112 ] . V_120 ;
if ( V_112 == V_77 )
break;
if ( V_111 & ( 1 << V_112 ) )
break;
F_9 ( T_4 , L_16 , V_112 ) ;
}
return ( V_112 << 8 ) | V_113 ;
}
static void F_30 ( void * V_121 , struct V_57 * V_58 ,
void * V_92 , struct V_122 * V_123 )
{
struct V_66 * V_67 = V_123 -> V_67 ;
struct V_94 * V_95 = V_123 -> V_95 ;
T_1 V_113 = V_77 ;
T_1 V_112 = V_77 ;
T_7 V_124 ;
int V_4 ;
struct V_24 * V_25 = V_92 ;
struct V_15 * V_16 = NULL ;
int V_125 = V_22 ;
int V_126 = V_22 ;
int V_127 = V_22 ;
T_3 V_52 ;
T_6 V_128 = 0 ;
unsigned long V_28 ;
T_7 V_111 ;
T_6 V_129 = - 1 ;
struct V_29 * T_4 V_30 = (struct V_29 * ) V_121 ;
struct V_100 * V_101 = F_26 ( V_95 ) ;
F_9 ( T_4 , L_3 ) ;
if ( V_25 && ! V_25 -> T_4 ) {
F_9 ( T_4 , L_17 ) ;
V_92 = NULL ;
}
if ( F_31 ( V_58 , V_92 , V_123 ) )
return;
V_111 = V_58 -> V_81 [ V_67 -> V_3 ] ;
V_129 = V_123 -> V_129 ;
if ( ( V_67 -> V_3 == V_12 ) && ( V_129 != - 1 ) )
V_129 += V_85 ;
if ( ( V_129 < 0 ) || ( V_129 >= V_130 ) )
V_129 = - 1 ;
V_4 = F_4 ( V_25 -> V_82 & 0xffff , V_31 - 1 ) ;
if ( V_67 -> V_3 == V_12 )
V_111 = V_111 << V_85 ;
F_7 ( & V_25 -> V_33 , V_28 ) ;
if ( V_25 -> V_76 != V_77 ) {
if ( V_25 -> V_76 < V_4 &&
( V_111 & ( 1 << V_25 -> V_76 ) ) )
V_4 = V_25 -> V_76 ;
V_25 -> V_76 = V_77 ;
}
if ( ( V_129 != - 1 ) && ( V_129 < V_4 ) ) {
if ( V_111 & ( 1 << V_129 ) )
V_4 = V_129 ;
}
V_16 = & ( V_25 -> V_32 [ V_4 ] ) ;
V_52 = V_16 -> V_20 - V_16 -> V_18 ;
if ( ( ( V_52 < V_54 ) &&
( V_16 -> V_18 < V_55 ) ) ) {
F_10 ( & V_25 -> V_33 , V_28 ) ;
F_9 ( T_4 , L_18
L_19
L_20 ,
V_4 ,
V_16 -> V_20 ,
V_16 -> V_18 ,
V_25 -> V_56 ? L_21 : L_22 ) ;
V_16 -> V_21 = V_22 ;
goto V_71;
}
V_125 = V_16 -> V_21 ;
V_124 = F_28 ( V_25 , V_4 , V_111 ,
V_67 -> V_3 ) ;
V_113 = V_124 & 0xff ;
V_112 = ( V_124 >> 8 ) & 0xff ;
if ( ( V_129 != - 1 ) && ( V_129 < V_112 ) )
V_112 = V_77 ;
if ( V_113 != V_77 )
V_126 = V_25 -> V_32 [ V_113 ] . V_21 ;
if ( V_112 != V_77 )
V_127 = V_25 -> V_32 [ V_112 ] . V_21 ;
F_10 ( & V_25 -> V_33 , V_28 ) ;
V_128 = 0 ;
if ( ( V_16 -> V_19 < V_131 ) || ! V_125 ) {
F_9 ( T_4 , L_23 ) ;
V_128 = - 1 ;
} else if ( ( V_126 == V_22 ) &&
( V_127 == V_22 ) ) {
if ( V_112 != V_77 && V_16 -> V_19 >= V_132 )
V_128 = 1 ;
else if ( V_113 != V_77 )
V_128 = 0 ;
} else if ( ( V_126 != V_22 ) &&
( V_127 != V_22 ) &&
( V_126 < V_125 ) && ( V_127 < V_125 ) ) {
F_9 ( T_4 , L_24
L_25 ,
V_126 , V_127 , V_125 ) ;
V_128 = 0 ;
} else {
if ( V_127 != V_22 ) {
if ( V_127 > V_125 &&
V_16 -> V_19 >= V_132 )
V_128 = 1 ;
else {
F_9 ( T_4 ,
L_26 ) ;
V_128 = 0 ;
}
} else if ( V_126 != V_22 ) {
if ( V_126 > V_125 ) {
F_9 ( T_4 ,
L_27 ) ;
V_128 = - 1 ;
} else if ( V_16 -> V_19 >= V_132 ) {
V_128 = 1 ;
}
}
}
if ( ( V_128 == - 1 ) && ( V_113 != V_77 ) &&
( ( V_16 -> V_19 > V_133 ) ||
( V_125 > ( 100 * V_25 -> V_56 [ V_113 ] ) ) ) )
V_128 = 0 ;
switch ( V_128 ) {
case - 1 :
if ( V_113 != V_77 )
V_4 = V_113 ;
break;
case 1 :
if ( V_112 != V_77 )
V_4 = V_112 ;
break;
case 0 :
default:
break;
}
F_9 ( T_4 , L_28 ,
V_4 , V_128 , V_113 , V_112 ) ;
V_71:
if ( V_67 -> V_3 == V_12 ) {
if ( F_32 ( V_4 < V_85 ) )
V_4 = V_85 ;
V_25 -> V_82 = V_4 ;
V_101 -> V_134 . V_103 [ 0 ] . V_107 = V_4 - V_85 ;
} else {
V_25 -> V_82 = V_4 ;
V_101 -> V_134 . V_103 [ 0 ] . V_107 = V_25 -> V_82 ;
}
F_9 ( T_4 , L_29 , V_4 ) ;
}
static int F_33 ( struct V_135 * V_135 , struct V_136 * V_136 )
{
V_136 -> V_137 = V_135 -> V_138 ;
return 0 ;
}
static T_8 F_34 ( struct V_136 * V_136 ,
char T_9 * V_139 ,
T_10 V_104 , T_11 * V_140 )
{
char * V_141 ;
int V_142 = 0 ;
int V_143 ;
T_8 V_144 ;
struct V_24 * V_145 = V_136 -> V_137 ;
V_141 = F_35 ( 1024 , V_146 ) ;
if ( ! V_141 )
return - V_147 ;
V_142 += sprintf ( V_141 + V_142 , L_30
L_31 ,
V_145 -> V_39 ,
V_145 -> V_82 ,
V_145 -> V_76 , F_12 ( V_145 -> V_45 ) ) ;
for ( V_143 = 0 ; V_143 < V_31 ; V_143 ++ ) {
V_142 += sprintf ( V_141 + V_142 ,
L_32 ,
V_145 -> V_32 [ V_143 ] . V_20 ,
V_145 -> V_32 [ V_143 ] . V_18 ,
V_145 -> V_32 [ V_143 ] . V_19 ) ;
}
V_144 = F_36 ( V_139 , V_104 , V_140 , V_141 , V_142 ) ;
F_37 ( V_141 ) ;
return V_144 ;
}
static void F_38 ( void * T_4 , void * V_92 ,
struct V_89 * V_148 )
{
struct V_24 * V_145 = V_92 ;
V_145 -> V_149 =
F_39 ( L_33 , 0600 , V_148 ,
V_145 , & V_150 ) ;
}
static void F_40 ( void * T_4 , void * V_92 )
{
struct V_24 * V_145 = V_92 ;
F_41 ( V_145 -> V_149 ) ;
}
static void F_42 ( void * V_121 ,
struct V_66 * V_67 ,
struct V_57 * V_58 , void * V_92 )
{
}
void F_43 ( struct V_60 * V_61 , T_2 V_59 )
{
struct V_29 * T_4 = V_61 -> T_4 ;
T_2 V_1 = 0 ;
unsigned long V_28 ;
struct V_24 * V_25 ;
struct V_57 * V_58 ;
struct V_64 * V_65 ;
F_9 ( T_4 , L_3 ) ;
F_44 () ;
V_58 = F_45 ( T_4 -> V_68 [ V_69 ] . V_151 ,
T_4 -> V_86 [ V_59 ] . V_58 . V_58 . V_152 ) ;
if ( ! V_58 ) {
F_9 ( T_4 , L_34 ) ;
F_46 () ;
return;
}
V_65 = ( void * ) V_58 -> V_72 ;
V_25 = & V_65 -> V_25 ;
F_7 ( & V_25 -> V_33 , V_28 ) ;
V_25 -> V_115 = 0 ;
switch ( T_4 -> V_3 ) {
case V_10 :
if ( T_4 -> V_68 [ V_69 ] . V_153 . V_28 &
V_154 ) {
V_25 -> V_115 = 1 ;
V_25 -> V_56 = V_155 ;
} else
V_25 -> V_56 = V_156 ;
break;
case V_12 :
V_25 -> V_56 = V_157 ;
break;
case V_158 :
F_3 () ;
break;
}
F_10 ( & V_25 -> V_33 , V_28 ) ;
V_1 = T_4 -> V_83 . V_159 ;
if ( V_1 == 0 )
V_1 = V_8 ;
F_9 ( T_4 , L_35 , V_1 ) ;
V_25 -> V_76 = F_1 ( V_1 , T_4 -> V_3 ) ;
F_9 ( T_4 , L_36
L_37 , V_1 , V_25 -> V_76 ,
V_116 [ V_25 -> V_76 ] . V_160 ) ;
F_46 () ;
}
int F_47 ( void )
{
return F_48 ( & V_161 ) ;
}
void F_49 ( void )
{
F_50 ( & V_161 ) ;
}
