static int F_1 ( struct V_1 * V_2 , int V_3 , bool V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = (struct V_7 * ) V_6 -> V_8 ;
struct V_9 * V_10 = V_8 -> V_10 ;
struct V_11 * V_12 = V_2 -> V_13 . V_14 ;
int V_15 = 0 ;
int V_16 = F_3 ( V_6 -> V_17 ) ;
if ( V_8 -> V_18 ) {
if ( V_16 > 1 ) {
F_4 ( V_12 ,
L_1 ) ;
return 0 ;
}
if ( V_4 )
V_15 = F_5 ( V_8 -> V_18 ) ;
else
V_15 = F_6 ( V_8 -> V_18 ) ;
if ( V_15 ) {
F_7 ( V_12 ,
L_2 ,
V_4 ? L_3 : L_4 , V_15 ) ;
return V_15 ;
}
}
if ( V_4 && ( V_10 -> V_19 -> V_20 == V_21 ) ) {
F_8 ( V_10 , 5 ) ;
F_8 ( V_10 , 0 ) ;
}
return 0 ;
}
static T_1 F_9 ( struct V_9 * V_10 )
{
return F_10 ( V_10 -> V_22 , V_10 -> V_2 ) ;
}
static int F_11 ( struct V_9 * V_10 )
{
struct V_1 * V_2 ;
struct V_5 * V_6 ;
struct V_7 * V_8 ;
int V_15 ;
if ( F_12 () )
return - V_23 ;
V_2 = F_13 ( & V_24 , V_10 -> V_12 , F_14 ( V_10 -> V_12 ) ) ;
if ( ! V_2 )
return - V_25 ;
F_15 ( V_10 -> V_12 , V_10 ) ;
V_2 -> V_26 = V_10 -> V_27 . V_28 ;
V_2 -> V_29 = V_10 -> V_27 . V_30 ;
V_2 -> V_31 = V_10 -> V_27 . abs ;
V_2 -> V_32 = 1 ;
V_2 -> V_33 = V_10 -> V_19 -> V_33 ;
V_2 -> V_34 = V_10 -> V_19 -> V_34 ;
if ( V_10 -> V_35 )
V_2 -> V_35 = V_10 -> V_35 ;
else
V_2 -> V_36 = V_10 -> V_36 ;
V_6 = F_2 ( V_2 ) ;
V_6 -> V_37 = V_10 -> V_27 . V_38 ;
V_6 -> V_39 = V_10 -> V_27 . V_40 ;
V_6 -> V_41 = V_10 -> V_27 . V_40 ;
V_6 -> V_42 = V_10 -> V_42 ;
V_8 = (struct V_7 * ) V_6 -> V_8 ;
V_8 -> V_18 = NULL ;
V_8 -> V_10 = V_10 ;
if ( V_10 -> V_19 -> V_18 && ! F_16 ( V_10 ) ) {
if ( V_10 -> V_19 -> V_43 & V_44 ) {
V_15 = F_5 ( V_10 -> V_19 -> V_18 ) ;
if ( V_15 ) {
F_7 ( V_10 -> V_12 ,
L_5 ,
V_15 ) ;
goto V_45;
}
} else {
V_8 -> V_18 = V_10 -> V_19 -> V_18 ;
}
}
V_15 = F_17 ( V_2 , 0 , 0 ) ;
if ( V_15 ) {
goto V_46;
} else {
struct V_47 * V_48 = & V_10 -> V_48 ;
V_10 -> V_2 = V_2 ;
if ( F_16 ( V_10 ) ) {
V_48 -> V_49 = & V_2 -> V_13 ;
V_2 -> V_13 . V_50 = 1 ;
}
}
if ( V_10 -> V_19 -> V_43 & V_51 )
F_18 ( V_10 , V_52 , V_53 , V_53 ) ;
if ( V_10 -> V_19 -> V_43 & V_54 )
F_18 ( V_10 , V_55 , V_56 , V_56 ) ;
return V_15 ;
V_46:
if ( V_10 -> V_19 -> V_18 && ! F_16 ( V_10 ) &&
( V_10 -> V_19 -> V_43 & V_44 ) )
F_6 ( V_10 -> V_19 -> V_18 ) ;
V_45:
F_19 ( V_2 ) ;
return V_15 ;
}
static void F_20 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
if ( V_2 ) {
F_21 ( V_2 ) ;
F_19 ( V_2 ) ;
if ( V_10 -> V_19 -> V_18 && ! F_16 ( V_10 ) &&
( V_10 -> V_19 -> V_43 & V_44 ) )
F_6 ( V_10 -> V_19 -> V_18 ) ;
}
}
void F_22 ( struct V_9 * V_10 )
{
if ( V_10 -> V_57 == V_58 && V_10 -> V_2 )
F_20 ( V_10 ) ;
}
static int F_23 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_16 ;
T_2 V_59 ;
int V_15 = F_24 ( V_2 ) ;
if ( V_15 )
return V_15 ;
V_16 = F_3 ( V_6 -> V_17 ) ;
while ( V_16 -- ) {
T_2 T_3 * V_60 = & V_6 -> V_31 -> V_61 [ V_16 ] ;
T_2 V_62 = F_25 ( V_6 , V_60 ) ;
if ( V_62 & V_63 ) {
V_59 = F_25 ( V_6 , & V_6 -> V_31 -> V_64 ) ;
V_59 |= V_65 ;
F_26 ( V_6 , V_59 , & V_6 -> V_31 -> V_64 ) ;
F_27 ( 150 , 200 ) ;
break;
}
}
return 0 ;
}
int F_28 ( struct V_9 * V_10 )
{
struct V_66 * V_67 ;
if ( ! F_29 ( V_10 , V_68 , V_69 ) )
return - V_70 ;
V_67 = F_30 ( V_10 -> V_12 , sizeof( struct V_66 ) , V_71 ) ;
if ( ! V_67 )
return - V_25 ;
V_67 -> V_72 = F_11 ;
V_67 -> V_73 = F_20 ;
V_67 -> V_22 = F_9 ;
V_67 -> V_74 = L_6 ;
V_10 -> V_75 [ V_58 ] = V_67 ;
return 0 ;
}
void F_31 ( void )
{
F_32 ( & V_24 , & V_76 ) ;
F_24 = V_24 . V_77 ;
V_24 . V_77 = F_23 ;
}
