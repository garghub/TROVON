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
V_21 -> V_40 = 0 ;
V_21 -> V_15 = 0 ;
F_8 ( & V_21 -> V_16 ) ;
}
static void F_21 ( struct V_4 * V_5 )
{
F_22 ( & V_5 -> V_6 ) ;
}
static inline struct V_41 * F_23 ( struct V_42 * V_43 )
{
#ifdef F_24
F_25 ( ! F_26 ( V_43 ) ) ;
#endif
return F_2 ( V_43 , struct V_41 , V_44 ) ;
}
static inline struct V_22 * F_27 ( struct V_21 * V_21 )
{
return V_21 -> V_22 ;
}
static inline struct V_21 * F_28 ( struct V_42 * V_43 )
{
return V_43 -> V_21 ;
}
static inline struct V_22 * F_29 ( struct V_42 * V_43 )
{
struct V_21 * V_21 = V_43 -> V_21 ;
return V_21 -> V_22 ;
}
void F_30 ( struct V_45 * V_46 )
{
int V_25 ;
if ( V_46 -> V_43 )
F_21 ( & V_46 -> V_4 ) ;
F_31 (i) {
if ( V_46 -> V_21 )
F_32 ( V_46 -> V_21 [ V_25 ] ) ;
if ( V_46 -> V_43 )
F_32 ( V_46 -> V_43 [ V_25 ] ) ;
}
F_32 ( V_46 -> V_21 ) ;
F_32 ( V_46 -> V_43 ) ;
}
void F_33 ( struct V_45 * V_46 , struct V_21 * V_21 ,
struct V_42 * V_43 , int V_47 ,
struct V_42 * V_48 )
{
struct V_22 * V_22 = F_34 ( V_47 ) ;
V_21 -> V_32 . V_33 = V_27 ;
V_21 -> V_49 = 0 ;
V_21 -> V_22 = V_22 ;
V_21 -> V_46 = V_46 ;
V_46 -> V_21 [ V_47 ] = V_21 ;
V_46 -> V_43 [ V_47 ] = V_43 ;
if ( ! V_43 )
return;
if ( ! V_48 )
V_43 -> V_21 = & V_22 -> V_44 ;
else
V_43 -> V_21 = V_48 -> V_50 ;
V_43 -> V_50 = V_21 ;
V_43 -> V_48 = V_48 ;
F_17 ( & V_43 -> V_51 ) ;
}
int F_35 ( struct V_45 * V_46 , struct V_45 * V_48 )
{
struct V_21 * V_21 ;
struct V_42 * V_43 ;
int V_25 ;
V_46 -> V_21 = F_36 ( sizeof( V_21 ) * V_52 , V_53 ) ;
if ( ! V_46 -> V_21 )
goto V_54;
V_46 -> V_43 = F_36 ( sizeof( V_43 ) * V_52 , V_53 ) ;
if ( ! V_46 -> V_43 )
goto V_54;
F_6 ( & V_46 -> V_4 ,
F_37 ( V_55 . V_10 ) , 0 ) ;
F_31 (i) {
V_21 = F_38 ( sizeof( struct V_21 ) ,
V_53 , F_39 ( V_25 ) ) ;
if ( ! V_21 )
goto V_54;
V_43 = F_38 ( sizeof( struct V_42 ) ,
V_53 , F_39 ( V_25 ) ) ;
if ( ! V_43 )
goto V_56;
F_16 ( V_21 , F_34 ( V_25 ) ) ;
V_21 -> V_15 = V_46 -> V_4 . V_15 ;
F_33 ( V_46 , V_21 , V_43 , V_25 , V_48 -> V_43 [ V_25 ] ) ;
}
return 1 ;
V_56:
F_32 ( V_21 ) ;
V_54:
return 0 ;
}
static inline struct V_41 * F_23 ( struct V_42 * V_43 )
{
return F_2 ( V_43 , struct V_41 , V_44 ) ;
}
static inline struct V_22 * F_27 ( struct V_21 * V_21 )
{
return F_2 ( V_21 , struct V_22 , V_44 ) ;
}
static inline struct V_22 * F_29 ( struct V_42 * V_43 )
{
struct V_41 * V_57 = F_23 ( V_43 ) ;
return F_40 ( V_57 ) ;
}
static inline struct V_21 * F_28 ( struct V_42 * V_43 )
{
struct V_22 * V_22 = F_29 ( V_43 ) ;
return & V_22 -> V_44 ;
}
void F_30 ( struct V_45 * V_46 ) { }
int F_35 ( struct V_45 * V_46 , struct V_45 * V_48 )
{
return 1 ;
}
static inline bool F_41 ( struct V_22 * V_22 , struct V_41 * V_58 )
{
return V_22 -> V_44 . V_32 . V_33 > V_58 -> V_59 ;
}
static inline int F_42 ( struct V_22 * V_22 )
{
return F_43 ( & V_22 -> V_60 -> V_61 ) ;
}
static inline void F_44 ( struct V_22 * V_22 )
{
if ( ! V_22 -> V_62 )
return;
F_45 ( V_22 -> V_47 , V_22 -> V_60 -> V_63 ) ;
F_46 () ;
F_47 ( & V_22 -> V_60 -> V_61 ) ;
}
static inline void F_48 ( struct V_22 * V_22 )
{
if ( ! V_22 -> V_62 )
return;
F_49 ( & V_22 -> V_60 -> V_61 ) ;
F_50 ( V_22 -> V_47 , V_22 -> V_60 -> V_63 ) ;
}
static void F_51 ( struct V_21 * V_21 )
{
if ( V_21 -> V_35 && V_21 -> V_64 > 1 ) {
if ( ! V_21 -> V_36 ) {
F_44 ( F_27 ( V_21 ) ) ;
V_21 -> V_36 = 1 ;
}
} else if ( V_21 -> V_36 ) {
F_48 ( F_27 ( V_21 ) ) ;
V_21 -> V_36 = 0 ;
}
}
static void F_52 ( struct V_42 * V_43 , struct V_21 * V_21 )
{
struct V_41 * V_57 ;
if ( ! F_26 ( V_43 ) )
return;
V_57 = F_23 ( V_43 ) ;
V_21 = & F_27 ( V_21 ) -> V_44 ;
V_21 -> V_64 ++ ;
if ( V_57 -> V_65 > 1 )
V_21 -> V_35 ++ ;
F_51 ( V_21 ) ;
}
static void F_53 ( struct V_42 * V_43 , struct V_21 * V_21 )
{
struct V_41 * V_57 ;
if ( ! F_26 ( V_43 ) )
return;
V_57 = F_23 ( V_43 ) ;
V_21 = & F_27 ( V_21 ) -> V_44 ;
V_21 -> V_64 -- ;
if ( V_57 -> V_65 > 1 )
V_21 -> V_35 -- ;
F_51 ( V_21 ) ;
}
static inline int F_54 ( struct V_22 * V_22 )
{
return ! F_55 ( & V_22 -> V_44 . V_37 ) ;
}
static inline void F_56 ( struct V_22 * V_22 )
{
V_22 -> V_66 = F_54 ( V_22 ) ;
}
static void F_57 ( struct V_22 * V_22 , struct V_41 * V_57 )
{
F_58 ( & V_57 -> V_37 , & V_22 -> V_44 . V_37 ) ;
F_59 ( & V_57 -> V_37 , V_57 -> V_59 ) ;
F_60 ( & V_57 -> V_37 , & V_22 -> V_44 . V_37 ) ;
if ( V_57 -> V_59 < V_22 -> V_44 . V_32 . V_34 )
V_22 -> V_44 . V_32 . V_34 = V_57 -> V_59 ;
}
static void F_61 ( struct V_22 * V_22 , struct V_41 * V_57 )
{
F_58 ( & V_57 -> V_37 , & V_22 -> V_44 . V_37 ) ;
if ( F_54 ( V_22 ) ) {
V_57 = F_62 ( & V_22 -> V_44 . V_37 ,
struct V_41 , V_37 ) ;
V_22 -> V_44 . V_32 . V_34 = V_57 -> V_59 ;
} else
V_22 -> V_44 . V_32 . V_34 = V_27 ;
}
static inline void F_57 ( struct V_22 * V_22 , struct V_41 * V_57 )
{
}
static inline void F_61 ( struct V_22 * V_22 , struct V_41 * V_57 )
{
}
static inline
void F_52 ( struct V_42 * V_43 , struct V_21 * V_21 )
{
}
static inline
void F_53 ( struct V_42 * V_43 , struct V_21 * V_21 )
{
}
static inline bool F_41 ( struct V_22 * V_22 , struct V_41 * V_58 )
{
return false ;
}
static inline int F_63 ( struct V_22 * V_67 )
{
return 0 ;
}
static inline void F_56 ( struct V_22 * V_22 )
{
}
static inline int F_64 ( struct V_42 * V_43 )
{
return ! F_65 ( & V_43 -> V_51 ) ;
}
static inline T_2 F_66 ( struct V_21 * V_21 )
{
if ( ! V_21 -> V_46 )
return V_20 ;
return V_21 -> V_15 ;
}
static inline T_2 F_67 ( struct V_21 * V_21 )
{
return F_37 ( V_21 -> V_46 -> V_4 . V_10 ) ;
}
static inline struct V_45 * F_68 ( struct V_45 * V_46 )
{
do {
V_46 = F_69 ( V_46 -> V_68 . V_34 ,
F_70 ( struct V_45 ) , V_68 ) ;
} while ( & V_46 -> V_68 != & V_69 && F_71 ( V_46 ) );
if ( & V_46 -> V_68 == & V_69 )
V_46 = NULL ;
return V_46 ;
}
static inline struct V_21 * F_72 ( struct V_42 * V_43 )
{
return V_43 -> V_50 ;
}
static void F_73 ( struct V_21 * V_21 )
{
struct V_41 * V_33 = F_27 ( V_21 ) -> V_33 ;
struct V_22 * V_22 = F_27 ( V_21 ) ;
struct V_42 * V_43 ;
int V_47 = F_74 ( V_22 ) ;
V_43 = V_21 -> V_46 -> V_43 [ V_47 ] ;
if ( V_21 -> V_70 ) {
if ( ! V_43 )
F_75 ( V_21 ) ;
else if ( ! F_64 ( V_43 ) )
F_76 ( V_43 , false ) ;
if ( V_21 -> V_32 . V_33 < V_33 -> V_59 )
F_77 ( V_22 ) ;
}
}
static void F_78 ( struct V_21 * V_21 )
{
struct V_42 * V_43 ;
int V_47 = F_74 ( F_27 ( V_21 ) ) ;
V_43 = V_21 -> V_46 -> V_43 [ V_47 ] ;
if ( ! V_43 )
F_79 ( V_21 ) ;
else if ( F_64 ( V_43 ) )
F_80 ( V_43 ) ;
}
static inline int F_81 ( struct V_21 * V_21 )
{
return V_21 -> V_40 && ! V_21 -> V_49 ;
}
static int F_82 ( struct V_42 * V_43 )
{
struct V_21 * V_21 = F_72 ( V_43 ) ;
struct V_41 * V_57 ;
if ( V_21 )
return ! ! V_21 -> V_49 ;
V_57 = F_23 ( V_43 ) ;
return V_57 -> V_59 != V_57 -> V_71 ;
}
static inline const struct V_72 * F_83 ( void )
{
return V_67 () -> V_60 -> V_73 ;
}
static inline const struct V_72 * F_83 ( void )
{
return V_74 ;
}
static inline
struct V_21 * F_84 ( struct V_4 * V_5 , int V_47 )
{
return F_2 ( V_5 , struct V_45 , V_4 ) -> V_21 [ V_47 ] ;
}
static inline struct V_4 * F_85 ( struct V_21 * V_21 )
{
return & V_21 -> V_46 -> V_4 ;
}
static inline T_2 F_66 ( struct V_21 * V_21 )
{
return V_21 -> V_15 ;
}
static inline T_2 F_67 ( struct V_21 * V_21 )
{
return F_37 ( V_55 . V_10 ) ;
}
static inline struct V_21 * F_72 ( struct V_42 * V_43 )
{
return NULL ;
}
static inline void F_73 ( struct V_21 * V_21 )
{
struct V_22 * V_22 = F_27 ( V_21 ) ;
if ( ! V_21 -> V_70 )
return;
F_75 ( V_21 ) ;
F_77 ( V_22 ) ;
}
static inline void F_78 ( struct V_21 * V_21 )
{
F_79 ( V_21 ) ;
}
static inline int F_81 ( struct V_21 * V_21 )
{
return V_21 -> V_40 ;
}
static inline const struct V_72 * F_83 ( void )
{
return V_74 ;
}
static inline
struct V_21 * F_84 ( struct V_4 * V_5 , int V_47 )
{
return & F_34 ( V_47 ) -> V_44 ;
}
static inline struct V_4 * F_85 ( struct V_21 * V_21 )
{
return & V_55 ;
}
bool F_86 ( struct V_21 * V_21 )
{
struct V_4 * V_5 = F_85 ( V_21 ) ;
return ( F_12 ( & V_5 -> V_6 ) ||
V_21 -> V_39 < V_5 -> V_15 ) ;
}
static int F_87 ( struct V_21 * V_21 )
{
struct V_4 * V_5 = F_85 ( V_21 ) ;
struct V_75 * V_60 = F_27 ( V_21 ) -> V_60 ;
int V_25 , V_76 , V_77 = 0 ;
T_2 V_10 ;
V_76 = F_88 ( V_60 -> V_73 ) ;
F_13 ( & V_5 -> V_16 ) ;
V_10 = F_37 ( V_5 -> V_10 ) ;
F_89 (i, rd->span) {
struct V_21 * V_78 = F_84 ( V_5 , V_25 ) ;
T_3 V_79 ;
if ( V_78 == V_21 )
continue;
F_13 ( & V_78 -> V_16 ) ;
if ( V_78 -> V_15 == V_20 )
goto V_34;
V_79 = V_78 -> V_15 - V_78 -> V_39 ;
if ( V_79 > 0 ) {
V_79 = F_90 ( ( T_2 ) V_79 , V_76 ) ;
if ( V_21 -> V_15 + V_79 > V_10 )
V_79 = V_10 - V_21 -> V_15 ;
V_78 -> V_15 -= V_79 ;
V_21 -> V_15 += V_79 ;
V_77 = 1 ;
if ( V_21 -> V_15 == V_10 ) {
F_15 ( & V_78 -> V_16 ) ;
break;
}
}
V_34:
F_15 ( & V_78 -> V_16 ) ;
}
F_15 ( & V_5 -> V_16 ) ;
return V_77 ;
}
static void F_91 ( struct V_22 * V_22 )
{
struct V_75 * V_60 = V_22 -> V_60 ;
T_4 V_78 ;
struct V_21 * V_21 ;
if ( F_92 ( ! V_80 ) )
return;
F_93 (rt_rq, iter, rq) {
struct V_4 * V_5 = F_85 ( V_21 ) ;
T_3 V_81 ;
int V_25 ;
F_13 ( & V_5 -> V_16 ) ;
F_13 ( & V_21 -> V_16 ) ;
if ( V_21 -> V_15 == V_20 ||
V_21 -> V_15 == V_5 -> V_15 )
goto V_82;
F_15 ( & V_21 -> V_16 ) ;
V_81 = V_5 -> V_15 - V_21 -> V_15 ;
F_89 (i, rd->span) {
struct V_21 * V_78 = F_84 ( V_5 , V_25 ) ;
T_3 V_79 ;
if ( V_78 == V_21 || V_78 -> V_15 == V_20 )
continue;
F_13 ( & V_78 -> V_16 ) ;
if ( V_81 > 0 ) {
V_79 = F_94 ( T_3 , V_78 -> V_15 , V_81 ) ;
V_78 -> V_15 -= V_79 ;
V_81 -= V_79 ;
} else {
V_78 -> V_15 -= V_81 ;
V_81 -= V_81 ;
}
F_15 ( & V_78 -> V_16 ) ;
if ( ! V_81 )
break;
}
F_13 ( & V_21 -> V_16 ) ;
F_95 ( V_81 ) ;
V_82:
V_21 -> V_15 = V_20 ;
V_21 -> V_40 = 0 ;
F_15 ( & V_21 -> V_16 ) ;
F_15 ( & V_5 -> V_16 ) ;
F_73 ( V_21 ) ;
}
}
static void F_96 ( struct V_22 * V_22 )
{
T_4 V_78 ;
struct V_21 * V_21 ;
if ( F_92 ( ! V_80 ) )
return;
F_93 (rt_rq, iter, rq) {
struct V_4 * V_5 = F_85 ( V_21 ) ;
F_13 ( & V_5 -> V_16 ) ;
F_13 ( & V_21 -> V_16 ) ;
V_21 -> V_15 = V_5 -> V_15 ;
V_21 -> V_39 = 0 ;
V_21 -> V_40 = 0 ;
F_15 ( & V_21 -> V_16 ) ;
F_15 ( & V_5 -> V_16 ) ;
}
}
static int F_97 ( struct V_21 * V_21 )
{
int V_77 = 0 ;
if ( ! F_98 ( V_83 ) )
return V_77 ;
if ( V_21 -> V_39 > V_21 -> V_15 ) {
F_15 ( & V_21 -> V_16 ) ;
V_77 = F_87 ( V_21 ) ;
F_13 ( & V_21 -> V_16 ) ;
}
return V_77 ;
}
static inline int F_97 ( struct V_21 * V_21 )
{
return 0 ;
}
static int F_5 ( struct V_4 * V_5 , int V_8 )
{
int V_25 , V_9 = 1 , V_84 = 0 ;
const struct V_72 * V_73 ;
V_73 = F_83 () ;
#ifdef F_99
if ( V_5 == & V_85 . V_4 )
V_73 = V_74 ;
#endif
F_89 (i, span) {
int V_86 = 0 ;
struct V_21 * V_21 = F_84 ( V_5 , V_25 ) ;
struct V_22 * V_22 = F_27 ( V_21 ) ;
F_13 ( & V_22 -> V_87 ) ;
if ( V_21 -> V_39 ) {
T_2 V_14 ;
F_13 ( & V_21 -> V_16 ) ;
if ( V_21 -> V_40 )
F_97 ( V_21 ) ;
V_14 = V_21 -> V_15 ;
V_21 -> V_39 -= F_100 ( V_21 -> V_39 , V_8 * V_14 ) ;
if ( V_21 -> V_40 && V_21 -> V_39 < V_14 ) {
V_21 -> V_40 = 0 ;
V_86 = 1 ;
if ( V_21 -> V_70 && V_22 -> V_33 == V_22 -> V_9 )
F_101 ( V_22 , false ) ;
}
if ( V_21 -> V_39 || V_21 -> V_70 )
V_9 = 0 ;
F_15 ( & V_21 -> V_16 ) ;
} else if ( V_21 -> V_70 ) {
V_9 = 0 ;
if ( ! F_81 ( V_21 ) )
V_86 = 1 ;
}
if ( V_21 -> V_40 )
V_84 = 1 ;
if ( V_86 )
F_73 ( V_21 ) ;
F_15 ( & V_22 -> V_87 ) ;
}
if ( ! V_84 && ( ! F_11 () || V_5 -> V_15 == V_20 ) )
return 1 ;
return V_9 ;
}
static inline int F_102 ( struct V_42 * V_43 )
{
#ifdef F_99
struct V_21 * V_21 = F_72 ( V_43 ) ;
if ( V_21 )
return V_21 -> V_32 . V_33 ;
#endif
return F_23 ( V_43 ) -> V_59 ;
}
static int F_103 ( struct V_21 * V_21 )
{
T_2 V_14 = F_66 ( V_21 ) ;
if ( V_21 -> V_40 )
return F_81 ( V_21 ) ;
if ( V_14 >= F_67 ( V_21 ) )
return 0 ;
F_97 ( V_21 ) ;
V_14 = F_66 ( V_21 ) ;
if ( V_14 == V_20 )
return 0 ;
if ( V_21 -> V_39 > V_14 ) {
struct V_4 * V_5 = F_85 ( V_21 ) ;
if ( F_104 ( V_5 -> V_15 ) ) {
V_21 -> V_40 = 1 ;
F_105 ( L_1 ) ;
} else {
V_21 -> V_39 = 0 ;
}
if ( F_81 ( V_21 ) ) {
F_78 ( V_21 ) ;
return 1 ;
}
}
return 0 ;
}
static void F_106 ( struct V_22 * V_22 )
{
struct V_41 * V_33 = V_22 -> V_33 ;
struct V_42 * V_43 = & V_33 -> V_44 ;
T_2 V_88 ;
if ( V_33 -> V_89 != & V_90 )
return;
V_88 = F_107 ( V_22 ) - V_33 -> V_91 . V_92 ;
if ( F_92 ( ( T_3 ) V_88 <= 0 ) )
return;
F_108 ( V_33 -> V_91 . V_93 . V_94 ,
F_109 ( V_33 -> V_91 . V_93 . V_94 , V_88 ) ) ;
V_33 -> V_91 . V_95 += V_88 ;
F_110 ( V_33 , V_88 ) ;
V_33 -> V_91 . V_92 = F_107 ( V_22 ) ;
F_111 ( V_33 , V_88 ) ;
F_112 ( V_22 , V_88 ) ;
if ( ! F_11 () )
return;
F_113 (rt_se) {
struct V_21 * V_21 = F_28 ( V_43 ) ;
if ( F_66 ( V_21 ) != V_20 ) {
F_13 ( & V_21 -> V_16 ) ;
V_21 -> V_39 += V_88 ;
if ( F_103 ( V_21 ) )
F_77 ( V_22 ) ;
F_15 ( & V_21 -> V_16 ) ;
}
}
}
static void
F_79 ( struct V_21 * V_21 )
{
struct V_22 * V_22 = F_27 ( V_21 ) ;
F_95 ( & V_22 -> V_44 != V_21 ) ;
if ( ! V_21 -> V_38 )
return;
F_95 ( ! V_22 -> V_96 ) ;
F_114 ( V_22 , V_21 -> V_70 ) ;
V_21 -> V_38 = 0 ;
}
static void
F_75 ( struct V_21 * V_21 )
{
struct V_22 * V_22 = F_27 ( V_21 ) ;
F_95 ( & V_22 -> V_44 != V_21 ) ;
if ( V_21 -> V_38 )
return;
if ( F_81 ( V_21 ) || ! V_21 -> V_70 )
return;
F_115 ( V_22 , V_21 -> V_70 ) ;
V_21 -> V_38 = 1 ;
}
static void
F_116 ( struct V_21 * V_21 , int V_59 , int V_97 )
{
struct V_22 * V_22 = F_27 ( V_21 ) ;
#ifdef F_99
if ( & V_22 -> V_44 != V_21 )
return;
#endif
if ( V_22 -> V_62 && V_59 < V_97 )
F_117 ( & V_22 -> V_60 -> V_98 , V_22 -> V_47 , V_59 ) ;
}
static void
F_118 ( struct V_21 * V_21 , int V_59 , int V_97 )
{
struct V_22 * V_22 = F_27 ( V_21 ) ;
#ifdef F_99
if ( & V_22 -> V_44 != V_21 )
return;
#endif
if ( V_22 -> V_62 && V_21 -> V_32 . V_33 != V_97 )
F_117 ( & V_22 -> V_60 -> V_98 , V_22 -> V_47 , V_21 -> V_32 . V_33 ) ;
}
static inline
void F_116 ( struct V_21 * V_21 , int V_59 , int V_97 ) {}
static inline
void F_118 ( struct V_21 * V_21 , int V_59 , int V_97 ) {}
static void
F_119 ( struct V_21 * V_21 , int V_59 )
{
int V_97 = V_21 -> V_32 . V_33 ;
if ( V_59 < V_97 )
V_21 -> V_32 . V_33 = V_59 ;
F_116 ( V_21 , V_59 , V_97 ) ;
}
static void
F_120 ( struct V_21 * V_21 , int V_59 )
{
int V_97 = V_21 -> V_32 . V_33 ;
if ( V_21 -> V_70 ) {
F_121 ( V_59 < V_97 ) ;
if ( V_59 == V_97 ) {
struct V_23 * V_24 = & V_21 -> V_26 ;
V_21 -> V_32 . V_33 =
F_122 ( V_24 -> V_29 ) ;
}
} else
V_21 -> V_32 . V_33 = V_27 ;
F_118 ( V_21 , V_59 , V_97 ) ;
}
static inline void F_119 ( struct V_21 * V_21 , int V_59 ) {}
static inline void F_120 ( struct V_21 * V_21 , int V_59 ) {}
static void
F_123 ( struct V_42 * V_43 , struct V_21 * V_21 )
{
if ( F_82 ( V_43 ) )
V_21 -> V_49 ++ ;
if ( V_21 -> V_46 )
F_10 ( & V_21 -> V_46 -> V_4 ) ;
}
static void
F_124 ( struct V_42 * V_43 , struct V_21 * V_21 )
{
if ( F_82 ( V_43 ) )
V_21 -> V_49 -- ;
F_121 ( ! V_21 -> V_70 && V_21 -> V_49 ) ;
}
static void
F_123 ( struct V_42 * V_43 , struct V_21 * V_21 )
{
F_10 ( & V_55 ) ;
}
static inline
void F_124 ( struct V_42 * V_43 , struct V_21 * V_21 ) {}
static inline
unsigned int F_125 ( struct V_42 * V_43 )
{
struct V_21 * V_99 = F_72 ( V_43 ) ;
if ( V_99 )
return V_99 -> V_70 ;
else
return 1 ;
}
static inline
void F_126 ( struct V_42 * V_43 , struct V_21 * V_21 )
{
int V_59 = F_102 ( V_43 ) ;
F_121 ( ! F_127 ( V_59 ) ) ;
V_21 -> V_70 += F_125 ( V_43 ) ;
F_119 ( V_21 , V_59 ) ;
F_52 ( V_43 , V_21 ) ;
F_123 ( V_43 , V_21 ) ;
}
static inline
void F_128 ( struct V_42 * V_43 , struct V_21 * V_21 )
{
F_121 ( ! F_127 ( F_102 ( V_43 ) ) ) ;
F_121 ( ! V_21 -> V_70 ) ;
V_21 -> V_70 -= F_125 ( V_43 ) ;
F_120 ( V_21 , F_102 ( V_43 ) ) ;
F_53 ( V_43 , V_21 ) ;
F_124 ( V_43 , V_21 ) ;
}
static void F_129 ( struct V_42 * V_43 , bool V_100 )
{
struct V_21 * V_21 = F_28 ( V_43 ) ;
struct V_23 * V_24 = & V_21 -> V_26 ;
struct V_21 * V_99 = F_72 ( V_43 ) ;
struct V_101 * V_28 = V_24 -> V_28 + F_102 ( V_43 ) ;
if ( V_99 && ( F_81 ( V_99 ) || ! V_99 -> V_70 ) )
return;
if ( V_100 )
F_130 ( & V_43 -> V_51 , V_28 ) ;
else
F_131 ( & V_43 -> V_51 , V_28 ) ;
F_19 ( F_102 ( V_43 ) , V_24 -> V_29 ) ;
F_126 ( V_43 , V_21 ) ;
}
static void F_132 ( struct V_42 * V_43 )
{
struct V_21 * V_21 = F_28 ( V_43 ) ;
struct V_23 * V_24 = & V_21 -> V_26 ;
F_133 ( & V_43 -> V_51 ) ;
if ( F_65 ( V_24 -> V_28 + F_102 ( V_43 ) ) )
F_18 ( F_102 ( V_43 ) , V_24 -> V_29 ) ;
F_128 ( V_43 , V_21 ) ;
}
static void F_134 ( struct V_42 * V_43 )
{
struct V_42 * V_102 = NULL ;
F_113 (rt_se) {
V_43 -> V_102 = V_102 ;
V_102 = V_43 ;
}
F_79 ( F_28 ( V_102 ) ) ;
for ( V_43 = V_102 ; V_43 ; V_43 = V_43 -> V_102 ) {
if ( F_64 ( V_43 ) )
F_132 ( V_43 ) ;
}
}
static void F_76 ( struct V_42 * V_43 , bool V_100 )
{
struct V_22 * V_22 = F_29 ( V_43 ) ;
F_134 ( V_43 ) ;
F_113 (rt_se)
F_129 ( V_43 , V_100 ) ;
F_75 ( & V_22 -> V_44 ) ;
}
static void F_80 ( struct V_42 * V_43 )
{
struct V_22 * V_22 = F_29 ( V_43 ) ;
F_134 ( V_43 ) ;
F_113 (rt_se) {
struct V_21 * V_21 = F_72 ( V_43 ) ;
if ( V_21 && V_21 -> V_70 )
F_129 ( V_43 , false ) ;
}
F_75 ( & V_22 -> V_44 ) ;
}
static void
F_135 ( struct V_22 * V_22 , struct V_41 * V_57 , int V_103 )
{
struct V_42 * V_43 = & V_57 -> V_44 ;
if ( V_103 & V_104 )
V_43 -> V_105 = 0 ;
F_76 ( V_43 , V_103 & V_106 ) ;
if ( ! F_136 ( V_22 , V_57 ) && V_57 -> V_65 > 1 )
F_57 ( V_22 , V_57 ) ;
}
static void F_137 ( struct V_22 * V_22 , struct V_41 * V_57 , int V_103 )
{
struct V_42 * V_43 = & V_57 -> V_44 ;
F_106 ( V_22 ) ;
F_80 ( V_43 ) ;
F_61 ( V_22 , V_57 ) ;
}
static void
F_138 ( struct V_21 * V_21 , struct V_42 * V_43 , int V_100 )
{
if ( F_64 ( V_43 ) ) {
struct V_23 * V_24 = & V_21 -> V_26 ;
struct V_101 * V_28 = V_24 -> V_28 + F_102 ( V_43 ) ;
if ( V_100 )
F_139 ( & V_43 -> V_51 , V_28 ) ;
else
F_140 ( & V_43 -> V_51 , V_28 ) ;
}
}
static void F_141 ( struct V_22 * V_22 , struct V_41 * V_57 , int V_100 )
{
struct V_42 * V_43 = & V_57 -> V_44 ;
struct V_21 * V_21 ;
F_113 (rt_se) {
V_21 = F_28 ( V_43 ) ;
F_138 ( V_21 , V_43 , V_100 ) ;
}
}
static void F_142 ( struct V_22 * V_22 )
{
F_141 ( V_22 , V_22 -> V_33 , 0 ) ;
}
static int
F_143 ( struct V_41 * V_57 , int V_47 , int V_107 , int V_103 )
{
struct V_41 * V_33 ;
struct V_22 * V_22 ;
if ( V_107 != V_108 && V_107 != V_109 )
goto V_110;
V_22 = F_34 ( V_47 ) ;
F_144 () ;
V_33 = F_145 ( V_22 -> V_33 ) ;
if ( V_33 && F_92 ( F_146 ( V_33 ) ) &&
( V_33 -> V_65 < 2 ||
V_33 -> V_59 <= V_57 -> V_59 ) ) {
int V_111 = F_147 ( V_57 ) ;
if ( V_111 != - 1 &&
V_57 -> V_59 < F_34 ( V_111 ) -> V_44 . V_32 . V_33 )
V_47 = V_111 ;
}
F_148 () ;
V_110:
return V_47 ;
}
static void F_149 ( struct V_22 * V_22 , struct V_41 * V_57 )
{
if ( V_22 -> V_33 -> V_65 == 1 ||
! F_150 ( & V_22 -> V_60 -> V_98 , V_22 -> V_33 , NULL ) )
return;
if ( V_57 -> V_65 != 1
&& F_150 ( & V_22 -> V_60 -> V_98 , V_57 , NULL ) )
return;
F_141 ( V_22 , V_57 , 1 ) ;
F_77 ( V_22 ) ;
}
static void F_151 ( struct V_22 * V_22 , struct V_41 * V_57 , int V_103 )
{
if ( V_57 -> V_59 < V_22 -> V_33 -> V_59 ) {
F_77 ( V_22 ) ;
return;
}
#ifdef V_31
if ( V_57 -> V_59 == V_22 -> V_33 -> V_59 && ! F_152 ( V_22 -> V_33 ) )
F_149 ( V_22 , V_57 ) ;
#endif
}
static struct V_42 * F_153 ( struct V_22 * V_22 ,
struct V_21 * V_21 )
{
struct V_23 * V_24 = & V_21 -> V_26 ;
struct V_42 * V_34 = NULL ;
struct V_101 * V_28 ;
int V_112 ;
V_112 = F_122 ( V_24 -> V_29 ) ;
F_95 ( V_112 >= V_27 ) ;
V_28 = V_24 -> V_28 + V_112 ;
V_34 = F_154 ( V_28 -> V_34 , struct V_42 , V_51 ) ;
return V_34 ;
}
static struct V_41 * F_155 ( struct V_22 * V_22 )
{
struct V_42 * V_43 ;
struct V_41 * V_57 ;
struct V_21 * V_21 = & V_22 -> V_44 ;
do {
V_43 = F_153 ( V_22 , V_21 ) ;
F_95 ( ! V_43 ) ;
V_21 = F_72 ( V_43 ) ;
} while ( V_21 );
V_57 = F_23 ( V_43 ) ;
V_57 -> V_91 . V_92 = F_107 ( V_22 ) ;
return V_57 ;
}
static struct V_41 *
F_156 ( struct V_22 * V_22 , struct V_41 * V_58 )
{
struct V_41 * V_57 ;
struct V_21 * V_21 = & V_22 -> V_44 ;
if ( F_41 ( V_22 , V_58 ) ) {
F_63 ( V_22 ) ;
if ( F_92 ( ( V_22 -> V_113 && F_157 ( V_22 -> V_113 ) ) ||
V_22 -> V_114 . V_115 ) )
return V_116 ;
}
if ( V_58 -> V_89 == & V_90 )
F_106 ( V_22 ) ;
if ( ! V_21 -> V_38 )
return NULL ;
F_158 ( V_22 , V_58 ) ;
V_57 = F_155 ( V_22 ) ;
F_61 ( V_22 , V_57 ) ;
F_56 ( V_22 ) ;
return V_57 ;
}
static void F_159 ( struct V_22 * V_22 , struct V_41 * V_57 )
{
F_106 ( V_22 ) ;
if ( F_64 ( & V_57 -> V_44 ) && V_57 -> V_65 > 1 )
F_57 ( V_22 , V_57 ) ;
}
static int F_160 ( struct V_22 * V_22 , struct V_41 * V_57 , int V_47 )
{
if ( ! F_161 ( V_22 , V_57 ) &&
F_162 ( V_47 , F_163 ( V_57 ) ) )
return 1 ;
return 0 ;
}
static struct V_41 * F_164 ( struct V_22 * V_22 , int V_47 )
{
struct V_117 * V_100 = & V_22 -> V_44 . V_37 ;
struct V_41 * V_57 ;
if ( ! F_54 ( V_22 ) )
return NULL ;
F_165 (p, head, pushable_tasks) {
if ( F_160 ( V_22 , V_57 , V_47 ) )
return V_57 ;
}
return NULL ;
}
static int F_147 ( struct V_41 * V_118 )
{
struct V_119 * V_120 ;
struct V_72 * V_121 = F_166 ( V_122 ) ;
int V_123 = F_167 () ;
int V_47 = F_168 ( V_118 ) ;
if ( F_92 ( ! V_121 ) )
return - 1 ;
if ( V_118 -> V_65 == 1 )
return - 1 ;
if ( ! F_150 ( & F_40 ( V_118 ) -> V_60 -> V_98 , V_118 , V_121 ) )
return - 1 ;
if ( F_162 ( V_47 , V_121 ) )
return V_47 ;
if ( ! F_162 ( V_123 , V_121 ) )
V_123 = - 1 ;
F_144 () ;
F_169 (cpu, sd) {
if ( V_120 -> V_103 & V_124 ) {
int V_125 ;
if ( V_123 != - 1 &&
F_162 ( V_123 , F_170 ( V_120 ) ) ) {
F_148 () ;
return V_123 ;
}
V_125 = F_171 ( V_121 ,
F_170 ( V_120 ) ) ;
if ( V_125 < V_52 ) {
F_148 () ;
return V_125 ;
}
}
}
F_148 () ;
if ( V_123 != - 1 )
return V_123 ;
V_47 = F_172 ( V_121 ) ;
if ( V_47 < V_52 )
return V_47 ;
return - 1 ;
}
static struct V_22 * F_173 ( struct V_41 * V_118 , struct V_22 * V_22 )
{
struct V_22 * V_126 = NULL ;
int V_127 ;
int V_47 ;
for ( V_127 = 0 ; V_127 < V_128 ; V_127 ++ ) {
V_47 = F_147 ( V_118 ) ;
if ( ( V_47 == - 1 ) || ( V_47 == V_22 -> V_47 ) )
break;
V_126 = F_34 ( V_47 ) ;
if ( V_126 -> V_44 . V_32 . V_33 <= V_118 -> V_59 ) {
V_126 = NULL ;
break;
}
if ( F_174 ( V_22 , V_126 ) ) {
if ( F_92 ( F_40 ( V_118 ) != V_22 ||
! F_162 ( V_126 -> V_47 ,
F_163 ( V_118 ) ) ||
F_161 ( V_22 , V_118 ) ||
! F_157 ( V_118 ) ) ) {
F_175 ( V_22 , V_126 ) ;
V_126 = NULL ;
break;
}
}
if ( V_126 -> V_44 . V_32 . V_33 > V_118 -> V_59 )
break;
F_175 ( V_22 , V_126 ) ;
V_126 = NULL ;
}
return V_126 ;
}
static struct V_41 * F_176 ( struct V_22 * V_22 )
{
struct V_41 * V_57 ;
if ( ! F_54 ( V_22 ) )
return NULL ;
V_57 = F_62 ( & V_22 -> V_44 . V_37 ,
struct V_41 , V_37 ) ;
F_95 ( V_22 -> V_47 != F_168 ( V_57 ) ) ;
F_95 ( F_136 ( V_22 , V_57 ) ) ;
F_95 ( V_57 -> V_65 <= 1 ) ;
F_95 ( ! F_157 ( V_57 ) ) ;
F_95 ( ! F_146 ( V_57 ) ) ;
return V_57 ;
}
static int F_177 ( struct V_22 * V_22 )
{
struct V_41 * V_129 ;
struct V_22 * V_126 ;
int V_130 = 0 ;
if ( ! V_22 -> V_44 . V_36 )
return 0 ;
V_129 = F_176 ( V_22 ) ;
if ( ! V_129 )
return 0 ;
V_131:
if ( F_92 ( V_129 == V_22 -> V_33 ) ) {
F_121 ( 1 ) ;
return 0 ;
}
if ( F_92 ( V_129 -> V_59 < V_22 -> V_33 -> V_59 ) ) {
F_77 ( V_22 ) ;
return 0 ;
}
F_178 ( V_129 ) ;
V_126 = F_173 ( V_129 , V_22 ) ;
if ( ! V_126 ) {
struct V_41 * V_118 ;
V_118 = F_176 ( V_22 ) ;
if ( F_168 ( V_129 ) == V_22 -> V_47 && V_118 == V_129 ) {
goto V_110;
}
if ( ! V_118 )
goto V_110;
F_179 ( V_129 ) ;
V_129 = V_118 ;
goto V_131;
}
F_180 ( V_22 , V_129 , 0 ) ;
F_181 ( V_129 , V_126 -> V_47 ) ;
F_182 ( V_126 , V_129 , 0 ) ;
V_130 = 1 ;
F_77 ( V_126 ) ;
F_175 ( V_22 , V_126 ) ;
V_110:
F_179 ( V_129 ) ;
return V_130 ;
}
static void F_183 ( struct V_22 * V_22 )
{
while ( F_177 ( V_22 ) )
;
}
static int F_63 ( struct V_22 * V_67 )
{
int V_123 = V_67 -> V_47 , V_130 = 0 , V_47 ;
struct V_41 * V_57 ;
struct V_22 * V_132 ;
if ( F_104 ( ! F_42 ( V_67 ) ) )
return 0 ;
F_184 () ;
F_89 (cpu, this_rq->rd->rto_mask) {
if ( V_123 == V_47 )
continue;
V_132 = F_34 ( V_47 ) ;
if ( V_132 -> V_44 . V_32 . V_34 >=
V_67 -> V_44 . V_32 . V_33 )
continue;
F_174 ( V_67 , V_132 ) ;
V_57 = F_164 ( V_132 , V_123 ) ;
if ( V_57 && ( V_57 -> V_59 < V_67 -> V_44 . V_32 . V_33 ) ) {
F_121 ( V_57 == V_132 -> V_33 ) ;
F_121 ( ! F_157 ( V_57 ) ) ;
if ( V_57 -> V_59 < V_132 -> V_33 -> V_59 )
goto V_133;
V_130 = 1 ;
F_180 ( V_132 , V_57 , 0 ) ;
F_181 ( V_57 , V_123 ) ;
F_182 ( V_67 , V_57 , 0 ) ;
}
V_133:
F_175 ( V_67 , V_132 ) ;
}
return V_130 ;
}
static void F_185 ( struct V_22 * V_22 )
{
F_183 ( V_22 ) ;
}
static void F_186 ( struct V_22 * V_22 , struct V_41 * V_57 )
{
if ( ! F_161 ( V_22 , V_57 ) &&
! F_152 ( V_22 -> V_33 ) &&
F_54 ( V_22 ) &&
V_57 -> V_65 > 1 &&
( F_187 ( V_22 -> V_33 ) || F_146 ( V_22 -> V_33 ) ) &&
( V_22 -> V_33 -> V_65 < 2 ||
V_22 -> V_33 -> V_59 <= V_57 -> V_59 ) )
F_183 ( V_22 ) ;
}
static void F_188 ( struct V_41 * V_57 ,
const struct V_72 * V_134 )
{
struct V_22 * V_22 ;
int V_76 ;
F_95 ( ! F_146 ( V_57 ) ) ;
if ( ! F_157 ( V_57 ) )
return;
V_76 = F_88 ( V_134 ) ;
if ( ( V_57 -> V_65 > 1 ) == ( V_76 > 1 ) )
return;
V_22 = F_40 ( V_57 ) ;
if ( V_76 <= 1 ) {
if ( ! F_136 ( V_22 , V_57 ) )
F_61 ( V_22 , V_57 ) ;
F_95 ( ! V_22 -> V_44 . V_35 ) ;
V_22 -> V_44 . V_35 -- ;
} else {
if ( ! F_136 ( V_22 , V_57 ) )
F_57 ( V_22 , V_57 ) ;
V_22 -> V_44 . V_35 ++ ;
}
F_51 ( & V_22 -> V_44 ) ;
}
static void F_189 ( struct V_22 * V_22 )
{
if ( V_22 -> V_44 . V_36 )
F_44 ( V_22 ) ;
F_96 ( V_22 ) ;
F_117 ( & V_22 -> V_60 -> V_98 , V_22 -> V_47 , V_22 -> V_44 . V_32 . V_33 ) ;
}
static void F_190 ( struct V_22 * V_22 )
{
if ( V_22 -> V_44 . V_36 )
F_48 ( V_22 ) ;
F_91 ( V_22 ) ;
F_117 ( & V_22 -> V_60 -> V_98 , V_22 -> V_47 , V_135 ) ;
}
static void F_191 ( struct V_22 * V_22 , struct V_41 * V_57 )
{
if ( ! F_157 ( V_57 ) || V_22 -> V_44 . V_70 )
return;
if ( F_63 ( V_22 ) )
F_77 ( V_22 ) ;
}
void T_5 F_192 ( void )
{
unsigned int V_25 ;
F_31 (i) {
F_193 ( & F_194 ( V_122 , V_25 ) ,
V_53 , F_39 ( V_25 ) ) ;
}
}
static void F_195 ( struct V_22 * V_22 , struct V_41 * V_57 )
{
int V_136 = 1 ;
if ( F_157 ( V_57 ) && V_22 -> V_33 != V_57 ) {
#ifdef V_31
if ( V_57 -> V_65 > 1 && V_22 -> V_44 . V_36 &&
F_177 ( V_22 ) && V_22 != F_40 ( V_57 ) )
V_136 = 0 ;
#endif
if ( V_136 && V_57 -> V_59 < V_22 -> V_33 -> V_59 )
F_77 ( V_22 ) ;
}
}
static void
F_196 ( struct V_22 * V_22 , struct V_41 * V_57 , int V_137 )
{
if ( ! F_157 ( V_57 ) )
return;
if ( V_22 -> V_33 == V_57 ) {
#ifdef V_31
if ( V_137 < V_57 -> V_59 )
F_63 ( V_22 ) ;
if ( V_57 -> V_59 > V_22 -> V_44 . V_32 . V_33 && V_22 -> V_33 == V_57 )
F_77 ( V_22 ) ;
#else
if ( V_137 < V_57 -> V_59 )
F_77 ( V_22 ) ;
#endif
} else {
if ( V_57 -> V_59 < V_22 -> V_33 -> V_59 )
F_77 ( V_22 ) ;
}
}
static void F_197 ( struct V_22 * V_22 , struct V_41 * V_57 )
{
unsigned long V_138 , V_139 ;
V_138 = F_198 ( V_57 , V_140 ) ;
V_139 = F_199 ( V_57 , V_140 ) ;
if ( V_138 != V_141 ) {
unsigned long V_34 ;
if ( V_57 -> V_44 . V_142 != V_143 ) {
V_57 -> V_44 . V_105 ++ ;
V_57 -> V_44 . V_142 = V_143 ;
}
V_34 = F_200 ( F_100 ( V_138 , V_139 ) , V_144 / V_145 ) ;
if ( V_57 -> V_44 . V_105 > V_34 )
V_57 -> V_146 . V_147 = V_57 -> V_91 . V_95 ;
}
}
static void F_201 ( struct V_22 * V_22 , struct V_41 * V_57 , int V_148 )
{
struct V_42 * V_43 = & V_57 -> V_44 ;
F_106 ( V_22 ) ;
F_197 ( V_22 , V_57 ) ;
if ( V_57 -> V_149 != V_150 )
return;
if ( -- V_57 -> V_44 . V_151 )
return;
V_57 -> V_44 . V_151 = V_152 ;
F_113 (rt_se) {
if ( V_43 -> V_51 . V_58 != V_43 -> V_51 . V_34 ) {
F_141 ( V_22 , V_57 , 0 ) ;
F_77 ( V_22 ) ;
return;
}
}
}
static void F_202 ( struct V_22 * V_22 )
{
struct V_41 * V_57 = V_22 -> V_33 ;
V_57 -> V_91 . V_92 = F_107 ( V_22 ) ;
F_61 ( V_22 , V_57 ) ;
}
static unsigned int F_203 ( struct V_22 * V_22 , struct V_41 * V_118 )
{
if ( V_118 -> V_149 == V_150 )
return V_152 ;
else
return 0 ;
}
void F_204 ( struct V_153 * V_154 , int V_47 )
{
T_4 V_78 ;
struct V_21 * V_21 ;
F_144 () ;
F_93 (rt_rq, iter, cpu_rq(cpu))
F_205 ( V_154 , V_47 , V_21 ) ;
F_148 () ;
}
