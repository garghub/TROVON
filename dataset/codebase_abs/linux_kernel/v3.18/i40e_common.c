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
V_2 -> V_15 . type = V_16 ;
break;
case V_17 :
case V_18 :
V_2 -> V_15 . type = V_19 ;
break;
default:
V_2 -> V_15 . type = V_20 ;
break;
}
} else {
V_3 = V_21 ;
}
F_2 ( V_2 , L_1 ,
V_2 -> V_15 . type , V_3 ) ;
return V_3 ;
}
void F_3 ( struct V_1 * V_2 , enum V_22 V_23 , void * V_24 ,
void * V_25 , T_2 V_26 )
{
struct V_27 * V_28 = (struct V_27 * ) V_24 ;
T_2 V_29 = F_4 ( V_28 -> V_30 ) ;
T_3 * V_31 = ( T_3 * ) V_25 ;
T_4 V_32 [ 4 ] ;
T_4 V_33 = 0 ;
if ( ( ! ( V_23 & V_2 -> V_34 ) ) || ( V_24 == NULL ) )
return;
F_5 ( V_2 , V_23 ,
L_2 ,
V_28 -> V_35 , V_28 -> V_36 , V_28 -> V_30 ,
V_28 -> V_37 ) ;
F_5 ( V_2 , V_23 , L_3 ,
V_28 -> V_38 , V_28 -> V_39 ) ;
F_5 ( V_2 , V_23 , L_4 ,
V_28 -> V_40 . V_41 . V_42 ,
V_28 -> V_40 . V_41 . V_43 ) ;
F_5 ( V_2 , V_23 , L_5 ,
V_28 -> V_40 . V_44 . V_45 ,
V_28 -> V_40 . V_44 . V_46 ) ;
if ( ( V_25 != NULL ) && ( V_28 -> V_30 != 0 ) ) {
memset ( V_32 , 0 , sizeof( V_32 ) ) ;
F_5 ( V_2 , V_23 , L_6 ) ;
if ( V_26 < V_29 )
V_29 = V_26 ;
for ( V_33 = 0 ; V_33 < V_29 ; V_33 ++ ) {
V_32 [ ( ( V_33 % 16 ) / 4 ) ] |=
( ( T_4 ) V_31 [ V_33 ] ) << ( 8 * ( V_33 % 4 ) ) ;
if ( ( V_33 % 16 ) == 15 ) {
F_5 ( V_2 , V_23 ,
L_7 ,
V_33 - 15 , V_32 [ 0 ] , V_32 [ 1 ] , V_32 [ 2 ] ,
V_32 [ 3 ] ) ;
memset ( V_32 , 0 , sizeof( V_32 ) ) ;
}
}
if ( ( V_33 % 16 ) != 0 )
F_5 ( V_2 , V_23 , L_7 ,
V_33 - ( V_33 % 16 ) , V_32 [ 0 ] , V_32 [ 1 ] , V_32 [ 2 ] ,
V_32 [ 3 ] ) ;
}
}
bool F_6 ( struct V_1 * V_2 )
{
if ( V_2 -> V_47 . V_48 . V_29 )
return ! ! ( F_7 ( V_2 , V_2 -> V_47 . V_48 . V_29 ) &
V_49 ) ;
else
return false ;
}
T_1 F_8 ( struct V_1 * V_2 ,
bool V_50 )
{
struct V_27 V_24 ;
struct V_51 * V_52 =
(struct V_51 * ) & V_24 . V_40 . V_53 ;
T_1 V_3 ;
F_9 ( & V_24 ,
V_54 ) ;
if ( V_50 )
V_52 -> V_55 = F_10 ( V_56 ) ;
V_3 = F_11 ( V_2 , & V_24 , NULL , 0 , NULL ) ;
return V_3 ;
}
T_1 F_12 ( struct V_1 * V_2 ,
enum V_57 V_58 ,
T_1 V_59 ,
T_3 * V_60 , T_2 V_61 ,
struct V_62 * V_63 )
{
struct V_27 V_24 ;
struct V_62 V_64 ;
T_1 V_3 ;
F_9 ( & V_24 , V_65 ) ;
V_24 . V_36 |= F_13 ( ( T_2 ) V_66 ) ;
V_24 . V_38 = F_10 ( V_58 ) ;
V_24 . V_39 = F_10 ( V_59 ) ;
if ( V_61 ) {
V_24 . V_36 |= F_13 ( ( T_2 ) ( V_67
| V_68 ) ) ;
if ( V_61 > V_69 )
V_24 . V_36 |= F_13 ( ( T_2 ) V_70 ) ;
V_24 . V_30 = F_13 ( V_61 ) ;
}
if ( ! V_63 ) {
memset ( & V_64 , 0 , sizeof( V_64 ) ) ;
V_64 . V_71 = true ;
V_63 = & V_64 ;
}
V_3 = F_11 ( V_2 , & V_24 , V_60 , V_61 , V_63 ) ;
return V_3 ;
}
void F_14 ( struct V_1 * V_2 ,
struct V_72 * V_60 )
{
struct V_73 * V_74 ;
int V_33 ;
V_74 = & V_60 -> V_74 [ 0 ] ;
V_2 -> V_75 . V_76 = V_60 -> V_76 ;
V_2 -> V_75 . V_77 = V_60 -> V_78 ;
V_2 -> V_75 . V_79 = V_60 -> V_78 ;
V_2 -> V_75 . V_80 = V_60 -> V_81 ;
V_2 -> V_75 . V_82 = V_60 -> V_83 &
V_84 ;
V_2 -> V_75 . V_85 = ( V_60 -> V_83 &
V_86 ) ? 1 : 0 ;
for ( V_33 = 0 ; V_33 < V_60 -> V_76 ; V_33 ++ ) {
if ( V_74 -> V_87 == V_88 ) {
memcpy ( V_2 -> V_15 . V_89 , V_74 -> V_90 ,
V_91 ) ;
memcpy ( V_2 -> V_15 . V_92 , V_74 -> V_90 ,
V_91 ) ;
}
V_74 ++ ;
}
}
T_1 F_15 ( struct V_1 * V_2 )
{
return F_12 ( V_2 , V_93 ,
0 , NULL , 0 , NULL ) ;
}
