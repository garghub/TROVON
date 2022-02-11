static void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = V_2 -> V_4 -> V_5 -> V_6
+ ( V_2 -> V_7 / 4 ) ;
T_1 V_8 ;
int V_9 = 2 * ( V_2 -> V_7 % 4 ) ;
T_1 V_10 = 0x3 << V_9 ;
F_2 ( & V_2 -> V_4 -> V_11 ) ;
V_8 = F_3 ( V_2 -> V_4 -> V_12 , V_3 ) ;
switch ( V_2 -> V_13 ) {
case V_14 :
F_4 ( V_2 -> V_4 -> V_12 , V_3 ,
( V_8 & ~ V_10 ) | ( V_15 << V_9 ) ) ;
break;
case V_16 :
F_4 ( V_2 -> V_4 -> V_12 , V_3 ,
V_8 & ~ V_10 ) ;
break;
default:
F_4 ( V_2 -> V_4 -> V_12 ,
V_17 + V_2 -> V_7 ,
V_2 -> V_13 ) ;
F_4 ( V_2 -> V_4 -> V_12 , V_3 ,
( V_8 & ~ V_10 ) | ( V_18 << V_9 ) ) ;
break;
}
F_5 ( & V_2 -> V_4 -> V_11 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
T_1 V_3 = V_2 -> V_4 -> V_5 -> V_6 +
( V_2 -> V_7 / 4 ) ;
T_1 V_8 ;
T_1 V_19 = F_3 ( V_2 -> V_4 -> V_12 ,
V_20 ) ;
int V_9 = 2 * ( V_2 -> V_7 % 4 ) ;
T_1 V_10 = 0x3 << V_9 ;
F_4 ( V_2 -> V_4 -> V_12 ,
V_2 -> V_4 -> V_5 -> V_21 , V_2 -> V_22 ) ;
F_4 ( V_2 -> V_4 -> V_12 ,
V_2 -> V_4 -> V_5 -> V_23 , V_2 -> V_24 ) ;
if ( ! ( V_19 & V_25 ) )
F_4 ( V_2 -> V_4 -> V_12 , V_20 ,
V_19 | V_25 ) ;
F_2 ( & V_2 -> V_4 -> V_11 ) ;
V_8 = F_3 ( V_2 -> V_4 -> V_12 , V_3 ) ;
if ( ( V_8 & V_10 ) != ( V_26 << V_9 ) )
F_4 ( V_2 -> V_4 -> V_12 , V_3 ,
( V_8 & ~ V_10 ) | ( V_26 << V_9 ) ) ;
F_5 ( & V_2 -> V_4 -> V_11 ) ;
}
static void F_7 ( struct V_27 * V_28 )
{
struct V_1 * V_2 = F_8 ( V_28 ,
struct V_1 , V_28 ) ;
switch ( V_2 -> V_29 ) {
case V_30 :
F_1 ( V_2 ) ;
break;
case V_31 :
F_6 ( V_2 ) ;
break;
}
}
static void F_9 ( struct V_32 * V_33 ,
enum V_34 V_35 )
{
struct V_1 * V_2 ;
V_2 = F_8 ( V_33 , struct V_1 , V_33 ) ;
V_2 -> V_29 = V_30 ;
V_2 -> V_13 = V_35 ;
F_10 ( & V_2 -> V_28 ) ;
}
static int F_11 ( struct V_32 * V_33 ,
unsigned long * V_36 , unsigned long * V_37 )
{
struct V_1 * V_2 ;
unsigned long V_38 , V_39 , V_40 ;
T_1 V_22 , V_24 ;
V_2 = F_8 ( V_33 , struct V_1 , V_33 ) ;
V_38 = * V_36 ;
V_39 = * V_37 ;
if ( ! V_38 && ! V_39 ) {
V_38 = 500 ;
V_39 = 500 ;
}
V_40 = V_38 + V_39 ;
if ( ( V_40 < V_41 ) ||
( V_40 > V_42 ) ) {
V_38 = 500 ;
V_39 = 500 ;
V_40 = V_38 + V_39 ;
}
V_22 = ( V_38 * 256 ) / V_40 ;
V_24 = ( V_40 * 24 / 1000 ) - 1 ;
V_2 -> V_29 = V_31 ;
V_2 -> V_22 = V_22 ;
V_2 -> V_24 = V_24 ;
F_10 ( & V_2 -> V_28 ) ;
* V_36 = V_38 ;
* V_37 = V_39 ;
return 0 ;
}
static struct V_43 *
F_12 ( struct V_44 * V_12 , struct V_45 * V_4 )
{
struct V_46 * V_47 = V_12 -> V_48 . V_49 , * V_50 ;
struct V_43 * V_51 ;
struct V_52 * V_53 ;
int V_54 ;
V_54 = F_13 ( V_47 ) ;
if ( ! V_54 || V_54 > V_4 -> V_55 )
return F_14 ( - V_56 ) ;
V_53 = F_15 ( & V_12 -> V_48 ,
sizeof( struct V_52 ) * V_4 -> V_55 , V_57 ) ;
if ( ! V_53 )
return F_14 ( - V_58 ) ;
F_16 (np, child) {
struct V_52 V_59 = {} ;
T_2 V_60 ;
int V_61 ;
V_61 = F_17 ( V_50 , L_1 , & V_60 ) ;
if ( ( V_61 != 0 ) || ( V_60 >= V_4 -> V_55 ) )
continue;
V_59 . V_62 =
F_18 ( V_50 , L_2 , NULL ) ? : V_50 -> V_62 ;
V_59 . V_63 =
F_18 ( V_50 , L_3 , NULL ) ;
V_53 [ V_60 ] = V_59 ;
}
V_51 = F_15 ( & V_12 -> V_48 ,
sizeof( struct V_43 ) , V_57 ) ;
if ( ! V_51 )
return F_14 ( - V_58 ) ;
V_51 -> V_64 . V_64 = V_53 ;
V_51 -> V_64 . V_65 = V_4 -> V_55 ;
if ( F_19 ( V_47 , L_4 ) )
V_51 -> V_66 = V_67 ;
else
V_51 -> V_66 = V_68 ;
if ( F_19 ( V_47 , L_5 ) )
V_51 -> V_69 = V_70 ;
else
V_51 -> V_69 = V_71 ;
return V_51 ;
}
static struct V_43 *
F_12 ( struct V_44 * V_12 , struct V_45 * V_4 )
{
return F_14 ( - V_56 ) ;
}
static int F_20 ( struct V_44 * V_12 ,
const struct V_72 * V_73 )
{
struct V_2 * V_74 ;
struct V_1 * V_2 ;
struct V_43 * V_51 ;
struct V_45 * V_4 ;
int V_75 , V_76 ;
V_4 = & V_77 [ V_73 -> V_78 ] ;
V_51 = F_21 ( & V_12 -> V_48 ) ;
if ( ! V_51 ) {
V_51 = F_12 ( V_12 , V_4 ) ;
if ( F_22 ( V_51 ) ) {
F_23 ( & V_12 -> V_48 , L_6 ) ;
V_51 = NULL ;
}
}
if ( V_51 && ( V_51 -> V_64 . V_65 < 1 ||
V_51 -> V_64 . V_65 > V_4 -> V_55 ) ) {
F_24 ( & V_12 -> V_48 , L_7 ,
V_4 -> V_55 ) ;
return - V_79 ;
}
V_74 = F_15 ( & V_12 -> V_48 , sizeof( * V_74 ) ,
V_57 ) ;
if ( ! V_74 )
return - V_58 ;
V_2 = F_15 ( & V_12 -> V_48 , V_4 -> V_55 * sizeof( * V_2 ) ,
V_57 ) ;
if ( ! V_2 )
return - V_58 ;
F_25 ( V_12 , V_74 ) ;
F_26 ( & V_74 -> V_11 ) ;
V_74 -> V_5 = V_4 ;
V_74 -> V_12 = V_12 ;
V_74 -> V_64 = V_2 ;
for ( V_75 = 0 ; V_75 < V_4 -> V_55 / 4 ; V_75 ++ )
F_4 ( V_12 , V_4 -> V_6 + V_75 , 0x00 ) ;
for ( V_75 = 0 ; V_75 < V_4 -> V_55 ; V_75 ++ ) {
V_2 [ V_75 ] . V_7 = V_75 ;
V_2 [ V_75 ] . V_4 = V_74 ;
if ( V_51 && V_75 < V_51 -> V_64 . V_65 ) {
if ( V_51 -> V_64 . V_64 [ V_75 ] . V_62 )
snprintf ( V_2 [ V_75 ] . V_62 ,
sizeof( V_2 [ V_75 ] . V_62 ) , L_8 ,
V_51 -> V_64 . V_64 [ V_75 ] . V_62 ) ;
if ( V_51 -> V_64 . V_64 [ V_75 ] . V_63 )
V_2 [ V_75 ] . V_33 . V_63 =
V_51 -> V_64 . V_64 [ V_75 ] . V_63 ;
}
if ( ! V_51 || V_75 >= V_51 -> V_64 . V_65 ||
! V_51 -> V_64 . V_64 [ V_75 ] . V_62 )
snprintf ( V_2 [ V_75 ] . V_62 , sizeof( V_2 [ V_75 ] . V_62 ) ,
L_9 , V_12 -> V_80 -> V_81 ,
V_12 -> V_82 , V_75 ) ;
V_2 [ V_75 ] . V_33 . V_62 = V_2 [ V_75 ] . V_62 ;
V_2 [ V_75 ] . V_33 . V_83 = F_9 ;
if ( V_51 && V_51 -> V_69 == V_70 )
V_2 [ V_75 ] . V_33 . V_84 = F_11 ;
F_27 ( & V_2 [ V_75 ] . V_28 , F_7 ) ;
V_76 = F_28 ( & V_12 -> V_48 , & V_2 [ V_75 ] . V_33 ) ;
if ( V_76 < 0 )
goto exit;
}
F_4 ( V_12 , V_85 , 0x00 ) ;
if ( V_51 ) {
if ( V_51 -> V_66 == V_68 )
F_4 ( V_12 , V_20 , 0x01 ) ;
else
F_4 ( V_12 , V_20 , 0x05 ) ;
}
return 0 ;
exit:
while ( V_75 -- ) {
F_29 ( & V_2 [ V_75 ] . V_33 ) ;
F_30 ( & V_2 [ V_75 ] . V_28 ) ;
}
return V_76 ;
}
static int F_31 ( struct V_44 * V_12 )
{
struct V_2 * V_2 = F_32 ( V_12 ) ;
int V_75 ;
for ( V_75 = 0 ; V_75 < V_2 -> V_5 -> V_55 ; V_75 ++ ) {
F_29 ( & V_2 -> V_64 [ V_75 ] . V_33 ) ;
F_30 ( & V_2 -> V_64 [ V_75 ] . V_28 ) ;
}
return 0 ;
}
