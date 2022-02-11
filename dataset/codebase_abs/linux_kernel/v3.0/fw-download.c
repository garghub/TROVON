static int F_1 ( struct V_1 * V_2 , const T_1 * V_3 ,
T_2 V_4 , T_2 V_5 )
{
struct V_6 * V_7 = & V_2 -> V_7 ;
struct V_8 * V_9 = & V_7 -> V_10 ;
F_2 ( V_2 , V_11 , L_1 ) ;
F_3 ( V_2 , V_11 , L_2 , V_4 ) ;
V_7 -> V_3 = V_3 ;
V_7 -> V_4 = V_4 ;
V_7 -> V_12 = 0 ;
V_7 -> V_13 = 0 ;
V_7 -> V_14 = F_4 ( V_5 , V_15 ) ;
if ( ! V_7 -> V_14 ) {
F_5 ( V_2 , V_11 , L_3 ) ;
return - V_16 ;
}
V_7 -> V_17 = V_5 ;
memcpy ( V_9 , V_7 -> V_3 , sizeof( struct V_8 ) ) ;
F_3 ( V_2 , V_11 , L_4
L_5 ,
V_9 -> V_18 , V_9 -> V_19 , V_9 -> V_20 ,
V_9 -> V_21 , V_9 -> V_22 , V_9 -> V_23 ,
V_9 -> V_24 , V_9 -> V_25 , V_9 -> V_26 ,
V_9 -> V_27 ) ;
V_7 -> V_12 += sizeof( struct V_8 ) ;
F_2 ( V_2 , V_11 , L_6 ) ;
return 0 ;
}
static bool F_6 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = & V_2 -> V_7 ;
T_3 * V_3 = ( T_3 * ) V_7 -> V_3 ;
int V_28 , V_29 , V_30 ;
T_4 V_31 = 0 ;
T_4 V_32 ;
T_4 V_33 = 0xffffffff ;
V_29 = ( V_7 -> V_4 - V_34 ) % 4 ;
V_30 = ( V_7 -> V_4 - V_34 ) / 4 ;
F_3 ( V_2 , V_11 , L_7 , V_29 , V_30 ) ;
for ( V_28 = 0 ; V_28 < V_30 ; V_28 ++ )
V_31 += F_7 ( V_3 [ V_28 ] ) ;
if ( V_29 ) {
V_33 <<= 8 * ( 4 - V_29 ) ;
V_31 += F_7 ( V_3 [ V_30 ] ) & V_33 ;
}
V_32 = F_8 ( ( T_3 * ) ( V_7 -> V_3 +
V_7 -> V_4 - V_34 ) ) ;
F_3 ( V_2 , V_11 ,
L_8 ,
V_31 , V_32 ) ;
return V_32 == V_31 ;
}
static int F_9 ( struct V_1 * V_2 , const T_1 * * V_35 ,
T_2 * V_36 , T_3 * V_37 )
{
struct V_6 * V_7 = & V_2 -> V_7 ;
struct V_38 * V_39 = & V_2 -> V_39 ;
struct V_40 * V_41 ;
F_2 ( V_2 , V_11 , L_1 ) ;
while ( V_7 -> V_12 + sizeof( struct V_40 )
<= V_7 -> V_4 ) {
V_41 = (struct V_40 * )
( V_7 -> V_3 + V_7 -> V_12 ) ;
V_7 -> V_12 += sizeof( struct V_40 ) ;
F_3 ( V_2 , V_11 ,
L_9 ,
V_41 -> type , V_41 -> V_42 ,
V_41 -> V_43 ) ;
if ( strcmp ( V_41 -> type , L_10 ) == 0 )
V_7 -> V_13 = F_7 ( V_41 -> V_42 ) ;
else if ( strcmp ( V_41 -> type , L_11 ) == 0 )
strcpy ( V_39 -> V_44 , V_7 -> V_3 + V_7 -> V_12 ) ;
else if ( ( ( strcmp ( V_41 -> type , L_12 ) == 0 ) &&
( V_2 -> V_45 & V_46 ) ) ||
( ( strcmp ( V_41 -> type , L_13 ) == 0 ) &&
( V_2 -> V_45 & V_47 ) ) ||
( ( strcmp ( V_41 -> type , L_14 ) == 0 ) &&
( V_2 -> V_45 & V_48 ) ) ) {
* V_37 = V_41 -> V_42 ;
* V_36 = F_7 ( V_41 -> V_43 ) ;
* V_35 = V_7 -> V_3 + V_7 -> V_12 ;
V_7 -> V_12 += F_7 ( V_41 -> V_43 ) ;
return 1 ;
} else if ( strcmp ( V_41 -> type , L_15 ) != 0 )
F_10 ( V_2 , V_11 ,
L_16 ,
V_41 -> type ) ;
V_7 -> V_12 += F_7 ( V_41 -> V_43 ) ;
F_3 ( V_2 , V_11 ,
L_17 , V_7 -> V_12 ) ;
}
F_2 ( V_2 , V_49 , L_6 ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 , const T_1 * V_35 ,
T_2 V_36 , T_3 V_50 )
{
struct V_6 * V_7 = & V_2 -> V_7 ;
struct V_51 * V_52 = (struct V_51 * ) V_7 -> V_14 ;
const T_1 * V_53 = V_35 ;
T_2 V_54 = 0 ;
int V_55 = 0 ;
int V_56 = 0 ;
T_4 V_57 = 0 ;
F_2 ( V_2 , V_11 , L_1 ) ;
F_3 ( V_2 , V_11 , L_18 ,
V_50 , V_36 ) ;
while ( V_54 < V_36 ) {
int V_28 ;
T_4 V_58 = 0 ;
T_4 V_59 = F_12 ( & V_2 -> V_59 ) ;
T_4 V_43 = F_13 ( V_7 -> V_17 - sizeof( * V_52 ) ,
V_36 - V_54 ) ;
T_4 V_60 = ( V_43 + sizeof( * V_52 ) +
V_61 - 1 ) &
~ ( V_61 - 1 ) ;
++ V_55 ;
if ( V_59 ) {
F_3 ( V_2 , V_11 ,
L_19 ) ;
V_56 = - V_62 ;
goto exit;
}
memset ( V_7 -> V_14 , 0 , V_7 -> V_17 ) ;
V_57 |= V_63 << V_64 ;
V_57 |= V_65 << V_66 ;
V_57 |= ( V_2 -> V_39 . V_67 ? 1 : 0 ) << V_68 ;
V_57 |= ( V_2 -> V_39 . V_32 ? 1 : 0 ) << V_69 ;
V_52 -> V_43 = F_14 ( V_43 ) ;
V_52 -> V_42 = V_50 ;
if ( V_43 & 0x3 )
V_57 &= ~ V_70 ;
memcpy ( V_52 -> V_71 , V_53 , V_43 ) ;
if ( V_57 & V_70 ) {
V_58 = V_43 + F_7 ( V_50 ) + V_57 ;
for ( V_28 = 0 ; V_28 < V_43 > > 2 ; V_28 ++ )
V_58 += ( ( T_4 * ) V_53 ) [ V_28 ] ;
V_52 -> V_72 = F_14 ( V_58 ) ;
F_3 ( V_2 , V_11 , L_20 ,
V_52 -> V_72 ) ;
}
F_3 ( V_2 , V_11 , L_21
L_22 ,
V_55 , V_60 , V_54 , V_36 , V_50 ) ;
if ( V_2 -> V_39 . V_73 )
F_15 ( V_11 , V_7 -> V_14 , V_60 ) ;
V_52 -> V_57 = F_14 ( V_57 ) ;
V_56 = F_16 ( V_2 , V_7 -> V_14 , V_60 ) ;
if ( V_56 != 0 ) {
F_3 ( V_2 , V_11 ,
L_23 , V_56 ) ;
goto exit;
}
V_50 = F_14 ( F_7 ( V_50 ) + V_43 ) ;
V_54 += V_43 ;
V_53 = V_35 + V_54 ;
if ( V_2 -> V_39 . V_74 && ( V_55 + 1 ) >= V_2 -> V_39 . V_74 ) {
F_3 ( V_2 , V_11 ,
L_24 ,
V_2 -> V_39 . V_74 ) ;
break;
}
}
if ( V_54 < V_36 )
V_56 = - V_75 ;
exit:
F_2 ( V_2 , V_11 , L_6 ) ;
return V_56 ;
}
static int F_17 ( struct V_1 * V_2 , bool V_76 )
{
struct V_6 * V_7 = & V_2 -> V_7 ;
struct V_51 * V_52 = (struct V_51 * ) V_7 -> V_14 ;
int V_56 ;
T_4 V_57 ;
F_2 ( V_2 , V_11 , L_1 ) ;
memset ( V_7 -> V_14 , 0 , V_7 -> V_17 ) ;
V_57 = V_65 << V_66 ;
if ( V_76 ) {
V_57 |= V_77 << V_64 ;
V_52 -> V_42 = F_14 ( V_7 -> V_13 ) ;
F_3 ( V_2 , V_11 , L_25 ,
V_7 -> V_13 ) ;
} else {
V_57 |= V_78 << V_64 ;
F_3 ( V_2 , V_11 , L_26 ) ;
}
V_52 -> V_57 = F_14 ( V_57 ) ;
F_15 ( V_11 , V_7 -> V_14 , sizeof( * V_52 ) ) ;
V_56 = F_16 ( V_2 , V_7 -> V_14 , V_61 ) ;
if ( V_56 )
F_3 ( V_2 , V_11 , L_27 , V_56 ) ;
F_2 ( V_2 , V_11 , L_6 ) ;
return 0 ;
}
int F_18 ( struct V_1 * V_2 )
{
const T_1 * V_79 = F_19 ( V_80 ) ;
const struct V_81 * V_82 ;
const T_1 * V_83 ;
T_2 V_84 ;
T_3 V_50 ;
int V_56 ;
F_3 ( V_2 , V_11 , L_28 ,
V_2 -> V_45 ) ;
F_3 ( V_2 , V_11 , L_29 ,
( V_2 -> V_45 & V_46 ) ? L_30 : L_31 ) ;
F_3 ( V_2 , V_11 , L_32 ,
( V_2 -> V_45 & V_47 ) ? L_30 : L_31 ) ;
F_3 ( V_2 , V_11 , L_33 ,
( V_2 -> V_45 & V_48 ) ? L_30 : L_31 ) ;
V_56 = F_20 ( & V_82 , V_79 , & V_2 -> V_85 -> V_86 ) ;
if ( V_56 < 0 ) {
F_5 ( V_2 , V_11 , L_34 ,
V_79 , V_56 ) ;
goto exit;
}
if ( V_82 -> V_87 < sizeof( struct V_40 ) ) {
F_5 ( V_2 , V_11 , L_35 ,
V_79 , sizeof( struct V_40 ) , V_82 -> V_87 ) ;
goto exit;
}
F_3 ( V_2 , V_11 , L_36 , V_79 ) ;
V_56 = F_1 ( V_2 , V_82 -> V_71 , V_82 -> V_87 , V_2 -> V_88 ) ;
if ( V_56 < 0 ) {
F_5 ( V_2 , V_11 ,
L_37 , V_56 ) ;
goto exit;
}
if ( ! F_6 ( V_2 ) ) {
F_5 ( V_2 , V_11 , L_38 ) ;
V_56 = - V_75 ;
goto exit;
}
while ( F_9 ( V_2 , & V_83 , & V_84 , & V_50 ) ) {
V_56 = F_11 ( V_2 , V_83 , V_84 , V_50 ) ;
if ( V_56 ) {
F_5 ( V_2 , V_11 ,
L_39 , V_79 ) ;
goto exit;
}
}
V_56 = F_17 ( V_2 , ! ! ( V_2 -> V_45 & V_89 ) ) ;
exit:
F_21 ( V_2 -> V_7 . V_14 ) ;
F_22 ( V_82 ) ;
return V_56 ;
}
