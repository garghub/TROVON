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
static void F_30 ( struct V_38 * V_39 , struct V_40 * V_40 )
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
F_41 ( V_42 ) ;
F_19 ( V_3 ) ;
error = 0 ;
}
F_42 ( & V_42 -> V_68 ) ;
F_42 ( & V_67 ) ;
return error ;
}
static int T_6 F_43 ( char * V_71 )
{
V_72 = F_44 ( V_71 , NULL , 0 ) ;
return 1 ;
}
static struct V_2 * F_45 ( int V_18 )
{
struct V_2 * V_3 ;
struct V_73 * V_74 ;
V_3 = F_46 ( sizeof( * V_3 ) , V_75 ) ;
if ( ! V_3 )
goto V_36;
V_3 -> V_76 = V_18 ;
F_47 ( & V_3 -> V_13 ) ;
F_48 ( & V_3 -> V_7 , V_77 ) ;
V_3 -> V_78 = F_49 ( V_75 ) ;
if ( ! V_3 -> V_78 )
goto V_79;
F_50 ( V_3 -> V_78 , F_30 ) ;
F_51 ( V_3 -> V_78 , 1024 ) ;
F_52 ( V_3 -> V_78 , V_80 ) ;
V_3 -> V_78 -> V_81 . V_82 = V_25 ;
V_3 -> V_78 -> V_81 . V_83 = V_84 ;
V_3 -> V_78 -> V_81 . V_85 = 1 ;
F_53 ( V_86 , V_3 -> V_78 ) ;
V_74 = V_3 -> V_87 = F_54 ( 1 << V_88 ) ;
if ( ! V_74 )
goto V_89;
V_74 -> V_90 = V_91 ;
V_74 -> V_92 = V_18 << V_88 ;
V_74 -> V_93 = & V_94 ;
V_74 -> V_45 = V_3 ;
V_74 -> V_95 = V_3 -> V_78 ;
V_74 -> V_96 |= V_97 ;
sprintf ( V_74 -> V_98 , L_1 , V_18 ) ;
F_55 ( V_74 , V_72 * 2 ) ;
return V_3 ;
V_89:
F_56 ( V_3 -> V_78 ) ;
V_79:
F_57 ( V_3 ) ;
V_36:
return NULL ;
}
static void F_58 ( struct V_2 * V_3 )
{
F_59 ( V_3 -> V_87 ) ;
F_56 ( V_3 -> V_78 ) ;
F_19 ( V_3 ) ;
F_57 ( V_3 ) ;
}
static struct V_2 * F_60 ( int V_18 )
{
struct V_2 * V_3 ;
F_61 (brd, &brd_devices, brd_list) {
if ( V_3 -> V_76 == V_18 )
goto V_36;
}
V_3 = F_45 ( V_18 ) ;
if ( V_3 ) {
F_62 ( V_3 -> V_87 ) ;
F_63 ( & V_3 -> V_99 , & V_100 ) ;
}
V_36:
return V_3 ;
}
static void F_64 ( struct V_2 * V_3 )
{
F_65 ( & V_3 -> V_99 ) ;
F_66 ( V_3 -> V_87 ) ;
F_58 ( V_3 ) ;
}
static struct V_101 * F_67 ( T_7 V_102 , int * V_103 , void * V_104 )
{
struct V_2 * V_3 ;
struct V_101 * V_105 ;
F_40 ( & V_106 ) ;
V_3 = F_60 ( F_68 ( V_102 ) >> V_88 ) ;
V_105 = V_3 ? F_69 ( V_3 -> V_87 ) : F_70 ( - V_26 ) ;
F_42 ( & V_106 ) ;
* V_103 = 0 ;
return V_105 ;
}
static int T_6 F_71 ( void )
{
int V_18 , V_107 ;
unsigned long V_108 ;
struct V_2 * V_3 , * V_109 ;
V_88 = 0 ;
if ( V_110 > 0 ) {
V_88 = F_72 ( V_110 ) ;
V_110 = ( 1UL << V_88 ) - 1 ;
}
if ( ( 1UL << V_88 ) > V_111 )
return - V_60 ;
if ( V_112 > 1UL << ( V_113 - V_88 ) )
return - V_60 ;
if ( V_112 ) {
V_107 = V_112 ;
V_108 = V_112 << V_88 ;
} else {
V_107 = V_114 ;
V_108 = 1UL << V_113 ;
}
if ( F_73 ( V_91 , L_2 ) )
return - V_48 ;
for ( V_18 = 0 ; V_18 < V_107 ; V_18 ++ ) {
V_3 = F_45 ( V_18 ) ;
if ( ! V_3 )
goto V_115;
F_63 ( & V_3 -> V_99 , & V_100 ) ;
}
F_61 (brd, &brd_devices, brd_list)
F_62 ( V_3 -> V_87 ) ;
F_74 ( F_75 ( V_91 , 0 ) , V_108 ,
V_116 , F_67 , NULL , NULL ) ;
F_76 ( V_117 L_3 ) ;
return 0 ;
V_115:
F_77 (brd, next, &brd_devices, brd_list) {
F_65 ( & V_3 -> V_99 ) ;
F_58 ( V_3 ) ;
}
F_78 ( V_91 , L_2 ) ;
return - V_26 ;
}
static void T_8 F_79 ( void )
{
unsigned long V_108 ;
struct V_2 * V_3 , * V_109 ;
V_108 = V_112 ? V_112 << V_88 : 1UL << V_113 ;
F_77 (brd, next, &brd_devices, brd_list)
F_64 ( V_3 ) ;
F_80 ( F_75 ( V_91 , 0 ) , V_108 ) ;
F_78 ( V_91 , L_2 ) ;
}
