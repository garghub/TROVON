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
V_12 = F_14 ( V_8 , V_10 . V_17 , V_10 . V_16 , & V_10 . V_25 ) ;
if ( V_12 )
goto V_21;
V_12 = F_15 ( V_6 , V_32 ,
F_16 ( V_6 , V_31 & V_33 ) ) ;
V_21:
if ( F_17 ( V_6 ) )
F_12 ( V_6 ) ;
return V_12 ;
}
static int F_18 ( struct V_1 * V_2 , int V_34 )
{
struct V_2 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 = F_2 ( V_6 ) -> V_8 ;
int V_12 = 0 ;
F_3 ( L_2 , V_6 , V_34 ) ;
F_5 ( V_6 ) ;
if ( ( V_2 -> type != V_35 && V_2 -> type != V_36 )
|| V_6 -> V_18 != V_30 ) {
V_12 = - V_20 ;
goto V_21;
}
switch ( V_8 -> V_37 ) {
case V_38 :
break;
case V_39 :
case V_40 :
if ( ! V_41 )
break;
default:
V_12 = - V_42 ;
goto V_21;
}
V_6 -> V_43 = V_34 ;
V_6 -> V_44 = 0 ;
V_8 -> V_29 = V_45 ;
V_6 -> V_18 = V_45 ;
V_21:
F_12 ( V_6 ) ;
return V_12 ;
}
static int F_19 ( struct V_1 * V_2 , struct V_1 * V_46 , int V_31 )
{
F_20 ( V_47 , V_48 ) ;
struct V_2 * V_6 = V_2 -> V_6 , * V_49 ;
long V_50 ;
int V_12 = 0 ;
F_21 ( V_6 , V_51 ) ;
V_50 = F_22 ( V_6 , V_31 & V_33 ) ;
F_3 ( L_3 , V_6 , V_50 ) ;
F_23 ( F_24 ( V_6 ) , & V_47 ) ;
while ( 1 ) {
F_25 ( V_52 ) ;
if ( V_6 -> V_18 != V_45 ) {
V_12 = - V_20 ;
break;
}
V_49 = F_26 ( V_6 , V_46 ) ;
if ( V_49 )
break;
if ( ! V_50 ) {
V_12 = - V_53 ;
break;
}
if ( F_27 ( V_48 ) ) {
V_12 = F_28 ( V_50 ) ;
break;
}
F_12 ( V_6 ) ;
V_50 = F_29 ( V_50 ) ;
F_21 ( V_6 , V_51 ) ;
}
F_30 ( V_54 ) ;
F_31 ( F_24 ( V_6 ) , & V_47 ) ;
if ( V_12 )
goto V_21;
V_46 -> V_29 = V_55 ;
F_3 ( L_4 , V_49 ) ;
V_21:
F_12 ( V_6 ) ;
return V_12 ;
}
static int F_32 ( struct V_1 * V_2 , struct V_3 * V_4 , int * V_11 , int V_56 )
{
struct V_9 * V_10 = (struct V_9 * ) V_4 ;
struct V_2 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 = F_2 ( V_6 ) -> V_8 ;
F_3 ( L_5 , V_2 , V_6 ) ;
V_4 -> V_13 = V_14 ;
* V_11 = sizeof( struct V_9 ) ;
if ( V_56 ) {
V_10 -> V_17 = V_8 -> V_22 ;
F_10 ( & V_10 -> V_25 , & F_11 ( V_6 ) -> V_57 ) ;
V_10 -> V_16 = F_33 ( V_8 -> V_58 ) ;
} else {
V_10 -> V_17 = V_8 -> V_59 ;
F_10 ( & V_10 -> V_25 , & F_11 ( V_6 ) -> V_28 ) ;
V_10 -> V_16 = F_33 ( V_8 -> V_60 ) ;
}
return 0 ;
}
static int F_34 ( struct V_1 * V_2 , int V_61 , char T_2 * V_62 , int T_2 * V_63 )
{
struct V_2 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 = F_2 ( V_6 ) -> V_8 ;
struct V_64 V_65 ;
struct V_66 V_67 ;
int V_11 , V_12 = 0 ;
T_3 V_68 ;
F_3 ( L_1 , V_6 ) ;
if ( F_35 ( V_11 , V_63 ) )
return - V_69 ;
F_5 ( V_6 ) ;
switch ( V_61 ) {
case V_70 :
memset ( & V_65 , 0 , sizeof( V_65 ) ) ;
V_65 . V_71 = V_8 -> V_71 ;
V_65 . V_72 = V_8 -> V_72 ;
V_65 . V_73 = V_8 -> V_73 ;
V_65 . V_37 = V_8 -> V_37 ;
V_65 . V_74 = V_8 -> V_74 ;
V_65 . V_75 = V_8 -> V_75 ;
V_65 . V_76 = V_8 -> V_77 ;
V_11 = F_4 (unsigned int, len, sizeof(opts)) ;
if ( F_36 ( V_62 , ( char * ) & V_65 , V_11 ) )
V_12 = - V_69 ;
break;
case V_78 :
switch ( V_8 -> V_26 ) {
case V_79 :
V_68 = V_80 ;
break;
case V_81 :
V_68 = V_80 | V_82 ;
break;
case V_83 :
V_68 = V_80 | V_82 |
V_84 ;
break;
default:
V_68 = 0 ;
break;
}
if ( F_37 ( V_85 , & V_8 -> V_31 ) )
V_68 |= V_86 ;
if ( F_37 ( V_87 , & V_8 -> V_31 ) )
V_68 |= V_88 ;
if ( F_38 ( V_68 , ( T_3 T_2 * ) V_62 ) )
V_12 = - V_69 ;
break;
case V_89 :
if ( V_6 -> V_18 != V_32 &&
! ( V_6 -> V_18 == V_90 &&
F_11 ( V_6 ) -> V_91 ) ) {
V_12 = - V_92 ;
break;
}
memset ( & V_67 , 0 , sizeof( V_67 ) ) ;
V_67 . V_93 = V_8 -> V_94 -> V_95 -> V_96 ;
memcpy ( V_67 . V_97 , V_8 -> V_94 -> V_95 -> V_97 , 3 ) ;
V_11 = F_4 (unsigned int, len, sizeof(cinfo)) ;
if ( F_36 ( V_62 , ( char * ) & V_67 , V_11 ) )
V_12 = - V_69 ;
break;
default:
V_12 = - V_98 ;
break;
}
F_12 ( V_6 ) ;
return V_12 ;
}
static int F_39 ( struct V_1 * V_2 , int V_99 , int V_61 , char T_2 * V_62 , int T_2 * V_63 )
{
struct V_2 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 = F_2 ( V_6 ) -> V_8 ;
struct V_100 V_101 ;
struct V_102 V_103 ;
int V_11 , V_12 = 0 ;
F_3 ( L_1 , V_6 ) ;
if ( V_99 == V_104 )
return F_34 ( V_2 , V_61 , V_62 , V_63 ) ;
if ( V_99 != V_105 )
return - V_98 ;
if ( F_35 ( V_11 , V_63 ) )
return - V_69 ;
F_5 ( V_6 ) ;
switch ( V_61 ) {
case V_106 :
if ( V_8 -> V_107 != V_108 &&
V_8 -> V_107 != V_109 ) {
V_12 = - V_15 ;
break;
}
memset ( & V_101 , 0 , sizeof( V_101 ) ) ;
V_101 . V_99 = V_8 -> V_26 ;
if ( V_6 -> V_18 == V_32 )
V_101 . V_110 = V_8 -> V_94 -> V_95 -> V_111 ;
V_11 = F_4 (unsigned int, len, sizeof(sec)) ;
if ( F_36 ( V_62 , ( char * ) & V_101 , V_11 ) )
V_12 = - V_69 ;
break;
case V_112 :
if ( V_6 -> V_18 != V_30 && V_6 -> V_18 != V_45 ) {
V_12 = - V_15 ;
break;
}
if ( F_38 ( F_11 ( V_6 ) -> V_91 , ( T_3 T_2 * ) V_62 ) )
V_12 = - V_69 ;
break;
case V_113 :
if ( F_38 ( F_37 ( V_114 , & V_8 -> V_31 ) ,
( T_3 T_2 * ) V_62 ) )
V_12 = - V_69 ;
break;
case V_115 :
if ( V_6 -> V_116 != V_35 && V_6 -> V_116 != V_36
&& V_6 -> V_116 != V_117 ) {
V_12 = - V_15 ;
break;
}
V_103 . V_118 = F_37 ( V_119 , & V_8 -> V_31 ) ;
V_11 = F_4 (unsigned int, len, sizeof(pwr)) ;
if ( F_36 ( V_62 , ( char * ) & V_103 , V_11 ) )
V_12 = - V_69 ;
break;
case V_120 :
if ( ! V_121 ) {
V_12 = - V_98 ;
break;
}
if ( F_38 ( V_8 -> V_122 , ( T_3 T_2 * ) V_62 ) )
V_12 = - V_69 ;
break;
default:
V_12 = - V_98 ;
break;
}
F_12 ( V_6 ) ;
return V_12 ;
}
static int F_40 ( struct V_1 * V_2 , int V_61 , char T_2 * V_62 , unsigned int V_63 )
{
struct V_2 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 = F_2 ( V_6 ) -> V_8 ;
struct V_64 V_65 ;
int V_11 , V_12 = 0 ;
T_3 V_68 ;
F_3 ( L_1 , V_6 ) ;
F_5 ( V_6 ) ;
switch ( V_61 ) {
case V_70 :
if ( V_6 -> V_18 == V_32 ) {
V_12 = - V_15 ;
break;
}
V_65 . V_71 = V_8 -> V_71 ;
V_65 . V_72 = V_8 -> V_72 ;
V_65 . V_73 = V_8 -> V_73 ;
V_65 . V_37 = V_8 -> V_37 ;
V_65 . V_74 = V_8 -> V_74 ;
V_65 . V_75 = V_8 -> V_75 ;
V_65 . V_76 = V_8 -> V_77 ;
V_11 = F_4 (unsigned int, sizeof(opts), optlen) ;
if ( F_41 ( ( char * ) & V_65 , V_62 , V_11 ) ) {
V_12 = - V_69 ;
break;
}
if ( V_65 . V_76 > V_123 ) {
V_12 = - V_15 ;
break;
}
V_8 -> V_37 = V_65 . V_37 ;
switch ( V_8 -> V_37 ) {
case V_38 :
F_42 ( V_124 , & V_8 -> V_125 ) ;
break;
case V_39 :
case V_40 :
if ( ! V_41 )
break;
default:
V_12 = - V_15 ;
break;
}
V_8 -> V_71 = V_65 . V_71 ;
V_8 -> V_72 = V_65 . V_72 ;
V_8 -> V_74 = V_65 . V_74 ;
V_8 -> V_75 = V_65 . V_75 ;
V_8 -> V_77 = V_65 . V_76 ;
break;
case V_78 :
if ( F_35 ( V_68 , ( T_3 T_2 * ) V_62 ) ) {
V_12 = - V_69 ;
break;
}
if ( V_68 & V_80 )
V_8 -> V_26 = V_79 ;
if ( V_68 & V_82 )
V_8 -> V_26 = V_81 ;
if ( V_68 & V_84 )
V_8 -> V_26 = V_83 ;
if ( V_68 & V_86 )
F_43 ( V_85 , & V_8 -> V_31 ) ;
else
F_42 ( V_85 , & V_8 -> V_31 ) ;
if ( V_68 & V_88 )
F_43 ( V_87 , & V_8 -> V_31 ) ;
else
F_42 ( V_87 , & V_8 -> V_31 ) ;
break;
default:
V_12 = - V_98 ;
break;
}
F_12 ( V_6 ) ;
return V_12 ;
}
static int F_44 ( struct V_1 * V_2 , int V_99 , int V_61 , char T_2 * V_62 , unsigned int V_63 )
{
struct V_2 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 = F_2 ( V_6 ) -> V_8 ;
struct V_100 V_101 ;
struct V_102 V_103 ;
struct V_126 * V_94 ;
int V_11 , V_12 = 0 ;
T_3 V_68 ;
F_3 ( L_1 , V_6 ) ;
if ( V_99 == V_104 )
return F_40 ( V_2 , V_61 , V_62 , V_63 ) ;
if ( V_99 != V_105 )
return - V_98 ;
F_5 ( V_6 ) ;
switch ( V_61 ) {
case V_106 :
if ( V_8 -> V_107 != V_108 &&
V_8 -> V_107 != V_109 ) {
V_12 = - V_15 ;
break;
}
V_101 . V_99 = V_79 ;
V_11 = F_4 (unsigned int, sizeof(sec), optlen) ;
if ( F_41 ( ( char * ) & V_101 , V_62 , V_11 ) ) {
V_12 = - V_69 ;
break;
}
if ( V_101 . V_99 < V_79 ||
V_101 . V_99 > V_83 ) {
V_12 = - V_15 ;
break;
}
V_8 -> V_26 = V_101 . V_99 ;
if ( ! V_8 -> V_94 )
break;
V_94 = V_8 -> V_94 ;
if ( V_8 -> V_60 == V_127 ) {
if ( ! V_94 -> V_95 -> V_128 ) {
V_12 = - V_15 ;
break;
}
if ( F_45 ( V_94 , V_101 . V_99 ) )
break;
V_6 -> V_18 = V_129 ;
V_8 -> V_29 = V_129 ;
} else if ( V_6 -> V_18 == V_90 &&
F_11 ( V_6 ) -> V_91 ) {
V_12 = F_46 ( V_8 ) ;
} else {
V_12 = - V_15 ;
}
break;
case V_112 :
if ( V_6 -> V_18 != V_30 && V_6 -> V_18 != V_45 ) {
V_12 = - V_15 ;
break;
}
if ( F_35 ( V_68 , ( T_3 T_2 * ) V_62 ) ) {
V_12 = - V_69 ;
break;
}
F_11 ( V_6 ) -> V_91 = V_68 ;
break;
case V_113 :
if ( F_35 ( V_68 , ( T_3 T_2 * ) V_62 ) ) {
V_12 = - V_69 ;
break;
}
if ( V_68 > V_130 ) {
V_12 = - V_15 ;
break;
}
if ( V_68 == V_131 ) {
struct V_126 * V_94 = V_8 -> V_94 ;
if ( ! V_94 || ! F_47 ( V_94 -> V_95 -> V_132 ) ) {
V_12 = - V_15 ;
break;
}
}
if ( V_68 )
F_43 ( V_114 , & V_8 -> V_31 ) ;
else
F_42 ( V_114 , & V_8 -> V_31 ) ;
break;
case V_115 :
if ( V_8 -> V_107 != V_108 &&
V_8 -> V_107 != V_109 ) {
V_12 = - V_15 ;
break;
}
V_103 . V_118 = V_133 ;
V_11 = F_4 (unsigned int, sizeof(pwr), optlen) ;
if ( F_41 ( ( char * ) & V_103 , V_62 , V_11 ) ) {
V_12 = - V_69 ;
break;
}
if ( V_103 . V_118 )
F_43 ( V_119 , & V_8 -> V_31 ) ;
else
F_42 ( V_119 , & V_8 -> V_31 ) ;
break;
case V_120 :
if ( ! V_121 ) {
V_12 = - V_98 ;
break;
}
if ( F_35 ( V_68 , ( T_3 T_2 * ) V_62 ) ) {
V_12 = - V_69 ;
break;
}
if ( V_68 > V_134 ) {
V_12 = - V_15 ;
break;
}
if ( V_8 -> V_37 != V_39 &&
V_8 -> V_37 != V_40 ) {
V_12 = - V_135 ;
break;
}
V_8 -> V_122 = ( V_136 ) V_68 ;
break;
default:
V_12 = - V_98 ;
break;
}
F_12 ( V_6 ) ;
return V_12 ;
}
static int F_48 ( struct V_137 * V_138 , struct V_1 * V_2 , struct V_139 * V_140 , T_4 V_11 )
{
struct V_2 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 = F_2 ( V_6 ) -> V_8 ;
int V_12 ;
F_3 ( L_5 , V_2 , V_6 ) ;
V_12 = F_49 ( V_6 ) ;
if ( V_12 )
return V_12 ;
if ( V_140 -> V_141 & V_142 )
return - V_135 ;
F_5 ( V_6 ) ;
if ( V_6 -> V_18 != V_32 ) {
F_12 ( V_6 ) ;
return - V_92 ;
}
V_12 = F_50 ( V_8 , V_140 , V_11 , V_6 -> V_143 ) ;
F_12 ( V_6 ) ;
return V_12 ;
}
static int F_51 ( struct V_137 * V_138 , struct V_1 * V_2 , struct V_139 * V_140 , T_4 V_11 , int V_31 )
{
struct V_2 * V_6 = V_2 -> V_6 ;
struct V_144 * V_145 = F_2 ( V_6 ) ;
int V_12 ;
F_5 ( V_6 ) ;
if ( V_6 -> V_18 == V_90 && F_11 ( V_6 ) -> V_91 ) {
V_6 -> V_18 = V_129 ;
V_145 -> V_8 -> V_29 = V_129 ;
F_52 ( V_145 -> V_8 ) ;
F_12 ( V_6 ) ;
return 0 ;
}
F_12 ( V_6 ) ;
if ( V_2 -> type == V_36 )
V_12 = F_53 ( V_138 , V_2 , V_140 , V_11 , V_31 ) ;
else
V_12 = F_54 ( V_138 , V_2 , V_140 , V_11 , V_31 ) ;
if ( V_145 -> V_8 -> V_37 != V_39 )
return V_12 ;
F_5 ( V_6 ) ;
if ( ! F_37 ( V_146 , & V_145 -> V_8 -> V_147 ) )
goto V_21;
if ( V_145 -> V_148 ) {
if ( ! F_55 ( V_6 , V_145 -> V_148 ) )
V_145 -> V_148 = NULL ;
else
goto V_21;
}
if ( F_56 ( & V_6 -> V_149 ) <= V_6 -> V_150 >> 1 )
F_57 ( V_145 -> V_8 , 0 ) ;
V_21:
F_12 ( V_6 ) ;
return V_12 ;
}
static void F_58 ( struct V_2 * V_6 )
{
if ( ! F_59 ( V_6 , V_151 ) || V_6 -> V_152 )
return;
F_3 ( L_6 , V_6 , V_6 -> V_18 ) ;
F_60 ( F_2 ( V_6 ) -> V_8 ) ;
F_61 ( V_6 , V_153 ) ;
F_62 ( V_6 ) ;
}
static int F_63 ( struct V_1 * V_2 , int V_154 )
{
struct V_2 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 = F_2 ( V_6 ) -> V_8 ;
int V_12 = 0 ;
F_3 ( L_5 , V_2 , V_6 ) ;
if ( ! V_6 )
return 0 ;
F_5 ( V_6 ) ;
if ( ! V_6 -> V_155 ) {
if ( V_8 -> V_37 == V_39 )
V_12 = F_64 ( V_6 ) ;
V_6 -> V_155 = V_156 ;
F_65 ( V_8 , 0 ) ;
if ( F_59 ( V_6 , V_157 ) && V_6 -> V_158 )
V_12 = F_15 ( V_6 , V_159 ,
V_6 -> V_158 ) ;
}
if ( ! V_12 && V_6 -> V_160 )
V_12 = - V_6 -> V_160 ;
F_12 ( V_6 ) ;
return V_12 ;
}
static int F_66 ( struct V_1 * V_2 )
{
struct V_2 * V_6 = V_2 -> V_6 ;
int V_12 ;
F_3 ( L_5 , V_2 , V_6 ) ;
if ( ! V_6 )
return 0 ;
V_12 = F_63 ( V_2 , 2 ) ;
F_67 ( V_6 ) ;
F_58 ( V_6 ) ;
return V_12 ;
}
static struct V_7 * F_68 ( void * V_161 )
{
struct V_2 * V_6 , * V_162 = V_161 ;
V_6 = F_69 ( F_70 ( V_162 ) , NULL , V_163 ,
V_164 ) ;
if ( ! V_6 )
return NULL ;
F_71 ( V_6 , V_163 ) ;
F_72 ( V_6 , V_162 ) ;
return F_2 ( V_6 ) -> V_8 ;
}
static int F_73 ( void * V_161 , struct V_165 * V_166 )
{
int V_12 ;
struct V_2 * V_6 = V_161 ;
struct V_144 * V_145 = F_2 ( V_6 ) ;
if ( V_145 -> V_148 )
return - V_167 ;
V_12 = F_55 ( V_6 , V_166 ) ;
if ( V_12 < 0 && V_145 -> V_8 -> V_37 == V_39 ) {
V_145 -> V_148 = V_166 ;
F_57 ( V_145 -> V_8 , 1 ) ;
V_12 = 0 ;
}
return V_12 ;
}
static void F_74 ( void * V_161 )
{
struct V_2 * V_6 = V_161 ;
F_58 ( V_6 ) ;
}
static void F_75 ( void * V_161 , int V_29 )
{
struct V_2 * V_6 = V_161 ;
V_6 -> V_18 = V_29 ;
}
static void F_76 ( struct V_2 * V_6 )
{
F_3 ( L_1 , V_6 ) ;
if ( F_2 ( V_6 ) -> V_148 ) {
F_77 ( F_2 ( V_6 ) -> V_148 ) ;
F_2 ( V_6 ) -> V_148 = NULL ;
}
F_78 ( & V_6 -> V_168 ) ;
F_78 ( & V_6 -> V_169 ) ;
}
static void F_72 ( struct V_2 * V_6 , struct V_2 * V_162 )
{
struct V_144 * V_145 = F_2 ( V_6 ) ;
struct V_7 * V_8 = V_145 -> V_8 ;
F_3 ( L_1 , V_6 ) ;
if ( V_162 ) {
struct V_7 * V_170 = F_2 ( V_162 ) -> V_8 ;
V_6 -> V_116 = V_162 -> V_116 ;
F_11 ( V_6 ) -> V_91 = F_11 ( V_162 ) -> V_91 ;
V_8 -> V_107 = V_170 -> V_107 ;
V_8 -> V_71 = V_170 -> V_71 ;
V_8 -> V_72 = V_170 -> V_72 ;
V_8 -> V_125 = V_170 -> V_125 ;
V_8 -> V_37 = V_170 -> V_37 ;
V_8 -> V_74 = V_170 -> V_74 ;
V_8 -> V_75 = V_170 -> V_75 ;
V_8 -> V_77 = V_170 -> V_77 ;
V_8 -> V_171 = V_170 -> V_171 ;
V_8 -> V_26 = V_170 -> V_26 ;
V_8 -> V_31 = V_170 -> V_31 ;
F_79 ( V_162 , V_6 ) ;
} else {
switch ( V_6 -> V_116 ) {
case V_117 :
V_8 -> V_107 = V_109 ;
break;
case V_172 :
V_8 -> V_107 = V_173 ;
break;
case V_35 :
case V_36 :
V_8 -> V_107 = V_108 ;
break;
}
V_8 -> V_71 = V_174 ;
V_8 -> V_72 = 0 ;
if ( ! V_41 && V_6 -> V_116 == V_36 ) {
V_8 -> V_37 = V_39 ;
F_43 ( V_124 , & V_8 -> V_125 ) ;
} else {
V_8 -> V_37 = V_38 ;
}
V_8 -> V_75 = V_175 ;
V_8 -> V_74 = V_176 ;
V_8 -> V_77 = V_177 ;
V_8 -> V_171 = V_177 ;
V_8 -> V_26 = V_79 ;
V_8 -> V_31 = 0 ;
F_43 ( V_119 , & V_8 -> V_31 ) ;
}
V_8 -> V_73 = V_178 ;
V_8 -> V_161 = V_6 ;
V_8 -> V_179 = & V_180 ;
}
static struct V_2 * F_69 ( struct V_181 * V_181 , struct V_1 * V_2 , int V_182 , T_5 V_183 )
{
struct V_2 * V_6 ;
struct V_7 * V_8 ;
V_6 = F_80 ( V_181 , V_184 , V_183 , & V_185 ) ;
if ( ! V_6 )
return NULL ;
F_81 ( V_2 , V_6 ) ;
F_82 ( & F_11 ( V_6 ) -> V_186 ) ;
V_6 -> V_187 = F_76 ;
V_6 -> V_188 = F_83 ( V_189 ) ;
F_84 ( V_6 , V_151 ) ;
V_6 -> V_190 = V_182 ;
V_6 -> V_18 = V_19 ;
V_8 = F_85 ( V_6 ) ;
if ( ! V_8 ) {
F_58 ( V_6 ) ;
return NULL ;
}
F_2 ( V_6 ) -> V_8 = V_8 ;
return V_6 ;
}
static int F_86 ( struct V_181 * V_181 , struct V_1 * V_2 , int V_191 ,
int V_192 )
{
struct V_2 * V_6 ;
F_3 ( L_7 , V_2 ) ;
V_2 -> V_29 = V_193 ;
if ( V_2 -> type != V_35 && V_2 -> type != V_36 &&
V_2 -> type != V_172 && V_2 -> type != V_117 )
return - V_194 ;
if ( V_2 -> type == V_117 && ! V_192 && ! F_7 ( V_195 ) )
return - V_196 ;
V_2 -> V_179 = & V_197 ;
V_6 = F_69 ( V_181 , V_2 , V_191 , V_164 ) ;
if ( ! V_6 )
return - V_167 ;
F_72 ( V_6 , NULL ) ;
return 0 ;
}
int T_6 F_87 ( void )
{
int V_12 ;
V_12 = F_88 ( & V_185 , 0 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_89 ( V_163 , & V_198 ) ;
if ( V_12 < 0 )
goto error;
F_90 ( L_8 ) ;
return 0 ;
error:
F_91 ( L_9 ) ;
F_92 ( & V_185 ) ;
return V_12 ;
}
void F_93 ( void )
{
if ( F_94 ( V_163 ) < 0 )
F_91 ( L_10 ) ;
F_92 ( & V_185 ) ;
}
