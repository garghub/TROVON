static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
int V_11 ;
int V_12 ;
V_10 = F_2 ( & V_2 -> V_13 , sizeof( * V_10 ) , V_14 ) ;
if ( ! V_10 )
return - V_15 ;
F_3 ( V_2 , V_10 ) ;
V_11 = F_4 ( V_2 ) ;
if ( V_11 ) {
F_5 ( & V_2 -> V_13 , L_1 ) ;
F_3 ( V_2 , NULL ) ;
return V_11 ;
}
V_11 = F_6 ( V_2 , V_16 ) ;
if ( V_11 ) {
F_5 ( & V_2 -> V_13 , L_2 ) ;
goto V_17;
}
V_10 -> V_18 = F_7 ( V_2 , 0 , F_8 ( V_2 , 0 ) ) ;
if ( ! V_10 -> V_18 ) {
V_11 = - V_15 ;
goto V_19;
}
V_12 = 0 ;
F_9 (&pdev->dev, fwn) {
struct V_20 V_21 ;
struct V_22 * V_22 ;
struct V_23 * V_24 ;
union V_25 V_26 ;
V_6 = F_10 ( V_8 ) ;
if ( ! V_6 )
break;
V_11 = F_11 ( V_6 , 0 , & V_21 ) ;
if ( V_11 ) {
F_5 ( & V_2 -> V_13 ,
L_3 ,
V_6 -> V_27 ) ;
break;
}
V_22 = F_12 ( & V_2 -> V_13 , sizeof( * V_24 ) ) ;
if ( ! V_22 )
break;
V_24 = V_22 -> V_28 ;
V_24 -> V_22 = V_22 ;
V_10 -> V_29 [ V_12 ] = V_24 ;
V_12 ++ ;
V_24 -> V_30 = ( V_31 ) V_10 -> V_18 +
V_21 . V_32 - F_13 ( V_2 , 0 ) ;
V_26 . V_31 = 0 ;
V_26 . V_33 . V_34 = 1 ;
F_14 ( V_26 . V_31 , V_24 -> V_30 + V_35 ) ;
V_24 -> V_22 -> V_27 = V_16 ;
snprintf ( V_24 -> V_22 -> V_36 , V_37 , L_4 , V_21 . V_32 ) ;
V_24 -> V_22 -> V_38 = & V_2 -> V_13 ;
V_24 -> V_22 -> V_39 = V_40 ;
V_24 -> V_22 -> V_41 = V_42 ;
V_11 = F_15 ( V_24 -> V_22 , V_6 ) ;
if ( V_11 )
F_5 ( & V_2 -> V_13 , L_5 ) ;
F_16 ( & V_2 -> V_13 , L_6 , V_21 . V_32 ) ;
if ( V_12 >= F_17 ( V_10 -> V_29 ) )
break;
}
return 0 ;
V_19:
F_18 ( V_2 ) ;
V_17:
F_3 ( V_2 , NULL ) ;
return V_11 ;
}
static void F_19 ( struct V_1 * V_2 )
{
int V_12 ;
struct V_9 * V_10 = F_20 ( V_2 ) ;
for ( V_12 = 0 ; V_12 < F_17 ( V_10 -> V_29 ) ; V_12 ++ ) {
struct V_23 * V_24 = V_10 -> V_29 [ V_12 ] ;
if ( ! V_24 )
continue;
F_21 ( V_24 -> V_22 ) ;
F_22 ( V_24 -> V_22 ) ;
F_14 ( 0 , V_24 -> V_30 + V_35 ) ;
}
F_3 ( V_2 , NULL ) ;
}
