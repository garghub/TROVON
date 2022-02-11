static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
V_4 -> V_6 = 0 ;
V_4 -> V_7 = 0 ;
return 0 ;
}
static struct V_8 *
F_2 ( struct V_8 * V_9 [] , T_1 * V_10 , T_1 V_11 ,
T_2 * V_12 ,
enum V_13 * V_14 , enum V_13 type ,
bool V_15 )
{
struct V_8 * V_16 ;
int V_17 = ( * V_10 ) ++ ;
if ( V_17 >= V_11 )
return NULL ;
V_16 = V_9 [ V_17 ] ;
if ( V_15 ) {
F_3 ( V_16 ) ;
if ( ! F_4 ( V_16 ) )
return NULL ;
}
* V_14 = type ;
* V_12 = V_17 ;
return V_16 ;
}
static T_3 F_5 ( T_2 * V_12 , enum V_13 * type ,
int * V_18 , struct V_19 * time ,
char * * V_20 , struct V_1 * V_2 )
{
T_3 V_21 ;
T_3 V_22 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_8 * V_16 ;
V_16 = F_2 ( V_4 -> V_9 , & V_4 -> V_6 ,
V_4 -> V_23 , V_12 , type ,
V_24 , 1 ) ;
if ( ! V_16 )
V_16 = F_2 ( & V_4 -> V_25 , & V_4 -> V_7 ,
1 , V_12 , type , V_26 , 0 ) ;
if ( ! V_16 )
V_16 = F_2 ( & V_4 -> V_27 , & V_4 -> V_28 ,
1 , V_12 , type , V_29 , 0 ) ;
if ( ! V_16 )
return 0 ;
time -> V_30 = 0 ;
time -> V_31 = 0 ;
V_21 = F_4 ( V_16 ) ;
V_22 = F_6 ( V_16 , NULL , 0 ) ;
* V_20 = F_7 ( V_21 + V_22 + 1 , V_32 ) ;
if ( * V_20 == NULL )
return - V_33 ;
memcpy ( * V_20 , F_8 ( V_16 ) , V_21 ) ;
F_6 ( V_16 , * V_20 + V_21 , V_22 + 1 ) ;
return V_21 + V_22 ;
}
static T_4 F_9 ( struct V_8 * V_16 )
{
char * V_34 ;
struct V_19 V_35 ;
T_4 V_36 ;
if ( F_10 ( & V_35 ) ) {
V_35 . V_30 = 0 ;
V_35 . V_31 = 0 ;
}
V_34 = F_11 ( V_37 , V_38 L_1 ,
( long ) V_35 . V_30 , ( long ) ( V_35 . V_31 / 1000 ) ) ;
F_12 ( ! V_34 ) ;
V_36 = V_34 ? strlen ( V_34 ) : 0 ;
F_13 ( V_16 , V_34 , V_36 ) ;
F_14 ( V_34 ) ;
return V_36 ;
}
static int T_5 F_15 ( enum V_13 type ,
enum V_39 V_40 ,
T_2 * V_12 , unsigned int V_41 ,
const char * V_20 , T_4 V_21 ,
struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_8 * V_16 ;
T_4 V_42 ;
if ( type == V_26 ) {
if ( ! V_4 -> V_25 )
return - V_33 ;
F_13 ( V_4 -> V_25 , V_20 , V_21 ) ;
return 0 ;
} else if ( type == V_29 ) {
if ( ! V_4 -> V_27 )
return - V_33 ;
F_13 ( V_4 -> V_27 , V_20 , V_21 ) ;
return 0 ;
}
if ( type != V_24 )
return - V_43 ;
if ( V_40 != V_44 &&
V_40 != V_45 )
return - V_43 ;
if ( V_40 == V_44 && ! V_4 -> V_46 )
return - V_43 ;
if ( V_41 != 1 )
return - V_47 ;
if ( ! V_4 -> V_9 )
return - V_47 ;
V_16 = V_4 -> V_9 [ V_4 -> V_48 ] ;
V_42 = F_9 ( V_16 ) ;
if ( V_21 + V_42 > V_16 -> V_49 )
V_21 = V_16 -> V_49 - V_42 ;
F_13 ( V_16 , V_20 , V_21 ) ;
V_4 -> V_48 = ( V_4 -> V_48 + 1 ) % V_4 -> V_23 ;
return 0 ;
}
static int F_16 ( enum V_13 type , T_2 V_12 , int V_18 ,
struct V_19 time , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_8 * V_16 ;
switch ( type ) {
case V_24 :
if ( V_12 >= V_4 -> V_23 )
return - V_43 ;
V_16 = V_4 -> V_9 [ V_12 ] ;
break;
case V_26 :
V_16 = V_4 -> V_25 ;
break;
case V_29 :
V_16 = V_4 -> V_27 ;
break;
default:
return - V_43 ;
}
F_17 ( V_16 ) ;
F_18 ( V_16 ) ;
return 0 ;
}
static void F_19 ( struct V_3 * V_4 )
{
int V_17 ;
if ( ! V_4 -> V_9 )
return;
for ( V_17 = 0 ; ! F_20 ( V_4 -> V_9 [ V_17 ] ) ; V_17 ++ )
F_21 ( V_4 -> V_9 [ V_17 ] ) ;
F_14 ( V_4 -> V_9 ) ;
}
static int F_22 ( struct V_50 * V_51 , struct V_3 * V_4 ,
T_6 * V_52 , T_4 V_53 )
{
int V_54 = - V_33 ;
int V_17 ;
if ( ! V_4 -> V_55 )
return 0 ;
if ( * V_52 + V_53 - V_4 -> V_56 > V_4 -> V_21 ) {
F_23 ( V_51 , L_2 ) ;
return - V_33 ;
}
V_4 -> V_23 = V_53 / V_4 -> V_55 ;
if ( ! V_4 -> V_23 )
return - V_33 ;
V_4 -> V_9 = F_24 ( sizeof( * V_4 -> V_9 ) * V_4 -> V_23 ,
V_32 ) ;
if ( ! V_4 -> V_9 ) {
F_23 ( V_51 , L_3 ) ;
return - V_33 ;
}
for ( V_17 = 0 ; V_17 < V_4 -> V_23 ; V_17 ++ ) {
T_4 V_57 = V_4 -> V_55 ;
V_4 -> V_9 [ V_17 ] = F_25 ( * V_52 , V_57 , 0 ,
& V_4 -> V_58 ) ;
if ( F_26 ( V_4 -> V_9 [ V_17 ] ) ) {
V_54 = F_27 ( V_4 -> V_9 [ V_17 ] ) ;
F_23 ( V_51 , L_4 ,
V_57 , ( unsigned long long ) * V_52 , V_54 ) ;
goto V_59;
}
* V_52 += V_57 ;
}
return 0 ;
V_59:
F_19 ( V_4 ) ;
return V_54 ;
}
static int F_28 ( struct V_50 * V_51 , struct V_3 * V_4 ,
struct V_8 * * V_16 ,
T_6 * V_52 , T_4 V_57 , T_7 V_60 )
{
if ( ! V_57 )
return 0 ;
if ( * V_52 + V_57 - V_4 -> V_56 > V_4 -> V_21 ) {
F_23 ( V_51 , L_5 ,
V_57 , ( unsigned long long ) * V_52 ,
V_4 -> V_21 , ( unsigned long long ) V_4 -> V_56 ) ;
return - V_33 ;
}
* V_16 = F_25 ( * V_52 , V_57 , V_60 , & V_4 -> V_58 ) ;
if ( F_26 ( * V_16 ) ) {
int V_54 = F_27 ( * V_16 ) ;
F_23 ( V_51 , L_4 ,
V_57 , ( unsigned long long ) * V_52 , V_54 ) ;
return V_54 ;
}
F_18 ( * V_16 ) ;
* V_52 += V_57 ;
return 0 ;
}
static int F_29 ( struct V_61 * V_62 )
{
struct V_50 * V_51 = & V_62 -> V_51 ;
struct V_63 * V_64 = V_62 -> V_51 . V_65 ;
struct V_3 * V_4 = & V_66 ;
T_4 V_53 ;
T_6 V_52 ;
int V_54 = - V_43 ;
if ( V_4 -> V_23 )
goto V_67;
if ( ! V_64 -> V_68 || ( ! V_64 -> V_55 && ! V_64 -> V_69 &&
! V_64 -> V_70 ) ) {
F_30 ( L_6
L_7 ) ;
goto V_67;
}
if ( ! F_31 ( V_64 -> V_68 ) )
V_64 -> V_68 = F_32 ( V_64 -> V_68 ) ;
if ( ! F_31 ( V_64 -> V_55 ) )
V_64 -> V_55 = F_32 ( V_64 -> V_55 ) ;
if ( ! F_31 ( V_64 -> V_69 ) )
V_64 -> V_69 = F_32 ( V_64 -> V_69 ) ;
if ( ! F_31 ( V_64 -> V_70 ) )
V_64 -> V_70 = F_32 ( V_64 -> V_70 ) ;
V_4 -> V_6 = 0 ;
V_4 -> V_21 = V_64 -> V_68 ;
V_4 -> V_56 = V_64 -> V_71 ;
V_4 -> V_55 = V_64 -> V_55 ;
V_4 -> V_69 = V_64 -> V_69 ;
V_4 -> V_70 = V_64 -> V_70 ;
V_4 -> V_46 = V_64 -> V_46 ;
V_4 -> V_58 = V_64 -> V_58 ;
V_52 = V_4 -> V_56 ;
V_53 = V_4 -> V_21 - V_4 -> V_69 - V_4 -> V_70 ;
V_54 = F_22 ( V_51 , V_4 , & V_52 , V_53 ) ;
if ( V_54 )
goto V_67;
V_54 = F_28 ( V_51 , V_4 , & V_4 -> V_25 , & V_52 ,
V_4 -> V_69 , 0 ) ;
if ( V_54 )
goto V_72;
V_54 = F_28 ( V_51 , V_4 , & V_4 -> V_27 , & V_52 , V_4 -> V_70 ,
V_73 ) ;
if ( V_54 )
goto V_74;
if ( ! V_4 -> V_9 && ! V_4 -> V_25 && ! V_4 -> V_27 ) {
F_30 ( L_8 ,
V_4 -> V_69 + V_4 -> V_55 +
V_4 -> V_70 ) ;
V_54 = - V_43 ;
goto V_75;
}
V_4 -> V_76 . V_5 = V_4 ;
if ( V_4 -> V_69 )
V_4 -> V_76 . V_77 = 1024 ;
V_4 -> V_76 . V_77 = V_11 ( V_4 -> V_55 , V_4 -> V_76 . V_77 ) ;
V_4 -> V_76 . V_20 = F_7 ( V_4 -> V_76 . V_77 , V_32 ) ;
F_33 ( & V_4 -> V_76 . V_78 ) ;
if ( ! V_4 -> V_76 . V_20 ) {
F_30 ( L_9 ) ;
V_54 = - V_33 ;
goto V_79;
}
V_54 = F_34 ( & V_4 -> V_76 ) ;
if ( V_54 ) {
F_30 ( L_10 ) ;
goto V_80;
}
V_68 = V_64 -> V_68 ;
V_71 = V_64 -> V_71 ;
V_55 = V_64 -> V_55 ;
V_46 = V_64 -> V_46 ;
F_35 ( L_11 ,
V_4 -> V_21 , ( unsigned long long ) V_4 -> V_56 ,
V_4 -> V_58 . V_81 , V_4 -> V_58 . V_82 ) ;
return 0 ;
V_80:
F_14 ( V_4 -> V_76 . V_20 ) ;
V_79:
V_4 -> V_76 . V_77 = 0 ;
V_4 -> V_23 = 0 ;
V_75:
F_14 ( V_4 -> V_27 ) ;
V_74:
F_14 ( V_4 -> V_25 ) ;
V_72:
F_19 ( V_4 ) ;
V_67:
return V_54 ;
}
static int T_8 F_36 ( struct V_61 * V_62 )
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
return - V_83 ;
}
static void F_37 ( void )
{
if ( ! V_68 )
return;
F_35 ( L_12 ) ;
V_84 = F_24 ( sizeof( * V_84 ) , V_32 ) ;
if ( ! V_84 ) {
F_35 ( L_13 ) ;
return;
}
V_84 -> V_68 = V_68 ;
V_84 -> V_71 = V_71 ;
V_84 -> V_55 = V_55 ;
V_84 -> V_69 = V_85 ;
V_84 -> V_70 = V_86 ;
V_84 -> V_46 = V_46 ;
V_84 -> V_58 . V_81 = V_87 == 1 ? 16 : V_87 ;
V_88 = F_38 ( NULL , L_14 , - 1 ,
V_84 , sizeof( struct V_63 ) ) ;
if ( F_26 ( V_88 ) ) {
F_35 ( L_15 ,
F_27 ( V_88 ) ) ;
}
}
static int T_9 F_39 ( void )
{
F_37 () ;
return F_40 ( & V_89 ) ;
}
static void T_8 F_41 ( void )
{
F_42 ( & V_89 ) ;
F_43 ( V_88 ) ;
F_14 ( V_84 ) ;
}
