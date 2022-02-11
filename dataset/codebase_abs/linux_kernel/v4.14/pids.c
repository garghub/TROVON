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
F_7 ( & V_4 -> V_11 , 0 ) ;
return & V_4 -> V_3 ;
}
static void F_8 ( struct V_2 * V_3 )
{
F_9 ( F_1 ( V_3 ) ) ;
}
static void F_10 ( struct V_1 * V_4 , int V_12 )
{
F_11 ( F_12 ( - V_12 , & V_4 -> V_10 ) ) ;
}
static void F_13 ( struct V_1 * V_4 , int V_12 )
{
struct V_1 * V_13 ;
for ( V_13 = V_4 ; F_3 ( V_13 ) ; V_13 = F_3 ( V_13 ) )
F_10 ( V_13 , V_12 ) ;
}
static void F_14 ( struct V_1 * V_4 , int V_12 )
{
struct V_1 * V_13 ;
for ( V_13 = V_4 ; F_3 ( V_13 ) ; V_13 = F_3 ( V_13 ) )
F_15 ( V_12 , & V_13 -> V_10 ) ;
}
static int F_16 ( struct V_1 * V_4 , int V_12 )
{
struct V_1 * V_13 , * V_14 ;
for ( V_13 = V_4 ; F_3 ( V_13 ) ; V_13 = F_3 ( V_13 ) ) {
T_1 V_15 = F_17 ( V_12 , & V_13 -> V_10 ) ;
if ( V_15 > V_13 -> V_8 )
goto V_16;
}
return 0 ;
V_16:
for ( V_14 = V_4 ; V_14 != V_13 ; V_14 = F_3 ( V_14 ) )
F_10 ( V_14 , V_12 ) ;
F_10 ( V_13 , V_12 ) ;
return - V_17 ;
}
static int F_18 ( struct V_18 * V_19 )
{
struct V_20 * V_21 ;
struct V_2 * V_22 ;
F_19 (task, dst_css, tset) {
struct V_1 * V_4 = F_1 ( V_22 ) ;
struct V_2 * V_23 ;
struct V_1 * V_24 ;
V_23 = F_20 ( V_21 , V_25 ) ;
V_24 = F_1 ( V_23 ) ;
F_14 ( V_4 , 1 ) ;
F_13 ( V_24 , 1 ) ;
}
return 0 ;
}
static void F_21 ( struct V_18 * V_19 )
{
struct V_20 * V_21 ;
struct V_2 * V_22 ;
F_19 (task, dst_css, tset) {
struct V_1 * V_4 = F_1 ( V_22 ) ;
struct V_2 * V_23 ;
struct V_1 * V_24 ;
V_23 = F_20 ( V_21 , V_25 ) ;
V_24 = F_1 ( V_23 ) ;
F_14 ( V_24 , 1 ) ;
F_13 ( V_4 , 1 ) ;
}
}
static int F_22 ( struct V_20 * V_21 )
{
struct V_2 * V_3 ;
struct V_1 * V_4 ;
int V_26 ;
V_3 = F_23 ( V_27 , V_25 , true ) ;
V_4 = F_1 ( V_3 ) ;
V_26 = F_16 ( V_4 , 1 ) ;
if ( V_26 ) {
if ( F_24 ( & V_4 -> V_11 ) == 1 ) {
F_25 ( L_1 ) ;
F_26 ( V_3 -> V_28 ) ;
F_27 ( L_2 ) ;
}
F_28 ( & V_4 -> V_29 ) ;
}
return V_26 ;
}
static void F_29 ( struct V_20 * V_21 )
{
struct V_2 * V_3 ;
struct V_1 * V_4 ;
V_3 = F_23 ( V_27 , V_25 , true ) ;
V_4 = F_1 ( V_3 ) ;
F_13 ( V_4 , 1 ) ;
}
static void F_30 ( struct V_20 * V_21 )
{
struct V_1 * V_4 = F_1 ( F_20 ( V_21 , V_25 ) ) ;
F_13 ( V_4 , 1 ) ;
}
static T_2 F_31 ( struct V_30 * V_31 , char * V_32 ,
T_3 V_33 , T_4 V_34 )
{
struct V_2 * V_3 = F_32 ( V_31 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_1 V_8 ;
int V_26 ;
V_32 = F_33 ( V_32 ) ;
if ( ! strcmp ( V_32 , V_35 ) ) {
V_8 = V_9 ;
goto V_36;
}
V_26 = F_34 ( V_32 , 0 , & V_8 ) ;
if ( V_26 )
return V_26 ;
if ( V_8 < 0 || V_8 >= V_9 )
return - V_37 ;
V_36:
V_4 -> V_8 = V_8 ;
return V_33 ;
}
static int F_35 ( struct V_38 * V_39 , void * V_40 )
{
struct V_2 * V_3 = F_36 ( V_39 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_1 V_8 = V_4 -> V_8 ;
if ( V_8 >= V_9 )
F_37 ( V_39 , L_3 , V_35 ) ;
else
F_37 ( V_39 , L_4 , V_8 ) ;
return 0 ;
}
static T_5 F_38 ( struct V_2 * V_3 ,
struct V_41 * V_42 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
return F_39 ( & V_4 -> V_10 ) ;
}
static int F_40 ( struct V_38 * V_39 , void * V_40 )
{
struct V_1 * V_4 = F_1 ( F_36 ( V_39 ) ) ;
F_37 ( V_39 , L_5 , ( T_5 ) F_39 ( & V_4 -> V_11 ) ) ;
return 0 ;
}
