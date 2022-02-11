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
static inline void F_68 ( struct V_21 * V_21 )
{
F_69 ( & V_21 -> V_66 ,
& F_27 ( V_21 ) -> V_66 ) ;
}
static inline void F_70 ( struct V_21 * V_21 )
{
F_71 ( & V_21 -> V_66 ) ;
}
static inline struct V_21 * F_72 ( struct V_41 * V_42 )
{
return V_42 -> V_49 ;
}
static void F_73 ( struct V_21 * V_21 )
{
struct V_40 * V_33 = F_27 ( V_21 ) -> V_33 ;
struct V_41 * V_42 ;
int V_46 = F_74 ( F_27 ( V_21 ) ) ;
V_42 = V_21 -> V_45 -> V_42 [ V_46 ] ;
if ( V_21 -> V_67 ) {
if ( V_42 && ! F_60 ( V_42 ) )
F_75 ( V_42 , false ) ;
if ( V_21 -> V_32 . V_33 < V_33 -> V_63 )
F_76 ( V_33 ) ;
}
}
static void F_77 ( struct V_21 * V_21 )
{
struct V_41 * V_42 ;
int V_46 = F_74 ( F_27 ( V_21 ) ) ;
V_42 = V_21 -> V_45 -> V_42 [ V_46 ] ;
if ( V_42 && F_60 ( V_42 ) )
F_78 ( V_42 ) ;
}
static inline int F_79 ( struct V_21 * V_21 )
{
return V_21 -> V_39 && ! V_21 -> V_48 ;
}
static int F_80 ( struct V_41 * V_42 )
{
struct V_21 * V_21 = F_72 ( V_42 ) ;
struct V_40 * V_56 ;
if ( V_21 )
return ! ! V_21 -> V_48 ;
V_56 = F_23 ( V_42 ) ;
return V_56 -> V_63 != V_56 -> V_68 ;
}
static inline const struct V_69 * F_81 ( void )
{
return F_33 ( F_82 () ) -> V_57 -> V_70 ;
}
static inline const struct V_69 * F_81 ( void )
{
return V_71 ;
}
static inline
struct V_21 * F_83 ( struct V_4 * V_5 , int V_46 )
{
return F_2 ( V_5 , struct V_44 , V_4 ) -> V_21 [ V_46 ] ;
}
static inline struct V_4 * F_84 ( struct V_21 * V_21 )
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
static inline void F_68 ( struct V_21 * V_21 )
{
}
static inline void F_70 ( struct V_21 * V_21 )
{
}
static inline struct V_21 * F_72 ( struct V_41 * V_42 )
{
return NULL ;
}
static inline void F_73 ( struct V_21 * V_21 )
{
if ( V_21 -> V_67 )
F_76 ( F_27 ( V_21 ) -> V_33 ) ;
}
static inline void F_77 ( struct V_21 * V_21 )
{
}
static inline int F_79 ( struct V_21 * V_21 )
{
return V_21 -> V_39 ;
}
static inline const struct V_69 * F_81 ( void )
{
return V_71 ;
}
static inline
struct V_21 * F_83 ( struct V_4 * V_5 , int V_46 )
{
return & F_33 ( V_46 ) -> V_43 ;
}
static inline struct V_4 * F_84 ( struct V_21 * V_21 )
{
return & V_54 ;
}
static int F_85 ( struct V_21 * V_21 )
{
struct V_4 * V_5 = F_84 ( V_21 ) ;
struct V_72 * V_57 = F_33 ( F_82 () ) -> V_57 ;
int V_25 , V_73 , V_74 = 0 ;
T_2 V_10 ;
V_73 = F_86 ( V_57 -> V_70 ) ;
F_13 ( & V_5 -> V_16 ) ;
V_10 = F_36 ( V_5 -> V_10 ) ;
F_87 (i, rd->span) {
struct V_21 * V_75 = F_83 ( V_5 , V_25 ) ;
T_3 V_76 ;
if ( V_75 == V_21 )
continue;
F_13 ( & V_75 -> V_16 ) ;
if ( V_75 -> V_15 == V_20 )
goto V_34;
V_76 = V_75 -> V_15 - V_75 -> V_38 ;
if ( V_76 > 0 ) {
V_76 = F_88 ( ( T_2 ) V_76 , V_73 ) ;
if ( V_21 -> V_15 + V_76 > V_10 )
V_76 = V_10 - V_21 -> V_15 ;
V_75 -> V_15 -= V_76 ;
V_21 -> V_15 += V_76 ;
V_74 = 1 ;
if ( V_21 -> V_15 == V_10 ) {
F_15 ( & V_75 -> V_16 ) ;
break;
}
}
V_34:
F_15 ( & V_75 -> V_16 ) ;
}
F_15 ( & V_5 -> V_16 ) ;
return V_74 ;
}
static void F_89 ( struct V_22 * V_22 )
{
struct V_72 * V_57 = V_22 -> V_57 ;
T_4 V_75 ;
struct V_21 * V_21 ;
if ( F_90 ( ! V_77 ) )
return;
F_91 (rt_rq, iter, rq) {
struct V_4 * V_5 = F_84 ( V_21 ) ;
T_3 V_78 ;
int V_25 ;
F_13 ( & V_5 -> V_16 ) ;
F_13 ( & V_21 -> V_16 ) ;
if ( V_21 -> V_15 == V_20 ||
V_21 -> V_15 == V_5 -> V_15 )
goto V_79;
F_15 ( & V_21 -> V_16 ) ;
V_78 = V_5 -> V_15 - V_21 -> V_15 ;
F_87 (i, rd->span) {
struct V_21 * V_75 = F_83 ( V_5 , V_25 ) ;
T_3 V_76 ;
if ( V_75 == V_21 || V_75 -> V_15 == V_20 )
continue;
F_13 ( & V_75 -> V_16 ) ;
if ( V_78 > 0 ) {
V_76 = F_92 ( T_3 , V_75 -> V_15 , V_78 ) ;
V_75 -> V_15 -= V_76 ;
V_78 -= V_76 ;
} else {
V_75 -> V_15 -= V_78 ;
V_78 -= V_78 ;
}
F_15 ( & V_75 -> V_16 ) ;
if ( ! V_78 )
break;
}
F_13 ( & V_21 -> V_16 ) ;
F_93 ( V_78 ) ;
V_79:
V_21 -> V_15 = V_20 ;
V_21 -> V_39 = 0 ;
F_15 ( & V_21 -> V_16 ) ;
F_15 ( & V_5 -> V_16 ) ;
}
}
static void F_94 ( struct V_22 * V_22 )
{
unsigned long V_80 ;
F_95 ( & V_22 -> V_81 , V_80 ) ;
F_89 ( V_22 ) ;
F_96 ( & V_22 -> V_81 , V_80 ) ;
}
static void F_97 ( struct V_22 * V_22 )
{
T_4 V_75 ;
struct V_21 * V_21 ;
if ( F_90 ( ! V_77 ) )
return;
F_91 (rt_rq, iter, rq) {
struct V_4 * V_5 = F_84 ( V_21 ) ;
F_13 ( & V_5 -> V_16 ) ;
F_13 ( & V_21 -> V_16 ) ;
V_21 -> V_15 = V_5 -> V_15 ;
V_21 -> V_38 = 0 ;
V_21 -> V_39 = 0 ;
F_15 ( & V_21 -> V_16 ) ;
F_15 ( & V_5 -> V_16 ) ;
}
}
static void F_98 ( struct V_22 * V_22 )
{
unsigned long V_80 ;
F_95 ( & V_22 -> V_81 , V_80 ) ;
F_97 ( V_22 ) ;
F_96 ( & V_22 -> V_81 , V_80 ) ;
}
int F_99 ( struct V_82 * V_83 , unsigned long V_84 , void * V_85 )
{
int V_46 = ( int ) ( long ) V_85 ;
switch ( V_84 ) {
case V_86 :
case V_87 :
F_94 ( F_33 ( V_46 ) ) ;
return V_88 ;
case V_89 :
case V_90 :
case V_91 :
case V_92 :
F_98 ( F_33 ( V_46 ) ) ;
return V_88 ;
default:
return V_93 ;
}
}
static int F_100 ( struct V_21 * V_21 )
{
int V_74 = 0 ;
if ( ! F_101 ( V_94 ) )
return V_74 ;
if ( V_21 -> V_38 > V_21 -> V_15 ) {
F_15 ( & V_21 -> V_16 ) ;
V_74 = F_85 ( V_21 ) ;
F_13 ( & V_21 -> V_16 ) ;
}
return V_74 ;
}
static inline int F_100 ( struct V_21 * V_21 )
{
return 0 ;
}
static int F_5 ( struct V_4 * V_5 , int V_8 )
{
int V_25 , V_9 = 1 , V_95 = 0 ;
const struct V_69 * V_70 ;
V_70 = F_81 () ;
#ifdef F_102
if ( V_5 == & V_96 . V_4 )
V_70 = V_71 ;
#endif
F_87 (i, span) {
int V_97 = 0 ;
struct V_21 * V_21 = F_83 ( V_5 , V_25 ) ;
struct V_22 * V_22 = F_27 ( V_21 ) ;
F_13 ( & V_22 -> V_81 ) ;
if ( V_21 -> V_38 ) {
T_2 V_14 ;
F_13 ( & V_21 -> V_16 ) ;
if ( V_21 -> V_39 )
F_100 ( V_21 ) ;
V_14 = V_21 -> V_15 ;
V_21 -> V_38 -= F_103 ( V_21 -> V_38 , V_8 * V_14 ) ;
if ( V_21 -> V_39 && V_21 -> V_38 < V_14 ) {
V_21 -> V_39 = 0 ;
V_97 = 1 ;
if ( V_21 -> V_67 && V_22 -> V_33 == V_22 -> V_9 )
V_22 -> V_98 = - 1 ;
}
if ( V_21 -> V_38 || V_21 -> V_67 )
V_9 = 0 ;
F_15 ( & V_21 -> V_16 ) ;
} else if ( V_21 -> V_67 ) {
V_9 = 0 ;
if ( ! F_79 ( V_21 ) )
V_97 = 1 ;
}
if ( V_21 -> V_39 )
V_95 = 1 ;
if ( V_97 )
F_73 ( V_21 ) ;
F_15 ( & V_22 -> V_81 ) ;
}
if ( ! V_95 && ( ! F_11 () || V_5 -> V_15 == V_20 ) )
return 1 ;
return V_9 ;
}
static inline int F_104 ( struct V_41 * V_42 )
{
#ifdef F_102
struct V_21 * V_21 = F_72 ( V_42 ) ;
if ( V_21 )
return V_21 -> V_32 . V_33 ;
#endif
return F_23 ( V_42 ) -> V_63 ;
}
static int F_105 ( struct V_21 * V_21 )
{
T_2 V_14 = F_62 ( V_21 ) ;
if ( V_21 -> V_39 )
return F_79 ( V_21 ) ;
if ( V_14 >= F_63 ( V_21 ) )
return 0 ;
F_100 ( V_21 ) ;
V_14 = F_62 ( V_21 ) ;
if ( V_14 == V_20 )
return 0 ;
if ( V_21 -> V_38 > V_14 ) {
struct V_4 * V_5 = F_84 ( V_21 ) ;
if ( F_106 ( V_5 -> V_15 ) ) {
static bool V_99 = false ;
V_21 -> V_39 = 1 ;
if ( ! V_99 ) {
V_99 = true ;
F_107 ( L_1 ) ;
}
} else {
V_21 -> V_38 = 0 ;
}
if ( F_79 ( V_21 ) ) {
F_77 ( V_21 ) ;
return 1 ;
}
}
return 0 ;
}
static void F_108 ( struct V_22 * V_22 )
{
struct V_40 * V_33 = V_22 -> V_33 ;
struct V_41 * V_42 = & V_33 -> V_43 ;
struct V_21 * V_21 = F_28 ( V_42 ) ;
T_2 V_100 ;
if ( V_33 -> V_101 != & V_102 )
return;
V_100 = V_22 -> V_103 - V_33 -> V_104 . V_105 ;
if ( F_90 ( ( T_3 ) V_100 < 0 ) )
V_100 = 0 ;
F_109 ( V_33 -> V_104 . V_106 . V_107 ,
F_110 ( V_33 -> V_104 . V_106 . V_107 , V_100 ) ) ;
V_33 -> V_104 . V_108 += V_100 ;
F_111 ( V_33 , V_100 ) ;
V_33 -> V_104 . V_105 = V_22 -> V_103 ;
F_112 ( V_33 , V_100 ) ;
F_113 ( V_22 , V_100 ) ;
if ( ! F_11 () )
return;
F_114 (rt_se) {
V_21 = F_28 ( V_42 ) ;
if ( F_62 ( V_21 ) != V_20 ) {
F_13 ( & V_21 -> V_16 ) ;
V_21 -> V_38 += V_100 ;
if ( F_105 ( V_21 ) )
F_76 ( V_33 ) ;
F_15 ( & V_21 -> V_16 ) ;
}
}
}
static void
F_115 ( struct V_21 * V_21 , int V_63 , int V_109 )
{
struct V_22 * V_22 = F_27 ( V_21 ) ;
if ( V_22 -> V_59 && V_63 < V_109 )
F_116 ( & V_22 -> V_57 -> V_110 , V_22 -> V_46 , V_63 ) ;
}
static void
F_117 ( struct V_21 * V_21 , int V_63 , int V_109 )
{
struct V_22 * V_22 = F_27 ( V_21 ) ;
if ( V_22 -> V_59 && V_21 -> V_32 . V_33 != V_109 )
F_116 ( & V_22 -> V_57 -> V_110 , V_22 -> V_46 , V_21 -> V_32 . V_33 ) ;
}
static inline
void F_115 ( struct V_21 * V_21 , int V_63 , int V_109 ) {}
static inline
void F_117 ( struct V_21 * V_21 , int V_63 , int V_109 ) {}
static void
F_118 ( struct V_21 * V_21 , int V_63 )
{
int V_109 = V_21 -> V_32 . V_33 ;
if ( V_63 < V_109 )
V_21 -> V_32 . V_33 = V_63 ;
F_115 ( V_21 , V_63 , V_109 ) ;
}
static void
F_119 ( struct V_21 * V_21 , int V_63 )
{
int V_109 = V_21 -> V_32 . V_33 ;
if ( V_21 -> V_67 ) {
F_120 ( V_63 < V_109 ) ;
if ( V_63 == V_109 ) {
struct V_23 * V_24 = & V_21 -> V_26 ;
V_21 -> V_32 . V_33 =
F_121 ( V_24 -> V_29 ) ;
}
} else
V_21 -> V_32 . V_33 = V_27 ;
F_117 ( V_21 , V_63 , V_109 ) ;
}
static inline void F_118 ( struct V_21 * V_21 , int V_63 ) {}
static inline void F_119 ( struct V_21 * V_21 , int V_63 ) {}
static void
F_122 ( struct V_41 * V_42 , struct V_21 * V_21 )
{
if ( F_80 ( V_42 ) )
V_21 -> V_48 ++ ;
if ( V_21 -> V_45 )
F_10 ( & V_21 -> V_45 -> V_4 ) ;
}
static void
F_123 ( struct V_41 * V_42 , struct V_21 * V_21 )
{
if ( F_80 ( V_42 ) )
V_21 -> V_48 -- ;
F_120 ( ! V_21 -> V_67 && V_21 -> V_48 ) ;
}
static void
F_122 ( struct V_41 * V_42 , struct V_21 * V_21 )
{
F_10 ( & V_54 ) ;
}
static inline
void F_123 ( struct V_41 * V_42 , struct V_21 * V_21 ) {}
static inline
void F_124 ( struct V_41 * V_42 , struct V_21 * V_21 )
{
int V_63 = F_104 ( V_42 ) ;
F_120 ( ! F_125 ( V_63 ) ) ;
V_21 -> V_67 ++ ;
F_118 ( V_21 , V_63 ) ;
F_50 ( V_42 , V_21 ) ;
F_122 ( V_42 , V_21 ) ;
}
static inline
void F_126 ( struct V_41 * V_42 , struct V_21 * V_21 )
{
F_120 ( ! F_125 ( F_104 ( V_42 ) ) ) ;
F_120 ( ! V_21 -> V_67 ) ;
V_21 -> V_67 -- ;
F_119 ( V_21 , F_104 ( V_42 ) ) ;
F_51 ( V_42 , V_21 ) ;
F_123 ( V_42 , V_21 ) ;
}
static void F_127 ( struct V_41 * V_42 , bool V_111 )
{
struct V_21 * V_21 = F_28 ( V_42 ) ;
struct V_23 * V_24 = & V_21 -> V_26 ;
struct V_21 * V_112 = F_72 ( V_42 ) ;
struct V_113 * V_28 = V_24 -> V_28 + F_104 ( V_42 ) ;
if ( V_112 && ( F_79 ( V_112 ) || ! V_112 -> V_67 ) )
return;
if ( ! V_21 -> V_67 )
F_68 ( V_21 ) ;
if ( V_111 )
F_128 ( & V_42 -> V_50 , V_28 ) ;
else
F_129 ( & V_42 -> V_50 , V_28 ) ;
F_19 ( F_104 ( V_42 ) , V_24 -> V_29 ) ;
F_124 ( V_42 , V_21 ) ;
}
static void F_130 ( struct V_41 * V_42 )
{
struct V_21 * V_21 = F_28 ( V_42 ) ;
struct V_23 * V_24 = & V_21 -> V_26 ;
F_131 ( & V_42 -> V_50 ) ;
if ( F_61 ( V_24 -> V_28 + F_104 ( V_42 ) ) )
F_18 ( F_104 ( V_42 ) , V_24 -> V_29 ) ;
F_126 ( V_42 , V_21 ) ;
if ( ! V_21 -> V_67 )
F_70 ( V_21 ) ;
}
static void F_132 ( struct V_41 * V_42 )
{
struct V_41 * V_114 = NULL ;
F_114 (rt_se) {
V_42 -> V_114 = V_114 ;
V_114 = V_42 ;
}
for ( V_42 = V_114 ; V_42 ; V_42 = V_42 -> V_114 ) {
if ( F_60 ( V_42 ) )
F_130 ( V_42 ) ;
}
}
static void F_75 ( struct V_41 * V_42 , bool V_111 )
{
F_132 ( V_42 ) ;
F_114 (rt_se)
F_127 ( V_42 , V_111 ) ;
}
static void F_78 ( struct V_41 * V_42 )
{
F_132 ( V_42 ) ;
F_114 (rt_se) {
struct V_21 * V_21 = F_72 ( V_42 ) ;
if ( V_21 && V_21 -> V_67 )
F_127 ( V_42 , false ) ;
}
}
static void
F_133 ( struct V_22 * V_22 , struct V_40 * V_56 , int V_80 )
{
struct V_41 * V_42 = & V_56 -> V_43 ;
if ( V_80 & V_115 )
V_42 -> V_116 = 0 ;
F_75 ( V_42 , V_80 & V_117 ) ;
if ( ! F_134 ( V_22 , V_56 ) && V_56 -> V_62 > 1 )
F_54 ( V_22 , V_56 ) ;
F_135 ( V_22 ) ;
}
static void F_136 ( struct V_22 * V_22 , struct V_40 * V_56 , int V_80 )
{
struct V_41 * V_42 = & V_56 -> V_43 ;
F_108 ( V_22 ) ;
F_78 ( V_42 ) ;
F_58 ( V_22 , V_56 ) ;
F_137 ( V_22 ) ;
}
static void
F_138 ( struct V_21 * V_21 , struct V_41 * V_42 , int V_111 )
{
if ( F_60 ( V_42 ) ) {
struct V_23 * V_24 = & V_21 -> V_26 ;
struct V_113 * V_28 = V_24 -> V_28 + F_104 ( V_42 ) ;
if ( V_111 )
F_139 ( & V_42 -> V_50 , V_28 ) ;
else
F_140 ( & V_42 -> V_50 , V_28 ) ;
}
}
static void F_141 ( struct V_22 * V_22 , struct V_40 * V_56 , int V_111 )
{
struct V_41 * V_42 = & V_56 -> V_43 ;
struct V_21 * V_21 ;
F_114 (rt_se) {
V_21 = F_28 ( V_42 ) ;
F_138 ( V_21 , V_42 , V_111 ) ;
}
}
static void F_142 ( struct V_22 * V_22 )
{
F_141 ( V_22 , V_22 -> V_33 , 0 ) ;
}
static int
F_143 ( struct V_40 * V_56 , int V_118 , int V_80 )
{
struct V_40 * V_33 ;
struct V_22 * V_22 ;
int V_46 ;
V_46 = F_144 ( V_56 ) ;
if ( V_56 -> V_62 == 1 )
goto V_119;
if ( V_118 != V_120 && V_118 != V_121 )
goto V_119;
V_22 = F_33 ( V_46 ) ;
F_145 () ;
V_33 = F_146 ( V_22 -> V_33 ) ;
if ( V_33 && F_90 ( F_147 ( V_33 ) ) &&
( V_33 -> V_62 < 2 ||
V_33 -> V_63 <= V_56 -> V_63 ) &&
( V_56 -> V_62 > 1 ) ) {
int V_122 = F_148 ( V_56 ) ;
if ( V_122 != - 1 )
V_46 = V_122 ;
}
F_149 () ;
V_119:
return V_46 ;
}
static void F_150 ( struct V_22 * V_22 , struct V_40 * V_56 )
{
if ( V_22 -> V_33 -> V_62 == 1 )
return;
if ( V_56 -> V_62 != 1
&& F_151 ( & V_22 -> V_57 -> V_110 , V_56 , NULL ) )
return;
if ( ! F_151 ( & V_22 -> V_57 -> V_110 , V_22 -> V_33 , NULL ) )
return;
F_141 ( V_22 , V_56 , 1 ) ;
F_76 ( V_22 -> V_33 ) ;
}
static void F_152 ( struct V_22 * V_22 , struct V_40 * V_56 , int V_80 )
{
if ( V_56 -> V_63 < V_22 -> V_33 -> V_63 ) {
F_76 ( V_22 -> V_33 ) ;
return;
}
#ifdef V_31
if ( V_56 -> V_63 == V_22 -> V_33 -> V_63 && ! F_153 ( V_22 -> V_33 ) )
F_150 ( V_22 , V_56 ) ;
#endif
}
static struct V_41 * F_154 ( struct V_22 * V_22 ,
struct V_21 * V_21 )
{
struct V_23 * V_24 = & V_21 -> V_26 ;
struct V_41 * V_34 = NULL ;
struct V_113 * V_28 ;
int V_123 ;
V_123 = F_121 ( V_24 -> V_29 ) ;
F_93 ( V_123 >= V_27 ) ;
V_28 = V_24 -> V_28 + V_123 ;
V_34 = F_155 ( V_28 -> V_34 , struct V_41 , V_50 ) ;
return V_34 ;
}
static struct V_40 * F_156 ( struct V_22 * V_22 )
{
struct V_41 * V_42 ;
struct V_40 * V_56 ;
struct V_21 * V_21 ;
V_21 = & V_22 -> V_43 ;
if ( ! V_21 -> V_67 )
return NULL ;
if ( F_79 ( V_21 ) )
return NULL ;
do {
V_42 = F_154 ( V_22 , V_21 ) ;
F_93 ( ! V_42 ) ;
V_21 = F_72 ( V_42 ) ;
} while ( V_21 );
V_56 = F_23 ( V_42 ) ;
V_56 -> V_104 . V_105 = V_22 -> V_103 ;
return V_56 ;
}
static struct V_40 * F_157 ( struct V_22 * V_22 )
{
struct V_40 * V_56 = F_156 ( V_22 ) ;
if ( V_56 )
F_58 ( V_22 , V_56 ) ;
#ifdef V_31
V_22 -> V_124 = F_52 ( V_22 ) ;
#endif
return V_56 ;
}
static void F_158 ( struct V_22 * V_22 , struct V_40 * V_56 )
{
F_108 ( V_22 ) ;
if ( F_60 ( & V_56 -> V_43 ) && V_56 -> V_62 > 1 )
F_54 ( V_22 , V_56 ) ;
}
static int F_159 ( struct V_22 * V_22 , struct V_40 * V_56 , int V_46 )
{
if ( ! F_160 ( V_22 , V_56 ) &&
( V_46 < 0 || F_161 ( V_46 , F_162 ( V_56 ) ) ) &&
( V_56 -> V_62 > 1 ) )
return 1 ;
return 0 ;
}
static struct V_40 * F_163 ( struct V_22 * V_22 , int V_46 )
{
struct V_40 * V_34 = NULL ;
struct V_41 * V_42 ;
struct V_23 * V_24 ;
struct V_21 * V_21 ;
int V_123 ;
F_164 (rt_rq, rq) {
V_24 = & V_21 -> V_26 ;
V_123 = F_121 ( V_24 -> V_29 ) ;
V_125:
if ( V_123 >= V_27 )
continue;
if ( V_34 && V_34 -> V_63 <= V_123 )
continue;
F_165 (rt_se, array->queue + idx, run_list) {
struct V_40 * V_56 ;
if ( ! F_26 ( V_42 ) )
continue;
V_56 = F_23 ( V_42 ) ;
if ( F_159 ( V_22 , V_56 , V_46 ) ) {
V_34 = V_56 ;
break;
}
}
if ( ! V_34 ) {
V_123 = F_166 ( V_24 -> V_29 , V_27 , V_123 + 1 ) ;
goto V_125;
}
}
return V_34 ;
}
static int F_148 ( struct V_40 * V_126 )
{
struct V_127 * V_128 ;
struct V_69 * V_129 = F_167 ( V_130 ) ;
int V_131 = F_82 () ;
int V_46 = F_144 ( V_126 ) ;
if ( F_90 ( ! V_129 ) )
return - 1 ;
if ( V_126 -> V_62 == 1 )
return - 1 ;
if ( ! F_151 ( & F_39 ( V_126 ) -> V_57 -> V_110 , V_126 , V_129 ) )
return - 1 ;
if ( F_161 ( V_46 , V_129 ) )
return V_46 ;
if ( ! F_161 ( V_131 , V_129 ) )
V_131 = - 1 ;
F_145 () ;
F_168 (cpu, sd) {
if ( V_128 -> V_80 & V_132 ) {
int V_133 ;
if ( V_131 != - 1 &&
F_161 ( V_131 , F_169 ( V_128 ) ) ) {
F_149 () ;
return V_131 ;
}
V_133 = F_170 ( V_129 ,
F_169 ( V_128 ) ) ;
if ( V_133 < V_51 ) {
F_149 () ;
return V_133 ;
}
}
}
F_149 () ;
if ( V_131 != - 1 )
return V_131 ;
V_46 = F_171 ( V_129 ) ;
if ( V_46 < V_51 )
return V_46 ;
return - 1 ;
}
static struct V_22 * F_172 ( struct V_40 * V_126 , struct V_22 * V_22 )
{
struct V_22 * V_134 = NULL ;
int V_135 ;
int V_46 ;
for ( V_135 = 0 ; V_135 < V_136 ; V_135 ++ ) {
V_46 = F_148 ( V_126 ) ;
if ( ( V_46 == - 1 ) || ( V_46 == V_22 -> V_46 ) )
break;
V_134 = F_33 ( V_46 ) ;
if ( F_173 ( V_22 , V_134 ) ) {
if ( F_90 ( F_39 ( V_126 ) != V_22 ||
! F_161 ( V_134 -> V_46 ,
F_162 ( V_126 ) ) ||
F_160 ( V_22 , V_126 ) ||
! V_126 -> V_137 ) ) {
F_174 ( V_22 , V_134 ) ;
V_134 = NULL ;
break;
}
}
if ( V_134 -> V_43 . V_32 . V_33 > V_126 -> V_63 )
break;
F_174 ( V_22 , V_134 ) ;
V_134 = NULL ;
}
return V_134 ;
}
static struct V_40 * F_175 ( struct V_22 * V_22 )
{
struct V_40 * V_56 ;
if ( ! F_52 ( V_22 ) )
return NULL ;
V_56 = F_59 ( & V_22 -> V_43 . V_37 ,
struct V_40 , V_37 ) ;
F_93 ( V_22 -> V_46 != F_144 ( V_56 ) ) ;
F_93 ( F_134 ( V_22 , V_56 ) ) ;
F_93 ( V_56 -> V_62 <= 1 ) ;
F_93 ( ! V_56 -> V_137 ) ;
F_93 ( ! F_147 ( V_56 ) ) ;
return V_56 ;
}
static int F_176 ( struct V_22 * V_22 )
{
struct V_40 * V_138 ;
struct V_22 * V_134 ;
int V_139 = 0 ;
if ( ! V_22 -> V_43 . V_36 )
return 0 ;
V_138 = F_175 ( V_22 ) ;
if ( ! V_138 )
return 0 ;
V_140:
if ( F_90 ( V_138 == V_22 -> V_33 ) ) {
F_120 ( 1 ) ;
return 0 ;
}
if ( F_90 ( V_138 -> V_63 < V_22 -> V_33 -> V_63 ) ) {
F_76 ( V_22 -> V_33 ) ;
return 0 ;
}
F_177 ( V_138 ) ;
V_134 = F_172 ( V_138 , V_22 ) ;
if ( ! V_134 ) {
struct V_40 * V_126 ;
V_126 = F_175 ( V_22 ) ;
if ( F_144 ( V_138 ) == V_22 -> V_46 && V_126 == V_138 ) {
goto V_119;
}
if ( ! V_126 )
goto V_119;
F_178 ( V_138 ) ;
V_138 = V_126 ;
goto V_140;
}
F_179 ( V_22 , V_138 , 0 ) ;
F_180 ( V_138 , V_134 -> V_46 ) ;
F_181 ( V_134 , V_138 , 0 ) ;
V_139 = 1 ;
F_76 ( V_134 -> V_33 ) ;
F_174 ( V_22 , V_134 ) ;
V_119:
F_178 ( V_138 ) ;
return V_139 ;
}
static void F_182 ( struct V_22 * V_22 )
{
while ( F_176 ( V_22 ) )
;
}
static int F_183 ( struct V_22 * V_141 )
{
int V_131 = V_141 -> V_46 , V_139 = 0 , V_46 ;
struct V_40 * V_56 ;
struct V_22 * V_142 ;
if ( F_106 ( ! F_40 ( V_141 ) ) )
return 0 ;
F_87 (cpu, this_rq->rd->rto_mask) {
if ( V_131 == V_46 )
continue;
V_142 = F_33 ( V_46 ) ;
if ( V_142 -> V_43 . V_32 . V_34 >=
V_141 -> V_43 . V_32 . V_33 )
continue;
F_173 ( V_141 , V_142 ) ;
if ( V_142 -> V_43 . V_67 <= 1 )
goto V_143;
V_56 = F_163 ( V_142 , V_131 ) ;
if ( V_56 && ( V_56 -> V_63 < V_141 -> V_43 . V_32 . V_33 ) ) {
F_120 ( V_56 == V_142 -> V_33 ) ;
F_120 ( ! V_56 -> V_137 ) ;
if ( V_56 -> V_63 < V_142 -> V_33 -> V_63 )
goto V_143;
V_139 = 1 ;
F_179 ( V_142 , V_56 , 0 ) ;
F_180 ( V_56 , V_131 ) ;
F_181 ( V_141 , V_56 , 0 ) ;
}
V_143:
F_174 ( V_141 , V_142 ) ;
}
return V_139 ;
}
static void F_184 ( struct V_22 * V_22 , struct V_40 * V_144 )
{
if ( V_22 -> V_43 . V_32 . V_33 > V_144 -> V_63 )
F_183 ( V_22 ) ;
}
static void F_185 ( struct V_22 * V_22 )
{
F_182 ( V_22 ) ;
}
static void F_186 ( struct V_22 * V_22 , struct V_40 * V_56 )
{
if ( ! F_160 ( V_22 , V_56 ) &&
! F_153 ( V_22 -> V_33 ) &&
F_52 ( V_22 ) &&
V_56 -> V_62 > 1 &&
F_147 ( V_22 -> V_33 ) &&
( V_22 -> V_33 -> V_62 < 2 ||
V_22 -> V_33 -> V_63 <= V_56 -> V_63 ) )
F_182 ( V_22 ) ;
}
static void F_187 ( struct V_40 * V_56 ,
const struct V_69 * V_145 )
{
struct V_22 * V_22 ;
int V_73 ;
F_93 ( ! F_147 ( V_56 ) ) ;
if ( ! V_56 -> V_137 )
return;
V_73 = F_86 ( V_145 ) ;
if ( ( V_56 -> V_62 > 1 ) == ( V_73 > 1 ) )
return;
V_22 = F_39 ( V_56 ) ;
if ( V_73 <= 1 ) {
if ( ! F_134 ( V_22 , V_56 ) )
F_58 ( V_22 , V_56 ) ;
F_93 ( ! V_22 -> V_43 . V_35 ) ;
V_22 -> V_43 . V_35 -- ;
} else {
if ( ! F_134 ( V_22 , V_56 ) )
F_54 ( V_22 , V_56 ) ;
V_22 -> V_43 . V_35 ++ ;
}
F_49 ( & V_22 -> V_43 ) ;
}
static void F_188 ( struct V_22 * V_22 )
{
if ( V_22 -> V_43 . V_36 )
F_42 ( V_22 ) ;
F_97 ( V_22 ) ;
F_116 ( & V_22 -> V_57 -> V_110 , V_22 -> V_46 , V_22 -> V_43 . V_32 . V_33 ) ;
}
static void F_189 ( struct V_22 * V_22 )
{
if ( V_22 -> V_43 . V_36 )
F_46 ( V_22 ) ;
F_89 ( V_22 ) ;
F_116 ( & V_22 -> V_57 -> V_110 , V_22 -> V_46 , V_146 ) ;
}
static void F_190 ( struct V_22 * V_22 , struct V_40 * V_56 )
{
if ( V_56 -> V_137 && ! V_22 -> V_43 . V_67 )
F_183 ( V_22 ) ;
}
void F_191 ( void )
{
unsigned int V_25 ;
F_30 (i) {
F_192 ( & F_193 ( V_130 , V_25 ) ,
V_52 , F_38 ( V_25 ) ) ;
}
}
static void F_194 ( struct V_22 * V_22 , struct V_40 * V_56 )
{
int V_147 = 1 ;
if ( V_56 -> V_137 && V_22 -> V_33 != V_56 ) {
#ifdef V_31
if ( V_22 -> V_43 . V_36 && F_176 ( V_22 ) &&
V_22 != F_39 ( V_56 ) )
V_147 = 0 ;
#endif
if ( V_147 && V_56 -> V_63 < V_22 -> V_33 -> V_63 )
F_76 ( V_22 -> V_33 ) ;
}
}
static void
F_195 ( struct V_22 * V_22 , struct V_40 * V_56 , int V_148 )
{
if ( ! V_56 -> V_137 )
return;
if ( V_22 -> V_33 == V_56 ) {
#ifdef V_31
if ( V_148 < V_56 -> V_63 )
F_183 ( V_22 ) ;
if ( V_56 -> V_63 > V_22 -> V_43 . V_32 . V_33 && V_22 -> V_33 == V_56 )
F_76 ( V_56 ) ;
#else
if ( V_148 < V_56 -> V_63 )
F_76 ( V_56 ) ;
#endif
} else {
if ( V_56 -> V_63 < V_22 -> V_33 -> V_63 )
F_76 ( V_22 -> V_33 ) ;
}
}
static void F_196 ( struct V_22 * V_22 , struct V_40 * V_56 )
{
unsigned long V_149 , V_150 ;
V_149 = F_197 ( V_56 , V_151 ) ;
V_150 = F_198 ( V_56 , V_151 ) ;
if ( V_149 != V_152 ) {
unsigned long V_34 ;
V_56 -> V_43 . V_116 ++ ;
V_34 = F_199 ( F_103 ( V_149 , V_150 ) , V_153 / V_154 ) ;
if ( V_56 -> V_43 . V_116 > V_34 )
V_56 -> V_155 . V_156 = V_56 -> V_104 . V_108 ;
}
}
static void F_200 ( struct V_22 * V_22 , struct V_40 * V_56 , int V_157 )
{
struct V_41 * V_42 = & V_56 -> V_43 ;
F_108 ( V_22 ) ;
F_196 ( V_22 , V_56 ) ;
if ( V_56 -> V_158 != V_159 )
return;
if ( -- V_56 -> V_43 . V_160 )
return;
V_56 -> V_43 . V_160 = V_161 ;
F_114 (rt_se) {
if ( V_42 -> V_50 . V_144 != V_42 -> V_50 . V_34 ) {
F_141 ( V_22 , V_56 , 0 ) ;
F_201 ( V_56 ) ;
return;
}
}
}
static void F_202 ( struct V_22 * V_22 )
{
struct V_40 * V_56 = V_22 -> V_33 ;
V_56 -> V_104 . V_105 = V_22 -> V_103 ;
F_58 ( V_22 , V_56 ) ;
}
static unsigned int F_203 ( struct V_22 * V_22 , struct V_40 * V_126 )
{
if ( V_126 -> V_158 == V_159 )
return V_161 ;
else
return 0 ;
}
void F_204 ( struct V_162 * V_163 , int V_46 )
{
T_4 V_75 ;
struct V_21 * V_21 ;
F_145 () ;
F_91 (rt_rq, iter, cpu_rq(cpu))
F_205 ( V_163 , V_46 , V_21 ) ;
F_149 () ;
}
