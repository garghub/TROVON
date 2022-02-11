int F_1 ( T_1 * V_1 , T_2 V_2 ,
struct V_3 * V_4 , union V_5 * V_5 ,
struct V_6 * V_7 )
{
T_3 V_8 ;
T_3 V_9 ;
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
if ( V_9 <= 1500 ) {
F_2 ( L_3 , V_4 -> V_18 ) ;
F_4 ( V_4 , V_20 ) ;
F_5 ( V_4 , V_9 ) ;
} else {
F_2 ( L_4 , V_4 -> V_18 ) ;
F_4 ( V_4 , V_20 ) ;
V_15 =
(struct V_14 * ) F_6 ( V_4 ,
sizeof( struct V_14 ) ) ;
V_15 -> type = F_7 ( V_9 ) ;
if ( V_2 == V_21
&& F_8 ( V_9 ) ) {
memcpy ( V_15 -> V_22 , V_23 ,
V_24 ) ;
} else {
memcpy ( V_15 -> V_22 , V_25 ,
V_24 ) ;
}
V_13 =
(struct V_12 * ) F_6 ( V_4 ,
sizeof( struct V_12 ) ) ;
V_13 -> V_26 = 0xAA ;
V_13 -> V_27 = 0xAA ;
V_13 -> V_28 = 0x03 ;
}
}
V_8 = F_9 ( F_10 ( V_29 ) |
F_11 ( V_30 ) ) ;
switch ( V_1 -> V_31 ) {
case V_32 :
memcpy ( V_5 -> V_33 . V_34 , & V_11 . V_35 , V_36 ) ;
memcpy ( V_5 -> V_33 . V_37 , V_1 -> V_38 -> V_39 , V_36 ) ;
memcpy ( V_5 -> V_33 . V_33 , V_1 -> V_40 , V_36 ) ;
break;
case V_41 :
V_8 |= F_9 ( F_12 ( 1 ) ) ;
memcpy ( V_5 -> V_33 . V_34 , V_1 -> V_40 , V_36 ) ;
memcpy ( V_5 -> V_33 . V_37 , V_1 -> V_38 -> V_39 , V_36 ) ;
memcpy ( V_5 -> V_33 . V_33 , & V_11 . V_35 , V_36 ) ;
break;
case V_42 :
V_8 |= F_9 ( F_13 ( 1 ) ) ;
memcpy ( V_5 -> V_33 . V_34 , & V_11 . V_35 , V_36 ) ;
memcpy ( V_5 -> V_33 . V_37 , V_1 -> V_40 , V_36 ) ;
memcpy ( V_5 -> V_33 . V_33 , & V_11 . V_43 , V_36 ) ;
break;
default:
F_14 ( V_1 -> V_38 ,
L_5 ) ;
return 1 ;
break;
}
V_7 -> V_17 = NULL ;
if ( ( V_1 -> V_44 & V_45 )
&& ( V_1 -> V_44 & V_46 ) ) {
V_7 -> V_17 = F_15 ( V_4 -> V_18 , V_47 ) ;
V_16 = F_16 ( V_1 , V_4 -> V_17 , V_7 -> V_17 ,
V_4 -> V_18 ,
( V_1 -> V_44 & V_48 ) ,
V_7 -> V_49 , V_7 -> V_50 ) ;
if ( V_16 ) {
F_17 ( V_1 -> V_38 ,
L_6 ,
V_16 ) ;
return 2 ;
}
V_8 |= F_9 ( F_18 ( 1 ) ) ;
}
V_5 -> V_33 . V_8 = V_8 ;
V_5 -> V_33 . V_51 = 0 ;
V_5 -> V_33 . V_52 = 0 ;
return 0 ;
}
static void F_19 ( T_1 * V_1 , char * V_53 ,
struct V_54 * V_55 )
{
int V_56 ;
for ( V_56 = 0 ; V_56 < V_1 -> V_57 ; V_56 ++ ) {
if ( ! memcmp ( V_1 -> V_58 [ V_56 ] , V_53 , V_36 ) ) {
memcpy ( V_1 -> V_58 [ V_56 ] , V_53 , V_36 ) ;
V_1 -> V_59 [ V_56 ] . V_60 = V_55 -> signal ;
V_1 -> V_59 [ V_56 ] . V_61 = V_55 -> V_61 ;
V_1 -> V_59 [ V_56 ] . V_62 =
( V_55 -> signal >
V_55 -> V_61 ) ? ( V_55 -> signal -
V_55 -> V_61 ) : 0 ;
V_1 -> V_59 [ V_56 ] . V_63 = 0x7 ;
}
}
}
int F_20 ( T_1 * V_1 , T_2 V_2 ,
struct V_3 * V_4 )
{
T_4 * V_38 = V_1 -> V_38 ;
T_3 V_8 ;
unsigned int V_64 ;
unsigned int V_65 ;
T_5 V_35 [ V_66 ] ;
T_5 V_43 [ V_66 ] ;
union V_5 * V_67 ;
struct V_10 * V_11 ;
struct V_12 * V_13 ;
struct V_14 * V_15 ;
int V_16 ;
V_64 = V_4 -> V_18 - V_68 - V_69 ;
V_65 = V_68 ;
V_67 = (union V_5 * ) V_4 -> V_17 ;
V_8 = F_21 ( V_67 -> V_33 . V_8 ) ;
if ( ( F_22 ( V_8 ) == 0 ) && ( F_23 ( V_8 ) == 0 ) ) {
memcpy ( V_35 , V_67 -> V_33 . V_34 , V_66 ) ;
memcpy ( V_43 , V_67 -> V_33 . V_37 , V_66 ) ;
} else if ( ( F_22 ( V_8 ) == 0 )
&& ( F_23 ( V_8 ) == 1 ) ) {
memcpy ( V_35 , V_67 -> V_33 . V_34 , V_66 ) ;
memcpy ( V_43 , V_67 -> V_33 . V_33 , V_66 ) ;
} else if ( ( F_22 ( V_8 ) == 1 )
&& ( F_23 ( V_8 ) == 0 ) ) {
memcpy ( V_35 , V_67 -> V_33 . V_33 , V_66 ) ;
memcpy ( V_43 , V_67 -> V_33 . V_37 , V_66 ) ;
} else {
V_65 = V_70 ;
if ( V_64 < V_70 - V_68 ) {
F_14 ( V_38 , L_7 ) ;
return 1 ;
}
V_64 -= ( V_70 - V_68 ) ;
memcpy ( V_35 , V_67 -> V_71 . V_33 , V_66 ) ;
memcpy ( V_43 , V_67 -> V_71 . V_71 , V_66 ) ;
}
if ( ( V_1 -> V_44 & V_45 ) && F_24 ( V_8 )
&& ( V_1 -> V_44 & V_72 ) ) {
if ( V_64 <= 8 ) {
F_14 ( V_38 ,
L_8 , V_4 -> V_18 ) ;
return 1 ;
}
V_16 = F_25 ( V_1 , V_4 -> V_17 + V_65 + 4 ,
V_64 - 8 , - 1 ,
V_4 -> V_17 + V_65 ,
V_4 -> V_17 + V_65 +
V_64 - 4 ) ;
if ( V_16 ) {
F_2 ( L_9 ,
V_16 ) ;
V_1 -> V_73 . V_74 ++ ;
return 2 ;
}
V_64 -= 8 ;
F_4 ( V_4 , 4 ) ;
F_5 ( V_4 , V_4 -> V_18 - 4 ) ;
V_1 -> V_73 . V_75 ++ ;
}
V_11 = (struct V_10 * ) ( V_4 -> V_17 + V_65 ) ;
V_13 = (struct V_12 * ) ( V_4 -> V_17 + V_65 ) ;
V_15 =
(struct V_14 * ) ( V_4 -> V_17 + V_65 +
sizeof( struct V_12 ) ) ;
if ( ( V_64 >= sizeof( struct V_10 ) ) &&
( V_13 -> V_26 != 0xaa || V_13 -> V_27 != 0xaa ) &&
( ( memcmp ( V_35 , V_11 -> V_35 , V_66 ) == 0 ) ||
( memcmp ( V_43 , V_11 -> V_43 , V_66 ) == 0 ) ) ) {
F_2 ( L_10 , V_64 ) ;
if ( V_64 > ( V_38 -> V_76 + V_20 ) ) {
F_14 ( V_38 , L_11 ,
V_64 , V_38 -> V_76 + V_20 ) ;
return 1 ;
}
F_4 ( V_4 , V_65 ) ;
F_5 ( V_4 , V_4 -> V_18 - V_69 ) ;
} else if ( ( V_64 >= sizeof( struct V_12 ) +
sizeof( struct V_14 ) )
&& ( V_13 -> V_26 == 0xaa )
&& ( V_13 -> V_27 == 0xaa )
&& ( V_13 -> V_28 == 0x03 )
&&
( ( ( memcmp ( V_15 -> V_22 , V_25 , V_24 ) == 0 )
&& ( V_2 == V_21 )
&& ( F_8 ( F_21 ( V_15 -> type ) ) ) )
|| ( memcmp ( V_15 -> V_22 , V_25 , V_24 ) !=
0 ) ) ) {
F_2 ( L_12 , V_64 ) ;
if ( V_64 > V_38 -> V_76 ) {
F_14 ( V_38 , L_13 ,
V_64 , V_38 -> V_76 ) ;
return 1 ;
}
F_4 ( V_4 , V_65 ) ;
V_11 = (struct V_10 * ) F_6 ( V_4 , V_20 ) ;
memcpy ( V_11 -> V_35 , V_35 , V_66 ) ;
memcpy ( V_11 -> V_43 , V_43 , V_66 ) ;
V_11 -> type = F_7 ( V_64 ) ;
F_5 ( V_4 , V_4 -> V_18 - V_69 ) ;
} else if ( ( V_64 >= sizeof( struct V_12 ) +
sizeof( struct V_14 ) )
&& ( V_13 -> V_26 == 0xaa )
&& ( V_13 -> V_27 == 0xaa )
&& ( V_13 -> V_28 == 0x03 ) ) {
F_2 ( L_14 , V_64 ) ;
if ( ( V_64 - sizeof( struct V_12 ) -
sizeof( struct V_14 ) )
> V_38 -> V_76 ) {
F_14 ( V_38 , L_15 ,
( long int ) ( V_64 -
sizeof( struct V_12 ) -
sizeof( struct V_14 ) ) , V_38 -> V_76 ) ;
return 1 ;
}
F_4 ( V_4 , V_65 ) ;
F_4 ( V_4 , sizeof( struct V_12 ) ) ;
F_4 ( V_4 , sizeof( struct V_14 ) ) ;
V_11 = (struct V_10 * ) F_6 ( V_4 , V_20 ) ;
V_11 -> type = V_15 -> type ;
memcpy ( V_11 -> V_35 , V_35 , V_66 ) ;
memcpy ( V_11 -> V_43 , V_43 , V_66 ) ;
F_5 ( V_4 , V_4 -> V_18 - V_69 ) ;
} else {
F_2 ( L_16 , V_64 ) ;
if ( V_64 > V_38 -> V_76 ) {
F_14 ( V_38 , L_17 ,
V_64 , V_38 -> V_76 ) ;
return 1 ;
}
F_4 ( V_4 , V_65 ) ;
V_11 = (struct V_10 * ) F_6 ( V_4 , V_20 ) ;
memcpy ( V_11 -> V_35 , V_35 , V_66 ) ;
memcpy ( V_11 -> V_43 , V_43 , V_66 ) ;
V_11 -> type = F_7 ( V_64 ) ;
F_5 ( V_4 , V_4 -> V_18 - V_69 ) ;
}
V_4 -> V_77 = F_26 ( V_4 , V_38 ) ;
if ( V_1 -> V_57 )
F_19 ( V_1 , F_27 ( V_4 ) -> V_78 ,
F_28 ( V_4 ) ) ;
F_29 ( V_4 ) ;
return 0 ;
}
int F_8 ( T_3 V_9 )
{
if ( V_9 == 0x80f3 )
return 1 ;
return 0 ;
}
void F_29 ( struct V_3 * V_4 )
{
struct V_54 * V_55 ;
struct V_79 * V_80 ;
if ( V_4 == NULL ) {
F_2 ( L_18 ) ;
return;
}
V_80 = F_30 ( V_4 ) ;
if ( V_80 == NULL ) {
F_2 ( L_19 ) ;
return;
}
V_55 = V_80 -> V_73 ;
if ( V_55 == NULL ) {
F_2 ( L_20 ) ;
return;
}
F_31 ( V_55 ) ;
memset ( V_4 -> V_81 , 0 , sizeof( V_4 -> V_81 ) ) ;
}
int F_32 ( struct V_82 * V_1 , struct V_3 * V_4 )
{
int V_83 = 0 ;
struct V_54 * V_55 ;
struct V_79 * V_80 ;
if ( F_28 ( V_4 ) != NULL ) {
F_14 ( V_1 -> V_38 ,
L_21 , V_1 -> V_84 ) ;
V_83 = 0 ;
goto exit;
}
V_55 = F_33 ( sizeof( struct V_54 ) , V_47 ) ;
if ( V_55 == NULL ) {
F_14 ( V_1 -> V_38 ,
L_22 , V_1 -> V_84 ) ;
V_83 = 1 ;
goto exit;
}
V_55 -> V_1 = V_1 ;
V_55 -> V_85 = V_86 ;
memset ( V_4 -> V_81 , 0 , sizeof( struct V_79 ) ) ;
V_80 = (struct V_79 * ) ( V_4 -> V_81 ) ;
V_80 -> V_87 = V_88 ;
V_80 -> V_73 = V_55 ;
exit:
return V_83 ;
}
void F_34 ( struct V_82 * V_1 , struct V_3 * V_4 )
{
struct V_79 * V_89 ;
V_89 = F_30 ( V_4 ) ;
if ( V_89 && V_89 -> V_73 )
F_29 ( V_4 ) ;
else
F_14 ( V_1 -> V_38 ,
L_23 , V_4 ) ;
F_35 ( V_4 ) ;
}
