static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_5 = V_2 -> V_5 ;
unsigned short V_6 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_4 -> V_8 ; V_7 ++ ) {
unsigned int V_9 = V_4 -> V_10 [ V_7 ] ;
unsigned int V_11 = F_2 ( V_9 ) ;
unsigned int V_12 = F_3 ( V_9 ) ;
unsigned int V_13 = F_4 ( V_11 , V_12 ,
V_14 ) ;
V_6 = F_5 ( V_9 ) ;
V_2 -> V_15 [ V_13 ] = V_6 ;
F_6 ( V_6 , V_5 -> V_16 ) ;
}
for ( V_7 = 0 ; V_7 < V_4 -> V_17 ; V_7 ++ ) {
V_6 = V_4 -> V_18 [ V_7 ] ;
V_2 -> V_15 [ V_19 + V_7 ] = V_6 ;
F_6 ( V_6 , V_5 -> V_16 ) ;
}
if ( V_4 -> V_20 ) {
if ( V_4 -> V_21 && V_4 -> V_22 ) {
V_6 = V_4 -> V_21 ;
V_2 -> V_15 [ V_19 + 0 ] = V_6 ;
F_6 ( V_6 , V_5 -> V_16 ) ;
V_6 = V_4 -> V_22 ;
V_2 -> V_15 [ V_19 + 1 ] = V_6 ;
F_6 ( V_6 , V_5 -> V_16 ) ;
V_2 -> V_23 [ 0 ] = - 1 ;
} else {
V_2 -> V_23 [ 0 ] = V_4 -> V_24 ;
F_6 ( V_4 -> V_24 , V_5 -> V_25 ) ;
}
}
if ( V_4 -> V_26 ) {
if ( V_4 -> V_27 && V_4 -> V_28 ) {
V_6 = V_4 -> V_27 ;
V_2 -> V_15 [ V_19 + 2 ] = V_6 ;
F_6 ( V_6 , V_5 -> V_16 ) ;
V_6 = V_4 -> V_28 ;
V_2 -> V_15 [ V_19 + 3 ] = V_6 ;
F_6 ( V_6 , V_5 -> V_16 ) ;
V_2 -> V_23 [ 1 ] = - 1 ;
} else {
V_2 -> V_23 [ 1 ] = V_4 -> V_29 ;
F_6 ( V_4 -> V_29 , V_5 -> V_25 ) ;
}
}
F_7 ( V_30 , V_5 -> V_16 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_5 = V_2 -> V_5 ;
int V_11 , V_12 , V_31 = 0 ;
T_1 V_32 [ V_33 ] ;
T_1 V_34 = F_9 ( V_35 ) ;
V_31 = F_10 ( V_34 ) ;
memset ( V_32 , 0 , sizeof( V_32 ) ) ;
if ( V_31 == 0 )
goto V_36;
if ( V_31 == 1 ) {
V_12 = F_11 ( V_34 ) ;
V_11 = F_12 ( V_34 ) ;
if ( V_12 >= V_4 -> V_37 ||
V_11 >= V_4 -> V_38 )
goto V_36;
V_32 [ V_12 ] = ( 1 << V_11 ) ;
goto V_36;
}
if ( V_31 > 1 ) {
T_1 V_39 = F_9 ( V_40 ) ;
T_1 V_41 = F_9 ( V_42 ) ;
T_1 V_43 = F_9 ( V_44 ) ;
T_1 V_45 = F_9 ( V_46 ) ;
V_32 [ 0 ] = V_39 & V_47 ;
V_32 [ 1 ] = ( V_39 >> 16 ) & V_47 ;
V_32 [ 2 ] = V_41 & V_47 ;
V_32 [ 3 ] = ( V_41 >> 16 ) & V_47 ;
V_32 [ 4 ] = V_43 & V_47 ;
V_32 [ 5 ] = ( V_43 >> 16 ) & V_47 ;
V_32 [ 6 ] = V_45 & V_47 ;
V_32 [ 7 ] = ( V_45 >> 16 ) & V_47 ;
}
V_36:
for ( V_12 = 0 ; V_12 < V_4 -> V_37 ; V_12 ++ ) {
T_1 V_48 ;
int V_49 ;
V_48 = V_2 -> V_50 [ V_12 ] ^ V_32 [ V_12 ] ;
if ( V_48 == 0 )
continue;
for ( V_11 = 0 ; V_11 < V_4 -> V_38 ; V_11 ++ ) {
if ( ( V_48 & ( 1 << V_11 ) ) == 0 )
continue;
V_49 = F_4 ( V_11 , V_12 , V_14 ) ;
F_13 ( V_5 , V_51 , V_52 , V_49 ) ;
F_14 ( V_5 , V_2 -> V_15 [ V_49 ] ,
V_32 [ V_12 ] & ( 1 << V_11 ) ) ;
}
}
F_15 ( V_5 ) ;
memcpy ( V_2 -> V_50 , V_32 , sizeof( V_32 ) ) ;
}
static inline int F_16 ( T_1 V_53 )
{
if ( V_53 & V_54 )
return ( V_53 & 0xff ) + 0x7f ;
else if ( V_53 & V_55 )
return ( V_53 & 0xff ) - 0x7f - 0xff ;
else
return ( V_53 & 0xff ) - 0x7f ;
}
static void F_17 ( struct V_1 * V_2 , int V_56 , int V_57 )
{
struct V_5 * V_58 = V_2 -> V_5 ;
if ( V_57 == 0 )
return;
if ( V_2 -> V_23 [ V_56 ] == - 1 ) {
int V_49 = V_19 + 2 * V_56 + ( V_57 > 0 ? 0 : 1 ) ;
unsigned char V_6 = V_2 -> V_15 [ V_49 ] ;
F_13 ( V_58 , V_51 , V_52 , V_49 ) ;
F_14 ( V_58 , V_6 , 1 ) ;
F_15 ( V_58 ) ;
F_13 ( V_58 , V_51 , V_52 , V_49 ) ;
F_14 ( V_58 , V_6 , 0 ) ;
F_15 ( V_58 ) ;
} else {
F_18 ( V_58 , V_2 -> V_23 [ V_56 ] , V_57 ) ;
F_15 ( V_58 ) ;
}
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_1 V_53 ;
V_53 = F_9 ( V_59 ) ;
F_20 ( V_59 , V_60 ) ;
if ( V_4 -> V_20 )
F_17 ( V_2 , 0 , F_16 ( V_53 ) ) ;
if ( V_4 -> V_26 )
F_17 ( V_2 , 1 , F_16 ( V_53 >> 16 ) ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_5 = V_2 -> V_5 ;
unsigned int V_32 ;
T_1 V_61 , V_48 ;
int V_7 ;
V_61 = F_9 ( V_62 ) ;
if ( V_4 -> V_20 || V_4 -> V_26 )
F_19 ( V_2 ) ;
if ( V_4 -> V_63 )
V_32 = ~ F_22 ( V_61 ) & V_2 -> V_64 ;
else
V_32 = F_22 ( V_61 ) & V_2 -> V_64 ;
V_48 = V_2 -> V_65 ^ V_32 ;
if ( V_48 == 0 )
return;
for ( V_7 = 0 ; V_7 < V_4 -> V_17 ; V_7 ++ ) {
if ( V_48 & ( 1 << V_7 ) ) {
int V_49 = V_19 + V_7 ;
F_13 ( V_5 , V_51 , V_52 , V_49 ) ;
F_14 ( V_5 , V_2 -> V_15 [ V_49 ] ,
V_32 & ( 1 << V_7 ) ) ;
}
}
F_15 ( V_5 ) ;
V_2 -> V_65 = V_32 ;
}
static void F_23 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_4 -> F_23 )
( V_4 -> F_23 ) ( ) ;
}
static T_2 F_24 ( int V_66 , void * V_67 )
{
struct V_1 * V_2 = V_67 ;
unsigned long V_68 = F_9 ( V_69 ) ;
F_23 ( V_2 ) ;
if ( V_68 & V_70 )
F_21 ( V_2 ) ;
if ( V_68 & V_71 )
F_8 ( V_2 ) ;
return V_72 ;
}
static void F_25 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
unsigned int V_73 = 0 , V_17 = 0 ;
unsigned long V_68 = 0 ;
F_9 ( V_69 ) ;
if ( V_4 -> V_38 && V_4 -> V_37 ) {
V_68 |= V_74 | V_75 | V_76 | V_77 ;
V_68 |= F_26 ( V_4 -> V_38 ) |
F_27 ( V_4 -> V_37 ) ;
}
if ( V_4 -> V_20 ) {
V_73 |= 0x03 ;
V_17 = 2 ;
V_68 |= V_78 ;
}
if ( V_4 -> V_26 ) {
V_73 |= 0x0c ;
V_17 = 4 ;
V_68 |= V_79 ;
}
if ( V_4 -> V_17 > V_17 )
V_17 = V_4 -> V_17 ;
if ( V_4 -> V_64 )
V_2 -> V_64 = V_4 -> V_64 ;
else
V_2 -> V_64 = ( ( 1 << V_17 ) - 1 ) & ~ V_73 ;
if ( V_17 )
V_68 |= V_80 | V_81 | F_28 ( V_17 ) ;
F_20 ( V_69 , V_68 | V_82 ) ;
F_20 ( V_59 , V_60 ) ;
F_20 ( V_83 , V_4 -> V_84 ) ;
}
static int F_29 ( struct V_5 * V_58 )
{
struct V_1 * V_2 = F_30 ( V_58 ) ;
F_31 ( V_2 -> V_85 ) ;
F_25 ( V_2 ) ;
return 0 ;
}
static void F_32 ( struct V_5 * V_58 )
{
struct V_1 * V_2 = F_30 ( V_58 ) ;
F_33 ( V_2 -> V_85 ) ;
}
static int F_34 ( struct V_86 * V_58 )
{
struct V_87 * V_88 = F_35 ( V_58 ) ;
struct V_1 * V_2 = F_36 ( V_88 ) ;
if ( F_37 ( & V_88 -> V_58 ) )
F_38 ( V_2 -> V_66 ) ;
else
F_33 ( V_2 -> V_85 ) ;
return 0 ;
}
static int F_39 ( struct V_86 * V_58 )
{
struct V_87 * V_88 = F_35 ( V_58 ) ;
struct V_1 * V_2 = F_36 ( V_88 ) ;
struct V_5 * V_5 = V_2 -> V_5 ;
if ( F_37 ( & V_88 -> V_58 ) ) {
F_40 ( V_2 -> V_66 ) ;
} else {
F_41 ( & V_5 -> V_89 ) ;
if ( V_5 -> V_90 ) {
F_31 ( V_2 -> V_85 ) ;
F_25 ( V_2 ) ;
}
F_42 ( & V_5 -> V_89 ) ;
}
return 0 ;
}
static int T_3 F_43 ( struct V_87 * V_88 )
{
struct V_3 * V_4 = V_88 -> V_58 . V_91 ;
struct V_1 * V_2 ;
struct V_5 * V_5 ;
struct V_92 * V_93 ;
int V_66 , error ;
if ( V_4 == NULL ) {
F_44 ( & V_88 -> V_58 , L_1 ) ;
return - V_94 ;
}
V_66 = F_45 ( V_88 , 0 ) ;
if ( V_66 < 0 ) {
F_44 ( & V_88 -> V_58 , L_2 ) ;
return - V_95 ;
}
V_93 = F_46 ( V_88 , V_96 , 0 ) ;
if ( V_93 == NULL ) {
F_44 ( & V_88 -> V_58 , L_3 ) ;
return - V_95 ;
}
V_2 = F_47 ( sizeof( struct V_1 ) , V_97 ) ;
V_5 = F_48 () ;
if ( ! V_2 || ! V_5 ) {
F_44 ( & V_88 -> V_58 , L_4 ) ;
error = - V_98 ;
goto V_99;
}
V_2 -> V_4 = V_4 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_66 = V_66 ;
V_93 = F_49 ( V_93 -> V_100 , F_50 ( V_93 ) , V_88 -> V_101 ) ;
if ( V_93 == NULL ) {
F_44 ( & V_88 -> V_58 , L_5 ) ;
error = - V_102 ;
goto V_99;
}
V_2 -> V_103 = F_51 ( V_93 -> V_100 , F_50 ( V_93 ) ) ;
if ( V_2 -> V_103 == NULL ) {
F_44 ( & V_88 -> V_58 , L_6 ) ;
error = - V_95 ;
goto V_104;
}
V_2 -> V_85 = F_52 ( & V_88 -> V_58 , NULL ) ;
if ( F_53 ( V_2 -> V_85 ) ) {
F_44 ( & V_88 -> V_58 , L_7 ) ;
error = F_54 ( V_2 -> V_85 ) ;
goto V_105;
}
V_5 -> V_101 = V_88 -> V_101 ;
V_5 -> V_106 . V_107 = V_108 ;
V_5 -> V_109 = F_29 ;
V_5 -> V_110 = F_32 ;
V_5 -> V_58 . V_111 = & V_88 -> V_58 ;
V_5 -> V_6 = V_2 -> V_15 ;
V_5 -> V_112 = sizeof( V_2 -> V_15 [ 0 ] ) ;
V_5 -> V_113 = F_55 ( V_2 -> V_15 ) ;
F_56 ( V_5 , V_2 ) ;
V_5 -> V_114 [ 0 ] = F_57 ( V_115 ) | F_57 ( V_116 ) ;
F_58 ( V_5 , V_51 , V_52 ) ;
F_1 ( V_2 ) ;
if ( ( V_4 -> V_20 && V_2 -> V_23 [ 0 ] != - 1 ) ||
( V_4 -> V_26 && V_2 -> V_23 [ 1 ] != - 1 ) ) {
V_5 -> V_114 [ 0 ] |= F_57 ( V_117 ) ;
}
error = F_59 ( V_66 , F_24 , 0 ,
V_88 -> V_101 , V_2 ) ;
if ( error ) {
F_44 ( & V_88 -> V_58 , L_8 ) ;
goto V_118;
}
error = F_60 ( V_5 ) ;
if ( error ) {
F_44 ( & V_88 -> V_58 , L_9 ) ;
goto V_119;
}
F_61 ( V_88 , V_2 ) ;
F_62 ( & V_88 -> V_58 , 1 ) ;
return 0 ;
V_119:
F_63 ( V_66 , V_88 ) ;
V_118:
F_64 ( V_2 -> V_85 ) ;
V_105:
F_65 ( V_2 -> V_103 ) ;
V_104:
F_66 ( V_93 -> V_100 , F_50 ( V_93 ) ) ;
V_99:
F_67 ( V_5 ) ;
F_68 ( V_2 ) ;
return error ;
}
static int T_4 F_69 ( struct V_87 * V_88 )
{
struct V_1 * V_2 = F_36 ( V_88 ) ;
struct V_92 * V_93 ;
F_63 ( V_2 -> V_66 , V_88 ) ;
F_64 ( V_2 -> V_85 ) ;
F_70 ( V_2 -> V_5 ) ;
F_65 ( V_2 -> V_103 ) ;
V_93 = F_46 ( V_88 , V_96 , 0 ) ;
F_66 ( V_93 -> V_100 , F_50 ( V_93 ) ) ;
F_61 ( V_88 , NULL ) ;
F_68 ( V_2 ) ;
return 0 ;
}
