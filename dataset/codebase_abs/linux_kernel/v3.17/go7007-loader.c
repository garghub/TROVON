static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_5 * V_6 ;
const struct V_7 * V_8 ;
T_1 V_9 , V_10 ;
const char * V_11 , * V_12 ;
int V_13 ;
int V_14 ;
V_6 = F_2 ( F_3 ( V_2 ) ) ;
if ( ! V_6 )
goto V_15;
if ( V_6 -> V_16 . V_17 != 1 ) {
F_4 ( & V_2 -> V_18 , L_1 ) ;
goto V_15;
}
V_9 = F_5 ( V_6 -> V_16 . V_19 ) ;
V_10 = F_5 ( V_6 -> V_16 . V_20 ) ;
for ( V_14 = 0 ; V_21 [ V_14 ] . V_22 ; V_14 ++ )
if ( V_21 [ V_14 ] . V_9 == V_9 &&
V_21 [ V_14 ] . V_10 == V_10 )
break;
if ( V_21 [ V_14 ] . V_22 == NULL )
goto V_15;
V_11 = V_21 [ V_14 ] . V_22 ;
V_12 = V_21 [ V_14 ] . V_23 ;
F_6 ( & V_2 -> V_18 , L_2 , V_11 ) ;
if ( F_7 ( & V_8 , V_11 , & V_6 -> V_18 ) ) {
F_4 ( & V_2 -> V_18 ,
L_3 , V_11 ) ;
goto V_15;
}
V_13 = F_8 ( V_6 , V_8 , V_24 ) ;
F_9 ( V_8 ) ;
if ( 0 != V_13 ) {
F_4 ( & V_2 -> V_18 , L_4 ) ;
goto V_15;
}
if ( V_12 == NULL )
return 0 ;
if ( F_7 ( & V_8 , V_12 , & V_6 -> V_18 ) ) {
F_4 ( & V_2 -> V_18 ,
L_3 , V_12 ) ;
goto V_15;
}
V_13 = F_8 ( V_6 , V_8 , V_24 ) ;
F_9 ( V_8 ) ;
if ( 0 != V_13 ) {
F_4 ( & V_2 -> V_18 , L_5 ) ;
goto V_15;
}
return 0 ;
V_15:
F_10 ( V_6 ) ;
F_4 ( & V_2 -> V_18 , L_6 ) ;
return - V_25 ;
}
static void F_11 ( struct V_1 * V_2 )
{
F_6 ( & V_2 -> V_18 , L_7 ) ;
F_10 ( F_3 ( V_2 ) ) ;
F_12 ( V_2 , NULL ) ;
}
