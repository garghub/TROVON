void
F_1 ( struct V_1 * V_2 , const char * V_3 , struct V_4 * V_5 )
{
F_2 ( & V_2 -> V_6 , 1 ) ;
F_3 ( & V_2 -> V_7 ) ;
F_4 ( & V_2 -> V_8 ) ;
F_5 ( V_2 ) ;
#ifdef F_6
F_7 ( & V_2 -> V_9 ) ;
#endif
F_8 ( V_2 , V_3 , V_5 ) ;
}
void T_1 F_9 ( struct V_1 * V_2 )
{
F_10 () ;
F_11 ( & V_2 -> V_6 , V_10 ) ;
F_12 ( V_2 ) ;
}
static T_2 void F_13 ( struct V_11 * V_12 ,
struct V_13 * V_14 )
{
#ifdef F_14
F_15 ( V_12 -> V_15 ) ;
F_15 ( V_14 -> V_16 ) ;
if ( V_14 -> V_17 ) {
F_15 ( V_14 -> V_17 != V_12 ) ;
F_15 ( V_14 -> V_18 > 0 ) ;
V_14 -> V_17 = NULL ;
}
F_15 ( V_14 -> V_19 != V_12 -> V_19 ) ;
#endif
V_14 -> V_18 ++ ;
}
static T_2 void
F_16 ( struct V_11 * V_2 ,
struct V_13 * V_15 )
{
unsigned long V_20 ;
struct V_21 * V_22 ;
F_13 ( V_2 , V_15 ) ;
V_2 -> V_15 = V_15 ;
F_17 () ;
if ( F_18 ( F_19 ( & V_2 -> V_23 . V_6 ) == 0 ) )
return;
F_20 ( & V_2 -> V_23 . V_7 , V_20 ) ;
F_21 (cur, &lock->base.wait_list, list) {
F_22 ( & V_2 -> V_23 , V_22 ) ;
F_23 ( V_22 -> V_24 ) ;
}
F_24 ( & V_2 -> V_23 . V_7 , V_20 ) ;
}
static T_2 void
F_25 ( struct V_11 * V_2 ,
struct V_13 * V_15 )
{
struct V_21 * V_22 ;
F_13 ( V_2 , V_15 ) ;
V_2 -> V_15 = V_15 ;
F_21 (cur, &lock->base.wait_list, list) {
F_22 ( & V_2 -> V_23 , V_22 ) ;
F_23 ( V_22 -> V_24 ) ;
}
}
static inline bool F_26 ( struct V_1 * V_2 , struct V_25 * V_26 )
{
if ( V_2 -> V_26 != V_26 )
return false ;
F_27 () ;
return V_26 -> V_27 ;
}
static T_3
int F_28 ( struct V_1 * V_2 , struct V_25 * V_26 )
{
F_29 () ;
while ( F_26 ( V_2 , V_26 ) ) {
if ( F_30 () )
break;
F_31 () ;
}
F_32 () ;
return V_2 -> V_26 == NULL ;
}
static inline int F_33 ( struct V_1 * V_2 )
{
struct V_25 * V_26 ;
int V_28 = 1 ;
if ( F_30 () )
return 0 ;
F_29 () ;
V_26 = F_34 ( V_2 -> V_26 ) ;
if ( V_26 )
V_28 = V_26 -> V_27 ;
F_32 () ;
return V_28 ;
}
static inline bool F_35 ( struct V_1 * V_2 )
{
return ! F_36 ( V_2 ) &&
( F_37 ( & V_2 -> V_6 , 1 , 0 ) == 1 ) ;
}
static bool F_38 ( struct V_1 * V_2 ,
struct V_13 * V_14 , const bool V_29 )
{
struct V_25 * V_24 = V_30 ;
if ( ! F_33 ( V_2 ) )
goto V_31;
if ( ! F_39 ( & V_2 -> V_9 ) )
goto V_31;
while ( true ) {
struct V_25 * V_26 ;
if ( V_29 && V_14 -> V_18 > 0 ) {
struct V_11 * V_12 ;
V_12 = F_40 ( V_2 , struct V_11 , V_23 ) ;
if ( F_34 ( V_12 -> V_15 ) )
break;
}
V_26 = F_34 ( V_2 -> V_26 ) ;
if ( V_26 && ! F_28 ( V_2 , V_26 ) )
break;
if ( F_35 ( V_2 ) ) {
F_41 ( & V_2 -> V_32 , V_33 ) ;
if ( V_29 ) {
struct V_11 * V_12 ;
V_12 = F_40 ( V_2 , struct V_11 , V_23 ) ;
F_16 ( V_12 , V_14 ) ;
}
F_12 ( V_2 ) ;
F_42 ( & V_2 -> V_9 ) ;
return true ;
}
if ( ! V_26 && ( F_30 () || F_43 ( V_24 ) ) )
break;
F_31 () ;
}
F_42 ( & V_2 -> V_9 ) ;
V_31:
if ( F_30 () ) {
F_44 ( V_34 ) ;
F_45 () ;
}
return false ;
}
static bool F_38 ( struct V_1 * V_2 ,
struct V_13 * V_14 , const bool V_29 )
{
return false ;
}
void T_1 F_46 ( struct V_1 * V_2 )
{
#ifndef F_14
F_5 ( V_2 ) ;
#endif
F_47 ( & V_2 -> V_6 , V_35 ) ;
}
void T_1 F_48 ( struct V_11 * V_2 )
{
if ( V_2 -> V_15 ) {
#ifdef F_14
F_15 ( ! V_2 -> V_15 -> V_18 ) ;
#endif
if ( V_2 -> V_15 -> V_18 > 0 )
V_2 -> V_15 -> V_18 -- ;
V_2 -> V_15 = NULL ;
}
#ifndef F_14
F_5 ( & V_2 -> V_23 ) ;
#endif
F_47 ( & V_2 -> V_23 . V_6 , V_35 ) ;
}
static inline int T_1
F_49 ( struct V_1 * V_2 , struct V_13 * V_15 )
{
struct V_11 * V_12 = F_40 ( V_2 , struct V_11 , V_23 ) ;
struct V_13 * V_36 = F_34 ( V_12 -> V_15 ) ;
if ( ! V_36 )
return 0 ;
if ( F_50 ( V_15 == V_36 ) )
return - V_37 ;
if ( V_15 -> V_38 - V_36 -> V_38 <= V_39 &&
( V_15 -> V_38 != V_36 -> V_38 || V_15 > V_36 ) ) {
#ifdef F_14
F_15 ( V_15 -> V_17 ) ;
V_15 -> V_17 = V_12 ;
#endif
return - V_40 ;
}
return 0 ;
}
static T_2 int T_1
F_51 ( struct V_1 * V_2 , long V_41 , unsigned int V_42 ,
struct V_43 * V_44 , unsigned long V_33 ,
struct V_13 * V_14 , const bool V_29 )
{
struct V_25 * V_24 = V_30 ;
struct V_21 V_45 ;
unsigned long V_20 ;
int V_46 ;
F_52 () ;
F_53 ( & V_2 -> V_32 , V_42 , 0 , V_44 , V_33 ) ;
if ( F_38 ( V_2 , V_14 , V_29 ) ) {
F_54 () ;
return 0 ;
}
F_20 ( & V_2 -> V_7 , V_20 ) ;
if ( ! F_36 ( V_2 ) && ( F_55 ( & V_2 -> V_6 , 0 ) == 1 ) )
goto V_47;
F_56 ( V_2 , & V_45 ) ;
F_57 ( V_2 , & V_45 , F_58 ( V_24 ) ) ;
F_59 ( & V_45 . V_48 , & V_2 -> V_8 ) ;
V_45 . V_24 = V_24 ;
F_60 ( & V_2 -> V_32 , V_33 ) ;
for (; ; ) {
if ( F_19 ( & V_2 -> V_6 ) >= 0 &&
( F_55 ( & V_2 -> V_6 , - 1 ) == 1 ) )
break;
if ( F_50 ( F_61 ( V_41 , V_24 ) ) ) {
V_46 = - V_49 ;
goto V_50;
}
if ( V_29 && V_14 -> V_18 > 0 ) {
V_46 = F_49 ( V_2 , V_14 ) ;
if ( V_46 )
goto V_50;
}
F_62 ( V_24 , V_41 ) ;
F_24 ( & V_2 -> V_7 , V_20 ) ;
F_45 () ;
F_20 ( & V_2 -> V_7 , V_20 ) ;
}
F_62 ( V_24 , V_34 ) ;
F_63 ( V_2 , & V_45 , F_64 () ) ;
if ( F_18 ( F_65 ( & V_2 -> V_8 ) ) )
F_2 ( & V_2 -> V_6 , 0 ) ;
F_66 ( & V_45 ) ;
V_47:
F_41 ( & V_2 -> V_32 , V_33 ) ;
F_12 ( V_2 ) ;
if ( V_29 ) {
struct V_11 * V_12 = F_40 ( V_2 , struct V_11 , V_23 ) ;
F_25 ( V_12 , V_14 ) ;
}
F_24 ( & V_2 -> V_7 , V_20 ) ;
F_54 () ;
return 0 ;
V_50:
F_63 ( V_2 , & V_45 , F_58 ( V_24 ) ) ;
F_24 ( & V_2 -> V_7 , V_20 ) ;
F_66 ( & V_45 ) ;
F_67 ( & V_2 -> V_32 , 1 , V_33 ) ;
F_54 () ;
return V_46 ;
}
void T_1
F_68 ( struct V_1 * V_2 , unsigned int V_42 )
{
F_10 () ;
F_51 ( V_2 , V_51 ,
V_42 , NULL , V_52 , NULL , 0 ) ;
}
void T_1
F_69 ( struct V_1 * V_2 , struct V_43 * V_53 )
{
F_10 () ;
F_51 ( V_2 , V_51 ,
0 , V_53 , V_52 , NULL , 0 ) ;
}
int T_1
F_70 ( struct V_1 * V_2 , unsigned int V_42 )
{
F_10 () ;
return F_51 ( V_2 , V_54 ,
V_42 , NULL , V_52 , NULL , 0 ) ;
}
int T_1
F_71 ( struct V_1 * V_2 , unsigned int V_42 )
{
F_10 () ;
return F_51 ( V_2 , V_55 ,
V_42 , NULL , V_52 , NULL , 0 ) ;
}
static inline int
F_72 ( struct V_11 * V_2 , struct V_13 * V_15 )
{
#ifdef F_73
unsigned V_56 ;
if ( V_15 -> V_57 -- == 0 ) {
V_56 = V_15 -> V_58 ;
if ( V_56 > V_59 / 4 )
V_56 = V_59 ;
else
V_56 = V_56 * 2 + V_56 + V_56 / 2 ;
V_15 -> V_58 = V_56 ;
V_15 -> V_57 = V_56 ;
V_15 -> V_17 = V_2 ;
F_48 ( V_2 ) ;
return - V_40 ;
}
#endif
return 0 ;
}
int T_1
F_74 ( struct V_11 * V_2 , struct V_13 * V_15 )
{
int V_46 ;
F_10 () ;
V_46 = F_51 ( & V_2 -> V_23 , V_51 ,
0 , & V_15 -> V_32 , V_52 , V_15 , 1 ) ;
if ( ! V_46 && V_15 -> V_18 > 1 )
return F_72 ( V_2 , V_15 ) ;
return V_46 ;
}
int T_1
F_75 ( struct V_11 * V_2 , struct V_13 * V_15 )
{
int V_46 ;
F_10 () ;
V_46 = F_51 ( & V_2 -> V_23 , V_55 ,
0 , & V_15 -> V_32 , V_52 , V_15 , 1 ) ;
if ( ! V_46 && V_15 -> V_18 > 1 )
return F_72 ( V_2 , V_15 ) ;
return V_46 ;
}
static inline void
F_76 ( struct V_1 * V_2 , int V_60 )
{
unsigned long V_20 ;
if ( F_77 () )
F_2 ( & V_2 -> V_6 , 1 ) ;
F_20 ( & V_2 -> V_7 , V_20 ) ;
F_67 ( & V_2 -> V_32 , V_60 , V_52 ) ;
F_78 ( V_2 ) ;
if ( ! F_65 ( & V_2 -> V_8 ) ) {
struct V_21 * V_45 =
F_79 ( V_2 -> V_8 . V_61 ,
struct V_21 , V_48 ) ;
F_22 ( V_2 , V_45 ) ;
F_23 ( V_45 -> V_24 ) ;
}
F_24 ( & V_2 -> V_7 , V_20 ) ;
}
T_4 void
V_35 ( T_5 * V_62 )
{
struct V_1 * V_2 = F_40 ( V_62 , struct V_1 , V_6 ) ;
F_76 ( V_2 , 1 ) ;
}
int T_1 F_80 ( struct V_1 * V_2 )
{
int V_46 ;
F_10 () ;
V_46 = F_81 ( & V_2 -> V_6 ) ;
if ( F_18 ( ! V_46 ) ) {
F_12 ( V_2 ) ;
return 0 ;
} else
return F_82 ( V_2 ) ;
}
int T_1 F_83 ( struct V_1 * V_2 )
{
int V_46 ;
F_10 () ;
V_46 = F_81 ( & V_2 -> V_6 ) ;
if ( F_18 ( ! V_46 ) ) {
F_12 ( V_2 ) ;
return 0 ;
} else
return F_84 ( V_2 ) ;
}
T_4 void T_1
V_10 ( T_5 * V_62 )
{
struct V_1 * V_2 = F_40 ( V_62 , struct V_1 , V_6 ) ;
F_51 ( V_2 , V_51 , 0 ,
NULL , V_52 , NULL , 0 ) ;
}
static T_3 int T_1
F_84 ( struct V_1 * V_2 )
{
return F_51 ( V_2 , V_54 , 0 ,
NULL , V_52 , NULL , 0 ) ;
}
static T_3 int T_1
F_82 ( struct V_1 * V_2 )
{
return F_51 ( V_2 , V_55 , 0 ,
NULL , V_52 , NULL , 0 ) ;
}
static T_3 int T_1
F_85 ( struct V_11 * V_2 , struct V_13 * V_15 )
{
return F_51 ( & V_2 -> V_23 , V_51 , 0 ,
NULL , V_52 , V_15 , 1 ) ;
}
static T_3 int T_1
F_86 ( struct V_11 * V_2 ,
struct V_13 * V_15 )
{
return F_51 ( & V_2 -> V_23 , V_55 , 0 ,
NULL , V_52 , V_15 , 1 ) ;
}
static inline int F_87 ( T_5 * V_62 )
{
struct V_1 * V_2 = F_40 ( V_62 , struct V_1 , V_6 ) ;
unsigned long V_20 ;
int V_63 ;
if ( F_36 ( V_2 ) )
return 0 ;
F_20 ( & V_2 -> V_7 , V_20 ) ;
V_63 = F_55 ( & V_2 -> V_6 , - 1 ) ;
if ( F_18 ( V_63 == 1 ) ) {
F_12 ( V_2 ) ;
F_88 ( & V_2 -> V_32 , 0 , 1 , V_52 ) ;
}
if ( F_18 ( F_65 ( & V_2 -> V_8 ) ) )
F_2 ( & V_2 -> V_6 , 0 ) ;
F_24 ( & V_2 -> V_7 , V_20 ) ;
return V_63 == 1 ;
}
int T_1 F_89 ( struct V_1 * V_2 )
{
int V_46 ;
V_46 = F_90 ( & V_2 -> V_6 , F_87 ) ;
if ( V_46 )
F_12 ( V_2 ) ;
return V_46 ;
}
int T_1
F_74 ( struct V_11 * V_2 , struct V_13 * V_15 )
{
int V_46 ;
F_10 () ;
V_46 = F_81 ( & V_2 -> V_23 . V_6 ) ;
if ( F_18 ( ! V_46 ) ) {
F_16 ( V_2 , V_15 ) ;
F_12 ( & V_2 -> V_23 ) ;
} else
V_46 = F_85 ( V_2 , V_15 ) ;
return V_46 ;
}
int T_1
F_75 ( struct V_11 * V_2 , struct V_13 * V_15 )
{
int V_46 ;
F_10 () ;
V_46 = F_81 ( & V_2 -> V_23 . V_6 ) ;
if ( F_18 ( ! V_46 ) ) {
F_16 ( V_2 , V_15 ) ;
F_12 ( & V_2 -> V_23 ) ;
} else
V_46 = F_86 ( V_2 , V_15 ) ;
return V_46 ;
}
int F_91 ( T_5 * V_64 , struct V_1 * V_2 )
{
if ( F_92 ( V_64 , - 1 , 1 ) )
return 0 ;
F_9 ( V_2 ) ;
if ( ! F_93 ( V_64 ) ) {
F_46 ( V_2 ) ;
return 0 ;
}
return 1 ;
}
