int F_1 ( T_1 T_2 * V_1 , T_3 * V_2 )
{
int V_3 = 0 ;
bool V_4 = F_2 () ;
if ( ! F_3 ( V_5 , V_1 , sizeof( T_1 ) ) )
return - V_6 ;
F_4 {
F_5 ( V_2 -> V_7 , & V_1 -> V_7 ) ;
F_5 ( V_2 -> V_8 , & V_1 -> V_8 ) ;
F_5 ( ( short ) V_2 -> V_9 , & V_1 -> V_9 ) ;
if ( V_2 -> V_9 < 0 ) {
F_5 ( V_2 -> V_10 , & V_1 -> V_10 ) ;
F_5 ( V_2 -> V_11 , & V_1 -> V_11 ) ;
F_5 ( F_6 ( V_2 -> V_12 ) , & V_1 -> V_12 ) ;
} else {
F_5 ( V_2 -> V_13 . V_14 [ 0 ] ,
& V_1 -> V_13 . V_14 [ 0 ] ) ;
switch ( V_2 -> V_9 >> 16 ) {
case V_15 >> 16 :
break;
case V_16 >> 16 :
if ( V_4 ) {
F_5 ( V_2 -> V_17 , & V_1 -> V_17 ) ;
F_5 ( V_2 -> V_18 , & V_1 -> V_18 ) ;
} else {
F_5 ( V_2 -> V_17 , & V_1 -> V_13 . V_19 . V_20 ) ;
F_5 ( V_2 -> V_18 , & V_1 -> V_13 . V_19 . V_21 ) ;
}
F_5 ( V_2 -> V_22 , & V_1 -> V_22 ) ;
default:
case V_23 >> 16 :
F_5 ( V_2 -> V_11 , & V_1 -> V_11 ) ;
break;
case V_24 >> 16 :
F_5 ( V_2 -> V_25 , & V_1 -> V_25 ) ;
break;
case V_26 >> 16 :
F_5 ( V_2 -> V_27 , & V_1 -> V_27 ) ;
F_5 ( F_6 ( V_2 -> V_12 ) ,
& V_1 -> V_12 ) ;
break;
case V_28 >> 16 :
case V_29 >> 16 :
F_5 ( V_2 -> V_11 , & V_1 -> V_11 ) ;
F_5 ( V_2 -> V_30 , & V_1 -> V_30 ) ;
break;
}
}
} F_7 ( V_3 ) ;
return V_3 ;
}
int F_8 ( T_3 * V_1 , T_1 T_2 * V_2 )
{
int V_3 = 0 ;
T_4 V_31 ;
if ( ! F_3 ( V_32 , V_2 , sizeof( T_1 ) ) )
return - V_6 ;
F_9 {
F_10 ( V_1 -> V_7 , & V_2 -> V_7 ) ;
F_10 ( V_1 -> V_8 , & V_2 -> V_8 ) ;
F_10 ( V_1 -> V_9 , & V_2 -> V_9 ) ;
F_10 ( V_1 -> V_10 , & V_2 -> V_10 ) ;
F_10 ( V_1 -> V_11 , & V_2 -> V_11 ) ;
F_10 ( V_31 , & V_2 -> V_12 ) ;
V_1 -> V_12 = F_11 ( V_31 ) ;
} F_12 ( V_3 ) ;
return V_3 ;
}
T_5 long F_13 ( int V_33 , int V_34 , T_6 V_35 )
{
T_7 V_36 ;
V_37 -> V_38 = V_37 -> V_36 ;
V_35 &= V_39 ;
F_14 ( & V_36 , V_35 ) ;
F_15 ( & V_36 ) ;
V_37 -> V_40 = V_41 ;
F_16 () ;
F_17 () ;
return - V_42 ;
}
T_5 long F_18 ( const T_8 T_2 * V_43 ,
T_8 T_2 * V_44 ,
struct V_45 * V_46 )
{
T_9 V_47 , V_48 ;
int V_49 , V_3 = 0 ;
T_10 V_50 ;
if ( V_43 ) {
T_4 V_51 ;
memset ( & V_47 , 0 , sizeof( T_9 ) ) ;
if ( ! F_3 ( V_32 , V_43 , sizeof( T_8 ) ) )
return - V_6 ;
F_9 {
F_10 ( V_51 , & V_43 -> V_52 ) ;
F_10 ( V_47 . V_53 , & V_43 -> V_53 ) ;
F_10 ( V_47 . V_54 , & V_43 -> V_54 ) ;
} F_12 ( V_3 ) ;
if ( V_3 )
return - V_6 ;
V_47 . V_52 = F_11 ( V_51 ) ;
}
V_50 = F_19 () ;
F_20 ( V_55 ) ;
V_49 = F_21 ( V_43 ? & V_47 : NULL , & V_48 , V_46 -> V_56 ) ;
F_20 ( V_50 ) ;
if ( V_49 >= 0 && V_44 ) {
if ( ! F_3 ( V_5 , V_44 , sizeof( T_8 ) ) )
return - V_6 ;
F_4 {
F_5 ( F_6 ( V_48 . V_52 ) , & V_44 -> V_52 ) ;
F_5 ( V_48 . V_53 , & V_44 -> V_53 ) ;
F_5 ( V_48 . V_54 , & V_44 -> V_54 ) ;
} F_7 ( V_3 ) ;
if ( V_3 )
V_49 = - V_6 ;
}
return V_49 ;
}
static int F_22 ( struct V_45 * V_46 ,
struct V_57 T_2 * V_58 ,
unsigned int * V_59 )
{
unsigned int V_60 , V_3 = 0 ;
void T_2 * V_61 ;
T_4 V_62 ;
F_23 () -> V_63 . V_64 = V_65 ;
F_9 {
F_24 ( V_66 ) ;
F_24 ( V_67 ) ;
F_24 ( V_68 ) ;
F_24 ( V_69 ) ;
F_25 ( V_70 ) ; F_25 ( V_71 ) ; F_25 ( V_72 ) ; F_25 ( V_56 ) ; F_25 ( V_73 ) ;
F_25 ( V_74 ) ; F_25 ( V_75 ) ; F_25 ( V_76 ) ;
F_26 ( V_77 ) ;
F_26 ( V_78 ) ;
F_10 ( V_60 , & V_58 -> V_79 ) ;
V_46 -> V_79 = ( V_46 -> V_79 & ~ V_80 ) | ( V_60 & V_80 ) ;
V_46 -> V_81 = - 1 ;
F_10 ( V_62 , & V_58 -> V_82 ) ;
V_61 = F_11 ( V_62 ) ;
V_3 |= F_27 ( V_61 ) ;
F_10 ( * V_59 , & V_58 -> V_83 ) ;
} F_12 ( V_3 ) ;
return V_3 ;
}
T_5 long F_28 ( struct V_45 * V_46 )
{
struct V_84 T_2 * V_85 = (struct V_84 T_2 * ) ( V_46 -> V_56 - 8 ) ;
T_7 V_86 ;
unsigned int V_83 ;
if ( ! F_3 ( V_32 , V_85 , sizeof( * V_85 ) ) )
goto V_87;
if ( F_29 ( V_86 . V_88 [ 0 ] , & V_85 -> V_58 . V_89 )
|| ( V_90 > 1
&& F_30 ( ( ( ( char * ) & V_86 . V_88 ) + 4 ) ,
& V_85 -> V_91 ,
sizeof( V_85 -> V_91 ) ) ) )
goto V_87;
F_31 ( & V_86 , ~ V_39 ) ;
F_15 ( & V_86 ) ;
if ( F_22 ( V_46 , & V_85 -> V_58 , & V_83 ) )
goto V_87;
return V_83 ;
V_87:
F_32 ( V_46 , V_85 , L_1 ) ;
return 0 ;
}
T_5 long F_33 ( struct V_45 * V_46 )
{
struct V_92 T_2 * V_85 ;
T_7 V_86 ;
unsigned int V_83 ;
struct V_45 V_93 ;
V_85 = (struct V_92 T_2 * ) ( V_46 -> V_56 - 4 ) ;
if ( ! F_3 ( V_32 , V_85 , sizeof( * V_85 ) ) )
goto V_87;
if ( F_30 ( & V_86 , & V_85 -> V_94 . V_95 , sizeof( V_86 ) ) )
goto V_87;
F_31 ( & V_86 , ~ V_39 ) ;
F_15 ( & V_86 ) ;
if ( F_22 ( V_46 , & V_85 -> V_94 . V_96 , & V_83 ) )
goto V_87;
V_93 = * V_46 ;
if ( F_18 ( & V_85 -> V_94 . V_97 , NULL , & V_93 ) == - V_6 )
goto V_87;
return V_83 ;
V_87:
F_32 ( V_46 , V_85 , L_2 ) ;
return 0 ;
}
static int F_34 ( struct V_57 T_2 * V_58 ,
void T_2 * V_82 ,
struct V_45 * V_46 , unsigned int V_35 )
{
int V_3 = 0 ;
F_4 {
F_5 ( F_35 ( V_66 ) , ( unsigned int T_2 * ) & V_58 -> V_66 ) ;
F_5 ( F_35 ( V_67 ) , ( unsigned int T_2 * ) & V_58 -> V_67 ) ;
F_5 ( F_35 ( V_68 ) , ( unsigned int T_2 * ) & V_58 -> V_68 ) ;
F_5 ( F_35 ( V_69 ) , ( unsigned int T_2 * ) & V_58 -> V_69 ) ;
F_5 ( V_46 -> V_70 , & V_58 -> V_70 ) ;
F_5 ( V_46 -> V_71 , & V_58 -> V_71 ) ;
F_5 ( V_46 -> V_72 , & V_58 -> V_72 ) ;
F_5 ( V_46 -> V_56 , & V_58 -> V_56 ) ;
F_5 ( V_46 -> V_73 , & V_58 -> V_73 ) ;
F_5 ( V_46 -> V_74 , & V_58 -> V_74 ) ;
F_5 ( V_46 -> V_75 , & V_58 -> V_75 ) ;
F_5 ( V_46 -> V_83 , & V_58 -> V_83 ) ;
F_5 ( V_37 -> V_98 . V_99 , & V_58 -> V_100 ) ;
F_5 ( V_37 -> V_98 . V_101 , & V_58 -> V_3 ) ;
F_5 ( V_46 -> V_76 , & V_58 -> V_76 ) ;
F_5 ( V_46 -> V_77 , ( unsigned int T_2 * ) & V_58 -> V_77 ) ;
F_5 ( V_46 -> V_79 , & V_58 -> V_79 ) ;
F_5 ( V_46 -> V_56 , & V_58 -> V_102 ) ;
F_5 ( V_46 -> V_78 , ( unsigned int T_2 * ) & V_58 -> V_78 ) ;
F_5 ( F_6 ( V_82 ) , & V_58 -> V_82 ) ;
F_5 ( V_35 , & V_58 -> V_89 ) ;
F_5 ( V_37 -> V_98 . V_103 , & V_58 -> V_103 ) ;
} F_7 ( V_3 ) ;
return V_3 ;
}
static void T_2 * F_36 ( struct V_104 * V_105 , struct V_45 * V_46 ,
T_11 V_106 ,
void * * V_82 )
{
unsigned long V_56 ;
V_56 = V_46 -> V_56 ;
if ( V_105 -> V_107 . V_108 & V_109 ) {
if ( F_37 ( V_56 ) == 0 )
V_56 = V_37 -> V_110 + V_37 -> V_111 ;
}
else if ( ( V_46 -> V_78 & 0xffff ) != V_112 &&
! ( V_105 -> V_107 . V_108 & V_113 ) &&
V_105 -> V_107 . V_114 )
V_56 = ( unsigned long ) V_105 -> V_107 . V_114 ;
if ( F_38 () ) {
V_56 = V_56 - V_115 ;
* V_82 = (struct V_116 * ) V_56 ;
if ( F_39 ( * V_82 ) < 0 )
return ( void T_2 * ) - 1L ;
}
V_56 -= V_106 ;
V_56 = ( ( V_56 + 4 ) & - 16ul ) - 4 ;
return ( void T_2 * ) V_56 ;
}
int F_40 ( int V_88 , struct V_104 * V_105 ,
T_12 * V_86 , struct V_45 * V_46 )
{
struct V_84 T_2 * V_85 ;
void T_2 * V_117 ;
int V_3 = 0 ;
void T_2 * V_82 = NULL ;
static const struct {
T_13 V_118 ;
T_4 V_119 ;
T_13 V_120 ;
} V_121 ( ( V_122 ) ) V_123 = {
0xb858 ,
V_124 ,
0x80cd ,
} ;
V_85 = F_36 ( V_105 , V_46 , sizeof( * V_85 ) , & V_82 ) ;
if ( ! F_3 ( V_5 , V_85 , sizeof( * V_85 ) ) )
return - V_6 ;
if ( F_41 ( V_88 , & V_85 -> V_88 ) )
return - V_6 ;
if ( F_34 ( & V_85 -> V_58 , V_82 , V_46 , V_86 -> V_88 [ 0 ] ) )
return - V_6 ;
if ( V_90 > 1 ) {
if ( F_42 ( V_85 -> V_91 , & V_86 -> V_88 [ 1 ] ,
sizeof( V_85 -> V_91 ) ) )
return - V_6 ;
}
if ( V_105 -> V_107 . V_108 & V_113 ) {
V_117 = V_105 -> V_107 . V_114 ;
} else {
if ( V_37 -> V_125 -> V_126 . V_127 )
V_117 = F_43 ( V_37 -> V_125 -> V_126 . V_127 ,
V_128 ) ;
else
V_117 = & V_85 -> V_129 ;
}
F_4 {
F_5 ( F_6 ( V_117 ) , & V_85 -> V_130 ) ;
F_5 ( * ( ( V_131 * ) & V_123 ) , ( V_131 * ) V_85 -> V_129 ) ;
} F_7 ( V_3 ) ;
if ( V_3 )
return - V_6 ;
V_46 -> V_56 = ( unsigned long ) V_85 ;
V_46 -> V_76 = ( unsigned long ) V_105 -> V_107 . V_132 ;
V_46 -> V_83 = V_88 ;
V_46 -> V_74 = 0 ;
V_46 -> V_75 = 0 ;
F_44 ( V_68 , V_112 ) ;
F_44 ( V_69 , V_112 ) ;
V_46 -> V_77 = V_133 ;
V_46 -> V_78 = V_112 ;
return 0 ;
}
int F_45 ( int V_88 , struct V_104 * V_105 , T_3 * V_134 ,
T_12 * V_86 , struct V_45 * V_46 )
{
struct V_92 T_2 * V_85 ;
void T_2 * V_117 ;
int V_3 = 0 ;
void T_2 * V_82 = NULL ;
static const struct {
T_14 V_135 ;
T_4 V_119 ;
T_13 V_120 ;
T_14 V_136 ;
} V_121 ( ( V_122 ) ) V_123 = {
0xb8 ,
V_137 ,
0x80cd ,
0 ,
} ;
V_85 = F_36 ( V_105 , V_46 , sizeof( * V_85 ) , & V_82 ) ;
if ( ! F_3 ( V_5 , V_85 , sizeof( * V_85 ) ) )
return - V_6 ;
F_4 {
F_5 ( V_88 , & V_85 -> V_88 ) ;
F_5 ( F_6 ( & V_85 -> V_134 ) , & V_85 -> V_138 ) ;
F_5 ( F_6 ( & V_85 -> V_94 ) , & V_85 -> V_139 ) ;
V_3 |= F_1 ( & V_85 -> V_134 , V_134 ) ;
if ( V_140 )
F_5 ( V_141 , & V_85 -> V_94 . V_142 ) ;
else
F_5 ( 0 , & V_85 -> V_94 . V_142 ) ;
F_5 ( 0 , & V_85 -> V_94 . V_143 ) ;
F_5 ( V_37 -> V_110 , & V_85 -> V_94 . V_97 . V_52 ) ;
F_5 ( F_37 ( V_46 -> V_56 ) ,
& V_85 -> V_94 . V_97 . V_53 ) ;
F_5 ( V_37 -> V_111 , & V_85 -> V_94 . V_97 . V_54 ) ;
V_3 |= F_34 ( & V_85 -> V_94 . V_96 , V_82 ,
V_46 , V_86 -> V_88 [ 0 ] ) ;
V_3 |= F_42 ( & V_85 -> V_94 . V_95 , V_86 , sizeof( * V_86 ) ) ;
if ( V_105 -> V_107 . V_108 & V_113 )
V_117 = V_105 -> V_107 . V_114 ;
else
V_117 = F_43 ( V_37 -> V_125 -> V_126 . V_127 ,
V_144 ) ;
F_5 ( F_6 ( V_117 ) , & V_85 -> V_130 ) ;
F_5 ( * ( ( V_131 * ) & V_123 ) , ( V_131 * ) V_85 -> V_129 ) ;
} F_7 ( V_3 ) ;
if ( V_3 )
return - V_6 ;
V_46 -> V_56 = ( unsigned long ) V_85 ;
V_46 -> V_76 = ( unsigned long ) V_105 -> V_107 . V_132 ;
V_46 -> V_83 = V_88 ;
V_46 -> V_74 = ( unsigned long ) & V_85 -> V_134 ;
V_46 -> V_75 = ( unsigned long ) & V_85 -> V_94 ;
F_44 ( V_68 , V_112 ) ;
F_44 ( V_69 , V_112 ) ;
V_46 -> V_77 = V_133 ;
V_46 -> V_78 = V_112 ;
return 0 ;
}
