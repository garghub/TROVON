struct V_1 *
F_1 ( T_1 V_2 )
{
struct V_1 * V_3 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_5 ; V_4 ++ ) {
V_3 = & V_6 [ V_4 ] ;
if ( V_3 -> V_7 == ( V_2 & V_3 -> V_8 ) )
return ( V_3 ) ;
}
return ( NULL ) ;
}
int
F_2 ( struct V_9 * V_10 , struct V_1 * V_3 , T_2 V_11 )
{
int error ;
int V_12 ;
T_2 V_13 ;
T_2 V_14 ;
T_2 V_15 ;
error = V_3 -> V_16 ( V_10 ) ;
V_12 = 0 ;
if ( error != 0 )
return ( error ) ;
error = F_3 ( V_10 , V_11 ) ;
if ( error != 0 )
return ( error ) ;
F_4 ( V_10 , FALSE ) ;
V_10 -> V_17 = V_3 -> V_18 ;
error = F_5 ( V_10 ) ;
if ( error != 0 )
return ( error ) ;
V_10 -> V_19 = V_20 ;
error = F_6 ( V_10 , FALSE ) ;
if ( error != 0 )
return ( error ) ;
V_15 = F_7 ( V_10 , V_21 ) ;
V_14 = V_15 & V_22 ;
switch ( V_14 ) {
case 9 :
case 10 :
case 11 :
case 12 :
case 14 :
case 15 :
break;
default:
F_8 ( L_1 , V_15 ) ;
return ( V_23 ) ;
}
if ( ( V_15 & V_24 ) != 0 )
V_10 -> V_25 |= V_26 ;
switch ( V_10 -> V_27 & ( V_28 | V_29 ) ) {
case V_28 :
{
T_2 V_30 ;
T_2 V_31 ;
T_2 V_32 ;
V_30 = F_7 ( V_10 , V_33 ) ;
V_31 = F_7 ( V_10 , V_34 ) ;
V_32 = F_7 ( V_10 , V_34 + 1 ) ;
if ( ( V_30 & V_35 ) != 0 )
V_10 -> V_25 |= 1 ;
if ( ( V_30 & V_36 ) == V_37 ) {
V_10 -> V_25 |= V_38 ;
} else {
if ( ( V_10 -> V_39 & V_40 ) != 0 ) {
V_10 -> V_41 = V_32 & V_42 ;
if ( V_31 & V_43 )
V_10 -> V_25 |= V_44 ;
} else {
V_10 -> V_41 = V_31 & V_45 ;
V_10 -> V_46 = V_32 & V_45 ;
if ( V_31 & V_43 )
V_10 -> V_25 |= V_44 ;
if ( V_32 & V_43 )
V_10 -> V_25 |= V_47 ;
}
}
if ( ( F_7 ( V_10 , V_48 ) & V_49 ) )
V_10 -> V_25 |= V_50 | V_51 ;
break;
}
case V_29 :
{
V_12 = F_9 ( V_10 ) ;
break;
}
default:
break;
}
if ( V_12 == 0 ) {
F_10 ( V_10 -> V_52 ) ;
V_10 -> V_52 = NULL ;
}
F_11 ( V_10 , V_53 , F_7 ( V_10 , V_53 ) & ~ V_54 ) ;
V_13 = F_7 ( V_10 , V_55 ) ;
F_11 ( V_10 , V_56 , V_13 & V_57 ) ;
F_11 ( V_10 , V_58 , ( V_13 << 2 ) & V_59 ) ;
V_10 -> V_60 . V_61 . V_62 = V_13 & V_57 ;
V_10 -> V_60 . V_61 . V_63 = ( V_13 << 2 ) & V_59 ;
error = F_12 ( V_10 ) ;
if ( error != 0 )
return ( error ) ;
error = F_13 ( V_10 , V_14 ) ;
if ( error != 0 )
return ( error ) ;
V_10 -> V_64 ++ ;
F_11 ( V_10 , V_65 , V_66 ) ;
return ( 0 ) ;
}
static int
V_20 ( struct V_9 * V_10 )
{
F_11 ( V_10 , V_56 , V_10 -> V_60 . V_61 . V_62 ) ;
F_11 ( V_10 , V_58 , V_10 -> V_60 . V_61 . V_63 ) ;
F_11 ( V_10 , V_53 , F_7 ( V_10 , V_53 ) & ~ V_54 ) ;
F_11 ( V_10 , V_65 , V_66 ) ;
return ( F_14 ( V_10 ) ) ;
}
static int
F_9 ( struct V_9 * V_10 )
{
struct V_67 V_68 ;
struct V_69 * V_70 ;
int V_12 ;
T_3 V_71 ;
V_68 . V_72 = V_10 ;
V_68 . V_73 = V_74 ;
V_68 . V_75 = V_76 ;
V_68 . V_77 = V_76 ;
V_68 . V_78 = V_79 ;
V_68 . V_80 = 0 ;
V_68 . V_81 = V_82 ;
V_68 . V_83 = V_84 ;
V_68 . V_85 = V_86 ;
V_68 . V_87 = V_88 ;
V_68 . V_89 = V_90 ;
V_70 = V_10 -> V_52 ;
if ( V_91 )
F_8 ( L_2 , F_15 ( V_10 ) ) ;
V_12 = F_16 ( & V_68 , ( V_92 * ) V_70 ,
0 , sizeof( * V_70 ) / 2 ) ;
if ( V_12 ) {
if ( F_17 ( V_70 ) == 0 ) {
if( V_91 )
F_8 ( L_3 ) ;
V_12 = 0 ;
} else if ( V_91 ) {
F_8 ( L_4 ) ;
}
}
if ( ! V_12 ) {
if ( V_91 )
F_8 ( L_5 , F_15 ( V_10 ) ) ;
V_10 -> V_25 |= V_38 ;
} else {
int V_4 ;
int V_93 ;
V_92 V_94 ;
V_93 = ( V_10 -> V_39 & V_40 ) != 0 ? 16 : 8 ;
V_94 = 0 ;
for ( V_4 = 0 ; V_4 < V_93 ; V_4 ++ ) {
T_3 V_95 ;
V_95 = ( V_70 -> V_96 [ V_4 ] & V_97 ) << 4 ;
if ( V_70 -> V_96 [ V_4 ] & V_98 )
V_95 |= V_99 ;
if ( V_70 -> V_96 [ V_4 ] & V_100 )
V_95 |= V_101 ;
if ( V_70 -> V_96 [ V_4 ] & V_102 )
V_94 |= ( 0x01 << V_4 ) ;
F_11 ( V_10 , V_103 + V_4 , V_95 ) ;
}
F_11 ( V_10 , V_104 , ~ ( V_94 & 0xff ) ) ;
F_11 ( V_10 , V_104 + 1 , ~ ( ( V_94 >> 8 ) & 0xff ) ) ;
V_10 -> V_41 = V_70 -> V_105 & V_106 ;
V_71 = ( V_10 -> V_41 & 0x7 ) ;
if ( V_70 -> V_107 & V_108 )
V_71 |= V_109 ;
if ( V_70 -> V_107 & V_110 )
V_71 |= V_111 ;
if ( V_70 -> V_112 & V_113 )
V_10 -> V_25 |= V_50 ;
F_11 ( V_10 , V_34 , V_71 ) ;
if ( V_70 -> V_107 & V_114 )
V_10 -> V_25 |= V_44 ;
}
return ( V_12 ) ;
}
static int
F_18 ( struct V_9 * V_10 )
{
int error ;
error = F_19 ( V_10 ) ;
V_10 -> V_27 |= V_29 ;
return ( error ) ;
}
static int
F_20 ( struct V_9 * V_10 )
{
int error ;
error = F_19 ( V_10 ) ;
V_10 -> V_27 |= V_28 ;
return ( error ) ;
}
static int
F_19 ( struct V_9 * V_10 )
{
V_10 -> V_115 = 'A' ;
V_10 -> V_116 = 'B' ;
V_10 -> V_27 = V_117 ;
V_10 -> V_39 = V_118 ;
V_10 -> V_119 |= V_120 ;
V_10 -> V_25 |= V_121 ;
V_10 -> V_122 = 448 ;
return ( 0 ) ;
}
