static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( F_3 ( V_3 , V_4 ) ,
struct V_1 , V_5 ) ;
}
static inline struct V_1 * F_4 ( struct V_6 * V_7 )
{
return F_2 ( F_5 ( V_7 , V_4 ) ,
struct V_1 , V_5 ) ;
}
static inline struct V_1 * F_6 ( struct V_1 * V_8 )
{
return F_1 ( V_8 -> V_5 . V_2 -> V_9 ) ;
}
static inline struct V_1 * F_7 ( struct V_1 * V_8 )
{
if ( ! V_8 -> V_5 . V_2 -> V_9 )
return NULL ;
return F_1 ( V_8 -> V_5 . V_2 -> V_9 ) ;
}
static struct F_3 * F_8 ( struct V_2 * V_3 )
{
struct V_1 * V_8 ;
if ( ! V_3 -> V_9 )
return & V_10 . V_5 ;
V_8 = F_9 ( sizeof( * V_8 ) , V_11 ) ;
if ( ! V_8 )
goto V_12;
V_8 -> V_13 = F_10 ( V_14 ) ;
if ( ! V_8 -> V_13 )
goto V_15;
V_8 -> V_16 = F_10 ( struct V_17 ) ;
if ( ! V_8 -> V_16 )
goto V_18;
return & V_8 -> V_5 ;
V_18:
F_11 ( V_8 -> V_13 ) ;
V_15:
F_12 ( V_8 ) ;
V_12:
return F_13 ( - V_19 ) ;
}
static void F_14 ( struct V_2 * V_3 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
F_11 ( V_8 -> V_16 ) ;
F_11 ( V_8 -> V_13 ) ;
F_12 ( V_8 ) ;
}
static V_14 F_15 ( struct V_1 * V_8 , int V_20 )
{
V_14 * V_13 = F_16 ( V_8 -> V_13 , V_20 ) ;
V_14 V_21 ;
#ifndef F_17
F_18 ( & F_19 ( V_20 ) -> V_22 ) ;
V_21 = * V_13 ;
F_20 ( & F_19 ( V_20 ) -> V_22 ) ;
#else
V_21 = * V_13 ;
#endif
return V_21 ;
}
static void F_21 ( struct V_1 * V_8 , int V_20 , V_14 V_23 )
{
V_14 * V_13 = F_16 ( V_8 -> V_13 , V_20 ) ;
#ifndef F_17
F_18 ( & F_19 ( V_20 ) -> V_22 ) ;
* V_13 = V_23 ;
F_20 ( & F_19 ( V_20 ) -> V_22 ) ;
#else
* V_13 = V_23 ;
#endif
}
static V_14 F_22 ( struct V_2 * V_3 , struct V_24 * V_25 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
V_14 V_26 = 0 ;
int V_27 ;
F_23 (i)
V_26 += F_15 ( V_8 , V_27 ) ;
return V_26 ;
}
static int F_24 ( struct V_2 * V_3 , struct V_24 * V_24 ,
V_14 V_28 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
int V_29 = 0 ;
int V_27 ;
if ( V_28 ) {
V_29 = - V_30 ;
goto V_12;
}
F_23 (i)
F_21 ( V_8 , V_27 , 0 ) ;
V_12:
return V_29 ;
}
static int F_25 ( struct V_2 * V_2 , struct V_24 * V_25 ,
struct V_31 * V_32 )
{
struct V_1 * V_8 = F_1 ( V_2 ) ;
V_14 V_33 ;
int V_27 ;
F_23 (i) {
V_33 = F_15 ( V_8 , V_27 ) ;
F_26 ( V_32 , L_1 , ( unsigned long long ) V_33 ) ;
}
F_26 ( V_32 , L_2 ) ;
return 0 ;
}
static int F_27 ( struct V_2 * V_3 , struct V_24 * V_25 ,
struct V_34 * V_35 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
int V_20 ;
T_1 V_23 = 0 ;
F_28 (cpu) {
struct V_17 * V_36 = F_16 ( V_8 -> V_16 , V_20 ) ;
V_23 += V_36 -> V_16 [ V_37 ] ;
V_23 += V_36 -> V_16 [ V_38 ] ;
}
V_23 = F_29 ( V_23 ) ;
V_35 -> V_39 ( V_35 , V_40 [ V_41 ] , V_23 ) ;
V_23 = 0 ;
F_28 (cpu) {
struct V_17 * V_36 = F_16 ( V_8 -> V_16 , V_20 ) ;
V_23 += V_36 -> V_16 [ V_42 ] ;
V_23 += V_36 -> V_16 [ V_43 ] ;
V_23 += V_36 -> V_16 [ V_44 ] ;
}
V_23 = F_29 ( V_23 ) ;
V_35 -> V_39 ( V_35 , V_40 [ V_45 ] , V_23 ) ;
return 0 ;
}
void F_30 ( struct V_6 * V_7 , V_14 V_46 )
{
struct V_1 * V_8 ;
int V_20 ;
V_20 = F_31 ( V_7 ) ;
F_32 () ;
V_8 = F_4 ( V_7 ) ;
while ( true ) {
V_14 * V_13 = F_16 ( V_8 -> V_13 , V_20 ) ;
* V_13 += V_46 ;
V_8 = F_7 ( V_8 ) ;
if ( ! V_8 )
break;
}
F_33 () ;
}
void F_34 ( struct V_6 * V_47 , int V_48 , V_14 V_23 )
{
struct V_17 * V_36 ;
struct V_1 * V_8 ;
F_32 () ;
V_8 = F_4 ( V_47 ) ;
while ( V_8 != & V_10 ) {
V_36 = F_35 ( V_8 -> V_16 ) ;
V_36 -> V_16 [ V_48 ] += V_23 ;
V_8 = F_6 ( V_8 ) ;
}
F_33 () ;
}
