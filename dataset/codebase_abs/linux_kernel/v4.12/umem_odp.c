static void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 -> V_4 ) ;
if ( V_2 -> V_3 -> V_5 ) {
int V_6 = V_2 -> V_3 -> V_6 ++ ;
if ( V_6 == 0 )
F_3 ( & V_2 -> V_3 -> V_7 ) ;
}
F_4 ( & V_2 -> V_3 -> V_4 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 -> V_4 ) ;
if ( V_2 -> V_3 -> V_5 ) {
++ V_2 -> V_3 -> V_8 ;
if ( -- V_2 -> V_3 -> V_6 == 0 )
F_6 ( & V_2 -> V_3 -> V_7 ) ;
}
F_4 ( & V_2 -> V_3 -> V_4 ) ;
}
static void F_7 ( struct V_9 * V_10 )
{
F_8 ( & V_10 -> V_11 ) ;
}
static void F_9 ( struct V_9 * V_10 )
{
int V_12 = F_10 ( & V_10 -> V_11 ) ;
if ( V_12 &&
! F_11 ( & V_10 -> V_13 ) ) {
struct V_14 * V_3 , * V_15 ;
F_12 ( & V_10 -> V_16 ) ;
if ( ! F_13 ( & V_10 -> V_11 ) ) {
F_14 (odp_data, next,
&context->no_private_counters,
no_private_counters) {
F_2 ( & V_3 -> V_4 ) ;
V_3 -> V_5 = true ;
F_15 ( & V_3 -> V_13 ) ;
F_6 ( & V_3 -> V_7 ) ;
F_4 ( & V_3 -> V_4 ) ;
}
}
F_16 ( & V_10 -> V_16 ) ;
}
}
static int F_17 ( struct V_1 * V_2 , T_1 V_17 ,
T_1 V_18 , void * V_19 ) {
F_1 ( V_2 ) ;
V_2 -> V_3 -> V_20 = 1 ;
F_18 () ;
F_6 ( & V_2 -> V_3 -> V_7 ) ;
V_2 -> V_10 -> V_21 ( V_2 , F_19 ( V_2 ) ,
F_20 ( V_2 ) ) ;
return 0 ;
}
static void F_21 ( struct V_22 * V_23 ,
struct V_24 * V_25 )
{
struct V_9 * V_10 = F_22 ( V_23 , struct V_9 , V_23 ) ;
if ( ! V_10 -> V_21 )
return;
F_7 ( V_10 ) ;
F_23 ( & V_10 -> V_16 ) ;
F_24 ( & V_10 -> V_26 , 0 ,
V_27 ,
F_17 ,
NULL ) ;
F_25 ( & V_10 -> V_16 ) ;
}
static int F_26 ( struct V_1 * V_2 , T_1 V_17 ,
T_1 V_18 , void * V_19 )
{
F_1 ( V_2 ) ;
V_2 -> V_10 -> V_21 ( V_2 , V_17 , V_17 + V_28 ) ;
F_5 ( V_2 ) ;
return 0 ;
}
static void F_27 ( struct V_22 * V_23 ,
struct V_24 * V_25 ,
unsigned long V_29 )
{
struct V_9 * V_10 = F_22 ( V_23 , struct V_9 , V_23 ) ;
if ( ! V_10 -> V_21 )
return;
F_7 ( V_10 ) ;
F_23 ( & V_10 -> V_16 ) ;
F_24 ( & V_10 -> V_26 , V_29 ,
V_29 + V_28 ,
F_26 , NULL ) ;
F_25 ( & V_10 -> V_16 ) ;
F_9 ( V_10 ) ;
}
static int F_28 ( struct V_1 * V_2 , T_1 V_17 ,
T_1 V_18 , void * V_19 )
{
F_1 ( V_2 ) ;
V_2 -> V_10 -> V_21 ( V_2 , V_17 , V_18 ) ;
return 0 ;
}
static void F_29 ( struct V_22 * V_23 ,
struct V_24 * V_25 ,
unsigned long V_17 ,
unsigned long V_18 )
{
struct V_9 * V_10 = F_22 ( V_23 , struct V_9 , V_23 ) ;
if ( ! V_10 -> V_21 )
return;
F_7 ( V_10 ) ;
F_23 ( & V_10 -> V_16 ) ;
F_24 ( & V_10 -> V_26 , V_17 ,
V_18 ,
F_28 , NULL ) ;
F_25 ( & V_10 -> V_16 ) ;
}
static int F_30 ( struct V_1 * V_2 , T_1 V_17 ,
T_1 V_18 , void * V_19 )
{
F_5 ( V_2 ) ;
return 0 ;
}
static void F_31 ( struct V_22 * V_23 ,
struct V_24 * V_25 ,
unsigned long V_17 ,
unsigned long V_18 )
{
struct V_9 * V_10 = F_22 ( V_23 , struct V_9 , V_23 ) ;
if ( ! V_10 -> V_21 )
return;
F_23 ( & V_10 -> V_16 ) ;
F_24 ( & V_10 -> V_26 , V_17 ,
V_18 ,
F_30 , NULL ) ;
F_25 ( & V_10 -> V_16 ) ;
F_9 ( V_10 ) ;
}
struct V_1 * F_32 ( struct V_9 * V_10 ,
unsigned long V_30 ,
T_2 V_31 )
{
struct V_1 * V_32 ;
struct V_14 * V_3 ;
int V_33 = V_31 >> V_34 ;
int V_35 ;
V_32 = F_33 ( sizeof( * V_32 ) , V_36 ) ;
if ( ! V_32 )
return F_34 ( - V_37 ) ;
V_32 -> V_10 = V_10 ;
V_32 -> V_38 = V_31 ;
V_32 -> V_29 = V_30 ;
V_32 -> V_39 = V_34 ;
V_32 -> V_40 = 1 ;
V_3 = F_33 ( sizeof( * V_3 ) , V_36 ) ;
if ( ! V_3 ) {
V_35 = - V_37 ;
goto V_41;
}
V_3 -> V_32 = V_32 ;
F_35 ( & V_3 -> V_4 ) ;
F_36 ( & V_3 -> V_7 ) ;
V_3 -> V_42 = F_37 ( V_33 * sizeof( * V_3 -> V_42 ) ) ;
if ( ! V_3 -> V_42 ) {
V_35 = - V_37 ;
goto V_43;
}
V_3 -> V_44 = F_37 ( V_33 * sizeof( * V_3 -> V_44 ) ) ;
if ( ! V_3 -> V_44 ) {
V_35 = - V_37 ;
goto V_45;
}
F_12 ( & V_10 -> V_16 ) ;
V_10 -> V_46 ++ ;
F_38 ( & V_3 -> V_47 , & V_10 -> V_26 ) ;
if ( F_39 ( ! F_13 ( & V_10 -> V_11 ) ) )
V_3 -> V_5 = true ;
else
F_40 ( & V_3 -> V_13 ,
& V_10 -> V_13 ) ;
F_16 ( & V_10 -> V_16 ) ;
V_32 -> V_3 = V_3 ;
return V_32 ;
V_45:
F_41 ( V_3 -> V_42 ) ;
V_43:
F_42 ( V_3 ) ;
V_41:
F_42 ( V_32 ) ;
return F_34 ( V_35 ) ;
}
int F_43 ( struct V_9 * V_10 , struct V_1 * V_32 ,
int V_48 )
{
int V_49 ;
struct V_50 * V_51 ;
struct V_24 * V_25 = F_44 ( V_52 ) ;
if ( ! V_25 )
return - V_53 ;
if ( V_48 & V_54 ) {
struct V_55 * V_56 ;
struct V_57 * V_58 ;
F_23 ( & V_25 -> V_59 ) ;
V_56 = F_45 ( V_25 , F_19 ( V_32 ) ) ;
if ( ! V_56 || ! F_46 ( V_56 ) ) {
F_25 ( & V_25 -> V_59 ) ;
return - V_53 ;
}
V_58 = F_47 ( V_56 ) ;
V_32 -> V_39 = F_48 ( V_58 ) ;
F_25 ( & V_25 -> V_59 ) ;
V_32 -> V_60 = 1 ;
} else {
V_32 -> V_60 = 0 ;
}
F_49 () ;
V_51 = F_50 ( V_52 -> V_61 , V_62 ) ;
F_51 () ;
F_52 ( V_51 ) ;
if ( V_10 -> V_63 != V_51 ) {
V_49 = - V_53 ;
goto V_64;
}
V_32 -> V_3 = F_33 ( sizeof( * V_32 -> V_3 ) , V_36 ) ;
if ( ! V_32 -> V_3 ) {
V_49 = - V_37 ;
goto V_64;
}
V_32 -> V_3 -> V_32 = V_32 ;
F_35 ( & V_32 -> V_3 -> V_4 ) ;
F_36 ( & V_32 -> V_3 -> V_7 ) ;
if ( F_53 ( V_32 ) ) {
V_32 -> V_3 -> V_42 = F_37 ( F_53 ( V_32 ) *
sizeof( * V_32 -> V_3 -> V_42 ) ) ;
if ( ! V_32 -> V_3 -> V_42 ) {
V_49 = - V_37 ;
goto V_43;
}
V_32 -> V_3 -> V_44 = F_37 ( F_53 ( V_32 ) *
sizeof( * V_32 -> V_3 -> V_44 ) ) ;
if ( ! V_32 -> V_3 -> V_44 ) {
V_49 = - V_37 ;
goto V_45;
}
}
F_12 ( & V_10 -> V_16 ) ;
V_10 -> V_46 ++ ;
if ( F_39 ( F_19 ( V_32 ) != F_20 ( V_32 ) ) )
F_38 ( & V_32 -> V_3 -> V_47 ,
& V_10 -> V_26 ) ;
if ( F_39 ( ! F_13 ( & V_10 -> V_11 ) ) ||
V_10 -> V_46 == 1 )
V_32 -> V_3 -> V_5 = true ;
else
F_40 ( & V_32 -> V_3 -> V_13 ,
& V_10 -> V_13 ) ;
F_54 ( & V_10 -> V_16 ) ;
if ( V_10 -> V_46 == 1 ) {
F_55 ( & V_10 -> V_11 , 0 ) ;
F_56 ( & V_10 -> V_23 . V_65 ) ;
V_10 -> V_23 . V_66 = & V_67 ;
F_57 () ;
V_49 = F_58 ( & V_10 -> V_23 , V_25 ) ;
F_59 () ;
if ( V_49 ) {
F_60 ( L_1 , V_49 ) ;
V_49 = - V_68 ;
goto V_69;
}
}
F_25 ( & V_10 -> V_16 ) ;
F_61 ( V_25 ) ;
return 0 ;
V_69:
F_25 ( & V_10 -> V_16 ) ;
F_41 ( V_32 -> V_3 -> V_44 ) ;
V_45:
F_41 ( V_32 -> V_3 -> V_42 ) ;
V_43:
F_42 ( V_32 -> V_3 ) ;
V_64:
F_61 ( V_25 ) ;
return V_49 ;
}
void F_62 ( struct V_1 * V_32 )
{
struct V_9 * V_10 = V_32 -> V_10 ;
F_63 ( V_32 , F_19 ( V_32 ) ,
F_20 ( V_32 ) ) ;
F_12 ( & V_10 -> V_16 ) ;
if ( F_39 ( F_19 ( V_32 ) != F_20 ( V_32 ) ) )
F_64 ( & V_32 -> V_3 -> V_47 ,
& V_10 -> V_26 ) ;
V_10 -> V_46 -- ;
if ( ! V_32 -> V_3 -> V_5 ) {
F_15 ( & V_32 -> V_3 -> V_13 ) ;
F_6 ( & V_32 -> V_3 -> V_7 ) ;
}
F_54 ( & V_10 -> V_16 ) ;
if ( ! V_10 -> V_46 ) {
struct V_70 * V_71 = NULL ;
struct V_24 * V_72 = NULL ;
V_71 = F_65 ( V_10 -> V_63 ,
V_62 ) ;
if ( V_71 == NULL )
goto V_73;
V_72 = F_44 ( V_71 ) ;
if ( V_72 == NULL )
goto V_74;
F_66 ( & V_10 -> V_23 , V_72 ) ;
F_61 ( V_72 ) ;
V_74:
F_67 ( V_71 ) ;
}
V_73:
F_25 ( & V_10 -> V_16 ) ;
F_41 ( V_32 -> V_3 -> V_44 ) ;
F_41 ( V_32 -> V_3 -> V_42 ) ;
F_42 ( V_32 -> V_3 ) ;
F_42 ( V_32 ) ;
}
static int F_68 (
struct V_1 * V_32 ,
int V_75 ,
struct V_76 * V_76 ,
T_1 V_77 ,
unsigned long V_78 )
{
struct V_79 * V_80 = V_32 -> V_10 -> V_81 ;
T_3 V_82 ;
int V_83 = 0 ;
int V_84 = 0 ;
int V_35 = 0 ;
if ( F_69 ( V_32 , V_78 ) ) {
V_35 = - V_85 ;
goto V_73;
}
if ( ! ( V_32 -> V_3 -> V_44 [ V_75 ] ) ) {
V_82 = F_70 ( V_80 ,
V_76 ,
0 , F_71 ( V_32 -> V_39 ) ,
V_86 ) ;
if ( F_72 ( V_80 , V_82 ) ) {
V_35 = - V_87 ;
goto V_73;
}
V_32 -> V_3 -> V_44 [ V_75 ] = V_82 | V_77 ;
V_32 -> V_3 -> V_42 [ V_75 ] = V_76 ;
V_32 -> V_88 ++ ;
V_83 = 1 ;
} else if ( V_32 -> V_3 -> V_42 [ V_75 ] == V_76 ) {
V_32 -> V_3 -> V_44 [ V_75 ] |= V_77 ;
} else {
F_60 ( L_2 ,
V_32 -> V_3 -> V_42 [ V_75 ] , V_76 ) ;
V_84 = 1 ;
}
V_73:
if ( V_32 -> V_10 -> V_21 || ! V_83 )
F_73 ( V_76 ) ;
if ( V_84 && V_32 -> V_10 -> V_21 ) {
F_26 (
V_32 ,
F_19 ( V_32 ) + ( V_75 >> V_32 -> V_39 ) ,
F_19 ( V_32 ) + ( ( V_75 + 1 ) >>
V_32 -> V_39 ) ,
NULL ) ;
V_35 = - V_85 ;
}
return V_35 ;
}
int F_74 ( struct V_1 * V_32 , T_1 V_89 , T_1 V_90 ,
T_1 V_77 , unsigned long V_78 )
{
struct V_70 * V_71 = NULL ;
struct V_24 * V_72 = NULL ;
struct V_76 * * V_91 = NULL ;
T_1 V_92 , V_93 ;
int V_94 , V_95 , V_35 = 0 , V_96 , V_88 = 0 , V_39 ;
unsigned int V_97 = 0 ;
T_4 V_98 = 0 ;
if ( V_77 == 0 )
return - V_53 ;
if ( V_89 < F_19 ( V_32 ) ||
V_89 + V_90 > F_20 ( V_32 ) )
return - V_87 ;
V_91 = (struct V_76 * * ) F_75 ( V_36 ) ;
if ( ! V_91 )
return - V_37 ;
V_39 = V_32 -> V_39 ;
V_92 = ~ ( F_71 ( V_39 ) - 1 ) ;
V_93 = V_89 & ( ~ V_92 ) ;
V_89 = V_89 & V_92 ;
V_90 += V_93 ;
V_71 = F_65 ( V_32 -> V_10 -> V_63 , V_62 ) ;
if ( V_71 == NULL ) {
V_35 = - V_53 ;
goto V_99;
}
V_72 = F_44 ( V_71 ) ;
if ( V_72 == NULL ) {
V_35 = - V_100 ;
goto V_74;
}
if ( V_77 & V_101 )
V_97 |= V_102 ;
V_96 = ( V_89 - F_19 ( V_32 ) ) >> V_39 ;
V_95 = V_96 ;
while ( V_90 > 0 ) {
const T_2 V_103 = F_76 ( T_2 ,
( V_90 + F_71 ( V_39 ) - 1 ) >> V_39 ,
V_28 / sizeof( struct V_76 * ) ) ;
F_23 ( & V_72 -> V_59 ) ;
V_88 = F_77 ( V_71 , V_72 ,
V_89 , V_103 ,
V_97 , V_91 , NULL , NULL ) ;
F_25 ( & V_72 -> V_59 ) ;
if ( V_88 < 0 )
break;
V_90 -= F_76 ( T_2 , V_88 << V_34 , V_90 ) ;
F_2 ( & V_32 -> V_3 -> V_4 ) ;
for ( V_94 = 0 ; V_94 < V_88 ; V_94 ++ , V_89 += V_28 ) {
if ( V_89 & ~ V_92 ) {
V_98 += V_28 ;
if ( F_78 ( V_91 [ V_94 ] ) != V_98 ) {
V_35 = - V_87 ;
break;
}
F_73 ( V_91 [ V_94 ] ) ;
continue;
}
V_35 = F_68 (
V_32 , V_95 , V_91 [ V_94 ] ,
V_77 , V_78 ) ;
if ( V_35 < 0 )
break;
V_98 = F_78 ( V_91 [ V_94 ] ) ;
V_95 ++ ;
}
F_4 ( & V_32 -> V_3 -> V_4 ) ;
if ( V_35 < 0 ) {
for ( ++ V_94 ; V_94 < V_88 ; ++ V_94 )
F_73 ( V_91 [ V_94 ] ) ;
break;
}
}
if ( V_35 >= 0 ) {
if ( V_88 < 0 && V_95 == V_96 )
V_35 = V_88 ;
else
V_35 = V_95 - V_96 ;
}
F_61 ( V_72 ) ;
V_74:
F_67 ( V_71 ) ;
V_99:
F_79 ( ( unsigned long ) V_91 ) ;
return V_35 ;
}
void F_63 ( struct V_1 * V_32 , T_1 V_104 ,
T_1 V_105 )
{
int V_106 ;
T_1 V_30 ;
struct V_79 * V_80 = V_32 -> V_10 -> V_81 ;
V_104 = F_80 ( T_1 , V_104 , F_19 ( V_32 ) ) ;
V_105 = F_76 ( T_1 , V_105 , F_20 ( V_32 ) ) ;
F_2 ( & V_32 -> V_3 -> V_4 ) ;
for ( V_30 = V_104 ; V_30 < V_105 ; V_30 += F_71 ( V_32 -> V_39 ) ) {
V_106 = ( V_30 - F_19 ( V_32 ) ) >> V_32 -> V_39 ;
if ( V_32 -> V_3 -> V_42 [ V_106 ] ) {
struct V_76 * V_76 = V_32 -> V_3 -> V_42 [ V_106 ] ;
T_3 V_107 = V_32 -> V_3 -> V_44 [ V_106 ] ;
T_3 V_82 = V_107 & V_108 ;
F_81 ( ! V_82 ) ;
F_82 ( V_80 , V_82 , V_28 ,
V_86 ) ;
if ( V_107 & V_101 ) {
struct V_76 * V_109 = F_83 ( V_76 ) ;
F_84 ( V_109 ) ;
}
if ( ! V_32 -> V_10 -> V_21 )
F_73 ( V_76 ) ;
V_32 -> V_3 -> V_42 [ V_106 ] = NULL ;
V_32 -> V_3 -> V_44 [ V_106 ] = 0 ;
V_32 -> V_88 -- ;
}
}
F_4 ( & V_32 -> V_3 -> V_4 ) ;
}
