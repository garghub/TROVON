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
if ( V_6 >= 0 && V_6 != 1 )
V_6 = - V_16 ;
} else {
union V_17 V_18 ;
V_6 = V_2 -> V_8 -> V_19 ( V_2 , V_4 -> V_13 ,
V_4 -> V_14 ,
V_20 ,
V_5 , V_21 , & V_18 ) ;
}
return V_6 ;
}
static int F_3 ( struct V_22 * V_23 , T_2 V_24 )
{
struct V_25 * V_18 = F_4 ( V_23 ) ;
struct V_3 * V_4 = V_18 -> V_4 ;
const struct V_26 * V_27 = V_18 -> V_27 ;
T_1 V_28 ;
int V_6 = 0 ;
if ( V_27 -> V_29 == V_30 )
V_28 = V_24 | V_27 -> V_31 ;
else
V_28 = 1 << V_24 ;
if ( V_18 -> V_32 != V_28 ) {
V_6 = F_1 ( V_23 -> V_33 , V_4 , V_28 ) ;
V_18 -> V_32 = V_6 < 0 ? 0 : V_28 ;
}
return V_6 ;
}
static int F_5 ( struct V_22 * V_23 , T_2 V_24 )
{
struct V_25 * V_18 = F_4 ( V_23 ) ;
struct V_3 * V_4 = V_18 -> V_4 ;
if ( ! ( V_18 -> V_34 & ( 1 << V_24 ) ) )
return 0 ;
V_18 -> V_32 = 0 ;
return F_1 ( V_23 -> V_33 , V_4 , V_18 -> V_32 ) ;
}
static int F_6 ( struct V_3 * V_4 ,
const struct V_35 * V_36 )
{
struct V_1 * V_2 = F_7 ( V_4 -> V_37 . V_33 ) ;
struct V_38 * V_39 = F_8 ( & V_4 -> V_37 ) ;
struct V_40 * V_41 = V_4 -> V_37 . V_41 ;
bool V_42 ;
struct V_43 * V_44 ;
int V_45 , V_46 , V_47 ;
struct V_22 * V_23 ;
struct V_25 * V_18 ;
const struct V_48 * V_49 ;
int V_6 ;
if ( ! F_9 ( V_2 , V_50 ) )
return - V_7 ;
V_23 = F_10 ( V_2 , & V_4 -> V_37 ,
V_51 , sizeof( * V_18 ) , 0 ,
F_3 , F_5 ) ;
if ( ! V_23 )
return - V_52 ;
V_18 = F_4 ( V_23 ) ;
F_11 ( V_4 , V_23 ) ;
V_18 -> V_4 = V_4 ;
V_44 = F_12 ( & V_4 -> V_37 , L_1 , V_53 ) ;
if ( F_13 ( V_44 ) )
return F_14 ( V_44 ) ;
if ( F_15 ( V_4 , 0 ) < 0 ) {
F_16 ( & V_4 -> V_37 , L_2 ) ;
return - V_7 ;
}
V_49 = F_17 ( F_18 ( V_54 ) , & V_4 -> V_37 ) ;
if ( V_49 )
V_18 -> V_27 = F_19 ( & V_4 -> V_37 ) ;
else if ( V_36 )
V_18 -> V_27 = & V_55 [ V_36 -> V_56 ] ;
else {
const struct V_57 * V_58 ;
V_58 = F_20 ( F_21 ( V_59 ) ,
& V_4 -> V_37 ) ;
if ( ! V_58 )
return - V_7 ;
V_18 -> V_27 = & V_55 [ V_58 -> V_56 ] ;
}
V_18 -> V_32 = 0 ;
V_42 = V_41 &&
F_22 ( V_41 , L_3 ) ;
for ( V_45 = 0 ; V_45 < V_18 -> V_27 -> V_60 ; V_45 ++ ) {
bool V_61 = false ;
V_46 = 0 ;
V_47 = 0 ;
if ( V_39 ) {
if ( V_45 < V_39 -> V_62 ) {
V_46 = V_39 -> V_63 [ V_45 ] . V_64 ;
V_47 = V_39 -> V_63 [ V_45 ] . V_47 ;
} else
break;
V_61 = V_39 -> V_63 [ V_45 ] . V_65 ;
}
V_18 -> V_34 |= ( V_61 ||
V_42 ) << V_45 ;
V_6 = F_23 ( V_23 , V_46 , V_45 , V_47 ) ;
if ( V_6 ) {
F_24 ( & V_4 -> V_37 ,
L_4
L_5 , V_45 , V_46 ) ;
goto V_66;
}
}
F_25 ( & V_4 -> V_37 ,
L_6 ,
V_45 , V_18 -> V_27 -> V_29 == V_30
? L_7 : L_8 , V_4 -> V_67 ) ;
return 0 ;
V_66:
F_26 ( V_23 ) ;
return V_6 ;
}
static int F_27 ( struct V_3 * V_4 )
{
struct V_22 * V_23 = F_28 ( V_4 ) ;
F_26 ( V_23 ) ;
return 0 ;
}
static int F_29 ( struct V_68 * V_37 )
{
struct V_3 * V_4 = F_30 ( V_37 ) ;
struct V_22 * V_23 = F_28 ( V_4 ) ;
struct V_25 * V_18 = F_4 ( V_23 ) ;
V_18 -> V_32 = 0 ;
return F_15 ( V_4 , 0 ) ;
}
