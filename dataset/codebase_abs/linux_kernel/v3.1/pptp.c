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
for ( V_13 = F_8 ( V_14 , V_15 , 1 ) ; V_13 < V_15 ;
V_13 = F_8 ( V_14 , V_15 , V_13 + 1 ) ) {
V_4 = F_3 ( V_7 [ V_13 ] ) ;
if ( ! V_4 )
continue;
V_6 = & V_4 -> V_8 . V_9 ;
if ( V_6 -> V_10 . V_2 == V_2 &&
V_6 -> V_10 . V_11 . V_3 == V_12 )
break;
}
F_6 () ;
return V_13 < V_15 ;
}
static int F_9 ( struct V_1 * V_4 )
{
static int V_2 ;
F_10 ( & V_16 ) ;
if ( ! V_4 -> V_8 . V_9 . V_17 . V_2 ) {
V_2 = F_11 ( V_14 , V_15 , V_2 + 1 ) ;
if ( V_2 == V_15 ) {
V_2 = F_11 ( V_14 , V_15 , 1 ) ;
if ( V_2 == V_15 )
goto V_18;
}
V_4 -> V_8 . V_9 . V_17 . V_2 = V_2 ;
} else if ( F_12 ( V_4 -> V_8 . V_9 . V_17 . V_2 , V_14 ) )
goto V_18;
F_13 ( V_4 -> V_8 . V_9 . V_17 . V_2 , V_14 ) ;
F_14 ( V_7 [ V_4 -> V_8 . V_9 . V_17 . V_2 ] , V_4 ) ;
F_15 ( & V_16 ) ;
return 0 ;
V_18:
F_15 ( & V_16 ) ;
return - 1 ;
}
static void F_16 ( struct V_1 * V_4 )
{
F_10 ( & V_16 ) ;
F_17 ( V_4 -> V_8 . V_9 . V_17 . V_2 , V_14 ) ;
F_14 ( V_7 [ V_4 -> V_8 . V_9 . V_17 . V_2 ] , NULL ) ;
F_15 ( & V_16 ) ;
F_18 () ;
}
static int F_19 ( struct V_19 * V_20 , struct V_21 * V_22 )
{
struct V_4 * V_23 = (struct V_4 * ) V_20 -> V_24 ;
struct V_1 * V_25 = F_20 ( V_23 ) ;
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
V_36 = F_21 ( & V_45 , & V_30 , NULL ,
V_6 -> V_10 . V_11 . V_3 ,
V_6 -> V_17 . V_11 . V_3 ,
0 , 0 , V_46 ,
F_22 ( 0 ) , 0 ) ;
if ( F_23 ( V_36 ) )
goto V_44;
V_38 = V_36 -> V_47 . V_48 ;
V_41 = F_24 ( V_38 ) + sizeof( * V_40 ) + sizeof( * V_27 ) + 2 ;
if ( F_25 ( V_22 ) < V_41 || F_26 ( V_22 ) || F_27 ( V_22 ) ) {
struct V_21 * V_49 = F_28 ( V_22 , V_41 ) ;
if ( ! V_49 ) {
F_29 ( V_36 ) ;
goto V_44;
}
if ( V_22 -> V_23 )
F_30 ( V_49 , V_22 -> V_23 ) ;
F_31 ( V_22 ) ;
V_22 = V_49 ;
}
V_33 = V_22 -> V_33 ;
V_31 = ( ( V_33 [ 0 ] << 8 ) + V_33 [ 1 ] ) == V_50 && 1 <= V_33 [ 2 ] && V_33 [ 2 ] <= 7 ;
if ( ( V_6 -> V_51 & V_52 ) && V_33 [ 0 ] == 0 && ! V_31 )
F_32 ( V_22 , 1 ) ;
if ( ( V_6 -> V_51 & V_53 ) == 0 || V_31 ) {
V_33 = F_33 ( V_22 , 2 ) ;
V_33 [ 0 ] = V_54 ;
V_33 [ 1 ] = V_55 ;
}
V_32 = V_22 -> V_32 ;
V_34 = V_6 -> V_34 ;
if ( V_6 -> V_56 == V_34 )
V_28 -= sizeof( V_27 -> V_57 ) ;
F_33 ( V_22 , V_28 ) ;
V_27 = (struct V_26 * ) ( V_22 -> V_33 ) ;
V_27 -> V_58 = V_59 ;
V_27 -> V_60 = V_61 ;
V_27 -> V_62 = F_34 ( V_63 ) ;
V_27 -> V_2 = F_34 ( V_6 -> V_10 . V_2 ) ;
V_27 -> V_58 |= V_64 ;
V_27 -> V_65 = F_35 ( ++ V_6 -> V_66 ) ;
if ( V_6 -> V_56 != V_34 ) {
V_27 -> V_60 |= V_67 ;
V_27 -> V_57 = F_35 ( V_34 ) ;
V_6 -> V_56 = V_34 ;
}
V_27 -> V_68 = F_34 ( V_32 ) ;
F_36 ( V_22 ) ;
F_33 ( V_22 , sizeof( * V_40 ) ) ;
F_37 ( V_22 ) ;
memset ( & ( F_38 ( V_22 ) -> V_6 ) , 0 , sizeof( F_38 ( V_22 ) -> V_6 ) ) ;
F_38 ( V_22 ) -> V_58 &= ~ ( V_69 | V_70 | V_71 ) ;
V_40 = F_39 ( V_22 ) ;
V_40 -> V_72 = 4 ;
V_40 -> V_73 = sizeof( struct V_39 ) >> 2 ;
if ( F_40 ( V_23 , & V_36 -> V_47 ) )
V_40 -> V_74 = F_34 ( V_75 ) ;
else
V_40 -> V_74 = 0 ;
V_40 -> V_62 = V_46 ;
V_40 -> V_76 = 0 ;
V_40 -> V_77 = V_30 . V_77 ;
V_40 -> V_78 = V_30 . V_78 ;
V_40 -> V_79 = F_41 ( & V_36 -> V_47 ) ;
V_40 -> V_80 = F_34 ( V_22 -> V_32 ) ;
F_42 ( V_22 ) ;
F_43 ( V_22 , & V_36 -> V_47 ) ;
F_44 ( V_22 ) ;
V_22 -> V_81 = V_82 ;
F_45 ( V_40 , & V_36 -> V_47 , NULL ) ;
F_46 ( V_40 ) ;
F_47 ( V_22 ) ;
return 1 ;
V_44:
F_31 ( V_22 ) ;
return 1 ;
}
static int F_48 ( struct V_4 * V_23 , struct V_21 * V_22 )
{
struct V_1 * V_25 = F_20 ( V_23 ) ;
struct V_5 * V_6 = & V_25 -> V_8 . V_9 ;
int V_83 , V_68 , V_65 ;
T_4 * V_84 ;
struct V_26 * V_85 ;
if ( ! ( V_23 -> V_42 & V_86 ) ) {
if ( F_49 ( V_23 , V_22 ) )
goto V_87;
return V_88 ;
}
V_85 = (struct V_26 * ) ( V_22 -> V_33 ) ;
V_83 = sizeof( * V_85 ) ;
if ( F_50 ( V_85 -> V_60 ) ) {
T_3 V_57 ;
if ( ! F_51 ( V_22 , V_83 ) )
goto V_87;
V_85 = (struct V_26 * ) ( V_22 -> V_33 ) ;
V_57 = F_52 ( V_85 -> V_58 ) ? V_85 -> V_57 : V_85 -> V_65 ;
V_57 = F_53 ( V_57 ) ;
if ( V_57 > V_6 -> V_89 )
V_6 -> V_89 = V_57 ;
if ( F_54 ( V_57 , V_6 -> V_89 ) )
V_6 -> V_89 = V_57 ;
} else {
V_83 -= sizeof( V_85 -> V_57 ) ;
}
if ( ! F_52 ( V_85 -> V_58 ) )
goto V_87;
V_68 = F_55 ( V_85 -> V_68 ) ;
V_65 = F_53 ( V_85 -> V_65 ) ;
if ( ! F_51 ( V_22 , V_83 + V_68 ) )
goto V_87;
V_84 = V_22 -> V_33 + V_83 ;
if ( V_65 < V_6 -> V_34 + 1 || F_54 ( V_6 -> V_34 , V_65 ) ) {
if ( ( V_84 [ 0 ] == V_54 ) && ( V_84 [ 1 ] == V_55 ) &&
( F_56 ( V_84 ) == V_50 ) &&
( ( V_84 [ 4 ] == V_90 ) || ( V_84 [ 4 ] == V_91 ) ) )
goto V_92;
} else {
V_6 -> V_34 = V_65 ;
V_92:
F_32 ( V_22 , V_83 ) ;
if ( V_84 [ 0 ] == V_54 && V_84 [ 1 ] == V_55 ) {
if ( V_22 -> V_32 < 3 )
goto V_87;
F_32 ( V_22 , 2 ) ;
}
if ( ( * V_22 -> V_33 ) & 1 ) {
F_33 ( V_22 , 1 ) [ 0 ] = 0 ;
}
V_22 -> V_81 = V_82 ;
F_57 ( V_22 , V_22 -> V_93 - V_22 -> V_33 ) ;
F_58 ( & V_25 -> V_20 , V_22 ) ;
return V_88 ;
}
V_87:
F_31 ( V_22 ) ;
return V_94 ;
}
static int F_59 ( struct V_21 * V_22 )
{
struct V_1 * V_25 ;
struct V_26 * V_85 ;
struct V_39 * V_40 ;
if ( V_22 -> V_95 != V_96 )
goto V_87;
if ( ! F_51 ( V_22 , 12 ) )
goto V_87;
V_40 = F_39 ( V_22 ) ;
V_85 = (struct V_26 * ) V_22 -> V_33 ;
if ( F_55 ( V_85 -> V_62 ) != V_63 ||
F_60 ( V_85 -> V_58 ) ||
F_61 ( V_85 -> V_58 ) ||
! F_62 ( V_85 -> V_58 ) ||
( V_85 -> V_58 & 0xF ) != 0 )
goto V_87;
V_25 = F_1 ( F_34 ( V_85 -> V_2 ) , V_40 -> V_78 ) ;
if ( V_25 ) {
F_42 ( V_22 ) ;
F_44 ( V_22 ) ;
return F_63 ( F_5 ( V_25 ) , V_22 , 0 ) ;
}
V_87:
F_31 ( V_22 ) ;
return V_94 ;
}
static int F_64 ( struct V_97 * V_4 , struct V_98 * V_99 ,
int V_100 )
{
struct V_4 * V_23 = V_4 -> V_23 ;
struct V_101 * V_102 = (struct V_101 * ) V_99 ;
struct V_1 * V_25 = F_20 ( V_23 ) ;
struct V_5 * V_6 = & V_25 -> V_8 . V_9 ;
int error = 0 ;
F_65 ( V_23 ) ;
V_6 -> V_17 = V_102 -> V_103 . V_9 ;
if ( F_9 ( V_25 ) ) {
F_66 ( V_23 ) ;
error = - V_104 ;
}
F_66 ( V_23 ) ;
return error ;
}
static int F_67 ( struct V_97 * V_4 , struct V_98 * V_99 ,
int V_100 , int V_58 )
{
struct V_4 * V_23 = V_4 -> V_23 ;
struct V_101 * V_102 = (struct V_101 * ) V_99 ;
struct V_1 * V_25 = F_20 ( V_23 ) ;
struct V_5 * V_6 = & V_25 -> V_8 . V_9 ;
struct V_35 * V_36 ;
struct V_29 V_30 ;
int error = 0 ;
if ( V_102 -> V_105 != V_106 )
return - V_107 ;
if ( F_7 ( V_102 -> V_103 . V_9 . V_2 , V_102 -> V_103 . V_9 . V_11 . V_3 ) )
return - V_108 ;
F_65 ( V_23 ) ;
if ( V_23 -> V_42 & V_86 ) {
error = - V_104 ;
goto V_109;
}
if ( V_23 -> V_42 & V_43 ) {
error = - V_108 ;
goto V_109;
}
if ( ! V_6 -> V_17 . V_11 . V_3 || ! V_102 -> V_103 . V_9 . V_11 . V_3 ) {
error = - V_107 ;
goto V_109;
}
V_25 -> V_20 . V_24 = V_23 ;
V_25 -> V_20 . V_110 = & V_111 ;
V_36 = F_21 ( & V_45 , & V_30 , V_23 ,
V_6 -> V_10 . V_11 . V_3 ,
V_6 -> V_17 . V_11 . V_3 ,
0 , 0 ,
V_46 , F_68 ( V_23 ) , 0 ) ;
if ( F_23 ( V_36 ) ) {
error = - V_112 ;
goto V_109;
}
F_69 ( V_23 , & V_36 -> V_47 ) ;
V_25 -> V_20 . V_113 = F_70 ( & V_36 -> V_47 ) ;
if ( ! V_25 -> V_20 . V_113 )
V_25 -> V_20 . V_113 = V_114 ;
F_29 ( V_36 ) ;
V_25 -> V_20 . V_113 -= V_115 ;
V_25 -> V_20 . V_116 = 2 + sizeof( struct V_26 ) ;
error = F_71 ( & V_25 -> V_20 ) ;
if ( error ) {
F_72 ( L_1 , error ) ;
goto V_109;
}
V_6 -> V_10 = V_102 -> V_103 . V_9 ;
V_23 -> V_42 = V_86 ;
V_109:
F_66 ( V_23 ) ;
return error ;
}
static int F_73 ( struct V_97 * V_4 , struct V_98 * V_117 ,
int * V_118 , int V_119 )
{
int V_32 = sizeof( struct V_101 ) ;
struct V_101 V_102 ;
V_102 . V_120 = V_121 ;
V_102 . V_105 = V_106 ;
V_102 . V_103 . V_9 = F_20 ( V_4 -> V_23 ) -> V_8 . V_9 . V_17 ;
memcpy ( V_117 , & V_102 , V_32 ) ;
* V_118 = V_32 ;
return 0 ;
}
static int F_74 ( struct V_97 * V_4 )
{
struct V_4 * V_23 = V_4 -> V_23 ;
struct V_1 * V_25 ;
struct V_5 * V_6 ;
int error = 0 ;
if ( ! V_23 )
return 0 ;
F_65 ( V_23 ) ;
if ( F_75 ( V_23 , V_122 ) ) {
F_66 ( V_23 ) ;
return - V_123 ;
}
V_25 = F_20 ( V_23 ) ;
V_6 = & V_25 -> V_8 . V_9 ;
F_16 ( V_25 ) ;
F_76 ( V_23 ) ;
V_23 -> V_42 = V_43 ;
F_77 ( V_23 ) ;
V_4 -> V_23 = NULL ;
F_66 ( V_23 ) ;
F_78 ( V_23 ) ;
return error ;
}
static void F_79 ( struct V_4 * V_23 )
{
if ( ! ( V_23 -> V_42 & V_43 ) ) {
F_16 ( F_20 ( V_23 ) ) ;
F_76 ( V_23 ) ;
}
F_80 ( & V_23 -> V_124 ) ;
}
static int F_81 ( struct V_125 * V_125 , struct V_97 * V_4 )
{
int error = - V_126 ;
struct V_4 * V_23 ;
struct V_1 * V_25 ;
struct V_5 * V_6 ;
V_23 = F_82 ( V_125 , V_127 , V_128 , & V_129 ) ;
if ( ! V_23 )
goto V_130;
F_83 ( V_4 , V_23 ) ;
V_4 -> V_131 = V_132 ;
V_4 -> V_110 = & V_133 ;
V_23 -> V_134 = F_48 ;
V_23 -> V_42 = V_135 ;
V_23 -> V_136 = V_137 ;
V_23 -> V_138 = V_127 ;
V_23 -> V_139 = V_106 ;
V_23 -> V_140 = F_79 ;
V_25 = F_20 ( V_23 ) ;
V_6 = & V_25 -> V_8 . V_9 ;
V_6 -> V_66 = 0 ; V_6 -> V_34 = 0 ;
V_6 -> V_89 = 0 ; V_6 -> V_56 = 0 ;
error = 0 ;
V_130:
return error ;
}
static int F_84 ( struct V_19 * V_20 , unsigned int V_141 ,
unsigned long V_142 )
{
struct V_4 * V_23 = (struct V_4 * ) V_20 -> V_24 ;
struct V_1 * V_25 = F_20 ( V_23 ) ;
struct V_5 * V_6 = & V_25 -> V_8 . V_9 ;
void T_5 * V_143 = ( void T_5 * ) V_142 ;
int T_5 * V_144 = V_143 ;
int V_145 , V_146 ;
V_145 = - V_147 ;
switch ( V_141 ) {
case V_148 :
V_146 = V_6 -> V_51 ;
if ( F_85 ( V_146 , V_144 ) )
break;
V_145 = 0 ;
break;
case V_149 :
if ( F_86 ( V_146 , V_144 ) )
break;
V_6 -> V_51 = V_146 & ~ V_150 ;
V_145 = 0 ;
break;
default:
V_145 = - V_151 ;
}
return V_145 ;
}
static int T_6 F_87 ( void )
{
int V_145 = 0 ;
F_88 ( L_2 V_152 L_3 ) ;
V_7 = F_89 ( ( V_15 + 1 ) * sizeof( void * ) ) ;
if ( ! V_7 ) {
F_72 ( L_4 ) ;
return - V_126 ;
}
V_145 = F_90 ( & V_153 , V_154 ) ;
if ( V_145 ) {
F_72 ( L_5 ) ;
goto V_155;
}
V_145 = F_91 ( & V_129 , 0 ) ;
if ( V_145 ) {
F_72 ( L_6 ) ;
goto V_156;
}
V_145 = F_92 ( V_106 , & V_157 ) ;
if ( V_145 ) {
F_72 ( L_7 ) ;
goto V_158;
}
return 0 ;
V_158:
F_93 ( & V_129 ) ;
V_156:
F_94 ( & V_153 , V_154 ) ;
V_155:
F_95 ( V_7 ) ;
return V_145 ;
}
static void T_7 F_96 ( void )
{
F_97 ( V_106 ) ;
F_93 ( & V_129 ) ;
F_94 ( & V_153 , V_154 ) ;
F_95 ( V_7 ) ;
}
