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
T_1 long F_19 ( T_2 V_28 , T_2 V_29 ,
T_6 T_4 * V_30 , T_2 V_31 )
{
return F_20 ( ( int ) V_28 , ( int ) V_29 , V_30 , V_31 ) ;
}
T_1 long F_21 ( T_2 V_28 , T_2 V_29 ,
T_7 T_4 * V_30 , T_2 V_31 )
{
return F_22 ( ( int ) V_28 , ( int ) V_29 ,
( V_32 T_4 * ) V_30 , V_31 ) ;
}
T_1 long F_23 ( T_2 V_5 , T_2 V_7 , T_2 V_33 , T_2 V_34 , T_2 V_35 )
{
return F_24 ( ( int ) V_5 ,
( unsigned long ) V_7 ,
( unsigned long ) V_33 ,
( unsigned long ) V_34 ,
( unsigned long ) V_35 ) ;
}
T_1 long F_25 ( T_2 V_36 ,
struct V_37 T_4 * V_38 )
{
return F_26 ( ( int ) V_36 , V_38 ) ;
}
T_1 long F_27 ( const char T_4 * V_39 , T_2 V_40 )
{
return F_28 ( V_39 , ( int ) V_40 ) ;
}
T_1 long F_29 ( const char T_4 * V_41 , T_2 V_40 )
{
return F_30 ( V_41 , ( int ) V_40 ) ;
}
T_1 long F_31 ( T_2 V_36 , unsigned int T_4 * V_42 , T_2 V_43 )
{
return F_32 ( ( int ) V_36 , V_42 , ( int ) V_43 ) ;
}
T_1 long F_33 ( T_2 V_44 , T_8 T_4 * V_45 )
{
return F_34 ( ( int ) V_44 , V_45 ) ;
}
T_1 long F_35 ( T_2 V_36 )
{
return F_36 ( ( int ) V_36 ) ;
}
T_1 long F_37 ( T_2 V_36 )
{
return F_38 ( ( int ) V_36 ) ;
}
T_1 long F_39 ( T_2 V_36 , T_2 V_46 )
{
return F_40 ( ( int ) V_36 , ( int ) V_46 ) ;
}
T_1 long F_41 ( const char T_4 * V_41 , T_2 V_40 )
{
return F_42 ( V_41 , ( int ) V_40 ) ;
}
long F_43 ( T_2 V_47 )
{
return F_44 ( ( int ) V_47 ) ;
}
V_32 F_45 ( unsigned int V_48 , T_2 V_30 , unsigned int V_49 )
{
return F_46 ( V_48 , ( int ) V_30 , V_49 ) ;
}
long F_47 ( const char T_4 * V_50 , T_2 V_51 )
{
return F_48 ( V_50 , ( int ) V_51 ) ;
}
long F_49 ( int V_48 , T_2 V_51 )
{
return F_50 ( V_48 , ( int ) V_51 ) ;
}
T_1 long F_51 ( const char T_4 * V_50 , char T_4 * V_52 , T_2 V_53 )
{
return F_52 ( V_50 , V_52 , ( int ) V_53 ) ;
}
T_1 long F_53 ( T_2 V_54 )
{
return F_54 ( ( int ) V_54 ) ;
}
T_1 long F_55 ( T_2 V_54 )
{
return F_56 ( ( int ) V_54 ) ;
}
T_1 long F_57 ( T_2 V_36 , struct V_55 T_4 * V_56 )
{
return F_58 ( ( int ) V_36 , V_56 ) ;
}
T_1 long F_59 ( T_2 V_36 )
{
return F_60 ( ( int ) V_36 ) ;
}
T_1 long F_61 ( T_2 V_36 , struct V_55 T_4 * V_56 )
{
return F_62 ( ( int ) V_36 , V_56 ) ;
}
T_1 long F_63 ( T_2 V_36 , T_2 V_54 , struct V_55 T_4 * V_56 )
{
return F_64 ( ( int ) V_36 , ( int ) V_54 , V_56 ) ;
}
T_1 long F_65 ( char T_4 * V_57 , T_2 V_58 )
{
return F_66 ( V_57 , ( int ) V_58 ) ;
}
T_1 long F_67 ( T_2 V_44 , T_8 T_4 * V_45 )
{
return F_68 ( ( int ) V_44 , V_45 ) ;
}
T_1 long F_69 ( char T_4 * V_57 , T_2 V_58 )
{
return F_70 ( V_57 , ( int ) V_58 ) ;
}
T_1 long F_71 ( T_2 V_36 , T_2 V_59 )
{
return F_72 ( ( int ) V_36 , ( int ) V_59 ) ;
}
long F_73 ( T_2 V_60 , T_2 V_61 )
{
return F_74 ( ( int ) V_60 , ( int ) V_61 ) ;
}
long F_75 ( T_2 V_60 , T_2 V_61 , T_2 V_62 )
{
return F_76 ( ( int ) V_60 , ( int ) V_61 , ( int ) V_62 ) ;
}
long F_77 ( T_2 V_60 , T_2 V_61 )
{
return F_78 ( ( int ) V_60 , ( int ) V_61 ) ;
}
long F_79 ( T_2 V_60 , T_2 V_61 , T_2 V_63 )
{
return F_80 ( ( int ) V_60 , ( int ) V_61 , ( int ) V_63 ) ;
}
T_1 long F_81 ( T_2 V_64 )
{
return F_82 ( ( int ) V_64 ) ;
}
T_1 long F_83 ( T_2 type , char T_4 * V_52 , T_2 V_58 )
{
return F_84 ( type , V_52 , ( int ) V_58 ) ;
}
T_1 long F_85 ( T_2 V_65 )
{
return F_86 ( ( int ) V_65 ) ;
}
unsigned long F_87 ( unsigned long V_66 , T_9 V_58 ,
unsigned long V_67 , unsigned long V_68 ,
unsigned long V_48 , unsigned long V_69 )
{
return F_88 ( V_66 , V_58 , V_67 , V_68 , V_48 , V_69 << 12 ) ;
}
long F_89 ( T_2 V_70 , T_2 V_36 , int V_46 )
{
return F_90 ( ( int ) V_70 , ( int ) V_36 , V_46 ) ;
}
T_10 F_91 ( unsigned int V_48 , char T_4 * V_71 , T_11 V_31 ,
T_2 V_72 , T_2 V_73 , T_2 V_74 )
{
return F_92 ( V_48 , V_71 , V_31 , ( ( V_75 ) V_73 << 32 ) | V_74 ) ;
}
T_10 F_93 ( unsigned int V_48 , const char T_4 * V_71 , T_11 V_31 ,
T_2 V_72 , T_2 V_73 , T_2 V_74 )
{
return F_94 ( V_48 , V_71 , V_31 , ( ( V_75 ) V_73 << 32 ) | V_74 ) ;
}
T_10 F_95 ( int V_48 , T_2 V_76 , T_2 V_77 , T_2 V_78 , T_2 V_31 )
{
return F_96 ( V_48 , ( ( V_75 ) V_77 << 32 ) | V_78 , V_31 ) ;
}
T_1 int F_97 ( const char T_4 * V_50 , T_2 V_79 ,
unsigned long V_80 , unsigned long V_81 )
{
return F_48 ( V_50 , ( V_80 << 32 ) | V_81 ) ;
}
T_1 long F_98 ( int V_48 , int V_40 , T_2 V_77 , T_2 V_78 ,
T_2 V_82 , T_2 V_83 )
{
return F_99 ( V_48 , V_40 , ( ( V_75 ) V_77 << 32 ) | V_78 ,
( ( V_75 ) V_82 << 32 ) | V_83 ) ;
}
T_1 int F_100 ( unsigned int V_48 , T_2 V_79 , unsigned long V_80 ,
unsigned long V_81 )
{
return F_50 ( V_48 , ( V_80 << 32 ) | V_81 ) ;
}
long F_101 ( T_2 V_84 , T_2 V_85 , char T_4 * V_52 ,
T_9 V_58 )
{
return F_102 ( ( V_86 ) V_84 << 32 | V_85 ,
V_52 , V_58 ) ;
}
long F_103 ( int V_48 , T_2 V_87 , T_2 V_88 , T_2 V_89 ,
T_9 V_58 , int V_90 )
{
return F_104 ( V_48 , ( V_86 ) V_88 << 32 | V_89 , V_58 ,
V_90 ) ;
}
T_1 long F_105 ( const char T_4 * V_91 ,
const char T_4 * V_92 ,
const void T_4 * V_93 ,
T_2 V_94 ,
T_2 V_95 )
{
return F_106 ( V_91 , V_92 , V_93 , V_94 , V_95 ) ;
}
T_1 long F_107 ( const char T_4 * V_91 ,
const char T_4 * V_92 ,
const char T_4 * V_96 ,
T_2 V_97 )
{
return F_108 ( V_91 , V_92 , V_96 , V_97 ) ;
}
T_1 long F_109 ( int V_48 , unsigned int V_68 ,
unsigned V_98 , unsigned V_99 ,
unsigned V_100 , unsigned V_101 )
{
V_75 V_30 = ( ( V_75 ) V_98 << 32 ) | V_99 ;
V_75 V_102 = ( ( V_75 ) V_100 << 32 ) | V_101 ;
return F_110 ( V_48 , V_30 , V_102 , V_68 ) ;
}
T_1 long F_111 ( int V_103 , unsigned int V_68 ,
unsigned V_104 , unsigned V_105 ,
int V_106 , const char T_4 * V_41 )
{
V_86 V_65 = ( ( V_86 ) V_104 << 32 ) | V_105 ;
return F_112 ( V_103 , V_68 , V_65 , V_106 , V_41 ) ;
}
