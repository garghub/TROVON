static int F_1 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
T_1 V_4 = NULL ;
T_2 V_5 = NULL ;
V_4 = F_2 ( V_6 ) ;
V_5 = F_3 ( sizeof( V_7 ) , V_8 ) ;
if ( ! V_5 )
return - V_9 ;
V_5 -> V_4 = V_4 ;
V_5 -> V_10 = 0xFFFFFFFF & ~ ( 1 << 0xB ) ;
F_4 ( & V_4 -> V_11 ) ;
V_5 -> V_12 = V_4 -> V_13 ;
V_4 -> V_13 = V_5 ;
F_5 ( & V_4 -> V_11 ) ;
V_3 -> V_14 = V_5 ;
F_6 ( & V_4 -> V_15 ) ;
F_7 ( V_1 , V_3 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
T_2 V_5 , V_16 , V_17 ;
T_1 V_4 = NULL ;
struct V_18 * V_19 , * V_20 ;
V_5 = ( T_2 ) V_3 -> V_14 ;
if ( V_5 == NULL ) {
F_9 ( V_4 , V_21 , 0 , 0 ,
L_1 ) ;
return 0 ;
}
V_4 = V_5 -> V_4 ;
F_4 ( & V_4 -> V_11 ) ;
V_16 = V_4 -> V_13 ;
for ( V_17 = NULL ; V_16 ; V_17 = V_16 , V_16 = V_16 -> V_12 ) {
if ( V_16 == V_5 )
break;
}
if ( V_16 ) {
if ( ! V_17 )
V_4 -> V_13 = V_16 -> V_12 ;
else
V_17 -> V_12 = V_16 -> V_12 ;
} else {
F_5 ( & V_4 -> V_11 ) ;
return 0 ;
}
V_19 = V_5 -> V_22 ;
while ( V_19 ) {
V_20 = V_19 -> V_12 ;
F_10 ( V_19 ) ;
V_19 = V_20 ;
}
F_5 ( & V_4 -> V_11 ) ;
F_11 ( & V_4 -> V_15 ) ;
F_12 ( V_5 ) ;
V_3 -> V_14 = NULL ;
return 0 ;
}
static T_3 F_13 ( struct V_2 * V_3 , char T_4 * V_23 , T_5 V_24 ,
T_6 * V_25 )
{
T_2 V_5 = V_3 -> V_14 ;
T_1 V_4 = V_5 -> V_4 ;
struct V_18 * V_26 = NULL ;
T_3 V_27 = 0 ;
int V_28 = 0 ;
unsigned long V_29 = 0 ;
V_28 = F_14 ( V_4 -> V_30 ,
( V_5 -> V_22 ||
V_4 -> V_31 ) ) ;
if ( ( V_28 == - V_32 ) ) {
F_9 ( V_4 , V_33 , V_34 , V_35 ,
L_2 ) ;
return V_28 ;
}
if ( V_4 -> V_31 ) {
F_9 ( V_4 , V_33 , V_34 , V_35 ,
L_3 ) ;
return - V_36 ;
}
if ( FALSE == V_4 -> V_37 )
return - V_38 ;
F_4 ( & V_4 -> V_11 ) ;
if ( V_5 -> V_22 ) {
V_26 = V_5 -> V_22 ;
F_15 ( V_5 -> V_22 ,
V_5 -> V_39 ) ;
V_5 -> V_40 -- ;
}
F_5 ( & V_4 -> V_11 ) ;
if ( V_26 ) {
V_27 = V_26 -> V_41 ;
V_29 = F_16 ( V_23 , V_26 -> V_42 ,
F_17 ( T_5 , V_27 , V_24 ) ) ;
if ( V_29 ) {
F_18 ( V_26 ) ;
F_9 ( V_4 , V_21 , 0 , 0 ,
L_4 ) ;
return - V_43 ;
}
F_9 ( V_4 , V_33 , V_34 , V_35 ,
L_5 ,
V_27 , V_26 , V_44 -> V_45 ) ;
F_18 ( V_26 ) ;
}
F_9 ( V_4 , V_33 , V_34 , V_35 , L_6 ) ;
return V_27 ;
}
static long F_19 ( struct V_2 * V_3 , T_7 V_46 , T_8 V_47 )
{
T_2 V_5 = V_3 -> V_14 ;
void T_4 * V_48 = ( void T_4 * ) V_47 ;
T_1 V_4 = V_5 -> V_4 ;
INT V_49 = V_50 ;
int V_51 = 0 ;
T_9 V_52 ;
F_9 ( V_4 , V_33 , V_34 , V_35 , L_7 , V_46 , V_47 ) ;
if( F_20 ( V_46 ) != V_53 )
return - V_43 ;
if( F_21 ( V_46 ) & V_54 )
V_49 = ! F_22 ( V_55 , V_48 , F_23 ( V_46 ) ) ;
else if ( F_21 ( V_46 ) & V_56 )
V_49 = ! F_22 ( V_57 , V_48 , F_23 ( V_46 ) ) ;
else if ( V_58 == ( F_21 ( V_46 ) & V_58 ) )
V_49 = V_59 ;
if( V_49 )
return - V_43 ;
if( V_4 -> V_31 )
{
return - V_43 ;
}
if( FALSE == V_4 -> V_37 )
{
switch ( V_46 )
{
case V_60 :
case V_61 :
case V_62 :
case V_63 :
case V_64 :
case V_65 :
case V_66 :
case V_67 :
return - V_38 ;
default:
break;
}
}
V_49 = F_24 ( V_4 , V_46 , V_47 ) ;
if( V_49 != V_68 )
return V_49 ;
switch( V_46 ) {
case V_69 :
{
T_10 V_70 = { 0 } ;
T_11 V_71 ;
T_7 V_72 ;
if( F_25 ( & V_52 , V_48 , sizeof( T_9 ) ) )
return - V_43 ;
if ( V_52 . V_73 > sizeof( V_70 ) )
return - V_74 ;
if( F_25 ( & V_70 , V_52 . V_75 , V_52 . V_73 ) )
return - V_43 ;
V_72 = V_52 . V_76 + ( 4 - V_52 . V_76 % 4 ) % 4 ;
V_71 = F_26 ( V_72 , V_8 ) ;
if( ! V_71 )
return - V_9 ;
V_49 = F_27 ( V_4 , ( T_7 ) V_70 . Register ,
( V_77 ) V_71 , V_72 ) ;
if( V_49 == V_59 )
{
if( F_16 ( V_52 . V_78 , V_71 , V_52 . V_76 ) )
V_49 = - V_43 ;
}
F_12 ( V_71 ) ;
break;
}
case V_79 :
{
T_12 V_80 = { 0 } ;
T_7 V_81 = 0 ;
if( F_25 ( & V_52 , V_48 , sizeof( T_9 ) ) )
return - V_43 ;
if ( V_52 . V_73 > sizeof( V_80 ) )
return - V_74 ;
if( F_25 ( & V_80 , V_52 . V_75 , V_52 . V_73 ) )
return - V_43 ;
V_81 = V_80 . Register & V_82 ;
if( ! ( ( V_4 -> V_83 -> V_84 ) & V_85 ) &&
( ( V_81 == V_86 ) ||
( V_81 == V_87 ) ||
( V_81 == V_88 ) ||
( V_81 == V_89 ) ) )
{
F_9 ( V_4 , V_21 , 0 , 0 , L_8 ) ;
return - V_43 ;
}
V_49 = F_28 ( V_4 , ( T_7 ) V_80 . Register ,
( V_77 ) V_80 . V_90 , sizeof( T_8 ) ) ;
if( V_49 == V_59 )
{
F_9 ( V_4 , V_33 , V_34 , V_35 , L_9 ) ;
}
else
{
F_9 ( V_4 , V_33 , V_34 , V_35 , L_10 ) ;
V_49 = - V_43 ;
}
break;
}
case V_91 :
case V_92 :
{
T_10 V_70 = { 0 } ;
T_11 V_71 = NULL ;
T_7 V_81 = 0 ;
if( ( V_4 -> V_93 == TRUE ) ||
( V_4 -> V_94 == TRUE ) ||
( V_4 -> V_95 == TRUE ) )
{
F_9 ( V_4 , V_21 , 0 , 0 , L_11 ) ;
return - V_38 ;
}
if( F_25 ( & V_52 , V_48 , sizeof( T_9 ) ) )
return - V_43 ;
if ( V_52 . V_73 > sizeof( V_70 ) )
return - V_74 ;
if( F_25 ( & V_70 , V_52 . V_75 , V_52 . V_73 ) )
return - V_43 ;
V_71 = F_26 ( V_52 . V_76 , V_8 ) ;
if( ! V_71 )
return V_50 ;
if( ( ( ( T_8 ) V_70 . Register & 0x0F000000 ) != 0x0F000000 ) ||
( ( T_8 ) V_70 . Register & 0x3 ) )
{
F_9 ( V_4 , V_21 , 0 , 0 , L_12 ,
( int ) V_70 . Register ) ;
return - V_74 ;
}
V_81 = V_70 . Register & V_82 ;
V_49 = F_29 ( V_4 , ( T_7 ) V_70 . Register ,
( V_77 ) V_71 , V_52 . V_76 ) ;
if( V_49 == V_59 )
if( F_16 ( V_52 . V_78 , V_71 , V_52 . V_76 ) )
V_49 = - V_43 ;
F_12 ( V_71 ) ;
break;
}
case V_96 :
case V_97 :
{
T_12 V_80 = { 0 } ;
T_7 V_81 = 0 ;
if( ( V_4 -> V_93 == TRUE ) ||
( V_4 -> V_94 == TRUE ) ||
( V_4 -> V_95 == TRUE ) )
{
F_9 ( V_4 , V_21 , 0 , 0 , L_13 ) ;
return - V_38 ;
}
if( F_25 ( & V_52 , V_48 , sizeof( T_9 ) ) )
return - V_43 ;
if ( V_52 . V_73 > sizeof( V_80 ) )
return - V_74 ;
if( F_25 ( & V_80 , V_52 . V_75 , V_52 . V_73 ) )
return - V_43 ;
if( ( ( ( T_8 ) V_80 . Register & 0x0F000000 ) != 0x0F000000 ) ||
( ( T_8 ) V_80 . Register & 0x3 ) )
{
F_9 ( V_4 , V_21 , 0 , 0 , L_14 ,
( int ) V_80 . Register ) ;
return - V_74 ;
}
V_81 = V_80 . Register & V_82 ;
if( ! ( ( V_4 -> V_83 -> V_84 ) & V_85 ) &&
( ( V_81 == V_86 ) ||
( V_81 == V_87 ) ||
( V_81 == V_88 ) ||
( V_81 == V_89 ) ) &&
( V_46 == V_96 ) )
{
F_9 ( V_4 , V_21 , 0 , 0 , L_8 ) ;
return - V_43 ;
}
V_49 = F_30 ( V_4 , ( T_7 ) V_80 . Register ,
( V_77 ) V_80 . V_90 , V_80 . V_98 ) ;
if( V_49 == V_59 )
{
F_9 ( V_4 , V_21 , V_34 , V_35 , L_9 ) ;
}
else
{
F_9 ( V_4 , V_33 , V_34 , V_35 , L_10 ) ;
V_49 = - V_43 ;
}
break;
}
case V_66 :
{
T_13 V_99 [ 4 ] ;
T_7 V_100 = 0 ;
T_7 V_101 = 0 ;
T_7 V_102 = 0 ;
T_14 V_103 = { 0 } ;
if( ( V_4 -> V_93 == TRUE ) ||
( V_4 -> V_94 == TRUE ) ||
( V_4 -> V_95 == TRUE ) )
{
F_9 ( V_4 , V_33 , V_34 , V_35 , L_15 ) ;
return - V_38 ;
}
if( F_25 ( & V_52 , V_48 , sizeof( T_9 ) ) )
return - V_43 ;
if ( V_52 . V_73 > sizeof( V_103 ) )
return - V_74 ;
if( F_25 ( & V_103 , V_52 . V_75 , V_52 . V_73 ) )
return - V_43 ;
V_101 = V_103 . V_104 ;
V_102 = V_103 . V_105 ;
V_100 = ( 1 << V_101 ) ;
if( F_31 ( V_4 , V_100 ) == FALSE )
{
F_9 ( V_4 , V_33 , V_34 , V_35 , L_16 , V_100 ) ;
V_49 = - V_74 ;
break;
}
if( V_102 )
{
V_49 = F_30 ( V_4 , V_106 ,
( V_77 ) ( & V_100 ) , sizeof( T_7 ) ) ;
if( V_49 == V_59 )
{
F_9 ( V_4 , V_33 , V_34 , V_35 , L_17 ) ;
}
else
{
F_9 ( V_4 , V_33 , V_34 , V_35 , L_18 , V_101 ) ;
break;
}
}
else
{
V_49 = F_30 ( V_4 , V_107 ,
( V_77 ) ( & V_100 ) , sizeof( T_7 ) ) ;
if( V_49 == V_59 )
{
F_9 ( V_4 , V_33 , V_34 , V_35 , L_17 ) ;
}
else
{
F_9 ( V_4 , V_33 , V_34 , V_35 , L_19 , V_101 ) ;
break;
}
}
V_49 = F_29 ( V_4 , ( T_7 ) V_108 ,
( V_77 ) V_99 , sizeof( T_7 ) ) ;
if ( V_59 != V_49 )
{
F_9 ( V_4 , V_33 , V_34 , V_35 , L_20 ) ;
break;
}
* ( T_7 * ) V_99 |= ( 1 << V_101 ) ;
V_49 = F_30 ( V_4 , V_108 ,
( V_77 ) V_99 , sizeof( T_7 ) ) ;
if( V_49 == V_59 )
{
F_9 ( V_4 , V_33 , V_34 , V_35 , L_21 ) ;
}
else
{
F_9 ( V_4 , V_33 , V_34 , V_35 , L_22 ) ;
break;
}
}
break;
case V_109 :
{
T_15 V_110 = { 0 } ;
F_9 ( V_4 , V_33 , V_34 , V_35 , L_23 ) ;
if( ( V_4 -> V_93 == TRUE ) ||
( V_4 -> V_94 == TRUE ) ||
( V_4 -> V_95 == TRUE ) )
{
F_9 ( V_4 , V_33 , V_34 , V_35 , L_15 ) ;
V_49 = - V_38 ;
break;
}
if ( F_25 ( & V_52 , V_48 , sizeof( T_9 ) ) )
return - V_43 ;
if ( V_52 . V_73 > sizeof( V_110 ) )
return - V_74 ;
if ( F_25 ( & V_110 , V_52 . V_75 , V_52 . V_73 ) )
return - V_43 ;
if( V_4 -> V_111 . V_112 )
{
if( V_110 . V_113 == V_114 )
{
F_9 ( V_4 , V_33 , V_34 , V_35 , L_24 ) ;
V_4 -> V_115 = V_116 ;
}
else
{
F_9 ( V_4 , V_33 , V_34 , V_35 , L_25 ) ;
V_4 -> V_115 = V_117 ;
}
F_32 ( & V_4 -> V_111 . V_118 ) ;
}
}
break;
case V_67 :
{
T_8 V_101 = 0 ;
T_13 V_119 [ 4 ] ;
T_14 V_103 = { 0 } ;
if( ( V_4 -> V_93 == TRUE ) ||
( V_4 -> V_94 == TRUE ) ||
( V_4 -> V_95 == TRUE ) )
return - V_38 ;
if( F_25 ( & V_52 , V_48 , sizeof( T_9 ) ) )
return - V_43 ;
if ( V_52 . V_73 > sizeof( V_103 ) )
return - V_74 ;
if( F_25 ( & V_103 , V_52 . V_75 , V_52 . V_73 ) )
return - V_43 ;
V_101 = V_103 . V_104 ;
V_49 = F_29 ( V_4 , ( T_7 ) V_120 ,
( V_77 ) V_119 , sizeof( T_7 ) ) ;
if( V_49 != V_59 )
{
F_9 ( V_4 , V_21 , 0 , 0 , L_26 ) ;
return V_49 ;
}
}
break;
case V_121 :
{
T_13 V_99 [ 4 ] ;
T_16 V_122 [ V_123 ] ;
T_17 V_124 = ( T_17 ) V_122 ;
memset ( V_124 , 0 , V_123 * sizeof( T_16 ) ) ;
if( ( V_4 -> V_93 == TRUE ) ||
( V_4 -> V_94 == TRUE ) ||
( V_4 -> V_95 == TRUE ) )
return - V_74 ;
if ( F_25 ( & V_52 , V_48 , sizeof( T_9 ) ) )
return - V_43 ;
if ( V_52 . V_73 > sizeof( V_122 ) )
return - V_74 ;
if ( F_25 ( & V_122 , V_52 . V_75 , V_52 . V_73 ) )
return - V_43 ;
if( F_31 ( V_4 , V_124 [ V_125 ] . V_126 ) == FALSE )
{
F_9 ( V_4 , V_33 , V_34 , V_35 , L_27 , V_124 [ V_125 ] . V_126 , V_4 -> V_127 ) ;
V_49 = - V_74 ;
break;
}
if( ( V_124 [ V_125 ] . V_126 ) &
( V_124 [ V_125 ] . V_128 ) )
{
* ( T_7 * ) V_99 = V_124 [ V_125 ] . V_126 &
V_124 [ V_125 ] . V_128 &
V_124 [ V_125 ] . V_129 ;
if( * ( T_7 * ) V_99 )
V_49 = F_30 ( V_4 , V_106 , ( V_77 ) V_99 , sizeof( T_8 ) ) ;
if( V_49 != V_59 )
{
F_9 ( V_4 , V_21 , 0 , 0 , L_28 ) ;
return V_49 ;
}
* ( T_7 * ) V_99 = ( V_124 [ V_125 ] . V_126 &
V_124 [ V_125 ] . V_128 &
( ~ ( V_124 [ V_125 ] . V_129 ) ) ) ;
if( * ( T_7 * ) V_99 )
V_49 = F_30 ( V_4 , V_107 , ( V_77 ) V_99 , sizeof( T_8 ) ) ;
if( V_49 != V_59 )
{
F_9 ( V_4 , V_21 , 0 , 0 , L_29 ) ;
return V_49 ;
}
}
if( V_124 [ V_125 ] . V_126 )
{
V_49 = F_29 ( V_4 , ( T_7 ) V_120 , ( V_77 ) V_99 , sizeof( T_7 ) ) ;
if( V_49 != V_59 )
{
F_9 ( V_4 , V_21 , 0 , 0 , L_30 ) ;
return V_49 ;
}
V_124 [ V_125 ] . V_129 = ( * ( T_7 * ) V_99 &
V_124 [ V_125 ] . V_126 ) ;
}
V_49 = F_16 ( V_52 . V_78 , & V_122 , V_52 . V_76 ) ;
if( V_49 )
{
F_9 ( V_4 , V_21 , 0 , 0 , L_31 , V_49 ) ;
break;
}
}
break;
case V_130 :
{
T_13 V_99 [ 4 ] ;
T_18 V_131 [ V_123 ] ;
T_19 V_132 = ( T_19 ) V_131 ;
if( ( V_4 -> V_93 == TRUE ) ||
( V_4 -> V_94 == TRUE ) ||
( V_4 -> V_95 == TRUE ) )
return - V_74 ;
if ( F_25 ( & V_52 , V_48 , sizeof( T_9 ) ) )
return - V_43 ;
if ( V_52 . V_73 > sizeof( V_131 ) )
return - V_74 ;
if ( F_25 ( & V_131 , V_52 . V_75 , V_52 . V_73 ) )
return - V_43 ;
V_49 = F_29 ( V_4 , ( T_7 ) V_108 , ( V_77 ) V_99 , sizeof( T_7 ) ) ;
if( V_59 != V_49 )
{
F_9 ( V_4 , V_21 , 0 , 0 , L_32 ) ;
return V_49 ;
}
if( F_31 ( V_4 , V_132 [ V_125 ] . V_126 ) == FALSE )
{
F_9 ( V_4 , V_33 , V_34 , V_35 , L_27 , V_132 [ V_125 ] . V_126 , V_4 -> V_127 ) ;
V_49 = - V_74 ;
break;
}
if( V_132 [ V_125 ] . V_126 )
{
* ( T_7 * ) V_99 |= ( V_132 [ V_125 ] . V_133 &
V_132 [ V_125 ] . V_126 ) ;
* ( T_7 * ) V_99 &= ~ ( ( ~ V_132 [ V_125 ] . V_133 ) &
V_132 [ V_125 ] . V_126 ) ;
V_132 [ V_125 ] . V_133 = * ( T_7 * ) V_99 ;
V_49 = F_30 ( V_4 , V_108 , ( V_77 ) V_99 , sizeof( T_8 ) ) ;
if( V_49 == V_59 )
{
F_9 ( V_4 , V_33 , V_34 , V_35 , L_33 ) ;
}
else
{
F_9 ( V_4 , V_21 , 0 , 0 , L_34 ) ;
V_49 = - V_43 ;
break;
}
}
else
{
V_132 [ V_125 ] . V_133 = * ( T_7 * ) V_99 ;
}
V_49 = F_16 ( V_52 . V_78 , & V_131 , V_52 . V_76 ) ;
if( V_49 )
{
F_9 ( V_4 , V_21 , 0 , 0 , L_31 , V_49 ) ;
break;
}
}
break;
case V_60 :
case V_61 :
case V_62 :
case V_63 :
case V_64 :
case V_65 :
{
T_20 V_134 = NULL ;
if( F_25 ( & V_52 , V_48 , sizeof( T_9 ) ) )
return - V_43 ;
V_134 = F_26 ( V_52 . V_73 , V_8 ) ;
if( ! V_134 )
return - V_9 ;
if( F_25 ( V_134 , V_52 . V_75 , V_52 . V_73 ) )
{
V_49 = - V_43 ;
F_12 ( V_134 ) ;
break;
}
F_4 ( & V_4 -> V_135 ) ;
V_49 = F_33 ( V_4 -> V_136 ,
! V_4 -> V_95 ,
( 1 * V_137 ) ) ;
if( V_49 == - V_32 )
goto V_138;
if( V_4 -> V_95 )
{
F_9 ( V_4 , V_33 , V_34 , V_35 , L_35 ) ;
V_49 = V_50 ;
goto V_138 ;
}
V_49 = F_34 ( V_4 , ( T_20 ) V_134 ) ;
V_138:
F_5 ( & V_4 -> V_135 ) ;
F_12 ( V_134 ) ;
break;
}
case V_139 :
{
INT V_140 = F_35 ( & V_4 -> V_141 ) ;
if( V_140 )
{
F_9 ( V_4 , V_33 , V_34 , V_35 , L_36 ) ;
return - V_38 ;
}
F_9 ( V_4 , V_21 , 0 , 0 , L_37 , V_44 -> V_45 ) ;
if( ! F_35 ( & V_4 -> V_142 ) )
{
V_4 -> V_143 = FALSE ;
V_4 -> V_144 = V_44 -> V_45 ;
V_4 -> V_145 = FALSE ;
V_4 -> V_37 = FALSE ;
F_36 ( V_4 -> V_146 ) ;
F_37 ( V_4 -> V_146 ) ;
V_49 = F_38 ( V_4 ) ;
if( V_49 )
{
F_39 ( V_147 L_38 , V_4 -> V_146 -> V_148 ) ;
F_5 ( & V_4 -> V_142 ) ;
F_5 ( & V_4 -> V_141 ) ;
break;
}
F_40 ( 10 ) ;
}
else
{
V_49 = - V_149 ;
}
F_5 ( & V_4 -> V_141 ) ;
break;
}
case V_150 :
{
T_21 * V_151 = NULL ;
F_9 ( V_4 , V_21 , 0 , 0 , L_37 , V_44 -> V_45 ) ;
do{
if( ! F_35 ( & V_4 -> V_142 ) )
{
F_9 ( V_4 , V_21 , 0 , 0 , L_39 ) ;
V_49 = - V_74 ;
break;
}
if( F_25 ( & V_52 , V_48 , sizeof( T_9 ) ) )
return - V_43 ;
F_9 ( V_4 , V_21 , 0 , 0 , L_40 ,
V_52 . V_73 ) ;
if ( V_52 . V_73 > sizeof( T_21 ) )
return - V_74 ;
V_151 = F_26 ( sizeof( * V_151 ) , V_8 ) ;
if( ! V_151 )
return - V_9 ;
if( F_25 ( V_151 , V_52 . V_75 , V_52 . V_73 ) )
return - V_43 ;
if( ! V_151 -> V_152 ||
( V_151 -> V_153 == 0 ) )
{
F_9 ( V_4 , V_21 , 0 , 0 , L_41 ,
V_151 -> V_153 ) ;
V_49 = - V_74 ;
break;
}
V_49 = F_41 ( V_4 , V_151 ) ;
if( V_49 != V_59 )
{
if( V_151 -> V_154 == V_155 )
{
F_9 ( V_4 , V_21 , 0 , 0 , L_42 ) ;
}
else
{
F_9 ( V_4 , V_21 , 0 , 0 , L_43 ) ;
}
if( V_4 -> V_111 . V_112 & V_156 )
{
V_4 -> V_115 = V_157 ;
V_4 -> V_111 . V_158 = FALSE ;
F_32 ( & V_4 -> V_111 . V_118 ) ;
}
}
break ;
}while( 0 );
if( V_49 != V_59 )
F_5 ( & V_4 -> V_142 ) ;
F_9 ( V_4 , V_21 , V_34 , V_35 , L_44 ) ;
F_12 ( V_151 ) ;
break;
}
case V_159 :
{
INT V_140 = F_35 ( & V_4 -> V_141 ) ;
if( V_140 )
{
F_9 ( V_4 , V_21 , 0 , 0 , L_45 ) ;
F_5 ( & V_4 -> V_142 ) ;
return - V_38 ;
}
if( F_35 ( & V_4 -> V_142 ) )
{
V_4 -> V_143 = TRUE ;
V_4 -> V_145 = TRUE ;
F_42 ( & V_4 -> V_160 , 0 ) ;
V_4 -> V_161 = 0 ;
V_4 -> V_162 = 0 ;
V_49 = F_43 ( V_4 ) ;
if( V_49 )
{
F_9 ( V_4 , V_21 , 0 , 0 , L_46 ) ;
F_5 ( & V_4 -> V_142 ) ;
F_5 ( & V_4 -> V_141 ) ;
break;
}
else
F_9 ( V_4 , V_33 , V_34 , V_35 , L_47 ) ;
F_40 ( 10 ) ;
if( F_44 ( ( V_163 ) V_4 -> V_164 ) )
{
F_9 ( V_4 , V_21 , 0 , 0 , L_48 ) ;
}
V_51 = 5 * V_137 ;
V_4 -> V_165 = FALSE ;
F_45 ( V_4 -> V_166 ,
V_4 -> V_165 , V_51 ) ;
V_4 -> V_144 = V_167 ;
V_4 -> V_37 = TRUE ;
F_42 ( & V_4 -> V_160 , 0 ) ;
V_4 -> V_161 = 0 ;
V_4 -> V_168 = 0 ;
F_42 ( & V_4 -> V_169 , 0 ) ;
V_4 -> V_170 = 0 ;
V_4 -> V_171 = 0 ;
if( V_4 -> V_111 . V_112 & V_156 )
{
V_4 -> V_115 = V_172 ;
F_32 ( & V_4 -> V_111 . V_118 ) ;
}
if( ! V_51 )
{
V_49 = - V_36 ;
}
}
else
{
V_49 = - V_74 ;
}
F_5 ( & V_4 -> V_142 ) ;
F_5 ( & V_4 -> V_141 ) ;
break;
}
case V_173 :
V_49 = 0 ;
if ( F_46 ( V_4 -> V_174 , ( unsigned long T_4 * ) V_47 ) )
V_49 = - V_43 ;
break;
case V_175 :
V_49 = 0 ;
if ( F_46 ( V_4 -> V_176 , ( unsigned long T_4 * ) V_47 ) )
V_49 = - V_43 ;
break;
case V_177 :
{
INT V_140 = F_35 ( & V_4 -> V_141 ) ;
if( V_140 )
{
F_9 ( V_4 , V_21 , 0 , 0 , L_36 ) ;
return - V_38 ;
}
F_4 ( & V_4 -> V_11 ) ;
V_49 = F_38 ( V_4 ) ;
F_47 () ;
F_5 ( & V_4 -> V_11 ) ;
F_5 ( & V_4 -> V_141 ) ;
F_48 ( V_4 ) ;
break;
}
case V_178 :
{
T_22 V_179 ;
V_49 = 0 ;
for ( V_179 = 0 ; V_179 < V_180 ; V_179 ++ ) {
if ( F_46 ( V_4 -> V_181 [ V_179 ] . V_182 ,
( unsigned long T_4 * ) V_47 ) ) {
V_49 = - V_43 ;
break;
}
}
break;
}
case V_183 :
F_49 ( V_4 ) ;
F_50 ( & V_4 -> V_184 ) ;
V_49 = V_59 ;
break;
case V_185 :
if( F_16 ( V_48 , & V_4 -> V_181 , sizeof( V_186 ) * V_180 ) )
return - V_43 ;
V_49 = V_59 ;
break;
case V_187 :
{
T_7 V_188 = 0 ;
if( F_25 ( & V_188 , V_48 , sizeof( T_7 ) ) )
return - V_43 ;
if( V_188 )
{
F_9 ( V_4 , V_33 , V_34 , V_35 , L_49 ) ;
V_4 -> V_189 = V_190 ;
}
else
{
F_9 ( V_4 , V_33 , V_34 , V_35 , L_50 ) ;
V_4 -> V_189 = V_191 ;
}
V_49 = V_59 ;
break;
}
case V_192 :
{
if( F_25 ( & V_52 , V_48 , sizeof( T_9 ) ) )
return - V_43 ;
if( F_16 ( V_52 . V_78 , V_193 , V_52 . V_76 ) )
return - V_43 ;
V_49 = V_59 ;
break;
}
case V_194 :
{
T_23 V_195 ;
if( F_25 ( & V_52 , V_48 , sizeof( T_9 ) ) )
{
F_9 ( V_4 , V_21 , 0 , 0 , L_51 ) ;
V_49 = - V_43 ;
break;
}
if ( V_52 . V_76 != sizeof( V_195 ) ) {
V_49 = - V_74 ;
break;
}
memset ( & V_195 , 0 , sizeof( V_195 ) ) ;
V_195 . V_196 = V_4 -> V_93 ;
V_195 . V_197 = V_4 -> V_94 ;
V_195 . V_198 = V_4 -> V_171 ;
if ( F_16 ( V_52 . V_78 , & V_195 ,
F_17 ( T_5 , sizeof( V_195 ) , V_52 . V_76 ) ) )
{
F_9 ( V_4 , V_21 , 0 , 0 , L_52 ) ;
V_49 = - V_43 ;
break;
}
V_49 = V_59 ;
break;
}
case V_199 :
{
T_7 V_200 ;
if( F_25 ( & V_52 , V_48 , sizeof( T_9 ) ) )
return - V_43 ;
if( F_25 ( & V_200 , V_52 . V_75 , sizeof( T_7 ) ) )
return - V_43 ;
if ( V_200 )
V_4 -> V_13 -> V_201 = TRUE ;
else
V_4 -> V_13 -> V_201 = FALSE ;
break;
}
case V_202 :
{
T_8 V_203 = 0 ;
if( F_25 ( & V_52 , V_48 , sizeof( T_9 ) ) )
return - V_43 ;
if( V_52 . V_76 < sizeof( V_204 ) )
{
F_9 ( V_4 , V_21 , 0 , 0 ,
L_53 ,
V_52 . V_76 , sizeof( V_204 ) ) ;
return - V_74 ;
}
if( F_25 ( & V_203 , V_52 . V_75 , sizeof( V_203 ) ) )
return - V_43 ;
F_9 ( V_4 , V_33 , V_34 , V_35 , L_54 , V_203 ) ;
F_51 ( V_4 , V_203 , V_52 . V_78 ) ;
V_49 = V_59 ;
}
break;
case V_205 :
{
T_20 V_71 ;
if( F_25 ( & V_52 , V_48 , sizeof( T_9 ) ) )
return - V_43 ;
if( V_52 . V_76 != sizeof( V_206 ) )
{
F_9 ( V_4 , V_21 , 0 , 0 ,
L_55 ,
V_52 . V_76 , sizeof( V_206 ) ) ;
return - V_74 ;
}
V_71 = F_3 ( sizeof( V_206 ) , V_8 ) ;
if( ! V_71 )
return V_50 ;
V_49 = F_52 ( V_4 , V_71 ) ;
F_53 ( V_71 , V_5 ) ;
if ( V_49 != V_50 )
if( F_16 ( V_52 . V_78 , V_71 , sizeof( V_206 ) ) )
V_49 = - V_43 ;
F_12 ( V_71 ) ;
break;
}
case V_207 :
if( ( FALSE == V_4 -> V_208 ) && ( TRUE == V_4 -> V_93 ) )
{
V_4 -> V_209 = V_210 ;
V_4 -> V_211 = TRUE ;
F_32 ( & V_4 -> V_212 ) ;
}
V_49 = V_59 ;
break;
case V_213 :
{
T_24 V_214 ;
T_7 V_81 = 0 ;
T_11 V_134 = NULL ;
if( ( V_4 -> V_93 == TRUE ) ||
( V_4 -> V_94 == TRUE ) ||
( V_4 -> V_95 == TRUE ) )
{
F_9 ( V_4 , V_21 , 0 , 0 , L_56 ) ;
V_49 = - V_38 ;
break;
}
if( F_25 ( & V_52 , V_48 , sizeof( T_9 ) ) )
return - V_43 ;
V_134 = F_26 ( V_52 . V_73 , V_8 ) ;
if( ! V_134 )
return - V_9 ;
if( F_25 ( V_134 , V_52 . V_75 , V_52 . V_73 ) )
{
F_12 ( V_134 ) ;
V_49 = - V_43 ;
break;
}
V_214 = ( T_24 ) V_134 ;
if( ( ( T_8 ) V_214 -> Register & 0x0F000000 ) != 0x0F000000 ||
( ( T_8 ) V_214 -> Register & 0x3 ) )
{
F_12 ( V_134 ) ;
F_9 ( V_4 , V_21 , 0 , 0 , L_14 , ( int ) V_214 -> Register ) ;
V_49 = - V_74 ;
break;
}
V_81 = V_214 -> Register & V_82 ;
if( ! ( ( V_4 -> V_83 -> V_84 ) & V_85 )
&& ( ( V_81 == V_86 ) ||
( V_81 == V_87 ) ||
( V_81 == V_88 ) ||
( V_81 == V_89 ) ) &&
( V_46 == V_96 ) )
{
F_12 ( V_134 ) ;
F_9 ( V_4 , V_21 , 0 , 0 , L_8 ) ;
V_49 = - V_43 ;
break;
}
if( V_214 -> V_215 == FALSE )
V_49 = F_54 ( V_4 , ( T_7 ) V_214 -> Register , ( T_11 ) V_214 -> V_216 , V_52 . V_73 - 2 * sizeof( T_8 ) ) ;
else
V_49 = F_30 ( V_4 , ( T_7 ) V_214 -> Register , ( V_77 ) V_214 -> V_216 , V_52 . V_73 - 2 * sizeof( T_8 ) ) ;
if( V_49 != V_59 )
{
F_9 ( V_4 , V_21 , 0 , 0 , L_10 ) ;
}
F_12 ( V_134 ) ;
break;
}
case V_217 :
if( F_25 ( & V_52 , V_48 , sizeof( T_9 ) ) )
return - V_43 ;
if( V_4 -> V_218 == V_219 || V_4 -> V_218 == V_220 ) {
if( F_16 ( V_52 . V_78 , & V_4 -> V_221 , sizeof( T_7 ) ) )
return - V_43 ;
}
V_49 = V_59 ;
break;
case V_222 :
{
T_7 V_223 = 0 ;
if( V_4 -> V_218 == V_220 )
{
if( F_25 ( & V_52 , V_48 , sizeof( T_9 ) ) )
return - V_43 ;
if ( F_25 ( & V_223 , V_52 . V_75 , sizeof( T_7 ) ) )
return - V_43 ;
if( ( V_223 < V_224 ) || ( V_223 > V_225 ) )
{
if ( F_16 ( V_52 . V_78 , & V_4 -> V_223 ,
sizeof( T_7 ) ) )
return - V_43 ;
}
else
{
if( F_55 ( V_4 ) )
{
if ( F_16 ( V_52 . V_78 ,
& V_4 -> V_223 ,
sizeof( T_7 ) ) )
return - V_43 ;
}
else
{
if( ( TRUE == V_4 -> V_94 ) ||
( TRUE == V_4 -> V_93 ) )
{
F_9 ( V_4 , V_21 , 0 , 0 , L_57 ) ;
return - V_38 ;
}
V_4 -> V_223 = V_223 ;
F_56 ( V_4 , V_4 -> V_223 ) ;
}
}
V_49 = V_59 ;
}
else
{
V_49 = V_50 ;
}
}
break;
case V_226 :
#ifdef F_57
{
T_25 V_227 ;
F_9 ( V_4 , V_33 , V_34 , V_35 , L_58 ) ;
if ( F_25 ( & V_52 , V_48 , sizeof( T_9 ) ) )
return - V_43 ;
if ( F_25 ( & V_227 , V_52 . V_75 , sizeof( T_25 ) ) )
return - V_43 ;
F_9 ( V_4 , V_21 , 0 , 0 , L_59 ,
V_227 . V_228 , V_227 . Type ) ;
V_227 . V_229 = 1 << V_227 . V_229 ;
F_9 ( V_4 , V_21 , 0 , 0 , L_60 , V_227 . V_229 ) ;
V_4 -> V_230 . type |= V_227 . Type ;
if ( V_227 . V_228 )
V_4 -> V_230 . V_231 [ V_227 . Type ] |= V_227 . V_229 ;
else
V_4 -> V_230 . V_231 [ V_227 . Type ] &= ~ V_227 . V_229 ;
F_58 ( V_4 ) ;
}
#endif
break;
case V_232 :
case V_233 :
{
T_26 V_234 ;
T_27 V_235 = NULL ;
T_8 V_236 = 0 ;
struct V_237 V_238 , V_239 ;
memset ( & V_238 , 0 , sizeof( struct V_237 ) ) ;
memset ( & V_239 , 0 , sizeof( struct V_237 ) ) ;
if( ( V_4 -> V_218 == V_220 ) && ( V_4 -> V_240 == 0 ) )
{
F_9 ( V_4 , V_21 , 0 , 0 , L_61 ) ;
V_49 = - V_43 ;
break;
}
if( F_55 ( V_4 ) )
{
if( ( V_4 -> V_241 != V_242 ) &&
( V_4 -> V_241 != V_243 ) &&
( V_4 -> V_241 != V_244 ) )
{
F_9 ( V_4 , V_21 , 0 , 0 , L_62 ) ;
return V_50 ;
}
}
if( F_25 ( & V_52 , V_48 , sizeof( T_9 ) ) )
return - V_43 ;
if( F_25 ( & V_234 ,
( V_232 == V_46 ) ? V_52 . V_78 : V_52 . V_75 ,
sizeof( T_26 ) ) )
return - V_43 ;
if( ( V_234 . V_245 + V_234 . V_246 ) > V_4 -> V_221 )
{
V_49 = V_50 ;
break;
}
V_235 = F_3 ( V_234 . V_246 , V_8 ) ;
if( ! V_235 )
return - V_9 ;
if( F_25 ( V_235 , V_234 . V_247 ,
V_234 . V_246 ) )
{
V_49 = - V_43 ;
F_12 ( V_235 ) ;
break;
}
F_59 ( & V_238 ) ;
if( V_232 == V_46 )
{
F_4 ( & V_4 -> V_141 ) ;
if( ( V_4 -> V_93 == TRUE ) ||
( V_4 -> V_94 == TRUE ) ||
( V_4 -> V_95 == TRUE ) )
{
F_9 ( V_4 , V_33 , V_34 , V_35 , L_57 ) ;
F_5 ( & V_4 -> V_141 ) ;
F_12 ( V_235 ) ;
return - V_38 ;
}
V_49 = F_60 ( V_4 , ( V_77 ) V_235 ,
V_234 . V_245 , V_234 . V_246 ) ;
F_5 ( & V_4 -> V_141 ) ;
if( V_49 != V_59 )
{
F_12 ( V_235 ) ;
return V_49 ;
}
if( F_16 ( V_234 . V_247 , V_235 , V_234 . V_246 ) )
{
F_12 ( V_235 ) ;
V_49 = - V_43 ;
}
}
else
{
F_4 ( & V_4 -> V_141 ) ;
if( ( V_4 -> V_93 == TRUE ) ||
( V_4 -> V_94 == TRUE ) ||
( V_4 -> V_95 == TRUE ) )
{
F_9 ( V_4 , V_33 , V_34 , V_35 , L_57 ) ;
F_5 ( & V_4 -> V_141 ) ;
F_12 ( V_235 ) ;
return - V_38 ;
}
V_4 -> V_248 = TRUE ;
if( F_55 ( V_4 ) )
{
V_49 = F_61 ( V_4 , V_4 -> V_241 ) ;
if( V_49 != V_59 )
{
if( ( ( V_234 . V_245 + V_234 . V_246 ) != V_4 -> V_221 ) ||
( V_234 . V_246 < V_249 ) )
{
F_9 ( V_4 , V_33 , V_34 , V_35 , L_63 ) ;
F_5 ( & V_4 -> V_141 ) ;
F_12 ( V_235 ) ;
return V_49 ;
}
V_236 = F_62 ( * ( V_77 ) ( V_235 + V_234 . V_246 - V_249 ) ) ;
if( V_236 != V_250 )
{
F_9 ( V_4 , V_33 , V_34 , V_35 , L_63 ) ;
F_5 ( & V_4 -> V_141 ) ;
F_12 ( V_235 ) ;
return V_49 ;
}
}
}
V_49 = F_63 ( V_4 , ( V_77 ) V_235 ,
V_234 . V_245 , V_234 . V_246 , V_234 . V_251 ) ;
if( F_55 ( V_4 ) )
F_64 ( V_4 , V_4 -> V_241 ) ;
V_4 -> V_248 = FALSE ;
F_5 ( & V_4 -> V_141 ) ;
if( V_49 != V_59 )
{
F_12 ( V_235 ) ;
return V_49 ;
}
}
F_59 ( & V_239 ) ;
F_9 ( V_4 , V_33 , V_34 , V_35 , L_64 , ( V_239 . V_252 - V_238 . V_252 ) * 1000 + ( V_239 . V_253 - V_238 . V_253 ) / 1000 ) ;
F_12 ( V_235 ) ;
V_49 = V_59 ;
}
break;
case V_254 :
{
T_28 V_255 = { 0 } ;
T_27 V_256 = NULL ;
T_7 V_257 = 0 ;
T_7 V_258 = 0 ;
T_7 V_259 = 0 ;
T_7 V_260 = 0 ;
void T_4 * V_261 ;
if( F_55 ( V_4 ) != TRUE )
{
F_9 ( V_4 , V_21 , 0 , 0 , L_65 ) ;
return - V_74 ;
}
F_9 ( V_4 , V_33 , V_34 , V_35 , L_66 ) ;
if ( F_25 ( & V_52 , V_48 , sizeof( T_9 ) ) )
return - V_43 ;
if ( F_25 ( & V_255 , V_52 . V_75 , sizeof( T_28 ) ) )
return - V_43 ;
F_9 ( V_4 , V_33 , V_34 , V_35 , L_67 , V_255 . V_262 ) ;
F_9 ( V_4 , V_33 , V_34 , V_35 , L_68 , V_255 . V_263 ) ;
F_9 ( V_4 , V_33 , V_34 , V_35 , L_69 , V_255 . V_264 ) ;
F_9 ( V_4 , V_33 , V_34 , V_35 , L_70 , V_255 . V_251 ) ;
if( F_65 ( V_4 , & V_255 ) == FALSE )
return V_50 ;
V_257 = V_255 . V_264 ;
if( V_257 > V_4 -> V_223 )
V_258 = V_4 -> V_223 ;
else
V_258 = V_257 ;
V_260 = V_255 . V_263 ;
V_261 = V_52 . V_78 ;
V_256 = ( T_11 ) F_3 ( V_258 , V_8 ) ;
if( V_256 == NULL )
{
F_9 ( V_4 , V_21 , 0 , 0 , L_71 ) ;
return - V_9 ;
}
F_4 ( & V_4 -> V_141 ) ;
if( ( V_4 -> V_93 == TRUE ) ||
( V_4 -> V_94 == TRUE ) ||
( V_4 -> V_95 == TRUE ) )
{
F_9 ( V_4 , V_33 , V_34 , V_35 , L_57 ) ;
F_5 ( & V_4 -> V_141 ) ;
F_12 ( V_256 ) ;
return - V_38 ;
}
while( V_257 )
{
if( V_257 > V_4 -> V_223 )
V_259 = V_4 -> V_223 ;
else
V_259 = V_257 ;
V_49 = F_66 ( V_4 , ( V_77 ) V_256 , V_255 . V_262 , V_260 , V_259 ) ;
if( V_49 )
{
F_9 ( V_4 , V_33 , V_34 , V_35 , L_72 , V_49 ) ;
break ;
}
F_67 ( V_4 , V_33 , V_34 , V_35 , V_256 , V_259 ) ;
V_49 = F_16 ( V_261 , V_256 , V_259 ) ;
if( V_49 )
{
F_9 ( V_4 , V_33 , V_34 , V_35 , L_73 , V_49 ) ;
break;
}
V_257 = V_257 - V_259 ;
if( V_257 )
{
V_260 = V_260 + V_259 ;
V_261 = V_261 + V_259 ;
}
}
F_5 ( & V_4 -> V_141 ) ;
F_12 ( V_256 ) ;
}
break ;
case V_265 :
{
T_28 V_266 = { 0 } ;
T_27 V_267 ;
void T_4 * V_268 ;
T_7 V_257 = 0 ;
T_7 V_258 = 0 ;
T_7 V_269 = 0 ;
T_7 V_270 = 0 ;
if( F_55 ( V_4 ) != TRUE )
{
F_9 ( V_4 , V_21 , 0 , 0 , L_65 ) ;
return - V_74 ;
}
V_4 -> V_271 = FALSE ;
F_9 ( V_4 , V_33 , V_34 , V_35 , L_74 ) ;
if ( F_25 ( & V_52 , V_48 , sizeof( T_9 ) ) )
return - V_43 ;
if ( F_25 ( & V_266 , V_52 . V_75 , sizeof( T_28 ) ) )
return - V_43 ;
F_9 ( V_4 , V_33 , V_34 , V_35 , L_67 , V_266 . V_262 ) ;
F_9 ( V_4 , V_33 , V_34 , V_35 , L_75 , V_266 . V_263 ) ;
F_9 ( V_4 , V_33 , V_34 , V_35 , L_69 , V_266 . V_264 ) ;
F_9 ( V_4 , V_33 , V_34 , V_35 , L_70 , V_266 . V_251 ) ;
if( ( V_266 . V_262 != V_272 ) && ( V_266 . V_262 != V_273 ) &&
( V_266 . V_262 != V_274 ) )
{
F_9 ( V_4 , V_33 , V_34 , V_35 , L_76 ) ;
return - V_74 ;
}
if( F_65 ( V_4 , & V_266 ) == FALSE )
return V_50 ;
V_268 = V_266 . V_275 ;
V_269 = V_266 . V_263 ;
V_257 = V_266 . V_264 ;
if( V_257 > V_4 -> V_223 )
V_258 = V_4 -> V_223 ;
else
V_258 = V_257 ;
V_267 = F_26 ( V_258 , V_8 ) ;
if( V_267 == NULL )
return - V_9 ;
V_270 = V_4 -> V_223 ;
if( V_269 % V_4 -> V_223 )
V_270 = V_4 -> V_223 - ( V_269 % V_4 -> V_223 ) ;
if( V_257 < V_270 )
V_270 = V_257 ;
F_4 ( & V_4 -> V_141 ) ;
if( ( V_4 -> V_93 == TRUE ) ||
( V_4 -> V_94 == TRUE ) ||
( V_4 -> V_95 == TRUE ) )
{
F_9 ( V_4 , V_33 , V_34 , V_35 , L_57 ) ;
F_5 ( & V_4 -> V_141 ) ;
F_12 ( V_267 ) ;
return - V_38 ;
}
F_61 ( V_4 , V_266 . V_262 ) ;
do
{
V_49 = F_25 ( V_267 , V_268 , V_270 ) ;
if( V_49 )
{
F_9 ( V_4 , V_21 , 0 , 0 , L_77 , V_49 ) ;
break ;
}
F_67 ( V_4 , V_33 , V_34 , V_35 , V_267 , V_270 ) ;
V_49 = F_68 ( V_4 , ( V_77 ) V_267 , V_266 . V_262 , V_269 , V_270 , V_266 . V_251 ) ;
if( V_49 )
{
F_9 ( V_4 , V_21 , 0 , 0 , L_72 , V_49 ) ;
break ;
}
V_257 = V_257 - V_270 ;
if( V_257 )
{
V_269 = V_269 + V_270 ;
V_268 = V_268 + V_270 ;
if( V_257 > V_4 -> V_223 )
V_270 = V_4 -> V_223 ;
else
V_270 = V_257 ;
}
} while( V_257 > 0 );
F_64 ( V_4 , V_266 . V_262 ) ;
F_5 ( & V_4 -> V_141 ) ;
F_12 ( V_267 ) ;
}
break ;
case V_276 :
{
T_29 V_277 ;
F_9 ( V_4 , V_33 , V_34 , V_35 , L_78 ) ;
if ( F_25 ( & V_52 , V_48 , sizeof( T_9 ) ) )
return - V_43 ;
if( V_52 . V_76 != sizeof( V_278 ) )
return - V_74 ;
V_277 = F_3 ( sizeof( V_278 ) , V_8 ) ;
if( V_277 == NULL )
{
F_9 ( V_4 , V_21 , 0 , 0 , L_79 ) ;
return - V_9 ;
}
F_4 ( & V_4 -> V_141 ) ;
if( ( V_4 -> V_93 == TRUE ) ||
( V_4 -> V_94 == TRUE ) ||
( V_4 -> V_95 == TRUE ) )
{
F_9 ( V_4 , V_33 , V_34 , V_35 , L_57 ) ;
F_5 ( & V_4 -> V_141 ) ;
F_12 ( V_277 ) ;
return - V_38 ;
}
F_69 ( V_4 , V_277 ) ;
F_5 ( & V_4 -> V_141 ) ;
if ( F_16 ( V_52 . V_78 , V_277 , sizeof( V_278 ) ) )
V_49 = - V_43 ;
F_12 ( V_277 ) ;
}
break ;
case V_279 :
{
T_30 V_280 = 0 ;
F_9 ( V_4 , V_33 , V_34 , V_35 , L_80 ) ;
if( F_55 ( V_4 ) != TRUE )
{
F_9 ( V_4 , V_21 , 0 , 0 , L_65 ) ;
return - V_74 ;
}
V_49 = F_25 ( & V_52 , V_48 , sizeof( T_9 ) ) ;
if( V_49 )
{
F_9 ( V_4 , V_21 , 0 , 0 , L_81 ) ;
return V_49 ;
}
V_49 = F_25 ( & V_280 , V_52 . V_75 , sizeof( INT ) ) ;
if( V_49 )
{
F_9 ( V_4 , V_21 , 0 , 0 , L_82 ) ;
return V_49 ;
}
F_4 ( & V_4 -> V_141 ) ;
if( ( V_4 -> V_93 == TRUE ) ||
( V_4 -> V_94 == TRUE ) ||
( V_4 -> V_95 == TRUE ) )
{
F_9 ( V_4 , V_33 , V_34 , V_35 , L_57 ) ;
F_5 ( & V_4 -> V_141 ) ;
return - V_38 ;
}
V_49 = F_70 ( V_4 , V_280 ) ;
if( V_49 )
{
F_9 ( V_4 , V_21 , 0 , 0 , L_83 , V_49 ) ;
}
F_5 ( & V_4 -> V_141 ) ;
}
break ;
case V_281 :
{
V_4 -> V_271 = FALSE ;
F_9 ( V_4 , V_33 , V_34 , V_35 , L_84 ) ;
V_49 = V_59 ;
}
break ;
case V_282 :
{
T_31 V_283 = { 0 } ;
V_49 = V_59 ;
F_9 ( V_4 , V_33 , V_34 , V_35 , L_85 ) ;
V_4 -> V_271 = FALSE ;
if( F_55 ( V_4 ) != TRUE )
{
F_9 ( V_4 , V_21 , 0 , 0 , L_65 ) ;
return - V_74 ;
}
V_49 = F_25 ( & V_52 , V_48 , sizeof( T_9 ) ) ;
if( V_49 )
{
F_9 ( V_4 , V_21 , 0 , 0 , L_86 , V_49 ) ;
return V_49 ;
}
V_49 = F_25 ( & V_283 , V_52 . V_75 , sizeof( T_31 ) ) ;
if( V_49 )
{
F_9 ( V_4 , V_21 , 0 , 0 , L_87 , V_49 ) ;
return V_49 ;
}
F_9 ( V_4 , V_33 , V_34 , V_35 , L_88 , V_283 . V_284 ) ;
F_9 ( V_4 , V_33 , V_34 , V_35 , L_89 , V_283 . V_285 ) ;
F_9 ( V_4 , V_33 , V_34 , V_35 , L_90 , V_283 . V_263 ) ;
F_9 ( V_4 , V_33 , V_34 , V_35 , L_91 , V_283 . V_264 ) ;
if( F_71 ( V_4 , V_283 . V_284 ) == FALSE )
{
F_9 ( V_4 , V_21 , 0 , 0 , L_92 , V_283 . V_284 ) ;
return - V_74 ;
}
if( F_71 ( V_4 , V_283 . V_285 ) == FALSE )
{
F_9 ( V_4 , V_21 , 0 , 0 , L_93 , V_283 . V_285 ) ;
return - V_74 ;
}
if( V_283 . V_284 == V_283 . V_285 )
{
F_9 ( V_4 , V_33 , V_34 , V_35 , L_94 ) ;
return - V_74 ;
}
F_4 ( & V_4 -> V_141 ) ;
if( ( V_4 -> V_93 == TRUE ) ||
( V_4 -> V_94 == TRUE ) ||
( V_4 -> V_95 == TRUE ) )
{
F_9 ( V_4 , V_33 , V_34 , V_35 , L_57 ) ;
F_5 ( & V_4 -> V_141 ) ;
return - V_38 ;
}
if( V_283 . V_284 == V_286 || V_283 . V_284 == V_287 )
{
if( F_72 ( V_4 ) )
{
F_9 ( V_4 , V_21 , 0 , 0 , L_95 ) ;
V_49 = - V_74 ;
}
else if( V_283 . V_264 == 0 )
{
V_49 = F_73 ( V_4 , V_283 ) ;
}
else
{
F_9 ( V_4 , V_21 , 0 , 0 , L_96 ) ;
V_49 = V_50 ;
}
F_5 ( & V_4 -> V_141 ) ;
return V_49 ;
}
V_49 = F_74 ( V_4 , V_283 . V_284 ,
V_283 . V_285 , V_283 . V_263 , V_283 . V_264 ) ;
F_5 ( & V_4 -> V_141 ) ;
}
break ;
case V_288 :
{
V_49 = V_59 ;
F_9 ( V_4 , V_33 , V_34 , V_35 , L_97 ) ;
V_49 = F_25 ( & V_52 , V_48 , sizeof( T_9 ) ) ;
if( V_49 )
{
F_9 ( V_4 , V_21 , 0 , 0 , L_81 ) ;
break;
}
if( V_4 -> V_218 != V_220 )
{
F_9 ( V_4 , V_21 , 0 , 0 , L_98 ) ;
V_49 = - V_74 ;
break;
}
if( F_55 ( V_4 ) == TRUE )
{
if( V_52 . V_76 < sizeof( V_289 ) )
return - V_74 ;
if ( F_16 ( V_52 . V_78 , V_4 -> V_290 , sizeof( V_289 ) ) )
return - V_43 ;
}
else
{
if( V_52 . V_76 < sizeof( V_291 ) )
return - V_74 ;
if ( F_16 ( V_52 . V_78 , V_4 -> V_292 , sizeof( V_291 ) ) )
return - V_43 ;
}
}
break ;
case V_293 :
{
T_7 V_294 = 0 ;
T_30 V_280 ;
V_280 = V_295 ;
F_9 ( V_4 , V_33 , V_34 , V_35 , L_99 ) ;
if( F_55 ( V_4 ) != TRUE )
{
F_9 ( V_4 , V_21 , 0 , 0 , L_65 ) ;
return - V_74 ;
}
V_49 = F_25 ( & V_52 , V_48 , sizeof( T_9 ) ) ;
if( V_49 )
{
F_9 ( V_4 , V_21 , 0 , 0 , L_81 ) ;
return V_49 ;
}
V_49 = F_25 ( & V_280 , V_52 . V_75 , sizeof( INT ) ) ;
if( V_49 )
{
F_9 ( V_4 , V_21 , 0 , 0 , L_82 ) ;
return V_49 ;
}
F_9 ( V_4 , V_33 , V_34 , V_35 , L_100 , V_280 ) ;
if( ( V_280 != V_242 ) &&
( V_280 != V_243 ) &&
( V_280 != V_244 ) )
{
F_9 ( V_4 , V_21 , 0 , 0 , L_101 , V_280 ) ;
return V_50 ;
}
V_294 = F_75 ( V_4 , V_280 ) ;
if( V_294 == V_296 )
{
F_9 ( V_4 , V_21 , 0 , 0 , L_102 , V_280 ) ;
return - V_74 ;
}
V_4 -> V_271 = TRUE ;
V_4 -> V_297 = V_294 ;
V_4 -> V_241 = V_280 ;
}
V_49 = V_59 ;
break;
case V_298 :
{
T_26 V_299 ;
INT V_257 ;
INT V_258 ;
INT V_260 = 0 ;
T_7 V_259 = 0 ;
T_27 V_256 ;
void T_4 * V_261 ;
if( V_4 -> V_218 != V_220 )
{
F_9 ( V_4 , V_21 , 0 , 0 , L_103 ) ;
return - V_74 ;
}
if( F_25 ( & V_52 , V_48 , sizeof( T_9 ) ) )
{
F_9 ( V_4 , V_21 , 0 , 0 , L_104 ) ;
V_49 = - V_43 ;
break;
}
if( F_25 ( & V_299 , V_52 . V_78 , sizeof( T_26 ) ) )
return - V_43 ;
V_257 = V_299 . V_246 ;
if( V_257 > V_300 )
V_258 = V_300 ;
else
V_258 = V_257 ;
V_260 = V_299 . V_245 ;
V_261 = V_299 . V_247 ;
V_256 = F_3 ( V_258 , V_8 ) ;
if( V_256 == NULL )
{
F_9 ( V_4 , V_21 , 0 , 0 , L_71 ) ;
V_49 = - V_9 ;
break;
}
F_4 ( & V_4 -> V_141 ) ;
if( ( V_4 -> V_93 == TRUE ) ||
( V_4 -> V_94 == TRUE ) ||
( V_4 -> V_95 == TRUE ) )
{
F_9 ( V_4 , V_33 , V_34 , V_35 , L_57 ) ;
F_12 ( V_256 ) ;
F_5 ( & V_4 -> V_141 ) ;
return - V_38 ;
}
V_4 -> V_301 = TRUE ;
while( V_257 )
{
if( V_257 > V_300 )
V_259 = V_300 ;
else
V_259 = V_257 ;
V_49 = F_60 ( V_4 , ( V_77 ) V_256 , V_260 , V_259 ) ;
if( V_49 )
{
F_9 ( V_4 , V_21 , 0 , 0 , L_72 , V_49 ) ;
break;
}
F_67 ( V_4 , V_33 , V_34 , V_35 , V_256 , V_259 ) ;
V_49 = F_16 ( V_261 , V_256 , V_259 ) ;
if( V_49 )
{
F_9 ( V_4 , V_21 , 0 , 0 , L_73 , V_49 ) ;
break;
}
V_257 = V_257 - V_259 ;
if( V_257 )
{
V_260 = V_260 + V_259 ;
V_261 = V_261 + V_259 ;
}
}
V_4 -> V_301 = FALSE ;
F_5 ( & V_4 -> V_141 ) ;
F_12 ( V_256 ) ;
break ;
}
case V_302 :
{
T_8 V_10 = 0 ;
V_49 = F_25 ( & V_52 , V_48 , sizeof( T_9 ) ) ;
if( V_49 )
{
F_9 ( V_4 , V_33 , V_34 , V_35 , L_105 ) ;
V_49 = - V_43 ;
break;
}
if ( V_52 . V_73 != sizeof( unsigned long ) ) {
V_49 = - V_74 ;
break;
}
V_49 = F_25 ( & V_10 , V_52 . V_75 , V_52 . V_73 ) ;
if( V_49 )
{
F_9 ( V_4 , V_33 , V_34 , V_35 , L_106 ) ;
V_49 = - V_43 ;
break;
}
F_9 ( V_4 , V_33 , V_34 , V_35 , L_107 , V_10 ) ;
V_5 -> V_10 = V_10 ;
}
break;
case V_303 :
{
T_32 V_304 ;
F_9 ( V_4 , V_33 , V_34 , V_35 , L_108 ) ;
V_304 . V_305 = V_306 ;
V_304 . V_307 = V_308 ;
V_304 . V_309 = 0 ;
V_304 . V_310 = V_4 -> V_218 ;
V_304 . V_311 = V_312 ;
if ( F_25 ( & V_52 , V_48 , sizeof( T_9 ) ) )
return - V_43 ;
if( V_52 . V_76 < sizeof( V_304 ) )
return - V_74 ;
if ( F_16 ( V_52 . V_78 , & V_304 , sizeof( V_304 ) ) )
return - V_43 ;
}
break ;
case V_313 :
{
T_33 V_314 = { 0 } ;
F_9 ( V_4 , V_33 , V_34 , V_35 , L_109 ) ;
if ( F_25 ( & V_52 , V_48 , sizeof( T_9 ) ) )
return - V_43 ;
if( V_52 . V_76 < sizeof( T_33 ) )
return - V_74 ;
V_314 . V_315 = F_76 () - V_4 -> V_316 ;
if ( F_16 ( V_52 . V_78 , & V_314 , sizeof( T_33 ) ) )
return - V_43 ;
}
break;
case V_317 :
F_9 ( V_4 , V_33 , V_34 , V_35 , L_110 ) ;
break;
default:
F_77 ( V_318 L_111 , V_46 ) ;
V_49 = V_50 ;
break;
}
return V_49 ;
}
int F_78 ( T_1 V_4 )
{
if ( V_4 -> V_319 > 0 )
return V_4 -> V_319 ;
V_4 -> V_319 = F_79 ( 0 , V_320 , & V_321 ) ;
if ( V_4 -> V_319 < 0 ) {
F_39 ( V_318 L_112 ) ;
return V_4 -> V_319 ;
}
V_4 -> V_322 = F_80 ( V_323 , NULL ,
F_81 ( V_4 -> V_319 , 0 ) ,
V_4 , V_320 ) ;
if ( F_82 ( V_4 -> V_322 ) ) {
F_39 ( V_318 L_113 ) ;
F_83 ( V_4 -> V_319 , V_320 ) ;
return F_84 ( V_4 -> V_322 ) ;
}
return 0 ;
}
void F_85 ( T_1 V_4 )
{
if ( V_4 -> V_319 > 0 ) {
F_86 ( V_323 , F_81 ( V_4 -> V_319 , 0 ) ) ;
F_83 ( V_4 -> V_319 , V_320 ) ;
}
}
