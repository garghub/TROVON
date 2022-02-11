static inline T_1 F_1 ( struct V_1 * V_2 , T_2 V_3 )
{
return F_2 ( V_2 -> V_4 + ( ( ( unsigned int ) V_3 ) << V_2 -> V_5 ) ) ;
}
static inline void F_3 ( struct V_1 * V_2 ,
T_2 V_3 , T_1 V_6 )
{
F_4 ( V_6 , V_2 -> V_4 + ( ( ( unsigned ) V_3 ) << V_2 -> V_5 ) ) ;
( void ) F_1 ( V_2 , V_7 ) ;
}
static T_1 F_5 ( struct V_1 * V_2 )
{
int V_8 , V_9 ;
T_1 V_10 ;
for ( V_8 = 0 ; V_8 < 1000 ; V_8 ++ ) {
V_10 = F_6 ( V_11 ) & V_12 ;
if ( V_10 != 0 )
return V_10 ;
if ( V_2 -> V_13 ) {
for ( V_9 = 1 ; V_9 < 100000 ; V_9 ++ )
F_7 () ;
} else
F_8 ( 1 ) ;
}
return V_10 ;
}
static void F_9 ( struct V_1 * V_2 , int V_14 )
{
F_10 ( V_15 , V_16 ) ;
V_2 -> V_17 = V_18 ;
V_2 -> V_14 = V_14 ;
}
static void F_11 ( struct V_1 * V_2 , T_1 V_10 )
{
T_1 V_19 ;
F_12 ( L_1 ,
V_20 [ V_2 -> V_17 ] , V_10 ) ;
if ( V_2 -> V_17 == V_21 ) {
F_13 ( V_22 L_2
L_3 ) ;
F_10 ( V_11 , V_10 ) ;
return;
}
if ( V_10 == 0 ) {
F_13 ( V_22 L_4
L_5 ) ;
if ( V_2 -> V_17 != V_18 ) {
F_9 ( V_2 , - V_23 ) ;
return;
}
V_19 = F_6 ( V_24 ) ;
if ( V_19 & V_25 )
F_10 ( V_24 , 0 ) ;
V_2 -> V_17 = V_21 ;
F_10 ( V_26 , 0x00 ) ;
if ( ! V_2 -> V_13 )
F_14 ( & V_2 -> F_14 ) ;
return;
}
if ( V_10 & V_27 ) {
V_19 = F_6 ( V_24 ) ;
if ( V_2 -> V_17 != V_28 ) {
F_15 ( L_6 ) ;
F_9 ( V_2 , - V_23 ) ;
}
if ( ( V_19 & V_29 ) == 0 ) {
V_2 -> V_14 = - V_30 ;
V_2 -> V_17 = V_18 ;
F_12 ( L_7 ) ;
} else {
if ( V_2 -> V_31 == 0 )
F_9 ( V_2 , 0 ) ;
else if ( V_2 -> V_32 ) {
V_2 -> V_17 = V_33 ;
if ( V_2 -> V_31 > 1 )
F_10 ( V_15 ,
V_34 ) ;
} else {
V_2 -> V_17 = V_35 ;
F_10 ( V_36 , * ( V_2 -> V_37 ++ ) ) ;
V_2 -> V_31 -- ;
}
}
F_10 ( V_11 , V_27 ) ;
}
if ( V_10 & V_38 ) {
if ( V_2 -> V_17 == V_33 ) {
* ( V_2 -> V_37 ++ ) = F_6 ( V_36 ) ;
V_2 -> V_31 -- ;
F_10 ( V_11 , V_38 ) ;
if ( V_2 -> V_31 == 0 )
V_2 -> V_17 = V_18 ;
else if ( V_2 -> V_31 == 1 )
F_10 ( V_15 , 0 ) ;
} else if ( V_2 -> V_17 == V_35 ) {
V_19 = F_6 ( V_24 ) ;
if ( ( V_19 & V_29 ) == 0 ) {
F_12 ( L_8 ) ;
V_2 -> V_14 = - V_39 ;
V_2 -> V_17 = V_18 ;
} else if ( V_2 -> V_31 ) {
F_10 ( V_36 , * ( V_2 -> V_37 ++ ) ) ;
V_2 -> V_31 -- ;
} else
F_9 ( V_2 , 0 ) ;
} else {
F_15 ( L_9 ) ;
if ( V_2 -> V_17 != V_18 )
F_9 ( V_2 , - V_23 ) ;
}
F_10 ( V_11 , V_38 ) ;
}
if ( V_10 & V_40 ) {
F_10 ( V_11 , V_40 ) ;
if ( V_2 -> V_17 != V_18 ) {
F_15 ( L_10 ) ;
V_2 -> V_14 = - V_23 ;
}
V_2 -> V_17 = V_21 ;
if ( ! V_2 -> V_13 )
F_14 ( & V_2 -> F_14 ) ;
}
if ( V_10 & V_41 )
F_10 ( V_11 , V_41 ) ;
}
static T_3 F_16 ( int V_42 , void * V_43 )
{
struct V_1 * V_2 = V_43 ;
unsigned long V_44 ;
F_17 ( & V_2 -> V_45 , V_44 ) ;
F_18 ( & V_2 -> V_46 ) ;
F_11 ( V_2 , F_6 ( V_11 ) ) ;
if ( V_2 -> V_17 != V_21 ) {
V_2 -> V_46 . V_47 = V_48 + V_49 ;
F_19 ( & V_2 -> V_46 ) ;
}
F_20 ( & V_2 -> V_45 , V_44 ) ;
return V_50 ;
}
static void F_21 ( unsigned long V_37 )
{
struct V_1 * V_2 = (struct V_1 * ) V_37 ;
unsigned long V_44 ;
F_17 ( & V_2 -> V_45 , V_44 ) ;
if ( F_22 ( & V_2 -> V_46 ) )
goto V_51;
F_11 ( V_2 , F_6 ( V_11 ) ) ;
if ( V_2 -> V_17 != V_21 ) {
V_2 -> V_46 . V_47 = V_48 + V_49 ;
F_19 ( & V_2 -> V_46 ) ;
}
V_51:
F_20 ( & V_2 -> V_45 , V_44 ) ;
}
static int F_23 ( struct V_52 * V_53 )
{
struct V_1 * V_2 = V_53 -> V_54 ;
F_24 ( & V_2 -> V_55 ) ;
return 0 ;
}
static void F_25 ( struct V_52 * V_53 )
{
struct V_1 * V_2 = V_53 -> V_54 ;
F_26 ( & V_2 -> V_55 ) ;
}
static int F_27 ( struct V_52 * V_53 , T_1 V_56 , int V_57 ,
T_4 V_58 , T_1 * V_37 , int V_31 )
{
struct V_1 * V_2 = V_53 -> V_54 ;
T_1 V_59 = V_2 -> V_60 ;
int V_61 = V_2 -> V_42 != V_62 && ! V_53 -> V_13 ;
switch( V_53 -> V_63 ) {
case V_64 :
return - V_65 ;
case V_66 :
V_59 |= V_67 ;
if ( V_57 != 0 )
return - V_65 ;
break;
case V_68 :
V_59 |= V_69 ;
if ( V_57 != 1 )
return - V_65 ;
break;
case V_70 :
V_59 |= V_71 ;
if ( V_57 != 1 )
return - V_65 ;
break;
}
F_10 ( V_11 , F_6 ( V_11 ) ) ;
F_10 ( V_72 , V_59 | ( V_53 -> V_73 << 4 ) ) ;
F_10 ( V_24 , 0 ) ;
F_10 ( V_74 , V_56 & 0xff ) ;
if ( ( V_59 & V_75 ) == V_69
|| ( V_59 & V_75 ) == V_71 )
F_10 ( V_7 , V_58 ) ;
V_2 -> V_37 = V_37 ;
V_2 -> V_31 = V_31 ;
V_2 -> V_17 = V_28 ;
V_2 -> V_14 = 0 ;
V_2 -> V_32 = ( V_56 & 1 ) ;
V_2 -> V_13 = V_53 -> V_13 ;
if ( V_61 ) {
F_28 ( & V_2 -> F_14 ) ;
F_10 ( V_11 , F_6 ( V_11 ) ) ;
V_2 -> V_46 . V_47 = V_48 + V_49 ;
F_19 ( & V_2 -> V_46 ) ;
F_10 ( V_26 , V_12 ) ;
}
F_10 ( V_15 , V_76 ) ;
if ( V_61 )
F_29 ( & V_2 -> F_14 ) ;
else {
while( V_2 -> V_17 != V_21 ) {
unsigned long V_44 ;
T_1 V_10 = F_5 ( V_2 ) ;
F_17 ( & V_2 -> V_45 , V_44 ) ;
F_11 ( V_2 , V_10 ) ;
F_20 ( & V_2 -> V_45 , V_44 ) ;
}
}
F_10 ( V_26 , 0 ) ;
return V_2 -> V_14 ;
}
static struct V_1 * T_5 F_30 ( struct V_77 * V_78 )
{
struct V_1 * V_2 ;
const T_4 * V_79 , * V_80 , * V_81 ;
T_4 V_82 ;
V_2 = F_31 ( sizeof( struct V_1 ) , V_83 ) ;
if ( V_2 == NULL ) {
F_13 ( V_84 L_11 ,
V_78 -> V_85 ) ;
return NULL ;
}
V_81 = F_32 ( V_78 , L_12 , NULL ) ;
if ( V_81 == NULL ) {
F_13 ( V_84 L_13 ,
V_78 -> V_85 ) ;
F_33 ( V_2 ) ;
return NULL ;
}
F_34 ( & V_2 -> V_55 ) ;
F_35 ( & V_2 -> F_14 ) ;
F_36 ( & V_2 -> V_45 ) ;
F_37 ( & V_2 -> V_46 ) ;
V_2 -> V_46 . V_86 = F_21 ;
V_2 -> V_46 . V_37 = ( unsigned long ) V_2 ;
V_79 = F_32 ( V_78 , L_14 , NULL ) ;
V_82 = V_79 ? ( * V_79 ) : 0x10 ;
for ( V_2 -> V_5 = 0 ; ( V_82 & 0x01 ) == 0 ; V_2 -> V_5 ++ )
V_82 >>= 1 ;
V_2 -> V_60 = V_87 ;
V_80 = F_32 ( V_78 , L_15 , NULL ) ;
if ( V_80 ) switch( * V_80 ) {
case 100 :
V_2 -> V_60 = V_88 ;
break;
case 50 :
V_2 -> V_60 = V_89 ;
break;
case 25 :
V_2 -> V_60 = V_87 ;
break;
}
V_2 -> V_42 = F_38 ( V_78 , 0 ) ;
if ( V_2 -> V_42 == V_62 )
F_13 ( V_22
L_16 ,
V_78 -> V_85 ) ;
V_2 -> V_4 = F_39 ( ( * V_81 ) , 0x1000 ) ;
if ( V_2 -> V_4 == NULL ) {
F_13 ( V_84 L_17 ,
V_78 -> V_85 ) ;
F_33 ( V_2 ) ;
return NULL ;
}
F_10 ( V_26 , 0 ) ;
if ( F_40 ( V_2 -> V_42 , F_16 , V_90 ,
L_18 , V_2 ) )
V_2 -> V_42 = V_62 ;
F_13 ( V_91 L_19 ,
* V_81 , V_2 -> V_42 , V_78 -> V_85 ) ;
return V_2 ;
}
static void T_5 F_41 ( struct V_1 * V_2 ,
struct V_77 * V_92 ,
struct V_77 * V_93 ,
int V_73 )
{
struct V_52 * V_53 ;
V_53 = F_31 ( sizeof( struct V_52 ) , V_83 ) ;
if ( V_53 == NULL )
return;
V_53 -> V_92 = F_42 ( V_92 ) ;
V_53 -> V_93 = F_42 ( V_93 ) ;
V_53 -> type = V_94 ;
V_53 -> V_54 = V_2 ;
V_53 -> V_73 = V_73 ;
V_53 -> V_63 = V_66 ;
V_53 -> V_95 = F_23 ;
V_53 -> V_96 = F_25 ;
V_53 -> V_97 = F_27 ;
F_34 ( & V_53 -> V_55 ) ;
if ( V_92 == V_93 )
V_53 -> V_44 = V_98 ;
F_43 ( & V_53 -> V_99 , & V_100 ) ;
F_13 ( V_91 L_20 , V_73 ,
( V_92 == V_93 ) ? L_21 : V_93 -> V_85 ) ;
}
static void T_5 F_44 ( void )
{
struct V_77 * V_78 , * V_101 , * V_102 ;
F_45 (np, L_22 , L_23 ) {
struct V_1 * V_2 ;
int V_103 ;
V_2 = F_30 ( V_78 ) ;
if ( V_2 == NULL )
continue;
V_101 = F_46 ( V_78 , NULL ) ;
V_103 = ! V_101 || strcmp ( V_101 -> V_104 , L_24 ) ;
F_47 ( V_101 ) ;
if ( V_103 ) {
int V_105 , V_8 ;
V_102 = F_48 ( V_78 ) ;
if ( V_102 == NULL )
continue;
V_105 = V_102 -> V_104 [ 0 ] == 'u' ? 2 : 1 ;
for ( V_8 = 0 ; V_8 < V_105 ; V_8 ++ )
F_41 ( V_2 , V_78 , V_78 , V_8 ) ;
} else {
for ( V_101 = NULL ;
( V_101 = F_46 ( V_78 , V_101 ) ) != NULL ; ) {
const T_4 * V_3 = F_32 ( V_101 ,
L_25 , NULL ) ;
if ( V_3 == NULL )
continue;
F_41 ( V_2 , V_78 , V_101 , * V_3 ) ;
}
}
}
}
static void F_49 ( struct V_106 * V_107 )
{
F_14 ( V_107 -> V_108 ) ;
}
static int F_50 ( struct V_52 * V_53 , T_1 V_56 , int V_57 ,
T_4 V_58 , T_1 * V_37 , int V_31 )
{
struct V_106 * V_107 = V_53 -> V_54 ;
struct V_109 * V_110 = (struct V_109 * ) & V_107 -> V_37 [ 1 ] ;
struct V_111 V_112 ;
int V_113 = V_56 & 1 ;
int V_114 ;
int V_115 = 0 ;
if ( V_31 > 16 )
return - V_65 ;
F_35 ( & V_112 ) ;
for ( V_114 = 0 ; V_114 < 16 ; V_114 ++ ) {
memset ( V_107 , 0 , sizeof( struct V_106 ) ) ;
V_110 -> V_53 = V_53 -> V_73 ;
V_110 -> V_116 = V_31 ;
switch( V_53 -> V_63 ) {
case V_66 :
if ( V_57 != 0 )
return - V_65 ;
V_110 -> V_117 = V_56 ;
V_110 -> V_63 = V_118 ;
break;
case V_68 :
case V_70 :
if ( V_57 != 1 )
return - V_65 ;
V_110 -> V_117 = V_56 & 0xfe ;
V_110 -> V_119 = V_56 ;
V_110 -> V_120 = V_58 ;
if ( V_53 -> V_63 == V_68 )
V_110 -> V_63 = V_121 ;
else
V_110 -> V_63 = V_122 ;
break;
default:
return - V_65 ;
}
F_28 ( & V_112 ) ;
V_107 -> V_37 [ 0 ] = V_123 ;
V_107 -> V_124 [ 0 ] = 0xff ;
V_107 -> V_125 = sizeof( struct V_109 ) + 1 ;
V_107 -> V_126 = F_49 ;
V_107 -> V_108 = & V_112 ;
if ( ! V_113 && V_31 ) {
memcpy ( V_110 -> V_37 , V_37 , V_31 ) ;
V_107 -> V_125 += V_31 ;
}
V_115 = F_51 ( V_107 ) ;
if ( V_115 )
return V_115 ;
F_29 ( & V_112 ) ;
if ( V_107 -> V_124 [ 0 ] == V_127 )
break;
F_8 ( 15 ) ;
}
if ( V_107 -> V_124 [ 0 ] != V_127 )
return - V_23 ;
for ( V_114 = 0 ; V_114 < 16 ; V_114 ++ ) {
memset ( V_107 , 0 , sizeof( struct V_106 ) ) ;
F_8 ( 15 ) ;
V_110 -> V_53 = V_128 ;
F_28 ( & V_112 ) ;
V_107 -> V_37 [ 0 ] = V_123 ;
V_107 -> V_124 [ 0 ] = 0xff ;
V_107 -> V_125 = 2 ;
V_107 -> V_126 = F_49 ;
V_107 -> V_108 = & V_112 ;
V_115 = F_51 ( V_107 ) ;
if ( V_115 )
return V_115 ;
F_29 ( & V_112 ) ;
if ( V_107 -> V_124 [ 0 ] == V_127 && ! V_113 )
return 0 ;
if ( V_107 -> V_124 [ 0 ] == V_129 && V_113 ) {
int V_130 = V_107 -> V_131 - 1 ;
if ( V_130 != V_31 ) {
F_13 ( V_22 L_26
L_27 , V_130 , V_31 ) ;
return - V_23 ;
}
if ( V_31 )
memcpy ( V_37 , & V_107 -> V_124 [ 1 ] , V_31 ) ;
return 0 ;
}
}
return - V_23 ;
}
static void T_5 F_52 ( void )
{
struct V_52 * V_53 ;
struct V_77 * V_93 ;
int V_73 , V_132 ;
if ( ! F_53 () )
return;
V_93 = F_54 ( NULL , L_28 ) ;
if ( V_93 == NULL )
V_93 = F_54 ( NULL , L_29 ) ;
if ( V_93 == NULL )
return;
F_13 ( V_91 L_30 , V_93 -> V_85 ) ;
for ( V_73 = 1 ; V_73 <= 2 ; V_73 ++ ) {
V_132 = sizeof( struct V_52 ) + sizeof( struct V_106 ) ;
V_53 = F_31 ( V_132 , V_83 ) ;
if ( V_53 == NULL )
return;
V_53 -> V_92 = V_93 ;
V_53 -> V_93 = V_93 ;
V_53 -> type = V_133 ;
V_53 -> V_73 = V_73 ;
V_53 -> V_63 = V_66 ;
V_53 -> V_54 = V_53 + 1 ;
V_53 -> V_97 = F_50 ;
F_34 ( & V_53 -> V_55 ) ;
V_53 -> V_44 = V_98 ;
F_43 ( & V_53 -> V_99 , & V_100 ) ;
F_13 ( V_91 L_31 , V_73 ) ;
}
}
static void F_55 ( struct V_134 * V_135 , void * V_136 )
{
F_14 ( V_136 ) ;
}
static int F_56 ( struct V_52 * V_53 , T_1 V_56 , int V_57 ,
T_4 V_58 , T_1 * V_37 , int V_31 )
{
struct V_134 * V_135 = V_53 -> V_54 ;
struct V_111 V_112 ;
int V_113 = V_56 & 1 ;
int V_115 = 0 ;
if ( ( V_113 && V_31 > V_137 ) ||
( ( ! V_113 ) && V_31 > V_138 ) )
return - V_65 ;
memset ( V_135 , 0 , sizeof( struct V_134 ) ) ;
V_135 -> V_139 . V_53 = V_53 -> V_73 ;
V_135 -> V_139 . V_140 = V_56 ;
V_135 -> V_139 . V_141 = V_31 ;
switch( V_53 -> V_63 ) {
case V_66 :
if ( V_57 != 0 )
return - V_65 ;
V_135 -> V_139 . type = V_142 ;
break;
case V_68 :
case V_70 :
if ( V_57 > 3 || V_57 < 1 )
return - V_65 ;
V_135 -> V_139 . V_143 = V_57 ;
memcpy ( & V_135 -> V_139 . V_58 , ( ( char * ) & V_58 ) + ( 4 - V_57 ) ,
V_57 ) ;
if ( V_53 -> V_63 == V_68 )
V_135 -> V_139 . type = V_144 ;
else
V_135 -> V_139 . type = V_145 ;
break;
default:
return - V_65 ;
}
if ( ! V_113 && V_31 )
memcpy ( V_135 -> V_139 . V_37 , V_37 , V_31 ) ;
F_35 ( & V_112 ) ;
V_135 -> V_126 = F_55 ;
V_135 -> V_136 = & V_112 ;
V_115 = F_57 ( V_135 ) ;
if ( V_115 < 0 )
return V_115 ;
F_29 ( & V_112 ) ;
V_115 = V_135 -> V_146 ;
if ( V_113 && V_31 )
memcpy ( V_37 , V_135 -> V_139 . V_37 , V_31 ) ;
return V_115 < 0 ? V_115 : 0 ;
}
static void T_5 F_58 ( void )
{
struct V_77 * V_92 , * V_93 ;
struct V_52 * V_53 ;
const T_4 * V_3 ;
int V_132 ;
if ( ! F_59 () )
return;
V_92 = F_54 ( NULL , L_32 ) ;
if ( V_92 == NULL )
V_92 = F_54 ( NULL , L_33 ) ;
if ( V_92 == NULL )
return;
F_13 ( V_91 L_34 , V_92 -> V_85 ) ;
for ( V_93 = NULL ;
( V_93 = F_46 ( V_92 , V_93 ) ) != NULL ; ) {
if ( strcmp ( V_93 -> type , L_22 ) &&
strcmp ( V_93 -> type , L_24 ) )
continue;
V_3 = F_32 ( V_93 , L_25 , NULL ) ;
if ( V_3 == NULL )
continue;
V_132 = sizeof( struct V_52 ) + sizeof( struct V_134 ) ;
V_53 = F_31 ( V_132 , V_83 ) ;
if ( V_53 == NULL )
return;
V_53 -> V_92 = V_92 ;
V_53 -> V_93 = F_42 ( V_93 ) ;
V_53 -> type = V_147 ;
V_53 -> V_73 = * V_3 ;
V_53 -> V_63 = V_66 ;
V_53 -> V_54 = V_53 + 1 ;
V_53 -> V_97 = F_56 ;
F_34 ( & V_53 -> V_55 ) ;
V_53 -> V_44 = 0 ;
F_43 ( & V_53 -> V_99 , & V_100 ) ;
F_13 ( V_91 L_35 ,
V_53 -> V_73 , V_93 -> V_85 ) ;
}
}
struct V_52 * F_60 ( struct V_77 * V_148 )
{
struct V_77 * V_149 = F_42 ( V_148 ) ;
struct V_77 * V_150 = NULL ;
struct V_52 * V_53 ;
while( V_149 ) {
F_61 (bus, &pmac_i2c_busses, link) {
if ( V_149 == V_53 -> V_93 ) {
if ( V_150 && V_53 -> V_44 & V_98 ) {
const T_4 * V_3 ;
V_3 = F_32 ( V_150 , L_25 ,
NULL ) ;
if ( ! V_3 )
continue;
if ( ( ( * V_3 ) >> 8 ) != V_53 -> V_73 )
continue;
}
F_47 ( V_149 ) ;
F_47 ( V_150 ) ;
return V_53 ;
}
}
F_47 ( V_150 ) ;
V_150 = V_149 ;
V_149 = F_48 ( V_149 ) ;
}
return NULL ;
}
T_1 F_62 ( struct V_77 * V_151 )
{
const T_4 * V_3 = F_32 ( V_151 , L_25 , NULL ) ;
if ( V_3 == NULL )
return 0 ;
return ( * V_3 ) & 0xff ;
}
struct V_77 * F_63 ( struct V_52 * V_53 )
{
return V_53 -> V_92 ;
}
struct V_77 * F_64 ( struct V_52 * V_53 )
{
return V_53 -> V_93 ;
}
int F_65 ( struct V_52 * V_53 )
{
return V_53 -> type ;
}
int F_66 ( struct V_52 * V_53 )
{
return V_53 -> V_44 ;
}
int F_67 ( struct V_52 * V_53 )
{
return V_53 -> V_73 ;
}
struct V_152 * F_68 ( struct V_52 * V_53 )
{
return & V_53 -> V_153 ;
}
struct V_52 * F_69 ( struct V_152 * V_153 )
{
struct V_52 * V_53 ;
F_61 (bus, &pmac_i2c_busses, link)
if ( & V_53 -> V_153 == V_153 )
return V_53 ;
return NULL ;
}
int F_70 ( struct V_77 * V_154 , struct V_152 * V_153 )
{
struct V_52 * V_53 = F_60 ( V_154 ) ;
if ( V_53 == NULL )
return 0 ;
return ( & V_53 -> V_153 == V_153 ) ;
}
int F_71 ( struct V_77 * V_78 )
{
struct V_52 * V_53 , * V_155 = NULL ;
F_61 (bus, &pmac_i2c_busses, link) {
if ( V_78 == V_53 -> V_92 ) {
V_155 = V_53 ;
break;
}
}
if ( ! V_155 )
return - V_156 ;
return F_72 ( V_53 , 0 ) ;
}
int F_73 ( struct V_77 * V_78 )
{
struct V_52 * V_53 , * V_155 = NULL ;
F_61 (bus, &pmac_i2c_busses, link) {
if ( V_78 == V_53 -> V_92 ) {
V_155 = V_53 ;
break;
}
}
if ( ! V_155 )
return - V_156 ;
F_74 ( V_53 ) ;
return 0 ;
}
int F_72 ( struct V_52 * V_53 , int V_13 )
{
int V_115 ;
F_24 ( & V_53 -> V_55 ) ;
V_53 -> V_13 = V_13 || V_157 ;
V_53 -> V_158 = 1 ;
V_53 -> V_63 = V_66 ;
if ( V_53 -> V_95 && ( V_115 = V_53 -> V_95 ( V_53 ) ) != 0 ) {
V_53 -> V_158 = 0 ;
F_26 ( & V_53 -> V_55 ) ;
return V_115 ;
}
return 0 ;
}
void F_74 ( struct V_52 * V_53 )
{
F_75 ( ! V_53 -> V_158 ) ;
if ( V_53 -> V_96 )
V_53 -> V_96 ( V_53 ) ;
V_53 -> V_158 = 0 ;
F_26 ( & V_53 -> V_55 ) ;
}
int F_76 ( struct V_52 * V_53 , int V_63 )
{
F_75 ( ! V_53 -> V_158 ) ;
if ( V_63 < V_64 || V_63 > V_70 ) {
F_13 ( V_84 L_36
L_37 , V_63 , V_53 -> V_93 -> V_85 ) ;
return - V_65 ;
}
V_53 -> V_63 = V_63 ;
return 0 ;
}
int F_77 ( struct V_52 * V_53 , T_1 V_56 , int V_57 ,
T_4 V_58 , T_1 * V_37 , int V_31 )
{
int V_115 ;
F_75 ( ! V_53 -> V_158 ) ;
F_78 ( L_38
L_39 , V_53 -> V_73 , V_56 , V_53 -> V_63 , V_57 ,
V_58 , V_31 , V_53 -> V_93 -> V_85 ) ;
V_115 = V_53 -> V_97 ( V_53 , V_56 , V_57 , V_58 , V_37 , V_31 ) ;
#ifdef F_79
if ( V_115 )
F_78 ( L_40 , V_115 ) ;
#endif
return V_115 ;
}
static void F_80 ( void (* F_81)( struct V_77 * V_154 ,
int V_159 ) )
{
struct V_52 * V_53 ;
struct V_77 * V_78 ;
static struct V_160 {
char * V_104 ;
char * V_161 ;
int V_159 ;
} V_162 [] = {
{ L_41 , L_42 , V_163 } ,
{ L_41 , L_43 , V_163 } ,
{ L_41 , NULL , V_164 } ,
{ L_44 , NULL , 0 } ,
{ L_45 , NULL , 0 } ,
{ L_46 , NULL , 0 } ,
{ NULL , NULL , 0 } ,
} ;
F_61 (bus, &pmac_i2c_busses, link) {
for ( V_78 = NULL ;
( V_78 = F_46 ( V_53 -> V_93 , V_78 ) ) != NULL ; ) {
struct V_160 * V_149 ;
if ( V_53 -> V_44 & V_98 )
if ( V_53 != F_60 ( V_78 ) )
continue;
for ( V_149 = V_162 ; V_149 -> V_104 != NULL ; V_149 ++ ) {
if ( strcmp ( V_78 -> V_104 , V_149 -> V_104 ) )
continue;
if ( V_149 -> V_161 &&
! F_82 ( V_78 , V_149 -> V_161 ) )
continue;
if ( V_149 -> V_159 & V_163 )
break;
F_81 ( V_78 , V_149 -> V_159 ) ;
break;
}
}
}
}
static void * F_83 ( struct V_165 * V_166 , struct V_167 * args )
{
struct V_168 * V_169 ;
struct V_52 * V_53 ;
V_53 = F_60 ( V_166 -> V_148 ) ;
if ( V_53 == NULL ) {
F_13 ( V_84 L_47 ,
V_166 -> V_148 -> V_85 ) ;
return NULL ;
}
if ( F_72 ( V_53 , 0 ) ) {
F_13 ( V_84 L_48 ,
V_166 -> V_148 -> V_85 ) ;
return NULL ;
}
V_169 = F_31 ( sizeof( struct V_168 ) , V_83 ) ;
if ( V_169 == NULL ) {
F_74 ( V_53 ) ;
return NULL ;
}
V_169 -> V_53 = V_53 ;
V_169 -> V_170 = F_62 ( V_166 -> V_148 ) ;
V_169 -> V_159 = ( int ) ( long ) V_166 -> V_171 ;
return V_169 ;
}
static void F_84 ( struct V_165 * V_166 , void * V_172 )
{
struct V_168 * V_169 = V_172 ;
if ( V_169 == NULL )
return;
F_74 ( V_169 -> V_53 ) ;
F_33 ( V_169 ) ;
}
static int F_85 ( T_6 , T_4 V_31 )
{
struct V_168 * V_169 = V_172 ;
V_169 -> V_173 = V_31 ;
return F_77 ( V_169 -> V_53 , V_169 -> V_170 | V_174 , 0 , 0 ,
V_169 -> V_175 , V_31 ) ;
}
static int F_86 ( T_6 , T_4 V_31 , const T_1 * V_37 )
{
struct V_168 * V_169 = V_172 ;
return F_77 ( V_169 -> V_53 , V_169 -> V_170 | V_176 , 0 , 0 ,
( T_1 * ) V_37 , V_31 ) ;
}
static void F_87 ( struct V_168 * V_169 ,
T_4 V_31 , const T_1 * V_177 , const T_1 * V_6 )
{
int V_8 ;
if ( V_169 -> V_159 & V_164 ) {
for ( V_8 = 0 ; V_8 < V_31 ; V_8 ++ )
V_169 -> V_178 [ V_8 ] = ( V_169 -> V_175 [ V_8 ] & V_177 [ V_8 ] ) | V_6 [ V_8 ] ;
} else {
for ( V_8 = 0 ; V_8 < V_31 ; V_8 ++ )
V_169 -> V_178 [ V_8 ] = ( V_169 -> V_175 [ V_8 ] & ~ V_177 [ V_8 ] )
| ( V_6 [ V_8 ] & V_177 [ V_8 ] ) ;
}
}
static int F_88 ( T_6 , T_4 V_179 , T_4 V_180 ,
T_4 V_181 , const T_1 * V_182 ,
const T_1 * V_183 )
{
struct V_168 * V_169 = V_172 ;
if ( V_179 > V_169 -> V_173 || V_180 > V_169 -> V_173 ||
V_181 > V_169 -> V_173 || V_180 > V_179 )
return - V_65 ;
F_87 ( V_169 , V_179 , V_182 , V_183 ) ;
return F_77 ( V_169 -> V_53 , V_169 -> V_170 | V_176 , 0 , 0 ,
V_169 -> V_178 , V_181 ) ;
}
static int F_89 ( T_6 , T_1 V_58 , T_4 V_31 )
{
struct V_168 * V_169 = V_172 ;
V_169 -> V_173 = V_31 ;
return F_77 ( V_169 -> V_53 , V_169 -> V_170 | V_174 , 1 , V_58 ,
V_169 -> V_175 , V_31 ) ;
}
static int F_90 ( T_6 , T_1 V_58 , T_4 V_31 ,
const T_1 * V_37 )
{
struct V_168 * V_169 = V_172 ;
return F_77 ( V_169 -> V_53 , V_169 -> V_170 | V_176 , 1 ,
V_58 , ( T_1 * ) V_37 , V_31 ) ;
}
static int F_91 ( T_6 , int V_63 )
{
struct V_168 * V_169 = V_172 ;
return F_76 ( V_169 -> V_53 , V_63 ) ;
}
static int F_92 ( T_6 , T_1 V_58 , T_4 V_179 ,
T_4 V_180 , T_4 V_181 , const T_1 * V_182 ,
const T_1 * V_183 )
{
struct V_168 * V_169 = V_172 ;
if ( V_179 > V_169 -> V_173 || V_180 > V_169 -> V_173 ||
V_181 > V_169 -> V_173 || V_180 > V_179 )
return - V_65 ;
F_87 ( V_169 , V_179 , V_182 , V_183 ) ;
return F_77 ( V_169 -> V_53 , V_169 -> V_170 | V_176 , 1 ,
V_58 , V_169 -> V_178 , V_181 ) ;
}
static int F_93 ( T_6 , T_4 V_31 ,
const T_1 * V_182 ,
const T_1 * V_183 )
{
struct V_168 * V_169 = V_172 ;
int V_8 , V_184 ;
if ( ! args || ! args -> V_116 || ! args -> V_185 [ 0 ] . V_149 )
return - V_65 ;
if ( V_31 > V_169 -> V_173 )
return - V_65 ;
for ( V_8 = 0 , V_184 = 1 ; V_184 && V_8 < V_31 ; V_8 ++ )
if ( ( V_169 -> V_175 [ V_8 ] & V_182 [ V_8 ] ) != V_183 [ V_8 ] )
V_184 = 0 ;
* args -> V_185 [ 0 ] . V_149 = V_184 ;
return 0 ;
}
static int F_94 ( T_6 , T_4 V_186 )
{
F_8 ( ( V_186 + 999 ) / 1000 ) ;
return 0 ;
}
static void T_5 F_95 ( struct V_77 * V_78 , int V_159 )
{
F_78 ( L_49 , V_78 -> V_85 ) ;
F_96 ( V_78 , & V_187 ,
( void * ) ( long ) V_159 ) ;
}
static void T_5 F_97 ( struct V_77 * V_78 , int V_159 )
{
F_78 ( L_49 , V_78 -> V_85 ) ;
F_98 ( V_78 , NULL , 0 , V_188 , NULL ) ;
}
static void F_99 ( struct V_77 * V_78 , int V_159 )
{
F_78 ( L_50 , V_78 -> V_85 ) ;
F_98 ( V_78 , NULL , 0 , V_189 , NULL ) ;
}
static void F_100 ( struct V_77 * V_78 , int V_159 )
{
F_78 ( L_51 , V_78 -> V_85 ) ;
F_98 ( V_78 , NULL , 0 , V_190 , NULL ) ;
}
void F_101 ( void )
{
F_80 ( F_99 ) ;
}
void F_102 ( void )
{
F_80 ( F_100 ) ;
}
int T_5 F_103 ( void )
{
static int V_191 ;
if ( V_191 )
return 0 ;
V_191 = 1 ;
F_44 () ;
#ifdef F_104
F_52 () ;
#endif
#ifdef F_105
F_58 () ;
#endif
F_80 ( F_95 ) ;
return 0 ;
}
static int T_5 F_106 ( void )
{
struct V_52 * V_53 ;
int V_8 = 0 ;
V_157 = 0 ;
F_61 (bus, &pmac_i2c_busses, link) {
V_53 -> V_192 =
F_107 ( L_52 , V_8 ++ ) ;
if ( V_53 -> V_192 == NULL )
return - V_193 ;
V_53 -> V_192 -> V_154 . V_194 = V_53 ;
V_53 -> V_192 -> V_154 . V_195 = V_53 -> V_93 ;
F_108 ( V_53 -> V_192 ) ;
}
F_80 ( F_97 ) ;
return 0 ;
}
