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
T_2 * V_80 = NULL ;
int V_16 = 0 ;
V_53 = ( ( T_2 * ) V_50 ) + V_50 -> V_56 ;
V_53 += * V_53 + 1 ;
V_16 = * V_53 ;
V_16 |= ( ( * ( V_53 + 1 ) ) << 8 ) & 0xFF00 ;
V_16 += 2 ;
if ( F_27 ( V_16 > V_81 ) ) {
F_29 ( V_2 -> V_3 , L_8 ,
V_4 ) ;
return - V_79 ;
}
V_10 = F_34 ( V_16 + 1 , V_82 ) ;
if ( ! V_10 ) {
F_29 ( V_2 -> V_3 , L_9 ,
V_4 ) ;
return - V_83 ;
}
F_35 ( V_10 != NULL ) ;
V_80 = F_36 ( V_10 , V_16 ) ;
memcpy ( V_80 , V_53 , V_16 ) ;
V_10 -> V_84 = F_37 ( V_85 ) ;
F_38 ( V_10 ) ;
V_10 -> V_86 = V_2 -> V_3 ;
if ( F_39 () )
F_40 ( V_10 ) ;
else
F_41 ( V_10 ) ;
V_2 -> V_3 -> V_31 . V_87 ++ ;
V_2 -> V_3 -> V_31 . V_88 += V_16 ;
}
V_78 = V_50 -> V_61 ;
while ( V_51 < V_28 && * V_78 ) {
V_77 += * V_78 ;
V_78 ++ ;
V_51 ++ ;
}
if ( V_50 -> V_62 & V_63 )
V_77 += V_64 ;
if ( ( V_77 % 4 ) || ( V_77 > ( V_89 - V_64 ) ) ) {
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
int V_90 = 0 ;
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
while ( V_51 < V_2 -> V_91 . V_51 ) {
V_53 += * V_78 ;
V_90 += * V_78 ;
V_78 ++ ;
V_51 ++ ;
}
while ( V_51 < V_28 && * V_78 ) {
struct V_9 * V_10 ;
T_2 * V_80 = NULL ;
T_2 * V_92 = NULL ;
int V_16 ;
V_92 = V_53 + * V_53 + 1 ;
V_16 = * V_92 ;
V_16 |= ( ( * ( V_92 + 1 ) ) << 8 ) & 0xFF00 ;
V_16 += 2 ;
if ( F_27 ( V_16 > V_81 ) ) {
F_29 ( V_2 -> V_3 , L_8 ,
V_4 ) ;
return - V_79 ;
}
V_10 = F_34 ( V_16 + 1 , V_82 ) ;
if ( ! V_10 ) {
F_29 ( V_2 -> V_3 , L_9 ,
V_4 ) ;
V_2 -> V_91 . V_51 = V_51 ;
return - V_83 ;
}
F_35 ( V_10 != NULL ) ;
V_80 = F_36 ( V_10 , V_16 ) ;
memcpy ( V_80 , V_92 , V_16 ) ;
V_10 -> V_84 = F_37 ( V_85 ) ;
F_38 ( V_10 ) ;
V_10 -> V_86 = V_2 -> V_3 ;
if ( F_39 () )
F_40 ( V_10 ) ;
else
F_41 ( V_10 ) ;
V_2 -> V_3 -> V_31 . V_87 ++ ;
V_2 -> V_3 -> V_31 . V_88 += V_16 ;
V_53 += * V_78 ;
V_90 += * V_78 ;
V_78 ++ ;
V_51 ++ ;
}
return V_90 ;
}
static void F_45 ( struct V_2 * V_2 )
{
int V_66 ;
int V_93 = 0 , V_94 , V_91 ;
struct V_49 * V_50 = NULL ;
T_2 * V_95 , * V_96 ;
struct V_49 * V_97 = NULL ;
V_50 = (struct V_49 * ) V_2 -> V_96 ;
F_2 ( V_2 -> V_3 , L_13 , V_4 ) ;
if ( F_3 ( V_5 , & V_2 -> V_6 ) )
return;
F_13 ( & V_2 -> V_30 ) ;
F_46 ( & V_2 -> V_36 ,
V_37 + V_2 -> V_19 . V_38 ) ;
F_14 ( & V_2 -> V_30 ) ;
if ( V_2 -> V_91 . V_98 == V_99 ) {
V_93 = F_42 ( V_50 ) ;
if ( V_93 < 0 )
goto V_100;
V_96 = V_2 -> V_96 ;
V_94 = V_93 ;
if ( V_93 > 0 && ( V_50 -> V_62 & V_63 ) )
V_94 += V_64 ;
if ( V_93 == 0 )
V_96 = V_2 -> V_101 ;
} else {
V_96 = V_2 -> V_101 ;
V_94 = V_64 ;
if ( V_2 -> V_91 . V_52 > 0 &&
( V_50 -> V_62 & V_63 ) ) {
V_97 = (struct V_49 * )
( V_50 -> V_54 + V_55 +
V_2 -> V_91 . V_52 ) ;
V_2 -> V_91 . V_97 = true ;
V_93 = F_42 ( V_97 ) ;
if ( V_93 < 0 )
goto V_100;
if ( V_93 > 0 ) {
V_94 = V_93 ;
if ( V_97 -> V_62 & V_63 )
V_94 += V_64 ;
}
memcpy ( V_96 , ( T_2 * ) V_97 ,
V_58 ) ;
}
}
if ( V_93 ) {
V_91 = V_102 ;
V_95 = V_96 + V_64 ;
} else {
V_91 = V_99 ;
V_95 = V_96 ;
V_94 = V_64 ;
}
if ( F_3 ( V_103 , & V_2 -> V_6 ) ) {
F_2 ( V_2 -> V_3 , L_14 ,
V_4 ) ;
V_66 = V_2 -> V_42 -> V_45 ( V_95 , V_94 ,
V_2 -> V_42 ) ;
if ( F_28 ( V_66 < 0 ) ) {
F_29 ( V_2 -> V_3 , L_15 ,
V_4 , V_66 ) ;
V_2 -> V_3 -> V_31 . V_104 ++ ;
V_2 -> V_3 -> V_31 . V_105 ++ ;
}
}
if ( V_2 -> V_91 . V_98 == V_99 ) {
if ( F_33 ( V_50 , V_2 ) < 0 )
goto V_100;
} else {
if ( F_44 ( V_50 , V_2 ) < 0 )
goto V_100;
if ( V_97 ) {
if ( F_33 ( V_97 , V_2 ) < 0 )
goto V_100;
V_97 -> V_56 = 0 ;
}
}
memset ( & V_2 -> V_91 , 0 , sizeof( V_2 -> V_91 ) ) ;
V_2 -> V_91 . V_98 = V_91 ;
V_2 -> V_95 = V_95 ;
V_2 -> V_94 = V_94 ;
V_2 -> V_91 . V_52 = V_93 ;
V_2 -> V_91 . V_97 = V_50 -> V_62 & V_63 ;
if ( V_96 != V_2 -> V_96 )
F_47 ( V_2 -> V_96 , V_2 -> V_101 ) ;
return;
V_100:
F_29 ( V_2 -> V_3 , L_16 , V_4 ) ;
F_48 ( L_17 , V_106 ,
V_2 -> V_96 , V_64 ) ;
F_49 ( & V_2 -> V_107 ) ;
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
static void F_54 ( struct V_108 * V_109 )
{
struct V_2 * V_2 = NULL ;
int V_66 ;
int V_16 ;
long V_41 ;
V_2 = F_32 ( V_109 , struct V_2 , V_110 ) ;
if ( F_3 ( V_5 , & V_2 -> V_6 ) )
return;
if ( F_27 ( F_3 ( V_103 , & V_2 -> V_6 ) ) ) {
F_21 ( V_111 , & V_2 -> V_6 ) ;
F_21 ( V_112 , & V_2 -> V_6 ) ;
return;
}
V_2 -> V_42 -> F_54 ( V_2 -> V_42 ) ;
F_2 ( V_2 -> V_3 , L_18 ,
V_4 ) ;
V_41 = V_113 ;
V_41 = F_22 ( V_2 -> V_114 ,
F_52 ( V_112 ,
& V_2 -> V_6 ) , V_41 ) ;
if ( F_27 ( V_41 < 0 ) ) {
F_29 ( V_2 -> V_3 , L_19 ,
V_4 , V_41 ) ;
F_21 ( V_111 , & V_2 -> V_6 ) ;
V_2 -> V_42 -> V_115 ( V_2 -> V_42 ) ;
return;
} else if ( ! V_41 ) {
bool V_116 = false ;
T_1 V_40 = 0 ;
F_2 ( V_2 -> V_3 , L_20 ,
V_4 ) ;
F_28 ( V_2 -> V_42 -> V_43 ( V_2 -> V_42 ,
& V_40 ) ) ;
F_2 ( V_2 -> V_3 , L_21 ,
V_4 , ( unsigned ) V_40 ) ;
F_28 ( V_2 -> V_42 -> V_117 ( V_2 -> V_42 ,
& V_116 ) ) ;
if ( V_116 ) {
F_29 ( V_2 -> V_3 , L_22 ,
V_4 ) ;
F_21 ( V_112 , & V_2 -> V_6 ) ;
goto V_118;
}
F_21 ( V_111 , & V_2 -> V_6 ) ;
V_2 -> V_42 -> V_115 ( V_2 -> V_42 ) ;
return;
}
V_118:
F_2 ( V_2 -> V_3 , L_23 ,
V_4 ) ;
F_20 ( V_103 , & V_2 -> V_6 ) ;
F_21 ( V_111 , & V_2 -> V_6 ) ;
F_2 ( V_2 -> V_3 , L_14 , V_4 ) ;
V_66 = V_2 -> V_42 -> V_45 ( V_2 -> V_95 , V_2 -> V_94 , V_2 -> V_42 ) ;
if ( F_28 ( V_66 < 0 ) )
F_29 ( V_2 -> V_3 , L_24 , V_4 , V_66 ) ;
F_21 ( V_112 , & V_2 -> V_6 ) ;
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
static void V_115 ( struct V_108 * V_109 )
{
long V_41 ;
struct V_2 * V_2 = NULL ;
T_1 V_40 = 0 ;
int V_119 = V_113 ;
V_2 = F_32 ( V_109 , struct V_2 , V_8 ) ;
F_2 ( V_2 -> V_3 , L_1 , V_4 ) ;
if ( F_3 ( V_5 , & V_2 -> V_6 ) )
return;
V_2 -> V_42 -> V_115 ( V_2 -> V_42 ) ;
V_41 = V_113 ;
V_41 = F_22 ( V_2 -> V_120 ,
F_52 ( V_121 ,
& V_2 -> V_6 ) , V_41 ) ;
if ( V_41 < 0 ) {
F_29 ( V_2 -> V_3 , L_19 ,
V_4 , V_41 ) ;
return;
} else if ( ! V_41 ) {
bool V_116 = true ;
F_29 ( V_2 -> V_3 , L_20 , V_4 ) ;
F_28 ( V_2 -> V_42 -> V_117 ( V_2 -> V_42 ,
& V_116 ) ) ;
if ( ! V_116 )
F_29 ( V_2 -> V_3 , L_22 ,
V_4 ) ;
}
while ( V_119 ) {
F_28 ( V_2 -> V_42 -> V_43 ( V_2 -> V_42 ,
& V_40 ) ) ;
if ( ! V_40 )
break;
F_56 ( V_122 ) ;
F_57 ( 1 ) ;
V_119 -- ;
}
if ( ! V_119 )
F_29 ( V_2 -> V_3 , L_28 , V_4 ) ;
F_21 ( V_103 , & V_2 -> V_6 ) ;
V_2 -> V_42 -> V_123 ( V_2 -> V_42 ) ;
}
static void F_58 ( struct V_108 * V_109 )
{
struct V_2 * V_2 = NULL ;
V_2 = F_32 ( V_109 , struct V_2 , V_107 ) ;
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
F_20 ( V_112 , & V_2 -> V_6 ) ;
F_53 ( & V_2 -> V_114 ) ;
if ( F_3 ( V_5 , & V_2 -> V_6 ) )
return;
if ( ! F_63 ( V_111 , & V_2 -> V_6 ) )
F_4 ( V_2 -> V_7 , & V_2 -> V_110 ) ;
}
static void F_64 ( struct V_75 * V_76 )
{
struct V_2 * V_2 = NULL ;
V_2 = F_32 ( V_76 , struct V_2 , V_76 ) ;
F_2 ( V_2 -> V_3 , L_1 ,
V_4 ) ;
F_20 ( V_121 , & V_2 -> V_6 ) ;
F_53 ( & V_2 -> V_120 ) ;
}
static void F_65 ( unsigned long V_1 )
{
struct V_2 * V_2 = (struct V_2 * ) V_1 ;
F_2 ( V_2 -> V_3 , L_1 ,
V_4 ) ;
F_26 ( V_2 ) ;
}
static int F_66 ( struct V_9 * V_10 , struct V_124 * V_86 )
{
struct V_2 * V_2 = NULL ;
int V_125 = 0 ;
int V_126 ;
int V_127 ;
if ( ! V_86 )
return - V_128 ;
V_2 = F_67 ( V_86 ) ;
switch ( V_10 -> V_129 ) {
case V_130 :
case V_131 :
case V_132 :
V_127 = V_25 ;
break;
case V_133 :
V_127 = V_134 ;
break;
case V_135 :
V_127 = V_136 ;
break;
case V_137 :
default:
V_127 = V_138 ;
break;
}
F_13 ( & V_2 -> V_30 ) ;
F_5 ( V_2 , V_10 , 1 ) ;
F_68 ( & V_2 -> V_26 [ V_127 ] , V_10 ) ;
if ( F_28 ( F_3 ( V_5 , & V_2 -> V_6 ) ) ) {
F_14 ( & V_2 -> V_30 ) ;
F_12 ( V_2 ) ;
return - V_128 ;
}
if ( ! V_2 -> V_69 &&
F_10 ( V_2 ) > V_2 -> V_19 . V_139 &&
V_2 -> V_71 . V_72 ) {
V_2 -> V_69 = 1 ;
V_2 -> V_71 . V_72 ( V_2 -> V_3 , V_140 ) ;
}
if ( V_2 -> V_34 == V_35 ) {
V_2 -> V_34 = V_141 ;
V_125 = 1 ;
}
if ( ! V_125 ) {
bool V_142 =
F_7 ( V_2 ) &&
F_69 ( & V_2 -> V_74 ) > 0 ;
F_14 ( & V_2 -> V_30 ) ;
if ( V_142 )
F_26 ( V_2 ) ;
return 0 ;
}
V_126 = F_70 ( & V_2 -> V_36 ) ;
F_14 ( & V_2 -> V_30 ) ;
if ( V_126 ) {
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
if ( ! F_63 ( V_111 , & V_2 -> V_6 ) )
F_4 ( V_2 -> V_7 , & V_2 -> V_110 ) ;
}
return 0 ;
}
static void F_71 ( struct V_124 * V_86 )
{
int V_23 ;
struct V_2 * V_2 = F_67 ( V_86 ) ;
V_86 -> V_143 = 0 ;
V_86 -> type = V_144 ;
V_86 -> V_145 = V_146 | V_147 ;
V_86 -> V_148 = V_81 ;
V_86 -> V_149 = 0 ;
V_86 -> V_150 = V_151 ;
V_86 -> V_152 = & V_153 ;
for ( V_23 = 0 ; V_23 < V_29 ; ++ V_23 )
F_72 ( & V_2 -> V_26 [ V_23 ] ) ;
V_2 -> V_71 . V_154 = V_155 ;
V_2 -> V_71 . V_156 = false ;
V_2 -> V_71 . V_157 = false ;
V_2 -> V_71 . V_158 = false ;
V_2 -> V_3 = V_86 ;
V_2 -> V_19 = V_159 ;
}
static int F_73 ( struct V_124 * V_3 )
{
struct V_2 * V_2 = F_67 ( V_3 ) ;
int V_66 ;
F_21 ( V_5 , & V_2 -> V_6 ) ;
V_2 -> V_34 = V_35 ;
V_2 -> V_91 . V_98 = V_99 ;
V_2 -> V_69 = 0 ;
V_2 -> V_65 = F_74 ( V_160 , V_161 ) ;
if ( ! V_2 -> V_65 ) {
V_66 = - V_162 ;
goto V_163;
}
V_2 -> V_96 = F_74 ( V_89 , V_161 ) ;
if ( ! V_2 -> V_96 ) {
V_66 = - V_162 ;
goto V_164;
}
V_2 -> V_101 = F_74 ( V_89 , V_161 ) ;
if ( ! V_2 -> V_101 ) {
V_66 = - V_162 ;
goto V_165;
}
V_2 -> V_19 . V_24 = V_159 . V_24 ;
V_2 -> V_95 = V_2 -> V_96 ;
V_2 -> V_94 = V_64 ;
F_75 ( & V_2 -> V_30 ) ;
V_2 -> V_76 . V_166 = F_31 ;
V_2 -> V_76 . V_167 = F_51 ;
V_2 -> V_76 . V_168 = F_62 ;
V_2 -> V_76 . V_169 = F_64 ;
F_76 ( & V_2 -> V_110 , F_54 ) ;
F_76 ( & V_2 -> V_8 , V_115 ) ;
F_76 ( & V_2 -> V_107 , F_58 ) ;
F_21 ( V_112 , & V_2 -> V_6 ) ;
F_21 ( V_121 , & V_2 -> V_6 ) ;
F_21 ( V_111 , & V_2 -> V_6 ) ;
F_21 ( V_103 , & V_2 -> V_6 ) ;
V_2 -> V_7 = F_77 ( V_2 -> V_3 -> V_170 ) ;
if ( ! V_2 -> V_7 ) {
F_29 ( V_2 -> V_3 , L_29 ,
V_4 ) ;
V_66 = - V_162 ;
goto V_171;
}
F_78 ( & V_2 -> V_114 ) ;
F_78 ( & V_2 -> V_120 ) ;
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
F_81 ( V_2 -> V_101 ) ;
V_165:
F_81 ( V_2 -> V_96 ) ;
V_164:
F_81 ( V_2 -> V_65 ) ;
V_163:
return V_66 ;
}
static int F_82 ( struct V_124 * V_3 )
{
struct V_2 * V_2 = F_67 ( V_3 ) ;
T_2 * V_65 , * V_96 , * V_179 ;
F_20 ( V_5 , & V_2 -> V_6 ) ;
F_83 ( V_2 -> V_7 ) ;
F_70 ( & V_2 -> V_36 ) ;
F_70 ( & V_2 -> V_174 ) ;
F_70 ( & V_2 -> V_74 ) ;
V_2 -> V_42 -> V_123 ( V_2 -> V_42 ) ;
F_80 ( V_2 -> V_7 ) ;
V_65 = V_2 -> V_65 ;
V_96 = V_2 -> V_96 ;
V_179 = V_2 -> V_101 ;
F_12 ( V_2 ) ;
V_2 -> V_42 -> V_178 ( V_2 -> V_42 ) ;
F_81 ( V_65 ) ;
F_81 ( V_96 ) ;
F_81 ( V_179 ) ;
return 0 ;
}
static void F_84 ( struct V_124 * V_86 )
{
struct V_2 * V_2 = F_67 ( V_86 ) ;
F_85 () ;
F_86 ( V_180 ) ;
F_87 ( & V_2 -> V_181 ) ;
}
static void F_88 ( struct V_182 * V_172 [] , struct V_2 * V_2 )
{
int V_23 ;
if ( ! V_172 ) {
F_89 ( L_32 ) ;
return;
}
V_23 = V_183 ;
if ( V_172 [ V_23 ] ) {
T_4 V_38 = F_90 ( V_172 [ V_23 ] ) ;
V_2 -> V_19 . V_38 = V_38 * V_46 / 1000 ;
if ( V_2 -> V_19 . V_38 == 0 )
V_2 -> V_19 . V_38 = 1 ;
else if ( V_2 -> V_19 . V_38 > V_184 )
V_2 -> V_19 . V_38 = V_184 ;
}
V_23 = V_185 ;
if ( V_172 [ V_23 ] )
V_2 -> V_19 . V_24 = F_90 ( V_172 [ V_23 ] ) ;
V_23 = V_186 ;
if ( V_172 [ V_23 ] )
V_2 -> V_19 . V_20 = F_90 ( V_172 [ V_23 ] ) ;
V_23 = V_187 ;
if ( V_172 [ V_23 ] )
V_2 -> V_19 . V_21 = F_90 ( V_172 [ V_23 ] ) ;
V_23 = V_188 ;
if ( V_172 [ V_23 ] )
V_2 -> V_19 . V_139 = F_90 ( V_172 [ V_23 ] ) ;
V_23 = V_189 ;
if ( V_172 [ V_23 ] )
V_2 -> V_19 . V_70 = F_90 ( V_172 [ V_23 ] ) ;
}
static int F_91 ( struct V_124 * V_86 , struct V_182 * V_190 [] ,
struct V_182 * V_172 [] )
{
F_88 ( V_172 , F_67 ( V_86 ) ) ;
F_92 ( V_86 ) ;
return 0 ;
}
static T_1 F_93 ( const struct V_124 * V_86 )
{
int V_23 ;
T_1 V_191 = 0 ;
for ( V_23 = V_192 + 1 ; V_23 < V_193 ; V_23 ++ )
V_191 += F_94 ( V_194 [ V_23 ] . V_16 ) ;
return V_191 ;
}
static int F_95 ( struct V_9 * V_10 , const struct V_124 * V_86 )
{
struct V_2 * V_2 = F_67 ( V_86 ) ;
if ( F_96 ( V_10 , V_183 ,
V_2 -> V_19 . V_38 ) ||
F_96 ( V_10 , V_185 ,
V_2 -> V_19 . V_24 ) ||
F_96 ( V_10 , V_186 ,
V_2 -> V_19 . V_20 ) ||
F_96 ( V_10 , V_187 ,
V_2 -> V_19 . V_21 ) ||
F_96 ( V_10 , V_188 ,
V_2 -> V_19 . V_139 ) ||
F_96 ( V_10 , V_189 ,
V_2 -> V_19 . V_70 ) )
return - V_195 ;
return 0 ;
}
static int F_97 ( struct V_196 * V_197 , struct V_124 * V_86 ,
struct V_182 * V_190 [] , struct V_182 * V_172 [] )
{
struct V_2 * V_2 = NULL ;
struct V_198 * ( * V_199 ) ( void ) ;
F_85 () ;
V_2 = F_67 ( V_86 ) ;
F_88 ( V_172 , V_2 ) ;
V_199 = F_98 ( V_200 ) ;
if ( ! V_199 ) {
F_43 ( L_33 , V_4 ) ;
return - V_162 ;
}
V_2 -> V_42 = (* V_199)() ;
if ( ! V_2 -> V_42 ) {
F_43 ( L_33 , V_4 ) ;
goto V_201;
}
V_2 -> V_42 -> V_76 = & V_2 -> V_76 ;
if ( F_99 ( V_86 ) ) {
F_100 ( L_34 , V_4 ) ;
goto V_201;
}
F_101 ( & V_2 -> V_181 , & V_202 ) ;
return 0 ;
V_201:
F_86 ( V_200 ) ;
return - V_162 ;
}
static void T_5 F_102 ( void )
{
struct V_203 * V_204 ;
struct V_203 * V_205 ;
struct V_2 * V_2 ;
F_103 ( & V_206 ) ;
F_59 () ;
F_104 (list_node, n, &cfhsi_list) {
V_2 = F_105 ( V_204 , struct V_2 , V_181 ) ;
F_106 ( V_2 -> V_3 ) ;
}
F_61 () ;
}
static int T_6 F_107 ( void )
{
return F_108 ( & V_206 ) ;
}
