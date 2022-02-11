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
if ( ! V_2 )
return - V_18 ;
V_16 = F_11 ( V_2 , F_12 ( V_2 -> V_15 ) ) ;
if ( V_16 )
goto V_19;
V_5 = F_13 ( V_15 , sizeof( * V_5 ) , V_20 ) ;
if ( ! V_5 ) {
V_16 = - V_18 ;
goto V_19;
}
V_2 -> V_6 = V_5 ;
F_14 ( V_2 , 1 ) ;
F_15 ( V_2 ) ;
V_16 = F_16 ( V_2 -> V_15 , V_2 ) ;
if ( V_16 ) {
F_17 ( V_2 -> V_15 , L_4 ) ;
goto V_19;
}
V_5 -> V_21 = F_18 ( V_2 ) ;
if ( ! V_5 -> V_21 ) {
F_17 ( V_2 -> V_15 , L_5 ) ;
V_16 = - V_22 ;
goto V_19;
}
V_5 -> V_23 = F_19 ( V_2 ) ;
if ( ! V_5 -> V_23 ) {
F_17 ( V_2 -> V_15 , L_6 ) ;
V_16 = - V_22 ;
goto V_19;
}
V_2 -> V_24 = true ;
F_5 () ;
V_5 -> V_25 = F_20 ( V_2 ) ;
if ( F_21 ( V_5 -> V_25 ) ) {
F_17 ( V_2 -> V_15 , L_7 ) ;
V_16 = F_22 ( V_5 -> V_25 ) ;
goto V_19;
}
F_23 ( V_2 ) ;
V_16 = F_24 ( V_2 , 0 ) ;
if ( V_16 )
goto V_19;
V_16 = F_25 ( V_2 ) ;
if ( V_16 )
goto V_26;
return 0 ;
V_26:
F_26 ( V_2 ) ;
V_19:
F_27 ( V_2 ) ;
return V_16 ;
}
static void F_28 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_29 ( V_15 ) ;
F_30 ( V_2 ) ;
F_26 ( V_2 ) ;
F_31 ( V_2 ) ;
F_32 ( V_2 ) ;
F_33 ( V_2 ) ;
F_27 ( V_2 ) ;
}
static bool F_34 ( struct V_27 * V_28 )
{
return F_35 ( V_28 ,
L_8 ) ;
}
static bool F_36 ( struct V_27 * V_28 )
{
return F_35 ( V_28 , L_9 ) ;
}
static int F_37 ( struct V_14 * V_15 , void * V_29 )
{
F_2 ( L_10 ,
F_38 ( V_15 -> V_30 ) ,
F_38 ( V_29 ) ) ;
return V_15 -> V_30 == V_29 ;
}
static int F_39 ( struct V_14 * V_15 ,
struct V_31 * * V_32 ,
struct V_27 * V_28 )
{
struct V_27 * V_33 , * V_34 , * V_35 ;
int V_36 = 0 ;
if ( ! F_34 ( V_28 ) &&
! F_40 ( V_28 ) )
return 0 ;
if ( ! F_34 ( V_28 ) ) {
F_2 ( L_11 ,
F_38 ( V_28 ) ) ;
F_41 ( V_15 , V_32 , F_37 , V_28 ) ;
V_36 ++ ;
}
V_33 = F_42 ( V_28 , 1 ) ;
if ( ! V_33 ) {
F_2 ( L_12 ) ;
return V_36 ;
}
F_43 (port, ep) {
V_35 = F_44 ( V_34 ) ;
if ( ! V_35 ) {
F_2 ( L_13 ) ;
F_45 ( V_35 ) ;
continue;
}
if ( F_36 ( V_28 ) ) {
struct V_37 V_38 ;
if ( F_46 ( V_34 , & V_38 ) ) {
F_2 ( L_14 ) ;
continue;
}
if ( ! V_38 . V_39 ) {
F_2 ( L_15 ) ;
continue;
}
}
V_36 += F_39 ( V_15 , V_32 , V_35 ) ;
F_45 ( V_35 ) ;
}
return V_36 ;
}
static int F_47 ( struct V_40 * V_41 )
{
struct V_31 * V_32 = NULL ;
struct V_27 * V_42 = V_41 -> V_15 . V_30 ;
int V_43 , V_36 = 0 ;
for ( V_43 = 0 ; ; V_43 ++ ) {
struct V_27 * V_44 = F_48 ( V_42 ,
L_16 ,
V_43 ) ;
if ( ! V_44 )
break;
V_36 += F_39 ( & V_41 -> V_15 , & V_32 ,
V_44 ) ;
F_45 ( V_44 ) ;
F_2 ( L_17 ,
V_36 , V_43 ) ;
}
if ( V_36 )
return F_49 ( & V_41 -> V_15 ,
& V_45 ,
V_32 ) ;
else
return 0 ;
}
static int F_50 ( struct V_40 * V_41 )
{
return 0 ;
}
