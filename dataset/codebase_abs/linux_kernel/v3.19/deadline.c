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
if ( ! F_44 ( V_7 ) || V_3 -> V_50 ||
V_3 -> V_71 || ! V_3 -> V_51 )
goto V_72;
F_68 () ;
F_69 ( V_5 ) ;
V_3 -> V_51 = 0 ;
V_3 -> V_73 = 0 ;
if ( F_70 ( V_7 ) ) {
F_71 ( V_5 , V_7 , V_74 ) ;
if ( F_44 ( V_5 -> V_26 ) )
F_72 ( V_5 , V_7 , 0 ) ;
else
F_73 ( V_5 ) ;
#ifdef F_18
if ( F_41 ( V_5 ) )
F_74 ( V_5 ) ;
#endif
}
V_72:
F_16 ( & V_5 -> V_18 ) ;
return V_75 ;
}
void F_75 ( struct V_2 * V_3 )
{
struct V_68 * V_69 = & V_3 -> V_65 ;
F_76 ( V_69 , V_76 , V_77 ) ;
V_69 -> V_78 = F_67 ;
}
static
int F_77 ( struct V_5 * V_5 , struct V_2 * V_3 )
{
return ( V_3 -> V_13 <= 0 ) ;
}
static void F_78 ( struct V_5 * V_5 )
{
struct V_1 * V_26 = V_5 -> V_26 ;
struct V_2 * V_3 = & V_26 -> V_4 ;
T_1 V_79 ;
if ( ! F_44 ( V_26 ) || ! F_6 ( V_3 ) )
return;
V_79 = F_79 ( V_5 ) - V_26 -> V_80 . V_81 ;
if ( F_80 ( ( T_3 ) V_79 <= 0 ) )
return;
F_81 ( V_26 -> V_80 . V_82 . V_83 ,
F_82 ( V_26 -> V_80 . V_82 . V_83 , V_79 ) ) ;
V_26 -> V_80 . V_84 += V_79 ;
F_83 ( V_26 , V_79 ) ;
V_26 -> V_80 . V_81 = F_79 ( V_5 ) ;
F_84 ( V_26 , V_79 ) ;
F_85 ( V_5 , V_79 ) ;
V_3 -> V_13 -= V_3 -> V_73 ? 0 : V_79 ;
if ( F_77 ( V_5 , V_3 ) ) {
F_86 ( V_5 , V_26 , 0 ) ;
if ( F_87 ( F_55 ( V_3 , V_26 -> V_4 . V_71 ) ) )
V_3 -> V_51 = 1 ;
else
F_71 ( V_5 , V_26 , V_74 ) ;
if ( ! F_8 ( V_26 , & V_5 -> V_4 ) )
F_73 ( V_5 ) ;
}
if ( F_88 () ) {
struct V_85 * V_85 = & V_5 -> V_86 ;
F_12 ( & V_85 -> V_87 ) ;
if ( F_89 ( V_85 ) )
V_85 -> V_88 += V_79 ;
F_16 ( & V_85 -> V_87 ) ;
}
}
static inline T_1 F_90 ( struct V_5 * V_5 )
{
struct V_1 * V_27 = F_91 ( V_5 , V_5 -> V_34 ) ;
if ( V_27 && F_92 ( V_27 -> V_89 ) )
return V_27 -> V_4 . V_52 ;
else
return 0 ;
}
static void F_93 ( struct V_6 * V_6 , T_1 V_52 )
{
struct V_5 * V_5 = F_3 ( V_6 ) ;
if ( V_6 -> V_25 . V_26 == 0 ||
F_51 ( V_52 , V_6 -> V_25 . V_26 ) ) {
V_6 -> V_25 . V_27 = V_6 -> V_25 . V_26 ;
V_6 -> V_25 . V_26 = V_52 ;
F_94 ( & V_5 -> V_31 -> V_90 , V_5 -> V_34 , V_52 , 1 ) ;
} else if ( V_6 -> V_25 . V_27 == 0 ||
F_51 ( V_52 , V_6 -> V_25 . V_27 ) ) {
V_6 -> V_25 . V_27 = F_90 ( V_5 ) ;
}
}
static void F_95 ( struct V_6 * V_6 , T_1 V_52 )
{
struct V_5 * V_5 = F_3 ( V_6 ) ;
if ( ! V_6 -> V_36 ) {
V_6 -> V_25 . V_26 = 0 ;
V_6 -> V_25 . V_27 = 0 ;
F_94 ( & V_5 -> V_31 -> V_90 , V_5 -> V_34 , 0 , 0 ) ;
} else {
struct V_8 * V_41 = V_6 -> V_9 ;
struct V_2 * V_40 ;
V_40 = F_33 ( V_41 , struct V_2 , V_8 ) ;
V_6 -> V_25 . V_26 = V_40 -> V_52 ;
V_6 -> V_25 . V_27 = F_90 ( V_5 ) ;
F_94 ( & V_5 -> V_31 -> V_90 , V_5 -> V_34 , V_40 -> V_52 , 1 ) ;
}
}
static inline void F_93 ( struct V_6 * V_6 , T_1 V_52 ) {}
static inline void F_95 ( struct V_6 * V_6 , T_1 V_52 ) {}
static inline
void F_96 ( struct V_2 * V_3 , struct V_6 * V_6 )
{
int V_89 = F_1 ( V_3 ) -> V_89 ;
T_1 V_52 = V_3 -> V_52 ;
F_48 ( ! F_92 ( V_89 ) ) ;
V_6 -> V_36 ++ ;
F_97 ( F_3 ( V_6 ) , 1 ) ;
F_93 ( V_6 , V_52 ) ;
F_29 ( V_3 , V_6 ) ;
}
static inline
void F_98 ( struct V_2 * V_3 , struct V_6 * V_6 )
{
int V_89 = F_1 ( V_3 ) -> V_89 ;
F_48 ( ! F_92 ( V_89 ) ) ;
F_48 ( ! V_6 -> V_36 ) ;
V_6 -> V_36 -- ;
F_99 ( F_3 ( V_6 ) , 1 ) ;
F_95 ( V_6 , V_3 -> V_52 ) ;
F_30 ( V_3 , V_6 ) ;
}
static void F_100 ( struct V_2 * V_3 )
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
F_96 ( V_3 , V_6 ) ;
}
static void F_101 ( struct V_2 * V_3 )
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
F_98 ( V_3 , V_6 ) ;
}
static void
F_102 ( struct V_2 * V_3 ,
struct V_2 * V_49 , int V_91 )
{
F_32 ( F_6 ( V_3 ) ) ;
if ( V_3 -> V_50 || V_91 & V_92 )
F_54 ( V_3 , V_49 ) ;
else if ( V_91 & V_74 )
F_50 ( V_3 , V_49 ) ;
F_100 ( V_3 ) ;
}
static void F_103 ( struct V_2 * V_3 )
{
F_101 ( V_3 ) ;
}
static void F_71 ( struct V_5 * V_5 , struct V_1 * V_7 , int V_91 )
{
struct V_1 * V_93 = F_104 ( V_7 ) ;
struct V_2 * V_49 = & V_7 -> V_4 ;
if ( V_93 && V_7 -> V_4 . V_71 && F_92 ( V_93 -> V_94 ) ) {
V_49 = & V_93 -> V_4 ;
} else if ( ! F_92 ( V_7 -> V_94 ) ) {
F_32 ( ! V_7 -> V_4 . V_71 || V_91 != V_74 ) ;
return;
}
if ( V_7 -> V_4 . V_51 )
return;
F_102 ( & V_7 -> V_4 , V_49 , V_91 ) ;
if ( ! F_105 ( V_5 , V_7 ) && V_7 -> V_37 > 1 )
F_31 ( V_5 , V_7 ) ;
}
static void F_86 ( struct V_5 * V_5 , struct V_1 * V_7 , int V_91 )
{
F_103 ( & V_7 -> V_4 ) ;
F_37 ( V_5 , V_7 ) ;
}
static void F_106 ( struct V_5 * V_5 , struct V_1 * V_7 , int V_91 )
{
F_78 ( V_5 ) ;
F_86 ( V_5 , V_7 , V_91 ) ;
}
static void F_107 ( struct V_5 * V_5 )
{
struct V_1 * V_7 = V_5 -> V_26 ;
if ( V_7 -> V_4 . V_13 > 0 ) {
V_5 -> V_26 -> V_4 . V_73 = 1 ;
V_7 -> V_4 . V_13 = 0 ;
}
F_78 ( V_5 ) ;
}
static int
F_108 ( struct V_1 * V_7 , int V_34 , int V_95 , int V_91 )
{
struct V_1 * V_26 ;
struct V_5 * V_5 ;
if ( V_95 != V_96 )
goto V_97;
V_5 = F_109 ( V_34 ) ;
F_110 () ;
V_26 = F_111 ( V_5 -> V_26 ) ;
if ( F_80 ( F_44 ( V_26 ) ) &&
( V_26 -> V_37 < 2 ||
! F_34 ( & V_7 -> V_4 , & V_26 -> V_4 ) ) &&
( V_7 -> V_37 > 1 ) ) {
int V_98 = F_112 ( V_7 ) ;
if ( V_98 != - 1 )
V_34 = V_98 ;
}
F_113 () ;
V_97:
return V_34 ;
}
static void F_114 ( struct V_5 * V_5 , struct V_1 * V_7 )
{
if ( V_5 -> V_26 -> V_37 == 1 ||
F_115 ( & V_5 -> V_31 -> V_90 , V_5 -> V_26 , NULL ) == - 1 )
return;
if ( V_7 -> V_37 != 1 &&
F_115 ( & V_5 -> V_31 -> V_90 , V_7 , NULL ) != - 1 )
return;
F_73 ( V_5 ) ;
}
static void F_72 ( struct V_5 * V_5 , struct V_1 * V_7 ,
int V_91 )
{
if ( F_34 ( & V_7 -> V_4 , & V_5 -> V_26 -> V_4 ) ) {
F_73 ( V_5 ) ;
return;
}
#ifdef F_18
if ( ( V_7 -> V_4 . V_52 == V_5 -> V_26 -> V_4 . V_52 ) &&
! F_116 ( V_5 -> V_26 ) )
F_114 ( V_5 , V_7 ) ;
#endif
}
static void F_117 ( struct V_5 * V_5 , struct V_1 * V_7 )
{
F_118 ( V_5 , V_7 -> V_4 . V_13 ) ;
}
static void F_117 ( struct V_5 * V_5 , struct V_1 * V_7 )
{
}
static struct V_2 * F_119 ( struct V_5 * V_5 ,
struct V_6 * V_6 )
{
struct V_8 * V_55 = V_6 -> V_9 ;
if ( ! V_55 )
return NULL ;
return F_33 ( V_55 , struct V_2 , V_8 ) ;
}
struct V_1 * F_120 ( struct V_5 * V_5 , struct V_1 * V_47 )
{
struct V_2 * V_3 ;
struct V_1 * V_7 ;
struct V_6 * V_6 ;
V_6 = & V_5 -> V_4 ;
if ( F_43 ( V_5 , V_47 ) ) {
F_46 ( V_5 ) ;
if ( V_5 -> V_99 && F_70 ( V_5 -> V_99 ) )
return V_100 ;
}
if ( V_47 -> V_101 == & V_102 )
F_78 ( V_5 ) ;
if ( F_80 ( ! V_6 -> V_36 ) )
return NULL ;
F_121 ( V_5 , V_47 ) ;
V_3 = F_119 ( V_5 , V_6 ) ;
F_32 ( ! V_3 ) ;
V_7 = F_1 ( V_3 ) ;
V_7 -> V_80 . V_81 = F_79 ( V_5 ) ;
F_37 ( V_5 , V_7 ) ;
if ( F_122 ( V_5 ) )
F_117 ( V_5 , V_7 ) ;
F_45 ( V_5 ) ;
return V_7 ;
}
static void F_123 ( struct V_5 * V_5 , struct V_1 * V_7 )
{
F_78 ( V_5 ) ;
if ( F_6 ( & V_7 -> V_4 ) && V_7 -> V_37 > 1 )
F_31 ( V_5 , V_7 ) ;
}
static void F_124 ( struct V_5 * V_5 , struct V_1 * V_7 , int V_103 )
{
F_78 ( V_5 ) ;
if ( F_122 ( V_5 ) && V_103 && V_7 -> V_4 . V_13 > 0 )
F_117 ( V_5 , V_7 ) ;
}
static void F_125 ( struct V_1 * V_7 )
{
}
static void F_126 ( struct V_1 * V_7 )
{
struct V_68 * V_69 = & V_7 -> V_4 . V_65 ;
struct V_17 * V_11 = F_127 ( F_128 ( V_7 ) ) ;
F_129 ( & V_11 -> V_18 ) ;
V_11 -> V_22 -= V_7 -> V_4 . V_17 ;
F_130 ( & V_11 -> V_18 ) ;
F_131 ( V_69 ) ;
}
static void F_132 ( struct V_5 * V_5 )
{
struct V_1 * V_7 = V_5 -> V_26 ;
V_7 -> V_80 . V_81 = F_79 ( V_5 ) ;
F_37 ( V_5 , V_7 ) ;
}
static int F_133 ( struct V_5 * V_5 , struct V_1 * V_7 , int V_34 )
{
if ( ! F_134 ( V_5 , V_7 ) &&
F_135 ( V_34 , F_136 ( V_7 ) ) )
return 1 ;
return 0 ;
}
static struct V_1 * F_91 ( struct V_5 * V_5 , int V_34 )
{
struct V_8 * V_46 = V_5 -> V_4 . V_9 ;
struct V_2 * V_3 ;
struct V_1 * V_7 = NULL ;
V_46:
V_46 = F_38 ( V_46 ) ;
if ( V_46 ) {
V_3 = F_33 ( V_46 , struct V_2 , V_8 ) ;
V_7 = F_1 ( V_3 ) ;
if ( F_133 ( V_5 , V_7 , V_34 ) )
return V_7 ;
goto V_46;
}
return NULL ;
}
static int F_112 ( struct V_1 * V_104 )
{
struct V_105 * V_106 ;
struct V_107 * V_108 = F_137 ( V_109 ) ;
int V_110 = F_138 () ;
int V_111 , V_34 = F_128 ( V_104 ) ;
if ( F_80 ( ! V_108 ) )
return - 1 ;
if ( V_104 -> V_37 == 1 )
return - 1 ;
F_139 ( V_108 , F_5 ( V_104 ) -> V_31 -> V_112 ) ;
F_140 ( V_108 , V_108 , V_113 ) ;
F_140 ( V_108 , V_108 , & V_104 -> V_114 ) ;
V_111 = F_115 ( & F_5 ( V_104 ) -> V_31 -> V_90 ,
V_104 , V_108 ) ;
if ( V_111 == - 1 )
return - 1 ;
if ( F_135 ( V_34 , V_108 ) )
return V_34 ;
if ( ! F_135 ( V_110 , V_108 ) )
V_110 = - 1 ;
F_110 () ;
F_141 (cpu, sd) {
if ( V_106 -> V_91 & V_115 ) {
if ( V_110 != - 1 &&
F_135 ( V_110 , F_142 ( V_106 ) ) ) {
F_113 () ;
return V_110 ;
}
if ( V_111 < V_116 &&
F_135 ( V_111 , F_142 ( V_106 ) ) ) {
F_113 () ;
return V_111 ;
}
}
}
F_113 () ;
if ( V_110 != - 1 )
return V_110 ;
V_34 = F_143 ( V_108 ) ;
if ( V_34 < V_116 )
return V_34 ;
return - 1 ;
}
static struct V_5 * F_144 ( struct V_1 * V_104 , struct V_5 * V_5 )
{
struct V_5 * V_117 = NULL ;
int V_118 ;
int V_34 ;
for ( V_118 = 0 ; V_118 < V_119 ; V_118 ++ ) {
V_34 = F_112 ( V_104 ) ;
if ( ( V_34 == - 1 ) || ( V_34 == V_5 -> V_34 ) )
break;
V_117 = F_109 ( V_34 ) ;
if ( F_145 ( V_5 , V_117 ) ) {
if ( F_80 ( F_5 ( V_104 ) != V_5 ||
! F_135 ( V_117 -> V_34 ,
& V_104 -> V_114 ) ||
F_134 ( V_5 , V_104 ) ||
! F_70 ( V_104 ) ) ) {
F_146 ( V_5 , V_117 ) ;
V_117 = NULL ;
break;
}
}
if ( ! V_117 -> V_4 . V_36 ||
F_51 ( V_104 -> V_4 . V_52 ,
V_117 -> V_4 . V_25 . V_26 ) )
break;
F_146 ( V_5 , V_117 ) ;
V_117 = NULL ;
}
return V_117 ;
}
static struct V_1 * F_147 ( struct V_5 * V_5 )
{
struct V_1 * V_7 ;
if ( ! F_41 ( V_5 ) )
return NULL ;
V_7 = F_33 ( V_5 -> V_4 . V_45 ,
struct V_1 , V_42 ) ;
F_32 ( V_5 -> V_34 != F_128 ( V_7 ) ) ;
F_32 ( F_105 ( V_5 , V_7 ) ) ;
F_32 ( V_7 -> V_37 <= 1 ) ;
F_32 ( ! F_70 ( V_7 ) ) ;
F_32 ( ! F_44 ( V_7 ) ) ;
return V_7 ;
}
static int F_74 ( struct V_5 * V_5 )
{
struct V_1 * V_120 ;
struct V_5 * V_117 ;
int V_121 = 0 ;
if ( ! V_5 -> V_4 . V_29 )
return 0 ;
V_120 = F_147 ( V_5 ) ;
if ( ! V_120 )
return 0 ;
V_122:
if ( F_80 ( V_120 == V_5 -> V_26 ) ) {
F_48 ( 1 ) ;
return 0 ;
}
if ( F_44 ( V_5 -> V_26 ) &&
F_51 ( V_120 -> V_4 . V_52 , V_5 -> V_26 -> V_4 . V_52 ) &&
V_5 -> V_26 -> V_37 > 1 ) {
F_73 ( V_5 ) ;
return 0 ;
}
F_148 ( V_120 ) ;
V_117 = F_144 ( V_120 , V_5 ) ;
if ( ! V_117 ) {
struct V_1 * V_104 ;
V_104 = F_147 ( V_5 ) ;
if ( F_128 ( V_120 ) == V_5 -> V_34 && V_104 == V_120 ) {
goto V_97;
}
if ( ! V_104 )
goto V_97;
F_149 ( V_120 ) ;
V_120 = V_104 ;
goto V_122;
}
F_150 ( V_5 , V_120 , 0 ) ;
F_151 ( V_120 , V_117 -> V_34 ) ;
F_152 ( V_117 , V_120 , 0 ) ;
V_121 = 1 ;
F_73 ( V_117 ) ;
F_146 ( V_5 , V_117 ) ;
V_97:
F_149 ( V_120 ) ;
return V_121 ;
}
static void F_153 ( struct V_5 * V_5 )
{
while ( F_74 ( V_5 ) )
;
}
static int F_46 ( struct V_5 * V_123 )
{
int V_110 = V_123 -> V_34 , V_121 = 0 , V_34 ;
struct V_1 * V_7 ;
struct V_5 * V_124 ;
T_1 V_125 = V_126 ;
if ( F_87 ( ! F_19 ( V_123 ) ) )
return 0 ;
F_154 () ;
F_155 (cpu, this_rq->rd->dlo_mask) {
if ( V_110 == V_34 )
continue;
V_124 = F_109 ( V_34 ) ;
if ( V_123 -> V_4 . V_36 &&
F_51 ( V_123 -> V_4 . V_25 . V_26 ,
V_124 -> V_4 . V_25 . V_27 ) )
continue;
F_145 ( V_123 , V_124 ) ;
if ( V_124 -> V_4 . V_36 <= 1 )
goto V_127;
V_7 = F_91 ( V_124 , V_110 ) ;
if ( V_7 && F_51 ( V_7 -> V_4 . V_52 , V_125 ) &&
( ! V_123 -> V_4 . V_36 ||
F_51 ( V_7 -> V_4 . V_52 ,
V_123 -> V_4 . V_25 . V_26 ) ) ) {
F_48 ( V_7 == V_124 -> V_26 ) ;
F_48 ( ! F_70 ( V_7 ) ) ;
if ( F_51 ( V_7 -> V_4 . V_52 ,
V_124 -> V_26 -> V_4 . V_52 ) )
goto V_127;
V_121 = 1 ;
F_150 ( V_124 , V_7 , 0 ) ;
F_151 ( V_7 , V_110 ) ;
F_152 ( V_123 , V_7 , 0 ) ;
V_125 = V_7 -> V_4 . V_52 ;
}
V_127:
F_146 ( V_123 , V_124 ) ;
}
return V_121 ;
}
static void F_156 ( struct V_5 * V_5 )
{
F_153 ( V_5 ) ;
}
static void F_157 ( struct V_5 * V_5 , struct V_1 * V_7 )
{
if ( ! F_134 ( V_5 , V_7 ) &&
! F_116 ( V_5 -> V_26 ) &&
F_41 ( V_5 ) &&
V_7 -> V_37 > 1 &&
F_44 ( V_5 -> V_26 ) &&
( V_5 -> V_26 -> V_37 < 2 ||
! F_34 ( & V_7 -> V_4 , & V_5 -> V_26 -> V_4 ) ) ) {
F_153 ( V_5 ) ;
}
}
static void F_158 ( struct V_1 * V_7 ,
const struct V_107 * V_128 )
{
struct V_5 * V_5 ;
struct V_129 * V_130 ;
int V_131 ;
F_32 ( ! F_44 ( V_7 ) ) ;
V_5 = F_5 ( V_7 ) ;
V_130 = V_5 -> V_31 ;
if ( ! F_159 ( V_130 -> V_112 , V_128 ) ) {
struct V_17 * V_132 ;
V_132 = F_127 ( F_160 ( V_5 ) ) ;
F_12 ( & V_132 -> V_18 ) ;
F_161 ( V_132 , V_7 -> V_4 . V_17 ) ;
F_16 ( & V_132 -> V_18 ) ;
}
if ( ! F_6 ( & V_7 -> V_4 ) )
return;
V_131 = F_162 ( V_128 ) ;
if ( ( V_7 -> V_37 > 1 ) == ( V_131 > 1 ) )
return;
if ( V_131 <= 1 ) {
if ( ! F_105 ( V_5 , V_7 ) )
F_37 ( V_5 , V_7 ) ;
F_32 ( ! V_5 -> V_4 . V_28 ) ;
V_5 -> V_4 . V_28 -- ;
} else {
if ( ! F_105 ( V_5 , V_7 ) )
F_31 ( V_5 , V_7 ) ;
V_5 -> V_4 . V_28 ++ ;
}
F_28 ( & V_5 -> V_4 ) ;
}
static void F_163 ( struct V_5 * V_5 )
{
if ( V_5 -> V_4 . V_29 )
F_21 ( V_5 ) ;
if ( V_5 -> V_4 . V_36 > 0 )
F_94 ( & V_5 -> V_31 -> V_90 , V_5 -> V_34 , V_5 -> V_4 . V_25 . V_26 , 1 ) ;
}
static void F_164 ( struct V_5 * V_5 )
{
if ( V_5 -> V_4 . V_29 )
F_25 ( V_5 ) ;
F_94 ( & V_5 -> V_31 -> V_90 , V_5 -> V_34 , 0 , 0 ) ;
}
void F_165 ( void )
{
unsigned int V_133 ;
F_166 (i)
F_167 ( & F_168 ( V_109 , V_133 ) ,
V_134 , F_169 ( V_133 ) ) ;
}
static void F_170 ( struct V_5 * V_5 , struct V_1 * V_7 )
{
struct V_68 * V_65 = & V_7 -> V_4 . V_65 ;
F_171 ( & V_7 -> V_135 ) ;
if ( F_66 ( V_65 ) ) {
int V_121 = F_172 ( V_65 ) ;
if ( F_80 ( V_121 == - 1 ) ) {
F_16 ( & V_5 -> V_18 ) ;
F_131 ( V_65 ) ;
F_12 ( & V_5 -> V_18 ) ;
}
}
}
static void F_173 ( struct V_5 * V_5 , struct V_1 * V_7 )
{
F_170 ( V_5 , V_7 ) ;
F_174 ( V_7 ) ;
if ( ! F_70 ( V_7 ) || V_5 -> V_4 . V_36 )
return;
if ( F_46 ( V_5 ) )
F_73 ( V_5 ) ;
}
static void F_175 ( struct V_5 * V_5 , struct V_1 * V_7 )
{
int V_136 = 1 ;
if ( F_80 ( V_7 -> V_4 . V_51 ) )
return;
if ( F_70 ( V_7 ) && V_5 -> V_26 != V_7 ) {
#ifdef F_18
if ( V_7 -> V_37 > 1 && V_5 -> V_4 . V_29 &&
F_74 ( V_5 ) && V_5 != F_5 ( V_7 ) )
V_136 = 0 ;
#endif
if ( V_136 ) {
if ( F_44 ( V_5 -> V_26 ) )
F_72 ( V_5 , V_7 , 0 ) ;
else
F_73 ( V_5 ) ;
}
}
}
static void F_176 ( struct V_5 * V_5 , struct V_1 * V_7 ,
int V_137 )
{
if ( F_70 ( V_7 ) || V_5 -> V_26 == V_7 ) {
#ifdef F_18
if ( ! V_5 -> V_4 . V_29 )
F_46 ( V_5 ) ;
if ( F_51 ( V_5 -> V_4 . V_25 . V_26 , V_7 -> V_4 . V_52 ) &&
V_5 -> V_26 == V_7 )
F_73 ( V_5 ) ;
#else
F_73 ( V_5 ) ;
#endif
} else
F_175 ( V_5 , V_7 ) ;
}
void F_177 ( struct V_138 * V_139 , int V_34 )
{
F_178 ( V_139 , V_34 , & F_109 ( V_34 ) -> V_4 ) ;
}
