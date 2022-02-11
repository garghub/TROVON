static struct V_1 * F_1 ( T_1 V_2 , T_2 V_3 )
{
struct V_1 * V_4 ;
struct V_5 * V_6 ;
F_2 () ;
V_4 = F_3 ( V_7 [ V_2 ] ) ;
if ( V_4 ) {
V_6 = & V_4 -> V_8 . V_9 ;
if ( V_6 -> V_10 . V_11 . V_3 != V_3 )
V_4 = NULL ;
else
F_4 ( F_5 ( V_4 ) ) ;
}
F_6 () ;
return V_4 ;
}
static int F_7 ( T_1 V_2 , T_2 V_12 )
{
struct V_1 * V_4 ;
struct V_5 * V_6 ;
int V_13 ;
F_2 () ;
V_13 = 1 ;
F_8 (i, callid_bitmap, MAX_CALLID) {
V_4 = F_3 ( V_7 [ V_13 ] ) ;
if ( ! V_4 )
continue;
V_6 = & V_4 -> V_8 . V_9 ;
if ( V_6 -> V_10 . V_2 == V_2 &&
V_6 -> V_10 . V_11 . V_3 == V_12 )
break;
}
F_6 () ;
return V_13 < V_14 ;
}
static int F_9 ( struct V_1 * V_4 )
{
static int V_2 ;
F_10 ( & V_15 ) ;
if ( ! V_4 -> V_8 . V_9 . V_16 . V_2 ) {
V_2 = F_11 ( V_17 , V_14 , V_2 + 1 ) ;
if ( V_2 == V_14 ) {
V_2 = F_11 ( V_17 , V_14 , 1 ) ;
if ( V_2 == V_14 )
goto V_18;
}
V_4 -> V_8 . V_9 . V_16 . V_2 = V_2 ;
} else if ( F_12 ( V_4 -> V_8 . V_9 . V_16 . V_2 , V_17 ) )
goto V_18;
F_13 ( V_4 -> V_8 . V_9 . V_16 . V_2 , V_17 ) ;
F_14 ( V_7 [ V_4 -> V_8 . V_9 . V_16 . V_2 ] , V_4 ) ;
F_15 ( & V_15 ) ;
return 0 ;
V_18:
F_15 ( & V_15 ) ;
return - 1 ;
}
static void F_16 ( struct V_1 * V_4 )
{
F_10 ( & V_15 ) ;
F_17 ( V_4 -> V_8 . V_9 . V_16 . V_2 , V_17 ) ;
F_18 ( V_7 [ V_4 -> V_8 . V_9 . V_16 . V_2 ] , NULL ) ;
F_15 ( & V_15 ) ;
F_19 () ;
}
static int F_20 ( struct V_19 * V_20 , struct V_21 * V_22 )
{
struct V_4 * V_23 = (struct V_4 * ) V_20 -> V_24 ;
struct V_1 * V_25 = F_21 ( V_23 ) ;
struct V_5 * V_6 = & V_25 -> V_8 . V_9 ;
struct V_26 * V_27 ;
unsigned int V_28 = sizeof( * V_27 ) ;
struct V_29 V_30 ;
int V_31 ;
int V_32 ;
unsigned char * V_33 ;
T_3 V_34 ;
struct V_35 * V_36 ;
struct V_37 * V_38 ;
struct V_39 * V_40 ;
int V_41 ;
if ( F_5 ( V_25 ) -> V_42 & V_43 )
goto V_44;
V_36 = F_22 ( F_23 ( V_23 ) , & V_30 , NULL ,
V_6 -> V_10 . V_11 . V_3 ,
V_6 -> V_16 . V_11 . V_3 ,
0 , 0 , V_45 ,
F_24 ( 0 ) , 0 ) ;
if ( F_25 ( V_36 ) )
goto V_44;
V_38 = V_36 -> V_46 . V_47 ;
V_41 = F_26 ( V_38 ) + sizeof( * V_40 ) + sizeof( * V_27 ) + 2 ;
if ( F_27 ( V_22 ) < V_41 || F_28 ( V_22 ) || F_29 ( V_22 ) ) {
struct V_21 * V_48 = F_30 ( V_22 , V_41 ) ;
if ( ! V_48 ) {
F_31 ( V_36 ) ;
goto V_44;
}
if ( V_22 -> V_23 )
F_32 ( V_48 , V_22 -> V_23 ) ;
F_33 ( V_22 ) ;
V_22 = V_48 ;
}
V_33 = V_22 -> V_33 ;
V_31 = ( ( V_33 [ 0 ] << 8 ) + V_33 [ 1 ] ) == V_49 && 1 <= V_33 [ 2 ] && V_33 [ 2 ] <= 7 ;
if ( ( V_6 -> V_50 & V_51 ) && V_33 [ 0 ] == 0 && ! V_31 )
F_34 ( V_22 , 1 ) ;
if ( ( V_6 -> V_50 & V_52 ) == 0 || V_31 ) {
V_33 = F_35 ( V_22 , 2 ) ;
V_33 [ 0 ] = V_53 ;
V_33 [ 1 ] = V_54 ;
}
V_32 = V_22 -> V_32 ;
V_34 = V_6 -> V_34 ;
if ( V_6 -> V_55 == V_34 )
V_28 -= sizeof( V_27 -> V_56 ) ;
F_35 ( V_22 , V_28 ) ;
V_27 = (struct V_26 * ) ( V_22 -> V_33 ) ;
V_27 -> V_57 = V_58 ;
V_27 -> V_59 = V_60 ;
V_27 -> V_61 = F_36 ( V_62 ) ;
V_27 -> V_2 = F_36 ( V_6 -> V_10 . V_2 ) ;
V_27 -> V_57 |= V_63 ;
V_27 -> V_64 = F_37 ( ++ V_6 -> V_65 ) ;
if ( V_6 -> V_55 != V_34 ) {
V_27 -> V_59 |= V_66 ;
V_27 -> V_56 = F_37 ( V_34 ) ;
V_6 -> V_55 = V_34 ;
}
V_27 -> V_67 = F_36 ( V_32 ) ;
F_38 ( V_22 ) ;
F_35 ( V_22 , sizeof( * V_40 ) ) ;
F_39 ( V_22 ) ;
memset ( & ( F_40 ( V_22 ) -> V_6 ) , 0 , sizeof( F_40 ( V_22 ) -> V_6 ) ) ;
F_40 ( V_22 ) -> V_57 &= ~ ( V_68 | V_69 | V_70 ) ;
V_40 = F_41 ( V_22 ) ;
V_40 -> V_71 = 4 ;
V_40 -> V_72 = sizeof( struct V_39 ) >> 2 ;
if ( F_42 ( V_23 , & V_36 -> V_46 ) )
V_40 -> V_73 = F_36 ( V_74 ) ;
else
V_40 -> V_73 = 0 ;
V_40 -> V_61 = V_45 ;
V_40 -> V_75 = 0 ;
V_40 -> V_76 = V_30 . V_76 ;
V_40 -> V_77 = V_30 . V_77 ;
V_40 -> V_78 = F_43 ( & V_36 -> V_46 ) ;
V_40 -> V_79 = F_36 ( V_22 -> V_32 ) ;
F_44 ( V_22 ) ;
F_45 ( V_22 , & V_36 -> V_46 ) ;
F_46 ( V_22 ) ;
V_22 -> V_80 = V_81 ;
F_47 ( V_22 , NULL ) ;
F_48 ( V_40 ) ;
F_49 ( V_22 ) ;
return 1 ;
V_44:
F_50 ( V_22 ) ;
return 1 ;
}
static int F_51 ( struct V_4 * V_23 , struct V_21 * V_22 )
{
struct V_1 * V_25 = F_21 ( V_23 ) ;
struct V_5 * V_6 = & V_25 -> V_8 . V_9 ;
int V_82 , V_67 , V_64 ;
T_4 * V_83 ;
struct V_26 * V_84 ;
if ( ! ( V_23 -> V_42 & V_85 ) ) {
if ( F_52 ( V_23 , V_22 ) )
goto V_86;
return V_87 ;
}
V_84 = (struct V_26 * ) ( V_22 -> V_33 ) ;
V_82 = sizeof( * V_84 ) ;
if ( F_53 ( V_84 -> V_59 ) ) {
T_3 V_56 ;
if ( ! F_54 ( V_22 , V_82 ) )
goto V_86;
V_84 = (struct V_26 * ) ( V_22 -> V_33 ) ;
V_56 = F_55 ( V_84 -> V_57 ) ? V_84 -> V_56 : V_84 -> V_64 ;
V_56 = F_56 ( V_56 ) ;
if ( V_56 > V_6 -> V_88 )
V_6 -> V_88 = V_56 ;
if ( F_57 ( V_56 , V_6 -> V_88 ) )
V_6 -> V_88 = V_56 ;
} else {
V_82 -= sizeof( V_84 -> V_56 ) ;
}
if ( ! F_55 ( V_84 -> V_57 ) )
goto V_86;
V_67 = F_58 ( V_84 -> V_67 ) ;
V_64 = F_56 ( V_84 -> V_64 ) ;
if ( ! F_54 ( V_22 , V_82 + V_67 ) )
goto V_86;
V_83 = V_22 -> V_33 + V_82 ;
if ( V_64 < V_6 -> V_34 + 1 || F_57 ( V_6 -> V_34 , V_64 ) ) {
if ( ( V_83 [ 0 ] == V_53 ) && ( V_83 [ 1 ] == V_54 ) &&
( F_59 ( V_83 ) == V_49 ) &&
( ( V_83 [ 4 ] == V_89 ) || ( V_83 [ 4 ] == V_90 ) ) )
goto V_91;
} else {
V_6 -> V_34 = V_64 ;
V_91:
F_34 ( V_22 , V_82 ) ;
if ( V_83 [ 0 ] == V_53 && V_83 [ 1 ] == V_54 ) {
if ( V_22 -> V_32 < 3 )
goto V_86;
F_34 ( V_22 , 2 ) ;
}
if ( ( * V_22 -> V_33 ) & 1 ) {
F_35 ( V_22 , 1 ) [ 0 ] = 0 ;
}
V_22 -> V_80 = V_81 ;
F_60 ( V_22 , V_22 -> V_92 - V_22 -> V_33 ) ;
F_61 ( & V_25 -> V_20 , V_22 ) ;
return V_87 ;
}
V_86:
F_50 ( V_22 ) ;
return V_93 ;
}
static int F_62 ( struct V_21 * V_22 )
{
struct V_1 * V_25 ;
struct V_26 * V_84 ;
struct V_39 * V_40 ;
if ( V_22 -> V_94 != V_95 )
goto V_86;
if ( ! F_54 ( V_22 , 12 ) )
goto V_86;
V_40 = F_41 ( V_22 ) ;
V_84 = (struct V_26 * ) V_22 -> V_33 ;
if ( F_58 ( V_84 -> V_61 ) != V_62 ||
F_63 ( V_84 -> V_57 ) ||
F_64 ( V_84 -> V_57 ) ||
! F_65 ( V_84 -> V_57 ) ||
( V_84 -> V_57 & 0xF ) != 0 )
goto V_86;
V_25 = F_1 ( F_36 ( V_84 -> V_2 ) , V_40 -> V_77 ) ;
if ( V_25 ) {
F_44 ( V_22 ) ;
F_46 ( V_22 ) ;
return F_66 ( F_5 ( V_25 ) , V_22 , 0 ) ;
}
V_86:
F_50 ( V_22 ) ;
return V_93 ;
}
static int F_67 ( struct V_96 * V_4 , struct V_97 * V_98 ,
int V_99 )
{
struct V_4 * V_23 = V_4 -> V_23 ;
struct V_100 * V_101 = (struct V_100 * ) V_98 ;
struct V_1 * V_25 = F_21 ( V_23 ) ;
struct V_5 * V_6 = & V_25 -> V_8 . V_9 ;
int error = 0 ;
F_68 ( V_23 ) ;
V_6 -> V_16 = V_101 -> V_102 . V_9 ;
if ( F_9 ( V_25 ) )
error = - V_103 ;
F_69 ( V_23 ) ;
return error ;
}
static int F_70 ( struct V_96 * V_4 , struct V_97 * V_98 ,
int V_99 , int V_57 )
{
struct V_4 * V_23 = V_4 -> V_23 ;
struct V_100 * V_101 = (struct V_100 * ) V_98 ;
struct V_1 * V_25 = F_21 ( V_23 ) ;
struct V_5 * V_6 = & V_25 -> V_8 . V_9 ;
struct V_35 * V_36 ;
struct V_29 V_30 ;
int error = 0 ;
if ( V_101 -> V_104 != V_105 )
return - V_106 ;
if ( F_7 ( V_101 -> V_102 . V_9 . V_2 , V_101 -> V_102 . V_9 . V_11 . V_3 ) )
return - V_107 ;
F_68 ( V_23 ) ;
if ( V_23 -> V_42 & V_85 ) {
error = - V_103 ;
goto V_108;
}
if ( V_23 -> V_42 & V_43 ) {
error = - V_107 ;
goto V_108;
}
if ( ! V_6 -> V_16 . V_11 . V_3 || ! V_101 -> V_102 . V_9 . V_11 . V_3 ) {
error = - V_106 ;
goto V_108;
}
V_25 -> V_20 . V_24 = V_23 ;
V_25 -> V_20 . V_109 = & V_110 ;
V_36 = F_22 ( F_23 ( V_23 ) , & V_30 , V_23 ,
V_6 -> V_10 . V_11 . V_3 ,
V_6 -> V_16 . V_11 . V_3 ,
0 , 0 ,
V_45 , F_71 ( V_23 ) , 0 ) ;
if ( F_25 ( V_36 ) ) {
error = - V_111 ;
goto V_108;
}
F_72 ( V_23 , & V_36 -> V_46 ) ;
V_25 -> V_20 . V_112 = F_73 ( & V_36 -> V_46 ) ;
if ( ! V_25 -> V_20 . V_112 )
V_25 -> V_20 . V_112 = V_113 ;
F_31 ( V_36 ) ;
V_25 -> V_20 . V_112 -= V_114 ;
V_25 -> V_20 . V_115 = 2 + sizeof( struct V_26 ) ;
error = F_74 ( & V_25 -> V_20 ) ;
if ( error ) {
F_75 ( L_1 , error ) ;
goto V_108;
}
V_6 -> V_10 = V_101 -> V_102 . V_9 ;
V_23 -> V_42 = V_85 ;
V_108:
F_69 ( V_23 ) ;
return error ;
}
static int F_76 ( struct V_96 * V_4 , struct V_97 * V_116 ,
int * V_117 , int V_118 )
{
int V_32 = sizeof( struct V_100 ) ;
struct V_100 V_101 ;
memset ( & V_101 . V_102 , 0 , sizeof( V_101 . V_102 ) ) ;
V_101 . V_119 = V_120 ;
V_101 . V_104 = V_105 ;
V_101 . V_102 . V_9 = F_21 ( V_4 -> V_23 ) -> V_8 . V_9 . V_16 ;
memcpy ( V_116 , & V_101 , V_32 ) ;
* V_117 = V_32 ;
return 0 ;
}
static int F_77 ( struct V_96 * V_4 )
{
struct V_4 * V_23 = V_4 -> V_23 ;
struct V_1 * V_25 ;
struct V_5 * V_6 ;
int error = 0 ;
if ( ! V_23 )
return 0 ;
F_68 ( V_23 ) ;
if ( F_78 ( V_23 , V_121 ) ) {
F_69 ( V_23 ) ;
return - V_122 ;
}
V_25 = F_21 ( V_23 ) ;
V_6 = & V_25 -> V_8 . V_9 ;
F_16 ( V_25 ) ;
F_79 ( V_23 ) ;
V_23 -> V_42 = V_43 ;
F_80 ( V_23 ) ;
V_4 -> V_23 = NULL ;
F_69 ( V_23 ) ;
F_81 ( V_23 ) ;
return error ;
}
static void F_82 ( struct V_4 * V_23 )
{
if ( ! ( V_23 -> V_42 & V_43 ) ) {
F_16 ( F_21 ( V_23 ) ) ;
F_79 ( V_23 ) ;
}
F_83 ( & V_23 -> V_123 ) ;
}
static int F_84 ( struct V_124 * V_124 , struct V_96 * V_4 )
{
int error = - V_125 ;
struct V_4 * V_23 ;
struct V_1 * V_25 ;
struct V_5 * V_6 ;
V_23 = F_85 ( V_124 , V_126 , V_127 , & V_128 ) ;
if ( ! V_23 )
goto V_129;
F_86 ( V_4 , V_23 ) ;
V_4 -> V_130 = V_131 ;
V_4 -> V_109 = & V_132 ;
V_23 -> V_133 = F_51 ;
V_23 -> V_42 = V_134 ;
V_23 -> V_135 = V_136 ;
V_23 -> V_137 = V_126 ;
V_23 -> V_138 = V_105 ;
V_23 -> V_139 = F_82 ;
V_25 = F_21 ( V_23 ) ;
V_6 = & V_25 -> V_8 . V_9 ;
V_6 -> V_65 = 0 ; V_6 -> V_34 = 0xffffffff ;
V_6 -> V_88 = 0 ; V_6 -> V_55 = 0xffffffff ;
error = 0 ;
V_129:
return error ;
}
static int F_87 ( struct V_19 * V_20 , unsigned int V_140 ,
unsigned long V_141 )
{
struct V_4 * V_23 = (struct V_4 * ) V_20 -> V_24 ;
struct V_1 * V_25 = F_21 ( V_23 ) ;
struct V_5 * V_6 = & V_25 -> V_8 . V_9 ;
void T_5 * V_142 = ( void T_5 * ) V_141 ;
int T_5 * V_143 = V_142 ;
int V_144 , V_145 ;
V_144 = - V_146 ;
switch ( V_140 ) {
case V_147 :
V_145 = V_6 -> V_50 ;
if ( F_88 ( V_145 , V_143 ) )
break;
V_144 = 0 ;
break;
case V_148 :
if ( F_89 ( V_145 , V_143 ) )
break;
V_6 -> V_50 = V_145 & ~ V_149 ;
V_144 = 0 ;
break;
default:
V_144 = - V_150 ;
}
return V_144 ;
}
static int T_6 F_90 ( void )
{
int V_144 = 0 ;
F_91 ( L_2 V_151 L_3 ) ;
V_7 = F_92 ( ( V_14 + 1 ) * sizeof( void * ) ) ;
if ( ! V_7 )
return - V_125 ;
V_144 = F_93 ( & V_152 , V_153 ) ;
if ( V_144 ) {
F_75 ( L_4 ) ;
goto V_154;
}
V_144 = F_94 ( & V_128 , 0 ) ;
if ( V_144 ) {
F_75 ( L_5 ) ;
goto V_155;
}
V_144 = F_95 ( V_105 , & V_156 ) ;
if ( V_144 ) {
F_75 ( L_6 ) ;
goto V_157;
}
return 0 ;
V_157:
F_96 ( & V_128 ) ;
V_155:
F_97 ( & V_152 , V_153 ) ;
V_154:
F_98 ( V_7 ) ;
return V_144 ;
}
static void T_7 F_99 ( void )
{
F_100 ( V_105 ) ;
F_96 ( & V_128 ) ;
F_97 ( & V_152 , V_153 ) ;
F_98 ( V_7 ) ;
}
