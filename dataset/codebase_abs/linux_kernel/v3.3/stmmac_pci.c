static void F_1 ( void )
{
memset ( & V_1 , 0 , sizeof( struct V_2 ) ) ;
V_1 . V_3 = 1 ;
V_1 . V_4 = 0 ;
V_1 . V_5 = V_6 ;
V_1 . V_7 = 32 ;
V_1 . V_8 = 2 ;
V_1 . V_9 = 1 ;
V_1 . V_10 = 1 ;
V_11 . V_3 = 1 ;
V_11 . V_12 = NULL ;
V_11 . V_13 = 0 ;
V_1 . V_14 = & V_11 ;
}
static int T_1 F_2 ( struct V_15 * V_16 ,
const struct V_17 * V_18 )
{
int V_19 = 0 ;
void T_2 * V_20 = NULL ;
struct V_21 * V_22 = NULL ;
int V_23 ;
V_19 = F_3 ( V_16 ) ;
if ( V_19 ) {
F_4 ( L_1 , V_24 ,
F_5 ( V_16 ) ) ;
return V_19 ;
}
if ( F_6 ( V_16 , V_25 ) ) {
F_4 ( L_2 , V_24 ) ;
V_19 = - V_26 ;
goto V_27;
}
for ( V_23 = 0 ; V_23 <= 5 ; V_23 ++ ) {
if ( F_7 ( V_16 , V_23 ) == 0 )
continue;
V_20 = F_8 ( V_16 , V_23 , 0 ) ;
if ( V_20 == NULL ) {
F_4 ( L_3 ,
V_24 ) ;
V_19 = - V_28 ;
goto V_29;
}
break;
}
F_9 ( V_16 ) ;
F_1 () ;
V_22 = F_10 ( & ( V_16 -> V_30 ) , & V_1 , V_20 ) ;
if ( ! V_22 ) {
F_4 ( L_4 , V_24 ) ;
goto V_31;
}
V_22 -> V_30 -> V_32 = V_16 -> V_32 ;
V_22 -> V_33 = V_16 -> V_32 ;
F_11 ( V_16 , V_22 -> V_30 ) ;
F_12 ( L_5 ) ;
return 0 ;
V_31:
F_13 ( V_16 ) ;
V_29:
F_14 ( V_16 ) ;
V_27:
F_15 ( V_16 ) ;
return V_19 ;
}
static void T_3 F_16 ( struct V_15 * V_16 )
{
struct V_34 * V_35 = F_17 ( V_16 ) ;
struct V_21 * V_22 = F_18 ( V_35 ) ;
F_19 ( V_35 ) ;
F_11 ( V_16 , NULL ) ;
F_20 ( V_16 , V_22 -> V_36 ) ;
F_14 ( V_16 ) ;
F_15 ( V_16 ) ;
}
static int F_21 ( struct V_15 * V_16 , T_4 V_37 )
{
struct V_34 * V_35 = F_17 ( V_16 ) ;
int V_19 ;
V_19 = F_22 ( V_35 ) ;
F_23 ( V_16 ) ;
F_24 ( V_16 , F_25 ( V_16 , V_37 ) ) ;
return V_19 ;
}
static int F_26 ( struct V_15 * V_16 )
{
struct V_34 * V_35 = F_17 ( V_16 ) ;
F_24 ( V_16 , V_38 ) ;
F_27 ( V_16 ) ;
return F_28 ( V_35 ) ;
}
static int T_5 F_29 ( void )
{
int V_19 ;
V_19 = F_30 ( & V_39 ) ;
if ( V_19 < 0 )
F_4 ( L_6 , V_24 ) ;
return V_19 ;
}
static void T_6 F_31 ( void )
{
F_32 ( & V_39 ) ;
}
