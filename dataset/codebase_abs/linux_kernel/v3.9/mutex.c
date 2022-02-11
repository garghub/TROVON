void
F_1 ( struct V_1 * V_2 , const char * V_3 , struct V_4 * V_5 )
{
F_2 ( & V_2 -> V_6 , 1 ) ;
F_3 ( & V_2 -> V_7 ) ;
F_4 ( & V_2 -> V_8 ) ;
F_5 ( V_2 ) ;
F_6 ( V_2 , V_3 , V_5 ) ;
}
void T_1 F_7 ( struct V_1 * V_2 )
{
F_8 () ;
F_9 ( & V_2 -> V_6 , V_9 ) ;
F_10 ( V_2 ) ;
}
void T_1 F_11 ( struct V_1 * V_2 )
{
#ifndef F_12
F_5 ( V_2 ) ;
#endif
F_13 ( & V_2 -> V_6 , V_10 ) ;
}
static inline int T_1
F_14 ( struct V_1 * V_2 , long V_11 , unsigned int V_12 ,
struct V_13 * V_14 , unsigned long V_15 )
{
struct V_16 * V_17 = V_18 ;
struct V_19 V_20 ;
unsigned long V_21 ;
F_15 () ;
F_16 ( & V_2 -> V_22 , V_12 , 0 , V_14 , V_15 ) ;
#ifdef F_17
for (; ; ) {
struct V_16 * V_23 ;
V_23 = F_18 ( V_2 -> V_23 ) ;
if ( V_23 && ! F_19 ( V_2 , V_23 ) )
break;
if ( F_20 ( & V_2 -> V_6 , 1 , 0 ) == 1 ) {
F_21 ( & V_2 -> V_22 , V_15 ) ;
F_10 ( V_2 ) ;
F_22 () ;
return 0 ;
}
if ( ! V_23 && ( F_23 () || F_24 ( V_17 ) ) )
break;
F_25 () ;
}
#endif
F_26 ( & V_2 -> V_7 , V_21 ) ;
F_27 ( V_2 , & V_20 ) ;
F_28 ( V_2 , & V_20 , F_29 ( V_17 ) ) ;
F_30 ( & V_20 . V_24 , & V_2 -> V_8 ) ;
V_20 . V_17 = V_17 ;
if ( F_31 ( & V_2 -> V_6 , - 1 ) == 1 )
goto V_25;
F_32 ( & V_2 -> V_22 , V_15 ) ;
for (; ; ) {
if ( F_31 ( & V_2 -> V_6 , - 1 ) == 1 )
break;
if ( F_33 ( F_34 ( V_11 , V_17 ) ) ) {
F_35 ( V_2 , & V_20 ,
F_29 ( V_17 ) ) ;
F_36 ( & V_2 -> V_22 , 1 , V_15 ) ;
F_37 ( & V_2 -> V_7 , V_21 ) ;
F_38 ( & V_20 ) ;
F_22 () ;
return - V_26 ;
}
F_39 ( V_17 , V_11 ) ;
F_37 ( & V_2 -> V_7 , V_21 ) ;
F_40 () ;
F_26 ( & V_2 -> V_7 , V_21 ) ;
}
V_25:
F_21 ( & V_2 -> V_22 , V_15 ) ;
F_35 ( V_2 , & V_20 , F_41 () ) ;
F_10 ( V_2 ) ;
if ( F_42 ( F_43 ( & V_2 -> V_8 ) ) )
F_2 ( & V_2 -> V_6 , 0 ) ;
F_37 ( & V_2 -> V_7 , V_21 ) ;
F_38 ( & V_20 ) ;
F_22 () ;
return 0 ;
}
void T_1
F_44 ( struct V_1 * V_2 , unsigned int V_12 )
{
F_8 () ;
F_14 ( V_2 , V_27 , V_12 , NULL , V_28 ) ;
}
void T_1
F_45 ( struct V_1 * V_2 , struct V_13 * V_29 )
{
F_8 () ;
F_14 ( V_2 , V_27 , 0 , V_29 , V_28 ) ;
}
int T_1
F_46 ( struct V_1 * V_2 , unsigned int V_12 )
{
F_8 () ;
return F_14 ( V_2 , V_30 , V_12 , NULL , V_28 ) ;
}
int T_1
F_47 ( struct V_1 * V_2 , unsigned int V_12 )
{
F_8 () ;
return F_14 ( V_2 , V_31 ,
V_12 , NULL , V_28 ) ;
}
static inline void
F_48 ( T_2 * V_32 , int V_33 )
{
struct V_1 * V_2 = F_49 ( V_32 , struct V_1 , V_6 ) ;
unsigned long V_21 ;
F_26 ( & V_2 -> V_7 , V_21 ) ;
F_36 ( & V_2 -> V_22 , V_33 , V_28 ) ;
F_50 ( V_2 ) ;
if ( F_51 () )
F_2 ( & V_2 -> V_6 , 1 ) ;
if ( ! F_43 ( & V_2 -> V_8 ) ) {
struct V_19 * V_20 =
F_52 ( V_2 -> V_8 . V_34 ,
struct V_19 , V_24 ) ;
F_53 ( V_2 , V_20 ) ;
F_54 ( V_20 -> V_17 ) ;
}
F_37 ( & V_2 -> V_7 , V_21 ) ;
}
static T_3 T_4 void
V_10 ( T_2 * V_32 )
{
F_48 ( V_32 , 1 ) ;
}
int T_1 F_55 ( struct V_1 * V_2 )
{
int V_35 ;
F_8 () ;
V_35 = F_56
( & V_2 -> V_6 , V_36 ) ;
if ( ! V_35 )
F_10 ( V_2 ) ;
return V_35 ;
}
int T_1 F_57 ( struct V_1 * V_2 )
{
int V_35 ;
F_8 () ;
V_35 = F_56
( & V_2 -> V_6 , V_37 ) ;
if ( ! V_35 )
F_10 ( V_2 ) ;
return V_35 ;
}
static T_3 T_4 void T_1
V_9 ( T_2 * V_32 )
{
struct V_1 * V_2 = F_49 ( V_32 , struct V_1 , V_6 ) ;
F_14 ( V_2 , V_27 , 0 , NULL , V_28 ) ;
}
static T_4 int T_1
V_37 ( T_2 * V_32 )
{
struct V_1 * V_2 = F_49 ( V_32 , struct V_1 , V_6 ) ;
return F_14 ( V_2 , V_30 , 0 , NULL , V_28 ) ;
}
static T_4 int T_1
V_36 ( T_2 * V_32 )
{
struct V_1 * V_2 = F_49 ( V_32 , struct V_1 , V_6 ) ;
return F_14 ( V_2 , V_31 , 0 , NULL , V_28 ) ;
}
static inline int F_58 ( T_2 * V_32 )
{
struct V_1 * V_2 = F_49 ( V_32 , struct V_1 , V_6 ) ;
unsigned long V_21 ;
int V_38 ;
F_26 ( & V_2 -> V_7 , V_21 ) ;
V_38 = F_31 ( & V_2 -> V_6 , - 1 ) ;
if ( F_42 ( V_38 == 1 ) ) {
F_10 ( V_2 ) ;
F_59 ( & V_2 -> V_22 , 0 , 1 , V_28 ) ;
}
if ( F_42 ( F_43 ( & V_2 -> V_8 ) ) )
F_2 ( & V_2 -> V_6 , 0 ) ;
F_37 ( & V_2 -> V_7 , V_21 ) ;
return V_38 == 1 ;
}
int T_1 F_60 ( struct V_1 * V_2 )
{
int V_35 ;
V_35 = F_61 ( & V_2 -> V_6 , F_58 ) ;
if ( V_35 )
F_10 ( V_2 ) ;
return V_35 ;
}
int F_62 ( T_2 * V_39 , struct V_1 * V_2 )
{
if ( F_63 ( V_39 , - 1 , 1 ) )
return 0 ;
F_7 ( V_2 ) ;
if ( ! F_64 ( V_39 ) ) {
F_11 ( V_2 ) ;
return 0 ;
}
return 1 ;
}
