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
bool V_54 = false ;
V_53 = F_50 ( V_7 , V_5 ) ;
if ( ! V_53 ) {
int V_34 ;
V_54 = true ;
V_34 = F_51 ( V_55 , F_52 ( V_7 ) ) ;
if ( V_34 >= V_56 ) {
F_32 ( F_53 () ) ;
V_34 = F_54 ( V_55 ) ;
}
V_53 = F_55 ( V_34 ) ;
F_56 ( V_5 , V_53 ) ;
}
F_57 ( V_5 , V_7 , 0 ) ;
F_58 ( V_7 , V_53 -> V_34 ) ;
F_59 ( V_53 , V_7 , 0 ) ;
if ( ! V_54 )
F_60 ( V_53 ) ;
F_61 ( V_53 , V_5 ) ;
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
static inline void F_62 ( struct V_2 * V_3 ,
struct V_2 * V_57 )
{
struct V_6 * V_6 = F_4 ( V_3 ) ;
struct V_5 * V_5 = F_3 ( V_6 ) ;
F_63 ( ! V_3 -> V_58 || V_3 -> V_59 ) ;
V_3 -> V_46 = F_64 ( V_5 ) + V_57 -> V_60 ;
V_3 -> V_13 = V_57 -> V_16 ;
V_3 -> V_58 = 0 ;
}
static void F_65 ( struct V_2 * V_3 ,
struct V_2 * V_57 )
{
struct V_6 * V_6 = F_4 ( V_3 ) ;
struct V_5 * V_5 = F_3 ( V_6 ) ;
F_32 ( V_57 -> V_16 <= 0 ) ;
if ( V_3 -> V_60 == 0 ) {
V_3 -> V_46 = F_64 ( V_5 ) + V_57 -> V_60 ;
V_3 -> V_13 = V_57 -> V_16 ;
}
while ( V_3 -> V_13 <= 0 ) {
V_3 -> V_46 += V_57 -> V_15 ;
V_3 -> V_13 += V_57 -> V_16 ;
}
if ( F_66 ( V_3 -> V_46 , F_64 ( V_5 ) ) ) {
F_67 ( L_1 ) ;
V_3 -> V_46 = F_64 ( V_5 ) + V_57 -> V_60 ;
V_3 -> V_13 = V_57 -> V_16 ;
}
if ( V_3 -> V_61 )
V_3 -> V_61 = 0 ;
if ( V_3 -> V_59 )
V_3 -> V_59 = 0 ;
}
static bool F_68 ( struct V_2 * V_3 ,
struct V_2 * V_57 , T_1 V_62 )
{
T_1 V_63 , V_64 ;
V_63 = ( V_57 -> V_15 >> V_65 ) * ( V_3 -> V_13 >> V_65 ) ;
V_64 = ( ( V_3 -> V_46 - V_62 ) >> V_65 ) *
( V_57 -> V_16 >> V_65 ) ;
return F_66 ( V_64 , V_63 ) ;
}
static void F_69 ( struct V_2 * V_3 ,
struct V_2 * V_57 )
{
struct V_6 * V_6 = F_4 ( V_3 ) ;
struct V_5 * V_5 = F_3 ( V_6 ) ;
if ( V_3 -> V_58 ) {
F_62 ( V_3 , V_57 ) ;
return;
}
if ( F_66 ( V_3 -> V_46 , F_64 ( V_5 ) ) ||
F_68 ( V_3 , V_57 , F_64 ( V_5 ) ) ) {
V_3 -> V_46 = F_64 ( V_5 ) + V_57 -> V_60 ;
V_3 -> V_13 = V_57 -> V_16 ;
}
}
static int F_70 ( struct V_1 * V_7 )
{
struct V_2 * V_3 = & V_7 -> V_4 ;
struct V_66 * V_67 = & V_3 -> V_68 ;
struct V_5 * V_5 = F_5 ( V_7 ) ;
T_2 V_69 , V_70 ;
T_3 V_71 ;
F_71 ( & V_5 -> V_18 ) ;
V_70 = F_72 ( V_3 -> V_46 ) ;
V_69 = F_73 ( V_67 ) ;
V_71 = F_74 ( V_69 ) - F_64 ( V_5 ) ;
V_70 = F_75 ( V_70 , V_71 ) ;
if ( F_76 ( V_70 , V_69 ) < 0 )
return 0 ;
if ( ! F_77 ( V_67 ) ) {
F_78 ( V_7 ) ;
F_79 ( V_67 , V_70 , V_72 ) ;
}
return 1 ;
}
static enum V_73 F_80 ( struct V_66 * V_67 )
{
struct V_2 * V_3 = F_2 ( V_67 ,
struct V_2 ,
V_68 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
unsigned long V_74 ;
struct V_5 * V_5 ;
V_5 = F_81 ( V_7 , & V_74 ) ;
if ( ! F_44 ( V_7 ) ) {
F_82 ( V_7 ) ;
goto V_75;
}
if ( V_3 -> V_58 )
goto V_75;
if ( V_3 -> V_76 )
goto V_75;
if ( ! V_3 -> V_59 )
goto V_75;
F_83 () ;
F_84 ( V_5 ) ;
if ( ! F_85 ( V_7 ) ) {
F_65 ( V_3 , V_3 ) ;
goto V_75;
}
F_86 ( V_5 , V_7 , V_77 ) ;
if ( F_44 ( V_5 -> V_26 ) )
F_87 ( V_5 , V_7 , 0 ) ;
else
F_60 ( V_5 ) ;
#ifdef F_18
if ( F_88 ( ! V_5 -> V_33 ) )
V_5 = F_49 ( V_5 , V_7 ) ;
if ( F_41 ( V_5 ) ) {
F_89 ( & V_5 -> V_18 ) ;
F_90 ( V_5 ) ;
F_91 ( & V_5 -> V_18 ) ;
}
#endif
V_75:
F_92 ( V_5 , V_7 , & V_74 ) ;
F_93 ( V_7 ) ;
return V_78 ;
}
void F_94 ( struct V_2 * V_3 )
{
struct V_66 * V_67 = & V_3 -> V_68 ;
F_95 ( V_67 , V_79 , V_80 ) ;
V_67 -> V_81 = F_80 ;
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
T_1 V_82 ;
if ( ! F_44 ( V_26 ) || ! F_6 ( V_3 ) )
return;
V_82 = F_98 ( V_5 ) - V_26 -> V_83 . V_84 ;
if ( F_88 ( ( T_3 ) V_82 <= 0 ) )
return;
F_99 ( V_26 -> V_83 . V_85 . V_86 ,
F_100 ( V_26 -> V_83 . V_85 . V_86 , V_82 ) ) ;
V_26 -> V_83 . V_87 += V_82 ;
F_101 ( V_26 , V_82 ) ;
V_26 -> V_83 . V_84 = F_98 ( V_5 ) ;
F_102 ( V_26 , V_82 ) ;
F_103 ( V_5 , V_82 ) ;
V_3 -> V_13 -= V_3 -> V_61 ? 0 : V_82 ;
if ( F_96 ( V_3 ) ) {
V_3 -> V_59 = 1 ;
F_104 ( V_5 , V_26 , 0 ) ;
if ( F_88 ( V_3 -> V_76 || ! F_70 ( V_26 ) ) )
F_86 ( V_5 , V_26 , V_77 ) ;
if ( ! F_8 ( V_26 , & V_5 -> V_4 ) )
F_60 ( V_5 ) ;
}
if ( F_105 () ) {
struct V_88 * V_88 = & V_5 -> V_89 ;
F_12 ( & V_88 -> V_90 ) ;
if ( F_106 ( V_88 ) )
V_88 -> V_91 += V_82 ;
F_16 ( & V_88 -> V_90 ) ;
}
}
static void F_107 ( struct V_6 * V_6 , T_1 V_46 )
{
struct V_5 * V_5 = F_3 ( V_6 ) ;
if ( V_6 -> V_25 . V_26 == 0 ||
F_66 ( V_46 , V_6 -> V_25 . V_26 ) ) {
V_6 -> V_25 . V_26 = V_46 ;
F_108 ( & V_5 -> V_31 -> V_92 , V_5 -> V_34 , V_46 , 1 ) ;
}
}
static void F_109 ( struct V_6 * V_6 , T_1 V_46 )
{
struct V_5 * V_5 = F_3 ( V_6 ) ;
if ( ! V_6 -> V_36 ) {
V_6 -> V_25 . V_26 = 0 ;
V_6 -> V_25 . V_27 = 0 ;
F_108 ( & V_5 -> V_31 -> V_92 , V_5 -> V_34 , 0 , 0 ) ;
} else {
struct V_8 * V_41 = V_6 -> V_9 ;
struct V_2 * V_40 ;
V_40 = F_33 ( V_41 , struct V_2 , V_8 ) ;
V_6 -> V_25 . V_26 = V_40 -> V_46 ;
F_108 ( & V_5 -> V_31 -> V_92 , V_5 -> V_34 , V_40 -> V_46 , 1 ) ;
}
}
static inline void F_107 ( struct V_6 * V_6 , T_1 V_46 ) {}
static inline void F_109 ( struct V_6 * V_6 , T_1 V_46 ) {}
static inline
void F_110 ( struct V_2 * V_3 , struct V_6 * V_6 )
{
int V_93 = F_1 ( V_3 ) -> V_93 ;
T_1 V_46 = V_3 -> V_46 ;
F_63 ( ! F_111 ( V_93 ) ) ;
V_6 -> V_36 ++ ;
F_112 ( F_3 ( V_6 ) , 1 ) ;
F_107 ( V_6 , V_46 ) ;
F_29 ( V_3 , V_6 ) ;
}
static inline
void F_113 ( struct V_2 * V_3 , struct V_6 * V_6 )
{
int V_93 = F_1 ( V_3 ) -> V_93 ;
F_63 ( ! F_111 ( V_93 ) ) ;
F_63 ( ! V_6 -> V_36 ) ;
V_6 -> V_36 -- ;
F_114 ( F_3 ( V_6 ) , 1 ) ;
F_109 ( V_6 , V_3 -> V_46 ) ;
F_30 ( V_3 , V_6 ) ;
}
static void F_115 ( struct V_2 * V_3 )
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
if ( F_66 ( V_3 -> V_46 , V_40 -> V_46 ) )
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
F_110 ( V_3 , V_6 ) ;
}
static void F_116 ( struct V_2 * V_3 )
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
F_113 ( V_3 , V_6 ) ;
}
static void
F_117 ( struct V_2 * V_3 ,
struct V_2 * V_57 , int V_74 )
{
F_32 ( F_6 ( V_3 ) ) ;
if ( V_3 -> V_58 || V_74 & V_94 )
F_69 ( V_3 , V_57 ) ;
else if ( V_74 & V_77 )
F_65 ( V_3 , V_57 ) ;
F_115 ( V_3 ) ;
}
static void F_118 ( struct V_2 * V_3 )
{
F_116 ( V_3 ) ;
}
static void F_86 ( struct V_5 * V_5 , struct V_1 * V_7 , int V_74 )
{
struct V_1 * V_95 = F_119 ( V_7 ) ;
struct V_2 * V_57 = & V_7 -> V_4 ;
if ( V_95 && V_7 -> V_4 . V_76 && F_111 ( V_95 -> V_96 ) ) {
V_57 = & V_95 -> V_4 ;
} else if ( ! F_111 ( V_7 -> V_96 ) ) {
F_32 ( ! V_7 -> V_4 . V_76 || V_74 != V_77 ) ;
return;
}
if ( V_7 -> V_4 . V_59 && ! ( V_74 & V_77 ) )
return;
F_117 ( & V_7 -> V_4 , V_57 , V_74 ) ;
if ( ! F_120 ( V_5 , V_7 ) && V_7 -> V_37 > 1 )
F_31 ( V_5 , V_7 ) ;
}
static void F_104 ( struct V_5 * V_5 , struct V_1 * V_7 , int V_74 )
{
F_118 ( & V_7 -> V_4 ) ;
F_37 ( V_5 , V_7 ) ;
}
static void F_121 ( struct V_5 * V_5 , struct V_1 * V_7 , int V_74 )
{
F_97 ( V_5 ) ;
F_104 ( V_5 , V_7 , V_74 ) ;
}
static void F_122 ( struct V_5 * V_5 )
{
struct V_1 * V_7 = V_5 -> V_26 ;
if ( V_7 -> V_4 . V_13 > 0 ) {
V_5 -> V_26 -> V_4 . V_61 = 1 ;
V_7 -> V_4 . V_13 = 0 ;
}
F_84 ( V_5 ) ;
F_97 ( V_5 ) ;
F_123 ( V_5 , true ) ;
}
static int
F_124 ( struct V_1 * V_7 , int V_34 , int V_97 , int V_74 )
{
struct V_1 * V_26 ;
struct V_5 * V_5 ;
if ( V_97 != V_98 )
goto V_99;
V_5 = F_55 ( V_34 ) ;
F_125 () ;
V_26 = F_126 ( V_5 -> V_26 ) ;
if ( F_88 ( F_44 ( V_26 ) ) &&
( V_26 -> V_37 < 2 ||
! F_34 ( & V_7 -> V_4 , & V_26 -> V_4 ) ) &&
( V_7 -> V_37 > 1 ) ) {
int V_100 = F_127 ( V_7 ) ;
if ( V_100 != - 1 &&
( F_66 ( V_7 -> V_4 . V_46 ,
F_55 ( V_100 ) -> V_4 . V_25 . V_26 ) ||
( F_55 ( V_100 ) -> V_4 . V_36 == 0 ) ) )
V_34 = V_100 ;
}
F_128 () ;
V_99:
return V_34 ;
}
static void F_129 ( struct V_5 * V_5 , struct V_1 * V_7 )
{
if ( V_5 -> V_26 -> V_37 == 1 ||
F_130 ( & V_5 -> V_31 -> V_92 , V_5 -> V_26 , NULL ) == - 1 )
return;
if ( V_7 -> V_37 != 1 &&
F_130 ( & V_5 -> V_31 -> V_92 , V_7 , NULL ) != - 1 )
return;
F_60 ( V_5 ) ;
}
static void F_87 ( struct V_5 * V_5 , struct V_1 * V_7 ,
int V_74 )
{
if ( F_34 ( & V_7 -> V_4 , & V_5 -> V_26 -> V_4 ) ) {
F_60 ( V_5 ) ;
return;
}
#ifdef F_18
if ( ( V_7 -> V_4 . V_46 == V_5 -> V_26 -> V_4 . V_46 ) &&
! F_131 ( V_5 -> V_26 ) )
F_129 ( V_5 , V_7 ) ;
#endif
}
static void F_132 ( struct V_5 * V_5 , struct V_1 * V_7 )
{
F_133 ( V_5 , V_7 -> V_4 . V_13 ) ;
}
static void F_132 ( struct V_5 * V_5 , struct V_1 * V_7 )
{
}
static struct V_2 * F_134 ( struct V_5 * V_5 ,
struct V_6 * V_6 )
{
struct V_8 * V_63 = V_6 -> V_9 ;
if ( ! V_63 )
return NULL ;
return F_33 ( V_63 , struct V_2 , V_8 ) ;
}
struct V_1 * F_135 ( struct V_5 * V_5 , struct V_1 * V_48 )
{
struct V_2 * V_3 ;
struct V_1 * V_7 ;
struct V_6 * V_6 ;
V_6 = & V_5 -> V_4 ;
if ( F_43 ( V_5 , V_48 ) ) {
F_89 ( & V_5 -> V_18 ) ;
V_52 ( V_5 ) ;
F_91 ( & V_5 -> V_18 ) ;
if ( V_5 -> V_101 && F_85 ( V_5 -> V_101 ) )
return V_102 ;
}
if ( V_48 -> V_103 == & V_104 )
F_97 ( V_5 ) ;
if ( F_88 ( ! V_6 -> V_36 ) )
return NULL ;
F_136 ( V_5 , V_48 ) ;
V_3 = F_134 ( V_5 , V_6 ) ;
F_32 ( ! V_3 ) ;
V_7 = F_1 ( V_3 ) ;
V_7 -> V_83 . V_84 = F_98 ( V_5 ) ;
F_37 ( V_5 , V_7 ) ;
if ( F_137 ( V_5 ) )
F_132 ( V_5 , V_7 ) ;
F_45 ( V_5 ) ;
return V_7 ;
}
static void F_138 ( struct V_5 * V_5 , struct V_1 * V_7 )
{
F_97 ( V_5 ) ;
if ( F_6 ( & V_7 -> V_4 ) && V_7 -> V_37 > 1 )
F_31 ( V_5 , V_7 ) ;
}
static void F_139 ( struct V_5 * V_5 , struct V_1 * V_7 , int V_105 )
{
F_97 ( V_5 ) ;
if ( F_137 ( V_5 ) && V_105 && V_7 -> V_4 . V_13 > 0 &&
F_8 ( V_7 , & V_5 -> V_4 ) )
F_132 ( V_5 , V_7 ) ;
}
static void F_140 ( struct V_1 * V_7 )
{
}
static void F_141 ( struct V_1 * V_7 )
{
struct V_17 * V_11 = F_142 ( F_143 ( V_7 ) ) ;
F_144 ( & V_11 -> V_18 ) ;
V_11 -> V_22 -= V_7 -> V_4 . V_17 ;
F_145 ( & V_11 -> V_18 ) ;
}
static void F_146 ( struct V_5 * V_5 )
{
struct V_1 * V_7 = V_5 -> V_26 ;
V_7 -> V_83 . V_84 = F_98 ( V_5 ) ;
F_37 ( V_5 , V_7 ) ;
}
static int F_147 ( struct V_5 * V_5 , struct V_1 * V_7 , int V_34 )
{
if ( ! F_148 ( V_5 , V_7 ) &&
F_149 ( V_34 , F_52 ( V_7 ) ) )
return 1 ;
return 0 ;
}
static struct V_1 * F_150 ( struct V_5 * V_5 , int V_34 )
{
struct V_8 * V_47 = V_5 -> V_4 . V_45 ;
struct V_1 * V_7 = NULL ;
if ( ! F_41 ( V_5 ) )
return NULL ;
V_47:
if ( V_47 ) {
V_7 = F_33 ( V_47 , struct V_1 , V_42 ) ;
if ( F_147 ( V_5 , V_7 , V_34 ) )
return V_7 ;
V_47 = F_38 ( V_47 ) ;
goto V_47;
}
return NULL ;
}
static int F_127 ( struct V_1 * V_106 )
{
struct V_107 * V_108 ;
struct V_109 * V_110 = F_151 ( V_111 ) ;
int V_112 = F_152 () ;
int V_113 , V_34 = F_143 ( V_106 ) ;
if ( F_88 ( ! V_110 ) )
return - 1 ;
if ( V_106 -> V_37 == 1 )
return - 1 ;
V_113 = F_130 ( & F_5 ( V_106 ) -> V_31 -> V_92 ,
V_106 , V_110 ) ;
if ( V_113 == - 1 )
return - 1 ;
if ( F_149 ( V_34 , V_110 ) )
return V_34 ;
if ( ! F_149 ( V_112 , V_110 ) )
V_112 = - 1 ;
F_125 () ;
F_153 (cpu, sd) {
if ( V_108 -> V_74 & V_114 ) {
if ( V_112 != - 1 &&
F_149 ( V_112 , F_154 ( V_108 ) ) ) {
F_128 () ;
return V_112 ;
}
if ( V_113 < V_56 &&
F_149 ( V_113 , F_154 ( V_108 ) ) ) {
F_128 () ;
return V_113 ;
}
}
}
F_128 () ;
if ( V_112 != - 1 )
return V_112 ;
V_34 = F_54 ( V_110 ) ;
if ( V_34 < V_56 )
return V_34 ;
return - 1 ;
}
static struct V_5 * F_50 ( struct V_1 * V_106 , struct V_5 * V_5 )
{
struct V_5 * V_53 = NULL ;
int V_115 ;
int V_34 ;
for ( V_115 = 0 ; V_115 < V_116 ; V_115 ++ ) {
V_34 = F_127 ( V_106 ) ;
if ( ( V_34 == - 1 ) || ( V_34 == V_5 -> V_34 ) )
break;
V_53 = F_55 ( V_34 ) ;
if ( V_53 -> V_4 . V_36 &&
! F_66 ( V_106 -> V_4 . V_46 ,
V_53 -> V_4 . V_25 . V_26 ) ) {
V_53 = NULL ;
break;
}
if ( F_56 ( V_5 , V_53 ) ) {
if ( F_88 ( F_5 ( V_106 ) != V_5 ||
! F_149 ( V_53 -> V_34 ,
& V_106 -> V_117 ) ||
F_148 ( V_5 , V_106 ) ||
! F_85 ( V_106 ) ) ) {
F_61 ( V_5 , V_53 ) ;
V_53 = NULL ;
break;
}
}
if ( ! V_53 -> V_4 . V_36 ||
F_66 ( V_106 -> V_4 . V_46 ,
V_53 -> V_4 . V_25 . V_26 ) )
break;
F_61 ( V_5 , V_53 ) ;
V_53 = NULL ;
}
return V_53 ;
}
static struct V_1 * F_155 ( struct V_5 * V_5 )
{
struct V_1 * V_7 ;
if ( ! F_41 ( V_5 ) )
return NULL ;
V_7 = F_33 ( V_5 -> V_4 . V_45 ,
struct V_1 , V_42 ) ;
F_32 ( V_5 -> V_34 != F_143 ( V_7 ) ) ;
F_32 ( F_120 ( V_5 , V_7 ) ) ;
F_32 ( V_7 -> V_37 <= 1 ) ;
F_32 ( ! F_85 ( V_7 ) ) ;
F_32 ( ! F_44 ( V_7 ) ) ;
return V_7 ;
}
static int F_90 ( struct V_5 * V_5 )
{
struct V_1 * V_118 ;
struct V_5 * V_53 ;
int V_119 = 0 ;
if ( ! V_5 -> V_4 . V_29 )
return 0 ;
V_118 = F_155 ( V_5 ) ;
if ( ! V_118 )
return 0 ;
V_120:
if ( F_88 ( V_118 == V_5 -> V_26 ) ) {
F_63 ( 1 ) ;
return 0 ;
}
if ( F_44 ( V_5 -> V_26 ) &&
F_66 ( V_118 -> V_4 . V_46 , V_5 -> V_26 -> V_4 . V_46 ) &&
V_5 -> V_26 -> V_37 > 1 ) {
F_60 ( V_5 ) ;
return 0 ;
}
F_78 ( V_118 ) ;
V_53 = F_50 ( V_118 , V_5 ) ;
if ( ! V_53 ) {
struct V_1 * V_106 ;
V_106 = F_155 ( V_5 ) ;
if ( F_143 ( V_118 ) == V_5 -> V_34 && V_106 == V_118 ) {
goto V_99;
}
if ( ! V_106 )
goto V_99;
F_93 ( V_118 ) ;
V_118 = V_106 ;
goto V_120;
}
F_57 ( V_5 , V_118 , 0 ) ;
F_58 ( V_118 , V_53 -> V_34 ) ;
F_59 ( V_53 , V_118 , 0 ) ;
V_119 = 1 ;
F_60 ( V_53 ) ;
F_61 ( V_5 , V_53 ) ;
V_99:
F_93 ( V_118 ) ;
return V_119 ;
}
static void V_50 ( struct V_5 * V_5 )
{
while ( F_90 ( V_5 ) )
;
}
static void V_52 ( struct V_5 * V_121 )
{
int V_112 = V_121 -> V_34 , V_34 ;
struct V_1 * V_7 ;
bool V_122 = false ;
struct V_5 * V_123 ;
T_1 V_124 = V_125 ;
if ( F_156 ( ! F_19 ( V_121 ) ) )
return;
F_157 () ;
F_158 (cpu, this_rq->rd->dlo_mask) {
if ( V_112 == V_34 )
continue;
V_123 = F_55 ( V_34 ) ;
if ( V_121 -> V_4 . V_36 &&
F_66 ( V_121 -> V_4 . V_25 . V_26 ,
V_123 -> V_4 . V_25 . V_27 ) )
continue;
F_56 ( V_121 , V_123 ) ;
if ( V_123 -> V_4 . V_36 <= 1 )
goto V_126;
V_7 = F_150 ( V_123 , V_112 ) ;
if ( V_7 && F_66 ( V_7 -> V_4 . V_46 , V_124 ) &&
( ! V_121 -> V_4 . V_36 ||
F_66 ( V_7 -> V_4 . V_46 ,
V_121 -> V_4 . V_25 . V_26 ) ) ) {
F_63 ( V_7 == V_123 -> V_26 ) ;
F_63 ( ! F_85 ( V_7 ) ) ;
if ( F_66 ( V_7 -> V_4 . V_46 ,
V_123 -> V_26 -> V_4 . V_46 ) )
goto V_126;
V_122 = true ;
F_57 ( V_123 , V_7 , 0 ) ;
F_58 ( V_7 , V_112 ) ;
F_59 ( V_121 , V_7 , 0 ) ;
V_124 = V_7 -> V_4 . V_46 ;
}
V_126:
F_61 ( V_121 , V_123 ) ;
}
if ( V_122 )
F_60 ( V_121 ) ;
}
static void F_159 ( struct V_5 * V_5 , struct V_1 * V_7 )
{
if ( ! F_148 ( V_5 , V_7 ) &&
! F_131 ( V_5 -> V_26 ) &&
V_7 -> V_37 > 1 &&
F_44 ( V_5 -> V_26 ) &&
( V_5 -> V_26 -> V_37 < 2 ||
! F_34 ( & V_7 -> V_4 , & V_5 -> V_26 -> V_4 ) ) ) {
V_50 ( V_5 ) ;
}
}
static void F_160 ( struct V_1 * V_7 ,
const struct V_109 * V_127 )
{
struct V_128 * V_129 ;
struct V_5 * V_5 ;
F_32 ( ! F_44 ( V_7 ) ) ;
V_5 = F_5 ( V_7 ) ;
V_129 = V_5 -> V_31 ;
if ( ! F_161 ( V_129 -> V_130 , V_127 ) ) {
struct V_17 * V_131 ;
V_131 = F_142 ( F_162 ( V_5 ) ) ;
F_12 ( & V_131 -> V_18 ) ;
F_163 ( V_131 , V_7 -> V_4 . V_17 ) ;
F_16 ( & V_131 -> V_18 ) ;
}
F_164 ( V_7 , V_127 ) ;
}
static void F_165 ( struct V_5 * V_5 )
{
if ( V_5 -> V_4 . V_29 )
F_21 ( V_5 ) ;
F_166 ( & V_5 -> V_31 -> V_92 , V_5 -> V_34 ) ;
if ( V_5 -> V_4 . V_36 > 0 )
F_108 ( & V_5 -> V_31 -> V_92 , V_5 -> V_34 , V_5 -> V_4 . V_25 . V_26 , 1 ) ;
}
static void F_167 ( struct V_5 * V_5 )
{
if ( V_5 -> V_4 . V_29 )
F_25 ( V_5 ) ;
F_108 ( & V_5 -> V_31 -> V_92 , V_5 -> V_34 , 0 , 0 ) ;
F_168 ( & V_5 -> V_31 -> V_92 , V_5 -> V_34 ) ;
}
void T_4 F_169 ( void )
{
unsigned int V_132 ;
F_170 (i)
F_171 ( & F_47 ( V_111 , V_132 ) ,
V_133 , F_172 ( V_132 ) ) ;
}
static void F_173 ( struct V_5 * V_5 , struct V_1 * V_7 )
{
if ( ! F_70 ( V_7 ) )
F_82 ( V_7 ) ;
if ( ! F_85 ( V_7 ) || V_5 -> V_4 . V_36 )
return;
F_48 ( V_5 ) ;
}
static void F_174 ( struct V_5 * V_5 , struct V_1 * V_7 )
{
if ( F_85 ( V_7 ) && V_5 -> V_26 != V_7 ) {
#ifdef F_18
if ( V_7 -> V_37 > 1 && V_5 -> V_4 . V_29 )
F_45 ( V_5 ) ;
#else
if ( F_44 ( V_5 -> V_26 ) )
F_87 ( V_5 , V_7 , 0 ) ;
else
F_60 ( V_5 ) ;
#endif
}
}
static void F_175 ( struct V_5 * V_5 , struct V_1 * V_7 ,
int V_134 )
{
if ( F_85 ( V_7 ) || V_5 -> V_26 == V_7 ) {
#ifdef F_18
if ( ! V_5 -> V_4 . V_29 )
F_48 ( V_5 ) ;
if ( F_66 ( V_5 -> V_4 . V_25 . V_26 , V_7 -> V_4 . V_46 ) )
F_60 ( V_5 ) ;
#else
F_60 ( V_5 ) ;
#endif
} else
F_174 ( V_5 , V_7 ) ;
}
void F_176 ( struct V_135 * V_136 , int V_34 )
{
F_177 ( V_136 , V_34 , & F_55 ( V_34 ) -> V_4 ) ;
}
