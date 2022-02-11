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
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_8 * V_16 ;
V_16 = F_2 ( V_4 -> V_9 , & V_4 -> V_6 ,
V_4 -> V_22 , V_12 , type ,
V_23 , 1 ) ;
if ( ! V_16 )
V_16 = F_2 ( & V_4 -> V_24 , & V_4 -> V_7 ,
1 , V_12 , type , V_25 , 0 ) ;
if ( ! V_16 )
V_16 = F_2 ( & V_4 -> V_26 , & V_4 -> V_27 ,
1 , V_12 , type , V_28 , 0 ) ;
if ( ! V_16 )
return 0 ;
time -> V_29 = 0 ;
time -> V_30 = 0 ;
V_21 = F_4 ( V_16 ) ;
* V_20 = F_6 ( V_21 , V_31 ) ;
if ( * V_20 == NULL )
return - V_32 ;
memcpy ( * V_20 , F_7 ( V_16 ) , V_21 ) ;
return V_21 ;
}
static T_4 F_8 ( struct V_8 * V_16 )
{
char * V_33 ;
struct V_34 V_35 ;
T_4 V_36 ;
F_9 ( & V_35 ) ;
V_33 = F_10 ( V_37 , V_38 L_1 ,
( long ) V_35 . V_29 , ( long ) V_35 . V_39 ) ;
F_11 ( ! V_33 ) ;
V_36 = V_33 ? strlen ( V_33 ) : 0 ;
F_12 ( V_16 , V_33 , V_36 ) ;
F_13 ( V_33 ) ;
return V_36 ;
}
static int T_5 F_14 ( enum V_13 type ,
enum V_40 V_41 ,
T_2 * V_12 , unsigned int V_42 ,
const char * V_20 , T_4 V_21 ,
struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_8 * V_16 ;
T_4 V_43 ;
if ( type == V_25 ) {
if ( ! V_4 -> V_24 )
return - V_32 ;
F_12 ( V_4 -> V_24 , V_20 , V_21 ) ;
return 0 ;
} else if ( type == V_28 ) {
if ( ! V_4 -> V_26 )
return - V_32 ;
F_12 ( V_4 -> V_26 , V_20 , V_21 ) ;
return 0 ;
}
if ( type != V_23 )
return - V_44 ;
if ( V_41 != V_45 &&
V_41 != V_46 )
return - V_44 ;
if ( V_41 == V_45 && ! V_4 -> V_47 )
return - V_44 ;
if ( V_42 != 1 )
return - V_48 ;
if ( ! V_4 -> V_9 )
return - V_48 ;
V_16 = V_4 -> V_9 [ V_4 -> V_49 ] ;
V_43 = F_8 ( V_16 ) ;
if ( V_21 + V_43 > V_16 -> V_50 )
V_21 = V_16 -> V_50 - V_43 ;
F_12 ( V_16 , V_20 , V_21 ) ;
V_4 -> V_49 = ( V_4 -> V_49 + 1 ) % V_4 -> V_22 ;
return 0 ;
}
static int F_15 ( enum V_13 type , T_2 V_12 , int V_18 ,
struct V_19 time , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_8 * V_16 ;
switch ( type ) {
case V_23 :
if ( V_12 >= V_4 -> V_22 )
return - V_44 ;
V_16 = V_4 -> V_9 [ V_12 ] ;
break;
case V_25 :
V_16 = V_4 -> V_24 ;
break;
case V_28 :
V_16 = V_4 -> V_26 ;
break;
default:
return - V_44 ;
}
F_16 ( V_16 ) ;
F_17 ( V_16 ) ;
return 0 ;
}
static void F_18 ( struct V_3 * V_4 )
{
int V_17 ;
if ( ! V_4 -> V_9 )
return;
for ( V_17 = 0 ; ! F_19 ( V_4 -> V_9 [ V_17 ] ) ; V_17 ++ )
F_20 ( V_4 -> V_9 [ V_17 ] ) ;
F_13 ( V_4 -> V_9 ) ;
}
static int F_21 ( struct V_51 * V_52 , struct V_3 * V_4 ,
T_6 * V_53 , T_4 V_54 )
{
int V_55 = - V_32 ;
int V_17 ;
if ( ! V_4 -> V_56 )
return 0 ;
if ( * V_53 + V_54 - V_4 -> V_57 > V_4 -> V_21 ) {
F_22 ( V_52 , L_2 ) ;
return - V_32 ;
}
V_4 -> V_22 = V_54 / V_4 -> V_56 ;
if ( ! V_4 -> V_22 )
return - V_32 ;
V_4 -> V_9 = F_23 ( sizeof( * V_4 -> V_9 ) * V_4 -> V_22 ,
V_31 ) ;
if ( ! V_4 -> V_9 ) {
F_22 ( V_52 , L_3 ) ;
return - V_32 ;
}
for ( V_17 = 0 ; V_17 < V_4 -> V_22 ; V_17 ++ ) {
T_4 V_58 = V_4 -> V_56 ;
V_4 -> V_9 [ V_17 ] = F_24 ( * V_53 , V_58 , 0 , V_4 -> V_59 ) ;
if ( F_25 ( V_4 -> V_9 [ V_17 ] ) ) {
V_55 = F_26 ( V_4 -> V_9 [ V_17 ] ) ;
F_22 ( V_52 , L_4 ,
V_58 , ( unsigned long long ) * V_53 , V_55 ) ;
goto V_60;
}
* V_53 += V_58 ;
}
return 0 ;
V_60:
F_18 ( V_4 ) ;
return V_55 ;
}
static int F_27 ( struct V_51 * V_52 , struct V_3 * V_4 ,
struct V_8 * * V_16 ,
T_6 * V_53 , T_4 V_58 , T_7 V_61 )
{
if ( ! V_58 )
return 0 ;
if ( * V_53 + V_58 - V_4 -> V_57 > V_4 -> V_21 ) {
F_22 ( V_52 , L_5 ,
V_58 , ( unsigned long long ) * V_53 ,
V_4 -> V_21 , ( unsigned long long ) V_4 -> V_57 ) ;
return - V_32 ;
}
* V_16 = F_24 ( * V_53 , V_58 , V_61 , V_4 -> V_59 ) ;
if ( F_25 ( * V_16 ) ) {
int V_55 = F_26 ( * V_16 ) ;
F_22 ( V_52 , L_4 ,
V_58 , ( unsigned long long ) * V_53 , V_55 ) ;
return V_55 ;
}
F_17 ( * V_16 ) ;
* V_53 += V_58 ;
return 0 ;
}
static int F_28 ( struct V_62 * V_63 )
{
struct V_51 * V_52 = & V_63 -> V_52 ;
struct V_64 * V_65 = V_63 -> V_52 . V_66 ;
struct V_3 * V_4 = & V_67 ;
T_4 V_54 ;
T_6 V_53 ;
int V_55 = - V_44 ;
if ( V_4 -> V_22 )
goto V_68;
if ( ! V_65 -> V_69 || ( ! V_65 -> V_56 && ! V_65 -> V_70 &&
! V_65 -> V_71 ) ) {
F_29 ( L_6
L_7 ) ;
goto V_68;
}
if ( ! F_30 ( V_65 -> V_69 ) )
V_65 -> V_69 = F_31 ( V_65 -> V_69 ) ;
if ( ! F_30 ( V_65 -> V_56 ) )
V_65 -> V_56 = F_31 ( V_65 -> V_56 ) ;
if ( ! F_30 ( V_65 -> V_70 ) )
V_65 -> V_70 = F_31 ( V_65 -> V_70 ) ;
if ( ! F_30 ( V_65 -> V_71 ) )
V_65 -> V_71 = F_31 ( V_65 -> V_71 ) ;
V_4 -> V_6 = 0 ;
V_4 -> V_21 = V_65 -> V_69 ;
V_4 -> V_57 = V_65 -> V_72 ;
V_4 -> V_56 = V_65 -> V_56 ;
V_4 -> V_70 = V_65 -> V_70 ;
V_4 -> V_71 = V_65 -> V_71 ;
V_4 -> V_47 = V_65 -> V_47 ;
V_4 -> V_59 = V_65 -> V_59 ;
V_53 = V_4 -> V_57 ;
V_54 = V_4 -> V_21 - V_4 -> V_70 - V_4 -> V_71 ;
V_55 = F_21 ( V_52 , V_4 , & V_53 , V_54 ) ;
if ( V_55 )
goto V_68;
V_55 = F_27 ( V_52 , V_4 , & V_4 -> V_24 , & V_53 ,
V_4 -> V_70 , 0 ) ;
if ( V_55 )
goto V_73;
V_55 = F_27 ( V_52 , V_4 , & V_4 -> V_26 , & V_53 , V_4 -> V_71 ,
V_74 ) ;
if ( V_55 )
goto V_75;
if ( ! V_4 -> V_9 && ! V_4 -> V_24 && ! V_4 -> V_26 ) {
F_29 ( L_8 ,
V_4 -> V_70 + V_4 -> V_56 +
V_4 -> V_71 ) ;
goto V_76;
}
V_4 -> V_77 . V_5 = V_4 ;
if ( V_4 -> V_70 )
V_4 -> V_77 . V_78 = 1024 ;
V_4 -> V_77 . V_78 = V_11 ( V_4 -> V_56 , V_4 -> V_77 . V_78 ) ;
V_4 -> V_77 . V_20 = F_6 ( V_4 -> V_77 . V_78 , V_31 ) ;
F_32 ( & V_4 -> V_77 . V_79 ) ;
if ( ! V_4 -> V_77 . V_20 ) {
F_29 ( L_9 ) ;
goto V_80;
}
V_55 = F_33 ( & V_4 -> V_77 ) ;
if ( V_55 ) {
F_29 ( L_10 ) ;
goto V_81;
}
V_69 = V_65 -> V_69 ;
V_72 = V_65 -> V_72 ;
V_56 = V_65 -> V_56 ;
V_47 = V_65 -> V_47 ;
F_34 ( L_11 ,
V_4 -> V_21 , ( unsigned long long ) V_4 -> V_57 ,
V_4 -> V_59 ) ;
return 0 ;
V_81:
F_13 ( V_4 -> V_77 . V_20 ) ;
V_80:
V_4 -> V_77 . V_78 = 0 ;
V_4 -> V_22 = 0 ;
V_76:
F_13 ( V_4 -> V_26 ) ;
V_75:
F_13 ( V_4 -> V_24 ) ;
V_73:
F_18 ( V_4 ) ;
V_68:
return V_55 ;
}
static int T_8 F_35 ( struct V_62 * V_63 )
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
return - V_82 ;
}
static void F_36 ( void )
{
if ( ! V_69 )
return;
F_34 ( L_12 ) ;
V_83 = F_23 ( sizeof( * V_83 ) , V_31 ) ;
if ( ! V_83 ) {
F_34 ( L_13 ) ;
return;
}
V_83 -> V_69 = V_69 ;
V_83 -> V_72 = V_72 ;
V_83 -> V_56 = V_56 ;
V_83 -> V_70 = V_84 ;
V_83 -> V_71 = V_85 ;
V_83 -> V_47 = V_47 ;
V_83 -> V_59 = V_86 == 1 ? 16 : V_86 ;
V_87 = F_37 ( NULL , L_14 , - 1 ,
V_83 , sizeof( struct V_64 ) ) ;
if ( F_25 ( V_87 ) ) {
F_34 ( L_15 ,
F_26 ( V_87 ) ) ;
}
}
static int T_9 F_38 ( void )
{
F_36 () ;
return F_39 ( & V_88 ) ;
}
static void T_8 F_40 ( void )
{
F_41 ( & V_88 ) ;
F_42 ( V_87 ) ;
F_13 ( V_83 ) ;
}
