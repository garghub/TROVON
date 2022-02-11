static int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
struct V_4 * V_5 ;
V_5 = F_2 ( sizeof( * V_5 ) , V_6 ) ;
if ( ! V_5 )
return - V_7 ;
F_3 ( & V_5 -> V_8 , 0 , V_3 ) ;
F_4 ( & V_5 -> V_9 ) ;
V_5 -> V_10 = V_3 ;
V_2 -> V_11 = V_5 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_11 ;
F_6 ( & V_5 -> V_9 ) ;
if ( ! F_7 ( & V_5 -> V_8 ) ) {
F_8 ( & V_5 -> V_9 ) ;
return - V_12 ;
}
F_9 ( & V_5 -> V_8 ) ;
F_8 ( & V_5 -> V_9 ) ;
F_10 ( V_5 ) ;
V_2 -> V_11 = NULL ;
return 0 ;
}
int F_11 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
const struct V_15 * V_16 ,
struct V_17 * V_18 )
{
struct V_4 * V_5 = V_2 -> V_11 ;
struct V_19 * V_20 = V_18 -> V_21 ;
enum V_22 V_23 ;
unsigned long V_24 , V_25 ;
int V_26 ;
if ( V_20 -> V_27 != V_28 )
return 0 ;
if ( V_16 )
V_24 = V_16 -> V_24 ;
else
V_24 = 0 ;
if ( V_16 && V_16 -> V_25 )
V_25 = V_16 -> V_25 ;
else
V_25 = V_2 -> V_29 ;
V_23 = V_30 ;
if ( V_16 && V_16 -> V_31 & V_32 )
V_23 = V_33 ;
F_6 ( & V_5 -> V_9 ) ;
V_26 = F_12 ( & V_5 -> V_8 , V_20 ,
V_18 -> V_34 , V_18 -> V_35 , 0 ,
V_24 , V_25 , V_23 ) ;
F_8 ( & V_5 -> V_9 ) ;
if ( ! V_26 ) {
V_18 -> V_27 = V_20 -> V_27 ;
if ( & V_14 -> V_18 == V_18 )
V_14 -> V_36 = ( V_14 -> V_18 . V_27 << V_37 ) +
V_14 -> V_38 -> V_2 [ V_14 -> V_18 . V_39 ] . V_40 ;
}
return V_26 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
const struct V_15 * V_16 ,
struct V_17 * V_18 )
{
struct V_4 * V_5 = V_2 -> V_11 ;
struct V_19 * V_20 ;
int V_26 ;
F_6 ( & V_5 -> V_9 ) ;
if ( V_5 -> V_10 < V_18 -> V_34 ) {
F_8 ( & V_5 -> V_9 ) ;
return 0 ;
}
V_5 -> V_10 -= V_18 -> V_34 ;
F_8 ( & V_5 -> V_9 ) ;
V_20 = F_2 ( sizeof( * V_20 ) , V_6 ) ;
if ( ! V_20 ) {
V_26 = - V_7 ;
goto V_41;
}
V_20 -> V_27 = V_28 ;
V_20 -> V_29 = V_18 -> V_34 ;
V_18 -> V_21 = V_20 ;
if ( V_16 -> V_24 || V_16 -> V_25 || V_16 -> V_31 & V_32 ) {
V_26 = F_11 ( V_2 , V_14 , V_16 , V_18 ) ;
if ( F_14 ( V_26 ) ) {
F_10 ( V_20 ) ;
V_18 -> V_21 = NULL ;
V_26 = 0 ;
goto V_41;
}
} else {
V_18 -> V_27 = V_20 -> V_27 ;
}
return 0 ;
V_41:
F_6 ( & V_5 -> V_9 ) ;
V_5 -> V_10 += V_18 -> V_34 ;
F_8 ( & V_5 -> V_9 ) ;
return V_26 ;
}
static void F_15 ( struct V_1 * V_2 ,
struct V_17 * V_18 )
{
struct V_4 * V_5 = V_2 -> V_11 ;
struct V_19 * V_20 = V_18 -> V_21 ;
if ( ! V_20 )
return;
F_6 ( & V_5 -> V_9 ) ;
if ( V_20 -> V_27 != V_28 )
F_16 ( V_20 ) ;
V_5 -> V_10 += V_18 -> V_34 ;
F_8 ( & V_5 -> V_9 ) ;
F_10 ( V_20 ) ;
V_18 -> V_21 = NULL ;
}
static void F_17 ( struct V_1 * V_2 ,
const char * V_42 )
{
struct V_4 * V_5 = V_2 -> V_11 ;
struct V_43 V_44 = F_18 ( V_42 ) ;
F_6 ( & V_5 -> V_9 ) ;
F_19 ( & V_5 -> V_8 , & V_44 ) ;
F_8 ( & V_5 -> V_9 ) ;
}
