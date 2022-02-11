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
if ( F_10 ( V_16 . V_23 ) ) {
if ( ! V_24 && V_16 . V_22 )
return - V_6 ;
if ( V_16 . V_21 &&
V_16 . V_21 != F_11 ( V_25 ) )
return - V_6 ;
}
F_12 ( V_12 ) ;
if ( V_12 -> V_26 != V_27 ) {
V_18 = - V_28 ;
goto V_29;
}
if ( V_16 . V_22 ) {
T_2 V_5 = F_13 ( V_16 . V_22 ) ;
if ( V_16 . V_23 == V_30 )
V_18 = F_2 ( V_5 ) ;
else
V_18 = F_4 ( V_5 ) ;
if ( V_18 )
goto V_29;
}
if ( V_16 . V_21 )
V_18 = F_14 ( V_14 , F_13 ( V_16 . V_21 ) ) ;
else
V_18 = F_15 ( V_14 , & V_16 . V_31 , V_16 . V_22 ) ;
if ( V_18 < 0 )
goto V_29;
switch ( V_14 -> V_32 ) {
case V_33 :
if ( F_13 ( V_16 . V_22 ) == V_34 )
V_14 -> V_35 = V_36 ;
break;
case V_37 :
if ( F_13 ( V_16 . V_22 ) == V_38 ||
F_13 ( V_16 . V_22 ) == V_39 )
V_14 -> V_35 = V_36 ;
break;
case V_40 :
V_14 -> V_35 = V_36 ;
break;
}
F_16 ( & V_14 -> V_41 , & V_16 . V_31 ) ;
V_14 -> V_42 = V_16 . V_23 ;
if ( V_14 -> V_5 && F_10 ( V_14 -> V_42 ) )
V_14 -> V_43 = V_44 ;
V_14 -> V_45 = V_46 ;
V_12 -> V_26 = V_46 ;
V_29:
F_17 ( V_12 ) ;
return V_18 ;
}
static int F_18 ( struct V_1 * V_2 , struct V_9 * V_10 ,
int V_11 , int V_47 )
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
if ( V_14 -> V_42 == V_30 && F_19 ( & V_14 -> V_41 , V_48 ) &&
F_10 ( V_16 . V_23 ) ) {
if ( V_14 -> V_49 != V_25 ||
V_16 . V_21 != F_11 ( V_25 ) )
return - V_6 ;
V_14 -> V_42 = V_50 ;
}
if ( V_14 -> V_42 != V_30 && V_16 . V_23 == V_30 )
return - V_6 ;
if ( F_10 ( V_16 . V_23 ) ) {
if ( ! V_24 && V_16 . V_22 )
return - V_6 ;
if ( V_16 . V_21 &&
V_16 . V_21 != F_11 ( V_25 ) )
return - V_6 ;
}
if ( V_14 -> V_5 && F_10 ( V_14 -> V_42 ) )
V_14 -> V_43 = V_44 ;
V_18 = F_20 ( V_14 , V_16 . V_22 , F_13 ( V_16 . V_21 ) ,
& V_16 . V_31 , V_16 . V_23 ) ;
if ( V_18 )
return V_18 ;
F_12 ( V_12 ) ;
V_18 = F_21 ( V_12 , V_51 ,
F_22 ( V_12 , V_47 & V_52 ) ) ;
F_17 ( V_12 ) ;
return V_18 ;
}
static int F_23 ( struct V_1 * V_2 , int V_53 )
{
struct V_2 * V_12 = V_2 -> V_12 ;
struct V_13 * V_14 = F_6 ( V_12 ) -> V_14 ;
int V_18 = 0 ;
F_7 ( L_2 , V_12 , V_53 ) ;
F_12 ( V_12 ) ;
if ( V_12 -> V_26 != V_46 ) {
V_18 = - V_28 ;
goto V_29;
}
if ( V_12 -> V_54 != V_55 && V_12 -> V_54 != V_56 ) {
V_18 = - V_6 ;
goto V_29;
}
switch ( V_14 -> V_43 ) {
case V_57 :
case V_44 :
break;
case V_58 :
case V_59 :
if ( ! V_60 )
break;
default:
V_18 = - V_61 ;
goto V_29;
}
V_12 -> V_62 = V_53 ;
V_12 -> V_63 = 0 ;
V_14 -> V_45 = V_64 ;
V_12 -> V_26 = V_64 ;
V_29:
F_17 ( V_12 ) ;
return V_18 ;
}
static int F_24 ( struct V_1 * V_2 , struct V_1 * V_65 ,
int V_47 )
{
F_25 ( V_66 , V_67 ) ;
struct V_2 * V_12 = V_2 -> V_12 , * V_68 ;
long V_69 ;
int V_18 = 0 ;
F_26 ( V_12 , V_70 ) ;
V_69 = F_27 ( V_12 , V_47 & V_52 ) ;
F_7 ( L_3 , V_12 , V_69 ) ;
F_28 ( F_29 ( V_12 ) , & V_66 ) ;
while ( 1 ) {
F_30 ( V_71 ) ;
if ( V_12 -> V_26 != V_64 ) {
V_18 = - V_28 ;
break;
}
V_68 = F_31 ( V_12 , V_65 ) ;
if ( V_68 )
break;
if ( ! V_69 ) {
V_18 = - V_72 ;
break;
}
if ( F_32 ( V_67 ) ) {
V_18 = F_33 ( V_69 ) ;
break;
}
F_17 ( V_12 ) ;
V_69 = F_34 ( V_69 ) ;
F_26 ( V_12 , V_70 ) ;
}
F_35 ( V_73 ) ;
F_36 ( F_29 ( V_12 ) , & V_66 ) ;
if ( V_18 )
goto V_29;
V_65 -> V_45 = V_74 ;
F_7 ( L_4 , V_68 ) ;
V_29:
F_17 ( V_12 ) ;
return V_18 ;
}
static int F_37 ( struct V_1 * V_2 , struct V_9 * V_10 ,
int * V_17 , int V_75 )
{
struct V_15 * V_16 = (struct V_15 * ) V_10 ;
struct V_2 * V_12 = V_2 -> V_12 ;
struct V_13 * V_14 = F_6 ( V_12 ) -> V_14 ;
F_7 ( L_5 , V_2 , V_12 ) ;
memset ( V_16 , 0 , sizeof( struct V_15 ) ) ;
V_10 -> V_19 = V_20 ;
* V_17 = sizeof( struct V_15 ) ;
if ( V_75 ) {
V_16 -> V_22 = V_14 -> V_5 ;
F_16 ( & V_16 -> V_31 , & V_14 -> V_76 ) ;
V_16 -> V_21 = F_38 ( V_14 -> V_77 ) ;
V_16 -> V_23 = V_14 -> V_78 ;
} else {
V_16 -> V_22 = V_14 -> V_79 ;
F_16 ( & V_16 -> V_31 , & V_14 -> V_41 ) ;
V_16 -> V_21 = F_38 ( V_14 -> V_49 ) ;
V_16 -> V_23 = V_14 -> V_42 ;
}
return 0 ;
}
static int F_39 ( struct V_1 * V_2 , int V_80 ,
char T_3 * V_81 , int T_3 * V_82 )
{
struct V_2 * V_12 = V_2 -> V_12 ;
struct V_13 * V_14 = F_6 ( V_12 ) -> V_14 ;
struct V_83 V_84 ;
struct V_85 V_86 ;
int V_17 , V_18 = 0 ;
T_4 V_87 ;
F_7 ( L_1 , V_12 ) ;
if ( F_40 ( V_17 , V_82 ) )
return - V_88 ;
F_12 ( V_12 ) ;
switch ( V_80 ) {
case V_89 :
if ( F_10 ( V_14 -> V_42 ) &&
V_14 -> V_49 != V_25 ) {
V_18 = - V_6 ;
break;
}
memset ( & V_84 , 0 , sizeof( V_84 ) ) ;
V_84 . V_90 = V_14 -> V_90 ;
V_84 . V_91 = V_14 -> V_91 ;
V_84 . V_92 = V_14 -> V_92 ;
V_84 . V_43 = V_14 -> V_43 ;
V_84 . V_93 = V_14 -> V_93 ;
V_84 . V_94 = V_14 -> V_94 ;
V_84 . V_95 = V_14 -> V_96 ;
V_17 = F_8 (unsigned int, len, sizeof(opts)) ;
if ( F_41 ( V_81 , ( char * ) & V_84 , V_17 ) )
V_18 = - V_88 ;
break;
case V_97 :
switch ( V_14 -> V_35 ) {
case V_98 :
V_87 = V_99 ;
break;
case V_100 :
V_87 = V_99 | V_101 ;
break;
case V_102 :
V_87 = V_99 | V_101 |
V_103 ;
break;
default:
V_87 = 0 ;
break;
}
if ( F_42 ( V_104 , & V_14 -> V_47 ) )
V_87 |= V_105 ;
if ( F_42 ( V_106 , & V_14 -> V_47 ) )
V_87 |= V_107 ;
if ( F_43 ( V_87 , ( T_4 T_3 * ) V_81 ) )
V_18 = - V_88 ;
break;
case V_108 :
if ( V_12 -> V_26 != V_51 &&
! ( V_12 -> V_26 == V_109 &&
F_42 ( V_110 , & F_44 ( V_12 ) -> V_47 ) ) ) {
V_18 = - V_111 ;
break;
}
memset ( & V_86 , 0 , sizeof( V_86 ) ) ;
V_86 . V_112 = V_14 -> V_113 -> V_114 -> V_115 ;
memcpy ( V_86 . V_116 , V_14 -> V_113 -> V_114 -> V_116 , 3 ) ;
V_17 = F_8 (unsigned int, len, sizeof(cinfo)) ;
if ( F_41 ( V_81 , ( char * ) & V_86 , V_17 ) )
V_18 = - V_88 ;
break;
default:
V_18 = - V_117 ;
break;
}
F_17 ( V_12 ) ;
return V_18 ;
}
static int F_45 ( struct V_1 * V_2 , int V_118 , int V_80 ,
char T_3 * V_81 , int T_3 * V_82 )
{
struct V_2 * V_12 = V_2 -> V_12 ;
struct V_13 * V_14 = F_6 ( V_12 ) -> V_14 ;
struct V_119 V_120 ;
struct V_121 V_122 ;
int V_17 , V_18 = 0 ;
F_7 ( L_1 , V_12 ) ;
if ( V_118 == V_123 )
return F_39 ( V_2 , V_80 , V_81 , V_82 ) ;
if ( V_118 != V_124 )
return - V_117 ;
if ( F_40 ( V_17 , V_82 ) )
return - V_88 ;
F_12 ( V_12 ) ;
switch ( V_80 ) {
case V_125 :
if ( V_14 -> V_32 != V_37 &&
V_14 -> V_32 != V_40 ) {
V_18 = - V_6 ;
break;
}
memset ( & V_120 , 0 , sizeof( V_120 ) ) ;
if ( V_14 -> V_113 ) {
V_120 . V_118 = V_14 -> V_113 -> V_114 -> V_35 ;
if ( V_12 -> V_26 == V_51 )
V_120 . V_126 = V_14 -> V_113 -> V_114 -> V_127 ;
} else {
V_120 . V_118 = V_14 -> V_35 ;
}
V_17 = F_8 (unsigned int, len, sizeof(sec)) ;
if ( F_41 ( V_81 , ( char * ) & V_120 , V_17 ) )
V_18 = - V_88 ;
break;
case V_128 :
if ( V_12 -> V_26 != V_46 && V_12 -> V_26 != V_64 ) {
V_18 = - V_6 ;
break;
}
if ( F_43 ( F_42 ( V_110 , & F_44 ( V_12 ) -> V_47 ) ,
( T_4 T_3 * ) V_81 ) )
V_18 = - V_88 ;
break;
case V_129 :
if ( F_43 ( F_42 ( V_130 , & V_14 -> V_47 ) ,
( T_4 T_3 * ) V_81 ) )
V_18 = - V_88 ;
break;
case V_131 :
if ( V_12 -> V_54 != V_55 && V_12 -> V_54 != V_56
&& V_12 -> V_54 != V_132 ) {
V_18 = - V_6 ;
break;
}
V_122 . V_133 = F_42 ( V_134 , & V_14 -> V_47 ) ;
V_17 = F_8 (unsigned int, len, sizeof(pwr)) ;
if ( F_41 ( V_81 , ( char * ) & V_122 , V_17 ) )
V_18 = - V_88 ;
break;
case V_135 :
if ( F_43 ( V_14 -> V_136 , ( T_4 T_3 * ) V_81 ) )
V_18 = - V_88 ;
break;
case V_137 :
if ( ! V_24 ) {
V_18 = - V_138 ;
break;
}
if ( ! F_10 ( V_14 -> V_42 ) ) {
V_18 = - V_6 ;
break;
}
if ( V_12 -> V_26 != V_51 ) {
V_18 = - V_111 ;
break;
}
if ( F_43 ( V_14 -> V_91 , ( T_1 T_3 * ) V_81 ) )
V_18 = - V_88 ;
break;
case V_139 :
if ( ! V_24 ) {
V_18 = - V_138 ;
break;
}
if ( ! F_10 ( V_14 -> V_42 ) ) {
V_18 = - V_6 ;
break;
}
if ( F_43 ( V_14 -> V_90 , ( T_1 T_3 * ) V_81 ) )
V_18 = - V_88 ;
break;
default:
V_18 = - V_117 ;
break;
}
F_17 ( V_12 ) ;
return V_18 ;
}
static bool F_46 ( struct V_13 * V_14 , T_1 V_140 )
{
switch ( V_14 -> V_49 ) {
case V_25 :
if ( V_140 < V_141 )
return false ;
break;
default:
if ( V_140 < V_142 )
return false ;
}
return true ;
}
static int F_47 ( struct V_1 * V_2 , int V_80 ,
char T_3 * V_81 , unsigned int V_82 )
{
struct V_2 * V_12 = V_2 -> V_12 ;
struct V_13 * V_14 = F_6 ( V_12 ) -> V_14 ;
struct V_83 V_84 ;
int V_17 , V_18 = 0 ;
T_4 V_87 ;
F_7 ( L_1 , V_12 ) ;
F_12 ( V_12 ) ;
switch ( V_80 ) {
case V_89 :
if ( F_10 ( V_14 -> V_42 ) ) {
V_18 = - V_6 ;
break;
}
if ( V_12 -> V_26 == V_51 ) {
V_18 = - V_6 ;
break;
}
V_84 . V_90 = V_14 -> V_90 ;
V_84 . V_91 = V_14 -> V_91 ;
V_84 . V_92 = V_14 -> V_92 ;
V_84 . V_43 = V_14 -> V_43 ;
V_84 . V_93 = V_14 -> V_93 ;
V_84 . V_94 = V_14 -> V_94 ;
V_84 . V_95 = V_14 -> V_96 ;
V_17 = F_8 (unsigned int, sizeof(opts), optlen) ;
if ( F_48 ( ( char * ) & V_84 , V_81 , V_17 ) ) {
V_18 = - V_88 ;
break;
}
if ( V_84 . V_95 > V_143 ) {
V_18 = - V_6 ;
break;
}
if ( ! F_46 ( V_14 , V_84 . V_90 ) ) {
V_18 = - V_6 ;
break;
}
V_14 -> V_43 = V_84 . V_43 ;
switch ( V_14 -> V_43 ) {
case V_44 :
break;
case V_57 :
F_49 ( V_144 , & V_14 -> V_145 ) ;
break;
case V_58 :
case V_59 :
if ( ! V_60 )
break;
default:
V_18 = - V_6 ;
break;
}
V_14 -> V_90 = V_84 . V_90 ;
V_14 -> V_91 = V_84 . V_91 ;
V_14 -> V_93 = V_84 . V_93 ;
V_14 -> V_94 = V_84 . V_94 ;
V_14 -> V_96 = V_84 . V_95 ;
V_14 -> V_92 = V_84 . V_92 ;
break;
case V_97 :
if ( F_40 ( V_87 , ( T_4 T_3 * ) V_81 ) ) {
V_18 = - V_88 ;
break;
}
if ( V_87 & V_99 )
V_14 -> V_35 = V_98 ;
if ( V_87 & V_101 )
V_14 -> V_35 = V_100 ;
if ( V_87 & V_103 )
V_14 -> V_35 = V_102 ;
if ( V_87 & V_105 )
F_50 ( V_104 , & V_14 -> V_47 ) ;
else
F_49 ( V_104 , & V_14 -> V_47 ) ;
if ( V_87 & V_107 )
F_50 ( V_106 , & V_14 -> V_47 ) ;
else
F_49 ( V_106 , & V_14 -> V_47 ) ;
break;
default:
V_18 = - V_117 ;
break;
}
F_17 ( V_12 ) ;
return V_18 ;
}
static int F_51 ( struct V_1 * V_2 , int V_118 , int V_80 ,
char T_3 * V_81 , unsigned int V_82 )
{
struct V_2 * V_12 = V_2 -> V_12 ;
struct V_13 * V_14 = F_6 ( V_12 ) -> V_14 ;
struct V_119 V_120 ;
struct V_121 V_122 ;
struct V_146 * V_113 ;
int V_17 , V_18 = 0 ;
T_4 V_87 ;
F_7 ( L_1 , V_12 ) ;
if ( V_118 == V_123 )
return F_47 ( V_2 , V_80 , V_81 , V_82 ) ;
if ( V_118 != V_124 )
return - V_117 ;
F_12 ( V_12 ) ;
switch ( V_80 ) {
case V_125 :
if ( V_14 -> V_32 != V_37 &&
V_14 -> V_32 != V_40 ) {
V_18 = - V_6 ;
break;
}
V_120 . V_118 = V_98 ;
V_17 = F_8 (unsigned int, sizeof(sec), optlen) ;
if ( F_48 ( ( char * ) & V_120 , V_81 , V_17 ) ) {
V_18 = - V_88 ;
break;
}
if ( V_120 . V_118 < V_98 ||
V_120 . V_118 > V_102 ) {
V_18 = - V_6 ;
break;
}
V_14 -> V_35 = V_120 . V_118 ;
if ( ! V_14 -> V_113 )
break;
V_113 = V_14 -> V_113 ;
if ( V_14 -> V_49 == V_25 ) {
if ( ! V_113 -> V_114 -> V_147 ) {
V_18 = - V_6 ;
break;
}
if ( F_52 ( V_113 -> V_114 , V_120 . V_118 ) )
break;
V_12 -> V_26 = V_148 ;
V_14 -> V_45 = V_148 ;
} else if ( ( V_12 -> V_26 == V_109 &&
F_42 ( V_110 , & F_44 ( V_12 ) -> V_47 ) ) ||
V_12 -> V_26 == V_51 ) {
if ( ! F_53 ( V_14 ) )
F_50 ( V_149 , & F_44 ( V_12 ) -> V_47 ) ;
else
V_12 -> V_150 ( V_12 ) ;
} else {
V_18 = - V_6 ;
}
break;
case V_128 :
if ( V_12 -> V_26 != V_46 && V_12 -> V_26 != V_64 ) {
V_18 = - V_6 ;
break;
}
if ( F_40 ( V_87 , ( T_4 T_3 * ) V_81 ) ) {
V_18 = - V_88 ;
break;
}
if ( V_87 ) {
F_50 ( V_110 , & F_44 ( V_12 ) -> V_47 ) ;
F_50 ( V_151 , & V_14 -> V_47 ) ;
} else {
F_49 ( V_110 , & F_44 ( V_12 ) -> V_47 ) ;
F_49 ( V_151 , & V_14 -> V_47 ) ;
}
break;
case V_129 :
if ( F_40 ( V_87 , ( T_4 T_3 * ) V_81 ) ) {
V_18 = - V_88 ;
break;
}
if ( V_87 > V_152 ) {
V_18 = - V_6 ;
break;
}
if ( V_87 == V_153 ) {
V_113 = V_14 -> V_113 ;
if ( ! V_113 || ! F_54 ( V_113 -> V_114 -> V_154 ) ) {
V_18 = - V_6 ;
break;
}
}
if ( V_87 )
F_50 ( V_130 , & V_14 -> V_47 ) ;
else
F_49 ( V_130 , & V_14 -> V_47 ) ;
break;
case V_131 :
if ( V_14 -> V_32 != V_37 &&
V_14 -> V_32 != V_40 ) {
V_18 = - V_6 ;
break;
}
V_122 . V_133 = V_155 ;
V_17 = F_8 (unsigned int, sizeof(pwr), optlen) ;
if ( F_48 ( ( char * ) & V_122 , V_81 , V_17 ) ) {
V_18 = - V_88 ;
break;
}
if ( V_122 . V_133 )
F_50 ( V_134 , & V_14 -> V_47 ) ;
else
F_49 ( V_134 , & V_14 -> V_47 ) ;
break;
case V_135 :
if ( F_40 ( V_87 , ( T_4 T_3 * ) V_81 ) ) {
V_18 = - V_88 ;
break;
}
if ( V_87 > V_156 ) {
V_18 = - V_6 ;
break;
}
if ( V_14 -> V_43 != V_58 &&
V_14 -> V_43 != V_59 ) {
V_18 = - V_157 ;
break;
}
V_14 -> V_136 = ( V_158 ) V_87 ;
if ( V_12 -> V_26 == V_51 &&
V_14 -> V_159 == V_160 )
F_55 ( V_14 ) ;
break;
case V_137 :
if ( ! V_24 ) {
V_18 = - V_138 ;
break;
}
if ( ! F_10 ( V_14 -> V_42 ) ) {
V_18 = - V_6 ;
break;
}
V_18 = - V_161 ;
break;
case V_139 :
if ( ! V_24 ) {
V_18 = - V_138 ;
break;
}
if ( ! F_10 ( V_14 -> V_42 ) ) {
V_18 = - V_6 ;
break;
}
if ( V_12 -> V_26 == V_51 ) {
V_18 = - V_162 ;
break;
}
if ( F_40 ( V_87 , ( T_4 T_3 * ) V_81 ) ) {
V_18 = - V_88 ;
break;
}
V_14 -> V_90 = V_87 ;
break;
default:
V_18 = - V_117 ;
break;
}
F_17 ( V_12 ) ;
return V_18 ;
}
static int F_56 ( struct V_163 * V_164 , struct V_1 * V_2 ,
struct V_165 * V_166 , T_5 V_17 )
{
struct V_2 * V_12 = V_2 -> V_12 ;
struct V_13 * V_14 = F_6 ( V_12 ) -> V_14 ;
int V_18 ;
F_7 ( L_5 , V_2 , V_12 ) ;
V_18 = F_57 ( V_12 ) ;
if ( V_18 )
return V_18 ;
if ( V_166 -> V_167 & V_168 )
return - V_157 ;
if ( V_12 -> V_26 != V_51 )
return - V_111 ;
F_12 ( V_12 ) ;
V_18 = F_58 ( V_12 , V_166 -> V_167 ) ;
F_17 ( V_12 ) ;
if ( V_18 )
return V_18 ;
F_59 ( V_14 ) ;
V_18 = F_60 ( V_14 , V_166 , V_17 , V_12 -> V_169 ) ;
F_61 ( V_14 ) ;
return V_18 ;
}
static int F_62 ( struct V_163 * V_164 , struct V_1 * V_2 ,
struct V_165 * V_166 , T_5 V_17 , int V_47 )
{
struct V_2 * V_12 = V_2 -> V_12 ;
struct V_170 * V_171 = F_6 ( V_12 ) ;
int V_18 ;
F_12 ( V_12 ) ;
if ( V_12 -> V_26 == V_109 && F_42 ( V_110 ,
& F_44 ( V_12 ) -> V_47 ) ) {
if ( F_10 ( V_171 -> V_14 -> V_42 ) ) {
V_12 -> V_26 = V_51 ;
V_171 -> V_14 -> V_45 = V_51 ;
F_63 ( V_171 -> V_14 ) ;
} else {
V_12 -> V_26 = V_148 ;
V_171 -> V_14 -> V_45 = V_148 ;
F_64 ( V_171 -> V_14 ) ;
}
V_18 = 0 ;
goto V_29;
}
F_17 ( V_12 ) ;
if ( V_2 -> type == V_56 )
V_18 = F_65 ( V_164 , V_2 , V_166 , V_17 , V_47 ) ;
else
V_18 = F_66 ( V_164 , V_2 , V_166 , V_17 , V_47 ) ;
if ( V_171 -> V_14 -> V_43 != V_58 )
return V_18 ;
F_12 ( V_12 ) ;
if ( ! F_42 ( V_172 , & V_171 -> V_14 -> V_173 ) )
goto V_29;
if ( V_171 -> V_174 ) {
if ( ! F_67 ( V_12 , V_171 -> V_174 ) )
V_171 -> V_174 = NULL ;
else
goto V_29;
}
if ( F_68 ( & V_12 -> V_175 ) <= V_12 -> V_176 >> 1 )
F_69 ( V_171 -> V_14 , 0 ) ;
V_29:
F_17 ( V_12 ) ;
return V_18 ;
}
static void F_70 ( struct V_2 * V_12 )
{
if ( ! F_71 ( V_12 , V_177 ) || V_12 -> V_178 )
return;
F_7 ( L_6 , V_12 , F_72 ( V_12 -> V_26 ) ) ;
F_73 ( F_6 ( V_12 ) -> V_14 ) ;
F_74 ( V_12 , V_179 ) ;
F_75 ( V_12 ) ;
}
static int F_76 ( struct V_2 * V_12 )
{
struct V_13 * V_14 = F_6 ( V_12 ) -> V_14 ;
F_25 ( V_66 , V_67 ) ;
int V_18 = 0 ;
int V_69 = V_180 / 5 ;
F_77 ( F_29 ( V_12 ) , & V_66 ) ;
F_30 ( V_71 ) ;
while ( V_14 -> V_181 > 0 && V_14 -> V_113 ) {
if ( ! V_69 )
V_69 = V_180 / 5 ;
if ( F_32 ( V_67 ) ) {
V_18 = F_33 ( V_69 ) ;
break;
}
F_17 ( V_12 ) ;
V_69 = F_34 ( V_69 ) ;
F_12 ( V_12 ) ;
F_30 ( V_71 ) ;
V_18 = F_57 ( V_12 ) ;
if ( V_18 )
break;
}
F_30 ( V_73 ) ;
F_36 ( F_29 ( V_12 ) , & V_66 ) ;
return V_18 ;
}
static int F_78 ( struct V_1 * V_2 , int V_182 )
{
struct V_2 * V_12 = V_2 -> V_12 ;
struct V_13 * V_14 ;
struct V_146 * V_113 ;
int V_18 = 0 ;
F_7 ( L_5 , V_2 , V_12 ) ;
if ( ! V_12 )
return 0 ;
V_14 = F_6 ( V_12 ) -> V_14 ;
V_113 = V_14 -> V_113 ;
if ( V_113 )
F_79 ( & V_113 -> V_183 ) ;
F_59 ( V_14 ) ;
F_12 ( V_12 ) ;
if ( ! V_12 -> V_184 ) {
if ( V_14 -> V_43 == V_58 )
V_18 = F_76 ( V_12 ) ;
V_12 -> V_184 = V_185 ;
F_17 ( V_12 ) ;
F_80 ( V_14 , 0 ) ;
F_12 ( V_12 ) ;
if ( F_71 ( V_12 , V_186 ) && V_12 -> V_187 )
V_18 = F_21 ( V_12 , V_188 ,
V_12 -> V_187 ) ;
}
if ( ! V_18 && V_12 -> V_189 )
V_18 = - V_12 -> V_189 ;
F_17 ( V_12 ) ;
F_61 ( V_14 ) ;
if ( V_113 )
F_81 ( & V_113 -> V_183 ) ;
return V_18 ;
}
static int F_82 ( struct V_1 * V_2 )
{
struct V_2 * V_12 = V_2 -> V_12 ;
int V_18 ;
F_7 ( L_5 , V_2 , V_12 ) ;
if ( ! V_12 )
return 0 ;
F_83 ( & V_190 , V_12 ) ;
V_18 = F_78 ( V_2 , 2 ) ;
F_84 ( V_12 ) ;
F_70 ( V_12 ) ;
return V_18 ;
}
static void F_85 ( struct V_2 * V_191 )
{
struct V_2 * V_12 ;
F_7 ( L_7 , V_191 ) ;
while ( ( V_12 = F_31 ( V_191 , NULL ) ) ) {
struct V_13 * V_14 = F_6 ( V_12 ) -> V_14 ;
F_59 ( V_14 ) ;
F_86 ( V_14 ) ;
F_80 ( V_14 , V_192 ) ;
F_61 ( V_14 ) ;
F_70 ( V_12 ) ;
}
}
static struct V_13 * F_87 ( struct V_13 * V_14 )
{
struct V_2 * V_12 , * V_191 = V_14 -> V_193 ;
F_12 ( V_191 ) ;
if ( F_88 ( V_191 ) ) {
F_7 ( L_8 , V_191 -> V_63 ) ;
return NULL ;
}
V_12 = F_89 ( F_90 ( V_191 ) , NULL , V_194 ,
V_195 ) ;
if ( ! V_12 )
return NULL ;
F_91 ( V_12 , V_194 ) ;
F_92 ( V_12 , V_191 ) ;
F_93 ( V_191 , V_12 ) ;
F_17 ( V_191 ) ;
return F_6 ( V_12 ) -> V_14 ;
}
static int F_94 ( struct V_13 * V_14 , struct V_196 * V_197 )
{
struct V_2 * V_12 = V_14 -> V_193 ;
int V_18 ;
F_12 ( V_12 ) ;
if ( F_6 ( V_12 ) -> V_174 ) {
V_18 = - V_198 ;
goto V_29;
}
V_18 = F_67 ( V_12 , V_197 ) ;
if ( V_18 < 0 && V_14 -> V_43 == V_58 ) {
F_6 ( V_12 ) -> V_174 = V_197 ;
F_69 ( V_14 , 1 ) ;
V_18 = 0 ;
}
V_29:
F_17 ( V_12 ) ;
return V_18 ;
}
static void F_95 ( struct V_13 * V_14 )
{
struct V_2 * V_12 = V_14 -> V_193 ;
F_70 ( V_12 ) ;
}
static void F_96 ( struct V_13 * V_14 , int V_18 )
{
struct V_2 * V_12 = V_14 -> V_193 ;
struct V_2 * V_191 ;
F_12 ( V_12 ) ;
V_191 = F_44 ( V_12 ) -> V_191 ;
F_74 ( V_12 , V_177 ) ;
switch ( V_14 -> V_45 ) {
case V_27 :
case V_46 :
case V_188 :
break;
case V_64 :
F_85 ( V_12 ) ;
V_12 -> V_26 = V_188 ;
V_14 -> V_45 = V_188 ;
break;
default:
V_12 -> V_26 = V_188 ;
V_14 -> V_45 = V_188 ;
V_12 -> V_189 = V_18 ;
if ( V_191 ) {
F_97 ( V_12 ) ;
V_191 -> V_199 ( V_191 , 0 ) ;
} else {
V_12 -> V_150 ( V_12 ) ;
}
break;
}
F_17 ( V_12 ) ;
}
static void F_98 ( struct V_13 * V_14 , int V_45 ,
int V_18 )
{
struct V_2 * V_12 = V_14 -> V_193 ;
V_12 -> V_26 = V_45 ;
if ( V_18 )
V_12 -> V_189 = V_18 ;
}
static struct V_196 * F_99 ( struct V_13 * V_14 ,
unsigned long V_17 , int V_200 )
{
struct V_2 * V_12 = V_14 -> V_193 ;
struct V_196 * V_197 ;
int V_18 ;
F_61 ( V_14 ) ;
V_197 = F_100 ( V_12 , V_17 , V_200 , & V_18 ) ;
F_59 ( V_14 ) ;
if ( ! V_197 )
return F_101 ( V_18 ) ;
F_102 ( V_197 ) -> V_14 = V_14 ;
return V_197 ;
}
static void F_103 ( struct V_13 * V_14 )
{
struct V_2 * V_12 = V_14 -> V_193 ;
struct V_2 * V_191 ;
F_12 ( V_12 ) ;
V_191 = F_44 ( V_12 ) -> V_191 ;
F_7 ( L_9 , V_12 , V_191 ) ;
V_12 -> V_26 = V_51 ;
V_12 -> V_150 ( V_12 ) ;
if ( V_191 )
V_191 -> V_199 ( V_191 , 0 ) ;
F_17 ( V_12 ) ;
}
static void F_104 ( struct V_13 * V_14 )
{
struct V_2 * V_191 , * V_12 = V_14 -> V_193 ;
F_12 ( V_12 ) ;
V_191 = F_44 ( V_12 ) -> V_191 ;
if ( V_191 )
V_191 -> V_199 ( V_191 , 0 ) ;
F_17 ( V_12 ) ;
}
static void F_105 ( struct V_13 * V_14 )
{
struct V_2 * V_12 = V_14 -> V_193 ;
F_49 ( V_149 , & F_44 ( V_12 ) -> V_47 ) ;
V_12 -> V_150 ( V_12 ) ;
}
static void F_106 ( struct V_13 * V_14 )
{
struct V_2 * V_12 = V_14 -> V_193 ;
F_12 ( V_12 ) ;
V_12 -> V_184 = V_185 ;
F_17 ( V_12 ) ;
}
static long F_107 ( struct V_13 * V_14 )
{
struct V_2 * V_12 = V_14 -> V_193 ;
return V_12 -> V_201 ;
}
static void F_108 ( struct V_13 * V_14 )
{
struct V_2 * V_12 = V_14 -> V_193 ;
F_50 ( V_149 , & F_44 ( V_12 ) -> V_47 ) ;
V_12 -> V_150 ( V_12 ) ;
}
static void F_109 ( struct V_2 * V_12 )
{
F_7 ( L_1 , V_12 ) ;
if ( F_6 ( V_12 ) -> V_14 )
F_73 ( F_6 ( V_12 ) -> V_14 ) ;
if ( F_6 ( V_12 ) -> V_174 ) {
F_110 ( F_6 ( V_12 ) -> V_174 ) ;
F_6 ( V_12 ) -> V_174 = NULL ;
}
F_111 ( & V_12 -> V_202 ) ;
F_111 ( & V_12 -> V_203 ) ;
}
static void F_112 ( struct V_196 * V_197 , void * V_204 ,
int * V_205 )
{
F_113 ( struct V_15 * , V_16 , V_204 ) ;
memset ( V_16 , 0 , sizeof( struct V_15 ) ) ;
V_16 -> V_206 = V_20 ;
V_16 -> V_22 = F_102 ( V_197 ) -> V_5 ;
F_16 ( & V_16 -> V_31 , & F_102 ( V_197 ) -> V_207 ) ;
* V_205 = sizeof( struct V_15 ) ;
}
static void F_92 ( struct V_2 * V_12 , struct V_2 * V_191 )
{
struct V_13 * V_14 = F_6 ( V_12 ) -> V_14 ;
F_7 ( L_1 , V_12 ) ;
if ( V_191 ) {
struct V_13 * V_208 = F_6 ( V_191 ) -> V_14 ;
V_12 -> V_54 = V_191 -> V_54 ;
F_44 ( V_12 ) -> V_47 = F_44 ( V_191 ) -> V_47 ;
V_14 -> V_32 = V_208 -> V_32 ;
V_14 -> V_90 = V_208 -> V_90 ;
V_14 -> V_91 = V_208 -> V_91 ;
V_14 -> V_145 = V_208 -> V_145 ;
V_14 -> V_43 = V_208 -> V_43 ;
V_14 -> V_93 = V_208 -> V_93 ;
V_14 -> V_94 = V_208 -> V_94 ;
V_14 -> V_96 = V_208 -> V_96 ;
V_14 -> V_209 = V_208 -> V_209 ;
V_14 -> V_35 = V_208 -> V_35 ;
V_14 -> V_47 = V_208 -> V_47 ;
V_14 -> V_210 = V_208 -> V_210 ;
V_14 -> V_211 = V_208 -> V_211 ;
F_114 ( V_191 , V_12 ) ;
} else {
switch ( V_12 -> V_54 ) {
case V_132 :
V_14 -> V_32 = V_40 ;
break;
case V_212 :
V_14 -> V_32 = V_33 ;
F_44 ( V_12 ) -> V_213 = F_112 ;
break;
case V_55 :
case V_56 :
V_14 -> V_32 = V_37 ;
break;
}
V_14 -> V_90 = V_214 ;
V_14 -> V_91 = 0 ;
if ( ! V_60 && V_12 -> V_54 == V_56 ) {
V_14 -> V_43 = V_58 ;
F_50 ( V_144 , & V_14 -> V_145 ) ;
} else {
V_14 -> V_43 = V_57 ;
}
F_115 ( V_14 ) ;
}
V_14 -> V_92 = V_215 ;
V_14 -> V_193 = V_12 ;
V_14 -> V_3 = & V_216 ;
}
static struct V_2 * F_89 ( struct V_217 * V_217 , struct V_1 * V_2 ,
int V_218 , T_6 V_219 )
{
struct V_2 * V_12 ;
struct V_13 * V_14 ;
V_12 = F_116 ( V_217 , V_220 , V_219 , & V_221 ) ;
if ( ! V_12 )
return NULL ;
F_117 ( V_2 , V_12 ) ;
F_118 ( & F_44 ( V_12 ) -> V_222 ) ;
V_12 -> V_223 = F_109 ;
V_12 -> V_201 = V_224 ;
F_119 ( V_12 , V_177 ) ;
V_12 -> V_225 = V_218 ;
V_12 -> V_26 = V_27 ;
V_14 = F_120 () ;
if ( ! V_14 ) {
F_121 ( V_12 ) ;
return NULL ;
}
F_122 ( V_14 ) ;
F_6 ( V_12 ) -> V_14 = V_14 ;
return V_12 ;
}
static int F_123 ( struct V_217 * V_217 , struct V_1 * V_2 , int V_226 ,
int V_227 )
{
struct V_2 * V_12 ;
F_7 ( L_10 , V_2 ) ;
V_2 -> V_45 = V_228 ;
if ( V_2 -> type != V_55 && V_2 -> type != V_56 &&
V_2 -> type != V_212 && V_2 -> type != V_132 )
return - V_229 ;
if ( V_2 -> type == V_132 && ! V_227 && ! F_3 ( V_230 ) )
return - V_161 ;
V_2 -> V_3 = & V_4 ;
V_12 = F_89 ( V_217 , V_2 , V_226 , V_195 ) ;
if ( ! V_12 )
return - V_198 ;
F_92 ( V_12 , NULL ) ;
F_124 ( & V_190 , V_12 ) ;
return 0 ;
}
int T_7 F_125 ( void )
{
int V_18 ;
V_18 = F_126 ( & V_221 , 0 ) ;
if ( V_18 < 0 )
return V_18 ;
V_18 = F_127 ( V_194 , & V_231 ) ;
if ( V_18 < 0 ) {
F_128 ( L_11 ) ;
goto error;
}
V_18 = F_129 ( & V_232 , L_12 , & V_190 ,
NULL ) ;
if ( V_18 < 0 ) {
F_128 ( L_13 ) ;
F_130 ( V_194 ) ;
goto error;
}
F_131 ( L_14 ) ;
return 0 ;
error:
F_132 ( & V_221 ) ;
return V_18 ;
}
void F_133 ( void )
{
F_134 ( & V_232 , L_12 ) ;
F_130 ( V_194 ) ;
F_132 ( & V_221 ) ;
}
