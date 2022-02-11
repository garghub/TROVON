static int F_1 ( struct V_1 * V_2 , unsigned long V_3 ,
void * V_4 )
{
struct V_5 V_6 = { . V_7 = V_8 } ;
int V_9 ;
V_3 = ( V_3 == V_10 ) ? V_11 : V_3 ;
F_2 ( & V_12 -> V_13 , L_1 ,
V_14 , __LINE__ , V_3 ) ;
V_6 . V_15 = V_3 ;
V_9 = F_3 ( V_16 , & V_6 , sizeof( V_6 ) , V_17 ) ;
if ( V_9 < 0 )
F_4 ( & V_12 -> V_13 , L_2 ,
V_14 , __LINE__ , V_9 ) ;
return V_18 ;
}
static void F_5 ( struct V_5 * V_6 )
{
int V_9 = F_6 ( & V_6 -> V_19 ) ;
if ( V_9 )
F_4 ( & V_12 -> V_13 , L_3 ,
V_14 , __LINE__ , V_9 ) ;
}
static void F_7 ( void )
{
struct V_5 V_6 ;
int V_9 ;
while ( 1 ) {
V_9 = F_8 ( V_16 , & V_6 , sizeof( V_6 ) , 0 ) ;
if ( ! V_9 ) {
return;
} else if ( V_9 < 0 ) {
F_4 ( & V_12 -> V_13 , L_4 ,
V_14 , __LINE__ , V_9 ) ;
return;
}
F_9 ( & V_12 -> V_13 , L_5 ,
V_14 , __LINE__ , V_9 , V_6 . V_7 ) ;
switch ( V_6 . V_7 ) {
case V_20 :
F_5 ( & V_6 ) ;
break;
case V_21 :
F_10 ( true ) ;
break;
default:
F_4 ( & V_12 -> V_13 , L_6 ,
V_14 , __LINE__ , V_6 . V_7 ) ;
break;
}
}
}
static int F_11 ( void )
{
struct V_22 V_23 ;
int V_24 , V_9 ;
V_16 = F_12 () ;
if ( ! V_16 ) {
F_4 ( & V_12 -> V_13 , L_7 ,
V_14 , __LINE__ ) ;
return - V_25 ;
}
V_23 . V_26 = 0 ;
V_23 . V_27 = V_28 ;
for ( V_24 = 0 ; V_24 < V_29 ; V_24 ++ ) {
V_9 = F_13 ( V_16 , & V_23 ) ;
if ( V_9 < 0 )
F_14 ( 1000 ) ;
else
break;
}
if ( V_9 < 0 ) {
F_4 ( & V_12 -> V_13 , L_8 ,
V_14 , __LINE__ , V_9 ) ;
F_15 ( V_16 ) ;
V_16 = NULL ;
}
return V_9 < 0 ? V_9 : 0 ;
}
static void F_16 ( void )
{
if ( V_16 ) {
F_15 ( V_16 ) ;
V_16 = NULL ;
}
}
static int F_17 ( void * V_30 )
{
struct V_5 V_6 = { . V_7 = V_31 } ;
struct V_32 V_33 ;
int V_9 ;
F_18 ( V_34 ) ;
while ( ! F_19 () ) {
V_33 . V_35 = V_16 ;
V_33 . V_36 = V_37 ;
V_9 = F_20 ( & V_33 , 1 , V_38 ) ;
if ( V_9 < 0 ) {
if ( - V_39 != V_9 )
F_4 ( & V_12 -> V_13 ,
L_9 ,
V_14 , __LINE__ , V_9 ) ;
continue;
}
if ( V_33 . V_40 & V_37 )
F_7 () ;
V_6 . V_7 = V_31 ;
V_9 = F_3 ( V_16 , & V_6 , sizeof( V_6 ) , V_17 ) ;
if ( V_9 < 0 )
F_4 ( & V_12 -> V_13 , L_2 ,
V_14 , __LINE__ , V_9 ) ;
}
F_9 ( & V_12 -> V_13 , L_10 ,
V_14 , __LINE__ ) ;
return 0 ;
}
static void F_21 ( struct V_41 * V_42 )
{
int V_9 ;
F_9 ( & V_42 -> V_13 , L_11 ,
V_14 , __LINE__ , V_42 -> V_43 ) ;
if ( V_42 -> V_43 )
return;
V_12 = V_42 ;
V_9 = F_11 () ;
if ( V_9 )
goto exit;
V_9 = F_22 ( & V_44 ) ;
if ( V_9 ) {
F_4 ( & V_42 -> V_13 ,
L_12 , V_9 ) ;
goto V_45;
}
V_46 = F_23 ( F_17 , NULL , L_13 ) ;
if ( F_24 ( V_46 ) ) {
V_9 = F_25 ( V_46 ) ;
F_4 ( & V_42 -> V_13 , L_14 ,
V_14 , __LINE__ , V_9 ) ;
goto V_47;
}
return;
V_47:
F_26 ( & V_44 ) ;
V_45:
F_16 () ;
exit:
V_12 = NULL ;
}
static void F_27 ( struct V_41 * V_42 )
{
int V_9 ;
F_9 ( & V_42 -> V_13 , L_11 ,
V_14 , __LINE__ , V_42 -> V_43 ) ;
if ( V_42 -> V_43 )
return;
if ( ! F_28 ( V_46 ) ) {
V_9 = F_29 ( V_34 , V_46 , 0 ) ;
if ( V_9 ) {
F_30 ( L_15 ,
V_14 , __LINE__ , V_9 ) ;
return;
}
F_31 ( V_46 ) ;
}
F_26 ( & V_44 ) ;
F_16 () ;
V_12 = NULL ;
}
static int T_1 F_32 ( void )
{
int V_9 = F_33 ( & V_48 ) ;
if ( V_9 )
F_30 ( L_16 , V_9 ) ;
return V_9 ;
}
static void T_2 F_34 ( void )
{
F_35 ( & V_48 ) ;
}
