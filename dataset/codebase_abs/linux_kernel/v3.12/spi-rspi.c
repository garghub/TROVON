static void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
F_2 ( V_3 , V_2 -> V_5 + V_4 ) ;
}
static void F_3 ( struct V_1 * V_2 , T_2 V_3 , T_2 V_4 )
{
F_4 ( V_3 , V_2 -> V_5 + V_4 ) ;
}
static T_1 F_5 ( struct V_1 * V_2 , T_2 V_4 )
{
return F_6 ( V_2 -> V_5 + V_4 ) ;
}
static T_2 F_7 ( struct V_1 * V_2 , T_2 V_4 )
{
return F_8 ( V_2 -> V_5 + V_4 ) ;
}
static unsigned char F_9 ( struct V_1 * V_2 )
{
int V_6 ;
unsigned char V_7 ;
V_6 = F_10 ( V_2 -> V_8 ) / ( 2 * V_2 -> V_9 ) - 1 ;
V_7 = F_11 ( V_6 , 0 , 255 ) ;
return V_7 ;
}
static void F_12 ( struct V_1 * V_2 , T_1 V_10 )
{
F_1 ( V_2 , F_5 ( V_2 , V_11 ) | V_10 , V_11 ) ;
}
static void F_13 ( struct V_1 * V_2 , T_1 V_12 )
{
F_1 ( V_2 , F_5 ( V_2 , V_11 ) & ~ V_12 , V_11 ) ;
}
static int F_14 ( struct V_1 * V_2 , T_1 V_13 ,
T_1 V_14 )
{
int V_15 ;
V_2 -> V_16 = F_5 ( V_2 , V_17 ) ;
F_12 ( V_2 , V_14 ) ;
V_15 = F_15 ( V_2 -> V_18 , V_2 -> V_16 & V_13 , V_19 ) ;
if ( V_15 == 0 && ! ( V_2 -> V_16 & V_13 ) )
return - V_20 ;
return 0 ;
}
static void F_16 ( struct V_1 * V_2 )
{
F_1 ( V_2 , F_5 ( V_2 , V_11 ) | V_21 , V_11 ) ;
}
static void F_17 ( struct V_1 * V_2 )
{
F_1 ( V_2 , F_5 ( V_2 , V_11 ) & ~ V_21 , V_11 ) ;
}
static int F_18 ( struct V_1 * V_2 , int V_22 )
{
F_1 ( V_2 , 0x00 , V_23 ) ;
F_1 ( V_2 , F_9 ( V_2 ) , V_24 ) ;
F_1 ( V_2 , 0x00 , V_25 ) ;
F_1 ( V_2 , 0x00 , V_26 ) ;
F_1 ( V_2 , 0x00 , V_27 ) ;
F_1 ( V_2 , 0x00 , V_28 ) ;
F_1 ( V_2 , 0x00 , V_29 ) ;
F_3 ( V_2 , F_19 ( V_22 ) | V_30 ,
V_31 ) ;
F_1 ( V_2 , V_32 , V_11 ) ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 , struct V_33 * V_34 ,
struct V_35 * V_36 )
{
int V_37 = V_36 -> V_38 ;
T_1 * V_3 ;
V_3 = ( T_1 * ) V_36 -> V_39 ;
while ( V_37 > 0 ) {
F_1 ( V_2 , F_5 ( V_2 , V_11 ) | V_40 ,
V_11 ) ;
if ( F_14 ( V_2 , V_41 , V_42 ) < 0 ) {
F_21 ( & V_2 -> V_43 -> V_44 ,
L_1 , V_45 ) ;
return - V_20 ;
}
F_3 ( V_2 , * V_3 , V_46 ) ;
V_3 ++ ;
V_37 -- ;
}
F_14 ( V_2 , V_41 , V_42 ) ;
return 0 ;
}
static void F_22 ( void * V_47 )
{
struct V_1 * V_2 = V_47 ;
V_2 -> V_48 = 1 ;
F_23 ( & V_2 -> V_18 ) ;
}
static int F_24 ( struct V_49 * V_50 , void * V_51 , unsigned V_38 ,
struct V_52 * V_53 ,
enum V_54 V_55 )
{
F_25 ( V_50 , 1 ) ;
F_26 ( V_50 , V_51 , V_38 ) ;
F_27 ( V_50 ) = V_38 ;
return F_28 ( V_53 -> V_56 -> V_44 , V_50 , 1 , V_55 ) ;
}
static void F_29 ( struct V_49 * V_50 , struct V_52 * V_53 ,
enum V_54 V_55 )
{
F_30 ( V_53 -> V_56 -> V_44 , V_50 , 1 , V_55 ) ;
}
static void F_31 ( void * V_51 , const void * V_3 , unsigned V_38 )
{
T_2 * V_57 = V_51 ;
const T_1 * V_58 = V_3 ;
while ( V_38 ) {
* V_57 ++ = ( T_2 ) ( * V_58 ++ ) ;
V_38 -- ;
}
}
static void F_32 ( void * V_51 , const void * V_3 , unsigned V_38 )
{
T_1 * V_57 = V_51 ;
const T_2 * V_58 = V_3 ;
while ( V_38 ) {
* V_57 ++ = ( T_1 ) * V_58 ++ ;
V_38 -- ;
}
}
static int F_33 ( struct V_1 * V_2 , struct V_35 * V_36 )
{
struct V_49 V_50 ;
void * V_51 = NULL ;
struct V_59 * V_60 ;
unsigned V_38 ;
int V_15 = 0 ;
if ( V_2 -> V_61 ) {
V_38 = V_36 -> V_38 * 2 ;
V_51 = F_34 ( V_38 , V_62 ) ;
if ( ! V_51 )
return - V_63 ;
F_31 ( V_51 , V_36 -> V_39 , V_36 -> V_38 ) ;
} else {
V_38 = V_36 -> V_38 ;
V_51 = ( void * ) V_36 -> V_39 ;
}
if ( ! F_24 ( & V_50 , V_51 , V_38 , V_2 -> V_64 , V_65 ) ) {
V_15 = - V_66 ;
goto V_67;
}
V_60 = F_35 ( V_2 -> V_64 , & V_50 , 1 , V_65 ,
V_68 | V_69 ) ;
if ( ! V_60 ) {
V_15 = - V_70 ;
goto V_71;
}
F_36 ( V_2 -> V_72 ) ;
F_1 ( V_2 , F_5 ( V_2 , V_11 ) | V_40 , V_11 ) ;
F_12 ( V_2 , V_42 ) ;
V_2 -> V_48 = 0 ;
V_60 -> V_73 = F_22 ;
V_60 -> V_74 = V_2 ;
F_37 ( V_60 ) ;
F_38 ( V_2 -> V_64 ) ;
V_15 = F_39 ( V_2 -> V_18 ,
V_2 -> V_48 , V_19 ) ;
if ( V_15 > 0 && V_2 -> V_48 )
V_15 = 0 ;
else if ( ! V_15 )
V_15 = - V_20 ;
F_13 ( V_2 , V_42 ) ;
F_40 ( V_2 -> V_72 ) ;
V_71:
F_29 ( & V_50 , V_2 -> V_64 , V_65 ) ;
V_67:
if ( V_2 -> V_61 )
F_41 ( V_51 ) ;
return V_15 ;
}
static void F_42 ( struct V_1 * V_2 )
{
unsigned char V_16 ;
V_16 = F_5 ( V_2 , V_17 ) ;
if ( V_16 & V_75 )
F_7 ( V_2 , V_46 ) ;
if ( V_16 & V_76 )
F_1 ( V_2 , F_5 ( V_2 , V_17 ) & ~ V_76 ,
V_11 ) ;
}
static int F_43 ( struct V_1 * V_2 , struct V_33 * V_34 ,
struct V_35 * V_36 )
{
int V_37 = V_36 -> V_38 ;
T_1 * V_3 ;
F_42 ( V_2 ) ;
V_3 = ( T_1 * ) V_36 -> V_77 ;
while ( V_37 > 0 ) {
F_1 ( V_2 , F_5 ( V_2 , V_11 ) & ~ V_40 ,
V_11 ) ;
if ( F_14 ( V_2 , V_41 , V_42 ) < 0 ) {
F_21 ( & V_2 -> V_43 -> V_44 ,
L_1 , V_45 ) ;
return - V_20 ;
}
F_3 ( V_2 , 0x00 , V_46 ) ;
if ( F_14 ( V_2 , V_75 , V_78 ) < 0 ) {
F_21 ( & V_2 -> V_43 -> V_44 ,
L_2 , V_45 ) ;
return - V_20 ;
}
* V_3 = ( T_1 ) F_7 ( V_2 , V_46 ) ;
V_3 ++ ;
V_37 -- ;
}
return 0 ;
}
static int F_44 ( struct V_1 * V_2 , struct V_35 * V_36 )
{
struct V_49 V_50 , V_79 ;
void * V_80 = NULL , * V_77 = NULL ;
struct V_59 * V_60 , * V_81 ;
unsigned V_38 ;
int V_15 = 0 ;
if ( V_2 -> V_61 ) {
V_38 = V_36 -> V_38 * 2 ;
V_77 = F_34 ( V_38 , V_62 ) ;
if ( ! V_77 )
return - V_63 ;
} else {
V_38 = V_36 -> V_38 ;
V_77 = V_36 -> V_77 ;
}
V_80 = F_45 ( V_38 , V_62 ) ;
if ( ! V_80 ) {
V_15 = - V_63 ;
goto V_67;
}
if ( ! F_24 ( & V_79 , V_80 , V_38 , V_2 -> V_64 ,
V_65 ) ) {
V_15 = - V_66 ;
goto V_67;
}
V_81 = F_35 ( V_2 -> V_64 , & V_79 , 1 ,
V_65 , V_68 | V_69 ) ;
if ( ! V_81 ) {
V_15 = - V_70 ;
goto V_82;
}
if ( ! F_24 ( & V_50 , V_77 , V_38 , V_2 -> V_83 ,
V_84 ) ) {
V_15 = - V_66 ;
goto V_82;
}
V_60 = F_35 ( V_2 -> V_83 , & V_50 , 1 , V_84 ,
V_68 | V_69 ) ;
if ( ! V_60 ) {
V_15 = - V_70 ;
goto V_71;
}
F_42 ( V_2 ) ;
F_36 ( V_2 -> V_72 ) ;
F_1 ( V_2 , F_5 ( V_2 , V_11 ) & ~ V_40 , V_11 ) ;
F_12 ( V_2 , V_42 | V_78 ) ;
V_2 -> V_48 = 0 ;
V_60 -> V_73 = F_22 ;
V_60 -> V_74 = V_2 ;
F_37 ( V_60 ) ;
F_38 ( V_2 -> V_83 ) ;
V_81 -> V_73 = NULL ;
F_37 ( V_81 ) ;
F_38 ( V_2 -> V_64 ) ;
V_15 = F_39 ( V_2 -> V_18 ,
V_2 -> V_48 , V_19 ) ;
if ( V_15 > 0 && V_2 -> V_48 )
V_15 = 0 ;
else if ( ! V_15 )
V_15 = - V_20 ;
F_13 ( V_2 , V_42 | V_78 ) ;
F_40 ( V_2 -> V_72 ) ;
V_71:
F_29 ( & V_50 , V_2 -> V_83 , V_84 ) ;
V_82:
F_29 ( & V_79 , V_2 -> V_64 , V_65 ) ;
V_67:
if ( V_2 -> V_61 ) {
if ( ! V_15 )
F_32 ( V_36 -> V_77 , V_77 , V_36 -> V_38 ) ;
F_41 ( V_77 ) ;
}
F_41 ( V_80 ) ;
return V_15 ;
}
static int F_46 ( struct V_1 * V_2 , struct V_35 * V_36 )
{
if ( V_36 -> V_39 && V_2 -> V_64 )
return 1 ;
if ( V_36 -> V_77 && V_2 -> V_64 && V_2 -> V_83 )
return 1 ;
return 0 ;
}
static void F_47 ( struct V_85 * V_86 )
{
struct V_1 * V_2 = F_48 ( V_86 , struct V_1 , V_87 ) ;
struct V_33 * V_34 ;
struct V_35 * V_36 ;
unsigned long V_88 ;
int V_15 ;
while ( 1 ) {
F_49 ( & V_2 -> V_89 , V_88 ) ;
if ( F_50 ( & V_2 -> V_90 ) ) {
F_51 ( & V_2 -> V_89 , V_88 ) ;
break;
}
V_34 = F_52 ( V_2 -> V_90 . V_91 , struct V_33 , V_90 ) ;
F_53 ( & V_34 -> V_90 ) ;
F_51 ( & V_2 -> V_89 , V_88 ) ;
F_16 ( V_2 ) ;
F_54 (t, &mesg->transfers, transfer_list) {
if ( V_36 -> V_39 ) {
if ( F_46 ( V_2 , V_36 ) )
V_15 = F_33 ( V_2 , V_36 ) ;
else
V_15 = F_20 ( V_2 , V_34 , V_36 ) ;
if ( V_15 < 0 )
goto error;
}
if ( V_36 -> V_77 ) {
if ( F_46 ( V_2 , V_36 ) )
V_15 = F_44 ( V_2 , V_36 ) ;
else
V_15 = F_43 ( V_2 , V_34 , V_36 ) ;
if ( V_15 < 0 )
goto error;
}
V_34 -> V_92 += V_36 -> V_38 ;
}
F_17 ( V_2 ) ;
V_34 -> V_93 = 0 ;
V_34 -> V_94 ( V_34 -> V_95 ) ;
}
return;
error:
V_34 -> V_93 = V_15 ;
V_34 -> V_94 ( V_34 -> V_95 ) ;
}
static int F_55 ( struct V_96 * V_97 )
{
struct V_1 * V_2 = F_56 ( V_97 -> V_43 ) ;
if ( ! V_97 -> V_98 )
V_97 -> V_98 = 8 ;
V_2 -> V_9 = V_97 -> V_9 ;
F_18 ( V_2 , 8 ) ;
return 0 ;
}
static int F_57 ( struct V_96 * V_97 , struct V_33 * V_34 )
{
struct V_1 * V_2 = F_56 ( V_97 -> V_43 ) ;
unsigned long V_88 ;
V_34 -> V_92 = 0 ;
V_34 -> V_93 = - V_99 ;
F_49 ( & V_2 -> V_89 , V_88 ) ;
F_58 ( & V_34 -> V_90 , & V_2 -> V_90 ) ;
F_59 ( & V_2 -> V_87 ) ;
F_51 ( & V_2 -> V_89 , V_88 ) ;
return 0 ;
}
static void F_60 ( struct V_96 * V_97 )
{
}
static T_3 F_61 ( int V_72 , void * V_100 )
{
struct V_1 * V_2 = (struct V_1 * ) V_100 ;
unsigned long V_16 ;
T_3 V_15 = V_101 ;
unsigned char F_36 = 0 ;
V_2 -> V_16 = V_16 = F_5 ( V_2 , V_17 ) ;
if ( V_16 & V_75 )
F_36 |= V_78 ;
if ( V_16 & V_41 )
F_36 |= V_42 ;
if ( F_36 ) {
V_15 = V_102 ;
F_13 ( V_2 , F_36 ) ;
F_62 ( & V_2 -> V_18 ) ;
}
return V_15 ;
}
static int F_63 ( struct V_1 * V_2 ,
struct V_103 * V_104 )
{
struct V_105 * V_106 = F_64 ( & V_104 -> V_44 ) ;
struct V_107 * V_108 = F_65 ( V_104 , V_109 , 0 ) ;
T_4 V_110 ;
struct V_111 V_112 ;
int V_15 ;
if ( ! V_108 || ! V_106 )
return 0 ;
V_2 -> V_61 = V_106 -> V_61 ;
if ( V_106 -> V_113 && V_106 -> V_114 ) {
F_66 ( V_110 ) ;
F_67 ( V_115 , V_110 ) ;
V_2 -> V_83 = F_68 ( V_110 , V_116 ,
( void * ) V_106 -> V_113 ) ;
if ( V_2 -> V_83 ) {
V_112 . V_117 = V_106 -> V_113 ;
V_112 . V_118 = V_119 ;
V_112 . V_120 = 0 ;
V_112 . V_121 = V_108 -> V_122 + V_46 ;
V_15 = F_69 ( V_2 -> V_83 , & V_112 ) ;
if ( ! V_15 )
F_70 ( & V_104 -> V_44 , L_3 ) ;
else
return V_15 ;
}
}
if ( V_106 -> V_114 ) {
F_66 ( V_110 ) ;
F_67 ( V_115 , V_110 ) ;
V_2 -> V_64 = F_68 ( V_110 , V_116 ,
( void * ) V_106 -> V_114 ) ;
if ( V_2 -> V_64 ) {
V_112 . V_117 = V_106 -> V_114 ;
V_112 . V_118 = V_123 ;
V_112 . V_120 = V_108 -> V_122 + V_46 ;
V_112 . V_121 = 0 ;
V_15 = F_69 ( V_2 -> V_64 , & V_112 ) ;
if ( ! V_15 )
F_70 ( & V_104 -> V_44 , L_4 ) ;
else
return V_15 ;
}
}
return 0 ;
}
static void F_71 ( struct V_1 * V_2 )
{
if ( V_2 -> V_64 )
F_72 ( V_2 -> V_64 ) ;
if ( V_2 -> V_83 )
F_72 ( V_2 -> V_83 ) ;
}
static int F_73 ( struct V_103 * V_104 )
{
struct V_1 * V_2 = F_74 ( F_75 ( V_104 ) ) ;
F_76 ( V_2 -> V_43 ) ;
F_71 ( V_2 ) ;
F_77 ( F_78 ( V_104 , 0 ) , V_2 ) ;
F_79 ( V_2 -> V_8 ) ;
F_80 ( V_2 -> V_5 ) ;
F_81 ( V_2 -> V_43 ) ;
return 0 ;
}
static int F_82 ( struct V_103 * V_104 )
{
struct V_107 * V_108 ;
struct V_124 * V_43 ;
struct V_1 * V_2 ;
int V_15 , V_72 ;
char V_125 [ 16 ] ;
V_108 = F_65 ( V_104 , V_109 , 0 ) ;
if ( F_83 ( V_108 == NULL ) ) {
F_21 ( & V_104 -> V_44 , L_5 ) ;
return - V_126 ;
}
V_72 = F_78 ( V_104 , 0 ) ;
if ( V_72 < 0 ) {
F_21 ( & V_104 -> V_44 , L_6 ) ;
return - V_127 ;
}
V_43 = F_84 ( & V_104 -> V_44 , sizeof( struct V_1 ) ) ;
if ( V_43 == NULL ) {
F_21 ( & V_104 -> V_44 , L_7 ) ;
return - V_63 ;
}
V_2 = F_56 ( V_43 ) ;
F_85 ( V_104 , V_2 ) ;
V_2 -> V_43 = V_43 ;
V_2 -> V_5 = F_86 ( V_108 -> V_122 , F_87 ( V_108 ) ) ;
if ( V_2 -> V_5 == NULL ) {
F_21 ( & V_104 -> V_44 , L_8 ) ;
V_15 = - V_63 ;
goto V_128;
}
snprintf ( V_125 , sizeof( V_125 ) , L_9 , V_104 -> V_129 ) ;
V_2 -> V_8 = F_88 ( & V_104 -> V_44 , V_125 ) ;
if ( F_89 ( V_2 -> V_8 ) ) {
F_21 ( & V_104 -> V_44 , L_10 ) ;
V_15 = F_90 ( V_2 -> V_8 ) ;
goto V_130;
}
F_91 ( V_2 -> V_8 ) ;
F_92 ( & V_2 -> V_90 ) ;
F_93 ( & V_2 -> V_89 ) ;
F_94 ( & V_2 -> V_87 , F_47 ) ;
F_95 ( & V_2 -> V_18 ) ;
V_43 -> V_131 = 2 ;
V_43 -> V_132 = V_104 -> V_129 ;
V_43 -> V_133 = F_55 ;
V_43 -> V_134 = F_57 ;
V_43 -> V_135 = F_60 ;
V_15 = F_96 ( V_72 , F_61 , 0 , F_97 ( & V_104 -> V_44 ) , V_2 ) ;
if ( V_15 < 0 ) {
F_21 ( & V_104 -> V_44 , L_11 ) ;
goto V_136;
}
V_2 -> V_72 = V_72 ;
V_15 = F_63 ( V_2 , V_104 ) ;
if ( V_15 < 0 ) {
F_21 ( & V_104 -> V_44 , L_12 ) ;
goto V_137;
}
V_15 = F_98 ( V_43 ) ;
if ( V_15 < 0 ) {
F_21 ( & V_104 -> V_44 , L_13 ) ;
goto V_137;
}
F_70 ( & V_104 -> V_44 , L_14 ) ;
return 0 ;
V_137:
F_71 ( V_2 ) ;
F_77 ( V_72 , V_2 ) ;
V_136:
F_79 ( V_2 -> V_8 ) ;
V_130:
F_80 ( V_2 -> V_5 ) ;
V_128:
F_81 ( V_43 ) ;
return V_15 ;
}
