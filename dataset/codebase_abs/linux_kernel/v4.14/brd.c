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
static void F_15 ( struct V_2 * V_3 )
{
unsigned long V_14 = 0 ;
struct V_1 * V_15 [ V_16 ] ;
int V_17 ;
do {
int V_18 ;
V_17 = F_16 ( & V_3 -> V_7 ,
( void * * ) V_15 , V_14 , V_16 ) ;
for ( V_18 = 0 ; V_18 < V_17 ; V_18 ++ ) {
void * V_19 ;
F_5 ( V_15 [ V_18 ] -> V_8 < V_14 ) ;
V_14 = V_15 [ V_18 ] -> V_8 ;
V_19 = F_17 ( & V_3 -> V_7 , V_14 ) ;
F_5 ( ! V_19 || V_19 != V_15 [ V_18 ] ) ;
F_10 ( V_15 [ V_18 ] ) ;
}
V_14 ++ ;
} while ( V_17 == V_16 );
}
static int F_18 ( struct V_2 * V_3 , T_1 V_4 , T_4 V_20 )
{
unsigned int V_21 = ( V_4 & ( V_22 - 1 ) ) << V_23 ;
T_4 V_24 ;
V_24 = F_19 ( T_4 , V_20 , V_25 - V_21 ) ;
if ( ! F_6 ( V_3 , V_4 ) )
return - V_26 ;
if ( V_24 < V_20 ) {
V_4 += V_24 >> V_23 ;
if ( ! F_6 ( V_3 , V_4 ) )
return - V_26 ;
}
return 0 ;
}
static void F_20 ( struct V_2 * V_3 , const void * V_27 ,
T_1 V_4 , T_4 V_20 )
{
struct V_1 * V_1 ;
void * V_28 ;
unsigned int V_21 = ( V_4 & ( V_22 - 1 ) ) << V_23 ;
T_4 V_24 ;
V_24 = F_19 ( T_4 , V_20 , V_25 - V_21 ) ;
V_1 = F_1 ( V_3 , V_4 ) ;
F_5 ( ! V_1 ) ;
V_28 = F_21 ( V_1 ) ;
memcpy ( V_28 + V_21 , V_27 , V_24 ) ;
F_22 ( V_28 ) ;
if ( V_24 < V_20 ) {
V_27 += V_24 ;
V_4 += V_24 >> V_23 ;
V_24 = V_20 - V_24 ;
V_1 = F_1 ( V_3 , V_4 ) ;
F_5 ( ! V_1 ) ;
V_28 = F_21 ( V_1 ) ;
memcpy ( V_28 , V_27 , V_24 ) ;
F_22 ( V_28 ) ;
}
}
static void F_23 ( void * V_28 , struct V_2 * V_3 ,
T_1 V_4 , T_4 V_20 )
{
struct V_1 * V_1 ;
void * V_27 ;
unsigned int V_21 = ( V_4 & ( V_22 - 1 ) ) << V_23 ;
T_4 V_24 ;
V_24 = F_19 ( T_4 , V_20 , V_25 - V_21 ) ;
V_1 = F_1 ( V_3 , V_4 ) ;
if ( V_1 ) {
V_27 = F_21 ( V_1 ) ;
memcpy ( V_28 , V_27 + V_21 , V_24 ) ;
F_22 ( V_27 ) ;
} else
memset ( V_28 , 0 , V_24 ) ;
if ( V_24 < V_20 ) {
V_28 += V_24 ;
V_4 += V_24 >> V_23 ;
V_24 = V_20 - V_24 ;
V_1 = F_1 ( V_3 , V_4 ) ;
if ( V_1 ) {
V_27 = F_21 ( V_1 ) ;
memcpy ( V_28 , V_27 , V_24 ) ;
F_22 ( V_27 ) ;
} else
memset ( V_28 , 0 , V_24 ) ;
}
}
static int F_24 ( struct V_2 * V_3 , struct V_1 * V_1 ,
unsigned int V_29 , unsigned int V_30 , bool V_31 ,
T_1 V_4 )
{
void * V_32 ;
int V_33 = 0 ;
if ( V_31 ) {
V_33 = F_18 ( V_3 , V_4 , V_29 ) ;
if ( V_33 )
goto V_34;
}
V_32 = F_21 ( V_1 ) ;
if ( ! V_31 ) {
F_23 ( V_32 + V_30 , V_3 , V_4 , V_29 ) ;
F_25 ( V_1 ) ;
} else {
F_25 ( V_1 ) ;
F_20 ( V_3 , V_32 + V_30 , V_4 , V_29 ) ;
}
F_22 ( V_32 ) ;
V_34:
return V_33 ;
}
static T_5 F_26 ( struct V_35 * V_36 , struct V_37 * V_37 )
{
struct V_2 * V_3 = V_37 -> V_38 -> V_39 ;
struct V_40 V_41 ;
T_1 V_4 ;
struct V_42 V_43 ;
V_4 = V_37 -> V_44 . V_45 ;
if ( F_27 ( V_37 ) > F_28 ( V_37 -> V_38 ) )
goto V_46;
F_29 (bvec, bio, iter) {
unsigned int V_29 = V_41 . V_47 ;
int V_33 ;
V_33 = F_24 ( V_3 , V_41 . V_48 , V_29 , V_41 . V_49 ,
F_30 ( F_31 ( V_37 ) ) , V_4 ) ;
if ( V_33 )
goto V_46;
V_4 += V_29 >> V_23 ;
}
F_32 ( V_37 ) ;
return V_50 ;
V_46:
F_33 ( V_37 ) ;
return V_50 ;
}
static int F_34 ( struct V_51 * V_52 , T_1 V_4 ,
struct V_1 * V_1 , bool V_31 )
{
struct V_2 * V_3 = V_52 -> V_53 -> V_39 ;
int V_33 ;
if ( F_35 ( V_1 ) )
return - V_54 ;
V_33 = F_24 ( V_3 , V_1 , V_25 , 0 , V_31 , V_4 ) ;
F_36 ( V_1 , V_31 , V_33 ) ;
return V_33 ;
}
static long F_37 ( struct V_2 * V_3 , T_2 V_55 ,
long V_17 , void * * V_56 , T_6 * V_57 )
{
struct V_1 * V_1 ;
if ( ! V_3 )
return - V_58 ;
V_1 = F_6 ( V_3 , ( T_1 ) V_55 << V_6 ) ;
if ( ! V_1 )
return - V_26 ;
* V_56 = F_38 ( V_1 ) ;
* V_57 = F_39 ( V_1 ) ;
return 1 ;
}
static long F_40 ( struct V_59 * V_60 ,
T_2 V_55 , long V_17 , void * * V_56 , T_6 * V_57 )
{
struct V_2 * V_3 = F_41 ( V_60 ) ;
return F_37 ( V_3 , V_55 , V_17 , V_56 , V_57 ) ;
}
static T_4 F_42 ( struct V_59 * V_60 , T_2 V_55 ,
void * V_61 , T_4 V_62 , struct V_63 * V_18 )
{
return F_43 ( V_61 , V_62 , V_18 ) ;
}
static int T_7 F_44 ( char * V_64 )
{
V_65 = F_45 ( V_64 , NULL , 0 ) ;
return 1 ;
}
static struct V_2 * F_46 ( int V_18 )
{
struct V_2 * V_3 ;
struct V_66 * V_67 ;
V_3 = F_47 ( sizeof( * V_3 ) , V_68 ) ;
if ( ! V_3 )
goto V_34;
V_3 -> V_69 = V_18 ;
F_48 ( & V_3 -> V_13 ) ;
F_49 ( & V_3 -> V_7 , V_70 ) ;
V_3 -> V_71 = F_50 ( V_68 ) ;
if ( ! V_3 -> V_71 )
goto V_72;
F_51 ( V_3 -> V_71 , F_26 ) ;
F_52 ( V_3 -> V_71 , 1024 ) ;
F_53 ( V_3 -> V_71 , V_25 ) ;
V_67 = V_3 -> V_73 = F_54 ( V_74 ) ;
if ( ! V_67 )
goto V_75;
V_67 -> V_76 = V_77 ;
V_67 -> V_78 = V_18 * V_74 ;
V_67 -> V_79 = & V_80 ;
V_67 -> V_39 = V_3 ;
V_67 -> V_81 = V_3 -> V_71 ;
V_67 -> V_82 = V_83 ;
sprintf ( V_67 -> V_84 , L_1 , V_18 ) ;
F_55 ( V_67 , V_65 * 2 ) ;
#ifdef F_7
F_56 ( V_85 , V_3 -> V_71 ) ;
V_3 -> V_60 = F_57 ( V_3 , V_67 -> V_84 , & V_86 ) ;
if ( ! V_3 -> V_60 )
goto V_87;
#endif
return V_3 ;
#ifdef F_7
V_87:
F_58 ( V_3 -> V_60 ) ;
F_59 ( V_3 -> V_60 ) ;
#endif
V_75:
F_60 ( V_3 -> V_71 ) ;
V_72:
F_61 ( V_3 ) ;
V_34:
return NULL ;
}
static void F_62 ( struct V_2 * V_3 )
{
F_63 ( V_3 -> V_73 ) ;
F_60 ( V_3 -> V_71 ) ;
F_15 ( V_3 ) ;
F_61 ( V_3 ) ;
}
static struct V_2 * F_64 ( int V_18 , bool * V_88 )
{
struct V_2 * V_3 ;
* V_88 = false ;
F_65 (brd, &brd_devices, brd_list) {
if ( V_3 -> V_69 == V_18 )
goto V_34;
}
V_3 = F_46 ( V_18 ) ;
if ( V_3 ) {
F_66 ( V_3 -> V_73 ) ;
F_67 ( & V_3 -> V_89 , & V_90 ) ;
}
* V_88 = true ;
V_34:
return V_3 ;
}
static void F_68 ( struct V_2 * V_3 )
{
F_69 ( & V_3 -> V_89 ) ;
#ifdef F_7
F_58 ( V_3 -> V_60 ) ;
F_59 ( V_3 -> V_60 ) ;
#endif
F_70 ( V_3 -> V_73 ) ;
F_62 ( V_3 ) ;
}
static struct V_91 * F_71 ( T_8 V_92 , int * V_93 , void * V_94 )
{
struct V_2 * V_3 ;
struct V_91 * V_95 ;
bool V_88 ;
F_72 ( & V_96 ) ;
V_3 = F_64 ( F_73 ( V_92 ) / V_74 , & V_88 ) ;
V_95 = V_3 ? F_74 ( V_3 -> V_73 ) : NULL ;
F_75 ( & V_96 ) ;
if ( V_88 )
* V_93 = 0 ;
return V_95 ;
}
static int T_7 F_76 ( void )
{
struct V_2 * V_3 , * V_97 ;
int V_18 ;
if ( F_77 ( V_77 , L_2 ) )
return - V_98 ;
if ( F_78 ( ! V_74 ) )
V_74 = 1 ;
for ( V_18 = 0 ; V_18 < V_99 ; V_18 ++ ) {
V_3 = F_46 ( V_18 ) ;
if ( ! V_3 )
goto V_100;
F_67 ( & V_3 -> V_89 , & V_90 ) ;
}
F_65 (brd, &brd_devices, brd_list)
F_66 ( V_3 -> V_73 ) ;
F_79 ( F_80 ( V_77 , 0 ) , 1UL << V_101 ,
V_102 , F_71 , NULL , NULL ) ;
F_81 ( L_3 ) ;
return 0 ;
V_100:
F_82 (brd, next, &brd_devices, brd_list) {
F_69 ( & V_3 -> V_89 ) ;
F_62 ( V_3 ) ;
}
F_83 ( V_77 , L_2 ) ;
F_81 ( L_4 ) ;
return - V_103 ;
}
static void T_9 F_84 ( void )
{
struct V_2 * V_3 , * V_97 ;
F_82 (brd, next, &brd_devices, brd_list)
F_68 ( V_3 ) ;
F_85 ( F_80 ( V_77 , 0 ) , 1UL << V_101 ) ;
F_83 ( V_77 , L_2 ) ;
F_81 ( L_5 ) ;
}
