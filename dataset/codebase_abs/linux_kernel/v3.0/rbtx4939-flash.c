static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
V_4 = F_2 ( V_2 ) ;
if ( ! V_4 )
return 0 ;
F_3 ( V_2 , NULL ) ;
if ( V_4 -> V_5 ) {
struct V_6 * V_7 = V_2 -> V_2 . V_8 ;
if ( V_4 -> V_9 )
F_4 ( V_4 -> V_10 ) ;
F_5 ( V_4 -> V_5 ) ;
F_6 ( V_4 -> V_5 ) ;
}
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_6 * V_7 ;
struct V_3 * V_4 ;
struct V_11 * V_12 ;
const char * * V_13 ;
int V_14 = 0 ;
unsigned long V_15 ;
V_7 = V_2 -> V_2 . V_8 ;
if ( ! V_7 )
return - V_16 ;
V_12 = F_8 ( V_2 , V_17 , 0 ) ;
if ( ! V_12 )
return - V_16 ;
V_4 = F_9 ( & V_2 -> V_2 , sizeof( struct V_3 ) ,
V_18 ) ;
if ( ! V_4 )
return - V_19 ;
F_3 ( V_2 , V_4 ) ;
V_15 = F_10 ( V_12 ) ;
F_11 ( L_1 , V_12 ) ;
if ( ! F_12 ( & V_2 -> V_2 , V_12 -> V_20 , V_15 ,
F_13 ( & V_2 -> V_2 ) ) )
return - V_21 ;
V_4 -> V_22 . V_23 = F_13 ( & V_2 -> V_2 ) ;
V_4 -> V_22 . V_24 = V_12 -> V_20 ;
V_4 -> V_22 . V_15 = V_15 ;
V_4 -> V_22 . V_25 = V_7 -> V_26 ;
V_4 -> V_22 . V_27 = F_14 ( & V_2 -> V_2 , V_4 -> V_22 . V_24 , V_15 ) ;
if ( ! V_4 -> V_22 . V_27 )
return - V_21 ;
if ( V_7 -> V_28 )
(* V_7 -> V_28 )( & V_4 -> V_22 ) ;
else
F_15 ( & V_4 -> V_22 ) ;
V_13 = V_29 ;
for (; ! V_4 -> V_5 && * V_13 ; V_13 ++ )
V_4 -> V_5 = F_16 ( * V_13 , & V_4 -> V_22 ) ;
if ( ! V_4 -> V_5 ) {
F_17 ( & V_2 -> V_2 , L_2 ) ;
V_14 = - V_30 ;
goto V_31;
}
V_4 -> V_5 -> V_32 = V_33 ;
if ( V_14 )
goto V_31;
V_14 = F_18 ( V_4 -> V_5 , V_34 ,
& V_4 -> V_10 , 0 ) ;
if ( V_14 > 0 ) {
F_19 ( V_4 -> V_5 , V_4 -> V_10 , V_14 ) ;
V_4 -> V_9 = V_14 ;
return 0 ;
}
if ( V_7 -> V_9 ) {
F_11 ( L_3 ) ;
F_19 ( V_4 -> V_5 , V_7 -> V_10 , V_7 -> V_9 ) ;
return 0 ;
}
F_19 ( V_4 -> V_5 , NULL , 0 ) ;
return 0 ;
V_31:
F_1 ( V_2 ) ;
return V_14 ;
}
static void F_20 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_5 -> V_35 && V_4 -> V_5 -> V_36 )
if ( V_4 -> V_5 -> V_35 ( V_4 -> V_5 ) == 0 )
V_4 -> V_5 -> V_36 ( V_4 -> V_5 ) ;
}
static int T_1 F_21 ( void )
{
return F_22 ( & V_37 ) ;
}
static void T_2 F_23 ( void )
{
F_24 ( & V_37 ) ;
}
