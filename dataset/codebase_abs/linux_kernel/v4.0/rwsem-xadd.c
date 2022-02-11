void F_1 ( struct V_1 * V_2 , const char * V_3 ,
struct V_4 * V_5 )
{
#ifdef F_2
F_3 ( ( void * ) V_2 , sizeof( * V_2 ) ) ;
F_4 ( & V_2 -> V_6 , V_3 , V_5 , 0 ) ;
#endif
V_2 -> V_7 = V_8 ;
F_5 ( & V_2 -> V_9 ) ;
F_6 ( & V_2 -> V_10 ) ;
#ifdef F_7
V_2 -> V_11 = NULL ;
F_8 ( & V_2 -> V_12 ) ;
#endif
}
static struct V_1 *
F_9 ( struct V_1 * V_2 , enum V_13 V_14 )
{
struct V_15 * V_16 ;
struct V_17 * V_18 ;
struct V_19 * V_20 ;
long V_21 , V_22 , V_23 , V_24 ;
V_16 = F_10 ( V_2 -> V_10 . V_20 , struct V_15 , V_25 ) ;
if ( V_16 -> type == V_26 ) {
if ( V_14 == V_27 )
F_11 ( V_16 -> V_28 ) ;
goto V_29;
}
V_24 = 0 ;
if ( V_14 != V_30 ) {
V_24 = V_31 ;
V_32:
V_21 = F_12 ( V_24 , V_2 ) - V_24 ;
if ( F_13 ( V_21 < V_33 ) ) {
if ( F_12 ( - V_24 , V_2 ) &
V_34 )
goto V_29;
goto V_32;
}
}
V_22 = 0 ;
do {
V_22 ++ ;
if ( V_16 -> V_25 . V_20 == & V_2 -> V_10 )
break;
V_16 = F_10 ( V_16 -> V_25 . V_20 ,
struct V_15 , V_25 ) ;
} while ( V_16 -> type != V_26 );
V_24 = V_22 * V_31 - V_24 ;
if ( V_16 -> type != V_26 )
V_24 -= V_33 ;
if ( V_24 )
F_14 ( V_24 , V_2 ) ;
V_20 = V_2 -> V_10 . V_20 ;
V_23 = V_22 ;
do {
V_16 = F_10 ( V_20 , struct V_15 , V_25 ) ;
V_20 = V_16 -> V_25 . V_20 ;
V_18 = V_16 -> V_28 ;
F_15 () ;
V_16 -> V_28 = NULL ;
F_11 ( V_18 ) ;
F_16 ( V_18 ) ;
} while ( -- V_23 );
V_2 -> V_10 . V_20 = V_20 ;
V_20 -> V_35 = & V_2 -> V_10 ;
V_29:
return V_2 ;
}
T_1
struct V_1 T_2 * F_17 ( struct V_1 * V_2 )
{
long V_7 , V_24 = - V_31 ;
struct V_15 V_16 ;
struct V_17 * V_18 = V_36 ;
V_16 . V_28 = V_18 ;
V_16 . type = V_37 ;
F_18 ( V_18 ) ;
F_19 ( & V_2 -> V_9 ) ;
if ( F_20 ( & V_2 -> V_10 ) )
V_24 += V_33 ;
F_21 ( & V_16 . V_25 , & V_2 -> V_10 ) ;
V_7 = F_12 ( V_24 , V_2 ) ;
if ( V_7 == V_33 ||
( V_7 > V_33 &&
V_24 != - V_31 ) )
V_2 = F_9 ( V_2 , V_27 ) ;
F_22 ( & V_2 -> V_9 ) ;
while ( true ) {
F_23 ( V_18 , V_38 ) ;
if ( ! V_16 . V_28 )
break;
F_24 () ;
}
F_25 ( V_18 , V_39 ) ;
return V_2 ;
}
static inline bool F_26 ( long V_7 , struct V_1 * V_2 )
{
if ( V_7 == V_33 &&
F_27 ( & V_2 -> V_7 , V_33 ,
V_40 ) == V_33 ) {
if ( ! F_28 ( & V_2 -> V_10 ) )
F_12 ( V_33 , V_2 ) ;
return true ;
}
return false ;
}
static inline bool F_29 ( struct V_1 * V_2 )
{
long V_41 , V_7 = F_30 ( V_2 -> V_7 ) ;
while ( true ) {
if ( ! ( V_7 == 0 || V_7 == V_33 ) )
return false ;
V_41 = F_27 ( & V_2 -> V_7 , V_7 , V_7 + V_40 ) ;
if ( V_41 == V_7 )
return true ;
V_7 = V_41 ;
}
}
static inline bool F_31 ( struct V_1 * V_2 )
{
struct V_17 * V_11 ;
bool V_42 = false ;
if ( F_32 () )
return false ;
F_33 () ;
V_11 = F_30 ( V_2 -> V_11 ) ;
if ( V_11 )
V_42 = V_11 -> V_42 ;
F_34 () ;
return V_42 ;
}
static inline bool F_35 ( struct V_1 * V_2 ,
struct V_17 * V_11 )
{
if ( V_2 -> V_11 != V_11 )
return false ;
F_36 () ;
return V_11 -> V_42 ;
}
static T_3
bool F_37 ( struct V_1 * V_2 , struct V_17 * V_11 )
{
F_33 () ;
while ( F_35 ( V_2 , V_11 ) ) {
if ( F_32 () )
break;
F_38 () ;
}
F_34 () ;
return V_2 -> V_11 == NULL ;
}
static bool F_39 ( struct V_1 * V_2 )
{
struct V_17 * V_11 ;
bool V_43 = false ;
F_40 () ;
if ( ! F_31 ( V_2 ) )
goto V_44;
if ( ! F_41 ( & V_2 -> V_12 ) )
goto V_44;
while ( true ) {
V_11 = F_30 ( V_2 -> V_11 ) ;
if ( V_11 && ! F_37 ( V_2 , V_11 ) )
break;
if ( F_29 ( V_2 ) ) {
V_43 = true ;
break;
}
if ( ! V_11 && ( F_32 () || F_42 ( V_36 ) ) )
break;
F_38 () ;
}
F_43 ( & V_2 -> V_12 ) ;
V_44:
F_44 () ;
return V_43 ;
}
static bool F_39 ( struct V_1 * V_2 )
{
return false ;
}
T_1
struct V_1 T_2 * F_45 ( struct V_1 * V_2 )
{
long V_7 ;
bool V_45 = true ;
struct V_15 V_16 ;
V_7 = F_12 ( - V_40 , V_2 ) ;
if ( F_39 ( V_2 ) )
return V_2 ;
V_16 . V_28 = V_36 ;
V_16 . type = V_26 ;
F_19 ( & V_2 -> V_9 ) ;
if ( F_20 ( & V_2 -> V_10 ) )
V_45 = false ;
F_21 ( & V_16 . V_25 , & V_2 -> V_10 ) ;
if ( V_45 ) {
V_7 = F_30 ( V_2 -> V_7 ) ;
if ( V_7 > V_33 )
V_2 = F_9 ( V_2 , V_46 ) ;
} else
V_7 = F_12 ( V_33 , V_2 ) ;
F_46 ( V_38 ) ;
while ( true ) {
if ( F_26 ( V_7 , V_2 ) )
break;
F_22 ( & V_2 -> V_9 ) ;
do {
F_24 () ;
F_46 ( V_38 ) ;
} while ( ( V_7 = V_2 -> V_7 ) & V_34 );
F_19 ( & V_2 -> V_9 ) ;
}
F_47 ( V_39 ) ;
F_48 ( & V_16 . V_25 ) ;
F_22 ( & V_2 -> V_9 ) ;
return V_2 ;
}
T_1
struct V_1 * F_49 ( struct V_1 * V_2 )
{
unsigned long V_47 ;
F_50 ( & V_2 -> V_9 , V_47 ) ;
if ( ! F_20 ( & V_2 -> V_10 ) )
V_2 = F_9 ( V_2 , V_27 ) ;
F_51 ( & V_2 -> V_9 , V_47 ) ;
return V_2 ;
}
T_1
struct V_1 * F_52 ( struct V_1 * V_2 )
{
unsigned long V_47 ;
F_50 ( & V_2 -> V_9 , V_47 ) ;
if ( ! F_20 ( & V_2 -> V_10 ) )
V_2 = F_9 ( V_2 , V_30 ) ;
F_51 ( & V_2 -> V_9 , V_47 ) ;
return V_2 ;
}
