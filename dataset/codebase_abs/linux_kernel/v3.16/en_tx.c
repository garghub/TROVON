int F_1 ( struct V_1 * V_2 ,
struct V_3 * * V_4 , int V_5 , T_1 V_6 ,
T_2 V_7 , int V_8 , int V_9 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_3 * V_12 ;
int V_13 ;
int V_14 ;
V_12 = F_2 ( sizeof( * V_12 ) , V_15 , V_8 ) ;
if ( ! V_12 ) {
V_12 = F_3 ( sizeof( * V_12 ) , V_15 ) ;
if ( ! V_12 ) {
F_4 ( V_2 , L_1 ) ;
return - V_16 ;
}
}
V_12 -> V_6 = V_6 ;
V_12 -> V_17 = V_6 - 1 ;
V_12 -> V_7 = V_7 ;
V_12 -> V_18 = V_2 -> V_19 -> V_18 ;
V_13 = V_6 * sizeof( struct V_20 ) ;
V_12 -> V_21 = F_5 ( V_13 , V_8 ) ;
if ( ! V_12 -> V_21 ) {
V_12 -> V_21 = F_6 ( V_13 ) ;
if ( ! V_12 -> V_21 ) {
V_14 = - V_16 ;
goto V_22;
}
}
F_7 ( V_23 , V_2 , L_2 ,
V_12 -> V_21 , V_13 ) ;
V_12 -> V_24 = F_8 ( V_25 , V_15 , V_8 ) ;
if ( ! V_12 -> V_24 ) {
V_12 -> V_24 = F_9 ( V_25 , V_15 ) ;
if ( ! V_12 -> V_24 ) {
V_14 = - V_16 ;
goto V_26;
}
}
V_12 -> V_27 = F_10 ( V_6 * V_12 -> V_7 , V_28 ) ;
F_11 ( & V_11 -> V_29 -> V_30 -> V_29 , V_8 ) ;
V_14 = F_12 ( V_11 -> V_29 , & V_12 -> V_31 , V_12 -> V_27 ,
2 * V_32 ) ;
F_11 ( & V_11 -> V_29 -> V_30 -> V_29 , V_11 -> V_29 -> V_33 ) ;
if ( V_14 ) {
F_4 ( V_2 , L_3 ) ;
goto V_34;
}
V_14 = F_13 ( & V_12 -> V_31 . V_35 ) ;
if ( V_14 ) {
F_4 ( V_2 , L_4 ) ;
goto V_36;
}
V_12 -> V_35 = V_12 -> V_31 . V_35 . V_37 . V_35 ;
F_7 ( V_23 , V_2 , L_5 ,
V_12 , V_12 -> V_35 , V_12 -> V_6 , V_12 -> V_27 ,
( unsigned long long ) V_12 -> V_31 . V_35 . V_37 . V_38 ) ;
V_12 -> V_5 = V_5 ;
V_14 = F_14 ( V_11 -> V_29 , V_12 -> V_5 , & V_12 -> V_39 , V_15 ) ;
if ( V_14 ) {
F_4 ( V_2 , L_6 , V_12 -> V_5 ) ;
goto V_40;
}
V_12 -> V_39 . V_41 = V_42 ;
V_14 = F_15 ( V_11 -> V_29 , & V_12 -> V_43 , V_8 ) ;
if ( V_14 ) {
F_7 ( V_23 , V_2 , L_7 , V_14 ) ;
V_12 -> V_43 . V_44 = & V_11 -> V_45 ;
V_12 -> V_43 . V_44 -> V_38 = V_11 -> V_46 ;
V_12 -> V_47 = false ;
} else
V_12 -> V_47 = true ;
V_12 -> V_48 = V_2 -> V_49 . V_50 ;
V_12 -> V_9 = V_9 ;
if ( V_9 < V_2 -> V_51 && F_16 ( V_9 ) )
F_17 ( V_9 , & V_12 -> V_52 ) ;
* V_4 = V_12 ;
return 0 ;
V_40:
F_18 ( & V_12 -> V_31 . V_35 ) ;
V_36:
F_19 ( V_11 -> V_29 , & V_12 -> V_31 , V_12 -> V_27 ) ;
V_34:
F_20 ( V_12 -> V_24 ) ;
V_12 -> V_24 = NULL ;
V_26:
F_21 ( V_12 -> V_21 ) ;
V_12 -> V_21 = NULL ;
V_22:
F_20 ( V_12 ) ;
* V_4 = NULL ;
return V_14 ;
}
void F_22 ( struct V_1 * V_2 ,
struct V_3 * * V_4 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_3 * V_12 = * V_4 ;
F_7 ( V_23 , V_2 , L_8 , V_12 -> V_5 ) ;
if ( V_12 -> V_47 )
F_23 ( V_11 -> V_29 , & V_12 -> V_43 ) ;
F_24 ( V_11 -> V_29 , & V_12 -> V_39 ) ;
F_25 ( V_11 -> V_29 , & V_12 -> V_39 ) ;
F_18 ( & V_12 -> V_31 . V_35 ) ;
F_19 ( V_11 -> V_29 , & V_12 -> V_31 , V_12 -> V_27 ) ;
F_20 ( V_12 -> V_24 ) ;
V_12 -> V_24 = NULL ;
F_21 ( V_12 -> V_21 ) ;
V_12 -> V_21 = NULL ;
F_20 ( V_12 ) ;
* V_4 = NULL ;
}
int F_26 ( struct V_1 * V_2 ,
struct V_3 * V_12 ,
int V_53 , int V_54 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
int V_14 ;
V_12 -> V_55 = V_53 ;
V_12 -> V_56 = 0 ;
V_12 -> V_57 = 0xffffffff ;
V_12 -> V_58 = 1 ;
V_12 -> V_59 = 0 ;
memset ( V_12 -> V_21 , 0 , V_12 -> V_6 * sizeof( struct V_20 ) ) ;
memset ( V_12 -> V_35 , 0 , V_12 -> V_27 ) ;
V_12 -> V_60 = V_61 ;
V_12 -> V_62 = V_12 -> V_39 . V_5 << 8 ;
F_27 ( V_2 , V_12 -> V_6 , V_12 -> V_7 , 1 , 0 , V_12 -> V_5 ,
V_12 -> V_55 , V_54 , & V_12 -> V_63 ) ;
if ( V_12 -> V_47 )
V_12 -> V_63 . V_64 = F_28 ( V_12 -> V_43 . V_44 -> V_65 ) ;
V_14 = F_29 ( V_11 -> V_29 , & V_12 -> V_31 . V_66 , & V_12 -> V_63 ,
& V_12 -> V_39 , & V_12 -> V_60 ) ;
if ( ! V_54 && F_16 ( V_12 -> V_9 ) )
F_30 ( V_2 -> V_29 , & V_12 -> V_52 ,
V_12 -> V_9 ) ;
return V_14 ;
}
void F_31 ( struct V_1 * V_2 ,
struct V_3 * V_12 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
F_32 ( V_11 -> V_29 , NULL , V_12 -> V_60 ,
V_61 , NULL , 0 , 0 , & V_12 -> V_39 ) ;
}
static void F_33 ( struct V_1 * V_2 ,
struct V_3 * V_12 , int V_65 ,
T_3 V_67 )
{
T_4 V_68 = F_28 ( V_69 | ( ! ! V_67 << V_70 ) ) ;
struct V_71 * V_72 = V_12 -> V_35 + V_65 * V_73 ;
struct V_20 * V_21 = & V_12 -> V_21 [ V_65 ] ;
void * V_74 = V_12 -> V_35 + V_12 -> V_27 ;
T_4 * V_75 = ( T_4 * ) V_72 ;
int V_76 ;
if ( F_34 ( ( void * ) V_72 + V_21 -> V_77 * V_73 <= V_74 ) ) {
for ( V_76 = 0 ; V_76 < V_21 -> V_77 * V_73 ;
V_76 += V_78 ) {
* V_75 = V_68 ;
V_75 += V_79 ;
}
} else {
for ( V_76 = 0 ; V_76 < V_21 -> V_77 * V_73 ;
V_76 += V_78 ) {
* V_75 = V_68 ;
V_75 += V_79 ;
if ( ( void * ) V_75 >= V_74 ) {
V_75 = V_12 -> V_35 ;
V_68 ^= F_28 ( 0x80000000 ) ;
}
}
}
}
static T_1 F_35 ( struct V_1 * V_2 ,
struct V_3 * V_12 ,
int V_65 , T_3 V_67 , T_5 V_80 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_20 * V_21 = & V_12 -> V_21 [ V_65 ] ;
struct V_71 * V_72 = V_12 -> V_35 + V_65 * V_73 ;
struct V_81 * V_82 = ( void * ) V_72 + V_21 -> V_83 ;
struct V_84 * V_85 = V_21 -> V_85 ;
struct V_86 * V_87 ;
void * V_74 = V_12 -> V_35 + V_12 -> V_27 ;
int V_88 = F_36 ( V_85 ) -> V_89 ;
int V_76 ;
struct V_90 V_91 ;
if ( V_80 ) {
F_37 ( V_11 , & V_91 , V_80 ) ;
F_38 ( V_85 , & V_91 ) ;
}
if ( F_34 ( ( void * ) V_72 + V_21 -> V_77 * V_73 <= V_74 ) ) {
if ( ! V_21 -> V_92 ) {
if ( V_21 -> V_93 ) {
F_39 ( V_2 -> V_94 ,
( V_95 ) F_40 ( V_82 -> V_96 ) ,
F_41 ( V_82 -> V_97 ) ,
V_98 ) ;
++ V_82 ;
}
for ( V_76 = 0 ; V_76 < V_88 ; V_76 ++ ) {
V_87 = & F_36 ( V_85 ) -> V_88 [ V_76 ] ;
F_42 ( V_2 -> V_94 ,
( V_95 ) F_40 ( V_82 [ V_76 ] . V_96 ) ,
F_43 ( V_87 ) , V_98 ) ;
}
}
} else {
if ( ! V_21 -> V_92 ) {
if ( ( void * ) V_82 >= V_74 ) {
V_82 = V_12 -> V_35 + ( ( void * ) V_82 - V_74 ) ;
}
if ( V_21 -> V_93 ) {
F_39 ( V_2 -> V_94 ,
( V_95 ) F_40 ( V_82 -> V_96 ) ,
F_41 ( V_82 -> V_97 ) ,
V_98 ) ;
++ V_82 ;
}
for ( V_76 = 0 ; V_76 < V_88 ; V_76 ++ ) {
if ( ( void * ) V_82 >= V_74 )
V_82 = V_12 -> V_35 ;
V_87 = & F_36 ( V_85 ) -> V_88 [ V_76 ] ;
F_42 ( V_2 -> V_94 ,
( V_95 ) F_40 ( V_82 -> V_96 ) ,
F_43 ( V_87 ) , V_98 ) ;
++ V_82 ;
}
}
}
F_44 ( V_85 ) ;
return V_21 -> V_77 ;
}
int F_45 ( struct V_99 * V_29 , struct V_3 * V_12 )
{
struct V_1 * V_2 = F_46 ( V_29 ) ;
int V_100 = 0 ;
V_12 -> V_57 += V_12 -> V_58 ;
F_7 ( V_23 , V_2 , L_9 ,
V_12 -> V_57 , V_12 -> V_56 ) ;
if ( ( T_1 ) ( V_12 -> V_56 - V_12 -> V_57 ) > V_12 -> V_6 ) {
if ( F_47 ( V_2 ) )
F_48 ( V_2 , L_10 ) ;
return 0 ;
}
while ( V_12 -> V_57 != V_12 -> V_56 ) {
V_12 -> V_58 = F_35 ( V_2 , V_12 ,
V_12 -> V_57 & V_12 -> V_17 ,
! ! ( V_12 -> V_57 & V_12 -> V_6 ) , 0 ) ;
V_12 -> V_57 += V_12 -> V_58 ;
V_100 ++ ;
}
F_49 ( V_12 -> V_101 ) ;
if ( V_100 )
F_7 ( V_23 , V_2 , L_11 , V_100 ) ;
return V_100 ;
}
static bool F_50 ( struct V_99 * V_29 ,
struct V_102 * V_53 )
{
struct V_1 * V_2 = F_46 ( V_29 ) ;
struct V_103 * V_104 = & V_53 -> V_104 ;
struct V_3 * V_12 = V_2 -> V_105 [ V_53 -> V_12 ] ;
struct V_106 * V_107 ;
T_2 V_65 ;
T_2 V_108 , V_109 , V_110 ;
T_1 V_111 = 0 ;
T_1 V_112 = 0 ;
T_1 V_113 = V_104 -> V_113 ;
int V_6 = V_53 -> V_6 ;
T_1 V_17 = V_12 -> V_17 ;
struct V_106 * V_35 = V_53 -> V_35 ;
T_1 V_114 = 0 ;
T_1 V_115 = 0 ;
int V_116 = V_2 -> V_117 ;
T_5 V_80 = 0 ;
int V_118 = 0 ;
int V_119 = V_2 -> V_120 ;
if ( ! V_2 -> V_121 )
return true ;
V_65 = V_113 & V_17 ;
V_107 = & V_35 [ ( V_65 << V_116 ) + V_116 ] ;
V_109 = V_12 -> V_57 & V_17 ;
V_110 = V_109 ;
while ( F_51 ( V_107 -> V_122 & V_123 ,
V_113 & V_6 ) && ( V_118 < V_119 ) ) {
F_52 () ;
if ( F_53 ( ( V_107 -> V_122 & V_124 ) ==
V_125 ) ) {
struct V_126 * V_127 = (struct V_126 * ) V_107 ;
F_4 ( V_2 , L_12 ,
V_127 -> V_128 ,
V_127 -> V_129 ) ;
}
V_108 = F_54 ( V_107 -> V_130 ) & V_17 ;
do {
V_111 += V_12 -> V_58 ;
V_109 = ( V_109 + V_12 -> V_58 ) & V_17 ;
if ( V_12 -> V_21 [ V_109 ] . V_131 )
V_80 = F_55 ( V_107 ) ;
V_12 -> V_58 = F_35 (
V_2 , V_12 , V_109 ,
! ! ( ( V_12 -> V_57 + V_111 ) &
V_12 -> V_6 ) , V_80 ) ;
F_33 ( V_2 , V_12 , V_110 ,
! ! ( ( V_12 -> V_57 + V_112 ) &
V_12 -> V_6 ) ) ;
V_110 = V_109 ;
V_112 = V_111 ;
V_114 ++ ;
V_115 += V_12 -> V_21 [ V_109 ] . V_132 ;
} while ( ( ++ V_118 < V_119 ) && ( V_109 != V_108 ) );
++ V_113 ;
V_65 = V_113 & V_17 ;
V_107 = & V_35 [ ( V_65 << V_116 ) + V_116 ] ;
}
V_104 -> V_113 = V_113 ;
F_56 ( V_104 ) ;
F_57 () ;
V_12 -> V_57 += V_111 ;
F_58 ( V_12 -> V_101 , V_114 , V_115 ) ;
if ( F_59 ( V_12 -> V_101 ) && V_111 > 0 ) {
F_60 ( V_12 -> V_101 ) ;
V_12 -> V_133 ++ ;
}
return V_118 < V_119 ;
}
void F_61 ( struct V_103 * V_104 )
{
struct V_102 * V_53 = F_62 ( V_104 , struct V_102 , V_104 ) ;
struct V_1 * V_2 = F_46 ( V_53 -> V_29 ) ;
if ( V_2 -> V_121 )
F_63 ( & V_53 -> V_134 ) ;
else
F_64 ( V_2 , V_53 ) ;
}
int F_65 ( struct V_135 * V_134 , int V_119 )
{
struct V_102 * V_53 = F_62 ( V_134 , struct V_102 , V_134 ) ;
struct V_99 * V_29 = V_53 -> V_29 ;
struct V_1 * V_2 = F_46 ( V_29 ) ;
int V_136 ;
V_136 = F_50 ( V_29 , V_53 ) ;
if ( ! V_136 )
return V_119 ;
F_66 ( V_134 ) ;
F_64 ( V_2 , V_53 ) ;
return 0 ;
}
static struct V_71 * F_67 ( struct V_1 * V_2 ,
struct V_3 * V_12 ,
T_1 V_65 ,
unsigned int V_137 )
{
T_1 V_138 = ( V_12 -> V_6 - V_65 ) * V_73 ;
int V_76 ;
for ( V_76 = V_137 - V_138 - 4 ; V_76 >= 0 ; V_76 -= 4 ) {
if ( ( V_76 & ( V_73 - 1 ) ) == 0 )
F_57 () ;
* ( ( T_1 * ) ( V_12 -> V_35 + V_76 ) ) =
* ( ( T_1 * ) ( V_12 -> V_24 + V_138 + V_76 ) ) ;
}
for ( V_76 = V_138 - 4 ; V_76 >= 4 ; V_76 -= 4 ) {
if ( ( V_76 & ( V_73 - 1 ) ) == 0 )
F_57 () ;
* ( ( T_1 * ) ( V_12 -> V_35 + V_65 * V_73 + V_76 ) ) =
* ( ( T_1 * ) ( V_12 -> V_24 + V_76 ) ) ;
}
return V_12 -> V_35 + V_65 * V_73 ;
}
static int F_68 ( int V_18 , struct V_84 * V_85 , void * * V_139 )
{
void * V_75 ;
if ( V_18 && ! F_69 ( V_85 ) && V_85 -> V_140 <= V_18 ) {
if ( F_36 ( V_85 ) -> V_89 == 1 ) {
V_75 = F_70 ( & F_36 ( V_85 ) -> V_88 [ 0 ] ) ;
if ( F_53 ( ! V_75 ) )
return 0 ;
if ( V_139 )
* V_139 = V_75 ;
return 1 ;
} else if ( F_53 ( F_36 ( V_85 ) -> V_89 ) )
return 0 ;
else
return 1 ;
}
return 0 ;
}
static int F_71 ( struct V_84 * V_85 )
{
if ( V_85 -> V_140 + V_141 + sizeof( struct V_142 )
<= V_143 )
return F_10 ( V_85 -> V_140 + V_141 +
sizeof( struct V_142 ) , 16 ) ;
else
return F_10 ( V_85 -> V_140 + V_141 + 2 *
sizeof( struct V_142 ) , 16 ) ;
}
static int F_72 ( struct V_84 * V_85 , struct V_99 * V_29 ,
int * V_144 )
{
struct V_1 * V_2 = F_46 ( V_29 ) ;
int V_145 ;
if ( F_69 ( V_85 ) ) {
if ( V_85 -> V_146 )
* V_144 = ( F_73 ( V_85 ) - V_85 -> V_82 ) + F_74 ( V_85 ) ;
else
* V_144 = F_75 ( V_85 ) + F_76 ( V_85 ) ;
V_145 = V_141 + F_36 ( V_85 ) -> V_89 * V_147 +
F_10 ( * V_144 + 4 , V_147 ) ;
if ( F_53 ( * V_144 != F_77 ( V_85 ) ) ) {
if ( * V_144 < F_77 ( V_85 ) )
V_145 += V_147 ;
else {
if ( F_47 ( V_2 ) )
F_48 ( V_2 , L_13 ) ;
return 0 ;
}
}
} else {
* V_144 = 0 ;
if ( ! F_68 ( V_2 -> V_19 -> V_18 , V_85 , NULL ) )
V_145 = V_141 + ( F_36 ( V_85 ) -> V_89 + 1 ) * V_147 ;
else
V_145 = F_71 ( V_85 ) ;
}
return V_145 ;
}
static void F_78 ( struct V_71 * V_72 , struct V_84 * V_85 ,
int V_145 , T_2 * V_148 , int V_149 , void * V_150 )
{
struct V_142 * V_92 = & V_72 -> V_92 ;
int V_151 = V_143 - V_141 - sizeof *V_92 ;
if ( V_85 -> V_140 <= V_151 ) {
if ( F_34 ( V_85 -> V_140 >= V_152 ) ) {
V_92 -> V_97 = F_28 ( 1 << 31 | V_85 -> V_140 ) ;
} else {
V_92 -> V_97 = F_28 ( 1 << 31 | V_152 ) ;
memset ( ( ( void * ) ( V_92 + 1 ) ) + V_85 -> V_140 , 0 ,
V_152 - V_85 -> V_140 ) ;
}
F_79 ( V_85 , V_92 + 1 , F_77 ( V_85 ) ) ;
if ( F_36 ( V_85 ) -> V_89 )
memcpy ( ( ( void * ) ( V_92 + 1 ) ) + F_77 ( V_85 ) , V_150 ,
F_43 ( & F_36 ( V_85 ) -> V_88 [ 0 ] ) ) ;
} else {
V_92 -> V_97 = F_28 ( 1 << 31 | V_151 ) ;
if ( F_77 ( V_85 ) <= V_151 ) {
F_79 ( V_85 , V_92 + 1 , F_77 ( V_85 ) ) ;
if ( F_77 ( V_85 ) < V_151 ) {
memcpy ( ( ( void * ) ( V_92 + 1 ) ) + F_77 ( V_85 ) ,
V_150 , V_151 - F_77 ( V_85 ) ) ;
V_150 += V_151 - F_77 ( V_85 ) ;
}
V_92 = ( void * ) ( V_92 + 1 ) + V_151 ;
memcpy ( ( ( void * ) ( V_92 + 1 ) ) , V_150 , V_85 -> V_140 - V_151 ) ;
} else {
F_79 ( V_85 , V_92 + 1 , V_151 ) ;
V_92 = ( void * ) ( V_92 + 1 ) + V_151 ;
F_80 ( V_85 , V_151 , V_92 + 1 ,
F_77 ( V_85 ) - V_151 ) ;
if ( F_36 ( V_85 ) -> V_89 )
memcpy ( ( ( void * ) ( V_92 + 1 ) ) + F_77 ( V_85 ) - V_151 ,
V_150 , F_43 ( & F_36 ( V_85 ) -> V_88 [ 0 ] ) ) ;
}
F_57 () ;
V_92 -> V_97 = F_28 ( 1 << 31 | ( V_85 -> V_140 - V_151 ) ) ;
}
}
T_2 F_81 ( struct V_99 * V_29 , struct V_84 * V_85 ,
void * V_153 , T_6 V_154 )
{
struct V_1 * V_2 = F_46 ( V_29 ) ;
T_2 V_155 = V_2 -> V_51 ;
T_3 V_156 = 0 ;
if ( V_29 -> V_157 )
return F_82 ( V_29 , V_85 ) ;
if ( F_83 ( V_85 ) )
V_156 = F_84 ( V_85 ) >> V_158 ;
return V_154 ( V_29 , V_85 ) % V_155 + V_156 * V_155 ;
}
static void F_85 ( void T_7 * V_159 , unsigned long * V_160 , unsigned V_161 )
{
F_86 ( V_159 , V_160 , V_161 / 8 ) ;
}
T_8 F_87 ( struct V_84 * V_85 , struct V_99 * V_29 )
{
struct V_1 * V_2 = F_46 ( V_29 ) ;
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_162 * V_94 = V_2 -> V_94 ;
struct V_3 * V_12 ;
struct V_71 * V_72 ;
struct V_81 * V_82 ;
struct V_20 * V_21 ;
int V_149 = 0 ;
int V_77 ;
int V_137 ;
int V_145 ;
T_1 V_65 , V_163 ;
T_4 V_164 ;
T_2 V_148 = 0 ;
int V_76 ;
int V_144 ;
void * V_150 ;
bool V_165 = false ;
if ( ! V_2 -> V_121 )
goto V_166;
V_145 = F_72 ( V_85 , V_29 , & V_144 ) ;
if ( F_53 ( ! V_145 ) )
goto V_166;
V_137 = F_10 ( V_145 , V_73 ) ;
V_77 = V_137 / V_73 ;
if ( F_53 ( V_77 > V_167 ) ) {
if ( F_47 ( V_2 ) )
F_48 ( V_2 , L_14 ) ;
goto V_166;
}
V_149 = V_85 -> V_168 ;
V_12 = V_2 -> V_105 [ V_149 ] ;
if ( F_83 ( V_85 ) )
V_148 = F_84 ( V_85 ) ;
if ( F_53 ( ( ( int ) ( V_12 -> V_56 - V_12 -> V_57 ) ) >
V_12 -> V_6 - V_169 - V_167 ) ) {
F_88 ( V_12 -> V_101 ) ;
V_12 -> V_170 ++ ;
F_57 () ;
if ( F_53 ( ( ( int ) ( V_12 -> V_56 - V_12 -> V_57 ) ) <=
V_12 -> V_6 - V_169 - V_167 ) ) {
F_60 ( V_12 -> V_101 ) ;
V_12 -> V_133 ++ ;
} else {
return V_171 ;
}
}
F_89 ( V_2 -> V_172 . V_173 ,
( T_1 ) ( V_12 -> V_56 - V_12 -> V_57 - 1 ) ) ;
V_65 = V_12 -> V_56 & V_12 -> V_17 ;
V_163 = V_12 -> V_56 ;
if ( F_34 ( V_65 + V_77 <= V_12 -> V_6 ) )
V_72 = V_12 -> V_35 + V_65 * V_73 ;
else {
V_72 = (struct V_71 * ) V_12 -> V_24 ;
V_165 = true ;
}
V_21 = & V_12 -> V_21 [ V_65 ] ;
V_21 -> V_85 = V_85 ;
V_21 -> V_77 = V_77 ;
if ( V_144 )
V_82 = ( ( void * ) & V_72 -> V_174 + F_10 ( V_144 + 4 ,
V_147 ) ) ;
else
V_82 = & V_72 -> V_82 ;
V_21 -> V_83 = ( void * ) V_82 - ( void * ) V_72 ;
V_21 -> V_93 = ( V_144 < F_77 ( V_85 ) &&
! F_68 ( V_12 -> V_18 , V_85 , NULL ) ) ? 1 : 0 ;
V_82 += F_36 ( V_85 ) -> V_89 + V_21 -> V_93 - 1 ;
if ( F_68 ( V_12 -> V_18 , V_85 , & V_150 ) ) {
V_21 -> V_92 = 1 ;
} else {
for ( V_76 = F_36 ( V_85 ) -> V_89 - 1 ; V_76 >= 0 ; V_76 -- ) {
struct V_86 * V_87 ;
V_95 V_175 ;
V_87 = & F_36 ( V_85 ) -> V_88 [ V_76 ] ;
V_175 = F_90 ( V_94 , V_87 ,
0 , F_43 ( V_87 ) ,
V_176 ) ;
if ( F_91 ( V_94 , V_175 ) )
goto V_177;
V_82 -> V_96 = F_92 ( V_175 ) ;
V_82 -> V_178 = F_28 ( V_11 -> V_179 . V_180 ) ;
F_57 () ;
V_82 -> V_97 = F_28 ( F_43 ( V_87 ) ) ;
-- V_82 ;
}
if ( V_21 -> V_93 ) {
T_1 V_97 = F_77 ( V_85 ) - V_144 ;
V_95 V_175 ;
V_175 = F_93 ( V_94 , V_85 -> V_82 +
V_144 , V_97 ,
V_98 ) ;
if ( F_91 ( V_94 , V_175 ) )
goto V_177;
V_82 -> V_96 = F_92 ( V_175 ) ;
V_82 -> V_178 = F_28 ( V_11 -> V_179 . V_180 ) ;
F_57 () ;
V_82 -> V_97 = F_28 ( V_97 ) ;
}
V_21 -> V_92 = 0 ;
}
if ( V_12 -> V_48 == V_181 &&
F_36 ( V_85 ) -> V_182 & V_183 ) {
F_36 ( V_85 ) -> V_182 |= V_184 ;
V_21 -> V_131 = 1 ;
}
V_72 -> V_185 . V_148 = F_94 ( V_148 ) ;
V_72 -> V_185 . V_186 = V_187 *
! ! F_83 ( V_85 ) ;
V_72 -> V_185 . V_188 = ( V_145 / 16 ) & 0x3f ;
V_72 -> V_185 . V_189 = V_2 -> V_190 ;
if ( F_34 ( V_85 -> V_191 == V_192 ) ) {
V_72 -> V_185 . V_189 |= F_28 ( V_193 |
V_194 ) ;
V_12 -> V_195 ++ ;
}
if ( V_2 -> V_196 & V_197 ) {
struct V_198 * V_199 ;
V_199 = (struct V_198 * ) V_85 -> V_82 ;
V_72 -> V_185 . V_200 [ 0 ] = F_95 ( ( V_201 * ) V_199 -> V_202 ) ;
V_72 -> V_185 . V_203 = F_95 ( ( T_4 * ) ( V_199 -> V_202 + 2 ) ) ;
}
if ( V_144 ) {
V_164 = F_28 ( V_204 | ( 1 << 6 ) ) |
( ( V_12 -> V_56 & V_12 -> V_6 ) ?
F_28 ( V_205 ) : 0 ) ;
V_72 -> V_174 . V_206 = F_28 (
F_36 ( V_85 ) -> V_207 << 16 | V_144 ) ;
memcpy ( V_72 -> V_174 . V_208 , V_85 -> V_82 , V_144 ) ;
V_2 -> V_209 . V_210 ++ ;
V_76 = ( ( V_85 -> V_140 - V_144 ) / F_36 ( V_85 ) -> V_207 ) +
! ! ( ( V_85 -> V_140 - V_144 ) % F_36 ( V_85 ) -> V_207 ) ;
V_21 -> V_132 = V_85 -> V_140 + ( V_76 - 1 ) * V_144 ;
V_12 -> V_114 += V_76 ;
} else {
V_164 = F_28 ( V_211 ) |
( ( V_12 -> V_56 & V_12 -> V_6 ) ?
F_28 ( V_205 ) : 0 ) ;
V_21 -> V_132 = F_96 (unsigned int, skb->len, ETH_ZLEN) ;
V_12 -> V_114 ++ ;
}
V_12 -> V_115 += V_21 -> V_132 ;
F_97 ( V_12 -> V_101 , V_21 -> V_132 ) ;
F_89 ( V_2 -> V_172 . V_212 , V_85 -> V_140 ) ;
if ( V_21 -> V_92 ) {
F_78 ( V_72 , V_85 , V_145 , & V_148 , V_149 , V_150 ) ;
V_21 -> V_92 = 1 ;
}
if ( V_85 -> V_146 ) {
struct V_213 * V_214 = (struct V_213 * ) F_98 ( V_85 ) ;
if ( V_214 -> V_215 == V_216 || V_214 -> V_215 == V_217 )
V_164 |= F_28 ( V_218 | V_219 ) ;
else
V_164 |= F_28 ( V_218 ) ;
}
V_12 -> V_56 += V_77 ;
if ( V_165 )
V_72 = F_67 ( V_2 , V_12 , V_65 , V_137 ) ;
F_99 ( V_85 ) ;
if ( V_12 -> V_47 && V_137 <= V_220 && ! V_165 && ! F_83 ( V_85 ) ) {
V_72 -> V_185 . V_221 |= F_28 ( V_12 -> V_62 ) ;
V_164 |= F_100 ( ( V_163 & 0xffff ) << 8 ) ;
F_57 () ;
V_72 -> V_185 . V_222 = V_164 ;
F_57 () ;
F_85 ( V_12 -> V_43 . V_223 + V_12 -> V_43 . V_224 , ( unsigned long * ) & V_72 -> V_185 ,
V_137 ) ;
F_57 () ;
V_12 -> V_43 . V_224 ^= V_12 -> V_43 . V_27 ;
} else {
F_57 () ;
V_72 -> V_185 . V_222 = V_164 ;
F_57 () ;
F_101 ( V_12 -> V_62 , V_12 -> V_43 . V_44 -> V_38 + V_225 ) ;
}
return V_226 ;
V_177:
F_4 ( V_2 , L_15 ) ;
for ( V_76 ++ ; V_76 < F_36 ( V_85 ) -> V_89 ; V_76 ++ ) {
V_82 ++ ;
F_42 ( V_94 , ( V_95 ) F_40 ( V_82 -> V_96 ) ,
F_41 ( V_82 -> V_97 ) ,
V_98 ) ;
}
V_166:
F_44 ( V_85 ) ;
V_2 -> V_227 . V_228 ++ ;
return V_226 ;
}
