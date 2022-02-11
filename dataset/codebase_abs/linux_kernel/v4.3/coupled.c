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
bool F_8 ( struct V_7 * V_8 , int V_9 )
{
return V_8 -> V_10 [ V_9 ] . V_11 & V_12 ;
}
int F_9 ( struct V_7 * V_8 )
{
int V_13 ;
for ( V_13 = V_8 -> V_14 - 1 ; V_13 >= 0 ; V_13 -- ) {
if ( F_8 ( V_8 , V_13 ) &&
( V_8 -> V_15 == V_13 ||
V_8 -> V_15 < 0 ||
V_8 -> V_15 >= V_8 -> V_14 ) )
return - V_16 ;
}
return 0 ;
}
static inline void F_10 ( struct V_17 * V_5 )
{
F_11 ( V_18 , & V_5 -> V_19 ) ;
}
static
inline int F_12 ( struct V_17 * V_5 )
{
int V_20 ;
int V_21 ;
V_20 = V_5 -> V_6 | ( V_5 -> V_6 << V_22 ) ;
V_21 = F_13 ( & V_5 -> V_19 ,
- V_18 , V_20 ) ;
return V_21 ? 0 : - V_16 ;
}
static inline int F_14 ( struct V_17 * V_5 )
{
int V_23 = F_4 ( & V_5 -> V_19 ) >> V_22 ;
return V_23 == 0 ;
}
static inline bool F_15 ( struct V_17 * V_5 )
{
int V_23 = F_4 ( & V_5 -> V_19 ) >> V_22 ;
return V_23 == V_5 -> V_6 ;
}
static inline bool F_16 ( struct V_17 * V_5 )
{
int V_24 = F_4 ( & V_5 -> V_19 ) & V_25 ;
return V_24 == V_5 -> V_6 ;
}
static inline int F_17 ( struct V_17 * V_5 )
{
int V_24 = F_4 ( & V_5 -> V_19 ) & V_25 ;
return V_24 == 0 ;
}
static inline int F_18 ( struct V_1 * V_2 ,
struct V_17 * V_5 )
{
int V_13 ;
int V_9 = V_26 ;
F_19 () ;
F_20 (i, &coupled->coupled_cpus)
if ( F_21 ( V_13 ) && V_5 -> V_27 [ V_13 ] < V_9 )
V_9 = V_5 -> V_27 [ V_13 ] ;
return V_9 ;
}
static void F_22 ( void * V_28 )
{
int V_29 = ( unsigned long ) V_28 ;
F_23 ( V_29 , & V_30 ) ;
F_24 ( V_29 , & V_31 ) ;
}
static void F_25 ( int V_29 )
{
struct V_32 * V_33 = & F_26 ( V_34 , V_29 ) ;
if ( ! F_27 ( V_29 , & V_31 ) )
F_28 ( V_29 , V_33 ) ;
}
static void F_29 ( int V_35 ,
struct V_17 * V_5 )
{
int V_29 ;
F_20 (cpu, &coupled->coupled_cpus)
if ( V_29 != V_35 && F_21 ( V_29 ) )
F_25 ( V_29 ) ;
}
static int F_30 ( int V_29 ,
struct V_17 * V_5 , int V_36 )
{
V_5 -> V_27 [ V_29 ] = V_36 ;
return F_6 ( & V_5 -> V_19 ) & V_25 ;
}
static void F_31 ( int V_29 ,
struct V_17 * V_5 )
{
F_32 ( & V_5 -> V_19 ) ;
V_5 -> V_27 [ V_29 ] = V_37 ;
}
static void F_33 ( int V_29 , struct V_17 * V_5 )
{
F_31 ( V_29 , V_5 ) ;
F_34 ( V_18 , & V_5 -> V_19 ) ;
}
static int F_35 ( int V_29 )
{
if ( ! F_36 ( V_29 , & V_31 ) )
return 0 ;
F_37 () ;
while ( F_36 ( V_29 , & V_31 ) )
F_5 () ;
F_38 () ;
return 1 ;
}
static bool F_39 ( struct V_17 * V_5 )
{
T_2 V_38 ;
int V_21 ;
F_40 ( & V_38 , V_39 , & V_5 -> V_40 ) ;
V_21 = F_40 ( & V_38 , & V_31 , & V_38 ) ;
return V_21 ;
}
int F_41 ( struct V_1 * V_2 ,
struct V_7 * V_8 , int V_36 )
{
int V_41 = - 1 ;
struct V_17 * V_5 = V_2 -> V_5 ;
int V_24 ;
if ( ! V_5 )
return - V_16 ;
while ( V_5 -> V_42 ) {
F_35 ( V_2 -> V_29 ) ;
if ( F_42 () ) {
F_37 () ;
return V_41 ;
}
V_41 = F_43 ( V_2 , V_8 ,
V_8 -> V_15 ) ;
F_38 () ;
}
F_19 () ;
V_43:
F_24 ( V_2 -> V_29 , & V_30 ) ;
V_24 = F_30 ( V_2 -> V_29 , V_5 , V_36 ) ;
if ( V_24 == V_5 -> V_6 ) {
F_23 ( V_2 -> V_29 , & V_30 ) ;
F_29 ( V_2 -> V_29 , V_5 ) ;
}
V_44:
while ( ! F_16 ( V_5 ) ||
! F_36 ( V_2 -> V_29 , & V_30 ) ) {
if ( F_35 ( V_2 -> V_29 ) )
continue;
if ( F_42 () ) {
F_31 ( V_2 -> V_29 , V_5 ) ;
goto V_45;
}
if ( V_5 -> V_42 ) {
F_31 ( V_2 -> V_29 , V_5 ) ;
goto V_45;
}
V_41 = F_43 ( V_2 , V_8 ,
V_8 -> V_15 ) ;
F_38 () ;
}
F_35 ( V_2 -> V_29 ) ;
if ( F_42 () ) {
F_31 ( V_2 -> V_29 , V_5 ) ;
goto V_45;
}
F_44 () ;
F_10 ( V_5 ) ;
while ( ! F_15 ( V_5 ) ) {
if ( ! F_16 ( V_5 ) )
if ( ! F_12 ( V_5 ) )
goto V_44;
F_5 () ;
}
F_19 () ;
if ( F_39 ( V_5 ) ) {
F_33 ( V_2 -> V_29 , V_5 ) ;
F_1 ( V_2 , & V_5 -> V_46 ) ;
goto V_43;
}
V_36 = F_18 ( V_2 , V_5 ) ;
V_41 = F_43 ( V_2 , V_8 , V_36 ) ;
F_33 ( V_2 -> V_29 , V_5 ) ;
V_45:
F_37 () ;
while ( ! F_14 ( V_5 ) )
F_5 () ;
return V_41 ;
}
static void F_45 ( struct V_17 * V_5 )
{
T_2 V_38 ;
F_40 ( & V_38 , V_39 , & V_5 -> V_40 ) ;
V_5 -> V_6 = F_46 ( & V_38 ) ;
}
int F_47 ( struct V_1 * V_2 )
{
int V_29 ;
struct V_1 * V_47 ;
struct V_32 * V_33 ;
struct V_17 * V_5 ;
if ( F_48 ( & V_2 -> V_40 ) )
return 0 ;
F_20 (cpu, &dev->coupled_cpus) {
V_47 = F_26 ( V_48 , V_29 ) ;
if ( V_47 && V_47 -> V_5 ) {
V_5 = V_47 -> V_5 ;
goto V_49;
}
}
V_5 = F_49 ( sizeof( struct V_17 ) , V_50 ) ;
if ( ! V_5 )
return - V_51 ;
V_5 -> V_40 = V_2 -> V_40 ;
V_49:
V_2 -> V_5 = V_5 ;
if ( F_50 ( ! F_51 ( & V_2 -> V_40 , & V_5 -> V_40 ) ) )
V_5 -> V_42 ++ ;
F_45 ( V_5 ) ;
V_5 -> V_52 ++ ;
V_33 = & F_26 ( V_34 , V_2 -> V_29 ) ;
V_33 -> V_53 = F_22 ;
V_33 -> V_28 = ( void * ) ( unsigned long ) V_2 -> V_29 ;
return 0 ;
}
void F_52 ( struct V_1 * V_2 )
{
struct V_17 * V_5 = V_2 -> V_5 ;
if ( F_48 ( & V_2 -> V_40 ) )
return;
if ( -- V_5 -> V_52 )
F_53 ( V_5 ) ;
V_2 -> V_5 = NULL ;
}
static void F_54 ( struct V_17 * V_5 )
{
int V_29 = F_55 () ;
V_5 -> V_42 ++ ;
F_29 ( V_29 , V_5 ) ;
F_56 () ;
while ( ! F_17 ( V_5 ) )
F_5 () ;
}
static void F_57 ( struct V_17 * V_5 )
{
int V_29 = F_55 () ;
F_44 () ;
V_5 -> V_42 -- ;
F_29 ( V_29 , V_5 ) ;
F_56 () ;
}
static int F_58 ( struct V_54 * V_55 ,
unsigned long V_56 , void * V_57 )
{
int V_29 = ( unsigned long ) V_57 ;
struct V_1 * V_2 ;
switch ( V_56 & ~ V_58 ) {
case V_59 :
case V_60 :
case V_61 :
case V_62 :
case V_63 :
case V_64 :
break;
default:
return V_65 ;
}
F_59 ( & V_66 ) ;
V_2 = F_26 ( V_48 , V_29 ) ;
if ( ! V_2 || ! V_2 -> V_5 )
goto V_45;
switch ( V_56 & ~ V_58 ) {
case V_59 :
case V_60 :
F_54 ( V_2 -> V_5 ) ;
break;
case V_61 :
case V_62 :
F_45 ( V_2 -> V_5 ) ;
case V_63 :
case V_64 :
F_57 ( V_2 -> V_5 ) ;
break;
}
V_45:
F_60 ( & V_66 ) ;
return V_65 ;
}
static int T_3 F_61 ( void )
{
return F_62 ( & V_67 ) ;
}
