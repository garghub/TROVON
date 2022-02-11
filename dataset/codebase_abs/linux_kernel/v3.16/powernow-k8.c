static inline const struct V_1 * F_1 ( int V_2 )
{
return F_2 ( 0 ) ;
}
static T_1 F_3 ( T_1 V_3 )
{
return 800 + ( V_3 * 100 ) ;
}
static T_1 F_4 ( T_1 V_3 )
{
return 1000 * F_3 ( V_3 ) ;
}
static T_1 F_5 ( T_1 V_3 )
{
if ( V_3 < V_4 )
return 8 + ( 2 * V_3 ) ;
else
return V_3 ;
}
static int F_6 ( void )
{
T_1 V_5 , V_6 ;
F_7 ( V_7 , V_5 , V_6 ) ;
return V_5 & V_8 ? 1 : 0 ;
}
static int F_8 ( struct V_9 * V_10 )
{
T_1 V_5 , V_6 ;
T_1 V_11 = 0 ;
do {
if ( V_11 ++ > 10000 ) {
F_9 ( L_1 ) ;
return 1 ;
}
F_7 ( V_7 , V_5 , V_6 ) ;
} while ( V_5 & V_8 );
V_10 -> V_12 = V_6 & V_13 ;
V_10 -> V_14 = V_5 & V_15 ;
return 0 ;
}
static void F_10 ( struct V_9 * V_10 )
{
F_11 ( ( 1 << V_10 -> V_16 ) * 10 ) ;
return;
}
static void F_12 ( struct V_9 * V_10 )
{
F_11 ( V_10 -> V_17 * V_18 ) ;
return;
}
static void F_13 ( void )
{
T_1 V_5 , V_6 ;
T_2 V_3 , V_19 ;
F_7 ( V_7 , V_5 , V_6 ) ;
V_19 = V_6 & V_13 ;
V_3 = V_5 & V_15 ;
V_5 = V_3 | ( V_19 << V_20 ) ;
V_6 = V_21 ;
F_9 ( L_2 , F_14 () , V_5 , V_6 ) ;
F_15 ( V_22 , V_5 , V_6 ) ;
}
static int F_16 ( struct V_9 * V_10 , T_1 V_3 )
{
T_1 V_5 ;
T_1 V_23 = V_10 -> V_12 ;
T_1 V_11 = 0 ;
if ( ( V_3 & V_24 ) || ( V_10 -> V_12 & V_25 ) ) {
F_17 ( L_3 ) ;
return 1 ;
}
V_5 = V_3 ;
V_5 |= ( V_10 -> V_12 << V_20 ) ;
V_5 |= V_26 ;
F_9 ( L_4 ,
V_3 , V_5 , V_10 -> V_27 * V_28 ) ;
do {
F_15 ( V_22 , V_5 , V_10 -> V_27 * V_28 ) ;
if ( V_11 ++ > 100 ) {
F_17 ( L_5 ) ;
return 1 ;
}
} while ( F_8 ( V_10 ) );
F_10 ( V_10 ) ;
if ( V_23 != V_10 -> V_12 ) {
F_17 ( L_6 ,
V_23 , V_10 -> V_12 ) ;
return 1 ;
}
if ( V_3 != V_10 -> V_14 ) {
F_17 ( L_7 , V_3 ,
V_10 -> V_14 ) ;
return 1 ;
}
return 0 ;
}
static int F_18 ( struct V_9 * V_10 , T_1 V_19 )
{
T_1 V_5 ;
T_1 V_29 = V_10 -> V_14 ;
int V_11 = 0 ;
if ( ( V_10 -> V_14 & V_24 ) || ( V_19 & V_25 ) ) {
F_17 ( L_8 ) ;
return 1 ;
}
V_5 = V_10 -> V_14 ;
V_5 |= ( V_19 << V_20 ) ;
V_5 |= V_26 ;
F_9 ( L_9 ,
V_19 , V_5 , V_30 ) ;
do {
F_15 ( V_22 , V_5 , V_30 ) ;
if ( V_11 ++ > 100 ) {
F_17 ( L_10 ) ;
return 1 ;
}
} while ( F_8 ( V_10 ) );
if ( V_29 != V_10 -> V_14 ) {
F_17 ( L_11 ,
V_29 , V_10 -> V_14 ) ;
return 1 ;
}
if ( V_19 != V_10 -> V_12 ) {
F_17 ( L_12 ,
V_19 , V_10 -> V_12 ) ;
return 1 ;
}
return 0 ;
}
static int F_19 ( struct V_9 * V_10 ,
T_1 V_31 , T_1 V_32 )
{
if ( ( V_10 -> V_12 - V_31 ) > V_32 )
V_31 = V_10 -> V_12 - V_32 ;
if ( F_18 ( V_10 , V_31 ) )
return 1 ;
F_12 ( V_10 ) ;
return 0 ;
}
static int F_20 ( struct V_9 * V_10 ,
T_1 V_33 , T_1 V_31 )
{
if ( F_21 ( V_10 , V_31 , V_33 ) )
return 1 ;
if ( F_22 ( V_10 , V_33 ) )
return 1 ;
if ( F_23 ( V_10 , V_31 ) )
return 1 ;
if ( F_8 ( V_10 ) )
return 1 ;
if ( ( V_33 != V_10 -> V_14 ) || ( V_31 != V_10 -> V_12 ) ) {
F_17 ( L_13 ,
F_14 () ,
V_33 , V_31 , V_10 -> V_14 , V_10 -> V_12 ) ;
return 1 ;
}
F_9 ( L_14 ,
F_14 () , V_10 -> V_14 , V_10 -> V_12 ) ;
return 0 ;
}
static int F_21 ( struct V_9 * V_10 ,
T_1 V_31 , T_1 V_33 )
{
T_1 V_34 = V_10 -> V_35 ;
T_1 V_29 = V_10 -> V_14 ;
T_1 V_36 , V_5 , V_37 = 1 ;
F_9 ( L_15 ,
F_14 () ,
V_10 -> V_14 , V_10 -> V_12 , V_31 , V_10 -> V_35 ) ;
if ( ( V_29 < V_38 ) && ( V_33 < V_38 ) )
V_37 = 2 ;
V_34 *= V_37 ;
F_7 ( V_7 , V_5 , V_36 ) ;
V_36 = 0x1f & ( V_36 >> 16 ) ;
F_9 ( L_16 , V_36 ) ;
if ( V_31 < V_36 )
V_31 = V_36 ;
while ( V_10 -> V_12 > V_31 ) {
F_9 ( L_17 ,
V_10 -> V_12 , V_31 ) ;
if ( F_19 ( V_10 , V_31 , V_10 -> V_39 ) )
return 1 ;
}
while ( ( V_34 > 0 ) &&
( ( V_37 * V_10 -> V_35 + V_10 -> V_12 ) > V_31 ) ) {
if ( V_10 -> V_12 == V_36 ) {
V_34 = 0 ;
} else {
F_9 ( L_18 ,
V_10 -> V_12 - 1 ) ;
if ( F_19 ( V_10 , V_10 -> V_12 - 1 , 1 ) )
return 1 ;
V_34 -- ;
}
}
if ( F_8 ( V_10 ) )
return 1 ;
if ( V_29 != V_10 -> V_14 ) {
F_17 ( L_19 , V_10 -> V_14 ) ;
return 1 ;
}
F_9 ( L_20 ,
V_10 -> V_14 , V_10 -> V_12 ) ;
return 0 ;
}
static int F_22 ( struct V_9 * V_10 , T_1 V_33 )
{
T_1 V_40 , V_41 , V_42 ;
T_1 V_43 , V_23 = V_10 -> V_12 ;
if ( V_10 -> V_14 == V_33 ) {
F_17 ( L_21 , V_10 -> V_14 ) ;
return 0 ;
}
F_9 ( L_22 ,
F_14 () ,
V_10 -> V_14 , V_10 -> V_12 , V_33 ) ;
V_40 = F_5 ( V_33 ) ;
V_41 = F_5 ( V_10 -> V_14 ) ;
V_42 = V_41 > V_40 ? V_41 - V_40
: V_40 - V_41 ;
if ( ( V_33 <= V_38 ) && ( V_10 -> V_14 <= V_38 ) )
V_42 = 0 ;
while ( V_42 > 2 ) {
( V_10 -> V_14 & 1 ) ? ( V_43 = 1 ) : ( V_43 = 2 ) ;
if ( V_33 > V_10 -> V_14 ) {
if ( V_10 -> V_14 > V_38 ) {
if ( F_16 ( V_10 ,
V_10 -> V_14 + V_43 ) )
return 1 ;
} else {
if ( F_16
( V_10 ,
2 + F_5 ( V_10 -> V_14 ) ) )
return 1 ;
}
} else {
if ( F_16 ( V_10 , V_10 -> V_14 - V_43 ) )
return 1 ;
}
V_41 = F_5 ( V_10 -> V_14 ) ;
V_42 = V_41 > V_40 ? V_41 - V_40
: V_40 - V_41 ;
}
if ( F_16 ( V_10 , V_33 ) )
return 1 ;
if ( F_8 ( V_10 ) )
return 1 ;
if ( V_10 -> V_14 != V_33 ) {
F_17 ( L_23 ,
V_10 -> V_14 , V_33 ) ;
return 1 ;
}
if ( V_23 != V_10 -> V_12 ) {
F_17 ( L_24 ,
V_23 , V_10 -> V_12 ) ;
return 1 ;
}
F_9 ( L_25 ,
V_10 -> V_14 , V_10 -> V_12 ) ;
return 0 ;
}
static int F_23 ( struct V_9 * V_10 ,
T_1 V_31 )
{
T_1 V_29 = V_10 -> V_14 ;
T_1 V_44 = V_31 ;
F_9 ( L_26 ,
F_14 () ,
V_10 -> V_14 , V_10 -> V_12 ) ;
if ( V_31 != V_10 -> V_12 ) {
if ( F_18 ( V_10 , V_31 ) )
return 1 ;
if ( V_29 != V_10 -> V_14 ) {
F_17 ( L_27 ,
V_29 , V_10 -> V_14 ) ;
return 1 ;
}
if ( V_10 -> V_12 != V_31 ) {
F_17 ( L_28 ,
V_31 , V_10 -> V_12 ) ;
return 1 ;
}
}
if ( F_8 ( V_10 ) )
return 1 ;
if ( V_44 != V_10 -> V_12 ) {
F_9 ( L_29 , V_10 -> V_12 ) ;
return 1 ;
}
if ( V_29 != V_10 -> V_14 ) {
F_9 ( L_30 ,
V_10 -> V_14 ) ;
return 1 ;
}
F_9 ( L_31 ,
V_10 -> V_14 , V_10 -> V_12 ) ;
return 0 ;
}
static void F_24 ( void * V_45 )
{
T_1 V_46 , V_47 , V_48 , V_49 ;
int * V_50 = V_45 ;
* V_50 = - V_51 ;
V_46 = F_25 ( V_52 ) ;
if ( ( V_46 & V_53 ) == V_54 ) {
if ( ( ( V_46 & V_55 ) != V_55 ) ||
( ( V_46 & V_56 ) > V_57 ) ) {
F_26 ( L_32 , V_46 ) ;
return;
}
V_46 = F_25 ( V_58 ) ;
if ( V_46 < V_59 ) {
F_26 ( L_33 ) ;
return;
}
F_27 ( V_59 , & V_46 , & V_47 , & V_48 , & V_49 ) ;
if ( ( V_49 & V_60 )
!= V_60 ) {
F_26 ( L_34 ) ;
return;
}
* V_50 = 0 ;
}
}
static int F_28 ( struct V_9 * V_10 , struct V_61 * V_62 ,
T_2 V_36 )
{
unsigned int V_63 ;
T_2 V_64 = 0xff ;
for ( V_63 = 0 ; V_63 < V_10 -> V_65 ; V_63 ++ ) {
if ( V_62 [ V_63 ] . V_19 > V_66 ) {
F_17 ( V_67 L_35 , V_63 ,
V_62 [ V_63 ] . V_19 ) ;
return - V_68 ;
}
if ( V_62 [ V_63 ] . V_19 < V_10 -> V_35 ) {
F_17 ( V_67 L_36 , V_63 ) ;
return - V_51 ;
}
if ( V_62 [ V_63 ] . V_19 < V_36 + V_10 -> V_35 ) {
F_17 ( V_67 L_37 , V_63 ) ;
return - V_51 ;
}
if ( V_62 [ V_63 ] . V_3 > V_69 ) {
F_17 ( V_67 L_38 , V_63 ) ;
return - V_51 ;
}
if ( V_63 && ( V_62 [ V_63 ] . V_3 < V_4 ) ) {
F_17 ( V_67 L_39 , V_63 ,
V_62 [ V_63 ] . V_3 ) ;
return - V_68 ;
}
if ( V_62 [ V_63 ] . V_3 < V_64 )
V_64 = V_62 [ V_63 ] . V_3 ;
}
if ( V_64 & 1 ) {
F_17 ( V_67 L_40 ) ;
return - V_68 ;
}
if ( V_64 > V_38 )
F_26 ( V_67 L_41 ) ;
return 0 ;
}
static void F_29 ( struct V_70 * V_71 ,
unsigned int V_72 )
{
V_71 [ V_72 ] . V_73 = V_74 ;
}
static void F_30 ( struct V_9 * V_10 )
{
int V_63 ;
for ( V_63 = 0 ; V_63 < V_10 -> V_65 ; V_63 ++ ) {
if ( V_10 -> V_71 [ V_63 ] . V_73 !=
V_74 ) {
F_26 ( L_42 ,
V_10 -> V_71 [ V_63 ] . V_75 & 0xff ,
V_10 -> V_71 [ V_63 ] . V_73 / 1000 ,
V_10 -> V_71 [ V_63 ] . V_75 >> 8 ) ;
}
}
if ( V_10 -> V_76 )
F_26 ( L_43 , V_10 -> V_76 ) ;
}
static int F_31 ( struct V_9 * V_10 ,
struct V_61 * V_62 , T_2 V_36 )
{
struct V_70 * V_71 ;
unsigned int V_63 ;
if ( V_10 -> V_76 ) {
F_32 ( L_44 ,
V_10 -> V_76 ) ;
V_10 -> V_65 = V_10 -> V_76 ;
}
for ( V_63 = 1 ; V_63 < V_10 -> V_65 ; V_63 ++ ) {
if ( V_62 [ V_63 - 1 ] . V_3 >= V_62 [ V_63 ] . V_3 ) {
F_17 ( L_45 ) ;
return - V_68 ;
}
}
if ( V_10 -> V_65 < 2 ) {
F_17 ( L_46 ) ;
return - V_51 ;
}
if ( F_28 ( V_10 , V_62 , V_36 ) )
return - V_68 ;
V_71 = F_33 ( ( sizeof( * V_71 )
* ( V_10 -> V_65 + 1 ) ) , V_77 ) ;
if ( ! V_71 ) {
F_17 ( L_47 ) ;
return - V_78 ;
}
for ( V_63 = 0 ; V_63 < V_10 -> V_65 ; V_63 ++ ) {
int V_79 ;
V_71 [ V_63 ] . V_75 = V_62 [ V_63 ] . V_3 ;
V_71 [ V_63 ] . V_75 |= ( V_62 [ V_63 ] . V_19 << 8 ) ;
V_79 = F_4 ( V_62 [ V_63 ] . V_3 ) ;
V_71 [ V_63 ] . V_73 = V_79 ;
}
V_71 [ V_10 -> V_65 ] . V_73 = V_80 ;
V_71 [ V_10 -> V_65 ] . V_75 = 0 ;
if ( F_8 ( V_10 ) ) {
F_34 ( V_71 ) ;
return - V_81 ;
}
F_9 ( L_48 , V_10 -> V_14 , V_10 -> V_12 ) ;
V_10 -> V_71 = V_71 ;
if ( F_35 ( F_1 ( V_10 -> V_2 ) ) == V_10 -> V_2 )
F_30 ( V_10 ) ;
for ( V_63 = 0 ; V_63 < V_10 -> V_65 ; V_63 ++ )
if ( ( V_62 [ V_63 ] . V_3 == V_10 -> V_14 ) &&
( V_62 [ V_63 ] . V_19 == V_10 -> V_12 ) )
return 0 ;
F_9 ( L_49 ) ;
return 0 ;
}
static int F_36 ( struct V_9 * V_10 )
{
struct V_82 * V_83 ;
unsigned int V_11 ;
T_1 V_84 ;
T_2 V_36 ;
T_1 V_85 = 0 ;
T_1 V_86 ;
for ( V_11 = 0xc0000 ; V_11 < 0xffff0 ; V_11 += 0x10 ) {
V_83 = F_37 ( V_11 ) ;
if ( memcmp ( V_83 , V_87 , V_88 ) != 0 )
continue;
F_9 ( L_50 , V_83 ) ;
F_9 ( L_51 , V_83 -> V_89 ) ;
if ( V_83 -> V_89 != V_90 ) {
F_17 ( V_67 L_52 ) ;
return - V_51 ;
}
F_9 ( L_53 , V_83 -> V_91 ) ;
if ( V_83 -> V_91 ) {
F_17 ( V_67 L_54 ) ;
return - V_51 ;
}
V_10 -> V_17 = V_83 -> V_17 ;
F_9 ( L_55 ,
V_10 -> V_17 ) ;
F_9 ( L_56 , V_83 -> V_92 ) ;
V_10 -> V_35 = V_83 -> V_92 & 3 ;
V_10 -> V_16 = ( ( V_83 -> V_92 ) >> 2 ) & 3 ;
V_84 = ( ( V_83 -> V_92 ) >> 4 ) & 3 ;
V_10 -> V_39 = 1 << V_84 ;
V_10 -> V_76 = ( ( V_83 -> V_92 ) >> 6 ) & 3 ;
F_9 ( L_57 , V_10 -> V_35 ) ;
F_9 ( L_58 , V_10 -> V_16 ) ;
F_9 ( L_59 , V_84 , V_10 -> V_39 ) ;
F_9 ( L_60 , V_83 -> V_93 ) ;
V_85 = V_83 -> V_93 ;
if ( ( V_83 -> F_27 == 0x00000fc0 ) ||
( V_83 -> F_27 == 0x00000fe0 ) ) {
V_86 = F_25 ( V_52 ) ;
if ( ( V_86 == 0x00000fc0 ) ||
( V_86 == 0x00000fe0 ) )
V_85 = 1 ;
}
if ( V_85 != 1 ) {
F_17 ( V_67 L_61 ) ;
return - V_51 ;
}
V_10 -> V_27 = V_83 -> V_94 ;
F_9 ( L_62 , V_83 -> V_94 ) ;
F_9 ( L_63 , V_83 -> V_95 ) ;
F_9 ( L_64 , V_83 -> V_36 ) ;
V_36 = V_83 -> V_36 ;
V_10 -> V_65 = V_83 -> V_65 ;
F_9 ( L_65 , V_10 -> V_65 ) ;
return F_31 ( V_10 ,
(struct V_61 * ) ( V_83 + 1 ) , V_36 ) ;
}
F_17 ( V_67 L_66 ) ;
F_17 ( L_67 ) ;
return - V_51 ;
}
static void F_38 ( struct V_9 * V_10 ,
unsigned int V_96 )
{
T_3 V_97 ;
if ( ! V_10 -> V_98 . V_99 )
return;
V_97 = V_10 -> V_98 . V_100 [ V_96 ] . V_97 ;
V_10 -> V_16 = ( V_97 >> V_101 ) & V_102 ;
V_10 -> V_35 = ( V_97 >> V_103 ) & V_104 ;
V_10 -> V_105 = ( V_97 >> V_106 ) & V_107 ;
V_10 -> V_27 = ( V_97 >> V_108 ) & V_109 ;
V_10 -> V_39 = 1 << ( ( V_97 >> V_110 ) & V_111 ) ;
V_10 -> V_17 = ( V_97 >> V_112 ) & V_113 ;
}
static int F_39 ( struct V_9 * V_10 )
{
struct V_70 * V_71 ;
int V_114 = - V_51 ;
T_3 V_97 , V_115 ;
if ( F_40 ( & V_10 -> V_98 , V_10 -> V_2 ) ) {
F_9 ( L_68 ) ;
return - V_81 ;
}
if ( V_10 -> V_98 . V_99 <= 1 ) {
F_9 ( L_69 ) ;
goto V_116;
}
V_97 = V_10 -> V_98 . V_117 . V_118 ;
V_115 = V_10 -> V_98 . V_119 . V_118 ;
if ( ( V_97 != V_120 ) ||
( V_115 != V_120 ) ) {
F_9 ( L_70 ,
V_97 , V_115 ) ;
goto V_116;
}
V_71 = F_33 ( ( sizeof( * V_71 )
* ( V_10 -> V_98 . V_99 + 1 ) ) , V_77 ) ;
if ( ! V_71 ) {
F_9 ( L_47 ) ;
goto V_116;
}
V_10 -> V_65 = V_10 -> V_98 . V_99 ;
F_38 ( V_10 , 0 ) ;
V_114 = F_41 ( V_10 , V_71 ) ;
if ( V_114 )
goto V_121;
V_71 [ V_10 -> V_98 . V_99 ] . V_73 =
V_80 ;
V_10 -> V_71 = V_71 ;
if ( F_35 ( F_1 ( V_10 -> V_2 ) ) == V_10 -> V_2 )
F_30 ( V_10 ) ;
F_42 ( V_122 ) ;
if ( ! F_43 ( & V_10 -> V_98 . V_123 , V_77 ) ) {
F_17 ( L_71 ) ;
V_114 = - V_78 ;
goto V_121;
}
return 0 ;
V_121:
F_34 ( V_71 ) ;
V_116:
F_44 ( & V_10 -> V_98 , V_10 -> V_2 ) ;
V_10 -> V_98 . V_99 = 0 ;
return V_114 ;
}
static int F_41 ( struct V_9 * V_10 ,
struct V_70 * V_71 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < V_10 -> V_98 . V_99 ; V_11 ++ ) {
T_1 V_3 ;
T_1 V_19 ;
T_1 V_79 , V_96 ;
T_3 V_115 , V_97 ;
if ( V_10 -> V_105 ) {
V_115 = V_10 -> V_98 . V_100 [ V_11 ] . V_115 ;
V_3 = V_115 & V_124 ;
V_19 = ( V_115 >> V_125 ) & V_126 ;
} else {
V_97 = V_10 -> V_98 . V_100 [ V_11 ] . V_97 ;
V_3 = V_97 & V_127 ;
V_19 = ( V_97 >> V_125 ) & V_128 ;
}
F_9 ( L_72 , V_11 , V_3 , V_19 ) ;
V_96 = V_3 | ( V_19 << 8 ) ;
V_71 [ V_11 ] . V_75 = V_96 ;
V_79 = F_4 ( V_3 ) ;
V_71 [ V_11 ] . V_73 = V_79 ;
if ( ( V_79 > ( V_129 * 1000 ) ) || ( V_79 < ( V_130 * 1000 ) ) ) {
F_9 ( L_73 , V_79 ) ;
F_29 ( V_71 , V_11 ) ;
continue;
}
if ( V_19 == V_131 ) {
F_9 ( L_74 , V_19 ) ;
F_29 ( V_71 , V_11 ) ;
continue;
}
if ( V_79 != ( V_10 -> V_98 . V_100 [ V_11 ] . V_132 * 1000 ) ) {
F_26 ( L_75 ,
V_79 , ( unsigned int )
( V_10 -> V_98 . V_100 [ V_11 ] . V_132
* 1000 ) ) ;
F_29 ( V_71 , V_11 ) ;
continue;
}
}
return 0 ;
}
static void F_45 ( struct V_9 * V_10 )
{
if ( V_10 -> V_98 . V_99 )
F_44 ( & V_10 -> V_98 ,
V_10 -> V_2 ) ;
F_46 ( V_10 -> V_98 . V_123 ) ;
}
static int F_47 ( struct V_9 * V_10 )
{
int V_133 = 0 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < V_10 -> V_98 . V_99 ; V_11 ++ ) {
int V_134 = V_10 -> V_98 . V_100 [ V_11 ] . V_135
+ V_10 -> V_98 . V_100 [ V_11 ] . V_136 ;
if ( V_134 > V_133 )
V_133 = V_134 ;
}
if ( V_133 == 0 ) {
F_17 ( V_137 L_76 ) ;
V_133 = 1 ;
}
return 1000 * V_133 ;
}
static int F_48 ( struct V_9 * V_10 ,
unsigned int V_96 )
{
struct V_138 * V_139 ;
T_1 V_3 = 0 ;
T_1 V_19 = 0 ;
int V_140 ;
struct V_141 V_142 ;
F_9 ( L_77 , F_14 () , V_96 ) ;
V_3 = V_10 -> V_71 [ V_96 ] . V_75 & 0xFF ;
V_19 = ( V_10 -> V_71 [ V_96 ] . V_75 & 0xFF00 ) >> 8 ;
F_9 ( L_78 , V_3 , V_19 ) ;
if ( F_8 ( V_10 ) )
return 1 ;
if ( ( V_10 -> V_12 == V_19 ) && ( V_10 -> V_14 == V_3 ) ) {
F_9 ( L_79 ,
V_3 , V_19 ) ;
return 0 ;
}
F_9 ( L_80 ,
F_14 () , V_3 , V_19 ) ;
V_142 . V_143 = F_4 ( V_10 -> V_14 ) ;
V_142 . V_144 = F_4 ( V_3 ) ;
V_139 = F_49 ( F_14 () ) ;
F_50 ( V_139 ) ;
F_51 ( V_139 , & V_142 ) ;
V_140 = F_20 ( V_10 , V_3 , V_19 ) ;
F_52 ( V_139 , & V_142 , V_140 ) ;
return V_140 ;
}
static long F_53 ( void * V_145 )
{
struct V_146 * V_147 = V_145 ;
struct V_138 * V_148 = V_147 -> V_148 ;
unsigned V_149 = V_147 -> V_149 ;
struct V_9 * V_10 = F_54 ( V_150 , V_148 -> V_2 ) ;
T_1 V_151 ;
T_1 V_152 ;
int V_153 ;
if ( ! V_10 )
return - V_68 ;
V_151 = V_10 -> V_14 ;
V_152 = V_10 -> V_12 ;
if ( F_6 () ) {
F_17 ( L_81 ) ;
return - V_81 ;
}
F_9 ( L_82 ,
V_148 -> V_2 , V_10 -> V_71 [ V_149 ] . V_73 , V_148 -> V_154 ,
V_148 -> V_155 ) ;
if ( F_8 ( V_10 ) )
return - V_81 ;
F_9 ( L_83 ,
V_10 -> V_14 , V_10 -> V_12 ) ;
if ( ( V_152 != V_10 -> V_12 ) ||
( V_151 != V_10 -> V_14 ) ) {
F_26 ( L_84 ,
V_151 , V_10 -> V_14 ,
V_152 , V_10 -> V_12 ) ;
}
F_55 ( & V_156 ) ;
F_38 ( V_10 , V_149 ) ;
V_153 = F_48 ( V_10 , V_149 ) ;
if ( V_153 ) {
F_17 ( L_85 ) ;
F_56 ( & V_156 ) ;
return 1 ;
}
F_56 ( & V_156 ) ;
V_148 -> V_157 = F_4 ( V_10 -> V_14 ) ;
return 0 ;
}
static int F_57 ( struct V_138 * V_148 , unsigned V_96 )
{
struct V_146 V_147 = { . V_148 = V_148 , . V_149 = V_96 } ;
return F_58 ( V_148 -> V_2 , F_53 , & V_147 ) ;
}
static void F_59 ( void * V_158 )
{
struct V_159 * V_159 = V_158 ;
if ( F_6 () ) {
F_17 ( L_86 ) ;
V_159 -> V_50 = - V_51 ;
return;
}
if ( F_8 ( V_159 -> V_10 ) ) {
V_159 -> V_50 = - V_51 ;
return;
}
F_13 () ;
V_159 -> V_50 = 0 ;
}
static int F_60 ( struct V_138 * V_148 )
{
struct V_9 * V_10 ;
struct V_159 V_159 ;
int V_50 , V_2 ;
F_61 ( V_148 -> V_2 , F_24 , & V_50 , 1 ) ;
if ( V_50 )
return - V_51 ;
V_10 = F_33 ( sizeof( * V_10 ) , V_77 ) ;
if ( ! V_10 ) {
F_17 ( L_87 ) ;
return - V_78 ;
}
V_10 -> V_2 = V_148 -> V_2 ;
if ( F_39 ( V_10 ) ) {
if ( F_62 () != 1 ) {
F_63 ( V_160 ) ;
goto V_116;
}
if ( V_148 -> V_2 != 0 ) {
F_17 ( V_67 L_88 ) ;
goto V_116;
}
V_50 = F_36 ( V_10 ) ;
if ( V_50 )
goto V_116;
V_148 -> V_161 . V_135 = (
( ( V_10 -> V_35 + 8 ) * V_10 -> V_17 * V_18 ) +
( ( 1 << V_10 -> V_16 ) * 30 ) ) * 1000 ;
} else
V_148 -> V_161 . V_135 = F_47 ( V_10 ) ;
V_159 . V_10 = V_10 ;
F_61 ( V_10 -> V_2 , F_59 ,
& V_159 , 1 ) ;
V_50 = V_159 . V_50 ;
if ( V_50 != 0 )
goto V_162;
F_64 ( V_148 -> V_163 , F_1 ( V_148 -> V_2 ) ) ;
V_10 -> V_164 = V_148 -> V_163 ;
if ( F_65 ( V_148 , V_10 -> V_71 ) ) {
F_17 ( V_67 L_89 ) ;
F_45 ( V_10 ) ;
F_34 ( V_10 -> V_71 ) ;
F_34 ( V_10 ) ;
return - V_68 ;
}
F_9 ( L_90 ,
V_10 -> V_14 , V_10 -> V_12 ) ;
F_66 (cpu, pol->cpus)
F_54 ( V_150 , V_2 ) = V_10 ;
return 0 ;
V_162:
F_45 ( V_10 ) ;
V_116:
F_34 ( V_10 ) ;
return - V_51 ;
}
static int F_67 ( struct V_138 * V_148 )
{
struct V_9 * V_10 = F_54 ( V_150 , V_148 -> V_2 ) ;
int V_2 ;
if ( ! V_10 )
return - V_68 ;
F_45 ( V_10 ) ;
F_34 ( V_10 -> V_71 ) ;
F_34 ( V_10 ) ;
F_66 (cpu, pol->cpus)
F_54 ( V_150 , V_2 ) = NULL ;
return 0 ;
}
static void F_68 ( void * V_165 )
{
int * V_166 = V_165 ;
struct V_9 * V_10 = F_69 ( V_150 ) ;
* V_166 = F_8 ( V_10 ) ;
}
static unsigned int F_70 ( unsigned int V_2 )
{
struct V_9 * V_10 = F_54 ( V_150 , V_2 ) ;
unsigned int V_167 = 0 ;
int V_166 ;
if ( ! V_10 )
return 0 ;
F_61 ( V_2 , F_68 , & V_166 , true ) ;
if ( V_166 )
goto V_168;
V_167 = F_4 ( V_10 -> V_14 ) ;
V_168:
return V_167 ;
}
static void F_71 ( void )
{
const char * V_169 , * V_170 = L_91 ;
V_169 = F_72 () ;
if ( ! V_169 )
goto V_171;
if ( strncmp ( V_169 , V_170 , F_73 ( V_172 , strlen ( V_169 ) , strlen ( V_170 ) ) ) )
F_32 ( L_92 , V_169 ) ;
return;
V_171:
F_32 ( L_93 ) ;
F_74 ( V_170 ) ;
}
static int F_75 ( void )
{
unsigned int V_11 , V_173 = 0 ;
int V_153 ;
if ( F_76 ( V_174 ) ) {
F_71 () ;
return - V_51 ;
}
if ( ! F_77 ( V_175 ) )
return - V_51 ;
F_78 () ;
F_79 (i) {
F_61 ( V_11 , F_24 , & V_153 , 1 ) ;
if ( ! V_153 )
V_173 ++ ;
}
if ( V_173 != F_62 () ) {
F_80 () ;
return - V_51 ;
}
F_80 () ;
V_153 = F_81 ( & V_176 ) ;
if ( V_153 )
return V_153 ;
F_26 ( L_94 V_177 L_95 ,
F_82 () , V_178 . V_179 , V_173 ) ;
return V_153 ;
}
static void T_4 F_83 ( void )
{
F_9 ( L_96 ) ;
F_84 ( & V_176 ) ;
}
