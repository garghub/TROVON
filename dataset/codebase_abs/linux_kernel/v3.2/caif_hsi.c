static void F_1 ( unsigned long V_1 )
{
struct V_2 * V_2 = (struct V_2 * ) V_1 ;
F_2 ( & V_2 -> V_3 -> V_4 , L_1 ,
V_5 ) ;
if ( ! F_3 ( V_6 , & V_2 -> V_7 ) )
F_4 ( V_2 -> V_8 , & V_2 -> V_9 ) ;
}
static void F_5 ( struct V_2 * V_2 )
{
struct V_10 * V_11 ;
for (; ; ) {
F_6 ( & V_2 -> V_12 ) ;
V_11 = F_7 ( & V_2 -> V_13 ) ;
if ( ! V_11 )
break;
V_2 -> V_3 -> V_14 . V_15 ++ ;
V_2 -> V_3 -> V_14 . V_16 ++ ;
F_8 ( & V_2 -> V_12 ) ;
F_9 ( V_11 ) ;
}
V_2 -> V_17 = V_18 ;
if ( ! F_3 ( V_6 , & V_2 -> V_7 ) )
F_10 ( & V_2 -> V_19 ,
V_20 + V_2 -> V_21 ) ;
F_8 ( & V_2 -> V_12 ) ;
}
static int F_11 ( struct V_2 * V_2 )
{
char V_22 [ 32 ] ;
T_1 V_23 ;
int V_24 ;
F_2 ( & V_2 -> V_3 -> V_4 , L_1 ,
V_5 ) ;
V_24 = V_2 -> V_4 -> V_25 ( V_2 -> V_4 ) ;
if ( V_24 ) {
F_12 ( & V_2 -> V_3 -> V_4 ,
L_2 ,
V_5 , V_24 ) ;
return V_24 ;
}
do {
V_24 = V_2 -> V_4 -> V_26 ( V_2 -> V_4 ,
& V_23 ) ;
if ( V_24 ) {
F_12 ( & V_2 -> V_3 -> V_4 ,
L_3 ,
V_5 , V_24 ) ;
break;
} else if ( ! V_23 )
break;
V_23 = F_13 ( sizeof( V_22 ) , V_23 ) ;
F_14 ( V_27 , & V_2 -> V_7 ) ;
V_24 = V_2 -> V_4 -> V_28 ( V_22 , V_23 ,
V_2 -> V_4 ) ;
if ( V_24 ) {
F_15 ( V_27 , & V_2 -> V_7 ) ;
F_12 ( & V_2 -> V_3 -> V_4 ,
L_4 ,
V_5 , V_24 ) ;
break;
}
V_24 = 5 * V_29 ;
V_24 = F_16 ( V_2 -> V_30 ,
! F_3 ( V_27 , & V_2 -> V_7 ) , V_24 ) ;
if ( V_24 < 0 ) {
F_12 ( & V_2 -> V_3 -> V_4 ,
L_5 ,
V_5 , V_24 ) ;
break;
} else if ( ! V_24 ) {
V_24 = - V_31 ;
F_12 ( & V_2 -> V_3 -> V_4 ,
L_6 ,
V_5 ) ;
break;
}
} while ( 1 );
V_2 -> V_4 -> V_32 ( V_2 -> V_4 ) ;
return V_24 ;
}
static int F_17 ( struct V_33 * V_34 , struct V_2 * V_2 )
{
int V_35 = 0 ;
int V_36 = 0 ;
struct V_10 * V_11 ;
T_2 * V_37 = V_34 -> V_38 + V_39 ;
V_11 = F_7 ( & V_2 -> V_13 ) ;
if ( ! V_11 )
return 0 ;
V_34 -> V_40 = 0 ;
if ( V_11 -> V_41 < V_39 ) {
struct V_42 * V_43 ;
int V_44 = 0 ;
int V_45 = 0 ;
V_43 = (struct V_42 * ) & V_11 -> V_46 ;
V_44 = 1 + F_18 ( ( V_43 -> V_47 + 1 ) , V_48 ) ;
V_45 = F_18 ( ( V_11 -> V_41 + V_44 ) , V_49 ) ;
if ( ( V_11 -> V_41 + V_44 + V_45 ) <= V_39 ) {
T_2 * V_50 = V_34 -> V_38 ;
V_34 -> V_40 = V_51 ;
* V_50 = ( T_2 ) ( V_44 - 1 ) ;
V_50 += V_44 ;
V_2 -> V_3 -> V_14 . V_52 ++ ;
V_2 -> V_3 -> V_14 . V_53 += V_11 -> V_41 ;
F_19 ( V_11 , 0 , V_50 , V_11 -> V_41 ) ;
F_20 ( V_11 ) ;
V_11 = NULL ;
}
}
V_37 = V_34 -> V_38 + V_39 ;
while ( V_35 < V_54 ) {
struct V_42 * V_43 ;
int V_44 = 0 ;
int V_45 = 0 ;
if ( ! V_11 )
V_11 = F_7 ( & V_2 -> V_13 ) ;
if ( ! V_11 )
break;
V_43 = (struct V_42 * ) & V_11 -> V_46 ;
V_44 = 1 + F_18 ( ( V_43 -> V_47 + 1 ) , V_48 ) ;
V_45 = F_18 ( ( V_11 -> V_41 + V_44 ) , V_49 ) ;
V_34 -> V_55 [ V_35 ] = V_44 + V_11 -> V_41 + V_45 ;
* V_37 = ( T_2 ) ( V_44 - 1 ) ;
V_37 += V_44 ;
V_2 -> V_3 -> V_14 . V_52 ++ ;
V_2 -> V_3 -> V_14 . V_53 += V_11 -> V_41 ;
F_19 ( V_11 , 0 , V_37 , V_11 -> V_41 ) ;
V_36 += V_34 -> V_55 [ V_35 ] ;
V_37 += V_11 -> V_41 + V_45 ;
F_20 ( V_11 ) ;
V_11 = NULL ;
V_35 ++ ;
}
while ( V_35 < V_54 ) {
V_34 -> V_55 [ V_35 ] = 0x0000 ;
V_35 ++ ;
}
V_11 = F_21 ( & V_2 -> V_13 ) ;
if ( V_11 )
V_34 -> V_56 |= V_57 ;
else
V_34 -> V_56 &= ~ V_57 ;
return V_58 + V_36 ;
}
static void F_22 ( struct V_2 * V_2 )
{
struct V_33 * V_34 = NULL ;
int V_41 = 0 ;
int V_59 ;
F_2 ( & V_2 -> V_3 -> V_4 , L_1 , V_5 ) ;
if ( F_3 ( V_6 , & V_2 -> V_7 ) )
return;
V_34 = (struct V_33 * ) V_2 -> V_60 ;
do {
F_6 ( & V_2 -> V_12 ) ;
if ( V_2 -> V_61 &&
V_2 -> V_13 . V_62 <= V_2 -> V_63 &&
V_2 -> V_64 . V_65 ) {
V_2 -> V_61 = 0 ;
V_2 -> V_64 . V_65 ( V_2 -> V_3 , V_66 ) ;
}
F_8 ( & V_2 -> V_12 ) ;
do {
V_41 = F_17 ( V_34 , V_2 ) ;
if ( ! V_41 ) {
F_6 ( & V_2 -> V_12 ) ;
if ( F_23 ( F_21 ( & V_2 -> V_13 ) ) ) {
F_8 ( & V_2 -> V_12 ) ;
continue;
}
V_2 -> V_17 = V_18 ;
F_10 ( & V_2 -> V_19 ,
V_20 + V_2 -> V_21 ) ;
F_8 ( & V_2 -> V_12 ) ;
goto V_67;
}
} while ( ! V_41 );
V_59 = V_2 -> V_4 -> V_68 ( V_2 -> V_60 , V_41 , V_2 -> V_4 ) ;
if ( F_24 ( V_59 < 0 ) ) {
F_25 ( & V_2 -> V_3 -> V_4 , L_7 ,
V_5 , V_59 ) ;
}
} while ( V_59 < 0 );
V_67:
return;
}
static void F_26 ( struct V_69 * V_70 )
{
struct V_2 * V_2 ;
V_2 = F_27 ( V_70 , struct V_2 , V_70 ) ;
F_2 ( & V_2 -> V_3 -> V_4 , L_1 ,
V_5 ) ;
if ( F_3 ( V_6 , & V_2 -> V_7 ) )
return;
F_22 ( V_2 ) ;
}
static int F_28 ( struct V_33 * V_34 , struct V_2 * V_2 )
{
int V_71 = 0 ;
int V_35 = 0 ;
T_3 * V_72 = NULL ;
T_2 * V_37 = NULL ;
if ( ( V_34 -> V_56 & ~ V_57 ) ||
( V_34 -> V_40 > V_39 ) ) {
F_25 ( & V_2 -> V_3 -> V_4 , L_8 ,
V_5 ) ;
return - V_73 ;
}
if ( V_34 -> V_40 ) {
struct V_10 * V_11 ;
T_2 * V_74 = NULL ;
int V_41 = 0 ;
V_37 = ( ( T_2 * ) V_34 ) + V_34 -> V_40 ;
V_37 += * V_37 + 1 ;
V_41 = * V_37 ;
V_41 |= ( ( * ( V_37 + 1 ) ) << 8 ) & 0xFF00 ;
V_41 += 2 ;
if ( F_23 ( V_41 > V_75 ) ) {
F_25 ( & V_2 -> V_3 -> V_4 , L_9 ,
V_5 ) ;
return - V_73 ;
}
V_11 = F_29 ( V_41 + 1 , V_76 ) ;
if ( ! V_11 ) {
F_25 ( & V_2 -> V_3 -> V_4 , L_10 ,
V_5 ) ;
return - V_77 ;
}
F_30 ( V_11 != NULL ) ;
V_74 = F_31 ( V_11 , V_41 ) ;
memcpy ( V_74 , V_37 , V_41 ) ;
V_11 -> V_78 = F_32 ( V_79 ) ;
F_33 ( V_11 ) ;
V_11 -> V_4 = V_2 -> V_3 ;
if ( F_34 () )
F_35 ( V_11 ) ;
else
F_36 ( V_11 ) ;
V_2 -> V_3 -> V_14 . V_80 ++ ;
V_2 -> V_3 -> V_14 . V_81 += V_41 ;
}
V_72 = V_34 -> V_55 ;
while ( V_35 < V_54 && * V_72 ) {
V_71 += * V_72 ;
V_72 ++ ;
V_35 ++ ;
}
if ( V_34 -> V_56 & V_57 )
V_71 += V_58 ;
if ( ( V_71 % 4 ) || ( V_71 > ( V_82 - V_58 ) ) ) {
F_25 ( & V_2 -> V_3 -> V_4 ,
L_11 ,
V_5 , V_71 ) ;
return - V_73 ;
}
return V_71 ;
}
static int F_37 ( struct V_33 * V_34 , struct V_2 * V_2 )
{
int V_83 = 0 ;
int V_35 = 0 ;
T_3 * V_72 = NULL ;
T_2 * V_37 = NULL ;
if ( F_24 ( ( V_34 -> V_56 & ~ V_57 ) ||
( V_34 -> V_40 > V_39 ) ) ) {
F_25 ( & V_2 -> V_3 -> V_4 , L_8 ,
V_5 ) ;
return - V_73 ;
}
V_37 = V_34 -> V_38 + V_39 ;
V_72 = V_34 -> V_55 ;
while ( V_35 < V_2 -> V_84 . V_35 ) {
V_37 += * V_72 ;
V_83 += * V_72 ;
V_72 ++ ;
V_35 ++ ;
}
while ( V_35 < V_54 && * V_72 ) {
struct V_10 * V_11 ;
T_2 * V_74 = NULL ;
T_2 * V_85 = NULL ;
int V_41 = 0 ;
V_85 = V_37 + * V_37 + 1 ;
V_41 = * V_85 ;
V_41 |= ( ( * ( V_85 + 1 ) ) << 8 ) & 0xFF00 ;
V_41 += 2 ;
if ( F_23 ( V_41 > V_75 ) ) {
F_25 ( & V_2 -> V_3 -> V_4 , L_9 ,
V_5 ) ;
return - V_73 ;
}
V_11 = F_29 ( V_41 + 1 , V_76 ) ;
if ( ! V_11 ) {
F_25 ( & V_2 -> V_3 -> V_4 , L_10 ,
V_5 ) ;
V_2 -> V_84 . V_35 = V_35 ;
return - V_77 ;
}
F_30 ( V_11 != NULL ) ;
V_74 = F_31 ( V_11 , V_41 ) ;
memcpy ( V_74 , V_85 , V_41 ) ;
V_11 -> V_78 = F_32 ( V_79 ) ;
F_33 ( V_11 ) ;
V_11 -> V_4 = V_2 -> V_3 ;
if ( F_34 () )
F_35 ( V_11 ) ;
else
F_36 ( V_11 ) ;
V_2 -> V_3 -> V_14 . V_80 ++ ;
V_2 -> V_3 -> V_14 . V_81 += V_41 ;
V_37 += * V_72 ;
V_83 += * V_72 ;
V_72 ++ ;
V_35 ++ ;
}
return V_83 ;
}
static void F_38 ( struct V_2 * V_2 )
{
int V_59 ;
int V_86 = 0 ;
struct V_33 * V_34 = NULL ;
V_34 = (struct V_33 * ) V_2 -> V_87 ;
F_2 ( & V_2 -> V_3 -> V_4 , L_12 , V_5 ) ;
if ( F_3 ( V_6 , & V_2 -> V_7 ) )
return;
F_6 ( & V_2 -> V_12 ) ;
F_39 ( & V_2 -> V_19 ,
V_20 + V_2 -> V_21 ) ;
F_8 ( & V_2 -> V_12 ) ;
if ( V_2 -> V_84 . V_88 == V_89 ) {
V_86 = F_28 ( V_34 , V_2 ) ;
if ( V_86 == - V_77 )
goto V_90;
if ( V_86 == - V_73 )
goto V_91;
} else {
int V_36 ;
if ( ! V_2 -> V_84 . V_92 ) {
V_36 = F_37 ( V_34 , V_2 ) ;
if ( V_36 == - V_77 )
goto V_90;
if ( V_36 == - V_73 )
goto V_91;
V_2 -> V_84 . V_36 = V_36 ;
} else {
V_36 = V_2 -> V_84 . V_36 ;
}
if ( ( V_36 > 0 ) && ( V_34 -> V_56 & V_57 ) ) {
struct V_33 * V_92 ;
V_92 = (struct V_33 * )
( V_34 -> V_38 + V_39 +
V_36 ) ;
V_2 -> V_84 . V_92 = true ;
V_86 = F_28 ( V_92 , V_2 ) ;
if ( V_86 == - V_77 )
goto V_90;
memcpy ( ( T_2 * ) V_34 , ( T_2 * ) V_92 ,
V_51 ) ;
if ( V_86 == - V_73 )
goto V_91;
}
}
memset ( & V_2 -> V_84 , 0 , sizeof( V_2 -> V_84 ) ) ;
if ( V_86 ) {
V_2 -> V_84 . V_88 = V_93 ;
V_2 -> V_94 = V_2 -> V_87 + V_58 ;
V_2 -> V_95 = V_86 ;
} else {
V_2 -> V_84 . V_88 = V_89 ;
V_2 -> V_94 = V_2 -> V_87 ;
V_2 -> V_95 = V_58 ;
}
if ( F_3 ( V_96 , & V_2 -> V_7 ) ) {
F_2 ( & V_2 -> V_3 -> V_4 , L_13 ,
V_5 ) ;
V_59 = V_2 -> V_4 -> V_28 ( V_2 -> V_94 , V_2 -> V_95 ,
V_2 -> V_4 ) ;
if ( F_24 ( V_59 < 0 ) ) {
F_25 ( & V_2 -> V_3 -> V_4 , L_14 ,
V_5 , V_59 ) ;
V_2 -> V_3 -> V_14 . V_97 ++ ;
V_2 -> V_3 -> V_14 . V_98 ++ ;
}
}
return;
V_90:
if ( ++ V_2 -> V_84 . V_99 > V_100 ) {
F_25 ( & V_2 -> V_3 -> V_4 , L_15
L_16 ,
V_5 , V_100 ) ;
F_40 () ;
}
F_10 ( & V_2 -> V_101 , V_20 + 1 ) ;
return;
V_91:
F_25 ( & V_2 -> V_3 -> V_4 , L_17 , V_5 ) ;
F_41 ( L_18 , V_102 ,
V_2 -> V_87 , V_58 ) ;
F_42 ( & V_2 -> V_103 ) ;
}
static void F_43 ( unsigned long V_1 )
{
struct V_2 * V_2 = (struct V_2 * ) V_1 ;
F_2 ( & V_2 -> V_3 -> V_4 , L_1 ,
V_5 ) ;
F_38 ( V_2 ) ;
}
static void F_44 ( struct V_69 * V_70 )
{
struct V_2 * V_2 ;
V_2 = F_27 ( V_70 , struct V_2 , V_70 ) ;
F_2 ( & V_2 -> V_3 -> V_4 , L_1 ,
V_5 ) ;
if ( F_3 ( V_6 , & V_2 -> V_7 ) )
return;
if ( F_45 ( V_27 , & V_2 -> V_7 ) )
F_46 ( & V_2 -> V_30 ) ;
else
F_38 ( V_2 ) ;
}
static void V_25 ( struct V_104 * V_105 )
{
struct V_2 * V_2 = NULL ;
int V_59 ;
int V_41 ;
long V_24 ;
V_2 = F_27 ( V_105 , struct V_2 , V_106 ) ;
if ( F_3 ( V_6 , & V_2 -> V_7 ) )
return;
if ( F_23 ( F_3 ( V_96 , & V_2 -> V_7 ) ) ) {
F_15 ( V_107 , & V_2 -> V_7 ) ;
F_15 ( V_108 , & V_2 -> V_7 ) ;
return;
}
V_2 -> V_4 -> V_25 ( V_2 -> V_4 ) ;
F_2 ( & V_2 -> V_3 -> V_4 , L_19 ,
V_5 ) ;
V_24 = V_109 ;
V_24 = F_16 ( V_2 -> V_110 ,
F_45 ( V_108 ,
& V_2 -> V_7 ) , V_24 ) ;
if ( F_23 ( V_24 < 0 ) ) {
F_25 ( & V_2 -> V_3 -> V_4 , L_20 ,
V_5 , V_24 ) ;
F_15 ( V_107 , & V_2 -> V_7 ) ;
V_2 -> V_4 -> V_32 ( V_2 -> V_4 ) ;
return;
} else if ( ! V_24 ) {
bool V_111 = false ;
T_1 V_23 = 0 ;
F_25 ( & V_2 -> V_3 -> V_4 , L_21 ,
V_5 ) ;
F_24 ( V_2 -> V_4 -> V_26 ( V_2 -> V_4 ,
& V_23 ) ) ;
F_25 ( & V_2 -> V_3 -> V_4 , L_22 ,
V_5 , ( unsigned ) V_23 ) ;
F_24 ( V_2 -> V_4 -> V_112 ( V_2 -> V_4 ,
& V_111 ) ) ;
if ( V_111 ) {
F_25 ( & V_2 -> V_3 -> V_4 , L_23 ,
V_5 ) ;
F_15 ( V_108 , & V_2 -> V_7 ) ;
goto V_113;
}
F_15 ( V_107 , & V_2 -> V_7 ) ;
V_2 -> V_4 -> V_32 ( V_2 -> V_4 ) ;
return;
}
V_113:
F_2 ( & V_2 -> V_3 -> V_4 , L_24 ,
V_5 ) ;
F_14 ( V_96 , & V_2 -> V_7 ) ;
F_15 ( V_107 , & V_2 -> V_7 ) ;
F_2 ( & V_2 -> V_3 -> V_4 , L_13 , V_5 ) ;
V_59 = V_2 -> V_4 -> V_28 ( V_2 -> V_94 , V_2 -> V_95 , V_2 -> V_4 ) ;
if ( F_24 ( V_59 < 0 ) )
F_25 ( & V_2 -> V_3 -> V_4 , L_25 , V_5 , V_59 ) ;
F_15 ( V_108 , & V_2 -> V_7 ) ;
F_6 ( & V_2 -> V_12 ) ;
if ( ! F_21 ( & V_2 -> V_13 ) ) {
F_2 ( & V_2 -> V_3 -> V_4 , L_26 ,
V_5 ) ;
F_10 ( & V_2 -> V_19 ,
V_20 + V_2 -> V_21 ) ;
F_8 ( & V_2 -> V_12 ) ;
return;
}
F_2 ( & V_2 -> V_3 -> V_4 , L_27 ,
V_5 ) ;
F_8 ( & V_2 -> V_12 ) ;
V_41 = F_17 ( (struct V_33 * ) V_2 -> V_60 , V_2 ) ;
if ( F_47 ( V_41 > 0 ) ) {
V_59 = V_2 -> V_4 -> V_68 ( V_2 -> V_60 , V_41 , V_2 -> V_4 ) ;
if ( F_24 ( V_59 < 0 ) ) {
F_25 ( & V_2 -> V_3 -> V_4 , L_7 ,
V_5 , V_59 ) ;
F_5 ( V_2 ) ;
}
} else {
F_25 ( & V_2 -> V_3 -> V_4 ,
L_28 ,
V_5 , V_41 ) ;
}
}
static void V_32 ( struct V_104 * V_105 )
{
long V_24 ;
struct V_2 * V_2 = NULL ;
T_1 V_23 = 0 ;
int V_114 = V_109 ;
V_2 = F_27 ( V_105 , struct V_2 , V_9 ) ;
F_2 ( & V_2 -> V_3 -> V_4 , L_1 , V_5 ) ;
if ( F_3 ( V_6 , & V_2 -> V_7 ) )
return;
V_2 -> V_4 -> V_32 ( V_2 -> V_4 ) ;
V_24 = V_109 ;
V_24 = F_16 ( V_2 -> V_115 ,
F_45 ( V_116 ,
& V_2 -> V_7 ) , V_24 ) ;
if ( V_24 < 0 ) {
F_25 ( & V_2 -> V_3 -> V_4 , L_20 ,
V_5 , V_24 ) ;
return;
} else if ( ! V_24 ) {
bool V_111 = true ;
F_25 ( & V_2 -> V_3 -> V_4 , L_21 , V_5 ) ;
F_24 ( V_2 -> V_4 -> V_112 ( V_2 -> V_4 ,
& V_111 ) ) ;
if ( ! V_111 )
F_25 ( & V_2 -> V_3 -> V_4 , L_23 ,
V_5 ) ;
}
while ( V_114 ) {
F_24 ( V_2 -> V_4 -> V_26 ( V_2 -> V_4 ,
& V_23 ) ) ;
if ( ! V_23 )
break;
F_48 ( V_117 ) ;
F_49 ( 1 ) ;
V_114 -- ;
}
if ( ! V_114 )
F_25 ( & V_2 -> V_3 -> V_4 , L_29 , V_5 ) ;
F_15 ( V_96 , & V_2 -> V_7 ) ;
V_2 -> V_4 -> V_118 ( V_2 -> V_4 ) ;
}
static void F_50 ( struct V_104 * V_105 )
{
struct V_2 * V_2 = NULL ;
V_2 = F_27 ( V_105 , struct V_2 , V_103 ) ;
F_51 () ;
F_52 ( V_2 -> V_3 ) ;
F_53 () ;
}
static void F_54 ( struct V_69 * V_70 )
{
struct V_2 * V_2 = NULL ;
V_2 = F_27 ( V_70 , struct V_2 , V_70 ) ;
F_2 ( & V_2 -> V_3 -> V_4 , L_1 ,
V_5 ) ;
F_14 ( V_108 , & V_2 -> V_7 ) ;
F_46 ( & V_2 -> V_110 ) ;
if ( F_3 ( V_6 , & V_2 -> V_7 ) )
return;
if ( ! F_55 ( V_107 , & V_2 -> V_7 ) )
F_4 ( V_2 -> V_8 , & V_2 -> V_106 ) ;
}
static void F_56 ( struct V_69 * V_70 )
{
struct V_2 * V_2 = NULL ;
V_2 = F_27 ( V_70 , struct V_2 , V_70 ) ;
F_2 ( & V_2 -> V_3 -> V_4 , L_1 ,
V_5 ) ;
F_14 ( V_116 , & V_2 -> V_7 ) ;
F_46 ( & V_2 -> V_115 ) ;
}
static int F_57 ( struct V_10 * V_11 , struct V_119 * V_4 )
{
struct V_2 * V_2 = NULL ;
int V_120 = 0 ;
int V_121 ;
if ( ! V_4 )
return - V_122 ;
V_2 = F_58 ( V_4 ) ;
F_6 ( & V_2 -> V_12 ) ;
F_59 ( & V_2 -> V_13 , V_11 ) ;
if ( F_24 ( F_3 ( V_6 , & V_2 -> V_7 ) ) ) {
F_8 ( & V_2 -> V_12 ) ;
F_5 ( V_2 ) ;
return - V_122 ;
}
if ( ! V_2 -> V_61 &&
V_2 -> V_13 . V_62 > V_2 -> V_123 &&
V_2 -> V_64 . V_65 ) {
V_2 -> V_61 = 1 ;
V_2 -> V_64 . V_65 ( V_2 -> V_3 , V_124 ) ;
}
if ( V_2 -> V_17 == V_18 ) {
V_2 -> V_17 = V_125 ;
V_120 = 1 ;
}
if ( ! V_120 ) {
F_8 ( & V_2 -> V_12 ) ;
return 0 ;
}
V_121 = F_60 ( & V_2 -> V_19 ) ;
F_8 ( & V_2 -> V_12 ) ;
if ( V_121 ) {
struct V_33 * V_34 = (struct V_33 * ) V_2 -> V_60 ;
int V_41 ;
int V_59 ;
V_41 = F_17 ( V_34 , V_2 ) ;
F_61 ( ! V_41 ) ;
V_59 = V_2 -> V_4 -> V_68 ( V_2 -> V_60 , V_41 , V_2 -> V_4 ) ;
if ( F_24 ( V_59 < 0 ) ) {
F_25 ( & V_2 -> V_3 -> V_4 , L_7 ,
V_5 , V_59 ) ;
F_5 ( V_2 ) ;
}
} else {
if ( ! F_55 ( V_107 , & V_2 -> V_7 ) )
F_4 ( V_2 -> V_8 , & V_2 -> V_106 ) ;
}
return 0 ;
}
static int F_62 ( struct V_119 * V_4 )
{
F_63 ( V_4 ) ;
return 0 ;
}
static int F_64 ( struct V_119 * V_4 )
{
F_65 ( V_4 ) ;
return 0 ;
}
static void F_66 ( struct V_119 * V_4 )
{
struct V_2 * V_2 = F_58 ( V_4 ) ;
V_4 -> V_126 = 0 ;
V_4 -> V_127 = & V_128 ;
V_4 -> type = V_129 ;
V_4 -> V_130 = V_131 | V_132 ;
V_4 -> V_133 = V_134 ;
V_4 -> V_135 = 0 ;
V_4 -> V_136 = V_137 ;
F_67 ( & V_2 -> V_13 ) ;
V_2 -> V_64 . V_138 = V_139 ;
V_2 -> V_64 . V_140 = false ;
V_2 -> V_64 . V_141 = false ;
V_2 -> V_64 . V_142 = false ;
V_2 -> V_3 = V_4 ;
}
int F_68 ( struct V_143 * V_144 )
{
struct V_2 * V_2 = NULL ;
struct V_119 * V_3 ;
struct V_145 * V_4 ;
int V_59 ;
V_3 = F_69 ( sizeof( struct V_2 ) , L_30 , F_66 ) ;
if ( ! V_3 )
return - V_146 ;
V_2 = F_58 ( V_3 ) ;
V_2 -> V_3 = V_3 ;
V_2 -> V_144 = V_144 ;
V_2 -> V_17 = V_18 ;
V_2 -> V_84 . V_88 = V_89 ;
V_2 -> V_61 = 0 ;
V_2 -> V_63 = V_147 ;
V_2 -> V_123 = V_148 ;
V_4 = (struct V_145 * ) V_144 -> V_4 . V_149 ;
V_2 -> V_4 = V_4 ;
V_4 -> V_70 = & V_2 -> V_70 ;
V_2 -> V_60 = F_70 ( V_150 , V_151 ) ;
if ( ! V_2 -> V_60 ) {
V_59 = - V_146 ;
goto V_152;
}
V_2 -> V_87 = F_70 ( V_82 , V_151 ) ;
if ( ! V_2 -> V_87 ) {
V_59 = - V_146 ;
goto V_153;
}
if ( V_21 != - 1 ) {
V_2 -> V_21 =
V_21 * V_29 / 1000 ;
if ( ! V_2 -> V_21 )
V_2 -> V_21 = 1 ;
else if ( V_2 -> V_21 > V_154 )
V_2 -> V_21 = V_154 ;
} else {
V_2 -> V_21 = V_154 ;
}
V_2 -> V_94 = V_2 -> V_87 ;
V_2 -> V_95 = V_58 ;
F_71 ( & V_2 -> V_12 ) ;
V_2 -> V_70 . V_155 = F_26 ;
V_2 -> V_70 . V_156 = F_44 ;
V_2 -> V_70 . V_157 = F_54 ;
V_2 -> V_70 . V_158 = F_56 ;
F_72 ( & V_2 -> V_106 , V_25 ) ;
F_72 ( & V_2 -> V_9 , V_32 ) ;
F_72 ( & V_2 -> V_103 , F_50 ) ;
F_15 ( V_108 , & V_2 -> V_7 ) ;
F_15 ( V_116 , & V_2 -> V_7 ) ;
F_15 ( V_107 , & V_2 -> V_7 ) ;
F_15 ( V_96 , & V_2 -> V_7 ) ;
V_2 -> V_8 = F_73 ( V_144 -> V_159 ) ;
if ( ! V_2 -> V_8 ) {
F_25 ( & V_3 -> V_4 , L_31 ,
V_5 ) ;
V_59 = - V_146 ;
goto V_160;
}
F_74 ( & V_2 -> V_110 ) ;
F_74 ( & V_2 -> V_115 ) ;
F_74 ( & V_2 -> V_30 ) ;
F_75 ( & V_2 -> V_19 ) ;
V_2 -> V_19 . V_161 = ( unsigned long ) V_2 ;
V_2 -> V_19 . V_162 = F_1 ;
F_75 ( & V_2 -> V_101 ) ;
V_2 -> V_101 . V_161 = ( unsigned long ) V_2 ;
V_2 -> V_101 . V_162 = F_43 ;
F_76 ( & V_163 ) ;
F_77 ( & V_2 -> V_164 , & V_165 ) ;
F_78 ( & V_163 ) ;
V_59 = V_2 -> V_4 -> V_166 ( V_2 -> V_4 ) ;
if ( V_59 ) {
F_25 ( & V_2 -> V_3 -> V_4 ,
L_32 ,
V_5 , V_59 ) ;
goto V_167;
}
V_59 = F_11 ( V_2 ) ;
if ( V_59 ) {
F_25 ( & V_3 -> V_4 , L_33 ,
V_5 , V_59 ) ;
goto V_168;
}
V_59 = F_79 ( V_3 ) ;
if ( V_59 ) {
F_25 ( & V_3 -> V_4 , L_34 ,
V_5 , V_59 ) ;
goto V_168;
}
F_65 ( V_3 ) ;
return V_59 ;
V_168:
V_2 -> V_4 -> V_169 ( V_2 -> V_4 ) ;
V_167:
F_80 ( V_2 -> V_8 ) ;
V_160:
F_81 ( V_2 -> V_87 ) ;
V_153:
F_81 ( V_2 -> V_60 ) ;
V_152:
V_137 ( V_3 ) ;
return V_59 ;
}
static void F_82 ( struct V_2 * V_2 )
{
T_2 * V_60 , * V_87 ;
F_83 ( V_2 -> V_3 ) ;
F_14 ( V_6 , & V_2 -> V_7 ) ;
F_84 ( V_2 -> V_8 ) ;
F_60 ( & V_2 -> V_19 ) ;
F_60 ( & V_2 -> V_101 ) ;
V_2 -> V_4 -> V_118 ( V_2 -> V_4 ) ;
F_80 ( V_2 -> V_8 ) ;
V_60 = V_2 -> V_60 ;
V_87 = V_2 -> V_87 ;
F_5 ( V_2 ) ;
V_2 -> V_4 -> V_169 ( V_2 -> V_4 ) ;
F_85 ( V_2 -> V_3 ) ;
F_81 ( V_60 ) ;
F_81 ( V_87 ) ;
}
int F_86 ( struct V_143 * V_144 )
{
struct V_170 * V_171 ;
struct V_170 * V_172 ;
struct V_2 * V_2 = NULL ;
struct V_145 * V_4 ;
V_4 = (struct V_145 * ) V_144 -> V_4 . V_149 ;
F_76 ( & V_163 ) ;
F_87 (list_node, n, &cfhsi_list) {
V_2 = F_88 ( V_171 , struct V_2 , V_164 ) ;
if ( V_2 -> V_4 == V_4 ) {
F_89 ( V_171 ) ;
F_78 ( & V_163 ) ;
F_82 ( V_2 ) ;
return 0 ;
}
}
F_78 ( & V_163 ) ;
return - V_146 ;
}
static void T_4 F_90 ( void )
{
struct V_170 * V_171 ;
struct V_170 * V_172 ;
struct V_2 * V_2 = NULL ;
F_76 ( & V_163 ) ;
F_87 (list_node, n, &cfhsi_list) {
V_2 = F_88 ( V_171 , struct V_2 , V_164 ) ;
F_89 ( V_171 ) ;
F_78 ( & V_163 ) ;
F_82 ( V_2 ) ;
F_76 ( & V_163 ) ;
}
F_78 ( & V_163 ) ;
F_91 ( & V_173 ) ;
}
static int T_5 F_92 ( void )
{
int V_174 ;
F_71 ( & V_163 ) ;
V_174 = F_93 ( & V_173 ) ;
if ( V_174 ) {
F_94 ( V_175 L_35 ,
V_174 ) ;
goto V_176;
}
return V_174 ;
V_176:
return V_174 ;
}
