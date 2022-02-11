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
static inline bool F_25 ( struct V_1 * V_2 , struct V_25 * V_26 )
{
if ( V_2 -> V_26 != V_26 )
return false ;
F_26 () ;
return V_26 -> V_27 ;
}
static T_3
int F_27 ( struct V_1 * V_2 , struct V_25 * V_26 )
{
F_28 () ;
while ( F_25 ( V_2 , V_26 ) ) {
if ( F_29 () )
break;
F_30 () ;
}
F_31 () ;
return V_2 -> V_26 == NULL ;
}
static inline int F_32 ( struct V_1 * V_2 )
{
struct V_25 * V_26 ;
int V_28 = 1 ;
if ( F_29 () )
return 0 ;
F_28 () ;
V_26 = F_33 ( V_2 -> V_26 ) ;
if ( V_26 )
V_28 = V_26 -> V_27 ;
F_31 () ;
return V_28 ;
}
static inline bool F_34 ( struct V_1 * V_2 )
{
return ! F_35 ( V_2 ) &&
( F_36 ( & V_2 -> V_6 , 1 , 0 ) == 1 ) ;
}
static bool F_37 ( struct V_1 * V_2 ,
struct V_13 * V_14 , const bool V_29 )
{
struct V_25 * V_24 = V_30 ;
if ( ! F_32 ( V_2 ) )
goto V_31;
if ( ! F_38 ( & V_2 -> V_9 ) )
goto V_31;
while ( true ) {
struct V_25 * V_26 ;
if ( V_29 && V_14 -> V_18 > 0 ) {
struct V_11 * V_12 ;
V_12 = F_39 ( V_2 , struct V_11 , V_23 ) ;
if ( F_33 ( V_12 -> V_15 ) )
break;
}
V_26 = F_33 ( V_2 -> V_26 ) ;
if ( V_26 && ! F_27 ( V_2 , V_26 ) )
break;
if ( F_34 ( V_2 ) ) {
F_40 ( & V_2 -> V_32 , V_33 ) ;
if ( V_29 ) {
struct V_11 * V_12 ;
V_12 = F_39 ( V_2 , struct V_11 , V_23 ) ;
F_16 ( V_12 , V_14 ) ;
}
F_12 ( V_2 ) ;
F_41 ( & V_2 -> V_9 ) ;
return true ;
}
if ( ! V_26 && ( F_29 () || F_42 ( V_24 ) ) )
break;
F_30 () ;
}
F_41 ( & V_2 -> V_9 ) ;
V_31:
if ( F_29 () )
F_43 () ;
return false ;
}
static bool F_37 ( struct V_1 * V_2 ,
struct V_13 * V_14 , const bool V_29 )
{
return false ;
}
void T_1 F_44 ( struct V_1 * V_2 )
{
#ifndef F_14
F_5 ( V_2 ) ;
#endif
F_45 ( & V_2 -> V_6 , V_34 ) ;
}
void T_1 F_46 ( struct V_11 * V_2 )
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
F_45 ( & V_2 -> V_23 . V_6 , V_34 ) ;
}
static inline int T_1
F_47 ( struct V_1 * V_2 , struct V_13 * V_15 )
{
struct V_11 * V_12 = F_39 ( V_2 , struct V_11 , V_23 ) ;
struct V_13 * V_35 = F_33 ( V_12 -> V_15 ) ;
if ( ! V_35 )
return 0 ;
if ( F_48 ( V_15 == V_35 ) )
return - V_36 ;
if ( V_15 -> V_37 - V_35 -> V_37 <= V_38 &&
( V_15 -> V_37 != V_35 -> V_37 || V_15 > V_35 ) ) {
#ifdef F_14
F_15 ( V_15 -> V_17 ) ;
V_15 -> V_17 = V_12 ;
#endif
return - V_39 ;
}
return 0 ;
}
static T_2 int T_1
F_49 ( struct V_1 * V_2 , long V_40 , unsigned int V_41 ,
struct V_42 * V_43 , unsigned long V_33 ,
struct V_13 * V_14 , const bool V_29 )
{
struct V_25 * V_24 = V_30 ;
struct V_21 V_44 ;
unsigned long V_20 ;
int V_45 ;
F_50 () ;
F_51 ( & V_2 -> V_32 , V_41 , 0 , V_43 , V_33 ) ;
if ( F_37 ( V_2 , V_14 , V_29 ) ) {
F_52 () ;
return 0 ;
}
F_20 ( & V_2 -> V_7 , V_20 ) ;
if ( ! F_35 ( V_2 ) && ( F_53 ( & V_2 -> V_6 , 0 ) == 1 ) )
goto V_46;
F_54 ( V_2 , & V_44 ) ;
F_55 ( V_2 , & V_44 , F_56 ( V_24 ) ) ;
F_57 ( & V_44 . V_47 , & V_2 -> V_8 ) ;
V_44 . V_24 = V_24 ;
F_58 ( & V_2 -> V_32 , V_33 ) ;
for (; ; ) {
if ( F_19 ( & V_2 -> V_6 ) >= 0 &&
( F_53 ( & V_2 -> V_6 , - 1 ) == 1 ) )
break;
if ( F_48 ( F_59 ( V_40 , V_24 ) ) ) {
V_45 = - V_48 ;
goto V_49;
}
if ( V_29 && V_14 -> V_18 > 0 ) {
V_45 = F_47 ( V_2 , V_14 ) ;
if ( V_45 )
goto V_49;
}
F_60 ( V_24 , V_40 ) ;
F_24 ( & V_2 -> V_7 , V_20 ) ;
F_43 () ;
F_20 ( & V_2 -> V_7 , V_20 ) ;
}
F_61 ( V_2 , & V_44 , F_62 () ) ;
if ( F_18 ( F_63 ( & V_2 -> V_8 ) ) )
F_2 ( & V_2 -> V_6 , 0 ) ;
F_64 ( & V_44 ) ;
V_46:
F_40 ( & V_2 -> V_32 , V_33 ) ;
F_12 ( V_2 ) ;
if ( V_29 ) {
struct V_11 * V_12 = F_39 ( V_2 , struct V_11 , V_23 ) ;
struct V_21 * V_22 ;
F_13 ( V_12 , V_14 ) ;
V_12 -> V_15 = V_14 ;
F_21 (cur, &lock->wait_list, list) {
F_22 ( V_2 , V_22 ) ;
F_23 ( V_22 -> V_24 ) ;
}
}
F_24 ( & V_2 -> V_7 , V_20 ) ;
F_52 () ;
return 0 ;
V_49:
F_61 ( V_2 , & V_44 , F_56 ( V_24 ) ) ;
F_24 ( & V_2 -> V_7 , V_20 ) ;
F_64 ( & V_44 ) ;
F_65 ( & V_2 -> V_32 , 1 , V_33 ) ;
F_52 () ;
return V_45 ;
}
void T_1
F_66 ( struct V_1 * V_2 , unsigned int V_41 )
{
F_10 () ;
F_49 ( V_2 , V_50 ,
V_41 , NULL , V_51 , NULL , 0 ) ;
}
void T_1
F_67 ( struct V_1 * V_2 , struct V_42 * V_52 )
{
F_10 () ;
F_49 ( V_2 , V_50 ,
0 , V_52 , V_51 , NULL , 0 ) ;
}
int T_1
F_68 ( struct V_1 * V_2 , unsigned int V_41 )
{
F_10 () ;
return F_49 ( V_2 , V_53 ,
V_41 , NULL , V_51 , NULL , 0 ) ;
}
int T_1
F_69 ( struct V_1 * V_2 , unsigned int V_41 )
{
F_10 () ;
return F_49 ( V_2 , V_54 ,
V_41 , NULL , V_51 , NULL , 0 ) ;
}
static inline int
F_70 ( struct V_11 * V_2 , struct V_13 * V_15 )
{
#ifdef F_71
unsigned V_55 ;
if ( V_15 -> V_56 -- == 0 ) {
V_55 = V_15 -> V_57 ;
if ( V_55 > V_58 / 4 )
V_55 = V_58 ;
else
V_55 = V_55 * 2 + V_55 + V_55 / 2 ;
V_15 -> V_57 = V_55 ;
V_15 -> V_56 = V_55 ;
V_15 -> V_17 = V_2 ;
F_46 ( V_2 ) ;
return - V_39 ;
}
#endif
return 0 ;
}
int T_1
F_72 ( struct V_11 * V_2 , struct V_13 * V_15 )
{
int V_45 ;
F_10 () ;
V_45 = F_49 ( & V_2 -> V_23 , V_50 ,
0 , & V_15 -> V_32 , V_51 , V_15 , 1 ) ;
if ( ! V_45 && V_15 -> V_18 > 1 )
return F_70 ( V_2 , V_15 ) ;
return V_45 ;
}
int T_1
F_73 ( struct V_11 * V_2 , struct V_13 * V_15 )
{
int V_45 ;
F_10 () ;
V_45 = F_49 ( & V_2 -> V_23 , V_54 ,
0 , & V_15 -> V_32 , V_51 , V_15 , 1 ) ;
if ( ! V_45 && V_15 -> V_18 > 1 )
return F_70 ( V_2 , V_15 ) ;
return V_45 ;
}
static inline void
F_74 ( struct V_1 * V_2 , int V_59 )
{
unsigned long V_20 ;
if ( F_75 () )
F_2 ( & V_2 -> V_6 , 1 ) ;
F_20 ( & V_2 -> V_7 , V_20 ) ;
F_65 ( & V_2 -> V_32 , V_59 , V_51 ) ;
F_76 ( V_2 ) ;
if ( ! F_63 ( & V_2 -> V_8 ) ) {
struct V_21 * V_44 =
F_77 ( V_2 -> V_8 . V_60 ,
struct V_21 , V_47 ) ;
F_22 ( V_2 , V_44 ) ;
F_23 ( V_44 -> V_24 ) ;
}
F_24 ( & V_2 -> V_7 , V_20 ) ;
}
T_4 void
V_34 ( T_5 * V_61 )
{
struct V_1 * V_2 = F_39 ( V_61 , struct V_1 , V_6 ) ;
F_74 ( V_2 , 1 ) ;
}
int T_1 F_78 ( struct V_1 * V_2 )
{
int V_45 ;
F_10 () ;
V_45 = F_79 ( & V_2 -> V_6 ) ;
if ( F_18 ( ! V_45 ) ) {
F_12 ( V_2 ) ;
return 0 ;
} else
return F_80 ( V_2 ) ;
}
int T_1 F_81 ( struct V_1 * V_2 )
{
int V_45 ;
F_10 () ;
V_45 = F_79 ( & V_2 -> V_6 ) ;
if ( F_18 ( ! V_45 ) ) {
F_12 ( V_2 ) ;
return 0 ;
} else
return F_82 ( V_2 ) ;
}
T_4 void T_1
V_10 ( T_5 * V_61 )
{
struct V_1 * V_2 = F_39 ( V_61 , struct V_1 , V_6 ) ;
F_49 ( V_2 , V_50 , 0 ,
NULL , V_51 , NULL , 0 ) ;
}
static T_3 int T_1
F_82 ( struct V_1 * V_2 )
{
return F_49 ( V_2 , V_53 , 0 ,
NULL , V_51 , NULL , 0 ) ;
}
static T_3 int T_1
F_80 ( struct V_1 * V_2 )
{
return F_49 ( V_2 , V_54 , 0 ,
NULL , V_51 , NULL , 0 ) ;
}
static T_3 int T_1
F_83 ( struct V_11 * V_2 , struct V_13 * V_15 )
{
return F_49 ( & V_2 -> V_23 , V_50 , 0 ,
NULL , V_51 , V_15 , 1 ) ;
}
static T_3 int T_1
F_84 ( struct V_11 * V_2 ,
struct V_13 * V_15 )
{
return F_49 ( & V_2 -> V_23 , V_54 , 0 ,
NULL , V_51 , V_15 , 1 ) ;
}
static inline int F_85 ( T_5 * V_61 )
{
struct V_1 * V_2 = F_39 ( V_61 , struct V_1 , V_6 ) ;
unsigned long V_20 ;
int V_62 ;
if ( F_35 ( V_2 ) )
return 0 ;
F_20 ( & V_2 -> V_7 , V_20 ) ;
V_62 = F_53 ( & V_2 -> V_6 , - 1 ) ;
if ( F_18 ( V_62 == 1 ) ) {
F_12 ( V_2 ) ;
F_86 ( & V_2 -> V_32 , 0 , 1 , V_51 ) ;
}
if ( F_18 ( F_63 ( & V_2 -> V_8 ) ) )
F_2 ( & V_2 -> V_6 , 0 ) ;
F_24 ( & V_2 -> V_7 , V_20 ) ;
return V_62 == 1 ;
}
int T_1 F_87 ( struct V_1 * V_2 )
{
int V_45 ;
V_45 = F_88 ( & V_2 -> V_6 , F_85 ) ;
if ( V_45 )
F_12 ( V_2 ) ;
return V_45 ;
}
int T_1
F_72 ( struct V_11 * V_2 , struct V_13 * V_15 )
{
int V_45 ;
F_10 () ;
V_45 = F_79 ( & V_2 -> V_23 . V_6 ) ;
if ( F_18 ( ! V_45 ) ) {
F_16 ( V_2 , V_15 ) ;
F_12 ( & V_2 -> V_23 ) ;
} else
V_45 = F_83 ( V_2 , V_15 ) ;
return V_45 ;
}
int T_1
F_73 ( struct V_11 * V_2 , struct V_13 * V_15 )
{
int V_45 ;
F_10 () ;
V_45 = F_79 ( & V_2 -> V_23 . V_6 ) ;
if ( F_18 ( ! V_45 ) ) {
F_16 ( V_2 , V_15 ) ;
F_12 ( & V_2 -> V_23 ) ;
} else
V_45 = F_84 ( V_2 , V_15 ) ;
return V_45 ;
}
int F_89 ( T_5 * V_63 , struct V_1 * V_2 )
{
if ( F_90 ( V_63 , - 1 , 1 ) )
return 0 ;
F_9 ( V_2 ) ;
if ( ! F_91 ( V_63 ) ) {
F_44 ( V_2 ) ;
return 0 ;
}
return 1 ;
}
