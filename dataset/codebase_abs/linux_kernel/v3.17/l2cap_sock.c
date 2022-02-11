bool F_1 ( struct V_1 * V_2 )
{
return V_2 && V_2 -> V_3 == & V_4 ;
}
static int F_2 ( T_1 V_5 )
{
if ( ( V_5 & 0x0101 ) != 0x0001 )
return - V_6 ;
if ( V_5 < 0x1001 && ! F_3 ( V_7 ) )
return - V_8 ;
return 0 ;
}
static int F_4 ( T_1 V_5 )
{
if ( V_5 > 0x00ff )
return - V_6 ;
if ( V_5 <= 0x007f && ! F_3 ( V_7 ) )
return - V_8 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , struct V_9 * V_10 , int V_11 )
{
struct V_2 * V_12 = V_2 -> V_12 ;
struct V_13 * V_14 = F_6 ( V_12 ) -> V_14 ;
struct V_15 V_16 ;
int V_17 , V_18 = 0 ;
F_7 ( L_1 , V_12 ) ;
if ( ! V_10 || V_10 -> V_19 != V_20 )
return - V_6 ;
memset ( & V_16 , 0 , sizeof( V_16 ) ) ;
V_17 = F_8 (unsigned int, sizeof(la), alen) ;
memcpy ( & V_16 , V_10 , V_17 ) ;
if ( V_16 . V_21 && V_16 . V_22 )
return - V_6 ;
if ( ! F_9 ( V_16 . V_23 ) )
return - V_6 ;
if ( V_16 . V_21 ) {
V_14 -> V_24 = V_25 ;
V_14 -> V_26 = V_27 ;
}
if ( F_10 ( V_16 . V_23 ) ) {
if ( V_16 . V_21 &&
V_16 . V_21 != F_11 ( V_28 ) )
return - V_6 ;
}
F_12 ( V_12 ) ;
if ( V_12 -> V_29 != V_30 ) {
V_18 = - V_31 ;
goto V_32;
}
if ( V_16 . V_22 ) {
T_2 V_5 = F_13 ( V_16 . V_22 ) ;
if ( V_16 . V_23 == V_33 )
V_18 = F_2 ( V_5 ) ;
else
V_18 = F_4 ( V_5 ) ;
if ( V_18 )
goto V_32;
}
if ( V_16 . V_21 )
V_18 = F_14 ( V_14 , F_13 ( V_16 . V_21 ) ) ;
else
V_18 = F_15 ( V_14 , & V_16 . V_34 , V_16 . V_22 ) ;
if ( V_18 < 0 )
goto V_32;
switch ( V_14 -> V_24 ) {
case V_35 :
if ( F_13 ( V_16 . V_22 ) == V_36 )
V_14 -> V_37 = V_38 ;
break;
case V_39 :
if ( F_13 ( V_16 . V_22 ) == V_40 ||
F_13 ( V_16 . V_22 ) == V_41 )
V_14 -> V_37 = V_38 ;
break;
case V_42 :
V_14 -> V_37 = V_38 ;
break;
}
F_16 ( & V_14 -> V_43 , & V_16 . V_34 ) ;
V_14 -> V_44 = V_16 . V_23 ;
if ( V_14 -> V_5 && F_10 ( V_14 -> V_44 ) )
V_14 -> V_45 = V_46 ;
V_14 -> V_47 = V_48 ;
V_12 -> V_29 = V_48 ;
V_32:
F_17 ( V_12 ) ;
return V_18 ;
}
static int F_18 ( struct V_1 * V_2 , struct V_9 * V_10 ,
int V_11 , int V_49 )
{
struct V_2 * V_12 = V_2 -> V_12 ;
struct V_13 * V_14 = F_6 ( V_12 ) -> V_14 ;
struct V_15 V_16 ;
int V_17 , V_18 = 0 ;
F_7 ( L_1 , V_12 ) ;
if ( ! V_10 || V_11 < sizeof( V_10 -> V_19 ) ||
V_10 -> V_19 != V_20 )
return - V_6 ;
memset ( & V_16 , 0 , sizeof( V_16 ) ) ;
V_17 = F_8 (unsigned int, sizeof(la), alen) ;
memcpy ( & V_16 , V_10 , V_17 ) ;
if ( V_16 . V_21 && V_16 . V_22 )
return - V_6 ;
if ( ! F_9 ( V_16 . V_23 ) )
return - V_6 ;
if ( V_14 -> V_44 == V_33 && F_19 ( & V_14 -> V_43 , V_50 ) &&
F_10 ( V_16 . V_23 ) ) {
if ( V_14 -> V_51 != V_28 ||
V_16 . V_21 != F_11 ( V_28 ) )
return - V_6 ;
V_14 -> V_44 = V_52 ;
}
if ( V_14 -> V_44 != V_33 && V_16 . V_23 == V_33 )
return - V_6 ;
if ( F_10 ( V_16 . V_23 ) ) {
if ( V_16 . V_21 &&
V_16 . V_21 != F_11 ( V_28 ) )
return - V_6 ;
}
if ( V_14 -> V_5 && F_10 ( V_14 -> V_44 ) )
V_14 -> V_45 = V_46 ;
V_18 = F_20 ( V_14 , V_16 . V_22 , F_13 ( V_16 . V_21 ) ,
& V_16 . V_34 , V_16 . V_23 ) ;
if ( V_18 )
return V_18 ;
F_12 ( V_12 ) ;
V_18 = F_21 ( V_12 , V_53 ,
F_22 ( V_12 , V_49 & V_54 ) ) ;
F_17 ( V_12 ) ;
return V_18 ;
}
static int F_23 ( struct V_1 * V_2 , int V_55 )
{
struct V_2 * V_12 = V_2 -> V_12 ;
struct V_13 * V_14 = F_6 ( V_12 ) -> V_14 ;
int V_18 = 0 ;
F_7 ( L_2 , V_12 , V_55 ) ;
F_12 ( V_12 ) ;
if ( V_12 -> V_29 != V_48 ) {
V_18 = - V_31 ;
goto V_32;
}
if ( V_12 -> V_56 != V_57 && V_12 -> V_56 != V_58 ) {
V_18 = - V_6 ;
goto V_32;
}
switch ( V_14 -> V_45 ) {
case V_59 :
case V_46 :
break;
case V_60 :
case V_61 :
if ( ! V_62 )
break;
default:
V_18 = - V_63 ;
goto V_32;
}
V_12 -> V_64 = V_55 ;
V_12 -> V_65 = 0 ;
V_14 -> V_47 = V_66 ;
V_12 -> V_29 = V_66 ;
V_32:
F_17 ( V_12 ) ;
return V_18 ;
}
static int F_24 ( struct V_1 * V_2 , struct V_1 * V_67 ,
int V_49 )
{
F_25 ( V_68 , V_69 ) ;
struct V_2 * V_12 = V_2 -> V_12 , * V_70 ;
long V_71 ;
int V_18 = 0 ;
F_26 ( V_12 , V_72 ) ;
V_71 = F_27 ( V_12 , V_49 & V_54 ) ;
F_7 ( L_3 , V_12 , V_71 ) ;
F_28 ( F_29 ( V_12 ) , & V_68 ) ;
while ( 1 ) {
F_30 ( V_73 ) ;
if ( V_12 -> V_29 != V_66 ) {
V_18 = - V_31 ;
break;
}
V_70 = F_31 ( V_12 , V_67 ) ;
if ( V_70 )
break;
if ( ! V_71 ) {
V_18 = - V_74 ;
break;
}
if ( F_32 ( V_69 ) ) {
V_18 = F_33 ( V_71 ) ;
break;
}
F_17 ( V_12 ) ;
V_71 = F_34 ( V_71 ) ;
F_26 ( V_12 , V_72 ) ;
}
F_35 ( V_75 ) ;
F_36 ( F_29 ( V_12 ) , & V_68 ) ;
if ( V_18 )
goto V_32;
V_67 -> V_47 = V_76 ;
F_7 ( L_4 , V_70 ) ;
V_32:
F_17 ( V_12 ) ;
return V_18 ;
}
static int F_37 ( struct V_1 * V_2 , struct V_9 * V_10 ,
int * V_17 , int V_77 )
{
struct V_15 * V_16 = (struct V_15 * ) V_10 ;
struct V_2 * V_12 = V_2 -> V_12 ;
struct V_13 * V_14 = F_6 ( V_12 ) -> V_14 ;
F_7 ( L_5 , V_2 , V_12 ) ;
if ( V_77 && V_12 -> V_29 != V_53 &&
V_12 -> V_29 != V_78 && V_12 -> V_29 != V_79 &&
V_12 -> V_29 != V_80 )
return - V_81 ;
memset ( V_16 , 0 , sizeof( struct V_15 ) ) ;
V_10 -> V_19 = V_20 ;
* V_17 = sizeof( struct V_15 ) ;
V_16 -> V_22 = V_14 -> V_5 ;
if ( V_77 ) {
F_16 ( & V_16 -> V_34 , & V_14 -> V_82 ) ;
V_16 -> V_21 = F_11 ( V_14 -> V_83 ) ;
V_16 -> V_23 = V_14 -> V_84 ;
} else {
F_16 ( & V_16 -> V_34 , & V_14 -> V_43 ) ;
V_16 -> V_21 = F_11 ( V_14 -> V_51 ) ;
V_16 -> V_23 = V_14 -> V_44 ;
}
return 0 ;
}
static int F_38 ( struct V_1 * V_2 , int V_85 ,
char T_3 * V_86 , int T_3 * V_87 )
{
struct V_2 * V_12 = V_2 -> V_12 ;
struct V_13 * V_14 = F_6 ( V_12 ) -> V_14 ;
struct V_88 V_89 ;
struct V_90 V_91 ;
int V_17 , V_18 = 0 ;
T_4 V_92 ;
F_7 ( L_1 , V_12 ) ;
if ( F_39 ( V_17 , V_87 ) )
return - V_93 ;
F_12 ( V_12 ) ;
switch ( V_85 ) {
case V_94 :
if ( F_10 ( V_14 -> V_44 ) &&
V_14 -> V_51 != V_28 ) {
V_18 = - V_6 ;
break;
}
memset ( & V_89 , 0 , sizeof( V_89 ) ) ;
V_89 . V_95 = V_14 -> V_95 ;
V_89 . V_26 = V_14 -> V_26 ;
V_89 . V_96 = V_14 -> V_96 ;
V_89 . V_45 = V_14 -> V_45 ;
V_89 . V_97 = V_14 -> V_97 ;
V_89 . V_98 = V_14 -> V_98 ;
V_89 . V_99 = V_14 -> V_100 ;
V_17 = F_8 (unsigned int, len, sizeof(opts)) ;
if ( F_40 ( V_86 , ( char * ) & V_89 , V_17 ) )
V_18 = - V_93 ;
break;
case V_101 :
switch ( V_14 -> V_37 ) {
case V_102 :
V_92 = V_103 ;
break;
case V_104 :
V_92 = V_103 | V_105 ;
break;
case V_106 :
V_92 = V_103 | V_105 |
V_107 ;
break;
case V_108 :
V_92 = V_103 | V_105 |
V_107 | V_109 ;
break;
default:
V_92 = 0 ;
break;
}
if ( F_41 ( V_110 , & V_14 -> V_49 ) )
V_92 |= V_111 ;
if ( F_41 ( V_112 , & V_14 -> V_49 ) )
V_92 |= V_113 ;
if ( F_42 ( V_92 , ( T_4 T_3 * ) V_86 ) )
V_18 = - V_93 ;
break;
case V_114 :
if ( V_12 -> V_29 != V_53 &&
! ( V_12 -> V_29 == V_79 &&
F_41 ( V_115 , & F_43 ( V_12 ) -> V_49 ) ) ) {
V_18 = - V_81 ;
break;
}
memset ( & V_91 , 0 , sizeof( V_91 ) ) ;
V_91 . V_116 = V_14 -> V_117 -> V_118 -> V_119 ;
memcpy ( V_91 . V_120 , V_14 -> V_117 -> V_118 -> V_120 , 3 ) ;
V_17 = F_8 (unsigned int, len, sizeof(cinfo)) ;
if ( F_40 ( V_86 , ( char * ) & V_91 , V_17 ) )
V_18 = - V_93 ;
break;
default:
V_18 = - V_121 ;
break;
}
F_17 ( V_12 ) ;
return V_18 ;
}
static int F_44 ( struct V_1 * V_2 , int V_122 , int V_85 ,
char T_3 * V_86 , int T_3 * V_87 )
{
struct V_2 * V_12 = V_2 -> V_12 ;
struct V_13 * V_14 = F_6 ( V_12 ) -> V_14 ;
struct V_123 V_124 ;
struct V_125 V_126 ;
int V_17 , V_18 = 0 ;
F_7 ( L_1 , V_12 ) ;
if ( V_122 == V_127 )
return F_38 ( V_2 , V_85 , V_86 , V_87 ) ;
if ( V_122 != V_128 )
return - V_121 ;
if ( F_39 ( V_17 , V_87 ) )
return - V_93 ;
F_12 ( V_12 ) ;
switch ( V_85 ) {
case V_129 :
if ( V_14 -> V_24 != V_39 &&
V_14 -> V_24 != V_25 &&
V_14 -> V_24 != V_42 ) {
V_18 = - V_6 ;
break;
}
memset ( & V_124 , 0 , sizeof( V_124 ) ) ;
if ( V_14 -> V_117 ) {
V_124 . V_122 = V_14 -> V_117 -> V_118 -> V_37 ;
if ( V_12 -> V_29 == V_53 )
V_124 . V_130 = V_14 -> V_117 -> V_118 -> V_131 ;
} else {
V_124 . V_122 = V_14 -> V_37 ;
}
V_17 = F_8 (unsigned int, len, sizeof(sec)) ;
if ( F_40 ( V_86 , ( char * ) & V_124 , V_17 ) )
V_18 = - V_93 ;
break;
case V_132 :
if ( V_12 -> V_29 != V_48 && V_12 -> V_29 != V_66 ) {
V_18 = - V_6 ;
break;
}
if ( F_42 ( F_41 ( V_115 , & F_43 ( V_12 ) -> V_49 ) ,
( T_4 T_3 * ) V_86 ) )
V_18 = - V_93 ;
break;
case V_133 :
if ( F_42 ( F_41 ( V_134 , & V_14 -> V_49 ) ,
( T_4 T_3 * ) V_86 ) )
V_18 = - V_93 ;
break;
case V_135 :
if ( V_12 -> V_56 != V_57 && V_12 -> V_56 != V_58
&& V_12 -> V_56 != V_136 ) {
V_18 = - V_6 ;
break;
}
V_126 . V_137 = F_41 ( V_138 , & V_14 -> V_49 ) ;
V_17 = F_8 (unsigned int, len, sizeof(pwr)) ;
if ( F_40 ( V_86 , ( char * ) & V_126 , V_17 ) )
V_18 = - V_93 ;
break;
case V_139 :
if ( F_42 ( V_14 -> V_140 , ( T_4 T_3 * ) V_86 ) )
V_18 = - V_93 ;
break;
case V_141 :
if ( ! F_10 ( V_14 -> V_44 ) ) {
V_18 = - V_6 ;
break;
}
if ( V_12 -> V_29 != V_53 ) {
V_18 = - V_81 ;
break;
}
if ( F_42 ( V_14 -> V_26 , ( T_1 T_3 * ) V_86 ) )
V_18 = - V_93 ;
break;
case V_142 :
if ( ! F_10 ( V_14 -> V_44 ) ) {
V_18 = - V_6 ;
break;
}
if ( F_42 ( V_14 -> V_95 , ( T_1 T_3 * ) V_86 ) )
V_18 = - V_93 ;
break;
default:
V_18 = - V_121 ;
break;
}
F_17 ( V_12 ) ;
return V_18 ;
}
static bool F_45 ( struct V_13 * V_14 , T_1 V_143 )
{
switch ( V_14 -> V_51 ) {
case V_28 :
if ( V_143 < V_144 )
return false ;
break;
default:
if ( V_143 < V_145 )
return false ;
}
return true ;
}
static int F_46 ( struct V_1 * V_2 , int V_85 ,
char T_3 * V_86 , unsigned int V_87 )
{
struct V_2 * V_12 = V_2 -> V_12 ;
struct V_13 * V_14 = F_6 ( V_12 ) -> V_14 ;
struct V_88 V_89 ;
int V_17 , V_18 = 0 ;
T_4 V_92 ;
F_7 ( L_1 , V_12 ) ;
F_12 ( V_12 ) ;
switch ( V_85 ) {
case V_94 :
if ( F_10 ( V_14 -> V_44 ) ) {
V_18 = - V_6 ;
break;
}
if ( V_12 -> V_29 == V_53 ) {
V_18 = - V_6 ;
break;
}
V_89 . V_95 = V_14 -> V_95 ;
V_89 . V_26 = V_14 -> V_26 ;
V_89 . V_96 = V_14 -> V_96 ;
V_89 . V_45 = V_14 -> V_45 ;
V_89 . V_97 = V_14 -> V_97 ;
V_89 . V_98 = V_14 -> V_98 ;
V_89 . V_99 = V_14 -> V_100 ;
V_17 = F_8 (unsigned int, sizeof(opts), optlen) ;
if ( F_47 ( ( char * ) & V_89 , V_86 , V_17 ) ) {
V_18 = - V_93 ;
break;
}
if ( V_89 . V_99 > V_146 ) {
V_18 = - V_6 ;
break;
}
if ( ! F_45 ( V_14 , V_89 . V_95 ) ) {
V_18 = - V_6 ;
break;
}
V_14 -> V_45 = V_89 . V_45 ;
switch ( V_14 -> V_45 ) {
case V_46 :
break;
case V_59 :
F_48 ( V_147 , & V_14 -> V_148 ) ;
break;
case V_60 :
case V_61 :
if ( ! V_62 )
break;
default:
V_18 = - V_6 ;
break;
}
V_14 -> V_95 = V_89 . V_95 ;
V_14 -> V_26 = V_89 . V_26 ;
V_14 -> V_97 = V_89 . V_97 ;
V_14 -> V_98 = V_89 . V_98 ;
V_14 -> V_100 = V_89 . V_99 ;
V_14 -> V_96 = V_89 . V_96 ;
break;
case V_101 :
if ( F_39 ( V_92 , ( T_4 T_3 * ) V_86 ) ) {
V_18 = - V_93 ;
break;
}
if ( V_92 & V_109 ) {
V_18 = - V_6 ;
break;
}
if ( V_92 & V_103 )
V_14 -> V_37 = V_102 ;
if ( V_92 & V_105 )
V_14 -> V_37 = V_104 ;
if ( V_92 & V_107 )
V_14 -> V_37 = V_106 ;
if ( V_92 & V_111 )
F_49 ( V_110 , & V_14 -> V_49 ) ;
else
F_48 ( V_110 , & V_14 -> V_49 ) ;
if ( V_92 & V_113 )
F_49 ( V_112 , & V_14 -> V_49 ) ;
else
F_48 ( V_112 , & V_14 -> V_49 ) ;
break;
default:
V_18 = - V_121 ;
break;
}
F_17 ( V_12 ) ;
return V_18 ;
}
static int F_50 ( struct V_1 * V_2 , int V_122 , int V_85 ,
char T_3 * V_86 , unsigned int V_87 )
{
struct V_2 * V_12 = V_2 -> V_12 ;
struct V_13 * V_14 = F_6 ( V_12 ) -> V_14 ;
struct V_123 V_124 ;
struct V_125 V_126 ;
struct V_149 * V_117 ;
int V_17 , V_18 = 0 ;
T_4 V_92 ;
F_7 ( L_1 , V_12 ) ;
if ( V_122 == V_127 )
return F_46 ( V_2 , V_85 , V_86 , V_87 ) ;
if ( V_122 != V_128 )
return - V_121 ;
F_12 ( V_12 ) ;
switch ( V_85 ) {
case V_129 :
if ( V_14 -> V_24 != V_39 &&
V_14 -> V_24 != V_25 &&
V_14 -> V_24 != V_42 ) {
V_18 = - V_6 ;
break;
}
V_124 . V_122 = V_102 ;
V_17 = F_8 (unsigned int, sizeof(sec), optlen) ;
if ( F_47 ( ( char * ) & V_124 , V_86 , V_17 ) ) {
V_18 = - V_93 ;
break;
}
if ( V_124 . V_122 < V_102 ||
V_124 . V_122 > V_106 ) {
V_18 = - V_6 ;
break;
}
V_14 -> V_37 = V_124 . V_122 ;
if ( ! V_14 -> V_117 )
break;
V_117 = V_14 -> V_117 ;
if ( V_14 -> V_51 == V_28 ) {
if ( F_51 ( V_117 -> V_118 , V_124 . V_122 ) )
break;
V_12 -> V_29 = V_80 ;
V_14 -> V_47 = V_80 ;
} else if ( ( V_12 -> V_29 == V_79 &&
F_41 ( V_115 , & F_43 ( V_12 ) -> V_49 ) ) ||
V_12 -> V_29 == V_53 ) {
if ( ! F_52 ( V_14 , true ) )
F_49 ( V_150 , & F_43 ( V_12 ) -> V_49 ) ;
else
V_12 -> V_151 ( V_12 ) ;
} else {
V_18 = - V_6 ;
}
break;
case V_132 :
if ( V_12 -> V_29 != V_48 && V_12 -> V_29 != V_66 ) {
V_18 = - V_6 ;
break;
}
if ( F_39 ( V_92 , ( T_4 T_3 * ) V_86 ) ) {
V_18 = - V_93 ;
break;
}
if ( V_92 ) {
F_49 ( V_115 , & F_43 ( V_12 ) -> V_49 ) ;
F_49 ( V_152 , & V_14 -> V_49 ) ;
} else {
F_48 ( V_115 , & F_43 ( V_12 ) -> V_49 ) ;
F_48 ( V_152 , & V_14 -> V_49 ) ;
}
break;
case V_133 :
if ( F_39 ( V_92 , ( T_4 T_3 * ) V_86 ) ) {
V_18 = - V_93 ;
break;
}
if ( V_92 > V_153 ) {
V_18 = - V_6 ;
break;
}
if ( V_92 == V_154 ) {
V_117 = V_14 -> V_117 ;
if ( ! V_117 || ! F_53 ( V_117 -> V_118 -> V_155 ) ) {
V_18 = - V_6 ;
break;
}
}
if ( V_92 )
F_49 ( V_134 , & V_14 -> V_49 ) ;
else
F_48 ( V_134 , & V_14 -> V_49 ) ;
break;
case V_135 :
if ( V_14 -> V_24 != V_39 &&
V_14 -> V_24 != V_42 ) {
V_18 = - V_6 ;
break;
}
V_126 . V_137 = V_156 ;
V_17 = F_8 (unsigned int, sizeof(pwr), optlen) ;
if ( F_47 ( ( char * ) & V_126 , V_86 , V_17 ) ) {
V_18 = - V_93 ;
break;
}
if ( V_126 . V_137 )
F_49 ( V_138 , & V_14 -> V_49 ) ;
else
F_48 ( V_138 , & V_14 -> V_49 ) ;
break;
case V_139 :
if ( F_39 ( V_92 , ( T_4 T_3 * ) V_86 ) ) {
V_18 = - V_93 ;
break;
}
if ( V_92 > V_157 ) {
V_18 = - V_6 ;
break;
}
if ( V_14 -> V_45 != V_60 &&
V_14 -> V_45 != V_61 ) {
V_18 = - V_63 ;
break;
}
V_14 -> V_140 = ( V_158 ) V_92 ;
if ( V_12 -> V_29 == V_53 &&
V_14 -> V_159 == V_160 )
F_54 ( V_14 ) ;
break;
case V_141 :
if ( ! F_10 ( V_14 -> V_44 ) ) {
V_18 = - V_6 ;
break;
}
V_18 = - V_161 ;
break;
case V_142 :
if ( ! F_10 ( V_14 -> V_44 ) ) {
V_18 = - V_6 ;
break;
}
if ( V_12 -> V_29 == V_53 ) {
V_18 = - V_162 ;
break;
}
if ( F_39 ( V_92 , ( T_4 T_3 * ) V_86 ) ) {
V_18 = - V_93 ;
break;
}
V_14 -> V_95 = V_92 ;
break;
default:
V_18 = - V_121 ;
break;
}
F_17 ( V_12 ) ;
return V_18 ;
}
static int F_55 ( struct V_163 * V_164 , struct V_1 * V_2 ,
struct V_165 * V_166 , T_5 V_17 )
{
struct V_2 * V_12 = V_2 -> V_12 ;
struct V_13 * V_14 = F_6 ( V_12 ) -> V_14 ;
int V_18 ;
F_7 ( L_5 , V_2 , V_12 ) ;
V_18 = F_56 ( V_12 ) ;
if ( V_18 )
return V_18 ;
if ( V_166 -> V_167 & V_168 )
return - V_63 ;
if ( V_12 -> V_29 != V_53 )
return - V_81 ;
F_12 ( V_12 ) ;
V_18 = F_57 ( V_12 , V_166 -> V_167 ) ;
F_17 ( V_12 ) ;
if ( V_18 )
return V_18 ;
F_58 ( V_14 ) ;
V_18 = F_59 ( V_14 , V_166 , V_17 ) ;
F_60 ( V_14 ) ;
return V_18 ;
}
static int F_61 ( struct V_163 * V_164 , struct V_1 * V_2 ,
struct V_165 * V_166 , T_5 V_17 , int V_49 )
{
struct V_2 * V_12 = V_2 -> V_12 ;
struct V_169 * V_170 = F_6 ( V_12 ) ;
int V_18 ;
F_12 ( V_12 ) ;
if ( V_12 -> V_29 == V_79 && F_41 ( V_115 ,
& F_43 ( V_12 ) -> V_49 ) ) {
if ( F_10 ( V_170 -> V_14 -> V_44 ) ) {
V_12 -> V_29 = V_53 ;
V_170 -> V_14 -> V_47 = V_53 ;
F_62 ( V_170 -> V_14 ) ;
} else {
V_12 -> V_29 = V_80 ;
V_170 -> V_14 -> V_47 = V_80 ;
F_63 ( V_170 -> V_14 ) ;
}
V_18 = 0 ;
goto V_32;
}
F_17 ( V_12 ) ;
if ( V_2 -> type == V_58 )
V_18 = F_64 ( V_164 , V_2 , V_166 , V_17 , V_49 ) ;
else
V_18 = F_65 ( V_164 , V_2 , V_166 , V_17 , V_49 ) ;
if ( V_170 -> V_14 -> V_45 != V_60 )
return V_18 ;
F_12 ( V_12 ) ;
if ( ! F_41 ( V_171 , & V_170 -> V_14 -> V_172 ) )
goto V_32;
if ( V_170 -> V_173 ) {
if ( ! F_66 ( V_12 , V_170 -> V_173 ) )
V_170 -> V_173 = NULL ;
else
goto V_32;
}
if ( F_67 ( & V_12 -> V_174 ) <= V_12 -> V_175 >> 1 )
F_68 ( V_170 -> V_14 , 0 ) ;
V_32:
F_17 ( V_12 ) ;
return V_18 ;
}
static void F_69 ( struct V_2 * V_12 )
{
if ( ! F_70 ( V_12 , V_176 ) || V_12 -> V_177 )
return;
F_7 ( L_6 , V_12 , F_71 ( V_12 -> V_29 ) ) ;
F_72 ( F_6 ( V_12 ) -> V_14 ) ;
F_73 ( V_12 , V_178 ) ;
F_74 ( V_12 ) ;
}
static int F_75 ( struct V_2 * V_12 )
{
struct V_13 * V_14 = F_6 ( V_12 ) -> V_14 ;
F_25 ( V_68 , V_69 ) ;
int V_18 = 0 ;
int V_71 = V_179 / 5 ;
F_76 ( F_29 ( V_12 ) , & V_68 ) ;
F_30 ( V_73 ) ;
while ( V_14 -> V_180 > 0 && V_14 -> V_117 ) {
if ( ! V_71 )
V_71 = V_179 / 5 ;
if ( F_32 ( V_69 ) ) {
V_18 = F_33 ( V_71 ) ;
break;
}
F_17 ( V_12 ) ;
V_71 = F_34 ( V_71 ) ;
F_12 ( V_12 ) ;
F_30 ( V_73 ) ;
V_18 = F_56 ( V_12 ) ;
if ( V_18 )
break;
}
F_30 ( V_75 ) ;
F_36 ( F_29 ( V_12 ) , & V_68 ) ;
return V_18 ;
}
static int F_77 ( struct V_1 * V_2 , int V_181 )
{
struct V_2 * V_12 = V_2 -> V_12 ;
struct V_13 * V_14 ;
struct V_149 * V_117 ;
int V_18 = 0 ;
F_7 ( L_5 , V_2 , V_12 ) ;
if ( ! V_12 )
return 0 ;
V_14 = F_6 ( V_12 ) -> V_14 ;
V_117 = V_14 -> V_117 ;
if ( V_117 )
F_78 ( & V_117 -> V_182 ) ;
F_58 ( V_14 ) ;
F_12 ( V_12 ) ;
if ( ! V_12 -> V_183 ) {
if ( V_14 -> V_45 == V_60 )
V_18 = F_75 ( V_12 ) ;
V_12 -> V_183 = V_184 ;
F_17 ( V_12 ) ;
F_79 ( V_14 , 0 ) ;
F_12 ( V_12 ) ;
if ( F_70 ( V_12 , V_185 ) && V_12 -> V_186 &&
! ( V_69 -> V_49 & V_187 ) )
V_18 = F_21 ( V_12 , V_188 ,
V_12 -> V_186 ) ;
}
if ( ! V_18 && V_12 -> V_189 )
V_18 = - V_12 -> V_189 ;
F_17 ( V_12 ) ;
F_60 ( V_14 ) ;
if ( V_117 )
F_80 ( & V_117 -> V_182 ) ;
return V_18 ;
}
static int F_81 ( struct V_1 * V_2 )
{
struct V_2 * V_12 = V_2 -> V_12 ;
int V_18 ;
F_7 ( L_5 , V_2 , V_12 ) ;
if ( ! V_12 )
return 0 ;
F_82 ( & V_190 , V_12 ) ;
V_18 = F_77 ( V_2 , 2 ) ;
F_83 ( V_12 ) ;
F_69 ( V_12 ) ;
return V_18 ;
}
static void F_84 ( struct V_2 * V_191 )
{
struct V_2 * V_12 ;
F_7 ( L_7 , V_191 ) ;
while ( ( V_12 = F_31 ( V_191 , NULL ) ) ) {
struct V_13 * V_14 = F_6 ( V_12 ) -> V_14 ;
F_58 ( V_14 ) ;
F_85 ( V_14 ) ;
F_79 ( V_14 , V_192 ) ;
F_60 ( V_14 ) ;
F_69 ( V_12 ) ;
}
}
static struct V_13 * F_86 ( struct V_13 * V_14 )
{
struct V_2 * V_12 , * V_191 = V_14 -> V_193 ;
F_12 ( V_191 ) ;
if ( F_87 ( V_191 ) ) {
F_7 ( L_8 , V_191 -> V_65 ) ;
F_17 ( V_191 ) ;
return NULL ;
}
V_12 = F_88 ( F_89 ( V_191 ) , NULL , V_194 ,
V_195 ) ;
if ( ! V_12 ) {
F_17 ( V_191 ) ;
return NULL ;
}
F_90 ( V_12 , V_194 ) ;
F_91 ( V_12 , V_191 ) ;
F_92 ( V_191 , V_12 ) ;
F_17 ( V_191 ) ;
return F_6 ( V_12 ) -> V_14 ;
}
static int F_93 ( struct V_13 * V_14 , struct V_196 * V_197 )
{
struct V_2 * V_12 = V_14 -> V_193 ;
int V_18 ;
F_12 ( V_12 ) ;
if ( F_6 ( V_12 ) -> V_173 ) {
V_18 = - V_198 ;
goto V_32;
}
V_18 = F_66 ( V_12 , V_197 ) ;
if ( V_18 < 0 && V_14 -> V_45 == V_60 ) {
F_6 ( V_12 ) -> V_173 = V_197 ;
F_68 ( V_14 , 1 ) ;
V_18 = 0 ;
}
V_32:
F_17 ( V_12 ) ;
return V_18 ;
}
static void F_94 ( struct V_13 * V_14 )
{
struct V_2 * V_12 = V_14 -> V_193 ;
F_69 ( V_12 ) ;
}
static void F_95 ( struct V_13 * V_14 , int V_18 )
{
struct V_2 * V_12 = V_14 -> V_193 ;
struct V_2 * V_191 ;
F_12 ( V_12 ) ;
V_191 = F_43 ( V_12 ) -> V_191 ;
F_73 ( V_12 , V_176 ) ;
switch ( V_14 -> V_47 ) {
case V_30 :
case V_48 :
case V_188 :
break;
case V_66 :
F_84 ( V_12 ) ;
V_12 -> V_29 = V_188 ;
V_14 -> V_47 = V_188 ;
break;
default:
V_12 -> V_29 = V_188 ;
V_14 -> V_47 = V_188 ;
V_12 -> V_189 = V_18 ;
if ( V_191 ) {
F_96 ( V_12 ) ;
V_191 -> V_199 ( V_191 ) ;
} else {
V_12 -> V_151 ( V_12 ) ;
}
break;
}
F_17 ( V_12 ) ;
}
static void F_97 ( struct V_13 * V_14 , int V_47 ,
int V_18 )
{
struct V_2 * V_12 = V_14 -> V_193 ;
V_12 -> V_29 = V_47 ;
if ( V_18 )
V_12 -> V_189 = V_18 ;
}
static struct V_196 * F_98 ( struct V_13 * V_14 ,
unsigned long V_200 ,
unsigned long V_17 , int V_201 )
{
struct V_2 * V_12 = V_14 -> V_193 ;
struct V_196 * V_197 ;
int V_18 ;
F_60 ( V_14 ) ;
V_197 = F_99 ( V_12 , V_200 + V_17 , V_201 , & V_18 ) ;
F_58 ( V_14 ) ;
if ( ! V_197 )
return F_100 ( V_18 ) ;
V_197 -> V_202 = V_12 -> V_203 ;
F_101 ( V_197 ) -> V_14 = V_14 ;
return V_197 ;
}
static int F_102 ( struct V_13 * V_14 ,
unsigned char * V_204 ,
struct V_205 * V_206 , int V_17 )
{
return F_103 ( V_204 , V_206 , V_17 ) ;
}
static void F_104 ( struct V_13 * V_14 )
{
struct V_2 * V_12 = V_14 -> V_193 ;
struct V_2 * V_191 ;
F_12 ( V_12 ) ;
V_191 = F_43 ( V_12 ) -> V_191 ;
F_7 ( L_9 , V_12 , V_191 ) ;
V_12 -> V_29 = V_53 ;
V_12 -> V_151 ( V_12 ) ;
if ( V_191 )
V_191 -> V_199 ( V_191 ) ;
F_17 ( V_12 ) ;
}
static void F_105 ( struct V_13 * V_14 )
{
struct V_2 * V_191 , * V_12 = V_14 -> V_193 ;
F_12 ( V_12 ) ;
V_191 = F_43 ( V_12 ) -> V_191 ;
if ( V_191 )
V_191 -> V_199 ( V_191 ) ;
F_17 ( V_12 ) ;
}
static void F_106 ( struct V_13 * V_14 )
{
struct V_2 * V_12 = V_14 -> V_193 ;
F_48 ( V_150 , & F_43 ( V_12 ) -> V_49 ) ;
V_12 -> V_151 ( V_12 ) ;
}
static void F_107 ( struct V_13 * V_14 )
{
struct V_2 * V_12 = V_14 -> V_193 ;
F_12 ( V_12 ) ;
V_12 -> V_183 = V_184 ;
F_17 ( V_12 ) ;
}
static long F_108 ( struct V_13 * V_14 )
{
struct V_2 * V_12 = V_14 -> V_193 ;
return V_12 -> V_207 ;
}
static void F_109 ( struct V_13 * V_14 )
{
struct V_2 * V_12 = V_14 -> V_193 ;
F_49 ( V_150 , & F_43 ( V_12 ) -> V_49 ) ;
V_12 -> V_151 ( V_12 ) ;
}
static void F_110 ( struct V_2 * V_12 )
{
F_7 ( L_1 , V_12 ) ;
if ( F_6 ( V_12 ) -> V_14 )
F_72 ( F_6 ( V_12 ) -> V_14 ) ;
if ( F_6 ( V_12 ) -> V_173 ) {
F_111 ( F_6 ( V_12 ) -> V_173 ) ;
F_6 ( V_12 ) -> V_173 = NULL ;
}
F_112 ( & V_12 -> V_208 ) ;
F_112 ( & V_12 -> V_209 ) ;
}
static void F_113 ( struct V_196 * V_197 , void * V_210 ,
int * V_211 )
{
F_114 ( struct V_15 * , V_16 , V_210 ) ;
memset ( V_16 , 0 , sizeof( struct V_15 ) ) ;
V_16 -> V_212 = V_20 ;
V_16 -> V_22 = F_101 ( V_197 ) -> V_5 ;
F_16 ( & V_16 -> V_34 , & F_101 ( V_197 ) -> V_213 ) ;
* V_211 = sizeof( struct V_15 ) ;
}
static void F_91 ( struct V_2 * V_12 , struct V_2 * V_191 )
{
struct V_13 * V_14 = F_6 ( V_12 ) -> V_14 ;
F_7 ( L_1 , V_12 ) ;
if ( V_191 ) {
struct V_13 * V_214 = F_6 ( V_191 ) -> V_14 ;
V_12 -> V_56 = V_191 -> V_56 ;
F_43 ( V_12 ) -> V_49 = F_43 ( V_191 ) -> V_49 ;
V_14 -> V_24 = V_214 -> V_24 ;
V_14 -> V_95 = V_214 -> V_95 ;
V_14 -> V_26 = V_214 -> V_26 ;
V_14 -> V_148 = V_214 -> V_148 ;
V_14 -> V_45 = V_214 -> V_45 ;
V_14 -> V_97 = V_214 -> V_97 ;
V_14 -> V_98 = V_214 -> V_98 ;
V_14 -> V_100 = V_214 -> V_100 ;
V_14 -> V_215 = V_214 -> V_215 ;
V_14 -> V_37 = V_214 -> V_37 ;
V_14 -> V_49 = V_214 -> V_49 ;
V_14 -> V_216 = V_214 -> V_216 ;
V_14 -> V_217 = V_214 -> V_217 ;
if ( V_14 -> V_24 == V_25 ) {
V_14 -> V_51 = V_214 -> V_51 ;
V_14 -> V_83 = V_214 -> V_51 ;
}
F_115 ( V_191 , V_12 ) ;
} else {
switch ( V_12 -> V_56 ) {
case V_136 :
V_14 -> V_24 = V_42 ;
break;
case V_218 :
V_14 -> V_24 = V_35 ;
F_43 ( V_12 ) -> V_219 = F_113 ;
break;
case V_57 :
case V_58 :
V_14 -> V_24 = V_39 ;
break;
}
V_14 -> V_95 = V_27 ;
V_14 -> V_26 = 0 ;
if ( ! V_62 && V_12 -> V_56 == V_58 ) {
V_14 -> V_45 = V_60 ;
F_49 ( V_147 , & V_14 -> V_148 ) ;
} else {
V_14 -> V_45 = V_59 ;
}
F_116 ( V_14 ) ;
}
V_14 -> V_96 = V_220 ;
V_14 -> V_193 = V_12 ;
V_14 -> V_3 = & V_221 ;
}
static struct V_2 * F_88 ( struct V_222 * V_222 , struct V_1 * V_2 ,
int V_223 , T_6 V_224 )
{
struct V_2 * V_12 ;
struct V_13 * V_14 ;
V_12 = F_117 ( V_222 , V_225 , V_224 , & V_226 ) ;
if ( ! V_12 )
return NULL ;
F_118 ( V_2 , V_12 ) ;
F_119 ( & F_43 ( V_12 ) -> V_227 ) ;
V_12 -> V_228 = F_110 ;
V_12 -> V_207 = V_229 ;
F_120 ( V_12 , V_176 ) ;
V_12 -> V_230 = V_223 ;
V_12 -> V_29 = V_30 ;
V_14 = F_121 () ;
if ( ! V_14 ) {
F_122 ( V_12 ) ;
return NULL ;
}
F_123 ( V_14 ) ;
F_6 ( V_12 ) -> V_14 = V_14 ;
return V_12 ;
}
static int F_124 ( struct V_222 * V_222 , struct V_1 * V_2 , int V_231 ,
int V_232 )
{
struct V_2 * V_12 ;
F_7 ( L_10 , V_2 ) ;
V_2 -> V_47 = V_233 ;
if ( V_2 -> type != V_57 && V_2 -> type != V_58 &&
V_2 -> type != V_218 && V_2 -> type != V_136 )
return - V_234 ;
if ( V_2 -> type == V_136 && ! V_232 && ! F_3 ( V_235 ) )
return - V_161 ;
V_2 -> V_3 = & V_4 ;
V_12 = F_88 ( V_222 , V_2 , V_231 , V_195 ) ;
if ( ! V_12 )
return - V_198 ;
F_91 ( V_12 , NULL ) ;
F_125 ( & V_190 , V_12 ) ;
return 0 ;
}
int T_7 F_126 ( void )
{
int V_18 ;
V_18 = F_127 ( & V_226 , 0 ) ;
if ( V_18 < 0 )
return V_18 ;
V_18 = F_128 ( V_194 , & V_236 ) ;
if ( V_18 < 0 ) {
F_129 ( L_11 ) ;
goto error;
}
V_18 = F_130 ( & V_237 , L_12 , & V_190 ,
NULL ) ;
if ( V_18 < 0 ) {
F_129 ( L_13 ) ;
F_131 ( V_194 ) ;
goto error;
}
F_132 ( L_14 ) ;
return 0 ;
error:
F_133 ( & V_226 ) ;
return V_18 ;
}
void F_134 ( void )
{
F_135 ( & V_237 , L_12 ) ;
F_131 ( V_194 ) ;
F_133 ( & V_226 ) ;
}
