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
struct V_18 * time ,
char * * V_19 ,
struct V_1 * V_2 )
{
T_3 V_20 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_8 * V_16 ;
V_16 = F_2 ( V_4 -> V_9 , & V_4 -> V_6 ,
V_4 -> V_21 , V_12 , type ,
V_22 , 1 ) ;
if ( ! V_16 )
V_16 = F_2 ( & V_4 -> V_23 , & V_4 -> V_7 ,
1 , V_12 , type , V_24 , 0 ) ;
if ( ! V_16 )
V_16 = F_2 ( & V_4 -> V_25 , & V_4 -> V_26 ,
1 , V_12 , type , V_27 , 0 ) ;
if ( ! V_16 )
return 0 ;
time -> V_28 = 0 ;
time -> V_29 = 0 ;
V_20 = F_4 ( V_16 ) ;
* V_19 = F_6 ( V_20 , V_30 ) ;
if ( * V_19 == NULL )
return - V_31 ;
memcpy ( * V_19 , F_7 ( V_16 ) , V_20 ) ;
return V_20 ;
}
static T_4 F_8 ( struct V_8 * V_16 )
{
char * V_32 ;
struct V_33 V_34 ;
T_4 V_35 ;
F_9 ( & V_34 ) ;
V_32 = F_10 ( V_36 , V_37 L_1 ,
( long ) V_34 . V_28 , ( long ) V_34 . V_38 ) ;
F_11 ( ! V_32 ) ;
V_35 = V_32 ? strlen ( V_32 ) : 0 ;
F_12 ( V_16 , V_32 , V_35 ) ;
F_13 ( V_32 ) ;
return V_35 ;
}
static int F_14 ( enum V_13 type ,
enum V_39 V_40 ,
T_2 * V_12 , unsigned int V_41 ,
const char * V_19 , T_4 V_20 ,
struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_8 * V_16 = V_4 -> V_9 [ V_4 -> V_42 ] ;
T_4 V_43 ;
if ( type == V_24 ) {
if ( ! V_4 -> V_23 )
return - V_31 ;
F_12 ( V_4 -> V_23 , V_19 , V_20 ) ;
return 0 ;
} else if ( type == V_27 ) {
if ( ! V_4 -> V_25 )
return - V_31 ;
F_12 ( V_4 -> V_25 , V_19 , V_20 ) ;
return 0 ;
}
if ( type != V_22 )
return - V_44 ;
if ( V_40 != V_45 &&
V_40 != V_46 )
return - V_44 ;
if ( V_40 == V_45 && ! V_4 -> V_47 )
return - V_44 ;
if ( V_41 != 1 )
return - V_48 ;
V_43 = F_8 ( V_16 ) ;
if ( V_20 + V_43 > V_16 -> V_49 )
V_20 = V_16 -> V_49 - V_43 ;
F_12 ( V_16 , V_19 , V_20 ) ;
V_4 -> V_42 = ( V_4 -> V_42 + 1 ) % V_4 -> V_21 ;
return 0 ;
}
static int F_15 ( enum V_13 type , T_2 V_12 ,
struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_8 * V_16 ;
switch ( type ) {
case V_22 :
if ( V_12 >= V_4 -> V_21 )
return - V_44 ;
V_16 = V_4 -> V_9 [ V_12 ] ;
break;
case V_24 :
V_16 = V_4 -> V_23 ;
break;
case V_27 :
V_16 = V_4 -> V_25 ;
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
static int F_21 ( struct V_50 * V_51 , struct V_3 * V_4 ,
T_5 * V_52 , T_4 V_53 )
{
int V_54 = - V_31 ;
int V_17 ;
if ( ! V_4 -> V_55 )
return 0 ;
V_4 -> V_21 = V_53 / V_4 -> V_55 ;
if ( ! V_4 -> V_21 )
return - V_31 ;
V_4 -> V_9 = F_22 ( sizeof( * V_4 -> V_9 ) * V_4 -> V_21 ,
V_30 ) ;
if ( ! V_4 -> V_9 ) {
F_23 ( V_51 , L_2 ) ;
return - V_31 ;
}
for ( V_17 = 0 ; V_17 < V_4 -> V_21 ; V_17 ++ ) {
T_4 V_56 = V_4 -> V_55 ;
V_4 -> V_9 [ V_17 ] = F_24 ( * V_52 , V_56 , 0 , V_4 -> V_57 ) ;
if ( F_25 ( V_4 -> V_9 [ V_17 ] ) ) {
V_54 = F_26 ( V_4 -> V_9 [ V_17 ] ) ;
F_23 ( V_51 , L_3 ,
V_56 , ( unsigned long long ) * V_52 , V_54 ) ;
goto V_58;
}
* V_52 += V_56 ;
}
return 0 ;
V_58:
F_18 ( V_4 ) ;
return V_54 ;
}
static int F_27 ( struct V_50 * V_51 , struct V_3 * V_4 ,
struct V_8 * * V_16 ,
T_5 * V_52 , T_4 V_56 , T_6 V_59 )
{
if ( ! V_56 )
return 0 ;
if ( * V_52 + V_56 > * V_52 + V_4 -> V_20 )
return - V_31 ;
* V_16 = F_24 ( * V_52 , V_56 , V_59 , V_4 -> V_57 ) ;
if ( F_25 ( * V_16 ) ) {
int V_54 = F_26 ( * V_16 ) ;
F_23 ( V_51 , L_3 ,
V_56 , ( unsigned long long ) * V_52 , V_54 ) ;
return V_54 ;
}
F_17 ( * V_16 ) ;
* V_52 += V_56 ;
return 0 ;
}
static int T_7 F_28 ( struct V_60 * V_61 )
{
struct V_50 * V_51 = & V_61 -> V_51 ;
struct V_62 * V_63 = V_61 -> V_51 . V_64 ;
struct V_3 * V_4 = & V_65 ;
T_4 V_53 ;
T_5 V_52 ;
int V_54 = - V_44 ;
if ( V_4 -> V_21 )
goto V_66;
if ( ! V_63 -> V_67 || ( ! V_63 -> V_55 && ! V_63 -> V_68 &&
! V_63 -> V_69 ) ) {
F_29 ( L_4
L_5 ) ;
goto V_66;
}
V_63 -> V_67 = F_30 ( V_63 -> V_67 ) ;
V_63 -> V_55 = F_30 ( V_63 -> V_55 ) ;
V_63 -> V_68 = F_30 ( V_63 -> V_68 ) ;
V_63 -> V_69 = F_30 ( V_63 -> V_69 ) ;
V_4 -> V_6 = 0 ;
V_4 -> V_20 = V_63 -> V_67 ;
V_4 -> V_70 = V_63 -> V_71 ;
V_4 -> V_55 = V_63 -> V_55 ;
V_4 -> V_68 = V_63 -> V_68 ;
V_4 -> V_69 = V_63 -> V_69 ;
V_4 -> V_47 = V_63 -> V_47 ;
V_4 -> V_57 = V_63 -> V_57 ;
V_52 = V_4 -> V_70 ;
V_53 = V_4 -> V_20 - V_4 -> V_68 - V_4 -> V_69 ;
V_54 = F_21 ( V_51 , V_4 , & V_52 , V_53 ) ;
if ( V_54 )
goto V_66;
V_54 = F_27 ( V_51 , V_4 , & V_4 -> V_23 , & V_52 ,
V_4 -> V_68 , 0 ) ;
if ( V_54 )
goto V_72;
V_54 = F_27 ( V_51 , V_4 , & V_4 -> V_25 , & V_52 , V_4 -> V_69 ,
V_73 ) ;
if ( V_54 )
goto V_74;
if ( ! V_4 -> V_9 && ! V_4 -> V_23 && ! V_4 -> V_25 ) {
F_29 ( L_6 ,
V_4 -> V_68 + V_4 -> V_55 +
V_4 -> V_69 ) ;
goto V_75;
}
V_4 -> V_76 . V_5 = V_4 ;
if ( V_4 -> V_9 )
V_4 -> V_76 . V_77 = V_4 -> V_9 [ 0 ] -> V_49 ;
else
V_4 -> V_76 . V_77 = V_4 -> V_23 -> V_49 ;
V_4 -> V_76 . V_19 = F_6 ( V_4 -> V_76 . V_77 , V_30 ) ;
F_31 ( & V_4 -> V_76 . V_78 ) ;
if ( ! V_4 -> V_76 . V_19 ) {
F_29 ( L_7 ) ;
goto V_79;
}
V_54 = F_32 ( & V_4 -> V_76 ) ;
if ( V_54 ) {
F_29 ( L_8 ) ;
goto V_80;
}
V_67 = V_63 -> V_67 ;
V_71 = V_63 -> V_71 ;
V_55 = V_63 -> V_55 ;
V_47 = V_63 -> V_47 ;
F_33 ( L_9 ,
V_4 -> V_20 , ( unsigned long long ) V_4 -> V_70 ,
V_4 -> V_57 ) ;
return 0 ;
V_80:
F_13 ( V_4 -> V_76 . V_19 ) ;
V_79:
V_4 -> V_76 . V_77 = 0 ;
V_4 -> V_21 = 0 ;
V_75:
F_13 ( V_4 -> V_25 ) ;
V_74:
F_13 ( V_4 -> V_23 ) ;
V_72:
F_18 ( V_4 ) ;
V_66:
return V_54 ;
}
static int T_8 F_34 ( struct V_60 * V_61 )
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
return - V_81 ;
}
static void F_35 ( void )
{
if ( ! V_67 )
return;
F_33 ( L_10 ) ;
V_82 = F_22 ( sizeof( * V_82 ) , V_30 ) ;
if ( ! V_82 ) {
F_33 ( L_11 ) ;
return;
}
V_82 -> V_67 = V_67 ;
V_82 -> V_71 = V_71 ;
V_82 -> V_55 = V_55 ;
V_82 -> V_68 = V_83 ;
V_82 -> V_69 = V_84 ;
V_82 -> V_47 = V_47 ;
V_82 -> V_57 = V_85 == 1 ? 16 : V_85 ;
V_86 = F_36 ( NULL , L_12 , - 1 ,
V_82 , sizeof( struct V_62 ) ) ;
if ( F_25 ( V_86 ) ) {
F_33 ( L_13 ,
F_26 ( V_86 ) ) ;
}
}
static int T_9 F_37 ( void )
{
F_35 () ;
return F_38 ( & V_87 ) ;
}
static void T_8 F_39 ( void )
{
F_40 ( & V_87 ) ;
F_13 ( V_82 ) ;
}
