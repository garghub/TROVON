void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
V_1 -> V_4 = V_5 ;
F_3 ( V_1 , V_3 -> V_6 ) ;
}
int F_4 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
int V_7 , V_8 = 0 ;
if ( V_3 -> V_9 == V_10 )
V_1 -> V_11 = 1 ;
else
V_1 -> V_11 = 0 ;
V_1 -> V_12 = F_5 ( V_13 ) ;
if ( V_3 -> V_14 )
V_1 -> V_12 |= F_5 ( V_15 ) ;
if ( ! V_3 -> V_16 || V_17 )
V_1 -> V_12 |= F_5 ( V_18 ) ;
V_3 -> V_19 . V_20 = V_21 ;
V_3 -> V_19 . V_22 = F_6 ( V_21 ) ;
for ( V_7 = 0 ; V_7 < V_23 ; V_7 ++ ) {
if ( V_3 -> V_24 & ( 1 << V_7 ) ) {
V_3 -> V_8 [ V_7 ] . V_25 =
F_7 ( V_7 + 1 ,
V_26 ) ;
V_8 ++ ;
}
}
V_3 -> V_19 . V_8 = V_3 -> V_8 ;
V_3 -> V_19 . V_27 = V_8 ;
V_1 -> V_28 [ V_26 ] = & V_3 -> V_19 ;
V_1 -> V_29 = V_30 ;
V_7 = 0 ;
if ( V_3 -> V_31 ) {
V_3 -> V_32 [ V_7 ] = V_33 ;
V_7 ++ ;
if ( V_3 -> V_34 ) {
V_3 -> V_32 [ V_7 ] = V_35 ;
V_7 ++ ;
}
}
if ( V_3 -> V_36 ) {
V_3 -> V_32 [ V_7 ] = V_37 ;
V_7 ++ ;
}
V_1 -> V_32 = V_3 -> V_32 ;
V_1 -> V_38 = V_7 ;
V_1 -> V_39 = V_3 -> V_40 ;
if ( ! V_3 -> V_41 )
V_1 -> V_42 = V_3 -> V_43 + 1 ;
V_1 -> V_44 = V_3 -> V_45 ;
V_1 -> V_46 = V_3 -> V_47 ;
return F_8 ( V_1 ) ;
}
static int F_9 ( struct V_1 * V_1 , struct V_48 * V_6 ,
enum V_49 type ,
struct V_50 * V_51 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
int V_52 = 0 ;
unsigned long V_53 ;
if ( F_10 ( V_3 , & V_53 ) != 0 )
return - V_54 ;
switch ( type ) {
case V_15 :
if ( ! V_3 -> V_14 && ! V_3 -> V_55 )
V_52 = - V_56 ;
break;
case V_13 :
break;
case V_18 :
if ( V_3 -> V_16 && ! V_17 ) {
F_11 ( V_1 ,
L_1 ) ;
V_52 = - V_56 ;
}
break;
default:
V_52 = - V_56 ;
}
if ( ! V_52 ) {
V_3 -> V_57 = type ;
F_12 ( V_3 ) ;
V_52 = F_13 ( V_3 ) ;
}
F_14 ( V_3 , & V_53 ) ;
return V_52 ;
}
static int F_15 ( struct V_1 * V_1 ,
struct V_58 * V_59 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
int V_52 ;
if ( ! V_59 )
return - V_56 ;
if ( V_3 -> V_60 && V_3 -> V_60 != V_59 )
return - V_54 ;
V_3 -> V_60 = V_59 ;
V_52 = F_16 ( V_3 , V_59 -> V_61 ) ;
if ( V_52 )
V_3 -> V_60 = NULL ;
return V_52 ;
}
static int F_17 ( struct V_1 * V_1 ,
struct V_62 * V_63 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
int V_52 = 0 ;
unsigned long V_64 ;
int V_65 ;
if ( ! V_63 -> V_66 )
return - V_56 ;
if ( F_18 ( V_63 ) != V_67 )
return - V_56 ;
if ( V_63 -> V_66 -> V_19 != V_26 )
return - V_56 ;
V_65 = F_19 ( V_63 -> V_66 -> V_25 ) ;
if ( ( V_65 < 1 ) || ( V_65 > V_23 ) ||
! ( V_3 -> V_24 & ( 1 << ( V_65 - 1 ) ) ) )
return - V_56 ;
if ( F_10 ( V_3 , & V_64 ) != 0 )
return - V_54 ;
V_3 -> V_65 = V_65 ;
if ( V_3 -> V_57 == V_18 ) {
struct V_68 * V_69 = & V_3 -> V_69 ;
V_52 = V_69 -> V_70 -> V_71 ( V_69 , V_72 |
V_73 ,
V_65 , NULL ) ;
}
F_14 ( V_3 , & V_64 ) ;
return V_52 ;
}
static int F_20 ( struct V_1 * V_1 , T_1 V_74 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
int V_75 = - 1 ;
int V_76 = - 1 ;
int V_52 = 0 ;
if ( V_74 & V_77 ) {
V_52 = - V_56 ;
}
if ( V_74 & V_78 ) {
V_52 = - V_56 ;
}
if ( V_74 & V_79 ) {
if ( V_3 -> V_41 ) {
if ( V_1 -> V_42 == - 1 )
V_75 = 0 ;
else {
F_21 ( V_80 L_2
L_3
L_4 ,
V_3 -> V_81 -> V_82 ) ;
V_75 = 1 ;
}
} else {
if ( V_1 -> V_42 == - 1 )
V_75 = 2346 ;
else if ( ( V_1 -> V_42 < 257 ) ||
( V_1 -> V_42 > 2347 ) )
V_52 = - V_56 ;
else
V_75 = V_1 -> V_42 & ~ 0x1 ;
}
}
if ( V_74 & V_83 ) {
if ( V_1 -> V_39 == - 1 )
V_76 = 2347 ;
else if ( V_1 -> V_39 > 2347 )
V_52 = - V_56 ;
else
V_76 = V_1 -> V_39 ;
}
if ( ! V_52 ) {
unsigned long V_64 ;
if ( F_10 ( V_3 , & V_64 ) != 0 )
return - V_54 ;
if ( V_75 >= 0 ) {
if ( V_3 -> V_41 )
V_3 -> V_84 = V_75 ;
else
V_3 -> V_43 = V_75 ;
}
if ( V_76 >= 0 )
V_3 -> V_40 = V_76 ;
V_52 = F_13 ( V_3 ) ;
F_14 ( V_3 , & V_64 ) ;
}
return V_52 ;
}
