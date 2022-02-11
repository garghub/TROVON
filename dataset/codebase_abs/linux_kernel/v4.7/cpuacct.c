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
V_7 -> V_13 = F_8 ( struct V_14 ) ;
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
static T_1 F_13 ( struct V_1 * V_7 , int V_20 ,
enum V_21 V_22 )
{
struct V_14 * V_13 = F_14 ( V_7 -> V_13 , V_20 ) ;
T_1 V_23 ;
F_15 ( V_22 > V_24 ) ;
#ifndef F_16
F_17 ( & F_18 ( V_20 ) -> V_25 ) ;
#endif
if ( V_22 == V_24 ) {
int V_26 = 0 ;
V_23 = 0 ;
for ( V_26 = 0 ; V_26 < V_24 ; V_26 ++ )
V_23 += V_13 -> V_27 [ V_26 ] ;
} else {
V_23 = V_13 -> V_27 [ V_22 ] ;
}
#ifndef F_16
F_19 ( & F_18 ( V_20 ) -> V_25 ) ;
#endif
return V_23 ;
}
static void F_20 ( struct V_1 * V_7 , int V_20 , T_1 V_28 )
{
struct V_14 * V_13 = F_14 ( V_7 -> V_13 , V_20 ) ;
int V_26 ;
#ifndef F_16
F_17 ( & F_18 ( V_20 ) -> V_25 ) ;
#endif
for ( V_26 = 0 ; V_26 < V_24 ; V_26 ++ )
V_13 -> V_27 [ V_26 ] = V_28 ;
#ifndef F_16
F_19 ( & F_18 ( V_20 ) -> V_25 ) ;
#endif
}
static T_1 F_21 ( struct V_2 * V_3 ,
enum V_21 V_22 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
T_1 V_29 = 0 ;
int V_26 ;
F_22 (i)
V_29 += F_13 ( V_7 , V_26 , V_22 ) ;
return V_29 ;
}
static T_1 F_23 ( struct V_2 * V_3 ,
struct V_30 * V_31 )
{
return F_21 ( V_3 , V_32 ) ;
}
static T_1 F_24 ( struct V_2 * V_3 ,
struct V_30 * V_31 )
{
return F_21 ( V_3 , V_33 ) ;
}
static T_1 F_25 ( struct V_2 * V_3 , struct V_30 * V_31 )
{
return F_21 ( V_3 , V_24 ) ;
}
static int F_26 ( struct V_2 * V_3 , struct V_30 * V_31 ,
T_1 V_28 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
int V_20 ;
if ( V_28 )
return - V_34 ;
F_22 (cpu)
F_20 ( V_7 , V_20 , 0 ) ;
return 0 ;
}
static int F_27 ( struct V_35 * V_36 ,
enum V_21 V_22 )
{
struct V_1 * V_7 = F_1 ( F_28 ( V_36 ) ) ;
T_1 V_37 ;
int V_26 ;
F_22 (i) {
V_37 = F_13 ( V_7 , V_26 , V_22 ) ;
F_29 ( V_36 , L_1 , ( unsigned long long ) V_37 ) ;
}
F_29 ( V_36 , L_2 ) ;
return 0 ;
}
static int F_30 ( struct V_35 * V_36 , void * V_38 )
{
return F_27 ( V_36 , V_32 ) ;
}
static int F_31 ( struct V_35 * V_36 , void * V_38 )
{
return F_27 ( V_36 , V_33 ) ;
}
static int F_32 ( struct V_35 * V_36 , void * V_38 )
{
return F_27 ( V_36 , V_24 ) ;
}
static int F_33 ( struct V_35 * V_39 , void * V_40 )
{
struct V_1 * V_7 = F_1 ( F_28 ( V_39 ) ) ;
int V_20 ;
T_2 V_28 = 0 ;
F_22 (cpu) {
struct V_17 * V_41 = F_14 ( V_7 -> V_16 , V_20 ) ;
V_28 += V_41 -> V_16 [ V_42 ] ;
V_28 += V_41 -> V_16 [ V_43 ] ;
}
V_28 = F_34 ( V_28 ) ;
F_29 ( V_39 , L_3 , V_44 [ V_45 ] , V_28 ) ;
V_28 = 0 ;
F_22 (cpu) {
struct V_17 * V_41 = F_14 ( V_7 -> V_16 , V_20 ) ;
V_28 += V_41 -> V_16 [ V_46 ] ;
V_28 += V_41 -> V_16 [ V_47 ] ;
V_28 += V_41 -> V_16 [ V_48 ] ;
}
V_28 = F_34 ( V_28 ) ;
F_29 ( V_39 , L_3 , V_44 [ V_49 ] , V_28 ) ;
return 0 ;
}
void F_35 ( struct V_4 * V_5 , T_1 V_50 )
{
struct V_1 * V_7 ;
int V_22 = V_33 ;
struct V_51 * V_52 = F_36 ( V_5 ) ;
if ( V_52 && F_37 ( V_52 ) )
V_22 = V_32 ;
F_38 () ;
for ( V_7 = F_3 ( V_5 ) ; V_7 ; V_7 = F_5 ( V_7 ) )
F_39 ( V_7 -> V_13 ) -> V_27 [ V_22 ] += V_50 ;
F_40 () ;
}
void F_41 ( struct V_4 * V_5 , int V_22 , T_1 V_28 )
{
struct V_1 * V_7 ;
F_38 () ;
for ( V_7 = F_3 ( V_5 ) ; V_7 != & V_10 ; V_7 = F_5 ( V_7 ) )
F_39 ( V_7 -> V_16 ) -> V_16 [ V_22 ] += V_28 ;
F_40 () ;
}
