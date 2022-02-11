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
V_1 . V_18 = V_19 ;
V_1 . V_20 = 1 ;
}
static int F_2 ( struct V_21 * V_22 ,
const struct V_23 * V_24 )
{
int V_25 = 0 ;
void T_1 * V_26 = NULL ;
struct V_27 * V_28 = NULL ;
int V_29 ;
V_25 = F_3 ( V_22 ) ;
if ( V_25 ) {
F_4 ( L_1 , V_30 ,
F_5 ( V_22 ) ) ;
return V_25 ;
}
if ( F_6 ( V_22 , V_31 ) ) {
F_4 ( L_2 , V_30 ) ;
V_25 = - V_32 ;
goto V_33;
}
for ( V_29 = 0 ; V_29 <= 5 ; V_29 ++ ) {
if ( F_7 ( V_22 , V_29 ) == 0 )
continue;
V_26 = F_8 ( V_22 , V_29 , 0 ) ;
if ( V_26 == NULL ) {
F_4 ( L_3 ,
V_30 ) ;
V_25 = - V_34 ;
goto V_35;
}
break;
}
F_9 ( V_22 ) ;
F_1 () ;
V_28 = F_10 ( & ( V_22 -> V_36 ) , & V_1 , V_26 ) ;
if ( F_11 ( V_28 ) ) {
F_4 ( L_4 , V_30 ) ;
V_25 = F_12 ( V_28 ) ;
goto V_37;
}
V_28 -> V_36 -> V_38 = V_22 -> V_38 ;
V_28 -> V_39 = V_22 -> V_38 ;
F_13 ( V_22 , V_28 -> V_36 ) ;
F_14 ( L_5 ) ;
return 0 ;
V_37:
F_15 ( V_22 ) ;
V_35:
F_16 ( V_22 ) ;
V_33:
F_17 ( V_22 ) ;
return V_25 ;
}
static void F_18 ( struct V_21 * V_22 )
{
struct V_40 * V_41 = F_19 ( V_22 ) ;
struct V_27 * V_28 = F_20 ( V_41 ) ;
F_21 ( V_41 ) ;
F_22 ( V_22 , V_28 -> V_42 ) ;
F_16 ( V_22 ) ;
F_17 ( V_22 ) ;
}
static int F_23 ( struct V_21 * V_22 , T_2 V_43 )
{
struct V_40 * V_41 = F_19 ( V_22 ) ;
int V_25 ;
V_25 = F_24 ( V_41 ) ;
F_25 ( V_22 ) ;
F_26 ( V_22 , F_27 ( V_22 , V_43 ) ) ;
return V_25 ;
}
static int F_28 ( struct V_21 * V_22 )
{
struct V_40 * V_41 = F_19 ( V_22 ) ;
F_26 ( V_22 , V_44 ) ;
F_29 ( V_22 ) ;
return F_30 ( V_41 ) ;
}
