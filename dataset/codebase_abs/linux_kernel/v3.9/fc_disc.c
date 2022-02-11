static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
V_4 = F_2 ( V_2 ) ;
F_3 ( & V_2 -> V_7 ) ;
F_4 (rdata, &disc->rports, peers)
V_4 -> V_8 . V_9 ( V_6 ) ;
F_5 ( & V_2 -> V_7 ) ;
}
static void F_6 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
struct V_3 * V_4 ;
struct V_12 * V_13 ;
struct V_14 * V_15 ;
struct V_16 V_17 ;
unsigned int V_18 ;
int V_19 = 0 ;
enum V_20 V_21 ;
enum V_22 V_23 ;
F_7 ( V_24 ) ;
struct V_25 * V_26 , * V_27 ;
V_4 = F_2 ( V_2 ) ;
F_8 ( V_2 , L_1 ) ;
V_13 = F_9 ( V_11 , sizeof( * V_13 ) ) ;
if ( ! V_13 )
goto V_28;
if ( V_13 -> V_29 != sizeof( * V_15 ) )
goto V_28;
V_18 = F_10 ( V_13 -> V_30 ) ;
if ( V_18 < sizeof( * V_13 ) )
goto V_28;
V_13 = F_9 ( V_11 , V_18 ) ;
if ( ! V_13 )
goto V_28;
V_18 -= sizeof( * V_13 ) ;
if ( V_18 % sizeof( * V_15 ) )
goto V_28;
for ( V_15 = ( void * ) ( V_13 + 1 ) ; V_18 > 0 ; V_18 -= sizeof( * V_15 ) , V_15 ++ ) {
V_21 = V_15 -> V_31 >> V_32 ;
V_21 &= V_33 ;
V_23 = V_15 -> V_31 >> V_34 ;
V_23 &= V_35 ;
switch ( V_23 ) {
case V_36 :
F_8 ( V_2 , L_2
L_3 , F_11 ( V_15 -> V_37 ) ) ;
V_26 = F_12 ( sizeof( * V_26 ) , V_38 ) ;
if ( ! V_26 ) {
V_19 = 1 ;
break;
}
V_26 -> V_39 = V_4 ;
V_26 -> V_40 = F_11 ( V_15 -> V_37 ) ;
F_13 ( & V_26 -> V_41 , & V_24 ) ;
break;
case V_42 :
case V_43 :
case V_44 :
default:
F_8 ( V_2 , L_4 , V_23 ) ;
V_19 = 1 ;
break;
}
}
V_4 -> V_8 . V_45 ( V_11 , V_46 , NULL ) ;
F_14 (dp, next, &disc_ports, peers) {
F_15 ( & V_26 -> V_41 ) ;
if ( ! V_19 )
V_19 = F_16 ( V_4 , V_26 ) ;
F_17 ( V_26 ) ;
}
if ( V_19 ) {
F_8 ( V_2 , L_5 ) ;
F_18 ( V_2 ) ;
} else {
F_8 ( V_2 , L_6
L_7 ,
V_19 , V_4 -> V_47 , V_2 -> V_48 ) ;
}
F_19 ( V_11 ) ;
return;
V_28:
F_8 ( V_2 , L_8 ) ;
V_17 . V_49 = V_50 ;
V_17 . V_51 = V_52 ;
V_4 -> V_8 . V_45 ( V_11 , V_53 , & V_17 ) ;
F_19 ( V_11 ) ;
}
static void F_20 ( struct V_3 * V_4 , struct V_10 * V_11 )
{
T_1 V_54 ;
struct V_1 * V_2 = & V_4 -> V_2 ;
V_54 = F_21 ( V_11 ) ;
switch ( V_54 ) {
case V_55 :
F_3 ( & V_2 -> V_7 ) ;
F_6 ( V_2 , V_11 ) ;
F_5 ( & V_2 -> V_7 ) ;
break;
default:
F_8 ( V_2 , L_9
L_10 , V_54 ) ;
F_19 ( V_11 ) ;
break;
}
}
static void F_18 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_56 )
return;
F_8 ( V_2 , L_11 ) ;
V_2 -> V_57 = 1 ;
if ( V_2 -> V_48 )
return;
V_2 -> V_58 = ( V_2 -> V_58 + 2 ) | 1 ;
V_2 -> V_59 = 0 ;
F_22 ( V_2 ) ;
}
static void F_23 ( void (* V_56)( struct V_3 * ,
enum V_60 ) ,
struct V_3 * V_4 )
{
struct V_1 * V_2 = & V_4 -> V_2 ;
F_3 ( & V_2 -> V_7 ) ;
V_2 -> V_56 = V_56 ;
F_18 ( V_2 ) ;
F_5 ( & V_2 -> V_7 ) ;
}
static void F_24 ( struct V_1 * V_2 , enum V_60 V_61 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 ;
F_8 ( V_2 , L_12 ) ;
V_2 -> V_48 = 0 ;
if ( V_2 -> V_57 ) {
F_18 ( V_2 ) ;
return;
}
F_4 (rdata, &disc->rports, peers) {
if ( ! V_6 -> V_58 )
continue;
if ( V_6 -> V_58 == V_2 -> V_58 )
V_4 -> V_8 . V_62 ( V_6 ) ;
else
V_4 -> V_8 . V_9 ( V_6 ) ;
}
F_5 ( & V_2 -> V_7 ) ;
V_2 -> V_56 ( V_4 , V_61 ) ;
F_3 ( & V_2 -> V_7 ) ;
}
static void F_25 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_63 = 0 ;
F_8 ( V_2 , L_13 ,
F_26 ( V_11 ) , V_2 -> V_59 ,
V_64 ) ;
if ( ! V_11 || F_26 ( V_11 ) == - V_65 ) {
if ( V_2 -> V_59 < V_64 ) {
if ( ! V_11 )
V_63 = F_27 ( V_66 ) ;
else {
V_63 = F_27 ( V_4 -> V_67 ) ;
if ( ! V_2 -> V_59 )
V_63 /= 4 ;
}
V_2 -> V_59 ++ ;
F_28 ( & V_2 -> V_68 , V_63 ) ;
} else
F_24 ( V_2 , V_69 ) ;
} else if ( F_26 ( V_11 ) == - V_70 ) {
V_2 -> V_48 = 0 ;
}
}
static void F_22 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_29 ( ! F_30 ( V_4 ) ) ;
V_2 -> V_48 = 1 ;
V_2 -> V_57 = 0 ;
V_2 -> V_71 = 0 ;
V_2 -> V_72 = 0 ;
V_11 = F_31 ( V_4 ,
sizeof( struct V_73 ) +
sizeof( struct V_74 ) ) ;
if ( ! V_11 )
goto V_75;
if ( V_4 -> V_8 . V_76 ( V_4 , 0 , V_11 ,
V_77 ,
V_78 ,
V_2 , 3 * V_4 -> V_79 ) )
return;
V_75:
F_25 ( V_2 , NULL ) ;
}
static int F_32 ( struct V_1 * V_2 , void * V_80 , T_2 V_18 )
{
struct V_3 * V_4 ;
struct V_81 * V_82 ;
char * V_83 ;
T_2 V_84 ;
T_2 V_85 ;
int error = 0 ;
struct V_86 V_87 ;
struct V_5 * V_6 ;
V_4 = F_2 ( V_2 ) ;
V_2 -> V_72 ++ ;
V_83 = V_80 ;
V_84 = V_18 ;
V_82 = (struct V_81 * ) V_83 ;
V_85 = V_2 -> V_71 ;
V_2 -> V_71 = 0 ;
if ( V_85 ) {
F_29 ( V_85 >= sizeof( * V_82 ) ) ;
V_84 = sizeof( * V_82 ) - V_85 ;
F_29 ( V_84 <= 0 ) ;
F_29 ( V_84 >= sizeof( * V_82 ) ) ;
if ( V_84 > V_18 )
V_84 = V_18 ;
V_82 = & V_2 -> V_88 ;
memcpy ( ( char * ) V_82 + V_85 , V_83 , V_84 ) ;
V_83 -= V_85 ;
V_18 += V_85 ;
V_84 += V_85 ;
V_2 -> V_71 = ( unsigned char ) V_84 ;
if ( V_84 == sizeof( * V_82 ) )
V_2 -> V_71 = 0 ;
}
while ( V_84 >= sizeof( * V_82 ) ) {
V_87 . V_40 = F_11 ( V_82 -> V_89 ) ;
V_87 . V_90 = F_33 ( V_82 -> V_91 ) ;
if ( V_87 . V_40 != V_4 -> V_40 &&
V_87 . V_90 != V_4 -> V_92 ) {
V_6 = V_4 -> V_8 . V_93 ( V_4 , V_87 . V_40 ) ;
if ( V_6 ) {
V_6 -> V_87 . V_90 = V_87 . V_90 ;
V_6 -> V_58 = V_2 -> V_58 ;
} else {
F_34 ( V_94 L_14
L_15
L_3 , V_87 . V_40 ) ;
error = - V_95 ;
}
}
if ( V_82 -> V_96 & V_97 ) {
F_24 ( V_2 , V_98 ) ;
V_18 = 0 ;
break;
}
V_18 -= sizeof( * V_82 ) ;
V_83 += sizeof( * V_82 ) ;
V_82 = (struct V_81 * ) V_83 ;
V_84 = V_18 ;
}
if ( error == 0 && V_18 > 0 && V_18 < sizeof( * V_82 ) ) {
if ( V_82 != & V_2 -> V_88 ) {
F_8 ( V_2 , L_16
L_17 ) ;
memcpy ( & V_2 -> V_88 , V_82 , V_18 ) ;
}
V_2 -> V_71 = ( unsigned char ) V_18 ;
}
return error ;
}
static void F_35 ( struct V_99 * V_100 )
{
struct V_1 * V_2 = F_36 ( V_100 ,
struct V_1 ,
V_68 . V_100 ) ;
F_3 ( & V_2 -> V_7 ) ;
F_22 ( V_2 ) ;
F_5 ( & V_2 -> V_7 ) ;
}
static void V_78 ( struct V_101 * V_102 , struct V_10 * V_11 ,
void * V_103 )
{
struct V_1 * V_2 = V_103 ;
struct V_73 * V_104 ;
struct V_105 * V_106 ;
enum V_60 V_61 = V_107 ;
unsigned int V_108 ;
unsigned int V_18 ;
int error = 0 ;
F_3 ( & V_2 -> V_7 ) ;
F_8 ( V_2 , L_18 ) ;
if ( F_37 ( V_11 ) ) {
F_25 ( V_2 , V_11 ) ;
F_5 ( & V_2 -> V_7 ) ;
return;
}
F_29 ( ! F_38 ( V_11 ) ) ;
V_106 = F_39 ( V_11 ) ;
V_18 = F_40 ( V_11 ) - sizeof( * V_106 ) ;
V_108 = F_10 ( V_106 -> V_109 ) ;
if ( F_41 ( V_11 ) == V_110 && V_108 == 0 && V_2 -> V_72 == 0 ) {
V_104 = F_9 ( V_11 , sizeof( * V_104 ) ) ;
if ( ! V_104 ) {
F_8 ( V_2 , L_19 ,
F_40 ( V_11 ) ) ;
V_61 = V_69 ;
} else if ( F_10 ( V_104 -> V_111 ) == V_112 ) {
V_18 -= sizeof( * V_104 ) ;
error = F_32 ( V_2 , V_104 + 1 , V_18 ) ;
} else if ( F_10 ( V_104 -> V_111 ) == V_113 ) {
F_8 ( V_2 , L_20
L_21 , V_104 -> V_114 ,
V_104 -> V_115 ) ;
V_61 = V_69 ;
if ( V_104 -> V_114 == V_116 &&
V_104 -> V_115 == V_117 )
V_61 = V_98 ;
} else {
F_8 ( V_2 , L_22
L_23 , F_10 ( V_104 -> V_111 ) ) ;
V_61 = V_69 ;
}
} else if ( F_41 ( V_11 ) == V_118 && V_108 == V_2 -> V_72 ) {
error = F_32 ( V_2 , V_106 + 1 , V_18 ) ;
} else {
F_8 ( V_2 , L_24
L_25 ,
V_108 , V_2 -> V_72 , F_41 ( V_11 ) , F_42 ( V_11 ) ) ;
V_61 = V_69 ;
}
if ( error )
F_25 ( V_2 , V_11 ) ;
else if ( V_61 != V_107 )
F_24 ( V_2 , V_61 ) ;
F_19 ( V_11 ) ;
F_5 ( & V_2 -> V_7 ) ;
}
static void F_43 ( struct V_101 * V_102 , struct V_10 * V_11 ,
void * V_119 )
{
struct V_5 * V_6 = V_119 ;
struct V_5 * V_120 ;
struct V_3 * V_4 ;
struct V_1 * V_2 ;
struct V_73 * V_104 ;
struct V_121 * V_122 ;
T_3 V_90 ;
V_4 = V_6 -> V_123 ;
V_2 = & V_4 -> V_2 ;
F_3 ( & V_2 -> V_7 ) ;
if ( F_26 ( V_11 ) == - V_70 )
goto V_124;
if ( F_37 ( V_11 ) )
goto V_19;
V_104 = F_9 ( V_11 , sizeof( * V_104 ) ) ;
if ( ! V_104 )
goto V_19;
if ( F_10 ( V_104 -> V_111 ) == V_112 ) {
if ( F_40 ( V_11 ) < sizeof( struct V_105 ) +
sizeof( * V_104 ) + sizeof( * V_122 ) )
goto V_19;
V_122 = (struct V_121 * ) ( V_104 + 1 ) ;
V_90 = F_44 ( & V_122 -> V_125 ) ;
if ( V_6 -> V_87 . V_90 == - 1 )
V_6 -> V_87 . V_90 = V_90 ;
else if ( V_6 -> V_87 . V_90 != V_90 ) {
F_8 ( V_2 , L_26
L_27 ,
V_6 -> V_87 . V_40 , V_90 ) ;
V_4 -> V_8 . V_9 ( V_6 ) ;
V_120 = V_4 -> V_8 . V_93 ( V_4 ,
V_6 -> V_87 . V_40 ) ;
if ( V_120 ) {
V_120 -> V_58 = V_2 -> V_58 ;
V_4 -> V_8 . V_62 ( V_120 ) ;
}
goto V_124;
}
V_6 -> V_58 = V_2 -> V_58 ;
V_4 -> V_8 . V_62 ( V_6 ) ;
} else if ( F_10 ( V_104 -> V_111 ) == V_113 ) {
F_8 ( V_2 , L_28 ,
V_104 -> V_114 , V_104 -> V_115 ) ;
V_4 -> V_8 . V_9 ( V_6 ) ;
} else {
F_8 ( V_2 , L_29 ,
F_10 ( V_104 -> V_111 ) ) ;
V_19:
F_18 ( V_2 ) ;
}
V_124:
F_5 ( & V_2 -> V_7 ) ;
F_45 ( & V_6 -> V_126 , V_4 -> V_8 . V_127 ) ;
}
static int F_46 ( struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_10 * V_11 ;
V_11 = F_31 ( V_4 , sizeof( struct V_73 ) +
sizeof( struct V_128 ) ) ;
if ( ! V_11 )
return - V_95 ;
if ( ! V_4 -> V_8 . V_76 ( V_4 , V_6 -> V_87 . V_40 , V_11 , V_129 ,
F_43 , V_6 ,
3 * V_4 -> V_79 ) )
return - V_95 ;
F_47 ( & V_6 -> V_126 ) ;
return 0 ;
}
static int F_16 ( struct V_3 * V_4 , struct V_25 * V_26 )
{
struct V_5 * V_6 ;
V_6 = V_4 -> V_8 . V_93 ( V_4 , V_26 -> V_40 ) ;
if ( ! V_6 )
return - V_95 ;
V_6 -> V_58 = 0 ;
return F_46 ( V_4 , V_6 ) ;
}
static void F_48 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = & V_4 -> V_2 ;
if ( V_2 -> V_48 )
F_49 ( & V_2 -> V_68 ) ;
F_1 ( V_2 ) ;
}
static void F_50 ( struct V_3 * V_4 )
{
F_48 ( V_4 ) ;
V_4 -> V_8 . V_130 () ;
}
void F_51 ( struct V_3 * V_4 , void * V_131 )
{
struct V_1 * V_2 = & V_4 -> V_2 ;
if ( ! V_4 -> V_8 . V_132 )
V_4 -> V_8 . V_132 = F_23 ;
if ( ! V_4 -> V_8 . V_133 )
V_4 -> V_8 . V_133 = F_48 ;
if ( ! V_4 -> V_8 . V_134 )
V_4 -> V_8 . V_134 = F_50 ;
if ( ! V_4 -> V_8 . V_135 )
V_4 -> V_8 . V_135 = F_20 ;
V_2 = & V_4 -> V_2 ;
V_2 -> V_131 = V_131 ;
}
void F_52 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = & V_4 -> V_2 ;
F_53 ( & V_2 -> V_68 , F_35 ) ;
F_54 ( & V_2 -> V_7 ) ;
F_55 ( & V_2 -> V_136 ) ;
}
