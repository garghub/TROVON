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
struct V_26 * V_26 = F_22 ( V_23 ) ;
struct V_5 * V_6 = & V_25 -> V_8 . V_9 ;
struct V_27 * V_28 ;
unsigned int V_29 = sizeof( * V_28 ) ;
struct V_30 V_31 ;
int V_32 ;
int V_33 ;
unsigned char * V_34 ;
T_3 V_35 ;
struct V_36 * V_37 ;
struct V_38 * V_39 ;
struct V_40 * V_41 ;
int V_42 ;
if ( F_5 ( V_25 ) -> V_43 & V_44 )
goto V_45;
V_37 = F_23 ( V_26 , & V_31 , NULL ,
V_6 -> V_10 . V_11 . V_3 ,
V_6 -> V_16 . V_11 . V_3 ,
0 , 0 , V_46 ,
F_24 ( 0 ) , 0 ) ;
if ( F_25 ( V_37 ) )
goto V_45;
V_39 = V_37 -> V_47 . V_48 ;
V_42 = F_26 ( V_39 ) + sizeof( * V_41 ) + sizeof( * V_28 ) + 2 ;
if ( F_27 ( V_22 ) < V_42 || F_28 ( V_22 ) || F_29 ( V_22 ) ) {
struct V_21 * V_49 = F_30 ( V_22 , V_42 ) ;
if ( ! V_49 ) {
F_31 ( V_37 ) ;
goto V_45;
}
if ( V_22 -> V_23 )
F_32 ( V_49 , V_22 -> V_23 ) ;
F_33 ( V_22 ) ;
V_22 = V_49 ;
}
V_34 = V_22 -> V_34 ;
V_32 = ( ( V_34 [ 0 ] << 8 ) + V_34 [ 1 ] ) == V_50 && 1 <= V_34 [ 2 ] && V_34 [ 2 ] <= 7 ;
if ( ( V_6 -> V_51 & V_52 ) && V_34 [ 0 ] == 0 && ! V_32 )
F_34 ( V_22 , 1 ) ;
if ( ( V_6 -> V_51 & V_53 ) == 0 || V_32 ) {
V_34 = F_35 ( V_22 , 2 ) ;
V_34 [ 0 ] = V_54 ;
V_34 [ 1 ] = V_55 ;
}
V_33 = V_22 -> V_33 ;
V_35 = V_6 -> V_35 ;
if ( V_6 -> V_56 == V_35 )
V_29 -= sizeof( V_28 -> V_57 ) ;
F_35 ( V_22 , V_29 ) ;
V_28 = (struct V_27 * ) ( V_22 -> V_34 ) ;
V_28 -> V_58 = V_59 ;
V_28 -> V_60 = V_61 ;
V_28 -> V_62 = F_36 ( V_63 ) ;
V_28 -> V_2 = F_36 ( V_6 -> V_10 . V_2 ) ;
V_28 -> V_58 |= V_64 ;
V_28 -> V_65 = F_37 ( ++ V_6 -> V_66 ) ;
if ( V_6 -> V_56 != V_35 ) {
V_28 -> V_60 |= V_67 ;
V_28 -> V_57 = F_37 ( V_35 ) ;
V_6 -> V_56 = V_35 ;
}
V_28 -> V_68 = F_36 ( V_33 ) ;
F_38 ( V_22 ) ;
F_35 ( V_22 , sizeof( * V_41 ) ) ;
F_39 ( V_22 ) ;
memset ( & ( F_40 ( V_22 ) -> V_6 ) , 0 , sizeof( F_40 ( V_22 ) -> V_6 ) ) ;
F_40 ( V_22 ) -> V_58 &= ~ ( V_69 | V_70 | V_71 ) ;
V_41 = F_41 ( V_22 ) ;
V_41 -> V_72 = 4 ;
V_41 -> V_73 = sizeof( struct V_40 ) >> 2 ;
if ( F_42 ( V_23 , & V_37 -> V_47 ) )
V_41 -> V_74 = F_36 ( V_75 ) ;
else
V_41 -> V_74 = 0 ;
V_41 -> V_62 = V_46 ;
V_41 -> V_76 = 0 ;
V_41 -> V_77 = V_31 . V_77 ;
V_41 -> V_78 = V_31 . V_78 ;
V_41 -> V_79 = F_43 ( & V_37 -> V_47 ) ;
V_41 -> V_80 = F_36 ( V_22 -> V_33 ) ;
F_44 ( V_22 ) ;
F_45 ( V_22 , & V_37 -> V_47 ) ;
F_46 ( V_22 ) ;
V_22 -> V_81 = V_82 ;
F_47 ( V_26 , V_22 , NULL ) ;
F_48 ( V_41 ) ;
F_49 ( V_26 , V_22 -> V_23 , V_22 ) ;
return 1 ;
V_45:
F_50 ( V_22 ) ;
return 1 ;
}
static int F_51 ( struct V_4 * V_23 , struct V_21 * V_22 )
{
struct V_1 * V_25 = F_21 ( V_23 ) ;
struct V_5 * V_6 = & V_25 -> V_8 . V_9 ;
int V_83 , V_68 , V_65 ;
T_4 * V_84 ;
struct V_27 * V_85 ;
if ( ! ( V_23 -> V_43 & V_86 ) ) {
if ( F_52 ( V_23 , V_22 ) )
goto V_87;
return V_88 ;
}
V_85 = (struct V_27 * ) ( V_22 -> V_34 ) ;
V_83 = sizeof( * V_85 ) ;
if ( F_53 ( V_85 -> V_60 ) ) {
T_3 V_57 ;
if ( ! F_54 ( V_22 , V_83 ) )
goto V_87;
V_85 = (struct V_27 * ) ( V_22 -> V_34 ) ;
V_57 = F_55 ( V_85 -> V_58 ) ? V_85 -> V_57 : V_85 -> V_65 ;
V_57 = F_56 ( V_57 ) ;
if ( V_57 > V_6 -> V_89 )
V_6 -> V_89 = V_57 ;
if ( F_57 ( V_57 , V_6 -> V_89 ) )
V_6 -> V_89 = V_57 ;
} else {
V_83 -= sizeof( V_85 -> V_57 ) ;
}
if ( ! F_55 ( V_85 -> V_58 ) )
goto V_87;
V_68 = F_58 ( V_85 -> V_68 ) ;
V_65 = F_56 ( V_85 -> V_65 ) ;
if ( ! F_54 ( V_22 , V_83 + V_68 ) )
goto V_87;
V_84 = V_22 -> V_34 + V_83 ;
if ( V_65 < V_6 -> V_35 + 1 || F_57 ( V_6 -> V_35 , V_65 ) ) {
if ( ( V_84 [ 0 ] == V_54 ) && ( V_84 [ 1 ] == V_55 ) &&
( F_59 ( V_84 ) == V_50 ) &&
( ( V_84 [ 4 ] == V_90 ) || ( V_84 [ 4 ] == V_91 ) ) )
goto V_92;
} else {
V_6 -> V_35 = V_65 ;
V_92:
F_34 ( V_22 , V_83 ) ;
if ( V_84 [ 0 ] == V_54 && V_84 [ 1 ] == V_55 ) {
if ( V_22 -> V_33 < 3 )
goto V_87;
F_34 ( V_22 , 2 ) ;
}
if ( ( * V_22 -> V_34 ) & 1 ) {
F_35 ( V_22 , 1 ) [ 0 ] = 0 ;
}
V_22 -> V_81 = V_82 ;
F_60 ( V_22 , V_22 -> V_93 - V_22 -> V_34 ) ;
F_61 ( & V_25 -> V_20 , V_22 ) ;
return V_88 ;
}
V_87:
F_50 ( V_22 ) ;
return V_94 ;
}
static int F_62 ( struct V_21 * V_22 )
{
struct V_1 * V_25 ;
struct V_27 * V_85 ;
struct V_40 * V_41 ;
if ( V_22 -> V_95 != V_96 )
goto V_87;
if ( ! F_54 ( V_22 , 12 ) )
goto V_87;
V_41 = F_41 ( V_22 ) ;
V_85 = (struct V_27 * ) V_22 -> V_34 ;
if ( F_58 ( V_85 -> V_62 ) != V_63 ||
F_63 ( V_85 -> V_58 ) ||
F_64 ( V_85 -> V_58 ) ||
! F_65 ( V_85 -> V_58 ) ||
( V_85 -> V_58 & 0xF ) != 0 )
goto V_87;
V_25 = F_1 ( F_36 ( V_85 -> V_2 ) , V_41 -> V_78 ) ;
if ( V_25 ) {
F_44 ( V_22 ) ;
F_46 ( V_22 ) ;
return F_66 ( F_5 ( V_25 ) , V_22 , 0 ) ;
}
V_87:
F_50 ( V_22 ) ;
return V_94 ;
}
static int F_67 ( struct V_97 * V_4 , struct V_98 * V_99 ,
int V_100 )
{
struct V_4 * V_23 = V_4 -> V_23 ;
struct V_101 * V_102 = (struct V_101 * ) V_99 ;
struct V_1 * V_25 = F_21 ( V_23 ) ;
struct V_5 * V_6 = & V_25 -> V_8 . V_9 ;
int error = 0 ;
if ( V_100 < sizeof( struct V_101 ) )
return - V_103 ;
F_68 ( V_23 ) ;
V_6 -> V_16 = V_102 -> V_104 . V_9 ;
if ( F_9 ( V_25 ) )
error = - V_105 ;
F_69 ( V_23 ) ;
return error ;
}
static int F_70 ( struct V_97 * V_4 , struct V_98 * V_99 ,
int V_100 , int V_58 )
{
struct V_4 * V_23 = V_4 -> V_23 ;
struct V_101 * V_102 = (struct V_101 * ) V_99 ;
struct V_1 * V_25 = F_21 ( V_23 ) ;
struct V_5 * V_6 = & V_25 -> V_8 . V_9 ;
struct V_36 * V_37 ;
struct V_30 V_31 ;
int error = 0 ;
if ( V_100 < sizeof( struct V_101 ) )
return - V_103 ;
if ( V_102 -> V_106 != V_107 )
return - V_103 ;
if ( F_7 ( V_102 -> V_104 . V_9 . V_2 , V_102 -> V_104 . V_9 . V_11 . V_3 ) )
return - V_108 ;
F_68 ( V_23 ) ;
if ( V_23 -> V_43 & V_86 ) {
error = - V_105 ;
goto V_109;
}
if ( V_23 -> V_43 & V_44 ) {
error = - V_108 ;
goto V_109;
}
if ( ! V_6 -> V_16 . V_11 . V_3 || ! V_102 -> V_104 . V_9 . V_11 . V_3 ) {
error = - V_103 ;
goto V_109;
}
V_25 -> V_20 . V_24 = V_23 ;
V_25 -> V_20 . V_110 = & V_111 ;
V_37 = F_23 ( F_22 ( V_23 ) , & V_31 , V_23 ,
V_6 -> V_10 . V_11 . V_3 ,
V_6 -> V_16 . V_11 . V_3 ,
0 , 0 ,
V_46 , F_71 ( V_23 ) , 0 ) ;
if ( F_25 ( V_37 ) ) {
error = - V_112 ;
goto V_109;
}
F_72 ( V_23 , & V_37 -> V_47 ) ;
V_25 -> V_20 . V_113 = F_73 ( & V_37 -> V_47 ) ;
if ( ! V_25 -> V_20 . V_113 )
V_25 -> V_20 . V_113 = V_114 ;
F_31 ( V_37 ) ;
V_25 -> V_20 . V_113 -= V_115 ;
V_25 -> V_20 . V_116 = 2 + sizeof( struct V_27 ) ;
error = F_74 ( & V_25 -> V_20 ) ;
if ( error ) {
F_75 ( L_1 , error ) ;
goto V_109;
}
V_6 -> V_10 = V_102 -> V_104 . V_9 ;
V_23 -> V_43 = V_86 ;
V_109:
F_69 ( V_23 ) ;
return error ;
}
static int F_76 ( struct V_97 * V_4 , struct V_98 * V_117 ,
int * V_118 , int V_119 )
{
int V_33 = sizeof( struct V_101 ) ;
struct V_101 V_102 ;
memset ( & V_102 . V_104 , 0 , sizeof( V_102 . V_104 ) ) ;
V_102 . V_120 = V_121 ;
V_102 . V_106 = V_107 ;
V_102 . V_104 . V_9 = F_21 ( V_4 -> V_23 ) -> V_8 . V_9 . V_16 ;
memcpy ( V_117 , & V_102 , V_33 ) ;
* V_118 = V_33 ;
return 0 ;
}
static int F_77 ( struct V_97 * V_4 )
{
struct V_4 * V_23 = V_4 -> V_23 ;
struct V_1 * V_25 ;
struct V_5 * V_6 ;
int error = 0 ;
if ( ! V_23 )
return 0 ;
F_68 ( V_23 ) ;
if ( F_78 ( V_23 , V_122 ) ) {
F_69 ( V_23 ) ;
return - V_123 ;
}
V_25 = F_21 ( V_23 ) ;
V_6 = & V_25 -> V_8 . V_9 ;
F_16 ( V_25 ) ;
F_79 ( V_23 ) ;
V_23 -> V_43 = V_44 ;
F_80 ( V_23 ) ;
V_4 -> V_23 = NULL ;
F_69 ( V_23 ) ;
F_81 ( V_23 ) ;
return error ;
}
static void F_82 ( struct V_4 * V_23 )
{
if ( ! ( V_23 -> V_43 & V_44 ) ) {
F_16 ( F_21 ( V_23 ) ) ;
F_79 ( V_23 ) ;
}
F_83 ( & V_23 -> V_124 ) ;
}
static int F_84 ( struct V_26 * V_26 , struct V_97 * V_4 , int V_125 )
{
int error = - V_126 ;
struct V_4 * V_23 ;
struct V_1 * V_25 ;
struct V_5 * V_6 ;
V_23 = F_85 ( V_26 , V_127 , V_128 , & V_129 , V_125 ) ;
if ( ! V_23 )
goto V_130;
F_86 ( V_4 , V_23 ) ;
V_4 -> V_131 = V_132 ;
V_4 -> V_110 = & V_133 ;
V_23 -> V_134 = F_51 ;
V_23 -> V_43 = V_135 ;
V_23 -> V_136 = V_137 ;
V_23 -> V_138 = V_127 ;
V_23 -> V_139 = V_107 ;
V_23 -> V_140 = F_82 ;
V_25 = F_21 ( V_23 ) ;
V_6 = & V_25 -> V_8 . V_9 ;
V_6 -> V_66 = 0 ; V_6 -> V_35 = 0xffffffff ;
V_6 -> V_89 = 0 ; V_6 -> V_56 = 0xffffffff ;
error = 0 ;
V_130:
return error ;
}
static int F_87 ( struct V_19 * V_20 , unsigned int V_141 ,
unsigned long V_142 )
{
struct V_4 * V_23 = (struct V_4 * ) V_20 -> V_24 ;
struct V_1 * V_25 = F_21 ( V_23 ) ;
struct V_5 * V_6 = & V_25 -> V_8 . V_9 ;
void T_5 * V_143 = ( void T_5 * ) V_142 ;
int T_5 * V_144 = V_143 ;
int V_145 , V_146 ;
V_145 = - V_147 ;
switch ( V_141 ) {
case V_148 :
V_146 = V_6 -> V_51 ;
if ( F_88 ( V_146 , V_144 ) )
break;
V_145 = 0 ;
break;
case V_149 :
if ( F_89 ( V_146 , V_144 ) )
break;
V_6 -> V_51 = V_146 & ~ V_150 ;
V_145 = 0 ;
break;
default:
V_145 = - V_151 ;
}
return V_145 ;
}
static int T_6 F_90 ( void )
{
int V_145 = 0 ;
F_91 ( L_2 V_152 L_3 ) ;
V_7 = F_92 ( ( V_14 + 1 ) * sizeof( void * ) ) ;
if ( ! V_7 )
return - V_126 ;
V_145 = F_93 ( & V_153 , V_154 ) ;
if ( V_145 ) {
F_75 ( L_4 ) ;
goto V_155;
}
V_145 = F_94 ( & V_129 , 0 ) ;
if ( V_145 ) {
F_75 ( L_5 ) ;
goto V_156;
}
V_145 = F_95 ( V_107 , & V_157 ) ;
if ( V_145 ) {
F_75 ( L_6 ) ;
goto V_158;
}
return 0 ;
V_158:
F_96 ( & V_129 ) ;
V_156:
F_97 ( & V_153 , V_154 ) ;
V_155:
F_98 ( V_7 ) ;
return V_145 ;
}
static void T_7 F_99 ( void )
{
F_100 ( V_107 ) ;
F_96 ( & V_129 ) ;
F_97 ( & V_153 , V_154 ) ;
F_98 ( V_7 ) ;
}
