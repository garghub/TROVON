int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
unsigned long V_5 ;
F_2 ( & V_2 -> V_6 , V_5 ) ;
F_3 ( V_2 , L_1 V_7 ,
V_4 -> V_8 , V_4 -> V_9 ) ;
if ( ( V_2 -> V_8 & V_4 -> V_8 ) ||
( V_2 -> V_9 & V_4 -> V_9 ) ) {
F_4 ( & V_2 -> V_6 , V_5 ) ;
F_5 ( V_10 L_2 ,
V_2 -> V_11 ) ;
return - V_12 ;
}
if ( F_6 ( & V_2 -> V_13 ) )
F_7 ( & V_2 -> V_14 ) ;
V_2 -> V_8 |= V_4 -> V_8 ;
V_2 -> V_9 |= V_4 -> V_9 ;
F_8 ( & V_4 -> V_13 , & V_2 -> V_13 ) ;
F_4 ( & V_2 -> V_6 , V_5 ) ;
return 0 ;
}
void F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
unsigned long V_5 ;
F_2 ( & V_2 -> V_6 , V_5 ) ;
F_3 ( V_2 , L_3 V_7 ,
V_4 -> V_8 , V_4 -> V_9 ) ;
V_2 -> V_8 &= ~ V_4 -> V_8 ;
V_2 -> V_9 &= ~ V_4 -> V_9 ;
F_10 ( & V_4 -> V_13 ) ;
if ( F_6 ( & V_2 -> V_13 ) )
F_11 ( & V_2 -> V_14 ) ;
F_4 ( & V_2 -> V_6 , V_5 ) ;
}
int F_12 ( struct V_1 * V_2 , int V_15 , unsigned long V_16 )
{
F_13 ( V_15 < 0 || V_15 >= V_2 -> V_17 ||
V_16 > V_18 ) ;
F_3 ( V_2 , L_4 V_7 , V_15 , V_16 ) ;
if ( V_16 & 0xf ) {
F_5 ( V_10
L_5 ,
V_2 -> V_11 , V_16 , V_15 ) ;
return - V_19 ;
}
F_14 ( V_2 , F_15 ( V_15 ) , V_16 >> 4 ) ;
return 0 ;
}
int F_16 ( struct V_1 * V_2 , int V_15 )
{
F_13 ( V_15 < 0 || V_15 >= V_2 -> V_20 ) ;
return V_15 * V_21 ;
}
int F_17 ( struct V_1 * V_2 , int V_15 )
{
F_13 ( V_15 < 0 || V_15 >= V_2 -> V_17 ) ;
return V_2 -> V_20 * V_21 + V_15 * V_22 ;
}
void F_18 ( struct V_1 * V_2 , int V_15 )
{
unsigned long V_5 ;
F_2 ( & V_2 -> V_6 , V_5 ) ;
F_3 ( V_2 , L_6 V_7 , V_15 ) ;
F_14 ( V_2 , V_23 ,
F_19 ( V_2 , V_23 ) | F_20 ( V_15 ) ) ;
F_4 ( & V_2 -> V_6 , V_5 ) ;
}
void F_21 ( struct V_1 * V_2 , int V_15 )
{
F_14 ( V_2 , V_24 , F_20 ( V_15 ) ) ;
F_3 ( V_2 , L_7 V_7 , V_15 ) ;
}
void F_22 ( struct V_1 * V_2 , int V_15 )
{
unsigned long V_5 ;
if ( ! ( V_15 % 8 ) )
V_15 >>= 3 ;
F_2 ( & V_2 -> V_6 , V_5 ) ;
F_3 ( V_2 , L_8 V_7 , V_15 ) ;
F_14 ( V_2 , V_25 ,
F_19 ( V_2 , V_25 ) | F_20 ( V_15 ) ) ;
F_4 ( & V_2 -> V_6 , V_5 ) ;
}
void F_23 ( struct V_1 * V_2 , int V_15 )
{
if ( ! ( V_15 % 8 ) )
V_15 >>= 3 ;
F_14 ( V_2 , V_26 , F_20 ( V_15 ) ) ;
F_3 ( V_2 , L_9 V_7 , V_15 ) ;
}
void F_24 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
unsigned long V_5 ;
F_2 ( & V_2 -> V_6 , V_5 ) ;
F_3 ( V_2 , L_10 V_7 , V_4 ) ;
F_25 ( V_27 , & V_4 -> V_5 ) ;
F_26 ( & V_4 -> V_28 , & V_2 -> V_28 ) ;
F_4 ( & V_2 -> V_6 , V_5 ) ;
}
void F_27 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
unsigned long V_5 ;
F_2 ( & V_2 -> V_6 , V_5 ) ;
F_3 ( V_2 , L_11 V_7 , V_4 ) ;
F_28 ( & V_4 -> V_28 ) ;
F_4 ( & V_2 -> V_6 , V_5 ) ;
}
static inline void F_29 ( struct V_1 * V_2 )
{
F_30 ( V_2 , L_12 V_7 ) ;
F_14 ( V_2 , V_29 , F_19 ( V_2 , V_29 ) | V_30 ) ;
}
static inline void F_31 ( struct V_1 * V_2 )
{
F_14 ( V_2 , V_29 , F_19 ( V_2 , V_29 ) & ~ V_30 ) ;
F_30 ( V_2 , L_13 V_7 ) ;
}
static T_1 F_32 ( int V_31 , void * V_32 )
{
struct V_1 * V_2 = V_32 ;
T_2 V_33 = F_19 ( V_2 , V_34 ) ;
F_14 ( V_2 , V_34 , V_33 ) ;
F_3 ( V_2 , L_14 V_7 , V_33 ) ;
if ( V_33 & V_35 ) {
if ( V_33 & V_36 ) {
return V_37 ;
}
if ( V_33 & V_38 ) {
if ( F_33 () )
F_5 ( V_39
L_15
L_16 ,
V_2 -> V_11 , V_33 ) ;
return V_37 ;
}
if ( F_33 () )
F_5 ( V_39
L_17 ,
V_2 -> V_11 , V_33 ) ;
}
return V_37 ;
}
static inline void F_34 ( struct V_1 * V_2 )
{
if ( F_35 ( F_36 ( & V_2 -> V_14 ) ) ) {
F_30 ( V_2 , L_18 V_7 ) ;
F_31 ( V_2 ) ;
F_37 ( & V_2 -> V_14 ) ;
} else
F_30 ( V_2 , L_19 V_7 ) ;
}
static T_1 F_38 ( int V_31 , void * V_32 )
{
struct V_1 * V_2 = V_32 ;
T_2 V_40 = F_19 ( V_2 , V_41 ) ;
F_30 ( V_2 , L_20 V_7 , V_40 ) ;
F_34 ( V_2 ) ;
F_14 ( V_2 , V_41 , V_40 ) ;
#ifdef F_39
if ( F_40 ( V_2 , V_42 ) )
F_41 ( V_43 , V_44 ,
( F_42 ( V_43 , V_44 ) | V_45 ) ) ;
#endif
return V_37 ;
}
static T_1 F_43 ( int V_31 , void * V_32 )
{
struct V_1 * V_2 = V_32 ;
T_2 V_40 = F_19 ( V_2 , V_46 ) ;
F_30 ( V_2 , L_21 V_7 , V_40 ) ;
F_34 ( V_2 ) ;
F_14 ( V_2 , V_46 , V_40 ) ;
#ifdef F_39
if ( F_40 ( V_2 , V_42 ) )
F_41 ( V_43 , V_44 ,
( F_42 ( V_43 , V_44 ) | V_47 ) ) ;
#endif
return V_37 ;
}
static T_1 F_44 ( int V_31 , void * V_32 )
{
struct V_1 * V_2 = V_32 ;
T_2 V_48 = F_19 ( V_2 , V_49 ) ;
F_14 ( V_2 , V_49 , V_48 ) ;
F_3 ( V_2 , L_22 V_7 , V_48 ) ;
if ( F_33 () )
F_5 ( V_39
L_23 ,
V_2 -> V_11 , V_48 ) ;
return V_37 ;
}
static T_1 F_45 ( int V_31 , void * V_32 )
{
struct V_1 * V_2 = V_32 ;
struct V_50 * V_51 ;
T_2 V_48 = F_19 ( V_2 , V_52 ) ;
F_3 ( V_2 , L_24 V_7 , V_48 ) ;
F_46 (l, &mal->list) {
struct V_3 * V_53 = F_47 ( V_51 , struct V_3 , V_13 ) ;
if ( V_48 & V_53 -> V_9 ) {
F_25 ( V_54 , & V_53 -> V_5 ) ;
V_53 -> V_55 -> V_56 ( V_53 -> V_57 ) ;
}
}
F_34 ( V_2 ) ;
F_14 ( V_2 , V_52 , V_48 ) ;
return V_37 ;
}
static T_1 F_48 ( int V_31 , void * V_32 )
{
struct V_1 * V_2 = V_32 ;
T_2 V_33 = F_19 ( V_2 , V_34 ) ;
if ( V_33 & V_35 ) {
if ( V_33 & V_36 ) {
if ( V_33 & V_58 )
return F_45 ( V_31 , V_32 ) ;
else
return F_44 ( V_31 , V_32 ) ;
} else {
return F_32 ( V_31 , V_32 ) ;
}
}
return V_37 ;
}
void F_49 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
while ( F_50 ( V_27 , & V_4 -> V_5 ) )
F_51 ( 1 ) ;
F_52 ( & V_2 -> V_14 ) ;
}
void F_53 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_54 () ;
F_55 ( V_27 , & V_4 -> V_5 ) ;
F_56 ( & V_2 -> V_14 ) ;
}
static int F_57 ( struct V_59 * V_14 , int V_60 )
{
struct V_1 * V_2 = F_58 ( V_14 , struct V_1 , V_14 ) ;
struct V_50 * V_51 ;
int V_61 = 0 ;
unsigned long V_5 ;
F_30 ( V_2 , L_25 V_7 , V_60 ) ;
V_62:
F_46 (l, &mal->poll_list) {
struct V_3 * V_53 =
F_47 ( V_51 , struct V_3 , V_28 ) ;
V_53 -> V_55 -> V_63 ( V_53 -> V_57 ) ;
}
F_46 (l, &mal->poll_list) {
struct V_3 * V_53 =
F_47 ( V_51 , struct V_3 , V_28 ) ;
int V_64 ;
if ( F_59 ( F_60 ( V_27 , & V_53 -> V_5 ) ) )
continue;
V_64 = V_53 -> V_55 -> V_65 ( V_53 -> V_57 , V_60 ) ;
if ( V_64 ) {
V_61 += V_64 ;
V_60 -= V_64 ;
if ( V_60 <= 0 )
goto V_66;
}
}
F_2 ( & V_2 -> V_6 , V_5 ) ;
F_61 ( V_14 ) ;
F_29 ( V_2 ) ;
F_4 ( & V_2 -> V_6 , V_5 ) ;
F_46 (l, &mal->poll_list) {
struct V_3 * V_53 =
F_47 ( V_51 , struct V_3 , V_28 ) ;
if ( F_59 ( F_60 ( V_27 , & V_53 -> V_5 ) ) )
continue;
if ( F_59 ( V_53 -> V_55 -> V_67 ( V_53 -> V_57 ) ||
F_60 ( V_54 , & V_53 -> V_5 ) ) ) {
F_30 ( V_2 , L_26 V_7 ) ;
if ( F_62 ( V_14 ) )
F_31 ( V_2 ) ;
else
F_30 ( V_2 , L_27 V_7 ) ;
if ( V_60 > 0 )
goto V_62;
else
goto V_66;
}
V_53 -> V_55 -> V_63 ( V_53 -> V_57 ) ;
}
V_66:
F_30 ( V_2 , L_28 V_7 , V_60 , V_61 ) ;
return V_61 ;
}
static void F_63 ( struct V_1 * V_2 )
{
int V_64 = 10 ;
F_3 ( V_2 , L_29 V_7 ) ;
F_14 ( V_2 , V_29 , V_68 ) ;
while ( ( F_19 ( V_2 , V_29 ) & V_68 ) && V_64 )
-- V_64 ;
if ( F_59 ( ! V_64 ) )
F_5 ( V_39 L_30 , V_2 -> V_11 ) ;
}
int F_64 ( struct V_1 * V_2 )
{
return sizeof( struct V_69 ) +
sizeof( struct V_70 ) ;
}
void * F_65 ( struct V_1 * V_2 , void * V_71 )
{
struct V_69 * V_72 = V_71 ;
struct V_70 * V_73 = (struct V_70 * ) ( V_72 + 1 ) ;
int V_74 ;
V_72 -> V_75 = V_2 -> V_75 ;
V_72 -> V_11 = V_2 -> V_11 ;
V_73 -> V_76 = V_2 -> V_20 ;
V_73 -> V_77 = V_2 -> V_17 ;
V_73 -> V_78 = F_19 ( V_2 , V_29 ) ;
V_73 -> V_33 = F_19 ( V_2 , V_34 ) ;
V_73 -> V_79 = F_19 ( V_2 , V_80 ) ;
V_73 -> V_81 = F_19 ( V_2 , V_23 ) ;
V_73 -> V_82 = F_19 ( V_2 , V_24 ) ;
V_73 -> V_83 = F_19 ( V_2 , V_41 ) ;
V_73 -> V_84 = F_19 ( V_2 , V_49 ) ;
V_73 -> V_85 = F_19 ( V_2 , V_25 ) ;
V_73 -> V_86 = F_19 ( V_2 , V_26 ) ;
V_73 -> V_87 = F_19 ( V_2 , V_46 ) ;
V_73 -> V_88 = F_19 ( V_2 , V_52 ) ;
for ( V_74 = 0 ; V_74 < V_73 -> V_76 ; ++ V_74 )
V_73 -> V_89 [ V_74 ] = F_19 ( V_2 , F_66 ( V_74 ) ) ;
for ( V_74 = 0 ; V_74 < V_73 -> V_77 ; ++ V_74 ) {
V_73 -> V_90 [ V_74 ] = F_19 ( V_2 , F_67 ( V_74 ) ) ;
V_73 -> V_91 [ V_74 ] = F_19 ( V_2 , F_15 ( V_74 ) ) ;
}
return V_73 + 1 ;
}
static int F_68 ( struct V_92 * V_93 )
{
struct V_1 * V_2 ;
int V_94 = 0 , V_74 , V_95 ;
int V_11 = V_96 ++ ;
unsigned int V_97 ;
const T_2 * V_98 ;
T_2 V_78 ;
unsigned long V_99 ;
T_3 V_100 , V_101 , V_102 ;
V_2 = F_69 ( sizeof( struct V_1 ) , V_103 ) ;
if ( ! V_2 ) {
F_5 ( V_39
L_31 ,
V_11 ) ;
return - V_104 ;
}
V_2 -> V_11 = V_11 ;
V_2 -> V_93 = V_93 ;
V_2 -> V_75 = F_70 ( V_93 -> V_57 . V_105 , L_32 ) ? 2 : 1 ;
F_3 ( V_2 , L_33 V_7 ) ;
V_98 = F_71 ( V_93 -> V_57 . V_105 , L_34 , NULL ) ;
if ( V_98 == NULL ) {
F_5 ( V_39
L_35 ,
V_11 ) ;
V_94 = - V_106 ;
goto V_107;
}
V_2 -> V_20 = V_98 [ 0 ] ;
V_98 = F_71 ( V_93 -> V_57 . V_105 , L_36 , NULL ) ;
if ( V_98 == NULL ) {
F_5 ( V_39
L_37 ,
V_11 ) ;
V_94 = - V_106 ;
goto V_107;
}
V_2 -> V_17 = V_98 [ 0 ] ;
V_97 = F_72 ( V_93 -> V_57 . V_105 , 0 ) ;
if ( V_97 == 0 ) {
F_5 ( V_39
L_38 , V_11 ) ;
V_94 = - V_106 ;
goto V_107;
}
V_2 -> V_108 = F_73 ( V_93 -> V_57 . V_105 , V_97 , 0x100 ) ;
if ( ! F_74 ( V_2 -> V_108 ) ) {
F_5 ( V_39
L_39 , V_11 ) ;
V_94 = - V_106 ;
goto V_107;
}
if ( F_70 ( V_93 -> V_57 . V_105 , L_40 ) ) {
#if F_75 ( V_109 ) && \
F_75 ( V_110 )
V_2 -> V_111 |= ( V_42 |
V_112 ) ;
#else
F_5 ( V_39 L_41 ,
V_93 -> V_57 . V_105 -> V_113 ) ;
V_94 = - V_106 ;
goto V_107;
#endif
}
V_2 -> V_114 = F_76 ( V_93 -> V_57 . V_105 , 0 ) ;
V_2 -> V_115 = F_76 ( V_93 -> V_57 . V_105 , 1 ) ;
V_2 -> V_116 = F_76 ( V_93 -> V_57 . V_105 , 2 ) ;
if ( F_40 ( V_2 , V_112 ) ) {
V_2 -> V_117 = V_2 -> V_118 = V_2 -> V_116 ;
} else {
V_2 -> V_117 = F_76 ( V_93 -> V_57 . V_105 , 3 ) ;
V_2 -> V_118 = F_76 ( V_93 -> V_57 . V_105 , 4 ) ;
}
if ( V_2 -> V_114 == V_119 || V_2 -> V_115 == V_119 ||
V_2 -> V_116 == V_119 || V_2 -> V_117 == V_119 ||
V_2 -> V_118 == V_119 ) {
F_5 ( V_39
L_42 , V_11 ) ;
V_94 = - V_106 ;
goto V_120;
}
F_77 ( & V_2 -> V_28 ) ;
F_77 ( & V_2 -> V_13 ) ;
F_78 ( & V_2 -> V_6 ) ;
F_79 ( & V_2 -> V_121 ) ;
F_80 ( & V_2 -> V_121 , & V_2 -> V_14 , F_57 ,
V_122 ) ;
F_63 ( V_2 ) ;
V_78 = ( V_2 -> V_75 == 2 ) ? V_123 : V_124 ;
V_78 |= V_125 | V_126 | V_127 ;
if ( F_70 ( V_93 -> V_57 . V_105 , L_43 ) )
V_78 &= ~ ( V_128 | V_129 ) ;
F_14 ( V_2 , V_29 , V_78 ) ;
F_13 ( V_2 -> V_20 <= 0 || V_2 -> V_20 > 32 ) ;
F_13 ( V_2 -> V_17 <= 0 || V_2 -> V_17 > 32 ) ;
V_95 = sizeof( struct V_130 ) *
( V_21 * V_2 -> V_20 +
V_22 * V_2 -> V_17 ) ;
V_2 -> V_131 =
F_81 ( & V_93 -> V_57 , V_95 , & V_2 -> V_132 ,
V_103 ) ;
if ( V_2 -> V_131 == NULL ) {
F_5 ( V_39
L_44 ,
V_11 ) ;
V_94 = - V_104 ;
goto V_120;
}
memset ( V_2 -> V_131 , 0 , V_95 ) ;
for ( V_74 = 0 ; V_74 < V_2 -> V_20 ; ++ V_74 )
F_14 ( V_2 , F_66 ( V_74 ) , V_2 -> V_132 +
sizeof( struct V_130 ) *
F_16 ( V_2 , V_74 ) ) ;
for ( V_74 = 0 ; V_74 < V_2 -> V_17 ; ++ V_74 )
F_14 ( V_2 , F_67 ( V_74 ) , V_2 -> V_132 +
sizeof( struct V_130 ) *
F_17 ( V_2 , V_74 ) ) ;
if ( F_40 ( V_2 , V_112 ) ) {
V_99 = V_133 ;
V_100 = V_101 = V_102 = F_48 ;
} else {
V_99 = 0 ;
V_100 = F_32 ;
V_101 = F_44 ;
V_102 = F_45 ;
}
V_94 = F_82 ( V_2 -> V_116 , V_100 , V_99 , L_45 , V_2 ) ;
if ( V_94 )
goto V_134;
V_94 = F_82 ( V_2 -> V_117 , V_101 , V_99 , L_46 , V_2 ) ;
if ( V_94 )
goto V_135;
V_94 = F_82 ( V_2 -> V_114 , F_38 , 0 , L_47 , V_2 ) ;
if ( V_94 )
goto V_136;
V_94 = F_82 ( V_2 -> V_118 , V_102 , V_99 , L_48 , V_2 ) ;
if ( V_94 )
goto V_137;
V_94 = F_82 ( V_2 -> V_115 , F_43 , 0 , L_49 , V_2 ) ;
if ( V_94 )
goto V_138;
if ( V_2 -> V_75 == 2 )
F_14 ( V_2 , V_80 , V_139 ) ;
else
F_14 ( V_2 , V_80 , V_140 ) ;
F_29 ( V_2 ) ;
F_5 ( V_141
L_50 ,
V_2 -> V_75 , V_93 -> V_57 . V_105 -> V_113 ,
V_2 -> V_20 , V_2 -> V_17 ) ;
F_83 () ;
F_84 ( & V_93 -> V_57 , V_2 ) ;
F_85 ( V_2 ) ;
return 0 ;
V_138:
F_86 ( V_2 -> V_118 , V_2 ) ;
V_137:
F_86 ( V_2 -> V_114 , V_2 ) ;
V_136:
F_86 ( V_2 -> V_117 , V_2 ) ;
V_135:
F_86 ( V_2 -> V_116 , V_2 ) ;
V_134:
F_87 ( & V_93 -> V_57 , V_95 , V_2 -> V_131 , V_2 -> V_132 ) ;
V_120:
F_88 ( V_2 -> V_108 , 0x100 ) ;
V_107:
F_89 ( V_2 ) ;
return V_94 ;
}
static int F_90 ( struct V_92 * V_93 )
{
struct V_1 * V_2 = F_91 ( & V_93 -> V_57 ) ;
F_3 ( V_2 , L_51 V_7 ) ;
F_11 ( & V_2 -> V_14 ) ;
if ( ! F_6 ( & V_2 -> V_13 ) )
F_92 ( 1 , V_142
L_52 ,
V_2 -> V_11 ) ;
F_84 ( & V_93 -> V_57 , NULL ) ;
F_86 ( V_2 -> V_116 , V_2 ) ;
F_86 ( V_2 -> V_117 , V_2 ) ;
F_86 ( V_2 -> V_114 , V_2 ) ;
F_86 ( V_2 -> V_118 , V_2 ) ;
F_86 ( V_2 -> V_115 , V_2 ) ;
F_63 ( V_2 ) ;
F_93 ( V_2 ) ;
F_87 ( & V_93 -> V_57 ,
sizeof( struct V_130 ) *
( V_21 * V_2 -> V_20 +
V_22 * V_2 -> V_17 ) , V_2 -> V_131 ,
V_2 -> V_132 ) ;
F_89 ( V_2 ) ;
return 0 ;
}
int T_4 F_94 ( void )
{
return F_95 ( & V_143 ) ;
}
void F_96 ( void )
{
F_97 ( & V_143 ) ;
}
