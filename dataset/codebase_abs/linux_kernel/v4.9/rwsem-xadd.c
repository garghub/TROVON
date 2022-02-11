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
T_1
struct V_1 T_2 * F_22 ( struct V_1 * V_2 )
{
long V_7 , V_22 = - V_28 ;
struct V_17 V_18 ;
struct V_31 * V_32 = V_33 ;
F_23 ( V_16 ) ;
V_18 . V_26 = V_32 ;
V_18 . type = V_34 ;
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
F_28 ( V_32 , V_35 ) ;
if ( ! V_18 . V_26 )
break;
F_29 () ;
}
F_30 ( V_32 , V_36 ) ;
return V_2 ;
}
static inline bool F_31 ( long V_7 , struct V_1 * V_2 )
{
if ( V_7 != V_30 )
return false ;
V_7 = F_32 ( & V_2 -> V_10 ) ?
V_37 :
V_37 + V_30 ;
if ( F_33 ( & V_2 -> V_7 , V_30 , V_7 )
== V_30 ) {
F_34 ( V_2 ) ;
return true ;
}
return false ;
}
static inline bool F_35 ( struct V_1 * V_2 )
{
long V_38 , V_7 = F_36 ( & V_2 -> V_7 ) ;
while ( true ) {
if ( ! ( V_7 == 0 || V_7 == V_30 ) )
return false ;
V_38 = F_33 ( & V_2 -> V_7 , V_7 ,
V_7 + V_37 ) ;
if ( V_38 == V_7 ) {
F_34 ( V_2 ) ;
return true ;
}
V_7 = V_38 ;
}
}
static inline bool F_37 ( struct V_1 * V_2 )
{
struct V_31 * V_11 ;
bool V_39 = true ;
if ( F_38 () )
return false ;
F_39 () ;
V_11 = F_40 ( V_2 -> V_11 ) ;
if ( ! F_41 ( V_11 ) ) {
V_39 = ! F_42 ( V_11 ) ;
goto V_40;
}
V_39 = V_11 -> V_41 ;
V_40:
F_43 () ;
return V_39 ;
}
static T_3 bool F_44 ( struct V_1 * V_2 )
{
struct V_31 * V_11 = F_40 ( V_2 -> V_11 ) ;
if ( ! F_41 ( V_11 ) )
goto V_42;
F_39 () ;
while ( V_2 -> V_11 == V_11 ) {
F_45 () ;
if ( ! V_11 -> V_41 || F_38 () ) {
F_43 () ;
return false ;
}
F_46 () ;
}
F_43 () ;
V_42:
return ! F_42 ( F_40 ( V_2 -> V_11 ) ) ;
}
static bool F_47 ( struct V_1 * V_2 )
{
bool V_43 = false ;
F_48 () ;
if ( ! F_37 ( V_2 ) )
goto V_40;
if ( ! F_49 ( & V_2 -> V_12 ) )
goto V_40;
while ( F_44 ( V_2 ) ) {
if ( F_35 ( V_2 ) ) {
V_43 = true ;
break;
}
if ( ! V_2 -> V_11 && ( F_38 () || F_50 ( V_33 ) ) )
break;
F_46 () ;
}
F_51 ( & V_2 -> V_12 ) ;
V_40:
F_52 () ;
return V_43 ;
}
static inline bool F_53 ( struct V_1 * V_2 )
{
return F_54 ( & V_2 -> V_12 ) ;
}
static bool F_47 ( struct V_1 * V_2 )
{
return false ;
}
static inline bool F_53 ( struct V_1 * V_2 )
{
return false ;
}
static inline struct V_1 *
F_55 ( struct V_1 * V_2 , int V_44 )
{
long V_7 ;
bool V_45 = true ;
struct V_17 V_18 ;
struct V_1 * V_39 = V_2 ;
F_23 ( V_16 ) ;
V_7 = F_56 ( V_37 , & V_2 -> V_7 ) ;
if ( F_47 ( V_2 ) )
return V_2 ;
V_18 . V_26 = V_33 ;
V_18 . type = V_24 ;
F_24 ( & V_2 -> V_9 ) ;
if ( F_20 ( & V_2 -> V_10 ) )
V_45 = false ;
F_25 ( & V_18 . V_23 , & V_2 -> V_10 ) ;
if ( V_45 ) {
V_7 = F_36 ( & V_2 -> V_7 ) ;
if ( V_7 > V_30 ) {
F_23 ( V_16 ) ;
F_10 ( V_2 , V_46 , & V_16 ) ;
F_27 ( & V_16 ) ;
}
} else
V_7 = F_15 ( V_30 , & V_2 -> V_7 ) ;
F_57 ( V_44 ) ;
while ( true ) {
if ( F_31 ( V_7 , V_2 ) )
break;
F_26 ( & V_2 -> V_9 ) ;
do {
if ( F_58 ( V_44 , V_33 ) )
goto V_47;
F_29 () ;
F_57 ( V_44 ) ;
} while ( ( V_7 = F_36 ( & V_2 -> V_7 ) ) & V_48 );
F_24 ( & V_2 -> V_9 ) ;
}
F_59 ( V_36 ) ;
F_18 ( & V_18 . V_23 ) ;
F_26 ( & V_2 -> V_9 ) ;
return V_39 ;
V_47:
F_59 ( V_36 ) ;
F_24 ( & V_2 -> V_9 ) ;
F_18 ( & V_18 . V_23 ) ;
if ( F_20 ( & V_2 -> V_10 ) )
F_21 ( - V_30 , & V_2 -> V_7 ) ;
else
F_10 ( V_2 , V_25 , & V_16 ) ;
F_26 ( & V_2 -> V_9 ) ;
F_27 ( & V_16 ) ;
return F_60 ( - V_49 ) ;
}
T_1 struct V_1 * T_2
F_61 ( struct V_1 * V_2 )
{
return F_55 ( V_2 , V_35 ) ;
}
T_1 struct V_1 * T_2
F_62 ( struct V_1 * V_2 )
{
return F_55 ( V_2 , V_50 ) ;
}
T_1
struct V_1 * F_63 ( struct V_1 * V_2 )
{
unsigned long V_51 ;
F_23 ( V_16 ) ;
if ( F_53 ( V_2 ) ) {
F_64 () ;
if ( ! F_65 ( & V_2 -> V_9 , V_51 ) )
return V_2 ;
goto V_52;
}
F_66 ( & V_2 -> V_9 , V_51 ) ;
V_52:
if ( ! F_20 ( & V_2 -> V_10 ) )
F_10 ( V_2 , V_25 , & V_16 ) ;
F_67 ( & V_2 -> V_9 , V_51 ) ;
F_27 ( & V_16 ) ;
return V_2 ;
}
T_1
struct V_1 * F_68 ( struct V_1 * V_2 )
{
unsigned long V_51 ;
F_23 ( V_16 ) ;
F_66 ( & V_2 -> V_9 , V_51 ) ;
if ( ! F_20 ( & V_2 -> V_10 ) )
F_10 ( V_2 , V_27 , & V_16 ) ;
F_67 ( & V_2 -> V_9 , V_51 ) ;
F_27 ( & V_16 ) ;
return V_2 ;
}
