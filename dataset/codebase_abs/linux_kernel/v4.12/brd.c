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
struct V_38 * V_39 = V_37 -> V_40 ;
struct V_2 * V_3 = V_39 -> V_41 -> V_42 ;
struct V_43 V_44 ;
T_1 V_4 ;
struct V_45 V_46 ;
V_4 = V_37 -> V_47 . V_48 ;
if ( F_27 ( V_37 ) > F_28 ( V_39 -> V_41 ) )
goto V_49;
F_29 (bvec, bio, iter) {
unsigned int V_29 = V_44 . V_50 ;
int V_33 ;
V_33 = F_24 ( V_3 , V_44 . V_51 , V_29 , V_44 . V_52 ,
F_30 ( F_31 ( V_37 ) ) , V_4 ) ;
if ( V_33 )
goto V_49;
V_4 += V_29 >> V_23 ;
}
F_32 ( V_37 ) ;
return V_53 ;
V_49:
F_33 ( V_37 ) ;
return V_53 ;
}
static int F_34 ( struct V_38 * V_39 , T_1 V_4 ,
struct V_1 * V_1 , bool V_31 )
{
struct V_2 * V_3 = V_39 -> V_41 -> V_42 ;
int V_33 = F_24 ( V_3 , V_1 , V_25 , 0 , V_31 , V_4 ) ;
F_35 ( V_1 , V_31 , V_33 ) ;
return V_33 ;
}
static long F_36 ( struct V_2 * V_3 , T_2 V_54 ,
long V_17 , void * * V_55 , T_6 * V_56 )
{
struct V_1 * V_1 ;
if ( ! V_3 )
return - V_57 ;
V_1 = F_6 ( V_3 , F_37 ( V_54 ) / 512 ) ;
if ( ! V_1 )
return - V_26 ;
* V_55 = F_38 ( V_1 ) ;
* V_56 = F_39 ( V_1 ) ;
return 1 ;
}
static long F_40 ( struct V_58 * V_59 ,
T_2 V_54 , long V_17 , void * * V_55 , T_6 * V_56 )
{
struct V_2 * V_3 = F_41 ( V_59 ) ;
return F_36 ( V_3 , V_54 , V_17 , V_55 , V_56 ) ;
}
static int T_7 F_42 ( char * V_60 )
{
V_61 = F_43 ( V_60 , NULL , 0 ) ;
return 1 ;
}
static struct V_2 * F_44 ( int V_18 )
{
struct V_2 * V_3 ;
struct V_62 * V_63 ;
V_3 = F_45 ( sizeof( * V_3 ) , V_64 ) ;
if ( ! V_3 )
goto V_34;
V_3 -> V_65 = V_18 ;
F_46 ( & V_3 -> V_13 ) ;
F_47 ( & V_3 -> V_7 , V_66 ) ;
V_3 -> V_67 = F_48 ( V_64 ) ;
if ( ! V_3 -> V_67 )
goto V_68;
F_49 ( V_3 -> V_67 , F_26 ) ;
F_50 ( V_3 -> V_67 , 1024 ) ;
F_51 ( V_3 -> V_67 , V_69 ) ;
F_52 ( V_3 -> V_67 , V_25 ) ;
V_63 = V_3 -> V_70 = F_53 ( V_71 ) ;
if ( ! V_63 )
goto V_72;
V_63 -> V_73 = V_74 ;
V_63 -> V_75 = V_18 * V_71 ;
V_63 -> V_76 = & V_77 ;
V_63 -> V_42 = V_3 ;
V_63 -> V_78 = V_3 -> V_67 ;
V_63 -> V_79 = V_80 ;
sprintf ( V_63 -> V_81 , L_1 , V_18 ) ;
F_54 ( V_63 , V_61 * 2 ) ;
#ifdef F_7
F_55 ( V_82 , V_3 -> V_67 ) ;
V_3 -> V_59 = F_56 ( V_3 , V_63 -> V_81 , & V_83 ) ;
if ( ! V_3 -> V_59 )
goto V_84;
#endif
return V_3 ;
#ifdef F_7
V_84:
F_57 ( V_3 -> V_59 ) ;
F_58 ( V_3 -> V_59 ) ;
#endif
V_72:
F_59 ( V_3 -> V_67 ) ;
V_68:
F_60 ( V_3 ) ;
V_34:
return NULL ;
}
static void F_61 ( struct V_2 * V_3 )
{
F_62 ( V_3 -> V_70 ) ;
F_59 ( V_3 -> V_67 ) ;
F_15 ( V_3 ) ;
F_60 ( V_3 ) ;
}
static struct V_2 * F_63 ( int V_18 , bool * V_85 )
{
struct V_2 * V_3 ;
* V_85 = false ;
F_64 (brd, &brd_devices, brd_list) {
if ( V_3 -> V_65 == V_18 )
goto V_34;
}
V_3 = F_44 ( V_18 ) ;
if ( V_3 ) {
F_65 ( V_3 -> V_70 ) ;
F_66 ( & V_3 -> V_86 , & V_87 ) ;
}
* V_85 = true ;
V_34:
return V_3 ;
}
static void F_67 ( struct V_2 * V_3 )
{
F_68 ( & V_3 -> V_86 ) ;
#ifdef F_7
F_57 ( V_3 -> V_59 ) ;
F_58 ( V_3 -> V_59 ) ;
#endif
F_69 ( V_3 -> V_70 ) ;
F_61 ( V_3 ) ;
}
static struct V_88 * F_70 ( T_8 V_89 , int * V_90 , void * V_91 )
{
struct V_2 * V_3 ;
struct V_88 * V_92 ;
bool V_85 ;
F_71 ( & V_93 ) ;
V_3 = F_63 ( F_72 ( V_89 ) / V_71 , & V_85 ) ;
V_92 = V_3 ? F_73 ( V_3 -> V_70 ) : NULL ;
F_74 ( & V_93 ) ;
if ( V_85 )
* V_90 = 0 ;
return V_92 ;
}
static int T_7 F_75 ( void )
{
struct V_2 * V_3 , * V_94 ;
int V_18 ;
if ( F_76 ( V_74 , L_2 ) )
return - V_95 ;
if ( F_77 ( ! V_71 ) )
V_71 = 1 ;
for ( V_18 = 0 ; V_18 < V_96 ; V_18 ++ ) {
V_3 = F_44 ( V_18 ) ;
if ( ! V_3 )
goto V_97;
F_66 ( & V_3 -> V_86 , & V_87 ) ;
}
F_64 (brd, &brd_devices, brd_list)
F_65 ( V_3 -> V_70 ) ;
F_78 ( F_79 ( V_74 , 0 ) , 1UL << V_98 ,
V_99 , F_70 , NULL , NULL ) ;
F_80 ( L_3 ) ;
return 0 ;
V_97:
F_81 (brd, next, &brd_devices, brd_list) {
F_68 ( & V_3 -> V_86 ) ;
F_61 ( V_3 ) ;
}
F_82 ( V_74 , L_2 ) ;
F_80 ( L_4 ) ;
return - V_100 ;
}
static void T_9 F_83 ( void )
{
struct V_2 * V_3 , * V_94 ;
F_81 (brd, next, &brd_devices, brd_list)
F_67 ( V_3 ) ;
F_84 ( F_79 ( V_74 , 0 ) , 1UL << V_98 ) ;
F_82 ( V_74 , L_2 ) ;
F_80 ( L_5 ) ;
}
