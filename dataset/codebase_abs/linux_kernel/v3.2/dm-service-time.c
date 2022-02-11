static struct V_1 * F_1 ( void )
{
struct V_1 * V_2 = F_2 ( sizeof( * V_2 ) , V_3 ) ;
if ( V_2 ) {
F_3 ( & V_2 -> V_4 ) ;
F_3 ( & V_2 -> V_5 ) ;
}
return V_2 ;
}
static int F_4 ( struct V_6 * V_7 , unsigned V_8 , char * * V_9 )
{
struct V_1 * V_2 = F_1 () ;
if ( ! V_2 )
return - V_10 ;
V_7 -> V_11 = V_2 ;
return 0 ;
}
static void F_5 ( struct V_12 * V_13 )
{
struct V_14 * V_15 , * V_16 ;
F_6 (pi, next, paths, list) {
F_7 ( & V_15 -> V_17 ) ;
F_8 ( V_15 ) ;
}
}
static void F_9 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_11 ;
F_5 ( & V_2 -> V_4 ) ;
F_5 ( & V_2 -> V_5 ) ;
F_8 ( V_2 ) ;
V_7 -> V_11 = NULL ;
}
static int F_10 ( struct V_6 * V_7 , struct V_18 * V_19 ,
T_1 type , char * V_20 , unsigned V_21 )
{
unsigned V_22 = 0 ;
struct V_14 * V_15 ;
if ( ! V_19 )
F_11 ( L_1 ) ;
else {
V_15 = V_19 -> V_23 ;
switch ( type ) {
case V_24 :
F_11 ( L_2 , F_12 ( & V_15 -> V_25 ) ,
V_15 -> V_26 ) ;
break;
case V_27 :
F_11 ( L_3 , V_15 -> V_28 ,
V_15 -> V_26 ) ;
break;
}
}
return V_22 ;
}
static int F_13 ( struct V_6 * V_7 , struct V_18 * V_19 ,
int V_8 , char * * V_9 , char * * error )
{
struct V_1 * V_2 = V_7 -> V_11 ;
struct V_14 * V_15 ;
unsigned V_28 = V_29 ;
unsigned V_26 = 1 ;
if ( V_8 > 2 ) {
* error = L_4 ;
return - V_30 ;
}
if ( V_8 && ( sscanf ( V_9 [ 0 ] , L_5 , & V_28 ) != 1 ) ) {
* error = L_6 ;
return - V_30 ;
}
if ( ( V_8 == 2 ) &&
( sscanf ( V_9 [ 1 ] , L_5 , & V_26 ) != 1 ||
V_26 > V_31 ) ) {
* error = L_7 ;
return - V_30 ;
}
V_15 = F_2 ( sizeof( * V_15 ) , V_3 ) ;
if ( ! V_15 ) {
* error = L_8 ;
return - V_10 ;
}
V_15 -> V_19 = V_19 ;
V_15 -> V_28 = V_28 ;
V_15 -> V_26 = V_26 ;
F_14 ( & V_15 -> V_25 , 0 ) ;
V_19 -> V_23 = V_15 ;
F_15 ( & V_15 -> V_17 , & V_2 -> V_4 ) ;
return 0 ;
}
static void F_16 ( struct V_6 * V_7 , struct V_18 * V_19 )
{
struct V_1 * V_2 = V_7 -> V_11 ;
struct V_14 * V_15 = V_19 -> V_23 ;
F_17 ( & V_15 -> V_17 , & V_2 -> V_5 ) ;
}
static int F_18 ( struct V_6 * V_7 , struct V_18 * V_19 )
{
struct V_1 * V_2 = V_7 -> V_11 ;
struct V_14 * V_15 = V_19 -> V_23 ;
F_19 ( & V_15 -> V_17 , & V_2 -> V_4 ) ;
return 0 ;
}
static int F_20 ( struct V_14 * V_32 , struct V_14 * V_33 ,
T_2 V_34 )
{
T_2 V_35 , V_36 , V_37 , V_38 ;
V_35 = F_12 ( & V_32 -> V_25 ) ;
V_36 = F_12 ( & V_33 -> V_25 ) ;
if ( V_32 -> V_26 == V_33 -> V_26 )
return V_35 - V_36 ;
if ( V_35 == V_36 ||
! V_32 -> V_26 || ! V_33 -> V_26 )
return V_33 -> V_26 - V_32 -> V_26 ;
V_35 += V_34 ;
V_36 += V_34 ;
if ( F_21 ( V_35 >= V_39 ||
V_36 >= V_39 ) ) {
V_35 >>= V_40 ;
V_36 >>= V_40 ;
}
V_37 = V_35 * V_33 -> V_26 ;
V_38 = V_36 * V_32 -> V_26 ;
if ( V_37 != V_38 )
return V_37 - V_38 ;
return V_33 -> V_26 - V_32 -> V_26 ;
}
static struct V_18 * F_22 ( struct V_6 * V_7 ,
unsigned * V_28 , T_2 V_41 )
{
struct V_1 * V_2 = V_7 -> V_11 ;
struct V_14 * V_15 = NULL , * V_42 = NULL ;
if ( F_23 ( & V_2 -> V_4 ) )
return NULL ;
F_19 ( V_2 -> V_4 . V_16 , & V_2 -> V_4 ) ;
F_24 (pi, &s->valid_paths, list)
if ( ! V_42 || ( F_20 ( V_15 , V_42 , V_41 ) < 0 ) )
V_42 = V_15 ;
if ( ! V_42 )
return NULL ;
* V_28 = V_42 -> V_28 ;
return V_42 -> V_19 ;
}
static int F_25 ( struct V_6 * V_7 , struct V_18 * V_19 ,
T_2 V_41 )
{
struct V_14 * V_15 = V_19 -> V_23 ;
F_26 ( V_41 , & V_15 -> V_25 ) ;
return 0 ;
}
static int F_27 ( struct V_6 * V_7 , struct V_18 * V_19 ,
T_2 V_41 )
{
struct V_14 * V_15 = V_19 -> V_23 ;
F_28 ( V_41 , & V_15 -> V_25 ) ;
return 0 ;
}
static int T_3 F_29 ( void )
{
int V_43 = F_30 ( & V_44 ) ;
if ( V_43 < 0 )
F_31 ( L_9 , V_43 ) ;
F_32 ( L_10 V_45 L_11 ) ;
return V_43 ;
}
static void T_4 F_33 ( void )
{
int V_43 = F_34 ( & V_44 ) ;
if ( V_43 < 0 )
F_31 ( L_12 , V_43 ) ;
}
