static int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 , unsigned long V_4 )
{
V_2 -> V_5 . V_6 = V_3 & 0xffffffffUL ;
V_2 -> V_5 . V_7 = V_4 & 0xffffffffUL ;
V_2 -> V_8 = V_3 >> 32 ;
V_2 -> V_9 = V_4 >> 32 ;
return 0 ;
}
static int F_2 ( struct V_10 * V_11 , struct V_1 * V_2 ,
unsigned long V_12 ,
unsigned long V_13 , char * V_14 ,
unsigned long V_15 )
{
char * V_16 = ( ( char * ) V_2 ) + V_13 ;
unsigned long V_17 , V_18 = 0 ;
T_1 V_19 , V_20 ;
if ( V_11 -> type == V_21 ) {
V_18 = sprintf ( V_16 ,
L_1 , V_11 -> V_22 . V_23 ) ;
}
memcpy ( V_16 + V_18 , V_14 , V_15 ) ;
V_15 += V_18 ;
V_16 [ V_15 - 1 ] = '\0' ;
F_3 ( L_2 , V_16 ) ;
V_17 = V_12 + V_13 ;
V_19 = V_17 & 0xffffffffUL ;
V_20 = V_17 >> 32 ;
V_2 -> V_5 . V_24 = V_19 ;
if ( V_20 )
V_2 -> V_25 = V_20 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 )
{
unsigned int V_26 ;
V_26 = V_27 . V_28 ;
if ( V_26 > V_29 )
V_26 = V_29 ;
V_2 -> V_30 = V_26 ;
memcpy ( & V_2 -> V_31 , & V_27 . V_32 ,
V_26 * sizeof( struct V_33 ) ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
unsigned long V_34 ,
unsigned int V_35 ,
unsigned int V_36 )
{
void * V_37 = ( void * ) V_2 + V_35 ;
unsigned long V_38 = V_34 + V_35 ;
struct V_39 * V_40 = & V_2 -> V_39 ;
if ( ! V_36 )
return 0 ;
F_6 ( V_37 , V_36 ) ;
V_40 -> V_41 = V_38 & 0xffffffff ;
V_40 -> V_42 = V_38 >> 32 ;
V_40 -> V_43 = V_36 ;
return 0 ;
}
static int
F_7 ( struct V_1 * V_2 ,
unsigned long V_34 ,
unsigned int V_44 )
{
unsigned long V_45 ;
struct V_46 * V_47 = ( void * ) V_2 + V_44 ;
struct V_48 * V_49 = ( void * ) V_47 + sizeof( struct V_46 ) ;
V_49 -> V_50 = V_51 . V_50 ;
V_49 -> V_52 = V_51 . V_52 ;
V_49 -> V_53 = V_51 . V_54 ;
V_49 -> V_55 = V_51 . V_55 ;
V_47 -> type = V_56 ;
V_47 -> V_18 = sizeof( struct V_48 ) ;
V_45 = V_34 + V_44 ;
V_47 -> V_57 = V_2 -> V_5 . V_46 ;
V_2 -> V_5 . V_46 = V_45 ;
return 0 ;
}
static int
F_8 ( struct V_1 * V_2 , unsigned long V_34 ,
unsigned int V_35 , unsigned int V_36 ,
unsigned int V_44 )
{
struct V_39 * V_58 = & V_1 . V_39 ;
struct V_39 * V_40 = & V_2 -> V_39 ;
if ( ! V_58 -> V_43 )
return 0 ;
if ( F_9 ( V_59 ) )
return 0 ;
V_40 -> V_60 = V_58 -> V_60 ;
V_40 -> V_61 = V_58 -> V_61 ;
V_40 -> V_62 = V_58 -> V_62 ;
V_40 -> V_63 = V_58 -> V_63 ;
V_40 -> V_64 = F_10 () ;
F_5 ( V_2 , V_34 , V_35 ,
V_36 ) ;
F_7 ( V_2 , V_34 ,
V_44 ) ;
return 0 ;
}
static int
F_11 ( struct V_10 * V_11 , struct V_1 * V_2 ,
unsigned long V_34 ,
unsigned int V_35 , unsigned int V_36 ,
unsigned int V_44 )
{
unsigned int V_26 ;
unsigned long long V_65 , V_66 , V_67 ;
int V_68 , V_69 = 0 ;
V_2 -> V_5 . V_70 = V_1 . V_5 . V_70 ;
memcpy ( & V_2 -> V_71 , & V_1 . V_71 ,
sizeof( struct V_71 ) ) ;
V_2 -> V_71 . V_72 = 0 ;
V_2 -> V_73 = 0 ;
memset ( & V_2 -> V_74 , 0 , sizeof( V_2 -> V_74 ) ) ;
memset ( & V_2 -> V_75 , 0 , sizeof( V_2 -> V_75 ) ) ;
memset ( & V_2 -> V_76 , 0 , sizeof( V_2 -> V_76 ) ) ;
if ( V_11 -> type == V_21 ) {
V_69 = F_12 ( V_11 , V_2 ) ;
if ( V_69 )
return V_69 ;
} else
F_4 ( V_2 ) ;
V_26 = V_2 -> V_30 ;
for ( V_68 = 0 ; V_68 < V_26 ; V_68 ++ ) {
if ( V_2 -> V_31 [ V_68 ] . type != V_77 )
continue;
V_66 = V_2 -> V_31 [ V_68 ] . V_78 ;
V_67 = V_2 -> V_31 [ V_68 ] . V_78 + V_2 -> V_31 [ V_68 ] . V_79 - 1 ;
if ( ( V_66 <= 0x100000 ) && V_67 > 0x100000 ) {
V_65 = ( V_67 >> 10 ) - ( 0x100000 >> 10 ) ;
V_2 -> V_71 . V_72 = V_65 ;
V_2 -> V_73 = V_65 ;
if ( V_65 > 0xfc00 )
V_2 -> V_71 . V_72 = 0xfc00 ;
if ( V_65 > 0xffffffff )
V_2 -> V_73 = 0xffffffff ;
}
}
#ifdef F_13
F_8 ( V_2 , V_34 , V_35 , V_36 ,
V_44 ) ;
#endif
memcpy ( V_2 -> V_80 , V_1 . V_80 ,
V_81 * sizeof( struct V_82 ) ) ;
V_2 -> V_83 = V_1 . V_83 ;
memcpy ( V_2 -> V_84 , V_1 . V_84 ,
V_85 * sizeof( unsigned int ) ) ;
return V_69 ;
}
static int F_14 ( const char * V_86 , unsigned long V_18 )
{
int V_69 = - V_87 ;
struct V_88 * V_89 ;
if ( V_18 < 2 * 512 ) {
F_15 ( L_3 ) ;
return V_69 ;
}
V_89 = (struct V_88 * ) ( V_86 + F_16 ( struct V_1 , V_5 ) ) ;
if ( memcmp ( ( char * ) & V_89 -> V_89 , L_4 , 4 ) != 0 ) {
F_15 ( L_5 ) ;
return V_69 ;
}
if ( V_89 -> V_90 != 0xAA55 ) {
F_15 ( L_6 ) ;
return V_69 ;
}
if ( V_89 -> V_91 < 0x020C ) {
F_15 ( L_7 ) ;
return V_69 ;
}
if ( ! ( V_89 -> V_92 & V_93 ) ) {
F_15 ( L_8 ) ;
return V_69 ;
}
if ( ! ( V_89 -> V_94 & V_95 ) ) {
F_15 ( L_9 ) ;
return V_69 ;
}
if ( ! ( V_89 -> V_94 & V_96 ) ) {
F_15 ( L_10 ) ;
return V_69 ;
}
if ( F_9 ( V_97 ) && ! F_9 ( V_98 ) ) {
F_3 ( L_11 ) ;
return V_69 ;
}
F_3 ( L_12 ) ;
V_69 = 0 ;
return V_69 ;
}
static void * F_17 ( struct V_10 * V_11 , char * V_99 ,
unsigned long V_100 , char * V_101 ,
unsigned long V_4 , char * V_14 ,
unsigned long V_15 )
{
struct V_88 * V_89 ;
int V_102 , V_103 , V_69 = 0 ;
unsigned long V_104 , V_105 , V_106 ;
struct V_1 * V_2 ;
unsigned long V_107 , V_108 , V_3 ;
unsigned long V_109 ;
unsigned long V_110 , V_111 , V_112 ;
char * V_113 ;
struct V_114 * V_115 ;
struct V_116 V_117 ;
void * V_118 ;
unsigned int V_119 = F_16 ( struct V_1 , V_5 ) ;
unsigned int V_35 , V_36 , V_44 ;
V_89 = (struct V_88 * ) ( V_99 + V_119 ) ;
V_102 = V_89 -> V_102 ;
if ( V_102 == 0 )
V_102 = 4 ;
V_103 = ( V_102 + 1 ) * 512 ;
if ( V_100 < V_103 ) {
F_15 ( L_13 ) ;
return F_18 ( - V_87 ) ;
}
if ( V_15 > V_89 -> V_120 ) {
F_15 ( L_14 ) ;
return F_18 ( - V_121 ) ;
}
if ( V_15 + V_122 > V_89 -> V_120 ) {
F_3 ( L_15 ) ;
return F_18 ( - V_121 ) ;
}
if ( V_11 -> type == V_21 ) {
V_69 = F_19 ( V_11 ) ;
if ( V_69 )
return F_18 ( V_69 ) ;
}
V_69 = F_20 ( V_11 , V_123 , V_124 , 1 ,
& V_109 ) ;
if ( V_69 ) {
F_15 ( L_16 ) ;
return F_18 ( V_69 ) ;
}
F_3 ( L_17 , V_109 ) ;
V_36 = F_21 () ;
V_36 = F_22 ( V_36 , 16 ) ;
V_105 = sizeof( struct V_1 ) + V_15 +
V_122 ;
V_105 = F_22 ( V_105 , 16 ) ;
V_106 = V_105 + V_36 +
sizeof( struct V_46 ) +
sizeof( struct V_48 ) ;
V_2 = F_23 ( V_106 , V_125 ) ;
if ( ! V_2 )
return F_18 ( - V_126 ) ;
V_35 = V_105 ;
V_44 = V_35 + V_36 ;
V_104 = 0x0202 + V_99 [ 0x0201 ] - V_119 ;
memcpy ( & V_2 -> V_5 , ( V_99 + V_119 ) , V_104 ) ;
V_69 = F_24 ( V_11 , ( char * ) V_2 , V_106 ,
V_106 , 16 , V_127 ,
V_124 , 1 , & V_107 ) ;
if ( V_69 )
goto V_128;
F_3 ( L_18 ,
V_107 , V_106 , V_106 ) ;
V_113 = V_99 + V_103 ;
V_110 = V_100 - V_103 ;
V_111 = F_25 ( V_89 -> V_129 ) ;
V_112 = V_89 -> V_130 ;
V_69 = F_24 ( V_11 , V_113 ,
V_110 , V_111 , V_112 ,
V_131 , V_124 , 1 ,
& V_108 ) ;
if ( V_69 )
goto V_128;
F_3 ( L_19 ,
V_108 , V_111 , V_111 ) ;
if ( V_101 ) {
V_69 = F_24 ( V_11 , V_101 , V_4 , V_4 ,
V_132 , V_133 ,
V_124 , 1 , & V_3 ) ;
if ( V_69 )
goto V_128;
F_3 ( L_20 ,
V_3 , V_4 , V_4 ) ;
F_1 ( V_2 , V_3 , V_4 ) ;
}
F_2 ( V_11 , V_2 , V_107 ,
sizeof( struct V_1 ) , V_14 , V_15 ) ;
V_2 -> V_5 . V_134 = 0x0D << 4 ;
V_2 -> V_5 . V_92 = 0 ;
V_69 = F_26 ( V_11 , L_21 , & V_117 ,
sizeof( V_117 ) , 1 ) ;
if ( V_69 )
goto V_128;
V_117 . V_135 = 0 ;
V_117 . V_136 = V_107 ;
V_117 . V_137 = V_108 + 0x200 ;
V_118 = F_27 ( V_11 , L_22 ) ;
if ( F_28 ( V_118 ) ) {
F_15 ( L_23 ) ;
V_69 = - V_121 ;
goto V_128;
}
V_117 . V_138 = ( unsigned long ) V_118 ;
V_69 = F_26 ( V_11 , L_21 , & V_117 ,
sizeof( V_117 ) , 0 ) ;
if ( V_69 )
goto V_128;
V_69 = F_11 ( V_11 , V_2 , V_107 ,
V_35 , V_36 ,
V_44 ) ;
if ( V_69 )
goto V_128;
V_115 = F_23 ( sizeof( struct V_114 ) , V_125 ) ;
if ( ! V_115 ) {
V_69 = - V_126 ;
goto V_128;
}
V_115 -> V_139 = V_2 ;
return V_115 ;
V_128:
F_29 ( V_2 ) ;
return F_18 ( V_69 ) ;
}
static int F_30 ( void * V_140 )
{
struct V_114 * V_115 = V_140 ;
if ( ! V_115 )
return 0 ;
F_29 ( V_115 -> V_139 ) ;
V_115 -> V_139 = NULL ;
return 0 ;
}
static int F_31 ( const char * V_99 , unsigned long V_100 )
{
return F_32 ( V_99 , V_100 ,
NULL ,
V_141 ) ;
}
