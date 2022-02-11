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
unsigned int V_29 , unsigned int V_30 , bool V_31 ,
T_1 V_4 )
{
void * V_32 ;
int V_33 = 0 ;
if ( V_31 ) {
V_33 = F_21 ( V_3 , V_4 , V_29 ) ;
if ( V_33 )
goto V_34;
}
V_32 = F_25 ( V_1 ) ;
if ( ! V_31 ) {
F_27 ( V_32 + V_30 , V_3 , V_4 , V_29 ) ;
F_29 ( V_1 ) ;
} else {
F_29 ( V_1 ) ;
F_24 ( V_3 , V_32 + V_30 , V_4 , V_29 ) ;
}
F_26 ( V_32 ) ;
V_34:
return V_33 ;
}
static T_5 F_30 ( struct V_35 * V_36 , struct V_37 * V_37 )
{
struct V_38 * V_39 = V_37 -> V_40 ;
struct V_2 * V_3 = V_39 -> V_41 -> V_42 ;
struct V_43 V_44 ;
T_1 V_4 ;
struct V_45 V_46 ;
V_4 = V_37 -> V_47 . V_48 ;
if ( F_31 ( V_37 ) > F_32 ( V_39 -> V_41 ) )
goto V_49;
if ( F_33 ( F_34 ( V_37 ) == V_50 ) ) {
if ( V_4 & ( ( V_25 >> V_23 ) - 1 ) ||
V_37 -> V_47 . V_51 & ~ V_52 )
goto V_49;
F_23 ( V_3 , V_4 , V_37 -> V_47 . V_51 ) ;
goto V_34;
}
F_35 (bvec, bio, iter) {
unsigned int V_29 = V_44 . V_53 ;
int V_33 ;
V_33 = F_28 ( V_3 , V_44 . V_54 , V_29 , V_44 . V_55 ,
F_36 ( F_34 ( V_37 ) ) , V_4 ) ;
if ( V_33 )
goto V_49;
V_4 += V_29 >> V_23 ;
}
V_34:
F_37 ( V_37 ) ;
return V_56 ;
V_49:
F_38 ( V_37 ) ;
return V_56 ;
}
static int F_39 ( struct V_38 * V_39 , T_1 V_4 ,
struct V_1 * V_1 , bool V_31 )
{
struct V_2 * V_3 = V_39 -> V_41 -> V_42 ;
int V_33 = F_28 ( V_3 , V_1 , V_25 , 0 , V_31 , V_4 ) ;
F_40 ( V_1 , V_31 , V_33 ) ;
return V_33 ;
}
static long F_41 ( struct V_38 * V_39 , T_1 V_4 ,
void * * V_57 , T_6 * V_58 , long V_59 )
{
struct V_2 * V_3 = V_39 -> V_41 -> V_42 ;
struct V_1 * V_1 ;
if ( ! V_3 )
return - V_60 ;
V_1 = F_6 ( V_3 , V_4 ) ;
if ( ! V_1 )
return - V_26 ;
* V_57 = F_42 ( V_1 ) ;
* V_58 = F_43 ( V_1 ) ;
return V_25 ;
}
static int F_44 ( struct V_38 * V_39 , T_7 V_61 ,
unsigned int V_62 , unsigned long V_63 )
{
int error ;
struct V_2 * V_3 = V_39 -> V_41 -> V_42 ;
if ( V_62 != V_64 )
return - V_65 ;
F_45 ( & V_66 ) ;
F_45 ( & V_39 -> V_67 ) ;
error = - V_68 ;
if ( V_39 -> V_69 <= 1 ) {
F_46 ( V_39 ) ;
F_19 ( V_3 ) ;
error = 0 ;
}
F_47 ( & V_39 -> V_67 ) ;
F_47 ( & V_66 ) ;
return error ;
}
static int T_8 F_48 ( char * V_70 )
{
V_71 = F_49 ( V_70 , NULL , 0 ) ;
return 1 ;
}
static struct V_2 * F_50 ( int V_18 )
{
struct V_2 * V_3 ;
struct V_72 * V_73 ;
V_3 = F_51 ( sizeof( * V_3 ) , V_74 ) ;
if ( ! V_3 )
goto V_34;
V_3 -> V_75 = V_18 ;
F_52 ( & V_3 -> V_13 ) ;
F_53 ( & V_3 -> V_7 , V_76 ) ;
V_3 -> V_77 = F_54 ( V_74 ) ;
if ( ! V_3 -> V_77 )
goto V_78;
F_55 ( V_3 -> V_77 , F_30 ) ;
F_56 ( V_3 -> V_77 , 1024 ) ;
F_57 ( V_3 -> V_77 , V_79 ) ;
F_58 ( V_3 -> V_77 , V_25 ) ;
V_3 -> V_77 -> V_80 . V_81 = V_25 ;
F_59 ( V_3 -> V_77 , V_82 ) ;
V_3 -> V_77 -> V_80 . V_83 = 1 ;
F_60 ( V_84 , V_3 -> V_77 ) ;
#ifdef F_7
F_60 ( V_85 , V_3 -> V_77 ) ;
#endif
V_73 = V_3 -> V_86 = F_61 ( V_87 ) ;
if ( ! V_73 )
goto V_88;
V_73 -> V_89 = V_90 ;
V_73 -> V_91 = V_18 * V_87 ;
V_73 -> V_92 = & V_93 ;
V_73 -> V_42 = V_3 ;
V_73 -> V_94 = V_3 -> V_77 ;
V_73 -> V_95 = V_96 ;
sprintf ( V_73 -> V_97 , L_1 , V_18 ) ;
F_62 ( V_73 , V_71 * 2 ) ;
return V_3 ;
V_88:
F_63 ( V_3 -> V_77 ) ;
V_78:
F_64 ( V_3 ) ;
V_34:
return NULL ;
}
static void F_65 ( struct V_2 * V_3 )
{
F_66 ( V_3 -> V_86 ) ;
F_63 ( V_3 -> V_77 ) ;
F_19 ( V_3 ) ;
F_64 ( V_3 ) ;
}
static struct V_2 * F_67 ( int V_18 , bool * V_98 )
{
struct V_2 * V_3 ;
* V_98 = false ;
F_68 (brd, &brd_devices, brd_list) {
if ( V_3 -> V_75 == V_18 )
goto V_34;
}
V_3 = F_50 ( V_18 ) ;
if ( V_3 ) {
F_69 ( V_3 -> V_86 ) ;
F_70 ( & V_3 -> V_99 , & V_100 ) ;
}
* V_98 = true ;
V_34:
return V_3 ;
}
static void F_71 ( struct V_2 * V_3 )
{
F_72 ( & V_3 -> V_99 ) ;
F_73 ( V_3 -> V_86 ) ;
F_65 ( V_3 ) ;
}
static struct V_101 * F_74 ( T_9 V_102 , int * V_103 , void * V_104 )
{
struct V_2 * V_3 ;
struct V_101 * V_105 ;
bool V_98 ;
F_45 ( & V_106 ) ;
V_3 = F_67 ( F_75 ( V_102 ) / V_87 , & V_98 ) ;
V_105 = V_3 ? F_76 ( V_3 -> V_86 ) : NULL ;
F_47 ( & V_106 ) ;
if ( V_98 )
* V_103 = 0 ;
return V_105 ;
}
static int T_8 F_77 ( void )
{
struct V_2 * V_3 , * V_107 ;
int V_18 ;
if ( F_78 ( V_90 , L_2 ) )
return - V_108 ;
if ( F_33 ( ! V_87 ) )
V_87 = 1 ;
for ( V_18 = 0 ; V_18 < V_109 ; V_18 ++ ) {
V_3 = F_50 ( V_18 ) ;
if ( ! V_3 )
goto V_110;
F_70 ( & V_3 -> V_99 , & V_100 ) ;
}
F_68 (brd, &brd_devices, brd_list)
F_69 ( V_3 -> V_86 ) ;
F_79 ( F_80 ( V_90 , 0 ) , 1UL << V_111 ,
V_112 , F_74 , NULL , NULL ) ;
F_81 ( L_3 ) ;
return 0 ;
V_110:
F_82 (brd, next, &brd_devices, brd_list) {
F_72 ( & V_3 -> V_99 ) ;
F_65 ( V_3 ) ;
}
F_83 ( V_90 , L_2 ) ;
F_81 ( L_4 ) ;
return - V_113 ;
}
static void T_10 F_84 ( void )
{
struct V_2 * V_3 , * V_107 ;
F_82 (brd, next, &brd_devices, brd_list)
F_71 ( V_3 ) ;
F_85 ( F_80 ( V_90 , 0 ) , 1UL << V_111 ) ;
F_83 ( V_90 , L_2 ) ;
F_81 ( L_5 ) ;
}
