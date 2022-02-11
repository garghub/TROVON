static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
V_4 -> V_6 = 0 ;
V_4 -> V_7 = 0 ;
V_4 -> V_8 = 0 ;
return 0 ;
}
static struct V_9 *
F_2 ( struct V_9 * V_10 [] , T_1 * V_11 , T_1 V_12 ,
T_2 * V_13 ,
enum V_14 * V_15 , enum V_14 type ,
bool V_16 )
{
struct V_9 * V_17 ;
int V_18 = ( * V_11 ) ++ ;
if ( V_18 >= V_12 )
return NULL ;
V_17 = V_10 [ V_18 ] ;
if ( ! V_17 )
return NULL ;
if ( V_16 )
F_3 ( V_17 ) ;
if ( ! F_4 ( V_17 ) )
return NULL ;
* V_15 = type ;
* V_13 = V_18 ;
return V_17 ;
}
static int F_5 ( char * V_19 , struct V_20 * time ,
bool * V_21 )
{
char V_22 ;
int V_23 = 0 ;
if ( sscanf ( V_19 , V_24 L_1 , & time -> V_25 ,
& time -> V_26 , & V_22 , & V_23 ) == 3 ) {
if ( V_22 == 'C' )
* V_21 = true ;
else
* V_21 = false ;
} else if ( sscanf ( V_19 , V_24 L_2 ,
& time -> V_25 , & time -> V_26 , & V_23 ) == 2 ) {
* V_21 = false ;
} else {
time -> V_25 = 0 ;
time -> V_26 = 0 ;
* V_21 = false ;
}
return V_23 ;
}
static T_3 F_6 ( T_2 * V_13 , enum V_14 * type ,
int * V_27 , struct V_20 * time ,
char * * V_28 , bool * V_21 ,
struct V_1 * V_2 )
{
T_3 V_29 ;
T_3 V_30 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_9 * V_17 ;
int V_23 ;
V_17 = F_2 ( V_4 -> V_10 , & V_4 -> V_6 ,
V_4 -> V_31 , V_13 , type ,
V_32 , 1 ) ;
if ( ! V_17 )
V_17 = F_2 ( & V_4 -> V_33 , & V_4 -> V_7 ,
1 , V_13 , type , V_34 , 0 ) ;
if ( ! V_17 )
V_17 = F_2 ( & V_4 -> V_35 , & V_4 -> V_8 ,
1 , V_13 , type , V_36 , 0 ) ;
if ( ! V_17 )
return 0 ;
if ( ! F_7 ( V_17 ) )
return 0 ;
V_29 = F_4 ( V_17 ) ;
V_23 = F_5 ( F_7 ( V_17 ) , time ,
V_21 ) ;
V_29 -= V_23 ;
V_30 = F_8 ( V_17 , NULL , 0 ) ;
* V_28 = F_9 ( V_29 + V_30 + 1 , V_37 ) ;
if ( * V_28 == NULL )
return - V_38 ;
memcpy ( * V_28 , ( char * ) F_7 ( V_17 ) + V_23 , V_29 ) ;
F_8 ( V_17 , * V_28 + V_29 , V_30 + 1 ) ;
return V_29 + V_30 ;
}
static T_4 F_10 ( struct V_9 * V_17 ,
bool V_21 )
{
char * V_39 ;
struct V_20 V_40 ;
T_4 V_41 ;
if ( F_11 ( & V_40 ) ) {
V_40 . V_25 = 0 ;
V_40 . V_26 = 0 ;
}
V_39 = F_12 ( V_42 , V_24 L_3 ,
( long ) V_40 . V_25 , ( long ) ( V_40 . V_26 / 1000 ) ,
V_21 ? 'C' : 'D' ) ;
F_13 ( ! V_39 ) ;
V_41 = V_39 ? strlen ( V_39 ) : 0 ;
F_14 ( V_17 , V_39 , V_41 ) ;
F_15 ( V_39 ) ;
return V_41 ;
}
static int T_5 F_16 ( enum V_14 type ,
enum V_43 V_44 ,
T_2 * V_13 , unsigned int V_45 ,
const char * V_28 ,
bool V_21 , T_4 V_29 ,
struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_9 * V_17 ;
T_4 V_46 ;
if ( type == V_34 ) {
if ( ! V_4 -> V_33 )
return - V_38 ;
F_14 ( V_4 -> V_33 , V_28 , V_29 ) ;
return 0 ;
} else if ( type == V_36 ) {
if ( ! V_4 -> V_35 )
return - V_38 ;
F_14 ( V_4 -> V_35 , V_28 , V_29 ) ;
return 0 ;
}
if ( type != V_32 )
return - V_47 ;
if ( V_44 != V_48 &&
V_44 != V_49 )
return - V_47 ;
if ( V_44 == V_48 && ! V_4 -> V_50 )
return - V_47 ;
if ( V_45 != 1 )
return - V_51 ;
if ( ! V_4 -> V_10 )
return - V_51 ;
V_17 = V_4 -> V_10 [ V_4 -> V_52 ] ;
V_46 = F_10 ( V_17 , V_21 ) ;
if ( V_29 + V_46 > V_17 -> V_53 )
V_29 = V_17 -> V_53 - V_46 ;
F_14 ( V_17 , V_28 , V_29 ) ;
V_4 -> V_52 = ( V_4 -> V_52 + 1 ) % V_4 -> V_31 ;
return 0 ;
}
static int F_17 ( enum V_14 type , T_2 V_13 , int V_27 ,
struct V_20 time , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_9 * V_17 ;
switch ( type ) {
case V_32 :
if ( V_13 >= V_4 -> V_31 )
return - V_47 ;
V_17 = V_4 -> V_10 [ V_13 ] ;
break;
case V_34 :
V_17 = V_4 -> V_33 ;
break;
case V_36 :
V_17 = V_4 -> V_35 ;
break;
default:
return - V_47 ;
}
F_18 ( V_17 ) ;
F_19 ( V_17 ) ;
return 0 ;
}
static void F_20 ( struct V_3 * V_4 )
{
int V_18 ;
V_4 -> V_31 = 0 ;
if ( ! V_4 -> V_10 )
return;
for ( V_18 = 0 ; ! F_21 ( V_4 -> V_10 [ V_18 ] ) ; V_18 ++ )
F_22 ( V_4 -> V_10 [ V_18 ] ) ;
F_15 ( V_4 -> V_10 ) ;
}
static int F_23 ( struct V_54 * V_55 , struct V_3 * V_4 ,
T_6 * V_56 , T_4 V_57 )
{
int V_58 = - V_38 ;
int V_18 ;
if ( ! V_4 -> V_59 )
return 0 ;
if ( * V_56 + V_57 - V_4 -> V_60 > V_4 -> V_29 ) {
F_24 ( V_55 , L_4 ) ;
return - V_38 ;
}
V_4 -> V_31 = V_57 / V_4 -> V_59 ;
if ( ! V_4 -> V_31 )
return - V_38 ;
V_4 -> V_10 = F_25 ( sizeof( * V_4 -> V_10 ) * V_4 -> V_31 ,
V_37 ) ;
if ( ! V_4 -> V_10 ) {
F_24 ( V_55 , L_5 ) ;
goto V_61;
}
for ( V_18 = 0 ; V_18 < V_4 -> V_31 ; V_18 ++ ) {
T_4 V_62 = V_4 -> V_59 ;
V_4 -> V_10 [ V_18 ] = F_26 ( * V_56 , V_62 , 0 ,
& V_4 -> V_63 ,
V_4 -> V_64 ) ;
if ( F_27 ( V_4 -> V_10 [ V_18 ] ) ) {
V_58 = F_28 ( V_4 -> V_10 [ V_18 ] ) ;
F_24 ( V_55 , L_6 ,
V_62 , ( unsigned long long ) * V_56 , V_58 ) ;
goto V_61;
}
* V_56 += V_62 ;
}
return 0 ;
V_61:
F_20 ( V_4 ) ;
return V_58 ;
}
static int F_29 ( struct V_54 * V_55 , struct V_3 * V_4 ,
struct V_9 * * V_17 ,
T_6 * V_56 , T_4 V_62 , T_7 V_65 )
{
if ( ! V_62 )
return 0 ;
if ( * V_56 + V_62 - V_4 -> V_60 > V_4 -> V_29 ) {
F_24 ( V_55 , L_7 ,
V_62 , ( unsigned long long ) * V_56 ,
V_4 -> V_29 , ( unsigned long long ) V_4 -> V_60 ) ;
return - V_38 ;
}
* V_17 = F_26 ( * V_56 , V_62 , V_65 , & V_4 -> V_63 , V_4 -> V_64 ) ;
if ( F_27 ( * V_17 ) ) {
int V_58 = F_28 ( * V_17 ) ;
F_24 ( V_55 , L_6 ,
V_62 , ( unsigned long long ) * V_56 , V_58 ) ;
return V_58 ;
}
F_19 ( * V_17 ) ;
* V_56 += V_62 ;
return 0 ;
}
static int F_30 ( struct V_66 * V_67 )
{
struct V_54 * V_55 = & V_67 -> V_55 ;
struct V_68 * V_69 = V_67 -> V_55 . V_70 ;
struct V_3 * V_4 = & V_71 ;
T_4 V_57 ;
T_6 V_56 ;
int V_58 = - V_47 ;
if ( V_4 -> V_31 )
goto V_72;
if ( ! V_69 -> V_73 || ( ! V_69 -> V_59 && ! V_69 -> V_74 &&
! V_69 -> V_75 ) ) {
F_31 ( L_8
L_9 ) ;
goto V_72;
}
if ( V_69 -> V_59 && ! F_32 ( V_69 -> V_59 ) )
V_69 -> V_59 = F_33 ( V_69 -> V_59 ) ;
if ( V_69 -> V_74 && ! F_32 ( V_69 -> V_74 ) )
V_69 -> V_74 = F_33 ( V_69 -> V_74 ) ;
if ( V_69 -> V_75 && ! F_32 ( V_69 -> V_75 ) )
V_69 -> V_75 = F_33 ( V_69 -> V_75 ) ;
V_4 -> V_29 = V_69 -> V_73 ;
V_4 -> V_60 = V_69 -> V_76 ;
V_4 -> V_64 = V_69 -> V_77 ;
V_4 -> V_59 = V_69 -> V_59 ;
V_4 -> V_74 = V_69 -> V_74 ;
V_4 -> V_75 = V_69 -> V_75 ;
V_4 -> V_50 = V_69 -> V_50 ;
V_4 -> V_63 = V_69 -> V_63 ;
V_56 = V_4 -> V_60 ;
V_57 = V_4 -> V_29 - V_4 -> V_74 - V_4 -> V_75 ;
V_58 = F_23 ( V_55 , V_4 , & V_56 , V_57 ) ;
if ( V_58 )
goto V_72;
V_58 = F_29 ( V_55 , V_4 , & V_4 -> V_33 , & V_56 ,
V_4 -> V_74 , 0 ) ;
if ( V_58 )
goto V_78;
V_58 = F_29 ( V_55 , V_4 , & V_4 -> V_35 , & V_56 , V_4 -> V_75 ,
V_79 ) ;
if ( V_58 )
goto V_80;
if ( ! V_4 -> V_10 && ! V_4 -> V_33 && ! V_4 -> V_35 ) {
F_31 ( L_10 ,
V_4 -> V_74 + V_4 -> V_59 +
V_4 -> V_75 ) ;
V_58 = - V_47 ;
goto V_81;
}
V_4 -> V_82 . V_5 = V_4 ;
if ( V_4 -> V_74 )
V_4 -> V_82 . V_83 = 1024 ;
V_4 -> V_82 . V_83 = V_12 ( V_4 -> V_59 , V_4 -> V_82 . V_83 ) ;
V_4 -> V_82 . V_28 = F_9 ( V_4 -> V_82 . V_83 , V_37 ) ;
F_34 ( & V_4 -> V_82 . V_84 ) ;
if ( ! V_4 -> V_82 . V_28 ) {
F_31 ( L_11 ) ;
V_58 = - V_38 ;
goto V_85;
}
V_58 = F_35 ( & V_4 -> V_82 ) ;
if ( V_58 ) {
F_31 ( L_12 ) ;
goto V_86;
}
V_73 = V_69 -> V_73 ;
V_76 = V_69 -> V_76 ;
V_59 = V_69 -> V_59 ;
V_50 = V_69 -> V_50 ;
F_36 ( L_13 ,
V_4 -> V_29 , ( unsigned long long ) V_4 -> V_60 ,
V_4 -> V_63 . V_87 , V_4 -> V_63 . V_88 ) ;
return 0 ;
V_86:
F_15 ( V_4 -> V_82 . V_28 ) ;
V_85:
V_4 -> V_82 . V_83 = 0 ;
V_81:
F_15 ( V_4 -> V_35 ) ;
V_80:
F_15 ( V_4 -> V_33 ) ;
V_78:
F_20 ( V_4 ) ;
V_72:
return V_58 ;
}
static int T_8 F_37 ( struct V_66 * V_67 )
{
#if 0
struct ramoops_context *cxt = &oops_cxt;
iounmap(cxt->virt_addr);
release_mem_region(cxt->phys_addr, cxt->size);
cxt->max_dump_cnt = 0;
kfree(cxt->pstore.buf);
cxt->pstore.bufsize = 0;
return 0;
#endif
return - V_89 ;
}
static void F_38 ( void )
{
if ( ! V_73 )
return;
F_36 ( L_14 ) ;
V_90 = F_25 ( sizeof( * V_90 ) , V_37 ) ;
if ( ! V_90 ) {
F_36 ( L_15 ) ;
return;
}
V_90 -> V_73 = V_73 ;
V_90 -> V_76 = V_76 ;
V_90 -> V_77 = 0 ;
V_90 -> V_59 = V_59 ;
V_90 -> V_74 = V_91 ;
V_90 -> V_75 = V_92 ;
V_90 -> V_50 = V_50 ;
V_90 -> V_63 . V_87 = V_93 == 1 ? 16 : V_93 ;
V_94 = F_39 ( NULL , L_16 , - 1 ,
V_90 , sizeof( struct V_68 ) ) ;
if ( F_27 ( V_94 ) ) {
F_36 ( L_17 ,
F_28 ( V_94 ) ) ;
}
}
static int T_9 F_40 ( void )
{
F_38 () ;
return F_41 ( & V_95 ) ;
}
static void T_8 F_42 ( void )
{
F_43 ( & V_95 ) ;
F_44 ( V_94 ) ;
F_15 ( V_90 ) ;
}
