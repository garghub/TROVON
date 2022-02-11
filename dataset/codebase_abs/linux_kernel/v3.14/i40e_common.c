T_1 F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = 0 ;
if ( V_2 -> V_4 == V_5 ) {
switch ( V_2 -> V_6 ) {
case V_7 :
case V_8 :
case V_9 :
case V_10 :
case V_11 :
case V_12 :
case V_13 :
case V_14 :
case V_15 :
case V_16 :
V_2 -> V_17 . type = V_18 ;
break;
case V_19 :
case V_20 :
V_2 -> V_17 . type = V_21 ;
break;
default:
V_2 -> V_17 . type = V_22 ;
break;
}
} else {
V_3 = V_23 ;
}
F_2 ( V_2 , L_1 ,
V_2 -> V_17 . type , V_3 ) ;
return V_3 ;
}
void F_3 ( struct V_1 * V_2 , enum V_24 V_25 , void * V_26 ,
void * V_27 )
{
struct V_28 * V_29 = (struct V_28 * ) V_26 ;
T_2 * V_30 = ( T_2 * ) V_27 ;
T_3 V_31 [ 4 ] ;
T_3 V_32 = 0 ;
if ( ( ! ( V_25 & V_2 -> V_33 ) ) || ( V_26 == NULL ) )
return;
F_4 ( V_2 , V_25 ,
L_2 ,
V_29 -> V_34 , V_29 -> V_35 , V_29 -> V_36 ,
V_29 -> V_37 ) ;
F_4 ( V_2 , V_25 , L_3 ,
V_29 -> V_38 , V_29 -> V_39 ) ;
F_4 ( V_2 , V_25 , L_4 ,
V_29 -> V_40 . V_41 . V_42 ,
V_29 -> V_40 . V_41 . V_43 ) ;
F_4 ( V_2 , V_25 , L_5 ,
V_29 -> V_40 . V_44 . V_45 ,
V_29 -> V_40 . V_44 . V_46 ) ;
if ( ( V_27 != NULL ) && ( V_29 -> V_36 != 0 ) ) {
memset ( V_31 , 0 , sizeof( V_31 ) ) ;
F_4 ( V_2 , V_25 , L_6 ) ;
for ( V_32 = 0 ; V_32 < F_5 ( V_29 -> V_36 ) ; V_32 ++ ) {
V_31 [ ( ( V_32 % 16 ) / 4 ) ] |=
( ( T_3 ) V_30 [ V_32 ] ) << ( 8 * ( V_32 % 4 ) ) ;
if ( ( V_32 % 16 ) == 15 ) {
F_4 ( V_2 , V_25 ,
L_7 ,
V_32 - 15 , V_31 [ 0 ] , V_31 [ 1 ] , V_31 [ 2 ] ,
V_31 [ 3 ] ) ;
memset ( V_31 , 0 , sizeof( V_31 ) ) ;
}
}
if ( ( V_32 % 16 ) != 0 )
F_4 ( V_2 , V_25 , L_7 ,
V_32 - ( V_32 % 16 ) , V_31 [ 0 ] , V_31 [ 1 ] , V_31 [ 2 ] ,
V_31 [ 3 ] ) ;
}
}
bool F_6 ( struct V_1 * V_2 )
{
return ! ! ( F_7 ( V_2 , V_2 -> V_47 . V_48 . V_49 ) & V_50 ) ;
}
T_1 F_8 ( struct V_1 * V_2 ,
bool V_51 )
{
struct V_28 V_26 ;
struct V_52 * V_53 =
(struct V_52 * ) & V_26 . V_40 . V_54 ;
T_1 V_3 ;
F_9 ( & V_26 ,
V_55 ) ;
if ( V_51 )
V_53 -> V_56 = F_10 ( V_57 ) ;
V_3 = F_11 ( V_2 , & V_26 , NULL , 0 , NULL ) ;
return V_3 ;
}
T_1 F_12 ( struct V_1 * V_2 ,
enum V_58 V_59 ,
T_1 V_60 ,
T_2 * V_61 , T_4 V_62 ,
struct V_63 * V_64 )
{
struct V_28 V_26 ;
T_1 V_3 ;
F_9 ( & V_26 , V_65 ) ;
V_26 . V_35 |= F_13 ( ( T_4 ) V_66 ) ;
V_26 . V_38 = F_10 ( V_59 ) ;
V_26 . V_39 = F_10 ( V_60 ) ;
if ( V_62 ) {
V_26 . V_35 |= F_13 ( ( T_4 ) ( V_67
| V_68 ) ) ;
if ( V_62 > V_69 )
V_26 . V_35 |= F_13 ( ( T_4 ) V_70 ) ;
V_26 . V_36 = F_13 ( V_62 ) ;
}
if ( ! V_64 ) {
struct V_63 V_71 ;
memset ( & V_71 , 0 , sizeof( V_71 ) ) ;
V_71 . V_72 = true ;
V_64 = & V_71 ;
}
V_3 = F_11 ( V_2 , (struct V_28 * ) & V_26 , V_61 ,
V_62 , V_64 ) ;
return V_3 ;
}
void F_14 ( struct V_1 * V_2 ,
struct V_73 * V_61 )
{
struct V_74 * V_75 ;
int V_32 ;
V_75 = & V_61 -> V_75 [ 0 ] ;
V_2 -> V_76 . V_77 = V_61 -> V_77 ;
V_2 -> V_76 . V_78 = V_61 -> V_79 ;
V_2 -> V_76 . V_80 = V_61 -> V_79 ;
V_2 -> V_76 . V_81 = V_61 -> V_82 ;
V_2 -> V_76 . V_83 = V_61 -> V_84 &
V_85 ;
V_2 -> V_76 . V_86 = ( V_61 -> V_84 &
V_87 ) ? 1 : 0 ;
for ( V_32 = 0 ; V_32 < V_61 -> V_77 ; V_32 ++ ) {
if ( V_75 -> V_88 == V_89 ) {
memcpy ( V_2 -> V_17 . V_90 , V_75 -> V_91 ,
V_92 ) ;
memcpy ( V_2 -> V_17 . V_93 , V_75 -> V_91 ,
V_92 ) ;
}
V_75 ++ ;
}
}
T_1 F_15 ( struct V_1 * V_2 )
{
return F_12 ( V_2 , V_94 ,
0 , NULL , 0 , NULL ) ;
}
