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
static inline void F_43 ( struct V_2 * V_3 ,
struct V_2 * V_47 )
{
struct V_6 * V_6 = F_4 ( V_3 ) ;
struct V_5 * V_5 = F_3 ( V_6 ) ;
F_44 ( ! V_3 -> V_48 || V_3 -> V_49 ) ;
V_3 -> V_50 = F_45 ( V_5 ) + V_47 -> V_51 ;
V_3 -> V_13 = V_47 -> V_16 ;
V_3 -> V_48 = 0 ;
}
static void F_46 ( struct V_2 * V_3 ,
struct V_2 * V_47 )
{
struct V_6 * V_6 = F_4 ( V_3 ) ;
struct V_5 * V_5 = F_3 ( V_6 ) ;
F_32 ( V_47 -> V_16 <= 0 ) ;
if ( V_3 -> V_51 == 0 ) {
V_3 -> V_50 = F_45 ( V_5 ) + V_47 -> V_51 ;
V_3 -> V_13 = V_47 -> V_16 ;
}
while ( V_3 -> V_13 <= 0 ) {
V_3 -> V_50 += V_47 -> V_15 ;
V_3 -> V_13 += V_47 -> V_16 ;
}
if ( F_47 ( V_3 -> V_50 , F_45 ( V_5 ) ) ) {
static bool V_52 = false ;
if ( ! V_52 ) {
V_52 = true ;
F_48 ( L_1 ) ;
}
V_3 -> V_50 = F_45 ( V_5 ) + V_47 -> V_51 ;
V_3 -> V_13 = V_47 -> V_16 ;
}
}
static bool F_49 ( struct V_2 * V_3 ,
struct V_2 * V_47 , T_1 V_53 )
{
T_1 V_54 , V_55 ;
V_54 = ( V_47 -> V_15 >> V_56 ) * ( V_3 -> V_13 >> V_56 ) ;
V_55 = ( ( V_3 -> V_50 - V_53 ) >> V_56 ) *
( V_47 -> V_16 >> V_56 ) ;
return F_47 ( V_55 , V_54 ) ;
}
static void F_50 ( struct V_2 * V_3 ,
struct V_2 * V_47 )
{
struct V_6 * V_6 = F_4 ( V_3 ) ;
struct V_5 * V_5 = F_3 ( V_6 ) ;
if ( V_3 -> V_48 ) {
F_43 ( V_3 , V_47 ) ;
return;
}
if ( F_47 ( V_3 -> V_50 , F_45 ( V_5 ) ) ||
F_49 ( V_3 , V_47 , F_45 ( V_5 ) ) ) {
V_3 -> V_50 = F_45 ( V_5 ) + V_47 -> V_51 ;
V_3 -> V_13 = V_47 -> V_16 ;
}
}
static int F_51 ( struct V_2 * V_3 , bool V_57 )
{
struct V_6 * V_6 = F_4 ( V_3 ) ;
struct V_5 * V_5 = F_3 ( V_6 ) ;
T_2 V_58 , V_59 ;
T_2 V_60 , V_61 ;
unsigned long V_62 ;
T_3 V_63 ;
if ( V_57 )
return 0 ;
V_59 = F_52 ( V_3 -> V_50 ) ;
V_58 = F_53 ( & V_3 -> V_64 ) ;
V_63 = F_54 ( V_58 ) - F_45 ( V_5 ) ;
V_59 = F_55 ( V_59 , V_63 ) ;
if ( F_56 ( V_59 , V_58 ) < 0 )
return 0 ;
F_57 ( & V_3 -> V_64 , V_59 ) ;
V_60 = F_58 ( & V_3 -> V_64 ) ;
V_61 = F_59 ( & V_3 -> V_64 ) ;
V_62 = F_54 ( F_60 ( V_61 , V_60 ) ) ;
F_61 ( & V_3 -> V_64 , V_60 ,
V_62 , V_65 , 0 ) ;
return F_62 ( & V_3 -> V_64 ) ;
}
static enum V_66 F_63 ( struct V_67 * V_68 )
{
struct V_2 * V_3 = F_2 ( V_68 ,
struct V_2 ,
V_64 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_5 * V_5 = F_5 ( V_7 ) ;
F_12 ( & V_5 -> V_18 ) ;
if ( ! F_64 ( V_7 ) || V_3 -> V_48 )
goto V_69;
F_65 () ;
F_66 ( V_5 ) ;
V_3 -> V_49 = 0 ;
if ( V_7 -> V_70 ) {
F_67 ( V_5 , V_7 , V_71 ) ;
if ( F_68 ( V_5 -> V_26 ) )
F_69 ( V_5 , V_7 , 0 ) ;
else
F_70 ( V_5 -> V_26 ) ;
#ifdef F_18
if ( F_41 ( V_5 ) )
F_71 ( V_5 ) ;
#endif
}
V_69:
F_16 ( & V_5 -> V_18 ) ;
return V_72 ;
}
void F_72 ( struct V_2 * V_3 )
{
struct V_67 * V_68 = & V_3 -> V_64 ;
if ( F_62 ( V_68 ) ) {
F_73 ( V_68 ) ;
return;
}
F_74 ( V_68 , V_73 , V_74 ) ;
V_68 -> V_75 = F_63 ;
}
static
int F_75 ( struct V_5 * V_5 , struct V_2 * V_3 )
{
int V_76 = F_47 ( V_3 -> V_50 , F_45 ( V_5 ) ) ;
int V_77 = V_3 -> V_13 <= 0 ;
if ( ! V_77 && ! V_76 )
return 0 ;
if ( V_76 ) {
V_3 -> V_13 = V_77 ? V_3 -> V_13 : 0 ;
V_3 -> V_13 -= F_45 ( V_5 ) - V_3 -> V_50 ;
}
return 1 ;
}
static void F_76 ( struct V_5 * V_5 )
{
struct V_1 * V_26 = V_5 -> V_26 ;
struct V_2 * V_3 = & V_26 -> V_4 ;
T_1 V_78 ;
if ( ! F_64 ( V_26 ) || ! F_6 ( V_3 ) )
return;
V_78 = F_77 ( V_5 ) - V_26 -> V_79 . V_80 ;
if ( F_78 ( ( T_3 ) V_78 < 0 ) )
V_78 = 0 ;
F_79 ( V_26 -> V_79 . V_81 . V_82 ,
F_80 ( V_26 -> V_79 . V_81 . V_82 , V_78 ) ) ;
V_26 -> V_79 . V_83 += V_78 ;
F_81 ( V_26 , V_78 ) ;
V_26 -> V_79 . V_80 = F_77 ( V_5 ) ;
F_82 ( V_26 , V_78 ) ;
F_83 ( V_5 , V_78 ) ;
V_3 -> V_13 -= V_78 ;
if ( F_75 ( V_5 , V_3 ) ) {
F_84 ( V_5 , V_26 , 0 ) ;
if ( F_85 ( F_51 ( V_3 , V_26 -> V_4 . V_84 ) ) )
V_3 -> V_49 = 1 ;
else
F_67 ( V_5 , V_26 , V_71 ) ;
if ( ! F_8 ( V_26 , & V_5 -> V_4 ) )
F_70 ( V_26 ) ;
}
if ( F_86 () ) {
struct V_85 * V_85 = & V_5 -> V_86 ;
F_12 ( & V_85 -> V_87 ) ;
if ( F_87 ( V_85 ) )
V_85 -> V_88 += V_78 ;
F_16 ( & V_85 -> V_87 ) ;
}
}
static inline T_1 F_88 ( struct V_5 * V_5 )
{
struct V_1 * V_27 = F_89 ( V_5 , V_5 -> V_34 ) ;
if ( V_27 && F_90 ( V_27 -> V_89 ) )
return V_27 -> V_4 . V_50 ;
else
return 0 ;
}
static void F_91 ( struct V_6 * V_6 , T_1 V_50 )
{
struct V_5 * V_5 = F_3 ( V_6 ) ;
if ( V_6 -> V_25 . V_26 == 0 ||
F_47 ( V_50 , V_6 -> V_25 . V_26 ) ) {
V_6 -> V_25 . V_27 = V_6 -> V_25 . V_26 ;
V_6 -> V_25 . V_26 = V_50 ;
F_92 ( & V_5 -> V_31 -> V_90 , V_5 -> V_34 , V_50 , 1 ) ;
} else if ( V_6 -> V_25 . V_27 == 0 ||
F_47 ( V_50 , V_6 -> V_25 . V_27 ) ) {
V_6 -> V_25 . V_27 = F_88 ( V_5 ) ;
}
}
static void F_93 ( struct V_6 * V_6 , T_1 V_50 )
{
struct V_5 * V_5 = F_3 ( V_6 ) ;
if ( ! V_6 -> V_36 ) {
V_6 -> V_25 . V_26 = 0 ;
V_6 -> V_25 . V_27 = 0 ;
F_92 ( & V_5 -> V_31 -> V_90 , V_5 -> V_34 , 0 , 0 ) ;
} else {
struct V_8 * V_41 = V_6 -> V_9 ;
struct V_2 * V_40 ;
V_40 = F_33 ( V_41 , struct V_2 , V_8 ) ;
V_6 -> V_25 . V_26 = V_40 -> V_50 ;
V_6 -> V_25 . V_27 = F_88 ( V_5 ) ;
F_92 ( & V_5 -> V_31 -> V_90 , V_5 -> V_34 , V_40 -> V_50 , 1 ) ;
}
}
static inline void F_91 ( struct V_6 * V_6 , T_1 V_50 ) {}
static inline void F_93 ( struct V_6 * V_6 , T_1 V_50 ) {}
static inline
void F_94 ( struct V_2 * V_3 , struct V_6 * V_6 )
{
int V_89 = F_1 ( V_3 ) -> V_89 ;
T_1 V_50 = V_3 -> V_50 ;
F_44 ( ! F_90 ( V_89 ) ) ;
V_6 -> V_36 ++ ;
F_95 ( F_3 ( V_6 ) ) ;
F_91 ( V_6 , V_50 ) ;
F_29 ( V_3 , V_6 ) ;
}
static inline
void F_96 ( struct V_2 * V_3 , struct V_6 * V_6 )
{
int V_89 = F_1 ( V_3 ) -> V_89 ;
F_44 ( ! F_90 ( V_89 ) ) ;
F_44 ( ! V_6 -> V_36 ) ;
V_6 -> V_36 -- ;
F_97 ( F_3 ( V_6 ) ) ;
F_93 ( V_6 , V_3 -> V_50 ) ;
F_30 ( V_3 , V_6 ) ;
}
static void F_98 ( struct V_2 * V_3 )
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
if ( F_47 ( V_3 -> V_50 , V_40 -> V_50 ) )
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
F_94 ( V_3 , V_6 ) ;
}
static void F_99 ( struct V_2 * V_3 )
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
F_96 ( V_3 , V_6 ) ;
}
static void
F_100 ( struct V_2 * V_3 ,
struct V_2 * V_47 , int V_91 )
{
F_32 ( F_6 ( V_3 ) ) ;
if ( ! V_3 -> V_48 && V_91 & V_71 )
F_46 ( V_3 , V_47 ) ;
else
F_50 ( V_3 , V_47 ) ;
F_98 ( V_3 ) ;
}
static void F_101 ( struct V_2 * V_3 )
{
F_99 ( V_3 ) ;
}
static void F_67 ( struct V_5 * V_5 , struct V_1 * V_7 , int V_91 )
{
struct V_1 * V_92 = F_102 ( V_7 ) ;
struct V_2 * V_47 = & V_7 -> V_4 ;
if ( V_92 && V_7 -> V_4 . V_84 && F_90 ( V_92 -> V_93 ) )
V_47 = & V_92 -> V_4 ;
if ( V_7 -> V_4 . V_49 )
return;
F_100 ( & V_7 -> V_4 , V_47 , V_91 ) ;
if ( ! F_103 ( V_5 , V_7 ) && V_7 -> V_37 > 1 )
F_31 ( V_5 , V_7 ) ;
}
static void F_84 ( struct V_5 * V_5 , struct V_1 * V_7 , int V_91 )
{
F_101 ( & V_7 -> V_4 ) ;
F_37 ( V_5 , V_7 ) ;
}
static void F_104 ( struct V_5 * V_5 , struct V_1 * V_7 , int V_91 )
{
F_76 ( V_5 ) ;
F_84 ( V_5 , V_7 , V_91 ) ;
}
static void F_105 ( struct V_5 * V_5 )
{
struct V_1 * V_7 = V_5 -> V_26 ;
if ( V_7 -> V_4 . V_13 > 0 ) {
V_5 -> V_26 -> V_4 . V_48 = 1 ;
V_7 -> V_4 . V_13 = 0 ;
}
F_76 ( V_5 ) ;
}
static int
F_106 ( struct V_1 * V_7 , int V_34 , int V_94 , int V_91 )
{
struct V_1 * V_26 ;
struct V_5 * V_5 ;
if ( V_94 != V_95 && V_94 != V_96 )
goto V_97;
V_5 = F_107 ( V_34 ) ;
F_108 () ;
V_26 = F_109 ( V_5 -> V_26 ) ;
if ( F_78 ( F_64 ( V_26 ) ) &&
( V_26 -> V_37 < 2 ||
! F_34 ( & V_7 -> V_4 , & V_26 -> V_4 ) ) &&
( V_7 -> V_37 > 1 ) ) {
int V_98 = F_110 ( V_7 ) ;
if ( V_98 != - 1 )
V_34 = V_98 ;
}
F_111 () ;
V_97:
return V_34 ;
}
static void F_112 ( struct V_5 * V_5 , struct V_1 * V_7 )
{
if ( V_5 -> V_26 -> V_37 == 1 ||
F_113 ( & V_5 -> V_31 -> V_90 , V_5 -> V_26 , NULL ) == - 1 )
return;
if ( V_7 -> V_37 != 1 &&
F_113 ( & V_5 -> V_31 -> V_90 , V_7 , NULL ) != - 1 )
return;
F_70 ( V_5 -> V_26 ) ;
}
static void F_69 ( struct V_5 * V_5 , struct V_1 * V_7 ,
int V_91 )
{
if ( F_34 ( & V_7 -> V_4 , & V_5 -> V_26 -> V_4 ) ) {
F_70 ( V_5 -> V_26 ) ;
return;
}
#ifdef F_18
if ( ( V_7 -> V_4 . V_50 == V_5 -> V_26 -> V_4 . V_50 ) &&
! F_114 ( V_5 -> V_26 ) )
F_112 ( V_5 , V_7 ) ;
#endif
}
static void F_115 ( struct V_5 * V_5 , struct V_1 * V_7 )
{
T_3 V_63 = V_7 -> V_4 . V_16 - V_7 -> V_4 . V_13 ;
if ( V_63 > 10000 )
F_116 ( V_5 , V_7 -> V_4 . V_13 ) ;
}
static struct V_2 * F_117 ( struct V_5 * V_5 ,
struct V_6 * V_6 )
{
struct V_8 * V_54 = V_6 -> V_9 ;
if ( ! V_54 )
return NULL ;
return F_33 ( V_54 , struct V_2 , V_8 ) ;
}
struct V_1 * F_118 ( struct V_5 * V_5 )
{
struct V_2 * V_3 ;
struct V_1 * V_7 ;
struct V_6 * V_6 ;
V_6 = & V_5 -> V_4 ;
if ( F_78 ( ! V_6 -> V_36 ) )
return NULL ;
V_3 = F_117 ( V_5 , V_6 ) ;
F_32 ( ! V_3 ) ;
V_7 = F_1 ( V_3 ) ;
V_7 -> V_79 . V_80 = F_77 ( V_5 ) ;
F_37 ( V_5 , V_7 ) ;
#ifdef F_119
if ( F_120 ( V_5 ) )
F_115 ( V_5 , V_7 ) ;
#endif
#ifdef F_18
V_5 -> V_99 = F_41 ( V_5 ) ;
#endif
return V_7 ;
}
static void F_121 ( struct V_5 * V_5 , struct V_1 * V_7 )
{
F_76 ( V_5 ) ;
if ( F_6 ( & V_7 -> V_4 ) && V_7 -> V_37 > 1 )
F_31 ( V_5 , V_7 ) ;
}
static void F_122 ( struct V_5 * V_5 , struct V_1 * V_7 , int V_100 )
{
F_76 ( V_5 ) ;
#ifdef F_119
if ( F_120 ( V_5 ) && V_100 && V_7 -> V_4 . V_13 > 0 )
F_115 ( V_5 , V_7 ) ;
#endif
}
static void F_123 ( struct V_1 * V_7 )
{
}
static void F_124 ( struct V_1 * V_7 )
{
struct V_67 * V_68 = & V_7 -> V_4 . V_64 ;
struct V_17 * V_11 = F_125 ( F_126 ( V_7 ) ) ;
F_127 ( & V_11 -> V_18 ) ;
V_11 -> V_22 -= V_7 -> V_4 . V_17 ;
F_128 ( & V_11 -> V_18 ) ;
F_129 ( V_68 ) ;
}
static void F_130 ( struct V_5 * V_5 )
{
struct V_1 * V_7 = V_5 -> V_26 ;
V_7 -> V_79 . V_80 = F_77 ( V_5 ) ;
F_37 ( V_5 , V_7 ) ;
}
static int F_131 ( struct V_5 * V_5 , struct V_1 * V_7 , int V_34 )
{
if ( ! F_132 ( V_5 , V_7 ) &&
( V_34 < 0 || F_133 ( V_34 , & V_7 -> V_101 ) ) &&
( V_7 -> V_37 > 1 ) )
return 1 ;
return 0 ;
}
static struct V_1 * F_89 ( struct V_5 * V_5 , int V_34 )
{
struct V_8 * V_46 = V_5 -> V_4 . V_9 ;
struct V_2 * V_3 ;
struct V_1 * V_7 = NULL ;
V_46:
V_46 = F_38 ( V_46 ) ;
if ( V_46 ) {
V_3 = F_33 ( V_46 , struct V_2 , V_8 ) ;
V_7 = F_1 ( V_3 ) ;
if ( F_131 ( V_5 , V_7 , V_34 ) )
return V_7 ;
goto V_46;
}
return NULL ;
}
static int F_110 ( struct V_1 * V_102 )
{
struct V_103 * V_104 ;
struct V_105 * V_106 = F_134 ( V_107 ) ;
int V_108 = F_135 () ;
int V_109 , V_34 = F_126 ( V_102 ) ;
if ( F_78 ( ! V_106 ) )
return - 1 ;
if ( V_102 -> V_37 == 1 )
return - 1 ;
V_109 = F_113 ( & F_5 ( V_102 ) -> V_31 -> V_90 ,
V_102 , V_106 ) ;
if ( V_109 == - 1 )
return - 1 ;
if ( F_133 ( V_34 , V_106 ) )
return V_34 ;
if ( ! F_133 ( V_108 , V_106 ) )
V_108 = - 1 ;
F_108 () ;
F_136 (cpu, sd) {
if ( V_104 -> V_91 & V_110 ) {
if ( V_108 != - 1 &&
F_133 ( V_108 , F_137 ( V_104 ) ) ) {
F_111 () ;
return V_108 ;
}
if ( V_109 < V_111 &&
F_133 ( V_109 , F_137 ( V_104 ) ) ) {
F_111 () ;
return V_109 ;
}
}
}
F_111 () ;
if ( V_108 != - 1 )
return V_108 ;
V_34 = F_138 ( V_106 ) ;
if ( V_34 < V_111 )
return V_34 ;
return - 1 ;
}
static struct V_5 * F_139 ( struct V_1 * V_102 , struct V_5 * V_5 )
{
struct V_5 * V_112 = NULL ;
int V_113 ;
int V_34 ;
for ( V_113 = 0 ; V_113 < V_114 ; V_113 ++ ) {
V_34 = F_110 ( V_102 ) ;
if ( ( V_34 == - 1 ) || ( V_34 == V_5 -> V_34 ) )
break;
V_112 = F_107 ( V_34 ) ;
if ( F_140 ( V_5 , V_112 ) ) {
if ( F_78 ( F_5 ( V_102 ) != V_5 ||
! F_133 ( V_112 -> V_34 ,
& V_102 -> V_101 ) ||
F_132 ( V_5 , V_102 ) || ! V_102 -> V_70 ) ) {
F_141 ( V_5 , V_112 ) ;
V_112 = NULL ;
break;
}
}
if ( ! V_112 -> V_4 . V_36 ||
F_47 ( V_102 -> V_4 . V_50 ,
V_112 -> V_4 . V_25 . V_26 ) )
break;
F_141 ( V_5 , V_112 ) ;
V_112 = NULL ;
}
return V_112 ;
}
static struct V_1 * F_142 ( struct V_5 * V_5 )
{
struct V_1 * V_7 ;
if ( ! F_41 ( V_5 ) )
return NULL ;
V_7 = F_33 ( V_5 -> V_4 . V_45 ,
struct V_1 , V_42 ) ;
F_32 ( V_5 -> V_34 != F_126 ( V_7 ) ) ;
F_32 ( F_103 ( V_5 , V_7 ) ) ;
F_32 ( V_7 -> V_37 <= 1 ) ;
F_32 ( ! V_7 -> V_70 ) ;
F_32 ( ! F_64 ( V_7 ) ) ;
return V_7 ;
}
static int F_71 ( struct V_5 * V_5 )
{
struct V_1 * V_115 ;
struct V_5 * V_112 ;
if ( ! V_5 -> V_4 . V_29 )
return 0 ;
V_115 = F_142 ( V_5 ) ;
if ( ! V_115 )
return 0 ;
V_116:
if ( F_78 ( V_115 == V_5 -> V_26 ) ) {
F_44 ( 1 ) ;
return 0 ;
}
if ( F_64 ( V_5 -> V_26 ) &&
F_47 ( V_115 -> V_4 . V_50 , V_5 -> V_26 -> V_4 . V_50 ) &&
V_5 -> V_26 -> V_37 > 1 ) {
F_70 ( V_5 -> V_26 ) ;
return 0 ;
}
F_143 ( V_115 ) ;
V_112 = F_139 ( V_115 , V_5 ) ;
if ( ! V_112 ) {
struct V_1 * V_102 ;
V_102 = F_142 ( V_5 ) ;
if ( F_126 ( V_115 ) == V_5 -> V_34 && V_102 == V_115 ) {
F_37 ( V_5 , V_115 ) ;
goto V_97;
}
if ( ! V_102 )
goto V_97;
F_144 ( V_115 ) ;
V_115 = V_102 ;
goto V_116;
}
F_145 ( V_5 , V_115 , 0 ) ;
F_146 ( V_115 , V_112 -> V_34 ) ;
F_147 ( V_112 , V_115 , 0 ) ;
F_70 ( V_112 -> V_26 ) ;
F_141 ( V_5 , V_112 ) ;
V_97:
F_144 ( V_115 ) ;
return 1 ;
}
static void F_148 ( struct V_5 * V_5 )
{
while ( F_71 ( V_5 ) )
;
}
static int F_149 ( struct V_5 * V_117 )
{
int V_108 = V_117 -> V_34 , V_118 = 0 , V_34 ;
struct V_1 * V_7 ;
struct V_5 * V_119 ;
T_1 V_120 = V_121 ;
if ( F_85 ( ! F_19 ( V_117 ) ) )
return 0 ;
F_150 () ;
F_151 (cpu, this_rq->rd->dlo_mask) {
if ( V_108 == V_34 )
continue;
V_119 = F_107 ( V_34 ) ;
if ( V_117 -> V_4 . V_36 &&
F_47 ( V_117 -> V_4 . V_25 . V_26 ,
V_119 -> V_4 . V_25 . V_27 ) )
continue;
F_140 ( V_117 , V_119 ) ;
if ( V_119 -> V_4 . V_36 <= 1 )
goto V_122;
V_7 = F_89 ( V_119 , V_108 ) ;
if ( V_7 && F_47 ( V_7 -> V_4 . V_50 , V_120 ) &&
( ! V_117 -> V_4 . V_36 ||
F_47 ( V_7 -> V_4 . V_50 ,
V_117 -> V_4 . V_25 . V_26 ) ) ) {
F_44 ( V_7 == V_119 -> V_26 ) ;
F_44 ( ! V_7 -> V_70 ) ;
if ( F_47 ( V_7 -> V_4 . V_50 ,
V_119 -> V_26 -> V_4 . V_50 ) )
goto V_122;
V_118 = 1 ;
F_145 ( V_119 , V_7 , 0 ) ;
F_146 ( V_7 , V_108 ) ;
F_147 ( V_117 , V_7 , 0 ) ;
V_120 = V_7 -> V_4 . V_50 ;
}
V_122:
F_141 ( V_117 , V_119 ) ;
}
return V_118 ;
}
static void F_152 ( struct V_5 * V_5 , struct V_1 * V_123 )
{
if ( F_64 ( V_123 ) )
F_149 ( V_5 ) ;
}
static void F_153 ( struct V_5 * V_5 )
{
F_148 ( V_5 ) ;
}
static void F_154 ( struct V_5 * V_5 , struct V_1 * V_7 )
{
if ( ! F_132 ( V_5 , V_7 ) &&
! F_114 ( V_5 -> V_26 ) &&
F_41 ( V_5 ) &&
V_7 -> V_37 > 1 &&
F_64 ( V_5 -> V_26 ) &&
( V_5 -> V_26 -> V_37 < 2 ||
F_34 ( & V_5 -> V_26 -> V_4 , & V_7 -> V_4 ) ) ) {
F_148 ( V_5 ) ;
}
}
static void F_155 ( struct V_1 * V_7 ,
const struct V_105 * V_124 )
{
struct V_5 * V_5 ;
int V_125 ;
F_32 ( ! F_64 ( V_7 ) ) ;
if ( ! F_6 ( & V_7 -> V_4 ) )
return;
V_125 = F_156 ( V_124 ) ;
if ( ( V_7 -> V_37 > 1 ) == ( V_125 > 1 ) )
return;
V_5 = F_5 ( V_7 ) ;
if ( V_125 <= 1 ) {
if ( ! F_103 ( V_5 , V_7 ) )
F_37 ( V_5 , V_7 ) ;
F_32 ( ! V_5 -> V_4 . V_28 ) ;
V_5 -> V_4 . V_28 -- ;
} else {
if ( ! F_103 ( V_5 , V_7 ) )
F_31 ( V_5 , V_7 ) ;
V_5 -> V_4 . V_28 ++ ;
}
F_28 ( & V_5 -> V_4 ) ;
}
static void F_157 ( struct V_5 * V_5 )
{
if ( V_5 -> V_4 . V_29 )
F_21 ( V_5 ) ;
if ( V_5 -> V_4 . V_36 > 0 )
F_92 ( & V_5 -> V_31 -> V_90 , V_5 -> V_34 , V_5 -> V_4 . V_25 . V_26 , 1 ) ;
}
static void F_158 ( struct V_5 * V_5 )
{
if ( V_5 -> V_4 . V_29 )
F_25 ( V_5 ) ;
F_92 ( & V_5 -> V_31 -> V_90 , V_5 -> V_34 , 0 , 0 ) ;
}
void F_159 ( void )
{
unsigned int V_126 ;
F_160 (i)
F_161 ( & F_162 ( V_107 , V_126 ) ,
V_127 , F_163 ( V_126 ) ) ;
}
static void F_164 ( struct V_5 * V_5 , struct V_1 * V_7 )
{
if ( F_62 ( & V_7 -> V_4 . V_64 ) && ! F_165 ( V_7 -> V_128 ) )
F_73 ( & V_7 -> V_4 . V_64 ) ;
#ifdef F_18
if ( ! V_5 -> V_4 . V_36 )
F_149 ( V_5 ) ;
#endif
}
static void F_166 ( struct V_5 * V_5 , struct V_1 * V_7 )
{
int V_129 = 1 ;
if ( F_78 ( V_7 -> V_4 . V_49 ) )
return;
if ( V_7 -> V_70 || V_5 -> V_26 != V_7 ) {
#ifdef F_18
if ( V_5 -> V_4 . V_29 && F_71 ( V_5 ) && V_5 != F_5 ( V_7 ) )
V_129 = 0 ;
#endif
if ( V_129 && F_68 ( V_5 -> V_26 ) )
F_69 ( V_5 , V_7 , 0 ) ;
}
}
static void F_167 ( struct V_5 * V_5 , struct V_1 * V_7 ,
int V_130 )
{
if ( V_7 -> V_70 || V_5 -> V_26 == V_7 ) {
#ifdef F_18
if ( ! V_5 -> V_4 . V_29 )
F_149 ( V_5 ) ;
if ( F_47 ( V_5 -> V_4 . V_25 . V_26 , V_7 -> V_4 . V_50 ) &&
V_5 -> V_26 == V_7 )
F_70 ( V_7 ) ;
#else
F_70 ( V_7 ) ;
#endif
} else
F_166 ( V_5 , V_7 ) ;
}
