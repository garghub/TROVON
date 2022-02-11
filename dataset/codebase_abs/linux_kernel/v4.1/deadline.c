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
if ( V_41 )
V_6 -> V_45 = & V_7 -> V_42 ;
F_35 ( & V_7 -> V_42 , V_39 , V_38 ) ;
F_36 ( & V_7 -> V_42 , & V_6 -> V_30 ) ;
}
static void F_37 ( struct V_5 * V_5 , struct V_1 * V_7 )
{
struct V_6 * V_6 = & V_5 -> V_4 ;
if ( F_7 ( & V_7 -> V_42 ) )
return;
if ( V_6 -> V_45 == & V_7 -> V_42 ) {
struct V_8 * V_46 ;
V_46 = F_38 ( & V_7 -> V_42 ) ;
V_6 -> V_45 = V_46 ;
}
F_39 ( & V_7 -> V_42 , & V_6 -> V_30 ) ;
F_40 ( & V_7 -> V_42 ) ;
}
static inline int F_41 ( struct V_5 * V_5 )
{
return ! F_42 ( & V_5 -> V_4 . V_30 ) ;
}
static inline bool F_43 ( struct V_5 * V_5 , struct V_1 * V_47 )
{
return F_44 ( V_47 ) ;
}
static inline void F_45 ( struct V_5 * V_5 )
{
V_5 -> V_48 = F_41 ( V_5 ) ;
}
static void F_46 ( struct V_5 * V_5 , struct V_1 * V_7 )
{
struct V_5 * V_49 = NULL ;
bool V_50 = false ;
V_49 = F_47 ( V_7 , V_5 ) ;
if ( ! V_49 ) {
int V_34 ;
V_50 = true ;
V_34 = F_48 ( V_51 , F_49 ( V_7 ) ) ;
if ( V_34 >= V_52 ) {
F_32 ( F_50 () ) ;
V_34 = F_51 ( V_51 ) ;
}
V_49 = F_52 ( V_34 ) ;
F_53 ( V_5 , V_49 ) ;
}
F_54 ( V_5 , V_7 , 0 ) ;
F_55 ( V_7 , V_49 -> V_34 ) ;
F_56 ( V_49 , V_7 , V_53 ) ;
if ( ! V_50 )
F_57 ( V_49 ) ;
F_58 ( V_5 , V_49 ) ;
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
static inline bool F_43 ( struct V_5 * V_5 , struct V_1 * V_47 )
{
return false ;
}
static inline int F_59 ( struct V_5 * V_5 )
{
return 0 ;
}
static inline void F_45 ( struct V_5 * V_5 )
{
}
static inline void F_60 ( struct V_2 * V_3 ,
struct V_2 * V_54 )
{
struct V_6 * V_6 = F_4 ( V_3 ) ;
struct V_5 * V_5 = F_3 ( V_6 ) ;
F_61 ( ! V_3 -> V_55 || V_3 -> V_56 ) ;
V_3 -> V_57 = F_62 ( V_5 ) + V_54 -> V_58 ;
V_3 -> V_13 = V_54 -> V_16 ;
V_3 -> V_55 = 0 ;
}
static void F_63 ( struct V_2 * V_3 ,
struct V_2 * V_54 )
{
struct V_6 * V_6 = F_4 ( V_3 ) ;
struct V_5 * V_5 = F_3 ( V_6 ) ;
F_32 ( V_54 -> V_16 <= 0 ) ;
if ( V_3 -> V_58 == 0 ) {
V_3 -> V_57 = F_62 ( V_5 ) + V_54 -> V_58 ;
V_3 -> V_13 = V_54 -> V_16 ;
}
while ( V_3 -> V_13 <= 0 ) {
V_3 -> V_57 += V_54 -> V_15 ;
V_3 -> V_13 += V_54 -> V_16 ;
}
if ( F_64 ( V_3 -> V_57 , F_62 ( V_5 ) ) ) {
F_65 ( L_1 ) ;
V_3 -> V_57 = F_62 ( V_5 ) + V_54 -> V_58 ;
V_3 -> V_13 = V_54 -> V_16 ;
}
if ( V_3 -> V_59 )
V_3 -> V_59 = 0 ;
if ( V_3 -> V_56 )
V_3 -> V_56 = 0 ;
}
static bool F_66 ( struct V_2 * V_3 ,
struct V_2 * V_54 , T_1 V_60 )
{
T_1 V_61 , V_62 ;
V_61 = ( V_54 -> V_15 >> V_63 ) * ( V_3 -> V_13 >> V_63 ) ;
V_62 = ( ( V_3 -> V_57 - V_60 ) >> V_63 ) *
( V_54 -> V_16 >> V_63 ) ;
return F_64 ( V_62 , V_61 ) ;
}
static void F_67 ( struct V_2 * V_3 ,
struct V_2 * V_54 )
{
struct V_6 * V_6 = F_4 ( V_3 ) ;
struct V_5 * V_5 = F_3 ( V_6 ) ;
if ( V_3 -> V_55 ) {
F_60 ( V_3 , V_54 ) ;
return;
}
if ( F_64 ( V_3 -> V_57 , F_62 ( V_5 ) ) ||
F_66 ( V_3 , V_54 , F_62 ( V_5 ) ) ) {
V_3 -> V_57 = F_62 ( V_5 ) + V_54 -> V_58 ;
V_3 -> V_13 = V_54 -> V_16 ;
}
}
static int F_68 ( struct V_2 * V_3 , bool V_64 )
{
struct V_6 * V_6 = F_4 ( V_3 ) ;
struct V_5 * V_5 = F_3 ( V_6 ) ;
T_2 V_65 , V_66 ;
T_2 V_67 , V_68 ;
unsigned long V_69 ;
T_3 V_70 ;
if ( V_64 )
return 0 ;
V_66 = F_69 ( V_3 -> V_57 ) ;
V_65 = F_70 ( & V_3 -> V_71 ) ;
V_70 = F_71 ( V_65 ) - F_62 ( V_5 ) ;
V_66 = F_72 ( V_66 , V_70 ) ;
if ( F_73 ( V_66 , V_65 ) < 0 )
return 0 ;
F_74 ( & V_3 -> V_71 , V_66 ) ;
V_67 = F_75 ( & V_3 -> V_71 ) ;
V_68 = F_76 ( & V_3 -> V_71 ) ;
V_69 = F_71 ( F_77 ( V_68 , V_67 ) ) ;
F_78 ( & V_3 -> V_71 , V_67 ,
V_69 , V_72 , 0 ) ;
return F_79 ( & V_3 -> V_71 ) ;
}
static enum V_73 F_80 ( struct V_74 * V_75 )
{
struct V_2 * V_3 = F_2 ( V_75 ,
struct V_2 ,
V_71 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
unsigned long V_76 ;
struct V_5 * V_5 ;
V_5 = F_81 ( V_7 , & V_76 ) ;
if ( ! F_44 ( V_7 ) || V_3 -> V_55 ||
V_3 -> V_77 || ! V_3 -> V_56 )
goto V_78;
F_82 () ;
F_83 ( V_5 ) ;
#ifdef F_18
if ( F_84 ( ! V_5 -> V_33 ) ) {
F_46 ( V_5 , V_7 ) ;
goto V_78;
}
#endif
if ( ! F_85 ( V_7 ) ) {
F_63 ( V_3 , V_3 ) ;
goto V_78;
}
F_86 ( V_5 , V_7 , V_53 ) ;
if ( F_44 ( V_5 -> V_26 ) )
F_87 ( V_5 , V_7 , 0 ) ;
else
F_57 ( V_5 ) ;
#ifdef F_18
if ( F_41 ( V_5 ) )
F_88 ( V_5 ) ;
#endif
V_78:
F_89 ( V_5 , V_7 , & V_76 ) ;
return V_79 ;
}
void F_90 ( struct V_2 * V_3 )
{
struct V_74 * V_75 = & V_3 -> V_71 ;
F_91 ( V_75 , V_80 , V_81 ) ;
V_75 -> V_82 = F_80 ;
}
static
int F_92 ( struct V_5 * V_5 , struct V_2 * V_3 )
{
return ( V_3 -> V_13 <= 0 ) ;
}
static void F_93 ( struct V_5 * V_5 )
{
struct V_1 * V_26 = V_5 -> V_26 ;
struct V_2 * V_3 = & V_26 -> V_4 ;
T_1 V_83 ;
if ( ! F_44 ( V_26 ) || ! F_6 ( V_3 ) )
return;
V_83 = F_94 ( V_5 ) - V_26 -> V_84 . V_85 ;
if ( F_84 ( ( T_3 ) V_83 <= 0 ) )
return;
F_95 ( V_26 -> V_84 . V_86 . V_87 ,
F_96 ( V_26 -> V_84 . V_86 . V_87 , V_83 ) ) ;
V_26 -> V_84 . V_88 += V_83 ;
F_97 ( V_26 , V_83 ) ;
V_26 -> V_84 . V_85 = F_94 ( V_5 ) ;
F_98 ( V_26 , V_83 ) ;
F_99 ( V_5 , V_83 ) ;
V_3 -> V_13 -= V_3 -> V_59 ? 0 : V_83 ;
if ( F_92 ( V_5 , V_3 ) ) {
V_3 -> V_56 = 1 ;
F_100 ( V_5 , V_26 , 0 ) ;
if ( F_84 ( ! F_68 ( V_3 , V_26 -> V_4 . V_77 ) ) )
F_86 ( V_5 , V_26 , V_53 ) ;
if ( ! F_8 ( V_26 , & V_5 -> V_4 ) )
F_57 ( V_5 ) ;
}
if ( F_101 () ) {
struct V_89 * V_89 = & V_5 -> V_90 ;
F_12 ( & V_89 -> V_91 ) ;
if ( F_102 ( V_89 ) )
V_89 -> V_92 += V_83 ;
F_16 ( & V_89 -> V_91 ) ;
}
}
static inline T_1 F_103 ( struct V_5 * V_5 )
{
struct V_1 * V_27 = F_104 ( V_5 , V_5 -> V_34 ) ;
if ( V_27 && F_105 ( V_27 -> V_93 ) )
return V_27 -> V_4 . V_57 ;
else
return 0 ;
}
static void F_106 ( struct V_6 * V_6 , T_1 V_57 )
{
struct V_5 * V_5 = F_3 ( V_6 ) ;
if ( V_6 -> V_25 . V_26 == 0 ||
F_64 ( V_57 , V_6 -> V_25 . V_26 ) ) {
V_6 -> V_25 . V_27 = V_6 -> V_25 . V_26 ;
V_6 -> V_25 . V_26 = V_57 ;
F_107 ( & V_5 -> V_31 -> V_94 , V_5 -> V_34 , V_57 , 1 ) ;
} else if ( V_6 -> V_25 . V_27 == 0 ||
F_64 ( V_57 , V_6 -> V_25 . V_27 ) ) {
V_6 -> V_25 . V_27 = F_103 ( V_5 ) ;
}
}
static void F_108 ( struct V_6 * V_6 , T_1 V_57 )
{
struct V_5 * V_5 = F_3 ( V_6 ) ;
if ( ! V_6 -> V_36 ) {
V_6 -> V_25 . V_26 = 0 ;
V_6 -> V_25 . V_27 = 0 ;
F_107 ( & V_5 -> V_31 -> V_94 , V_5 -> V_34 , 0 , 0 ) ;
} else {
struct V_8 * V_41 = V_6 -> V_9 ;
struct V_2 * V_40 ;
V_40 = F_33 ( V_41 , struct V_2 , V_8 ) ;
V_6 -> V_25 . V_26 = V_40 -> V_57 ;
V_6 -> V_25 . V_27 = F_103 ( V_5 ) ;
F_107 ( & V_5 -> V_31 -> V_94 , V_5 -> V_34 , V_40 -> V_57 , 1 ) ;
}
}
static inline void F_106 ( struct V_6 * V_6 , T_1 V_57 ) {}
static inline void F_108 ( struct V_6 * V_6 , T_1 V_57 ) {}
static inline
void F_109 ( struct V_2 * V_3 , struct V_6 * V_6 )
{
int V_93 = F_1 ( V_3 ) -> V_93 ;
T_1 V_57 = V_3 -> V_57 ;
F_61 ( ! F_105 ( V_93 ) ) ;
V_6 -> V_36 ++ ;
F_110 ( F_3 ( V_6 ) , 1 ) ;
F_106 ( V_6 , V_57 ) ;
F_29 ( V_3 , V_6 ) ;
}
static inline
void F_111 ( struct V_2 * V_3 , struct V_6 * V_6 )
{
int V_93 = F_1 ( V_3 ) -> V_93 ;
F_61 ( ! F_105 ( V_93 ) ) ;
F_61 ( ! V_6 -> V_36 ) ;
V_6 -> V_36 -- ;
F_112 ( F_3 ( V_6 ) , 1 ) ;
F_108 ( V_6 , V_3 -> V_57 ) ;
F_30 ( V_3 , V_6 ) ;
}
static void F_113 ( struct V_2 * V_3 )
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
if ( F_64 ( V_3 -> V_57 , V_40 -> V_57 ) )
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
F_109 ( V_3 , V_6 ) ;
}
static void F_114 ( struct V_2 * V_3 )
{
struct V_6 * V_6 = F_4 ( V_3 ) ;
if ( F_7 ( & V_3 -> V_8 ) )
return;
if ( V_6 -> V_9 == & V_3 -> V_8 ) {
struct V_8 * V_46 ;
V_46 = F_38 ( & V_3 -> V_8 ) ;
V_6 -> V_9 = V_46 ;
}
F_39 ( & V_3 -> V_8 , & V_6 -> V_23 ) ;
F_40 ( & V_3 -> V_8 ) ;
F_111 ( V_3 , V_6 ) ;
}
static void
F_115 ( struct V_2 * V_3 ,
struct V_2 * V_54 , int V_76 )
{
F_32 ( F_6 ( V_3 ) ) ;
if ( V_3 -> V_55 || V_76 & V_95 )
F_67 ( V_3 , V_54 ) ;
else if ( V_76 & V_53 )
F_63 ( V_3 , V_54 ) ;
F_113 ( V_3 ) ;
}
static void F_116 ( struct V_2 * V_3 )
{
F_114 ( V_3 ) ;
}
static void F_86 ( struct V_5 * V_5 , struct V_1 * V_7 , int V_76 )
{
struct V_1 * V_96 = F_117 ( V_7 ) ;
struct V_2 * V_54 = & V_7 -> V_4 ;
if ( V_96 && V_7 -> V_4 . V_77 && F_105 ( V_96 -> V_97 ) ) {
V_54 = & V_96 -> V_4 ;
} else if ( ! F_105 ( V_7 -> V_97 ) ) {
F_32 ( ! V_7 -> V_4 . V_77 || V_76 != V_53 ) ;
return;
}
if ( V_7 -> V_4 . V_56 && ! ( V_76 & V_53 ) )
return;
F_115 ( & V_7 -> V_4 , V_54 , V_76 ) ;
if ( ! F_118 ( V_5 , V_7 ) && V_7 -> V_37 > 1 )
F_31 ( V_5 , V_7 ) ;
}
static void F_100 ( struct V_5 * V_5 , struct V_1 * V_7 , int V_76 )
{
F_116 ( & V_7 -> V_4 ) ;
F_37 ( V_5 , V_7 ) ;
}
static void F_119 ( struct V_5 * V_5 , struct V_1 * V_7 , int V_76 )
{
F_93 ( V_5 ) ;
F_100 ( V_5 , V_7 , V_76 ) ;
}
static void F_120 ( struct V_5 * V_5 )
{
struct V_1 * V_7 = V_5 -> V_26 ;
if ( V_7 -> V_4 . V_13 > 0 ) {
V_5 -> V_26 -> V_4 . V_59 = 1 ;
V_7 -> V_4 . V_13 = 0 ;
}
F_83 ( V_5 ) ;
F_93 ( V_5 ) ;
F_121 ( V_5 , true ) ;
}
static int
F_122 ( struct V_1 * V_7 , int V_34 , int V_98 , int V_76 )
{
struct V_1 * V_26 ;
struct V_5 * V_5 ;
if ( V_98 != V_99 )
goto V_100;
V_5 = F_52 ( V_34 ) ;
F_123 () ;
V_26 = F_124 ( V_5 -> V_26 ) ;
if ( F_84 ( F_44 ( V_26 ) ) &&
( V_26 -> V_37 < 2 ||
! F_34 ( & V_7 -> V_4 , & V_26 -> V_4 ) ) &&
( V_7 -> V_37 > 1 ) ) {
int V_101 = F_125 ( V_7 ) ;
if ( V_101 != - 1 )
V_34 = V_101 ;
}
F_126 () ;
V_100:
return V_34 ;
}
static void F_127 ( struct V_5 * V_5 , struct V_1 * V_7 )
{
if ( V_5 -> V_26 -> V_37 == 1 ||
F_128 ( & V_5 -> V_31 -> V_94 , V_5 -> V_26 , NULL ) == - 1 )
return;
if ( V_7 -> V_37 != 1 &&
F_128 ( & V_5 -> V_31 -> V_94 , V_7 , NULL ) != - 1 )
return;
F_57 ( V_5 ) ;
}
static void F_87 ( struct V_5 * V_5 , struct V_1 * V_7 ,
int V_76 )
{
if ( F_34 ( & V_7 -> V_4 , & V_5 -> V_26 -> V_4 ) ) {
F_57 ( V_5 ) ;
return;
}
#ifdef F_18
if ( ( V_7 -> V_4 . V_57 == V_5 -> V_26 -> V_4 . V_57 ) &&
! F_129 ( V_5 -> V_26 ) )
F_127 ( V_5 , V_7 ) ;
#endif
}
static void F_130 ( struct V_5 * V_5 , struct V_1 * V_7 )
{
F_131 ( V_5 , V_7 -> V_4 . V_13 ) ;
}
static void F_130 ( struct V_5 * V_5 , struct V_1 * V_7 )
{
}
static struct V_2 * F_132 ( struct V_5 * V_5 ,
struct V_6 * V_6 )
{
struct V_8 * V_61 = V_6 -> V_9 ;
if ( ! V_61 )
return NULL ;
return F_33 ( V_61 , struct V_2 , V_8 ) ;
}
struct V_1 * F_133 ( struct V_5 * V_5 , struct V_1 * V_47 )
{
struct V_2 * V_3 ;
struct V_1 * V_7 ;
struct V_6 * V_6 ;
V_6 = & V_5 -> V_4 ;
if ( F_43 ( V_5 , V_47 ) ) {
F_59 ( V_5 ) ;
if ( V_5 -> V_102 && F_85 ( V_5 -> V_102 ) )
return V_103 ;
}
if ( V_47 -> V_104 == & V_105 )
F_93 ( V_5 ) ;
if ( F_84 ( ! V_6 -> V_36 ) )
return NULL ;
F_134 ( V_5 , V_47 ) ;
V_3 = F_132 ( V_5 , V_6 ) ;
F_32 ( ! V_3 ) ;
V_7 = F_1 ( V_3 ) ;
V_7 -> V_84 . V_85 = F_94 ( V_5 ) ;
F_37 ( V_5 , V_7 ) ;
if ( F_135 ( V_5 ) )
F_130 ( V_5 , V_7 ) ;
F_45 ( V_5 ) ;
return V_7 ;
}
static void F_136 ( struct V_5 * V_5 , struct V_1 * V_7 )
{
F_93 ( V_5 ) ;
if ( F_6 ( & V_7 -> V_4 ) && V_7 -> V_37 > 1 )
F_31 ( V_5 , V_7 ) ;
}
static void F_137 ( struct V_5 * V_5 , struct V_1 * V_7 , int V_106 )
{
F_93 ( V_5 ) ;
if ( F_135 ( V_5 ) && V_106 && V_7 -> V_4 . V_13 > 0 &&
F_8 ( V_7 , & V_5 -> V_4 ) )
F_130 ( V_5 , V_7 ) ;
}
static void F_138 ( struct V_1 * V_7 )
{
}
static void F_139 ( struct V_1 * V_7 )
{
struct V_74 * V_75 = & V_7 -> V_4 . V_71 ;
struct V_17 * V_11 = F_140 ( F_141 ( V_7 ) ) ;
F_142 ( & V_11 -> V_18 ) ;
V_11 -> V_22 -= V_7 -> V_4 . V_17 ;
F_143 ( & V_11 -> V_18 ) ;
F_144 ( V_75 ) ;
}
static void F_145 ( struct V_5 * V_5 )
{
struct V_1 * V_7 = V_5 -> V_26 ;
V_7 -> V_84 . V_85 = F_94 ( V_5 ) ;
F_37 ( V_5 , V_7 ) ;
}
static int F_146 ( struct V_5 * V_5 , struct V_1 * V_7 , int V_34 )
{
if ( ! F_147 ( V_5 , V_7 ) &&
F_148 ( V_34 , F_49 ( V_7 ) ) )
return 1 ;
return 0 ;
}
static struct V_1 * F_104 ( struct V_5 * V_5 , int V_34 )
{
struct V_8 * V_46 = V_5 -> V_4 . V_9 ;
struct V_2 * V_3 ;
struct V_1 * V_7 = NULL ;
V_46:
V_46 = F_38 ( V_46 ) ;
if ( V_46 ) {
V_3 = F_33 ( V_46 , struct V_2 , V_8 ) ;
V_7 = F_1 ( V_3 ) ;
if ( F_146 ( V_5 , V_7 , V_34 ) )
return V_7 ;
goto V_46;
}
return NULL ;
}
static int F_125 ( struct V_1 * V_107 )
{
struct V_108 * V_109 ;
struct V_110 * V_111 = F_149 ( V_112 ) ;
int V_113 = F_150 () ;
int V_114 , V_34 = F_141 ( V_107 ) ;
if ( F_84 ( ! V_111 ) )
return - 1 ;
if ( V_107 -> V_37 == 1 )
return - 1 ;
V_114 = F_128 ( & F_5 ( V_107 ) -> V_31 -> V_94 ,
V_107 , V_111 ) ;
if ( V_114 == - 1 )
return - 1 ;
if ( F_148 ( V_34 , V_111 ) )
return V_34 ;
if ( ! F_148 ( V_113 , V_111 ) )
V_113 = - 1 ;
F_123 () ;
F_151 (cpu, sd) {
if ( V_109 -> V_76 & V_115 ) {
if ( V_113 != - 1 &&
F_148 ( V_113 , F_152 ( V_109 ) ) ) {
F_126 () ;
return V_113 ;
}
if ( V_114 < V_52 &&
F_148 ( V_114 , F_152 ( V_109 ) ) ) {
F_126 () ;
return V_114 ;
}
}
}
F_126 () ;
if ( V_113 != - 1 )
return V_113 ;
V_34 = F_51 ( V_111 ) ;
if ( V_34 < V_52 )
return V_34 ;
return - 1 ;
}
static struct V_5 * F_47 ( struct V_1 * V_107 , struct V_5 * V_5 )
{
struct V_5 * V_49 = NULL ;
int V_116 ;
int V_34 ;
for ( V_116 = 0 ; V_116 < V_117 ; V_116 ++ ) {
V_34 = F_125 ( V_107 ) ;
if ( ( V_34 == - 1 ) || ( V_34 == V_5 -> V_34 ) )
break;
V_49 = F_52 ( V_34 ) ;
if ( F_53 ( V_5 , V_49 ) ) {
if ( F_84 ( F_5 ( V_107 ) != V_5 ||
! F_148 ( V_49 -> V_34 ,
& V_107 -> V_118 ) ||
F_147 ( V_5 , V_107 ) ||
! F_85 ( V_107 ) ) ) {
F_58 ( V_5 , V_49 ) ;
V_49 = NULL ;
break;
}
}
if ( ! V_49 -> V_4 . V_36 ||
F_64 ( V_107 -> V_4 . V_57 ,
V_49 -> V_4 . V_25 . V_26 ) )
break;
F_58 ( V_5 , V_49 ) ;
V_49 = NULL ;
}
return V_49 ;
}
static struct V_1 * F_153 ( struct V_5 * V_5 )
{
struct V_1 * V_7 ;
if ( ! F_41 ( V_5 ) )
return NULL ;
V_7 = F_33 ( V_5 -> V_4 . V_45 ,
struct V_1 , V_42 ) ;
F_32 ( V_5 -> V_34 != F_141 ( V_7 ) ) ;
F_32 ( F_118 ( V_5 , V_7 ) ) ;
F_32 ( V_7 -> V_37 <= 1 ) ;
F_32 ( ! F_85 ( V_7 ) ) ;
F_32 ( ! F_44 ( V_7 ) ) ;
return V_7 ;
}
static int F_88 ( struct V_5 * V_5 )
{
struct V_1 * V_119 ;
struct V_5 * V_49 ;
int V_120 = 0 ;
if ( ! V_5 -> V_4 . V_29 )
return 0 ;
V_119 = F_153 ( V_5 ) ;
if ( ! V_119 )
return 0 ;
V_121:
if ( F_84 ( V_119 == V_5 -> V_26 ) ) {
F_61 ( 1 ) ;
return 0 ;
}
if ( F_44 ( V_5 -> V_26 ) &&
F_64 ( V_119 -> V_4 . V_57 , V_5 -> V_26 -> V_4 . V_57 ) &&
V_5 -> V_26 -> V_37 > 1 ) {
F_57 ( V_5 ) ;
return 0 ;
}
F_154 ( V_119 ) ;
V_49 = F_47 ( V_119 , V_5 ) ;
if ( ! V_49 ) {
struct V_1 * V_107 ;
V_107 = F_153 ( V_5 ) ;
if ( F_141 ( V_119 ) == V_5 -> V_34 && V_107 == V_119 ) {
goto V_100;
}
if ( ! V_107 )
goto V_100;
F_155 ( V_119 ) ;
V_119 = V_107 ;
goto V_121;
}
F_54 ( V_5 , V_119 , 0 ) ;
F_55 ( V_119 , V_49 -> V_34 ) ;
F_56 ( V_49 , V_119 , 0 ) ;
V_120 = 1 ;
F_57 ( V_49 ) ;
F_58 ( V_5 , V_49 ) ;
V_100:
F_155 ( V_119 ) ;
return V_120 ;
}
static void F_156 ( struct V_5 * V_5 )
{
while ( F_88 ( V_5 ) )
;
}
static int F_59 ( struct V_5 * V_122 )
{
int V_113 = V_122 -> V_34 , V_120 = 0 , V_34 ;
struct V_1 * V_7 ;
struct V_5 * V_123 ;
T_1 V_124 = V_125 ;
if ( F_157 ( ! F_19 ( V_122 ) ) )
return 0 ;
F_158 () ;
F_159 (cpu, this_rq->rd->dlo_mask) {
if ( V_113 == V_34 )
continue;
V_123 = F_52 ( V_34 ) ;
if ( V_122 -> V_4 . V_36 &&
F_64 ( V_122 -> V_4 . V_25 . V_26 ,
V_123 -> V_4 . V_25 . V_27 ) )
continue;
F_53 ( V_122 , V_123 ) ;
if ( V_123 -> V_4 . V_36 <= 1 )
goto V_126;
V_7 = F_104 ( V_123 , V_113 ) ;
if ( V_7 && F_64 ( V_7 -> V_4 . V_57 , V_124 ) &&
( ! V_122 -> V_4 . V_36 ||
F_64 ( V_7 -> V_4 . V_57 ,
V_122 -> V_4 . V_25 . V_26 ) ) ) {
F_61 ( V_7 == V_123 -> V_26 ) ;
F_61 ( ! F_85 ( V_7 ) ) ;
if ( F_64 ( V_7 -> V_4 . V_57 ,
V_123 -> V_26 -> V_4 . V_57 ) )
goto V_126;
V_120 = 1 ;
F_54 ( V_123 , V_7 , 0 ) ;
F_55 ( V_7 , V_113 ) ;
F_56 ( V_122 , V_7 , 0 ) ;
V_124 = V_7 -> V_4 . V_57 ;
}
V_126:
F_58 ( V_122 , V_123 ) ;
}
return V_120 ;
}
static void F_160 ( struct V_5 * V_5 )
{
F_156 ( V_5 ) ;
}
static void F_161 ( struct V_5 * V_5 , struct V_1 * V_7 )
{
if ( ! F_147 ( V_5 , V_7 ) &&
! F_129 ( V_5 -> V_26 ) &&
F_41 ( V_5 ) &&
V_7 -> V_37 > 1 &&
F_44 ( V_5 -> V_26 ) &&
( V_5 -> V_26 -> V_37 < 2 ||
! F_34 ( & V_7 -> V_4 , & V_5 -> V_26 -> V_4 ) ) ) {
F_156 ( V_5 ) ;
}
}
static void F_162 ( struct V_1 * V_7 ,
const struct V_110 * V_127 )
{
struct V_5 * V_5 ;
struct V_128 * V_129 ;
int V_130 ;
F_32 ( ! F_44 ( V_7 ) ) ;
V_5 = F_5 ( V_7 ) ;
V_129 = V_5 -> V_31 ;
if ( ! F_163 ( V_129 -> V_131 , V_127 ) ) {
struct V_17 * V_132 ;
V_132 = F_140 ( F_164 ( V_5 ) ) ;
F_12 ( & V_132 -> V_18 ) ;
F_165 ( V_132 , V_7 -> V_4 . V_17 ) ;
F_16 ( & V_132 -> V_18 ) ;
}
if ( ! F_6 ( & V_7 -> V_4 ) )
return;
V_130 = F_166 ( V_127 ) ;
if ( ( V_7 -> V_37 > 1 ) == ( V_130 > 1 ) )
return;
if ( V_130 <= 1 ) {
if ( ! F_118 ( V_5 , V_7 ) )
F_37 ( V_5 , V_7 ) ;
F_32 ( ! V_5 -> V_4 . V_28 ) ;
V_5 -> V_4 . V_28 -- ;
} else {
if ( ! F_118 ( V_5 , V_7 ) )
F_31 ( V_5 , V_7 ) ;
V_5 -> V_4 . V_28 ++ ;
}
F_28 ( & V_5 -> V_4 ) ;
}
static void F_167 ( struct V_5 * V_5 )
{
if ( V_5 -> V_4 . V_29 )
F_21 ( V_5 ) ;
F_168 ( & V_5 -> V_31 -> V_94 , V_5 -> V_34 ) ;
if ( V_5 -> V_4 . V_36 > 0 )
F_107 ( & V_5 -> V_31 -> V_94 , V_5 -> V_34 , V_5 -> V_4 . V_25 . V_26 , 1 ) ;
}
static void F_169 ( struct V_5 * V_5 )
{
if ( V_5 -> V_4 . V_29 )
F_25 ( V_5 ) ;
F_107 ( & V_5 -> V_31 -> V_94 , V_5 -> V_34 , 0 , 0 ) ;
F_170 ( & V_5 -> V_31 -> V_94 , V_5 -> V_34 ) ;
}
void F_171 ( void )
{
unsigned int V_133 ;
F_172 (i)
F_173 ( & F_174 ( V_112 , V_133 ) ,
V_134 , F_175 ( V_133 ) ) ;
}
static void F_176 ( struct V_5 * V_5 , struct V_1 * V_7 )
{
struct V_74 * V_71 = & V_7 -> V_4 . V_71 ;
F_177 ( & V_7 -> V_135 ) ;
if ( F_79 ( V_71 ) ) {
int V_120 = F_178 ( V_71 ) ;
if ( F_84 ( V_120 == - 1 ) ) {
F_16 ( & V_5 -> V_18 ) ;
F_144 ( V_71 ) ;
F_12 ( & V_5 -> V_18 ) ;
}
}
}
static void F_179 ( struct V_5 * V_5 , struct V_1 * V_7 )
{
F_176 ( V_5 , V_7 ) ;
F_180 ( V_7 ) ;
if ( ! F_85 ( V_7 ) || V_5 -> V_4 . V_36 )
return;
if ( F_59 ( V_5 ) )
F_57 ( V_5 ) ;
}
static void F_181 ( struct V_5 * V_5 , struct V_1 * V_7 )
{
int V_136 = 1 ;
if ( F_85 ( V_7 ) && V_5 -> V_26 != V_7 ) {
#ifdef F_18
if ( V_7 -> V_37 > 1 && V_5 -> V_4 . V_29 &&
F_88 ( V_5 ) && V_5 != F_5 ( V_7 ) )
V_136 = 0 ;
#endif
if ( V_136 ) {
if ( F_44 ( V_5 -> V_26 ) )
F_87 ( V_5 , V_7 , 0 ) ;
else
F_57 ( V_5 ) ;
}
}
}
static void F_182 ( struct V_5 * V_5 , struct V_1 * V_7 ,
int V_137 )
{
if ( F_85 ( V_7 ) || V_5 -> V_26 == V_7 ) {
#ifdef F_18
if ( ! V_5 -> V_4 . V_29 )
F_59 ( V_5 ) ;
if ( F_64 ( V_5 -> V_4 . V_25 . V_26 , V_7 -> V_4 . V_57 ) &&
V_5 -> V_26 == V_7 )
F_57 ( V_5 ) ;
#else
F_57 ( V_5 ) ;
#endif
} else
F_181 ( V_5 , V_7 ) ;
}
void F_183 ( struct V_138 * V_139 , int V_34 )
{
F_184 ( V_139 , V_34 , & F_52 ( V_34 ) -> V_4 ) ;
}
