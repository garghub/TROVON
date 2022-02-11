static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 ;
T_1 * V_7 ;
int V_8 ;
T_1 V_9 = 0 ;
F_2 ( V_2 -> V_10 != V_11 ) ;
F_2 ( V_4 -> V_12 + sizeof( * V_6 ) > V_2 -> V_13 ) ;
V_7 = V_2 -> V_14 ;
V_6 = (struct V_5 * ) V_7 ;
V_6 -> V_15 = V_11 ;
V_6 -> V_16 = 0 ;
V_6 -> V_17 = V_4 -> V_17 ;
V_6 -> V_18 = V_4 -> V_19 ;
V_6 -> V_20 = 0 ;
V_6 -> V_21 = V_4 -> V_12 ;
for ( V_8 = 0 ; V_8 < sizeof( * V_6 ) ; V_8 ++ )
V_9 += V_7 [ V_8 ] ;
memcpy ( V_7 + sizeof( * V_6 ) , V_4 -> V_22 , V_4 -> V_12 ) ;
for ( V_8 = 0 ; V_8 < V_4 -> V_12 ; V_8 ++ )
V_9 += V_4 -> V_22 [ V_8 ] ;
V_6 -> V_16 = - V_9 ;
return sizeof( * V_6 ) + V_4 -> V_12 ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_23 ;
if ( V_2 -> V_10 > 2 )
V_23 = V_2 -> V_24 ( V_2 , V_4 ) ;
else
V_23 = V_2 -> V_25 ( V_2 , V_4 ) ;
if ( V_4 -> V_26 == V_27 ) {
int V_8 ;
struct V_3 * V_28 ;
struct V_29 * V_30 ;
V_28 = F_4 ( sizeof( * V_28 ) + sizeof( * V_30 ) ,
V_31 ) ;
if ( ! V_28 )
return - V_32 ;
V_28 -> V_19 = 0 ;
V_28 -> V_17 = V_33 ;
V_28 -> V_34 = sizeof( * V_30 ) ;
V_28 -> V_12 = 0 ;
for ( V_8 = 0 ; V_8 < V_35 ; V_8 ++ ) {
F_5 ( 10000 , 11000 ) ;
V_23 = V_2 -> V_25 ( V_2 , V_28 ) ;
if ( V_23 < 0 )
break;
V_4 -> V_26 = V_28 -> V_26 ;
if ( V_28 -> V_26 != V_36 )
break;
V_30 = (struct V_29 * )
V_28 -> V_22 ;
if ( ! ( V_30 -> V_37 & V_38 ) )
break;
}
F_6 ( V_28 ) ;
}
return V_23 ;
}
int F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_1 * V_7 ;
T_1 V_9 ;
int V_8 ;
if ( V_2 -> V_10 > 2 )
return F_1 ( V_2 , V_4 ) ;
F_2 ( V_4 -> V_12 > V_39 ) ;
V_7 = V_2 -> V_14 ;
V_7 [ 0 ] = V_40 + V_4 -> V_19 ;
V_7 [ 1 ] = V_4 -> V_17 ;
V_7 [ 2 ] = V_4 -> V_12 ;
V_9 = V_7 [ 0 ] + V_7 [ 1 ] + V_7 [ 2 ] ;
for ( V_8 = 0 ; V_8 < V_4 -> V_12 ; V_8 ++ )
V_9 += V_7 [ V_41 + V_8 ] = V_4 -> V_22 [ V_8 ] ;
V_7 [ V_41 + V_4 -> V_12 ] = V_9 ;
return V_42 + V_4 -> V_12 ;
}
int F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
switch ( V_4 -> V_26 ) {
case V_36 :
return 0 ;
case V_27 :
F_9 ( V_2 -> V_43 , L_1 ,
V_4 -> V_17 ) ;
return - V_44 ;
default:
F_9 ( V_2 -> V_43 , L_2 ,
V_4 -> V_17 , V_4 -> V_26 ) ;
return 0 ;
}
}
static int F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_2 * V_45 )
{
struct V_46 * V_47 ;
int V_23 ;
V_4 -> V_17 = V_48 ;
V_4 -> V_19 = 0 ;
V_4 -> V_12 = 0 ;
V_4 -> V_34 = sizeof( * V_47 ) ;
V_23 = F_3 ( V_2 , V_4 ) ;
if ( V_23 > 0 ) {
V_47 = (struct V_46 * ) V_4 -> V_22 ;
* V_45 = V_47 -> V_45 ;
}
return V_23 ;
}
static int F_11 ( struct V_1 * V_2 ,
int V_49 ,
struct V_3 * V_4 )
{
int V_23 ;
if ( ! V_2 -> V_24 )
return - V_50 ;
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
V_4 -> V_17 = F_12 ( V_49 ) | V_51 ;
V_4 -> V_34 = sizeof( struct V_52 ) ;
V_23 = F_3 ( V_2 , V_4 ) ;
if ( V_23 < 0 ) {
F_9 ( V_2 -> V_43 ,
L_3 ,
V_49 , V_23 ) ;
return V_23 ;
}
if ( V_49 > 0 && V_4 -> V_26 == V_53 )
return - V_54 ;
else if ( V_4 -> V_26 != V_36 )
return V_4 -> V_26 ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_55 * V_56 ;
struct V_57 * V_58 ;
int V_23 ;
int V_59 = F_14 ( sizeof( * V_56 ) , sizeof( * V_58 ) ) ;
V_4 = F_4 ( sizeof( * V_4 ) + V_59 , V_31 ) ;
if ( ! V_4 )
return - V_32 ;
V_4 -> V_19 = 0 ;
V_4 -> V_17 = V_60 ;
V_56 = (struct V_55 * ) V_4 -> V_22 ;
V_4 -> V_12 = sizeof( * V_56 ) ;
V_58 = (struct V_57 * ) V_4 -> V_22 ;
V_4 -> V_34 = sizeof( * V_58 ) ;
V_56 -> V_61 = 0xa0b0c0d0 ;
V_23 = F_3 ( V_2 , V_4 ) ;
if ( V_23 < 0 ) {
F_9 ( V_2 -> V_43 ,
L_4 ,
V_23 ) ;
goto exit;
} else if ( V_4 -> V_26 != V_36 ) {
F_15 ( V_2 -> V_43 ,
L_5 ,
V_4 -> V_26 ) ;
V_23 = V_4 -> V_26 ;
goto exit;
} else if ( V_58 -> V_62 != 0xa1b2c3d4 ) {
F_15 ( V_2 -> V_43 ,
L_6 ,
V_58 -> V_62 ) ;
V_23 = - V_63 ;
goto exit;
}
V_23 = 0 ;
exit:
F_6 ( V_4 ) ;
return V_23 ;
}
static int F_16 ( struct V_1 * V_2 ,
T_3 V_64 , T_4 * V_45 )
{
struct V_65 * V_66 ;
struct V_67 * V_68 ;
struct V_3 * V_4 ;
int V_23 ;
V_4 = F_4 ( sizeof( * V_4 ) + F_14 ( sizeof( * V_68 ) , sizeof( * V_66 ) ) ,
V_31 ) ;
if ( ! V_4 )
return - V_32 ;
V_4 -> V_19 = 0 ;
V_4 -> V_17 = V_69 ;
V_4 -> V_34 = sizeof( * V_68 ) ;
V_4 -> V_12 = sizeof( * V_66 ) ;
V_66 = (struct V_65 * ) V_4 -> V_22 ;
V_66 -> V_64 = V_64 ;
V_23 = F_3 ( V_2 , V_4 ) ;
if ( V_23 > 0 ) {
V_68 = (struct V_67 * ) V_4 -> V_22 ;
* V_45 = V_68 -> V_70 ;
}
F_6 ( V_4 ) ;
return V_23 ;
}
int F_17 ( struct V_1 * V_2 )
{
struct V_71 * V_43 = V_2 -> V_43 ;
struct V_3 * V_72 ;
struct V_52 * V_73 ;
T_4 V_74 = 0 ;
int V_23 ;
V_72 = F_18 ( sizeof( * V_72 ) + sizeof( * V_73 ) ,
V_31 ) ;
if ( ! V_72 )
return - V_32 ;
V_2 -> V_10 = 3 ;
V_23 = F_11 ( V_2 , 0 , V_72 ) ;
if ( V_23 == 0 ) {
V_73 = (struct V_52 * )
V_72 -> V_22 ;
V_2 -> V_75 = V_73 -> V_76 -
sizeof( struct V_5 ) ;
V_2 -> V_77 = V_73 -> V_78 -
sizeof( struct V_79 ) ;
V_2 -> V_10 =
F_19 ( V_11 ,
F_20 ( V_73 -> V_80 ) - 1 ) ;
F_9 ( V_2 -> V_43 ,
L_7 ,
V_2 -> V_10 ) ;
V_2 -> V_81 = V_2 -> V_77 +
sizeof( struct V_79 ) +
V_82 ;
V_2 -> V_13 = V_2 -> V_75 +
sizeof( struct V_5 ) +
V_83 ;
V_23 = F_11 ( V_2 , 1 , V_72 ) ;
if ( V_23 ) {
F_9 ( V_2 -> V_43 , L_8 , V_23 ) ;
V_2 -> V_84 = 0 ;
} else {
F_9 ( V_2 -> V_43 , L_9 ) ;
V_2 -> V_84 =
V_73 -> V_76 -
sizeof( struct V_5 ) ;
}
} else {
V_2 -> V_10 = 2 ;
V_23 = F_13 ( V_2 ) ;
if ( V_23 == 0 ) {
F_9 ( V_2 -> V_43 , L_10 ) ;
V_2 -> V_75 = V_39 ;
V_2 -> V_77 = V_39 ;
V_2 -> V_84 = 0 ;
V_2 -> V_24 = NULL ;
V_2 -> V_81 = V_85 ;
V_2 -> V_13 = V_85 ;
} else {
V_2 -> V_10 = V_86 ;
F_9 ( V_2 -> V_43 , L_11 , V_23 ) ;
goto exit;
}
}
F_21 ( V_43 , V_2 -> V_87 ) ;
F_21 ( V_43 , V_2 -> V_14 ) ;
V_2 -> V_87 = F_22 ( V_43 , V_2 -> V_81 , V_31 ) ;
if ( ! V_2 -> V_87 ) {
V_23 = - V_32 ;
goto exit;
}
V_2 -> V_14 = F_22 ( V_43 , V_2 -> V_13 , V_31 ) ;
if ( ! V_2 -> V_14 ) {
F_21 ( V_43 , V_2 -> V_87 ) ;
V_23 = - V_32 ;
goto exit;
}
V_23 = F_16 ( V_2 ,
V_88 ,
& V_74 ) ;
if ( V_23 < 0 || V_74 == 0 )
V_2 -> V_89 = 0 ;
else
V_2 -> V_89 = 1 ;
V_23 = F_10 ( V_2 , V_72 ,
& V_2 -> V_90 ) ;
if ( V_23 < 0 )
V_2 -> V_90 = V_91 ;
V_23 = 0 ;
exit:
F_6 ( V_72 ) ;
return V_23 ;
}
int F_23 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_23 ;
F_24 ( & V_2 -> V_92 ) ;
if ( V_2 -> V_10 == V_86 ) {
V_23 = F_17 ( V_2 ) ;
if ( V_23 ) {
F_15 ( V_2 -> V_43 ,
L_12 ) ;
F_25 ( & V_2 -> V_92 ) ;
return V_23 ;
}
}
if ( V_4 -> V_34 > V_2 -> V_77 ) {
F_9 ( V_2 -> V_43 , L_13 ) ;
V_4 -> V_34 = V_2 -> V_77 ;
}
if ( V_4 -> V_17 < F_12 ( 1 ) ) {
if ( V_4 -> V_12 > V_2 -> V_75 ) {
F_15 ( V_2 -> V_43 ,
L_14 ,
V_4 -> V_12 ,
V_2 -> V_75 ) ;
F_25 ( & V_2 -> V_92 ) ;
return - V_93 ;
}
} else {
if ( V_4 -> V_12 > V_2 -> V_84 ) {
F_15 ( V_2 -> V_43 ,
L_15 ,
V_4 -> V_12 ,
V_2 -> V_84 ) ;
F_25 ( & V_2 -> V_92 ) ;
return - V_93 ;
}
}
V_23 = F_3 ( V_2 , V_4 ) ;
F_25 ( & V_2 -> V_92 ) ;
return V_23 ;
}
int F_26 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_23 ;
V_23 = F_23 ( V_2 , V_4 ) ;
if ( V_23 < 0 ) {
F_15 ( V_2 -> V_43 , L_16 , V_23 ) ;
} else if ( V_4 -> V_26 != V_36 ) {
F_9 ( V_2 -> V_43 , L_17 , V_4 -> V_26 ) ;
return - V_94 ;
}
return V_23 ;
}
static int F_27 ( struct V_1 * V_2 )
{
T_1 V_95 [ sizeof( struct V_3 ) + sizeof( V_2 -> V_96 ) ] ;
struct V_3 * V_4 = (struct V_3 * ) & V_95 ;
int V_23 ;
if ( V_2 -> V_97 ) {
F_9 ( V_2 -> V_43 , L_18 ) ;
return - V_98 ;
}
V_4 -> V_19 = 0 ;
V_4 -> V_17 = V_88 ;
V_4 -> V_34 = sizeof( V_2 -> V_96 ) ;
V_4 -> V_12 = 0 ;
V_23 = F_23 ( V_2 , V_4 ) ;
if ( V_23 > 0 ) {
V_2 -> V_99 = V_23 - 1 ;
memcpy ( & V_2 -> V_96 , V_4 -> V_22 ,
sizeof( V_2 -> V_96 ) ) ;
}
return V_23 ;
}
static int F_28 ( struct V_1 * V_2 )
{
T_1 V_95 [ sizeof( struct V_3 ) +
sizeof( V_2 -> V_96 . V_22 ) ] ;
struct V_3 * V_4 = (struct V_3 * ) & V_95 ;
V_4 -> V_19 = 0 ;
V_4 -> V_17 = V_100 ;
V_4 -> V_34 = sizeof( V_2 -> V_96 . V_22 ) ;
V_4 -> V_12 = 0 ;
V_2 -> V_99 = F_23 ( V_2 , V_4 ) ;
V_2 -> V_96 . V_101 = V_102 ;
memcpy ( & V_2 -> V_96 . V_22 , V_4 -> V_22 ,
sizeof( V_2 -> V_96 . V_22 ) ) ;
return V_2 -> V_99 ;
}
int F_29 ( struct V_1 * V_2 , bool * V_103 )
{
T_4 V_104 ;
int V_23 ;
if ( ! V_2 -> V_89 ) {
V_23 = F_28 ( V_2 ) ;
if ( V_23 < 0 )
return V_23 ;
if ( V_103 )
* V_103 = true ;
return V_23 ;
}
V_23 = F_27 ( V_2 ) ;
if ( V_23 < 0 )
return V_23 ;
if ( V_103 ) {
V_104 = F_30 ( V_2 ) ;
* V_103 = ! V_104 ||
! ! ( V_104 & V_2 -> V_90 ) ;
}
return V_23 ;
}
T_4 F_30 ( struct V_1 * V_2 )
{
T_4 V_104 ;
F_2 ( ! V_2 -> V_89 ) ;
if ( V_2 -> V_96 . V_101 != V_105 )
return 0 ;
if ( V_2 -> V_99 != sizeof( V_104 ) ) {
F_31 ( V_2 -> V_43 , L_19 ) ;
return 0 ;
}
V_104 = F_32 ( & V_2 -> V_96 . V_22 . V_104 ) ;
return V_104 ;
}
