static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 , int V_5 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_10 = V_7 -> V_10 ;
int V_11 ;
V_11 = F_2 ( V_10 , & V_3 , 1 , V_4 , V_5 ) ;
if ( V_11 < 0 )
F_3 ( & V_10 -> V_12 , L_1 , V_11 , V_3 ) ;
return V_11 ;
}
static void F_4 ( struct V_1 * V_2 , unsigned int V_13 , T_1 * V_14 )
{
V_14 [ 1 ] = V_13 >> ( V_2 -> V_15 * 8 - 8 ) ;
V_14 [ 2 ] = V_13 >> ( V_2 -> V_15 * 8 - 16 ) ;
V_14 [ 3 ] = V_13 >> ( V_2 -> V_15 * 8 - 24 ) ;
V_14 [ 4 ] = V_13 >> ( V_2 -> V_15 * 8 - 32 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
return 1 + V_2 -> V_15 ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_16 , T_1 * V_17 , int V_5 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_10 = V_7 -> V_10 ;
V_7 -> V_18 [ 0 ] = V_16 ;
if ( V_17 )
memcpy ( & V_7 -> V_18 [ 1 ] , V_17 , V_5 ) ;
return F_7 ( V_10 , V_7 -> V_18 , V_5 + 1 ) ;
}
static T_2 F_8 ( struct V_1 * V_2 , T_3 V_19 , T_4 V_5 ,
const T_5 * V_17 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_10 = V_7 -> V_10 ;
unsigned int V_20 , V_21 , V_22 , V_23 ;
struct V_24 V_25 [ 3 ] = {} ;
struct V_26 V_27 ;
int V_28 = F_5 ( V_2 ) ;
T_2 V_11 ;
V_20 = F_9 ( V_2 -> V_29 ) ;
V_21 = F_10 ( V_2 -> V_29 ) ;
V_22 = F_11 ( V_2 -> V_29 ) ;
F_12 ( & V_27 ) ;
if ( V_2 -> V_30 == V_31 && V_2 -> V_32 )
V_28 = 1 ;
V_7 -> V_18 [ 0 ] = V_2 -> V_30 ;
F_4 ( V_2 , V_19 , V_7 -> V_18 ) ;
V_25 [ 0 ] . V_33 = V_7 -> V_18 ;
V_25 [ 0 ] . V_34 = V_20 ;
V_25 [ 0 ] . V_5 = V_28 ;
F_13 ( & V_25 [ 0 ] , & V_27 ) ;
V_23 = 1 ;
if ( V_21 != V_20 ) {
V_25 [ 0 ] . V_5 = 1 ;
V_25 [ 1 ] . V_33 = & V_7 -> V_18 [ 1 ] ;
V_25 [ 1 ] . V_34 = V_21 ;
V_25 [ 1 ] . V_5 = V_28 - 1 ;
F_13 ( & V_25 [ 1 ] , & V_27 ) ;
V_23 = 2 ;
}
V_25 [ V_23 ] . V_33 = V_17 ;
V_25 [ V_23 ] . V_34 = V_22 ;
V_25 [ V_23 ] . V_5 = V_5 ;
F_13 ( & V_25 [ V_23 ] , & V_27 ) ;
V_11 = F_14 ( V_10 , & V_27 ) ;
if ( V_11 )
return V_11 ;
V_11 = V_27 . V_35 - V_28 ;
if ( V_11 < 0 )
return - V_36 ;
return V_11 ;
}
static T_2 F_15 ( struct V_1 * V_2 , T_3 V_37 , T_4 V_5 ,
T_5 * V_17 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_10 = V_7 -> V_10 ;
unsigned int V_20 , V_21 , V_22 , V_23 ;
struct V_24 V_25 [ 3 ] ;
struct V_26 V_27 ;
unsigned int V_38 = V_2 -> V_39 ;
T_2 V_11 ;
int V_28 ;
V_20 = F_9 ( V_2 -> V_40 ) ;
V_21 = F_10 ( V_2 -> V_40 ) ;
V_22 = F_11 ( V_2 -> V_40 ) ;
V_38 = ( V_38 * V_21 ) / 8 ;
if ( F_16 ( V_10 ) ) {
struct V_41 V_42 ;
memset ( & V_42 , 0 , sizeof( V_42 ) ) ;
V_42 . V_17 = V_17 ;
V_42 . V_37 = V_37 ;
V_42 . V_5 = V_5 ;
V_42 . V_43 = V_2 -> V_43 ;
V_42 . V_15 = V_2 -> V_15 ;
V_42 . V_44 = V_38 ;
V_42 . V_45 = V_20 ;
V_42 . V_21 = V_21 ;
V_42 . V_22 = V_22 ;
V_11 = F_17 ( V_10 , & V_42 ) ;
if ( V_11 < 0 )
return V_11 ;
return V_42 . V_46 ;
}
F_12 ( & V_27 ) ;
memset ( V_25 , 0 , ( sizeof V_25 ) ) ;
V_7 -> V_18 [ 0 ] = V_2 -> V_43 ;
F_4 ( V_2 , V_37 , V_7 -> V_18 ) ;
V_25 [ 0 ] . V_33 = V_7 -> V_18 ;
V_25 [ 0 ] . V_34 = V_20 ;
V_25 [ 0 ] . V_5 = F_5 ( V_2 ) + V_38 ;
F_13 ( & V_25 [ 0 ] , & V_27 ) ;
V_28 = V_25 [ 0 ] . V_5 ;
memset ( V_7 -> V_18 + V_28 - V_38 , 0xff , V_38 ) ;
V_23 = 1 ;
if ( V_21 != V_20 ) {
V_25 [ 0 ] . V_5 = 1 ;
V_25 [ 1 ] . V_33 = & V_7 -> V_18 [ 1 ] ;
V_25 [ 1 ] . V_34 = V_21 ;
V_25 [ 1 ] . V_5 = V_28 - 1 ;
F_13 ( & V_25 [ 1 ] , & V_27 ) ;
V_23 = 2 ;
}
V_25 [ V_23 ] . V_47 = V_17 ;
V_25 [ V_23 ] . V_48 = V_22 ;
V_25 [ V_23 ] . V_5 = F_18 ( V_5 , F_19 ( V_10 ) ,
F_20 ( V_10 ) - V_28 ) ;
F_13 ( & V_25 [ V_23 ] , & V_27 ) ;
V_11 = F_14 ( V_10 , & V_27 ) ;
if ( V_11 )
return V_11 ;
V_11 = V_27 . V_35 - V_28 ;
if ( V_11 < 0 )
return - V_36 ;
return V_11 ;
}
static int F_21 ( struct V_9 * V_10 )
{
struct V_49 * V_50 ;
struct V_6 * V_7 ;
struct V_1 * V_2 ;
struct V_51 V_52 = {
. V_53 = V_54 |
V_55 |
V_56 ,
} ;
char * V_57 ;
int V_11 ;
V_50 = F_22 ( & V_10 -> V_12 ) ;
V_7 = F_23 ( & V_10 -> V_12 , sizeof( * V_7 ) , V_58 ) ;
if ( ! V_7 )
return - V_59 ;
V_2 = & V_7 -> V_1 ;
V_2 -> V_60 = F_15 ;
V_2 -> V_61 = F_8 ;
V_2 -> V_62 = F_6 ;
V_2 -> V_63 = F_1 ;
V_2 -> V_12 = & V_10 -> V_12 ;
F_24 ( V_2 , V_10 -> V_12 . V_64 ) ;
V_2 -> V_8 = V_7 ;
F_25 ( V_10 , V_7 ) ;
V_7 -> V_10 = V_10 ;
if ( V_10 -> V_65 & V_66 ) {
V_52 . V_53 |= V_67 ;
if ( V_10 -> V_65 & V_68 )
V_52 . V_53 |= ( V_69 |
V_70 |
V_71 ) ;
} else if ( V_10 -> V_65 & V_72 ) {
V_52 . V_53 |= V_73 ;
if ( V_10 -> V_65 & V_74 )
V_52 . V_53 |= V_75 ;
}
if ( V_50 && V_50 -> V_76 )
V_2 -> V_77 . V_76 = V_50 -> V_76 ;
if ( V_50 && V_50 -> type )
V_57 = V_50 -> type ;
else if ( ! strcmp ( V_10 -> V_78 , L_2 ) )
V_57 = NULL ;
else
V_57 = V_10 -> V_78 ;
V_11 = F_26 ( V_2 , V_57 , & V_52 ) ;
if ( V_11 )
return V_11 ;
return F_27 ( & V_2 -> V_77 , V_50 ? V_50 -> V_79 : NULL ,
V_50 ? V_50 -> V_80 : 0 ) ;
}
static int F_28 ( struct V_9 * V_10 )
{
struct V_6 * V_7 = F_29 ( V_10 ) ;
return F_30 ( & V_7 -> V_1 . V_77 ) ;
}
