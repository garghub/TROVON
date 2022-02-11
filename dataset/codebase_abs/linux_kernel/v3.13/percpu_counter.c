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
int F_22 ( struct V_4 * V_5 , T_1 V_8 ,
struct V_17 * V_18 )
{
F_23 ( & V_5 -> V_11 ) ;
F_24 ( & V_5 -> V_11 , V_18 ) ;
V_5 -> V_14 = V_8 ;
V_5 -> V_13 = F_25 ( T_2 ) ;
if ( ! V_5 -> V_13 )
return - V_19 ;
F_4 ( V_5 ) ;
#ifdef F_26
F_27 ( & V_5 -> V_20 ) ;
F_28 ( & V_21 ) ;
F_29 ( & V_5 -> V_20 , & V_22 ) ;
F_30 ( & V_21 ) ;
#endif
return 0 ;
}
void F_2 ( struct V_4 * V_5 )
{
if ( ! V_5 -> V_13 )
return;
F_7 ( V_5 ) ;
#ifdef F_26
F_28 ( & V_21 ) ;
F_31 ( & V_5 -> V_20 ) ;
F_30 ( & V_21 ) ;
#endif
F_32 ( V_5 -> V_13 ) ;
V_5 -> V_13 = NULL ;
}
static void F_33 ( void )
{
int V_23 = F_34 () ;
V_24 = F_35 ( 32 , V_23 * 2 ) ;
}
static int F_36 ( struct V_25 * V_26 ,
unsigned long V_27 , void * V_28 )
{
#ifdef F_26
unsigned int V_9 ;
struct V_4 * V_5 ;
F_33 () ;
if ( V_27 != V_29 )
return V_30 ;
V_9 = ( unsigned long ) V_28 ;
F_28 ( & V_21 ) ;
F_37 (fbc, &percpu_counters, list) {
T_2 * V_12 ;
unsigned long V_10 ;
F_10 ( & V_5 -> V_11 , V_10 ) ;
V_12 = F_12 ( V_5 -> V_13 , V_9 ) ;
V_5 -> V_14 += * V_12 ;
* V_12 = 0 ;
F_13 ( & V_5 -> V_11 , V_10 ) ;
}
F_30 ( & V_21 ) ;
#endif
return V_30 ;
}
int F_38 ( struct V_4 * V_5 , T_1 V_31 )
{
T_1 V_14 ;
V_14 = F_39 ( V_5 ) ;
if ( abs ( V_14 - V_31 ) > ( V_24 * F_34 () ) ) {
if ( V_14 > V_31 )
return 1 ;
else
return - 1 ;
}
V_14 = F_40 ( V_5 ) ;
if ( V_14 > V_31 )
return 1 ;
else if ( V_14 < V_31 )
return - 1 ;
else
return 0 ;
}
static int T_3 F_41 ( void )
{
F_33 () ;
F_42 ( F_36 , 0 ) ;
return 0 ;
}
