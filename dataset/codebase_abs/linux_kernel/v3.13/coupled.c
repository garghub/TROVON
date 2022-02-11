void F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
int V_4 = V_2 -> V_5 -> V_6 ;
F_2 () ;
F_3 ( V_3 ) ;
while ( F_4 ( V_3 ) < V_4 )
F_5 () ;
if ( F_6 ( V_3 ) == V_4 * 2 ) {
F_7 ( V_3 , 0 ) ;
return;
}
while ( F_4 ( V_3 ) > V_4 )
F_5 () ;
}
bool F_8 ( struct V_1 * V_2 ,
struct V_7 * V_8 , int V_9 )
{
return V_8 -> V_10 [ V_9 ] . V_11 & V_12 ;
}
static inline void F_9 ( struct V_13 * V_5 )
{
F_10 ( V_14 , & V_5 -> V_15 ) ;
}
static
inline int F_11 ( struct V_13 * V_5 )
{
int V_16 ;
int V_17 ;
V_16 = V_5 -> V_6 | ( V_5 -> V_6 << V_18 ) ;
V_17 = F_12 ( & V_5 -> V_15 ,
- V_14 , V_16 ) ;
return V_17 ? 0 : - V_19 ;
}
static inline int F_13 ( struct V_13 * V_5 )
{
int V_20 = F_4 ( & V_5 -> V_15 ) >> V_18 ;
return V_20 == 0 ;
}
static inline bool F_14 ( struct V_13 * V_5 )
{
int V_20 = F_4 ( & V_5 -> V_15 ) >> V_18 ;
return V_20 == V_5 -> V_6 ;
}
static inline bool F_15 ( struct V_13 * V_5 )
{
int V_21 = F_4 ( & V_5 -> V_15 ) & V_22 ;
return V_21 == V_5 -> V_6 ;
}
static inline int F_16 ( struct V_13 * V_5 )
{
int V_21 = F_4 ( & V_5 -> V_15 ) & V_22 ;
return V_21 == 0 ;
}
static inline int F_17 ( struct V_1 * V_2 ,
struct V_13 * V_5 )
{
int V_23 ;
int V_9 = V_24 ;
F_18 () ;
F_19 (i, coupled->coupled_cpus)
if ( F_20 ( V_23 ) && V_5 -> V_25 [ V_23 ] < V_9 )
V_9 = V_5 -> V_25 [ V_23 ] ;
return V_9 ;
}
static void F_21 ( void * V_26 )
{
int V_27 = ( unsigned long ) V_26 ;
F_22 ( V_27 , & V_28 ) ;
F_23 ( V_27 , & V_29 ) ;
}
static void F_24 ( int V_27 )
{
struct V_30 * V_31 = & F_25 ( V_32 , V_27 ) ;
if ( ! F_26 ( V_27 , & V_29 ) )
F_27 ( V_27 , V_31 , 0 ) ;
}
static void F_28 ( int V_33 ,
struct V_13 * V_5 )
{
int V_27 ;
F_19 (cpu, coupled->coupled_cpus)
if ( V_27 != V_33 && F_20 ( V_27 ) )
F_24 ( V_27 ) ;
}
static int F_29 ( int V_27 ,
struct V_13 * V_5 , int V_34 )
{
V_5 -> V_25 [ V_27 ] = V_34 ;
return F_6 ( & V_5 -> V_15 ) & V_22 ;
}
static void F_30 ( int V_27 ,
struct V_13 * V_5 )
{
F_31 ( & V_5 -> V_15 ) ;
V_5 -> V_25 [ V_27 ] = V_35 ;
}
static void F_32 ( int V_27 , struct V_13 * V_5 )
{
F_30 ( V_27 , V_5 ) ;
F_33 ( V_14 , & V_5 -> V_15 ) ;
}
static int F_34 ( int V_27 )
{
if ( ! F_35 ( V_27 , & V_29 ) )
return 0 ;
F_36 () ;
while ( F_35 ( V_27 , & V_29 ) )
F_5 () ;
F_37 () ;
return 1 ;
}
static bool F_38 ( struct V_13 * V_5 )
{
T_2 V_36 ;
int V_17 ;
F_39 ( & V_36 , V_37 , & V_5 -> V_38 ) ;
V_17 = F_39 ( & V_36 , & V_29 , & V_36 ) ;
return V_17 ;
}
int F_40 ( struct V_1 * V_2 ,
struct V_7 * V_8 , int V_34 )
{
int V_39 = - 1 ;
struct V_13 * V_5 = V_2 -> V_5 ;
int V_21 ;
if ( ! V_5 )
return - V_19 ;
while ( V_5 -> V_40 ) {
F_34 ( V_2 -> V_27 ) ;
if ( F_41 () ) {
F_36 () ;
return V_39 ;
}
V_39 = F_42 ( V_2 , V_8 ,
V_2 -> V_41 ) ;
F_37 () ;
}
F_18 () ;
V_42:
F_23 ( V_2 -> V_27 , & V_28 ) ;
V_21 = F_29 ( V_2 -> V_27 , V_5 , V_34 ) ;
if ( V_21 == V_5 -> V_6 ) {
F_22 ( V_2 -> V_27 , & V_28 ) ;
F_28 ( V_2 -> V_27 , V_5 ) ;
}
V_43:
while ( ! F_15 ( V_5 ) ||
! F_35 ( V_2 -> V_27 , & V_28 ) ) {
if ( F_34 ( V_2 -> V_27 ) )
continue;
if ( F_41 () ) {
F_30 ( V_2 -> V_27 , V_5 ) ;
goto V_44;
}
if ( V_5 -> V_40 ) {
F_30 ( V_2 -> V_27 , V_5 ) ;
goto V_44;
}
V_39 = F_42 ( V_2 , V_8 ,
V_2 -> V_41 ) ;
F_37 () ;
}
F_34 ( V_2 -> V_27 ) ;
if ( F_41 () ) {
F_30 ( V_2 -> V_27 , V_5 ) ;
goto V_44;
}
F_43 () ;
F_9 ( V_5 ) ;
while ( ! F_14 ( V_5 ) ) {
if ( ! F_15 ( V_5 ) )
if ( ! F_11 ( V_5 ) )
goto V_43;
F_5 () ;
}
F_18 () ;
if ( F_38 ( V_5 ) ) {
F_32 ( V_2 -> V_27 , V_5 ) ;
F_1 ( V_2 , & V_5 -> V_45 ) ;
goto V_42;
}
V_34 = F_17 ( V_2 , V_5 ) ;
V_39 = F_42 ( V_2 , V_8 , V_34 ) ;
F_32 ( V_2 -> V_27 , V_5 ) ;
V_44:
F_36 () ;
while ( ! F_13 ( V_5 ) )
F_5 () ;
return V_39 ;
}
static void F_44 ( struct V_13 * V_5 )
{
T_2 V_36 ;
F_39 ( & V_36 , V_37 , & V_5 -> V_38 ) ;
V_5 -> V_6 = F_45 ( & V_36 ) ;
}
int F_46 ( struct V_1 * V_2 )
{
int V_27 ;
struct V_1 * V_46 ;
struct V_30 * V_31 ;
struct V_13 * V_5 ;
if ( F_47 ( & V_2 -> V_38 ) )
return 0 ;
F_19 (cpu, dev->coupled_cpus) {
V_46 = F_25 ( V_47 , V_27 ) ;
if ( V_46 && V_46 -> V_5 ) {
V_5 = V_46 -> V_5 ;
goto V_48;
}
}
V_5 = F_48 ( sizeof( struct V_13 ) , V_49 ) ;
if ( ! V_5 )
return - V_50 ;
V_5 -> V_38 = V_2 -> V_38 ;
V_48:
V_2 -> V_5 = V_5 ;
if ( F_49 ( ! F_50 ( & V_2 -> V_38 , & V_5 -> V_38 ) ) )
V_5 -> V_40 ++ ;
F_44 ( V_5 ) ;
V_5 -> V_51 ++ ;
V_31 = & F_25 ( V_32 , V_2 -> V_27 ) ;
V_31 -> V_52 = F_21 ;
V_31 -> V_26 = ( void * ) ( unsigned long ) V_2 -> V_27 ;
return 0 ;
}
void F_51 ( struct V_1 * V_2 )
{
struct V_13 * V_5 = V_2 -> V_5 ;
if ( F_47 ( & V_2 -> V_38 ) )
return;
if ( -- V_5 -> V_51 )
F_52 ( V_5 ) ;
V_2 -> V_5 = NULL ;
}
static void F_53 ( struct V_13 * V_5 )
{
int V_27 = F_54 () ;
V_5 -> V_40 ++ ;
F_28 ( V_27 , V_5 ) ;
F_55 () ;
while ( ! F_16 ( V_5 ) )
F_5 () ;
}
static void F_56 ( struct V_13 * V_5 )
{
int V_27 = F_54 () ;
F_43 () ;
V_5 -> V_40 -- ;
F_28 ( V_27 , V_5 ) ;
F_55 () ;
}
static int F_57 ( struct V_53 * V_54 ,
unsigned long V_55 , void * V_56 )
{
int V_27 = ( unsigned long ) V_56 ;
struct V_1 * V_2 ;
switch ( V_55 & ~ V_57 ) {
case V_58 :
case V_59 :
case V_60 :
case V_61 :
case V_62 :
case V_63 :
break;
default:
return V_64 ;
}
F_58 ( & V_65 ) ;
V_2 = F_25 ( V_47 , V_27 ) ;
if ( ! V_2 || ! V_2 -> V_5 )
goto V_44;
switch ( V_55 & ~ V_57 ) {
case V_58 :
case V_59 :
F_53 ( V_2 -> V_5 ) ;
break;
case V_60 :
case V_61 :
F_44 ( V_2 -> V_5 ) ;
case V_62 :
case V_63 :
F_56 ( V_2 -> V_5 ) ;
break;
}
V_44:
F_59 ( & V_65 ) ;
return V_64 ;
}
static int T_3 F_60 ( void )
{
return F_61 ( & V_66 ) ;
}
