static T_1
F_1 ( struct V_1 * V_2 ,
T_2 V_3 , T_1 V_4 )
{
T_2 V_5 , V_6 , V_7 ;
T_1 V_8 = 0 ;
T_3 V_9 = 0 ;
struct V_10 * V_11 = V_2 -> V_11 ;
T_1 V_12 [ 8 ] [ 3 ] = {
{ 0x124 , 0x15F , 0x186 } ,
{ 0x249 , 0x2BE , 0x30C } ,
{ 0x36D , 0x41D , 0x492 } ,
{ 0x492 , 0x57C , 0x618 } ,
{ 0x5B6 , 0x6DB , 0x79E } ,
{ 0x6DB , 0x83A , 0x0 } ,
{ 0x7FF , 0x999 , 0xAAA } ,
{ 0x924 , 0xAF8 , 0xC30 }
} ;
T_1 V_13 [ 8 ] [ 3 ] = {
{ 0x249 , 0x2BE , 0x30C } ,
{ 0x492 , 0x57C , 0x618 } ,
{ 0x6DB , 0x83A , 0x0 } ,
{ 0x924 , 0xAF8 , 0xC30 } ,
{ 0xB6D , 0xDB6 , 0xF3C } ,
{ 0xDB6 , 0x1074 , 0x1248 } ,
{ 0xFFF , 0x1332 , 0x1554 } ,
{ 0x1248 , 0x15F0 , 0x1860 }
} ;
if ( V_3 & V_14 )
V_9 = V_11 -> V_15 ;
else
V_9 = V_11 -> V_16 ;
V_6 = 0 ;
for ( V_5 = 0 ; V_5 < 8 ; V_5 ++ ) {
V_7 = ( V_4 >> ( 2 * V_5 ) ) & 0x3 ;
if ( V_7 < 3 )
V_6 = V_5 ;
}
V_7 = ( V_4 >> ( 2 * V_6 ) ) & 0x3 ;
if ( V_7 >= 3 )
V_7 = 2 ;
if ( F_2 ( V_9 ) ) {
V_8 = V_13 [ V_6 ] [ V_7 ] ;
if ( ! V_8 )
V_8 = V_13 [ V_6 ] [ V_7 - 1 ] ;
} else {
V_8 = V_12 [ V_6 ] [ V_7 ] ;
if ( ! V_8 )
V_8 = V_12 [ V_6 ] [ V_7 - 1 ] ;
}
return V_8 ;
}
static void
F_3 ( struct V_1 * V_2 ,
struct V_17 * V_18 , T_2 V_3 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
if ( V_3 & V_19 )
V_18 -> V_18 . V_20 =
F_4 ( V_11 -> V_15 ) ;
else
V_18 -> V_18 . V_20 =
F_4 ( V_11 -> V_16 ) ;
}
static void
F_5 ( struct V_1 * V_2 ,
struct V_17 * V_18 , T_2 V_3 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
T_1 V_21 , V_22 , V_23 ;
T_1 V_24 , V_25 , V_6 , V_26 ;
F_3 ( V_2 , V_18 , V_3 ) ;
V_21 = F_6 ( V_11 -> V_27 ) ;
V_22 = F_7 ( V_18 -> V_18 . V_28 . V_29 ) ;
V_23 = 0 ;
for ( V_6 = 1 ; V_6 <= 8 ; V_6 ++ ) {
V_24 = F_8 ( V_21 , V_6 ) ;
V_25 = F_8 ( V_22 , V_6 ) ;
if ( ( V_24 == V_30 ) ||
( V_25 == V_30 ) )
F_9 ( V_23 , V_6 , V_30 ) ;
else
F_9 ( V_23 , V_6 ,
F_10 ( V_24 , V_25 ) ) ;
}
V_18 -> V_18 . V_28 . V_29 = F_11 ( V_23 ) ;
V_26 = F_1 ( V_2 , V_3 , V_23 ) ;
V_18 -> V_18 . V_28 . V_31 = F_11 ( V_26 ) ;
V_21 = F_12 ( V_11 -> V_27 ) ;
V_22 = F_7 ( V_18 -> V_18 . V_28 . V_32 ) ;
V_23 = 0 ;
for ( V_6 = 1 ; V_6 <= 8 ; V_6 ++ ) {
V_24 = F_8 ( V_21 , V_6 ) ;
V_25 = F_8 ( V_22 , V_6 ) ;
if ( ( V_24 == V_30 ) ||
( V_25 == V_30 ) )
F_9 ( V_23 , V_6 , V_30 ) ;
else
F_9 ( V_23 , V_6 ,
F_10 ( V_24 , V_25 ) ) ;
}
V_18 -> V_18 . V_28 . V_32 = F_11 ( V_23 ) ;
V_26 = F_1 ( V_2 , V_3 , V_23 ) ;
V_18 -> V_18 . V_28 . V_33 = F_11 ( V_26 ) ;
return;
}
int F_13 ( struct V_1 * V_2 ,
struct V_34 * V_35 ,
T_2 * * V_36 )
{
struct V_17 * V_18 ;
struct V_37 * V_38 ;
struct V_39 * V_40 ;
struct V_41 * V_42 ;
struct V_10 * V_11 = V_2 -> V_11 ;
T_2 V_43 ;
T_3 V_9 ;
int V_44 = 0 ;
if ( V_35 -> V_45 & V_19 )
V_9 = V_11 -> V_15 ;
else
V_9 = V_11 -> V_16 ;
if ( V_35 -> V_46 ) {
V_18 = (struct V_17 * ) * V_36 ;
memset ( V_18 , 0 , sizeof( * V_18 ) ) ;
V_18 -> V_47 . type = F_11 ( V_48 ) ;
V_18 -> V_47 . V_49 =
F_11 ( sizeof( struct V_50 ) ) ;
memcpy ( ( T_2 * ) V_18 + sizeof( struct V_51 ) ,
( T_2 * ) V_35 -> V_46 ,
F_7 ( V_18 -> V_47 . V_49 ) ) ;
F_5 ( V_2 , V_18 , V_35 -> V_45 ) ;
* V_36 += sizeof( * V_18 ) ;
V_44 += sizeof( * V_18 ) ;
}
if ( V_35 -> V_52 ) {
if ( V_2 -> V_53 == V_54 ) {
V_42 = (struct V_41 * ) * V_36 ;
memset ( V_42 , 0 , sizeof( * V_42 ) ) ;
V_42 -> V_47 . type =
F_11 ( V_55 ) ;
V_42 -> V_47 . V_49 = F_11 ( sizeof( * V_42 ) -
sizeof( struct V_51 ) ) ;
memcpy ( ( T_2 * ) V_42 +
sizeof( struct V_51 ) ,
( T_2 * ) V_35 -> V_52 +
sizeof( struct V_56 ) ,
F_7 ( V_42 -> V_47 . V_49 ) ) ;
V_43 = F_2 ( V_9 ) ;
switch ( V_43 ) {
case 0 :
V_42 -> V_57 =
F_14 ( T_2 , V_58 ,
V_35 -> V_52 -> V_57 ) ;
break;
case 1 :
V_42 -> V_57 =
F_14 ( T_2 , V_59 ,
V_35 -> V_52 -> V_57 ) ;
break;
case 2 :
V_42 -> V_57 =
F_14 ( T_2 , V_60 ,
V_35 -> V_52 -> V_57 ) ;
break;
default:
V_42 -> V_57 =
V_61 ;
break;
}
* V_36 += sizeof( * V_42 ) ;
V_44 += sizeof( * V_42 ) ;
}
}
if ( V_35 -> V_62 ) {
V_40 = V_35 -> V_62 ;
V_38 = ( void * ) * V_36 ;
memset ( V_38 , 0 , sizeof( * V_38 ) ) ;
V_38 -> V_47 . type = F_11 ( V_63 ) ;
V_38 -> V_47 . V_49 = F_11 ( sizeof( T_2 ) ) ;
V_38 -> V_62 = V_40 -> V_62 ;
* V_36 += sizeof( * V_38 ) ;
V_44 += sizeof( * V_38 ) ;
}
return V_44 ;
}
int F_15 ( struct V_1 * V_2 ,
struct V_64 * V_65 , T_1 V_66 ,
struct V_67 * V_68 )
{
struct V_69 * V_70 = & V_65 -> V_71 . V_72 ;
V_65 -> V_73 = F_11 ( V_74 ) ;
V_65 -> V_75 = F_11 ( sizeof( struct V_69 ) +
V_76 ) ;
V_70 -> V_77 = F_11 ( V_66 ) ;
V_70 -> V_78 = V_68 -> V_78 ;
V_70 -> V_79 = V_68 -> V_79 ;
V_70 -> V_80 = F_4 ( V_68 -> V_80 ) ;
V_70 -> V_81 = F_4 ( V_68 -> V_81 ) ;
V_70 -> V_82 = F_4 ( V_68 -> V_82 ) ;
return 0 ;
}
void F_16 ( struct V_1 * V_2 )
{
V_2 -> V_83 . V_84 = V_85 ;
if ( F_17 ( V_2 ) == V_86 ) {
V_2 -> V_83 . V_87 =
V_88 ;
V_2 -> V_83 . V_89 =
V_90 ;
} else {
V_2 -> V_83 . V_87 =
V_91 ;
V_2 -> V_83 . V_89 =
V_92 ;
}
return;
}
