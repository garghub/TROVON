static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static struct V_1 * F_3 ( struct V_1 * V_4 )
{
return F_1 ( V_4 -> V_3 . V_5 ) ;
}
static struct V_2 *
F_4 ( struct V_2 * V_5 )
{
struct V_1 * V_4 ;
V_4 = F_5 ( sizeof( struct V_1 ) , V_6 ) ;
if ( ! V_4 )
return F_6 ( - V_7 ) ;
V_4 -> V_8 = V_9 ;
F_7 ( & V_4 -> V_10 , 0 ) ;
return & V_4 -> V_3 ;
}
static void F_8 ( struct V_2 * V_3 )
{
F_9 ( F_1 ( V_3 ) ) ;
}
static void F_10 ( struct V_1 * V_4 , int V_11 )
{
F_11 ( F_12 ( - V_11 , & V_4 -> V_10 ) ) ;
}
static void F_13 ( struct V_1 * V_4 , int V_11 )
{
struct V_1 * V_12 ;
for ( V_12 = V_4 ; F_3 ( V_12 ) ; V_12 = F_3 ( V_12 ) )
F_10 ( V_12 , V_11 ) ;
}
static void F_14 ( struct V_1 * V_4 , int V_11 )
{
struct V_1 * V_12 ;
for ( V_12 = V_4 ; F_3 ( V_12 ) ; V_12 = F_3 ( V_12 ) )
F_15 ( V_11 , & V_12 -> V_10 ) ;
}
static int F_16 ( struct V_1 * V_4 , int V_11 )
{
struct V_1 * V_12 , * V_13 ;
for ( V_12 = V_4 ; F_3 ( V_12 ) ; V_12 = F_3 ( V_12 ) ) {
T_1 V_14 = F_17 ( V_11 , & V_12 -> V_10 ) ;
if ( V_14 > V_12 -> V_8 )
goto V_15;
}
return 0 ;
V_15:
for ( V_13 = V_4 ; V_13 != V_12 ; V_13 = F_3 ( V_13 ) )
F_10 ( V_13 , V_11 ) ;
F_10 ( V_12 , V_11 ) ;
return - V_16 ;
}
static int F_18 ( struct V_17 * V_18 )
{
struct V_19 * V_20 ;
struct V_2 * V_21 ;
F_19 (task, dst_css, tset) {
struct V_1 * V_4 = F_1 ( V_21 ) ;
struct V_2 * V_22 ;
struct V_1 * V_23 ;
V_22 = F_20 ( V_20 , V_24 ) ;
V_23 = F_1 ( V_22 ) ;
F_14 ( V_4 , 1 ) ;
F_13 ( V_23 , 1 ) ;
}
return 0 ;
}
static void F_21 ( struct V_17 * V_18 )
{
struct V_19 * V_20 ;
struct V_2 * V_21 ;
F_19 (task, dst_css, tset) {
struct V_1 * V_4 = F_1 ( V_21 ) ;
struct V_2 * V_22 ;
struct V_1 * V_23 ;
V_22 = F_20 ( V_20 , V_24 ) ;
V_23 = F_1 ( V_22 ) ;
F_14 ( V_23 , 1 ) ;
F_13 ( V_4 , 1 ) ;
}
}
static int F_22 ( struct V_19 * V_20 )
{
struct V_2 * V_3 ;
struct V_1 * V_4 ;
V_3 = F_23 ( V_25 , V_24 , true ) ;
V_4 = F_1 ( V_3 ) ;
return F_16 ( V_4 , 1 ) ;
}
static void F_24 ( struct V_19 * V_20 )
{
struct V_2 * V_3 ;
struct V_1 * V_4 ;
V_3 = F_23 ( V_25 , V_24 , true ) ;
V_4 = F_1 ( V_3 ) ;
F_13 ( V_4 , 1 ) ;
}
static void F_25 ( struct V_19 * V_20 )
{
struct V_1 * V_4 = F_1 ( F_20 ( V_20 , V_24 ) ) ;
F_13 ( V_4 , 1 ) ;
}
static T_2 F_26 ( struct V_26 * V_27 , char * V_28 ,
T_3 V_29 , T_4 V_30 )
{
struct V_2 * V_3 = F_27 ( V_27 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_1 V_8 ;
int V_31 ;
V_28 = F_28 ( V_28 ) ;
if ( ! strcmp ( V_28 , V_32 ) ) {
V_8 = V_9 ;
goto V_33;
}
V_31 = F_29 ( V_28 , 0 , & V_8 ) ;
if ( V_31 )
return V_31 ;
if ( V_8 < 0 || V_8 >= V_9 )
return - V_34 ;
V_33:
V_4 -> V_8 = V_8 ;
return V_29 ;
}
static int F_30 ( struct V_35 * V_36 , void * V_37 )
{
struct V_2 * V_3 = F_31 ( V_36 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_1 V_8 = V_4 -> V_8 ;
if ( V_8 >= V_9 )
F_32 ( V_36 , L_1 , V_32 ) ;
else
F_32 ( V_36 , L_2 , V_8 ) ;
return 0 ;
}
static T_5 F_33 ( struct V_2 * V_3 ,
struct V_38 * V_39 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
return F_34 ( & V_4 -> V_10 ) ;
}
