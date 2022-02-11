static bool F_1 ( void * V_1 , enum V_2 V_3 )
{
struct V_4 * V_5 = V_1 ;
switch ( V_3 ) {
case V_6 :
F_2 ( V_5 ) ;
F_3 ( V_5 , & V_7 ) ;
return true ;
default:
return false ;
}
}
static inline void F_4 ( struct V_4 * V_5 )
{
F_5 ( V_5 , & V_7 ) ;
F_6 ( V_5 , & V_7 ) ;
}
static inline void F_7 ( struct V_4 * V_5 )
{
F_8 ( V_5 , & V_7 ) ;
F_3 ( V_5 , & V_7 ) ;
}
static inline void F_4 ( struct V_4 * V_5 )
{ }
static inline void F_7 ( struct V_4 * V_5 )
{ }
void F_9 ( struct V_4 * V_5 , T_1 V_8 )
{
int V_9 ;
unsigned long V_10 ;
F_10 ( & V_5 -> V_11 , V_10 ) ;
F_11 (cpu) {
T_2 * V_12 = F_12 ( V_5 -> V_13 , V_9 ) ;
* V_12 = 0 ;
}
V_5 -> V_14 = V_8 ;
F_13 ( & V_5 -> V_11 , V_10 ) ;
}
void F_14 ( struct V_4 * V_5 , T_1 V_8 , T_2 V_15 )
{
T_1 V_14 ;
F_15 () ;
V_14 = F_16 ( * V_5 -> V_13 ) + V_8 ;
if ( V_14 >= V_15 || V_14 <= - V_15 ) {
unsigned long V_10 ;
F_10 ( & V_5 -> V_11 , V_10 ) ;
V_5 -> V_14 += V_14 ;
F_17 ( * V_5 -> V_13 , V_14 - V_8 ) ;
F_13 ( & V_5 -> V_11 , V_10 ) ;
} else {
F_18 ( * V_5 -> V_13 , V_8 ) ;
}
F_19 () ;
}
T_1 F_20 ( struct V_4 * V_5 )
{
T_1 V_16 ;
int V_9 ;
unsigned long V_10 ;
F_10 ( & V_5 -> V_11 , V_10 ) ;
V_16 = V_5 -> V_14 ;
F_21 (cpu) {
T_2 * V_12 = F_12 ( V_5 -> V_13 , V_9 ) ;
V_16 += * V_12 ;
}
F_13 ( & V_5 -> V_11 , V_10 ) ;
return V_16 ;
}
int F_22 ( struct V_4 * V_5 , T_1 V_8 , T_3 V_17 ,
struct V_18 * V_19 )
{
unsigned long V_10 V_20 ;
F_23 ( & V_5 -> V_11 ) ;
F_24 ( & V_5 -> V_11 , V_19 ) ;
V_5 -> V_14 = V_8 ;
V_5 -> V_13 = F_25 ( T_2 , V_17 ) ;
if ( ! V_5 -> V_13 )
return - V_21 ;
F_4 ( V_5 ) ;
#ifdef F_26
F_27 ( & V_5 -> V_22 ) ;
F_28 ( & V_23 , V_10 ) ;
F_29 ( & V_5 -> V_22 , & V_24 ) ;
F_30 ( & V_23 , V_10 ) ;
#endif
return 0 ;
}
void F_2 ( struct V_4 * V_5 )
{
unsigned long V_10 V_20 ;
if ( ! V_5 -> V_13 )
return;
F_7 ( V_5 ) ;
#ifdef F_26
F_28 ( & V_23 , V_10 ) ;
F_31 ( & V_5 -> V_22 ) ;
F_30 ( & V_23 , V_10 ) ;
#endif
F_32 ( V_5 -> V_13 ) ;
V_5 -> V_13 = NULL ;
}
static void F_33 ( void )
{
int V_25 = F_34 () ;
V_26 = F_35 ( 32 , V_25 * 2 ) ;
}
static int F_36 ( struct V_27 * V_28 ,
unsigned long V_29 , void * V_30 )
{
#ifdef F_26
unsigned int V_9 ;
struct V_4 * V_5 ;
F_33 () ;
if ( V_29 != V_31 && V_29 != V_32 )
return V_33 ;
V_9 = ( unsigned long ) V_30 ;
F_37 ( & V_23 ) ;
F_38 (fbc, &percpu_counters, list) {
T_2 * V_12 ;
unsigned long V_10 ;
F_10 ( & V_5 -> V_11 , V_10 ) ;
V_12 = F_12 ( V_5 -> V_13 , V_9 ) ;
V_5 -> V_14 += * V_12 ;
* V_12 = 0 ;
F_13 ( & V_5 -> V_11 , V_10 ) ;
}
F_39 ( & V_23 ) ;
#endif
return V_33 ;
}
int F_40 ( struct V_4 * V_5 , T_1 V_34 , T_2 V_15 )
{
T_1 V_14 ;
V_14 = F_41 ( V_5 ) ;
if ( abs ( V_14 - V_34 ) > ( V_15 * F_34 () ) ) {
if ( V_14 > V_34 )
return 1 ;
else
return - 1 ;
}
V_14 = F_42 ( V_5 ) ;
if ( V_14 > V_34 )
return 1 ;
else if ( V_14 < V_34 )
return - 1 ;
else
return 0 ;
}
static int T_4 F_43 ( void )
{
F_33 () ;
F_44 ( F_36 , 0 ) ;
return 0 ;
}
