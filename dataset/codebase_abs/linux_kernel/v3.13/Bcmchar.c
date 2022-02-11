static int F_1 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
struct V_4 * V_5 = NULL ;
struct V_6 * V_7 = NULL ;
V_5 = F_2 ( V_8 ) ;
V_7 = F_3 ( sizeof( struct V_6 ) , V_9 ) ;
if ( ! V_7 )
return - V_10 ;
V_7 -> V_5 = V_5 ;
V_7 -> V_11 = 0xFFFFFFFF & ~ ( 1 << 0xB ) ;
F_4 ( & V_5 -> V_12 ) ;
V_7 -> V_13 = V_5 -> V_14 ;
V_5 -> V_14 = V_7 ;
F_5 ( & V_5 -> V_12 ) ;
V_3 -> V_15 = V_7 ;
F_6 ( & V_5 -> V_16 ) ;
F_7 ( V_1 , V_3 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
struct V_6 * V_7 , * V_17 , * V_18 ;
struct V_4 * V_5 = NULL ;
struct V_19 * V_20 , * V_21 ;
V_7 = (struct V_6 * ) V_3 -> V_15 ;
if ( V_7 == NULL )
return 0 ;
V_5 = V_7 -> V_5 ;
F_4 ( & V_5 -> V_12 ) ;
V_17 = V_5 -> V_14 ;
for ( V_18 = NULL ; V_17 ; V_18 = V_17 , V_17 = V_17 -> V_13 ) {
if ( V_17 == V_7 )
break;
}
if ( V_17 ) {
if ( ! V_18 )
V_5 -> V_14 = V_17 -> V_13 ;
else
V_18 -> V_13 = V_17 -> V_13 ;
} else {
F_5 ( & V_5 -> V_12 ) ;
return 0 ;
}
V_20 = V_7 -> V_22 ;
while ( V_20 ) {
V_21 = V_20 -> V_13 ;
F_9 ( V_20 ) ;
V_20 = V_21 ;
}
F_5 ( & V_5 -> V_12 ) ;
F_10 ( & V_5 -> V_16 ) ;
F_11 ( V_7 ) ;
V_3 -> V_15 = NULL ;
return 0 ;
}
static T_1 F_12 ( struct V_2 * V_3 , char T_2 * V_23 , T_3 V_24 ,
T_4 * V_25 )
{
struct V_6 * V_7 = V_3 -> V_15 ;
struct V_4 * V_5 = V_7 -> V_5 ;
struct V_19 * V_26 = NULL ;
T_1 V_27 = 0 ;
int V_28 = 0 ;
unsigned long V_29 = 0 ;
V_28 = F_13 ( V_5 -> V_30 ,
( V_7 -> V_22 ||
V_5 -> V_31 ) ) ;
if ( ( V_28 == - V_32 ) ) {
F_14 ( V_5 , V_33 , V_34 , V_35 ,
L_1 ) ;
return V_28 ;
}
if ( V_5 -> V_31 ) {
F_14 ( V_5 , V_33 , V_34 , V_35 ,
L_2 ) ;
return - V_36 ;
}
if ( false == V_5 -> V_37 )
return - V_38 ;
F_4 ( & V_5 -> V_12 ) ;
if ( V_7 -> V_22 ) {
V_26 = V_7 -> V_22 ;
F_15 ( V_7 -> V_22 ,
V_7 -> V_39 ) ;
V_7 -> V_40 -- ;
}
F_5 ( & V_5 -> V_12 ) ;
if ( V_26 ) {
V_27 = V_26 -> V_41 ;
V_29 = F_16 ( V_23 , V_26 -> V_42 ,
F_17 ( T_3 , V_27 , V_24 ) ) ;
if ( V_29 ) {
F_18 ( V_26 ) ;
F_14 ( V_5 , V_43 , 0 , 0 ,
L_3 ) ;
return - V_44 ;
}
F_14 ( V_5 , V_33 , V_34 , V_35 ,
L_4 ,
V_27 , V_26 , V_45 -> V_46 ) ;
F_18 ( V_26 ) ;
}
F_14 ( V_5 , V_33 , V_34 , V_35 , L_5 ) ;
return V_27 ;
}
static long F_19 ( struct V_2 * V_3 , T_5 V_47 , T_6 V_48 )
{
struct V_6 * V_7 = V_3 -> V_15 ;
void T_2 * V_49 = ( void T_2 * ) V_48 ;
struct V_4 * V_5 = V_7 -> V_5 ;
INT V_50 = V_51 ;
int V_52 = 0 ;
struct V_53 V_54 ;
int V_55 ;
F_14 ( V_5 , V_33 , V_34 , V_35 , L_6 , V_47 , V_48 ) ;
if ( F_20 ( V_47 ) != V_56 )
return - V_44 ;
if ( F_21 ( V_47 ) & V_57 )
V_50 = ! F_22 ( V_58 , V_49 , F_23 ( V_47 ) ) ;
else if ( F_21 ( V_47 ) & V_59 )
V_50 = ! F_22 ( V_60 , V_49 , F_23 ( V_47 ) ) ;
else if ( V_61 == ( F_21 ( V_47 ) & V_61 ) )
V_50 = V_62 ;
if ( V_50 )
return - V_44 ;
if ( V_5 -> V_31 )
return - V_44 ;
if ( false == V_5 -> V_37 ) {
switch ( V_47 ) {
case V_63 :
case V_64 :
case V_65 :
case V_66 :
case V_67 :
case V_68 :
case V_69 :
case V_70 :
return - V_38 ;
default:
break;
}
}
V_50 = F_24 ( V_5 , V_47 , V_48 ) ;
if ( V_50 != V_71 )
return V_50 ;
switch ( V_47 ) {
case V_72 : {
struct V_73 V_74 = { 0 } ;
T_7 V_75 ;
T_5 V_76 ;
T_8 V_77 ;
if ( F_25 ( & V_54 , V_49 , sizeof( struct V_53 ) ) )
return - V_44 ;
if ( V_54 . V_78 > sizeof( V_74 ) )
return - V_79 ;
if ( F_25 ( & V_74 , V_54 . V_80 , V_54 . V_78 ) )
return - V_44 ;
if ( V_54 . V_81 > V_82 ||
V_54 . V_81 == 0 ) {
return - V_79 ;
}
V_76 = V_54 . V_81 ;
V_77 = 4 - ( V_76 % 4 ) ;
V_76 += V_77 % 4 ;
V_75 = F_26 ( V_76 , V_9 ) ;
if ( ! V_75 )
return - V_10 ;
V_55 = F_27 ( V_5 , ( T_5 ) V_74 . Register ,
( V_83 ) V_75 , V_76 ) ;
if ( V_55 > 0 ) {
V_50 = V_62 ;
if ( F_16 ( V_54 . V_84 , V_75 , V_55 ) ) {
F_11 ( V_75 ) ;
return - V_44 ;
}
} else {
V_50 = V_55 ;
}
F_11 ( V_75 ) ;
break;
}
case V_85 : {
struct V_86 V_87 = { 0 } ;
T_5 V_88 = 0 ;
if ( F_25 ( & V_54 , V_49 , sizeof( struct V_53 ) ) )
return - V_44 ;
if ( V_54 . V_78 > sizeof( V_87 ) )
return - V_79 ;
if ( F_25 ( & V_87 , V_54 . V_80 , V_54 . V_78 ) )
return - V_44 ;
V_88 = V_87 . Register & V_89 ;
if ( ! ( ( V_5 -> V_90 -> V_91 ) & V_92 ) &&
( ( V_88 == V_93 ) ||
( V_88 == V_94 ) ||
( V_88 == V_95 ) ||
( V_88 == V_96 ) ) ) {
F_14 ( V_5 , V_43 , 0 , 0 , L_7 ) ;
return - V_44 ;
}
V_50 = F_28 ( V_5 , ( T_5 ) V_87 . Register ,
( V_83 ) V_87 . V_97 , sizeof( T_6 ) ) ;
if ( V_50 == V_62 ) {
F_14 ( V_5 , V_33 , V_34 , V_35 , L_8 ) ;
} else {
F_14 ( V_5 , V_33 , V_34 , V_35 , L_9 ) ;
V_50 = - V_44 ;
}
break;
}
case V_98 :
case V_99 : {
struct V_73 V_74 = { 0 } ;
T_7 V_75 = NULL ;
T_5 V_88 = 0 ;
if ( ( V_5 -> V_100 == TRUE ) ||
( V_5 -> V_101 == TRUE ) ||
( V_5 -> V_102 == TRUE ) ) {
F_14 ( V_5 , V_43 , 0 , 0 , L_10 ) ;
return - V_38 ;
}
if ( F_25 ( & V_54 , V_49 , sizeof( struct V_53 ) ) )
return - V_44 ;
if ( V_54 . V_78 > sizeof( V_74 ) )
return - V_79 ;
if ( F_25 ( & V_74 , V_54 . V_80 , V_54 . V_78 ) )
return - V_44 ;
if ( V_54 . V_81 > V_82 ||
V_54 . V_81 == 0 ) {
return - V_79 ;
}
V_75 = F_26 ( V_54 . V_81 , V_9 ) ;
if ( ! V_75 )
return V_51 ;
if ( ( ( ( T_6 ) V_74 . Register & 0x0F000000 ) != 0x0F000000 ) ||
( ( T_6 ) V_74 . Register & 0x3 ) ) {
F_14 ( V_5 , V_43 , 0 , 0 , L_11 ,
( int ) V_74 . Register ) ;
F_11 ( V_75 ) ;
return - V_79 ;
}
V_88 = V_74 . Register & V_89 ;
V_55 = F_29 ( V_5 , ( T_5 ) V_74 . Register , ( V_83 ) V_75 , V_54 . V_81 ) ;
if ( V_55 > 0 ) {
V_50 = V_62 ;
if ( F_16 ( V_54 . V_84 , V_75 , V_55 ) ) {
F_11 ( V_75 ) ;
return - V_44 ;
}
} else {
V_50 = V_55 ;
}
F_11 ( V_75 ) ;
break;
}
case V_103 :
case V_104 : {
struct V_86 V_87 = { 0 } ;
T_5 V_88 = 0 ;
if ( ( V_5 -> V_100 == TRUE ) ||
( V_5 -> V_101 == TRUE ) ||
( V_5 -> V_102 == TRUE ) ) {
F_14 ( V_5 , V_43 , 0 , 0 , L_12 ) ;
return - V_38 ;
}
if ( F_25 ( & V_54 , V_49 , sizeof( struct V_53 ) ) )
return - V_44 ;
if ( V_54 . V_78 > sizeof( V_87 ) )
return - V_79 ;
if ( F_25 ( & V_87 , V_54 . V_80 , V_54 . V_78 ) )
return - V_44 ;
if ( ( ( ( T_6 ) V_87 . Register & 0x0F000000 ) != 0x0F000000 ) ||
( ( T_6 ) V_87 . Register & 0x3 ) ) {
F_14 ( V_5 , V_43 , 0 , 0 , L_13 , ( int ) V_87 . Register ) ;
return - V_79 ;
}
V_88 = V_87 . Register & V_89 ;
if ( ! ( ( V_5 -> V_90 -> V_91 ) & V_92 ) &&
( ( V_88 == V_93 ) ||
( V_88 == V_94 ) ||
( V_88 == V_95 ) ||
( V_88 == V_96 ) ) &&
( V_47 == V_103 ) ) {
F_14 ( V_5 , V_43 , 0 , 0 , L_7 ) ;
return - V_44 ;
}
V_50 = F_30 ( V_5 , ( T_5 ) V_87 . Register ,
( V_83 ) V_87 . V_97 , V_87 . V_105 ) ;
if ( V_50 == V_62 ) {
F_14 ( V_5 , V_43 , V_34 , V_35 , L_8 ) ;
} else {
F_14 ( V_5 , V_33 , V_34 , V_35 , L_9 ) ;
V_50 = - V_44 ;
}
break;
}
case V_69 : {
T_9 V_106 [ 4 ] ;
T_5 V_107 = 0 ;
T_5 V_108 = 0 ;
T_5 V_109 = 0 ;
struct V_110 V_111 = { 0 } ;
if ( ( V_5 -> V_100 == TRUE ) ||
( V_5 -> V_101 == TRUE ) ||
( V_5 -> V_102 == TRUE ) ) {
F_14 ( V_5 , V_33 , V_34 , V_35 , L_14 ) ;
return - V_38 ;
}
if ( F_25 ( & V_54 , V_49 , sizeof( struct V_53 ) ) )
return - V_44 ;
if ( V_54 . V_78 > sizeof( V_111 ) )
return - V_79 ;
if ( F_25 ( & V_111 , V_54 . V_80 , V_54 . V_78 ) )
return - V_44 ;
V_108 = V_111 . V_112 ;
V_109 = V_111 . V_113 ;
V_107 = ( 1 << V_108 ) ;
if ( F_31 ( V_5 , V_107 ) == false ) {
F_14 ( V_5 , V_33 , V_34 , V_35 , L_15 , V_107 ) ;
V_50 = - V_79 ;
break;
}
if ( V_109 ) {
V_50 = F_30 ( V_5 , V_114 , ( V_83 ) ( & V_107 ) , sizeof( T_5 ) ) ;
if ( V_50 == V_62 ) {
F_14 ( V_5 , V_33 , V_34 , V_35 , L_16 ) ;
} else {
F_14 ( V_5 , V_33 , V_34 , V_35 , L_17 , V_108 ) ;
break;
}
} else {
V_50 = F_30 ( V_5 , V_115 , ( V_83 ) ( & V_107 ) , sizeof( T_5 ) ) ;
if ( V_50 == V_62 ) {
F_14 ( V_5 , V_33 , V_34 , V_35 , L_16 ) ;
} else {
F_14 ( V_5 , V_33 , V_34 , V_35 , L_18 , V_108 ) ;
break;
}
}
V_55 = F_29 ( V_5 , ( T_5 ) V_116 , ( V_83 ) V_106 , sizeof( T_5 ) ) ;
if ( V_55 < 0 ) {
V_50 = V_55 ;
F_14 ( V_5 , V_33 , V_34 , V_35 ,
L_19 ) ;
break;
} else {
V_50 = V_62 ;
}
* ( T_5 * ) V_106 |= ( 1 << V_108 ) ;
V_50 = F_30 ( V_5 , V_116 ,
( V_83 ) V_106 , sizeof( T_5 ) ) ;
if ( V_50 == V_62 ) {
F_14 ( V_5 , V_33 , V_34 , V_35 , L_20 ) ;
} else {
F_14 ( V_5 , V_33 , V_34 , V_35 , L_21 ) ;
break;
}
}
break;
case V_117 : {
struct V_118 V_119 = { 0 } ;
F_14 ( V_5 , V_33 , V_34 , V_35 , L_22 ) ;
if ( ( V_5 -> V_100 == TRUE ) ||
( V_5 -> V_101 == TRUE ) ||
( V_5 -> V_102 == TRUE ) ) {
F_14 ( V_5 , V_33 , V_34 , V_35 , L_14 ) ;
V_50 = - V_38 ;
break;
}
if ( F_25 ( & V_54 , V_49 , sizeof( struct V_53 ) ) )
return - V_44 ;
if ( V_54 . V_78 > sizeof( V_119 ) )
return - V_79 ;
if ( F_25 ( & V_119 , V_54 . V_80 , V_54 . V_78 ) )
return - V_44 ;
if ( V_5 -> V_120 . V_121 ) {
if ( V_119 . V_122 == V_123 ) {
F_14 ( V_5 , V_33 , V_34 , V_35 , L_23 ) ;
V_5 -> V_124 = V_125 ;
} else {
F_14 ( V_5 , V_33 , V_34 , V_35 , L_24 ) ;
V_5 -> V_124 = V_126 ;
}
F_32 ( & V_5 -> V_120 . V_127 ) ;
}
}
break;
case V_70 : {
T_6 V_108 = 0 ;
T_9 V_128 [ 4 ] ;
struct V_110 V_111 = { 0 } ;
if ( ( V_5 -> V_100 == TRUE ) ||
( V_5 -> V_101 == TRUE ) ||
( V_5 -> V_102 == TRUE ) )
return - V_38 ;
if ( F_25 ( & V_54 , V_49 , sizeof( struct V_53 ) ) )
return - V_44 ;
if ( V_54 . V_78 > sizeof( V_111 ) )
return - V_79 ;
if ( F_25 ( & V_111 , V_54 . V_80 , V_54 . V_78 ) )
return - V_44 ;
V_108 = V_111 . V_112 ;
V_55 = F_29 ( V_5 , ( T_5 ) V_129 ,
( V_83 ) V_128 , sizeof( T_5 ) ) ;
if ( V_55 < 0 ) {
V_50 = V_55 ;
F_14 ( V_5 , V_43 , 0 , 0 , L_25 ) ;
return V_50 ;
} else {
V_50 = V_62 ;
}
}
break;
case V_130 : {
T_9 V_106 [ 4 ] ;
struct V_131 V_132 [ V_133 ] ;
struct V_131 * V_134 = (struct V_131 * ) V_132 ;
memset ( V_134 , 0 , V_133 * sizeof( struct V_131 ) ) ;
if ( ( V_5 -> V_100 == TRUE ) ||
( V_5 -> V_101 == TRUE ) ||
( V_5 -> V_102 == TRUE ) )
return - V_79 ;
if ( F_25 ( & V_54 , V_49 , sizeof( struct V_53 ) ) )
return - V_44 ;
if ( V_54 . V_78 > sizeof( V_132 ) )
return - V_79 ;
if ( F_25 ( & V_132 , V_54 . V_80 , V_54 . V_78 ) )
return - V_44 ;
if ( F_31 ( V_5 , V_134 [ V_135 ] . V_136 ) == false ) {
F_14 ( V_5 , V_33 , V_34 , V_35 ,
L_26 ,
V_134 [ V_135 ] . V_136 , V_5 -> V_137 ) ;
V_50 = - V_79 ;
break;
}
if ( ( V_134 [ V_135 ] . V_136 ) &
( V_134 [ V_135 ] . V_138 ) ) {
* ( T_5 * ) V_106 = V_134 [ V_135 ] . V_136 &
V_134 [ V_135 ] . V_138 &
V_134 [ V_135 ] . V_139 ;
if ( * ( T_5 * ) V_106 )
V_50 = F_30 ( V_5 , V_114 ,
( V_83 ) V_106 , sizeof( T_6 ) ) ;
if ( V_50 != V_62 ) {
F_14 ( V_5 , V_43 , 0 , 0 , L_27 ) ;
return V_50 ;
}
* ( T_5 * ) V_106 = ( V_134 [ V_135 ] . V_136 &
V_134 [ V_135 ] . V_138 &
( ~ ( V_134 [ V_135 ] . V_139 ) ) ) ;
if ( * ( T_5 * ) V_106 )
V_50 = F_30 ( V_5 , V_115 , ( V_83 ) V_106 , sizeof( T_6 ) ) ;
if ( V_50 != V_62 ) {
F_14 ( V_5 , V_43 , 0 , 0 , L_28 ) ;
return V_50 ;
}
}
if ( V_134 [ V_135 ] . V_136 ) {
V_55 = F_29 ( V_5 , ( T_5 ) V_129 , ( V_83 ) V_106 , sizeof( T_5 ) ) ;
if ( V_55 < 0 ) {
V_50 = V_55 ;
F_14 ( V_5 , V_43 , 0 , 0 , L_29 ) ;
return V_50 ;
} else {
V_50 = V_62 ;
}
V_134 [ V_135 ] . V_139 = ( * ( T_5 * ) V_106 &
V_134 [ V_135 ] . V_136 ) ;
}
V_50 = F_16 ( V_54 . V_84 , & V_132 , V_54 . V_81 ) ;
if ( V_50 ) {
F_14 ( V_5 , V_43 , 0 , 0 ,
L_30 , V_50 ) ;
return - V_44 ;
}
}
break;
case V_140 : {
T_9 V_106 [ 4 ] ;
struct V_141 V_142 [ V_133 ] ;
struct V_141 * V_143 = (struct V_141 * ) V_142 ;
if ( ( V_5 -> V_100 == TRUE ) ||
( V_5 -> V_101 == TRUE ) ||
( V_5 -> V_102 == TRUE ) )
return - V_79 ;
if ( F_25 ( & V_54 , V_49 , sizeof( struct V_53 ) ) )
return - V_44 ;
if ( V_54 . V_78 > sizeof( V_142 ) )
return - V_79 ;
if ( F_25 ( & V_142 , V_54 . V_80 , V_54 . V_78 ) )
return - V_44 ;
V_55 = F_29 ( V_5 , ( T_5 ) V_116 , ( V_83 ) V_106 , sizeof( T_5 ) ) ;
if ( V_55 < 0 ) {
V_50 = V_55 ;
F_14 ( V_5 , V_43 , 0 , 0 , L_31 ) ;
return V_50 ;
} else {
V_50 = V_62 ;
}
if ( F_31 ( V_5 , V_143 [ V_135 ] . V_136 ) == false ) {
F_14 ( V_5 , V_33 , V_34 , V_35 ,
L_26 ,
V_143 [ V_135 ] . V_136 , V_5 -> V_137 ) ;
V_50 = - V_79 ;
break;
}
if ( V_143 [ V_135 ] . V_136 ) {
* ( T_5 * ) V_106 |= ( V_143 [ V_135 ] . V_144 &
V_143 [ V_135 ] . V_136 ) ;
* ( T_5 * ) V_106 &= ~ ( ( ~ V_143 [ V_135 ] . V_144 ) &
V_143 [ V_135 ] . V_136 ) ;
V_143 [ V_135 ] . V_144 = * ( T_5 * ) V_106 ;
V_50 = F_30 ( V_5 , V_116 , ( V_83 ) V_106 , sizeof( T_6 ) ) ;
if ( V_50 == V_62 ) {
F_14 ( V_5 , V_33 , V_34 , V_35 ,
L_32 ) ;
} else {
F_14 ( V_5 , V_43 , 0 , 0 ,
L_33 ) ;
V_50 = - V_44 ;
break;
}
} else {
V_143 [ V_135 ] . V_144 = * ( T_5 * ) V_106 ;
}
V_50 = F_16 ( V_54 . V_84 , & V_142 , V_54 . V_81 ) ;
if ( V_50 ) {
F_14 ( V_5 , V_43 , 0 , 0 ,
L_30 , V_50 ) ;
return - V_44 ;
}
}
break;
case V_63 :
case V_64 :
case V_65 :
case V_66 :
case V_67 :
case V_68 : {
T_10 V_145 = NULL ;
if ( F_25 ( & V_54 , V_49 , sizeof( struct V_53 ) ) )
return - V_44 ;
if ( V_54 . V_78 < sizeof( struct V_146 ) )
return - V_79 ;
if ( V_54 . V_78 > V_147 )
return - V_79 ;
V_145 = F_33 ( V_54 . V_80 ,
V_54 . V_78 ) ;
if ( F_34 ( V_145 ) )
return F_35 ( V_145 ) ;
F_4 ( & V_5 -> V_148 ) ;
V_50 = F_36 ( V_5 -> V_149 ,
! V_5 -> V_102 ,
( 1 * V_150 ) ) ;
if ( V_50 == - V_32 )
goto V_151;
if ( V_5 -> V_102 ) {
F_14 ( V_5 , V_33 , V_34 , V_35 ,
L_34 ) ;
V_50 = V_51 ;
goto V_151;
}
V_50 = F_37 ( V_5 , ( T_10 ) V_145 ) ;
V_151:
F_5 ( & V_5 -> V_148 ) ;
F_11 ( V_145 ) ;
break;
}
case V_152 : {
if ( F_38 ( & V_5 -> V_153 ) ) {
F_14 ( V_5 , V_33 , V_34 , V_35 ,
L_35 ) ;
return - V_38 ;
}
F_14 ( V_5 , V_43 , 0 , 0 ,
L_36 , V_45 -> V_46 ) ;
if ( F_38 ( & V_5 -> V_154 ) )
return - V_155 ;
V_5 -> V_156 = false ;
V_5 -> V_157 = V_45 -> V_46 ;
V_5 -> V_158 = false ;
V_5 -> V_37 = false ;
F_39 ( V_5 -> V_159 ) ;
F_40 ( V_5 -> V_159 ) ;
V_50 = F_41 ( V_5 ) ;
if ( V_50 ) {
F_42 ( V_160 L_37 , V_5 -> V_159 -> V_161 ) ;
F_5 ( & V_5 -> V_154 ) ;
F_5 ( & V_5 -> V_153 ) ;
return V_50 ;
}
F_43 ( 10 ) ;
F_5 ( & V_5 -> V_153 ) ;
return V_50 ;
}
case V_162 : {
struct V_163 * V_164 = NULL ;
F_14 ( V_5 , V_43 , 0 , 0 , L_36 , V_45 -> V_46 ) ;
if ( ! F_38 ( & V_5 -> V_154 ) ) {
F_14 ( V_5 , V_43 , 0 , 0 ,
L_38 ) ;
F_5 ( & V_5 -> V_154 ) ;
V_50 = - V_79 ;
return V_50 ;
}
if ( F_25 ( & V_54 , V_49 , sizeof( struct V_53 ) ) ) {
F_5 ( & V_5 -> V_154 ) ;
return - V_44 ;
}
F_14 ( V_5 , V_43 , 0 , 0 ,
L_39 , V_54 . V_78 ) ;
if ( V_54 . V_78 > sizeof( struct V_163 ) ) {
F_5 ( & V_5 -> V_154 ) ;
return - V_79 ;
}
V_164 = F_26 ( sizeof( * V_164 ) , V_9 ) ;
if ( ! V_164 ) {
F_5 ( & V_5 -> V_154 ) ;
return - V_10 ;
}
if ( F_25 ( V_164 , V_54 . V_80 , V_54 . V_78 ) ) {
F_5 ( & V_5 -> V_154 ) ;
F_11 ( V_164 ) ;
return - V_44 ;
}
if ( ! V_164 -> V_165 ||
( V_164 -> V_166 == 0 ) ) {
F_14 ( V_5 , V_43 , 0 , 0 , L_40 ,
V_164 -> V_166 ) ;
F_5 ( & V_5 -> V_154 ) ;
F_11 ( V_164 ) ;
V_50 = - V_79 ;
return V_50 ;
}
V_50 = F_44 ( V_5 , V_164 ) ;
if ( V_50 != V_62 ) {
if ( V_164 -> V_167 == V_168 )
F_14 ( V_5 , V_43 , 0 , 0 , L_41 ) ;
else
F_14 ( V_5 , V_43 , 0 , 0 , L_42 ) ;
if ( V_5 -> V_120 . V_121 & V_169 ) {
V_5 -> V_124 = V_170 ;
V_5 -> V_120 . V_171 = false ;
F_32 ( & V_5 -> V_120 . V_127 ) ;
}
}
if ( V_50 != V_62 )
F_5 ( & V_5 -> V_154 ) ;
F_14 ( V_5 , V_43 , V_34 , V_35 , L_43 ) ;
F_11 ( V_164 ) ;
return V_50 ;
}
case V_172 : {
if ( ! F_38 ( & V_5 -> V_154 ) ) {
F_5 ( & V_5 -> V_154 ) ;
return - V_79 ;
}
if ( F_38 ( & V_5 -> V_153 ) ) {
F_14 ( V_5 , V_43 , 0 , 0 ,
L_44 ) ;
F_5 ( & V_5 -> V_154 ) ;
return - V_38 ;
}
V_5 -> V_156 = TRUE ;
V_5 -> V_158 = TRUE ;
F_45 ( & V_5 -> V_173 , 0 ) ;
V_5 -> V_174 = 0 ;
V_5 -> V_175 = 0 ;
V_50 = F_46 ( V_5 ) ;
if ( V_50 ) {
F_14 ( V_5 , V_43 , 0 , 0 , L_45 ) ;
F_5 ( & V_5 -> V_154 ) ;
F_5 ( & V_5 -> V_153 ) ;
return V_50 ;
} else {
F_14 ( V_5 , V_33 , V_34 ,
V_35 , L_46 ) ;
}
F_43 ( 10 ) ;
if ( F_47 ( (struct V_176 * ) V_5 -> V_177 ) )
F_14 ( V_5 , V_43 , 0 , 0 , L_47 ) ;
V_52 = 5 * V_150 ;
V_5 -> V_178 = false ;
F_48 ( V_5 -> V_179 ,
V_5 -> V_178 , V_52 ) ;
V_5 -> V_157 = V_180 ;
V_5 -> V_37 = TRUE ;
F_45 ( & V_5 -> V_173 , 0 ) ;
V_5 -> V_174 = 0 ;
V_5 -> V_181 = 0 ;
F_45 ( & V_5 -> V_182 , 0 ) ;
V_5 -> V_183 = 0 ;
V_5 -> V_184 = 0 ;
if ( V_5 -> V_120 . V_121 & V_169 ) {
V_5 -> V_124 = V_185 ;
F_32 ( & V_5 -> V_120 . V_127 ) ;
}
if ( ! V_52 )
V_50 = - V_36 ;
F_5 ( & V_5 -> V_154 ) ;
F_5 ( & V_5 -> V_153 ) ;
return V_50 ;
}
case V_186 :
V_50 = 0 ;
if ( F_49 ( V_5 -> V_187 , ( unsigned long T_2 * ) V_48 ) )
V_50 = - V_44 ;
break;
case V_188 :
V_50 = 0 ;
if ( F_49 ( V_5 -> V_189 , ( unsigned long T_2 * ) V_48 ) )
V_50 = - V_44 ;
break;
case V_190 : {
INT V_191 = F_38 ( & V_5 -> V_153 ) ;
if ( V_191 ) {
F_14 ( V_5 , V_43 , 0 , 0 , L_48 ) ;
return - V_38 ;
}
F_4 ( & V_5 -> V_12 ) ;
V_50 = F_41 ( V_5 ) ;
F_50 () ;
F_5 ( & V_5 -> V_12 ) ;
F_5 ( & V_5 -> V_153 ) ;
F_51 ( V_5 ) ;
break;
}
case V_192 : {
T_11 V_193 ;
V_50 = 0 ;
for ( V_193 = 0 ; V_193 < V_194 ; V_193 ++ ) {
if ( F_49 ( V_5 -> V_195 [ V_193 ] . V_196 ,
( unsigned long T_2 * ) V_48 ) ) {
V_50 = - V_44 ;
break;
}
}
break;
}
case V_197 :
F_52 ( V_5 ) ;
F_53 ( & V_5 -> V_198 ) ;
V_50 = V_62 ;
break;
case V_199 :
if ( F_16 ( V_49 , & V_5 -> V_195 , sizeof( struct V_200 ) * V_194 ) )
return - V_44 ;
V_50 = V_62 ;
break;
case V_201 : {
T_5 V_202 = 0 ;
if ( F_25 ( & V_202 , V_49 , sizeof( T_5 ) ) )
return - V_44 ;
if ( V_202 ) {
F_14 ( V_5 , V_33 , V_34 , V_35 , L_49 ) ;
V_5 -> V_203 = V_204 ;
} else {
F_14 ( V_5 , V_33 , V_34 , V_35 , L_50 ) ;
V_5 -> V_203 = V_205 ;
}
V_50 = V_62 ;
break;
}
case V_206 : {
T_12 V_41 ;
if ( F_25 ( & V_54 , V_49 , sizeof( struct V_53 ) ) )
return - V_44 ;
V_41 = F_17 ( T_12 , V_54 . V_81 , strlen ( V_207 ) + 1 ) ;
if ( F_16 ( V_54 . V_84 , V_207 , V_41 ) )
return - V_44 ;
V_50 = V_62 ;
break;
}
case V_208 : {
struct V_209 V_210 ;
if ( F_25 ( & V_54 , V_49 , sizeof( struct V_53 ) ) ) {
F_14 ( V_5 , V_43 , 0 , 0 , L_51 ) ;
return - V_44 ;
}
if ( V_54 . V_81 != sizeof( V_210 ) ) {
V_50 = - V_79 ;
break;
}
memset ( & V_210 , 0 , sizeof( V_210 ) ) ;
V_210 . V_211 = V_5 -> V_100 ;
V_210 . V_212 = V_5 -> V_101 ;
V_210 . V_213 = V_5 -> V_184 ;
if ( F_16 ( V_54 . V_84 , & V_210 , F_17 ( T_3 , sizeof( V_210 ) , V_54 . V_81 ) ) ) {
F_14 ( V_5 , V_43 , 0 , 0 , L_52 ) ;
return - V_44 ;
}
V_50 = V_62 ;
break;
}
case V_214 : {
T_5 V_215 ;
if ( F_25 ( & V_54 , V_49 , sizeof( struct V_53 ) ) )
return - V_44 ;
if ( F_25 ( & V_215 , V_54 . V_80 , sizeof( T_5 ) ) )
return - V_44 ;
if ( V_215 )
V_5 -> V_14 -> V_216 = TRUE ;
else
V_5 -> V_14 -> V_216 = false ;
break;
}
case V_217 : {
T_6 V_218 = 0 ;
if ( F_25 ( & V_54 , V_49 , sizeof( struct V_53 ) ) )
return - V_44 ;
if ( V_54 . V_81 < sizeof( struct V_219 ) ) {
F_14 ( V_5 , V_43 , 0 , 0 ,
L_53 ,
V_54 . V_81 , sizeof( struct V_219 ) ) ;
return - V_79 ;
}
if ( F_25 ( & V_218 , V_54 . V_80 , sizeof( V_218 ) ) )
return - V_44 ;
F_14 ( V_5 , V_33 , V_34 , V_35 , L_54 , V_218 ) ;
F_54 ( V_5 , V_218 , V_54 . V_84 ) ;
V_50 = V_62 ;
}
break;
case V_220 : {
T_10 V_75 ;
if ( F_25 ( & V_54 , V_49 , sizeof( struct V_53 ) ) )
return - V_44 ;
if ( V_54 . V_81 != sizeof( struct V_221 ) ) {
F_14 ( V_5 , V_43 , 0 , 0 ,
L_55 ,
V_54 . V_81 , sizeof( struct V_221 ) ) ;
return - V_79 ;
}
V_75 = F_3 ( sizeof( struct V_221 ) , V_9 ) ;
if ( ! V_75 )
return V_51 ;
V_50 = F_55 ( V_5 , V_75 ) ;
F_56 ( V_75 , V_7 ) ;
if ( V_50 != V_51 )
if ( F_16 ( V_54 . V_84 , V_75 , sizeof( struct V_221 ) ) ) {
F_11 ( V_75 ) ;
return - V_44 ;
}
F_11 ( V_75 ) ;
break;
}
case V_222 :
if ( ( false == V_5 -> V_223 ) && ( TRUE == V_5 -> V_100 ) ) {
V_5 -> V_224 = V_225 ;
V_5 -> V_226 = TRUE ;
F_32 ( & V_5 -> V_227 ) ;
}
V_50 = V_62 ;
break;
case V_228 : {
struct V_229 * V_230 ;
T_5 V_88 = 0 ;
T_7 V_145 = NULL ;
if ( ( V_5 -> V_100 == TRUE ) ||
( V_5 -> V_101 == TRUE ) ||
( V_5 -> V_102 == TRUE ) ) {
F_14 ( V_5 , V_43 , 0 , 0 , L_56 ) ;
V_50 = - V_38 ;
break;
}
if ( F_25 ( & V_54 , V_49 , sizeof( struct V_53 ) ) )
return - V_44 ;
if ( V_54 . V_78 < sizeof( T_6 ) * 2 )
return - V_79 ;
V_145 = F_33 ( V_54 . V_80 ,
V_54 . V_78 ) ;
if ( F_34 ( V_145 ) )
return F_35 ( V_145 ) ;
V_230 = (struct V_229 * ) V_145 ;
if ( ( ( T_6 ) V_230 -> Register & 0x0F000000 ) != 0x0F000000 ||
( ( T_6 ) V_230 -> Register & 0x3 ) ) {
F_14 ( V_5 , V_43 , 0 , 0 , L_13 , ( int ) V_230 -> Register ) ;
F_11 ( V_145 ) ;
V_50 = - V_79 ;
break;
}
V_88 = V_230 -> Register & V_89 ;
if ( ! ( ( V_5 -> V_90 -> V_91 ) & V_92 ) &&
( ( V_88 == V_93 ) ||
( V_88 == V_94 ) ||
( V_88 == V_95 ) ||
( V_88 == V_96 ) ) &&
( V_47 == V_103 ) ) {
F_11 ( V_145 ) ;
F_14 ( V_5 , V_43 , 0 , 0 , L_7 ) ;
V_50 = - V_44 ;
break;
}
if ( V_230 -> V_231 == false )
V_50 = F_57 ( V_5 , ( T_5 ) V_230 -> Register , ( T_7 ) V_230 -> V_232 , V_54 . V_78 - 2 * sizeof( T_6 ) ) ;
else
V_50 = F_30 ( V_5 , ( T_5 ) V_230 -> Register , ( V_83 ) V_230 -> V_232 , V_54 . V_78 - 2 * sizeof( T_6 ) ) ;
if ( V_50 != V_62 )
F_14 ( V_5 , V_43 , 0 , 0 , L_9 ) ;
F_11 ( V_145 ) ;
break;
}
case V_233 :
if ( F_25 ( & V_54 , V_49 , sizeof( struct V_53 ) ) )
return - V_44 ;
if ( V_5 -> V_234 == V_235 || V_5 -> V_234 == V_236 ) {
if ( F_16 ( V_54 . V_84 , & V_5 -> V_237 , sizeof( T_5 ) ) )
return - V_44 ;
}
V_50 = V_62 ;
break;
case V_238 : {
T_5 V_239 = 0 ;
if ( V_5 -> V_234 == V_236 ) {
if ( F_25 ( & V_54 , V_49 , sizeof( struct V_53 ) ) )
return - V_44 ;
if ( F_25 ( & V_239 , V_54 . V_80 , sizeof( T_5 ) ) )
return - V_44 ;
if ( ( V_239 < V_240 ) || ( V_239 > V_241 ) ) {
if ( F_16 ( V_54 . V_84 , & V_5 -> V_239 ,
sizeof( T_5 ) ) )
return - V_44 ;
} else {
if ( F_58 ( V_5 ) ) {
if ( F_16 ( V_54 . V_84 , & V_5 -> V_239 , sizeof( T_5 ) ) )
return - V_44 ;
} else {
if ( ( TRUE == V_5 -> V_101 ) || ( TRUE == V_5 -> V_100 ) ) {
F_14 ( V_5 , V_43 , 0 , 0 , L_57 ) ;
return - V_38 ;
}
V_5 -> V_239 = V_239 ;
F_59 ( V_5 , V_5 -> V_239 ) ;
}
}
V_50 = V_62 ;
} else {
V_50 = V_51 ;
}
}
break;
case V_242 :
#ifdef F_60
{
struct V_243 V_244 ;
F_14 ( V_5 , V_33 , V_34 , V_35 , L_58 ) ;
if ( F_25 ( & V_54 , V_49 , sizeof( struct V_53 ) ) )
return - V_44 ;
if ( F_25 ( & V_244 , V_54 . V_80 , sizeof( struct V_243 ) ) )
return - V_44 ;
F_14 ( V_5 , V_43 , 0 , 0 , L_59 ,
V_244 . V_245 , V_244 . Type ) ;
V_244 . V_246 = 1 << V_244 . V_246 ;
F_14 ( V_5 , V_43 , 0 , 0 , L_60 , V_244 . V_246 ) ;
V_5 -> V_247 . type |= V_244 . Type ;
if ( V_244 . V_245 )
V_5 -> V_247 . V_248 [ V_244 . Type ] |= V_244 . V_246 ;
else
V_5 -> V_247 . V_248 [ V_244 . Type ] &= ~ V_244 . V_246 ;
F_61 ( V_5 ) ;
}
#endif
break;
case V_249 :
case V_250 : {
struct V_251 V_252 ;
T_13 V_253 = NULL ;
T_6 V_254 = 0 ;
struct V_255 V_256 , V_257 ;
memset ( & V_256 , 0 , sizeof( struct V_255 ) ) ;
memset ( & V_257 , 0 , sizeof( struct V_255 ) ) ;
if ( ( V_5 -> V_234 == V_236 ) && ( V_5 -> V_258 == 0 ) ) {
F_14 ( V_5 , V_43 , 0 , 0 , L_61 ) ;
return - V_44 ;
}
if ( F_58 ( V_5 ) ) {
if ( ( V_5 -> V_259 != V_260 ) &&
( V_5 -> V_259 != V_261 ) &&
( V_5 -> V_259 != V_262 ) ) {
F_14 ( V_5 , V_43 , 0 , 0 , L_62 ) ;
return V_51 ;
}
}
if ( F_25 ( & V_54 , V_49 , sizeof( struct V_53 ) ) )
return - V_44 ;
if ( F_25 ( & V_252 ,
( V_249 == V_47 ) ? V_54 . V_84 : V_54 . V_80 ,
sizeof( struct V_251 ) ) )
return - V_44 ;
if ( V_252 . V_263 > V_5 -> V_237 )
return V_51 ;
if ( V_252 . V_264 > V_5 -> V_237 - V_252 . V_263 ) {
return V_51 ;
}
V_253 = F_33 ( V_252 . V_265 ,
V_252 . V_263 ) ;
if ( F_34 ( V_253 ) )
return F_35 ( V_253 ) ;
F_62 ( & V_256 ) ;
if ( V_249 == V_47 ) {
F_4 ( & V_5 -> V_153 ) ;
if ( ( V_5 -> V_100 == TRUE ) ||
( V_5 -> V_101 == TRUE ) ||
( V_5 -> V_102 == TRUE ) ) {
F_14 ( V_5 , V_33 , V_34 , V_35 , L_57 ) ;
F_5 ( & V_5 -> V_153 ) ;
F_11 ( V_253 ) ;
return - V_38 ;
}
V_50 = F_63 ( V_5 , ( V_83 ) V_253 , V_252 . V_264 , V_252 . V_263 ) ;
F_5 ( & V_5 -> V_153 ) ;
if ( V_50 != V_62 ) {
F_11 ( V_253 ) ;
return V_50 ;
}
if ( F_16 ( V_252 . V_265 , V_253 , V_252 . V_263 ) ) {
F_11 ( V_253 ) ;
return - V_44 ;
}
} else {
F_4 ( & V_5 -> V_153 ) ;
if ( ( V_5 -> V_100 == TRUE ) ||
( V_5 -> V_101 == TRUE ) ||
( V_5 -> V_102 == TRUE ) ) {
F_14 ( V_5 , V_33 , V_34 , V_35 , L_57 ) ;
F_5 ( & V_5 -> V_153 ) ;
F_11 ( V_253 ) ;
return - V_38 ;
}
V_5 -> V_266 = TRUE ;
if ( F_58 ( V_5 ) ) {
V_50 = F_64 ( V_5 , V_5 -> V_259 ) ;
if ( V_50 != V_62 ) {
if ( ( ( V_252 . V_264 + V_252 . V_263 ) != V_5 -> V_237 ) ||
( V_252 . V_263 < V_267 ) ) {
F_14 ( V_5 , V_33 , V_34 , V_35 , L_63 ) ;
F_5 ( & V_5 -> V_153 ) ;
F_11 ( V_253 ) ;
return V_50 ;
}
V_254 = F_65 ( * ( V_83 ) ( V_253 + V_252 . V_263 - V_267 ) ) ;
if ( V_254 != V_268 ) {
F_14 ( V_5 , V_33 , V_34 , V_35 , L_63 ) ;
F_5 ( & V_5 -> V_153 ) ;
F_11 ( V_253 ) ;
return V_50 ;
}
}
}
V_50 = F_66 ( V_5 , ( V_83 ) V_253 , V_252 . V_264 , V_252 . V_263 , V_252 . V_269 ) ;
if ( F_58 ( V_5 ) )
F_67 ( V_5 , V_5 -> V_259 ) ;
V_5 -> V_266 = false ;
F_5 ( & V_5 -> V_153 ) ;
if ( V_50 != V_62 ) {
F_11 ( V_253 ) ;
return V_50 ;
}
}
F_62 ( & V_257 ) ;
F_14 ( V_5 , V_33 , V_34 , V_35 , L_64 , ( V_257 . V_270 - V_256 . V_270 ) * 1000 + ( V_257 . V_271 - V_256 . V_271 ) / 1000 ) ;
F_11 ( V_253 ) ;
return V_62 ;
}
case V_272 : {
struct V_273 V_274 = { 0 } ;
T_13 V_275 = NULL ;
T_5 V_276 = 0 ;
T_5 V_277 = 0 ;
T_5 V_278 = 0 ;
T_5 V_279 = 0 ;
void T_2 * V_280 ;
if ( F_58 ( V_5 ) != TRUE ) {
F_14 ( V_5 , V_43 , 0 , 0 , L_65 ) ;
return - V_79 ;
}
F_14 ( V_5 , V_33 , V_34 , V_35 , L_66 ) ;
if ( F_25 ( & V_54 , V_49 , sizeof( struct V_53 ) ) )
return - V_44 ;
if ( F_25 ( & V_274 , V_54 . V_80 , sizeof( struct V_273 ) ) )
return - V_44 ;
F_14 ( V_5 , V_33 , V_34 , V_35 , L_67 , V_274 . V_281 ) ;
F_14 ( V_5 , V_33 , V_34 , V_35 , L_68 , V_274 . V_282 ) ;
F_14 ( V_5 , V_33 , V_34 , V_35 , L_69 , V_274 . V_283 ) ;
F_14 ( V_5 , V_33 , V_34 , V_35 , L_70 , V_274 . V_269 ) ;
if ( F_68 ( V_5 , & V_274 ) == false )
return V_51 ;
V_276 = V_274 . V_283 ;
if ( V_276 > V_5 -> V_239 )
V_277 = V_5 -> V_239 ;
else
V_277 = V_276 ;
V_279 = V_274 . V_282 ;
V_280 = V_54 . V_84 ;
V_275 = ( T_7 ) F_3 ( V_277 , V_9 ) ;
if ( V_275 == NULL ) {
F_14 ( V_5 , V_43 , 0 , 0 , L_71 ) ;
return - V_10 ;
}
F_4 ( & V_5 -> V_153 ) ;
if ( ( V_5 -> V_100 == TRUE ) ||
( V_5 -> V_101 == TRUE ) ||
( V_5 -> V_102 == TRUE ) ) {
F_14 ( V_5 , V_33 , V_34 , V_35 , L_57 ) ;
F_5 ( & V_5 -> V_153 ) ;
F_11 ( V_275 ) ;
return - V_38 ;
}
while ( V_276 ) {
if ( V_276 > V_5 -> V_239 )
V_278 = V_5 -> V_239 ;
else
V_278 = V_276 ;
V_50 = F_69 ( V_5 , ( V_83 ) V_275 , V_274 . V_281 , V_279 , V_278 ) ;
if ( V_50 ) {
F_14 ( V_5 , V_33 , V_34 , V_35 , L_72 , V_50 ) ;
break;
}
F_70 ( V_5 , V_33 , V_34 , V_35 , V_275 , V_278 ) ;
V_50 = F_16 ( V_280 , V_275 , V_278 ) ;
if ( V_50 ) {
F_14 ( V_5 , V_33 , V_34 , V_35 , L_73 , V_50 ) ;
F_5 ( & V_5 -> V_153 ) ;
F_11 ( V_275 ) ;
return - V_44 ;
}
V_276 = V_276 - V_278 ;
if ( V_276 ) {
V_279 = V_279 + V_278 ;
V_280 = V_280 + V_278 ;
}
}
F_5 ( & V_5 -> V_153 ) ;
F_11 ( V_275 ) ;
}
break;
case V_284 : {
struct V_273 V_285 = { 0 } ;
T_13 V_286 ;
void T_2 * V_287 ;
T_5 V_276 = 0 ;
T_5 V_277 = 0 ;
T_5 V_288 = 0 ;
T_5 V_289 = 0 ;
if ( F_58 ( V_5 ) != TRUE ) {
F_14 ( V_5 , V_43 , 0 , 0 , L_65 ) ;
return - V_79 ;
}
V_5 -> V_290 = false ;
F_14 ( V_5 , V_33 , V_34 , V_35 , L_74 ) ;
if ( F_25 ( & V_54 , V_49 , sizeof( struct V_53 ) ) )
return - V_44 ;
if ( F_25 ( & V_285 , V_54 . V_80 , sizeof( struct V_273 ) ) )
return - V_44 ;
F_14 ( V_5 , V_33 , V_34 , V_35 , L_67 , V_285 . V_281 ) ;
F_14 ( V_5 , V_33 , V_34 , V_35 , L_75 , V_285 . V_282 ) ;
F_14 ( V_5 , V_33 , V_34 , V_35 , L_69 , V_285 . V_283 ) ;
F_14 ( V_5 , V_33 , V_34 , V_35 , L_70 , V_285 . V_269 ) ;
if ( ( V_285 . V_281 != V_291 ) && ( V_285 . V_281 != V_292 ) && ( V_285 . V_281 != V_293 ) ) {
F_14 ( V_5 , V_33 , V_34 , V_35 , L_76 ) ;
return - V_79 ;
}
if ( F_68 ( V_5 , & V_285 ) == false )
return V_51 ;
V_287 = V_285 . V_294 ;
V_288 = V_285 . V_282 ;
V_276 = V_285 . V_283 ;
if ( V_276 > V_5 -> V_239 )
V_277 = V_5 -> V_239 ;
else
V_277 = V_276 ;
V_286 = F_26 ( V_277 , V_9 ) ;
if ( V_286 == NULL )
return - V_10 ;
V_289 = V_5 -> V_239 ;
if ( V_288 % V_5 -> V_239 )
V_289 = V_5 -> V_239 - ( V_288 % V_5 -> V_239 ) ;
if ( V_276 < V_289 )
V_289 = V_276 ;
F_4 ( & V_5 -> V_153 ) ;
if ( ( V_5 -> V_100 == TRUE ) ||
( V_5 -> V_101 == TRUE ) ||
( V_5 -> V_102 == TRUE ) ) {
F_14 ( V_5 , V_33 , V_34 , V_35 , L_57 ) ;
F_5 ( & V_5 -> V_153 ) ;
F_11 ( V_286 ) ;
return - V_38 ;
}
F_64 ( V_5 , V_285 . V_281 ) ;
do {
V_50 = F_25 ( V_286 , V_287 , V_289 ) ;
if ( V_50 ) {
F_14 ( V_5 , V_43 , 0 , 0 , L_77 , V_50 ) ;
F_5 ( & V_5 -> V_153 ) ;
F_11 ( V_286 ) ;
return - V_44 ;
}
F_70 ( V_5 , V_33 , V_34 , V_35 , V_286 , V_289 ) ;
V_50 = F_71 ( V_5 , ( V_83 ) V_286 , V_285 . V_281 , V_288 , V_289 , V_285 . V_269 ) ;
if ( V_50 ) {
F_14 ( V_5 , V_43 , 0 , 0 , L_72 , V_50 ) ;
break;
}
V_276 = V_276 - V_289 ;
if ( V_276 ) {
V_288 = V_288 + V_289 ;
V_287 = V_287 + V_289 ;
if ( V_276 > V_5 -> V_239 )
V_289 = V_5 -> V_239 ;
else
V_289 = V_276 ;
}
} while ( V_276 > 0 );
F_67 ( V_5 , V_285 . V_281 ) ;
F_5 ( & V_5 -> V_153 ) ;
F_11 ( V_286 ) ;
}
break;
case V_295 : {
struct V_296 * V_297 ;
F_14 ( V_5 , V_33 , V_34 , V_35 , L_78 ) ;
if ( F_25 ( & V_54 , V_49 , sizeof( struct V_53 ) ) )
return - V_44 ;
if ( V_54 . V_81 != sizeof( struct V_296 ) )
return - V_79 ;
V_297 = F_3 ( sizeof( struct V_296 ) , V_9 ) ;
if ( V_297 == NULL ) {
F_14 ( V_5 , V_43 , 0 , 0 , L_79 ) ;
return - V_10 ;
}
F_4 ( & V_5 -> V_153 ) ;
if ( ( V_5 -> V_100 == TRUE ) ||
( V_5 -> V_101 == TRUE ) ||
( V_5 -> V_102 == TRUE ) ) {
F_14 ( V_5 , V_33 , V_34 , V_35 , L_57 ) ;
F_5 ( & V_5 -> V_153 ) ;
F_11 ( V_297 ) ;
return - V_38 ;
}
F_72 ( V_5 , V_297 ) ;
F_5 ( & V_5 -> V_153 ) ;
if ( F_16 ( V_54 . V_84 , V_297 , sizeof( struct V_296 ) ) ) {
F_11 ( V_297 ) ;
return - V_44 ;
}
F_11 ( V_297 ) ;
}
break;
case V_298 : {
enum V_299 V_300 = 0 ;
F_14 ( V_5 , V_33 , V_34 , V_35 , L_80 ) ;
if ( F_58 ( V_5 ) != TRUE ) {
F_14 ( V_5 , V_43 , 0 , 0 , L_65 ) ;
return - V_79 ;
}
V_50 = F_25 ( & V_54 , V_49 , sizeof( struct V_53 ) ) ;
if ( V_50 ) {
F_14 ( V_5 , V_43 , 0 , 0 , L_81 ) ;
return - V_44 ;
}
V_50 = F_25 ( & V_300 , V_54 . V_80 , sizeof( INT ) ) ;
if ( V_50 ) {
F_14 ( V_5 , V_43 , 0 , 0 , L_82 ) ;
return - V_44 ;
}
F_4 ( & V_5 -> V_153 ) ;
if ( ( V_5 -> V_100 == TRUE ) ||
( V_5 -> V_101 == TRUE ) ||
( V_5 -> V_102 == TRUE ) ) {
F_14 ( V_5 , V_33 , V_34 , V_35 , L_57 ) ;
F_5 ( & V_5 -> V_153 ) ;
return - V_38 ;
}
V_50 = F_73 ( V_5 , V_300 ) ;
if ( V_50 )
F_14 ( V_5 , V_43 , 0 , 0 , L_83 , V_50 ) ;
F_5 ( & V_5 -> V_153 ) ;
}
break;
case V_301 : {
V_5 -> V_290 = false ;
F_14 ( V_5 , V_33 , V_34 , V_35 , L_84 ) ;
V_50 = V_62 ;
}
break;
case V_302 : {
struct V_303 V_304 = { 0 } ;
V_50 = V_62 ;
F_14 ( V_5 , V_33 , V_34 , V_35 , L_85 ) ;
V_5 -> V_290 = false ;
if ( F_58 ( V_5 ) != TRUE ) {
F_14 ( V_5 , V_43 , 0 , 0 , L_65 ) ;
return - V_79 ;
}
V_50 = F_25 ( & V_54 , V_49 , sizeof( struct V_53 ) ) ;
if ( V_50 ) {
F_14 ( V_5 , V_43 , 0 , 0 , L_86 , V_50 ) ;
return - V_44 ;
}
V_50 = F_25 ( & V_304 , V_54 . V_80 , sizeof( struct V_303 ) ) ;
if ( V_50 ) {
F_14 ( V_5 , V_43 , 0 , 0 , L_87 , V_50 ) ;
return - V_44 ;
}
F_14 ( V_5 , V_33 , V_34 , V_35 , L_88 , V_304 . V_305 ) ;
F_14 ( V_5 , V_33 , V_34 , V_35 , L_89 , V_304 . V_306 ) ;
F_14 ( V_5 , V_33 , V_34 , V_35 , L_90 , V_304 . V_282 ) ;
F_14 ( V_5 , V_33 , V_34 , V_35 , L_91 , V_304 . V_283 ) ;
if ( F_74 ( V_5 , V_304 . V_305 ) == false ) {
F_14 ( V_5 , V_43 , 0 , 0 , L_92 , V_304 . V_305 ) ;
return - V_79 ;
}
if ( F_74 ( V_5 , V_304 . V_306 ) == false ) {
F_14 ( V_5 , V_43 , 0 , 0 , L_93 , V_304 . V_306 ) ;
return - V_79 ;
}
if ( V_304 . V_305 == V_304 . V_306 ) {
F_14 ( V_5 , V_33 , V_34 , V_35 , L_94 ) ;
return - V_79 ;
}
F_4 ( & V_5 -> V_153 ) ;
if ( ( V_5 -> V_100 == TRUE ) ||
( V_5 -> V_101 == TRUE ) ||
( V_5 -> V_102 == TRUE ) ) {
F_14 ( V_5 , V_33 , V_34 , V_35 , L_57 ) ;
F_5 ( & V_5 -> V_153 ) ;
return - V_38 ;
}
if ( V_304 . V_305 == V_307 || V_304 . V_305 == V_308 ) {
if ( F_75 ( V_5 ) ) {
F_14 ( V_5 , V_43 , 0 , 0 , L_95 ) ;
V_50 = - V_79 ;
} else if ( V_304 . V_283 == 0 ) {
V_50 = F_76 ( V_5 , V_304 ) ;
} else {
F_14 ( V_5 , V_43 , 0 , 0 , L_96 ) ;
V_50 = V_51 ;
}
F_5 ( & V_5 -> V_153 ) ;
return V_50 ;
}
V_50 = F_77 ( V_5 , V_304 . V_305 ,
V_304 . V_306 , V_304 . V_282 , V_304 . V_283 ) ;
F_5 ( & V_5 -> V_153 ) ;
}
break;
case V_309 : {
V_50 = V_62 ;
F_14 ( V_5 , V_33 , V_34 , V_35 , L_97 ) ;
V_50 = F_25 ( & V_54 , V_49 , sizeof( struct V_53 ) ) ;
if ( V_50 ) {
F_14 ( V_5 , V_43 , 0 , 0 , L_81 ) ;
return - V_44 ;
}
if ( V_5 -> V_234 != V_236 ) {
F_14 ( V_5 , V_43 , 0 , 0 , L_98 ) ;
V_50 = - V_79 ;
break;
}
if ( F_58 ( V_5 ) == TRUE ) {
if ( V_54 . V_81 < sizeof( struct V_310 ) )
return - V_79 ;
if ( F_16 ( V_54 . V_84 , V_5 -> V_311 , sizeof( struct V_310 ) ) )
return - V_44 ;
} else {
if ( V_54 . V_81 < sizeof( struct V_312 ) )
return - V_79 ;
if ( F_16 ( V_54 . V_84 , V_5 -> V_313 , sizeof( struct V_312 ) ) )
return - V_44 ;
}
}
break;
case V_314 : {
T_5 V_315 = 0 ;
enum V_299 V_300 ;
V_300 = V_316 ;
F_14 ( V_5 , V_33 , V_34 , V_35 , L_99 ) ;
if ( F_58 ( V_5 ) != TRUE ) {
F_14 ( V_5 , V_43 , 0 , 0 , L_65 ) ;
return - V_79 ;
}
V_50 = F_25 ( & V_54 , V_49 , sizeof( struct V_53 ) ) ;
if ( V_50 ) {
F_14 ( V_5 , V_43 , 0 , 0 , L_81 ) ;
return - V_44 ;
}
V_50 = F_25 ( & V_300 , V_54 . V_80 , sizeof( INT ) ) ;
if ( V_50 ) {
F_14 ( V_5 , V_43 , 0 , 0 , L_82 ) ;
return - V_44 ;
}
F_14 ( V_5 , V_33 , V_34 , V_35 , L_100 , V_300 ) ;
if ( ( V_300 != V_260 ) &&
( V_300 != V_261 ) &&
( V_300 != V_262 ) ) {
F_14 ( V_5 , V_43 , 0 , 0 , L_101 , V_300 ) ;
return V_51 ;
}
V_315 = F_78 ( V_5 , V_300 ) ;
if ( V_315 == V_317 ) {
F_14 ( V_5 , V_43 , 0 , 0 , L_102 , V_300 ) ;
return - V_79 ;
}
V_5 -> V_290 = TRUE ;
V_5 -> V_318 = V_315 ;
V_5 -> V_259 = V_300 ;
}
V_50 = V_62 ;
break;
case V_319 : {
struct V_251 V_320 ;
INT V_276 ;
INT V_277 ;
INT V_279 = 0 ;
T_5 V_278 = 0 ;
T_13 V_275 ;
void T_2 * V_280 ;
if ( V_5 -> V_234 != V_236 ) {
F_14 ( V_5 , V_43 , 0 , 0 , L_103 ) ;
return - V_79 ;
}
if ( F_25 ( & V_54 , V_49 , sizeof( struct V_53 ) ) ) {
F_14 ( V_5 , V_43 , 0 , 0 , L_104 ) ;
return - V_44 ;
}
if ( F_25 ( & V_320 , V_54 . V_84 , sizeof( struct V_251 ) ) )
return - V_44 ;
V_276 = V_320 . V_263 ;
if ( V_276 > V_321 )
V_277 = V_321 ;
else
V_277 = V_276 ;
V_279 = V_320 . V_264 ;
V_280 = V_320 . V_265 ;
V_275 = F_3 ( V_277 , V_9 ) ;
if ( V_275 == NULL ) {
F_14 ( V_5 , V_43 , 0 , 0 , L_71 ) ;
V_50 = - V_10 ;
break;
}
F_4 ( & V_5 -> V_153 ) ;
if ( ( V_5 -> V_100 == TRUE ) ||
( V_5 -> V_101 == TRUE ) ||
( V_5 -> V_102 == TRUE ) ) {
F_14 ( V_5 , V_33 , V_34 , V_35 , L_57 ) ;
F_11 ( V_275 ) ;
F_5 ( & V_5 -> V_153 ) ;
return - V_38 ;
}
V_5 -> V_322 = TRUE ;
while ( V_276 ) {
if ( V_276 > V_321 )
V_278 = V_321 ;
else
V_278 = V_276 ;
V_50 = F_63 ( V_5 , ( V_83 ) V_275 , V_279 , V_278 ) ;
if ( V_50 ) {
F_14 ( V_5 , V_43 , 0 , 0 , L_72 , V_50 ) ;
break;
}
F_70 ( V_5 , V_33 , V_34 , V_35 , V_275 , V_278 ) ;
V_50 = F_16 ( V_280 , V_275 , V_278 ) ;
if ( V_50 ) {
F_14 ( V_5 , V_43 , 0 , 0 , L_73 , V_50 ) ;
F_5 ( & V_5 -> V_153 ) ;
F_11 ( V_275 ) ;
return - V_44 ;
}
V_276 = V_276 - V_278 ;
if ( V_276 ) {
V_279 = V_279 + V_278 ;
V_280 = V_280 + V_278 ;
}
}
V_5 -> V_322 = false ;
F_5 ( & V_5 -> V_153 ) ;
F_11 ( V_275 ) ;
break;
}
case V_323 : {
T_6 V_11 = 0 ;
V_50 = F_25 ( & V_54 , V_49 , sizeof( struct V_53 ) ) ;
if ( V_50 ) {
F_14 ( V_5 , V_33 , V_34 , V_35 , L_105 ) ;
return - V_44 ;
}
if ( V_54 . V_78 != sizeof( unsigned long ) ) {
V_50 = - V_79 ;
break;
}
V_50 = F_25 ( & V_11 , V_54 . V_80 , V_54 . V_78 ) ;
if ( V_50 ) {
F_14 ( V_5 , V_33 , V_34 , V_35 , L_106 ) ;
return - V_44 ;
}
F_14 ( V_5 , V_33 , V_34 , V_35 , L_107 , V_11 ) ;
V_7 -> V_11 = V_11 ;
}
break;
case V_324 : {
struct V_325 V_326 ;
F_14 ( V_5 , V_33 , V_34 , V_35 , L_108 ) ;
memset ( & V_326 , 0 , sizeof( V_326 ) ) ;
V_326 . V_327 = V_328 ;
V_326 . V_329 = V_330 ;
V_326 . V_331 = 0 ;
V_326 . V_332 = V_5 -> V_234 ;
V_326 . V_333 = V_334 ;
if ( F_25 ( & V_54 , V_49 , sizeof( struct V_53 ) ) )
return - V_44 ;
if ( V_54 . V_81 < sizeof( V_326 ) )
return - V_79 ;
if ( F_16 ( V_54 . V_84 , & V_326 , sizeof( V_326 ) ) )
return - V_44 ;
}
break;
case V_335 : {
struct V_336 V_337 = { 0 } ;
F_14 ( V_5 , V_33 , V_34 , V_35 , L_109 ) ;
if ( F_25 ( & V_54 , V_49 , sizeof( struct V_53 ) ) )
return - V_44 ;
if ( V_54 . V_81 < sizeof( struct V_336 ) )
return - V_79 ;
V_337 . V_338 = F_79 () - V_5 -> V_339 ;
if ( F_16 ( V_54 . V_84 , & V_337 , sizeof( struct V_336 ) ) )
return - V_44 ;
}
break;
case V_340 :
F_14 ( V_5 , V_33 , V_34 , V_35 , L_110 ) ;
break;
default:
F_80 ( V_341 L_111 , V_47 ) ;
V_50 = V_51 ;
break;
}
return V_50 ;
}
int F_81 ( struct V_4 * V_5 )
{
if ( V_5 -> V_342 > 0 )
return V_5 -> V_342 ;
V_5 -> V_342 = F_82 ( 0 , V_343 , & V_344 ) ;
if ( V_5 -> V_342 < 0 ) {
F_42 ( V_341 L_112 ) ;
return V_5 -> V_342 ;
}
V_5 -> V_345 = F_83 ( V_346 , NULL ,
F_84 ( V_5 -> V_342 , 0 ) ,
V_5 , V_343 ) ;
if ( F_34 ( V_5 -> V_345 ) ) {
F_42 ( V_341 L_113 ) ;
F_85 ( V_5 -> V_342 , V_343 ) ;
return F_35 ( V_5 -> V_345 ) ;
}
return 0 ;
}
void F_86 ( struct V_4 * V_5 )
{
if ( V_5 -> V_342 > 0 ) {
F_87 ( V_346 , F_84 ( V_5 -> V_342 , 0 ) ) ;
F_85 ( V_5 -> V_342 , V_343 ) ;
}
}
