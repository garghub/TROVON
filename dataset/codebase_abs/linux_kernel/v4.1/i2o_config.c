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
if ( V_12 . V_35 > 65536 )
return - V_36 ;
V_28 = F_12 ( V_12 . V_37 , V_12 . V_35 ) ;
if ( F_13 ( V_28 ) )
return F_14 ( V_28 ) ;
V_29 = F_15 ( 65536 , V_38 ) ;
if ( ! V_29 ) {
F_16 ( V_28 ) ;
return - V_39 ;
}
V_14 = F_17 ( V_26 , V_30 , V_28 , V_12 . V_35 , V_29 , 65536 ) ;
F_16 ( V_28 ) ;
if ( V_14 < 0 ) {
F_16 ( V_29 ) ;
return - V_40 ;
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
struct V_41 V_42 ;
struct V_41 T_2 * V_43 = (struct V_41 T_2 * ) V_1 ;
unsigned char V_44 = 0 , V_45 = 1 ;
struct V_46 V_47 ;
struct V_48 * V_49 ;
unsigned int V_50 = 0 , V_51 = 0 , V_52 = 8192 ;
struct V_2 * V_3 ;
if ( F_5 ( & V_42 , V_43 , sizeof( struct V_41 ) ) )
return - V_9 ;
if ( F_6 ( V_51 , V_42 . V_51 ) < 0 )
return - V_9 ;
if ( F_6 ( V_44 , V_42 . V_44 ) < 0 )
return - V_9 ;
if ( F_6 ( V_45 , V_42 . V_45 ) < 0 )
return - V_9 ;
if ( V_45 == V_44 )
V_52 = V_51 - ( V_44 - 1 ) * 8192 ;
if ( ! V_42 . V_53 || ! F_19 ( V_54 , V_42 . V_53 , V_52 ) )
return - V_9 ;
V_3 = F_7 ( V_42 . V_17 ) ;
if ( ! V_3 )
return - V_18 ;
V_49 = F_20 ( V_3 , V_55 ) ;
if ( F_13 ( V_49 ) )
return F_14 ( V_49 ) ;
if ( F_21 ( & V_3 -> V_56 -> V_26 , & V_47 , V_52 ) ) {
F_22 ( V_3 , V_49 ) ;
return - V_39 ;
}
if ( F_23 ( V_47 . V_19 , V_42 . V_53 , V_52 ) ) {
F_22 ( V_3 , V_49 ) ;
F_24 ( & V_3 -> V_56 -> V_26 , & V_47 ) ;
return - V_9 ;
}
V_49 -> V_57 . V_58 [ 0 ] = F_25 ( V_59 | V_60 ) ;
V_49 -> V_57 . V_58 [ 1 ] =
F_25 ( V_61 << 24 | V_62 << 12 |
V_63 ) ;
V_49 -> V_57 . V_58 [ 2 ] = F_25 ( V_64 . V_65 ) ;
V_49 -> V_57 . V_58 [ 3 ] = F_25 ( 0 ) ;
V_49 -> V_66 [ 0 ] =
F_25 ( ( ( ( T_4 ) V_42 . V_67 ) << 24 ) | ( ( ( T_4 ) V_42 .
V_68 ) << 16 ) |
( ( ( T_4 ) V_44 ) << 8 ) | ( ( ( T_4 ) V_45 ) ) ) ;
V_49 -> V_66 [ 1 ] = F_25 ( V_51 ) ;
V_49 -> V_66 [ 2 ] = F_25 ( V_42 . V_69 ) ;
V_49 -> V_66 [ 3 ] = F_25 ( 0xD0000000 | V_52 ) ;
V_49 -> V_66 [ 4 ] = F_25 ( V_47 . V_70 ) ;
F_26 ( L_1 , V_45 , V_44 , V_52 ) ;
V_50 = F_27 ( V_3 , V_49 , 60 , & V_47 ) ;
if ( V_50 != - V_71 )
F_24 ( & V_3 -> V_56 -> V_26 , & V_47 ) ;
if ( V_50 != V_72 ) {
F_28 ( L_2 , V_50 ) ;
return V_50 ;
}
return 0 ;
}
static int F_29 ( unsigned long V_1 )
{
struct V_41 V_42 ;
struct V_41 T_2 * V_43 = (struct V_41 T_2 * ) V_1 ;
unsigned char V_44 = 0 , V_45 = 1 ;
struct V_46 V_47 ;
struct V_48 * V_49 ;
unsigned int V_50 = 0 , V_51 = 0 , V_52 = 8192 ;
struct V_2 * V_3 ;
int V_7 = 0 ;
if ( F_5 ( & V_42 , V_43 , sizeof( struct V_41 ) ) )
return - V_9 ;
if ( F_6 ( V_51 , V_42 . V_51 ) < 0 )
return - V_9 ;
if ( F_6 ( V_44 , V_42 . V_44 ) < 0 )
return - V_9 ;
if ( F_6 ( V_45 , V_42 . V_45 ) < 0 )
return - V_9 ;
if ( V_45 == V_44 )
V_52 = V_51 - ( V_44 - 1 ) * 8192 ;
if ( ! V_42 . V_53 )
return - V_9 ;
V_3 = F_7 ( V_42 . V_17 ) ;
if ( ! V_3 )
return - V_18 ;
V_49 = F_20 ( V_3 , V_55 ) ;
if ( F_13 ( V_49 ) )
return F_14 ( V_49 ) ;
if ( F_21 ( & V_3 -> V_56 -> V_26 , & V_47 , V_52 ) ) {
F_22 ( V_3 , V_49 ) ;
return - V_39 ;
}
V_49 -> V_57 . V_58 [ 0 ] = F_25 ( V_59 | V_60 ) ;
V_49 -> V_57 . V_58 [ 1 ] =
F_25 ( V_73 << 24 | V_62 << 12 | V_63 ) ;
V_49 -> V_57 . V_58 [ 2 ] = F_25 ( V_64 . V_65 ) ;
V_49 -> V_57 . V_58 [ 3 ] = F_25 ( 0 ) ;
V_49 -> V_66 [ 0 ] =
F_25 ( ( T_4 ) V_42 . V_67 << 24 | ( T_4 ) V_42 .
V_68 << 16 | ( T_4 ) V_44 << 8 | ( T_4 ) V_45 ) ;
V_49 -> V_66 [ 1 ] = F_25 ( V_51 ) ;
V_49 -> V_66 [ 2 ] = F_25 ( V_42 . V_69 ) ;
V_49 -> V_66 [ 3 ] = F_25 ( 0xD0000000 | V_52 ) ;
V_49 -> V_66 [ 4 ] = F_25 ( V_47 . V_70 ) ;
F_26 ( L_3 , V_45 , V_44 , V_52 ) ;
V_50 = F_27 ( V_3 , V_49 , 60 , & V_47 ) ;
if ( V_50 != V_72 ) {
if ( V_50 != - V_71 )
F_24 ( & V_3 -> V_56 -> V_26 , & V_47 ) ;
F_28 ( L_4 , V_50 ) ;
return V_50 ;
}
if ( F_3 ( V_42 . V_53 , V_47 . V_19 , V_52 ) )
V_7 = - V_9 ;
F_24 ( & V_3 -> V_56 -> V_26 , & V_47 ) ;
return V_7 ;
}
static int F_30 ( unsigned long V_1 )
{
struct V_2 * V_3 ;
struct V_41 V_42 ;
struct V_41 T_2 * V_43 = (struct V_41 T_2 * ) V_1 ;
struct V_48 * V_49 ;
unsigned int V_51 ;
int V_74 ;
if ( F_5 ( & V_42 , V_43 , sizeof( struct V_41 ) ) )
return - V_9 ;
if ( F_6 ( V_51 , V_42 . V_51 ) < 0 )
return - V_9 ;
V_3 = F_7 ( V_42 . V_17 ) ;
if ( ! V_3 )
return - V_18 ;
V_49 = F_20 ( V_3 , V_55 ) ;
if ( F_13 ( V_49 ) )
return F_14 ( V_49 ) ;
V_49 -> V_57 . V_58 [ 0 ] = F_25 ( V_75 | V_76 ) ;
V_49 -> V_57 . V_58 [ 1 ] =
F_25 ( V_77 << 24 | V_62 << 12 | V_63 ) ;
V_49 -> V_57 . V_58 [ 2 ] = F_25 ( V_64 . V_65 ) ;
V_49 -> V_57 . V_58 [ 3 ] = F_25 ( 0 ) ;
V_49 -> V_66 [ 0 ] =
F_25 ( ( T_4 ) V_42 . V_67 << 24 | ( T_4 ) V_42 . V_68 << 16 ) ;
V_49 -> V_66 [ 1 ] = F_25 ( V_51 ) ;
V_49 -> V_66 [ 2 ] = F_25 ( V_42 . V_69 ) ;
V_74 = F_31 ( V_3 , V_49 , 10 ) ;
if ( V_74 != V_72 ) {
F_28 ( L_5 , V_74 ) ;
return - V_71 ;
}
return 0 ;
}
static int F_32 ( unsigned long V_1 )
{
int V_74 ;
int V_17 = ( int ) V_1 ;
struct V_48 * V_49 ;
struct V_2 * V_3 ;
V_3 = F_7 ( V_17 ) ;
if ( ! V_3 )
return - V_18 ;
V_49 = F_20 ( V_3 , V_55 ) ;
if ( F_13 ( V_49 ) )
return F_14 ( V_49 ) ;
V_49 -> V_57 . V_58 [ 0 ] = F_25 ( V_78 | V_76 ) ;
V_49 -> V_57 . V_58 [ 1 ] =
F_25 ( V_79 << 24 | V_62 << 12 | V_17 ) ;
V_49 -> V_57 . V_58 [ 2 ] = F_25 ( V_64 . V_65 ) ;
V_49 -> V_57 . V_58 [ 3 ] = F_25 ( 0 ) ;
V_74 = F_31 ( V_3 , V_49 , 10 ) ;
if ( V_74 != V_72 ) {
F_28 ( L_6 ,
V_74 ) ;
return - V_71 ;
}
return 0 ;
}
static int F_33 ( unsigned long V_1 , struct V_80 * V_81 )
{
struct V_48 * V_49 ;
struct V_82 T_2 * V_83 = (struct V_82 T_2 * ) V_1 ;
struct V_82 V_84 ;
struct V_2 * V_3 ;
struct V_25 * V_85 ;
if ( F_5 ( & V_84 , V_83 , sizeof( struct V_82 ) ) )
return - V_9 ;
V_3 = F_7 ( V_84 . V_17 ) ;
if ( ! V_3 )
return - V_18 ;
V_85 = F_11 ( V_3 , V_84 . V_34 ) ;
if ( ! V_85 )
return - V_86 ;
V_49 = F_20 ( V_3 , V_55 ) ;
if ( F_13 ( V_49 ) )
return F_14 ( V_49 ) ;
V_49 -> V_57 . V_58 [ 0 ] = F_25 ( V_78 | V_76 ) ;
V_49 -> V_57 . V_58 [ 1 ] =
F_25 ( V_87 << 24 | V_62 << 12 |
V_84 . V_34 ) ;
V_49 -> V_57 . V_58 [ 2 ] = F_25 ( V_64 . V_65 ) ;
V_49 -> V_57 . V_58 [ 3 ] = F_25 ( F_34 ( V_3 , V_81 -> V_88 ) ) ;
V_49 -> V_66 [ 0 ] = F_25 ( V_84 . V_89 ) ;
F_35 ( V_3 , V_49 ) ;
return 0 ;
}
static int F_36 ( unsigned long V_1 , struct V_80 * V_81 )
{
struct V_90 * V_91 = NULL ;
struct V_92 T_2 * V_93 = (struct V_92 T_2 * ) V_1 ;
struct V_92 V_94 ;
unsigned long V_67 ;
for ( V_91 = V_95 ; V_91 ; V_91 = V_91 -> V_96 )
if ( V_91 -> V_97 == ( V_98 ) V_81 -> V_88 )
break;
if ( ! V_91 -> V_99 )
return - V_100 ;
memcpy ( & V_94 . V_101 , & V_91 -> V_102 [ V_91 -> V_103 ] , sizeof( struct V_104 ) ) ;
F_37 ( V_91 -> V_103 , V_105 ) ;
F_38 ( & V_106 , V_67 ) ;
V_91 -> V_99 -- ;
V_94 . V_107 = V_91 -> V_99 ;
V_94 . V_108 = V_91 -> V_109 ;
F_39 ( & V_106 , V_67 ) ;
if ( F_3 ( V_93 , & V_94 , sizeof( struct V_92 ) ) )
return - V_9 ;
return 0 ;
}
static int F_40 ( struct V_80 * V_80 , unsigned V_110 ,
unsigned long V_1 )
{
struct V_111 T_2 * V_11 ;
struct V_2 * V_3 ;
T_4 T_2 * V_112 ;
T_4 * V_113 = NULL ;
T_4 T_2 * V_114 = NULL ;
T_4 V_115 = 0 ;
T_4 V_116 = 0 ;
T_4 V_117 = 0 ;
struct V_46 V_118 [ V_119 ] ;
T_4 V_120 = 0 ;
T_4 V_121 = 0 ;
T_4 V_122 = 0 ;
T_4 V_123 = 0 ;
T_6 * V_124 ;
struct V_48 * V_49 ;
unsigned int V_17 ;
V_11 = (struct V_111 T_2 * ) V_1 ;
if ( F_6 ( V_17 , & V_11 -> V_17 ) || F_6 ( V_122 , & V_11 -> V_49 ) )
return - V_9 ;
V_112 = F_41 ( V_122 ) ;
V_3 = F_7 ( V_17 ) ;
if ( ! V_3 ) {
F_26 ( L_7 , V_17 ) ;
return - V_18 ;
}
V_124 = V_3 -> V_125 . V_19 ;
if ( F_6 ( V_115 , & V_112 [ 0 ] ) ) {
F_42 ( L_8 ) ;
return - V_9 ;
}
V_115 = V_115 >> 16 ;
if ( V_115 > V_124 -> V_126 ) {
F_42 ( L_9 ) ;
return - V_9 ;
}
V_114 = & V_112 [ V_115 ] ;
V_115 <<= 2 ;
V_49 = F_20 ( V_3 , V_55 ) ;
if ( F_13 ( V_49 ) )
return F_14 ( V_49 ) ;
V_117 = - V_9 ;
if ( F_5 ( V_49 , V_112 , V_115 ) ) {
F_42 ( L_10 ) ;
goto V_127;
}
F_43 ( V_49 ) ;
if ( F_6 ( V_116 , & V_114 [ 0 ] ) < 0 )
goto V_127;
V_116 >>= 16 ;
V_116 <<= 2 ;
V_117 = - V_39 ;
V_113 = F_44 ( V_116 , V_38 ) ;
if ( ! V_113 ) {
F_45 ( V_128 L_11 ,
V_3 -> V_129 ) ;
goto V_127;
}
V_120 = ( V_49 -> V_57 . V_58 [ 0 ] >> 4 ) & 0x0f ;
memset ( V_118 , 0 , sizeof( V_118 [ 0 ] ) * V_119 ) ;
if ( V_120 ) {
struct V_130 * V_131 ;
if ( V_120 * 4 >= V_115 ) {
V_117 = - V_9 ;
goto V_132;
}
V_131 = (struct V_130 * ) ( ( & V_49 -> V_57 . V_58 [ 0 ] ) +
V_120 ) ;
V_121 =
( V_115 - V_120 * 4 ) / sizeof( struct V_130 ) ;
if ( V_121 > V_119 ) {
F_45 ( V_133 L_12 ,
V_3 -> V_129 , V_121 ) ;
V_117 = - V_134 ;
goto V_132;
}
for ( V_122 = 0 ; V_122 < V_121 ; V_122 ++ ) {
int V_135 ;
struct V_46 * V_91 ;
if ( ! ( V_131 [ V_122 ] . V_136 & 0x10000000
) ) {
F_45 ( V_133
L_13 ,
V_3 -> V_129 , V_122 , V_131 [ V_122 ] . V_136 ) ;
V_117 = - V_134 ;
goto V_132;
}
V_135 = V_131 [ V_122 ] . V_136 & 0xffffff ;
V_91 = & ( V_118 [ V_123 ] ) ;
if ( F_21 ( & V_3 -> V_56 -> V_26 , V_91 , V_135 ) ) {
F_45 ( V_133
L_14 ,
V_3 -> V_129 , V_135 , V_122 , V_121 ) ;
V_117 = - V_39 ;
goto V_137;
}
V_123 ++ ;
if ( V_131 [ V_122 ] .
V_136 & 0x04000000 ) {
if ( F_5
( V_91 -> V_19 ,
( void T_2 * ) ( unsigned long ) V_131 [ V_122 ] .
V_138 , V_135 ) ) {
F_45 ( V_133
L_15 ,
V_3 -> V_129 , V_122 ) ;
V_117 = - V_9 ;
goto V_137;
}
}
V_131 [ V_122 ] . V_138 = ( T_4 ) V_91 -> V_70 ;
}
}
V_117 = F_31 ( V_3 , V_49 , 60 ) ;
V_49 = NULL ;
if ( V_117 ) {
V_113 [ 4 ] = ( ( T_4 ) V_117 ) << 24 ;
goto V_137;
}
if ( V_120 ) {
T_4 V_139 [ V_140 ] ;
T_4 V_141 ;
struct V_130 * V_131 ;
int V_135 ;
memset ( & V_139 , 0 , V_140 * 4 ) ;
if ( F_6 ( V_115 , & V_112 [ 0 ] ) ) {
V_117 = - V_9 ;
goto V_137;
}
V_115 = V_115 >> 16 ;
V_115 *= 4 ;
if ( V_115 > sizeof( V_139 ) ) {
V_117 = - V_134 ;
goto V_137;
}
if ( F_5 ( V_139 , V_112 , V_115 ) ) {
V_117 = - V_9 ;
goto V_137;
}
V_121 =
( V_115 - V_120 * 4 ) / sizeof( struct V_130 ) ;
V_131 = (struct V_130 * ) ( V_139 + V_120 ) ;
for ( V_141 = 0 ; V_141 < V_121 ; V_141 ++ ) {
if ( !
( V_131 [ V_141 ] .
V_136 & 0x4000000 ) ) {
V_135 = V_131 [ V_141 ] . V_136 & 0xffffff ;
if ( F_3
( ( void T_2 * ) ( V_142 ) V_131 [ V_141 ] . V_138 ,
V_118 [ V_141 ] . V_19 , V_135 ) ) {
F_45 ( V_128
L_16 ,
V_3 -> V_129 , V_118 [ V_141 ] . V_19 ,
V_131 [ V_141 ] . V_138 ) ;
V_117 = - V_9 ;
goto V_137;
}
}
}
}
V_137:
if ( V_116 ) {
if ( F_5 ( V_113 + 2 , V_112 + 2 , sizeof( T_4 ) * 2 ) ) {
F_45 ( V_128
L_17 ,
V_3 -> V_129 ) ;
V_117 = - V_9 ;
}
if ( F_3 ( V_114 , V_113 , V_116 ) ) {
F_45 ( V_128
L_18 , V_3 -> V_129 ) ;
V_117 = - V_9 ;
}
}
for ( V_122 = 0 ; V_122 < V_123 ; V_122 ++ )
F_24 ( & V_3 -> V_56 -> V_26 , & V_118 [ V_122 ] ) ;
V_132:
F_16 ( V_113 ) ;
V_127:
if ( V_49 )
F_22 ( V_3 , V_49 ) ;
return V_117 ;
}
static long F_46 ( struct V_80 * V_80 , unsigned V_11 ,
unsigned long V_1 )
{
int V_7 ;
switch ( V_11 ) {
case V_143 :
V_7 = F_47 ( V_80 , V_11 , V_1 ) ;
break;
case V_144 :
F_48 ( & V_145 ) ;
V_7 = F_40 ( V_80 , V_11 , V_1 ) ;
F_49 ( & V_145 ) ;
break;
default:
V_7 = - V_146 ;
break;
}
return V_7 ;
}
static int F_50 ( unsigned long V_1 )
{
struct V_147 T_2 * V_11 =
(struct V_147 T_2 * ) V_1 ;
struct V_2 * V_3 ;
T_4 T_2 * V_112 ;
T_4 * V_113 = NULL ;
T_4 T_2 * V_114 = NULL ;
T_4 V_115 = 0 ;
T_4 V_116 = 0 ;
T_4 V_117 = 0 ;
struct V_46 V_118 [ V_119 ] ;
T_4 V_120 = 0 ;
T_4 V_121 = 0 ;
int V_123 = 0 ;
T_4 V_122 = 0 ;
T_6 * V_124 ;
struct V_48 * V_49 ;
unsigned int V_17 ;
if ( F_6 ( V_17 , & V_11 -> V_17 ) || F_6 ( V_112 , & V_11 -> V_49 ) )
return - V_9 ;
V_3 = F_7 ( V_17 ) ;
if ( ! V_3 ) {
F_42 ( L_7 , V_17 ) ;
return - V_18 ;
}
V_124 = V_3 -> V_125 . V_19 ;
if ( F_6 ( V_115 , & V_112 [ 0 ] ) )
return - V_9 ;
V_115 = V_115 >> 16 ;
if ( V_115 > V_124 -> V_126 ) {
F_42 ( L_9 ) ;
return - V_9 ;
}
V_114 = & V_112 [ V_115 ] ;
V_115 <<= 2 ;
V_49 = F_20 ( V_3 , V_55 ) ;
if ( F_13 ( V_49 ) )
return F_14 ( V_49 ) ;
V_117 = - V_9 ;
if ( F_5 ( V_49 , V_112 , V_115 ) )
goto V_127;
if ( F_6 ( V_116 , & V_114 [ 0 ] ) < 0 )
goto V_127;
V_116 >>= 16 ;
V_116 <<= 2 ;
V_113 = F_44 ( V_116 , V_38 ) ;
if ( ! V_113 ) {
F_45 ( V_128 L_11 ,
V_3 -> V_129 ) ;
V_117 = - V_39 ;
goto V_127;
}
V_120 = ( V_49 -> V_57 . V_58 [ 0 ] >> 4 ) & 0x0f ;
memset ( V_118 , 0 , sizeof( V_118 [ 0 ] ) * V_119 ) ;
if ( V_120 ) {
struct V_130 * V_131 ;
struct V_46 * V_91 ;
if ( V_120 * 4 >= V_115 ) {
V_117 = - V_9 ;
goto V_132;
}
V_131 = (struct V_130 * ) ( ( & V_49 -> V_57 . V_58 [ 0 ] ) +
V_120 ) ;
V_121 =
( V_115 - V_120 * 4 ) / sizeof( struct V_130 ) ;
if ( V_121 > V_119 ) {
F_45 ( V_133 L_12 ,
V_3 -> V_129 , V_121 ) ;
V_117 = - V_134 ;
goto V_132;
}
for ( V_122 = 0 ; V_122 < V_121 ; V_122 ++ ) {
int V_135 ;
if ( ! ( V_131 [ V_122 ] . V_136 & 0x10000000
) ) {
F_45 ( V_133
L_13 ,
V_3 -> V_129 , V_122 , V_131 [ V_122 ] . V_136 ) ;
V_117 = - V_134 ;
goto V_137;
}
V_135 = V_131 [ V_122 ] . V_136 & 0xffffff ;
V_91 = & ( V_118 [ V_123 ] ) ;
if ( F_21 ( & V_3 -> V_56 -> V_26 , V_91 , V_135 ) ) {
F_45 ( V_133
L_14 ,
V_3 -> V_129 , V_135 , V_122 , V_121 ) ;
V_117 = - V_39 ;
goto V_137;
}
V_123 ++ ;
if ( V_131 [ V_122 ] .
V_136 & 0x04000000 ) {
if ( F_5
( V_91 -> V_19 , ( void T_2 * ) V_131 [ V_122 ] . V_138 ,
V_135 ) ) {
F_45 ( V_133
L_15 ,
V_3 -> V_129 , V_122 ) ;
V_117 = - V_9 ;
goto V_137;
}
}
V_131 [ V_122 ] . V_138 = V_91 -> V_70 ;
}
}
V_117 = F_31 ( V_3 , V_49 , 60 ) ;
V_49 = NULL ;
if ( V_117 ) {
V_113 [ 4 ] = ( ( T_4 ) V_117 ) << 24 ;
goto V_137;
}
if ( V_120 ) {
T_4 V_139 [ V_140 ] ;
T_4 V_141 ;
struct V_130 * V_131 ;
int V_135 ;
memset ( & V_139 , 0 , V_140 * 4 ) ;
if ( F_6 ( V_115 , & V_112 [ 0 ] ) ) {
V_117 = - V_9 ;
goto V_137;
}
V_115 = V_115 >> 16 ;
V_115 *= 4 ;
if ( V_115 > sizeof( V_139 ) ) {
V_117 = - V_9 ;
goto V_137;
}
if ( F_5 ( V_139 , V_112 , V_115 ) ) {
V_117 = - V_9 ;
goto V_137;
}
V_121 =
( V_115 - V_120 * 4 ) / sizeof( struct V_130 ) ;
V_131 = (struct V_130 * ) ( V_139 + V_120 ) ;
for ( V_141 = 0 ; V_141 < V_121 ; V_141 ++ ) {
if ( !
( V_131 [ V_141 ] .
V_136 & 0x4000000 ) ) {
V_135 = V_131 [ V_141 ] . V_136 & 0xffffff ;
if ( F_3
( ( void T_2 * ) V_131 [ V_141 ] . V_138 , V_118 [ V_141 ] . V_19 ,
V_135 ) ) {
F_45 ( V_128
L_16 ,
V_3 -> V_129 , V_118 [ V_141 ] . V_19 ,
V_131 [ V_141 ] . V_138 ) ;
V_117 = - V_9 ;
goto V_137;
}
}
}
}
V_137:
if ( V_116 ) {
if ( F_5 ( V_113 + 2 , V_112 + 2 , sizeof( T_4 ) * 2 ) ) {
F_45 ( V_128
L_17 ,
V_3 -> V_129 ) ;
V_117 = - V_9 ;
}
if ( F_3 ( V_114 , V_113 , V_116 ) ) {
F_45 ( V_128
L_18 , V_3 -> V_129 ) ;
V_117 = - V_9 ;
}
}
for ( V_122 = 0 ; V_122 < V_123 ; V_122 ++ )
F_24 ( & V_3 -> V_56 -> V_26 , & V_118 [ V_122 ] ) ;
V_132:
F_16 ( V_113 ) ;
V_127:
if ( V_49 )
F_22 ( V_3 , V_49 ) ;
return V_117 ;
}
static long F_47 ( struct V_80 * V_81 , unsigned int V_11 , unsigned long V_1 )
{
int V_7 ;
F_48 ( & V_145 ) ;
switch ( V_11 ) {
case V_143 :
V_7 = F_1 ( V_1 ) ;
break;
case V_148 :
V_7 = F_4 ( V_1 ) ;
break;
case V_149 :
V_7 = F_9 ( V_1 ) ;
break;
case V_150 :
V_7 = F_10 ( V_1 , V_150 ) ;
break;
case V_31 :
V_7 = F_10 ( V_1 , V_31 ) ;
break;
case V_151 :
V_7 = F_18 ( V_1 ) ;
break;
case V_152 :
V_7 = F_29 ( V_1 ) ;
break;
case V_153 :
V_7 = F_30 ( V_1 ) ;
break;
case V_154 :
V_7 = F_32 ( V_1 ) ;
break;
case V_155 :
V_7 = F_33 ( V_1 , V_81 ) ;
break;
case V_156 :
V_7 = F_36 ( V_1 , V_81 ) ;
break;
#ifdef F_51
case V_157 :
V_7 = F_50 ( V_1 ) ;
break;
#endif
default:
F_26 ( L_19 ) ;
V_7 = - V_134 ;
}
F_49 ( & V_145 ) ;
return V_7 ;
}
static int F_52 ( struct V_158 * V_158 , struct V_80 * V_80 )
{
struct V_90 * V_5 = F_15 ( sizeof( struct V_90 ) ,
V_38 ) ;
unsigned long V_67 ;
if ( ! V_5 )
return - V_39 ;
F_48 ( & V_145 ) ;
V_80 -> V_88 = ( void * ) ( V_159 ++ ) ;
V_5 -> V_81 = V_80 ;
V_5 -> V_160 = NULL ;
V_5 -> V_97 = ( V_98 ) V_80 -> V_88 ;
V_5 -> V_99 = 0 ;
V_5 -> V_161 = 0 ;
V_5 -> V_103 = 0 ;
V_5 -> V_109 = 0 ;
V_5 -> V_96 = V_95 ;
F_38 ( & V_106 , V_67 ) ;
V_95 = V_5 ;
F_39 ( & V_106 , V_67 ) ;
F_49 ( & V_145 ) ;
return 0 ;
}
static int F_53 ( int V_162 , struct V_80 * V_81 , int V_163 )
{
V_98 V_164 = ( V_98 ) V_81 -> V_88 ;
struct V_90 * V_91 ;
int V_7 = - V_165 ;
F_48 ( & V_145 ) ;
for ( V_91 = V_95 ; V_91 ; V_91 = V_91 -> V_96 )
if ( V_91 -> V_97 == V_164 )
break;
if ( V_91 )
V_7 = F_54 ( V_162 , V_81 , V_163 , & V_91 -> V_160 ) ;
F_49 ( & V_145 ) ;
return V_7 ;
}
static int F_55 ( struct V_158 * V_158 , struct V_80 * V_80 )
{
V_98 V_164 = ( V_98 ) V_80 -> V_88 ;
struct V_90 * V_91 , * * V_166 ;
unsigned long V_67 ;
F_48 ( & V_145 ) ;
F_38 ( & V_106 , V_67 ) ;
for ( V_166 = & V_95 ; ( V_91 = * V_166 ) != NULL ; V_166 = & V_91 -> V_96 ) {
if ( V_91 -> V_97 == V_164 ) {
* V_166 = V_91 -> V_96 ;
F_16 ( V_91 ) ;
break;
}
}
F_39 ( & V_106 , V_67 ) ;
F_49 ( & V_145 ) ;
return 0 ;
}
static int T_7 F_56 ( void )
{
F_57 ( & V_106 ) ;
if ( F_58 ( & V_167 ) < 0 ) {
F_59 ( L_20 ) ;
return - V_168 ;
}
return 0 ;
}
static void F_60 ( void )
{
F_61 ( & V_167 ) ;
}
