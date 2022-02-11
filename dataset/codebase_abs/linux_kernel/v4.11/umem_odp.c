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
V_32 -> V_39 = V_28 ;
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
int F_43 ( struct V_9 * V_10 , struct V_1 * V_32 )
{
int V_48 ;
struct V_49 * V_50 ;
struct V_24 * V_25 = F_44 ( V_51 ) ;
if ( ! V_25 )
return - V_52 ;
F_45 () ;
V_50 = F_46 ( V_51 -> V_53 , V_54 ) ;
F_47 () ;
F_48 ( V_50 ) ;
if ( V_10 -> V_55 != V_50 ) {
V_48 = - V_52 ;
goto V_56;
}
V_32 -> V_57 = 0 ;
V_32 -> V_3 = F_33 ( sizeof( * V_32 -> V_3 ) , V_36 ) ;
if ( ! V_32 -> V_3 ) {
V_48 = - V_37 ;
goto V_56;
}
V_32 -> V_3 -> V_32 = V_32 ;
F_35 ( & V_32 -> V_3 -> V_4 ) ;
F_36 ( & V_32 -> V_3 -> V_7 ) ;
if ( F_49 ( V_32 ) ) {
V_32 -> V_3 -> V_42 = F_37 ( F_49 ( V_32 ) *
sizeof( * V_32 -> V_3 -> V_42 ) ) ;
if ( ! V_32 -> V_3 -> V_42 ) {
V_48 = - V_37 ;
goto V_43;
}
V_32 -> V_3 -> V_44 = F_37 ( F_49 ( V_32 ) *
sizeof( * V_32 -> V_3 -> V_44 ) ) ;
if ( ! V_32 -> V_3 -> V_44 ) {
V_48 = - V_37 ;
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
F_50 ( & V_10 -> V_16 ) ;
if ( V_10 -> V_46 == 1 ) {
F_51 ( & V_10 -> V_11 , 0 ) ;
F_52 ( & V_10 -> V_23 . V_58 ) ;
V_10 -> V_23 . V_59 = & V_60 ;
F_53 () ;
V_48 = F_54 ( & V_10 -> V_23 , V_25 ) ;
F_55 () ;
if ( V_48 ) {
F_56 ( L_1 , V_48 ) ;
V_48 = - V_61 ;
goto V_62;
}
}
F_25 ( & V_10 -> V_16 ) ;
F_57 ( V_25 ) ;
return 0 ;
V_62:
F_25 ( & V_10 -> V_16 ) ;
F_41 ( V_32 -> V_3 -> V_44 ) ;
V_45:
F_41 ( V_32 -> V_3 -> V_42 ) ;
V_43:
F_42 ( V_32 -> V_3 ) ;
V_56:
F_57 ( V_25 ) ;
return V_48 ;
}
void F_58 ( struct V_1 * V_32 )
{
struct V_9 * V_10 = V_32 -> V_10 ;
F_59 ( V_32 , F_19 ( V_32 ) ,
F_20 ( V_32 ) ) ;
F_12 ( & V_10 -> V_16 ) ;
if ( F_39 ( F_19 ( V_32 ) != F_20 ( V_32 ) ) )
F_60 ( & V_32 -> V_3 -> V_47 ,
& V_10 -> V_26 ) ;
V_10 -> V_46 -- ;
if ( ! V_32 -> V_3 -> V_5 ) {
F_15 ( & V_32 -> V_3 -> V_13 ) ;
F_6 ( & V_32 -> V_3 -> V_7 ) ;
}
F_50 ( & V_10 -> V_16 ) ;
if ( ! V_10 -> V_46 ) {
struct V_63 * V_64 = NULL ;
struct V_24 * V_65 = NULL ;
V_64 = F_61 ( V_10 -> V_55 ,
V_54 ) ;
if ( V_64 == NULL )
goto V_66;
V_65 = F_44 ( V_64 ) ;
if ( V_65 == NULL )
goto V_67;
F_62 ( & V_10 -> V_23 , V_65 ) ;
F_57 ( V_65 ) ;
V_67:
F_63 ( V_64 ) ;
}
V_66:
F_25 ( & V_10 -> V_16 ) ;
F_41 ( V_32 -> V_3 -> V_44 ) ;
F_41 ( V_32 -> V_3 -> V_42 ) ;
F_42 ( V_32 -> V_3 ) ;
F_42 ( V_32 ) ;
}
static int F_64 (
struct V_1 * V_32 ,
int V_68 ,
T_1 V_69 ,
struct V_70 * V_70 ,
T_1 V_71 ,
unsigned long V_72 )
{
struct V_73 * V_74 = V_32 -> V_10 -> V_75 ;
T_3 V_76 ;
int V_77 = 0 ;
int V_78 = 0 ;
int V_35 = 0 ;
if ( F_65 ( V_32 , V_72 ) ) {
V_35 = - V_79 ;
goto V_66;
}
if ( ! ( V_32 -> V_3 -> V_44 [ V_68 ] ) ) {
V_76 = F_66 ( V_74 ,
V_70 ,
0 , V_28 ,
V_80 ) ;
if ( F_67 ( V_74 , V_76 ) ) {
V_35 = - V_81 ;
goto V_66;
}
V_32 -> V_3 -> V_44 [ V_68 ] = V_76 | V_71 ;
V_32 -> V_3 -> V_42 [ V_68 ] = V_70 ;
V_32 -> V_82 ++ ;
V_77 = 1 ;
} else if ( V_32 -> V_3 -> V_42 [ V_68 ] == V_70 ) {
V_32 -> V_3 -> V_44 [ V_68 ] |= V_71 ;
} else {
F_56 ( L_2 ,
V_32 -> V_3 -> V_42 [ V_68 ] , V_70 ) ;
V_78 = 1 ;
}
V_66:
if ( V_32 -> V_10 -> V_21 || ! V_77 )
F_68 ( V_70 ) ;
if ( V_78 && V_32 -> V_10 -> V_21 ) {
F_26 (
V_32 ,
V_69 + ( V_68 * V_28 ) ,
V_69 + ( ( V_68 + 1 ) * V_28 ) ,
NULL ) ;
V_35 = - V_79 ;
}
return V_35 ;
}
int F_69 ( struct V_1 * V_32 , T_1 V_83 , T_1 V_84 ,
T_1 V_71 , unsigned long V_72 )
{
struct V_63 * V_64 = NULL ;
struct V_24 * V_65 = NULL ;
struct V_70 * * V_85 = NULL ;
T_1 V_86 ;
int V_87 , V_88 , V_35 = 0 , V_89 , V_82 = 0 ;
T_1 V_69 ;
unsigned int V_90 = 0 ;
if ( V_71 == 0 )
return - V_52 ;
if ( V_83 < F_19 ( V_32 ) ||
V_83 + V_84 > F_20 ( V_32 ) )
return - V_81 ;
V_85 = (struct V_70 * * ) F_70 ( V_36 ) ;
if ( ! V_85 )
return - V_37 ;
V_86 = V_83 & ( ~ V_91 ) ;
V_83 = V_83 & V_91 ;
V_69 = V_83 ;
V_84 += V_86 ;
V_64 = F_61 ( V_32 -> V_10 -> V_55 , V_54 ) ;
if ( V_64 == NULL ) {
V_35 = - V_52 ;
goto V_92;
}
V_65 = F_44 ( V_64 ) ;
if ( V_65 == NULL ) {
V_35 = - V_93 ;
goto V_67;
}
if ( V_71 & V_94 )
V_90 |= V_95 ;
V_89 = ( V_83 - F_19 ( V_32 ) ) >> V_34 ;
V_88 = V_89 ;
while ( V_84 > 0 ) {
const T_2 V_96 =
F_71 ( T_2 , F_72 ( V_84 , V_28 ) / V_28 ,
V_28 / sizeof( struct V_70 * ) ) ;
F_23 ( & V_65 -> V_97 ) ;
V_82 = F_73 ( V_64 , V_65 ,
V_83 , V_96 ,
V_90 , V_85 , NULL , NULL ) ;
F_25 ( & V_65 -> V_97 ) ;
if ( V_82 < 0 )
break;
V_84 -= F_71 ( T_2 , V_82 << V_34 , V_84 ) ;
V_83 += V_82 << V_34 ;
F_2 ( & V_32 -> V_3 -> V_4 ) ;
for ( V_87 = 0 ; V_87 < V_82 ; ++ V_87 ) {
V_35 = F_64 (
V_32 , V_88 , V_69 , V_85 [ V_87 ] ,
V_71 , V_72 ) ;
if ( V_35 < 0 )
break;
V_88 ++ ;
}
F_4 ( & V_32 -> V_3 -> V_4 ) ;
if ( V_35 < 0 ) {
for ( ++ V_87 ; V_87 < V_82 ; ++ V_87 )
F_68 ( V_85 [ V_87 ] ) ;
break;
}
}
if ( V_35 >= 0 ) {
if ( V_82 < 0 && V_88 == V_89 )
V_35 = V_82 ;
else
V_35 = V_88 - V_89 ;
}
F_57 ( V_65 ) ;
V_67:
F_63 ( V_64 ) ;
V_92:
F_74 ( ( unsigned long ) V_85 ) ;
return V_35 ;
}
void F_59 ( struct V_1 * V_32 , T_1 V_98 ,
T_1 V_99 )
{
int V_100 ;
T_1 V_30 ;
struct V_73 * V_74 = V_32 -> V_10 -> V_75 ;
V_98 = F_75 ( T_1 , V_98 , F_19 ( V_32 ) ) ;
V_99 = F_71 ( T_1 , V_99 , F_20 ( V_32 ) ) ;
F_2 ( & V_32 -> V_3 -> V_4 ) ;
for ( V_30 = V_98 ; V_30 < V_99 ; V_30 += ( T_1 ) V_32 -> V_39 ) {
V_100 = ( V_30 - F_19 ( V_32 ) ) / V_28 ;
if ( V_32 -> V_3 -> V_42 [ V_100 ] ) {
struct V_70 * V_70 = V_32 -> V_3 -> V_42 [ V_100 ] ;
T_3 V_101 = V_32 -> V_3 -> V_44 [ V_100 ] ;
T_3 V_76 = V_101 & V_102 ;
F_76 ( ! V_76 ) ;
F_77 ( V_74 , V_76 , V_28 ,
V_80 ) ;
if ( V_101 & V_94 ) {
struct V_70 * V_103 = F_78 ( V_70 ) ;
F_79 ( V_103 ) ;
}
if ( ! V_32 -> V_10 -> V_21 )
F_68 ( V_70 ) ;
V_32 -> V_3 -> V_42 [ V_100 ] = NULL ;
V_32 -> V_3 -> V_44 [ V_100 ] = 0 ;
V_32 -> V_82 -- ;
}
}
F_4 ( & V_32 -> V_3 -> V_4 ) ;
}
