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
static inline bool F_10 ( struct V_1 * V_2 , const bool V_12 )
{
unsigned long V_6 , V_13 = ( unsigned long ) V_14 ;
V_6 = F_11 ( & V_2 -> V_6 ) ;
for (; ; ) {
unsigned long V_15 , V_16 = F_9 ( V_6 ) ;
if ( F_8 ( V_6 ) ) {
if ( V_12 && F_12 ( F_8 ( V_6 ) == V_14 ) ) {
F_13 () ;
return true ;
}
return false ;
}
if ( V_12 )
V_16 &= ~ V_17 ;
V_15 = F_14 ( & V_2 -> V_6 , V_6 , V_13 | V_16 ) ;
if ( V_15 == V_6 )
return true ;
V_6 = V_15 ;
}
}
static T_1 bool F_15 ( struct V_1 * V_2 )
{
unsigned long V_13 = ( unsigned long ) V_14 ;
if ( ! F_14 ( & V_2 -> V_6 , 0UL , V_13 ) )
return true ;
return false ;
}
static T_1 bool F_16 ( struct V_1 * V_2 )
{
unsigned long V_13 = ( unsigned long ) V_14 ;
if ( F_17 ( & V_2 -> V_6 , V_13 , 0UL ) == V_13 )
return true ;
return false ;
}
static inline void F_18 ( struct V_1 * V_2 , unsigned long V_18 )
{
F_19 ( V_18 , & V_2 -> V_6 ) ;
}
static inline void F_20 ( struct V_1 * V_2 , unsigned long V_18 )
{
F_21 ( V_18 , & V_2 -> V_6 ) ;
}
static inline bool F_22 ( struct V_1 * V_2 , struct V_19 * V_20 )
{
return F_23 ( & V_2 -> V_8 , struct V_19 , V_21 ) == V_20 ;
}
static void F_24 ( struct V_1 * V_2 , struct V_10 * V_22 )
{
unsigned long V_6 = F_11 ( & V_2 -> V_6 ) ;
for (; ; ) {
unsigned long V_15 , V_23 ;
#ifdef F_25
F_26 ( F_8 ( V_6 ) != V_14 ) ;
#endif
V_23 = ( V_6 & V_24 ) ;
V_23 |= ( unsigned long ) V_22 ;
V_15 = F_17 ( & V_2 -> V_6 , V_6 , V_23 ) ;
if ( V_15 == V_6 )
break;
V_6 = V_15 ;
}
}
void T_2 F_27 ( struct V_1 * V_2 )
{
F_28 () ;
if ( ! F_15 ( V_2 ) )
F_29 ( V_2 ) ;
}
static T_1 void F_30 ( struct V_25 * V_26 ,
struct V_27 * V_28 )
{
#ifdef F_25
F_26 ( V_26 -> V_29 ) ;
F_26 ( V_28 -> V_30 ) ;
if ( V_28 -> V_31 ) {
F_26 ( V_28 -> V_31 != V_26 ) ;
F_26 ( V_28 -> V_32 > 0 ) ;
V_28 -> V_31 = NULL ;
}
F_26 ( V_28 -> V_33 != V_26 -> V_33 ) ;
#endif
V_28 -> V_32 ++ ;
}
static T_1 void
F_31 ( struct V_25 * V_2 ,
struct V_27 * V_29 )
{
unsigned long V_16 ;
struct V_19 * V_34 ;
F_30 ( V_2 , V_29 ) ;
V_2 -> V_29 = V_29 ;
F_13 () ;
if ( F_32 ( ! ( F_11 ( & V_2 -> V_35 . V_6 ) & V_24 ) ) )
return;
F_33 ( & V_2 -> V_35 . V_7 , V_16 ) ;
F_34 (cur, &lock->base.wait_list, list) {
F_35 ( & V_2 -> V_35 , V_34 ) ;
F_36 ( V_34 -> V_22 ) ;
}
F_37 ( & V_2 -> V_35 . V_7 , V_16 ) ;
}
static T_1 void
F_38 ( struct V_25 * V_2 ,
struct V_27 * V_29 )
{
struct V_19 * V_34 ;
F_30 ( V_2 , V_29 ) ;
V_2 -> V_29 = V_29 ;
F_34 (cur, &lock->base.wait_list, list) {
F_35 ( & V_2 -> V_35 , V_34 ) ;
F_36 ( V_34 -> V_22 ) ;
}
}
static T_3
bool F_39 ( struct V_1 * V_2 , struct V_10 * V_6 )
{
bool V_36 = true ;
F_40 () ;
while ( F_41 ( V_2 ) == V_6 ) {
F_42 () ;
if ( ! V_6 -> V_37 || F_43 () ||
F_44 ( F_45 ( V_6 ) ) ) {
V_36 = false ;
break;
}
F_46 () ;
}
F_47 () ;
return V_36 ;
}
static inline int F_48 ( struct V_1 * V_2 )
{
struct V_10 * V_6 ;
int V_38 = 1 ;
if ( F_43 () )
return 0 ;
F_40 () ;
V_6 = F_41 ( V_2 ) ;
if ( V_6 )
V_38 = V_6 -> V_37 && ! F_44 ( F_45 ( V_6 ) ) ;
F_47 () ;
return V_38 ;
}
static bool F_49 ( struct V_1 * V_2 ,
struct V_27 * V_28 ,
const bool V_39 , const bool V_20 )
{
struct V_10 * V_22 = V_14 ;
if ( ! V_20 ) {
if ( ! F_48 ( V_2 ) )
goto V_40;
if ( ! F_50 ( & V_2 -> V_9 ) )
goto V_40;
}
for (; ; ) {
struct V_10 * V_6 ;
if ( V_39 && V_28 -> V_32 > 0 ) {
struct V_25 * V_26 ;
V_26 = F_51 ( V_2 , struct V_25 , V_35 ) ;
if ( F_52 ( V_26 -> V_29 ) )
goto V_41;
}
V_6 = F_41 ( V_2 ) ;
if ( V_6 ) {
if ( V_20 && V_6 == V_22 ) {
F_13 () ;
break;
}
if ( ! F_39 ( V_2 , V_6 ) )
goto V_41;
}
if ( F_10 ( V_2 , V_20 ) )
break;
F_46 () ;
}
if ( ! V_20 )
F_53 ( & V_2 -> V_9 ) ;
return true ;
V_41:
if ( ! V_20 )
F_53 ( & V_2 -> V_9 ) ;
V_40:
if ( F_43 () ) {
F_54 ( V_42 ) ;
F_55 () ;
}
return false ;
}
static bool F_49 ( struct V_1 * V_2 ,
struct V_27 * V_28 ,
const bool V_39 , const bool V_20 )
{
return false ;
}
void T_2 F_56 ( struct V_1 * V_2 )
{
#ifndef F_57
if ( F_16 ( V_2 ) )
return;
#endif
F_58 ( V_2 , V_43 ) ;
}
void T_2 F_59 ( struct V_25 * V_2 )
{
if ( V_2 -> V_29 ) {
#ifdef F_25
F_26 ( ! V_2 -> V_29 -> V_32 ) ;
#endif
if ( V_2 -> V_29 -> V_32 > 0 )
V_2 -> V_29 -> V_32 -- ;
V_2 -> V_29 = NULL ;
}
F_56 ( & V_2 -> V_35 ) ;
}
static inline int T_2
F_60 ( struct V_1 * V_2 , struct V_27 * V_29 )
{
struct V_25 * V_26 = F_51 ( V_2 , struct V_25 , V_35 ) ;
struct V_27 * V_44 = F_52 ( V_26 -> V_29 ) ;
if ( ! V_44 )
return 0 ;
if ( V_29 -> V_45 - V_44 -> V_45 <= V_46 &&
( V_29 -> V_45 != V_44 -> V_45 || V_29 > V_44 ) ) {
#ifdef F_25
F_26 ( V_29 -> V_31 ) ;
V_29 -> V_31 = V_26 ;
#endif
return - V_47 ;
}
return 0 ;
}
static T_1 int T_2
F_61 ( struct V_1 * V_2 , long V_48 , unsigned int V_49 ,
struct V_50 * V_51 , unsigned long V_52 ,
struct V_27 * V_28 , const bool V_39 )
{
struct V_10 * V_22 = V_14 ;
struct V_19 V_20 ;
unsigned long V_16 ;
bool V_53 = false ;
struct V_25 * V_26 ;
int V_36 ;
if ( V_39 ) {
V_26 = F_51 ( V_2 , struct V_25 , V_35 ) ;
if ( F_12 ( V_28 == F_52 ( V_26 -> V_29 ) ) )
return - V_54 ;
}
F_62 () ;
F_63 ( & V_2 -> V_55 , V_49 , 0 , V_51 , V_52 ) ;
if ( F_10 ( V_2 , false ) ||
F_49 ( V_2 , V_28 , V_39 , false ) ) {
F_64 ( & V_2 -> V_55 , V_52 ) ;
if ( V_39 )
F_31 ( V_26 , V_28 ) ;
F_65 () ;
return 0 ;
}
F_33 ( & V_2 -> V_7 , V_16 ) ;
if ( F_10 ( V_2 , false ) )
goto V_56;
F_66 ( V_2 , & V_20 ) ;
F_67 ( V_2 , & V_20 , V_22 ) ;
F_68 ( & V_20 . V_21 , & V_2 -> V_8 ) ;
V_20 . V_22 = V_22 ;
if ( F_22 ( V_2 , & V_20 ) )
F_18 ( V_2 , V_24 ) ;
F_69 ( & V_2 -> V_55 , V_52 ) ;
F_70 ( V_22 , V_48 ) ;
for (; ; ) {
if ( F_10 ( V_2 , V_53 ) )
goto V_32;
if ( F_12 ( F_71 ( V_48 , V_22 ) ) ) {
V_36 = - V_57 ;
goto V_58;
}
if ( V_39 && V_28 -> V_32 > 0 ) {
V_36 = F_60 ( V_2 , V_28 ) ;
if ( V_36 )
goto V_58;
}
F_37 ( & V_2 -> V_7 , V_16 ) ;
F_55 () ;
if ( ! V_53 && F_22 ( V_2 , & V_20 ) ) {
V_53 = true ;
F_18 ( V_2 , V_17 ) ;
}
F_70 ( V_22 , V_48 ) ;
if ( ( V_53 && F_49 ( V_2 , V_28 , V_39 , true ) ) ||
F_10 ( V_2 , V_53 ) )
break;
F_33 ( & V_2 -> V_7 , V_16 ) ;
}
F_33 ( & V_2 -> V_7 , V_16 ) ;
V_32:
F_72 ( V_22 , V_42 ) ;
F_73 ( V_2 , & V_20 , V_22 ) ;
if ( F_32 ( F_74 ( & V_2 -> V_8 ) ) )
F_20 ( V_2 , V_11 ) ;
F_75 ( & V_20 ) ;
V_56:
F_64 ( & V_2 -> V_55 , V_52 ) ;
if ( V_39 )
F_38 ( V_26 , V_28 ) ;
F_37 ( & V_2 -> V_7 , V_16 ) ;
F_65 () ;
return 0 ;
V_58:
F_72 ( V_22 , V_42 ) ;
F_73 ( V_2 , & V_20 , V_22 ) ;
F_37 ( & V_2 -> V_7 , V_16 ) ;
F_75 ( & V_20 ) ;
F_76 ( & V_2 -> V_55 , 1 , V_52 ) ;
F_65 () ;
return V_36 ;
}
void T_2
F_77 ( struct V_1 * V_2 , unsigned int V_49 )
{
F_28 () ;
F_61 ( V_2 , V_59 ,
V_49 , NULL , V_43 , NULL , 0 ) ;
}
void T_2
F_78 ( struct V_1 * V_2 , struct V_50 * V_60 )
{
F_28 () ;
F_61 ( V_2 , V_59 ,
0 , V_60 , V_43 , NULL , 0 ) ;
}
int T_2
F_79 ( struct V_1 * V_2 , unsigned int V_49 )
{
F_28 () ;
return F_61 ( V_2 , V_61 ,
V_49 , NULL , V_43 , NULL , 0 ) ;
}
int T_2
F_80 ( struct V_1 * V_2 , unsigned int V_49 )
{
F_28 () ;
return F_61 ( V_2 , V_62 ,
V_49 , NULL , V_43 , NULL , 0 ) ;
}
static inline int
F_81 ( struct V_25 * V_2 , struct V_27 * V_29 )
{
#ifdef F_82
unsigned V_63 ;
if ( V_29 -> V_64 -- == 0 ) {
V_63 = V_29 -> V_65 ;
if ( V_63 > V_66 / 4 )
V_63 = V_66 ;
else
V_63 = V_63 * 2 + V_63 + V_63 / 2 ;
V_29 -> V_65 = V_63 ;
V_29 -> V_64 = V_63 ;
V_29 -> V_31 = V_2 ;
F_59 ( V_2 ) ;
return - V_47 ;
}
#endif
return 0 ;
}
int T_2
F_83 ( struct V_25 * V_2 , struct V_27 * V_29 )
{
int V_36 ;
F_28 () ;
V_36 = F_61 ( & V_2 -> V_35 , V_59 ,
0 , & V_29 -> V_55 , V_43 , V_29 , 1 ) ;
if ( ! V_36 && V_29 -> V_32 > 1 )
return F_81 ( V_2 , V_29 ) ;
return V_36 ;
}
int T_2
F_84 ( struct V_25 * V_2 , struct V_27 * V_29 )
{
int V_36 ;
F_28 () ;
V_36 = F_61 ( & V_2 -> V_35 , V_62 ,
0 , & V_29 -> V_55 , V_43 , V_29 , 1 ) ;
if ( ! V_36 && V_29 -> V_32 > 1 )
return F_81 ( V_2 , V_29 ) ;
return V_36 ;
}
static T_3 void T_2 F_58 ( struct V_1 * V_2 , unsigned long V_52 )
{
struct V_10 * V_67 = NULL ;
unsigned long V_6 , V_16 ;
F_85 ( V_68 ) ;
F_76 ( & V_2 -> V_55 , 1 , V_52 ) ;
V_6 = F_11 ( & V_2 -> V_6 ) ;
for (; ; ) {
unsigned long V_15 ;
#ifdef F_25
F_26 ( F_8 ( V_6 ) != V_14 ) ;
#endif
if ( V_6 & V_17 )
break;
V_15 = F_17 ( & V_2 -> V_6 , V_6 ,
F_9 ( V_6 ) ) ;
if ( V_15 == V_6 ) {
if ( V_6 & V_24 )
break;
return;
}
V_6 = V_15 ;
}
F_33 ( & V_2 -> V_7 , V_16 ) ;
F_86 ( V_2 ) ;
if ( ! F_74 ( & V_2 -> V_8 ) ) {
struct V_19 * V_20 =
F_23 ( & V_2 -> V_8 ,
struct V_19 , V_21 ) ;
V_67 = V_20 -> V_22 ;
F_35 ( V_2 , V_20 ) ;
F_87 ( & V_68 , V_67 ) ;
}
if ( V_6 & V_17 )
F_24 ( V_2 , V_67 ) ;
F_37 ( & V_2 -> V_7 , V_16 ) ;
F_88 ( & V_68 ) ;
}
int T_2 F_89 ( struct V_1 * V_2 )
{
F_28 () ;
if ( F_15 ( V_2 ) )
return 0 ;
return F_90 ( V_2 ) ;
}
int T_2 F_91 ( struct V_1 * V_2 )
{
F_28 () ;
if ( F_15 ( V_2 ) )
return 0 ;
return F_92 ( V_2 ) ;
}
static T_3 void T_2
F_29 ( struct V_1 * V_2 )
{
F_61 ( V_2 , V_59 , 0 ,
NULL , V_43 , NULL , 0 ) ;
}
static T_3 int T_2
F_92 ( struct V_1 * V_2 )
{
return F_61 ( V_2 , V_61 , 0 ,
NULL , V_43 , NULL , 0 ) ;
}
static T_3 int T_2
F_90 ( struct V_1 * V_2 )
{
return F_61 ( V_2 , V_62 , 0 ,
NULL , V_43 , NULL , 0 ) ;
}
static T_3 int T_2
F_93 ( struct V_25 * V_2 , struct V_27 * V_29 )
{
return F_61 ( & V_2 -> V_35 , V_59 , 0 ,
NULL , V_43 , V_29 , 1 ) ;
}
static T_3 int T_2
F_94 ( struct V_25 * V_2 ,
struct V_27 * V_29 )
{
return F_61 ( & V_2 -> V_35 , V_62 , 0 ,
NULL , V_43 , V_29 , 1 ) ;
}
int T_2 F_95 ( struct V_1 * V_2 )
{
bool V_69 = F_10 ( V_2 , false ) ;
if ( V_69 )
F_96 ( & V_2 -> V_55 , 0 , 1 , V_43 ) ;
return V_69 ;
}
int T_2
F_83 ( struct V_25 * V_2 , struct V_27 * V_29 )
{
F_28 () ;
if ( F_15 ( & V_2 -> V_35 ) ) {
F_31 ( V_2 , V_29 ) ;
return 0 ;
}
return F_93 ( V_2 , V_29 ) ;
}
int T_2
F_84 ( struct V_25 * V_2 , struct V_27 * V_29 )
{
F_28 () ;
if ( F_15 ( & V_2 -> V_35 ) ) {
F_31 ( V_2 , V_29 ) ;
return 0 ;
}
return F_94 ( V_2 , V_29 ) ;
}
int F_97 ( T_4 * V_70 , struct V_1 * V_2 )
{
if ( F_98 ( V_70 , - 1 , 1 ) )
return 0 ;
F_27 ( V_2 ) ;
if ( ! F_99 ( V_70 ) ) {
F_56 ( V_2 ) ;
return 0 ;
}
return 1 ;
}
