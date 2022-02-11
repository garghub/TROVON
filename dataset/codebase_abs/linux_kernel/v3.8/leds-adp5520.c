static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 , V_2 ) ;
F_3 ( V_4 -> V_5 , V_6 + V_4 -> V_7 - 1 ,
V_4 -> V_8 >> 2 ) ;
}
static void F_4 ( struct V_9 * V_10 ,
enum V_11 V_12 )
{
struct V_3 * V_4 ;
V_4 = F_2 ( V_10 , struct V_3 , V_13 ) ;
V_4 -> V_8 = V_12 ;
F_5 ( & V_4 -> V_2 ) ;
}
static int F_6 ( struct V_3 * V_4 )
{
struct V_14 * V_15 = V_4 -> V_5 ;
int V_16 = V_4 -> V_16 ;
int V_17 = 0 ;
switch ( V_4 -> V_7 ) {
case V_18 :
V_17 |= F_7 ( V_15 , V_19 ,
( V_16 >> V_20 ) &
V_21 ) ;
V_17 |= F_7 ( V_15 , V_22 ,
V_23 ) ;
break;
case V_24 :
V_17 |= F_7 ( V_15 , V_19 ,
( ( V_16 >> V_20 ) &
V_21 ) << 2 ) ;
V_17 |= F_8 ( V_15 , V_22 ,
V_25 ) ;
V_17 |= F_7 ( V_15 , V_22 ,
V_26 ) ;
break;
case V_27 :
V_17 |= F_7 ( V_15 , V_19 ,
( ( V_16 >> V_20 ) &
V_21 ) << 4 ) ;
V_17 |= F_8 ( V_15 , V_22 ,
V_28 ) ;
V_17 |= F_7 ( V_15 , V_22 ,
V_29 ) ;
break;
}
return V_17 ;
}
static int F_9 ( struct V_30 * V_31 )
{
struct V_32 * V_33 = V_31 -> V_15 . V_34 ;
struct V_14 * V_15 = V_31 -> V_15 . V_35 ;
int V_17 = 0 ;
V_17 |= F_3 ( V_15 , V_6 , 0 ) ;
V_17 |= F_3 ( V_15 , V_36 , 0 ) ;
V_17 |= F_3 ( V_15 , V_37 , 0 ) ;
V_17 |= F_3 ( V_15 , V_19 , V_33 -> V_38 << 6 ) ;
V_17 |= F_3 ( V_15 , V_39 , F_10 ( V_33 -> V_40 ,
V_33 -> V_41 ) ) ;
return V_17 ;
}
static int F_11 ( struct V_30 * V_31 )
{
struct V_32 * V_33 = V_31 -> V_15 . V_34 ;
struct V_3 * V_4 , * V_42 ;
struct V_43 * V_44 ;
int V_17 , V_45 ;
if ( V_33 == NULL ) {
F_12 ( & V_31 -> V_15 , L_1 ) ;
return - V_46 ;
}
if ( V_33 -> V_47 > V_48 ) {
F_12 ( & V_31 -> V_15 , L_2 ,
V_48 ) ;
return - V_49 ;
}
V_4 = F_13 ( & V_31 -> V_15 , sizeof( * V_4 ) * V_33 -> V_47 ,
V_50 ) ;
if ( V_4 == NULL ) {
F_12 ( & V_31 -> V_15 , L_3 ) ;
return - V_51 ;
}
V_17 = F_9 ( V_31 ) ;
if ( V_17 ) {
F_12 ( & V_31 -> V_15 , L_4 ) ;
return V_17 ;
}
for ( V_45 = 0 ; V_45 < V_33 -> V_47 ; ++ V_45 ) {
V_44 = & V_33 -> V_52 [ V_45 ] ;
V_42 = & V_4 [ V_45 ] ;
V_42 -> V_13 . V_53 = V_44 -> V_53 ;
V_42 -> V_13 . V_54 = V_44 -> V_54 ;
V_42 -> V_13 . V_55 = F_4 ;
V_42 -> V_13 . V_56 = V_57 ;
if ( V_44 -> V_16 & V_58 )
V_42 -> V_16 = V_44 -> V_16 ;
else
V_42 -> V_16 = V_45 + 1 ;
V_42 -> V_7 = V_42 -> V_16 & V_58 ;
V_42 -> V_5 = V_31 -> V_15 . V_35 ;
V_42 -> V_8 = V_57 ;
F_14 ( & V_42 -> V_2 , F_1 ) ;
V_17 = F_15 ( V_42 -> V_5 , & V_42 -> V_13 ) ;
if ( V_17 ) {
F_12 ( & V_31 -> V_15 , L_5 ,
V_42 -> V_7 ) ;
goto V_59;
}
V_17 = F_6 ( V_42 ) ;
if ( V_17 ) {
F_12 ( & V_31 -> V_15 , L_4 ) ;
V_45 ++ ;
goto V_59;
}
}
F_16 ( V_31 , V_4 ) ;
return 0 ;
V_59:
if ( V_45 > 0 ) {
for ( V_45 = V_45 - 1 ; V_45 >= 0 ; V_45 -- ) {
F_17 ( & V_4 [ V_45 ] . V_13 ) ;
F_18 ( & V_4 [ V_45 ] . V_2 ) ;
}
}
return V_17 ;
}
static int F_19 ( struct V_30 * V_31 )
{
struct V_32 * V_33 = V_31 -> V_15 . V_34 ;
struct V_3 * V_4 ;
int V_45 ;
V_4 = F_20 ( V_31 ) ;
F_8 ( V_4 -> V_5 , V_22 ,
V_23 | V_26 | V_29 ) ;
for ( V_45 = 0 ; V_45 < V_33 -> V_47 ; V_45 ++ ) {
F_17 ( & V_4 [ V_45 ] . V_13 ) ;
F_18 ( & V_4 [ V_45 ] . V_2 ) ;
}
return 0 ;
}
