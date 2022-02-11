bool F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
struct V_7 * V_8 )
{
T_1 V_9 = 0 ;
struct V_10 * V_11 = NULL ;
T_2 V_12 = ( T_2 ) F_2 ( V_13 ) ;
V_4 -> V_14 = V_15 ;
V_4 -> V_16 = V_17 ;
if ( V_4 -> V_18 >= V_12 ) {
V_4 -> V_14 = V_19 ;
return false ;
}
if ( V_4 -> V_20 > V_13 [ V_4 -> V_18 ] ) {
V_4 -> V_14 = V_21 ;
return false ;
}
if ( V_2 -> V_22 & V_23 ) {
V_4 -> V_14 = V_24 ;
return false ;
}
if ( V_4 -> V_18 != V_25 )
F_3 ( V_6 ) ;
V_6 -> V_26 -> V_27 . V_18 = V_4 -> V_18 ;
V_6 -> V_28 = V_29 ;
V_6 -> V_30 = V_4 ;
switch ( V_4 -> V_18 ) {
case V_31 :
if ( V_4 -> V_32 . V_33 . V_34 != V_35
&& V_4 -> V_32 . V_33 . V_34 != V_36
&& V_4 -> V_32 . V_33 . V_34 != V_37 ) {
V_4 -> V_14 = V_19 ;
return false ;
}
if ( V_4 -> V_32 . V_33 . V_34 != V_37 )
V_9 = V_4 -> V_38 ;
V_6 -> V_26 -> V_33 . V_39 = F_4 ( V_9 ) ;
V_6 -> V_26 -> V_33 . V_34 = V_4 -> V_32 . V_33 . V_34 ;
memcpy ( V_6 -> V_26 -> V_33 . V_40 . V_41 . V_42 ,
V_4 -> V_32 . V_33 . V_40 . V_41 . V_42 ,
sizeof( V_4 -> V_32 . V_33 . V_40 . V_41 . V_42 ) ) ;
V_11 = V_6 -> V_26 -> V_33 . V_40 . V_41 . V_43 ;
break;
case V_44 :
V_9 = V_4 -> V_38 ;
V_6 -> V_26 -> V_45 . V_46 =
F_4 ( V_4 -> V_32 . V_45 . V_46 ) ;
V_6 -> V_26 -> V_45 . V_39 = F_4 ( V_9 ) ;
V_11 = V_6 -> V_26 -> V_45 . V_43 ;
break;
case V_47 :
{
T_2 * V_48 = V_8 -> V_49
- F_5 ( struct V_3 , V_40 )
+ F_5 ( struct V_3 , V_32 )
+ F_5 ( struct V_50 ,
V_40 ) ;
if ( V_4 -> V_38 ) {
T_1 V_51 = 0 ;
if ( V_4 -> V_32 . V_52 . V_53 == V_54
|| V_4 -> V_32 . V_52 . V_53 == V_55 ) {
V_6 -> V_26 -> V_52 . V_56 =
( T_2 ) F_5 ( struct V_57 ,
V_58 ) ;
V_51 = V_4 -> V_38 ;
V_9 = V_4 -> V_32 . V_52 . V_38 ;
} else if ( V_4 -> V_32 . V_52 . V_53 == V_59
|| V_4 -> V_32 . V_52 . V_53 ==
V_60 ) {
V_9 = V_4 -> V_38 ;
V_48 = V_8 -> V_49 ;
} else {
V_4 -> V_14 = V_61 ;
return false ;
}
V_6 -> V_26 -> V_52 . V_39 = F_4 ( V_9 ) ;
if ( V_51 ) {
V_6 -> V_26 -> V_52 . V_62 =
F_4 ( V_51 ) ;
F_6 ( V_8 , V_2 , V_6 ,
V_6 -> V_26 -> V_52 . V_58 ) ;
V_8 -> V_39 = V_51 ;
if ( ! F_7 ( V_2 , V_6 , V_8 ) ) {
V_4 -> V_14 = V_63 ;
return false ;
}
}
} else {
V_9 = V_4 -> V_32 . V_52 . V_38 ;
V_6 -> V_26 -> V_52 . V_39 = F_4 ( V_9 ) ;
}
V_11 = V_6 -> V_26 -> V_52 . V_43 ;
V_8 -> V_49 = V_48 ;
V_6 -> V_26 -> V_52 . V_53 = V_4 -> V_32 . V_52 . V_53 ;
V_6 -> V_26 -> V_52 . V_64 = V_4 -> V_32 . V_52 . V_64 ;
V_6 -> V_26 -> V_52 . V_65 =
F_4 ( V_4 -> V_32 . V_52 . V_65 ) ;
F_8 ( V_6 -> V_26 -> V_52 . V_53 , & V_4 -> V_32 . V_52 . V_40 ) ;
break;
}
case V_66 :
if ( V_4 -> V_38
|| V_4 -> V_32 . V_67 . V_38 == 0 ) {
V_4 -> V_14 = V_61 ;
return false ;
}
if ( V_4 -> V_32 . V_67 . V_68 == V_69 ) {
V_4 -> V_14 = V_19 ;
return false ;
}
V_6 -> V_26 -> V_67 . V_34 = V_4 -> V_32 . V_67 . V_68 ;
V_6 -> V_26 -> V_67 . V_39 = F_4 ( V_4 -> V_32 . V_67 . V_38 ) ;
if ( V_4 -> V_32 . V_67 . V_68 == V_70 ) {
memcpy ( & V_6 -> V_26 -> V_67 . V_40 ,
& V_4 -> V_32 . V_67 . V_40 ,
V_4 -> V_32 . V_67 . V_38 ) ;
F_9 ( V_6 -> V_26 -> V_67 . V_34 ,
& V_6 -> V_26 -> V_67 . V_40 ) ;
} else {
V_4 -> V_14 = V_19 ;
return false ;
}
break;
case V_71 :
V_4 -> V_32 . V_72 . V_73 = V_12 ;
memcpy ( V_4 -> V_32 . V_72 . V_74 , V_13 ,
V_12 ) ;
V_4 -> V_16 = V_75 ;
break;
default:
V_4 -> V_14 = V_19 ;
return false ;
}
if ( V_9 ) {
F_6 ( V_8 , V_2 , V_6 , V_11 ) ;
V_8 -> V_39 = V_9 ;
if ( ! F_7 ( V_2 , V_6 , V_8 ) ) {
V_4 -> V_14 = V_63 ;
return false ;
}
}
F_10 ( V_2 , V_6 ) ;
return true ;
}
static void V_29 ( struct V_1 * V_2 ,
struct V_5 * V_6 )
{
struct V_3 * V_4 = (struct V_3 * ) V_6 -> V_30 ;
V_4 -> V_16 = V_6 -> V_76 ;
switch ( V_4 -> V_18 ) {
case V_31 :
if ( V_4 -> V_32 . V_33 . V_34 == V_37
|| V_4 -> V_32 . V_33 . V_34 == V_35 )
V_4 -> V_32 . V_33 . V_40 . V_41 . V_77 =
F_11 ( V_6 -> V_78 . V_79 . V_77 ) ;
break;
case V_47 :
V_4 -> V_32 . V_52 . V_64 =
V_6 -> V_78 . V_80 . V_64 ;
V_4 -> V_32 . V_52 . V_65 = F_12 (
V_6 -> V_78 . V_80 . V_65 ) ;
if ( V_4 -> V_38 == 0 )
V_4 -> V_32 . V_52 . V_38 =
F_11 ( V_6 -> V_78 . V_80 . V_39 ) ;
F_8 ( V_6 -> V_26 -> V_52 . V_53 , & V_4 -> V_32 . V_52 . V_40 ) ;
break;
case V_66 :
if ( V_4 -> V_32 . V_67 . V_68 == V_70 ) {
struct V_81 * V_67 = & V_4 -> V_32 . V_67 ;
struct V_82 * V_83 = & V_6 -> V_78 . V_84 ;
char V_85 [ sizeof( V_67 -> V_40 . V_86 . V_87 ) + 1 ] ;
V_67 -> V_38 =
F_4 ( sizeof( struct V_88 ) ) ;
V_67 -> V_40 . V_86 . V_89 =
F_11 ( V_83 -> V_89 ) ;
V_67 -> V_40 . V_86 . V_90 = V_83 -> V_90 ;
snprintf ( V_85 , sizeof( V_85 ) , L_1 ,
( int ) F_13 ( F_12 ( V_83 -> V_87 ) ) ,
( int ) F_14 ( F_12 ( V_83 -> V_87 ) ) ) ;
memcpy ( & V_67 -> V_40 . V_86 . V_87 , V_85 ,
sizeof( V_67 -> V_40 . V_86 . V_87 ) ) ;
if ( F_15 ( F_13 ( V_67 -> V_40 . V_86 . V_90 ) ) == 'A' )
V_67 -> V_40 . V_86 . V_91 =
V_67 -> V_40 . V_86 . V_90 ;
else
V_67 -> V_40 . V_86 . V_91 =
V_67 -> V_40 . V_86 . V_87 ;
} else {
F_9 ( V_6 -> V_26 -> V_67 . V_34 ,
& V_4 -> V_32 . V_67 . V_40 ) ;
}
break;
case V_44 :
V_4 -> V_32 . V_45 . V_46 =
F_11 ( V_6 -> V_78 . V_92 . V_46 ) ;
break;
default:
break;
}
}
void F_16 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
T_2 V_34 ,
T_2 V_93 ,
T_1 V_94 ,
T_1 V_39 )
{
struct V_95 * V_26 = & V_6 -> V_26 -> V_33 ;
F_3 ( V_6 ) ;
V_6 -> V_26 -> V_27 . V_18 = V_31 ;
if ( V_34 == V_96
|| V_34 == V_97
|| V_34 == V_98 )
V_26 -> V_99 = ( T_2 ) F_5 ( struct V_95 ,
V_40 . V_43 ) ;
V_26 -> V_39 = F_4 ( V_39 ) ;
V_26 -> V_100 = F_4 ( V_94 ) ;
V_26 -> V_101 = V_93 ;
V_26 -> V_34 = V_34 ;
}
void F_17 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
T_2 V_34 ,
T_2 V_102 ,
T_3 V_65 ,
T_1 V_39 ,
void * V_40 )
{
struct V_57 * V_26 = & V_6 -> V_26 -> V_52 ;
F_3 ( V_6 ) ;
V_6 -> V_26 -> V_27 . V_18 = V_47 ;
V_26 -> V_53 = V_34 ;
V_26 -> V_64 = V_102 ;
V_26 -> V_65 = F_18 ( V_65 ) ;
V_26 -> V_39 = F_4 ( V_39 ) ;
if ( V_26 -> V_39 ) {
if ( V_2 -> V_22 & V_103 ) {
V_26 -> V_99 = ( T_2 ) F_5 (
struct V_57 , V_43 ) ;
V_26 -> V_43 [ 0 ] . V_39 = F_4 ( V_104 | V_39 ) ;
V_26 -> V_43 [ 0 ] . V_105 = F_19 (
V_6 -> V_106 -> V_107 +
sizeof( union V_108 ) ) ;
} else {
V_26 -> V_99 = ( T_2 ) F_5 (
struct V_57 , V_109 ) ;
V_26 -> V_109 [ 0 ] . V_110 = F_4 ( V_39 ) ;
V_26 -> V_109 [ 0 ] . V_105 = F_19 (
V_6 -> V_106 -> V_107 +
sizeof( union V_108 ) ) ;
}
}
if ( V_40 ) {
F_8 ( V_34 , V_40 ) ;
memcpy ( & V_6 -> V_111 -> V_112 . V_40 . V_113 [ 0 ] , V_40 ,
V_39 ) ;
}
}
void F_20 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
struct V_114 * V_26 = & V_6 -> V_26 -> V_115 ;
F_3 ( V_6 ) ;
V_6 -> V_26 -> V_27 . V_18 = V_116 ;
V_26 -> V_39 = F_4 ( sizeof( struct V_117 ) ) ;
if ( V_2 -> V_22 & V_103 ) {
V_26 -> V_99 =
( T_2 ) F_5 ( struct V_114 , V_43 ) ;
V_26 -> V_43 [ 0 ] . V_39 = F_4 ( V_104 | V_26 -> V_39 ) ;
V_26 -> V_43 [ 0 ] . V_105 = F_19 (
V_6 -> V_106 -> V_107 +
sizeof( union V_108 ) ) ;
} else {
V_26 -> V_99 = ( T_2 ) F_5 ( struct V_114 ,
V_109 ) ;
V_26 -> V_109 [ 0 ] . V_110 = F_4 ( V_26 -> V_39 ) ;
V_26 -> V_109 [ 0 ] . V_105 = F_19 (
V_6 -> V_106 -> V_107 +
sizeof( union V_108 ) ) ;
}
}
void F_21 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
T_1 V_39 ,
T_1 V_46 )
{
struct V_118 * V_26 = & V_6 -> V_26 -> V_45 ;
F_3 ( V_6 ) ;
V_6 -> V_26 -> V_27 . V_18 = V_44 ;
V_26 -> V_39 = F_4 ( V_39 ) ;
V_26 -> V_46 = F_4 ( V_46 ) ;
V_26 -> V_99 = ( T_2 ) F_5 ( struct V_118 , V_43 ) ;
}
void F_22 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
T_1 V_39 ,
T_2 V_34 )
{
struct V_119 * V_26 = & V_6 -> V_26 -> V_120 ;
F_3 ( V_6 ) ;
V_6 -> V_26 -> V_27 . V_18 = V_121 ;
V_26 -> V_39 = F_4 ( V_39 ) ;
V_26 -> V_34 = V_34 ;
V_26 -> V_99 = ( T_2 ) F_5 ( struct V_119 , V_43 ) ;
}
void F_23 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
T_2 V_34 ,
T_1 V_39 ,
void * V_40 )
{
struct V_122 * V_26 = & V_6 -> V_26 -> V_67 ;
F_3 ( V_6 ) ;
V_6 -> V_26 -> V_27 . V_18 = V_66 ;
V_26 -> V_34 = V_34 ;
V_26 -> V_39 = F_4 ( V_39 ) ;
if ( V_40 ) {
F_9 ( V_34 , V_40 ) ;
memcpy ( & V_26 -> V_40 , V_40 , V_39 ) ;
}
}
static void F_3 ( struct V_5 * V_6 )
{
T_1 V_123 = V_6 -> V_26 -> V_27 . V_123 ;
memset ( V_6 -> V_26 , 0 , sizeof( * V_6 -> V_26 ) ) ;
V_6 -> V_26 -> V_27 . V_123 = V_123 ;
V_6 -> V_76 = V_17 ;
memset ( V_6 -> V_124 , 0 , V_125 ) ;
F_24 ( & V_6 -> V_126 ) ;
}
