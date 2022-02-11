static void F_1 ( void )
{
struct V_1 * V_2 ;
V_2 = F_2 ( 1 ) ;
if ( ! V_2 )
return;
V_2 -> V_3 [ 0 ] . V_4 = 0 ;
V_2 -> V_3 [ 0 ] . V_5 = ~ 0 ;
F_3 ( V_2 , L_1 , false ) ;
F_4 ( V_2 ) ;
}
static int F_5 ( struct V_6 * V_7 )
{
struct V_8 * V_9 ;
struct V_10 * V_11 ;
int V_12 ;
V_9 = F_6 ( & V_13 , V_7 ) ;
if ( F_7 ( V_9 ) )
return F_8 ( V_9 ) ;
V_11 = F_9 ( V_7 , sizeof( * V_11 ) , V_14 ) ;
if ( ! V_11 ) {
V_12 = - V_15 ;
goto V_16;
}
V_9 -> V_17 = V_11 ;
V_12 = F_10 ( V_7 ) ;
if ( V_12 && V_12 != - V_18 ) {
F_11 ( V_9 -> V_7 , L_2 ) ;
goto V_16;
}
V_12 = F_12 ( V_9 , 1 ) ;
if ( V_12 )
goto V_19;
F_13 ( V_9 ) ;
V_12 = F_14 ( V_9 -> V_7 , V_9 ) ;
if ( V_12 ) {
F_11 ( V_9 -> V_7 , L_3 ) ;
goto V_20;
}
V_9 -> V_21 = true ;
F_1 () ;
V_11 -> V_22 = F_15 ( V_9 ) ;
if ( F_7 ( V_11 -> V_22 ) ) {
F_11 ( V_9 -> V_7 , L_4 ) ;
V_12 = F_8 ( V_11 -> V_22 ) ;
goto V_20;
}
F_16 ( V_9 ) ;
V_12 = F_17 ( V_9 , 0 ) ;
if ( V_12 )
goto V_23;
return 0 ;
V_23:
F_18 ( V_9 ) ;
F_19 ( V_9 ) ;
V_20:
F_20 ( V_9 ) ;
F_21 ( V_9 ) ;
V_19:
F_22 ( V_7 ) ;
V_16:
F_23 ( V_9 ) ;
return V_12 ;
}
static void F_24 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = F_25 ( V_7 ) ;
F_26 ( V_9 ) ;
F_18 ( V_9 ) ;
F_19 ( V_9 ) ;
F_20 ( V_9 ) ;
F_21 ( V_9 ) ;
F_22 ( V_7 ) ;
F_23 ( V_9 ) ;
}
static bool F_27 ( struct V_24 * V_25 )
{
return F_28 ( V_25 , L_5 ) ||
F_28 ( V_25 , L_6 ) ||
F_28 ( V_25 , L_7 ) ;
}
static bool F_29 ( struct V_24 * V_25 )
{
return F_28 ( V_25 , L_8 ) ||
F_28 ( V_25 , L_9 ) ||
F_28 ( V_25 , L_10 ) ||
F_28 ( V_25 , L_11 ) ;
}
static int F_30 ( struct V_6 * V_7 , void * V_26 )
{
F_31 ( L_12 ,
F_32 ( V_7 -> V_27 ) ,
F_32 ( V_26 ) ) ;
return V_7 -> V_27 == V_26 ;
}
static int F_33 ( struct V_6 * V_7 ,
struct V_28 * * V_29 ,
struct V_24 * V_25 )
{
struct V_24 * V_30 , * V_31 , * V_32 ;
int V_33 = 0 ;
if ( ! F_27 ( V_25 ) &&
! F_34 ( V_25 ) )
return 0 ;
if ( ! F_27 ( V_25 ) ) {
F_31 ( L_13 ,
F_32 ( V_25 ) ) ;
F_35 ( V_7 , V_29 , F_30 , V_25 ) ;
V_33 ++ ;
}
V_30 = F_36 ( V_25 , 1 ) ;
if ( ! V_30 ) {
F_31 ( L_14 ) ;
return V_33 ;
}
F_37 (port, ep) {
V_32 = F_38 ( V_31 ) ;
if ( ! V_32 ) {
F_31 ( L_15 ) ;
F_39 ( V_32 ) ;
continue;
}
if ( F_29 ( V_25 ) ) {
struct V_34 V_35 ;
if ( F_40 ( V_31 , & V_35 ) ) {
F_31 ( L_16 ) ;
continue;
}
if ( ! V_35 . V_36 ) {
F_31 ( L_17 ) ;
continue;
}
}
V_33 += F_33 ( V_7 , V_29 , V_32 ) ;
F_39 ( V_32 ) ;
}
return V_33 ;
}
static int F_41 ( struct V_37 * V_38 )
{
struct V_28 * V_29 = NULL ;
struct V_24 * V_39 = V_38 -> V_7 . V_27 ;
int V_40 , V_33 = 0 ;
for ( V_40 = 0 ; ; V_40 ++ ) {
struct V_24 * V_41 = F_42 ( V_39 ,
L_18 ,
V_40 ) ;
if ( ! V_41 )
break;
V_33 += F_33 ( & V_38 -> V_7 , & V_29 ,
V_41 ) ;
F_39 ( V_41 ) ;
F_31 ( L_19 ,
V_33 , V_40 ) ;
}
if ( V_33 )
return F_43 ( & V_38 -> V_7 ,
& V_42 ,
V_29 ) ;
else
return 0 ;
}
static int F_44 ( struct V_37 * V_38 )
{
return 0 ;
}
