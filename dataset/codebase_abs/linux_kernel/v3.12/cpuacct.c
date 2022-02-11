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
return F_1 ( F_6 ( & V_7 -> V_3 ) ) ;
}
static struct V_2 *
F_7 ( struct V_2 * V_8 )
{
struct V_1 * V_7 ;
if ( ! V_8 )
return & V_9 . V_3 ;
V_7 = F_8 ( sizeof( * V_7 ) , V_10 ) ;
if ( ! V_7 )
goto V_11;
V_7 -> V_12 = F_9 ( V_13 ) ;
if ( ! V_7 -> V_12 )
goto V_14;
V_7 -> V_15 = F_9 ( struct V_16 ) ;
if ( ! V_7 -> V_15 )
goto V_17;
return & V_7 -> V_3 ;
V_17:
F_10 ( V_7 -> V_12 ) ;
V_14:
F_11 ( V_7 ) ;
V_11:
return F_12 ( - V_18 ) ;
}
static void F_13 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
F_10 ( V_7 -> V_15 ) ;
F_10 ( V_7 -> V_12 ) ;
F_11 ( V_7 ) ;
}
static V_13 F_14 ( struct V_1 * V_7 , int V_19 )
{
V_13 * V_12 = F_15 ( V_7 -> V_12 , V_19 ) ;
V_13 V_20 ;
#ifndef F_16
F_17 ( & F_18 ( V_19 ) -> V_21 ) ;
V_20 = * V_12 ;
F_19 ( & F_18 ( V_19 ) -> V_21 ) ;
#else
V_20 = * V_12 ;
#endif
return V_20 ;
}
static void F_20 ( struct V_1 * V_7 , int V_19 , V_13 V_22 )
{
V_13 * V_12 = F_15 ( V_7 -> V_12 , V_19 ) ;
#ifndef F_16
F_17 ( & F_18 ( V_19 ) -> V_21 ) ;
* V_12 = V_22 ;
F_19 ( & F_18 ( V_19 ) -> V_21 ) ;
#else
* V_12 = V_22 ;
#endif
}
static V_13 F_21 ( struct V_2 * V_3 , struct V_23 * V_24 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
V_13 V_25 = 0 ;
int V_26 ;
F_22 (i)
V_25 += F_14 ( V_7 , V_26 ) ;
return V_25 ;
}
static int F_23 ( struct V_2 * V_3 , struct V_23 * V_24 ,
V_13 V_27 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
int V_28 = 0 ;
int V_26 ;
if ( V_27 ) {
V_28 = - V_29 ;
goto V_11;
}
F_22 (i)
F_20 ( V_7 , V_26 , 0 ) ;
V_11:
return V_28 ;
}
static int F_24 ( struct V_2 * V_3 ,
struct V_23 * V_24 , struct V_30 * V_31 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
V_13 V_32 ;
int V_26 ;
F_22 (i) {
V_32 = F_14 ( V_7 , V_26 ) ;
F_25 ( V_31 , L_1 , ( unsigned long long ) V_32 ) ;
}
F_25 ( V_31 , L_2 ) ;
return 0 ;
}
static int F_26 ( struct V_2 * V_3 ,
struct V_23 * V_24 , struct V_33 * V_34 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
int V_19 ;
T_1 V_22 = 0 ;
F_27 (cpu) {
struct V_16 * V_35 = F_15 ( V_7 -> V_15 , V_19 ) ;
V_22 += V_35 -> V_15 [ V_36 ] ;
V_22 += V_35 -> V_15 [ V_37 ] ;
}
V_22 = F_28 ( V_22 ) ;
V_34 -> V_38 ( V_34 , V_39 [ V_40 ] , V_22 ) ;
V_22 = 0 ;
F_27 (cpu) {
struct V_16 * V_35 = F_15 ( V_7 -> V_15 , V_19 ) ;
V_22 += V_35 -> V_15 [ V_41 ] ;
V_22 += V_35 -> V_15 [ V_42 ] ;
V_22 += V_35 -> V_15 [ V_43 ] ;
}
V_22 = F_28 ( V_22 ) ;
V_34 -> V_38 ( V_34 , V_39 [ V_44 ] , V_22 ) ;
return 0 ;
}
void F_29 ( struct V_4 * V_5 , V_13 V_45 )
{
struct V_1 * V_7 ;
int V_19 ;
V_19 = F_30 ( V_5 ) ;
F_31 () ;
V_7 = F_3 ( V_5 ) ;
while ( true ) {
V_13 * V_12 = F_15 ( V_7 -> V_12 , V_19 ) ;
* V_12 += V_45 ;
V_7 = F_5 ( V_7 ) ;
if ( ! V_7 )
break;
}
F_32 () ;
}
void F_33 ( struct V_4 * V_46 , int V_47 , V_13 V_22 )
{
struct V_16 * V_35 ;
struct V_1 * V_7 ;
F_31 () ;
V_7 = F_3 ( V_46 ) ;
while ( V_7 != & V_9 ) {
V_35 = F_34 ( V_7 -> V_15 ) ;
V_35 -> V_15 [ V_47 ] += V_22 ;
V_7 = F_5 ( V_7 ) ;
}
F_32 () ;
}
