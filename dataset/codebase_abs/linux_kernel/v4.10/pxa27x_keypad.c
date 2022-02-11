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
unsigned short V_40 ;
int V_24 ;
int error ;
error = F_4 ( V_4 -> V_48 , NULL ,
V_4 -> V_14 ,
V_4 -> V_15 ,
V_2 -> V_16 , V_5 ) ;
if ( error )
return error ;
V_5 -> V_47 = F_15 ( V_2 -> V_16 ) ;
for ( V_24 = 0 ; V_24 < V_4 -> V_25 ; V_24 ++ ) {
V_40 = V_4 -> V_49 [ V_24 ] ;
V_2 -> V_16 [ V_30 + V_24 ] = V_40 ;
F_10 ( V_40 , V_5 -> V_31 ) ;
}
if ( V_4 -> V_41 ) {
if ( V_4 -> V_50 && V_4 -> V_51 ) {
V_40 = V_4 -> V_50 ;
V_2 -> V_16 [ V_30 + 0 ] = V_40 ;
F_10 ( V_40 , V_5 -> V_31 ) ;
V_40 = V_4 -> V_51 ;
V_2 -> V_16 [ V_30 + 1 ] = V_40 ;
F_10 ( V_40 , V_5 -> V_31 ) ;
V_2 -> V_43 [ 0 ] = - 1 ;
} else {
V_2 -> V_43 [ 0 ] = V_4 -> V_36 ;
F_10 ( V_4 -> V_36 , V_5 -> V_37 ) ;
}
}
if ( V_4 -> V_42 ) {
if ( V_4 -> V_52 && V_4 -> V_53 ) {
V_40 = V_4 -> V_52 ;
V_2 -> V_16 [ V_30 + 2 ] = V_40 ;
F_10 ( V_40 , V_5 -> V_31 ) ;
V_40 = V_4 -> V_53 ;
V_2 -> V_16 [ V_30 + 3 ] = V_40 ;
F_10 ( V_40 , V_5 -> V_31 ) ;
V_2 -> V_43 [ 1 ] = - 1 ;
} else {
V_2 -> V_43 [ 1 ] = V_4 -> V_38 ;
F_10 ( V_4 -> V_38 , V_5 -> V_37 ) ;
}
}
F_18 ( V_54 , V_5 -> V_31 ) ;
return 0 ;
}
static void F_19 ( struct V_1 * V_2 )
{
const struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_5 = V_2 -> V_5 ;
int V_55 , V_56 , V_57 = 0 ;
T_4 V_58 [ V_12 ] ;
T_4 V_59 = F_20 ( V_60 ) ;
V_57 = F_21 ( V_59 ) ;
memset ( V_58 , 0 , sizeof( V_58 ) ) ;
if ( V_57 == 0 )
goto V_61;
if ( V_57 == 1 ) {
V_56 = F_22 ( V_59 ) ;
V_55 = F_23 ( V_59 ) ;
if ( V_56 >= V_4 -> V_15 ||
V_55 >= V_4 -> V_14 )
goto V_61;
V_58 [ V_56 ] = ( 1 << V_55 ) ;
goto V_61;
}
if ( V_57 > 1 ) {
T_4 V_62 = F_20 ( V_63 ) ;
T_4 V_64 = F_20 ( V_65 ) ;
T_4 V_66 = F_20 ( V_67 ) ;
T_4 V_68 = F_20 ( V_69 ) ;
V_58 [ 0 ] = V_62 & V_70 ;
V_58 [ 1 ] = ( V_62 >> 16 ) & V_70 ;
V_58 [ 2 ] = V_64 & V_70 ;
V_58 [ 3 ] = ( V_64 >> 16 ) & V_70 ;
V_58 [ 4 ] = V_66 & V_70 ;
V_58 [ 5 ] = ( V_66 >> 16 ) & V_70 ;
V_58 [ 6 ] = V_68 & V_70 ;
V_58 [ 7 ] = ( V_68 >> 16 ) & V_70 ;
}
V_61:
for ( V_56 = 0 ; V_56 < V_4 -> V_15 ; V_56 ++ ) {
T_4 V_71 ;
int V_21 ;
V_71 = V_2 -> V_72 [ V_56 ] ^ V_58 [ V_56 ] ;
if ( V_71 == 0 )
continue;
for ( V_55 = 0 ; V_55 < V_4 -> V_14 ; V_55 ++ ) {
if ( ( V_71 & ( 1 << V_55 ) ) == 0 )
continue;
V_21 = F_24 ( V_55 , V_56 , V_2 -> V_73 ) ;
F_25 ( V_5 , V_74 , V_75 , V_21 ) ;
F_26 ( V_5 , V_2 -> V_16 [ V_21 ] ,
V_58 [ V_56 ] & ( 1 << V_55 ) ) ;
}
}
F_27 ( V_5 ) ;
memcpy ( V_2 -> V_72 , V_58 , sizeof( V_58 ) ) ;
}
static inline int F_28 ( T_4 V_76 )
{
if ( V_76 & V_77 )
return ( V_76 & 0xff ) + 0x7f ;
else if ( V_76 & V_78 )
return ( V_76 & 0xff ) - 0x7f - 0xff ;
else
return ( V_76 & 0xff ) - 0x7f ;
}
static void F_29 ( struct V_1 * V_2 , int V_79 , int V_80 )
{
struct V_5 * V_7 = V_2 -> V_5 ;
if ( V_80 == 0 )
return;
if ( V_2 -> V_43 [ V_79 ] == - 1 ) {
int V_21 = V_30 + 2 * V_79 + ( V_80 > 0 ? 0 : 1 ) ;
unsigned char V_40 = V_2 -> V_16 [ V_21 ] ;
F_25 ( V_7 , V_74 , V_75 , V_21 ) ;
F_26 ( V_7 , V_40 , 1 ) ;
F_27 ( V_7 ) ;
F_25 ( V_7 , V_74 , V_75 , V_21 ) ;
F_26 ( V_7 , V_40 , 0 ) ;
F_27 ( V_7 ) ;
} else {
F_30 ( V_7 , V_2 -> V_43 [ V_79 ] , V_80 ) ;
F_27 ( V_7 ) ;
}
}
static void F_31 ( struct V_1 * V_2 )
{
const struct V_3 * V_4 = V_2 -> V_4 ;
T_4 V_76 ;
V_76 = F_20 ( V_81 ) ;
F_32 ( V_81 , V_82 ) ;
if ( V_4 -> V_41 )
F_29 ( V_2 , 0 , F_28 ( V_76 ) ) ;
if ( V_4 -> V_42 )
F_29 ( V_2 , 1 , F_28 ( V_76 >> 16 ) ) ;
}
static void F_33 ( struct V_1 * V_2 )
{
const struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_5 = V_2 -> V_5 ;
unsigned int V_58 ;
T_4 V_83 , V_71 ;
int V_24 ;
V_83 = F_20 ( V_84 ) ;
if ( V_4 -> V_41 || V_4 -> V_42 )
F_31 ( V_2 ) ;
if ( V_4 -> V_27 )
V_58 = ~ F_34 ( V_83 ) & V_2 -> V_26 ;
else
V_58 = F_34 ( V_83 ) & V_2 -> V_26 ;
V_71 = V_2 -> V_85 ^ V_58 ;
if ( V_71 == 0 )
return;
for ( V_24 = 0 ; V_24 < V_4 -> V_25 ; V_24 ++ ) {
if ( V_71 & ( 1 << V_24 ) ) {
int V_21 = V_30 + V_24 ;
F_25 ( V_5 , V_74 , V_75 , V_21 ) ;
F_26 ( V_5 , V_2 -> V_16 [ V_21 ] ,
V_58 & ( 1 << V_24 ) ) ;
}
}
F_27 ( V_5 ) ;
V_2 -> V_85 = V_58 ;
}
static void F_35 ( struct V_1 * V_2 )
{
const struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_4 -> F_35 )
( V_4 -> F_35 ) ( ) ;
}
static T_5 F_36 ( int V_86 , void * V_87 )
{
struct V_1 * V_2 = V_87 ;
unsigned long V_88 = F_20 ( V_89 ) ;
F_35 ( V_2 ) ;
if ( V_88 & V_90 )
F_33 ( V_2 ) ;
if ( V_88 & V_91 )
F_19 ( V_2 ) ;
return V_92 ;
}
static void F_37 ( struct V_1 * V_2 )
{
const struct V_3 * V_4 = V_2 -> V_4 ;
unsigned int V_93 = 0 , V_25 = 0 ;
unsigned long V_88 = 0 ;
F_20 ( V_89 ) ;
if ( V_4 -> V_14 && V_4 -> V_15 ) {
V_88 |= V_94 | V_95 | V_96 | V_97 ;
V_88 |= F_38 ( V_4 -> V_14 ) |
F_39 ( V_4 -> V_15 ) ;
}
if ( V_4 -> V_41 ) {
V_93 |= 0x03 ;
V_25 = 2 ;
V_88 |= V_98 ;
}
if ( V_4 -> V_42 ) {
V_93 |= 0x0c ;
V_25 = 4 ;
V_88 |= V_99 ;
}
if ( V_4 -> V_25 > V_25 )
V_25 = V_4 -> V_25 ;
if ( V_4 -> V_26 )
V_2 -> V_26 = V_4 -> V_26 ;
else
V_2 -> V_26 = ( ( 1 << V_25 ) - 1 ) & ~ V_93 ;
if ( V_25 )
V_88 |= V_100 | V_101 | F_40 ( V_25 ) ;
F_32 ( V_89 , V_88 | V_102 ) ;
F_32 ( V_81 , V_82 ) ;
F_32 ( V_103 , V_4 -> V_46 ) ;
}
static int F_41 ( struct V_5 * V_7 )
{
struct V_1 * V_2 = F_42 ( V_7 ) ;
F_43 ( V_2 -> V_104 ) ;
F_37 ( V_2 ) ;
return 0 ;
}
static void F_44 ( struct V_5 * V_7 )
{
struct V_1 * V_2 = F_42 ( V_7 ) ;
F_45 ( V_2 -> V_104 ) ;
}
static int F_46 ( struct V_6 * V_7 )
{
struct V_105 * V_106 = F_47 ( V_7 ) ;
struct V_1 * V_2 = F_48 ( V_106 ) ;
if ( F_49 ( & V_106 -> V_7 ) )
F_50 ( V_2 -> V_86 ) ;
else
F_45 ( V_2 -> V_104 ) ;
return 0 ;
}
static int F_51 ( struct V_6 * V_7 )
{
struct V_105 * V_106 = F_47 ( V_7 ) ;
struct V_1 * V_2 = F_48 ( V_106 ) ;
struct V_5 * V_5 = V_2 -> V_5 ;
if ( F_49 ( & V_106 -> V_7 ) ) {
F_52 ( V_2 -> V_86 ) ;
} else {
F_53 ( & V_5 -> V_107 ) ;
if ( V_5 -> V_108 ) {
F_43 ( V_2 -> V_104 ) ;
F_37 ( V_2 ) ;
}
F_54 ( & V_5 -> V_107 ) ;
}
return 0 ;
}
static int F_55 ( struct V_105 * V_106 )
{
const struct V_3 * V_4 =
F_56 ( & V_106 -> V_7 ) ;
struct V_17 * V_18 = V_106 -> V_7 . V_19 ;
struct V_1 * V_2 ;
struct V_5 * V_5 ;
struct V_109 * V_110 ;
int V_86 , error ;
if ( ! V_18 && ! V_4 )
return - V_13 ;
V_86 = F_57 ( V_106 , 0 ) ;
if ( V_86 < 0 ) {
F_3 ( & V_106 -> V_7 , L_16 ) ;
return - V_111 ;
}
V_110 = F_58 ( V_106 , V_112 , 0 ) ;
if ( V_110 == NULL ) {
F_3 ( & V_106 -> V_7 , L_17 ) ;
return - V_111 ;
}
V_2 = F_14 ( & V_106 -> V_7 , sizeof( * V_2 ) ,
V_44 ) ;
if ( ! V_2 )
return - V_45 ;
V_5 = F_59 ( & V_106 -> V_7 ) ;
if ( ! V_5 )
return - V_45 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_86 = V_86 ;
V_2 -> V_113 = F_60 ( & V_106 -> V_7 , V_110 ) ;
if ( F_61 ( V_2 -> V_113 ) )
return F_62 ( V_2 -> V_113 ) ;
V_2 -> V_104 = F_63 ( & V_106 -> V_7 , NULL ) ;
if ( F_61 ( V_2 -> V_104 ) ) {
F_3 ( & V_106 -> V_7 , L_18 ) ;
return F_62 ( V_2 -> V_104 ) ;
}
V_5 -> V_114 = V_106 -> V_114 ;
V_5 -> V_115 . V_116 = V_117 ;
V_5 -> V_118 = F_41 ;
V_5 -> V_119 = F_44 ;
V_5 -> V_7 . V_8 = & V_106 -> V_7 ;
V_5 -> V_40 = V_2 -> V_16 ;
V_5 -> V_120 = sizeof( V_2 -> V_16 [ 0 ] ) ;
V_5 -> V_47 = F_15 ( V_2 -> V_16 ) ;
F_64 ( V_5 , V_2 ) ;
V_5 -> V_121 [ 0 ] = F_65 ( V_122 ) | F_65 ( V_123 ) ;
F_66 ( V_5 , V_74 , V_75 ) ;
if ( V_4 ) {
error = F_17 ( V_2 ) ;
} else {
error = F_13 ( V_2 ) ;
V_4 = V_2 -> V_4 ;
}
if ( error ) {
F_3 ( & V_106 -> V_7 , L_19 ) ;
return error ;
}
V_2 -> V_73 = F_67 ( V_4 -> V_15 ) ;
if ( ( V_4 -> V_41 && V_2 -> V_43 [ 0 ] != - 1 ) ||
( V_4 -> V_42 && V_2 -> V_43 [ 1 ] != - 1 ) ) {
V_5 -> V_121 [ 0 ] |= F_65 ( V_124 ) ;
}
error = F_68 ( & V_106 -> V_7 , V_86 , F_36 ,
0 , V_106 -> V_114 , V_2 ) ;
if ( error ) {
F_3 ( & V_106 -> V_7 , L_20 ) ;
return error ;
}
error = F_69 ( V_5 ) ;
if ( error ) {
F_3 ( & V_106 -> V_7 , L_21 ) ;
return error ;
}
F_70 ( V_106 , V_2 ) ;
F_71 ( & V_106 -> V_7 , 1 ) ;
return 0 ;
}
