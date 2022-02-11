static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
if ( V_2 != NULL )
V_4 = & V_2 -> V_4 ;
else
return;
if ( V_4 -> V_5 -> V_6 != NULL )
V_4 -> V_5 -> V_6 ( V_2 ) ;
if ( V_7 ) {
if ( F_2 ( & V_2 -> V_4 . V_8 ) )
return;
if ( F_3 ( V_4 ) < 0 )
F_4 ( V_9 , L_1 ) ;
F_5 ( & V_2 -> V_4 . V_8 ) ;
}
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_10 = - V_11 ;
if ( V_2 != NULL )
V_4 = & V_2 -> V_4 ;
else
return V_10 ;
if ( V_4 -> V_5 -> V_12 != NULL )
V_10 = V_4 -> V_5 -> V_12 ( V_2 ) ;
if ( V_7 ) {
if ( F_2 ( & V_2 -> V_4 . V_8 ) )
return - V_11 ;
V_10 = F_7 ( V_4 ) ;
F_5 ( & V_2 -> V_4 . V_8 ) ;
}
return V_10 ;
}
static int F_8 ( struct V_1 * V_2 ,
int V_13 , T_1 V_14 , int V_15 ) {
struct V_3 * V_4 = & V_2 -> V_4 ;
int V_10 = - V_11 ;
F_9 () ;
if ( F_2 ( & V_2 -> V_4 . V_8 ) ) {
F_4 ( V_9 , L_2 ) ;
return - V_16 ;
}
switch ( V_15 ) {
case 0 :
V_10 = F_10 ( V_4 , ( V_17 ) V_14 ) ;
F_4 ( V_9 , L_3 ,
V_13 , V_14 , V_10 ) ;
break;
case 1 :
{
struct V_18 V_19 ;
V_19 . type = V_20 ;
V_19 . V_21 = 0xFF ;
V_19 . V_14 = V_14 ;
V_10 = F_11 ( V_4 , & V_19 ) ;
F_4 ( V_9 , L_4 ,
V_13 , V_19 . V_21 , V_19 . V_14 , V_10 ) ;
break;
}
}
F_5 ( & V_2 -> V_4 . V_8 ) ;
F_12 () ;
return V_10 ;
}
static int F_13 ( struct V_22 * V_23 )
{
int V_10 = 0 ;
struct V_24 * V_25 = V_23 -> V_25 ;
struct V_1 * V_26 = V_25 -> V_27 ;
F_9 () ;
if ( F_2 ( & V_26 -> V_28 ) )
return - V_29 ;
if ( V_30 )
F_8 ( V_26 , V_23 -> V_13 ,
V_23 -> V_14 , 1 ) ;
if ( V_26 -> V_31 ++ == 0 )
V_10 = F_6 ( V_26 ) ;
F_5 ( & V_26 -> V_28 ) ;
F_12 () ;
return V_10 ;
}
static int F_14 ( struct V_22 * V_23 )
{
struct V_24 * V_25 = V_23 -> V_25 ;
struct V_1 * V_26 = V_25 -> V_27 ;
F_9 () ;
if ( F_2 ( & V_26 -> V_28 ) )
return - V_29 ;
if ( -- V_26 -> V_31 == 0 )
F_1 ( V_26 ) ;
if ( V_30 )
F_8 ( V_26 , V_23 -> V_13 ,
V_23 -> V_14 , 0 ) ;
F_5 ( & V_26 -> V_28 ) ;
F_12 () ;
return 0 ;
}
int F_15 ( struct V_1 * V_26 )
{
struct V_32 * V_2 = & V_26 -> V_4 . V_33 -> V_2 ;
int V_10 ;
V_10 = F_16 ( & V_26 -> V_34 ,
V_26 -> V_35 , V_36 ,
V_2 , V_37 ) ;
if ( V_10 < 0 ) {
F_17 ( V_2 , L_5 ,
V_38 , V_10 ) ;
return V_10 ;
}
V_26 -> V_39 . V_27 = V_26 ;
V_26 -> V_39 . V_40 = V_30 ? 16 : 256 ;
V_26 -> V_39 . V_41 = 256 ;
V_26 -> V_39 . V_42 = F_13 ;
V_26 -> V_39 . V_43 = F_14 ;
V_26 -> V_39 . V_44 . V_45 = V_46 |
V_47 ;
V_26 -> V_48 . V_40 = V_26 -> V_39 . V_40 ;
V_26 -> V_48 . V_25 = & V_26 -> V_39 . V_44 ;
V_26 -> V_48 . V_45 = 0 ;
V_10 = F_18 ( & V_26 -> V_39 ) ;
if ( V_10 < 0 ) {
F_17 ( V_2 , L_6 , V_38 , V_10 ) ;
goto V_49;
}
V_10 = F_19 ( & V_26 -> V_48 , & V_26 -> V_34 ) ;
if ( V_10 < 0 ) {
F_17 ( V_2 , L_7 ,
V_38 , V_10 ) ;
goto V_50;
}
V_10 = F_20 ( V_26 , & V_26 -> V_51 ) ;
if ( V_10 < 0 ) {
F_17 ( V_2 , L_8 ,
V_38 , V_10 ) ;
goto V_52;
}
F_21 ( & V_26 -> V_4 . V_8 ) ;
F_21 ( & V_26 -> V_28 ) ;
if ( V_53 )
F_22 ( F_23 ( & V_26 -> V_4 ) ,
L_9 ) ;
F_24 ( L_10 , V_26 -> V_35 ) ;
return 0 ;
V_52:
F_25 ( & V_26 -> V_48 ) ;
V_50:
F_26 ( & V_26 -> V_39 ) ;
V_49:
F_27 ( & V_26 -> V_34 ) ;
return V_10 ;
}
void F_28 ( struct V_1 * V_26 )
{
F_29 ( & V_26 -> V_51 ) ;
F_25 ( & V_26 -> V_48 ) ;
F_26 ( & V_26 -> V_39 ) ;
F_27 ( & V_26 -> V_34 ) ;
F_24 ( L_11 , V_26 -> V_35 ) ;
}
