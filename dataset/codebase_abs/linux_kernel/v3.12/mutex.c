void
F_1 ( struct V_1 * V_2 , const char * V_3 , struct V_4 * V_5 )
{
F_2 ( & V_2 -> V_6 , 1 ) ;
F_3 ( & V_2 -> V_7 ) ;
F_4 ( & V_2 -> V_8 ) ;
F_5 ( V_2 ) ;
#ifdef F_6
V_2 -> V_9 = NULL ;
#endif
F_7 ( V_2 , V_3 , V_5 ) ;
}
void T_1 F_8 ( struct V_1 * V_2 )
{
F_9 () ;
F_10 ( & V_2 -> V_6 , V_10 ) ;
F_11 ( V_2 ) ;
}
static T_2
void F_12 ( struct V_11 * * V_2 , struct V_11 * V_12 )
{
struct V_11 * V_13 ;
V_12 -> V_14 = 0 ;
V_12 -> V_15 = NULL ;
V_13 = F_13 ( V_2 , V_12 ) ;
if ( F_14 ( V_13 == NULL ) ) {
V_12 -> V_14 = 1 ;
return;
}
F_15 ( V_13 -> V_15 ) = V_12 ;
F_16 () ;
while ( ! F_15 ( V_12 -> V_14 ) )
F_17 () ;
}
static void F_18 ( struct V_11 * * V_2 , struct V_11 * V_12 )
{
struct V_11 * V_15 = F_15 ( V_12 -> V_15 ) ;
if ( F_14 ( ! V_15 ) ) {
if ( F_19 ( V_2 , V_12 , NULL ) == V_12 )
return;
while ( ! ( V_15 = F_15 ( V_12 -> V_15 ) ) )
F_17 () ;
}
F_15 ( V_15 -> V_14 ) = 1 ;
F_16 () ;
}
static inline bool F_20 ( struct V_1 * V_2 , struct V_16 * V_17 )
{
if ( V_2 -> V_17 != V_17 )
return false ;
F_21 () ;
return V_17 -> V_18 ;
}
static T_2
int F_22 ( struct V_1 * V_2 , struct V_16 * V_17 )
{
F_23 () ;
while ( F_20 ( V_2 , V_17 ) ) {
if ( F_24 () )
break;
F_17 () ;
}
F_25 () ;
return V_2 -> V_17 == NULL ;
}
static inline int F_26 ( struct V_1 * V_2 )
{
struct V_16 * V_17 ;
int V_19 = 1 ;
F_23 () ;
V_17 = F_15 ( V_2 -> V_17 ) ;
if ( V_17 )
V_19 = V_17 -> V_18 ;
F_25 () ;
return V_19 ;
}
void T_1 F_27 ( struct V_1 * V_2 )
{
#ifndef F_28
F_5 ( V_2 ) ;
#endif
F_29 ( & V_2 -> V_6 , V_20 ) ;
}
void T_1 F_30 ( struct V_21 * V_2 )
{
if ( V_2 -> V_22 ) {
#ifdef F_28
F_31 ( ! V_2 -> V_22 -> V_23 ) ;
#endif
if ( V_2 -> V_22 -> V_23 > 0 )
V_2 -> V_22 -> V_23 -- ;
V_2 -> V_22 = NULL ;
}
#ifndef F_28
F_5 ( & V_2 -> V_24 ) ;
#endif
F_29 ( & V_2 -> V_24 . V_6 , V_20 ) ;
}
static inline int T_1
F_32 ( struct V_1 * V_2 , struct V_25 * V_22 )
{
struct V_21 * V_26 = F_33 ( V_2 , struct V_21 , V_24 ) ;
struct V_25 * V_27 = F_15 ( V_26 -> V_22 ) ;
if ( ! V_27 )
return 0 ;
if ( F_34 ( V_22 == V_27 ) )
return - V_28 ;
if ( V_22 -> V_29 - V_27 -> V_29 <= V_30 &&
( V_22 -> V_29 != V_27 -> V_29 || V_22 > V_27 ) ) {
#ifdef F_28
F_31 ( V_22 -> V_31 ) ;
V_22 -> V_31 = V_26 ;
#endif
return - V_32 ;
}
return 0 ;
}
static T_3 void F_35 ( struct V_21 * V_26 ,
struct V_25 * V_33 )
{
#ifdef F_28
F_31 ( V_26 -> V_22 ) ;
F_31 ( V_33 -> V_34 ) ;
if ( V_33 -> V_31 ) {
F_31 ( V_33 -> V_31 != V_26 ) ;
F_31 ( V_33 -> V_23 > 0 ) ;
V_33 -> V_31 = NULL ;
}
F_31 ( V_33 -> V_35 != V_26 -> V_35 ) ;
#endif
V_33 -> V_23 ++ ;
}
static T_3 void
F_36 ( struct V_21 * V_2 ,
struct V_25 * V_22 )
{
unsigned long V_36 ;
struct V_37 * V_38 ;
F_35 ( V_2 , V_22 ) ;
V_2 -> V_22 = V_22 ;
F_37 () ;
if ( F_14 ( F_38 ( & V_2 -> V_24 . V_6 ) == 0 ) )
return;
F_39 ( & V_2 -> V_24 . V_7 , V_36 ) ;
F_40 (cur, &lock->base.wait_list, list) {
F_41 ( & V_2 -> V_24 , V_38 ) ;
F_42 ( V_38 -> V_39 ) ;
}
F_43 ( & V_2 -> V_24 . V_7 , V_36 ) ;
}
static T_3 int T_1
F_44 ( struct V_1 * V_2 , long V_40 , unsigned int V_41 ,
struct V_42 * V_43 , unsigned long V_44 ,
struct V_25 * V_33 , const bool V_45 )
{
struct V_16 * V_39 = V_46 ;
struct V_37 V_47 ;
unsigned long V_36 ;
int V_48 ;
F_45 () ;
F_46 ( & V_2 -> V_49 , V_41 , 0 , V_43 , V_44 ) ;
#ifdef F_6
if ( ! F_26 ( V_2 ) )
goto V_50;
for (; ; ) {
struct V_16 * V_17 ;
struct V_11 V_12 ;
if ( V_45 && V_33 -> V_23 > 0 ) {
struct V_21 * V_26 ;
V_26 = F_33 ( V_2 , struct V_21 , V_24 ) ;
if ( F_15 ( V_26 -> V_22 ) )
goto V_50;
}
F_12 ( F_47 ( V_2 ) , & V_12 ) ;
V_17 = F_15 ( V_2 -> V_17 ) ;
if ( V_17 && ! F_22 ( V_2 , V_17 ) ) {
F_18 ( F_47 ( V_2 ) , & V_12 ) ;
goto V_50;
}
if ( ( F_38 ( & V_2 -> V_6 ) == 1 ) &&
( F_48 ( & V_2 -> V_6 , 1 , 0 ) == 1 ) ) {
F_49 ( & V_2 -> V_49 , V_44 ) ;
if ( V_45 ) {
struct V_21 * V_26 ;
V_26 = F_33 ( V_2 , struct V_21 , V_24 ) ;
F_36 ( V_26 , V_33 ) ;
}
F_11 ( V_2 ) ;
F_18 ( F_47 ( V_2 ) , & V_12 ) ;
F_50 () ;
return 0 ;
}
F_18 ( F_47 ( V_2 ) , & V_12 ) ;
if ( ! V_17 && ( F_24 () || F_51 ( V_39 ) ) )
goto V_50;
F_17 () ;
}
V_50:
#endif
F_39 ( & V_2 -> V_7 , V_36 ) ;
if ( F_52 ( V_2 ) && ( F_53 ( & V_2 -> V_6 , 0 ) == 1 ) )
goto V_51;
F_54 ( V_2 , & V_47 ) ;
F_55 ( V_2 , & V_47 , F_56 ( V_39 ) ) ;
F_57 ( & V_47 . V_52 , & V_2 -> V_8 ) ;
V_47 . V_39 = V_39 ;
F_58 ( & V_2 -> V_49 , V_44 ) ;
for (; ; ) {
if ( F_52 ( V_2 ) &&
( F_53 ( & V_2 -> V_6 , - 1 ) == 1 ) )
break;
if ( F_34 ( F_59 ( V_40 , V_39 ) ) ) {
V_48 = - V_53 ;
goto V_54;
}
if ( V_45 && V_33 -> V_23 > 0 ) {
V_48 = F_32 ( V_2 , V_33 ) ;
if ( V_48 )
goto V_54;
}
F_60 ( V_39 , V_40 ) ;
F_43 ( & V_2 -> V_7 , V_36 ) ;
F_61 () ;
F_39 ( & V_2 -> V_7 , V_36 ) ;
}
F_62 ( V_2 , & V_47 , F_63 () ) ;
if ( F_14 ( F_64 ( & V_2 -> V_8 ) ) )
F_2 ( & V_2 -> V_6 , 0 ) ;
F_65 ( & V_47 ) ;
V_51:
F_49 ( & V_2 -> V_49 , V_44 ) ;
F_11 ( V_2 ) ;
if ( V_45 ) {
struct V_21 * V_26 = F_33 ( V_2 , struct V_21 , V_24 ) ;
struct V_37 * V_38 ;
F_35 ( V_26 , V_33 ) ;
V_26 -> V_22 = V_33 ;
F_40 (cur, &lock->wait_list, list) {
F_41 ( V_2 , V_38 ) ;
F_42 ( V_38 -> V_39 ) ;
}
}
F_43 ( & V_2 -> V_7 , V_36 ) ;
F_50 () ;
return 0 ;
V_54:
F_62 ( V_2 , & V_47 , F_56 ( V_39 ) ) ;
F_43 ( & V_2 -> V_7 , V_36 ) ;
F_65 ( & V_47 ) ;
F_66 ( & V_2 -> V_49 , 1 , V_44 ) ;
F_50 () ;
return V_48 ;
}
void T_1
F_67 ( struct V_1 * V_2 , unsigned int V_41 )
{
F_9 () ;
F_44 ( V_2 , V_55 ,
V_41 , NULL , V_56 , NULL , 0 ) ;
}
void T_1
F_68 ( struct V_1 * V_2 , struct V_42 * V_57 )
{
F_9 () ;
F_44 ( V_2 , V_55 ,
0 , V_57 , V_56 , NULL , 0 ) ;
}
int T_1
F_69 ( struct V_1 * V_2 , unsigned int V_41 )
{
F_9 () ;
return F_44 ( V_2 , V_58 ,
V_41 , NULL , V_56 , NULL , 0 ) ;
}
int T_1
F_70 ( struct V_1 * V_2 , unsigned int V_41 )
{
F_9 () ;
return F_44 ( V_2 , V_59 ,
V_41 , NULL , V_56 , NULL , 0 ) ;
}
static inline int
F_71 ( struct V_21 * V_2 , struct V_25 * V_22 )
{
#ifdef F_72
unsigned V_60 ;
if ( V_22 -> V_61 -- == 0 ) {
V_60 = V_22 -> V_62 ;
if ( V_60 > V_63 / 4 )
V_60 = V_63 ;
else
V_60 = V_60 * 2 + V_60 + V_60 / 2 ;
V_22 -> V_62 = V_60 ;
V_22 -> V_61 = V_60 ;
V_22 -> V_31 = V_2 ;
F_30 ( V_2 ) ;
return - V_32 ;
}
#endif
return 0 ;
}
int T_1
F_73 ( struct V_21 * V_2 , struct V_25 * V_22 )
{
int V_48 ;
F_9 () ;
V_48 = F_44 ( & V_2 -> V_24 , V_55 ,
0 , & V_22 -> V_49 , V_56 , V_22 , 1 ) ;
if ( ! V_48 && V_22 -> V_23 > 1 )
return F_71 ( V_2 , V_22 ) ;
return V_48 ;
}
int T_1
F_74 ( struct V_21 * V_2 , struct V_25 * V_22 )
{
int V_48 ;
F_9 () ;
V_48 = F_44 ( & V_2 -> V_24 , V_59 ,
0 , & V_22 -> V_49 , V_56 , V_22 , 1 ) ;
if ( ! V_48 && V_22 -> V_23 > 1 )
return F_71 ( V_2 , V_22 ) ;
return V_48 ;
}
static inline void
F_75 ( T_4 * V_64 , int V_65 )
{
struct V_1 * V_2 = F_33 ( V_64 , struct V_1 , V_6 ) ;
unsigned long V_36 ;
F_39 ( & V_2 -> V_7 , V_36 ) ;
F_66 ( & V_2 -> V_49 , V_65 , V_56 ) ;
F_76 ( V_2 ) ;
if ( F_77 () )
F_2 ( & V_2 -> V_6 , 1 ) ;
if ( ! F_64 ( & V_2 -> V_8 ) ) {
struct V_37 * V_47 =
F_78 ( V_2 -> V_8 . V_15 ,
struct V_37 , V_52 ) ;
F_41 ( V_2 , V_47 ) ;
F_42 ( V_47 -> V_39 ) ;
}
F_43 ( & V_2 -> V_7 , V_36 ) ;
}
static T_5 T_2 void
V_20 ( T_4 * V_64 )
{
F_75 ( V_64 , 1 ) ;
}
int T_1 F_79 ( struct V_1 * V_2 )
{
int V_48 ;
F_9 () ;
V_48 = F_80 ( & V_2 -> V_6 ) ;
if ( F_14 ( ! V_48 ) ) {
F_11 ( V_2 ) ;
return 0 ;
} else
return F_81 ( V_2 ) ;
}
int T_1 F_82 ( struct V_1 * V_2 )
{
int V_48 ;
F_9 () ;
V_48 = F_80 ( & V_2 -> V_6 ) ;
if ( F_14 ( ! V_48 ) ) {
F_11 ( V_2 ) ;
return 0 ;
} else
return F_83 ( V_2 ) ;
}
static T_5 T_2 void T_1
V_10 ( T_4 * V_64 )
{
struct V_1 * V_2 = F_33 ( V_64 , struct V_1 , V_6 ) ;
F_44 ( V_2 , V_55 , 0 ,
NULL , V_56 , NULL , 0 ) ;
}
static T_2 int T_1
F_83 ( struct V_1 * V_2 )
{
return F_44 ( V_2 , V_58 , 0 ,
NULL , V_56 , NULL , 0 ) ;
}
static T_2 int T_1
F_81 ( struct V_1 * V_2 )
{
return F_44 ( V_2 , V_59 , 0 ,
NULL , V_56 , NULL , 0 ) ;
}
static T_2 int T_1
F_84 ( struct V_21 * V_2 , struct V_25 * V_22 )
{
return F_44 ( & V_2 -> V_24 , V_55 , 0 ,
NULL , V_56 , V_22 , 1 ) ;
}
static T_2 int T_1
F_85 ( struct V_21 * V_2 ,
struct V_25 * V_22 )
{
return F_44 ( & V_2 -> V_24 , V_59 , 0 ,
NULL , V_56 , V_22 , 1 ) ;
}
static inline int F_86 ( T_4 * V_64 )
{
struct V_1 * V_2 = F_33 ( V_64 , struct V_1 , V_6 ) ;
unsigned long V_36 ;
int V_13 ;
F_39 ( & V_2 -> V_7 , V_36 ) ;
V_13 = F_53 ( & V_2 -> V_6 , - 1 ) ;
if ( F_14 ( V_13 == 1 ) ) {
F_11 ( V_2 ) ;
F_87 ( & V_2 -> V_49 , 0 , 1 , V_56 ) ;
}
if ( F_14 ( F_64 ( & V_2 -> V_8 ) ) )
F_2 ( & V_2 -> V_6 , 0 ) ;
F_43 ( & V_2 -> V_7 , V_36 ) ;
return V_13 == 1 ;
}
int T_1 F_88 ( struct V_1 * V_2 )
{
int V_48 ;
V_48 = F_89 ( & V_2 -> V_6 , F_86 ) ;
if ( V_48 )
F_11 ( V_2 ) ;
return V_48 ;
}
int T_1
F_73 ( struct V_21 * V_2 , struct V_25 * V_22 )
{
int V_48 ;
F_9 () ;
V_48 = F_80 ( & V_2 -> V_24 . V_6 ) ;
if ( F_14 ( ! V_48 ) ) {
F_36 ( V_2 , V_22 ) ;
F_11 ( & V_2 -> V_24 ) ;
} else
V_48 = F_84 ( V_2 , V_22 ) ;
return V_48 ;
}
int T_1
F_74 ( struct V_21 * V_2 , struct V_25 * V_22 )
{
int V_48 ;
F_9 () ;
V_48 = F_80 ( & V_2 -> V_24 . V_6 ) ;
if ( F_14 ( ! V_48 ) ) {
F_36 ( V_2 , V_22 ) ;
F_11 ( & V_2 -> V_24 ) ;
} else
V_48 = F_85 ( V_2 , V_22 ) ;
return V_48 ;
}
int F_90 ( T_4 * V_66 , struct V_1 * V_2 )
{
if ( F_91 ( V_66 , - 1 , 1 ) )
return 0 ;
F_8 ( V_2 ) ;
if ( ! F_92 ( V_66 ) ) {
F_27 ( V_2 ) ;
return 0 ;
}
return 1 ;
}
