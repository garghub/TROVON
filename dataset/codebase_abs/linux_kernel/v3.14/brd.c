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
V_1 -> V_8 = V_5 ;
if ( F_12 ( & V_3 -> V_7 , V_5 , V_1 ) ) {
F_10 ( V_1 ) ;
V_1 = F_3 ( & V_3 -> V_7 , V_5 ) ;
F_5 ( ! V_1 ) ;
F_5 ( V_1 -> V_8 != V_5 ) ;
}
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
V_28 = F_25 ( V_1 ) ;
memcpy ( V_28 + V_21 , V_27 , V_24 ) ;
F_26 ( V_28 ) ;
if ( V_24 < V_20 ) {
V_27 += V_24 ;
V_4 += V_24 >> V_23 ;
V_24 = V_20 - V_24 ;
V_1 = F_1 ( V_3 , V_4 ) ;
F_5 ( ! V_1 ) ;
V_28 = F_25 ( V_1 ) ;
memcpy ( V_28 , V_27 , V_24 ) ;
F_26 ( V_28 ) ;
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
V_27 = F_25 ( V_1 ) ;
memcpy ( V_28 , V_27 + V_21 , V_24 ) ;
F_26 ( V_27 ) ;
} else
memset ( V_28 , 0 , V_24 ) ;
if ( V_24 < V_20 ) {
V_28 += V_24 ;
V_4 += V_24 >> V_23 ;
V_24 = V_20 - V_24 ;
V_1 = F_1 ( V_3 , V_4 ) ;
if ( V_1 ) {
V_27 = F_25 ( V_1 ) ;
memcpy ( V_28 , V_27 , V_24 ) ;
F_26 ( V_27 ) ;
} else
memset ( V_28 , 0 , V_24 ) ;
}
}
static int F_28 ( struct V_2 * V_3 , struct V_1 * V_1 ,
unsigned int V_29 , unsigned int V_30 , int V_31 ,
T_1 V_4 )
{
void * V_32 ;
int V_33 = 0 ;
if ( V_31 != V_34 ) {
V_33 = F_21 ( V_3 , V_4 , V_29 ) ;
if ( V_33 )
goto V_35;
}
V_32 = F_25 ( V_1 ) ;
if ( V_31 == V_34 ) {
F_27 ( V_32 + V_30 , V_3 , V_4 , V_29 ) ;
F_29 ( V_1 ) ;
} else {
F_29 ( V_1 ) ;
F_24 ( V_3 , V_32 + V_30 , V_4 , V_29 ) ;
}
F_26 ( V_32 ) ;
V_35:
return V_33 ;
}
static void F_30 ( struct V_36 * V_37 , struct V_38 * V_38 )
{
struct V_39 * V_40 = V_38 -> V_41 ;
struct V_2 * V_3 = V_40 -> V_42 -> V_43 ;
int V_31 ;
struct V_44 V_45 ;
T_1 V_4 ;
struct V_46 V_47 ;
int V_33 = - V_48 ;
V_4 = V_38 -> V_49 . V_50 ;
if ( F_31 ( V_38 ) > F_32 ( V_40 -> V_42 ) )
goto V_35;
if ( F_33 ( V_38 -> V_51 & V_52 ) ) {
V_33 = 0 ;
F_23 ( V_3 , V_4 , V_38 -> V_49 . V_53 ) ;
goto V_35;
}
V_31 = F_34 ( V_38 ) ;
if ( V_31 == V_54 )
V_31 = V_34 ;
F_35 (bvec, bio, iter) {
unsigned int V_29 = V_45 . V_55 ;
V_33 = F_28 ( V_3 , V_45 . V_56 , V_29 ,
V_45 . V_57 , V_31 , V_4 ) ;
if ( V_33 )
break;
V_4 += V_29 >> V_23 ;
}
V_35:
F_36 ( V_38 , V_33 ) ;
}
static int F_37 ( struct V_39 * V_40 , T_1 V_4 ,
void * * V_58 , unsigned long * V_59 )
{
struct V_2 * V_3 = V_40 -> V_42 -> V_43 ;
struct V_1 * V_1 ;
if ( ! V_3 )
return - V_60 ;
if ( V_4 & ( V_22 - 1 ) )
return - V_61 ;
if ( V_4 + V_22 > F_32 ( V_40 -> V_42 ) )
return - V_62 ;
V_1 = F_6 ( V_3 , V_4 ) ;
if ( ! V_1 )
return - V_26 ;
* V_58 = F_38 ( V_1 ) ;
* V_59 = F_39 ( V_1 ) ;
return 0 ;
}
static int F_40 ( struct V_39 * V_40 , T_5 V_63 ,
unsigned int V_64 , unsigned long V_65 )
{
int error ;
struct V_2 * V_3 = V_40 -> V_42 -> V_43 ;
if ( V_64 != V_66 )
return - V_67 ;
F_41 ( & V_68 ) ;
F_41 ( & V_40 -> V_69 ) ;
error = - V_70 ;
if ( V_40 -> V_71 <= 1 ) {
F_42 ( V_40 ) ;
F_19 ( V_3 ) ;
error = 0 ;
}
F_43 ( & V_40 -> V_69 ) ;
F_43 ( & V_68 ) ;
return error ;
}
static int T_6 F_44 ( char * V_72 )
{
V_73 = F_45 ( V_72 , NULL , 0 ) ;
return 1 ;
}
static struct V_2 * F_46 ( int V_18 )
{
struct V_2 * V_3 ;
struct V_74 * V_75 ;
V_3 = F_47 ( sizeof( * V_3 ) , V_76 ) ;
if ( ! V_3 )
goto V_35;
V_3 -> V_77 = V_18 ;
F_48 ( & V_3 -> V_13 ) ;
F_49 ( & V_3 -> V_7 , V_78 ) ;
V_3 -> V_79 = F_50 ( V_76 ) ;
if ( ! V_3 -> V_79 )
goto V_80;
F_51 ( V_3 -> V_79 , F_30 ) ;
F_52 ( V_3 -> V_79 , 1024 ) ;
F_53 ( V_3 -> V_79 , V_81 ) ;
V_3 -> V_79 -> V_82 . V_83 = V_25 ;
V_3 -> V_79 -> V_82 . V_84 = V_85 ;
V_3 -> V_79 -> V_82 . V_86 = 1 ;
F_54 ( V_87 , V_3 -> V_79 ) ;
V_75 = V_3 -> V_88 = F_55 ( 1 << V_89 ) ;
if ( ! V_75 )
goto V_90;
V_75 -> V_91 = V_92 ;
V_75 -> V_93 = V_18 << V_89 ;
V_75 -> V_94 = & V_95 ;
V_75 -> V_43 = V_3 ;
V_75 -> V_96 = V_3 -> V_79 ;
V_75 -> V_97 |= V_98 ;
sprintf ( V_75 -> V_99 , L_1 , V_18 ) ;
F_56 ( V_75 , V_73 * 2 ) ;
return V_3 ;
V_90:
F_57 ( V_3 -> V_79 ) ;
V_80:
F_58 ( V_3 ) ;
V_35:
return NULL ;
}
static void F_59 ( struct V_2 * V_3 )
{
F_60 ( V_3 -> V_88 ) ;
F_57 ( V_3 -> V_79 ) ;
F_19 ( V_3 ) ;
F_58 ( V_3 ) ;
}
static struct V_2 * F_61 ( int V_18 )
{
struct V_2 * V_3 ;
F_62 (brd, &brd_devices, brd_list) {
if ( V_3 -> V_77 == V_18 )
goto V_35;
}
V_3 = F_46 ( V_18 ) ;
if ( V_3 ) {
F_63 ( V_3 -> V_88 ) ;
F_64 ( & V_3 -> V_100 , & V_101 ) ;
}
V_35:
return V_3 ;
}
static void F_65 ( struct V_2 * V_3 )
{
F_66 ( & V_3 -> V_100 ) ;
F_67 ( V_3 -> V_88 ) ;
F_59 ( V_3 ) ;
}
static struct V_102 * F_68 ( T_7 V_103 , int * V_104 , void * V_105 )
{
struct V_2 * V_3 ;
struct V_102 * V_106 ;
F_41 ( & V_107 ) ;
V_3 = F_61 ( F_69 ( V_103 ) >> V_89 ) ;
V_106 = V_3 ? F_70 ( V_3 -> V_88 ) : NULL ;
F_43 ( & V_107 ) ;
* V_104 = 0 ;
return V_106 ;
}
static int T_6 F_71 ( void )
{
int V_18 , V_108 ;
unsigned long V_109 ;
struct V_2 * V_3 , * V_110 ;
V_89 = 0 ;
if ( V_111 > 0 ) {
V_89 = F_72 ( V_111 ) ;
V_111 = ( 1UL << V_89 ) - 1 ;
}
if ( ( 1UL << V_89 ) > V_112 )
return - V_61 ;
if ( V_113 > 1UL << ( V_114 - V_89 ) )
return - V_61 ;
if ( V_113 ) {
V_108 = V_113 ;
V_109 = V_113 << V_89 ;
} else {
V_108 = V_115 ;
V_109 = 1UL << V_114 ;
}
if ( F_73 ( V_92 , L_2 ) )
return - V_48 ;
for ( V_18 = 0 ; V_18 < V_108 ; V_18 ++ ) {
V_3 = F_46 ( V_18 ) ;
if ( ! V_3 )
goto V_116;
F_64 ( & V_3 -> V_100 , & V_101 ) ;
}
F_62 (brd, &brd_devices, brd_list)
F_63 ( V_3 -> V_88 ) ;
F_74 ( F_75 ( V_92 , 0 ) , V_109 ,
V_117 , F_68 , NULL , NULL ) ;
F_76 ( V_118 L_3 ) ;
return 0 ;
V_116:
F_77 (brd, next, &brd_devices, brd_list) {
F_66 ( & V_3 -> V_100 ) ;
F_59 ( V_3 ) ;
}
F_78 ( V_92 , L_2 ) ;
return - V_26 ;
}
static void T_8 F_79 ( void )
{
unsigned long V_109 ;
struct V_2 * V_3 , * V_110 ;
V_109 = V_113 ? V_113 << V_89 : 1UL << V_114 ;
F_77 (brd, next, &brd_devices, brd_list)
F_65 ( V_3 ) ;
F_80 ( F_75 ( V_92 , 0 ) , V_109 ) ;
F_78 ( V_92 , L_2 ) ;
}
