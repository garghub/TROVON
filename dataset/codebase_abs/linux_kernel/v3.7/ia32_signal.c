int F_1 ( T_1 T_2 * V_1 , T_3 * V_2 )
{
int V_3 = 0 ;
bool V_4 = F_2 ( V_5 ) ;
if ( ! F_3 ( V_6 , V_1 , sizeof( T_1 ) ) )
return - V_7 ;
F_4 {
F_5 ( V_2 -> V_8 , & V_1 -> V_8 ) ;
F_5 ( V_2 -> V_9 , & V_1 -> V_9 ) ;
F_5 ( ( short ) V_2 -> V_10 , & V_1 -> V_10 ) ;
if ( V_2 -> V_10 < 0 ) {
F_5 ( V_2 -> V_11 , & V_1 -> V_11 ) ;
F_5 ( V_2 -> V_12 , & V_1 -> V_12 ) ;
F_5 ( F_6 ( V_2 -> V_13 ) , & V_1 -> V_13 ) ;
} else {
F_5 ( V_2 -> V_14 . V_15 [ 0 ] ,
& V_1 -> V_14 . V_15 [ 0 ] ) ;
switch ( V_2 -> V_10 >> 16 ) {
case V_16 >> 16 :
break;
case V_17 >> 16 :
F_5 ( V_2 -> V_18 , & V_1 -> V_18 ) ;
F_5 ( V_2 -> V_19 , & V_1 -> V_19 ) ;
break;
case V_20 >> 16 :
if ( V_4 ) {
F_5 ( V_2 -> V_21 , & V_1 -> V_21 ) ;
F_5 ( V_2 -> V_22 , & V_1 -> V_22 ) ;
} else {
F_5 ( V_2 -> V_21 , & V_1 -> V_14 . V_23 . V_24 ) ;
F_5 ( V_2 -> V_22 , & V_1 -> V_14 . V_23 . V_25 ) ;
}
F_5 ( V_2 -> V_26 , & V_1 -> V_26 ) ;
default:
case V_27 >> 16 :
F_5 ( V_2 -> V_12 , & V_1 -> V_12 ) ;
break;
case V_28 >> 16 :
F_5 ( V_2 -> V_29 , & V_1 -> V_29 ) ;
break;
case V_30 >> 16 :
F_5 ( V_2 -> V_31 , & V_1 -> V_31 ) ;
F_5 ( F_6 ( V_2 -> V_13 ) ,
& V_1 -> V_13 ) ;
break;
case V_32 >> 16 :
case V_33 >> 16 :
F_5 ( V_2 -> V_12 , & V_1 -> V_12 ) ;
F_5 ( V_2 -> V_34 , & V_1 -> V_34 ) ;
break;
}
}
} F_7 ( V_3 ) ;
return V_3 ;
}
int F_8 ( T_3 * V_1 , T_1 T_2 * V_2 )
{
int V_3 = 0 ;
T_4 V_35 ;
if ( ! F_3 ( V_36 , V_2 , sizeof( T_1 ) ) )
return - V_7 ;
F_9 {
F_10 ( V_1 -> V_8 , & V_2 -> V_8 ) ;
F_10 ( V_1 -> V_9 , & V_2 -> V_9 ) ;
F_10 ( V_1 -> V_10 , & V_2 -> V_10 ) ;
F_10 ( V_1 -> V_11 , & V_2 -> V_11 ) ;
F_10 ( V_1 -> V_12 , & V_2 -> V_12 ) ;
F_10 ( V_35 , & V_2 -> V_13 ) ;
V_1 -> V_13 = F_11 ( V_35 ) ;
} F_12 ( V_3 ) ;
return V_3 ;
}
T_5 long F_13 ( int V_37 , int V_38 , T_6 V_39 )
{
T_7 V_40 ;
F_14 ( & V_40 , V_39 ) ;
return F_15 ( & V_40 ) ;
}
T_5 long F_16 ( const T_8 T_2 * V_41 ,
T_8 T_2 * V_42 ,
struct V_43 * V_44 )
{
T_9 V_45 , V_46 ;
int V_47 , V_3 = 0 ;
T_10 V_48 ;
if ( V_41 ) {
T_4 V_49 ;
memset ( & V_45 , 0 , sizeof( T_9 ) ) ;
if ( ! F_3 ( V_36 , V_41 , sizeof( T_8 ) ) )
return - V_7 ;
F_9 {
F_10 ( V_49 , & V_41 -> V_50 ) ;
F_10 ( V_45 . V_51 , & V_41 -> V_51 ) ;
F_10 ( V_45 . V_52 , & V_41 -> V_52 ) ;
} F_12 ( V_3 ) ;
if ( V_3 )
return - V_7 ;
V_45 . V_50 = F_11 ( V_49 ) ;
}
V_48 = F_17 () ;
F_18 ( V_53 ) ;
V_47 = F_19 ( ( T_9 V_54 T_2 * ) ( V_41 ? & V_45 : NULL ) ,
( T_9 V_54 T_2 * ) & V_46 , V_44 -> V_55 ) ;
F_18 ( V_48 ) ;
if ( V_47 >= 0 && V_42 ) {
if ( ! F_3 ( V_6 , V_42 , sizeof( T_8 ) ) )
return - V_7 ;
F_4 {
F_5 ( F_6 ( V_46 . V_50 ) , & V_42 -> V_50 ) ;
F_5 ( V_46 . V_51 , & V_42 -> V_51 ) ;
F_5 ( V_46 . V_52 , & V_42 -> V_52 ) ;
} F_7 ( V_3 ) ;
if ( V_3 )
V_47 = - V_7 ;
}
return V_47 ;
}
static int F_20 ( struct V_43 * V_44 ,
struct V_56 T_2 * V_57 ,
unsigned int * V_58 )
{
unsigned int V_59 , V_3 = 0 ;
void T_2 * V_60 ;
T_4 V_61 ;
F_21 () -> V_62 . V_63 = V_64 ;
F_9 {
F_22 ( V_65 ) ;
F_22 ( V_66 ) ;
F_22 ( V_67 ) ;
F_22 ( V_68 ) ;
F_23 ( V_69 ) ; F_23 ( V_70 ) ; F_23 ( V_71 ) ; F_23 ( V_55 ) ; F_23 ( V_72 ) ;
F_23 ( V_73 ) ; F_23 ( V_74 ) ; F_23 ( V_75 ) ;
F_24 ( V_76 ) ;
F_24 ( V_77 ) ;
F_10 ( V_59 , & V_57 -> V_78 ) ;
V_44 -> V_78 = ( V_44 -> V_78 & ~ V_79 ) | ( V_59 & V_79 ) ;
V_44 -> V_80 = - 1 ;
F_10 ( V_61 , & V_57 -> V_81 ) ;
V_60 = F_11 ( V_61 ) ;
F_10 ( * V_58 , & V_57 -> V_82 ) ;
} F_12 ( V_3 ) ;
V_3 |= F_25 ( V_60 , 1 ) ;
return V_3 ;
}
T_5 long F_26 ( struct V_43 * V_44 )
{
struct V_83 T_2 * V_84 = (struct V_83 T_2 * ) ( V_44 -> V_55 - 8 ) ;
T_7 V_85 ;
unsigned int V_82 ;
if ( ! F_3 ( V_36 , V_84 , sizeof( * V_84 ) ) )
goto V_86;
if ( F_27 ( V_85 . V_87 [ 0 ] , & V_84 -> V_57 . V_88 )
|| ( V_89 > 1
&& F_28 ( ( ( ( char * ) & V_85 . V_87 ) + 4 ) ,
& V_84 -> V_90 ,
sizeof( V_84 -> V_90 ) ) ) )
goto V_86;
F_29 ( & V_85 ) ;
if ( F_20 ( V_44 , & V_84 -> V_57 , & V_82 ) )
goto V_86;
return V_82 ;
V_86:
F_30 ( V_44 , V_84 , L_1 ) ;
return 0 ;
}
T_5 long F_31 ( struct V_43 * V_44 )
{
struct V_91 T_2 * V_84 ;
T_7 V_85 ;
unsigned int V_82 ;
struct V_43 V_92 ;
V_84 = (struct V_91 T_2 * ) ( V_44 -> V_55 - 4 ) ;
if ( ! F_3 ( V_36 , V_84 , sizeof( * V_84 ) ) )
goto V_86;
if ( F_28 ( & V_85 , & V_84 -> V_93 . V_94 , sizeof( V_85 ) ) )
goto V_86;
F_29 ( & V_85 ) ;
if ( F_20 ( V_44 , & V_84 -> V_93 . V_95 , & V_82 ) )
goto V_86;
V_92 = * V_44 ;
if ( F_16 ( & V_84 -> V_93 . V_96 , NULL , & V_92 ) == - V_7 )
goto V_86;
return V_82 ;
V_86:
F_30 ( V_44 , V_84 , L_2 ) ;
return 0 ;
}
static int F_32 ( struct V_56 T_2 * V_57 ,
void T_2 * V_81 ,
struct V_43 * V_44 , unsigned int V_39 )
{
int V_3 = 0 ;
F_4 {
F_5 ( F_33 ( V_65 ) , ( unsigned int T_2 * ) & V_57 -> V_65 ) ;
F_5 ( F_33 ( V_66 ) , ( unsigned int T_2 * ) & V_57 -> V_66 ) ;
F_5 ( F_33 ( V_67 ) , ( unsigned int T_2 * ) & V_57 -> V_67 ) ;
F_5 ( F_33 ( V_68 ) , ( unsigned int T_2 * ) & V_57 -> V_68 ) ;
F_5 ( V_44 -> V_69 , & V_57 -> V_69 ) ;
F_5 ( V_44 -> V_70 , & V_57 -> V_70 ) ;
F_5 ( V_44 -> V_71 , & V_57 -> V_71 ) ;
F_5 ( V_44 -> V_55 , & V_57 -> V_55 ) ;
F_5 ( V_44 -> V_72 , & V_57 -> V_72 ) ;
F_5 ( V_44 -> V_73 , & V_57 -> V_73 ) ;
F_5 ( V_44 -> V_74 , & V_57 -> V_74 ) ;
F_5 ( V_44 -> V_82 , & V_57 -> V_82 ) ;
F_5 ( V_97 -> V_98 . V_99 , & V_57 -> V_100 ) ;
F_5 ( V_97 -> V_98 . V_101 , & V_57 -> V_3 ) ;
F_5 ( V_44 -> V_75 , & V_57 -> V_75 ) ;
F_5 ( V_44 -> V_76 , ( unsigned int T_2 * ) & V_57 -> V_76 ) ;
F_5 ( V_44 -> V_78 , & V_57 -> V_78 ) ;
F_5 ( V_44 -> V_55 , & V_57 -> V_102 ) ;
F_5 ( V_44 -> V_77 , ( unsigned int T_2 * ) & V_57 -> V_77 ) ;
F_5 ( F_6 ( V_81 ) , & V_57 -> V_81 ) ;
F_5 ( V_39 , & V_57 -> V_88 ) ;
F_5 ( V_97 -> V_98 . V_103 , & V_57 -> V_103 ) ;
} F_7 ( V_3 ) ;
return V_3 ;
}
static void T_2 * F_34 ( struct V_104 * V_105 , struct V_43 * V_44 ,
T_11 V_106 ,
void T_2 * * V_81 )
{
unsigned long V_55 ;
V_55 = V_44 -> V_55 ;
if ( V_105 -> V_107 . V_108 & V_109 ) {
if ( F_35 ( V_55 ) == 0 )
V_55 = V_97 -> V_110 + V_97 -> V_111 ;
}
else if ( ( V_44 -> V_77 & 0xffff ) != V_112 &&
! ( V_105 -> V_107 . V_108 & V_113 ) &&
V_105 -> V_107 . V_114 )
V_55 = ( unsigned long ) V_105 -> V_107 . V_114 ;
if ( F_36 () ) {
unsigned long V_115 , V_116 ;
V_55 = F_37 ( V_55 , 1 , & V_115 , & V_116 ) ;
* V_81 = (struct V_117 T_2 * ) V_55 ;
if ( F_38 ( * V_81 , ( void T_2 * ) V_115 ,
V_116 ) < 0 )
return ( void T_2 * ) - 1L ;
}
V_55 -= V_106 ;
V_55 = ( ( V_55 + 4 ) & - 16ul ) - 4 ;
return ( void T_2 * ) V_55 ;
}
int F_39 ( int V_87 , struct V_104 * V_105 ,
T_12 * V_85 , struct V_43 * V_44 )
{
struct V_83 T_2 * V_84 ;
void T_2 * V_118 ;
int V_3 = 0 ;
void T_2 * V_81 = NULL ;
static const struct {
T_13 V_119 ;
T_4 V_120 ;
T_13 V_121 ;
} V_122 ( ( V_123 ) ) V_124 = {
0xb858 ,
V_125 ,
0x80cd ,
} ;
V_84 = F_34 ( V_105 , V_44 , sizeof( * V_84 ) , & V_81 ) ;
if ( ! F_3 ( V_6 , V_84 , sizeof( * V_84 ) ) )
return - V_7 ;
if ( F_40 ( V_87 , & V_84 -> V_87 ) )
return - V_7 ;
if ( F_32 ( & V_84 -> V_57 , V_81 , V_44 , V_85 -> V_87 [ 0 ] ) )
return - V_7 ;
if ( V_89 > 1 ) {
if ( F_41 ( V_84 -> V_90 , & V_85 -> V_87 [ 1 ] ,
sizeof( V_84 -> V_90 ) ) )
return - V_7 ;
}
if ( V_105 -> V_107 . V_108 & V_113 ) {
V_118 = V_105 -> V_107 . V_114 ;
} else {
if ( V_97 -> V_126 -> V_127 . V_128 )
V_118 = F_42 ( V_97 -> V_126 -> V_127 . V_128 ,
V_129 ) ;
else
V_118 = & V_84 -> V_130 ;
}
F_4 {
F_5 ( F_6 ( V_118 ) , & V_84 -> V_131 ) ;
F_5 ( * ( ( V_132 * ) & V_124 ) , ( V_132 T_2 * ) V_84 -> V_130 ) ;
} F_7 ( V_3 ) ;
if ( V_3 )
return - V_7 ;
V_44 -> V_55 = ( unsigned long ) V_84 ;
V_44 -> V_75 = ( unsigned long ) V_105 -> V_107 . V_133 ;
V_44 -> V_82 = V_87 ;
V_44 -> V_73 = 0 ;
V_44 -> V_74 = 0 ;
F_43 ( V_67 , V_112 ) ;
F_43 ( V_68 , V_112 ) ;
V_44 -> V_76 = V_134 ;
V_44 -> V_77 = V_112 ;
return 0 ;
}
int F_44 ( int V_87 , struct V_104 * V_105 , T_3 * V_135 ,
T_12 * V_85 , struct V_43 * V_44 )
{
struct V_91 T_2 * V_84 ;
void T_2 * V_118 ;
int V_3 = 0 ;
void T_2 * V_81 = NULL ;
static const struct {
T_14 V_136 ;
T_4 V_120 ;
T_13 V_121 ;
T_14 V_137 ;
} V_122 ( ( V_123 ) ) V_124 = {
0xb8 ,
V_138 ,
0x80cd ,
0 ,
} ;
V_84 = F_34 ( V_105 , V_44 , sizeof( * V_84 ) , & V_81 ) ;
if ( ! F_3 ( V_6 , V_84 , sizeof( * V_84 ) ) )
return - V_7 ;
F_4 {
F_5 ( V_87 , & V_84 -> V_87 ) ;
F_5 ( F_6 ( & V_84 -> V_135 ) , & V_84 -> V_139 ) ;
F_5 ( F_6 ( & V_84 -> V_93 ) , & V_84 -> V_140 ) ;
if ( V_141 )
F_5 ( V_142 , & V_84 -> V_93 . V_143 ) ;
else
F_5 ( 0 , & V_84 -> V_93 . V_143 ) ;
F_5 ( 0 , & V_84 -> V_93 . V_144 ) ;
F_5 ( V_97 -> V_110 , & V_84 -> V_93 . V_96 . V_50 ) ;
F_5 ( F_35 ( V_44 -> V_55 ) ,
& V_84 -> V_93 . V_96 . V_51 ) ;
F_5 ( V_97 -> V_111 , & V_84 -> V_93 . V_96 . V_52 ) ;
if ( V_105 -> V_107 . V_108 & V_113 )
V_118 = V_105 -> V_107 . V_114 ;
else
V_118 = F_42 ( V_97 -> V_126 -> V_127 . V_128 ,
V_145 ) ;
F_5 ( F_6 ( V_118 ) , & V_84 -> V_131 ) ;
F_5 ( * ( ( V_132 * ) & V_124 ) , ( V_132 T_2 * ) V_84 -> V_130 ) ;
} F_7 ( V_3 ) ;
V_3 |= F_1 ( & V_84 -> V_135 , V_135 ) ;
V_3 |= F_32 ( & V_84 -> V_93 . V_95 , V_81 ,
V_44 , V_85 -> V_87 [ 0 ] ) ;
V_3 |= F_41 ( & V_84 -> V_93 . V_94 , V_85 , sizeof( * V_85 ) ) ;
if ( V_3 )
return - V_7 ;
V_44 -> V_55 = ( unsigned long ) V_84 ;
V_44 -> V_75 = ( unsigned long ) V_105 -> V_107 . V_133 ;
V_44 -> V_82 = V_87 ;
V_44 -> V_73 = ( unsigned long ) & V_84 -> V_135 ;
V_44 -> V_74 = ( unsigned long ) & V_84 -> V_93 ;
F_43 ( V_67 , V_112 ) ;
F_43 ( V_68 , V_112 ) ;
V_44 -> V_76 = V_134 ;
V_44 -> V_77 = V_112 ;
return 0 ;
}
