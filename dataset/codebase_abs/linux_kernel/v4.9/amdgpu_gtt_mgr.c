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
enum V_22 V_23 = V_24 ;
enum V_25 V_26 = V_27 ;
unsigned long V_28 , V_29 ;
int V_30 ;
if ( V_20 -> V_31 != V_32 )
return 0 ;
if ( V_16 )
V_28 = V_16 -> V_28 ;
else
V_28 = 0 ;
if ( V_16 && V_16 -> V_29 )
V_29 = V_16 -> V_29 ;
else
V_29 = V_2 -> V_33 ;
if ( V_16 && V_16 -> V_34 & V_35 ) {
V_23 = V_36 ;
V_26 = V_37 ;
}
F_6 ( & V_5 -> V_9 ) ;
V_30 = F_12 ( & V_5 -> V_8 , V_20 , V_18 -> V_38 ,
V_18 -> V_39 , 0 ,
V_28 , V_29 , V_23 , V_26 ) ;
F_8 ( & V_5 -> V_9 ) ;
if ( ! V_30 ) {
V_18 -> V_31 = V_20 -> V_31 ;
if ( & V_14 -> V_18 == V_18 )
V_14 -> V_40 = ( V_14 -> V_18 . V_31 << V_41 ) +
V_14 -> V_42 -> V_2 [ V_14 -> V_18 . V_43 ] . V_44 ;
}
return V_30 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
const struct V_15 * V_16 ,
struct V_17 * V_18 )
{
struct V_4 * V_5 = V_2 -> V_11 ;
struct V_19 * V_20 ;
int V_30 ;
F_6 ( & V_5 -> V_9 ) ;
if ( V_5 -> V_10 < V_18 -> V_38 ) {
F_8 ( & V_5 -> V_9 ) ;
return 0 ;
}
V_5 -> V_10 -= V_18 -> V_38 ;
F_8 ( & V_5 -> V_9 ) ;
V_20 = F_2 ( sizeof( * V_20 ) , V_6 ) ;
if ( ! V_20 )
return - V_7 ;
V_20 -> V_31 = V_32 ;
V_18 -> V_21 = V_20 ;
if ( V_16 -> V_28 || V_16 -> V_29 || V_16 -> V_34 & V_35 ) {
V_30 = F_11 ( V_2 , V_14 , V_16 , V_18 ) ;
if ( F_14 ( V_30 ) ) {
F_10 ( V_20 ) ;
V_18 -> V_21 = NULL ;
}
} else {
V_18 -> V_31 = V_20 -> V_31 ;
}
return 0 ;
}
static void F_15 ( struct V_1 * V_2 ,
struct V_17 * V_18 )
{
struct V_4 * V_5 = V_2 -> V_11 ;
struct V_19 * V_20 = V_18 -> V_21 ;
if ( ! V_20 )
return;
F_6 ( & V_5 -> V_9 ) ;
if ( V_20 -> V_31 != V_32 )
F_16 ( V_20 ) ;
V_5 -> V_10 += V_18 -> V_38 ;
F_8 ( & V_5 -> V_9 ) ;
F_10 ( V_20 ) ;
V_18 -> V_21 = NULL ;
}
static void F_17 ( struct V_1 * V_2 ,
const char * V_45 )
{
struct V_4 * V_5 = V_2 -> V_11 ;
F_6 ( & V_5 -> V_9 ) ;
F_18 ( & V_5 -> V_8 , V_45 ) ;
F_8 ( & V_5 -> V_9 ) ;
}
