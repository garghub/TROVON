int F_1 ( T_1 T_2 * V_1 , const T_3 * V_2 )
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
static int F_13 ( struct V_37 * V_38 ,
struct V_39 T_2 * V_40 ,
unsigned int * V_41 )
{
unsigned int V_42 , V_3 = 0 ;
void T_2 * V_43 ;
T_4 V_44 ;
V_45 -> V_46 . V_47 = V_48 ;
F_9 {
F_14 ( V_49 ) ;
F_14 ( V_50 ) ;
F_14 ( V_51 ) ;
F_14 ( V_52 ) ;
F_15 ( V_53 ) ; F_15 ( V_54 ) ; F_15 ( V_55 ) ; F_15 ( V_56 ) ; F_15 ( V_57 ) ;
F_15 ( V_58 ) ; F_15 ( V_59 ) ; F_15 ( V_60 ) ;
F_16 ( V_61 ) ;
F_16 ( V_62 ) ;
F_10 ( V_42 , & V_40 -> V_63 ) ;
V_38 -> V_63 = ( V_38 -> V_63 & ~ V_64 ) | ( V_42 & V_64 ) ;
V_38 -> V_65 = - 1 ;
F_10 ( V_44 , & V_40 -> V_66 ) ;
V_43 = F_11 ( V_44 ) ;
F_10 ( * V_41 , & V_40 -> V_67 ) ;
} F_12 ( V_3 ) ;
V_3 |= F_17 ( V_43 , 1 ) ;
return V_3 ;
}
T_5 long F_18 ( void )
{
struct V_37 * V_38 = F_19 () ;
struct V_68 T_2 * V_69 = (struct V_68 T_2 * ) ( V_38 -> V_56 - 8 ) ;
T_6 V_70 ;
unsigned int V_67 ;
if ( ! F_3 ( V_36 , V_69 , sizeof( * V_69 ) ) )
goto V_71;
if ( F_20 ( V_70 . V_72 [ 0 ] , & V_69 -> V_40 . V_73 )
|| ( V_74 > 1
&& F_21 ( ( ( ( char * ) & V_70 . V_72 ) + 4 ) ,
& V_69 -> V_75 ,
sizeof( V_69 -> V_75 ) ) ) )
goto V_71;
F_22 ( & V_70 ) ;
if ( F_13 ( V_38 , & V_69 -> V_40 , & V_67 ) )
goto V_71;
return V_67 ;
V_71:
F_23 ( V_38 , V_69 , L_1 ) ;
return 0 ;
}
T_5 long F_24 ( void )
{
struct V_37 * V_38 = F_19 () ;
struct V_76 T_2 * V_69 ;
T_6 V_70 ;
unsigned int V_67 ;
V_69 = (struct V_76 T_2 * ) ( V_38 -> V_56 - 4 ) ;
if ( ! F_3 ( V_36 , V_69 , sizeof( * V_69 ) ) )
goto V_71;
if ( F_21 ( & V_70 , & V_69 -> V_77 . V_78 , sizeof( V_70 ) ) )
goto V_71;
F_22 ( & V_70 ) ;
if ( F_13 ( V_38 , & V_69 -> V_77 . V_79 , & V_67 ) )
goto V_71;
if ( F_25 ( & V_69 -> V_77 . V_80 ) )
goto V_71;
return V_67 ;
V_71:
F_23 ( V_38 , V_69 , L_2 ) ;
return 0 ;
}
static int F_26 ( struct V_39 T_2 * V_40 ,
void T_2 * V_66 ,
struct V_37 * V_38 , unsigned int V_81 )
{
int V_3 = 0 ;
F_4 {
F_5 ( F_27 ( V_49 ) , ( unsigned int T_2 * ) & V_40 -> V_49 ) ;
F_5 ( F_27 ( V_50 ) , ( unsigned int T_2 * ) & V_40 -> V_50 ) ;
F_5 ( F_27 ( V_51 ) , ( unsigned int T_2 * ) & V_40 -> V_51 ) ;
F_5 ( F_27 ( V_52 ) , ( unsigned int T_2 * ) & V_40 -> V_52 ) ;
F_5 ( V_38 -> V_53 , & V_40 -> V_53 ) ;
F_5 ( V_38 -> V_54 , & V_40 -> V_54 ) ;
F_5 ( V_38 -> V_55 , & V_40 -> V_55 ) ;
F_5 ( V_38 -> V_56 , & V_40 -> V_56 ) ;
F_5 ( V_38 -> V_57 , & V_40 -> V_57 ) ;
F_5 ( V_38 -> V_58 , & V_40 -> V_58 ) ;
F_5 ( V_38 -> V_59 , & V_40 -> V_59 ) ;
F_5 ( V_38 -> V_67 , & V_40 -> V_67 ) ;
F_5 ( V_45 -> V_82 . V_83 , & V_40 -> V_84 ) ;
F_5 ( V_45 -> V_82 . V_85 , & V_40 -> V_3 ) ;
F_5 ( V_38 -> V_60 , & V_40 -> V_60 ) ;
F_5 ( V_38 -> V_61 , ( unsigned int T_2 * ) & V_40 -> V_61 ) ;
F_5 ( V_38 -> V_63 , & V_40 -> V_63 ) ;
F_5 ( V_38 -> V_56 , & V_40 -> V_86 ) ;
F_5 ( V_38 -> V_62 , ( unsigned int T_2 * ) & V_40 -> V_62 ) ;
F_5 ( F_6 ( V_66 ) , & V_40 -> V_66 ) ;
F_5 ( V_81 , & V_40 -> V_73 ) ;
F_5 ( V_45 -> V_82 . V_87 , & V_40 -> V_87 ) ;
} F_7 ( V_3 ) ;
return V_3 ;
}
static void T_2 * F_28 ( struct V_88 * V_89 , struct V_37 * V_38 ,
T_7 V_90 ,
void T_2 * * V_66 )
{
unsigned long V_56 ;
V_56 = V_38 -> V_56 ;
if ( V_89 -> V_91 . V_92 . V_93 & V_94 )
V_56 = F_29 ( V_56 , V_89 ) ;
else if ( ( V_38 -> V_62 & 0xffff ) != V_95 &&
! ( V_89 -> V_91 . V_92 . V_93 & V_96 ) &&
V_89 -> V_91 . V_92 . V_97 )
V_56 = ( unsigned long ) V_89 -> V_91 . V_92 . V_97 ;
if ( F_30 () ) {
unsigned long V_98 , V_99 ;
V_56 = F_31 ( V_56 , 1 , & V_98 , & V_99 ) ;
* V_66 = (struct V_100 T_2 * ) V_56 ;
if ( F_32 ( * V_66 , ( void T_2 * ) V_98 ,
V_99 ) < 0 )
return ( void T_2 * ) - 1L ;
}
V_56 -= V_90 ;
V_56 = ( ( V_56 + 4 ) & - 16ul ) - 4 ;
return ( void T_2 * ) V_56 ;
}
int F_33 ( int V_72 , struct V_88 * V_89 ,
T_8 * V_70 , struct V_37 * V_38 )
{
struct V_68 T_2 * V_69 ;
void T_2 * V_101 ;
int V_3 = 0 ;
void T_2 * V_66 = NULL ;
static const struct {
T_9 V_102 ;
T_4 V_103 ;
T_9 V_104 ;
} V_105 ( ( V_106 ) ) V_107 = {
0xb858 ,
V_108 ,
0x80cd ,
} ;
V_69 = F_28 ( V_89 , V_38 , sizeof( * V_69 ) , & V_66 ) ;
if ( ! F_3 ( V_6 , V_69 , sizeof( * V_69 ) ) )
return - V_7 ;
if ( F_34 ( V_72 , & V_69 -> V_72 ) )
return - V_7 ;
if ( F_26 ( & V_69 -> V_40 , V_66 , V_38 , V_70 -> V_72 [ 0 ] ) )
return - V_7 ;
if ( V_74 > 1 ) {
if ( F_35 ( V_69 -> V_75 , & V_70 -> V_72 [ 1 ] ,
sizeof( V_69 -> V_75 ) ) )
return - V_7 ;
}
if ( V_89 -> V_91 . V_92 . V_93 & V_96 ) {
V_101 = V_89 -> V_91 . V_92 . V_97 ;
} else {
if ( V_45 -> V_109 -> V_110 . V_111 )
V_101 = V_45 -> V_109 -> V_110 . V_111 +
V_112 -> V_113 ;
else
V_101 = & V_69 -> V_114 ;
}
F_4 {
F_5 ( F_6 ( V_101 ) , & V_69 -> V_115 ) ;
F_5 ( * ( ( V_116 * ) & V_107 ) , ( V_116 T_2 * ) V_69 -> V_114 ) ;
} F_7 ( V_3 ) ;
if ( V_3 )
return - V_7 ;
V_38 -> V_56 = ( unsigned long ) V_69 ;
V_38 -> V_60 = ( unsigned long ) V_89 -> V_91 . V_92 . V_117 ;
V_38 -> V_67 = V_72 ;
V_38 -> V_58 = 0 ;
V_38 -> V_59 = 0 ;
F_36 ( V_51 , V_95 ) ;
F_36 ( V_52 , V_95 ) ;
V_38 -> V_61 = V_118 ;
V_38 -> V_62 = V_95 ;
return 0 ;
}
int F_37 ( int V_72 , struct V_88 * V_89 ,
T_8 * V_70 , struct V_37 * V_38 )
{
struct V_76 T_2 * V_69 ;
void T_2 * V_101 ;
int V_3 = 0 ;
void T_2 * V_66 = NULL ;
static const struct {
T_10 V_119 ;
T_4 V_103 ;
T_9 V_104 ;
T_10 V_120 ;
} V_105 ( ( V_106 ) ) V_107 = {
0xb8 ,
V_121 ,
0x80cd ,
0 ,
} ;
V_69 = F_28 ( V_89 , V_38 , sizeof( * V_69 ) , & V_66 ) ;
if ( ! F_3 ( V_6 , V_69 , sizeof( * V_69 ) ) )
return - V_7 ;
F_4 {
F_5 ( V_72 , & V_69 -> V_72 ) ;
F_5 ( F_6 ( & V_69 -> V_122 ) , & V_69 -> V_123 ) ;
F_5 ( F_6 ( & V_69 -> V_77 ) , & V_69 -> V_124 ) ;
if ( V_125 )
F_5 ( V_126 , & V_69 -> V_77 . V_127 ) ;
else
F_5 ( 0 , & V_69 -> V_77 . V_127 ) ;
F_5 ( 0 , & V_69 -> V_77 . V_128 ) ;
F_38 ( & V_69 -> V_77 . V_80 , V_38 -> V_56 ) ;
if ( V_89 -> V_91 . V_92 . V_93 & V_96 )
V_101 = V_89 -> V_91 . V_92 . V_97 ;
else
V_101 = V_45 -> V_109 -> V_110 . V_111 +
V_112 -> V_129 ;
F_5 ( F_6 ( V_101 ) , & V_69 -> V_115 ) ;
F_5 ( * ( ( V_116 * ) & V_107 ) , ( V_116 T_2 * ) V_69 -> V_114 ) ;
} F_7 ( V_3 ) ;
V_3 |= F_1 ( & V_69 -> V_122 , & V_89 -> V_122 ) ;
V_3 |= F_26 ( & V_69 -> V_77 . V_79 , V_66 ,
V_38 , V_70 -> V_72 [ 0 ] ) ;
V_3 |= F_35 ( & V_69 -> V_77 . V_78 , V_70 , sizeof( * V_70 ) ) ;
if ( V_3 )
return - V_7 ;
V_38 -> V_56 = ( unsigned long ) V_69 ;
V_38 -> V_60 = ( unsigned long ) V_89 -> V_91 . V_92 . V_117 ;
V_38 -> V_67 = V_72 ;
V_38 -> V_58 = ( unsigned long ) & V_69 -> V_122 ;
V_38 -> V_59 = ( unsigned long ) & V_69 -> V_77 ;
F_36 ( V_51 , V_95 ) ;
F_36 ( V_52 , V_95 ) ;
V_38 -> V_61 = V_118 ;
V_38 -> V_62 = V_95 ;
return 0 ;
}
