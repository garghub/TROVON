static int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 = V_5 -> V_8 ;
F_2 ( L_1 , V_3 ) ;
F_3 ( V_8 , true ) ;
return 0 ;
}
static void F_4 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 = V_5 -> V_8 ;
F_2 ( L_2 , V_3 ) ;
F_3 ( V_8 , false ) ;
}
static void F_5 ( void )
{
struct V_9 * V_10 ;
V_10 = F_6 ( 1 ) ;
if ( ! V_10 )
return;
V_10 -> V_11 [ 0 ] . V_12 = 0 ;
V_10 -> V_11 [ 0 ] . V_13 = ~ 0 ;
F_7 ( V_10 , L_3 , false ) ;
F_8 ( V_10 ) ;
}
static int F_9 ( struct V_14 * V_15 )
{
struct V_1 * V_2 ;
struct V_4 * V_5 ;
int V_16 ;
V_2 = F_10 ( & V_17 , V_15 ) ;
if ( F_11 ( V_2 ) )
return F_12 ( V_2 ) ;
V_5 = F_13 ( V_15 , sizeof( * V_5 ) , V_18 ) ;
if ( ! V_5 ) {
V_16 = - V_19 ;
goto V_20;
}
V_2 -> V_6 = V_5 ;
F_14 ( V_2 , 1 ) ;
F_15 ( V_2 ) ;
V_16 = F_16 ( V_2 -> V_15 , V_2 ) ;
if ( V_16 ) {
F_17 ( V_2 -> V_15 , L_4 ) ;
goto V_20;
}
V_5 -> V_21 = F_18 ( V_2 ) ;
if ( F_11 ( V_5 -> V_21 ) ) {
F_17 ( V_2 -> V_15 , L_5 ) ;
V_16 = F_12 ( V_5 -> V_21 ) ;
goto V_20;
}
V_5 -> V_22 = F_19 ( V_2 ) ;
if ( ! V_5 -> V_22 ) {
F_17 ( V_2 -> V_15 , L_6 ) ;
V_16 = - V_23 ;
goto V_20;
}
V_2 -> V_24 = true ;
F_5 () ;
V_5 -> V_25 = F_20 ( V_2 ) ;
if ( F_11 ( V_5 -> V_25 ) ) {
F_17 ( V_2 -> V_15 , L_7 ) ;
V_16 = F_12 ( V_5 -> V_25 ) ;
goto V_20;
}
F_21 ( V_2 ) ;
V_16 = F_22 ( V_2 , 0 ) ;
if ( V_16 )
goto V_20;
return 0 ;
V_20:
F_23 ( V_2 ) ;
return V_16 ;
}
static void F_24 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_25 ( V_15 ) ;
F_26 ( V_2 ) ;
F_27 ( V_2 ) ;
F_28 ( V_2 ) ;
F_29 ( V_2 ) ;
F_23 ( V_2 ) ;
}
static bool F_30 ( struct V_26 * V_27 )
{
return F_31 ( V_27 , L_8 ) ||
F_31 ( V_27 , L_9 ) ;
}
static bool F_32 ( struct V_26 * V_27 )
{
return F_31 ( V_27 , L_10 ) ||
F_31 ( V_27 , L_11 ) ;
}
static int F_33 ( struct V_14 * V_15 , void * V_28 )
{
F_2 ( L_12 ,
F_34 ( V_15 -> V_29 ) ,
F_34 ( V_28 ) ) ;
return V_15 -> V_29 == V_28 ;
}
static int F_35 ( struct V_14 * V_15 ,
struct V_30 * * V_31 ,
struct V_26 * V_27 )
{
struct V_26 * V_32 , * V_33 , * V_34 ;
int V_35 = 0 ;
if ( ! F_30 ( V_27 ) &&
! F_36 ( V_27 ) )
return 0 ;
if ( ! F_30 ( V_27 ) ) {
F_2 ( L_13 ,
F_34 ( V_27 ) ) ;
F_37 ( V_15 , V_31 , F_33 , V_27 ) ;
V_35 ++ ;
}
V_32 = F_38 ( V_27 , 1 ) ;
if ( ! V_32 ) {
F_2 ( L_14 ) ;
return V_35 ;
}
F_39 (port, ep) {
V_34 = F_40 ( V_33 ) ;
if ( ! V_34 ) {
F_2 ( L_15 ) ;
F_41 ( V_34 ) ;
continue;
}
if ( F_32 ( V_27 ) ) {
struct V_36 V_37 ;
if ( F_42 ( V_33 , & V_37 ) ) {
F_2 ( L_16 ) ;
continue;
}
if ( ! V_37 . V_38 ) {
F_2 ( L_17 ) ;
continue;
}
}
V_35 += F_35 ( V_15 , V_31 , V_34 ) ;
F_41 ( V_34 ) ;
}
return V_35 ;
}
static int F_43 ( struct V_39 * V_40 )
{
struct V_30 * V_31 = NULL ;
struct V_26 * V_41 = V_40 -> V_15 . V_29 ;
int V_42 , V_35 = 0 ;
for ( V_42 = 0 ; ; V_42 ++ ) {
struct V_26 * V_43 = F_44 ( V_41 ,
L_18 ,
V_42 ) ;
if ( ! V_43 )
break;
V_35 += F_35 ( & V_40 -> V_15 , & V_31 ,
V_43 ) ;
F_41 ( V_43 ) ;
F_2 ( L_19 ,
V_35 , V_42 ) ;
}
if ( V_35 )
return F_45 ( & V_40 -> V_15 ,
& V_44 ,
V_31 ) ;
else
return 0 ;
}
static int F_46 ( struct V_39 * V_40 )
{
return 0 ;
}
