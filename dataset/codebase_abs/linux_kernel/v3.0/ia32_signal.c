int F_1 ( T_1 T_2 * V_1 , T_3 * V_2 )
{
int V_3 = 0 ;
if ( ! F_2 ( V_4 , V_1 , sizeof( T_1 ) ) )
return - V_5 ;
F_3 {
F_4 ( V_2 -> V_6 , & V_1 -> V_6 ) ;
F_4 ( V_2 -> V_7 , & V_1 -> V_7 ) ;
F_4 ( ( short ) V_2 -> V_8 , & V_1 -> V_8 ) ;
if ( V_2 -> V_8 < 0 ) {
F_4 ( V_2 -> V_9 , & V_1 -> V_9 ) ;
F_4 ( V_2 -> V_10 , & V_1 -> V_10 ) ;
F_4 ( F_5 ( V_2 -> V_11 ) , & V_1 -> V_11 ) ;
} else {
F_4 ( V_2 -> V_12 . V_13 [ 0 ] ,
& V_1 -> V_12 . V_13 [ 0 ] ) ;
switch ( V_2 -> V_8 >> 16 ) {
case V_14 >> 16 :
break;
case V_15 >> 16 :
F_4 ( V_2 -> V_16 , & V_1 -> V_16 ) ;
F_4 ( V_2 -> V_17 , & V_1 -> V_17 ) ;
F_4 ( V_2 -> V_18 , & V_1 -> V_18 ) ;
default:
case V_19 >> 16 :
F_4 ( V_2 -> V_10 , & V_1 -> V_10 ) ;
break;
case V_20 >> 16 :
F_4 ( V_2 -> V_21 , & V_1 -> V_21 ) ;
break;
case V_22 >> 16 :
F_4 ( V_2 -> V_23 , & V_1 -> V_23 ) ;
F_4 ( F_5 ( V_2 -> V_11 ) ,
& V_1 -> V_11 ) ;
break;
case V_24 >> 16 :
case V_25 >> 16 :
F_4 ( V_2 -> V_10 , & V_1 -> V_10 ) ;
F_4 ( V_2 -> V_26 , & V_1 -> V_26 ) ;
break;
}
}
} F_6 ( V_3 ) ;
return V_3 ;
}
int F_7 ( T_3 * V_1 , T_1 T_2 * V_2 )
{
int V_3 = 0 ;
T_4 V_27 ;
if ( ! F_2 ( V_28 , V_2 , sizeof( T_1 ) ) )
return - V_5 ;
F_8 {
F_9 ( V_1 -> V_6 , & V_2 -> V_6 ) ;
F_9 ( V_1 -> V_7 , & V_2 -> V_7 ) ;
F_9 ( V_1 -> V_8 , & V_2 -> V_8 ) ;
F_9 ( V_1 -> V_9 , & V_2 -> V_9 ) ;
F_9 ( V_1 -> V_10 , & V_2 -> V_10 ) ;
F_9 ( V_27 , & V_2 -> V_11 ) ;
V_1 -> V_11 = F_10 ( V_27 ) ;
} F_11 ( V_3 ) ;
return V_3 ;
}
T_5 long F_12 ( int V_29 , int V_30 , T_6 V_31 )
{
V_31 &= V_32 ;
F_13 ( & V_33 -> V_34 -> V_35 ) ;
V_33 -> V_36 = V_33 -> V_37 ;
F_14 ( & V_33 -> V_37 , V_31 ) ;
F_15 () ;
F_16 ( & V_33 -> V_34 -> V_35 ) ;
V_33 -> V_38 = V_39 ;
F_17 () ;
F_18 () ;
return - V_40 ;
}
T_5 long F_19 ( const T_7 T_2 * V_41 ,
T_7 T_2 * V_42 ,
struct V_43 * V_44 )
{
T_8 V_45 , V_46 ;
int V_47 , V_3 = 0 ;
T_9 V_48 ;
if ( V_41 ) {
T_4 V_49 ;
memset ( & V_45 , 0 , sizeof( T_8 ) ) ;
if ( ! F_2 ( V_28 , V_41 , sizeof( T_7 ) ) )
return - V_5 ;
F_8 {
F_9 ( V_49 , & V_41 -> V_50 ) ;
F_9 ( V_45 . V_51 , & V_41 -> V_51 ) ;
F_9 ( V_45 . V_52 , & V_41 -> V_52 ) ;
} F_11 ( V_3 ) ;
if ( V_3 )
return - V_5 ;
V_45 . V_50 = F_10 ( V_49 ) ;
}
V_48 = F_20 () ;
F_21 ( V_53 ) ;
V_47 = F_22 ( V_41 ? & V_45 : NULL , & V_46 , V_44 -> V_54 ) ;
F_21 ( V_48 ) ;
if ( V_47 >= 0 && V_42 ) {
if ( ! F_2 ( V_4 , V_42 , sizeof( T_7 ) ) )
return - V_5 ;
F_3 {
F_4 ( F_5 ( V_46 . V_50 ) , & V_42 -> V_50 ) ;
F_4 ( V_46 . V_51 , & V_42 -> V_51 ) ;
F_4 ( V_46 . V_52 , & V_42 -> V_52 ) ;
} F_6 ( V_3 ) ;
if ( V_3 )
V_47 = - V_5 ;
}
return V_47 ;
}
static int F_23 ( struct V_43 * V_44 ,
struct V_55 T_2 * V_56 ,
unsigned int * V_57 )
{
unsigned int V_58 , V_3 = 0 ;
void T_2 * V_59 ;
T_4 V_60 ;
F_24 () -> V_61 . V_62 = V_63 ;
F_8 {
F_25 ( V_64 ) ;
F_25 ( V_65 ) ;
F_25 ( V_66 ) ;
F_25 ( V_67 ) ;
F_26 ( V_68 ) ; F_26 ( V_69 ) ; F_26 ( V_70 ) ; F_26 ( V_54 ) ; F_26 ( V_71 ) ;
F_26 ( V_72 ) ; F_26 ( V_73 ) ; F_26 ( V_74 ) ;
F_27 ( V_75 ) ;
F_27 ( V_76 ) ;
F_9 ( V_58 , & V_56 -> V_77 ) ;
V_44 -> V_77 = ( V_44 -> V_77 & ~ V_78 ) | ( V_58 & V_78 ) ;
V_44 -> V_79 = - 1 ;
F_9 ( V_60 , & V_56 -> V_80 ) ;
V_59 = F_10 ( V_60 ) ;
V_3 |= F_28 ( V_59 ) ;
F_9 ( * V_57 , & V_56 -> V_81 ) ;
} F_11 ( V_3 ) ;
return V_3 ;
}
T_5 long F_29 ( struct V_43 * V_44 )
{
struct V_82 T_2 * V_83 = (struct V_82 T_2 * ) ( V_44 -> V_54 - 8 ) ;
T_10 V_84 ;
unsigned int V_81 ;
if ( ! F_2 ( V_28 , V_83 , sizeof( * V_83 ) ) )
goto V_85;
if ( F_30 ( V_84 . V_86 [ 0 ] , & V_83 -> V_56 . V_87 )
|| ( V_88 > 1
&& F_31 ( ( ( ( char * ) & V_84 . V_86 ) + 4 ) ,
& V_83 -> V_89 ,
sizeof( V_83 -> V_89 ) ) ) )
goto V_85;
F_32 ( & V_84 , ~ V_32 ) ;
F_13 ( & V_33 -> V_34 -> V_35 ) ;
V_33 -> V_37 = V_84 ;
F_15 () ;
F_16 ( & V_33 -> V_34 -> V_35 ) ;
if ( F_23 ( V_44 , & V_83 -> V_56 , & V_81 ) )
goto V_85;
return V_81 ;
V_85:
F_33 ( V_44 , V_83 , L_1 ) ;
return 0 ;
}
T_5 long F_34 ( struct V_43 * V_44 )
{
struct V_90 T_2 * V_83 ;
T_10 V_84 ;
unsigned int V_81 ;
struct V_43 V_91 ;
V_83 = (struct V_90 T_2 * ) ( V_44 -> V_54 - 4 ) ;
if ( ! F_2 ( V_28 , V_83 , sizeof( * V_83 ) ) )
goto V_85;
if ( F_31 ( & V_84 , & V_83 -> V_92 . V_93 , sizeof( V_84 ) ) )
goto V_85;
F_32 ( & V_84 , ~ V_32 ) ;
F_13 ( & V_33 -> V_34 -> V_35 ) ;
V_33 -> V_37 = V_84 ;
F_15 () ;
F_16 ( & V_33 -> V_34 -> V_35 ) ;
if ( F_23 ( V_44 , & V_83 -> V_92 . V_94 , & V_81 ) )
goto V_85;
V_91 = * V_44 ;
if ( F_19 ( & V_83 -> V_92 . V_95 , NULL , & V_91 ) == - V_5 )
goto V_85;
return V_81 ;
V_85:
F_33 ( V_44 , V_83 , L_2 ) ;
return 0 ;
}
static int F_35 ( struct V_55 T_2 * V_56 ,
void T_2 * V_80 ,
struct V_43 * V_44 , unsigned int V_31 )
{
int V_3 = 0 ;
F_3 {
F_4 ( F_36 ( V_64 ) , ( unsigned int T_2 * ) & V_56 -> V_64 ) ;
F_4 ( F_36 ( V_65 ) , ( unsigned int T_2 * ) & V_56 -> V_65 ) ;
F_4 ( F_36 ( V_66 ) , ( unsigned int T_2 * ) & V_56 -> V_66 ) ;
F_4 ( F_36 ( V_67 ) , ( unsigned int T_2 * ) & V_56 -> V_67 ) ;
F_4 ( V_44 -> V_68 , & V_56 -> V_68 ) ;
F_4 ( V_44 -> V_69 , & V_56 -> V_69 ) ;
F_4 ( V_44 -> V_70 , & V_56 -> V_70 ) ;
F_4 ( V_44 -> V_54 , & V_56 -> V_54 ) ;
F_4 ( V_44 -> V_71 , & V_56 -> V_71 ) ;
F_4 ( V_44 -> V_72 , & V_56 -> V_72 ) ;
F_4 ( V_44 -> V_73 , & V_56 -> V_73 ) ;
F_4 ( V_44 -> V_81 , & V_56 -> V_81 ) ;
F_4 ( V_33 -> V_96 . V_97 , & V_56 -> V_98 ) ;
F_4 ( V_33 -> V_96 . V_99 , & V_56 -> V_3 ) ;
F_4 ( V_44 -> V_74 , & V_56 -> V_74 ) ;
F_4 ( V_44 -> V_75 , ( unsigned int T_2 * ) & V_56 -> V_75 ) ;
F_4 ( V_44 -> V_77 , & V_56 -> V_77 ) ;
F_4 ( V_44 -> V_54 , & V_56 -> V_100 ) ;
F_4 ( V_44 -> V_76 , ( unsigned int T_2 * ) & V_56 -> V_76 ) ;
F_4 ( F_5 ( V_80 ) , & V_56 -> V_80 ) ;
F_4 ( V_31 , & V_56 -> V_87 ) ;
F_4 ( V_33 -> V_96 . V_101 , & V_56 -> V_101 ) ;
} F_6 ( V_3 ) ;
return V_3 ;
}
static void T_2 * F_37 ( struct V_102 * V_103 , struct V_43 * V_44 ,
T_11 V_104 ,
void * * V_80 )
{
unsigned long V_54 ;
V_54 = V_44 -> V_54 ;
if ( V_103 -> V_105 . V_106 & V_107 ) {
if ( F_38 ( V_54 ) == 0 )
V_54 = V_33 -> V_108 + V_33 -> V_109 ;
}
else if ( ( V_44 -> V_76 & 0xffff ) != V_110 &&
! ( V_103 -> V_105 . V_106 & V_111 ) &&
V_103 -> V_105 . V_112 )
V_54 = ( unsigned long ) V_103 -> V_105 . V_112 ;
if ( F_39 () ) {
V_54 = V_54 - V_113 ;
* V_80 = (struct V_114 * ) V_54 ;
if ( F_40 ( * V_80 ) < 0 )
return ( void T_2 * ) - 1L ;
}
V_54 -= V_104 ;
V_54 = ( ( V_54 + 4 ) & - 16ul ) - 4 ;
return ( void T_2 * ) V_54 ;
}
int F_41 ( int V_86 , struct V_102 * V_103 ,
T_12 * V_84 , struct V_43 * V_44 )
{
struct V_82 T_2 * V_83 ;
void T_2 * V_115 ;
int V_3 = 0 ;
void T_2 * V_80 = NULL ;
static const struct {
T_13 V_116 ;
T_4 V_117 ;
T_13 V_118 ;
} V_119 ( ( V_120 ) ) V_121 = {
0xb858 ,
V_122 ,
0x80cd ,
} ;
V_83 = F_37 ( V_103 , V_44 , sizeof( * V_83 ) , & V_80 ) ;
if ( ! F_2 ( V_4 , V_83 , sizeof( * V_83 ) ) )
return - V_5 ;
if ( F_42 ( V_86 , & V_83 -> V_86 ) )
return - V_5 ;
if ( F_35 ( & V_83 -> V_56 , V_80 , V_44 , V_84 -> V_86 [ 0 ] ) )
return - V_5 ;
if ( V_88 > 1 ) {
if ( F_43 ( V_83 -> V_89 , & V_84 -> V_86 [ 1 ] ,
sizeof( V_83 -> V_89 ) ) )
return - V_5 ;
}
if ( V_103 -> V_105 . V_106 & V_111 ) {
V_115 = V_103 -> V_105 . V_112 ;
} else {
if ( V_33 -> V_123 -> V_124 . V_125 )
V_115 = F_44 ( V_33 -> V_123 -> V_124 . V_125 ,
V_126 ) ;
else
V_115 = & V_83 -> V_127 ;
}
F_3 {
F_4 ( F_5 ( V_115 ) , & V_83 -> V_128 ) ;
F_4 ( * ( ( V_129 * ) & V_121 ) , ( V_129 * ) V_83 -> V_127 ) ;
} F_6 ( V_3 ) ;
if ( V_3 )
return - V_5 ;
V_44 -> V_54 = ( unsigned long ) V_83 ;
V_44 -> V_74 = ( unsigned long ) V_103 -> V_105 . V_130 ;
V_44 -> V_81 = V_86 ;
V_44 -> V_72 = 0 ;
V_44 -> V_73 = 0 ;
F_45 ( V_66 , V_110 ) ;
F_45 ( V_67 , V_110 ) ;
V_44 -> V_75 = V_131 ;
V_44 -> V_76 = V_110 ;
return 0 ;
}
int F_46 ( int V_86 , struct V_102 * V_103 , T_3 * V_132 ,
T_12 * V_84 , struct V_43 * V_44 )
{
struct V_90 T_2 * V_83 ;
void T_2 * V_115 ;
int V_3 = 0 ;
void T_2 * V_80 = NULL ;
static const struct {
T_14 V_133 ;
T_4 V_117 ;
T_13 V_118 ;
T_14 V_134 ;
} V_119 ( ( V_120 ) ) V_121 = {
0xb8 ,
V_135 ,
0x80cd ,
0 ,
} ;
V_83 = F_37 ( V_103 , V_44 , sizeof( * V_83 ) , & V_80 ) ;
if ( ! F_2 ( V_4 , V_83 , sizeof( * V_83 ) ) )
return - V_5 ;
F_3 {
F_4 ( V_86 , & V_83 -> V_86 ) ;
F_4 ( F_5 ( & V_83 -> V_132 ) , & V_83 -> V_136 ) ;
F_4 ( F_5 ( & V_83 -> V_92 ) , & V_83 -> V_137 ) ;
V_3 |= F_1 ( & V_83 -> V_132 , V_132 ) ;
if ( V_138 )
F_4 ( V_139 , & V_83 -> V_92 . V_140 ) ;
else
F_4 ( 0 , & V_83 -> V_92 . V_140 ) ;
F_4 ( 0 , & V_83 -> V_92 . V_141 ) ;
F_4 ( V_33 -> V_108 , & V_83 -> V_92 . V_95 . V_50 ) ;
F_4 ( F_38 ( V_44 -> V_54 ) ,
& V_83 -> V_92 . V_95 . V_51 ) ;
F_4 ( V_33 -> V_109 , & V_83 -> V_92 . V_95 . V_52 ) ;
V_3 |= F_35 ( & V_83 -> V_92 . V_94 , V_80 ,
V_44 , V_84 -> V_86 [ 0 ] ) ;
V_3 |= F_43 ( & V_83 -> V_92 . V_93 , V_84 , sizeof( * V_84 ) ) ;
if ( V_103 -> V_105 . V_106 & V_111 )
V_115 = V_103 -> V_105 . V_112 ;
else
V_115 = F_44 ( V_33 -> V_123 -> V_124 . V_125 ,
V_142 ) ;
F_4 ( F_5 ( V_115 ) , & V_83 -> V_128 ) ;
F_4 ( * ( ( V_129 * ) & V_121 ) , ( V_129 * ) V_83 -> V_127 ) ;
} F_6 ( V_3 ) ;
if ( V_3 )
return - V_5 ;
V_44 -> V_54 = ( unsigned long ) V_83 ;
V_44 -> V_74 = ( unsigned long ) V_103 -> V_105 . V_130 ;
V_44 -> V_81 = V_86 ;
V_44 -> V_72 = ( unsigned long ) & V_83 -> V_132 ;
V_44 -> V_73 = ( unsigned long ) & V_83 -> V_92 ;
F_45 ( V_66 , V_110 ) ;
F_45 ( V_67 , V_110 ) ;
V_44 -> V_75 = V_131 ;
V_44 -> V_76 = V_110 ;
return 0 ;
}
