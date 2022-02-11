static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
V_4 = F_2 ( V_2 ) ;
F_3 () ;
F_4 (rdata, &disc->rports, peers) {
if ( F_5 ( & V_6 -> V_7 ) ) {
F_6 ( V_6 ) ;
F_7 ( & V_6 -> V_7 , V_8 ) ;
}
}
F_8 () ;
}
static void F_9 ( struct V_1 * V_2 , struct V_9 * V_10 )
{
struct V_3 * V_4 ;
struct V_11 * V_12 ;
struct V_13 * V_14 ;
struct V_15 V_16 ;
unsigned int V_17 ;
int V_18 = 0 ;
enum V_19 V_20 ;
enum V_21 V_22 ;
F_10 ( V_23 ) ;
struct V_24 * V_25 , * V_26 ;
V_4 = F_2 ( V_2 ) ;
F_11 ( V_2 , L_1 ) ;
V_12 = F_12 ( V_10 , sizeof( * V_12 ) ) ;
if ( ! V_12 )
goto V_27;
if ( V_12 -> V_28 != sizeof( * V_14 ) )
goto V_27;
V_17 = F_13 ( V_12 -> V_29 ) ;
if ( V_17 < sizeof( * V_12 ) )
goto V_27;
V_12 = F_12 ( V_10 , V_17 ) ;
if ( ! V_12 )
goto V_27;
V_17 -= sizeof( * V_12 ) ;
if ( V_17 % sizeof( * V_14 ) )
goto V_27;
for ( V_14 = ( void * ) ( V_12 + 1 ) ; V_17 > 0 ; V_17 -= sizeof( * V_14 ) , V_14 ++ ) {
V_20 = V_14 -> V_30 >> V_31 ;
V_20 &= V_32 ;
V_22 = V_14 -> V_30 >> V_33 ;
V_22 &= V_34 ;
switch ( V_22 ) {
case V_35 :
F_11 ( V_2 , L_2
L_3 , F_14 ( V_14 -> V_36 ) ) ;
V_25 = F_15 ( sizeof( * V_25 ) , V_37 ) ;
if ( ! V_25 ) {
V_18 = 1 ;
break;
}
V_25 -> V_38 = V_4 ;
V_25 -> V_39 = F_14 ( V_14 -> V_36 ) ;
F_16 ( & V_25 -> V_40 , & V_23 ) ;
break;
case V_41 :
case V_42 :
case V_43 :
default:
F_11 ( V_2 , L_4 , V_22 ) ;
V_18 = 1 ;
break;
}
}
F_17 ( V_10 , V_44 , NULL ) ;
F_18 (dp, next, &disc_ports, peers) {
F_19 ( & V_25 -> V_40 ) ;
if ( ! V_18 )
V_18 = F_20 ( V_4 , V_25 ) ;
F_21 ( V_25 ) ;
}
if ( V_18 ) {
F_11 ( V_2 , L_5 ) ;
F_22 ( V_2 ) ;
} else {
F_11 ( V_2 , L_6
L_7 ,
V_18 , V_4 -> V_45 , V_2 -> V_46 ) ;
}
F_23 ( V_10 ) ;
return;
V_27:
F_11 ( V_2 , L_8 ) ;
V_16 . V_47 = V_48 ;
V_16 . V_49 = V_50 ;
F_17 ( V_10 , V_51 , & V_16 ) ;
F_23 ( V_10 ) ;
}
static void F_24 ( struct V_3 * V_4 , struct V_9 * V_10 )
{
T_1 V_52 ;
struct V_1 * V_2 = & V_4 -> V_2 ;
V_52 = F_25 ( V_10 ) ;
switch ( V_52 ) {
case V_53 :
F_26 ( & V_2 -> V_54 ) ;
F_9 ( V_2 , V_10 ) ;
F_27 ( & V_2 -> V_54 ) ;
break;
default:
F_11 ( V_2 , L_9
L_10 , V_52 ) ;
F_23 ( V_10 ) ;
break;
}
}
static void F_22 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_55 )
return;
F_11 ( V_2 , L_11 ) ;
V_2 -> V_56 = 1 ;
if ( V_2 -> V_46 )
return;
V_2 -> V_57 = ( V_2 -> V_57 + 2 ) | 1 ;
V_2 -> V_58 = 0 ;
F_28 ( V_2 ) ;
}
static void F_29 ( void (* V_55)( struct V_3 * ,
enum V_59 ) ,
struct V_3 * V_4 )
{
struct V_1 * V_2 = & V_4 -> V_2 ;
F_26 ( & V_2 -> V_54 ) ;
V_2 -> V_55 = V_55 ;
F_22 ( V_2 ) ;
F_27 ( & V_2 -> V_54 ) ;
}
static void F_30 ( struct V_1 * V_2 , enum V_59 V_60 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 ;
F_11 ( V_2 , L_12 ) ;
V_2 -> V_46 = 0 ;
if ( V_2 -> V_56 ) {
F_22 ( V_2 ) ;
return;
}
F_3 () ;
F_4 (rdata, &disc->rports, peers) {
if ( ! F_5 ( & V_6 -> V_7 ) )
continue;
if ( V_6 -> V_57 ) {
if ( V_6 -> V_57 == V_2 -> V_57 )
F_31 ( V_6 ) ;
else
F_6 ( V_6 ) ;
}
F_7 ( & V_6 -> V_7 , V_8 ) ;
}
F_8 () ;
F_27 ( & V_2 -> V_54 ) ;
V_2 -> V_55 ( V_4 , V_60 ) ;
F_26 ( & V_2 -> V_54 ) ;
}
static void F_32 ( struct V_1 * V_2 , struct V_9 * V_10 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_61 = 0 ;
F_11 ( V_2 , L_13 ,
F_33 ( V_10 ) , V_2 -> V_58 ,
V_62 ) ;
if ( ! V_10 || F_33 ( V_10 ) == - V_63 ) {
if ( V_2 -> V_58 < V_62 ) {
if ( ! V_10 )
V_61 = F_34 ( V_64 ) ;
else {
V_61 = F_34 ( V_4 -> V_65 ) ;
if ( ! V_2 -> V_58 )
V_61 /= 4 ;
}
V_2 -> V_58 ++ ;
F_35 ( & V_2 -> V_66 , V_61 ) ;
} else
F_30 ( V_2 , V_67 ) ;
} else if ( F_33 ( V_10 ) == - V_68 ) {
V_2 -> V_46 = 0 ;
}
}
static void F_28 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_36 ( ! F_37 ( V_4 ) ) ;
V_2 -> V_46 = 1 ;
V_2 -> V_56 = 0 ;
V_2 -> V_69 = 0 ;
V_2 -> V_70 = 0 ;
V_10 = F_38 ( V_4 ,
sizeof( struct V_71 ) +
sizeof( struct V_72 ) ) ;
if ( ! V_10 )
goto V_73;
if ( V_4 -> V_74 . V_75 ( V_4 , 0 , V_10 ,
V_76 ,
V_77 ,
V_2 , 3 * V_4 -> V_78 ) )
return;
V_73:
F_32 ( V_2 , NULL ) ;
}
static int F_39 ( struct V_1 * V_2 , void * V_79 , T_2 V_17 )
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
V_2 -> V_70 ++ ;
V_82 = V_79 ;
V_83 = V_17 ;
V_81 = (struct V_80 * ) V_82 ;
V_84 = V_2 -> V_69 ;
V_2 -> V_69 = 0 ;
if ( V_84 ) {
F_36 ( V_84 >= sizeof( * V_81 ) ) ;
V_83 = sizeof( * V_81 ) - V_84 ;
F_36 ( V_83 <= 0 ) ;
F_36 ( V_83 >= sizeof( * V_81 ) ) ;
if ( V_83 > V_17 )
V_83 = V_17 ;
V_81 = & V_2 -> V_87 ;
memcpy ( ( char * ) V_81 + V_84 , V_82 , V_83 ) ;
V_82 -= V_84 ;
V_17 += V_84 ;
V_83 += V_84 ;
V_2 -> V_69 = ( unsigned char ) V_83 ;
if ( V_83 == sizeof( * V_81 ) )
V_2 -> V_69 = 0 ;
}
while ( V_83 >= sizeof( * V_81 ) ) {
V_86 . V_39 = F_14 ( V_81 -> V_88 ) ;
V_86 . V_89 = F_40 ( V_81 -> V_90 ) ;
if ( V_86 . V_39 != V_4 -> V_39 &&
V_86 . V_89 != V_4 -> V_91 ) {
V_6 = F_41 ( V_4 , V_86 . V_39 ) ;
if ( V_6 ) {
V_6 -> V_86 . V_89 = V_86 . V_89 ;
V_6 -> V_57 = V_2 -> V_57 ;
} else {
F_42 ( V_92 L_14
L_15
L_3 , V_86 . V_39 ) ;
error = - V_93 ;
}
}
if ( V_81 -> V_94 & V_95 ) {
F_30 ( V_2 , V_96 ) ;
V_17 = 0 ;
break;
}
V_17 -= sizeof( * V_81 ) ;
V_82 += sizeof( * V_81 ) ;
V_81 = (struct V_80 * ) V_82 ;
V_83 = V_17 ;
}
if ( error == 0 && V_17 > 0 && V_17 < sizeof( * V_81 ) ) {
if ( V_81 != & V_2 -> V_87 ) {
F_11 ( V_2 , L_16
L_17 ) ;
memcpy ( & V_2 -> V_87 , V_81 , V_17 ) ;
}
V_2 -> V_69 = ( unsigned char ) V_17 ;
}
return error ;
}
static void F_43 ( struct V_97 * V_98 )
{
struct V_1 * V_2 = F_44 ( V_98 ,
struct V_1 ,
V_66 . V_98 ) ;
F_26 ( & V_2 -> V_54 ) ;
F_28 ( V_2 ) ;
F_27 ( & V_2 -> V_54 ) ;
}
static void V_77 ( struct V_99 * V_100 , struct V_9 * V_10 ,
void * V_101 )
{
struct V_1 * V_2 = V_101 ;
struct V_71 * V_102 ;
struct V_103 * V_104 ;
enum V_59 V_60 = V_105 ;
unsigned int V_106 ;
unsigned int V_17 ;
int error = 0 ;
F_26 ( & V_2 -> V_54 ) ;
F_11 ( V_2 , L_18 ) ;
if ( F_45 ( V_10 ) ) {
F_32 ( V_2 , V_10 ) ;
F_27 ( & V_2 -> V_54 ) ;
return;
}
F_36 ( ! F_46 ( V_10 ) ) ;
V_104 = F_47 ( V_10 ) ;
V_17 = F_48 ( V_10 ) - sizeof( * V_104 ) ;
V_106 = F_13 ( V_104 -> V_107 ) ;
if ( F_49 ( V_10 ) == V_108 && V_106 == 0 && V_2 -> V_70 == 0 ) {
V_102 = F_12 ( V_10 , sizeof( * V_102 ) ) ;
if ( ! V_102 ) {
F_11 ( V_2 , L_19 ,
F_48 ( V_10 ) ) ;
V_60 = V_67 ;
} else if ( F_13 ( V_102 -> V_109 ) == V_110 ) {
V_17 -= sizeof( * V_102 ) ;
error = F_39 ( V_2 , V_102 + 1 , V_17 ) ;
} else if ( F_13 ( V_102 -> V_109 ) == V_111 ) {
F_11 ( V_2 , L_20
L_21 , V_102 -> V_112 ,
V_102 -> V_113 ) ;
V_60 = V_67 ;
if ( V_102 -> V_112 == V_114 &&
V_102 -> V_113 == V_115 )
V_60 = V_96 ;
} else {
F_11 ( V_2 , L_22
L_23 , F_13 ( V_102 -> V_109 ) ) ;
V_60 = V_67 ;
}
} else if ( F_49 ( V_10 ) == V_116 && V_106 == V_2 -> V_70 ) {
error = F_39 ( V_2 , V_104 + 1 , V_17 ) ;
} else {
F_11 ( V_2 , L_24
L_25 ,
V_106 , V_2 -> V_70 , F_49 ( V_10 ) , F_50 ( V_10 ) ) ;
V_60 = V_67 ;
}
if ( error )
F_32 ( V_2 , V_10 ) ;
else if ( V_60 != V_105 )
F_30 ( V_2 , V_60 ) ;
F_23 ( V_10 ) ;
F_27 ( & V_2 -> V_54 ) ;
}
static void F_51 ( struct V_99 * V_100 , struct V_9 * V_10 ,
void * V_117 )
{
struct V_5 * V_6 = V_117 ;
struct V_5 * V_118 ;
struct V_3 * V_4 ;
struct V_1 * V_2 ;
struct V_71 * V_102 ;
struct V_119 * V_120 ;
T_3 V_89 ;
V_4 = V_6 -> V_121 ;
V_2 = & V_4 -> V_2 ;
if ( F_33 ( V_10 ) == - V_68 )
goto V_122;
if ( F_45 ( V_10 ) )
goto V_18;
V_102 = F_12 ( V_10 , sizeof( * V_102 ) ) ;
if ( ! V_102 )
goto V_18;
if ( F_13 ( V_102 -> V_109 ) == V_110 ) {
if ( F_48 ( V_10 ) < sizeof( struct V_103 ) +
sizeof( * V_102 ) + sizeof( * V_120 ) )
goto V_18;
V_120 = (struct V_119 * ) ( V_102 + 1 ) ;
V_89 = F_52 ( & V_120 -> V_123 ) ;
F_26 ( & V_6 -> V_124 ) ;
if ( V_6 -> V_86 . V_89 == - 1 )
V_6 -> V_86 . V_89 = V_89 ;
else if ( V_6 -> V_86 . V_89 != V_89 ) {
F_11 ( V_2 , L_26
L_27 ,
V_6 -> V_86 . V_39 , V_89 ) ;
F_27 ( & V_6 -> V_124 ) ;
F_6 ( V_6 ) ;
F_26 ( & V_4 -> V_2 . V_54 ) ;
V_118 = F_41 ( V_4 , V_6 -> V_86 . V_39 ) ;
F_27 ( & V_4 -> V_2 . V_54 ) ;
if ( V_118 ) {
V_118 -> V_57 = V_2 -> V_57 ;
F_31 ( V_118 ) ;
}
goto V_122;
}
V_6 -> V_57 = V_2 -> V_57 ;
F_27 ( & V_6 -> V_124 ) ;
F_31 ( V_6 ) ;
} else if ( F_13 ( V_102 -> V_109 ) == V_111 ) {
F_11 ( V_2 , L_28 ,
V_102 -> V_112 , V_102 -> V_113 ) ;
F_6 ( V_6 ) ;
} else {
F_11 ( V_2 , L_29 ,
F_13 ( V_102 -> V_109 ) ) ;
V_18:
F_26 ( & V_2 -> V_54 ) ;
F_22 ( V_2 ) ;
F_27 ( & V_2 -> V_54 ) ;
}
V_122:
F_7 ( & V_6 -> V_7 , V_8 ) ;
}
static int F_53 ( struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_9 * V_10 ;
V_10 = F_38 ( V_4 , sizeof( struct V_71 ) +
sizeof( struct V_125 ) ) ;
if ( ! V_10 )
return - V_93 ;
if ( ! V_4 -> V_74 . V_75 ( V_4 , V_6 -> V_86 . V_39 , V_10 , V_126 ,
F_51 , V_6 ,
3 * V_4 -> V_78 ) )
return - V_93 ;
F_54 ( & V_6 -> V_7 ) ;
return 0 ;
}
static int F_20 ( struct V_3 * V_4 , struct V_24 * V_25 )
{
struct V_5 * V_6 ;
V_6 = F_41 ( V_4 , V_25 -> V_39 ) ;
if ( ! V_6 )
return - V_93 ;
V_6 -> V_57 = 0 ;
return F_53 ( V_4 , V_6 ) ;
}
static void F_55 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = & V_4 -> V_2 ;
if ( V_2 -> V_46 )
F_56 ( & V_2 -> V_66 ) ;
F_1 ( V_2 ) ;
}
static void F_57 ( struct V_3 * V_4 )
{
F_55 ( V_4 ) ;
F_58 () ;
}
void F_59 ( struct V_3 * V_4 , void * V_127 )
{
struct V_1 * V_2 = & V_4 -> V_2 ;
if ( ! V_4 -> V_74 . V_128 )
V_4 -> V_74 . V_128 = F_29 ;
if ( ! V_4 -> V_74 . V_129 )
V_4 -> V_74 . V_129 = F_55 ;
if ( ! V_4 -> V_74 . V_130 )
V_4 -> V_74 . V_130 = F_57 ;
if ( ! V_4 -> V_74 . V_131 )
V_4 -> V_74 . V_131 = F_24 ;
V_2 = & V_4 -> V_2 ;
V_2 -> V_127 = V_127 ;
}
void F_60 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = & V_4 -> V_2 ;
F_61 ( & V_2 -> V_66 , F_43 ) ;
F_62 ( & V_2 -> V_54 ) ;
F_63 ( & V_2 -> V_132 ) ;
}
