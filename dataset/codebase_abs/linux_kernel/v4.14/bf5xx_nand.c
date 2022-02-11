static int F_1 ( struct V_1 * V_2 , int V_3 ,
struct V_4 * V_5 )
{
if ( V_3 > 7 )
return - V_6 ;
V_5 -> V_7 = V_3 * 8 ;
V_5 -> V_8 = 3 ;
return 0 ;
}
static int F_2 ( struct V_1 * V_2 , int V_3 ,
struct V_4 * V_5 )
{
if ( V_3 > 7 )
return - V_6 ;
V_5 -> V_7 = ( V_3 * 8 ) + 3 ;
V_5 -> V_8 = 5 ;
return 0 ;
}
static struct V_9 * F_3 ( struct V_1 * V_2 )
{
return F_4 ( F_5 ( V_2 ) , struct V_9 ,
V_10 ) ;
}
static struct V_9 * F_6 ( struct V_11 * V_12 )
{
return F_7 ( V_12 ) ;
}
static struct V_13 * F_8 ( struct V_11 * V_12 )
{
return F_9 ( & V_12 -> V_14 ) ;
}
static void F_10 ( struct V_1 * V_2 , int V_15 ,
unsigned int V_16 )
{
if ( V_15 == V_17 )
return;
while ( F_11 () & V_18 )
F_12 () ;
if ( V_16 & V_19 )
F_13 ( V_15 ) ;
else if ( V_16 & V_20 )
F_14 ( V_15 ) ;
F_15 () ;
}
static int F_16 ( struct V_1 * V_2 )
{
unsigned short V_21 = F_11 () ;
if ( ( V_21 & V_22 ) == V_22 )
return 1 ;
else
return 0 ;
}
static int F_17 ( struct V_1 * V_2 , T_1 * V_23 ,
T_1 * V_24 , T_1 * V_25 )
{
struct V_9 * V_26 = F_3 ( V_2 ) ;
T_2 V_27 [ 5 ] ;
T_2 V_28 , V_29 ;
int V_30 ;
unsigned short V_31 , V_32 ;
T_1 V_33 ;
V_28 = V_25 [ 0 ] | ( V_25 [ 1 ] << 8 ) | ( V_25 [ 2 ] << 16 ) ;
V_29 = V_24 [ 0 ] | ( V_24 [ 1 ] << 8 ) | ( V_24 [ 2 ] << 16 ) ;
V_27 [ 0 ] = ( V_28 ^ V_29 ) ;
if ( ! V_27 [ 0 ] || ! V_28 || ! V_29 )
return 0 ;
if ( F_18 ( V_27 [ 0 ] ) == 1 ) {
F_19 ( V_26 -> V_34 , L_1 ) ;
return - V_35 ;
}
V_27 [ 1 ] = ( V_28 & 0x7FF ) ^ ( V_29 & 0x7FF ) ;
V_27 [ 2 ] = ( V_28 & 0x7FF ) ^ ( ( V_28 >> 11 ) & 0x7FF ) ;
V_27 [ 3 ] = ( V_29 & 0x7FF ) ^ ( ( V_29 >> 11 ) & 0x7FF ) ;
V_27 [ 4 ] = V_27 [ 2 ] ^ V_27 [ 3 ] ;
for ( V_30 = 0 ; V_30 < 5 ; V_30 ++ )
F_20 ( V_26 -> V_34 , L_2 , V_30 , V_27 [ V_30 ] ) ;
F_20 ( V_26 -> V_34 ,
L_3 ,
V_28 , V_29 ) ;
if ( F_18 ( V_27 [ 0 ] ) == 11 && V_27 [ 4 ] == 0x7FF ) {
F_20 ( V_26 -> V_34 ,
L_4 ) ;
F_20 ( V_26 -> V_34 ,
L_5 , V_27 [ 1 ] ) ;
V_31 = V_27 [ 1 ] & 0x7 ;
V_32 = V_27 [ 1 ] >> 0x3 ;
V_33 = * ( V_23 + V_32 ) ;
V_33 = V_33 ^ ( 0x1 << V_31 ) ;
* ( V_23 + V_32 ) = V_33 ;
return 1 ;
}
F_19 ( V_26 -> V_34 ,
L_6 ) ;
F_19 ( V_26 -> V_34 ,
L_7 ) ;
return - V_35 ;
}
static int F_21 ( struct V_1 * V_2 , T_1 * V_23 ,
T_1 * V_24 , T_1 * V_25 )
{
struct V_36 * V_10 = F_5 ( V_2 ) ;
int V_37 , V_38 = 0 ;
V_37 = F_17 ( V_2 , V_23 , V_24 , V_25 ) ;
if ( V_37 < 0 )
return V_37 ;
V_38 = V_37 ;
if ( V_10 -> V_39 . V_40 == 512 ) {
V_23 += 256 ;
V_24 += 3 ;
V_25 += 3 ;
V_37 = F_17 ( V_2 , V_23 , V_24 , V_25 ) ;
if ( V_37 < 0 )
return V_37 ;
V_38 += V_37 ;
}
return V_38 ;
}
static void F_22 ( struct V_1 * V_2 , int V_41 )
{
return;
}
static int F_23 ( struct V_1 * V_2 ,
const T_1 * V_23 , T_1 * V_42 )
{
struct V_9 * V_26 = F_3 ( V_2 ) ;
struct V_36 * V_10 = F_5 ( V_2 ) ;
T_3 V_43 , V_44 ;
T_2 V_45 [ 2 ] ;
T_4 * V_46 ;
V_43 = F_24 () ;
V_44 = F_25 () ;
V_45 [ 0 ] = ( V_43 & 0x7ff ) | ( ( V_44 & 0x7ff ) << 11 ) ;
F_26 ( V_26 -> V_34 , L_8 , V_45 [ 0 ] ) ;
V_46 = ( T_4 * ) V_45 ;
memcpy ( V_42 , V_46 , 3 ) ;
if ( V_10 -> V_39 . V_40 == 512 ) {
V_43 = F_27 () ;
V_44 = F_28 () ;
V_45 [ 1 ] = ( V_43 & 0x7ff ) | ( ( V_44 & 0x7ff ) << 11 ) ;
V_46 = ( T_4 * ) ( V_45 + 1 ) ;
memcpy ( ( V_42 + 3 ) , V_46 , 3 ) ;
F_26 ( V_26 -> V_34 , L_8 , V_45 [ 1 ] ) ;
}
return 0 ;
}
static void F_29 ( struct V_1 * V_2 , T_5 * V_47 , int V_48 )
{
int V_30 ;
unsigned short V_21 ;
for ( V_30 = 0 ; V_30 < V_48 ; V_30 ++ ) {
while ( F_11 () & V_18 )
F_12 () ;
F_30 ( 0x0000 ) ;
F_15 () ;
while ( ( F_31 () & V_49 ) != V_49 )
F_12 () ;
V_47 [ V_30 ] = F_32 () ;
V_21 = F_31 () ;
V_21 |= V_49 ;
F_33 ( V_21 ) ;
F_15 () ;
}
}
static T_5 F_34 ( struct V_1 * V_2 )
{
T_5 V_21 ;
F_29 ( V_2 , & V_21 , 1 ) ;
return V_21 ;
}
static void F_35 ( struct V_1 * V_2 ,
const T_5 * V_47 , int V_48 )
{
int V_30 ;
for ( V_30 = 0 ; V_30 < V_48 ; V_30 ++ ) {
while ( F_11 () & V_18 )
F_12 () ;
F_36 ( V_47 [ V_30 ] ) ;
F_15 () ;
}
}
static void F_37 ( struct V_1 * V_2 , T_5 * V_47 , int V_48 )
{
int V_30 ;
T_3 * V_46 = ( T_3 * ) V_47 ;
V_48 >>= 1 ;
F_30 ( 0x5555 ) ;
F_15 () ;
for ( V_30 = 0 ; V_30 < V_48 ; V_30 ++ )
V_46 [ V_30 ] = F_32 () ;
}
static void F_38 ( struct V_1 * V_2 ,
const T_5 * V_47 , int V_48 )
{
int V_30 ;
T_3 * V_46 = ( T_3 * ) V_47 ;
V_48 >>= 1 ;
for ( V_30 = 0 ; V_30 < V_48 ; V_30 ++ )
F_36 ( V_46 [ V_30 ] ) ;
F_15 () ;
}
static T_6 F_39 ( int V_50 , void * V_51 )
{
struct V_9 * V_26 = V_51 ;
F_40 ( V_52 ) ;
F_41 ( V_52 ) ;
F_42 ( & V_26 -> V_53 ) ;
return V_54 ;
}
static void F_43 ( struct V_1 * V_2 ,
T_5 * V_47 , int V_55 )
{
struct V_9 * V_26 = F_3 ( V_2 ) ;
struct V_36 * V_10 = F_5 ( V_2 ) ;
unsigned short V_21 ;
F_26 ( V_26 -> V_34 , L_9 ,
V_2 , V_47 , V_55 ) ;
if ( V_55 )
F_44 ( ( unsigned int ) V_47 ,
( unsigned int ) ( V_47 + V_10 -> V_39 . V_40 ) ) ;
else
F_45 ( ( unsigned int ) V_47 ,
( unsigned int ) ( V_47 + V_10 -> V_39 . V_40 ) ) ;
F_46 ( V_56 ) ;
F_15 () ;
while ( F_47 () & V_56 )
F_12 () ;
F_41 ( V_52 ) ;
F_40 ( V_52 ) ;
F_48 ( V_52 , 0x0 ) ;
F_49 ( V_52 , ( unsigned long ) V_47 ) ;
#ifdef F_50
F_51 ( V_52 , ( V_10 -> V_39 . V_40 >> 1 ) ) ;
F_52 ( V_52 , 2 ) ;
V_21 = V_57 | V_58 ;
#endif
#ifdef F_53
F_51 ( V_52 , ( V_10 -> V_39 . V_40 >> 2 ) ) ;
F_52 ( V_52 , 4 ) ;
V_21 = V_57 | V_59 ;
#endif
if ( V_55 )
V_21 |= V_60 ;
F_48 ( V_52 , V_21 ) ;
F_54 ( V_52 ) ;
if ( V_55 )
F_55 ( V_61 ) ;
else
F_55 ( V_62 ) ;
F_56 ( & V_26 -> V_53 ) ;
}
static void F_57 ( struct V_1 * V_2 ,
T_5 * V_47 , int V_48 )
{
struct V_9 * V_26 = F_3 ( V_2 ) ;
struct V_36 * V_10 = F_5 ( V_2 ) ;
F_26 ( V_26 -> V_34 , L_10 , V_2 , V_47 , V_48 ) ;
if ( V_48 == V_10 -> V_39 . V_40 )
F_43 ( V_2 , V_47 , 1 ) ;
else
F_29 ( V_2 , V_47 , V_48 ) ;
}
static void F_58 ( struct V_1 * V_2 ,
const T_5 * V_47 , int V_48 )
{
struct V_9 * V_26 = F_3 ( V_2 ) ;
struct V_36 * V_10 = F_5 ( V_2 ) ;
F_26 ( V_26 -> V_34 , L_11 , V_2 , V_47 , V_48 ) ;
if ( V_48 == V_10 -> V_39 . V_40 )
F_43 ( V_2 , ( T_5 * ) V_47 , 0 ) ;
else
F_35 ( V_2 , V_47 , V_48 ) ;
}
static int F_59 ( struct V_1 * V_2 , struct V_36 * V_10 ,
T_5 * V_47 , int V_63 , int V_64 )
{
F_29 ( V_2 , V_47 , V_2 -> V_65 ) ;
F_29 ( V_2 , V_10 -> V_66 , V_2 -> V_67 ) ;
return 0 ;
}
static int F_60 ( struct V_1 * V_2 ,
struct V_36 * V_10 , const T_5 * V_47 , int V_63 ,
int V_64 )
{
F_35 ( V_2 , V_47 , V_2 -> V_65 ) ;
F_35 ( V_2 , V_10 -> V_66 , V_2 -> V_67 ) ;
return 0 ;
}
static int F_61 ( struct V_9 * V_26 )
{
int V_37 ;
if ( ! V_68 )
return 0 ;
F_62 ( & V_26 -> V_53 ) ;
V_37 = F_63 ( V_52 , L_12 ) ;
if ( V_37 < 0 ) {
F_19 ( V_26 -> V_34 , L_13 ) ;
return V_37 ;
}
#ifdef F_53
F_64 ( F_65 () & ~ 1 ) ;
F_15 () ;
#endif
F_66 ( V_52 , F_39 , V_26 ) ;
F_41 ( V_52 ) ;
return 0 ;
}
static void F_67 ( struct V_9 * V_26 )
{
if ( V_68 )
F_68 ( V_52 ) ;
}
static int F_69 ( struct V_9 * V_26 )
{
int V_69 = 0 ;
unsigned short V_21 ;
struct V_13 * V_70 = V_26 -> V_71 ;
F_20 ( V_26 -> V_34 ,
L_14 ,
( V_70 -> V_72 ? 16 : 8 ) ,
V_70 -> V_73 , V_70 -> V_74 ) ;
V_21 = ( 1 << V_75 ) |
( V_70 -> V_72 << V_76 ) |
( V_70 -> V_74 << V_77 ) |
( V_70 -> V_73 << V_78 ) ;
F_26 ( V_26 -> V_34 , L_15 , V_21 ) ;
F_70 ( V_21 ) ;
F_15 () ;
F_71 ( 0x0 ) ;
F_15 () ;
V_21 = F_31 () ;
F_33 ( V_21 ) ;
F_15 () ;
if ( F_61 ( V_26 ) )
V_69 = - V_79 ;
return V_69 ;
}
static int F_72 ( struct V_9 * V_26 )
{
struct V_1 * V_2 = F_73 ( & V_26 -> V_10 ) ;
struct V_80 * V_81 = V_26 -> V_71 -> V_82 ;
int V_83 = V_26 -> V_71 -> V_84 ;
return F_74 ( V_2 , V_81 , V_83 ) ;
}
static int F_75 ( struct V_11 * V_12 )
{
struct V_9 * V_26 = F_6 ( V_12 ) ;
F_76 ( F_73 ( & V_26 -> V_10 ) ) ;
F_77 ( V_85 ) ;
F_67 ( V_26 ) ;
return 0 ;
}
static int F_78 ( struct V_1 * V_2 )
{
struct V_36 * V_10 = F_5 ( V_2 ) ;
int V_37 ;
V_37 = F_79 ( V_2 , 1 , NULL ) ;
if ( V_37 )
return V_37 ;
if ( V_68 ) {
if ( F_80 ( V_2 -> V_65 >= 512 ) ) {
V_10 -> V_39 . V_40 = 512 ;
V_10 -> V_39 . V_86 = 6 ;
V_10 -> V_39 . V_87 = 2 ;
} else {
V_10 -> V_39 . V_40 = 256 ;
V_10 -> V_39 . V_86 = 3 ;
V_10 -> V_39 . V_87 = 1 ;
F_70 ( F_81 () & ~ ( 1 << V_75 ) ) ;
F_15 () ;
}
}
return F_82 ( V_2 ) ;
}
static int F_83 ( struct V_11 * V_12 )
{
struct V_13 * V_70 = F_8 ( V_12 ) ;
struct V_9 * V_26 = NULL ;
struct V_36 * V_10 = NULL ;
struct V_1 * V_2 = NULL ;
int V_69 = 0 ;
F_26 ( & V_12 -> V_14 , L_16 , V_12 ) ;
if ( ! V_70 ) {
F_19 ( & V_12 -> V_14 , L_17 ) ;
return - V_88 ;
}
if ( F_84 ( V_85 , V_89 ) ) {
F_19 ( & V_12 -> V_14 , L_18 ) ;
return - V_90 ;
}
V_26 = F_85 ( & V_12 -> V_14 , sizeof( * V_26 ) , V_91 ) ;
if ( V_26 == NULL ) {
V_69 = - V_92 ;
goto V_93;
}
F_86 ( V_12 , V_26 ) ;
F_87 ( & V_26 -> V_94 ) ;
V_26 -> V_34 = & V_12 -> V_14 ;
V_26 -> V_71 = V_70 ;
V_10 = & V_26 -> V_10 ;
V_2 = F_73 ( & V_26 -> V_10 ) ;
if ( V_70 -> V_72 )
V_10 -> V_95 |= V_96 ;
V_10 -> V_95 |= V_97 | V_98 ;
V_10 -> V_99 = ( V_70 -> V_72 ) ?
F_37 : F_29 ;
V_10 -> V_100 = ( V_70 -> V_72 ) ?
F_38 : F_35 ;
V_10 -> V_101 = F_34 ;
V_10 -> V_102 = F_10 ;
V_10 -> V_103 = F_16 ;
F_88 ( V_10 , V_2 ) ;
V_10 -> V_94 = & V_26 -> V_94 ;
V_10 -> V_104 = ( void V_105 * ) V_106 ;
V_10 -> V_107 = ( void V_105 * ) V_108 ;
V_10 -> V_109 = 0 ;
V_2 -> V_14 . V_110 = & V_12 -> V_14 ;
V_69 = F_69 ( V_26 ) ;
if ( V_69 )
goto V_93;
if ( V_68 ) {
#ifdef F_89
F_90 ( V_2 , & V_111 ) ;
#endif
V_10 -> V_99 = F_57 ;
V_10 -> V_100 = F_58 ;
V_10 -> V_39 . V_112 = F_23 ;
V_10 -> V_39 . V_113 = F_21 ;
V_10 -> V_39 . V_41 = V_114 ;
V_10 -> V_39 . V_115 = F_22 ;
V_10 -> V_39 . V_116 = F_59 ;
V_10 -> V_39 . V_117 = F_60 ;
} else {
V_10 -> V_39 . V_41 = V_118 ;
V_10 -> V_39 . V_119 = V_120 ;
}
if ( F_78 ( V_2 ) ) {
V_69 = - V_79 ;
goto V_121;
}
#ifdef F_89
V_10 -> V_122 = 63 ;
#endif
F_72 ( V_26 ) ;
F_26 ( & V_12 -> V_14 , L_19 ) ;
return 0 ;
V_121:
F_67 ( V_26 ) ;
V_93:
F_77 ( V_85 ) ;
return V_69 ;
}
