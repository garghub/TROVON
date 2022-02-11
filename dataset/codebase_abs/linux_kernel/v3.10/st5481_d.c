static inline void F_1 ( struct V_1 * V_2 , int V_3 , void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) & V_2 -> V_7 ;
V_6 -> V_8 ( V_6 , V_3 , V_4 ) ;
}
static void
F_2 ( struct V_9 * V_10 , int V_11 , void * V_4 )
{
struct V_1 * V_2 = V_10 -> V_12 ;
if ( V_10 -> V_13 == V_14 )
F_3 ( V_2 ) ;
F_4 ( V_10 , V_15 ) ;
F_1 ( V_2 , V_16 | V_17 , NULL ) ;
}
static void
F_5 ( struct V_9 * V_10 , int V_11 , void * V_4 )
{
struct V_1 * V_2 = V_10 -> V_12 ;
if ( V_10 -> V_13 == V_14 )
F_3 ( V_2 ) ;
F_4 ( V_10 , V_18 ) ;
}
static void
F_6 ( struct V_9 * V_10 , int V_11 , void * V_4 )
{
struct V_1 * V_2 = V_10 -> V_12 ;
F_7 ( & V_2 -> V_19 , 0 ) ;
F_8 ( V_2 ) ;
F_4 ( V_10 , V_14 ) ;
F_1 ( V_2 , V_20 | V_17 , NULL ) ;
}
static void
F_9 ( struct V_9 * V_10 , int V_11 , void * V_4 )
{
struct V_1 * V_2 = V_10 -> V_12 ;
if ( V_10 -> V_13 == V_14 )
F_3 ( V_2 ) ;
F_4 ( V_10 , V_21 ) ;
}
static void
F_10 ( struct V_9 * V_10 , int V_11 , void * V_4 )
{
struct V_1 * V_2 = V_10 -> V_12 ;
F_11 ( V_2 , V_22 ) ;
F_4 ( V_10 , V_15 ) ;
F_1 ( V_2 , V_16 | V_17 , NULL ) ;
}
static void
F_12 ( struct V_9 * V_10 , int V_11 , void * V_4 )
{
}
static void
F_13 ( struct V_9 * V_10 , int V_11 , void * V_4 )
{
struct V_1 * V_2 = V_10 -> V_12 ;
F_11 ( V_2 , V_22 ) ;
F_11 ( V_2 , V_23 ) ;
F_14 ( & V_2 -> V_19 , V_24 , V_25 , NULL , 2 ) ;
F_11 ( V_2 , V_26 ) ;
F_4 ( V_10 , V_27 ) ;
}
void F_15 ( void * V_28 )
{
struct V_1 * V_2 = V_28 ;
F_16 ( & V_2 -> V_29 . V_30 , V_31 , NULL ) ;
}
static void F_17 ( struct V_32 * V_32 )
{
struct V_1 * V_2 = V_32 -> V_28 ;
struct V_33 * V_29 = & V_2 -> V_29 ;
long V_34 ;
F_18 ( 2 , L_1 ) ;
V_34 = F_19 ( V_29 -> V_32 , V_32 ) ;
F_20 ( V_34 , & V_29 -> V_35 ) ;
if ( F_21 ( V_32 -> V_36 < 0 ) ) {
switch ( V_32 -> V_36 ) {
case - V_37 :
case - V_38 :
case - V_39 :
F_18 ( 1 , L_2 , V_32 -> V_36 ) ;
break;
default:
F_22 ( L_3 , V_32 -> V_36 ) ;
if ( V_29 -> V_35 == 0 ) {
F_23 ( V_2 , V_40 | V_41 , F_15 , V_2 ) ;
}
break;
}
return;
}
F_16 ( & V_2 -> V_29 . V_30 , V_42 , ( void * ) V_34 ) ;
}
static void F_24 ( struct V_9 * V_30 , int V_11 , void * V_4 )
{
struct V_1 * V_2 = V_30 -> V_12 ;
struct V_33 * V_29 = & V_2 -> V_29 ;
struct V_32 * V_32 ;
int V_43 , V_44 ;
struct V_45 * V_46 ;
int V_34 = 0 ;
V_46 = V_29 -> V_47 ;
F_18 ( 2 , L_4 , V_46 -> V_43 ) ;
F_25 ( & V_29 -> V_48 , V_49 | V_50 ) ;
if ( F_26 ( V_34 , & V_29 -> V_35 ) ) {
F_22 ( L_5 , V_40 , V_34 , V_29 -> V_35 ) ;
return;
}
V_32 = V_29 -> V_32 [ V_34 ] ;
F_27 ( 0x10 , V_46 ) ;
V_43 = F_28 ( & V_29 -> V_48 ,
V_46 -> V_51 , V_46 -> V_43 , & V_44 ,
V_32 -> V_52 , 16 ) ;
F_29 ( V_46 , V_44 ) ;
if ( V_43 < 16 )
F_4 ( & V_29 -> V_30 , V_53 ) ;
else
F_4 ( & V_29 -> V_30 , V_54 ) ;
if ( V_46 -> V_43 == 0 ) {
V_29 -> V_47 = NULL ;
F_1 ( V_2 , V_55 | V_56 , NULL ) ;
F_30 ( V_46 ) ;
}
V_32 -> V_57 = V_43 ;
V_32 -> V_58 [ 0 ] . V_59 = 0 ;
V_32 -> V_58 [ 0 ] . V_60 = V_43 ;
V_32 -> V_61 = 1 ;
V_32 -> V_62 = V_2 -> V_63 ;
V_32 -> V_64 = V_65 ;
F_31 ( 0x20 , V_32 ) ;
F_32 ( V_32 , V_66 ) ;
}
static void F_33 ( struct V_9 * V_30 , int V_11 , void * V_4 )
{
struct V_1 * V_2 = V_30 -> V_12 ;
struct V_33 * V_29 = & V_2 -> V_29 ;
F_4 ( & V_29 -> V_30 , V_67 ) ;
F_34 ( V_2 , V_68 , 16 , NULL , NULL ) ;
}
static void F_35 ( struct V_9 * V_30 , int V_11 , void * V_4 )
{
struct V_1 * V_2 = V_30 -> V_12 ;
struct V_33 * V_29 = & V_2 -> V_29 ;
F_4 ( & V_29 -> V_30 , V_69 ) ;
}
static void F_36 ( struct V_9 * V_30 , int V_11 , void * V_4 )
{
struct V_1 * V_2 = V_30 -> V_12 ;
struct V_33 * V_29 = & V_2 -> V_29 ;
F_34 ( V_2 , V_68 , 16 , NULL , NULL ) ;
F_4 ( & V_29 -> V_30 , V_70 ) ;
}
static void F_37 ( struct V_9 * V_30 , int V_11 , void * V_4 )
{
struct V_1 * V_2 = V_30 -> V_12 ;
struct V_33 * V_29 = & V_2 -> V_29 ;
F_4 ( & V_29 -> V_30 , V_71 ) ;
F_38 ( V_2 , 0 ) ;
F_38 ( V_2 , 1 ) ;
}
static void F_39 ( struct V_9 * V_30 , int V_11 , void * V_4 )
{
struct V_1 * V_2 = V_30 -> V_12 ;
struct V_33 * V_29 = & V_2 -> V_29 ;
F_4 ( & V_29 -> V_30 , V_72 ) ;
F_23 ( V_2 , V_40 | V_41 , F_15 , V_2 ) ;
}
static void F_40 ( struct V_9 * V_30 , int V_11 , void * V_4 )
{
struct V_1 * V_2 = V_30 -> V_12 ;
struct V_33 * V_29 = & V_2 -> V_29 ;
F_4 ( & V_29 -> V_30 , V_73 ) ;
F_34 ( V_2 , V_68 , 0 , V_74 , V_2 ) ;
}
static void F_41 ( struct V_9 * V_30 , int V_11 , void * V_4 )
{
struct V_1 * V_2 = V_30 -> V_12 ;
struct V_33 * V_29 = & V_2 -> V_29 ;
if ( F_42 ( 0 , & V_29 -> V_35 ) || F_42 ( 1 , & V_29 -> V_35 ) ) {
F_4 ( & V_29 -> V_30 , V_75 ) ;
} else {
F_40 ( V_30 , V_11 , V_4 ) ;
}
}
static void F_43 ( struct V_9 * V_30 , int V_11 , void * V_4 )
{
struct V_1 * V_2 = V_30 -> V_12 ;
struct V_33 * V_29 = & V_2 -> V_29 ;
if ( ! F_42 ( 0 , & V_29 -> V_35 ) && ! F_42 ( 1 , & V_29 -> V_35 ) )
F_40 ( V_30 , V_11 , V_4 ) ;
}
static void F_44 ( struct V_9 * V_30 , int V_11 , void * V_4 )
{
struct V_1 * V_2 = V_30 -> V_12 ;
struct V_33 * V_29 = & V_2 -> V_29 ;
F_4 ( & V_29 -> V_30 , V_76 ) ;
if ( V_29 -> V_47 )
F_16 ( & V_29 -> V_30 , V_77 , NULL ) ;
}
static void F_45 ( struct V_9 * V_30 , int V_11 , void * V_4 )
{
struct V_1 * V_2 = V_30 -> V_12 ;
long V_34 = ( long ) V_4 ;
F_38 ( V_2 , V_34 ) ;
}
static void F_46 ( struct V_9 * V_30 , int V_11 , void * V_4 )
{
}
void F_47 ( struct V_5 * V_7 , int V_3 , void * V_4 )
{
struct V_1 * V_2 = V_7 -> V_78 ;
struct V_45 * V_46 = V_4 ;
switch ( V_3 ) {
case V_20 | V_79 :
F_16 ( & V_2 -> V_80 , V_81 , NULL ) ;
break;
case V_16 | V_79 :
F_16 ( & V_2 -> V_80 , V_82 , NULL ) ;
break;
case V_55 | V_79 :
F_18 ( 2 , L_6 , V_46 -> V_43 ) ;
F_48 ( V_2 -> V_29 . V_47 ) ;
V_2 -> V_29 . V_47 = V_46 ;
F_16 ( & V_2 -> V_29 . V_30 , V_77 , NULL ) ;
break;
default:
F_22 ( L_7 , V_3 ) ;
break;
}
}
static void F_8 ( struct V_1 * V_2 )
{
struct V_33 * V_29 = & V_2 -> V_29 ;
struct V_83 * V_84 = & V_2 -> V_84 ;
F_18 ( 8 , L_1 ) ;
F_4 ( & V_29 -> V_30 , V_76 ) ;
F_34 ( V_2 , V_85 , 0xfc , NULL , NULL ) ;
F_49 ( V_84 , V_86 ) ;
#ifdef F_50
F_34 ( V_87 , V_88 , 0x04 , NULL , NULL ) ;
#endif
F_23 ( V_2 , V_40 | V_41 , NULL , NULL ) ;
V_2 -> V_89 |= V_90 ;
F_34 ( V_2 , V_91 , V_2 -> V_89 , NULL , NULL ) ;
}
static void F_3 ( struct V_1 * V_2 )
{
F_18 ( 8 , L_1 ) ;
F_49 ( & V_2 -> V_84 , V_92 ) ;
V_2 -> V_89 &= ~ V_90 ;
F_34 ( V_2 , V_91 , V_2 -> V_89 , NULL , NULL ) ;
}
static int F_51 ( struct V_1 * V_2 )
{
struct V_93 * V_62 = V_2 -> V_63 ;
struct V_94 * V_95 ;
struct V_96 * V_97 = NULL ;
struct V_98 * V_99 ;
struct V_33 * V_29 = & V_2 -> V_29 ;
F_18 ( 2 , L_1 ) ;
V_95 = F_52 ( V_62 , 0 ) ;
if ( V_95 )
V_97 = F_53 ( V_95 , 3 ) ;
if ( ! V_97 )
return - V_100 ;
V_99 = & V_97 -> V_99 [ V_40 - 1 ] ;
F_18 ( 2 , L_8 ,
V_99 -> V_101 . V_102 , F_54 ( V_99 -> V_101 . V_103 ) ) ;
return F_55 ( V_29 -> V_32 , V_62 ,
F_56 ( V_62 , V_99 -> V_101 . V_102 ) ,
V_104 , V_105 ,
V_104 * V_105 ,
F_17 , V_2 ) ;
}
static void F_57 ( struct V_1 * V_2 )
{
struct V_33 * V_29 = & V_2 -> V_29 ;
F_18 ( 2 , L_1 ) ;
F_58 ( V_29 -> V_32 ) ;
}
int F_59 ( struct V_1 * V_2 )
{
int V_106 ;
F_18 ( 2 , L_1 ) ;
V_106 = F_51 ( V_2 ) ;
if ( V_106 )
goto V_107;
V_2 -> V_84 . V_108 = V_109 ;
V_2 -> V_84 . V_110 = V_104 ;
V_2 -> V_84 . V_111 = V_112 ;
V_2 -> V_84 . V_113 = V_114 | V_115 ;
V_2 -> V_84 . V_116 = V_117 ;
V_2 -> V_84 . V_2 = V_2 ;
V_2 -> V_84 . V_5 = & V_2 -> V_7 . V_6 ;
V_106 = F_60 ( & V_2 -> V_84 ) ;
if ( V_106 )
goto V_118;
V_2 -> V_80 . V_30 = & V_119 ;
V_2 -> V_80 . V_13 = V_15 ;
V_2 -> V_80 . V_120 = V_121 & 0x100 ;
V_2 -> V_80 . V_12 = V_2 ;
V_2 -> V_80 . V_122 = V_123 ;
F_61 ( & V_2 -> V_80 , & V_2 -> V_19 ) ;
V_2 -> V_29 . V_30 . V_30 = & V_124 ;
V_2 -> V_29 . V_30 . V_13 = V_76 ;
V_2 -> V_29 . V_30 . V_120 = V_121 & 0x100 ;
V_2 -> V_29 . V_30 . V_12 = V_2 ;
V_2 -> V_29 . V_30 . V_122 = V_125 ;
return 0 ;
V_118:
F_57 ( V_2 ) ;
V_107:
return V_106 ;
}
void F_62 ( struct V_1 * V_2 )
{
F_18 ( 2 , L_1 ) ;
F_63 ( & V_2 -> V_84 ) ;
F_57 ( V_2 ) ;
}
int T_1 F_64 ( void )
{
int V_106 ;
V_119 . V_126 = V_127 ;
V_119 . V_128 = V_129 ;
V_119 . V_130 = V_131 ;
V_119 . V_132 = V_133 ;
V_106 = F_65 ( & V_119 , V_134 , F_66 ( V_134 ) ) ;
if ( V_106 )
goto V_107;
V_124 . V_126 = V_135 ;
V_124 . V_128 = V_136 ;
V_124 . V_130 = V_137 ;
V_124 . V_132 = V_138 ;
V_106 = F_65 ( & V_124 , V_139 , F_66 ( V_139 ) ) ;
if ( V_106 )
goto V_140;
return 0 ;
V_140:
F_67 ( & V_119 ) ;
V_107:
return V_106 ;
}
void F_68 ( void )
{
F_67 ( & V_119 ) ;
F_67 ( & V_124 ) ;
}
