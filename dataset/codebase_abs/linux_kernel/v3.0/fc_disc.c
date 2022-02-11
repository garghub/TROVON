void F_1 ( struct V_1 * V_2 )
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
}
}
static void F_22 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_29 ( ! F_30 ( V_4 ) ) ;
V_2 -> V_48 = 1 ;
V_2 -> V_57 = 0 ;
V_2 -> V_70 = 0 ;
V_2 -> V_71 = 0 ;
V_11 = F_31 ( V_4 ,
sizeof( struct V_72 ) +
sizeof( struct V_73 ) ) ;
if ( ! V_11 )
goto V_74;
if ( V_4 -> V_8 . V_75 ( V_4 , 0 , V_11 ,
V_76 ,
V_77 ,
V_2 , 3 * V_4 -> V_78 ) )
return;
V_74:
F_25 ( V_2 , NULL ) ;
}
static int F_32 ( struct V_1 * V_2 , void * V_79 , T_2 V_18 )
{
struct V_3 * V_4 ;
struct V_80 * V_81 ;
char * V_82 ;
T_2 V_83 ;
T_2 V_84 ;
int error = 0 ;
struct V_85 V_86 ;
struct V_5 * V_6 ;
V_4 = F_2 ( V_2 ) ;
V_2 -> V_71 ++ ;
V_82 = V_79 ;
V_83 = V_18 ;
V_81 = (struct V_80 * ) V_82 ;
V_84 = V_2 -> V_70 ;
V_2 -> V_70 = 0 ;
if ( V_84 ) {
F_29 ( V_84 >= sizeof( * V_81 ) ) ;
V_83 = sizeof( * V_81 ) - V_84 ;
F_29 ( V_83 <= 0 ) ;
F_29 ( V_83 >= sizeof( * V_81 ) ) ;
if ( V_83 > V_18 )
V_83 = V_18 ;
V_81 = & V_2 -> V_87 ;
memcpy ( ( char * ) V_81 + V_84 , V_82 , V_83 ) ;
V_82 -= V_84 ;
V_18 += V_84 ;
V_83 += V_84 ;
V_2 -> V_70 = ( unsigned char ) V_83 ;
if ( V_83 == sizeof( * V_81 ) )
V_2 -> V_70 = 0 ;
}
while ( V_83 >= sizeof( * V_81 ) ) {
V_86 . V_40 = F_11 ( V_81 -> V_88 ) ;
V_86 . V_89 = F_33 ( V_81 -> V_90 ) ;
if ( V_86 . V_40 != V_4 -> V_40 &&
V_86 . V_89 != V_4 -> V_91 ) {
V_6 = V_4 -> V_8 . V_92 ( V_4 , V_86 . V_40 ) ;
if ( V_6 ) {
V_6 -> V_86 . V_89 = V_86 . V_89 ;
V_6 -> V_58 = V_2 -> V_58 ;
} else {
F_34 ( V_93 L_14
L_15
L_3 , V_86 . V_40 ) ;
error = - V_94 ;
}
}
if ( V_81 -> V_95 & V_96 ) {
F_24 ( V_2 , V_97 ) ;
V_18 = 0 ;
break;
}
V_18 -= sizeof( * V_81 ) ;
V_82 += sizeof( * V_81 ) ;
V_81 = (struct V_80 * ) V_82 ;
V_83 = V_18 ;
}
if ( error == 0 && V_18 > 0 && V_18 < sizeof( * V_81 ) ) {
if ( V_81 != & V_2 -> V_87 ) {
F_8 ( V_2 , L_16
L_17 ) ;
memcpy ( & V_2 -> V_87 , V_81 , V_18 ) ;
}
V_2 -> V_70 = ( unsigned char ) V_18 ;
}
return error ;
}
static void F_35 ( struct V_98 * V_99 )
{
struct V_1 * V_2 = F_36 ( V_99 ,
struct V_1 ,
V_68 . V_99 ) ;
F_3 ( & V_2 -> V_7 ) ;
F_22 ( V_2 ) ;
F_5 ( & V_2 -> V_7 ) ;
}
static void V_77 ( struct V_100 * V_101 , struct V_10 * V_11 ,
void * V_102 )
{
struct V_1 * V_2 = V_102 ;
struct V_72 * V_103 ;
struct V_104 * V_105 ;
enum V_60 V_61 = V_106 ;
unsigned int V_107 ;
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
V_105 = F_39 ( V_11 ) ;
V_18 = F_40 ( V_11 ) - sizeof( * V_105 ) ;
V_107 = F_10 ( V_105 -> V_108 ) ;
if ( F_41 ( V_11 ) == V_109 && V_107 == 0 && V_2 -> V_71 == 0 ) {
V_103 = F_9 ( V_11 , sizeof( * V_103 ) ) ;
if ( ! V_103 ) {
F_8 ( V_2 , L_19 ,
F_40 ( V_11 ) ) ;
V_61 = V_69 ;
} else if ( F_10 ( V_103 -> V_110 ) == V_111 ) {
V_18 -= sizeof( * V_103 ) ;
error = F_32 ( V_2 , V_103 + 1 , V_18 ) ;
} else if ( F_10 ( V_103 -> V_110 ) == V_112 ) {
F_8 ( V_2 , L_20
L_21 , V_103 -> V_113 ,
V_103 -> V_114 ) ;
V_61 = V_69 ;
if ( V_103 -> V_113 == V_115 &&
V_103 -> V_114 == V_116 )
V_61 = V_97 ;
} else {
F_8 ( V_2 , L_22
L_23 , F_10 ( V_103 -> V_110 ) ) ;
V_61 = V_69 ;
}
} else if ( F_41 ( V_11 ) == V_117 && V_107 == V_2 -> V_71 ) {
error = F_32 ( V_2 , V_105 + 1 , V_18 ) ;
} else {
F_8 ( V_2 , L_24
L_25 ,
V_107 , V_2 -> V_71 , F_41 ( V_11 ) , F_42 ( V_11 ) ) ;
V_61 = V_69 ;
}
if ( error )
F_25 ( V_2 , V_11 ) ;
else if ( V_61 != V_106 )
F_24 ( V_2 , V_61 ) ;
F_19 ( V_11 ) ;
F_5 ( & V_2 -> V_7 ) ;
}
static void F_43 ( struct V_100 * V_101 , struct V_10 * V_11 ,
void * V_118 )
{
struct V_5 * V_6 = V_118 ;
struct V_5 * V_119 ;
struct V_3 * V_4 ;
struct V_1 * V_2 ;
struct V_72 * V_103 ;
struct V_120 * V_121 ;
T_3 V_89 ;
V_4 = V_6 -> V_122 ;
V_2 = & V_4 -> V_2 ;
F_3 ( & V_2 -> V_7 ) ;
if ( F_26 ( V_11 ) == - V_123 )
goto V_124;
if ( F_37 ( V_11 ) )
goto V_19;
V_103 = F_9 ( V_11 , sizeof( * V_103 ) ) ;
if ( ! V_103 )
goto V_19;
if ( F_10 ( V_103 -> V_110 ) == V_111 ) {
if ( F_40 ( V_11 ) < sizeof( struct V_104 ) +
sizeof( * V_103 ) + sizeof( * V_121 ) )
goto V_19;
V_121 = (struct V_120 * ) ( V_103 + 1 ) ;
V_89 = F_44 ( & V_121 -> V_125 ) ;
if ( V_6 -> V_86 . V_89 == - 1 )
V_6 -> V_86 . V_89 = V_89 ;
else if ( V_6 -> V_86 . V_89 != V_89 ) {
F_8 ( V_2 , L_26
L_27 ,
V_6 -> V_86 . V_40 , V_89 ) ;
V_4 -> V_8 . V_9 ( V_6 ) ;
V_119 = V_4 -> V_8 . V_92 ( V_4 ,
V_6 -> V_86 . V_40 ) ;
if ( V_119 ) {
V_119 -> V_58 = V_2 -> V_58 ;
V_4 -> V_8 . V_62 ( V_119 ) ;
}
goto V_124;
}
V_6 -> V_58 = V_2 -> V_58 ;
V_4 -> V_8 . V_62 ( V_6 ) ;
} else if ( F_10 ( V_103 -> V_110 ) == V_112 ) {
F_8 ( V_2 , L_28 ,
V_103 -> V_113 , V_103 -> V_114 ) ;
V_4 -> V_8 . V_9 ( V_6 ) ;
} else {
F_8 ( V_2 , L_29 ,
F_10 ( V_103 -> V_110 ) ) ;
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
V_11 = F_31 ( V_4 , sizeof( struct V_72 ) +
sizeof( struct V_128 ) ) ;
if ( ! V_11 )
return - V_94 ;
if ( ! V_4 -> V_8 . V_75 ( V_4 , V_6 -> V_86 . V_40 , V_11 , V_129 ,
F_43 , V_6 ,
3 * V_4 -> V_78 ) )
return - V_94 ;
F_47 ( & V_6 -> V_126 ) ;
return 0 ;
}
static int F_16 ( struct V_3 * V_4 , struct V_25 * V_26 )
{
struct V_5 * V_6 ;
V_6 = V_4 -> V_8 . V_92 ( V_4 , V_26 -> V_40 ) ;
if ( ! V_6 )
return - V_94 ;
V_6 -> V_58 = 0 ;
return F_46 ( V_4 , V_6 ) ;
}
void F_48 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = & V_4 -> V_2 ;
if ( V_2 -> V_48 )
F_49 ( & V_2 -> V_68 ) ;
F_1 ( V_2 ) ;
}
void F_50 ( struct V_3 * V_4 )
{
F_48 ( V_4 ) ;
V_4 -> V_8 . V_130 () ;
}
int F_51 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
if ( ! V_4 -> V_8 . V_131 )
V_4 -> V_8 . V_131 = F_23 ;
if ( ! V_4 -> V_8 . V_132 )
V_4 -> V_8 . V_132 = F_48 ;
if ( ! V_4 -> V_8 . V_133 )
V_4 -> V_8 . V_133 = F_50 ;
if ( ! V_4 -> V_8 . V_134 )
V_4 -> V_8 . V_134 = F_20 ;
V_2 = & V_4 -> V_2 ;
F_52 ( & V_2 -> V_68 , F_35 ) ;
F_53 ( & V_2 -> V_7 ) ;
F_54 ( & V_2 -> V_135 ) ;
V_2 -> V_136 = V_4 ;
return 0 ;
}
