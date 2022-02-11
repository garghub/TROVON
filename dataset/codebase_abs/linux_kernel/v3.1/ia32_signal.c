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
T_7 V_32 ;
V_33 -> V_34 = V_33 -> V_32 ;
V_31 &= V_35 ;
F_13 ( & V_32 , V_31 ) ;
F_14 ( & V_32 ) ;
V_33 -> V_36 = V_37 ;
F_15 () ;
F_16 () ;
return - V_38 ;
}
T_5 long F_17 ( const T_8 T_2 * V_39 ,
T_8 T_2 * V_40 ,
struct V_41 * V_42 )
{
T_9 V_43 , V_44 ;
int V_45 , V_3 = 0 ;
T_10 V_46 ;
if ( V_39 ) {
T_4 V_47 ;
memset ( & V_43 , 0 , sizeof( T_9 ) ) ;
if ( ! F_2 ( V_28 , V_39 , sizeof( T_8 ) ) )
return - V_5 ;
F_8 {
F_9 ( V_47 , & V_39 -> V_48 ) ;
F_9 ( V_43 . V_49 , & V_39 -> V_49 ) ;
F_9 ( V_43 . V_50 , & V_39 -> V_50 ) ;
} F_11 ( V_3 ) ;
if ( V_3 )
return - V_5 ;
V_43 . V_48 = F_10 ( V_47 ) ;
}
V_46 = F_18 () ;
F_19 ( V_51 ) ;
V_45 = F_20 ( V_39 ? & V_43 : NULL , & V_44 , V_42 -> V_52 ) ;
F_19 ( V_46 ) ;
if ( V_45 >= 0 && V_40 ) {
if ( ! F_2 ( V_4 , V_40 , sizeof( T_8 ) ) )
return - V_5 ;
F_3 {
F_4 ( F_5 ( V_44 . V_48 ) , & V_40 -> V_48 ) ;
F_4 ( V_44 . V_49 , & V_40 -> V_49 ) ;
F_4 ( V_44 . V_50 , & V_40 -> V_50 ) ;
} F_6 ( V_3 ) ;
if ( V_3 )
V_45 = - V_5 ;
}
return V_45 ;
}
static int F_21 ( struct V_41 * V_42 ,
struct V_53 T_2 * V_54 ,
unsigned int * V_55 )
{
unsigned int V_56 , V_3 = 0 ;
void T_2 * V_57 ;
T_4 V_58 ;
F_22 () -> V_59 . V_60 = V_61 ;
F_8 {
F_23 ( V_62 ) ;
F_23 ( V_63 ) ;
F_23 ( V_64 ) ;
F_23 ( V_65 ) ;
F_24 ( V_66 ) ; F_24 ( V_67 ) ; F_24 ( V_68 ) ; F_24 ( V_52 ) ; F_24 ( V_69 ) ;
F_24 ( V_70 ) ; F_24 ( V_71 ) ; F_24 ( V_72 ) ;
F_25 ( V_73 ) ;
F_25 ( V_74 ) ;
F_9 ( V_56 , & V_54 -> V_75 ) ;
V_42 -> V_75 = ( V_42 -> V_75 & ~ V_76 ) | ( V_56 & V_76 ) ;
V_42 -> V_77 = - 1 ;
F_9 ( V_58 , & V_54 -> V_78 ) ;
V_57 = F_10 ( V_58 ) ;
V_3 |= F_26 ( V_57 ) ;
F_9 ( * V_55 , & V_54 -> V_79 ) ;
} F_11 ( V_3 ) ;
return V_3 ;
}
T_5 long F_27 ( struct V_41 * V_42 )
{
struct V_80 T_2 * V_81 = (struct V_80 T_2 * ) ( V_42 -> V_52 - 8 ) ;
T_7 V_82 ;
unsigned int V_79 ;
if ( ! F_2 ( V_28 , V_81 , sizeof( * V_81 ) ) )
goto V_83;
if ( F_28 ( V_82 . V_84 [ 0 ] , & V_81 -> V_54 . V_85 )
|| ( V_86 > 1
&& F_29 ( ( ( ( char * ) & V_82 . V_84 ) + 4 ) ,
& V_81 -> V_87 ,
sizeof( V_81 -> V_87 ) ) ) )
goto V_83;
F_30 ( & V_82 , ~ V_35 ) ;
F_14 ( & V_82 ) ;
if ( F_21 ( V_42 , & V_81 -> V_54 , & V_79 ) )
goto V_83;
return V_79 ;
V_83:
F_31 ( V_42 , V_81 , L_1 ) ;
return 0 ;
}
T_5 long F_32 ( struct V_41 * V_42 )
{
struct V_88 T_2 * V_81 ;
T_7 V_82 ;
unsigned int V_79 ;
struct V_41 V_89 ;
V_81 = (struct V_88 T_2 * ) ( V_42 -> V_52 - 4 ) ;
if ( ! F_2 ( V_28 , V_81 , sizeof( * V_81 ) ) )
goto V_83;
if ( F_29 ( & V_82 , & V_81 -> V_90 . V_91 , sizeof( V_82 ) ) )
goto V_83;
F_30 ( & V_82 , ~ V_35 ) ;
F_14 ( & V_82 ) ;
if ( F_21 ( V_42 , & V_81 -> V_90 . V_92 , & V_79 ) )
goto V_83;
V_89 = * V_42 ;
if ( F_17 ( & V_81 -> V_90 . V_93 , NULL , & V_89 ) == - V_5 )
goto V_83;
return V_79 ;
V_83:
F_31 ( V_42 , V_81 , L_2 ) ;
return 0 ;
}
static int F_33 ( struct V_53 T_2 * V_54 ,
void T_2 * V_78 ,
struct V_41 * V_42 , unsigned int V_31 )
{
int V_3 = 0 ;
F_3 {
F_4 ( F_34 ( V_62 ) , ( unsigned int T_2 * ) & V_54 -> V_62 ) ;
F_4 ( F_34 ( V_63 ) , ( unsigned int T_2 * ) & V_54 -> V_63 ) ;
F_4 ( F_34 ( V_64 ) , ( unsigned int T_2 * ) & V_54 -> V_64 ) ;
F_4 ( F_34 ( V_65 ) , ( unsigned int T_2 * ) & V_54 -> V_65 ) ;
F_4 ( V_42 -> V_66 , & V_54 -> V_66 ) ;
F_4 ( V_42 -> V_67 , & V_54 -> V_67 ) ;
F_4 ( V_42 -> V_68 , & V_54 -> V_68 ) ;
F_4 ( V_42 -> V_52 , & V_54 -> V_52 ) ;
F_4 ( V_42 -> V_69 , & V_54 -> V_69 ) ;
F_4 ( V_42 -> V_70 , & V_54 -> V_70 ) ;
F_4 ( V_42 -> V_71 , & V_54 -> V_71 ) ;
F_4 ( V_42 -> V_79 , & V_54 -> V_79 ) ;
F_4 ( V_33 -> V_94 . V_95 , & V_54 -> V_96 ) ;
F_4 ( V_33 -> V_94 . V_97 , & V_54 -> V_3 ) ;
F_4 ( V_42 -> V_72 , & V_54 -> V_72 ) ;
F_4 ( V_42 -> V_73 , ( unsigned int T_2 * ) & V_54 -> V_73 ) ;
F_4 ( V_42 -> V_75 , & V_54 -> V_75 ) ;
F_4 ( V_42 -> V_52 , & V_54 -> V_98 ) ;
F_4 ( V_42 -> V_74 , ( unsigned int T_2 * ) & V_54 -> V_74 ) ;
F_4 ( F_5 ( V_78 ) , & V_54 -> V_78 ) ;
F_4 ( V_31 , & V_54 -> V_85 ) ;
F_4 ( V_33 -> V_94 . V_99 , & V_54 -> V_99 ) ;
} F_6 ( V_3 ) ;
return V_3 ;
}
static void T_2 * F_35 ( struct V_100 * V_101 , struct V_41 * V_42 ,
T_11 V_102 ,
void * * V_78 )
{
unsigned long V_52 ;
V_52 = V_42 -> V_52 ;
if ( V_101 -> V_103 . V_104 & V_105 ) {
if ( F_36 ( V_52 ) == 0 )
V_52 = V_33 -> V_106 + V_33 -> V_107 ;
}
else if ( ( V_42 -> V_74 & 0xffff ) != V_108 &&
! ( V_101 -> V_103 . V_104 & V_109 ) &&
V_101 -> V_103 . V_110 )
V_52 = ( unsigned long ) V_101 -> V_103 . V_110 ;
if ( F_37 () ) {
V_52 = V_52 - V_111 ;
* V_78 = (struct V_112 * ) V_52 ;
if ( F_38 ( * V_78 ) < 0 )
return ( void T_2 * ) - 1L ;
}
V_52 -= V_102 ;
V_52 = ( ( V_52 + 4 ) & - 16ul ) - 4 ;
return ( void T_2 * ) V_52 ;
}
int F_39 ( int V_84 , struct V_100 * V_101 ,
T_12 * V_82 , struct V_41 * V_42 )
{
struct V_80 T_2 * V_81 ;
void T_2 * V_113 ;
int V_3 = 0 ;
void T_2 * V_78 = NULL ;
static const struct {
T_13 V_114 ;
T_4 V_115 ;
T_13 V_116 ;
} V_117 ( ( V_118 ) ) V_119 = {
0xb858 ,
V_120 ,
0x80cd ,
} ;
V_81 = F_35 ( V_101 , V_42 , sizeof( * V_81 ) , & V_78 ) ;
if ( ! F_2 ( V_4 , V_81 , sizeof( * V_81 ) ) )
return - V_5 ;
if ( F_40 ( V_84 , & V_81 -> V_84 ) )
return - V_5 ;
if ( F_33 ( & V_81 -> V_54 , V_78 , V_42 , V_82 -> V_84 [ 0 ] ) )
return - V_5 ;
if ( V_86 > 1 ) {
if ( F_41 ( V_81 -> V_87 , & V_82 -> V_84 [ 1 ] ,
sizeof( V_81 -> V_87 ) ) )
return - V_5 ;
}
if ( V_101 -> V_103 . V_104 & V_109 ) {
V_113 = V_101 -> V_103 . V_110 ;
} else {
if ( V_33 -> V_121 -> V_122 . V_123 )
V_113 = F_42 ( V_33 -> V_121 -> V_122 . V_123 ,
V_124 ) ;
else
V_113 = & V_81 -> V_125 ;
}
F_3 {
F_4 ( F_5 ( V_113 ) , & V_81 -> V_126 ) ;
F_4 ( * ( ( V_127 * ) & V_119 ) , ( V_127 * ) V_81 -> V_125 ) ;
} F_6 ( V_3 ) ;
if ( V_3 )
return - V_5 ;
V_42 -> V_52 = ( unsigned long ) V_81 ;
V_42 -> V_72 = ( unsigned long ) V_101 -> V_103 . V_128 ;
V_42 -> V_79 = V_84 ;
V_42 -> V_70 = 0 ;
V_42 -> V_71 = 0 ;
F_43 ( V_64 , V_108 ) ;
F_43 ( V_65 , V_108 ) ;
V_42 -> V_73 = V_129 ;
V_42 -> V_74 = V_108 ;
return 0 ;
}
int F_44 ( int V_84 , struct V_100 * V_101 , T_3 * V_130 ,
T_12 * V_82 , struct V_41 * V_42 )
{
struct V_88 T_2 * V_81 ;
void T_2 * V_113 ;
int V_3 = 0 ;
void T_2 * V_78 = NULL ;
static const struct {
T_14 V_131 ;
T_4 V_115 ;
T_13 V_116 ;
T_14 V_132 ;
} V_117 ( ( V_118 ) ) V_119 = {
0xb8 ,
V_133 ,
0x80cd ,
0 ,
} ;
V_81 = F_35 ( V_101 , V_42 , sizeof( * V_81 ) , & V_78 ) ;
if ( ! F_2 ( V_4 , V_81 , sizeof( * V_81 ) ) )
return - V_5 ;
F_3 {
F_4 ( V_84 , & V_81 -> V_84 ) ;
F_4 ( F_5 ( & V_81 -> V_130 ) , & V_81 -> V_134 ) ;
F_4 ( F_5 ( & V_81 -> V_90 ) , & V_81 -> V_135 ) ;
V_3 |= F_1 ( & V_81 -> V_130 , V_130 ) ;
if ( V_136 )
F_4 ( V_137 , & V_81 -> V_90 . V_138 ) ;
else
F_4 ( 0 , & V_81 -> V_90 . V_138 ) ;
F_4 ( 0 , & V_81 -> V_90 . V_139 ) ;
F_4 ( V_33 -> V_106 , & V_81 -> V_90 . V_93 . V_48 ) ;
F_4 ( F_36 ( V_42 -> V_52 ) ,
& V_81 -> V_90 . V_93 . V_49 ) ;
F_4 ( V_33 -> V_107 , & V_81 -> V_90 . V_93 . V_50 ) ;
V_3 |= F_33 ( & V_81 -> V_90 . V_92 , V_78 ,
V_42 , V_82 -> V_84 [ 0 ] ) ;
V_3 |= F_41 ( & V_81 -> V_90 . V_91 , V_82 , sizeof( * V_82 ) ) ;
if ( V_101 -> V_103 . V_104 & V_109 )
V_113 = V_101 -> V_103 . V_110 ;
else
V_113 = F_42 ( V_33 -> V_121 -> V_122 . V_123 ,
V_140 ) ;
F_4 ( F_5 ( V_113 ) , & V_81 -> V_126 ) ;
F_4 ( * ( ( V_127 * ) & V_119 ) , ( V_127 * ) V_81 -> V_125 ) ;
} F_6 ( V_3 ) ;
if ( V_3 )
return - V_5 ;
V_42 -> V_52 = ( unsigned long ) V_81 ;
V_42 -> V_72 = ( unsigned long ) V_101 -> V_103 . V_128 ;
V_42 -> V_79 = V_84 ;
V_42 -> V_70 = ( unsigned long ) & V_81 -> V_130 ;
V_42 -> V_71 = ( unsigned long ) & V_81 -> V_90 ;
F_43 ( V_64 , V_108 ) ;
F_43 ( V_65 , V_108 ) ;
V_42 -> V_73 = V_129 ;
V_42 -> V_74 = V_108 ;
return 0 ;
}
