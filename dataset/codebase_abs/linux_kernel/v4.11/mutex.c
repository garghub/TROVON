void
F_1 ( struct V_1 * V_2 , const char * V_3 , struct V_4 * V_5 )
{
F_2 ( & V_2 -> V_6 , 0 ) ;
F_3 ( & V_2 -> V_7 ) ;
F_4 ( & V_2 -> V_8 ) ;
#ifdef F_5
F_6 ( & V_2 -> V_9 ) ;
#endif
F_7 ( V_2 , V_3 , V_5 ) ;
}
static inline struct V_10 * F_8 ( unsigned long V_6 )
{
return (struct V_10 * ) ( V_6 & ~ V_11 ) ;
}
static inline unsigned long F_9 ( unsigned long V_6 )
{
return V_6 & V_11 ;
}
static inline struct V_10 * F_10 ( struct V_1 * V_2 )
{
unsigned long V_6 , V_12 = ( unsigned long ) V_13 ;
V_6 = F_11 ( & V_2 -> V_6 ) ;
for (; ; ) {
unsigned long V_14 , V_15 = F_9 ( V_6 ) ;
unsigned long V_16 = V_6 & ~ V_11 ;
if ( V_16 ) {
if ( F_12 ( V_16 != V_12 ) )
break;
if ( F_12 ( ! ( V_15 & V_17 ) ) )
break;
V_15 &= ~ V_17 ;
} else {
#ifdef F_13
F_14 ( V_15 & V_17 ) ;
#endif
}
V_15 &= ~ V_18 ;
V_14 = F_15 ( & V_2 -> V_6 , V_6 , V_12 | V_15 ) ;
if ( V_14 == V_6 )
return NULL ;
V_6 = V_14 ;
}
return F_8 ( V_6 ) ;
}
static inline bool F_16 ( struct V_1 * V_2 )
{
return ! F_10 ( V_2 ) ;
}
static T_1 bool F_17 ( struct V_1 * V_2 )
{
unsigned long V_12 = ( unsigned long ) V_13 ;
if ( ! F_15 ( & V_2 -> V_6 , 0UL , V_12 ) )
return true ;
return false ;
}
static T_1 bool F_18 ( struct V_1 * V_2 )
{
unsigned long V_12 = ( unsigned long ) V_13 ;
if ( F_19 ( & V_2 -> V_6 , V_12 , 0UL ) == V_12 )
return true ;
return false ;
}
static inline void F_20 ( struct V_1 * V_2 , unsigned long V_19 )
{
F_21 ( V_19 , & V_2 -> V_6 ) ;
}
static inline void F_22 ( struct V_1 * V_2 , unsigned long V_19 )
{
F_23 ( V_19 , & V_2 -> V_6 ) ;
}
static inline bool F_24 ( struct V_1 * V_2 , struct V_20 * V_21 )
{
return F_25 ( & V_2 -> V_8 , struct V_20 , V_22 ) == V_21 ;
}
static void F_26 ( struct V_1 * V_2 , struct V_10 * V_16 )
{
unsigned long V_6 = F_11 ( & V_2 -> V_6 ) ;
for (; ; ) {
unsigned long V_14 , V_23 ;
#ifdef F_13
F_14 ( F_8 ( V_6 ) != V_13 ) ;
F_14 ( V_6 & V_17 ) ;
#endif
V_23 = ( V_6 & V_24 ) ;
V_23 |= ( unsigned long ) V_16 ;
if ( V_16 )
V_23 |= V_17 ;
V_14 = F_19 ( & V_2 -> V_6 , V_6 , V_23 ) ;
if ( V_14 == V_6 )
break;
V_6 = V_14 ;
}
}
void T_2 F_27 ( struct V_1 * V_2 )
{
F_28 () ;
if ( ! F_17 ( V_2 ) )
F_29 ( V_2 ) ;
}
static T_1 void
F_30 ( struct V_25 * V_26 , struct V_27 * V_28 )
{
#ifdef F_13
F_14 ( V_26 -> V_29 ) ;
F_14 ( V_28 -> V_30 ) ;
if ( V_28 -> V_31 ) {
F_14 ( V_28 -> V_31 != V_26 ) ;
F_14 ( V_28 -> V_32 > 0 ) ;
V_28 -> V_31 = NULL ;
}
F_14 ( V_28 -> V_33 != V_26 -> V_33 ) ;
#endif
V_28 -> V_32 ++ ;
}
static inline bool T_2
F_31 ( struct V_27 * V_34 , struct V_27 * V_35 )
{
return V_34 -> V_36 - V_35 -> V_36 <= V_37 &&
( V_34 -> V_36 != V_35 -> V_36 || V_34 > V_35 ) ;
}
static void T_2
F_32 ( struct V_1 * V_2 , struct V_27 * V_28 )
{
struct V_20 * V_38 ;
F_33 ( & V_2 -> V_7 ) ;
F_34 (cur, &lock->wait_list, list) {
if ( ! V_38 -> V_28 )
continue;
if ( V_38 -> V_28 -> V_32 > 0 &&
F_31 ( V_38 -> V_28 , V_28 ) ) {
F_35 ( V_2 , V_38 ) ;
F_36 ( V_38 -> V_16 ) ;
}
break;
}
}
static T_1 void
F_37 ( struct V_25 * V_2 , struct V_27 * V_29 )
{
F_30 ( V_2 , V_29 ) ;
V_2 -> V_29 = V_29 ;
F_38 () ;
if ( F_12 ( ! ( F_11 ( & V_2 -> V_39 . V_6 ) & V_24 ) ) )
return;
F_39 ( & V_2 -> V_39 . V_7 ) ;
F_32 ( & V_2 -> V_39 , V_29 ) ;
F_40 ( & V_2 -> V_39 . V_7 ) ;
}
static T_1 void
F_41 ( struct V_25 * V_2 , struct V_27 * V_29 )
{
F_30 ( V_2 , V_29 ) ;
V_2 -> V_29 = V_29 ;
}
static inline
bool F_42 ( struct V_1 * V_2 , struct V_27 * V_28 ,
struct V_20 * V_21 )
{
struct V_25 * V_26 ;
V_26 = F_43 ( V_2 , struct V_25 , V_39 ) ;
if ( V_28 -> V_32 > 0 && F_44 ( V_26 -> V_29 ) )
return false ;
if ( ! V_21 && ( F_11 ( & V_2 -> V_6 ) & V_24 ) )
return false ;
if ( V_21 && ! F_24 ( V_2 , V_21 ) )
return false ;
return true ;
}
static T_3
bool F_45 ( struct V_1 * V_2 , struct V_10 * V_6 ,
struct V_27 * V_28 , struct V_20 * V_21 )
{
bool V_40 = true ;
F_46 () ;
while ( F_47 ( V_2 ) == V_6 ) {
F_48 () ;
if ( ! V_6 -> V_41 || F_49 () ||
F_50 ( F_51 ( V_6 ) ) ) {
V_40 = false ;
break;
}
if ( V_28 && ! F_42 ( V_2 , V_28 , V_21 ) ) {
V_40 = false ;
break;
}
F_52 () ;
}
F_53 () ;
return V_40 ;
}
static inline int F_54 ( struct V_1 * V_2 )
{
struct V_10 * V_6 ;
int V_42 = 1 ;
if ( F_49 () )
return 0 ;
F_46 () ;
V_6 = F_47 ( V_2 ) ;
if ( V_6 )
V_42 = V_6 -> V_41 && ! F_50 ( F_51 ( V_6 ) ) ;
F_53 () ;
return V_42 ;
}
static T_1 bool
F_55 ( struct V_1 * V_2 , struct V_27 * V_28 ,
const bool V_43 , struct V_20 * V_21 )
{
if ( ! V_21 ) {
if ( ! F_54 ( V_2 ) )
goto V_44;
if ( ! F_56 ( & V_2 -> V_9 ) )
goto V_44;
}
for (; ; ) {
struct V_10 * V_6 ;
V_6 = F_10 ( V_2 ) ;
if ( ! V_6 )
break;
if ( ! F_45 ( V_2 , V_6 , V_28 , V_21 ) )
goto V_45;
F_52 () ;
}
if ( ! V_21 )
F_57 ( & V_2 -> V_9 ) ;
return true ;
V_45:
if ( ! V_21 )
F_57 ( & V_2 -> V_9 ) ;
V_44:
if ( F_49 () ) {
F_58 ( V_46 ) ;
F_59 () ;
}
return false ;
}
static T_1 bool
F_55 ( struct V_1 * V_2 , struct V_27 * V_28 ,
const bool V_43 , struct V_20 * V_21 )
{
return false ;
}
void T_2 F_60 ( struct V_1 * V_2 )
{
#ifndef F_61
if ( F_18 ( V_2 ) )
return;
#endif
F_62 ( V_2 , V_47 ) ;
}
void T_2 F_63 ( struct V_25 * V_2 )
{
if ( V_2 -> V_29 ) {
#ifdef F_13
F_14 ( ! V_2 -> V_29 -> V_32 ) ;
#endif
if ( V_2 -> V_29 -> V_32 > 0 )
V_2 -> V_29 -> V_32 -- ;
V_2 -> V_29 = NULL ;
}
F_60 ( & V_2 -> V_39 ) ;
}
static inline int T_2
F_64 ( struct V_1 * V_2 , struct V_20 * V_21 ,
struct V_27 * V_29 )
{
struct V_25 * V_26 = F_43 ( V_2 , struct V_25 , V_39 ) ;
struct V_27 * V_48 = F_44 ( V_26 -> V_29 ) ;
struct V_20 * V_38 ;
if ( V_48 && F_31 ( V_29 , V_48 ) )
goto V_49;
V_38 = V_21 ;
F_65 (cur, &lock->wait_list, list) {
if ( V_38 -> V_28 )
goto V_49;
}
return 0 ;
V_49:
#ifdef F_13
F_14 ( V_29 -> V_31 ) ;
V_29 -> V_31 = V_26 ;
#endif
return - V_50 ;
}
static inline int T_2
F_66 ( struct V_20 * V_21 ,
struct V_1 * V_2 ,
struct V_27 * V_28 )
{
struct V_20 * V_38 ;
struct V_51 * V_52 ;
if ( ! V_28 ) {
F_67 ( & V_21 -> V_22 , & V_2 -> V_8 ) ;
return 0 ;
}
V_52 = & V_2 -> V_8 ;
F_68 (cur, &lock->wait_list, list) {
if ( ! V_38 -> V_28 )
continue;
if ( F_31 ( V_28 , V_38 -> V_28 ) ) {
if ( V_28 -> V_32 > 0 ) {
#ifdef F_13
struct V_25 * V_26 ;
V_26 = F_43 ( V_2 , struct V_25 , V_39 ) ;
F_14 ( V_28 -> V_31 ) ;
V_28 -> V_31 = V_26 ;
#endif
return - V_50 ;
}
break;
}
V_52 = & V_38 -> V_22 ;
if ( V_38 -> V_28 -> V_32 > 0 ) {
F_35 ( V_2 , V_38 ) ;
F_36 ( V_38 -> V_16 ) ;
}
}
F_67 ( & V_21 -> V_22 , V_52 ) ;
return 0 ;
}
static T_1 int T_2
F_69 ( struct V_1 * V_2 , long V_53 , unsigned int V_54 ,
struct V_55 * V_56 , unsigned long V_57 ,
struct V_27 * V_28 , const bool V_43 )
{
struct V_20 V_21 ;
bool V_58 = false ;
struct V_25 * V_26 ;
int V_40 ;
F_28 () ;
V_26 = F_43 ( V_2 , struct V_25 , V_39 ) ;
if ( V_43 && V_28 ) {
if ( F_70 ( V_28 == F_44 ( V_26 -> V_29 ) ) )
return - V_59 ;
}
F_71 () ;
F_72 ( & V_2 -> V_60 , V_54 , 0 , V_56 , V_57 ) ;
if ( F_16 ( V_2 ) ||
F_55 ( V_2 , V_28 , V_43 , NULL ) ) {
F_73 ( & V_2 -> V_60 , V_57 ) ;
if ( V_43 && V_28 )
F_37 ( V_26 , V_28 ) ;
F_74 () ;
return 0 ;
}
F_39 ( & V_2 -> V_7 ) ;
if ( F_16 ( V_2 ) ) {
if ( V_43 && V_28 )
F_32 ( V_2 , V_28 ) ;
goto V_61;
}
F_75 ( V_2 , & V_21 ) ;
F_76 ( V_2 , & V_21 , V_13 ) ;
F_77 ( & V_2 -> V_60 , V_57 ) ;
if ( ! V_43 ) {
F_67 ( & V_21 . V_22 , & V_2 -> V_8 ) ;
#ifdef F_13
V_21 . V_28 = V_62 ;
#endif
} else {
V_40 = F_66 ( & V_21 , V_2 , V_28 ) ;
if ( V_40 )
goto V_63;
V_21 . V_28 = V_28 ;
}
V_21 . V_16 = V_13 ;
if ( F_24 ( V_2 , & V_21 ) )
F_20 ( V_2 , V_24 ) ;
F_78 ( V_53 ) ;
for (; ; ) {
if ( F_16 ( V_2 ) )
goto V_32;
if ( F_70 ( F_79 ( V_53 , V_13 ) ) ) {
V_40 = - V_64 ;
goto V_65;
}
if ( V_43 && V_28 && V_28 -> V_32 > 0 ) {
V_40 = F_64 ( V_2 , & V_21 , V_28 ) ;
if ( V_40 )
goto V_65;
}
F_40 ( & V_2 -> V_7 ) ;
F_59 () ;
if ( ( V_43 && V_28 ) || ! V_58 ) {
V_58 = F_24 ( V_2 , & V_21 ) ;
if ( V_58 )
F_20 ( V_2 , V_18 ) ;
}
F_78 ( V_53 ) ;
if ( F_16 ( V_2 ) ||
( V_58 && F_55 ( V_2 , V_28 , V_43 , & V_21 ) ) )
break;
F_39 ( & V_2 -> V_7 ) ;
}
F_39 ( & V_2 -> V_7 ) ;
V_32:
F_58 ( V_46 ) ;
F_80 ( V_2 , & V_21 , V_13 ) ;
if ( F_12 ( F_81 ( & V_2 -> V_8 ) ) )
F_22 ( V_2 , V_11 ) ;
F_82 ( & V_21 ) ;
V_61:
F_73 ( & V_2 -> V_60 , V_57 ) ;
if ( V_43 && V_28 )
F_41 ( V_26 , V_28 ) ;
F_40 ( & V_2 -> V_7 ) ;
F_74 () ;
return 0 ;
V_65:
F_58 ( V_46 ) ;
F_80 ( V_2 , & V_21 , V_13 ) ;
V_63:
F_40 ( & V_2 -> V_7 ) ;
F_82 ( & V_21 ) ;
F_83 ( & V_2 -> V_60 , 1 , V_57 ) ;
F_74 () ;
return V_40 ;
}
static int T_2
F_84 ( struct V_1 * V_2 , long V_53 , unsigned int V_54 ,
struct V_55 * V_56 , unsigned long V_57 )
{
return F_69 ( V_2 , V_53 , V_54 , V_56 , V_57 , NULL , false ) ;
}
static int T_2
F_85 ( struct V_1 * V_2 , long V_53 , unsigned int V_54 ,
struct V_55 * V_56 , unsigned long V_57 ,
struct V_27 * V_28 )
{
return F_69 ( V_2 , V_53 , V_54 , V_56 , V_57 , V_28 , true ) ;
}
void T_2
F_86 ( struct V_1 * V_2 , unsigned int V_54 )
{
F_84 ( V_2 , V_66 , V_54 , NULL , V_47 ) ;
}
void T_2
F_87 ( struct V_1 * V_2 , struct V_55 * V_67 )
{
F_84 ( V_2 , V_66 , 0 , V_67 , V_47 ) ;
}
int T_2
F_88 ( struct V_1 * V_2 , unsigned int V_54 )
{
return F_84 ( V_2 , V_68 , V_54 , NULL , V_47 ) ;
}
int T_2
F_89 ( struct V_1 * V_2 , unsigned int V_54 )
{
return F_84 ( V_2 , V_69 , V_54 , NULL , V_47 ) ;
}
void T_2
F_90 ( struct V_1 * V_2 , unsigned int V_54 )
{
int V_70 ;
F_28 () ;
V_70 = F_91 () ;
F_69 ( V_2 , V_66 ,
V_54 , NULL , V_47 , NULL , 0 ) ;
F_92 ( V_70 ) ;
}
static inline int
F_93 ( struct V_25 * V_2 , struct V_27 * V_29 )
{
#ifdef F_94
unsigned V_71 ;
if ( V_29 -> V_72 -- == 0 ) {
V_71 = V_29 -> V_73 ;
if ( V_71 > V_74 / 4 )
V_71 = V_74 ;
else
V_71 = V_71 * 2 + V_71 + V_71 / 2 ;
V_29 -> V_73 = V_71 ;
V_29 -> V_72 = V_71 ;
V_29 -> V_31 = V_2 ;
F_63 ( V_2 ) ;
return - V_50 ;
}
#endif
return 0 ;
}
int T_2
F_95 ( struct V_25 * V_2 , struct V_27 * V_29 )
{
int V_40 ;
F_28 () ;
V_40 = F_85 ( & V_2 -> V_39 , V_66 ,
0 , V_29 ? & V_29 -> V_60 : NULL , V_47 ,
V_29 ) ;
if ( ! V_40 && V_29 && V_29 -> V_32 > 1 )
return F_93 ( V_2 , V_29 ) ;
return V_40 ;
}
int T_2
F_96 ( struct V_25 * V_2 , struct V_27 * V_29 )
{
int V_40 ;
F_28 () ;
V_40 = F_85 ( & V_2 -> V_39 , V_69 ,
0 , V_29 ? & V_29 -> V_60 : NULL , V_47 ,
V_29 ) ;
if ( ! V_40 && V_29 && V_29 -> V_32 > 1 )
return F_93 ( V_2 , V_29 ) ;
return V_40 ;
}
static T_3 void T_2 F_62 ( struct V_1 * V_2 , unsigned long V_57 )
{
struct V_10 * V_75 = NULL ;
F_97 ( V_76 ) ;
unsigned long V_6 ;
F_83 ( & V_2 -> V_60 , 1 , V_57 ) ;
V_6 = F_11 ( & V_2 -> V_6 ) ;
for (; ; ) {
unsigned long V_14 ;
#ifdef F_13
F_14 ( F_8 ( V_6 ) != V_13 ) ;
F_14 ( V_6 & V_17 ) ;
#endif
if ( V_6 & V_18 )
break;
V_14 = F_19 ( & V_2 -> V_6 , V_6 ,
F_9 ( V_6 ) ) ;
if ( V_14 == V_6 ) {
if ( V_6 & V_24 )
break;
return;
}
V_6 = V_14 ;
}
F_39 ( & V_2 -> V_7 ) ;
F_98 ( V_2 ) ;
if ( ! F_81 ( & V_2 -> V_8 ) ) {
struct V_20 * V_21 =
F_25 ( & V_2 -> V_8 ,
struct V_20 , V_22 ) ;
V_75 = V_21 -> V_16 ;
F_35 ( V_2 , V_21 ) ;
F_99 ( & V_76 , V_75 ) ;
}
if ( V_6 & V_18 )
F_26 ( V_2 , V_75 ) ;
F_40 ( & V_2 -> V_7 ) ;
F_100 ( & V_76 ) ;
}
int T_2 F_101 ( struct V_1 * V_2 )
{
F_28 () ;
if ( F_17 ( V_2 ) )
return 0 ;
return F_102 ( V_2 ) ;
}
int T_2 F_103 ( struct V_1 * V_2 )
{
F_28 () ;
if ( F_17 ( V_2 ) )
return 0 ;
return F_104 ( V_2 ) ;
}
void T_2 F_105 ( struct V_1 * V_2 )
{
int V_70 ;
V_70 = F_91 () ;
F_27 ( V_2 ) ;
F_92 ( V_70 ) ;
}
static T_3 void T_2
F_29 ( struct V_1 * V_2 )
{
F_84 ( V_2 , V_66 , 0 , NULL , V_47 ) ;
}
static T_3 int T_2
F_104 ( struct V_1 * V_2 )
{
return F_84 ( V_2 , V_68 , 0 , NULL , V_47 ) ;
}
static T_3 int T_2
F_102 ( struct V_1 * V_2 )
{
return F_84 ( V_2 , V_69 , 0 , NULL , V_47 ) ;
}
static T_3 int T_2
F_106 ( struct V_25 * V_2 , struct V_27 * V_29 )
{
return F_85 ( & V_2 -> V_39 , V_66 , 0 , NULL ,
V_47 , V_29 ) ;
}
static T_3 int T_2
F_107 ( struct V_25 * V_2 ,
struct V_27 * V_29 )
{
return F_85 ( & V_2 -> V_39 , V_69 , 0 , NULL ,
V_47 , V_29 ) ;
}
int T_2 F_108 ( struct V_1 * V_2 )
{
bool V_77 = F_16 ( V_2 ) ;
if ( V_77 )
F_109 ( & V_2 -> V_60 , 0 , 1 , V_47 ) ;
return V_77 ;
}
int T_2
F_95 ( struct V_25 * V_2 , struct V_27 * V_29 )
{
F_28 () ;
if ( F_17 ( & V_2 -> V_39 ) ) {
if ( V_29 )
F_37 ( V_2 , V_29 ) ;
return 0 ;
}
return F_106 ( V_2 , V_29 ) ;
}
int T_2
F_96 ( struct V_25 * V_2 , struct V_27 * V_29 )
{
F_28 () ;
if ( F_17 ( & V_2 -> V_39 ) ) {
if ( V_29 )
F_37 ( V_2 , V_29 ) ;
return 0 ;
}
return F_107 ( V_2 , V_29 ) ;
}
int F_110 ( T_4 * V_78 , struct V_1 * V_2 )
{
if ( F_111 ( V_78 , - 1 , 1 ) )
return 0 ;
F_27 ( V_2 ) ;
if ( ! F_112 ( V_78 ) ) {
F_60 ( V_2 ) ;
return 0 ;
}
return 1 ;
}
