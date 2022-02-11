static struct V_1 * F_1 ( struct V_2 * V_3 , T_1 V_4 )
{
T_2 V_5 ;
struct V_1 * V_1 ;
F_2 () ;
V_5 = V_4 >> V_6 ;
V_1 = F_3 ( & V_3 -> V_7 , V_5 ) ;
F_4 () ;
F_5 ( V_1 && V_1 -> V_8 != V_5 ) ;
return V_1 ;
}
static struct V_1 * F_6 ( struct V_2 * V_3 , T_1 V_4 )
{
T_2 V_5 ;
struct V_1 * V_1 ;
T_3 V_9 ;
V_1 = F_1 ( V_3 , V_4 ) ;
if ( V_1 )
return V_1 ;
V_9 = V_10 | V_11 ;
#ifndef F_7
V_9 |= V_12 ;
#endif
V_1 = F_8 ( V_9 ) ;
if ( ! V_1 )
return NULL ;
if ( F_9 ( V_10 ) ) {
F_10 ( V_1 ) ;
return NULL ;
}
F_11 ( & V_3 -> V_13 ) ;
V_5 = V_4 >> V_6 ;
if ( F_12 ( & V_3 -> V_7 , V_5 , V_1 ) ) {
F_10 ( V_1 ) ;
V_1 = F_3 ( & V_3 -> V_7 , V_5 ) ;
F_5 ( ! V_1 ) ;
F_5 ( V_1 -> V_8 != V_5 ) ;
} else
V_1 -> V_8 = V_5 ;
F_13 ( & V_3 -> V_13 ) ;
F_14 () ;
return V_1 ;
}
static void F_15 ( struct V_2 * V_3 , T_1 V_4 )
{
struct V_1 * V_1 ;
T_2 V_5 ;
F_11 ( & V_3 -> V_13 ) ;
V_5 = V_4 >> V_6 ;
V_1 = F_16 ( & V_3 -> V_7 , V_5 ) ;
F_13 ( & V_3 -> V_13 ) ;
if ( V_1 )
F_10 ( V_1 ) ;
}
static void F_17 ( struct V_2 * V_3 , T_1 V_4 )
{
struct V_1 * V_1 ;
V_1 = F_1 ( V_3 , V_4 ) ;
if ( V_1 )
F_18 ( V_1 ) ;
}
static void F_19 ( struct V_2 * V_3 )
{
unsigned long V_14 = 0 ;
struct V_1 * V_15 [ V_16 ] ;
int V_17 ;
do {
int V_18 ;
V_17 = F_20 ( & V_3 -> V_7 ,
( void * * ) V_15 , V_14 , V_16 ) ;
for ( V_18 = 0 ; V_18 < V_17 ; V_18 ++ ) {
void * V_19 ;
F_5 ( V_15 [ V_18 ] -> V_8 < V_14 ) ;
V_14 = V_15 [ V_18 ] -> V_8 ;
V_19 = F_16 ( & V_3 -> V_7 , V_14 ) ;
F_5 ( ! V_19 || V_19 != V_15 [ V_18 ] ) ;
F_10 ( V_15 [ V_18 ] ) ;
}
V_14 ++ ;
} while ( V_17 == V_16 );
}
static int F_21 ( struct V_2 * V_3 , T_1 V_4 , T_4 V_20 )
{
unsigned int V_21 = ( V_4 & ( V_22 - 1 ) ) << V_23 ;
T_4 V_24 ;
V_24 = F_22 ( T_4 , V_20 , V_25 - V_21 ) ;
if ( ! F_6 ( V_3 , V_4 ) )
return - V_26 ;
if ( V_24 < V_20 ) {
V_4 += V_24 >> V_23 ;
if ( ! F_6 ( V_3 , V_4 ) )
return - V_26 ;
}
return 0 ;
}
static void F_23 ( struct V_2 * V_3 ,
T_1 V_4 , T_4 V_20 )
{
while ( V_20 >= V_25 ) {
if ( 0 )
F_15 ( V_3 , V_4 ) ;
else
F_17 ( V_3 , V_4 ) ;
V_4 += V_25 >> V_23 ;
V_20 -= V_25 ;
}
}
static void F_24 ( struct V_2 * V_3 , const void * V_27 ,
T_1 V_4 , T_4 V_20 )
{
struct V_1 * V_1 ;
void * V_28 ;
unsigned int V_21 = ( V_4 & ( V_22 - 1 ) ) << V_23 ;
T_4 V_24 ;
V_24 = F_22 ( T_4 , V_20 , V_25 - V_21 ) ;
V_1 = F_1 ( V_3 , V_4 ) ;
F_5 ( ! V_1 ) ;
V_28 = F_25 ( V_1 , V_29 ) ;
memcpy ( V_28 + V_21 , V_27 , V_24 ) ;
F_26 ( V_28 , V_29 ) ;
if ( V_24 < V_20 ) {
V_27 += V_24 ;
V_4 += V_24 >> V_23 ;
V_24 = V_20 - V_24 ;
V_1 = F_1 ( V_3 , V_4 ) ;
F_5 ( ! V_1 ) ;
V_28 = F_25 ( V_1 , V_29 ) ;
memcpy ( V_28 , V_27 , V_24 ) ;
F_26 ( V_28 , V_29 ) ;
}
}
static void F_27 ( void * V_28 , struct V_2 * V_3 ,
T_1 V_4 , T_4 V_20 )
{
struct V_1 * V_1 ;
void * V_27 ;
unsigned int V_21 = ( V_4 & ( V_22 - 1 ) ) << V_23 ;
T_4 V_24 ;
V_24 = F_22 ( T_4 , V_20 , V_25 - V_21 ) ;
V_1 = F_1 ( V_3 , V_4 ) ;
if ( V_1 ) {
V_27 = F_25 ( V_1 , V_29 ) ;
memcpy ( V_28 , V_27 + V_21 , V_24 ) ;
F_26 ( V_27 , V_29 ) ;
} else
memset ( V_28 , 0 , V_24 ) ;
if ( V_24 < V_20 ) {
V_28 += V_24 ;
V_4 += V_24 >> V_23 ;
V_24 = V_20 - V_24 ;
V_1 = F_1 ( V_3 , V_4 ) ;
if ( V_1 ) {
V_27 = F_25 ( V_1 , V_29 ) ;
memcpy ( V_28 , V_27 , V_24 ) ;
F_26 ( V_27 , V_29 ) ;
} else
memset ( V_28 , 0 , V_24 ) ;
}
}
static int F_28 ( struct V_2 * V_3 , struct V_1 * V_1 ,
unsigned int V_30 , unsigned int V_31 , int V_32 ,
T_1 V_4 )
{
void * V_33 ;
int V_34 = 0 ;
if ( V_32 != V_35 ) {
V_34 = F_21 ( V_3 , V_4 , V_30 ) ;
if ( V_34 )
goto V_36;
}
V_33 = F_25 ( V_1 , V_37 ) ;
if ( V_32 == V_35 ) {
F_27 ( V_33 + V_31 , V_3 , V_4 , V_30 ) ;
F_29 ( V_1 ) ;
} else {
F_29 ( V_1 ) ;
F_24 ( V_3 , V_33 + V_31 , V_4 , V_30 ) ;
}
F_26 ( V_33 , V_37 ) ;
V_36:
return V_34 ;
}
static int F_30 ( struct V_38 * V_39 , struct V_40 * V_40 )
{
struct V_41 * V_42 = V_40 -> V_43 ;
struct V_2 * V_3 = V_42 -> V_44 -> V_45 ;
int V_32 ;
struct V_46 * V_47 ;
T_1 V_4 ;
int V_18 ;
int V_34 = - V_48 ;
V_4 = V_40 -> V_49 ;
if ( V_4 + ( V_40 -> V_50 >> V_23 ) >
F_31 ( V_42 -> V_44 ) )
goto V_36;
if ( F_32 ( V_40 -> V_51 & V_52 ) ) {
V_34 = 0 ;
F_23 ( V_3 , V_4 , V_40 -> V_50 ) ;
goto V_36;
}
V_32 = F_33 ( V_40 ) ;
if ( V_32 == V_53 )
V_32 = V_35 ;
F_34 (bvec, bio, i) {
unsigned int V_30 = V_47 -> V_54 ;
V_34 = F_28 ( V_3 , V_47 -> V_55 , V_30 ,
V_47 -> V_56 , V_32 , V_4 ) ;
if ( V_34 )
break;
V_4 += V_30 >> V_23 ;
}
V_36:
F_35 ( V_40 , V_34 ) ;
return 0 ;
}
static int F_36 ( struct V_41 * V_42 , T_1 V_4 ,
void * * V_57 , unsigned long * V_58 )
{
struct V_2 * V_3 = V_42 -> V_44 -> V_45 ;
struct V_1 * V_1 ;
if ( ! V_3 )
return - V_59 ;
if ( V_4 & ( V_22 - 1 ) )
return - V_60 ;
if ( V_4 + V_22 > F_31 ( V_42 -> V_44 ) )
return - V_61 ;
V_1 = F_6 ( V_3 , V_4 ) ;
if ( ! V_1 )
return - V_26 ;
* V_57 = F_37 ( V_1 ) ;
* V_58 = F_38 ( V_1 ) ;
return 0 ;
}
static int F_39 ( struct V_41 * V_42 , T_5 V_62 ,
unsigned int V_63 , unsigned long V_64 )
{
int error ;
struct V_2 * V_3 = V_42 -> V_44 -> V_45 ;
if ( V_63 != V_65 )
return - V_66 ;
F_40 ( & V_67 ) ;
F_40 ( & V_42 -> V_68 ) ;
error = - V_69 ;
if ( V_42 -> V_70 <= 1 ) {
F_41 () ;
F_42 ( V_42 -> V_71 -> V_72 , 0 ) ;
F_19 ( V_3 ) ;
error = 0 ;
}
F_43 ( & V_42 -> V_68 ) ;
F_43 ( & V_67 ) ;
return error ;
}
static int T_6 F_44 ( char * V_73 )
{
V_74 = F_45 ( V_73 , NULL , 0 ) ;
return 1 ;
}
static struct V_2 * F_46 ( int V_18 )
{
struct V_2 * V_3 ;
struct V_75 * V_76 ;
V_3 = F_47 ( sizeof( * V_3 ) , V_77 ) ;
if ( ! V_3 )
goto V_36;
V_3 -> V_78 = V_18 ;
F_48 ( & V_3 -> V_13 ) ;
F_49 ( & V_3 -> V_7 , V_79 ) ;
V_3 -> V_80 = F_50 ( V_77 ) ;
if ( ! V_3 -> V_80 )
goto V_81;
F_51 ( V_3 -> V_80 , F_30 ) ;
F_52 ( V_3 -> V_80 , 1024 ) ;
F_53 ( V_3 -> V_80 , V_82 ) ;
V_3 -> V_80 -> V_83 . V_84 = V_25 ;
V_3 -> V_80 -> V_83 . V_85 = V_86 ;
V_3 -> V_80 -> V_83 . V_87 = 1 ;
F_54 ( V_88 , V_3 -> V_80 ) ;
V_76 = V_3 -> V_89 = F_55 ( 1 << V_90 ) ;
if ( ! V_76 )
goto V_91;
V_76 -> V_92 = V_93 ;
V_76 -> V_94 = V_18 << V_90 ;
V_76 -> V_95 = & V_96 ;
V_76 -> V_45 = V_3 ;
V_76 -> V_97 = V_3 -> V_80 ;
V_76 -> V_98 |= V_99 ;
sprintf ( V_76 -> V_100 , L_1 , V_18 ) ;
F_56 ( V_76 , V_74 * 2 ) ;
return V_3 ;
V_91:
F_57 ( V_3 -> V_80 ) ;
V_81:
F_58 ( V_3 ) ;
V_36:
return NULL ;
}
static void F_59 ( struct V_2 * V_3 )
{
F_60 ( V_3 -> V_89 ) ;
F_57 ( V_3 -> V_80 ) ;
F_19 ( V_3 ) ;
F_58 ( V_3 ) ;
}
static struct V_2 * F_61 ( int V_18 )
{
struct V_2 * V_3 ;
F_62 (brd, &brd_devices, brd_list) {
if ( V_3 -> V_78 == V_18 )
goto V_36;
}
V_3 = F_46 ( V_18 ) ;
if ( V_3 ) {
F_63 ( V_3 -> V_89 ) ;
F_64 ( & V_3 -> V_101 , & V_102 ) ;
}
V_36:
return V_3 ;
}
static void F_65 ( struct V_2 * V_3 )
{
F_66 ( & V_3 -> V_101 ) ;
F_67 ( V_3 -> V_89 ) ;
F_59 ( V_3 ) ;
}
static struct V_103 * F_68 ( T_7 V_104 , int * V_105 , void * V_106 )
{
struct V_2 * V_3 ;
struct V_103 * V_107 ;
F_40 ( & V_108 ) ;
V_3 = F_61 ( F_69 ( V_104 ) >> V_90 ) ;
V_107 = V_3 ? F_70 ( V_3 -> V_89 ) : F_71 ( - V_26 ) ;
F_43 ( & V_108 ) ;
* V_105 = 0 ;
return V_107 ;
}
static int T_6 F_72 ( void )
{
int V_18 , V_109 ;
unsigned long V_110 ;
struct V_2 * V_3 , * V_111 ;
V_90 = 0 ;
if ( V_112 > 0 ) {
V_90 = F_73 ( V_112 ) ;
V_112 = ( 1UL << V_90 ) - 1 ;
}
if ( ( 1UL << V_90 ) > V_113 )
return - V_60 ;
if ( V_114 > 1UL << ( V_115 - V_90 ) )
return - V_60 ;
if ( V_114 ) {
V_109 = V_114 ;
V_110 = V_114 << V_90 ;
} else {
V_109 = V_116 ;
V_110 = 1UL << V_115 ;
}
if ( F_74 ( V_93 , L_2 ) )
return - V_48 ;
for ( V_18 = 0 ; V_18 < V_109 ; V_18 ++ ) {
V_3 = F_46 ( V_18 ) ;
if ( ! V_3 )
goto V_117;
F_64 ( & V_3 -> V_101 , & V_102 ) ;
}
F_62 (brd, &brd_devices, brd_list)
F_63 ( V_3 -> V_89 ) ;
F_75 ( F_76 ( V_93 , 0 ) , V_110 ,
V_118 , F_68 , NULL , NULL ) ;
F_77 ( V_119 L_3 ) ;
return 0 ;
V_117:
F_78 (brd, next, &brd_devices, brd_list) {
F_66 ( & V_3 -> V_101 ) ;
F_59 ( V_3 ) ;
}
F_79 ( V_93 , L_2 ) ;
return - V_26 ;
}
static void T_8 F_80 ( void )
{
unsigned long V_110 ;
struct V_2 * V_3 , * V_111 ;
V_110 = V_114 ? V_114 << V_90 : 1UL << V_115 ;
F_78 (brd, next, &brd_devices, brd_list)
F_65 ( V_3 ) ;
F_81 ( F_76 ( V_93 , 0 ) , V_110 ) ;
F_79 ( V_93 , L_2 ) ;
}
