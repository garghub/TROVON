static struct V_1 * F_1 ( struct V_2 * V_3 , T_1 V_4 )
{
struct V_1 * V_5 = NULL ;
struct V_6 * V_7 ;
struct V_8 * V_9 ;
struct V_10 * V_11 = V_3 -> V_12 -> V_11 ;
F_2 ( & V_11 -> V_13 ) ;
if ( ! F_3 ( & V_3 -> V_14 , ( unsigned long ) V_4 , & V_9 ) ) {
V_7 = F_4 ( V_9 , struct V_6 , V_15 ) ;
V_5 = V_7 -> V_16 ;
}
F_5 ( & V_11 -> V_13 ) ;
return V_5 ;
}
static int F_6 ( struct V_2 * V_3 , struct V_1 * V_16 ,
T_1 V_4 )
{
struct V_6 * V_17 ;
struct V_10 * V_11 = V_3 -> V_12 -> V_11 ;
F_7 ( L_1 , V_4 ) ;
V_17 = F_8 ( sizeof( * V_17 ) , V_18 ) ;
if ( ! V_17 )
return - V_19 ;
V_17 -> V_16 = V_16 ;
V_17 -> V_15 . V_20 = ( unsigned long ) V_4 ;
F_2 ( & V_11 -> V_13 ) ;
F_9 ( & V_3 -> V_14 , & V_17 -> V_15 ) ;
F_10 ( & V_17 -> V_21 , & V_3 -> V_22 ) ;
F_5 ( & V_11 -> V_13 ) ;
return 0 ;
}
static int F_11 ( struct V_2 * V_3 , T_1 V_4 )
{
struct V_6 * V_7 ;
struct V_8 * V_9 ;
struct V_10 * V_11 = V_3 -> V_12 -> V_11 ;
F_7 ( L_1 , V_4 ) ;
F_2 ( & V_11 -> V_13 ) ;
if ( F_3 ( & V_3 -> V_14 , ( unsigned long ) V_4 , & V_9 ) ) {
F_5 ( & V_11 -> V_13 ) ;
return - V_23 ;
}
V_7 = F_4 ( V_9 , struct V_6 , V_15 ) ;
F_12 ( & V_3 -> V_14 , V_9 ) ;
F_13 ( & V_7 -> V_21 ) ;
F_5 ( & V_11 -> V_13 ) ;
F_14 ( V_7 ) ;
return 0 ;
}
int F_15 ( struct V_10 * V_11 , void * V_24 , struct V_1 * V_25 )
{
static T_1 V_26 = 0 ;
static F_16 ( V_27 ) ;
struct V_28 * V_29 = V_24 ;
if ( V_25 -> V_4 ) {
V_29 -> V_4 = V_25 -> V_4 ;
} else {
do {
F_17 ( & V_27 ) ;
if ( ! V_26 )
++ V_26 ;
V_29 -> V_4 = V_26 ++ ;
F_18 ( & V_27 ) ;
} while ( F_1 ( V_25 -> V_3 , V_29 -> V_4 ) );
V_25 -> V_4 = V_29 -> V_4 ;
F_6 ( V_25 -> V_3 , V_25 , V_29 -> V_4 ) ;
}
F_7 ( L_2 , V_29 -> V_4 ) ;
return 0 ;
}
int F_19 ( struct V_10 * V_11 , void * V_24 ,
struct V_1 * V_25 )
{
struct V_28 * V_29 = V_24 ;
struct V_1 * V_30 ;
F_7 ( L_2 , V_29 -> V_4 ) ;
if ( ( V_30 = F_1 ( V_25 -> V_3 , V_29 -> V_4 ) ) ) {
V_30 -> V_31 = 1 ;
F_11 ( V_25 -> V_3 , V_29 -> V_4 ) ;
return 0 ;
}
return - V_23 ;
}
