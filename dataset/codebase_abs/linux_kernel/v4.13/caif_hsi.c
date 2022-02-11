static void F_1 ( unsigned long V_1 )
{
struct V_2 * V_2 = (struct V_2 * ) V_1 ;
F_2 ( V_2 -> V_3 , L_1 ,
V_4 ) ;
if ( ! F_3 ( V_5 , & V_2 -> V_6 ) )
F_4 ( V_2 -> V_7 , & V_2 -> V_8 ) ;
}
static void F_5 ( struct V_2 * V_2 ,
const struct V_9 * V_10 ,
int V_11 )
{
struct V_12 * V_13 ;
int V_14 , V_15 , V_16 ;
V_13 = (struct V_12 * ) & V_10 -> V_17 ;
V_14 = 1 + F_6 ( ( V_13 -> V_18 + 1 ) , V_2 -> V_19 . V_20 ) ;
V_15 = F_6 ( ( V_10 -> V_16 + V_14 ) , V_2 -> V_19 . V_21 ) ;
V_16 = V_10 -> V_16 + V_14 + V_15 ;
if ( V_11 > 0 )
V_2 -> V_22 += V_16 ;
else if ( V_11 < 0 )
V_2 -> V_22 -= V_16 ;
}
static bool F_7 ( struct V_2 * V_2 )
{
int V_23 ;
if ( V_2 -> V_19 . V_24 == 0 )
return true ;
for ( V_23 = 0 ; V_23 < V_25 ; ++ V_23 ) {
if ( V_2 -> V_26 [ V_23 ] . V_27 )
return true ;
}
if ( V_2 -> V_26 [ V_25 ] . V_27 >= V_28 )
return true ;
return false ;
}
static struct V_9 * F_8 ( struct V_2 * V_2 )
{
struct V_9 * V_10 ;
int V_23 ;
for ( V_23 = 0 ; V_23 < V_29 ; ++ V_23 ) {
V_10 = F_9 ( & V_2 -> V_26 [ V_23 ] ) ;
if ( V_10 )
break;
}
return V_10 ;
}
static int F_10 ( struct V_2 * V_2 )
{
int V_23 , V_16 = 0 ;
for ( V_23 = 0 ; V_23 < V_29 ; ++ V_23 )
V_16 += F_11 ( & V_2 -> V_26 [ V_23 ] ) ;
return V_16 ;
}
static void F_12 ( struct V_2 * V_2 )
{
struct V_9 * V_10 ;
for (; ; ) {
F_13 ( & V_2 -> V_30 ) ;
V_10 = F_8 ( V_2 ) ;
if ( ! V_10 )
break;
V_2 -> V_3 -> V_31 . V_32 ++ ;
V_2 -> V_3 -> V_31 . V_33 ++ ;
F_5 ( V_2 , V_10 , - 1 ) ;
F_14 ( & V_2 -> V_30 ) ;
F_15 ( V_10 ) ;
}
V_2 -> V_34 = V_35 ;
if ( ! F_3 ( V_5 , & V_2 -> V_6 ) )
F_16 ( & V_2 -> V_36 ,
V_37 + V_2 -> V_19 . V_38 ) ;
F_14 ( & V_2 -> V_30 ) ;
}
static int F_17 ( struct V_2 * V_2 )
{
char V_39 [ 32 ] ;
T_1 V_40 ;
int V_41 ;
F_2 ( V_2 -> V_3 , L_1 ,
V_4 ) ;
do {
V_41 = V_2 -> V_42 -> V_43 ( V_2 -> V_42 ,
& V_40 ) ;
if ( V_41 ) {
F_18 ( V_2 -> V_3 ,
L_2 ,
V_4 , V_41 ) ;
break;
} else if ( ! V_40 )
break;
V_40 = F_19 ( sizeof( V_39 ) , V_40 ) ;
F_20 ( V_44 , & V_2 -> V_6 ) ;
V_41 = V_2 -> V_42 -> V_45 ( V_39 , V_40 ,
V_2 -> V_42 ) ;
if ( V_41 ) {
F_21 ( V_44 , & V_2 -> V_6 ) ;
F_18 ( V_2 -> V_3 ,
L_3 ,
V_4 , V_41 ) ;
break;
}
V_41 = 5 * V_46 ;
V_41 = F_22 ( V_2 -> V_47 ,
! F_3 ( V_44 , & V_2 -> V_6 ) , V_41 ) ;
if ( V_41 < 0 ) {
F_18 ( V_2 -> V_3 ,
L_4 ,
V_4 , V_41 ) ;
break;
} else if ( ! V_41 ) {
V_41 = - V_48 ;
F_18 ( V_2 -> V_3 ,
L_5 ,
V_4 ) ;
break;
}
} while ( 1 );
return V_41 ;
}
static int F_23 ( struct V_49 * V_50 , struct V_2 * V_2 )
{
int V_51 = 0 ;
int V_52 = 0 ;
struct V_9 * V_10 ;
T_2 * V_53 = V_50 -> V_54 + V_55 ;
V_10 = F_8 ( V_2 ) ;
if ( ! V_10 )
return 0 ;
V_50 -> V_56 = 0 ;
if ( V_10 -> V_16 < V_55 ) {
struct V_12 * V_13 ;
int V_14 ;
int V_15 ;
V_13 = (struct V_12 * ) & V_10 -> V_17 ;
V_14 = 1 + F_6 ( ( V_13 -> V_18 + 1 ) , V_2 -> V_19 . V_20 ) ;
V_15 = F_6 ( ( V_10 -> V_16 + V_14 ) , V_2 -> V_19 . V_21 ) ;
if ( ( V_10 -> V_16 + V_14 + V_15 ) <= V_55 ) {
T_2 * V_57 = V_50 -> V_54 ;
V_50 -> V_56 = V_58 ;
* V_57 = ( T_2 ) ( V_14 - 1 ) ;
V_57 += V_14 ;
F_13 ( & V_2 -> V_30 ) ;
V_2 -> V_3 -> V_31 . V_59 ++ ;
V_2 -> V_3 -> V_31 . V_60 += V_10 -> V_16 ;
F_5 ( V_2 , V_10 , - 1 ) ;
F_14 ( & V_2 -> V_30 ) ;
F_24 ( V_10 , 0 , V_57 , V_10 -> V_16 ) ;
F_25 ( V_10 ) ;
V_10 = NULL ;
}
}
V_53 = V_50 -> V_54 + V_55 ;
while ( V_51 < V_28 ) {
struct V_12 * V_13 ;
int V_14 ;
int V_15 ;
if ( ! V_10 )
V_10 = F_8 ( V_2 ) ;
if ( ! V_10 )
break;
V_13 = (struct V_12 * ) & V_10 -> V_17 ;
V_14 = 1 + F_6 ( ( V_13 -> V_18 + 1 ) , V_2 -> V_19 . V_20 ) ;
V_15 = F_6 ( ( V_10 -> V_16 + V_14 ) , V_2 -> V_19 . V_21 ) ;
V_50 -> V_61 [ V_51 ] = V_14 + V_10 -> V_16 + V_15 ;
* V_53 = ( T_2 ) ( V_14 - 1 ) ;
V_53 += V_14 ;
F_13 ( & V_2 -> V_30 ) ;
V_2 -> V_3 -> V_31 . V_59 ++ ;
V_2 -> V_3 -> V_31 . V_60 += V_10 -> V_16 ;
F_5 ( V_2 , V_10 , - 1 ) ;
F_14 ( & V_2 -> V_30 ) ;
F_24 ( V_10 , 0 , V_53 , V_10 -> V_16 ) ;
V_52 += V_50 -> V_61 [ V_51 ] ;
V_53 += V_10 -> V_16 + V_15 ;
F_25 ( V_10 ) ;
V_10 = NULL ;
V_51 ++ ;
}
while ( V_51 < V_28 ) {
V_50 -> V_61 [ V_51 ] = 0x0000 ;
V_51 ++ ;
}
if ( F_7 ( V_2 ) )
V_50 -> V_62 |= V_63 ;
else
V_50 -> V_62 &= ~ V_63 ;
return V_64 + V_52 ;
}
static void F_26 ( struct V_2 * V_2 )
{
struct V_49 * V_50 = (struct V_49 * ) V_2 -> V_65 ;
int V_16 , V_66 ;
F_2 ( V_2 -> V_3 , L_1 , V_4 ) ;
if ( F_3 ( V_5 , & V_2 -> V_6 ) )
return;
do {
V_16 = F_23 ( V_50 , V_2 ) ;
if ( ! V_16 ) {
F_13 ( & V_2 -> V_30 ) ;
if ( F_27 ( F_10 ( V_2 ) ) ) {
F_14 ( & V_2 -> V_30 ) ;
V_66 = - V_67 ;
continue;
}
V_2 -> V_34 = V_35 ;
F_16 ( & V_2 -> V_36 ,
V_37 + V_2 -> V_19 . V_38 ) ;
F_14 ( & V_2 -> V_30 ) ;
break;
}
V_66 = V_2 -> V_42 -> V_68 ( V_2 -> V_65 , V_16 , V_2 -> V_42 ) ;
if ( F_28 ( V_66 < 0 ) )
F_29 ( V_2 -> V_3 , L_6 ,
V_4 , V_66 ) ;
} while ( V_66 < 0 );
}
static void F_30 ( struct V_2 * V_2 )
{
F_2 ( V_2 -> V_3 , L_1 , V_4 ) ;
if ( F_3 ( V_5 , & V_2 -> V_6 ) )
return;
F_13 ( & V_2 -> V_30 ) ;
if ( V_2 -> V_69 &&
F_10 ( V_2 ) <= V_2 -> V_19 . V_70 &&
V_2 -> V_71 . V_72 ) {
V_2 -> V_69 = 0 ;
V_2 -> V_71 . V_72 ( V_2 -> V_3 , V_73 ) ;
}
if ( F_7 ( V_2 ) ) {
F_14 ( & V_2 -> V_30 ) ;
F_26 ( V_2 ) ;
} else {
F_16 ( & V_2 -> V_74 ,
V_37 + V_2 -> V_19 . V_24 ) ;
F_14 ( & V_2 -> V_30 ) ;
}
return;
}
static void F_31 ( struct V_75 * V_76 )
{
struct V_2 * V_2 ;
V_2 = F_32 ( V_76 , struct V_2 , V_76 ) ;
F_2 ( V_2 -> V_3 , L_1 ,
V_4 ) ;
if ( F_3 ( V_5 , & V_2 -> V_6 ) )
return;
F_30 ( V_2 ) ;
}
static int F_33 ( struct V_49 * V_50 , struct V_2 * V_2 )
{
int V_77 = 0 ;
int V_51 = 0 ;
T_3 * V_78 = NULL ;
T_2 * V_53 = NULL ;
if ( ( V_50 -> V_62 & ~ V_63 ) ||
( V_50 -> V_56 > V_55 ) ) {
F_29 ( V_2 -> V_3 , L_7 ,
V_4 ) ;
return - V_79 ;
}
if ( V_50 -> V_56 ) {
struct V_9 * V_10 ;
int V_16 = 0 ;
V_53 = ( ( T_2 * ) V_50 ) + V_50 -> V_56 ;
V_53 += * V_53 + 1 ;
V_16 = * V_53 ;
V_16 |= ( ( * ( V_53 + 1 ) ) << 8 ) & 0xFF00 ;
V_16 += 2 ;
if ( F_27 ( V_16 > V_80 ) ) {
F_29 ( V_2 -> V_3 , L_8 ,
V_4 ) ;
return - V_79 ;
}
V_10 = F_34 ( V_16 + 1 , V_81 ) ;
if ( ! V_10 ) {
F_29 ( V_2 -> V_3 , L_9 ,
V_4 ) ;
return - V_82 ;
}
F_35 ( V_10 != NULL ) ;
F_36 ( V_10 , V_53 , V_16 ) ;
V_10 -> V_83 = F_37 ( V_84 ) ;
F_38 ( V_10 ) ;
V_10 -> V_85 = V_2 -> V_3 ;
if ( F_39 () )
F_40 ( V_10 ) ;
else
F_41 ( V_10 ) ;
V_2 -> V_3 -> V_31 . V_86 ++ ;
V_2 -> V_3 -> V_31 . V_87 += V_16 ;
}
V_78 = V_50 -> V_61 ;
while ( V_51 < V_28 && * V_78 ) {
V_77 += * V_78 ;
V_78 ++ ;
V_51 ++ ;
}
if ( V_50 -> V_62 & V_63 )
V_77 += V_64 ;
if ( ( V_77 % 4 ) || ( V_77 > ( V_88 - V_64 ) ) ) {
F_29 ( V_2 -> V_3 ,
L_10 ,
V_4 , V_77 ) ;
return - V_79 ;
}
return V_77 ;
}
static int F_42 ( struct V_49 * V_50 )
{
int V_77 = 0 ;
int V_51 = 0 ;
T_3 * V_78 ;
if ( ( V_50 -> V_62 & ~ V_63 ) ||
( V_50 -> V_56 > V_55 ) ) {
F_43 ( L_11 , V_50 -> V_62 ,
V_50 -> V_56 ) ;
return - V_79 ;
}
V_78 = V_50 -> V_61 ;
while ( V_51 < V_28 && * V_78 ) {
V_77 += * V_78 ;
V_78 ++ ;
V_51 ++ ;
}
if ( V_77 % 4 ) {
F_43 ( L_12 , V_77 ) ;
return - V_79 ;
}
return V_77 ;
}
static int F_44 ( struct V_49 * V_50 , struct V_2 * V_2 )
{
int V_89 = 0 ;
int V_51 = 0 ;
T_3 * V_78 = NULL ;
T_2 * V_53 = NULL ;
if ( F_28 ( ( V_50 -> V_62 & ~ V_63 ) ||
( V_50 -> V_56 > V_55 ) ) ) {
F_29 ( V_2 -> V_3 , L_7 ,
V_4 ) ;
return - V_79 ;
}
V_53 = V_50 -> V_54 + V_55 ;
V_78 = V_50 -> V_61 ;
while ( V_51 < V_2 -> V_90 . V_51 ) {
V_53 += * V_78 ;
V_89 += * V_78 ;
V_78 ++ ;
V_51 ++ ;
}
while ( V_51 < V_28 && * V_78 ) {
struct V_9 * V_10 ;
T_2 * V_91 = NULL ;
int V_16 ;
V_91 = V_53 + * V_53 + 1 ;
V_16 = * V_91 ;
V_16 |= ( ( * ( V_91 + 1 ) ) << 8 ) & 0xFF00 ;
V_16 += 2 ;
if ( F_27 ( V_16 > V_80 ) ) {
F_29 ( V_2 -> V_3 , L_8 ,
V_4 ) ;
return - V_79 ;
}
V_10 = F_34 ( V_16 + 1 , V_81 ) ;
if ( ! V_10 ) {
F_29 ( V_2 -> V_3 , L_9 ,
V_4 ) ;
V_2 -> V_90 . V_51 = V_51 ;
return - V_82 ;
}
F_35 ( V_10 != NULL ) ;
F_36 ( V_10 , V_91 , V_16 ) ;
V_10 -> V_83 = F_37 ( V_84 ) ;
F_38 ( V_10 ) ;
V_10 -> V_85 = V_2 -> V_3 ;
if ( F_39 () )
F_40 ( V_10 ) ;
else
F_41 ( V_10 ) ;
V_2 -> V_3 -> V_31 . V_86 ++ ;
V_2 -> V_3 -> V_31 . V_87 += V_16 ;
V_53 += * V_78 ;
V_89 += * V_78 ;
V_78 ++ ;
V_51 ++ ;
}
return V_89 ;
}
static void F_45 ( struct V_2 * V_2 )
{
int V_66 ;
int V_92 = 0 , V_93 , V_90 ;
struct V_49 * V_50 = NULL ;
T_2 * V_94 , * V_95 ;
struct V_49 * V_96 = NULL ;
V_50 = (struct V_49 * ) V_2 -> V_95 ;
F_2 ( V_2 -> V_3 , L_13 , V_4 ) ;
if ( F_3 ( V_5 , & V_2 -> V_6 ) )
return;
F_13 ( & V_2 -> V_30 ) ;
F_46 ( & V_2 -> V_36 ,
V_37 + V_2 -> V_19 . V_38 ) ;
F_14 ( & V_2 -> V_30 ) ;
if ( V_2 -> V_90 . V_97 == V_98 ) {
V_92 = F_42 ( V_50 ) ;
if ( V_92 < 0 )
goto V_99;
V_95 = V_2 -> V_95 ;
V_93 = V_92 ;
if ( V_92 > 0 && ( V_50 -> V_62 & V_63 ) )
V_93 += V_64 ;
if ( V_92 == 0 )
V_95 = V_2 -> V_100 ;
} else {
V_95 = V_2 -> V_100 ;
V_93 = V_64 ;
if ( V_2 -> V_90 . V_52 > 0 &&
( V_50 -> V_62 & V_63 ) ) {
V_96 = (struct V_49 * )
( V_50 -> V_54 + V_55 +
V_2 -> V_90 . V_52 ) ;
V_2 -> V_90 . V_96 = true ;
V_92 = F_42 ( V_96 ) ;
if ( V_92 < 0 )
goto V_99;
if ( V_92 > 0 ) {
V_93 = V_92 ;
if ( V_96 -> V_62 & V_63 )
V_93 += V_64 ;
}
memcpy ( V_95 , ( T_2 * ) V_96 ,
V_58 ) ;
}
}
if ( V_92 ) {
V_90 = V_101 ;
V_94 = V_95 + V_64 ;
} else {
V_90 = V_98 ;
V_94 = V_95 ;
V_93 = V_64 ;
}
if ( F_3 ( V_102 , & V_2 -> V_6 ) ) {
F_2 ( V_2 -> V_3 , L_14 ,
V_4 ) ;
V_66 = V_2 -> V_42 -> V_45 ( V_94 , V_93 ,
V_2 -> V_42 ) ;
if ( F_28 ( V_66 < 0 ) ) {
F_29 ( V_2 -> V_3 , L_15 ,
V_4 , V_66 ) ;
V_2 -> V_3 -> V_31 . V_103 ++ ;
V_2 -> V_3 -> V_31 . V_104 ++ ;
}
}
if ( V_2 -> V_90 . V_97 == V_98 ) {
if ( F_33 ( V_50 , V_2 ) < 0 )
goto V_99;
} else {
if ( F_44 ( V_50 , V_2 ) < 0 )
goto V_99;
if ( V_96 ) {
if ( F_33 ( V_96 , V_2 ) < 0 )
goto V_99;
V_96 -> V_56 = 0 ;
}
}
memset ( & V_2 -> V_90 , 0 , sizeof( V_2 -> V_90 ) ) ;
V_2 -> V_90 . V_97 = V_90 ;
V_2 -> V_94 = V_94 ;
V_2 -> V_93 = V_93 ;
V_2 -> V_90 . V_52 = V_92 ;
V_2 -> V_90 . V_96 = V_50 -> V_62 & V_63 ;
if ( V_95 != V_2 -> V_95 )
F_47 ( V_2 -> V_95 , V_2 -> V_100 ) ;
return;
V_99:
F_29 ( V_2 -> V_3 , L_16 , V_4 ) ;
F_48 ( L_17 , V_105 ,
V_2 -> V_95 , V_64 ) ;
F_49 ( & V_2 -> V_106 ) ;
}
static void F_50 ( unsigned long V_1 )
{
struct V_2 * V_2 = (struct V_2 * ) V_1 ;
F_2 ( V_2 -> V_3 , L_1 ,
V_4 ) ;
F_45 ( V_2 ) ;
}
static void F_51 ( struct V_75 * V_76 )
{
struct V_2 * V_2 ;
V_2 = F_32 ( V_76 , struct V_2 , V_76 ) ;
F_2 ( V_2 -> V_3 , L_1 ,
V_4 ) ;
if ( F_3 ( V_5 , & V_2 -> V_6 ) )
return;
if ( F_52 ( V_44 , & V_2 -> V_6 ) )
F_53 ( & V_2 -> V_47 ) ;
else
F_45 ( V_2 ) ;
}
static void F_54 ( struct V_107 * V_108 )
{
struct V_2 * V_2 = NULL ;
int V_66 ;
int V_16 ;
long V_41 ;
V_2 = F_32 ( V_108 , struct V_2 , V_109 ) ;
if ( F_3 ( V_5 , & V_2 -> V_6 ) )
return;
if ( F_27 ( F_3 ( V_102 , & V_2 -> V_6 ) ) ) {
F_21 ( V_110 , & V_2 -> V_6 ) ;
F_21 ( V_111 , & V_2 -> V_6 ) ;
return;
}
V_2 -> V_42 -> F_54 ( V_2 -> V_42 ) ;
F_2 ( V_2 -> V_3 , L_18 ,
V_4 ) ;
V_41 = V_112 ;
V_41 = F_22 ( V_2 -> V_113 ,
F_52 ( V_111 ,
& V_2 -> V_6 ) , V_41 ) ;
if ( F_27 ( V_41 < 0 ) ) {
F_29 ( V_2 -> V_3 , L_19 ,
V_4 , V_41 ) ;
F_21 ( V_110 , & V_2 -> V_6 ) ;
V_2 -> V_42 -> V_114 ( V_2 -> V_42 ) ;
return;
} else if ( ! V_41 ) {
bool V_115 = false ;
T_1 V_40 = 0 ;
F_2 ( V_2 -> V_3 , L_20 ,
V_4 ) ;
F_28 ( V_2 -> V_42 -> V_43 ( V_2 -> V_42 ,
& V_40 ) ) ;
F_2 ( V_2 -> V_3 , L_21 ,
V_4 , ( unsigned ) V_40 ) ;
F_28 ( V_2 -> V_42 -> V_116 ( V_2 -> V_42 ,
& V_115 ) ) ;
if ( V_115 ) {
F_29 ( V_2 -> V_3 , L_22 ,
V_4 ) ;
F_21 ( V_111 , & V_2 -> V_6 ) ;
goto V_117;
}
F_21 ( V_110 , & V_2 -> V_6 ) ;
V_2 -> V_42 -> V_114 ( V_2 -> V_42 ) ;
return;
}
V_117:
F_2 ( V_2 -> V_3 , L_23 ,
V_4 ) ;
F_20 ( V_102 , & V_2 -> V_6 ) ;
F_21 ( V_110 , & V_2 -> V_6 ) ;
F_2 ( V_2 -> V_3 , L_14 , V_4 ) ;
V_66 = V_2 -> V_42 -> V_45 ( V_2 -> V_94 , V_2 -> V_93 , V_2 -> V_42 ) ;
if ( F_28 ( V_66 < 0 ) )
F_29 ( V_2 -> V_3 , L_24 , V_4 , V_66 ) ;
F_21 ( V_111 , & V_2 -> V_6 ) ;
F_13 ( & V_2 -> V_30 ) ;
if ( ! F_10 ( V_2 ) ) {
F_2 ( V_2 -> V_3 , L_25 ,
V_4 ) ;
F_16 ( & V_2 -> V_36 ,
V_37 + V_2 -> V_19 . V_38 ) ;
F_14 ( & V_2 -> V_30 ) ;
return;
}
F_2 ( V_2 -> V_3 , L_26 ,
V_4 ) ;
F_14 ( & V_2 -> V_30 ) ;
V_16 = F_23 ( (struct V_49 * ) V_2 -> V_65 , V_2 ) ;
if ( F_55 ( V_16 > 0 ) ) {
V_66 = V_2 -> V_42 -> V_68 ( V_2 -> V_65 , V_16 , V_2 -> V_42 ) ;
if ( F_28 ( V_66 < 0 ) ) {
F_29 ( V_2 -> V_3 , L_6 ,
V_4 , V_66 ) ;
F_12 ( V_2 ) ;
}
} else {
F_29 ( V_2 -> V_3 ,
L_27 ,
V_4 , V_16 ) ;
}
}
static void V_114 ( struct V_107 * V_108 )
{
long V_41 ;
struct V_2 * V_2 = NULL ;
T_1 V_40 = 0 ;
int V_118 = V_112 ;
V_2 = F_32 ( V_108 , struct V_2 , V_8 ) ;
F_2 ( V_2 -> V_3 , L_1 , V_4 ) ;
if ( F_3 ( V_5 , & V_2 -> V_6 ) )
return;
V_2 -> V_42 -> V_114 ( V_2 -> V_42 ) ;
V_41 = V_112 ;
V_41 = F_22 ( V_2 -> V_119 ,
F_52 ( V_120 ,
& V_2 -> V_6 ) , V_41 ) ;
if ( V_41 < 0 ) {
F_29 ( V_2 -> V_3 , L_19 ,
V_4 , V_41 ) ;
return;
} else if ( ! V_41 ) {
bool V_115 = true ;
F_29 ( V_2 -> V_3 , L_20 , V_4 ) ;
F_28 ( V_2 -> V_42 -> V_116 ( V_2 -> V_42 ,
& V_115 ) ) ;
if ( ! V_115 )
F_29 ( V_2 -> V_3 , L_22 ,
V_4 ) ;
}
while ( V_118 ) {
F_28 ( V_2 -> V_42 -> V_43 ( V_2 -> V_42 ,
& V_40 ) ) ;
if ( ! V_40 )
break;
F_56 ( V_121 ) ;
F_57 ( 1 ) ;
V_118 -- ;
}
if ( ! V_118 )
F_29 ( V_2 -> V_3 , L_28 , V_4 ) ;
F_21 ( V_102 , & V_2 -> V_6 ) ;
V_2 -> V_42 -> V_122 ( V_2 -> V_42 ) ;
}
static void F_58 ( struct V_107 * V_108 )
{
struct V_2 * V_2 = NULL ;
V_2 = F_32 ( V_108 , struct V_2 , V_106 ) ;
F_59 () ;
F_60 ( V_2 -> V_3 ) ;
F_61 () ;
}
static void F_62 ( struct V_75 * V_76 )
{
struct V_2 * V_2 = NULL ;
V_2 = F_32 ( V_76 , struct V_2 , V_76 ) ;
F_2 ( V_2 -> V_3 , L_1 ,
V_4 ) ;
F_20 ( V_111 , & V_2 -> V_6 ) ;
F_53 ( & V_2 -> V_113 ) ;
if ( F_3 ( V_5 , & V_2 -> V_6 ) )
return;
if ( ! F_63 ( V_110 , & V_2 -> V_6 ) )
F_4 ( V_2 -> V_7 , & V_2 -> V_109 ) ;
}
static void F_64 ( struct V_75 * V_76 )
{
struct V_2 * V_2 = NULL ;
V_2 = F_32 ( V_76 , struct V_2 , V_76 ) ;
F_2 ( V_2 -> V_3 , L_1 ,
V_4 ) ;
F_20 ( V_120 , & V_2 -> V_6 ) ;
F_53 ( & V_2 -> V_119 ) ;
}
static void F_65 ( unsigned long V_1 )
{
struct V_2 * V_2 = (struct V_2 * ) V_1 ;
F_2 ( V_2 -> V_3 , L_1 ,
V_4 ) ;
F_26 ( V_2 ) ;
}
static int F_66 ( struct V_9 * V_10 , struct V_123 * V_85 )
{
struct V_2 * V_2 = NULL ;
int V_124 = 0 ;
int V_125 ;
int V_126 ;
if ( ! V_85 )
return - V_127 ;
V_2 = F_67 ( V_85 ) ;
switch ( V_10 -> V_128 ) {
case V_129 :
case V_130 :
case V_131 :
V_126 = V_25 ;
break;
case V_132 :
V_126 = V_133 ;
break;
case V_134 :
V_126 = V_135 ;
break;
case V_136 :
default:
V_126 = V_137 ;
break;
}
F_13 ( & V_2 -> V_30 ) ;
F_5 ( V_2 , V_10 , 1 ) ;
F_68 ( & V_2 -> V_26 [ V_126 ] , V_10 ) ;
if ( F_28 ( F_3 ( V_5 , & V_2 -> V_6 ) ) ) {
F_14 ( & V_2 -> V_30 ) ;
F_12 ( V_2 ) ;
return - V_127 ;
}
if ( ! V_2 -> V_69 &&
F_10 ( V_2 ) > V_2 -> V_19 . V_138 &&
V_2 -> V_71 . V_72 ) {
V_2 -> V_69 = 1 ;
V_2 -> V_71 . V_72 ( V_2 -> V_3 , V_139 ) ;
}
if ( V_2 -> V_34 == V_35 ) {
V_2 -> V_34 = V_140 ;
V_124 = 1 ;
}
if ( ! V_124 ) {
bool V_141 =
F_7 ( V_2 ) &&
F_69 ( & V_2 -> V_74 ) > 0 ;
F_14 ( & V_2 -> V_30 ) ;
if ( V_141 )
F_26 ( V_2 ) ;
return 0 ;
}
V_125 = F_70 ( & V_2 -> V_36 ) ;
F_14 ( & V_2 -> V_30 ) ;
if ( V_125 ) {
struct V_49 * V_50 = (struct V_49 * ) V_2 -> V_65 ;
int V_16 ;
int V_66 ;
V_16 = F_23 ( V_50 , V_2 ) ;
F_28 ( ! V_16 ) ;
V_66 = V_2 -> V_42 -> V_68 ( V_2 -> V_65 , V_16 , V_2 -> V_42 ) ;
if ( F_28 ( V_66 < 0 ) ) {
F_29 ( V_2 -> V_3 , L_6 ,
V_4 , V_66 ) ;
F_12 ( V_2 ) ;
}
} else {
if ( ! F_63 ( V_110 , & V_2 -> V_6 ) )
F_4 ( V_2 -> V_7 , & V_2 -> V_109 ) ;
}
return 0 ;
}
static void F_71 ( struct V_123 * V_85 )
{
int V_23 ;
struct V_2 * V_2 = F_67 ( V_85 ) ;
V_85 -> V_142 = 0 ;
V_85 -> type = V_143 ;
V_85 -> V_144 = V_145 | V_146 ;
V_85 -> V_147 = V_80 ;
V_85 -> V_148 |= V_149 ;
V_85 -> V_150 = true ;
V_85 -> V_151 = & V_152 ;
for ( V_23 = 0 ; V_23 < V_29 ; ++ V_23 )
F_72 ( & V_2 -> V_26 [ V_23 ] ) ;
V_2 -> V_71 . V_153 = V_154 ;
V_2 -> V_71 . V_155 = false ;
V_2 -> V_71 . V_156 = false ;
V_2 -> V_71 . V_157 = false ;
V_2 -> V_3 = V_85 ;
V_2 -> V_19 = V_158 ;
}
static int F_73 ( struct V_123 * V_3 )
{
struct V_2 * V_2 = F_67 ( V_3 ) ;
int V_66 ;
F_21 ( V_5 , & V_2 -> V_6 ) ;
V_2 -> V_34 = V_35 ;
V_2 -> V_90 . V_97 = V_98 ;
V_2 -> V_69 = 0 ;
V_2 -> V_65 = F_74 ( V_159 , V_160 ) ;
if ( ! V_2 -> V_65 ) {
V_66 = - V_161 ;
goto V_162;
}
V_2 -> V_95 = F_74 ( V_88 , V_160 ) ;
if ( ! V_2 -> V_95 ) {
V_66 = - V_161 ;
goto V_163;
}
V_2 -> V_100 = F_74 ( V_88 , V_160 ) ;
if ( ! V_2 -> V_100 ) {
V_66 = - V_161 ;
goto V_164;
}
V_2 -> V_19 . V_24 = V_158 . V_24 ;
V_2 -> V_94 = V_2 -> V_95 ;
V_2 -> V_93 = V_64 ;
F_75 ( & V_2 -> V_30 ) ;
V_2 -> V_76 . V_165 = F_31 ;
V_2 -> V_76 . V_166 = F_51 ;
V_2 -> V_76 . V_167 = F_62 ;
V_2 -> V_76 . V_168 = F_64 ;
F_76 ( & V_2 -> V_109 , F_54 ) ;
F_76 ( & V_2 -> V_8 , V_114 ) ;
F_76 ( & V_2 -> V_106 , F_58 ) ;
F_21 ( V_111 , & V_2 -> V_6 ) ;
F_21 ( V_120 , & V_2 -> V_6 ) ;
F_21 ( V_110 , & V_2 -> V_6 ) ;
F_21 ( V_102 , & V_2 -> V_6 ) ;
V_2 -> V_7 = F_77 ( V_2 -> V_3 -> V_169 , V_170 ) ;
if ( ! V_2 -> V_7 ) {
F_29 ( V_2 -> V_3 , L_29 ,
V_4 ) ;
V_66 = - V_161 ;
goto V_171;
}
F_78 ( & V_2 -> V_113 ) ;
F_78 ( & V_2 -> V_119 ) ;
F_78 ( & V_2 -> V_47 ) ;
F_79 ( & V_2 -> V_36 ) ;
V_2 -> V_36 . V_172 = ( unsigned long ) V_2 ;
V_2 -> V_36 . V_173 = F_1 ;
F_79 ( & V_2 -> V_174 ) ;
V_2 -> V_174 . V_172 = ( unsigned long ) V_2 ;
V_2 -> V_174 . V_173 = F_50 ;
F_79 ( & V_2 -> V_74 ) ;
V_2 -> V_74 . V_172 = ( unsigned long ) V_2 ;
V_2 -> V_74 . V_173 = F_65 ;
V_66 = V_2 -> V_42 -> V_175 ( V_2 -> V_42 ) ;
if ( V_66 ) {
F_29 ( V_2 -> V_3 ,
L_30 ,
V_4 , V_66 ) ;
goto V_176;
}
V_66 = F_17 ( V_2 ) ;
if ( V_66 ) {
F_29 ( V_2 -> V_3 , L_31 ,
V_4 , V_66 ) ;
goto V_177;
}
return V_66 ;
V_177:
V_2 -> V_42 -> V_178 ( V_2 -> V_42 ) ;
V_176:
F_80 ( V_2 -> V_7 ) ;
V_171:
F_81 ( V_2 -> V_100 ) ;
V_164:
F_81 ( V_2 -> V_95 ) ;
V_163:
F_81 ( V_2 -> V_65 ) ;
V_162:
return V_66 ;
}
static int F_82 ( struct V_123 * V_3 )
{
struct V_2 * V_2 = F_67 ( V_3 ) ;
T_2 * V_65 , * V_95 , * V_179 ;
F_20 ( V_5 , & V_2 -> V_6 ) ;
F_70 ( & V_2 -> V_36 ) ;
F_70 ( & V_2 -> V_174 ) ;
F_70 ( & V_2 -> V_74 ) ;
V_2 -> V_42 -> V_122 ( V_2 -> V_42 ) ;
F_80 ( V_2 -> V_7 ) ;
V_65 = V_2 -> V_65 ;
V_95 = V_2 -> V_95 ;
V_179 = V_2 -> V_100 ;
F_12 ( V_2 ) ;
V_2 -> V_42 -> V_178 ( V_2 -> V_42 ) ;
F_81 ( V_65 ) ;
F_81 ( V_95 ) ;
F_81 ( V_179 ) ;
return 0 ;
}
static void F_83 ( struct V_123 * V_85 )
{
struct V_2 * V_2 = F_67 ( V_85 ) ;
F_84 () ;
F_85 ( V_180 ) ;
F_86 ( & V_2 -> V_181 ) ;
}
static void F_87 ( struct V_182 * V_172 [] , struct V_2 * V_2 )
{
int V_23 ;
if ( ! V_172 ) {
F_88 ( L_32 ) ;
return;
}
V_23 = V_183 ;
if ( V_172 [ V_23 ] ) {
T_4 V_38 = F_89 ( V_172 [ V_23 ] ) ;
V_2 -> V_19 . V_38 = V_38 * V_46 / 1000 ;
if ( V_2 -> V_19 . V_38 == 0 )
V_2 -> V_19 . V_38 = 1 ;
else if ( V_2 -> V_19 . V_38 > V_184 )
V_2 -> V_19 . V_38 = V_184 ;
}
V_23 = V_185 ;
if ( V_172 [ V_23 ] )
V_2 -> V_19 . V_24 = F_89 ( V_172 [ V_23 ] ) ;
V_23 = V_186 ;
if ( V_172 [ V_23 ] )
V_2 -> V_19 . V_20 = F_89 ( V_172 [ V_23 ] ) ;
V_23 = V_187 ;
if ( V_172 [ V_23 ] )
V_2 -> V_19 . V_21 = F_89 ( V_172 [ V_23 ] ) ;
V_23 = V_188 ;
if ( V_172 [ V_23 ] )
V_2 -> V_19 . V_138 = F_89 ( V_172 [ V_23 ] ) ;
V_23 = V_189 ;
if ( V_172 [ V_23 ] )
V_2 -> V_19 . V_70 = F_89 ( V_172 [ V_23 ] ) ;
}
static int F_90 ( struct V_123 * V_85 , struct V_182 * V_190 [] ,
struct V_182 * V_172 [] ,
struct V_191 * V_192 )
{
F_87 ( V_172 , F_67 ( V_85 ) ) ;
F_91 ( V_85 ) ;
return 0 ;
}
static T_1 F_92 ( const struct V_123 * V_85 )
{
int V_23 ;
T_1 V_193 = 0 ;
for ( V_23 = V_194 + 1 ; V_23 < V_195 ; V_23 ++ )
V_193 += F_93 ( V_196 [ V_23 ] . V_16 ) ;
return V_193 ;
}
static int F_94 ( struct V_9 * V_10 , const struct V_123 * V_85 )
{
struct V_2 * V_2 = F_67 ( V_85 ) ;
if ( F_95 ( V_10 , V_183 ,
V_2 -> V_19 . V_38 ) ||
F_95 ( V_10 , V_185 ,
V_2 -> V_19 . V_24 ) ||
F_95 ( V_10 , V_186 ,
V_2 -> V_19 . V_20 ) ||
F_95 ( V_10 , V_187 ,
V_2 -> V_19 . V_21 ) ||
F_95 ( V_10 , V_188 ,
V_2 -> V_19 . V_138 ) ||
F_95 ( V_10 , V_189 ,
V_2 -> V_19 . V_70 ) )
return - V_197 ;
return 0 ;
}
static int F_96 ( struct V_198 * V_199 , struct V_123 * V_85 ,
struct V_182 * V_190 [] , struct V_182 * V_172 [] ,
struct V_191 * V_192 )
{
struct V_2 * V_2 = NULL ;
struct V_200 * ( * V_201 ) ( void ) ;
F_84 () ;
V_2 = F_67 ( V_85 ) ;
F_87 ( V_172 , V_2 ) ;
V_201 = F_97 ( V_202 ) ;
if ( ! V_201 ) {
F_43 ( L_33 , V_4 ) ;
return - V_161 ;
}
V_2 -> V_42 = (* V_201)() ;
if ( ! V_2 -> V_42 ) {
F_43 ( L_33 , V_4 ) ;
goto V_203;
}
V_2 -> V_42 -> V_76 = & V_2 -> V_76 ;
if ( F_98 ( V_85 ) ) {
F_99 ( L_34 , V_4 ) ;
goto V_203;
}
F_100 ( & V_2 -> V_181 , & V_204 ) ;
return 0 ;
V_203:
F_85 ( V_202 ) ;
return - V_161 ;
}
static void T_5 F_101 ( void )
{
struct V_205 * V_206 ;
struct V_205 * V_207 ;
struct V_2 * V_2 ;
F_102 ( & V_208 ) ;
F_59 () ;
F_103 (list_node, n, &cfhsi_list) {
V_2 = F_104 ( V_206 , struct V_2 , V_181 ) ;
F_105 ( V_2 -> V_3 ) ;
}
F_61 () ;
}
static int T_6 F_106 ( void )
{
return F_107 ( & V_208 ) ;
}
