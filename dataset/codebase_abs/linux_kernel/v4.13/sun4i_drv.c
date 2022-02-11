static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_2 ( V_4 -> V_6 ) ;
}
static void F_3 ( void )
{
struct V_7 * V_8 ;
V_8 = F_4 ( 1 ) ;
if ( ! V_8 )
return;
V_8 -> V_9 [ 0 ] . V_10 = 0 ;
V_8 -> V_9 [ 0 ] . V_11 = ~ 0 ;
F_5 ( V_8 , L_1 , false ) ;
F_6 ( V_8 ) ;
}
static int F_7 ( struct V_12 * V_2 )
{
struct V_1 * V_13 ;
struct V_3 * V_4 ;
int V_14 ;
V_13 = F_8 ( & V_15 , V_2 ) ;
if ( F_9 ( V_13 ) )
return F_10 ( V_13 ) ;
V_4 = F_11 ( V_2 , sizeof( * V_4 ) , V_16 ) ;
if ( ! V_4 ) {
V_14 = - V_17 ;
goto V_18;
}
V_13 -> V_5 = V_4 ;
F_12 ( & V_4 -> V_19 ) ;
F_12 ( & V_4 -> V_20 ) ;
V_14 = F_13 ( V_2 ) ;
if ( V_14 && V_14 != - V_21 ) {
F_14 ( V_13 -> V_2 , L_2 ) ;
goto V_18;
}
V_14 = F_15 ( V_13 , 1 ) ;
if ( V_14 )
goto V_22;
F_16 ( V_13 ) ;
V_14 = F_17 ( V_13 -> V_2 , V_13 ) ;
if ( V_14 ) {
F_14 ( V_13 -> V_2 , L_3 ) ;
goto V_23;
}
V_13 -> V_24 = true ;
F_3 () ;
V_4 -> V_6 = F_18 ( V_13 ) ;
if ( F_9 ( V_4 -> V_6 ) ) {
F_14 ( V_13 -> V_2 , L_4 ) ;
V_14 = F_10 ( V_4 -> V_6 ) ;
goto V_23;
}
F_19 ( V_13 ) ;
V_14 = F_20 ( V_13 , 0 ) ;
if ( V_14 )
goto V_25;
return 0 ;
V_25:
F_21 ( V_13 ) ;
F_22 ( V_13 ) ;
V_23:
F_23 ( V_13 ) ;
V_22:
F_24 ( V_2 ) ;
V_18:
F_25 ( V_13 ) ;
return V_14 ;
}
static void F_26 ( struct V_12 * V_2 )
{
struct V_1 * V_13 = F_27 ( V_2 ) ;
F_28 ( V_13 ) ;
F_21 ( V_13 ) ;
F_22 ( V_13 ) ;
F_23 ( V_13 ) ;
F_24 ( V_2 ) ;
F_25 ( V_13 ) ;
}
static bool F_29 ( struct V_26 * V_27 )
{
return F_30 ( V_27 , L_5 ) ;
}
static bool F_31 ( struct V_26 * V_27 )
{
return F_30 ( V_27 , L_6 ) ||
F_30 ( V_27 , L_7 ) ||
F_30 ( V_27 , L_8 ) ;
}
static bool F_32 ( struct V_26 * V_27 )
{
return F_30 ( V_27 , L_9 ) ||
F_30 ( V_27 , L_10 ) ||
F_30 ( V_27 , L_11 ) ||
F_30 ( V_27 , L_12 ) ||
F_30 ( V_27 , L_13 ) ;
}
static int F_33 ( struct V_12 * V_2 , void * V_28 )
{
F_34 ( L_14 ,
F_35 ( V_2 -> V_29 ) ,
F_35 ( V_28 ) ) ;
return V_2 -> V_29 == V_28 ;
}
static int F_36 ( struct V_12 * V_2 ,
struct V_30 * * V_31 ,
struct V_26 * V_27 )
{
struct V_26 * V_32 , * V_33 , * V_34 ;
int V_35 = 0 ;
if ( ! F_31 ( V_27 ) &&
! F_37 ( V_27 ) )
return 0 ;
if ( F_29 ( V_27 ) )
return 0 ;
if ( ! F_31 ( V_27 ) ) {
F_34 ( L_15 ,
F_35 ( V_27 ) ) ;
F_38 ( V_2 , V_31 , F_33 , V_27 ) ;
V_35 ++ ;
}
V_32 = F_39 ( V_27 , 1 ) ;
if ( ! V_32 ) {
F_34 ( L_16 ) ;
return V_35 ;
}
F_40 (port, ep) {
V_34 = F_41 ( V_33 ) ;
if ( ! V_34 ) {
F_34 ( L_17 ) ;
F_42 ( V_34 ) ;
continue;
}
if ( F_32 ( V_27 ) ) {
struct V_36 V_37 ;
if ( F_43 ( V_33 , & V_37 ) ) {
F_34 ( L_18 ) ;
continue;
}
if ( ! V_37 . V_38 ) {
F_34 ( L_19 ) ;
continue;
}
}
V_35 += F_36 ( V_2 , V_31 , V_34 ) ;
F_42 ( V_34 ) ;
}
return V_35 ;
}
static int F_44 ( struct V_39 * V_40 )
{
struct V_30 * V_31 = NULL ;
struct V_26 * V_41 = V_40 -> V_2 . V_29 ;
int V_42 , V_35 = 0 ;
for ( V_42 = 0 ; ; V_42 ++ ) {
struct V_26 * V_43 = F_45 ( V_41 ,
L_20 ,
V_42 ) ;
if ( ! V_43 )
break;
V_35 += F_36 ( & V_40 -> V_2 , & V_31 ,
V_43 ) ;
F_42 ( V_43 ) ;
F_34 ( L_21 ,
V_35 , V_42 ) ;
}
if ( V_35 )
return F_46 ( & V_40 -> V_2 ,
& V_44 ,
V_31 ) ;
else
return 0 ;
}
static int F_47 ( struct V_39 * V_40 )
{
return 0 ;
}
