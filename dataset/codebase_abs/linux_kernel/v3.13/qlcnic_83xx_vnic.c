int F_1 ( struct V_1 * V_2 , int V_3 )
{
if ( V_3 ) {
if ( F_2 ( V_2 ) )
return - V_4 ;
}
F_3 ( V_2 -> V_5 , V_6 , V_7 ) ;
if ( V_3 )
F_4 ( V_2 ) ;
return 0 ;
}
int F_5 ( struct V_1 * V_2 , int V_3 )
{
struct V_8 * V_5 = V_2 -> V_5 ;
if ( V_3 ) {
if ( F_2 ( V_2 ) )
return - V_4 ;
}
F_3 ( V_2 -> V_5 , V_6 , V_9 ) ;
V_5 -> V_10 . V_11 = V_9 ;
if ( V_3 )
F_4 ( V_2 ) ;
return 0 ;
}
int F_6 ( struct V_1 * V_2 )
{
T_1 V_12 ;
int V_13 = - V_4 ;
T_2 V_14 = V_15 ;
struct V_8 * V_5 = V_2 -> V_5 ;
if ( F_2 ( V_2 ) )
return V_13 ;
V_12 = V_5 -> V_16 ;
V_14 = F_7 ( V_2 -> V_5 , V_17 ) ;
V_14 = ( V_14 & ~ F_8 ( 0x3 , V_12 ) ) |
F_8 ( V_15 , V_12 ) ;
F_3 ( V_2 -> V_5 , V_17 , V_14 ) ;
F_4 ( V_2 ) ;
return 0 ;
}
static void
F_9 ( struct V_1 * V_2 )
{
struct V_8 * V_5 = V_2 -> V_5 ;
if ( V_5 -> V_18 == V_19 ) {
V_2 -> V_20 = V_21 ;
V_2 -> V_22 = V_23 ;
V_2 -> V_24 = V_25 ;
V_2 -> V_26 = V_25 ;
} else if ( V_5 -> V_18 == V_27 ) {
V_2 -> V_20 = V_28 ;
V_2 -> V_24 = V_29 ;
V_2 -> V_26 = V_29 ;
V_2 -> V_22 = V_30 ;
}
V_2 -> V_31 = V_32 ;
V_2 -> V_33 = V_34 ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_8 * V_5 = V_2 -> V_5 ;
struct V_35 * V_36 = & V_2 -> V_37 -> V_36 ;
struct V_38 * V_39 ;
int V_40 , V_41 = - V_42 ;
F_11 ( V_2 ) ;
if ( ! ( V_2 -> V_43 & V_44 ) ) {
if ( F_12 ( V_2 ) )
return V_41 ;
V_39 = V_2 -> V_45 ;
for ( V_40 = 0 ; V_40 < V_5 -> V_46 ; V_40 ++ , V_39 ++ ) {
F_13 ( V_36 , L_1 ,
V_39 -> V_16 , V_39 -> V_47 , V_39 -> type ,
V_39 -> V_48 , V_39 -> V_49 , V_39 -> V_50 ,
V_39 -> V_51 ) ;
}
F_13 ( V_36 , L_2 ,
V_5 -> V_52 , V_5 -> V_46 ) ;
if ( F_6 ( V_2 ) )
return V_41 ;
if ( F_14 ( V_2 ) )
return V_41 ;
} else {
if ( F_15 ( V_2 ) )
return V_41 ;
}
if ( F_16 ( V_2 ) )
return V_41 ;
F_9 ( V_2 ) ;
V_5 -> V_53 = V_54 ? 1 : 0 ;
V_2 -> V_43 |= V_44 ;
F_1 ( V_2 , 1 ) ;
F_13 ( V_36 , L_3 ,
V_5 -> V_55 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
int V_41 = - V_42 ;
F_11 ( V_2 ) ;
if ( F_16 ( V_2 ) )
return V_41 ;
F_9 ( V_2 ) ;
V_2 -> V_5 -> V_53 = ! ! V_54 ;
V_2 -> V_43 |= V_44 ;
F_13 ( & V_2 -> V_37 -> V_36 ,
L_4 ,
V_2 -> V_5 -> V_55 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 )
{
int V_41 = - V_42 ;
F_19 ( V_2 ) ;
if ( F_20 ( V_2 ) )
return V_41 ;
if ( F_16 ( V_2 ) )
return V_41 ;
F_9 ( V_2 ) ;
V_2 -> V_5 -> V_53 = ! ! V_54 ;
V_2 -> V_43 |= V_44 ;
F_13 ( & V_2 -> V_37 -> V_36 , L_5 ,
V_2 -> V_5 -> V_55 ) ;
return 0 ;
}
int F_21 ( struct V_1 * V_2 )
{
T_2 V_56 , V_57 ;
struct V_8 * V_5 = V_2 -> V_5 ;
struct V_58 * V_59 = V_2 -> V_59 ;
F_22 ( V_2 ) ;
V_56 = F_7 ( V_2 -> V_5 , V_17 ) ;
if ( V_56 == V_60 )
V_57 = V_15 ;
else
V_57 = F_23 ( V_56 ,
V_5 -> V_16 ) ;
switch ( V_57 ) {
case V_61 :
V_5 -> V_56 = V_61 ;
V_5 -> V_10 . V_62 = V_63 ;
V_59 -> V_64 = F_18 ;
break;
case V_65 :
V_5 -> V_56 = V_65 ;
V_5 -> V_10 . V_62 = V_66 ;
V_59 -> V_64 = F_17 ;
break;
case V_15 :
V_5 -> V_56 = V_15 ;
V_5 -> V_10 . V_62 = V_63 ;
V_59 -> V_64 = F_10 ;
break;
default:
F_24 ( & V_2 -> V_37 -> V_36 , L_6 ) ;
return - V_42 ;
}
if ( V_5 -> V_67 & V_68 )
V_2 -> V_43 |= V_69 ;
else
V_2 -> V_43 &= ~ V_69 ;
V_5 -> V_10 . V_11 = V_9 ;
V_5 -> V_10 . V_70 = V_71 ;
return 0 ;
}
int F_25 ( struct V_1 * V_2 )
{
struct V_8 * V_5 = V_2 -> V_5 ;
struct V_72 * V_10 = & V_5 -> V_10 ;
T_2 V_73 ;
V_73 = F_7 ( V_5 , V_6 ) ;
while ( V_73 != V_7 && V_10 -> V_70 -- ) {
F_26 ( 1000 ) ;
V_73 = F_7 ( V_5 , V_6 ) ;
}
if ( ! V_10 -> V_70 ) {
F_24 ( & V_2 -> V_37 -> V_36 ,
L_7 ) ;
return - V_42 ;
}
return 0 ;
}
int F_27 ( struct V_1 * V_2 ,
int V_74 , int * V_75 )
{
struct V_76 V_77 ;
int V_41 = 0 ;
memset ( & V_77 , 0 , sizeof( struct V_76 ) ) ;
V_41 = F_28 ( V_2 , & V_77 , V_74 ) ;
if ( V_41 )
return V_41 ;
if ( V_77 . V_67 & V_68 )
* V_75 = V_77 . V_78 ;
else
V_41 = - V_42 ;
if ( ! V_41 )
V_2 -> V_79 [ * V_75 ] . V_43 |= V_80 ;
return V_41 ;
}
