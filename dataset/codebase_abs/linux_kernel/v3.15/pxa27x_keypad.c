static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_7 . V_8 ;
T_1 V_9 , V_10 ;
int error ;
error = F_2 ( V_7 , & V_9 , & V_10 ) ;
if ( error )
return error ;
if ( V_9 > V_11 || V_10 > V_12 ) {
F_3 ( V_7 , L_1 ) ;
return - V_13 ;
}
V_4 -> V_14 = V_9 ;
V_4 -> V_15 = V_10 ;
error = F_4 ( NULL , NULL ,
V_4 -> V_14 ,
V_4 -> V_15 ,
V_2 -> V_16 , V_5 ) ;
if ( error )
return error ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_7 . V_8 ;
struct V_17 * V_18 = V_7 -> V_19 ;
const T_2 * V_20 ;
unsigned short V_21 ;
unsigned int V_22 , V_23 ;
int V_24 ;
int error ;
error = F_6 ( V_18 , L_2 ,
& V_4 -> V_25 ) ;
if ( error ) {
return error == - V_13 ? 0 : error ;
}
error = F_6 ( V_18 , L_3 ,
& V_4 -> V_26 ) ;
if ( error ) {
if ( error != - V_13 )
return error ;
V_4 -> V_26 = 0 ;
}
V_4 -> V_27 = F_7 ( V_18 ,
L_4 ) ;
V_20 = F_8 ( V_18 , L_5 , & V_22 ) ;
if ( ! V_20 )
return - V_13 ;
if ( V_22 % sizeof( V_28 ) )
return - V_13 ;
V_23 = V_22 / sizeof( V_28 ) ;
if ( V_23 > V_29 )
return - V_13 ;
for ( V_24 = 0 ; V_24 < V_23 ; V_24 ++ ) {
V_21 = F_9 ( V_20 + V_24 ) ;
V_2 -> V_16 [ V_30 + V_24 ] = V_21 ;
F_10 ( V_21 , V_5 -> V_31 ) ;
}
return 0 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
const T_3 * V_20 ;
int V_24 , V_32 ;
unsigned int V_21 , V_22 ;
const char * V_33 [ 2 ] = {
L_6 , L_7 } ;
const char V_34 [] = { L_8 } ;
struct V_5 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_7 . V_8 ;
struct V_17 * V_18 = V_7 -> V_19 ;
V_32 = F_6 ( V_18 , V_34 , & V_21 ) ;
if ( V_32 == 0 ) {
unsigned short V_35 ;
V_35 = V_21 & 0xffff ;
V_4 -> V_36 = ( V_21 & 0xffff ) ;
F_10 ( V_35 , V_5 -> V_37 ) ;
V_35 = V_21 >> 16 ;
V_4 -> V_38 = V_35 ;
F_10 ( V_35 , V_5 -> V_37 ) ;
}
for ( V_24 = 0 ; V_24 < 2 ; V_24 ++ ) {
V_20 = F_8 ( V_18 , V_33 [ V_24 ] , & V_22 ) ;
if ( ! V_20 )
continue;
V_21 = F_12 ( V_20 ) ;
if ( ( ! ( V_21 & 0xffff ) || ! ( V_21 >> 16 ) ) && V_32 ) {
return V_32 ;
} else {
unsigned int V_39 = V_30 + ( V_24 << 1 ) ;
unsigned short V_40 ;
V_40 = V_21 & 0xffff ;
V_2 -> V_16 [ V_39 ] = V_40 ;
F_10 ( V_40 , V_5 -> V_31 ) ;
V_40 = V_21 >> 16 ;
V_2 -> V_16 [ V_39 + 1 ] = V_40 ;
F_10 ( V_40 , V_5 -> V_31 ) ;
if ( V_24 == 0 )
V_4 -> V_36 = - 1 ;
else
V_4 -> V_38 = - 1 ;
}
if ( V_24 == 0 )
V_4 -> V_41 = 1 ;
else
V_4 -> V_42 = 1 ;
}
V_2 -> V_43 [ 0 ] = V_4 -> V_36 ;
V_2 -> V_43 [ 1 ] = V_4 -> V_38 ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_7 . V_8 ;
struct V_17 * V_18 = V_7 -> V_19 ;
struct V_3 * V_4 ;
int error ;
V_4 = F_14 ( V_7 , sizeof( * V_4 ) , V_44 ) ;
if ( ! V_4 ) {
F_3 ( V_7 , L_9 ) ;
return - V_45 ;
}
error = F_1 ( V_2 , V_4 ) ;
if ( error ) {
F_3 ( V_7 , L_10 ) ;
return error ;
}
error = F_5 ( V_2 , V_4 ) ;
if ( error ) {
F_3 ( V_7 , L_11 ) ;
return error ;
}
error = F_11 ( V_2 , V_4 ) ;
if ( error ) {
F_3 ( V_7 , L_12 ) ;
return error ;
}
error = F_6 ( V_18 , L_13 ,
& V_4 -> V_46 ) ;
if ( error ) {
F_3 ( V_7 , L_14 ) ;
return error ;
}
V_5 -> V_47 = F_15 ( V_2 -> V_16 ) ;
V_2 -> V_4 = V_4 ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
F_16 ( V_2 -> V_5 -> V_7 . V_8 , L_15 ) ;
return - V_13 ;
}
static int F_17 ( struct V_1 * V_2 )
{
const struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_5 = V_2 -> V_5 ;
const struct V_48 * V_49 =
V_4 ? V_4 -> V_48 : NULL ;
unsigned short V_40 ;
int V_24 ;
int error ;
error = F_4 ( V_49 , NULL ,
V_4 -> V_14 ,
V_4 -> V_15 ,
V_2 -> V_16 , V_5 ) ;
if ( error )
return error ;
V_5 -> V_47 = F_15 ( V_2 -> V_16 ) ;
for ( V_24 = 0 ; V_24 < V_4 -> V_25 ; V_24 ++ ) {
V_40 = V_4 -> V_50 [ V_24 ] ;
V_2 -> V_16 [ V_30 + V_24 ] = V_40 ;
F_10 ( V_40 , V_5 -> V_31 ) ;
}
if ( V_4 -> V_41 ) {
if ( V_4 -> V_51 && V_4 -> V_52 ) {
V_40 = V_4 -> V_51 ;
V_2 -> V_16 [ V_30 + 0 ] = V_40 ;
F_10 ( V_40 , V_5 -> V_31 ) ;
V_40 = V_4 -> V_52 ;
V_2 -> V_16 [ V_30 + 1 ] = V_40 ;
F_10 ( V_40 , V_5 -> V_31 ) ;
V_2 -> V_43 [ 0 ] = - 1 ;
} else {
V_2 -> V_43 [ 0 ] = V_4 -> V_36 ;
F_10 ( V_4 -> V_36 , V_5 -> V_37 ) ;
}
}
if ( V_4 -> V_42 ) {
if ( V_4 -> V_53 && V_4 -> V_54 ) {
V_40 = V_4 -> V_53 ;
V_2 -> V_16 [ V_30 + 2 ] = V_40 ;
F_10 ( V_40 , V_5 -> V_31 ) ;
V_40 = V_4 -> V_54 ;
V_2 -> V_16 [ V_30 + 3 ] = V_40 ;
F_10 ( V_40 , V_5 -> V_31 ) ;
V_2 -> V_43 [ 1 ] = - 1 ;
} else {
V_2 -> V_43 [ 1 ] = V_4 -> V_38 ;
F_10 ( V_4 -> V_38 , V_5 -> V_37 ) ;
}
}
F_18 ( V_55 , V_5 -> V_31 ) ;
return 0 ;
}
static void F_19 ( struct V_1 * V_2 )
{
const struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_5 = V_2 -> V_5 ;
int V_56 , V_57 , V_58 = 0 ;
T_4 V_59 [ V_12 ] ;
T_4 V_60 = F_20 ( V_61 ) ;
V_58 = F_21 ( V_60 ) ;
memset ( V_59 , 0 , sizeof( V_59 ) ) ;
if ( V_58 == 0 )
goto V_62;
if ( V_58 == 1 ) {
V_57 = F_22 ( V_60 ) ;
V_56 = F_23 ( V_60 ) ;
if ( V_57 >= V_4 -> V_15 ||
V_56 >= V_4 -> V_14 )
goto V_62;
V_59 [ V_57 ] = ( 1 << V_56 ) ;
goto V_62;
}
if ( V_58 > 1 ) {
T_4 V_63 = F_20 ( V_64 ) ;
T_4 V_65 = F_20 ( V_66 ) ;
T_4 V_67 = F_20 ( V_68 ) ;
T_4 V_69 = F_20 ( V_70 ) ;
V_59 [ 0 ] = V_63 & V_71 ;
V_59 [ 1 ] = ( V_63 >> 16 ) & V_71 ;
V_59 [ 2 ] = V_65 & V_71 ;
V_59 [ 3 ] = ( V_65 >> 16 ) & V_71 ;
V_59 [ 4 ] = V_67 & V_71 ;
V_59 [ 5 ] = ( V_67 >> 16 ) & V_71 ;
V_59 [ 6 ] = V_69 & V_71 ;
V_59 [ 7 ] = ( V_69 >> 16 ) & V_71 ;
}
V_62:
for ( V_57 = 0 ; V_57 < V_4 -> V_15 ; V_57 ++ ) {
T_4 V_72 ;
int V_21 ;
V_72 = V_2 -> V_73 [ V_57 ] ^ V_59 [ V_57 ] ;
if ( V_72 == 0 )
continue;
for ( V_56 = 0 ; V_56 < V_4 -> V_14 ; V_56 ++ ) {
if ( ( V_72 & ( 1 << V_56 ) ) == 0 )
continue;
V_21 = F_24 ( V_56 , V_57 , V_2 -> V_74 ) ;
F_25 ( V_5 , V_75 , V_76 , V_21 ) ;
F_26 ( V_5 , V_2 -> V_16 [ V_21 ] ,
V_59 [ V_57 ] & ( 1 << V_56 ) ) ;
}
}
F_27 ( V_5 ) ;
memcpy ( V_2 -> V_73 , V_59 , sizeof( V_59 ) ) ;
}
static inline int F_28 ( T_4 V_77 )
{
if ( V_77 & V_78 )
return ( V_77 & 0xff ) + 0x7f ;
else if ( V_77 & V_79 )
return ( V_77 & 0xff ) - 0x7f - 0xff ;
else
return ( V_77 & 0xff ) - 0x7f ;
}
static void F_29 ( struct V_1 * V_2 , int V_80 , int V_81 )
{
struct V_5 * V_7 = V_2 -> V_5 ;
if ( V_81 == 0 )
return;
if ( V_2 -> V_43 [ V_80 ] == - 1 ) {
int V_21 = V_30 + 2 * V_80 + ( V_81 > 0 ? 0 : 1 ) ;
unsigned char V_40 = V_2 -> V_16 [ V_21 ] ;
F_25 ( V_7 , V_75 , V_76 , V_21 ) ;
F_26 ( V_7 , V_40 , 1 ) ;
F_27 ( V_7 ) ;
F_25 ( V_7 , V_75 , V_76 , V_21 ) ;
F_26 ( V_7 , V_40 , 0 ) ;
F_27 ( V_7 ) ;
} else {
F_30 ( V_7 , V_2 -> V_43 [ V_80 ] , V_81 ) ;
F_27 ( V_7 ) ;
}
}
static void F_31 ( struct V_1 * V_2 )
{
const struct V_3 * V_4 = V_2 -> V_4 ;
T_4 V_77 ;
V_77 = F_20 ( V_82 ) ;
F_32 ( V_82 , V_83 ) ;
if ( V_4 -> V_41 )
F_29 ( V_2 , 0 , F_28 ( V_77 ) ) ;
if ( V_4 -> V_42 )
F_29 ( V_2 , 1 , F_28 ( V_77 >> 16 ) ) ;
}
static void F_33 ( struct V_1 * V_2 )
{
const struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_5 = V_2 -> V_5 ;
unsigned int V_59 ;
T_4 V_84 , V_72 ;
int V_24 ;
V_84 = F_20 ( V_85 ) ;
if ( V_4 -> V_41 || V_4 -> V_42 )
F_31 ( V_2 ) ;
if ( V_4 -> V_27 )
V_59 = ~ F_34 ( V_84 ) & V_2 -> V_26 ;
else
V_59 = F_34 ( V_84 ) & V_2 -> V_26 ;
V_72 = V_2 -> V_86 ^ V_59 ;
if ( V_72 == 0 )
return;
for ( V_24 = 0 ; V_24 < V_4 -> V_25 ; V_24 ++ ) {
if ( V_72 & ( 1 << V_24 ) ) {
int V_21 = V_30 + V_24 ;
F_25 ( V_5 , V_75 , V_76 , V_21 ) ;
F_26 ( V_5 , V_2 -> V_16 [ V_21 ] ,
V_59 & ( 1 << V_24 ) ) ;
}
}
F_27 ( V_5 ) ;
V_2 -> V_86 = V_59 ;
}
static void F_35 ( struct V_1 * V_2 )
{
const struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_4 -> F_35 )
( V_4 -> F_35 ) ( ) ;
}
static T_5 F_36 ( int V_87 , void * V_88 )
{
struct V_1 * V_2 = V_88 ;
unsigned long V_89 = F_20 ( V_90 ) ;
F_35 ( V_2 ) ;
if ( V_89 & V_91 )
F_33 ( V_2 ) ;
if ( V_89 & V_92 )
F_19 ( V_2 ) ;
return V_93 ;
}
static void F_37 ( struct V_1 * V_2 )
{
const struct V_3 * V_4 = V_2 -> V_4 ;
unsigned int V_94 = 0 , V_25 = 0 ;
unsigned long V_89 = 0 ;
F_20 ( V_90 ) ;
if ( V_4 -> V_14 && V_4 -> V_15 ) {
V_89 |= V_95 | V_96 | V_97 | V_98 ;
V_89 |= F_38 ( V_4 -> V_14 ) |
F_39 ( V_4 -> V_15 ) ;
}
if ( V_4 -> V_41 ) {
V_94 |= 0x03 ;
V_25 = 2 ;
V_89 |= V_99 ;
}
if ( V_4 -> V_42 ) {
V_94 |= 0x0c ;
V_25 = 4 ;
V_89 |= V_100 ;
}
if ( V_4 -> V_25 > V_25 )
V_25 = V_4 -> V_25 ;
if ( V_4 -> V_26 )
V_2 -> V_26 = V_4 -> V_26 ;
else
V_2 -> V_26 = ( ( 1 << V_25 ) - 1 ) & ~ V_94 ;
if ( V_25 )
V_89 |= V_101 | V_102 | F_40 ( V_25 ) ;
F_32 ( V_90 , V_89 | V_103 ) ;
F_32 ( V_82 , V_83 ) ;
F_32 ( V_104 , V_4 -> V_46 ) ;
}
static int F_41 ( struct V_5 * V_7 )
{
struct V_1 * V_2 = F_42 ( V_7 ) ;
F_43 ( V_2 -> V_105 ) ;
F_37 ( V_2 ) ;
return 0 ;
}
static void F_44 ( struct V_5 * V_7 )
{
struct V_1 * V_2 = F_42 ( V_7 ) ;
F_45 ( V_2 -> V_105 ) ;
}
static int F_46 ( struct V_6 * V_7 )
{
struct V_106 * V_107 = F_47 ( V_7 ) ;
struct V_1 * V_2 = F_48 ( V_107 ) ;
if ( F_49 ( & V_107 -> V_7 ) )
F_50 ( V_2 -> V_87 ) ;
else
F_45 ( V_2 -> V_105 ) ;
return 0 ;
}
static int F_51 ( struct V_6 * V_7 )
{
struct V_106 * V_107 = F_47 ( V_7 ) ;
struct V_1 * V_2 = F_48 ( V_107 ) ;
struct V_5 * V_5 = V_2 -> V_5 ;
if ( F_49 ( & V_107 -> V_7 ) ) {
F_52 ( V_2 -> V_87 ) ;
} else {
F_53 ( & V_5 -> V_108 ) ;
if ( V_5 -> V_109 ) {
F_43 ( V_2 -> V_105 ) ;
F_37 ( V_2 ) ;
}
F_54 ( & V_5 -> V_108 ) ;
}
return 0 ;
}
static int F_55 ( struct V_106 * V_107 )
{
const struct V_3 * V_4 =
F_56 ( & V_107 -> V_7 ) ;
struct V_17 * V_18 = V_107 -> V_7 . V_19 ;
struct V_1 * V_2 ;
struct V_5 * V_5 ;
struct V_110 * V_111 ;
int V_87 , error ;
if ( ! V_18 && ! V_4 )
return - V_13 ;
V_87 = F_57 ( V_107 , 0 ) ;
if ( V_87 < 0 ) {
F_3 ( & V_107 -> V_7 , L_16 ) ;
return - V_112 ;
}
V_111 = F_58 ( V_107 , V_113 , 0 ) ;
if ( V_111 == NULL ) {
F_3 ( & V_107 -> V_7 , L_17 ) ;
return - V_112 ;
}
V_2 = F_59 ( sizeof( struct V_1 ) , V_44 ) ;
V_5 = F_60 () ;
if ( ! V_2 || ! V_5 ) {
F_3 ( & V_107 -> V_7 , L_18 ) ;
error = - V_45 ;
goto V_114;
}
V_2 -> V_4 = V_4 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_87 = V_87 ;
V_111 = F_61 ( V_111 -> V_115 , F_62 ( V_111 ) , V_107 -> V_116 ) ;
if ( V_111 == NULL ) {
F_3 ( & V_107 -> V_7 , L_19 ) ;
error = - V_117 ;
goto V_114;
}
V_2 -> V_118 = F_63 ( V_111 -> V_115 , F_62 ( V_111 ) ) ;
if ( V_2 -> V_118 == NULL ) {
F_3 ( & V_107 -> V_7 , L_20 ) ;
error = - V_112 ;
goto V_119;
}
V_2 -> V_105 = F_64 ( & V_107 -> V_7 , NULL ) ;
if ( F_65 ( V_2 -> V_105 ) ) {
F_3 ( & V_107 -> V_7 , L_21 ) ;
error = F_66 ( V_2 -> V_105 ) ;
goto V_120;
}
V_5 -> V_116 = V_107 -> V_116 ;
V_5 -> V_121 . V_122 = V_123 ;
V_5 -> V_124 = F_41 ;
V_5 -> V_125 = F_44 ;
V_5 -> V_7 . V_8 = & V_107 -> V_7 ;
V_5 -> V_40 = V_2 -> V_16 ;
V_5 -> V_126 = sizeof( V_2 -> V_16 [ 0 ] ) ;
V_5 -> V_47 = F_15 ( V_2 -> V_16 ) ;
F_67 ( V_5 , V_2 ) ;
V_5 -> V_127 [ 0 ] = F_68 ( V_128 ) | F_68 ( V_129 ) ;
F_69 ( V_5 , V_75 , V_76 ) ;
if ( V_4 ) {
error = F_17 ( V_2 ) ;
} else {
error = F_13 ( V_2 ) ;
V_4 = V_2 -> V_4 ;
}
if ( error ) {
F_3 ( & V_107 -> V_7 , L_22 ) ;
goto V_130;
}
V_2 -> V_74 = F_70 ( V_4 -> V_15 ) ;
if ( ( V_4 -> V_41 && V_2 -> V_43 [ 0 ] != - 1 ) ||
( V_4 -> V_42 && V_2 -> V_43 [ 1 ] != - 1 ) ) {
V_5 -> V_127 [ 0 ] |= F_68 ( V_131 ) ;
}
error = F_71 ( V_87 , F_36 , 0 ,
V_107 -> V_116 , V_2 ) ;
if ( error ) {
F_3 ( & V_107 -> V_7 , L_23 ) ;
goto V_130;
}
error = F_72 ( V_5 ) ;
if ( error ) {
F_3 ( & V_107 -> V_7 , L_24 ) ;
goto V_132;
}
F_73 ( V_107 , V_2 ) ;
F_74 ( & V_107 -> V_7 , 1 ) ;
return 0 ;
V_132:
F_75 ( V_87 , V_2 ) ;
V_130:
F_76 ( V_2 -> V_105 ) ;
V_120:
F_77 ( V_2 -> V_118 ) ;
V_119:
F_78 ( V_111 -> V_115 , F_62 ( V_111 ) ) ;
V_114:
F_79 ( V_5 ) ;
F_80 ( V_2 ) ;
return error ;
}
static int F_81 ( struct V_106 * V_107 )
{
struct V_1 * V_2 = F_48 ( V_107 ) ;
struct V_110 * V_111 ;
F_75 ( V_2 -> V_87 , V_2 ) ;
F_76 ( V_2 -> V_105 ) ;
F_82 ( V_2 -> V_5 ) ;
F_77 ( V_2 -> V_118 ) ;
V_111 = F_58 ( V_107 , V_113 , 0 ) ;
F_78 ( V_111 -> V_115 , F_62 ( V_111 ) ) ;
F_80 ( V_2 ) ;
return 0 ;
}
