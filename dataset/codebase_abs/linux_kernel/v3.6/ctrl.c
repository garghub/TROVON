void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
if ( V_2 -> V_4 . V_5 == V_3 )
return;
if ( V_2 -> V_6 . V_7 & V_8 ) {
F_2 ( & V_2 -> V_9 -> V_10 , L_1 ) ;
return;
}
F_3 ( V_2 , V_3 ) ;
F_4 ( V_2 , V_3 ) ;
F_5 ( V_2 , V_3 ) ;
V_2 -> V_4 . V_5 = V_3 ;
}
void F_6 ( struct V_1 * V_2 , T_1 V_3 )
{
T_1 V_11 , V_12 ;
if ( V_2 -> V_4 . V_13 == V_3 )
return;
V_11 = V_2 -> V_4 . V_14 ;
V_12 = V_2 -> V_4 . V_15 ;
if ( V_11 == V_16 )
F_7 ( V_2 , V_17 ) ;
if ( V_12 == V_16 )
F_8 ( V_2 , V_17 ) ;
switch ( V_2 -> V_4 . V_13 ) {
case V_18 :
break;
case V_19 :
F_9 ( V_2 , V_20 ) ;
break;
case V_21 :
F_10 ( V_2 , V_22 ) ;
break;
case V_23 :
case V_24 :
case V_25 :
F_11 ( V_2 , V_26 ) ;
break;
default:
return;
}
switch ( V_3 ) {
case V_18 :
break;
case V_19 :
F_9 ( V_2 , V_27 ) ;
break;
case V_21 :
F_10 ( V_2 , V_28 ) ;
break;
case V_23 :
F_11 ( V_2 , V_29 ) ;
break;
case V_24 :
F_11 ( V_2 , V_30 ) ;
break;
case V_25 :
F_11 ( V_2 , V_31 ) ;
break;
default:
return;
}
V_2 -> V_4 . V_13 = V_3 ;
if ( V_11 == V_16 )
F_7 ( V_2 , V_16 ) ;
if ( V_12 == V_16 )
F_8 ( V_2 , V_16 ) ;
}
void F_12 ( struct V_1 * V_2 , T_1 * V_32 , T_1 * V_33 )
{
T_1 V_34 ;
* V_33 = 0 ;
switch ( V_32 [ 0 ] ) {
case V_35 :
if ( ! ( V_32 [ 1 ] & 7 ) )
* V_33 = F_13 ( V_2 -> V_36 , V_32 [ 1 ] / 8 ) ;
break;
case V_37 :
for ( V_34 = 0 ; V_34 < V_38 ; V_34 ++ )
if ( V_39 [ V_34 ] [ V_2 -> V_40 . V_41 ] == V_32 [ 1 ] ) {
* V_33 = F_14 ( V_2 , V_34 ) ;
break;
}
break;
case V_42 :
for ( V_34 = 0 ; V_34 < V_43 ; V_34 ++ )
if ( V_44 [ V_34 ] == V_32 [ 1 ] ) {
* V_33 = F_15 ( V_2 , V_34 ) ;
break;
}
break;
case V_45 :
for ( V_34 = 0 ; V_34 < V_46 ; V_34 ++ )
if ( V_47 [ V_34 ] == V_32 [ 1 ] ) {
* V_33 = F_16 ( V_2 , V_34 ) ;
break;
}
break;
default:
break;
}
}
void F_17 ( struct V_1 * V_2 , T_1 * V_32 )
{
T_1 V_34 ;
switch ( V_32 [ 0 ] ) {
case V_35 :
F_18 ( V_2 -> V_36 , V_32 [ 1 ] , V_32 [ 2 ] ) ;
break;
case V_37 :
for ( V_34 = 0 ; V_34 < V_38 ; V_34 ++ )
if ( V_39 [ V_34 ] [ V_2 -> V_40 . V_41 ] == V_32 [ 1 ] ) {
F_19 ( V_2 , V_34 , V_32 [ 2 ] ) ;
break;
}
break;
case V_42 :
for ( V_34 = 0 ; V_34 < V_43 ; V_34 ++ )
if ( V_44 [ V_34 ] == V_32 [ 1 ] ) {
F_20 ( V_2 , V_34 , V_32 [ 2 ] ) ;
break;
}
break;
case V_45 :
for ( V_34 = 0 ; V_34 < V_46 ; V_34 ++ )
if ( V_47 [ V_34 ] == V_32 [ 1 ] ) {
F_21 ( V_2 , V_34 , V_32 [ 2 ] ) ;
break;
}
break;
}
}
void F_22 ( struct V_1 * V_2 , T_2 * V_48 )
{
memcpy ( V_48 , & ( V_2 -> V_4 ) , sizeof( T_2 ) ) ;
}
void F_23 ( struct V_1 * V_2 , T_2 * V_48 )
{
if ( V_48 -> V_49 != 0xff )
F_24 ( V_2 , V_48 -> V_49 ) ;
if ( V_48 -> V_50 != 0xff )
F_25 ( V_2 , V_48 -> V_50 ,
V_48 -> V_51 ,
V_48 -> V_52 ) ;
if ( V_48 -> V_53 != 0xff )
F_26 ( V_2 , V_48 -> V_53 ) ;
if ( V_48 -> V_54 != 0xff )
F_27 ( V_2 , V_48 -> V_54 ) ;
if ( V_48 -> V_15 != 0xff )
F_8 ( V_2 , V_48 -> V_15 ) ;
if ( V_48 -> V_14 != 0xff )
F_7 ( V_2 , V_48 -> V_14 ) ;
if ( V_48 -> V_5 != 0xff )
F_1 ( V_2 , V_48 -> V_5 ) ;
if ( V_48 -> V_55 != 0xff )
F_28 ( V_2 , V_48 -> V_55 ) ;
if ( V_48 -> V_56 != 0xff )
F_29 ( V_2 , V_48 -> V_56 ) ;
if ( V_48 -> V_57 != 0xff )
F_30 ( V_2 , V_48 -> V_57 ) ;
if ( V_48 -> V_58 != 0xff )
F_31 ( V_2 , V_48 -> V_58 ) ;
if ( V_48 -> V_13 != 0xff )
F_6 ( V_2 , V_48 -> V_13 ) ;
if ( V_48 -> V_59 != 0xff )
F_32 ( V_2 , V_48 -> V_59 ) ;
if ( V_48 -> V_60 != 0xff )
F_33 ( V_2 , V_48 -> V_60 ) ;
}
void F_34 ( struct V_1 * V_2 ,
T_3 * V_61 )
{
T_1 V_62 ;
V_2 -> V_63 . V_64 = F_15 ( V_2 , V_65 )
& V_66 ? 1 : 0 ;
switch ( V_2 -> V_4 . V_5 ) {
case V_67 :
case V_68 :
V_62 = F_15 ( V_2 , V_69 ) ;
V_2 -> V_63 . V_70 = V_62 & V_71 ? 1 : 0 ;
V_2 -> V_63 . V_72 = V_62 & V_73 ? 1 : 0 ;
F_35 ( V_2 ) ;
V_2 -> V_63 . V_74 = V_62 & V_75 ? 1 : 0 ;
V_2 -> V_63 . V_76 = V_62 & V_77 ? 1 : 0 ;
break;
case V_78 :
case V_79 :
V_62 = F_15 ( V_2 , V_80 ) ;
V_2 -> V_63 . V_74 = V_62 & V_81 ? 1 : 0 ;
F_35 ( V_2 ) ;
V_2 -> V_63 . V_82 = V_62 & V_83 ? 1 : 0 ;
V_2 -> V_63 . V_72 = V_62 & V_84 ? 1 : 0 ;
V_62 = F_15 ( V_2 , V_85 ) ;
V_2 -> V_63 . V_76 = V_62 & V_86 ? 1 : 0 ;
V_2 -> V_63 . V_87 = V_62 & V_88 ? 1 : 0 ;
V_2 -> V_63 . V_89 = V_62 & V_90 ;
V_2 -> V_63 . V_91 = F_15 ( V_2 , V_92 ) ;
break;
default:
break;
}
V_62 = F_15 ( V_2 , V_93 ) << 8 ;
V_62 += F_15 ( V_2 , V_94 ) ;
V_2 -> V_63 . V_95 += V_62 ;
V_62 = F_15 ( V_2 , V_96 ) << 8 ;
V_62 += F_15 ( V_2 , V_94 ) ;
V_2 -> V_63 . V_97 += V_62 ;
V_62 = F_15 ( V_2 , V_98 ) << 8 ;
V_62 += F_15 ( V_2 , V_94 ) ;
V_2 -> V_63 . V_99 += V_62 ;
V_62 = F_15 ( V_2 , V_100 ) << 8 ;
V_62 += F_15 ( V_2 , V_94 ) ;
V_2 -> V_63 . V_101 += V_62 ;
V_62 = F_15 ( V_2 , V_102 ) << 8 ;
V_62 += F_15 ( V_2 , V_94 ) ;
V_2 -> V_63 . V_103 += V_62 ;
memcpy ( V_61 , & ( V_2 -> V_63 ) , sizeof( T_3 ) ) ;
}
void F_36 ( struct V_1 * V_2 )
{
memset ( & ( V_2 -> V_63 ) , 0 , sizeof( T_3 ) ) ;
}
void F_37 ( struct V_1 * V_2 , T_1 V_104 , char * V_105 ,
T_4 * V_106 , int * V_107 )
{
T_2 * V_48 = ( T_2 * ) V_105 ;
T_1 * V_108 = ( T_1 * ) V_105 ;
switch ( V_104 ) {
case V_109 :
F_22 ( V_2 , & ( V_106 -> V_110 . V_48 ) ) ;
* V_107 = sizeof( V_106 -> V_110 . V_48 ) ;
break;
case V_111 :
F_23 ( V_2 , V_48 ) ;
* V_107 = 0 ;
break;
case V_112 :
F_34 ( V_2 , & ( V_106 -> V_110 . V_61 ) ) ;
* V_107 = sizeof( V_106 -> V_110 . V_61 ) ;
break;
case V_113 :
F_36 ( V_2 ) ;
* V_107 = 0 ;
break;
case V_114 :
F_12 ( V_2 , V_108 , & ( V_106 -> V_110 . V_108 ) ) ;
* V_107 = sizeof( V_106 -> V_110 . V_108 ) ;
break;
case V_115 :
F_17 ( V_2 , V_108 ) ;
* V_107 = 0 ;
break;
case V_116 :
* V_107 = 0 ;
break;
default:
* V_107 = 0 ;
break;
}
}
void F_38 ( struct V_1 * V_2 )
{
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
V_2 -> V_4 . V_49 = V_117 ;
V_2 -> V_4 . V_50 = V_118 ;
V_2 -> V_4 . V_54 = V_119 ;
V_2 -> V_4 . V_15 = V_17 ;
V_2 -> V_4 . V_14 = V_17 ;
V_2 -> V_4 . V_5 = V_78 ;
V_2 -> V_4 . V_55 = V_120 ;
V_2 -> V_4 . V_56 = V_17 ;
V_2 -> V_4 . V_57 = V_17 ;
V_2 -> V_4 . V_58 = V_17 ;
V_2 -> V_4 . V_13 = V_18 ;
V_2 -> V_4 . V_59 = V_121 ;
V_2 -> V_4 . V_60 = V_122 ;
V_2 -> V_4 . V_53 = V_123 ;
}
