T_1 * F_1 ( T_1 V_1 )
{
T_1 V_2 ;
for ( V_2 = 0 ; V_2 < F_2 ( V_3 ) ; V_2 ++ )
if ( V_3 [ V_2 ] . V_1 == V_1 )
return V_3 [ V_2 ] . V_4 ;
return NULL ;
}
T_2 F_3 ( struct V_5 * V_6 ,
T_1 V_7 , T_1 V_8 )
{
T_2 V_9 = 0 ;
T_1 V_10 = 0 ;
T_1 V_11 = 0 ;
T_1 V_12 = 0 ;
if ( ( V_8 & 0x3 ) == V_13 ) {
V_10 = F_4 ( V_7 & 0xF , 9 ) ;
V_11 = ( V_8 & 0xC ) >> 2 ;
V_12 = ( V_8 & 0x10 ) >> 4 ;
if ( ( V_7 >> 4 ) == 1 )
V_9 = V_14 [ 2 * ( 3 - V_11 ) + V_12 ] [ V_10 ] ;
else
V_9 = V_15 [ 2 * ( 3 - V_11 ) + V_12 ] [ V_10 ] ;
} else if ( ( V_8 & 0x3 ) == V_16 ) {
V_11 = ( V_8 & 0xC ) >> 2 ;
V_12 = ( V_8 & 0x10 ) >> 4 ;
if ( V_7 == V_17 ) {
if ( V_12 == 1 )
V_9 = 0x0D ;
else
V_9 = 0x0C ;
} else if ( V_7 < 16 ) {
if ( ( V_11 == 1 ) || ( V_11 == 0 ) )
V_9 = V_18 [ 2 * ( 1 - V_11 ) + V_12 ] [ V_7 ] ;
else
V_9 = V_19 [ 0 ] ;
} else {
V_9 = V_19 [ 0 ] ;
}
} else {
if ( V_7 >= V_20 )
V_7 = 0 ;
V_9 = V_19 [ V_7 ] ;
}
return V_9 ;
}
T_2 F_5 ( struct V_5 * V_6 ,
T_1 V_7 , T_1 V_8 )
{
T_2 V_21 =
( V_6 -> V_22 -> V_23 == V_24 ) ? 16 : 8 ;
T_2 V_9 ;
if ( V_6 -> V_22 -> V_25 )
return F_3 ( V_6 , V_7 , V_8 ) ;
if ( V_8 & F_6 ( 0 ) ) {
if ( V_7 == V_17 ) {
if ( V_8 & F_6 ( 2 ) )
V_9 = 0x0D ;
else
V_9 = 0x0C ;
} else if ( V_7 < V_21 ) {
if ( V_8 & F_6 ( 1 ) ) {
if ( V_8 & F_6 ( 2 ) )
V_9 = V_18 [ 1 ] [ V_7 ] ;
else
V_9 = V_18 [ 0 ] [ V_7 ] ;
} else {
if ( V_8 & F_6 ( 2 ) )
V_9 = V_18 [ 3 ] [ V_7 ] ;
else
V_9 = V_18 [ 2 ] [ V_7 ] ;
}
} else
V_9 = V_19 [ 0 ] ;
} else {
if ( V_7 >= V_20 )
V_7 = 0 ;
V_9 = V_19 [ V_7 ] ;
}
return V_9 ;
}
T_2 F_7 ( struct V_5 * V_6 , T_1 * V_26 )
{
if ( ! V_6 -> V_27 )
return F_8 ( V_6 , V_26 ) ;
else
return F_9 ( V_26 , 0 ,
V_6 -> V_28 . V_29 ,
V_6 -> V_28 . V_30 ) ;
}
struct V_31 *
F_10 ( struct V_5 * V_6 , T_1 V_32 , T_3 V_33 , T_2 V_34 )
{
struct V_31 * V_35 = NULL ;
struct V_36 * V_37 ;
struct V_38 * V_39 = NULL ;
int V_2 ;
if ( ! V_33 && ! V_34 )
return V_35 ;
if ( F_11 ( V_32 ) == V_40 )
V_37 = V_6 -> V_41 . V_42 -> V_43 [ V_44 ] ;
else
V_37 = V_6 -> V_41 . V_42 -> V_43 [ V_45 ] ;
if ( ! V_37 ) {
F_12 ( V_6 -> V_22 , ERROR ,
L_1 ,
V_46 , V_32 ) ;
return V_35 ;
}
for ( V_2 = 0 ; V_2 < V_37 -> V_47 ; V_2 ++ ) {
V_39 = & V_37 -> V_48 [ V_2 ] ;
if ( V_39 -> V_49 & V_50 )
continue;
if ( V_34 ) {
if ( V_39 -> V_51 == V_34 )
break;
} else {
if ( V_39 -> V_52 == V_33 ||
V_33 == V_53 )
break;
}
}
if ( V_2 == V_37 -> V_47 ) {
F_12 ( V_6 -> V_22 , V_54 ,
L_2
L_3 ,
V_46 , V_32 , V_33 , V_34 ) ;
} else {
if ( ! V_39 )
return V_35 ;
V_6 -> V_35 . V_33 = V_39 -> V_52 ;
V_6 -> V_35 . V_34 = V_39 -> V_51 ;
V_6 -> V_35 . V_55 = V_39 -> V_56 ;
V_35 = & V_6 -> V_35 ;
}
return V_35 ;
}
T_1
F_13 ( struct V_5 * V_6 )
{
T_2 V_2 ;
int V_57 = 0 ;
for ( V_2 = 0 ; V_2 < F_2 ( V_6 -> V_58 ) ; V_2 ++ )
if ( V_6 -> V_58 [ V_2 ] )
V_57 ++ ;
if ( V_57 > 1 )
return true ;
else
return false ;
}
T_2 F_14 ( struct V_5 * V_6 ,
T_1 * V_26 , T_1 V_59 )
{
struct V_42 * V_42 = V_6 -> V_22 -> V_42 ;
struct V_60 * V_61 = V_6 -> V_62 ;
T_2 V_63 , V_64 ;
struct V_36 * V_37 ;
int V_2 ;
if ( V_59 ) {
V_37 = V_42 -> V_43 [ V_45 ] ;
if ( F_15 ( ! V_37 ) )
return 0 ;
V_64 = V_61 -> V_26 [ V_45 ] ;
} else {
V_37 = V_42 -> V_43 [ V_44 ] ;
if ( F_15 ( ! V_37 ) )
return 0 ;
V_64 = V_61 -> V_26 [ V_44 ] ;
}
V_63 = 0 ;
for ( V_2 = 0 ; V_2 < V_37 -> V_65 ; V_2 ++ ) {
if ( ( F_6 ( V_2 ) & V_64 ) == 0 )
continue;
V_26 [ V_63 ++ ] = ( T_1 ) ( V_37 -> V_66 [ V_2 ] . V_67 / 5 ) ;
}
return V_63 ;
}
T_2 F_8 ( struct V_5 * V_6 , T_1 * V_26 )
{
T_2 V_68 = 0 ;
struct V_69 * V_22 = V_6 -> V_22 ;
if ( V_6 -> V_70 == V_71 ||
V_6 -> V_70 == V_72 ) {
switch ( V_22 -> V_73 ) {
case V_74 :
F_12 ( V_22 , V_75 , L_4
L_5 ,
V_22 -> V_73 ) ;
V_68 = F_9 ( V_26 , V_68 , V_76 ,
sizeof( V_76 ) ) ;
break;
case V_77 :
case V_77 | V_78 :
F_12 ( V_22 , V_75 , L_4
L_6 ,
V_22 -> V_73 ) ;
V_68 = F_9 ( V_26 , V_68 , V_79 ,
sizeof( V_79 ) ) ;
break;
case V_74 | V_77 :
case V_80 | V_74 | V_77 :
case V_80 | V_74 :
case V_80 | V_74 | V_77 | V_78 | V_81 :
case V_80 | V_74 | V_77 | V_78 | V_81 | V_82 :
case V_74 | V_77 | V_78 :
F_12 ( V_22 , V_75 , L_4
L_7 ,
V_22 -> V_73 ) ;
V_68 = F_9 ( V_26 , V_68 , V_83 ,
sizeof( V_83 ) ) ;
break;
case V_80 :
case V_80 | V_77 :
F_12 ( V_22 , V_75 , L_4
L_8 ,
V_22 -> V_73 ) ;
V_68 = F_9 ( V_26 , V_68 , V_84 ,
sizeof( V_84 ) ) ;
break;
case V_81 :
case V_80 | V_81 :
case V_80 | V_81 | V_82 :
case V_80 | V_77 | V_81 | V_78 :
case V_80 | V_77 | V_81 | V_78 | V_82 :
F_12 ( V_22 , V_75 , L_4
L_8 ,
V_22 -> V_73 ) ;
V_68 = F_9 ( V_26 , V_68 , V_84 ,
sizeof( V_84 ) ) ;
break;
case V_78 :
F_12 ( V_22 , V_75 , L_4
L_9 ,
V_22 -> V_73 ) ;
V_68 = F_9 ( V_26 , V_68 , V_85 ,
sizeof( V_85 ) ) ;
break;
}
} else {
switch ( V_22 -> V_86 ) {
case V_74 :
F_12 ( V_22 , V_75 , L_10 ) ;
V_68 = F_9 ( V_26 , V_68 , V_87 ,
sizeof( V_87 ) ) ;
break;
case V_77 :
case V_77 | V_78 :
F_12 ( V_22 , V_75 , L_11 ) ;
V_68 = F_9 ( V_26 , V_68 , V_88 ,
sizeof( V_88 ) ) ;
break;
case V_74 | V_77 :
case V_74 | V_77 | V_78 :
F_12 ( V_22 , V_75 , L_12 ) ;
V_68 = F_9 ( V_26 , V_68 , V_89 ,
sizeof( V_89 ) ) ;
break;
case V_80 :
case V_80 | V_81 :
F_12 ( V_22 , V_75 , L_13 ) ;
V_68 = F_9 ( V_26 , V_68 , V_90 ,
sizeof( V_90 ) ) ;
break;
}
}
return V_68 ;
}
T_1 F_16 ( struct V_5 * V_6 ,
T_1 V_91 , T_1 V_92 )
{
T_1 V_93 = 0 ;
if ( ( V_92 & F_6 ( 0 ) ) && ( V_92 & F_6 ( 1 ) ) )
V_93 = V_94 +
V_95 + V_91 ;
else if ( V_92 & F_6 ( 0 ) )
V_93 = V_94 + V_91 ;
else
V_93 = ( V_91 > V_96 ) ?
V_91 - 1 : V_91 ;
return V_93 ;
}
