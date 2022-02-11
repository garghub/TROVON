static int F_1 ( struct V_1 * V_1 , T_1 V_2 ,
const struct V_3 * V_4 ,
unsigned long * V_5 ,
struct V_6 * V_7 ,
int (* F_2)( const struct V_6 * V_8 ,
const struct V_6 * V_9 ) ,
unsigned int log )
{
struct V_6 * V_9 ;
struct V_10 * V_11 ;
T_2 V_12 = F_3 ( V_7 ) ;
F_4 (sk2, node, &hslot->head)
if ( F_5 ( F_6 ( V_9 ) , V_1 ) &&
V_9 != V_7 &&
( V_5 || F_7 ( V_9 ) -> V_13 == V_2 ) &&
( ! V_9 -> V_14 || ! V_7 -> V_14 ) &&
( ! V_9 -> V_15 || ! V_7 -> V_15 ||
V_9 -> V_15 == V_7 -> V_15 ) &&
( ! V_9 -> V_16 || ! V_7 -> V_16 ||
! F_8 ( V_12 , F_3 ( V_9 ) ) ) &&
(* F_2)( V_7 , V_9 ) ) {
if ( V_5 )
F_9 ( F_7 ( V_9 ) -> V_13 >> log ,
V_5 ) ;
else
return 1 ;
}
return 0 ;
}
static int F_10 ( struct V_1 * V_1 , T_1 V_2 ,
struct V_3 * V_17 ,
struct V_6 * V_7 ,
int (* F_2)( const struct V_6 * V_8 ,
const struct V_6 * V_9 ) )
{
struct V_6 * V_9 ;
struct V_10 * V_11 ;
T_2 V_12 = F_3 ( V_7 ) ;
int V_18 = 0 ;
F_11 ( & V_17 -> V_19 ) ;
F_12 (sk2, node, &hslot2->head)
if ( F_5 ( F_6 ( V_9 ) , V_1 ) &&
V_9 != V_7 &&
( F_7 ( V_9 ) -> V_13 == V_2 ) &&
( ! V_9 -> V_14 || ! V_7 -> V_14 ) &&
( ! V_9 -> V_15 || ! V_7 -> V_15 ||
V_9 -> V_15 == V_7 -> V_15 ) &&
( ! V_9 -> V_16 || ! V_7 -> V_16 ||
! F_8 ( V_12 , F_3 ( V_9 ) ) ) &&
(* F_2)( V_7 , V_9 ) ) {
V_18 = 1 ;
break;
}
F_13 ( & V_17 -> V_19 ) ;
return V_18 ;
}
int F_14 ( struct V_6 * V_7 , unsigned short V_20 ,
int (* F_2)( const struct V_6 * V_8 ,
const struct V_6 * V_9 ) ,
unsigned int V_21 )
{
struct V_3 * V_4 , * V_17 ;
struct V_22 * V_23 = V_7 -> V_24 -> V_25 . V_22 ;
int error = 1 ;
struct V_1 * V_1 = F_6 ( V_7 ) ;
if ( ! V_20 ) {
int V_26 , V_27 , V_28 ;
unsigned int rand ;
unsigned short V_29 , V_30 ;
F_15 ( V_5 , V_31 ) ;
F_16 ( & V_26 , & V_27 ) ;
V_28 = ( V_27 - V_26 ) + 1 ;
rand = F_17 () ;
V_29 = ( ( ( V_32 ) rand * V_28 ) >> 32 ) + V_26 ;
rand = ( rand | 1 ) * ( V_23 -> V_33 + 1 ) ;
V_30 = V_29 + V_23 -> V_33 + 1 ;
do {
V_4 = F_18 ( V_23 , V_1 , V_29 ) ;
F_19 ( V_5 , V_31 ) ;
F_20 ( & V_4 -> V_19 ) ;
F_1 ( V_1 , V_20 , V_4 , V_5 , V_7 ,
F_2 , V_23 -> log ) ;
V_20 = V_29 ;
do {
if ( V_26 <= V_20 && V_20 <= V_27 &&
! F_21 ( V_20 >> V_23 -> log , V_5 ) &&
! F_22 ( V_20 ) )
goto V_34;
V_20 += rand ;
} while ( V_20 != V_29 );
F_23 ( & V_4 -> V_19 ) ;
} while ( ++ V_29 != V_30 );
goto V_35;
} else {
V_4 = F_18 ( V_23 , V_1 , V_20 ) ;
F_20 ( & V_4 -> V_19 ) ;
if ( V_4 -> V_36 > 10 ) {
int V_37 ;
unsigned int V_38 = F_7 ( V_7 ) -> V_39 ^ V_20 ;
V_38 &= V_23 -> V_33 ;
V_21 &= V_23 -> V_33 ;
V_17 = F_24 ( V_23 , V_38 ) ;
if ( V_4 -> V_36 < V_17 -> V_36 )
goto V_40;
V_37 = F_10 ( V_1 , V_20 , V_17 ,
V_7 , F_2 ) ;
if ( ! V_37 && ( V_21 != V_38 ) ) {
V_17 = F_24 ( V_23 , V_21 ) ;
V_37 = F_10 ( V_1 , V_20 , V_17 ,
V_7 , F_2 ) ;
}
if ( V_37 )
goto V_41;
else
goto V_34;
}
V_40:
if ( F_1 ( V_1 , V_20 , V_4 , NULL , V_7 ,
F_2 , 0 ) )
goto V_41;
}
V_34:
F_25 ( V_7 ) -> V_42 = V_20 ;
F_7 ( V_7 ) -> V_13 = V_20 ;
F_7 ( V_7 ) -> V_39 ^= V_20 ;
if ( F_26 ( V_7 ) ) {
F_27 ( V_7 , & V_4 -> V_43 ) ;
V_4 -> V_36 ++ ;
F_28 ( F_6 ( V_7 ) , V_7 -> V_24 , 1 ) ;
V_17 = F_24 ( V_23 , F_7 ( V_7 ) -> V_39 ) ;
F_11 ( & V_17 -> V_19 ) ;
F_29 ( & F_7 ( V_7 ) -> V_44 ,
& V_17 -> V_43 ) ;
V_17 -> V_36 ++ ;
F_13 ( & V_17 -> V_19 ) ;
}
error = 0 ;
V_41:
F_23 ( & V_4 -> V_19 ) ;
V_35:
return error ;
}
static int F_30 ( const struct V_6 * V_8 , const struct V_6 * V_9 )
{
struct V_45 * V_46 = F_25 ( V_8 ) , * V_47 = F_25 ( V_9 ) ;
return ( ! F_31 ( V_9 ) &&
( ! V_46 -> V_48 || ! V_47 -> V_48 ||
V_46 -> V_48 == V_47 -> V_48 ) ) ;
}
static unsigned int F_32 ( struct V_1 * V_1 , T_3 V_49 ,
unsigned int V_50 )
{
return F_33 ( ( V_51 V_52 ) V_49 , F_34 ( V_1 ) ) ^ V_50 ;
}
int F_35 ( struct V_6 * V_7 , unsigned short V_20 )
{
unsigned int V_21 =
F_32 ( F_6 ( V_7 ) , F_36 ( V_53 ) , V_20 ) ;
unsigned int V_54 =
F_32 ( F_6 ( V_7 ) , F_25 ( V_7 ) -> V_48 , 0 ) ;
F_7 ( V_7 ) -> V_39 = V_54 ;
return F_14 ( V_7 , V_20 , F_30 , V_21 ) ;
}
static inline int F_37 ( struct V_6 * V_7 , struct V_1 * V_1 , T_3 V_49 ,
unsigned short V_55 ,
T_4 V_56 , T_3 V_57 , T_4 V_58 , int V_59 )
{
int V_60 = - 1 ;
if ( F_5 ( F_6 ( V_7 ) , V_1 ) && F_7 ( V_7 ) -> V_13 == V_55 &&
! F_31 ( V_7 ) ) {
struct V_45 * V_61 = F_25 ( V_7 ) ;
V_60 = ( V_7 -> V_62 == V_63 ? 2 : 1 ) ;
if ( V_61 -> V_48 ) {
if ( V_61 -> V_48 != V_57 )
return - 1 ;
V_60 += 4 ;
}
if ( V_61 -> V_64 ) {
if ( V_61 -> V_64 != V_49 )
return - 1 ;
V_60 += 4 ;
}
if ( V_61 -> V_65 ) {
if ( V_61 -> V_65 != V_56 )
return - 1 ;
V_60 += 4 ;
}
if ( V_7 -> V_15 ) {
if ( V_7 -> V_15 != V_59 )
return - 1 ;
V_60 += 4 ;
}
}
return V_60 ;
}
static inline int F_38 ( struct V_6 * V_7 , struct V_1 * V_1 ,
T_3 V_49 , T_4 V_56 ,
T_3 V_57 , unsigned int V_55 , int V_59 )
{
int V_60 = - 1 ;
if ( F_5 ( F_6 ( V_7 ) , V_1 ) && ! F_31 ( V_7 ) ) {
struct V_45 * V_61 = F_25 ( V_7 ) ;
if ( V_61 -> V_48 != V_57 )
return - 1 ;
if ( V_61 -> V_42 != V_55 )
return - 1 ;
V_60 = ( V_7 -> V_62 == V_63 ? 2 : 1 ) ;
if ( V_61 -> V_64 ) {
if ( V_61 -> V_64 != V_49 )
return - 1 ;
V_60 += 4 ;
}
if ( V_61 -> V_65 ) {
if ( V_61 -> V_65 != V_56 )
return - 1 ;
V_60 += 4 ;
}
if ( V_7 -> V_15 ) {
if ( V_7 -> V_15 != V_59 )
return - 1 ;
V_60 += 4 ;
}
}
return V_60 ;
}
static struct V_6 * F_39 ( struct V_1 * V_1 ,
T_3 V_49 , T_4 V_56 ,
T_3 V_57 , unsigned int V_55 , int V_59 ,
struct V_3 * V_17 , unsigned int V_38 )
{
struct V_6 * V_7 , * V_66 ;
struct V_10 * V_11 ;
int V_60 , V_67 , V_68 = 0 , V_69 = 0 ;
V_52 V_70 = 0 ;
V_71:
V_66 = NULL ;
V_67 = 0 ;
F_40 (sk, node, &hslot2->head) {
V_60 = F_38 ( V_7 , V_1 , V_49 , V_56 ,
V_57 , V_55 , V_59 ) ;
if ( V_60 > V_67 ) {
V_66 = V_7 ;
V_67 = V_60 ;
V_69 = V_7 -> V_16 ;
if ( V_69 ) {
V_70 = F_41 ( V_1 , V_57 , V_55 ,
V_49 , F_42 ( V_56 ) ) ;
V_68 = 1 ;
}
} else if ( V_60 == V_67 && V_69 ) {
V_68 ++ ;
if ( ( ( V_32 ) V_70 * V_68 ) >> 32 == 0 )
V_66 = V_7 ;
V_70 = F_43 ( V_70 ) ;
}
}
if ( F_44 ( V_11 ) != V_38 )
goto V_71;
if ( V_66 ) {
if ( F_45 ( ! F_46 ( & V_66 -> V_72 , 2 ) ) )
V_66 = NULL ;
else if ( F_45 ( F_38 ( V_66 , V_1 , V_49 , V_56 ,
V_57 , V_55 , V_59 ) < V_67 ) ) {
F_47 ( V_66 ) ;
goto V_71;
}
}
return V_66 ;
}
struct V_6 * F_48 ( struct V_1 * V_1 , T_3 V_49 ,
T_4 V_56 , T_3 V_57 , T_4 V_58 ,
int V_59 , struct V_22 * V_23 )
{
struct V_6 * V_7 , * V_66 ;
struct V_10 * V_11 ;
unsigned short V_55 = F_49 ( V_58 ) ;
unsigned int V_73 , V_38 , V_74 = F_50 ( V_1 , V_55 , V_23 -> V_33 ) ;
struct V_3 * V_17 , * V_4 = & V_23 -> V_70 [ V_74 ] ;
int V_60 , V_67 , V_68 = 0 , V_69 = 0 ;
V_52 V_70 = 0 ;
F_51 () ;
if ( V_4 -> V_36 > 10 ) {
V_73 = F_32 ( V_1 , V_57 , V_55 ) ;
V_38 = V_73 & V_23 -> V_33 ;
V_17 = & V_23 -> V_73 [ V_38 ] ;
if ( V_4 -> V_36 < V_17 -> V_36 )
goto V_71;
V_66 = F_39 ( V_1 , V_49 , V_56 ,
V_57 , V_55 , V_59 ,
V_17 , V_38 ) ;
if ( ! V_66 ) {
V_73 = F_32 ( V_1 , F_36 ( V_53 ) , V_55 ) ;
V_38 = V_73 & V_23 -> V_33 ;
V_17 = & V_23 -> V_73 [ V_38 ] ;
if ( V_4 -> V_36 < V_17 -> V_36 )
goto V_71;
V_66 = F_39 ( V_1 , V_49 , V_56 ,
F_36 ( V_53 ) , V_55 , V_59 ,
V_17 , V_38 ) ;
}
F_52 () ;
return V_66 ;
}
V_71:
V_66 = NULL ;
V_67 = 0 ;
F_53 (sk, node, &hslot->head) {
V_60 = F_37 ( V_7 , V_1 , V_49 , V_55 , V_56 ,
V_57 , V_58 , V_59 ) ;
if ( V_60 > V_67 ) {
V_66 = V_7 ;
V_67 = V_60 ;
V_69 = V_7 -> V_16 ;
if ( V_69 ) {
V_70 = F_41 ( V_1 , V_57 , V_55 ,
V_49 , F_42 ( V_56 ) ) ;
V_68 = 1 ;
}
} else if ( V_60 == V_67 && V_69 ) {
V_68 ++ ;
if ( ( ( V_32 ) V_70 * V_68 ) >> 32 == 0 )
V_66 = V_7 ;
V_70 = F_43 ( V_70 ) ;
}
}
if ( F_44 ( V_11 ) != V_74 )
goto V_71;
if ( V_66 ) {
if ( F_45 ( ! F_46 ( & V_66 -> V_72 , 2 ) ) )
V_66 = NULL ;
else if ( F_45 ( F_37 ( V_66 , V_1 , V_49 , V_55 , V_56 ,
V_57 , V_58 , V_59 ) < V_67 ) ) {
F_47 ( V_66 ) ;
goto V_71;
}
}
F_52 () ;
return V_66 ;
}
static inline struct V_6 * F_54 ( struct V_75 * V_76 ,
T_4 V_56 , T_4 V_58 ,
struct V_22 * V_23 )
{
struct V_6 * V_7 ;
const struct V_77 * V_78 = F_55 ( V_76 ) ;
if ( F_45 ( V_7 = F_56 ( V_76 ) ) )
return V_7 ;
else
return F_48 ( F_57 ( F_58 ( V_76 ) -> V_79 ) , V_78 -> V_49 , V_56 ,
V_78 -> V_57 , V_58 , F_59 ( V_76 ) ,
V_23 ) ;
}
struct V_6 * F_60 ( struct V_1 * V_1 , T_3 V_49 , T_4 V_56 ,
T_3 V_57 , T_4 V_58 , int V_59 )
{
return F_48 ( V_1 , V_49 , V_56 , V_57 , V_58 , V_59 , & V_22 ) ;
}
static inline struct V_6 * F_61 ( struct V_1 * V_1 , struct V_6 * V_7 ,
T_4 V_80 , T_3 V_81 ,
T_4 V_82 , T_3 V_83 ,
int V_59 )
{
struct V_10 * V_11 ;
struct V_6 * V_84 = V_7 ;
unsigned short V_55 = F_49 ( V_80 ) ;
F_62 (s, node) {
struct V_45 * V_61 = F_25 ( V_84 ) ;
if ( ! F_5 ( F_6 ( V_84 ) , V_1 ) ||
F_7 ( V_84 ) -> V_13 != V_55 ||
( V_61 -> V_64 && V_61 -> V_64 != V_83 ) ||
( V_61 -> V_65 != V_82 && V_61 -> V_65 ) ||
( V_61 -> V_48 &&
V_61 -> V_48 != V_81 ) ||
F_31 ( V_84 ) ||
( V_84 -> V_15 && V_84 -> V_15 != V_59 ) )
continue;
if ( ! F_63 ( V_84 , V_81 , V_83 , V_59 ) )
continue;
goto V_34;
}
V_84 = NULL ;
V_34:
return V_84 ;
}
void F_64 ( struct V_75 * V_76 , V_52 V_85 , struct V_22 * V_23 )
{
struct V_45 * V_61 ;
const struct V_77 * V_78 = ( const struct V_77 * ) V_76 -> V_86 ;
struct V_87 * V_88 = (struct V_87 * ) ( V_76 -> V_86 + ( V_78 -> V_89 << 2 ) ) ;
const int type = F_65 ( V_76 ) -> type ;
const int V_90 = F_65 ( V_76 ) -> V_90 ;
struct V_6 * V_7 ;
int V_91 ;
int V_92 ;
struct V_1 * V_1 = F_57 ( V_76 -> V_79 ) ;
V_7 = F_48 ( V_1 , V_78 -> V_57 , V_88 -> V_93 ,
V_78 -> V_49 , V_88 -> V_94 , V_76 -> V_79 -> V_95 , V_23 ) ;
if ( V_7 == NULL ) {
F_66 ( V_1 , V_96 ) ;
return;
}
V_92 = 0 ;
V_91 = 0 ;
V_61 = F_25 ( V_7 ) ;
switch ( type ) {
default:
case V_97 :
V_92 = V_98 ;
break;
case V_99 :
goto V_100;
case V_101 :
V_92 = V_102 ;
V_91 = 1 ;
break;
case V_103 :
if ( V_90 == V_104 ) {
F_67 ( V_76 , V_7 , V_85 ) ;
if ( V_61 -> V_105 != V_106 ) {
V_92 = V_107 ;
V_91 = 1 ;
break;
}
goto V_100;
}
V_92 = V_98 ;
if ( V_90 <= V_108 ) {
V_91 = V_109 [ V_90 ] . V_110 ;
V_92 = V_109 [ V_90 ] . V_111 ;
}
break;
case V_112 :
F_68 ( V_76 , V_7 ) ;
break;
}
if ( ! V_61 -> V_113 ) {
if ( ! V_91 || V_7 -> V_114 != V_115 )
goto V_100;
} else
F_69 ( V_7 , V_76 , V_92 , V_88 -> V_93 , V_85 , ( V_116 * ) ( V_88 + 1 ) ) ;
V_7 -> V_117 = V_92 ;
V_7 -> V_118 ( V_7 ) ;
V_100:
F_47 ( V_7 ) ;
}
void F_70 ( struct V_75 * V_76 , V_52 V_85 )
{
F_64 ( V_76 , V_85 , & V_22 ) ;
}
void F_71 ( struct V_6 * V_7 )
{
struct V_119 * V_120 = F_7 ( V_7 ) ;
if ( V_120 -> V_121 ) {
V_120 -> V_122 = 0 ;
V_120 -> V_121 = 0 ;
F_72 ( V_7 ) ;
}
}
static void F_73 ( struct V_75 * V_76 , T_3 V_123 , T_3 V_124 )
{
struct V_87 * V_88 = F_74 ( V_76 ) ;
struct V_75 * V_125 = F_75 ( V_76 ) -> V_126 ;
int V_127 = F_76 ( V_76 ) ;
int V_122 = V_76 -> V_122 - V_127 ;
int V_128 = V_122 ;
T_5 V_129 = 0 ;
if ( ! V_125 ) {
V_76 -> V_130 = F_77 ( V_76 ) - V_76 -> V_43 ;
V_76 -> V_131 = F_78 ( struct V_87 , V_132 ) ;
V_88 -> V_132 = ~ F_79 ( V_123 , V_124 , V_122 ,
V_133 , 0 ) ;
} else {
do {
V_129 = F_80 ( V_129 , V_125 -> V_129 ) ;
V_128 -= V_125 -> V_122 ;
} while ( ( V_125 = V_125 -> V_134 ) );
V_129 = F_81 ( V_76 , V_127 , V_128 , V_129 ) ;
V_76 -> V_135 = V_136 ;
V_88 -> V_132 = F_79 ( V_123 , V_124 , V_122 , V_133 , V_129 ) ;
if ( V_88 -> V_132 == 0 )
V_88 -> V_132 = V_137 ;
}
}
static int F_82 ( struct V_75 * V_76 , struct V_138 * V_139 )
{
struct V_6 * V_7 = V_76 -> V_7 ;
struct V_45 * V_61 = F_25 ( V_7 ) ;
struct V_87 * V_88 ;
int V_92 = 0 ;
int V_140 = F_83 ( V_7 ) ;
int V_127 = F_76 ( V_76 ) ;
int V_122 = V_76 -> V_122 - V_127 ;
T_5 V_129 = 0 ;
V_88 = F_74 ( V_76 ) ;
V_88 -> V_94 = V_61 -> V_141 ;
V_88 -> V_93 = V_139 -> V_142 ;
V_88 -> V_122 = F_42 ( V_122 ) ;
V_88 -> V_132 = 0 ;
if ( V_140 )
V_129 = F_84 ( V_76 ) ;
else if ( V_7 -> V_143 == V_144 ) {
V_76 -> V_135 = V_136 ;
goto V_145;
} else if ( V_76 -> V_135 == V_146 ) {
F_73 ( V_76 , V_139 -> V_49 , V_139 -> V_57 ) ;
goto V_145;
} else
V_129 = F_85 ( V_76 ) ;
V_88 -> V_132 = F_79 ( V_139 -> V_49 , V_139 -> V_57 , V_122 ,
V_7 -> V_147 , V_129 ) ;
if ( V_88 -> V_132 == 0 )
V_88 -> V_132 = V_137 ;
V_145:
V_92 = F_86 ( F_6 ( V_7 ) , V_76 ) ;
if ( V_92 ) {
if ( V_92 == - V_148 && ! V_61 -> V_113 ) {
F_87 ( F_6 ( V_7 ) ,
V_149 , V_140 ) ;
V_92 = 0 ;
}
} else
F_87 ( F_6 ( V_7 ) ,
V_150 , V_140 ) ;
return V_92 ;
}
static int F_88 ( struct V_6 * V_7 )
{
struct V_119 * V_120 = F_7 ( V_7 ) ;
struct V_45 * V_61 = F_25 ( V_7 ) ;
struct V_138 * V_139 = & V_61 -> V_151 . V_152 . V_153 . V_154 ;
struct V_75 * V_76 ;
int V_92 = 0 ;
V_76 = F_89 ( V_7 , V_139 ) ;
if ( ! V_76 )
goto V_100;
V_92 = F_82 ( V_76 , V_139 ) ;
V_100:
V_120 -> V_122 = 0 ;
V_120 -> V_121 = 0 ;
return V_92 ;
}
int F_90 ( struct V_155 * V_156 , struct V_6 * V_7 , struct V_157 * V_158 ,
T_6 V_122 )
{
struct V_45 * V_61 = F_25 ( V_7 ) ;
struct V_119 * V_120 = F_7 ( V_7 ) ;
struct V_138 V_159 ;
struct V_138 * V_139 ;
int V_160 = V_122 ;
struct V_161 V_162 ;
struct V_163 * V_164 = NULL ;
int free = 0 ;
int V_165 = 0 ;
T_3 V_57 , V_166 , V_49 ;
T_4 V_58 ;
V_116 V_167 ;
int V_92 , V_140 = F_83 ( V_7 ) ;
int V_168 = V_120 -> V_169 || V_158 -> V_170 & V_171 ;
int (* F_91)( void * , char * , int , int , int , struct V_75 * );
struct V_75 * V_76 ;
struct V_172 V_173 ;
if ( V_122 > 0xFFFF )
return - V_107 ;
if ( V_158 -> V_170 & V_174 )
return - V_175 ;
V_162 . V_176 = NULL ;
V_162 . V_177 = 0 ;
F_91 = V_140 ? V_178 : V_179 ;
V_139 = & V_61 -> V_151 . V_152 . V_153 . V_154 ;
if ( V_120 -> V_121 ) {
F_92 ( V_7 ) ;
if ( F_93 ( V_120 -> V_121 ) ) {
if ( F_45 ( V_120 -> V_121 != V_180 ) ) {
F_94 ( V_7 ) ;
return - V_181 ;
}
goto V_182;
}
F_94 ( V_7 ) ;
}
V_160 += sizeof( struct V_87 ) ;
if ( V_158 -> V_183 ) {
struct V_184 * V_185 = (struct V_184 * ) V_158 -> V_183 ;
if ( V_158 -> V_186 < sizeof( * V_185 ) )
return - V_181 ;
if ( V_185 -> V_187 != V_180 ) {
if ( V_185 -> V_187 != V_188 )
return - V_189 ;
}
V_57 = V_185 -> V_190 . V_191 ;
V_58 = V_185 -> V_192 ;
if ( V_58 == 0 )
return - V_181 ;
} else {
if ( V_7 -> V_114 != V_115 )
return - V_193 ;
V_57 = V_61 -> V_64 ;
V_58 = V_61 -> V_65 ;
V_165 = 1 ;
}
V_162 . V_194 = V_61 -> V_195 ;
V_162 . V_196 = V_7 -> V_15 ;
V_92 = F_95 ( V_7 , & V_162 . V_177 ) ;
if ( V_92 )
return V_92 ;
if ( V_158 -> V_197 ) {
V_92 = F_96 ( F_6 ( V_7 ) , V_158 , & V_162 ) ;
if ( V_92 )
return V_92 ;
if ( V_162 . V_176 )
free = 1 ;
V_165 = 0 ;
}
if ( ! V_162 . V_176 ) {
struct V_198 * V_199 ;
F_51 () ;
V_199 = F_97 ( V_61 -> V_199 ) ;
if ( V_199 ) {
memcpy ( & V_173 , V_199 ,
sizeof( * V_199 ) + V_199 -> V_176 . V_200 ) ;
V_162 . V_176 = & V_173 . V_176 ;
}
F_52 () ;
}
V_49 = V_162 . V_194 ;
V_162 . V_194 = V_166 = V_57 ;
if ( V_162 . V_176 && V_162 . V_176 -> V_176 . V_201 ) {
if ( ! V_57 )
return - V_181 ;
V_166 = V_162 . V_176 -> V_176 . V_166 ;
V_165 = 0 ;
}
V_167 = F_98 ( V_61 -> V_167 ) ;
if ( F_99 ( V_7 , V_202 ) ||
( V_158 -> V_170 & V_203 ) ||
( V_162 . V_176 && V_162 . V_176 -> V_176 . V_204 ) ) {
V_167 |= V_205 ;
V_165 = 0 ;
}
if ( F_100 ( V_57 ) ) {
if ( ! V_162 . V_196 )
V_162 . V_196 = V_61 -> V_206 ;
if ( ! V_49 )
V_49 = V_61 -> V_207 ;
V_165 = 0 ;
} else if ( ! V_162 . V_196 )
V_162 . V_196 = V_61 -> V_208 ;
if ( V_165 )
V_164 = (struct V_163 * ) F_101 ( V_7 , 0 ) ;
if ( V_164 == NULL ) {
struct V_1 * V_1 = F_6 ( V_7 ) ;
V_139 = & V_159 ;
F_102 ( V_139 , V_162 . V_196 , V_7 -> V_209 , V_167 ,
V_210 , V_7 -> V_147 ,
F_103 ( V_7 ) | V_211 ,
V_166 , V_49 , V_58 , V_61 -> V_141 ) ;
F_104 ( V_7 , F_105 ( V_139 ) ) ;
V_164 = F_106 ( V_1 , V_139 , V_7 ) ;
if ( F_107 ( V_164 ) ) {
V_92 = F_108 ( V_164 ) ;
V_164 = NULL ;
if ( V_92 == - V_212 )
F_109 ( V_1 , V_213 ) ;
goto V_100;
}
V_92 = - V_214 ;
if ( ( V_164 -> V_215 & V_216 ) &&
! F_99 ( V_7 , V_217 ) )
goto V_100;
if ( V_165 )
F_110 ( V_7 , F_111 ( & V_164 -> V_124 ) ) ;
}
if ( V_158 -> V_170 & V_218 )
goto V_219;
V_220:
V_49 = V_139 -> V_49 ;
if ( ! V_162 . V_194 )
V_57 = V_162 . V_194 = V_139 -> V_57 ;
if ( ! V_168 ) {
V_76 = F_112 ( V_7 , V_139 , F_91 , V_158 -> V_221 , V_160 ,
sizeof( struct V_87 ) , & V_162 , & V_164 ,
V_158 -> V_170 ) ;
V_92 = F_108 ( V_76 ) ;
if ( ! F_113 ( V_76 ) )
V_92 = F_82 ( V_76 , V_139 ) ;
goto V_100;
}
F_92 ( V_7 ) ;
if ( F_45 ( V_120 -> V_121 ) ) {
F_94 ( V_7 ) ;
F_114 (KERN_DEBUG pr_fmt(L_1)) ;
V_92 = - V_181 ;
goto V_100;
}
V_139 = & V_61 -> V_151 . V_152 . V_153 . V_154 ;
V_139 -> V_57 = V_57 ;
V_139 -> V_49 = V_49 ;
V_139 -> V_142 = V_58 ;
V_139 -> V_222 = V_61 -> V_141 ;
V_120 -> V_121 = V_180 ;
V_182:
V_120 -> V_122 += V_160 ;
V_92 = F_115 ( V_7 , V_139 , F_91 , V_158 -> V_221 , V_160 ,
sizeof( struct V_87 ) , & V_162 , & V_164 ,
V_168 ? V_158 -> V_170 | V_171 : V_158 -> V_170 ) ;
if ( V_92 )
F_71 ( V_7 ) ;
else if ( ! V_168 )
V_92 = F_88 ( V_7 ) ;
else if ( F_45 ( F_116 ( & V_7 -> V_223 ) ) )
V_120 -> V_121 = 0 ;
F_94 ( V_7 ) ;
V_100:
F_117 ( V_164 ) ;
if ( free )
F_118 ( V_162 . V_176 ) ;
if ( ! V_92 )
return V_122 ;
if ( V_92 == - V_148 || F_21 ( V_224 , & V_7 -> V_225 -> V_226 ) ) {
F_87 ( F_6 ( V_7 ) ,
V_149 , V_140 ) ;
}
return V_92 ;
V_219:
F_119 ( & V_164 -> V_124 ) ;
if ( ! ( V_158 -> V_170 & V_227 ) || V_122 )
goto V_220;
V_92 = 0 ;
goto V_100;
}
int F_120 ( struct V_6 * V_7 , struct V_228 * V_228 , int V_127 ,
T_6 V_229 , int V_226 )
{
struct V_45 * V_61 = F_25 ( V_7 ) ;
struct V_119 * V_120 = F_7 ( V_7 ) ;
int V_230 ;
if ( ! V_120 -> V_121 ) {
struct V_157 V_158 = { . V_170 = V_226 | V_171 } ;
V_230 = F_90 ( NULL , V_7 , & V_158 , 0 ) ;
if ( V_230 < 0 )
return V_230 ;
}
F_92 ( V_7 ) ;
if ( F_45 ( ! V_120 -> V_121 ) ) {
F_94 ( V_7 ) ;
F_114 (KERN_DEBUG pr_fmt(L_2)) ;
return - V_181 ;
}
V_230 = F_121 ( V_7 , & V_61 -> V_151 . V_152 . V_153 . V_154 ,
V_228 , V_127 , V_229 , V_226 ) ;
if ( V_230 == - V_175 ) {
F_94 ( V_7 ) ;
return F_122 ( V_7 -> V_225 , V_228 , V_127 ,
V_229 , V_226 ) ;
}
if ( V_230 < 0 ) {
F_71 ( V_7 ) ;
goto V_100;
}
V_120 -> V_122 += V_229 ;
if ( ! ( V_120 -> V_169 || ( V_226 & V_171 ) ) )
V_230 = F_88 ( V_7 ) ;
if ( ! V_230 )
V_230 = V_229 ;
V_100:
F_94 ( V_7 ) ;
return V_230 ;
}
static unsigned int F_123 ( struct V_6 * V_7 )
{
struct V_231 V_232 , * V_233 = & V_7 -> V_234 ;
struct V_75 * V_76 ;
unsigned int V_18 ;
F_124 ( & V_232 ) ;
F_20 ( & V_233 -> V_19 ) ;
while ( ( V_76 = F_125 ( V_233 ) ) != NULL &&
F_126 ( V_76 ) ) {
F_127 ( F_6 ( V_7 ) , V_235 ,
F_83 ( V_7 ) ) ;
F_128 ( & V_7 -> V_236 ) ;
F_129 ( V_76 , V_233 ) ;
F_130 ( & V_232 , V_76 ) ;
}
V_18 = V_76 ? V_76 -> V_122 : 0 ;
F_23 ( & V_233 -> V_19 ) ;
if ( ! F_116 ( & V_232 ) ) {
bool V_237 = F_131 ( V_7 ) ;
F_132 ( & V_232 ) ;
F_133 ( V_7 ) ;
F_134 ( V_7 , V_237 ) ;
}
return V_18 ;
}
int F_135 ( struct V_6 * V_7 , int V_238 , unsigned long V_239 )
{
switch ( V_238 ) {
case V_240 :
{
int V_241 = F_136 ( V_7 ) ;
return F_137 ( V_241 , ( int V_242 * ) V_239 ) ;
}
case V_243 :
{
unsigned int V_241 = F_123 ( V_7 ) ;
if ( V_241 )
V_241 -= sizeof( struct V_87 ) ;
return F_137 ( V_241 , ( int V_242 * ) V_239 ) ;
}
default:
return - V_244 ;
}
return 0 ;
}
int F_138 ( struct V_155 * V_156 , struct V_6 * V_7 , struct V_157 * V_158 ,
T_6 V_122 , int V_245 , int V_226 , int * V_246 )
{
struct V_45 * V_61 = F_25 ( V_7 ) ;
struct V_184 * sin = (struct V_184 * ) V_158 -> V_183 ;
struct V_75 * V_76 ;
unsigned int V_160 , V_247 ;
int V_248 , V_249 = 0 ;
int V_92 ;
int V_140 = F_83 ( V_7 ) ;
bool V_237 ;
if ( V_246 )
* V_246 = sizeof( * sin ) ;
if ( V_226 & V_250 )
return F_139 ( V_7 , V_158 , V_122 ) ;
V_251:
V_76 = F_140 ( V_7 , V_226 | ( V_245 ? V_252 : 0 ) ,
& V_248 , & V_249 , & V_92 ) ;
if ( ! V_76 )
goto V_100;
V_160 = V_76 -> V_122 - sizeof( struct V_87 ) ;
V_247 = V_122 ;
if ( V_247 > V_160 )
V_247 = V_160 ;
else if ( V_247 < V_160 )
V_158 -> V_170 |= V_253 ;
if ( V_247 < V_160 || F_141 ( V_76 ) -> V_254 ) {
if ( F_126 ( V_76 ) )
goto V_255;
}
if ( F_142 ( V_76 ) )
V_92 = F_143 ( V_76 , sizeof( struct V_87 ) ,
V_158 -> V_221 , V_247 ) ;
else {
V_92 = F_144 ( V_76 ,
sizeof( struct V_87 ) ,
V_158 -> V_221 ) ;
if ( V_92 == - V_181 )
goto V_255;
}
if ( F_45 ( V_92 ) ) {
F_145 ( V_76 , F_138 ) ;
if ( ! V_248 ) {
F_128 ( & V_7 -> V_236 ) ;
F_87 ( F_6 ( V_7 ) ,
V_235 , V_140 ) ;
}
goto V_256;
}
if ( ! V_248 )
F_87 ( F_6 ( V_7 ) ,
V_257 , V_140 ) ;
F_146 ( V_158 , V_7 , V_76 ) ;
if ( sin ) {
sin -> V_187 = V_180 ;
sin -> V_192 = F_74 ( V_76 ) -> V_94 ;
sin -> V_190 . V_191 = F_55 ( V_76 ) -> V_49 ;
memset ( sin -> V_258 , 0 , sizeof( sin -> V_258 ) ) ;
}
if ( V_61 -> V_259 )
F_147 ( V_158 , V_76 ) ;
V_92 = V_247 ;
if ( V_226 & V_253 )
V_92 = V_160 ;
V_256:
F_148 ( V_7 , V_76 ) ;
V_100:
return V_92 ;
V_255:
V_237 = F_131 ( V_7 ) ;
if ( ! F_149 ( V_7 , V_76 , V_226 ) )
F_87 ( F_6 ( V_7 ) , V_235 , V_140 ) ;
F_134 ( V_7 , V_237 ) ;
if ( V_245 )
return - V_260 ;
V_158 -> V_170 &= ~ V_253 ;
goto V_251;
}
int F_150 ( struct V_6 * V_7 , int V_226 )
{
struct V_45 * V_61 = F_25 ( V_7 ) ;
V_7 -> V_114 = V_261 ;
V_61 -> V_64 = 0 ;
V_61 -> V_65 = 0 ;
F_151 ( V_7 ) ;
V_7 -> V_15 = 0 ;
if ( ! ( V_7 -> V_262 & V_263 ) )
F_152 ( V_7 ) ;
if ( ! ( V_7 -> V_262 & V_264 ) ) {
V_7 -> V_24 -> V_265 ( V_7 ) ;
V_61 -> V_141 = 0 ;
}
F_153 ( V_7 ) ;
return 0 ;
}
void F_154 ( struct V_6 * V_7 )
{
if ( F_155 ( V_7 ) ) {
struct V_22 * V_23 = V_7 -> V_24 -> V_25 . V_22 ;
struct V_3 * V_4 , * V_17 ;
V_4 = F_18 ( V_23 , F_6 ( V_7 ) ,
F_7 ( V_7 ) -> V_13 ) ;
V_17 = F_24 ( V_23 , F_7 ( V_7 ) -> V_39 ) ;
F_20 ( & V_4 -> V_19 ) ;
if ( F_156 ( V_7 ) ) {
V_4 -> V_36 -- ;
F_25 ( V_7 ) -> V_42 = 0 ;
F_28 ( F_6 ( V_7 ) , V_7 -> V_24 , - 1 ) ;
F_11 ( & V_17 -> V_19 ) ;
F_157 ( & F_7 ( V_7 ) -> V_44 ) ;
V_17 -> V_36 -- ;
F_13 ( & V_17 -> V_19 ) ;
}
F_23 ( & V_4 -> V_19 ) ;
}
}
void F_158 ( struct V_6 * V_7 , T_7 V_266 )
{
if ( F_155 ( V_7 ) ) {
struct V_22 * V_23 = V_7 -> V_24 -> V_25 . V_22 ;
struct V_3 * V_4 , * V_17 , * V_267 ;
V_17 = F_24 ( V_23 , F_7 ( V_7 ) -> V_39 ) ;
V_267 = F_24 ( V_23 , V_266 ) ;
F_7 ( V_7 ) -> V_39 = V_266 ;
if ( V_17 != V_267 ) {
V_4 = F_18 ( V_23 , F_6 ( V_7 ) ,
F_7 ( V_7 ) -> V_13 ) ;
F_20 ( & V_4 -> V_19 ) ;
F_11 ( & V_17 -> V_19 ) ;
F_157 ( & F_7 ( V_7 ) -> V_44 ) ;
V_17 -> V_36 -- ;
F_13 ( & V_17 -> V_19 ) ;
F_11 ( & V_267 -> V_19 ) ;
F_29 ( & F_7 ( V_7 ) -> V_44 ,
& V_267 -> V_43 ) ;
V_267 -> V_36 ++ ;
F_13 ( & V_267 -> V_19 ) ;
F_23 ( & V_4 -> V_19 ) ;
}
}
}
static void F_159 ( struct V_6 * V_7 )
{
T_7 V_268 = F_32 ( F_6 ( V_7 ) ,
F_25 ( V_7 ) -> V_48 ,
F_25 ( V_7 ) -> V_42 ) ;
F_158 ( V_7 , V_268 ) ;
}
static int F_160 ( struct V_6 * V_7 , struct V_75 * V_76 )
{
int V_269 ;
if ( F_25 ( V_7 ) -> V_64 )
F_161 ( V_7 , V_76 ) ;
V_269 = F_162 ( V_7 , V_76 ) ;
if ( V_269 < 0 ) {
int V_140 = F_83 ( V_7 ) ;
if ( V_269 == - V_270 )
F_127 ( F_6 ( V_7 ) , V_271 ,
V_140 ) ;
F_127 ( F_6 ( V_7 ) , V_235 , V_140 ) ;
F_163 ( V_76 ) ;
F_164 ( V_269 , V_7 ) ;
return - 1 ;
}
return 0 ;
}
void F_165 ( void )
{
if ( ! F_166 ( & V_272 ) )
F_167 ( & V_272 ) ;
}
int F_168 ( struct V_6 * V_7 , struct V_75 * V_76 )
{
struct V_119 * V_120 = F_7 ( V_7 ) ;
int V_269 ;
int V_140 = F_83 ( V_7 ) ;
if ( ! F_169 ( V_7 , V_273 , V_76 ) )
goto V_274;
F_170 ( V_76 ) ;
if ( F_171 ( & V_272 ) && V_120 -> V_275 ) {
int (* F_172)( struct V_6 * V_7 , struct V_75 * V_76 );
F_172 = F_173 ( V_120 -> F_172 ) ;
if ( V_76 -> V_122 > sizeof( struct V_87 ) && F_172 != NULL ) {
int V_230 ;
V_230 = F_172 ( V_7 , V_76 ) ;
if ( V_230 <= 0 ) {
F_127 ( F_6 ( V_7 ) ,
V_257 ,
V_140 ) ;
return - V_230 ;
}
}
}
if ( ( V_140 & V_276 ) && F_141 ( V_76 ) -> V_254 ) {
if ( V_120 -> V_277 == 0 ) {
F_114 ( V_278 L_3 ,
F_141 ( V_76 ) -> V_279 , V_76 -> V_122 ) ;
goto V_274;
}
if ( F_141 ( V_76 ) -> V_279 < V_120 -> V_277 ) {
F_114 ( V_278 L_4 ,
F_141 ( V_76 ) -> V_279 , V_120 -> V_277 ) ;
goto V_274;
}
}
if ( F_174 ( V_7 -> V_280 ) &&
F_126 ( V_76 ) )
goto V_274;
if ( F_175 ( V_7 , V_76 , V_7 -> V_281 ) )
goto V_274;
V_269 = 0 ;
F_176 ( V_76 ) ;
F_177 ( V_7 ) ;
if ( ! F_178 ( V_7 ) )
V_269 = F_160 ( V_7 , V_76 ) ;
else if ( F_179 ( V_7 , V_76 , V_7 -> V_281 ) ) {
F_180 ( V_7 ) ;
goto V_274;
}
F_180 ( V_7 ) ;
return V_269 ;
V_274:
F_127 ( F_6 ( V_7 ) , V_235 , V_140 ) ;
F_128 ( & V_7 -> V_236 ) ;
F_163 ( V_76 ) ;
return - 1 ;
}
static void F_181 ( struct V_6 * * V_282 , unsigned int V_36 ,
struct V_75 * V_76 , unsigned int V_283 )
{
unsigned int V_284 ;
struct V_75 * V_285 = NULL ;
struct V_6 * V_7 ;
for ( V_284 = 0 ; V_284 < V_36 ; V_284 ++ ) {
V_7 = V_282 [ V_284 ] ;
if ( F_93 ( V_285 == NULL ) )
V_285 = ( V_284 == V_283 ) ? V_76 : F_182 ( V_76 , V_286 ) ;
if ( ! V_285 ) {
F_128 ( & V_7 -> V_236 ) ;
F_127 ( F_6 ( V_7 ) , V_271 ,
F_83 ( V_7 ) ) ;
F_127 ( F_6 ( V_7 ) , V_235 ,
F_83 ( V_7 ) ) ;
}
if ( V_285 && F_168 ( V_7 , V_285 ) <= 0 )
V_285 = NULL ;
}
if ( F_45 ( V_285 ) )
F_163 ( V_285 ) ;
}
static int F_183 ( struct V_1 * V_1 , struct V_75 * V_76 ,
struct V_87 * V_88 ,
T_3 V_49 , T_3 V_57 ,
struct V_22 * V_23 )
{
struct V_6 * V_7 , * V_282 [ 256 / sizeof( struct V_6 * ) ] ;
struct V_3 * V_4 = F_18 ( V_23 , V_1 , F_49 ( V_88 -> V_93 ) ) ;
int V_59 ;
unsigned int V_284 , V_36 = 0 ;
F_11 ( & V_4 -> V_19 ) ;
V_7 = F_184 ( & V_4 -> V_43 ) ;
V_59 = V_76 -> V_79 -> V_95 ;
V_7 = F_61 ( V_1 , V_7 , V_88 -> V_93 , V_57 , V_88 -> V_94 , V_49 , V_59 ) ;
while ( V_7 ) {
V_282 [ V_36 ++ ] = V_7 ;
V_7 = F_61 ( V_1 , F_185 ( V_7 ) , V_88 -> V_93 ,
V_57 , V_88 -> V_94 , V_49 , V_59 ) ;
if ( F_45 ( V_36 == F_186 ( V_282 ) ) ) {
if ( ! V_7 )
break;
F_181 ( V_282 , V_36 , V_76 , ~ 0 ) ;
V_36 = 0 ;
}
}
for ( V_284 = 0 ; V_284 < V_36 ; V_284 ++ )
F_187 ( V_282 [ V_284 ] ) ;
F_13 ( & V_4 -> V_19 ) ;
if ( V_36 ) {
F_181 ( V_282 , V_36 , V_76 , V_36 - 1 ) ;
for ( V_284 = 0 ; V_284 < V_36 ; V_284 ++ )
F_47 ( V_282 [ V_284 ] ) ;
} else {
F_163 ( V_76 ) ;
}
return 0 ;
}
static inline int F_188 ( struct V_75 * V_76 , struct V_87 * V_88 ,
int V_287 )
{
const struct V_77 * V_78 ;
int V_92 ;
F_141 ( V_76 ) -> V_254 = 0 ;
F_141 ( V_76 ) -> V_279 = V_76 -> V_122 ;
if ( V_287 == V_288 ) {
V_92 = F_189 ( V_76 , V_88 ) ;
if ( V_92 )
return V_92 ;
}
V_78 = F_55 ( V_76 ) ;
if ( V_88 -> V_132 == 0 ) {
V_76 -> V_135 = V_289 ;
} else if ( V_76 -> V_135 == V_290 ) {
if ( ! F_79 ( V_78 -> V_49 , V_78 -> V_57 , V_76 -> V_122 ,
V_287 , V_76 -> V_129 ) )
V_76 -> V_135 = V_289 ;
}
if ( ! F_142 ( V_76 ) )
V_76 -> V_129 = F_190 ( V_78 -> V_49 , V_78 -> V_57 ,
V_76 -> V_122 , V_287 , 0 ) ;
return 0 ;
}
int F_191 ( struct V_75 * V_76 , struct V_22 * V_23 ,
int V_287 )
{
struct V_6 * V_7 ;
struct V_87 * V_88 ;
unsigned short V_160 ;
struct V_163 * V_164 = F_192 ( V_76 ) ;
T_3 V_49 , V_57 ;
struct V_1 * V_1 = F_57 ( V_76 -> V_79 ) ;
if ( ! F_193 ( V_76 , sizeof( struct V_87 ) ) )
goto V_274;
V_88 = F_74 ( V_76 ) ;
V_160 = F_49 ( V_88 -> V_122 ) ;
V_49 = F_55 ( V_76 ) -> V_49 ;
V_57 = F_55 ( V_76 ) -> V_57 ;
if ( V_160 > V_76 -> V_122 )
goto V_291;
if ( V_287 == V_133 ) {
if ( V_160 < sizeof( * V_88 ) || F_194 ( V_76 , V_160 ) )
goto V_291;
V_88 = F_74 ( V_76 ) ;
}
if ( F_188 ( V_76 , V_88 , V_287 ) )
goto V_292;
if ( V_164 -> V_215 & ( V_216 | V_293 ) )
return F_183 ( V_1 , V_76 , V_88 ,
V_49 , V_57 , V_23 ) ;
V_7 = F_54 ( V_76 , V_88 -> V_94 , V_88 -> V_93 , V_23 ) ;
if ( V_7 != NULL ) {
int V_230 = F_168 ( V_7 , V_76 ) ;
F_47 ( V_7 ) ;
if ( V_230 > 0 )
return - V_230 ;
return 0 ;
}
if ( ! F_169 ( NULL , V_273 , V_76 ) )
goto V_274;
F_170 ( V_76 ) ;
if ( F_126 ( V_76 ) )
goto V_292;
F_127 ( V_1 , V_294 , V_287 == V_288 ) ;
F_195 ( V_76 , V_103 , V_295 , 0 ) ;
F_163 ( V_76 ) ;
return 0 ;
V_291:
F_114 ( V_296 L_5 ,
V_287 == V_288 ? L_6 : L_7 ,
& V_49 , F_49 ( V_88 -> V_94 ) ,
V_160 , V_76 -> V_122 ,
& V_57 , F_49 ( V_88 -> V_93 ) ) ;
goto V_274;
V_292:
F_114 ( V_296 L_8 ,
V_287 == V_288 ? L_6 : L_7 ,
& V_49 , F_49 ( V_88 -> V_94 ) , & V_57 , F_49 ( V_88 -> V_93 ) ,
V_160 ) ;
V_274:
F_127 ( V_1 , V_235 , V_287 == V_288 ) ;
F_163 ( V_76 ) ;
return 0 ;
}
int F_196 ( struct V_75 * V_76 )
{
return F_191 ( V_76 , & V_22 , V_133 ) ;
}
void F_197 ( struct V_6 * V_7 )
{
struct V_119 * V_120 = F_7 ( V_7 ) ;
bool V_237 = F_131 ( V_7 ) ;
F_71 ( V_7 ) ;
F_134 ( V_7 , V_237 ) ;
if ( F_171 ( & V_272 ) && V_120 -> V_275 ) {
void (* F_198)( struct V_6 * V_7 );
F_198 = F_173 ( V_120 -> F_198 ) ;
if ( F_198 )
F_198 ( V_7 ) ;
}
}
int F_199 ( struct V_6 * V_7 , int V_297 , int V_298 ,
char V_242 * V_299 , unsigned int V_200 ,
int (* F_200)( struct V_6 * ) )
{
struct V_119 * V_120 = F_7 ( V_7 ) ;
int V_300 ;
int V_92 = 0 ;
int V_140 = F_83 ( V_7 ) ;
if ( V_200 < sizeof( int ) )
return - V_181 ;
if ( F_201 ( V_300 , ( int V_242 * ) V_299 ) )
return - V_301 ;
switch ( V_298 ) {
case V_302 :
if ( V_300 != 0 ) {
V_120 -> V_169 = 1 ;
} else {
V_120 -> V_169 = 0 ;
F_92 ( V_7 ) ;
(* F_200)( V_7 ) ;
F_94 ( V_7 ) ;
}
break;
case V_303 :
switch ( V_300 ) {
case 0 :
case V_304 :
case V_305 :
V_120 -> F_172 = V_306 ;
case V_307 :
V_120 -> V_275 = V_300 ;
F_165 () ;
break;
default:
V_92 = - V_308 ;
break;
}
break;
case V_309 :
if ( ! V_140 )
return - V_308 ;
if ( V_300 != 0 && V_300 < 8 )
V_300 = 8 ;
else if ( V_300 > V_310 )
V_300 = V_310 ;
V_120 -> V_311 = V_300 ;
V_120 -> V_312 |= V_313 ;
break;
case V_314 :
if ( ! V_140 )
return - V_308 ;
if ( V_300 != 0 && V_300 < 8 )
V_300 = 8 ;
else if ( V_300 > V_310 )
V_300 = V_310 ;
V_120 -> V_277 = V_300 ;
V_120 -> V_312 |= V_276 ;
break;
default:
V_92 = - V_308 ;
break;
}
return V_92 ;
}
int F_202 ( struct V_6 * V_7 , int V_297 , int V_298 ,
char V_242 * V_299 , unsigned int V_200 )
{
if ( V_297 == V_315 || V_297 == V_316 )
return F_199 ( V_7 , V_297 , V_298 , V_299 , V_200 ,
F_88 ) ;
return F_203 ( V_7 , V_297 , V_298 , V_299 , V_200 ) ;
}
int F_204 ( struct V_6 * V_7 , int V_297 , int V_298 ,
char V_242 * V_299 , unsigned int V_200 )
{
if ( V_297 == V_315 || V_297 == V_316 )
return F_199 ( V_7 , V_297 , V_298 , V_299 , V_200 ,
F_88 ) ;
return F_205 ( V_7 , V_297 , V_298 , V_299 , V_200 ) ;
}
int F_206 ( struct V_6 * V_7 , int V_297 , int V_298 ,
char V_242 * V_299 , int V_242 * V_200 )
{
struct V_119 * V_120 = F_7 ( V_7 ) ;
int V_300 , V_122 ;
if ( F_201 ( V_122 , V_200 ) )
return - V_301 ;
V_122 = F_207 (unsigned int, len, sizeof(int)) ;
if ( V_122 < 0 )
return - V_181 ;
switch ( V_298 ) {
case V_302 :
V_300 = V_120 -> V_169 ;
break;
case V_303 :
V_300 = V_120 -> V_275 ;
break;
case V_309 :
V_300 = V_120 -> V_311 ;
break;
case V_314 :
V_300 = V_120 -> V_277 ;
break;
default:
return - V_308 ;
}
if ( F_137 ( V_122 , V_200 ) )
return - V_301 ;
if ( F_208 ( V_299 , & V_300 , V_122 ) )
return - V_301 ;
return 0 ;
}
int F_209 ( struct V_6 * V_7 , int V_297 , int V_298 ,
char V_242 * V_299 , int V_242 * V_200 )
{
if ( V_297 == V_315 || V_297 == V_316 )
return F_206 ( V_7 , V_297 , V_298 , V_299 , V_200 ) ;
return F_210 ( V_7 , V_297 , V_298 , V_299 , V_200 ) ;
}
int F_211 ( struct V_6 * V_7 , int V_297 , int V_298 ,
char V_242 * V_299 , int V_242 * V_200 )
{
if ( V_297 == V_315 || V_297 == V_316 )
return F_206 ( V_7 , V_297 , V_298 , V_299 , V_200 ) ;
return F_212 ( V_7 , V_297 , V_298 , V_299 , V_200 ) ;
}
unsigned int F_213 ( struct V_317 * V_317 , struct V_318 * V_6 , T_8 * V_319 )
{
unsigned int V_33 = F_214 ( V_317 , V_6 , V_319 ) ;
struct V_6 * V_7 = V_6 -> V_7 ;
if ( ( V_33 & V_320 ) && ! ( V_317 -> V_321 & V_322 ) &&
! ( V_7 -> V_323 & V_324 ) && ! F_123 ( V_7 ) )
V_33 &= ~ ( V_325 | V_320 ) ;
return V_33 ;
}
static struct V_6 * F_215 ( struct V_326 * V_327 , int V_328 )
{
struct V_6 * V_7 ;
struct V_329 * V_330 = V_327 -> V_331 ;
struct V_1 * V_1 = F_216 ( V_327 ) ;
for ( V_330 -> V_332 = V_328 ; V_330 -> V_332 <= V_330 -> V_22 -> V_33 ;
++ V_330 -> V_332 ) {
struct V_10 * V_11 ;
struct V_3 * V_4 = & V_330 -> V_22 -> V_70 [ V_330 -> V_332 ] ;
if ( F_217 ( & V_4 -> V_43 ) )
continue;
F_20 ( & V_4 -> V_19 ) ;
F_4 (sk, node, &hslot->head) {
if ( ! F_5 ( F_6 ( V_7 ) , V_1 ) )
continue;
if ( V_7 -> V_62 == V_330 -> V_333 )
goto V_34;
}
F_23 ( & V_4 -> V_19 ) ;
}
V_7 = NULL ;
V_34:
return V_7 ;
}
static struct V_6 * F_218 ( struct V_326 * V_327 , struct V_6 * V_7 )
{
struct V_329 * V_330 = V_327 -> V_331 ;
struct V_1 * V_1 = F_216 ( V_327 ) ;
do {
V_7 = F_185 ( V_7 ) ;
} while ( V_7 && ( ! F_5 ( F_6 ( V_7 ) , V_1 ) || V_7 -> V_62 != V_330 -> V_333 ) );
if ( ! V_7 ) {
if ( V_330 -> V_332 <= V_330 -> V_22 -> V_33 )
F_23 ( & V_330 -> V_22 -> V_70 [ V_330 -> V_332 ] . V_19 ) ;
return F_215 ( V_327 , V_330 -> V_332 + 1 ) ;
}
return V_7 ;
}
static struct V_6 * F_219 ( struct V_326 * V_327 , T_9 V_334 )
{
struct V_6 * V_7 = F_215 ( V_327 , 0 ) ;
if ( V_7 )
while ( V_334 && ( V_7 = F_218 ( V_327 , V_7 ) ) != NULL )
-- V_334 ;
return V_334 ? NULL : V_7 ;
}
static void * F_220 ( struct V_326 * V_327 , T_9 * V_334 )
{
struct V_329 * V_330 = V_327 -> V_331 ;
V_330 -> V_332 = V_335 ;
return * V_334 ? F_219 ( V_327 , * V_334 - 1 ) : V_336 ;
}
static void * F_221 ( struct V_326 * V_327 , void * V_337 , T_9 * V_334 )
{
struct V_6 * V_7 ;
if ( V_337 == V_336 )
V_7 = F_219 ( V_327 , 0 ) ;
else
V_7 = F_218 ( V_327 , V_337 ) ;
++ * V_334 ;
return V_7 ;
}
static void F_222 ( struct V_326 * V_327 , void * V_337 )
{
struct V_329 * V_330 = V_327 -> V_331 ;
if ( V_330 -> V_332 <= V_330 -> V_22 -> V_33 )
F_23 ( & V_330 -> V_22 -> V_70 [ V_330 -> V_332 ] . V_19 ) ;
}
int F_223 ( struct V_338 * V_338 , struct V_317 * V_317 )
{
struct V_339 * V_340 = F_224 ( V_338 ) -> V_86 ;
struct V_329 * V_84 ;
int V_92 ;
V_92 = F_225 ( V_338 , V_317 , & V_340 -> V_341 ,
sizeof( struct V_329 ) ) ;
if ( V_92 < 0 )
return V_92 ;
V_84 = ( (struct V_326 * ) V_317 -> V_342 ) -> V_331 ;
V_84 -> V_333 = V_340 -> V_333 ;
V_84 -> V_22 = V_340 -> V_22 ;
return V_92 ;
}
int F_226 ( struct V_1 * V_1 , struct V_339 * V_340 )
{
struct V_343 * V_344 ;
int V_269 = 0 ;
V_340 -> V_341 . V_328 = F_220 ;
V_340 -> V_341 . V_134 = F_221 ;
V_340 -> V_341 . V_345 = F_222 ;
V_344 = F_227 ( V_340 -> V_346 , V_347 , V_1 -> V_348 ,
V_340 -> V_349 , V_340 ) ;
if ( ! V_344 )
V_269 = - V_270 ;
return V_269 ;
}
void F_228 ( struct V_1 * V_1 , struct V_339 * V_340 )
{
F_229 ( V_340 -> V_346 , V_1 -> V_348 ) ;
}
static void F_230 ( struct V_6 * V_350 , struct V_326 * V_351 ,
int V_332 , int * V_122 )
{
struct V_45 * V_61 = F_25 ( V_350 ) ;
T_3 V_93 = V_61 -> V_64 ;
T_3 V_123 = V_61 -> V_48 ;
T_1 V_352 = F_49 ( V_61 -> V_65 ) ;
T_1 V_353 = F_49 ( V_61 -> V_141 ) ;
F_231 ( V_351 , L_9
L_10 ,
V_332 , V_123 , V_353 , V_93 , V_352 , V_350 -> V_114 ,
F_136 ( V_350 ) ,
F_232 ( V_350 ) ,
0 , 0L , 0 ,
F_233 ( F_234 ( V_351 ) , F_3 ( V_350 ) ) ,
0 , F_235 ( V_350 ) ,
F_236 ( & V_350 -> V_72 ) , V_350 ,
F_236 ( & V_350 -> V_236 ) , V_122 ) ;
}
int F_237 ( struct V_326 * V_327 , void * V_337 )
{
if ( V_337 == V_336 )
F_231 ( V_327 , L_11 ,
L_12
L_13
L_14 ) ;
else {
struct V_329 * V_330 = V_327 -> V_331 ;
int V_122 ;
F_230 ( V_337 , V_327 , V_330 -> V_332 , & V_122 ) ;
F_231 ( V_327 , L_15 , 127 - V_122 , L_7 ) ;
}
return 0 ;
}
static int T_10 F_238 ( struct V_1 * V_1 )
{
return F_226 ( V_1 , & V_354 ) ;
}
static void T_11 F_239 ( struct V_1 * V_1 )
{
F_228 ( V_1 , & V_354 ) ;
}
int T_12 F_240 ( void )
{
return F_241 ( & V_355 ) ;
}
void F_242 ( void )
{
F_243 ( & V_355 ) ;
}
static int T_12 F_244 ( char * V_356 )
{
T_13 V_230 ;
if ( ! V_356 )
return 0 ;
V_230 = F_245 ( V_356 , 0 , & V_357 ) ;
if ( V_230 )
return 0 ;
if ( V_357 && V_357 < V_358 )
V_357 = V_358 ;
return 1 ;
}
void T_12 F_246 ( struct V_22 * V_359 , const char * V_346 )
{
unsigned int V_284 ;
V_359 -> V_70 = F_247 ( V_346 ,
2 * sizeof( struct V_3 ) ,
V_357 ,
21 ,
0 ,
& V_359 -> log ,
& V_359 -> V_33 ,
V_358 ,
64 * 1024 ) ;
V_359 -> V_73 = V_359 -> V_70 + ( V_359 -> V_33 + 1 ) ;
for ( V_284 = 0 ; V_284 <= V_359 -> V_33 ; V_284 ++ ) {
F_248 ( & V_359 -> V_70 [ V_284 ] . V_43 , V_284 ) ;
V_359 -> V_70 [ V_284 ] . V_36 = 0 ;
F_249 ( & V_359 -> V_70 [ V_284 ] . V_19 ) ;
}
for ( V_284 = 0 ; V_284 <= V_359 -> V_33 ; V_284 ++ ) {
F_248 ( & V_359 -> V_73 [ V_284 ] . V_43 , V_284 ) ;
V_359 -> V_73 [ V_284 ] . V_36 = 0 ;
F_249 ( & V_359 -> V_73 [ V_284 ] . V_19 ) ;
}
}
void T_12 F_250 ( void )
{
unsigned long V_360 ;
F_246 ( & V_22 , L_16 ) ;
V_360 = F_251 () / 8 ;
V_360 = F_252 ( V_360 , 128UL ) ;
V_361 [ 0 ] = V_360 / 4 * 3 ;
V_361 [ 1 ] = V_360 ;
V_361 [ 2 ] = V_361 [ 0 ] * 2 ;
V_362 = V_363 ;
V_364 = V_363 ;
}
int F_253 ( struct V_75 * V_76 )
{
const struct V_77 * V_78 ;
struct V_87 * V_88 ;
if ( ! F_193 ( V_76 , sizeof( * V_88 ) ) )
return - V_181 ;
V_78 = F_55 ( V_76 ) ;
V_88 = F_74 ( V_76 ) ;
V_88 -> V_132 = ~ F_79 ( V_78 -> V_49 , V_78 -> V_57 , V_76 -> V_122 ,
V_133 , 0 ) ;
V_76 -> V_130 = F_77 ( V_76 ) - V_76 -> V_43 ;
V_76 -> V_131 = F_78 ( struct V_87 , V_132 ) ;
V_76 -> V_135 = V_146 ;
return 0 ;
}
struct V_75 * F_254 ( struct V_75 * V_76 ,
T_14 V_365 )
{
struct V_75 * V_366 = F_255 ( - V_181 ) ;
unsigned int V_367 ;
int V_127 ;
T_5 V_129 ;
V_367 = F_75 ( V_76 ) -> V_368 ;
if ( F_45 ( V_76 -> V_122 <= V_367 ) )
goto V_100;
if ( F_256 ( V_76 , V_365 | V_369 ) ) {
int type = F_75 ( V_76 ) -> V_370 ;
if ( F_45 ( type & ~ ( V_371 | V_372 |
V_373 ) ||
! ( type & ( V_371 ) ) ) )
goto V_100;
F_75 ( V_76 ) -> V_374 = F_257 ( V_76 -> V_122 , V_367 ) ;
V_366 = NULL ;
goto V_100;
}
V_127 = F_258 ( V_76 ) ;
V_129 = F_81 ( V_76 , V_127 , V_76 -> V_122 - V_127 , 0 ) ;
V_127 += V_76 -> V_131 ;
* ( V_375 * ) ( V_76 -> V_86 + V_127 ) = F_259 ( V_129 ) ;
V_76 -> V_135 = V_136 ;
V_366 = F_260 ( V_76 , V_365 ) ;
V_100:
return V_366 ;
}
