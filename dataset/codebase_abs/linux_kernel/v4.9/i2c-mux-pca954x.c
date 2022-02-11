static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_1 V_5 )
{
int V_6 = - V_7 ;
if ( V_2 -> V_8 -> V_9 ) {
struct V_10 V_11 ;
char V_12 [ 1 ] ;
V_11 . V_13 = V_4 -> V_13 ;
V_11 . V_14 = 0 ;
V_11 . V_15 = 1 ;
V_12 [ 0 ] = V_5 ;
V_11 . V_12 = V_12 ;
V_6 = F_2 ( V_2 , & V_11 , 1 ) ;
} else {
union V_16 V_17 ;
V_6 = V_2 -> V_8 -> V_18 ( V_2 , V_4 -> V_13 ,
V_4 -> V_14 ,
V_19 ,
V_5 , V_20 , & V_17 ) ;
}
return V_6 ;
}
static int F_3 ( struct V_21 * V_22 , T_2 V_23 )
{
struct V_24 * V_17 = F_4 ( V_22 ) ;
struct V_3 * V_4 = V_17 -> V_4 ;
const struct V_25 * V_26 = V_17 -> V_26 ;
T_1 V_27 ;
int V_6 = 0 ;
if ( V_26 -> V_28 == V_29 )
V_27 = V_23 | V_26 -> V_30 ;
else
V_27 = 1 << V_23 ;
if ( V_17 -> V_31 != V_27 ) {
V_6 = F_1 ( V_22 -> V_32 , V_4 , V_27 ) ;
V_17 -> V_31 = V_6 ? 0 : V_27 ;
}
return V_6 ;
}
static int F_5 ( struct V_21 * V_22 , T_2 V_23 )
{
struct V_24 * V_17 = F_4 ( V_22 ) ;
struct V_3 * V_4 = V_17 -> V_4 ;
if ( ! ( V_17 -> V_33 & ( 1 << V_23 ) ) )
return 0 ;
V_17 -> V_31 = 0 ;
return F_1 ( V_22 -> V_32 , V_4 , V_17 -> V_31 ) ;
}
static int F_6 ( struct V_3 * V_4 ,
const struct V_34 * V_35 )
{
struct V_1 * V_2 = F_7 ( V_4 -> V_36 . V_32 ) ;
struct V_37 * V_38 = F_8 ( & V_4 -> V_36 ) ;
struct V_39 * V_40 = V_4 -> V_36 . V_40 ;
bool V_41 ;
struct V_42 * V_43 ;
int V_44 , V_45 , V_46 ;
struct V_21 * V_22 ;
struct V_24 * V_17 ;
const struct V_47 * V_48 ;
int V_6 ;
if ( ! F_9 ( V_2 , V_49 ) )
return - V_7 ;
V_22 = F_10 ( V_2 , & V_4 -> V_36 ,
V_50 , sizeof( * V_17 ) , 0 ,
F_3 , F_5 ) ;
if ( ! V_22 )
return - V_51 ;
V_17 = F_4 ( V_22 ) ;
F_11 ( V_4 , V_22 ) ;
V_17 -> V_4 = V_4 ;
V_43 = F_12 ( & V_4 -> V_36 , L_1 , V_52 ) ;
if ( F_13 ( V_43 ) )
return F_14 ( V_43 ) ;
if ( F_15 ( V_4 , 0 ) < 0 ) {
F_16 ( & V_4 -> V_36 , L_2 ) ;
return - V_7 ;
}
V_48 = F_17 ( F_18 ( V_53 ) , & V_4 -> V_36 ) ;
if ( V_48 )
V_17 -> V_26 = F_19 ( & V_4 -> V_36 ) ;
else
V_17 -> V_26 = & V_54 [ V_35 -> V_55 ] ;
V_17 -> V_31 = 0 ;
V_41 = V_40 &&
F_20 ( V_40 , L_3 ) ;
for ( V_44 = 0 ; V_44 < V_17 -> V_26 -> V_56 ; V_44 ++ ) {
bool V_57 = false ;
V_45 = 0 ;
V_46 = 0 ;
if ( V_38 ) {
if ( V_44 < V_38 -> V_58 ) {
V_45 = V_38 -> V_59 [ V_44 ] . V_60 ;
V_46 = V_38 -> V_59 [ V_44 ] . V_46 ;
} else
break;
V_57 = V_38 -> V_59 [ V_44 ] . V_61 ;
}
V_17 -> V_33 |= ( V_57 ||
V_41 ) << V_44 ;
V_6 = F_21 ( V_22 , V_45 , V_44 , V_46 ) ;
if ( V_6 ) {
F_22 ( & V_4 -> V_36 ,
L_4
L_5 , V_44 , V_45 ) ;
goto V_62;
}
}
F_23 ( & V_4 -> V_36 ,
L_6 ,
V_44 , V_17 -> V_26 -> V_28 == V_29
? L_7 : L_8 , V_4 -> V_63 ) ;
return 0 ;
V_62:
F_24 ( V_22 ) ;
return V_6 ;
}
static int F_25 ( struct V_3 * V_4 )
{
struct V_21 * V_22 = F_26 ( V_4 ) ;
F_24 ( V_22 ) ;
return 0 ;
}
static int F_27 ( struct V_64 * V_36 )
{
struct V_3 * V_4 = F_28 ( V_36 ) ;
struct V_21 * V_22 = F_26 ( V_4 ) ;
struct V_24 * V_17 = F_4 ( V_22 ) ;
V_17 -> V_31 = 0 ;
return F_15 ( V_4 , 0 ) ;
}
