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
V_12 = F_8 ( V_8 , F_6 ( V_10 . V_16 ) ) ;
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
V_12 = F_14 ( V_8 , V_10 . V_17 , F_6 ( V_10 . V_16 ) ,
& V_10 . V_25 , V_10 . V_32 ) ;
if ( V_12 )
return V_12 ;
F_5 ( V_6 ) ;
V_12 = F_15 ( V_6 , V_33 ,
F_16 ( V_6 , V_31 & V_34 ) ) ;
F_12 ( V_6 ) ;
return V_12 ;
}
static int F_17 ( struct V_1 * V_2 , int V_35 )
{
struct V_2 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 = F_2 ( V_6 ) -> V_8 ;
int V_12 = 0 ;
F_3 ( L_2 , V_6 , V_35 ) ;
F_5 ( V_6 ) ;
if ( V_6 -> V_18 != V_30 ) {
V_12 = - V_20 ;
goto V_21;
}
if ( V_6 -> V_36 != V_37 && V_6 -> V_36 != V_38 ) {
V_12 = - V_15 ;
goto V_21;
}
switch ( V_8 -> V_39 ) {
case V_40 :
break;
case V_41 :
case V_42 :
if ( ! V_43 )
break;
default:
V_12 = - V_44 ;
goto V_21;
}
V_6 -> V_45 = V_35 ;
V_6 -> V_46 = 0 ;
V_8 -> V_29 = V_47 ;
V_6 -> V_18 = V_47 ;
V_21:
F_12 ( V_6 ) ;
return V_12 ;
}
static int F_18 ( struct V_1 * V_2 , struct V_1 * V_48 , int V_31 )
{
F_19 ( V_49 , V_50 ) ;
struct V_2 * V_6 = V_2 -> V_6 , * V_51 ;
long V_52 ;
int V_12 = 0 ;
F_20 ( V_6 , V_53 ) ;
V_52 = F_21 ( V_6 , V_31 & V_34 ) ;
F_3 ( L_3 , V_6 , V_52 ) ;
F_22 ( F_23 ( V_6 ) , & V_49 ) ;
while ( 1 ) {
F_24 ( V_54 ) ;
if ( V_6 -> V_18 != V_47 ) {
V_12 = - V_20 ;
break;
}
V_51 = F_25 ( V_6 , V_48 ) ;
if ( V_51 )
break;
if ( ! V_52 ) {
V_12 = - V_55 ;
break;
}
if ( F_26 ( V_50 ) ) {
V_12 = F_27 ( V_52 ) ;
break;
}
F_12 ( V_6 ) ;
V_52 = F_28 ( V_52 ) ;
F_20 ( V_6 , V_53 ) ;
}
F_29 ( V_56 ) ;
F_30 ( F_23 ( V_6 ) , & V_49 ) ;
if ( V_12 )
goto V_21;
V_48 -> V_29 = V_57 ;
F_3 ( L_4 , V_51 ) ;
V_21:
F_12 ( V_6 ) ;
return V_12 ;
}
static int F_31 ( struct V_1 * V_2 , struct V_3 * V_4 , int * V_11 , int V_58 )
{
struct V_9 * V_10 = (struct V_9 * ) V_4 ;
struct V_2 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 = F_2 ( V_6 ) -> V_8 ;
F_3 ( L_5 , V_2 , V_6 ) ;
V_4 -> V_13 = V_14 ;
* V_11 = sizeof( struct V_9 ) ;
if ( V_58 ) {
V_10 -> V_17 = V_8 -> V_22 ;
F_10 ( & V_10 -> V_25 , & F_11 ( V_6 ) -> V_59 ) ;
V_10 -> V_16 = F_32 ( V_8 -> V_60 ) ;
} else {
V_10 -> V_17 = V_8 -> V_61 ;
F_10 ( & V_10 -> V_25 , & F_11 ( V_6 ) -> V_28 ) ;
V_10 -> V_16 = F_32 ( V_8 -> V_62 ) ;
}
return 0 ;
}
static int F_33 ( struct V_1 * V_2 , int V_63 , char T_2 * V_64 , int T_2 * V_65 )
{
struct V_2 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 = F_2 ( V_6 ) -> V_8 ;
struct V_66 V_67 ;
struct V_68 V_69 ;
int V_11 , V_12 = 0 ;
T_3 V_70 ;
F_3 ( L_1 , V_6 ) ;
if ( F_34 ( V_11 , V_65 ) )
return - V_71 ;
F_5 ( V_6 ) ;
switch ( V_63 ) {
case V_72 :
memset ( & V_67 , 0 , sizeof( V_67 ) ) ;
V_67 . V_73 = V_8 -> V_73 ;
V_67 . V_74 = V_8 -> V_74 ;
V_67 . V_75 = V_8 -> V_75 ;
V_67 . V_39 = V_8 -> V_39 ;
V_67 . V_76 = V_8 -> V_76 ;
V_67 . V_77 = V_8 -> V_77 ;
V_67 . V_78 = V_8 -> V_79 ;
V_11 = F_4 (unsigned int, len, sizeof(opts)) ;
if ( F_35 ( V_64 , ( char * ) & V_67 , V_11 ) )
V_12 = - V_71 ;
break;
case V_80 :
switch ( V_8 -> V_26 ) {
case V_81 :
V_70 = V_82 ;
break;
case V_83 :
V_70 = V_82 | V_84 ;
break;
case V_85 :
V_70 = V_82 | V_84 |
V_86 ;
break;
default:
V_70 = 0 ;
break;
}
if ( F_36 ( V_87 , & V_8 -> V_31 ) )
V_70 |= V_88 ;
if ( F_36 ( V_89 , & V_8 -> V_31 ) )
V_70 |= V_90 ;
if ( F_37 ( V_70 , ( T_3 T_2 * ) V_64 ) )
V_12 = - V_71 ;
break;
case V_91 :
if ( V_6 -> V_18 != V_33 &&
! ( V_6 -> V_18 == V_92 &&
F_36 ( V_93 , & F_11 ( V_6 ) -> V_31 ) ) ) {
V_12 = - V_94 ;
break;
}
memset ( & V_69 , 0 , sizeof( V_69 ) ) ;
V_69 . V_95 = V_8 -> V_96 -> V_97 -> V_98 ;
memcpy ( V_69 . V_99 , V_8 -> V_96 -> V_97 -> V_99 , 3 ) ;
V_11 = F_4 (unsigned int, len, sizeof(cinfo)) ;
if ( F_35 ( V_64 , ( char * ) & V_69 , V_11 ) )
V_12 = - V_71 ;
break;
default:
V_12 = - V_100 ;
break;
}
F_12 ( V_6 ) ;
return V_12 ;
}
static int F_38 ( struct V_1 * V_2 , int V_101 , int V_63 , char T_2 * V_64 , int T_2 * V_65 )
{
struct V_2 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 = F_2 ( V_6 ) -> V_8 ;
struct V_102 V_103 ;
struct V_104 V_105 ;
int V_11 , V_12 = 0 ;
F_3 ( L_1 , V_6 ) ;
if ( V_101 == V_106 )
return F_33 ( V_2 , V_63 , V_64 , V_65 ) ;
if ( V_101 != V_107 )
return - V_100 ;
if ( F_34 ( V_11 , V_65 ) )
return - V_71 ;
F_5 ( V_6 ) ;
switch ( V_63 ) {
case V_108 :
if ( V_8 -> V_109 != V_110 &&
V_8 -> V_109 != V_111 ) {
V_12 = - V_15 ;
break;
}
memset ( & V_103 , 0 , sizeof( V_103 ) ) ;
if ( V_8 -> V_96 )
V_103 . V_101 = V_8 -> V_96 -> V_97 -> V_26 ;
else
V_103 . V_101 = V_8 -> V_26 ;
if ( V_6 -> V_18 == V_33 )
V_103 . V_112 = V_8 -> V_96 -> V_97 -> V_113 ;
V_11 = F_4 (unsigned int, len, sizeof(sec)) ;
if ( F_35 ( V_64 , ( char * ) & V_103 , V_11 ) )
V_12 = - V_71 ;
break;
case V_114 :
if ( V_6 -> V_18 != V_30 && V_6 -> V_18 != V_47 ) {
V_12 = - V_15 ;
break;
}
if ( F_37 ( F_36 ( V_93 , & F_11 ( V_6 ) -> V_31 ) ,
( T_3 T_2 * ) V_64 ) )
V_12 = - V_71 ;
break;
case V_115 :
if ( F_37 ( F_36 ( V_116 , & V_8 -> V_31 ) ,
( T_3 T_2 * ) V_64 ) )
V_12 = - V_71 ;
break;
case V_117 :
if ( V_6 -> V_36 != V_37 && V_6 -> V_36 != V_38
&& V_6 -> V_36 != V_118 ) {
V_12 = - V_15 ;
break;
}
V_105 . V_119 = F_36 ( V_120 , & V_8 -> V_31 ) ;
V_11 = F_4 (unsigned int, len, sizeof(pwr)) ;
if ( F_35 ( V_64 , ( char * ) & V_105 , V_11 ) )
V_12 = - V_71 ;
break;
case V_121 :
if ( ! V_122 ) {
V_12 = - V_100 ;
break;
}
if ( F_37 ( V_8 -> V_123 , ( T_3 T_2 * ) V_64 ) )
V_12 = - V_71 ;
break;
default:
V_12 = - V_100 ;
break;
}
F_12 ( V_6 ) ;
return V_12 ;
}
static int F_39 ( struct V_1 * V_2 , int V_63 , char T_2 * V_64 , unsigned int V_65 )
{
struct V_2 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 = F_2 ( V_6 ) -> V_8 ;
struct V_66 V_67 ;
int V_11 , V_12 = 0 ;
T_3 V_70 ;
F_3 ( L_1 , V_6 ) ;
F_5 ( V_6 ) ;
switch ( V_63 ) {
case V_72 :
if ( V_6 -> V_18 == V_33 ) {
V_12 = - V_15 ;
break;
}
V_67 . V_73 = V_8 -> V_73 ;
V_67 . V_74 = V_8 -> V_74 ;
V_67 . V_75 = V_8 -> V_75 ;
V_67 . V_39 = V_8 -> V_39 ;
V_67 . V_76 = V_8 -> V_76 ;
V_67 . V_77 = V_8 -> V_77 ;
V_67 . V_78 = V_8 -> V_79 ;
V_11 = F_4 (unsigned int, sizeof(opts), optlen) ;
if ( F_40 ( ( char * ) & V_67 , V_64 , V_11 ) ) {
V_12 = - V_71 ;
break;
}
if ( V_67 . V_78 > V_124 ) {
V_12 = - V_15 ;
break;
}
V_8 -> V_39 = V_67 . V_39 ;
switch ( V_8 -> V_39 ) {
case V_40 :
F_41 ( V_125 , & V_8 -> V_126 ) ;
break;
case V_41 :
case V_42 :
if ( ! V_43 )
break;
default:
V_12 = - V_15 ;
break;
}
V_8 -> V_73 = V_67 . V_73 ;
V_8 -> V_74 = V_67 . V_74 ;
V_8 -> V_76 = V_67 . V_76 ;
V_8 -> V_77 = V_67 . V_77 ;
V_8 -> V_79 = V_67 . V_78 ;
break;
case V_80 :
if ( F_34 ( V_70 , ( T_3 T_2 * ) V_64 ) ) {
V_12 = - V_71 ;
break;
}
if ( V_70 & V_82 )
V_8 -> V_26 = V_81 ;
if ( V_70 & V_84 )
V_8 -> V_26 = V_83 ;
if ( V_70 & V_86 )
V_8 -> V_26 = V_85 ;
if ( V_70 & V_88 )
F_42 ( V_87 , & V_8 -> V_31 ) ;
else
F_41 ( V_87 , & V_8 -> V_31 ) ;
if ( V_70 & V_90 )
F_42 ( V_89 , & V_8 -> V_31 ) ;
else
F_41 ( V_89 , & V_8 -> V_31 ) ;
break;
default:
V_12 = - V_100 ;
break;
}
F_12 ( V_6 ) ;
return V_12 ;
}
static int F_43 ( struct V_1 * V_2 , int V_101 , int V_63 , char T_2 * V_64 , unsigned int V_65 )
{
struct V_2 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 = F_2 ( V_6 ) -> V_8 ;
struct V_102 V_103 ;
struct V_104 V_105 ;
struct V_127 * V_96 ;
int V_11 , V_12 = 0 ;
T_3 V_70 ;
F_3 ( L_1 , V_6 ) ;
if ( V_101 == V_106 )
return F_39 ( V_2 , V_63 , V_64 , V_65 ) ;
if ( V_101 != V_107 )
return - V_100 ;
F_5 ( V_6 ) ;
switch ( V_63 ) {
case V_108 :
if ( V_8 -> V_109 != V_110 &&
V_8 -> V_109 != V_111 ) {
V_12 = - V_15 ;
break;
}
V_103 . V_101 = V_81 ;
V_11 = F_4 (unsigned int, sizeof(sec), optlen) ;
if ( F_40 ( ( char * ) & V_103 , V_64 , V_11 ) ) {
V_12 = - V_71 ;
break;
}
if ( V_103 . V_101 < V_81 ||
V_103 . V_101 > V_85 ) {
V_12 = - V_15 ;
break;
}
V_8 -> V_26 = V_103 . V_101 ;
if ( ! V_8 -> V_96 )
break;
V_96 = V_8 -> V_96 ;
if ( V_8 -> V_62 == V_128 ) {
if ( ! V_96 -> V_97 -> V_129 ) {
V_12 = - V_15 ;
break;
}
if ( F_44 ( V_96 , V_103 . V_101 ) )
break;
V_6 -> V_18 = V_130 ;
V_8 -> V_29 = V_130 ;
} else if ( ( V_6 -> V_18 == V_92 &&
F_36 ( V_93 , & F_11 ( V_6 ) -> V_31 ) ) ||
V_6 -> V_18 == V_33 ) {
if ( ! F_45 ( V_8 ) )
F_42 ( V_131 , & F_11 ( V_6 ) -> V_31 ) ;
else
V_6 -> V_132 ( V_6 ) ;
} else {
V_12 = - V_15 ;
}
break;
case V_114 :
if ( V_6 -> V_18 != V_30 && V_6 -> V_18 != V_47 ) {
V_12 = - V_15 ;
break;
}
if ( F_34 ( V_70 , ( T_3 T_2 * ) V_64 ) ) {
V_12 = - V_71 ;
break;
}
if ( V_70 )
F_42 ( V_93 , & F_11 ( V_6 ) -> V_31 ) ;
else
F_41 ( V_93 , & F_11 ( V_6 ) -> V_31 ) ;
break;
case V_115 :
if ( F_34 ( V_70 , ( T_3 T_2 * ) V_64 ) ) {
V_12 = - V_71 ;
break;
}
if ( V_70 > V_133 ) {
V_12 = - V_15 ;
break;
}
if ( V_70 == V_134 ) {
struct V_127 * V_96 = V_8 -> V_96 ;
if ( ! V_96 || ! F_46 ( V_96 -> V_97 -> V_135 ) ) {
V_12 = - V_15 ;
break;
}
}
if ( V_70 )
F_42 ( V_116 , & V_8 -> V_31 ) ;
else
F_41 ( V_116 , & V_8 -> V_31 ) ;
break;
case V_117 :
if ( V_8 -> V_109 != V_110 &&
V_8 -> V_109 != V_111 ) {
V_12 = - V_15 ;
break;
}
V_105 . V_119 = V_136 ;
V_11 = F_4 (unsigned int, sizeof(pwr), optlen) ;
if ( F_40 ( ( char * ) & V_105 , V_64 , V_11 ) ) {
V_12 = - V_71 ;
break;
}
if ( V_105 . V_119 )
F_42 ( V_120 , & V_8 -> V_31 ) ;
else
F_41 ( V_120 , & V_8 -> V_31 ) ;
break;
case V_121 :
if ( ! V_122 ) {
V_12 = - V_100 ;
break;
}
if ( F_34 ( V_70 , ( T_3 T_2 * ) V_64 ) ) {
V_12 = - V_71 ;
break;
}
if ( V_70 > V_137 ) {
V_12 = - V_15 ;
break;
}
if ( V_8 -> V_39 != V_41 &&
V_8 -> V_39 != V_42 ) {
V_12 = - V_138 ;
break;
}
V_8 -> V_123 = ( V_139 ) V_70 ;
break;
default:
V_12 = - V_100 ;
break;
}
F_12 ( V_6 ) ;
return V_12 ;
}
static int F_47 ( struct V_140 * V_141 , struct V_1 * V_2 , struct V_142 * V_143 , T_4 V_11 )
{
struct V_2 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 = F_2 ( V_6 ) -> V_8 ;
int V_12 ;
F_3 ( L_5 , V_2 , V_6 ) ;
V_12 = F_48 ( V_6 ) ;
if ( V_12 )
return V_12 ;
if ( V_143 -> V_144 & V_145 )
return - V_138 ;
if ( V_6 -> V_18 != V_33 )
return - V_94 ;
F_49 ( V_8 ) ;
V_12 = F_50 ( V_8 , V_143 , V_11 , V_6 -> V_146 ) ;
F_51 ( V_8 ) ;
return V_12 ;
}
static int F_52 ( struct V_140 * V_141 , struct V_1 * V_2 , struct V_142 * V_143 , T_4 V_11 , int V_31 )
{
struct V_2 * V_6 = V_2 -> V_6 ;
struct V_147 * V_148 = F_2 ( V_6 ) ;
int V_12 ;
F_5 ( V_6 ) ;
if ( V_6 -> V_18 == V_92 && F_36 ( V_93 ,
& F_11 ( V_6 ) -> V_31 ) ) {
V_6 -> V_18 = V_130 ;
V_148 -> V_8 -> V_29 = V_130 ;
F_53 ( V_148 -> V_8 ) ;
F_12 ( V_6 ) ;
return 0 ;
}
F_12 ( V_6 ) ;
if ( V_2 -> type == V_38 )
V_12 = F_54 ( V_141 , V_2 , V_143 , V_11 , V_31 ) ;
else
V_12 = F_55 ( V_141 , V_2 , V_143 , V_11 , V_31 ) ;
if ( V_148 -> V_8 -> V_39 != V_41 )
return V_12 ;
F_5 ( V_6 ) ;
if ( ! F_36 ( V_149 , & V_148 -> V_8 -> V_150 ) )
goto V_21;
if ( V_148 -> V_151 ) {
if ( ! F_56 ( V_6 , V_148 -> V_151 ) )
V_148 -> V_151 = NULL ;
else
goto V_21;
}
if ( F_57 ( & V_6 -> V_152 ) <= V_6 -> V_153 >> 1 )
F_58 ( V_148 -> V_8 , 0 ) ;
V_21:
F_12 ( V_6 ) ;
return V_12 ;
}
static void F_59 ( struct V_2 * V_6 )
{
if ( ! F_60 ( V_6 , V_154 ) || V_6 -> V_155 )
return;
F_3 ( L_6 , V_6 , F_61 ( V_6 -> V_18 ) ) ;
F_62 ( F_2 ( V_6 ) -> V_8 ) ;
F_63 ( V_6 , V_156 ) ;
F_64 ( V_6 ) ;
}
static int F_65 ( struct V_1 * V_2 , int V_157 )
{
struct V_2 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 ;
struct V_127 * V_96 ;
int V_12 = 0 ;
F_3 ( L_5 , V_2 , V_6 ) ;
if ( ! V_6 )
return 0 ;
V_8 = F_2 ( V_6 ) -> V_8 ;
V_96 = V_8 -> V_96 ;
if ( V_96 )
F_66 ( & V_96 -> V_158 ) ;
F_49 ( V_8 ) ;
F_5 ( V_6 ) ;
if ( ! V_6 -> V_159 ) {
if ( V_8 -> V_39 == V_41 )
V_12 = F_67 ( V_6 ) ;
V_6 -> V_159 = V_160 ;
F_12 ( V_6 ) ;
F_68 ( V_8 , 0 ) ;
F_5 ( V_6 ) ;
if ( F_60 ( V_6 , V_161 ) && V_6 -> V_162 )
V_12 = F_15 ( V_6 , V_163 ,
V_6 -> V_162 ) ;
}
if ( ! V_12 && V_6 -> V_164 )
V_12 = - V_6 -> V_164 ;
F_12 ( V_6 ) ;
F_51 ( V_8 ) ;
if ( V_96 )
F_69 ( & V_96 -> V_158 ) ;
return V_12 ;
}
static int F_70 ( struct V_1 * V_2 )
{
struct V_2 * V_6 = V_2 -> V_6 ;
int V_12 ;
F_3 ( L_5 , V_2 , V_6 ) ;
if ( ! V_6 )
return 0 ;
V_12 = F_65 ( V_2 , 2 ) ;
F_71 ( V_6 ) ;
F_59 ( V_6 ) ;
return V_12 ;
}
static struct V_7 * F_72 ( void * V_165 )
{
struct V_2 * V_6 , * V_166 = V_165 ;
V_6 = F_73 ( F_74 ( V_166 ) , NULL , V_167 ,
V_168 ) ;
if ( ! V_6 )
return NULL ;
F_75 ( V_6 , V_167 ) ;
F_76 ( V_6 , V_166 ) ;
return F_2 ( V_6 ) -> V_8 ;
}
static int F_77 ( void * V_165 , struct V_169 * V_170 )
{
int V_12 ;
struct V_2 * V_6 = V_165 ;
struct V_147 * V_148 = F_2 ( V_6 ) ;
F_5 ( V_6 ) ;
if ( V_148 -> V_151 ) {
V_12 = - V_171 ;
goto V_21;
}
V_12 = F_56 ( V_6 , V_170 ) ;
if ( V_12 < 0 && V_148 -> V_8 -> V_39 == V_41 ) {
V_148 -> V_151 = V_170 ;
F_58 ( V_148 -> V_8 , 1 ) ;
V_12 = 0 ;
}
V_21:
F_12 ( V_6 ) ;
return V_12 ;
}
static void F_78 ( void * V_165 )
{
struct V_2 * V_6 = V_165 ;
F_59 ( V_6 ) ;
}
static void F_79 ( void * V_165 , int V_29 )
{
struct V_2 * V_6 = V_165 ;
V_6 -> V_18 = V_29 ;
}
static struct V_169 * F_80 ( struct V_7 * V_8 ,
unsigned long V_11 , int V_172 )
{
struct V_169 * V_170 ;
int V_12 ;
F_51 ( V_8 ) ;
V_170 = F_81 ( V_8 -> V_6 , V_11 , V_172 , & V_12 ) ;
F_49 ( V_8 ) ;
if ( ! V_170 )
return F_82 ( V_12 ) ;
return V_170 ;
}
static void F_83 ( struct V_2 * V_6 )
{
F_3 ( L_1 , V_6 ) ;
F_84 ( F_2 ( V_6 ) -> V_8 ) ;
if ( F_2 ( V_6 ) -> V_151 ) {
F_85 ( F_2 ( V_6 ) -> V_151 ) ;
F_2 ( V_6 ) -> V_151 = NULL ;
}
F_86 ( & V_6 -> V_173 ) ;
F_86 ( & V_6 -> V_174 ) ;
}
static void F_76 ( struct V_2 * V_6 , struct V_2 * V_166 )
{
struct V_147 * V_148 = F_2 ( V_6 ) ;
struct V_7 * V_8 = V_148 -> V_8 ;
F_3 ( L_1 , V_6 ) ;
if ( V_166 ) {
struct V_7 * V_175 = F_2 ( V_166 ) -> V_8 ;
V_6 -> V_36 = V_166 -> V_36 ;
F_11 ( V_6 ) -> V_31 = F_11 ( V_166 ) -> V_31 ;
V_8 -> V_109 = V_175 -> V_109 ;
V_8 -> V_73 = V_175 -> V_73 ;
V_8 -> V_74 = V_175 -> V_74 ;
V_8 -> V_126 = V_175 -> V_126 ;
V_8 -> V_39 = V_175 -> V_39 ;
V_8 -> V_76 = V_175 -> V_76 ;
V_8 -> V_77 = V_175 -> V_77 ;
V_8 -> V_79 = V_175 -> V_79 ;
V_8 -> V_176 = V_175 -> V_176 ;
V_8 -> V_26 = V_175 -> V_26 ;
V_8 -> V_31 = V_175 -> V_31 ;
F_87 ( V_166 , V_6 ) ;
} else {
switch ( V_6 -> V_36 ) {
case V_118 :
V_8 -> V_109 = V_111 ;
break;
case V_177 :
V_8 -> V_109 = V_178 ;
break;
case V_37 :
case V_38 :
V_8 -> V_109 = V_110 ;
break;
}
V_8 -> V_73 = V_179 ;
V_8 -> V_74 = 0 ;
if ( ! V_43 && V_6 -> V_36 == V_38 ) {
V_8 -> V_39 = V_41 ;
F_42 ( V_125 , & V_8 -> V_126 ) ;
} else {
V_8 -> V_39 = V_40 ;
}
F_88 ( V_8 ) ;
}
V_8 -> V_75 = V_180 ;
V_8 -> V_165 = V_6 ;
V_8 -> V_181 = & V_182 ;
}
static struct V_2 * F_73 ( struct V_183 * V_183 , struct V_1 * V_2 , int V_184 , T_5 V_185 )
{
struct V_2 * V_6 ;
struct V_7 * V_8 ;
V_6 = F_89 ( V_183 , V_186 , V_185 , & V_187 ) ;
if ( ! V_6 )
return NULL ;
F_90 ( V_2 , V_6 ) ;
F_91 ( & F_11 ( V_6 ) -> V_188 ) ;
V_6 -> V_189 = F_83 ;
V_6 -> V_190 = V_191 ;
F_92 ( V_6 , V_154 ) ;
V_6 -> V_192 = V_184 ;
V_6 -> V_18 = V_19 ;
V_8 = F_93 () ;
if ( ! V_8 ) {
F_59 ( V_6 ) ;
return NULL ;
}
F_94 ( V_8 ) ;
V_8 -> V_6 = V_6 ;
F_2 ( V_6 ) -> V_8 = V_8 ;
return V_6 ;
}
static int F_95 ( struct V_183 * V_183 , struct V_1 * V_2 , int V_193 ,
int V_194 )
{
struct V_2 * V_6 ;
F_3 ( L_7 , V_2 ) ;
V_2 -> V_29 = V_195 ;
if ( V_2 -> type != V_37 && V_2 -> type != V_38 &&
V_2 -> type != V_177 && V_2 -> type != V_118 )
return - V_196 ;
if ( V_2 -> type == V_118 && ! V_194 && ! F_7 ( V_197 ) )
return - V_198 ;
V_2 -> V_181 = & V_199 ;
V_6 = F_73 ( V_183 , V_2 , V_193 , V_168 ) ;
if ( ! V_6 )
return - V_171 ;
F_76 ( V_6 , NULL ) ;
return 0 ;
}
int T_6 F_96 ( void )
{
int V_12 ;
V_12 = F_97 ( & V_187 , 0 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_98 ( V_167 , & V_200 ) ;
if ( V_12 < 0 )
goto error;
F_99 ( L_8 ) ;
return 0 ;
error:
F_100 ( L_9 ) ;
F_101 ( & V_187 ) ;
return V_12 ;
}
void F_102 ( void )
{
if ( F_103 ( V_167 ) < 0 )
F_100 ( L_10 ) ;
F_101 ( & V_187 ) ;
}
