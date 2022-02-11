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
int V_45 ,
struct V_3 * V_4 )
{
int V_23 ;
if ( ! V_2 -> V_24 )
return - V_46 ;
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
V_4 -> V_17 = F_11 ( V_45 ) | V_47 ;
V_4 -> V_34 = sizeof( struct V_48 ) ;
V_23 = F_3 ( V_2 , V_4 ) ;
if ( V_23 < 0 ) {
F_9 ( V_2 -> V_43 ,
L_3 ,
V_45 , V_23 ) ;
return V_23 ;
}
if ( V_45 > 0 && V_4 -> V_26 == V_49 )
return - V_50 ;
else if ( V_4 -> V_26 != V_36 )
return V_4 -> V_26 ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_51 * V_52 ;
struct V_53 * V_54 ;
int V_23 ;
int V_55 = F_13 ( sizeof( * V_52 ) , sizeof( * V_54 ) ) ;
V_4 = F_4 ( sizeof( * V_4 ) + V_55 , V_31 ) ;
if ( ! V_4 )
return - V_32 ;
V_4 -> V_19 = 0 ;
V_4 -> V_17 = V_56 ;
V_52 = (struct V_51 * ) V_4 -> V_22 ;
V_4 -> V_12 = sizeof( * V_52 ) ;
V_54 = (struct V_53 * ) V_4 -> V_22 ;
V_4 -> V_34 = sizeof( * V_54 ) ;
V_52 -> V_57 = 0xa0b0c0d0 ;
V_23 = F_3 ( V_2 , V_4 ) ;
if ( V_23 < 0 ) {
F_9 ( V_2 -> V_43 ,
L_4 ,
V_23 ) ;
goto exit;
} else if ( V_4 -> V_26 != V_36 ) {
F_14 ( V_2 -> V_43 ,
L_5 ,
V_4 -> V_26 ) ;
V_23 = V_4 -> V_26 ;
goto exit;
} else if ( V_54 -> V_58 != 0xa1b2c3d4 ) {
F_14 ( V_2 -> V_43 ,
L_6 ,
V_54 -> V_58 ) ;
V_23 = - V_59 ;
goto exit;
}
V_23 = 0 ;
exit:
F_6 ( V_4 ) ;
return V_23 ;
}
int F_15 ( struct V_1 * V_2 )
{
struct V_60 * V_43 = V_2 -> V_43 ;
struct V_3 * V_61 ;
struct V_48 * V_62 ;
int V_23 ;
V_61 = F_16 ( sizeof( * V_61 ) + sizeof( * V_62 ) ,
V_31 ) ;
if ( ! V_61 )
return - V_32 ;
V_2 -> V_10 = 3 ;
V_23 = F_10 ( V_2 , 0 , V_61 ) ;
if ( V_23 == 0 ) {
V_62 = (struct V_48 * )
V_61 -> V_22 ;
V_2 -> V_63 = V_62 -> V_64 -
sizeof( struct V_5 ) ;
V_2 -> V_65 = V_62 -> V_66 -
sizeof( struct V_67 ) ;
V_2 -> V_10 =
F_17 ( V_11 ,
F_18 ( V_62 -> V_68 ) - 1 ) ;
F_9 ( V_2 -> V_43 ,
L_7 ,
V_2 -> V_10 ) ;
V_2 -> V_69 = V_2 -> V_65 +
sizeof( struct V_67 ) +
V_70 ;
V_2 -> V_13 = V_2 -> V_63 +
sizeof( struct V_5 ) +
V_71 ;
V_23 = F_10 ( V_2 , 1 , V_61 ) ;
if ( V_23 ) {
F_9 ( V_2 -> V_43 , L_8 , V_23 ) ;
V_2 -> V_72 = 0 ;
} else {
F_9 ( V_2 -> V_43 , L_9 ) ;
V_2 -> V_72 =
V_62 -> V_64 -
sizeof( struct V_5 ) ;
}
} else {
V_2 -> V_10 = 2 ;
V_23 = F_12 ( V_2 ) ;
if ( V_23 == 0 ) {
F_9 ( V_2 -> V_43 , L_10 ) ;
V_2 -> V_63 = V_39 ;
V_2 -> V_65 = V_39 ;
V_2 -> V_72 = 0 ;
V_2 -> V_24 = NULL ;
V_2 -> V_69 = V_73 ;
V_2 -> V_13 = V_73 ;
} else {
V_2 -> V_10 = V_74 ;
F_9 ( V_2 -> V_43 , L_11 , V_23 ) ;
goto exit;
}
}
F_19 ( V_43 , V_2 -> V_75 ) ;
F_19 ( V_43 , V_2 -> V_14 ) ;
V_2 -> V_75 = F_20 ( V_43 , V_2 -> V_69 , V_31 ) ;
if ( ! V_2 -> V_75 ) {
V_23 = - V_32 ;
goto exit;
}
V_2 -> V_14 = F_20 ( V_43 , V_2 -> V_13 , V_31 ) ;
if ( ! V_2 -> V_14 ) {
F_19 ( V_43 , V_2 -> V_75 ) ;
V_23 = - V_32 ;
goto exit;
}
exit:
F_6 ( V_61 ) ;
return V_23 ;
}
int F_21 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_23 ;
F_22 ( & V_2 -> V_76 ) ;
if ( V_2 -> V_10 == V_74 ) {
V_23 = F_15 ( V_2 ) ;
if ( V_23 ) {
F_14 ( V_2 -> V_43 ,
L_12 ) ;
F_23 ( & V_2 -> V_76 ) ;
return V_23 ;
}
}
if ( V_4 -> V_34 > V_2 -> V_65 ) {
F_9 ( V_2 -> V_43 , L_13 ) ;
V_4 -> V_34 = V_2 -> V_65 ;
}
if ( V_4 -> V_17 < F_11 ( 1 ) ) {
if ( V_4 -> V_12 > V_2 -> V_63 ) {
F_14 ( V_2 -> V_43 ,
L_14 ,
V_4 -> V_12 ,
V_2 -> V_63 ) ;
F_23 ( & V_2 -> V_76 ) ;
return - V_77 ;
}
} else {
if ( V_4 -> V_12 > V_2 -> V_72 ) {
F_14 ( V_2 -> V_43 ,
L_15 ,
V_4 -> V_12 ,
V_2 -> V_72 ) ;
F_23 ( & V_2 -> V_76 ) ;
return - V_77 ;
}
}
V_23 = F_3 ( V_2 , V_4 ) ;
F_23 ( & V_2 -> V_76 ) ;
return V_23 ;
}
int F_24 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_23 ;
V_23 = F_21 ( V_2 , V_4 ) ;
if ( V_23 < 0 ) {
F_14 ( V_2 -> V_43 , L_16 , V_23 ) ;
} else if ( V_4 -> V_26 != V_36 ) {
F_9 ( V_2 -> V_43 , L_17 , V_4 -> V_26 ) ;
return - V_78 ;
}
return V_23 ;
}
