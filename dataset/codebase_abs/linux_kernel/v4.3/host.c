static int F_1 ( struct V_1 * V_2 , int V_3 , bool V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = (struct V_7 * ) V_6 -> V_8 ;
struct V_9 * V_10 = V_2 -> V_11 . V_12 ;
struct V_13 * V_14 = F_3 ( V_10 ) ;
int V_15 = 0 ;
int V_16 = F_4 ( V_6 -> V_17 ) ;
if ( V_8 -> V_18 ) {
if ( V_16 > 1 ) {
F_5 ( V_10 ,
L_1 ) ;
return 0 ;
}
if ( V_4 )
V_15 = F_6 ( V_8 -> V_18 ) ;
else
V_15 = F_7 ( V_8 -> V_18 ) ;
if ( V_15 ) {
F_8 ( V_10 ,
L_2 ,
V_4 ? L_3 : L_4 , V_15 ) ;
return V_15 ;
}
}
if ( V_4 && ( V_14 -> V_19 -> V_20 == V_21 ) ) {
F_9 ( V_14 , 5 ) ;
F_9 ( V_14 , 0 ) ;
}
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_11 . V_12 ;
struct V_13 * V_14 = F_3 ( V_10 ) ;
int V_15 ;
V_15 = F_11 ( V_2 ) ;
if ( V_15 )
return V_15 ;
F_12 ( V_14 ) ;
return V_15 ;
}
static T_1 F_13 ( struct V_13 * V_14 )
{
return F_14 ( V_14 -> V_22 , V_14 -> V_2 ) ;
}
static int F_15 ( struct V_13 * V_14 )
{
struct V_1 * V_2 ;
struct V_5 * V_6 ;
struct V_7 * V_8 ;
int V_15 ;
if ( F_16 () )
return - V_23 ;
V_2 = F_17 ( & V_24 , V_14 -> V_10 , F_18 ( V_14 -> V_10 ) ) ;
if ( ! V_2 )
return - V_25 ;
F_19 ( V_14 -> V_10 , V_14 ) ;
V_2 -> V_26 = V_14 -> V_27 . V_28 ;
V_2 -> V_29 = V_14 -> V_27 . V_30 ;
V_2 -> V_31 = V_14 -> V_27 . abs ;
V_2 -> V_32 = 1 ;
V_2 -> V_33 = V_14 -> V_19 -> V_33 ;
V_2 -> V_34 = V_14 -> V_19 -> V_34 ;
if ( V_14 -> V_35 )
V_2 -> V_35 = V_14 -> V_35 ;
else
V_2 -> V_36 = V_14 -> V_36 ;
V_6 = F_2 ( V_2 ) ;
V_6 -> V_37 = V_14 -> V_27 . V_38 ;
V_6 -> V_39 = V_14 -> V_27 . V_40 ;
V_6 -> V_41 = V_14 -> V_27 . V_40 ;
V_6 -> V_42 = V_14 -> V_42 ;
V_8 = (struct V_7 * ) V_6 -> V_8 ;
V_8 -> V_18 = NULL ;
if ( V_14 -> V_19 -> V_18 && ! F_20 ( V_14 ) ) {
if ( V_14 -> V_19 -> V_43 & V_44 ) {
V_15 = F_6 ( V_14 -> V_19 -> V_18 ) ;
if ( V_15 ) {
F_8 ( V_14 -> V_10 ,
L_5 ,
V_15 ) ;
goto V_45;
}
} else {
V_8 -> V_18 = V_14 -> V_19 -> V_18 ;
}
}
V_15 = F_21 ( V_2 , 0 , 0 ) ;
if ( V_15 ) {
goto V_46;
} else {
struct V_47 * V_48 = & V_14 -> V_48 ;
V_14 -> V_2 = V_2 ;
if ( F_20 ( V_14 ) ) {
V_48 -> V_49 = & V_2 -> V_11 ;
V_2 -> V_11 . V_50 = 1 ;
}
}
return V_15 ;
V_46:
if ( V_14 -> V_19 -> V_18 && ! F_20 ( V_14 ) &&
( V_14 -> V_19 -> V_43 & V_44 ) )
F_7 ( V_14 -> V_19 -> V_18 ) ;
V_45:
F_22 ( V_2 ) ;
return V_15 ;
}
static void F_23 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = V_14 -> V_2 ;
if ( V_2 ) {
F_24 ( V_2 ) ;
F_22 ( V_2 ) ;
if ( V_14 -> V_19 -> V_18 && ! F_20 ( V_14 ) &&
( V_14 -> V_19 -> V_43 & V_44 ) )
F_7 ( V_14 -> V_19 -> V_18 ) ;
}
}
void F_25 ( struct V_13 * V_14 )
{
if ( V_14 -> V_51 == V_52 && V_14 -> V_2 )
F_23 ( V_14 ) ;
}
static int F_26 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_16 ;
T_2 V_53 ;
int V_15 = F_27 ( V_2 ) ;
if ( V_15 )
return V_15 ;
V_16 = F_4 ( V_6 -> V_17 ) ;
while ( V_16 -- ) {
T_2 T_3 * V_54 = & V_6 -> V_31 -> V_55 [ V_16 ] ;
T_2 V_56 = F_28 ( V_6 , V_54 ) ;
if ( V_56 & V_57 ) {
V_53 = F_28 ( V_6 , & V_6 -> V_31 -> V_58 ) ;
V_53 |= V_59 ;
F_29 ( V_6 , V_53 , & V_6 -> V_31 -> V_58 ) ;
F_30 ( 150 , 200 ) ;
break;
}
}
return 0 ;
}
int F_31 ( struct V_13 * V_14 )
{
struct V_60 * V_61 ;
if ( ! F_32 ( V_14 , V_62 , V_63 ) )
return - V_64 ;
V_61 = F_33 ( V_14 -> V_10 , sizeof( struct V_60 ) , V_65 ) ;
if ( ! V_61 )
return - V_25 ;
V_61 -> V_66 = F_15 ;
V_61 -> V_67 = F_23 ;
V_61 -> V_22 = F_13 ;
V_61 -> V_68 = L_6 ;
V_14 -> V_69 [ V_52 ] = V_61 ;
return 0 ;
}
void F_34 ( void )
{
F_35 ( & V_24 , & V_70 ) ;
F_27 = V_24 . V_71 ;
V_24 . V_71 = F_26 ;
}
