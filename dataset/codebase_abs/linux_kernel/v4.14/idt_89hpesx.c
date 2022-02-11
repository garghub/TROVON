static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
T_1 V_5 ;
T_2 V_6 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_4 -> V_8 ; V_7 ++ ) {
V_6 = V_4 -> V_6 | V_9 ;
if ( V_7 == 0 )
V_6 |= V_10 ;
if ( V_7 == V_4 -> V_8 - 1 )
V_6 |= V_11 ;
V_5 = F_2 ( V_12 , V_2 -> V_13 , V_6 ,
V_4 -> V_14 [ V_7 ] ) ;
if ( V_5 != 0 )
return ( int ) V_5 ;
}
return 0 ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_1 V_5 ;
T_2 V_6 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_4 -> V_8 ; V_7 ++ ) {
V_6 = V_4 -> V_6 | V_9 ;
if ( V_7 == 0 )
V_6 |= V_10 ;
if ( V_7 == V_4 -> V_8 - 1 )
V_6 |= V_11 ;
V_5 = F_2 ( V_15 , V_2 -> V_13 , V_6 ) ;
if ( V_5 < 0 )
return ( int ) V_5 ;
V_4 -> V_14 [ V_7 ] = ( T_2 ) V_5 ;
}
return 0 ;
}
static int F_4 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
T_1 V_5 ;
T_2 V_6 ;
int V_7 , V_16 ;
V_16 = V_4 -> V_8 - ( V_4 -> V_8 % 2 ) ;
for ( V_7 = 0 ; V_7 < V_16 ; V_7 += 2 ) {
V_6 = V_4 -> V_6 | V_17 ;
if ( V_7 == 0 )
V_6 |= V_10 ;
if ( V_7 == V_16 - 2 )
V_6 |= V_11 ;
V_5 = F_2 ( V_18 , V_2 -> V_13 , V_6 ,
* ( V_19 * ) & V_4 -> V_14 [ V_7 ] ) ;
if ( V_5 != 0 )
return ( int ) V_5 ;
}
if ( V_4 -> V_8 != V_16 ) {
V_6 = V_4 -> V_6 | V_9 | V_11 ;
if ( V_7 == 0 )
V_6 |= V_10 ;
V_5 = F_2 ( V_12 , V_2 -> V_13 , V_6 ,
V_4 -> V_14 [ V_7 ] ) ;
if ( V_5 != 0 )
return ( int ) V_5 ;
}
return 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_1 V_5 ;
T_2 V_6 ;
int V_7 , V_16 ;
V_16 = V_4 -> V_8 - ( V_4 -> V_8 % 2 ) ;
for ( V_7 = 0 ; V_7 < V_16 ; V_7 += 2 ) {
V_6 = V_4 -> V_6 | V_17 ;
if ( V_7 == 0 )
V_6 |= V_10 ;
if ( V_7 == V_16 - 2 )
V_6 |= V_11 ;
V_5 = F_2 ( V_20 , V_2 -> V_13 , V_6 ) ;
if ( V_5 < 0 )
return ( int ) V_5 ;
* ( V_19 * ) & V_4 -> V_14 [ V_7 ] = ( V_19 ) V_5 ;
}
if ( V_4 -> V_8 != V_16 ) {
V_6 = V_4 -> V_6 | V_9 | V_11 ;
if ( V_7 == 0 )
V_6 |= V_10 ;
V_5 = F_2 ( V_15 , V_2 -> V_13 , V_6 ) ;
if ( V_5 < 0 )
return ( int ) V_5 ;
V_4 -> V_14 [ V_7 ] = ( T_2 ) V_5 ;
}
return 0 ;
}
static int F_6 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
T_2 V_6 ;
if ( V_4 -> V_8 > V_21 )
return - V_22 ;
V_6 = V_4 -> V_6 | V_23 | V_10 | V_11 ;
return F_2 ( V_24 , V_2 -> V_13 , V_6 , V_4 -> V_8 ,
V_4 -> V_14 ) ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_1 V_5 ;
T_2 V_6 ;
if ( V_4 -> V_8 > V_21 )
return - V_22 ;
V_6 = V_4 -> V_6 | V_23 | V_10 | V_11 ;
V_5 = F_2 ( V_25 , V_2 -> V_13 , V_6 , V_4 -> V_14 ) ;
if ( V_5 != V_4 -> V_8 )
return ( V_5 < 0 ? V_5 : - V_26 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
T_2 V_6 , V_27 [ V_21 + 1 ] ;
if ( V_4 -> V_8 > V_21 )
return - V_22 ;
V_27 [ 0 ] = V_4 -> V_8 ;
memcpy ( & V_27 [ 1 ] , V_4 -> V_14 , V_4 -> V_8 ) ;
V_6 = V_4 -> V_6 | V_23 | V_10 | V_11 ;
return F_2 ( V_28 , V_2 -> V_13 , V_6 ,
V_4 -> V_8 + 1 , V_27 ) ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_2 V_6 , V_27 [ V_21 + 1 ] ;
T_1 V_5 ;
if ( V_4 -> V_8 > V_21 )
return - V_22 ;
V_6 = V_4 -> V_6 | V_23 | V_10 | V_11 ;
V_5 = F_2 ( V_29 , V_2 -> V_13 , V_6 ,
V_4 -> V_8 + 1 , V_27 ) ;
if ( V_5 != V_4 -> V_8 + 1 )
return ( V_5 < 0 ? V_5 : - V_26 ) ;
if ( V_27 [ 0 ] != V_4 -> V_8 )
return - V_26 ;
memcpy ( V_4 -> V_14 , & V_27 [ 1 ] , V_4 -> V_8 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , V_19 V_30 ,
T_2 * V_14 )
{
struct V_31 * V_32 = & V_2 -> V_13 -> V_32 ;
struct V_33 V_34 ;
struct V_3 V_35 ;
int V_36 , V_37 ;
V_35 . V_6 = V_2 -> V_38 | V_39 ;
V_35 . V_14 = ( T_2 * ) & V_34 ;
V_37 = V_40 ;
do {
V_35 . V_8 = V_41 ;
V_34 . V_42 = V_2 -> V_43 | V_44 ;
V_34 . V_45 = V_2 -> V_45 ;
V_34 . V_30 = F_11 ( V_30 ) ;
V_36 = V_2 -> V_46 ( V_2 , & V_35 ) ;
if ( V_36 != 0 ) {
F_12 ( V_32 , L_1 ,
V_30 ) ;
break;
}
V_35 . V_8 = V_47 ;
V_36 = V_2 -> V_48 ( V_2 , & V_35 ) ;
if ( V_36 != 0 ) {
F_12 ( V_32 , L_2 ,
V_30 ) ;
break;
}
if ( V_37 && ( V_34 . V_42 & V_49 ) ) {
F_13 ( V_32 , L_3 ,
V_50 ) ;
F_14 ( V_50 ) ;
continue;
}
if ( V_34 . V_42 & ( V_49 | V_51 | V_52 ) ) {
F_12 ( V_32 ,
L_4 ,
V_34 . V_42 ) ;
V_36 = - V_53 ;
break;
}
* V_14 = V_34 . V_14 ;
break;
} while ( V_37 -- );
return V_36 ;
}
static int F_15 ( struct V_1 * V_2 , V_19 V_30 , V_19 V_54 ,
const T_2 * V_14 )
{
struct V_31 * V_32 = & V_2 -> V_13 -> V_32 ;
struct V_33 V_34 ;
struct V_3 V_35 ;
int V_36 ;
V_19 V_7 ;
V_35 . V_6 = V_2 -> V_38 | V_39 ;
V_35 . V_14 = ( T_2 * ) & V_34 ;
for ( V_7 = 0 ; V_7 < V_54 ; V_7 ++ , V_30 ++ ) {
F_16 ( & V_2 -> V_55 ) ;
V_35 . V_8 = V_56 ;
V_34 . V_42 = V_2 -> V_43 | V_57 ;
V_34 . V_45 = V_2 -> V_45 ;
V_34 . V_30 = F_11 ( V_30 ) ;
V_34 . V_14 = V_14 [ V_7 ] ;
V_36 = V_2 -> V_46 ( V_2 , & V_35 ) ;
if ( V_36 != 0 ) {
F_12 ( V_32 ,
L_5 ,
V_30 , V_14 [ V_7 ] ) ;
goto V_58;
}
V_34 . V_14 = ~ V_14 [ V_7 ] ;
V_36 = F_10 ( V_2 , V_30 , & V_34 . V_14 ) ;
if ( V_36 != 0 )
goto V_58;
if ( V_34 . V_14 != V_14 [ V_7 ] ) {
F_12 ( V_32 , L_6 ,
V_34 . V_14 , V_14 [ V_7 ] ) ;
V_36 = - V_53 ;
goto V_58;
}
V_58:
F_17 ( & V_2 -> V_55 ) ;
if ( V_36 != 0 )
return V_36 ;
}
return 0 ;
}
static int F_18 ( struct V_1 * V_2 , V_19 V_30 , V_19 V_54 ,
T_2 * V_27 )
{
int V_36 ;
V_19 V_7 ;
for ( V_7 = 0 ; V_7 < V_54 ; V_7 ++ , V_30 ++ ) {
F_16 ( & V_2 -> V_55 ) ;
V_36 = F_10 ( V_2 , V_30 , & V_27 [ V_7 ] ) ;
F_17 ( & V_2 -> V_55 ) ;
if ( V_36 != 0 )
return V_36 ;
}
return 0 ;
}
static int F_19 ( struct V_1 * V_2 , V_19 V_59 ,
const T_3 V_14 )
{
struct V_31 * V_32 = & V_2 -> V_13 -> V_32 ;
struct V_60 V_61 ;
struct V_3 V_35 ;
int V_36 ;
V_35 . V_6 = V_2 -> V_38 | V_62 ;
V_35 . V_14 = ( T_2 * ) & V_61 ;
F_16 ( & V_2 -> V_55 ) ;
V_35 . V_8 = V_63 ;
V_61 . V_42 = V_2 -> V_64 | V_65 ;
V_61 . V_59 = F_11 ( V_59 ) ;
V_61 . V_14 = F_20 ( V_14 ) ;
V_36 = V_2 -> V_46 ( V_2 , & V_35 ) ;
if ( V_36 != 0 ) {
F_12 ( V_32 , L_7 ,
F_21 ( V_59 ) , V_14 ) ;
goto V_58;
}
V_35 . V_8 = V_66 ;
V_61 . V_42 = V_2 -> V_64 | V_67 ;
V_36 = V_2 -> V_46 ( V_2 , & V_35 ) ;
if ( V_36 != 0 ) {
F_12 ( V_32 , L_8 ,
F_21 ( V_59 ) ) ;
goto V_58;
}
V_35 . V_8 = V_68 ;
V_36 = V_2 -> V_48 ( V_2 , & V_35 ) ;
if ( V_36 != 0 ) {
F_12 ( V_32 , L_9 ,
F_21 ( V_59 ) ) ;
goto V_58;
}
if ( V_61 . V_42 & ( V_69 | V_70 ) ) {
F_12 ( V_32 , L_10 ) ;
V_36 = - V_53 ;
goto V_58;
}
V_58:
F_17 ( & V_2 -> V_55 ) ;
return V_36 ;
}
static int F_22 ( struct V_1 * V_2 , V_19 V_59 , T_3 * V_14 )
{
struct V_31 * V_32 = & V_2 -> V_13 -> V_32 ;
struct V_60 V_61 ;
struct V_3 V_35 ;
int V_36 ;
V_35 . V_6 = V_2 -> V_38 | V_62 ;
V_35 . V_14 = ( T_2 * ) & V_61 ;
F_16 ( & V_2 -> V_55 ) ;
V_35 . V_8 = V_66 ;
V_61 . V_42 = V_2 -> V_64 | V_67 ;
V_61 . V_59 = F_11 ( V_59 ) ;
V_36 = V_2 -> V_46 ( V_2 , & V_35 ) ;
if ( V_36 != 0 ) {
F_12 ( V_32 , L_8 ,
F_21 ( V_59 ) ) ;
goto V_58;
}
V_35 . V_8 = V_68 ;
V_36 = V_2 -> V_48 ( V_2 , & V_35 ) ;
if ( V_36 != 0 ) {
F_12 ( V_32 , L_11 ,
F_21 ( V_59 ) ) ;
goto V_58;
}
if ( V_61 . V_42 & ( V_69 | V_70 ) ) {
F_12 ( V_32 , L_10 ) ;
V_36 = - V_53 ;
goto V_58;
}
* V_14 = F_23 ( V_61 . V_14 ) ;
V_58:
F_17 ( & V_2 -> V_55 ) ;
return V_36 ;
}
static T_4 F_24 ( struct V_71 * V_72 , struct V_73 * V_74 ,
struct V_75 * V_76 ,
char * V_27 , T_5 V_77 , T_6 V_78 )
{
struct V_1 * V_2 ;
int V_36 ;
V_2 = F_25 ( F_26 ( V_74 ) ) ;
V_36 = F_15 ( V_2 , ( V_19 ) V_77 , ( V_19 ) V_78 , ( T_2 * ) V_27 ) ;
return ( V_36 != 0 ? V_36 : V_78 ) ;
}
static T_4 F_27 ( struct V_71 * V_72 , struct V_73 * V_74 ,
struct V_75 * V_76 ,
char * V_27 , T_5 V_77 , T_6 V_78 )
{
struct V_1 * V_2 ;
int V_36 ;
V_2 = F_25 ( F_26 ( V_74 ) ) ;
V_36 = F_18 ( V_2 , ( V_19 ) V_77 , ( V_19 ) V_78 , ( T_2 * ) V_27 ) ;
return ( V_36 != 0 ? V_36 : V_78 ) ;
}
static T_4 F_28 ( struct V_71 * V_79 , const char T_7 * V_80 ,
T_6 V_78 , T_5 * V_81 )
{
struct V_1 * V_2 = V_79 -> V_82 ;
char * V_83 , * V_84 , * V_85 ;
int V_36 , V_86 , V_87 ;
T_3 V_59 , V_88 ;
char * V_27 ;
V_27 = F_29 ( V_78 + 1 , V_89 ) ;
if ( ! V_27 )
return - V_90 ;
V_36 = F_30 ( V_27 , V_78 , V_81 , V_80 , V_78 ) ;
if ( V_36 < 0 )
goto V_91;
V_27 [ V_78 ] = 0 ;
V_83 = F_31 ( V_27 , V_78 , ':' ) ;
if ( V_83 != NULL ) {
V_86 = V_83 - V_27 ;
V_84 =
F_29 ( sizeof( char ) * ( V_86 + 1 ) , V_89 ) ;
if ( V_84 == NULL ) {
V_36 = - V_90 ;
goto V_91;
}
strncpy ( V_84 , V_27 , V_86 ) ;
V_84 [ V_86 ] = '\0' ;
V_85 = V_83 + 1 ;
V_87 = F_32 ( V_85 , V_78 - V_86 ) ;
} else {
V_84 = ( char * ) V_27 ;
V_86 = F_32 ( V_84 , V_78 ) ;
V_85 = NULL ;
V_87 = 0 ;
}
V_36 = F_33 ( V_84 , 0 , & V_59 ) ;
if ( V_36 != 0 )
goto V_92;
if ( V_59 > V_93 || ! F_34 ( V_59 , V_94 ) ) {
V_36 = - V_22 ;
goto V_92;
}
V_2 -> V_95 = ( V_59 >> 2 ) ;
if ( V_83 != NULL ) {
V_36 = F_33 ( V_85 , 0 , & V_88 ) ;
if ( V_36 != 0 )
goto V_92;
V_36 = F_19 ( V_2 , V_2 -> V_95 , V_88 ) ;
if ( V_36 != 0 )
goto V_92;
}
V_92:
if ( V_83 != NULL )
F_35 ( V_84 ) ;
V_91:
F_35 ( V_27 ) ;
return ( V_36 != 0 ? V_36 : V_78 ) ;
}
static T_4 F_36 ( struct V_71 * V_79 , char T_7 * V_80 ,
T_6 V_78 , T_5 * V_81 )
{
struct V_1 * V_2 = V_79 -> V_82 ;
T_3 V_59 , V_88 ;
char V_27 [ V_96 ] ;
int V_36 , V_97 ;
V_36 = F_22 ( V_2 , V_2 -> V_95 , & V_88 ) ;
if ( V_36 != 0 )
return V_36 ;
V_59 = ( ( T_3 ) V_2 -> V_95 << 2 ) ;
V_97 = snprintf ( V_27 , V_96 , L_12 ,
( unsigned int ) V_59 , ( unsigned int ) V_88 ) ;
return F_37 ( V_80 , V_78 , V_81 , V_27 , V_97 ) ;
}
static void F_38 ( struct V_1 * V_2 )
{
V_2 -> V_98 = 0 ;
V_2 -> V_99 = true ;
V_2 -> V_43 = 0 ;
V_2 -> V_45 = 0 ;
}
static const struct V_100 * F_39 ( struct V_101 * V_102 )
{
const struct V_100 * V_103 = V_104 ;
const char * V_105 , * V_106 ;
char V_107 [ V_108 ] ;
int V_36 ;
V_36 = F_40 ( V_102 , L_13 , & V_105 ) ;
if ( V_36 )
return NULL ;
V_106 = strchr ( V_105 , ',' ) ;
F_41 ( V_107 , V_106 ? V_106 + 1 : V_105 , sizeof( V_107 ) ) ;
while ( V_103 -> V_109 [ 0 ] ) {
if ( strcmp ( V_107 , V_103 -> V_109 ) == 0 )
return V_103 ;
V_103 ++ ;
}
return NULL ;
}
static void F_42 ( struct V_1 * V_2 )
{
struct V_31 * V_32 = & V_2 -> V_13 -> V_32 ;
struct V_101 * V_102 ;
const struct V_100 * V_110 = NULL ;
T_3 V_111 ;
int V_36 ;
F_43 (dev, fwnode) {
V_110 = F_39 ( V_102 ) ;
if ( F_44 ( V_110 ) ) {
F_45 ( V_32 , L_14 ) ;
continue;
} else
break;
}
if ( ! V_110 ) {
F_45 ( V_32 , L_15 ) ;
F_38 ( V_2 ) ;
return;
}
V_2 -> V_98 = ( T_3 ) V_110 -> V_112 ;
V_36 = F_46 ( V_102 , L_16 , & V_111 ) ;
if ( V_36 || ( V_111 == 0 ) ) {
F_45 ( V_32 , L_17 ,
V_113 ) ;
V_2 -> V_43 = 0 ;
V_2 -> V_45 = V_113 << 1 ;
} else {
V_2 -> V_43 = V_114 ;
V_2 -> V_45 = V_111 << 1 ;
}
if ( F_47 ( V_102 , L_18 ) )
V_2 -> V_99 = true ;
else
V_2 -> V_99 = false ;
F_48 ( V_32 , L_19 ,
V_2 -> V_98 , V_2 -> V_45 ) ;
}
static struct V_1 * F_49 ( struct V_115 * V_13 )
{
struct V_1 * V_2 ;
V_2 = F_50 ( & V_13 -> V_32 , sizeof( struct V_1 ) ,
V_89 ) ;
if ( V_2 == NULL )
return F_51 ( - V_90 ) ;
V_2 -> V_13 = V_13 ;
F_52 ( V_13 , V_2 ) ;
F_42 ( V_2 ) ;
V_2 -> V_64 = V_116 ;
V_2 -> V_95 = V_117 ;
if ( F_53 ( V_13 -> V_118 , V_119 ) ) {
V_2 -> V_38 = V_120 ;
V_13 -> V_121 |= V_122 ;
} else {
V_2 -> V_38 = 0 ;
}
return V_2 ;
}
static void F_54 ( struct V_1 * V_2 )
{
F_52 ( V_2 -> V_13 , NULL ) ;
}
static int F_55 ( struct V_1 * V_2 )
{
struct V_123 * V_118 = V_2 -> V_13 -> V_118 ;
struct V_31 * V_32 = & V_2 -> V_13 -> V_32 ;
if ( F_53 ( V_118 ,
V_124 ) ) {
V_2 -> V_48 = F_7 ;
F_13 ( V_32 , L_20 ) ;
} else if ( F_53 ( V_118 ,
V_125 ) ) {
V_2 -> V_48 = F_9 ;
F_13 ( V_32 , L_21 ) ;
} else if ( F_53 ( V_118 ,
V_126 ) &&
F_53 ( V_118 ,
V_127 ) ) {
V_2 -> V_48 = F_5 ;
F_45 ( V_32 , L_22 ) ;
} else if ( F_53 ( V_118 ,
V_127 ) ) {
V_2 -> V_48 = F_3 ;
F_45 ( V_32 , L_23 ) ;
} else {
F_12 ( V_32 , L_24 ) ;
return - V_128 ;
}
if ( F_53 ( V_118 ,
V_129 ) ) {
V_2 -> V_46 = F_6 ;
F_13 ( V_32 , L_25 ) ;
} else if ( F_53 ( V_118 ,
V_130 ) ) {
V_2 -> V_46 = F_8 ;
F_13 ( V_32 , L_26 ) ;
} else if ( F_53 ( V_118 ,
V_131 ) &&
F_53 ( V_118 ,
V_132 ) ) {
V_2 -> V_46 = F_4 ;
F_45 ( V_32 , L_27 ) ;
} else if ( F_53 ( V_118 ,
V_132 ) ) {
V_2 -> V_46 = F_1 ;
F_45 ( V_32 , L_28 ) ;
} else {
F_12 ( V_32 , L_29 ) ;
return - V_128 ;
}
F_56 ( & V_2 -> V_55 ) ;
return 0 ;
}
static int F_57 ( struct V_1 * V_2 )
{
struct V_31 * V_32 = & V_2 -> V_13 -> V_32 ;
T_3 V_133 ;
int V_36 ;
V_36 = F_22 ( V_2 , V_134 , & V_133 ) ;
if ( V_36 != 0 ) {
F_12 ( V_32 , L_30 ) ;
return V_36 ;
}
if ( ( V_133 & V_135 ) != V_136 ) {
F_12 ( V_32 , L_31 , V_133 ) ;
return - V_137 ;
}
F_48 ( V_32 , L_32 ,
( V_133 & V_135 ) , ( V_133 >> 16 ) ) ;
return 0 ;
}
static int F_58 ( struct V_1 * V_2 )
{
struct V_31 * V_32 = & V_2 -> V_13 -> V_32 ;
int V_36 ;
if ( V_2 -> V_98 == 0 ) {
F_13 ( V_32 , L_33 ) ;
return 0 ;
}
V_2 -> V_138 = F_50 ( V_32 , sizeof( * V_2 -> V_138 ) , V_89 ) ;
if ( ! V_2 -> V_138 )
return - V_90 ;
memcpy ( V_2 -> V_138 , & V_139 , sizeof( * V_2 -> V_138 ) ) ;
if ( V_2 -> V_99 ) {
V_2 -> V_138 -> V_76 . V_140 &= ~ 0200 ;
V_2 -> V_138 -> V_141 = NULL ;
}
V_2 -> V_138 -> V_97 = V_2 -> V_98 ;
V_36 = F_59 ( & V_32 -> V_74 , V_2 -> V_138 ) ;
if ( V_36 != 0 ) {
F_12 ( V_32 , L_34 ) ;
return V_36 ;
}
return 0 ;
}
static void F_60 ( struct V_1 * V_2 )
{
struct V_31 * V_32 = & V_2 -> V_13 -> V_32 ;
if ( V_2 -> V_98 == 0 )
return;
F_61 ( & V_32 -> V_74 , V_2 -> V_138 ) ;
}
static void F_62 ( struct V_1 * V_2 )
{
struct V_115 * V_142 = V_2 -> V_13 ;
char V_143 [ V_144 ] ;
snprintf ( V_143 , V_144 , L_35 , V_142 -> V_118 -> V_145 , V_142 -> V_146 ) ;
V_2 -> V_147 = F_63 ( V_143 , V_148 ) ;
V_2 -> V_149 = F_64 ( V_142 -> V_109 , 0600 ,
V_2 -> V_147 , V_2 , & V_150 ) ;
}
static void F_65 ( struct V_1 * V_2 )
{
F_66 ( V_2 -> V_147 ) ;
}
static int F_67 ( struct V_115 * V_13 , const struct V_100 * V_103 )
{
struct V_1 * V_2 ;
int V_36 ;
V_2 = F_49 ( V_13 ) ;
if ( F_68 ( V_2 ) )
return F_69 ( V_2 ) ;
V_36 = F_55 ( V_2 ) ;
if ( V_36 != 0 )
goto V_151;
V_36 = F_57 ( V_2 ) ;
if ( V_36 != 0 )
goto V_151;
V_36 = F_58 ( V_2 ) ;
if ( V_36 != 0 )
goto V_151;
F_62 ( V_2 ) ;
return 0 ;
V_151:
F_54 ( V_2 ) ;
return V_36 ;
}
static int F_70 ( struct V_115 * V_13 )
{
struct V_1 * V_2 = F_71 ( V_13 ) ;
F_65 ( V_2 ) ;
F_60 ( V_2 ) ;
F_54 ( V_2 ) ;
return 0 ;
}
static int T_8 F_72 ( void )
{
if ( F_73 () )
V_148 = F_63 ( L_36 , NULL ) ;
return F_74 ( & V_152 ) ;
}
static void T_9 F_75 ( void )
{
F_66 ( V_148 ) ;
F_76 ( & V_152 ) ;
}
