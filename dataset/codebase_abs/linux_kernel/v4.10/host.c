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
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_15 ;
V_15 = F_11 ( V_2 ) ;
if ( V_15 )
return V_15 ;
V_6 -> V_22 = 0 ;
F_12 ( V_14 ) ;
return V_15 ;
}
static T_1 F_13 ( struct V_13 * V_14 )
{
return F_14 ( V_14 -> V_23 , V_14 -> V_2 ) ;
}
static int F_15 ( struct V_13 * V_14 )
{
struct V_1 * V_2 ;
struct V_5 * V_6 ;
struct V_7 * V_8 ;
int V_15 ;
if ( F_16 () )
return - V_24 ;
V_2 = F_17 ( & V_25 , V_14 -> V_10 , F_18 ( V_14 -> V_10 ) ) ;
if ( ! V_2 )
return - V_26 ;
F_19 ( V_14 -> V_10 , V_14 ) ;
V_2 -> V_27 = V_14 -> V_28 . V_29 ;
V_2 -> V_30 = V_14 -> V_28 . V_31 ;
V_2 -> V_32 = V_14 -> V_28 . abs ;
V_2 -> V_33 = 1 ;
V_2 -> V_34 = V_14 -> V_19 -> V_34 ;
V_2 -> V_35 = V_14 -> V_19 -> V_35 ;
if ( V_14 -> V_36 )
V_2 -> V_36 = V_14 -> V_36 ;
else
V_2 -> V_37 = V_14 -> V_37 ;
V_6 = F_2 ( V_2 ) ;
V_6 -> V_38 = V_14 -> V_28 . V_39 ;
V_6 -> V_40 = V_14 -> V_28 . V_41 ;
V_6 -> V_42 = V_14 -> V_28 . V_41 ;
V_6 -> V_43 = V_14 -> V_43 ;
V_8 = (struct V_7 * ) V_6 -> V_8 ;
V_8 -> V_18 = NULL ;
if ( V_14 -> V_19 -> V_18 && ! F_20 ( V_14 ) ) {
if ( V_14 -> V_19 -> V_44 & V_45 ) {
V_15 = F_6 ( V_14 -> V_19 -> V_18 ) ;
if ( V_15 ) {
F_8 ( V_14 -> V_10 ,
L_5 ,
V_15 ) ;
goto V_46;
}
} else {
V_8 -> V_18 = V_14 -> V_19 -> V_18 ;
}
}
V_15 = F_21 ( V_2 , 0 , 0 ) ;
if ( V_15 ) {
goto V_47;
} else {
struct V_48 * V_49 = & V_14 -> V_49 ;
V_14 -> V_2 = V_2 ;
if ( F_20 ( V_14 ) ) {
V_49 -> V_50 = & V_2 -> V_11 ;
V_2 -> V_11 . V_51 = 1 ;
}
}
return V_15 ;
V_47:
if ( V_14 -> V_19 -> V_18 && ! F_20 ( V_14 ) &&
( V_14 -> V_19 -> V_44 & V_45 ) )
F_7 ( V_14 -> V_19 -> V_18 ) ;
V_46:
F_22 ( V_2 ) ;
return V_15 ;
}
static void F_23 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = V_14 -> V_2 ;
if ( V_2 ) {
F_24 ( V_2 ) ;
V_14 -> V_52 = V_53 ;
F_25 ( V_14 -> V_23 ) ;
F_22 ( V_2 ) ;
if ( V_14 -> V_19 -> V_18 && ! F_20 ( V_14 ) &&
( V_14 -> V_19 -> V_44 & V_45 ) )
F_7 ( V_14 -> V_19 -> V_18 ) ;
}
V_14 -> V_2 = NULL ;
V_14 -> V_49 . V_50 = NULL ;
}
void F_26 ( struct V_13 * V_14 )
{
if ( V_14 -> V_52 == V_54 && V_14 -> V_2 )
F_23 ( V_14 ) ;
}
static int F_27 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_16 ;
T_2 V_55 ;
int V_15 = F_28 ( V_2 ) ;
if ( V_15 )
return V_15 ;
V_16 = F_4 ( V_6 -> V_17 ) ;
while ( V_16 -- ) {
T_2 T_3 * V_56 = & V_6 -> V_32 -> V_57 [ V_16 ] ;
T_2 V_58 = F_29 ( V_6 , V_56 ) ;
if ( V_58 & V_59 ) {
V_55 = F_29 ( V_6 , & V_6 -> V_32 -> V_60 ) ;
V_55 |= V_61 ;
F_30 ( V_6 , V_55 , & V_6 -> V_32 -> V_60 ) ;
F_31 ( 150 , 200 ) ;
break;
}
}
return 0 ;
}
int F_32 ( struct V_13 * V_14 )
{
struct V_62 * V_63 ;
if ( ! F_33 ( V_14 , V_64 , V_65 ) )
return - V_66 ;
V_63 = F_34 ( V_14 -> V_10 , sizeof( struct V_62 ) , V_67 ) ;
if ( ! V_63 )
return - V_26 ;
V_63 -> V_68 = F_15 ;
V_63 -> V_69 = F_23 ;
V_63 -> V_23 = F_13 ;
V_63 -> V_70 = L_6 ;
V_14 -> V_71 [ V_54 ] = V_63 ;
return 0 ;
}
void F_35 ( void )
{
F_36 ( & V_25 , & V_72 ) ;
F_28 = V_25 . V_73 ;
V_25 . V_73 = F_27 ;
}
