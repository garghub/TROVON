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
static void F_5 ( char * V_18 , struct V_19 * time ,
bool * V_20 )
{
char V_21 ;
if ( sscanf ( V_18 , V_22 L_1 ,
& time -> V_23 , & time -> V_24 , & V_21 ) == 3 ) {
if ( V_21 == 'C' )
* V_20 = true ;
else
* V_20 = false ;
} else if ( sscanf ( V_18 , V_22 L_2 ,
& time -> V_23 , & time -> V_24 ) == 2 ) {
* V_20 = false ;
} else {
time -> V_23 = 0 ;
time -> V_24 = 0 ;
* V_20 = false ;
}
}
static T_3 F_6 ( T_2 * V_12 , enum V_13 * type ,
int * V_25 , struct V_19 * time ,
char * * V_26 , bool * V_20 ,
struct V_1 * V_2 )
{
T_3 V_27 ;
T_3 V_28 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_8 * V_16 ;
V_16 = F_2 ( V_4 -> V_9 , & V_4 -> V_6 ,
V_4 -> V_29 , V_12 , type ,
V_30 , 1 ) ;
if ( ! V_16 )
V_16 = F_2 ( & V_4 -> V_31 , & V_4 -> V_7 ,
1 , V_12 , type , V_32 , 0 ) ;
if ( ! V_16 )
V_16 = F_2 ( & V_4 -> V_33 , & V_4 -> V_34 ,
1 , V_12 , type , V_35 , 0 ) ;
if ( ! V_16 )
return 0 ;
V_27 = F_4 ( V_16 ) ;
V_28 = F_7 ( V_16 , NULL , 0 ) ;
* V_26 = F_8 ( V_27 + V_28 + 1 , V_36 ) ;
if ( * V_26 == NULL )
return - V_37 ;
memcpy ( * V_26 , F_9 ( V_16 ) , V_27 ) ;
F_5 ( * V_26 , time , V_20 ) ;
F_7 ( V_16 , * V_26 + V_27 , V_28 + 1 ) ;
return V_27 + V_28 ;
}
static T_4 F_10 ( struct V_8 * V_16 ,
bool V_20 )
{
char * V_38 ;
struct V_19 V_39 ;
T_4 V_40 ;
if ( F_11 ( & V_39 ) ) {
V_39 . V_23 = 0 ;
V_39 . V_24 = 0 ;
}
V_38 = F_12 ( V_41 , V_22 L_1 ,
( long ) V_39 . V_23 , ( long ) ( V_39 . V_24 / 1000 ) ,
V_20 ? 'C' : 'D' ) ;
F_13 ( ! V_38 ) ;
V_40 = V_38 ? strlen ( V_38 ) : 0 ;
F_14 ( V_16 , V_38 , V_40 ) ;
F_15 ( V_38 ) ;
return V_40 ;
}
static int T_5 F_16 ( enum V_13 type ,
enum V_42 V_43 ,
T_2 * V_12 , unsigned int V_44 ,
const char * V_26 ,
bool V_20 , T_4 V_27 ,
struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_8 * V_16 ;
T_4 V_45 ;
if ( type == V_32 ) {
if ( ! V_4 -> V_31 )
return - V_37 ;
F_14 ( V_4 -> V_31 , V_26 , V_27 ) ;
return 0 ;
} else if ( type == V_35 ) {
if ( ! V_4 -> V_33 )
return - V_37 ;
F_14 ( V_4 -> V_33 , V_26 , V_27 ) ;
return 0 ;
}
if ( type != V_30 )
return - V_46 ;
if ( V_43 != V_47 &&
V_43 != V_48 )
return - V_46 ;
if ( V_43 == V_47 && ! V_4 -> V_49 )
return - V_46 ;
if ( V_44 != 1 )
return - V_50 ;
if ( ! V_4 -> V_9 )
return - V_50 ;
V_16 = V_4 -> V_9 [ V_4 -> V_51 ] ;
V_45 = F_10 ( V_16 , V_20 ) ;
if ( V_27 + V_45 > V_16 -> V_52 )
V_27 = V_16 -> V_52 - V_45 ;
F_14 ( V_16 , V_26 , V_27 ) ;
V_4 -> V_51 = ( V_4 -> V_51 + 1 ) % V_4 -> V_29 ;
return 0 ;
}
static int F_17 ( enum V_13 type , T_2 V_12 , int V_25 ,
struct V_19 time , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_8 * V_16 ;
switch ( type ) {
case V_30 :
if ( V_12 >= V_4 -> V_29 )
return - V_46 ;
V_16 = V_4 -> V_9 [ V_12 ] ;
break;
case V_32 :
V_16 = V_4 -> V_31 ;
break;
case V_35 :
V_16 = V_4 -> V_33 ;
break;
default:
return - V_46 ;
}
F_18 ( V_16 ) ;
F_19 ( V_16 ) ;
return 0 ;
}
static void F_20 ( struct V_3 * V_4 )
{
int V_17 ;
if ( ! V_4 -> V_9 )
return;
for ( V_17 = 0 ; ! F_21 ( V_4 -> V_9 [ V_17 ] ) ; V_17 ++ )
F_22 ( V_4 -> V_9 [ V_17 ] ) ;
F_15 ( V_4 -> V_9 ) ;
}
static int F_23 ( struct V_53 * V_54 , struct V_3 * V_4 ,
T_6 * V_55 , T_4 V_56 )
{
int V_57 = - V_37 ;
int V_17 ;
if ( ! V_4 -> V_58 )
return 0 ;
if ( * V_55 + V_56 - V_4 -> V_59 > V_4 -> V_27 ) {
F_24 ( V_54 , L_3 ) ;
return - V_37 ;
}
V_4 -> V_29 = V_56 / V_4 -> V_58 ;
if ( ! V_4 -> V_29 )
return - V_37 ;
V_4 -> V_9 = F_25 ( sizeof( * V_4 -> V_9 ) * V_4 -> V_29 ,
V_36 ) ;
if ( ! V_4 -> V_9 ) {
F_24 ( V_54 , L_4 ) ;
return - V_37 ;
}
for ( V_17 = 0 ; V_17 < V_4 -> V_29 ; V_17 ++ ) {
T_4 V_60 = V_4 -> V_58 ;
V_4 -> V_9 [ V_17 ] = F_26 ( * V_55 , V_60 , 0 ,
& V_4 -> V_61 ) ;
if ( F_27 ( V_4 -> V_9 [ V_17 ] ) ) {
V_57 = F_28 ( V_4 -> V_9 [ V_17 ] ) ;
F_24 ( V_54 , L_5 ,
V_60 , ( unsigned long long ) * V_55 , V_57 ) ;
goto V_62;
}
* V_55 += V_60 ;
}
return 0 ;
V_62:
F_20 ( V_4 ) ;
return V_57 ;
}
static int F_29 ( struct V_53 * V_54 , struct V_3 * V_4 ,
struct V_8 * * V_16 ,
T_6 * V_55 , T_4 V_60 , T_7 V_63 )
{
if ( ! V_60 )
return 0 ;
if ( * V_55 + V_60 - V_4 -> V_59 > V_4 -> V_27 ) {
F_24 ( V_54 , L_6 ,
V_60 , ( unsigned long long ) * V_55 ,
V_4 -> V_27 , ( unsigned long long ) V_4 -> V_59 ) ;
return - V_37 ;
}
* V_16 = F_26 ( * V_55 , V_60 , V_63 , & V_4 -> V_61 ) ;
if ( F_27 ( * V_16 ) ) {
int V_57 = F_28 ( * V_16 ) ;
F_24 ( V_54 , L_5 ,
V_60 , ( unsigned long long ) * V_55 , V_57 ) ;
return V_57 ;
}
F_19 ( * V_16 ) ;
* V_55 += V_60 ;
return 0 ;
}
static int F_30 ( struct V_64 * V_65 )
{
struct V_53 * V_54 = & V_65 -> V_54 ;
struct V_66 * V_67 = V_65 -> V_54 . V_68 ;
struct V_3 * V_4 = & V_69 ;
T_4 V_56 ;
T_6 V_55 ;
int V_57 = - V_46 ;
if ( V_4 -> V_29 )
goto V_70;
if ( ! V_67 -> V_71 || ( ! V_67 -> V_58 && ! V_67 -> V_72 &&
! V_67 -> V_73 ) ) {
F_31 ( L_7
L_8 ) ;
goto V_70;
}
if ( V_67 -> V_58 && ! F_32 ( V_67 -> V_58 ) )
V_67 -> V_58 = F_33 ( V_67 -> V_58 ) ;
if ( V_67 -> V_72 && ! F_32 ( V_67 -> V_72 ) )
V_67 -> V_72 = F_33 ( V_67 -> V_72 ) ;
if ( V_67 -> V_73 && ! F_32 ( V_67 -> V_73 ) )
V_67 -> V_73 = F_33 ( V_67 -> V_73 ) ;
V_4 -> V_6 = 0 ;
V_4 -> V_27 = V_67 -> V_71 ;
V_4 -> V_59 = V_67 -> V_74 ;
V_4 -> V_58 = V_67 -> V_58 ;
V_4 -> V_72 = V_67 -> V_72 ;
V_4 -> V_73 = V_67 -> V_73 ;
V_4 -> V_49 = V_67 -> V_49 ;
V_4 -> V_61 = V_67 -> V_61 ;
V_55 = V_4 -> V_59 ;
V_56 = V_4 -> V_27 - V_4 -> V_72 - V_4 -> V_73 ;
V_57 = F_23 ( V_54 , V_4 , & V_55 , V_56 ) ;
if ( V_57 )
goto V_70;
V_57 = F_29 ( V_54 , V_4 , & V_4 -> V_31 , & V_55 ,
V_4 -> V_72 , 0 ) ;
if ( V_57 )
goto V_75;
V_57 = F_29 ( V_54 , V_4 , & V_4 -> V_33 , & V_55 , V_4 -> V_73 ,
V_76 ) ;
if ( V_57 )
goto V_77;
if ( ! V_4 -> V_9 && ! V_4 -> V_31 && ! V_4 -> V_33 ) {
F_31 ( L_9 ,
V_4 -> V_72 + V_4 -> V_58 +
V_4 -> V_73 ) ;
V_57 = - V_46 ;
goto V_78;
}
V_4 -> V_79 . V_5 = V_4 ;
if ( V_4 -> V_72 )
V_4 -> V_79 . V_80 = 1024 ;
V_4 -> V_79 . V_80 = V_11 ( V_4 -> V_58 , V_4 -> V_79 . V_80 ) ;
V_4 -> V_79 . V_26 = F_8 ( V_4 -> V_79 . V_80 , V_36 ) ;
F_34 ( & V_4 -> V_79 . V_81 ) ;
if ( ! V_4 -> V_79 . V_26 ) {
F_31 ( L_10 ) ;
V_57 = - V_37 ;
goto V_82;
}
V_57 = F_35 ( & V_4 -> V_79 ) ;
if ( V_57 ) {
F_31 ( L_11 ) ;
goto V_83;
}
V_71 = V_67 -> V_71 ;
V_74 = V_67 -> V_74 ;
V_58 = V_67 -> V_58 ;
V_49 = V_67 -> V_49 ;
F_36 ( L_12 ,
V_4 -> V_27 , ( unsigned long long ) V_4 -> V_59 ,
V_4 -> V_61 . V_84 , V_4 -> V_61 . V_85 ) ;
return 0 ;
V_83:
F_15 ( V_4 -> V_79 . V_26 ) ;
V_82:
V_4 -> V_79 . V_80 = 0 ;
V_4 -> V_29 = 0 ;
V_78:
F_15 ( V_4 -> V_33 ) ;
V_77:
F_15 ( V_4 -> V_31 ) ;
V_75:
F_20 ( V_4 ) ;
V_70:
return V_57 ;
}
static int T_8 F_37 ( struct V_64 * V_65 )
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
return - V_86 ;
}
static void F_38 ( void )
{
if ( ! V_71 )
return;
F_36 ( L_13 ) ;
V_87 = F_25 ( sizeof( * V_87 ) , V_36 ) ;
if ( ! V_87 ) {
F_36 ( L_14 ) ;
return;
}
V_87 -> V_71 = V_71 ;
V_87 -> V_74 = V_74 ;
V_87 -> V_58 = V_58 ;
V_87 -> V_72 = V_88 ;
V_87 -> V_73 = V_89 ;
V_87 -> V_49 = V_49 ;
V_87 -> V_61 . V_84 = V_90 == 1 ? 16 : V_90 ;
V_91 = F_39 ( NULL , L_15 , - 1 ,
V_87 , sizeof( struct V_66 ) ) ;
if ( F_27 ( V_91 ) ) {
F_36 ( L_16 ,
F_28 ( V_91 ) ) ;
}
}
static int T_9 F_40 ( void )
{
F_38 () ;
return F_41 ( & V_92 ) ;
}
static void T_8 F_42 ( void )
{
F_43 ( & V_92 ) ;
F_44 ( V_91 ) ;
F_15 ( V_87 ) ;
}
