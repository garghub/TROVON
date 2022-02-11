static int F_1 ( struct V_1 * V_2 , int V_3 , bool V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = (struct V_7 * ) V_6 -> V_8 ;
struct V_9 * V_10 = V_2 -> V_11 . V_12 ;
int V_13 = 0 ;
int V_14 = F_3 ( V_6 -> V_15 ) ;
if ( V_8 -> V_16 ) {
if ( V_14 > 1 ) {
F_4 ( V_10 ,
L_1 ) ;
return 0 ;
}
if ( V_4 )
V_13 = F_5 ( V_8 -> V_16 ) ;
else
V_13 = F_6 ( V_8 -> V_16 ) ;
if ( V_13 ) {
F_7 ( V_10 ,
L_2 ,
V_4 ? L_3 : L_4 , V_13 ) ;
return V_13 ;
}
}
return 0 ;
}
static T_1 F_8 ( struct V_17 * V_18 )
{
return F_9 ( V_18 -> V_19 , V_18 -> V_2 ) ;
}
static int F_10 ( struct V_17 * V_18 )
{
struct V_1 * V_2 ;
struct V_5 * V_6 ;
struct V_7 * V_8 ;
int V_13 ;
if ( F_11 () )
return - V_20 ;
V_2 = F_12 ( & V_21 , V_18 -> V_10 , F_13 ( V_18 -> V_10 ) ) ;
if ( ! V_2 )
return - V_22 ;
F_14 ( V_18 -> V_10 , V_18 ) ;
V_2 -> V_23 = V_18 -> V_24 . V_25 ;
V_2 -> V_26 = V_18 -> V_24 . V_27 ;
V_2 -> V_28 = V_18 -> V_24 . abs ;
V_2 -> V_29 = 1 ;
V_2 -> V_30 = V_18 -> V_31 -> V_30 ;
V_2 -> V_32 = V_18 -> V_31 -> V_32 ;
if ( V_18 -> V_33 )
V_2 -> V_33 = V_18 -> V_33 ;
else
V_2 -> V_34 = V_18 -> V_34 ;
V_6 = F_2 ( V_2 ) ;
V_6 -> V_35 = V_18 -> V_24 . V_36 ;
V_6 -> V_37 = V_18 -> V_24 . V_38 ;
V_6 -> V_39 = V_18 -> V_24 . V_38 ;
V_6 -> V_40 = V_18 -> V_40 ;
V_8 = (struct V_7 * ) V_6 -> V_8 ;
V_8 -> V_16 = NULL ;
if ( V_18 -> V_31 -> V_16 && ! F_15 ( V_18 ) ) {
if ( V_18 -> V_31 -> V_41 & V_42 ) {
V_13 = F_5 ( V_18 -> V_31 -> V_16 ) ;
if ( V_13 ) {
F_7 ( V_18 -> V_10 ,
L_5 ,
V_13 ) ;
goto V_43;
}
} else {
V_8 -> V_16 = V_18 -> V_31 -> V_16 ;
}
}
V_13 = F_16 ( V_2 , 0 , 0 ) ;
if ( V_13 ) {
goto V_44;
} else {
struct V_45 * V_46 = & V_18 -> V_46 ;
V_18 -> V_2 = V_2 ;
if ( F_15 ( V_18 ) ) {
V_46 -> V_47 = & V_2 -> V_11 ;
V_2 -> V_11 . V_48 = 1 ;
}
}
if ( V_18 -> V_31 -> V_41 & V_49 )
F_17 ( V_18 , V_50 , V_51 , V_51 ) ;
if ( V_18 -> V_31 -> V_41 & V_52 )
F_17 ( V_18 , V_53 , V_54 , V_54 ) ;
return V_13 ;
V_44:
if ( V_18 -> V_31 -> V_16 && ! F_15 ( V_18 ) &&
( V_18 -> V_31 -> V_41 & V_42 ) )
F_6 ( V_18 -> V_31 -> V_16 ) ;
V_43:
F_18 ( V_2 ) ;
return V_13 ;
}
static void F_19 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = V_18 -> V_2 ;
if ( V_2 ) {
F_20 ( V_2 ) ;
F_18 ( V_2 ) ;
if ( V_18 -> V_31 -> V_16 && ! F_15 ( V_18 ) &&
( V_18 -> V_31 -> V_41 & V_42 ) )
F_6 ( V_18 -> V_31 -> V_16 ) ;
}
}
void F_21 ( struct V_17 * V_18 )
{
if ( V_18 -> V_55 == V_56 && V_18 -> V_2 )
F_19 ( V_18 ) ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_14 ;
T_2 V_57 ;
int V_13 = F_23 ( V_2 ) ;
if ( V_13 )
return V_13 ;
V_14 = F_3 ( V_6 -> V_15 ) ;
while ( V_14 -- ) {
T_2 T_3 * V_58 = & V_6 -> V_28 -> V_59 [ V_14 ] ;
T_2 V_60 = F_24 ( V_6 , V_58 ) ;
if ( V_60 & V_61 ) {
V_57 = F_24 ( V_6 , & V_6 -> V_28 -> V_62 ) ;
V_57 |= V_63 ;
F_25 ( V_6 , V_57 , & V_6 -> V_28 -> V_62 ) ;
F_26 ( 150 , 200 ) ;
break;
}
}
return 0 ;
}
int F_27 ( struct V_17 * V_18 )
{
struct V_64 * V_65 ;
if ( ! F_28 ( V_18 , V_66 , V_67 ) )
return - V_68 ;
V_65 = F_29 ( V_18 -> V_10 , sizeof( struct V_64 ) , V_69 ) ;
if ( ! V_65 )
return - V_22 ;
V_65 -> V_70 = F_10 ;
V_65 -> V_71 = F_19 ;
V_65 -> V_19 = F_8 ;
V_65 -> V_72 = L_6 ;
V_18 -> V_73 [ V_56 ] = V_65 ;
F_30 ( & V_21 , & V_74 ) ;
F_23 = V_21 . V_75 ;
V_21 . V_75 = F_22 ;
return 0 ;
}
