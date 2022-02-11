static T_1 F_1 ( T_1 V_1 )
{
return 800 + ( V_1 * 100 ) ;
}
static T_1 F_2 ( T_1 V_1 )
{
return 1000 * F_1 ( V_1 ) ;
}
static T_1 F_3 ( T_1 V_1 )
{
if ( V_1 < V_2 )
return 8 + ( 2 * V_1 ) ;
else
return V_1 ;
}
static int F_4 ( void )
{
T_1 V_3 , V_4 ;
F_5 ( V_5 , V_3 , V_4 ) ;
return V_3 & V_6 ? 1 : 0 ;
}
static int F_6 ( struct V_7 * V_8 )
{
T_1 V_3 , V_4 ;
T_1 V_9 = 0 ;
do {
if ( V_9 ++ > 10000 ) {
F_7 ( L_1 ) ;
return 1 ;
}
F_5 ( V_5 , V_3 , V_4 ) ;
} while ( V_3 & V_6 );
V_8 -> V_10 = V_4 & V_11 ;
V_8 -> V_12 = V_3 & V_13 ;
return 0 ;
}
static void F_8 ( struct V_7 * V_8 )
{
F_9 ( ( 1 << V_8 -> V_14 ) * 10 ) ;
return;
}
static void F_10 ( struct V_7 * V_8 )
{
F_9 ( V_8 -> V_15 * V_16 ) ;
return;
}
static void F_11 ( void )
{
T_1 V_3 , V_4 ;
T_2 V_1 , V_17 ;
F_5 ( V_5 , V_3 , V_4 ) ;
V_17 = V_4 & V_11 ;
V_1 = V_3 & V_13 ;
V_3 = V_1 | ( V_17 << V_18 ) ;
V_4 = V_19 ;
F_7 ( L_2 , F_12 () , V_3 , V_4 ) ;
F_13 ( V_20 , V_3 , V_4 ) ;
}
static int F_14 ( struct V_7 * V_8 , T_1 V_1 )
{
T_1 V_3 ;
T_1 V_21 = V_8 -> V_10 ;
T_1 V_9 = 0 ;
if ( ( V_1 & V_22 ) || ( V_8 -> V_10 & V_23 ) ) {
F_15 ( L_3 ) ;
return 1 ;
}
V_3 = V_1 ;
V_3 |= ( V_8 -> V_10 << V_18 ) ;
V_3 |= V_24 ;
F_7 ( L_4 ,
V_1 , V_3 , V_8 -> V_25 * V_26 ) ;
do {
F_13 ( V_20 , V_3 , V_8 -> V_25 * V_26 ) ;
if ( V_9 ++ > 100 ) {
F_15 ( L_5 ) ;
return 1 ;
}
} while ( F_6 ( V_8 ) );
F_8 ( V_8 ) ;
if ( V_21 != V_8 -> V_10 ) {
F_15 ( L_6 ,
V_21 , V_8 -> V_10 ) ;
return 1 ;
}
if ( V_1 != V_8 -> V_12 ) {
F_15 ( L_7 , V_1 ,
V_8 -> V_12 ) ;
return 1 ;
}
return 0 ;
}
static int F_16 ( struct V_7 * V_8 , T_1 V_17 )
{
T_1 V_3 ;
T_1 V_27 = V_8 -> V_12 ;
int V_9 = 0 ;
if ( ( V_8 -> V_12 & V_22 ) || ( V_17 & V_23 ) ) {
F_15 ( L_8 ) ;
return 1 ;
}
V_3 = V_8 -> V_12 ;
V_3 |= ( V_17 << V_18 ) ;
V_3 |= V_24 ;
F_7 ( L_9 ,
V_17 , V_3 , V_28 ) ;
do {
F_13 ( V_20 , V_3 , V_28 ) ;
if ( V_9 ++ > 100 ) {
F_15 ( L_10 ) ;
return 1 ;
}
} while ( F_6 ( V_8 ) );
if ( V_27 != V_8 -> V_12 ) {
F_15 ( L_11 ,
V_27 , V_8 -> V_12 ) ;
return 1 ;
}
if ( V_17 != V_8 -> V_10 ) {
F_15 ( L_12 ,
V_17 , V_8 -> V_10 ) ;
return 1 ;
}
return 0 ;
}
static int F_17 ( struct V_7 * V_8 ,
T_1 V_29 , T_1 V_30 )
{
if ( ( V_8 -> V_10 - V_29 ) > V_30 )
V_29 = V_8 -> V_10 - V_30 ;
if ( F_16 ( V_8 , V_29 ) )
return 1 ;
F_10 ( V_8 ) ;
return 0 ;
}
static int F_18 ( struct V_7 * V_8 ,
T_1 V_31 , T_1 V_29 )
{
if ( F_19 ( V_8 , V_29 , V_31 ) )
return 1 ;
if ( F_20 ( V_8 , V_31 ) )
return 1 ;
if ( F_21 ( V_8 , V_29 ) )
return 1 ;
if ( F_6 ( V_8 ) )
return 1 ;
if ( ( V_31 != V_8 -> V_12 ) || ( V_29 != V_8 -> V_10 ) ) {
F_15 ( L_13 ,
F_12 () ,
V_31 , V_29 , V_8 -> V_12 , V_8 -> V_10 ) ;
return 1 ;
}
F_7 ( L_14 ,
F_12 () , V_8 -> V_12 , V_8 -> V_10 ) ;
return 0 ;
}
static int F_19 ( struct V_7 * V_8 ,
T_1 V_29 , T_1 V_31 )
{
T_1 V_32 = V_8 -> V_33 ;
T_1 V_27 = V_8 -> V_12 ;
T_1 V_34 , V_3 , V_35 = 1 ;
F_7 ( L_15 ,
F_12 () ,
V_8 -> V_12 , V_8 -> V_10 , V_29 , V_8 -> V_33 ) ;
if ( ( V_27 < V_36 ) && ( V_31 < V_36 ) )
V_35 = 2 ;
V_32 *= V_35 ;
F_5 ( V_5 , V_3 , V_34 ) ;
V_34 = 0x1f & ( V_34 >> 16 ) ;
F_7 ( L_16 , V_34 ) ;
if ( V_29 < V_34 )
V_29 = V_34 ;
while ( V_8 -> V_10 > V_29 ) {
F_7 ( L_17 ,
V_8 -> V_10 , V_29 ) ;
if ( F_17 ( V_8 , V_29 , V_8 -> V_37 ) )
return 1 ;
}
while ( ( V_32 > 0 ) &&
( ( V_35 * V_8 -> V_33 + V_8 -> V_10 ) > V_29 ) ) {
if ( V_8 -> V_10 == V_34 ) {
V_32 = 0 ;
} else {
F_7 ( L_18 ,
V_8 -> V_10 - 1 ) ;
if ( F_17 ( V_8 , V_8 -> V_10 - 1 , 1 ) )
return 1 ;
V_32 -- ;
}
}
if ( F_6 ( V_8 ) )
return 1 ;
if ( V_27 != V_8 -> V_12 ) {
F_15 ( L_19 , V_8 -> V_12 ) ;
return 1 ;
}
F_7 ( L_20 ,
V_8 -> V_12 , V_8 -> V_10 ) ;
return 0 ;
}
static int F_20 ( struct V_7 * V_8 , T_1 V_31 )
{
T_1 V_38 , V_39 , V_40 ;
T_1 V_41 , V_21 = V_8 -> V_10 ;
if ( V_8 -> V_12 == V_31 ) {
F_15 ( L_21 , V_8 -> V_12 ) ;
return 0 ;
}
F_7 ( L_22 ,
F_12 () ,
V_8 -> V_12 , V_8 -> V_10 , V_31 ) ;
V_38 = F_3 ( V_31 ) ;
V_39 = F_3 ( V_8 -> V_12 ) ;
V_40 = V_39 > V_38 ? V_39 - V_38
: V_38 - V_39 ;
if ( ( V_31 <= V_36 ) && ( V_8 -> V_12 <= V_36 ) )
V_40 = 0 ;
while ( V_40 > 2 ) {
( V_8 -> V_12 & 1 ) ? ( V_41 = 1 ) : ( V_41 = 2 ) ;
if ( V_31 > V_8 -> V_12 ) {
if ( V_8 -> V_12 > V_36 ) {
if ( F_14 ( V_8 ,
V_8 -> V_12 + V_41 ) )
return 1 ;
} else {
if ( F_14
( V_8 ,
2 + F_3 ( V_8 -> V_12 ) ) )
return 1 ;
}
} else {
if ( F_14 ( V_8 , V_8 -> V_12 - V_41 ) )
return 1 ;
}
V_39 = F_3 ( V_8 -> V_12 ) ;
V_40 = V_39 > V_38 ? V_39 - V_38
: V_38 - V_39 ;
}
if ( F_14 ( V_8 , V_31 ) )
return 1 ;
if ( F_6 ( V_8 ) )
return 1 ;
if ( V_8 -> V_12 != V_31 ) {
F_15 ( L_23 ,
V_8 -> V_12 , V_31 ) ;
return 1 ;
}
if ( V_21 != V_8 -> V_10 ) {
F_15 ( L_24 ,
V_21 , V_8 -> V_10 ) ;
return 1 ;
}
F_7 ( L_25 ,
V_8 -> V_12 , V_8 -> V_10 ) ;
return 0 ;
}
static int F_21 ( struct V_7 * V_8 ,
T_1 V_29 )
{
T_1 V_27 = V_8 -> V_12 ;
T_1 V_42 = V_29 ;
F_7 ( L_26 ,
F_12 () ,
V_8 -> V_12 , V_8 -> V_10 ) ;
if ( V_29 != V_8 -> V_10 ) {
if ( F_16 ( V_8 , V_29 ) )
return 1 ;
if ( V_27 != V_8 -> V_12 ) {
F_15 ( L_27 ,
V_27 , V_8 -> V_12 ) ;
return 1 ;
}
if ( V_8 -> V_10 != V_29 ) {
F_15 ( L_28 ,
V_29 , V_8 -> V_10 ) ;
return 1 ;
}
}
if ( F_6 ( V_8 ) )
return 1 ;
if ( V_42 != V_8 -> V_10 ) {
F_7 ( L_29 , V_8 -> V_10 ) ;
return 1 ;
}
if ( V_27 != V_8 -> V_12 ) {
F_7 ( L_30 ,
V_8 -> V_12 ) ;
return 1 ;
}
F_7 ( L_31 ,
V_8 -> V_12 , V_8 -> V_10 ) ;
return 0 ;
}
static void F_22 ( void * V_43 )
{
T_1 V_44 , V_45 , V_46 , V_47 ;
int * V_48 = V_43 ;
* V_48 = - V_49 ;
V_44 = F_23 ( V_50 ) ;
if ( ( V_44 & V_51 ) == V_52 ) {
if ( ( ( V_44 & V_53 ) != V_53 ) ||
( ( V_44 & V_54 ) > V_55 ) ) {
F_24 ( L_32 , V_44 ) ;
return;
}
V_44 = F_23 ( V_56 ) ;
if ( V_44 < V_57 ) {
F_24 ( L_33 ) ;
return;
}
F_25 ( V_57 , & V_44 , & V_45 , & V_46 , & V_47 ) ;
if ( ( V_47 & V_58 )
!= V_58 ) {
F_24 ( L_34 ) ;
return;
}
* V_48 = 0 ;
}
}
static int F_26 ( struct V_7 * V_8 , struct V_59 * V_60 ,
T_2 V_34 )
{
unsigned int V_61 ;
T_2 V_62 = 0xff ;
for ( V_61 = 0 ; V_61 < V_8 -> V_63 ; V_61 ++ ) {
if ( V_60 [ V_61 ] . V_17 > V_64 ) {
F_15 ( V_65 L_35 , V_61 ,
V_60 [ V_61 ] . V_17 ) ;
return - V_66 ;
}
if ( V_60 [ V_61 ] . V_17 < V_8 -> V_33 ) {
F_15 ( V_65 L_36 , V_61 ) ;
return - V_49 ;
}
if ( V_60 [ V_61 ] . V_17 < V_34 + V_8 -> V_33 ) {
F_15 ( V_65 L_37 , V_61 ) ;
return - V_49 ;
}
if ( V_60 [ V_61 ] . V_1 > V_67 ) {
F_15 ( V_65 L_38 , V_61 ) ;
return - V_49 ;
}
if ( V_61 && ( V_60 [ V_61 ] . V_1 < V_2 ) ) {
F_15 ( V_65 L_39 , V_61 ,
V_60 [ V_61 ] . V_1 ) ;
return - V_66 ;
}
if ( V_60 [ V_61 ] . V_1 < V_62 )
V_62 = V_60 [ V_61 ] . V_1 ;
}
if ( V_62 & 1 ) {
F_15 ( V_65 L_40 ) ;
return - V_66 ;
}
if ( V_62 > V_36 )
F_24 ( V_65 L_41 ) ;
return 0 ;
}
static void F_27 ( struct V_68 * V_69 ,
unsigned int V_70 )
{
V_69 [ V_70 ] . V_71 = V_72 ;
}
static void F_28 ( struct V_7 * V_8 )
{
int V_61 ;
for ( V_61 = 0 ; V_61 < V_8 -> V_63 ; V_61 ++ ) {
if ( V_8 -> V_69 [ V_61 ] . V_71 !=
V_72 ) {
F_24 ( L_42 ,
V_8 -> V_69 [ V_61 ] . V_73 & 0xff ,
V_8 -> V_69 [ V_61 ] . V_71 / 1000 ,
V_8 -> V_69 [ V_61 ] . V_73 >> 8 ) ;
}
}
if ( V_8 -> V_74 )
F_24 ( L_43 , V_8 -> V_74 ) ;
}
static int F_29 ( struct V_7 * V_8 ,
struct V_59 * V_60 , T_2 V_34 )
{
struct V_68 * V_69 ;
unsigned int V_61 ;
if ( V_8 -> V_74 ) {
F_30 ( L_44 ,
V_8 -> V_74 ) ;
V_8 -> V_63 = V_8 -> V_74 ;
}
for ( V_61 = 1 ; V_61 < V_8 -> V_63 ; V_61 ++ ) {
if ( V_60 [ V_61 - 1 ] . V_1 >= V_60 [ V_61 ] . V_1 ) {
F_15 ( L_45 ) ;
return - V_66 ;
}
}
if ( V_8 -> V_63 < 2 ) {
F_15 ( L_46 ) ;
return - V_49 ;
}
if ( F_26 ( V_8 , V_60 , V_34 ) )
return - V_66 ;
V_69 = F_31 ( ( sizeof( * V_69 )
* ( V_8 -> V_63 + 1 ) ) , V_75 ) ;
if ( ! V_69 ) {
F_15 ( L_47 ) ;
return - V_76 ;
}
for ( V_61 = 0 ; V_61 < V_8 -> V_63 ; V_61 ++ ) {
int V_77 ;
V_69 [ V_61 ] . V_73 = V_60 [ V_61 ] . V_1 ;
V_69 [ V_61 ] . V_73 |= ( V_60 [ V_61 ] . V_17 << 8 ) ;
V_77 = F_2 ( V_60 [ V_61 ] . V_1 ) ;
V_69 [ V_61 ] . V_71 = V_77 ;
}
V_69 [ V_8 -> V_63 ] . V_71 = V_78 ;
V_69 [ V_8 -> V_63 ] . V_73 = 0 ;
if ( F_6 ( V_8 ) ) {
F_32 ( V_69 ) ;
return - V_79 ;
}
F_7 ( L_48 , V_8 -> V_12 , V_8 -> V_10 ) ;
V_8 -> V_69 = V_69 ;
if ( F_33 ( F_34 ( V_8 -> V_80 ) ) == V_8 -> V_80 )
F_28 ( V_8 ) ;
for ( V_61 = 0 ; V_61 < V_8 -> V_63 ; V_61 ++ )
if ( ( V_60 [ V_61 ] . V_1 == V_8 -> V_12 ) &&
( V_60 [ V_61 ] . V_17 == V_8 -> V_10 ) )
return 0 ;
F_7 ( L_49 ) ;
return 0 ;
}
static int F_35 ( struct V_7 * V_8 )
{
struct V_81 * V_82 ;
unsigned int V_9 ;
T_1 V_83 ;
T_2 V_34 ;
T_1 V_84 = 0 ;
T_1 V_85 ;
for ( V_9 = 0xc0000 ; V_9 < 0xffff0 ; V_9 += 0x10 ) {
V_82 = F_36 ( V_9 ) ;
if ( memcmp ( V_82 , V_86 , V_87 ) != 0 )
continue;
F_7 ( L_50 , V_82 ) ;
F_7 ( L_51 , V_82 -> V_88 ) ;
if ( V_82 -> V_88 != V_89 ) {
F_15 ( V_65 L_52 ) ;
return - V_49 ;
}
F_7 ( L_53 , V_82 -> V_90 ) ;
if ( V_82 -> V_90 ) {
F_15 ( V_65 L_54 ) ;
return - V_49 ;
}
V_8 -> V_15 = V_82 -> V_15 ;
F_7 ( L_55 ,
V_8 -> V_15 ) ;
F_7 ( L_56 , V_82 -> V_91 ) ;
V_8 -> V_33 = V_82 -> V_91 & 3 ;
V_8 -> V_14 = ( ( V_82 -> V_91 ) >> 2 ) & 3 ;
V_83 = ( ( V_82 -> V_91 ) >> 4 ) & 3 ;
V_8 -> V_37 = 1 << V_83 ;
V_8 -> V_74 = ( ( V_82 -> V_91 ) >> 6 ) & 3 ;
F_7 ( L_57 , V_8 -> V_33 ) ;
F_7 ( L_58 , V_8 -> V_14 ) ;
F_7 ( L_59 , V_83 , V_8 -> V_37 ) ;
F_7 ( L_60 , V_82 -> V_92 ) ;
V_84 = V_82 -> V_92 ;
if ( ( V_82 -> F_25 == 0x00000fc0 ) ||
( V_82 -> F_25 == 0x00000fe0 ) ) {
V_85 = F_23 ( V_50 ) ;
if ( ( V_85 == 0x00000fc0 ) ||
( V_85 == 0x00000fe0 ) )
V_84 = 1 ;
}
if ( V_84 != 1 ) {
F_15 ( V_65 L_61 ) ;
return - V_49 ;
}
V_8 -> V_25 = V_82 -> V_93 ;
F_7 ( L_62 , V_82 -> V_93 ) ;
F_7 ( L_63 , V_82 -> V_94 ) ;
F_7 ( L_64 , V_82 -> V_34 ) ;
V_34 = V_82 -> V_34 ;
V_8 -> V_63 = V_82 -> V_63 ;
F_7 ( L_65 , V_8 -> V_63 ) ;
return F_29 ( V_8 ,
(struct V_59 * ) ( V_82 + 1 ) , V_34 ) ;
}
F_15 ( V_65 L_66 ) ;
F_15 ( L_67 ) ;
return - V_49 ;
}
static void F_37 ( struct V_7 * V_8 ,
unsigned int V_95 )
{
T_3 V_96 ;
if ( ! V_8 -> V_97 . V_98 )
return;
V_96 = V_8 -> V_97 . V_99 [ V_95 ] . V_96 ;
V_8 -> V_14 = ( V_96 >> V_100 ) & V_101 ;
V_8 -> V_33 = ( V_96 >> V_102 ) & V_103 ;
V_8 -> V_104 = ( V_96 >> V_105 ) & V_106 ;
V_8 -> V_25 = ( V_96 >> V_107 ) & V_108 ;
V_8 -> V_37 = 1 << ( ( V_96 >> V_109 ) & V_110 ) ;
V_8 -> V_15 = ( V_96 >> V_111 ) & V_112 ;
}
static int F_38 ( struct V_7 * V_8 )
{
struct V_68 * V_69 ;
int V_113 = - V_49 ;
T_3 V_96 , V_114 ;
if ( F_39 ( & V_8 -> V_97 , V_8 -> V_80 ) ) {
F_7 ( L_68 ) ;
return - V_79 ;
}
if ( V_8 -> V_97 . V_98 <= 1 ) {
F_7 ( L_69 ) ;
goto V_115;
}
V_96 = V_8 -> V_97 . V_116 . V_117 ;
V_114 = V_8 -> V_97 . V_118 . V_117 ;
if ( ( V_96 != V_119 ) ||
( V_114 != V_119 ) ) {
F_7 ( L_70 ,
V_96 , V_114 ) ;
goto V_115;
}
V_69 = F_31 ( ( sizeof( * V_69 )
* ( V_8 -> V_97 . V_98 + 1 ) ) , V_75 ) ;
if ( ! V_69 ) {
F_7 ( L_47 ) ;
goto V_115;
}
V_8 -> V_63 = V_8 -> V_97 . V_98 ;
F_37 ( V_8 , 0 ) ;
V_113 = F_40 ( V_8 , V_69 ) ;
if ( V_113 )
goto V_120;
V_69 [ V_8 -> V_97 . V_98 ] . V_71 =
V_78 ;
V_8 -> V_69 = V_69 ;
if ( F_33 ( F_34 ( V_8 -> V_80 ) ) == V_8 -> V_80 )
F_28 ( V_8 ) ;
F_41 ( V_121 ) ;
if ( ! F_42 ( & V_8 -> V_97 . V_122 , V_75 ) ) {
F_15 ( L_71 ) ;
V_113 = - V_76 ;
goto V_120;
}
return 0 ;
V_120:
F_32 ( V_69 ) ;
V_115:
F_43 ( & V_8 -> V_97 , V_8 -> V_80 ) ;
V_8 -> V_97 . V_98 = 0 ;
return V_113 ;
}
static int F_40 ( struct V_7 * V_8 ,
struct V_68 * V_69 )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < V_8 -> V_97 . V_98 ; V_9 ++ ) {
T_1 V_1 ;
T_1 V_17 ;
T_1 V_77 , V_95 ;
T_3 V_114 , V_96 ;
if ( V_8 -> V_104 ) {
V_114 = V_8 -> V_97 . V_99 [ V_9 ] . V_114 ;
V_1 = V_114 & V_123 ;
V_17 = ( V_114 >> V_124 ) & V_125 ;
} else {
V_96 = V_8 -> V_97 . V_99 [ V_9 ] . V_96 ;
V_1 = V_96 & V_126 ;
V_17 = ( V_96 >> V_124 ) & V_127 ;
}
F_7 ( L_72 , V_9 , V_1 , V_17 ) ;
V_95 = V_1 | ( V_17 << 8 ) ;
V_69 [ V_9 ] . V_73 = V_95 ;
V_77 = F_2 ( V_1 ) ;
V_69 [ V_9 ] . V_71 = V_77 ;
if ( ( V_77 > ( V_128 * 1000 ) ) || ( V_77 < ( V_129 * 1000 ) ) ) {
F_7 ( L_73 , V_77 ) ;
F_27 ( V_69 , V_9 ) ;
continue;
}
if ( V_17 == V_130 ) {
F_7 ( L_74 , V_17 ) ;
F_27 ( V_69 , V_9 ) ;
continue;
}
if ( V_77 != ( V_8 -> V_97 . V_99 [ V_9 ] . V_131 * 1000 ) ) {
F_24 ( L_75 ,
V_77 , ( unsigned int )
( V_8 -> V_97 . V_99 [ V_9 ] . V_131
* 1000 ) ) ;
F_27 ( V_69 , V_9 ) ;
continue;
}
}
return 0 ;
}
static void F_44 ( struct V_7 * V_8 )
{
if ( V_8 -> V_97 . V_98 )
F_43 ( & V_8 -> V_97 ,
V_8 -> V_80 ) ;
F_45 ( V_8 -> V_97 . V_122 ) ;
}
static int F_46 ( struct V_7 * V_8 )
{
int V_132 = 0 ;
int V_9 ;
for ( V_9 = 0 ; V_9 < V_8 -> V_97 . V_98 ; V_9 ++ ) {
int V_133 = V_8 -> V_97 . V_99 [ V_9 ] . V_134
+ V_8 -> V_97 . V_99 [ V_9 ] . V_135 ;
if ( V_133 > V_132 )
V_132 = V_133 ;
}
if ( V_132 == 0 ) {
F_15 ( V_136 L_76 ) ;
V_132 = 1 ;
}
return 1000 * V_132 ;
}
static int F_47 ( struct V_7 * V_8 ,
unsigned int V_95 )
{
struct V_137 * V_138 ;
T_1 V_1 = 0 ;
T_1 V_17 = 0 ;
int V_139 ;
struct V_140 V_141 ;
F_7 ( L_77 , F_12 () , V_95 ) ;
V_1 = V_8 -> V_69 [ V_95 ] . V_73 & 0xFF ;
V_17 = ( V_8 -> V_69 [ V_95 ] . V_73 & 0xFF00 ) >> 8 ;
F_7 ( L_78 , V_1 , V_17 ) ;
if ( F_6 ( V_8 ) )
return 1 ;
if ( ( V_8 -> V_10 == V_17 ) && ( V_8 -> V_12 == V_1 ) ) {
F_7 ( L_79 ,
V_1 , V_17 ) ;
return 0 ;
}
F_7 ( L_80 ,
F_12 () , V_1 , V_17 ) ;
V_141 . V_142 = F_2 ( V_8 -> V_12 ) ;
V_141 . V_143 = F_2 ( V_1 ) ;
V_138 = F_48 ( F_12 () ) ;
F_49 ( V_138 ) ;
F_50 ( V_138 , & V_141 ) ;
V_139 = F_18 ( V_8 , V_1 , V_17 ) ;
F_51 ( V_138 , & V_141 , V_139 ) ;
return V_139 ;
}
static long F_52 ( void * V_144 )
{
struct V_145 * V_146 = V_144 ;
struct V_137 * V_147 = V_146 -> V_147 ;
unsigned V_148 = V_146 -> V_148 ;
struct V_7 * V_8 = F_53 ( V_149 , V_147 -> V_80 ) ;
T_1 V_150 ;
T_1 V_151 ;
int V_152 ;
if ( ! V_8 )
return - V_66 ;
V_150 = V_8 -> V_12 ;
V_151 = V_8 -> V_10 ;
if ( F_4 () ) {
F_15 ( L_81 ) ;
return - V_79 ;
}
F_7 ( L_82 ,
V_147 -> V_80 , V_8 -> V_69 [ V_148 ] . V_71 , V_147 -> V_153 ,
V_147 -> V_154 ) ;
if ( F_6 ( V_8 ) )
return - V_79 ;
F_7 ( L_83 ,
V_8 -> V_12 , V_8 -> V_10 ) ;
if ( ( V_151 != V_8 -> V_10 ) ||
( V_150 != V_8 -> V_12 ) ) {
F_24 ( L_84 ,
V_150 , V_8 -> V_12 ,
V_151 , V_8 -> V_10 ) ;
}
F_54 ( & V_155 ) ;
F_37 ( V_8 , V_148 ) ;
V_152 = F_47 ( V_8 , V_148 ) ;
if ( V_152 ) {
F_15 ( L_85 ) ;
F_55 ( & V_155 ) ;
return 1 ;
}
F_55 ( & V_155 ) ;
V_147 -> V_156 = F_2 ( V_8 -> V_12 ) ;
return 0 ;
}
static int F_56 ( struct V_137 * V_147 , unsigned V_95 )
{
struct V_145 V_146 = { . V_147 = V_147 , . V_148 = V_95 } ;
return F_57 ( V_147 -> V_80 , F_52 , & V_146 ) ;
}
static void F_58 ( void * V_157 )
{
struct V_158 * V_158 = V_157 ;
if ( F_4 () ) {
F_15 ( L_86 ) ;
V_158 -> V_48 = - V_49 ;
return;
}
if ( F_6 ( V_158 -> V_8 ) ) {
V_158 -> V_48 = - V_49 ;
return;
}
F_11 () ;
V_158 -> V_48 = 0 ;
}
static int F_59 ( struct V_137 * V_147 )
{
struct V_7 * V_8 ;
struct V_158 V_158 ;
int V_48 , V_80 ;
F_60 ( V_147 -> V_80 , F_22 , & V_48 , 1 ) ;
if ( V_48 )
return - V_49 ;
V_8 = F_31 ( sizeof( * V_8 ) , V_75 ) ;
if ( ! V_8 ) {
F_15 ( L_87 ) ;
return - V_76 ;
}
V_8 -> V_80 = V_147 -> V_80 ;
if ( F_38 ( V_8 ) ) {
if ( F_61 () != 1 ) {
F_62 ( V_159 ) ;
goto V_115;
}
if ( V_147 -> V_80 != 0 ) {
F_15 ( V_65 L_88 ) ;
goto V_115;
}
V_48 = F_35 ( V_8 ) ;
if ( V_48 )
goto V_115;
V_147 -> V_160 . V_134 = (
( ( V_8 -> V_33 + 8 ) * V_8 -> V_15 * V_16 ) +
( ( 1 << V_8 -> V_14 ) * 30 ) ) * 1000 ;
} else
V_147 -> V_160 . V_134 = F_46 ( V_8 ) ;
V_158 . V_8 = V_8 ;
F_60 ( V_8 -> V_80 , F_58 ,
& V_158 , 1 ) ;
V_48 = V_158 . V_48 ;
if ( V_48 != 0 )
goto V_161;
F_63 ( V_147 -> V_162 , F_34 ( V_147 -> V_80 ) ) ;
V_8 -> V_163 = V_147 -> V_162 ;
if ( F_64 ( V_147 , V_8 -> V_69 ) ) {
F_15 ( V_65 L_89 ) ;
F_44 ( V_8 ) ;
F_32 ( V_8 -> V_69 ) ;
F_32 ( V_8 ) ;
return - V_66 ;
}
F_7 ( L_90 ,
V_8 -> V_12 , V_8 -> V_10 ) ;
F_65 (cpu, pol->cpus)
F_53 ( V_149 , V_80 ) = V_8 ;
return 0 ;
V_161:
F_44 ( V_8 ) ;
V_115:
F_32 ( V_8 ) ;
return - V_49 ;
}
static int F_66 ( struct V_137 * V_147 )
{
struct V_7 * V_8 = F_53 ( V_149 , V_147 -> V_80 ) ;
int V_80 ;
if ( ! V_8 )
return - V_66 ;
F_44 ( V_8 ) ;
F_32 ( V_8 -> V_69 ) ;
F_32 ( V_8 ) ;
F_65 (cpu, pol->cpus)
F_53 ( V_149 , V_80 ) = NULL ;
return 0 ;
}
static void F_67 ( void * V_164 )
{
int * V_165 = V_164 ;
struct V_7 * V_8 = F_68 ( V_149 ) ;
* V_165 = F_6 ( V_8 ) ;
}
static unsigned int F_69 ( unsigned int V_80 )
{
struct V_7 * V_8 = F_53 ( V_149 , V_80 ) ;
unsigned int V_166 = 0 ;
int V_165 ;
if ( ! V_8 )
return 0 ;
F_60 ( V_80 , F_67 , & V_165 , true ) ;
if ( V_165 )
goto V_167;
V_166 = F_2 ( V_8 -> V_12 ) ;
V_167:
return V_166 ;
}
static void F_70 ( void )
{
const char * V_168 , * V_169 = L_91 ;
V_168 = F_71 () ;
if ( ! V_168 )
goto V_170;
if ( strncmp ( V_168 , V_169 , F_72 ( V_171 , strlen ( V_168 ) , strlen ( V_169 ) ) ) )
F_30 ( L_92 , V_168 ) ;
return;
V_170:
F_30 ( L_93 ) ;
F_73 ( V_169 ) ;
}
static int F_74 ( void )
{
unsigned int V_9 , V_172 = 0 ;
int V_152 ;
if ( F_75 ( V_173 ) ) {
F_70 () ;
return - V_49 ;
}
if ( ! F_76 ( V_174 ) )
return - V_49 ;
F_77 () ;
F_78 (i) {
F_60 ( V_9 , F_22 , & V_152 , 1 ) ;
if ( ! V_152 )
V_172 ++ ;
}
if ( V_172 != F_61 () ) {
F_79 () ;
return - V_49 ;
}
F_79 () ;
V_152 = F_80 ( & V_175 ) ;
if ( V_152 )
return V_152 ;
F_24 ( L_94 V_176 L_95 ,
F_81 () , V_177 . V_178 , V_172 ) ;
return V_152 ;
}
static void T_4 F_82 ( void )
{
F_7 ( L_96 ) ;
F_83 ( & V_175 ) ;
}
