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
void F_17 ( struct V_6 * V_6 , struct V_5 * V_5 )
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
static inline int F_46 ( struct V_5 * V_5 )
{
return 0 ;
}
static inline void F_45 ( struct V_5 * V_5 )
{
}
static inline void F_47 ( struct V_2 * V_3 ,
struct V_2 * V_49 )
{
struct V_6 * V_6 = F_4 ( V_3 ) ;
struct V_5 * V_5 = F_3 ( V_6 ) ;
F_48 ( ! V_3 -> V_50 || V_3 -> V_51 ) ;
V_3 -> V_52 = F_49 ( V_5 ) + V_49 -> V_53 ;
V_3 -> V_13 = V_49 -> V_16 ;
V_3 -> V_50 = 0 ;
}
static void F_50 ( struct V_2 * V_3 ,
struct V_2 * V_49 )
{
struct V_6 * V_6 = F_4 ( V_3 ) ;
struct V_5 * V_5 = F_3 ( V_6 ) ;
F_32 ( V_49 -> V_16 <= 0 ) ;
if ( V_3 -> V_53 == 0 ) {
V_3 -> V_52 = F_49 ( V_5 ) + V_49 -> V_53 ;
V_3 -> V_13 = V_49 -> V_16 ;
}
while ( V_3 -> V_13 <= 0 ) {
V_3 -> V_52 += V_49 -> V_15 ;
V_3 -> V_13 += V_49 -> V_16 ;
}
if ( F_51 ( V_3 -> V_52 , F_49 ( V_5 ) ) ) {
static bool V_54 = false ;
if ( ! V_54 ) {
V_54 = true ;
F_52 ( L_1 ) ;
}
V_3 -> V_52 = F_49 ( V_5 ) + V_49 -> V_53 ;
V_3 -> V_13 = V_49 -> V_16 ;
}
}
static bool F_53 ( struct V_2 * V_3 ,
struct V_2 * V_49 , T_1 V_55 )
{
T_1 V_56 , V_57 ;
V_56 = ( V_49 -> V_15 >> V_58 ) * ( V_3 -> V_13 >> V_58 ) ;
V_57 = ( ( V_3 -> V_52 - V_55 ) >> V_58 ) *
( V_49 -> V_16 >> V_58 ) ;
return F_51 ( V_57 , V_56 ) ;
}
static void F_54 ( struct V_2 * V_3 ,
struct V_2 * V_49 )
{
struct V_6 * V_6 = F_4 ( V_3 ) ;
struct V_5 * V_5 = F_3 ( V_6 ) ;
if ( V_3 -> V_50 ) {
F_47 ( V_3 , V_49 ) ;
return;
}
if ( F_51 ( V_3 -> V_52 , F_49 ( V_5 ) ) ||
F_53 ( V_3 , V_49 , F_49 ( V_5 ) ) ) {
V_3 -> V_52 = F_49 ( V_5 ) + V_49 -> V_53 ;
V_3 -> V_13 = V_49 -> V_16 ;
}
}
static int F_55 ( struct V_2 * V_3 , bool V_59 )
{
struct V_6 * V_6 = F_4 ( V_3 ) ;
struct V_5 * V_5 = F_3 ( V_6 ) ;
T_2 V_60 , V_61 ;
T_2 V_62 , V_63 ;
unsigned long V_64 ;
T_3 V_65 ;
if ( V_59 )
return 0 ;
V_61 = F_56 ( V_3 -> V_52 ) ;
V_60 = F_57 ( & V_3 -> V_66 ) ;
V_65 = F_58 ( V_60 ) - F_49 ( V_5 ) ;
V_61 = F_59 ( V_61 , V_65 ) ;
if ( F_60 ( V_61 , V_60 ) < 0 )
return 0 ;
F_61 ( & V_3 -> V_66 , V_61 ) ;
V_62 = F_62 ( & V_3 -> V_66 ) ;
V_63 = F_63 ( & V_3 -> V_66 ) ;
V_64 = F_58 ( F_64 ( V_63 , V_62 ) ) ;
F_65 ( & V_3 -> V_66 , V_62 ,
V_64 , V_67 , 0 ) ;
return F_66 ( & V_3 -> V_66 ) ;
}
static enum V_68 F_67 ( struct V_69 * V_70 )
{
struct V_2 * V_3 = F_2 ( V_70 ,
struct V_2 ,
V_66 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_5 * V_5 ;
V_71:
V_5 = F_5 ( V_7 ) ;
F_12 ( & V_5 -> V_18 ) ;
if ( V_5 != F_5 ( V_7 ) ) {
F_16 ( & V_5 -> V_18 ) ;
goto V_71;
}
if ( ! F_44 ( V_7 ) || V_3 -> V_50 )
goto V_72;
F_68 () ;
F_69 ( V_5 ) ;
V_3 -> V_51 = 0 ;
V_3 -> V_73 = 0 ;
if ( V_7 -> V_74 ) {
F_70 ( V_5 , V_7 , V_75 ) ;
if ( F_71 ( V_5 -> V_26 ) )
F_72 ( V_5 , V_7 , 0 ) ;
else
F_73 ( V_5 -> V_26 ) ;
#ifdef F_18
if ( F_41 ( V_5 ) )
F_74 ( V_5 ) ;
#endif
}
V_72:
F_16 ( & V_5 -> V_18 ) ;
return V_76 ;
}
void F_75 ( struct V_2 * V_3 )
{
struct V_69 * V_70 = & V_3 -> V_66 ;
if ( F_66 ( V_70 ) ) {
F_76 ( V_70 ) ;
return;
}
F_77 ( V_70 , V_77 , V_78 ) ;
V_70 -> V_79 = F_67 ;
}
static
int F_78 ( struct V_5 * V_5 , struct V_2 * V_3 )
{
int V_80 = F_51 ( V_3 -> V_52 , F_49 ( V_5 ) ) ;
int V_81 = V_3 -> V_13 <= 0 ;
if ( ! V_81 && ! V_80 )
return 0 ;
if ( V_80 ) {
V_3 -> V_13 = V_81 ? V_3 -> V_13 : 0 ;
V_3 -> V_13 -= F_49 ( V_5 ) - V_3 -> V_52 ;
}
return 1 ;
}
static void F_79 ( struct V_5 * V_5 )
{
struct V_1 * V_26 = V_5 -> V_26 ;
struct V_2 * V_3 = & V_26 -> V_4 ;
T_1 V_82 ;
if ( ! F_44 ( V_26 ) || ! F_6 ( V_3 ) )
return;
V_82 = F_80 ( V_5 ) - V_26 -> V_83 . V_84 ;
if ( F_81 ( ( T_3 ) V_82 <= 0 ) )
return;
F_82 ( V_26 -> V_83 . V_85 . V_86 ,
F_83 ( V_26 -> V_83 . V_85 . V_86 , V_82 ) ) ;
V_26 -> V_83 . V_87 += V_82 ;
F_84 ( V_26 , V_82 ) ;
V_26 -> V_83 . V_84 = F_80 ( V_5 ) ;
F_85 ( V_26 , V_82 ) ;
F_86 ( V_5 , V_82 ) ;
V_3 -> V_13 -= V_82 ;
if ( F_78 ( V_5 , V_3 ) ) {
F_87 ( V_5 , V_26 , 0 ) ;
if ( F_88 ( F_55 ( V_3 , V_26 -> V_4 . V_88 ) ) )
V_3 -> V_51 = 1 ;
else
F_70 ( V_5 , V_26 , V_75 ) ;
if ( ! F_8 ( V_26 , & V_5 -> V_4 ) )
F_73 ( V_26 ) ;
}
if ( F_89 () ) {
struct V_89 * V_89 = & V_5 -> V_90 ;
F_12 ( & V_89 -> V_91 ) ;
if ( F_90 ( V_89 ) )
V_89 -> V_92 += V_82 ;
F_16 ( & V_89 -> V_91 ) ;
}
}
static inline T_1 F_91 ( struct V_5 * V_5 )
{
struct V_1 * V_27 = F_92 ( V_5 , V_5 -> V_34 ) ;
if ( V_27 && F_93 ( V_27 -> V_93 ) )
return V_27 -> V_4 . V_52 ;
else
return 0 ;
}
static void F_94 ( struct V_6 * V_6 , T_1 V_52 )
{
struct V_5 * V_5 = F_3 ( V_6 ) ;
if ( V_6 -> V_25 . V_26 == 0 ||
F_51 ( V_52 , V_6 -> V_25 . V_26 ) ) {
V_6 -> V_25 . V_27 = V_6 -> V_25 . V_26 ;
V_6 -> V_25 . V_26 = V_52 ;
F_95 ( & V_5 -> V_31 -> V_94 , V_5 -> V_34 , V_52 , 1 ) ;
} else if ( V_6 -> V_25 . V_27 == 0 ||
F_51 ( V_52 , V_6 -> V_25 . V_27 ) ) {
V_6 -> V_25 . V_27 = F_91 ( V_5 ) ;
}
}
static void F_96 ( struct V_6 * V_6 , T_1 V_52 )
{
struct V_5 * V_5 = F_3 ( V_6 ) ;
if ( ! V_6 -> V_36 ) {
V_6 -> V_25 . V_26 = 0 ;
V_6 -> V_25 . V_27 = 0 ;
F_95 ( & V_5 -> V_31 -> V_94 , V_5 -> V_34 , 0 , 0 ) ;
} else {
struct V_8 * V_41 = V_6 -> V_9 ;
struct V_2 * V_40 ;
V_40 = F_33 ( V_41 , struct V_2 , V_8 ) ;
V_6 -> V_25 . V_26 = V_40 -> V_52 ;
V_6 -> V_25 . V_27 = F_91 ( V_5 ) ;
F_95 ( & V_5 -> V_31 -> V_94 , V_5 -> V_34 , V_40 -> V_52 , 1 ) ;
}
}
static inline void F_94 ( struct V_6 * V_6 , T_1 V_52 ) {}
static inline void F_96 ( struct V_6 * V_6 , T_1 V_52 ) {}
static inline
void F_97 ( struct V_2 * V_3 , struct V_6 * V_6 )
{
int V_93 = F_1 ( V_3 ) -> V_93 ;
T_1 V_52 = V_3 -> V_52 ;
F_48 ( ! F_93 ( V_93 ) ) ;
V_6 -> V_36 ++ ;
F_98 ( F_3 ( V_6 ) ) ;
F_94 ( V_6 , V_52 ) ;
F_29 ( V_3 , V_6 ) ;
}
static inline
void F_99 ( struct V_2 * V_3 , struct V_6 * V_6 )
{
int V_93 = F_1 ( V_3 ) -> V_93 ;
F_48 ( ! F_93 ( V_93 ) ) ;
F_48 ( ! V_6 -> V_36 ) ;
V_6 -> V_36 -- ;
F_100 ( F_3 ( V_6 ) ) ;
F_96 ( V_6 , V_3 -> V_52 ) ;
F_30 ( V_3 , V_6 ) ;
}
static void F_101 ( struct V_2 * V_3 )
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
if ( F_51 ( V_3 -> V_52 , V_40 -> V_52 ) )
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
F_97 ( V_3 , V_6 ) ;
}
static void F_102 ( struct V_2 * V_3 )
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
F_99 ( V_3 , V_6 ) ;
}
static void
F_103 ( struct V_2 * V_3 ,
struct V_2 * V_49 , int V_95 )
{
F_32 ( F_6 ( V_3 ) ) ;
if ( ! V_3 -> V_50 && V_95 & V_75 )
F_50 ( V_3 , V_49 ) ;
else
F_54 ( V_3 , V_49 ) ;
F_101 ( V_3 ) ;
}
static void F_104 ( struct V_2 * V_3 )
{
F_102 ( V_3 ) ;
}
static void F_70 ( struct V_5 * V_5 , struct V_1 * V_7 , int V_95 )
{
struct V_1 * V_96 = F_105 ( V_7 ) ;
struct V_2 * V_49 = & V_7 -> V_4 ;
if ( V_96 && V_7 -> V_4 . V_88 && F_93 ( V_96 -> V_97 ) )
V_49 = & V_96 -> V_4 ;
if ( V_7 -> V_4 . V_51 )
return;
F_103 ( & V_7 -> V_4 , V_49 , V_95 ) ;
if ( ! F_106 ( V_5 , V_7 ) && V_7 -> V_37 > 1 )
F_31 ( V_5 , V_7 ) ;
}
static void F_87 ( struct V_5 * V_5 , struct V_1 * V_7 , int V_95 )
{
F_104 ( & V_7 -> V_4 ) ;
F_37 ( V_5 , V_7 ) ;
}
static void F_107 ( struct V_5 * V_5 , struct V_1 * V_7 , int V_95 )
{
F_79 ( V_5 ) ;
F_87 ( V_5 , V_7 , V_95 ) ;
}
static void F_108 ( struct V_5 * V_5 )
{
struct V_1 * V_7 = V_5 -> V_26 ;
if ( V_7 -> V_4 . V_13 > 0 ) {
V_5 -> V_26 -> V_4 . V_73 = 1 ;
V_7 -> V_4 . V_13 = 0 ;
}
F_79 ( V_5 ) ;
}
static int
F_109 ( struct V_1 * V_7 , int V_34 , int V_98 , int V_95 )
{
struct V_1 * V_26 ;
struct V_5 * V_5 ;
if ( V_98 != V_99 && V_98 != V_100 )
goto V_101;
V_5 = F_110 ( V_34 ) ;
F_111 () ;
V_26 = F_112 ( V_5 -> V_26 ) ;
if ( F_81 ( F_44 ( V_26 ) ) &&
( V_26 -> V_37 < 2 ||
! F_34 ( & V_7 -> V_4 , & V_26 -> V_4 ) ) &&
( V_7 -> V_37 > 1 ) ) {
int V_102 = F_113 ( V_7 ) ;
if ( V_102 != - 1 )
V_34 = V_102 ;
}
F_114 () ;
V_101:
return V_34 ;
}
static void F_115 ( struct V_5 * V_5 , struct V_1 * V_7 )
{
if ( V_5 -> V_26 -> V_37 == 1 ||
F_116 ( & V_5 -> V_31 -> V_94 , V_5 -> V_26 , NULL ) == - 1 )
return;
if ( V_7 -> V_37 != 1 &&
F_116 ( & V_5 -> V_31 -> V_94 , V_7 , NULL ) != - 1 )
return;
F_73 ( V_5 -> V_26 ) ;
}
static void F_72 ( struct V_5 * V_5 , struct V_1 * V_7 ,
int V_95 )
{
if ( F_34 ( & V_7 -> V_4 , & V_5 -> V_26 -> V_4 ) ) {
F_73 ( V_5 -> V_26 ) ;
return;
}
#ifdef F_18
if ( ( V_7 -> V_4 . V_52 == V_5 -> V_26 -> V_4 . V_52 ) &&
! F_117 ( V_5 -> V_26 ) )
F_115 ( V_5 , V_7 ) ;
#endif
}
static void F_118 ( struct V_5 * V_5 , struct V_1 * V_7 )
{
T_3 V_65 = V_7 -> V_4 . V_16 - V_7 -> V_4 . V_13 ;
if ( V_65 > 10000 )
F_119 ( V_5 , V_7 -> V_4 . V_13 ) ;
}
static struct V_2 * F_120 ( struct V_5 * V_5 ,
struct V_6 * V_6 )
{
struct V_8 * V_56 = V_6 -> V_9 ;
if ( ! V_56 )
return NULL ;
return F_33 ( V_56 , struct V_2 , V_8 ) ;
}
struct V_1 * F_121 ( struct V_5 * V_5 , struct V_1 * V_47 )
{
struct V_2 * V_3 ;
struct V_1 * V_7 ;
struct V_6 * V_6 ;
V_6 = & V_5 -> V_4 ;
if ( F_43 ( V_5 , V_47 ) ) {
F_46 ( V_5 ) ;
if ( V_5 -> V_103 && V_5 -> V_103 -> V_74 )
return V_104 ;
}
if ( V_47 -> V_105 == & V_106 )
F_79 ( V_5 ) ;
if ( F_81 ( ! V_6 -> V_36 ) )
return NULL ;
F_122 ( V_5 , V_47 ) ;
V_3 = F_120 ( V_5 , V_6 ) ;
F_32 ( ! V_3 ) ;
V_7 = F_1 ( V_3 ) ;
V_7 -> V_83 . V_84 = F_80 ( V_5 ) ;
F_37 ( V_5 , V_7 ) ;
#ifdef F_123
if ( F_124 ( V_5 ) )
F_118 ( V_5 , V_7 ) ;
#endif
F_45 ( V_5 ) ;
return V_7 ;
}
static void F_125 ( struct V_5 * V_5 , struct V_1 * V_7 )
{
F_79 ( V_5 ) ;
if ( F_6 ( & V_7 -> V_4 ) && V_7 -> V_37 > 1 )
F_31 ( V_5 , V_7 ) ;
}
static void F_126 ( struct V_5 * V_5 , struct V_1 * V_7 , int V_107 )
{
F_79 ( V_5 ) ;
#ifdef F_123
if ( F_124 ( V_5 ) && V_107 && V_7 -> V_4 . V_13 > 0 )
F_118 ( V_5 , V_7 ) ;
#endif
}
static void F_127 ( struct V_1 * V_7 )
{
}
static void F_128 ( struct V_1 * V_7 )
{
struct V_69 * V_70 = & V_7 -> V_4 . V_66 ;
struct V_17 * V_11 = F_129 ( F_130 ( V_7 ) ) ;
F_131 ( & V_11 -> V_18 ) ;
V_11 -> V_22 -= V_7 -> V_4 . V_17 ;
F_132 ( & V_11 -> V_18 ) ;
F_133 ( V_70 ) ;
}
static void F_134 ( struct V_5 * V_5 )
{
struct V_1 * V_7 = V_5 -> V_26 ;
V_7 -> V_83 . V_84 = F_80 ( V_5 ) ;
F_37 ( V_5 , V_7 ) ;
}
static int F_135 ( struct V_5 * V_5 , struct V_1 * V_7 , int V_34 )
{
if ( ! F_136 ( V_5 , V_7 ) &&
( V_34 < 0 || F_137 ( V_34 , & V_7 -> V_108 ) ) &&
( V_7 -> V_37 > 1 ) )
return 1 ;
return 0 ;
}
static struct V_1 * F_92 ( struct V_5 * V_5 , int V_34 )
{
struct V_8 * V_46 = V_5 -> V_4 . V_9 ;
struct V_2 * V_3 ;
struct V_1 * V_7 = NULL ;
V_46:
V_46 = F_38 ( V_46 ) ;
if ( V_46 ) {
V_3 = F_33 ( V_46 , struct V_2 , V_8 ) ;
V_7 = F_1 ( V_3 ) ;
if ( F_135 ( V_5 , V_7 , V_34 ) )
return V_7 ;
goto V_46;
}
return NULL ;
}
static int F_113 ( struct V_1 * V_109 )
{
struct V_110 * V_111 ;
struct V_112 * V_113 = F_138 ( V_114 ) ;
int V_115 = F_139 () ;
int V_116 , V_34 = F_130 ( V_109 ) ;
if ( F_81 ( ! V_113 ) )
return - 1 ;
if ( V_109 -> V_37 == 1 )
return - 1 ;
V_116 = F_116 ( & F_5 ( V_109 ) -> V_31 -> V_94 ,
V_109 , V_113 ) ;
if ( V_116 == - 1 )
return - 1 ;
if ( F_137 ( V_34 , V_113 ) )
return V_34 ;
if ( ! F_137 ( V_115 , V_113 ) )
V_115 = - 1 ;
F_111 () ;
F_140 (cpu, sd) {
if ( V_111 -> V_95 & V_117 ) {
if ( V_115 != - 1 &&
F_137 ( V_115 , F_141 ( V_111 ) ) ) {
F_114 () ;
return V_115 ;
}
if ( V_116 < V_118 &&
F_137 ( V_116 , F_141 ( V_111 ) ) ) {
F_114 () ;
return V_116 ;
}
}
}
F_114 () ;
if ( V_115 != - 1 )
return V_115 ;
V_34 = F_142 ( V_113 ) ;
if ( V_34 < V_118 )
return V_34 ;
return - 1 ;
}
static struct V_5 * F_143 ( struct V_1 * V_109 , struct V_5 * V_5 )
{
struct V_5 * V_119 = NULL ;
int V_120 ;
int V_34 ;
for ( V_120 = 0 ; V_120 < V_121 ; V_120 ++ ) {
V_34 = F_113 ( V_109 ) ;
if ( ( V_34 == - 1 ) || ( V_34 == V_5 -> V_34 ) )
break;
V_119 = F_110 ( V_34 ) ;
if ( F_144 ( V_5 , V_119 ) ) {
if ( F_81 ( F_5 ( V_109 ) != V_5 ||
! F_137 ( V_119 -> V_34 ,
& V_109 -> V_108 ) ||
F_136 ( V_5 , V_109 ) || ! V_109 -> V_74 ) ) {
F_145 ( V_5 , V_119 ) ;
V_119 = NULL ;
break;
}
}
if ( ! V_119 -> V_4 . V_36 ||
F_51 ( V_109 -> V_4 . V_52 ,
V_119 -> V_4 . V_25 . V_26 ) )
break;
F_145 ( V_5 , V_119 ) ;
V_119 = NULL ;
}
return V_119 ;
}
static struct V_1 * F_146 ( struct V_5 * V_5 )
{
struct V_1 * V_7 ;
if ( ! F_41 ( V_5 ) )
return NULL ;
V_7 = F_33 ( V_5 -> V_4 . V_45 ,
struct V_1 , V_42 ) ;
F_32 ( V_5 -> V_34 != F_130 ( V_7 ) ) ;
F_32 ( F_106 ( V_5 , V_7 ) ) ;
F_32 ( V_7 -> V_37 <= 1 ) ;
F_32 ( ! V_7 -> V_74 ) ;
F_32 ( ! F_44 ( V_7 ) ) ;
return V_7 ;
}
static int F_74 ( struct V_5 * V_5 )
{
struct V_1 * V_122 ;
struct V_5 * V_119 ;
if ( ! V_5 -> V_4 . V_29 )
return 0 ;
V_122 = F_146 ( V_5 ) ;
if ( ! V_122 )
return 0 ;
V_123:
if ( F_81 ( V_122 == V_5 -> V_26 ) ) {
F_48 ( 1 ) ;
return 0 ;
}
if ( F_44 ( V_5 -> V_26 ) &&
F_51 ( V_122 -> V_4 . V_52 , V_5 -> V_26 -> V_4 . V_52 ) &&
V_5 -> V_26 -> V_37 > 1 ) {
F_73 ( V_5 -> V_26 ) ;
return 0 ;
}
F_147 ( V_122 ) ;
V_119 = F_143 ( V_122 , V_5 ) ;
if ( ! V_119 ) {
struct V_1 * V_109 ;
V_109 = F_146 ( V_5 ) ;
if ( F_130 ( V_122 ) == V_5 -> V_34 && V_109 == V_122 ) {
F_37 ( V_5 , V_122 ) ;
goto V_101;
}
if ( ! V_109 )
goto V_101;
F_148 ( V_122 ) ;
V_122 = V_109 ;
goto V_123;
}
F_149 ( V_5 , V_122 , 0 ) ;
F_150 ( V_122 , V_119 -> V_34 ) ;
F_151 ( V_119 , V_122 , 0 ) ;
F_73 ( V_119 -> V_26 ) ;
F_145 ( V_5 , V_119 ) ;
V_101:
F_148 ( V_122 ) ;
return 1 ;
}
static void F_152 ( struct V_5 * V_5 )
{
while ( F_74 ( V_5 ) )
;
}
static int F_46 ( struct V_5 * V_124 )
{
int V_115 = V_124 -> V_34 , V_125 = 0 , V_34 ;
struct V_1 * V_7 ;
struct V_5 * V_126 ;
T_1 V_127 = V_128 ;
if ( F_88 ( ! F_19 ( V_124 ) ) )
return 0 ;
F_153 () ;
F_154 (cpu, this_rq->rd->dlo_mask) {
if ( V_115 == V_34 )
continue;
V_126 = F_110 ( V_34 ) ;
if ( V_124 -> V_4 . V_36 &&
F_51 ( V_124 -> V_4 . V_25 . V_26 ,
V_126 -> V_4 . V_25 . V_27 ) )
continue;
F_144 ( V_124 , V_126 ) ;
if ( V_126 -> V_4 . V_36 <= 1 )
goto V_129;
V_7 = F_92 ( V_126 , V_115 ) ;
if ( V_7 && F_51 ( V_7 -> V_4 . V_52 , V_127 ) &&
( ! V_124 -> V_4 . V_36 ||
F_51 ( V_7 -> V_4 . V_52 ,
V_124 -> V_4 . V_25 . V_26 ) ) ) {
F_48 ( V_7 == V_126 -> V_26 ) ;
F_48 ( ! V_7 -> V_74 ) ;
if ( F_51 ( V_7 -> V_4 . V_52 ,
V_126 -> V_26 -> V_4 . V_52 ) )
goto V_129;
V_125 = 1 ;
F_149 ( V_126 , V_7 , 0 ) ;
F_150 ( V_7 , V_115 ) ;
F_151 ( V_124 , V_7 , 0 ) ;
V_127 = V_7 -> V_4 . V_52 ;
}
V_129:
F_145 ( V_124 , V_126 ) ;
}
return V_125 ;
}
static void F_155 ( struct V_5 * V_5 )
{
F_152 ( V_5 ) ;
}
static void F_156 ( struct V_5 * V_5 , struct V_1 * V_7 )
{
if ( ! F_136 ( V_5 , V_7 ) &&
! F_117 ( V_5 -> V_26 ) &&
F_41 ( V_5 ) &&
V_7 -> V_37 > 1 &&
F_44 ( V_5 -> V_26 ) &&
( V_5 -> V_26 -> V_37 < 2 ||
F_34 ( & V_5 -> V_26 -> V_4 , & V_7 -> V_4 ) ) ) {
F_152 ( V_5 ) ;
}
}
static void F_157 ( struct V_1 * V_7 ,
const struct V_112 * V_130 )
{
struct V_5 * V_5 ;
int V_131 ;
F_32 ( ! F_44 ( V_7 ) ) ;
if ( ! F_6 ( & V_7 -> V_4 ) )
return;
V_131 = F_158 ( V_130 ) ;
if ( ( V_7 -> V_37 > 1 ) == ( V_131 > 1 ) )
return;
V_5 = F_5 ( V_7 ) ;
if ( V_131 <= 1 ) {
if ( ! F_106 ( V_5 , V_7 ) )
F_37 ( V_5 , V_7 ) ;
F_32 ( ! V_5 -> V_4 . V_28 ) ;
V_5 -> V_4 . V_28 -- ;
} else {
if ( ! F_106 ( V_5 , V_7 ) )
F_31 ( V_5 , V_7 ) ;
V_5 -> V_4 . V_28 ++ ;
}
F_28 ( & V_5 -> V_4 ) ;
}
static void F_159 ( struct V_5 * V_5 )
{
if ( V_5 -> V_4 . V_29 )
F_21 ( V_5 ) ;
if ( V_5 -> V_4 . V_36 > 0 )
F_95 ( & V_5 -> V_31 -> V_94 , V_5 -> V_34 , V_5 -> V_4 . V_25 . V_26 , 1 ) ;
}
static void F_160 ( struct V_5 * V_5 )
{
if ( V_5 -> V_4 . V_29 )
F_25 ( V_5 ) ;
F_95 ( & V_5 -> V_31 -> V_94 , V_5 -> V_34 , 0 , 0 ) ;
}
void F_161 ( void )
{
unsigned int V_132 ;
F_162 (i)
F_163 ( & F_164 ( V_114 , V_132 ) ,
V_133 , F_165 ( V_132 ) ) ;
}
static void F_166 ( struct V_5 * V_5 , struct V_1 * V_7 )
{
if ( F_66 ( & V_7 -> V_4 . V_66 ) && ! F_167 ( V_7 -> V_134 ) )
F_76 ( & V_7 -> V_4 . V_66 ) ;
#ifdef F_18
if ( ! V_5 -> V_4 . V_36 )
F_46 ( V_5 ) ;
#endif
}
static void F_168 ( struct V_5 * V_5 , struct V_1 * V_7 )
{
int V_135 = 1 ;
if ( F_81 ( V_7 -> V_4 . V_51 ) )
return;
if ( V_7 -> V_74 && V_5 -> V_26 != V_7 ) {
#ifdef F_18
if ( V_5 -> V_4 . V_29 && F_74 ( V_5 ) && V_5 != F_5 ( V_7 ) )
V_135 = 0 ;
#endif
if ( V_135 && F_71 ( V_5 -> V_26 ) )
F_72 ( V_5 , V_7 , 0 ) ;
}
}
static void F_169 ( struct V_5 * V_5 , struct V_1 * V_7 ,
int V_136 )
{
if ( V_7 -> V_74 || V_5 -> V_26 == V_7 ) {
#ifdef F_18
if ( ! V_5 -> V_4 . V_29 )
F_46 ( V_5 ) ;
if ( F_51 ( V_5 -> V_4 . V_25 . V_26 , V_7 -> V_4 . V_52 ) &&
V_5 -> V_26 == V_7 )
F_73 ( V_7 ) ;
#else
F_73 ( V_7 ) ;
#endif
} else
F_168 ( V_5 , V_7 ) ;
}
