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
T_2 * V_32 = & F_26 ( V_33 , V_29 ) ;
if ( ! F_27 ( V_29 , & V_31 ) )
F_28 ( V_29 , V_32 ) ;
}
static void F_29 ( int V_34 ,
struct V_17 * V_5 )
{
int V_29 ;
F_20 (cpu, &coupled->coupled_cpus)
if ( V_29 != V_34 && F_21 ( V_29 ) )
F_25 ( V_29 ) ;
}
static int F_30 ( int V_29 ,
struct V_17 * V_5 , int V_35 )
{
V_5 -> V_27 [ V_29 ] = V_35 ;
return F_6 ( & V_5 -> V_19 ) & V_25 ;
}
static void F_31 ( int V_29 ,
struct V_17 * V_5 )
{
F_32 ( & V_5 -> V_19 ) ;
V_5 -> V_27 [ V_29 ] = V_36 ;
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
T_3 V_37 ;
int V_21 ;
F_40 ( & V_37 , V_38 , & V_5 -> V_39 ) ;
V_21 = F_40 ( & V_37 , & V_31 , & V_37 ) ;
return V_21 ;
}
int F_41 ( struct V_1 * V_2 ,
struct V_7 * V_8 , int V_35 )
{
int V_40 = - 1 ;
struct V_17 * V_5 = V_2 -> V_5 ;
int V_24 ;
if ( ! V_5 )
return - V_16 ;
while ( V_5 -> V_41 ) {
F_35 ( V_2 -> V_29 ) ;
if ( F_42 () ) {
F_37 () ;
return V_40 ;
}
V_40 = F_43 ( V_2 , V_8 ,
V_8 -> V_15 ) ;
F_38 () ;
}
F_19 () ;
V_42:
F_24 ( V_2 -> V_29 , & V_30 ) ;
V_24 = F_30 ( V_2 -> V_29 , V_5 , V_35 ) ;
if ( V_24 == V_5 -> V_6 ) {
F_23 ( V_2 -> V_29 , & V_30 ) ;
F_29 ( V_2 -> V_29 , V_5 ) ;
}
V_43:
while ( ! F_16 ( V_5 ) ||
! F_36 ( V_2 -> V_29 , & V_30 ) ) {
if ( F_35 ( V_2 -> V_29 ) )
continue;
if ( F_42 () ) {
F_31 ( V_2 -> V_29 , V_5 ) ;
goto V_44;
}
if ( V_5 -> V_41 ) {
F_31 ( V_2 -> V_29 , V_5 ) ;
goto V_44;
}
V_40 = F_43 ( V_2 , V_8 ,
V_8 -> V_15 ) ;
F_38 () ;
}
F_35 ( V_2 -> V_29 ) ;
if ( F_42 () ) {
F_31 ( V_2 -> V_29 , V_5 ) ;
goto V_44;
}
F_44 () ;
F_10 ( V_5 ) ;
while ( ! F_15 ( V_5 ) ) {
if ( ! F_16 ( V_5 ) )
if ( ! F_12 ( V_5 ) )
goto V_43;
F_5 () ;
}
F_19 () ;
if ( F_39 ( V_5 ) ) {
F_33 ( V_2 -> V_29 , V_5 ) ;
F_1 ( V_2 , & V_5 -> V_45 ) ;
goto V_42;
}
V_35 = F_18 ( V_2 , V_5 ) ;
V_40 = F_43 ( V_2 , V_8 , V_35 ) ;
F_33 ( V_2 -> V_29 , V_5 ) ;
V_44:
F_37 () ;
while ( ! F_14 ( V_5 ) )
F_5 () ;
return V_40 ;
}
static void F_45 ( struct V_17 * V_5 )
{
T_3 V_37 ;
F_40 ( & V_37 , V_38 , & V_5 -> V_39 ) ;
V_5 -> V_6 = F_46 ( & V_37 ) ;
}
int F_47 ( struct V_1 * V_2 )
{
int V_29 ;
struct V_1 * V_46 ;
T_2 * V_32 ;
struct V_17 * V_5 ;
if ( F_48 ( & V_2 -> V_39 ) )
return 0 ;
F_20 (cpu, &dev->coupled_cpus) {
V_46 = F_26 ( V_47 , V_29 ) ;
if ( V_46 && V_46 -> V_5 ) {
V_5 = V_46 -> V_5 ;
goto V_48;
}
}
V_5 = F_49 ( sizeof( struct V_17 ) , V_49 ) ;
if ( ! V_5 )
return - V_50 ;
V_5 -> V_39 = V_2 -> V_39 ;
V_48:
V_2 -> V_5 = V_5 ;
if ( F_50 ( ! F_51 ( & V_2 -> V_39 , & V_5 -> V_39 ) ) )
V_5 -> V_41 ++ ;
F_45 ( V_5 ) ;
V_5 -> V_51 ++ ;
V_32 = & F_26 ( V_33 , V_2 -> V_29 ) ;
V_32 -> V_52 = F_22 ;
V_32 -> V_28 = ( void * ) ( unsigned long ) V_2 -> V_29 ;
return 0 ;
}
void F_52 ( struct V_1 * V_2 )
{
struct V_17 * V_5 = V_2 -> V_5 ;
if ( F_48 ( & V_2 -> V_39 ) )
return;
if ( -- V_5 -> V_51 )
F_53 ( V_5 ) ;
V_2 -> V_5 = NULL ;
}
static void F_54 ( struct V_17 * V_5 )
{
int V_29 = F_55 () ;
V_5 -> V_41 ++ ;
F_29 ( V_29 , V_5 ) ;
F_56 () ;
while ( ! F_17 ( V_5 ) )
F_5 () ;
}
static void F_57 ( struct V_17 * V_5 )
{
int V_29 = F_55 () ;
F_44 () ;
V_5 -> V_41 -- ;
F_29 ( V_29 , V_5 ) ;
F_56 () ;
}
static int F_58 ( unsigned int V_29 )
{
struct V_1 * V_2 ;
F_59 ( & V_53 ) ;
V_2 = F_26 ( V_47 , V_29 ) ;
if ( V_2 && V_2 -> V_5 ) {
F_45 ( V_2 -> V_5 ) ;
F_57 ( V_2 -> V_5 ) ;
}
F_60 ( & V_53 ) ;
return 0 ;
}
static int F_61 ( unsigned int V_29 )
{
struct V_1 * V_2 ;
F_59 ( & V_53 ) ;
V_2 = F_26 ( V_47 , V_29 ) ;
if ( V_2 && V_2 -> V_5 )
F_54 ( V_2 -> V_5 ) ;
F_60 ( & V_53 ) ;
return 0 ;
}
static int T_4 F_62 ( void )
{
int V_21 ;
V_21 = F_63 ( V_54 ,
L_1 ,
F_61 ,
F_58 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_63 ( V_55 ,
L_2 ,
F_58 ,
F_61 ) ;
if ( V_21 < 0 )
F_64 ( V_54 ) ;
return V_21 ;
}
