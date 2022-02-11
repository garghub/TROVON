static bool F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
T_1 V_4 ;
V_4 = F_2 ( V_2 , V_5 ) & V_6 ;
return ( V_4 == V_3 ) ;
}
static int F_3 ( struct V_1 * V_2 ,
const void * V_7 , T_1 V_8 )
{
int V_9 = 0 ;
V_9 = V_2 -> V_10 . V_11 . V_12 ( V_2 , V_7 , V_8 ) ;
if ( V_9 < 0 )
return V_9 ;
V_9 = F_4 ( V_2 ,
V_5 ,
V_6 ,
V_13 ,
V_14 ,
L_1 ) ;
V_2 -> V_10 . V_11 . V_15 ( V_2 ) ;
return V_9 ;
}
static int F_5 ( struct V_1 * V_2 )
{
int V_9 = 0 , V_16 ;
const struct V_17 * V_18 = NULL ;
struct V_19 * V_20 = V_2 -> V_21 ;
T_1 V_22 ;
V_9 = F_6 ( & V_18 , L_2 , V_2 -> V_23 ) ;
if ( V_9 < 0 ) {
F_7 ( V_2 -> V_23 , L_3 , V_9 ) ;
F_8 ( V_2 ) ;
return - V_24 ;
}
F_9 ( V_2 ) ;
F_10 ( V_2 ) ;
for ( V_16 = V_25 ; V_16 > 0 ; -- V_16 ) {
if ( F_1 ( V_2 , V_26 ) ) {
F_11 ( V_2 -> V_23 ,
L_4 ) ;
break;
}
F_12 ( 1 ) ;
}
if ( ! V_16 ) {
V_22 = F_2 ( V_2 , V_5 ) ;
F_7 ( V_2 -> V_23 ,
L_5 , V_22 ) ;
V_9 = - V_24 ;
goto V_27;
}
V_9 = F_3 ( V_2 , V_18 -> V_28 , V_18 -> V_29 ) ;
if ( V_9 < 0 ) {
F_7 ( V_2 -> V_23 , L_6 , V_9 ) ;
goto V_27;
} else {
V_9 = F_13 ( V_20 -> V_30 , V_20 -> V_31 ,
F_14 ( V_32 ) ) ;
if ( V_9 == 0 ) {
F_7 ( V_2 -> V_23 , L_7 ) ;
V_9 = - V_24 ;
goto V_27;
}
F_11 ( V_2 -> V_23 , L_8 , V_9 ) ;
F_15 ( V_2 , V_33 ) ;
}
F_16 ( V_18 ) ;
return 0 ;
V_27:
F_8 ( V_2 ) ;
F_16 ( V_18 ) ;
return V_9 ;
}
static int F_17 ( struct V_1 * V_2 )
{
int V_9 ;
V_9 = F_5 ( V_2 ) ;
if ( V_9 < 0 ) {
F_7 ( V_2 -> V_23 , L_9 ) ;
return V_9 ;
}
F_15 ( V_2 , V_33 ) ;
return V_9 ;
}
static int F_18 ( struct V_1 * V_2 )
{
int V_9 ;
struct V_34 V_35 ;
struct V_19 * V_20 = V_2 -> V_21 ;
F_11 ( V_2 -> V_23 , L_10 , V_36 ) ;
F_19 ( & V_2 -> V_37 ) ;
if ( ! F_20 ( V_2 ) ) {
F_21 ( & V_2 -> V_37 ) ;
return 0 ;
}
F_21 ( & V_2 -> V_37 ) ;
V_35 . V_38 = V_39 ;
V_35 . V_40 = V_41 ;
V_9 = F_22 ( & V_20 -> V_42 , V_43 , V_44 , & V_35 ) ;
if ( V_9 < 0 ) {
F_7 ( V_2 -> V_23 , L_11 ) ;
return V_9 ;
}
V_9 = F_8 ( V_2 ) ;
if ( V_9 < 0 ) {
F_7 ( V_2 -> V_23 , L_12 , V_9 ) ;
V_9 = - V_24 ;
}
F_15 ( V_2 , V_45 ) ;
return V_9 ;
}
static unsigned int F_23 ( struct V_1 * V_2 )
{
return F_2 ( V_2 , V_46 ) ;
}
int F_24 ( struct V_47 * V_23 , void T_2 * V_48 , int V_49 ,
struct V_50 V_51 , struct V_19 * * V_52 )
{
struct V_19 * V_20 ;
struct V_1 * V_53 ;
int V_9 ;
V_20 = F_25 ( V_23 , sizeof( * V_20 ) , V_54 ) ;
if ( V_20 == NULL )
return - V_55 ;
V_20 -> V_23 = V_23 ;
V_56 . V_21 = V_20 ;
V_20 -> V_52 = F_26 ( V_23 , & V_56 , V_49 ) ;
if ( ! V_20 -> V_52 ) {
F_7 ( V_20 -> V_23 , L_13 , V_36 ) ;
return - V_57 ;
}
V_53 = V_20 -> V_52 ;
V_53 -> V_58 . V_59 = V_48 ;
V_53 -> V_58 . V_60 = V_48 ;
F_27 ( V_53 , ( V_61 + V_62 ) ,
V_63 , V_64 , V_65 ) ;
V_53 -> V_51 = V_51 ;
V_53 -> V_66 = V_67 ;
V_9 = F_28 ( V_23 , V_20 ) ;
if ( V_9 )
return V_9 ;
V_20 -> V_31 = false ;
F_29 ( & V_20 -> V_30 ) ;
V_9 = F_30 ( V_53 ) ;
if ( V_9 < 0 ) {
F_7 ( V_20 -> V_23 , L_14 , V_9 ) ;
goto V_68;
}
V_9 = F_31 ( V_53 ) ;
if ( V_9 < 0 ) {
F_7 ( V_23 , L_15 , V_9 ) ;
goto V_68;
}
V_9 = V_53 -> V_66 . V_69 ( V_53 ) ;
if ( V_9 < 0 ) {
F_7 ( V_23 , L_16 , V_9 ) ;
return V_9 ;
}
if ( V_52 )
* V_52 = V_20 ;
return 0 ;
V_68:
F_32 ( & V_20 -> V_42 ) ;
return V_9 ;
}
void F_33 ( struct V_47 * V_23 , struct V_19 * V_2 )
{
F_32 ( & V_2 -> V_42 ) ;
V_2 -> V_52 -> V_10 . V_11 . V_70 ( V_2 -> V_52 ) ;
V_2 -> V_52 -> V_11 -> free ( V_2 -> V_52 ) ;
}
