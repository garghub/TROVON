static void F_1 ( unsigned long V_1 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
int V_4 ;
F_2 ( L_1 , V_3 , V_3 -> V_5 ) ;
F_3 ( V_3 ) ;
if ( F_4 ( V_3 ) ) {
F_5 ( V_3 , V_6 / 5 ) ;
F_6 ( V_3 ) ;
F_7 ( V_3 ) ;
return;
}
if ( V_3 -> V_5 == V_7 || V_3 -> V_5 == V_8 )
V_4 = V_9 ;
else if ( V_3 -> V_5 == V_10 &&
F_8 ( V_3 ) -> V_11 -> V_12 != V_13 )
V_4 = V_9 ;
else
V_4 = V_14 ;
F_9 ( V_3 , V_4 ) ;
F_6 ( V_3 ) ;
F_10 ( V_3 ) ;
F_7 ( V_3 ) ;
}
void F_5 ( struct V_2 * V_3 , long V_15 )
{
F_2 ( L_2 , V_3 , V_3 -> V_5 , V_15 ) ;
F_11 ( V_3 , & V_3 -> V_16 , V_17 + V_15 ) ;
}
void F_12 ( struct V_2 * V_3 )
{
F_2 ( L_1 , V_3 , V_3 -> V_5 ) ;
F_13 ( V_3 , & V_3 -> V_16 ) ;
}
static int F_14 ( struct V_18 * V_2 , struct V_19 * V_20 , int V_21 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_22 * V_11 = F_8 ( V_3 ) -> V_11 ;
struct V_23 V_24 ;
int V_25 , V_26 = 0 ;
F_2 ( L_3 , V_3 ) ;
if ( ! V_20 || V_20 -> V_27 != V_28 )
return - V_29 ;
memset ( & V_24 , 0 , sizeof( V_24 ) ) ;
V_25 = F_15 (unsigned int, sizeof(la), alen) ;
memcpy ( & V_24 , V_20 , V_25 ) ;
if ( V_24 . V_30 && V_24 . V_31 )
return - V_29 ;
F_16 ( V_3 ) ;
if ( V_3 -> V_5 != V_32 ) {
V_26 = - V_33 ;
goto V_34;
}
if ( V_24 . V_31 ) {
T_1 V_35 = F_17 ( V_24 . V_31 ) ;
if ( ( V_35 & 0x0101 ) != 0x0001 ) {
V_26 = - V_29 ;
goto V_34;
}
if ( V_35 < 0x1001 && ! F_18 ( V_36 ) ) {
V_26 = - V_37 ;
goto V_34;
}
}
if ( V_24 . V_30 )
V_26 = F_19 ( V_11 , V_24 . V_30 ) ;
else
V_26 = F_20 ( V_11 , & V_24 . V_38 , V_24 . V_31 ) ;
if ( V_26 < 0 )
goto V_34;
if ( F_17 ( V_24 . V_31 ) == 0x0001 ||
F_17 ( V_24 . V_31 ) == 0x0003 )
V_11 -> V_12 = V_13 ;
F_21 ( & F_22 ( V_3 ) -> V_39 , & V_24 . V_38 ) ;
V_3 -> V_5 = V_40 ;
V_34:
F_23 ( V_3 ) ;
return V_26 ;
}
static int F_24 ( struct V_18 * V_2 , struct V_19 * V_20 , int V_21 , int V_41 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_22 * V_11 = F_8 ( V_3 ) -> V_11 ;
struct V_23 V_24 ;
int V_25 , V_26 = 0 ;
F_2 ( L_3 , V_3 ) ;
if ( ! V_20 || V_21 < sizeof( V_20 -> V_27 ) ||
V_20 -> V_27 != V_28 )
return - V_29 ;
memset ( & V_24 , 0 , sizeof( V_24 ) ) ;
V_25 = F_15 (unsigned int, sizeof(la), alen) ;
memcpy ( & V_24 , V_20 , V_25 ) ;
if ( V_24 . V_30 && V_24 . V_31 )
return - V_29 ;
F_16 ( V_3 ) ;
if ( ( V_3 -> V_42 == V_43 || V_3 -> V_42 == V_44 )
&& ! ( V_24 . V_31 || V_24 . V_30 ) ) {
V_26 = - V_29 ;
goto V_34;
}
switch ( V_11 -> V_45 ) {
case V_46 :
break;
case V_47 :
case V_48 :
if ( ! V_49 )
break;
default:
V_26 = - V_50 ;
goto V_34;
}
switch ( V_3 -> V_5 ) {
case V_10 :
case V_51 :
case V_8 :
goto V_52;
case V_7 :
V_26 = - V_53 ;
goto V_34;
case V_32 :
case V_40 :
break;
default:
V_26 = - V_33 ;
goto V_34;
}
if ( ( F_17 ( V_24 . V_31 ) & 0x0101 ) != 0x0001 &&
V_3 -> V_42 != V_54 && ! V_24 . V_30 ) {
V_26 = - V_29 ;
goto V_34;
}
F_21 ( & F_22 ( V_3 ) -> V_55 , & V_24 . V_38 ) ;
V_11 -> V_35 = V_24 . V_31 ;
V_11 -> V_56 = V_24 . V_30 ;
V_26 = F_25 ( F_8 ( V_3 ) -> V_11 ) ;
if ( V_26 )
goto V_34;
V_52:
V_26 = F_26 ( V_3 , V_7 ,
F_27 ( V_3 , V_41 & V_57 ) ) ;
V_34:
F_23 ( V_3 ) ;
return V_26 ;
}
static int F_28 ( struct V_18 * V_2 , int V_58 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_22 * V_11 = F_8 ( V_3 ) -> V_11 ;
int V_26 = 0 ;
F_2 ( L_4 , V_3 , V_58 ) ;
F_16 ( V_3 ) ;
if ( ( V_2 -> type != V_43 && V_2 -> type != V_44 )
|| V_3 -> V_5 != V_40 ) {
V_26 = - V_33 ;
goto V_34;
}
switch ( V_11 -> V_45 ) {
case V_46 :
break;
case V_47 :
case V_48 :
if ( ! V_49 )
break;
default:
V_26 = - V_50 ;
goto V_34;
}
V_3 -> V_59 = V_58 ;
V_3 -> V_60 = 0 ;
V_3 -> V_5 = V_61 ;
V_34:
F_23 ( V_3 ) ;
return V_26 ;
}
static int F_29 ( struct V_18 * V_2 , struct V_18 * V_62 , int V_41 )
{
F_30 ( V_52 , V_63 ) ;
struct V_2 * V_3 = V_2 -> V_3 , * V_64 ;
long V_65 ;
int V_26 = 0 ;
F_31 ( V_3 , V_66 ) ;
if ( V_3 -> V_5 != V_61 ) {
V_26 = - V_33 ;
goto V_34;
}
V_65 = F_32 ( V_3 , V_41 & V_57 ) ;
F_2 ( L_5 , V_3 , V_65 ) ;
F_33 ( F_34 ( V_3 ) , & V_52 ) ;
while ( ! ( V_64 = F_35 ( V_3 , V_62 ) ) ) {
F_36 ( V_67 ) ;
if ( ! V_65 ) {
V_26 = - V_68 ;
break;
}
F_23 ( V_3 ) ;
V_65 = F_37 ( V_65 ) ;
F_31 ( V_3 , V_66 ) ;
if ( V_3 -> V_5 != V_61 ) {
V_26 = - V_33 ;
break;
}
if ( F_38 ( V_63 ) ) {
V_26 = F_39 ( V_65 ) ;
break;
}
}
F_36 ( V_69 ) ;
F_40 ( F_34 ( V_3 ) , & V_52 ) ;
if ( V_26 )
goto V_34;
V_62 -> V_70 = V_71 ;
F_2 ( L_6 , V_64 ) ;
V_34:
F_23 ( V_3 ) ;
return V_26 ;
}
static int F_41 ( struct V_18 * V_2 , struct V_19 * V_20 , int * V_25 , int V_72 )
{
struct V_23 * V_24 = (struct V_23 * ) V_20 ;
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_22 * V_11 = F_8 ( V_3 ) -> V_11 ;
F_2 ( L_7 , V_2 , V_3 ) ;
V_20 -> V_27 = V_28 ;
* V_25 = sizeof( struct V_23 ) ;
if ( V_72 ) {
V_24 -> V_31 = V_11 -> V_35 ;
F_21 ( & V_24 -> V_38 , & F_22 ( V_3 ) -> V_55 ) ;
V_24 -> V_30 = F_42 ( V_11 -> V_56 ) ;
} else {
V_24 -> V_31 = V_11 -> V_73 ;
F_21 ( & V_24 -> V_38 , & F_22 ( V_3 ) -> V_39 ) ;
V_24 -> V_30 = F_42 ( V_11 -> V_74 ) ;
}
return 0 ;
}
static int F_43 ( struct V_18 * V_2 , int V_75 , char T_2 * V_76 , int T_2 * V_77 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_22 * V_11 = F_8 ( V_3 ) -> V_11 ;
struct V_78 V_79 ;
struct V_80 V_81 ;
int V_25 , V_26 = 0 ;
T_3 V_82 ;
F_2 ( L_3 , V_3 ) ;
if ( F_44 ( V_25 , V_77 ) )
return - V_83 ;
F_16 ( V_3 ) ;
switch ( V_75 ) {
case V_84 :
memset ( & V_79 , 0 , sizeof( V_79 ) ) ;
V_79 . V_85 = V_11 -> V_85 ;
V_79 . V_86 = V_11 -> V_86 ;
V_79 . V_87 = V_11 -> V_87 ;
V_79 . V_45 = V_11 -> V_45 ;
V_79 . V_88 = V_11 -> V_88 ;
V_79 . V_89 = V_11 -> V_89 ;
V_79 . V_90 = ( T_1 ) V_11 -> V_91 ;
V_25 = F_15 (unsigned int, len, sizeof(opts)) ;
if ( F_45 ( V_76 , ( char * ) & V_79 , V_25 ) )
V_26 = - V_83 ;
break;
case V_92 :
switch ( V_11 -> V_12 ) {
case V_93 :
V_82 = V_94 ;
break;
case V_95 :
V_82 = V_94 | V_96 ;
break;
case V_97 :
V_82 = V_94 | V_96 |
V_98 ;
break;
default:
V_82 = 0 ;
break;
}
if ( V_11 -> V_99 )
V_82 |= V_100 ;
if ( V_11 -> V_101 )
V_82 |= V_102 ;
if ( F_46 ( V_82 , ( T_3 T_2 * ) V_76 ) )
V_26 = - V_83 ;
break;
case V_103 :
if ( V_3 -> V_5 != V_7 &&
! ( V_3 -> V_5 == V_51 &&
F_22 ( V_3 ) -> V_104 ) ) {
V_26 = - V_105 ;
break;
}
memset ( & V_81 , 0 , sizeof( V_81 ) ) ;
V_81 . V_106 = V_11 -> V_107 -> V_108 -> V_109 ;
memcpy ( V_81 . V_110 , V_11 -> V_107 -> V_108 -> V_110 , 3 ) ;
V_25 = F_15 (unsigned int, len, sizeof(cinfo)) ;
if ( F_45 ( V_76 , ( char * ) & V_81 , V_25 ) )
V_26 = - V_83 ;
break;
default:
V_26 = - V_111 ;
break;
}
F_23 ( V_3 ) ;
return V_26 ;
}
static int F_47 ( struct V_18 * V_2 , int V_112 , int V_75 , char T_2 * V_76 , int T_2 * V_77 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_22 * V_11 = F_8 ( V_3 ) -> V_11 ;
struct V_113 V_114 ;
int V_25 , V_26 = 0 ;
F_2 ( L_3 , V_3 ) ;
if ( V_112 == V_115 )
return F_43 ( V_2 , V_75 , V_76 , V_77 ) ;
if ( V_112 != V_116 )
return - V_111 ;
if ( F_44 ( V_25 , V_77 ) )
return - V_83 ;
F_16 ( V_3 ) ;
switch ( V_75 ) {
case V_117 :
if ( V_3 -> V_42 != V_43 && V_3 -> V_42 != V_44
&& V_3 -> V_42 != V_54 ) {
V_26 = - V_29 ;
break;
}
V_114 . V_112 = V_11 -> V_12 ;
V_25 = F_15 (unsigned int, len, sizeof(sec)) ;
if ( F_45 ( V_76 , ( char * ) & V_114 , V_25 ) )
V_26 = - V_83 ;
break;
case V_118 :
if ( V_3 -> V_5 != V_40 && V_3 -> V_5 != V_61 ) {
V_26 = - V_29 ;
break;
}
if ( F_46 ( F_22 ( V_3 ) -> V_104 , ( T_3 T_2 * ) V_76 ) )
V_26 = - V_83 ;
break;
case V_119 :
if ( F_46 ( V_11 -> V_120 , ( T_3 T_2 * ) V_76 ) )
V_26 = - V_83 ;
break;
default:
V_26 = - V_111 ;
break;
}
F_23 ( V_3 ) ;
return V_26 ;
}
static int F_48 ( struct V_18 * V_2 , int V_75 , char T_2 * V_76 , unsigned int V_77 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_22 * V_11 = F_8 ( V_3 ) -> V_11 ;
struct V_78 V_79 ;
int V_25 , V_26 = 0 ;
T_3 V_82 ;
F_2 ( L_3 , V_3 ) ;
F_16 ( V_3 ) ;
switch ( V_75 ) {
case V_84 :
if ( V_3 -> V_5 == V_7 ) {
V_26 = - V_29 ;
break;
}
V_79 . V_85 = V_11 -> V_85 ;
V_79 . V_86 = V_11 -> V_86 ;
V_79 . V_87 = V_11 -> V_87 ;
V_79 . V_45 = V_11 -> V_45 ;
V_79 . V_88 = V_11 -> V_88 ;
V_79 . V_89 = V_11 -> V_89 ;
V_79 . V_90 = ( T_1 ) V_11 -> V_91 ;
V_25 = F_15 (unsigned int, sizeof(opts), optlen) ;
if ( F_49 ( ( char * ) & V_79 , V_76 , V_25 ) ) {
V_26 = - V_83 ;
break;
}
if ( V_79 . V_90 > V_121 ) {
V_26 = - V_29 ;
break;
}
V_11 -> V_45 = V_79 . V_45 ;
switch ( V_11 -> V_45 ) {
case V_46 :
V_11 -> V_122 &= ~ V_123 ;
break;
case V_47 :
case V_48 :
if ( ! V_49 )
break;
default:
V_26 = - V_29 ;
break;
}
V_11 -> V_85 = V_79 . V_85 ;
V_11 -> V_86 = V_79 . V_86 ;
V_11 -> V_88 = V_79 . V_88 ;
V_11 -> V_89 = V_79 . V_89 ;
V_11 -> V_91 = ( V_124 ) V_79 . V_90 ;
break;
case V_92 :
if ( F_44 ( V_82 , ( T_3 T_2 * ) V_76 ) ) {
V_26 = - V_83 ;
break;
}
if ( V_82 & V_94 )
V_11 -> V_12 = V_93 ;
if ( V_82 & V_96 )
V_11 -> V_12 = V_95 ;
if ( V_82 & V_98 )
V_11 -> V_12 = V_97 ;
V_11 -> V_99 = ( V_82 & V_100 ) ;
V_11 -> V_101 = ( V_82 & V_102 ) ;
break;
default:
V_26 = - V_111 ;
break;
}
F_23 ( V_3 ) ;
return V_26 ;
}
static int F_50 ( struct V_18 * V_2 , int V_112 , int V_75 , char T_2 * V_76 , unsigned int V_77 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_22 * V_11 = F_8 ( V_3 ) -> V_11 ;
struct V_113 V_114 ;
int V_25 , V_26 = 0 ;
T_3 V_82 ;
F_2 ( L_3 , V_3 ) ;
if ( V_112 == V_115 )
return F_48 ( V_2 , V_75 , V_76 , V_77 ) ;
if ( V_112 != V_116 )
return - V_111 ;
F_16 ( V_3 ) ;
switch ( V_75 ) {
case V_117 :
if ( V_3 -> V_42 != V_43 && V_3 -> V_42 != V_44
&& V_3 -> V_42 != V_54 ) {
V_26 = - V_29 ;
break;
}
V_114 . V_112 = V_93 ;
V_25 = F_15 (unsigned int, sizeof(sec), optlen) ;
if ( F_49 ( ( char * ) & V_114 , V_76 , V_25 ) ) {
V_26 = - V_83 ;
break;
}
if ( V_114 . V_112 < V_93 ||
V_114 . V_112 > V_97 ) {
V_26 = - V_29 ;
break;
}
V_11 -> V_12 = V_114 . V_112 ;
break;
case V_118 :
if ( V_3 -> V_5 != V_40 && V_3 -> V_5 != V_61 ) {
V_26 = - V_29 ;
break;
}
if ( F_44 ( V_82 , ( T_3 T_2 * ) V_76 ) ) {
V_26 = - V_83 ;
break;
}
F_22 ( V_3 ) -> V_104 = V_82 ;
break;
case V_119 :
if ( F_44 ( V_82 , ( T_3 T_2 * ) V_76 ) ) {
V_26 = - V_83 ;
break;
}
if ( V_82 > V_125 ) {
V_26 = - V_29 ;
break;
}
if ( V_82 == V_126 ) {
struct V_127 * V_107 = V_11 -> V_107 ;
if ( ! V_107 || ! F_51 ( V_107 -> V_108 -> V_128 ) ) {
V_26 = - V_29 ;
break;
}
}
V_11 -> V_120 = V_82 ;
break;
default:
V_26 = - V_111 ;
break;
}
F_23 ( V_3 ) ;
return V_26 ;
}
static int F_52 ( struct V_129 * V_130 , struct V_18 * V_2 , struct V_131 * V_132 , T_4 V_25 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_22 * V_11 = F_8 ( V_3 ) -> V_11 ;
struct V_133 * V_134 ;
T_5 V_135 ;
int V_26 ;
F_2 ( L_7 , V_2 , V_3 ) ;
V_26 = F_53 ( V_3 ) ;
if ( V_26 )
return V_26 ;
if ( V_132 -> V_136 & V_137 )
return - V_138 ;
F_16 ( V_3 ) ;
if ( V_3 -> V_5 != V_7 ) {
V_26 = - V_105 ;
goto V_34;
}
if ( V_3 -> V_42 == V_139 ) {
V_134 = F_54 ( V_11 , V_132 , V_25 ) ;
if ( F_55 ( V_134 ) ) {
V_26 = F_56 ( V_134 ) ;
} else {
F_57 ( V_11 , V_134 ) ;
V_26 = V_25 ;
}
goto V_34;
}
switch ( V_11 -> V_45 ) {
case V_46 :
if ( V_25 > V_11 -> V_86 ) {
V_26 = - V_140 ;
goto V_34;
}
V_134 = F_58 ( V_11 , V_132 , V_25 ) ;
if ( F_55 ( V_134 ) ) {
V_26 = F_56 ( V_134 ) ;
goto V_34;
}
F_57 ( V_11 , V_134 ) ;
V_26 = V_25 ;
break;
case V_47 :
case V_48 :
if ( V_25 <= V_11 -> V_141 ) {
V_135 = V_142 ;
V_134 = F_59 ( V_11 , V_132 , V_25 , V_135 ,
0 ) ;
if ( F_55 ( V_134 ) ) {
V_26 = F_56 ( V_134 ) ;
goto V_34;
}
F_60 ( & V_11 -> V_143 , V_134 ) ;
if ( V_11 -> V_144 == NULL )
V_11 -> V_144 = V_134 ;
} else {
V_26 = F_61 ( V_11 , V_132 , V_25 ) ;
if ( V_26 < 0 )
goto V_34;
}
if ( V_11 -> V_45 == V_48 ) {
F_62 ( V_11 ) ;
V_26 = V_25 ;
break;
}
if ( ( V_11 -> V_145 & V_146 ) &&
( V_11 -> V_145 & V_147 ) ) {
V_26 = V_25 ;
break;
}
V_26 = F_63 ( V_11 ) ;
if ( V_26 >= 0 )
V_26 = V_25 ;
break;
default:
F_2 ( L_8 , V_11 -> V_45 ) ;
V_26 = - V_33 ;
}
V_34:
F_23 ( V_3 ) ;
return V_26 ;
}
static int F_64 ( struct V_129 * V_130 , struct V_18 * V_2 , struct V_131 * V_132 , T_4 V_25 , int V_41 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
F_16 ( V_3 ) ;
if ( V_3 -> V_5 == V_51 && F_22 ( V_3 ) -> V_104 ) {
V_3 -> V_5 = V_8 ;
F_65 ( F_8 ( V_3 ) -> V_11 ) ;
F_23 ( V_3 ) ;
return 0 ;
}
F_23 ( V_3 ) ;
if ( V_2 -> type == V_44 )
return F_66 ( V_130 , V_2 , V_132 , V_25 , V_41 ) ;
return F_67 ( V_130 , V_2 , V_132 , V_25 , V_41 ) ;
}
void F_10 ( struct V_2 * V_3 )
{
if ( ! F_68 ( V_3 , V_148 ) || V_3 -> V_149 )
return;
F_2 ( L_9 , V_3 , V_3 -> V_5 ) ;
F_69 ( F_8 ( V_3 ) -> V_11 ) ;
F_70 ( V_3 , V_150 ) ;
F_7 ( V_3 ) ;
}
static void F_71 ( struct V_2 * V_3 )
{
F_12 ( V_3 ) ;
F_16 ( V_3 ) ;
F_9 ( V_3 , V_151 ) ;
F_23 ( V_3 ) ;
F_10 ( V_3 ) ;
}
static void F_72 ( struct V_2 * V_152 )
{
struct V_2 * V_3 ;
F_2 ( L_10 , V_152 ) ;
while ( ( V_3 = F_35 ( V_152 , NULL ) ) )
F_71 ( V_3 ) ;
V_152 -> V_5 = V_153 ;
F_70 ( V_152 , V_148 ) ;
}
void F_9 ( struct V_2 * V_3 , int V_4 )
{
struct V_22 * V_11 = F_8 ( V_3 ) -> V_11 ;
struct V_127 * V_107 = V_11 -> V_107 ;
F_2 ( L_11 , V_3 , V_3 -> V_5 , V_3 -> V_149 ) ;
switch ( V_3 -> V_5 ) {
case V_61 :
F_72 ( V_3 ) ;
break;
case V_7 :
case V_8 :
if ( ( V_3 -> V_42 == V_43 ||
V_3 -> V_42 == V_44 ) &&
V_107 -> V_108 -> type == V_154 ) {
F_5 ( V_3 , V_3 -> V_155 ) ;
F_73 ( V_107 , V_11 , V_4 ) ;
} else
F_74 ( V_11 , V_4 ) ;
break;
case V_51 :
if ( ( V_3 -> V_42 == V_43 ||
V_3 -> V_42 == V_44 ) &&
V_107 -> V_108 -> type == V_154 ) {
struct V_156 V_157 ;
T_1 V_158 ;
if ( F_22 ( V_3 ) -> V_104 )
V_158 = V_159 ;
else
V_158 = V_160 ;
V_157 . V_74 = F_42 ( V_11 -> V_56 ) ;
V_157 . V_56 = F_42 ( V_11 -> V_74 ) ;
V_157 . V_158 = F_42 ( V_158 ) ;
V_157 . V_161 = F_42 ( V_162 ) ;
F_75 ( V_107 , V_11 -> V_163 , V_164 ,
sizeof( V_157 ) , & V_157 ) ;
}
F_74 ( V_11 , V_4 ) ;
break;
case V_10 :
case V_165 :
F_74 ( V_11 , V_4 ) ;
break;
default:
F_70 ( V_3 , V_148 ) ;
break;
}
}
static int F_76 ( struct V_18 * V_2 , int V_166 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_22 * V_11 = F_8 ( V_3 ) -> V_11 ;
int V_26 = 0 ;
F_2 ( L_7 , V_2 , V_3 ) ;
if ( ! V_3 )
return 0 ;
F_16 ( V_3 ) ;
if ( ! V_3 -> V_167 ) {
if ( V_11 -> V_45 == V_47 )
V_26 = F_77 ( V_3 ) ;
V_3 -> V_167 = V_168 ;
F_12 ( V_3 ) ;
F_9 ( V_3 , 0 ) ;
if ( F_68 ( V_3 , V_169 ) && V_3 -> V_170 )
V_26 = F_26 ( V_3 , V_153 ,
V_3 -> V_170 ) ;
}
if ( ! V_26 && V_3 -> V_171 )
V_26 = - V_3 -> V_171 ;
F_23 ( V_3 ) ;
return V_26 ;
}
static int F_78 ( struct V_18 * V_2 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
int V_26 ;
F_2 ( L_7 , V_2 , V_3 ) ;
if ( ! V_3 )
return 0 ;
V_26 = F_76 ( V_2 , 2 ) ;
F_79 ( V_3 ) ;
F_10 ( V_3 ) ;
return V_26 ;
}
static void F_80 ( struct V_2 * V_3 )
{
F_2 ( L_3 , V_3 ) ;
F_81 ( & V_3 -> V_172 ) ;
F_81 ( & V_3 -> V_173 ) ;
}
void F_82 ( struct V_2 * V_3 , struct V_2 * V_152 )
{
struct V_174 * V_175 = F_8 ( V_3 ) ;
struct V_22 * V_11 = V_175 -> V_11 ;
F_2 ( L_3 , V_3 ) ;
if ( V_152 ) {
struct V_22 * V_176 = F_8 ( V_152 ) -> V_11 ;
V_3 -> V_42 = V_152 -> V_42 ;
F_22 ( V_3 ) -> V_104 = F_22 ( V_152 ) -> V_104 ;
V_11 -> V_85 = V_176 -> V_85 ;
V_11 -> V_86 = V_176 -> V_86 ;
V_11 -> V_122 = V_176 -> V_122 ;
V_11 -> V_45 = V_176 -> V_45 ;
V_11 -> V_88 = V_176 -> V_88 ;
V_11 -> V_89 = V_176 -> V_89 ;
V_11 -> V_91 = V_176 -> V_91 ;
V_11 -> V_12 = V_176 -> V_12 ;
V_11 -> V_99 = V_176 -> V_99 ;
V_11 -> V_101 = V_176 -> V_101 ;
V_11 -> V_120 = V_176 -> V_120 ;
} else {
V_11 -> V_85 = V_177 ;
V_11 -> V_86 = 0 ;
if ( ! V_49 && V_3 -> V_42 == V_44 ) {
V_11 -> V_45 = V_47 ;
V_11 -> V_122 |= V_123 ;
} else {
V_11 -> V_45 = V_46 ;
}
V_11 -> V_89 = V_178 ;
V_11 -> V_88 = V_179 ;
V_11 -> V_91 = V_121 ;
V_11 -> V_12 = V_93 ;
V_11 -> V_99 = 0 ;
V_11 -> V_101 = 0 ;
V_11 -> V_120 = V_126 ;
}
V_11 -> V_87 = V_180 ;
}
struct V_2 * F_83 ( struct V_181 * V_181 , struct V_18 * V_2 , int V_182 , T_6 V_183 )
{
struct V_2 * V_3 ;
V_3 = F_84 ( V_181 , V_184 , V_183 , & V_185 ) ;
if ( ! V_3 )
return NULL ;
F_85 ( V_2 , V_3 ) ;
F_86 ( & F_22 ( V_3 ) -> V_186 ) ;
V_3 -> V_187 = F_80 ;
V_3 -> V_155 = F_87 ( V_188 ) ;
F_88 ( V_3 , V_148 ) ;
V_3 -> V_189 = V_182 ;
V_3 -> V_5 = V_32 ;
F_89 ( & V_3 -> V_16 , F_1 , ( unsigned long ) V_3 ) ;
return V_3 ;
}
static int F_90 ( struct V_181 * V_181 , struct V_18 * V_2 , int V_190 ,
int V_191 )
{
struct V_2 * V_3 ;
struct V_22 * V_11 ;
F_2 ( L_12 , V_2 ) ;
V_2 -> V_70 = V_192 ;
if ( V_2 -> type != V_43 && V_2 -> type != V_44 &&
V_2 -> type != V_139 && V_2 -> type != V_54 )
return - V_193 ;
if ( V_2 -> type == V_54 && ! V_191 && ! F_18 ( V_194 ) )
return - V_195 ;
V_2 -> V_196 = & V_197 ;
V_3 = F_83 ( V_181 , V_2 , V_190 , V_198 ) ;
if ( ! V_3 )
return - V_199 ;
V_11 = F_91 ( V_3 ) ;
if ( ! V_11 ) {
F_10 ( V_3 ) ;
return - V_199 ;
}
F_8 ( V_3 ) -> V_11 = V_11 ;
F_82 ( V_3 , NULL ) ;
return 0 ;
}
int T_7 F_92 ( void )
{
int V_26 ;
V_26 = F_93 ( & V_185 , 0 ) ;
if ( V_26 < 0 )
return V_26 ;
V_26 = F_94 ( V_200 , & V_201 ) ;
if ( V_26 < 0 )
goto error;
F_95 ( L_13 ) ;
return 0 ;
error:
F_96 ( L_14 ) ;
F_97 ( & V_185 ) ;
return V_26 ;
}
void F_98 ( void )
{
if ( F_99 ( V_200 ) < 0 )
F_96 ( L_15 ) ;
F_97 ( & V_185 ) ;
}
