T_1 long F_1 ( T_2 V_1 , T_3 T_4 * V_2 ,
T_3 T_4 * V_3 , T_3 T_4 * exp ,
T_5 V_4 )
{
return F_2 ( ( int ) V_1 , V_2 , V_3 , exp , F_3 ( V_4 ) ) ;
}
T_1 long F_4 ( T_2 V_5 , T_2 V_6 , T_2 V_7 )
{
return F_5 ( ( int ) V_5 , V_6 , V_7 ) ;
}
long F_6 ( T_2 V_8 , T_2 V_9 , T_2 V_10 , T_2 V_11 , T_5 V_12 ,
T_2 V_13 )
{
int V_14 ;
V_14 = V_8 >> 16 ;
V_8 &= 0xffff ;
switch ( V_8 ) {
case V_15 :
if ( V_13 )
return F_7 ( ( int ) V_9 ,
F_3 ( V_12 ) , V_10 ,
F_3 ( V_13 ) ) ;
case V_16 :
return F_8 ( ( int ) V_9 , F_3 ( V_12 ) , V_10 ,
NULL ) ;
case V_17 :
return F_9 ( ( int ) V_9 , ( int ) V_10 , V_11 ) ;
case V_18 :
return F_10 ( ( int ) V_9 , ( int ) V_10 , V_11 ,
F_3 ( V_12 ) ) ;
case V_19 :
return F_11 ( ( int ) V_9 , ( int ) V_10 , V_11 ,
F_3 ( V_12 ) ) ;
case V_20 :
return F_12 ( ( int ) V_9 , V_10 , ( int ) V_13 ,
V_11 , V_14 , F_3 ( V_12 ) ) ;
case V_21 :
return F_13 ( ( int ) V_9 , V_10 ) ;
case V_22 :
return F_14 ( ( int ) V_9 , V_10 , F_3 ( V_12 ) ) ;
case V_23 :
return F_15 ( ( int ) V_9 , V_10 , V_11 , V_14 ,
F_3 ( V_12 ) ) ;
case V_24 :
return F_16 ( F_3 ( V_12 ) ) ;
case V_25 :
return F_17 ( ( int ) V_9 , V_10 , V_11 ) ;
case V_26 :
return F_18 ( ( int ) V_9 , V_10 , F_3 ( V_12 ) ) ;
default:
return - V_27 ;
}
return - V_27 ;
}
T_1 long F_19 ( T_2 V_28 , T_2 V_29 , T_6 T_4 * V_30 , T_2 V_31 )
{
T_7 V_32 = F_20 () ;
int V_33 ;
T_8 V_34 ;
T_8 T_4 * V_35 ;
if ( V_30 && F_21 ( V_34 , V_30 ) )
return - V_36 ;
F_22 ( V_37 ) ;
V_35 = V_30 ? ( T_8 T_4 * ) & V_34 : NULL ;
V_33 = F_23 ( ( int ) V_28 , ( int ) V_29 , V_35 , V_31 ) ;
F_22 ( V_32 ) ;
if ( V_30 && F_24 ( V_34 , V_30 ) )
return - V_36 ;
return V_33 ;
}
T_1 int F_25 ( int V_28 , int V_29 , T_9 T_4 * V_30 , T_10 V_31 )
{
T_7 V_32 = F_20 () ;
int V_33 ;
T_11 V_38 ;
T_11 T_4 * V_35 ;
if ( V_30 && F_21 ( V_38 , V_30 ) )
return - V_36 ;
F_22 ( V_37 ) ;
V_35 = V_30 ? ( T_11 T_4 * ) & V_38 : NULL ;
V_33 = F_26 ( V_28 , V_29 , V_35 , V_31 ) ;
F_22 ( V_32 ) ;
if ( V_30 && F_24 ( V_38 , V_30 ) )
return - V_36 ;
return V_33 ;
}
long F_27 ( unsigned long V_39 , unsigned long V_40 , unsigned long V_41 ,
unsigned long V_42 , unsigned long V_43 , unsigned long V_44 ,
struct V_45 * V_46 )
{
int error ;
char * V_47 ;
V_47 = F_28 ( ( char T_4 * ) V_39 ) ;
error = F_29 ( V_47 ) ;
if ( F_30 ( V_47 ) )
goto V_48;
F_31 ( V_49 ) ;
F_32 ( V_49 ) ;
error = F_33 ( V_47 , F_3 ( V_40 ) , F_3 ( V_41 ) , V_46 ) ;
F_34 ( V_47 ) ;
V_48:
return error ;
}
T_1 long F_35 ( T_2 V_5 , T_2 V_7 , T_2 V_50 , T_2 V_51 , T_2 V_52 )
{
return F_36 ( ( int ) V_5 ,
( unsigned long ) V_7 ,
( unsigned long ) V_50 ,
( unsigned long ) V_51 ,
( unsigned long ) V_52 ) ;
}
T_1 long F_37 ( T_2 V_53 , struct V_54 T_4 * V_55 )
{
struct V_56 V_57 ;
int V_33 ;
T_7 V_32 = F_20 () ;
F_22 ( V_37 ) ;
V_33 = F_38 ( ( int ) V_53 , (struct V_56 T_4 * ) & V_57 ) ;
F_22 ( V_32 ) ;
if ( F_39 ( & V_57 , V_55 ) )
return - V_36 ;
return V_33 ;
}
T_1 long F_40 ( const char T_4 * V_47 , T_2 V_58 )
{
return F_41 ( V_47 , ( int ) V_58 ) ;
}
T_1 long F_42 ( const char T_4 * V_59 , T_2 V_58 )
{
return F_43 ( V_59 , ( int ) V_58 ) ;
}
T_1 long F_44 ( T_2 V_53 , unsigned int T_4 * V_60 , T_2 V_61 )
{
return F_45 ( ( int ) V_53 , V_60 , ( int ) V_61 ) ;
}
T_1 long F_46 ( T_2 V_62 , T_12 T_4 * V_63 )
{
return F_47 ( ( int ) V_62 , V_63 ) ;
}
T_1 long F_48 ( T_2 V_53 )
{
return F_49 ( ( int ) V_53 ) ;
}
T_1 long F_50 ( T_2 V_53 )
{
return F_51 ( ( int ) V_53 ) ;
}
T_1 long F_52 ( T_2 V_53 , T_2 V_64 )
{
return F_53 ( ( int ) V_53 , ( int ) V_64 ) ;
}
T_1 long F_54 ( const char T_4 * V_59 , T_2 V_58 )
{
return F_55 ( V_59 , ( int ) V_58 ) ;
}
long F_56 ( T_2 V_65 )
{
return F_57 ( ( int ) V_65 ) ;
}
T_8 F_58 ( unsigned int V_66 , T_2 V_30 , unsigned int V_67 )
{
return F_59 ( V_66 , ( int ) V_30 , V_67 ) ;
}
long F_60 ( const char T_4 * V_68 , T_2 V_69 )
{
return F_61 ( V_68 , ( int ) V_69 ) ;
}
long F_62 ( int V_66 , T_2 V_69 )
{
return F_63 ( V_66 , ( int ) V_69 ) ;
}
T_1 long F_64 ( const char T_4 * V_68 , char T_4 * V_70 , T_2 V_71 )
{
return F_65 ( V_68 , V_70 , ( int ) V_71 ) ;
}
T_1 long F_66 ( T_2 V_72 )
{
return F_67 ( ( int ) V_72 ) ;
}
T_1 long F_68 ( T_2 V_72 )
{
return F_69 ( ( int ) V_72 ) ;
}
T_1 long F_70 ( T_2 V_53 , struct V_73 T_4 * V_74 )
{
return F_71 ( ( int ) V_53 , V_74 ) ;
}
T_1 long F_72 ( T_2 V_53 )
{
return F_73 ( ( int ) V_53 ) ;
}
T_1 long F_74 ( T_2 V_53 , struct V_73 T_4 * V_74 )
{
return F_75 ( ( int ) V_53 , V_74 ) ;
}
T_1 long F_76 ( T_2 V_53 , T_2 V_72 , struct V_73 T_4 * V_74 )
{
return F_77 ( ( int ) V_53 , ( int ) V_72 , V_74 ) ;
}
T_1 long F_78 ( char T_4 * V_75 , T_2 V_76 )
{
return F_79 ( V_75 , ( int ) V_76 ) ;
}
T_1 long F_80 ( T_2 V_62 , T_12 T_4 * V_63 )
{
return F_81 ( ( int ) V_62 , V_63 ) ;
}
T_1 long F_82 ( char T_4 * V_75 , T_2 V_76 )
{
return F_83 ( V_75 , ( int ) V_76 ) ;
}
T_1 long F_84 ( T_2 V_53 , T_2 V_77 )
{
return F_85 ( ( int ) V_53 , ( int ) V_77 ) ;
}
long F_86 ( T_2 V_78 , T_2 V_79 )
{
return F_87 ( ( int ) V_78 , ( int ) V_79 ) ;
}
long F_88 ( T_2 V_78 , T_2 V_79 , T_2 V_80 )
{
return F_89 ( ( int ) V_78 , ( int ) V_79 , ( int ) V_80 ) ;
}
long F_90 ( T_2 V_78 , T_2 V_79 )
{
return F_91 ( ( int ) V_78 , ( int ) V_79 ) ;
}
long F_92 ( T_2 V_78 , T_2 V_79 , T_2 V_81 )
{
return F_93 ( ( int ) V_78 , ( int ) V_79 , ( int ) V_81 ) ;
}
T_1 long F_94 ( T_2 V_82 )
{
return F_95 ( ( int ) V_82 ) ;
}
T_1 long F_96 ( T_2 type , char T_4 * V_70 , T_2 V_76 )
{
return F_97 ( type , V_70 , ( int ) V_76 ) ;
}
T_1 long F_98 ( T_2 V_83 )
{
return F_99 ( ( int ) V_83 ) ;
}
unsigned long F_100 ( unsigned long V_84 , T_13 V_76 ,
unsigned long V_85 , unsigned long V_86 ,
unsigned long V_66 , unsigned long V_87 )
{
return F_101 ( V_84 , V_76 , V_85 , V_86 , V_66 , V_87 << 12 ) ;
}
long F_102 ( T_2 V_88 , T_2 V_53 , int V_64 )
{
return F_103 ( ( int ) V_88 , ( int ) V_53 , V_64 ) ;
}
T_14 F_104 ( unsigned int V_66 , char T_4 * V_89 , T_15 V_31 ,
T_2 V_90 , T_2 V_91 , T_2 V_92 )
{
return F_105 ( V_66 , V_89 , V_31 , ( ( T_11 ) V_91 << 32 ) | V_92 ) ;
}
T_14 F_106 ( unsigned int V_66 , const char T_4 * V_89 , T_15 V_31 ,
T_2 V_90 , T_2 V_91 , T_2 V_92 )
{
return F_107 ( V_66 , V_89 , V_31 , ( ( T_11 ) V_91 << 32 ) | V_92 ) ;
}
T_14 F_108 ( int V_66 , T_2 V_93 , T_2 V_94 , T_2 V_95 , T_2 V_31 )
{
return F_109 ( V_66 , ( ( T_11 ) V_94 << 32 ) | V_95 , V_31 ) ;
}
T_1 int F_110 ( const char T_4 * V_68 , T_2 V_96 ,
unsigned long V_97 , unsigned long V_98 )
{
return F_61 ( V_68 , ( V_97 << 32 ) | V_98 ) ;
}
T_1 long F_111 ( int V_66 , int V_58 , T_2 V_94 , T_2 V_95 ,
T_2 V_99 , T_2 V_100 )
{
return F_112 ( V_66 , V_58 , ( ( T_11 ) V_94 << 32 ) | V_95 ,
( ( T_11 ) V_99 << 32 ) | V_100 ) ;
}
T_1 int F_113 ( unsigned int V_66 , T_2 V_96 , unsigned long V_97 ,
unsigned long V_98 )
{
return F_63 ( V_66 , ( V_97 << 32 ) | V_98 ) ;
}
long F_114 ( T_2 V_101 , T_2 V_102 , char T_4 * V_70 ,
T_13 V_76 )
{
return F_115 ( ( V_103 ) V_101 << 32 | V_102 ,
V_70 , V_76 ) ;
}
long F_116 ( int V_66 , T_2 V_104 , T_2 V_105 , T_2 V_106 ,
T_13 V_76 , int V_107 )
{
return F_117 ( V_66 , ( V_103 ) V_105 << 32 | V_106 , V_76 ,
V_107 ) ;
}
T_1 long F_118 ( const char T_4 * V_108 ,
const char T_4 * V_109 ,
const void T_4 * V_110 ,
T_2 V_111 ,
T_2 V_112 )
{
return F_119 ( V_108 , V_109 , V_110 , V_111 , V_112 ) ;
}
T_1 long F_120 ( const char T_4 * V_108 ,
const char T_4 * V_109 ,
const char T_4 * V_113 ,
T_2 V_114 )
{
return F_121 ( V_108 , V_109 , V_113 , V_114 ) ;
}
T_1 long F_122 ( int V_66 , unsigned int V_86 ,
unsigned V_115 , unsigned V_116 ,
unsigned V_117 , unsigned V_118 )
{
T_11 V_30 = ( ( T_11 ) V_115 << 32 ) | V_116 ;
T_11 V_119 = ( ( T_11 ) V_117 << 32 ) | V_118 ;
return F_123 ( V_66 , V_30 , V_119 , V_86 ) ;
}
T_1 long F_124 ( int V_120 , unsigned int V_86 ,
unsigned V_121 , unsigned V_122 ,
int V_123 , const char T_4 * V_59 )
{
V_103 V_83 = ( ( V_103 ) V_121 << 32 ) | V_122 ;
return F_125 ( V_120 , V_86 , V_83 , V_123 , V_59 ) ;
}
