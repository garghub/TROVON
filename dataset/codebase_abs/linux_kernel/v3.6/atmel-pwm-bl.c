static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 = V_2 -> V_6 . V_7 ;
int V_8 ;
if ( V_2 -> V_6 . V_9 != V_10 )
V_5 = 0 ;
if ( V_2 -> V_6 . V_11 != V_10 )
V_5 = 0 ;
if ( V_4 -> V_12 -> V_13 )
V_8 = V_4 -> V_12 -> V_14 + V_5 ;
else
V_8 = V_4 -> V_12 -> V_15 - V_5 ;
if ( V_8 > V_4 -> V_12 -> V_15 )
V_8 = V_4 -> V_12 -> V_15 ;
if ( V_8 < V_4 -> V_12 -> V_14 )
V_8 = V_4 -> V_12 -> V_14 ;
if ( ! V_5 ) {
if ( V_4 -> V_16 != - 1 ) {
F_3 ( V_4 -> V_16 ,
0 ^ V_4 -> V_12 -> V_17 ) ;
}
F_4 ( & V_4 -> V_18 , V_19 , V_8 ) ;
F_5 ( & V_4 -> V_18 ) ;
} else {
F_6 ( & V_4 -> V_18 ) ;
F_4 ( & V_4 -> V_18 , V_19 , V_8 ) ;
if ( V_4 -> V_16 != - 1 ) {
F_3 ( V_4 -> V_16 ,
1 ^ V_4 -> V_12 -> V_17 ) ;
}
}
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_5 ;
if ( V_4 -> V_12 -> V_13 ) {
V_5 = F_8 ( & V_4 -> V_18 , V_20 ) -
V_4 -> V_12 -> V_14 ;
} else {
V_5 = V_4 -> V_12 -> V_15 -
F_8 ( & V_4 -> V_18 , V_20 ) ;
}
return V_5 ;
}
static int F_9 ( struct V_3 * V_4 )
{
unsigned long V_21 = V_4 -> V_18 . V_22 ;
unsigned long V_23 = F_10 ( V_21 ,
( V_4 -> V_12 -> V_24 *
V_4 -> V_12 -> V_25 ) ) - 1 ;
V_23 = F_11 ( V_23 ) ;
if ( V_23 > 0xf )
V_23 = 0xf ;
F_4 ( & V_4 -> V_18 , V_26 , V_23 ) ;
F_4 ( & V_4 -> V_18 , V_20 ,
V_4 -> V_12 -> V_14 +
V_4 -> V_27 -> V_6 . V_7 ) ;
F_4 ( & V_4 -> V_18 , V_28 ,
V_4 -> V_12 -> V_25 ) ;
F_12 ( & V_4 -> V_29 -> V_30 , L_1
L_2 , V_4 -> V_18 . V_22 /
V_4 -> V_12 -> V_25 /
( 1 << V_23 ) ) ;
return F_6 ( & V_4 -> V_18 ) ;
}
static int F_13 ( struct V_31 * V_29 )
{
struct V_32 V_6 ;
const struct V_33 * V_12 ;
struct V_1 * V_27 ;
struct V_3 * V_4 ;
int V_34 ;
V_4 = F_14 ( & V_29 -> V_30 , sizeof( struct V_3 ) ,
V_35 ) ;
if ( ! V_4 )
return - V_36 ;
V_4 -> V_29 = V_29 ;
V_12 = V_29 -> V_30 . V_37 ;
if ( ! V_12 ) {
V_34 = - V_38 ;
goto V_39;
}
if ( V_12 -> V_25 < V_12 -> V_15 ||
V_12 -> V_14 > V_12 -> V_15 ||
V_12 -> V_24 == 0 ) {
V_34 = - V_40 ;
goto V_39;
}
V_4 -> V_12 = V_12 ;
V_4 -> V_16 = V_12 -> V_16 ;
V_34 = F_15 ( V_12 -> V_41 , & V_4 -> V_18 ) ;
if ( V_34 )
goto V_39;
if ( V_4 -> V_16 != - 1 ) {
V_34 = F_16 ( & V_29 -> V_30 , V_4 -> V_16 ,
L_3 ) ;
if ( V_34 ) {
V_4 -> V_16 = - 1 ;
goto V_42;
}
V_34 = F_17 ( V_4 -> V_16 ,
0 ^ V_12 -> V_17 ) ;
if ( V_34 )
goto V_42;
}
memset ( & V_6 , 0 , sizeof( struct V_32 ) ) ;
V_6 . type = V_43 ;
V_6 . V_44 = V_12 -> V_15 - V_12 -> V_14 ;
V_27 = F_18 ( L_4 , & V_29 -> V_30 , V_4 ,
& V_45 , & V_6 ) ;
if ( F_19 ( V_27 ) ) {
V_34 = F_20 ( V_27 ) ;
goto V_42;
}
V_4 -> V_27 = V_27 ;
F_21 ( V_29 , V_4 ) ;
V_27 -> V_6 . V_9 = V_10 ;
V_27 -> V_6 . V_7 = V_27 -> V_6 . V_44 / 2 ;
V_34 = F_9 ( V_4 ) ;
if ( V_34 )
goto V_46;
F_1 ( V_27 ) ;
return 0 ;
V_46:
F_21 ( V_29 , NULL ) ;
F_22 ( V_27 ) ;
V_42:
F_23 ( & V_4 -> V_18 ) ;
V_39:
return V_34 ;
}
static int T_2 F_24 ( struct V_31 * V_29 )
{
struct V_3 * V_4 = F_25 ( V_29 ) ;
if ( V_4 -> V_16 != - 1 )
F_3 ( V_4 -> V_16 , 0 ) ;
F_5 ( & V_4 -> V_18 ) ;
F_23 ( & V_4 -> V_18 ) ;
F_22 ( V_4 -> V_27 ) ;
F_21 ( V_29 , NULL ) ;
return 0 ;
}
static int T_3 F_26 ( void )
{
return F_27 ( & V_47 , F_13 ) ;
}
static void T_2 F_28 ( void )
{
F_29 ( & V_47 ) ;
}
