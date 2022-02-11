static int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 , void * V_4 )
{
if ( V_3 == V_5 )
V_6 . V_7 = V_8 ;
return V_9 ;
}
static int F_2 ( struct V_10 * V_11 ,
unsigned int V_12 )
{
unsigned int V_13 , V_14 ;
V_13 = V_11 -> V_15 ;
V_14 = V_11 -> V_16 [ V_12 ] . V_17 ;
F_3 ( V_18 . V_19 , L_1 , V_13 , V_14 ) ;
F_4 ( V_11 -> V_20 , V_18 . V_21 ) ;
F_5 ( F_6 ( V_22 ) | V_23 | V_24 ,
V_22 ) ;
F_5 ( F_6 ( V_22 ) & ~ ( V_23 | V_24 ) ,
V_22 ) ;
F_7 ( V_18 . V_25 , V_14 * 1000 ) ;
F_4 ( V_11 -> V_20 , V_18 . V_25 ) ;
return 0 ;
}
static int F_8 ( struct V_10 * V_11 )
{
struct V_26 * V_27 ;
unsigned int V_28 , V_29 ;
int V_30 , V_31 , V_32 ;
V_28 = F_9 ( V_18 . V_33 ) / 1000 ;
V_30 = 1 << V_34 ;
V_27 = F_10 ( sizeof( * V_27 ) * V_30 , V_35 ) ;
if ( ! V_27 ) {
F_11 ( V_18 . V_19 ,
L_2 ) ;
V_32 = - V_36 ;
goto V_37;
}
for ( V_31 = 0 ; V_31 < ( V_30 - 1 ) ; V_31 ++ ) {
V_29 = V_28 / ( V_31 + 1 ) ;
if ( ( V_29 < V_18 . V_38 ) ||
( V_29 > V_18 . V_39 ) )
V_27 [ V_31 ] . V_17 = V_40 ;
else
V_27 [ V_31 ] . V_17 = V_29 ;
F_3 ( V_18 . V_19 ,
L_3 , V_31 ,
V_27 [ V_31 ] . V_17 ) ;
}
V_27 [ V_31 ] . V_17 = V_41 ;
V_11 -> V_20 = V_18 . V_20 ;
V_32 = F_12 ( V_11 , V_27 , 0 ) ;
if ( V_32 )
F_13 ( V_27 ) ;
V_37:
return V_32 ;
}
static int F_14 ( struct V_10 * V_11 )
{
F_13 ( V_11 -> V_16 ) ;
return 0 ;
}
static int F_15 ( struct V_42 * V_43 )
{
F_16 ( & V_44 ,
V_45 ) ;
F_17 ( & V_46 ) ;
return 0 ;
}
static int F_18 ( struct V_42 * V_43 )
{
struct V_47 * V_48 = V_43 -> V_19 . V_49 ;
struct V_20 * V_20 ;
int V_32 ;
if ( ! V_48 || ! V_48 -> V_50 || ! V_48 -> V_51 )
return - V_52 ;
V_18 . V_19 = & V_43 -> V_19 ;
V_20 = F_19 ( & V_43 -> V_19 , V_48 -> V_50 ) ;
if ( F_20 ( V_20 ) ) {
F_11 ( V_18 . V_19 , L_4 ,
V_48 -> V_50 ) ;
V_32 = F_21 ( V_20 ) ;
goto V_37;
}
V_18 . V_20 = V_20 ;
V_20 = F_22 ( V_20 ) ;
if ( F_20 ( V_20 ) ) {
F_11 ( V_18 . V_19 , L_5 ,
F_23 ( V_18 . V_20 ) ) ;
V_32 = F_21 ( V_20 ) ;
goto V_37;
}
V_18 . V_25 = V_20 ;
V_20 = F_22 ( V_20 ) ;
if ( F_20 ( V_20 ) ) {
F_11 ( V_18 . V_19 , L_5 ,
F_23 ( V_18 . V_25 ) ) ;
V_32 = F_21 ( V_20 ) ;
goto V_37;
}
V_18 . V_33 = V_20 ;
V_20 = F_19 ( & V_43 -> V_19 , V_48 -> V_51 ) ;
if ( F_20 ( V_20 ) ) {
F_11 ( V_18 . V_19 , L_4 ,
V_48 -> V_51 ) ;
V_32 = F_21 ( V_20 ) ;
goto V_37;
}
V_18 . V_21 = V_20 ;
V_18 . V_39 = V_48 -> V_39 ;
V_18 . V_38 = V_48 -> V_38 ;
V_32 = F_24 ( & V_46 ) ;
if ( V_32 ) {
F_11 ( V_18 . V_19 ,
L_6 , V_32 ) ;
goto V_37;
}
V_32 = F_25 ( & V_44 ,
V_45 ) ;
if ( ! V_32 )
goto V_37;
F_11 ( V_18 . V_19 , L_7 ,
V_32 ) ;
F_17 ( & V_46 ) ;
V_37:
return V_32 ;
}
