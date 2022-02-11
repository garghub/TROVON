static int F_1 ( unsigned long V_1 )
{
struct V_2 * V_3 ;
T_1 T_2 * V_4 = ( void T_2 * ) V_1 ;
T_1 V_5 [ V_6 ] ;
int V_7 = 0 ;
memset ( V_5 , 0 , V_6 ) ;
F_2 (c, &i2o_controllers, list)
V_5 [ V_3 -> V_8 ] = 1 ;
if ( F_3 ( V_4 , V_5 , V_6 ) )
V_7 = - V_9 ;
return V_7 ;
}
static int F_4 ( unsigned long V_1 )
{
struct V_2 * V_3 ;
struct V_10 T_2 * V_11 = (struct V_10 T_2 * ) V_1 ;
struct V_10 V_12 ;
T_3 * V_13 ;
int V_14 ;
T_4 V_15 ;
int V_7 = 0 ;
if ( F_5 ( & V_12 , V_11 , sizeof( struct V_10 ) ) )
return - V_9 ;
if ( F_6 ( V_15 , V_12 . V_15 ) < 0 )
return - V_9 ;
if ( V_12 . V_16 == NULL )
return - V_9 ;
V_3 = F_7 ( V_12 . V_17 ) ;
if ( ! V_3 )
return - V_18 ;
V_13 = ( T_3 * ) V_3 -> V_13 . V_19 ;
V_14 = 8 + ( ( V_13 -> V_20 * V_13 -> V_21 ) << 2 ) ;
if ( F_8 ( V_14 , V_12 . V_15 ) )
V_7 = - V_9 ;
else if ( V_14 > V_15 )
V_7 = - V_22 ;
else if ( F_3 ( V_12 . V_16 , ( void * ) V_13 , V_14 ) )
V_7 = - V_9 ;
return V_7 ;
}
static int F_9 ( unsigned long V_1 )
{
struct V_2 * V_3 ;
struct V_10 T_2 * V_11 = (struct V_10 T_2 * ) V_1 ;
struct V_10 V_12 ;
T_5 * V_23 ;
int V_14 ;
int V_7 = 0 ;
T_4 V_15 ;
if ( F_5 ( & V_12 , V_11 , sizeof( struct V_10 ) ) )
return - V_9 ;
if ( F_6 ( V_15 , V_12 . V_15 ) < 0 )
return - V_9 ;
if ( V_12 . V_16 == NULL )
return - V_9 ;
V_3 = F_7 ( V_12 . V_17 ) ;
if ( ! V_3 )
return - V_18 ;
V_23 = ( T_5 * ) V_3 -> V_23 ;
V_14 = ( unsigned int ) V_23 -> V_24 << 2 ;
if ( F_8 ( V_14 , V_12 . V_15 ) )
V_7 = - V_9 ;
else if ( V_14 > V_15 )
V_7 = - V_22 ;
else if ( F_3 ( V_12 . V_16 , V_23 , V_14 ) )
V_7 = - V_9 ;
return V_7 ;
}
static int F_10 ( unsigned long V_1 , unsigned int type )
{
int V_7 = 0 ;
struct V_2 * V_3 ;
struct V_25 * V_26 ;
struct V_27 T_2 * V_11 =
(struct V_27 T_2 * ) V_1 ;
struct V_27 V_12 ;
T_4 V_15 ;
T_1 * V_28 ;
T_1 * V_29 ;
int V_14 = 0 ;
T_4 V_30 = ( type == V_31 ?
V_32 : V_33 ) ;
if ( F_5 ( & V_12 , V_11 , sizeof( struct V_27 ) ) )
return - V_9 ;
if ( F_6 ( V_15 , V_12 . V_15 ) )
return - V_9 ;
V_3 = F_7 ( V_12 . V_17 ) ;
if ( ! V_3 )
return - V_18 ;
V_26 = F_11 ( V_3 , V_12 . V_34 ) ;
if ( ! V_26 )
return - V_18 ;
V_28 = F_12 ( V_12 . V_35 , V_12 . V_36 ) ;
if ( F_13 ( V_28 ) )
return F_14 ( V_28 ) ;
V_29 = F_15 ( 65536 , V_37 ) ;
if ( ! V_29 ) {
F_16 ( V_28 ) ;
return - V_38 ;
}
V_14 = F_17 ( V_26 , V_30 , V_28 , V_12 . V_36 , V_29 , 65536 ) ;
F_16 ( V_28 ) ;
if ( V_14 < 0 ) {
F_16 ( V_29 ) ;
return - V_39 ;
}
if ( F_8 ( V_14 , V_12 . V_15 ) )
V_7 = - V_9 ;
else if ( V_14 > V_15 )
V_7 = - V_22 ;
else if ( F_3 ( V_12 . V_16 , V_29 , V_14 ) )
V_7 = - V_9 ;
F_16 ( V_29 ) ;
return V_7 ;
}
static int F_18 ( unsigned long V_1 )
{
struct V_40 V_41 ;
struct V_40 T_2 * V_42 = (struct V_40 T_2 * ) V_1 ;
unsigned char V_43 = 0 , V_44 = 1 ;
struct V_45 V_46 ;
struct V_47 * V_48 ;
unsigned int V_49 = 0 , V_50 = 0 , V_51 = 8192 ;
struct V_2 * V_3 ;
if ( F_5 ( & V_41 , V_42 , sizeof( struct V_40 ) ) )
return - V_9 ;
if ( F_6 ( V_50 , V_41 . V_50 ) < 0 )
return - V_9 ;
if ( F_6 ( V_43 , V_41 . V_43 ) < 0 )
return - V_9 ;
if ( F_6 ( V_44 , V_41 . V_44 ) < 0 )
return - V_9 ;
if ( V_44 == V_43 )
V_51 = V_50 - ( V_43 - 1 ) * 8192 ;
if ( ! V_41 . V_52 || ! F_19 ( V_53 , V_41 . V_52 , V_51 ) )
return - V_9 ;
V_3 = F_7 ( V_41 . V_17 ) ;
if ( ! V_3 )
return - V_18 ;
V_48 = F_20 ( V_3 , V_54 ) ;
if ( F_13 ( V_48 ) )
return F_14 ( V_48 ) ;
if ( F_21 ( & V_3 -> V_55 -> V_26 , & V_46 , V_51 ) ) {
F_22 ( V_3 , V_48 ) ;
return - V_38 ;
}
if ( F_23 ( V_46 . V_19 , V_41 . V_52 , V_51 ) ) {
F_22 ( V_3 , V_48 ) ;
F_24 ( & V_3 -> V_55 -> V_26 , & V_46 ) ;
return - V_9 ;
}
V_48 -> V_56 . V_57 [ 0 ] = F_25 ( V_58 | V_59 ) ;
V_48 -> V_56 . V_57 [ 1 ] =
F_25 ( V_60 << 24 | V_61 << 12 |
V_62 ) ;
V_48 -> V_56 . V_57 [ 2 ] = F_25 ( V_63 . V_64 ) ;
V_48 -> V_56 . V_57 [ 3 ] = F_25 ( 0 ) ;
V_48 -> V_65 [ 0 ] =
F_25 ( ( ( ( T_4 ) V_41 . V_66 ) << 24 ) | ( ( ( T_4 ) V_41 .
V_67 ) << 16 ) |
( ( ( T_4 ) V_43 ) << 8 ) | ( ( ( T_4 ) V_44 ) ) ) ;
V_48 -> V_65 [ 1 ] = F_25 ( V_50 ) ;
V_48 -> V_65 [ 2 ] = F_25 ( V_41 . V_68 ) ;
V_48 -> V_65 [ 3 ] = F_25 ( 0xD0000000 | V_51 ) ;
V_48 -> V_65 [ 4 ] = F_25 ( V_46 . V_69 ) ;
F_26 ( L_1 , V_44 , V_43 , V_51 ) ;
V_49 = F_27 ( V_3 , V_48 , 60 , & V_46 ) ;
if ( V_49 != - V_70 )
F_24 ( & V_3 -> V_55 -> V_26 , & V_46 ) ;
if ( V_49 != V_71 ) {
F_28 ( L_2 , V_49 ) ;
return V_49 ;
}
return 0 ;
}
static int F_29 ( unsigned long V_1 )
{
struct V_40 V_41 ;
struct V_40 T_2 * V_42 = (struct V_40 T_2 * ) V_1 ;
unsigned char V_43 = 0 , V_44 = 1 ;
struct V_45 V_46 ;
struct V_47 * V_48 ;
unsigned int V_49 = 0 , V_50 = 0 , V_51 = 8192 ;
struct V_2 * V_3 ;
int V_7 = 0 ;
if ( F_5 ( & V_41 , V_42 , sizeof( struct V_40 ) ) )
return - V_9 ;
if ( F_6 ( V_50 , V_41 . V_50 ) < 0 )
return - V_9 ;
if ( F_6 ( V_43 , V_41 . V_43 ) < 0 )
return - V_9 ;
if ( F_6 ( V_44 , V_41 . V_44 ) < 0 )
return - V_9 ;
if ( V_44 == V_43 )
V_51 = V_50 - ( V_43 - 1 ) * 8192 ;
if ( ! V_41 . V_52 )
return - V_9 ;
V_3 = F_7 ( V_41 . V_17 ) ;
if ( ! V_3 )
return - V_18 ;
V_48 = F_20 ( V_3 , V_54 ) ;
if ( F_13 ( V_48 ) )
return F_14 ( V_48 ) ;
if ( F_21 ( & V_3 -> V_55 -> V_26 , & V_46 , V_51 ) ) {
F_22 ( V_3 , V_48 ) ;
return - V_38 ;
}
V_48 -> V_56 . V_57 [ 0 ] = F_25 ( V_58 | V_59 ) ;
V_48 -> V_56 . V_57 [ 1 ] =
F_25 ( V_72 << 24 | V_61 << 12 | V_62 ) ;
V_48 -> V_56 . V_57 [ 2 ] = F_25 ( V_63 . V_64 ) ;
V_48 -> V_56 . V_57 [ 3 ] = F_25 ( 0 ) ;
V_48 -> V_65 [ 0 ] =
F_25 ( ( T_4 ) V_41 . V_66 << 24 | ( T_4 ) V_41 .
V_67 << 16 | ( T_4 ) V_43 << 8 | ( T_4 ) V_44 ) ;
V_48 -> V_65 [ 1 ] = F_25 ( V_50 ) ;
V_48 -> V_65 [ 2 ] = F_25 ( V_41 . V_68 ) ;
V_48 -> V_65 [ 3 ] = F_25 ( 0xD0000000 | V_51 ) ;
V_48 -> V_65 [ 4 ] = F_25 ( V_46 . V_69 ) ;
F_26 ( L_3 , V_44 , V_43 , V_51 ) ;
V_49 = F_27 ( V_3 , V_48 , 60 , & V_46 ) ;
if ( V_49 != V_71 ) {
if ( V_49 != - V_70 )
F_24 ( & V_3 -> V_55 -> V_26 , & V_46 ) ;
F_28 ( L_4 , V_49 ) ;
return V_49 ;
}
if ( F_3 ( V_41 . V_52 , V_46 . V_19 , V_51 ) )
V_7 = - V_9 ;
F_24 ( & V_3 -> V_55 -> V_26 , & V_46 ) ;
return V_7 ;
}
static int F_30 ( unsigned long V_1 )
{
struct V_2 * V_3 ;
struct V_40 V_41 ;
struct V_40 T_2 * V_42 = (struct V_40 T_2 * ) V_1 ;
struct V_47 * V_48 ;
unsigned int V_50 ;
int V_73 ;
if ( F_5 ( & V_41 , V_42 , sizeof( struct V_40 ) ) )
return - V_9 ;
if ( F_6 ( V_50 , V_41 . V_50 ) < 0 )
return - V_9 ;
V_3 = F_7 ( V_41 . V_17 ) ;
if ( ! V_3 )
return - V_18 ;
V_48 = F_20 ( V_3 , V_54 ) ;
if ( F_13 ( V_48 ) )
return F_14 ( V_48 ) ;
V_48 -> V_56 . V_57 [ 0 ] = F_25 ( V_74 | V_75 ) ;
V_48 -> V_56 . V_57 [ 1 ] =
F_25 ( V_76 << 24 | V_61 << 12 | V_62 ) ;
V_48 -> V_56 . V_57 [ 2 ] = F_25 ( V_63 . V_64 ) ;
V_48 -> V_56 . V_57 [ 3 ] = F_25 ( 0 ) ;
V_48 -> V_65 [ 0 ] =
F_25 ( ( T_4 ) V_41 . V_66 << 24 | ( T_4 ) V_41 . V_67 << 16 ) ;
V_48 -> V_65 [ 1 ] = F_25 ( V_50 ) ;
V_48 -> V_65 [ 2 ] = F_25 ( V_41 . V_68 ) ;
V_73 = F_31 ( V_3 , V_48 , 10 ) ;
if ( V_73 != V_71 ) {
F_28 ( L_5 , V_73 ) ;
return - V_70 ;
}
return 0 ;
}
static int F_32 ( unsigned long V_1 )
{
int V_73 ;
int V_17 = ( int ) V_1 ;
struct V_47 * V_48 ;
struct V_2 * V_3 ;
V_3 = F_7 ( V_17 ) ;
if ( ! V_3 )
return - V_18 ;
V_48 = F_20 ( V_3 , V_54 ) ;
if ( F_13 ( V_48 ) )
return F_14 ( V_48 ) ;
V_48 -> V_56 . V_57 [ 0 ] = F_25 ( V_77 | V_75 ) ;
V_48 -> V_56 . V_57 [ 1 ] =
F_25 ( V_78 << 24 | V_61 << 12 | V_17 ) ;
V_48 -> V_56 . V_57 [ 2 ] = F_25 ( V_63 . V_64 ) ;
V_48 -> V_56 . V_57 [ 3 ] = F_25 ( 0 ) ;
V_73 = F_31 ( V_3 , V_48 , 10 ) ;
if ( V_73 != V_71 ) {
F_28 ( L_6 ,
V_73 ) ;
return - V_70 ;
}
return 0 ;
}
static int F_33 ( unsigned long V_1 , struct V_79 * V_80 )
{
struct V_47 * V_48 ;
struct V_81 T_2 * V_82 = (struct V_81 T_2 * ) V_1 ;
struct V_81 V_83 ;
struct V_2 * V_3 ;
struct V_25 * V_84 ;
if ( F_5 ( & V_83 , V_82 , sizeof( struct V_81 ) ) )
return - V_9 ;
V_3 = F_7 ( V_83 . V_17 ) ;
if ( ! V_3 )
return - V_18 ;
V_84 = F_11 ( V_3 , V_83 . V_34 ) ;
if ( ! V_84 )
return - V_85 ;
V_48 = F_20 ( V_3 , V_54 ) ;
if ( F_13 ( V_48 ) )
return F_14 ( V_48 ) ;
V_48 -> V_56 . V_57 [ 0 ] = F_25 ( V_77 | V_75 ) ;
V_48 -> V_56 . V_57 [ 1 ] =
F_25 ( V_86 << 24 | V_61 << 12 |
V_83 . V_34 ) ;
V_48 -> V_56 . V_57 [ 2 ] = F_25 ( V_63 . V_64 ) ;
V_48 -> V_56 . V_57 [ 3 ] = F_25 ( F_34 ( V_3 , V_80 -> V_87 ) ) ;
V_48 -> V_65 [ 0 ] = F_25 ( V_83 . V_88 ) ;
F_35 ( V_3 , V_48 ) ;
return 0 ;
}
static int F_36 ( unsigned long V_1 , struct V_79 * V_80 )
{
struct V_89 * V_90 = NULL ;
struct V_91 T_2 * V_92 = (struct V_91 T_2 * ) V_1 ;
struct V_91 V_93 ;
unsigned long V_66 ;
for ( V_90 = V_94 ; V_90 ; V_90 = V_90 -> V_95 )
if ( V_90 -> V_96 == ( V_97 ) V_80 -> V_87 )
break;
if ( ! V_90 -> V_98 )
return - V_99 ;
memcpy ( & V_93 . V_100 , & V_90 -> V_101 [ V_90 -> V_102 ] , sizeof( struct V_103 ) ) ;
F_37 ( V_90 -> V_102 , V_104 ) ;
F_38 ( & V_105 , V_66 ) ;
V_90 -> V_98 -- ;
V_93 . V_106 = V_90 -> V_98 ;
V_93 . V_107 = V_90 -> V_108 ;
F_39 ( & V_105 , V_66 ) ;
if ( F_3 ( V_92 , & V_93 , sizeof( struct V_91 ) ) )
return - V_9 ;
return 0 ;
}
static int F_40 ( struct V_79 * V_79 , unsigned V_109 ,
unsigned long V_1 )
{
struct V_110 T_2 * V_11 ;
struct V_2 * V_3 ;
T_4 T_2 * V_111 ;
T_4 * V_112 = NULL ;
T_4 T_2 * V_113 = NULL ;
T_4 V_114 = 0 ;
T_4 V_115 = 0 ;
T_4 V_116 = 0 ;
struct V_45 V_117 [ V_118 ] ;
T_4 V_119 = 0 ;
T_4 V_120 = 0 ;
T_4 V_121 = 0 ;
T_4 V_122 = 0 ;
T_6 * V_123 ;
struct V_47 * V_48 ;
unsigned int V_17 ;
V_11 = (struct V_110 T_2 * ) V_1 ;
if ( F_6 ( V_17 , & V_11 -> V_17 ) || F_6 ( V_121 , & V_11 -> V_48 ) )
return - V_9 ;
V_111 = F_41 ( V_121 ) ;
V_3 = F_7 ( V_17 ) ;
if ( ! V_3 ) {
F_26 ( L_7 , V_17 ) ;
return - V_18 ;
}
V_123 = V_3 -> V_124 . V_19 ;
if ( F_6 ( V_114 , & V_111 [ 0 ] ) ) {
F_42 ( L_8 ) ;
return - V_9 ;
}
V_114 = V_114 >> 16 ;
if ( V_114 > V_123 -> V_125 ) {
F_42 ( L_9 ) ;
return - V_9 ;
}
V_113 = & V_111 [ V_114 ] ;
V_114 <<= 2 ;
V_48 = F_20 ( V_3 , V_54 ) ;
if ( F_13 ( V_48 ) )
return F_14 ( V_48 ) ;
V_116 = - V_9 ;
if ( F_5 ( V_48 , V_111 , V_114 ) ) {
F_42 ( L_10 ) ;
goto V_126;
}
F_43 ( V_48 ) ;
if ( F_6 ( V_115 , & V_113 [ 0 ] ) < 0 )
goto V_126;
V_115 >>= 16 ;
V_115 <<= 2 ;
V_116 = - V_38 ;
V_112 = F_44 ( V_115 , V_37 ) ;
if ( ! V_112 ) {
F_45 ( V_127 L_11 ,
V_3 -> V_128 ) ;
goto V_126;
}
V_119 = ( V_48 -> V_56 . V_57 [ 0 ] >> 4 ) & 0x0f ;
memset ( V_117 , 0 , sizeof( V_117 [ 0 ] ) * V_118 ) ;
if ( V_119 ) {
struct V_129 * V_130 ;
if ( V_119 * 4 >= V_114 ) {
V_116 = - V_9 ;
goto V_131;
}
V_130 = (struct V_129 * ) ( ( & V_48 -> V_56 . V_57 [ 0 ] ) +
V_119 ) ;
V_120 =
( V_114 - V_119 * 4 ) / sizeof( struct V_129 ) ;
if ( V_120 > V_118 ) {
F_45 ( V_132 L_12 ,
V_3 -> V_128 , V_120 ) ;
V_116 = - V_133 ;
goto V_131;
}
for ( V_121 = 0 ; V_121 < V_120 ; V_121 ++ ) {
int V_134 ;
struct V_45 * V_90 ;
if ( ! ( V_130 [ V_121 ] . V_135 & 0x10000000
) ) {
F_45 ( V_132
L_13 ,
V_3 -> V_128 , V_121 , V_130 [ V_121 ] . V_135 ) ;
V_116 = - V_133 ;
goto V_131;
}
V_134 = V_130 [ V_121 ] . V_135 & 0xffffff ;
V_90 = & ( V_117 [ V_122 ] ) ;
if ( F_21 ( & V_3 -> V_55 -> V_26 , V_90 , V_134 ) ) {
F_45 ( V_132
L_14 ,
V_3 -> V_128 , V_134 , V_121 , V_120 ) ;
V_116 = - V_38 ;
goto V_136;
}
V_122 ++ ;
if ( V_130 [ V_121 ] .
V_135 & 0x04000000 ) {
if ( F_5
( V_90 -> V_19 ,
( void T_2 * ) ( unsigned long ) V_130 [ V_121 ] .
V_137 , V_134 ) ) {
F_45 ( V_132
L_15 ,
V_3 -> V_128 , V_121 ) ;
V_116 = - V_9 ;
goto V_136;
}
}
V_130 [ V_121 ] . V_137 = ( T_4 ) V_90 -> V_69 ;
}
}
V_116 = F_31 ( V_3 , V_48 , 60 ) ;
V_48 = NULL ;
if ( V_116 ) {
V_112 [ 4 ] = ( ( T_4 ) V_116 ) << 24 ;
goto V_136;
}
if ( V_119 ) {
T_4 V_138 [ V_139 ] ;
T_4 V_140 ;
struct V_129 * V_130 ;
int V_134 ;
memset ( & V_138 , 0 , V_139 * 4 ) ;
if ( F_6 ( V_114 , & V_111 [ 0 ] ) ) {
V_116 = - V_9 ;
goto V_136;
}
V_114 = V_114 >> 16 ;
V_114 *= 4 ;
if ( F_5 ( V_138 , V_111 , V_114 ) ) {
V_116 = - V_9 ;
goto V_136;
}
V_120 =
( V_114 - V_119 * 4 ) / sizeof( struct V_129 ) ;
V_130 = (struct V_129 * ) ( V_138 + V_119 ) ;
for ( V_140 = 0 ; V_140 < V_120 ; V_140 ++ ) {
if ( !
( V_130 [ V_140 ] .
V_135 & 0x4000000 ) ) {
V_134 = V_130 [ V_140 ] . V_135 & 0xffffff ;
if ( F_3
( ( void T_2 * ) ( V_141 ) V_130 [ V_140 ] . V_137 ,
V_117 [ V_140 ] . V_19 , V_134 ) ) {
F_45 ( V_127
L_16 ,
V_3 -> V_128 , V_117 [ V_140 ] . V_19 ,
V_130 [ V_140 ] . V_137 ) ;
V_116 = - V_9 ;
goto V_136;
}
}
}
}
V_136:
if ( V_115 ) {
if ( F_5 ( V_112 + 2 , V_111 + 2 , sizeof( T_4 ) * 2 ) ) {
F_45 ( V_127
L_17 ,
V_3 -> V_128 ) ;
V_116 = - V_9 ;
}
if ( F_3 ( V_113 , V_112 , V_115 ) ) {
F_45 ( V_127
L_18 , V_3 -> V_128 ) ;
V_116 = - V_9 ;
}
}
for ( V_121 = 0 ; V_121 < V_122 ; V_121 ++ )
F_24 ( & V_3 -> V_55 -> V_26 , & V_117 [ V_121 ] ) ;
V_131:
F_16 ( V_112 ) ;
V_126:
if ( V_48 )
F_22 ( V_3 , V_48 ) ;
return V_116 ;
}
static long F_46 ( struct V_79 * V_79 , unsigned V_11 ,
unsigned long V_1 )
{
int V_7 ;
F_47 ( & V_142 ) ;
switch ( V_11 ) {
case V_143 :
V_7 = F_48 ( V_79 , V_11 , V_1 ) ;
break;
case V_144 :
V_7 = F_40 ( V_79 , V_11 , V_1 ) ;
break;
default:
V_7 = - V_145 ;
break;
}
F_49 ( & V_142 ) ;
return V_7 ;
}
static int F_50 ( unsigned long V_1 )
{
struct V_146 T_2 * V_11 =
(struct V_146 T_2 * ) V_1 ;
struct V_2 * V_3 ;
T_4 T_2 * V_111 ;
T_4 * V_112 = NULL ;
T_4 T_2 * V_113 = NULL ;
T_4 V_114 = 0 ;
T_4 V_115 = 0 ;
T_4 V_116 = 0 ;
struct V_45 V_117 [ V_118 ] ;
T_4 V_119 = 0 ;
T_4 V_120 = 0 ;
int V_122 = 0 ;
T_4 V_121 = 0 ;
T_6 * V_123 ;
struct V_47 * V_48 ;
unsigned int V_17 ;
if ( F_6 ( V_17 , & V_11 -> V_17 ) || F_6 ( V_111 , & V_11 -> V_48 ) )
return - V_9 ;
V_3 = F_7 ( V_17 ) ;
if ( ! V_3 ) {
F_42 ( L_7 , V_17 ) ;
return - V_18 ;
}
V_123 = V_3 -> V_124 . V_19 ;
if ( F_6 ( V_114 , & V_111 [ 0 ] ) )
return - V_9 ;
V_114 = V_114 >> 16 ;
if ( V_114 > V_123 -> V_125 ) {
F_42 ( L_9 ) ;
return - V_9 ;
}
V_113 = & V_111 [ V_114 ] ;
V_114 <<= 2 ;
V_48 = F_20 ( V_3 , V_54 ) ;
if ( F_13 ( V_48 ) )
return F_14 ( V_48 ) ;
V_116 = - V_9 ;
if ( F_5 ( V_48 , V_111 , V_114 ) )
goto V_126;
if ( F_6 ( V_115 , & V_113 [ 0 ] ) < 0 )
goto V_126;
V_115 >>= 16 ;
V_115 <<= 2 ;
V_112 = F_44 ( V_115 , V_37 ) ;
if ( ! V_112 ) {
F_45 ( V_127 L_11 ,
V_3 -> V_128 ) ;
V_116 = - V_38 ;
goto V_126;
}
V_119 = ( V_48 -> V_56 . V_57 [ 0 ] >> 4 ) & 0x0f ;
memset ( V_117 , 0 , sizeof( V_117 [ 0 ] ) * V_118 ) ;
if ( V_119 ) {
struct V_129 * V_130 ;
struct V_45 * V_90 ;
if ( V_119 * 4 >= V_114 ) {
V_116 = - V_9 ;
goto V_131;
}
V_130 = (struct V_129 * ) ( ( & V_48 -> V_56 . V_57 [ 0 ] ) +
V_119 ) ;
V_120 =
( V_114 - V_119 * 4 ) / sizeof( struct V_129 ) ;
if ( V_120 > V_118 ) {
F_45 ( V_132 L_12 ,
V_3 -> V_128 , V_120 ) ;
V_116 = - V_133 ;
goto V_131;
}
for ( V_121 = 0 ; V_121 < V_120 ; V_121 ++ ) {
int V_134 ;
if ( ! ( V_130 [ V_121 ] . V_135 & 0x10000000
) ) {
F_45 ( V_132
L_13 ,
V_3 -> V_128 , V_121 , V_130 [ V_121 ] . V_135 ) ;
V_116 = - V_133 ;
goto V_136;
}
V_134 = V_130 [ V_121 ] . V_135 & 0xffffff ;
V_90 = & ( V_117 [ V_122 ] ) ;
if ( F_21 ( & V_3 -> V_55 -> V_26 , V_90 , V_134 ) ) {
F_45 ( V_132
L_14 ,
V_3 -> V_128 , V_134 , V_121 , V_120 ) ;
V_116 = - V_38 ;
goto V_136;
}
V_122 ++ ;
if ( V_130 [ V_121 ] .
V_135 & 0x04000000 ) {
if ( F_5
( V_90 -> V_19 , ( void T_2 * ) V_130 [ V_121 ] . V_137 ,
V_134 ) ) {
F_45 ( V_132
L_15 ,
V_3 -> V_128 , V_121 ) ;
V_116 = - V_9 ;
goto V_136;
}
}
V_130 [ V_121 ] . V_137 = V_90 -> V_69 ;
}
}
V_116 = F_31 ( V_3 , V_48 , 60 ) ;
V_48 = NULL ;
if ( V_116 ) {
V_112 [ 4 ] = ( ( T_4 ) V_116 ) << 24 ;
goto V_136;
}
if ( V_119 ) {
T_4 V_138 [ V_139 ] ;
T_4 V_140 ;
struct V_129 * V_130 ;
int V_134 ;
memset ( & V_138 , 0 , V_139 * 4 ) ;
if ( F_6 ( V_114 , & V_111 [ 0 ] ) ) {
V_116 = - V_9 ;
goto V_136;
}
V_114 = V_114 >> 16 ;
V_114 *= 4 ;
if ( F_5 ( V_138 , V_111 , V_114 ) ) {
V_116 = - V_9 ;
goto V_136;
}
V_120 =
( V_114 - V_119 * 4 ) / sizeof( struct V_129 ) ;
V_130 = (struct V_129 * ) ( V_138 + V_119 ) ;
for ( V_140 = 0 ; V_140 < V_120 ; V_140 ++ ) {
if ( !
( V_130 [ V_140 ] .
V_135 & 0x4000000 ) ) {
V_134 = V_130 [ V_140 ] . V_135 & 0xffffff ;
if ( F_3
( ( void T_2 * ) V_130 [ V_140 ] . V_137 , V_117 [ V_140 ] . V_19 ,
V_134 ) ) {
F_45 ( V_127
L_16 ,
V_3 -> V_128 , V_117 [ V_140 ] . V_19 ,
V_130 [ V_140 ] . V_137 ) ;
V_116 = - V_9 ;
goto V_136;
}
}
}
}
V_136:
if ( V_115 ) {
if ( F_5 ( V_112 + 2 , V_111 + 2 , sizeof( T_4 ) * 2 ) ) {
F_45 ( V_127
L_17 ,
V_3 -> V_128 ) ;
V_116 = - V_9 ;
}
if ( F_3 ( V_113 , V_112 , V_115 ) ) {
F_45 ( V_127
L_18 , V_3 -> V_128 ) ;
V_116 = - V_9 ;
}
}
for ( V_121 = 0 ; V_121 < V_122 ; V_121 ++ )
F_24 ( & V_3 -> V_55 -> V_26 , & V_117 [ V_121 ] ) ;
V_131:
F_16 ( V_112 ) ;
V_126:
if ( V_48 )
F_22 ( V_3 , V_48 ) ;
return V_116 ;
}
static long F_48 ( struct V_79 * V_80 , unsigned int V_11 , unsigned long V_1 )
{
int V_7 ;
F_47 ( & V_142 ) ;
switch ( V_11 ) {
case V_143 :
V_7 = F_1 ( V_1 ) ;
break;
case V_147 :
V_7 = F_4 ( V_1 ) ;
break;
case V_148 :
V_7 = F_9 ( V_1 ) ;
break;
case V_149 :
V_7 = F_10 ( V_1 , V_149 ) ;
break;
case V_31 :
V_7 = F_10 ( V_1 , V_31 ) ;
break;
case V_150 :
V_7 = F_18 ( V_1 ) ;
break;
case V_151 :
V_7 = F_29 ( V_1 ) ;
break;
case V_152 :
V_7 = F_30 ( V_1 ) ;
break;
case V_153 :
V_7 = F_32 ( V_1 ) ;
break;
case V_154 :
V_7 = F_33 ( V_1 , V_80 ) ;
break;
case V_155 :
V_7 = F_36 ( V_1 , V_80 ) ;
break;
#ifdef F_51
case V_156 :
V_7 = F_50 ( V_1 ) ;
break;
#endif
default:
F_26 ( L_19 ) ;
V_7 = - V_133 ;
}
F_49 ( & V_142 ) ;
return V_7 ;
}
static int F_52 ( struct V_157 * V_157 , struct V_79 * V_79 )
{
struct V_89 * V_5 = F_15 ( sizeof( struct V_89 ) ,
V_37 ) ;
unsigned long V_66 ;
if ( ! V_5 )
return - V_38 ;
F_47 ( & V_142 ) ;
V_79 -> V_87 = ( void * ) ( V_158 ++ ) ;
V_5 -> V_80 = V_79 ;
V_5 -> V_159 = NULL ;
V_5 -> V_96 = ( V_97 ) V_79 -> V_87 ;
V_5 -> V_98 = 0 ;
V_5 -> V_160 = 0 ;
V_5 -> V_102 = 0 ;
V_5 -> V_108 = 0 ;
V_5 -> V_95 = V_94 ;
F_38 ( & V_105 , V_66 ) ;
V_94 = V_5 ;
F_39 ( & V_105 , V_66 ) ;
F_49 ( & V_142 ) ;
return 0 ;
}
static int F_53 ( int V_161 , struct V_79 * V_80 , int V_162 )
{
V_97 V_163 = ( V_97 ) V_80 -> V_87 ;
struct V_89 * V_90 ;
int V_7 = - V_164 ;
F_47 ( & V_142 ) ;
for ( V_90 = V_94 ; V_90 ; V_90 = V_90 -> V_95 )
if ( V_90 -> V_96 == V_163 )
break;
if ( V_90 )
V_7 = F_54 ( V_161 , V_80 , V_162 , & V_90 -> V_159 ) ;
F_49 ( & V_142 ) ;
return V_7 ;
}
static int F_55 ( struct V_157 * V_157 , struct V_79 * V_79 )
{
V_97 V_163 = ( V_97 ) V_79 -> V_87 ;
struct V_89 * V_90 , * * V_165 ;
unsigned long V_66 ;
F_47 ( & V_142 ) ;
F_38 ( & V_105 , V_66 ) ;
for ( V_165 = & V_94 ; ( V_90 = * V_165 ) != NULL ; V_165 = & V_90 -> V_95 ) {
if ( V_90 -> V_96 == V_163 ) {
* V_165 = V_90 -> V_95 ;
F_16 ( V_90 ) ;
break;
}
}
F_39 ( & V_105 , V_66 ) ;
F_49 ( & V_142 ) ;
return 0 ;
}
static int T_7 F_56 ( void )
{
F_57 ( & V_105 ) ;
if ( F_58 ( & V_166 ) < 0 ) {
F_59 ( L_20 ) ;
return - V_167 ;
}
return 0 ;
}
static void F_60 ( void )
{
F_61 ( & V_166 ) ;
}
