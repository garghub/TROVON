static T_1 F_1 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_4 * V_5 = & V_2 -> V_6 ;
F_2 ( & V_5 -> V_7 ) ;
V_3 = F_3 ( V_5 -> V_8 , V_5 -> V_9 ) ;
if ( V_3 < V_5 -> V_9 ) {
F_4 ( V_3 , V_5 -> V_8 ) ;
V_3 += V_5 -> V_10 ;
} else
V_3 = V_11 ;
F_5 ( & V_5 -> V_7 ) ;
return ( T_1 ) V_3 ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_12 ;
struct V_4 * V_5 = & V_2 -> V_6 ;
V_3 -= V_5 -> V_10 ;
F_2 ( & V_5 -> V_7 ) ;
V_12 = F_7 ( V_3 , V_5 -> V_8 ) ;
F_5 ( & V_5 -> V_7 ) ;
return V_12 ;
}
static void F_8 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = & V_2 -> V_6 ;
V_3 -= V_5 -> V_10 ;
F_2 ( & V_5 -> V_7 ) ;
F_9 ( V_3 , V_5 -> V_8 ) ;
F_5 ( & V_5 -> V_7 ) ;
}
static T_1 F_10 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_4 * V_5 = & V_2 -> V_6 ;
F_2 ( & V_5 -> V_7 ) ;
V_3 = F_11 ( V_5 -> V_8 , V_5 -> V_9 ) ;
if ( V_3 >= V_5 -> V_9 )
V_3 = V_11 ;
else
V_3 += V_5 -> V_10 ;
F_5 ( & V_5 -> V_7 ) ;
return ( T_1 ) V_3 ;
}
static T_1 F_12 ( struct V_1 * V_2 , T_1 V_13 )
{
int V_3 ;
struct V_4 * V_5 = & V_2 -> V_6 ;
F_2 ( & V_5 -> V_7 ) ;
V_3 = F_13 ( V_5 -> V_8 , V_5 -> V_9 , V_13 ) ;
if ( V_3 >= V_5 -> V_9 )
V_3 = V_11 ;
else
V_3 += V_5 -> V_10 ;
F_5 ( & V_5 -> V_7 ) ;
return ( T_1 ) V_3 ;
}
static T_1 F_14 ( struct V_14 * V_15 , T_1 V_3 , T_2 V_16 )
{
T_3 V_17 ;
F_15 ( V_15 , V_3 , V_16 , V_18 , & V_17 ) ;
return F_16 ( V_15 -> V_19 , V_17 ) ;
}
static void F_17 ( struct V_14 * V_15 , T_1 V_3 , T_2 V_16 , T_1 V_20 )
{
F_18 ( V_15 , V_3 , V_16 , V_18 ,
F_19 ( V_15 -> V_19 , V_20 ) ) ;
}
static void F_20 ( struct V_14 * V_15 , T_1 V_20 )
{
F_21 ( V_15 , V_18 , F_19 ( V_15 -> V_19 ,
V_20 ) ) ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = V_2 -> V_21 ;
struct V_22 * V_23 ;
T_3 V_17 ;
int V_24 = 0 ;
F_21 ( V_15 , V_25 ,
V_15 -> V_26 ) ;
F_23 ( V_15 , V_25 , & V_17 ) ;
if ( ( V_17 & 0xffff ) != 0xffff ) {
F_24 ( V_27
L_1 ,
V_17 ) ;
V_24 = - V_28 ;
}
F_25 (rdev, &net->devices, net_list) {
F_26 ( V_23 , V_25 ,
V_15 -> V_26 ) ;
F_27 ( V_23 , V_25 , & V_17 ) ;
if ( ( V_17 & 0xffff ) != 0xffff ) {
F_24 ( V_27
L_2 ,
V_23 -> V_29 , V_23 -> V_20 ) ;
V_24 = - V_28 ;
}
F_27 ( V_23 ,
V_23 -> V_30 + V_31 ,
& V_17 ) ;
V_17 |= V_32 | V_33 ;
F_26 ( V_23 ,
V_23 -> V_30 + V_31 ,
V_17 ) ;
}
return V_24 ;
}
static int F_28 ( struct V_14 * V_15 )
{
T_3 V_17 ;
F_21 ( V_15 , V_25 ,
V_15 -> V_26 ) ;
F_23 ( V_15 , V_25 , & V_17 ) ;
if ( ( V_17 & 0xffff ) != V_15 -> V_26 )
return - 1 ;
F_20 ( V_15 , V_15 -> V_26 ) ;
return 0 ;
}
static int F_29 ( struct V_14 * V_15 , int V_34 ,
int V_35 )
{
T_3 V_36 = V_37 | V_38 | V_39 | V_40 | V_41 | V_42 | V_43 ;
return ! ! ( ( V_34 | V_35 ) & V_36 ) ;
}
static void F_30 ( struct V_44 * V_45 )
{
struct V_22 * V_23 ;
V_23 = F_31 ( V_45 ) ;
F_32 ( V_23 ) ;
}
static int F_33 ( struct V_22 * V_23 )
{
if ( V_23 -> V_46 & V_47 )
return 1 ;
return 0 ;
}
static struct V_22 * F_34 ( struct V_1 * V_2 ,
struct V_14 * V_15 , T_1 V_3 ,
T_2 V_16 , int V_48 )
{
int V_24 = 0 ;
struct V_22 * V_23 ;
struct V_49 * V_50 = NULL ;
int V_17 , V_51 ;
T_4 V_52 ;
T_3 V_53 = 0 ;
V_52 = sizeof( struct V_22 ) ;
if ( F_15 ( V_15 , V_3 , V_16 ,
V_54 , & V_17 ) )
return NULL ;
if ( V_17 & ( V_47 | V_55 ) ) {
F_15 ( V_15 , V_3 , V_16 ,
V_56 , & V_53 ) ;
if ( V_17 & V_47 ) {
V_52 += ( F_35 ( V_53 ) *
sizeof( V_50 -> V_57 [ 0 ] ) ) + sizeof( * V_50 ) ;
}
}
V_23 = F_36 ( V_52 , V_58 ) ;
if ( ! V_23 )
return NULL ;
V_23 -> V_2 = V_2 ;
V_23 -> V_46 = V_17 ;
V_23 -> V_53 = V_53 ;
F_15 ( V_15 , V_3 , V_16 , V_59 ,
& V_17 ) ;
V_23 -> V_20 = V_17 >> 16 ;
V_23 -> V_29 = V_17 & 0xffff ;
F_15 ( V_15 , V_3 , V_16 , V_60 ,
& V_23 -> V_61 ) ;
F_15 ( V_15 , V_3 , V_16 , V_62 ,
& V_17 ) ;
V_23 -> V_63 = V_17 >> 16 ;
V_23 -> V_64 = V_17 & 0xffff ;
F_15 ( V_15 , V_3 , V_16 , V_65 ,
& V_17 ) ;
V_23 -> V_66 = V_17 >> 16 ;
if ( V_23 -> V_46 & V_67 ) {
V_23 -> V_68 = V_17 & 0xffff ;
V_23 -> V_30 = F_37 ( V_15 , 0 , V_3 ,
V_16 ) ;
V_23 -> V_69 = F_38 ( V_15 , 0 , V_3 ,
V_16 , V_70 ) ;
}
F_15 ( V_15 , V_3 , V_16 , V_71 ,
& V_23 -> V_34 ) ;
F_15 ( V_15 , V_3 , V_16 , V_72 ,
& V_23 -> V_35 ) ;
if ( V_48 ) {
if ( V_73 >= 0x10000 ) {
F_39 ( L_3 ) ;
goto V_74;
}
F_18 ( V_15 , V_3 , V_16 ,
V_75 , V_73 ) ;
V_23 -> V_76 = V_73 ++ ;
V_23 -> V_48 = true ;
} else {
F_15 ( V_15 , V_3 , V_16 ,
V_75 ,
& V_23 -> V_76 ) ;
}
if ( F_29 ( V_15 , V_23 -> V_34 , V_23 -> V_35 ) ) {
if ( V_48 ) {
F_17 ( V_15 , V_3 , V_16 , V_77 ) ;
V_23 -> V_3 = V_77 ;
V_77 = F_1 ( V_2 ) ;
} else
V_23 -> V_3 = F_14 ( V_15 , V_3 , V_16 ) ;
V_23 -> V_16 = 0xff ;
} else {
V_23 -> V_3 = V_3 ;
V_23 -> V_16 = V_16 ;
}
if ( F_33 ( V_23 ) ) {
V_50 = V_23 -> V_50 ;
V_50 -> V_78 = 0 ;
F_40 ( & V_50 -> V_7 ) ;
V_50 -> V_79 = F_36 ( sizeof( T_2 ) *
F_41 ( V_15 -> V_19 ) ,
V_58 ) ;
if ( ! V_50 -> V_79 )
goto V_74;
for ( V_51 = 0 ; V_51 < F_41 ( V_15 -> V_19 ) ;
V_51 ++ )
V_50 -> V_79 [ V_51 ] = V_80 ;
F_42 ( & V_23 -> V_45 , L_4 , V_23 -> V_2 -> V_81 ,
V_23 -> V_76 & V_82 ) ;
if ( V_48 )
F_43 ( V_23 , V_83 , 0 ) ;
F_44 ( & V_50 -> V_84 , & V_2 -> V_85 ) ;
} else {
if ( V_48 )
F_45 ( V_15 , 0 , V_3 , V_16 , 0 ) ;
F_42 ( & V_23 -> V_45 , L_5 , V_23 -> V_2 -> V_81 ,
V_23 -> V_76 & V_82 ) ;
}
V_23 -> V_45 . V_86 = & V_15 -> V_45 ;
F_46 ( V_23 ) ;
F_47 ( & V_23 -> V_45 ) ;
V_23 -> V_45 . V_87 = F_30 ;
F_48 ( V_23 ) ;
V_23 -> V_88 = F_49 ( 32 ) ;
V_23 -> V_45 . V_88 = & V_23 -> V_88 ;
V_23 -> V_45 . V_89 = F_49 ( 32 ) ;
if ( V_23 -> V_35 & V_90 )
F_50 ( & V_23 -> V_91 [ V_92 ] ,
0 , 0xffff ) ;
V_24 = F_51 ( V_23 ) ;
if ( V_24 )
goto V_74;
return V_23 ;
V_74:
if ( V_50 )
F_32 ( V_50 -> V_79 ) ;
F_32 ( V_23 ) ;
return NULL ;
}
static int
F_52 ( struct V_14 * V_15 , T_1 V_3 , T_2 V_16 , int V_93 )
{
T_3 V_17 = 0 ;
T_3 V_94 ;
V_94 = F_53 ( V_15 , 0 , V_3 , V_16 , 0 ) ;
while ( V_94 ) {
F_15 ( V_15 , V_3 , V_16 ,
V_94 , & V_17 ) ;
V_17 = F_54 ( V_17 ) ;
if ( ( V_17 == V_95 ) ||
( V_17 == V_96 ) ||
( V_17 == V_97 ) )
break;
V_94 = F_53 ( V_15 , 0 , V_3 , V_16 ,
V_94 ) ;
}
if ( V_94 )
F_15 ( V_15 , V_3 , V_16 ,
V_94 +
F_55 ( V_93 ) ,
& V_17 ) ;
return V_17 & V_98 ;
}
static T_1 F_56 ( struct V_14 * V_15 , T_2 V_16 )
{
T_3 V_17 ;
F_15 ( V_15 , F_57 ( V_15 -> V_19 ) , V_16 ,
V_25 , & V_17 ) ;
return ( T_1 ) ( V_17 & 0xffff ) ;
}
static int F_58 ( struct V_1 * V_2 , struct V_14 * V_15 ,
T_2 V_16 , struct V_22 * V_99 , int V_100 )
{
struct V_22 * V_23 ;
T_3 V_101 ;
int V_102 ;
if ( F_59 ( V_15 ,
F_57 ( V_15 -> V_19 ) , V_16 ) ) {
F_60 ( L_6 ) ;
return - 1 ;
}
if ( F_56 ( V_15 , V_16 ) == V_15 -> V_26 ) {
F_60 ( L_7 ) ;
F_15 ( V_15 , F_57 ( V_15 -> V_19 ) ,
V_16 , V_75 , & V_101 ) ;
if ( V_101 ) {
V_23 = F_61 ( ( V_101 & 0xffff ) , NULL ) ;
if ( V_23 && V_99 && F_33 ( V_99 ) ) {
F_60 ( L_8 ,
F_62 ( V_23 ) ) ;
V_99 -> V_50 -> V_57 [ V_100 ] = V_23 ;
}
}
return 0 ;
}
F_18 ( V_15 , F_57 ( V_15 -> V_19 ) ,
V_16 ,
V_25 , V_15 -> V_26 ) ;
while ( ( V_102 = F_56 ( V_15 , V_16 ) )
< V_15 -> V_26 ) {
F_63 ( 1 ) ;
F_18 ( V_15 , F_57 ( V_15 -> V_19 ) ,
V_16 ,
V_25 ,
V_15 -> V_26 ) ;
}
if ( F_56 ( V_15 , V_16 ) > V_15 -> V_26 ) {
F_60 (
L_9 ) ;
return - 1 ;
}
V_23 = F_34 ( V_2 , V_15 , F_57 ( V_15 -> V_19 ) ,
V_16 , 1 ) ;
if ( V_23 ) {
F_44 ( & V_23 -> V_103 , & V_2 -> V_104 ) ;
V_23 -> V_99 = V_99 ;
if ( V_99 && F_33 ( V_99 ) )
V_99 -> V_50 -> V_57 [ V_100 ] = V_23 ;
} else
return - 1 ;
if ( F_33 ( V_23 ) ) {
int V_105 ;
int V_106 ;
int V_107 ;
T_1 V_3 ;
int V_108 ;
V_107 = F_64 ( V_23 -> V_53 ) ;
F_65 ( V_23 , V_83 ,
V_15 -> V_26 , V_107 , 0 ) ;
V_23 -> V_50 -> V_79 [ V_15 -> V_26 ] = V_107 ;
V_3 = F_10 ( V_2 ) ;
while ( V_3 != V_11 && V_3 < V_77 ) {
if ( V_3 != V_15 -> V_26 ) {
F_65 ( V_23 , V_83 ,
V_3 , V_107 , 0 ) ;
V_23 -> V_50 -> V_79 [ V_3 ] = V_107 ;
}
V_3 = F_12 ( V_2 , V_3 + 1 ) ;
}
F_60 (
L_10 ,
F_62 ( V_23 ) , V_23 -> V_29 , V_23 -> V_20 ,
F_35 ( V_23 -> V_53 ) ) ;
V_105 = V_77 ;
for ( V_108 = 0 ;
V_108 < F_35 ( V_23 -> V_53 ) ;
V_108 ++ ) {
if ( V_107 == V_108 ) {
F_45 ( V_15 , 0 ,
F_57 ( V_15 -> V_19 ) ,
V_16 , V_108 ) ;
V_23 -> V_50 -> V_78 |= ( 1 << V_108 ) ;
continue;
}
V_106 = V_77 ;
if ( F_52
( V_15 , F_57 ( V_15 -> V_19 ) , V_16 ,
V_108 ) ) {
F_60 (
L_11 ,
V_108 ) ;
F_45 ( V_15 , 0 ,
F_57 ( V_15 -> V_19 ) ,
V_16 , V_108 ) ;
V_23 -> V_50 -> V_78 |= ( 1 << V_108 ) ;
F_65 ( V_23 , V_83 ,
F_57 ( V_15 -> V_19 ) ,
V_108 , 0 ) ;
if ( F_58 ( V_2 , V_15 , V_16 + 1 ,
V_23 , V_108 ) < 0 )
return - 1 ;
V_3 = F_12 ( V_2 , V_106 + 1 ) ;
if ( V_3 != V_11 ) {
for ( V_3 = V_106 ;
V_3 < V_77 ; ) {
if ( V_3 != V_15 -> V_26 ) {
F_65 ( V_23 ,
V_83 ,
V_3 ,
V_108 ,
0 ) ;
V_23 -> V_50 ->
V_79 [ V_3 ] =
V_108 ;
}
V_3 = F_12 ( V_2 ,
V_3 + 1 ) ;
}
}
} else {
if ( V_23 -> V_69 )
F_66 ( V_23 , V_108 , 1 ) ;
V_23 -> V_50 -> V_78 &= ~ ( 1 << V_108 ) ;
}
}
if ( ( V_23 -> V_34 & V_109 ) &&
( V_23 -> V_69 ) ) {
F_26 ( V_23 ,
V_23 -> V_69 + V_110 ,
( V_15 -> V_26 << 16 ) |
( V_15 -> V_19 << 15 ) ) ;
}
F_67 ( V_23 ) ;
if ( V_77 == V_105 )
V_77 = F_1 ( V_2 ) ;
V_23 -> V_3 = V_105 ;
} else
F_60 ( L_12 ,
F_62 ( V_23 ) , V_23 -> V_29 , V_23 -> V_20 ) ;
return 0 ;
}
static int F_68 ( struct V_14 * V_15 )
{
T_3 V_101 ;
F_23 ( V_15 , V_15 -> V_30 + V_31 ,
& V_101 ) ;
return ( V_101 & V_32 ) ? 1 : 0 ;
}
static int
F_69 ( struct V_1 * V_2 , struct V_14 * V_15 , T_1 V_3 ,
T_2 V_16 , struct V_22 * V_99 , int V_100 )
{
T_2 V_108 , V_111 ;
struct V_22 * V_23 ;
T_1 V_112 ;
if ( ( V_23 = F_34 ( V_2 , V_15 , V_3 , V_16 , 0 ) ) ) {
F_44 ( & V_23 -> V_103 , & V_2 -> V_104 ) ;
V_23 -> V_99 = V_99 ;
if ( V_99 && F_33 ( V_99 ) )
V_99 -> V_50 -> V_57 [ V_100 ] = V_23 ;
} else
return - 1 ;
if ( F_33 ( V_23 ) ) {
V_23 -> V_3 = V_3 ;
F_60 (
L_10 ,
F_62 ( V_23 ) , V_23 -> V_29 , V_23 -> V_20 ,
F_35 ( V_23 -> V_53 ) ) ;
for ( V_108 = 0 ;
V_108 < F_35 ( V_23 -> V_53 ) ;
V_108 ++ ) {
if ( F_64 ( V_23 -> V_53 ) == V_108 )
continue;
if ( F_52
( V_15 , V_3 , V_16 , V_108 ) ) {
F_60 (
L_11 ,
V_108 ) ;
F_70 ( V_15 , V_3 , V_16 , 1000 ) ;
for ( V_112 = 0 ;
V_112 < F_57 ( V_15 -> V_19 ) ;
V_112 ++ ) {
F_71 ( V_23 ,
V_83 ,
V_112 ,
& V_111 , 0 ) ;
if ( V_111 == V_108 )
break;
}
if ( V_112 == F_57 ( V_15 -> V_19 ) )
continue;
F_72 ( V_15 , V_3 , V_16 ) ;
if ( F_69 ( V_2 , V_15 , V_112 ,
V_16 + 1 , V_23 , V_108 ) < 0 )
return - 1 ;
}
}
} else
F_60 ( L_12 ,
F_62 ( V_23 ) , V_23 -> V_29 , V_23 -> V_20 ) ;
return 0 ;
}
static int F_73 ( struct V_14 * V_15 )
{
T_3 V_17 = 0 ;
T_3 V_94 ;
int * V_113 = V_114 ;
do {
if ( ( V_94 =
F_38 ( V_15 , 1 , 0 , 0 , * V_113 ) ) )
break;
} while ( * ++ V_113 >= 0 );
if ( V_94 )
F_23 ( V_15 ,
V_94 +
F_55 ( V_15 -> V_115 ) ,
& V_17 ) ;
return V_17 & V_98 ;
}
static struct V_1 * F_74 ( struct V_14 * V_15 ,
int V_48 , T_1 V_10 )
{
struct V_1 * V_2 ;
V_2 = F_36 ( sizeof( struct V_1 ) , V_58 ) ;
if ( V_2 && V_48 ) {
V_2 -> V_6 . V_8 = F_75 (
F_76 ( F_41 ( V_15 -> V_19 ) ) ,
sizeof( long ) ,
V_58 ) ;
if ( V_2 -> V_6 . V_8 == NULL ) {
F_39 ( L_13 ) ;
F_32 ( V_2 ) ;
V_2 = NULL ;
} else {
V_2 -> V_6 . V_10 = V_10 ;
V_2 -> V_6 . V_9 =
F_41 ( V_15 -> V_19 ) ;
F_40 ( & V_2 -> V_6 . V_7 ) ;
}
}
if ( V_2 ) {
F_77 ( & V_2 -> V_84 ) ;
F_77 ( & V_2 -> V_104 ) ;
F_77 ( & V_2 -> V_85 ) ;
F_77 ( & V_2 -> V_116 ) ;
F_44 ( & V_15 -> V_117 , & V_2 -> V_116 ) ;
V_2 -> V_21 = V_15 ;
V_2 -> V_81 = V_15 -> V_81 ;
}
return V_2 ;
}
static void F_78 ( struct V_1 * V_2 )
{
struct V_22 * V_23 , * V_118 ;
struct V_49 * V_50 ;
T_2 V_93 ;
T_1 V_3 ;
F_25 (rdev, &net->devices, net_list) {
V_3 = V_23 -> V_3 ;
F_25 (rswitch, &net->switches, node) {
if ( F_33 ( V_23 ) && ( V_23 -> V_50 == V_50 ) )
continue;
if ( V_80 == V_50 -> V_79 [ V_3 ] ) {
V_118 = F_79 ( V_50 ) ;
if ( V_118 -> V_3 == V_3 )
continue;
V_93 = F_64 ( V_118 -> V_53 ) ;
F_65 ( V_118 , V_83 ,
V_3 , V_93 , 0 ) ;
V_50 -> V_79 [ V_3 ] = V_93 ;
}
}
}
}
static void F_67 ( struct V_22 * V_23 )
{
if ( F_33 ( V_23 ) && ( V_23 -> V_69 ) &&
V_23 -> V_50 -> V_119 && V_23 -> V_50 -> V_119 -> V_120 ) {
V_23 -> V_50 -> V_119 -> V_120 ( V_23 ) ;
}
}
static void F_80 ( struct V_14 * V_15 , int V_121 )
{
if ( V_15 -> V_119 -> V_122 )
V_15 -> V_119 -> V_122 ( V_15 , V_121 ) ;
}
static int F_81 ( struct V_14 * V_123 , T_3 V_124 )
{
struct V_1 * V_2 = NULL ;
int V_125 = 0 ;
F_24 ( V_27 L_14 , V_123 -> V_81 ,
V_123 -> V_126 ) ;
if ( V_123 -> V_117 . V_127 || V_123 -> V_117 . V_99 )
return - V_128 ;
if ( F_28 ( V_123 ) < 0 ) {
F_24 ( V_27
L_15 ,
V_123 -> V_81 ) ;
V_125 = - V_128 ;
goto V_129;
}
if ( F_73 ( V_123 ) ) {
V_2 = F_74 ( V_123 , 1 , 0 ) ;
if ( ! V_2 ) {
F_24 ( V_130 L_16 ) ;
V_125 = - V_131 ;
goto V_129;
}
F_6 ( V_2 , V_123 -> V_26 ) ;
F_45 ( V_123 , 1 , 0 , 0 , 0 ) ;
F_21 ( V_123 , V_75 ,
V_73 ++ ) ;
V_77 = F_1 ( V_2 ) ;
if ( F_58 ( V_2 , V_123 , 0 , NULL , 0 ) < 0 ) {
F_24 ( V_27
L_17 ,
V_123 -> V_81 ) ;
F_22 ( V_2 ) ;
V_125 = - V_128 ;
goto V_129;
}
F_8 ( V_2 , V_77 ) ;
F_78 ( V_2 ) ;
F_22 ( V_2 ) ;
F_80 ( V_123 , 1 ) ;
} else {
F_24 ( V_27 L_18 ,
V_123 -> V_81 ) ;
V_125 = - V_28 ;
}
V_129:
return V_125 ;
}
static void F_82 ( struct V_1 * V_2 )
{
struct V_49 * V_50 ;
struct V_22 * V_23 ;
int V_132 ;
T_2 V_93 ;
F_25 (rswitch, &net->switches, node) {
V_23 = F_79 ( V_50 ) ;
F_70 ( V_2 -> V_21 , V_23 -> V_3 ,
V_23 -> V_16 , 1000 ) ;
for ( V_132 = 0 ;
V_132 < F_41 ( V_2 -> V_21 -> V_19 ) ;
V_132 ++ ) {
if ( F_71 ( V_23 , V_83 ,
V_132 , & V_93 , 0 ) < 0 )
continue;
V_50 -> V_79 [ V_132 ] = V_93 ;
}
F_72 ( V_2 -> V_21 , V_23 -> V_3 , V_23 -> V_16 ) ;
}
}
static int F_83 ( struct V_14 * V_123 , T_3 V_124 )
{
struct V_1 * V_2 = NULL ;
unsigned long V_133 ;
F_24 ( V_27 L_19 , V_123 -> V_81 ,
V_123 -> V_126 ) ;
if ( F_73 ( V_123 ) ) {
if ( F_68 ( V_123 ) )
goto V_134;
else if ( V_124 & V_135 )
return - V_136 ;
F_60 ( L_20 ) ;
V_133 = V_137 + V_138 * V_139 ;
while ( F_84 ( V_137 , V_133 ) ) {
if ( F_68 ( V_123 ) )
goto V_134;
F_85 ( 10 ) ;
}
F_60 ( L_21 ,
V_123 -> V_81 , V_123 -> V_126 ) ;
goto V_140;
V_134:
F_60 ( L_22 ) ;
V_2 = F_74 ( V_123 , 0 , 0 ) ;
if ( ! V_2 ) {
F_24 ( V_130 L_23 ) ;
goto V_140;
}
F_23 ( V_123 , V_18 ,
& V_123 -> V_26 ) ;
V_123 -> V_26 = F_16 ( V_123 -> V_19 ,
V_123 -> V_26 ) ;
if ( F_69 ( V_2 , V_123 , F_57 ( V_123 -> V_19 ) ,
0 , NULL , 0 ) < 0 ) {
F_24 ( V_27
L_24 ,
V_123 -> V_81 ) ;
goto V_140;
}
F_82 ( V_2 ) ;
}
return 0 ;
V_140:
return - V_128 ;
}
static int T_5 F_86 ( void )
{
if ( F_87 ( V_141 , & V_142 ) )
return - V_143 ;
if ( V_144 )
F_88 () ;
return 0 ;
}
