T_1 * F_1 ( T_1 V_1 )
{
T_1 V_2 ;
T_1 V_3 = sizeof( V_4 ) /
sizeof( struct V_5 ) ;
for ( V_2 = 0 ; V_2 < V_3 ; V_2 ++ )
if ( V_4 [ V_2 ] . V_1 == V_1 )
return V_4 [ V_2 ] . V_6 ;
return NULL ;
}
T_2 F_2 ( struct V_7 * V_8 ,
T_1 V_9 , T_1 V_10 )
{
T_2 V_11 = 0 ;
T_1 V_12 = 0 ;
T_1 V_13 = 0 ;
T_1 V_14 = 0 ;
if ( ( V_10 & 0x3 ) == V_15 ) {
V_12 = F_3 ( V_9 & 0xF , 9 ) ;
V_13 = ( V_10 & 0xC ) >> 2 ;
V_14 = ( V_10 & 0x10 ) >> 4 ;
if ( ( V_9 >> 4 ) == 1 )
V_11 = V_16 [ 2 * ( 3 - V_13 ) + V_14 ] [ V_12 ] ;
else
V_11 = V_17 [ 2 * ( 3 - V_13 ) + V_14 ] [ V_12 ] ;
} else if ( ( V_10 & 0x3 ) == V_18 ) {
V_13 = ( V_10 & 0xC ) >> 2 ;
V_14 = ( V_10 & 0x10 ) >> 4 ;
if ( V_9 == V_19 ) {
if ( V_14 == 1 )
V_11 = 0x0D ;
else
V_11 = 0x0C ;
} else if ( V_9 < 16 ) {
if ( ( V_13 == 1 ) || ( V_13 == 0 ) )
V_11 = V_20 [ 2 * ( 1 - V_13 ) + V_14 ] [ V_9 ] ;
else
V_11 = V_21 [ 0 ] ;
} else {
V_11 = V_21 [ 0 ] ;
}
} else {
if ( V_9 >= V_22 )
V_9 = 0 ;
V_11 = V_21 [ V_9 ] ;
}
return V_11 ;
}
T_2 F_4 ( struct V_7 * V_8 ,
T_1 V_9 , T_1 V_10 )
{
T_2 V_23 =
( V_8 -> V_24 -> V_25 == V_26 ) ? 16 : 8 ;
T_2 V_11 ;
if ( V_8 -> V_24 -> V_27 )
return F_2 ( V_8 , V_9 , V_10 ) ;
if ( V_10 & F_5 ( 0 ) ) {
if ( V_9 == V_19 ) {
if ( V_10 & F_5 ( 2 ) )
V_11 = 0x0D ;
else
V_11 = 0x0C ;
} else if ( V_9 < V_23 ) {
if ( V_10 & F_5 ( 1 ) ) {
if ( V_10 & F_5 ( 2 ) )
V_11 = V_20 [ 1 ] [ V_9 ] ;
else
V_11 = V_20 [ 0 ] [ V_9 ] ;
} else {
if ( V_10 & F_5 ( 2 ) )
V_11 = V_20 [ 3 ] [ V_9 ] ;
else
V_11 = V_20 [ 2 ] [ V_9 ] ;
}
} else
V_11 = V_21 [ 0 ] ;
} else {
if ( V_9 >= V_22 )
V_9 = 0 ;
V_11 = V_21 [ V_9 ] ;
}
return V_11 ;
}
T_2 F_6 ( struct V_7 * V_8 , T_1 * V_28 )
{
if ( ! V_8 -> V_29 )
return F_7 ( V_8 , V_28 ) ;
else
return F_8 ( V_28 , 0 ,
V_8 -> V_30 . V_31 ,
V_8 -> V_30 . V_32 ) ;
}
struct V_33 *
F_9 ( struct V_7 * V_8 , T_1 V_34 , T_3 V_35 , T_2 V_36 )
{
struct V_33 * V_37 = NULL ;
struct V_38 * V_39 ;
struct V_40 * V_41 = NULL ;
int V_2 ;
if ( ! V_35 && ! V_36 )
return V_37 ;
if ( F_10 ( V_34 ) == V_42 )
V_39 = V_8 -> V_43 . V_44 -> V_45 [ V_46 ] ;
else
V_39 = V_8 -> V_43 . V_44 -> V_45 [ V_47 ] ;
if ( ! V_39 ) {
F_11 ( V_8 -> V_24 , ERROR ,
L_1 ,
V_48 , V_34 ) ;
return V_37 ;
}
for ( V_2 = 0 ; V_2 < V_39 -> V_49 ; V_2 ++ ) {
V_41 = & V_39 -> V_50 [ V_2 ] ;
if ( V_41 -> V_51 & V_52 )
continue;
if ( V_36 ) {
if ( V_41 -> V_53 == V_36 )
break;
} else {
if ( V_41 -> V_54 == V_35 ||
V_35 == V_55 )
break;
}
}
if ( V_2 == V_39 -> V_49 ) {
F_11 ( V_8 -> V_24 , ERROR ,
L_2
L_3 ,
V_48 , V_34 , V_35 , V_36 ) ;
} else {
if ( ! V_41 )
return V_37 ;
V_8 -> V_37 . V_35 = V_41 -> V_54 ;
V_8 -> V_37 . V_36 = V_41 -> V_53 ;
V_8 -> V_37 . V_56 = V_41 -> V_57 ;
V_37 = & V_8 -> V_37 ;
}
return V_37 ;
}
T_1
F_12 ( struct V_7 * V_8 )
{
T_2 V_2 ;
int V_58 = 0 ;
for ( V_2 = 0 ; V_2 < F_13 ( V_8 -> V_59 ) ; V_2 ++ )
if ( V_8 -> V_59 [ V_2 ] )
V_58 ++ ;
if ( V_58 > 1 )
return true ;
else
return false ;
}
T_2 F_14 ( struct V_7 * V_8 ,
T_1 * V_28 , T_1 V_60 )
{
struct V_44 * V_44 = V_8 -> V_24 -> V_44 ;
struct V_61 * V_62 = V_8 -> V_63 ;
T_2 V_64 , V_65 ;
struct V_38 * V_39 ;
int V_2 ;
if ( V_60 ) {
V_39 = V_44 -> V_45 [ V_47 ] ;
if ( F_15 ( ! V_39 ) )
return 0 ;
V_65 = V_62 -> V_28 [ V_47 ] ;
} else {
V_39 = V_44 -> V_45 [ V_46 ] ;
if ( F_15 ( ! V_39 ) )
return 0 ;
V_65 = V_62 -> V_28 [ V_46 ] ;
}
V_64 = 0 ;
for ( V_2 = 0 ; V_2 < V_39 -> V_66 ; V_2 ++ ) {
if ( ( F_5 ( V_2 ) & V_65 ) == 0 )
continue;
V_28 [ V_64 ++ ] = ( T_1 ) ( V_39 -> V_67 [ V_2 ] . V_68 / 5 ) ;
}
return V_64 ;
}
T_2 F_7 ( struct V_7 * V_8 , T_1 * V_28 )
{
T_2 V_69 = 0 ;
struct V_70 * V_24 = V_8 -> V_24 ;
if ( V_8 -> V_71 == V_72 ||
V_8 -> V_71 == V_73 ) {
switch ( V_24 -> V_74 ) {
case V_75 :
F_11 ( V_24 , V_76 , L_4
L_5 ,
V_24 -> V_74 ) ;
V_69 = F_8 ( V_28 , V_69 , V_77 ,
sizeof( V_77 ) ) ;
break;
case V_78 :
case V_78 | V_79 :
F_11 ( V_24 , V_76 , L_4
L_6 ,
V_24 -> V_74 ) ;
V_69 = F_8 ( V_28 , V_69 , V_80 ,
sizeof( V_80 ) ) ;
break;
case V_75 | V_78 :
case V_81 | V_75 | V_78 :
case V_81 | V_75 :
case V_81 | V_75 | V_78 | V_79 | V_82 :
case V_81 | V_75 | V_78 | V_79 | V_82 | V_83 :
case V_75 | V_78 | V_79 :
F_11 ( V_24 , V_76 , L_4
L_7 ,
V_24 -> V_74 ) ;
V_69 = F_8 ( V_28 , V_69 , V_84 ,
sizeof( V_84 ) ) ;
break;
case V_81 :
case V_81 | V_78 :
F_11 ( V_24 , V_76 , L_4
L_8 ,
V_24 -> V_74 ) ;
V_69 = F_8 ( V_28 , V_69 , V_85 ,
sizeof( V_85 ) ) ;
break;
case V_82 :
case V_81 | V_82 :
case V_81 | V_82 | V_83 :
case V_81 | V_78 | V_82 | V_79 :
case V_81 | V_78 | V_82 | V_79 | V_83 :
F_11 ( V_24 , V_76 , L_4
L_8 ,
V_24 -> V_74 ) ;
V_69 = F_8 ( V_28 , V_69 , V_85 ,
sizeof( V_85 ) ) ;
break;
case V_79 :
F_11 ( V_24 , V_76 , L_4
L_9 ,
V_24 -> V_74 ) ;
V_69 = F_8 ( V_28 , V_69 , V_86 ,
sizeof( V_86 ) ) ;
break;
}
} else {
switch ( V_24 -> V_87 ) {
case V_75 :
F_11 ( V_24 , V_76 , L_10 ) ;
V_69 = F_8 ( V_28 , V_69 , V_88 ,
sizeof( V_88 ) ) ;
break;
case V_78 :
case V_78 | V_79 :
F_11 ( V_24 , V_76 , L_11 ) ;
V_69 = F_8 ( V_28 , V_69 , V_89 ,
sizeof( V_89 ) ) ;
break;
case V_75 | V_78 :
case V_75 | V_78 | V_79 :
F_11 ( V_24 , V_76 , L_12 ) ;
V_69 = F_8 ( V_28 , V_69 , V_90 ,
sizeof( V_90 ) ) ;
break;
case V_81 :
case V_81 | V_82 :
F_11 ( V_24 , V_76 , L_13 ) ;
V_69 = F_8 ( V_28 , V_69 , V_91 ,
sizeof( V_91 ) ) ;
break;
}
}
return V_69 ;
}
T_1 F_16 ( struct V_7 * V_8 ,
T_1 V_92 , T_1 V_93 )
{
T_1 V_94 = 0 ;
if ( ( V_93 & F_5 ( 0 ) ) && ( V_93 & F_5 ( 1 ) ) )
V_94 = V_95 +
V_96 + V_92 ;
else if ( V_93 & F_5 ( 0 ) )
V_94 = V_95 + V_92 ;
else
V_94 = ( V_92 > V_97 ) ?
V_92 - 1 : V_92 ;
return V_94 ;
}
