static void F_1 ( const struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
F_2 ( V_3 , V_2 -> V_5 + V_4 ) ;
}
static void F_3 ( const struct V_1 * V_2 , T_2 V_3 , T_2 V_4 )
{
F_4 ( V_3 , V_2 -> V_5 + V_4 ) ;
}
static void F_5 ( const struct V_1 * V_2 , T_3 V_3 , T_2 V_4 )
{
F_6 ( V_3 , V_2 -> V_5 + V_4 ) ;
}
static T_1 F_7 ( const struct V_1 * V_2 , T_2 V_4 )
{
return F_8 ( V_2 -> V_5 + V_4 ) ;
}
static T_2 F_9 ( const struct V_1 * V_2 , T_2 V_4 )
{
return F_10 ( V_2 -> V_5 + V_4 ) ;
}
static int F_11 ( const struct V_1 * V_2 ,
int V_6 )
{
int V_7 ;
F_1 ( V_2 , 0x00 , V_8 ) ;
V_7 = F_12 ( V_2 -> V_9 ) / ( 2 * V_2 -> V_10 ) - 1 ;
F_1 ( V_2 , F_13 ( V_7 , 0 , 255 ) , V_11 ) ;
F_1 ( V_2 , 0x00 , V_12 ) ;
F_1 ( V_2 , 0x00 , V_13 ) ;
F_1 ( V_2 , 0x00 , V_14 ) ;
F_1 ( V_2 , 0x00 , V_15 ) ;
F_1 ( V_2 , 0x00 , V_16 ) ;
F_3 ( V_2 , F_14 ( V_6 ) | V_2 -> V_17 ,
V_18 ) ;
F_1 ( V_2 , V_19 , V_20 ) ;
return 0 ;
}
static int F_15 ( const struct V_1 * V_2 ,
int V_6 )
{
T_2 V_17 ;
int V_7 ;
F_1 ( V_2 , 0x00 , V_8 ) ;
V_7 = F_12 ( V_2 -> V_9 ) / ( 2 * V_2 -> V_10 ) ;
F_1 ( V_2 , F_13 ( V_7 , 0 , 255 ) , V_11 ) ;
F_1 ( V_2 , 0x00 , V_12 ) ;
F_1 ( V_2 , 0x00 , V_13 ) ;
F_1 ( V_2 , 0x00 , V_14 ) ;
F_1 ( V_2 , 0x00 , V_15 ) ;
if ( V_6 == 8 )
V_17 = V_21 ;
else if ( V_6 == 16 )
V_17 = V_22 ;
else
V_17 = V_23 ;
V_17 |= V_24 | V_25 | V_2 -> V_17 | V_26 ;
F_5 ( V_2 , 0 , V_27 ) ;
F_1 ( V_2 , V_28 | V_29 , V_30 ) ;
F_1 ( V_2 , 0x00 , V_30 ) ;
F_3 ( V_2 , V_17 , V_18 ) ;
F_1 ( V_2 , V_31 | V_19 , V_20 ) ;
return 0 ;
}
static void F_16 ( const struct V_1 * V_2 , T_1 V_32 )
{
F_1 ( V_2 , F_7 ( V_2 , V_20 ) | V_32 , V_20 ) ;
}
static void F_17 ( const struct V_1 * V_2 , T_1 V_33 )
{
F_1 ( V_2 , F_7 ( V_2 , V_20 ) & ~ V_33 , V_20 ) ;
}
static int F_18 ( struct V_1 * V_2 , T_1 V_34 ,
T_1 V_35 )
{
int V_36 ;
V_2 -> V_37 = F_7 ( V_2 , V_38 ) ;
F_16 ( V_2 , V_35 ) ;
V_36 = F_19 ( V_2 -> V_39 , V_2 -> V_37 & V_34 , V_40 ) ;
if ( V_36 == 0 && ! ( V_2 -> V_37 & V_34 ) )
return - V_41 ;
return 0 ;
}
static void F_20 ( const struct V_1 * V_2 )
{
F_1 ( V_2 , F_7 ( V_2 , V_20 ) | V_31 , V_20 ) ;
}
static void F_21 ( const struct V_1 * V_2 )
{
F_1 ( V_2 , F_7 ( V_2 , V_20 ) & ~ V_31 , V_20 ) ;
}
static int F_22 ( struct V_1 * V_2 , struct V_42 * V_43 ,
struct V_44 * V_45 )
{
int V_46 = V_45 -> V_47 ;
const T_1 * V_3 = V_45 -> V_48 ;
while ( V_46 > 0 ) {
F_1 ( V_2 , F_7 ( V_2 , V_20 ) | V_49 ,
V_20 ) ;
if ( F_18 ( V_2 , V_50 , V_51 ) < 0 ) {
F_23 ( & V_2 -> V_52 -> V_53 ,
L_1 , V_54 ) ;
return - V_41 ;
}
F_3 ( V_2 , * V_3 , V_55 ) ;
V_3 ++ ;
V_46 -- ;
}
F_18 ( V_2 , V_50 , V_51 ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 , struct V_42 * V_43 ,
struct V_44 * V_45 )
{
int V_46 = V_45 -> V_47 ;
const T_1 * V_3 = V_45 -> V_48 ;
F_1 ( V_2 , V_28 , V_30 ) ;
F_1 ( V_2 , 0x00 , V_30 ) ;
while ( V_46 > 0 ) {
if ( F_18 ( V_2 , V_50 , V_51 ) < 0 ) {
F_23 ( & V_2 -> V_52 -> V_53 ,
L_1 , V_54 ) ;
return - V_41 ;
}
F_1 ( V_2 , * V_3 ++ , V_55 ) ;
if ( F_18 ( V_2 , V_56 , V_57 ) < 0 ) {
F_23 ( & V_2 -> V_52 -> V_53 ,
L_2 , V_54 ) ;
return - V_41 ;
}
F_7 ( V_2 , V_55 ) ;
V_46 -- ;
}
F_18 ( V_2 , V_50 , V_51 ) ;
return 0 ;
}
static void F_25 ( void * V_58 )
{
struct V_1 * V_2 = V_58 ;
V_2 -> V_59 = 1 ;
F_26 ( & V_2 -> V_39 ) ;
}
static int F_27 ( struct V_60 * V_61 , const void * V_62 ,
unsigned V_47 , struct V_63 * V_64 ,
enum V_65 V_66 )
{
F_28 ( V_61 , 1 ) ;
F_29 ( V_61 , V_62 , V_47 ) ;
F_30 ( V_61 ) = V_47 ;
return F_31 ( V_64 -> V_67 -> V_53 , V_61 , 1 , V_66 ) ;
}
static void F_32 ( struct V_60 * V_61 , struct V_63 * V_64 ,
enum V_65 V_66 )
{
F_33 ( V_64 -> V_67 -> V_53 , V_61 , 1 , V_66 ) ;
}
static void F_34 ( void * V_62 , const void * V_3 , unsigned V_47 )
{
T_2 * V_68 = V_62 ;
const T_1 * V_69 = V_3 ;
while ( V_47 ) {
* V_68 ++ = ( T_2 ) ( * V_69 ++ ) ;
V_47 -- ;
}
}
static void F_35 ( void * V_62 , const void * V_3 , unsigned V_47 )
{
T_1 * V_68 = V_62 ;
const T_2 * V_69 = V_3 ;
while ( V_47 ) {
* V_68 ++ = ( T_1 ) * V_69 ++ ;
V_47 -- ;
}
}
static int F_36 ( struct V_1 * V_2 , struct V_44 * V_45 )
{
struct V_60 V_61 ;
const void * V_62 = NULL ;
struct V_70 * V_71 ;
unsigned V_47 ;
int V_36 = 0 ;
if ( V_2 -> V_72 ) {
void * V_73 ;
V_47 = V_45 -> V_47 * 2 ;
V_73 = F_37 ( V_47 , V_74 ) ;
if ( ! V_73 )
return - V_75 ;
F_34 ( V_73 , V_45 -> V_48 , V_45 -> V_47 ) ;
V_62 = V_73 ;
} else {
V_47 = V_45 -> V_47 ;
V_62 = V_45 -> V_48 ;
}
if ( ! F_27 ( & V_61 , V_62 , V_47 , V_2 -> V_76 , V_77 ) ) {
V_36 = - V_78 ;
goto V_79;
}
V_71 = F_38 ( V_2 -> V_76 , & V_61 , 1 , V_77 ,
V_80 | V_81 ) ;
if ( ! V_71 ) {
V_36 = - V_82 ;
goto V_83;
}
F_39 ( V_2 -> V_84 ) ;
F_1 ( V_2 , F_7 ( V_2 , V_20 ) | V_49 , V_20 ) ;
F_16 ( V_2 , V_51 ) ;
V_2 -> V_59 = 0 ;
V_71 -> V_85 = F_25 ;
V_71 -> V_86 = V_2 ;
F_40 ( V_71 ) ;
F_41 ( V_2 -> V_76 ) ;
V_36 = F_42 ( V_2 -> V_39 ,
V_2 -> V_59 , V_40 ) ;
if ( V_36 > 0 && V_2 -> V_59 )
V_36 = 0 ;
else if ( ! V_36 )
V_36 = - V_41 ;
F_17 ( V_2 , V_51 ) ;
F_43 ( V_2 -> V_84 ) ;
V_83:
F_32 ( & V_61 , V_2 -> V_76 , V_77 ) ;
V_79:
if ( V_2 -> V_72 )
F_44 ( V_62 ) ;
return V_36 ;
}
static void F_45 ( const struct V_1 * V_2 )
{
T_1 V_37 ;
V_37 = F_7 ( V_2 , V_38 ) ;
if ( V_37 & V_56 )
F_9 ( V_2 , V_55 ) ;
if ( V_37 & V_87 )
F_1 ( V_2 , F_7 ( V_2 , V_38 ) & ~ V_87 ,
V_38 ) ;
}
static int F_46 ( struct V_1 * V_2 , struct V_42 * V_43 ,
struct V_44 * V_45 )
{
int V_46 = V_45 -> V_47 ;
T_1 * V_3 ;
F_45 ( V_2 ) ;
V_3 = V_45 -> V_88 ;
while ( V_46 > 0 ) {
F_1 ( V_2 , F_7 ( V_2 , V_20 ) & ~ V_49 ,
V_20 ) ;
if ( F_18 ( V_2 , V_50 , V_51 ) < 0 ) {
F_23 ( & V_2 -> V_52 -> V_53 ,
L_1 , V_54 ) ;
return - V_41 ;
}
F_3 ( V_2 , V_89 , V_55 ) ;
if ( F_18 ( V_2 , V_56 , V_57 ) < 0 ) {
F_23 ( & V_2 -> V_52 -> V_53 ,
L_2 , V_54 ) ;
return - V_41 ;
}
* V_3 = ( T_1 ) F_9 ( V_2 , V_55 ) ;
V_3 ++ ;
V_46 -- ;
}
return 0 ;
}
static void F_47 ( const struct V_1 * V_2 )
{
T_1 V_37 ;
V_37 = F_7 ( V_2 , V_38 ) ;
if ( V_37 & V_56 )
F_7 ( V_2 , V_55 ) ;
F_1 ( V_2 , V_28 | V_29 , V_30 ) ;
F_1 ( V_2 , 0x00 , V_30 ) ;
}
static int F_48 ( struct V_1 * V_2 , struct V_42 * V_43 ,
struct V_44 * V_45 )
{
int V_46 = V_45 -> V_47 ;
T_1 * V_3 ;
F_47 ( V_2 ) ;
V_3 = V_45 -> V_88 ;
while ( V_46 > 0 ) {
if ( F_18 ( V_2 , V_50 , V_51 ) < 0 ) {
F_23 ( & V_2 -> V_52 -> V_53 ,
L_1 , V_54 ) ;
return - V_41 ;
}
F_1 ( V_2 , V_89 , V_55 ) ;
if ( F_18 ( V_2 , V_56 , V_57 ) < 0 ) {
F_23 ( & V_2 -> V_52 -> V_53 ,
L_2 , V_54 ) ;
return - V_41 ;
}
* V_3 ++ = F_7 ( V_2 , V_55 ) ;
V_46 -- ;
}
return 0 ;
}
static int F_49 ( struct V_1 * V_2 , struct V_44 * V_45 )
{
struct V_60 V_61 , V_90 ;
void * V_91 = NULL , * V_88 = NULL ;
struct V_70 * V_71 , * V_92 ;
unsigned V_47 ;
int V_36 = 0 ;
if ( V_2 -> V_72 ) {
V_47 = V_45 -> V_47 * 2 ;
V_88 = F_37 ( V_47 , V_74 ) ;
if ( ! V_88 )
return - V_75 ;
} else {
V_47 = V_45 -> V_47 ;
V_88 = V_45 -> V_88 ;
}
V_91 = F_50 ( V_47 , V_74 ) ;
if ( ! V_91 ) {
V_36 = - V_75 ;
goto V_79;
}
if ( ! F_27 ( & V_90 , V_91 , V_47 , V_2 -> V_76 ,
V_77 ) ) {
V_36 = - V_78 ;
goto V_79;
}
V_92 = F_38 ( V_2 -> V_76 , & V_90 , 1 ,
V_77 , V_80 | V_81 ) ;
if ( ! V_92 ) {
V_36 = - V_82 ;
goto V_93;
}
if ( ! F_27 ( & V_61 , V_88 , V_47 , V_2 -> V_94 ,
V_95 ) ) {
V_36 = - V_78 ;
goto V_93;
}
V_71 = F_38 ( V_2 -> V_94 , & V_61 , 1 , V_95 ,
V_80 | V_81 ) ;
if ( ! V_71 ) {
V_36 = - V_82 ;
goto V_83;
}
F_45 ( V_2 ) ;
F_39 ( V_2 -> V_84 ) ;
F_1 ( V_2 , F_7 ( V_2 , V_20 ) & ~ V_49 , V_20 ) ;
F_16 ( V_2 , V_51 | V_57 ) ;
V_2 -> V_59 = 0 ;
V_71 -> V_85 = F_25 ;
V_71 -> V_86 = V_2 ;
F_40 ( V_71 ) ;
F_41 ( V_2 -> V_94 ) ;
V_92 -> V_85 = NULL ;
F_40 ( V_92 ) ;
F_41 ( V_2 -> V_76 ) ;
V_36 = F_42 ( V_2 -> V_39 ,
V_2 -> V_59 , V_40 ) ;
if ( V_36 > 0 && V_2 -> V_59 )
V_36 = 0 ;
else if ( ! V_36 )
V_36 = - V_41 ;
F_17 ( V_2 , V_51 | V_57 ) ;
F_43 ( V_2 -> V_84 ) ;
V_83:
F_32 ( & V_61 , V_2 -> V_94 , V_95 ) ;
V_93:
F_32 ( & V_90 , V_2 -> V_76 , V_77 ) ;
V_79:
if ( V_2 -> V_72 ) {
if ( ! V_36 )
F_35 ( V_45 -> V_88 , V_88 , V_45 -> V_47 ) ;
F_44 ( V_88 ) ;
}
F_44 ( V_91 ) ;
return V_36 ;
}
static int F_51 ( const struct V_1 * V_2 , struct V_44 * V_45 )
{
if ( V_45 -> V_48 && V_2 -> V_76 )
return 1 ;
if ( V_45 -> V_88 && V_2 -> V_76 && V_2 -> V_94 )
return 1 ;
return 0 ;
}
static void F_52 ( struct V_96 * V_97 )
{
struct V_1 * V_2 = F_53 ( V_97 , struct V_1 , V_98 ) ;
struct V_42 * V_43 ;
struct V_44 * V_45 ;
unsigned long V_99 ;
int V_36 ;
while ( 1 ) {
F_54 ( & V_2 -> V_100 , V_99 ) ;
if ( F_55 ( & V_2 -> V_101 ) ) {
F_56 ( & V_2 -> V_100 , V_99 ) ;
break;
}
V_43 = F_57 ( V_2 -> V_101 . V_102 , struct V_42 , V_101 ) ;
F_58 ( & V_43 -> V_101 ) ;
F_56 ( & V_2 -> V_100 , V_99 ) ;
F_20 ( V_2 ) ;
F_59 (t, &mesg->transfers, transfer_list) {
if ( V_45 -> V_48 ) {
if ( F_51 ( V_2 , V_45 ) )
V_36 = F_36 ( V_2 , V_45 ) ;
else
V_36 = F_60 ( V_2 , V_43 , V_45 ) ;
if ( V_36 < 0 )
goto error;
}
if ( V_45 -> V_88 ) {
if ( F_51 ( V_2 , V_45 ) )
V_36 = F_49 ( V_2 , V_45 ) ;
else
V_36 = F_61 ( V_2 , V_43 , V_45 ) ;
if ( V_36 < 0 )
goto error;
}
V_43 -> V_103 += V_45 -> V_47 ;
}
F_21 ( V_2 ) ;
V_43 -> V_104 = 0 ;
V_43 -> V_105 ( V_43 -> V_106 ) ;
}
return;
error:
V_43 -> V_104 = V_36 ;
V_43 -> V_105 ( V_43 -> V_106 ) ;
}
static int F_62 ( struct V_107 * V_108 )
{
struct V_1 * V_2 = F_63 ( V_108 -> V_52 ) ;
V_2 -> V_10 = V_108 -> V_10 ;
V_2 -> V_17 = V_109 ;
if ( V_108 -> V_110 & V_111 )
V_2 -> V_17 |= V_112 ;
if ( V_108 -> V_110 & V_113 )
V_2 -> V_17 |= V_114 ;
F_64 ( V_2 , 8 ) ;
return 0 ;
}
static int F_65 ( struct V_107 * V_108 , struct V_42 * V_43 )
{
struct V_1 * V_2 = F_63 ( V_108 -> V_52 ) ;
unsigned long V_99 ;
V_43 -> V_103 = 0 ;
V_43 -> V_104 = - V_115 ;
F_54 ( & V_2 -> V_100 , V_99 ) ;
F_66 ( & V_43 -> V_101 , & V_2 -> V_101 ) ;
F_67 ( & V_2 -> V_98 ) ;
F_56 ( & V_2 -> V_100 , V_99 ) ;
return 0 ;
}
static void F_68 ( struct V_107 * V_108 )
{
}
static T_4 F_69 ( int V_84 , void * V_116 )
{
struct V_1 * V_2 = V_116 ;
T_1 V_37 ;
T_4 V_36 = V_117 ;
T_1 F_39 = 0 ;
V_2 -> V_37 = V_37 = F_7 ( V_2 , V_38 ) ;
if ( V_37 & V_56 )
F_39 |= V_57 ;
if ( V_37 & V_50 )
F_39 |= V_51 ;
if ( F_39 ) {
V_36 = V_118 ;
F_17 ( V_2 , F_39 ) ;
F_70 ( & V_2 -> V_39 ) ;
}
return V_36 ;
}
static int F_71 ( struct V_1 * V_2 ,
struct V_119 * V_120 )
{
const struct V_121 * V_122 = F_72 ( & V_120 -> V_53 ) ;
struct V_123 * V_124 = F_73 ( V_120 , V_125 , 0 ) ;
T_5 V_126 ;
struct V_127 V_128 ;
int V_36 ;
if ( ! V_124 || ! V_122 )
return 0 ;
V_2 -> V_72 = V_122 -> V_72 ;
if ( V_122 -> V_129 && V_122 -> V_130 ) {
F_74 ( V_126 ) ;
F_75 ( V_131 , V_126 ) ;
V_2 -> V_94 = F_76 ( V_126 , V_132 ,
( void * ) V_122 -> V_129 ) ;
if ( V_2 -> V_94 ) {
V_128 . V_133 = V_122 -> V_129 ;
V_128 . V_134 = V_135 ;
V_128 . V_136 = 0 ;
V_128 . V_137 = V_124 -> V_138 + V_55 ;
V_36 = F_77 ( V_2 -> V_94 , & V_128 ) ;
if ( ! V_36 )
F_78 ( & V_120 -> V_53 , L_3 ) ;
else
return V_36 ;
}
}
if ( V_122 -> V_130 ) {
F_74 ( V_126 ) ;
F_75 ( V_131 , V_126 ) ;
V_2 -> V_76 = F_76 ( V_126 , V_132 ,
( void * ) V_122 -> V_130 ) ;
if ( V_2 -> V_76 ) {
V_128 . V_133 = V_122 -> V_130 ;
V_128 . V_134 = V_139 ;
V_128 . V_136 = V_124 -> V_138 + V_55 ;
V_128 . V_137 = 0 ;
V_36 = F_77 ( V_2 -> V_76 , & V_128 ) ;
if ( ! V_36 )
F_78 ( & V_120 -> V_53 , L_4 ) ;
else
return V_36 ;
}
}
return 0 ;
}
static void F_79 ( struct V_1 * V_2 )
{
if ( V_2 -> V_76 )
F_80 ( V_2 -> V_76 ) ;
if ( V_2 -> V_94 )
F_80 ( V_2 -> V_94 ) ;
}
static int F_81 ( struct V_119 * V_120 )
{
struct V_1 * V_2 = F_82 ( V_120 ) ;
F_79 ( V_2 ) ;
F_83 ( V_2 -> V_9 ) ;
return 0 ;
}
static int F_84 ( struct V_119 * V_120 )
{
struct V_123 * V_124 ;
struct V_140 * V_52 ;
struct V_1 * V_2 ;
int V_36 , V_84 ;
char V_141 [ 16 ] ;
const struct V_121 * V_122 = F_72 ( & V_120 -> V_53 ) ;
const struct V_142 * V_143 ;
const struct V_144 * V_145 = V_120 -> V_145 ;
V_143 = (struct V_142 * ) V_145 -> V_146 ;
if ( ! V_143 -> F_64 ) {
F_23 ( & V_120 -> V_53 , L_5 ) ;
return - V_147 ;
}
V_84 = F_85 ( V_120 , 0 ) ;
if ( V_84 < 0 ) {
F_23 ( & V_120 -> V_53 , L_6 ) ;
return - V_147 ;
}
V_52 = F_86 ( & V_120 -> V_53 , sizeof( struct V_1 ) ) ;
if ( V_52 == NULL ) {
F_23 ( & V_120 -> V_53 , L_7 ) ;
return - V_75 ;
}
V_2 = F_63 ( V_52 ) ;
F_87 ( V_120 , V_2 ) ;
V_2 -> V_143 = V_143 ;
V_2 -> V_52 = V_52 ;
V_124 = F_73 ( V_120 , V_125 , 0 ) ;
V_2 -> V_5 = F_88 ( & V_120 -> V_53 , V_124 ) ;
if ( F_89 ( V_2 -> V_5 ) ) {
V_36 = F_90 ( V_2 -> V_5 ) ;
goto V_148;
}
snprintf ( V_141 , sizeof( V_141 ) , L_8 , V_145 -> V_149 , V_120 -> V_150 ) ;
V_2 -> V_9 = F_91 ( & V_120 -> V_53 , V_141 ) ;
if ( F_89 ( V_2 -> V_9 ) ) {
F_23 ( & V_120 -> V_53 , L_9 ) ;
V_36 = F_90 ( V_2 -> V_9 ) ;
goto V_148;
}
F_92 ( V_2 -> V_9 ) ;
F_93 ( & V_2 -> V_101 ) ;
F_94 ( & V_2 -> V_100 ) ;
F_95 ( & V_2 -> V_98 , F_52 ) ;
F_96 ( & V_2 -> V_39 ) ;
if ( V_122 && V_122 -> V_151 )
V_52 -> V_151 = V_122 -> V_151 ;
else
V_52 -> V_151 = 2 ;
V_52 -> V_152 = V_120 -> V_150 ;
V_52 -> V_153 = F_62 ;
V_52 -> V_154 = F_65 ;
V_52 -> V_155 = F_68 ;
V_52 -> V_156 = V_113 | V_111 ;
V_36 = F_97 ( & V_120 -> V_53 , V_84 , F_69 , 0 ,
F_98 ( & V_120 -> V_53 ) , V_2 ) ;
if ( V_36 < 0 ) {
F_23 ( & V_120 -> V_53 , L_10 ) ;
goto V_157;
}
V_2 -> V_84 = V_84 ;
V_36 = F_71 ( V_2 , V_120 ) ;
if ( V_36 < 0 ) {
F_23 ( & V_120 -> V_53 , L_11 ) ;
goto V_158;
}
V_36 = F_99 ( & V_120 -> V_53 , V_52 ) ;
if ( V_36 < 0 ) {
F_23 ( & V_120 -> V_53 , L_12 ) ;
goto V_158;
}
F_78 ( & V_120 -> V_53 , L_13 ) ;
return 0 ;
V_158:
F_79 ( V_2 ) ;
V_157:
F_83 ( V_2 -> V_9 ) ;
V_148:
F_100 ( V_52 ) ;
return V_36 ;
}
