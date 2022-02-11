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
static int F_9 ( struct V_1 * V_4 ,
struct V_15 * V_16 )
{
static int V_2 ;
F_10 ( & V_17 ) ;
if ( ! V_16 -> V_2 ) {
V_2 = F_11 ( V_18 , V_14 , V_2 + 1 ) ;
if ( V_2 == V_14 ) {
V_2 = F_11 ( V_18 , V_14 , 1 ) ;
if ( V_2 == V_14 )
goto V_19;
}
V_16 -> V_2 = V_2 ;
} else if ( F_12 ( V_16 -> V_2 , V_18 ) ) {
goto V_19;
}
V_4 -> V_8 . V_9 . V_20 = * V_16 ;
F_13 ( V_16 -> V_2 , V_18 ) ;
F_14 ( V_7 [ V_16 -> V_2 ] , V_4 ) ;
F_15 ( & V_17 ) ;
return 0 ;
V_19:
F_15 ( & V_17 ) ;
return - 1 ;
}
static void F_16 ( struct V_1 * V_4 )
{
F_10 ( & V_17 ) ;
F_17 ( V_4 -> V_8 . V_9 . V_20 . V_2 , V_18 ) ;
F_18 ( V_7 [ V_4 -> V_8 . V_9 . V_20 . V_2 ] , NULL ) ;
F_15 ( & V_17 ) ;
F_19 () ;
}
static int F_20 ( struct V_21 * V_22 , struct V_23 * V_24 )
{
struct V_4 * V_25 = (struct V_4 * ) V_22 -> V_26 ;
struct V_1 * V_27 = F_21 ( V_25 ) ;
struct V_28 * V_28 = F_22 ( V_25 ) ;
struct V_5 * V_6 = & V_27 -> V_8 . V_9 ;
struct V_29 * V_30 ;
unsigned int V_31 = sizeof( * V_30 ) ;
struct V_32 V_33 ;
int V_34 ;
int V_35 ;
unsigned char * V_36 ;
T_3 V_37 ;
struct V_38 * V_39 ;
struct V_40 * V_41 ;
struct V_42 * V_43 ;
int V_44 ;
if ( F_5 ( V_27 ) -> V_45 & V_46 )
goto V_47;
V_39 = F_23 ( V_28 , & V_33 , NULL ,
V_6 -> V_10 . V_11 . V_3 ,
V_6 -> V_20 . V_11 . V_3 ,
0 , 0 , V_48 ,
F_24 ( 0 ) , 0 ) ;
if ( F_25 ( V_39 ) )
goto V_47;
V_41 = V_39 -> V_49 . V_50 ;
V_44 = F_26 ( V_41 ) + sizeof( * V_43 ) + sizeof( * V_30 ) + 2 ;
if ( F_27 ( V_24 ) < V_44 || F_28 ( V_24 ) || F_29 ( V_24 ) ) {
struct V_23 * V_51 = F_30 ( V_24 , V_44 ) ;
if ( ! V_51 ) {
F_31 ( V_39 ) ;
goto V_47;
}
if ( V_24 -> V_25 )
F_32 ( V_51 , V_24 -> V_25 ) ;
F_33 ( V_24 ) ;
V_24 = V_51 ;
}
V_36 = V_24 -> V_36 ;
V_34 = ( ( V_36 [ 0 ] << 8 ) + V_36 [ 1 ] ) == V_52 && 1 <= V_36 [ 2 ] && V_36 [ 2 ] <= 7 ;
if ( ( V_6 -> V_53 & V_54 ) && V_36 [ 0 ] == 0 && ! V_34 )
F_34 ( V_24 , 1 ) ;
if ( ( V_6 -> V_53 & V_55 ) == 0 || V_34 ) {
V_36 = F_35 ( V_24 , 2 ) ;
V_36 [ 0 ] = V_56 ;
V_36 [ 1 ] = V_57 ;
}
V_35 = V_24 -> V_35 ;
V_37 = V_6 -> V_37 ;
if ( V_6 -> V_58 == V_37 )
V_31 -= sizeof( V_30 -> V_59 ) ;
F_35 ( V_24 , V_31 ) ;
V_30 = (struct V_29 * ) ( V_24 -> V_36 ) ;
V_30 -> V_60 = V_61 ;
V_30 -> V_62 = V_63 ;
V_30 -> V_64 = F_36 ( V_65 ) ;
V_30 -> V_2 = F_36 ( V_6 -> V_10 . V_2 ) ;
V_30 -> V_60 |= V_66 ;
V_30 -> V_67 = F_37 ( ++ V_6 -> V_68 ) ;
if ( V_6 -> V_58 != V_37 ) {
V_30 -> V_62 |= V_69 ;
V_30 -> V_59 = F_37 ( V_37 ) ;
V_6 -> V_58 = V_37 ;
}
V_30 -> V_70 = F_36 ( V_35 ) ;
F_38 ( V_24 ) ;
F_35 ( V_24 , sizeof( * V_43 ) ) ;
F_39 ( V_24 ) ;
memset ( & ( F_40 ( V_24 ) -> V_6 ) , 0 , sizeof( F_40 ( V_24 ) -> V_6 ) ) ;
F_40 ( V_24 ) -> V_60 &= ~ ( V_71 | V_72 | V_73 ) ;
V_43 = F_41 ( V_24 ) ;
V_43 -> V_74 = 4 ;
V_43 -> V_75 = sizeof( struct V_42 ) >> 2 ;
if ( F_42 ( V_25 , & V_39 -> V_49 ) )
V_43 -> V_76 = F_36 ( V_77 ) ;
else
V_43 -> V_76 = 0 ;
V_43 -> V_64 = V_48 ;
V_43 -> V_78 = 0 ;
V_43 -> V_79 = V_33 . V_79 ;
V_43 -> V_80 = V_33 . V_80 ;
V_43 -> V_81 = F_43 ( & V_39 -> V_49 ) ;
V_43 -> V_82 = F_36 ( V_24 -> V_35 ) ;
F_44 ( V_24 ) ;
F_45 ( V_24 , & V_39 -> V_49 ) ;
F_46 ( V_24 ) ;
V_24 -> V_83 = V_84 ;
F_47 ( V_28 , V_24 , NULL ) ;
F_48 ( V_43 ) ;
F_49 ( V_28 , V_24 -> V_25 , V_24 ) ;
return 1 ;
V_47:
F_50 ( V_24 ) ;
return 1 ;
}
static int F_51 ( struct V_4 * V_25 , struct V_23 * V_24 )
{
struct V_1 * V_27 = F_21 ( V_25 ) ;
struct V_5 * V_6 = & V_27 -> V_8 . V_9 ;
int V_85 , V_70 , V_67 ;
T_4 * V_86 ;
struct V_29 * V_87 ;
if ( ! ( V_25 -> V_45 & V_88 ) ) {
if ( F_52 ( V_25 , V_24 ) )
goto V_89;
return V_90 ;
}
V_87 = (struct V_29 * ) ( V_24 -> V_36 ) ;
V_85 = sizeof( * V_87 ) ;
if ( F_53 ( V_87 -> V_62 ) ) {
T_3 V_59 ;
if ( ! F_54 ( V_24 , V_85 ) )
goto V_89;
V_87 = (struct V_29 * ) ( V_24 -> V_36 ) ;
V_59 = F_55 ( V_87 -> V_60 ) ? V_87 -> V_59 : V_87 -> V_67 ;
V_59 = F_56 ( V_59 ) ;
if ( V_59 > V_6 -> V_91 )
V_6 -> V_91 = V_59 ;
if ( F_57 ( V_59 , V_6 -> V_91 ) )
V_6 -> V_91 = V_59 ;
} else {
V_85 -= sizeof( V_87 -> V_59 ) ;
}
if ( ! F_55 ( V_87 -> V_60 ) )
goto V_89;
V_70 = F_58 ( V_87 -> V_70 ) ;
V_67 = F_56 ( V_87 -> V_67 ) ;
if ( ! F_54 ( V_24 , V_85 + V_70 ) )
goto V_89;
V_86 = V_24 -> V_36 + V_85 ;
if ( V_67 < V_6 -> V_37 + 1 || F_57 ( V_6 -> V_37 , V_67 ) ) {
if ( ( V_86 [ 0 ] == V_56 ) && ( V_86 [ 1 ] == V_57 ) &&
( F_59 ( V_86 ) == V_52 ) &&
( ( V_86 [ 4 ] == V_92 ) || ( V_86 [ 4 ] == V_93 ) ) )
goto V_94;
} else {
V_6 -> V_37 = V_67 ;
V_94:
F_34 ( V_24 , V_85 ) ;
if ( V_86 [ 0 ] == V_56 && V_86 [ 1 ] == V_57 ) {
if ( V_24 -> V_35 < 3 )
goto V_89;
F_34 ( V_24 , 2 ) ;
}
if ( ( * V_24 -> V_36 ) & 1 ) {
F_35 ( V_24 , 1 ) [ 0 ] = 0 ;
}
V_24 -> V_83 = V_84 ;
F_60 ( V_24 , V_24 -> V_95 - V_24 -> V_36 ) ;
F_61 ( & V_27 -> V_22 , V_24 ) ;
return V_90 ;
}
V_89:
F_50 ( V_24 ) ;
return V_96 ;
}
static int F_62 ( struct V_23 * V_24 )
{
struct V_1 * V_27 ;
struct V_29 * V_87 ;
struct V_42 * V_43 ;
if ( V_24 -> V_97 != V_98 )
goto V_89;
if ( ! F_54 ( V_24 , 12 ) )
goto V_89;
V_43 = F_41 ( V_24 ) ;
V_87 = (struct V_29 * ) V_24 -> V_36 ;
if ( F_58 ( V_87 -> V_64 ) != V_65 ||
F_63 ( V_87 -> V_60 ) ||
F_64 ( V_87 -> V_60 ) ||
! F_65 ( V_87 -> V_60 ) ||
( V_87 -> V_60 & 0xF ) != 0 )
goto V_89;
V_27 = F_1 ( F_36 ( V_87 -> V_2 ) , V_43 -> V_80 ) ;
if ( V_27 ) {
F_44 ( V_24 ) ;
F_46 ( V_24 ) ;
return F_66 ( F_5 ( V_27 ) , V_24 , 0 ) ;
}
V_89:
F_50 ( V_24 ) ;
return V_96 ;
}
static int F_67 ( struct V_99 * V_4 , struct V_100 * V_101 ,
int V_102 )
{
struct V_4 * V_25 = V_4 -> V_25 ;
struct V_103 * V_104 = (struct V_103 * ) V_101 ;
struct V_1 * V_27 = F_21 ( V_25 ) ;
int error = 0 ;
if ( V_102 < sizeof( struct V_103 ) )
return - V_105 ;
F_68 ( V_25 ) ;
if ( V_25 -> V_45 & V_46 ) {
error = - V_106 ;
goto V_107;
}
if ( V_25 -> V_45 & V_108 ) {
error = - V_109 ;
goto V_107;
}
if ( F_9 ( V_27 , & V_104 -> V_110 . V_9 ) )
error = - V_109 ;
else
V_25 -> V_45 |= V_108 ;
V_107:
F_69 ( V_25 ) ;
return error ;
}
static int F_70 ( struct V_99 * V_4 , struct V_100 * V_101 ,
int V_102 , int V_60 )
{
struct V_4 * V_25 = V_4 -> V_25 ;
struct V_103 * V_104 = (struct V_103 * ) V_101 ;
struct V_1 * V_27 = F_21 ( V_25 ) ;
struct V_5 * V_6 = & V_27 -> V_8 . V_9 ;
struct V_38 * V_39 ;
struct V_32 V_33 ;
int error = 0 ;
if ( V_102 < sizeof( struct V_103 ) )
return - V_105 ;
if ( V_104 -> V_111 != V_112 )
return - V_105 ;
if ( F_7 ( V_104 -> V_110 . V_9 . V_2 , V_104 -> V_110 . V_9 . V_11 . V_3 ) )
return - V_106 ;
F_68 ( V_25 ) ;
if ( V_25 -> V_45 & V_88 ) {
error = - V_109 ;
goto V_113;
}
if ( V_25 -> V_45 & V_46 ) {
error = - V_106 ;
goto V_113;
}
if ( ! V_6 -> V_20 . V_11 . V_3 || ! V_104 -> V_110 . V_9 . V_11 . V_3 ) {
error = - V_105 ;
goto V_113;
}
V_27 -> V_22 . V_26 = V_25 ;
V_27 -> V_22 . V_114 = & V_115 ;
V_39 = F_23 ( F_22 ( V_25 ) , & V_33 , V_25 ,
V_6 -> V_10 . V_11 . V_3 ,
V_6 -> V_20 . V_11 . V_3 ,
0 , 0 ,
V_48 , F_71 ( V_25 ) , 0 ) ;
if ( F_25 ( V_39 ) ) {
error = - V_116 ;
goto V_113;
}
F_72 ( V_25 , & V_39 -> V_49 ) ;
V_27 -> V_22 . V_117 = F_73 ( & V_39 -> V_49 ) ;
if ( ! V_27 -> V_22 . V_117 )
V_27 -> V_22 . V_117 = V_118 ;
F_31 ( V_39 ) ;
V_27 -> V_22 . V_117 -= V_119 ;
V_27 -> V_22 . V_120 = 2 + sizeof( struct V_29 ) ;
error = F_74 ( & V_27 -> V_22 ) ;
if ( error ) {
F_75 ( L_1 , error ) ;
goto V_113;
}
V_6 -> V_10 = V_104 -> V_110 . V_9 ;
V_25 -> V_45 |= V_88 ;
V_113:
F_69 ( V_25 ) ;
return error ;
}
static int F_76 ( struct V_99 * V_4 , struct V_100 * V_121 ,
int * V_122 , int V_123 )
{
int V_35 = sizeof( struct V_103 ) ;
struct V_103 V_104 ;
memset ( & V_104 . V_110 , 0 , sizeof( V_104 . V_110 ) ) ;
V_104 . V_124 = V_125 ;
V_104 . V_111 = V_112 ;
V_104 . V_110 . V_9 = F_21 ( V_4 -> V_25 ) -> V_8 . V_9 . V_20 ;
memcpy ( V_121 , & V_104 , V_35 ) ;
* V_122 = V_35 ;
return 0 ;
}
static int F_77 ( struct V_99 * V_4 )
{
struct V_4 * V_25 = V_4 -> V_25 ;
struct V_1 * V_27 ;
struct V_5 * V_6 ;
int error = 0 ;
if ( ! V_25 )
return 0 ;
F_68 ( V_25 ) ;
if ( F_78 ( V_25 , V_126 ) ) {
F_69 ( V_25 ) ;
return - V_127 ;
}
V_27 = F_21 ( V_25 ) ;
V_6 = & V_27 -> V_8 . V_9 ;
F_16 ( V_27 ) ;
F_79 ( V_25 ) ;
V_25 -> V_45 = V_46 ;
F_80 ( V_25 ) ;
V_4 -> V_25 = NULL ;
F_69 ( V_25 ) ;
F_81 ( V_25 ) ;
return error ;
}
static void F_82 ( struct V_4 * V_25 )
{
if ( ! ( V_25 -> V_45 & V_46 ) ) {
F_16 ( F_21 ( V_25 ) ) ;
F_79 ( V_25 ) ;
}
F_83 ( & V_25 -> V_128 ) ;
}
static int F_84 ( struct V_28 * V_28 , struct V_99 * V_4 , int V_129 )
{
int error = - V_130 ;
struct V_4 * V_25 ;
struct V_1 * V_27 ;
struct V_5 * V_6 ;
V_25 = F_85 ( V_28 , V_131 , V_132 , & V_133 , V_129 ) ;
if ( ! V_25 )
goto V_107;
F_86 ( V_4 , V_25 ) ;
V_4 -> V_134 = V_135 ;
V_4 -> V_114 = & V_136 ;
V_25 -> V_137 = F_51 ;
V_25 -> V_45 = V_138 ;
V_25 -> V_139 = V_140 ;
V_25 -> V_141 = V_131 ;
V_25 -> V_142 = V_112 ;
V_25 -> V_143 = F_82 ;
V_27 = F_21 ( V_25 ) ;
V_6 = & V_27 -> V_8 . V_9 ;
V_6 -> V_68 = 0 ; V_6 -> V_37 = 0xffffffff ;
V_6 -> V_91 = 0 ; V_6 -> V_58 = 0xffffffff ;
error = 0 ;
V_107:
return error ;
}
static int F_87 ( struct V_21 * V_22 , unsigned int V_144 ,
unsigned long V_145 )
{
struct V_4 * V_25 = (struct V_4 * ) V_22 -> V_26 ;
struct V_1 * V_27 = F_21 ( V_25 ) ;
struct V_5 * V_6 = & V_27 -> V_8 . V_9 ;
void T_5 * V_146 = ( void T_5 * ) V_145 ;
int T_5 * V_147 = V_146 ;
int V_148 , V_149 ;
V_148 = - V_150 ;
switch ( V_144 ) {
case V_151 :
V_149 = V_6 -> V_53 ;
if ( F_88 ( V_149 , V_147 ) )
break;
V_148 = 0 ;
break;
case V_152 :
if ( F_89 ( V_149 , V_147 ) )
break;
V_6 -> V_53 = V_149 & ~ V_153 ;
V_148 = 0 ;
break;
default:
V_148 = - V_154 ;
}
return V_148 ;
}
static int T_6 F_90 ( void )
{
int V_148 = 0 ;
F_91 ( L_2 V_155 L_3 ) ;
V_7 = F_92 ( ( V_14 + 1 ) * sizeof( void * ) ) ;
if ( ! V_7 )
return - V_130 ;
V_148 = F_93 ( & V_156 , V_157 ) ;
if ( V_148 ) {
F_75 ( L_4 ) ;
goto V_158;
}
V_148 = F_94 ( & V_133 , 0 ) ;
if ( V_148 ) {
F_75 ( L_5 ) ;
goto V_159;
}
V_148 = F_95 ( V_112 , & V_160 ) ;
if ( V_148 ) {
F_75 ( L_6 ) ;
goto V_161;
}
return 0 ;
V_161:
F_96 ( & V_133 ) ;
V_159:
F_97 ( & V_156 , V_157 ) ;
V_158:
F_98 ( V_7 ) ;
return V_148 ;
}
static void T_7 F_99 ( void )
{
F_100 ( V_112 ) ;
F_96 ( & V_133 ) ;
F_97 ( & V_156 , V_157 ) ;
F_98 ( V_7 ) ;
}
