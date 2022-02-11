static void F_1 ( struct V_1 * V_2 , int * V_3 )
{
* V_3 = V_4 >> 2 ;
}
static bool F_2 ( struct V_1 * V_2 , T_1 V_5 , T_2 * V_6 )
{
struct V_7 * V_8 = (struct V_7 * ) V_2 -> V_9 ;
struct V_10 * V_11 = F_3 ( V_8 -> V_12 ) ;
struct V_13 * V_14 ;
V_14 = F_4 ( & V_11 -> V_12 ) ;
if ( V_5 >= ( F_5 ( V_14 -> V_15 ) ) ) {
F_6 ( V_2 ,
L_1 ,
V_16 , V_5 ) ;
return false ;
}
* V_6 = V_14 -> V_15 [ V_5 ] ;
return true ;
}
static int F_7 ( struct V_10 * V_11 )
{
void T_3 * V_17 ;
struct V_7 * V_8 ;
struct V_18 * V_19 ;
struct V_20 * V_21 ;
const struct V_22 * V_23 = F_8 ( V_11 ) ;
int V_24 ;
int V_25 = 0 ;
struct V_26 * V_27 ;
char V_28 [ 64 ] ;
if ( ! F_4 ( & V_11 -> V_12 ) ) {
F_9 ( & V_11 -> V_12 , L_2 ) ;
return - V_29 ;
}
V_21 = F_10 ( V_11 , V_30 , 0 ) ;
if ( V_21 == NULL ) {
F_9 ( & V_11 -> V_12 , L_3 ) ;
return - V_31 ;
}
V_17 = F_11 ( & V_11 -> V_12 , V_21 -> V_32 , F_12 ( V_21 ) ) ;
if ( V_17 == NULL ) {
F_9 ( & V_11 -> V_12 , L_4 ) ;
return - V_33 ;
}
V_21 = F_10 ( V_11 , V_34 , 0 ) ;
if ( V_21 == NULL ) {
F_9 ( & V_11 -> V_12 , L_5 ) ;
return - V_31 ;
}
V_24 = V_21 -> V_32 ;
F_13 () ;
V_19 = F_14 ( sizeof( struct V_7 ) , & V_35 ) ;
if ( V_19 == NULL ) {
F_9 ( & V_11 -> V_12 , L_6 ) ;
return - V_33 ;
}
F_15 ( V_19 , & V_11 -> V_12 ) ;
F_16 ( V_11 , V_19 ) ;
V_8 = V_19 -> V_9 ;
V_8 -> V_19 = V_19 ;
V_8 -> V_12 = & V_11 -> V_12 ;
V_8 -> V_17 = V_17 ;
V_8 -> V_24 = V_24 ;
V_25 = F_17 ( V_24 , V_36 , V_37 , L_7 , V_8 ) ;
if ( V_25 ) {
F_9 ( & V_11 -> V_12 , L_8 ) ;
goto V_38;
}
V_25 = F_18 ( V_23 -> V_39 , V_8 , & V_40 ) ;
if ( V_25 ) {
F_9 ( & V_11 -> V_12 , L_9 ) ;
goto V_41;
}
V_27 = V_8 -> V_42 ;
F_19 ( V_27 , V_28 , sizeof( V_28 ) ) ;
F_20 ( V_19 -> V_43 , L_10 ,
V_28 , ( unsigned long ) V_17 , V_24 ) ;
return 0 ;
V_41:
F_21 ( V_24 , V_8 ) ;
V_38:
F_22 ( V_19 ) ;
return V_25 ;
}
static int F_23 ( struct V_10 * V_11 )
{
struct V_18 * V_19 = F_24 ( V_11 ) ;
if ( V_19 ) {
struct V_7 * V_8 = V_19 -> V_9 ;
F_25 ( V_8 ) ;
F_21 ( V_8 -> V_24 , V_8 ) ;
F_22 ( V_8 -> V_19 ) ;
}
return 0 ;
}
int F_26 ( void )
{
return F_27 ( & V_44 ) ;
}
void F_28 ( void )
{
F_29 ( & V_44 ) ;
}
