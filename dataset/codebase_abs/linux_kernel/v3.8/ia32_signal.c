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
static int F_16 ( struct V_41 * V_42 ,
struct V_43 T_2 * V_44 ,
unsigned int * V_45 )
{
unsigned int V_46 , V_3 = 0 ;
void T_2 * V_47 ;
T_4 V_48 ;
F_17 () -> V_49 . V_50 = V_51 ;
F_9 {
F_18 ( V_52 ) ;
F_18 ( V_53 ) ;
F_18 ( V_54 ) ;
F_18 ( V_55 ) ;
F_19 ( V_56 ) ; F_19 ( V_57 ) ; F_19 ( V_58 ) ; F_19 ( V_59 ) ; F_19 ( V_60 ) ;
F_19 ( V_61 ) ; F_19 ( V_62 ) ; F_19 ( V_63 ) ;
F_20 ( V_64 ) ;
F_20 ( V_65 ) ;
F_10 ( V_46 , & V_44 -> V_66 ) ;
V_42 -> V_66 = ( V_42 -> V_66 & ~ V_67 ) | ( V_46 & V_67 ) ;
V_42 -> V_68 = - 1 ;
F_10 ( V_48 , & V_44 -> V_69 ) ;
V_47 = F_11 ( V_48 ) ;
F_10 ( * V_45 , & V_44 -> V_70 ) ;
} F_12 ( V_3 ) ;
V_3 |= F_21 ( V_47 , 1 ) ;
return V_3 ;
}
T_5 long F_22 ( struct V_41 * V_42 )
{
struct V_71 T_2 * V_72 = (struct V_71 T_2 * ) ( V_42 -> V_59 - 8 ) ;
T_7 V_73 ;
unsigned int V_70 ;
if ( ! F_3 ( V_36 , V_72 , sizeof( * V_72 ) ) )
goto V_74;
if ( F_23 ( V_73 . V_75 [ 0 ] , & V_72 -> V_44 . V_76 )
|| ( V_77 > 1
&& F_24 ( ( ( ( char * ) & V_73 . V_75 ) + 4 ) ,
& V_72 -> V_78 ,
sizeof( V_72 -> V_78 ) ) ) )
goto V_74;
F_25 ( & V_73 ) ;
if ( F_16 ( V_42 , & V_72 -> V_44 , & V_70 ) )
goto V_74;
return V_70 ;
V_74:
F_26 ( V_42 , V_72 , L_1 ) ;
return 0 ;
}
T_5 long F_27 ( struct V_41 * V_42 )
{
struct V_79 T_2 * V_72 ;
T_7 V_73 ;
unsigned int V_70 ;
V_72 = (struct V_79 T_2 * ) ( V_42 -> V_59 - 4 ) ;
if ( ! F_3 ( V_36 , V_72 , sizeof( * V_72 ) ) )
goto V_74;
if ( F_24 ( & V_73 , & V_72 -> V_80 . V_81 , sizeof( V_73 ) ) )
goto V_74;
F_25 ( & V_73 ) ;
if ( F_16 ( V_42 , & V_72 -> V_80 . V_82 , & V_70 ) )
goto V_74;
if ( F_28 ( & V_72 -> V_80 . V_83 ) )
goto V_74;
return V_70 ;
V_74:
F_26 ( V_42 , V_72 , L_2 ) ;
return 0 ;
}
static int F_29 ( struct V_43 T_2 * V_44 ,
void T_2 * V_69 ,
struct V_41 * V_42 , unsigned int V_39 )
{
int V_3 = 0 ;
F_4 {
F_5 ( F_30 ( V_52 ) , ( unsigned int T_2 * ) & V_44 -> V_52 ) ;
F_5 ( F_30 ( V_53 ) , ( unsigned int T_2 * ) & V_44 -> V_53 ) ;
F_5 ( F_30 ( V_54 ) , ( unsigned int T_2 * ) & V_44 -> V_54 ) ;
F_5 ( F_30 ( V_55 ) , ( unsigned int T_2 * ) & V_44 -> V_55 ) ;
F_5 ( V_42 -> V_56 , & V_44 -> V_56 ) ;
F_5 ( V_42 -> V_57 , & V_44 -> V_57 ) ;
F_5 ( V_42 -> V_58 , & V_44 -> V_58 ) ;
F_5 ( V_42 -> V_59 , & V_44 -> V_59 ) ;
F_5 ( V_42 -> V_60 , & V_44 -> V_60 ) ;
F_5 ( V_42 -> V_61 , & V_44 -> V_61 ) ;
F_5 ( V_42 -> V_62 , & V_44 -> V_62 ) ;
F_5 ( V_42 -> V_70 , & V_44 -> V_70 ) ;
F_5 ( V_84 -> V_85 . V_86 , & V_44 -> V_87 ) ;
F_5 ( V_84 -> V_85 . V_88 , & V_44 -> V_3 ) ;
F_5 ( V_42 -> V_63 , & V_44 -> V_63 ) ;
F_5 ( V_42 -> V_64 , ( unsigned int T_2 * ) & V_44 -> V_64 ) ;
F_5 ( V_42 -> V_66 , & V_44 -> V_66 ) ;
F_5 ( V_42 -> V_59 , & V_44 -> V_89 ) ;
F_5 ( V_42 -> V_65 , ( unsigned int T_2 * ) & V_44 -> V_65 ) ;
F_5 ( F_6 ( V_69 ) , & V_44 -> V_69 ) ;
F_5 ( V_39 , & V_44 -> V_76 ) ;
F_5 ( V_84 -> V_85 . V_90 , & V_44 -> V_90 ) ;
} F_7 ( V_3 ) ;
return V_3 ;
}
static void T_2 * F_31 ( struct V_91 * V_92 , struct V_41 * V_42 ,
T_8 V_93 ,
void T_2 * * V_69 )
{
unsigned long V_59 ;
V_59 = V_42 -> V_59 ;
if ( V_92 -> V_94 . V_95 & V_96 ) {
if ( F_32 ( V_59 ) == 0 )
V_59 = V_84 -> V_97 + V_84 -> V_98 ;
}
else if ( ( V_42 -> V_65 & 0xffff ) != V_99 &&
! ( V_92 -> V_94 . V_95 & V_100 ) &&
V_92 -> V_94 . V_101 )
V_59 = ( unsigned long ) V_92 -> V_94 . V_101 ;
if ( F_33 () ) {
unsigned long V_102 , V_103 ;
V_59 = F_34 ( V_59 , 1 , & V_102 , & V_103 ) ;
* V_69 = (struct V_104 T_2 * ) V_59 ;
if ( F_35 ( * V_69 , ( void T_2 * ) V_102 ,
V_103 ) < 0 )
return ( void T_2 * ) - 1L ;
}
V_59 -= V_93 ;
V_59 = ( ( V_59 + 4 ) & - 16ul ) - 4 ;
return ( void T_2 * ) V_59 ;
}
int F_36 ( int V_75 , struct V_91 * V_92 ,
T_9 * V_73 , struct V_41 * V_42 )
{
struct V_71 T_2 * V_72 ;
void T_2 * V_105 ;
int V_3 = 0 ;
void T_2 * V_69 = NULL ;
static const struct {
T_10 V_106 ;
T_4 V_107 ;
T_10 V_108 ;
} V_109 ( ( V_110 ) ) V_111 = {
0xb858 ,
V_112 ,
0x80cd ,
} ;
V_72 = F_31 ( V_92 , V_42 , sizeof( * V_72 ) , & V_69 ) ;
if ( ! F_3 ( V_6 , V_72 , sizeof( * V_72 ) ) )
return - V_7 ;
if ( F_37 ( V_75 , & V_72 -> V_75 ) )
return - V_7 ;
if ( F_29 ( & V_72 -> V_44 , V_69 , V_42 , V_73 -> V_75 [ 0 ] ) )
return - V_7 ;
if ( V_77 > 1 ) {
if ( F_38 ( V_72 -> V_78 , & V_73 -> V_75 [ 1 ] ,
sizeof( V_72 -> V_78 ) ) )
return - V_7 ;
}
if ( V_92 -> V_94 . V_95 & V_100 ) {
V_105 = V_92 -> V_94 . V_101 ;
} else {
if ( V_84 -> V_113 -> V_114 . V_115 )
V_105 = F_39 ( V_84 -> V_113 -> V_114 . V_115 ,
V_116 ) ;
else
V_105 = & V_72 -> V_117 ;
}
F_4 {
F_5 ( F_6 ( V_105 ) , & V_72 -> V_118 ) ;
F_5 ( * ( ( V_119 * ) & V_111 ) , ( V_119 T_2 * ) V_72 -> V_117 ) ;
} F_7 ( V_3 ) ;
if ( V_3 )
return - V_7 ;
V_42 -> V_59 = ( unsigned long ) V_72 ;
V_42 -> V_63 = ( unsigned long ) V_92 -> V_94 . V_120 ;
V_42 -> V_70 = V_75 ;
V_42 -> V_61 = 0 ;
V_42 -> V_62 = 0 ;
F_40 ( V_54 , V_99 ) ;
F_40 ( V_55 , V_99 ) ;
V_42 -> V_64 = V_121 ;
V_42 -> V_65 = V_99 ;
return 0 ;
}
int F_41 ( int V_75 , struct V_91 * V_92 , T_3 * V_122 ,
T_9 * V_73 , struct V_41 * V_42 )
{
struct V_79 T_2 * V_72 ;
void T_2 * V_105 ;
int V_3 = 0 ;
void T_2 * V_69 = NULL ;
static const struct {
T_11 V_123 ;
T_4 V_107 ;
T_10 V_108 ;
T_11 V_124 ;
} V_109 ( ( V_110 ) ) V_111 = {
0xb8 ,
V_125 ,
0x80cd ,
0 ,
} ;
V_72 = F_31 ( V_92 , V_42 , sizeof( * V_72 ) , & V_69 ) ;
if ( ! F_3 ( V_6 , V_72 , sizeof( * V_72 ) ) )
return - V_7 ;
F_4 {
F_5 ( V_75 , & V_72 -> V_75 ) ;
F_5 ( F_6 ( & V_72 -> V_122 ) , & V_72 -> V_126 ) ;
F_5 ( F_6 ( & V_72 -> V_80 ) , & V_72 -> V_127 ) ;
if ( V_128 )
F_5 ( V_129 , & V_72 -> V_80 . V_130 ) ;
else
F_5 ( 0 , & V_72 -> V_80 . V_130 ) ;
F_5 ( 0 , & V_72 -> V_80 . V_131 ) ;
V_3 |= F_42 ( & V_72 -> V_80 . V_83 , V_42 -> V_59 ) ;
if ( V_92 -> V_94 . V_95 & V_100 )
V_105 = V_92 -> V_94 . V_101 ;
else
V_105 = F_39 ( V_84 -> V_113 -> V_114 . V_115 ,
V_132 ) ;
F_5 ( F_6 ( V_105 ) , & V_72 -> V_118 ) ;
F_5 ( * ( ( V_119 * ) & V_111 ) , ( V_119 T_2 * ) V_72 -> V_117 ) ;
} F_7 ( V_3 ) ;
V_3 |= F_1 ( & V_72 -> V_122 , V_122 ) ;
V_3 |= F_29 ( & V_72 -> V_80 . V_82 , V_69 ,
V_42 , V_73 -> V_75 [ 0 ] ) ;
V_3 |= F_38 ( & V_72 -> V_80 . V_81 , V_73 , sizeof( * V_73 ) ) ;
if ( V_3 )
return - V_7 ;
V_42 -> V_59 = ( unsigned long ) V_72 ;
V_42 -> V_63 = ( unsigned long ) V_92 -> V_94 . V_120 ;
V_42 -> V_70 = V_75 ;
V_42 -> V_61 = ( unsigned long ) & V_72 -> V_122 ;
V_42 -> V_62 = ( unsigned long ) & V_72 -> V_80 ;
F_40 ( V_54 , V_99 ) ;
F_40 ( V_55 , V_99 ) ;
V_42 -> V_64 = V_121 ;
V_42 -> V_65 = V_99 ;
return 0 ;
}
