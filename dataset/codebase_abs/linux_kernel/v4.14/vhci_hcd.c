static void F_1 ( T_1 V_1 , T_1 V_2 , bool V_3 )
{
int V_4 = 0 ;
T_1 V_5 = 1 ;
const char * const * V_6 = V_7 ;
if ( V_3 )
V_6 = V_8 ;
F_2 ( L_1 , V_1 , V_2 ) ;
while ( V_5 ) {
T_1 V_9 = V_1 & V_5 ;
T_1 V_10 = V_2 & V_5 ;
char V_11 ;
if ( ! V_9 && V_10 )
V_11 = '+' ;
else if ( V_9 && ! V_10 )
V_11 = '-' ;
else
V_11 = ' ' ;
if ( V_9 || V_10 ) {
F_2 ( L_2 , V_11 , V_6 [ V_4 ] ) ;
if ( V_5 == 1 )
F_2 ( L_2 , V_11 , L_3 ) ;
}
V_5 <<= 1 ;
V_4 ++ ;
}
F_2 ( L_4 ) ;
}
void F_3 ( struct V_12 * V_13 , enum V_14 V_15 )
{
struct V_16 * V_16 = F_4 ( V_13 ) ;
struct V_17 * V_17 = V_16 -> V_17 ;
int V_18 = V_13 -> V_18 ;
T_1 V_19 ;
unsigned long V_20 ;
F_5 ( L_5 , V_18 ) ;
F_6 ( & V_17 -> V_21 , V_20 ) ;
V_19 = V_16 -> V_22 [ V_18 ] ;
V_19 |= V_23 | ( 1 << V_24 ) ;
switch ( V_15 ) {
case V_25 :
V_19 |= V_26 ;
break;
case V_27 :
V_19 |= V_28 ;
break;
default:
break;
}
V_16 -> V_22 [ V_18 ] = V_19 ;
F_7 ( & V_17 -> V_21 , V_20 ) ;
F_8 ( F_9 ( V_16 ) ) ;
}
static void F_10 ( struct V_12 * V_13 )
{
struct V_16 * V_16 = F_4 ( V_13 ) ;
struct V_17 * V_17 = V_16 -> V_17 ;
int V_18 = V_13 -> V_18 ;
T_1 V_19 ;
unsigned long V_20 ;
F_5 ( L_6 , V_18 ) ;
F_6 ( & V_17 -> V_21 , V_20 ) ;
V_19 = V_16 -> V_22 [ V_18 ] ;
V_19 &= ~ V_23 ;
V_19 |= ( 1 << V_24 ) ;
V_16 -> V_22 [ V_18 ] = V_19 ;
F_7 ( & V_17 -> V_21 , V_20 ) ;
F_8 ( F_9 ( V_16 ) ) ;
}
static int F_11 ( struct V_29 * V_30 , char * V_31 )
{
struct V_16 * V_16 = F_12 ( V_30 ) ;
struct V_17 * V_17 = V_16 -> V_17 ;
int V_32 = F_13 ( V_33 + 1 , 8 ) ;
int V_18 ;
int V_34 = 0 ;
unsigned long V_20 ;
memset ( V_31 , 0 , V_32 ) ;
F_6 ( & V_17 -> V_21 , V_20 ) ;
if ( ! F_14 ( V_30 ) ) {
F_5 ( L_7 ) ;
goto V_35;
}
for ( V_18 = 0 ; V_18 < V_33 ; V_18 ++ ) {
if ( ( V_16 -> V_22 [ V_18 ] & V_36 ) ) {
F_5 ( L_8 , V_18 ) ;
V_31 [ ( V_18 + 1 ) / 8 ] |= 1 << ( V_18 + 1 ) % 8 ;
V_34 = 1 ;
}
}
if ( ( V_30 -> V_37 == V_38 ) && ( V_34 == 1 ) )
F_15 ( V_30 ) ;
V_35:
F_7 ( & V_17 -> V_21 , V_20 ) ;
return V_34 ? V_32 : 0 ;
}
static inline void
F_16 ( struct V_39 * V_6 )
{
memset ( V_6 , 0 , sizeof *V_6 ) ;
V_6 -> V_40 = V_41 ;
V_6 -> V_42 = 12 ;
V_6 -> V_43 = F_17 (
V_44 | V_45 ) ;
V_6 -> V_46 = V_33 ;
V_6 -> V_47 . V_48 . V_49 = 0x04 ;
V_6 -> V_47 . V_48 . V_50 = 0xffff ;
}
static inline void F_18 ( struct V_39 * V_6 )
{
int V_51 ;
memset ( V_6 , 0 , sizeof( * V_6 ) ) ;
V_6 -> V_40 = V_52 ;
V_6 -> V_43 = F_17 (
V_44 | V_45 ) ;
V_6 -> V_46 = V_33 ;
F_19 ( V_33 > V_53 ) ;
V_51 = V_6 -> V_46 / 8 + 1 ;
V_6 -> V_42 = V_54 + 2 * V_51 ;
memset ( & V_6 -> V_47 . V_55 . V_50 [ 0 ] , 0 , V_51 ) ;
memset ( & V_6 -> V_47 . V_55 . V_50 [ V_51 ] , 0xff , V_51 ) ;
}
static int F_20 ( struct V_29 * V_30 , T_2 V_56 , T_2 V_57 ,
T_2 V_58 , char * V_31 , T_2 V_59 )
{
struct V_16 * V_16 ;
struct V_17 * V_17 ;
int V_32 = 0 ;
int V_18 ;
unsigned long V_20 ;
T_1 V_60 [ V_33 ] ;
if ( ! F_14 ( V_30 ) )
return - V_61 ;
V_58 = ( ( V_62 ) ( V_58 & 0x00ff ) ) ;
F_5 ( L_9 , V_56 , V_57 ,
V_58 ) ;
if ( V_58 > V_33 )
F_21 ( L_10 , V_58 ) ;
V_18 = V_58 - 1 ;
V_16 = F_12 ( V_30 ) ;
V_17 = V_16 -> V_17 ;
F_6 ( & V_17 -> V_21 , V_20 ) ;
if ( V_63 ) {
memcpy ( V_60 , V_16 -> V_22 ,
sizeof( V_60 ) ) ;
}
switch ( V_56 ) {
case V_64 :
F_5 ( L_11 ) ;
break;
case V_65 :
switch ( V_57 ) {
case V_66 :
if ( V_30 -> V_15 == V_67 ) {
F_21 ( L_12
L_13 ) ;
goto error;
}
F_5 (
L_14 ) ;
if ( V_16 -> V_22 [ V_18 ] & V_68 ) {
V_16 -> V_69 = 1 ;
V_16 -> V_70 = V_71 + F_22 ( 20 ) ;
}
break;
case V_72 :
F_5 (
L_15 ) ;
if ( V_30 -> V_15 == V_67 )
V_16 -> V_22 [ V_18 ] &= ~ V_73 ;
else
V_16 -> V_22 [ V_18 ] &= ~ V_74 ;
break;
default:
F_5 ( L_16 ,
V_57 ) ;
V_16 -> V_22 [ V_18 ] &= ~ ( 1 << V_57 ) ;
break;
}
break;
case V_75 :
F_5 ( L_17 ) ;
if ( V_30 -> V_15 == V_67 &&
( V_59 < V_76 ||
V_57 != ( V_41 << 8 ) ) ) {
F_21 ( L_18 ) ;
goto error;
}
if ( V_30 -> V_15 == V_67 )
F_16 ( (struct V_39 * ) V_31 ) ;
else
F_18 ( (struct V_39 * ) V_31 ) ;
break;
case V_77 | V_78 :
if ( V_30 -> V_15 != V_67 )
goto error;
if ( ( V_57 >> 8 ) != V_79 )
goto error;
memcpy ( V_31 , & V_80 , sizeof( V_80 ) ) ;
V_32 = sizeof( V_80 ) ;
break;
case V_81 :
F_5 ( L_19 ) ;
* ( V_82 * ) V_31 = F_23 ( 0 ) ;
break;
case V_83 :
F_5 ( L_20 , V_58 ) ;
if ( V_58 < 1 ) {
F_21 ( L_10 , V_58 ) ;
V_32 = - V_84 ;
}
if ( V_16 -> V_69 && F_24 ( V_71 , V_16 -> V_70 ) ) {
V_16 -> V_22 [ V_18 ] |= ( 1 << V_85 ) ;
V_16 -> V_22 [ V_18 ] &= ~ ( 1 << V_66 ) ;
V_16 -> V_69 = 0 ;
V_16 -> V_70 = 0 ;
}
if ( ( V_16 -> V_22 [ V_18 ] & ( 1 << V_86 ) ) !=
0 && F_24 ( V_71 , V_16 -> V_70 ) ) {
V_16 -> V_22 [ V_18 ] |= ( 1 << V_87 ) ;
V_16 -> V_22 [ V_18 ] &= ~ ( 1 << V_86 ) ;
V_16 -> V_70 = 0 ;
if ( V_16 -> V_13 [ V_18 ] . V_88 . V_19 ==
V_89 ) {
F_5 (
L_21 ,
V_18 ,
V_16 -> V_13 [ V_18 ] . V_88 . V_19 ) ;
V_16 -> V_22 [ V_18 ] |=
V_90 ;
}
if ( V_30 -> V_15 < V_67 ) {
switch ( V_16 -> V_13 [ V_18 ] . V_15 ) {
case V_25 :
V_16 -> V_22 [ V_18 ] |=
V_26 ;
break;
case V_27 :
V_16 -> V_22 [ V_18 ] |=
V_28 ;
break;
default:
F_21 ( L_22 ) ;
break;
}
}
}
( ( V_91 * ) V_31 ) [ 0 ] = F_17 ( V_16 -> V_22 [ V_18 ] ) ;
( ( V_91 * ) V_31 ) [ 1 ] =
F_17 ( V_16 -> V_22 [ V_18 ] >> 16 ) ;
F_5 ( L_23 , ( ( T_2 * ) V_31 ) [ 0 ] ,
( ( T_2 * ) V_31 ) [ 1 ] ) ;
break;
case V_92 :
F_5 ( L_24 ) ;
V_32 = - V_84 ;
break;
case V_93 :
switch ( V_57 ) {
case V_94 :
F_5 (
L_25 ) ;
if ( V_30 -> V_15 != V_67 ) {
F_21 ( L_26
L_27 ) ;
goto error;
}
break;
case V_95 :
F_5 (
L_28 ) ;
case V_96 :
F_5 (
L_29 ) ;
if ( V_30 -> V_15 != V_67 ) {
F_21 ( L_30
L_27 ) ;
goto error;
}
break;
case V_66 :
F_5 (
L_31 ) ;
if ( V_30 -> V_15 == V_67 ) {
F_21 ( L_32
L_13 ) ;
goto error;
}
V_16 -> V_22 [ V_18 ] |= V_68 ;
break;
case V_72 :
F_5 (
L_33 ) ;
if ( V_30 -> V_15 == V_67 )
V_16 -> V_22 [ V_18 ] |= V_73 ;
else
V_16 -> V_22 [ V_18 ] |= V_74 ;
break;
case V_97 :
F_5 (
L_34 ) ;
if ( V_30 -> V_15 != V_67 ) {
F_21 ( L_35
L_27 ) ;
goto error;
}
case V_86 :
F_5 (
L_36 ) ;
if ( V_30 -> V_15 == V_67 ) {
V_16 -> V_22 [ V_18 ] = 0 ;
V_16 -> V_22 [ V_18 ] =
( V_73 |
V_23 |
V_98 ) ;
} else if ( V_16 -> V_22 [ V_18 ] & V_90 ) {
V_16 -> V_22 [ V_18 ] &= ~ ( V_90
| V_28
| V_26 ) ;
}
V_16 -> V_70 = V_71 + F_22 ( 50 ) ;
default:
F_5 ( L_37 ,
V_57 ) ;
if ( V_30 -> V_15 == V_67 ) {
if ( ( V_16 -> V_22 [ V_18 ] &
V_73 ) != 0 ) {
V_16 -> V_22 [ V_18 ] |= ( 1 << V_57 ) ;
}
} else
if ( ( V_16 -> V_22 [ V_18 ] &
V_74 ) != 0 ) {
V_16 -> V_22 [ V_18 ] |= ( 1 << V_57 ) ;
}
}
break;
case V_99 :
F_5 ( L_38 ) ;
if ( V_30 -> V_15 != V_67 ) {
F_21 ( L_39
L_27 ) ;
goto error;
}
* ( V_82 * ) V_31 = F_23 ( 0 ) ;
break;
case V_100 :
F_5 ( L_40 ) ;
if ( V_30 -> V_15 != V_67 ) {
F_21 ( L_41
L_42 ) ;
goto error;
}
break;
default:
F_21 ( L_43 ,
V_56 , V_57 , V_58 , V_59 ) ;
error:
V_32 = - V_84 ;
}
if ( V_63 ) {
F_2 ( L_44 , V_18 ) ;
if ( V_18 >= 0 ) {
F_1 ( V_60 [ V_18 ] ,
V_16 -> V_22 [ V_18 ] ,
V_30 -> V_15 == V_67 ) ;
}
}
F_5 ( L_45 ) ;
F_7 ( & V_17 -> V_21 , V_20 ) ;
if ( ( V_16 -> V_22 [ V_18 ] & V_36 ) != 0 )
F_8 ( V_30 ) ;
return V_32 ;
}
static void F_25 ( struct V_101 * V_101 , struct V_12 * V_13 )
{
struct V_102 * V_103 ;
struct V_16 * V_16 ;
unsigned long V_20 ;
if ( ! V_13 ) {
F_21 ( L_46 ) ;
return;
}
V_16 = F_4 ( V_13 ) ;
V_103 = F_26 ( sizeof( struct V_102 ) , V_104 ) ;
if ( ! V_103 ) {
F_27 ( & V_13 -> V_88 , V_105 ) ;
return;
}
F_6 ( & V_13 -> V_106 , V_20 ) ;
V_103 -> V_107 = F_28 ( & V_16 -> V_107 ) ;
if ( V_103 -> V_107 == 0xffff )
F_29 ( & V_101 -> V_108 -> V_108 , L_47 ) ;
V_103 -> V_13 = V_13 ;
V_103 -> V_101 = V_101 ;
V_101 -> V_109 = ( void * ) V_103 ;
F_30 ( & V_103 -> V_110 , & V_13 -> V_111 ) ;
F_31 ( & V_13 -> V_112 ) ;
F_7 ( & V_13 -> V_106 , V_20 ) ;
}
static int F_32 ( struct V_29 * V_30 , struct V_101 * V_101 , T_3 V_113 )
{
struct V_16 * V_16 = F_12 ( V_30 ) ;
struct V_17 * V_17 = V_16 -> V_17 ;
struct V_114 * V_108 = & V_101 -> V_108 -> V_108 ;
T_4 V_115 = V_101 -> V_108 -> V_115 ;
int V_116 = 0 ;
struct V_12 * V_13 ;
unsigned long V_20 ;
F_33 ( L_48 ,
V_30 , V_101 , V_113 ) ;
if ( V_115 > V_33 ) {
F_21 ( L_10 , V_115 ) ;
return - V_117 ;
}
V_13 = & V_16 -> V_13 [ V_115 - 1 ] ;
F_34 ( ! V_101 -> V_118 && V_101 -> V_119 ) ;
F_6 ( & V_17 -> V_21 , V_20 ) ;
if ( V_101 -> V_19 != - V_120 ) {
F_35 ( V_108 , L_49 , V_101 -> V_19 ) ;
F_7 ( & V_17 -> V_21 , V_20 ) ;
return V_101 -> V_19 ;
}
F_36 ( & V_13 -> V_88 . V_21 ) ;
if ( V_13 -> V_88 . V_19 == V_121 ||
V_13 -> V_88 . V_19 == V_122 ) {
F_35 ( V_108 , L_50 , V_13 -> V_18 ) ;
F_37 ( & V_13 -> V_88 . V_21 ) ;
F_7 ( & V_17 -> V_21 , V_20 ) ;
return - V_117 ;
}
F_37 ( & V_13 -> V_88 . V_21 ) ;
V_116 = F_38 ( V_30 , V_101 ) ;
if ( V_116 )
goto V_123;
if ( F_39 ( V_101 -> V_124 ) == 0 ) {
V_62 type = F_40 ( V_101 -> V_124 ) ;
struct V_125 * V_126 =
(struct V_125 * ) V_101 -> V_127 ;
if ( type != V_128 || ! V_126 ) {
F_35 ( V_108 , L_51 ) ;
V_116 = - V_129 ;
goto V_130;
}
switch ( V_126 -> V_131 ) {
case V_132 :
F_29 ( V_108 , L_52 ,
V_126 -> V_57 , V_13 -> V_18 ) ;
F_41 ( V_13 -> V_133 ) ;
V_13 -> V_133 = F_42 ( V_101 -> V_108 ) ;
F_36 ( & V_13 -> V_88 . V_21 ) ;
V_13 -> V_88 . V_19 = V_134 ;
F_37 ( & V_13 -> V_88 . V_21 ) ;
if ( V_101 -> V_19 == - V_120 ) {
V_101 -> V_19 = 0 ;
}
goto V_130;
case V_78 :
if ( V_126 -> V_57 == F_17 ( V_135 << 8 ) )
F_33 (
L_53 ) ;
F_41 ( V_13 -> V_133 ) ;
V_13 -> V_133 = F_42 ( V_101 -> V_108 ) ;
goto V_136;
default:
F_35 ( V_108 ,
L_54 ,
V_126 -> V_131 ,
V_126 -> V_57 ) ;
V_116 = - V_129 ;
goto V_130;
}
}
V_136:
F_25 ( V_101 , V_13 ) ;
F_7 ( & V_17 -> V_21 , V_20 ) ;
return 0 ;
V_130:
F_43 ( V_30 , V_101 ) ;
V_123:
F_7 ( & V_17 -> V_21 , V_20 ) ;
if ( ! V_116 )
F_44 ( V_30 , V_101 , V_101 -> V_19 ) ;
return V_116 ;
}
static int F_45 ( struct V_29 * V_30 , struct V_101 * V_101 , int V_19 )
{
struct V_16 * V_16 = F_12 ( V_30 ) ;
struct V_17 * V_17 = V_16 -> V_17 ;
struct V_102 * V_103 ;
struct V_12 * V_13 ;
unsigned long V_20 ;
F_46 ( L_55 , V_101 ) ;
F_6 ( & V_17 -> V_21 , V_20 ) ;
V_103 = V_101 -> V_109 ;
if ( ! V_103 ) {
F_7 ( & V_17 -> V_21 , V_20 ) ;
return - V_137 ;
}
{
int V_116 = 0 ;
V_116 = F_47 ( V_30 , V_101 , V_19 ) ;
if ( V_116 ) {
F_7 ( & V_17 -> V_21 , V_20 ) ;
return V_116 ;
}
}
V_13 = V_103 -> V_13 ;
if ( ! V_13 -> V_88 . V_138 ) {
F_36 ( & V_13 -> V_106 ) ;
F_46 ( L_56 , V_13 ) ;
F_48 ( & V_103 -> V_110 ) ;
F_49 ( V_103 ) ;
V_101 -> V_109 = NULL ;
F_37 ( & V_13 -> V_106 ) ;
F_46 ( L_57 , V_101 ) ;
F_43 ( V_30 , V_101 ) ;
F_7 ( & V_17 -> V_21 , V_20 ) ;
F_44 ( V_30 , V_101 , V_101 -> V_19 ) ;
F_6 ( & V_17 -> V_21 , V_20 ) ;
} else {
struct V_139 * V_140 ;
F_36 ( & V_13 -> V_106 ) ;
V_140 = F_26 ( sizeof( struct V_139 ) , V_104 ) ;
if ( ! V_140 ) {
F_37 ( & V_13 -> V_106 ) ;
F_7 ( & V_17 -> V_21 , V_20 ) ;
F_27 ( & V_13 -> V_88 , V_105 ) ;
return - V_141 ;
}
V_140 -> V_107 = F_28 ( & V_16 -> V_107 ) ;
if ( V_140 -> V_107 == 0xffff )
F_46 ( L_47 ) ;
V_140 -> V_142 = V_103 -> V_107 ;
F_46 ( L_58 , V_13 ) ;
F_30 ( & V_140 -> V_110 , & V_13 -> V_143 ) ;
F_31 ( & V_13 -> V_112 ) ;
F_37 ( & V_13 -> V_106 ) ;
}
F_7 ( & V_17 -> V_21 , V_20 ) ;
F_33 ( L_59 ) ;
return 0 ;
}
static void F_50 ( struct V_12 * V_13 )
{
struct V_16 * V_16 = F_4 ( V_13 ) ;
struct V_29 * V_30 = F_9 ( V_16 ) ;
struct V_17 * V_17 = V_16 -> V_17 ;
struct V_139 * V_140 , * V_144 ;
unsigned long V_20 ;
F_6 ( & V_17 -> V_21 , V_20 ) ;
F_36 ( & V_13 -> V_106 ) ;
F_51 (unlink, tmp, &vdev->unlink_tx, list) {
F_46 ( L_60 , V_140 -> V_142 ) ;
F_48 ( & V_140 -> V_110 ) ;
F_49 ( V_140 ) ;
}
while ( ! F_52 ( & V_13 -> V_145 ) ) {
struct V_101 * V_101 ;
V_140 = F_53 ( & V_13 -> V_145 , struct V_139 ,
V_110 ) ;
F_46 ( L_61 , V_140 -> V_142 ) ;
V_101 = F_54 ( V_13 , V_140 -> V_142 ) ;
if ( ! V_101 ) {
F_46 ( L_62 ,
V_140 -> V_142 ) ;
F_48 ( & V_140 -> V_110 ) ;
F_49 ( V_140 ) ;
continue;
}
V_101 -> V_19 = - V_117 ;
F_43 ( V_30 , V_101 ) ;
F_48 ( & V_140 -> V_110 ) ;
F_37 ( & V_13 -> V_106 ) ;
F_7 ( & V_17 -> V_21 , V_20 ) ;
F_44 ( V_30 , V_101 , V_101 -> V_19 ) ;
F_6 ( & V_17 -> V_21 , V_20 ) ;
F_36 ( & V_13 -> V_106 ) ;
F_49 ( V_140 ) ;
}
F_37 ( & V_13 -> V_106 ) ;
F_7 ( & V_17 -> V_21 , V_20 ) ;
}
static void F_55 ( struct V_146 * V_88 )
{
struct V_12 * V_13 = F_56 ( V_88 , struct V_12 , V_88 ) ;
if ( V_88 -> V_138 ) {
F_2 ( L_63 , V_88 -> V_138 ) ;
F_57 ( V_88 -> V_138 , V_147 ) ;
}
if ( V_13 -> V_88 . V_148 ) {
F_58 ( V_13 -> V_88 . V_148 ) ;
V_13 -> V_88 . V_148 = NULL ;
}
if ( V_13 -> V_88 . V_149 ) {
F_58 ( V_13 -> V_88 . V_149 ) ;
V_13 -> V_88 . V_149 = NULL ;
}
F_46 ( L_64 ) ;
if ( V_13 -> V_88 . V_138 ) {
F_59 ( V_13 -> V_88 . V_138 ) ;
V_13 -> V_88 . V_138 = NULL ;
}
F_46 ( L_65 ) ;
F_50 ( V_13 ) ;
F_10 ( V_13 ) ;
F_46 ( L_66 ) ;
}
static void F_60 ( struct V_146 * V_88 )
{
struct V_12 * V_13 = F_56 ( V_88 , struct V_12 , V_88 ) ;
unsigned long V_20 ;
F_6 ( & V_88 -> V_21 , V_20 ) ;
V_13 -> V_15 = 0 ;
V_13 -> V_150 = 0 ;
F_41 ( V_13 -> V_133 ) ;
V_13 -> V_133 = NULL ;
if ( V_88 -> V_138 ) {
F_59 ( V_88 -> V_138 ) ;
V_88 -> V_138 = NULL ;
}
V_88 -> V_19 = V_121 ;
F_7 ( & V_88 -> V_21 , V_20 ) ;
}
static void F_61 ( struct V_146 * V_88 )
{
unsigned long V_20 ;
F_6 ( & V_88 -> V_21 , V_20 ) ;
V_88 -> V_19 = V_122 ;
F_7 ( & V_88 -> V_21 , V_20 ) ;
}
static void F_62 ( struct V_12 * V_13 )
{
memset ( V_13 , 0 , sizeof( struct V_12 ) ) ;
V_13 -> V_88 . V_151 = V_152 ;
V_13 -> V_88 . V_19 = V_121 ;
F_63 ( & V_13 -> V_88 . V_21 ) ;
F_64 ( & V_13 -> V_153 ) ;
F_64 ( & V_13 -> V_111 ) ;
F_64 ( & V_13 -> V_143 ) ;
F_64 ( & V_13 -> V_145 ) ;
F_63 ( & V_13 -> V_106 ) ;
F_65 ( & V_13 -> V_112 ) ;
V_13 -> V_88 . V_154 . V_155 = F_55 ;
V_13 -> V_88 . V_154 . V_156 = F_60 ;
V_13 -> V_88 . V_154 . V_157 = F_61 ;
F_66 ( & V_13 -> V_88 ) ;
}
static int F_67 ( const char * V_158 )
{
char * V_159 ;
long V_160 ;
int V_116 ;
V_159 = strchr ( V_158 , '.' ) ;
if ( V_159 == NULL )
return 0 ;
V_116 = F_68 ( V_159 + 1 , 10 , & V_160 ) ;
if ( V_116 < 0 )
return V_116 ;
return V_160 ;
}
static int F_69 ( struct V_29 * V_30 )
{
struct V_17 * V_17 = * ( ( void * * ) F_70 ( V_30 -> V_161 . V_162 ) ) ;
V_30 -> V_161 . V_163 = ~ 0 ;
if ( F_71 ( V_30 ) ) {
V_17 -> V_164 = F_12 ( V_30 ) ;
V_17 -> V_164 -> V_17 = V_17 ;
V_30 -> V_15 = V_165 ;
V_30 -> V_161 . V_166 -> V_15 = V_25 ;
} else {
V_17 -> V_167 = F_12 ( V_30 ) ;
V_17 -> V_167 -> V_17 = V_17 ;
V_30 -> V_15 = V_67 ;
V_30 -> V_161 . V_166 -> V_15 = V_168 ;
}
return 0 ;
}
static int F_72 ( struct V_29 * V_30 )
{
struct V_16 * V_16 = F_12 ( V_30 ) ;
int V_169 , V_18 ;
int V_170 ;
F_33 ( L_67 ) ;
if ( F_71 ( V_30 ) )
F_63 ( & V_16 -> V_17 -> V_21 ) ;
for ( V_18 = 0 ; V_18 < V_33 ; V_18 ++ ) {
struct V_12 * V_13 = & V_16 -> V_13 [ V_18 ] ;
F_62 ( V_13 ) ;
V_13 -> V_18 = V_18 ;
}
F_73 ( & V_16 -> V_107 , 0 ) ;
V_30 -> V_171 = 0 ;
V_30 -> V_172 = 1 ;
#ifdef F_74
V_30 -> V_161 . V_173 = 1 ;
#endif
V_169 = F_67 ( F_75 ( V_30 ) ) ;
if ( V_169 < 0 ) {
F_21 ( L_68 , F_75 ( V_30 ) ) ;
return - V_129 ;
}
if ( V_169 == 0 && F_71 ( V_30 ) ) {
V_170 = F_76 () ;
if ( V_170 ) {
F_21 ( L_69 ) ;
return V_170 ;
}
V_170 = F_77 ( & F_78 ( V_30 ) -> V_174 , & V_175 ) ;
if ( V_170 ) {
F_21 ( L_70 ) ;
F_79 () ;
return V_170 ;
}
F_46 ( L_71 , F_75 ( V_30 ) ) ;
}
return 0 ;
}
static void F_80 ( struct V_29 * V_30 )
{
struct V_16 * V_16 = F_12 ( V_30 ) ;
int V_169 , V_18 ;
F_33 ( L_72 ) ;
V_169 = F_67 ( F_75 ( V_30 ) ) ;
if ( V_169 == 0 && F_71 ( V_30 ) ) {
F_81 ( & F_78 ( V_30 ) -> V_174 , & V_175 ) ;
F_79 () ;
}
for ( V_18 = 0 ; V_18 < V_33 ; V_18 ++ ) {
struct V_12 * V_13 = & V_16 -> V_13 [ V_18 ] ;
F_27 ( & V_13 -> V_88 , V_176 ) ;
F_82 ( & V_13 -> V_88 ) ;
}
}
static int F_83 ( struct V_29 * V_30 )
{
F_84 ( & V_30 -> V_161 . V_166 -> V_108 , L_73 ) ;
return 0 ;
}
static int F_85 ( struct V_29 * V_30 )
{
struct V_17 * V_17 = * ( ( void * * ) F_70 ( V_30 -> V_161 . V_162 ) ) ;
unsigned long V_20 ;
F_86 ( & V_30 -> V_161 . V_166 -> V_108 , L_74 , V_177 ) ;
F_6 ( & V_17 -> V_21 , V_20 ) ;
V_30 -> V_37 = V_38 ;
F_7 ( & V_17 -> V_21 , V_20 ) ;
return 0 ;
}
static int F_87 ( struct V_29 * V_30 )
{
struct V_17 * V_17 = * ( ( void * * ) F_70 ( V_30 -> V_161 . V_162 ) ) ;
int V_178 = 0 ;
unsigned long V_20 ;
F_86 ( & V_30 -> V_161 . V_166 -> V_108 , L_74 , V_177 ) ;
F_6 ( & V_17 -> V_21 , V_20 ) ;
if ( ! F_14 ( V_30 ) )
V_178 = - V_179 ;
else
V_30 -> V_37 = V_180 ;
F_7 ( & V_17 -> V_21 , V_20 ) ;
return V_178 ;
}
static int F_88 ( struct V_29 * V_30 , struct V_181 * V_133 ,
struct V_182 * * V_183 , unsigned int V_184 ,
unsigned int V_185 , T_3 V_113 )
{
F_86 ( & V_30 -> V_161 . V_166 -> V_108 , L_75 ) ;
return 0 ;
}
static int F_89 ( struct V_29 * V_30 , struct V_181 * V_133 ,
struct V_182 * * V_183 , unsigned int V_184 ,
T_3 V_113 )
{
F_86 ( & V_30 -> V_161 . V_166 -> V_108 , L_76 ) ;
return 0 ;
}
static int F_90 ( struct V_186 * V_187 )
{
struct V_17 * V_17 = * ( ( void * * ) F_70 ( & V_187 -> V_108 ) ) ;
struct V_29 * V_188 ;
struct V_29 * V_189 ;
int V_116 ;
F_33 ( L_77 , V_187 -> V_158 , V_187 -> V_169 ) ;
V_188 = F_91 ( & V_190 , & V_187 -> V_108 , F_92 ( & V_187 -> V_108 ) ) ;
if ( ! V_188 ) {
F_21 ( L_78 ) ;
return - V_141 ;
}
V_188 -> V_191 = 1 ;
V_116 = F_93 ( V_188 , 0 , 0 ) ;
if ( V_116 != 0 ) {
F_21 ( L_79 , V_116 ) ;
goto V_192;
}
V_189 = F_94 ( & V_190 , & V_187 -> V_108 ,
F_92 ( & V_187 -> V_108 ) , V_188 ) ;
if ( ! V_189 ) {
V_116 = - V_141 ;
F_21 ( L_80 ) ;
goto V_193;
}
V_116 = F_93 ( V_189 , 0 , 0 ) ;
if ( V_116 ) {
F_21 ( L_81 , V_116 ) ;
goto V_194;
}
F_33 ( L_82 ) ;
return 0 ;
V_194:
F_95 ( V_189 ) ;
V_193:
F_96 ( V_188 ) ;
V_192:
F_95 ( V_188 ) ;
V_17 -> V_164 = NULL ;
V_17 -> V_167 = NULL ;
return V_116 ;
}
static int F_97 ( struct V_186 * V_187 )
{
struct V_17 * V_17 = * ( ( void * * ) F_70 ( & V_187 -> V_108 ) ) ;
F_96 ( F_9 ( V_17 -> V_167 ) ) ;
F_95 ( F_9 ( V_17 -> V_167 ) ) ;
F_96 ( F_9 ( V_17 -> V_164 ) ) ;
F_95 ( F_9 ( V_17 -> V_164 ) ) ;
V_17 -> V_164 = NULL ;
V_17 -> V_167 = NULL ;
return 0 ;
}
static int F_98 ( struct V_186 * V_187 , T_5 V_37 )
{
struct V_29 * V_30 ;
struct V_17 * V_17 ;
int V_18 ;
int V_195 = 0 ;
int V_116 = 0 ;
unsigned long V_20 ;
F_86 ( & V_187 -> V_108 , L_74 , V_177 ) ;
V_30 = F_99 ( V_187 ) ;
if ( ! V_30 )
return 0 ;
V_17 = * ( ( void * * ) F_70 ( V_30 -> V_161 . V_162 ) ) ;
F_6 ( & V_17 -> V_21 , V_20 ) ;
for ( V_18 = 0 ; V_18 < V_33 ; V_18 ++ ) {
if ( V_17 -> V_164 -> V_22 [ V_18 ] &
V_23 )
V_195 += 1 ;
if ( V_17 -> V_167 -> V_22 [ V_18 ] &
V_23 )
V_195 += 1 ;
}
F_7 ( & V_17 -> V_21 , V_20 ) ;
if ( V_195 > 0 ) {
F_29 ( & V_187 -> V_108 ,
L_83 ,
V_195 , ( V_195 == 1 ? L_84 : L_85 ) ) ;
V_116 = - V_196 ;
} else {
F_29 ( & V_187 -> V_108 , L_86 ) ;
F_100 ( V_197 , & V_30 -> V_20 ) ;
}
return V_116 ;
}
static int F_101 ( struct V_186 * V_187 )
{
struct V_29 * V_30 ;
F_86 ( & V_187 -> V_108 , L_74 , V_177 ) ;
V_30 = F_99 ( V_187 ) ;
if ( ! V_30 )
return 0 ;
F_102 ( V_197 , & V_30 -> V_20 ) ;
F_8 ( V_30 ) ;
return 0 ;
}
static void F_103 ( void )
{
struct V_186 * V_187 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_198 ; V_4 ++ ) {
V_187 = V_199 [ V_4 ] . V_187 ;
if ( V_187 != NULL )
F_104 ( V_187 ) ;
V_199 [ V_4 ] . V_187 = NULL ;
}
F_105 ( & V_200 . V_174 , V_201 ) ;
}
static int T_6 F_106 ( void )
{
int V_4 , V_116 ;
if ( F_107 () )
return - V_117 ;
if ( V_198 < 1 )
V_198 = 1 ;
V_199 = F_108 ( V_198 , sizeof( struct V_17 ) , V_202 ) ;
if ( V_199 == NULL )
return - V_141 ;
for ( V_4 = 0 ; V_4 < V_198 ; V_4 ++ ) {
V_199 [ V_4 ] . V_187 = F_109 ( V_201 , V_4 ) ;
if ( ! V_199 [ V_4 ] . V_187 ) {
V_4 -- ;
while ( V_4 >= 0 )
F_110 ( V_199 [ V_4 -- ] . V_187 ) ;
V_116 = - V_141 ;
goto V_203;
}
}
for ( V_4 = 0 ; V_4 < V_198 ; V_4 ++ ) {
void * V_17 = & V_199 [ V_4 ] ;
V_116 = F_111 ( V_199 [ V_4 ] . V_187 , & V_17 , sizeof( void * ) ) ;
if ( V_116 )
goto V_204;
}
V_116 = F_112 ( & V_205 ) ;
if ( V_116 )
goto V_204;
for ( V_4 = 0 ; V_4 < V_198 ; V_4 ++ ) {
V_116 = F_113 ( V_199 [ V_4 ] . V_187 ) ;
if ( V_116 < 0 ) {
V_4 -- ;
while ( V_4 >= 0 )
F_114 ( V_199 [ V_4 -- ] . V_187 ) ;
goto V_206;
}
}
return V_116 ;
V_206:
F_115 ( & V_205 ) ;
V_204:
for ( V_4 = 0 ; V_4 < V_198 ; V_4 ++ )
F_110 ( V_199 [ V_4 ] . V_187 ) ;
V_203:
F_49 ( V_199 ) ;
return V_116 ;
}
static void T_7 F_116 ( void )
{
F_103 () ;
F_115 ( & V_205 ) ;
F_49 ( V_199 ) ;
}
