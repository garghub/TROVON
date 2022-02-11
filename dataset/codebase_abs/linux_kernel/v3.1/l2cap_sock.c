static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_5 )
{
struct V_2 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 = F_2 ( V_6 ) -> V_8 ;
struct V_9 V_10 ;
int V_11 , V_12 = 0 ;
F_3 ( L_1 , V_6 ) ;
if ( ! V_4 || V_4 -> V_13 != V_14 )
return - V_15 ;
memset ( & V_10 , 0 , sizeof( V_10 ) ) ;
V_11 = F_4 (unsigned int, sizeof(la), alen) ;
memcpy ( & V_10 , V_4 , V_11 ) ;
if ( V_10 . V_16 && V_10 . V_17 )
return - V_15 ;
F_5 ( V_6 ) ;
if ( V_6 -> V_18 != V_19 ) {
V_12 = - V_20 ;
goto V_21;
}
if ( V_10 . V_17 ) {
T_1 V_22 = F_6 ( V_10 . V_17 ) ;
if ( ( V_22 & 0x0101 ) != 0x0001 ) {
V_12 = - V_15 ;
goto V_21;
}
if ( V_22 < 0x1001 && ! F_7 ( V_23 ) ) {
V_12 = - V_24 ;
goto V_21;
}
}
if ( V_10 . V_16 )
V_12 = F_8 ( V_8 , V_10 . V_16 ) ;
else
V_12 = F_9 ( V_8 , & V_10 . V_25 , V_10 . V_17 ) ;
if ( V_12 < 0 )
goto V_21;
if ( F_6 ( V_10 . V_17 ) == 0x0001 ||
F_6 ( V_10 . V_17 ) == 0x0003 )
V_8 -> V_26 = V_27 ;
F_10 ( & F_11 ( V_6 ) -> V_28 , & V_10 . V_25 ) ;
V_8 -> V_29 = V_30 ;
V_6 -> V_18 = V_30 ;
V_21:
F_12 ( V_6 ) ;
return V_12 ;
}
static int F_13 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_5 , int V_31 )
{
struct V_2 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 = F_2 ( V_6 ) -> V_8 ;
struct V_9 V_10 ;
int V_11 , V_12 = 0 ;
F_3 ( L_1 , V_6 ) ;
if ( ! V_4 || V_5 < sizeof( V_4 -> V_13 ) ||
V_4 -> V_13 != V_14 )
return - V_15 ;
memset ( & V_10 , 0 , sizeof( V_10 ) ) ;
V_11 = F_4 (unsigned int, sizeof(la), alen) ;
memcpy ( & V_10 , V_4 , V_11 ) ;
if ( V_10 . V_16 && V_10 . V_17 )
return - V_15 ;
F_5 ( V_6 ) ;
if ( V_8 -> V_32 == V_33
&& ! ( V_10 . V_17 || V_10 . V_16 ) ) {
V_12 = - V_15 ;
goto V_21;
}
switch ( V_8 -> V_34 ) {
case V_35 :
break;
case V_36 :
case V_37 :
if ( ! V_38 )
break;
default:
V_12 = - V_39 ;
goto V_21;
}
switch ( V_6 -> V_18 ) {
case V_40 :
case V_41 :
case V_42 :
goto V_43;
case V_44 :
V_12 = - V_45 ;
goto V_21;
case V_19 :
case V_30 :
break;
default:
V_12 = - V_20 ;
goto V_21;
}
if ( ( F_6 ( V_10 . V_17 ) & 0x0101 ) != 0x0001 && ! V_10 . V_16 &&
V_8 -> V_32 != V_46 ) {
V_12 = - V_15 ;
goto V_21;
}
F_10 ( & F_11 ( V_6 ) -> V_47 , & V_10 . V_25 ) ;
V_8 -> V_22 = V_10 . V_17 ;
V_8 -> V_48 = V_10 . V_16 ;
V_12 = F_14 ( F_2 ( V_6 ) -> V_8 ) ;
if ( V_12 )
goto V_21;
V_43:
V_12 = F_15 ( V_6 , V_44 ,
F_16 ( V_6 , V_31 & V_49 ) ) ;
V_21:
F_12 ( V_6 ) ;
return V_12 ;
}
static int F_17 ( struct V_1 * V_2 , int V_50 )
{
struct V_2 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 = F_2 ( V_6 ) -> V_8 ;
int V_12 = 0 ;
F_3 ( L_2 , V_6 , V_50 ) ;
F_5 ( V_6 ) ;
if ( ( V_2 -> type != V_51 && V_2 -> type != V_52 )
|| V_6 -> V_18 != V_30 ) {
V_12 = - V_20 ;
goto V_21;
}
switch ( V_8 -> V_34 ) {
case V_35 :
break;
case V_36 :
case V_37 :
if ( ! V_38 )
break;
default:
V_12 = - V_39 ;
goto V_21;
}
V_6 -> V_53 = V_50 ;
V_6 -> V_54 = 0 ;
V_8 -> V_29 = V_55 ;
V_6 -> V_18 = V_55 ;
V_21:
F_12 ( V_6 ) ;
return V_12 ;
}
static int F_18 ( struct V_1 * V_2 , struct V_1 * V_56 , int V_31 )
{
F_19 ( V_43 , V_57 ) ;
struct V_2 * V_6 = V_2 -> V_6 , * V_58 ;
long V_59 ;
int V_12 = 0 ;
F_20 ( V_6 , V_60 ) ;
V_59 = F_21 ( V_6 , V_31 & V_49 ) ;
F_3 ( L_3 , V_6 , V_59 ) ;
F_22 ( F_23 ( V_6 ) , & V_43 ) ;
while ( 1 ) {
F_24 ( V_61 ) ;
if ( V_6 -> V_18 != V_55 ) {
V_12 = - V_20 ;
break;
}
V_58 = F_25 ( V_6 , V_56 ) ;
if ( V_58 )
break;
if ( ! V_59 ) {
V_12 = - V_62 ;
break;
}
if ( F_26 ( V_57 ) ) {
V_12 = F_27 ( V_59 ) ;
break;
}
F_12 ( V_6 ) ;
V_59 = F_28 ( V_59 ) ;
F_20 ( V_6 , V_60 ) ;
}
F_29 ( V_63 ) ;
F_30 ( F_23 ( V_6 ) , & V_43 ) ;
if ( V_12 )
goto V_21;
V_56 -> V_29 = V_64 ;
F_3 ( L_4 , V_58 ) ;
V_21:
F_12 ( V_6 ) ;
return V_12 ;
}
static int F_31 ( struct V_1 * V_2 , struct V_3 * V_4 , int * V_11 , int V_65 )
{
struct V_9 * V_10 = (struct V_9 * ) V_4 ;
struct V_2 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 = F_2 ( V_6 ) -> V_8 ;
F_3 ( L_5 , V_2 , V_6 ) ;
V_4 -> V_13 = V_14 ;
* V_11 = sizeof( struct V_9 ) ;
if ( V_65 ) {
V_10 -> V_17 = V_8 -> V_22 ;
F_10 ( & V_10 -> V_25 , & F_11 ( V_6 ) -> V_47 ) ;
V_10 -> V_16 = F_32 ( V_8 -> V_48 ) ;
} else {
V_10 -> V_17 = V_8 -> V_66 ;
F_10 ( & V_10 -> V_25 , & F_11 ( V_6 ) -> V_28 ) ;
V_10 -> V_16 = F_32 ( V_8 -> V_67 ) ;
}
return 0 ;
}
static int F_33 ( struct V_1 * V_2 , int V_68 , char T_2 * V_69 , int T_2 * V_70 )
{
struct V_2 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 = F_2 ( V_6 ) -> V_8 ;
struct V_71 V_72 ;
struct V_73 V_74 ;
int V_11 , V_12 = 0 ;
T_3 V_75 ;
F_3 ( L_1 , V_6 ) ;
if ( F_34 ( V_11 , V_70 ) )
return - V_76 ;
F_5 ( V_6 ) ;
switch ( V_68 ) {
case V_77 :
memset ( & V_72 , 0 , sizeof( V_72 ) ) ;
V_72 . V_78 = V_8 -> V_78 ;
V_72 . V_79 = V_8 -> V_79 ;
V_72 . V_80 = V_8 -> V_80 ;
V_72 . V_34 = V_8 -> V_34 ;
V_72 . V_81 = V_8 -> V_81 ;
V_72 . V_82 = V_8 -> V_82 ;
V_72 . V_83 = ( T_1 ) V_8 -> V_84 ;
V_11 = F_4 (unsigned int, len, sizeof(opts)) ;
if ( F_35 ( V_69 , ( char * ) & V_72 , V_11 ) )
V_12 = - V_76 ;
break;
case V_85 :
switch ( V_8 -> V_26 ) {
case V_86 :
V_75 = V_87 ;
break;
case V_88 :
V_75 = V_87 | V_89 ;
break;
case V_90 :
V_75 = V_87 | V_89 |
V_91 ;
break;
default:
V_75 = 0 ;
break;
}
if ( V_8 -> V_92 )
V_75 |= V_93 ;
if ( V_8 -> V_94 )
V_75 |= V_95 ;
if ( F_36 ( V_75 , ( T_3 T_2 * ) V_69 ) )
V_12 = - V_76 ;
break;
case V_96 :
if ( V_6 -> V_18 != V_44 &&
! ( V_6 -> V_18 == V_41 &&
F_11 ( V_6 ) -> V_97 ) ) {
V_12 = - V_98 ;
break;
}
memset ( & V_74 , 0 , sizeof( V_74 ) ) ;
V_74 . V_99 = V_8 -> V_100 -> V_101 -> V_102 ;
memcpy ( V_74 . V_103 , V_8 -> V_100 -> V_101 -> V_103 , 3 ) ;
V_11 = F_4 (unsigned int, len, sizeof(cinfo)) ;
if ( F_35 ( V_69 , ( char * ) & V_74 , V_11 ) )
V_12 = - V_76 ;
break;
default:
V_12 = - V_104 ;
break;
}
F_12 ( V_6 ) ;
return V_12 ;
}
static int F_37 ( struct V_1 * V_2 , int V_105 , int V_68 , char T_2 * V_69 , int T_2 * V_70 )
{
struct V_2 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 = F_2 ( V_6 ) -> V_8 ;
struct V_106 V_107 ;
struct V_108 V_109 ;
int V_11 , V_12 = 0 ;
F_3 ( L_1 , V_6 ) ;
if ( V_105 == V_110 )
return F_33 ( V_2 , V_68 , V_69 , V_70 ) ;
if ( V_105 != V_111 )
return - V_104 ;
if ( F_34 ( V_11 , V_70 ) )
return - V_76 ;
F_5 ( V_6 ) ;
switch ( V_68 ) {
case V_112 :
if ( V_8 -> V_32 != V_33 &&
V_8 -> V_32 != V_46 ) {
V_12 = - V_15 ;
break;
}
memset ( & V_107 , 0 , sizeof( V_107 ) ) ;
V_107 . V_105 = V_8 -> V_26 ;
if ( V_6 -> V_18 == V_44 )
V_107 . V_113 = V_8 -> V_100 -> V_101 -> V_114 ;
V_11 = F_4 (unsigned int, len, sizeof(sec)) ;
if ( F_35 ( V_69 , ( char * ) & V_107 , V_11 ) )
V_12 = - V_76 ;
break;
case V_115 :
if ( V_6 -> V_18 != V_30 && V_6 -> V_18 != V_55 ) {
V_12 = - V_15 ;
break;
}
if ( F_36 ( F_11 ( V_6 ) -> V_97 , ( T_3 T_2 * ) V_69 ) )
V_12 = - V_76 ;
break;
case V_116 :
if ( F_36 ( V_8 -> V_117 , ( T_3 T_2 * ) V_69 ) )
V_12 = - V_76 ;
break;
case V_118 :
if ( V_6 -> V_119 != V_51 && V_6 -> V_119 != V_52
&& V_6 -> V_119 != V_120 ) {
V_12 = - V_15 ;
break;
}
V_109 . V_121 = V_8 -> V_121 ;
V_11 = F_4 (unsigned int, len, sizeof(pwr)) ;
if ( F_35 ( V_69 , ( char * ) & V_109 , V_11 ) )
V_12 = - V_76 ;
break;
default:
V_12 = - V_104 ;
break;
}
F_12 ( V_6 ) ;
return V_12 ;
}
static int F_38 ( struct V_1 * V_2 , int V_68 , char T_2 * V_69 , unsigned int V_70 )
{
struct V_2 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 = F_2 ( V_6 ) -> V_8 ;
struct V_71 V_72 ;
int V_11 , V_12 = 0 ;
T_3 V_75 ;
F_3 ( L_1 , V_6 ) ;
F_5 ( V_6 ) ;
switch ( V_68 ) {
case V_77 :
if ( V_6 -> V_18 == V_44 ) {
V_12 = - V_15 ;
break;
}
V_72 . V_78 = V_8 -> V_78 ;
V_72 . V_79 = V_8 -> V_79 ;
V_72 . V_80 = V_8 -> V_80 ;
V_72 . V_34 = V_8 -> V_34 ;
V_72 . V_81 = V_8 -> V_81 ;
V_72 . V_82 = V_8 -> V_82 ;
V_72 . V_83 = ( T_1 ) V_8 -> V_84 ;
V_11 = F_4 (unsigned int, sizeof(opts), optlen) ;
if ( F_39 ( ( char * ) & V_72 , V_69 , V_11 ) ) {
V_12 = - V_76 ;
break;
}
if ( V_72 . V_83 > V_122 ) {
V_12 = - V_15 ;
break;
}
V_8 -> V_34 = V_72 . V_34 ;
switch ( V_8 -> V_34 ) {
case V_35 :
F_40 ( V_123 , & V_8 -> V_124 ) ;
break;
case V_36 :
case V_37 :
if ( ! V_38 )
break;
default:
V_12 = - V_15 ;
break;
}
V_8 -> V_78 = V_72 . V_78 ;
V_8 -> V_79 = V_72 . V_79 ;
V_8 -> V_81 = V_72 . V_81 ;
V_8 -> V_82 = V_72 . V_82 ;
V_8 -> V_84 = ( V_125 ) V_72 . V_83 ;
break;
case V_85 :
if ( F_34 ( V_75 , ( T_3 T_2 * ) V_69 ) ) {
V_12 = - V_76 ;
break;
}
if ( V_75 & V_87 )
V_8 -> V_26 = V_86 ;
if ( V_75 & V_89 )
V_8 -> V_26 = V_88 ;
if ( V_75 & V_91 )
V_8 -> V_26 = V_90 ;
V_8 -> V_92 = ( V_75 & V_93 ) ;
V_8 -> V_94 = ( V_75 & V_95 ) ;
break;
default:
V_12 = - V_104 ;
break;
}
F_12 ( V_6 ) ;
return V_12 ;
}
static int F_41 ( struct V_1 * V_2 , int V_105 , int V_68 , char T_2 * V_69 , unsigned int V_70 )
{
struct V_2 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 = F_2 ( V_6 ) -> V_8 ;
struct V_106 V_107 ;
struct V_108 V_109 ;
struct V_126 * V_100 ;
int V_11 , V_12 = 0 ;
T_3 V_75 ;
F_3 ( L_1 , V_6 ) ;
if ( V_105 == V_110 )
return F_38 ( V_2 , V_68 , V_69 , V_70 ) ;
if ( V_105 != V_111 )
return - V_104 ;
F_5 ( V_6 ) ;
switch ( V_68 ) {
case V_112 :
if ( V_8 -> V_32 != V_33 &&
V_8 -> V_32 != V_46 ) {
V_12 = - V_15 ;
break;
}
V_107 . V_105 = V_86 ;
V_11 = F_4 (unsigned int, sizeof(sec), optlen) ;
if ( F_39 ( ( char * ) & V_107 , V_69 , V_11 ) ) {
V_12 = - V_76 ;
break;
}
if ( V_107 . V_105 < V_86 ||
V_107 . V_105 > V_90 ) {
V_12 = - V_15 ;
break;
}
V_8 -> V_26 = V_107 . V_105 ;
V_100 = V_8 -> V_100 ;
if ( V_100 && V_8 -> V_67 == V_127 ) {
if ( ! V_100 -> V_101 -> V_128 ) {
V_12 = - V_15 ;
break;
}
if ( F_42 ( V_100 , V_107 . V_105 ) )
break;
V_12 = 0 ;
V_6 -> V_18 = V_42 ;
}
break;
case V_115 :
if ( V_6 -> V_18 != V_30 && V_6 -> V_18 != V_55 ) {
V_12 = - V_15 ;
break;
}
if ( F_34 ( V_75 , ( T_3 T_2 * ) V_69 ) ) {
V_12 = - V_76 ;
break;
}
F_11 ( V_6 ) -> V_97 = V_75 ;
break;
case V_116 :
if ( F_34 ( V_75 , ( T_3 T_2 * ) V_69 ) ) {
V_12 = - V_76 ;
break;
}
if ( V_75 > V_129 ) {
V_12 = - V_15 ;
break;
}
if ( V_75 == V_130 ) {
struct V_126 * V_100 = V_8 -> V_100 ;
if ( ! V_100 || ! F_43 ( V_100 -> V_101 -> V_131 ) ) {
V_12 = - V_15 ;
break;
}
}
V_8 -> V_117 = V_75 ;
break;
case V_118 :
if ( V_8 -> V_32 != V_33 &&
V_8 -> V_32 != V_46 ) {
V_12 = - V_15 ;
break;
}
V_109 . V_121 = V_132 ;
V_11 = F_4 (unsigned int, sizeof(pwr), optlen) ;
if ( F_39 ( ( char * ) & V_109 , V_69 , V_11 ) ) {
V_12 = - V_76 ;
break;
}
V_8 -> V_121 = V_109 . V_121 ;
break;
default:
V_12 = - V_104 ;
break;
}
F_12 ( V_6 ) ;
return V_12 ;
}
static int F_44 ( struct V_133 * V_134 , struct V_1 * V_2 , struct V_135 * V_136 , T_4 V_11 )
{
struct V_2 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 = F_2 ( V_6 ) -> V_8 ;
int V_12 ;
F_3 ( L_5 , V_2 , V_6 ) ;
V_12 = F_45 ( V_6 ) ;
if ( V_12 )
return V_12 ;
if ( V_136 -> V_137 & V_138 )
return - V_139 ;
F_5 ( V_6 ) ;
if ( V_6 -> V_18 != V_44 ) {
F_12 ( V_6 ) ;
return - V_98 ;
}
V_12 = F_46 ( V_8 , V_136 , V_11 ) ;
F_12 ( V_6 ) ;
return V_12 ;
}
static int F_47 ( struct V_133 * V_134 , struct V_1 * V_2 , struct V_135 * V_136 , T_4 V_11 , int V_31 )
{
struct V_2 * V_6 = V_2 -> V_6 ;
struct V_140 * V_141 = F_2 ( V_6 ) ;
int V_12 ;
F_5 ( V_6 ) ;
if ( V_6 -> V_18 == V_41 && F_11 ( V_6 ) -> V_97 ) {
V_6 -> V_18 = V_42 ;
F_48 ( V_141 -> V_8 ) ;
F_12 ( V_6 ) ;
return 0 ;
}
F_12 ( V_6 ) ;
if ( V_2 -> type == V_52 )
V_12 = F_49 ( V_134 , V_2 , V_136 , V_11 , V_31 ) ;
else
V_12 = F_50 ( V_134 , V_2 , V_136 , V_11 , V_31 ) ;
if ( V_141 -> V_8 -> V_34 != V_36 )
return V_12 ;
F_5 ( V_6 ) ;
if ( ! F_51 ( V_142 , & V_141 -> V_8 -> V_143 ) )
goto V_21;
if ( V_141 -> V_144 ) {
if ( ! F_52 ( V_6 , V_141 -> V_144 ) )
V_141 -> V_144 = NULL ;
else
goto V_21;
}
if ( F_53 ( & V_6 -> V_145 ) <= V_6 -> V_146 >> 1 )
F_54 ( V_141 -> V_8 , 0 ) ;
V_21:
F_12 ( V_6 ) ;
return V_12 ;
}
static void F_55 ( struct V_2 * V_6 )
{
if ( ! F_56 ( V_6 , V_147 ) || V_6 -> V_148 )
return;
F_3 ( L_6 , V_6 , V_6 -> V_18 ) ;
F_57 ( F_2 ( V_6 ) -> V_8 ) ;
F_58 ( V_6 , V_149 ) ;
F_59 ( V_6 ) ;
}
static int F_60 ( struct V_1 * V_2 , int V_150 )
{
struct V_2 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 = F_2 ( V_6 ) -> V_8 ;
int V_12 = 0 ;
F_3 ( L_5 , V_2 , V_6 ) ;
if ( ! V_6 )
return 0 ;
F_5 ( V_6 ) ;
if ( ! V_6 -> V_151 ) {
if ( V_8 -> V_34 == V_36 )
V_12 = F_61 ( V_6 ) ;
V_6 -> V_151 = V_152 ;
F_62 ( V_8 , 0 ) ;
if ( F_56 ( V_6 , V_153 ) && V_6 -> V_154 )
V_12 = F_15 ( V_6 , V_155 ,
V_6 -> V_154 ) ;
}
if ( ! V_12 && V_6 -> V_156 )
V_12 = - V_6 -> V_156 ;
F_12 ( V_6 ) ;
return V_12 ;
}
static int F_63 ( struct V_1 * V_2 )
{
struct V_2 * V_6 = V_2 -> V_6 ;
int V_12 ;
F_3 ( L_5 , V_2 , V_6 ) ;
if ( ! V_6 )
return 0 ;
V_12 = F_60 ( V_2 , 2 ) ;
F_64 ( V_6 ) ;
F_55 ( V_6 ) ;
return V_12 ;
}
static struct V_7 * F_65 ( void * V_157 )
{
struct V_2 * V_6 , * V_158 = V_157 ;
V_6 = F_66 ( F_67 ( V_158 ) , NULL , V_159 ,
V_160 ) ;
if ( ! V_6 )
return NULL ;
F_68 ( V_6 , V_158 ) ;
return F_2 ( V_6 ) -> V_8 ;
}
static int F_69 ( void * V_157 , struct V_161 * V_162 )
{
int V_12 ;
struct V_2 * V_6 = V_157 ;
struct V_140 * V_141 = F_2 ( V_6 ) ;
if ( V_141 -> V_144 )
return - V_163 ;
V_12 = F_52 ( V_6 , V_162 ) ;
if ( V_12 < 0 && V_141 -> V_8 -> V_34 == V_36 ) {
V_141 -> V_144 = V_162 ;
F_54 ( V_141 -> V_8 , 1 ) ;
V_12 = 0 ;
}
return V_12 ;
}
static void F_70 ( void * V_157 )
{
struct V_2 * V_6 = V_157 ;
F_55 ( V_6 ) ;
}
static void F_71 ( void * V_157 , int V_29 )
{
struct V_2 * V_6 = V_157 ;
V_6 -> V_18 = V_29 ;
}
static void F_72 ( struct V_2 * V_6 )
{
F_3 ( L_1 , V_6 ) ;
if ( F_2 ( V_6 ) -> V_144 ) {
F_73 ( F_2 ( V_6 ) -> V_144 ) ;
F_2 ( V_6 ) -> V_144 = NULL ;
}
F_74 ( & V_6 -> V_164 ) ;
F_74 ( & V_6 -> V_165 ) ;
}
static void F_68 ( struct V_2 * V_6 , struct V_2 * V_158 )
{
struct V_140 * V_141 = F_2 ( V_6 ) ;
struct V_7 * V_8 = V_141 -> V_8 ;
F_3 ( L_1 , V_6 ) ;
if ( V_158 ) {
struct V_7 * V_166 = F_2 ( V_158 ) -> V_8 ;
V_6 -> V_119 = V_158 -> V_119 ;
F_11 ( V_6 ) -> V_97 = F_11 ( V_158 ) -> V_97 ;
V_8 -> V_32 = V_166 -> V_32 ;
V_8 -> V_78 = V_166 -> V_78 ;
V_8 -> V_79 = V_166 -> V_79 ;
V_8 -> V_124 = V_166 -> V_124 ;
V_8 -> V_34 = V_166 -> V_34 ;
V_8 -> V_81 = V_166 -> V_81 ;
V_8 -> V_82 = V_166 -> V_82 ;
V_8 -> V_84 = V_166 -> V_84 ;
V_8 -> V_26 = V_166 -> V_26 ;
V_8 -> V_92 = V_166 -> V_92 ;
V_8 -> V_94 = V_166 -> V_94 ;
V_8 -> V_117 = V_166 -> V_117 ;
V_8 -> V_121 = V_166 -> V_121 ;
F_75 ( V_158 , V_6 ) ;
} else {
switch ( V_6 -> V_119 ) {
case V_120 :
V_8 -> V_32 = V_46 ;
break;
case V_167 :
V_8 -> V_32 = V_168 ;
break;
case V_51 :
case V_52 :
V_8 -> V_32 = V_33 ;
break;
}
V_8 -> V_78 = V_169 ;
V_8 -> V_79 = 0 ;
if ( ! V_38 && V_6 -> V_119 == V_52 ) {
V_8 -> V_34 = V_36 ;
F_76 ( V_123 , & V_8 -> V_124 ) ;
} else {
V_8 -> V_34 = V_35 ;
}
V_8 -> V_82 = V_170 ;
V_8 -> V_81 = V_171 ;
V_8 -> V_84 = V_122 ;
V_8 -> V_26 = V_86 ;
V_8 -> V_92 = 0 ;
V_8 -> V_94 = 0 ;
V_8 -> V_117 = V_130 ;
V_8 -> V_121 = V_132 ;
}
V_8 -> V_80 = V_172 ;
V_8 -> V_157 = V_6 ;
V_8 -> V_173 = & V_174 ;
}
static struct V_2 * F_66 ( struct V_175 * V_175 , struct V_1 * V_2 , int V_176 , T_5 V_177 )
{
struct V_2 * V_6 ;
struct V_7 * V_8 ;
V_6 = F_77 ( V_175 , V_178 , V_177 , & V_179 ) ;
if ( ! V_6 )
return NULL ;
F_78 ( V_2 , V_6 ) ;
F_79 ( & F_11 ( V_6 ) -> V_180 ) ;
V_6 -> V_181 = F_72 ;
V_6 -> V_182 = V_183 ;
F_80 ( V_6 , V_147 ) ;
V_6 -> V_184 = V_176 ;
V_6 -> V_18 = V_19 ;
V_8 = F_81 ( V_6 ) ;
if ( ! V_8 ) {
F_55 ( V_6 ) ;
return NULL ;
}
F_2 ( V_6 ) -> V_8 = V_8 ;
return V_6 ;
}
static int F_82 ( struct V_175 * V_175 , struct V_1 * V_2 , int V_185 ,
int V_186 )
{
struct V_2 * V_6 ;
F_3 ( L_7 , V_2 ) ;
V_2 -> V_29 = V_187 ;
if ( V_2 -> type != V_51 && V_2 -> type != V_52 &&
V_2 -> type != V_167 && V_2 -> type != V_120 )
return - V_188 ;
if ( V_2 -> type == V_120 && ! V_186 && ! F_7 ( V_189 ) )
return - V_190 ;
V_2 -> V_173 = & V_191 ;
V_6 = F_66 ( V_175 , V_2 , V_185 , V_160 ) ;
if ( ! V_6 )
return - V_163 ;
F_68 ( V_6 , NULL ) ;
return 0 ;
}
int T_6 F_83 ( void )
{
int V_12 ;
V_12 = F_84 ( & V_179 , 0 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_85 ( V_159 , & V_192 ) ;
if ( V_12 < 0 )
goto error;
F_86 ( L_8 ) ;
return 0 ;
error:
F_87 ( L_9 ) ;
F_88 ( & V_179 ) ;
return V_12 ;
}
void F_89 ( void )
{
if ( F_90 ( V_159 ) < 0 )
F_87 ( L_10 ) ;
F_88 ( & V_179 ) ;
}
