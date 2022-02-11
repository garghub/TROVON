static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_7 = V_6 -> V_8 . V_9 ;
T_1 V_10 , V_11 , V_12 ;
F_3 ( V_4 -> V_13 , V_6 -> V_14 , sizeof( V_4 -> V_13 ) ) ;
F_3 ( V_4 -> V_9 , V_6 -> V_15 , sizeof( V_4 -> V_9 ) ) ;
F_3 ( V_4 -> V_16 , F_4 ( V_6 -> V_17 ) ,
sizeof( V_4 -> V_16 ) ) ;
V_10 = F_5 ( V_7 , V_18 ,
V_19 ) ;
V_11 = F_5 ( V_7 , V_20 ,
V_21 ) ;
V_12 = F_5 ( V_7 , V_22 ,
V_23 ) ;
snprintf ( V_4 -> V_24 , sizeof( V_4 -> V_24 ) ,
L_1 , V_10 , V_11 , V_12 ) ;
}
static T_1 F_6 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return V_6 -> V_25 ;
}
static void F_7 ( struct V_1 * V_2 ,
T_1 V_26 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_25 = V_26 ;
}
static void F_8 ( struct V_1 * V_2 ,
struct V_27 * V_28 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_28 -> V_29 = V_30 ;
V_28 -> V_31 = V_30 ;
V_28 -> V_32 = V_6 -> V_33 ;
V_28 -> V_34 = V_6 -> V_35 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_36 * V_37 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
memset ( V_37 , 0 , sizeof( struct V_36 ) ) ;
V_37 -> V_38 = V_6 -> V_39 ;
V_37 -> V_40 = V_6 -> V_41 ;
V_37 -> V_42 = V_6 -> V_43 ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_36 * V_37 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_44 * V_45 = & V_6 -> V_45 ;
unsigned int V_41 , V_46 , V_39 ;
unsigned int V_43 ;
if ( ( V_37 -> V_47 ) || ( V_37 -> V_48 ) ||
( V_37 -> V_49 ) || ( V_37 -> V_50 ) ||
( V_37 -> V_51 ) || ( V_37 -> V_52 ) ||
( V_37 -> V_53 ) || ( V_37 -> V_54 ) ||
( V_37 -> V_55 ) || ( V_37 -> V_56 ) ||
( V_37 -> V_57 ) || ( V_37 -> V_58 ) ||
( V_37 -> V_59 ) || ( V_37 -> V_60 ) ||
( V_37 -> V_61 ) || ( V_37 -> V_62 ) ||
( V_37 -> V_63 ) ||
( V_37 -> V_64 ) ||
( V_37 -> V_65 ) )
return - V_66 ;
V_39 = V_37 -> V_38 ;
V_46 = V_45 -> V_67 ( V_6 , V_39 ) ;
V_41 = V_37 -> V_40 ;
V_43 = V_37 -> V_42 ;
if ( ( V_46 > V_68 ) ||
( V_46 < V_69 ) ||
( V_41 > V_6 -> V_70 ) )
return - V_71 ;
if ( V_43 > V_6 -> V_72 )
return - V_71 ;
V_6 -> V_46 = V_46 ;
V_6 -> V_39 = V_39 ;
V_6 -> V_41 = V_41 ;
V_45 -> V_73 ( V_6 ) ;
V_6 -> V_43 = V_43 ;
V_45 -> V_74 ( V_6 ) ;
return 0 ;
}
static void F_11 ( struct V_1 * V_2 ,
T_1 V_75 , T_2 * V_76 )
{
int V_77 ;
switch ( V_75 ) {
case V_78 :
for ( V_77 = 0 ; V_77 < V_79 ; V_77 ++ ) {
memcpy ( V_76 , V_80 [ V_77 ] . V_81 ,
V_82 ) ;
V_76 += V_82 ;
}
break;
default:
F_12 ( 1 ) ;
break;
}
}
static int F_13 ( struct V_1 * V_2 ,
int V_75 )
{
int V_83 ;
switch ( V_75 ) {
case V_78 :
V_83 = V_79 ;
break;
default:
V_83 = - V_66 ;
}
return V_83 ;
}
static void F_14 ( struct V_1 * V_2 ,
struct V_84 * V_85 ,
T_3 * V_76 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_2 * V_86 ;
int V_77 ;
V_6 -> V_45 . V_87 ( V_6 ) ;
for ( V_77 = 0 ; V_77 < V_79 ; V_77 ++ ) {
V_86 = ( T_2 * ) V_6 + V_80 [ V_77 ] . V_88 ;
* V_76 ++ = * ( T_3 * ) V_86 ;
}
}
const struct V_89 * F_15 ( void )
{
return & V_90 ;
}
