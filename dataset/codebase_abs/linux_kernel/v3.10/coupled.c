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
}
static void F_23 ( int V_27 )
{
struct V_29 * V_30 = & F_24 ( V_31 , V_27 ) ;
if ( ! F_25 ( V_27 , & V_28 ) )
F_26 ( V_27 , V_30 , 0 ) ;
}
static void F_27 ( int V_32 ,
struct V_13 * V_5 )
{
int V_27 ;
F_19 (cpu, coupled->coupled_cpus)
if ( V_27 != V_32 && F_20 ( V_27 ) )
F_23 ( V_27 ) ;
}
static void F_28 ( int V_27 ,
struct V_13 * V_5 , int V_33 )
{
int V_21 ;
V_5 -> V_25 [ V_27 ] = V_33 ;
V_21 = F_6 ( & V_5 -> V_15 ) & V_22 ;
if ( V_21 == V_5 -> V_6 )
F_27 ( V_27 , V_5 ) ;
}
static void F_29 ( int V_27 ,
struct V_13 * V_5 )
{
F_30 ( & V_5 -> V_15 ) ;
V_5 -> V_25 [ V_27 ] = V_34 ;
}
static void F_31 ( int V_27 , struct V_13 * V_5 )
{
F_29 ( V_27 , V_5 ) ;
F_32 ( V_14 , & V_5 -> V_15 ) ;
}
static int F_33 ( int V_27 )
{
F_34 () ;
while ( F_35 ( V_27 , & V_28 ) )
F_5 () ;
F_36 () ;
return F_37 () ? - V_35 : 0 ;
}
int F_38 ( struct V_1 * V_2 ,
struct V_7 * V_8 , int V_33 )
{
int V_36 = - 1 ;
struct V_13 * V_5 = V_2 -> V_5 ;
if ( ! V_5 )
return - V_19 ;
while ( V_5 -> V_37 ) {
if ( F_33 ( V_2 -> V_27 ) ) {
F_34 () ;
return V_36 ;
}
V_36 = F_39 ( V_2 , V_8 ,
V_2 -> V_38 ) ;
}
F_18 () ;
F_28 ( V_2 -> V_27 , V_5 , V_33 ) ;
V_39:
while ( ! F_15 ( V_5 ) ) {
if ( F_33 ( V_2 -> V_27 ) ) {
F_29 ( V_2 -> V_27 , V_5 ) ;
goto V_40;
}
if ( V_5 -> V_37 ) {
F_29 ( V_2 -> V_27 , V_5 ) ;
goto V_40;
}
V_36 = F_39 ( V_2 , V_8 ,
V_2 -> V_38 ) ;
}
if ( F_33 ( V_2 -> V_27 ) ) {
F_29 ( V_2 -> V_27 , V_5 ) ;
goto V_40;
}
F_9 ( V_5 ) ;
while ( ! F_14 ( V_5 ) ) {
if ( ! F_15 ( V_5 ) )
if ( ! F_11 ( V_5 ) )
goto V_39;
F_5 () ;
}
V_33 = F_17 ( V_2 , V_5 ) ;
V_36 = F_39 ( V_2 , V_8 , V_33 ) ;
F_31 ( V_2 -> V_27 , V_5 ) ;
V_40:
F_34 () ;
while ( ! F_13 ( V_5 ) )
F_5 () ;
return V_36 ;
}
static void F_40 ( struct V_13 * V_5 )
{
T_2 V_41 ;
F_41 ( & V_41 , V_42 , & V_5 -> V_43 ) ;
V_5 -> V_6 = F_42 ( & V_41 ) ;
}
int F_43 ( struct V_1 * V_2 )
{
int V_27 ;
struct V_1 * V_44 ;
struct V_29 * V_30 ;
struct V_13 * V_5 ;
if ( F_44 ( & V_2 -> V_43 ) )
return 0 ;
F_19 (cpu, dev->coupled_cpus) {
V_44 = F_24 ( V_45 , V_27 ) ;
if ( V_44 && V_44 -> V_5 ) {
V_5 = V_44 -> V_5 ;
goto V_46;
}
}
V_5 = F_45 ( sizeof( struct V_13 ) , V_47 ) ;
if ( ! V_5 )
return - V_48 ;
V_5 -> V_43 = V_2 -> V_43 ;
V_46:
V_2 -> V_5 = V_5 ;
if ( F_46 ( ! F_47 ( & V_2 -> V_43 , & V_5 -> V_43 ) ) )
V_5 -> V_37 ++ ;
F_40 ( V_5 ) ;
V_5 -> V_49 ++ ;
V_30 = & F_24 ( V_31 , V_2 -> V_27 ) ;
V_30 -> V_50 = F_21 ;
V_30 -> V_26 = ( void * ) ( unsigned long ) V_2 -> V_27 ;
return 0 ;
}
void F_48 ( struct V_1 * V_2 )
{
struct V_13 * V_5 = V_2 -> V_5 ;
if ( F_44 ( & V_2 -> V_43 ) )
return;
if ( -- V_5 -> V_49 )
F_49 ( V_5 ) ;
V_2 -> V_5 = NULL ;
}
static void F_50 ( struct V_13 * V_5 )
{
int V_27 = F_51 () ;
V_5 -> V_37 ++ ;
F_27 ( V_27 , V_5 ) ;
F_52 () ;
while ( ! F_16 ( V_5 ) )
F_5 () ;
}
static void F_53 ( struct V_13 * V_5 )
{
int V_27 = F_51 () ;
F_54 () ;
V_5 -> V_37 -- ;
F_27 ( V_27 , V_5 ) ;
F_52 () ;
}
static int F_55 ( struct V_51 * V_52 ,
unsigned long V_53 , void * V_54 )
{
int V_27 = ( unsigned long ) V_54 ;
struct V_1 * V_2 ;
switch ( V_53 & ~ V_55 ) {
case V_56 :
case V_57 :
case V_58 :
case V_59 :
case V_60 :
case V_61 :
break;
default:
return V_62 ;
}
F_56 ( & V_63 ) ;
V_2 = F_24 ( V_45 , V_27 ) ;
if ( ! V_2 || ! V_2 -> V_5 )
goto V_40;
switch ( V_53 & ~ V_55 ) {
case V_56 :
case V_57 :
F_50 ( V_2 -> V_5 ) ;
break;
case V_58 :
case V_59 :
F_40 ( V_2 -> V_5 ) ;
case V_60 :
case V_61 :
F_53 ( V_2 -> V_5 ) ;
break;
}
V_40:
F_57 ( & V_63 ) ;
return V_62 ;
}
static int T_3 F_58 ( void )
{
return F_59 ( & V_64 ) ;
}
