static int F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_6 = V_5 -> V_6 ;
int V_7 = ! V_5 -> V_8 && V_3 ;
int V_9 = V_5 -> V_8 && ! V_3 ;
int V_10 ;
if ( V_7 ) {
V_10 = F_3 ( V_6 , V_5 -> V_11 ,
V_12 , V_12 ) ;
if ( V_10 < 0 )
goto V_13;
V_10 = F_3 ( V_6 , V_14 ,
V_15 , V_15 ) ;
if ( V_10 < 0 )
goto V_13;
}
if ( V_9 ) {
V_10 = F_3 ( V_6 , V_14 ,
V_15 , 0 ) ;
if ( V_10 < 0 )
goto V_13;
V_10 = F_3 ( V_6 , V_5 -> V_11 ,
V_16 | V_12 , 0 ) ;
if ( V_10 < 0 )
goto V_13;
}
V_10 = F_3 ( V_6 , V_5 -> V_11 ,
V_17 , V_3 ) ;
if ( V_10 < 0 )
goto V_13;
if ( V_7 ) {
V_10 = F_3 ( V_6 , V_5 -> V_11 ,
V_16 , V_16 ) ;
if ( V_10 < 0 )
return V_10 ;
}
V_5 -> V_8 = V_3 ;
return 0 ;
V_13:
if ( V_7 || V_9 ) {
F_3 ( V_6 , V_14 , V_15 , 0 ) ;
F_3 ( V_6 , V_5 -> V_11 , V_12 , 0 ) ;
}
return V_10 ;
}
static int F_4 ( struct V_1 * V_2 )
{
int V_3 = V_2 -> V_18 . V_3 ;
if ( V_2 -> V_18 . V_19 != V_20 )
V_3 = 0 ;
if ( V_2 -> V_18 . V_21 != V_20 )
V_3 = 0 ;
if ( V_2 -> V_18 . V_22 & V_23 )
V_3 = 0 ;
return F_1 ( V_2 , V_3 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
return V_5 -> V_8 ;
}
static int F_6 ( struct V_24 * V_25 )
{
struct V_6 * V_6 = F_7 ( V_25 -> V_26 . V_27 ) ;
struct V_28 * V_28 ;
struct V_29 * V_30 ;
struct V_4 * V_5 ;
struct V_1 * V_2 ;
struct V_31 V_18 ;
int V_10 , V_32 , V_33 , V_11 , V_34 ;
if ( V_25 -> V_26 . V_27 -> V_35 ) {
V_28 = V_25 -> V_26 . V_27 -> V_35 ;
V_30 = V_28 -> V_36 ;
} else {
V_30 = NULL ;
}
if ( ! V_30 ) {
F_8 ( & V_25 -> V_26 , L_1 ) ;
return - V_37 ;
}
for ( V_32 = 0 ; V_32 < V_38 ; V_32 ++ ) {
if ( V_39 [ V_32 ] > V_30 -> V_40 )
break;
}
if ( V_32 == 0 ) {
F_8 ( & V_25 -> V_26 , L_2 , V_30 -> V_40 ) ;
return - V_37 ;
}
V_33 = V_32 - 1 ;
if ( V_30 -> V_40 != V_39 [ V_33 ] )
F_9 ( & V_25 -> V_26 ,
L_3 ,
V_39 [ V_33 ] , V_30 -> V_40 ) ;
switch ( V_30 -> V_41 ) {
case 1 :
V_11 = V_42 ;
V_34 = 0 ;
break;
case 2 :
V_11 = V_43 ;
V_34 = V_44 ;
break;
default:
F_8 ( & V_25 -> V_26 , L_4 , V_30 -> V_41 ) ;
return - V_37 ;
}
V_10 = F_10 ( V_6 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_3 ( V_6 , V_45 , V_44 ,
V_34 ) ;
F_11 ( V_6 ) ;
if ( V_10 < 0 )
return V_10 ;
V_5 = F_12 ( sizeof( * V_5 ) , V_46 ) ;
if ( V_5 == NULL )
return - V_47 ;
V_5 -> V_6 = V_6 ;
V_5 -> V_8 = 0 ;
V_5 -> V_11 = V_11 ;
V_18 . type = V_48 ;
V_18 . V_49 = V_33 ;
V_2 = F_13 ( L_5 , & V_25 -> V_26 , V_5 ,
& V_50 , & V_18 ) ;
if ( F_14 ( V_2 ) ) {
F_8 ( & V_25 -> V_26 , L_6 ) ;
F_15 ( V_5 ) ;
return F_16 ( V_2 ) ;
}
V_2 -> V_18 . V_3 = V_33 ;
F_17 ( V_25 , V_2 ) ;
F_3 ( V_6 , V_14 , V_15 , 0 ) ;
F_18 ( V_2 ) ;
return 0 ;
}
static int F_19 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = F_20 ( V_25 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_21 ( V_2 ) ;
F_15 ( V_5 ) ;
return 0 ;
}
