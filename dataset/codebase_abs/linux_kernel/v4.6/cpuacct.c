static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return V_3 ? F_2 ( V_3 , struct V_1 , V_3 ) : NULL ;
}
static inline struct V_1 * F_3 ( struct V_4 * V_5 )
{
return F_1 ( F_4 ( V_5 , V_6 ) ) ;
}
static inline struct V_1 * F_5 ( struct V_1 * V_7 )
{
return F_1 ( V_7 -> V_3 . V_8 ) ;
}
static struct V_2 *
F_6 ( struct V_2 * V_9 )
{
struct V_1 * V_7 ;
if ( ! V_9 )
return & V_10 . V_3 ;
V_7 = F_7 ( sizeof( * V_7 ) , V_11 ) ;
if ( ! V_7 )
goto V_12;
V_7 -> V_13 = F_8 ( V_14 ) ;
if ( ! V_7 -> V_13 )
goto V_15;
V_7 -> V_16 = F_8 ( struct V_17 ) ;
if ( ! V_7 -> V_16 )
goto V_18;
return & V_7 -> V_3 ;
V_18:
F_9 ( V_7 -> V_13 ) ;
V_15:
F_10 ( V_7 ) ;
V_12:
return F_11 ( - V_19 ) ;
}
static void F_12 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
F_9 ( V_7 -> V_16 ) ;
F_9 ( V_7 -> V_13 ) ;
F_10 ( V_7 ) ;
}
static V_14 F_13 ( struct V_1 * V_7 , int V_20 )
{
V_14 * V_13 = F_14 ( V_7 -> V_13 , V_20 ) ;
V_14 V_21 ;
#ifndef F_15
F_16 ( & F_17 ( V_20 ) -> V_22 ) ;
V_21 = * V_13 ;
F_18 ( & F_17 ( V_20 ) -> V_22 ) ;
#else
V_21 = * V_13 ;
#endif
return V_21 ;
}
static void F_19 ( struct V_1 * V_7 , int V_20 , V_14 V_23 )
{
V_14 * V_13 = F_14 ( V_7 -> V_13 , V_20 ) ;
#ifndef F_15
F_16 ( & F_17 ( V_20 ) -> V_22 ) ;
* V_13 = V_23 ;
F_18 ( & F_17 ( V_20 ) -> V_22 ) ;
#else
* V_13 = V_23 ;
#endif
}
static V_14 F_20 ( struct V_2 * V_3 , struct V_24 * V_25 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
V_14 V_26 = 0 ;
int V_27 ;
F_21 (i)
V_26 += F_13 ( V_7 , V_27 ) ;
return V_26 ;
}
static int F_22 ( struct V_2 * V_3 , struct V_24 * V_25 ,
V_14 V_23 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
int V_28 = 0 ;
int V_27 ;
if ( V_23 ) {
V_28 = - V_29 ;
goto V_12;
}
F_21 (i)
F_19 ( V_7 , V_27 , 0 ) ;
V_12:
return V_28 ;
}
static int F_23 ( struct V_30 * V_31 , void * V_32 )
{
struct V_1 * V_7 = F_1 ( F_24 ( V_31 ) ) ;
V_14 V_33 ;
int V_27 ;
F_21 (i) {
V_33 = F_13 ( V_7 , V_27 ) ;
F_25 ( V_31 , L_1 , ( unsigned long long ) V_33 ) ;
}
F_25 ( V_31 , L_2 ) ;
return 0 ;
}
static int F_26 ( struct V_30 * V_34 , void * V_35 )
{
struct V_1 * V_7 = F_1 ( F_24 ( V_34 ) ) ;
int V_20 ;
T_1 V_23 = 0 ;
F_27 (cpu) {
struct V_17 * V_36 = F_14 ( V_7 -> V_16 , V_20 ) ;
V_23 += V_36 -> V_16 [ V_37 ] ;
V_23 += V_36 -> V_16 [ V_38 ] ;
}
V_23 = F_28 ( V_23 ) ;
F_25 ( V_34 , L_3 , V_39 [ V_40 ] , V_23 ) ;
V_23 = 0 ;
F_27 (cpu) {
struct V_17 * V_36 = F_14 ( V_7 -> V_16 , V_20 ) ;
V_23 += V_36 -> V_16 [ V_41 ] ;
V_23 += V_36 -> V_16 [ V_42 ] ;
V_23 += V_36 -> V_16 [ V_43 ] ;
}
V_23 = F_28 ( V_23 ) ;
F_25 ( V_34 , L_3 , V_39 [ V_44 ] , V_23 ) ;
return 0 ;
}
void F_29 ( struct V_4 * V_5 , V_14 V_45 )
{
struct V_1 * V_7 ;
F_30 () ;
for ( V_7 = F_3 ( V_5 ) ; V_7 ; V_7 = F_5 ( V_7 ) )
* F_31 ( V_7 -> V_13 ) += V_45 ;
F_32 () ;
}
void F_33 ( struct V_4 * V_5 , int V_46 , V_14 V_23 )
{
struct V_1 * V_7 ;
F_30 () ;
for ( V_7 = F_3 ( V_5 ) ; V_7 != & V_10 ; V_7 = F_5 ( V_7 ) )
F_31 ( V_7 -> V_16 ) -> V_16 [ V_46 ] += V_23 ;
F_32 () ;
}
