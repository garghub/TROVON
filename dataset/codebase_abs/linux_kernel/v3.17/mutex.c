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
static inline bool F_13 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
if ( V_2 -> V_12 != V_12 )
return false ;
F_14 () ;
return V_12 -> V_13 ;
}
static T_2
int F_15 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
F_16 () ;
while ( F_13 ( V_2 , V_12 ) ) {
if ( F_17 () )
break;
F_18 () ;
}
F_19 () ;
return V_2 -> V_12 == NULL ;
}
static inline int F_20 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
int V_14 = 1 ;
if ( F_17 () )
return 0 ;
F_16 () ;
V_12 = F_21 ( V_2 -> V_12 ) ;
if ( V_12 )
V_14 = V_12 -> V_13 ;
F_19 () ;
return V_14 ;
}
void T_1 F_22 ( struct V_1 * V_2 )
{
#ifndef F_23
F_5 ( V_2 ) ;
#endif
F_24 ( & V_2 -> V_6 , V_15 ) ;
}
void T_1 F_25 ( struct V_16 * V_2 )
{
if ( V_2 -> V_17 ) {
#ifdef F_23
F_26 ( ! V_2 -> V_17 -> V_18 ) ;
#endif
if ( V_2 -> V_17 -> V_18 > 0 )
V_2 -> V_17 -> V_18 -- ;
V_2 -> V_17 = NULL ;
}
#ifndef F_23
F_5 ( & V_2 -> V_19 ) ;
#endif
F_24 ( & V_2 -> V_19 . V_6 , V_15 ) ;
}
static inline int T_1
F_27 ( struct V_1 * V_2 , struct V_20 * V_17 )
{
struct V_16 * V_21 = F_28 ( V_2 , struct V_16 , V_19 ) ;
struct V_20 * V_22 = F_21 ( V_21 -> V_17 ) ;
if ( ! V_22 )
return 0 ;
if ( F_29 ( V_17 == V_22 ) )
return - V_23 ;
if ( V_17 -> V_24 - V_22 -> V_24 <= V_25 &&
( V_17 -> V_24 != V_22 -> V_24 || V_17 > V_22 ) ) {
#ifdef F_23
F_26 ( V_17 -> V_26 ) ;
V_17 -> V_26 = V_21 ;
#endif
return - V_27 ;
}
return 0 ;
}
static T_3 void F_30 ( struct V_16 * V_21 ,
struct V_20 * V_28 )
{
#ifdef F_23
F_26 ( V_21 -> V_17 ) ;
F_26 ( V_28 -> V_29 ) ;
if ( V_28 -> V_26 ) {
F_26 ( V_28 -> V_26 != V_21 ) ;
F_26 ( V_28 -> V_18 > 0 ) ;
V_28 -> V_26 = NULL ;
}
F_26 ( V_28 -> V_30 != V_21 -> V_30 ) ;
#endif
V_28 -> V_18 ++ ;
}
static T_3 void
F_31 ( struct V_16 * V_2 ,
struct V_20 * V_17 )
{
unsigned long V_31 ;
struct V_32 * V_33 ;
F_30 ( V_2 , V_17 ) ;
V_2 -> V_17 = V_17 ;
F_32 () ;
if ( F_33 ( F_34 ( & V_2 -> V_19 . V_6 ) == 0 ) )
return;
F_35 ( & V_2 -> V_19 . V_7 , V_31 ) ;
F_36 (cur, &lock->base.wait_list, list) {
F_37 ( & V_2 -> V_19 , V_33 ) ;
F_38 ( V_33 -> V_34 ) ;
}
F_39 ( & V_2 -> V_19 . V_7 , V_31 ) ;
}
static T_3 int T_1
F_40 ( struct V_1 * V_2 , long V_35 , unsigned int V_36 ,
struct V_37 * V_38 , unsigned long V_39 ,
struct V_20 * V_28 , const bool V_40 )
{
struct V_11 * V_34 = V_41 ;
struct V_32 V_42 ;
unsigned long V_31 ;
int V_43 ;
F_41 () ;
F_42 ( & V_2 -> V_44 , V_36 , 0 , V_38 , V_39 ) ;
#ifdef F_6
if ( ! F_20 ( V_2 ) )
goto V_45;
if ( ! F_43 ( & V_2 -> V_9 ) )
goto V_45;
for (; ; ) {
struct V_11 * V_12 ;
if ( V_40 && V_28 -> V_18 > 0 ) {
struct V_16 * V_21 ;
V_21 = F_28 ( V_2 , struct V_16 , V_19 ) ;
if ( F_21 ( V_21 -> V_17 ) )
break;
}
V_12 = F_21 ( V_2 -> V_12 ) ;
if ( V_12 && ! F_15 ( V_2 , V_12 ) )
break;
if ( ! F_44 ( V_2 ) &&
( F_45 ( & V_2 -> V_6 , 1 , 0 ) == 1 ) ) {
F_46 ( & V_2 -> V_44 , V_39 ) ;
if ( V_40 ) {
struct V_16 * V_21 ;
V_21 = F_28 ( V_2 , struct V_16 , V_19 ) ;
F_31 ( V_21 , V_28 ) ;
}
F_12 ( V_2 ) ;
F_47 ( & V_2 -> V_9 ) ;
F_48 () ;
return 0 ;
}
if ( ! V_12 && ( F_17 () || F_49 ( V_34 ) ) )
break;
F_18 () ;
}
F_47 ( & V_2 -> V_9 ) ;
V_45:
if ( F_17 () )
F_50 () ;
#endif
F_35 ( & V_2 -> V_7 , V_31 ) ;
if ( ! F_44 ( V_2 ) && ( F_51 ( & V_2 -> V_6 , 0 ) == 1 ) )
goto V_46;
F_52 ( V_2 , & V_42 ) ;
F_53 ( V_2 , & V_42 , F_54 ( V_34 ) ) ;
F_55 ( & V_42 . V_47 , & V_2 -> V_8 ) ;
V_42 . V_34 = V_34 ;
F_56 ( & V_2 -> V_44 , V_39 ) ;
for (; ; ) {
if ( F_34 ( & V_2 -> V_6 ) >= 0 &&
( F_51 ( & V_2 -> V_6 , - 1 ) == 1 ) )
break;
if ( F_29 ( F_57 ( V_35 , V_34 ) ) ) {
V_43 = - V_48 ;
goto V_49;
}
if ( V_40 && V_28 -> V_18 > 0 ) {
V_43 = F_27 ( V_2 , V_28 ) ;
if ( V_43 )
goto V_49;
}
F_58 ( V_34 , V_35 ) ;
F_39 ( & V_2 -> V_7 , V_31 ) ;
F_50 () ;
F_35 ( & V_2 -> V_7 , V_31 ) ;
}
F_59 ( V_2 , & V_42 , F_60 () ) ;
if ( F_33 ( F_61 ( & V_2 -> V_8 ) ) )
F_2 ( & V_2 -> V_6 , 0 ) ;
F_62 ( & V_42 ) ;
V_46:
F_46 ( & V_2 -> V_44 , V_39 ) ;
F_12 ( V_2 ) ;
if ( V_40 ) {
struct V_16 * V_21 = F_28 ( V_2 , struct V_16 , V_19 ) ;
struct V_32 * V_33 ;
F_30 ( V_21 , V_28 ) ;
V_21 -> V_17 = V_28 ;
F_36 (cur, &lock->wait_list, list) {
F_37 ( V_2 , V_33 ) ;
F_38 ( V_33 -> V_34 ) ;
}
}
F_39 ( & V_2 -> V_7 , V_31 ) ;
F_48 () ;
return 0 ;
V_49:
F_59 ( V_2 , & V_42 , F_54 ( V_34 ) ) ;
F_39 ( & V_2 -> V_7 , V_31 ) ;
F_62 ( & V_42 ) ;
F_63 ( & V_2 -> V_44 , 1 , V_39 ) ;
F_48 () ;
return V_43 ;
}
void T_1
F_64 ( struct V_1 * V_2 , unsigned int V_36 )
{
F_10 () ;
F_40 ( V_2 , V_50 ,
V_36 , NULL , V_51 , NULL , 0 ) ;
}
void T_1
F_65 ( struct V_1 * V_2 , struct V_37 * V_52 )
{
F_10 () ;
F_40 ( V_2 , V_50 ,
0 , V_52 , V_51 , NULL , 0 ) ;
}
int T_1
F_66 ( struct V_1 * V_2 , unsigned int V_36 )
{
F_10 () ;
return F_40 ( V_2 , V_53 ,
V_36 , NULL , V_51 , NULL , 0 ) ;
}
int T_1
F_67 ( struct V_1 * V_2 , unsigned int V_36 )
{
F_10 () ;
return F_40 ( V_2 , V_54 ,
V_36 , NULL , V_51 , NULL , 0 ) ;
}
static inline int
F_68 ( struct V_16 * V_2 , struct V_20 * V_17 )
{
#ifdef F_69
unsigned V_55 ;
if ( V_17 -> V_56 -- == 0 ) {
V_55 = V_17 -> V_57 ;
if ( V_55 > V_58 / 4 )
V_55 = V_58 ;
else
V_55 = V_55 * 2 + V_55 + V_55 / 2 ;
V_17 -> V_57 = V_55 ;
V_17 -> V_56 = V_55 ;
V_17 -> V_26 = V_2 ;
F_25 ( V_2 ) ;
return - V_27 ;
}
#endif
return 0 ;
}
int T_1
F_70 ( struct V_16 * V_2 , struct V_20 * V_17 )
{
int V_43 ;
F_10 () ;
V_43 = F_40 ( & V_2 -> V_19 , V_50 ,
0 , & V_17 -> V_44 , V_51 , V_17 , 1 ) ;
if ( ! V_43 && V_17 -> V_18 > 1 )
return F_68 ( V_2 , V_17 ) ;
return V_43 ;
}
int T_1
F_71 ( struct V_16 * V_2 , struct V_20 * V_17 )
{
int V_43 ;
F_10 () ;
V_43 = F_40 ( & V_2 -> V_19 , V_54 ,
0 , & V_17 -> V_44 , V_51 , V_17 , 1 ) ;
if ( ! V_43 && V_17 -> V_18 > 1 )
return F_68 ( V_2 , V_17 ) ;
return V_43 ;
}
static inline void
F_72 ( T_4 * V_59 , int V_60 )
{
struct V_1 * V_2 = F_28 ( V_59 , struct V_1 , V_6 ) ;
unsigned long V_31 ;
if ( F_73 () )
F_2 ( & V_2 -> V_6 , 1 ) ;
F_35 ( & V_2 -> V_7 , V_31 ) ;
F_63 ( & V_2 -> V_44 , V_60 , V_51 ) ;
F_74 ( V_2 ) ;
if ( ! F_61 ( & V_2 -> V_8 ) ) {
struct V_32 * V_42 =
F_75 ( V_2 -> V_8 . V_61 ,
struct V_32 , V_47 ) ;
F_37 ( V_2 , V_42 ) ;
F_38 ( V_42 -> V_34 ) ;
}
F_39 ( & V_2 -> V_7 , V_31 ) ;
}
T_5 void
V_15 ( T_4 * V_59 )
{
F_72 ( V_59 , 1 ) ;
}
int T_1 F_76 ( struct V_1 * V_2 )
{
int V_43 ;
F_10 () ;
V_43 = F_77 ( & V_2 -> V_6 ) ;
if ( F_33 ( ! V_43 ) ) {
F_12 ( V_2 ) ;
return 0 ;
} else
return F_78 ( V_2 ) ;
}
int T_1 F_79 ( struct V_1 * V_2 )
{
int V_43 ;
F_10 () ;
V_43 = F_77 ( & V_2 -> V_6 ) ;
if ( F_33 ( ! V_43 ) ) {
F_12 ( V_2 ) ;
return 0 ;
} else
return F_80 ( V_2 ) ;
}
T_5 void T_1
V_10 ( T_4 * V_59 )
{
struct V_1 * V_2 = F_28 ( V_59 , struct V_1 , V_6 ) ;
F_40 ( V_2 , V_50 , 0 ,
NULL , V_51 , NULL , 0 ) ;
}
static T_2 int T_1
F_80 ( struct V_1 * V_2 )
{
return F_40 ( V_2 , V_53 , 0 ,
NULL , V_51 , NULL , 0 ) ;
}
static T_2 int T_1
F_78 ( struct V_1 * V_2 )
{
return F_40 ( V_2 , V_54 , 0 ,
NULL , V_51 , NULL , 0 ) ;
}
static T_2 int T_1
F_81 ( struct V_16 * V_2 , struct V_20 * V_17 )
{
return F_40 ( & V_2 -> V_19 , V_50 , 0 ,
NULL , V_51 , V_17 , 1 ) ;
}
static T_2 int T_1
F_82 ( struct V_16 * V_2 ,
struct V_20 * V_17 )
{
return F_40 ( & V_2 -> V_19 , V_54 , 0 ,
NULL , V_51 , V_17 , 1 ) ;
}
static inline int F_83 ( T_4 * V_59 )
{
struct V_1 * V_2 = F_28 ( V_59 , struct V_1 , V_6 ) ;
unsigned long V_31 ;
int V_62 ;
if ( F_44 ( V_2 ) )
return 0 ;
F_35 ( & V_2 -> V_7 , V_31 ) ;
V_62 = F_51 ( & V_2 -> V_6 , - 1 ) ;
if ( F_33 ( V_62 == 1 ) ) {
F_12 ( V_2 ) ;
F_84 ( & V_2 -> V_44 , 0 , 1 , V_51 ) ;
}
if ( F_33 ( F_61 ( & V_2 -> V_8 ) ) )
F_2 ( & V_2 -> V_6 , 0 ) ;
F_39 ( & V_2 -> V_7 , V_31 ) ;
return V_62 == 1 ;
}
int T_1 F_85 ( struct V_1 * V_2 )
{
int V_43 ;
V_43 = F_86 ( & V_2 -> V_6 , F_83 ) ;
if ( V_43 )
F_12 ( V_2 ) ;
return V_43 ;
}
int T_1
F_70 ( struct V_16 * V_2 , struct V_20 * V_17 )
{
int V_43 ;
F_10 () ;
V_43 = F_77 ( & V_2 -> V_19 . V_6 ) ;
if ( F_33 ( ! V_43 ) ) {
F_31 ( V_2 , V_17 ) ;
F_12 ( & V_2 -> V_19 ) ;
} else
V_43 = F_81 ( V_2 , V_17 ) ;
return V_43 ;
}
int T_1
F_71 ( struct V_16 * V_2 , struct V_20 * V_17 )
{
int V_43 ;
F_10 () ;
V_43 = F_77 ( & V_2 -> V_19 . V_6 ) ;
if ( F_33 ( ! V_43 ) ) {
F_31 ( V_2 , V_17 ) ;
F_12 ( & V_2 -> V_19 ) ;
} else
V_43 = F_82 ( V_2 , V_17 ) ;
return V_43 ;
}
int F_87 ( T_4 * V_63 , struct V_1 * V_2 )
{
if ( F_88 ( V_63 , - 1 , 1 ) )
return 0 ;
F_9 ( V_2 ) ;
if ( ! F_89 ( V_63 ) ) {
F_22 ( V_2 ) ;
return 0 ;
}
return 1 ;
}
