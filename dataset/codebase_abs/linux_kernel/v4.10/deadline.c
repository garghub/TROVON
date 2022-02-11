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
if ( F_30 ( V_7 ) > 1 )
V_6 -> V_28 ++ ;
F_28 ( V_6 ) ;
}
static void F_31 ( struct V_2 * V_3 , struct V_6 * V_6 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
if ( F_30 ( V_7 ) > 1 )
V_6 -> V_28 -- ;
F_28 ( V_6 ) ;
}
static void F_32 ( struct V_5 * V_5 , struct V_1 * V_7 )
{
struct V_6 * V_6 = & V_5 -> V_4 ;
struct V_8 * * V_37 = & V_6 -> V_30 . V_8 ;
struct V_8 * V_38 = NULL ;
struct V_1 * V_39 ;
int V_40 = 1 ;
F_33 ( ! F_7 ( & V_7 -> V_41 ) ) ;
while ( * V_37 ) {
V_38 = * V_37 ;
V_39 = F_34 ( V_38 , struct V_1 ,
V_41 ) ;
if ( F_35 ( & V_7 -> V_4 , & V_39 -> V_4 ) )
V_37 = & V_38 -> V_42 ;
else {
V_37 = & V_38 -> V_43 ;
V_40 = 0 ;
}
}
if ( V_40 ) {
V_6 -> V_44 = & V_7 -> V_41 ;
V_6 -> V_25 . V_27 = V_7 -> V_4 . V_45 ;
}
F_36 ( & V_7 -> V_41 , V_38 , V_37 ) ;
F_37 ( & V_7 -> V_41 , & V_6 -> V_30 ) ;
}
static void F_38 ( struct V_5 * V_5 , struct V_1 * V_7 )
{
struct V_6 * V_6 = & V_5 -> V_4 ;
if ( F_7 ( & V_7 -> V_41 ) )
return;
if ( V_6 -> V_44 == & V_7 -> V_41 ) {
struct V_8 * V_46 ;
V_46 = F_39 ( & V_7 -> V_41 ) ;
V_6 -> V_44 = V_46 ;
if ( V_46 ) {
V_6 -> V_25 . V_27 = F_34 ( V_46 ,
struct V_1 , V_41 ) -> V_4 . V_45 ;
}
}
F_40 ( & V_7 -> V_41 , & V_6 -> V_30 ) ;
F_41 ( & V_7 -> V_41 ) ;
}
static inline int F_42 ( struct V_5 * V_5 )
{
return ! F_43 ( & V_5 -> V_4 . V_30 ) ;
}
static inline bool F_44 ( struct V_5 * V_5 , struct V_1 * V_47 )
{
return F_45 ( V_47 ) ;
}
static inline void F_46 ( struct V_5 * V_5 )
{
if ( ! F_42 ( V_5 ) )
return;
F_47 ( V_5 , & F_48 ( V_48 , V_5 -> V_34 ) , V_49 ) ;
}
static inline void F_49 ( struct V_5 * V_5 )
{
F_47 ( V_5 , & F_48 ( V_50 , V_5 -> V_34 ) , V_51 ) ;
}
static struct V_5 * F_50 ( struct V_5 * V_5 , struct V_1 * V_7 )
{
struct V_5 * V_52 = NULL ;
V_52 = F_51 ( V_7 , V_5 ) ;
if ( ! V_52 ) {
int V_34 ;
V_34 = F_52 ( V_53 , F_53 ( V_7 ) ) ;
if ( V_34 >= V_54 ) {
F_33 ( F_54 () ) ;
V_34 = F_55 ( V_53 ) ;
}
V_52 = F_56 ( V_34 ) ;
F_57 ( V_5 , V_52 ) ;
}
F_58 ( V_7 , V_52 -> V_34 ) ;
F_59 ( V_52 , V_5 ) ;
return V_52 ;
}
static inline
void F_32 ( struct V_5 * V_5 , struct V_1 * V_7 )
{
}
static inline
void F_38 ( struct V_5 * V_5 , struct V_1 * V_7 )
{
}
static inline
void F_29 ( struct V_2 * V_3 , struct V_6 * V_6 )
{
}
static inline
void F_31 ( struct V_2 * V_3 , struct V_6 * V_6 )
{
}
static inline bool F_44 ( struct V_5 * V_5 , struct V_1 * V_47 )
{
return false ;
}
static inline void V_51 ( struct V_5 * V_5 )
{
}
static inline void F_46 ( struct V_5 * V_5 )
{
}
static inline void F_49 ( struct V_5 * V_5 )
{
}
static inline void F_60 ( struct V_2 * V_3 )
{
struct V_6 * V_6 = F_4 ( V_3 ) ;
struct V_5 * V_5 = F_3 ( V_6 ) ;
F_61 ( V_3 -> V_55 ) ;
F_61 ( F_62 ( F_63 ( V_5 ) , V_3 -> V_45 ) ) ;
if ( V_3 -> V_56 )
return;
V_3 -> V_45 = F_63 ( V_5 ) + V_3 -> V_57 ;
V_3 -> V_13 = V_3 -> V_16 ;
}
static void F_64 ( struct V_2 * V_3 ,
struct V_2 * V_58 )
{
struct V_6 * V_6 = F_4 ( V_3 ) ;
struct V_5 * V_5 = F_3 ( V_6 ) ;
F_33 ( V_58 -> V_16 <= 0 ) ;
if ( V_3 -> V_57 == 0 ) {
V_3 -> V_45 = F_63 ( V_5 ) + V_58 -> V_57 ;
V_3 -> V_13 = V_58 -> V_16 ;
}
if ( V_3 -> V_59 && V_3 -> V_13 > 0 )
V_3 -> V_13 = 0 ;
while ( V_3 -> V_13 <= 0 ) {
V_3 -> V_45 += V_58 -> V_15 ;
V_3 -> V_13 += V_58 -> V_16 ;
}
if ( F_62 ( V_3 -> V_45 , F_63 ( V_5 ) ) ) {
F_65 ( L_1 ) ;
V_3 -> V_45 = F_63 ( V_5 ) + V_58 -> V_57 ;
V_3 -> V_13 = V_58 -> V_16 ;
}
if ( V_3 -> V_59 )
V_3 -> V_59 = 0 ;
if ( V_3 -> V_56 )
V_3 -> V_56 = 0 ;
}
static bool F_66 ( struct V_2 * V_3 ,
struct V_2 * V_58 , T_1 V_60 )
{
T_1 V_61 , V_62 ;
V_61 = ( V_58 -> V_15 >> V_63 ) * ( V_3 -> V_13 >> V_63 ) ;
V_62 = ( ( V_3 -> V_45 - V_60 ) >> V_63 ) *
( V_58 -> V_16 >> V_63 ) ;
return F_62 ( V_62 , V_61 ) ;
}
static void F_67 ( struct V_2 * V_3 ,
struct V_2 * V_58 )
{
struct V_6 * V_6 = F_4 ( V_3 ) ;
struct V_5 * V_5 = F_3 ( V_6 ) ;
if ( F_62 ( V_3 -> V_45 , F_63 ( V_5 ) ) ||
F_66 ( V_3 , V_58 , F_63 ( V_5 ) ) ) {
V_3 -> V_45 = F_63 ( V_5 ) + V_58 -> V_57 ;
V_3 -> V_13 = V_58 -> V_16 ;
}
}
static int F_68 ( struct V_1 * V_7 )
{
struct V_2 * V_3 = & V_7 -> V_4 ;
struct V_64 * V_65 = & V_3 -> V_66 ;
struct V_5 * V_5 = F_5 ( V_7 ) ;
T_2 V_67 , V_68 ;
T_3 V_69 ;
F_69 ( & V_5 -> V_18 ) ;
V_68 = F_70 ( V_3 -> V_45 ) ;
V_67 = F_71 ( V_65 ) ;
V_69 = F_72 ( V_67 ) - F_63 ( V_5 ) ;
V_68 = F_73 ( V_68 , V_69 ) ;
if ( F_74 ( V_68 , V_67 ) < 0 )
return 0 ;
if ( ! F_75 ( V_65 ) ) {
F_76 ( V_7 ) ;
F_77 ( V_65 , V_68 , V_70 ) ;
}
return 1 ;
}
static enum V_71 F_78 ( struct V_64 * V_65 )
{
struct V_2 * V_3 = F_2 ( V_65 ,
struct V_2 ,
V_66 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_72 V_73 ;
struct V_5 * V_5 ;
V_5 = F_79 ( V_7 , & V_73 ) ;
if ( ! F_45 ( V_7 ) ) {
F_80 ( V_7 ) ;
goto V_74;
}
if ( V_3 -> V_55 )
goto V_74;
if ( ! V_3 -> V_56 )
goto V_74;
F_81 () ;
F_82 ( V_5 ) ;
if ( ! F_83 ( V_7 ) ) {
F_64 ( V_3 , V_3 ) ;
goto V_74;
}
#ifdef F_18
if ( F_84 ( ! V_5 -> V_33 ) ) {
F_85 ( & V_5 -> V_18 , V_73 . V_75 ) ;
V_5 = F_50 ( V_5 , V_7 ) ;
V_73 . V_75 = F_86 ( & V_5 -> V_18 ) ;
}
#endif
F_87 ( V_5 , V_7 , V_76 ) ;
if ( F_45 ( V_5 -> V_26 ) )
F_88 ( V_5 , V_7 , 0 ) ;
else
F_89 ( V_5 ) ;
#ifdef F_18
if ( F_42 ( V_5 ) ) {
F_85 ( & V_5 -> V_18 , V_73 . V_75 ) ;
F_90 ( V_5 ) ;
F_91 ( & V_5 -> V_18 , V_73 . V_75 ) ;
}
#endif
V_74:
F_92 ( V_5 , V_7 , & V_73 ) ;
F_93 ( V_7 ) ;
return V_77 ;
}
void F_94 ( struct V_2 * V_3 )
{
struct V_64 * V_65 = & V_3 -> V_66 ;
F_95 ( V_65 , V_78 , V_79 ) ;
V_65 -> V_80 = F_78 ;
}
static
int F_96 ( struct V_2 * V_3 )
{
return ( V_3 -> V_13 <= 0 ) ;
}
static void F_97 ( struct V_5 * V_5 )
{
struct V_1 * V_26 = V_5 -> V_26 ;
struct V_2 * V_3 = & V_26 -> V_4 ;
T_1 V_81 ;
if ( ! F_45 ( V_26 ) || ! F_6 ( V_3 ) )
return;
V_81 = F_98 ( V_5 ) - V_26 -> V_82 . V_83 ;
if ( F_84 ( ( T_3 ) V_81 <= 0 ) ) {
if ( F_84 ( V_3 -> V_59 ) )
goto V_84;
return;
}
F_99 ( V_5 , V_85 ) ;
F_100 ( V_26 -> V_82 . V_86 . V_87 ,
F_101 ( V_26 -> V_82 . V_86 . V_87 , V_81 ) ) ;
V_26 -> V_82 . V_88 += V_81 ;
F_102 ( V_26 , V_81 ) ;
V_26 -> V_82 . V_83 = F_98 ( V_5 ) ;
F_103 ( V_26 , V_81 ) ;
F_104 ( V_5 , V_81 ) ;
V_3 -> V_13 -= V_81 ;
V_84:
if ( F_96 ( V_3 ) || V_3 -> V_59 ) {
V_3 -> V_56 = 1 ;
F_105 ( V_5 , V_26 , 0 ) ;
if ( F_84 ( V_3 -> V_55 || ! F_68 ( V_26 ) ) )
F_87 ( V_5 , V_26 , V_76 ) ;
if ( ! F_8 ( V_26 , & V_5 -> V_4 ) )
F_89 ( V_5 ) ;
}
if ( F_106 () ) {
struct V_89 * V_89 = & V_5 -> V_90 ;
F_12 ( & V_89 -> V_91 ) ;
if ( F_107 ( V_89 ) )
V_89 -> V_92 += V_81 ;
F_16 ( & V_89 -> V_91 ) ;
}
}
static void F_108 ( struct V_6 * V_6 , T_1 V_45 )
{
struct V_5 * V_5 = F_3 ( V_6 ) ;
if ( V_6 -> V_25 . V_26 == 0 ||
F_62 ( V_45 , V_6 -> V_25 . V_26 ) ) {
V_6 -> V_25 . V_26 = V_45 ;
F_109 ( & V_5 -> V_31 -> V_93 , V_5 -> V_34 , V_45 ) ;
}
}
static void F_110 ( struct V_6 * V_6 , T_1 V_45 )
{
struct V_5 * V_5 = F_3 ( V_6 ) ;
if ( ! V_6 -> V_36 ) {
V_6 -> V_25 . V_26 = 0 ;
V_6 -> V_25 . V_27 = 0 ;
F_111 ( & V_5 -> V_31 -> V_93 , V_5 -> V_34 ) ;
} else {
struct V_8 * V_40 = V_6 -> V_9 ;
struct V_2 * V_39 ;
V_39 = F_34 ( V_40 , struct V_2 , V_8 ) ;
V_6 -> V_25 . V_26 = V_39 -> V_45 ;
F_109 ( & V_5 -> V_31 -> V_93 , V_5 -> V_34 , V_39 -> V_45 ) ;
}
}
static inline void F_108 ( struct V_6 * V_6 , T_1 V_45 ) {}
static inline void F_110 ( struct V_6 * V_6 , T_1 V_45 ) {}
static inline
void F_112 ( struct V_2 * V_3 , struct V_6 * V_6 )
{
int V_94 = F_1 ( V_3 ) -> V_94 ;
T_1 V_45 = V_3 -> V_45 ;
F_61 ( ! F_113 ( V_94 ) ) ;
V_6 -> V_36 ++ ;
F_114 ( F_3 ( V_6 ) , 1 ) ;
F_108 ( V_6 , V_45 ) ;
F_29 ( V_3 , V_6 ) ;
}
static inline
void F_115 ( struct V_2 * V_3 , struct V_6 * V_6 )
{
int V_94 = F_1 ( V_3 ) -> V_94 ;
F_61 ( ! F_113 ( V_94 ) ) ;
F_61 ( ! V_6 -> V_36 ) ;
V_6 -> V_36 -- ;
F_116 ( F_3 ( V_6 ) , 1 ) ;
F_110 ( V_6 , V_3 -> V_45 ) ;
F_31 ( V_3 , V_6 ) ;
}
static void F_117 ( struct V_2 * V_3 )
{
struct V_6 * V_6 = F_4 ( V_3 ) ;
struct V_8 * * V_37 = & V_6 -> V_23 . V_8 ;
struct V_8 * V_38 = NULL ;
struct V_2 * V_39 ;
int V_40 = 1 ;
F_33 ( ! F_7 ( & V_3 -> V_8 ) ) ;
while ( * V_37 ) {
V_38 = * V_37 ;
V_39 = F_34 ( V_38 , struct V_2 , V_8 ) ;
if ( F_62 ( V_3 -> V_45 , V_39 -> V_45 ) )
V_37 = & V_38 -> V_42 ;
else {
V_37 = & V_38 -> V_43 ;
V_40 = 0 ;
}
}
if ( V_40 )
V_6 -> V_9 = & V_3 -> V_8 ;
F_36 ( & V_3 -> V_8 , V_38 , V_37 ) ;
F_37 ( & V_3 -> V_8 , & V_6 -> V_23 ) ;
F_112 ( V_3 , V_6 ) ;
}
static void F_118 ( struct V_2 * V_3 )
{
struct V_6 * V_6 = F_4 ( V_3 ) ;
if ( F_7 ( & V_3 -> V_8 ) )
return;
if ( V_6 -> V_9 == & V_3 -> V_8 ) {
struct V_8 * V_46 ;
V_46 = F_39 ( & V_3 -> V_8 ) ;
V_6 -> V_9 = V_46 ;
}
F_40 ( & V_3 -> V_8 , & V_6 -> V_23 ) ;
F_41 ( & V_3 -> V_8 ) ;
F_115 ( V_3 , V_6 ) ;
}
static void
F_119 ( struct V_2 * V_3 ,
struct V_2 * V_58 , int V_95 )
{
F_33 ( F_6 ( V_3 ) ) ;
if ( V_95 & V_96 )
F_67 ( V_3 , V_58 ) ;
else if ( V_95 & V_76 )
F_64 ( V_3 , V_58 ) ;
F_117 ( V_3 ) ;
}
static void F_120 ( struct V_2 * V_3 )
{
F_118 ( V_3 ) ;
}
static void F_87 ( struct V_5 * V_5 , struct V_1 * V_7 , int V_95 )
{
struct V_1 * V_97 = F_121 ( V_7 ) ;
struct V_2 * V_58 = & V_7 -> V_4 ;
if ( V_97 && V_7 -> V_4 . V_55 && F_113 ( V_97 -> V_98 ) ) {
V_58 = & V_97 -> V_4 ;
} else if ( ! F_113 ( V_7 -> V_98 ) ) {
F_33 ( ! V_7 -> V_4 . V_55 || V_95 != V_76 ) ;
return;
}
if ( V_7 -> V_4 . V_56 && ! ( V_95 & V_76 ) )
return;
F_119 ( & V_7 -> V_4 , V_58 , V_95 ) ;
if ( ! F_122 ( V_5 , V_7 ) && F_30 ( V_7 ) > 1 )
F_32 ( V_5 , V_7 ) ;
}
static void F_105 ( struct V_5 * V_5 , struct V_1 * V_7 , int V_95 )
{
F_120 ( & V_7 -> V_4 ) ;
F_38 ( V_5 , V_7 ) ;
}
static void F_123 ( struct V_5 * V_5 , struct V_1 * V_7 , int V_95 )
{
F_97 ( V_5 ) ;
F_105 ( V_5 , V_7 , V_95 ) ;
}
static void F_124 ( struct V_5 * V_5 )
{
V_5 -> V_26 -> V_4 . V_59 = 1 ;
F_82 ( V_5 ) ;
F_97 ( V_5 ) ;
F_125 ( V_5 , true ) ;
}
static int
F_126 ( struct V_1 * V_7 , int V_34 , int V_99 , int V_95 )
{
struct V_1 * V_26 ;
struct V_5 * V_5 ;
if ( V_99 != V_100 )
goto V_101;
V_5 = F_56 ( V_34 ) ;
F_127 () ;
V_26 = F_128 ( V_5 -> V_26 ) ;
if ( F_84 ( F_45 ( V_26 ) ) &&
( F_30 ( V_26 ) < 2 ||
! F_35 ( & V_7 -> V_4 , & V_26 -> V_4 ) ) &&
( F_30 ( V_7 ) > 1 ) ) {
int V_102 = F_129 ( V_7 ) ;
if ( V_102 != - 1 &&
( F_62 ( V_7 -> V_4 . V_45 ,
F_56 ( V_102 ) -> V_4 . V_25 . V_26 ) ||
( F_56 ( V_102 ) -> V_4 . V_36 == 0 ) ) )
V_34 = V_102 ;
}
F_130 () ;
V_101:
return V_34 ;
}
static void F_131 ( struct V_5 * V_5 , struct V_1 * V_7 )
{
if ( F_30 ( V_5 -> V_26 ) == 1 ||
F_132 ( & V_5 -> V_31 -> V_93 , V_5 -> V_26 , NULL ) == - 1 )
return;
if ( F_30 ( V_7 ) != 1 &&
F_132 ( & V_5 -> V_31 -> V_93 , V_7 , NULL ) != - 1 )
return;
F_89 ( V_5 ) ;
}
static void F_88 ( struct V_5 * V_5 , struct V_1 * V_7 ,
int V_95 )
{
if ( F_35 ( & V_7 -> V_4 , & V_5 -> V_26 -> V_4 ) ) {
F_89 ( V_5 ) ;
return;
}
#ifdef F_18
if ( ( V_7 -> V_4 . V_45 == V_5 -> V_26 -> V_4 . V_45 ) &&
! F_133 ( V_5 -> V_26 ) )
F_131 ( V_5 , V_7 ) ;
#endif
}
static void F_134 ( struct V_5 * V_5 , struct V_1 * V_7 )
{
F_135 ( V_5 , V_7 -> V_4 . V_13 ) ;
}
static void F_134 ( struct V_5 * V_5 , struct V_1 * V_7 )
{
}
static struct V_2 * F_136 ( struct V_5 * V_5 ,
struct V_6 * V_6 )
{
struct V_8 * V_61 = V_6 -> V_9 ;
if ( ! V_61 )
return NULL ;
return F_34 ( V_61 , struct V_2 , V_8 ) ;
}
struct V_1 *
F_137 ( struct V_5 * V_5 , struct V_1 * V_47 , struct V_103 V_75 )
{
struct V_2 * V_3 ;
struct V_1 * V_7 ;
struct V_6 * V_6 ;
V_6 = & V_5 -> V_4 ;
if ( F_44 ( V_5 , V_47 ) ) {
F_85 ( & V_5 -> V_18 , V_75 ) ;
V_51 ( V_5 ) ;
F_91 ( & V_5 -> V_18 , V_75 ) ;
if ( V_5 -> V_104 && F_83 ( V_5 -> V_104 ) )
return V_105 ;
}
if ( V_47 -> V_106 == & V_107 )
F_97 ( V_5 ) ;
if ( F_84 ( ! V_6 -> V_36 ) )
return NULL ;
F_138 ( V_5 , V_47 ) ;
V_3 = F_136 ( V_5 , V_6 ) ;
F_33 ( ! V_3 ) ;
V_7 = F_1 ( V_3 ) ;
V_7 -> V_82 . V_83 = F_98 ( V_5 ) ;
F_38 ( V_5 , V_7 ) ;
if ( F_139 ( V_5 ) )
F_134 ( V_5 , V_7 ) ;
F_46 ( V_5 ) ;
return V_7 ;
}
static void F_140 ( struct V_5 * V_5 , struct V_1 * V_7 )
{
F_97 ( V_5 ) ;
if ( F_6 ( & V_7 -> V_4 ) && F_30 ( V_7 ) > 1 )
F_32 ( V_5 , V_7 ) ;
}
static void F_141 ( struct V_5 * V_5 , struct V_1 * V_7 , int V_108 )
{
F_97 ( V_5 ) ;
if ( F_139 ( V_5 ) && V_108 && V_7 -> V_4 . V_13 > 0 &&
F_8 ( V_7 , & V_5 -> V_4 ) )
F_134 ( V_5 , V_7 ) ;
}
static void F_142 ( struct V_1 * V_7 )
{
}
static void F_143 ( struct V_1 * V_7 )
{
struct V_17 * V_11 = F_144 ( F_145 ( V_7 ) ) ;
F_146 ( & V_11 -> V_18 ) ;
V_11 -> V_22 -= V_7 -> V_4 . V_17 ;
F_147 ( & V_11 -> V_18 ) ;
}
static void F_148 ( struct V_5 * V_5 )
{
struct V_1 * V_7 = V_5 -> V_26 ;
V_7 -> V_82 . V_83 = F_98 ( V_5 ) ;
F_38 ( V_5 , V_7 ) ;
}
static int F_149 ( struct V_5 * V_5 , struct V_1 * V_7 , int V_34 )
{
if ( ! F_150 ( V_5 , V_7 ) &&
F_151 ( V_34 , F_53 ( V_7 ) ) )
return 1 ;
return 0 ;
}
static struct V_1 * F_152 ( struct V_5 * V_5 , int V_34 )
{
struct V_8 * V_46 = V_5 -> V_4 . V_44 ;
struct V_1 * V_7 = NULL ;
if ( ! F_42 ( V_5 ) )
return NULL ;
V_46:
if ( V_46 ) {
V_7 = F_34 ( V_46 , struct V_1 , V_41 ) ;
if ( F_149 ( V_5 , V_7 , V_34 ) )
return V_7 ;
V_46 = F_39 ( V_46 ) ;
goto V_46;
}
return NULL ;
}
static int F_129 ( struct V_1 * V_109 )
{
struct V_110 * V_111 ;
struct V_112 * V_113 = F_153 ( V_114 ) ;
int V_115 = F_154 () ;
int V_116 , V_34 = F_145 ( V_109 ) ;
if ( F_84 ( ! V_113 ) )
return - 1 ;
if ( F_30 ( V_109 ) == 1 )
return - 1 ;
V_116 = F_132 ( & F_5 ( V_109 ) -> V_31 -> V_93 ,
V_109 , V_113 ) ;
if ( V_116 == - 1 )
return - 1 ;
if ( F_151 ( V_34 , V_113 ) )
return V_34 ;
if ( ! F_151 ( V_115 , V_113 ) )
V_115 = - 1 ;
F_127 () ;
F_155 (cpu, sd) {
if ( V_111 -> V_95 & V_117 ) {
if ( V_115 != - 1 &&
F_151 ( V_115 , F_156 ( V_111 ) ) ) {
F_130 () ;
return V_115 ;
}
if ( V_116 < V_54 &&
F_151 ( V_116 , F_156 ( V_111 ) ) ) {
F_130 () ;
return V_116 ;
}
}
}
F_130 () ;
if ( V_115 != - 1 )
return V_115 ;
V_34 = F_55 ( V_113 ) ;
if ( V_34 < V_54 )
return V_34 ;
return - 1 ;
}
static struct V_5 * F_51 ( struct V_1 * V_109 , struct V_5 * V_5 )
{
struct V_5 * V_52 = NULL ;
int V_118 ;
int V_34 ;
for ( V_118 = 0 ; V_118 < V_119 ; V_118 ++ ) {
V_34 = F_129 ( V_109 ) ;
if ( ( V_34 == - 1 ) || ( V_34 == V_5 -> V_34 ) )
break;
V_52 = F_56 ( V_34 ) ;
if ( V_52 -> V_4 . V_36 &&
! F_62 ( V_109 -> V_4 . V_45 ,
V_52 -> V_4 . V_25 . V_26 ) ) {
V_52 = NULL ;
break;
}
if ( F_57 ( V_5 , V_52 ) ) {
if ( F_84 ( F_5 ( V_109 ) != V_5 ||
! F_151 ( V_52 -> V_34 ,
F_53 ( V_109 ) ) ||
F_150 ( V_5 , V_109 ) ||
! F_45 ( V_109 ) ||
! F_83 ( V_109 ) ) ) {
F_59 ( V_5 , V_52 ) ;
V_52 = NULL ;
break;
}
}
if ( ! V_52 -> V_4 . V_36 ||
F_62 ( V_109 -> V_4 . V_45 ,
V_52 -> V_4 . V_25 . V_26 ) )
break;
F_59 ( V_5 , V_52 ) ;
V_52 = NULL ;
}
return V_52 ;
}
static struct V_1 * F_157 ( struct V_5 * V_5 )
{
struct V_1 * V_7 ;
if ( ! F_42 ( V_5 ) )
return NULL ;
V_7 = F_34 ( V_5 -> V_4 . V_44 ,
struct V_1 , V_41 ) ;
F_33 ( V_5 -> V_34 != F_145 ( V_7 ) ) ;
F_33 ( F_122 ( V_5 , V_7 ) ) ;
F_33 ( F_30 ( V_7 ) <= 1 ) ;
F_33 ( ! F_83 ( V_7 ) ) ;
F_33 ( ! F_45 ( V_7 ) ) ;
return V_7 ;
}
static int F_90 ( struct V_5 * V_5 )
{
struct V_1 * V_120 ;
struct V_5 * V_52 ;
int V_121 = 0 ;
if ( ! V_5 -> V_4 . V_29 )
return 0 ;
V_120 = F_157 ( V_5 ) ;
if ( ! V_120 )
return 0 ;
V_122:
if ( F_84 ( V_120 == V_5 -> V_26 ) ) {
F_61 ( 1 ) ;
return 0 ;
}
if ( F_45 ( V_5 -> V_26 ) &&
F_62 ( V_120 -> V_4 . V_45 , V_5 -> V_26 -> V_4 . V_45 ) &&
F_30 ( V_5 -> V_26 ) > 1 ) {
F_89 ( V_5 ) ;
return 0 ;
}
F_76 ( V_120 ) ;
V_52 = F_51 ( V_120 , V_5 ) ;
if ( ! V_52 ) {
struct V_1 * V_109 ;
V_109 = F_157 ( V_5 ) ;
if ( F_145 ( V_120 ) == V_5 -> V_34 && V_109 == V_120 ) {
goto V_101;
}
if ( ! V_109 )
goto V_101;
F_93 ( V_120 ) ;
V_120 = V_109 ;
goto V_122;
}
F_158 ( V_5 , V_120 , 0 ) ;
F_58 ( V_120 , V_52 -> V_34 ) ;
F_159 ( V_52 , V_120 , 0 ) ;
V_121 = 1 ;
F_89 ( V_52 ) ;
F_59 ( V_5 , V_52 ) ;
V_101:
F_93 ( V_120 ) ;
return V_121 ;
}
static void V_49 ( struct V_5 * V_5 )
{
while ( F_90 ( V_5 ) )
;
}
static void V_51 ( struct V_5 * V_123 )
{
int V_115 = V_123 -> V_34 , V_34 ;
struct V_1 * V_7 ;
bool V_124 = false ;
struct V_5 * V_125 ;
T_1 V_126 = V_127 ;
if ( F_160 ( ! F_19 ( V_123 ) ) )
return;
F_161 () ;
F_162 (cpu, this_rq->rd->dlo_mask) {
if ( V_115 == V_34 )
continue;
V_125 = F_56 ( V_34 ) ;
if ( V_123 -> V_4 . V_36 &&
F_62 ( V_123 -> V_4 . V_25 . V_26 ,
V_125 -> V_4 . V_25 . V_27 ) )
continue;
F_57 ( V_123 , V_125 ) ;
if ( V_125 -> V_4 . V_36 <= 1 )
goto V_128;
V_7 = F_152 ( V_125 , V_115 ) ;
if ( V_7 && F_62 ( V_7 -> V_4 . V_45 , V_126 ) &&
( ! V_123 -> V_4 . V_36 ||
F_62 ( V_7 -> V_4 . V_45 ,
V_123 -> V_4 . V_25 . V_26 ) ) ) {
F_61 ( V_7 == V_125 -> V_26 ) ;
F_61 ( ! F_83 ( V_7 ) ) ;
if ( F_62 ( V_7 -> V_4 . V_45 ,
V_125 -> V_26 -> V_4 . V_45 ) )
goto V_128;
V_124 = true ;
F_158 ( V_125 , V_7 , 0 ) ;
F_58 ( V_7 , V_115 ) ;
F_159 ( V_123 , V_7 , 0 ) ;
V_126 = V_7 -> V_4 . V_45 ;
}
V_128:
F_59 ( V_123 , V_125 ) ;
}
if ( V_124 )
F_89 ( V_123 ) ;
}
static void F_163 ( struct V_5 * V_5 , struct V_1 * V_7 )
{
if ( ! F_150 ( V_5 , V_7 ) &&
! F_133 ( V_5 -> V_26 ) &&
F_30 ( V_7 ) > 1 &&
F_45 ( V_5 -> V_26 ) &&
( F_30 ( V_5 -> V_26 ) < 2 ||
! F_35 ( & V_7 -> V_4 , & V_5 -> V_26 -> V_4 ) ) ) {
V_49 ( V_5 ) ;
}
}
static void F_164 ( struct V_1 * V_7 ,
const struct V_112 * V_129 )
{
struct V_130 * V_131 ;
struct V_5 * V_5 ;
F_33 ( ! F_45 ( V_7 ) ) ;
V_5 = F_5 ( V_7 ) ;
V_131 = V_5 -> V_31 ;
if ( ! F_165 ( V_131 -> V_132 , V_129 ) ) {
struct V_17 * V_133 ;
V_133 = F_144 ( F_166 ( V_5 ) ) ;
F_12 ( & V_133 -> V_18 ) ;
F_167 ( V_133 , V_7 -> V_4 . V_17 ) ;
F_16 ( & V_133 -> V_18 ) ;
}
F_168 ( V_7 , V_129 ) ;
}
static void F_169 ( struct V_5 * V_5 )
{
if ( V_5 -> V_4 . V_29 )
F_21 ( V_5 ) ;
F_170 ( & V_5 -> V_31 -> V_93 , V_5 -> V_34 ) ;
if ( V_5 -> V_4 . V_36 > 0 )
F_109 ( & V_5 -> V_31 -> V_93 , V_5 -> V_34 , V_5 -> V_4 . V_25 . V_26 ) ;
}
static void F_171 ( struct V_5 * V_5 )
{
if ( V_5 -> V_4 . V_29 )
F_25 ( V_5 ) ;
F_111 ( & V_5 -> V_31 -> V_93 , V_5 -> V_34 ) ;
F_172 ( & V_5 -> V_31 -> V_93 , V_5 -> V_34 ) ;
}
void T_4 F_173 ( void )
{
unsigned int V_134 ;
F_174 (i)
F_175 ( & F_48 ( V_114 , V_134 ) ,
V_135 , F_176 ( V_134 ) ) ;
}
static void F_177 ( struct V_5 * V_5 , struct V_1 * V_7 )
{
if ( ! F_68 ( V_7 ) )
F_80 ( V_7 ) ;
if ( ! F_83 ( V_7 ) || V_5 -> V_4 . V_36 )
return;
F_49 ( V_5 ) ;
}
static void F_178 ( struct V_5 * V_5 , struct V_1 * V_7 )
{
if ( ! F_83 ( V_7 ) )
return;
if ( F_62 ( V_7 -> V_4 . V_45 , F_63 ( V_5 ) ) )
F_60 ( & V_7 -> V_4 ) ;
if ( V_5 -> V_26 != V_7 ) {
#ifdef F_18
if ( F_30 ( V_7 ) > 1 && V_5 -> V_4 . V_29 )
F_46 ( V_5 ) ;
#else
if ( F_45 ( V_5 -> V_26 ) )
F_88 ( V_5 , V_7 , 0 ) ;
else
F_89 ( V_5 ) ;
#endif
}
}
static void F_179 ( struct V_5 * V_5 , struct V_1 * V_7 ,
int V_136 )
{
if ( F_83 ( V_7 ) || V_5 -> V_26 == V_7 ) {
#ifdef F_18
if ( ! V_5 -> V_4 . V_29 )
F_49 ( V_5 ) ;
if ( F_62 ( V_5 -> V_4 . V_25 . V_26 , V_7 -> V_4 . V_45 ) )
F_89 ( V_5 ) ;
#else
F_89 ( V_5 ) ;
#endif
}
}
void F_180 ( struct V_137 * V_138 , int V_34 )
{
F_181 ( V_138 , V_34 , & F_56 ( V_34 ) -> V_4 ) ;
}
