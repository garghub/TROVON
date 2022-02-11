bool F_1 ( struct V_1 * V_2 )
{
return V_2 && V_2 -> V_3 == & V_4 ;
}
static int F_2 ( T_1 V_5 )
{
if ( ( V_5 & 0x0101 ) != 0x0001 )
return - V_6 ;
if ( V_5 < V_7 && ! F_3 ( V_8 ) )
return - V_9 ;
return 0 ;
}
static int F_4 ( T_1 V_5 )
{
if ( V_5 > V_10 )
return - V_6 ;
if ( V_5 < V_11 && ! F_3 ( V_8 ) )
return - V_9 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , struct V_12 * V_13 , int V_14 )
{
struct V_2 * V_15 = V_2 -> V_15 ;
struct V_16 * V_17 = F_6 ( V_15 ) -> V_17 ;
struct V_18 V_19 ;
int V_20 , V_21 = 0 ;
F_7 ( L_1 , V_15 ) ;
if ( ! V_13 || V_13 -> V_22 != V_23 )
return - V_6 ;
memset ( & V_19 , 0 , sizeof( V_19 ) ) ;
V_20 = F_8 (unsigned int, sizeof(la), alen) ;
memcpy ( & V_19 , V_13 , V_20 ) ;
if ( V_19 . V_24 && V_19 . V_25 )
return - V_6 ;
if ( ! F_9 ( V_19 . V_26 ) )
return - V_6 ;
if ( F_10 ( V_19 . V_26 ) ) {
if ( V_19 . V_24 &&
V_19 . V_24 != F_11 ( V_27 ) )
return - V_6 ;
}
F_12 ( V_15 ) ;
if ( V_15 -> V_28 != V_29 ) {
V_21 = - V_30 ;
goto V_31;
}
if ( V_19 . V_25 ) {
T_2 V_5 = F_13 ( V_19 . V_25 ) ;
if ( V_19 . V_26 == V_32 )
V_21 = F_2 ( V_5 ) ;
else
V_21 = F_4 ( V_5 ) ;
if ( V_21 )
goto V_31;
}
F_14 ( & V_17 -> V_33 , & V_19 . V_34 ) ;
V_17 -> V_35 = V_19 . V_26 ;
if ( V_19 . V_24 )
V_21 = F_15 ( V_17 , F_13 ( V_19 . V_24 ) ) ;
else
V_21 = F_16 ( V_17 , & V_19 . V_34 , V_19 . V_25 ) ;
if ( V_21 < 0 )
goto V_31;
switch ( V_17 -> V_36 ) {
case V_37 :
if ( F_13 ( V_19 . V_25 ) == V_38 )
V_17 -> V_39 = V_40 ;
break;
case V_41 :
if ( F_13 ( V_19 . V_25 ) == V_42 ||
F_13 ( V_19 . V_25 ) == V_43 )
V_17 -> V_39 = V_40 ;
break;
case V_44 :
V_17 -> V_39 = V_40 ;
break;
case V_45 :
F_17 ( V_46 , & V_17 -> V_47 ) ;
break;
}
if ( V_17 -> V_5 && F_10 ( V_17 -> V_35 ) )
V_17 -> V_48 = V_49 ;
V_17 -> V_50 = V_51 ;
V_15 -> V_28 = V_51 ;
V_31:
F_18 ( V_15 ) ;
return V_21 ;
}
static int F_19 ( struct V_1 * V_2 , struct V_12 * V_13 ,
int V_14 , int V_47 )
{
struct V_2 * V_15 = V_2 -> V_15 ;
struct V_16 * V_17 = F_6 ( V_15 ) -> V_17 ;
struct V_18 V_19 ;
int V_20 , V_21 = 0 ;
F_7 ( L_1 , V_15 ) ;
if ( ! V_13 || V_14 < sizeof( V_13 -> V_22 ) ||
V_13 -> V_22 != V_23 )
return - V_6 ;
memset ( & V_19 , 0 , sizeof( V_19 ) ) ;
V_20 = F_8 (unsigned int, sizeof(la), alen) ;
memcpy ( & V_19 , V_13 , V_20 ) ;
if ( V_19 . V_24 && V_19 . V_25 )
return - V_6 ;
if ( ! F_9 ( V_19 . V_26 ) )
return - V_6 ;
if ( V_17 -> V_35 == V_32 && F_20 ( & V_17 -> V_33 , V_52 ) &&
F_10 ( V_19 . V_26 ) ) {
if ( V_17 -> V_53 != V_27 ||
V_19 . V_24 != F_11 ( V_27 ) )
return - V_6 ;
V_17 -> V_35 = V_54 ;
}
if ( V_17 -> V_35 != V_32 && V_19 . V_26 == V_32 )
return - V_6 ;
if ( F_10 ( V_19 . V_26 ) ) {
if ( V_19 . V_24 &&
V_19 . V_24 != F_11 ( V_27 ) )
return - V_6 ;
}
if ( V_17 -> V_5 && F_10 ( V_17 -> V_35 ) )
V_17 -> V_48 = V_49 ;
V_21 = F_21 ( V_17 , V_19 . V_25 , F_13 ( V_19 . V_24 ) ,
& V_19 . V_34 , V_19 . V_26 ) ;
if ( V_21 )
return V_21 ;
F_12 ( V_15 ) ;
V_21 = F_22 ( V_15 , V_55 ,
F_23 ( V_15 , V_47 & V_56 ) ) ;
F_18 ( V_15 ) ;
return V_21 ;
}
static int F_24 ( struct V_1 * V_2 , int V_57 )
{
struct V_2 * V_15 = V_2 -> V_15 ;
struct V_16 * V_17 = F_6 ( V_15 ) -> V_17 ;
int V_21 = 0 ;
F_7 ( L_2 , V_15 , V_57 ) ;
F_12 ( V_15 ) ;
if ( V_15 -> V_28 != V_51 ) {
V_21 = - V_30 ;
goto V_31;
}
if ( V_15 -> V_58 != V_59 && V_15 -> V_58 != V_60 ) {
V_21 = - V_6 ;
goto V_31;
}
switch ( V_17 -> V_48 ) {
case V_61 :
case V_49 :
break;
case V_62 :
case V_63 :
if ( ! V_64 )
break;
default:
V_21 = - V_65 ;
goto V_31;
}
V_15 -> V_66 = V_57 ;
V_15 -> V_67 = 0 ;
F_25 ( & V_17 -> V_68 , V_69 ) ;
V_17 -> V_50 = V_70 ;
V_15 -> V_28 = V_70 ;
V_31:
F_18 ( V_15 ) ;
return V_21 ;
}
static int F_26 ( struct V_1 * V_2 , struct V_1 * V_71 ,
int V_47 )
{
F_27 ( V_72 , V_73 ) ;
struct V_2 * V_15 = V_2 -> V_15 , * V_74 ;
long V_75 ;
int V_21 = 0 ;
F_28 ( V_15 , V_69 ) ;
V_75 = F_29 ( V_15 , V_47 & V_56 ) ;
F_7 ( L_3 , V_15 , V_75 ) ;
F_30 ( F_31 ( V_15 ) , & V_72 ) ;
while ( 1 ) {
if ( V_15 -> V_28 != V_70 ) {
V_21 = - V_30 ;
break;
}
V_74 = F_32 ( V_15 , V_71 ) ;
if ( V_74 )
break;
if ( ! V_75 ) {
V_21 = - V_76 ;
break;
}
if ( F_33 ( V_77 ) ) {
V_21 = F_34 ( V_75 ) ;
break;
}
F_18 ( V_15 ) ;
V_75 = F_35 ( & V_72 , V_78 , V_75 ) ;
F_28 ( V_15 , V_69 ) ;
}
F_36 ( F_31 ( V_15 ) , & V_72 ) ;
if ( V_21 )
goto V_31;
V_71 -> V_50 = V_79 ;
F_7 ( L_4 , V_74 ) ;
V_31:
F_18 ( V_15 ) ;
return V_21 ;
}
static int F_37 ( struct V_1 * V_2 , struct V_12 * V_13 ,
int * V_20 , int V_80 )
{
struct V_18 * V_19 = (struct V_18 * ) V_13 ;
struct V_2 * V_15 = V_2 -> V_15 ;
struct V_16 * V_17 = F_6 ( V_15 ) -> V_17 ;
F_7 ( L_5 , V_2 , V_15 ) ;
if ( V_80 && V_15 -> V_28 != V_55 &&
V_15 -> V_28 != V_81 && V_15 -> V_28 != V_82 &&
V_15 -> V_28 != V_83 )
return - V_84 ;
memset ( V_19 , 0 , sizeof( struct V_18 ) ) ;
V_13 -> V_22 = V_23 ;
* V_20 = sizeof( struct V_18 ) ;
V_19 -> V_25 = V_17 -> V_5 ;
if ( V_80 ) {
F_14 ( & V_19 -> V_34 , & V_17 -> V_85 ) ;
V_19 -> V_24 = F_11 ( V_17 -> V_86 ) ;
V_19 -> V_26 = V_17 -> V_87 ;
} else {
F_14 ( & V_19 -> V_34 , & V_17 -> V_33 ) ;
V_19 -> V_24 = F_11 ( V_17 -> V_53 ) ;
V_19 -> V_26 = V_17 -> V_35 ;
}
return 0 ;
}
static int F_38 ( struct V_1 * V_2 , int V_88 ,
char T_3 * V_89 , int T_3 * V_90 )
{
struct V_2 * V_15 = V_2 -> V_15 ;
struct V_16 * V_17 = F_6 ( V_15 ) -> V_17 ;
struct V_91 V_92 ;
struct V_93 V_94 ;
int V_20 , V_21 = 0 ;
T_4 V_95 ;
F_7 ( L_1 , V_15 ) ;
if ( F_39 ( V_20 , V_90 ) )
return - V_96 ;
F_12 ( V_15 ) ;
switch ( V_88 ) {
case V_97 :
if ( F_10 ( V_17 -> V_35 ) &&
V_17 -> V_53 != V_27 ) {
V_21 = - V_6 ;
break;
}
memset ( & V_92 , 0 , sizeof( V_92 ) ) ;
V_92 . V_98 = V_17 -> V_98 ;
V_92 . V_99 = V_17 -> V_99 ;
V_92 . V_100 = V_17 -> V_100 ;
V_92 . V_48 = V_17 -> V_48 ;
V_92 . V_101 = V_17 -> V_101 ;
V_92 . V_102 = V_17 -> V_102 ;
V_92 . V_103 = V_17 -> V_104 ;
V_20 = F_8 (unsigned int, len, sizeof(opts)) ;
if ( F_40 ( V_89 , ( char * ) & V_92 , V_20 ) )
V_21 = - V_96 ;
break;
case V_105 :
switch ( V_17 -> V_39 ) {
case V_106 :
V_95 = V_107 ;
break;
case V_108 :
V_95 = V_107 | V_109 ;
break;
case V_110 :
V_95 = V_107 | V_109 |
V_111 ;
break;
case V_112 :
V_95 = V_107 | V_109 |
V_111 | V_113 ;
break;
default:
V_95 = 0 ;
break;
}
if ( F_41 ( V_114 , & V_17 -> V_47 ) )
V_95 |= V_115 ;
if ( F_41 ( V_116 , & V_17 -> V_47 ) )
V_95 |= V_117 ;
if ( F_42 ( V_95 , ( T_4 T_3 * ) V_89 ) )
V_21 = - V_96 ;
break;
case V_118 :
if ( V_15 -> V_28 != V_55 &&
! ( V_15 -> V_28 == V_82 &&
F_41 ( V_119 , & F_43 ( V_15 ) -> V_47 ) ) ) {
V_21 = - V_84 ;
break;
}
memset ( & V_94 , 0 , sizeof( V_94 ) ) ;
V_94 . V_120 = V_17 -> V_121 -> V_122 -> V_123 ;
memcpy ( V_94 . V_124 , V_17 -> V_121 -> V_122 -> V_124 , 3 ) ;
V_20 = F_8 (unsigned int, len, sizeof(cinfo)) ;
if ( F_40 ( V_89 , ( char * ) & V_94 , V_20 ) )
V_21 = - V_96 ;
break;
default:
V_21 = - V_125 ;
break;
}
F_18 ( V_15 ) ;
return V_21 ;
}
static int F_44 ( struct V_1 * V_2 , int V_126 , int V_88 ,
char T_3 * V_89 , int T_3 * V_90 )
{
struct V_2 * V_15 = V_2 -> V_15 ;
struct V_16 * V_17 = F_6 ( V_15 ) -> V_17 ;
struct V_127 V_128 ;
struct V_129 V_130 ;
int V_20 , V_21 = 0 ;
F_7 ( L_1 , V_15 ) ;
if ( V_126 == V_131 )
return F_38 ( V_2 , V_88 , V_89 , V_90 ) ;
if ( V_126 != V_132 )
return - V_125 ;
if ( F_39 ( V_20 , V_90 ) )
return - V_96 ;
F_12 ( V_15 ) ;
switch ( V_88 ) {
case V_133 :
if ( V_17 -> V_36 != V_41 &&
V_17 -> V_36 != V_45 &&
V_17 -> V_36 != V_44 ) {
V_21 = - V_6 ;
break;
}
memset ( & V_128 , 0 , sizeof( V_128 ) ) ;
if ( V_17 -> V_121 ) {
V_128 . V_126 = V_17 -> V_121 -> V_122 -> V_39 ;
if ( V_15 -> V_28 == V_55 )
V_128 . V_134 = V_17 -> V_121 -> V_122 -> V_135 ;
} else {
V_128 . V_126 = V_17 -> V_39 ;
}
V_20 = F_8 (unsigned int, len, sizeof(sec)) ;
if ( F_40 ( V_89 , ( char * ) & V_128 , V_20 ) )
V_21 = - V_96 ;
break;
case V_136 :
if ( V_15 -> V_28 != V_51 && V_15 -> V_28 != V_70 ) {
V_21 = - V_6 ;
break;
}
if ( F_42 ( F_41 ( V_119 , & F_43 ( V_15 ) -> V_47 ) ,
( T_4 T_3 * ) V_89 ) )
V_21 = - V_96 ;
break;
case V_137 :
if ( F_42 ( F_41 ( V_138 , & V_17 -> V_47 ) ,
( T_4 T_3 * ) V_89 ) )
V_21 = - V_96 ;
break;
case V_139 :
if ( V_15 -> V_58 != V_59 && V_15 -> V_58 != V_60
&& V_15 -> V_58 != V_140 ) {
V_21 = - V_6 ;
break;
}
V_130 . V_141 = F_41 ( V_142 , & V_17 -> V_47 ) ;
V_20 = F_8 (unsigned int, len, sizeof(pwr)) ;
if ( F_40 ( V_89 , ( char * ) & V_130 , V_20 ) )
V_21 = - V_96 ;
break;
case V_143 :
if ( F_42 ( V_17 -> V_144 , ( T_4 T_3 * ) V_89 ) )
V_21 = - V_96 ;
break;
case V_145 :
if ( ! F_10 ( V_17 -> V_35 ) ) {
V_21 = - V_6 ;
break;
}
if ( V_15 -> V_28 != V_55 ) {
V_21 = - V_84 ;
break;
}
if ( F_42 ( V_17 -> V_99 , ( T_1 T_3 * ) V_89 ) )
V_21 = - V_96 ;
break;
case V_146 :
if ( ! F_10 ( V_17 -> V_35 ) ) {
V_21 = - V_6 ;
break;
}
if ( F_42 ( V_17 -> V_98 , ( T_1 T_3 * ) V_89 ) )
V_21 = - V_96 ;
break;
default:
V_21 = - V_125 ;
break;
}
F_18 ( V_15 ) ;
return V_21 ;
}
static bool F_45 ( struct V_16 * V_17 , T_1 V_147 )
{
switch ( V_17 -> V_53 ) {
case V_27 :
if ( V_147 < V_148 )
return false ;
break;
default:
if ( V_147 < V_149 )
return false ;
}
return true ;
}
static int F_46 ( struct V_1 * V_2 , int V_88 ,
char T_3 * V_89 , unsigned int V_90 )
{
struct V_2 * V_15 = V_2 -> V_15 ;
struct V_16 * V_17 = F_6 ( V_15 ) -> V_17 ;
struct V_91 V_92 ;
int V_20 , V_21 = 0 ;
T_4 V_95 ;
F_7 ( L_1 , V_15 ) ;
F_12 ( V_15 ) ;
switch ( V_88 ) {
case V_97 :
if ( F_10 ( V_17 -> V_35 ) ) {
V_21 = - V_6 ;
break;
}
if ( V_15 -> V_28 == V_55 ) {
V_21 = - V_6 ;
break;
}
V_92 . V_98 = V_17 -> V_98 ;
V_92 . V_99 = V_17 -> V_99 ;
V_92 . V_100 = V_17 -> V_100 ;
V_92 . V_48 = V_17 -> V_48 ;
V_92 . V_101 = V_17 -> V_101 ;
V_92 . V_102 = V_17 -> V_102 ;
V_92 . V_103 = V_17 -> V_104 ;
V_20 = F_8 (unsigned int, sizeof(opts), optlen) ;
if ( F_47 ( ( char * ) & V_92 , V_89 , V_20 ) ) {
V_21 = - V_96 ;
break;
}
if ( V_92 . V_103 > V_150 ) {
V_21 = - V_6 ;
break;
}
if ( ! F_45 ( V_17 , V_92 . V_98 ) ) {
V_21 = - V_6 ;
break;
}
V_17 -> V_48 = V_92 . V_48 ;
switch ( V_17 -> V_48 ) {
case V_49 :
break;
case V_61 :
F_48 ( V_151 , & V_17 -> V_152 ) ;
break;
case V_62 :
case V_63 :
if ( ! V_64 )
break;
default:
V_21 = - V_6 ;
break;
}
V_17 -> V_98 = V_92 . V_98 ;
V_17 -> V_99 = V_92 . V_99 ;
V_17 -> V_101 = V_92 . V_101 ;
V_17 -> V_102 = V_92 . V_102 ;
V_17 -> V_104 = V_92 . V_103 ;
V_17 -> V_100 = V_92 . V_100 ;
break;
case V_105 :
if ( F_39 ( V_95 , ( T_4 T_3 * ) V_89 ) ) {
V_21 = - V_96 ;
break;
}
if ( V_95 & V_113 ) {
V_21 = - V_6 ;
break;
}
if ( V_95 & V_107 )
V_17 -> V_39 = V_106 ;
if ( V_95 & V_109 )
V_17 -> V_39 = V_108 ;
if ( V_95 & V_111 )
V_17 -> V_39 = V_110 ;
if ( V_95 & V_115 )
F_17 ( V_114 , & V_17 -> V_47 ) ;
else
F_48 ( V_114 , & V_17 -> V_47 ) ;
if ( V_95 & V_117 )
F_17 ( V_116 , & V_17 -> V_47 ) ;
else
F_48 ( V_116 , & V_17 -> V_47 ) ;
break;
default:
V_21 = - V_125 ;
break;
}
F_18 ( V_15 ) ;
return V_21 ;
}
static int F_49 ( struct V_1 * V_2 , int V_126 , int V_88 ,
char T_3 * V_89 , unsigned int V_90 )
{
struct V_2 * V_15 = V_2 -> V_15 ;
struct V_16 * V_17 = F_6 ( V_15 ) -> V_17 ;
struct V_127 V_128 ;
struct V_129 V_130 ;
struct V_153 * V_121 ;
int V_20 , V_21 = 0 ;
T_4 V_95 ;
F_7 ( L_1 , V_15 ) ;
if ( V_126 == V_131 )
return F_46 ( V_2 , V_88 , V_89 , V_90 ) ;
if ( V_126 != V_132 )
return - V_125 ;
F_12 ( V_15 ) ;
switch ( V_88 ) {
case V_133 :
if ( V_17 -> V_36 != V_41 &&
V_17 -> V_36 != V_45 &&
V_17 -> V_36 != V_44 ) {
V_21 = - V_6 ;
break;
}
V_128 . V_126 = V_106 ;
V_20 = F_8 (unsigned int, sizeof(sec), optlen) ;
if ( F_47 ( ( char * ) & V_128 , V_89 , V_20 ) ) {
V_21 = - V_96 ;
break;
}
if ( V_128 . V_126 < V_106 ||
V_128 . V_126 > V_110 ) {
V_21 = - V_6 ;
break;
}
V_17 -> V_39 = V_128 . V_126 ;
if ( ! V_17 -> V_121 )
break;
V_121 = V_17 -> V_121 ;
if ( V_17 -> V_53 == V_27 ) {
if ( F_50 ( V_121 -> V_122 , V_128 . V_126 ) )
break;
F_17 ( V_154 , & V_17 -> V_47 ) ;
V_15 -> V_28 = V_83 ;
V_17 -> V_50 = V_83 ;
} else if ( ( V_15 -> V_28 == V_82 &&
F_41 ( V_119 , & F_43 ( V_15 ) -> V_47 ) ) ||
V_15 -> V_28 == V_55 ) {
if ( ! F_51 ( V_17 , true ) )
F_17 ( V_155 , & F_43 ( V_15 ) -> V_47 ) ;
else
V_15 -> V_156 ( V_15 ) ;
} else {
V_21 = - V_6 ;
}
break;
case V_136 :
if ( V_15 -> V_28 != V_51 && V_15 -> V_28 != V_70 ) {
V_21 = - V_6 ;
break;
}
if ( F_39 ( V_95 , ( T_4 T_3 * ) V_89 ) ) {
V_21 = - V_96 ;
break;
}
if ( V_95 ) {
F_17 ( V_119 , & F_43 ( V_15 ) -> V_47 ) ;
F_17 ( V_157 , & V_17 -> V_47 ) ;
} else {
F_48 ( V_119 , & F_43 ( V_15 ) -> V_47 ) ;
F_48 ( V_157 , & V_17 -> V_47 ) ;
}
break;
case V_137 :
if ( F_39 ( V_95 , ( T_4 T_3 * ) V_89 ) ) {
V_21 = - V_96 ;
break;
}
if ( V_95 > V_158 ) {
V_21 = - V_6 ;
break;
}
if ( V_95 == V_159 ) {
V_121 = V_17 -> V_121 ;
if ( ! V_121 || ! F_52 ( V_121 -> V_122 -> V_160 ) ) {
V_21 = - V_6 ;
break;
}
}
if ( V_95 )
F_17 ( V_138 , & V_17 -> V_47 ) ;
else
F_48 ( V_138 , & V_17 -> V_47 ) ;
break;
case V_139 :
if ( V_17 -> V_36 != V_41 &&
V_17 -> V_36 != V_44 ) {
V_21 = - V_6 ;
break;
}
V_130 . V_141 = V_161 ;
V_20 = F_8 (unsigned int, sizeof(pwr), optlen) ;
if ( F_47 ( ( char * ) & V_130 , V_89 , V_20 ) ) {
V_21 = - V_96 ;
break;
}
if ( V_130 . V_141 )
F_17 ( V_142 , & V_17 -> V_47 ) ;
else
F_48 ( V_142 , & V_17 -> V_47 ) ;
break;
case V_143 :
if ( F_39 ( V_95 , ( T_4 T_3 * ) V_89 ) ) {
V_21 = - V_96 ;
break;
}
if ( V_95 > V_162 ) {
V_21 = - V_6 ;
break;
}
if ( V_17 -> V_48 != V_62 &&
V_17 -> V_48 != V_63 ) {
V_21 = - V_65 ;
break;
}
V_17 -> V_144 = ( V_163 ) V_95 ;
if ( V_15 -> V_28 == V_55 &&
V_17 -> V_164 == V_165 )
F_53 ( V_17 ) ;
break;
case V_145 :
if ( ! F_10 ( V_17 -> V_35 ) ) {
V_21 = - V_6 ;
break;
}
V_21 = - V_166 ;
break;
case V_146 :
if ( ! F_10 ( V_17 -> V_35 ) ) {
V_21 = - V_6 ;
break;
}
if ( V_15 -> V_28 == V_55 ) {
V_21 = - V_167 ;
break;
}
if ( F_39 ( V_95 , ( T_4 T_3 * ) V_89 ) ) {
V_21 = - V_96 ;
break;
}
V_17 -> V_98 = V_95 ;
break;
default:
V_21 = - V_125 ;
break;
}
F_18 ( V_15 ) ;
return V_21 ;
}
static int F_54 ( struct V_1 * V_2 , struct V_168 * V_169 ,
T_5 V_20 )
{
struct V_2 * V_15 = V_2 -> V_15 ;
struct V_16 * V_17 = F_6 ( V_15 ) -> V_17 ;
int V_21 ;
F_7 ( L_5 , V_2 , V_15 ) ;
V_21 = F_55 ( V_15 ) ;
if ( V_21 )
return V_21 ;
if ( V_169 -> V_170 & V_171 )
return - V_65 ;
if ( V_15 -> V_28 != V_55 )
return - V_84 ;
F_12 ( V_15 ) ;
V_21 = F_56 ( V_15 , V_169 -> V_170 ) ;
F_18 ( V_15 ) ;
if ( V_21 )
return V_21 ;
F_57 ( V_17 ) ;
V_21 = F_58 ( V_17 , V_169 , V_20 ) ;
F_59 ( V_17 ) ;
return V_21 ;
}
static int F_60 ( struct V_1 * V_2 , struct V_168 * V_169 ,
T_5 V_20 , int V_47 )
{
struct V_2 * V_15 = V_2 -> V_15 ;
struct V_172 * V_173 = F_6 ( V_15 ) ;
int V_21 ;
F_12 ( V_15 ) ;
if ( V_15 -> V_28 == V_82 && F_41 ( V_119 ,
& F_43 ( V_15 ) -> V_47 ) ) {
if ( F_10 ( V_173 -> V_17 -> V_35 ) ) {
V_15 -> V_28 = V_55 ;
V_173 -> V_17 -> V_50 = V_55 ;
F_61 ( V_173 -> V_17 ) ;
} else {
V_15 -> V_28 = V_83 ;
V_173 -> V_17 -> V_50 = V_83 ;
F_62 ( V_173 -> V_17 ) ;
}
V_21 = 0 ;
goto V_31;
}
F_18 ( V_15 ) ;
if ( V_2 -> type == V_60 )
V_21 = F_63 ( V_2 , V_169 , V_20 , V_47 ) ;
else
V_21 = F_64 ( V_2 , V_169 , V_20 , V_47 ) ;
if ( V_173 -> V_17 -> V_48 != V_62 )
return V_21 ;
F_12 ( V_15 ) ;
if ( ! F_41 ( V_174 , & V_173 -> V_17 -> V_175 ) )
goto V_31;
if ( V_173 -> V_176 ) {
if ( ! F_65 ( V_15 , V_173 -> V_176 ) )
V_173 -> V_176 = NULL ;
else
goto V_31;
}
if ( F_66 ( & V_15 -> V_177 ) <= V_15 -> V_178 >> 1 )
F_67 ( V_173 -> V_17 , 0 ) ;
V_31:
F_18 ( V_15 ) ;
return V_21 ;
}
static void F_68 ( struct V_2 * V_15 )
{
if ( ! F_69 ( V_15 , V_179 ) || V_15 -> V_180 )
return;
F_7 ( L_6 , V_15 , F_70 ( V_15 -> V_28 ) ) ;
F_71 ( F_6 ( V_15 ) -> V_17 ) ;
F_72 ( V_15 , V_181 ) ;
F_73 ( V_15 ) ;
}
static int F_74 ( struct V_2 * V_15 , struct V_16 * V_17 )
{
F_75 ( V_72 , V_77 ) ;
int V_21 = 0 ;
int V_75 = V_182 ;
unsigned long V_183 = V_184 + V_185 ;
F_76 ( F_31 ( V_15 ) , & V_72 ) ;
F_77 ( V_78 ) ;
do {
F_7 ( L_7 ,
V_17 -> V_186 , F_78 ( V_184 , V_183 ) ? 0 :
F_79 ( V_183 - V_184 ) ) ;
if ( ! V_75 )
V_75 = V_182 ;
if ( F_33 ( V_77 ) ) {
V_21 = F_34 ( V_75 ) ;
break;
}
F_18 ( V_15 ) ;
V_75 = F_80 ( V_75 ) ;
F_12 ( V_15 ) ;
F_77 ( V_78 ) ;
V_21 = F_55 ( V_15 ) ;
if ( V_21 )
break;
if ( F_78 ( V_184 , V_183 ) ) {
V_21 = - V_187 ;
break;
}
} while ( V_17 -> V_186 > 0 &&
V_17 -> V_50 == V_55 );
F_77 ( V_188 ) ;
F_36 ( F_31 ( V_15 ) , & V_72 ) ;
return V_21 ;
}
static int F_81 ( struct V_1 * V_2 , int V_189 )
{
struct V_2 * V_15 = V_2 -> V_15 ;
struct V_16 * V_17 ;
struct V_153 * V_121 ;
int V_21 = 0 ;
F_7 ( L_5 , V_2 , V_15 ) ;
if ( ! V_15 )
return 0 ;
F_12 ( V_15 ) ;
if ( V_15 -> V_190 )
goto V_191;
F_7 ( L_8 ) ;
F_82 ( V_15 ) ;
V_17 = F_6 ( V_15 ) -> V_17 ;
F_83 ( V_17 ) ;
F_7 ( L_9 , V_17 , F_70 ( V_17 -> V_50 ) ) ;
if ( V_17 -> V_48 == V_62 &&
V_17 -> V_186 > 0 &&
V_17 -> V_50 == V_55 ) {
V_21 = F_74 ( V_15 , V_17 ) ;
if ( V_15 -> V_190 )
goto V_192;
}
V_15 -> V_190 = V_193 ;
F_18 ( V_15 ) ;
F_57 ( V_17 ) ;
V_121 = V_17 -> V_121 ;
if ( V_121 )
F_84 ( V_121 ) ;
F_59 ( V_17 ) ;
if ( V_121 )
F_85 ( & V_121 -> V_194 ) ;
F_57 ( V_17 ) ;
F_86 ( V_17 , 0 ) ;
F_59 ( V_17 ) ;
if ( V_121 ) {
F_87 ( & V_121 -> V_194 ) ;
F_88 ( V_121 ) ;
}
F_12 ( V_15 ) ;
if ( F_69 ( V_15 , V_195 ) && V_15 -> V_196 &&
! ( V_77 -> V_47 & V_197 ) )
V_21 = F_22 ( V_15 , V_198 ,
V_15 -> V_196 ) ;
V_192:
F_71 ( V_17 ) ;
F_73 ( V_15 ) ;
V_191:
if ( ! V_21 && V_15 -> V_199 )
V_21 = - V_15 -> V_199 ;
F_18 ( V_15 ) ;
F_7 ( L_10 , V_21 ) ;
return V_21 ;
}
static int F_89 ( struct V_1 * V_2 )
{
struct V_2 * V_15 = V_2 -> V_15 ;
int V_21 ;
F_7 ( L_5 , V_2 , V_15 ) ;
if ( ! V_15 )
return 0 ;
F_90 ( & V_200 , V_15 ) ;
V_21 = F_81 ( V_2 , 2 ) ;
F_91 ( V_15 ) ;
F_68 ( V_15 ) ;
return V_21 ;
}
static void F_92 ( struct V_2 * V_201 )
{
struct V_2 * V_15 ;
F_7 ( L_11 , V_201 ,
F_70 ( V_201 -> V_28 ) ) ;
while ( ( V_15 = F_32 ( V_201 , NULL ) ) ) {
struct V_16 * V_17 = F_6 ( V_15 ) -> V_17 ;
F_7 ( L_12 , V_17 ,
F_70 ( V_17 -> V_50 ) ) ;
F_57 ( V_17 ) ;
F_93 ( V_17 ) ;
F_86 ( V_17 , V_202 ) ;
F_59 ( V_17 ) ;
F_68 ( V_15 ) ;
}
}
static struct V_16 * F_94 ( struct V_16 * V_17 )
{
struct V_2 * V_15 , * V_201 = V_17 -> V_203 ;
F_12 ( V_201 ) ;
if ( F_95 ( V_201 ) ) {
F_7 ( L_13 , V_201 -> V_67 ) ;
F_18 ( V_201 ) ;
return NULL ;
}
V_15 = F_96 ( F_97 ( V_201 ) , NULL , V_204 ,
V_205 , 0 ) ;
if ( ! V_15 ) {
F_18 ( V_201 ) ;
return NULL ;
}
F_98 ( V_15 , V_204 ) ;
F_99 ( V_15 , V_201 ) ;
F_100 ( V_201 , V_15 ) ;
F_18 ( V_201 ) ;
return F_6 ( V_15 ) -> V_17 ;
}
static int F_101 ( struct V_16 * V_17 , struct V_206 * V_207 )
{
struct V_2 * V_15 = V_17 -> V_203 ;
int V_21 ;
F_12 ( V_15 ) ;
if ( F_6 ( V_15 ) -> V_176 ) {
V_21 = - V_208 ;
goto V_31;
}
V_21 = F_65 ( V_15 , V_207 ) ;
if ( V_21 < 0 && V_17 -> V_48 == V_62 ) {
F_6 ( V_15 ) -> V_176 = V_207 ;
F_67 ( V_17 , 1 ) ;
V_21 = 0 ;
}
V_31:
F_18 ( V_15 ) ;
return V_21 ;
}
static void F_102 ( struct V_16 * V_17 )
{
struct V_2 * V_15 = V_17 -> V_203 ;
F_68 ( V_15 ) ;
}
static void F_103 ( struct V_16 * V_17 , int V_21 )
{
struct V_2 * V_15 = V_17 -> V_203 ;
struct V_2 * V_201 ;
F_7 ( L_9 , V_17 , F_70 ( V_17 -> V_50 ) ) ;
F_28 ( V_15 , F_66 ( & V_17 -> V_68 ) ) ;
V_201 = F_43 ( V_15 ) -> V_201 ;
F_72 ( V_15 , V_179 ) ;
switch ( V_17 -> V_50 ) {
case V_29 :
case V_51 :
case V_198 :
break;
case V_70 :
F_92 ( V_15 ) ;
V_15 -> V_28 = V_198 ;
V_17 -> V_50 = V_198 ;
break;
default:
V_15 -> V_28 = V_198 ;
V_17 -> V_50 = V_198 ;
V_15 -> V_199 = V_21 ;
if ( V_201 ) {
F_104 ( V_15 ) ;
V_201 -> V_209 ( V_201 ) ;
} else {
V_15 -> V_156 ( V_15 ) ;
}
break;
}
F_18 ( V_15 ) ;
}
static void F_105 ( struct V_16 * V_17 , int V_50 ,
int V_21 )
{
struct V_2 * V_15 = V_17 -> V_203 ;
V_15 -> V_28 = V_50 ;
if ( V_21 )
V_15 -> V_199 = V_21 ;
}
static struct V_206 * F_106 ( struct V_16 * V_17 ,
unsigned long V_210 ,
unsigned long V_20 , int V_211 )
{
struct V_2 * V_15 = V_17 -> V_203 ;
struct V_206 * V_207 ;
int V_21 ;
F_59 ( V_17 ) ;
V_207 = F_107 ( V_15 , V_210 + V_20 , V_211 , & V_21 ) ;
F_57 ( V_17 ) ;
if ( ! V_207 )
return F_108 ( V_21 ) ;
V_207 -> V_212 = V_15 -> V_213 ;
F_109 ( V_207 ) -> V_214 . V_17 = V_17 ;
return V_207 ;
}
static void F_110 ( struct V_16 * V_17 )
{
struct V_2 * V_15 = V_17 -> V_203 ;
struct V_2 * V_201 ;
F_12 ( V_15 ) ;
V_201 = F_43 ( V_15 ) -> V_201 ;
F_7 ( L_14 , V_15 , V_201 ) ;
V_15 -> V_28 = V_55 ;
V_15 -> V_156 ( V_15 ) ;
if ( V_201 )
V_201 -> V_209 ( V_201 ) ;
F_18 ( V_15 ) ;
}
static void F_111 ( struct V_16 * V_17 )
{
struct V_2 * V_201 , * V_15 = V_17 -> V_203 ;
F_12 ( V_15 ) ;
V_201 = F_43 ( V_15 ) -> V_201 ;
if ( V_201 )
V_201 -> V_209 ( V_201 ) ;
F_18 ( V_15 ) ;
}
static void F_112 ( struct V_16 * V_17 )
{
struct V_2 * V_15 = V_17 -> V_203 ;
if ( F_113 ( V_154 , & V_17 -> V_47 ) ) {
V_15 -> V_28 = V_55 ;
V_17 -> V_50 = V_55 ;
}
F_48 ( V_155 , & F_43 ( V_15 ) -> V_47 ) ;
V_15 -> V_156 ( V_15 ) ;
}
static void F_114 ( struct V_16 * V_17 )
{
struct V_2 * V_15 = V_17 -> V_203 ;
F_12 ( V_15 ) ;
V_15 -> V_190 = V_193 ;
F_18 ( V_15 ) ;
}
static long F_115 ( struct V_16 * V_17 )
{
struct V_2 * V_15 = V_17 -> V_203 ;
return V_15 -> V_215 ;
}
static void F_116 ( struct V_16 * V_17 )
{
struct V_2 * V_15 = V_17 -> V_203 ;
F_17 ( V_155 , & F_43 ( V_15 ) -> V_47 ) ;
V_15 -> V_156 ( V_15 ) ;
}
static void F_117 ( struct V_2 * V_15 )
{
F_7 ( L_1 , V_15 ) ;
if ( F_6 ( V_15 ) -> V_17 )
F_71 ( F_6 ( V_15 ) -> V_17 ) ;
if ( F_6 ( V_15 ) -> V_176 ) {
F_118 ( F_6 ( V_15 ) -> V_176 ) ;
F_6 ( V_15 ) -> V_176 = NULL ;
}
F_119 ( & V_15 -> V_216 ) ;
F_119 ( & V_15 -> V_217 ) ;
}
static void F_120 ( struct V_206 * V_207 , void * V_218 ,
int * V_219 )
{
F_121 ( struct V_18 * , V_19 , V_218 ) ;
memset ( V_19 , 0 , sizeof( struct V_18 ) ) ;
V_19 -> V_220 = V_23 ;
V_19 -> V_25 = F_109 ( V_207 ) -> V_214 . V_5 ;
F_14 ( & V_19 -> V_34 , & F_109 ( V_207 ) -> V_214 . V_221 ) ;
* V_219 = sizeof( struct V_18 ) ;
}
static void F_99 ( struct V_2 * V_15 , struct V_2 * V_201 )
{
struct V_16 * V_17 = F_6 ( V_15 ) -> V_17 ;
F_7 ( L_1 , V_15 ) ;
if ( V_201 ) {
struct V_16 * V_222 = F_6 ( V_201 ) -> V_17 ;
V_15 -> V_58 = V_201 -> V_58 ;
F_43 ( V_15 ) -> V_47 = F_43 ( V_201 ) -> V_47 ;
V_17 -> V_36 = V_222 -> V_36 ;
V_17 -> V_98 = V_222 -> V_98 ;
V_17 -> V_99 = V_222 -> V_99 ;
V_17 -> V_152 = V_222 -> V_152 ;
V_17 -> V_48 = V_222 -> V_48 ;
V_17 -> V_101 = V_222 -> V_101 ;
V_17 -> V_102 = V_222 -> V_102 ;
V_17 -> V_104 = V_222 -> V_104 ;
V_17 -> V_223 = V_222 -> V_223 ;
V_17 -> V_39 = V_222 -> V_39 ;
V_17 -> V_47 = V_222 -> V_47 ;
V_17 -> V_224 = V_222 -> V_224 ;
V_17 -> V_225 = V_222 -> V_225 ;
if ( V_17 -> V_36 == V_45 ) {
V_17 -> V_53 = V_222 -> V_53 ;
V_17 -> V_86 = V_222 -> V_53 ;
}
F_122 ( V_201 , V_15 ) ;
} else {
switch ( V_15 -> V_58 ) {
case V_140 :
V_17 -> V_36 = V_44 ;
break;
case V_226 :
V_17 -> V_36 = V_37 ;
F_43 ( V_15 ) -> V_227 = F_120 ;
break;
case V_59 :
case V_60 :
V_17 -> V_36 = V_41 ;
break;
}
V_17 -> V_98 = V_228 ;
V_17 -> V_99 = 0 ;
if ( ! V_64 && V_15 -> V_58 == V_60 ) {
V_17 -> V_48 = V_62 ;
F_17 ( V_151 , & V_17 -> V_152 ) ;
} else {
V_17 -> V_48 = V_61 ;
}
F_123 ( V_17 ) ;
}
V_17 -> V_100 = V_229 ;
V_17 -> V_203 = V_15 ;
V_17 -> V_3 = & V_230 ;
}
static struct V_2 * F_96 ( struct V_231 * V_231 , struct V_1 * V_2 ,
int V_232 , T_6 V_233 , int V_234 )
{
struct V_2 * V_15 ;
struct V_16 * V_17 ;
V_15 = F_124 ( V_231 , V_235 , V_233 , & V_236 , V_234 ) ;
if ( ! V_15 )
return NULL ;
F_125 ( V_2 , V_15 ) ;
F_126 ( & F_43 ( V_15 ) -> V_237 ) ;
V_15 -> V_238 = F_117 ;
V_15 -> V_215 = V_239 ;
F_127 ( V_15 , V_179 ) ;
V_15 -> V_240 = V_232 ;
V_15 -> V_28 = V_29 ;
V_17 = F_128 () ;
if ( ! V_17 ) {
F_129 ( V_15 ) ;
return NULL ;
}
F_83 ( V_17 ) ;
F_6 ( V_15 ) -> V_17 = V_17 ;
return V_15 ;
}
static int F_130 ( struct V_231 * V_231 , struct V_1 * V_2 , int V_241 ,
int V_234 )
{
struct V_2 * V_15 ;
F_7 ( L_15 , V_2 ) ;
V_2 -> V_50 = V_242 ;
if ( V_2 -> type != V_59 && V_2 -> type != V_60 &&
V_2 -> type != V_226 && V_2 -> type != V_140 )
return - V_243 ;
if ( V_2 -> type == V_140 && ! V_234 && ! F_3 ( V_244 ) )
return - V_166 ;
V_2 -> V_3 = & V_4 ;
V_15 = F_96 ( V_231 , V_2 , V_241 , V_205 , V_234 ) ;
if ( ! V_15 )
return - V_208 ;
F_99 ( V_15 , NULL ) ;
F_131 ( & V_200 , V_15 ) ;
return 0 ;
}
int T_7 F_132 ( void )
{
int V_21 ;
F_133 ( sizeof( struct V_18 ) > sizeof( struct V_12 ) ) ;
V_21 = F_134 ( & V_236 , 0 ) ;
if ( V_21 < 0 )
return V_21 ;
V_21 = F_135 ( V_204 , & V_245 ) ;
if ( V_21 < 0 ) {
F_136 ( L_16 ) ;
goto error;
}
V_21 = F_137 ( & V_246 , L_17 , & V_200 ,
NULL ) ;
if ( V_21 < 0 ) {
F_136 ( L_18 ) ;
F_138 ( V_204 ) ;
goto error;
}
F_139 ( L_19 ) ;
return 0 ;
error:
F_140 ( & V_236 ) ;
return V_21 ;
}
void F_141 ( void )
{
F_142 ( & V_246 , L_17 ) ;
F_138 ( V_204 ) ;
F_140 ( & V_236 ) ;
}
