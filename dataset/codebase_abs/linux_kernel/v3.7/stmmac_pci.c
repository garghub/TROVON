static void F_1 ( void )
{
memset ( & V_1 , 0 , sizeof( struct V_2 ) ) ;
V_1 . V_3 = 1 ;
V_1 . V_4 = 0 ;
V_1 . V_5 = V_6 ;
V_1 . V_7 = 2 ;
V_1 . V_8 = 1 ;
V_1 . V_9 = 1 ;
V_10 . V_11 = NULL ;
V_10 . V_12 = 0 ;
V_1 . V_13 = & V_10 ;
V_14 . V_15 = 32 ;
V_14 . V_16 = V_17 ;
V_1 . V_14 = & V_14 ;
}
static int T_1 F_2 ( struct V_18 * V_19 ,
const struct V_20 * V_21 )
{
int V_22 = 0 ;
void T_2 * V_23 = NULL ;
struct V_24 * V_25 = NULL ;
int V_26 ;
V_22 = F_3 ( V_19 ) ;
if ( V_22 ) {
F_4 ( L_1 , V_27 ,
F_5 ( V_19 ) ) ;
return V_22 ;
}
if ( F_6 ( V_19 , V_28 ) ) {
F_4 ( L_2 , V_27 ) ;
V_22 = - V_29 ;
goto V_30;
}
for ( V_26 = 0 ; V_26 <= 5 ; V_26 ++ ) {
if ( F_7 ( V_19 , V_26 ) == 0 )
continue;
V_23 = F_8 ( V_19 , V_26 , 0 ) ;
if ( V_23 == NULL ) {
F_4 ( L_3 ,
V_27 ) ;
V_22 = - V_31 ;
goto V_32;
}
break;
}
F_9 ( V_19 ) ;
F_1 () ;
V_25 = F_10 ( & ( V_19 -> V_33 ) , & V_1 , V_23 ) ;
if ( ! V_25 ) {
F_4 ( L_4 , V_27 ) ;
goto V_34;
}
V_25 -> V_33 -> V_35 = V_19 -> V_35 ;
V_25 -> V_36 = V_19 -> V_35 ;
F_11 ( V_19 , V_25 -> V_33 ) ;
F_12 ( L_5 ) ;
return 0 ;
V_34:
F_13 ( V_19 ) ;
V_32:
F_14 ( V_19 ) ;
V_30:
F_15 ( V_19 ) ;
return V_22 ;
}
static void T_3 F_16 ( struct V_18 * V_19 )
{
struct V_37 * V_38 = F_17 ( V_19 ) ;
struct V_24 * V_25 = F_18 ( V_38 ) ;
F_19 ( V_38 ) ;
F_11 ( V_19 , NULL ) ;
F_20 ( V_19 , V_25 -> V_39 ) ;
F_14 ( V_19 ) ;
F_15 ( V_19 ) ;
}
static int F_21 ( struct V_18 * V_19 , T_4 V_40 )
{
struct V_37 * V_38 = F_17 ( V_19 ) ;
int V_22 ;
V_22 = F_22 ( V_38 ) ;
F_23 ( V_19 ) ;
F_24 ( V_19 , F_25 ( V_19 , V_40 ) ) ;
return V_22 ;
}
static int F_26 ( struct V_18 * V_19 )
{
struct V_37 * V_38 = F_17 ( V_19 ) ;
F_24 ( V_19 , V_41 ) ;
F_27 ( V_19 ) ;
return F_28 ( V_38 ) ;
}
