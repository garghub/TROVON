static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static T_1 F_3 ( struct V_5 * V_5 , char T_2 * V_6 ,
T_3 V_7 , T_4 * V_8 )
{
struct V_1 * V_9 = V_5 -> V_10 ;
struct V_11 * V_12 ;
struct V_13 * V_14 ;
unsigned long V_15 ;
int V_16 ;
if ( ! V_7 )
return 0 ;
if ( ! F_4 ( V_17 , V_6 , V_7 ) )
return - V_18 ;
F_5 ( & V_9 -> V_19 , V_15 ) ;
#define F_6 (!list_empty(&hidg->completed_out_req))
while ( ! F_6 ) {
F_7 ( & V_9 -> V_19 , V_15 ) ;
if ( V_5 -> V_20 & V_21 )
return - V_22 ;
if ( F_8 ( V_9 -> V_23 , F_6 ) )
return - V_24 ;
F_5 ( & V_9 -> V_19 , V_15 ) ;
}
V_12 = F_9 ( & V_9 -> V_25 ,
struct V_11 , V_12 ) ;
V_14 = V_12 -> V_14 ;
V_7 = F_10 (unsigned int, count, req->actual - list->pos) ;
F_7 ( & V_9 -> V_19 , V_15 ) ;
V_7 -= F_11 ( V_6 , V_14 -> V_26 + V_12 -> V_27 , V_7 ) ;
V_12 -> V_27 += V_7 ;
if ( V_12 -> V_27 == V_14 -> V_28 ) {
F_5 ( & V_9 -> V_19 , V_15 ) ;
F_12 ( & V_12 -> V_12 ) ;
F_13 ( V_12 ) ;
F_7 ( & V_9 -> V_19 , V_15 ) ;
V_14 -> V_29 = V_9 -> V_30 ;
V_16 = F_14 ( V_9 -> V_31 , V_14 , V_32 ) ;
if ( V_16 < 0 )
return V_16 ;
}
return V_7 ;
}
static void F_15 ( struct V_33 * V_34 , struct V_13 * V_14 )
{
struct V_1 * V_9 = (struct V_1 * ) V_34 -> V_35 ;
if ( V_14 -> V_36 != 0 ) {
ERROR ( V_9 -> V_4 . V_37 -> V_38 ,
L_1 , V_14 -> V_36 ) ;
}
V_9 -> V_39 = 0 ;
F_16 ( & V_9 -> V_40 ) ;
}
static T_1 F_17 ( struct V_5 * V_5 , const char T_2 * V_6 ,
T_3 V_7 , T_4 * V_41 )
{
struct V_1 * V_9 = V_5 -> V_10 ;
T_1 V_36 = - V_42 ;
if ( ! F_4 ( V_43 , V_6 , V_7 ) )
return - V_18 ;
F_18 ( & V_9 -> V_44 ) ;
#define F_19 (!hidg->write_pending)
while ( ! F_19 ) {
F_20 ( & V_9 -> V_44 ) ;
if ( V_5 -> V_20 & V_21 )
return - V_22 ;
if ( F_21 (
V_9 -> V_40 , F_19 ) )
return - V_24 ;
F_18 ( & V_9 -> V_44 ) ;
}
V_7 = F_10 ( unsigned , V_7 , V_9 -> V_30 ) ;
V_36 = F_22 ( V_9 -> V_14 -> V_26 , V_6 , V_7 ) ;
if ( V_36 != 0 ) {
ERROR ( V_9 -> V_4 . V_37 -> V_38 ,
L_2 ) ;
F_20 ( & V_9 -> V_44 ) ;
return - V_45 ;
}
V_9 -> V_14 -> V_36 = 0 ;
V_9 -> V_14 -> V_46 = 0 ;
V_9 -> V_14 -> V_29 = V_7 ;
V_9 -> V_14 -> V_47 = F_15 ;
V_9 -> V_14 -> V_48 = V_9 ;
V_9 -> V_39 = 1 ;
V_36 = F_14 ( V_9 -> V_49 , V_9 -> V_14 , V_50 ) ;
if ( V_36 < 0 ) {
ERROR ( V_9 -> V_4 . V_37 -> V_38 ,
L_3 , V_36 ) ;
V_9 -> V_39 = 0 ;
F_16 ( & V_9 -> V_40 ) ;
} else {
V_36 = V_7 ;
}
F_20 ( & V_9 -> V_44 ) ;
return V_36 ;
}
static unsigned int F_23 ( struct V_5 * V_5 , T_5 * V_51 )
{
struct V_1 * V_9 = V_5 -> V_10 ;
unsigned int V_16 = 0 ;
F_24 ( V_5 , & V_9 -> V_23 , V_51 ) ;
F_24 ( V_5 , & V_9 -> V_40 , V_51 ) ;
if ( F_19 )
V_16 |= V_52 | V_53 ;
if ( F_6 )
V_16 |= V_54 | V_55 ;
return V_16 ;
}
static int F_25 ( struct V_56 * V_56 , struct V_5 * V_57 )
{
V_57 -> V_10 = NULL ;
return 0 ;
}
static int F_26 ( struct V_56 * V_56 , struct V_5 * V_57 )
{
struct V_1 * V_9 =
F_2 ( V_56 -> V_58 , struct V_1 , V_38 ) ;
V_57 -> V_10 = V_9 ;
return 0 ;
}
static struct V_13 * F_27 ( struct V_33 * V_34 , unsigned V_29 )
{
struct V_13 * V_14 ;
V_14 = F_28 ( V_34 , V_50 ) ;
if ( V_14 ) {
V_14 -> V_29 = V_29 ;
V_14 -> V_26 = F_29 ( V_29 , V_50 ) ;
if ( ! V_14 -> V_26 ) {
F_30 ( V_34 , V_14 ) ;
V_14 = NULL ;
}
}
return V_14 ;
}
static void F_31 ( struct V_33 * V_34 , struct V_13 * V_14 )
{
struct V_1 * V_9 = (struct V_1 * ) V_14 -> V_48 ;
struct V_11 * V_59 ;
unsigned long V_15 ;
V_59 = F_32 ( sizeof( * V_59 ) , V_50 ) ;
if ( ! V_59 )
return;
V_59 -> V_14 = V_14 ;
F_5 ( & V_9 -> V_19 , V_15 ) ;
F_33 ( & V_59 -> V_12 , & V_9 -> V_25 ) ;
F_7 ( & V_9 -> V_19 , V_15 ) ;
F_16 ( & V_9 -> V_23 ) ;
}
static int F_34 ( struct V_2 * V_3 ,
const struct V_60 * V_61 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
struct V_62 * V_38 = V_3 -> V_37 -> V_38 ;
struct V_13 * V_14 = V_38 -> V_14 ;
int V_36 = 0 ;
T_6 V_63 , V_29 ;
V_63 = F_35 ( V_61 -> V_64 ) ;
V_29 = F_35 ( V_61 -> V_65 ) ;
F_36 ( V_38 , L_4
L_5 , V_61 -> V_66 , V_61 -> V_67 , V_63 ) ;
switch ( ( V_61 -> V_66 << 8 ) | V_61 -> V_67 ) {
case ( ( V_68 | V_69 | V_70 ) << 8
| V_71 ) :
F_36 ( V_38 , L_6 ) ;
V_29 = F_10 ( unsigned , V_29 , V_9 -> V_30 ) ;
memset ( V_14 -> V_26 , 0x0 , V_29 ) ;
goto V_72;
break;
case ( ( V_68 | V_69 | V_70 ) << 8
| V_73 ) :
F_36 ( V_38 , L_7 ) ;
goto V_74;
break;
case ( ( V_75 | V_69 | V_70 ) << 8
| V_76 ) :
F_36 ( V_38 , L_8 , V_61 -> V_65 ) ;
goto V_74;
break;
case ( ( V_75 | V_69 | V_70 ) << 8
| V_77 ) :
F_36 ( V_38 , L_9 ) ;
goto V_74;
break;
case ( ( V_68 | V_78 | V_70 ) << 8
| V_79 ) :
switch ( V_63 >> 8 ) {
case V_80 :
F_36 ( V_38 , L_10 ) ;
V_29 = F_10 (unsigned short, length,
hidg_desc.bLength) ;
memcpy ( V_14 -> V_26 , & V_81 , V_29 ) ;
goto V_72;
break;
case V_82 :
F_36 ( V_38 , L_11 ) ;
V_29 = F_10 (unsigned short, length,
hidg->report_desc_length) ;
memcpy ( V_14 -> V_26 , V_9 -> V_83 , V_29 ) ;
goto V_72;
break;
default:
F_36 ( V_38 , L_12 ,
V_63 >> 8 ) ;
goto V_74;
break;
}
break;
default:
F_36 ( V_38 , L_13 ,
V_61 -> V_67 ) ;
goto V_74;
break;
}
V_74:
return - V_84 ;
V_72:
V_14 -> V_46 = 0 ;
V_14 -> V_29 = V_29 ;
V_36 = F_14 ( V_38 -> V_85 -> V_86 , V_14 , V_50 ) ;
if ( V_36 < 0 )
ERROR ( V_38 , L_14 , V_63 ) ;
return V_36 ;
}
static void F_37 ( struct V_2 * V_3 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
struct V_11 * V_12 , * V_87 ;
F_38 ( V_9 -> V_49 ) ;
V_9 -> V_49 -> V_35 = NULL ;
F_38 ( V_9 -> V_31 ) ;
V_9 -> V_31 -> V_35 = NULL ;
F_39 (list, next, &hidg->completed_out_req, list) {
F_12 ( & V_12 -> V_12 ) ;
F_13 ( V_12 ) ;
}
}
static int F_40 ( struct V_2 * V_3 , unsigned V_88 , unsigned V_89 )
{
struct V_62 * V_38 = V_3 -> V_37 -> V_38 ;
struct V_1 * V_9 = F_1 ( V_3 ) ;
int V_90 , V_36 = 0 ;
F_36 ( V_38 , L_15 , V_88 , V_89 ) ;
if ( V_9 -> V_49 != NULL ) {
if ( V_9 -> V_49 -> V_35 != NULL )
F_38 ( V_9 -> V_49 ) ;
V_36 = F_41 ( V_3 -> V_37 -> V_38 -> V_85 , V_3 ,
V_9 -> V_49 ) ;
if ( V_36 ) {
ERROR ( V_38 , L_16 ) ;
goto V_91;
}
V_36 = F_42 ( V_9 -> V_49 ) ;
if ( V_36 < 0 ) {
ERROR ( V_38 , L_17 ) ;
goto V_91;
}
V_9 -> V_49 -> V_35 = V_9 ;
}
if ( V_9 -> V_31 != NULL ) {
if ( V_9 -> V_31 -> V_35 != NULL )
F_38 ( V_9 -> V_31 ) ;
V_36 = F_41 ( V_3 -> V_37 -> V_38 -> V_85 , V_3 ,
V_9 -> V_31 ) ;
if ( V_36 ) {
ERROR ( V_38 , L_16 ) ;
goto V_91;
}
V_36 = F_42 ( V_9 -> V_31 ) ;
if ( V_36 < 0 ) {
ERROR ( V_38 , L_17 ) ;
goto V_91;
}
V_9 -> V_31 -> V_35 = V_9 ;
for ( V_90 = 0 ; V_90 < V_9 -> V_92 && V_36 == 0 ; V_90 ++ ) {
struct V_13 * V_14 =
F_27 ( V_9 -> V_31 ,
V_9 -> V_30 ) ;
if ( V_14 ) {
V_14 -> V_47 = F_31 ;
V_14 -> V_48 = V_9 ;
V_36 = F_14 ( V_9 -> V_31 , V_14 ,
V_50 ) ;
if ( V_36 )
ERROR ( V_38 , L_18 ,
V_9 -> V_31 -> V_93 , V_36 ) ;
} else {
F_38 ( V_9 -> V_31 ) ;
V_9 -> V_31 -> V_35 = NULL ;
V_36 = - V_42 ;
goto V_91;
}
}
}
V_91:
return V_36 ;
}
static int T_7 F_43 ( struct V_94 * V_95 , struct V_2 * V_3 )
{
struct V_33 * V_34 ;
struct V_1 * V_9 = F_1 ( V_3 ) ;
int V_36 ;
T_8 V_96 ;
V_36 = F_44 ( V_95 , V_3 ) ;
if ( V_36 < 0 )
goto V_91;
V_97 . V_98 = V_36 ;
V_36 = - V_99 ;
V_34 = F_45 ( V_95 -> V_38 -> V_85 , & V_100 ) ;
if ( ! V_34 )
goto V_91;
V_34 -> V_35 = V_95 -> V_38 ;
V_9 -> V_49 = V_34 ;
V_34 = F_45 ( V_95 -> V_38 -> V_85 , & V_101 ) ;
if ( ! V_34 )
goto V_91;
V_34 -> V_35 = V_95 -> V_38 ;
V_9 -> V_31 = V_34 ;
V_36 = - V_42 ;
V_9 -> V_14 = F_28 ( V_9 -> V_49 , V_32 ) ;
if ( ! V_9 -> V_14 )
goto V_91;
V_9 -> V_14 -> V_26 = F_29 ( V_9 -> V_30 , V_32 ) ;
if ( ! V_9 -> V_14 -> V_26 )
goto V_91;
V_97 . V_102 = V_9 -> V_102 ;
V_97 . V_103 = V_9 -> V_103 ;
V_104 . V_105 = F_46 ( V_9 -> V_30 ) ;
V_100 . V_105 = F_46 ( V_9 -> V_30 ) ;
V_106 . V_105 = F_46 ( V_9 -> V_30 ) ;
V_101 . V_105 = F_46 ( V_9 -> V_30 ) ;
V_81 . V_107 [ 0 ] . V_108 = V_82 ;
V_81 . V_107 [ 0 ] . V_109 =
F_46 ( V_9 -> V_110 ) ;
V_3 -> V_111 = F_47 ( V_112 ) ;
if ( ! V_3 -> V_111 )
goto V_91;
if ( F_48 ( V_95 -> V_38 -> V_85 ) ) {
V_104 . V_113 =
V_100 . V_113 ;
V_106 . V_113 =
V_101 . V_113 ;
V_3 -> V_114 = F_47 ( V_115 ) ;
if ( ! V_3 -> V_114 )
goto V_91;
}
F_49 ( & V_9 -> V_44 ) ;
F_50 ( & V_9 -> V_19 ) ;
F_51 ( & V_9 -> V_40 ) ;
F_51 ( & V_9 -> V_23 ) ;
F_52 ( & V_9 -> V_25 ) ;
F_53 ( & V_9 -> V_38 , & V_116 ) ;
V_96 = F_54 ( V_117 , V_9 -> V_118 ) ;
V_36 = F_55 ( & V_9 -> V_38 , V_96 , 1 ) ;
if ( V_36 )
goto V_91;
F_56 ( V_119 , NULL , V_96 , NULL , L_19 , L_20 , V_9 -> V_118 ) ;
return 0 ;
V_91:
ERROR ( V_3 -> V_37 -> V_38 , L_21 ) ;
if ( V_9 -> V_14 != NULL ) {
F_13 ( V_9 -> V_14 -> V_26 ) ;
if ( V_9 -> V_49 != NULL )
F_30 ( V_9 -> V_49 , V_9 -> V_14 ) ;
}
F_57 ( V_3 -> V_114 ) ;
F_57 ( V_3 -> V_111 ) ;
return V_36 ;
}
static void F_58 ( struct V_94 * V_95 , struct V_2 * V_3 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
F_59 ( V_119 , F_54 ( V_117 , V_9 -> V_118 ) ) ;
F_60 ( & V_9 -> V_38 ) ;
F_38 ( V_9 -> V_49 ) ;
F_61 ( V_9 -> V_49 , V_9 -> V_14 ) ;
F_13 ( V_9 -> V_14 -> V_26 ) ;
F_30 ( V_9 -> V_49 , V_9 -> V_14 ) ;
F_57 ( V_3 -> V_114 ) ;
F_57 ( V_3 -> V_111 ) ;
F_13 ( V_9 -> V_83 ) ;
F_13 ( V_9 ) ;
}
int T_7 F_62 ( struct V_94 * V_95 ,
struct V_120 * V_121 , int V_122 )
{
struct V_1 * V_9 ;
int V_36 ;
if ( V_122 >= V_123 )
return - V_124 ;
if ( V_125 [ V_126 ] . V_127 == 0 ) {
V_36 = F_63 ( V_95 -> V_38 ) ;
if ( V_36 < 0 )
return V_36 ;
V_125 [ V_126 ] . V_127 = V_36 ;
V_97 . V_128 = V_36 ;
}
V_9 = F_32 ( sizeof *V_9 , V_32 ) ;
if ( ! V_9 )
return - V_42 ;
V_9 -> V_118 = V_122 ;
V_9 -> V_102 = V_121 -> V_129 ;
V_9 -> V_103 = V_121 -> V_130 ;
V_9 -> V_30 = V_121 -> V_30 ;
V_9 -> V_110 = V_121 -> V_110 ;
V_9 -> V_83 = F_64 ( V_121 -> V_83 ,
V_121 -> V_110 ,
V_32 ) ;
if ( ! V_9 -> V_83 ) {
F_13 ( V_9 ) ;
return - V_42 ;
}
V_9 -> V_4 . V_93 = L_22 ;
V_9 -> V_4 . V_131 = V_132 ;
V_9 -> V_4 . V_133 = F_43 ;
V_9 -> V_4 . V_134 = F_58 ;
V_9 -> V_4 . V_135 = F_40 ;
V_9 -> V_4 . V_136 = F_37 ;
V_9 -> V_4 . V_137 = F_34 ;
V_9 -> V_92 = 4 ;
V_36 = F_65 ( V_95 , & V_9 -> V_4 ) ;
if ( V_36 )
F_13 ( V_9 ) ;
return V_36 ;
}
int T_7 F_66 ( struct V_138 * V_139 , int V_7 )
{
int V_36 ;
T_8 V_96 ;
V_119 = F_67 ( V_140 , L_20 ) ;
V_36 = F_68 ( & V_96 , 0 , V_7 , L_20 ) ;
if ( ! V_36 ) {
V_117 = F_69 ( V_96 ) ;
V_123 = V_7 ;
}
return V_36 ;
}
void F_70 ( void )
{
if ( V_117 ) {
F_71 ( F_54 ( V_117 , 0 ) , V_123 ) ;
V_117 = V_123 = 0 ;
}
F_72 ( V_119 ) ;
V_119 = NULL ;
}
