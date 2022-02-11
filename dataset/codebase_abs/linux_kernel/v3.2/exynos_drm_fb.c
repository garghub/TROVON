static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( L_1 , __FILE__ ) ;
F_4 ( V_2 ) ;
if ( ! V_4 -> V_5 && V_4 -> V_6 )
F_5 ( V_2 -> V_7 , V_4 -> V_6 ) ;
F_6 ( V_4 ) ;
V_4 = NULL ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
unsigned int * V_10 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( L_1 , __FILE__ ) ;
return F_8 ( V_9 ,
& V_4 -> V_5 -> V_11 , V_10 ) ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_8 * V_9 , unsigned V_12 ,
unsigned V_13 , struct V_14 * V_15 ,
unsigned V_16 )
{
F_3 ( L_1 , __FILE__ ) ;
return 0 ;
}
static struct V_1 *
F_10 ( struct V_8 * V_9 , struct V_17 * V_7 ,
struct V_18 * V_19 )
{
struct V_3 * V_4 ;
struct V_1 * V_2 ;
struct V_20 * V_5 = NULL ;
struct V_21 * V_22 ;
unsigned int V_23 ;
int V_24 ;
F_3 ( L_1 , __FILE__ ) ;
V_19 -> V_25 = F_11 ( V_19 -> V_25 ,
V_19 -> V_26 * ( V_19 -> V_27 >> 3 ) ) ;
F_12 ( L_2 ,
V_19 -> V_26 , V_19 -> V_28 ) ;
V_4 = F_13 ( sizeof( * V_4 ) , V_29 ) ;
if ( ! V_4 ) {
F_14 ( L_3 ) ;
return F_15 ( - V_30 ) ;
}
V_2 = & V_4 -> V_2 ;
V_24 = F_16 ( V_7 , V_2 , & V_31 ) ;
if ( V_24 ) {
F_14 ( L_4 ) ;
goto V_32;
}
F_12 ( L_5 , V_2 -> V_11 . V_33 ) ;
V_23 = V_19 -> V_25 * V_19 -> V_28 ;
if ( ! V_19 -> V_10 ) {
if ( ! V_9 ) {
struct V_34 * V_6 ;
V_6 = F_17 ( V_7 , V_23 ) ;
if ( F_18 ( V_6 ) ) {
V_24 = F_19 ( V_6 ) ;
goto V_35;
}
V_4 -> V_6 = V_6 ;
F_12 ( L_6 ,
( unsigned long ) V_6 -> V_36 , V_23 ) ;
goto V_37;
} else {
V_5 = F_20 ( V_7 , V_9 ,
& V_19 -> V_10 ,
V_23 ) ;
if ( F_18 ( V_5 ) ) {
V_24 = F_19 ( V_5 ) ;
goto V_35;
}
}
} else {
V_22 = F_21 ( V_7 , V_9 , V_19 -> V_10 ) ;
if ( ! V_22 ) {
F_14 ( L_7 ) ;
goto V_35;
}
V_5 = F_22 ( V_22 ) ;
F_23 ( V_22 ) ;
}
V_4 -> V_6 = V_5 -> V_6 ;
F_12 ( L_8 ,
( unsigned long ) V_4 -> V_6 -> V_36 , V_23 ,
( unsigned int ) & V_5 -> V_11 ) ;
V_37:
V_4 -> V_5 = V_5 ;
F_24 ( V_2 , V_19 ) ;
return V_2 ;
V_35:
F_4 ( V_2 ) ;
V_32:
F_6 ( V_4 ) ;
return F_15 ( V_24 ) ;
}
struct V_1 * F_25 ( struct V_17 * V_7 ,
struct V_8 * V_9 ,
struct V_18 * V_19 )
{
F_3 ( L_1 , __FILE__ ) ;
return F_10 ( V_9 , V_7 , V_19 ) ;
}
struct V_34 * F_26 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_34 * V_6 ;
F_3 ( L_1 , __FILE__ ) ;
V_6 = V_4 -> V_6 ;
if ( ! V_6 )
return NULL ;
F_3 ( L_9 ,
( unsigned long ) V_6 -> V_38 ,
( unsigned long ) V_6 -> V_36 ) ;
return V_6 ;
}
static void F_27 ( struct V_17 * V_7 )
{
struct V_39 * V_40 = V_7 -> V_41 ;
struct V_42 * V_43 = V_40 -> V_43 ;
if ( V_43 )
F_28 ( V_43 ) ;
}
void F_29 ( struct V_17 * V_7 )
{
V_7 -> V_44 . V_45 = 0 ;
V_7 -> V_44 . V_46 = 0 ;
V_7 -> V_44 . V_47 = 4096 ;
V_7 -> V_44 . V_48 = 4096 ;
V_7 -> V_44 . V_49 = & V_50 ;
}
