static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static struct V_1 * F_3 ( struct V_4 * V_5 )
{
return F_4 ( V_5 ) ;
}
static struct V_6 * F_5 ( struct V_4 * V_5 )
{
return V_5 -> V_7 . V_8 ;
}
static void F_6 ( struct V_2 * V_3 , int V_9 ,
unsigned int V_10 )
{
if ( V_9 == V_11 )
return;
while ( F_7 () & V_12 )
F_8 () ;
if ( V_10 & V_13 )
F_9 ( V_9 ) ;
else if ( V_10 & V_14 )
F_10 ( V_9 ) ;
F_11 () ;
}
static int F_12 ( struct V_2 * V_3 )
{
unsigned short V_15 = F_7 () ;
if ( ( V_15 & V_16 ) == V_16 )
return 1 ;
else
return 0 ;
}
static int F_13 ( struct V_2 * V_3 , T_1 * V_17 ,
T_1 * V_18 , T_1 * V_19 )
{
struct V_1 * V_20 = F_1 ( V_3 ) ;
T_2 V_21 [ 5 ] ;
T_2 V_22 , V_23 ;
int V_24 ;
unsigned short V_25 , V_26 ;
T_1 V_27 ;
V_22 = V_19 [ 0 ] | ( V_19 [ 1 ] << 8 ) | ( V_19 [ 2 ] << 16 ) ;
V_23 = V_18 [ 0 ] | ( V_18 [ 1 ] << 8 ) | ( V_18 [ 2 ] << 16 ) ;
V_21 [ 0 ] = ( V_22 ^ V_23 ) ;
if ( ! V_21 [ 0 ] || ! V_22 || ! V_23 )
return 0 ;
if ( F_14 ( V_21 [ 0 ] ) == 1 ) {
F_15 ( V_20 -> V_28 , L_1 ) ;
return 1 ;
}
V_21 [ 1 ] = ( V_22 & 0x7FF ) ^ ( V_23 & 0x7FF ) ;
V_21 [ 2 ] = ( V_22 & 0x7FF ) ^ ( ( V_22 >> 11 ) & 0x7FF ) ;
V_21 [ 3 ] = ( V_23 & 0x7FF ) ^ ( ( V_23 >> 11 ) & 0x7FF ) ;
V_21 [ 4 ] = V_21 [ 2 ] ^ V_21 [ 3 ] ;
for ( V_24 = 0 ; V_24 < 5 ; V_24 ++ )
F_16 ( V_20 -> V_28 , L_2 , V_24 , V_21 [ V_24 ] ) ;
F_16 ( V_20 -> V_28 ,
L_3 ,
V_22 , V_23 ) ;
if ( F_14 ( V_21 [ 0 ] ) == 11 && V_21 [ 4 ] == 0x7FF ) {
F_16 ( V_20 -> V_28 ,
L_4 ) ;
F_16 ( V_20 -> V_28 ,
L_5 , V_21 [ 1 ] ) ;
V_25 = V_21 [ 1 ] & 0x7 ;
V_26 = V_21 [ 1 ] >> 0x3 ;
V_27 = * ( V_17 + V_26 ) ;
V_27 = V_27 ^ ( 0x1 << V_25 ) ;
* ( V_17 + V_26 ) = V_27 ;
return 0 ;
}
F_15 ( V_20 -> V_28 ,
L_6 ) ;
F_15 ( V_20 -> V_28 ,
L_7 ) ;
return 1 ;
}
static int F_17 ( struct V_2 * V_3 , T_1 * V_17 ,
T_1 * V_18 , T_1 * V_19 )
{
struct V_29 * V_30 = V_3 -> V_31 ;
int V_32 ;
V_32 = F_13 ( V_3 , V_17 , V_18 , V_19 ) ;
if ( V_30 -> V_33 . V_34 == 512 ) {
V_17 += 256 ;
V_18 += 3 ;
V_19 += 3 ;
V_32 |= F_13 ( V_3 , V_17 , V_18 , V_19 ) ;
}
return V_32 ;
}
static void F_18 ( struct V_2 * V_3 , int V_35 )
{
return;
}
static int F_19 ( struct V_2 * V_3 ,
const T_1 * V_17 , T_1 * V_36 )
{
struct V_1 * V_20 = F_1 ( V_3 ) ;
struct V_29 * V_30 = V_3 -> V_31 ;
T_3 V_37 , V_38 ;
T_2 V_39 [ 2 ] ;
T_4 * V_40 ;
V_37 = F_20 () ;
V_38 = F_21 () ;
V_39 [ 0 ] = ( V_37 & 0x7ff ) | ( ( V_38 & 0x7ff ) << 11 ) ;
F_22 ( V_20 -> V_28 , L_8 , V_39 [ 0 ] ) ;
V_40 = ( T_4 * ) V_39 ;
memcpy ( V_36 , V_40 , 3 ) ;
if ( V_30 -> V_33 . V_34 == 512 ) {
V_37 = F_23 () ;
V_38 = F_24 () ;
V_39 [ 1 ] = ( V_37 & 0x7ff ) | ( ( V_38 & 0x7ff ) << 11 ) ;
V_40 = ( T_4 * ) ( V_39 + 1 ) ;
memcpy ( ( V_36 + 3 ) , V_40 , 3 ) ;
F_22 ( V_20 -> V_28 , L_8 , V_39 [ 1 ] ) ;
}
return 0 ;
}
static void F_25 ( struct V_2 * V_3 , T_5 * V_41 , int V_42 )
{
int V_24 ;
unsigned short V_15 ;
for ( V_24 = 0 ; V_24 < V_42 ; V_24 ++ ) {
while ( F_7 () & V_12 )
F_8 () ;
F_26 ( 0x0000 ) ;
F_11 () ;
while ( ( F_27 () & V_43 ) != V_43 )
F_8 () ;
V_41 [ V_24 ] = F_28 () ;
V_15 = F_27 () ;
V_15 |= V_43 ;
F_29 ( V_15 ) ;
F_11 () ;
}
}
static T_5 F_30 ( struct V_2 * V_3 )
{
T_5 V_15 ;
F_25 ( V_3 , & V_15 , 1 ) ;
return V_15 ;
}
static void F_31 ( struct V_2 * V_3 ,
const T_5 * V_41 , int V_42 )
{
int V_24 ;
for ( V_24 = 0 ; V_24 < V_42 ; V_24 ++ ) {
while ( F_7 () & V_12 )
F_8 () ;
F_32 ( V_41 [ V_24 ] ) ;
F_11 () ;
}
}
static void F_33 ( struct V_2 * V_3 , T_5 * V_41 , int V_42 )
{
int V_24 ;
T_3 * V_40 = ( T_3 * ) V_41 ;
V_42 >>= 1 ;
F_26 ( 0x5555 ) ;
F_11 () ;
for ( V_24 = 0 ; V_24 < V_42 ; V_24 ++ )
V_40 [ V_24 ] = F_28 () ;
}
static void F_34 ( struct V_2 * V_3 ,
const T_5 * V_41 , int V_42 )
{
int V_24 ;
T_3 * V_40 = ( T_3 * ) V_41 ;
V_42 >>= 1 ;
for ( V_24 = 0 ; V_24 < V_42 ; V_24 ++ )
F_32 ( V_40 [ V_24 ] ) ;
F_11 () ;
}
static T_6 F_35 ( int V_44 , void * V_45 )
{
struct V_1 * V_20 = V_45 ;
F_36 ( V_46 ) ;
F_37 ( V_46 ) ;
F_38 ( & V_20 -> V_47 ) ;
return V_48 ;
}
static void F_39 ( struct V_2 * V_3 ,
T_5 * V_41 , int V_49 )
{
struct V_1 * V_20 = F_1 ( V_3 ) ;
struct V_29 * V_30 = V_3 -> V_31 ;
unsigned short V_15 ;
F_22 ( V_20 -> V_28 , L_9 ,
V_3 , V_41 , V_49 ) ;
if ( V_49 )
F_40 ( ( unsigned int ) V_41 ,
( unsigned int ) ( V_41 + V_30 -> V_33 . V_34 ) ) ;
else
F_41 ( ( unsigned int ) V_41 ,
( unsigned int ) ( V_41 + V_30 -> V_33 . V_34 ) ) ;
F_42 ( V_50 ) ;
F_11 () ;
while ( F_43 () & V_50 )
F_8 () ;
F_37 ( V_46 ) ;
F_36 ( V_46 ) ;
F_44 ( V_46 , 0x0 ) ;
F_45 ( V_46 , ( unsigned long ) V_41 ) ;
#ifdef F_46
F_47 ( V_46 , ( V_30 -> V_33 . V_34 >> 1 ) ) ;
F_48 ( V_46 , 2 ) ;
V_15 = V_51 | V_52 ;
#endif
#ifdef F_49
F_47 ( V_46 , ( V_30 -> V_33 . V_34 >> 2 ) ) ;
F_48 ( V_46 , 4 ) ;
V_15 = V_51 | V_53 ;
#endif
if ( V_49 )
V_15 |= V_54 ;
F_44 ( V_46 , V_15 ) ;
F_50 ( V_46 ) ;
if ( V_49 )
F_51 ( V_55 ) ;
else
F_51 ( V_56 ) ;
F_52 ( & V_20 -> V_47 ) ;
}
static void F_53 ( struct V_2 * V_3 ,
T_5 * V_41 , int V_42 )
{
struct V_1 * V_20 = F_1 ( V_3 ) ;
struct V_29 * V_30 = V_3 -> V_31 ;
F_22 ( V_20 -> V_28 , L_10 , V_3 , V_41 , V_42 ) ;
if ( V_42 == V_30 -> V_33 . V_34 )
F_39 ( V_3 , V_41 , 1 ) ;
else
F_25 ( V_3 , V_41 , V_42 ) ;
}
static void F_54 ( struct V_2 * V_3 ,
const T_5 * V_41 , int V_42 )
{
struct V_1 * V_20 = F_1 ( V_3 ) ;
struct V_29 * V_30 = V_3 -> V_31 ;
F_22 ( V_20 -> V_28 , L_11 , V_3 , V_41 , V_42 ) ;
if ( V_42 == V_30 -> V_33 . V_34 )
F_39 ( V_3 , ( T_5 * ) V_41 , 0 ) ;
else
F_31 ( V_3 , V_41 , V_42 ) ;
}
static int F_55 ( struct V_2 * V_3 , struct V_29 * V_30 ,
T_5 * V_41 , int V_57 , int V_58 )
{
F_25 ( V_3 , V_41 , V_3 -> V_59 ) ;
F_25 ( V_3 , V_30 -> V_60 , V_3 -> V_61 ) ;
return 0 ;
}
static int F_56 ( struct V_2 * V_3 ,
struct V_29 * V_30 , const T_5 * V_41 , int V_57 )
{
F_31 ( V_3 , V_41 , V_3 -> V_59 ) ;
F_31 ( V_3 , V_30 -> V_60 , V_3 -> V_61 ) ;
return 0 ;
}
static int F_57 ( struct V_1 * V_20 )
{
int V_32 ;
if ( ! V_62 )
return 0 ;
F_58 ( & V_20 -> V_47 ) ;
V_32 = F_59 ( V_46 , L_12 ) ;
if ( V_32 < 0 ) {
F_15 ( V_20 -> V_28 , L_13 ) ;
return V_32 ;
}
#ifdef F_49
F_60 ( F_61 () & ~ 1 ) ;
F_11 () ;
#endif
F_62 ( V_46 , F_35 , V_20 ) ;
F_37 ( V_46 ) ;
return 0 ;
}
static void F_63 ( struct V_1 * V_20 )
{
if ( V_62 )
F_64 ( V_46 ) ;
}
static int F_65 ( struct V_1 * V_20 )
{
int V_63 = 0 ;
unsigned short V_15 ;
struct V_6 * V_64 = V_20 -> V_65 ;
F_16 ( V_20 -> V_28 ,
L_14 ,
( V_64 -> V_66 ? 16 : 8 ) ,
V_64 -> V_67 , V_64 -> V_68 ) ;
V_15 = ( 1 << V_69 ) |
( V_64 -> V_66 << V_70 ) |
( V_64 -> V_68 << V_71 ) |
( V_64 -> V_67 << V_72 ) ;
F_22 ( V_20 -> V_28 , L_15 , V_15 ) ;
F_66 ( V_15 ) ;
F_11 () ;
F_67 ( 0x0 ) ;
F_11 () ;
V_15 = F_27 () ;
F_29 ( V_15 ) ;
F_11 () ;
if ( F_57 ( V_20 ) )
V_63 = - V_73 ;
return V_63 ;
}
static int F_68 ( struct V_1 * V_20 )
{
struct V_2 * V_3 = & V_20 -> V_3 ;
struct V_74 * V_75 = V_20 -> V_65 -> V_76 ;
int V_77 = V_20 -> V_65 -> V_78 ;
return F_69 ( V_3 , V_75 , V_77 ) ;
}
static int F_70 ( struct V_4 * V_5 )
{
struct V_1 * V_20 = F_3 ( V_5 ) ;
F_71 ( V_5 , NULL ) ;
F_72 ( & V_20 -> V_3 ) ;
F_73 ( V_79 ) ;
F_63 ( V_20 ) ;
F_74 ( V_20 ) ;
return 0 ;
}
static int F_75 ( struct V_2 * V_3 )
{
struct V_29 * V_30 = V_3 -> V_31 ;
int V_32 ;
V_32 = F_76 ( V_3 , 1 , NULL ) ;
if ( V_32 )
return V_32 ;
if ( V_62 ) {
if ( F_77 ( V_3 -> V_59 >= 512 ) ) {
V_30 -> V_33 . V_34 = 512 ;
V_30 -> V_33 . V_80 = 6 ;
V_30 -> V_33 . V_81 = 2 ;
} else {
V_30 -> V_33 . V_34 = 256 ;
V_30 -> V_33 . V_80 = 3 ;
V_30 -> V_33 . V_81 = 1 ;
F_66 ( F_78 () & ~ ( 1 << V_69 ) ) ;
F_11 () ;
}
}
return F_79 ( V_3 ) ;
}
static int F_80 ( struct V_4 * V_5 )
{
struct V_6 * V_64 = F_5 ( V_5 ) ;
struct V_1 * V_20 = NULL ;
struct V_29 * V_30 = NULL ;
struct V_2 * V_3 = NULL ;
int V_63 = 0 ;
F_22 ( & V_5 -> V_7 , L_16 , V_5 ) ;
if ( ! V_64 ) {
F_15 ( & V_5 -> V_7 , L_17 ) ;
return - V_82 ;
}
if ( F_81 ( V_79 , V_83 ) ) {
F_15 ( & V_5 -> V_7 , L_18 ) ;
return - V_84 ;
}
V_20 = F_82 ( sizeof( * V_20 ) , V_85 ) ;
if ( V_20 == NULL ) {
F_15 ( & V_5 -> V_7 , L_19 ) ;
V_63 = - V_86 ;
goto V_87;
}
F_71 ( V_5 , V_20 ) ;
F_83 ( & V_20 -> V_88 . V_89 ) ;
F_84 ( & V_20 -> V_88 . V_90 ) ;
V_20 -> V_28 = & V_5 -> V_7 ;
V_20 -> V_65 = V_64 ;
V_30 = & V_20 -> V_30 ;
if ( V_64 -> V_66 )
V_30 -> V_91 |= V_92 ;
V_30 -> V_91 |= V_93 | V_94 ;
V_30 -> V_95 = ( V_64 -> V_66 ) ?
F_33 : F_25 ;
V_30 -> V_96 = ( V_64 -> V_66 ) ?
F_34 : F_31 ;
V_30 -> V_97 = F_30 ;
V_30 -> V_98 = F_6 ;
V_30 -> V_99 = F_12 ;
V_30 -> V_31 = & V_20 -> V_3 ;
V_30 -> V_88 = & V_20 -> V_88 ;
V_30 -> V_100 = ( void V_101 * ) V_102 ;
V_30 -> V_103 = ( void V_101 * ) V_104 ;
V_30 -> V_105 = 0 ;
V_3 = & V_20 -> V_3 ;
V_3 -> V_31 = V_30 ;
V_3 -> V_106 = V_107 ;
V_63 = F_65 ( V_20 ) ;
if ( V_63 )
goto V_108;
if ( V_62 ) {
#ifdef F_85
V_30 -> V_33 . V_109 = & V_110 ;
#endif
V_30 -> V_95 = F_53 ;
V_30 -> V_96 = F_54 ;
V_30 -> V_33 . V_111 = F_19 ;
V_30 -> V_33 . V_112 = F_17 ;
V_30 -> V_33 . V_35 = V_113 ;
V_30 -> V_33 . V_114 = F_18 ;
V_30 -> V_33 . V_115 = F_55 ;
V_30 -> V_33 . V_116 = F_56 ;
} else {
V_30 -> V_33 . V_35 = V_117 ;
}
if ( F_75 ( V_3 ) ) {
V_63 = - V_73 ;
goto V_118;
}
#ifdef F_85
V_30 -> V_119 = 63 ;
#endif
F_68 ( V_20 ) ;
F_22 ( & V_5 -> V_7 , L_20 ) ;
return 0 ;
V_118:
F_63 ( V_20 ) ;
V_108:
F_71 ( V_5 , NULL ) ;
F_74 ( V_20 ) ;
V_87:
F_73 ( V_79 ) ;
return V_63 ;
}
static int F_86 ( struct V_4 * V_7 , T_7 V_120 )
{
struct V_1 * V_20 = F_4 ( V_7 ) ;
return 0 ;
}
static int F_87 ( struct V_4 * V_7 )
{
struct V_1 * V_20 = F_4 ( V_7 ) ;
return 0 ;
}
static int T_8 F_88 ( void )
{
F_89 ( V_121 L_21 ,
V_122 , V_123 ) ;
return F_90 ( & V_124 ) ;
}
static void T_9 F_91 ( void )
{
F_92 ( & V_124 ) ;
}
