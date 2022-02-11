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
int V_19 = 1 ;
F_23 () ;
if ( V_2 -> V_17 )
V_19 = V_2 -> V_17 -> V_18 ;
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
static inline int T_1
F_30 ( struct V_1 * V_2 , long V_21 , unsigned int V_22 ,
struct V_23 * V_24 , unsigned long V_25 )
{
struct V_16 * V_26 = V_27 ;
struct V_28 V_29 ;
unsigned long V_30 ;
F_31 () ;
F_32 ( & V_2 -> V_31 , V_22 , 0 , V_24 , V_25 ) ;
#ifdef F_6
if ( ! F_26 ( V_2 ) )
goto V_32;
for (; ; ) {
struct V_16 * V_17 ;
struct V_11 V_12 ;
F_12 ( F_33 ( V_2 ) , & V_12 ) ;
V_17 = F_15 ( V_2 -> V_17 ) ;
if ( V_17 && ! F_22 ( V_2 , V_17 ) ) {
F_18 ( F_33 ( V_2 ) , & V_12 ) ;
break;
}
if ( ( F_34 ( & V_2 -> V_6 ) == 1 ) &&
( F_35 ( & V_2 -> V_6 , 1 , 0 ) == 1 ) ) {
F_36 ( & V_2 -> V_31 , V_25 ) ;
F_11 ( V_2 ) ;
F_18 ( F_33 ( V_2 ) , & V_12 ) ;
F_37 () ;
return 0 ;
}
F_18 ( F_33 ( V_2 ) , & V_12 ) ;
if ( ! V_17 && ( F_24 () || F_38 ( V_26 ) ) )
break;
F_17 () ;
}
V_32:
#endif
F_39 ( & V_2 -> V_7 , V_30 ) ;
F_40 ( V_2 , & V_29 ) ;
F_41 ( V_2 , & V_29 , F_42 ( V_26 ) ) ;
F_43 ( & V_29 . V_33 , & V_2 -> V_8 ) ;
V_29 . V_26 = V_26 ;
if ( F_44 ( V_2 ) && ( F_45 ( & V_2 -> V_6 , - 1 ) == 1 ) )
goto V_34;
F_46 ( & V_2 -> V_31 , V_25 ) ;
for (; ; ) {
if ( F_44 ( V_2 ) &&
( F_45 ( & V_2 -> V_6 , - 1 ) == 1 ) )
break;
if ( F_47 ( F_48 ( V_21 , V_26 ) ) ) {
F_49 ( V_2 , & V_29 ,
F_42 ( V_26 ) ) ;
F_50 ( & V_2 -> V_31 , 1 , V_25 ) ;
F_51 ( & V_2 -> V_7 , V_30 ) ;
F_52 ( & V_29 ) ;
F_37 () ;
return - V_35 ;
}
F_53 ( V_26 , V_21 ) ;
F_51 ( & V_2 -> V_7 , V_30 ) ;
F_54 () ;
F_39 ( & V_2 -> V_7 , V_30 ) ;
}
V_34:
F_36 ( & V_2 -> V_31 , V_25 ) ;
F_49 ( V_2 , & V_29 , F_55 () ) ;
F_11 ( V_2 ) ;
if ( F_14 ( F_56 ( & V_2 -> V_8 ) ) )
F_2 ( & V_2 -> V_6 , 0 ) ;
F_51 ( & V_2 -> V_7 , V_30 ) ;
F_52 ( & V_29 ) ;
F_37 () ;
return 0 ;
}
void T_1
F_57 ( struct V_1 * V_2 , unsigned int V_22 )
{
F_9 () ;
F_30 ( V_2 , V_36 , V_22 , NULL , V_37 ) ;
}
void T_1
F_58 ( struct V_1 * V_2 , struct V_23 * V_38 )
{
F_9 () ;
F_30 ( V_2 , V_36 , 0 , V_38 , V_37 ) ;
}
int T_1
F_59 ( struct V_1 * V_2 , unsigned int V_22 )
{
F_9 () ;
return F_30 ( V_2 , V_39 , V_22 , NULL , V_37 ) ;
}
int T_1
F_60 ( struct V_1 * V_2 , unsigned int V_22 )
{
F_9 () ;
return F_30 ( V_2 , V_40 ,
V_22 , NULL , V_37 ) ;
}
static inline void
F_61 ( T_3 * V_41 , int V_42 )
{
struct V_1 * V_2 = F_62 ( V_41 , struct V_1 , V_6 ) ;
unsigned long V_30 ;
F_39 ( & V_2 -> V_7 , V_30 ) ;
F_50 ( & V_2 -> V_31 , V_42 , V_37 ) ;
F_63 ( V_2 ) ;
if ( F_64 () )
F_2 ( & V_2 -> V_6 , 1 ) ;
if ( ! F_56 ( & V_2 -> V_8 ) ) {
struct V_28 * V_29 =
F_65 ( V_2 -> V_8 . V_15 ,
struct V_28 , V_33 ) ;
F_66 ( V_2 , V_29 ) ;
F_67 ( V_29 -> V_26 ) ;
}
F_51 ( & V_2 -> V_7 , V_30 ) ;
}
static T_4 T_2 void
V_20 ( T_3 * V_41 )
{
F_61 ( V_41 , 1 ) ;
}
int T_1 F_68 ( struct V_1 * V_2 )
{
int V_43 ;
F_9 () ;
V_43 = F_69
( & V_2 -> V_6 , V_44 ) ;
if ( ! V_43 )
F_11 ( V_2 ) ;
return V_43 ;
}
int T_1 F_70 ( struct V_1 * V_2 )
{
int V_43 ;
F_9 () ;
V_43 = F_69
( & V_2 -> V_6 , V_45 ) ;
if ( ! V_43 )
F_11 ( V_2 ) ;
return V_43 ;
}
static T_4 T_2 void T_1
V_10 ( T_3 * V_41 )
{
struct V_1 * V_2 = F_62 ( V_41 , struct V_1 , V_6 ) ;
F_30 ( V_2 , V_36 , 0 , NULL , V_37 ) ;
}
static T_2 int T_1
V_45 ( T_3 * V_41 )
{
struct V_1 * V_2 = F_62 ( V_41 , struct V_1 , V_6 ) ;
return F_30 ( V_2 , V_39 , 0 , NULL , V_37 ) ;
}
static T_2 int T_1
V_44 ( T_3 * V_41 )
{
struct V_1 * V_2 = F_62 ( V_41 , struct V_1 , V_6 ) ;
return F_30 ( V_2 , V_40 , 0 , NULL , V_37 ) ;
}
static inline int F_71 ( T_3 * V_41 )
{
struct V_1 * V_2 = F_62 ( V_41 , struct V_1 , V_6 ) ;
unsigned long V_30 ;
int V_13 ;
F_39 ( & V_2 -> V_7 , V_30 ) ;
V_13 = F_45 ( & V_2 -> V_6 , - 1 ) ;
if ( F_14 ( V_13 == 1 ) ) {
F_11 ( V_2 ) ;
F_72 ( & V_2 -> V_31 , 0 , 1 , V_37 ) ;
}
if ( F_14 ( F_56 ( & V_2 -> V_8 ) ) )
F_2 ( & V_2 -> V_6 , 0 ) ;
F_51 ( & V_2 -> V_7 , V_30 ) ;
return V_13 == 1 ;
}
int T_1 F_73 ( struct V_1 * V_2 )
{
int V_43 ;
V_43 = F_74 ( & V_2 -> V_6 , F_71 ) ;
if ( V_43 )
F_11 ( V_2 ) ;
return V_43 ;
}
int F_75 ( T_3 * V_46 , struct V_1 * V_2 )
{
if ( F_76 ( V_46 , - 1 , 1 ) )
return 0 ;
F_8 ( V_2 ) ;
if ( ! F_77 ( V_46 ) ) {
F_27 ( V_2 ) ;
return 0 ;
}
return 1 ;
}
