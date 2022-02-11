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
for ( V_12 = V_4 ; V_12 ; V_12 = F_3 ( V_12 ) )
F_10 ( V_12 , V_11 ) ;
}
static void F_14 ( struct V_1 * V_4 , int V_11 )
{
struct V_1 * V_12 ;
for ( V_12 = V_4 ; V_12 ; V_12 = F_3 ( V_12 ) )
F_15 ( V_11 , & V_12 -> V_10 ) ;
}
static int F_16 ( struct V_1 * V_4 , int V_11 )
{
struct V_1 * V_12 , * V_13 ;
for ( V_12 = V_4 ; V_12 ; V_12 = F_3 ( V_12 ) ) {
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
static int F_18 ( struct V_2 * V_3 ,
struct V_17 * V_18 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_19 * V_20 ;
F_19 (task, tset) {
struct V_2 * V_21 ;
struct V_1 * V_22 ;
V_21 = F_20 ( V_20 , V_23 ) ;
V_22 = F_1 ( V_21 ) ;
F_14 ( V_4 , 1 ) ;
F_13 ( V_22 , 1 ) ;
}
return 0 ;
}
static void F_21 ( struct V_2 * V_3 ,
struct V_17 * V_18 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_19 * V_20 ;
F_19 (task, tset) {
struct V_2 * V_21 ;
struct V_1 * V_22 ;
V_21 = F_20 ( V_20 , V_23 ) ;
V_22 = F_1 ( V_21 ) ;
F_14 ( V_22 , 1 ) ;
F_13 ( V_4 , 1 ) ;
}
}
static int F_22 ( struct V_19 * V_20 , void * * V_24 )
{
struct V_2 * V_3 ;
struct V_1 * V_4 ;
int V_25 ;
V_3 = F_23 ( V_26 , V_23 ) ;
V_4 = F_1 ( V_3 ) ;
V_25 = F_16 ( V_4 , 1 ) ;
if ( V_25 )
goto V_27;
* V_24 = V_3 ;
return 0 ;
V_27:
F_24 ( V_3 ) ;
return V_25 ;
}
static void F_25 ( struct V_19 * V_20 , void * V_28 )
{
struct V_2 * V_3 = V_28 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_13 ( V_4 , 1 ) ;
F_24 ( V_3 ) ;
}
static void F_26 ( struct V_19 * V_20 , void * V_28 )
{
struct V_2 * V_3 ;
struct V_2 * V_21 = V_28 ;
struct V_1 * V_4 ;
struct V_1 * V_22 = F_1 ( V_21 ) ;
V_3 = F_23 ( V_20 , V_23 ) ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 != V_22 ) {
F_13 ( V_22 , 1 ) ;
F_14 ( V_4 , 1 ) ;
}
F_24 ( V_3 ) ;
F_24 ( V_21 ) ;
}
static void F_27 ( struct V_2 * V_3 ,
struct V_2 * V_21 ,
struct V_19 * V_20 )
{
struct V_1 * V_4 = F_1 ( V_21 ) ;
F_13 ( V_4 , 1 ) ;
}
static T_2 F_28 ( struct V_29 * V_30 , char * V_31 ,
T_3 V_32 , T_4 V_33 )
{
struct V_2 * V_3 = F_29 ( V_30 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_1 V_8 ;
int V_25 ;
V_31 = F_30 ( V_31 ) ;
if ( ! strcmp ( V_31 , V_34 ) ) {
V_8 = V_9 ;
goto V_35;
}
V_25 = F_31 ( V_31 , 0 , & V_8 ) ;
if ( V_25 )
return V_25 ;
if ( V_8 < 0 || V_8 >= V_9 )
return - V_36 ;
V_35:
V_4 -> V_8 = V_8 ;
return V_32 ;
}
static int F_32 ( struct V_37 * V_38 , void * V_39 )
{
struct V_2 * V_3 = F_33 ( V_38 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_1 V_8 = V_4 -> V_8 ;
if ( V_8 >= V_9 )
F_34 ( V_38 , L_1 , V_34 ) ;
else
F_34 ( V_38 , L_2 , V_8 ) ;
return 0 ;
}
static T_5 F_35 ( struct V_2 * V_3 ,
struct V_40 * V_41 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
return F_36 ( & V_4 -> V_10 ) ;
}
