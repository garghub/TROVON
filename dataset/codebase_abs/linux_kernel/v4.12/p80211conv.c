int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
struct V_4 * V_5 , union V_6 * V_6 ,
struct V_7 * V_8 )
{
T_2 V_9 ;
T_3 V_10 ;
struct V_11 V_12 ;
struct V_13 * V_14 ;
struct V_15 * V_16 ;
int V_17 ;
memcpy ( & V_12 , V_5 -> V_18 , sizeof( V_12 ) ) ;
if ( V_5 -> V_19 <= 0 ) {
F_2 ( L_1 ) ;
return 1 ;
}
if ( V_3 == V_20 ) {
F_2 ( L_2 , V_5 -> V_19 ) ;
} else {
V_10 = F_3 ( V_12 . type ) ;
if ( V_10 <= V_21 ) {
F_2 ( L_3 , V_5 -> V_19 ) ;
F_4 ( V_5 , V_22 ) ;
F_5 ( V_5 , V_10 ) ;
} else {
F_2 ( L_4 , V_5 -> V_19 ) ;
F_4 ( V_5 , V_22 ) ;
V_16 =
(struct V_15 * ) F_6 ( V_5 ,
sizeof( struct V_15 ) ) ;
V_16 -> type = F_7 ( V_10 ) ;
if ( V_3 == V_23 &&
F_8 ( V_10 ) ) {
memcpy ( V_16 -> V_24 , V_25 ,
V_26 ) ;
} else {
memcpy ( V_16 -> V_24 , V_27 ,
V_26 ) ;
}
V_14 =
(struct V_13 * ) F_6 ( V_5 ,
sizeof( struct V_13 ) ) ;
V_14 -> V_28 = 0xAA ;
V_14 -> V_29 = 0xAA ;
V_14 -> V_30 = 0x03 ;
}
}
V_9 = F_9 ( F_10 ( V_31 ) |
F_11 ( V_32 ) ) ;
switch ( V_2 -> V_33 ) {
case V_34 :
memcpy ( V_6 -> V_35 . V_36 , & V_12 . V_37 , V_38 ) ;
memcpy ( V_6 -> V_35 . V_39 , V_2 -> V_40 -> V_41 , V_38 ) ;
memcpy ( V_6 -> V_35 . V_35 , V_2 -> V_42 , V_38 ) ;
break;
case V_43 :
V_9 |= F_9 ( F_12 ( 1 ) ) ;
memcpy ( V_6 -> V_35 . V_36 , V_2 -> V_42 , V_38 ) ;
memcpy ( V_6 -> V_35 . V_39 , V_2 -> V_40 -> V_41 , V_38 ) ;
memcpy ( V_6 -> V_35 . V_35 , & V_12 . V_37 , V_38 ) ;
break;
case V_44 :
V_9 |= F_9 ( F_13 ( 1 ) ) ;
memcpy ( V_6 -> V_35 . V_36 , & V_12 . V_37 , V_38 ) ;
memcpy ( V_6 -> V_35 . V_39 , V_2 -> V_42 , V_38 ) ;
memcpy ( V_6 -> V_35 . V_35 , & V_12 . V_45 , V_38 ) ;
break;
default:
F_14 ( V_2 -> V_40 ,
L_5 ) ;
return 1 ;
}
V_8 -> V_18 = NULL ;
if ( ( V_2 -> V_46 & V_47 ) &&
( V_2 -> V_46 & V_48 ) ) {
V_8 -> V_18 = F_15 ( V_5 -> V_19 , V_49 ) ;
if ( ! V_8 -> V_18 )
return - V_50 ;
V_17 = F_16 ( V_2 , V_5 -> V_18 , V_8 -> V_18 ,
V_5 -> V_19 ,
V_2 -> V_46 & V_51 ,
V_8 -> V_52 , V_8 -> V_53 ) ;
if ( V_17 ) {
F_17 ( V_2 -> V_40 ,
L_6 ,
V_17 ) ;
return 2 ;
}
V_9 |= F_9 ( F_18 ( 1 ) ) ;
}
V_6 -> V_35 . V_9 = V_9 ;
V_6 -> V_35 . V_54 = 0 ;
V_6 -> V_35 . V_55 = 0 ;
return 0 ;
}
static void F_19 ( struct V_1 * V_2 , char * V_56 ,
struct V_57 * V_58 )
{
int V_59 ;
for ( V_59 = 0 ; V_59 < V_2 -> V_60 ; V_59 ++ ) {
if ( ! memcmp ( V_2 -> V_61 [ V_59 ] , V_56 , V_38 ) ) {
V_2 -> V_62 [ V_59 ] . V_63 = V_58 -> signal ;
V_2 -> V_62 [ V_59 ] . V_64 = V_58 -> V_64 ;
V_2 -> V_62 [ V_59 ] . V_65 =
( V_58 -> signal >
V_58 -> V_64 ) ? ( V_58 -> signal -
V_58 -> V_64 ) : 0 ;
V_2 -> V_62 [ V_59 ] . V_66 = 0x7 ;
}
}
}
int F_20 ( struct V_1 * V_2 , T_1 V_3 ,
struct V_4 * V_5 )
{
struct V_67 * V_40 = V_2 -> V_40 ;
T_3 V_9 ;
unsigned int V_68 ;
unsigned int V_69 ;
T_4 V_37 [ V_38 ] ;
T_4 V_45 [ V_38 ] ;
union V_6 * V_70 ;
struct V_11 * V_12 ;
struct V_13 * V_14 ;
struct V_15 * V_16 ;
int V_17 ;
V_68 = V_5 -> V_19 - V_71 - V_72 ;
V_69 = V_71 ;
V_70 = (union V_6 * ) V_5 -> V_18 ;
V_9 = F_21 ( V_70 -> V_35 . V_9 ) ;
if ( ( F_22 ( V_9 ) == 0 ) && ( F_23 ( V_9 ) == 0 ) ) {
F_24 ( V_37 , V_70 -> V_35 . V_36 ) ;
F_24 ( V_45 , V_70 -> V_35 . V_39 ) ;
} else if ( ( F_22 ( V_9 ) == 0 ) &&
( F_23 ( V_9 ) == 1 ) ) {
F_24 ( V_37 , V_70 -> V_35 . V_36 ) ;
F_24 ( V_45 , V_70 -> V_35 . V_35 ) ;
} else if ( ( F_22 ( V_9 ) == 1 ) &&
( F_23 ( V_9 ) == 0 ) ) {
F_24 ( V_37 , V_70 -> V_35 . V_35 ) ;
F_24 ( V_45 , V_70 -> V_35 . V_39 ) ;
} else {
V_69 = V_73 ;
if ( V_68 < V_73 - V_71 ) {
F_14 ( V_40 , L_7 ) ;
return 1 ;
}
V_68 -= ( V_73 - V_71 ) ;
F_24 ( V_37 , V_70 -> V_74 . V_35 ) ;
F_24 ( V_45 , V_70 -> V_74 . V_74 ) ;
}
if ( ( V_2 -> V_46 & V_47 ) &&
F_25 ( V_9 ) &&
( V_2 -> V_46 & V_75 ) ) {
if ( V_68 <= 8 ) {
F_14 ( V_40 ,
L_8 , V_5 -> V_19 ) ;
return 1 ;
}
V_17 = F_26 ( V_2 , V_5 -> V_18 + V_69 + 4 ,
V_68 - 8 , - 1 ,
V_5 -> V_18 + V_69 ,
V_5 -> V_18 + V_69 +
V_68 - 4 ) ;
if ( V_17 ) {
F_2 ( L_9 ,
V_17 ) ;
V_2 -> V_76 . V_77 ++ ;
return 2 ;
}
V_68 -= 8 ;
F_4 ( V_5 , 4 ) ;
F_5 ( V_5 , V_5 -> V_19 - 4 ) ;
V_2 -> V_76 . V_78 ++ ;
}
V_12 = (struct V_11 * ) ( V_5 -> V_18 + V_69 ) ;
V_14 = (struct V_13 * ) ( V_5 -> V_18 + V_69 ) ;
V_16 =
(struct V_15 * ) ( V_5 -> V_18 + V_69 +
sizeof( struct V_13 ) ) ;
if ( ( V_68 >= sizeof( struct V_11 ) ) &&
( V_14 -> V_28 != 0xaa || V_14 -> V_29 != 0xaa ) &&
( ( ! F_27 ( V_37 , V_12 -> V_37 ) ) ||
( ! F_27 ( V_45 , V_12 -> V_45 ) ) ) ) {
F_2 ( L_10 , V_68 ) ;
if ( V_68 > ( V_40 -> V_79 + V_22 ) ) {
F_14 ( V_40 , L_11 ,
V_68 , V_40 -> V_79 + V_22 ) ;
return 1 ;
}
F_4 ( V_5 , V_69 ) ;
F_5 ( V_5 , V_5 -> V_19 - V_72 ) ;
} else if ( ( V_68 >= sizeof( struct V_13 ) +
sizeof( struct V_15 ) ) &&
( V_14 -> V_28 == 0xaa ) &&
( V_14 -> V_29 == 0xaa ) &&
( V_14 -> V_30 == 0x03 ) &&
( ( ( memcmp ( V_16 -> V_24 , V_27 ,
V_26 ) == 0 ) &&
( V_3 == V_23 ) &&
( F_8 ( F_28 ( V_16 -> type ) ) ) ) ||
( memcmp ( V_16 -> V_24 , V_27 , V_26 ) !=
0 ) ) ) {
F_2 ( L_12 , V_68 ) ;
if ( V_68 > V_40 -> V_79 ) {
F_14 ( V_40 , L_13 ,
V_68 , V_40 -> V_79 ) ;
return 1 ;
}
F_4 ( V_5 , V_69 ) ;
V_12 = (struct V_11 * ) F_6 ( V_5 , V_22 ) ;
F_24 ( V_12 -> V_37 , V_37 ) ;
F_24 ( V_12 -> V_45 , V_45 ) ;
V_12 -> type = F_7 ( V_68 ) ;
F_5 ( V_5 , V_5 -> V_19 - V_72 ) ;
} else if ( ( V_68 >= sizeof( struct V_13 ) +
sizeof( struct V_15 ) ) &&
( V_14 -> V_28 == 0xaa ) &&
( V_14 -> V_29 == 0xaa ) &&
( V_14 -> V_30 == 0x03 ) ) {
F_2 ( L_14 , V_68 ) ;
if ( ( V_68 - sizeof( struct V_13 ) -
sizeof( struct V_15 ) )
> V_40 -> V_79 ) {
F_14 ( V_40 , L_15 ,
( long int ) ( V_68 -
sizeof( struct V_13 ) -
sizeof( struct V_15 ) ) , V_40 -> V_79 ) ;
return 1 ;
}
F_4 ( V_5 , V_69 ) ;
F_4 ( V_5 , sizeof( struct V_13 ) ) ;
F_4 ( V_5 , sizeof( struct V_15 ) ) ;
V_12 = (struct V_11 * ) F_6 ( V_5 , V_22 ) ;
V_12 -> type = V_16 -> type ;
F_24 ( V_12 -> V_37 , V_37 ) ;
F_24 ( V_12 -> V_45 , V_45 ) ;
F_5 ( V_5 , V_5 -> V_19 - V_72 ) ;
} else {
F_2 ( L_16 , V_68 ) ;
if ( V_68 > V_40 -> V_79 ) {
F_14 ( V_40 , L_17 ,
V_68 , V_40 -> V_79 ) ;
return 1 ;
}
F_4 ( V_5 , V_69 ) ;
V_12 = (struct V_11 * ) F_6 ( V_5 , V_22 ) ;
F_24 ( V_12 -> V_37 , V_37 ) ;
F_24 ( V_12 -> V_45 , V_45 ) ;
V_12 -> type = F_7 ( V_68 ) ;
F_5 ( V_5 , V_5 -> V_19 - V_72 ) ;
}
V_5 -> V_80 = F_29 ( V_5 , V_40 ) ;
if ( V_2 -> V_60 )
F_19 ( V_2 , F_30 ( V_5 ) -> V_81 ,
F_31 ( V_5 ) ) ;
F_32 ( V_5 ) ;
return 0 ;
}
int F_8 ( T_3 V_10 )
{
if ( V_10 == V_82 )
return 1 ;
return 0 ;
}
void F_32 ( struct V_4 * V_5 )
{
struct V_57 * V_58 ;
struct V_83 * V_84 ;
if ( ! V_5 ) {
F_2 ( L_18 ) ;
return;
}
V_84 = F_33 ( V_5 ) ;
if ( ! V_84 ) {
F_2 ( L_19 ) ;
return;
}
V_58 = V_84 -> V_76 ;
if ( ! V_58 ) {
F_2 ( L_20 ) ;
return;
}
F_34 ( V_58 ) ;
memset ( V_5 -> V_85 , 0 , sizeof( V_5 -> V_85 ) ) ;
}
int F_35 ( struct V_1 * V_2 , struct V_4 * V_5 )
{
int V_86 = 0 ;
struct V_57 * V_58 ;
struct V_83 * V_84 ;
if ( F_31 ( V_5 ) ) {
F_14 ( V_2 -> V_40 ,
L_21 , V_2 -> V_87 ) ;
V_86 = 0 ;
goto exit;
}
V_58 = F_36 ( sizeof( * V_58 ) , V_49 ) ;
if ( ! V_58 ) {
V_86 = 1 ;
goto exit;
}
V_58 -> V_2 = V_2 ;
V_58 -> V_88 = V_89 ;
memset ( V_5 -> V_85 , 0 , sizeof( struct V_83 ) ) ;
V_84 = (struct V_83 * ) ( V_5 -> V_85 ) ;
V_84 -> V_90 = V_91 ;
V_84 -> V_76 = V_58 ;
exit:
return V_86 ;
}
void F_37 ( struct V_1 * V_2 , struct V_4 * V_5 )
{
struct V_83 * V_92 ;
V_92 = F_33 ( V_5 ) ;
if ( V_92 && V_92 -> V_76 )
F_32 ( V_5 ) ;
else
F_14 ( V_2 -> V_40 ,
L_22 , V_5 ) ;
F_38 ( V_5 ) ;
}
