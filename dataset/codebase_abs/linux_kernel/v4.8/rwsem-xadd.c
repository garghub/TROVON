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
static struct V_1 *
F_10 ( struct V_1 * V_2 ,
enum V_13 V_14 , struct V_15 * V_16 )
{
struct V_17 * V_18 ;
struct V_19 * V_20 ;
struct V_21 * V_22 ;
long V_23 , V_24 , V_25 , V_26 ;
V_18 = F_11 ( V_2 -> V_10 . V_22 , struct V_17 , V_27 ) ;
if ( V_18 -> type == V_28 ) {
if ( V_14 == V_29 ) {
F_12 ( V_16 , V_18 -> V_30 ) ;
}
goto V_31;
}
V_26 = 0 ;
if ( V_14 != V_32 ) {
V_26 = V_33 ;
V_34:
V_23 = F_13 ( V_26 , & V_2 -> V_7 ) ;
if ( F_14 ( V_23 < V_35 ) ) {
if ( F_15 ( - V_26 , & V_2 -> V_7 ) <
V_35 )
goto V_31;
goto V_34;
}
F_16 ( V_2 ) ;
}
V_24 = 0 ;
do {
V_24 ++ ;
if ( V_18 -> V_27 . V_22 == & V_2 -> V_10 )
break;
V_18 = F_11 ( V_18 -> V_27 . V_22 ,
struct V_17 , V_27 ) ;
} while ( V_18 -> type != V_28 );
V_26 = V_24 * V_33 - V_26 ;
if ( V_18 -> type != V_28 )
V_26 -= V_35 ;
if ( V_26 )
F_17 ( V_26 , & V_2 -> V_7 ) ;
V_22 = V_2 -> V_10 . V_22 ;
V_25 = V_24 ;
do {
V_18 = F_11 ( V_22 , struct V_17 , V_27 ) ;
V_22 = V_18 -> V_27 . V_22 ;
V_20 = V_18 -> V_30 ;
F_12 ( V_16 , V_20 ) ;
F_18 ( & V_18 -> V_30 , NULL ) ;
} while ( -- V_25 );
V_2 -> V_10 . V_22 = V_22 ;
V_22 -> V_36 = & V_2 -> V_10 ;
V_31:
return V_2 ;
}
T_1
struct V_1 T_2 * F_19 ( struct V_1 * V_2 )
{
long V_7 , V_26 = - V_33 ;
struct V_17 V_18 ;
struct V_19 * V_20 = V_37 ;
F_20 ( V_16 ) ;
V_18 . V_30 = V_20 ;
V_18 . type = V_38 ;
F_21 ( & V_2 -> V_9 ) ;
if ( F_22 ( & V_2 -> V_10 ) )
V_26 += V_35 ;
F_23 ( & V_18 . V_27 , & V_2 -> V_10 ) ;
V_7 = F_15 ( V_26 , & V_2 -> V_7 ) ;
if ( V_7 == V_35 ||
( V_7 > V_35 &&
V_26 != - V_33 ) )
V_2 = F_10 ( V_2 , V_29 , & V_16 ) ;
F_24 ( & V_2 -> V_9 ) ;
F_25 ( & V_16 ) ;
while ( true ) {
F_26 ( V_20 , V_39 ) ;
if ( ! V_18 . V_30 )
break;
F_27 () ;
}
F_28 ( V_20 , V_40 ) ;
return V_2 ;
}
static inline bool F_29 ( long V_7 , struct V_1 * V_2 )
{
if ( V_7 != V_35 )
return false ;
V_7 = F_30 ( & V_2 -> V_10 ) ?
V_41 :
V_41 + V_35 ;
if ( F_31 ( & V_2 -> V_7 , V_35 , V_7 )
== V_35 ) {
F_32 ( V_2 ) ;
return true ;
}
return false ;
}
static inline bool F_33 ( struct V_1 * V_2 )
{
long V_42 , V_7 = F_34 ( & V_2 -> V_7 ) ;
while ( true ) {
if ( ! ( V_7 == 0 || V_7 == V_35 ) )
return false ;
V_42 = F_31 ( & V_2 -> V_7 , V_7 ,
V_7 + V_41 ) ;
if ( V_42 == V_7 ) {
F_32 ( V_2 ) ;
return true ;
}
V_7 = V_42 ;
}
}
static inline bool F_35 ( struct V_1 * V_2 )
{
struct V_19 * V_11 ;
bool V_43 = true ;
if ( F_36 () )
return false ;
F_37 () ;
V_11 = F_38 ( V_2 -> V_11 ) ;
if ( ! F_39 ( V_11 ) ) {
V_43 = ! F_40 ( V_11 ) ;
goto V_44;
}
V_43 = V_11 -> V_45 ;
V_44:
F_41 () ;
return V_43 ;
}
static T_3 bool F_42 ( struct V_1 * V_2 )
{
struct V_19 * V_11 = F_38 ( V_2 -> V_11 ) ;
if ( ! F_39 ( V_11 ) )
goto V_31;
F_37 () ;
while ( V_2 -> V_11 == V_11 ) {
F_43 () ;
if ( ! V_11 -> V_45 || F_36 () ) {
F_41 () ;
return false ;
}
F_44 () ;
}
F_41 () ;
V_31:
return ! F_40 ( F_38 ( V_2 -> V_11 ) ) ;
}
static bool F_45 ( struct V_1 * V_2 )
{
bool V_46 = false ;
F_46 () ;
if ( ! F_35 ( V_2 ) )
goto V_44;
if ( ! F_47 ( & V_2 -> V_12 ) )
goto V_44;
while ( F_42 ( V_2 ) ) {
if ( F_33 ( V_2 ) ) {
V_46 = true ;
break;
}
if ( ! V_2 -> V_11 && ( F_36 () || F_48 ( V_37 ) ) )
break;
F_44 () ;
}
F_49 ( & V_2 -> V_12 ) ;
V_44:
F_50 () ;
return V_46 ;
}
static inline bool F_51 ( struct V_1 * V_2 )
{
return F_52 ( & V_2 -> V_12 ) ;
}
static bool F_45 ( struct V_1 * V_2 )
{
return false ;
}
static inline bool F_51 ( struct V_1 * V_2 )
{
return false ;
}
static inline struct V_1 *
F_53 ( struct V_1 * V_2 , int V_47 )
{
long V_7 ;
bool V_48 = true ;
struct V_17 V_18 ;
struct V_1 * V_43 = V_2 ;
F_20 ( V_16 ) ;
V_7 = F_54 ( V_41 , & V_2 -> V_7 ) ;
if ( F_45 ( V_2 ) )
return V_2 ;
V_18 . V_30 = V_37 ;
V_18 . type = V_28 ;
F_21 ( & V_2 -> V_9 ) ;
if ( F_22 ( & V_2 -> V_10 ) )
V_48 = false ;
F_23 ( & V_18 . V_27 , & V_2 -> V_10 ) ;
if ( V_48 ) {
V_7 = F_34 ( & V_2 -> V_7 ) ;
if ( V_7 > V_35 ) {
F_20 ( V_16 ) ;
V_2 = F_10 ( V_2 , V_49 , & V_16 ) ;
F_25 ( & V_16 ) ;
}
} else
V_7 = F_15 ( V_35 , & V_2 -> V_7 ) ;
F_55 ( V_47 ) ;
while ( true ) {
if ( F_29 ( V_7 , V_2 ) )
break;
F_24 ( & V_2 -> V_9 ) ;
do {
if ( F_56 ( V_47 , V_37 ) )
goto V_50;
F_27 () ;
F_55 ( V_47 ) ;
} while ( ( V_7 = F_34 ( & V_2 -> V_7 ) ) & V_51 );
F_21 ( & V_2 -> V_9 ) ;
}
F_57 ( V_40 ) ;
F_58 ( & V_18 . V_27 ) ;
F_24 ( & V_2 -> V_9 ) ;
return V_43 ;
V_50:
F_57 ( V_40 ) ;
F_21 ( & V_2 -> V_9 ) ;
F_58 ( & V_18 . V_27 ) ;
if ( F_22 ( & V_2 -> V_10 ) )
F_17 ( - V_35 , & V_2 -> V_7 ) ;
else
F_10 ( V_2 , V_29 , & V_16 ) ;
F_24 ( & V_2 -> V_9 ) ;
F_25 ( & V_16 ) ;
return F_59 ( - V_52 ) ;
}
T_1 struct V_1 * T_2
F_60 ( struct V_1 * V_2 )
{
return F_53 ( V_2 , V_39 ) ;
}
T_1 struct V_1 * T_2
F_61 ( struct V_1 * V_2 )
{
return F_53 ( V_2 , V_53 ) ;
}
T_1
struct V_1 * F_62 ( struct V_1 * V_2 )
{
unsigned long V_54 ;
F_20 ( V_16 ) ;
if ( F_51 ( V_2 ) ) {
F_63 () ;
if ( ! F_64 ( & V_2 -> V_9 , V_54 ) )
return V_2 ;
goto V_55;
}
F_65 ( & V_2 -> V_9 , V_54 ) ;
V_55:
if ( ! F_22 ( & V_2 -> V_10 ) )
V_2 = F_10 ( V_2 , V_29 , & V_16 ) ;
F_66 ( & V_2 -> V_9 , V_54 ) ;
F_25 ( & V_16 ) ;
return V_2 ;
}
T_1
struct V_1 * F_67 ( struct V_1 * V_2 )
{
unsigned long V_54 ;
F_20 ( V_16 ) ;
F_65 ( & V_2 -> V_9 , V_54 ) ;
if ( ! F_22 ( & V_2 -> V_10 ) )
V_2 = F_10 ( V_2 , V_32 , & V_16 ) ;
F_66 ( & V_2 -> V_9 , V_54 ) ;
F_25 ( & V_16 ) ;
return V_2 ;
}
