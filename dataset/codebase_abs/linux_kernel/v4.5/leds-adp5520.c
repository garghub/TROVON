static int F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
struct V_5 * V_6 ;
V_6 = F_2 ( V_2 , struct V_5 , V_7 ) ;
return F_3 ( V_6 -> V_8 , V_9 + V_6 -> V_10 - 1 ,
V_4 >> 2 ) ;
}
static int F_4 ( struct V_5 * V_6 )
{
struct V_11 * V_12 = V_6 -> V_8 ;
int V_13 = V_6 -> V_13 ;
int V_14 = 0 ;
switch ( V_6 -> V_10 ) {
case V_15 :
V_14 |= F_5 ( V_12 , V_16 ,
( V_13 >> V_17 ) &
V_18 ) ;
V_14 |= F_5 ( V_12 , V_19 ,
V_20 ) ;
break;
case V_21 :
V_14 |= F_5 ( V_12 , V_16 ,
( ( V_13 >> V_17 ) &
V_18 ) << 2 ) ;
V_14 |= F_6 ( V_12 , V_19 ,
V_22 ) ;
V_14 |= F_5 ( V_12 , V_19 ,
V_23 ) ;
break;
case V_24 :
V_14 |= F_5 ( V_12 , V_16 ,
( ( V_13 >> V_17 ) &
V_18 ) << 4 ) ;
V_14 |= F_6 ( V_12 , V_19 ,
V_25 ) ;
V_14 |= F_5 ( V_12 , V_19 ,
V_26 ) ;
break;
}
return V_14 ;
}
static int F_7 ( struct V_27 * V_28 )
{
struct V_29 * V_30 = F_8 ( & V_28 -> V_12 ) ;
struct V_11 * V_12 = V_28 -> V_12 . V_31 ;
int V_14 = 0 ;
V_14 |= F_3 ( V_12 , V_9 , 0 ) ;
V_14 |= F_3 ( V_12 , V_32 , 0 ) ;
V_14 |= F_3 ( V_12 , V_33 , 0 ) ;
V_14 |= F_3 ( V_12 , V_16 , V_30 -> V_34 << 6 ) ;
V_14 |= F_3 ( V_12 , V_35 , F_9 ( V_30 -> V_36 ,
V_30 -> V_37 ) ) ;
return V_14 ;
}
static int F_10 ( struct V_27 * V_28 )
{
struct V_29 * V_30 = F_8 ( & V_28 -> V_12 ) ;
struct V_5 * V_6 , * V_38 ;
struct V_39 * V_40 ;
int V_14 , V_41 ;
if ( V_30 == NULL ) {
F_11 ( & V_28 -> V_12 , L_1 ) ;
return - V_42 ;
}
if ( V_30 -> V_43 > V_44 ) {
F_11 ( & V_28 -> V_12 , L_2 ,
V_44 ) ;
return - V_45 ;
}
V_6 = F_12 ( & V_28 -> V_12 , sizeof( * V_6 ) * V_30 -> V_43 ,
V_46 ) ;
if ( ! V_6 )
return - V_47 ;
V_14 = F_7 ( V_28 ) ;
if ( V_14 ) {
F_11 ( & V_28 -> V_12 , L_3 ) ;
return V_14 ;
}
for ( V_41 = 0 ; V_41 < V_30 -> V_43 ; ++ V_41 ) {
V_40 = & V_30 -> V_48 [ V_41 ] ;
V_38 = & V_6 [ V_41 ] ;
V_38 -> V_7 . V_49 = V_40 -> V_49 ;
V_38 -> V_7 . V_50 = V_40 -> V_50 ;
V_38 -> V_7 . V_51 = F_1 ;
V_38 -> V_7 . V_52 = V_53 ;
if ( V_40 -> V_13 & V_54 )
V_38 -> V_13 = V_40 -> V_13 ;
else
V_38 -> V_13 = V_41 + 1 ;
V_38 -> V_10 = V_38 -> V_13 & V_54 ;
V_38 -> V_8 = V_28 -> V_12 . V_31 ;
V_14 = F_13 ( V_38 -> V_8 , & V_38 -> V_7 ) ;
if ( V_14 ) {
F_11 ( & V_28 -> V_12 , L_4 ,
V_38 -> V_10 ) ;
goto V_55;
}
V_14 = F_4 ( V_38 ) ;
if ( V_14 ) {
F_11 ( & V_28 -> V_12 , L_3 ) ;
V_41 ++ ;
goto V_55;
}
}
F_14 ( V_28 , V_6 ) ;
return 0 ;
V_55:
if ( V_41 > 0 ) {
for ( V_41 = V_41 - 1 ; V_41 >= 0 ; V_41 -- )
F_15 ( & V_6 [ V_41 ] . V_7 ) ;
}
return V_14 ;
}
static int F_16 ( struct V_27 * V_28 )
{
struct V_29 * V_30 = F_8 ( & V_28 -> V_12 ) ;
struct V_5 * V_6 ;
int V_41 ;
V_6 = F_17 ( V_28 ) ;
F_6 ( V_6 -> V_8 , V_19 ,
V_20 | V_23 | V_26 ) ;
for ( V_41 = 0 ; V_41 < V_30 -> V_43 ; V_41 ++ ) {
F_15 ( & V_6 [ V_41 ] . V_7 ) ;
}
return 0 ;
}
