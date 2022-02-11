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
if ( V_7 == NULL ) {
F_9 ( V_5 , V_22 , 0 , 0 ,
L_1 ) ;
return 0 ;
}
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
V_20 = V_7 -> V_23 ;
while ( V_20 ) {
V_21 = V_20 -> V_13 ;
F_10 ( V_20 ) ;
V_20 = V_21 ;
}
F_5 ( & V_5 -> V_12 ) ;
F_11 ( & V_5 -> V_16 ) ;
F_12 ( V_7 ) ;
V_3 -> V_15 = NULL ;
return 0 ;
}
static T_1 F_13 ( struct V_2 * V_3 , char T_2 * V_24 , T_3 V_25 ,
T_4 * V_26 )
{
struct V_6 * V_7 = V_3 -> V_15 ;
struct V_4 * V_5 = V_7 -> V_5 ;
struct V_19 * V_27 = NULL ;
T_1 V_28 = 0 ;
int V_29 = 0 ;
unsigned long V_30 = 0 ;
V_29 = F_14 ( V_5 -> V_31 ,
( V_7 -> V_23 ||
V_5 -> V_32 ) ) ;
if ( ( V_29 == - V_33 ) ) {
F_9 ( V_5 , V_34 , V_35 , V_36 ,
L_2 ) ;
return V_29 ;
}
if ( V_5 -> V_32 ) {
F_9 ( V_5 , V_34 , V_35 , V_36 ,
L_3 ) ;
return - V_37 ;
}
if ( FALSE == V_5 -> V_38 )
return - V_39 ;
F_4 ( & V_5 -> V_12 ) ;
if ( V_7 -> V_23 ) {
V_27 = V_7 -> V_23 ;
F_15 ( V_7 -> V_23 ,
V_7 -> V_40 ) ;
V_7 -> V_41 -- ;
}
F_5 ( & V_5 -> V_12 ) ;
if ( V_27 ) {
V_28 = V_27 -> V_42 ;
V_30 = F_16 ( V_24 , V_27 -> V_43 ,
F_17 ( T_3 , V_28 , V_25 ) ) ;
if ( V_30 ) {
F_18 ( V_27 ) ;
F_9 ( V_5 , V_22 , 0 , 0 ,
L_4 ) ;
return - V_44 ;
}
F_9 ( V_5 , V_34 , V_35 , V_36 ,
L_5 ,
V_28 , V_27 , V_45 -> V_46 ) ;
F_18 ( V_27 ) ;
}
F_9 ( V_5 , V_34 , V_35 , V_36 , L_6 ) ;
return V_28 ;
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
F_9 ( V_5 , V_34 , V_35 , V_36 , L_7 , V_47 , V_48 ) ;
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
if ( V_5 -> V_32 )
return - V_44 ;
if ( FALSE == V_5 -> V_38 ) {
switch ( V_47 ) {
case V_63 :
case V_64 :
case V_65 :
case V_66 :
case V_67 :
case V_68 :
case V_69 :
case V_70 :
return - V_39 ;
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
F_12 ( V_75 ) ;
return - V_44 ;
}
} else {
V_50 = V_55 ;
}
F_12 ( V_75 ) ;
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
F_9 ( V_5 , V_22 , 0 , 0 , L_8 ) ;
return - V_44 ;
}
V_50 = F_28 ( V_5 , ( T_5 ) V_87 . Register ,
( V_83 ) V_87 . V_97 , sizeof( T_6 ) ) ;
if ( V_50 == V_62 ) {
F_9 ( V_5 , V_34 , V_35 , V_36 , L_9 ) ;
} else {
F_9 ( V_5 , V_34 , V_35 , V_36 , L_10 ) ;
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
F_9 ( V_5 , V_22 , 0 , 0 , L_11 ) ;
return - V_39 ;
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
F_9 ( V_5 , V_22 , 0 , 0 , L_12 ,
( int ) V_74 . Register ) ;
F_12 ( V_75 ) ;
return - V_79 ;
}
V_88 = V_74 . Register & V_89 ;
V_55 = F_29 ( V_5 , ( T_5 ) V_74 . Register , ( V_83 ) V_75 , V_54 . V_81 ) ;
if ( V_55 > 0 ) {
V_50 = V_62 ;
if ( F_16 ( V_54 . V_84 , V_75 , V_55 ) ) {
F_12 ( V_75 ) ;
return - V_44 ;
}
} else {
V_50 = V_55 ;
}
F_12 ( V_75 ) ;
break;
}
case V_103 :
case V_104 : {
struct V_86 V_87 = { 0 } ;
T_5 V_88 = 0 ;
if ( ( V_5 -> V_100 == TRUE ) ||
( V_5 -> V_101 == TRUE ) ||
( V_5 -> V_102 == TRUE ) ) {
F_9 ( V_5 , V_22 , 0 , 0 , L_13 ) ;
return - V_39 ;
}
if ( F_25 ( & V_54 , V_49 , sizeof( struct V_53 ) ) )
return - V_44 ;
if ( V_54 . V_78 > sizeof( V_87 ) )
return - V_79 ;
if ( F_25 ( & V_87 , V_54 . V_80 , V_54 . V_78 ) )
return - V_44 ;
if ( ( ( ( T_6 ) V_87 . Register & 0x0F000000 ) != 0x0F000000 ) ||
( ( T_6 ) V_87 . Register & 0x3 ) ) {
F_9 ( V_5 , V_22 , 0 , 0 , L_14 , ( int ) V_87 . Register ) ;
return - V_79 ;
}
V_88 = V_87 . Register & V_89 ;
if ( ! ( ( V_5 -> V_90 -> V_91 ) & V_92 ) &&
( ( V_88 == V_93 ) ||
( V_88 == V_94 ) ||
( V_88 == V_95 ) ||
( V_88 == V_96 ) ) &&
( V_47 == V_103 ) ) {
F_9 ( V_5 , V_22 , 0 , 0 , L_8 ) ;
return - V_44 ;
}
V_50 = F_30 ( V_5 , ( T_5 ) V_87 . Register ,
( V_83 ) V_87 . V_97 , V_87 . V_105 ) ;
if ( V_50 == V_62 ) {
F_9 ( V_5 , V_22 , V_35 , V_36 , L_9 ) ;
} else {
F_9 ( V_5 , V_34 , V_35 , V_36 , L_10 ) ;
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
F_9 ( V_5 , V_34 , V_35 , V_36 , L_15 ) ;
return - V_39 ;
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
if ( F_31 ( V_5 , V_107 ) == FALSE ) {
F_9 ( V_5 , V_34 , V_35 , V_36 , L_16 , V_107 ) ;
V_50 = - V_79 ;
break;
}
if ( V_109 ) {
V_50 = F_30 ( V_5 , V_114 , ( V_83 ) ( & V_107 ) , sizeof( T_5 ) ) ;
if ( V_50 == V_62 ) {
F_9 ( V_5 , V_34 , V_35 , V_36 , L_17 ) ;
} else {
F_9 ( V_5 , V_34 , V_35 , V_36 , L_18 , V_108 ) ;
break;
}
} else {
V_50 = F_30 ( V_5 , V_115 , ( V_83 ) ( & V_107 ) , sizeof( T_5 ) ) ;
if ( V_50 == V_62 ) {
F_9 ( V_5 , V_34 , V_35 , V_36 , L_17 ) ;
} else {
F_9 ( V_5 , V_34 , V_35 , V_36 , L_19 , V_108 ) ;
break;
}
}
V_55 = F_29 ( V_5 , ( T_5 ) V_116 , ( V_83 ) V_106 , sizeof( T_5 ) ) ;
if ( V_55 < 0 ) {
V_50 = V_55 ;
F_9 ( V_5 , V_34 , V_35 , V_36 ,
L_20 ) ;
break;
} else {
V_50 = V_62 ;
}
* ( T_5 * ) V_106 |= ( 1 << V_108 ) ;
V_50 = F_30 ( V_5 , V_116 ,
( V_83 ) V_106 , sizeof( T_5 ) ) ;
if ( V_50 == V_62 ) {
F_9 ( V_5 , V_34 , V_35 , V_36 , L_21 ) ;
} else {
F_9 ( V_5 , V_34 , V_35 , V_36 , L_22 ) ;
break;
}
}
break;
case V_117 : {
struct V_118 V_119 = { 0 } ;
F_9 ( V_5 , V_34 , V_35 , V_36 , L_23 ) ;
if ( ( V_5 -> V_100 == TRUE ) ||
( V_5 -> V_101 == TRUE ) ||
( V_5 -> V_102 == TRUE ) ) {
F_9 ( V_5 , V_34 , V_35 , V_36 , L_15 ) ;
V_50 = - V_39 ;
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
F_9 ( V_5 , V_34 , V_35 , V_36 , L_24 ) ;
V_5 -> V_124 = V_125 ;
} else {
F_9 ( V_5 , V_34 , V_35 , V_36 , L_25 ) ;
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
return - V_39 ;
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
F_9 ( V_5 , V_22 , 0 , 0 , L_26 ) ;
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
if ( F_31 ( V_5 , V_134 [ V_135 ] . V_136 ) == FALSE ) {
F_9 ( V_5 , V_34 , V_35 , V_36 ,
L_27 ,
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
F_9 ( V_5 , V_22 , 0 , 0 , L_28 ) ;
return V_50 ;
}
* ( T_5 * ) V_106 = ( V_134 [ V_135 ] . V_136 &
V_134 [ V_135 ] . V_138 &
( ~ ( V_134 [ V_135 ] . V_139 ) ) ) ;
if ( * ( T_5 * ) V_106 )
V_50 = F_30 ( V_5 , V_115 , ( V_83 ) V_106 , sizeof( T_6 ) ) ;
if ( V_50 != V_62 ) {
F_9 ( V_5 , V_22 , 0 , 0 , L_29 ) ;
return V_50 ;
}
}
if ( V_134 [ V_135 ] . V_136 ) {
V_55 = F_29 ( V_5 , ( T_5 ) V_129 , ( V_83 ) V_106 , sizeof( T_5 ) ) ;
if ( V_55 < 0 ) {
V_50 = V_55 ;
F_9 ( V_5 , V_22 , 0 , 0 , L_30 ) ;
return V_50 ;
} else {
V_50 = V_62 ;
}
V_134 [ V_135 ] . V_139 = ( * ( T_5 * ) V_106 &
V_134 [ V_135 ] . V_136 ) ;
}
V_50 = F_16 ( V_54 . V_84 , & V_132 , V_54 . V_81 ) ;
if ( V_50 ) {
F_9 ( V_5 , V_22 , 0 , 0 ,
L_31 , V_50 ) ;
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
F_9 ( V_5 , V_22 , 0 , 0 , L_32 ) ;
return V_50 ;
} else {
V_50 = V_62 ;
}
if ( F_31 ( V_5 , V_143 [ V_135 ] . V_136 ) == FALSE ) {
F_9 ( V_5 , V_34 , V_35 , V_36 ,
L_27 ,
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
F_9 ( V_5 , V_34 , V_35 , V_36 ,
L_33 ) ;
} else {
F_9 ( V_5 , V_22 , 0 , 0 ,
L_34 ) ;
V_50 = - V_44 ;
break;
}
} else {
V_143 [ V_135 ] . V_144 = * ( T_5 * ) V_106 ;
}
V_50 = F_16 ( V_54 . V_84 , & V_142 , V_54 . V_81 ) ;
if ( V_50 ) {
F_9 ( V_5 , V_22 , 0 , 0 ,
L_31 , V_50 ) ;
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
if ( V_50 == - V_33 )
goto V_151;
if ( V_5 -> V_102 ) {
F_9 ( V_5 , V_34 , V_35 , V_36 ,
L_35 ) ;
V_50 = V_51 ;
goto V_151;
}
V_50 = F_37 ( V_5 , ( T_10 ) V_145 ) ;
V_151:
F_5 ( & V_5 -> V_148 ) ;
F_12 ( V_145 ) ;
break;
}
case V_152 : {
if ( F_38 ( & V_5 -> V_153 ) ) {
F_9 ( V_5 , V_34 , V_35 , V_36 ,
L_36 ) ;
return - V_39 ;
}
F_9 ( V_5 , V_22 , 0 , 0 ,
L_37 , V_45 -> V_46 ) ;
if ( F_38 ( & V_5 -> V_154 ) )
return - V_155 ;
V_5 -> V_156 = FALSE ;
V_5 -> V_157 = V_45 -> V_46 ;
V_5 -> V_158 = FALSE ;
V_5 -> V_38 = FALSE ;
F_39 ( V_5 -> V_159 ) ;
F_40 ( V_5 -> V_159 ) ;
V_50 = F_41 ( V_5 ) ;
if ( V_50 ) {
F_42 ( V_160 L_38 , V_5 -> V_159 -> V_161 ) ;
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
F_9 ( V_5 , V_22 , 0 , 0 , L_37 , V_45 -> V_46 ) ;
if ( ! F_38 ( & V_5 -> V_154 ) ) {
F_9 ( V_5 , V_22 , 0 , 0 ,
L_39 ) ;
F_5 ( & V_5 -> V_154 ) ;
V_50 = - V_79 ;
return V_50 ;
}
if ( F_25 ( & V_54 , V_49 , sizeof( struct V_53 ) ) ) {
F_5 ( & V_5 -> V_154 ) ;
return - V_44 ;
}
F_9 ( V_5 , V_22 , 0 , 0 ,
L_40 , V_54 . V_78 ) ;
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
F_12 ( V_164 ) ;
return - V_44 ;
}
if ( ! V_164 -> V_165 ||
( V_164 -> V_166 == 0 ) ) {
F_9 ( V_5 , V_22 , 0 , 0 , L_41 ,
V_164 -> V_166 ) ;
F_5 ( & V_5 -> V_154 ) ;
F_12 ( V_164 ) ;
V_50 = - V_79 ;
return V_50 ;
}
V_50 = F_44 ( V_5 , V_164 ) ;
if ( V_50 != V_62 ) {
if ( V_164 -> V_167 == V_168 )
F_9 ( V_5 , V_22 , 0 , 0 , L_42 ) ;
else
F_9 ( V_5 , V_22 , 0 , 0 , L_43 ) ;
if ( V_5 -> V_120 . V_121 & V_169 ) {
V_5 -> V_124 = V_170 ;
V_5 -> V_120 . V_171 = FALSE ;
F_32 ( & V_5 -> V_120 . V_127 ) ;
}
}
if ( V_50 != V_62 )
F_5 ( & V_5 -> V_154 ) ;
F_9 ( V_5 , V_22 , V_35 , V_36 , L_44 ) ;
F_12 ( V_164 ) ;
return V_50 ;
}
case V_172 : {
if ( ! F_38 ( & V_5 -> V_154 ) ) {
F_5 ( & V_5 -> V_154 ) ;
return - V_79 ;
}
if ( F_38 ( & V_5 -> V_153 ) ) {
F_9 ( V_5 , V_22 , 0 , 0 ,
L_45 ) ;
F_5 ( & V_5 -> V_154 ) ;
return - V_39 ;
}
V_5 -> V_156 = TRUE ;
V_5 -> V_158 = TRUE ;
F_45 ( & V_5 -> V_173 , 0 ) ;
V_5 -> V_174 = 0 ;
V_5 -> V_175 = 0 ;
V_50 = F_46 ( V_5 ) ;
if ( V_50 ) {
F_9 ( V_5 , V_22 , 0 , 0 , L_46 ) ;
F_5 ( & V_5 -> V_154 ) ;
F_5 ( & V_5 -> V_153 ) ;
return V_50 ;
} else {
F_9 ( V_5 , V_34 , V_35 ,
V_36 , L_47 ) ;
}
F_43 ( 10 ) ;
if ( F_47 ( (struct V_176 * ) V_5 -> V_177 ) )
F_9 ( V_5 , V_22 , 0 , 0 , L_48 ) ;
V_52 = 5 * V_150 ;
V_5 -> V_178 = FALSE ;
F_48 ( V_5 -> V_179 ,
V_5 -> V_178 , V_52 ) ;
V_5 -> V_157 = V_180 ;
V_5 -> V_38 = TRUE ;
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
V_50 = - V_37 ;
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
F_9 ( V_5 , V_22 , 0 , 0 , L_49 ) ;
return - V_39 ;
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
F_9 ( V_5 , V_34 , V_35 , V_36 , L_50 ) ;
V_5 -> V_203 = V_204 ;
} else {
F_9 ( V_5 , V_34 , V_35 , V_36 , L_51 ) ;
V_5 -> V_203 = V_205 ;
}
V_50 = V_62 ;
break;
}
case V_206 : {
T_12 V_42 ;
if ( F_25 ( & V_54 , V_49 , sizeof( struct V_53 ) ) )
return - V_44 ;
V_42 = F_17 ( T_12 , V_54 . V_81 , strlen ( V_207 ) + 1 ) ;
if ( F_16 ( V_54 . V_84 , V_207 , V_42 ) )
return - V_44 ;
V_50 = V_62 ;
break;
}
case V_208 : {
T_13 V_209 ;
if ( F_25 ( & V_54 , V_49 , sizeof( struct V_53 ) ) ) {
F_9 ( V_5 , V_22 , 0 , 0 , L_52 ) ;
return - V_44 ;
}
if ( V_54 . V_81 != sizeof( V_209 ) ) {
V_50 = - V_79 ;
break;
}
memset ( & V_209 , 0 , sizeof( V_209 ) ) ;
V_209 . V_210 = V_5 -> V_100 ;
V_209 . V_211 = V_5 -> V_101 ;
V_209 . V_212 = V_5 -> V_184 ;
if ( F_16 ( V_54 . V_84 , & V_209 , F_17 ( T_3 , sizeof( V_209 ) , V_54 . V_81 ) ) ) {
F_9 ( V_5 , V_22 , 0 , 0 , L_53 ) ;
return - V_44 ;
}
V_50 = V_62 ;
break;
}
case V_213 : {
T_5 V_214 ;
if ( F_25 ( & V_54 , V_49 , sizeof( struct V_53 ) ) )
return - V_44 ;
if ( F_25 ( & V_214 , V_54 . V_80 , sizeof( T_5 ) ) )
return - V_44 ;
if ( V_214 )
V_5 -> V_14 -> V_215 = TRUE ;
else
V_5 -> V_14 -> V_215 = FALSE ;
break;
}
case V_216 : {
T_6 V_217 = 0 ;
if ( F_25 ( & V_54 , V_49 , sizeof( struct V_53 ) ) )
return - V_44 ;
if ( V_54 . V_81 < sizeof( struct V_218 ) ) {
F_9 ( V_5 , V_22 , 0 , 0 ,
L_54 ,
V_54 . V_81 , sizeof( struct V_218 ) ) ;
return - V_79 ;
}
if ( F_25 ( & V_217 , V_54 . V_80 , sizeof( V_217 ) ) )
return - V_44 ;
F_9 ( V_5 , V_34 , V_35 , V_36 , L_55 , V_217 ) ;
F_54 ( V_5 , V_217 , V_54 . V_84 ) ;
V_50 = V_62 ;
}
break;
case V_219 : {
T_10 V_75 ;
if ( F_25 ( & V_54 , V_49 , sizeof( struct V_53 ) ) )
return - V_44 ;
if ( V_54 . V_81 != sizeof( struct V_220 ) ) {
F_9 ( V_5 , V_22 , 0 , 0 ,
L_56 ,
V_54 . V_81 , sizeof( struct V_220 ) ) ;
return - V_79 ;
}
V_75 = F_3 ( sizeof( struct V_220 ) , V_9 ) ;
if ( ! V_75 )
return V_51 ;
V_50 = F_55 ( V_5 , V_75 ) ;
F_56 ( V_75 , V_7 ) ;
if ( V_50 != V_51 )
if ( F_16 ( V_54 . V_84 , V_75 , sizeof( struct V_220 ) ) ) {
F_12 ( V_75 ) ;
return - V_44 ;
}
F_12 ( V_75 ) ;
break;
}
case V_221 :
if ( ( FALSE == V_5 -> V_222 ) && ( TRUE == V_5 -> V_100 ) ) {
V_5 -> V_223 = V_224 ;
V_5 -> V_225 = TRUE ;
F_32 ( & V_5 -> V_226 ) ;
}
V_50 = V_62 ;
break;
case V_227 : {
struct V_228 * V_229 ;
T_5 V_88 = 0 ;
T_7 V_145 = NULL ;
if ( ( V_5 -> V_100 == TRUE ) ||
( V_5 -> V_101 == TRUE ) ||
( V_5 -> V_102 == TRUE ) ) {
F_9 ( V_5 , V_22 , 0 , 0 , L_57 ) ;
V_50 = - V_39 ;
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
V_229 = (struct V_228 * ) V_145 ;
if ( ( ( T_6 ) V_229 -> Register & 0x0F000000 ) != 0x0F000000 ||
( ( T_6 ) V_229 -> Register & 0x3 ) ) {
F_12 ( V_145 ) ;
F_9 ( V_5 , V_22 , 0 , 0 , L_14 , ( int ) V_229 -> Register ) ;
V_50 = - V_79 ;
break;
}
V_88 = V_229 -> Register & V_89 ;
if ( ! ( ( V_5 -> V_90 -> V_91 ) & V_92 ) &&
( ( V_88 == V_93 ) ||
( V_88 == V_94 ) ||
( V_88 == V_95 ) ||
( V_88 == V_96 ) ) &&
( V_47 == V_103 ) ) {
F_12 ( V_145 ) ;
F_9 ( V_5 , V_22 , 0 , 0 , L_8 ) ;
V_50 = - V_44 ;
break;
}
if ( V_229 -> V_230 == FALSE )
V_50 = F_57 ( V_5 , ( T_5 ) V_229 -> Register , ( T_7 ) V_229 -> V_231 , V_54 . V_78 - 2 * sizeof( T_6 ) ) ;
else
V_50 = F_30 ( V_5 , ( T_5 ) V_229 -> Register , ( V_83 ) V_229 -> V_231 , V_54 . V_78 - 2 * sizeof( T_6 ) ) ;
if ( V_50 != V_62 )
F_9 ( V_5 , V_22 , 0 , 0 , L_10 ) ;
F_12 ( V_145 ) ;
break;
}
case V_232 :
if ( F_25 ( & V_54 , V_49 , sizeof( struct V_53 ) ) )
return - V_44 ;
if ( V_5 -> V_233 == V_234 || V_5 -> V_233 == V_235 ) {
if ( F_16 ( V_54 . V_84 , & V_5 -> V_236 , sizeof( T_5 ) ) )
return - V_44 ;
}
V_50 = V_62 ;
break;
case V_237 : {
T_5 V_238 = 0 ;
if ( V_5 -> V_233 == V_235 ) {
if ( F_25 ( & V_54 , V_49 , sizeof( struct V_53 ) ) )
return - V_44 ;
if ( F_25 ( & V_238 , V_54 . V_80 , sizeof( T_5 ) ) )
return - V_44 ;
if ( ( V_238 < V_239 ) || ( V_238 > V_240 ) ) {
if ( F_16 ( V_54 . V_84 , & V_5 -> V_238 ,
sizeof( T_5 ) ) )
return - V_44 ;
} else {
if ( F_58 ( V_5 ) ) {
if ( F_16 ( V_54 . V_84 , & V_5 -> V_238 , sizeof( T_5 ) ) )
return - V_44 ;
} else {
if ( ( TRUE == V_5 -> V_101 ) || ( TRUE == V_5 -> V_100 ) ) {
F_9 ( V_5 , V_22 , 0 , 0 , L_58 ) ;
return - V_39 ;
}
V_5 -> V_238 = V_238 ;
F_59 ( V_5 , V_5 -> V_238 ) ;
}
}
V_50 = V_62 ;
} else {
V_50 = V_51 ;
}
}
break;
case V_241 :
#ifdef F_60
{
T_14 V_242 ;
F_9 ( V_5 , V_34 , V_35 , V_36 , L_59 ) ;
if ( F_25 ( & V_54 , V_49 , sizeof( struct V_53 ) ) )
return - V_44 ;
if ( F_25 ( & V_242 , V_54 . V_80 , sizeof( T_14 ) ) )
return - V_44 ;
F_9 ( V_5 , V_22 , 0 , 0 , L_60 ,
V_242 . V_243 , V_242 . Type ) ;
V_242 . V_244 = 1 << V_242 . V_244 ;
F_9 ( V_5 , V_22 , 0 , 0 , L_61 , V_242 . V_244 ) ;
V_5 -> V_245 . type |= V_242 . Type ;
if ( V_242 . V_243 )
V_5 -> V_245 . V_246 [ V_242 . Type ] |= V_242 . V_244 ;
else
V_5 -> V_245 . V_246 [ V_242 . Type ] &= ~ V_242 . V_244 ;
F_61 ( V_5 ) ;
}
#endif
break;
case V_247 :
case V_248 : {
struct V_249 V_250 ;
T_15 V_251 = NULL ;
T_6 V_252 = 0 ;
struct V_253 V_254 , V_255 ;
memset ( & V_254 , 0 , sizeof( struct V_253 ) ) ;
memset ( & V_255 , 0 , sizeof( struct V_253 ) ) ;
if ( ( V_5 -> V_233 == V_235 ) && ( V_5 -> V_256 == 0 ) ) {
F_9 ( V_5 , V_22 , 0 , 0 , L_62 ) ;
return - V_44 ;
}
if ( F_58 ( V_5 ) ) {
if ( ( V_5 -> V_257 != V_258 ) &&
( V_5 -> V_257 != V_259 ) &&
( V_5 -> V_257 != V_260 ) ) {
F_9 ( V_5 , V_22 , 0 , 0 , L_63 ) ;
return V_51 ;
}
}
if ( F_25 ( & V_54 , V_49 , sizeof( struct V_53 ) ) )
return - V_44 ;
if ( F_25 ( & V_250 ,
( V_247 == V_47 ) ? V_54 . V_84 : V_54 . V_80 ,
sizeof( struct V_249 ) ) )
return - V_44 ;
if ( V_250 . V_261 > V_5 -> V_236 )
return V_51 ;
if ( V_250 . V_262 > V_5 -> V_236 - V_250 . V_261 ) {
return V_51 ;
}
V_251 = F_33 ( V_250 . V_263 ,
V_250 . V_261 ) ;
if ( F_34 ( V_251 ) )
return F_35 ( V_251 ) ;
F_62 ( & V_254 ) ;
if ( V_247 == V_47 ) {
F_4 ( & V_5 -> V_153 ) ;
if ( ( V_5 -> V_100 == TRUE ) ||
( V_5 -> V_101 == TRUE ) ||
( V_5 -> V_102 == TRUE ) ) {
F_9 ( V_5 , V_34 , V_35 , V_36 , L_58 ) ;
F_5 ( & V_5 -> V_153 ) ;
F_12 ( V_251 ) ;
return - V_39 ;
}
V_50 = F_63 ( V_5 , ( V_83 ) V_251 , V_250 . V_262 , V_250 . V_261 ) ;
F_5 ( & V_5 -> V_153 ) ;
if ( V_50 != V_62 ) {
F_12 ( V_251 ) ;
return V_50 ;
}
if ( F_16 ( V_250 . V_263 , V_251 , V_250 . V_261 ) ) {
F_12 ( V_251 ) ;
return - V_44 ;
}
} else {
F_4 ( & V_5 -> V_153 ) ;
if ( ( V_5 -> V_100 == TRUE ) ||
( V_5 -> V_101 == TRUE ) ||
( V_5 -> V_102 == TRUE ) ) {
F_9 ( V_5 , V_34 , V_35 , V_36 , L_58 ) ;
F_5 ( & V_5 -> V_153 ) ;
F_12 ( V_251 ) ;
return - V_39 ;
}
V_5 -> V_264 = TRUE ;
if ( F_58 ( V_5 ) ) {
V_50 = F_64 ( V_5 , V_5 -> V_257 ) ;
if ( V_50 != V_62 ) {
if ( ( ( V_250 . V_262 + V_250 . V_261 ) != V_5 -> V_236 ) ||
( V_250 . V_261 < V_265 ) ) {
F_9 ( V_5 , V_34 , V_35 , V_36 , L_64 ) ;
F_5 ( & V_5 -> V_153 ) ;
F_12 ( V_251 ) ;
return V_50 ;
}
V_252 = F_65 ( * ( V_83 ) ( V_251 + V_250 . V_261 - V_265 ) ) ;
if ( V_252 != V_266 ) {
F_9 ( V_5 , V_34 , V_35 , V_36 , L_64 ) ;
F_5 ( & V_5 -> V_153 ) ;
F_12 ( V_251 ) ;
return V_50 ;
}
}
}
V_50 = F_66 ( V_5 , ( V_83 ) V_251 , V_250 . V_262 , V_250 . V_261 , V_250 . V_267 ) ;
if ( F_58 ( V_5 ) )
F_67 ( V_5 , V_5 -> V_257 ) ;
V_5 -> V_264 = FALSE ;
F_5 ( & V_5 -> V_153 ) ;
if ( V_50 != V_62 ) {
F_12 ( V_251 ) ;
return V_50 ;
}
}
F_62 ( & V_255 ) ;
F_9 ( V_5 , V_34 , V_35 , V_36 , L_65 , ( V_255 . V_268 - V_254 . V_268 ) * 1000 + ( V_255 . V_269 - V_254 . V_269 ) / 1000 ) ;
F_12 ( V_251 ) ;
return V_62 ;
}
case V_270 : {
struct V_271 V_272 = { 0 } ;
T_15 V_273 = NULL ;
T_5 V_274 = 0 ;
T_5 V_275 = 0 ;
T_5 V_276 = 0 ;
T_5 V_277 = 0 ;
void T_2 * V_278 ;
if ( F_58 ( V_5 ) != TRUE ) {
F_9 ( V_5 , V_22 , 0 , 0 , L_66 ) ;
return - V_79 ;
}
F_9 ( V_5 , V_34 , V_35 , V_36 , L_67 ) ;
if ( F_25 ( & V_54 , V_49 , sizeof( struct V_53 ) ) )
return - V_44 ;
if ( F_25 ( & V_272 , V_54 . V_80 , sizeof( struct V_271 ) ) )
return - V_44 ;
F_9 ( V_5 , V_34 , V_35 , V_36 , L_68 , V_272 . V_279 ) ;
F_9 ( V_5 , V_34 , V_35 , V_36 , L_69 , V_272 . V_280 ) ;
F_9 ( V_5 , V_34 , V_35 , V_36 , L_70 , V_272 . V_281 ) ;
F_9 ( V_5 , V_34 , V_35 , V_36 , L_71 , V_272 . V_267 ) ;
if ( F_68 ( V_5 , & V_272 ) == FALSE )
return V_51 ;
V_274 = V_272 . V_281 ;
if ( V_274 > V_5 -> V_238 )
V_275 = V_5 -> V_238 ;
else
V_275 = V_274 ;
V_277 = V_272 . V_280 ;
V_278 = V_54 . V_84 ;
V_273 = ( T_7 ) F_3 ( V_275 , V_9 ) ;
if ( V_273 == NULL ) {
F_9 ( V_5 , V_22 , 0 , 0 , L_72 ) ;
return - V_10 ;
}
F_4 ( & V_5 -> V_153 ) ;
if ( ( V_5 -> V_100 == TRUE ) ||
( V_5 -> V_101 == TRUE ) ||
( V_5 -> V_102 == TRUE ) ) {
F_9 ( V_5 , V_34 , V_35 , V_36 , L_58 ) ;
F_5 ( & V_5 -> V_153 ) ;
F_12 ( V_273 ) ;
return - V_39 ;
}
while ( V_274 ) {
if ( V_274 > V_5 -> V_238 )
V_276 = V_5 -> V_238 ;
else
V_276 = V_274 ;
V_50 = F_69 ( V_5 , ( V_83 ) V_273 , V_272 . V_279 , V_277 , V_276 ) ;
if ( V_50 ) {
F_9 ( V_5 , V_34 , V_35 , V_36 , L_73 , V_50 ) ;
break;
}
F_70 ( V_5 , V_34 , V_35 , V_36 , V_273 , V_276 ) ;
V_50 = F_16 ( V_278 , V_273 , V_276 ) ;
if ( V_50 ) {
F_9 ( V_5 , V_34 , V_35 , V_36 , L_74 , V_50 ) ;
F_5 ( & V_5 -> V_153 ) ;
F_12 ( V_273 ) ;
return - V_44 ;
}
V_274 = V_274 - V_276 ;
if ( V_274 ) {
V_277 = V_277 + V_276 ;
V_278 = V_278 + V_276 ;
}
}
F_5 ( & V_5 -> V_153 ) ;
F_12 ( V_273 ) ;
}
break;
case V_282 : {
struct V_271 V_283 = { 0 } ;
T_15 V_284 ;
void T_2 * V_285 ;
T_5 V_274 = 0 ;
T_5 V_275 = 0 ;
T_5 V_286 = 0 ;
T_5 V_287 = 0 ;
if ( F_58 ( V_5 ) != TRUE ) {
F_9 ( V_5 , V_22 , 0 , 0 , L_66 ) ;
return - V_79 ;
}
V_5 -> V_288 = FALSE ;
F_9 ( V_5 , V_34 , V_35 , V_36 , L_75 ) ;
if ( F_25 ( & V_54 , V_49 , sizeof( struct V_53 ) ) )
return - V_44 ;
if ( F_25 ( & V_283 , V_54 . V_80 , sizeof( struct V_271 ) ) )
return - V_44 ;
F_9 ( V_5 , V_34 , V_35 , V_36 , L_68 , V_283 . V_279 ) ;
F_9 ( V_5 , V_34 , V_35 , V_36 , L_76 , V_283 . V_280 ) ;
F_9 ( V_5 , V_34 , V_35 , V_36 , L_70 , V_283 . V_281 ) ;
F_9 ( V_5 , V_34 , V_35 , V_36 , L_71 , V_283 . V_267 ) ;
if ( ( V_283 . V_279 != V_289 ) && ( V_283 . V_279 != V_290 ) && ( V_283 . V_279 != V_291 ) ) {
F_9 ( V_5 , V_34 , V_35 , V_36 , L_77 ) ;
return - V_79 ;
}
if ( F_68 ( V_5 , & V_283 ) == FALSE )
return V_51 ;
V_285 = V_283 . V_292 ;
V_286 = V_283 . V_280 ;
V_274 = V_283 . V_281 ;
if ( V_274 > V_5 -> V_238 )
V_275 = V_5 -> V_238 ;
else
V_275 = V_274 ;
V_284 = F_26 ( V_275 , V_9 ) ;
if ( V_284 == NULL )
return - V_10 ;
V_287 = V_5 -> V_238 ;
if ( V_286 % V_5 -> V_238 )
V_287 = V_5 -> V_238 - ( V_286 % V_5 -> V_238 ) ;
if ( V_274 < V_287 )
V_287 = V_274 ;
F_4 ( & V_5 -> V_153 ) ;
if ( ( V_5 -> V_100 == TRUE ) ||
( V_5 -> V_101 == TRUE ) ||
( V_5 -> V_102 == TRUE ) ) {
F_9 ( V_5 , V_34 , V_35 , V_36 , L_58 ) ;
F_5 ( & V_5 -> V_153 ) ;
F_12 ( V_284 ) ;
return - V_39 ;
}
F_64 ( V_5 , V_283 . V_279 ) ;
do {
V_50 = F_25 ( V_284 , V_285 , V_287 ) ;
if ( V_50 ) {
F_9 ( V_5 , V_22 , 0 , 0 , L_78 , V_50 ) ;
F_5 ( & V_5 -> V_153 ) ;
F_12 ( V_284 ) ;
return - V_44 ;
}
F_70 ( V_5 , V_34 , V_35 , V_36 , V_284 , V_287 ) ;
V_50 = F_71 ( V_5 , ( V_83 ) V_284 , V_283 . V_279 , V_286 , V_287 , V_283 . V_267 ) ;
if ( V_50 ) {
F_9 ( V_5 , V_22 , 0 , 0 , L_73 , V_50 ) ;
break;
}
V_274 = V_274 - V_287 ;
if ( V_274 ) {
V_286 = V_286 + V_287 ;
V_285 = V_285 + V_287 ;
if ( V_274 > V_5 -> V_238 )
V_287 = V_5 -> V_238 ;
else
V_287 = V_274 ;
}
} while ( V_274 > 0 );
F_67 ( V_5 , V_283 . V_279 ) ;
F_5 ( & V_5 -> V_153 ) ;
F_12 ( V_284 ) ;
}
break;
case V_293 : {
struct V_294 * V_295 ;
F_9 ( V_5 , V_34 , V_35 , V_36 , L_79 ) ;
if ( F_25 ( & V_54 , V_49 , sizeof( struct V_53 ) ) )
return - V_44 ;
if ( V_54 . V_81 != sizeof( struct V_294 ) )
return - V_79 ;
V_295 = F_3 ( sizeof( struct V_294 ) , V_9 ) ;
if ( V_295 == NULL ) {
F_9 ( V_5 , V_22 , 0 , 0 , L_80 ) ;
return - V_10 ;
}
F_4 ( & V_5 -> V_153 ) ;
if ( ( V_5 -> V_100 == TRUE ) ||
( V_5 -> V_101 == TRUE ) ||
( V_5 -> V_102 == TRUE ) ) {
F_9 ( V_5 , V_34 , V_35 , V_36 , L_58 ) ;
F_5 ( & V_5 -> V_153 ) ;
F_12 ( V_295 ) ;
return - V_39 ;
}
F_72 ( V_5 , V_295 ) ;
F_5 ( & V_5 -> V_153 ) ;
if ( F_16 ( V_54 . V_84 , V_295 , sizeof( struct V_294 ) ) ) {
F_12 ( V_295 ) ;
return - V_44 ;
}
F_12 ( V_295 ) ;
}
break;
case V_296 : {
enum V_297 V_298 = 0 ;
F_9 ( V_5 , V_34 , V_35 , V_36 , L_81 ) ;
if ( F_58 ( V_5 ) != TRUE ) {
F_9 ( V_5 , V_22 , 0 , 0 , L_66 ) ;
return - V_79 ;
}
V_50 = F_25 ( & V_54 , V_49 , sizeof( struct V_53 ) ) ;
if ( V_50 ) {
F_9 ( V_5 , V_22 , 0 , 0 , L_82 ) ;
return - V_44 ;
}
V_50 = F_25 ( & V_298 , V_54 . V_80 , sizeof( INT ) ) ;
if ( V_50 ) {
F_9 ( V_5 , V_22 , 0 , 0 , L_83 ) ;
return - V_44 ;
}
F_4 ( & V_5 -> V_153 ) ;
if ( ( V_5 -> V_100 == TRUE ) ||
( V_5 -> V_101 == TRUE ) ||
( V_5 -> V_102 == TRUE ) ) {
F_9 ( V_5 , V_34 , V_35 , V_36 , L_58 ) ;
F_5 ( & V_5 -> V_153 ) ;
return - V_39 ;
}
V_50 = F_73 ( V_5 , V_298 ) ;
if ( V_50 )
F_9 ( V_5 , V_22 , 0 , 0 , L_84 , V_50 ) ;
F_5 ( & V_5 -> V_153 ) ;
}
break;
case V_299 : {
V_5 -> V_288 = FALSE ;
F_9 ( V_5 , V_34 , V_35 , V_36 , L_85 ) ;
V_50 = V_62 ;
}
break;
case V_300 : {
struct V_301 V_302 = { 0 } ;
V_50 = V_62 ;
F_9 ( V_5 , V_34 , V_35 , V_36 , L_86 ) ;
V_5 -> V_288 = FALSE ;
if ( F_58 ( V_5 ) != TRUE ) {
F_9 ( V_5 , V_22 , 0 , 0 , L_66 ) ;
return - V_79 ;
}
V_50 = F_25 ( & V_54 , V_49 , sizeof( struct V_53 ) ) ;
if ( V_50 ) {
F_9 ( V_5 , V_22 , 0 , 0 , L_87 , V_50 ) ;
return - V_44 ;
}
V_50 = F_25 ( & V_302 , V_54 . V_80 , sizeof( struct V_301 ) ) ;
if ( V_50 ) {
F_9 ( V_5 , V_22 , 0 , 0 , L_88 , V_50 ) ;
return - V_44 ;
}
F_9 ( V_5 , V_34 , V_35 , V_36 , L_89 , V_302 . V_303 ) ;
F_9 ( V_5 , V_34 , V_35 , V_36 , L_90 , V_302 . V_304 ) ;
F_9 ( V_5 , V_34 , V_35 , V_36 , L_91 , V_302 . V_280 ) ;
F_9 ( V_5 , V_34 , V_35 , V_36 , L_92 , V_302 . V_281 ) ;
if ( F_74 ( V_5 , V_302 . V_303 ) == FALSE ) {
F_9 ( V_5 , V_22 , 0 , 0 , L_93 , V_302 . V_303 ) ;
return - V_79 ;
}
if ( F_74 ( V_5 , V_302 . V_304 ) == FALSE ) {
F_9 ( V_5 , V_22 , 0 , 0 , L_94 , V_302 . V_304 ) ;
return - V_79 ;
}
if ( V_302 . V_303 == V_302 . V_304 ) {
F_9 ( V_5 , V_34 , V_35 , V_36 , L_95 ) ;
return - V_79 ;
}
F_4 ( & V_5 -> V_153 ) ;
if ( ( V_5 -> V_100 == TRUE ) ||
( V_5 -> V_101 == TRUE ) ||
( V_5 -> V_102 == TRUE ) ) {
F_9 ( V_5 , V_34 , V_35 , V_36 , L_58 ) ;
F_5 ( & V_5 -> V_153 ) ;
return - V_39 ;
}
if ( V_302 . V_303 == V_305 || V_302 . V_303 == V_306 ) {
if ( F_75 ( V_5 ) ) {
F_9 ( V_5 , V_22 , 0 , 0 , L_96 ) ;
V_50 = - V_79 ;
} else if ( V_302 . V_281 == 0 ) {
V_50 = F_76 ( V_5 , V_302 ) ;
} else {
F_9 ( V_5 , V_22 , 0 , 0 , L_97 ) ;
V_50 = V_51 ;
}
F_5 ( & V_5 -> V_153 ) ;
return V_50 ;
}
V_50 = F_77 ( V_5 , V_302 . V_303 ,
V_302 . V_304 , V_302 . V_280 , V_302 . V_281 ) ;
F_5 ( & V_5 -> V_153 ) ;
}
break;
case V_307 : {
V_50 = V_62 ;
F_9 ( V_5 , V_34 , V_35 , V_36 , L_98 ) ;
V_50 = F_25 ( & V_54 , V_49 , sizeof( struct V_53 ) ) ;
if ( V_50 ) {
F_9 ( V_5 , V_22 , 0 , 0 , L_82 ) ;
return - V_44 ;
}
if ( V_5 -> V_233 != V_235 ) {
F_9 ( V_5 , V_22 , 0 , 0 , L_99 ) ;
V_50 = - V_79 ;
break;
}
if ( F_58 ( V_5 ) == TRUE ) {
if ( V_54 . V_81 < sizeof( V_308 ) )
return - V_79 ;
if ( F_16 ( V_54 . V_84 , V_5 -> V_309 , sizeof( V_308 ) ) )
return - V_44 ;
} else {
if ( V_54 . V_81 < sizeof( V_310 ) )
return - V_79 ;
if ( F_16 ( V_54 . V_84 , V_5 -> V_311 , sizeof( V_310 ) ) )
return - V_44 ;
}
}
break;
case V_312 : {
T_5 V_313 = 0 ;
enum V_297 V_298 ;
V_298 = V_314 ;
F_9 ( V_5 , V_34 , V_35 , V_36 , L_100 ) ;
if ( F_58 ( V_5 ) != TRUE ) {
F_9 ( V_5 , V_22 , 0 , 0 , L_66 ) ;
return - V_79 ;
}
V_50 = F_25 ( & V_54 , V_49 , sizeof( struct V_53 ) ) ;
if ( V_50 ) {
F_9 ( V_5 , V_22 , 0 , 0 , L_82 ) ;
return - V_44 ;
}
V_50 = F_25 ( & V_298 , V_54 . V_80 , sizeof( INT ) ) ;
if ( V_50 ) {
F_9 ( V_5 , V_22 , 0 , 0 , L_83 ) ;
return - V_44 ;
}
F_9 ( V_5 , V_34 , V_35 , V_36 , L_101 , V_298 ) ;
if ( ( V_298 != V_258 ) &&
( V_298 != V_259 ) &&
( V_298 != V_260 ) ) {
F_9 ( V_5 , V_22 , 0 , 0 , L_102 , V_298 ) ;
return V_51 ;
}
V_313 = F_78 ( V_5 , V_298 ) ;
if ( V_313 == V_315 ) {
F_9 ( V_5 , V_22 , 0 , 0 , L_103 , V_298 ) ;
return - V_79 ;
}
V_5 -> V_288 = TRUE ;
V_5 -> V_316 = V_313 ;
V_5 -> V_257 = V_298 ;
}
V_50 = V_62 ;
break;
case V_317 : {
struct V_249 V_318 ;
INT V_274 ;
INT V_275 ;
INT V_277 = 0 ;
T_5 V_276 = 0 ;
T_15 V_273 ;
void T_2 * V_278 ;
if ( V_5 -> V_233 != V_235 ) {
F_9 ( V_5 , V_22 , 0 , 0 , L_104 ) ;
return - V_79 ;
}
if ( F_25 ( & V_54 , V_49 , sizeof( struct V_53 ) ) ) {
F_9 ( V_5 , V_22 , 0 , 0 , L_105 ) ;
return - V_44 ;
}
if ( F_25 ( & V_318 , V_54 . V_84 , sizeof( struct V_249 ) ) )
return - V_44 ;
V_274 = V_318 . V_261 ;
if ( V_274 > V_319 )
V_275 = V_319 ;
else
V_275 = V_274 ;
V_277 = V_318 . V_262 ;
V_278 = V_318 . V_263 ;
V_273 = F_3 ( V_275 , V_9 ) ;
if ( V_273 == NULL ) {
F_9 ( V_5 , V_22 , 0 , 0 , L_72 ) ;
V_50 = - V_10 ;
break;
}
F_4 ( & V_5 -> V_153 ) ;
if ( ( V_5 -> V_100 == TRUE ) ||
( V_5 -> V_101 == TRUE ) ||
( V_5 -> V_102 == TRUE ) ) {
F_9 ( V_5 , V_34 , V_35 , V_36 , L_58 ) ;
F_12 ( V_273 ) ;
F_5 ( & V_5 -> V_153 ) ;
return - V_39 ;
}
V_5 -> V_320 = TRUE ;
while ( V_274 ) {
if ( V_274 > V_319 )
V_276 = V_319 ;
else
V_276 = V_274 ;
V_50 = F_63 ( V_5 , ( V_83 ) V_273 , V_277 , V_276 ) ;
if ( V_50 ) {
F_9 ( V_5 , V_22 , 0 , 0 , L_73 , V_50 ) ;
break;
}
F_70 ( V_5 , V_34 , V_35 , V_36 , V_273 , V_276 ) ;
V_50 = F_16 ( V_278 , V_273 , V_276 ) ;
if ( V_50 ) {
F_9 ( V_5 , V_22 , 0 , 0 , L_74 , V_50 ) ;
F_5 ( & V_5 -> V_153 ) ;
F_12 ( V_273 ) ;
return - V_44 ;
}
V_274 = V_274 - V_276 ;
if ( V_274 ) {
V_277 = V_277 + V_276 ;
V_278 = V_278 + V_276 ;
}
}
V_5 -> V_320 = FALSE ;
F_5 ( & V_5 -> V_153 ) ;
F_12 ( V_273 ) ;
break;
}
case V_321 : {
T_6 V_11 = 0 ;
V_50 = F_25 ( & V_54 , V_49 , sizeof( struct V_53 ) ) ;
if ( V_50 ) {
F_9 ( V_5 , V_34 , V_35 , V_36 , L_106 ) ;
return - V_44 ;
}
if ( V_54 . V_78 != sizeof( unsigned long ) ) {
V_50 = - V_79 ;
break;
}
V_50 = F_25 ( & V_11 , V_54 . V_80 , V_54 . V_78 ) ;
if ( V_50 ) {
F_9 ( V_5 , V_34 , V_35 , V_36 , L_107 ) ;
return - V_44 ;
}
F_9 ( V_5 , V_34 , V_35 , V_36 , L_108 , V_11 ) ;
V_7 -> V_11 = V_11 ;
}
break;
case V_322 : {
struct V_323 V_324 ;
F_9 ( V_5 , V_34 , V_35 , V_36 , L_109 ) ;
V_324 . V_325 = V_326 ;
V_324 . V_327 = V_328 ;
V_324 . V_329 = 0 ;
V_324 . V_330 = V_5 -> V_233 ;
V_324 . V_331 = V_332 ;
if ( F_25 ( & V_54 , V_49 , sizeof( struct V_53 ) ) )
return - V_44 ;
if ( V_54 . V_81 < sizeof( V_324 ) )
return - V_79 ;
if ( F_16 ( V_54 . V_84 , & V_324 , sizeof( V_324 ) ) )
return - V_44 ;
}
break;
case V_333 : {
struct V_334 V_335 = { 0 } ;
F_9 ( V_5 , V_34 , V_35 , V_36 , L_110 ) ;
if ( F_25 ( & V_54 , V_49 , sizeof( struct V_53 ) ) )
return - V_44 ;
if ( V_54 . V_81 < sizeof( struct V_334 ) )
return - V_79 ;
V_335 . V_336 = F_79 () - V_5 -> V_337 ;
if ( F_16 ( V_54 . V_84 , & V_335 , sizeof( struct V_334 ) ) )
return - V_44 ;
}
break;
case V_338 :
F_9 ( V_5 , V_34 , V_35 , V_36 , L_111 ) ;
break;
default:
F_80 ( V_339 L_112 , V_47 ) ;
V_50 = V_51 ;
break;
}
return V_50 ;
}
int F_81 ( struct V_4 * V_5 )
{
if ( V_5 -> V_340 > 0 )
return V_5 -> V_340 ;
V_5 -> V_340 = F_82 ( 0 , V_341 , & V_342 ) ;
if ( V_5 -> V_340 < 0 ) {
F_42 ( V_339 L_113 ) ;
return V_5 -> V_340 ;
}
V_5 -> V_343 = F_83 ( V_344 , NULL ,
F_84 ( V_5 -> V_340 , 0 ) ,
V_5 , V_341 ) ;
if ( F_34 ( V_5 -> V_343 ) ) {
F_42 ( V_339 L_114 ) ;
F_85 ( V_5 -> V_340 , V_341 ) ;
return F_35 ( V_5 -> V_343 ) ;
}
return 0 ;
}
void F_86 ( struct V_4 * V_5 )
{
if ( V_5 -> V_340 > 0 ) {
F_87 ( V_344 , F_84 ( V_5 -> V_340 , 0 ) ) ;
F_85 ( V_5 -> V_340 , V_341 ) ;
}
}
