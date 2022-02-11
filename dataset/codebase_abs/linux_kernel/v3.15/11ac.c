static T_1
F_1 ( struct V_1 * V_2 ,
T_2 V_3 , T_1 V_4 )
{
T_2 V_5 , V_6 , V_7 ;
T_1 V_8 = 0 ;
T_3 V_9 = 0 ;
struct V_10 * V_11 = V_2 -> V_11 ;
if ( V_3 & V_12 )
V_9 = V_11 -> V_13 ;
else
V_9 = V_11 -> V_14 ;
V_6 = 1 ;
for ( V_5 = 1 ; V_5 <= 8 ; V_5 ++ ) {
V_7 = F_2 ( V_4 , V_5 ) ;
if ( V_7 < V_15 )
V_6 = V_5 ;
}
V_7 = F_2 ( V_4 , V_6 ) ;
if ( V_7 == V_15 )
V_7 = V_16 ;
if ( F_3 ( V_9 ) ) {
V_8 = V_17 [ V_6 - 1 ] [ V_7 ] ;
if ( ! V_8 )
V_8 = V_17 [ V_6 - 1 ] [ V_7 - 1 ] ;
} else {
V_8 = V_18 [ V_6 - 1 ] [ V_7 ] ;
if ( ! V_8 )
V_8 = V_18 [ V_6 - 1 ] [ V_7 - 1 ] ;
}
return V_8 ;
}
static void
F_4 ( struct V_1 * V_2 ,
struct V_19 * V_20 , T_2 V_3 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
if ( V_3 & V_21 )
V_20 -> V_22 =
F_5 ( V_11 -> V_13 ) ;
else
V_20 -> V_22 =
F_5 ( V_11 -> V_14 ) ;
}
void F_6 ( struct V_1 * V_2 ,
struct V_19 * V_20 , T_2 V_3 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
T_1 V_23 , V_24 , V_25 ;
T_1 V_26 , V_27 , V_6 , V_28 ;
F_4 ( V_2 , V_20 , V_3 ) ;
V_23 = F_7 ( V_11 -> V_29 ) ;
V_24 = F_8 ( V_20 -> V_30 . V_31 ) ;
V_25 = 0 ;
for ( V_6 = 1 ; V_6 <= 8 ; V_6 ++ ) {
V_26 = F_2 ( V_23 , V_6 ) ;
V_27 = F_2 ( V_24 , V_6 ) ;
if ( ( V_26 == V_15 ) ||
( V_27 == V_15 ) )
F_9 ( V_25 , V_6 ,
V_15 ) ;
else
F_9 ( V_25 , V_6 ,
F_10 ( V_26 , V_27 ) ) ;
}
V_20 -> V_30 . V_31 = F_11 ( V_25 ) ;
V_28 = F_1 ( V_2 , V_3 , V_25 ) ;
V_20 -> V_30 . V_32 = F_11 ( V_28 ) ;
V_23 = F_12 ( V_11 -> V_29 ) ;
V_24 = F_8 ( V_20 -> V_30 . V_33 ) ;
V_25 = 0 ;
for ( V_6 = 1 ; V_6 <= 8 ; V_6 ++ ) {
V_26 = F_2 ( V_23 , V_6 ) ;
V_27 = F_2 ( V_24 , V_6 ) ;
if ( ( V_26 == V_15 ) ||
( V_27 == V_15 ) )
F_9 ( V_25 , V_6 ,
V_15 ) ;
else
F_9 ( V_25 , V_6 ,
F_10 ( V_26 , V_27 ) ) ;
}
V_20 -> V_30 . V_33 = F_11 ( V_25 ) ;
V_28 = F_1 ( V_2 , V_3 , V_25 ) ;
V_20 -> V_30 . V_34 = F_11 ( V_28 ) ;
return;
}
int F_13 ( struct V_1 * V_2 ,
struct V_35 * V_36 ,
T_2 * * V_37 )
{
struct V_38 * V_20 ;
struct V_39 * V_40 ;
struct V_41 * V_42 ;
struct V_43 * V_44 ;
struct V_10 * V_11 = V_2 -> V_11 ;
T_2 V_45 ;
T_3 V_9 ;
int V_46 = 0 ;
if ( V_36 -> V_47 & V_21 )
V_9 = V_11 -> V_13 ;
else
V_9 = V_11 -> V_14 ;
if ( V_36 -> V_48 ) {
V_20 = (struct V_38 * ) * V_37 ;
memset ( V_20 , 0 , sizeof( * V_20 ) ) ;
V_20 -> V_49 . type = F_11 ( V_50 ) ;
V_20 -> V_49 . V_51 =
F_11 ( sizeof( struct V_19 ) ) ;
memcpy ( ( T_2 * ) V_20 + sizeof( struct V_52 ) ,
( T_2 * ) V_36 -> V_48 ,
F_8 ( V_20 -> V_49 . V_51 ) ) ;
F_6 ( V_2 , & V_20 -> V_20 ,
V_36 -> V_47 ) ;
* V_37 += sizeof( * V_20 ) ;
V_46 += sizeof( * V_20 ) ;
}
if ( V_36 -> V_53 ) {
if ( V_2 -> V_54 == V_55 ) {
V_44 = (struct V_43 * ) * V_37 ;
memset ( V_44 , 0 , sizeof( * V_44 ) ) ;
V_44 -> V_49 . type =
F_11 ( V_56 ) ;
V_44 -> V_49 . V_51 = F_11 ( sizeof( * V_44 ) -
sizeof( struct V_52 ) ) ;
memcpy ( ( T_2 * ) V_44 +
sizeof( struct V_52 ) ,
( T_2 * ) V_36 -> V_53 +
sizeof( struct V_57 ) ,
F_8 ( V_44 -> V_49 . V_51 ) ) ;
V_45 = F_3 ( V_9 ) ;
switch ( V_45 ) {
case 0 :
V_44 -> V_58 =
F_14 ( T_2 , V_59 ,
V_36 -> V_53 -> V_58 ) ;
break;
case 1 :
V_44 -> V_58 =
F_14 ( T_2 , V_60 ,
V_36 -> V_53 -> V_58 ) ;
break;
case 2 :
V_44 -> V_58 =
F_14 ( T_2 , V_61 ,
V_36 -> V_53 -> V_58 ) ;
break;
default:
V_44 -> V_58 =
V_62 ;
break;
}
* V_37 += sizeof( * V_44 ) ;
V_46 += sizeof( * V_44 ) ;
}
}
if ( V_36 -> V_63 ) {
V_42 = V_36 -> V_63 ;
V_40 = ( void * ) * V_37 ;
memset ( V_40 , 0 , sizeof( * V_40 ) ) ;
V_40 -> V_49 . type = F_11 ( V_64 ) ;
V_40 -> V_49 . V_51 = F_11 ( sizeof( T_2 ) ) ;
V_40 -> V_63 = V_42 -> V_63 ;
* V_37 += sizeof( * V_40 ) ;
V_46 += sizeof( * V_40 ) ;
}
return V_46 ;
}
int F_15 ( struct V_1 * V_2 ,
struct V_65 * V_66 , T_1 V_67 ,
struct V_68 * V_69 )
{
struct V_70 * V_71 = & V_66 -> V_72 . V_73 ;
V_66 -> V_74 = F_11 ( V_75 ) ;
V_66 -> V_76 = F_11 ( sizeof( struct V_70 ) +
V_77 ) ;
V_71 -> V_78 = F_11 ( V_67 ) ;
V_71 -> V_79 = V_69 -> V_79 ;
V_71 -> V_80 = V_69 -> V_80 ;
V_71 -> V_81 = F_5 ( V_69 -> V_81 ) ;
V_71 -> V_82 = F_5 ( V_69 -> V_82 ) ;
V_71 -> V_83 = F_5 ( V_69 -> V_83 ) ;
return 0 ;
}
void F_16 ( struct V_1 * V_2 )
{
V_2 -> V_84 . V_85 = V_86 ;
if ( F_17 ( V_2 ) == V_87 ) {
V_2 -> V_84 . V_88 =
V_89 ;
V_2 -> V_84 . V_90 =
V_91 ;
} else {
V_2 -> V_84 . V_88 =
V_92 ;
V_2 -> V_84 . V_90 =
V_93 ;
}
return;
}
bool F_18 ( struct V_1 * V_2 )
{
struct V_35 * V_36 ;
struct V_94 * V_95 ;
V_36 = & V_2 -> V_96 . V_97 ;
V_95 = V_36 -> V_53 ;
if ( ! V_36 -> V_48 || ! V_95 )
return false ;
if ( V_95 -> V_58 == V_62 )
return false ;
return true ;
}
T_2 F_19 ( struct V_1 * V_2 , T_2 V_98 ,
T_3 V_99 , T_2 V_100 )
{
T_2 V_101 = 0 ;
if ( V_98 & V_12 ) {
switch ( V_99 ) {
case 36 :
case 40 :
case 44 :
case 48 :
if ( V_100 == V_59 )
V_101 = 42 ;
break;
case 52 :
case 56 :
case 60 :
case 64 :
if ( V_100 == V_59 )
V_101 = 58 ;
else if ( V_100 == V_60 )
V_101 = 50 ;
break;
case 100 :
case 104 :
case 108 :
case 112 :
if ( V_100 == V_59 )
V_101 = 106 ;
break;
case 116 :
case 120 :
case 124 :
case 128 :
if ( V_100 == V_59 )
V_101 = 122 ;
else if ( V_100 == V_60 )
V_101 = 114 ;
break;
case 132 :
case 136 :
case 140 :
case 144 :
if ( V_100 == V_59 )
V_101 = 138 ;
break;
case 149 :
case 153 :
case 157 :
case 161 :
if ( V_100 == V_59 )
V_101 = 155 ;
break;
default:
V_101 = 42 ;
}
}
return V_101 ;
}
