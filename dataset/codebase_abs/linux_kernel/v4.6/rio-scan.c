static T_1 F_1 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_4 * V_5 = (struct V_4 * ) V_2 -> V_6 ;
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
struct V_4 * V_5 = (struct V_4 * ) V_2 -> V_6 ;
V_3 -= V_5 -> V_10 ;
F_2 ( & V_5 -> V_7 ) ;
V_12 = F_7 ( V_3 , V_5 -> V_8 ) ;
F_5 ( & V_5 -> V_7 ) ;
return V_12 ;
}
static void F_8 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = (struct V_4 * ) V_2 -> V_6 ;
V_3 -= V_5 -> V_10 ;
F_2 ( & V_5 -> V_7 ) ;
F_9 ( V_3 , V_5 -> V_8 ) ;
F_5 ( & V_5 -> V_7 ) ;
}
static T_1 F_10 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_4 * V_5 = (struct V_4 * ) V_2 -> V_6 ;
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
struct V_4 * V_5 = (struct V_4 * ) V_2 -> V_6 ;
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
static int F_20 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = V_2 -> V_21 ;
struct V_22 * V_23 ;
T_3 V_17 ;
int V_24 = 0 ;
F_21 ( V_15 , V_25 ,
V_15 -> V_26 ) ;
F_22 ( V_15 , V_25 , & V_17 ) ;
if ( ( V_17 & 0xffff ) != 0xffff ) {
F_23 ( V_27
L_1 ,
V_17 ) ;
V_24 = - V_28 ;
}
F_24 (rdev, &net->devices, net_list) {
F_25 ( V_23 , V_25 ,
V_15 -> V_26 ) ;
F_26 ( V_23 , V_25 , & V_17 ) ;
if ( ( V_17 & 0xffff ) != 0xffff ) {
F_23 ( V_27
L_2 ,
V_23 -> V_29 , V_23 -> V_20 ) ;
V_24 = - V_28 ;
}
F_26 ( V_23 ,
V_23 -> V_30 + V_31 ,
& V_17 ) ;
V_17 |= V_32 | V_33 ;
F_25 ( V_23 ,
V_23 -> V_30 + V_31 ,
V_17 ) ;
}
return V_24 ;
}
static int F_27 ( struct V_14 * V_15 )
{
T_3 V_17 ;
F_21 ( V_15 , V_25 ,
V_15 -> V_26 ) ;
F_22 ( V_15 , V_25 , & V_17 ) ;
if ( ( V_17 & 0xffff ) != V_15 -> V_26 )
return - 1 ;
F_28 ( V_15 , V_15 -> V_26 ) ;
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
} else {
if ( V_48 )
F_44 ( V_15 , 0 , V_3 , V_16 , 0 ) ;
F_42 ( & V_23 -> V_45 , L_5 , V_23 -> V_2 -> V_81 ,
V_23 -> V_76 & V_82 ) ;
}
V_23 -> V_45 . V_84 = & V_2 -> V_45 ;
F_45 ( V_23 ) ;
V_23 -> V_45 . V_85 = F_30 ;
V_23 -> V_86 = F_46 ( 32 ) ;
V_23 -> V_45 . V_86 = & V_23 -> V_86 ;
V_23 -> V_45 . V_87 = F_46 ( 32 ) ;
if ( V_23 -> V_35 & V_88 )
F_47 ( & V_23 -> V_89 [ V_90 ] ,
0 , 0xffff ) ;
V_24 = F_48 ( V_23 ) ;
if ( V_24 )
goto V_74;
F_49 ( V_23 ) ;
return V_23 ;
V_74:
if ( V_50 )
F_32 ( V_50 -> V_79 ) ;
F_32 ( V_23 ) ;
return NULL ;
}
static int
F_50 ( struct V_14 * V_15 , T_1 V_3 , T_2 V_16 , int V_91 )
{
T_3 V_17 = 0 ;
T_3 V_92 ;
V_92 = F_51 ( V_15 , 0 , V_3 , V_16 , 0 ) ;
while ( V_92 ) {
F_15 ( V_15 , V_3 , V_16 ,
V_92 , & V_17 ) ;
V_17 = F_52 ( V_17 ) ;
if ( ( V_17 == V_93 ) ||
( V_17 == V_94 ) ||
( V_17 == V_95 ) )
break;
V_92 = F_51 ( V_15 , 0 , V_3 , V_16 ,
V_92 ) ;
}
if ( V_92 )
F_15 ( V_15 , V_3 , V_16 ,
V_92 +
F_53 ( V_91 ) ,
& V_17 ) ;
return V_17 & V_96 ;
}
static T_1 F_54 ( struct V_14 * V_15 , T_2 V_16 )
{
T_3 V_17 ;
F_15 ( V_15 , F_55 ( V_15 -> V_19 ) , V_16 ,
V_25 , & V_17 ) ;
return ( T_1 ) ( V_17 & 0xffff ) ;
}
static int F_56 ( struct V_1 * V_2 , struct V_14 * V_15 ,
T_2 V_16 , struct V_22 * V_97 , int V_98 )
{
struct V_22 * V_23 ;
T_3 V_99 ;
int V_100 ;
if ( F_57 ( V_15 ,
F_55 ( V_15 -> V_19 ) , V_16 ) ) {
F_58 ( L_6 ) ;
return - 1 ;
}
if ( F_54 ( V_15 , V_16 ) == V_15 -> V_26 ) {
F_58 ( L_7 ) ;
F_15 ( V_15 , F_55 ( V_15 -> V_19 ) ,
V_16 , V_75 , & V_99 ) ;
if ( V_99 ) {
V_23 = F_59 ( ( V_99 & 0xffff ) , NULL ) ;
if ( V_23 && V_97 && F_33 ( V_97 ) ) {
F_58 ( L_8 ,
F_60 ( V_23 ) ) ;
V_97 -> V_50 -> V_57 [ V_98 ] = V_23 ;
}
}
return 0 ;
}
F_18 ( V_15 , F_55 ( V_15 -> V_19 ) ,
V_16 ,
V_25 , V_15 -> V_26 ) ;
while ( ( V_100 = F_54 ( V_15 , V_16 ) )
< V_15 -> V_26 ) {
F_61 ( 1 ) ;
F_18 ( V_15 , F_55 ( V_15 -> V_19 ) ,
V_16 ,
V_25 ,
V_15 -> V_26 ) ;
}
if ( F_54 ( V_15 , V_16 ) > V_15 -> V_26 ) {
F_58 (
L_9 ) ;
return - 1 ;
}
V_23 = F_34 ( V_2 , V_15 , F_55 ( V_15 -> V_19 ) ,
V_16 , 1 ) ;
if ( V_23 ) {
V_23 -> V_97 = V_97 ;
if ( V_97 && F_33 ( V_97 ) )
V_97 -> V_50 -> V_57 [ V_98 ] = V_23 ;
} else
return - 1 ;
if ( F_33 ( V_23 ) ) {
int V_101 ;
int V_102 ;
int V_103 ;
T_1 V_3 ;
int V_104 ;
V_103 = F_62 ( V_23 -> V_53 ) ;
F_63 ( V_23 , V_83 ,
V_15 -> V_26 , V_103 , 0 ) ;
V_23 -> V_50 -> V_79 [ V_15 -> V_26 ] = V_103 ;
V_3 = F_10 ( V_2 ) ;
while ( V_3 != V_11 && V_3 < V_77 ) {
if ( V_3 != V_15 -> V_26 ) {
F_63 ( V_23 , V_83 ,
V_3 , V_103 , 0 ) ;
V_23 -> V_50 -> V_79 [ V_3 ] = V_103 ;
}
V_3 = F_12 ( V_2 , V_3 + 1 ) ;
}
F_58 (
L_10 ,
F_60 ( V_23 ) , V_23 -> V_29 , V_23 -> V_20 ,
F_35 ( V_23 -> V_53 ) ) ;
V_101 = V_77 ;
for ( V_104 = 0 ;
V_104 < F_35 ( V_23 -> V_53 ) ;
V_104 ++ ) {
if ( V_103 == V_104 ) {
F_44 ( V_15 , 0 ,
F_55 ( V_15 -> V_19 ) ,
V_16 , V_104 ) ;
V_23 -> V_50 -> V_78 |= ( 1 << V_104 ) ;
continue;
}
V_102 = V_77 ;
if ( F_50
( V_15 , F_55 ( V_15 -> V_19 ) , V_16 ,
V_104 ) ) {
F_58 (
L_11 ,
V_104 ) ;
F_44 ( V_15 , 0 ,
F_55 ( V_15 -> V_19 ) ,
V_16 , V_104 ) ;
V_23 -> V_50 -> V_78 |= ( 1 << V_104 ) ;
F_63 ( V_23 , V_83 ,
F_55 ( V_15 -> V_19 ) ,
V_104 , 0 ) ;
if ( F_56 ( V_2 , V_15 , V_16 + 1 ,
V_23 , V_104 ) < 0 )
return - 1 ;
V_3 = F_12 ( V_2 , V_102 + 1 ) ;
if ( V_3 != V_11 ) {
for ( V_3 = V_102 ;
V_3 < V_77 ; ) {
if ( V_3 != V_15 -> V_26 ) {
F_63 ( V_23 ,
V_83 ,
V_3 ,
V_104 ,
0 ) ;
V_23 -> V_50 ->
V_79 [ V_3 ] =
V_104 ;
}
V_3 = F_12 ( V_2 ,
V_3 + 1 ) ;
}
}
} else {
if ( V_23 -> V_69 )
F_64 ( V_23 , V_104 , 1 ) ;
V_23 -> V_50 -> V_78 &= ~ ( 1 << V_104 ) ;
}
}
if ( ( V_23 -> V_34 & V_105 ) &&
( V_23 -> V_69 ) ) {
F_25 ( V_23 ,
V_23 -> V_69 + V_106 ,
( V_15 -> V_26 << 16 ) |
( V_15 -> V_19 << 15 ) ) ;
}
F_65 ( V_23 ) ;
if ( V_77 == V_101 )
V_77 = F_1 ( V_2 ) ;
V_23 -> V_3 = V_101 ;
} else
F_58 ( L_12 ,
F_60 ( V_23 ) , V_23 -> V_29 , V_23 -> V_20 ) ;
return 0 ;
}
static int F_66 ( struct V_14 * V_15 )
{
T_3 V_99 ;
F_22 ( V_15 , V_15 -> V_30 + V_31 ,
& V_99 ) ;
return ( V_99 & V_32 ) ? 1 : 0 ;
}
static int
F_67 ( struct V_1 * V_2 , struct V_14 * V_15 , T_1 V_3 ,
T_2 V_16 , struct V_22 * V_97 , int V_98 )
{
T_2 V_104 , V_107 ;
struct V_22 * V_23 ;
T_1 V_108 ;
if ( ( V_23 = F_34 ( V_2 , V_15 , V_3 , V_16 , 0 ) ) ) {
V_23 -> V_97 = V_97 ;
if ( V_97 && F_33 ( V_97 ) )
V_97 -> V_50 -> V_57 [ V_98 ] = V_23 ;
} else
return - 1 ;
if ( F_33 ( V_23 ) ) {
V_23 -> V_3 = V_3 ;
F_58 (
L_10 ,
F_60 ( V_23 ) , V_23 -> V_29 , V_23 -> V_20 ,
F_35 ( V_23 -> V_53 ) ) ;
for ( V_104 = 0 ;
V_104 < F_35 ( V_23 -> V_53 ) ;
V_104 ++ ) {
if ( F_62 ( V_23 -> V_53 ) == V_104 )
continue;
if ( F_50
( V_15 , V_3 , V_16 , V_104 ) ) {
F_58 (
L_11 ,
V_104 ) ;
F_68 ( V_15 , V_3 , V_16 , 1000 ) ;
for ( V_108 = 0 ;
V_108 < F_55 ( V_15 -> V_19 ) ;
V_108 ++ ) {
F_69 ( V_23 ,
V_83 ,
V_108 ,
& V_107 , 0 ) ;
if ( V_107 == V_104 )
break;
}
if ( V_108 == F_55 ( V_15 -> V_19 ) )
continue;
F_70 ( V_15 , V_3 , V_16 ) ;
if ( F_67 ( V_2 , V_15 , V_108 ,
V_16 + 1 , V_23 , V_104 ) < 0 )
return - 1 ;
}
}
} else
F_58 ( L_12 ,
F_60 ( V_23 ) , V_23 -> V_29 , V_23 -> V_20 ) ;
return 0 ;
}
static int F_71 ( struct V_14 * V_15 )
{
T_3 V_17 = 0 ;
T_3 V_92 ;
int * V_109 = V_110 ;
do {
if ( ( V_92 =
F_38 ( V_15 , 1 , 0 , 0 , * V_109 ) ) )
break;
} while ( * ++ V_109 >= 0 );
if ( V_92 )
F_22 ( V_15 ,
V_92 +
F_53 ( V_15 -> V_111 ) ,
& V_17 ) ;
return V_17 & V_96 ;
}
static void F_72 ( struct V_1 * V_2 )
{
F_58 ( L_13 , V_112 , V_2 -> V_81 ) ;
F_32 ( V_2 -> V_6 ) ;
}
static void F_73 ( struct V_44 * V_45 )
{
struct V_1 * V_2 ;
V_2 = F_74 ( V_45 ) ;
F_58 ( L_13 , V_112 , V_2 -> V_81 ) ;
F_32 ( V_2 ) ;
}
static struct V_1 * F_75 ( struct V_14 * V_113 ,
int V_48 , T_1 V_10 )
{
struct V_1 * V_2 ;
V_2 = F_76 ( V_113 ) ;
if ( V_2 && V_48 ) {
struct V_4 * V_5 ;
T_4 V_52 ;
V_52 = sizeof( struct V_4 ) +
F_77 (
F_41 ( V_113 -> V_19 )
) * sizeof( long ) ;
V_5 = F_36 ( V_52 , V_58 ) ;
if ( V_5 == NULL ) {
F_39 ( L_14 ) ;
F_78 ( V_2 ) ;
V_2 = NULL ;
} else {
V_2 -> V_6 = V_5 ;
V_2 -> V_85 = F_72 ;
V_5 -> V_10 = V_10 ;
V_5 -> V_9 = F_41 ( V_113 -> V_19 ) ;
F_40 ( & V_5 -> V_7 ) ;
}
}
if ( V_2 ) {
V_2 -> V_81 = V_113 -> V_81 ;
V_2 -> V_21 = V_113 ;
F_42 ( & V_2 -> V_45 , L_15 , V_2 -> V_81 ) ;
V_2 -> V_45 . V_84 = & V_113 -> V_45 ;
V_2 -> V_45 . V_85 = F_73 ;
F_79 ( V_2 ) ;
}
return V_2 ;
}
static void F_80 ( struct V_1 * V_2 )
{
struct V_22 * V_23 , * V_114 ;
struct V_49 * V_50 ;
T_2 V_91 ;
T_1 V_3 ;
F_24 (rdev, &net->devices, net_list) {
V_3 = V_23 -> V_3 ;
F_24 (rswitch, &net->switches, node) {
if ( F_33 ( V_23 ) && ( V_23 -> V_50 == V_50 ) )
continue;
if ( V_80 == V_50 -> V_79 [ V_3 ] ) {
V_114 = F_81 ( V_50 ) ;
if ( V_114 -> V_3 == V_3 )
continue;
V_91 = F_62 ( V_114 -> V_53 ) ;
F_63 ( V_114 , V_83 ,
V_3 , V_91 , 0 ) ;
V_50 -> V_79 [ V_3 ] = V_91 ;
}
}
}
}
static void F_65 ( struct V_22 * V_23 )
{
if ( F_33 ( V_23 ) && ( V_23 -> V_69 ) &&
V_23 -> V_50 -> V_115 && V_23 -> V_50 -> V_115 -> V_116 ) {
V_23 -> V_50 -> V_115 -> V_116 ( V_23 ) ;
}
}
static int F_82 ( struct V_14 * V_113 , T_3 V_117 )
{
struct V_1 * V_2 = NULL ;
int V_118 = 0 ;
F_23 ( V_27 L_16 , V_113 -> V_81 ,
V_113 -> V_119 ) ;
if ( V_113 -> V_120 . V_121 || V_113 -> V_120 . V_97 )
return - V_122 ;
if ( F_27 ( V_113 ) < 0 ) {
F_23 ( V_27
L_17 ,
V_113 -> V_81 ) ;
V_118 = - V_122 ;
goto V_123;
}
if ( F_71 ( V_113 ) ) {
V_2 = F_75 ( V_113 , 1 , 0 ) ;
if ( ! V_2 ) {
F_23 ( V_124 L_18 ) ;
V_118 = - V_125 ;
goto V_123;
}
F_6 ( V_2 , V_113 -> V_26 ) ;
F_44 ( V_113 , 1 , 0 , 0 , 0 ) ;
F_21 ( V_113 , V_75 ,
V_73 ++ ) ;
V_77 = F_1 ( V_2 ) ;
if ( F_56 ( V_2 , V_113 , 0 , NULL , 0 ) < 0 ) {
F_23 ( V_27
L_19 ,
V_113 -> V_81 ) ;
F_20 ( V_2 ) ;
V_118 = - V_122 ;
goto V_123;
}
F_8 ( V_2 , V_77 ) ;
F_80 ( V_2 ) ;
F_20 ( V_2 ) ;
F_83 ( V_113 , 1 ) ;
} else {
F_23 ( V_27 L_20 ,
V_113 -> V_81 ) ;
V_118 = - V_28 ;
}
V_123:
return V_118 ;
}
static void F_84 ( struct V_1 * V_2 )
{
struct V_49 * V_50 ;
struct V_22 * V_23 ;
int V_126 ;
T_2 V_91 ;
F_24 (rswitch, &net->switches, node) {
V_23 = F_81 ( V_50 ) ;
F_68 ( V_2 -> V_21 , V_23 -> V_3 ,
V_23 -> V_16 , 1000 ) ;
for ( V_126 = 0 ;
V_126 < F_41 ( V_2 -> V_21 -> V_19 ) ;
V_126 ++ ) {
if ( F_69 ( V_23 , V_83 ,
V_126 , & V_91 , 0 ) < 0 )
continue;
V_50 -> V_79 [ V_126 ] = V_91 ;
}
F_70 ( V_2 -> V_21 , V_23 -> V_3 , V_23 -> V_16 ) ;
}
}
static int F_85 ( struct V_14 * V_113 , T_3 V_117 )
{
struct V_1 * V_2 = NULL ;
unsigned long V_127 ;
F_23 ( V_27 L_21 , V_113 -> V_81 ,
V_113 -> V_119 ) ;
if ( F_71 ( V_113 ) ) {
if ( F_66 ( V_113 ) )
goto V_128;
else if ( V_117 & V_129 )
return - V_130 ;
F_58 ( L_22 ) ;
V_127 = V_131 + V_132 * V_133 ;
while ( F_86 ( V_131 , V_127 ) ) {
if ( F_66 ( V_113 ) )
goto V_128;
F_87 ( 10 ) ;
}
F_58 ( L_23 ,
V_113 -> V_81 , V_113 -> V_119 ) ;
goto V_134;
V_128:
F_58 ( L_24 ) ;
V_2 = F_75 ( V_113 , 0 , 0 ) ;
if ( ! V_2 ) {
F_23 ( V_124 L_25 ) ;
goto V_134;
}
F_22 ( V_113 , V_18 ,
& V_113 -> V_26 ) ;
V_113 -> V_26 = F_16 ( V_113 -> V_19 ,
V_113 -> V_26 ) ;
if ( F_67 ( V_2 , V_113 , F_55 ( V_113 -> V_19 ) ,
0 , NULL , 0 ) < 0 ) {
F_23 ( V_27
L_26 ,
V_113 -> V_81 ) ;
goto V_134;
}
F_84 ( V_2 ) ;
}
return 0 ;
V_134:
return - V_122 ;
}
static int T_5 F_88 ( void )
{
if ( F_89 ( V_135 , & V_136 ) )
return - V_137 ;
if ( V_138 )
F_90 () ;
return 0 ;
}
