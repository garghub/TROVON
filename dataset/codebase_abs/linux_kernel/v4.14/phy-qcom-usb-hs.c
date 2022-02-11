static int F_1 ( struct V_1 * V_1 , enum V_2 V_3 )
{
struct V_4 * V_5 = F_2 ( V_1 ) ;
T_1 V_6 ;
int V_7 ;
if ( ! V_5 -> V_8 ) {
T_1 V_9 = 0 ;
switch ( V_3 ) {
case V_10 :
case V_11 :
V_9 |= V_12 ;
case V_13 :
V_9 |= V_14 ;
default:
break;
}
V_7 = F_3 ( V_5 -> V_15 , V_16 , V_9 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_3 ( V_5 -> V_15 , V_17 , V_9 ) ;
} else {
switch ( V_3 ) {
case V_10 :
case V_13 :
V_6 = F_4 ( V_18 ) ;
break;
case V_11 :
V_6 = F_5 ( V_18 ) ;
break;
default:
return - V_19 ;
}
V_7 = F_3 ( V_5 -> V_15 , F_4 ( V_20 ) ,
V_21 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_3 ( V_5 -> V_15 , V_6 , V_22 ) ;
}
return V_7 ;
}
static int
F_6 ( struct V_23 * V_24 , unsigned long V_25 ,
void * V_26 )
{
struct V_4 * V_5 ;
T_1 V_6 ;
V_5 = F_7 ( V_24 , struct V_4 , V_27 ) ;
if ( V_25 )
V_6 = F_4 ( V_18 ) ;
else
V_6 = F_5 ( V_18 ) ;
return F_3 ( V_5 -> V_15 , V_6 , V_28 ) ;
}
static int F_8 ( struct V_1 * V_1 )
{
struct V_4 * V_5 = F_2 ( V_1 ) ;
struct V_15 * V_15 = V_5 -> V_15 ;
const struct V_29 * V_30 ;
int V_7 , V_31 ;
V_7 = F_9 ( V_5 -> V_32 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_9 ( V_5 -> V_33 ) ;
if ( V_7 )
goto V_34;
V_7 = F_10 ( V_5 -> V_35 , 50000 ) ;
if ( V_7 < 0 )
goto V_36;
V_7 = F_11 ( V_5 -> V_35 ) ;
if ( V_7 )
goto V_36;
V_7 = F_12 ( V_5 -> V_37 , 3050000 , 3300000 ,
3300000 ) ;
if ( V_7 )
goto V_38;
V_7 = F_10 ( V_5 -> V_37 , 50000 ) ;
if ( V_7 < 0 )
goto V_38;
V_7 = F_11 ( V_5 -> V_37 ) ;
if ( V_7 )
goto V_38;
for ( V_30 = V_5 -> V_39 ; V_30 -> V_6 ; V_30 ++ ) {
V_7 = F_3 ( V_15 , V_40 + V_30 -> V_6 ,
V_30 -> V_9 ) ;
if ( V_7 )
goto V_41;
}
if ( V_5 -> V_42 ) {
V_7 = F_13 ( V_5 -> V_42 ) ;
if ( V_7 )
goto V_41;
}
if ( V_5 -> V_8 ) {
V_31 = F_14 ( V_5 -> V_8 , V_43 ) ;
F_6 ( & V_5 -> V_27 , V_31 ,
V_5 -> V_8 ) ;
V_7 = F_15 ( & V_15 -> V_44 , V_5 -> V_8 ,
V_43 , & V_5 -> V_27 ) ;
if ( V_7 )
goto V_41;
}
return 0 ;
V_41:
F_16 ( V_5 -> V_37 ) ;
V_38:
F_16 ( V_5 -> V_35 ) ;
V_36:
F_17 ( V_5 -> V_33 ) ;
V_34:
F_17 ( V_5 -> V_32 ) ;
return V_7 ;
}
static int F_18 ( struct V_1 * V_1 )
{
struct V_4 * V_5 = F_2 ( V_1 ) ;
F_16 ( V_5 -> V_37 ) ;
F_16 ( V_5 -> V_35 ) ;
F_17 ( V_5 -> V_33 ) ;
F_17 ( V_5 -> V_32 ) ;
return 0 ;
}
static int F_19 ( struct V_15 * V_15 )
{
struct V_4 * V_5 ;
struct V_45 * V_46 ;
struct V_47 * V_47 ;
struct V_48 * V_49 ;
struct V_50 * V_42 ;
int V_51 ;
int V_7 ;
V_5 = F_20 ( & V_15 -> V_44 , sizeof( * V_5 ) , V_52 ) ;
if ( ! V_5 )
return - V_53 ;
F_21 ( V_15 , V_5 ) ;
V_5 -> V_15 = V_15 ;
V_51 = F_22 ( V_15 -> V_44 . V_54 , L_1 ) ;
if ( V_51 < 0 )
V_51 = 0 ;
V_5 -> V_39 = F_23 ( & V_15 -> V_44 , ( V_51 / 2 ) + 1 ,
sizeof( * V_5 -> V_39 ) , V_52 ) ;
if ( ! V_5 -> V_39 )
return - V_53 ;
V_7 = F_24 ( V_15 -> V_44 . V_54 , L_1 ,
( T_1 * ) V_5 -> V_39 , V_51 ) ;
if ( V_7 && V_51 )
return V_7 ;
V_5 -> V_39 [ V_51 / 2 ] . V_6 = V_5 -> V_39 [ V_51 / 2 ] . V_9 = 0 ;
V_5 -> V_32 = V_47 = F_25 ( & V_15 -> V_44 , L_2 ) ;
if ( F_26 ( V_47 ) )
return F_27 ( V_47 ) ;
V_5 -> V_33 = V_47 = F_25 ( & V_15 -> V_44 , L_3 ) ;
if ( F_26 ( V_47 ) )
return F_27 ( V_47 ) ;
V_5 -> V_35 = V_49 = F_28 ( & V_15 -> V_44 , L_4 ) ;
if ( F_26 ( V_49 ) )
return F_27 ( V_49 ) ;
V_5 -> V_37 = V_49 = F_28 ( & V_15 -> V_44 , L_5 ) ;
if ( F_26 ( V_49 ) )
return F_27 ( V_49 ) ;
V_5 -> V_42 = V_42 = F_29 ( & V_15 -> V_44 , L_6 ) ;
if ( F_26 ( V_42 ) ) {
if ( F_27 ( V_42 ) == - V_55 )
return F_27 ( V_42 ) ;
V_5 -> V_42 = NULL ;
}
V_5 -> V_1 = F_30 ( & V_15 -> V_44 , V_15 -> V_44 . V_54 ,
& V_56 ) ;
if ( F_26 ( V_5 -> V_1 ) )
return F_27 ( V_5 -> V_1 ) ;
V_5 -> V_8 = F_31 ( & V_15 -> V_44 , 0 ) ;
if ( F_26 ( V_5 -> V_8 ) ) {
if ( F_27 ( V_5 -> V_8 ) != - V_57 )
return F_27 ( V_5 -> V_8 ) ;
V_5 -> V_8 = NULL ;
}
V_5 -> V_27 . V_58 = F_6 ;
F_32 ( V_5 -> V_1 , V_5 ) ;
V_46 = F_33 ( & V_15 -> V_44 , V_59 ) ;
return F_34 ( V_46 ) ;
}
