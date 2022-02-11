static void F_1 ( struct V_1 * V_1 , int V_2 )
{
struct V_3 * V_4 = F_2 ( V_1 ) ;
if ( V_2 ) {
if ( V_1 -> V_5 & V_6 )
return;
V_1 -> V_5 = V_6 ;
V_1 -> V_7 = V_8 ;
} else {
V_1 -> V_5 = 0 ;
V_1 -> V_7 = 0 ;
V_4 -> V_9 = V_10 ;
}
V_1 -> V_11 = 0 ;
F_3 ( V_1 , V_12 , 0 ) ;
F_3 ( V_1 , V_13 , ~ 0 ) ;
if ( V_1 -> V_14 && V_1 -> V_14 -> F_1 ) {
F_4 ( L_1 , V_2 ? L_2 : L_3 ) ;
V_1 -> V_14 -> F_1 ( V_4 -> V_15 . V_16 , V_2 ) ;
}
if ( V_1 -> V_14 && V_1 -> V_14 -> V_17 )
V_1 -> V_14 -> V_17 ( V_4 -> V_15 . V_16 ) ;
else {
F_3 ( V_1 , V_18 , V_19 ) ;
F_5 ( 20 ) ;
}
F_3 ( V_1 , V_12 , 0 ) ;
F_3 ( V_1 , V_18 , V_1 -> V_11 ) ;
F_3 ( V_1 , V_20 , V_21 ) ;
F_3 ( V_1 , V_12 , V_1 -> V_7 ) ;
}
static void F_6 (
struct V_1 * V_1 ,
struct V_22 * V_23 ,
struct V_24 * V_24 ,
T_1 V_25 ,
T_1 V_26
)
{
T_1 V_27 ;
T_1 V_28 ;
void T_2 * V_29 ;
V_27 = F_7 ( V_25 == 0 ) ;
V_28 = sizeof( struct V_30 ) ;
V_29 = V_1 -> V_29 ;
F_8 ( V_1 , V_27 , V_24 -> F_6 , V_28 ) ;
F_3 ( V_1 , V_25 + V_31 , V_27 ) ;
F_9 ( V_28 , V_29 ) ;
F_9 ( V_32 , V_29 ) ;
F_9 ( F_10 ( V_24 -> V_33 ) , V_29 ) ;
F_3 ( V_1 , V_25 + V_34 ,
V_26 | V_35 ) ;
V_23 -> V_36 = 0 ;
F_11 ( L_4 , V_23 ) ;
}
static void F_12 (
struct V_1 * V_1 ,
struct V_22 * V_23 ,
struct V_24 * V_24 ,
T_1 V_25 ,
T_1 V_26
)
{
int V_37 ;
void T_2 * V_29 ;
V_37 = V_24 -> V_38 && F_13 ( V_24 -> V_33 ) ;
V_29 = V_1 -> V_29 ;
F_3 ( V_1 , V_25 + V_31 , 0 ) ;
F_9 ( 0 , V_29 ) ;
F_9 ( ( V_37 ? V_39 : V_40 ) , V_29 ) ;
F_9 ( F_10 ( V_24 -> V_33 ) , V_29 ) ;
V_26 |= V_41 ;
if ( V_37 )
V_26 |= V_35 ;
F_3 ( V_1 , V_25 + V_34 , V_26 ) ;
V_23 -> V_36 = 0 ;
F_11 ( L_5 , V_23 -> V_42 ? L_6 : L_7 ,
V_37 ? L_8 : L_9 , V_23 ) ;
}
static void F_14 (
struct V_1 * V_1 ,
struct V_22 * V_23 ,
struct V_24 * V_24 ,
T_1 V_25 ,
T_1 V_26
)
{
T_1 V_27 ;
T_1 V_28 ;
void T_2 * V_29 ;
V_28 = V_23 -> V_43 ;
V_27 = F_7 ( V_25 == 0 ) ;
if ( ! ( V_26 & V_44 )
&& F_15 ( V_24 -> V_45 , V_23 -> V_46 , 0 ) )
V_26 |= V_41 ;
V_29 = V_1 -> V_29 ;
F_3 ( V_1 , V_25 + V_31 , V_27 ) ;
F_9 ( V_28 , V_29 ) ;
F_9 ( V_40 | V_23 -> V_46 , V_29 ) ;
F_9 ( F_10 ( V_24 -> V_33 ) , V_29 ) ;
F_3 ( V_1 , V_25 + V_34 , V_26 ) ;
V_23 -> V_36 = F_16 ( V_47 , V_28 ,
V_24 -> V_38 - V_24 -> V_48 ) ;
F_11 ( L_10 , V_23 -> V_42 ? L_6 : L_7 ,
! ! F_15 ( V_24 -> V_45 , V_23 -> V_46 , 0 ) , V_23 , V_28 ) ;
}
static void F_17 (
struct V_1 * V_1 ,
struct V_22 * V_23 ,
struct V_24 * V_24 ,
T_1 V_25 ,
T_1 V_26
)
{
void * V_49 ;
T_1 V_27 ;
T_1 V_28 ;
void T_2 * V_29 ;
V_49 = V_24 -> V_50 + V_24 -> V_48 ;
F_18 ( V_49 ) ;
V_28 = F_16 ( V_47 , V_23 -> V_43 ,
V_24 -> V_38 - V_24 -> V_48 ) ;
if ( ! ( V_26 & V_44 )
&& F_15 ( V_24 -> V_45 , V_23 -> V_46 , 1 ) )
V_26 |= V_41 ;
V_27 = F_7 ( V_25 == 0 ) ;
V_29 = V_1 -> V_29 ;
F_8 ( V_1 , V_27 , V_49 , V_28 ) ;
F_3 ( V_1 , V_25 + V_31 , V_27 ) ;
F_9 ( V_28 , V_29 ) ;
F_9 ( V_39 | V_23 -> V_46 , V_29 ) ;
F_9 ( F_10 ( V_24 -> V_33 ) , V_29 ) ;
F_3 ( V_1 , V_25 + V_34 ,
V_26 | V_35 ) ;
V_23 -> V_36 = V_28 ;
F_11 ( L_11 , V_23 -> V_42 ? L_6 : L_7 ,
! ! F_15 ( V_24 -> V_45 , V_23 -> V_46 , 1 ) , V_23 , V_28 ) ;
}
static inline void F_19 ( struct V_1 * V_1 )
{
if ( V_1 -> V_7 & V_51 )
return;
F_20 ( L_12 ) ;
V_1 -> V_7 |= V_51 ;
}
static inline void F_21 ( struct V_1 * V_1 )
{
if ( ! ( V_1 -> V_7 & V_51 ) )
return;
F_20 ( L_13 ) ;
V_1 -> V_7 &= ~ V_51 ;
}
static struct V_22 * F_22 ( struct V_1 * V_1 , T_1 V_25 )
{
struct V_22 * V_23 ;
struct V_24 * V_24 ;
int V_52 ;
T_1 V_26 ;
if ( V_1 -> V_53 ) {
V_23 = V_1 -> V_53 ;
V_1 -> V_53 = V_23 -> V_54 ;
} else {
if ( V_1 -> V_55 )
V_23 = V_1 -> V_55 ;
else if ( ! F_23 ( & V_1 -> V_56 ) )
V_23 = F_24 ( V_1 -> V_56 . V_54 ,
struct V_22 , V_57 ) ;
else {
return NULL ;
}
#ifdef F_25
if ( ( V_25 && V_1 -> V_58 == V_23 ) || V_1 -> V_59 == V_23 )
return NULL ;
#endif
if ( V_23 -> V_57 . V_54 == & V_1 -> V_56 )
V_1 -> V_55 = NULL ;
else
V_1 -> V_55 = F_24 ( V_23 -> V_57 . V_54 ,
struct V_22 , V_57 ) ;
}
if ( F_26 ( F_23 ( & V_23 -> V_60 -> V_61 ) ) ) {
F_4 ( L_14 , V_23 ) ;
return NULL ;
}
V_24 = F_24 ( V_23 -> V_60 -> V_61 . V_54 , struct V_24 , V_61 ) ;
V_26 = V_23 -> V_62 ;
V_52 = F_27 ( V_1 , V_63 ) << 6 ;
V_52 -= 100 ;
if ( V_24 -> V_45 -> V_64 == V_65 ) {
if ( V_26 & V_66 ) {
V_52 -= 800 ;
}
V_52 -= V_23 -> V_43 << 8 ;
if ( V_52 < 0 ) {
if ( V_23 -> V_67 )
V_1 -> V_68 ++ ;
F_19 ( V_1 ) ;
return NULL ;
}
} else {
V_52 -= 12000 / 19 ;
if ( V_52 < 0 ) {
if ( V_23 -> V_67 )
V_1 -> V_68 ++ ;
V_26 |= V_69 ;
} else if ( V_23 -> V_42 )
V_26 |= V_69 ;
}
switch ( V_23 -> V_70 ) {
case V_71 :
F_14 ( V_1 , V_23 , V_24 , V_25 , V_26 ) ;
break;
case V_72 :
F_17 ( V_1 , V_23 , V_24 , V_25 , V_26 ) ;
break;
case V_73 :
F_6 ( V_1 , V_23 , V_24 , V_25 , V_26 ) ;
break;
case V_74 :
F_12 ( V_1 , V_23 , V_24 , V_25 , V_26 ) ;
break;
default:
F_4 ( L_15 , V_23 , V_23 -> V_70 ) ;
V_23 = NULL ;
}
return V_23 ;
}
static inline void F_28 ( struct V_1 * V_1 )
{
if ( V_1 -> V_5 & V_75 )
return;
if ( V_1 -> V_59 == NULL ) {
V_1 -> V_59 = F_22 ( V_1 , F_29 ( V_76 ) ) ;
if ( V_1 -> V_59 != NULL )
V_1 -> V_77 = V_78 + V_79 ;
}
#ifdef F_25
if ( V_1 -> V_58 == NULL ) {
V_1 -> V_58 = F_22 ( V_1 , F_30 ( V_76 ) ) ;
if ( V_1 -> V_58 != NULL )
V_1 -> V_80 = V_78 + V_79 ;
}
#endif
}
static void F_31 (
struct V_1 * V_1 ,
struct V_22 * V_23 ,
struct V_24 * V_24 ,
int V_81
) __releases( V_1 -> V_82 ) __acquires( V_1 -> V_82 )
{
unsigned V_83 ;
if ( F_32 ( V_24 -> V_33 ) )
V_23 -> V_70 = V_73 ;
F_33 ( F_2 ( V_1 ) , V_24 ) ;
F_34 ( & V_1 -> V_82 ) ;
F_35 ( F_2 ( V_1 ) , V_24 , V_81 ) ;
F_36 ( & V_1 -> V_82 ) ;
if ( ! F_23 ( & V_23 -> V_60 -> V_61 ) )
return;
if ( ! F_23 ( & V_23 -> V_57 ) ) {
F_37 ( & V_23 -> V_57 ) ;
if ( V_23 == V_1 -> V_55 )
V_1 -> V_55 = NULL ;
return;
}
F_4 ( L_16 , V_23 -> V_67 , V_23 , V_23 -> V_84 ) ;
for ( V_83 = V_23 -> V_84 ; V_83 < V_85 ; V_83 += V_23 -> V_67 ) {
struct V_22 * V_86 ;
struct V_22 * * V_87 = & V_1 -> V_88 [ V_83 ] ;
while ( * V_87 && ( ( V_86 = * V_87 ) != V_23 ) )
V_87 = & V_86 -> V_54 ;
if ( * V_87 )
* V_87 = V_23 -> V_54 ;
V_1 -> V_89 [ V_83 ] -= V_23 -> V_89 ;
}
V_23 -> V_84 = V_85 ;
V_1 -> V_90 -- ;
F_2 ( V_1 ) -> V_15 . V_91
-= V_23 -> V_89 / V_23 -> V_67 ;
if ( V_23 == V_1 -> V_53 )
V_1 -> V_53 = V_23 -> V_54 ;
if ( V_1 -> V_90 == 0 )
F_21 ( V_1 ) ;
}
static void
F_38 ( struct V_1 * V_1 , struct V_22 * V_23 , T_1 V_25 )
{
T_1 V_81 ;
struct V_24 * V_24 ;
int V_92 = - V_93 ;
if ( F_26 ( ! V_23 ) )
return;
V_81 = F_27 ( V_1 , V_25 + V_94 ) ;
V_24 = F_24 ( V_23 -> V_60 -> V_61 . V_54 , struct V_24 , V_61 ) ;
if ( V_81 & V_95 ) {
if ( ! V_23 -> V_67 )
V_23 -> V_42 ++ ;
V_23 -> V_96 = 0 ;
} else if ( V_81 & V_97 ) {
struct V_98 * V_99 = V_24 -> V_45 ;
int V_28 ;
unsigned char * V_49 ;
V_23 -> V_42 = V_23 -> V_96 = 0 ;
switch ( V_23 -> V_70 ) {
case V_72 :
V_24 -> V_48 += V_23 -> V_36 ;
F_39 ( V_99 , V_23 -> V_46 , 1 ) ;
if ( V_24 -> V_48
== V_24 -> V_38 ) {
if ( F_32 ( V_24 -> V_33 ) )
V_23 -> V_70 = V_74 ;
else if ( V_23 -> V_36 < V_23 -> V_43
|| ! ( V_24 -> V_100
& V_101 ) )
V_92 = 0 ;
}
break;
case V_71 :
V_49 = V_24 -> V_50 + V_24 -> V_48 ;
F_40 ( V_49 ) ;
V_28 = V_23 -> V_43 - F_27 ( V_1 ,
V_25 + V_102 ) ;
if ( V_28 > V_23 -> V_36 ) {
V_28 = V_23 -> V_36 ;
V_92 = - V_103 ;
}
V_24 -> V_48 += V_28 ;
F_41 ( V_1 , F_7 ( V_25 == 0 ) ,
V_49 , V_28 ) ;
F_39 ( V_99 , V_23 -> V_46 , 0 ) ;
if ( V_92 == - V_93 &&
( V_28 < V_23 -> V_43 ||
V_24 -> V_48 ==
V_24 -> V_38 ) ) {
if ( F_32 ( V_24 -> V_33 ) )
V_23 -> V_70 = V_74 ;
else
V_92 = 0 ;
}
break;
case V_73 :
if ( V_24 -> V_38 == V_24 -> V_48 )
V_23 -> V_70 = V_74 ;
else if ( F_42 ( V_24 -> V_33 ) ) {
F_43 ( V_99 , 0 , 1 , 1 ) ;
V_23 -> V_70 = V_72 ;
} else {
F_43 ( V_99 , 0 , 0 , 1 ) ;
V_23 -> V_70 = V_71 ;
}
break;
case V_74 :
V_92 = 0 ;
break;
}
} else if ( V_81 & V_104 ) {
F_11 ( L_17 , V_25 , V_23 ) ;
V_23 -> V_42 = V_23 -> V_96 = 0 ;
V_92 = - V_105 ;
} else if ( ++ V_23 -> V_96 >= 3 ) {
if ( V_81 & V_106 )
V_92 = - V_107 ;
else if ( V_81 & V_108 )
V_92 = - V_103 ;
else
V_92 = - V_109 ;
V_23 -> V_96 = 0 ;
F_11 ( L_18 ,
V_25 , V_81 , V_23 , V_92 ) ;
}
if ( V_92 != - V_93 || V_24 -> V_110 )
F_31 ( V_1 , V_23 , V_24 , V_92 ) ;
}
static inline T_1 F_44 ( struct V_1 * V_1 )
{
T_1 V_111 ;
T_1 V_112 = 0 ;
if ( V_1 -> V_59 && F_45 ( V_1 -> V_77 , V_78 ) ) {
V_111 = F_27 ( V_1 , F_29 ( V_34 ) ) ;
if ( V_111 & V_113 )
F_3 ( V_1 , F_29 ( V_34 ) , 0 ) ;
F_4 ( L_19 ,
( V_111 & V_113 ) ? L_20 : L_21 ,
V_111 ,
F_27 ( V_1 , F_29 ( V_94 ) ) ) ;
V_112 |= V_114 ;
}
#ifdef F_25
if ( V_1 -> V_58 && F_45 ( V_1 -> V_80 , V_78 ) ) {
V_111 = F_27 ( V_1 , F_30 ( V_34 ) ) ;
if ( V_111 & V_113 )
F_3 ( V_1 , F_30 ( V_34 ) , 0 ) ;
F_4 ( L_22 ,
( V_111 & V_113 ) ? L_20 : L_21 ,
V_111 ,
F_27 ( V_1 , F_30 ( V_94 ) ) ) ;
V_112 |= V_114 ;
}
#endif
return V_112 ;
}
static T_3 F_46 ( struct V_3 * V_4 )
{
struct V_1 * V_1 = F_47 ( V_4 ) ;
T_1 V_112 ;
T_3 V_115 = V_116 ;
unsigned V_117 = 5 ;
F_36 ( & V_1 -> V_82 ) ;
V_118:
V_112 = F_27 ( V_1 , V_13 ) & ~ V_119 ;
if ( V_112 ) {
F_3 ( V_1 , V_13 , V_112 ) ;
V_112 &= V_1 -> V_7 ;
}
#ifdef F_48
if ( V_112 == 0 ) {
V_112 = F_44 ( V_1 ) ;
if ( V_112 )
V_1 -> V_120 ++ ;
}
#endif
if ( V_112 & V_114 ) {
F_38 ( V_1 , V_1 -> V_59 , F_29 ( V_76 ) ) ;
V_1 -> V_59 = NULL ;
V_1 -> V_121 ++ ;
}
#ifdef F_25
if ( V_112 & V_122 ) {
F_38 ( V_1 , V_1 -> V_58 , F_30 ( V_76 ) ) ;
V_1 -> V_58 = NULL ;
V_1 -> V_123 ++ ;
}
#endif
if ( V_112 & V_51 ) {
unsigned V_124 ;
V_124 = V_1 -> V_125 ++ % ( V_85 - 1 ) ;
V_1 -> V_126 ++ ;
if ( V_1 -> V_53 ) {
V_1 -> V_68 ++ ;
}
if ( V_1 -> V_88 [ V_124 ] )
V_1 -> V_53 = V_1 -> V_88 [ V_124 ] ;
}
if ( V_112 & V_8 ) {
V_1 -> V_127 ++ ;
V_1 -> V_128 = 0 ;
V_1 -> V_126 = 0 ;
V_1 -> V_121 = 0 ;
V_1 -> V_123 = 0 ;
V_1 -> V_120 = 0 ;
V_1 -> V_11 = 0 ;
F_3 ( V_1 , V_18 , V_1 -> V_11 ) ;
V_1 -> V_7 = V_8 ;
F_3 ( V_1 , V_12 , V_1 -> V_7 ) ;
if ( V_1 -> V_59 ) {
F_3 ( V_1 , F_29 ( V_34 ) , 0 ) ;
F_31 ( V_1 , V_1 -> V_59 ,
F_24 ( V_1 -> V_59
-> V_60 -> V_61 . V_54 ,
struct V_24 , V_61 ) ,
- V_129 ) ;
V_1 -> V_59 = NULL ;
}
#ifdef F_25
if ( V_1 -> V_58 ) {
F_3 ( V_1 , F_30 ( V_34 ) , 0 ) ;
F_31 ( V_1 , V_1 -> V_58 ,
F_24 ( V_1 -> V_58
-> V_60 -> V_61 . V_54 ,
struct V_24 , V_61 ) ,
NULL , - V_129 ) ;
V_1 -> V_58 = NULL ;
}
#endif
if ( V_112 & V_130 )
V_1 -> V_5 &= ~ V_131 ;
else
V_1 -> V_5 |= V_131 ;
V_1 -> V_5 |= V_132 << 16 ;
} else if ( V_112 & V_130 ) {
if ( V_1 -> V_5 & V_75 ) {
F_4 ( L_23 ) ;
V_1 -> V_5 |= V_133 << 16 ;
V_1 -> V_128 ++ ;
} else
V_112 &= ~ V_130 ;
}
if ( V_112 ) {
if ( V_1 -> V_5 & V_134 )
F_28 ( V_1 ) ;
V_115 = V_135 ;
if ( V_117 -- )
goto V_118;
}
if ( V_1 -> V_90 == 0 && F_23 ( & V_1 -> V_56 ) )
F_21 ( V_1 ) ;
F_3 ( V_1 , V_12 , V_1 -> V_7 ) ;
F_34 ( & V_1 -> V_82 ) ;
return V_115 ;
}
static int F_49 ( struct V_1 * V_1 , T_4 V_67 , T_4 V_89 )
{
int V_83 , V_84 = - V_136 ;
for ( V_83 = 0 ; V_83 < V_67 ; V_83 ++ ) {
if ( V_84 < 0 || V_1 -> V_89 [ V_84 ] > V_1 -> V_89 [ V_83 ] ) {
int V_137 ;
for ( V_137 = V_83 ; V_137 < V_85 ; V_137 += V_67 ) {
if ( ( V_1 -> V_89 [ V_137 ] + V_89 )
> V_138 )
break;
}
if ( V_137 < V_85 )
continue;
V_84 = V_83 ;
}
}
return V_84 ;
}
static int F_50 (
struct V_3 * V_4 ,
struct V_24 * V_24 ,
T_5 V_139
) {
struct V_1 * V_1 = F_47 ( V_4 ) ;
struct V_98 * V_99 = V_24 -> V_45 ;
unsigned int V_33 = V_24 -> V_33 ;
int V_140 = ! F_13 ( V_33 ) ;
int type = F_51 ( V_33 ) ;
int V_46 = F_52 ( V_33 ) ;
struct V_22 * V_23 = NULL ;
unsigned long V_141 ;
int V_83 ;
int V_142 ;
struct V_143 * V_60 = V_24 -> V_23 ;
#ifndef F_53
if ( type == V_144 )
return - V_136 ;
#endif
if ( ! V_60 -> V_145 ) {
V_23 = F_54 ( sizeof *V_23 , V_139 ) ;
if ( V_23 == NULL )
return - V_146 ;
}
F_55 ( & V_1 -> V_82 , V_141 ) ;
if ( ! ( V_1 -> V_5 & V_134 )
|| ! F_56 ( V_4 -> V_9 ) ) {
V_142 = - V_147 ;
F_57 ( V_23 ) ;
goto V_148;
}
V_142 = F_58 ( V_4 , V_24 ) ;
if ( V_142 ) {
F_57 ( V_23 ) ;
goto V_148;
}
if ( V_60 -> V_145 ) {
F_57 ( V_23 ) ;
V_23 = V_60 -> V_145 ;
} else if ( ! V_23 ) {
V_142 = - V_146 ;
goto V_149;
} else {
F_59 ( & V_23 -> V_57 ) ;
V_23 -> V_99 = V_99 ;
V_23 -> V_46 = V_46 ;
V_23 -> V_43 = F_60 ( V_99 , V_24 -> V_33 , V_140 ) ;
V_23 -> V_62 = V_113 | V_150 ;
F_43 ( V_99 , V_46 , V_140 , 0 ) ;
if ( type == V_151 )
V_23 -> V_70 = V_73 ;
else if ( V_140 )
V_23 -> V_70 = V_72 ;
else
V_23 -> V_70 = V_71 ;
if ( V_23 -> V_43 > V_152 ) {
F_4 ( L_24 ,
V_99 -> V_153 , V_46 , V_23 -> V_43 ) ;
V_142 = - V_154 ;
F_57 ( V_23 ) ;
goto V_149;
}
if ( V_99 -> V_64 == V_65 ) {
if ( ! ( V_1 -> V_11 & V_155 ) )
V_23 -> V_62 |= V_66 ;
}
switch ( type ) {
case V_144 :
case V_156 :
if ( V_24 -> V_157 > V_85 )
V_24 -> V_157 = V_85 ;
V_23 -> V_67 = V_24 -> V_157 ;
V_23 -> V_84 = V_85 ;
if ( type == V_144 )
V_23 -> V_62 |= V_44 ;
V_23 -> V_89 = F_61 ( V_99 -> V_64 , ! V_140 ,
( type == V_144 ) ,
F_60 ( V_99 , V_33 , V_140 ) )
/ 1000 ;
break;
}
V_23 -> V_60 = V_60 ;
V_60 -> V_145 = V_23 ;
}
switch ( type ) {
case V_151 :
case V_158 :
if ( F_23 ( & V_23 -> V_57 ) )
F_62 ( & V_23 -> V_57 , & V_1 -> V_56 ) ;
break;
case V_144 :
case V_156 :
V_24 -> V_157 = V_23 -> V_67 ;
if ( V_23 -> V_84 < V_85 ) {
V_24 -> V_159 = ( V_1 -> V_125 & ( V_85 - 1 ) )
+ V_23 -> V_84 ;
break;
}
V_142 = F_49 ( V_1 , V_23 -> V_67 , V_23 -> V_89 ) ;
if ( V_142 < 0 )
goto V_149;
V_23 -> V_84 = V_142 ;
V_142 = 0 ;
V_24 -> V_159 = ( V_1 -> V_125 & ( V_85 - 1 ) )
+ V_23 -> V_84 ;
F_4 ( L_25 , V_23 -> V_67 , V_23 , V_23 -> V_84 ) ;
for ( V_83 = V_23 -> V_84 ; V_83 < V_85 ; V_83 += V_23 -> V_67 ) {
struct V_22 * * V_87 = & V_1 -> V_88 [ V_83 ] ;
struct V_22 * V_160 = * V_87 ;
while ( V_160 && V_23 != V_160 ) {
if ( V_23 -> V_67 > V_160 -> V_67 )
break;
V_87 = & V_160 -> V_54 ;
V_160 = * V_87 ;
}
if ( V_23 != V_160 ) {
V_23 -> V_54 = V_160 ;
* V_87 = V_23 ;
}
V_1 -> V_89 [ V_83 ] += V_23 -> V_89 ;
}
V_1 -> V_90 ++ ;
V_4 -> V_15 . V_91 += V_23 -> V_89 / V_23 -> V_67 ;
F_19 ( V_1 ) ;
}
V_24 -> V_145 = V_60 ;
F_28 ( V_1 ) ;
F_3 ( V_1 , V_12 , V_1 -> V_7 ) ;
V_149:
if ( V_142 )
F_33 ( V_4 , V_24 ) ;
V_148:
F_63 ( & V_1 -> V_82 , V_141 ) ;
return V_142 ;
}
static int F_64 ( struct V_3 * V_4 , struct V_24 * V_24 , int V_81 )
{
struct V_1 * V_1 = F_47 ( V_4 ) ;
struct V_143 * V_60 ;
unsigned long V_141 ;
struct V_22 * V_23 ;
int V_142 ;
F_55 ( & V_1 -> V_82 , V_141 ) ;
V_142 = F_65 ( V_4 , V_24 , V_81 ) ;
if ( V_142 )
goto V_149;
V_60 = V_24 -> V_145 ;
V_23 = V_60 -> V_145 ;
if ( V_23 ) {
if ( V_23 -> V_60 -> V_61 . V_54 != & V_24 -> V_61 ) {
} else if ( V_1 -> V_59 == V_23 ) {
if ( F_45 ( V_1 -> V_77 , V_78 ) ) {
F_4 ( L_26 ,
F_27 ( V_1 ,
F_29 ( V_34 ) ) ,
F_27 ( V_1 ,
F_29 ( V_94 ) ) ) ;
F_3 ( V_1 , F_29 ( V_34 ) ,
0 ) ;
V_1 -> V_59 = NULL ;
} else
V_24 = NULL ;
#ifdef F_25
} else if ( V_1 -> V_58 == V_23 ) {
if ( F_45 ( V_1 -> V_77 , V_78 ) ) {
F_4 ( L_27 ,
F_27 ( V_1 ,
F_30 ( V_34 ) ) ,
F_27 ( V_1 ,
F_30 ( V_94 ) ) ) ;
F_3 ( V_1 , F_30 ( V_34 ) ,
0 ) ;
V_1 -> V_58 = NULL ;
} else
V_24 = NULL ;
#endif
} else {
}
if ( V_24 )
F_31 ( V_1 , V_23 , V_24 , 0 ) ;
else
F_20 ( L_28 , V_24 ,
( V_1 -> V_59 == V_23 ) ? L_29 : L_30 ) ;
} else
V_142 = - V_154 ;
V_149:
F_63 ( & V_1 -> V_82 , V_141 ) ;
return V_142 ;
}
static void
F_66 ( struct V_3 * V_4 , struct V_143 * V_60 )
{
struct V_22 * V_23 = V_60 -> V_145 ;
if ( ! V_23 )
return;
if ( ! F_23 ( & V_60 -> V_61 ) )
F_67 ( 3 ) ;
if ( ! F_23 ( & V_60 -> V_61 ) )
F_68 ( L_31 , V_23 ) ;
F_57 ( V_23 ) ;
V_60 -> V_145 = NULL ;
}
static int
F_69 ( struct V_3 * V_4 )
{
struct V_1 * V_1 = F_47 ( V_4 ) ;
return V_1 -> V_125 ;
}
static int
F_70 ( struct V_3 * V_4 , char * V_49 )
{
struct V_1 * V_1 = F_47 ( V_4 ) ;
#ifdef F_71
unsigned long V_141 ;
F_72 ( V_141 ) ;
if ( ! F_73 ( & V_1 -> V_161 ) ) {
if ( F_46 ( V_4 ) != V_116 )
V_1 -> V_120 ++ ;
}
F_74 ( V_141 ) ;
#endif
if ( ! ( V_1 -> V_5 & ( 0xffff << 16 ) ) )
return 0 ;
* V_49 = ( 1 << 1 ) ;
return 1 ;
}
static void
F_75 (
struct V_1 * V_1 ,
struct V_162 * V_163
) {
T_4 V_86 = 0 ;
V_163 -> V_164 = 0x29 ;
V_163 -> V_165 = 0 ;
V_163 -> V_166 = 1 ;
V_163 -> V_167 = 9 ;
V_163 -> V_168 = 0 ;
if ( V_1 -> V_14 && V_1 -> V_14 -> F_1 ) {
V_163 -> V_168 = V_1 -> V_14 -> V_169 ;
if ( ! V_163 -> V_168 )
V_163 -> V_168 = 10 ;
V_86 = 0x0001 ;
} else
V_86 = 0x0002 ;
V_86 |= 0x0010 ;
V_163 -> V_170 = F_76 ( V_86 ) ;
V_163 -> V_171 . V_172 . V_173 [ 0 ] = 0 << 1 ;
V_163 -> V_171 . V_172 . V_173 [ 1 ] = ~ 0 ;
}
static void
F_77 ( unsigned long V_174 )
{
struct V_1 * V_1 = ( void * ) V_174 ;
unsigned long V_141 ;
T_1 V_112 ;
T_1 V_175 = V_1 -> V_11 & V_176 ;
const V_47 V_177 = V_131
| V_134
| V_178 ;
F_55 ( & V_1 -> V_82 , V_141 ) ;
V_1 -> V_11 &= ~ V_176 ;
F_3 ( V_1 , V_18 , V_1 -> V_11 ) ;
F_78 ( 3 ) ;
V_112 = F_27 ( V_1 , V_13 ) ;
switch ( V_175 ) {
case V_19 :
F_4 ( L_32 ) ;
V_1 -> V_5 = ( V_179 << 16 )
| V_6 ;
V_1 -> V_11 = 0 ;
if ( V_112 & V_8 )
V_112 &= ~ V_130 ;
break;
case V_180 :
F_4 ( L_33 ) ;
V_1 -> V_5 &= ~ V_75 ;
break;
default:
F_4 ( L_34 , V_175 ) ;
break;
}
F_3 ( V_1 , V_13 , V_112 ) ;
if ( V_112 & V_130 ) {
if ( V_1 -> V_5 & V_131 )
V_1 -> V_5 |= ( V_132 << 16 )
| ( V_181 << 16 ) ;
V_1 -> V_5 &= ~ V_177 ;
V_1 -> V_7 = V_8 ;
} else {
V_1 -> V_5 |= V_177 ;
if ( V_112 & V_119 )
V_1 -> V_5 &= ~ V_178 ;
V_1 -> V_7 = V_8 | V_130 ;
}
if ( V_1 -> V_5 & V_131 ) {
T_1 V_182 = V_21 ;
V_1 -> V_7 |= V_114 ;
#ifdef F_25
V_1 -> V_7 |= V_122 ;
#endif
if ( V_1 -> V_5 & V_178 ) {
V_1 -> V_11 |= V_155 ;
V_182 |= V_183 ;
}
V_1 -> V_11 |= V_184 ;
F_3 ( V_1 , V_185 , 0xe0 ) ;
F_3 ( V_1 , V_20 , V_182 ) ;
F_3 ( V_1 , F_29 ( V_186 ) , 0 ) ;
F_9 ( V_187 , V_1 -> V_29 ) ;
F_9 ( 0 , V_1 -> V_29 ) ;
F_3 ( V_1 , F_29 ( V_34 ) ,
V_113 ) ;
} else {
V_1 -> V_11 = 0 ;
}
F_3 ( V_1 , V_18 , V_1 -> V_11 ) ;
F_3 ( V_1 , V_12 , V_1 -> V_7 ) ;
F_63 ( & V_1 -> V_82 , V_141 ) ;
}
static int
F_79 (
struct V_3 * V_4 ,
T_4 V_188 ,
T_4 V_189 ,
T_4 V_190 ,
char * V_49 ,
T_4 V_191
) {
struct V_1 * V_1 = F_47 ( V_4 ) ;
int V_142 = 0 ;
unsigned long V_141 ;
F_55 ( & V_1 -> V_82 , V_141 ) ;
switch ( V_188 ) {
case V_192 :
case V_193 :
switch ( V_189 ) {
case V_194 :
case V_195 :
break;
default:
goto error;
}
break;
case V_196 :
if ( V_190 != 1 || V_191 != 0 )
goto error;
switch ( V_189 ) {
case V_197 :
V_1 -> V_5 &= V_6 ;
V_1 -> V_11 = 0 ;
F_3 ( V_1 , V_18 , V_1 -> V_11 ) ;
V_1 -> V_7 = V_8 ;
F_3 ( V_1 , V_12 ,
V_1 -> V_7 ) ;
break;
case V_198 :
if ( ! ( V_1 -> V_5 & V_75 ) )
break;
F_4 ( L_35 ) ;
V_1 -> V_7 = 0 ;
F_3 ( V_1 , V_12 ,
V_1 -> V_7 ) ;
V_1 -> V_11 |= V_180 ;
F_3 ( V_1 , V_18 , V_1 -> V_11 ) ;
F_80 ( & V_1 -> V_161 , V_78
+ F_81 ( 20 ) ) ;
break;
case V_199 :
F_1 ( V_1 , 0 ) ;
break;
case V_200 :
case V_201 :
case V_202 :
case V_203 :
case V_204 :
break;
default:
goto error;
}
V_1 -> V_5 &= ~ ( 1 << V_189 ) ;
break;
case V_205 :
F_75 ( V_1 , (struct V_162 * ) V_49 ) ;
break;
case V_206 :
F_82 ( 0 , V_49 ) ;
break;
case V_207 :
if ( V_190 != 1 )
goto error;
F_82 ( V_1 -> V_5 , V_49 ) ;
#ifndef F_83
if ( * ( T_4 * ) ( V_49 + 2 ) )
#endif
F_4 ( L_36 , V_1 -> V_5 ) ;
break;
case V_208 :
if ( V_190 != 1 || V_191 != 0 )
goto error;
switch ( V_189 ) {
case V_198 :
if ( V_1 -> V_5 & V_209 )
goto error;
if ( ! ( V_1 -> V_5 & V_134 ) )
goto error;
F_4 ( L_37 ) ;
V_1 -> V_11 &= ~ V_184 ;
F_3 ( V_1 , V_18 , V_1 -> V_11 ) ;
break;
case V_199 :
F_1 ( V_1 , 1 ) ;
break;
case V_210 :
if ( V_1 -> V_5 & V_75 )
goto error;
if ( ! ( V_1 -> V_5 & V_6 ) )
break;
V_1 -> V_7 = 0 ;
F_3 ( V_1 , V_12 ,
V_1 -> V_7 ) ;
V_1 -> V_11 = V_19 ;
F_3 ( V_1 , V_18 , V_1 -> V_11 ) ;
V_1 -> V_5 |= V_209 ;
F_80 ( & V_1 -> V_161 , V_78
+ F_81 ( 50 ) ) ;
break;
default:
goto error;
}
V_1 -> V_5 |= 1 << V_189 ;
break;
default:
error:
V_142 = - V_105 ;
}
F_63 ( & V_1 -> V_82 , V_141 ) ;
return V_142 ;
}
static int
F_84 ( struct V_3 * V_4 )
{
F_4 ( L_38 , V_211 ) ;
return 0 ;
}
static int
F_85 ( struct V_3 * V_4 )
{
F_4 ( L_38 , V_211 ) ;
return 0 ;
}
static inline void F_86 ( struct V_1 * V_1 ) { }
static inline void F_87 ( struct V_1 * V_1 ) { }
static void F_88 ( struct V_212 * V_213 , char * V_214 , T_1 V_177 )
{
F_89 ( V_213 , L_39 , V_214 , V_177 ,
( V_177 & V_114 ) ? L_40 : L_7 ,
( V_177 & V_122 ) ? L_41 : L_7 ,
( V_177 & V_51 ) ? L_42 : L_7 ,
( V_177 & V_8 ) ? L_43 : L_7 ,
( V_177 & V_130 ) ? L_44 : L_7 ,
( V_177 & V_119 ) ? L_45 : L_7 ) ;
}
static int F_90 ( struct V_212 * V_213 , void * V_215 )
{
struct V_1 * V_1 = V_213 -> V_216 ;
struct V_22 * V_23 ;
unsigned V_83 ;
F_89 ( V_213 , L_46 ,
F_2 ( V_1 ) -> V_217 ,
V_218 , V_219 ,
V_1 -> V_5 ) ;
F_89 ( V_213 , L_47 , V_1 -> V_127 ) ;
F_89 ( V_213 , L_48
L_49 ,
V_1 -> V_121 , V_1 -> V_123 ,
V_1 -> V_128 , V_1 -> V_126 ,
V_1 -> V_68 , V_1 -> V_120 ) ;
F_91 ( & V_1 -> V_82 ) ;
if ( V_1 -> V_11 & V_220 )
F_89 ( V_213 , L_50 ) ;
else {
T_1 V_221 = F_27 ( V_1 , V_18 ) ;
F_89 (s, L_51 , t,
(t & SL11H_CTL1MASK_SOF_ENA) ? L_52 : L_7 ,
({char *s; switch (t & SL11H_CTL1MASK_FORCE) {
case SL11H_CTL1MASK_NORMAL: s = L_7; break;
case SL11H_CTL1MASK_SE0: s = L_53; break;
case SL11H_CTL1MASK_K: s = L_54; break;
default: s = L_55; break;
}; s; }),
(t & SL11H_CTL1MASK_LSPD) ? L_56 : L_7 ,
(t & SL11H_CTL1MASK_SUSPEND) ? L_57 : L_7 ) ;
F_88 ( V_213 , L_58 ,
F_27 ( V_1 , V_12 ) ) ;
F_88 ( V_213 , L_59 ,
F_27 ( V_1 , V_13 ) ) ;
F_89 ( V_213 , L_60 ,
F_27 ( V_1 , V_63 ) << 6 ) ;
}
F_89 ( V_213 , L_61 , V_1 -> V_59 ,
F_27 ( V_1 , F_29 ( V_34 ) ) ,
F_27 ( V_1 , F_29 ( V_94 ) ) ) ;
F_89 ( V_213 , L_62 , V_1 -> V_58 ,
F_27 ( V_1 , F_30 ( V_34 ) ) ,
F_27 ( V_1 , F_30 ( V_94 ) ) ) ;
F_89 ( V_213 , L_63 ) ;
F_92 (ep, &sl811->async, schedule) {
struct V_24 * V_24 ;
F_89 (s, L_64
L_65 ,
(ep == sl811->active_a) ? L_66 : L_7 ,
(ep == sl811->active_b) ? L_67 : L_7 ,
ep, ep->epnum,
({ char *s; switch (ep->nextpid) {
case USB_PID_IN: s = L_9; break;
case USB_PID_OUT: s = L_8; break;
case USB_PID_SETUP: s = L_68; break;
case USB_PID_ACK: s = L_69; break;
default: s = L_70; break;
}; s;}),
ep->maxpacket,
ep->nak_count, ep->error_count) ;
F_92 (urb, &ep->hep->urb_list, urb_list) {
F_89 ( V_213 , L_71 , V_24 ,
V_24 -> V_48 ,
V_24 -> V_38 ) ;
}
}
if ( ! F_23 ( & V_1 -> V_56 ) )
F_89 ( V_213 , L_63 ) ;
F_89 ( V_213 , L_72 , V_85 ) ;
for ( V_83 = 0 ; V_83 < V_85 ; V_83 ++ ) {
V_23 = V_1 -> V_88 [ V_83 ] ;
if ( ! V_23 )
continue;
F_89 ( V_213 , L_73 , V_83 , V_1 -> V_89 [ V_83 ] ) ;
do {
F_89 ( V_213 ,
L_74
L_75 ,
( V_23 == V_1 -> V_59 ) ? L_66 : L_7 ,
( V_23 == V_1 -> V_58 ) ? L_67 : L_7 ,
V_23 -> V_67 , V_23 ,
( V_23 -> V_99 -> V_64 == V_222 )
? L_7 : L_76 ,
V_23 -> V_99 -> V_153 , V_23 -> V_46 ,
( V_23 -> V_46 == 0 ) ? L_7
: ( ( V_23 -> V_70 == V_71 )
? L_9
: L_8 ) ,
V_23 -> V_43 , V_23 -> V_96 ) ;
V_23 = V_23 -> V_54 ;
} while ( V_23 );
}
F_93 ( & V_1 -> V_82 ) ;
F_89 ( V_213 , L_63 ) ;
return 0 ;
}
static int F_94 ( struct V_223 * V_223 , struct V_224 * V_224 )
{
return F_95 ( V_224 , F_90 , F_96 ( V_223 ) ) ;
}
static void F_86 ( struct V_1 * V_1 )
{
V_1 -> V_225 = F_97 ( V_226 , 0 , NULL , & V_227 , V_1 ) ;
}
static void F_87 ( struct V_1 * V_1 )
{
if ( V_1 -> V_225 )
F_98 ( V_226 , NULL ) ;
}
static void
F_99 ( struct V_3 * V_4 )
{
struct V_1 * V_1 = F_47 ( V_4 ) ;
unsigned long V_141 ;
F_100 ( & V_4 -> V_228 ) ;
F_55 ( & V_1 -> V_82 , V_141 ) ;
F_1 ( V_1 , 0 ) ;
F_63 ( & V_1 -> V_82 , V_141 ) ;
}
static int
F_101 ( struct V_3 * V_4 )
{
struct V_1 * V_1 = F_47 ( V_4 ) ;
V_4 -> V_9 = V_229 ;
if ( V_1 -> V_14 ) {
if ( ! F_102 ( V_4 -> V_15 . V_16 ) )
F_103 ( V_4 -> V_15 . V_16 ,
V_1 -> V_14 -> V_230 ) ;
V_4 -> V_231 = V_1 -> V_14 -> V_232 * 2 ;
}
F_1 ( V_1 , 1 ) ;
return 0 ;
}
static int
F_104 ( struct V_233 * V_45 )
{
struct V_3 * V_4 = F_105 ( V_45 ) ;
struct V_1 * V_1 = F_47 ( V_4 ) ;
struct V_234 * V_235 ;
F_87 ( V_1 ) ;
F_106 ( V_4 ) ;
V_235 = F_107 ( V_45 , V_236 , 1 ) ;
if ( V_235 )
F_108 ( V_1 -> V_29 ) ;
V_235 = F_107 ( V_45 , V_236 , 0 ) ;
if ( V_235 )
F_108 ( V_1 -> V_237 ) ;
F_109 ( V_4 ) ;
return 0 ;
}
static int
F_110 ( struct V_233 * V_45 )
{
struct V_3 * V_4 ;
struct V_1 * V_1 ;
struct V_234 * V_27 , * V_238 , * V_239 ;
int V_240 ;
void T_2 * V_237 ;
void T_2 * V_29 ;
int V_142 ;
T_1 V_241 , V_242 = 0 ;
unsigned long V_243 ;
if ( F_111 () )
return - V_147 ;
V_239 = F_107 ( V_45 , V_244 , 0 ) ;
if ( V_45 -> V_245 < 3 || ! V_239 )
return - V_147 ;
V_240 = V_239 -> F_22 ;
V_243 = V_239 -> V_141 & V_246 ;
if ( V_45 -> V_45 . V_247 ) {
F_4 ( L_77 ) ;
return - V_154 ;
}
V_27 = F_107 ( V_45 , V_236 , 0 ) ;
V_238 = F_107 ( V_45 , V_236 , 1 ) ;
V_142 = - V_248 ;
if ( ! V_27 || ! V_238 ) {
V_27 = F_107 ( V_45 , V_249 , 0 ) ;
V_238 = F_107 ( V_45 , V_249 , 1 ) ;
if ( ! V_27 || ! V_238 )
return - V_147 ;
V_242 = 1 ;
V_237 = ( void T_2 * ) ( unsigned long ) V_27 -> F_22 ;
V_29 = ( void T_2 * ) ( unsigned long ) V_238 -> F_22 ;
} else {
V_237 = F_112 ( V_27 -> F_22 , 1 ) ;
if ( V_237 == NULL ) {
V_142 = - V_146 ;
goto V_250;
}
V_29 = F_112 ( V_238 -> F_22 , 1 ) ;
if ( V_29 == NULL ) {
V_142 = - V_146 ;
goto V_251;
}
}
V_4 = F_113 ( & V_252 , & V_45 -> V_45 , F_114 ( & V_45 -> V_45 ) ) ;
if ( ! V_4 ) {
V_142 = - V_146 ;
goto V_253;
}
V_4 -> V_254 = V_27 -> F_22 ;
V_1 = F_47 ( V_4 ) ;
F_115 ( & V_1 -> V_82 ) ;
F_59 ( & V_1 -> V_56 ) ;
V_1 -> V_14 = V_45 -> V_45 . V_255 ;
F_116 ( & V_1 -> V_161 ) ;
V_1 -> V_161 . V_256 = F_77 ;
V_1 -> V_161 . V_238 = ( unsigned long ) V_1 ;
V_1 -> V_237 = V_237 ;
V_1 -> V_29 = V_29 ;
F_91 ( & V_1 -> V_82 ) ;
F_1 ( V_1 , 0 ) ;
F_93 ( & V_1 -> V_82 ) ;
F_67 ( 200 ) ;
V_241 = F_27 ( V_1 , V_257 ) ;
switch ( V_241 >> 4 ) {
case 1 :
V_4 -> V_217 = L_78 ;
break;
case 2 :
V_4 -> V_217 = L_79 ;
break;
default:
F_4 ( L_80 , V_241 ) ;
V_142 = - V_258 ;
goto V_259;
}
V_243 |= V_260 ;
V_142 = F_117 ( V_4 , V_240 , V_243 ) ;
if ( V_142 != 0 )
goto V_259;
F_86 ( V_1 ) ;
return V_142 ;
V_259:
F_109 ( V_4 ) ;
V_253:
if ( ! V_242 )
F_108 ( V_29 ) ;
V_251:
if ( ! V_242 )
F_108 ( V_237 ) ;
V_250:
F_4 ( L_81 , V_142 ) ;
return V_142 ;
}
static int
F_118 ( struct V_233 * V_45 , T_6 V_9 )
{
struct V_3 * V_4 = F_105 ( V_45 ) ;
struct V_1 * V_1 = F_47 ( V_4 ) ;
int V_142 = 0 ;
switch ( V_9 . V_261 ) {
case V_262 :
V_142 = F_84 ( V_4 ) ;
break;
case V_263 :
case V_264 :
case V_265 :
F_1 ( V_1 , 0 ) ;
break;
}
return V_142 ;
}
static int
F_119 ( struct V_233 * V_45 )
{
struct V_3 * V_4 = F_105 ( V_45 ) ;
struct V_1 * V_1 = F_47 ( V_4 ) ;
if ( ! V_1 -> V_5 || ! F_102 ( & V_4 -> V_15 . V_266 -> V_45 ) ) {
V_1 -> V_5 = 0 ;
F_1 ( V_1 , 1 ) ;
F_120 ( V_4 -> V_15 . V_266 ) ;
return 0 ;
}
return F_85 ( V_4 ) ;
}
