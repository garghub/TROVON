static enum V_1 F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 =
F_2 ( V_3 , struct V_4 , V_6 ) ;
int V_7 = 0 ;
int V_8 ;
F_3 ( & V_5 -> V_9 ) ;
for (; ; ) {
V_8 = F_4 ( V_3 , V_5 -> V_10 ) ;
if ( ! V_8 )
break;
F_5 ( & V_5 -> V_9 ) ;
V_7 = F_6 ( V_5 , V_8 ) ;
F_3 ( & V_5 -> V_9 ) ;
}
if ( V_7 )
V_5 -> V_11 = 0 ;
F_5 ( & V_5 -> V_9 ) ;
return V_7 ? V_12 : V_13 ;
}
void F_7 ( struct V_4 * V_5 , T_1 V_14 , T_1 V_15 )
{
V_5 -> V_10 = F_8 ( V_14 ) ;
V_5 -> V_16 = V_15 ;
F_9 ( & V_5 -> V_9 ) ;
F_10 ( & V_5 -> V_6 ,
V_17 , V_18 ) ;
V_5 -> V_6 . V_19 = F_1 ;
}
static void F_11 ( struct V_4 * V_5 )
{
if ( ! F_12 () || V_5 -> V_16 == V_20 )
return;
F_3 ( & V_5 -> V_9 ) ;
if ( ! V_5 -> V_11 ) {
V_5 -> V_11 = 1 ;
F_4 ( & V_5 -> V_6 , F_8 ( 0 ) ) ;
F_13 ( & V_5 -> V_6 , V_21 ) ;
}
F_5 ( & V_5 -> V_9 ) ;
}
void F_14 ( struct V_22 * V_22 )
{
struct V_23 * V_24 ;
int V_25 ;
V_24 = & V_22 -> V_26 ;
for ( V_25 = 0 ; V_25 < V_27 ; V_25 ++ ) {
F_15 ( V_24 -> V_28 + V_25 ) ;
F_16 ( V_25 , V_24 -> V_29 ) ;
}
F_17 ( V_27 , V_24 -> V_29 ) ;
#if V_30 V_31
V_22 -> V_32 . V_33 = V_27 ;
V_22 -> V_32 . V_34 = V_27 ;
V_22 -> V_35 = 0 ;
V_22 -> V_36 = 0 ;
F_18 ( & V_22 -> V_37 ) ;
#ifdef F_19
V_22 -> V_38 = 0 ;
V_22 -> V_39 = V_40 ;
F_9 ( & V_22 -> V_41 ) ;
F_20 ( & V_22 -> V_42 , V_43 ) ;
#endif
#endif
V_22 -> V_44 = 0 ;
V_22 -> V_45 = 0 ;
V_22 -> V_46 = 0 ;
V_22 -> V_16 = 0 ;
F_9 ( & V_22 -> V_9 ) ;
}
static void F_21 ( struct V_4 * V_5 )
{
F_22 ( & V_5 -> V_6 ) ;
}
static inline struct V_47 * F_23 ( struct V_48 * V_49 )
{
#ifdef F_24
F_25 ( ! F_26 ( V_49 ) ) ;
#endif
return F_2 ( V_49 , struct V_47 , V_50 ) ;
}
static inline struct V_51 * F_27 ( struct V_22 * V_22 )
{
return V_22 -> V_51 ;
}
static inline struct V_22 * F_28 ( struct V_48 * V_49 )
{
return V_49 -> V_22 ;
}
static inline struct V_51 * F_29 ( struct V_48 * V_49 )
{
struct V_22 * V_22 = V_49 -> V_22 ;
return V_22 -> V_51 ;
}
void F_30 ( struct V_52 * V_53 )
{
int V_25 ;
if ( V_53 -> V_49 )
F_21 ( & V_53 -> V_4 ) ;
F_31 (i) {
if ( V_53 -> V_22 )
F_32 ( V_53 -> V_22 [ V_25 ] ) ;
if ( V_53 -> V_49 )
F_32 ( V_53 -> V_49 [ V_25 ] ) ;
}
F_32 ( V_53 -> V_22 ) ;
F_32 ( V_53 -> V_49 ) ;
}
void F_33 ( struct V_52 * V_53 , struct V_22 * V_22 ,
struct V_48 * V_49 , int V_54 ,
struct V_48 * V_55 )
{
struct V_51 * V_51 = F_34 ( V_54 ) ;
V_22 -> V_32 . V_33 = V_27 ;
V_22 -> V_56 = 0 ;
V_22 -> V_51 = V_51 ;
V_22 -> V_53 = V_53 ;
V_53 -> V_22 [ V_54 ] = V_22 ;
V_53 -> V_49 [ V_54 ] = V_49 ;
if ( ! V_49 )
return;
if ( ! V_55 )
V_49 -> V_22 = & V_51 -> V_50 ;
else
V_49 -> V_22 = V_55 -> V_57 ;
V_49 -> V_57 = V_22 ;
V_49 -> V_55 = V_55 ;
F_15 ( & V_49 -> V_58 ) ;
}
int F_35 ( struct V_52 * V_53 , struct V_52 * V_55 )
{
struct V_22 * V_22 ;
struct V_48 * V_49 ;
int V_25 ;
V_53 -> V_22 = F_36 ( sizeof( V_22 ) * V_40 , V_59 ) ;
if ( ! V_53 -> V_22 )
goto V_60;
V_53 -> V_49 = F_36 ( sizeof( V_49 ) * V_40 , V_59 ) ;
if ( ! V_53 -> V_49 )
goto V_60;
F_7 ( & V_53 -> V_4 ,
F_37 ( V_61 . V_10 ) , 0 ) ;
F_31 (i) {
V_22 = F_38 ( sizeof( struct V_22 ) ,
V_59 , F_39 ( V_25 ) ) ;
if ( ! V_22 )
goto V_60;
V_49 = F_38 ( sizeof( struct V_48 ) ,
V_59 , F_39 ( V_25 ) ) ;
if ( ! V_49 )
goto V_62;
F_14 ( V_22 ) ;
V_22 -> V_16 = V_53 -> V_4 . V_16 ;
F_33 ( V_53 , V_22 , V_49 , V_25 , V_55 -> V_49 [ V_25 ] ) ;
}
return 1 ;
V_62:
F_32 ( V_22 ) ;
V_60:
return 0 ;
}
static inline struct V_47 * F_23 ( struct V_48 * V_49 )
{
return F_2 ( V_49 , struct V_47 , V_50 ) ;
}
static inline struct V_51 * F_27 ( struct V_22 * V_22 )
{
return F_2 ( V_22 , struct V_51 , V_50 ) ;
}
static inline struct V_51 * F_29 ( struct V_48 * V_49 )
{
struct V_47 * V_63 = F_23 ( V_49 ) ;
return F_40 ( V_63 ) ;
}
static inline struct V_22 * F_28 ( struct V_48 * V_49 )
{
struct V_51 * V_51 = F_29 ( V_49 ) ;
return & V_51 -> V_50 ;
}
void F_30 ( struct V_52 * V_53 ) { }
int F_35 ( struct V_52 * V_53 , struct V_52 * V_55 )
{
return 1 ;
}
static inline bool F_41 ( struct V_51 * V_51 , struct V_47 * V_64 )
{
return V_51 -> V_50 . V_32 . V_33 > V_64 -> V_65 ;
}
static inline int F_42 ( struct V_51 * V_51 )
{
return F_43 ( & V_51 -> V_66 -> V_67 ) ;
}
static inline void F_44 ( struct V_51 * V_51 )
{
if ( ! V_51 -> V_68 )
return;
F_45 ( V_51 -> V_54 , V_51 -> V_66 -> V_69 ) ;
F_46 () ;
F_47 ( & V_51 -> V_66 -> V_67 ) ;
}
static inline void F_48 ( struct V_51 * V_51 )
{
if ( ! V_51 -> V_68 )
return;
F_49 ( & V_51 -> V_66 -> V_67 ) ;
F_50 ( V_51 -> V_54 , V_51 -> V_66 -> V_69 ) ;
}
static void F_51 ( struct V_22 * V_22 )
{
if ( V_22 -> V_35 && V_22 -> V_70 > 1 ) {
if ( ! V_22 -> V_36 ) {
F_44 ( F_27 ( V_22 ) ) ;
V_22 -> V_36 = 1 ;
}
} else if ( V_22 -> V_36 ) {
F_48 ( F_27 ( V_22 ) ) ;
V_22 -> V_36 = 0 ;
}
}
static void F_52 ( struct V_48 * V_49 , struct V_22 * V_22 )
{
struct V_47 * V_63 ;
if ( ! F_26 ( V_49 ) )
return;
V_63 = F_23 ( V_49 ) ;
V_22 = & F_27 ( V_22 ) -> V_50 ;
V_22 -> V_70 ++ ;
if ( F_53 ( V_63 ) > 1 )
V_22 -> V_35 ++ ;
F_51 ( V_22 ) ;
}
static void F_54 ( struct V_48 * V_49 , struct V_22 * V_22 )
{
struct V_47 * V_63 ;
if ( ! F_26 ( V_49 ) )
return;
V_63 = F_23 ( V_49 ) ;
V_22 = & F_27 ( V_22 ) -> V_50 ;
V_22 -> V_70 -- ;
if ( F_53 ( V_63 ) > 1 )
V_22 -> V_35 -- ;
F_51 ( V_22 ) ;
}
static inline int F_55 ( struct V_51 * V_51 )
{
return ! F_56 ( & V_51 -> V_50 . V_37 ) ;
}
static inline void F_57 ( struct V_51 * V_51 )
{
if ( ! F_55 ( V_51 ) )
return;
F_58 ( V_51 , & F_59 ( V_71 , V_51 -> V_54 ) , V_72 ) ;
}
static inline void F_60 ( struct V_51 * V_51 )
{
F_58 ( V_51 , & F_59 ( V_73 , V_51 -> V_54 ) , V_74 ) ;
}
static void F_61 ( struct V_51 * V_51 , struct V_47 * V_63 )
{
F_62 ( & V_63 -> V_37 , & V_51 -> V_50 . V_37 ) ;
F_63 ( & V_63 -> V_37 , V_63 -> V_65 ) ;
F_64 ( & V_63 -> V_37 , & V_51 -> V_50 . V_37 ) ;
if ( V_63 -> V_65 < V_51 -> V_50 . V_32 . V_34 )
V_51 -> V_50 . V_32 . V_34 = V_63 -> V_65 ;
}
static void F_65 ( struct V_51 * V_51 , struct V_47 * V_63 )
{
F_62 ( & V_63 -> V_37 , & V_51 -> V_50 . V_37 ) ;
if ( F_55 ( V_51 ) ) {
V_63 = F_66 ( & V_51 -> V_50 . V_37 ,
struct V_47 , V_37 ) ;
V_51 -> V_50 . V_32 . V_34 = V_63 -> V_65 ;
} else
V_51 -> V_50 . V_32 . V_34 = V_27 ;
}
static inline void F_61 ( struct V_51 * V_51 , struct V_47 * V_63 )
{
}
static inline void F_65 ( struct V_51 * V_51 , struct V_47 * V_63 )
{
}
static inline
void F_52 ( struct V_48 * V_49 , struct V_22 * V_22 )
{
}
static inline
void F_54 ( struct V_48 * V_49 , struct V_22 * V_22 )
{
}
static inline bool F_41 ( struct V_51 * V_51 , struct V_47 * V_64 )
{
return false ;
}
static inline void V_74 ( struct V_51 * V_75 )
{
}
static inline void F_57 ( struct V_51 * V_51 )
{
}
static inline int F_67 ( struct V_48 * V_49 )
{
return V_49 -> V_76 ;
}
static inline T_1 F_68 ( struct V_22 * V_22 )
{
if ( ! V_22 -> V_53 )
return V_20 ;
return V_22 -> V_16 ;
}
static inline T_1 F_69 ( struct V_22 * V_22 )
{
return F_37 ( V_22 -> V_53 -> V_4 . V_10 ) ;
}
static inline struct V_52 * F_70 ( struct V_52 * V_53 )
{
do {
V_53 = F_71 ( V_53 -> V_77 . V_34 ,
F_72 ( struct V_52 ) , V_77 ) ;
} while ( & V_53 -> V_77 != & V_78 && F_73 ( V_53 ) );
if ( & V_53 -> V_77 == & V_78 )
V_53 = NULL ;
return V_53 ;
}
static inline struct V_22 * F_74 ( struct V_48 * V_49 )
{
return V_49 -> V_57 ;
}
static void F_75 ( struct V_22 * V_22 )
{
struct V_47 * V_33 = F_27 ( V_22 ) -> V_33 ;
struct V_51 * V_51 = F_27 ( V_22 ) ;
struct V_48 * V_49 ;
int V_54 = F_76 ( V_51 ) ;
V_49 = V_22 -> V_53 -> V_49 [ V_54 ] ;
if ( V_22 -> V_79 ) {
if ( ! V_49 )
F_77 ( V_22 ) ;
else if ( ! F_67 ( V_49 ) )
F_78 ( V_49 , 0 ) ;
if ( V_22 -> V_32 . V_33 < V_33 -> V_65 )
F_79 ( V_51 ) ;
}
}
static void F_80 ( struct V_22 * V_22 )
{
struct V_48 * V_49 ;
int V_54 = F_76 ( F_27 ( V_22 ) ) ;
V_49 = V_22 -> V_53 -> V_49 [ V_54 ] ;
if ( ! V_49 )
F_81 ( V_22 ) ;
else if ( F_67 ( V_49 ) )
F_82 ( V_49 , 0 ) ;
}
static inline int F_83 ( struct V_22 * V_22 )
{
return V_22 -> V_46 && ! V_22 -> V_56 ;
}
static int F_84 ( struct V_48 * V_49 )
{
struct V_22 * V_22 = F_74 ( V_49 ) ;
struct V_47 * V_63 ;
if ( V_22 )
return ! ! V_22 -> V_56 ;
V_63 = F_23 ( V_49 ) ;
return V_63 -> V_65 != V_63 -> V_80 ;
}
static inline const struct V_81 * F_85 ( void )
{
return V_75 () -> V_66 -> V_82 ;
}
static inline const struct V_81 * F_85 ( void )
{
return V_83 ;
}
static inline
struct V_22 * F_86 ( struct V_4 * V_5 , int V_54 )
{
return F_2 ( V_5 , struct V_52 , V_4 ) -> V_22 [ V_54 ] ;
}
static inline struct V_4 * F_87 ( struct V_22 * V_22 )
{
return & V_22 -> V_53 -> V_4 ;
}
static inline T_1 F_68 ( struct V_22 * V_22 )
{
return V_22 -> V_16 ;
}
static inline T_1 F_69 ( struct V_22 * V_22 )
{
return F_37 ( V_61 . V_10 ) ;
}
static inline struct V_22 * F_74 ( struct V_48 * V_49 )
{
return NULL ;
}
static inline void F_75 ( struct V_22 * V_22 )
{
struct V_51 * V_51 = F_27 ( V_22 ) ;
if ( ! V_22 -> V_79 )
return;
F_77 ( V_22 ) ;
F_79 ( V_51 ) ;
}
static inline void F_80 ( struct V_22 * V_22 )
{
F_81 ( V_22 ) ;
}
static inline int F_83 ( struct V_22 * V_22 )
{
return V_22 -> V_46 ;
}
static inline const struct V_81 * F_85 ( void )
{
return V_83 ;
}
static inline
struct V_22 * F_86 ( struct V_4 * V_5 , int V_54 )
{
return & F_34 ( V_54 ) -> V_50 ;
}
static inline struct V_4 * F_87 ( struct V_22 * V_22 )
{
return & V_61 ;
}
bool F_88 ( struct V_22 * V_22 )
{
struct V_4 * V_5 = F_87 ( V_22 ) ;
return ( F_89 ( & V_5 -> V_6 ) ||
V_22 -> V_45 < V_5 -> V_16 ) ;
}
static void F_90 ( struct V_22 * V_22 )
{
struct V_4 * V_5 = F_87 ( V_22 ) ;
struct V_84 * V_66 = F_27 ( V_22 ) -> V_66 ;
int V_25 , V_85 ;
T_1 V_10 ;
V_85 = F_91 ( V_66 -> V_82 ) ;
F_3 ( & V_5 -> V_9 ) ;
V_10 = F_37 ( V_5 -> V_10 ) ;
F_92 (i, rd->span) {
struct V_22 * V_86 = F_86 ( V_5 , V_25 ) ;
T_2 V_87 ;
if ( V_86 == V_22 )
continue;
F_3 ( & V_86 -> V_9 ) ;
if ( V_86 -> V_16 == V_20 )
goto V_34;
V_87 = V_86 -> V_16 - V_86 -> V_45 ;
if ( V_87 > 0 ) {
V_87 = F_93 ( ( T_1 ) V_87 , V_85 ) ;
if ( V_22 -> V_16 + V_87 > V_10 )
V_87 = V_10 - V_22 -> V_16 ;
V_86 -> V_16 -= V_87 ;
V_22 -> V_16 += V_87 ;
if ( V_22 -> V_16 == V_10 ) {
F_5 ( & V_86 -> V_9 ) ;
break;
}
}
V_34:
F_5 ( & V_86 -> V_9 ) ;
}
F_5 ( & V_5 -> V_9 ) ;
}
static void F_94 ( struct V_51 * V_51 )
{
struct V_84 * V_66 = V_51 -> V_66 ;
T_3 V_86 ;
struct V_22 * V_22 ;
if ( F_95 ( ! V_88 ) )
return;
F_96 (rt_rq, iter, rq) {
struct V_4 * V_5 = F_87 ( V_22 ) ;
T_2 V_89 ;
int V_25 ;
F_3 ( & V_5 -> V_9 ) ;
F_3 ( & V_22 -> V_9 ) ;
if ( V_22 -> V_16 == V_20 ||
V_22 -> V_16 == V_5 -> V_16 )
goto V_90;
F_5 ( & V_22 -> V_9 ) ;
V_89 = V_5 -> V_16 - V_22 -> V_16 ;
F_92 (i, rd->span) {
struct V_22 * V_86 = F_86 ( V_5 , V_25 ) ;
T_2 V_87 ;
if ( V_86 == V_22 || V_86 -> V_16 == V_20 )
continue;
F_3 ( & V_86 -> V_9 ) ;
if ( V_89 > 0 ) {
V_87 = F_97 ( T_2 , V_86 -> V_16 , V_89 ) ;
V_86 -> V_16 -= V_87 ;
V_89 -= V_87 ;
} else {
V_86 -> V_16 -= V_89 ;
V_89 -= V_89 ;
}
F_5 ( & V_86 -> V_9 ) ;
if ( ! V_89 )
break;
}
F_3 ( & V_22 -> V_9 ) ;
F_98 ( V_89 ) ;
V_90:
V_22 -> V_16 = V_20 ;
V_22 -> V_46 = 0 ;
F_5 ( & V_22 -> V_9 ) ;
F_5 ( & V_5 -> V_9 ) ;
F_75 ( V_22 ) ;
}
}
static void F_99 ( struct V_51 * V_51 )
{
T_3 V_86 ;
struct V_22 * V_22 ;
if ( F_95 ( ! V_88 ) )
return;
F_96 (rt_rq, iter, rq) {
struct V_4 * V_5 = F_87 ( V_22 ) ;
F_3 ( & V_5 -> V_9 ) ;
F_3 ( & V_22 -> V_9 ) ;
V_22 -> V_16 = V_5 -> V_16 ;
V_22 -> V_45 = 0 ;
V_22 -> V_46 = 0 ;
F_5 ( & V_22 -> V_9 ) ;
F_5 ( & V_5 -> V_9 ) ;
}
}
static void F_100 ( struct V_22 * V_22 )
{
if ( ! F_101 ( V_91 ) )
return;
if ( V_22 -> V_45 > V_22 -> V_16 ) {
F_5 ( & V_22 -> V_9 ) ;
F_90 ( V_22 ) ;
F_3 ( & V_22 -> V_9 ) ;
}
}
static inline void F_100 ( struct V_22 * V_22 ) {}
static int F_6 ( struct V_4 * V_5 , int V_8 )
{
int V_25 , V_7 = 1 , V_92 = 0 ;
const struct V_81 * V_82 ;
V_82 = F_85 () ;
#ifdef F_102
if ( V_5 == & V_93 . V_4 )
V_82 = V_83 ;
#endif
F_92 (i, span) {
int V_94 = 0 ;
struct V_22 * V_22 = F_86 ( V_5 , V_25 ) ;
struct V_51 * V_51 = F_27 ( V_22 ) ;
F_3 ( & V_51 -> V_95 ) ;
if ( V_22 -> V_45 ) {
T_1 V_15 ;
F_3 ( & V_22 -> V_9 ) ;
if ( V_22 -> V_46 )
F_100 ( V_22 ) ;
V_15 = V_22 -> V_16 ;
V_22 -> V_45 -= F_103 ( V_22 -> V_45 , V_8 * V_15 ) ;
if ( V_22 -> V_46 && V_22 -> V_45 < V_15 ) {
V_22 -> V_46 = 0 ;
V_94 = 1 ;
if ( V_22 -> V_79 && V_51 -> V_33 == V_51 -> V_7 )
F_104 ( V_51 , false ) ;
}
if ( V_22 -> V_45 || V_22 -> V_79 )
V_7 = 0 ;
F_5 ( & V_22 -> V_9 ) ;
} else if ( V_22 -> V_79 ) {
V_7 = 0 ;
if ( ! F_83 ( V_22 ) )
V_94 = 1 ;
}
if ( V_22 -> V_46 )
V_92 = 1 ;
if ( V_94 )
F_75 ( V_22 ) ;
F_5 ( & V_51 -> V_95 ) ;
}
if ( ! V_92 && ( ! F_12 () || V_5 -> V_16 == V_20 ) )
return 1 ;
return V_7 ;
}
static inline int F_105 ( struct V_48 * V_49 )
{
#ifdef F_102
struct V_22 * V_22 = F_74 ( V_49 ) ;
if ( V_22 )
return V_22 -> V_32 . V_33 ;
#endif
return F_23 ( V_49 ) -> V_65 ;
}
static int F_106 ( struct V_22 * V_22 )
{
T_1 V_15 = F_68 ( V_22 ) ;
if ( V_22 -> V_46 )
return F_83 ( V_22 ) ;
if ( V_15 >= F_69 ( V_22 ) )
return 0 ;
F_100 ( V_22 ) ;
V_15 = F_68 ( V_22 ) ;
if ( V_15 == V_20 )
return 0 ;
if ( V_22 -> V_45 > V_15 ) {
struct V_4 * V_5 = F_87 ( V_22 ) ;
if ( F_107 ( V_5 -> V_16 ) ) {
V_22 -> V_46 = 1 ;
F_108 ( L_1 ) ;
} else {
V_22 -> V_45 = 0 ;
}
if ( F_83 ( V_22 ) ) {
F_80 ( V_22 ) ;
return 1 ;
}
}
return 0 ;
}
static void F_109 ( struct V_51 * V_51 )
{
struct V_47 * V_33 = V_51 -> V_33 ;
struct V_48 * V_49 = & V_33 -> V_50 ;
T_1 V_96 ;
if ( V_33 -> V_97 != & V_98 )
return;
V_96 = F_110 ( V_51 ) - V_33 -> V_99 . V_100 ;
if ( F_95 ( ( T_2 ) V_96 <= 0 ) )
return;
F_111 ( V_51 , V_101 ) ;
F_112 ( V_33 -> V_99 . V_102 . V_103 ,
F_113 ( V_33 -> V_99 . V_102 . V_103 , V_96 ) ) ;
V_33 -> V_99 . V_104 += V_96 ;
F_114 ( V_33 , V_96 ) ;
V_33 -> V_99 . V_100 = F_110 ( V_51 ) ;
F_115 ( V_33 , V_96 ) ;
F_116 ( V_51 , V_96 ) ;
if ( ! F_12 () )
return;
F_117 (rt_se) {
struct V_22 * V_22 = F_28 ( V_49 ) ;
if ( F_68 ( V_22 ) != V_20 ) {
F_3 ( & V_22 -> V_9 ) ;
V_22 -> V_45 += V_96 ;
if ( F_106 ( V_22 ) )
F_79 ( V_51 ) ;
F_5 ( & V_22 -> V_9 ) ;
}
}
}
static void
F_81 ( struct V_22 * V_22 )
{
struct V_51 * V_51 = F_27 ( V_22 ) ;
F_98 ( & V_51 -> V_50 != V_22 ) ;
if ( ! V_22 -> V_44 )
return;
F_98 ( ! V_51 -> V_105 ) ;
F_118 ( V_51 , V_22 -> V_79 ) ;
V_22 -> V_44 = 0 ;
}
static void
F_77 ( struct V_22 * V_22 )
{
struct V_51 * V_51 = F_27 ( V_22 ) ;
F_98 ( & V_51 -> V_50 != V_22 ) ;
if ( V_22 -> V_44 )
return;
if ( F_83 ( V_22 ) || ! V_22 -> V_79 )
return;
F_119 ( V_51 , V_22 -> V_79 ) ;
V_22 -> V_44 = 1 ;
}
static void
F_120 ( struct V_22 * V_22 , int V_65 , int V_106 )
{
struct V_51 * V_51 = F_27 ( V_22 ) ;
#ifdef F_102
if ( & V_51 -> V_50 != V_22 )
return;
#endif
if ( V_51 -> V_68 && V_65 < V_106 )
F_121 ( & V_51 -> V_66 -> V_107 , V_51 -> V_54 , V_65 ) ;
}
static void
F_122 ( struct V_22 * V_22 , int V_65 , int V_106 )
{
struct V_51 * V_51 = F_27 ( V_22 ) ;
#ifdef F_102
if ( & V_51 -> V_50 != V_22 )
return;
#endif
if ( V_51 -> V_68 && V_22 -> V_32 . V_33 != V_106 )
F_121 ( & V_51 -> V_66 -> V_107 , V_51 -> V_54 , V_22 -> V_32 . V_33 ) ;
}
static inline
void F_120 ( struct V_22 * V_22 , int V_65 , int V_106 ) {}
static inline
void F_122 ( struct V_22 * V_22 , int V_65 , int V_106 ) {}
static void
F_123 ( struct V_22 * V_22 , int V_65 )
{
int V_106 = V_22 -> V_32 . V_33 ;
if ( V_65 < V_106 )
V_22 -> V_32 . V_33 = V_65 ;
F_120 ( V_22 , V_65 , V_106 ) ;
}
static void
F_124 ( struct V_22 * V_22 , int V_65 )
{
int V_106 = V_22 -> V_32 . V_33 ;
if ( V_22 -> V_79 ) {
F_125 ( V_65 < V_106 ) ;
if ( V_65 == V_106 ) {
struct V_23 * V_24 = & V_22 -> V_26 ;
V_22 -> V_32 . V_33 =
F_126 ( V_24 -> V_29 ) ;
}
} else
V_22 -> V_32 . V_33 = V_27 ;
F_122 ( V_22 , V_65 , V_106 ) ;
}
static inline void F_123 ( struct V_22 * V_22 , int V_65 ) {}
static inline void F_124 ( struct V_22 * V_22 , int V_65 ) {}
static void
F_127 ( struct V_48 * V_49 , struct V_22 * V_22 )
{
if ( F_84 ( V_49 ) )
V_22 -> V_56 ++ ;
if ( V_22 -> V_53 )
F_11 ( & V_22 -> V_53 -> V_4 ) ;
}
static void
F_128 ( struct V_48 * V_49 , struct V_22 * V_22 )
{
if ( F_84 ( V_49 ) )
V_22 -> V_56 -- ;
F_125 ( ! V_22 -> V_79 && V_22 -> V_56 ) ;
}
static void
F_127 ( struct V_48 * V_49 , struct V_22 * V_22 )
{
F_11 ( & V_61 ) ;
}
static inline
void F_128 ( struct V_48 * V_49 , struct V_22 * V_22 ) {}
static inline
unsigned int F_129 ( struct V_48 * V_49 )
{
struct V_22 * V_108 = F_74 ( V_49 ) ;
if ( V_108 )
return V_108 -> V_79 ;
else
return 1 ;
}
static inline
unsigned int F_130 ( struct V_48 * V_49 )
{
struct V_22 * V_108 = F_74 ( V_49 ) ;
struct V_47 * V_109 ;
if ( V_108 )
return V_108 -> V_110 ;
V_109 = F_23 ( V_49 ) ;
return ( V_109 -> V_111 == V_112 ) ? 1 : 0 ;
}
static inline
void F_131 ( struct V_48 * V_49 , struct V_22 * V_22 )
{
int V_65 = F_105 ( V_49 ) ;
F_125 ( ! F_132 ( V_65 ) ) ;
V_22 -> V_79 += F_129 ( V_49 ) ;
V_22 -> V_110 += F_130 ( V_49 ) ;
F_123 ( V_22 , V_65 ) ;
F_52 ( V_49 , V_22 ) ;
F_127 ( V_49 , V_22 ) ;
}
static inline
void F_133 ( struct V_48 * V_49 , struct V_22 * V_22 )
{
F_125 ( ! F_132 ( F_105 ( V_49 ) ) ) ;
F_125 ( ! V_22 -> V_79 ) ;
V_22 -> V_79 -= F_129 ( V_49 ) ;
V_22 -> V_110 -= F_130 ( V_49 ) ;
F_124 ( V_22 , F_105 ( V_49 ) ) ;
F_54 ( V_49 , V_22 ) ;
F_128 ( V_49 , V_22 ) ;
}
static inline bool F_134 ( unsigned int V_113 )
{
if ( ( V_113 & ( V_114 | V_115 ) ) == V_114 )
return false ;
return true ;
}
static void F_135 ( struct V_48 * V_49 , struct V_23 * V_24 )
{
F_136 ( & V_49 -> V_58 ) ;
if ( F_137 ( V_24 -> V_28 + F_105 ( V_49 ) ) )
F_16 ( F_105 ( V_49 ) , V_24 -> V_29 ) ;
V_49 -> V_116 = 0 ;
}
static void F_138 ( struct V_48 * V_49 , unsigned int V_113 )
{
struct V_22 * V_22 = F_28 ( V_49 ) ;
struct V_23 * V_24 = & V_22 -> V_26 ;
struct V_22 * V_108 = F_74 ( V_49 ) ;
struct V_117 * V_28 = V_24 -> V_28 + F_105 ( V_49 ) ;
if ( V_108 && ( F_83 ( V_108 ) || ! V_108 -> V_79 ) ) {
if ( V_49 -> V_116 )
F_135 ( V_49 , V_24 ) ;
return;
}
if ( F_134 ( V_113 ) ) {
F_25 ( V_49 -> V_116 ) ;
if ( V_113 & V_118 )
F_139 ( & V_49 -> V_58 , V_28 ) ;
else
F_140 ( & V_49 -> V_58 , V_28 ) ;
F_17 ( F_105 ( V_49 ) , V_24 -> V_29 ) ;
V_49 -> V_116 = 1 ;
}
V_49 -> V_76 = 1 ;
F_131 ( V_49 , V_22 ) ;
}
static void F_141 ( struct V_48 * V_49 , unsigned int V_113 )
{
struct V_22 * V_22 = F_28 ( V_49 ) ;
struct V_23 * V_24 = & V_22 -> V_26 ;
if ( F_134 ( V_113 ) ) {
F_25 ( ! V_49 -> V_116 ) ;
F_135 ( V_49 , V_24 ) ;
}
V_49 -> V_76 = 0 ;
F_133 ( V_49 , V_22 ) ;
}
static void F_142 ( struct V_48 * V_49 , unsigned int V_113 )
{
struct V_48 * V_119 = NULL ;
F_117 (rt_se) {
V_49 -> V_119 = V_119 ;
V_119 = V_49 ;
}
F_81 ( F_28 ( V_119 ) ) ;
for ( V_49 = V_119 ; V_49 ; V_49 = V_49 -> V_119 ) {
if ( F_67 ( V_49 ) )
F_141 ( V_49 , V_113 ) ;
}
}
static void F_78 ( struct V_48 * V_49 , unsigned int V_113 )
{
struct V_51 * V_51 = F_29 ( V_49 ) ;
F_142 ( V_49 , V_113 ) ;
F_117 (rt_se)
F_138 ( V_49 , V_113 ) ;
F_77 ( & V_51 -> V_50 ) ;
}
static void F_82 ( struct V_48 * V_49 , unsigned int V_113 )
{
struct V_51 * V_51 = F_29 ( V_49 ) ;
F_142 ( V_49 , V_113 ) ;
F_117 (rt_se) {
struct V_22 * V_22 = F_74 ( V_49 ) ;
if ( V_22 && V_22 -> V_79 )
F_138 ( V_49 , V_113 ) ;
}
F_77 ( & V_51 -> V_50 ) ;
}
static void
F_143 ( struct V_51 * V_51 , struct V_47 * V_63 , int V_113 )
{
struct V_48 * V_49 = & V_63 -> V_50 ;
if ( V_113 & V_120 )
V_49 -> V_121 = 0 ;
F_78 ( V_49 , V_113 ) ;
if ( ! F_144 ( V_51 , V_63 ) && F_53 ( V_63 ) > 1 )
F_61 ( V_51 , V_63 ) ;
}
static void F_145 ( struct V_51 * V_51 , struct V_47 * V_63 , int V_113 )
{
struct V_48 * V_49 = & V_63 -> V_50 ;
F_109 ( V_51 ) ;
F_82 ( V_49 , V_113 ) ;
F_65 ( V_51 , V_63 ) ;
}
static void
F_146 ( struct V_22 * V_22 , struct V_48 * V_49 , int V_122 )
{
if ( F_67 ( V_49 ) ) {
struct V_23 * V_24 = & V_22 -> V_26 ;
struct V_117 * V_28 = V_24 -> V_28 + F_105 ( V_49 ) ;
if ( V_122 )
F_147 ( & V_49 -> V_58 , V_28 ) ;
else
F_148 ( & V_49 -> V_58 , V_28 ) ;
}
}
static void F_149 ( struct V_51 * V_51 , struct V_47 * V_63 , int V_122 )
{
struct V_48 * V_49 = & V_63 -> V_50 ;
struct V_22 * V_22 ;
F_117 (rt_se) {
V_22 = F_28 ( V_49 ) ;
F_146 ( V_22 , V_49 , V_122 ) ;
}
}
static void F_150 ( struct V_51 * V_51 )
{
F_149 ( V_51 , V_51 -> V_33 , 0 ) ;
}
static int
F_151 ( struct V_47 * V_63 , int V_54 , int V_123 , int V_113 )
{
struct V_47 * V_33 ;
struct V_51 * V_51 ;
if ( V_123 != V_124 && V_123 != V_125 )
goto V_126;
V_51 = F_34 ( V_54 ) ;
F_152 () ;
V_33 = F_153 ( V_51 -> V_33 ) ;
if ( V_33 && F_95 ( F_154 ( V_33 ) ) &&
( F_53 ( V_33 ) < 2 ||
V_33 -> V_65 <= V_63 -> V_65 ) ) {
int V_127 = F_155 ( V_63 ) ;
if ( V_127 != - 1 &&
V_63 -> V_65 < F_34 ( V_127 ) -> V_50 . V_32 . V_33 )
V_54 = V_127 ;
}
F_156 () ;
V_126:
return V_54 ;
}
static void F_157 ( struct V_51 * V_51 , struct V_47 * V_63 )
{
if ( F_53 ( V_51 -> V_33 ) == 1 ||
! F_158 ( & V_51 -> V_66 -> V_107 , V_51 -> V_33 , NULL ) )
return;
if ( F_53 ( V_63 ) != 1
&& F_158 ( & V_51 -> V_66 -> V_107 , V_63 , NULL ) )
return;
F_149 ( V_51 , V_63 , 1 ) ;
F_79 ( V_51 ) ;
}
static void F_159 ( struct V_51 * V_51 , struct V_47 * V_63 , int V_113 )
{
if ( V_63 -> V_65 < V_51 -> V_33 -> V_65 ) {
F_79 ( V_51 ) ;
return;
}
#ifdef V_31
if ( V_63 -> V_65 == V_51 -> V_33 -> V_65 && ! F_160 ( V_51 -> V_33 ) )
F_157 ( V_51 , V_63 ) ;
#endif
}
static struct V_48 * F_161 ( struct V_51 * V_51 ,
struct V_22 * V_22 )
{
struct V_23 * V_24 = & V_22 -> V_26 ;
struct V_48 * V_34 = NULL ;
struct V_117 * V_28 ;
int V_128 ;
V_128 = F_126 ( V_24 -> V_29 ) ;
F_98 ( V_128 >= V_27 ) ;
V_28 = V_24 -> V_28 + V_128 ;
V_34 = F_162 ( V_28 -> V_34 , struct V_48 , V_58 ) ;
return V_34 ;
}
static struct V_47 * F_163 ( struct V_51 * V_51 )
{
struct V_48 * V_49 ;
struct V_47 * V_63 ;
struct V_22 * V_22 = & V_51 -> V_50 ;
do {
V_49 = F_161 ( V_51 , V_22 ) ;
F_98 ( ! V_49 ) ;
V_22 = F_74 ( V_49 ) ;
} while ( V_22 );
V_63 = F_23 ( V_49 ) ;
V_63 -> V_99 . V_100 = F_110 ( V_51 ) ;
return V_63 ;
}
static struct V_47 *
F_164 ( struct V_51 * V_51 , struct V_47 * V_64 , struct V_129 V_130 )
{
struct V_47 * V_63 ;
struct V_22 * V_22 = & V_51 -> V_50 ;
if ( F_41 ( V_51 , V_64 ) ) {
F_165 ( & V_51 -> V_95 , V_130 ) ;
V_74 ( V_51 ) ;
F_166 ( & V_51 -> V_95 , V_130 ) ;
if ( F_95 ( ( V_51 -> V_131 && F_167 ( V_51 -> V_131 ) ) ||
V_51 -> V_132 . V_133 ) )
return V_134 ;
}
if ( V_64 -> V_97 == & V_98 )
F_109 ( V_51 ) ;
if ( ! V_22 -> V_44 )
return NULL ;
F_168 ( V_51 , V_64 ) ;
V_63 = F_163 ( V_51 ) ;
F_65 ( V_51 , V_63 ) ;
F_57 ( V_51 ) ;
return V_63 ;
}
static void F_169 ( struct V_51 * V_51 , struct V_47 * V_63 )
{
F_109 ( V_51 ) ;
if ( F_67 ( & V_63 -> V_50 ) && F_53 ( V_63 ) > 1 )
F_61 ( V_51 , V_63 ) ;
}
static int F_170 ( struct V_51 * V_51 , struct V_47 * V_63 , int V_54 )
{
if ( ! F_171 ( V_51 , V_63 ) &&
F_172 ( V_54 , F_173 ( V_63 ) ) )
return 1 ;
return 0 ;
}
static struct V_47 * F_174 ( struct V_51 * V_51 , int V_54 )
{
struct V_135 * V_122 = & V_51 -> V_50 . V_37 ;
struct V_47 * V_63 ;
if ( ! F_55 ( V_51 ) )
return NULL ;
F_175 (p, head, pushable_tasks) {
if ( F_170 ( V_51 , V_63 , V_54 ) )
return V_63 ;
}
return NULL ;
}
static int F_155 ( struct V_47 * V_136 )
{
struct V_137 * V_138 ;
struct V_81 * V_139 = F_176 ( V_140 ) ;
int V_141 = F_177 () ;
int V_54 = F_178 ( V_136 ) ;
if ( F_95 ( ! V_139 ) )
return - 1 ;
if ( F_53 ( V_136 ) == 1 )
return - 1 ;
if ( ! F_158 ( & F_40 ( V_136 ) -> V_66 -> V_107 , V_136 , V_139 ) )
return - 1 ;
if ( F_172 ( V_54 , V_139 ) )
return V_54 ;
if ( ! F_172 ( V_141 , V_139 ) )
V_141 = - 1 ;
F_152 () ;
F_179 (cpu, sd) {
if ( V_138 -> V_113 & V_142 ) {
int V_143 ;
if ( V_141 != - 1 &&
F_172 ( V_141 , F_180 ( V_138 ) ) ) {
F_156 () ;
return V_141 ;
}
V_143 = F_181 ( V_139 ,
F_180 ( V_138 ) ) ;
if ( V_143 < V_40 ) {
F_156 () ;
return V_143 ;
}
}
}
F_156 () ;
if ( V_141 != - 1 )
return V_141 ;
V_54 = F_182 ( V_139 ) ;
if ( V_54 < V_40 )
return V_54 ;
return - 1 ;
}
static struct V_51 * F_183 ( struct V_47 * V_136 , struct V_51 * V_51 )
{
struct V_51 * V_144 = NULL ;
int V_145 ;
int V_54 ;
for ( V_145 = 0 ; V_145 < V_146 ; V_145 ++ ) {
V_54 = F_155 ( V_136 ) ;
if ( ( V_54 == - 1 ) || ( V_54 == V_51 -> V_54 ) )
break;
V_144 = F_34 ( V_54 ) ;
if ( V_144 -> V_50 . V_32 . V_33 <= V_136 -> V_65 ) {
V_144 = NULL ;
break;
}
if ( F_184 ( V_51 , V_144 ) ) {
if ( F_95 ( F_40 ( V_136 ) != V_51 ||
! F_172 ( V_144 -> V_54 ,
F_173 ( V_136 ) ) ||
F_171 ( V_51 , V_136 ) ||
! F_154 ( V_136 ) ||
! F_167 ( V_136 ) ) ) {
F_185 ( V_51 , V_144 ) ;
V_144 = NULL ;
break;
}
}
if ( V_144 -> V_50 . V_32 . V_33 > V_136 -> V_65 )
break;
F_185 ( V_51 , V_144 ) ;
V_144 = NULL ;
}
return V_144 ;
}
static struct V_47 * F_186 ( struct V_51 * V_51 )
{
struct V_47 * V_63 ;
if ( ! F_55 ( V_51 ) )
return NULL ;
V_63 = F_66 ( & V_51 -> V_50 . V_37 ,
struct V_47 , V_37 ) ;
F_98 ( V_51 -> V_54 != F_178 ( V_63 ) ) ;
F_98 ( F_144 ( V_51 , V_63 ) ) ;
F_98 ( F_53 ( V_63 ) <= 1 ) ;
F_98 ( ! F_167 ( V_63 ) ) ;
F_98 ( ! F_154 ( V_63 ) ) ;
return V_63 ;
}
static int F_187 ( struct V_51 * V_51 )
{
struct V_47 * V_147 ;
struct V_51 * V_144 ;
int V_148 = 0 ;
if ( ! V_51 -> V_50 . V_36 )
return 0 ;
V_147 = F_186 ( V_51 ) ;
if ( ! V_147 )
return 0 ;
V_149:
if ( F_95 ( V_147 == V_51 -> V_33 ) ) {
F_125 ( 1 ) ;
return 0 ;
}
if ( F_95 ( V_147 -> V_65 < V_51 -> V_33 -> V_65 ) ) {
F_79 ( V_51 ) ;
return 0 ;
}
F_188 ( V_147 ) ;
V_144 = F_183 ( V_147 , V_51 ) ;
if ( ! V_144 ) {
struct V_47 * V_136 ;
V_136 = F_186 ( V_51 ) ;
if ( F_178 ( V_147 ) == V_51 -> V_54 && V_136 == V_147 ) {
goto V_126;
}
if ( ! V_136 )
goto V_126;
F_189 ( V_147 ) ;
V_147 = V_136 ;
goto V_149;
}
F_190 ( V_51 , V_147 , 0 ) ;
F_191 ( V_147 , V_144 -> V_54 ) ;
F_192 ( V_144 , V_147 , 0 ) ;
V_148 = 1 ;
F_79 ( V_144 ) ;
F_185 ( V_51 , V_144 ) ;
V_126:
F_189 ( V_147 ) ;
return V_148 ;
}
static void V_72 ( struct V_51 * V_51 )
{
while ( F_187 ( V_51 ) )
;
}
static int F_193 ( struct V_51 * V_51 )
{
int V_150 = V_51 -> V_50 . V_39 ;
int V_54 ;
V_54 = F_194 ( V_150 , V_51 -> V_66 -> V_69 ) ;
if ( V_150 < V_51 -> V_54 ) {
if ( V_54 >= V_51 -> V_54 )
return V_40 ;
} else if ( V_54 >= V_40 ) {
V_54 = F_195 ( V_51 -> V_66 -> V_69 ) ;
if ( V_54 >= V_51 -> V_54 )
return V_40 ;
}
V_51 -> V_50 . V_39 = V_54 ;
return V_54 ;
}
static int F_196 ( struct V_51 * V_51 )
{
struct V_51 * V_151 ;
int V_54 ;
while ( 1 ) {
V_54 = F_193 ( V_51 ) ;
if ( V_54 >= V_40 )
break;
V_151 = F_34 ( V_54 ) ;
if ( V_151 -> V_50 . V_32 . V_34 < V_51 -> V_50 . V_32 . V_33 )
break;
}
return V_54 ;
}
static void F_197 ( struct V_51 * V_51 )
{
int V_54 ;
if ( V_51 -> V_50 . V_38 & V_152 ) {
F_3 ( & V_51 -> V_50 . V_41 ) ;
if ( V_51 -> V_50 . V_38 & V_152 ) {
V_51 -> V_50 . V_38 |= V_153 ;
F_5 ( & V_51 -> V_50 . V_41 ) ;
return;
}
F_5 ( & V_51 -> V_50 . V_41 ) ;
}
V_51 -> V_50 . V_39 = V_51 -> V_54 ;
V_54 = F_196 ( V_51 ) ;
if ( V_54 >= V_40 )
return;
V_51 -> V_50 . V_38 = V_152 ;
F_198 ( & V_51 -> V_50 . V_42 , V_54 ) ;
}
static void F_199 ( void * V_154 )
{
struct V_22 * V_22 = V_154 ;
struct V_51 * V_51 , * V_155 ;
int V_141 ;
int V_54 ;
V_141 = V_22 -> V_39 ;
F_98 ( V_141 != F_177 () ) ;
V_51 = F_34 ( V_141 ) ;
V_155 = F_27 ( V_22 ) ;
V_156:
if ( F_55 ( V_51 ) ) {
F_3 ( & V_51 -> V_95 ) ;
F_187 ( V_51 ) ;
F_5 ( & V_51 -> V_95 ) ;
}
F_3 ( & V_22 -> V_41 ) ;
if ( V_22 -> V_38 & V_153 ) {
V_22 -> V_38 &= ~ V_153 ;
V_22 -> V_39 = V_155 -> V_54 ;
}
V_54 = F_196 ( V_155 ) ;
if ( V_54 >= V_40 )
V_22 -> V_38 &= ~ V_152 ;
F_5 ( & V_22 -> V_41 ) ;
if ( V_54 >= V_40 )
return;
if ( F_95 ( V_54 == V_51 -> V_54 ) )
goto V_156;
F_198 ( & V_22 -> V_42 , V_54 ) ;
}
static void V_43 ( struct V_157 * V_158 )
{
struct V_22 * V_22 = F_2 ( V_158 , struct V_22 , V_42 ) ;
F_199 ( V_22 ) ;
}
static void V_74 ( struct V_51 * V_75 )
{
int V_141 = V_75 -> V_54 , V_54 ;
bool V_159 = false ;
struct V_47 * V_63 ;
struct V_51 * V_155 ;
if ( F_107 ( ! F_42 ( V_75 ) ) )
return;
F_200 () ;
#ifdef F_19
if ( F_101 ( V_160 ) ) {
F_197 ( V_75 ) ;
return;
}
#endif
F_92 (cpu, this_rq->rd->rto_mask) {
if ( V_141 == V_54 )
continue;
V_155 = F_34 ( V_54 ) ;
if ( V_155 -> V_50 . V_32 . V_34 >=
V_75 -> V_50 . V_32 . V_33 )
continue;
F_184 ( V_75 , V_155 ) ;
V_63 = F_174 ( V_155 , V_141 ) ;
if ( V_63 && ( V_63 -> V_65 < V_75 -> V_50 . V_32 . V_33 ) ) {
F_125 ( V_63 == V_155 -> V_33 ) ;
F_125 ( ! F_167 ( V_63 ) ) ;
if ( V_63 -> V_65 < V_155 -> V_33 -> V_65 )
goto V_161;
V_159 = true ;
F_190 ( V_155 , V_63 , 0 ) ;
F_191 ( V_63 , V_141 ) ;
F_192 ( V_75 , V_63 , 0 ) ;
}
V_161:
F_185 ( V_75 , V_155 ) ;
}
if ( V_159 )
F_79 ( V_75 ) ;
}
static void F_201 ( struct V_51 * V_51 , struct V_47 * V_63 )
{
if ( ! F_171 ( V_51 , V_63 ) &&
! F_160 ( V_51 -> V_33 ) &&
F_53 ( V_63 ) > 1 &&
( F_202 ( V_51 -> V_33 ) || F_154 ( V_51 -> V_33 ) ) &&
( F_53 ( V_51 -> V_33 ) < 2 ||
V_51 -> V_33 -> V_65 <= V_63 -> V_65 ) )
V_72 ( V_51 ) ;
}
static void F_203 ( struct V_51 * V_51 )
{
if ( V_51 -> V_50 . V_36 )
F_44 ( V_51 ) ;
F_99 ( V_51 ) ;
F_121 ( & V_51 -> V_66 -> V_107 , V_51 -> V_54 , V_51 -> V_50 . V_32 . V_33 ) ;
}
static void F_204 ( struct V_51 * V_51 )
{
if ( V_51 -> V_50 . V_36 )
F_48 ( V_51 ) ;
F_94 ( V_51 ) ;
F_121 ( & V_51 -> V_66 -> V_107 , V_51 -> V_54 , V_162 ) ;
}
static void F_205 ( struct V_51 * V_51 , struct V_47 * V_63 )
{
if ( ! F_167 ( V_63 ) || V_51 -> V_50 . V_79 )
return;
F_60 ( V_51 ) ;
}
void T_4 F_206 ( void )
{
unsigned int V_25 ;
F_31 (i) {
F_207 ( & F_59 ( V_140 , V_25 ) ,
V_59 , F_39 ( V_25 ) ) ;
}
}
static void F_208 ( struct V_51 * V_51 , struct V_47 * V_63 )
{
if ( F_167 ( V_63 ) && V_51 -> V_33 != V_63 ) {
#ifdef V_31
if ( F_53 ( V_63 ) > 1 && V_51 -> V_50 . V_36 )
F_57 ( V_51 ) ;
#else
if ( V_63 -> V_65 < V_51 -> V_33 -> V_65 )
F_79 ( V_51 ) ;
#endif
}
}
static void
F_209 ( struct V_51 * V_51 , struct V_47 * V_63 , int V_163 )
{
if ( ! F_167 ( V_63 ) )
return;
if ( V_51 -> V_33 == V_63 ) {
#ifdef V_31
if ( V_163 < V_63 -> V_65 )
F_60 ( V_51 ) ;
if ( V_63 -> V_65 > V_51 -> V_50 . V_32 . V_33 )
F_79 ( V_51 ) ;
#else
if ( V_163 < V_63 -> V_65 )
F_79 ( V_51 ) ;
#endif
} else {
if ( V_63 -> V_65 < V_51 -> V_33 -> V_65 )
F_79 ( V_51 ) ;
}
}
static void F_210 ( struct V_51 * V_51 , struct V_47 * V_63 )
{
unsigned long V_164 , V_165 ;
V_164 = F_211 ( V_63 , V_166 ) ;
V_165 = F_212 ( V_63 , V_166 ) ;
if ( V_164 != V_167 ) {
unsigned long V_34 ;
if ( V_63 -> V_50 . V_168 != V_169 ) {
V_63 -> V_50 . V_121 ++ ;
V_63 -> V_50 . V_168 = V_169 ;
}
V_34 = F_213 ( F_103 ( V_164 , V_165 ) , V_170 / V_171 ) ;
if ( V_63 -> V_50 . V_121 > V_34 )
V_63 -> V_172 . V_173 = V_63 -> V_99 . V_104 ;
}
}
static void F_214 ( struct V_51 * V_51 , struct V_47 * V_63 , int V_174 )
{
struct V_48 * V_49 = & V_63 -> V_50 ;
F_109 ( V_51 ) ;
F_210 ( V_51 , V_63 ) ;
if ( V_63 -> V_111 != V_112 )
return;
if ( -- V_63 -> V_50 . V_175 )
return;
V_63 -> V_50 . V_175 = V_176 ;
F_117 (rt_se) {
if ( V_49 -> V_58 . V_64 != V_49 -> V_58 . V_34 ) {
F_149 ( V_51 , V_63 , 0 ) ;
F_79 ( V_51 ) ;
return;
}
}
}
static void F_215 ( struct V_51 * V_51 )
{
struct V_47 * V_63 = V_51 -> V_33 ;
V_63 -> V_99 . V_100 = F_110 ( V_51 ) ;
F_65 ( V_51 , V_63 ) ;
}
static unsigned int F_216 ( struct V_51 * V_51 , struct V_47 * V_136 )
{
if ( V_136 -> V_111 == V_112 )
return V_176 ;
else
return 0 ;
}
void F_217 ( struct V_177 * V_178 , int V_54 )
{
T_3 V_86 ;
struct V_22 * V_22 ;
F_152 () ;
F_96 (rt_rq, iter, cpu_rq(cpu))
F_218 ( V_178 , V_54 , V_22 ) ;
F_156 () ;
}
