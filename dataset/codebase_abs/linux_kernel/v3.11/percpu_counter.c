static int F_1 ( void * V_1 , enum V_2 V_3 )
{
struct V_4 * V_5 = V_1 ;
switch ( V_3 ) {
case V_6 :
F_2 ( V_5 ) ;
F_3 ( V_5 , & V_7 ) ;
return 1 ;
default:
return 0 ;
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
F_10 ( & V_5 -> V_10 ) ;
F_11 (cpu) {
T_2 * V_11 = F_12 ( V_5 -> V_12 , V_9 ) ;
* V_11 = 0 ;
}
V_5 -> V_13 = V_8 ;
F_13 ( & V_5 -> V_10 ) ;
}
void F_14 ( struct V_4 * V_5 , T_1 V_8 , T_2 V_14 )
{
T_1 V_13 ;
F_15 () ;
V_13 = F_16 ( * V_5 -> V_12 ) + V_8 ;
if ( V_13 >= V_14 || V_13 <= - V_14 ) {
F_10 ( & V_5 -> V_10 ) ;
V_5 -> V_13 += V_13 ;
F_13 ( & V_5 -> V_10 ) ;
F_17 ( * V_5 -> V_12 , 0 ) ;
} else {
F_17 ( * V_5 -> V_12 , V_13 ) ;
}
F_18 () ;
}
T_1 F_19 ( struct V_4 * V_5 )
{
T_1 V_15 ;
int V_9 ;
F_10 ( & V_5 -> V_10 ) ;
V_15 = V_5 -> V_13 ;
F_20 (cpu) {
T_2 * V_11 = F_12 ( V_5 -> V_12 , V_9 ) ;
V_15 += * V_11 ;
}
F_13 ( & V_5 -> V_10 ) ;
return V_15 ;
}
int F_21 ( struct V_4 * V_5 , T_1 V_8 ,
struct V_16 * V_17 )
{
F_22 ( & V_5 -> V_10 ) ;
F_23 ( & V_5 -> V_10 , V_17 ) ;
V_5 -> V_13 = V_8 ;
V_5 -> V_12 = F_24 ( T_2 ) ;
if ( ! V_5 -> V_12 )
return - V_18 ;
F_4 ( V_5 ) ;
#ifdef F_25
F_26 ( & V_5 -> V_19 ) ;
F_27 ( & V_20 ) ;
F_28 ( & V_5 -> V_19 , & V_21 ) ;
F_29 ( & V_20 ) ;
#endif
return 0 ;
}
void F_2 ( struct V_4 * V_5 )
{
if ( ! V_5 -> V_12 )
return;
F_7 ( V_5 ) ;
#ifdef F_25
F_27 ( & V_20 ) ;
F_30 ( & V_5 -> V_19 ) ;
F_29 ( & V_20 ) ;
#endif
F_31 ( V_5 -> V_12 ) ;
V_5 -> V_12 = NULL ;
}
static void F_32 ( void )
{
int V_22 = F_33 () ;
V_23 = F_34 ( 32 , V_22 * 2 ) ;
}
static int F_35 ( struct V_24 * V_25 ,
unsigned long V_26 , void * V_27 )
{
#ifdef F_25
unsigned int V_9 ;
struct V_4 * V_5 ;
F_32 () ;
if ( V_26 != V_28 )
return V_29 ;
V_9 = ( unsigned long ) V_27 ;
F_27 ( & V_20 ) ;
F_36 (fbc, &percpu_counters, list) {
T_2 * V_11 ;
unsigned long V_30 ;
F_37 ( & V_5 -> V_10 , V_30 ) ;
V_11 = F_12 ( V_5 -> V_12 , V_9 ) ;
V_5 -> V_13 += * V_11 ;
* V_11 = 0 ;
F_38 ( & V_5 -> V_10 , V_30 ) ;
}
F_29 ( & V_20 ) ;
#endif
return V_29 ;
}
int F_39 ( struct V_4 * V_5 , T_1 V_31 )
{
T_1 V_13 ;
V_13 = F_40 ( V_5 ) ;
if ( abs ( V_13 - V_31 ) > ( V_23 * F_33 () ) ) {
if ( V_13 > V_31 )
return 1 ;
else
return - 1 ;
}
V_13 = F_41 ( V_5 ) ;
if ( V_13 > V_31 )
return 1 ;
else if ( V_13 < V_31 )
return - 1 ;
else
return 0 ;
}
static int T_3 F_42 ( void )
{
F_32 () ;
F_43 ( F_35 , 0 ) ;
return 0 ;
}
