static T_1 F_1 ( int V_1 , void * V_2 )
{
const struct V_3 * V_4 ;
struct V_5 V_6 ;
int V_7 ;
F_2 ( & V_6 ) ;
V_4 = V_2 ;
V_7 = F_3 ( V_4 -> V_8 -> V_9 ) ;
if ( ( V_7 && ! V_4 -> V_8 -> V_10 ) ||
( ! V_7 && V_4 -> V_8 -> V_10 ) )
F_4 ( V_4 -> V_11 , & V_6 , V_12 , NULL ) ;
else if ( V_4 -> V_8 -> V_13 &&
( ( V_7 && V_4 -> V_8 -> V_10 ) ||
( ! V_7 && ! V_4 -> V_8 -> V_10 ) ) )
F_4 ( V_4 -> V_11 , & V_6 , V_14 , NULL ) ;
return V_15 ;
}
static int F_5 ( struct V_16 * V_17 )
{
int V_18 ;
const struct V_19 * V_8 = V_17 -> V_20 . V_21 ;
V_18 = F_6 ( V_8 -> V_9 , V_8 -> V_22 ) ;
if ( V_18 ) {
F_7 ( L_1 , V_8 -> V_9 ) ;
return - V_23 ;
}
V_18 = F_8 ( V_8 -> V_9 ) ;
if ( V_18 ) {
F_7 ( L_2 ) ;
F_9 ( V_8 -> V_9 ) ;
return - V_23 ;
}
return 0 ;
}
static unsigned long
F_10 ( const struct V_19 * V_8 )
{
unsigned long V_24 = V_8 -> V_10 ?
V_25 : V_26 ;
if ( V_8 -> V_13 ) {
V_24 |= ( ( V_24 & V_26 ) ?
V_25 : V_26 ) ;
}
return V_24 ;
}
static int F_11 ( struct V_16 * V_17 )
{
struct V_3 * V_2 ;
int V_1 ;
int V_18 ;
int V_27 ;
int V_28 ;
const struct V_19 * V_8 = V_17 -> V_20 . V_21 ;
V_18 = F_5 ( V_17 ) ;
if ( V_18 )
return - V_23 ;
V_1 = F_12 ( V_8 -> V_9 ) ;
if ( V_1 < 0 ) {
F_13 ( L_3 , V_1 ) ;
V_27 = - V_23 ;
goto V_29;
}
V_2 = F_14 ( & V_17 -> V_20 , sizeof( struct V_3 ) ,
V_30 ) ;
if ( V_2 == NULL ) {
V_27 = - V_31 ;
goto V_29;
}
V_2 -> V_4 . V_32 = V_12 | V_33 |
V_34 | V_35 | V_36 ;
if ( V_8 -> V_13 )
V_2 -> V_4 . V_32 |= V_14 | V_37 |
V_38 ;
V_2 -> V_4 . V_39 = V_40 ;
snprintf ( V_2 -> V_4 . V_41 , V_42 - 1 , L_4 ,
V_17 -> V_41 , V_17 -> V_43 ) ;
V_28 = V_12 | V_33 ;
if ( V_8 -> V_13 )
V_28 |= V_14 | V_37 ;
V_2 -> V_11 = F_15 ( & V_2 -> V_4 , V_28 ) ;
if ( V_2 -> V_11 == NULL ) {
F_13 ( L_5 , V_1 ) ;
V_27 = - V_23 ;
goto V_29;
}
V_2 -> V_1 = V_1 ;
V_2 -> V_8 = V_8 ;
V_18 = F_16 ( V_1 , F_1 ,
F_10 ( V_8 ) , V_2 -> V_4 . V_41 , V_2 ) ;
if ( V_18 ) {
F_17 ( V_2 -> V_11 ) ;
F_13 ( L_6 , V_1 ) ;
V_27 = - V_23 ;
goto V_29;
}
F_18 ( V_17 , V_2 ) ;
F_19 ( V_2 -> V_11 -> V_20 , L_7 , V_1 ) ;
return 0 ;
V_29:
F_9 ( V_8 -> V_9 ) ;
return V_27 ;
}
static int F_20 ( struct V_16 * V_17 )
{
struct V_3 * V_2 = F_21 ( V_17 ) ;
const struct V_19 * V_8 = V_2 -> V_8 ;
F_18 ( V_17 , NULL ) ;
F_22 ( V_2 -> V_1 , V_2 ) ;
F_9 ( V_8 -> V_9 ) ;
F_17 ( V_2 -> V_11 ) ;
F_23 ( L_8 , V_2 -> V_1 ) ;
return 0 ;
}
static int T_2 F_24 ( void )
{
int V_18 = F_25 ( & V_44 ) ;
if ( V_18 < 0 )
F_13 ( L_9 ) ;
return V_18 ;
}
static void T_3 F_26 ( void )
{
F_27 ( & V_44 ) ;
F_28 ( L_10 ) ;
}
