int F_1 ( T_1 * V_1 , T_2 V_2 ,
struct V_3 * V_4 , union V_5 * V_5 ,
struct V_6 * V_7 )
{
T_3 V_8 ;
T_4 V_9 ;
struct V_10 V_11 ;
struct V_12 * V_13 ;
struct V_14 * V_15 ;
int V_16 ;
memcpy ( & V_11 , V_4 -> V_17 , sizeof( V_11 ) ) ;
if ( V_4 -> V_18 <= 0 ) {
F_2 ( L_1 ) ;
return 1 ;
}
if ( V_2 == V_19 ) {
F_2 ( L_2 , V_4 -> V_18 ) ;
} else {
V_9 = F_3 ( V_11 . type ) ;
if ( V_9 <= V_20 ) {
F_2 ( L_3 , V_4 -> V_18 ) ;
F_4 ( V_4 , V_21 ) ;
F_5 ( V_4 , V_9 ) ;
} else {
F_2 ( L_4 , V_4 -> V_18 ) ;
F_4 ( V_4 , V_21 ) ;
V_15 =
(struct V_14 * ) F_6 ( V_4 ,
sizeof( struct V_14 ) ) ;
V_15 -> type = F_7 ( V_9 ) ;
if ( V_2 == V_22
&& F_8 ( V_9 ) ) {
memcpy ( V_15 -> V_23 , V_24 ,
V_25 ) ;
} else {
memcpy ( V_15 -> V_23 , V_26 ,
V_25 ) ;
}
V_13 =
(struct V_12 * ) F_6 ( V_4 ,
sizeof( struct V_12 ) ) ;
V_13 -> V_27 = 0xAA ;
V_13 -> V_28 = 0xAA ;
V_13 -> V_29 = 0x03 ;
}
}
V_8 = F_9 ( F_10 ( V_30 ) |
F_11 ( V_31 ) ) ;
switch ( V_1 -> V_32 ) {
case V_33 :
memcpy ( V_5 -> V_34 . V_35 , & V_11 . V_36 , V_37 ) ;
memcpy ( V_5 -> V_34 . V_38 , V_1 -> V_39 -> V_40 , V_37 ) ;
memcpy ( V_5 -> V_34 . V_34 , V_1 -> V_41 , V_37 ) ;
break;
case V_42 :
V_8 |= F_9 ( F_12 ( 1 ) ) ;
memcpy ( V_5 -> V_34 . V_35 , V_1 -> V_41 , V_37 ) ;
memcpy ( V_5 -> V_34 . V_38 , V_1 -> V_39 -> V_40 , V_37 ) ;
memcpy ( V_5 -> V_34 . V_34 , & V_11 . V_36 , V_37 ) ;
break;
case V_43 :
V_8 |= F_9 ( F_13 ( 1 ) ) ;
memcpy ( V_5 -> V_34 . V_35 , & V_11 . V_36 , V_37 ) ;
memcpy ( V_5 -> V_34 . V_38 , V_1 -> V_41 , V_37 ) ;
memcpy ( V_5 -> V_34 . V_34 , & V_11 . V_44 , V_37 ) ;
break;
default:
F_14 ( V_1 -> V_39 ,
L_5 ) ;
return 1 ;
}
V_7 -> V_17 = NULL ;
if ( ( V_1 -> V_45 & V_46 )
&& ( V_1 -> V_45 & V_47 ) ) {
V_7 -> V_17 = F_15 ( V_4 -> V_18 , V_48 ) ;
if ( ! V_7 -> V_17 )
return - V_49 ;
V_16 = F_16 ( V_1 , V_4 -> V_17 , V_7 -> V_17 ,
V_4 -> V_18 ,
( V_1 -> V_45 & V_50 ) ,
V_7 -> V_51 , V_7 -> V_52 ) ;
if ( V_16 ) {
F_17 ( V_1 -> V_39 ,
L_6 ,
V_16 ) ;
return 2 ;
}
V_8 |= F_9 ( F_18 ( 1 ) ) ;
}
V_5 -> V_34 . V_8 = V_8 ;
V_5 -> V_34 . V_53 = 0 ;
V_5 -> V_34 . V_54 = 0 ;
return 0 ;
}
static void F_19 ( T_1 * V_1 , char * V_55 ,
struct V_56 * V_57 )
{
int V_58 ;
for ( V_58 = 0 ; V_58 < V_1 -> V_59 ; V_58 ++ ) {
if ( ! memcmp ( V_1 -> V_60 [ V_58 ] , V_55 , V_37 ) ) {
memcpy ( V_1 -> V_60 [ V_58 ] , V_55 , V_37 ) ;
V_1 -> V_61 [ V_58 ] . V_62 = V_57 -> signal ;
V_1 -> V_61 [ V_58 ] . V_63 = V_57 -> V_63 ;
V_1 -> V_61 [ V_58 ] . V_64 =
( V_57 -> signal >
V_57 -> V_63 ) ? ( V_57 -> signal -
V_57 -> V_63 ) : 0 ;
V_1 -> V_61 [ V_58 ] . V_65 = 0x7 ;
}
}
}
int F_20 ( T_1 * V_1 , T_2 V_2 ,
struct V_3 * V_4 )
{
T_5 * V_39 = V_1 -> V_39 ;
T_4 V_8 ;
unsigned int V_66 ;
unsigned int V_67 ;
T_6 V_36 [ V_37 ] ;
T_6 V_44 [ V_37 ] ;
union V_5 * V_68 ;
struct V_10 * V_11 ;
struct V_12 * V_13 ;
struct V_14 * V_15 ;
int V_16 ;
V_66 = V_4 -> V_18 - V_69 - V_70 ;
V_67 = V_69 ;
V_68 = (union V_5 * ) V_4 -> V_17 ;
V_8 = F_21 ( V_68 -> V_34 . V_8 ) ;
if ( ( F_22 ( V_8 ) == 0 ) && ( F_23 ( V_8 ) == 0 ) ) {
F_24 ( V_36 , V_68 -> V_34 . V_35 ) ;
F_24 ( V_44 , V_68 -> V_34 . V_38 ) ;
} else if ( ( F_22 ( V_8 ) == 0 )
&& ( F_23 ( V_8 ) == 1 ) ) {
F_24 ( V_36 , V_68 -> V_34 . V_35 ) ;
F_24 ( V_44 , V_68 -> V_34 . V_34 ) ;
} else if ( ( F_22 ( V_8 ) == 1 )
&& ( F_23 ( V_8 ) == 0 ) ) {
F_24 ( V_36 , V_68 -> V_34 . V_34 ) ;
F_24 ( V_44 , V_68 -> V_34 . V_38 ) ;
} else {
V_67 = V_71 ;
if ( V_66 < V_71 - V_69 ) {
F_14 ( V_39 , L_7 ) ;
return 1 ;
}
V_66 -= ( V_71 - V_69 ) ;
F_24 ( V_36 , V_68 -> V_72 . V_34 ) ;
F_24 ( V_44 , V_68 -> V_72 . V_72 ) ;
}
if ( ( V_1 -> V_45 & V_46 ) && F_25 ( V_8 )
&& ( V_1 -> V_45 & V_73 ) ) {
if ( V_66 <= 8 ) {
F_14 ( V_39 ,
L_8 , V_4 -> V_18 ) ;
return 1 ;
}
V_16 = F_26 ( V_1 , V_4 -> V_17 + V_67 + 4 ,
V_66 - 8 , - 1 ,
V_4 -> V_17 + V_67 ,
V_4 -> V_17 + V_67 +
V_66 - 4 ) ;
if ( V_16 ) {
F_2 ( L_9 ,
V_16 ) ;
V_1 -> V_74 . V_75 ++ ;
return 2 ;
}
V_66 -= 8 ;
F_4 ( V_4 , 4 ) ;
F_5 ( V_4 , V_4 -> V_18 - 4 ) ;
V_1 -> V_74 . V_76 ++ ;
}
V_11 = (struct V_10 * ) ( V_4 -> V_17 + V_67 ) ;
V_13 = (struct V_12 * ) ( V_4 -> V_17 + V_67 ) ;
V_15 =
(struct V_14 * ) ( V_4 -> V_17 + V_67 +
sizeof( struct V_12 ) ) ;
if ( ( V_66 >= sizeof( struct V_10 ) ) &&
( V_13 -> V_27 != 0xaa || V_13 -> V_28 != 0xaa ) &&
( ( ! F_27 ( V_36 , V_11 -> V_36 ) ) ||
( ! F_27 ( V_44 , V_11 -> V_44 ) ) ) ) {
F_2 ( L_10 , V_66 ) ;
if ( V_66 > ( V_39 -> V_77 + V_21 ) ) {
F_14 ( V_39 , L_11 ,
V_66 , V_39 -> V_77 + V_21 ) ;
return 1 ;
}
F_4 ( V_4 , V_67 ) ;
F_5 ( V_4 , V_4 -> V_18 - V_70 ) ;
} else if ( ( V_66 >= sizeof( struct V_12 ) +
sizeof( struct V_14 ) )
&& ( V_13 -> V_27 == 0xaa )
&& ( V_13 -> V_28 == 0xaa )
&& ( V_13 -> V_29 == 0x03 )
&&
( ( ( memcmp ( V_15 -> V_23 , V_26 , V_25 ) == 0 )
&& ( V_2 == V_22 )
&& ( F_8 ( F_21 ( V_15 -> type ) ) ) )
|| ( memcmp ( V_15 -> V_23 , V_26 , V_25 ) !=
0 ) ) ) {
F_2 ( L_12 , V_66 ) ;
if ( V_66 > V_39 -> V_77 ) {
F_14 ( V_39 , L_13 ,
V_66 , V_39 -> V_77 ) ;
return 1 ;
}
F_4 ( V_4 , V_67 ) ;
V_11 = (struct V_10 * ) F_6 ( V_4 , V_21 ) ;
F_24 ( V_11 -> V_36 , V_36 ) ;
F_24 ( V_11 -> V_44 , V_44 ) ;
V_11 -> type = F_7 ( V_66 ) ;
F_5 ( V_4 , V_4 -> V_18 - V_70 ) ;
} else if ( ( V_66 >= sizeof( struct V_12 ) +
sizeof( struct V_14 ) )
&& ( V_13 -> V_27 == 0xaa )
&& ( V_13 -> V_28 == 0xaa )
&& ( V_13 -> V_29 == 0x03 ) ) {
F_2 ( L_14 , V_66 ) ;
if ( ( V_66 - sizeof( struct V_12 ) -
sizeof( struct V_14 ) )
> V_39 -> V_77 ) {
F_14 ( V_39 , L_15 ,
( long int ) ( V_66 -
sizeof( struct V_12 ) -
sizeof( struct V_14 ) ) , V_39 -> V_77 ) ;
return 1 ;
}
F_4 ( V_4 , V_67 ) ;
F_4 ( V_4 , sizeof( struct V_12 ) ) ;
F_4 ( V_4 , sizeof( struct V_14 ) ) ;
V_11 = (struct V_10 * ) F_6 ( V_4 , V_21 ) ;
V_11 -> type = V_15 -> type ;
F_24 ( V_11 -> V_36 , V_36 ) ;
F_24 ( V_11 -> V_44 , V_44 ) ;
F_5 ( V_4 , V_4 -> V_18 - V_70 ) ;
} else {
F_2 ( L_16 , V_66 ) ;
if ( V_66 > V_39 -> V_77 ) {
F_14 ( V_39 , L_17 ,
V_66 , V_39 -> V_77 ) ;
return 1 ;
}
F_4 ( V_4 , V_67 ) ;
V_11 = (struct V_10 * ) F_6 ( V_4 , V_21 ) ;
F_24 ( V_11 -> V_36 , V_36 ) ;
F_24 ( V_11 -> V_44 , V_44 ) ;
V_11 -> type = F_7 ( V_66 ) ;
F_5 ( V_4 , V_4 -> V_18 - V_70 ) ;
}
V_4 -> V_78 = F_28 ( V_4 , V_39 ) ;
if ( V_1 -> V_59 )
F_19 ( V_1 , F_29 ( V_4 ) -> V_79 ,
F_30 ( V_4 ) ) ;
F_31 ( V_4 ) ;
return 0 ;
}
int F_8 ( T_4 V_9 )
{
if ( V_9 == V_80 )
return 1 ;
return 0 ;
}
void F_31 ( struct V_3 * V_4 )
{
struct V_56 * V_57 ;
struct V_81 * V_82 ;
if ( V_4 == NULL ) {
F_2 ( L_18 ) ;
return;
}
V_82 = F_32 ( V_4 ) ;
if ( V_82 == NULL ) {
F_2 ( L_19 ) ;
return;
}
V_57 = V_82 -> V_74 ;
if ( V_57 == NULL ) {
F_2 ( L_20 ) ;
return;
}
F_33 ( V_57 ) ;
memset ( V_4 -> V_83 , 0 , sizeof( V_4 -> V_83 ) ) ;
}
int F_34 ( struct V_84 * V_1 , struct V_3 * V_4 )
{
int V_85 = 0 ;
struct V_56 * V_57 ;
struct V_81 * V_82 ;
if ( F_30 ( V_4 ) != NULL ) {
F_14 ( V_1 -> V_39 ,
L_21 , V_1 -> V_86 ) ;
V_85 = 0 ;
goto exit;
}
V_57 = F_35 ( sizeof( struct V_56 ) , V_48 ) ;
if ( V_57 == NULL ) {
F_14 ( V_1 -> V_39 ,
L_22 , V_1 -> V_86 ) ;
V_85 = 1 ;
goto exit;
}
V_57 -> V_1 = V_1 ;
V_57 -> V_87 = V_88 ;
memset ( V_4 -> V_83 , 0 , sizeof( struct V_81 ) ) ;
V_82 = (struct V_81 * ) ( V_4 -> V_83 ) ;
V_82 -> V_89 = V_90 ;
V_82 -> V_74 = V_57 ;
exit:
return V_85 ;
}
void F_36 ( struct V_84 * V_1 , struct V_3 * V_4 )
{
struct V_81 * V_91 ;
V_91 = F_32 ( V_4 ) ;
if ( V_91 && V_91 -> V_74 )
F_31 ( V_4 ) ;
else
F_14 ( V_1 -> V_39 ,
L_23 , V_4 ) ;
F_37 ( V_4 ) ;
}
