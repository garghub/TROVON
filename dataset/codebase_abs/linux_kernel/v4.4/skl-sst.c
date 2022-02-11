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
struct V_17 * V_18 = V_2 -> V_19 ;
T_1 V_20 ;
V_18 -> V_21 = false ;
F_6 ( & V_18 -> V_22 ) ;
if ( V_2 -> V_23 == NULL ) {
V_9 = F_7 ( & V_2 -> V_23 , L_2 , V_2 -> V_24 ) ;
if ( V_9 < 0 ) {
F_8 ( V_2 -> V_24 , L_3 , V_9 ) ;
F_9 ( V_2 ) ;
return - V_25 ;
}
}
V_9 = F_10 ( V_2 ) ;
if ( V_9 < 0 ) {
F_8 ( V_2 -> V_24 , L_4 , V_9 ) ;
goto V_26;
}
V_9 = F_11 ( V_2 ) ;
if ( V_9 < 0 ) {
F_8 ( V_2 -> V_24 , L_5 , V_9 ) ;
goto V_26;
}
F_12 ( V_2 ) ;
F_13 ( V_2 ) ;
for ( V_16 = V_27 ; V_16 > 0 ; -- V_16 ) {
if ( F_1 ( V_2 , V_28 ) ) {
F_14 ( V_2 -> V_24 ,
L_6 ) ;
break;
}
F_15 ( 1 ) ;
}
if ( ! V_16 ) {
V_20 = F_2 ( V_2 , V_5 ) ;
F_8 ( V_2 -> V_24 ,
L_7 , V_20 ) ;
V_9 = - V_25 ;
goto V_26;
}
V_9 = F_3 ( V_2 , V_2 -> V_23 -> V_29 , V_2 -> V_23 -> V_30 ) ;
if ( V_9 < 0 ) {
F_8 ( V_2 -> V_24 , L_8 , V_9 ) ;
goto V_26;
} else {
V_9 = F_16 ( V_18 -> V_22 , V_18 -> V_21 ,
F_17 ( V_31 ) ) ;
if ( V_9 == 0 ) {
F_8 ( V_2 -> V_24 , L_9 ) ;
V_9 = - V_25 ;
goto V_26;
}
F_14 ( V_2 -> V_24 , L_10 , V_9 ) ;
F_18 ( V_2 , V_32 ) ;
}
return 0 ;
V_26:
F_9 ( V_2 ) ;
F_19 ( V_2 -> V_23 ) ;
V_2 -> V_23 = NULL ;
return V_9 ;
}
static int F_20 ( struct V_1 * V_2 )
{
int V_9 ;
V_9 = F_5 ( V_2 ) ;
if ( V_9 < 0 ) {
F_8 ( V_2 -> V_24 , L_11 ) ;
return V_9 ;
}
F_18 ( V_2 , V_32 ) ;
return V_9 ;
}
static int F_21 ( struct V_1 * V_2 )
{
int V_9 ;
struct V_33 V_34 ;
struct V_17 * V_18 = V_2 -> V_19 ;
F_14 ( V_2 -> V_24 , L_12 , V_35 ) ;
F_22 ( & V_2 -> V_36 ) ;
if ( ! F_23 ( V_2 ) ) {
F_24 ( & V_2 -> V_36 ) ;
return 0 ;
}
F_24 ( & V_2 -> V_36 ) ;
V_34 . V_37 = V_38 ;
V_34 . V_39 = V_40 ;
V_9 = F_25 ( & V_18 -> V_41 , V_42 , V_43 , & V_34 ) ;
if ( V_9 < 0 ) {
F_8 ( V_2 -> V_24 , L_13 ) ;
return V_9 ;
}
V_9 = F_9 ( V_2 ) ;
if ( V_9 < 0 ) {
F_8 ( V_2 -> V_24 , L_14 , V_9 ) ;
V_9 = - V_25 ;
}
F_18 ( V_2 , V_44 ) ;
V_2 -> V_10 . V_11 . V_45 ( V_2 ) ;
F_26 ( V_2 ) ;
F_27 ( V_2 ) ;
F_28 ( V_2 ) ;
return V_9 ;
}
static unsigned int F_29 ( struct V_1 * V_2 )
{
return F_2 ( V_2 , V_46 ) ;
}
int F_30 ( struct V_47 * V_24 , void T_2 * V_48 , int V_49 ,
struct V_50 V_51 , struct V_17 * * V_52 )
{
struct V_17 * V_18 ;
struct V_1 * V_53 ;
int V_9 ;
V_18 = F_31 ( V_24 , sizeof( * V_18 ) , V_54 ) ;
if ( V_18 == NULL )
return - V_55 ;
V_18 -> V_24 = V_24 ;
V_56 . V_19 = V_18 ;
V_18 -> V_52 = F_32 ( V_24 , & V_56 , V_49 ) ;
if ( ! V_18 -> V_52 ) {
F_8 ( V_18 -> V_24 , L_15 , V_35 ) ;
return - V_57 ;
}
V_53 = V_18 -> V_52 ;
V_53 -> V_58 . V_59 = V_48 ;
V_53 -> V_58 . V_60 = V_48 ;
F_33 ( V_53 , ( V_61 + V_62 ) ,
V_63 , V_64 , V_65 ) ;
V_53 -> V_51 = V_51 ;
V_53 -> V_66 = V_67 ;
V_9 = F_34 ( V_24 , V_18 ) ;
if ( V_9 )
return V_9 ;
V_9 = V_53 -> V_66 . V_68 ( V_53 ) ;
if ( V_9 < 0 ) {
F_8 ( V_24 , L_16 , V_9 ) ;
return V_9 ;
}
if ( V_52 )
* V_52 = V_18 ;
return 0 ;
F_35 ( & V_18 -> V_41 ) ;
return V_9 ;
}
void F_36 ( struct V_47 * V_24 , struct V_17 * V_2 )
{
F_35 ( & V_2 -> V_41 ) ;
V_2 -> V_52 -> V_10 . V_11 . V_45 ( V_2 -> V_52 ) ;
V_2 -> V_52 -> V_11 -> free ( V_2 -> V_52 ) ;
}
