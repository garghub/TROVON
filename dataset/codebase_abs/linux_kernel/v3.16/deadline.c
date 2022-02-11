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
F_52 ( L_1 ) ;
V_3 -> V_52 = F_49 ( V_5 ) + V_49 -> V_53 ;
V_3 -> V_13 = V_49 -> V_16 ;
}
}
static bool F_53 ( struct V_2 * V_3 ,
struct V_2 * V_49 , T_1 V_54 )
{
T_1 V_55 , V_56 ;
V_55 = ( V_49 -> V_15 >> V_57 ) * ( V_3 -> V_13 >> V_57 ) ;
V_56 = ( ( V_3 -> V_52 - V_54 ) >> V_57 ) *
( V_49 -> V_16 >> V_57 ) ;
return F_51 ( V_56 , V_55 ) ;
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
static int F_55 ( struct V_2 * V_3 , bool V_58 )
{
struct V_6 * V_6 = F_4 ( V_3 ) ;
struct V_5 * V_5 = F_3 ( V_6 ) ;
T_2 V_59 , V_60 ;
T_2 V_61 , V_62 ;
unsigned long V_63 ;
T_3 V_64 ;
if ( V_58 )
return 0 ;
V_60 = F_56 ( V_3 -> V_52 ) ;
V_59 = F_57 ( & V_3 -> V_65 ) ;
V_64 = F_58 ( V_59 ) - F_49 ( V_5 ) ;
V_60 = F_59 ( V_60 , V_64 ) ;
if ( F_60 ( V_60 , V_59 ) < 0 )
return 0 ;
F_61 ( & V_3 -> V_65 , V_60 ) ;
V_61 = F_62 ( & V_3 -> V_65 ) ;
V_62 = F_63 ( & V_3 -> V_65 ) ;
V_63 = F_58 ( F_64 ( V_62 , V_61 ) ) ;
F_65 ( & V_3 -> V_65 , V_61 ,
V_63 , V_66 , 0 ) ;
return F_66 ( & V_3 -> V_65 ) ;
}
static enum V_67 F_67 ( struct V_68 * V_69 )
{
struct V_2 * V_3 = F_2 ( V_69 ,
struct V_2 ,
V_65 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_5 * V_5 ;
V_70:
V_5 = F_5 ( V_7 ) ;
F_12 ( & V_5 -> V_18 ) ;
if ( V_5 != F_5 ( V_7 ) ) {
F_16 ( & V_5 -> V_18 ) ;
goto V_70;
}
if ( ! F_44 ( V_7 ) || V_3 -> V_50 )
goto V_71;
F_68 () ;
F_69 ( V_5 ) ;
V_3 -> V_51 = 0 ;
V_3 -> V_72 = 0 ;
if ( V_7 -> V_73 ) {
F_70 ( V_5 , V_7 , V_74 ) ;
if ( F_71 ( V_5 -> V_26 ) )
F_72 ( V_5 , V_7 , 0 ) ;
else
F_73 ( V_5 -> V_26 ) ;
#ifdef F_18
if ( F_41 ( V_5 ) )
F_74 ( V_5 ) ;
#endif
}
V_71:
F_16 ( & V_5 -> V_18 ) ;
return V_75 ;
}
void F_75 ( struct V_2 * V_3 )
{
struct V_68 * V_69 = & V_3 -> V_65 ;
if ( F_66 ( V_69 ) ) {
F_76 ( V_69 ) ;
return;
}
F_77 ( V_69 , V_76 , V_77 ) ;
V_69 -> V_78 = F_67 ;
}
static
int F_78 ( struct V_5 * V_5 , struct V_2 * V_3 )
{
int V_79 = F_51 ( V_3 -> V_52 , F_49 ( V_5 ) ) ;
int V_80 = V_3 -> V_13 <= 0 ;
if ( ! V_80 && ! V_79 )
return 0 ;
if ( V_79 ) {
V_3 -> V_13 = V_80 ? V_3 -> V_13 : 0 ;
V_3 -> V_13 -= F_49 ( V_5 ) - V_3 -> V_52 ;
}
return 1 ;
}
static void F_79 ( struct V_5 * V_5 )
{
struct V_1 * V_26 = V_5 -> V_26 ;
struct V_2 * V_3 = & V_26 -> V_4 ;
T_1 V_81 ;
if ( ! F_44 ( V_26 ) || ! F_6 ( V_3 ) )
return;
V_81 = F_80 ( V_5 ) - V_26 -> V_82 . V_83 ;
if ( F_81 ( ( T_3 ) V_81 <= 0 ) )
return;
F_82 ( V_26 -> V_82 . V_84 . V_85 ,
F_83 ( V_26 -> V_82 . V_84 . V_85 , V_81 ) ) ;
V_26 -> V_82 . V_86 += V_81 ;
F_84 ( V_26 , V_81 ) ;
V_26 -> V_82 . V_83 = F_80 ( V_5 ) ;
F_85 ( V_26 , V_81 ) ;
F_86 ( V_5 , V_81 ) ;
V_3 -> V_13 -= V_81 ;
if ( F_78 ( V_5 , V_3 ) ) {
F_87 ( V_5 , V_26 , 0 ) ;
if ( F_88 ( F_55 ( V_3 , V_26 -> V_4 . V_87 ) ) )
V_3 -> V_51 = 1 ;
else
F_70 ( V_5 , V_26 , V_74 ) ;
if ( ! F_8 ( V_26 , & V_5 -> V_4 ) )
F_73 ( V_26 ) ;
}
if ( F_89 () ) {
struct V_88 * V_88 = & V_5 -> V_89 ;
F_12 ( & V_88 -> V_90 ) ;
if ( F_90 ( V_88 ) )
V_88 -> V_91 += V_81 ;
F_16 ( & V_88 -> V_90 ) ;
}
}
static inline T_1 F_91 ( struct V_5 * V_5 )
{
struct V_1 * V_27 = F_92 ( V_5 , V_5 -> V_34 ) ;
if ( V_27 && F_93 ( V_27 -> V_92 ) )
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
F_95 ( & V_5 -> V_31 -> V_93 , V_5 -> V_34 , V_52 , 1 ) ;
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
F_95 ( & V_5 -> V_31 -> V_93 , V_5 -> V_34 , 0 , 0 ) ;
} else {
struct V_8 * V_41 = V_6 -> V_9 ;
struct V_2 * V_40 ;
V_40 = F_33 ( V_41 , struct V_2 , V_8 ) ;
V_6 -> V_25 . V_26 = V_40 -> V_52 ;
V_6 -> V_25 . V_27 = F_91 ( V_5 ) ;
F_95 ( & V_5 -> V_31 -> V_93 , V_5 -> V_34 , V_40 -> V_52 , 1 ) ;
}
}
static inline void F_94 ( struct V_6 * V_6 , T_1 V_52 ) {}
static inline void F_96 ( struct V_6 * V_6 , T_1 V_52 ) {}
static inline
void F_97 ( struct V_2 * V_3 , struct V_6 * V_6 )
{
int V_92 = F_1 ( V_3 ) -> V_92 ;
T_1 V_52 = V_3 -> V_52 ;
F_48 ( ! F_93 ( V_92 ) ) ;
V_6 -> V_36 ++ ;
F_98 ( F_3 ( V_6 ) , 1 ) ;
F_94 ( V_6 , V_52 ) ;
F_29 ( V_3 , V_6 ) ;
}
static inline
void F_99 ( struct V_2 * V_3 , struct V_6 * V_6 )
{
int V_92 = F_1 ( V_3 ) -> V_92 ;
F_48 ( ! F_93 ( V_92 ) ) ;
F_48 ( ! V_6 -> V_36 ) ;
V_6 -> V_36 -- ;
F_100 ( F_3 ( V_6 ) , 1 ) ;
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
struct V_2 * V_49 , int V_94 )
{
F_32 ( F_6 ( V_3 ) ) ;
if ( ! V_3 -> V_50 && V_94 & V_74 )
F_50 ( V_3 , V_49 ) ;
else
F_54 ( V_3 , V_49 ) ;
F_101 ( V_3 ) ;
}
static void F_104 ( struct V_2 * V_3 )
{
F_102 ( V_3 ) ;
}
static void F_70 ( struct V_5 * V_5 , struct V_1 * V_7 , int V_94 )
{
struct V_1 * V_95 = F_105 ( V_7 ) ;
struct V_2 * V_49 = & V_7 -> V_4 ;
if ( V_95 && V_7 -> V_4 . V_87 && F_93 ( V_95 -> V_96 ) )
V_49 = & V_95 -> V_4 ;
if ( V_7 -> V_4 . V_51 )
return;
F_103 ( & V_7 -> V_4 , V_49 , V_94 ) ;
if ( ! F_106 ( V_5 , V_7 ) && V_7 -> V_37 > 1 )
F_31 ( V_5 , V_7 ) ;
}
static void F_87 ( struct V_5 * V_5 , struct V_1 * V_7 , int V_94 )
{
F_104 ( & V_7 -> V_4 ) ;
F_37 ( V_5 , V_7 ) ;
}
static void F_107 ( struct V_5 * V_5 , struct V_1 * V_7 , int V_94 )
{
F_79 ( V_5 ) ;
F_87 ( V_5 , V_7 , V_94 ) ;
}
static void F_108 ( struct V_5 * V_5 )
{
struct V_1 * V_7 = V_5 -> V_26 ;
if ( V_7 -> V_4 . V_13 > 0 ) {
V_5 -> V_26 -> V_4 . V_72 = 1 ;
V_7 -> V_4 . V_13 = 0 ;
}
F_79 ( V_5 ) ;
}
static int
F_109 ( struct V_1 * V_7 , int V_34 , int V_97 , int V_94 )
{
struct V_1 * V_26 ;
struct V_5 * V_5 ;
if ( V_97 != V_98 && V_97 != V_99 )
goto V_100;
V_5 = F_110 ( V_34 ) ;
F_111 () ;
V_26 = F_112 ( V_5 -> V_26 ) ;
if ( F_81 ( F_44 ( V_26 ) ) &&
( V_26 -> V_37 < 2 ||
! F_34 ( & V_7 -> V_4 , & V_26 -> V_4 ) ) &&
( V_7 -> V_37 > 1 ) ) {
int V_101 = F_113 ( V_7 ) ;
if ( V_101 != - 1 )
V_34 = V_101 ;
}
F_114 () ;
V_100:
return V_34 ;
}
static void F_115 ( struct V_5 * V_5 , struct V_1 * V_7 )
{
if ( V_5 -> V_26 -> V_37 == 1 ||
F_116 ( & V_5 -> V_31 -> V_93 , V_5 -> V_26 , NULL ) == - 1 )
return;
if ( V_7 -> V_37 != 1 &&
F_116 ( & V_5 -> V_31 -> V_93 , V_7 , NULL ) != - 1 )
return;
F_73 ( V_5 -> V_26 ) ;
}
static void F_72 ( struct V_5 * V_5 , struct V_1 * V_7 ,
int V_94 )
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
T_3 V_64 = V_7 -> V_4 . V_16 - V_7 -> V_4 . V_13 ;
if ( V_64 > 10000 )
F_119 ( V_5 , V_7 -> V_4 . V_13 ) ;
}
static struct V_2 * F_120 ( struct V_5 * V_5 ,
struct V_6 * V_6 )
{
struct V_8 * V_55 = V_6 -> V_9 ;
if ( ! V_55 )
return NULL ;
return F_33 ( V_55 , struct V_2 , V_8 ) ;
}
struct V_1 * F_121 ( struct V_5 * V_5 , struct V_1 * V_47 )
{
struct V_2 * V_3 ;
struct V_1 * V_7 ;
struct V_6 * V_6 ;
V_6 = & V_5 -> V_4 ;
if ( F_43 ( V_5 , V_47 ) ) {
F_46 ( V_5 ) ;
if ( V_5 -> V_102 && V_5 -> V_102 -> V_73 )
return V_103 ;
}
if ( V_47 -> V_104 == & V_105 )
F_79 ( V_5 ) ;
if ( F_81 ( ! V_6 -> V_36 ) )
return NULL ;
F_122 ( V_5 , V_47 ) ;
V_3 = F_120 ( V_5 , V_6 ) ;
F_32 ( ! V_3 ) ;
V_7 = F_1 ( V_3 ) ;
V_7 -> V_82 . V_83 = F_80 ( V_5 ) ;
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
static void F_126 ( struct V_5 * V_5 , struct V_1 * V_7 , int V_106 )
{
F_79 ( V_5 ) ;
#ifdef F_123
if ( F_124 ( V_5 ) && V_106 && V_7 -> V_4 . V_13 > 0 )
F_118 ( V_5 , V_7 ) ;
#endif
}
static void F_127 ( struct V_1 * V_7 )
{
}
static void F_128 ( struct V_1 * V_7 )
{
struct V_68 * V_69 = & V_7 -> V_4 . V_65 ;
struct V_17 * V_11 = F_129 ( F_130 ( V_7 ) ) ;
F_131 ( & V_11 -> V_18 ) ;
V_11 -> V_22 -= V_7 -> V_4 . V_17 ;
F_132 ( & V_11 -> V_18 ) ;
F_133 ( V_69 ) ;
}
static void F_134 ( struct V_5 * V_5 )
{
struct V_1 * V_7 = V_5 -> V_26 ;
V_7 -> V_82 . V_83 = F_80 ( V_5 ) ;
F_37 ( V_5 , V_7 ) ;
}
static int F_135 ( struct V_5 * V_5 , struct V_1 * V_7 , int V_34 )
{
if ( ! F_136 ( V_5 , V_7 ) &&
( V_34 < 0 || F_137 ( V_34 , & V_7 -> V_107 ) ) &&
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
static int F_113 ( struct V_1 * V_108 )
{
struct V_109 * V_110 ;
struct V_111 * V_112 = F_138 ( V_113 ) ;
int V_114 = F_139 () ;
int V_115 , V_34 = F_130 ( V_108 ) ;
if ( F_81 ( ! V_112 ) )
return - 1 ;
if ( V_108 -> V_37 == 1 )
return - 1 ;
V_115 = F_116 ( & F_5 ( V_108 ) -> V_31 -> V_93 ,
V_108 , V_112 ) ;
if ( V_115 == - 1 )
return - 1 ;
if ( F_137 ( V_34 , V_112 ) )
return V_34 ;
if ( ! F_137 ( V_114 , V_112 ) )
V_114 = - 1 ;
F_111 () ;
F_140 (cpu, sd) {
if ( V_110 -> V_94 & V_116 ) {
if ( V_114 != - 1 &&
F_137 ( V_114 , F_141 ( V_110 ) ) ) {
F_114 () ;
return V_114 ;
}
if ( V_115 < V_117 &&
F_137 ( V_115 , F_141 ( V_110 ) ) ) {
F_114 () ;
return V_115 ;
}
}
}
F_114 () ;
if ( V_114 != - 1 )
return V_114 ;
V_34 = F_142 ( V_112 ) ;
if ( V_34 < V_117 )
return V_34 ;
return - 1 ;
}
static struct V_5 * F_143 ( struct V_1 * V_108 , struct V_5 * V_5 )
{
struct V_5 * V_118 = NULL ;
int V_119 ;
int V_34 ;
for ( V_119 = 0 ; V_119 < V_120 ; V_119 ++ ) {
V_34 = F_113 ( V_108 ) ;
if ( ( V_34 == - 1 ) || ( V_34 == V_5 -> V_34 ) )
break;
V_118 = F_110 ( V_34 ) ;
if ( F_144 ( V_5 , V_118 ) ) {
if ( F_81 ( F_5 ( V_108 ) != V_5 ||
! F_137 ( V_118 -> V_34 ,
& V_108 -> V_107 ) ||
F_136 ( V_5 , V_108 ) || ! V_108 -> V_73 ) ) {
F_145 ( V_5 , V_118 ) ;
V_118 = NULL ;
break;
}
}
if ( ! V_118 -> V_4 . V_36 ||
F_51 ( V_108 -> V_4 . V_52 ,
V_118 -> V_4 . V_25 . V_26 ) )
break;
F_145 ( V_5 , V_118 ) ;
V_118 = NULL ;
}
return V_118 ;
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
F_32 ( ! V_7 -> V_73 ) ;
F_32 ( ! F_44 ( V_7 ) ) ;
return V_7 ;
}
static int F_74 ( struct V_5 * V_5 )
{
struct V_1 * V_121 ;
struct V_5 * V_118 ;
if ( ! V_5 -> V_4 . V_29 )
return 0 ;
V_121 = F_146 ( V_5 ) ;
if ( ! V_121 )
return 0 ;
V_122:
if ( F_81 ( V_121 == V_5 -> V_26 ) ) {
F_48 ( 1 ) ;
return 0 ;
}
if ( F_44 ( V_5 -> V_26 ) &&
F_51 ( V_121 -> V_4 . V_52 , V_5 -> V_26 -> V_4 . V_52 ) &&
V_5 -> V_26 -> V_37 > 1 ) {
F_73 ( V_5 -> V_26 ) ;
return 0 ;
}
F_147 ( V_121 ) ;
V_118 = F_143 ( V_121 , V_5 ) ;
if ( ! V_118 ) {
struct V_1 * V_108 ;
V_108 = F_146 ( V_5 ) ;
if ( F_130 ( V_121 ) == V_5 -> V_34 && V_108 == V_121 ) {
F_37 ( V_5 , V_121 ) ;
goto V_100;
}
if ( ! V_108 )
goto V_100;
F_148 ( V_121 ) ;
V_121 = V_108 ;
goto V_122;
}
F_149 ( V_5 , V_121 , 0 ) ;
F_150 ( V_121 , V_118 -> V_34 ) ;
F_151 ( V_118 , V_121 , 0 ) ;
F_73 ( V_118 -> V_26 ) ;
F_145 ( V_5 , V_118 ) ;
V_100:
F_148 ( V_121 ) ;
return 1 ;
}
static void F_152 ( struct V_5 * V_5 )
{
while ( F_74 ( V_5 ) )
;
}
static int F_46 ( struct V_5 * V_123 )
{
int V_114 = V_123 -> V_34 , V_124 = 0 , V_34 ;
struct V_1 * V_7 ;
struct V_5 * V_125 ;
T_1 V_126 = V_127 ;
if ( F_88 ( ! F_19 ( V_123 ) ) )
return 0 ;
F_153 () ;
F_154 (cpu, this_rq->rd->dlo_mask) {
if ( V_114 == V_34 )
continue;
V_125 = F_110 ( V_34 ) ;
if ( V_123 -> V_4 . V_36 &&
F_51 ( V_123 -> V_4 . V_25 . V_26 ,
V_125 -> V_4 . V_25 . V_27 ) )
continue;
F_144 ( V_123 , V_125 ) ;
if ( V_125 -> V_4 . V_36 <= 1 )
goto V_128;
V_7 = F_92 ( V_125 , V_114 ) ;
if ( V_7 && F_51 ( V_7 -> V_4 . V_52 , V_126 ) &&
( ! V_123 -> V_4 . V_36 ||
F_51 ( V_7 -> V_4 . V_52 ,
V_123 -> V_4 . V_25 . V_26 ) ) ) {
F_48 ( V_7 == V_125 -> V_26 ) ;
F_48 ( ! V_7 -> V_73 ) ;
if ( F_51 ( V_7 -> V_4 . V_52 ,
V_125 -> V_26 -> V_4 . V_52 ) )
goto V_128;
V_124 = 1 ;
F_149 ( V_125 , V_7 , 0 ) ;
F_150 ( V_7 , V_114 ) ;
F_151 ( V_123 , V_7 , 0 ) ;
V_126 = V_7 -> V_4 . V_52 ;
}
V_128:
F_145 ( V_123 , V_125 ) ;
}
return V_124 ;
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
const struct V_111 * V_129 )
{
struct V_5 * V_5 ;
int V_130 ;
F_32 ( ! F_44 ( V_7 ) ) ;
if ( ! F_6 ( & V_7 -> V_4 ) )
return;
V_130 = F_158 ( V_129 ) ;
if ( ( V_7 -> V_37 > 1 ) == ( V_130 > 1 ) )
return;
V_5 = F_5 ( V_7 ) ;
if ( V_130 <= 1 ) {
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
F_95 ( & V_5 -> V_31 -> V_93 , V_5 -> V_34 , V_5 -> V_4 . V_25 . V_26 , 1 ) ;
}
static void F_160 ( struct V_5 * V_5 )
{
if ( V_5 -> V_4 . V_29 )
F_25 ( V_5 ) ;
F_95 ( & V_5 -> V_31 -> V_93 , V_5 -> V_34 , 0 , 0 ) ;
}
void F_161 ( void )
{
unsigned int V_131 ;
F_162 (i)
F_163 ( & F_164 ( V_113 , V_131 ) ,
V_132 , F_165 ( V_131 ) ) ;
}
static void F_166 ( struct V_5 * V_5 , struct V_1 * V_7 )
{
if ( F_66 ( & V_7 -> V_4 . V_65 ) && ! F_167 ( V_7 -> V_133 ) )
F_76 ( & V_7 -> V_4 . V_65 ) ;
#ifdef F_18
if ( ! V_5 -> V_4 . V_36 )
F_46 ( V_5 ) ;
#endif
}
static void F_168 ( struct V_5 * V_5 , struct V_1 * V_7 )
{
int V_134 = 1 ;
if ( F_81 ( V_7 -> V_4 . V_51 ) )
return;
if ( V_7 -> V_73 && V_5 -> V_26 != V_7 ) {
#ifdef F_18
if ( V_5 -> V_4 . V_29 && F_74 ( V_5 ) && V_5 != F_5 ( V_7 ) )
V_134 = 0 ;
#endif
if ( V_134 && F_71 ( V_5 -> V_26 ) )
F_72 ( V_5 , V_7 , 0 ) ;
}
}
static void F_169 ( struct V_5 * V_5 , struct V_1 * V_7 ,
int V_135 )
{
if ( V_7 -> V_73 || V_5 -> V_26 == V_7 ) {
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
