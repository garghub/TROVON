static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
#ifdef F_2
F_3 ( ! F_4 ( V_3 ) ) ;
#endif
return F_5 ( V_3 , struct V_1 , V_4 ) ;
}
static inline struct V_5 * F_6 ( struct V_6 * V_6 )
{
return V_6 -> V_5 ;
}
static inline struct V_6 * F_7 ( struct V_2 * V_3 )
{
return V_3 -> V_6 ;
}
static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_5 ( V_3 , struct V_1 , V_4 ) ;
}
static inline struct V_5 * F_6 ( struct V_6 * V_6 )
{
return F_5 ( V_6 , struct V_5 , V_4 ) ;
}
static inline struct V_6 * F_7 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_5 * V_5 = F_8 ( V_7 ) ;
return & V_5 -> V_4 ;
}
static inline int F_9 ( struct V_5 * V_5 )
{
return F_10 ( & V_5 -> V_8 -> V_9 ) ;
}
static inline void F_11 ( struct V_5 * V_5 )
{
if ( ! V_5 -> V_10 )
return;
F_12 ( V_5 -> V_11 , V_5 -> V_8 -> V_12 ) ;
F_13 () ;
F_14 ( & V_5 -> V_8 -> V_9 ) ;
}
static inline void F_15 ( struct V_5 * V_5 )
{
if ( ! V_5 -> V_10 )
return;
F_16 ( & V_5 -> V_8 -> V_9 ) ;
F_17 ( V_5 -> V_11 , V_5 -> V_8 -> V_12 ) ;
}
static void F_18 ( struct V_6 * V_6 )
{
if ( V_6 -> V_13 && V_6 -> V_14 > 1 ) {
if ( ! V_6 -> V_15 ) {
F_11 ( F_6 ( V_6 ) ) ;
V_6 -> V_15 = 1 ;
}
} else if ( V_6 -> V_15 ) {
F_15 ( F_6 ( V_6 ) ) ;
V_6 -> V_15 = 0 ;
}
}
static void F_19 ( struct V_2 * V_3 , struct V_6 * V_6 )
{
if ( ! F_4 ( V_3 ) )
return;
V_6 = & F_6 ( V_6 ) -> V_4 ;
V_6 -> V_14 ++ ;
if ( V_3 -> V_16 > 1 )
V_6 -> V_13 ++ ;
F_18 ( V_6 ) ;
}
static void F_20 ( struct V_2 * V_3 , struct V_6 * V_6 )
{
if ( ! F_4 ( V_3 ) )
return;
V_6 = & F_6 ( V_6 ) -> V_4 ;
V_6 -> V_14 -- ;
if ( V_3 -> V_16 > 1 )
V_6 -> V_13 -- ;
F_18 ( V_6 ) ;
}
static void F_21 ( struct V_5 * V_5 , struct V_1 * V_7 )
{
F_22 ( & V_7 -> V_17 , & V_5 -> V_4 . V_17 ) ;
F_23 ( & V_7 -> V_17 , V_7 -> V_18 ) ;
F_24 ( & V_7 -> V_17 , & V_5 -> V_4 . V_17 ) ;
}
static void F_25 ( struct V_5 * V_5 , struct V_1 * V_7 )
{
F_22 ( & V_7 -> V_17 , & V_5 -> V_4 . V_17 ) ;
}
static inline int F_26 ( struct V_5 * V_5 )
{
return ! F_27 ( & V_5 -> V_4 . V_17 ) ;
}
static inline void F_21 ( struct V_5 * V_5 , struct V_1 * V_7 )
{
}
static inline void F_25 ( struct V_5 * V_5 , struct V_1 * V_7 )
{
}
static inline
void F_19 ( struct V_2 * V_3 , struct V_6 * V_6 )
{
}
static inline
void F_20 ( struct V_2 * V_3 , struct V_6 * V_6 )
{
}
static inline int F_28 ( struct V_2 * V_3 )
{
return ! F_29 ( & V_3 -> V_19 ) ;
}
static inline T_1 F_30 ( struct V_6 * V_6 )
{
if ( ! V_6 -> V_20 )
return V_21 ;
return V_6 -> V_22 ;
}
static inline T_1 F_31 ( struct V_6 * V_6 )
{
return F_32 ( V_6 -> V_20 -> V_23 . V_24 ) ;
}
static inline void F_33 ( struct V_6 * V_6 )
{
F_34 ( & V_6 -> V_25 ,
& F_6 ( V_6 ) -> V_25 ) ;
}
static inline void F_35 ( struct V_6 * V_6 )
{
F_36 ( & V_6 -> V_25 ) ;
}
static inline struct V_6 * F_37 ( struct V_2 * V_3 )
{
return V_3 -> V_26 ;
}
static void F_38 ( struct V_6 * V_6 )
{
struct V_1 * V_27 = F_6 ( V_6 ) -> V_27 ;
struct V_2 * V_3 ;
int V_11 = F_39 ( F_6 ( V_6 ) ) ;
V_3 = V_6 -> V_20 -> V_3 [ V_11 ] ;
if ( V_6 -> V_28 ) {
if ( V_3 && ! F_28 ( V_3 ) )
F_40 ( V_3 , false ) ;
if ( V_6 -> V_29 . V_27 < V_27 -> V_18 )
F_41 ( V_27 ) ;
}
}
static void F_42 ( struct V_6 * V_6 )
{
struct V_2 * V_3 ;
int V_11 = F_39 ( F_6 ( V_6 ) ) ;
V_3 = V_6 -> V_20 -> V_3 [ V_11 ] ;
if ( V_3 && F_28 ( V_3 ) )
F_43 ( V_3 ) ;
}
static inline int F_44 ( struct V_6 * V_6 )
{
return V_6 -> V_30 && ! V_6 -> V_31 ;
}
static int F_45 ( struct V_2 * V_3 )
{
struct V_6 * V_6 = F_37 ( V_3 ) ;
struct V_1 * V_7 ;
if ( V_6 )
return ! ! V_6 -> V_31 ;
V_7 = F_1 ( V_3 ) ;
return V_7 -> V_18 != V_7 -> V_32 ;
}
static inline const struct V_33 * F_46 ( void )
{
return F_47 ( F_48 () ) -> V_8 -> V_34 ;
}
static inline const struct V_33 * F_46 ( void )
{
return V_35 ;
}
static inline
struct V_6 * F_49 ( struct V_23 * V_36 , int V_11 )
{
return F_5 ( V_36 , struct V_37 , V_23 ) -> V_6 [ V_11 ] ;
}
static inline struct V_23 * F_50 ( struct V_6 * V_6 )
{
return & V_6 -> V_20 -> V_23 ;
}
static inline T_1 F_30 ( struct V_6 * V_6 )
{
return V_6 -> V_22 ;
}
static inline T_1 F_31 ( struct V_6 * V_6 )
{
return F_32 ( V_38 . V_24 ) ;
}
static inline void F_33 ( struct V_6 * V_6 )
{
}
static inline void F_35 ( struct V_6 * V_6 )
{
}
static inline struct V_6 * F_37 ( struct V_2 * V_3 )
{
return NULL ;
}
static inline void F_38 ( struct V_6 * V_6 )
{
if ( V_6 -> V_28 )
F_41 ( F_6 ( V_6 ) -> V_27 ) ;
}
static inline void F_42 ( struct V_6 * V_6 )
{
}
static inline int F_44 ( struct V_6 * V_6 )
{
return V_6 -> V_30 ;
}
static inline const struct V_33 * F_46 ( void )
{
return V_35 ;
}
static inline
struct V_6 * F_49 ( struct V_23 * V_36 , int V_11 )
{
return & F_47 ( V_11 ) -> V_4 ;
}
static inline struct V_23 * F_50 ( struct V_6 * V_6 )
{
return & V_38 ;
}
static int F_51 ( struct V_6 * V_6 )
{
struct V_23 * V_36 = F_50 ( V_6 ) ;
struct V_39 * V_8 = F_47 ( F_48 () ) -> V_8 ;
int V_40 , V_41 , V_42 = 0 ;
T_1 V_24 ;
V_41 = F_52 ( V_8 -> V_34 ) ;
F_53 ( & V_36 -> V_43 ) ;
V_24 = F_32 ( V_36 -> V_24 ) ;
F_54 (i, rd->span) {
struct V_6 * V_44 = F_49 ( V_36 , V_40 ) ;
T_2 V_45 ;
if ( V_44 == V_6 )
continue;
F_53 ( & V_44 -> V_43 ) ;
if ( V_44 -> V_22 == V_21 )
goto V_46;
V_45 = V_44 -> V_22 - V_44 -> V_47 ;
if ( V_45 > 0 ) {
V_45 = F_55 ( ( T_1 ) V_45 , V_41 ) ;
if ( V_6 -> V_22 + V_45 > V_24 )
V_45 = V_24 - V_6 -> V_22 ;
V_44 -> V_22 -= V_45 ;
V_6 -> V_22 += V_45 ;
V_42 = 1 ;
if ( V_6 -> V_22 == V_24 ) {
F_56 ( & V_44 -> V_43 ) ;
break;
}
}
V_46:
F_56 ( & V_44 -> V_43 ) ;
}
F_56 ( & V_36 -> V_43 ) ;
return V_42 ;
}
static void F_57 ( struct V_5 * V_5 )
{
struct V_39 * V_8 = V_5 -> V_8 ;
T_3 V_44 ;
struct V_6 * V_6 ;
if ( F_58 ( ! V_48 ) )
return;
F_59 (rt_rq, iter, rq) {
struct V_23 * V_36 = F_50 ( V_6 ) ;
T_2 V_49 ;
int V_40 ;
F_53 ( & V_36 -> V_43 ) ;
F_53 ( & V_6 -> V_43 ) ;
if ( V_6 -> V_22 == V_21 ||
V_6 -> V_22 == V_36 -> V_22 )
goto V_50;
F_56 ( & V_6 -> V_43 ) ;
V_49 = V_36 -> V_22 - V_6 -> V_22 ;
F_54 (i, rd->span) {
struct V_6 * V_44 = F_49 ( V_36 , V_40 ) ;
T_2 V_45 ;
if ( V_44 == V_6 || V_44 -> V_22 == V_21 )
continue;
F_53 ( & V_44 -> V_43 ) ;
if ( V_49 > 0 ) {
V_45 = F_60 ( T_2 , V_44 -> V_22 , V_49 ) ;
V_44 -> V_22 -= V_45 ;
V_49 -= V_45 ;
} else {
V_44 -> V_22 -= V_49 ;
V_49 -= V_49 ;
}
F_56 ( & V_44 -> V_43 ) ;
if ( ! V_49 )
break;
}
F_53 ( & V_6 -> V_43 ) ;
F_61 ( V_49 ) ;
V_50:
V_6 -> V_22 = V_21 ;
F_56 ( & V_6 -> V_43 ) ;
F_56 ( & V_36 -> V_43 ) ;
}
}
static void F_62 ( struct V_5 * V_5 )
{
unsigned long V_51 ;
F_63 ( & V_5 -> V_52 , V_51 ) ;
F_57 ( V_5 ) ;
F_64 ( & V_5 -> V_52 , V_51 ) ;
}
static void F_65 ( struct V_5 * V_5 )
{
T_3 V_44 ;
struct V_6 * V_6 ;
if ( F_58 ( ! V_48 ) )
return;
F_59 (rt_rq, iter, rq) {
struct V_23 * V_36 = F_50 ( V_6 ) ;
F_53 ( & V_36 -> V_43 ) ;
F_53 ( & V_6 -> V_43 ) ;
V_6 -> V_22 = V_36 -> V_22 ;
V_6 -> V_47 = 0 ;
V_6 -> V_30 = 0 ;
F_56 ( & V_6 -> V_43 ) ;
F_56 ( & V_36 -> V_43 ) ;
}
}
static void F_66 ( struct V_5 * V_5 )
{
unsigned long V_51 ;
F_63 ( & V_5 -> V_52 , V_51 ) ;
F_65 ( V_5 ) ;
F_64 ( & V_5 -> V_52 , V_51 ) ;
}
static int F_67 ( struct V_6 * V_6 )
{
int V_42 = 0 ;
if ( V_6 -> V_47 > V_6 -> V_22 ) {
F_56 ( & V_6 -> V_43 ) ;
V_42 = F_51 ( V_6 ) ;
F_53 ( & V_6 -> V_43 ) ;
}
return V_42 ;
}
static inline int F_67 ( struct V_6 * V_6 )
{
return 0 ;
}
static int F_68 ( struct V_23 * V_36 , int V_53 )
{
int V_40 , V_54 = 1 ;
const struct V_33 * V_34 ;
if ( ! F_69 () || V_36 -> V_22 == V_21 )
return 1 ;
V_34 = F_46 () ;
F_54 (i, span) {
int V_55 = 0 ;
struct V_6 * V_6 = F_49 ( V_36 , V_40 ) ;
struct V_5 * V_5 = F_6 ( V_6 ) ;
F_53 ( & V_5 -> V_52 ) ;
if ( V_6 -> V_47 ) {
T_1 V_56 ;
F_53 ( & V_6 -> V_43 ) ;
if ( V_6 -> V_30 )
F_67 ( V_6 ) ;
V_56 = V_6 -> V_22 ;
V_6 -> V_47 -= F_70 ( V_6 -> V_47 , V_53 * V_56 ) ;
if ( V_6 -> V_30 && V_6 -> V_47 < V_56 ) {
V_6 -> V_30 = 0 ;
V_55 = 1 ;
if ( V_6 -> V_28 && V_5 -> V_27 == V_5 -> V_54 )
V_5 -> V_57 = - 1 ;
}
if ( V_6 -> V_47 || V_6 -> V_28 )
V_54 = 0 ;
F_56 ( & V_6 -> V_43 ) ;
} else if ( V_6 -> V_28 ) {
V_54 = 0 ;
if ( ! F_44 ( V_6 ) )
V_55 = 1 ;
}
if ( V_55 )
F_38 ( V_6 ) ;
F_56 ( & V_5 -> V_52 ) ;
}
return V_54 ;
}
static inline int F_71 ( struct V_2 * V_3 )
{
#ifdef F_72
struct V_6 * V_6 = F_37 ( V_3 ) ;
if ( V_6 )
return V_6 -> V_29 . V_27 ;
#endif
return F_1 ( V_3 ) -> V_18 ;
}
static int F_73 ( struct V_6 * V_6 )
{
T_1 V_56 = F_30 ( V_6 ) ;
if ( V_6 -> V_30 )
return F_44 ( V_6 ) ;
if ( F_30 ( V_6 ) >= F_31 ( V_6 ) )
return 0 ;
F_67 ( V_6 ) ;
V_56 = F_30 ( V_6 ) ;
if ( V_56 == V_21 )
return 0 ;
if ( V_6 -> V_47 > V_56 ) {
V_6 -> V_30 = 1 ;
if ( F_44 ( V_6 ) ) {
F_42 ( V_6 ) ;
return 1 ;
}
}
return 0 ;
}
static void F_74 ( struct V_5 * V_5 )
{
struct V_1 * V_27 = V_5 -> V_27 ;
struct V_2 * V_3 = & V_27 -> V_4 ;
struct V_6 * V_6 = F_7 ( V_3 ) ;
T_1 V_58 ;
if ( V_27 -> V_59 != & V_60 )
return;
V_58 = V_5 -> V_61 - V_27 -> V_62 . V_63 ;
if ( F_58 ( ( T_2 ) V_58 < 0 ) )
V_58 = 0 ;
F_75 ( V_27 -> V_62 . V_64 . V_65 , F_76 ( V_27 -> V_62 . V_64 . V_65 , V_58 ) ) ;
V_27 -> V_62 . V_66 += V_58 ;
F_77 ( V_27 , V_58 ) ;
V_27 -> V_62 . V_63 = V_5 -> V_61 ;
F_78 ( V_27 , V_58 ) ;
F_79 ( V_5 , V_58 ) ;
if ( ! F_69 () )
return;
F_80 (rt_se) {
V_6 = F_7 ( V_3 ) ;
if ( F_30 ( V_6 ) != V_21 ) {
F_53 ( & V_6 -> V_43 ) ;
V_6 -> V_47 += V_58 ;
if ( F_73 ( V_6 ) )
F_41 ( V_27 ) ;
F_56 ( & V_6 -> V_43 ) ;
}
}
}
static inline int F_81 ( struct V_5 * V_5 )
{
struct V_1 * V_46 = F_82 ( V_5 , V_5 -> V_11 ) ;
if ( V_46 && F_83 ( V_46 -> V_18 ) )
return V_46 -> V_18 ;
else
return V_67 ;
}
static void
F_84 ( struct V_6 * V_6 , int V_18 , int V_68 )
{
struct V_5 * V_5 = F_6 ( V_6 ) ;
if ( V_18 < V_68 ) {
V_6 -> V_29 . V_46 = V_68 ;
if ( V_5 -> V_10 )
F_85 ( & V_5 -> V_8 -> V_69 , V_5 -> V_11 , V_18 ) ;
} else if ( V_18 == V_6 -> V_29 . V_27 )
V_6 -> V_29 . V_46 = V_18 ;
else if ( V_18 < V_6 -> V_29 . V_46 )
V_6 -> V_29 . V_46 = F_81 ( V_5 ) ;
}
static void
F_86 ( struct V_6 * V_6 , int V_18 , int V_68 )
{
struct V_5 * V_5 = F_6 ( V_6 ) ;
if ( V_6 -> V_28 && ( V_18 <= V_6 -> V_29 . V_46 ) )
V_6 -> V_29 . V_46 = F_81 ( V_5 ) ;
if ( V_5 -> V_10 && V_6 -> V_29 . V_27 != V_68 )
F_85 ( & V_5 -> V_8 -> V_69 , V_5 -> V_11 , V_6 -> V_29 . V_27 ) ;
}
static inline
void F_84 ( struct V_6 * V_6 , int V_18 , int V_68 ) {}
static inline
void F_86 ( struct V_6 * V_6 , int V_18 , int V_68 ) {}
static void
F_87 ( struct V_6 * V_6 , int V_18 )
{
int V_68 = V_6 -> V_29 . V_27 ;
if ( V_18 < V_68 )
V_6 -> V_29 . V_27 = V_18 ;
F_84 ( V_6 , V_18 , V_68 ) ;
}
static void
F_88 ( struct V_6 * V_6 , int V_18 )
{
int V_68 = V_6 -> V_29 . V_27 ;
if ( V_6 -> V_28 ) {
F_89 ( V_18 < V_68 ) ;
if ( V_18 == V_68 ) {
struct V_70 * V_71 = & V_6 -> V_72 ;
V_6 -> V_29 . V_27 =
F_90 ( V_71 -> V_73 ) ;
}
} else
V_6 -> V_29 . V_27 = V_67 ;
F_86 ( V_6 , V_18 , V_68 ) ;
}
static inline void F_87 ( struct V_6 * V_6 , int V_18 ) {}
static inline void F_88 ( struct V_6 * V_6 , int V_18 ) {}
static void
F_91 ( struct V_2 * V_3 , struct V_6 * V_6 )
{
if ( F_45 ( V_3 ) )
V_6 -> V_31 ++ ;
if ( V_6 -> V_20 )
F_92 ( & V_6 -> V_20 -> V_23 ) ;
}
static void
F_93 ( struct V_2 * V_3 , struct V_6 * V_6 )
{
if ( F_45 ( V_3 ) )
V_6 -> V_31 -- ;
F_89 ( ! V_6 -> V_28 && V_6 -> V_31 ) ;
}
static void
F_91 ( struct V_2 * V_3 , struct V_6 * V_6 )
{
F_92 ( & V_38 ) ;
}
static inline
void F_93 ( struct V_2 * V_3 , struct V_6 * V_6 ) {}
static inline
void F_94 ( struct V_2 * V_3 , struct V_6 * V_6 )
{
int V_18 = F_71 ( V_3 ) ;
F_89 ( ! F_83 ( V_18 ) ) ;
V_6 -> V_28 ++ ;
F_87 ( V_6 , V_18 ) ;
F_19 ( V_3 , V_6 ) ;
F_91 ( V_3 , V_6 ) ;
}
static inline
void F_95 ( struct V_2 * V_3 , struct V_6 * V_6 )
{
F_89 ( ! F_83 ( F_71 ( V_3 ) ) ) ;
F_89 ( ! V_6 -> V_28 ) ;
V_6 -> V_28 -- ;
F_88 ( V_6 , F_71 ( V_3 ) ) ;
F_20 ( V_3 , V_6 ) ;
F_93 ( V_3 , V_6 ) ;
}
static void F_96 ( struct V_2 * V_3 , bool V_74 )
{
struct V_6 * V_6 = F_7 ( V_3 ) ;
struct V_70 * V_71 = & V_6 -> V_72 ;
struct V_6 * V_75 = F_37 ( V_3 ) ;
struct V_76 * V_77 = V_71 -> V_77 + F_71 ( V_3 ) ;
if ( V_75 && ( F_44 ( V_75 ) || ! V_75 -> V_28 ) )
return;
if ( ! V_6 -> V_28 )
F_33 ( V_6 ) ;
if ( V_74 )
F_97 ( & V_3 -> V_19 , V_77 ) ;
else
F_98 ( & V_3 -> V_19 , V_77 ) ;
F_99 ( F_71 ( V_3 ) , V_71 -> V_73 ) ;
F_94 ( V_3 , V_6 ) ;
}
static void F_100 ( struct V_2 * V_3 )
{
struct V_6 * V_6 = F_7 ( V_3 ) ;
struct V_70 * V_71 = & V_6 -> V_72 ;
F_101 ( & V_3 -> V_19 ) ;
if ( F_29 ( V_71 -> V_77 + F_71 ( V_3 ) ) )
F_102 ( F_71 ( V_3 ) , V_71 -> V_73 ) ;
F_95 ( V_3 , V_6 ) ;
if ( ! V_6 -> V_28 )
F_35 ( V_6 ) ;
}
static void F_103 ( struct V_2 * V_3 )
{
struct V_2 * V_78 = NULL ;
F_80 (rt_se) {
V_3 -> V_78 = V_78 ;
V_78 = V_3 ;
}
for ( V_3 = V_78 ; V_3 ; V_3 = V_3 -> V_78 ) {
if ( F_28 ( V_3 ) )
F_100 ( V_3 ) ;
}
}
static void F_40 ( struct V_2 * V_3 , bool V_74 )
{
F_103 ( V_3 ) ;
F_80 (rt_se)
F_96 ( V_3 , V_74 ) ;
}
static void F_43 ( struct V_2 * V_3 )
{
F_103 ( V_3 ) ;
F_80 (rt_se) {
struct V_6 * V_6 = F_37 ( V_3 ) ;
if ( V_6 && V_6 -> V_28 )
F_96 ( V_3 , false ) ;
}
}
static void
F_104 ( struct V_5 * V_5 , struct V_1 * V_7 , int V_51 )
{
struct V_2 * V_3 = & V_7 -> V_4 ;
if ( V_51 & V_79 )
V_3 -> V_80 = 0 ;
F_40 ( V_3 , V_51 & V_81 ) ;
if ( ! F_105 ( V_5 , V_7 ) && V_7 -> V_4 . V_16 > 1 )
F_21 ( V_5 , V_7 ) ;
}
static void F_106 ( struct V_5 * V_5 , struct V_1 * V_7 , int V_51 )
{
struct V_2 * V_3 = & V_7 -> V_4 ;
F_74 ( V_5 ) ;
F_43 ( V_3 ) ;
F_25 ( V_5 , V_7 ) ;
}
static void
F_107 ( struct V_6 * V_6 , struct V_2 * V_3 , int V_74 )
{
if ( F_28 ( V_3 ) ) {
struct V_70 * V_71 = & V_6 -> V_72 ;
struct V_76 * V_77 = V_71 -> V_77 + F_71 ( V_3 ) ;
if ( V_74 )
F_108 ( & V_3 -> V_19 , V_77 ) ;
else
F_109 ( & V_3 -> V_19 , V_77 ) ;
}
}
static void F_110 ( struct V_5 * V_5 , struct V_1 * V_7 , int V_74 )
{
struct V_2 * V_3 = & V_7 -> V_4 ;
struct V_6 * V_6 ;
F_80 (rt_se) {
V_6 = F_7 ( V_3 ) ;
F_107 ( V_6 , V_3 , V_74 ) ;
}
}
static void F_111 ( struct V_5 * V_5 )
{
F_110 ( V_5 , V_5 -> V_27 , 0 ) ;
}
static int
F_112 ( struct V_1 * V_7 , int V_82 , int V_51 )
{
struct V_1 * V_27 ;
struct V_5 * V_5 ;
int V_11 ;
if ( V_82 != V_83 )
return F_48 () ;
V_11 = F_113 ( V_7 ) ;
V_5 = F_47 ( V_11 ) ;
F_114 () ;
V_27 = F_115 ( V_5 -> V_27 ) ;
if ( V_27 && F_58 ( F_116 ( V_27 ) ) &&
( V_27 -> V_4 . V_16 < 2 ||
V_27 -> V_18 < V_7 -> V_18 ) &&
( V_7 -> V_4 . V_16 > 1 ) ) {
int V_84 = F_117 ( V_7 ) ;
if ( V_84 != - 1 )
V_11 = V_84 ;
}
F_118 () ;
return V_11 ;
}
static void F_119 ( struct V_5 * V_5 , struct V_1 * V_7 )
{
if ( V_5 -> V_27 -> V_4 . V_16 == 1 )
return;
if ( V_7 -> V_4 . V_16 != 1
&& F_120 ( & V_5 -> V_8 -> V_69 , V_7 , NULL ) )
return;
if ( ! F_120 ( & V_5 -> V_8 -> V_69 , V_5 -> V_27 , NULL ) )
return;
F_110 ( V_5 , V_7 , 1 ) ;
F_41 ( V_5 -> V_27 ) ;
}
static void F_121 ( struct V_5 * V_5 , struct V_1 * V_7 , int V_51 )
{
if ( V_7 -> V_18 < V_5 -> V_27 -> V_18 ) {
F_41 ( V_5 -> V_27 ) ;
return;
}
#ifdef F_122
if ( V_7 -> V_18 == V_5 -> V_27 -> V_18 && ! F_123 ( V_5 -> V_27 ) )
F_119 ( V_5 , V_7 ) ;
#endif
}
static struct V_2 * F_124 ( struct V_5 * V_5 ,
struct V_6 * V_6 )
{
struct V_70 * V_71 = & V_6 -> V_72 ;
struct V_2 * V_46 = NULL ;
struct V_76 * V_77 ;
int V_85 ;
V_85 = F_90 ( V_71 -> V_73 ) ;
F_61 ( V_85 >= V_67 ) ;
V_77 = V_71 -> V_77 + V_85 ;
V_46 = F_125 ( V_77 -> V_46 , struct V_2 , V_19 ) ;
return V_46 ;
}
static struct V_1 * F_126 ( struct V_5 * V_5 )
{
struct V_2 * V_3 ;
struct V_1 * V_7 ;
struct V_6 * V_6 ;
V_6 = & V_5 -> V_4 ;
if ( F_58 ( ! V_6 -> V_28 ) )
return NULL ;
if ( F_44 ( V_6 ) )
return NULL ;
do {
V_3 = F_124 ( V_5 , V_6 ) ;
F_61 ( ! V_3 ) ;
V_6 = F_37 ( V_3 ) ;
} while ( V_6 );
V_7 = F_1 ( V_3 ) ;
V_7 -> V_62 . V_63 = V_5 -> V_61 ;
return V_7 ;
}
static struct V_1 * F_127 ( struct V_5 * V_5 )
{
struct V_1 * V_7 = F_126 ( V_5 ) ;
if ( V_7 )
F_25 ( V_5 , V_7 ) ;
#ifdef F_122
V_5 -> V_86 = F_26 ( V_5 ) ;
#endif
return V_7 ;
}
static void F_128 ( struct V_5 * V_5 , struct V_1 * V_7 )
{
F_74 ( V_5 ) ;
V_7 -> V_62 . V_63 = 0 ;
if ( F_28 ( & V_7 -> V_4 ) && V_7 -> V_4 . V_16 > 1 )
F_21 ( V_5 , V_7 ) ;
}
static int F_129 ( struct V_5 * V_5 , struct V_1 * V_7 , int V_11 )
{
if ( ! F_130 ( V_5 , V_7 ) &&
( V_11 < 0 || F_131 ( V_11 , & V_7 -> V_87 ) ) &&
( V_7 -> V_4 . V_16 > 1 ) )
return 1 ;
return 0 ;
}
static struct V_1 * F_82 ( struct V_5 * V_5 , int V_11 )
{
struct V_1 * V_46 = NULL ;
struct V_2 * V_3 ;
struct V_70 * V_71 ;
struct V_6 * V_6 ;
int V_85 ;
F_132 (rt_rq, rq) {
V_71 = & V_6 -> V_72 ;
V_85 = F_90 ( V_71 -> V_73 ) ;
V_88:
if ( V_85 >= V_67 )
continue;
if ( V_46 && V_46 -> V_18 < V_85 )
continue;
F_133 (rt_se, array->queue + idx, run_list) {
struct V_1 * V_7 ;
if ( ! F_4 ( V_3 ) )
continue;
V_7 = F_1 ( V_3 ) ;
if ( F_129 ( V_5 , V_7 , V_11 ) ) {
V_46 = V_7 ;
break;
}
}
if ( ! V_46 ) {
V_85 = F_134 ( V_71 -> V_73 , V_67 , V_85 + 1 ) ;
goto V_88;
}
}
return V_46 ;
}
static int F_117 ( struct V_1 * V_89 )
{
struct V_90 * V_91 ;
struct V_33 * V_92 = F_135 ( V_93 ) ;
int V_94 = F_48 () ;
int V_11 = F_113 ( V_89 ) ;
if ( F_58 ( ! V_92 ) )
return - 1 ;
if ( V_89 -> V_4 . V_16 == 1 )
return - 1 ;
if ( ! F_120 ( & F_8 ( V_89 ) -> V_8 -> V_69 , V_89 , V_92 ) )
return - 1 ;
if ( F_131 ( V_11 , V_92 ) )
return V_11 ;
if ( ! F_131 ( V_94 , V_92 ) )
V_94 = - 1 ;
F_114 () ;
F_136 (cpu, sd) {
if ( V_91 -> V_51 & V_95 ) {
int V_96 ;
if ( V_94 != - 1 &&
F_131 ( V_94 , F_137 ( V_91 ) ) ) {
F_118 () ;
return V_94 ;
}
V_96 = F_138 ( V_92 ,
F_137 ( V_91 ) ) ;
if ( V_96 < V_97 ) {
F_118 () ;
return V_96 ;
}
}
}
F_118 () ;
if ( V_94 != - 1 )
return V_94 ;
V_11 = F_139 ( V_92 ) ;
if ( V_11 < V_97 )
return V_11 ;
return - 1 ;
}
static struct V_5 * F_140 ( struct V_1 * V_89 , struct V_5 * V_5 )
{
struct V_5 * V_98 = NULL ;
int V_99 ;
int V_11 ;
for ( V_99 = 0 ; V_99 < V_100 ; V_99 ++ ) {
V_11 = F_117 ( V_89 ) ;
if ( ( V_11 == - 1 ) || ( V_11 == V_5 -> V_11 ) )
break;
V_98 = F_47 ( V_11 ) ;
if ( F_141 ( V_5 , V_98 ) ) {
if ( F_58 ( F_8 ( V_89 ) != V_5 ||
! F_131 ( V_98 -> V_11 ,
& V_89 -> V_87 ) ||
F_130 ( V_5 , V_89 ) ||
! V_89 -> V_101 ) ) {
F_56 ( & V_98 -> V_52 ) ;
V_98 = NULL ;
break;
}
}
if ( V_98 -> V_4 . V_29 . V_27 > V_89 -> V_18 )
break;
F_142 ( V_5 , V_98 ) ;
V_98 = NULL ;
}
return V_98 ;
}
static struct V_1 * F_143 ( struct V_5 * V_5 )
{
struct V_1 * V_7 ;
if ( ! F_26 ( V_5 ) )
return NULL ;
V_7 = F_144 ( & V_5 -> V_4 . V_17 ,
struct V_1 , V_17 ) ;
F_61 ( V_5 -> V_11 != F_113 ( V_7 ) ) ;
F_61 ( F_105 ( V_5 , V_7 ) ) ;
F_61 ( V_7 -> V_4 . V_16 <= 1 ) ;
F_61 ( ! V_7 -> V_101 ) ;
F_61 ( ! F_116 ( V_7 ) ) ;
return V_7 ;
}
static int F_145 ( struct V_5 * V_5 )
{
struct V_1 * V_102 ;
struct V_5 * V_98 ;
if ( ! V_5 -> V_4 . V_15 )
return 0 ;
V_102 = F_143 ( V_5 ) ;
if ( ! V_102 )
return 0 ;
V_103:
if ( F_58 ( V_102 == V_5 -> V_27 ) ) {
F_89 ( 1 ) ;
return 0 ;
}
if ( F_58 ( V_102 -> V_18 < V_5 -> V_27 -> V_18 ) ) {
F_41 ( V_5 -> V_27 ) ;
return 0 ;
}
F_146 ( V_102 ) ;
V_98 = F_140 ( V_102 , V_5 ) ;
if ( ! V_98 ) {
struct V_1 * V_89 ;
V_89 = F_143 ( V_5 ) ;
if ( F_113 ( V_102 ) == V_5 -> V_11 && V_89 == V_102 ) {
F_25 ( V_5 , V_102 ) ;
goto V_104;
}
if ( ! V_89 )
goto V_104;
F_147 ( V_102 ) ;
V_102 = V_89 ;
goto V_103;
}
F_148 ( V_5 , V_102 , 0 ) ;
F_149 ( V_102 , V_98 -> V_11 ) ;
F_150 ( V_98 , V_102 , 0 ) ;
F_41 ( V_98 -> V_27 ) ;
F_142 ( V_5 , V_98 ) ;
V_104:
F_147 ( V_102 ) ;
return 1 ;
}
static void F_151 ( struct V_5 * V_5 )
{
while ( F_145 ( V_5 ) )
;
}
static int F_152 ( struct V_5 * V_105 )
{
int V_94 = V_105 -> V_11 , V_106 = 0 , V_11 ;
struct V_1 * V_7 ;
struct V_5 * V_107 ;
if ( F_153 ( ! F_9 ( V_105 ) ) )
return 0 ;
F_54 (cpu, this_rq->rd->rto_mask) {
if ( V_94 == V_11 )
continue;
V_107 = F_47 ( V_11 ) ;
if ( V_107 -> V_4 . V_29 . V_46 >=
V_105 -> V_4 . V_29 . V_27 )
continue;
F_141 ( V_105 , V_107 ) ;
if ( V_107 -> V_4 . V_28 <= 1 )
goto V_108;
V_7 = F_82 ( V_107 , V_94 ) ;
if ( V_7 && ( V_7 -> V_18 < V_105 -> V_4 . V_29 . V_27 ) ) {
F_89 ( V_7 == V_107 -> V_27 ) ;
F_89 ( ! V_7 -> V_101 ) ;
if ( V_7 -> V_18 < V_107 -> V_27 -> V_18 )
goto V_108;
V_106 = 1 ;
F_148 ( V_107 , V_7 , 0 ) ;
F_149 ( V_7 , V_94 ) ;
F_150 ( V_105 , V_7 , 0 ) ;
}
V_108:
F_142 ( V_105 , V_107 ) ;
}
return V_106 ;
}
static void F_154 ( struct V_5 * V_5 , struct V_1 * V_109 )
{
if ( F_58 ( F_116 ( V_109 ) ) && V_5 -> V_4 . V_29 . V_27 > V_109 -> V_18 )
F_152 ( V_5 ) ;
}
static void F_155 ( struct V_5 * V_5 )
{
F_151 ( V_5 ) ;
}
static void F_156 ( struct V_5 * V_5 , struct V_1 * V_7 )
{
if ( ! F_130 ( V_5 , V_7 ) &&
! F_123 ( V_5 -> V_27 ) &&
F_26 ( V_5 ) &&
V_7 -> V_4 . V_16 > 1 &&
F_116 ( V_5 -> V_27 ) &&
( V_5 -> V_27 -> V_4 . V_16 < 2 ||
V_5 -> V_27 -> V_18 < V_7 -> V_18 ) )
F_151 ( V_5 ) ;
}
static void F_157 ( struct V_1 * V_7 ,
const struct V_33 * V_110 )
{
int V_41 = F_52 ( V_110 ) ;
F_61 ( ! F_116 ( V_7 ) ) ;
if ( V_7 -> V_101 && ( V_41 != V_7 -> V_4 . V_16 ) ) {
struct V_5 * V_5 = F_8 ( V_7 ) ;
if ( ! F_105 ( V_5 , V_7 ) ) {
if ( V_7 -> V_4 . V_16 > 1 )
F_25 ( V_5 , V_7 ) ;
if ( V_41 > 1 )
F_21 ( V_5 , V_7 ) ;
}
if ( ( V_7 -> V_4 . V_16 <= 1 ) && ( V_41 > 1 ) ) {
V_5 -> V_4 . V_13 ++ ;
} else if ( ( V_7 -> V_4 . V_16 > 1 ) && ( V_41 <= 1 ) ) {
F_61 ( ! V_5 -> V_4 . V_13 ) ;
V_5 -> V_4 . V_13 -- ;
}
F_18 ( & V_5 -> V_4 ) ;
}
F_158 ( & V_7 -> V_87 , V_110 ) ;
V_7 -> V_4 . V_16 = V_41 ;
}
static void F_159 ( struct V_5 * V_5 )
{
if ( V_5 -> V_4 . V_15 )
F_11 ( V_5 ) ;
F_65 ( V_5 ) ;
F_85 ( & V_5 -> V_8 -> V_69 , V_5 -> V_11 , V_5 -> V_4 . V_29 . V_27 ) ;
}
static void F_160 ( struct V_5 * V_5 )
{
if ( V_5 -> V_4 . V_15 )
F_15 ( V_5 ) ;
F_57 ( V_5 ) ;
F_85 ( & V_5 -> V_8 -> V_69 , V_5 -> V_11 , V_111 ) ;
}
static void F_161 ( struct V_5 * V_5 , struct V_1 * V_7 )
{
if ( V_7 -> V_101 && ! V_5 -> V_4 . V_28 )
F_152 ( V_5 ) ;
}
static inline void F_162 ( void )
{
unsigned int V_40 ;
F_163 (i)
F_164 ( & F_165 ( V_93 , V_40 ) ,
V_112 , F_166 ( V_40 ) ) ;
}
static void F_167 ( struct V_5 * V_5 , struct V_1 * V_7 )
{
int V_113 = 1 ;
if ( V_7 -> V_101 && V_5 -> V_27 != V_7 ) {
#ifdef F_122
if ( V_5 -> V_4 . V_15 && F_145 ( V_5 ) &&
V_5 != F_8 ( V_7 ) )
V_113 = 0 ;
#endif
if ( V_113 && V_7 -> V_18 < V_5 -> V_27 -> V_18 )
F_41 ( V_5 -> V_27 ) ;
}
}
static void
F_168 ( struct V_5 * V_5 , struct V_1 * V_7 , int V_114 )
{
if ( ! V_7 -> V_101 )
return;
if ( V_5 -> V_27 == V_7 ) {
#ifdef F_122
if ( V_114 < V_7 -> V_18 )
F_152 ( V_5 ) ;
if ( V_7 -> V_18 > V_5 -> V_4 . V_29 . V_27 && V_5 -> V_27 == V_7 )
F_41 ( V_7 ) ;
#else
if ( V_114 < V_7 -> V_18 )
F_41 ( V_7 ) ;
#endif
} else {
if ( V_7 -> V_18 < V_5 -> V_27 -> V_18 )
F_41 ( V_5 -> V_27 ) ;
}
}
static void F_169 ( struct V_5 * V_5 , struct V_1 * V_7 )
{
unsigned long V_115 , V_116 ;
V_115 = F_170 ( V_7 , V_117 ) ;
V_116 = F_171 ( V_7 , V_117 ) ;
if ( V_115 != V_118 ) {
unsigned long V_46 ;
V_7 -> V_4 . V_80 ++ ;
V_46 = F_172 ( F_70 ( V_115 , V_116 ) , V_119 / V_120 ) ;
if ( V_7 -> V_4 . V_80 > V_46 )
V_7 -> V_121 . V_122 = V_7 -> V_62 . V_66 ;
}
}
static void F_173 ( struct V_5 * V_5 , struct V_1 * V_7 , int V_123 )
{
F_74 ( V_5 ) ;
F_169 ( V_5 , V_7 ) ;
if ( V_7 -> V_124 != V_125 )
return;
if ( -- V_7 -> V_4 . V_126 )
return;
V_7 -> V_4 . V_126 = V_127 ;
if ( V_7 -> V_4 . V_19 . V_109 != V_7 -> V_4 . V_19 . V_46 ) {
F_110 ( V_5 , V_7 , 0 ) ;
F_174 ( V_7 ) ;
}
}
static void F_175 ( struct V_5 * V_5 )
{
struct V_1 * V_7 = V_5 -> V_27 ;
V_7 -> V_62 . V_63 = V_5 -> V_61 ;
F_25 ( V_5 , V_7 ) ;
}
static unsigned int F_176 ( struct V_5 * V_5 , struct V_1 * V_89 )
{
if ( V_89 -> V_124 == V_125 )
return V_127 ;
else
return 0 ;
}
static void F_177 ( struct V_128 * V_129 , int V_11 )
{
T_3 V_44 ;
struct V_6 * V_6 ;
F_114 () ;
F_59 (rt_rq, iter, cpu_rq(cpu))
F_178 ( V_129 , V_11 , V_6 ) ;
F_118 () ;
}
