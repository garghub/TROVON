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
T_7 V_53 ;
int V_54 ;
F_9 ( V_5 , V_34 , V_35 , V_36 , L_7 , V_47 , V_48 ) ;
if ( F_20 ( V_47 ) != V_55 )
return - V_44 ;
if ( F_21 ( V_47 ) & V_56 )
V_50 = ! F_22 ( V_57 , V_49 , F_23 ( V_47 ) ) ;
else if ( F_21 ( V_47 ) & V_58 )
V_50 = ! F_22 ( V_59 , V_49 , F_23 ( V_47 ) ) ;
else if ( V_60 == ( F_21 ( V_47 ) & V_60 ) )
V_50 = V_61 ;
if ( V_50 )
return - V_44 ;
if ( V_5 -> V_32 )
return - V_44 ;
if ( FALSE == V_5 -> V_38 ) {
switch ( V_47 ) {
case V_62 :
case V_63 :
case V_64 :
case V_65 :
case V_66 :
case V_67 :
case V_68 :
case V_69 :
return - V_39 ;
default:
break;
}
}
V_50 = F_24 ( V_5 , V_47 , V_48 ) ;
if ( V_50 != V_70 )
return V_50 ;
switch ( V_47 ) {
case V_71 : {
T_8 V_72 = { 0 } ;
T_9 V_73 ;
T_5 V_74 ;
T_10 V_75 ;
if ( F_25 ( & V_53 , V_49 , sizeof( T_7 ) ) )
return - V_44 ;
if ( V_53 . V_76 > sizeof( V_72 ) )
return - V_77 ;
if ( F_25 ( & V_72 , V_53 . V_78 , V_53 . V_76 ) )
return - V_44 ;
if ( V_53 . V_79 > V_80 ||
V_53 . V_79 == 0 ) {
return - V_77 ;
}
V_74 = V_53 . V_79 ;
V_75 = 4 - ( V_74 % 4 ) ;
V_74 += V_75 % 4 ;
V_73 = F_26 ( V_74 , V_9 ) ;
if ( ! V_73 )
return - V_10 ;
V_54 = F_27 ( V_5 , ( T_5 ) V_72 . Register ,
( V_81 ) V_73 , V_74 ) ;
if ( V_54 > 0 ) {
V_50 = V_61 ;
if ( F_16 ( V_53 . V_82 , V_73 , V_54 ) ) {
F_12 ( V_73 ) ;
return - V_44 ;
}
} else {
V_50 = V_54 ;
}
F_12 ( V_73 ) ;
break;
}
case V_83 : {
T_11 V_84 = { 0 } ;
T_5 V_85 = 0 ;
if ( F_25 ( & V_53 , V_49 , sizeof( T_7 ) ) )
return - V_44 ;
if ( V_53 . V_76 > sizeof( V_84 ) )
return - V_77 ;
if ( F_25 ( & V_84 , V_53 . V_78 , V_53 . V_76 ) )
return - V_44 ;
V_85 = V_84 . Register & V_86 ;
if ( ! ( ( V_5 -> V_87 -> V_88 ) & V_89 ) &&
( ( V_85 == V_90 ) ||
( V_85 == V_91 ) ||
( V_85 == V_92 ) ||
( V_85 == V_93 ) ) ) {
F_9 ( V_5 , V_22 , 0 , 0 , L_8 ) ;
return - V_44 ;
}
V_50 = F_28 ( V_5 , ( T_5 ) V_84 . Register ,
( V_81 ) V_84 . V_94 , sizeof( T_6 ) ) ;
if ( V_50 == V_61 ) {
F_9 ( V_5 , V_34 , V_35 , V_36 , L_9 ) ;
} else {
F_9 ( V_5 , V_34 , V_35 , V_36 , L_10 ) ;
V_50 = - V_44 ;
}
break;
}
case V_95 :
case V_96 : {
T_8 V_72 = { 0 } ;
T_9 V_73 = NULL ;
T_5 V_85 = 0 ;
if ( ( V_5 -> V_97 == TRUE ) ||
( V_5 -> V_98 == TRUE ) ||
( V_5 -> V_99 == TRUE ) ) {
F_9 ( V_5 , V_22 , 0 , 0 , L_11 ) ;
return - V_39 ;
}
if ( F_25 ( & V_53 , V_49 , sizeof( T_7 ) ) )
return - V_44 ;
if ( V_53 . V_76 > sizeof( V_72 ) )
return - V_77 ;
if ( F_25 ( & V_72 , V_53 . V_78 , V_53 . V_76 ) )
return - V_44 ;
if ( V_53 . V_79 > V_80 ||
V_53 . V_79 == 0 ) {
return - V_77 ;
}
V_73 = F_26 ( V_53 . V_79 , V_9 ) ;
if ( ! V_73 )
return V_51 ;
if ( ( ( ( T_6 ) V_72 . Register & 0x0F000000 ) != 0x0F000000 ) ||
( ( T_6 ) V_72 . Register & 0x3 ) ) {
F_9 ( V_5 , V_22 , 0 , 0 , L_12 ,
( int ) V_72 . Register ) ;
F_12 ( V_73 ) ;
return - V_77 ;
}
V_85 = V_72 . Register & V_86 ;
V_54 = F_29 ( V_5 , ( T_5 ) V_72 . Register , ( V_81 ) V_73 , V_53 . V_79 ) ;
if ( V_54 > 0 ) {
V_50 = V_61 ;
if ( F_16 ( V_53 . V_82 , V_73 , V_54 ) ) {
F_12 ( V_73 ) ;
return - V_44 ;
}
} else {
V_50 = V_54 ;
}
F_12 ( V_73 ) ;
break;
}
case V_100 :
case V_101 : {
T_11 V_84 = { 0 } ;
T_5 V_85 = 0 ;
if ( ( V_5 -> V_97 == TRUE ) ||
( V_5 -> V_98 == TRUE ) ||
( V_5 -> V_99 == TRUE ) ) {
F_9 ( V_5 , V_22 , 0 , 0 , L_13 ) ;
return - V_39 ;
}
if ( F_25 ( & V_53 , V_49 , sizeof( T_7 ) ) )
return - V_44 ;
if ( V_53 . V_76 > sizeof( V_84 ) )
return - V_77 ;
if ( F_25 ( & V_84 , V_53 . V_78 , V_53 . V_76 ) )
return - V_44 ;
if ( ( ( ( T_6 ) V_84 . Register & 0x0F000000 ) != 0x0F000000 ) ||
( ( T_6 ) V_84 . Register & 0x3 ) ) {
F_9 ( V_5 , V_22 , 0 , 0 , L_14 , ( int ) V_84 . Register ) ;
return - V_77 ;
}
V_85 = V_84 . Register & V_86 ;
if ( ! ( ( V_5 -> V_87 -> V_88 ) & V_89 ) &&
( ( V_85 == V_90 ) ||
( V_85 == V_91 ) ||
( V_85 == V_92 ) ||
( V_85 == V_93 ) ) &&
( V_47 == V_100 ) ) {
F_9 ( V_5 , V_22 , 0 , 0 , L_8 ) ;
return - V_44 ;
}
V_50 = F_30 ( V_5 , ( T_5 ) V_84 . Register ,
( V_81 ) V_84 . V_94 , V_84 . V_102 ) ;
if ( V_50 == V_61 ) {
F_9 ( V_5 , V_22 , V_35 , V_36 , L_9 ) ;
} else {
F_9 ( V_5 , V_34 , V_35 , V_36 , L_10 ) ;
V_50 = - V_44 ;
}
break;
}
case V_68 : {
T_12 V_103 [ 4 ] ;
T_5 V_104 = 0 ;
T_5 V_105 = 0 ;
T_5 V_106 = 0 ;
T_13 V_107 = { 0 } ;
if ( ( V_5 -> V_97 == TRUE ) ||
( V_5 -> V_98 == TRUE ) ||
( V_5 -> V_99 == TRUE ) ) {
F_9 ( V_5 , V_34 , V_35 , V_36 , L_15 ) ;
return - V_39 ;
}
if ( F_25 ( & V_53 , V_49 , sizeof( T_7 ) ) )
return - V_44 ;
if ( V_53 . V_76 > sizeof( V_107 ) )
return - V_77 ;
if ( F_25 ( & V_107 , V_53 . V_78 , V_53 . V_76 ) )
return - V_44 ;
V_105 = V_107 . V_108 ;
V_106 = V_107 . V_109 ;
V_104 = ( 1 << V_105 ) ;
if ( F_31 ( V_5 , V_104 ) == FALSE ) {
F_9 ( V_5 , V_34 , V_35 , V_36 , L_16 , V_104 ) ;
V_50 = - V_77 ;
break;
}
if ( V_106 ) {
V_50 = F_30 ( V_5 , V_110 , ( V_81 ) ( & V_104 ) , sizeof( T_5 ) ) ;
if ( V_50 == V_61 ) {
F_9 ( V_5 , V_34 , V_35 , V_36 , L_17 ) ;
} else {
F_9 ( V_5 , V_34 , V_35 , V_36 , L_18 , V_105 ) ;
break;
}
} else {
V_50 = F_30 ( V_5 , V_111 , ( V_81 ) ( & V_104 ) , sizeof( T_5 ) ) ;
if ( V_50 == V_61 ) {
F_9 ( V_5 , V_34 , V_35 , V_36 , L_17 ) ;
} else {
F_9 ( V_5 , V_34 , V_35 , V_36 , L_19 , V_105 ) ;
break;
}
}
V_54 = F_29 ( V_5 , ( T_5 ) V_112 , ( V_81 ) V_103 , sizeof( T_5 ) ) ;
if ( V_54 < 0 ) {
V_50 = V_54 ;
F_9 ( V_5 , V_34 , V_35 , V_36 ,
L_20 ) ;
break;
} else {
V_50 = V_61 ;
}
* ( T_5 * ) V_103 |= ( 1 << V_105 ) ;
V_50 = F_30 ( V_5 , V_112 ,
( V_81 ) V_103 , sizeof( T_5 ) ) ;
if ( V_50 == V_61 ) {
F_9 ( V_5 , V_34 , V_35 , V_36 , L_21 ) ;
} else {
F_9 ( V_5 , V_34 , V_35 , V_36 , L_22 ) ;
break;
}
}
break;
case V_113 : {
T_14 V_114 = { 0 } ;
F_9 ( V_5 , V_34 , V_35 , V_36 , L_23 ) ;
if ( ( V_5 -> V_97 == TRUE ) ||
( V_5 -> V_98 == TRUE ) ||
( V_5 -> V_99 == TRUE ) ) {
F_9 ( V_5 , V_34 , V_35 , V_36 , L_15 ) ;
V_50 = - V_39 ;
break;
}
if ( F_25 ( & V_53 , V_49 , sizeof( T_7 ) ) )
return - V_44 ;
if ( V_53 . V_76 > sizeof( V_114 ) )
return - V_77 ;
if ( F_25 ( & V_114 , V_53 . V_78 , V_53 . V_76 ) )
return - V_44 ;
if ( V_5 -> V_115 . V_116 ) {
if ( V_114 . V_117 == V_118 ) {
F_9 ( V_5 , V_34 , V_35 , V_36 , L_24 ) ;
V_5 -> V_119 = V_120 ;
} else {
F_9 ( V_5 , V_34 , V_35 , V_36 , L_25 ) ;
V_5 -> V_119 = V_121 ;
}
F_32 ( & V_5 -> V_115 . V_122 ) ;
}
}
break;
case V_69 : {
T_6 V_105 = 0 ;
T_12 V_123 [ 4 ] ;
T_13 V_107 = { 0 } ;
if ( ( V_5 -> V_97 == TRUE ) ||
( V_5 -> V_98 == TRUE ) ||
( V_5 -> V_99 == TRUE ) )
return - V_39 ;
if ( F_25 ( & V_53 , V_49 , sizeof( T_7 ) ) )
return - V_44 ;
if ( V_53 . V_76 > sizeof( V_107 ) )
return - V_77 ;
if ( F_25 ( & V_107 , V_53 . V_78 , V_53 . V_76 ) )
return - V_44 ;
V_105 = V_107 . V_108 ;
V_54 = F_29 ( V_5 , ( T_5 ) V_124 ,
( V_81 ) V_123 , sizeof( T_5 ) ) ;
if ( V_54 < 0 ) {
V_50 = V_54 ;
F_9 ( V_5 , V_22 , 0 , 0 , L_26 ) ;
return V_50 ;
} else {
V_50 = V_61 ;
}
}
break;
case V_125 : {
T_12 V_103 [ 4 ] ;
T_15 V_126 [ V_127 ] ;
T_16 V_128 = ( T_16 ) V_126 ;
memset ( V_128 , 0 , V_127 * sizeof( T_15 ) ) ;
if ( ( V_5 -> V_97 == TRUE ) ||
( V_5 -> V_98 == TRUE ) ||
( V_5 -> V_99 == TRUE ) )
return - V_77 ;
if ( F_25 ( & V_53 , V_49 , sizeof( T_7 ) ) )
return - V_44 ;
if ( V_53 . V_76 > sizeof( V_126 ) )
return - V_77 ;
if ( F_25 ( & V_126 , V_53 . V_78 , V_53 . V_76 ) )
return - V_44 ;
if ( F_31 ( V_5 , V_128 [ V_129 ] . V_130 ) == FALSE ) {
F_9 ( V_5 , V_34 , V_35 , V_36 ,
L_27 ,
V_128 [ V_129 ] . V_130 , V_5 -> V_131 ) ;
V_50 = - V_77 ;
break;
}
if ( ( V_128 [ V_129 ] . V_130 ) &
( V_128 [ V_129 ] . V_132 ) ) {
* ( T_5 * ) V_103 = V_128 [ V_129 ] . V_130 &
V_128 [ V_129 ] . V_132 &
V_128 [ V_129 ] . V_133 ;
if ( * ( T_5 * ) V_103 )
V_50 = F_30 ( V_5 , V_110 ,
( V_81 ) V_103 , sizeof( T_6 ) ) ;
if ( V_50 != V_61 ) {
F_9 ( V_5 , V_22 , 0 , 0 , L_28 ) ;
return V_50 ;
}
* ( T_5 * ) V_103 = ( V_128 [ V_129 ] . V_130 &
V_128 [ V_129 ] . V_132 &
( ~ ( V_128 [ V_129 ] . V_133 ) ) ) ;
if ( * ( T_5 * ) V_103 )
V_50 = F_30 ( V_5 , V_111 , ( V_81 ) V_103 , sizeof( T_6 ) ) ;
if ( V_50 != V_61 ) {
F_9 ( V_5 , V_22 , 0 , 0 , L_29 ) ;
return V_50 ;
}
}
if ( V_128 [ V_129 ] . V_130 ) {
V_54 = F_29 ( V_5 , ( T_5 ) V_124 , ( V_81 ) V_103 , sizeof( T_5 ) ) ;
if ( V_54 < 0 ) {
V_50 = V_54 ;
F_9 ( V_5 , V_22 , 0 , 0 , L_30 ) ;
return V_50 ;
} else {
V_50 = V_61 ;
}
V_128 [ V_129 ] . V_133 = ( * ( T_5 * ) V_103 &
V_128 [ V_129 ] . V_130 ) ;
}
V_50 = F_16 ( V_53 . V_82 , & V_126 , V_53 . V_79 ) ;
if ( V_50 ) {
F_9 ( V_5 , V_22 , 0 , 0 ,
L_31 , V_50 ) ;
return - V_44 ;
}
}
break;
case V_134 : {
T_12 V_103 [ 4 ] ;
T_17 V_135 [ V_127 ] ;
T_18 V_136 = ( T_18 ) V_135 ;
if ( ( V_5 -> V_97 == TRUE ) ||
( V_5 -> V_98 == TRUE ) ||
( V_5 -> V_99 == TRUE ) )
return - V_77 ;
if ( F_25 ( & V_53 , V_49 , sizeof( T_7 ) ) )
return - V_44 ;
if ( V_53 . V_76 > sizeof( V_135 ) )
return - V_77 ;
if ( F_25 ( & V_135 , V_53 . V_78 , V_53 . V_76 ) )
return - V_44 ;
V_54 = F_29 ( V_5 , ( T_5 ) V_112 , ( V_81 ) V_103 , sizeof( T_5 ) ) ;
if ( V_54 < 0 ) {
V_50 = V_54 ;
F_9 ( V_5 , V_22 , 0 , 0 , L_32 ) ;
return V_50 ;
} else {
V_50 = V_61 ;
}
if ( F_31 ( V_5 , V_136 [ V_129 ] . V_130 ) == FALSE ) {
F_9 ( V_5 , V_34 , V_35 , V_36 ,
L_27 ,
V_136 [ V_129 ] . V_130 , V_5 -> V_131 ) ;
V_50 = - V_77 ;
break;
}
if ( V_136 [ V_129 ] . V_130 ) {
* ( T_5 * ) V_103 |= ( V_136 [ V_129 ] . V_137 &
V_136 [ V_129 ] . V_130 ) ;
* ( T_5 * ) V_103 &= ~ ( ( ~ V_136 [ V_129 ] . V_137 ) &
V_136 [ V_129 ] . V_130 ) ;
V_136 [ V_129 ] . V_137 = * ( T_5 * ) V_103 ;
V_50 = F_30 ( V_5 , V_112 , ( V_81 ) V_103 , sizeof( T_6 ) ) ;
if ( V_50 == V_61 ) {
F_9 ( V_5 , V_34 , V_35 , V_36 ,
L_33 ) ;
} else {
F_9 ( V_5 , V_22 , 0 , 0 ,
L_34 ) ;
V_50 = - V_44 ;
break;
}
} else {
V_136 [ V_129 ] . V_137 = * ( T_5 * ) V_103 ;
}
V_50 = F_16 ( V_53 . V_82 , & V_135 , V_53 . V_79 ) ;
if ( V_50 ) {
F_9 ( V_5 , V_22 , 0 , 0 ,
L_31 , V_50 ) ;
return - V_44 ;
}
}
break;
case V_62 :
case V_63 :
case V_64 :
case V_65 :
case V_66 :
case V_67 : {
T_19 V_138 = NULL ;
if ( F_25 ( & V_53 , V_49 , sizeof( T_7 ) ) )
return - V_44 ;
if ( V_53 . V_76 < sizeof( struct V_139 ) )
return - V_77 ;
if ( V_53 . V_76 > V_140 )
return - V_77 ;
V_138 = F_33 ( V_53 . V_78 ,
V_53 . V_76 ) ;
if ( F_34 ( V_138 ) )
return F_35 ( V_138 ) ;
F_4 ( & V_5 -> V_141 ) ;
V_50 = F_36 ( V_5 -> V_142 ,
! V_5 -> V_99 ,
( 1 * V_143 ) ) ;
if ( V_50 == - V_33 )
goto V_144;
if ( V_5 -> V_99 ) {
F_9 ( V_5 , V_34 , V_35 , V_36 ,
L_35 ) ;
V_50 = V_51 ;
goto V_144;
}
V_50 = F_37 ( V_5 , ( T_19 ) V_138 ) ;
V_144:
F_5 ( & V_5 -> V_141 ) ;
F_12 ( V_138 ) ;
break;
}
case V_145 : {
if ( F_38 ( & V_5 -> V_146 ) ) {
F_9 ( V_5 , V_34 , V_35 , V_36 ,
L_36 ) ;
return - V_39 ;
}
F_9 ( V_5 , V_22 , 0 , 0 ,
L_37 , V_45 -> V_46 ) ;
if ( F_38 ( & V_5 -> V_147 ) )
return - V_148 ;
V_5 -> V_149 = FALSE ;
V_5 -> V_150 = V_45 -> V_46 ;
V_5 -> V_151 = FALSE ;
V_5 -> V_38 = FALSE ;
F_39 ( V_5 -> V_152 ) ;
F_40 ( V_5 -> V_152 ) ;
V_50 = F_41 ( V_5 ) ;
if ( V_50 ) {
F_42 ( V_153 L_38 , V_5 -> V_152 -> V_154 ) ;
F_5 ( & V_5 -> V_147 ) ;
F_5 ( & V_5 -> V_146 ) ;
return V_50 ;
}
F_43 ( 10 ) ;
F_5 ( & V_5 -> V_146 ) ;
return V_50 ;
}
case V_155 : {
struct V_156 * V_157 = NULL ;
F_9 ( V_5 , V_22 , 0 , 0 , L_37 , V_45 -> V_46 ) ;
if ( ! F_38 ( & V_5 -> V_147 ) ) {
F_9 ( V_5 , V_22 , 0 , 0 ,
L_39 ) ;
F_5 ( & V_5 -> V_147 ) ;
V_50 = - V_77 ;
return V_50 ;
}
if ( F_25 ( & V_53 , V_49 , sizeof( T_7 ) ) ) {
F_5 ( & V_5 -> V_147 ) ;
return - V_44 ;
}
F_9 ( V_5 , V_22 , 0 , 0 ,
L_40 , V_53 . V_76 ) ;
if ( V_53 . V_76 > sizeof( struct V_156 ) ) {
F_5 ( & V_5 -> V_147 ) ;
return - V_77 ;
}
V_157 = F_26 ( sizeof( * V_157 ) , V_9 ) ;
if ( ! V_157 ) {
F_5 ( & V_5 -> V_147 ) ;
return - V_10 ;
}
if ( F_25 ( V_157 , V_53 . V_78 , V_53 . V_76 ) ) {
F_5 ( & V_5 -> V_147 ) ;
return - V_44 ;
}
if ( ! V_157 -> V_158 ||
( V_157 -> V_159 == 0 ) ) {
F_9 ( V_5 , V_22 , 0 , 0 , L_41 ,
V_157 -> V_159 ) ;
F_5 ( & V_5 -> V_147 ) ;
V_50 = - V_77 ;
return V_50 ;
}
V_50 = F_44 ( V_5 , V_157 ) ;
if ( V_50 != V_61 ) {
if ( V_157 -> V_160 == V_161 )
F_9 ( V_5 , V_22 , 0 , 0 , L_42 ) ;
else
F_9 ( V_5 , V_22 , 0 , 0 , L_43 ) ;
if ( V_5 -> V_115 . V_116 & V_162 ) {
V_5 -> V_119 = V_163 ;
V_5 -> V_115 . V_164 = FALSE ;
F_32 ( & V_5 -> V_115 . V_122 ) ;
}
}
if ( V_50 != V_61 )
F_5 ( & V_5 -> V_147 ) ;
F_9 ( V_5 , V_22 , V_35 , V_36 , L_44 ) ;
F_12 ( V_157 ) ;
return V_50 ;
}
case V_165 : {
if ( ! F_38 ( & V_5 -> V_147 ) ) {
F_5 ( & V_5 -> V_147 ) ;
return - V_77 ;
}
if ( F_38 ( & V_5 -> V_146 ) ) {
F_9 ( V_5 , V_22 , 0 , 0 ,
L_45 ) ;
F_5 ( & V_5 -> V_147 ) ;
return - V_39 ;
}
V_5 -> V_149 = TRUE ;
V_5 -> V_151 = TRUE ;
F_45 ( & V_5 -> V_166 , 0 ) ;
V_5 -> V_167 = 0 ;
V_5 -> V_168 = 0 ;
V_50 = F_46 ( V_5 ) ;
if ( V_50 ) {
F_9 ( V_5 , V_22 , 0 , 0 , L_46 ) ;
F_5 ( & V_5 -> V_147 ) ;
F_5 ( & V_5 -> V_146 ) ;
return V_50 ;
} else {
F_9 ( V_5 , V_34 , V_35 ,
V_36 , L_47 ) ;
}
F_43 ( 10 ) ;
if ( F_47 ( ( V_169 ) V_5 -> V_170 ) )
F_9 ( V_5 , V_22 , 0 , 0 , L_48 ) ;
V_52 = 5 * V_143 ;
V_5 -> V_171 = FALSE ;
F_48 ( V_5 -> V_172 ,
V_5 -> V_171 , V_52 ) ;
V_5 -> V_150 = V_173 ;
V_5 -> V_38 = TRUE ;
F_45 ( & V_5 -> V_166 , 0 ) ;
V_5 -> V_167 = 0 ;
V_5 -> V_174 = 0 ;
F_45 ( & V_5 -> V_175 , 0 ) ;
V_5 -> V_176 = 0 ;
V_5 -> V_177 = 0 ;
if ( V_5 -> V_115 . V_116 & V_162 ) {
V_5 -> V_119 = V_178 ;
F_32 ( & V_5 -> V_115 . V_122 ) ;
}
if ( ! V_52 )
V_50 = - V_37 ;
F_5 ( & V_5 -> V_147 ) ;
F_5 ( & V_5 -> V_146 ) ;
return V_50 ;
}
case V_179 :
V_50 = 0 ;
if ( F_49 ( V_5 -> V_180 , ( unsigned long T_2 * ) V_48 ) )
V_50 = - V_44 ;
break;
case V_181 :
V_50 = 0 ;
if ( F_49 ( V_5 -> V_182 , ( unsigned long T_2 * ) V_48 ) )
V_50 = - V_44 ;
break;
case V_183 : {
INT V_184 = F_38 ( & V_5 -> V_146 ) ;
if ( V_184 ) {
F_9 ( V_5 , V_22 , 0 , 0 , L_49 ) ;
return - V_39 ;
}
F_4 ( & V_5 -> V_12 ) ;
V_50 = F_41 ( V_5 ) ;
F_50 () ;
F_5 ( & V_5 -> V_12 ) ;
F_5 ( & V_5 -> V_146 ) ;
F_51 ( V_5 ) ;
break;
}
case V_185 : {
T_20 V_186 ;
V_50 = 0 ;
for ( V_186 = 0 ; V_186 < V_187 ; V_186 ++ ) {
if ( F_49 ( V_5 -> V_188 [ V_186 ] . V_189 ,
( unsigned long T_2 * ) V_48 ) ) {
V_50 = - V_44 ;
break;
}
}
break;
}
case V_190 :
F_52 ( V_5 ) ;
F_53 ( & V_5 -> V_191 ) ;
V_50 = V_61 ;
break;
case V_192 :
if ( F_16 ( V_49 , & V_5 -> V_188 , sizeof( struct V_193 ) * V_187 ) )
return - V_44 ;
V_50 = V_61 ;
break;
case V_194 : {
T_5 V_195 = 0 ;
if ( F_25 ( & V_195 , V_49 , sizeof( T_5 ) ) )
return - V_44 ;
if ( V_195 ) {
F_9 ( V_5 , V_34 , V_35 , V_36 , L_50 ) ;
V_5 -> V_196 = V_197 ;
} else {
F_9 ( V_5 , V_34 , V_35 , V_36 , L_51 ) ;
V_5 -> V_196 = V_198 ;
}
V_50 = V_61 ;
break;
}
case V_199 : {
T_21 V_42 ;
if ( F_25 ( & V_53 , V_49 , sizeof( T_7 ) ) )
return - V_44 ;
V_42 = F_17 ( T_21 , V_53 . V_79 , strlen ( V_200 ) + 1 ) ;
if ( F_16 ( V_53 . V_82 , V_200 , V_42 ) )
return - V_44 ;
V_50 = V_61 ;
break;
}
case V_201 : {
T_22 V_202 ;
if ( F_25 ( & V_53 , V_49 , sizeof( T_7 ) ) ) {
F_9 ( V_5 , V_22 , 0 , 0 , L_52 ) ;
return - V_44 ;
}
if ( V_53 . V_79 != sizeof( V_202 ) ) {
V_50 = - V_77 ;
break;
}
memset ( & V_202 , 0 , sizeof( V_202 ) ) ;
V_202 . V_203 = V_5 -> V_97 ;
V_202 . V_204 = V_5 -> V_98 ;
V_202 . V_205 = V_5 -> V_177 ;
if ( F_16 ( V_53 . V_82 , & V_202 , F_17 ( T_3 , sizeof( V_202 ) , V_53 . V_79 ) ) ) {
F_9 ( V_5 , V_22 , 0 , 0 , L_53 ) ;
return - V_44 ;
}
V_50 = V_61 ;
break;
}
case V_206 : {
T_5 V_207 ;
if ( F_25 ( & V_53 , V_49 , sizeof( T_7 ) ) )
return - V_44 ;
if ( F_25 ( & V_207 , V_53 . V_78 , sizeof( T_5 ) ) )
return - V_44 ;
if ( V_207 )
V_5 -> V_14 -> V_208 = TRUE ;
else
V_5 -> V_14 -> V_208 = FALSE ;
break;
}
case V_209 : {
T_6 V_210 = 0 ;
if ( F_25 ( & V_53 , V_49 , sizeof( T_7 ) ) )
return - V_44 ;
if ( V_53 . V_79 < sizeof( V_211 ) ) {
F_9 ( V_5 , V_22 , 0 , 0 ,
L_54 ,
V_53 . V_79 , sizeof( V_211 ) ) ;
return - V_77 ;
}
if ( F_25 ( & V_210 , V_53 . V_78 , sizeof( V_210 ) ) )
return - V_44 ;
F_9 ( V_5 , V_34 , V_35 , V_36 , L_55 , V_210 ) ;
F_54 ( V_5 , V_210 , V_53 . V_82 ) ;
V_50 = V_61 ;
}
break;
case V_212 : {
T_19 V_73 ;
if ( F_25 ( & V_53 , V_49 , sizeof( T_7 ) ) )
return - V_44 ;
if ( V_53 . V_79 != sizeof( V_213 ) ) {
F_9 ( V_5 , V_22 , 0 , 0 ,
L_56 ,
V_53 . V_79 , sizeof( V_213 ) ) ;
return - V_77 ;
}
V_73 = F_3 ( sizeof( V_213 ) , V_9 ) ;
if ( ! V_73 )
return V_51 ;
V_50 = F_55 ( V_5 , V_73 ) ;
F_56 ( V_73 , V_7 ) ;
if ( V_50 != V_51 )
if ( F_16 ( V_53 . V_82 , V_73 , sizeof( V_213 ) ) ) {
F_12 ( V_73 ) ;
return - V_44 ;
}
F_12 ( V_73 ) ;
break;
}
case V_214 :
if ( ( FALSE == V_5 -> V_215 ) && ( TRUE == V_5 -> V_97 ) ) {
V_5 -> V_216 = V_217 ;
V_5 -> V_218 = TRUE ;
F_32 ( & V_5 -> V_219 ) ;
}
V_50 = V_61 ;
break;
case V_220 : {
T_23 V_221 ;
T_5 V_85 = 0 ;
T_9 V_138 = NULL ;
if ( ( V_5 -> V_97 == TRUE ) ||
( V_5 -> V_98 == TRUE ) ||
( V_5 -> V_99 == TRUE ) ) {
F_9 ( V_5 , V_22 , 0 , 0 , L_57 ) ;
V_50 = - V_39 ;
break;
}
if ( F_25 ( & V_53 , V_49 , sizeof( T_7 ) ) )
return - V_44 ;
if ( V_53 . V_76 < sizeof( T_6 ) * 2 )
return - V_77 ;
V_138 = F_33 ( V_53 . V_78 ,
V_53 . V_76 ) ;
if ( F_34 ( V_138 ) )
return F_35 ( V_138 ) ;
V_221 = ( T_23 ) V_138 ;
if ( ( ( T_6 ) V_221 -> Register & 0x0F000000 ) != 0x0F000000 ||
( ( T_6 ) V_221 -> Register & 0x3 ) ) {
F_12 ( V_138 ) ;
F_9 ( V_5 , V_22 , 0 , 0 , L_14 , ( int ) V_221 -> Register ) ;
V_50 = - V_77 ;
break;
}
V_85 = V_221 -> Register & V_86 ;
if ( ! ( ( V_5 -> V_87 -> V_88 ) & V_89 ) &&
( ( V_85 == V_90 ) ||
( V_85 == V_91 ) ||
( V_85 == V_92 ) ||
( V_85 == V_93 ) ) &&
( V_47 == V_100 ) ) {
F_12 ( V_138 ) ;
F_9 ( V_5 , V_22 , 0 , 0 , L_8 ) ;
V_50 = - V_44 ;
break;
}
if ( V_221 -> V_222 == FALSE )
V_50 = F_57 ( V_5 , ( T_5 ) V_221 -> Register , ( T_9 ) V_221 -> V_223 , V_53 . V_76 - 2 * sizeof( T_6 ) ) ;
else
V_50 = F_30 ( V_5 , ( T_5 ) V_221 -> Register , ( V_81 ) V_221 -> V_223 , V_53 . V_76 - 2 * sizeof( T_6 ) ) ;
if ( V_50 != V_61 )
F_9 ( V_5 , V_22 , 0 , 0 , L_10 ) ;
F_12 ( V_138 ) ;
break;
}
case V_224 :
if ( F_25 ( & V_53 , V_49 , sizeof( T_7 ) ) )
return - V_44 ;
if ( V_5 -> V_225 == V_226 || V_5 -> V_225 == V_227 ) {
if ( F_16 ( V_53 . V_82 , & V_5 -> V_228 , sizeof( T_5 ) ) )
return - V_44 ;
}
V_50 = V_61 ;
break;
case V_229 : {
T_5 V_230 = 0 ;
if ( V_5 -> V_225 == V_227 ) {
if ( F_25 ( & V_53 , V_49 , sizeof( T_7 ) ) )
return - V_44 ;
if ( F_25 ( & V_230 , V_53 . V_78 , sizeof( T_5 ) ) )
return - V_44 ;
if ( ( V_230 < V_231 ) || ( V_230 > V_232 ) ) {
if ( F_16 ( V_53 . V_82 , & V_5 -> V_230 ,
sizeof( T_5 ) ) )
return - V_44 ;
} else {
if ( F_58 ( V_5 ) ) {
if ( F_16 ( V_53 . V_82 , & V_5 -> V_230 , sizeof( T_5 ) ) )
return - V_44 ;
} else {
if ( ( TRUE == V_5 -> V_98 ) || ( TRUE == V_5 -> V_97 ) ) {
F_9 ( V_5 , V_22 , 0 , 0 , L_58 ) ;
return - V_39 ;
}
V_5 -> V_230 = V_230 ;
F_59 ( V_5 , V_5 -> V_230 ) ;
}
}
V_50 = V_61 ;
} else {
V_50 = V_51 ;
}
}
break;
case V_233 :
#ifdef F_60
{
T_24 V_234 ;
F_9 ( V_5 , V_34 , V_35 , V_36 , L_59 ) ;
if ( F_25 ( & V_53 , V_49 , sizeof( T_7 ) ) )
return - V_44 ;
if ( F_25 ( & V_234 , V_53 . V_78 , sizeof( T_24 ) ) )
return - V_44 ;
F_9 ( V_5 , V_22 , 0 , 0 , L_60 ,
V_234 . V_235 , V_234 . Type ) ;
V_234 . V_236 = 1 << V_234 . V_236 ;
F_9 ( V_5 , V_22 , 0 , 0 , L_61 , V_234 . V_236 ) ;
V_5 -> V_237 . type |= V_234 . Type ;
if ( V_234 . V_235 )
V_5 -> V_237 . V_238 [ V_234 . Type ] |= V_234 . V_236 ;
else
V_5 -> V_237 . V_238 [ V_234 . Type ] &= ~ V_234 . V_236 ;
F_61 ( V_5 ) ;
}
#endif
break;
case V_239 :
case V_240 : {
T_25 V_241 ;
T_26 V_242 = NULL ;
T_6 V_243 = 0 ;
struct V_244 V_245 , V_246 ;
memset ( & V_245 , 0 , sizeof( struct V_244 ) ) ;
memset ( & V_246 , 0 , sizeof( struct V_244 ) ) ;
if ( ( V_5 -> V_225 == V_227 ) && ( V_5 -> V_247 == 0 ) ) {
F_9 ( V_5 , V_22 , 0 , 0 , L_62 ) ;
return - V_44 ;
}
if ( F_58 ( V_5 ) ) {
if ( ( V_5 -> V_248 != V_249 ) &&
( V_5 -> V_248 != V_250 ) &&
( V_5 -> V_248 != V_251 ) ) {
F_9 ( V_5 , V_22 , 0 , 0 , L_63 ) ;
return V_51 ;
}
}
if ( F_25 ( & V_53 , V_49 , sizeof( T_7 ) ) )
return - V_44 ;
if ( F_25 ( & V_241 ,
( V_239 == V_47 ) ? V_53 . V_82 : V_53 . V_78 ,
sizeof( T_25 ) ) )
return - V_44 ;
if ( V_241 . V_252 > V_5 -> V_228 )
return V_51 ;
if ( V_241 . V_253 > V_5 -> V_228 - V_241 . V_252 ) {
return V_51 ;
}
V_242 = F_33 ( V_241 . V_254 ,
V_241 . V_252 ) ;
if ( F_34 ( V_242 ) )
return F_35 ( V_242 ) ;
F_62 ( & V_245 ) ;
if ( V_239 == V_47 ) {
F_4 ( & V_5 -> V_146 ) ;
if ( ( V_5 -> V_97 == TRUE ) ||
( V_5 -> V_98 == TRUE ) ||
( V_5 -> V_99 == TRUE ) ) {
F_9 ( V_5 , V_34 , V_35 , V_36 , L_58 ) ;
F_5 ( & V_5 -> V_146 ) ;
F_12 ( V_242 ) ;
return - V_39 ;
}
V_50 = F_63 ( V_5 , ( V_81 ) V_242 , V_241 . V_253 , V_241 . V_252 ) ;
F_5 ( & V_5 -> V_146 ) ;
if ( V_50 != V_61 ) {
F_12 ( V_242 ) ;
return V_50 ;
}
if ( F_16 ( V_241 . V_254 , V_242 , V_241 . V_252 ) ) {
F_12 ( V_242 ) ;
return - V_44 ;
}
} else {
F_4 ( & V_5 -> V_146 ) ;
if ( ( V_5 -> V_97 == TRUE ) ||
( V_5 -> V_98 == TRUE ) ||
( V_5 -> V_99 == TRUE ) ) {
F_9 ( V_5 , V_34 , V_35 , V_36 , L_58 ) ;
F_5 ( & V_5 -> V_146 ) ;
F_12 ( V_242 ) ;
return - V_39 ;
}
V_5 -> V_255 = TRUE ;
if ( F_58 ( V_5 ) ) {
V_50 = F_64 ( V_5 , V_5 -> V_248 ) ;
if ( V_50 != V_61 ) {
if ( ( ( V_241 . V_253 + V_241 . V_252 ) != V_5 -> V_228 ) ||
( V_241 . V_252 < V_256 ) ) {
F_9 ( V_5 , V_34 , V_35 , V_36 , L_64 ) ;
F_5 ( & V_5 -> V_146 ) ;
F_12 ( V_242 ) ;
return V_50 ;
}
V_243 = F_65 ( * ( V_81 ) ( V_242 + V_241 . V_252 - V_256 ) ) ;
if ( V_243 != V_257 ) {
F_9 ( V_5 , V_34 , V_35 , V_36 , L_64 ) ;
F_5 ( & V_5 -> V_146 ) ;
F_12 ( V_242 ) ;
return V_50 ;
}
}
}
V_50 = F_66 ( V_5 , ( V_81 ) V_242 , V_241 . V_253 , V_241 . V_252 , V_241 . V_258 ) ;
if ( F_58 ( V_5 ) )
F_67 ( V_5 , V_5 -> V_248 ) ;
V_5 -> V_255 = FALSE ;
F_5 ( & V_5 -> V_146 ) ;
if ( V_50 != V_61 ) {
F_12 ( V_242 ) ;
return V_50 ;
}
}
F_62 ( & V_246 ) ;
F_9 ( V_5 , V_34 , V_35 , V_36 , L_65 , ( V_246 . V_259 - V_245 . V_259 ) * 1000 + ( V_246 . V_260 - V_245 . V_260 ) / 1000 ) ;
F_12 ( V_242 ) ;
return V_61 ;
}
case V_261 : {
T_27 V_262 = { 0 } ;
T_26 V_263 = NULL ;
T_5 V_264 = 0 ;
T_5 V_265 = 0 ;
T_5 V_266 = 0 ;
T_5 V_267 = 0 ;
void T_2 * V_268 ;
if ( F_58 ( V_5 ) != TRUE ) {
F_9 ( V_5 , V_22 , 0 , 0 , L_66 ) ;
return - V_77 ;
}
F_9 ( V_5 , V_34 , V_35 , V_36 , L_67 ) ;
if ( F_25 ( & V_53 , V_49 , sizeof( T_7 ) ) )
return - V_44 ;
if ( F_25 ( & V_262 , V_53 . V_78 , sizeof( T_27 ) ) )
return - V_44 ;
F_9 ( V_5 , V_34 , V_35 , V_36 , L_68 , V_262 . V_269 ) ;
F_9 ( V_5 , V_34 , V_35 , V_36 , L_69 , V_262 . V_270 ) ;
F_9 ( V_5 , V_34 , V_35 , V_36 , L_70 , V_262 . V_271 ) ;
F_9 ( V_5 , V_34 , V_35 , V_36 , L_71 , V_262 . V_258 ) ;
if ( F_68 ( V_5 , & V_262 ) == FALSE )
return V_51 ;
V_264 = V_262 . V_271 ;
if ( V_264 > V_5 -> V_230 )
V_265 = V_5 -> V_230 ;
else
V_265 = V_264 ;
V_267 = V_262 . V_270 ;
V_268 = V_53 . V_82 ;
V_263 = ( T_9 ) F_3 ( V_265 , V_9 ) ;
if ( V_263 == NULL ) {
F_9 ( V_5 , V_22 , 0 , 0 , L_72 ) ;
return - V_10 ;
}
F_4 ( & V_5 -> V_146 ) ;
if ( ( V_5 -> V_97 == TRUE ) ||
( V_5 -> V_98 == TRUE ) ||
( V_5 -> V_99 == TRUE ) ) {
F_9 ( V_5 , V_34 , V_35 , V_36 , L_58 ) ;
F_5 ( & V_5 -> V_146 ) ;
F_12 ( V_263 ) ;
return - V_39 ;
}
while ( V_264 ) {
if ( V_264 > V_5 -> V_230 )
V_266 = V_5 -> V_230 ;
else
V_266 = V_264 ;
V_50 = F_69 ( V_5 , ( V_81 ) V_263 , V_262 . V_269 , V_267 , V_266 ) ;
if ( V_50 ) {
F_9 ( V_5 , V_34 , V_35 , V_36 , L_73 , V_50 ) ;
break;
}
F_70 ( V_5 , V_34 , V_35 , V_36 , V_263 , V_266 ) ;
V_50 = F_16 ( V_268 , V_263 , V_266 ) ;
if ( V_50 ) {
F_9 ( V_5 , V_34 , V_35 , V_36 , L_74 , V_50 ) ;
F_5 ( & V_5 -> V_146 ) ;
F_12 ( V_263 ) ;
return - V_44 ;
}
V_264 = V_264 - V_266 ;
if ( V_264 ) {
V_267 = V_267 + V_266 ;
V_268 = V_268 + V_266 ;
}
}
F_5 ( & V_5 -> V_146 ) ;
F_12 ( V_263 ) ;
}
break;
case V_272 : {
T_27 V_273 = { 0 } ;
T_26 V_274 ;
void T_2 * V_275 ;
T_5 V_264 = 0 ;
T_5 V_265 = 0 ;
T_5 V_276 = 0 ;
T_5 V_277 = 0 ;
if ( F_58 ( V_5 ) != TRUE ) {
F_9 ( V_5 , V_22 , 0 , 0 , L_66 ) ;
return - V_77 ;
}
V_5 -> V_278 = FALSE ;
F_9 ( V_5 , V_34 , V_35 , V_36 , L_75 ) ;
if ( F_25 ( & V_53 , V_49 , sizeof( T_7 ) ) )
return - V_44 ;
if ( F_25 ( & V_273 , V_53 . V_78 , sizeof( T_27 ) ) )
return - V_44 ;
F_9 ( V_5 , V_34 , V_35 , V_36 , L_68 , V_273 . V_269 ) ;
F_9 ( V_5 , V_34 , V_35 , V_36 , L_76 , V_273 . V_270 ) ;
F_9 ( V_5 , V_34 , V_35 , V_36 , L_70 , V_273 . V_271 ) ;
F_9 ( V_5 , V_34 , V_35 , V_36 , L_71 , V_273 . V_258 ) ;
if ( ( V_273 . V_269 != V_279 ) && ( V_273 . V_269 != V_280 ) && ( V_273 . V_269 != V_281 ) ) {
F_9 ( V_5 , V_34 , V_35 , V_36 , L_77 ) ;
return - V_77 ;
}
if ( F_68 ( V_5 , & V_273 ) == FALSE )
return V_51 ;
V_275 = V_273 . V_282 ;
V_276 = V_273 . V_270 ;
V_264 = V_273 . V_271 ;
if ( V_264 > V_5 -> V_230 )
V_265 = V_5 -> V_230 ;
else
V_265 = V_264 ;
V_274 = F_26 ( V_265 , V_9 ) ;
if ( V_274 == NULL )
return - V_10 ;
V_277 = V_5 -> V_230 ;
if ( V_276 % V_5 -> V_230 )
V_277 = V_5 -> V_230 - ( V_276 % V_5 -> V_230 ) ;
if ( V_264 < V_277 )
V_277 = V_264 ;
F_4 ( & V_5 -> V_146 ) ;
if ( ( V_5 -> V_97 == TRUE ) ||
( V_5 -> V_98 == TRUE ) ||
( V_5 -> V_99 == TRUE ) ) {
F_9 ( V_5 , V_34 , V_35 , V_36 , L_58 ) ;
F_5 ( & V_5 -> V_146 ) ;
F_12 ( V_274 ) ;
return - V_39 ;
}
F_64 ( V_5 , V_273 . V_269 ) ;
do {
V_50 = F_25 ( V_274 , V_275 , V_277 ) ;
if ( V_50 ) {
F_9 ( V_5 , V_22 , 0 , 0 , L_78 , V_50 ) ;
F_5 ( & V_5 -> V_146 ) ;
F_12 ( V_274 ) ;
return - V_44 ;
}
F_70 ( V_5 , V_34 , V_35 , V_36 , V_274 , V_277 ) ;
V_50 = F_71 ( V_5 , ( V_81 ) V_274 , V_273 . V_269 , V_276 , V_277 , V_273 . V_258 ) ;
if ( V_50 ) {
F_9 ( V_5 , V_22 , 0 , 0 , L_73 , V_50 ) ;
break;
}
V_264 = V_264 - V_277 ;
if ( V_264 ) {
V_276 = V_276 + V_277 ;
V_275 = V_275 + V_277 ;
if ( V_264 > V_5 -> V_230 )
V_277 = V_5 -> V_230 ;
else
V_277 = V_264 ;
}
} while ( V_264 > 0 );
F_67 ( V_5 , V_273 . V_269 ) ;
F_5 ( & V_5 -> V_146 ) ;
F_12 ( V_274 ) ;
}
break;
case V_283 : {
T_28 V_284 ;
F_9 ( V_5 , V_34 , V_35 , V_36 , L_79 ) ;
if ( F_25 ( & V_53 , V_49 , sizeof( T_7 ) ) )
return - V_44 ;
if ( V_53 . V_79 != sizeof( V_285 ) )
return - V_77 ;
V_284 = F_3 ( sizeof( V_285 ) , V_9 ) ;
if ( V_284 == NULL ) {
F_9 ( V_5 , V_22 , 0 , 0 , L_80 ) ;
return - V_10 ;
}
F_4 ( & V_5 -> V_146 ) ;
if ( ( V_5 -> V_97 == TRUE ) ||
( V_5 -> V_98 == TRUE ) ||
( V_5 -> V_99 == TRUE ) ) {
F_9 ( V_5 , V_34 , V_35 , V_36 , L_58 ) ;
F_5 ( & V_5 -> V_146 ) ;
F_12 ( V_284 ) ;
return - V_39 ;
}
F_72 ( V_5 , V_284 ) ;
F_5 ( & V_5 -> V_146 ) ;
if ( F_16 ( V_53 . V_82 , V_284 , sizeof( V_285 ) ) ) {
F_12 ( V_284 ) ;
return - V_44 ;
}
F_12 ( V_284 ) ;
}
break;
case V_286 : {
T_29 V_287 = 0 ;
F_9 ( V_5 , V_34 , V_35 , V_36 , L_81 ) ;
if ( F_58 ( V_5 ) != TRUE ) {
F_9 ( V_5 , V_22 , 0 , 0 , L_66 ) ;
return - V_77 ;
}
V_50 = F_25 ( & V_53 , V_49 , sizeof( T_7 ) ) ;
if ( V_50 ) {
F_9 ( V_5 , V_22 , 0 , 0 , L_82 ) ;
return - V_44 ;
}
V_50 = F_25 ( & V_287 , V_53 . V_78 , sizeof( INT ) ) ;
if ( V_50 ) {
F_9 ( V_5 , V_22 , 0 , 0 , L_83 ) ;
return - V_44 ;
}
F_4 ( & V_5 -> V_146 ) ;
if ( ( V_5 -> V_97 == TRUE ) ||
( V_5 -> V_98 == TRUE ) ||
( V_5 -> V_99 == TRUE ) ) {
F_9 ( V_5 , V_34 , V_35 , V_36 , L_58 ) ;
F_5 ( & V_5 -> V_146 ) ;
return - V_39 ;
}
V_50 = F_73 ( V_5 , V_287 ) ;
if ( V_50 )
F_9 ( V_5 , V_22 , 0 , 0 , L_84 , V_50 ) ;
F_5 ( & V_5 -> V_146 ) ;
}
break;
case V_288 : {
V_5 -> V_278 = FALSE ;
F_9 ( V_5 , V_34 , V_35 , V_36 , L_85 ) ;
V_50 = V_61 ;
}
break;
case V_289 : {
T_30 V_290 = { 0 } ;
V_50 = V_61 ;
F_9 ( V_5 , V_34 , V_35 , V_36 , L_86 ) ;
V_5 -> V_278 = FALSE ;
if ( F_58 ( V_5 ) != TRUE ) {
F_9 ( V_5 , V_22 , 0 , 0 , L_66 ) ;
return - V_77 ;
}
V_50 = F_25 ( & V_53 , V_49 , sizeof( T_7 ) ) ;
if ( V_50 ) {
F_9 ( V_5 , V_22 , 0 , 0 , L_87 , V_50 ) ;
return - V_44 ;
}
V_50 = F_25 ( & V_290 , V_53 . V_78 , sizeof( T_30 ) ) ;
if ( V_50 ) {
F_9 ( V_5 , V_22 , 0 , 0 , L_88 , V_50 ) ;
return - V_44 ;
}
F_9 ( V_5 , V_34 , V_35 , V_36 , L_89 , V_290 . V_291 ) ;
F_9 ( V_5 , V_34 , V_35 , V_36 , L_90 , V_290 . V_292 ) ;
F_9 ( V_5 , V_34 , V_35 , V_36 , L_91 , V_290 . V_270 ) ;
F_9 ( V_5 , V_34 , V_35 , V_36 , L_92 , V_290 . V_271 ) ;
if ( F_74 ( V_5 , V_290 . V_291 ) == FALSE ) {
F_9 ( V_5 , V_22 , 0 , 0 , L_93 , V_290 . V_291 ) ;
return - V_77 ;
}
if ( F_74 ( V_5 , V_290 . V_292 ) == FALSE ) {
F_9 ( V_5 , V_22 , 0 , 0 , L_94 , V_290 . V_292 ) ;
return - V_77 ;
}
if ( V_290 . V_291 == V_290 . V_292 ) {
F_9 ( V_5 , V_34 , V_35 , V_36 , L_95 ) ;
return - V_77 ;
}
F_4 ( & V_5 -> V_146 ) ;
if ( ( V_5 -> V_97 == TRUE ) ||
( V_5 -> V_98 == TRUE ) ||
( V_5 -> V_99 == TRUE ) ) {
F_9 ( V_5 , V_34 , V_35 , V_36 , L_58 ) ;
F_5 ( & V_5 -> V_146 ) ;
return - V_39 ;
}
if ( V_290 . V_291 == V_293 || V_290 . V_291 == V_294 ) {
if ( F_75 ( V_5 ) ) {
F_9 ( V_5 , V_22 , 0 , 0 , L_96 ) ;
V_50 = - V_77 ;
} else if ( V_290 . V_271 == 0 ) {
V_50 = F_76 ( V_5 , V_290 ) ;
} else {
F_9 ( V_5 , V_22 , 0 , 0 , L_97 ) ;
V_50 = V_51 ;
}
F_5 ( & V_5 -> V_146 ) ;
return V_50 ;
}
V_50 = F_77 ( V_5 , V_290 . V_291 ,
V_290 . V_292 , V_290 . V_270 , V_290 . V_271 ) ;
F_5 ( & V_5 -> V_146 ) ;
}
break;
case V_295 : {
V_50 = V_61 ;
F_9 ( V_5 , V_34 , V_35 , V_36 , L_98 ) ;
V_50 = F_25 ( & V_53 , V_49 , sizeof( T_7 ) ) ;
if ( V_50 ) {
F_9 ( V_5 , V_22 , 0 , 0 , L_82 ) ;
return - V_44 ;
}
if ( V_5 -> V_225 != V_227 ) {
F_9 ( V_5 , V_22 , 0 , 0 , L_99 ) ;
V_50 = - V_77 ;
break;
}
if ( F_58 ( V_5 ) == TRUE ) {
if ( V_53 . V_79 < sizeof( V_296 ) )
return - V_77 ;
if ( F_16 ( V_53 . V_82 , V_5 -> V_297 , sizeof( V_296 ) ) )
return - V_44 ;
} else {
if ( V_53 . V_79 < sizeof( V_298 ) )
return - V_77 ;
if ( F_16 ( V_53 . V_82 , V_5 -> V_299 , sizeof( V_298 ) ) )
return - V_44 ;
}
}
break;
case V_300 : {
T_5 V_301 = 0 ;
T_29 V_287 ;
V_287 = V_302 ;
F_9 ( V_5 , V_34 , V_35 , V_36 , L_100 ) ;
if ( F_58 ( V_5 ) != TRUE ) {
F_9 ( V_5 , V_22 , 0 , 0 , L_66 ) ;
return - V_77 ;
}
V_50 = F_25 ( & V_53 , V_49 , sizeof( T_7 ) ) ;
if ( V_50 ) {
F_9 ( V_5 , V_22 , 0 , 0 , L_82 ) ;
return - V_44 ;
}
V_50 = F_25 ( & V_287 , V_53 . V_78 , sizeof( INT ) ) ;
if ( V_50 ) {
F_9 ( V_5 , V_22 , 0 , 0 , L_83 ) ;
return - V_44 ;
}
F_9 ( V_5 , V_34 , V_35 , V_36 , L_101 , V_287 ) ;
if ( ( V_287 != V_249 ) &&
( V_287 != V_250 ) &&
( V_287 != V_251 ) ) {
F_9 ( V_5 , V_22 , 0 , 0 , L_102 , V_287 ) ;
return V_51 ;
}
V_301 = F_78 ( V_5 , V_287 ) ;
if ( V_301 == V_303 ) {
F_9 ( V_5 , V_22 , 0 , 0 , L_103 , V_287 ) ;
return - V_77 ;
}
V_5 -> V_278 = TRUE ;
V_5 -> V_304 = V_301 ;
V_5 -> V_248 = V_287 ;
}
V_50 = V_61 ;
break;
case V_305 : {
T_25 V_306 ;
INT V_264 ;
INT V_265 ;
INT V_267 = 0 ;
T_5 V_266 = 0 ;
T_26 V_263 ;
void T_2 * V_268 ;
if ( V_5 -> V_225 != V_227 ) {
F_9 ( V_5 , V_22 , 0 , 0 , L_104 ) ;
return - V_77 ;
}
if ( F_25 ( & V_53 , V_49 , sizeof( T_7 ) ) ) {
F_9 ( V_5 , V_22 , 0 , 0 , L_105 ) ;
return - V_44 ;
}
if ( F_25 ( & V_306 , V_53 . V_82 , sizeof( T_25 ) ) )
return - V_44 ;
V_264 = V_306 . V_252 ;
if ( V_264 > V_307 )
V_265 = V_307 ;
else
V_265 = V_264 ;
V_267 = V_306 . V_253 ;
V_268 = V_306 . V_254 ;
V_263 = F_3 ( V_265 , V_9 ) ;
if ( V_263 == NULL ) {
F_9 ( V_5 , V_22 , 0 , 0 , L_72 ) ;
V_50 = - V_10 ;
break;
}
F_4 ( & V_5 -> V_146 ) ;
if ( ( V_5 -> V_97 == TRUE ) ||
( V_5 -> V_98 == TRUE ) ||
( V_5 -> V_99 == TRUE ) ) {
F_9 ( V_5 , V_34 , V_35 , V_36 , L_58 ) ;
F_12 ( V_263 ) ;
F_5 ( & V_5 -> V_146 ) ;
return - V_39 ;
}
V_5 -> V_308 = TRUE ;
while ( V_264 ) {
if ( V_264 > V_307 )
V_266 = V_307 ;
else
V_266 = V_264 ;
V_50 = F_63 ( V_5 , ( V_81 ) V_263 , V_267 , V_266 ) ;
if ( V_50 ) {
F_9 ( V_5 , V_22 , 0 , 0 , L_73 , V_50 ) ;
break;
}
F_70 ( V_5 , V_34 , V_35 , V_36 , V_263 , V_266 ) ;
V_50 = F_16 ( V_268 , V_263 , V_266 ) ;
if ( V_50 ) {
F_9 ( V_5 , V_22 , 0 , 0 , L_74 , V_50 ) ;
F_5 ( & V_5 -> V_146 ) ;
F_12 ( V_263 ) ;
return - V_44 ;
}
V_264 = V_264 - V_266 ;
if ( V_264 ) {
V_267 = V_267 + V_266 ;
V_268 = V_268 + V_266 ;
}
}
V_5 -> V_308 = FALSE ;
F_5 ( & V_5 -> V_146 ) ;
F_12 ( V_263 ) ;
break;
}
case V_309 : {
T_6 V_11 = 0 ;
V_50 = F_25 ( & V_53 , V_49 , sizeof( T_7 ) ) ;
if ( V_50 ) {
F_9 ( V_5 , V_34 , V_35 , V_36 , L_106 ) ;
return - V_44 ;
}
if ( V_53 . V_76 != sizeof( unsigned long ) ) {
V_50 = - V_77 ;
break;
}
V_50 = F_25 ( & V_11 , V_53 . V_78 , V_53 . V_76 ) ;
if ( V_50 ) {
F_9 ( V_5 , V_34 , V_35 , V_36 , L_107 ) ;
return - V_44 ;
}
F_9 ( V_5 , V_34 , V_35 , V_36 , L_108 , V_11 ) ;
V_7 -> V_11 = V_11 ;
}
break;
case V_310 : {
T_31 V_311 ;
F_9 ( V_5 , V_34 , V_35 , V_36 , L_109 ) ;
V_311 . V_312 = V_313 ;
V_311 . V_314 = V_315 ;
V_311 . V_316 = 0 ;
V_311 . V_317 = V_5 -> V_225 ;
V_311 . V_318 = V_319 ;
if ( F_25 ( & V_53 , V_49 , sizeof( T_7 ) ) )
return - V_44 ;
if ( V_53 . V_79 < sizeof( V_311 ) )
return - V_77 ;
if ( F_16 ( V_53 . V_82 , & V_311 , sizeof( V_311 ) ) )
return - V_44 ;
}
break;
case V_320 : {
T_32 V_321 = { 0 } ;
F_9 ( V_5 , V_34 , V_35 , V_36 , L_110 ) ;
if ( F_25 ( & V_53 , V_49 , sizeof( T_7 ) ) )
return - V_44 ;
if ( V_53 . V_79 < sizeof( T_32 ) )
return - V_77 ;
V_321 . V_322 = F_79 () - V_5 -> V_323 ;
if ( F_16 ( V_53 . V_82 , & V_321 , sizeof( T_32 ) ) )
return - V_44 ;
}
break;
case V_324 :
F_9 ( V_5 , V_34 , V_35 , V_36 , L_111 ) ;
break;
default:
F_80 ( V_325 L_112 , V_47 ) ;
V_50 = V_51 ;
break;
}
return V_50 ;
}
int F_81 ( struct V_4 * V_5 )
{
if ( V_5 -> V_326 > 0 )
return V_5 -> V_326 ;
V_5 -> V_326 = F_82 ( 0 , V_327 , & V_328 ) ;
if ( V_5 -> V_326 < 0 ) {
F_42 ( V_325 L_113 ) ;
return V_5 -> V_326 ;
}
V_5 -> V_329 = F_83 ( V_330 , NULL ,
F_84 ( V_5 -> V_326 , 0 ) ,
V_5 , V_327 ) ;
if ( F_34 ( V_5 -> V_329 ) ) {
F_42 ( V_325 L_114 ) ;
F_85 ( V_5 -> V_326 , V_327 ) ;
return F_35 ( V_5 -> V_329 ) ;
}
return 0 ;
}
void F_86 ( struct V_4 * V_5 )
{
if ( V_5 -> V_326 > 0 ) {
F_87 ( V_330 , F_84 ( V_5 -> V_326 , 0 ) ) ;
F_85 ( V_5 -> V_326 , V_327 ) ;
}
}
