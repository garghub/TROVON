static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
V_4 -> V_6 = 0 ;
V_4 -> V_7 = 0 ;
V_4 -> V_8 = 0 ;
V_4 -> V_9 = 0 ;
return 0 ;
}
static struct V_10 *
F_2 ( struct V_10 * V_11 [] , T_1 * V_12 , T_1 V_13 ,
T_2 * V_14 ,
enum V_15 * V_16 , enum V_15 type ,
bool V_17 )
{
struct V_10 * V_18 ;
int V_19 = ( * V_12 ) ++ ;
if ( V_19 >= V_13 )
return NULL ;
V_18 = V_11 [ V_19 ] ;
if ( ! V_18 )
return NULL ;
if ( V_17 )
F_3 ( V_18 ) ;
if ( ! F_4 ( V_18 ) )
return NULL ;
* V_16 = type ;
* V_14 = V_19 ;
return V_18 ;
}
static int F_5 ( char * V_20 , struct V_21 * time ,
bool * V_22 )
{
char V_23 ;
int V_24 = 0 ;
if ( sscanf ( V_20 , V_25 L_1 , & time -> V_26 ,
& time -> V_27 , & V_23 , & V_24 ) == 3 ) {
if ( V_23 == 'C' )
* V_22 = true ;
else
* V_22 = false ;
} else if ( sscanf ( V_20 , V_25 L_2 ,
& time -> V_26 , & time -> V_27 , & V_24 ) == 2 ) {
* V_22 = false ;
} else {
time -> V_26 = 0 ;
time -> V_27 = 0 ;
* V_22 = false ;
}
return V_24 ;
}
static bool F_6 ( struct V_10 * V_18 )
{
return ! ! V_18 && ! ! ( F_4 ( V_18 ) +
F_7 ( V_18 , NULL , 0 ) ) ;
}
static T_3 F_8 ( T_2 * V_14 , enum V_15 * type ,
int * V_28 , struct V_21 * time ,
char * * V_29 , bool * V_22 ,
struct V_1 * V_2 )
{
T_3 V_30 ;
T_3 V_31 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_10 * V_18 = NULL ;
int V_24 = 0 ;
time -> V_26 = 0 ;
time -> V_27 = 0 ;
* V_22 = false ;
while ( V_4 -> V_6 < V_4 -> V_32 && ! V_18 ) {
V_18 = F_2 ( V_4 -> V_11 , & V_4 -> V_6 ,
V_4 -> V_32 , V_14 , type ,
V_33 , 1 ) ;
if ( ! F_6 ( V_18 ) )
continue;
V_24 = F_5 ( F_9 ( V_18 ) ,
time , V_22 ) ;
if ( ! V_24 ) {
F_10 ( V_18 ) ;
F_11 ( V_18 ) ;
V_18 = NULL ;
}
}
if ( ! F_6 ( V_18 ) )
V_18 = F_2 ( & V_4 -> V_34 , & V_4 -> V_7 ,
1 , V_14 , type , V_35 , 0 ) ;
if ( ! F_6 ( V_18 ) )
V_18 = F_2 ( & V_4 -> V_36 , & V_4 -> V_8 ,
1 , V_14 , type , V_37 , 0 ) ;
if ( ! F_6 ( V_18 ) )
V_18 = F_2 ( & V_4 -> V_38 , & V_4 -> V_9 ,
1 , V_14 , type , V_39 , 0 ) ;
if ( ! F_6 ( V_18 ) )
return 0 ;
V_30 = F_4 ( V_18 ) - V_24 ;
V_31 = F_7 ( V_18 , NULL , 0 ) ;
* V_29 = F_12 ( V_30 + V_31 + 1 , V_40 ) ;
if ( * V_29 == NULL )
return - V_41 ;
memcpy ( * V_29 , ( char * ) F_9 ( V_18 ) + V_24 , V_30 ) ;
F_7 ( V_18 , * V_29 + V_30 , V_31 + 1 ) ;
return V_30 + V_31 ;
}
static T_4 F_13 ( struct V_10 * V_18 ,
bool V_22 )
{
char * V_42 ;
struct V_21 V_43 ;
T_4 V_44 ;
if ( F_14 ( & V_43 ) ) {
V_43 . V_26 = 0 ;
V_43 . V_27 = 0 ;
}
V_42 = F_15 ( V_45 , V_25 L_3 ,
( long ) V_43 . V_26 , ( long ) ( V_43 . V_27 / 1000 ) ,
V_22 ? 'C' : 'D' ) ;
F_16 ( ! V_42 ) ;
V_44 = V_42 ? strlen ( V_42 ) : 0 ;
F_17 ( V_18 , V_42 , V_44 ) ;
F_18 ( V_42 ) ;
return V_44 ;
}
static int T_5 F_19 ( enum V_15 type ,
enum V_46 V_47 ,
T_2 * V_14 , unsigned int V_48 ,
const char * V_29 ,
bool V_22 , T_4 V_30 ,
struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_10 * V_18 ;
T_4 V_49 ;
if ( type == V_35 ) {
if ( ! V_4 -> V_34 )
return - V_41 ;
F_17 ( V_4 -> V_34 , V_29 , V_30 ) ;
return 0 ;
} else if ( type == V_37 ) {
if ( ! V_4 -> V_36 )
return - V_41 ;
F_17 ( V_4 -> V_36 , V_29 , V_30 ) ;
return 0 ;
} else if ( type == V_39 ) {
if ( ! V_4 -> V_38 )
return - V_41 ;
F_17 ( V_4 -> V_38 , V_29 , V_30 ) ;
return 0 ;
}
if ( type != V_33 )
return - V_50 ;
if ( V_47 != V_51 &&
V_47 != V_52 )
return - V_50 ;
if ( V_47 == V_51 && ! V_4 -> V_53 )
return - V_50 ;
if ( V_48 != 1 )
return - V_54 ;
if ( ! V_4 -> V_11 )
return - V_54 ;
V_18 = V_4 -> V_11 [ V_4 -> V_55 ] ;
V_49 = F_13 ( V_18 , V_22 ) ;
if ( V_30 + V_49 > V_18 -> V_56 )
V_30 = V_18 -> V_56 - V_49 ;
F_17 ( V_18 , V_29 , V_30 ) ;
V_4 -> V_55 = ( V_4 -> V_55 + 1 ) % V_4 -> V_32 ;
return 0 ;
}
static int F_20 ( enum V_15 type , T_2 V_14 , int V_28 ,
struct V_21 time , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_10 * V_18 ;
switch ( type ) {
case V_33 :
if ( V_14 >= V_4 -> V_32 )
return - V_50 ;
V_18 = V_4 -> V_11 [ V_14 ] ;
break;
case V_35 :
V_18 = V_4 -> V_34 ;
break;
case V_37 :
V_18 = V_4 -> V_36 ;
break;
case V_39 :
V_18 = V_4 -> V_38 ;
break;
default:
return - V_50 ;
}
F_10 ( V_18 ) ;
F_11 ( V_18 ) ;
return 0 ;
}
static void F_21 ( struct V_3 * V_4 )
{
int V_19 ;
V_4 -> V_32 = 0 ;
if ( ! V_4 -> V_11 )
return;
for ( V_19 = 0 ; ! F_22 ( V_4 -> V_11 [ V_19 ] ) ; V_19 ++ )
F_23 ( V_4 -> V_11 [ V_19 ] ) ;
F_18 ( V_4 -> V_11 ) ;
}
static int F_24 ( struct V_57 * V_58 , struct V_3 * V_4 ,
T_6 * V_59 , T_4 V_60 )
{
int V_61 = - V_41 ;
int V_19 ;
if ( ! V_4 -> V_62 )
return 0 ;
if ( * V_59 + V_60 - V_4 -> V_63 > V_4 -> V_30 ) {
F_25 ( V_58 , L_4 ) ;
return - V_41 ;
}
V_4 -> V_32 = V_60 / V_4 -> V_62 ;
if ( ! V_4 -> V_32 )
return - V_41 ;
V_4 -> V_11 = F_26 ( sizeof( * V_4 -> V_11 ) * V_4 -> V_32 ,
V_40 ) ;
if ( ! V_4 -> V_11 ) {
F_25 ( V_58 , L_5 ) ;
goto V_64;
}
for ( V_19 = 0 ; V_19 < V_4 -> V_32 ; V_19 ++ ) {
V_4 -> V_11 [ V_19 ] = F_27 ( * V_59 , V_4 -> V_62 , 0 ,
& V_4 -> V_65 ,
V_4 -> V_66 ) ;
if ( F_28 ( V_4 -> V_11 [ V_19 ] ) ) {
V_61 = F_29 ( V_4 -> V_11 [ V_19 ] ) ;
F_25 ( V_58 , L_6 ,
V_4 -> V_62 , ( unsigned long long ) * V_59 , V_61 ) ;
goto V_64;
}
* V_59 += V_4 -> V_62 ;
}
return 0 ;
V_64:
F_21 ( V_4 ) ;
return V_61 ;
}
static int F_30 ( struct V_57 * V_58 , struct V_3 * V_4 ,
struct V_10 * * V_18 ,
T_6 * V_59 , T_4 V_67 , T_7 V_68 )
{
if ( ! V_67 )
return 0 ;
if ( * V_59 + V_67 - V_4 -> V_63 > V_4 -> V_30 ) {
F_25 ( V_58 , L_7 ,
V_67 , ( unsigned long long ) * V_59 ,
V_4 -> V_30 , ( unsigned long long ) V_4 -> V_63 ) ;
return - V_41 ;
}
* V_18 = F_27 ( * V_59 , V_67 , V_68 , & V_4 -> V_65 , V_4 -> V_66 ) ;
if ( F_28 ( * V_18 ) ) {
int V_61 = F_29 ( * V_18 ) ;
F_25 ( V_58 , L_6 ,
V_67 , ( unsigned long long ) * V_59 , V_61 ) ;
return V_61 ;
}
F_11 ( * V_18 ) ;
* V_59 += V_67 ;
return 0 ;
}
static int F_31 ( struct V_69 * V_70 )
{
struct V_57 * V_58 = & V_70 -> V_58 ;
struct V_71 * V_72 = V_70 -> V_58 . V_73 ;
struct V_3 * V_4 = & V_74 ;
T_4 V_60 ;
T_6 V_59 ;
int V_61 = - V_50 ;
if ( V_4 -> V_32 )
goto V_75;
if ( ! V_72 -> V_76 || ( ! V_72 -> V_62 && ! V_72 -> V_77 &&
! V_72 -> V_78 && ! V_72 -> V_79 ) ) {
F_32 ( L_8
L_9 ) ;
goto V_75;
}
if ( V_72 -> V_62 && ! F_33 ( V_72 -> V_62 ) )
V_72 -> V_62 = F_34 ( V_72 -> V_62 ) ;
if ( V_72 -> V_77 && ! F_33 ( V_72 -> V_77 ) )
V_72 -> V_77 = F_34 ( V_72 -> V_77 ) ;
if ( V_72 -> V_78 && ! F_33 ( V_72 -> V_78 ) )
V_72 -> V_78 = F_34 ( V_72 -> V_78 ) ;
if ( V_72 -> V_79 && ! F_33 ( V_72 -> V_79 ) )
V_72 -> V_79 = F_34 ( V_72 -> V_79 ) ;
V_4 -> V_30 = V_72 -> V_76 ;
V_4 -> V_63 = V_72 -> V_80 ;
V_4 -> V_66 = V_72 -> V_81 ;
V_4 -> V_62 = V_72 -> V_62 ;
V_4 -> V_77 = V_72 -> V_77 ;
V_4 -> V_78 = V_72 -> V_78 ;
V_4 -> V_79 = V_72 -> V_79 ;
V_4 -> V_53 = V_72 -> V_53 ;
V_4 -> V_65 = V_72 -> V_65 ;
V_59 = V_4 -> V_63 ;
V_60 = V_4 -> V_30 - V_4 -> V_77 - V_4 -> V_78
- V_4 -> V_79 ;
V_61 = F_24 ( V_58 , V_4 , & V_59 , V_60 ) ;
if ( V_61 )
goto V_75;
V_61 = F_30 ( V_58 , V_4 , & V_4 -> V_34 , & V_59 ,
V_4 -> V_77 , 0 ) ;
if ( V_61 )
goto V_82;
V_61 = F_30 ( V_58 , V_4 , & V_4 -> V_36 , & V_59 , V_4 -> V_78 ,
V_83 ) ;
if ( V_61 )
goto V_84;
V_61 = F_30 ( V_58 , V_4 , & V_4 -> V_38 , & V_59 , V_4 -> V_79 , 0 ) ;
if ( V_61 )
goto V_85;
V_4 -> V_86 . V_5 = V_4 ;
if ( V_4 -> V_77 )
V_4 -> V_86 . V_87 = 1024 ;
V_4 -> V_86 . V_87 = V_13 ( V_4 -> V_62 , V_4 -> V_86 . V_87 ) ;
V_4 -> V_86 . V_29 = F_12 ( V_4 -> V_86 . V_87 , V_40 ) ;
F_35 ( & V_4 -> V_86 . V_88 ) ;
if ( ! V_4 -> V_86 . V_29 ) {
F_32 ( L_10 ) ;
V_61 = - V_41 ;
goto V_89;
}
V_61 = F_36 ( & V_4 -> V_86 ) ;
if ( V_61 ) {
F_32 ( L_11 ) ;
goto V_90;
}
V_76 = V_72 -> V_76 ;
V_80 = V_72 -> V_80 ;
V_62 = V_72 -> V_62 ;
V_53 = V_72 -> V_53 ;
V_91 = V_72 -> V_77 ;
V_92 = V_72 -> V_79 ;
V_93 = V_72 -> V_78 ;
F_37 ( L_12 ,
V_4 -> V_30 , ( unsigned long long ) V_4 -> V_63 ,
V_4 -> V_65 . V_94 , V_4 -> V_65 . V_95 ) ;
return 0 ;
V_90:
F_18 ( V_4 -> V_86 . V_29 ) ;
V_89:
V_4 -> V_86 . V_87 = 0 ;
F_18 ( V_4 -> V_38 ) ;
V_85:
F_18 ( V_4 -> V_36 ) ;
V_84:
F_18 ( V_4 -> V_34 ) ;
V_82:
F_21 ( V_4 ) ;
V_75:
return V_61 ;
}
static int T_8 F_38 ( struct V_69 * V_70 )
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
return - V_96 ;
}
static void F_39 ( void )
{
if ( ! V_76 )
return;
F_37 ( L_13 ) ;
V_97 = F_26 ( sizeof( * V_97 ) , V_40 ) ;
if ( ! V_97 ) {
F_37 ( L_14 ) ;
return;
}
V_97 -> V_76 = V_76 ;
V_97 -> V_80 = V_80 ;
V_97 -> V_81 = V_81 ;
V_97 -> V_62 = V_62 ;
V_97 -> V_77 = V_91 ;
V_97 -> V_78 = V_93 ;
V_97 -> V_79 = V_92 ;
V_97 -> V_53 = V_53 ;
V_97 -> V_65 . V_94 = V_98 == 1 ? 16 : V_98 ;
V_99 = F_40 ( NULL , L_15 , - 1 ,
V_97 , sizeof( struct V_71 ) ) ;
if ( F_28 ( V_99 ) ) {
F_37 ( L_16 ,
F_29 ( V_99 ) ) ;
}
}
static int T_9 F_41 ( void )
{
F_39 () ;
return F_42 ( & V_100 ) ;
}
static void T_8 F_43 ( void )
{
F_44 ( & V_100 ) ;
F_45 ( V_99 ) ;
F_18 ( V_97 ) ;
}
