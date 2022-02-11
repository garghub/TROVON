static int F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_6 [ V_7 ] = { V_3 } ;
return V_5 -> V_8 ( V_2 , V_5 , V_9 ,
V_6 ) ;
}
static int F_3 ( struct V_4 * V_5 )
{
struct V_10 * V_11 = & V_5 -> V_12 ;
struct V_13 * V_14 = ( void * ) V_11 -> V_15 ;
if ( ! V_5 -> V_16 )
return 0 ;
if ( F_4 ( V_11 -> V_17 ) < 1 )
return 0 ;
V_5 -> V_18 = V_14 -> V_19 ;
V_5 -> V_20 = F_1 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , int V_21 ,
struct V_22 * V_23 )
{
if ( V_21 >= 4 )
return - V_24 ;
V_23 -> V_25 = ( V_21 * 16 ) + 8 ;
V_23 -> V_26 = 8 ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , int V_21 ,
struct V_22 * V_23 )
{
if ( V_21 >= 4 )
return - V_24 ;
V_23 -> V_25 = ( V_21 * 16 ) + 2 ;
V_23 -> V_26 = 6 ;
return 0 ;
}
static int F_7 ( struct V_4 * V_5 , bool V_27 )
{
T_1 V_6 [ V_7 ] = { 0 , } ;
if ( V_27 )
V_6 [ 0 ] |= V_28 ;
return V_5 -> V_8 ( F_8 ( V_5 ) , V_5 ,
V_29 , V_6 ) ;
}
static int
F_9 ( struct V_1 * V_2 , struct V_4 * V_5 ,
T_2 * V_30 , int V_31 ,
int V_32 )
{
int V_33 ;
int V_34 = 0 ;
F_7 ( V_5 , true ) ;
V_5 -> V_35 ( V_2 , V_36 , 0x00 , V_32 ) ;
V_5 -> V_35 ( V_2 , V_37 , - 1 , - 1 ) ;
V_33 = V_5 -> V_38 ( V_2 ) ;
if ( V_33 & V_39 )
V_2 -> V_40 . V_41 ++ ;
else if ( V_33 & V_42 )
V_34 = V_5 -> V_43 . V_44 ;
V_5 -> V_35 ( V_2 , V_36 , - 1 , - 1 ) ;
F_10 ( V_2 , V_5 , V_30 , V_31 , V_32 ) ;
F_7 ( V_5 , false ) ;
return V_34 ;
}
static int
F_11 ( struct V_1 * V_2 , struct V_4 * V_5 ,
const T_2 * V_30 , int V_31 ,
int V_32 )
{
int V_33 ;
F_7 ( V_5 , true ) ;
V_5 -> V_35 ( V_2 , V_45 , 0x00 , V_32 ) ;
F_12 ( V_2 , V_5 , V_30 , V_31 , V_32 ) ;
V_5 -> V_35 ( V_2 , V_46 , - 1 , - 1 ) ;
V_33 = V_5 -> V_47 ( V_2 , V_5 ) ;
F_7 ( V_5 , false ) ;
return V_33 & V_39 ? - V_48 : 0 ;
}
static int
F_13 ( struct V_1 * V_2 ,
struct V_4 * V_5 ,
T_2 * V_30 , int V_31 ,
int V_32 )
{
V_5 -> V_35 ( V_2 , V_36 , 0x00 , V_32 ) ;
F_10 ( V_2 , V_5 , V_30 , V_31 , V_32 ) ;
return 0 ;
}
static int
F_14 ( struct V_1 * V_2 ,
struct V_4 * V_5 ,
const T_2 * V_30 , int V_31 ,
int V_32 )
{
int V_33 ;
V_5 -> V_35 ( V_2 , V_45 , 0x00 , V_32 ) ;
F_12 ( V_2 , V_5 , V_30 , V_31 , V_32 ) ;
V_5 -> V_35 ( V_2 , V_46 , - 1 , - 1 ) ;
V_33 = V_5 -> V_47 ( V_2 , V_5 ) ;
return V_33 & V_39 ? - V_48 : 0 ;
}
static int F_15 ( struct V_4 * V_5 )
{
T_1 V_6 [ V_7 ] = { 0 , } ;
int V_49 ;
if ( V_5 -> V_16 == 0 )
return V_50 ;
if ( V_5 -> V_51 != 1 )
return V_50 ;
V_49 = F_7 ( V_5 , true ) ;
if ( V_49 )
return V_50 ;
V_5 -> V_52 ( F_8 ( V_5 ) , V_5 ,
V_29 , V_6 ) ;
if ( ( V_6 [ 0 ] & V_28 ) == 0 )
return V_50 ;
V_49 = F_7 ( V_5 , false ) ;
if ( V_49 )
return V_50 ;
V_5 -> V_52 ( F_8 ( V_5 ) , V_5 ,
V_29 , V_6 ) ;
if ( V_6 [ 0 ] & V_28 )
return V_53 ;
if ( V_5 -> V_12 . V_54 != 4 )
return V_50 ;
return V_55 ;
}
static int F_16 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_8 ( V_5 ) ;
int V_56 ;
int V_49 ;
V_49 = F_3 ( V_5 ) ;
if ( V_49 )
return V_49 ;
if ( V_2 -> V_57 == 2048 )
V_5 -> V_58 |= V_59 ;
V_56 = F_15 ( V_5 ) ;
if ( V_56 == V_53 ) {
F_17 ( L_1 ) ;
return - V_60 ;
}
if ( V_5 -> V_43 . V_61 == V_62 ) {
if ( V_56 == V_50 ) {
F_17 ( L_2 ) ;
return - V_60 ;
}
V_5 -> V_43 . V_63 = V_64 ;
V_5 -> V_43 . V_65 = 8 ;
V_5 -> V_43 . V_66 = 512 ;
V_5 -> V_43 . V_44 = 4 ;
V_5 -> V_43 . V_67 = V_68 ;
V_5 -> V_43 . V_69 = F_9 ;
V_5 -> V_43 . V_70 = F_11 ;
V_5 -> V_43 . V_71 =
F_13 ;
V_5 -> V_43 . V_72 =
F_14 ;
F_18 ( V_2 , & V_73 ) ;
}
return 0 ;
}
