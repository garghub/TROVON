static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static T_1 F_3 ( struct V_5 * V_5 , char T_2 * V_6 ,
T_3 V_7 , T_4 * V_8 )
{
struct V_1 * V_9 = V_5 -> V_10 ;
char * V_11 = NULL ;
unsigned long V_12 ;
if ( ! V_7 )
return 0 ;
if ( ! F_4 ( V_13 , V_6 , V_7 ) )
return - V_14 ;
F_5 ( & V_9 -> V_15 , V_12 ) ;
#define F_6 (hidg->set_report_buff != NULL)
while ( ! F_6 ) {
F_7 ( & V_9 -> V_15 , V_12 ) ;
if ( V_5 -> V_16 & V_17 )
return - V_18 ;
if ( F_8 ( V_9 -> V_19 , F_6 ) )
return - V_20 ;
F_5 ( & V_9 -> V_15 , V_12 ) ;
}
V_7 = F_9 ( unsigned , V_7 , V_9 -> V_21 ) ;
V_11 = V_9 -> V_22 ;
V_9 -> V_22 = NULL ;
F_7 ( & V_9 -> V_15 , V_12 ) ;
if ( V_11 != NULL ) {
V_7 -= F_10 ( V_6 , V_11 , V_7 ) ;
F_11 ( V_11 ) ;
} else
V_7 = - V_23 ;
return V_7 ;
}
static void F_12 ( struct V_24 * V_25 , struct V_26 * V_27 )
{
struct V_1 * V_9 = (struct V_1 * ) V_25 -> V_28 ;
if ( V_27 -> V_29 != 0 ) {
ERROR ( V_9 -> V_4 . V_30 -> V_31 ,
L_1 , V_27 -> V_29 ) ;
}
V_9 -> V_32 = 0 ;
F_13 ( & V_9 -> V_33 ) ;
}
static T_1 F_14 ( struct V_5 * V_5 , const char T_2 * V_6 ,
T_3 V_7 , T_4 * V_34 )
{
struct V_1 * V_9 = V_5 -> V_10 ;
T_1 V_29 = - V_23 ;
if ( ! F_4 ( V_35 , V_6 , V_7 ) )
return - V_14 ;
F_15 ( & V_9 -> V_36 ) ;
#define F_16 (!hidg->write_pending)
while ( ! F_16 ) {
F_17 ( & V_9 -> V_36 ) ;
if ( V_5 -> V_16 & V_17 )
return - V_18 ;
if ( F_18 (
V_9 -> V_33 , F_16 ) )
return - V_20 ;
F_15 ( & V_9 -> V_36 ) ;
}
V_7 = F_9 ( unsigned , V_7 , V_9 -> V_37 ) ;
V_29 = F_19 ( V_9 -> V_27 -> V_38 , V_6 , V_7 ) ;
if ( V_29 != 0 ) {
ERROR ( V_9 -> V_4 . V_30 -> V_31 ,
L_2 ) ;
F_17 ( & V_9 -> V_36 ) ;
return - V_39 ;
}
V_9 -> V_27 -> V_29 = 0 ;
V_9 -> V_27 -> V_40 = 0 ;
V_9 -> V_27 -> V_41 = V_7 ;
V_9 -> V_27 -> V_42 = F_12 ;
V_9 -> V_27 -> V_43 = V_9 ;
V_9 -> V_32 = 1 ;
V_29 = F_20 ( V_9 -> V_44 , V_9 -> V_27 , V_45 ) ;
if ( V_29 < 0 ) {
ERROR ( V_9 -> V_4 . V_30 -> V_31 ,
L_3 , V_29 ) ;
V_9 -> V_32 = 0 ;
F_13 ( & V_9 -> V_33 ) ;
} else {
V_29 = V_7 ;
}
F_17 ( & V_9 -> V_36 ) ;
return V_29 ;
}
static unsigned int F_21 ( struct V_5 * V_5 , T_5 * V_46 )
{
struct V_1 * V_9 = V_5 -> V_10 ;
unsigned int V_47 = 0 ;
F_22 ( V_5 , & V_9 -> V_19 , V_46 ) ;
F_22 ( V_5 , & V_9 -> V_33 , V_46 ) ;
if ( F_16 )
V_47 |= V_48 | V_49 ;
if ( F_6 )
V_47 |= V_50 | V_51 ;
return V_47 ;
}
static int F_23 ( struct V_52 * V_52 , struct V_5 * V_53 )
{
V_53 -> V_10 = NULL ;
return 0 ;
}
static int F_24 ( struct V_52 * V_52 , struct V_5 * V_53 )
{
struct V_1 * V_9 =
F_2 ( V_52 -> V_54 , struct V_1 , V_31 ) ;
V_53 -> V_10 = V_9 ;
return 0 ;
}
static void F_25 ( struct V_24 * V_25 , struct V_26 * V_27 )
{
struct V_1 * V_9 = (struct V_1 * ) V_27 -> V_43 ;
if ( V_27 -> V_29 != 0 || V_27 -> V_38 == NULL || V_27 -> V_55 == 0 ) {
ERROR ( V_9 -> V_4 . V_30 -> V_31 , L_4 , V_56 ) ;
return;
}
F_26 ( & V_9 -> V_15 ) ;
V_9 -> V_22 = F_27 ( V_9 -> V_22 ,
V_27 -> V_55 , V_45 ) ;
if ( V_9 -> V_22 == NULL ) {
F_28 ( & V_9 -> V_15 ) ;
return;
}
V_9 -> V_21 = V_27 -> V_55 ;
memcpy ( V_9 -> V_22 , V_27 -> V_38 , V_27 -> V_55 ) ;
F_28 ( & V_9 -> V_15 ) ;
F_13 ( & V_9 -> V_19 ) ;
}
static int F_29 ( struct V_2 * V_3 ,
const struct V_57 * V_58 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
struct V_59 * V_31 = V_3 -> V_30 -> V_31 ;
struct V_26 * V_27 = V_31 -> V_27 ;
int V_29 = 0 ;
T_6 V_60 , V_41 ;
V_60 = F_30 ( V_58 -> V_61 ) ;
V_41 = F_30 ( V_58 -> V_62 ) ;
F_31 ( V_31 , L_5
L_6 , V_58 -> V_63 , V_58 -> V_64 , V_60 ) ;
switch ( ( V_58 -> V_63 << 8 ) | V_58 -> V_64 ) {
case ( ( V_65 | V_66 | V_67 ) << 8
| V_68 ) :
F_31 ( V_31 , L_7 ) ;
V_41 = F_9 ( unsigned , V_41 , V_9 -> V_37 ) ;
memset ( V_27 -> V_38 , 0x0 , V_41 ) ;
goto V_69;
break;
case ( ( V_65 | V_66 | V_67 ) << 8
| V_70 ) :
F_31 ( V_31 , L_8 ) ;
goto V_71;
break;
case ( ( V_72 | V_66 | V_67 ) << 8
| V_73 ) :
F_31 ( V_31 , L_9 , V_58 -> V_62 ) ;
V_27 -> V_43 = V_9 ;
V_27 -> V_42 = F_25 ;
goto V_69;
break;
case ( ( V_72 | V_66 | V_67 ) << 8
| V_74 ) :
F_31 ( V_31 , L_10 ) ;
goto V_71;
break;
case ( ( V_65 | V_75 | V_67 ) << 8
| V_76 ) :
switch ( V_60 >> 8 ) {
case V_77 :
F_31 ( V_31 , L_11 ) ;
V_41 = F_9 (unsigned short, length,
hidg_desc.bLength) ;
memcpy ( V_27 -> V_38 , & V_78 , V_41 ) ;
goto V_69;
break;
case V_79 :
F_31 ( V_31 , L_12 ) ;
V_41 = F_9 (unsigned short, length,
hidg->report_desc_length) ;
memcpy ( V_27 -> V_38 , V_9 -> V_80 , V_41 ) ;
goto V_69;
break;
default:
F_31 ( V_31 , L_13 ,
V_60 >> 8 ) ;
goto V_71;
break;
}
break;
default:
F_31 ( V_31 , L_14 ,
V_58 -> V_64 ) ;
goto V_71;
break;
}
V_71:
return - V_81 ;
V_69:
V_27 -> V_40 = 0 ;
V_27 -> V_41 = V_41 ;
V_29 = F_20 ( V_31 -> V_82 -> V_83 , V_27 , V_45 ) ;
if ( V_29 < 0 )
ERROR ( V_31 , L_15 , V_60 ) ;
return V_29 ;
}
static void F_32 ( struct V_2 * V_3 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
F_33 ( V_9 -> V_44 ) ;
V_9 -> V_44 -> V_28 = NULL ;
}
static int F_34 ( struct V_2 * V_3 , unsigned V_84 , unsigned V_85 )
{
struct V_59 * V_31 = V_3 -> V_30 -> V_31 ;
struct V_1 * V_9 = F_1 ( V_3 ) ;
int V_29 = 0 ;
F_31 ( V_31 , L_16 , V_84 , V_85 ) ;
if ( V_9 -> V_44 != NULL ) {
if ( V_9 -> V_44 -> V_28 != NULL )
F_33 ( V_9 -> V_44 ) ;
V_29 = F_35 ( V_3 -> V_30 -> V_31 -> V_82 , V_3 ,
V_9 -> V_44 ) ;
if ( V_29 ) {
ERROR ( V_31 , L_17 ) ;
goto V_86;
}
V_29 = F_36 ( V_9 -> V_44 ) ;
if ( V_29 < 0 ) {
ERROR ( V_31 , L_18 ) ;
goto V_86;
}
V_9 -> V_44 -> V_28 = V_9 ;
}
V_86:
return V_29 ;
}
static int T_7 F_37 ( struct V_87 * V_88 , struct V_2 * V_3 )
{
struct V_24 * V_25 ;
struct V_1 * V_9 = F_1 ( V_3 ) ;
int V_29 ;
T_8 V_89 ;
V_29 = F_38 ( V_88 , V_3 ) ;
if ( V_29 < 0 )
goto V_86;
V_90 . V_91 = V_29 ;
V_29 = - V_92 ;
V_25 = F_39 ( V_88 -> V_31 -> V_82 , & V_93 ) ;
if ( ! V_25 )
goto V_86;
V_25 -> V_28 = V_88 -> V_31 ;
V_9 -> V_44 = V_25 ;
V_29 = - V_23 ;
V_9 -> V_27 = F_40 ( V_9 -> V_44 , V_94 ) ;
if ( ! V_9 -> V_27 )
goto V_86;
V_9 -> V_27 -> V_38 = F_41 ( V_9 -> V_37 , V_94 ) ;
if ( ! V_9 -> V_27 -> V_38 )
goto V_86;
V_90 . V_95 = V_9 -> V_95 ;
V_90 . V_96 = V_9 -> V_96 ;
V_97 . V_98 = F_42 ( V_9 -> V_37 ) ;
V_93 . V_98 = F_42 ( V_9 -> V_37 ) ;
V_78 . V_99 [ 0 ] . V_100 = V_79 ;
V_78 . V_99 [ 0 ] . V_101 =
F_42 ( V_9 -> V_102 ) ;
V_9 -> V_22 = NULL ;
V_3 -> V_103 = F_43 ( V_104 ) ;
if ( ! V_3 -> V_103 )
goto V_86;
if ( F_44 ( V_88 -> V_31 -> V_82 ) ) {
V_97 . V_105 =
V_93 . V_105 ;
V_3 -> V_106 = F_43 ( V_107 ) ;
if ( ! V_3 -> V_106 )
goto V_86;
}
F_45 ( & V_9 -> V_36 ) ;
F_46 ( & V_9 -> V_15 ) ;
F_47 ( & V_9 -> V_33 ) ;
F_47 ( & V_9 -> V_19 ) ;
F_48 ( & V_9 -> V_31 , & V_108 ) ;
V_89 = F_49 ( V_109 , V_9 -> V_110 ) ;
V_29 = F_50 ( & V_9 -> V_31 , V_89 , 1 ) ;
if ( V_29 )
goto V_86;
F_51 ( V_111 , NULL , V_89 , NULL , L_19 , L_20 , V_9 -> V_110 ) ;
return 0 ;
V_86:
ERROR ( V_3 -> V_30 -> V_31 , L_21 ) ;
if ( V_9 -> V_27 != NULL ) {
F_11 ( V_9 -> V_27 -> V_38 ) ;
if ( V_9 -> V_44 != NULL )
F_52 ( V_9 -> V_44 , V_9 -> V_27 ) ;
}
F_53 ( V_3 -> V_106 ) ;
F_53 ( V_3 -> V_103 ) ;
return V_29 ;
}
static void F_54 ( struct V_87 * V_88 , struct V_2 * V_3 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
F_55 ( V_111 , F_49 ( V_109 , V_9 -> V_110 ) ) ;
F_56 ( & V_9 -> V_31 ) ;
F_33 ( V_9 -> V_44 ) ;
F_57 ( V_9 -> V_44 , V_9 -> V_27 ) ;
F_11 ( V_9 -> V_27 -> V_38 ) ;
F_52 ( V_9 -> V_44 , V_9 -> V_27 ) ;
F_53 ( V_3 -> V_106 ) ;
F_53 ( V_3 -> V_103 ) ;
F_11 ( V_9 -> V_80 ) ;
F_11 ( V_9 -> V_22 ) ;
F_11 ( V_9 ) ;
}
int T_7 F_58 ( struct V_87 * V_88 ,
struct V_112 * V_113 , int V_114 )
{
struct V_1 * V_9 ;
int V_29 ;
if ( V_114 >= V_115 )
return - V_116 ;
if ( V_117 [ V_118 ] . V_119 == 0 ) {
V_29 = F_59 ( V_88 -> V_31 ) ;
if ( V_29 < 0 )
return V_29 ;
V_117 [ V_118 ] . V_119 = V_29 ;
V_90 . V_120 = V_29 ;
}
V_9 = F_60 ( sizeof *V_9 , V_94 ) ;
if ( ! V_9 )
return - V_23 ;
V_9 -> V_110 = V_114 ;
V_9 -> V_95 = V_113 -> V_121 ;
V_9 -> V_96 = V_113 -> V_122 ;
V_9 -> V_37 = V_113 -> V_37 ;
V_9 -> V_102 = V_113 -> V_102 ;
V_9 -> V_80 = F_61 ( V_113 -> V_80 ,
V_113 -> V_102 ,
V_94 ) ;
if ( ! V_9 -> V_80 ) {
F_11 ( V_9 ) ;
return - V_23 ;
}
V_9 -> V_4 . V_123 = L_22 ;
V_9 -> V_4 . V_124 = V_125 ;
V_9 -> V_4 . V_126 = F_37 ;
V_9 -> V_4 . V_127 = F_54 ;
V_9 -> V_4 . V_128 = F_34 ;
V_9 -> V_4 . V_129 = F_32 ;
V_9 -> V_4 . V_130 = F_29 ;
V_29 = F_62 ( V_88 , & V_9 -> V_4 ) ;
if ( V_29 )
F_11 ( V_9 ) ;
return V_29 ;
}
int T_7 F_63 ( struct V_131 * V_132 , int V_7 )
{
int V_29 ;
T_8 V_89 ;
V_111 = F_64 ( V_133 , L_20 ) ;
V_29 = F_65 ( & V_89 , 0 , V_7 , L_20 ) ;
if ( ! V_29 ) {
V_109 = F_66 ( V_89 ) ;
V_115 = V_7 ;
}
return V_29 ;
}
void F_67 ( void )
{
if ( V_109 ) {
F_68 ( F_49 ( V_109 , 0 ) , V_115 ) ;
V_109 = V_115 = 0 ;
}
F_69 ( V_111 ) ;
V_111 = NULL ;
}
