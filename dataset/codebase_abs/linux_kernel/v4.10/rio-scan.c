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
V_16 , & V_23 -> V_69 ) ;
F_38 ( L_3 ,
V_70 , V_23 -> V_69 ) ;
V_23 -> V_71 = F_39 ( V_15 , 0 , V_3 ,
V_16 , V_72 ) ;
if ( ! V_23 -> V_71 )
V_23 -> V_71 = F_39 ( V_15 , 0 , V_3 ,
V_16 , V_73 ) ;
}
F_15 ( V_15 , V_3 , V_16 , V_74 ,
& V_23 -> V_34 ) ;
F_15 ( V_15 , V_3 , V_16 , V_75 ,
& V_23 -> V_35 ) ;
if ( V_48 ) {
if ( V_76 >= 0x10000 ) {
F_40 ( L_4 ) ;
goto V_77;
}
F_18 ( V_15 , V_3 , V_16 ,
V_78 , V_76 ) ;
V_23 -> V_79 = V_76 ++ ;
V_23 -> V_48 = true ;
} else {
F_15 ( V_15 , V_3 , V_16 ,
V_78 ,
& V_23 -> V_79 ) ;
}
if ( F_29 ( V_15 , V_23 -> V_34 , V_23 -> V_35 ) ) {
if ( V_48 ) {
F_17 ( V_15 , V_3 , V_16 , V_80 ) ;
V_23 -> V_3 = V_80 ;
V_80 = F_1 ( V_2 ) ;
} else
V_23 -> V_3 = F_14 ( V_15 , V_3 , V_16 ) ;
V_23 -> V_16 = 0xff ;
} else {
V_23 -> V_3 = V_3 ;
V_23 -> V_16 = V_16 ;
}
if ( F_33 ( V_23 ) ) {
V_50 = V_23 -> V_50 ;
V_50 -> V_81 = 0 ;
F_41 ( & V_50 -> V_7 ) ;
V_50 -> V_82 = F_36 ( sizeof( T_2 ) *
F_42 ( V_15 -> V_19 ) ,
V_58 ) ;
if ( ! V_50 -> V_82 )
goto V_77;
for ( V_51 = 0 ; V_51 < F_42 ( V_15 -> V_19 ) ;
V_51 ++ )
V_50 -> V_82 [ V_51 ] = V_83 ;
F_43 ( & V_23 -> V_45 , L_5 , V_23 -> V_2 -> V_84 ,
V_23 -> V_79 & V_85 ) ;
if ( V_48 )
F_44 ( V_23 , V_86 , 0 ) ;
} else {
if ( V_48 )
F_45 ( V_15 , 0 , V_3 , V_16 , 0 ) ;
F_43 ( & V_23 -> V_45 , L_6 , V_23 -> V_2 -> V_84 ,
V_23 -> V_79 & V_85 ) ;
}
V_23 -> V_45 . V_87 = & V_2 -> V_45 ;
F_46 ( V_23 ) ;
V_23 -> V_45 . V_88 = F_30 ;
V_23 -> V_89 = F_47 ( 32 ) ;
V_23 -> V_45 . V_89 = & V_23 -> V_89 ;
V_23 -> V_45 . V_90 = F_47 ( 32 ) ;
if ( V_23 -> V_35 & V_91 )
F_48 ( & V_23 -> V_92 [ V_93 ] ,
0 , 0xffff ) ;
V_24 = F_49 ( V_23 ) ;
if ( V_24 )
goto V_77;
F_50 ( V_23 ) ;
return V_23 ;
V_77:
if ( V_50 )
F_32 ( V_50 -> V_82 ) ;
F_32 ( V_23 ) ;
return NULL ;
}
static int
F_51 ( struct V_22 * V_23 , int V_94 )
{
T_3 V_17 = 0 ;
F_26 ( V_23 , F_52 ( V_23 , V_94 ) ,
& V_17 ) ;
return V_17 & V_95 ;
}
static T_1 F_53 ( struct V_14 * V_15 , T_2 V_16 )
{
T_3 V_17 ;
F_15 ( V_15 , F_54 ( V_15 -> V_19 ) , V_16 ,
V_25 , & V_17 ) ;
return ( T_1 ) ( V_17 & 0xffff ) ;
}
static int F_55 ( struct V_1 * V_2 , struct V_14 * V_15 ,
T_2 V_16 , struct V_22 * V_96 , int V_97 )
{
struct V_22 * V_23 ;
T_3 V_98 ;
int V_99 ;
if ( F_56 ( V_15 ,
F_54 ( V_15 -> V_19 ) , V_16 ) ) {
F_38 ( L_7 ) ;
return - 1 ;
}
if ( F_53 ( V_15 , V_16 ) == V_15 -> V_26 ) {
F_38 ( L_8 ) ;
F_15 ( V_15 , F_54 ( V_15 -> V_19 ) ,
V_16 , V_78 , & V_98 ) ;
if ( V_98 ) {
V_23 = F_57 ( ( V_98 & 0xffff ) , NULL ) ;
if ( V_23 && V_96 && F_33 ( V_96 ) ) {
F_38 ( L_9 ,
F_58 ( V_23 ) ) ;
V_96 -> V_50 -> V_57 [ V_97 ] = V_23 ;
}
}
return 0 ;
}
F_18 ( V_15 , F_54 ( V_15 -> V_19 ) ,
V_16 ,
V_25 , V_15 -> V_26 ) ;
while ( ( V_99 = F_53 ( V_15 , V_16 ) )
< V_15 -> V_26 ) {
F_59 ( 1 ) ;
F_18 ( V_15 , F_54 ( V_15 -> V_19 ) ,
V_16 ,
V_25 ,
V_15 -> V_26 ) ;
}
if ( F_53 ( V_15 , V_16 ) > V_15 -> V_26 ) {
F_38 (
L_10 ) ;
return - 1 ;
}
V_23 = F_34 ( V_2 , V_15 , F_54 ( V_15 -> V_19 ) ,
V_16 , 1 ) ;
if ( V_23 ) {
V_23 -> V_96 = V_96 ;
if ( V_96 && F_33 ( V_96 ) )
V_96 -> V_50 -> V_57 [ V_97 ] = V_23 ;
} else
return - 1 ;
if ( F_33 ( V_23 ) ) {
int V_100 ;
int V_101 ;
int V_102 ;
T_1 V_3 ;
int V_103 ;
V_102 = F_60 ( V_23 -> V_53 ) ;
F_61 ( V_23 , V_86 ,
V_15 -> V_26 , V_102 , 0 ) ;
V_23 -> V_50 -> V_82 [ V_15 -> V_26 ] = V_102 ;
V_3 = F_10 ( V_2 ) ;
while ( V_3 != V_11 && V_3 < V_80 ) {
if ( V_3 != V_15 -> V_26 ) {
F_61 ( V_23 , V_86 ,
V_3 , V_102 , 0 ) ;
V_23 -> V_50 -> V_82 [ V_3 ] = V_102 ;
}
V_3 = F_12 ( V_2 , V_3 + 1 ) ;
}
F_38 (
L_11 ,
F_58 ( V_23 ) , V_23 -> V_29 , V_23 -> V_20 ,
F_35 ( V_23 -> V_53 ) ) ;
V_100 = V_80 ;
for ( V_103 = 0 ;
V_103 < F_35 ( V_23 -> V_53 ) ;
V_103 ++ ) {
if ( V_102 == V_103 ) {
F_45 ( V_15 , 0 ,
F_54 ( V_15 -> V_19 ) ,
V_16 , V_103 ) ;
V_23 -> V_50 -> V_81 |= ( 1 << V_103 ) ;
continue;
}
V_101 = V_80 ;
if ( F_51 ( V_23 , V_103 ) ) {
F_38 (
L_12 ,
V_103 ) ;
F_45 ( V_15 , 0 ,
F_54 ( V_15 -> V_19 ) ,
V_16 , V_103 ) ;
V_23 -> V_50 -> V_81 |= ( 1 << V_103 ) ;
F_61 ( V_23 , V_86 ,
F_54 ( V_15 -> V_19 ) ,
V_103 , 0 ) ;
if ( F_55 ( V_2 , V_15 , V_16 + 1 ,
V_23 , V_103 ) < 0 )
return - 1 ;
V_3 = F_12 ( V_2 , V_101 + 1 ) ;
if ( V_3 != V_11 ) {
for ( V_3 = V_101 ;
V_3 < V_80 ; ) {
if ( V_3 != V_15 -> V_26 ) {
F_61 ( V_23 ,
V_86 ,
V_3 ,
V_103 ,
0 ) ;
V_23 -> V_50 ->
V_82 [ V_3 ] =
V_103 ;
}
V_3 = F_12 ( V_2 ,
V_3 + 1 ) ;
}
}
} else {
if ( V_23 -> V_71 )
F_62 ( V_23 , V_103 , 1 ) ;
V_23 -> V_50 -> V_81 &= ~ ( 1 << V_103 ) ;
}
}
if ( ( V_23 -> V_34 & V_104 ) &&
( V_23 -> V_71 ) ) {
F_25 ( V_23 ,
V_23 -> V_71 + V_105 ,
( V_15 -> V_26 << 16 ) |
( V_15 -> V_19 << 15 ) ) ;
}
F_63 ( V_23 ) ;
if ( V_80 == V_100 )
V_80 = F_1 ( V_2 ) ;
V_23 -> V_3 = V_100 ;
} else
F_38 ( L_13 ,
F_58 ( V_23 ) , V_23 -> V_29 , V_23 -> V_20 ) ;
return 0 ;
}
static int F_64 ( struct V_14 * V_15 )
{
T_3 V_98 ;
F_22 ( V_15 , V_15 -> V_30 + V_31 ,
& V_98 ) ;
return ( V_98 & V_32 ) ? 1 : 0 ;
}
static int
F_65 ( struct V_1 * V_2 , struct V_14 * V_15 , T_1 V_3 ,
T_2 V_16 , struct V_22 * V_96 , int V_97 )
{
T_2 V_103 , V_106 ;
struct V_22 * V_23 ;
T_1 V_107 ;
if ( ( V_23 = F_34 ( V_2 , V_15 , V_3 , V_16 , 0 ) ) ) {
V_23 -> V_96 = V_96 ;
if ( V_96 && F_33 ( V_96 ) )
V_96 -> V_50 -> V_57 [ V_97 ] = V_23 ;
} else
return - 1 ;
if ( F_33 ( V_23 ) ) {
V_23 -> V_3 = V_3 ;
F_38 (
L_11 ,
F_58 ( V_23 ) , V_23 -> V_29 , V_23 -> V_20 ,
F_35 ( V_23 -> V_53 ) ) ;
for ( V_103 = 0 ;
V_103 < F_35 ( V_23 -> V_53 ) ;
V_103 ++ ) {
if ( F_60 ( V_23 -> V_53 ) == V_103 )
continue;
if ( F_51 ( V_23 , V_103 ) ) {
F_38 (
L_12 ,
V_103 ) ;
F_66 ( V_15 , V_3 , V_16 , 1000 ) ;
for ( V_107 = 0 ;
V_107 < F_54 ( V_15 -> V_19 ) ;
V_107 ++ ) {
F_67 ( V_23 ,
V_86 ,
V_107 ,
& V_106 , 0 ) ;
if ( V_106 == V_103 )
break;
}
if ( V_107 == F_54 ( V_15 -> V_19 ) )
continue;
F_68 ( V_15 , V_3 , V_16 ) ;
if ( F_65 ( V_2 , V_15 , V_107 ,
V_16 + 1 , V_23 , V_103 ) < 0 )
return - 1 ;
}
}
} else
F_38 ( L_13 ,
F_58 ( V_23 ) , V_23 -> V_29 , V_23 -> V_20 ) ;
return 0 ;
}
static int F_69 ( struct V_14 * V_15 )
{
T_3 V_17 = 0 ;
F_22 ( V_15 ,
V_15 -> V_30 +
F_70 ( V_15 -> V_108 , V_15 -> V_69 ) ,
& V_17 ) ;
return V_17 & V_95 ;
}
static void F_71 ( struct V_1 * V_2 )
{
F_38 ( L_14 , V_70 , V_2 -> V_84 ) ;
F_32 ( V_2 -> V_6 ) ;
}
static void F_72 ( struct V_44 * V_45 )
{
struct V_1 * V_2 ;
V_2 = F_73 ( V_45 ) ;
F_38 ( L_14 , V_70 , V_2 -> V_84 ) ;
F_32 ( V_2 ) ;
}
static struct V_1 * F_74 ( struct V_14 * V_109 ,
int V_48 , T_1 V_10 )
{
struct V_1 * V_2 ;
V_2 = F_75 ( V_109 ) ;
if ( V_2 && V_48 ) {
struct V_4 * V_5 ;
T_4 V_52 ;
V_52 = sizeof( struct V_4 ) +
F_76 (
F_42 ( V_109 -> V_19 )
) * sizeof( long ) ;
V_5 = F_36 ( V_52 , V_58 ) ;
if ( V_5 == NULL ) {
F_40 ( L_15 ) ;
F_77 ( V_2 ) ;
V_2 = NULL ;
} else {
V_2 -> V_6 = V_5 ;
V_2 -> V_88 = F_71 ;
V_5 -> V_10 = V_10 ;
V_5 -> V_9 = F_42 ( V_109 -> V_19 ) ;
F_41 ( & V_5 -> V_7 ) ;
}
}
if ( V_2 ) {
V_2 -> V_84 = V_109 -> V_84 ;
V_2 -> V_21 = V_109 ;
F_43 ( & V_2 -> V_45 , L_16 , V_2 -> V_84 ) ;
V_2 -> V_45 . V_87 = & V_109 -> V_45 ;
V_2 -> V_45 . V_88 = F_72 ;
F_78 ( V_2 ) ;
}
return V_2 ;
}
static void F_79 ( struct V_1 * V_2 )
{
struct V_22 * V_23 , * V_110 ;
struct V_49 * V_50 ;
T_2 V_111 ;
T_1 V_3 ;
F_24 (rdev, &net->devices, net_list) {
V_3 = V_23 -> V_3 ;
F_24 (rswitch, &net->switches, node) {
if ( F_33 ( V_23 ) && ( V_23 -> V_50 == V_50 ) )
continue;
if ( V_83 == V_50 -> V_82 [ V_3 ] ) {
V_110 = F_80 ( V_50 ) ;
if ( V_110 -> V_3 == V_3 )
continue;
V_111 = F_60 ( V_110 -> V_53 ) ;
F_61 ( V_110 , V_86 ,
V_3 , V_111 , 0 ) ;
V_50 -> V_82 [ V_3 ] = V_111 ;
}
}
}
}
static void F_63 ( struct V_22 * V_23 )
{
if ( F_33 ( V_23 ) && ( V_23 -> V_71 ) &&
V_23 -> V_50 -> V_112 && V_23 -> V_50 -> V_112 -> V_113 ) {
V_23 -> V_50 -> V_112 -> V_113 ( V_23 ) ;
}
}
static int F_81 ( struct V_14 * V_109 , T_3 V_114 )
{
struct V_1 * V_2 = NULL ;
int V_115 = 0 ;
F_23 ( V_27 L_17 , V_109 -> V_84 ,
V_109 -> V_116 ) ;
if ( V_109 -> V_117 . V_118 || V_109 -> V_117 . V_96 )
return - V_119 ;
if ( F_27 ( V_109 ) < 0 ) {
F_23 ( V_27
L_18 ,
V_109 -> V_84 ) ;
V_115 = - V_119 ;
goto V_120;
}
if ( F_69 ( V_109 ) ) {
V_2 = F_74 ( V_109 , 1 , 0 ) ;
if ( ! V_2 ) {
F_23 ( V_121 L_19 ) ;
V_115 = - V_122 ;
goto V_120;
}
F_6 ( V_2 , V_109 -> V_26 ) ;
F_45 ( V_109 , 1 , 0 , 0 , 0 ) ;
F_21 ( V_109 , V_78 ,
V_76 ++ ) ;
V_80 = F_1 ( V_2 ) ;
if ( F_55 ( V_2 , V_109 , 0 , NULL , 0 ) < 0 ) {
F_23 ( V_27
L_20 ,
V_109 -> V_84 ) ;
F_20 ( V_2 ) ;
V_115 = - V_119 ;
goto V_120;
}
F_8 ( V_2 , V_80 ) ;
F_79 ( V_2 ) ;
F_20 ( V_2 ) ;
F_82 ( V_109 , 1 ) ;
} else {
F_23 ( V_27 L_21 ,
V_109 -> V_84 ) ;
V_115 = - V_28 ;
}
V_120:
return V_115 ;
}
static void F_83 ( struct V_1 * V_2 )
{
struct V_49 * V_50 ;
struct V_22 * V_23 ;
int V_123 ;
T_2 V_111 ;
F_24 (rswitch, &net->switches, node) {
V_23 = F_80 ( V_50 ) ;
F_66 ( V_2 -> V_21 , V_23 -> V_3 ,
V_23 -> V_16 , 1000 ) ;
for ( V_123 = 0 ;
V_123 < F_42 ( V_2 -> V_21 -> V_19 ) ;
V_123 ++ ) {
if ( F_67 ( V_23 , V_86 ,
V_123 , & V_111 , 0 ) < 0 )
continue;
V_50 -> V_82 [ V_123 ] = V_111 ;
}
F_68 ( V_2 -> V_21 , V_23 -> V_3 , V_23 -> V_16 ) ;
}
}
static int F_84 ( struct V_14 * V_109 , T_3 V_114 )
{
struct V_1 * V_2 = NULL ;
unsigned long V_124 ;
F_23 ( V_27 L_22 , V_109 -> V_84 ,
V_109 -> V_116 ) ;
if ( F_69 ( V_109 ) ) {
if ( F_64 ( V_109 ) )
goto V_125;
else if ( V_114 & V_126 )
return - V_127 ;
F_38 ( L_23 ) ;
V_124 = V_128 + V_129 * V_130 ;
while ( F_85 ( V_128 , V_124 ) ) {
if ( F_64 ( V_109 ) )
goto V_125;
F_86 ( 10 ) ;
}
F_38 ( L_24 ,
V_109 -> V_84 , V_109 -> V_116 ) ;
goto V_131;
V_125:
F_38 ( L_25 ) ;
V_2 = F_74 ( V_109 , 0 , 0 ) ;
if ( ! V_2 ) {
F_23 ( V_121 L_26 ) ;
goto V_131;
}
F_22 ( V_109 , V_18 ,
& V_109 -> V_26 ) ;
V_109 -> V_26 = F_16 ( V_109 -> V_19 ,
V_109 -> V_26 ) ;
if ( F_65 ( V_2 , V_109 , F_54 ( V_109 -> V_19 ) ,
0 , NULL , 0 ) < 0 ) {
F_23 ( V_27
L_27 ,
V_109 -> V_84 ) ;
goto V_131;
}
F_83 ( V_2 ) ;
}
return 0 ;
V_131:
return - V_119 ;
}
static int T_5 F_87 ( void )
{
if ( F_88 ( V_132 , & V_133 ) )
return - V_134 ;
if ( V_135 )
F_89 () ;
return 0 ;
}
