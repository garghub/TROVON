static T_1 int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
void T_2 * V_7 ;
int V_8 ;
V_4 = F_2 ( & V_2 -> V_9 , 1 ) ;
if ( ! V_4 ) {
V_8 = - V_10 ;
goto V_11;
}
V_7 = F_3 ( & V_2 -> V_9 , V_12 , 0x1000 ) ;
if ( ! V_7 ) {
V_8 = - V_10 ;
goto V_11;
}
V_8 = F_4 ( V_13 ,
F_5 ( V_13 ) ) ;
if ( V_8 )
goto V_11;
F_6 ( V_14 , 0 ) ;
F_7 ( 30 ) ;
F_6 ( V_14 , 1 ) ;
F_7 ( 30 ) ;
V_6 = V_4 -> V_15 [ 0 ] ;
V_6 -> V_16 = & V_17 ;
V_6 -> V_18 = V_19 ;
V_6 -> V_20 |= V_21 ;
V_6 -> V_22 . V_23 = V_7 + 0x10 ;
V_6 -> V_22 . V_24 = V_7 + 0xe ;
V_6 -> V_22 . V_25 = V_7 + 0xe ;
F_8 ( & V_6 -> V_22 ) ;
V_8 = F_9 ( V_4 , 0 , NULL , V_26 ,
& V_27 ) ;
if ( V_8 )
goto V_28;
return V_8 ;
V_28:
F_10 ( V_13 , F_5 ( V_13 ) ) ;
V_11:
return V_8 ;
}
static T_3 int F_11 ( struct V_1 * V_9 )
{
struct V_3 * V_4 = F_12 ( V_9 ) ;
F_13 ( V_4 ) ;
F_6 ( V_29 , 0 ) ;
F_10 ( V_13 , F_5 ( V_13 ) ) ;
return 0 ;
}
