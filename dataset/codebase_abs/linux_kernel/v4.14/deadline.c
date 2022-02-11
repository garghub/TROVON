static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static inline struct V_5 * F_3 ( struct V_6 * V_6 )
{
return F_2 ( V_6 , struct V_5 , V_4 ) ;
}
static inline struct V_6 * F_4 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_5 * V_5 = F_5 ( V_7 ) ;
return & V_5 -> V_4 ;
}
static inline int F_6 ( struct V_2 * V_3 )
{
return ! F_7 ( & V_3 -> V_8 ) ;
}
static inline struct V_9 * F_8 ( int V_10 )
{
F_9 ( ! F_10 () ,
L_1 ) ;
return & F_11 ( V_10 ) -> V_11 -> V_9 ;
}
static inline int F_12 ( int V_10 )
{
struct V_12 * V_11 = F_11 ( V_10 ) -> V_11 ;
int V_13 = 0 ;
F_9 ( ! F_10 () ,
L_1 ) ;
F_13 (i, rd->span, cpu_active_mask)
V_13 ++ ;
return V_13 ;
}
static inline struct V_9 * F_8 ( int V_10 )
{
return & F_11 ( V_10 ) -> V_4 . V_9 ;
}
static inline int F_12 ( int V_10 )
{
return 1 ;
}
static inline
void F_14 ( T_1 V_9 , struct V_6 * V_6 )
{
T_1 V_14 = V_6 -> V_15 ;
F_15 ( & ( F_3 ( V_6 ) ) -> V_16 ) ;
V_6 -> V_15 += V_9 ;
F_16 ( V_6 -> V_15 < V_14 ) ;
F_16 ( V_6 -> V_15 > V_6 -> V_17 ) ;
}
static inline
void F_17 ( T_1 V_9 , struct V_6 * V_6 )
{
T_1 V_14 = V_6 -> V_15 ;
F_15 ( & ( F_3 ( V_6 ) ) -> V_16 ) ;
V_6 -> V_15 -= V_9 ;
F_16 ( V_6 -> V_15 > V_14 ) ;
if ( V_6 -> V_15 > V_14 )
V_6 -> V_15 = 0 ;
}
static inline
void F_18 ( T_1 V_9 , struct V_6 * V_6 )
{
T_1 V_14 = V_6 -> V_17 ;
F_15 ( & ( F_3 ( V_6 ) ) -> V_16 ) ;
V_6 -> V_17 += V_9 ;
F_16 ( V_6 -> V_17 < V_14 ) ;
}
static inline
void F_19 ( T_1 V_9 , struct V_6 * V_6 )
{
T_1 V_14 = V_6 -> V_17 ;
F_15 ( & ( F_3 ( V_6 ) ) -> V_16 ) ;
V_6 -> V_17 -= V_9 ;
F_16 ( V_6 -> V_17 > V_14 ) ;
if ( V_6 -> V_17 > V_14 )
V_6 -> V_17 = 0 ;
F_16 ( V_6 -> V_15 > V_6 -> V_17 ) ;
}
void F_20 ( struct V_1 * V_7 , T_1 V_18 )
{
struct V_5 * V_5 ;
if ( F_21 ( V_7 ) )
return;
V_5 = F_5 ( V_7 ) ;
if ( V_7 -> V_4 . V_19 ) {
F_17 ( V_7 -> V_4 . V_9 , & V_5 -> V_4 ) ;
V_7 -> V_4 . V_19 = 0 ;
if ( F_22 ( & V_7 -> V_4 . V_20 ) == 1 )
F_23 ( V_7 ) ;
}
F_19 ( V_7 -> V_4 . V_9 , & V_5 -> V_4 ) ;
F_18 ( V_18 , & V_5 -> V_4 ) ;
}
static void F_24 ( struct V_1 * V_7 )
{
struct V_2 * V_3 = & V_7 -> V_4 ;
struct V_21 * V_22 = & V_3 -> V_20 ;
struct V_6 * V_6 = F_4 ( V_3 ) ;
struct V_5 * V_5 = F_3 ( V_6 ) ;
T_2 V_23 ;
if ( V_3 -> V_24 == 0 )
return;
F_25 ( F_26 ( & V_3 -> V_20 ) ) ;
F_25 ( V_3 -> V_19 ) ;
V_23 = V_3 -> V_25 -
F_27 ( ( V_3 -> V_26 * V_3 -> V_27 ) ,
V_3 -> V_24 ) ;
V_23 -= F_28 ( V_5 ) ;
if ( V_23 < 0 ) {
if ( F_29 ( V_7 ) )
F_17 ( V_3 -> V_9 , V_6 ) ;
if ( ! F_29 ( V_7 ) || V_7 -> V_28 == V_29 ) {
struct V_9 * V_30 = F_8 ( F_30 ( V_7 ) ) ;
if ( V_7 -> V_28 == V_29 )
F_19 ( V_7 -> V_4 . V_9 , & V_5 -> V_4 ) ;
F_31 ( & V_30 -> V_16 ) ;
F_32 ( V_30 , V_7 -> V_4 . V_9 , F_12 ( F_30 ( V_7 ) ) ) ;
F_33 ( V_7 ) ;
F_34 ( & V_30 -> V_16 ) ;
}
return;
}
V_3 -> V_19 = 1 ;
F_35 ( V_7 ) ;
F_36 ( V_22 , F_37 ( V_23 ) , V_31 ) ;
}
static void F_38 ( struct V_2 * V_3 , int V_32 )
{
struct V_6 * V_6 = F_4 ( V_3 ) ;
if ( V_3 -> V_24 == 0 )
return;
if ( V_32 & V_33 )
F_18 ( V_3 -> V_9 , V_6 ) ;
if ( V_3 -> V_19 ) {
V_3 -> V_19 = 0 ;
if ( F_22 ( & V_3 -> V_20 ) == 1 )
F_23 ( F_1 ( V_3 ) ) ;
} else {
F_14 ( V_3 -> V_9 , V_6 ) ;
}
}
static inline int F_39 ( struct V_1 * V_7 , struct V_6 * V_6 )
{
struct V_2 * V_3 = & V_7 -> V_4 ;
return V_6 -> V_34 . V_35 == & V_3 -> V_8 ;
}
void F_40 ( struct V_36 * V_30 , T_1 V_37 , T_1 V_26 )
{
F_41 ( & V_30 -> V_38 ) ;
V_30 -> V_27 = V_37 ;
V_30 -> V_24 = V_26 ;
}
void F_42 ( struct V_9 * V_30 )
{
F_41 ( & V_30 -> V_16 ) ;
F_31 ( & V_39 . V_38 ) ;
if ( F_43 () == V_40 )
V_30 -> V_41 = - 1 ;
else
V_30 -> V_41 = F_44 ( F_45 () , F_43 () ) ;
F_34 ( & V_39 . V_38 ) ;
V_30 -> V_42 = 0 ;
}
void F_46 ( struct V_6 * V_6 )
{
V_6 -> V_34 = V_43 ;
#ifdef F_47
V_6 -> V_44 . V_45 = V_6 -> V_44 . V_46 = 0 ;
V_6 -> V_47 = 0 ;
V_6 -> V_48 = 0 ;
V_6 -> V_49 = V_43 ;
#else
F_42 ( & V_6 -> V_9 ) ;
#endif
V_6 -> V_15 = 0 ;
V_6 -> V_17 = 0 ;
F_48 ( V_6 ) ;
}
static inline int F_49 ( struct V_5 * V_5 )
{
return F_50 ( & V_5 -> V_11 -> V_50 ) ;
}
static inline void F_51 ( struct V_5 * V_5 )
{
if ( ! V_5 -> V_51 )
return;
F_52 ( V_5 -> V_52 , V_5 -> V_11 -> V_53 ) ;
F_53 () ;
F_54 ( & V_5 -> V_11 -> V_50 ) ;
}
static inline void F_55 ( struct V_5 * V_5 )
{
if ( ! V_5 -> V_51 )
return;
F_56 ( & V_5 -> V_11 -> V_50 ) ;
F_57 ( V_5 -> V_52 , V_5 -> V_11 -> V_53 ) ;
}
static void F_58 ( struct V_6 * V_6 )
{
if ( V_6 -> V_47 && V_6 -> V_54 > 1 ) {
if ( ! V_6 -> V_48 ) {
F_51 ( F_3 ( V_6 ) ) ;
V_6 -> V_48 = 1 ;
}
} else if ( V_6 -> V_48 ) {
F_55 ( F_3 ( V_6 ) ) ;
V_6 -> V_48 = 0 ;
}
}
static void F_59 ( struct V_2 * V_3 , struct V_6 * V_6 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
if ( V_7 -> V_55 > 1 )
V_6 -> V_47 ++ ;
F_58 ( V_6 ) ;
}
static void F_60 ( struct V_2 * V_3 , struct V_6 * V_6 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
if ( V_7 -> V_55 > 1 )
V_6 -> V_47 -- ;
F_58 ( V_6 ) ;
}
static void F_61 ( struct V_5 * V_5 , struct V_1 * V_7 )
{
struct V_6 * V_6 = & V_5 -> V_4 ;
struct V_8 * * V_56 = & V_6 -> V_49 . V_57 . V_8 ;
struct V_8 * V_58 = NULL ;
struct V_1 * V_59 ;
bool V_60 = true ;
F_62 ( ! F_7 ( & V_7 -> V_61 ) ) ;
while ( * V_56 ) {
V_58 = * V_56 ;
V_59 = F_63 ( V_58 , struct V_1 ,
V_61 ) ;
if ( F_64 ( & V_7 -> V_4 , & V_59 -> V_4 ) )
V_56 = & V_58 -> V_62 ;
else {
V_56 = & V_58 -> V_63 ;
V_60 = false ;
}
}
if ( V_60 )
V_6 -> V_44 . V_46 = V_7 -> V_4 . V_25 ;
F_65 ( & V_7 -> V_61 , V_58 , V_56 ) ;
F_66 ( & V_7 -> V_61 ,
& V_6 -> V_49 , V_60 ) ;
}
static void F_67 ( struct V_5 * V_5 , struct V_1 * V_7 )
{
struct V_6 * V_6 = & V_5 -> V_4 ;
if ( F_7 ( & V_7 -> V_61 ) )
return;
if ( V_6 -> V_49 . V_35 == & V_7 -> V_61 ) {
struct V_8 * V_64 ;
V_64 = F_68 ( & V_7 -> V_61 ) ;
if ( V_64 ) {
V_6 -> V_44 . V_46 = F_63 ( V_64 ,
struct V_1 , V_61 ) -> V_4 . V_25 ;
}
}
F_69 ( & V_7 -> V_61 , & V_6 -> V_49 ) ;
F_70 ( & V_7 -> V_61 ) ;
}
static inline int F_71 ( struct V_5 * V_5 )
{
return ! F_72 ( & V_5 -> V_4 . V_49 . V_57 ) ;
}
static inline bool F_73 ( struct V_5 * V_5 , struct V_1 * V_65 )
{
return F_29 ( V_65 ) ;
}
static inline void F_74 ( struct V_5 * V_5 )
{
if ( ! F_71 ( V_5 ) )
return;
F_75 ( V_5 , & F_76 ( V_66 , V_5 -> V_52 ) , V_67 ) ;
}
static inline void F_77 ( struct V_5 * V_5 )
{
F_75 ( V_5 , & F_76 ( V_68 , V_5 -> V_52 ) , V_69 ) ;
}
static struct V_5 * F_78 ( struct V_5 * V_5 , struct V_1 * V_7 )
{
struct V_5 * V_70 = NULL ;
V_70 = F_79 ( V_7 , V_5 ) ;
if ( ! V_70 ) {
int V_52 ;
V_52 = F_80 ( V_71 , & V_7 -> V_72 ) ;
if ( V_52 >= V_73 ) {
F_62 ( F_81 () ) ;
V_52 = F_82 ( V_71 ) ;
}
V_70 = F_11 ( V_52 ) ;
F_83 ( V_5 , V_70 ) ;
}
F_84 ( V_7 , V_70 -> V_52 ) ;
F_85 ( V_70 , V_5 ) ;
return V_70 ;
}
static inline
void F_61 ( struct V_5 * V_5 , struct V_1 * V_7 )
{
}
static inline
void F_67 ( struct V_5 * V_5 , struct V_1 * V_7 )
{
}
static inline
void F_59 ( struct V_2 * V_3 , struct V_6 * V_6 )
{
}
static inline
void F_60 ( struct V_2 * V_3 , struct V_6 * V_6 )
{
}
static inline bool F_73 ( struct V_5 * V_5 , struct V_1 * V_65 )
{
return false ;
}
static inline void V_69 ( struct V_5 * V_5 )
{
}
static inline void F_74 ( struct V_5 * V_5 )
{
}
static inline void F_77 ( struct V_5 * V_5 )
{
}
static inline void F_86 ( struct V_2 * V_3 )
{
struct V_6 * V_6 = F_4 ( V_3 ) ;
struct V_5 * V_5 = F_3 ( V_6 ) ;
F_25 ( V_3 -> V_74 ) ;
F_25 ( F_87 ( F_28 ( V_5 ) , V_3 -> V_25 ) ) ;
if ( V_3 -> V_75 )
return;
V_3 -> V_25 = F_28 ( V_5 ) + V_3 -> V_76 ;
V_3 -> V_26 = V_3 -> V_24 ;
}
static void F_88 ( struct V_2 * V_3 ,
struct V_2 * V_77 )
{
struct V_6 * V_6 = F_4 ( V_3 ) ;
struct V_5 * V_5 = F_3 ( V_6 ) ;
F_62 ( V_77 -> V_24 <= 0 ) ;
if ( V_3 -> V_76 == 0 ) {
V_3 -> V_25 = F_28 ( V_5 ) + V_77 -> V_76 ;
V_3 -> V_26 = V_77 -> V_24 ;
}
if ( V_3 -> V_78 && V_3 -> V_26 > 0 )
V_3 -> V_26 = 0 ;
while ( V_3 -> V_26 <= 0 ) {
V_3 -> V_25 += V_77 -> V_27 ;
V_3 -> V_26 += V_77 -> V_24 ;
}
if ( F_87 ( V_3 -> V_25 , F_28 ( V_5 ) ) ) {
F_89 ( L_2 ) ;
V_3 -> V_25 = F_28 ( V_5 ) + V_77 -> V_76 ;
V_3 -> V_26 = V_77 -> V_24 ;
}
if ( V_3 -> V_78 )
V_3 -> V_78 = 0 ;
if ( V_3 -> V_75 )
V_3 -> V_75 = 0 ;
}
static bool F_90 ( struct V_2 * V_3 ,
struct V_2 * V_77 , T_1 V_79 )
{
T_1 V_80 , V_81 ;
V_80 = ( V_77 -> V_76 >> V_82 ) * ( V_3 -> V_26 >> V_82 ) ;
V_81 = ( ( V_3 -> V_25 - V_79 ) >> V_82 ) *
( V_77 -> V_24 >> V_82 ) ;
return F_87 ( V_81 , V_80 ) ;
}
static void
F_91 ( struct V_2 * V_3 , struct V_5 * V_5 )
{
T_1 V_83 = V_3 -> V_25 - F_28 ( V_5 ) ;
F_25 ( F_87 ( V_3 -> V_25 , F_28 ( V_5 ) ) ) ;
V_3 -> V_26 = ( V_3 -> V_84 * V_83 ) >> V_85 ;
}
static inline bool F_92 ( struct V_2 * V_3 )
{
return V_3 -> V_76 == V_3 -> V_27 ;
}
static void F_93 ( struct V_2 * V_3 ,
struct V_2 * V_77 )
{
struct V_6 * V_6 = F_4 ( V_3 ) ;
struct V_5 * V_5 = F_3 ( V_6 ) ;
if ( F_87 ( V_3 -> V_25 , F_28 ( V_5 ) ) ||
F_90 ( V_3 , V_77 , F_28 ( V_5 ) ) ) {
if ( F_94 ( ! F_92 ( V_3 ) &&
! F_87 ( V_3 -> V_25 , F_28 ( V_5 ) ) &&
! V_3 -> V_74 ) ) {
F_91 ( V_3 , V_5 ) ;
return;
}
V_3 -> V_25 = F_28 ( V_5 ) + V_77 -> V_76 ;
V_3 -> V_26 = V_77 -> V_24 ;
}
}
static inline T_1 F_95 ( struct V_2 * V_3 )
{
return V_3 -> V_25 - V_3 -> V_76 + V_3 -> V_27 ;
}
static int F_96 ( struct V_1 * V_7 )
{
struct V_2 * V_3 = & V_7 -> V_4 ;
struct V_21 * V_22 = & V_3 -> V_86 ;
struct V_5 * V_5 = F_5 ( V_7 ) ;
T_3 V_87 , V_88 ;
T_2 V_89 ;
F_15 ( & V_5 -> V_16 ) ;
V_88 = F_37 ( F_95 ( V_3 ) ) ;
V_87 = F_97 ( V_22 ) ;
V_89 = F_98 ( V_87 ) - F_28 ( V_5 ) ;
V_88 = F_99 ( V_88 , V_89 ) ;
if ( F_100 ( V_88 , V_87 ) < 0 )
return 0 ;
if ( ! F_101 ( V_22 ) ) {
F_35 ( V_7 ) ;
F_36 ( V_22 , V_88 , V_90 ) ;
}
return 1 ;
}
static enum V_91 F_102 ( struct V_21 * V_22 )
{
struct V_2 * V_3 = F_2 ( V_22 ,
struct V_2 ,
V_86 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_92 V_93 ;
struct V_5 * V_5 ;
V_5 = F_103 ( V_7 , & V_93 ) ;
if ( ! F_29 ( V_7 ) )
goto V_94;
if ( V_3 -> V_74 )
goto V_94;
if ( ! V_3 -> V_75 )
goto V_94;
F_104 () ;
F_105 ( V_5 ) ;
if ( ! F_21 ( V_7 ) ) {
F_88 ( V_3 , V_3 ) ;
goto V_94;
}
#ifdef F_47
if ( F_94 ( ! V_5 -> V_51 ) ) {
F_106 ( & V_5 -> V_16 , V_93 . V_95 ) ;
V_5 = F_78 ( V_5 , V_7 ) ;
V_93 . V_95 = F_107 ( & V_5 -> V_16 ) ;
F_105 ( V_5 ) ;
}
#endif
F_108 ( V_5 , V_7 , V_96 ) ;
if ( F_29 ( V_5 -> V_45 ) )
F_109 ( V_5 , V_7 , 0 ) ;
else
F_110 ( V_5 ) ;
#ifdef F_47
if ( F_71 ( V_5 ) ) {
F_111 ( V_5 , & V_93 ) ;
F_112 ( V_5 ) ;
F_113 ( V_5 , & V_93 ) ;
}
#endif
V_94:
F_114 ( V_5 , V_7 , & V_93 ) ;
F_23 ( V_7 ) ;
return V_97 ;
}
void F_115 ( struct V_2 * V_3 )
{
struct V_21 * V_22 = & V_3 -> V_86 ;
F_116 ( V_22 , V_98 , V_31 ) ;
V_22 -> V_99 = F_102 ;
}
static inline void F_117 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_5 * V_5 = F_3 ( F_4 ( V_3 ) ) ;
if ( F_87 ( V_3 -> V_25 , F_28 ( V_5 ) ) &&
F_87 ( F_28 ( V_5 ) , F_95 ( V_3 ) ) ) {
if ( F_94 ( V_3 -> V_74 || ! F_96 ( V_7 ) ) )
return;
V_3 -> V_75 = 1 ;
if ( V_3 -> V_26 > 0 )
V_3 -> V_26 = 0 ;
}
}
static
int F_118 ( struct V_2 * V_3 )
{
return ( V_3 -> V_26 <= 0 ) ;
}
T_1 F_119 ( T_1 V_89 , struct V_5 * V_5 , struct V_2 * V_3 )
{
T_1 V_100 = V_5 -> V_4 . V_17 - V_5 -> V_4 . V_15 ;
T_1 V_101 ;
T_1 V_102 = ( V_3 -> V_9 * V_5 -> V_4 . V_103 ) >> V_104 ;
if ( V_100 + V_5 -> V_4 . V_105 > V_106 - V_102 )
V_101 = V_102 ;
else
V_101 = V_106 - V_100 - V_5 -> V_4 . V_105 ;
return ( V_89 * V_101 ) >> V_85 ;
}
static void F_120 ( struct V_5 * V_5 )
{
struct V_1 * V_45 = V_5 -> V_45 ;
struct V_2 * V_3 = & V_45 -> V_4 ;
T_1 V_107 ;
if ( ! F_29 ( V_45 ) || ! F_6 ( V_3 ) )
return;
V_107 = F_121 ( V_5 ) - V_45 -> V_108 . V_109 ;
if ( F_94 ( ( T_2 ) V_107 <= 0 ) ) {
if ( F_94 ( V_3 -> V_78 ) )
goto V_110;
return;
}
F_122 ( V_5 , V_111 ) ;
F_123 ( V_45 -> V_108 . V_112 . V_113 ,
F_124 ( V_45 -> V_108 . V_112 . V_113 , V_107 ) ) ;
V_45 -> V_108 . V_114 += V_107 ;
F_125 ( V_45 , V_107 ) ;
V_45 -> V_108 . V_109 = F_121 ( V_5 ) ;
F_126 ( V_45 , V_107 ) ;
F_127 ( V_5 , V_107 ) ;
if ( F_94 ( V_3 -> V_32 & V_115 ) )
V_107 = F_119 ( V_107 , V_5 , & V_45 -> V_4 ) ;
V_3 -> V_26 -= V_107 ;
V_110:
if ( F_118 ( V_3 ) || V_3 -> V_78 ) {
V_3 -> V_75 = 1 ;
F_128 ( V_5 , V_45 , 0 ) ;
if ( F_94 ( V_3 -> V_74 || ! F_96 ( V_45 ) ) )
F_108 ( V_5 , V_45 , V_96 ) ;
if ( ! F_39 ( V_45 , & V_5 -> V_4 ) )
F_110 ( V_5 ) ;
}
if ( F_129 () ) {
struct V_116 * V_116 = & V_5 -> V_117 ;
F_31 ( & V_116 -> V_118 ) ;
if ( F_130 ( V_116 ) )
V_116 -> V_119 += V_107 ;
F_34 ( & V_116 -> V_118 ) ;
}
}
static enum V_91 F_131 ( struct V_21 * V_22 )
{
struct V_2 * V_3 = F_2 ( V_22 ,
struct V_2 ,
V_20 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_92 V_93 ;
struct V_5 * V_5 ;
V_5 = F_103 ( V_7 , & V_93 ) ;
if ( ! F_29 ( V_7 ) || V_7 -> V_28 == V_29 ) {
struct V_9 * V_30 = F_8 ( F_30 ( V_7 ) ) ;
if ( V_7 -> V_28 == V_29 && V_3 -> V_19 ) {
F_17 ( V_7 -> V_4 . V_9 , F_4 ( & V_7 -> V_4 ) ) ;
F_19 ( V_7 -> V_4 . V_9 , F_4 ( & V_7 -> V_4 ) ) ;
V_3 -> V_19 = 0 ;
}
F_31 ( & V_30 -> V_16 ) ;
F_32 ( V_30 , V_7 -> V_4 . V_9 , F_12 ( F_30 ( V_7 ) ) ) ;
F_34 ( & V_30 -> V_16 ) ;
F_33 ( V_7 ) ;
goto V_94;
}
if ( V_3 -> V_19 == 0 )
goto V_94;
F_104 () ;
F_105 ( V_5 ) ;
F_17 ( V_3 -> V_9 , & V_5 -> V_4 ) ;
V_3 -> V_19 = 0 ;
V_94:
F_114 ( V_5 , V_7 , & V_93 ) ;
F_23 ( V_7 ) ;
return V_97 ;
}
void F_132 ( struct V_2 * V_3 )
{
struct V_21 * V_22 = & V_3 -> V_20 ;
F_116 ( V_22 , V_98 , V_31 ) ;
V_22 -> V_99 = F_131 ;
}
static void F_133 ( struct V_6 * V_6 , T_1 V_25 )
{
struct V_5 * V_5 = F_3 ( V_6 ) ;
if ( V_6 -> V_44 . V_45 == 0 ||
F_87 ( V_25 , V_6 -> V_44 . V_45 ) ) {
V_6 -> V_44 . V_45 = V_25 ;
F_134 ( & V_5 -> V_11 -> V_120 , V_5 -> V_52 , V_25 ) ;
}
}
static void F_135 ( struct V_6 * V_6 , T_1 V_25 )
{
struct V_5 * V_5 = F_3 ( V_6 ) ;
if ( ! V_6 -> V_54 ) {
V_6 -> V_44 . V_45 = 0 ;
V_6 -> V_44 . V_46 = 0 ;
F_136 ( & V_5 -> V_11 -> V_120 , V_5 -> V_52 ) ;
} else {
struct V_8 * V_60 = V_6 -> V_34 . V_35 ;
struct V_2 * V_59 ;
V_59 = F_63 ( V_60 , struct V_2 , V_8 ) ;
V_6 -> V_44 . V_45 = V_59 -> V_25 ;
F_134 ( & V_5 -> V_11 -> V_120 , V_5 -> V_52 , V_59 -> V_25 ) ;
}
}
static inline void F_133 ( struct V_6 * V_6 , T_1 V_25 ) {}
static inline void F_135 ( struct V_6 * V_6 , T_1 V_25 ) {}
static inline
void F_137 ( struct V_2 * V_3 , struct V_6 * V_6 )
{
int V_121 = F_1 ( V_3 ) -> V_121 ;
T_1 V_25 = V_3 -> V_25 ;
F_25 ( ! F_138 ( V_121 ) ) ;
V_6 -> V_54 ++ ;
F_139 ( F_3 ( V_6 ) , 1 ) ;
F_133 ( V_6 , V_25 ) ;
F_59 ( V_3 , V_6 ) ;
}
static inline
void F_140 ( struct V_2 * V_3 , struct V_6 * V_6 )
{
int V_121 = F_1 ( V_3 ) -> V_121 ;
F_25 ( ! F_138 ( V_121 ) ) ;
F_25 ( ! V_6 -> V_54 ) ;
V_6 -> V_54 -- ;
F_141 ( F_3 ( V_6 ) , 1 ) ;
F_135 ( V_6 , V_3 -> V_25 ) ;
F_60 ( V_3 , V_6 ) ;
}
static void F_142 ( struct V_2 * V_3 )
{
struct V_6 * V_6 = F_4 ( V_3 ) ;
struct V_8 * * V_56 = & V_6 -> V_34 . V_57 . V_8 ;
struct V_8 * V_58 = NULL ;
struct V_2 * V_59 ;
int V_60 = 1 ;
F_62 ( ! F_7 ( & V_3 -> V_8 ) ) ;
while ( * V_56 ) {
V_58 = * V_56 ;
V_59 = F_63 ( V_58 , struct V_2 , V_8 ) ;
if ( F_87 ( V_3 -> V_25 , V_59 -> V_25 ) )
V_56 = & V_58 -> V_62 ;
else {
V_56 = & V_58 -> V_63 ;
V_60 = 0 ;
}
}
F_65 ( & V_3 -> V_8 , V_58 , V_56 ) ;
F_66 ( & V_3 -> V_8 , & V_6 -> V_34 , V_60 ) ;
F_137 ( V_3 , V_6 ) ;
}
static void F_143 ( struct V_2 * V_3 )
{
struct V_6 * V_6 = F_4 ( V_3 ) ;
if ( F_7 ( & V_3 -> V_8 ) )
return;
F_69 ( & V_3 -> V_8 , & V_6 -> V_34 ) ;
F_70 ( & V_3 -> V_8 ) ;
F_140 ( V_3 , V_6 ) ;
}
static void
F_144 ( struct V_2 * V_3 ,
struct V_2 * V_77 , int V_32 )
{
F_62 ( F_6 ( V_3 ) ) ;
if ( V_32 & V_122 ) {
F_38 ( V_3 , V_32 ) ;
F_93 ( V_3 , V_77 ) ;
} else if ( V_32 & V_96 ) {
F_88 ( V_3 , V_77 ) ;
}
F_142 ( V_3 ) ;
}
static void F_145 ( struct V_2 * V_3 )
{
F_143 ( V_3 ) ;
}
static void F_108 ( struct V_5 * V_5 , struct V_1 * V_7 , int V_32 )
{
struct V_1 * V_123 = F_146 ( V_7 ) ;
struct V_2 * V_77 = & V_7 -> V_4 ;
if ( V_123 && F_138 ( V_123 -> V_124 ) && V_7 -> V_4 . V_74 ) {
V_77 = & V_123 -> V_4 ;
} else if ( ! F_138 ( V_7 -> V_124 ) ) {
F_62 ( ! V_7 -> V_4 . V_74 || V_32 != V_96 ) ;
return;
}
if ( ! V_7 -> V_4 . V_75 && ! F_92 ( & V_7 -> V_4 ) )
F_117 ( & V_7 -> V_4 ) ;
if ( V_7 -> V_125 == V_126 || V_32 & V_127 ) {
F_18 ( V_7 -> V_4 . V_9 , & V_5 -> V_4 ) ;
F_14 ( V_7 -> V_4 . V_9 , & V_5 -> V_4 ) ;
}
if ( V_7 -> V_4 . V_75 && ! ( V_32 & V_96 ) ) {
if ( V_32 & V_122 )
F_38 ( & V_7 -> V_4 , V_32 ) ;
return;
}
F_144 ( & V_7 -> V_4 , V_77 , V_32 ) ;
if ( ! F_147 ( V_5 , V_7 ) && V_7 -> V_55 > 1 )
F_61 ( V_5 , V_7 ) ;
}
static void F_128 ( struct V_5 * V_5 , struct V_1 * V_7 , int V_32 )
{
F_145 ( & V_7 -> V_4 ) ;
F_67 ( V_5 , V_7 ) ;
}
static void F_148 ( struct V_5 * V_5 , struct V_1 * V_7 , int V_32 )
{
F_120 ( V_5 ) ;
F_128 ( V_5 , V_7 , V_32 ) ;
if ( V_7 -> V_125 == V_126 || V_32 & V_128 ) {
F_17 ( V_7 -> V_4 . V_9 , & V_5 -> V_4 ) ;
F_19 ( V_7 -> V_4 . V_9 , & V_5 -> V_4 ) ;
}
if ( V_32 & V_129 )
F_24 ( V_7 ) ;
}
static void F_149 ( struct V_5 * V_5 )
{
V_5 -> V_45 -> V_4 . V_78 = 1 ;
F_105 ( V_5 ) ;
F_120 ( V_5 ) ;
F_150 ( V_5 , true ) ;
}
static int
F_151 ( struct V_1 * V_7 , int V_52 , int V_130 , int V_32 )
{
struct V_1 * V_45 ;
struct V_5 * V_5 ;
if ( V_130 != V_131 )
goto V_132;
V_5 = F_11 ( V_52 ) ;
F_152 () ;
V_45 = F_153 ( V_5 -> V_45 ) ;
if ( F_94 ( F_29 ( V_45 ) ) &&
( V_45 -> V_55 < 2 ||
! F_64 ( & V_7 -> V_4 , & V_45 -> V_4 ) ) &&
( V_7 -> V_55 > 1 ) ) {
int V_133 = F_154 ( V_7 ) ;
if ( V_133 != - 1 &&
( F_87 ( V_7 -> V_4 . V_25 ,
F_11 ( V_133 ) -> V_4 . V_44 . V_45 ) ||
( F_11 ( V_133 ) -> V_4 . V_54 == 0 ) ) )
V_52 = V_133 ;
}
F_155 () ;
V_132:
return V_52 ;
}
static void F_156 ( struct V_1 * V_7 )
{
struct V_5 * V_5 ;
if ( V_7 -> V_28 != V_134 )
return;
V_5 = F_5 ( V_7 ) ;
F_31 ( & V_5 -> V_16 ) ;
if ( V_7 -> V_4 . V_19 ) {
F_17 ( V_7 -> V_4 . V_9 , & V_5 -> V_4 ) ;
V_7 -> V_4 . V_19 = 0 ;
if ( F_22 ( & V_7 -> V_4 . V_20 ) == 1 )
F_23 ( V_7 ) ;
}
F_19 ( V_7 -> V_4 . V_9 , & V_5 -> V_4 ) ;
F_34 ( & V_5 -> V_16 ) ;
}
static void F_157 ( struct V_5 * V_5 , struct V_1 * V_7 )
{
if ( V_5 -> V_45 -> V_55 == 1 ||
! F_158 ( & V_5 -> V_11 -> V_120 , V_5 -> V_45 , NULL ) )
return;
if ( V_7 -> V_55 != 1 &&
F_158 ( & V_5 -> V_11 -> V_120 , V_7 , NULL ) )
return;
F_110 ( V_5 ) ;
}
static void F_109 ( struct V_5 * V_5 , struct V_1 * V_7 ,
int V_32 )
{
if ( F_64 ( & V_7 -> V_4 , & V_5 -> V_45 -> V_4 ) ) {
F_110 ( V_5 ) ;
return;
}
#ifdef F_47
if ( ( V_7 -> V_4 . V_25 == V_5 -> V_45 -> V_4 . V_25 ) &&
! F_159 ( V_5 -> V_45 ) )
F_157 ( V_5 , V_7 ) ;
#endif
}
static void F_160 ( struct V_5 * V_5 , struct V_1 * V_7 )
{
F_161 ( V_5 , V_7 -> V_4 . V_26 ) ;
}
static void F_160 ( struct V_5 * V_5 , struct V_1 * V_7 )
{
}
static struct V_2 * F_162 ( struct V_5 * V_5 ,
struct V_6 * V_6 )
{
struct V_8 * V_80 = F_163 ( & V_6 -> V_34 ) ;
if ( ! V_80 )
return NULL ;
return F_63 ( V_80 , struct V_2 , V_8 ) ;
}
static struct V_1 *
F_164 ( struct V_5 * V_5 , struct V_1 * V_65 , struct V_92 * V_93 )
{
struct V_2 * V_3 ;
struct V_1 * V_7 ;
struct V_6 * V_6 ;
V_6 = & V_5 -> V_4 ;
if ( F_73 ( V_5 , V_65 ) ) {
F_111 ( V_5 , V_93 ) ;
V_69 ( V_5 ) ;
F_113 ( V_5 , V_93 ) ;
if ( V_5 -> V_135 && F_21 ( V_5 -> V_135 ) )
return V_136 ;
}
if ( V_65 -> V_137 == & V_138 )
F_120 ( V_5 ) ;
if ( F_94 ( ! V_6 -> V_54 ) )
return NULL ;
F_165 ( V_5 , V_65 ) ;
V_3 = F_162 ( V_5 , V_6 ) ;
F_62 ( ! V_3 ) ;
V_7 = F_1 ( V_3 ) ;
V_7 -> V_108 . V_109 = F_121 ( V_5 ) ;
F_67 ( V_5 , V_7 ) ;
if ( F_166 ( V_5 ) )
F_160 ( V_5 , V_7 ) ;
F_74 ( V_5 ) ;
return V_7 ;
}
static void F_167 ( struct V_5 * V_5 , struct V_1 * V_7 )
{
F_120 ( V_5 ) ;
if ( F_6 ( & V_7 -> V_4 ) && V_7 -> V_55 > 1 )
F_61 ( V_5 , V_7 ) ;
}
static void F_168 ( struct V_5 * V_5 , struct V_1 * V_7 , int V_139 )
{
F_120 ( V_5 ) ;
if ( F_166 ( V_5 ) && V_139 && V_7 -> V_4 . V_26 > 0 &&
F_39 ( V_7 , & V_5 -> V_4 ) )
F_160 ( V_5 , V_7 ) ;
}
static void F_169 ( struct V_1 * V_7 )
{
}
static void F_170 ( struct V_5 * V_5 )
{
struct V_1 * V_7 = V_5 -> V_45 ;
V_7 -> V_108 . V_109 = F_121 ( V_5 ) ;
F_67 ( V_5 , V_7 ) ;
}
static int F_171 ( struct V_5 * V_5 , struct V_1 * V_7 , int V_52 )
{
if ( ! F_172 ( V_5 , V_7 ) &&
F_173 ( V_52 , & V_7 -> V_72 ) )
return 1 ;
return 0 ;
}
static struct V_1 * F_174 ( struct V_5 * V_5 , int V_52 )
{
struct V_8 * V_64 = V_5 -> V_4 . V_49 . V_35 ;
struct V_1 * V_7 = NULL ;
if ( ! F_71 ( V_5 ) )
return NULL ;
V_64:
if ( V_64 ) {
V_7 = F_63 ( V_64 , struct V_1 , V_61 ) ;
if ( F_171 ( V_5 , V_7 , V_52 ) )
return V_7 ;
V_64 = F_68 ( V_64 ) ;
goto V_64;
}
return NULL ;
}
static int F_154 ( struct V_1 * V_140 )
{
struct V_141 * V_142 ;
struct V_143 * V_144 = F_175 ( V_145 ) ;
int V_146 = F_176 () ;
int V_52 = F_30 ( V_140 ) ;
if ( F_94 ( ! V_144 ) )
return - 1 ;
if ( V_140 -> V_55 == 1 )
return - 1 ;
if ( ! F_158 ( & F_5 ( V_140 ) -> V_11 -> V_120 , V_140 , V_144 ) )
return - 1 ;
if ( F_173 ( V_52 , V_144 ) )
return V_52 ;
if ( ! F_173 ( V_146 , V_144 ) )
V_146 = - 1 ;
F_152 () ;
F_177 (cpu, sd) {
if ( V_142 -> V_32 & V_147 ) {
int V_148 ;
if ( V_146 != - 1 &&
F_173 ( V_146 , F_178 ( V_142 ) ) ) {
F_155 () ;
return V_146 ;
}
V_148 = F_179 ( V_144 ,
F_178 ( V_142 ) ) ;
if ( V_148 < V_73 ) {
F_155 () ;
return V_148 ;
}
}
}
F_155 () ;
if ( V_146 != - 1 )
return V_146 ;
V_52 = F_82 ( V_144 ) ;
if ( V_52 < V_73 )
return V_52 ;
return - 1 ;
}
static struct V_5 * F_79 ( struct V_1 * V_140 , struct V_5 * V_5 )
{
struct V_5 * V_70 = NULL ;
int V_149 ;
int V_52 ;
for ( V_149 = 0 ; V_149 < V_150 ; V_149 ++ ) {
V_52 = F_154 ( V_140 ) ;
if ( ( V_52 == - 1 ) || ( V_52 == V_5 -> V_52 ) )
break;
V_70 = F_11 ( V_52 ) ;
if ( V_70 -> V_4 . V_54 &&
! F_87 ( V_140 -> V_4 . V_25 ,
V_70 -> V_4 . V_44 . V_45 ) ) {
V_70 = NULL ;
break;
}
if ( F_83 ( V_5 , V_70 ) ) {
if ( F_94 ( F_5 ( V_140 ) != V_5 ||
! F_173 ( V_70 -> V_52 , & V_140 -> V_72 ) ||
F_172 ( V_5 , V_140 ) ||
! F_29 ( V_140 ) ||
! F_21 ( V_140 ) ) ) {
F_85 ( V_5 , V_70 ) ;
V_70 = NULL ;
break;
}
}
if ( ! V_70 -> V_4 . V_54 ||
F_87 ( V_140 -> V_4 . V_25 ,
V_70 -> V_4 . V_44 . V_45 ) )
break;
F_85 ( V_5 , V_70 ) ;
V_70 = NULL ;
}
return V_70 ;
}
static struct V_1 * F_180 ( struct V_5 * V_5 )
{
struct V_1 * V_7 ;
if ( ! F_71 ( V_5 ) )
return NULL ;
V_7 = F_63 ( V_5 -> V_4 . V_49 . V_35 ,
struct V_1 , V_61 ) ;
F_62 ( V_5 -> V_52 != F_30 ( V_7 ) ) ;
F_62 ( F_147 ( V_5 , V_7 ) ) ;
F_62 ( V_7 -> V_55 <= 1 ) ;
F_62 ( ! F_21 ( V_7 ) ) ;
F_62 ( ! F_29 ( V_7 ) ) ;
return V_7 ;
}
static int F_112 ( struct V_5 * V_5 )
{
struct V_1 * V_151 ;
struct V_5 * V_70 ;
int V_152 = 0 ;
if ( ! V_5 -> V_4 . V_48 )
return 0 ;
V_151 = F_180 ( V_5 ) ;
if ( ! V_151 )
return 0 ;
V_153:
if ( F_94 ( V_151 == V_5 -> V_45 ) ) {
F_25 ( 1 ) ;
return 0 ;
}
if ( F_29 ( V_5 -> V_45 ) &&
F_87 ( V_151 -> V_4 . V_25 , V_5 -> V_45 -> V_4 . V_25 ) &&
V_5 -> V_45 -> V_55 > 1 ) {
F_110 ( V_5 ) ;
return 0 ;
}
F_35 ( V_151 ) ;
V_70 = F_79 ( V_151 , V_5 ) ;
if ( ! V_70 ) {
struct V_1 * V_140 ;
V_140 = F_180 ( V_5 ) ;
if ( V_140 == V_151 ) {
goto V_132;
}
if ( ! V_140 )
goto V_132;
F_23 ( V_151 ) ;
V_151 = V_140 ;
goto V_153;
}
F_181 ( V_5 , V_151 , 0 ) ;
F_17 ( V_151 -> V_4 . V_9 , & V_5 -> V_4 ) ;
F_19 ( V_151 -> V_4 . V_9 , & V_5 -> V_4 ) ;
F_84 ( V_151 , V_70 -> V_52 ) ;
F_18 ( V_151 -> V_4 . V_9 , & V_70 -> V_4 ) ;
F_14 ( V_151 -> V_4 . V_9 , & V_70 -> V_4 ) ;
F_182 ( V_70 , V_151 , 0 ) ;
V_152 = 1 ;
F_110 ( V_70 ) ;
F_85 ( V_5 , V_70 ) ;
V_132:
F_23 ( V_151 ) ;
return V_152 ;
}
static void V_67 ( struct V_5 * V_5 )
{
while ( F_112 ( V_5 ) )
;
}
static void V_69 ( struct V_5 * V_154 )
{
int V_146 = V_154 -> V_52 , V_52 ;
struct V_1 * V_7 ;
bool V_155 = false ;
struct V_5 * V_156 ;
T_1 V_157 = V_158 ;
if ( F_183 ( ! F_49 ( V_154 ) ) )
return;
F_184 () ;
F_185 (cpu, this_rq->rd->dlo_mask) {
if ( V_146 == V_52 )
continue;
V_156 = F_11 ( V_52 ) ;
if ( V_154 -> V_4 . V_54 &&
F_87 ( V_154 -> V_4 . V_44 . V_45 ,
V_156 -> V_4 . V_44 . V_46 ) )
continue;
F_83 ( V_154 , V_156 ) ;
if ( V_156 -> V_4 . V_54 <= 1 )
goto V_159;
V_7 = F_174 ( V_156 , V_146 ) ;
if ( V_7 && F_87 ( V_7 -> V_4 . V_25 , V_157 ) &&
( ! V_154 -> V_4 . V_54 ||
F_87 ( V_7 -> V_4 . V_25 ,
V_154 -> V_4 . V_44 . V_45 ) ) ) {
F_25 ( V_7 == V_156 -> V_45 ) ;
F_25 ( ! F_21 ( V_7 ) ) ;
if ( F_87 ( V_7 -> V_4 . V_25 ,
V_156 -> V_45 -> V_4 . V_25 ) )
goto V_159;
V_155 = true ;
F_181 ( V_156 , V_7 , 0 ) ;
F_17 ( V_7 -> V_4 . V_9 , & V_156 -> V_4 ) ;
F_19 ( V_7 -> V_4 . V_9 , & V_156 -> V_4 ) ;
F_84 ( V_7 , V_146 ) ;
F_18 ( V_7 -> V_4 . V_9 , & V_154 -> V_4 ) ;
F_14 ( V_7 -> V_4 . V_9 , & V_154 -> V_4 ) ;
F_182 ( V_154 , V_7 , 0 ) ;
V_157 = V_7 -> V_4 . V_25 ;
}
V_159:
F_85 ( V_154 , V_156 ) ;
}
if ( V_155 )
F_110 ( V_154 ) ;
}
static void F_186 ( struct V_5 * V_5 , struct V_1 * V_7 )
{
if ( ! F_172 ( V_5 , V_7 ) &&
! F_159 ( V_5 -> V_45 ) &&
V_7 -> V_55 > 1 &&
F_29 ( V_5 -> V_45 ) &&
( V_5 -> V_45 -> V_55 < 2 ||
! F_64 ( & V_7 -> V_4 , & V_5 -> V_45 -> V_4 ) ) ) {
V_67 ( V_5 ) ;
}
}
static void F_187 ( struct V_1 * V_7 ,
const struct V_143 * V_160 )
{
struct V_12 * V_161 ;
struct V_5 * V_5 ;
F_62 ( ! F_29 ( V_7 ) ) ;
V_5 = F_5 ( V_7 ) ;
V_161 = V_5 -> V_11 ;
if ( ! F_188 ( V_161 -> V_162 , V_160 ) ) {
struct V_9 * V_163 ;
V_163 = F_8 ( F_189 ( V_5 ) ) ;
F_31 ( & V_163 -> V_16 ) ;
F_32 ( V_163 , V_7 -> V_4 . V_9 , F_12 ( F_30 ( V_7 ) ) ) ;
F_34 ( & V_163 -> V_16 ) ;
}
F_190 ( V_7 , V_160 ) ;
}
static void F_191 ( struct V_5 * V_5 )
{
if ( V_5 -> V_4 . V_48 )
F_51 ( V_5 ) ;
F_192 ( & V_5 -> V_11 -> V_120 , V_5 -> V_52 ) ;
if ( V_5 -> V_4 . V_54 > 0 )
F_134 ( & V_5 -> V_11 -> V_120 , V_5 -> V_52 , V_5 -> V_4 . V_44 . V_45 ) ;
}
static void F_193 ( struct V_5 * V_5 )
{
if ( V_5 -> V_4 . V_48 )
F_55 ( V_5 ) ;
F_136 ( & V_5 -> V_11 -> V_120 , V_5 -> V_52 ) ;
F_194 ( & V_5 -> V_11 -> V_120 , V_5 -> V_52 ) ;
}
void T_4 F_195 ( void )
{
unsigned int V_10 ;
F_196 (i)
F_197 ( & F_76 ( V_145 , V_10 ) ,
V_164 , F_198 ( V_10 ) ) ;
}
static void F_199 ( struct V_5 * V_5 , struct V_1 * V_7 )
{
if ( F_21 ( V_7 ) && V_7 -> V_4 . V_24 )
F_24 ( V_7 ) ;
if ( ! F_21 ( V_7 ) )
F_19 ( V_7 -> V_4 . V_9 , & V_5 -> V_4 ) ;
if ( V_7 -> V_4 . V_19 )
V_7 -> V_4 . V_19 = 0 ;
if ( ! F_21 ( V_7 ) || V_5 -> V_4 . V_54 )
return;
F_77 ( V_5 ) ;
}
static void F_200 ( struct V_5 * V_5 , struct V_1 * V_7 )
{
if ( F_22 ( & V_7 -> V_4 . V_20 ) == 1 )
F_23 ( V_7 ) ;
if ( ! F_21 ( V_7 ) ) {
F_18 ( V_7 -> V_4 . V_9 , & V_5 -> V_4 ) ;
return;
}
if ( F_87 ( V_7 -> V_4 . V_25 , F_28 ( V_5 ) ) )
F_86 ( & V_7 -> V_4 ) ;
if ( V_5 -> V_45 != V_7 ) {
#ifdef F_47
if ( V_7 -> V_55 > 1 && V_5 -> V_4 . V_48 )
F_74 ( V_5 ) ;
#endif
if ( F_29 ( V_5 -> V_45 ) )
F_109 ( V_5 , V_7 , 0 ) ;
else
F_110 ( V_5 ) ;
}
}
static void F_201 ( struct V_5 * V_5 , struct V_1 * V_7 ,
int V_165 )
{
if ( F_21 ( V_7 ) || V_5 -> V_45 == V_7 ) {
#ifdef F_47
if ( ! V_5 -> V_4 . V_48 )
F_77 ( V_5 ) ;
if ( F_87 ( V_5 -> V_4 . V_44 . V_45 , V_7 -> V_4 . V_25 ) )
F_110 ( V_5 ) ;
#else
F_110 ( V_5 ) ;
#endif
}
}
int F_202 ( void )
{
T_1 V_26 = F_43 () ;
T_1 V_37 = F_45 () ;
T_1 V_18 = F_44 ( V_37 , V_26 ) ;
struct V_9 * V_30 ;
int V_52 , V_152 = 0 ;
unsigned long V_32 ;
F_196 (cpu) {
F_203 () ;
V_30 = F_8 ( V_52 ) ;
F_204 ( & V_30 -> V_16 , V_32 ) ;
if ( V_18 < V_30 -> V_42 )
V_152 = - V_166 ;
F_205 ( & V_30 -> V_16 , V_32 ) ;
F_206 () ;
if ( V_152 )
break;
}
return V_152 ;
}
void F_48 ( struct V_6 * V_6 )
{
if ( F_43 () == V_40 ) {
V_6 -> V_103 = 1 << V_104 ;
V_6 -> V_105 = 1 << V_85 ;
} else {
V_6 -> V_103 = F_44 ( F_43 () ,
F_45 () ) >> ( V_85 - V_104 ) ;
V_6 -> V_105 = F_44 ( F_45 () ,
F_43 () ) ;
}
}
void F_207 ( void )
{
T_1 V_18 = - 1 ;
struct V_9 * V_30 ;
int V_52 ;
unsigned long V_32 ;
V_39 . V_27 = F_45 () ;
V_39 . V_24 = F_43 () ;
if ( F_43 () != V_40 )
V_18 = F_44 ( F_45 () , F_43 () ) ;
F_196 (cpu) {
F_203 () ;
V_30 = F_8 ( V_52 ) ;
F_204 ( & V_30 -> V_16 , V_32 ) ;
V_30 -> V_41 = V_18 ;
F_205 ( & V_30 -> V_16 , V_32 ) ;
F_206 () ;
F_48 ( & F_11 ( V_52 ) -> V_4 ) ;
}
}
int F_208 ( struct V_1 * V_7 , int V_167 ,
const struct V_168 * V_169 )
{
struct V_9 * V_30 = F_8 ( F_30 ( V_7 ) ) ;
T_1 V_37 = V_169 -> V_170 ? : V_169 -> V_171 ;
T_1 V_26 = V_169 -> V_172 ;
T_1 V_18 = F_209 ( V_167 ) ? F_44 ( V_37 , V_26 ) : 0 ;
int V_13 , V_173 = - 1 ;
if ( V_18 == V_7 -> V_4 . V_9 && F_210 ( V_7 ) )
return 0 ;
F_31 ( & V_30 -> V_16 ) ;
V_13 = F_12 ( F_30 ( V_7 ) ) ;
if ( F_209 ( V_167 ) && ! F_210 ( V_7 ) &&
! F_211 ( V_30 , V_13 , 0 , V_18 ) ) {
if ( F_26 ( & V_7 -> V_4 . V_20 ) )
F_32 ( V_30 , V_7 -> V_4 . V_9 , V_13 ) ;
F_212 ( V_30 , V_18 , V_13 ) ;
V_173 = 0 ;
} else if ( F_209 ( V_167 ) && F_210 ( V_7 ) &&
! F_211 ( V_30 , V_13 , V_7 -> V_4 . V_9 , V_18 ) ) {
F_32 ( V_30 , V_7 -> V_4 . V_9 , V_13 ) ;
F_212 ( V_30 , V_18 , V_13 ) ;
F_20 ( V_7 , V_18 ) ;
V_173 = 0 ;
} else if ( ! F_209 ( V_167 ) && F_210 ( V_7 ) ) {
V_173 = 0 ;
}
F_34 ( & V_30 -> V_16 ) ;
return V_173 ;
}
void F_213 ( struct V_1 * V_7 , const struct V_168 * V_169 )
{
struct V_2 * V_3 = & V_7 -> V_4 ;
V_3 -> V_24 = V_169 -> V_172 ;
V_3 -> V_76 = V_169 -> V_171 ;
V_3 -> V_27 = V_169 -> V_170 ? : V_3 -> V_76 ;
V_3 -> V_32 = V_169 -> V_174 ;
V_3 -> V_9 = F_44 ( V_3 -> V_27 , V_3 -> V_24 ) ;
V_3 -> V_84 = F_44 ( V_3 -> V_76 , V_3 -> V_24 ) ;
}
void F_214 ( struct V_1 * V_7 , struct V_168 * V_169 )
{
struct V_2 * V_3 = & V_7 -> V_4 ;
V_169 -> V_175 = V_7 -> V_176 ;
V_169 -> V_172 = V_3 -> V_24 ;
V_169 -> V_171 = V_3 -> V_76 ;
V_169 -> V_170 = V_3 -> V_27 ;
V_169 -> V_174 = V_3 -> V_32 ;
}
bool F_215 ( const struct V_168 * V_169 )
{
if ( V_169 -> V_171 == 0 )
return false ;
if ( V_169 -> V_172 < ( 1ULL << V_82 ) )
return false ;
if ( V_169 -> V_171 & ( 1ULL << 63 ) ||
V_169 -> V_170 & ( 1ULL << 63 ) )
return false ;
if ( ( V_169 -> V_170 != 0 &&
V_169 -> V_170 < V_169 -> V_171 ) ||
V_169 -> V_171 < V_169 -> V_172 )
return false ;
return true ;
}
void F_33 ( struct V_1 * V_7 )
{
struct V_2 * V_3 = & V_7 -> V_4 ;
V_3 -> V_24 = 0 ;
V_3 -> V_76 = 0 ;
V_3 -> V_27 = 0 ;
V_3 -> V_32 = 0 ;
V_3 -> V_9 = 0 ;
V_3 -> V_84 = 0 ;
V_3 -> V_75 = 0 ;
V_3 -> V_78 = 0 ;
V_3 -> V_19 = 0 ;
}
bool F_216 ( struct V_1 * V_7 , const struct V_168 * V_169 )
{
struct V_2 * V_3 = & V_7 -> V_4 ;
if ( V_3 -> V_24 != V_169 -> V_172 ||
V_3 -> V_76 != V_169 -> V_171 ||
V_3 -> V_27 != V_169 -> V_170 ||
V_3 -> V_32 != V_169 -> V_174 )
return true ;
return false ;
}
int F_217 ( struct V_1 * V_7 , const struct V_143 * V_177 )
{
unsigned int V_178 = F_80 ( V_71 ,
V_177 ) ;
struct V_9 * V_30 ;
bool V_179 ;
int V_13 , V_152 ;
unsigned long V_32 ;
F_203 () ;
V_30 = F_8 ( V_178 ) ;
F_204 ( & V_30 -> V_16 , V_32 ) ;
V_13 = F_12 ( V_178 ) ;
V_179 = F_211 ( V_30 , V_13 , 0 , V_7 -> V_4 . V_9 ) ;
if ( V_179 )
V_152 = - V_166 ;
else {
F_212 ( V_30 , V_7 -> V_4 . V_9 , V_13 ) ;
V_152 = 0 ;
}
F_205 ( & V_30 -> V_16 , V_32 ) ;
F_206 () ;
return V_152 ;
}
int F_218 ( const struct V_143 * V_180 ,
const struct V_143 * V_181 )
{
int V_152 = 1 , V_182 ;
struct V_9 * V_183 ;
unsigned long V_32 ;
F_203 () ;
V_183 = F_8 ( F_82 ( V_180 ) ) ;
V_182 = F_219 ( V_181 ) ;
F_204 ( & V_183 -> V_16 , V_32 ) ;
if ( V_183 -> V_41 != - 1 &&
V_183 -> V_41 * V_182 < V_183 -> V_42 )
V_152 = 0 ;
F_205 ( & V_183 -> V_16 , V_32 ) ;
F_206 () ;
return V_152 ;
}
bool F_220 ( unsigned int V_52 )
{
unsigned long V_32 ;
struct V_9 * V_30 ;
bool V_179 ;
int V_13 ;
F_203 () ;
V_30 = F_8 ( V_52 ) ;
F_204 ( & V_30 -> V_16 , V_32 ) ;
V_13 = F_12 ( V_52 ) ;
V_179 = F_211 ( V_30 , V_13 , 0 , 0 ) ;
F_205 ( & V_30 -> V_16 , V_32 ) ;
F_206 () ;
return V_179 ;
}
void F_221 ( struct V_184 * V_185 , int V_52 )
{
F_222 ( V_185 , V_52 , & F_11 ( V_52 ) -> V_4 ) ;
}
