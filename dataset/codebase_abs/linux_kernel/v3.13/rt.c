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
static inline int F_40 ( struct V_22 * V_22 )
{
return F_41 ( & V_22 -> V_57 -> V_58 ) ;
}
static inline void F_42 ( struct V_22 * V_22 )
{
if ( ! V_22 -> V_59 )
return;
F_43 ( V_22 -> V_46 , V_22 -> V_57 -> V_60 ) ;
F_44 () ;
F_45 ( & V_22 -> V_57 -> V_58 ) ;
}
static inline void F_46 ( struct V_22 * V_22 )
{
if ( ! V_22 -> V_59 )
return;
F_47 ( & V_22 -> V_57 -> V_58 ) ;
F_48 ( V_22 -> V_46 , V_22 -> V_57 -> V_60 ) ;
}
static void F_49 ( struct V_21 * V_21 )
{
if ( V_21 -> V_35 && V_21 -> V_61 > 1 ) {
if ( ! V_21 -> V_36 ) {
F_42 ( F_27 ( V_21 ) ) ;
V_21 -> V_36 = 1 ;
}
} else if ( V_21 -> V_36 ) {
F_46 ( F_27 ( V_21 ) ) ;
V_21 -> V_36 = 0 ;
}
}
static void F_50 ( struct V_41 * V_42 , struct V_21 * V_21 )
{
struct V_40 * V_56 ;
if ( ! F_26 ( V_42 ) )
return;
V_56 = F_23 ( V_42 ) ;
V_21 = & F_27 ( V_21 ) -> V_43 ;
V_21 -> V_61 ++ ;
if ( V_56 -> V_62 > 1 )
V_21 -> V_35 ++ ;
F_49 ( V_21 ) ;
}
static void F_51 ( struct V_41 * V_42 , struct V_21 * V_21 )
{
struct V_40 * V_56 ;
if ( ! F_26 ( V_42 ) )
return;
V_56 = F_23 ( V_42 ) ;
V_21 = & F_27 ( V_21 ) -> V_43 ;
V_21 -> V_61 -- ;
if ( V_56 -> V_62 > 1 )
V_21 -> V_35 -- ;
F_49 ( V_21 ) ;
}
static inline int F_52 ( struct V_22 * V_22 )
{
return ! F_53 ( & V_22 -> V_43 . V_37 ) ;
}
static void F_54 ( struct V_22 * V_22 , struct V_40 * V_56 )
{
F_55 ( & V_56 -> V_37 , & V_22 -> V_43 . V_37 ) ;
F_56 ( & V_56 -> V_37 , V_56 -> V_63 ) ;
F_57 ( & V_56 -> V_37 , & V_22 -> V_43 . V_37 ) ;
if ( V_56 -> V_63 < V_22 -> V_43 . V_32 . V_34 )
V_22 -> V_43 . V_32 . V_34 = V_56 -> V_63 ;
}
static void F_58 ( struct V_22 * V_22 , struct V_40 * V_56 )
{
F_55 ( & V_56 -> V_37 , & V_22 -> V_43 . V_37 ) ;
if ( F_52 ( V_22 ) ) {
V_56 = F_59 ( & V_22 -> V_43 . V_37 ,
struct V_40 , V_37 ) ;
V_22 -> V_43 . V_32 . V_34 = V_56 -> V_63 ;
} else
V_22 -> V_43 . V_32 . V_34 = V_27 ;
}
static inline void F_54 ( struct V_22 * V_22 , struct V_40 * V_56 )
{
}
static inline void F_58 ( struct V_22 * V_22 , struct V_40 * V_56 )
{
}
static inline
void F_50 ( struct V_41 * V_42 , struct V_21 * V_21 )
{
}
static inline
void F_51 ( struct V_41 * V_42 , struct V_21 * V_21 )
{
}
static inline int F_60 ( struct V_41 * V_42 )
{
return ! F_61 ( & V_42 -> V_50 ) ;
}
static inline T_2 F_62 ( struct V_21 * V_21 )
{
if ( ! V_21 -> V_45 )
return V_20 ;
return V_21 -> V_15 ;
}
static inline T_2 F_63 ( struct V_21 * V_21 )
{
return F_36 ( V_21 -> V_45 -> V_4 . V_10 ) ;
}
static inline struct V_44 * F_64 ( struct V_44 * V_45 )
{
do {
V_45 = F_65 ( V_45 -> V_64 . V_34 ,
F_66 ( struct V_44 ) , V_64 ) ;
} while ( & V_45 -> V_64 != & V_65 && F_67 ( V_45 ) );
if ( & V_45 -> V_64 == & V_65 )
V_45 = NULL ;
return V_45 ;
}
static inline struct V_21 * F_68 ( struct V_41 * V_42 )
{
return V_42 -> V_49 ;
}
static void F_69 ( struct V_21 * V_21 )
{
struct V_40 * V_33 = F_27 ( V_21 ) -> V_33 ;
struct V_41 * V_42 ;
int V_46 = F_70 ( F_27 ( V_21 ) ) ;
V_42 = V_21 -> V_45 -> V_42 [ V_46 ] ;
if ( V_21 -> V_66 ) {
if ( V_42 && ! F_60 ( V_42 ) )
F_71 ( V_42 , false ) ;
if ( V_21 -> V_32 . V_33 < V_33 -> V_63 )
F_72 ( V_33 ) ;
}
}
static void F_73 ( struct V_21 * V_21 )
{
struct V_41 * V_42 ;
int V_46 = F_70 ( F_27 ( V_21 ) ) ;
V_42 = V_21 -> V_45 -> V_42 [ V_46 ] ;
if ( V_42 && F_60 ( V_42 ) )
F_74 ( V_42 ) ;
}
static inline int F_75 ( struct V_21 * V_21 )
{
return V_21 -> V_39 && ! V_21 -> V_48 ;
}
static int F_76 ( struct V_41 * V_42 )
{
struct V_21 * V_21 = F_68 ( V_42 ) ;
struct V_40 * V_56 ;
if ( V_21 )
return ! ! V_21 -> V_48 ;
V_56 = F_23 ( V_42 ) ;
return V_56 -> V_63 != V_56 -> V_67 ;
}
static inline const struct V_68 * F_77 ( void )
{
return F_78 () -> V_57 -> V_69 ;
}
static inline const struct V_68 * F_77 ( void )
{
return V_70 ;
}
static inline
struct V_21 * F_79 ( struct V_4 * V_5 , int V_46 )
{
return F_2 ( V_5 , struct V_44 , V_4 ) -> V_21 [ V_46 ] ;
}
static inline struct V_4 * F_80 ( struct V_21 * V_21 )
{
return & V_21 -> V_45 -> V_4 ;
}
static inline T_2 F_62 ( struct V_21 * V_21 )
{
return V_21 -> V_15 ;
}
static inline T_2 F_63 ( struct V_21 * V_21 )
{
return F_36 ( V_54 . V_10 ) ;
}
static inline struct V_21 * F_68 ( struct V_41 * V_42 )
{
return NULL ;
}
static inline void F_69 ( struct V_21 * V_21 )
{
if ( V_21 -> V_66 )
F_72 ( F_27 ( V_21 ) -> V_33 ) ;
}
static inline void F_73 ( struct V_21 * V_21 )
{
}
static inline int F_75 ( struct V_21 * V_21 )
{
return V_21 -> V_39 ;
}
static inline const struct V_68 * F_77 ( void )
{
return V_70 ;
}
static inline
struct V_21 * F_79 ( struct V_4 * V_5 , int V_46 )
{
return & F_33 ( V_46 ) -> V_43 ;
}
static inline struct V_4 * F_80 ( struct V_21 * V_21 )
{
return & V_54 ;
}
static int F_81 ( struct V_21 * V_21 )
{
struct V_4 * V_5 = F_80 ( V_21 ) ;
struct V_71 * V_57 = F_27 ( V_21 ) -> V_57 ;
int V_25 , V_72 , V_73 = 0 ;
T_2 V_10 ;
V_72 = F_82 ( V_57 -> V_69 ) ;
F_13 ( & V_5 -> V_16 ) ;
V_10 = F_36 ( V_5 -> V_10 ) ;
F_83 (i, rd->span) {
struct V_21 * V_74 = F_79 ( V_5 , V_25 ) ;
T_3 V_75 ;
if ( V_74 == V_21 )
continue;
F_13 ( & V_74 -> V_16 ) ;
if ( V_74 -> V_15 == V_20 )
goto V_34;
V_75 = V_74 -> V_15 - V_74 -> V_38 ;
if ( V_75 > 0 ) {
V_75 = F_84 ( ( T_2 ) V_75 , V_72 ) ;
if ( V_21 -> V_15 + V_75 > V_10 )
V_75 = V_10 - V_21 -> V_15 ;
V_74 -> V_15 -= V_75 ;
V_21 -> V_15 += V_75 ;
V_73 = 1 ;
if ( V_21 -> V_15 == V_10 ) {
F_15 ( & V_74 -> V_16 ) ;
break;
}
}
V_34:
F_15 ( & V_74 -> V_16 ) ;
}
F_15 ( & V_5 -> V_16 ) ;
return V_73 ;
}
static void F_85 ( struct V_22 * V_22 )
{
struct V_71 * V_57 = V_22 -> V_57 ;
T_4 V_74 ;
struct V_21 * V_21 ;
if ( F_86 ( ! V_76 ) )
return;
F_87 (rt_rq, iter, rq) {
struct V_4 * V_5 = F_80 ( V_21 ) ;
T_3 V_77 ;
int V_25 ;
F_13 ( & V_5 -> V_16 ) ;
F_13 ( & V_21 -> V_16 ) ;
if ( V_21 -> V_15 == V_20 ||
V_21 -> V_15 == V_5 -> V_15 )
goto V_78;
F_15 ( & V_21 -> V_16 ) ;
V_77 = V_5 -> V_15 - V_21 -> V_15 ;
F_83 (i, rd->span) {
struct V_21 * V_74 = F_79 ( V_5 , V_25 ) ;
T_3 V_75 ;
if ( V_74 == V_21 || V_74 -> V_15 == V_20 )
continue;
F_13 ( & V_74 -> V_16 ) ;
if ( V_77 > 0 ) {
V_75 = F_88 ( T_3 , V_74 -> V_15 , V_77 ) ;
V_74 -> V_15 -= V_75 ;
V_77 -= V_75 ;
} else {
V_74 -> V_15 -= V_77 ;
V_77 -= V_77 ;
}
F_15 ( & V_74 -> V_16 ) ;
if ( ! V_77 )
break;
}
F_13 ( & V_21 -> V_16 ) ;
F_89 ( V_77 ) ;
V_78:
V_21 -> V_15 = V_20 ;
V_21 -> V_39 = 0 ;
F_15 ( & V_21 -> V_16 ) ;
F_15 ( & V_5 -> V_16 ) ;
}
}
static void F_90 ( struct V_22 * V_22 )
{
T_4 V_74 ;
struct V_21 * V_21 ;
if ( F_86 ( ! V_76 ) )
return;
F_87 (rt_rq, iter, rq) {
struct V_4 * V_5 = F_80 ( V_21 ) ;
F_13 ( & V_5 -> V_16 ) ;
F_13 ( & V_21 -> V_16 ) ;
V_21 -> V_15 = V_5 -> V_15 ;
V_21 -> V_38 = 0 ;
V_21 -> V_39 = 0 ;
F_15 ( & V_21 -> V_16 ) ;
F_15 ( & V_5 -> V_16 ) ;
}
}
static int F_91 ( struct V_21 * V_21 )
{
int V_73 = 0 ;
if ( ! F_92 ( V_79 ) )
return V_73 ;
if ( V_21 -> V_38 > V_21 -> V_15 ) {
F_15 ( & V_21 -> V_16 ) ;
V_73 = F_81 ( V_21 ) ;
F_13 ( & V_21 -> V_16 ) ;
}
return V_73 ;
}
static inline int F_91 ( struct V_21 * V_21 )
{
return 0 ;
}
static int F_5 ( struct V_4 * V_5 , int V_8 )
{
int V_25 , V_9 = 1 , V_80 = 0 ;
const struct V_68 * V_69 ;
V_69 = F_77 () ;
#ifdef F_93
if ( V_5 == & V_81 . V_4 )
V_69 = V_70 ;
#endif
F_83 (i, span) {
int V_82 = 0 ;
struct V_21 * V_21 = F_79 ( V_5 , V_25 ) ;
struct V_22 * V_22 = F_27 ( V_21 ) ;
F_13 ( & V_22 -> V_83 ) ;
if ( V_21 -> V_38 ) {
T_2 V_14 ;
F_13 ( & V_21 -> V_16 ) ;
if ( V_21 -> V_39 )
F_91 ( V_21 ) ;
V_14 = V_21 -> V_15 ;
V_21 -> V_38 -= F_94 ( V_21 -> V_38 , V_8 * V_14 ) ;
if ( V_21 -> V_39 && V_21 -> V_38 < V_14 ) {
V_21 -> V_39 = 0 ;
V_82 = 1 ;
if ( V_21 -> V_66 && V_22 -> V_33 == V_22 -> V_9 )
V_22 -> V_84 = - 1 ;
}
if ( V_21 -> V_38 || V_21 -> V_66 )
V_9 = 0 ;
F_15 ( & V_21 -> V_16 ) ;
} else if ( V_21 -> V_66 ) {
V_9 = 0 ;
if ( ! F_75 ( V_21 ) )
V_82 = 1 ;
}
if ( V_21 -> V_39 )
V_80 = 1 ;
if ( V_82 )
F_69 ( V_21 ) ;
F_15 ( & V_22 -> V_83 ) ;
}
if ( ! V_80 && ( ! F_11 () || V_5 -> V_15 == V_20 ) )
return 1 ;
return V_9 ;
}
static inline int F_95 ( struct V_41 * V_42 )
{
#ifdef F_93
struct V_21 * V_21 = F_68 ( V_42 ) ;
if ( V_21 )
return V_21 -> V_32 . V_33 ;
#endif
return F_23 ( V_42 ) -> V_63 ;
}
static int F_96 ( struct V_21 * V_21 )
{
T_2 V_14 = F_62 ( V_21 ) ;
if ( V_21 -> V_39 )
return F_75 ( V_21 ) ;
if ( V_14 >= F_63 ( V_21 ) )
return 0 ;
F_91 ( V_21 ) ;
V_14 = F_62 ( V_21 ) ;
if ( V_14 == V_20 )
return 0 ;
if ( V_21 -> V_38 > V_14 ) {
struct V_4 * V_5 = F_80 ( V_21 ) ;
if ( F_97 ( V_5 -> V_15 ) ) {
static bool V_85 = false ;
V_21 -> V_39 = 1 ;
if ( ! V_85 ) {
V_85 = true ;
F_98 ( L_1 ) ;
}
} else {
V_21 -> V_38 = 0 ;
}
if ( F_75 ( V_21 ) ) {
F_73 ( V_21 ) ;
return 1 ;
}
}
return 0 ;
}
static void F_99 ( struct V_22 * V_22 )
{
struct V_40 * V_33 = V_22 -> V_33 ;
struct V_41 * V_42 = & V_33 -> V_43 ;
struct V_21 * V_21 = F_28 ( V_42 ) ;
T_2 V_86 ;
if ( V_33 -> V_87 != & V_88 )
return;
V_86 = F_100 ( V_22 ) - V_33 -> V_89 . V_90 ;
if ( F_86 ( ( T_3 ) V_86 <= 0 ) )
return;
F_101 ( V_33 -> V_89 . V_91 . V_92 ,
F_102 ( V_33 -> V_89 . V_91 . V_92 , V_86 ) ) ;
V_33 -> V_89 . V_93 += V_86 ;
F_103 ( V_33 , V_86 ) ;
V_33 -> V_89 . V_90 = F_100 ( V_22 ) ;
F_104 ( V_33 , V_86 ) ;
F_105 ( V_22 , V_86 ) ;
if ( ! F_11 () )
return;
F_106 (rt_se) {
V_21 = F_28 ( V_42 ) ;
if ( F_62 ( V_21 ) != V_20 ) {
F_13 ( & V_21 -> V_16 ) ;
V_21 -> V_38 += V_86 ;
if ( F_96 ( V_21 ) )
F_72 ( V_33 ) ;
F_15 ( & V_21 -> V_16 ) ;
}
}
}
static void
F_107 ( struct V_21 * V_21 , int V_63 , int V_94 )
{
struct V_22 * V_22 = F_27 ( V_21 ) ;
#ifdef F_93
if ( & V_22 -> V_43 != V_21 )
return;
#endif
if ( V_22 -> V_59 && V_63 < V_94 )
F_108 ( & V_22 -> V_57 -> V_95 , V_22 -> V_46 , V_63 ) ;
}
static void
F_109 ( struct V_21 * V_21 , int V_63 , int V_94 )
{
struct V_22 * V_22 = F_27 ( V_21 ) ;
#ifdef F_93
if ( & V_22 -> V_43 != V_21 )
return;
#endif
if ( V_22 -> V_59 && V_21 -> V_32 . V_33 != V_94 )
F_108 ( & V_22 -> V_57 -> V_95 , V_22 -> V_46 , V_21 -> V_32 . V_33 ) ;
}
static inline
void F_107 ( struct V_21 * V_21 , int V_63 , int V_94 ) {}
static inline
void F_109 ( struct V_21 * V_21 , int V_63 , int V_94 ) {}
static void
F_110 ( struct V_21 * V_21 , int V_63 )
{
int V_94 = V_21 -> V_32 . V_33 ;
if ( V_63 < V_94 )
V_21 -> V_32 . V_33 = V_63 ;
F_107 ( V_21 , V_63 , V_94 ) ;
}
static void
F_111 ( struct V_21 * V_21 , int V_63 )
{
int V_94 = V_21 -> V_32 . V_33 ;
if ( V_21 -> V_66 ) {
F_112 ( V_63 < V_94 ) ;
if ( V_63 == V_94 ) {
struct V_23 * V_24 = & V_21 -> V_26 ;
V_21 -> V_32 . V_33 =
F_113 ( V_24 -> V_29 ) ;
}
} else
V_21 -> V_32 . V_33 = V_27 ;
F_109 ( V_21 , V_63 , V_94 ) ;
}
static inline void F_110 ( struct V_21 * V_21 , int V_63 ) {}
static inline void F_111 ( struct V_21 * V_21 , int V_63 ) {}
static void
F_114 ( struct V_41 * V_42 , struct V_21 * V_21 )
{
if ( F_76 ( V_42 ) )
V_21 -> V_48 ++ ;
if ( V_21 -> V_45 )
F_10 ( & V_21 -> V_45 -> V_4 ) ;
}
static void
F_115 ( struct V_41 * V_42 , struct V_21 * V_21 )
{
if ( F_76 ( V_42 ) )
V_21 -> V_48 -- ;
F_112 ( ! V_21 -> V_66 && V_21 -> V_48 ) ;
}
static void
F_114 ( struct V_41 * V_42 , struct V_21 * V_21 )
{
F_10 ( & V_54 ) ;
}
static inline
void F_115 ( struct V_41 * V_42 , struct V_21 * V_21 ) {}
static inline
void F_116 ( struct V_41 * V_42 , struct V_21 * V_21 )
{
int V_63 = F_95 ( V_42 ) ;
F_112 ( ! F_117 ( V_63 ) ) ;
V_21 -> V_66 ++ ;
F_110 ( V_21 , V_63 ) ;
F_50 ( V_42 , V_21 ) ;
F_114 ( V_42 , V_21 ) ;
}
static inline
void F_118 ( struct V_41 * V_42 , struct V_21 * V_21 )
{
F_112 ( ! F_117 ( F_95 ( V_42 ) ) ) ;
F_112 ( ! V_21 -> V_66 ) ;
V_21 -> V_66 -- ;
F_111 ( V_21 , F_95 ( V_42 ) ) ;
F_51 ( V_42 , V_21 ) ;
F_115 ( V_42 , V_21 ) ;
}
static void F_119 ( struct V_41 * V_42 , bool V_96 )
{
struct V_21 * V_21 = F_28 ( V_42 ) ;
struct V_23 * V_24 = & V_21 -> V_26 ;
struct V_21 * V_97 = F_68 ( V_42 ) ;
struct V_98 * V_28 = V_24 -> V_28 + F_95 ( V_42 ) ;
if ( V_97 && ( F_75 ( V_97 ) || ! V_97 -> V_66 ) )
return;
if ( V_96 )
F_120 ( & V_42 -> V_50 , V_28 ) ;
else
F_121 ( & V_42 -> V_50 , V_28 ) ;
F_19 ( F_95 ( V_42 ) , V_24 -> V_29 ) ;
F_116 ( V_42 , V_21 ) ;
}
static void F_122 ( struct V_41 * V_42 )
{
struct V_21 * V_21 = F_28 ( V_42 ) ;
struct V_23 * V_24 = & V_21 -> V_26 ;
F_123 ( & V_42 -> V_50 ) ;
if ( F_61 ( V_24 -> V_28 + F_95 ( V_42 ) ) )
F_18 ( F_95 ( V_42 ) , V_24 -> V_29 ) ;
F_118 ( V_42 , V_21 ) ;
}
static void F_124 ( struct V_41 * V_42 )
{
struct V_41 * V_99 = NULL ;
F_106 (rt_se) {
V_42 -> V_99 = V_99 ;
V_99 = V_42 ;
}
for ( V_42 = V_99 ; V_42 ; V_42 = V_42 -> V_99 ) {
if ( F_60 ( V_42 ) )
F_122 ( V_42 ) ;
}
}
static void F_71 ( struct V_41 * V_42 , bool V_96 )
{
F_124 ( V_42 ) ;
F_106 (rt_se)
F_119 ( V_42 , V_96 ) ;
}
static void F_74 ( struct V_41 * V_42 )
{
F_124 ( V_42 ) ;
F_106 (rt_se) {
struct V_21 * V_21 = F_68 ( V_42 ) ;
if ( V_21 && V_21 -> V_66 )
F_119 ( V_42 , false ) ;
}
}
static void
F_125 ( struct V_22 * V_22 , struct V_40 * V_56 , int V_100 )
{
struct V_41 * V_42 = & V_56 -> V_43 ;
if ( V_100 & V_101 )
V_42 -> V_102 = 0 ;
F_71 ( V_42 , V_100 & V_103 ) ;
if ( ! F_126 ( V_22 , V_56 ) && V_56 -> V_62 > 1 )
F_54 ( V_22 , V_56 ) ;
F_127 ( V_22 ) ;
}
static void F_128 ( struct V_22 * V_22 , struct V_40 * V_56 , int V_100 )
{
struct V_41 * V_42 = & V_56 -> V_43 ;
F_99 ( V_22 ) ;
F_74 ( V_42 ) ;
F_58 ( V_22 , V_56 ) ;
F_129 ( V_22 ) ;
}
static void
F_130 ( struct V_21 * V_21 , struct V_41 * V_42 , int V_96 )
{
if ( F_60 ( V_42 ) ) {
struct V_23 * V_24 = & V_21 -> V_26 ;
struct V_98 * V_28 = V_24 -> V_28 + F_95 ( V_42 ) ;
if ( V_96 )
F_131 ( & V_42 -> V_50 , V_28 ) ;
else
F_132 ( & V_42 -> V_50 , V_28 ) ;
}
}
static void F_133 ( struct V_22 * V_22 , struct V_40 * V_56 , int V_96 )
{
struct V_41 * V_42 = & V_56 -> V_43 ;
struct V_21 * V_21 ;
F_106 (rt_se) {
V_21 = F_28 ( V_42 ) ;
F_130 ( V_21 , V_42 , V_96 ) ;
}
}
static void F_134 ( struct V_22 * V_22 )
{
F_133 ( V_22 , V_22 -> V_33 , 0 ) ;
}
static int
F_135 ( struct V_40 * V_56 , int V_46 , int V_104 , int V_100 )
{
struct V_40 * V_33 ;
struct V_22 * V_22 ;
if ( V_56 -> V_62 == 1 )
goto V_105;
if ( V_104 != V_106 && V_104 != V_107 )
goto V_105;
V_22 = F_33 ( V_46 ) ;
F_136 () ;
V_33 = F_137 ( V_22 -> V_33 ) ;
if ( V_33 && F_86 ( F_138 ( V_33 ) ) &&
( V_33 -> V_62 < 2 ||
V_33 -> V_63 <= V_56 -> V_63 ) ) {
int V_108 = F_139 ( V_56 ) ;
if ( V_108 != - 1 )
V_46 = V_108 ;
}
F_140 () ;
V_105:
return V_46 ;
}
static void F_141 ( struct V_22 * V_22 , struct V_40 * V_56 )
{
if ( V_22 -> V_33 -> V_62 == 1 )
return;
if ( V_56 -> V_62 != 1
&& F_142 ( & V_22 -> V_57 -> V_95 , V_56 , NULL ) )
return;
if ( ! F_142 ( & V_22 -> V_57 -> V_95 , V_22 -> V_33 , NULL ) )
return;
F_133 ( V_22 , V_56 , 1 ) ;
F_72 ( V_22 -> V_33 ) ;
}
static void F_143 ( struct V_22 * V_22 , struct V_40 * V_56 , int V_100 )
{
if ( V_56 -> V_63 < V_22 -> V_33 -> V_63 ) {
F_72 ( V_22 -> V_33 ) ;
return;
}
#ifdef V_31
if ( V_56 -> V_63 == V_22 -> V_33 -> V_63 && ! F_144 ( V_22 -> V_33 ) )
F_141 ( V_22 , V_56 ) ;
#endif
}
static struct V_41 * F_145 ( struct V_22 * V_22 ,
struct V_21 * V_21 )
{
struct V_23 * V_24 = & V_21 -> V_26 ;
struct V_41 * V_34 = NULL ;
struct V_98 * V_28 ;
int V_109 ;
V_109 = F_113 ( V_24 -> V_29 ) ;
F_89 ( V_109 >= V_27 ) ;
V_28 = V_24 -> V_28 + V_109 ;
V_34 = F_146 ( V_28 -> V_34 , struct V_41 , V_50 ) ;
return V_34 ;
}
static struct V_40 * F_147 ( struct V_22 * V_22 )
{
struct V_41 * V_42 ;
struct V_40 * V_56 ;
struct V_21 * V_21 ;
V_21 = & V_22 -> V_43 ;
if ( ! V_21 -> V_66 )
return NULL ;
if ( F_75 ( V_21 ) )
return NULL ;
do {
V_42 = F_145 ( V_22 , V_21 ) ;
F_89 ( ! V_42 ) ;
V_21 = F_68 ( V_42 ) ;
} while ( V_21 );
V_56 = F_23 ( V_42 ) ;
V_56 -> V_89 . V_90 = F_100 ( V_22 ) ;
return V_56 ;
}
static struct V_40 * F_148 ( struct V_22 * V_22 )
{
struct V_40 * V_56 = F_147 ( V_22 ) ;
if ( V_56 )
F_58 ( V_22 , V_56 ) ;
#ifdef V_31
V_22 -> V_110 = F_52 ( V_22 ) ;
#endif
return V_56 ;
}
static void F_149 ( struct V_22 * V_22 , struct V_40 * V_56 )
{
F_99 ( V_22 ) ;
if ( F_60 ( & V_56 -> V_43 ) && V_56 -> V_62 > 1 )
F_54 ( V_22 , V_56 ) ;
}
static int F_150 ( struct V_22 * V_22 , struct V_40 * V_56 , int V_46 )
{
if ( ! F_151 ( V_22 , V_56 ) &&
F_152 ( V_46 , F_153 ( V_56 ) ) )
return 1 ;
return 0 ;
}
static struct V_40 * F_154 ( struct V_22 * V_22 , int V_46 )
{
struct V_111 * V_96 = & V_22 -> V_43 . V_37 ;
struct V_40 * V_56 ;
if ( ! F_52 ( V_22 ) )
return NULL ;
F_155 (p, head, pushable_tasks) {
if ( F_150 ( V_22 , V_56 , V_46 ) )
return V_56 ;
}
return NULL ;
}
static int F_139 ( struct V_40 * V_112 )
{
struct V_113 * V_114 ;
struct V_68 * V_115 = F_156 ( V_116 ) ;
int V_117 = F_157 () ;
int V_46 = F_158 ( V_112 ) ;
if ( F_86 ( ! V_115 ) )
return - 1 ;
if ( V_112 -> V_62 == 1 )
return - 1 ;
if ( ! F_142 ( & F_39 ( V_112 ) -> V_57 -> V_95 , V_112 , V_115 ) )
return - 1 ;
if ( F_152 ( V_46 , V_115 ) )
return V_46 ;
if ( ! F_152 ( V_117 , V_115 ) )
V_117 = - 1 ;
F_136 () ;
F_159 (cpu, sd) {
if ( V_114 -> V_100 & V_118 ) {
int V_119 ;
if ( V_117 != - 1 &&
F_152 ( V_117 , F_160 ( V_114 ) ) ) {
F_140 () ;
return V_117 ;
}
V_119 = F_161 ( V_115 ,
F_160 ( V_114 ) ) ;
if ( V_119 < V_51 ) {
F_140 () ;
return V_119 ;
}
}
}
F_140 () ;
if ( V_117 != - 1 )
return V_117 ;
V_46 = F_162 ( V_115 ) ;
if ( V_46 < V_51 )
return V_46 ;
return - 1 ;
}
static struct V_22 * F_163 ( struct V_40 * V_112 , struct V_22 * V_22 )
{
struct V_22 * V_120 = NULL ;
int V_121 ;
int V_46 ;
for ( V_121 = 0 ; V_121 < V_122 ; V_121 ++ ) {
V_46 = F_139 ( V_112 ) ;
if ( ( V_46 == - 1 ) || ( V_46 == V_22 -> V_46 ) )
break;
V_120 = F_33 ( V_46 ) ;
if ( F_164 ( V_22 , V_120 ) ) {
if ( F_86 ( F_39 ( V_112 ) != V_22 ||
! F_152 ( V_120 -> V_46 ,
F_153 ( V_112 ) ) ||
F_151 ( V_22 , V_112 ) ||
! V_112 -> V_123 ) ) {
F_165 ( V_22 , V_120 ) ;
V_120 = NULL ;
break;
}
}
if ( V_120 -> V_43 . V_32 . V_33 > V_112 -> V_63 )
break;
F_165 ( V_22 , V_120 ) ;
V_120 = NULL ;
}
return V_120 ;
}
static struct V_40 * F_166 ( struct V_22 * V_22 )
{
struct V_40 * V_56 ;
if ( ! F_52 ( V_22 ) )
return NULL ;
V_56 = F_59 ( & V_22 -> V_43 . V_37 ,
struct V_40 , V_37 ) ;
F_89 ( V_22 -> V_46 != F_158 ( V_56 ) ) ;
F_89 ( F_126 ( V_22 , V_56 ) ) ;
F_89 ( V_56 -> V_62 <= 1 ) ;
F_89 ( ! V_56 -> V_123 ) ;
F_89 ( ! F_138 ( V_56 ) ) ;
return V_56 ;
}
static int F_167 ( struct V_22 * V_22 )
{
struct V_40 * V_124 ;
struct V_22 * V_120 ;
int V_125 = 0 ;
if ( ! V_22 -> V_43 . V_36 )
return 0 ;
V_124 = F_166 ( V_22 ) ;
if ( ! V_124 )
return 0 ;
V_126:
if ( F_86 ( V_124 == V_22 -> V_33 ) ) {
F_112 ( 1 ) ;
return 0 ;
}
if ( F_86 ( V_124 -> V_63 < V_22 -> V_33 -> V_63 ) ) {
F_72 ( V_22 -> V_33 ) ;
return 0 ;
}
F_168 ( V_124 ) ;
V_120 = F_163 ( V_124 , V_22 ) ;
if ( ! V_120 ) {
struct V_40 * V_112 ;
V_112 = F_166 ( V_22 ) ;
if ( F_158 ( V_124 ) == V_22 -> V_46 && V_112 == V_124 ) {
goto V_105;
}
if ( ! V_112 )
goto V_105;
F_169 ( V_124 ) ;
V_124 = V_112 ;
goto V_126;
}
F_170 ( V_22 , V_124 , 0 ) ;
F_171 ( V_124 , V_120 -> V_46 ) ;
F_172 ( V_120 , V_124 , 0 ) ;
V_125 = 1 ;
F_72 ( V_120 -> V_33 ) ;
F_165 ( V_22 , V_120 ) ;
V_105:
F_169 ( V_124 ) ;
return V_125 ;
}
static void F_173 ( struct V_22 * V_22 )
{
while ( F_167 ( V_22 ) )
;
}
static int F_174 ( struct V_22 * F_78 )
{
int V_117 = F_78 -> V_46 , V_125 = 0 , V_46 ;
struct V_40 * V_56 ;
struct V_22 * V_127 ;
if ( F_97 ( ! F_40 ( F_78 ) ) )
return 0 ;
F_175 () ;
F_83 (cpu, this_rq->rd->rto_mask) {
if ( V_117 == V_46 )
continue;
V_127 = F_33 ( V_46 ) ;
if ( V_127 -> V_43 . V_32 . V_34 >=
F_78 -> V_43 . V_32 . V_33 )
continue;
F_164 ( F_78 , V_127 ) ;
V_56 = F_154 ( V_127 , V_117 ) ;
if ( V_56 && ( V_56 -> V_63 < F_78 -> V_43 . V_32 . V_33 ) ) {
F_112 ( V_56 == V_127 -> V_33 ) ;
F_112 ( ! V_56 -> V_123 ) ;
if ( V_56 -> V_63 < V_127 -> V_33 -> V_63 )
goto V_128;
V_125 = 1 ;
F_170 ( V_127 , V_56 , 0 ) ;
F_171 ( V_56 , V_117 ) ;
F_172 ( F_78 , V_56 , 0 ) ;
}
V_128:
F_165 ( F_78 , V_127 ) ;
}
return V_125 ;
}
static void F_176 ( struct V_22 * V_22 , struct V_40 * V_129 )
{
if ( V_22 -> V_43 . V_32 . V_33 > V_129 -> V_63 )
F_174 ( V_22 ) ;
}
static void F_177 ( struct V_22 * V_22 )
{
F_173 ( V_22 ) ;
}
static void F_178 ( struct V_22 * V_22 , struct V_40 * V_56 )
{
if ( ! F_151 ( V_22 , V_56 ) &&
! F_144 ( V_22 -> V_33 ) &&
F_52 ( V_22 ) &&
V_56 -> V_62 > 1 &&
F_138 ( V_22 -> V_33 ) &&
( V_22 -> V_33 -> V_62 < 2 ||
V_22 -> V_33 -> V_63 <= V_56 -> V_63 ) )
F_173 ( V_22 ) ;
}
static void F_179 ( struct V_40 * V_56 ,
const struct V_68 * V_130 )
{
struct V_22 * V_22 ;
int V_72 ;
F_89 ( ! F_138 ( V_56 ) ) ;
if ( ! V_56 -> V_123 )
return;
V_72 = F_82 ( V_130 ) ;
if ( ( V_56 -> V_62 > 1 ) == ( V_72 > 1 ) )
return;
V_22 = F_39 ( V_56 ) ;
if ( V_72 <= 1 ) {
if ( ! F_126 ( V_22 , V_56 ) )
F_58 ( V_22 , V_56 ) ;
F_89 ( ! V_22 -> V_43 . V_35 ) ;
V_22 -> V_43 . V_35 -- ;
} else {
if ( ! F_126 ( V_22 , V_56 ) )
F_54 ( V_22 , V_56 ) ;
V_22 -> V_43 . V_35 ++ ;
}
F_49 ( & V_22 -> V_43 ) ;
}
static void F_180 ( struct V_22 * V_22 )
{
if ( V_22 -> V_43 . V_36 )
F_42 ( V_22 ) ;
F_90 ( V_22 ) ;
F_108 ( & V_22 -> V_57 -> V_95 , V_22 -> V_46 , V_22 -> V_43 . V_32 . V_33 ) ;
}
static void F_181 ( struct V_22 * V_22 )
{
if ( V_22 -> V_43 . V_36 )
F_46 ( V_22 ) ;
F_85 ( V_22 ) ;
F_108 ( & V_22 -> V_57 -> V_95 , V_22 -> V_46 , V_131 ) ;
}
static void F_182 ( struct V_22 * V_22 , struct V_40 * V_56 )
{
if ( ! V_56 -> V_123 || V_22 -> V_43 . V_66 )
return;
if ( F_174 ( V_22 ) )
F_72 ( V_22 -> V_33 ) ;
}
void F_183 ( void )
{
unsigned int V_25 ;
F_30 (i) {
F_184 ( & F_185 ( V_116 , V_25 ) ,
V_52 , F_38 ( V_25 ) ) ;
}
}
static void F_186 ( struct V_22 * V_22 , struct V_40 * V_56 )
{
int V_132 = 1 ;
if ( V_56 -> V_123 && V_22 -> V_33 != V_56 ) {
#ifdef V_31
if ( V_22 -> V_43 . V_36 && F_167 ( V_22 ) &&
V_22 != F_39 ( V_56 ) )
V_132 = 0 ;
#endif
if ( V_132 && V_56 -> V_63 < V_22 -> V_33 -> V_63 )
F_72 ( V_22 -> V_33 ) ;
}
}
static void
F_187 ( struct V_22 * V_22 , struct V_40 * V_56 , int V_133 )
{
if ( ! V_56 -> V_123 )
return;
if ( V_22 -> V_33 == V_56 ) {
#ifdef V_31
if ( V_133 < V_56 -> V_63 )
F_174 ( V_22 ) ;
if ( V_56 -> V_63 > V_22 -> V_43 . V_32 . V_33 && V_22 -> V_33 == V_56 )
F_72 ( V_56 ) ;
#else
if ( V_133 < V_56 -> V_63 )
F_72 ( V_56 ) ;
#endif
} else {
if ( V_56 -> V_63 < V_22 -> V_33 -> V_63 )
F_72 ( V_22 -> V_33 ) ;
}
}
static void F_188 ( struct V_22 * V_22 , struct V_40 * V_56 )
{
unsigned long V_134 , V_135 ;
V_134 = F_189 ( V_56 , V_136 ) ;
V_135 = F_190 ( V_56 , V_136 ) ;
if ( V_134 != V_137 ) {
unsigned long V_34 ;
if ( V_56 -> V_43 . V_138 != V_139 ) {
V_56 -> V_43 . V_102 ++ ;
V_56 -> V_43 . V_138 = V_139 ;
}
V_34 = F_191 ( F_94 ( V_134 , V_135 ) , V_140 / V_141 ) ;
if ( V_56 -> V_43 . V_102 > V_34 )
V_56 -> V_142 . V_143 = V_56 -> V_89 . V_93 ;
}
}
static void F_192 ( struct V_22 * V_22 , struct V_40 * V_56 , int V_144 )
{
struct V_41 * V_42 = & V_56 -> V_43 ;
F_99 ( V_22 ) ;
F_188 ( V_22 , V_56 ) ;
if ( V_56 -> V_145 != V_146 )
return;
if ( -- V_56 -> V_43 . V_147 )
return;
V_56 -> V_43 . V_147 = V_148 ;
F_106 (rt_se) {
if ( V_42 -> V_50 . V_129 != V_42 -> V_50 . V_34 ) {
F_133 ( V_22 , V_56 , 0 ) ;
F_193 ( V_56 ) ;
return;
}
}
}
static void F_194 ( struct V_22 * V_22 )
{
struct V_40 * V_56 = V_22 -> V_33 ;
V_56 -> V_89 . V_90 = F_100 ( V_22 ) ;
F_58 ( V_22 , V_56 ) ;
}
static unsigned int F_195 ( struct V_22 * V_22 , struct V_40 * V_112 )
{
if ( V_112 -> V_145 == V_146 )
return V_148 ;
else
return 0 ;
}
void F_196 ( struct V_149 * V_150 , int V_46 )
{
T_4 V_74 ;
struct V_21 * V_21 ;
F_136 () ;
F_87 (rt_rq, iter, cpu_rq(cpu))
F_197 ( V_150 , V_46 , V_21 ) ;
F_140 () ;
}
