static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 . V_8 ;
T_1 V_9 = 0 ;
T_1 V_10 = 0 ;
T_1 V_11 = 0 ;
if ( ! V_4 -> V_12 ) {
V_4 -> V_12 = F_2 ( sizeof( struct V_13 ) , V_14 ) ;
if ( ! V_4 -> V_12 )
return - V_15 ;
}
V_4 -> V_12 -> V_16 = F_3 ( V_6 , L_1 ) ;
if ( F_4 ( V_6 , L_2 ,
& V_4 -> V_12 -> V_17 ) ) {
V_4 -> V_12 -> V_17 = 1 ;
} else {
V_4 -> V_12 -> V_17 -- ;
}
if ( F_4 ( V_6 , L_3 ,
& V_4 -> V_12 -> V_18 ) ) {
V_4 -> V_12 -> V_18 = 1 ;
} else {
V_4 -> V_12 -> V_18 -- ;
}
F_4 ( V_6 , L_4 , & V_9 ) ;
for ( V_10 = 0 ; V_10 < 7 ; V_10 ++ ) {
if ( V_9 & ( 1 << V_10 ) ) {
switch ( V_10 ) {
case 0 :
V_4 -> V_12 -> V_19 [ V_11 ] = 4 ; break;
case 1 :
V_4 -> V_12 -> V_19 [ V_11 ] = 8 ; break;
case 2 :
V_4 -> V_12 -> V_19 [ V_11 ] = 16 ; break;
case 3 :
V_4 -> V_12 -> V_19 [ V_11 ] = 32 ; break;
case 4 :
V_4 -> V_12 -> V_19 [ V_11 ] = 64 ; break;
case 5 :
V_4 -> V_12 -> V_19 [ V_11 ] = 128 ; break;
case 6 :
V_4 -> V_12 -> V_19 [ V_11 ] = 256 ; break;
default:
break;
}
V_11 ++ ;
}
}
V_4 -> V_20 = 1 ;
V_4 -> V_21 -> V_22 = 1 ;
V_4 -> V_23 = 1 ;
V_4 -> V_24 = 1 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_25 V_26 ;
struct V_27 * V_28 ;
int V_29 ;
memset ( & V_26 , 0 , sizeof( struct V_25 ) ) ;
V_26 . V_30 = F_6 ( V_2 , 0 ) ;
if ( V_26 . V_30 < 0 ) {
if ( V_26 . V_30 != - V_31 )
F_7 ( & V_2 -> V_7 ,
L_5 ) ;
return V_26 . V_30 ;
}
V_26 . V_32 = V_26 . V_30 ;
V_28 = F_8 ( V_2 , V_33 , 0 ) ;
V_26 . V_34 = F_9 ( & V_2 -> V_7 , V_28 ) ;
if ( F_10 ( V_26 . V_34 ) )
return F_11 ( V_26 . V_34 ) ;
V_4 = F_12 ( V_2 , & V_26 . V_35 ) ;
if ( F_10 ( V_4 ) )
return F_11 ( V_4 ) ;
V_4 -> V_36 = F_13 ( & V_2 -> V_7 , L_6 ) ;
if ( F_10 ( V_4 -> V_36 ) ) {
F_7 ( & V_2 -> V_7 , L_7 ) ;
V_29 = F_11 ( V_4 -> V_36 ) ;
V_4 -> V_36 = NULL ;
goto V_37;
}
F_14 ( V_4 -> V_36 ) ;
V_4 -> V_38 = F_13 ( & V_2 -> V_7 , L_8 ) ;
if ( F_10 ( V_4 -> V_38 ) ) {
F_7 ( & V_2 -> V_7 , L_9 ) ;
V_29 = F_11 ( V_4 -> V_38 ) ;
V_4 -> V_38 = NULL ;
goto V_39;
}
F_14 ( V_4 -> V_38 ) ;
V_29 = F_1 ( V_2 , V_4 ) ;
if ( V_29 )
goto V_40;
V_29 = F_15 ( & V_2 -> V_7 , V_4 , & V_26 ) ;
if ( V_29 )
goto V_40;
return 0 ;
V_40:
F_16 ( V_4 -> V_38 ) ;
V_39:
F_16 ( V_4 -> V_36 ) ;
V_37:
F_17 ( V_2 , V_4 ) ;
return V_29 ;
}
static int F_18 ( struct V_1 * V_2 )
{
return F_19 ( V_2 ) ;
}
