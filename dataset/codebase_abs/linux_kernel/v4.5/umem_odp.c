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
int F_32 ( struct V_9 * V_10 , struct V_1 * V_30 )
{
int V_31 ;
struct V_32 * V_33 ;
struct V_24 * V_25 = F_33 ( V_34 ) ;
if ( ! V_25 )
return - V_35 ;
F_34 () ;
V_33 = F_35 ( V_34 -> V_36 , V_37 ) ;
F_36 () ;
F_37 ( V_33 ) ;
if ( V_10 -> V_38 != V_33 ) {
V_31 = - V_35 ;
goto V_39;
}
V_30 -> V_40 = 0 ;
V_30 -> V_3 = F_38 ( sizeof( * V_30 -> V_3 ) , V_41 ) ;
if ( ! V_30 -> V_3 ) {
V_31 = - V_42 ;
goto V_39;
}
V_30 -> V_3 -> V_30 = V_30 ;
F_39 ( & V_30 -> V_3 -> V_4 ) ;
F_40 ( & V_30 -> V_3 -> V_7 ) ;
V_30 -> V_3 -> V_43 = F_41 ( F_42 ( V_30 ) *
sizeof( * V_30 -> V_3 -> V_43 ) ) ;
if ( ! V_30 -> V_3 -> V_43 ) {
V_31 = - V_42 ;
goto V_44;
}
V_30 -> V_3 -> V_45 = F_41 ( F_42 ( V_30 ) *
sizeof( * V_30 -> V_3 -> V_45 ) ) ;
if ( ! V_30 -> V_3 -> V_45 ) {
V_31 = - V_42 ;
goto V_46;
}
F_12 ( & V_10 -> V_16 ) ;
V_10 -> V_47 ++ ;
if ( F_43 ( F_19 ( V_30 ) != F_20 ( V_30 ) ) )
F_44 ( & V_30 -> V_3 -> V_48 ,
& V_10 -> V_26 ) ;
if ( F_43 ( ! F_13 ( & V_10 -> V_11 ) ) ||
V_10 -> V_47 == 1 )
V_30 -> V_3 -> V_5 = true ;
else
F_45 ( & V_30 -> V_3 -> V_13 ,
& V_10 -> V_13 ) ;
F_46 ( & V_10 -> V_16 ) ;
if ( V_10 -> V_47 == 1 ) {
F_47 ( & V_10 -> V_11 , 0 ) ;
F_48 ( & V_10 -> V_23 . V_49 ) ;
V_10 -> V_23 . V_50 = & V_51 ;
F_49 () ;
V_31 = F_50 ( & V_10 -> V_23 , V_25 ) ;
F_51 () ;
if ( V_31 ) {
F_52 ( L_1 , V_31 ) ;
V_31 = - V_52 ;
goto V_53;
}
}
F_25 ( & V_10 -> V_16 ) ;
F_53 ( V_25 ) ;
return 0 ;
V_53:
F_25 ( & V_10 -> V_16 ) ;
F_54 ( V_30 -> V_3 -> V_45 ) ;
V_46:
F_54 ( V_30 -> V_3 -> V_43 ) ;
V_44:
F_55 ( V_30 -> V_3 ) ;
V_39:
F_53 ( V_25 ) ;
return V_31 ;
}
void F_56 ( struct V_1 * V_30 )
{
struct V_9 * V_10 = V_30 -> V_10 ;
F_57 ( V_30 , F_19 ( V_30 ) ,
F_20 ( V_30 ) ) ;
F_12 ( & V_10 -> V_16 ) ;
if ( F_43 ( F_19 ( V_30 ) != F_20 ( V_30 ) ) )
F_58 ( & V_30 -> V_3 -> V_48 ,
& V_10 -> V_26 ) ;
V_10 -> V_47 -- ;
if ( ! V_30 -> V_3 -> V_5 ) {
F_15 ( & V_30 -> V_3 -> V_13 ) ;
F_6 ( & V_30 -> V_3 -> V_7 ) ;
}
F_46 ( & V_10 -> V_16 ) ;
if ( ! V_10 -> V_47 ) {
struct V_54 * V_55 = NULL ;
struct V_24 * V_56 = NULL ;
V_55 = F_59 ( V_10 -> V_38 ,
V_37 ) ;
if ( V_55 == NULL )
goto V_57;
V_56 = F_33 ( V_55 ) ;
if ( V_56 == NULL )
goto V_58;
F_60 ( & V_10 -> V_23 , V_56 ) ;
F_53 ( V_56 ) ;
V_58:
F_61 ( V_55 ) ;
}
V_57:
F_25 ( & V_10 -> V_16 ) ;
F_54 ( V_30 -> V_3 -> V_45 ) ;
F_54 ( V_30 -> V_3 -> V_43 ) ;
F_55 ( V_30 -> V_3 ) ;
F_55 ( V_30 ) ;
}
static int F_62 (
struct V_1 * V_30 ,
int V_59 ,
T_1 V_60 ,
struct V_61 * V_61 ,
T_1 V_62 ,
unsigned long V_63 )
{
struct V_64 * V_65 = V_30 -> V_10 -> V_66 ;
T_2 V_67 ;
int V_68 = 0 ;
int V_69 = 0 ;
int V_70 = 0 ;
if ( F_63 ( V_30 , V_63 ) ) {
V_70 = - V_71 ;
goto V_57;
}
if ( ! ( V_30 -> V_3 -> V_45 [ V_59 ] ) ) {
V_67 = F_64 ( V_65 ,
V_61 ,
0 , V_28 ,
V_72 ) ;
if ( F_65 ( V_65 , V_67 ) ) {
V_70 = - V_73 ;
goto V_57;
}
V_30 -> V_3 -> V_45 [ V_59 ] = V_67 | V_62 ;
V_30 -> V_3 -> V_43 [ V_59 ] = V_61 ;
V_68 = 1 ;
} else if ( V_30 -> V_3 -> V_43 [ V_59 ] == V_61 ) {
V_30 -> V_3 -> V_45 [ V_59 ] |= V_62 ;
} else {
F_52 ( L_2 ,
V_30 -> V_3 -> V_43 [ V_59 ] , V_61 ) ;
V_69 = 1 ;
}
V_57:
if ( V_30 -> V_10 -> V_21 || ! V_68 )
F_66 ( V_61 ) ;
if ( V_69 && V_30 -> V_10 -> V_21 ) {
F_26 (
V_30 ,
V_60 + ( V_59 * V_28 ) ,
V_60 + ( ( V_59 + 1 ) * V_28 ) ,
NULL ) ;
V_70 = - V_71 ;
}
return V_70 ;
}
int F_67 ( struct V_1 * V_30 , T_1 V_74 , T_1 V_75 ,
T_1 V_62 , unsigned long V_63 )
{
struct V_54 * V_55 = NULL ;
struct V_24 * V_56 = NULL ;
struct V_61 * * V_76 = NULL ;
T_1 V_77 ;
int V_78 , V_79 , V_70 = 0 , V_80 , V_81 = 0 ;
T_1 V_60 ;
if ( V_62 == 0 )
return - V_35 ;
if ( V_74 < F_19 ( V_30 ) ||
V_74 + V_75 > F_20 ( V_30 ) )
return - V_73 ;
V_76 = (struct V_61 * * ) F_68 ( V_41 ) ;
if ( ! V_76 )
return - V_42 ;
V_77 = V_74 & ( ~ V_82 ) ;
V_74 = V_74 & V_82 ;
V_60 = V_74 ;
V_75 += V_77 ;
V_55 = F_59 ( V_30 -> V_10 -> V_38 , V_37 ) ;
if ( V_55 == NULL ) {
V_70 = - V_35 ;
goto V_83;
}
V_56 = F_33 ( V_55 ) ;
if ( V_56 == NULL ) {
V_70 = - V_35 ;
goto V_58;
}
V_80 = ( V_74 - F_19 ( V_30 ) ) >> V_84 ;
V_79 = V_80 ;
while ( V_75 > 0 ) {
const T_3 V_85 =
F_69 ( T_3 , F_70 ( V_75 , V_28 ) / V_28 ,
V_28 / sizeof( struct V_61 * ) ) ;
F_23 ( & V_56 -> V_86 ) ;
V_81 = F_71 ( V_55 , V_56 , V_74 ,
V_85 ,
V_62 & V_87 , 0 ,
V_76 , NULL ) ;
F_25 ( & V_56 -> V_86 ) ;
if ( V_81 < 0 )
break;
V_75 -= F_69 ( T_3 , V_81 << V_84 , V_75 ) ;
V_74 += V_81 << V_84 ;
F_2 ( & V_30 -> V_3 -> V_4 ) ;
for ( V_78 = 0 ; V_78 < V_81 ; ++ V_78 ) {
V_70 = F_62 (
V_30 , V_79 , V_60 , V_76 [ V_78 ] ,
V_62 , V_63 ) ;
if ( V_70 < 0 )
break;
V_79 ++ ;
}
F_4 ( & V_30 -> V_3 -> V_4 ) ;
if ( V_70 < 0 ) {
for ( ++ V_78 ; V_78 < V_81 ; ++ V_78 )
F_66 ( V_76 [ V_78 ] ) ;
break;
}
}
if ( V_70 >= 0 ) {
if ( V_81 < 0 && V_79 == V_80 )
V_70 = V_81 ;
else
V_70 = V_79 - V_80 ;
}
F_53 ( V_56 ) ;
V_58:
F_61 ( V_55 ) ;
V_83:
F_72 ( ( unsigned long ) V_76 ) ;
return V_70 ;
}
void F_57 ( struct V_1 * V_30 , T_1 V_88 ,
T_1 V_89 )
{
int V_90 ;
T_1 V_91 ;
struct V_64 * V_65 = V_30 -> V_10 -> V_66 ;
V_88 = F_73 ( T_1 , V_88 , F_19 ( V_30 ) ) ;
V_89 = F_69 ( T_1 , V_89 , F_20 ( V_30 ) ) ;
F_2 ( & V_30 -> V_3 -> V_4 ) ;
for ( V_91 = V_88 ; V_91 < V_89 ; V_91 += ( T_1 ) V_30 -> V_92 ) {
V_90 = ( V_91 - F_19 ( V_30 ) ) / V_28 ;
if ( V_30 -> V_3 -> V_43 [ V_90 ] ) {
struct V_61 * V_61 = V_30 -> V_3 -> V_43 [ V_90 ] ;
T_2 V_93 = V_30 -> V_3 -> V_45 [ V_90 ] ;
T_2 V_67 = V_93 & V_94 ;
F_74 ( ! V_67 ) ;
F_75 ( V_65 , V_67 , V_28 ,
V_72 ) ;
if ( V_93 & V_87 ) {
struct V_61 * V_95 = F_76 ( V_61 ) ;
F_77 ( V_95 ) ;
}
if ( ! V_30 -> V_10 -> V_21 )
F_66 ( V_61 ) ;
V_30 -> V_3 -> V_43 [ V_90 ] = NULL ;
V_30 -> V_3 -> V_45 [ V_90 ] = 0 ;
}
}
F_4 ( & V_30 -> V_3 -> V_4 ) ;
}
