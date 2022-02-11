static int F_1 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
F_2 ( V_2 , L_1 ) ;
F_3 ( V_2 , V_4 ,
V_5 ) ;
F_3 ( V_2 , V_6 , V_7 ) ;
F_3 ( V_2 , V_8 ,
V_9 ) ;
F_4 ( V_2 ) ;
F_3 ( V_2 , V_10 , V_11 ) ;
V_3 = F_5 ( V_2 , V_10 ,
V_12 ,
V_12 , 25000 ) ;
if ( V_3 < 0 ) {
F_2 ( V_2 , L_2 ) ;
return V_3 ;
}
F_6 ( V_13 , & V_2 -> V_14 ) ;
return 0 ;
}
static void F_7 ( struct V_1 * V_2 , bool V_15 )
{
F_2 ( V_2 , L_3 ) ;
if ( V_15 ) {
if ( ! F_8 ( V_13 , & V_2 -> V_14 ) )
F_1 ( V_2 ) ;
F_3 ( V_2 , V_16 ,
V_17 ) ;
F_3 ( V_2 , V_8 ,
V_18 |
V_19 ) ;
F_9 ( 1 ) ;
F_10 ( V_2 , V_16 ,
V_17 ) ;
F_9 ( 5 ) ;
}
F_11 ( V_13 , & V_2 -> V_14 ) ;
F_12 ( V_2 ) ;
F_13 ( V_2 ) ;
F_10 ( V_2 , V_10 , V_11 ) ;
}
void F_14 ( struct V_1 * V_2 , bool V_20 )
{
struct V_21 * V_22 = F_15 ( V_2 ) ;
F_16 ( & V_22 -> V_23 ) ;
if ( V_22 -> V_24 )
return;
V_22 -> V_24 = true ;
F_17 ( V_2 ) ;
F_18 ( V_2 ) ;
if ( F_19 ( V_13 , & V_2 -> V_14 ) ) {
F_2 ( V_2 ,
L_4 ) ;
F_20 ( V_2 ) ;
F_21 ( V_2 ) ;
}
F_22 ( V_2 ) ;
F_23 ( V_2 ) ;
F_10 ( V_2 , V_10 ,
V_25 ) ;
F_7 ( V_2 , false ) ;
F_13 ( V_2 ) ;
F_24 ( V_22 ) ;
F_17 ( V_2 ) ;
F_11 ( V_26 , & V_2 -> V_14 ) ;
F_11 ( V_27 , & V_2 -> V_14 ) ;
F_11 ( V_28 , & V_2 -> V_14 ) ;
F_25 ( V_2 ) ;
F_26 ( V_2 ) ;
}
void F_27 ( struct V_1 * V_2 , bool V_20 )
{
struct V_21 * V_22 = F_15 ( V_2 ) ;
bool V_29 ;
F_28 ( & V_22 -> V_23 ) ;
V_22 -> V_30 = true ;
V_29 = F_8 ( V_31 , & V_2 -> V_14 ) ;
F_14 ( V_2 , V_20 ) ;
F_29 ( V_2 , V_29 ) ;
F_30 ( & V_22 -> V_23 ) ;
}
static int F_31 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = F_15 ( V_2 ) ;
F_32 ( & V_22 -> V_32 ) ;
F_1 ( V_2 ) ;
F_33 ( & V_22 -> V_32 ) ;
F_34 ( V_2 -> V_33 ) ;
if ( F_35 ( V_2 ) )
return - V_34 ;
if ( F_36 ( V_2 ) )
return - V_34 ;
F_3 ( V_2 , V_35 , 0x800FFFFF ) ;
F_2 ( V_2 , L_5 ) ;
return 0 ;
}
void F_37 ( struct V_1 * V_2 , T_1 V_36 )
{
struct V_21 * V_22 = F_15 ( V_2 ) ;
F_38 ( V_2 ) ;
memset ( V_22 -> V_37 , 0 , sizeof( V_22 -> V_37 ) ) ;
memset ( V_22 -> V_38 , 0 , sizeof( V_22 -> V_38 ) ) ;
F_23 ( V_2 ) ;
}
int F_39 ( struct V_1 * V_2 ,
const struct V_39 * V_40 , bool V_41 )
{
struct V_21 * V_22 = F_15 ( V_2 ) ;
bool V_42 ;
int V_3 ;
if ( F_26 ( V_2 ) ) {
F_40 ( V_2 , L_6 ) ;
V_3 = - V_43 ;
goto V_44;
}
F_25 ( V_2 ) ;
F_41 ( V_2 , V_45 , 0xFFFFFFFF ) ;
F_17 ( V_2 ) ;
F_42 ( V_2 ) ;
F_28 ( & V_22 -> V_23 ) ;
V_42 = F_43 ( V_2 ) ;
if ( V_42 && ! V_41 ) {
V_3 = - V_46 ;
goto V_44;
}
if ( V_22 -> V_24 ) {
F_40 ( V_2 ,
L_7 ) ;
V_3 = - V_43 ;
goto V_44;
}
F_41 ( V_2 , V_47 , V_48 ) ;
F_41 ( V_2 , V_47 ,
V_49 ) ;
F_41 ( V_2 , V_45 , 0xFFFFFFFF ) ;
V_3 = F_31 ( V_2 ) ;
if ( V_3 ) {
F_44 ( V_2 , L_8 ) ;
goto V_44;
}
V_3 = F_45 ( V_2 , V_40 ) ;
if ( V_3 )
goto V_44;
V_42 = F_43 ( V_2 ) ;
if ( V_42 && ! V_41 )
V_3 = - V_46 ;
V_44:
F_30 ( & V_22 -> V_23 ) ;
return V_3 ;
}
