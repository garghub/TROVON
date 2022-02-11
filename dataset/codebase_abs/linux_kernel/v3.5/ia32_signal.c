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
V_47 = F_19 ( V_41 ? & V_45 : NULL , & V_46 , V_44 -> V_54 ) ;
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
struct V_55 T_2 * V_56 ,
unsigned int * V_57 )
{
unsigned int V_58 , V_3 = 0 ;
void T_2 * V_59 ;
T_4 V_60 ;
F_21 () -> V_61 . V_62 = V_63 ;
F_9 {
F_22 ( V_64 ) ;
F_22 ( V_65 ) ;
F_22 ( V_66 ) ;
F_22 ( V_67 ) ;
F_23 ( V_68 ) ; F_23 ( V_69 ) ; F_23 ( V_70 ) ; F_23 ( V_54 ) ; F_23 ( V_71 ) ;
F_23 ( V_72 ) ; F_23 ( V_73 ) ; F_23 ( V_74 ) ;
F_24 ( V_75 ) ;
F_24 ( V_76 ) ;
F_10 ( V_58 , & V_56 -> V_77 ) ;
V_44 -> V_77 = ( V_44 -> V_77 & ~ V_78 ) | ( V_58 & V_78 ) ;
V_44 -> V_79 = - 1 ;
F_10 ( V_60 , & V_56 -> V_80 ) ;
V_59 = F_11 ( V_60 ) ;
V_3 |= F_25 ( V_59 ) ;
F_10 ( * V_57 , & V_56 -> V_81 ) ;
} F_12 ( V_3 ) ;
return V_3 ;
}
T_5 long F_26 ( struct V_43 * V_44 )
{
struct V_82 T_2 * V_83 = (struct V_82 T_2 * ) ( V_44 -> V_54 - 8 ) ;
T_7 V_84 ;
unsigned int V_81 ;
if ( ! F_3 ( V_36 , V_83 , sizeof( * V_83 ) ) )
goto V_85;
if ( F_27 ( V_84 . V_86 [ 0 ] , & V_83 -> V_56 . V_87 )
|| ( V_88 > 1
&& F_28 ( ( ( ( char * ) & V_84 . V_86 ) + 4 ) ,
& V_83 -> V_89 ,
sizeof( V_83 -> V_89 ) ) ) )
goto V_85;
F_29 ( & V_84 ) ;
if ( F_20 ( V_44 , & V_83 -> V_56 , & V_81 ) )
goto V_85;
return V_81 ;
V_85:
F_30 ( V_44 , V_83 , L_1 ) ;
return 0 ;
}
T_5 long F_31 ( struct V_43 * V_44 )
{
struct V_90 T_2 * V_83 ;
T_7 V_84 ;
unsigned int V_81 ;
struct V_43 V_91 ;
V_83 = (struct V_90 T_2 * ) ( V_44 -> V_54 - 4 ) ;
if ( ! F_3 ( V_36 , V_83 , sizeof( * V_83 ) ) )
goto V_85;
if ( F_28 ( & V_84 , & V_83 -> V_92 . V_93 , sizeof( V_84 ) ) )
goto V_85;
F_29 ( & V_84 ) ;
if ( F_20 ( V_44 , & V_83 -> V_92 . V_94 , & V_81 ) )
goto V_85;
V_91 = * V_44 ;
if ( F_16 ( & V_83 -> V_92 . V_95 , NULL , & V_91 ) == - V_7 )
goto V_85;
return V_81 ;
V_85:
F_30 ( V_44 , V_83 , L_2 ) ;
return 0 ;
}
static int F_32 ( struct V_55 T_2 * V_56 ,
void T_2 * V_80 ,
struct V_43 * V_44 , unsigned int V_39 )
{
int V_3 = 0 ;
F_4 {
F_5 ( F_33 ( V_64 ) , ( unsigned int T_2 * ) & V_56 -> V_64 ) ;
F_5 ( F_33 ( V_65 ) , ( unsigned int T_2 * ) & V_56 -> V_65 ) ;
F_5 ( F_33 ( V_66 ) , ( unsigned int T_2 * ) & V_56 -> V_66 ) ;
F_5 ( F_33 ( V_67 ) , ( unsigned int T_2 * ) & V_56 -> V_67 ) ;
F_5 ( V_44 -> V_68 , & V_56 -> V_68 ) ;
F_5 ( V_44 -> V_69 , & V_56 -> V_69 ) ;
F_5 ( V_44 -> V_70 , & V_56 -> V_70 ) ;
F_5 ( V_44 -> V_54 , & V_56 -> V_54 ) ;
F_5 ( V_44 -> V_71 , & V_56 -> V_71 ) ;
F_5 ( V_44 -> V_72 , & V_56 -> V_72 ) ;
F_5 ( V_44 -> V_73 , & V_56 -> V_73 ) ;
F_5 ( V_44 -> V_81 , & V_56 -> V_81 ) ;
F_5 ( V_96 -> V_97 . V_98 , & V_56 -> V_99 ) ;
F_5 ( V_96 -> V_97 . V_100 , & V_56 -> V_3 ) ;
F_5 ( V_44 -> V_74 , & V_56 -> V_74 ) ;
F_5 ( V_44 -> V_75 , ( unsigned int T_2 * ) & V_56 -> V_75 ) ;
F_5 ( V_44 -> V_77 , & V_56 -> V_77 ) ;
F_5 ( V_44 -> V_54 , & V_56 -> V_101 ) ;
F_5 ( V_44 -> V_76 , ( unsigned int T_2 * ) & V_56 -> V_76 ) ;
F_5 ( F_6 ( V_80 ) , & V_56 -> V_80 ) ;
F_5 ( V_39 , & V_56 -> V_87 ) ;
F_5 ( V_96 -> V_97 . V_102 , & V_56 -> V_102 ) ;
} F_7 ( V_3 ) ;
return V_3 ;
}
static void T_2 * F_34 ( struct V_103 * V_104 , struct V_43 * V_44 ,
T_11 V_105 ,
void * * V_80 )
{
unsigned long V_54 ;
V_54 = V_44 -> V_54 ;
if ( V_104 -> V_106 . V_107 & V_108 ) {
if ( F_35 ( V_54 ) == 0 )
V_54 = V_96 -> V_109 + V_96 -> V_110 ;
}
else if ( ( V_44 -> V_76 & 0xffff ) != V_111 &&
! ( V_104 -> V_106 . V_107 & V_112 ) &&
V_104 -> V_106 . V_113 )
V_54 = ( unsigned long ) V_104 -> V_106 . V_113 ;
if ( F_36 () ) {
V_54 = V_54 - V_114 ;
* V_80 = (struct V_115 * ) V_54 ;
if ( F_37 ( * V_80 ) < 0 )
return ( void T_2 * ) - 1L ;
}
V_54 -= V_105 ;
V_54 = ( ( V_54 + 4 ) & - 16ul ) - 4 ;
return ( void T_2 * ) V_54 ;
}
int F_38 ( int V_86 , struct V_103 * V_104 ,
T_12 * V_84 , struct V_43 * V_44 )
{
struct V_82 T_2 * V_83 ;
void T_2 * V_116 ;
int V_3 = 0 ;
void T_2 * V_80 = NULL ;
static const struct {
T_13 V_117 ;
T_4 V_118 ;
T_13 V_119 ;
} V_120 ( ( V_121 ) ) V_122 = {
0xb858 ,
V_123 ,
0x80cd ,
} ;
V_83 = F_34 ( V_104 , V_44 , sizeof( * V_83 ) , & V_80 ) ;
if ( ! F_3 ( V_6 , V_83 , sizeof( * V_83 ) ) )
return - V_7 ;
if ( F_39 ( V_86 , & V_83 -> V_86 ) )
return - V_7 ;
if ( F_32 ( & V_83 -> V_56 , V_80 , V_44 , V_84 -> V_86 [ 0 ] ) )
return - V_7 ;
if ( V_88 > 1 ) {
if ( F_40 ( V_83 -> V_89 , & V_84 -> V_86 [ 1 ] ,
sizeof( V_83 -> V_89 ) ) )
return - V_7 ;
}
if ( V_104 -> V_106 . V_107 & V_112 ) {
V_116 = V_104 -> V_106 . V_113 ;
} else {
if ( V_96 -> V_124 -> V_125 . V_126 )
V_116 = F_41 ( V_96 -> V_124 -> V_125 . V_126 ,
V_127 ) ;
else
V_116 = & V_83 -> V_128 ;
}
F_4 {
F_5 ( F_6 ( V_116 ) , & V_83 -> V_129 ) ;
F_5 ( * ( ( V_130 * ) & V_122 ) , ( V_130 * ) V_83 -> V_128 ) ;
} F_7 ( V_3 ) ;
if ( V_3 )
return - V_7 ;
V_44 -> V_54 = ( unsigned long ) V_83 ;
V_44 -> V_74 = ( unsigned long ) V_104 -> V_106 . V_131 ;
V_44 -> V_81 = V_86 ;
V_44 -> V_72 = 0 ;
V_44 -> V_73 = 0 ;
F_42 ( V_66 , V_111 ) ;
F_42 ( V_67 , V_111 ) ;
V_44 -> V_75 = V_132 ;
V_44 -> V_76 = V_111 ;
return 0 ;
}
int F_43 ( int V_86 , struct V_103 * V_104 , T_3 * V_133 ,
T_12 * V_84 , struct V_43 * V_44 )
{
struct V_90 T_2 * V_83 ;
void T_2 * V_116 ;
int V_3 = 0 ;
void T_2 * V_80 = NULL ;
static const struct {
T_14 V_134 ;
T_4 V_118 ;
T_13 V_119 ;
T_14 V_135 ;
} V_120 ( ( V_121 ) ) V_122 = {
0xb8 ,
V_136 ,
0x80cd ,
0 ,
} ;
V_83 = F_34 ( V_104 , V_44 , sizeof( * V_83 ) , & V_80 ) ;
if ( ! F_3 ( V_6 , V_83 , sizeof( * V_83 ) ) )
return - V_7 ;
F_4 {
F_5 ( V_86 , & V_83 -> V_86 ) ;
F_5 ( F_6 ( & V_83 -> V_133 ) , & V_83 -> V_137 ) ;
F_5 ( F_6 ( & V_83 -> V_92 ) , & V_83 -> V_138 ) ;
V_3 |= F_1 ( & V_83 -> V_133 , V_133 ) ;
if ( V_139 )
F_5 ( V_140 , & V_83 -> V_92 . V_141 ) ;
else
F_5 ( 0 , & V_83 -> V_92 . V_141 ) ;
F_5 ( 0 , & V_83 -> V_92 . V_142 ) ;
F_5 ( V_96 -> V_109 , & V_83 -> V_92 . V_95 . V_50 ) ;
F_5 ( F_35 ( V_44 -> V_54 ) ,
& V_83 -> V_92 . V_95 . V_51 ) ;
F_5 ( V_96 -> V_110 , & V_83 -> V_92 . V_95 . V_52 ) ;
V_3 |= F_32 ( & V_83 -> V_92 . V_94 , V_80 ,
V_44 , V_84 -> V_86 [ 0 ] ) ;
V_3 |= F_40 ( & V_83 -> V_92 . V_93 , V_84 , sizeof( * V_84 ) ) ;
if ( V_104 -> V_106 . V_107 & V_112 )
V_116 = V_104 -> V_106 . V_113 ;
else
V_116 = F_41 ( V_96 -> V_124 -> V_125 . V_126 ,
V_143 ) ;
F_5 ( F_6 ( V_116 ) , & V_83 -> V_129 ) ;
F_5 ( * ( ( V_130 * ) & V_122 ) , ( V_130 * ) V_83 -> V_128 ) ;
} F_7 ( V_3 ) ;
if ( V_3 )
return - V_7 ;
V_44 -> V_54 = ( unsigned long ) V_83 ;
V_44 -> V_74 = ( unsigned long ) V_104 -> V_106 . V_131 ;
V_44 -> V_81 = V_86 ;
V_44 -> V_72 = ( unsigned long ) & V_83 -> V_133 ;
V_44 -> V_73 = ( unsigned long ) & V_83 -> V_92 ;
F_42 ( V_66 , V_111 ) ;
F_42 ( V_67 , V_111 ) ;
V_44 -> V_75 = V_132 ;
V_44 -> V_76 = V_111 ;
return 0 ;
}
