T_1 long F_1 ( const char T_2 * V_1 , T_3 V_2 , T_3 V_3 )
{
return F_2 ( V_1 , F_3 ( V_2 ) , F_4 ( V_3 ) ) ;
}
T_1 long F_5 ( const char T_2 * V_1 , T_3 V_2 , T_3 V_3 )
{
return F_6 ( V_1 , F_3 ( V_2 ) , F_4 ( V_3 ) ) ;
}
T_1 long F_7 ( unsigned int V_4 , T_3 V_2 , T_3 V_3 )
{
return F_8 ( V_4 , F_3 ( V_2 ) , F_4 ( V_3 ) ) ;
}
T_1 long F_9 ( T_3 V_5 , T_3 V_6 )
{
return F_10 ( F_4 ( V_5 ) , F_4 ( V_6 ) ) ;
}
T_1 long F_11 ( T_3 V_7 )
{
return F_12 ( ( V_8 ) V_7 ) ;
}
T_1 long F_13 ( T_3 V_9 , T_3 V_10 )
{
return F_14 ( F_3 ( V_9 ) , F_3 ( V_10 ) ) ;
}
T_1 long F_15 ( T_3 V_11 )
{
return F_16 ( ( V_12 ) V_11 ) ;
}
T_1 long F_17 ( T_3 V_9 , T_3 V_10 , T_3 V_13 )
{
return F_18 ( F_3 ( V_9 ) , F_3 ( V_10 ) ,
F_3 ( V_13 ) ) ;
}
T_1 long F_19 ( T_3 T_2 * V_14 , T_3 T_2 * V_15 , T_3 T_2 * V_16 )
{
const struct V_17 * V_17 = F_20 () ;
int V_18 ;
T_3 V_9 , V_10 , V_13 ;
V_9 = F_21 ( F_22 ( V_17 -> V_19 , V_17 -> V_11 ) ) ;
V_10 = F_21 ( F_22 ( V_17 -> V_19 , V_17 -> V_10 ) ) ;
V_13 = F_21 ( F_22 ( V_17 -> V_19 , V_17 -> V_13 ) ) ;
if ( ! ( V_18 = F_23 ( V_9 , V_14 ) ) &&
! ( V_18 = F_23 ( V_10 , V_15 ) ) )
V_18 = F_23 ( V_13 , V_16 ) ;
return V_18 ;
}
T_1 long F_24 ( T_3 V_5 , T_3 V_6 , T_3 V_20 )
{
return F_25 ( F_4 ( V_5 ) , F_4 ( V_6 ) ,
F_4 ( V_20 ) ) ;
}
T_1 long F_26 ( T_3 T_2 * V_21 , T_3 T_2 * V_22 , T_3 T_2 * V_23 )
{
const struct V_17 * V_17 = F_20 () ;
int V_18 ;
T_3 V_5 , V_6 , V_20 ;
V_5 = F_27 ( F_28 ( V_17 -> V_19 , V_17 -> V_7 ) ) ;
V_6 = F_27 ( F_28 ( V_17 -> V_19 , V_17 -> V_6 ) ) ;
V_20 = F_27 ( F_28 ( V_17 -> V_19 , V_17 -> V_20 ) ) ;
if ( ! ( V_18 = F_23 ( V_5 , V_21 ) ) &&
! ( V_18 = F_23 ( V_6 , V_22 ) ) )
V_18 = F_23 ( V_20 , V_23 ) ;
return V_18 ;
}
T_1 long F_29 ( T_3 V_11 )
{
return F_30 ( ( V_12 ) V_11 ) ;
}
T_1 long F_31 ( T_3 V_7 )
{
return F_32 ( ( V_8 ) V_7 ) ;
}
static int F_33 ( T_3 T_2 * V_24 , struct V_25 * V_25 )
{
struct V_26 * V_19 = F_34 () ;
int V_27 ;
T_3 V_3 ;
T_4 V_28 ;
for ( V_27 = 0 ; V_27 < V_25 -> V_29 ; V_27 ++ ) {
V_28 = F_35 ( V_25 , V_27 ) ;
V_3 = ( T_3 ) F_28 ( V_19 , V_28 ) ;
if ( F_23 ( V_3 , V_24 + V_27 ) )
return - V_30 ;
}
return 0 ;
}
static int F_36 ( struct V_25 * V_25 , T_3 T_2 * V_24 )
{
struct V_26 * V_19 = F_34 () ;
int V_27 ;
T_3 V_3 ;
T_4 V_28 ;
for ( V_27 = 0 ; V_27 < V_25 -> V_29 ; V_27 ++ ) {
if ( F_37 ( V_3 , V_24 + V_27 ) )
return - V_30 ;
V_28 = F_38 ( V_19 , ( V_8 ) V_3 ) ;
if ( ! F_39 ( V_28 ) )
return - V_31 ;
F_35 ( V_25 , V_27 ) = V_28 ;
}
return 0 ;
}
T_1 long F_40 ( int V_32 , T_3 T_2 * V_24 )
{
int V_27 ;
if ( V_32 < 0 )
return - V_31 ;
F_41 ( V_33 -> V_17 -> V_25 ) ;
V_27 = V_33 -> V_17 -> V_25 -> V_29 ;
if ( V_32 ) {
if ( V_27 > V_32 ) {
V_27 = - V_31 ;
goto V_34;
}
if ( F_33 ( V_24 , V_33 -> V_17 -> V_25 ) ) {
V_27 = - V_30 ;
goto V_34;
}
}
V_34:
F_42 ( V_33 -> V_17 -> V_25 ) ;
return V_27 ;
}
T_1 long F_43 ( int V_32 , T_3 T_2 * V_24 )
{
struct V_25 * V_25 ;
int V_18 ;
if ( ! F_44 ( V_35 ) )
return - V_36 ;
if ( ( unsigned ) V_32 > V_37 )
return - V_31 ;
V_25 = F_45 ( V_32 ) ;
if ( ! V_25 )
return - V_38 ;
V_18 = F_36 ( V_25 , V_24 ) ;
if ( V_18 ) {
F_42 ( V_25 ) ;
return V_18 ;
}
V_18 = F_46 ( V_25 ) ;
F_42 ( V_25 ) ;
return V_18 ;
}
T_1 long F_47 ( void )
{
return F_21 ( F_22 ( F_34 () , F_48 () ) ) ;
}
T_1 long F_49 ( void )
{
return F_21 ( F_22 ( F_34 () , F_50 () ) ) ;
}
T_1 long F_51 ( void )
{
return F_27 ( F_28 ( F_34 () , F_52 () ) ) ;
}
T_1 long F_53 ( void )
{
return F_27 ( F_28 ( F_34 () , F_54 () ) ) ;
}
T_1 long F_55 ( T_5 V_39 , int V_40 , int V_41 , int V_42 , T_5 V_43 )
{
if ( V_39 >> 16 )
return - V_31 ;
switch ( V_39 ) {
case V_44 :
return F_56 ( V_40 , F_57 ( V_43 ) ,
V_41 , F_57 ( V_42 ) ) ;
case V_45 :
return F_58 ( V_40 , F_57 ( V_43 ) ,
V_41 , NULL ) ;
case V_46 :
return F_59 ( V_40 , V_41 , V_42 ) ;
case V_47 :
return F_60 ( V_40 , V_41 , V_42 ,
F_57 ( V_43 ) ) ;
case V_48 :
return F_61 ( V_40 , V_41 , V_42 ,
F_57 ( V_43 ) ) ;
case V_49 :
return F_62 ( V_40 , V_41 , 0 , V_42 ,
0 , F_57 ( V_43 ) ) ;
case V_50 :
return F_63 ( ( V_51 ) V_40 , V_41 ) ;
case V_52 :
return F_64 ( V_40 , V_41 , F_57 ( V_43 ) ) ;
case V_53 :
return F_65 ( V_40 , V_41 , V_42 ,
0 , F_57 ( V_43 ) ) ;
case V_54 :
return F_66 ( F_57 ( V_43 ) ) ;
case V_55 :
return F_67 ( V_40 , ( unsigned ) V_41 , V_42 ) ;
case V_56 :
return F_68 ( V_40 , V_41 , F_57 ( V_43 ) ) ;
}
return - V_57 ;
}
T_1 long F_69 ( const char T_2 * V_58 , unsigned long V_59 , unsigned long V_60 )
{
if ( ( int ) V_59 < 0 )
return - V_31 ;
else
return F_70 ( V_58 , ( V_59 << 32 ) | V_60 ) ;
}
T_1 long F_71 ( unsigned int V_4 , unsigned long V_59 , unsigned long V_60 )
{
if ( ( int ) V_59 < 0 )
return - V_31 ;
else
return F_72 ( V_4 , ( V_59 << 32 ) | V_60 ) ;
}
T_1 long F_73 ( unsigned int V_4 , char T_2 * V_61 ,
T_6 V_62 , T_5 V_63 , T_5 V_64 )
{
if ( ( V_65 ) V_62 < 0 )
return - V_31 ;
return F_74 ( V_4 , V_61 , V_62 , ( ( V_66 ) F_75 ( V_63 ) << 32 ) | F_75 ( V_64 ) ) ;
}
T_1 long F_76 ( unsigned int V_4 , const char T_2 * V_61 ,
T_6 V_62 , T_5 V_63 , T_5 V_64 )
{
if ( ( V_65 ) V_62 < 0 )
return - V_31 ;
return F_77 ( V_4 , V_61 , V_62 , ( ( V_66 ) F_75 ( V_63 ) << 32 ) | F_75 ( V_64 ) ) ;
}
T_1 V_65 F_78 ( int V_4 , T_5 V_67 , T_5 V_68 , T_7 V_62 )
{
return F_79 ( V_4 , ( ( V_66 ) F_75 ( V_67 ) << 32 ) | F_75 ( V_68 ) , V_62 ) ;
}
T_1 long F_80 ( int V_69 , int V_70 , T_8 T_2 * V_71 , T_6 V_62 )
{
T_9 V_72 = F_81 () ;
int V_73 ;
T_10 V_74 ;
if ( V_71 && F_37 ( V_74 , V_71 ) )
return - V_30 ;
F_82 ( V_75 ) ;
V_73 = F_83 ( V_69 , V_70 ,
V_71 ? ( T_10 V_76 T_2 * ) & V_74 : NULL , V_62 ) ;
F_82 ( V_72 ) ;
if ( V_71 && F_23 ( V_74 , V_71 ) )
return - V_30 ;
return V_73 ;
}
T_1 long F_84 ( int V_69 , int V_70 ,
T_11 T_2 * V_71 , T_7 V_62 )
{
T_9 V_72 = F_81 () ;
int V_73 ;
V_66 V_77 ;
if ( V_71 && F_37 ( V_77 , V_71 ) )
return - V_30 ;
F_82 ( V_75 ) ;
V_73 = F_85 ( V_69 , V_70 ,
V_71 ? ( V_66 V_76 T_2 * ) & V_77 : NULL ,
V_62 ) ;
F_82 ( V_72 ) ;
if ( V_71 && F_23 ( V_77 , V_71 ) )
return - V_30 ;
return V_73 ;
}
static int F_86 ( struct V_78 T_2 * V_61 , struct V_79 * V_80 )
{
struct V_78 V_81 ;
memset ( & V_81 , 0 , sizeof( V_81 ) ) ;
V_81 . V_82 = F_87 ( V_80 -> V_83 ) ;
V_81 . V_84 = V_80 -> V_85 ;
V_81 . V_86 = ( T_5 ) V_80 -> V_85 ;
V_81 . V_87 = V_80 -> V_88 ;
V_81 . V_89 = ( unsigned int ) V_80 -> V_90 ;
V_81 . V_91 = F_22 ( F_34 () , V_80 -> V_11 ) ;
V_81 . V_92 = F_28 ( F_34 () , V_80 -> V_7 ) ;
V_81 . V_93 = F_87 ( V_80 -> V_94 ) ;
V_81 . V_95 = V_80 -> V_96 ;
V_81 . V_97 = ( T_5 ) V_80 -> V_98 ;
V_81 . V_99 = ( T_5 ) V_80 -> V_100 ;
V_81 . V_101 = ( T_5 ) V_80 -> V_102 . V_103 ;
V_81 . V_104 = ( T_5 ) V_80 -> V_105 . V_103 ;
V_81 . V_106 = ( T_5 ) V_80 -> ctime . V_103 ;
return F_88 ( V_61 , & V_81 , sizeof( V_81 ) ) ? - V_30 : 0 ;
}
T_1 long F_89 ( const char T_2 * V_1 , struct V_78 T_2 * V_107 )
{
struct V_79 V_80 ;
int V_73 = F_90 ( V_1 , & V_80 ) ;
if ( ! V_73 )
V_73 = F_86 ( V_107 , & V_80 ) ;
return V_73 ;
}
T_1 long F_91 ( const char T_2 * V_1 , struct V_78 T_2 * V_107 )
{
struct V_79 V_80 ;
int V_73 = F_92 ( V_1 , & V_80 ) ;
if ( ! V_73 )
V_73 = F_86 ( V_107 , & V_80 ) ;
return V_73 ;
}
T_1 long F_93 ( unsigned long V_4 , struct V_78 T_2 * V_107 )
{
struct V_79 V_80 ;
int V_73 = F_94 ( V_4 , & V_80 ) ;
if ( ! V_73 )
V_73 = F_86 ( V_107 , & V_80 ) ;
return V_73 ;
}
T_1 long F_95 ( unsigned int V_108 , const char T_2 * V_1 ,
struct V_78 T_2 * V_107 , int V_109 )
{
struct V_79 V_80 ;
int error ;
error = F_96 ( V_108 , V_1 , & V_80 , V_109 ) ;
if ( error )
return error ;
return F_86 ( V_107 , & V_80 ) ;
}
T_1 unsigned long F_97 ( struct V_110 T_2 * V_111 )
{
struct V_110 V_112 ;
if ( F_98 ( & V_112 , V_111 , sizeof( V_112 ) ) )
return - V_30 ;
if ( V_112 . V_71 & ~ V_113 )
return - V_31 ;
return F_99 ( V_112 . V_114 , V_112 . V_115 , V_112 . V_116 , V_112 . V_117 , V_112 . V_4 ,
V_112 . V_71 >> V_118 ) ;
}
T_1 long F_100 ( struct V_110 T_2 * V_111 )
{
struct V_110 V_112 ;
if ( F_98 ( & V_112 , V_111 , sizeof( V_112 ) ) )
return - V_30 ;
return F_99 ( V_112 . V_114 , V_112 . V_115 , V_112 . V_116 , V_112 . V_117 , V_112 . V_4 , V_112 . V_71 ) ;
}
T_1 long F_101 ( unsigned int V_4 , char T_2 * V_119 , T_6 V_62 )
{
if ( ( V_65 ) V_62 < 0 )
return - V_31 ;
return F_102 ( V_4 , V_119 , V_62 ) ;
}
T_1 long F_103 ( unsigned int V_4 , const char T_2 * V_119 , T_6 V_62 )
{
if ( ( V_65 ) V_62 < 0 )
return - V_31 ;
return F_104 ( V_4 , V_119 , V_62 ) ;
}
T_1 long
F_105 ( int V_4 , V_66 V_71 , T_6 V_115 , int V_120 )
{
if ( V_120 == 4 )
V_120 = V_121 ;
else if ( V_120 == 5 )
V_120 = V_122 ;
return F_106 ( V_4 , V_71 , V_115 , V_120 ) ;
}
T_1 long
F_107 ( struct V_123 T_2 * args )
{
struct V_123 V_112 ;
if ( F_98 ( & V_112 , args , sizeof( V_112 ) ) )
return - V_30 ;
if ( V_112 . V_124 == 4 )
V_112 . V_124 = V_121 ;
else if ( V_112 . V_124 == 5 )
V_112 . V_124 = V_122 ;
return F_108 ( V_112 . V_4 , V_112 . V_71 , V_112 . V_115 , V_112 . V_124 ) ;
}
