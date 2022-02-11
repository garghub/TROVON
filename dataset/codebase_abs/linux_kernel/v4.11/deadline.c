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
static inline int F_8 ( struct V_1 * V_7 , struct V_6 * V_6 )
{
struct V_2 * V_3 = & V_7 -> V_4 ;
return V_6 -> V_9 == & V_3 -> V_8 ;
}
void F_9 ( struct V_10 * V_11 , T_1 V_12 , T_1 V_13 )
{
F_10 ( & V_11 -> V_14 ) ;
V_11 -> V_15 = V_12 ;
V_11 -> V_16 = V_13 ;
}
void F_11 ( struct V_17 * V_11 )
{
F_10 ( & V_11 -> V_18 ) ;
F_12 ( & V_19 . V_14 ) ;
if ( F_13 () == V_20 )
V_11 -> V_21 = - 1 ;
else
V_11 -> V_21 = F_14 ( F_15 () , F_13 () ) ;
F_16 ( & V_19 . V_14 ) ;
V_11 -> V_22 = 0 ;
}
void F_17 ( struct V_6 * V_6 )
{
V_6 -> V_23 = V_24 ;
#ifdef F_18
V_6 -> V_25 . V_26 = V_6 -> V_25 . V_27 = 0 ;
V_6 -> V_28 = 0 ;
V_6 -> V_29 = 0 ;
V_6 -> V_30 = V_24 ;
#else
F_11 ( & V_6 -> V_17 ) ;
#endif
}
static inline int F_19 ( struct V_5 * V_5 )
{
return F_20 ( & V_5 -> V_31 -> V_32 ) ;
}
static inline void F_21 ( struct V_5 * V_5 )
{
if ( ! V_5 -> V_33 )
return;
F_22 ( V_5 -> V_34 , V_5 -> V_31 -> V_35 ) ;
F_23 () ;
F_24 ( & V_5 -> V_31 -> V_32 ) ;
}
static inline void F_25 ( struct V_5 * V_5 )
{
if ( ! V_5 -> V_33 )
return;
F_26 ( & V_5 -> V_31 -> V_32 ) ;
F_27 ( V_5 -> V_34 , V_5 -> V_31 -> V_35 ) ;
}
static void F_28 ( struct V_6 * V_6 )
{
if ( V_6 -> V_28 && V_6 -> V_36 > 1 ) {
if ( ! V_6 -> V_29 ) {
F_21 ( F_3 ( V_6 ) ) ;
V_6 -> V_29 = 1 ;
}
} else if ( V_6 -> V_29 ) {
F_25 ( F_3 ( V_6 ) ) ;
V_6 -> V_29 = 0 ;
}
}
static void F_29 ( struct V_2 * V_3 , struct V_6 * V_6 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
if ( V_7 -> V_37 > 1 )
V_6 -> V_28 ++ ;
F_28 ( V_6 ) ;
}
static void F_30 ( struct V_2 * V_3 , struct V_6 * V_6 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
if ( V_7 -> V_37 > 1 )
V_6 -> V_28 -- ;
F_28 ( V_6 ) ;
}
static void F_31 ( struct V_5 * V_5 , struct V_1 * V_7 )
{
struct V_6 * V_6 = & V_5 -> V_4 ;
struct V_8 * * V_38 = & V_6 -> V_30 . V_8 ;
struct V_8 * V_39 = NULL ;
struct V_1 * V_40 ;
int V_41 = 1 ;
F_32 ( ! F_7 ( & V_7 -> V_42 ) ) ;
while ( * V_38 ) {
V_39 = * V_38 ;
V_40 = F_33 ( V_39 , struct V_1 ,
V_42 ) ;
if ( F_34 ( & V_7 -> V_4 , & V_40 -> V_4 ) )
V_38 = & V_39 -> V_43 ;
else {
V_38 = & V_39 -> V_44 ;
V_41 = 0 ;
}
}
if ( V_41 ) {
V_6 -> V_45 = & V_7 -> V_42 ;
V_6 -> V_25 . V_27 = V_7 -> V_4 . V_46 ;
}
F_35 ( & V_7 -> V_42 , V_39 , V_38 ) ;
F_36 ( & V_7 -> V_42 , & V_6 -> V_30 ) ;
}
static void F_37 ( struct V_5 * V_5 , struct V_1 * V_7 )
{
struct V_6 * V_6 = & V_5 -> V_4 ;
if ( F_7 ( & V_7 -> V_42 ) )
return;
if ( V_6 -> V_45 == & V_7 -> V_42 ) {
struct V_8 * V_47 ;
V_47 = F_38 ( & V_7 -> V_42 ) ;
V_6 -> V_45 = V_47 ;
if ( V_47 ) {
V_6 -> V_25 . V_27 = F_33 ( V_47 ,
struct V_1 , V_42 ) -> V_4 . V_46 ;
}
}
F_39 ( & V_7 -> V_42 , & V_6 -> V_30 ) ;
F_40 ( & V_7 -> V_42 ) ;
}
static inline int F_41 ( struct V_5 * V_5 )
{
return ! F_42 ( & V_5 -> V_4 . V_30 ) ;
}
static inline bool F_43 ( struct V_5 * V_5 , struct V_1 * V_48 )
{
return F_44 ( V_48 ) ;
}
static inline void F_45 ( struct V_5 * V_5 )
{
if ( ! F_41 ( V_5 ) )
return;
F_46 ( V_5 , & F_47 ( V_49 , V_5 -> V_34 ) , V_50 ) ;
}
static inline void F_48 ( struct V_5 * V_5 )
{
F_46 ( V_5 , & F_47 ( V_51 , V_5 -> V_34 ) , V_52 ) ;
}
static struct V_5 * F_49 ( struct V_5 * V_5 , struct V_1 * V_7 )
{
struct V_5 * V_53 = NULL ;
V_53 = F_50 ( V_7 , V_5 ) ;
if ( ! V_53 ) {
int V_34 ;
V_34 = F_51 ( V_54 , & V_7 -> V_55 ) ;
if ( V_34 >= V_56 ) {
F_32 ( F_52 () ) ;
V_34 = F_53 ( V_54 ) ;
}
V_53 = F_54 ( V_34 ) ;
F_55 ( V_5 , V_53 ) ;
}
F_56 ( V_7 , V_53 -> V_34 ) ;
F_57 ( V_53 , V_5 ) ;
return V_53 ;
}
static inline
void F_31 ( struct V_5 * V_5 , struct V_1 * V_7 )
{
}
static inline
void F_37 ( struct V_5 * V_5 , struct V_1 * V_7 )
{
}
static inline
void F_29 ( struct V_2 * V_3 , struct V_6 * V_6 )
{
}
static inline
void F_30 ( struct V_2 * V_3 , struct V_6 * V_6 )
{
}
static inline bool F_43 ( struct V_5 * V_5 , struct V_1 * V_48 )
{
return false ;
}
static inline void V_52 ( struct V_5 * V_5 )
{
}
static inline void F_45 ( struct V_5 * V_5 )
{
}
static inline void F_48 ( struct V_5 * V_5 )
{
}
static inline void F_58 ( struct V_2 * V_3 )
{
struct V_6 * V_6 = F_4 ( V_3 ) ;
struct V_5 * V_5 = F_3 ( V_6 ) ;
F_59 ( V_3 -> V_57 ) ;
F_59 ( F_60 ( F_61 ( V_5 ) , V_3 -> V_46 ) ) ;
if ( V_3 -> V_58 )
return;
V_3 -> V_46 = F_61 ( V_5 ) + V_3 -> V_59 ;
V_3 -> V_13 = V_3 -> V_16 ;
}
static void F_62 ( struct V_2 * V_3 ,
struct V_2 * V_60 )
{
struct V_6 * V_6 = F_4 ( V_3 ) ;
struct V_5 * V_5 = F_3 ( V_6 ) ;
F_32 ( V_60 -> V_16 <= 0 ) ;
if ( V_3 -> V_59 == 0 ) {
V_3 -> V_46 = F_61 ( V_5 ) + V_60 -> V_59 ;
V_3 -> V_13 = V_60 -> V_16 ;
}
if ( V_3 -> V_61 && V_3 -> V_13 > 0 )
V_3 -> V_13 = 0 ;
while ( V_3 -> V_13 <= 0 ) {
V_3 -> V_46 += V_60 -> V_15 ;
V_3 -> V_13 += V_60 -> V_16 ;
}
if ( F_60 ( V_3 -> V_46 , F_61 ( V_5 ) ) ) {
F_63 ( L_1 ) ;
V_3 -> V_46 = F_61 ( V_5 ) + V_60 -> V_59 ;
V_3 -> V_13 = V_60 -> V_16 ;
}
if ( V_3 -> V_61 )
V_3 -> V_61 = 0 ;
if ( V_3 -> V_58 )
V_3 -> V_58 = 0 ;
}
static bool F_64 ( struct V_2 * V_3 ,
struct V_2 * V_60 , T_1 V_62 )
{
T_1 V_63 , V_64 ;
V_63 = ( V_60 -> V_59 >> V_65 ) * ( V_3 -> V_13 >> V_65 ) ;
V_64 = ( ( V_3 -> V_46 - V_62 ) >> V_65 ) *
( V_60 -> V_16 >> V_65 ) ;
return F_60 ( V_64 , V_63 ) ;
}
static void F_65 ( struct V_2 * V_3 ,
struct V_2 * V_60 )
{
struct V_6 * V_6 = F_4 ( V_3 ) ;
struct V_5 * V_5 = F_3 ( V_6 ) ;
if ( F_60 ( V_3 -> V_46 , F_61 ( V_5 ) ) ||
F_64 ( V_3 , V_60 , F_61 ( V_5 ) ) ) {
V_3 -> V_46 = F_61 ( V_5 ) + V_60 -> V_59 ;
V_3 -> V_13 = V_60 -> V_16 ;
}
}
static inline T_1 F_66 ( struct V_2 * V_3 )
{
return V_3 -> V_46 - V_3 -> V_59 + V_3 -> V_15 ;
}
static int F_67 ( struct V_1 * V_7 )
{
struct V_2 * V_3 = & V_7 -> V_4 ;
struct V_66 * V_67 = & V_3 -> V_68 ;
struct V_5 * V_5 = F_5 ( V_7 ) ;
T_2 V_69 , V_70 ;
T_3 V_71 ;
F_68 ( & V_5 -> V_18 ) ;
V_70 = F_69 ( F_66 ( V_3 ) ) ;
V_69 = F_70 ( V_67 ) ;
V_71 = F_71 ( V_69 ) - F_61 ( V_5 ) ;
V_70 = F_72 ( V_70 , V_71 ) ;
if ( F_73 ( V_70 , V_69 ) < 0 )
return 0 ;
if ( ! F_74 ( V_67 ) ) {
F_75 ( V_7 ) ;
F_76 ( V_67 , V_70 , V_72 ) ;
}
return 1 ;
}
static enum V_73 F_77 ( struct V_66 * V_67 )
{
struct V_2 * V_3 = F_2 ( V_67 ,
struct V_2 ,
V_68 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_74 V_75 ;
struct V_5 * V_5 ;
V_5 = F_78 ( V_7 , & V_75 ) ;
if ( ! F_44 ( V_7 ) ) {
F_79 ( V_7 ) ;
goto V_76;
}
if ( V_3 -> V_57 )
goto V_76;
if ( ! V_3 -> V_58 )
goto V_76;
F_80 () ;
F_81 ( V_5 ) ;
if ( ! F_82 ( V_7 ) ) {
F_62 ( V_3 , V_3 ) ;
goto V_76;
}
#ifdef F_18
if ( F_83 ( ! V_5 -> V_33 ) ) {
F_84 ( & V_5 -> V_18 , V_75 . V_77 ) ;
V_5 = F_49 ( V_5 , V_7 ) ;
V_75 . V_77 = F_85 ( & V_5 -> V_18 ) ;
F_81 ( V_5 ) ;
}
#endif
F_86 ( V_5 , V_7 , V_78 ) ;
if ( F_44 ( V_5 -> V_26 ) )
F_87 ( V_5 , V_7 , 0 ) ;
else
F_88 ( V_5 ) ;
#ifdef F_18
if ( F_41 ( V_5 ) ) {
F_89 ( V_5 , & V_75 ) ;
F_90 ( V_5 ) ;
F_91 ( V_5 , & V_75 ) ;
}
#endif
V_76:
F_92 ( V_5 , V_7 , & V_75 ) ;
F_93 ( V_7 ) ;
return V_79 ;
}
void F_94 ( struct V_2 * V_3 )
{
struct V_66 * V_67 = & V_3 -> V_68 ;
F_95 ( V_67 , V_80 , V_81 ) ;
V_67 -> V_82 = F_77 ;
}
static inline void F_96 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_5 * V_5 = F_3 ( F_4 ( V_3 ) ) ;
if ( F_60 ( V_3 -> V_46 , F_61 ( V_5 ) ) &&
F_60 ( F_61 ( V_5 ) , F_66 ( V_3 ) ) ) {
if ( F_83 ( V_3 -> V_57 || ! F_67 ( V_7 ) ) )
return;
V_3 -> V_58 = 1 ;
}
}
static
int F_97 ( struct V_2 * V_3 )
{
return ( V_3 -> V_13 <= 0 ) ;
}
static void F_98 ( struct V_5 * V_5 )
{
struct V_1 * V_26 = V_5 -> V_26 ;
struct V_2 * V_3 = & V_26 -> V_4 ;
T_1 V_83 ;
if ( ! F_44 ( V_26 ) || ! F_6 ( V_3 ) )
return;
V_83 = F_99 ( V_5 ) - V_26 -> V_84 . V_85 ;
if ( F_83 ( ( T_3 ) V_83 <= 0 ) ) {
if ( F_83 ( V_3 -> V_61 ) )
goto V_86;
return;
}
F_100 ( V_5 , V_87 ) ;
F_101 ( V_26 -> V_84 . V_88 . V_89 ,
F_102 ( V_26 -> V_84 . V_88 . V_89 , V_83 ) ) ;
V_26 -> V_84 . V_90 += V_83 ;
F_103 ( V_26 , V_83 ) ;
V_26 -> V_84 . V_85 = F_99 ( V_5 ) ;
F_104 ( V_26 , V_83 ) ;
F_105 ( V_5 , V_83 ) ;
V_3 -> V_13 -= V_83 ;
V_86:
if ( F_97 ( V_3 ) || V_3 -> V_61 ) {
V_3 -> V_58 = 1 ;
F_106 ( V_5 , V_26 , 0 ) ;
if ( F_83 ( V_3 -> V_57 || ! F_67 ( V_26 ) ) )
F_86 ( V_5 , V_26 , V_78 ) ;
if ( ! F_8 ( V_26 , & V_5 -> V_4 ) )
F_88 ( V_5 ) ;
}
if ( F_107 () ) {
struct V_91 * V_91 = & V_5 -> V_92 ;
F_12 ( & V_91 -> V_93 ) ;
if ( F_108 ( V_91 ) )
V_91 -> V_94 += V_83 ;
F_16 ( & V_91 -> V_93 ) ;
}
}
static void F_109 ( struct V_6 * V_6 , T_1 V_46 )
{
struct V_5 * V_5 = F_3 ( V_6 ) ;
if ( V_6 -> V_25 . V_26 == 0 ||
F_60 ( V_46 , V_6 -> V_25 . V_26 ) ) {
V_6 -> V_25 . V_26 = V_46 ;
F_110 ( & V_5 -> V_31 -> V_95 , V_5 -> V_34 , V_46 ) ;
}
}
static void F_111 ( struct V_6 * V_6 , T_1 V_46 )
{
struct V_5 * V_5 = F_3 ( V_6 ) ;
if ( ! V_6 -> V_36 ) {
V_6 -> V_25 . V_26 = 0 ;
V_6 -> V_25 . V_27 = 0 ;
F_112 ( & V_5 -> V_31 -> V_95 , V_5 -> V_34 ) ;
} else {
struct V_8 * V_41 = V_6 -> V_9 ;
struct V_2 * V_40 ;
V_40 = F_33 ( V_41 , struct V_2 , V_8 ) ;
V_6 -> V_25 . V_26 = V_40 -> V_46 ;
F_110 ( & V_5 -> V_31 -> V_95 , V_5 -> V_34 , V_40 -> V_46 ) ;
}
}
static inline void F_109 ( struct V_6 * V_6 , T_1 V_46 ) {}
static inline void F_111 ( struct V_6 * V_6 , T_1 V_46 ) {}
static inline
void F_113 ( struct V_2 * V_3 , struct V_6 * V_6 )
{
int V_96 = F_1 ( V_3 ) -> V_96 ;
T_1 V_46 = V_3 -> V_46 ;
F_59 ( ! F_114 ( V_96 ) ) ;
V_6 -> V_36 ++ ;
F_115 ( F_3 ( V_6 ) , 1 ) ;
F_109 ( V_6 , V_46 ) ;
F_29 ( V_3 , V_6 ) ;
}
static inline
void F_116 ( struct V_2 * V_3 , struct V_6 * V_6 )
{
int V_96 = F_1 ( V_3 ) -> V_96 ;
F_59 ( ! F_114 ( V_96 ) ) ;
F_59 ( ! V_6 -> V_36 ) ;
V_6 -> V_36 -- ;
F_117 ( F_3 ( V_6 ) , 1 ) ;
F_111 ( V_6 , V_3 -> V_46 ) ;
F_30 ( V_3 , V_6 ) ;
}
static void F_118 ( struct V_2 * V_3 )
{
struct V_6 * V_6 = F_4 ( V_3 ) ;
struct V_8 * * V_38 = & V_6 -> V_23 . V_8 ;
struct V_8 * V_39 = NULL ;
struct V_2 * V_40 ;
int V_41 = 1 ;
F_32 ( ! F_7 ( & V_3 -> V_8 ) ) ;
while ( * V_38 ) {
V_39 = * V_38 ;
V_40 = F_33 ( V_39 , struct V_2 , V_8 ) ;
if ( F_60 ( V_3 -> V_46 , V_40 -> V_46 ) )
V_38 = & V_39 -> V_43 ;
else {
V_38 = & V_39 -> V_44 ;
V_41 = 0 ;
}
}
if ( V_41 )
V_6 -> V_9 = & V_3 -> V_8 ;
F_35 ( & V_3 -> V_8 , V_39 , V_38 ) ;
F_36 ( & V_3 -> V_8 , & V_6 -> V_23 ) ;
F_113 ( V_3 , V_6 ) ;
}
static void F_119 ( struct V_2 * V_3 )
{
struct V_6 * V_6 = F_4 ( V_3 ) ;
if ( F_7 ( & V_3 -> V_8 ) )
return;
if ( V_6 -> V_9 == & V_3 -> V_8 ) {
struct V_8 * V_47 ;
V_47 = F_38 ( & V_3 -> V_8 ) ;
V_6 -> V_9 = V_47 ;
}
F_39 ( & V_3 -> V_8 , & V_6 -> V_23 ) ;
F_40 ( & V_3 -> V_8 ) ;
F_116 ( V_3 , V_6 ) ;
}
static void
F_120 ( struct V_2 * V_3 ,
struct V_2 * V_60 , int V_97 )
{
F_32 ( F_6 ( V_3 ) ) ;
if ( V_97 & V_98 )
F_65 ( V_3 , V_60 ) ;
else if ( V_97 & V_78 )
F_62 ( V_3 , V_60 ) ;
F_118 ( V_3 ) ;
}
static void F_121 ( struct V_2 * V_3 )
{
F_119 ( V_3 ) ;
}
static inline bool F_122 ( struct V_2 * V_3 )
{
return V_3 -> V_59 < V_3 -> V_15 ;
}
static void F_86 ( struct V_5 * V_5 , struct V_1 * V_7 , int V_97 )
{
struct V_1 * V_99 = F_123 ( V_7 ) ;
struct V_2 * V_60 = & V_7 -> V_4 ;
if ( V_99 && V_7 -> V_4 . V_57 && F_114 ( V_99 -> V_100 ) ) {
V_60 = & V_99 -> V_4 ;
} else if ( ! F_114 ( V_7 -> V_100 ) ) {
F_32 ( ! V_7 -> V_4 . V_57 || V_97 != V_78 ) ;
return;
}
if ( ! V_7 -> V_4 . V_58 && F_122 ( & V_7 -> V_4 ) )
F_96 ( & V_7 -> V_4 ) ;
if ( V_7 -> V_4 . V_58 && ! ( V_97 & V_78 ) )
return;
F_120 ( & V_7 -> V_4 , V_60 , V_97 ) ;
if ( ! F_124 ( V_5 , V_7 ) && V_7 -> V_37 > 1 )
F_31 ( V_5 , V_7 ) ;
}
static void F_106 ( struct V_5 * V_5 , struct V_1 * V_7 , int V_97 )
{
F_121 ( & V_7 -> V_4 ) ;
F_37 ( V_5 , V_7 ) ;
}
static void F_125 ( struct V_5 * V_5 , struct V_1 * V_7 , int V_97 )
{
F_98 ( V_5 ) ;
F_106 ( V_5 , V_7 , V_97 ) ;
}
static void F_126 ( struct V_5 * V_5 )
{
V_5 -> V_26 -> V_4 . V_61 = 1 ;
F_81 ( V_5 ) ;
F_98 ( V_5 ) ;
F_127 ( V_5 , true ) ;
}
static int
F_128 ( struct V_1 * V_7 , int V_34 , int V_101 , int V_97 )
{
struct V_1 * V_26 ;
struct V_5 * V_5 ;
if ( V_101 != V_102 )
goto V_103;
V_5 = F_54 ( V_34 ) ;
F_129 () ;
V_26 = F_130 ( V_5 -> V_26 ) ;
if ( F_83 ( F_44 ( V_26 ) ) &&
( V_26 -> V_37 < 2 ||
! F_34 ( & V_7 -> V_4 , & V_26 -> V_4 ) ) &&
( V_7 -> V_37 > 1 ) ) {
int V_104 = F_131 ( V_7 ) ;
if ( V_104 != - 1 &&
( F_60 ( V_7 -> V_4 . V_46 ,
F_54 ( V_104 ) -> V_4 . V_25 . V_26 ) ||
( F_54 ( V_104 ) -> V_4 . V_36 == 0 ) ) )
V_34 = V_104 ;
}
F_132 () ;
V_103:
return V_34 ;
}
static void F_133 ( struct V_5 * V_5 , struct V_1 * V_7 )
{
if ( V_5 -> V_26 -> V_37 == 1 ||
F_134 ( & V_5 -> V_31 -> V_95 , V_5 -> V_26 , NULL ) == - 1 )
return;
if ( V_7 -> V_37 != 1 &&
F_134 ( & V_5 -> V_31 -> V_95 , V_7 , NULL ) != - 1 )
return;
F_88 ( V_5 ) ;
}
static void F_87 ( struct V_5 * V_5 , struct V_1 * V_7 ,
int V_97 )
{
if ( F_34 ( & V_7 -> V_4 , & V_5 -> V_26 -> V_4 ) ) {
F_88 ( V_5 ) ;
return;
}
#ifdef F_18
if ( ( V_7 -> V_4 . V_46 == V_5 -> V_26 -> V_4 . V_46 ) &&
! F_135 ( V_5 -> V_26 ) )
F_133 ( V_5 , V_7 ) ;
#endif
}
static void F_136 ( struct V_5 * V_5 , struct V_1 * V_7 )
{
F_137 ( V_5 , V_7 -> V_4 . V_13 ) ;
}
static void F_136 ( struct V_5 * V_5 , struct V_1 * V_7 )
{
}
static struct V_2 * F_138 ( struct V_5 * V_5 ,
struct V_6 * V_6 )
{
struct V_8 * V_63 = V_6 -> V_9 ;
if ( ! V_63 )
return NULL ;
return F_33 ( V_63 , struct V_2 , V_8 ) ;
}
struct V_1 *
F_139 ( struct V_5 * V_5 , struct V_1 * V_48 , struct V_74 * V_75 )
{
struct V_2 * V_3 ;
struct V_1 * V_7 ;
struct V_6 * V_6 ;
V_6 = & V_5 -> V_4 ;
if ( F_43 ( V_5 , V_48 ) ) {
F_89 ( V_5 , V_75 ) ;
V_52 ( V_5 ) ;
F_91 ( V_5 , V_75 ) ;
if ( V_5 -> V_105 && F_82 ( V_5 -> V_105 ) )
return V_106 ;
}
if ( V_48 -> V_107 == & V_108 )
F_98 ( V_5 ) ;
if ( F_83 ( ! V_6 -> V_36 ) )
return NULL ;
F_140 ( V_5 , V_48 ) ;
V_3 = F_138 ( V_5 , V_6 ) ;
F_32 ( ! V_3 ) ;
V_7 = F_1 ( V_3 ) ;
V_7 -> V_84 . V_85 = F_99 ( V_5 ) ;
F_37 ( V_5 , V_7 ) ;
if ( F_141 ( V_5 ) )
F_136 ( V_5 , V_7 ) ;
F_45 ( V_5 ) ;
return V_7 ;
}
static void F_142 ( struct V_5 * V_5 , struct V_1 * V_7 )
{
F_98 ( V_5 ) ;
if ( F_6 ( & V_7 -> V_4 ) && V_7 -> V_37 > 1 )
F_31 ( V_5 , V_7 ) ;
}
static void F_143 ( struct V_5 * V_5 , struct V_1 * V_7 , int V_109 )
{
F_98 ( V_5 ) ;
if ( F_141 ( V_5 ) && V_109 && V_7 -> V_4 . V_13 > 0 &&
F_8 ( V_7 , & V_5 -> V_4 ) )
F_136 ( V_5 , V_7 ) ;
}
static void F_144 ( struct V_1 * V_7 )
{
}
static void F_145 ( struct V_1 * V_7 )
{
struct V_17 * V_11 = F_146 ( F_147 ( V_7 ) ) ;
F_148 ( & V_11 -> V_18 ) ;
V_11 -> V_22 -= V_7 -> V_4 . V_17 ;
F_149 ( & V_11 -> V_18 ) ;
}
static void F_150 ( struct V_5 * V_5 )
{
struct V_1 * V_7 = V_5 -> V_26 ;
V_7 -> V_84 . V_85 = F_99 ( V_5 ) ;
F_37 ( V_5 , V_7 ) ;
}
static int F_151 ( struct V_5 * V_5 , struct V_1 * V_7 , int V_34 )
{
if ( ! F_152 ( V_5 , V_7 ) &&
F_153 ( V_34 , & V_7 -> V_55 ) )
return 1 ;
return 0 ;
}
static struct V_1 * F_154 ( struct V_5 * V_5 , int V_34 )
{
struct V_8 * V_47 = V_5 -> V_4 . V_45 ;
struct V_1 * V_7 = NULL ;
if ( ! F_41 ( V_5 ) )
return NULL ;
V_47:
if ( V_47 ) {
V_7 = F_33 ( V_47 , struct V_1 , V_42 ) ;
if ( F_151 ( V_5 , V_7 , V_34 ) )
return V_7 ;
V_47 = F_38 ( V_47 ) ;
goto V_47;
}
return NULL ;
}
static int F_131 ( struct V_1 * V_110 )
{
struct V_111 * V_112 ;
struct V_113 * V_114 = F_155 ( V_115 ) ;
int V_116 = F_156 () ;
int V_117 , V_34 = F_147 ( V_110 ) ;
if ( F_83 ( ! V_114 ) )
return - 1 ;
if ( V_110 -> V_37 == 1 )
return - 1 ;
V_117 = F_134 ( & F_5 ( V_110 ) -> V_31 -> V_95 ,
V_110 , V_114 ) ;
if ( V_117 == - 1 )
return - 1 ;
if ( F_153 ( V_34 , V_114 ) )
return V_34 ;
if ( ! F_153 ( V_116 , V_114 ) )
V_116 = - 1 ;
F_129 () ;
F_157 (cpu, sd) {
if ( V_112 -> V_97 & V_118 ) {
if ( V_116 != - 1 &&
F_153 ( V_116 , F_158 ( V_112 ) ) ) {
F_132 () ;
return V_116 ;
}
if ( V_117 < V_56 &&
F_153 ( V_117 , F_158 ( V_112 ) ) ) {
F_132 () ;
return V_117 ;
}
}
}
F_132 () ;
if ( V_116 != - 1 )
return V_116 ;
V_34 = F_53 ( V_114 ) ;
if ( V_34 < V_56 )
return V_34 ;
return - 1 ;
}
static struct V_5 * F_50 ( struct V_1 * V_110 , struct V_5 * V_5 )
{
struct V_5 * V_53 = NULL ;
int V_119 ;
int V_34 ;
for ( V_119 = 0 ; V_119 < V_120 ; V_119 ++ ) {
V_34 = F_131 ( V_110 ) ;
if ( ( V_34 == - 1 ) || ( V_34 == V_5 -> V_34 ) )
break;
V_53 = F_54 ( V_34 ) ;
if ( V_53 -> V_4 . V_36 &&
! F_60 ( V_110 -> V_4 . V_46 ,
V_53 -> V_4 . V_25 . V_26 ) ) {
V_53 = NULL ;
break;
}
if ( F_55 ( V_5 , V_53 ) ) {
if ( F_83 ( F_5 ( V_110 ) != V_5 ||
! F_153 ( V_53 -> V_34 , & V_110 -> V_55 ) ||
F_152 ( V_5 , V_110 ) ||
! F_44 ( V_110 ) ||
! F_82 ( V_110 ) ) ) {
F_57 ( V_5 , V_53 ) ;
V_53 = NULL ;
break;
}
}
if ( ! V_53 -> V_4 . V_36 ||
F_60 ( V_110 -> V_4 . V_46 ,
V_53 -> V_4 . V_25 . V_26 ) )
break;
F_57 ( V_5 , V_53 ) ;
V_53 = NULL ;
}
return V_53 ;
}
static struct V_1 * F_159 ( struct V_5 * V_5 )
{
struct V_1 * V_7 ;
if ( ! F_41 ( V_5 ) )
return NULL ;
V_7 = F_33 ( V_5 -> V_4 . V_45 ,
struct V_1 , V_42 ) ;
F_32 ( V_5 -> V_34 != F_147 ( V_7 ) ) ;
F_32 ( F_124 ( V_5 , V_7 ) ) ;
F_32 ( V_7 -> V_37 <= 1 ) ;
F_32 ( ! F_82 ( V_7 ) ) ;
F_32 ( ! F_44 ( V_7 ) ) ;
return V_7 ;
}
static int F_90 ( struct V_5 * V_5 )
{
struct V_1 * V_121 ;
struct V_5 * V_53 ;
int V_122 = 0 ;
if ( ! V_5 -> V_4 . V_29 )
return 0 ;
V_121 = F_159 ( V_5 ) ;
if ( ! V_121 )
return 0 ;
V_123:
if ( F_83 ( V_121 == V_5 -> V_26 ) ) {
F_59 ( 1 ) ;
return 0 ;
}
if ( F_44 ( V_5 -> V_26 ) &&
F_60 ( V_121 -> V_4 . V_46 , V_5 -> V_26 -> V_4 . V_46 ) &&
V_5 -> V_26 -> V_37 > 1 ) {
F_88 ( V_5 ) ;
return 0 ;
}
F_75 ( V_121 ) ;
V_53 = F_50 ( V_121 , V_5 ) ;
if ( ! V_53 ) {
struct V_1 * V_110 ;
V_110 = F_159 ( V_5 ) ;
if ( F_147 ( V_121 ) == V_5 -> V_34 && V_110 == V_121 ) {
goto V_103;
}
if ( ! V_110 )
goto V_103;
F_93 ( V_121 ) ;
V_121 = V_110 ;
goto V_123;
}
F_160 ( V_5 , V_121 , 0 ) ;
F_56 ( V_121 , V_53 -> V_34 ) ;
F_161 ( V_53 , V_121 , 0 ) ;
V_122 = 1 ;
F_88 ( V_53 ) ;
F_57 ( V_5 , V_53 ) ;
V_103:
F_93 ( V_121 ) ;
return V_122 ;
}
static void V_50 ( struct V_5 * V_5 )
{
while ( F_90 ( V_5 ) )
;
}
static void V_52 ( struct V_5 * V_124 )
{
int V_116 = V_124 -> V_34 , V_34 ;
struct V_1 * V_7 ;
bool V_125 = false ;
struct V_5 * V_126 ;
T_1 V_127 = V_128 ;
if ( F_162 ( ! F_19 ( V_124 ) ) )
return;
F_163 () ;
F_164 (cpu, this_rq->rd->dlo_mask) {
if ( V_116 == V_34 )
continue;
V_126 = F_54 ( V_34 ) ;
if ( V_124 -> V_4 . V_36 &&
F_60 ( V_124 -> V_4 . V_25 . V_26 ,
V_126 -> V_4 . V_25 . V_27 ) )
continue;
F_55 ( V_124 , V_126 ) ;
if ( V_126 -> V_4 . V_36 <= 1 )
goto V_129;
V_7 = F_154 ( V_126 , V_116 ) ;
if ( V_7 && F_60 ( V_7 -> V_4 . V_46 , V_127 ) &&
( ! V_124 -> V_4 . V_36 ||
F_60 ( V_7 -> V_4 . V_46 ,
V_124 -> V_4 . V_25 . V_26 ) ) ) {
F_59 ( V_7 == V_126 -> V_26 ) ;
F_59 ( ! F_82 ( V_7 ) ) ;
if ( F_60 ( V_7 -> V_4 . V_46 ,
V_126 -> V_26 -> V_4 . V_46 ) )
goto V_129;
V_125 = true ;
F_160 ( V_126 , V_7 , 0 ) ;
F_56 ( V_7 , V_116 ) ;
F_161 ( V_124 , V_7 , 0 ) ;
V_127 = V_7 -> V_4 . V_46 ;
}
V_129:
F_57 ( V_124 , V_126 ) ;
}
if ( V_125 )
F_88 ( V_124 ) ;
}
static void F_165 ( struct V_5 * V_5 , struct V_1 * V_7 )
{
if ( ! F_152 ( V_5 , V_7 ) &&
! F_135 ( V_5 -> V_26 ) &&
V_7 -> V_37 > 1 &&
F_44 ( V_5 -> V_26 ) &&
( V_5 -> V_26 -> V_37 < 2 ||
! F_34 ( & V_7 -> V_4 , & V_5 -> V_26 -> V_4 ) ) ) {
V_50 ( V_5 ) ;
}
}
static void F_166 ( struct V_1 * V_7 ,
const struct V_113 * V_130 )
{
struct V_131 * V_132 ;
struct V_5 * V_5 ;
F_32 ( ! F_44 ( V_7 ) ) ;
V_5 = F_5 ( V_7 ) ;
V_132 = V_5 -> V_31 ;
if ( ! F_167 ( V_132 -> V_133 , V_130 ) ) {
struct V_17 * V_134 ;
V_134 = F_146 ( F_168 ( V_5 ) ) ;
F_12 ( & V_134 -> V_18 ) ;
F_169 ( V_134 , V_7 -> V_4 . V_17 ) ;
F_16 ( & V_134 -> V_18 ) ;
}
F_170 ( V_7 , V_130 ) ;
}
static void F_171 ( struct V_5 * V_5 )
{
if ( V_5 -> V_4 . V_29 )
F_21 ( V_5 ) ;
F_172 ( & V_5 -> V_31 -> V_95 , V_5 -> V_34 ) ;
if ( V_5 -> V_4 . V_36 > 0 )
F_110 ( & V_5 -> V_31 -> V_95 , V_5 -> V_34 , V_5 -> V_4 . V_25 . V_26 ) ;
}
static void F_173 ( struct V_5 * V_5 )
{
if ( V_5 -> V_4 . V_29 )
F_25 ( V_5 ) ;
F_112 ( & V_5 -> V_31 -> V_95 , V_5 -> V_34 ) ;
F_174 ( & V_5 -> V_31 -> V_95 , V_5 -> V_34 ) ;
}
void T_4 F_175 ( void )
{
unsigned int V_135 ;
F_176 (i)
F_177 ( & F_47 ( V_115 , V_135 ) ,
V_136 , F_178 ( V_135 ) ) ;
}
static void F_179 ( struct V_5 * V_5 , struct V_1 * V_7 )
{
if ( ! F_67 ( V_7 ) )
F_79 ( V_7 ) ;
if ( ! F_82 ( V_7 ) || V_5 -> V_4 . V_36 )
return;
F_48 ( V_5 ) ;
}
static void F_180 ( struct V_5 * V_5 , struct V_1 * V_7 )
{
if ( ! F_82 ( V_7 ) )
return;
if ( F_60 ( V_7 -> V_4 . V_46 , F_61 ( V_5 ) ) )
F_58 ( & V_7 -> V_4 ) ;
if ( V_5 -> V_26 != V_7 ) {
#ifdef F_18
if ( V_7 -> V_37 > 1 && V_5 -> V_4 . V_29 )
F_45 ( V_5 ) ;
#endif
if ( F_44 ( V_5 -> V_26 ) )
F_87 ( V_5 , V_7 , 0 ) ;
else
F_88 ( V_5 ) ;
}
}
static void F_181 ( struct V_5 * V_5 , struct V_1 * V_7 ,
int V_137 )
{
if ( F_82 ( V_7 ) || V_5 -> V_26 == V_7 ) {
#ifdef F_18
if ( ! V_5 -> V_4 . V_29 )
F_48 ( V_5 ) ;
if ( F_60 ( V_5 -> V_4 . V_25 . V_26 , V_7 -> V_4 . V_46 ) )
F_88 ( V_5 ) ;
#else
F_88 ( V_5 ) ;
#endif
}
}
void F_182 ( struct V_138 * V_139 , int V_34 )
{
F_183 ( V_139 , V_34 , & F_54 ( V_34 ) -> V_4 ) ;
}
