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
void * V_25 )
{
struct V_26 * V_27 = (struct V_26 * ) V_24 ;
T_2 * V_28 = ( T_2 * ) V_25 ;
T_3 V_29 [ 4 ] ;
T_3 V_30 = 0 ;
if ( ( ! ( V_23 & V_2 -> V_31 ) ) || ( V_24 == NULL ) )
return;
F_4 ( V_2 , V_23 ,
L_2 ,
V_27 -> V_32 , V_27 -> V_33 , V_27 -> V_34 ,
V_27 -> V_35 ) ;
F_4 ( V_2 , V_23 , L_3 ,
V_27 -> V_36 , V_27 -> V_37 ) ;
F_4 ( V_2 , V_23 , L_4 ,
V_27 -> V_38 . V_39 . V_40 ,
V_27 -> V_38 . V_39 . V_41 ) ;
F_4 ( V_2 , V_23 , L_5 ,
V_27 -> V_38 . V_42 . V_43 ,
V_27 -> V_38 . V_42 . V_44 ) ;
if ( ( V_25 != NULL ) && ( V_27 -> V_34 != 0 ) ) {
memset ( V_29 , 0 , sizeof( V_29 ) ) ;
F_4 ( V_2 , V_23 , L_6 ) ;
for ( V_30 = 0 ; V_30 < F_5 ( V_27 -> V_34 ) ; V_30 ++ ) {
V_29 [ ( ( V_30 % 16 ) / 4 ) ] |=
( ( T_3 ) V_28 [ V_30 ] ) << ( 8 * ( V_30 % 4 ) ) ;
if ( ( V_30 % 16 ) == 15 ) {
F_4 ( V_2 , V_23 ,
L_7 ,
V_30 - 15 , V_29 [ 0 ] , V_29 [ 1 ] , V_29 [ 2 ] ,
V_29 [ 3 ] ) ;
memset ( V_29 , 0 , sizeof( V_29 ) ) ;
}
}
if ( ( V_30 % 16 ) != 0 )
F_4 ( V_2 , V_23 , L_7 ,
V_30 - ( V_30 % 16 ) , V_29 [ 0 ] , V_29 [ 1 ] , V_29 [ 2 ] ,
V_29 [ 3 ] ) ;
}
}
bool F_6 ( struct V_1 * V_2 )
{
if ( V_2 -> V_45 . V_46 . V_47 )
return ! ! ( F_7 ( V_2 , V_2 -> V_45 . V_46 . V_47 ) &
V_48 ) ;
else
return false ;
}
T_1 F_8 ( struct V_1 * V_2 ,
bool V_49 )
{
struct V_26 V_24 ;
struct V_50 * V_51 =
(struct V_50 * ) & V_24 . V_38 . V_52 ;
T_1 V_3 ;
F_9 ( & V_24 ,
V_53 ) ;
if ( V_49 )
V_51 -> V_54 = F_10 ( V_55 ) ;
V_3 = F_11 ( V_2 , & V_24 , NULL , 0 , NULL ) ;
return V_3 ;
}
T_1 F_12 ( struct V_1 * V_2 ,
enum V_56 V_57 ,
T_1 V_58 ,
T_2 * V_59 , T_4 V_60 ,
struct V_61 * V_62 )
{
struct V_26 V_24 ;
struct V_61 V_63 ;
T_1 V_3 ;
F_9 ( & V_24 , V_64 ) ;
V_24 . V_33 |= F_13 ( ( T_4 ) V_65 ) ;
V_24 . V_36 = F_10 ( V_57 ) ;
V_24 . V_37 = F_10 ( V_58 ) ;
if ( V_60 ) {
V_24 . V_33 |= F_13 ( ( T_4 ) ( V_66
| V_67 ) ) ;
if ( V_60 > V_68 )
V_24 . V_33 |= F_13 ( ( T_4 ) V_69 ) ;
V_24 . V_34 = F_13 ( V_60 ) ;
}
if ( ! V_62 ) {
memset ( & V_63 , 0 , sizeof( V_63 ) ) ;
V_63 . V_70 = true ;
V_62 = & V_63 ;
}
V_3 = F_11 ( V_2 , & V_24 , V_59 , V_60 , V_62 ) ;
return V_3 ;
}
void F_14 ( struct V_1 * V_2 ,
struct V_71 * V_59 )
{
struct V_72 * V_73 ;
int V_30 ;
V_73 = & V_59 -> V_73 [ 0 ] ;
V_2 -> V_74 . V_75 = V_59 -> V_75 ;
V_2 -> V_74 . V_76 = V_59 -> V_77 ;
V_2 -> V_74 . V_78 = V_59 -> V_77 ;
V_2 -> V_74 . V_79 = V_59 -> V_80 ;
V_2 -> V_74 . V_81 = V_59 -> V_82 &
V_83 ;
V_2 -> V_74 . V_84 = ( V_59 -> V_82 &
V_85 ) ? 1 : 0 ;
for ( V_30 = 0 ; V_30 < V_59 -> V_75 ; V_30 ++ ) {
if ( V_73 -> V_86 == V_87 ) {
memcpy ( V_2 -> V_15 . V_88 , V_73 -> V_89 ,
V_90 ) ;
memcpy ( V_2 -> V_15 . V_91 , V_73 -> V_89 ,
V_90 ) ;
}
V_73 ++ ;
}
}
T_1 F_15 ( struct V_1 * V_2 )
{
return F_12 ( V_2 , V_92 ,
0 , NULL , 0 , NULL ) ;
}
