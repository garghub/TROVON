static enum V_1 F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 =
F_2 ( V_3 , struct V_4 , V_6 ) ;
T_1 V_7 ;
int V_8 ;
int V_9 = 0 ;
for (; ; ) {
V_7 = F_3 ( V_3 ) ;
V_8 = F_4 ( V_3 , V_7 , V_5 -> V_10 ) ;
if ( ! V_8 )
break;
V_9 = F_5 ( V_5 , V_8 ) ;
}
return V_9 ? V_11 : V_12 ;
}
void F_6 ( struct V_4 * V_5 , T_2 V_13 , T_2 V_14 )
{
V_5 -> V_10 = F_7 ( V_13 ) ;
V_5 -> V_15 = V_14 ;
F_8 ( & V_5 -> V_16 ) ;
F_9 ( & V_5 -> V_6 ,
V_17 , V_18 ) ;
V_5 -> V_6 . V_19 = F_1 ;
}
static void F_10 ( struct V_4 * V_5 )
{
if ( ! F_11 () || V_5 -> V_15 == V_20 )
return;
if ( F_12 ( & V_5 -> V_6 ) )
return;
F_13 ( & V_5 -> V_16 ) ;
F_14 ( & V_5 -> V_6 , V_5 -> V_10 ) ;
F_15 ( & V_5 -> V_16 ) ;
}
void F_16 ( struct V_21 * V_21 , struct V_22 * V_22 )
{
struct V_23 * V_24 ;
int V_25 ;
V_24 = & V_21 -> V_26 ;
for ( V_25 = 0 ; V_25 < V_27 ; V_25 ++ ) {
F_17 ( V_24 -> V_28 + V_25 ) ;
F_18 ( V_25 , V_24 -> V_29 ) ;
}
F_19 ( V_27 , V_24 -> V_29 ) ;
#if V_30 V_31
V_21 -> V_32 . V_33 = V_27 ;
V_21 -> V_32 . V_34 = V_27 ;
V_21 -> V_35 = 0 ;
V_21 -> V_36 = 0 ;
F_20 ( & V_21 -> V_37 ) ;
#endif
V_21 -> V_38 = 0 ;
V_21 -> V_39 = 0 ;
V_21 -> V_15 = 0 ;
F_8 ( & V_21 -> V_16 ) ;
}
static void F_21 ( struct V_4 * V_5 )
{
F_22 ( & V_5 -> V_6 ) ;
}
static inline struct V_40 * F_23 ( struct V_41 * V_42 )
{
#ifdef F_24
F_25 ( ! F_26 ( V_42 ) ) ;
#endif
return F_2 ( V_42 , struct V_40 , V_43 ) ;
}
static inline struct V_22 * F_27 ( struct V_21 * V_21 )
{
return V_21 -> V_22 ;
}
static inline struct V_21 * F_28 ( struct V_41 * V_42 )
{
return V_42 -> V_21 ;
}
void F_29 ( struct V_44 * V_45 )
{
int V_25 ;
if ( V_45 -> V_42 )
F_21 ( & V_45 -> V_4 ) ;
F_30 (i) {
if ( V_45 -> V_21 )
F_31 ( V_45 -> V_21 [ V_25 ] ) ;
if ( V_45 -> V_42 )
F_31 ( V_45 -> V_42 [ V_25 ] ) ;
}
F_31 ( V_45 -> V_21 ) ;
F_31 ( V_45 -> V_42 ) ;
}
void F_32 ( struct V_44 * V_45 , struct V_21 * V_21 ,
struct V_41 * V_42 , int V_46 ,
struct V_41 * V_47 )
{
struct V_22 * V_22 = F_33 ( V_46 ) ;
V_21 -> V_32 . V_33 = V_27 ;
V_21 -> V_48 = 0 ;
V_21 -> V_22 = V_22 ;
V_21 -> V_45 = V_45 ;
V_45 -> V_21 [ V_46 ] = V_21 ;
V_45 -> V_42 [ V_46 ] = V_42 ;
if ( ! V_42 )
return;
if ( ! V_47 )
V_42 -> V_21 = & V_22 -> V_43 ;
else
V_42 -> V_21 = V_47 -> V_49 ;
V_42 -> V_49 = V_21 ;
V_42 -> V_47 = V_47 ;
F_17 ( & V_42 -> V_50 ) ;
}
int F_34 ( struct V_44 * V_45 , struct V_44 * V_47 )
{
struct V_21 * V_21 ;
struct V_41 * V_42 ;
int V_25 ;
V_45 -> V_21 = F_35 ( sizeof( V_21 ) * V_51 , V_52 ) ;
if ( ! V_45 -> V_21 )
goto V_53;
V_45 -> V_42 = F_35 ( sizeof( V_42 ) * V_51 , V_52 ) ;
if ( ! V_45 -> V_42 )
goto V_53;
F_6 ( & V_45 -> V_4 ,
F_36 ( V_54 . V_10 ) , 0 ) ;
F_30 (i) {
V_21 = F_37 ( sizeof( struct V_21 ) ,
V_52 , F_38 ( V_25 ) ) ;
if ( ! V_21 )
goto V_53;
V_42 = F_37 ( sizeof( struct V_41 ) ,
V_52 , F_38 ( V_25 ) ) ;
if ( ! V_42 )
goto V_55;
F_16 ( V_21 , F_33 ( V_25 ) ) ;
V_21 -> V_15 = V_45 -> V_4 . V_15 ;
F_32 ( V_45 , V_21 , V_42 , V_25 , V_47 -> V_42 [ V_25 ] ) ;
}
return 1 ;
V_55:
F_31 ( V_21 ) ;
V_53:
return 0 ;
}
static inline struct V_40 * F_23 ( struct V_41 * V_42 )
{
return F_2 ( V_42 , struct V_40 , V_43 ) ;
}
static inline struct V_22 * F_27 ( struct V_21 * V_21 )
{
return F_2 ( V_21 , struct V_22 , V_43 ) ;
}
static inline struct V_21 * F_28 ( struct V_41 * V_42 )
{
struct V_40 * V_56 = F_23 ( V_42 ) ;
struct V_22 * V_22 = F_39 ( V_56 ) ;
return & V_22 -> V_43 ;
}
void F_29 ( struct V_44 * V_45 ) { }
int F_34 ( struct V_44 * V_45 , struct V_44 * V_47 )
{
return 1 ;
}
static inline bool F_40 ( struct V_22 * V_22 , struct V_40 * V_57 )
{
return V_22 -> V_43 . V_32 . V_33 > V_57 -> V_58 ;
}
static inline int F_41 ( struct V_22 * V_22 )
{
return F_42 ( & V_22 -> V_59 -> V_60 ) ;
}
static inline void F_43 ( struct V_22 * V_22 )
{
if ( ! V_22 -> V_61 )
return;
F_44 ( V_22 -> V_46 , V_22 -> V_59 -> V_62 ) ;
F_45 () ;
F_46 ( & V_22 -> V_59 -> V_60 ) ;
}
static inline void F_47 ( struct V_22 * V_22 )
{
if ( ! V_22 -> V_61 )
return;
F_48 ( & V_22 -> V_59 -> V_60 ) ;
F_49 ( V_22 -> V_46 , V_22 -> V_59 -> V_62 ) ;
}
static void F_50 ( struct V_21 * V_21 )
{
if ( V_21 -> V_35 && V_21 -> V_63 > 1 ) {
if ( ! V_21 -> V_36 ) {
F_43 ( F_27 ( V_21 ) ) ;
V_21 -> V_36 = 1 ;
}
} else if ( V_21 -> V_36 ) {
F_47 ( F_27 ( V_21 ) ) ;
V_21 -> V_36 = 0 ;
}
}
static void F_51 ( struct V_41 * V_42 , struct V_21 * V_21 )
{
struct V_40 * V_56 ;
if ( ! F_26 ( V_42 ) )
return;
V_56 = F_23 ( V_42 ) ;
V_21 = & F_27 ( V_21 ) -> V_43 ;
V_21 -> V_63 ++ ;
if ( V_56 -> V_64 > 1 )
V_21 -> V_35 ++ ;
F_50 ( V_21 ) ;
}
static void F_52 ( struct V_41 * V_42 , struct V_21 * V_21 )
{
struct V_40 * V_56 ;
if ( ! F_26 ( V_42 ) )
return;
V_56 = F_23 ( V_42 ) ;
V_21 = & F_27 ( V_21 ) -> V_43 ;
V_21 -> V_63 -- ;
if ( V_56 -> V_64 > 1 )
V_21 -> V_35 -- ;
F_50 ( V_21 ) ;
}
static inline int F_53 ( struct V_22 * V_22 )
{
return ! F_54 ( & V_22 -> V_43 . V_37 ) ;
}
static inline void F_55 ( struct V_22 * V_22 )
{
V_22 -> V_65 = F_53 ( V_22 ) ;
}
static void F_56 ( struct V_22 * V_22 , struct V_40 * V_56 )
{
F_57 ( & V_56 -> V_37 , & V_22 -> V_43 . V_37 ) ;
F_58 ( & V_56 -> V_37 , V_56 -> V_58 ) ;
F_59 ( & V_56 -> V_37 , & V_22 -> V_43 . V_37 ) ;
if ( V_56 -> V_58 < V_22 -> V_43 . V_32 . V_34 )
V_22 -> V_43 . V_32 . V_34 = V_56 -> V_58 ;
}
static void F_60 ( struct V_22 * V_22 , struct V_40 * V_56 )
{
F_57 ( & V_56 -> V_37 , & V_22 -> V_43 . V_37 ) ;
if ( F_53 ( V_22 ) ) {
V_56 = F_61 ( & V_22 -> V_43 . V_37 ,
struct V_40 , V_37 ) ;
V_22 -> V_43 . V_32 . V_34 = V_56 -> V_58 ;
} else
V_22 -> V_43 . V_32 . V_34 = V_27 ;
}
static inline void F_56 ( struct V_22 * V_22 , struct V_40 * V_56 )
{
}
static inline void F_60 ( struct V_22 * V_22 , struct V_40 * V_56 )
{
}
static inline
void F_51 ( struct V_41 * V_42 , struct V_21 * V_21 )
{
}
static inline
void F_52 ( struct V_41 * V_42 , struct V_21 * V_21 )
{
}
static inline bool F_40 ( struct V_22 * V_22 , struct V_40 * V_57 )
{
return false ;
}
static inline int F_62 ( struct V_22 * V_66 )
{
return 0 ;
}
static inline void F_55 ( struct V_22 * V_22 )
{
}
static inline int F_63 ( struct V_41 * V_42 )
{
return ! F_64 ( & V_42 -> V_50 ) ;
}
static inline T_2 F_65 ( struct V_21 * V_21 )
{
if ( ! V_21 -> V_45 )
return V_20 ;
return V_21 -> V_15 ;
}
static inline T_2 F_66 ( struct V_21 * V_21 )
{
return F_36 ( V_21 -> V_45 -> V_4 . V_10 ) ;
}
static inline struct V_44 * F_67 ( struct V_44 * V_45 )
{
do {
V_45 = F_68 ( V_45 -> V_67 . V_34 ,
F_69 ( struct V_44 ) , V_67 ) ;
} while ( & V_45 -> V_67 != & V_68 && F_70 ( V_45 ) );
if ( & V_45 -> V_67 == & V_68 )
V_45 = NULL ;
return V_45 ;
}
static inline struct V_21 * F_71 ( struct V_41 * V_42 )
{
return V_42 -> V_49 ;
}
static void F_72 ( struct V_21 * V_21 )
{
struct V_40 * V_33 = F_27 ( V_21 ) -> V_33 ;
struct V_41 * V_42 ;
int V_46 = F_73 ( F_27 ( V_21 ) ) ;
V_42 = V_21 -> V_45 -> V_42 [ V_46 ] ;
if ( V_21 -> V_69 ) {
if ( V_42 && ! F_63 ( V_42 ) )
F_74 ( V_42 , false ) ;
if ( V_21 -> V_32 . V_33 < V_33 -> V_58 )
F_75 ( V_33 ) ;
}
}
static void F_76 ( struct V_21 * V_21 )
{
struct V_41 * V_42 ;
int V_46 = F_73 ( F_27 ( V_21 ) ) ;
V_42 = V_21 -> V_45 -> V_42 [ V_46 ] ;
if ( V_42 && F_63 ( V_42 ) )
F_77 ( V_42 ) ;
}
static int F_78 ( struct V_41 * V_42 )
{
struct V_21 * V_21 = F_71 ( V_42 ) ;
struct V_40 * V_56 ;
if ( V_21 )
return ! ! V_21 -> V_48 ;
V_56 = F_23 ( V_42 ) ;
return V_56 -> V_58 != V_56 -> V_70 ;
}
static inline const struct V_71 * F_79 ( void )
{
return V_66 () -> V_59 -> V_72 ;
}
static inline const struct V_71 * F_79 ( void )
{
return V_73 ;
}
static inline
struct V_21 * F_80 ( struct V_4 * V_5 , int V_46 )
{
return F_2 ( V_5 , struct V_44 , V_4 ) -> V_21 [ V_46 ] ;
}
static inline struct V_4 * F_81 ( struct V_21 * V_21 )
{
return & V_21 -> V_45 -> V_4 ;
}
static inline T_2 F_65 ( struct V_21 * V_21 )
{
return V_21 -> V_15 ;
}
static inline T_2 F_66 ( struct V_21 * V_21 )
{
return F_36 ( V_54 . V_10 ) ;
}
static inline struct V_21 * F_71 ( struct V_41 * V_42 )
{
return NULL ;
}
static inline void F_72 ( struct V_21 * V_21 )
{
if ( V_21 -> V_69 )
F_75 ( F_27 ( V_21 ) -> V_33 ) ;
}
static inline void F_76 ( struct V_21 * V_21 )
{
}
static inline const struct V_71 * F_79 ( void )
{
return V_73 ;
}
static inline
struct V_21 * F_80 ( struct V_4 * V_5 , int V_46 )
{
return & F_33 ( V_46 ) -> V_43 ;
}
static inline struct V_4 * F_81 ( struct V_21 * V_21 )
{
return & V_54 ;
}
bool F_82 ( struct V_21 * V_21 )
{
struct V_4 * V_5 = F_81 ( V_21 ) ;
return ( F_12 ( & V_5 -> V_6 ) ||
V_21 -> V_38 < V_5 -> V_15 ) ;
}
static int F_83 ( struct V_21 * V_21 )
{
struct V_4 * V_5 = F_81 ( V_21 ) ;
struct V_74 * V_59 = F_27 ( V_21 ) -> V_59 ;
int V_25 , V_75 , V_76 = 0 ;
T_2 V_10 ;
V_75 = F_84 ( V_59 -> V_72 ) ;
F_13 ( & V_5 -> V_16 ) ;
V_10 = F_36 ( V_5 -> V_10 ) ;
F_85 (i, rd->span) {
struct V_21 * V_77 = F_80 ( V_5 , V_25 ) ;
T_3 V_78 ;
if ( V_77 == V_21 )
continue;
F_13 ( & V_77 -> V_16 ) ;
if ( V_77 -> V_15 == V_20 )
goto V_34;
V_78 = V_77 -> V_15 - V_77 -> V_38 ;
if ( V_78 > 0 ) {
V_78 = F_86 ( ( T_2 ) V_78 , V_75 ) ;
if ( V_21 -> V_15 + V_78 > V_10 )
V_78 = V_10 - V_21 -> V_15 ;
V_77 -> V_15 -= V_78 ;
V_21 -> V_15 += V_78 ;
V_76 = 1 ;
if ( V_21 -> V_15 == V_10 ) {
F_15 ( & V_77 -> V_16 ) ;
break;
}
}
V_34:
F_15 ( & V_77 -> V_16 ) ;
}
F_15 ( & V_5 -> V_16 ) ;
return V_76 ;
}
static void F_87 ( struct V_22 * V_22 )
{
struct V_74 * V_59 = V_22 -> V_59 ;
T_4 V_77 ;
struct V_21 * V_21 ;
if ( F_88 ( ! V_79 ) )
return;
F_89 (rt_rq, iter, rq) {
struct V_4 * V_5 = F_81 ( V_21 ) ;
T_3 V_80 ;
int V_25 ;
F_13 ( & V_5 -> V_16 ) ;
F_13 ( & V_21 -> V_16 ) ;
if ( V_21 -> V_15 == V_20 ||
V_21 -> V_15 == V_5 -> V_15 )
goto V_81;
F_15 ( & V_21 -> V_16 ) ;
V_80 = V_5 -> V_15 - V_21 -> V_15 ;
F_85 (i, rd->span) {
struct V_21 * V_77 = F_80 ( V_5 , V_25 ) ;
T_3 V_78 ;
if ( V_77 == V_21 || V_77 -> V_15 == V_20 )
continue;
F_13 ( & V_77 -> V_16 ) ;
if ( V_80 > 0 ) {
V_78 = F_90 ( T_3 , V_77 -> V_15 , V_80 ) ;
V_77 -> V_15 -= V_78 ;
V_80 -= V_78 ;
} else {
V_77 -> V_15 -= V_80 ;
V_80 -= V_80 ;
}
F_15 ( & V_77 -> V_16 ) ;
if ( ! V_80 )
break;
}
F_13 ( & V_21 -> V_16 ) ;
F_91 ( V_80 ) ;
V_81:
V_21 -> V_15 = V_20 ;
V_21 -> V_39 = 0 ;
F_15 ( & V_21 -> V_16 ) ;
F_15 ( & V_5 -> V_16 ) ;
}
}
static void F_92 ( struct V_22 * V_22 )
{
T_4 V_77 ;
struct V_21 * V_21 ;
if ( F_88 ( ! V_79 ) )
return;
F_89 (rt_rq, iter, rq) {
struct V_4 * V_5 = F_81 ( V_21 ) ;
F_13 ( & V_5 -> V_16 ) ;
F_13 ( & V_21 -> V_16 ) ;
V_21 -> V_15 = V_5 -> V_15 ;
V_21 -> V_38 = 0 ;
V_21 -> V_39 = 0 ;
F_15 ( & V_21 -> V_16 ) ;
F_15 ( & V_5 -> V_16 ) ;
}
}
static int F_93 ( struct V_21 * V_21 )
{
int V_76 = 0 ;
if ( ! F_94 ( V_82 ) )
return V_76 ;
if ( V_21 -> V_38 > V_21 -> V_15 ) {
F_15 ( & V_21 -> V_16 ) ;
V_76 = F_83 ( V_21 ) ;
F_13 ( & V_21 -> V_16 ) ;
}
return V_76 ;
}
static inline int F_93 ( struct V_21 * V_21 )
{
return 0 ;
}
static int F_5 ( struct V_4 * V_5 , int V_8 )
{
int V_25 , V_9 = 1 , V_83 = 0 ;
const struct V_71 * V_72 ;
V_72 = F_79 () ;
#ifdef F_95
if ( V_5 == & V_84 . V_4 )
V_72 = V_73 ;
#endif
F_85 (i, span) {
int V_85 = 0 ;
struct V_21 * V_21 = F_80 ( V_5 , V_25 ) ;
struct V_22 * V_22 = F_27 ( V_21 ) ;
F_13 ( & V_22 -> V_86 ) ;
if ( V_21 -> V_38 ) {
T_2 V_14 ;
F_13 ( & V_21 -> V_16 ) ;
if ( V_21 -> V_39 )
F_93 ( V_21 ) ;
V_14 = V_21 -> V_15 ;
V_21 -> V_38 -= F_96 ( V_21 -> V_38 , V_8 * V_14 ) ;
if ( V_21 -> V_39 && V_21 -> V_38 < V_14 ) {
V_21 -> V_39 = 0 ;
V_85 = 1 ;
if ( V_21 -> V_69 && V_22 -> V_33 == V_22 -> V_9 )
V_22 -> V_87 = - 1 ;
}
if ( V_21 -> V_38 || V_21 -> V_69 )
V_9 = 0 ;
F_15 ( & V_21 -> V_16 ) ;
} else if ( V_21 -> V_69 ) {
V_9 = 0 ;
if ( ! F_97 ( V_21 ) )
V_85 = 1 ;
}
if ( V_21 -> V_39 )
V_83 = 1 ;
if ( V_85 )
F_72 ( V_21 ) ;
F_15 ( & V_22 -> V_86 ) ;
}
if ( ! V_83 && ( ! F_11 () || V_5 -> V_15 == V_20 ) )
return 1 ;
return V_9 ;
}
static inline int F_98 ( struct V_41 * V_42 )
{
#ifdef F_95
struct V_21 * V_21 = F_71 ( V_42 ) ;
if ( V_21 )
return V_21 -> V_32 . V_33 ;
#endif
return F_23 ( V_42 ) -> V_58 ;
}
static int F_99 ( struct V_21 * V_21 )
{
T_2 V_14 = F_65 ( V_21 ) ;
if ( V_21 -> V_39 )
return F_97 ( V_21 ) ;
if ( V_14 >= F_66 ( V_21 ) )
return 0 ;
F_93 ( V_21 ) ;
V_14 = F_65 ( V_21 ) ;
if ( V_14 == V_20 )
return 0 ;
if ( V_21 -> V_38 > V_14 ) {
struct V_4 * V_5 = F_81 ( V_21 ) ;
if ( F_100 ( V_5 -> V_15 ) ) {
static bool V_88 = false ;
V_21 -> V_39 = 1 ;
if ( ! V_88 ) {
V_88 = true ;
F_101 ( L_1 ) ;
}
} else {
V_21 -> V_38 = 0 ;
}
if ( F_97 ( V_21 ) ) {
F_76 ( V_21 ) ;
return 1 ;
}
}
return 0 ;
}
static void F_102 ( struct V_22 * V_22 )
{
struct V_40 * V_33 = V_22 -> V_33 ;
struct V_41 * V_42 = & V_33 -> V_43 ;
struct V_21 * V_21 = F_28 ( V_42 ) ;
T_2 V_89 ;
if ( V_33 -> V_90 != & V_91 )
return;
V_89 = F_103 ( V_22 ) - V_33 -> V_92 . V_93 ;
if ( F_88 ( ( T_3 ) V_89 <= 0 ) )
return;
F_104 ( V_33 -> V_92 . V_94 . V_95 ,
F_105 ( V_33 -> V_92 . V_94 . V_95 , V_89 ) ) ;
V_33 -> V_92 . V_96 += V_89 ;
F_106 ( V_33 , V_89 ) ;
V_33 -> V_92 . V_93 = F_103 ( V_22 ) ;
F_107 ( V_33 , V_89 ) ;
F_108 ( V_22 , V_89 ) ;
if ( ! F_11 () )
return;
F_109 (rt_se) {
V_21 = F_28 ( V_42 ) ;
if ( F_65 ( V_21 ) != V_20 ) {
F_13 ( & V_21 -> V_16 ) ;
V_21 -> V_38 += V_89 ;
if ( F_99 ( V_21 ) )
F_75 ( V_33 ) ;
F_15 ( & V_21 -> V_16 ) ;
}
}
}
static void
F_110 ( struct V_21 * V_21 , int V_58 , int V_97 )
{
struct V_22 * V_22 = F_27 ( V_21 ) ;
#ifdef F_95
if ( & V_22 -> V_43 != V_21 )
return;
#endif
if ( V_22 -> V_61 && V_58 < V_97 )
F_111 ( & V_22 -> V_59 -> V_98 , V_22 -> V_46 , V_58 ) ;
}
static void
F_112 ( struct V_21 * V_21 , int V_58 , int V_97 )
{
struct V_22 * V_22 = F_27 ( V_21 ) ;
#ifdef F_95
if ( & V_22 -> V_43 != V_21 )
return;
#endif
if ( V_22 -> V_61 && V_21 -> V_32 . V_33 != V_97 )
F_111 ( & V_22 -> V_59 -> V_98 , V_22 -> V_46 , V_21 -> V_32 . V_33 ) ;
}
static inline
void F_110 ( struct V_21 * V_21 , int V_58 , int V_97 ) {}
static inline
void F_112 ( struct V_21 * V_21 , int V_58 , int V_97 ) {}
static void
F_113 ( struct V_21 * V_21 , int V_58 )
{
int V_97 = V_21 -> V_32 . V_33 ;
if ( V_58 < V_97 )
V_21 -> V_32 . V_33 = V_58 ;
F_110 ( V_21 , V_58 , V_97 ) ;
}
static void
F_114 ( struct V_21 * V_21 , int V_58 )
{
int V_97 = V_21 -> V_32 . V_33 ;
if ( V_21 -> V_69 ) {
F_115 ( V_58 < V_97 ) ;
if ( V_58 == V_97 ) {
struct V_23 * V_24 = & V_21 -> V_26 ;
V_21 -> V_32 . V_33 =
F_116 ( V_24 -> V_29 ) ;
}
} else
V_21 -> V_32 . V_33 = V_27 ;
F_112 ( V_21 , V_58 , V_97 ) ;
}
static inline void F_113 ( struct V_21 * V_21 , int V_58 ) {}
static inline void F_114 ( struct V_21 * V_21 , int V_58 ) {}
static void
F_117 ( struct V_41 * V_42 , struct V_21 * V_21 )
{
if ( F_78 ( V_42 ) )
V_21 -> V_48 ++ ;
if ( V_21 -> V_45 )
F_10 ( & V_21 -> V_45 -> V_4 ) ;
}
static void
F_118 ( struct V_41 * V_42 , struct V_21 * V_21 )
{
if ( F_78 ( V_42 ) )
V_21 -> V_48 -- ;
F_115 ( ! V_21 -> V_69 && V_21 -> V_48 ) ;
}
static void
F_117 ( struct V_41 * V_42 , struct V_21 * V_21 )
{
F_10 ( & V_54 ) ;
}
static inline
void F_118 ( struct V_41 * V_42 , struct V_21 * V_21 ) {}
static inline
void F_119 ( struct V_41 * V_42 , struct V_21 * V_21 )
{
int V_58 = F_98 ( V_42 ) ;
F_115 ( ! F_120 ( V_58 ) ) ;
V_21 -> V_69 ++ ;
F_113 ( V_21 , V_58 ) ;
F_51 ( V_42 , V_21 ) ;
F_117 ( V_42 , V_21 ) ;
}
static inline
void F_121 ( struct V_41 * V_42 , struct V_21 * V_21 )
{
F_115 ( ! F_120 ( F_98 ( V_42 ) ) ) ;
F_115 ( ! V_21 -> V_69 ) ;
V_21 -> V_69 -- ;
F_114 ( V_21 , F_98 ( V_42 ) ) ;
F_52 ( V_42 , V_21 ) ;
F_118 ( V_42 , V_21 ) ;
}
static void F_122 ( struct V_41 * V_42 , bool V_99 )
{
struct V_21 * V_21 = F_28 ( V_42 ) ;
struct V_23 * V_24 = & V_21 -> V_26 ;
struct V_21 * V_100 = F_71 ( V_42 ) ;
struct V_101 * V_28 = V_24 -> V_28 + F_98 ( V_42 ) ;
if ( V_100 && ( F_97 ( V_100 ) || ! V_100 -> V_69 ) )
return;
if ( V_99 )
F_123 ( & V_42 -> V_50 , V_28 ) ;
else
F_124 ( & V_42 -> V_50 , V_28 ) ;
F_19 ( F_98 ( V_42 ) , V_24 -> V_29 ) ;
F_119 ( V_42 , V_21 ) ;
}
static void F_125 ( struct V_41 * V_42 )
{
struct V_21 * V_21 = F_28 ( V_42 ) ;
struct V_23 * V_24 = & V_21 -> V_26 ;
F_126 ( & V_42 -> V_50 ) ;
if ( F_64 ( V_24 -> V_28 + F_98 ( V_42 ) ) )
F_18 ( F_98 ( V_42 ) , V_24 -> V_29 ) ;
F_121 ( V_42 , V_21 ) ;
}
static void F_127 ( struct V_41 * V_42 )
{
struct V_41 * V_102 = NULL ;
F_109 (rt_se) {
V_42 -> V_102 = V_102 ;
V_102 = V_42 ;
}
for ( V_42 = V_102 ; V_42 ; V_42 = V_42 -> V_102 ) {
if ( F_63 ( V_42 ) )
F_125 ( V_42 ) ;
}
}
static void F_74 ( struct V_41 * V_42 , bool V_99 )
{
F_127 ( V_42 ) ;
F_109 (rt_se)
F_122 ( V_42 , V_99 ) ;
}
static void F_77 ( struct V_41 * V_42 )
{
F_127 ( V_42 ) ;
F_109 (rt_se) {
struct V_21 * V_21 = F_71 ( V_42 ) ;
if ( V_21 && V_21 -> V_69 )
F_122 ( V_42 , false ) ;
}
}
static void
F_128 ( struct V_22 * V_22 , struct V_40 * V_56 , int V_103 )
{
struct V_41 * V_42 = & V_56 -> V_43 ;
if ( V_103 & V_104 )
V_42 -> V_105 = 0 ;
F_74 ( V_42 , V_103 & V_106 ) ;
if ( ! F_129 ( V_22 , V_56 ) && V_56 -> V_64 > 1 )
F_56 ( V_22 , V_56 ) ;
F_130 ( V_22 ) ;
}
static void F_131 ( struct V_22 * V_22 , struct V_40 * V_56 , int V_103 )
{
struct V_41 * V_42 = & V_56 -> V_43 ;
F_102 ( V_22 ) ;
F_77 ( V_42 ) ;
F_60 ( V_22 , V_56 ) ;
F_132 ( V_22 ) ;
}
static void
F_133 ( struct V_21 * V_21 , struct V_41 * V_42 , int V_99 )
{
if ( F_63 ( V_42 ) ) {
struct V_23 * V_24 = & V_21 -> V_26 ;
struct V_101 * V_28 = V_24 -> V_28 + F_98 ( V_42 ) ;
if ( V_99 )
F_134 ( & V_42 -> V_50 , V_28 ) ;
else
F_135 ( & V_42 -> V_50 , V_28 ) ;
}
}
static void F_136 ( struct V_22 * V_22 , struct V_40 * V_56 , int V_99 )
{
struct V_41 * V_42 = & V_56 -> V_43 ;
struct V_21 * V_21 ;
F_109 (rt_se) {
V_21 = F_28 ( V_42 ) ;
F_133 ( V_21 , V_42 , V_99 ) ;
}
}
static void F_137 ( struct V_22 * V_22 )
{
F_136 ( V_22 , V_22 -> V_33 , 0 ) ;
}
static int
F_138 ( struct V_40 * V_56 , int V_46 , int V_107 , int V_103 )
{
struct V_40 * V_33 ;
struct V_22 * V_22 ;
if ( V_56 -> V_64 == 1 )
goto V_108;
if ( V_107 != V_109 && V_107 != V_110 )
goto V_108;
V_22 = F_33 ( V_46 ) ;
F_139 () ;
V_33 = F_140 ( V_22 -> V_33 ) ;
if ( V_33 && F_88 ( F_141 ( V_33 ) ) &&
( V_33 -> V_64 < 2 ||
V_33 -> V_58 <= V_56 -> V_58 ) ) {
int V_111 = F_142 ( V_56 ) ;
if ( V_111 != - 1 )
V_46 = V_111 ;
}
F_143 () ;
V_108:
return V_46 ;
}
static void F_144 ( struct V_22 * V_22 , struct V_40 * V_56 )
{
if ( V_22 -> V_33 -> V_64 == 1 )
return;
if ( V_56 -> V_64 != 1
&& F_145 ( & V_22 -> V_59 -> V_98 , V_56 , NULL ) )
return;
if ( ! F_145 ( & V_22 -> V_59 -> V_98 , V_22 -> V_33 , NULL ) )
return;
F_136 ( V_22 , V_56 , 1 ) ;
F_75 ( V_22 -> V_33 ) ;
}
static void F_146 ( struct V_22 * V_22 , struct V_40 * V_56 , int V_103 )
{
if ( V_56 -> V_58 < V_22 -> V_33 -> V_58 ) {
F_75 ( V_22 -> V_33 ) ;
return;
}
#ifdef V_31
if ( V_56 -> V_58 == V_22 -> V_33 -> V_58 && ! F_147 ( V_22 -> V_33 ) )
F_144 ( V_22 , V_56 ) ;
#endif
}
static struct V_41 * F_148 ( struct V_22 * V_22 ,
struct V_21 * V_21 )
{
struct V_23 * V_24 = & V_21 -> V_26 ;
struct V_41 * V_34 = NULL ;
struct V_101 * V_28 ;
int V_112 ;
V_112 = F_116 ( V_24 -> V_29 ) ;
F_91 ( V_112 >= V_27 ) ;
V_28 = V_24 -> V_28 + V_112 ;
V_34 = F_149 ( V_28 -> V_34 , struct V_41 , V_50 ) ;
return V_34 ;
}
static struct V_40 * F_150 ( struct V_22 * V_22 )
{
struct V_41 * V_42 ;
struct V_40 * V_56 ;
struct V_21 * V_21 = & V_22 -> V_43 ;
do {
V_42 = F_148 ( V_22 , V_21 ) ;
F_91 ( ! V_42 ) ;
V_21 = F_71 ( V_42 ) ;
} while ( V_21 );
V_56 = F_23 ( V_42 ) ;
V_56 -> V_92 . V_93 = F_103 ( V_22 ) ;
return V_56 ;
}
static struct V_40 *
F_151 ( struct V_22 * V_22 , struct V_40 * V_57 )
{
struct V_40 * V_56 ;
struct V_21 * V_21 = & V_22 -> V_43 ;
if ( F_40 ( V_22 , V_57 ) ) {
F_62 ( V_22 ) ;
if ( F_88 ( ( V_22 -> V_113 && V_22 -> V_113 -> V_114 ) ||
V_22 -> V_115 . V_116 ) )
return V_117 ;
}
if ( V_57 -> V_90 == & V_91 )
F_102 ( V_22 ) ;
if ( ! V_21 -> V_69 )
return NULL ;
if ( F_97 ( V_21 ) )
return NULL ;
F_152 ( V_22 , V_57 ) ;
V_56 = F_150 ( V_22 ) ;
if ( V_56 )
F_60 ( V_22 , V_56 ) ;
F_55 ( V_22 ) ;
return V_56 ;
}
static void F_153 ( struct V_22 * V_22 , struct V_40 * V_56 )
{
F_102 ( V_22 ) ;
if ( F_63 ( & V_56 -> V_43 ) && V_56 -> V_64 > 1 )
F_56 ( V_22 , V_56 ) ;
}
static int F_154 ( struct V_22 * V_22 , struct V_40 * V_56 , int V_46 )
{
if ( ! F_155 ( V_22 , V_56 ) &&
F_156 ( V_46 , F_157 ( V_56 ) ) )
return 1 ;
return 0 ;
}
static struct V_40 * F_158 ( struct V_22 * V_22 , int V_46 )
{
struct V_118 * V_99 = & V_22 -> V_43 . V_37 ;
struct V_40 * V_56 ;
if ( ! F_53 ( V_22 ) )
return NULL ;
F_159 (p, head, pushable_tasks) {
if ( F_154 ( V_22 , V_56 , V_46 ) )
return V_56 ;
}
return NULL ;
}
static int F_142 ( struct V_40 * V_119 )
{
struct V_120 * V_121 ;
struct V_71 * V_122 = F_160 ( V_123 ) ;
int V_124 = F_161 () ;
int V_46 = F_162 ( V_119 ) ;
if ( F_88 ( ! V_122 ) )
return - 1 ;
if ( V_119 -> V_64 == 1 )
return - 1 ;
if ( ! F_145 ( & F_39 ( V_119 ) -> V_59 -> V_98 , V_119 , V_122 ) )
return - 1 ;
if ( F_156 ( V_46 , V_122 ) )
return V_46 ;
if ( ! F_156 ( V_124 , V_122 ) )
V_124 = - 1 ;
F_139 () ;
F_163 (cpu, sd) {
if ( V_121 -> V_103 & V_125 ) {
int V_126 ;
if ( V_124 != - 1 &&
F_156 ( V_124 , F_164 ( V_121 ) ) ) {
F_143 () ;
return V_124 ;
}
V_126 = F_165 ( V_122 ,
F_164 ( V_121 ) ) ;
if ( V_126 < V_51 ) {
F_143 () ;
return V_126 ;
}
}
}
F_143 () ;
if ( V_124 != - 1 )
return V_124 ;
V_46 = F_166 ( V_122 ) ;
if ( V_46 < V_51 )
return V_46 ;
return - 1 ;
}
static struct V_22 * F_167 ( struct V_40 * V_119 , struct V_22 * V_22 )
{
struct V_22 * V_127 = NULL ;
int V_128 ;
int V_46 ;
for ( V_128 = 0 ; V_128 < V_129 ; V_128 ++ ) {
V_46 = F_142 ( V_119 ) ;
if ( ( V_46 == - 1 ) || ( V_46 == V_22 -> V_46 ) )
break;
V_127 = F_33 ( V_46 ) ;
if ( F_168 ( V_22 , V_127 ) ) {
if ( F_88 ( F_39 ( V_119 ) != V_22 ||
! F_156 ( V_127 -> V_46 ,
F_157 ( V_119 ) ) ||
F_155 ( V_22 , V_119 ) ||
! V_119 -> V_114 ) ) {
F_169 ( V_22 , V_127 ) ;
V_127 = NULL ;
break;
}
}
if ( V_127 -> V_43 . V_32 . V_33 > V_119 -> V_58 )
break;
F_169 ( V_22 , V_127 ) ;
V_127 = NULL ;
}
return V_127 ;
}
static struct V_40 * F_170 ( struct V_22 * V_22 )
{
struct V_40 * V_56 ;
if ( ! F_53 ( V_22 ) )
return NULL ;
V_56 = F_61 ( & V_22 -> V_43 . V_37 ,
struct V_40 , V_37 ) ;
F_91 ( V_22 -> V_46 != F_162 ( V_56 ) ) ;
F_91 ( F_129 ( V_22 , V_56 ) ) ;
F_91 ( V_56 -> V_64 <= 1 ) ;
F_91 ( ! V_56 -> V_114 ) ;
F_91 ( ! F_141 ( V_56 ) ) ;
return V_56 ;
}
static int F_171 ( struct V_22 * V_22 )
{
struct V_40 * V_130 ;
struct V_22 * V_127 ;
int V_131 = 0 ;
if ( ! V_22 -> V_43 . V_36 )
return 0 ;
V_130 = F_170 ( V_22 ) ;
if ( ! V_130 )
return 0 ;
V_132:
if ( F_88 ( V_130 == V_22 -> V_33 ) ) {
F_115 ( 1 ) ;
return 0 ;
}
if ( F_88 ( V_130 -> V_58 < V_22 -> V_33 -> V_58 ) ) {
F_75 ( V_22 -> V_33 ) ;
return 0 ;
}
F_172 ( V_130 ) ;
V_127 = F_167 ( V_130 , V_22 ) ;
if ( ! V_127 ) {
struct V_40 * V_119 ;
V_119 = F_170 ( V_22 ) ;
if ( F_162 ( V_130 ) == V_22 -> V_46 && V_119 == V_130 ) {
goto V_108;
}
if ( ! V_119 )
goto V_108;
F_173 ( V_130 ) ;
V_130 = V_119 ;
goto V_132;
}
F_174 ( V_22 , V_130 , 0 ) ;
F_175 ( V_130 , V_127 -> V_46 ) ;
F_176 ( V_127 , V_130 , 0 ) ;
V_131 = 1 ;
F_75 ( V_127 -> V_33 ) ;
F_169 ( V_22 , V_127 ) ;
V_108:
F_173 ( V_130 ) ;
return V_131 ;
}
static void F_177 ( struct V_22 * V_22 )
{
while ( F_171 ( V_22 ) )
;
}
static int F_62 ( struct V_22 * V_66 )
{
int V_124 = V_66 -> V_46 , V_131 = 0 , V_46 ;
struct V_40 * V_56 ;
struct V_22 * V_133 ;
if ( F_100 ( ! F_41 ( V_66 ) ) )
return 0 ;
F_178 () ;
F_85 (cpu, this_rq->rd->rto_mask) {
if ( V_124 == V_46 )
continue;
V_133 = F_33 ( V_46 ) ;
if ( V_133 -> V_43 . V_32 . V_34 >=
V_66 -> V_43 . V_32 . V_33 )
continue;
F_168 ( V_66 , V_133 ) ;
V_56 = F_158 ( V_133 , V_124 ) ;
if ( V_56 && ( V_56 -> V_58 < V_66 -> V_43 . V_32 . V_33 ) ) {
F_115 ( V_56 == V_133 -> V_33 ) ;
F_115 ( ! V_56 -> V_114 ) ;
if ( V_56 -> V_58 < V_133 -> V_33 -> V_58 )
goto V_134;
V_131 = 1 ;
F_174 ( V_133 , V_56 , 0 ) ;
F_175 ( V_56 , V_124 ) ;
F_176 ( V_66 , V_56 , 0 ) ;
}
V_134:
F_169 ( V_66 , V_133 ) ;
}
return V_131 ;
}
static void F_179 ( struct V_22 * V_22 )
{
F_177 ( V_22 ) ;
}
static void F_180 ( struct V_22 * V_22 , struct V_40 * V_56 )
{
if ( ! F_155 ( V_22 , V_56 ) &&
! F_147 ( V_22 -> V_33 ) &&
F_53 ( V_22 ) &&
V_56 -> V_64 > 1 &&
( F_181 ( V_22 -> V_33 ) || F_141 ( V_22 -> V_33 ) ) &&
( V_22 -> V_33 -> V_64 < 2 ||
V_22 -> V_33 -> V_58 <= V_56 -> V_58 ) )
F_177 ( V_22 ) ;
}
static void F_182 ( struct V_40 * V_56 ,
const struct V_71 * V_135 )
{
struct V_22 * V_22 ;
int V_75 ;
F_91 ( ! F_141 ( V_56 ) ) ;
if ( ! V_56 -> V_114 )
return;
V_75 = F_84 ( V_135 ) ;
if ( ( V_56 -> V_64 > 1 ) == ( V_75 > 1 ) )
return;
V_22 = F_39 ( V_56 ) ;
if ( V_75 <= 1 ) {
if ( ! F_129 ( V_22 , V_56 ) )
F_60 ( V_22 , V_56 ) ;
F_91 ( ! V_22 -> V_43 . V_35 ) ;
V_22 -> V_43 . V_35 -- ;
} else {
if ( ! F_129 ( V_22 , V_56 ) )
F_56 ( V_22 , V_56 ) ;
V_22 -> V_43 . V_35 ++ ;
}
F_50 ( & V_22 -> V_43 ) ;
}
static void F_183 ( struct V_22 * V_22 )
{
if ( V_22 -> V_43 . V_36 )
F_43 ( V_22 ) ;
F_92 ( V_22 ) ;
F_111 ( & V_22 -> V_59 -> V_98 , V_22 -> V_46 , V_22 -> V_43 . V_32 . V_33 ) ;
}
static void F_184 ( struct V_22 * V_22 )
{
if ( V_22 -> V_43 . V_36 )
F_47 ( V_22 ) ;
F_87 ( V_22 ) ;
F_111 ( & V_22 -> V_59 -> V_98 , V_22 -> V_46 , V_136 ) ;
}
static void F_185 ( struct V_22 * V_22 , struct V_40 * V_56 )
{
if ( ! V_56 -> V_114 || V_22 -> V_43 . V_69 )
return;
if ( F_62 ( V_22 ) )
F_75 ( V_22 -> V_33 ) ;
}
void T_5 F_186 ( void )
{
unsigned int V_25 ;
F_30 (i) {
F_187 ( & F_188 ( V_123 , V_25 ) ,
V_52 , F_38 ( V_25 ) ) ;
}
}
static void F_189 ( struct V_22 * V_22 , struct V_40 * V_56 )
{
int V_137 = 1 ;
if ( V_56 -> V_114 && V_22 -> V_33 != V_56 ) {
#ifdef V_31
if ( V_22 -> V_43 . V_36 && F_171 ( V_22 ) &&
V_22 != F_39 ( V_56 ) )
V_137 = 0 ;
#endif
if ( V_137 && V_56 -> V_58 < V_22 -> V_33 -> V_58 )
F_75 ( V_22 -> V_33 ) ;
}
}
static void
F_190 ( struct V_22 * V_22 , struct V_40 * V_56 , int V_138 )
{
if ( ! V_56 -> V_114 )
return;
if ( V_22 -> V_33 == V_56 ) {
#ifdef V_31
if ( V_138 < V_56 -> V_58 )
F_62 ( V_22 ) ;
if ( V_56 -> V_58 > V_22 -> V_43 . V_32 . V_33 && V_22 -> V_33 == V_56 )
F_75 ( V_56 ) ;
#else
if ( V_138 < V_56 -> V_58 )
F_75 ( V_56 ) ;
#endif
} else {
if ( V_56 -> V_58 < V_22 -> V_33 -> V_58 )
F_75 ( V_22 -> V_33 ) ;
}
}
static void F_191 ( struct V_22 * V_22 , struct V_40 * V_56 )
{
unsigned long V_139 , V_140 ;
V_139 = F_192 ( V_56 , V_141 ) ;
V_140 = F_193 ( V_56 , V_141 ) ;
if ( V_139 != V_142 ) {
unsigned long V_34 ;
if ( V_56 -> V_43 . V_143 != V_144 ) {
V_56 -> V_43 . V_105 ++ ;
V_56 -> V_43 . V_143 = V_144 ;
}
V_34 = F_194 ( F_96 ( V_139 , V_140 ) , V_145 / V_146 ) ;
if ( V_56 -> V_43 . V_105 > V_34 )
V_56 -> V_147 . V_148 = V_56 -> V_92 . V_96 ;
}
}
static void F_195 ( struct V_22 * V_22 , struct V_40 * V_56 , int V_149 )
{
struct V_41 * V_42 = & V_56 -> V_43 ;
F_102 ( V_22 ) ;
F_191 ( V_22 , V_56 ) ;
if ( V_56 -> V_150 != V_151 )
return;
if ( -- V_56 -> V_43 . V_152 )
return;
V_56 -> V_43 . V_152 = V_153 ;
F_109 (rt_se) {
if ( V_42 -> V_50 . V_57 != V_42 -> V_50 . V_34 ) {
F_136 ( V_22 , V_56 , 0 ) ;
F_196 ( V_56 ) ;
return;
}
}
}
static void F_197 ( struct V_22 * V_22 )
{
struct V_40 * V_56 = V_22 -> V_33 ;
V_56 -> V_92 . V_93 = F_103 ( V_22 ) ;
F_60 ( V_22 , V_56 ) ;
}
static unsigned int F_198 ( struct V_22 * V_22 , struct V_40 * V_119 )
{
if ( V_119 -> V_150 == V_151 )
return V_153 ;
else
return 0 ;
}
void F_199 ( struct V_154 * V_155 , int V_46 )
{
T_4 V_77 ;
struct V_21 * V_21 ;
F_139 () ;
F_89 (rt_rq, iter, cpu_rq(cpu))
F_200 ( V_155 , V_46 , V_21 ) ;
F_143 () ;
}
