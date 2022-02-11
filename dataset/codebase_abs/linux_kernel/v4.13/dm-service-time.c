static struct V_1 * F_1 ( void )
{
struct V_1 * V_2 = F_2 ( sizeof( * V_2 ) , V_3 ) ;
if ( V_2 ) {
F_3 ( & V_2 -> V_4 ) ;
F_3 ( & V_2 -> V_5 ) ;
F_4 ( & V_2 -> V_6 ) ;
}
return V_2 ;
}
static int F_5 ( struct V_7 * V_8 , unsigned V_9 , char * * V_10 )
{
struct V_1 * V_2 = F_1 () ;
if ( ! V_2 )
return - V_11 ;
V_8 -> V_12 = V_2 ;
return 0 ;
}
static void F_6 ( struct V_13 * V_14 )
{
struct V_15 * V_16 , * V_17 ;
F_7 (pi, next, paths, list) {
F_8 ( & V_16 -> V_18 ) ;
F_9 ( V_16 ) ;
}
}
static void F_10 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_12 ;
F_6 ( & V_2 -> V_4 ) ;
F_6 ( & V_2 -> V_5 ) ;
F_9 ( V_2 ) ;
V_8 -> V_12 = NULL ;
}
static int F_11 ( struct V_7 * V_8 , struct V_19 * V_20 ,
T_1 type , char * V_21 , unsigned V_22 )
{
unsigned V_23 = 0 ;
struct V_15 * V_16 ;
if ( ! V_20 )
F_12 ( L_1 ) ;
else {
V_16 = V_20 -> V_24 ;
switch ( type ) {
case V_25 :
F_12 ( L_2 , F_13 ( & V_16 -> V_26 ) ,
V_16 -> V_27 ) ;
break;
case V_28 :
F_12 ( L_3 , V_16 -> V_29 ,
V_16 -> V_27 ) ;
break;
}
}
return V_23 ;
}
static int F_14 ( struct V_7 * V_8 , struct V_19 * V_20 ,
int V_9 , char * * V_10 , char * * error )
{
struct V_1 * V_2 = V_8 -> V_12 ;
struct V_15 * V_16 ;
unsigned V_29 = V_30 ;
unsigned V_27 = 1 ;
char V_31 ;
unsigned long V_32 ;
if ( V_9 > 2 ) {
* error = L_4 ;
return - V_33 ;
}
if ( V_9 && ( sscanf ( V_10 [ 0 ] , L_5 , & V_29 , & V_31 ) != 1 ) ) {
* error = L_6 ;
return - V_33 ;
}
if ( V_29 > 1 ) {
F_15 ( L_7 ) ;
V_29 = 1 ;
}
if ( ( V_9 == 2 ) &&
( sscanf ( V_10 [ 1 ] , L_5 , & V_27 , & V_31 ) != 1 ||
V_27 > V_34 ) ) {
* error = L_8 ;
return - V_33 ;
}
V_16 = F_2 ( sizeof( * V_16 ) , V_3 ) ;
if ( ! V_16 ) {
* error = L_9 ;
return - V_11 ;
}
V_16 -> V_20 = V_20 ;
V_16 -> V_29 = V_29 ;
V_16 -> V_27 = V_27 ;
F_16 ( & V_16 -> V_26 , 0 ) ;
V_20 -> V_24 = V_16 ;
F_17 ( & V_2 -> V_6 , V_32 ) ;
F_18 ( & V_16 -> V_18 , & V_2 -> V_4 ) ;
F_19 ( & V_2 -> V_6 , V_32 ) ;
return 0 ;
}
static void F_20 ( struct V_7 * V_8 , struct V_19 * V_20 )
{
struct V_1 * V_2 = V_8 -> V_12 ;
struct V_15 * V_16 = V_20 -> V_24 ;
unsigned long V_32 ;
F_17 ( & V_2 -> V_6 , V_32 ) ;
F_21 ( & V_16 -> V_18 , & V_2 -> V_5 ) ;
F_19 ( & V_2 -> V_6 , V_32 ) ;
}
static int F_22 ( struct V_7 * V_8 , struct V_19 * V_20 )
{
struct V_1 * V_2 = V_8 -> V_12 ;
struct V_15 * V_16 = V_20 -> V_24 ;
unsigned long V_32 ;
F_17 ( & V_2 -> V_6 , V_32 ) ;
F_23 ( & V_16 -> V_18 , & V_2 -> V_4 ) ;
F_19 ( & V_2 -> V_6 , V_32 ) ;
return 0 ;
}
static int F_24 ( struct V_15 * V_35 , struct V_15 * V_36 ,
T_2 V_37 )
{
T_2 V_38 , V_39 , V_40 , V_41 ;
V_38 = F_13 ( & V_35 -> V_26 ) ;
V_39 = F_13 ( & V_36 -> V_26 ) ;
if ( V_35 -> V_27 == V_36 -> V_27 )
return V_38 - V_39 ;
if ( V_38 == V_39 ||
! V_35 -> V_27 || ! V_36 -> V_27 )
return V_36 -> V_27 - V_35 -> V_27 ;
V_38 += V_37 ;
V_39 += V_37 ;
if ( F_25 ( V_38 >= V_42 ||
V_39 >= V_42 ) ) {
V_38 >>= V_43 ;
V_39 >>= V_43 ;
}
V_40 = V_38 * V_36 -> V_27 ;
V_41 = V_39 * V_35 -> V_27 ;
if ( V_40 != V_41 )
return V_40 - V_41 ;
return V_36 -> V_27 - V_35 -> V_27 ;
}
static struct V_19 * F_26 ( struct V_7 * V_8 , T_2 V_44 )
{
struct V_1 * V_2 = V_8 -> V_12 ;
struct V_15 * V_16 = NULL , * V_45 = NULL ;
struct V_19 * V_46 = NULL ;
unsigned long V_32 ;
F_17 ( & V_2 -> V_6 , V_32 ) ;
if ( F_27 ( & V_2 -> V_4 ) )
goto V_47;
F_23 ( V_2 -> V_4 . V_17 , & V_2 -> V_4 ) ;
F_28 (pi, &s->valid_paths, list)
if ( ! V_45 || ( F_24 ( V_16 , V_45 , V_44 ) < 0 ) )
V_45 = V_16 ;
if ( ! V_45 )
goto V_47;
V_46 = V_45 -> V_20 ;
V_47:
F_19 ( & V_2 -> V_6 , V_32 ) ;
return V_46 ;
}
static int F_29 ( struct V_7 * V_8 , struct V_19 * V_20 ,
T_2 V_44 )
{
struct V_15 * V_16 = V_20 -> V_24 ;
F_30 ( V_44 , & V_16 -> V_26 ) ;
return 0 ;
}
static int F_31 ( struct V_7 * V_8 , struct V_19 * V_20 ,
T_2 V_44 )
{
struct V_15 * V_16 = V_20 -> V_24 ;
F_32 ( V_44 , & V_16 -> V_26 ) ;
return 0 ;
}
static int T_3 F_33 ( void )
{
int V_48 = F_34 ( & V_49 ) ;
if ( V_48 < 0 )
F_35 ( L_10 , V_48 ) ;
F_36 ( L_11 V_50 L_12 ) ;
return V_48 ;
}
static void T_4 F_37 ( void )
{
int V_48 = F_38 ( & V_49 ) ;
if ( V_48 < 0 )
F_35 ( L_13 , V_48 ) ;
}
