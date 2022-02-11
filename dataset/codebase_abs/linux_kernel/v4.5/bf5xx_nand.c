static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( F_3 ( V_3 ) , struct V_1 ,
V_4 ) ;
}
static struct V_1 * F_4 ( struct V_5 * V_6 )
{
return F_5 ( V_6 ) ;
}
static struct V_7 * F_6 ( struct V_5 * V_6 )
{
return F_7 ( & V_6 -> V_8 ) ;
}
static void F_8 ( struct V_2 * V_3 , int V_9 ,
unsigned int V_10 )
{
if ( V_9 == V_11 )
return;
while ( F_9 () & V_12 )
F_10 () ;
if ( V_10 & V_13 )
F_11 ( V_9 ) ;
else if ( V_10 & V_14 )
F_12 ( V_9 ) ;
F_13 () ;
}
static int F_14 ( struct V_2 * V_3 )
{
unsigned short V_15 = F_9 () ;
if ( ( V_15 & V_16 ) == V_16 )
return 1 ;
else
return 0 ;
}
static int F_15 ( struct V_2 * V_3 , T_1 * V_17 ,
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
if ( F_16 ( V_21 [ 0 ] ) == 1 ) {
F_17 ( V_20 -> V_28 , L_1 ) ;
return - V_29 ;
}
V_21 [ 1 ] = ( V_22 & 0x7FF ) ^ ( V_23 & 0x7FF ) ;
V_21 [ 2 ] = ( V_22 & 0x7FF ) ^ ( ( V_22 >> 11 ) & 0x7FF ) ;
V_21 [ 3 ] = ( V_23 & 0x7FF ) ^ ( ( V_23 >> 11 ) & 0x7FF ) ;
V_21 [ 4 ] = V_21 [ 2 ] ^ V_21 [ 3 ] ;
for ( V_24 = 0 ; V_24 < 5 ; V_24 ++ )
F_18 ( V_20 -> V_28 , L_2 , V_24 , V_21 [ V_24 ] ) ;
F_18 ( V_20 -> V_28 ,
L_3 ,
V_22 , V_23 ) ;
if ( F_16 ( V_21 [ 0 ] ) == 11 && V_21 [ 4 ] == 0x7FF ) {
F_18 ( V_20 -> V_28 ,
L_4 ) ;
F_18 ( V_20 -> V_28 ,
L_5 , V_21 [ 1 ] ) ;
V_25 = V_21 [ 1 ] & 0x7 ;
V_26 = V_21 [ 1 ] >> 0x3 ;
V_27 = * ( V_17 + V_26 ) ;
V_27 = V_27 ^ ( 0x1 << V_25 ) ;
* ( V_17 + V_26 ) = V_27 ;
return 1 ;
}
F_17 ( V_20 -> V_28 ,
L_6 ) ;
F_17 ( V_20 -> V_28 ,
L_7 ) ;
return - V_29 ;
}
static int F_19 ( struct V_2 * V_3 , T_1 * V_17 ,
T_1 * V_18 , T_1 * V_19 )
{
struct V_30 * V_4 = F_3 ( V_3 ) ;
int V_31 , V_32 = 0 ;
V_31 = F_15 ( V_3 , V_17 , V_18 , V_19 ) ;
if ( V_31 < 0 )
return V_31 ;
V_32 = V_31 ;
if ( V_4 -> V_33 . V_34 == 512 ) {
V_17 += 256 ;
V_18 += 3 ;
V_19 += 3 ;
V_31 = F_15 ( V_3 , V_17 , V_18 , V_19 ) ;
if ( V_31 < 0 )
return V_31 ;
V_32 += V_31 ;
}
return V_32 ;
}
static void F_20 ( struct V_2 * V_3 , int V_35 )
{
return;
}
static int F_21 ( struct V_2 * V_3 ,
const T_1 * V_17 , T_1 * V_36 )
{
struct V_1 * V_20 = F_1 ( V_3 ) ;
struct V_30 * V_4 = F_3 ( V_3 ) ;
T_3 V_37 , V_38 ;
T_2 V_39 [ 2 ] ;
T_4 * V_40 ;
V_37 = F_22 () ;
V_38 = F_23 () ;
V_39 [ 0 ] = ( V_37 & 0x7ff ) | ( ( V_38 & 0x7ff ) << 11 ) ;
F_24 ( V_20 -> V_28 , L_8 , V_39 [ 0 ] ) ;
V_40 = ( T_4 * ) V_39 ;
memcpy ( V_36 , V_40 , 3 ) ;
if ( V_4 -> V_33 . V_34 == 512 ) {
V_37 = F_25 () ;
V_38 = F_26 () ;
V_39 [ 1 ] = ( V_37 & 0x7ff ) | ( ( V_38 & 0x7ff ) << 11 ) ;
V_40 = ( T_4 * ) ( V_39 + 1 ) ;
memcpy ( ( V_36 + 3 ) , V_40 , 3 ) ;
F_24 ( V_20 -> V_28 , L_8 , V_39 [ 1 ] ) ;
}
return 0 ;
}
static void F_27 ( struct V_2 * V_3 , T_5 * V_41 , int V_42 )
{
int V_24 ;
unsigned short V_15 ;
for ( V_24 = 0 ; V_24 < V_42 ; V_24 ++ ) {
while ( F_9 () & V_12 )
F_10 () ;
F_28 ( 0x0000 ) ;
F_13 () ;
while ( ( F_29 () & V_43 ) != V_43 )
F_10 () ;
V_41 [ V_24 ] = F_30 () ;
V_15 = F_29 () ;
V_15 |= V_43 ;
F_31 ( V_15 ) ;
F_13 () ;
}
}
static T_5 F_32 ( struct V_2 * V_3 )
{
T_5 V_15 ;
F_27 ( V_3 , & V_15 , 1 ) ;
return V_15 ;
}
static void F_33 ( struct V_2 * V_3 ,
const T_5 * V_41 , int V_42 )
{
int V_24 ;
for ( V_24 = 0 ; V_24 < V_42 ; V_24 ++ ) {
while ( F_9 () & V_12 )
F_10 () ;
F_34 ( V_41 [ V_24 ] ) ;
F_13 () ;
}
}
static void F_35 ( struct V_2 * V_3 , T_5 * V_41 , int V_42 )
{
int V_24 ;
T_3 * V_40 = ( T_3 * ) V_41 ;
V_42 >>= 1 ;
F_28 ( 0x5555 ) ;
F_13 () ;
for ( V_24 = 0 ; V_24 < V_42 ; V_24 ++ )
V_40 [ V_24 ] = F_30 () ;
}
static void F_36 ( struct V_2 * V_3 ,
const T_5 * V_41 , int V_42 )
{
int V_24 ;
T_3 * V_40 = ( T_3 * ) V_41 ;
V_42 >>= 1 ;
for ( V_24 = 0 ; V_24 < V_42 ; V_24 ++ )
F_34 ( V_40 [ V_24 ] ) ;
F_13 () ;
}
static T_6 F_37 ( int V_44 , void * V_45 )
{
struct V_1 * V_20 = V_45 ;
F_38 ( V_46 ) ;
F_39 ( V_46 ) ;
F_40 ( & V_20 -> V_47 ) ;
return V_48 ;
}
static void F_41 ( struct V_2 * V_3 ,
T_5 * V_41 , int V_49 )
{
struct V_1 * V_20 = F_1 ( V_3 ) ;
struct V_30 * V_4 = F_3 ( V_3 ) ;
unsigned short V_15 ;
F_24 ( V_20 -> V_28 , L_9 ,
V_3 , V_41 , V_49 ) ;
if ( V_49 )
F_42 ( ( unsigned int ) V_41 ,
( unsigned int ) ( V_41 + V_4 -> V_33 . V_34 ) ) ;
else
F_43 ( ( unsigned int ) V_41 ,
( unsigned int ) ( V_41 + V_4 -> V_33 . V_34 ) ) ;
F_44 ( V_50 ) ;
F_13 () ;
while ( F_45 () & V_50 )
F_10 () ;
F_39 ( V_46 ) ;
F_38 ( V_46 ) ;
F_46 ( V_46 , 0x0 ) ;
F_47 ( V_46 , ( unsigned long ) V_41 ) ;
#ifdef F_48
F_49 ( V_46 , ( V_4 -> V_33 . V_34 >> 1 ) ) ;
F_50 ( V_46 , 2 ) ;
V_15 = V_51 | V_52 ;
#endif
#ifdef F_51
F_49 ( V_46 , ( V_4 -> V_33 . V_34 >> 2 ) ) ;
F_50 ( V_46 , 4 ) ;
V_15 = V_51 | V_53 ;
#endif
if ( V_49 )
V_15 |= V_54 ;
F_46 ( V_46 , V_15 ) ;
F_52 ( V_46 ) ;
if ( V_49 )
F_53 ( V_55 ) ;
else
F_53 ( V_56 ) ;
F_54 ( & V_20 -> V_47 ) ;
}
static void F_55 ( struct V_2 * V_3 ,
T_5 * V_41 , int V_42 )
{
struct V_1 * V_20 = F_1 ( V_3 ) ;
struct V_30 * V_4 = F_3 ( V_3 ) ;
F_24 ( V_20 -> V_28 , L_10 , V_3 , V_41 , V_42 ) ;
if ( V_42 == V_4 -> V_33 . V_34 )
F_41 ( V_3 , V_41 , 1 ) ;
else
F_27 ( V_3 , V_41 , V_42 ) ;
}
static void F_56 ( struct V_2 * V_3 ,
const T_5 * V_41 , int V_42 )
{
struct V_1 * V_20 = F_1 ( V_3 ) ;
struct V_30 * V_4 = F_3 ( V_3 ) ;
F_24 ( V_20 -> V_28 , L_11 , V_3 , V_41 , V_42 ) ;
if ( V_42 == V_4 -> V_33 . V_34 )
F_41 ( V_3 , ( T_5 * ) V_41 , 0 ) ;
else
F_33 ( V_3 , V_41 , V_42 ) ;
}
static int F_57 ( struct V_2 * V_3 , struct V_30 * V_4 ,
T_5 * V_41 , int V_57 , int V_58 )
{
F_27 ( V_3 , V_41 , V_3 -> V_59 ) ;
F_27 ( V_3 , V_4 -> V_60 , V_3 -> V_61 ) ;
return 0 ;
}
static int F_58 ( struct V_2 * V_3 ,
struct V_30 * V_4 , const T_5 * V_41 , int V_57 ,
int V_58 )
{
F_33 ( V_3 , V_41 , V_3 -> V_59 ) ;
F_33 ( V_3 , V_4 -> V_60 , V_3 -> V_61 ) ;
return 0 ;
}
static int F_59 ( struct V_1 * V_20 )
{
int V_31 ;
if ( ! V_62 )
return 0 ;
F_60 ( & V_20 -> V_47 ) ;
V_31 = F_61 ( V_46 , L_12 ) ;
if ( V_31 < 0 ) {
F_17 ( V_20 -> V_28 , L_13 ) ;
return V_31 ;
}
#ifdef F_51
F_62 ( F_63 () & ~ 1 ) ;
F_13 () ;
#endif
F_64 ( V_46 , F_37 , V_20 ) ;
F_39 ( V_46 ) ;
return 0 ;
}
static void F_65 ( struct V_1 * V_20 )
{
if ( V_62 )
F_66 ( V_46 ) ;
}
static int F_67 ( struct V_1 * V_20 )
{
int V_63 = 0 ;
unsigned short V_15 ;
struct V_7 * V_64 = V_20 -> V_65 ;
F_18 ( V_20 -> V_28 ,
L_14 ,
( V_64 -> V_66 ? 16 : 8 ) ,
V_64 -> V_67 , V_64 -> V_68 ) ;
V_15 = ( 1 << V_69 ) |
( V_64 -> V_66 << V_70 ) |
( V_64 -> V_68 << V_71 ) |
( V_64 -> V_67 << V_72 ) ;
F_24 ( V_20 -> V_28 , L_15 , V_15 ) ;
F_68 ( V_15 ) ;
F_13 () ;
F_69 ( 0x0 ) ;
F_13 () ;
V_15 = F_29 () ;
F_31 ( V_15 ) ;
F_13 () ;
if ( F_59 ( V_20 ) )
V_63 = - V_73 ;
return V_63 ;
}
static int F_70 ( struct V_1 * V_20 )
{
struct V_2 * V_3 = F_71 ( & V_20 -> V_4 ) ;
struct V_74 * V_75 = V_20 -> V_65 -> V_76 ;
int V_77 = V_20 -> V_65 -> V_78 ;
return F_72 ( V_3 , V_75 , V_77 ) ;
}
static int F_73 ( struct V_5 * V_6 )
{
struct V_1 * V_20 = F_4 ( V_6 ) ;
F_74 ( F_71 ( & V_20 -> V_4 ) ) ;
F_75 ( V_79 ) ;
F_65 ( V_20 ) ;
return 0 ;
}
static int F_76 ( struct V_2 * V_3 )
{
struct V_30 * V_4 = F_3 ( V_3 ) ;
int V_31 ;
V_31 = F_77 ( V_3 , 1 , NULL ) ;
if ( V_31 )
return V_31 ;
if ( V_62 ) {
if ( F_78 ( V_3 -> V_59 >= 512 ) ) {
V_4 -> V_33 . V_34 = 512 ;
V_4 -> V_33 . V_80 = 6 ;
V_4 -> V_33 . V_81 = 2 ;
} else {
V_4 -> V_33 . V_34 = 256 ;
V_4 -> V_33 . V_80 = 3 ;
V_4 -> V_33 . V_81 = 1 ;
F_68 ( F_79 () & ~ ( 1 << V_69 ) ) ;
F_13 () ;
}
}
return F_80 ( V_3 ) ;
}
static int F_81 ( struct V_5 * V_6 )
{
struct V_7 * V_64 = F_6 ( V_6 ) ;
struct V_1 * V_20 = NULL ;
struct V_30 * V_4 = NULL ;
struct V_2 * V_3 = NULL ;
int V_63 = 0 ;
F_24 ( & V_6 -> V_8 , L_16 , V_6 ) ;
if ( ! V_64 ) {
F_17 ( & V_6 -> V_8 , L_17 ) ;
return - V_82 ;
}
if ( F_82 ( V_79 , V_83 ) ) {
F_17 ( & V_6 -> V_8 , L_18 ) ;
return - V_84 ;
}
V_20 = F_83 ( & V_6 -> V_8 , sizeof( * V_20 ) , V_85 ) ;
if ( V_20 == NULL ) {
V_63 = - V_86 ;
goto V_87;
}
F_84 ( V_6 , V_20 ) ;
F_85 ( & V_20 -> V_88 . V_89 ) ;
F_86 ( & V_20 -> V_88 . V_90 ) ;
V_20 -> V_28 = & V_6 -> V_8 ;
V_20 -> V_65 = V_64 ;
V_4 = & V_20 -> V_4 ;
V_3 = F_71 ( & V_20 -> V_4 ) ;
if ( V_64 -> V_66 )
V_4 -> V_91 |= V_92 ;
V_4 -> V_91 |= V_93 | V_94 ;
V_4 -> V_95 = ( V_64 -> V_66 ) ?
F_35 : F_27 ;
V_4 -> V_96 = ( V_64 -> V_66 ) ?
F_36 : F_33 ;
V_4 -> V_97 = F_32 ;
V_4 -> V_98 = F_8 ;
V_4 -> V_99 = F_14 ;
F_87 ( V_4 , V_3 ) ;
V_4 -> V_88 = & V_20 -> V_88 ;
V_4 -> V_100 = ( void V_101 * ) V_102 ;
V_4 -> V_103 = ( void V_101 * ) V_104 ;
V_4 -> V_105 = 0 ;
V_3 -> V_8 . V_106 = & V_6 -> V_8 ;
V_63 = F_67 ( V_20 ) ;
if ( V_63 )
goto V_87;
if ( V_62 ) {
#ifdef F_88
V_4 -> V_33 . V_107 = & V_108 ;
#endif
V_4 -> V_95 = F_55 ;
V_4 -> V_96 = F_56 ;
V_4 -> V_33 . V_109 = F_21 ;
V_4 -> V_33 . V_110 = F_19 ;
V_4 -> V_33 . V_35 = V_111 ;
V_4 -> V_33 . V_112 = F_20 ;
V_4 -> V_33 . V_113 = F_57 ;
V_4 -> V_33 . V_114 = F_58 ;
} else {
V_4 -> V_33 . V_35 = V_115 ;
}
if ( F_76 ( V_3 ) ) {
V_63 = - V_73 ;
goto V_116;
}
#ifdef F_88
V_4 -> V_117 = 63 ;
#endif
F_70 ( V_20 ) ;
F_24 ( & V_6 -> V_8 , L_19 ) ;
return 0 ;
V_116:
F_65 ( V_20 ) ;
V_87:
F_75 ( V_79 ) ;
return V_63 ;
}
