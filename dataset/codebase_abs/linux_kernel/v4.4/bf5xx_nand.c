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
return F_6 ( & V_5 -> V_7 ) ;
}
static void F_7 ( struct V_2 * V_3 , int V_8 ,
unsigned int V_9 )
{
if ( V_8 == V_10 )
return;
while ( F_8 () & V_11 )
F_9 () ;
if ( V_9 & V_12 )
F_10 ( V_8 ) ;
else if ( V_9 & V_13 )
F_11 ( V_8 ) ;
F_12 () ;
}
static int F_13 ( struct V_2 * V_3 )
{
unsigned short V_14 = F_8 () ;
if ( ( V_14 & V_15 ) == V_15 )
return 1 ;
else
return 0 ;
}
static int F_14 ( struct V_2 * V_3 , T_1 * V_16 ,
T_1 * V_17 , T_1 * V_18 )
{
struct V_1 * V_19 = F_1 ( V_3 ) ;
T_2 V_20 [ 5 ] ;
T_2 V_21 , V_22 ;
int V_23 ;
unsigned short V_24 , V_25 ;
T_1 V_26 ;
V_21 = V_18 [ 0 ] | ( V_18 [ 1 ] << 8 ) | ( V_18 [ 2 ] << 16 ) ;
V_22 = V_17 [ 0 ] | ( V_17 [ 1 ] << 8 ) | ( V_17 [ 2 ] << 16 ) ;
V_20 [ 0 ] = ( V_21 ^ V_22 ) ;
if ( ! V_20 [ 0 ] || ! V_21 || ! V_22 )
return 0 ;
if ( F_15 ( V_20 [ 0 ] ) == 1 ) {
F_16 ( V_19 -> V_27 , L_1 ) ;
return 1 ;
}
V_20 [ 1 ] = ( V_21 & 0x7FF ) ^ ( V_22 & 0x7FF ) ;
V_20 [ 2 ] = ( V_21 & 0x7FF ) ^ ( ( V_21 >> 11 ) & 0x7FF ) ;
V_20 [ 3 ] = ( V_22 & 0x7FF ) ^ ( ( V_22 >> 11 ) & 0x7FF ) ;
V_20 [ 4 ] = V_20 [ 2 ] ^ V_20 [ 3 ] ;
for ( V_23 = 0 ; V_23 < 5 ; V_23 ++ )
F_17 ( V_19 -> V_27 , L_2 , V_23 , V_20 [ V_23 ] ) ;
F_17 ( V_19 -> V_27 ,
L_3 ,
V_21 , V_22 ) ;
if ( F_15 ( V_20 [ 0 ] ) == 11 && V_20 [ 4 ] == 0x7FF ) {
F_17 ( V_19 -> V_27 ,
L_4 ) ;
F_17 ( V_19 -> V_27 ,
L_5 , V_20 [ 1 ] ) ;
V_24 = V_20 [ 1 ] & 0x7 ;
V_25 = V_20 [ 1 ] >> 0x3 ;
V_26 = * ( V_16 + V_25 ) ;
V_26 = V_26 ^ ( 0x1 << V_24 ) ;
* ( V_16 + V_25 ) = V_26 ;
return 0 ;
}
F_16 ( V_19 -> V_27 ,
L_6 ) ;
F_16 ( V_19 -> V_27 ,
L_7 ) ;
return 1 ;
}
static int F_18 ( struct V_2 * V_3 , T_1 * V_16 ,
T_1 * V_17 , T_1 * V_18 )
{
struct V_28 * V_29 = V_3 -> V_30 ;
int V_31 ;
V_31 = F_14 ( V_3 , V_16 , V_17 , V_18 ) ;
if ( V_29 -> V_32 . V_33 == 512 ) {
V_16 += 256 ;
V_17 += 3 ;
V_18 += 3 ;
V_31 |= F_14 ( V_3 , V_16 , V_17 , V_18 ) ;
}
return V_31 ;
}
static void F_19 ( struct V_2 * V_3 , int V_34 )
{
return;
}
static int F_20 ( struct V_2 * V_3 ,
const T_1 * V_16 , T_1 * V_35 )
{
struct V_1 * V_19 = F_1 ( V_3 ) ;
struct V_28 * V_29 = V_3 -> V_30 ;
T_3 V_36 , V_37 ;
T_2 V_38 [ 2 ] ;
T_4 * V_39 ;
V_36 = F_21 () ;
V_37 = F_22 () ;
V_38 [ 0 ] = ( V_36 & 0x7ff ) | ( ( V_37 & 0x7ff ) << 11 ) ;
F_23 ( V_19 -> V_27 , L_8 , V_38 [ 0 ] ) ;
V_39 = ( T_4 * ) V_38 ;
memcpy ( V_35 , V_39 , 3 ) ;
if ( V_29 -> V_32 . V_33 == 512 ) {
V_36 = F_24 () ;
V_37 = F_25 () ;
V_38 [ 1 ] = ( V_36 & 0x7ff ) | ( ( V_37 & 0x7ff ) << 11 ) ;
V_39 = ( T_4 * ) ( V_38 + 1 ) ;
memcpy ( ( V_35 + 3 ) , V_39 , 3 ) ;
F_23 ( V_19 -> V_27 , L_8 , V_38 [ 1 ] ) ;
}
return 0 ;
}
static void F_26 ( struct V_2 * V_3 , T_5 * V_40 , int V_41 )
{
int V_23 ;
unsigned short V_14 ;
for ( V_23 = 0 ; V_23 < V_41 ; V_23 ++ ) {
while ( F_8 () & V_11 )
F_9 () ;
F_27 ( 0x0000 ) ;
F_12 () ;
while ( ( F_28 () & V_42 ) != V_42 )
F_9 () ;
V_40 [ V_23 ] = F_29 () ;
V_14 = F_28 () ;
V_14 |= V_42 ;
F_30 ( V_14 ) ;
F_12 () ;
}
}
static T_5 F_31 ( struct V_2 * V_3 )
{
T_5 V_14 ;
F_26 ( V_3 , & V_14 , 1 ) ;
return V_14 ;
}
static void F_32 ( struct V_2 * V_3 ,
const T_5 * V_40 , int V_41 )
{
int V_23 ;
for ( V_23 = 0 ; V_23 < V_41 ; V_23 ++ ) {
while ( F_8 () & V_11 )
F_9 () ;
F_33 ( V_40 [ V_23 ] ) ;
F_12 () ;
}
}
static void F_34 ( struct V_2 * V_3 , T_5 * V_40 , int V_41 )
{
int V_23 ;
T_3 * V_39 = ( T_3 * ) V_40 ;
V_41 >>= 1 ;
F_27 ( 0x5555 ) ;
F_12 () ;
for ( V_23 = 0 ; V_23 < V_41 ; V_23 ++ )
V_39 [ V_23 ] = F_29 () ;
}
static void F_35 ( struct V_2 * V_3 ,
const T_5 * V_40 , int V_41 )
{
int V_23 ;
T_3 * V_39 = ( T_3 * ) V_40 ;
V_41 >>= 1 ;
for ( V_23 = 0 ; V_23 < V_41 ; V_23 ++ )
F_33 ( V_39 [ V_23 ] ) ;
F_12 () ;
}
static T_6 F_36 ( int V_43 , void * V_44 )
{
struct V_1 * V_19 = V_44 ;
F_37 ( V_45 ) ;
F_38 ( V_45 ) ;
F_39 ( & V_19 -> V_46 ) ;
return V_47 ;
}
static void F_40 ( struct V_2 * V_3 ,
T_5 * V_40 , int V_48 )
{
struct V_1 * V_19 = F_1 ( V_3 ) ;
struct V_28 * V_29 = V_3 -> V_30 ;
unsigned short V_14 ;
F_23 ( V_19 -> V_27 , L_9 ,
V_3 , V_40 , V_48 ) ;
if ( V_48 )
F_41 ( ( unsigned int ) V_40 ,
( unsigned int ) ( V_40 + V_29 -> V_32 . V_33 ) ) ;
else
F_42 ( ( unsigned int ) V_40 ,
( unsigned int ) ( V_40 + V_29 -> V_32 . V_33 ) ) ;
F_43 ( V_49 ) ;
F_12 () ;
while ( F_44 () & V_49 )
F_9 () ;
F_38 ( V_45 ) ;
F_37 ( V_45 ) ;
F_45 ( V_45 , 0x0 ) ;
F_46 ( V_45 , ( unsigned long ) V_40 ) ;
#ifdef F_47
F_48 ( V_45 , ( V_29 -> V_32 . V_33 >> 1 ) ) ;
F_49 ( V_45 , 2 ) ;
V_14 = V_50 | V_51 ;
#endif
#ifdef F_50
F_48 ( V_45 , ( V_29 -> V_32 . V_33 >> 2 ) ) ;
F_49 ( V_45 , 4 ) ;
V_14 = V_50 | V_52 ;
#endif
if ( V_48 )
V_14 |= V_53 ;
F_45 ( V_45 , V_14 ) ;
F_51 ( V_45 ) ;
if ( V_48 )
F_52 ( V_54 ) ;
else
F_52 ( V_55 ) ;
F_53 ( & V_19 -> V_46 ) ;
}
static void F_54 ( struct V_2 * V_3 ,
T_5 * V_40 , int V_41 )
{
struct V_1 * V_19 = F_1 ( V_3 ) ;
struct V_28 * V_29 = V_3 -> V_30 ;
F_23 ( V_19 -> V_27 , L_10 , V_3 , V_40 , V_41 ) ;
if ( V_41 == V_29 -> V_32 . V_33 )
F_40 ( V_3 , V_40 , 1 ) ;
else
F_26 ( V_3 , V_40 , V_41 ) ;
}
static void F_55 ( struct V_2 * V_3 ,
const T_5 * V_40 , int V_41 )
{
struct V_1 * V_19 = F_1 ( V_3 ) ;
struct V_28 * V_29 = V_3 -> V_30 ;
F_23 ( V_19 -> V_27 , L_11 , V_3 , V_40 , V_41 ) ;
if ( V_41 == V_29 -> V_32 . V_33 )
F_40 ( V_3 , ( T_5 * ) V_40 , 0 ) ;
else
F_32 ( V_3 , V_40 , V_41 ) ;
}
static int F_56 ( struct V_2 * V_3 , struct V_28 * V_29 ,
T_5 * V_40 , int V_56 , int V_57 )
{
F_26 ( V_3 , V_40 , V_3 -> V_58 ) ;
F_26 ( V_3 , V_29 -> V_59 , V_3 -> V_60 ) ;
return 0 ;
}
static int F_57 ( struct V_2 * V_3 ,
struct V_28 * V_29 , const T_5 * V_40 , int V_56 ,
int V_57 )
{
F_32 ( V_3 , V_40 , V_3 -> V_58 ) ;
F_32 ( V_3 , V_29 -> V_59 , V_3 -> V_60 ) ;
return 0 ;
}
static int F_58 ( struct V_1 * V_19 )
{
int V_31 ;
if ( ! V_61 )
return 0 ;
F_59 ( & V_19 -> V_46 ) ;
V_31 = F_60 ( V_45 , L_12 ) ;
if ( V_31 < 0 ) {
F_16 ( V_19 -> V_27 , L_13 ) ;
return V_31 ;
}
#ifdef F_50
F_61 ( F_62 () & ~ 1 ) ;
F_12 () ;
#endif
F_63 ( V_45 , F_36 , V_19 ) ;
F_38 ( V_45 ) ;
return 0 ;
}
static void F_64 ( struct V_1 * V_19 )
{
if ( V_61 )
F_65 ( V_45 ) ;
}
static int F_66 ( struct V_1 * V_19 )
{
int V_62 = 0 ;
unsigned short V_14 ;
struct V_6 * V_63 = V_19 -> V_64 ;
F_17 ( V_19 -> V_27 ,
L_14 ,
( V_63 -> V_65 ? 16 : 8 ) ,
V_63 -> V_66 , V_63 -> V_67 ) ;
V_14 = ( 1 << V_68 ) |
( V_63 -> V_65 << V_69 ) |
( V_63 -> V_67 << V_70 ) |
( V_63 -> V_66 << V_71 ) ;
F_23 ( V_19 -> V_27 , L_15 , V_14 ) ;
F_67 ( V_14 ) ;
F_12 () ;
F_68 ( 0x0 ) ;
F_12 () ;
V_14 = F_28 () ;
F_30 ( V_14 ) ;
F_12 () ;
if ( F_58 ( V_19 ) )
V_62 = - V_72 ;
return V_62 ;
}
static int F_69 ( struct V_1 * V_19 )
{
struct V_2 * V_3 = & V_19 -> V_3 ;
struct V_73 * V_74 = V_19 -> V_64 -> V_75 ;
int V_76 = V_19 -> V_64 -> V_77 ;
return F_70 ( V_3 , V_74 , V_76 ) ;
}
static int F_71 ( struct V_4 * V_5 )
{
struct V_1 * V_19 = F_3 ( V_5 ) ;
F_72 ( & V_19 -> V_3 ) ;
F_73 ( V_78 ) ;
F_64 ( V_19 ) ;
return 0 ;
}
static int F_74 ( struct V_2 * V_3 )
{
struct V_28 * V_29 = V_3 -> V_30 ;
int V_31 ;
V_31 = F_75 ( V_3 , 1 , NULL ) ;
if ( V_31 )
return V_31 ;
if ( V_61 ) {
if ( F_76 ( V_3 -> V_58 >= 512 ) ) {
V_29 -> V_32 . V_33 = 512 ;
V_29 -> V_32 . V_79 = 6 ;
V_29 -> V_32 . V_80 = 2 ;
} else {
V_29 -> V_32 . V_33 = 256 ;
V_29 -> V_32 . V_79 = 3 ;
V_29 -> V_32 . V_80 = 1 ;
F_67 ( F_77 () & ~ ( 1 << V_68 ) ) ;
F_12 () ;
}
}
return F_78 ( V_3 ) ;
}
static int F_79 ( struct V_4 * V_5 )
{
struct V_6 * V_63 = F_5 ( V_5 ) ;
struct V_1 * V_19 = NULL ;
struct V_28 * V_29 = NULL ;
struct V_2 * V_3 = NULL ;
int V_62 = 0 ;
F_23 ( & V_5 -> V_7 , L_16 , V_5 ) ;
if ( ! V_63 ) {
F_16 ( & V_5 -> V_7 , L_17 ) ;
return - V_81 ;
}
if ( F_80 ( V_78 , V_82 ) ) {
F_16 ( & V_5 -> V_7 , L_18 ) ;
return - V_83 ;
}
V_19 = F_81 ( & V_5 -> V_7 , sizeof( * V_19 ) , V_84 ) ;
if ( V_19 == NULL ) {
V_62 = - V_85 ;
goto V_86;
}
F_82 ( V_5 , V_19 ) ;
F_83 ( & V_19 -> V_87 . V_88 ) ;
F_84 ( & V_19 -> V_87 . V_89 ) ;
V_19 -> V_27 = & V_5 -> V_7 ;
V_19 -> V_64 = V_63 ;
V_29 = & V_19 -> V_29 ;
if ( V_63 -> V_65 )
V_29 -> V_90 |= V_91 ;
V_29 -> V_90 |= V_92 | V_93 ;
V_29 -> V_94 = ( V_63 -> V_65 ) ?
F_34 : F_26 ;
V_29 -> V_95 = ( V_63 -> V_65 ) ?
F_35 : F_32 ;
V_29 -> V_96 = F_31 ;
V_29 -> V_97 = F_7 ;
V_29 -> V_98 = F_13 ;
V_29 -> V_30 = & V_19 -> V_3 ;
V_29 -> V_87 = & V_19 -> V_87 ;
V_29 -> V_99 = ( void V_100 * ) V_101 ;
V_29 -> V_102 = ( void V_100 * ) V_103 ;
V_29 -> V_104 = 0 ;
V_3 = & V_19 -> V_3 ;
V_3 -> V_30 = V_29 ;
V_3 -> V_7 . V_105 = & V_5 -> V_7 ;
V_62 = F_66 ( V_19 ) ;
if ( V_62 )
goto V_86;
if ( V_61 ) {
#ifdef F_85
V_29 -> V_32 . V_106 = & V_107 ;
#endif
V_29 -> V_94 = F_54 ;
V_29 -> V_95 = F_55 ;
V_29 -> V_32 . V_108 = F_20 ;
V_29 -> V_32 . V_109 = F_18 ;
V_29 -> V_32 . V_34 = V_110 ;
V_29 -> V_32 . V_111 = F_19 ;
V_29 -> V_32 . V_112 = F_56 ;
V_29 -> V_32 . V_113 = F_57 ;
} else {
V_29 -> V_32 . V_34 = V_114 ;
}
if ( F_74 ( V_3 ) ) {
V_62 = - V_72 ;
goto V_115;
}
#ifdef F_85
V_29 -> V_116 = 63 ;
#endif
F_69 ( V_19 ) ;
F_23 ( & V_5 -> V_7 , L_19 ) ;
return 0 ;
V_115:
F_64 ( V_19 ) ;
V_86:
F_73 ( V_78 ) ;
return V_62 ;
}
