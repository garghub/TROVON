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
if ( V_63 -> V_71 > 1 )
V_22 -> V_35 ++ ;
F_51 ( V_22 ) ;
}
static void F_53 ( struct V_48 * V_49 , struct V_22 * V_22 )
{
struct V_47 * V_63 ;
if ( ! F_26 ( V_49 ) )
return;
V_63 = F_23 ( V_49 ) ;
V_22 = & F_27 ( V_22 ) -> V_50 ;
V_22 -> V_70 -- ;
if ( V_63 -> V_71 > 1 )
V_22 -> V_35 -- ;
F_51 ( V_22 ) ;
}
static inline int F_54 ( struct V_51 * V_51 )
{
return ! F_55 ( & V_51 -> V_50 . V_37 ) ;
}
static inline void F_56 ( struct V_51 * V_51 )
{
if ( ! F_54 ( V_51 ) )
return;
F_57 ( V_51 , & F_58 ( V_72 , V_51 -> V_54 ) , V_73 ) ;
}
static inline void F_59 ( struct V_51 * V_51 )
{
F_57 ( V_51 , & F_58 ( V_74 , V_51 -> V_54 ) , V_75 ) ;
}
static void F_60 ( struct V_51 * V_51 , struct V_47 * V_63 )
{
F_61 ( & V_63 -> V_37 , & V_51 -> V_50 . V_37 ) ;
F_62 ( & V_63 -> V_37 , V_63 -> V_65 ) ;
F_63 ( & V_63 -> V_37 , & V_51 -> V_50 . V_37 ) ;
if ( V_63 -> V_65 < V_51 -> V_50 . V_32 . V_34 )
V_51 -> V_50 . V_32 . V_34 = V_63 -> V_65 ;
}
static void F_64 ( struct V_51 * V_51 , struct V_47 * V_63 )
{
F_61 ( & V_63 -> V_37 , & V_51 -> V_50 . V_37 ) ;
if ( F_54 ( V_51 ) ) {
V_63 = F_65 ( & V_51 -> V_50 . V_37 ,
struct V_47 , V_37 ) ;
V_51 -> V_50 . V_32 . V_34 = V_63 -> V_65 ;
} else
V_51 -> V_50 . V_32 . V_34 = V_27 ;
}
static inline void F_60 ( struct V_51 * V_51 , struct V_47 * V_63 )
{
}
static inline void F_64 ( struct V_51 * V_51 , struct V_47 * V_63 )
{
}
static inline
void F_52 ( struct V_48 * V_49 , struct V_22 * V_22 )
{
}
static inline
void F_53 ( struct V_48 * V_49 , struct V_22 * V_22 )
{
}
static inline bool F_41 ( struct V_51 * V_51 , struct V_47 * V_64 )
{
return false ;
}
static inline void V_75 ( struct V_51 * V_76 )
{
}
static inline void F_56 ( struct V_51 * V_51 )
{
}
static inline int F_66 ( struct V_48 * V_49 )
{
return V_49 -> V_77 ;
}
static inline T_1 F_67 ( struct V_22 * V_22 )
{
if ( ! V_22 -> V_53 )
return V_20 ;
return V_22 -> V_16 ;
}
static inline T_1 F_68 ( struct V_22 * V_22 )
{
return F_37 ( V_22 -> V_53 -> V_4 . V_10 ) ;
}
static inline struct V_52 * F_69 ( struct V_52 * V_53 )
{
do {
V_53 = F_70 ( V_53 -> V_78 . V_34 ,
F_71 ( struct V_52 ) , V_78 ) ;
} while ( & V_53 -> V_78 != & V_79 && F_72 ( V_53 ) );
if ( & V_53 -> V_78 == & V_79 )
V_53 = NULL ;
return V_53 ;
}
static inline struct V_22 * F_73 ( struct V_48 * V_49 )
{
return V_49 -> V_57 ;
}
static void F_74 ( struct V_22 * V_22 )
{
struct V_47 * V_33 = F_27 ( V_22 ) -> V_33 ;
struct V_51 * V_51 = F_27 ( V_22 ) ;
struct V_48 * V_49 ;
int V_54 = F_75 ( V_51 ) ;
V_49 = V_22 -> V_53 -> V_49 [ V_54 ] ;
if ( V_22 -> V_80 ) {
if ( ! V_49 )
F_76 ( V_22 ) ;
else if ( ! F_66 ( V_49 ) )
F_77 ( V_49 , 0 ) ;
if ( V_22 -> V_32 . V_33 < V_33 -> V_65 )
F_78 ( V_51 ) ;
}
}
static void F_79 ( struct V_22 * V_22 )
{
struct V_48 * V_49 ;
int V_54 = F_75 ( F_27 ( V_22 ) ) ;
V_49 = V_22 -> V_53 -> V_49 [ V_54 ] ;
if ( ! V_49 )
F_80 ( V_22 ) ;
else if ( F_66 ( V_49 ) )
F_81 ( V_49 , 0 ) ;
}
static inline int F_82 ( struct V_22 * V_22 )
{
return V_22 -> V_46 && ! V_22 -> V_56 ;
}
static int F_83 ( struct V_48 * V_49 )
{
struct V_22 * V_22 = F_73 ( V_49 ) ;
struct V_47 * V_63 ;
if ( V_22 )
return ! ! V_22 -> V_56 ;
V_63 = F_23 ( V_49 ) ;
return V_63 -> V_65 != V_63 -> V_81 ;
}
static inline const struct V_82 * F_84 ( void )
{
return V_76 () -> V_66 -> V_83 ;
}
static inline const struct V_82 * F_84 ( void )
{
return V_84 ;
}
static inline
struct V_22 * F_85 ( struct V_4 * V_5 , int V_54 )
{
return F_2 ( V_5 , struct V_52 , V_4 ) -> V_22 [ V_54 ] ;
}
static inline struct V_4 * F_86 ( struct V_22 * V_22 )
{
return & V_22 -> V_53 -> V_4 ;
}
static inline T_1 F_67 ( struct V_22 * V_22 )
{
return V_22 -> V_16 ;
}
static inline T_1 F_68 ( struct V_22 * V_22 )
{
return F_37 ( V_61 . V_10 ) ;
}
static inline struct V_22 * F_73 ( struct V_48 * V_49 )
{
return NULL ;
}
static inline void F_74 ( struct V_22 * V_22 )
{
struct V_51 * V_51 = F_27 ( V_22 ) ;
if ( ! V_22 -> V_80 )
return;
F_76 ( V_22 ) ;
F_78 ( V_51 ) ;
}
static inline void F_79 ( struct V_22 * V_22 )
{
F_80 ( V_22 ) ;
}
static inline int F_82 ( struct V_22 * V_22 )
{
return V_22 -> V_46 ;
}
static inline const struct V_82 * F_84 ( void )
{
return V_84 ;
}
static inline
struct V_22 * F_85 ( struct V_4 * V_5 , int V_54 )
{
return & F_34 ( V_54 ) -> V_50 ;
}
static inline struct V_4 * F_86 ( struct V_22 * V_22 )
{
return & V_61 ;
}
bool F_87 ( struct V_22 * V_22 )
{
struct V_4 * V_5 = F_86 ( V_22 ) ;
return ( F_88 ( & V_5 -> V_6 ) ||
V_22 -> V_45 < V_5 -> V_16 ) ;
}
static void F_89 ( struct V_22 * V_22 )
{
struct V_4 * V_5 = F_86 ( V_22 ) ;
struct V_85 * V_66 = F_27 ( V_22 ) -> V_66 ;
int V_25 , V_86 ;
T_1 V_10 ;
V_86 = F_90 ( V_66 -> V_83 ) ;
F_3 ( & V_5 -> V_9 ) ;
V_10 = F_37 ( V_5 -> V_10 ) ;
F_91 (i, rd->span) {
struct V_22 * V_87 = F_85 ( V_5 , V_25 ) ;
T_2 V_88 ;
if ( V_87 == V_22 )
continue;
F_3 ( & V_87 -> V_9 ) ;
if ( V_87 -> V_16 == V_20 )
goto V_34;
V_88 = V_87 -> V_16 - V_87 -> V_45 ;
if ( V_88 > 0 ) {
V_88 = F_92 ( ( T_1 ) V_88 , V_86 ) ;
if ( V_22 -> V_16 + V_88 > V_10 )
V_88 = V_10 - V_22 -> V_16 ;
V_87 -> V_16 -= V_88 ;
V_22 -> V_16 += V_88 ;
if ( V_22 -> V_16 == V_10 ) {
F_5 ( & V_87 -> V_9 ) ;
break;
}
}
V_34:
F_5 ( & V_87 -> V_9 ) ;
}
F_5 ( & V_5 -> V_9 ) ;
}
static void F_93 ( struct V_51 * V_51 )
{
struct V_85 * V_66 = V_51 -> V_66 ;
T_3 V_87 ;
struct V_22 * V_22 ;
if ( F_94 ( ! V_89 ) )
return;
F_95 (rt_rq, iter, rq) {
struct V_4 * V_5 = F_86 ( V_22 ) ;
T_2 V_90 ;
int V_25 ;
F_3 ( & V_5 -> V_9 ) ;
F_3 ( & V_22 -> V_9 ) ;
if ( V_22 -> V_16 == V_20 ||
V_22 -> V_16 == V_5 -> V_16 )
goto V_91;
F_5 ( & V_22 -> V_9 ) ;
V_90 = V_5 -> V_16 - V_22 -> V_16 ;
F_91 (i, rd->span) {
struct V_22 * V_87 = F_85 ( V_5 , V_25 ) ;
T_2 V_88 ;
if ( V_87 == V_22 || V_87 -> V_16 == V_20 )
continue;
F_3 ( & V_87 -> V_9 ) ;
if ( V_90 > 0 ) {
V_88 = F_96 ( T_2 , V_87 -> V_16 , V_90 ) ;
V_87 -> V_16 -= V_88 ;
V_90 -= V_88 ;
} else {
V_87 -> V_16 -= V_90 ;
V_90 -= V_90 ;
}
F_5 ( & V_87 -> V_9 ) ;
if ( ! V_90 )
break;
}
F_3 ( & V_22 -> V_9 ) ;
F_97 ( V_90 ) ;
V_91:
V_22 -> V_16 = V_20 ;
V_22 -> V_46 = 0 ;
F_5 ( & V_22 -> V_9 ) ;
F_5 ( & V_5 -> V_9 ) ;
F_74 ( V_22 ) ;
}
}
static void F_98 ( struct V_51 * V_51 )
{
T_3 V_87 ;
struct V_22 * V_22 ;
if ( F_94 ( ! V_89 ) )
return;
F_95 (rt_rq, iter, rq) {
struct V_4 * V_5 = F_86 ( V_22 ) ;
F_3 ( & V_5 -> V_9 ) ;
F_3 ( & V_22 -> V_9 ) ;
V_22 -> V_16 = V_5 -> V_16 ;
V_22 -> V_45 = 0 ;
V_22 -> V_46 = 0 ;
F_5 ( & V_22 -> V_9 ) ;
F_5 ( & V_5 -> V_9 ) ;
}
}
static void F_99 ( struct V_22 * V_22 )
{
if ( ! F_100 ( V_92 ) )
return;
if ( V_22 -> V_45 > V_22 -> V_16 ) {
F_5 ( & V_22 -> V_9 ) ;
F_89 ( V_22 ) ;
F_3 ( & V_22 -> V_9 ) ;
}
}
static inline void F_99 ( struct V_22 * V_22 ) {}
static int F_6 ( struct V_4 * V_5 , int V_8 )
{
int V_25 , V_7 = 1 , V_93 = 0 ;
const struct V_82 * V_83 ;
V_83 = F_84 () ;
#ifdef F_101
if ( V_5 == & V_94 . V_4 )
V_83 = V_84 ;
#endif
F_91 (i, span) {
int V_95 = 0 ;
struct V_22 * V_22 = F_85 ( V_5 , V_25 ) ;
struct V_51 * V_51 = F_27 ( V_22 ) ;
int V_96 ;
F_3 ( & V_22 -> V_9 ) ;
V_96 = ! V_22 -> V_45 && ! V_22 -> V_80 ;
F_5 ( & V_22 -> V_9 ) ;
if ( V_96 )
continue;
F_3 ( & V_51 -> V_97 ) ;
if ( V_22 -> V_45 ) {
T_1 V_15 ;
F_3 ( & V_22 -> V_9 ) ;
if ( V_22 -> V_46 )
F_99 ( V_22 ) ;
V_15 = V_22 -> V_16 ;
V_22 -> V_45 -= F_102 ( V_22 -> V_45 , V_8 * V_15 ) ;
if ( V_22 -> V_46 && V_22 -> V_45 < V_15 ) {
V_22 -> V_46 = 0 ;
V_95 = 1 ;
if ( V_22 -> V_80 && V_51 -> V_33 == V_51 -> V_7 )
F_103 ( V_51 , false ) ;
}
if ( V_22 -> V_45 || V_22 -> V_80 )
V_7 = 0 ;
F_5 ( & V_22 -> V_9 ) ;
} else if ( V_22 -> V_80 ) {
V_7 = 0 ;
if ( ! F_82 ( V_22 ) )
V_95 = 1 ;
}
if ( V_22 -> V_46 )
V_93 = 1 ;
if ( V_95 )
F_74 ( V_22 ) ;
F_5 ( & V_51 -> V_97 ) ;
}
if ( ! V_93 && ( ! F_12 () || V_5 -> V_16 == V_20 ) )
return 1 ;
return V_7 ;
}
static inline int F_104 ( struct V_48 * V_49 )
{
#ifdef F_101
struct V_22 * V_22 = F_73 ( V_49 ) ;
if ( V_22 )
return V_22 -> V_32 . V_33 ;
#endif
return F_23 ( V_49 ) -> V_65 ;
}
static int F_105 ( struct V_22 * V_22 )
{
T_1 V_15 = F_67 ( V_22 ) ;
if ( V_22 -> V_46 )
return F_82 ( V_22 ) ;
if ( V_15 >= F_68 ( V_22 ) )
return 0 ;
F_99 ( V_22 ) ;
V_15 = F_67 ( V_22 ) ;
if ( V_15 == V_20 )
return 0 ;
if ( V_22 -> V_45 > V_15 ) {
struct V_4 * V_5 = F_86 ( V_22 ) ;
if ( F_106 ( V_5 -> V_16 ) ) {
V_22 -> V_46 = 1 ;
F_107 ( L_1 ) ;
} else {
V_22 -> V_45 = 0 ;
}
if ( F_82 ( V_22 ) ) {
F_79 ( V_22 ) ;
return 1 ;
}
}
return 0 ;
}
static void F_108 ( struct V_51 * V_51 )
{
struct V_47 * V_33 = V_51 -> V_33 ;
struct V_48 * V_49 = & V_33 -> V_50 ;
T_1 V_98 ;
if ( V_33 -> V_99 != & V_100 )
return;
V_98 = F_109 ( V_51 ) - V_33 -> V_101 . V_102 ;
if ( F_94 ( ( T_2 ) V_98 <= 0 ) )
return;
F_110 ( V_51 , V_103 ) ;
F_111 ( V_33 -> V_101 . V_104 . V_105 ,
F_112 ( V_33 -> V_101 . V_104 . V_105 , V_98 ) ) ;
V_33 -> V_101 . V_106 += V_98 ;
F_113 ( V_33 , V_98 ) ;
V_33 -> V_101 . V_102 = F_109 ( V_51 ) ;
F_114 ( V_33 , V_98 ) ;
F_115 ( V_51 , V_98 ) ;
if ( ! F_12 () )
return;
F_116 (rt_se) {
struct V_22 * V_22 = F_28 ( V_49 ) ;
if ( F_67 ( V_22 ) != V_20 ) {
F_3 ( & V_22 -> V_9 ) ;
V_22 -> V_45 += V_98 ;
if ( F_105 ( V_22 ) )
F_78 ( V_51 ) ;
F_5 ( & V_22 -> V_9 ) ;
}
}
}
static void
F_80 ( struct V_22 * V_22 )
{
struct V_51 * V_51 = F_27 ( V_22 ) ;
F_97 ( & V_51 -> V_50 != V_22 ) ;
if ( ! V_22 -> V_44 )
return;
F_97 ( ! V_51 -> V_107 ) ;
F_117 ( V_51 , V_22 -> V_80 ) ;
V_22 -> V_44 = 0 ;
}
static void
F_76 ( struct V_22 * V_22 )
{
struct V_51 * V_51 = F_27 ( V_22 ) ;
F_97 ( & V_51 -> V_50 != V_22 ) ;
if ( V_22 -> V_44 )
return;
if ( F_82 ( V_22 ) || ! V_22 -> V_80 )
return;
F_118 ( V_51 , V_22 -> V_80 ) ;
V_22 -> V_44 = 1 ;
}
static void
F_119 ( struct V_22 * V_22 , int V_65 , int V_108 )
{
struct V_51 * V_51 = F_27 ( V_22 ) ;
#ifdef F_101
if ( & V_51 -> V_50 != V_22 )
return;
#endif
if ( V_51 -> V_68 && V_65 < V_108 )
F_120 ( & V_51 -> V_66 -> V_109 , V_51 -> V_54 , V_65 ) ;
}
static void
F_121 ( struct V_22 * V_22 , int V_65 , int V_108 )
{
struct V_51 * V_51 = F_27 ( V_22 ) ;
#ifdef F_101
if ( & V_51 -> V_50 != V_22 )
return;
#endif
if ( V_51 -> V_68 && V_22 -> V_32 . V_33 != V_108 )
F_120 ( & V_51 -> V_66 -> V_109 , V_51 -> V_54 , V_22 -> V_32 . V_33 ) ;
}
static inline
void F_119 ( struct V_22 * V_22 , int V_65 , int V_108 ) {}
static inline
void F_121 ( struct V_22 * V_22 , int V_65 , int V_108 ) {}
static void
F_122 ( struct V_22 * V_22 , int V_65 )
{
int V_108 = V_22 -> V_32 . V_33 ;
if ( V_65 < V_108 )
V_22 -> V_32 . V_33 = V_65 ;
F_119 ( V_22 , V_65 , V_108 ) ;
}
static void
F_123 ( struct V_22 * V_22 , int V_65 )
{
int V_108 = V_22 -> V_32 . V_33 ;
if ( V_22 -> V_80 ) {
F_124 ( V_65 < V_108 ) ;
if ( V_65 == V_108 ) {
struct V_23 * V_24 = & V_22 -> V_26 ;
V_22 -> V_32 . V_33 =
F_125 ( V_24 -> V_29 ) ;
}
} else
V_22 -> V_32 . V_33 = V_27 ;
F_121 ( V_22 , V_65 , V_108 ) ;
}
static inline void F_122 ( struct V_22 * V_22 , int V_65 ) {}
static inline void F_123 ( struct V_22 * V_22 , int V_65 ) {}
static void
F_126 ( struct V_48 * V_49 , struct V_22 * V_22 )
{
if ( F_83 ( V_49 ) )
V_22 -> V_56 ++ ;
if ( V_22 -> V_53 )
F_11 ( & V_22 -> V_53 -> V_4 ) ;
}
static void
F_127 ( struct V_48 * V_49 , struct V_22 * V_22 )
{
if ( F_83 ( V_49 ) )
V_22 -> V_56 -- ;
F_124 ( ! V_22 -> V_80 && V_22 -> V_56 ) ;
}
static void
F_126 ( struct V_48 * V_49 , struct V_22 * V_22 )
{
F_11 ( & V_61 ) ;
}
static inline
void F_127 ( struct V_48 * V_49 , struct V_22 * V_22 ) {}
static inline
unsigned int F_128 ( struct V_48 * V_49 )
{
struct V_22 * V_110 = F_73 ( V_49 ) ;
if ( V_110 )
return V_110 -> V_80 ;
else
return 1 ;
}
static inline
unsigned int F_129 ( struct V_48 * V_49 )
{
struct V_22 * V_110 = F_73 ( V_49 ) ;
struct V_47 * V_111 ;
if ( V_110 )
return V_110 -> V_112 ;
V_111 = F_23 ( V_49 ) ;
return ( V_111 -> V_113 == V_114 ) ? 1 : 0 ;
}
static inline
void F_130 ( struct V_48 * V_49 , struct V_22 * V_22 )
{
int V_65 = F_104 ( V_49 ) ;
F_124 ( ! F_131 ( V_65 ) ) ;
V_22 -> V_80 += F_128 ( V_49 ) ;
V_22 -> V_112 += F_129 ( V_49 ) ;
F_122 ( V_22 , V_65 ) ;
F_52 ( V_49 , V_22 ) ;
F_126 ( V_49 , V_22 ) ;
}
static inline
void F_132 ( struct V_48 * V_49 , struct V_22 * V_22 )
{
F_124 ( ! F_131 ( F_104 ( V_49 ) ) ) ;
F_124 ( ! V_22 -> V_80 ) ;
V_22 -> V_80 -= F_128 ( V_49 ) ;
V_22 -> V_112 -= F_129 ( V_49 ) ;
F_123 ( V_22 , F_104 ( V_49 ) ) ;
F_53 ( V_49 , V_22 ) ;
F_127 ( V_49 , V_22 ) ;
}
static inline bool F_133 ( unsigned int V_115 )
{
if ( ( V_115 & ( V_116 | V_117 ) ) == V_116 )
return false ;
return true ;
}
static void F_134 ( struct V_48 * V_49 , struct V_23 * V_24 )
{
F_135 ( & V_49 -> V_58 ) ;
if ( F_136 ( V_24 -> V_28 + F_104 ( V_49 ) ) )
F_16 ( F_104 ( V_49 ) , V_24 -> V_29 ) ;
V_49 -> V_118 = 0 ;
}
static void F_137 ( struct V_48 * V_49 , unsigned int V_115 )
{
struct V_22 * V_22 = F_28 ( V_49 ) ;
struct V_23 * V_24 = & V_22 -> V_26 ;
struct V_22 * V_110 = F_73 ( V_49 ) ;
struct V_119 * V_28 = V_24 -> V_28 + F_104 ( V_49 ) ;
if ( V_110 && ( F_82 ( V_110 ) || ! V_110 -> V_80 ) ) {
if ( V_49 -> V_118 )
F_134 ( V_49 , V_24 ) ;
return;
}
if ( F_133 ( V_115 ) ) {
F_25 ( V_49 -> V_118 ) ;
if ( V_115 & V_120 )
F_138 ( & V_49 -> V_58 , V_28 ) ;
else
F_139 ( & V_49 -> V_58 , V_28 ) ;
F_17 ( F_104 ( V_49 ) , V_24 -> V_29 ) ;
V_49 -> V_118 = 1 ;
}
V_49 -> V_77 = 1 ;
F_130 ( V_49 , V_22 ) ;
}
static void F_140 ( struct V_48 * V_49 , unsigned int V_115 )
{
struct V_22 * V_22 = F_28 ( V_49 ) ;
struct V_23 * V_24 = & V_22 -> V_26 ;
if ( F_133 ( V_115 ) ) {
F_25 ( ! V_49 -> V_118 ) ;
F_134 ( V_49 , V_24 ) ;
}
V_49 -> V_77 = 0 ;
F_132 ( V_49 , V_22 ) ;
}
static void F_141 ( struct V_48 * V_49 , unsigned int V_115 )
{
struct V_48 * V_121 = NULL ;
F_116 (rt_se) {
V_49 -> V_121 = V_121 ;
V_121 = V_49 ;
}
F_80 ( F_28 ( V_121 ) ) ;
for ( V_49 = V_121 ; V_49 ; V_49 = V_49 -> V_121 ) {
if ( F_66 ( V_49 ) )
F_140 ( V_49 , V_115 ) ;
}
}
static void F_77 ( struct V_48 * V_49 , unsigned int V_115 )
{
struct V_51 * V_51 = F_29 ( V_49 ) ;
F_141 ( V_49 , V_115 ) ;
F_116 (rt_se)
F_137 ( V_49 , V_115 ) ;
F_76 ( & V_51 -> V_50 ) ;
}
static void F_81 ( struct V_48 * V_49 , unsigned int V_115 )
{
struct V_51 * V_51 = F_29 ( V_49 ) ;
F_141 ( V_49 , V_115 ) ;
F_116 (rt_se) {
struct V_22 * V_22 = F_73 ( V_49 ) ;
if ( V_22 && V_22 -> V_80 )
F_137 ( V_49 , V_115 ) ;
}
F_76 ( & V_51 -> V_50 ) ;
}
static void
F_142 ( struct V_51 * V_51 , struct V_47 * V_63 , int V_115 )
{
struct V_48 * V_49 = & V_63 -> V_50 ;
if ( V_115 & V_122 )
V_49 -> V_123 = 0 ;
F_77 ( V_49 , V_115 ) ;
if ( ! F_143 ( V_51 , V_63 ) && V_63 -> V_71 > 1 )
F_60 ( V_51 , V_63 ) ;
}
static void F_144 ( struct V_51 * V_51 , struct V_47 * V_63 , int V_115 )
{
struct V_48 * V_49 = & V_63 -> V_50 ;
F_108 ( V_51 ) ;
F_81 ( V_49 , V_115 ) ;
F_64 ( V_51 , V_63 ) ;
}
static void
F_145 ( struct V_22 * V_22 , struct V_48 * V_49 , int V_124 )
{
if ( F_66 ( V_49 ) ) {
struct V_23 * V_24 = & V_22 -> V_26 ;
struct V_119 * V_28 = V_24 -> V_28 + F_104 ( V_49 ) ;
if ( V_124 )
F_146 ( & V_49 -> V_58 , V_28 ) ;
else
F_147 ( & V_49 -> V_58 , V_28 ) ;
}
}
static void F_148 ( struct V_51 * V_51 , struct V_47 * V_63 , int V_124 )
{
struct V_48 * V_49 = & V_63 -> V_50 ;
struct V_22 * V_22 ;
F_116 (rt_se) {
V_22 = F_28 ( V_49 ) ;
F_145 ( V_22 , V_49 , V_124 ) ;
}
}
static void F_149 ( struct V_51 * V_51 )
{
F_148 ( V_51 , V_51 -> V_33 , 0 ) ;
}
static int
F_150 ( struct V_47 * V_63 , int V_54 , int V_125 , int V_115 )
{
struct V_47 * V_33 ;
struct V_51 * V_51 ;
if ( V_125 != V_126 && V_125 != V_127 )
goto V_128;
V_51 = F_34 ( V_54 ) ;
F_151 () ;
V_33 = F_152 ( V_51 -> V_33 ) ;
if ( V_33 && F_94 ( F_153 ( V_33 ) ) &&
( V_33 -> V_71 < 2 ||
V_33 -> V_65 <= V_63 -> V_65 ) ) {
int V_129 = F_154 ( V_63 ) ;
if ( V_129 != - 1 &&
V_63 -> V_65 < F_34 ( V_129 ) -> V_50 . V_32 . V_33 )
V_54 = V_129 ;
}
F_155 () ;
V_128:
return V_54 ;
}
static void F_156 ( struct V_51 * V_51 , struct V_47 * V_63 )
{
if ( V_51 -> V_33 -> V_71 == 1 ||
! F_157 ( & V_51 -> V_66 -> V_109 , V_51 -> V_33 , NULL ) )
return;
if ( V_63 -> V_71 != 1
&& F_157 ( & V_51 -> V_66 -> V_109 , V_63 , NULL ) )
return;
F_148 ( V_51 , V_63 , 1 ) ;
F_78 ( V_51 ) ;
}
static void F_158 ( struct V_51 * V_51 , struct V_47 * V_63 , int V_115 )
{
if ( V_63 -> V_65 < V_51 -> V_33 -> V_65 ) {
F_78 ( V_51 ) ;
return;
}
#ifdef V_31
if ( V_63 -> V_65 == V_51 -> V_33 -> V_65 && ! F_159 ( V_51 -> V_33 ) )
F_156 ( V_51 , V_63 ) ;
#endif
}
static struct V_48 * F_160 ( struct V_51 * V_51 ,
struct V_22 * V_22 )
{
struct V_23 * V_24 = & V_22 -> V_26 ;
struct V_48 * V_34 = NULL ;
struct V_119 * V_28 ;
int V_130 ;
V_130 = F_125 ( V_24 -> V_29 ) ;
F_97 ( V_130 >= V_27 ) ;
V_28 = V_24 -> V_28 + V_130 ;
V_34 = F_161 ( V_28 -> V_34 , struct V_48 , V_58 ) ;
return V_34 ;
}
static struct V_47 * F_162 ( struct V_51 * V_51 )
{
struct V_48 * V_49 ;
struct V_47 * V_63 ;
struct V_22 * V_22 = & V_51 -> V_50 ;
do {
V_49 = F_160 ( V_51 , V_22 ) ;
F_97 ( ! V_49 ) ;
V_22 = F_73 ( V_49 ) ;
} while ( V_22 );
V_63 = F_23 ( V_49 ) ;
V_63 -> V_101 . V_102 = F_109 ( V_51 ) ;
return V_63 ;
}
static struct V_47 *
F_163 ( struct V_51 * V_51 , struct V_47 * V_64 , struct V_131 * V_132 )
{
struct V_47 * V_63 ;
struct V_22 * V_22 = & V_51 -> V_50 ;
if ( F_41 ( V_51 , V_64 ) ) {
F_164 ( V_51 , V_132 ) ;
V_75 ( V_51 ) ;
F_165 ( V_51 , V_132 ) ;
if ( F_94 ( ( V_51 -> V_133 && F_166 ( V_51 -> V_133 ) ) ||
V_51 -> V_134 . V_135 ) )
return V_136 ;
}
if ( V_64 -> V_99 == & V_100 )
F_108 ( V_51 ) ;
if ( ! V_22 -> V_44 )
return NULL ;
F_167 ( V_51 , V_64 ) ;
V_63 = F_162 ( V_51 ) ;
F_64 ( V_51 , V_63 ) ;
F_56 ( V_51 ) ;
return V_63 ;
}
static void F_168 ( struct V_51 * V_51 , struct V_47 * V_63 )
{
F_108 ( V_51 ) ;
if ( F_66 ( & V_63 -> V_50 ) && V_63 -> V_71 > 1 )
F_60 ( V_51 , V_63 ) ;
}
static int F_169 ( struct V_51 * V_51 , struct V_47 * V_63 , int V_54 )
{
if ( ! F_170 ( V_51 , V_63 ) &&
F_171 ( V_54 , & V_63 -> V_137 ) )
return 1 ;
return 0 ;
}
static struct V_47 * F_172 ( struct V_51 * V_51 , int V_54 )
{
struct V_138 * V_124 = & V_51 -> V_50 . V_37 ;
struct V_47 * V_63 ;
if ( ! F_54 ( V_51 ) )
return NULL ;
F_173 (p, head, pushable_tasks) {
if ( F_169 ( V_51 , V_63 , V_54 ) )
return V_63 ;
}
return NULL ;
}
static int F_154 ( struct V_47 * V_139 )
{
struct V_140 * V_141 ;
struct V_82 * V_142 = F_174 ( V_143 ) ;
int V_144 = F_175 () ;
int V_54 = F_176 ( V_139 ) ;
if ( F_94 ( ! V_142 ) )
return - 1 ;
if ( V_139 -> V_71 == 1 )
return - 1 ;
if ( ! F_157 ( & F_40 ( V_139 ) -> V_66 -> V_109 , V_139 , V_142 ) )
return - 1 ;
if ( F_171 ( V_54 , V_142 ) )
return V_54 ;
if ( ! F_171 ( V_144 , V_142 ) )
V_144 = - 1 ;
F_151 () ;
F_177 (cpu, sd) {
if ( V_141 -> V_115 & V_145 ) {
int V_146 ;
if ( V_144 != - 1 &&
F_171 ( V_144 , F_178 ( V_141 ) ) ) {
F_155 () ;
return V_144 ;
}
V_146 = F_179 ( V_142 ,
F_178 ( V_141 ) ) ;
if ( V_146 < V_40 ) {
F_155 () ;
return V_146 ;
}
}
}
F_155 () ;
if ( V_144 != - 1 )
return V_144 ;
V_54 = F_180 ( V_142 ) ;
if ( V_54 < V_40 )
return V_54 ;
return - 1 ;
}
static struct V_51 * F_181 ( struct V_47 * V_139 , struct V_51 * V_51 )
{
struct V_51 * V_147 = NULL ;
int V_148 ;
int V_54 ;
for ( V_148 = 0 ; V_148 < V_149 ; V_148 ++ ) {
V_54 = F_154 ( V_139 ) ;
if ( ( V_54 == - 1 ) || ( V_54 == V_51 -> V_54 ) )
break;
V_147 = F_34 ( V_54 ) ;
if ( V_147 -> V_50 . V_32 . V_33 <= V_139 -> V_65 ) {
V_147 = NULL ;
break;
}
if ( F_182 ( V_51 , V_147 ) ) {
if ( F_94 ( F_40 ( V_139 ) != V_51 ||
! F_171 ( V_147 -> V_54 , & V_139 -> V_137 ) ||
F_170 ( V_51 , V_139 ) ||
! F_153 ( V_139 ) ||
! F_166 ( V_139 ) ) ) {
F_183 ( V_51 , V_147 ) ;
V_147 = NULL ;
break;
}
}
if ( V_147 -> V_50 . V_32 . V_33 > V_139 -> V_65 )
break;
F_183 ( V_51 , V_147 ) ;
V_147 = NULL ;
}
return V_147 ;
}
static struct V_47 * F_184 ( struct V_51 * V_51 )
{
struct V_47 * V_63 ;
if ( ! F_54 ( V_51 ) )
return NULL ;
V_63 = F_65 ( & V_51 -> V_50 . V_37 ,
struct V_47 , V_37 ) ;
F_97 ( V_51 -> V_54 != F_176 ( V_63 ) ) ;
F_97 ( F_143 ( V_51 , V_63 ) ) ;
F_97 ( V_63 -> V_71 <= 1 ) ;
F_97 ( ! F_166 ( V_63 ) ) ;
F_97 ( ! F_153 ( V_63 ) ) ;
return V_63 ;
}
static int F_185 ( struct V_51 * V_51 )
{
struct V_47 * V_150 ;
struct V_51 * V_147 ;
int V_151 = 0 ;
if ( ! V_51 -> V_50 . V_36 )
return 0 ;
V_150 = F_184 ( V_51 ) ;
if ( ! V_150 )
return 0 ;
V_152:
if ( F_94 ( V_150 == V_51 -> V_33 ) ) {
F_124 ( 1 ) ;
return 0 ;
}
if ( F_94 ( V_150 -> V_65 < V_51 -> V_33 -> V_65 ) ) {
F_78 ( V_51 ) ;
return 0 ;
}
F_186 ( V_150 ) ;
V_147 = F_181 ( V_150 , V_51 ) ;
if ( ! V_147 ) {
struct V_47 * V_139 ;
V_139 = F_184 ( V_51 ) ;
if ( V_139 == V_150 ) {
goto V_128;
}
if ( ! V_139 )
goto V_128;
F_187 ( V_150 ) ;
V_150 = V_139 ;
goto V_152;
}
F_188 ( V_51 , V_150 , 0 ) ;
F_189 ( V_150 , V_147 -> V_54 ) ;
F_190 ( V_147 , V_150 , 0 ) ;
V_151 = 1 ;
F_78 ( V_147 ) ;
F_183 ( V_51 , V_147 ) ;
V_128:
F_187 ( V_150 ) ;
return V_151 ;
}
static void V_73 ( struct V_51 * V_51 )
{
while ( F_185 ( V_51 ) )
;
}
static int F_191 ( struct V_51 * V_51 )
{
int V_153 = V_51 -> V_50 . V_39 ;
int V_54 ;
V_54 = F_192 ( V_153 , V_51 -> V_66 -> V_69 ) ;
if ( V_153 < V_51 -> V_54 ) {
if ( V_54 >= V_51 -> V_54 )
return V_40 ;
} else if ( V_54 >= V_40 ) {
V_54 = F_193 ( V_51 -> V_66 -> V_69 ) ;
if ( V_54 >= V_51 -> V_54 )
return V_40 ;
}
V_51 -> V_50 . V_39 = V_54 ;
return V_54 ;
}
static int F_194 ( struct V_51 * V_51 )
{
struct V_51 * V_154 ;
int V_54 ;
while ( 1 ) {
V_54 = F_191 ( V_51 ) ;
if ( V_54 >= V_40 )
break;
V_154 = F_34 ( V_54 ) ;
if ( V_154 -> V_50 . V_32 . V_34 < V_51 -> V_50 . V_32 . V_33 )
break;
}
return V_54 ;
}
static void F_195 ( struct V_51 * V_51 )
{
int V_54 ;
if ( V_51 -> V_50 . V_38 & V_155 ) {
F_3 ( & V_51 -> V_50 . V_41 ) ;
if ( V_51 -> V_50 . V_38 & V_155 ) {
V_51 -> V_50 . V_38 |= V_156 ;
F_5 ( & V_51 -> V_50 . V_41 ) ;
return;
}
F_5 ( & V_51 -> V_50 . V_41 ) ;
}
V_51 -> V_50 . V_39 = V_51 -> V_54 ;
V_54 = F_194 ( V_51 ) ;
if ( V_54 >= V_40 )
return;
V_51 -> V_50 . V_38 = V_155 ;
F_196 ( & V_51 -> V_50 . V_42 , V_54 ) ;
}
static void F_197 ( void * V_157 )
{
struct V_22 * V_22 = V_157 ;
struct V_51 * V_51 , * V_158 ;
int V_144 ;
int V_54 ;
V_144 = V_22 -> V_39 ;
F_97 ( V_144 != F_175 () ) ;
V_51 = F_34 ( V_144 ) ;
V_158 = F_27 ( V_22 ) ;
V_159:
if ( F_54 ( V_51 ) ) {
F_3 ( & V_51 -> V_97 ) ;
F_185 ( V_51 ) ;
F_5 ( & V_51 -> V_97 ) ;
}
F_3 ( & V_22 -> V_41 ) ;
if ( V_22 -> V_38 & V_156 ) {
V_22 -> V_38 &= ~ V_156 ;
V_22 -> V_39 = V_158 -> V_54 ;
}
V_54 = F_194 ( V_158 ) ;
if ( V_54 >= V_40 )
V_22 -> V_38 &= ~ V_155 ;
F_5 ( & V_22 -> V_41 ) ;
if ( V_54 >= V_40 )
return;
if ( F_94 ( V_54 == V_51 -> V_54 ) )
goto V_159;
F_196 ( & V_22 -> V_42 , V_54 ) ;
}
static void V_43 ( struct V_160 * V_161 )
{
struct V_22 * V_22 = F_2 ( V_161 , struct V_22 , V_42 ) ;
F_197 ( V_22 ) ;
}
static void V_75 ( struct V_51 * V_76 )
{
int V_144 = V_76 -> V_54 , V_54 ;
bool V_162 = false ;
struct V_47 * V_63 ;
struct V_51 * V_158 ;
if ( F_106 ( ! F_42 ( V_76 ) ) )
return;
F_198 () ;
#ifdef F_19
if ( F_100 ( V_163 ) ) {
F_195 ( V_76 ) ;
return;
}
#endif
F_91 (cpu, this_rq->rd->rto_mask) {
if ( V_144 == V_54 )
continue;
V_158 = F_34 ( V_54 ) ;
if ( V_158 -> V_50 . V_32 . V_34 >=
V_76 -> V_50 . V_32 . V_33 )
continue;
F_182 ( V_76 , V_158 ) ;
V_63 = F_172 ( V_158 , V_144 ) ;
if ( V_63 && ( V_63 -> V_65 < V_76 -> V_50 . V_32 . V_33 ) ) {
F_124 ( V_63 == V_158 -> V_33 ) ;
F_124 ( ! F_166 ( V_63 ) ) ;
if ( V_63 -> V_65 < V_158 -> V_33 -> V_65 )
goto V_96;
V_162 = true ;
F_188 ( V_158 , V_63 , 0 ) ;
F_189 ( V_63 , V_144 ) ;
F_190 ( V_76 , V_63 , 0 ) ;
}
V_96:
F_183 ( V_76 , V_158 ) ;
}
if ( V_162 )
F_78 ( V_76 ) ;
}
static void F_199 ( struct V_51 * V_51 , struct V_47 * V_63 )
{
if ( ! F_170 ( V_51 , V_63 ) &&
! F_159 ( V_51 -> V_33 ) &&
V_63 -> V_71 > 1 &&
( F_200 ( V_51 -> V_33 ) || F_153 ( V_51 -> V_33 ) ) &&
( V_51 -> V_33 -> V_71 < 2 ||
V_51 -> V_33 -> V_65 <= V_63 -> V_65 ) )
V_73 ( V_51 ) ;
}
static void F_201 ( struct V_51 * V_51 )
{
if ( V_51 -> V_50 . V_36 )
F_44 ( V_51 ) ;
F_98 ( V_51 ) ;
F_120 ( & V_51 -> V_66 -> V_109 , V_51 -> V_54 , V_51 -> V_50 . V_32 . V_33 ) ;
}
static void F_202 ( struct V_51 * V_51 )
{
if ( V_51 -> V_50 . V_36 )
F_48 ( V_51 ) ;
F_93 ( V_51 ) ;
F_120 ( & V_51 -> V_66 -> V_109 , V_51 -> V_54 , V_164 ) ;
}
static void F_203 ( struct V_51 * V_51 , struct V_47 * V_63 )
{
if ( ! F_166 ( V_63 ) || V_51 -> V_50 . V_80 )
return;
F_59 ( V_51 ) ;
}
void T_4 F_204 ( void )
{
unsigned int V_25 ;
F_31 (i) {
F_205 ( & F_58 ( V_143 , V_25 ) ,
V_59 , F_39 ( V_25 ) ) ;
}
}
static void F_206 ( struct V_51 * V_51 , struct V_47 * V_63 )
{
if ( F_166 ( V_63 ) && V_51 -> V_33 != V_63 ) {
#ifdef V_31
if ( V_63 -> V_71 > 1 && V_51 -> V_50 . V_36 )
F_56 ( V_51 ) ;
#endif
if ( V_63 -> V_65 < V_51 -> V_33 -> V_65 )
F_78 ( V_51 ) ;
}
}
static void
F_207 ( struct V_51 * V_51 , struct V_47 * V_63 , int V_165 )
{
if ( ! F_166 ( V_63 ) )
return;
if ( V_51 -> V_33 == V_63 ) {
#ifdef V_31
if ( V_165 < V_63 -> V_65 )
F_59 ( V_51 ) ;
if ( V_63 -> V_65 > V_51 -> V_50 . V_32 . V_33 )
F_78 ( V_51 ) ;
#else
if ( V_165 < V_63 -> V_65 )
F_78 ( V_51 ) ;
#endif
} else {
if ( V_63 -> V_65 < V_51 -> V_33 -> V_65 )
F_78 ( V_51 ) ;
}
}
static void F_208 ( struct V_51 * V_51 , struct V_47 * V_63 )
{
unsigned long V_166 , V_167 ;
V_166 = F_209 ( V_63 , V_168 ) ;
V_167 = F_210 ( V_63 , V_168 ) ;
if ( V_166 != V_169 ) {
unsigned long V_34 ;
if ( V_63 -> V_50 . V_170 != V_171 ) {
V_63 -> V_50 . V_123 ++ ;
V_63 -> V_50 . V_170 = V_171 ;
}
V_34 = F_211 ( F_102 ( V_166 , V_167 ) , V_172 / V_173 ) ;
if ( V_63 -> V_50 . V_123 > V_34 )
V_63 -> V_174 . V_175 = V_63 -> V_101 . V_106 ;
}
}
static inline void F_208 ( struct V_51 * V_51 , struct V_47 * V_63 ) { }
static void F_212 ( struct V_51 * V_51 , struct V_47 * V_63 , int V_176 )
{
struct V_48 * V_49 = & V_63 -> V_50 ;
F_108 ( V_51 ) ;
F_208 ( V_51 , V_63 ) ;
if ( V_63 -> V_113 != V_114 )
return;
if ( -- V_63 -> V_50 . V_177 )
return;
V_63 -> V_50 . V_177 = V_178 ;
F_116 (rt_se) {
if ( V_49 -> V_58 . V_64 != V_49 -> V_58 . V_34 ) {
F_148 ( V_51 , V_63 , 0 ) ;
F_78 ( V_51 ) ;
return;
}
}
}
static void F_213 ( struct V_51 * V_51 )
{
struct V_47 * V_63 = V_51 -> V_33 ;
V_63 -> V_101 . V_102 = F_109 ( V_51 ) ;
F_64 ( V_51 , V_63 ) ;
}
static unsigned int F_214 ( struct V_51 * V_51 , struct V_47 * V_139 )
{
if ( V_139 -> V_113 == V_114 )
return V_178 ;
else
return 0 ;
}
static inline int F_215 ( struct V_52 * V_53 )
{
struct V_47 * V_179 , * V_63 ;
if ( F_72 ( V_53 ) )
return 0 ;
F_216 (g, p) {
if ( F_153 ( V_63 ) && V_52 ( V_63 ) == V_53 )
return 1 ;
}
return 0 ;
}
static int F_217 ( struct V_52 * V_53 , void * V_180 )
{
struct V_181 * V_182 = V_180 ;
struct V_52 * V_183 ;
unsigned long V_184 , V_185 = 0 ;
T_1 V_14 , V_15 ;
V_14 = F_37 ( V_53 -> V_4 . V_10 ) ;
V_15 = V_53 -> V_4 . V_16 ;
if ( V_53 == V_182 -> V_53 ) {
V_14 = V_182 -> V_10 ;
V_15 = V_182 -> V_16 ;
}
if ( V_15 > V_14 && V_15 != V_20 )
return - V_186 ;
if ( F_12 () && ! V_15 && F_215 ( V_53 ) )
return - V_187 ;
V_184 = F_218 ( V_14 , V_15 ) ;
if ( V_184 > F_218 ( F_219 () , F_220 () ) )
return - V_186 ;
F_221 (child, &tg->children, siblings) {
V_14 = F_37 ( V_183 -> V_4 . V_10 ) ;
V_15 = V_183 -> V_4 . V_16 ;
if ( V_183 == V_182 -> V_53 ) {
V_14 = V_182 -> V_10 ;
V_15 = V_182 -> V_16 ;
}
V_185 += F_218 ( V_14 , V_15 ) ;
}
if ( V_185 > V_184 )
return - V_186 ;
return 0 ;
}
static int F_222 ( struct V_52 * V_53 , T_1 V_14 , T_1 V_15 )
{
int V_151 ;
struct V_181 V_180 = {
. V_53 = V_53 ,
. V_10 = V_14 ,
. V_16 = V_15 ,
} ;
F_151 () ;
V_151 = F_223 ( F_217 , V_188 , & V_180 ) ;
F_155 () ;
return V_151 ;
}
static int F_224 ( struct V_52 * V_53 ,
T_1 V_10 , T_1 V_16 )
{
int V_25 , V_60 = 0 ;
if ( V_53 == & V_94 && V_16 == 0 )
return - V_186 ;
if ( V_10 == 0 )
return - V_186 ;
F_225 ( & V_189 ) ;
F_226 ( & V_190 ) ;
V_60 = F_222 ( V_53 , V_10 , V_16 ) ;
if ( V_60 )
goto V_191;
F_227 ( & V_53 -> V_4 . V_9 ) ;
V_53 -> V_4 . V_10 = F_8 ( V_10 ) ;
V_53 -> V_4 . V_16 = V_16 ;
F_31 (i) {
struct V_22 * V_22 = V_53 -> V_22 [ V_25 ] ;
F_3 ( & V_22 -> V_9 ) ;
V_22 -> V_16 = V_16 ;
F_5 ( & V_22 -> V_9 ) ;
}
F_228 ( & V_53 -> V_4 . V_9 ) ;
V_191:
F_229 ( & V_190 ) ;
F_230 ( & V_189 ) ;
return V_60 ;
}
int F_231 ( struct V_52 * V_53 , long V_192 )
{
T_1 V_16 , V_10 ;
V_10 = F_37 ( V_53 -> V_4 . V_10 ) ;
V_16 = ( T_1 ) V_192 * V_193 ;
if ( V_192 < 0 )
V_16 = V_20 ;
return F_224 ( V_53 , V_10 , V_16 ) ;
}
long F_232 ( struct V_52 * V_53 )
{
T_1 V_192 ;
if ( V_53 -> V_4 . V_16 == V_20 )
return - 1 ;
V_192 = V_53 -> V_4 . V_16 ;
F_233 ( V_192 , V_193 ) ;
return V_192 ;
}
int F_234 ( struct V_52 * V_53 , T_1 V_194 )
{
T_1 V_16 , V_10 ;
V_10 = V_194 * V_193 ;
V_16 = V_53 -> V_4 . V_16 ;
return F_224 ( V_53 , V_10 , V_16 ) ;
}
long F_235 ( struct V_52 * V_53 )
{
T_1 V_194 ;
V_194 = F_37 ( V_53 -> V_4 . V_10 ) ;
F_233 ( V_194 , V_193 ) ;
return V_194 ;
}
static int F_236 ( void )
{
int V_151 = 0 ;
F_225 ( & V_189 ) ;
F_226 ( & V_190 ) ;
V_151 = F_222 ( NULL , 0 , 0 ) ;
F_229 ( & V_190 ) ;
F_230 ( & V_189 ) ;
return V_151 ;
}
int F_237 ( struct V_52 * V_53 , struct V_47 * V_111 )
{
if ( F_153 ( V_111 ) && V_53 -> V_4 . V_16 == 0 )
return 0 ;
return 1 ;
}
static int F_236 ( void )
{
unsigned long V_115 ;
int V_25 ;
F_238 ( & V_61 . V_9 , V_115 ) ;
F_31 (i) {
struct V_22 * V_22 = & F_34 ( V_25 ) -> V_50 ;
F_3 ( & V_22 -> V_9 ) ;
V_22 -> V_16 = F_220 () ;
F_5 ( & V_22 -> V_9 ) ;
}
F_239 ( & V_61 . V_9 , V_115 ) ;
return 0 ;
}
static int F_240 ( void )
{
if ( V_195 <= 0 )
return - V_186 ;
if ( ( V_196 != V_20 ) &&
( V_196 > V_195 ) )
return - V_186 ;
return 0 ;
}
static void F_241 ( void )
{
V_61 . V_16 = F_220 () ;
V_61 . V_10 = F_8 ( F_219 () ) ;
}
int F_242 ( struct V_197 * V_198 , int V_199 ,
void T_5 * V_200 , T_6 * V_201 ,
T_7 * V_202 )
{
int V_203 , V_204 ;
static F_243 ( V_205 ) ;
int V_151 ;
F_225 ( & V_205 ) ;
V_203 = V_195 ;
V_204 = V_196 ;
V_151 = F_244 ( V_198 , V_199 , V_200 , V_201 , V_202 ) ;
if ( ! V_151 && V_199 ) {
V_151 = F_240 () ;
if ( V_151 )
goto V_206;
V_151 = F_245 () ;
if ( V_151 )
goto V_206;
V_151 = F_236 () ;
if ( V_151 )
goto V_206;
F_241 () ;
F_246 () ;
}
if ( 0 ) {
V_206:
V_195 = V_203 ;
V_196 = V_204 ;
}
F_230 ( & V_205 ) ;
return V_151 ;
}
int F_247 ( struct V_197 * V_198 , int V_199 ,
void T_5 * V_200 , T_6 * V_201 ,
T_7 * V_202 )
{
int V_151 ;
static F_243 ( V_205 ) ;
F_225 ( & V_205 ) ;
V_151 = F_244 ( V_198 , V_199 , V_200 , V_201 , V_202 ) ;
if ( ! V_151 && V_199 ) {
V_178 =
V_207 <= 0 ? V_208 :
F_248 ( V_207 ) ;
}
F_230 ( & V_205 ) ;
return V_151 ;
}
void F_249 ( struct V_209 * V_210 , int V_54 )
{
T_3 V_87 ;
struct V_22 * V_22 ;
F_151 () ;
F_95 (rt_rq, iter, cpu_rq(cpu))
F_250 ( V_210 , V_54 , V_22 ) ;
F_155 () ;
}
