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
F_37 ( & V_2 -> V_6 ) ;
F_31 ( V_2 ) ;
F_38 ( & V_2 -> V_6 ) ;
F_39 ( & V_2 -> V_14 ) ;
} else
F_30 ( V_2 , L_19 V_7 ) ;
}
static T_1 F_40 ( int V_31 , void * V_32 )
{
struct V_1 * V_2 = V_32 ;
T_2 V_40 = F_19 ( V_2 , V_41 ) ;
F_30 ( V_2 , L_20 V_7 , V_40 ) ;
F_34 ( V_2 ) ;
F_14 ( V_2 , V_41 , V_40 ) ;
#ifdef F_41
if ( F_42 ( V_2 , V_42 ) )
F_43 ( V_43 , V_44 ,
( F_44 ( V_43 , V_44 ) | V_45 ) ) ;
#endif
return V_37 ;
}
static T_1 F_45 ( int V_31 , void * V_32 )
{
struct V_1 * V_2 = V_32 ;
T_2 V_40 = F_19 ( V_2 , V_46 ) ;
F_30 ( V_2 , L_21 V_7 , V_40 ) ;
F_34 ( V_2 ) ;
F_14 ( V_2 , V_46 , V_40 ) ;
#ifdef F_41
if ( F_42 ( V_2 , V_42 ) )
F_43 ( V_43 , V_44 ,
( F_44 ( V_43 , V_44 ) | V_47 ) ) ;
#endif
return V_37 ;
}
static T_1 F_46 ( int V_31 , void * V_32 )
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
static T_1 F_47 ( int V_31 , void * V_32 )
{
struct V_1 * V_2 = V_32 ;
struct V_50 * V_51 ;
T_2 V_48 = F_19 ( V_2 , V_52 ) ;
F_3 ( V_2 , L_24 V_7 , V_48 ) ;
F_48 (l, &mal->list) {
struct V_3 * V_53 = F_49 ( V_51 , struct V_3 , V_13 ) ;
if ( V_48 & V_53 -> V_9 ) {
F_25 ( V_54 , & V_53 -> V_5 ) ;
V_53 -> V_55 -> V_56 ( V_53 -> V_57 ) ;
}
}
F_34 ( V_2 ) ;
F_14 ( V_2 , V_52 , V_48 ) ;
return V_37 ;
}
static T_1 F_50 ( int V_31 , void * V_32 )
{
struct V_1 * V_2 = V_32 ;
T_2 V_33 = F_19 ( V_2 , V_34 ) ;
if ( V_33 & V_35 ) {
if ( V_33 & V_36 ) {
if ( V_33 & V_58 )
return F_47 ( V_31 , V_32 ) ;
else
return F_46 ( V_31 , V_32 ) ;
} else {
return F_32 ( V_31 , V_32 ) ;
}
}
return V_37 ;
}
void F_51 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
while ( F_52 ( V_27 , & V_4 -> V_5 ) )
F_53 ( 1 ) ;
F_54 ( & V_2 -> V_14 ) ;
}
void F_55 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_56 () ;
F_57 ( V_27 , & V_4 -> V_5 ) ;
F_58 ( & V_2 -> V_14 ) ;
}
static int F_59 ( struct V_59 * V_14 , int V_60 )
{
struct V_1 * V_2 = F_60 ( V_14 , struct V_1 , V_14 ) ;
struct V_50 * V_51 ;
int V_61 = 0 ;
unsigned long V_5 ;
F_30 ( V_2 , L_25 V_7 , V_60 ) ;
F_48 (l, &mal->poll_list) {
struct V_3 * V_53 =
F_49 ( V_51 , struct V_3 , V_28 ) ;
V_53 -> V_55 -> V_62 ( V_53 -> V_57 ) ;
}
F_48 (l, &mal->poll_list) {
struct V_3 * V_53 =
F_49 ( V_51 , struct V_3 , V_28 ) ;
int V_63 ;
if ( F_61 ( F_62 ( V_27 , & V_53 -> V_5 ) ) )
continue;
V_63 = V_53 -> V_55 -> V_64 ( V_53 -> V_57 , V_60 - V_61 ) ;
if ( V_63 ) {
V_61 += V_63 ;
if ( V_61 >= V_60 )
return V_60 ;
}
}
if ( F_63 ( V_14 , V_61 ) ) {
F_2 ( & V_2 -> V_6 , V_5 ) ;
F_29 ( V_2 ) ;
F_4 ( & V_2 -> V_6 , V_5 ) ;
}
F_48 (l, &mal->poll_list) {
struct V_3 * V_53 =
F_49 ( V_51 , struct V_3 , V_28 ) ;
if ( F_61 ( F_62 ( V_27 , & V_53 -> V_5 ) ) )
continue;
if ( F_61 ( V_53 -> V_55 -> V_65 ( V_53 -> V_57 ) ||
F_62 ( V_54 , & V_53 -> V_5 ) ) ) {
F_30 ( V_2 , L_26 V_7 ) ;
if ( ! F_64 ( V_14 ) )
goto V_66;
F_2 ( & V_2 -> V_6 , V_5 ) ;
F_31 ( V_2 ) ;
F_4 ( & V_2 -> V_6 , V_5 ) ;
}
V_53 -> V_55 -> V_62 ( V_53 -> V_57 ) ;
}
V_66:
F_30 ( V_2 , L_27 V_7 , V_60 , V_61 ) ;
return V_61 ;
}
static void F_65 ( struct V_1 * V_2 )
{
int V_63 = 10 ;
F_3 ( V_2 , L_28 V_7 ) ;
F_14 ( V_2 , V_29 , V_67 ) ;
while ( ( F_19 ( V_2 , V_29 ) & V_67 ) && V_63 )
-- V_63 ;
if ( F_61 ( ! V_63 ) )
F_5 ( V_39 L_29 , V_2 -> V_11 ) ;
}
int F_66 ( struct V_1 * V_2 )
{
return sizeof( struct V_68 ) +
sizeof( struct V_69 ) ;
}
void * F_67 ( struct V_1 * V_2 , void * V_70 )
{
struct V_68 * V_71 = V_70 ;
struct V_69 * V_72 = (struct V_69 * ) ( V_71 + 1 ) ;
int V_73 ;
V_71 -> V_74 = V_2 -> V_74 ;
V_71 -> V_11 = V_2 -> V_11 ;
V_72 -> V_75 = V_2 -> V_20 ;
V_72 -> V_76 = V_2 -> V_17 ;
V_72 -> V_77 = F_19 ( V_2 , V_29 ) ;
V_72 -> V_33 = F_19 ( V_2 , V_34 ) ;
V_72 -> V_78 = F_19 ( V_2 , V_79 ) ;
V_72 -> V_80 = F_19 ( V_2 , V_23 ) ;
V_72 -> V_81 = F_19 ( V_2 , V_24 ) ;
V_72 -> V_82 = F_19 ( V_2 , V_41 ) ;
V_72 -> V_83 = F_19 ( V_2 , V_49 ) ;
V_72 -> V_84 = F_19 ( V_2 , V_25 ) ;
V_72 -> V_85 = F_19 ( V_2 , V_26 ) ;
V_72 -> V_86 = F_19 ( V_2 , V_46 ) ;
V_72 -> V_87 = F_19 ( V_2 , V_52 ) ;
for ( V_73 = 0 ; V_73 < V_72 -> V_75 ; ++ V_73 )
V_72 -> V_88 [ V_73 ] = F_19 ( V_2 , F_68 ( V_73 ) ) ;
for ( V_73 = 0 ; V_73 < V_72 -> V_76 ; ++ V_73 ) {
V_72 -> V_89 [ V_73 ] = F_19 ( V_2 , F_69 ( V_73 ) ) ;
V_72 -> V_90 [ V_73 ] = F_19 ( V_2 , F_15 ( V_73 ) ) ;
}
return V_72 + 1 ;
}
static int F_70 ( struct V_91 * V_92 )
{
struct V_1 * V_2 ;
int V_93 = 0 , V_73 , V_94 ;
int V_11 = V_95 ++ ;
unsigned int V_96 ;
const T_2 * V_97 ;
T_2 V_77 ;
unsigned long V_98 ;
T_3 V_99 , V_100 , V_101 ;
V_2 = F_71 ( sizeof( struct V_1 ) , V_102 ) ;
if ( ! V_2 )
return - V_103 ;
V_2 -> V_11 = V_11 ;
V_2 -> V_92 = V_92 ;
V_2 -> V_74 = F_72 ( V_92 -> V_57 . V_104 , L_30 ) ? 2 : 1 ;
F_3 ( V_2 , L_31 V_7 ) ;
V_97 = F_73 ( V_92 -> V_57 . V_104 , L_32 , NULL ) ;
if ( V_97 == NULL ) {
F_5 ( V_39
L_33 ,
V_11 ) ;
V_93 = - V_105 ;
goto V_106;
}
V_2 -> V_20 = V_97 [ 0 ] ;
V_97 = F_73 ( V_92 -> V_57 . V_104 , L_34 , NULL ) ;
if ( V_97 == NULL ) {
F_5 ( V_39
L_35 ,
V_11 ) ;
V_93 = - V_105 ;
goto V_106;
}
V_2 -> V_17 = V_97 [ 0 ] ;
V_96 = F_74 ( V_92 -> V_57 . V_104 , 0 ) ;
if ( V_96 == 0 ) {
F_5 ( V_39
L_36 , V_11 ) ;
V_93 = - V_105 ;
goto V_106;
}
V_2 -> V_107 = F_75 ( V_92 -> V_57 . V_104 , V_96 , 0x100 ) ;
if ( ! F_76 ( V_2 -> V_107 ) ) {
F_5 ( V_39
L_37 , V_11 ) ;
V_93 = - V_105 ;
goto V_106;
}
if ( F_72 ( V_92 -> V_57 . V_104 , L_38 ) ) {
#if F_77 ( V_108 ) && \
F_77 ( V_109 )
V_2 -> V_110 |= ( V_42 |
V_111 ) ;
#else
F_5 ( V_39 L_39 ,
V_92 -> V_57 . V_104 ) ;
V_93 = - V_105 ;
goto V_106;
#endif
}
V_2 -> V_112 = F_78 ( V_92 -> V_57 . V_104 , 0 ) ;
V_2 -> V_113 = F_78 ( V_92 -> V_57 . V_104 , 1 ) ;
V_2 -> V_114 = F_78 ( V_92 -> V_57 . V_104 , 2 ) ;
if ( F_42 ( V_2 , V_111 ) ) {
V_2 -> V_115 = V_2 -> V_116 = V_2 -> V_114 ;
} else {
V_2 -> V_115 = F_78 ( V_92 -> V_57 . V_104 , 3 ) ;
V_2 -> V_116 = F_78 ( V_92 -> V_57 . V_104 , 4 ) ;
}
if ( ! V_2 -> V_112 || ! V_2 -> V_113 || ! V_2 -> V_114 ||
! V_2 -> V_115 || ! V_2 -> V_116 ) {
F_5 ( V_39
L_40 , V_11 ) ;
V_93 = - V_105 ;
goto V_117;
}
F_79 ( & V_2 -> V_28 ) ;
F_79 ( & V_2 -> V_13 ) ;
F_80 ( & V_2 -> V_6 ) ;
F_81 ( & V_2 -> V_118 ) ;
F_82 ( & V_2 -> V_118 , & V_2 -> V_14 , F_59 ,
V_119 ) ;
F_65 ( V_2 ) ;
V_77 = ( V_2 -> V_74 == 2 ) ? V_120 : V_121 ;
V_77 |= V_122 | V_123 | V_124 ;
if ( F_72 ( V_92 -> V_57 . V_104 , L_41 ) )
V_77 &= ~ ( V_125 | V_126 ) ;
F_14 ( V_2 , V_29 , V_77 ) ;
F_13 ( V_2 -> V_20 <= 0 || V_2 -> V_20 > 32 ) ;
F_13 ( V_2 -> V_17 <= 0 || V_2 -> V_17 > 32 ) ;
V_94 = sizeof( struct V_127 ) *
( V_21 * V_2 -> V_20 +
V_22 * V_2 -> V_17 ) ;
V_2 -> V_128 = F_83 ( & V_92 -> V_57 , V_94 , & V_2 -> V_129 ,
V_102 ) ;
if ( V_2 -> V_128 == NULL ) {
V_93 = - V_103 ;
goto V_117;
}
for ( V_73 = 0 ; V_73 < V_2 -> V_20 ; ++ V_73 )
F_14 ( V_2 , F_68 ( V_73 ) , V_2 -> V_129 +
sizeof( struct V_127 ) *
F_16 ( V_2 , V_73 ) ) ;
for ( V_73 = 0 ; V_73 < V_2 -> V_17 ; ++ V_73 )
F_14 ( V_2 , F_69 ( V_73 ) , V_2 -> V_129 +
sizeof( struct V_127 ) *
F_17 ( V_2 , V_73 ) ) ;
if ( F_42 ( V_2 , V_111 ) ) {
V_98 = V_130 ;
V_99 = V_100 = V_101 = F_50 ;
} else {
V_98 = 0 ;
V_99 = F_32 ;
V_100 = F_46 ;
V_101 = F_47 ;
}
V_93 = F_84 ( V_2 -> V_114 , V_99 , V_98 , L_42 , V_2 ) ;
if ( V_93 )
goto V_131;
V_93 = F_84 ( V_2 -> V_115 , V_100 , V_98 , L_43 , V_2 ) ;
if ( V_93 )
goto V_132;
V_93 = F_84 ( V_2 -> V_112 , F_40 , 0 , L_44 , V_2 ) ;
if ( V_93 )
goto V_133;
V_93 = F_84 ( V_2 -> V_116 , V_101 , V_98 , L_45 , V_2 ) ;
if ( V_93 )
goto V_134;
V_93 = F_84 ( V_2 -> V_113 , F_45 , 0 , L_46 , V_2 ) ;
if ( V_93 )
goto V_135;
F_14 ( V_2 , V_79 , V_136 ) ;
F_29 ( V_2 ) ;
F_5 ( V_137
L_47 ,
V_2 -> V_74 , V_92 -> V_57 . V_104 ,
V_2 -> V_20 , V_2 -> V_17 ) ;
F_85 () ;
F_86 ( V_92 , V_2 ) ;
return 0 ;
V_135:
F_87 ( V_2 -> V_116 , V_2 ) ;
V_134:
F_87 ( V_2 -> V_112 , V_2 ) ;
V_133:
F_87 ( V_2 -> V_115 , V_2 ) ;
V_132:
F_87 ( V_2 -> V_114 , V_2 ) ;
V_131:
F_88 ( & V_92 -> V_57 , V_94 , V_2 -> V_128 , V_2 -> V_129 ) ;
V_117:
F_89 ( V_2 -> V_107 , 0x100 ) ;
V_106:
F_90 ( V_2 ) ;
return V_93 ;
}
static int F_91 ( struct V_91 * V_92 )
{
struct V_1 * V_2 = F_92 ( V_92 ) ;
F_3 ( V_2 , L_48 V_7 ) ;
F_11 ( & V_2 -> V_14 ) ;
if ( ! F_6 ( & V_2 -> V_13 ) )
F_93 ( 1 , V_138
L_49 ,
V_2 -> V_11 ) ;
F_87 ( V_2 -> V_114 , V_2 ) ;
F_87 ( V_2 -> V_115 , V_2 ) ;
F_87 ( V_2 -> V_112 , V_2 ) ;
F_87 ( V_2 -> V_116 , V_2 ) ;
F_87 ( V_2 -> V_113 , V_2 ) ;
F_65 ( V_2 ) ;
F_88 ( & V_92 -> V_57 ,
sizeof( struct V_127 ) *
( V_21 * V_2 -> V_20 +
V_22 * V_2 -> V_17 ) , V_2 -> V_128 ,
V_2 -> V_129 ) ;
F_90 ( V_2 ) ;
return 0 ;
}
int T_4 F_94 ( void )
{
return F_95 ( & V_139 ) ;
}
void F_96 ( void )
{
F_97 ( & V_139 ) ;
}
