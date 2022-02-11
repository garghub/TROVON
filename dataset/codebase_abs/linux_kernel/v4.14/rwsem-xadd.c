void F_1 ( struct V_1 * V_2 , const char * V_3 ,
struct V_4 * V_5 )
{
#ifdef F_2
F_3 ( ( void * ) V_2 , sizeof( * V_2 ) ) ;
F_4 ( & V_2 -> V_6 , V_3 , V_5 , 0 ) ;
#endif
F_5 ( & V_2 -> V_7 , V_8 ) ;
F_6 ( & V_2 -> V_9 ) ;
F_7 ( & V_2 -> V_10 ) ;
#ifdef F_8
V_2 -> V_11 = NULL ;
F_9 ( & V_2 -> V_12 ) ;
#endif
}
static void F_10 ( struct V_1 * V_2 ,
enum V_13 V_14 ,
struct V_15 * V_16 )
{
struct V_17 * V_18 , * V_19 ;
long V_20 , V_21 = 0 , V_22 = 0 ;
V_18 = F_11 ( & V_2 -> V_10 , struct V_17 , V_23 ) ;
if ( V_18 -> type == V_24 ) {
if ( V_14 == V_25 ) {
F_12 ( V_16 , V_18 -> V_26 ) ;
}
return;
}
if ( V_14 != V_27 ) {
V_22 = V_28 ;
V_29:
V_20 = F_13 ( V_22 , & V_2 -> V_7 ) ;
if ( F_14 ( V_20 < V_30 ) ) {
if ( F_15 ( - V_22 , & V_2 -> V_7 ) <
V_30 )
return;
goto V_29;
}
F_16 ( V_2 ) ;
}
F_17 (waiter, tmp, &sem->wait_list, list) {
struct V_31 * V_32 ;
if ( V_18 -> type == V_24 )
break;
V_21 ++ ;
V_32 = V_18 -> V_26 ;
F_12 ( V_16 , V_32 ) ;
F_18 ( & V_18 -> V_23 ) ;
F_19 ( & V_18 -> V_26 , NULL ) ;
}
V_22 = V_21 * V_28 - V_22 ;
if ( F_20 ( & V_2 -> V_10 ) ) {
V_22 -= V_30 ;
}
if ( V_22 )
F_21 ( V_22 , & V_2 -> V_7 ) ;
}
static inline struct V_1 T_1 *
F_22 ( struct V_1 * V_2 , int V_33 )
{
long V_7 , V_22 = - V_28 ;
struct V_17 V_18 ;
F_23 ( V_16 ) ;
V_18 . V_26 = V_34 ;
V_18 . type = V_35 ;
F_24 ( & V_2 -> V_9 ) ;
if ( F_20 ( & V_2 -> V_10 ) )
V_22 += V_30 ;
F_25 ( & V_18 . V_23 , & V_2 -> V_10 ) ;
V_7 = F_15 ( V_22 , & V_2 -> V_7 ) ;
if ( V_7 == V_30 ||
( V_7 > V_30 &&
V_22 != - V_28 ) )
F_10 ( V_2 , V_25 , & V_16 ) ;
F_26 ( & V_2 -> V_9 ) ;
F_27 ( & V_16 ) ;
while ( true ) {
F_28 ( V_33 ) ;
if ( ! V_18 . V_26 )
break;
if ( F_29 ( V_33 , V_34 ) ) {
F_24 ( & V_2 -> V_9 ) ;
if ( V_18 . V_26 )
goto V_36;
F_26 ( & V_2 -> V_9 ) ;
break;
}
F_30 () ;
}
F_31 ( V_37 ) ;
return V_2 ;
V_36:
F_18 ( & V_18 . V_23 ) ;
if ( F_20 ( & V_2 -> V_10 ) )
F_21 ( - V_30 , & V_2 -> V_7 ) ;
F_26 ( & V_2 -> V_9 ) ;
F_31 ( V_37 ) ;
return F_32 ( - V_38 ) ;
}
T_2 struct V_1 * T_1
F_33 ( struct V_1 * V_2 )
{
return F_22 ( V_2 , V_39 ) ;
}
T_2 struct V_1 * T_1
F_34 ( struct V_1 * V_2 )
{
return F_22 ( V_2 , V_40 ) ;
}
static inline bool F_35 ( long V_7 , struct V_1 * V_2 )
{
if ( V_7 != V_30 )
return false ;
V_7 = F_36 ( & V_2 -> V_10 ) ?
V_41 :
V_41 + V_30 ;
if ( F_37 ( & V_2 -> V_7 , V_30 , V_7 )
== V_30 ) {
F_38 ( V_2 ) ;
return true ;
}
return false ;
}
static inline bool F_39 ( struct V_1 * V_2 )
{
long V_42 , V_7 = F_40 ( & V_2 -> V_7 ) ;
while ( true ) {
if ( ! ( V_7 == 0 || V_7 == V_30 ) )
return false ;
V_42 = F_37 ( & V_2 -> V_7 , V_7 ,
V_7 + V_41 ) ;
if ( V_42 == V_7 ) {
F_38 ( V_2 ) ;
return true ;
}
V_7 = V_42 ;
}
}
static inline bool F_41 ( struct V_1 * V_2 )
{
struct V_31 * V_11 ;
bool V_43 = true ;
if ( F_42 () )
return false ;
F_43 () ;
V_11 = F_44 ( V_2 -> V_11 ) ;
if ( ! F_45 ( V_11 ) ) {
V_43 = ! F_46 ( V_11 ) ;
goto V_44;
}
V_43 = V_11 -> V_45 && ! F_47 ( F_48 ( V_11 ) ) ;
V_44:
F_49 () ;
return V_43 ;
}
static T_3 bool F_50 ( struct V_1 * V_2 )
{
struct V_31 * V_11 = F_44 ( V_2 -> V_11 ) ;
if ( ! F_45 ( V_11 ) )
goto V_46;
F_43 () ;
while ( V_2 -> V_11 == V_11 ) {
F_51 () ;
if ( ! V_11 -> V_45 || F_42 () ||
F_47 ( F_48 ( V_11 ) ) ) {
F_49 () ;
return false ;
}
F_52 () ;
}
F_49 () ;
V_46:
return ! F_46 ( F_44 ( V_2 -> V_11 ) ) ;
}
static bool F_53 ( struct V_1 * V_2 )
{
bool V_47 = false ;
F_54 () ;
if ( ! F_41 ( V_2 ) )
goto V_44;
if ( ! F_55 ( & V_2 -> V_12 ) )
goto V_44;
while ( F_50 ( V_2 ) ) {
if ( F_39 ( V_2 ) ) {
V_47 = true ;
break;
}
if ( ! V_2 -> V_11 && ( F_42 () || F_56 ( V_34 ) ) )
break;
F_52 () ;
}
F_57 ( & V_2 -> V_12 ) ;
V_44:
F_58 () ;
return V_47 ;
}
static inline bool F_59 ( struct V_1 * V_2 )
{
return F_60 ( & V_2 -> V_12 ) ;
}
static bool F_53 ( struct V_1 * V_2 )
{
return false ;
}
static inline bool F_59 ( struct V_1 * V_2 )
{
return false ;
}
static inline struct V_1 *
F_61 ( struct V_1 * V_2 , int V_33 )
{
long V_7 ;
bool V_48 = true ;
struct V_17 V_18 ;
struct V_1 * V_43 = V_2 ;
F_23 ( V_16 ) ;
V_7 = F_62 ( V_41 , & V_2 -> V_7 ) ;
if ( F_53 ( V_2 ) )
return V_2 ;
V_18 . V_26 = V_34 ;
V_18 . type = V_24 ;
F_24 ( & V_2 -> V_9 ) ;
if ( F_20 ( & V_2 -> V_10 ) )
V_48 = false ;
F_25 ( & V_18 . V_23 , & V_2 -> V_10 ) ;
if ( V_48 ) {
V_7 = F_40 ( & V_2 -> V_7 ) ;
if ( V_7 > V_30 ) {
F_10 ( V_2 , V_49 , & V_16 ) ;
F_27 ( & V_16 ) ;
F_63 ( & V_16 ) ;
}
} else
V_7 = F_15 ( V_30 , & V_2 -> V_7 ) ;
F_28 ( V_33 ) ;
while ( true ) {
if ( F_35 ( V_7 , V_2 ) )
break;
F_26 ( & V_2 -> V_9 ) ;
do {
if ( F_29 ( V_33 , V_34 ) )
goto V_36;
F_30 () ;
F_28 ( V_33 ) ;
} while ( ( V_7 = F_40 ( & V_2 -> V_7 ) ) & V_50 );
F_24 ( & V_2 -> V_9 ) ;
}
F_31 ( V_37 ) ;
F_18 ( & V_18 . V_23 ) ;
F_26 ( & V_2 -> V_9 ) ;
return V_43 ;
V_36:
F_31 ( V_37 ) ;
F_24 ( & V_2 -> V_9 ) ;
F_18 ( & V_18 . V_23 ) ;
if ( F_20 ( & V_2 -> V_10 ) )
F_21 ( - V_30 , & V_2 -> V_7 ) ;
else
F_10 ( V_2 , V_25 , & V_16 ) ;
F_26 ( & V_2 -> V_9 ) ;
F_27 ( & V_16 ) ;
return F_32 ( - V_38 ) ;
}
T_2 struct V_1 * T_1
F_64 ( struct V_1 * V_2 )
{
return F_61 ( V_2 , V_39 ) ;
}
T_2 struct V_1 * T_1
F_65 ( struct V_1 * V_2 )
{
return F_61 ( V_2 , V_40 ) ;
}
T_2
struct V_1 * F_66 ( struct V_1 * V_2 )
{
unsigned long V_51 ;
F_23 ( V_16 ) ;
F_67 () ;
if ( F_59 ( V_2 ) ) {
F_67 () ;
if ( ! F_68 ( & V_2 -> V_9 , V_51 ) )
return V_2 ;
goto V_52;
}
F_69 ( & V_2 -> V_9 , V_51 ) ;
V_52:
if ( ! F_20 ( & V_2 -> V_10 ) )
F_10 ( V_2 , V_25 , & V_16 ) ;
F_70 ( & V_2 -> V_9 , V_51 ) ;
F_27 ( & V_16 ) ;
return V_2 ;
}
T_2
struct V_1 * F_71 ( struct V_1 * V_2 )
{
unsigned long V_51 ;
F_23 ( V_16 ) ;
F_69 ( & V_2 -> V_9 , V_51 ) ;
if ( ! F_20 ( & V_2 -> V_10 ) )
F_10 ( V_2 , V_27 , & V_16 ) ;
F_70 ( & V_2 -> V_9 , V_51 ) ;
F_27 ( & V_16 ) ;
return V_2 ;
}
