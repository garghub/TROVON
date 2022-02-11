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
V_12 -> V_29 != V_78 && V_12 -> V_29 != V_79 )
return - V_80 ;
memset ( V_16 , 0 , sizeof( struct V_15 ) ) ;
V_10 -> V_19 = V_20 ;
* V_17 = sizeof( struct V_15 ) ;
V_16 -> V_22 = V_14 -> V_5 ;
if ( V_77 ) {
F_16 ( & V_16 -> V_34 , & V_14 -> V_81 ) ;
V_16 -> V_21 = F_11 ( V_14 -> V_82 ) ;
V_16 -> V_23 = V_14 -> V_83 ;
} else {
F_16 ( & V_16 -> V_34 , & V_14 -> V_43 ) ;
V_16 -> V_21 = F_11 ( V_14 -> V_51 ) ;
V_16 -> V_23 = V_14 -> V_44 ;
}
return 0 ;
}
static int F_38 ( struct V_1 * V_2 , int V_84 ,
char T_3 * V_85 , int T_3 * V_86 )
{
struct V_2 * V_12 = V_2 -> V_12 ;
struct V_13 * V_14 = F_6 ( V_12 ) -> V_14 ;
struct V_87 V_88 ;
struct V_89 V_90 ;
int V_17 , V_18 = 0 ;
T_4 V_91 ;
F_7 ( L_1 , V_12 ) ;
if ( F_39 ( V_17 , V_86 ) )
return - V_92 ;
F_12 ( V_12 ) ;
switch ( V_84 ) {
case V_93 :
if ( F_10 ( V_14 -> V_44 ) &&
V_14 -> V_51 != V_28 ) {
V_18 = - V_6 ;
break;
}
memset ( & V_88 , 0 , sizeof( V_88 ) ) ;
V_88 . V_94 = V_14 -> V_94 ;
V_88 . V_26 = V_14 -> V_26 ;
V_88 . V_95 = V_14 -> V_95 ;
V_88 . V_45 = V_14 -> V_45 ;
V_88 . V_96 = V_14 -> V_96 ;
V_88 . V_97 = V_14 -> V_97 ;
V_88 . V_98 = V_14 -> V_99 ;
V_17 = F_8 (unsigned int, len, sizeof(opts)) ;
if ( F_40 ( V_85 , ( char * ) & V_88 , V_17 ) )
V_18 = - V_92 ;
break;
case V_100 :
switch ( V_14 -> V_37 ) {
case V_101 :
V_91 = V_102 ;
break;
case V_103 :
V_91 = V_102 | V_104 ;
break;
case V_105 :
V_91 = V_102 | V_104 |
V_106 ;
break;
case V_107 :
V_91 = V_102 | V_104 |
V_106 | V_108 ;
break;
default:
V_91 = 0 ;
break;
}
if ( F_41 ( V_109 , & V_14 -> V_49 ) )
V_91 |= V_110 ;
if ( F_41 ( V_111 , & V_14 -> V_49 ) )
V_91 |= V_112 ;
if ( F_42 ( V_91 , ( T_4 T_3 * ) V_85 ) )
V_18 = - V_92 ;
break;
case V_113 :
if ( V_12 -> V_29 != V_53 &&
! ( V_12 -> V_29 == V_79 &&
F_41 ( V_114 , & F_43 ( V_12 ) -> V_49 ) ) ) {
V_18 = - V_80 ;
break;
}
memset ( & V_90 , 0 , sizeof( V_90 ) ) ;
V_90 . V_115 = V_14 -> V_116 -> V_117 -> V_118 ;
memcpy ( V_90 . V_119 , V_14 -> V_116 -> V_117 -> V_119 , 3 ) ;
V_17 = F_8 (unsigned int, len, sizeof(cinfo)) ;
if ( F_40 ( V_85 , ( char * ) & V_90 , V_17 ) )
V_18 = - V_92 ;
break;
default:
V_18 = - V_120 ;
break;
}
F_17 ( V_12 ) ;
return V_18 ;
}
static int F_44 ( struct V_1 * V_2 , int V_121 , int V_84 ,
char T_3 * V_85 , int T_3 * V_86 )
{
struct V_2 * V_12 = V_2 -> V_12 ;
struct V_13 * V_14 = F_6 ( V_12 ) -> V_14 ;
struct V_122 V_123 ;
struct V_124 V_125 ;
int V_17 , V_18 = 0 ;
F_7 ( L_1 , V_12 ) ;
if ( V_121 == V_126 )
return F_38 ( V_2 , V_84 , V_85 , V_86 ) ;
if ( V_121 != V_127 )
return - V_120 ;
if ( F_39 ( V_17 , V_86 ) )
return - V_92 ;
F_12 ( V_12 ) ;
switch ( V_84 ) {
case V_128 :
if ( V_14 -> V_24 != V_39 &&
V_14 -> V_24 != V_25 &&
V_14 -> V_24 != V_42 ) {
V_18 = - V_6 ;
break;
}
memset ( & V_123 , 0 , sizeof( V_123 ) ) ;
if ( V_14 -> V_116 ) {
V_123 . V_121 = V_14 -> V_116 -> V_117 -> V_37 ;
if ( V_12 -> V_29 == V_53 )
V_123 . V_129 = V_14 -> V_116 -> V_117 -> V_130 ;
} else {
V_123 . V_121 = V_14 -> V_37 ;
}
V_17 = F_8 (unsigned int, len, sizeof(sec)) ;
if ( F_40 ( V_85 , ( char * ) & V_123 , V_17 ) )
V_18 = - V_92 ;
break;
case V_131 :
if ( V_12 -> V_29 != V_48 && V_12 -> V_29 != V_66 ) {
V_18 = - V_6 ;
break;
}
if ( F_42 ( F_41 ( V_114 , & F_43 ( V_12 ) -> V_49 ) ,
( T_4 T_3 * ) V_85 ) )
V_18 = - V_92 ;
break;
case V_132 :
if ( F_42 ( F_41 ( V_133 , & V_14 -> V_49 ) ,
( T_4 T_3 * ) V_85 ) )
V_18 = - V_92 ;
break;
case V_134 :
if ( V_12 -> V_56 != V_57 && V_12 -> V_56 != V_58
&& V_12 -> V_56 != V_135 ) {
V_18 = - V_6 ;
break;
}
V_125 . V_136 = F_41 ( V_137 , & V_14 -> V_49 ) ;
V_17 = F_8 (unsigned int, len, sizeof(pwr)) ;
if ( F_40 ( V_85 , ( char * ) & V_125 , V_17 ) )
V_18 = - V_92 ;
break;
case V_138 :
if ( F_42 ( V_14 -> V_139 , ( T_4 T_3 * ) V_85 ) )
V_18 = - V_92 ;
break;
case V_140 :
if ( ! F_10 ( V_14 -> V_44 ) ) {
V_18 = - V_6 ;
break;
}
if ( V_12 -> V_29 != V_53 ) {
V_18 = - V_80 ;
break;
}
if ( F_42 ( V_14 -> V_26 , ( T_1 T_3 * ) V_85 ) )
V_18 = - V_92 ;
break;
case V_141 :
if ( ! F_10 ( V_14 -> V_44 ) ) {
V_18 = - V_6 ;
break;
}
if ( F_42 ( V_14 -> V_94 , ( T_1 T_3 * ) V_85 ) )
V_18 = - V_92 ;
break;
default:
V_18 = - V_120 ;
break;
}
F_17 ( V_12 ) ;
return V_18 ;
}
static bool F_45 ( struct V_13 * V_14 , T_1 V_142 )
{
switch ( V_14 -> V_51 ) {
case V_28 :
if ( V_142 < V_143 )
return false ;
break;
default:
if ( V_142 < V_144 )
return false ;
}
return true ;
}
static int F_46 ( struct V_1 * V_2 , int V_84 ,
char T_3 * V_85 , unsigned int V_86 )
{
struct V_2 * V_12 = V_2 -> V_12 ;
struct V_13 * V_14 = F_6 ( V_12 ) -> V_14 ;
struct V_87 V_88 ;
int V_17 , V_18 = 0 ;
T_4 V_91 ;
F_7 ( L_1 , V_12 ) ;
F_12 ( V_12 ) ;
switch ( V_84 ) {
case V_93 :
if ( F_10 ( V_14 -> V_44 ) ) {
V_18 = - V_6 ;
break;
}
if ( V_12 -> V_29 == V_53 ) {
V_18 = - V_6 ;
break;
}
V_88 . V_94 = V_14 -> V_94 ;
V_88 . V_26 = V_14 -> V_26 ;
V_88 . V_95 = V_14 -> V_95 ;
V_88 . V_45 = V_14 -> V_45 ;
V_88 . V_96 = V_14 -> V_96 ;
V_88 . V_97 = V_14 -> V_97 ;
V_88 . V_98 = V_14 -> V_99 ;
V_17 = F_8 (unsigned int, sizeof(opts), optlen) ;
if ( F_47 ( ( char * ) & V_88 , V_85 , V_17 ) ) {
V_18 = - V_92 ;
break;
}
if ( V_88 . V_98 > V_145 ) {
V_18 = - V_6 ;
break;
}
if ( ! F_45 ( V_14 , V_88 . V_94 ) ) {
V_18 = - V_6 ;
break;
}
V_14 -> V_45 = V_88 . V_45 ;
switch ( V_14 -> V_45 ) {
case V_46 :
break;
case V_59 :
F_48 ( V_146 , & V_14 -> V_147 ) ;
break;
case V_60 :
case V_61 :
if ( ! V_62 )
break;
default:
V_18 = - V_6 ;
break;
}
V_14 -> V_94 = V_88 . V_94 ;
V_14 -> V_26 = V_88 . V_26 ;
V_14 -> V_96 = V_88 . V_96 ;
V_14 -> V_97 = V_88 . V_97 ;
V_14 -> V_99 = V_88 . V_98 ;
V_14 -> V_95 = V_88 . V_95 ;
break;
case V_100 :
if ( F_39 ( V_91 , ( T_4 T_3 * ) V_85 ) ) {
V_18 = - V_92 ;
break;
}
if ( V_91 & V_108 ) {
V_18 = - V_6 ;
break;
}
if ( V_91 & V_102 )
V_14 -> V_37 = V_101 ;
if ( V_91 & V_104 )
V_14 -> V_37 = V_103 ;
if ( V_91 & V_106 )
V_14 -> V_37 = V_105 ;
if ( V_91 & V_110 )
F_49 ( V_109 , & V_14 -> V_49 ) ;
else
F_48 ( V_109 , & V_14 -> V_49 ) ;
if ( V_91 & V_112 )
F_49 ( V_111 , & V_14 -> V_49 ) ;
else
F_48 ( V_111 , & V_14 -> V_49 ) ;
break;
default:
V_18 = - V_120 ;
break;
}
F_17 ( V_12 ) ;
return V_18 ;
}
static int F_50 ( struct V_1 * V_2 , int V_121 , int V_84 ,
char T_3 * V_85 , unsigned int V_86 )
{
struct V_2 * V_12 = V_2 -> V_12 ;
struct V_13 * V_14 = F_6 ( V_12 ) -> V_14 ;
struct V_122 V_123 ;
struct V_124 V_125 ;
struct V_148 * V_116 ;
int V_17 , V_18 = 0 ;
T_4 V_91 ;
F_7 ( L_1 , V_12 ) ;
if ( V_121 == V_126 )
return F_46 ( V_2 , V_84 , V_85 , V_86 ) ;
if ( V_121 != V_127 )
return - V_120 ;
F_12 ( V_12 ) ;
switch ( V_84 ) {
case V_128 :
if ( V_14 -> V_24 != V_39 &&
V_14 -> V_24 != V_25 &&
V_14 -> V_24 != V_42 ) {
V_18 = - V_6 ;
break;
}
V_123 . V_121 = V_101 ;
V_17 = F_8 (unsigned int, sizeof(sec), optlen) ;
if ( F_47 ( ( char * ) & V_123 , V_85 , V_17 ) ) {
V_18 = - V_92 ;
break;
}
if ( V_123 . V_121 < V_101 ||
V_123 . V_121 > V_105 ) {
V_18 = - V_6 ;
break;
}
V_14 -> V_37 = V_123 . V_121 ;
if ( ! V_14 -> V_116 )
break;
V_116 = V_14 -> V_116 ;
if ( V_14 -> V_51 == V_28 ) {
if ( ! V_116 -> V_117 -> V_149 ) {
V_18 = - V_6 ;
break;
}
if ( F_51 ( V_116 -> V_117 , V_123 . V_121 ) )
break;
V_12 -> V_29 = V_150 ;
V_14 -> V_47 = V_150 ;
} else if ( ( V_12 -> V_29 == V_79 &&
F_41 ( V_114 , & F_43 ( V_12 ) -> V_49 ) ) ||
V_12 -> V_29 == V_53 ) {
if ( ! F_52 ( V_14 ) )
F_49 ( V_151 , & F_43 ( V_12 ) -> V_49 ) ;
else
V_12 -> V_152 ( V_12 ) ;
} else {
V_18 = - V_6 ;
}
break;
case V_131 :
if ( V_12 -> V_29 != V_48 && V_12 -> V_29 != V_66 ) {
V_18 = - V_6 ;
break;
}
if ( F_39 ( V_91 , ( T_4 T_3 * ) V_85 ) ) {
V_18 = - V_92 ;
break;
}
if ( V_91 ) {
F_49 ( V_114 , & F_43 ( V_12 ) -> V_49 ) ;
F_49 ( V_153 , & V_14 -> V_49 ) ;
} else {
F_48 ( V_114 , & F_43 ( V_12 ) -> V_49 ) ;
F_48 ( V_153 , & V_14 -> V_49 ) ;
}
break;
case V_132 :
if ( F_39 ( V_91 , ( T_4 T_3 * ) V_85 ) ) {
V_18 = - V_92 ;
break;
}
if ( V_91 > V_154 ) {
V_18 = - V_6 ;
break;
}
if ( V_91 == V_155 ) {
V_116 = V_14 -> V_116 ;
if ( ! V_116 || ! F_53 ( V_116 -> V_117 -> V_156 ) ) {
V_18 = - V_6 ;
break;
}
}
if ( V_91 )
F_49 ( V_133 , & V_14 -> V_49 ) ;
else
F_48 ( V_133 , & V_14 -> V_49 ) ;
break;
case V_134 :
if ( V_14 -> V_24 != V_39 &&
V_14 -> V_24 != V_42 ) {
V_18 = - V_6 ;
break;
}
V_125 . V_136 = V_157 ;
V_17 = F_8 (unsigned int, sizeof(pwr), optlen) ;
if ( F_47 ( ( char * ) & V_125 , V_85 , V_17 ) ) {
V_18 = - V_92 ;
break;
}
if ( V_125 . V_136 )
F_49 ( V_137 , & V_14 -> V_49 ) ;
else
F_48 ( V_137 , & V_14 -> V_49 ) ;
break;
case V_138 :
if ( F_39 ( V_91 , ( T_4 T_3 * ) V_85 ) ) {
V_18 = - V_92 ;
break;
}
if ( V_91 > V_158 ) {
V_18 = - V_6 ;
break;
}
if ( V_14 -> V_45 != V_60 &&
V_14 -> V_45 != V_61 ) {
V_18 = - V_159 ;
break;
}
V_14 -> V_139 = ( V_160 ) V_91 ;
if ( V_12 -> V_29 == V_53 &&
V_14 -> V_161 == V_162 )
F_54 ( V_14 ) ;
break;
case V_140 :
if ( ! F_10 ( V_14 -> V_44 ) ) {
V_18 = - V_6 ;
break;
}
V_18 = - V_163 ;
break;
case V_141 :
if ( ! F_10 ( V_14 -> V_44 ) ) {
V_18 = - V_6 ;
break;
}
if ( V_12 -> V_29 == V_53 ) {
V_18 = - V_164 ;
break;
}
if ( F_39 ( V_91 , ( T_4 T_3 * ) V_85 ) ) {
V_18 = - V_92 ;
break;
}
V_14 -> V_94 = V_91 ;
break;
default:
V_18 = - V_120 ;
break;
}
F_17 ( V_12 ) ;
return V_18 ;
}
static int F_55 ( struct V_165 * V_166 , struct V_1 * V_2 ,
struct V_167 * V_168 , T_5 V_17 )
{
struct V_2 * V_12 = V_2 -> V_12 ;
struct V_13 * V_14 = F_6 ( V_12 ) -> V_14 ;
int V_18 ;
F_7 ( L_5 , V_2 , V_12 ) ;
V_18 = F_56 ( V_12 ) ;
if ( V_18 )
return V_18 ;
if ( V_168 -> V_169 & V_170 )
return - V_159 ;
if ( V_12 -> V_29 != V_53 )
return - V_80 ;
F_12 ( V_12 ) ;
V_18 = F_57 ( V_12 , V_168 -> V_169 ) ;
F_17 ( V_12 ) ;
if ( V_18 )
return V_18 ;
F_58 ( V_14 ) ;
V_18 = F_59 ( V_14 , V_168 , V_17 , V_12 -> V_171 ) ;
F_60 ( V_14 ) ;
return V_18 ;
}
static int F_61 ( struct V_165 * V_166 , struct V_1 * V_2 ,
struct V_167 * V_168 , T_5 V_17 , int V_49 )
{
struct V_2 * V_12 = V_2 -> V_12 ;
struct V_172 * V_173 = F_6 ( V_12 ) ;
int V_18 ;
F_12 ( V_12 ) ;
if ( V_12 -> V_29 == V_79 && F_41 ( V_114 ,
& F_43 ( V_12 ) -> V_49 ) ) {
if ( F_10 ( V_173 -> V_14 -> V_44 ) ) {
V_12 -> V_29 = V_53 ;
V_173 -> V_14 -> V_47 = V_53 ;
F_62 ( V_173 -> V_14 ) ;
} else {
V_12 -> V_29 = V_150 ;
V_173 -> V_14 -> V_47 = V_150 ;
F_63 ( V_173 -> V_14 ) ;
}
V_18 = 0 ;
goto V_32;
}
F_17 ( V_12 ) ;
if ( V_2 -> type == V_58 )
V_18 = F_64 ( V_166 , V_2 , V_168 , V_17 , V_49 ) ;
else
V_18 = F_65 ( V_166 , V_2 , V_168 , V_17 , V_49 ) ;
if ( V_173 -> V_14 -> V_45 != V_60 )
return V_18 ;
F_12 ( V_12 ) ;
if ( ! F_41 ( V_174 , & V_173 -> V_14 -> V_175 ) )
goto V_32;
if ( V_173 -> V_176 ) {
if ( ! F_66 ( V_12 , V_173 -> V_176 ) )
V_173 -> V_176 = NULL ;
else
goto V_32;
}
if ( F_67 ( & V_12 -> V_177 ) <= V_12 -> V_178 >> 1 )
F_68 ( V_173 -> V_14 , 0 ) ;
V_32:
F_17 ( V_12 ) ;
return V_18 ;
}
static void F_69 ( struct V_2 * V_12 )
{
if ( ! F_70 ( V_12 , V_179 ) || V_12 -> V_180 )
return;
F_7 ( L_6 , V_12 , F_71 ( V_12 -> V_29 ) ) ;
F_72 ( F_6 ( V_12 ) -> V_14 ) ;
F_73 ( V_12 , V_181 ) ;
F_74 ( V_12 ) ;
}
static int F_75 ( struct V_2 * V_12 )
{
struct V_13 * V_14 = F_6 ( V_12 ) -> V_14 ;
F_25 ( V_68 , V_69 ) ;
int V_18 = 0 ;
int V_71 = V_182 / 5 ;
F_76 ( F_29 ( V_12 ) , & V_68 ) ;
F_30 ( V_73 ) ;
while ( V_14 -> V_183 > 0 && V_14 -> V_116 ) {
if ( ! V_71 )
V_71 = V_182 / 5 ;
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
static int F_77 ( struct V_1 * V_2 , int V_184 )
{
struct V_2 * V_12 = V_2 -> V_12 ;
struct V_13 * V_14 ;
struct V_148 * V_116 ;
int V_18 = 0 ;
F_7 ( L_5 , V_2 , V_12 ) ;
if ( ! V_12 )
return 0 ;
V_14 = F_6 ( V_12 ) -> V_14 ;
V_116 = V_14 -> V_116 ;
if ( V_116 )
F_78 ( & V_116 -> V_185 ) ;
F_58 ( V_14 ) ;
F_12 ( V_12 ) ;
if ( ! V_12 -> V_186 ) {
if ( V_14 -> V_45 == V_60 )
V_18 = F_75 ( V_12 ) ;
V_12 -> V_186 = V_187 ;
F_17 ( V_12 ) ;
F_79 ( V_14 , 0 ) ;
F_12 ( V_12 ) ;
if ( F_70 ( V_12 , V_188 ) && V_12 -> V_189 )
V_18 = F_21 ( V_12 , V_190 ,
V_12 -> V_189 ) ;
}
if ( ! V_18 && V_12 -> V_191 )
V_18 = - V_12 -> V_191 ;
F_17 ( V_12 ) ;
F_60 ( V_14 ) ;
if ( V_116 )
F_80 ( & V_116 -> V_185 ) ;
return V_18 ;
}
static int F_81 ( struct V_1 * V_2 )
{
struct V_2 * V_12 = V_2 -> V_12 ;
int V_18 ;
F_7 ( L_5 , V_2 , V_12 ) ;
if ( ! V_12 )
return 0 ;
F_82 ( & V_192 , V_12 ) ;
V_18 = F_77 ( V_2 , 2 ) ;
F_83 ( V_12 ) ;
F_69 ( V_12 ) ;
return V_18 ;
}
static void F_84 ( struct V_2 * V_193 )
{
struct V_2 * V_12 ;
F_7 ( L_7 , V_193 ) ;
while ( ( V_12 = F_31 ( V_193 , NULL ) ) ) {
struct V_13 * V_14 = F_6 ( V_12 ) -> V_14 ;
F_58 ( V_14 ) ;
F_85 ( V_14 ) ;
F_79 ( V_14 , V_194 ) ;
F_60 ( V_14 ) ;
F_69 ( V_12 ) ;
}
}
static struct V_13 * F_86 ( struct V_13 * V_14 )
{
struct V_2 * V_12 , * V_193 = V_14 -> V_195 ;
F_12 ( V_193 ) ;
if ( F_87 ( V_193 ) ) {
F_7 ( L_8 , V_193 -> V_65 ) ;
return NULL ;
}
V_12 = F_88 ( F_89 ( V_193 ) , NULL , V_196 ,
V_197 ) ;
if ( ! V_12 )
return NULL ;
F_90 ( V_12 , V_196 ) ;
F_91 ( V_12 , V_193 ) ;
F_92 ( V_193 , V_12 ) ;
F_17 ( V_193 ) ;
return F_6 ( V_12 ) -> V_14 ;
}
static int F_93 ( struct V_13 * V_14 , struct V_198 * V_199 )
{
struct V_2 * V_12 = V_14 -> V_195 ;
int V_18 ;
F_12 ( V_12 ) ;
if ( F_6 ( V_12 ) -> V_176 ) {
V_18 = - V_200 ;
goto V_32;
}
V_18 = F_66 ( V_12 , V_199 ) ;
if ( V_18 < 0 && V_14 -> V_45 == V_60 ) {
F_6 ( V_12 ) -> V_176 = V_199 ;
F_68 ( V_14 , 1 ) ;
V_18 = 0 ;
}
V_32:
F_17 ( V_12 ) ;
return V_18 ;
}
static void F_94 ( struct V_13 * V_14 )
{
struct V_2 * V_12 = V_14 -> V_195 ;
F_69 ( V_12 ) ;
}
static void F_95 ( struct V_13 * V_14 , int V_18 )
{
struct V_2 * V_12 = V_14 -> V_195 ;
struct V_2 * V_193 ;
F_12 ( V_12 ) ;
V_193 = F_43 ( V_12 ) -> V_193 ;
F_73 ( V_12 , V_179 ) ;
switch ( V_14 -> V_47 ) {
case V_30 :
case V_48 :
case V_190 :
break;
case V_66 :
F_84 ( V_12 ) ;
V_12 -> V_29 = V_190 ;
V_14 -> V_47 = V_190 ;
break;
default:
V_12 -> V_29 = V_190 ;
V_14 -> V_47 = V_190 ;
V_12 -> V_191 = V_18 ;
if ( V_193 ) {
F_96 ( V_12 ) ;
V_193 -> V_201 ( V_193 ) ;
} else {
V_12 -> V_152 ( V_12 ) ;
}
break;
}
F_17 ( V_12 ) ;
}
static void F_97 ( struct V_13 * V_14 , int V_47 ,
int V_18 )
{
struct V_2 * V_12 = V_14 -> V_195 ;
V_12 -> V_29 = V_47 ;
if ( V_18 )
V_12 -> V_191 = V_18 ;
}
static struct V_198 * F_98 ( struct V_13 * V_14 ,
unsigned long V_17 , int V_202 )
{
struct V_2 * V_12 = V_14 -> V_195 ;
struct V_198 * V_199 ;
int V_18 ;
F_60 ( V_14 ) ;
V_199 = F_99 ( V_12 , V_17 , V_202 , & V_18 ) ;
F_58 ( V_14 ) ;
if ( ! V_199 )
return F_100 ( V_18 ) ;
F_101 ( V_199 ) -> V_14 = V_14 ;
return V_199 ;
}
static void F_102 ( struct V_13 * V_14 )
{
struct V_2 * V_12 = V_14 -> V_195 ;
struct V_2 * V_193 ;
F_12 ( V_12 ) ;
V_193 = F_43 ( V_12 ) -> V_193 ;
F_7 ( L_9 , V_12 , V_193 ) ;
V_12 -> V_29 = V_53 ;
V_12 -> V_152 ( V_12 ) ;
if ( V_193 )
V_193 -> V_201 ( V_193 ) ;
F_17 ( V_12 ) ;
}
static void F_103 ( struct V_13 * V_14 )
{
struct V_2 * V_193 , * V_12 = V_14 -> V_195 ;
F_12 ( V_12 ) ;
V_193 = F_43 ( V_12 ) -> V_193 ;
if ( V_193 )
V_193 -> V_201 ( V_193 ) ;
F_17 ( V_12 ) ;
}
static void F_104 ( struct V_13 * V_14 )
{
struct V_2 * V_12 = V_14 -> V_195 ;
F_48 ( V_151 , & F_43 ( V_12 ) -> V_49 ) ;
V_12 -> V_152 ( V_12 ) ;
}
static void F_105 ( struct V_13 * V_14 )
{
struct V_2 * V_12 = V_14 -> V_195 ;
F_12 ( V_12 ) ;
V_12 -> V_186 = V_187 ;
F_17 ( V_12 ) ;
}
static long F_106 ( struct V_13 * V_14 )
{
struct V_2 * V_12 = V_14 -> V_195 ;
return V_12 -> V_203 ;
}
static void F_107 ( struct V_13 * V_14 )
{
struct V_2 * V_12 = V_14 -> V_195 ;
F_49 ( V_151 , & F_43 ( V_12 ) -> V_49 ) ;
V_12 -> V_152 ( V_12 ) ;
}
static void F_108 ( struct V_2 * V_12 )
{
F_7 ( L_1 , V_12 ) ;
if ( F_6 ( V_12 ) -> V_14 )
F_72 ( F_6 ( V_12 ) -> V_14 ) ;
if ( F_6 ( V_12 ) -> V_176 ) {
F_109 ( F_6 ( V_12 ) -> V_176 ) ;
F_6 ( V_12 ) -> V_176 = NULL ;
}
F_110 ( & V_12 -> V_204 ) ;
F_110 ( & V_12 -> V_205 ) ;
}
static void F_111 ( struct V_198 * V_199 , void * V_206 ,
int * V_207 )
{
F_112 ( struct V_15 * , V_16 , V_206 ) ;
memset ( V_16 , 0 , sizeof( struct V_15 ) ) ;
V_16 -> V_208 = V_20 ;
V_16 -> V_22 = F_101 ( V_199 ) -> V_5 ;
F_16 ( & V_16 -> V_34 , & F_101 ( V_199 ) -> V_209 ) ;
* V_207 = sizeof( struct V_15 ) ;
}
static void F_91 ( struct V_2 * V_12 , struct V_2 * V_193 )
{
struct V_13 * V_14 = F_6 ( V_12 ) -> V_14 ;
F_7 ( L_1 , V_12 ) ;
if ( V_193 ) {
struct V_13 * V_210 = F_6 ( V_193 ) -> V_14 ;
V_12 -> V_56 = V_193 -> V_56 ;
F_43 ( V_12 ) -> V_49 = F_43 ( V_193 ) -> V_49 ;
V_14 -> V_24 = V_210 -> V_24 ;
V_14 -> V_94 = V_210 -> V_94 ;
V_14 -> V_26 = V_210 -> V_26 ;
V_14 -> V_147 = V_210 -> V_147 ;
V_14 -> V_45 = V_210 -> V_45 ;
V_14 -> V_96 = V_210 -> V_96 ;
V_14 -> V_97 = V_210 -> V_97 ;
V_14 -> V_99 = V_210 -> V_99 ;
V_14 -> V_211 = V_210 -> V_211 ;
V_14 -> V_37 = V_210 -> V_37 ;
V_14 -> V_49 = V_210 -> V_49 ;
V_14 -> V_212 = V_210 -> V_212 ;
V_14 -> V_213 = V_210 -> V_213 ;
if ( V_14 -> V_24 == V_25 ) {
V_14 -> V_51 = V_210 -> V_51 ;
V_14 -> V_82 = V_210 -> V_51 ;
}
F_113 ( V_193 , V_12 ) ;
} else {
switch ( V_12 -> V_56 ) {
case V_135 :
V_14 -> V_24 = V_42 ;
break;
case V_214 :
V_14 -> V_24 = V_35 ;
F_43 ( V_12 ) -> V_215 = F_111 ;
break;
case V_57 :
case V_58 :
V_14 -> V_24 = V_39 ;
break;
}
V_14 -> V_94 = V_27 ;
V_14 -> V_26 = 0 ;
if ( ! V_62 && V_12 -> V_56 == V_58 ) {
V_14 -> V_45 = V_60 ;
F_49 ( V_146 , & V_14 -> V_147 ) ;
} else {
V_14 -> V_45 = V_59 ;
}
F_114 ( V_14 ) ;
}
V_14 -> V_95 = V_216 ;
V_14 -> V_195 = V_12 ;
V_14 -> V_3 = & V_217 ;
}
static struct V_2 * F_88 ( struct V_218 * V_218 , struct V_1 * V_2 ,
int V_219 , T_6 V_220 )
{
struct V_2 * V_12 ;
struct V_13 * V_14 ;
V_12 = F_115 ( V_218 , V_221 , V_220 , & V_222 ) ;
if ( ! V_12 )
return NULL ;
F_116 ( V_2 , V_12 ) ;
F_117 ( & F_43 ( V_12 ) -> V_223 ) ;
V_12 -> V_224 = F_108 ;
V_12 -> V_203 = V_225 ;
F_118 ( V_12 , V_179 ) ;
V_12 -> V_226 = V_219 ;
V_12 -> V_29 = V_30 ;
V_14 = F_119 () ;
if ( ! V_14 ) {
F_120 ( V_12 ) ;
return NULL ;
}
F_121 ( V_14 ) ;
F_6 ( V_12 ) -> V_14 = V_14 ;
return V_12 ;
}
static int F_122 ( struct V_218 * V_218 , struct V_1 * V_2 , int V_227 ,
int V_228 )
{
struct V_2 * V_12 ;
F_7 ( L_10 , V_2 ) ;
V_2 -> V_47 = V_229 ;
if ( V_2 -> type != V_57 && V_2 -> type != V_58 &&
V_2 -> type != V_214 && V_2 -> type != V_135 )
return - V_230 ;
if ( V_2 -> type == V_135 && ! V_228 && ! F_3 ( V_231 ) )
return - V_163 ;
V_2 -> V_3 = & V_4 ;
V_12 = F_88 ( V_218 , V_2 , V_227 , V_197 ) ;
if ( ! V_12 )
return - V_200 ;
F_91 ( V_12 , NULL ) ;
F_123 ( & V_192 , V_12 ) ;
return 0 ;
}
int T_7 F_124 ( void )
{
int V_18 ;
V_18 = F_125 ( & V_222 , 0 ) ;
if ( V_18 < 0 )
return V_18 ;
V_18 = F_126 ( V_196 , & V_232 ) ;
if ( V_18 < 0 ) {
F_127 ( L_11 ) ;
goto error;
}
V_18 = F_128 ( & V_233 , L_12 , & V_192 ,
NULL ) ;
if ( V_18 < 0 ) {
F_127 ( L_13 ) ;
F_129 ( V_196 ) ;
goto error;
}
F_130 ( L_14 ) ;
return 0 ;
error:
F_131 ( & V_222 ) ;
return V_18 ;
}
void F_132 ( void )
{
F_133 ( & V_233 , L_12 ) ;
F_129 ( V_196 ) ;
F_131 ( & V_222 ) ;
}
