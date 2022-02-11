static int F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
T_1 V_5 = V_2 -> V_6 -> V_7 -> V_8
+ ( V_2 -> V_9 / 4 ) ;
T_1 V_10 ;
int V_11 = 2 * ( V_2 -> V_9 % 4 ) ;
T_1 V_12 = 0x3 << V_11 ;
int V_13 ;
F_2 ( & V_2 -> V_6 -> V_14 ) ;
V_10 = F_3 ( V_2 -> V_6 -> V_15 , V_5 ) ;
switch ( V_4 ) {
case V_16 :
V_13 = F_4 ( V_2 -> V_6 -> V_15 ,
V_5 ,
( V_10 & ~ V_12 ) | ( V_17 << V_11 ) ) ;
break;
case V_18 :
V_13 = F_4 ( V_2 -> V_6 -> V_15 ,
V_5 , V_10 & ~ V_12 ) ;
break;
default:
V_13 = F_4 ( V_2 -> V_6 -> V_15 ,
V_19 + V_2 -> V_9 ,
V_4 ) ;
if ( V_13 < 0 )
goto V_20;
V_13 = F_4 ( V_2 -> V_6 -> V_15 ,
V_5 ,
( V_10 & ~ V_12 ) | ( V_21 << V_11 ) ) ;
break;
}
V_20:
F_5 ( & V_2 -> V_6 -> V_14 ) ;
return V_13 ;
}
static void F_6 ( struct V_1 * V_2 )
{
T_1 V_5 = V_2 -> V_6 -> V_7 -> V_8 +
( V_2 -> V_9 / 4 ) ;
T_1 V_10 ;
T_1 V_22 = F_3 ( V_2 -> V_6 -> V_15 ,
V_23 ) ;
int V_11 = 2 * ( V_2 -> V_9 % 4 ) ;
T_1 V_12 = 0x3 << V_11 ;
F_4 ( V_2 -> V_6 -> V_15 ,
V_2 -> V_6 -> V_7 -> V_24 , V_2 -> V_25 ) ;
F_4 ( V_2 -> V_6 -> V_15 ,
V_2 -> V_6 -> V_7 -> V_26 , V_2 -> V_27 ) ;
if ( ! ( V_22 & V_28 ) )
F_4 ( V_2 -> V_6 -> V_15 , V_23 ,
V_22 | V_28 ) ;
F_2 ( & V_2 -> V_6 -> V_14 ) ;
V_10 = F_3 ( V_2 -> V_6 -> V_15 , V_5 ) ;
if ( ( V_10 & V_12 ) != ( V_29 << V_11 ) )
F_4 ( V_2 -> V_6 -> V_15 , V_5 ,
( V_10 & ~ V_12 ) | ( V_29 << V_11 ) ) ;
F_5 ( & V_2 -> V_6 -> V_14 ) ;
}
static int F_7 ( struct V_30 * V_31 ,
enum V_3 V_32 )
{
struct V_1 * V_2 ;
V_2 = F_8 ( V_31 , struct V_1 , V_31 ) ;
return F_1 ( V_2 , V_32 ) ;
}
static int F_9 ( struct V_30 * V_31 ,
unsigned long * V_33 , unsigned long * V_34 )
{
struct V_1 * V_2 ;
unsigned long V_35 , V_36 , V_37 ;
T_1 V_25 , V_27 ;
V_2 = F_8 ( V_31 , struct V_1 , V_31 ) ;
V_35 = * V_33 ;
V_36 = * V_34 ;
if ( ! V_35 && ! V_36 ) {
V_35 = 500 ;
V_36 = 500 ;
}
V_37 = V_35 + V_36 ;
if ( ( V_37 < V_38 ) ||
( V_37 > V_39 ) ) {
V_35 = 500 ;
V_36 = 500 ;
V_37 = V_35 + V_36 ;
}
V_25 = ( V_35 * 256 ) / V_37 ;
V_27 = ( V_37 * 24 / 1000 ) - 1 ;
V_2 -> V_25 = V_25 ;
V_2 -> V_27 = V_27 ;
F_6 ( V_2 ) ;
* V_33 = V_35 ;
* V_34 = V_36 ;
return 0 ;
}
static struct V_40 *
F_10 ( struct V_41 * V_15 , struct V_42 * V_6 )
{
struct V_43 * V_44 = V_15 -> V_45 . V_46 , * V_47 ;
struct V_40 * V_48 ;
struct V_49 * V_50 ;
int V_51 ;
V_51 = F_11 ( V_44 ) ;
if ( ! V_51 || V_51 > V_6 -> V_52 )
return F_12 ( - V_53 ) ;
V_50 = F_13 ( & V_15 -> V_45 ,
sizeof( struct V_49 ) * V_6 -> V_52 , V_54 ) ;
if ( ! V_50 )
return F_12 ( - V_55 ) ;
F_14 (np, child) {
struct V_49 V_56 = {} ;
T_2 V_57 ;
int V_58 ;
V_58 = F_15 ( V_47 , L_1 , & V_57 ) ;
if ( ( V_58 != 0 ) || ( V_57 >= V_6 -> V_52 ) )
continue;
V_56 . V_59 =
F_16 ( V_47 , L_2 , NULL ) ? : V_47 -> V_59 ;
V_56 . V_60 =
F_16 ( V_47 , L_3 , NULL ) ;
V_50 [ V_57 ] = V_56 ;
}
V_48 = F_13 ( & V_15 -> V_45 ,
sizeof( struct V_40 ) , V_54 ) ;
if ( ! V_48 )
return F_12 ( - V_55 ) ;
V_48 -> V_61 . V_61 = V_50 ;
V_48 -> V_61 . V_62 = V_6 -> V_52 ;
if ( F_17 ( V_44 , L_4 ) )
V_48 -> V_63 = V_64 ;
else
V_48 -> V_63 = V_65 ;
if ( F_17 ( V_44 , L_5 ) )
V_48 -> V_66 = V_67 ;
else
V_48 -> V_66 = V_68 ;
return V_48 ;
}
static struct V_40 *
F_10 ( struct V_41 * V_15 , struct V_42 * V_6 )
{
return F_12 ( - V_53 ) ;
}
static int F_18 ( struct V_41 * V_15 ,
const struct V_69 * V_70 )
{
struct V_2 * V_71 ;
struct V_1 * V_2 ;
struct V_40 * V_48 ;
struct V_42 * V_6 ;
int V_72 , V_73 ;
V_6 = & V_74 [ V_70 -> V_75 ] ;
V_48 = F_19 ( & V_15 -> V_45 ) ;
if ( ! V_48 ) {
V_48 = F_10 ( V_15 , V_6 ) ;
if ( F_20 ( V_48 ) ) {
F_21 ( & V_15 -> V_45 , L_6 ) ;
V_48 = NULL ;
}
}
if ( V_48 && ( V_48 -> V_61 . V_62 < 1 ||
V_48 -> V_61 . V_62 > V_6 -> V_52 ) ) {
F_22 ( & V_15 -> V_45 , L_7 ,
V_6 -> V_52 ) ;
return - V_76 ;
}
V_71 = F_13 ( & V_15 -> V_45 , sizeof( * V_71 ) ,
V_54 ) ;
if ( ! V_71 )
return - V_55 ;
V_2 = F_13 ( & V_15 -> V_45 , V_6 -> V_52 * sizeof( * V_2 ) ,
V_54 ) ;
if ( ! V_2 )
return - V_55 ;
F_23 ( V_15 , V_71 ) ;
F_24 ( & V_71 -> V_14 ) ;
V_71 -> V_7 = V_6 ;
V_71 -> V_15 = V_15 ;
V_71 -> V_61 = V_2 ;
for ( V_72 = 0 ; V_72 < V_6 -> V_52 / 4 ; V_72 ++ )
F_4 ( V_15 , V_6 -> V_8 + V_72 , 0x00 ) ;
for ( V_72 = 0 ; V_72 < V_6 -> V_52 ; V_72 ++ ) {
V_2 [ V_72 ] . V_9 = V_72 ;
V_2 [ V_72 ] . V_6 = V_71 ;
if ( V_48 && V_72 < V_48 -> V_61 . V_62 ) {
if ( V_48 -> V_61 . V_61 [ V_72 ] . V_59 )
snprintf ( V_2 [ V_72 ] . V_59 ,
sizeof( V_2 [ V_72 ] . V_59 ) , L_8 ,
V_48 -> V_61 . V_61 [ V_72 ] . V_59 ) ;
if ( V_48 -> V_61 . V_61 [ V_72 ] . V_60 )
V_2 [ V_72 ] . V_31 . V_60 =
V_48 -> V_61 . V_61 [ V_72 ] . V_60 ;
}
if ( ! V_48 || V_72 >= V_48 -> V_61 . V_62 ||
! V_48 -> V_61 . V_61 [ V_72 ] . V_59 )
snprintf ( V_2 [ V_72 ] . V_59 , sizeof( V_2 [ V_72 ] . V_59 ) ,
L_9 , V_15 -> V_77 -> V_78 ,
V_15 -> V_79 , V_72 ) ;
V_2 [ V_72 ] . V_31 . V_59 = V_2 [ V_72 ] . V_59 ;
V_2 [ V_72 ] . V_31 . V_80 = F_7 ;
if ( V_48 && V_48 -> V_66 == V_67 )
V_2 [ V_72 ] . V_31 . V_81 = F_9 ;
V_73 = F_25 ( & V_15 -> V_45 , & V_2 [ V_72 ] . V_31 ) ;
if ( V_73 < 0 )
goto exit;
}
F_4 ( V_15 , V_82 , 0x00 ) ;
if ( V_48 ) {
if ( V_48 -> V_63 == V_65 )
F_4 ( V_15 , V_23 , 0x01 ) ;
else
F_4 ( V_15 , V_23 , 0x05 ) ;
}
return 0 ;
exit:
while ( V_72 -- )
F_26 ( & V_2 [ V_72 ] . V_31 ) ;
return V_73 ;
}
static int F_27 ( struct V_41 * V_15 )
{
struct V_2 * V_2 = F_28 ( V_15 ) ;
int V_72 ;
for ( V_72 = 0 ; V_72 < V_2 -> V_7 -> V_52 ; V_72 ++ )
F_26 ( & V_2 -> V_61 [ V_72 ] . V_31 ) ;
return 0 ;
}
