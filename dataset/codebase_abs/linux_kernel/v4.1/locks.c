static bool F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 & ( V_4 | V_5 ) ;
}
static int F_2 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 & V_4 )
return V_6 ;
if ( V_2 -> V_3 & V_5 )
return V_7 ;
return V_2 -> V_8 ;
}
static struct V_9 *
F_3 ( struct V_10 * V_10 , int type )
{
struct V_9 * V_11 ;
if ( F_4 ( V_10 -> V_12 ) || type == V_6 )
goto V_13;
V_11 = F_5 ( V_14 , V_15 ) ;
if ( ! V_11 )
goto V_13;
F_6 ( & V_11 -> V_16 ) ;
F_7 ( & V_11 -> V_17 ) ;
F_7 ( & V_11 -> V_18 ) ;
F_7 ( & V_11 -> V_19 ) ;
if ( F_8 ( & V_10 -> V_12 , NULL , V_11 ) )
F_9 ( V_14 , V_11 ) ;
V_13:
return V_10 -> V_12 ;
}
void
F_10 ( struct V_9 * V_20 )
{
if ( V_20 ) {
F_11 ( ! F_12 ( & V_20 -> V_17 ) ) ;
F_11 ( ! F_12 ( & V_20 -> V_18 ) ) ;
F_11 ( ! F_12 ( & V_20 -> V_19 ) ) ;
F_9 ( V_14 , V_20 ) ;
}
}
static void F_13 ( struct V_1 * V_2 )
{
F_14 ( & V_2 -> V_21 ) ;
F_7 ( & V_2 -> V_22 ) ;
F_7 ( & V_2 -> V_23 ) ;
F_15 ( & V_2 -> V_24 ) ;
}
struct V_1 * F_16 ( void )
{
struct V_1 * V_2 = F_17 ( V_25 , V_15 ) ;
if ( V_2 )
F_13 ( V_2 ) ;
return V_2 ;
}
void F_18 ( struct V_1 * V_2 )
{
if ( V_2 -> V_26 ) {
if ( V_2 -> V_26 -> V_27 )
V_2 -> V_26 -> V_27 ( V_2 ) ;
V_2 -> V_26 = NULL ;
}
if ( V_2 -> V_28 ) {
if ( V_2 -> V_28 -> V_29 ) {
V_2 -> V_28 -> V_29 ( V_2 -> V_30 ) ;
V_2 -> V_30 = NULL ;
}
V_2 -> V_28 = NULL ;
}
}
void F_19 ( struct V_1 * V_2 )
{
F_20 ( F_21 ( & V_2 -> V_24 ) ) ;
F_20 ( ! F_12 ( & V_2 -> V_22 ) ) ;
F_20 ( ! F_12 ( & V_2 -> V_23 ) ) ;
F_20 ( ! F_22 ( & V_2 -> V_21 ) ) ;
F_18 ( V_2 ) ;
F_9 ( V_25 , V_2 ) ;
}
static void
F_23 ( struct V_31 * V_32 )
{
struct V_1 * V_2 ;
while ( ! F_12 ( V_32 ) ) {
V_2 = F_24 ( V_32 , struct V_1 , V_22 ) ;
F_25 ( & V_2 -> V_22 ) ;
F_19 ( V_2 ) ;
}
}
void F_26 ( struct V_1 * V_2 )
{
memset ( V_2 , 0 , sizeof( struct V_1 ) ) ;
F_13 ( V_2 ) ;
}
void F_27 ( struct V_1 * V_11 , struct V_1 * V_2 )
{
V_11 -> V_30 = V_2 -> V_30 ;
V_11 -> V_33 = V_2 -> V_33 ;
V_11 -> V_34 = NULL ;
V_11 -> V_3 = V_2 -> V_3 ;
V_11 -> V_8 = V_2 -> V_8 ;
V_11 -> V_35 = V_2 -> V_35 ;
V_11 -> V_36 = V_2 -> V_36 ;
V_11 -> V_28 = V_2 -> V_28 ;
V_11 -> V_26 = NULL ;
if ( V_2 -> V_28 ) {
if ( V_2 -> V_28 -> V_37 )
V_2 -> V_28 -> V_37 ( V_2 -> V_30 ) ;
}
}
void F_28 ( struct V_1 * V_11 , struct V_1 * V_2 )
{
F_11 ( V_11 -> V_26 ) ;
F_27 ( V_11 , V_2 ) ;
V_11 -> V_34 = V_2 -> V_34 ;
V_11 -> V_26 = V_2 -> V_26 ;
if ( V_2 -> V_26 ) {
if ( V_2 -> V_26 -> V_38 )
V_2 -> V_26 -> V_38 ( V_11 , V_2 ) ;
}
}
static inline int F_29 ( int V_39 ) {
if ( V_39 & V_40 )
return V_39 & ( V_40 | V_41 ) ;
switch ( V_39 ) {
case V_42 :
return V_7 ;
case V_43 :
return V_44 ;
case V_45 :
return V_6 ;
}
return - V_46 ;
}
static struct V_1 *
F_30 ( struct V_47 * V_48 , unsigned int V_39 )
{
struct V_1 * V_2 ;
int type = F_29 ( V_39 ) ;
if ( type < 0 )
return F_31 ( type ) ;
V_2 = F_16 () ;
if ( V_2 == NULL )
return F_31 ( - V_49 ) ;
V_2 -> V_34 = V_48 ;
V_2 -> V_30 = V_48 ;
V_2 -> V_33 = V_50 -> V_51 ;
V_2 -> V_3 = V_52 ;
V_2 -> V_8 = type ;
V_2 -> V_36 = V_53 ;
return V_2 ;
}
static int F_32 ( struct V_1 * V_2 , long type )
{
switch ( type ) {
case V_7 :
case V_44 :
case V_6 :
V_2 -> V_8 = type ;
break;
default:
return - V_46 ;
}
return 0 ;
}
static int F_33 ( struct V_47 * V_48 , struct V_1 * V_2 ,
struct V_54 * V_55 )
{
switch ( V_55 -> V_56 ) {
case V_57 :
V_2 -> V_35 = 0 ;
break;
case V_58 :
V_2 -> V_35 = V_48 -> V_59 ;
break;
case V_60 :
V_2 -> V_35 = F_34 ( F_35 ( V_48 ) ) ;
break;
default:
return - V_46 ;
}
if ( V_55 -> V_61 > V_53 - V_2 -> V_35 )
return - V_62 ;
V_2 -> V_35 += V_55 -> V_61 ;
if ( V_2 -> V_35 < 0 )
return - V_46 ;
if ( V_55 -> V_63 > 0 ) {
if ( V_55 -> V_63 - 1 > V_53 - V_2 -> V_35 )
return - V_62 ;
V_2 -> V_36 = V_2 -> V_35 + V_55 -> V_63 - 1 ;
} else if ( V_55 -> V_63 < 0 ) {
if ( V_2 -> V_35 + V_55 -> V_63 < 0 )
return - V_46 ;
V_2 -> V_36 = V_2 -> V_35 - 1 ;
V_2 -> V_35 += V_55 -> V_63 ;
} else
V_2 -> V_36 = V_53 ;
V_2 -> V_30 = V_50 -> V_64 ;
V_2 -> V_33 = V_50 -> V_51 ;
V_2 -> V_34 = V_48 ;
V_2 -> V_3 = V_65 ;
V_2 -> V_26 = NULL ;
V_2 -> V_28 = NULL ;
return F_32 ( V_2 , V_55 -> V_66 ) ;
}
static int F_36 ( struct V_47 * V_48 , struct V_1 * V_2 ,
struct V_67 * V_55 )
{
struct V_54 V_68 = {
. V_66 = V_55 -> V_66 ,
. V_56 = V_55 -> V_56 ,
. V_61 = V_55 -> V_61 ,
. V_63 = V_55 -> V_63 ,
} ;
return F_33 ( V_48 , V_2 , & V_68 ) ;
}
static bool
F_37 ( struct V_1 * V_2 )
{
F_38 ( & V_2 -> V_69 , V_70 , V_71 ) ;
return false ;
}
static void
F_39 ( struct V_1 * V_2 , void * * V_72 )
{
struct V_47 * V_48 = V_2 -> V_34 ;
struct V_73 * V_74 = * V_72 ;
if ( ! F_40 ( V_74 -> V_75 , V_48 , & V_2 -> V_69 , V_74 ) )
* V_72 = NULL ;
F_41 ( V_48 , F_42 ( V_50 ) , V_76 , 0 ) ;
}
static int F_43 ( struct V_47 * V_48 , long type , struct V_1 * V_2 )
{
if ( F_32 ( V_2 , type ) != 0 )
return - V_46 ;
V_2 -> V_30 = V_48 ;
V_2 -> V_33 = V_50 -> V_51 ;
V_2 -> V_34 = V_48 ;
V_2 -> V_3 = V_77 ;
V_2 -> V_35 = 0 ;
V_2 -> V_36 = V_53 ;
V_2 -> V_26 = NULL ;
V_2 -> V_28 = & V_78 ;
return 0 ;
}
static struct V_1 * F_44 ( struct V_47 * V_48 , long type )
{
struct V_1 * V_2 = F_16 () ;
int error = - V_49 ;
if ( V_2 == NULL )
return F_31 ( error ) ;
error = F_43 ( V_48 , type , V_2 ) ;
if ( error ) {
F_19 ( V_2 ) ;
return F_31 ( error ) ;
}
return V_2 ;
}
static inline int F_45 ( struct V_1 * V_79 , struct V_1 * V_80 )
{
return ( ( V_79 -> V_36 >= V_80 -> V_35 ) &&
( V_80 -> V_36 >= V_79 -> V_35 ) ) ;
}
static int F_46 ( struct V_1 * V_79 , struct V_1 * V_80 )
{
if ( V_79 -> V_28 && V_79 -> V_28 -> V_81 )
return V_80 -> V_28 == V_79 -> V_28 &&
V_79 -> V_28 -> V_81 ( V_79 , V_80 ) ;
return V_79 -> V_30 == V_80 -> V_30 ;
}
static void F_47 ( struct V_1 * V_2 )
{
F_48 ( & V_82 ) ;
V_2 -> V_83 = F_49 () ;
F_50 ( & V_2 -> V_21 , F_51 ( & V_84 ) ) ;
F_52 ( & V_82 ) ;
}
static void F_53 ( struct V_1 * V_2 )
{
if ( F_22 ( & V_2 -> V_21 ) )
return;
F_54 ( & V_82 , V_2 -> V_83 ) ;
F_55 ( & V_2 -> V_21 ) ;
F_56 ( & V_82 , V_2 -> V_83 ) ;
}
static unsigned long
F_57 ( struct V_1 * V_2 )
{
if ( V_2 -> V_28 && V_2 -> V_28 -> V_85 )
return V_2 -> V_28 -> V_85 ( V_2 ) ;
return ( unsigned long ) V_2 -> V_30 ;
}
static void F_58 ( struct V_1 * V_86 )
{
F_59 ( & V_87 ) ;
F_60 ( V_88 , & V_86 -> V_21 , F_57 ( V_86 ) ) ;
}
static void F_61 ( struct V_1 * V_86 )
{
F_59 ( & V_87 ) ;
F_62 ( & V_86 -> V_21 ) ;
}
static void F_63 ( struct V_1 * V_86 )
{
F_61 ( V_86 ) ;
F_25 ( & V_86 -> V_23 ) ;
V_86 -> V_89 = NULL ;
}
static void F_64 ( struct V_1 * V_86 )
{
F_65 ( & V_87 ) ;
F_63 ( V_86 ) ;
F_66 ( & V_87 ) ;
}
static void F_67 ( struct V_1 * V_90 ,
struct V_1 * V_86 )
{
F_20 ( ! F_12 ( & V_86 -> V_23 ) ) ;
V_86 -> V_89 = V_90 ;
F_68 ( & V_86 -> V_23 , & V_90 -> V_23 ) ;
if ( F_69 ( V_90 ) && ! F_70 ( V_90 ) )
F_58 ( V_86 ) ;
}
static void F_71 ( struct V_1 * V_90 ,
struct V_1 * V_86 )
{
F_65 ( & V_87 ) ;
F_67 ( V_90 , V_86 ) ;
F_66 ( & V_87 ) ;
}
static void F_72 ( struct V_1 * V_90 )
{
if ( F_12 ( & V_90 -> V_23 ) )
return;
F_65 ( & V_87 ) ;
while ( ! F_12 ( & V_90 -> V_23 ) ) {
struct V_1 * V_86 ;
V_86 = F_24 ( & V_90 -> V_23 ,
struct V_1 , V_23 ) ;
F_63 ( V_86 ) ;
if ( V_86 -> V_28 && V_86 -> V_28 -> V_91 )
V_86 -> V_28 -> V_91 ( V_86 ) ;
else
F_73 ( & V_86 -> V_24 ) ;
}
F_66 ( & V_87 ) ;
}
static void
F_74 ( struct V_1 * V_2 , struct V_31 * V_92 )
{
V_2 -> V_93 = F_75 ( F_76 ( V_50 ) ) ;
F_68 ( & V_2 -> V_22 , V_92 ) ;
F_47 ( V_2 ) ;
}
static void
F_77 ( struct V_1 * V_2 )
{
F_53 ( V_2 ) ;
F_25 ( & V_2 -> V_22 ) ;
if ( V_2 -> V_93 ) {
F_78 ( V_2 -> V_93 ) ;
V_2 -> V_93 = NULL ;
}
F_72 ( V_2 ) ;
}
static void
F_79 ( struct V_1 * V_2 , struct V_31 * V_32 )
{
F_77 ( V_2 ) ;
if ( V_32 )
F_80 ( & V_2 -> V_22 , V_32 ) ;
else
F_19 ( V_2 ) ;
}
static int F_81 ( struct V_1 * V_94 , struct V_1 * V_95 )
{
if ( V_95 -> V_8 == V_44 )
return 1 ;
if ( V_94 -> V_8 == V_44 )
return 1 ;
return 0 ;
}
static int F_82 ( struct V_1 * V_94 , struct V_1 * V_95 )
{
if ( F_46 ( V_94 , V_95 ) )
return ( 0 ) ;
if ( ! F_45 ( V_94 , V_95 ) )
return 0 ;
return ( F_81 ( V_94 , V_95 ) ) ;
}
static int F_83 ( struct V_1 * V_94 , struct V_1 * V_95 )
{
if ( V_94 -> V_34 == V_95 -> V_34 )
return ( 0 ) ;
if ( ( V_94 -> V_8 & V_40 ) || ( V_95 -> V_8 & V_40 ) )
return 0 ;
return ( F_81 ( V_94 , V_95 ) ) ;
}
void
F_84 ( struct V_47 * V_48 , struct V_1 * V_2 )
{
struct V_1 * V_96 ;
struct V_9 * V_20 ;
struct V_10 * V_10 = F_35 ( V_48 ) ;
V_20 = V_10 -> V_12 ;
if ( ! V_20 || F_85 ( & V_20 -> V_18 ) ) {
V_2 -> V_8 = V_6 ;
return;
}
F_65 ( & V_20 -> V_16 ) ;
F_86 (cfl, &ctx->flc_posix, fl_list) {
if ( F_82 ( V_2 , V_96 ) ) {
F_27 ( V_2 , V_96 ) ;
if ( V_96 -> V_93 )
V_2 -> V_33 = F_87 ( V_96 -> V_93 ) ;
goto V_13;
}
}
V_2 -> V_8 = V_6 ;
V_13:
F_66 ( & V_20 -> V_16 ) ;
return;
}
static struct V_1 * F_88 ( struct V_1 * V_97 )
{
struct V_1 * V_2 ;
F_89 (blocked_hash, fl, fl_link, posix_owner_key(block_fl)) {
if ( F_46 ( V_2 , V_97 ) )
return V_2 -> V_89 ;
}
return NULL ;
}
static int F_90 ( struct V_1 * V_94 ,
struct V_1 * V_97 )
{
int V_98 = 0 ;
F_59 ( & V_87 ) ;
if ( F_70 ( V_94 ) )
return 0 ;
while ( ( V_97 = F_88 ( V_97 ) ) ) {
if ( V_98 ++ > V_99 )
return 0 ;
if ( F_46 ( V_94 , V_97 ) )
return 1 ;
}
return 0 ;
}
static int F_91 ( struct V_47 * V_48 , struct V_1 * V_100 )
{
struct V_1 * V_101 = NULL ;
struct V_1 * V_2 ;
struct V_9 * V_20 ;
struct V_10 * V_10 = F_35 ( V_48 ) ;
int error = 0 ;
bool V_102 = false ;
F_92 ( V_32 ) ;
V_20 = F_3 ( V_10 , V_100 -> V_8 ) ;
if ( ! V_20 ) {
if ( V_100 -> V_8 != V_6 )
return - V_49 ;
return ( V_100 -> V_3 & V_103 ) ? - V_104 : 0 ;
}
if ( ! ( V_100 -> V_3 & V_105 ) && ( V_100 -> V_8 != V_6 ) ) {
V_101 = F_16 () ;
if ( ! V_101 )
return - V_49 ;
}
F_65 ( & V_20 -> V_16 ) ;
if ( V_100 -> V_3 & V_105 )
goto V_106;
F_86 (fl, &ctx->flc_flock, fl_list) {
if ( V_48 != V_2 -> V_34 )
continue;
if ( V_100 -> V_8 == V_2 -> V_8 )
goto V_13;
V_102 = true ;
F_79 ( V_2 , & V_32 ) ;
break;
}
if ( V_100 -> V_8 == V_6 ) {
if ( ( V_100 -> V_3 & V_103 ) && ! V_102 )
error = - V_104 ;
goto V_13;
}
V_106:
F_86 (fl, &ctx->flc_flock, fl_list) {
if ( ! F_83 ( V_100 , V_2 ) )
continue;
error = - V_107 ;
if ( ! ( V_100 -> V_3 & V_108 ) )
goto V_13;
error = V_109 ;
F_71 ( V_2 , V_100 ) ;
goto V_13;
}
if ( V_100 -> V_3 & V_105 )
goto V_13;
F_28 ( V_101 , V_100 ) ;
F_74 ( V_101 , & V_20 -> V_17 ) ;
V_101 = NULL ;
error = 0 ;
V_13:
F_66 ( & V_20 -> V_16 ) ;
if ( V_101 )
F_19 ( V_101 ) ;
F_23 ( & V_32 ) ;
return error ;
}
static int F_93 ( struct V_10 * V_10 , struct V_1 * V_100 , struct V_1 * V_110 )
{
struct V_1 * V_2 , * V_111 ;
struct V_1 * V_101 = NULL ;
struct V_1 * V_112 = NULL ;
struct V_1 * V_113 = NULL ;
struct V_1 * V_114 = NULL ;
struct V_9 * V_20 ;
int error ;
bool V_115 = false ;
F_92 ( V_32 ) ;
V_20 = F_3 ( V_10 , V_100 -> V_8 ) ;
if ( ! V_20 )
return ( V_100 -> V_8 == V_6 ) ? 0 : - V_49 ;
if ( ! ( V_100 -> V_3 & V_105 ) &&
( V_100 -> V_8 != V_6 ||
V_100 -> V_35 != 0 || V_100 -> V_36 != V_53 ) ) {
V_101 = F_16 () ;
V_112 = F_16 () ;
}
F_65 ( & V_20 -> V_16 ) ;
if ( V_100 -> V_8 != V_6 ) {
F_86 (fl, &ctx->flc_posix, fl_list) {
if ( ! F_82 ( V_100 , V_2 ) )
continue;
if ( V_110 )
F_27 ( V_110 , V_2 ) ;
error = - V_107 ;
if ( ! ( V_100 -> V_3 & V_108 ) )
goto V_13;
error = - V_116 ;
F_65 ( & V_87 ) ;
if ( F_4 ( ! F_90 ( V_100 , V_2 ) ) ) {
error = V_109 ;
F_67 ( V_2 , V_100 ) ;
}
F_66 ( & V_87 ) ;
goto V_13;
}
}
error = 0 ;
if ( V_100 -> V_3 & V_105 )
goto V_13;
F_86 (fl, &ctx->flc_posix, fl_list) {
if ( F_46 ( V_100 , V_2 ) )
break;
}
F_94 (fl, tmp, &ctx->flc_posix, fl_list) {
if ( ! F_46 ( V_100 , V_2 ) )
break;
if ( V_100 -> V_8 == V_2 -> V_8 ) {
if ( V_2 -> V_36 < V_100 -> V_35 - 1 )
continue;
if ( V_2 -> V_35 - 1 > V_100 -> V_36 )
break;
if ( V_2 -> V_35 > V_100 -> V_35 )
V_2 -> V_35 = V_100 -> V_35 ;
else
V_100 -> V_35 = V_2 -> V_35 ;
if ( V_2 -> V_36 < V_100 -> V_36 )
V_2 -> V_36 = V_100 -> V_36 ;
else
V_100 -> V_36 = V_2 -> V_36 ;
if ( V_115 ) {
F_79 ( V_2 , & V_32 ) ;
continue;
}
V_100 = V_2 ;
V_115 = true ;
} else {
if ( V_2 -> V_36 < V_100 -> V_35 )
continue;
if ( V_2 -> V_35 > V_100 -> V_36 )
break;
if ( V_100 -> V_8 == V_6 )
V_115 = true ;
if ( V_2 -> V_35 < V_100 -> V_35 )
V_113 = V_2 ;
if ( V_2 -> V_36 > V_100 -> V_36 ) {
V_114 = V_2 ;
break;
}
if ( V_2 -> V_35 >= V_100 -> V_35 ) {
if ( V_115 ) {
F_79 ( V_2 , & V_32 ) ;
continue;
}
error = - V_117 ;
if ( ! V_101 )
goto V_13;
F_28 ( V_101 , V_100 ) ;
V_100 = V_101 ;
V_101 = NULL ;
F_74 ( V_100 , & V_2 -> V_22 ) ;
F_79 ( V_2 , & V_32 ) ;
V_115 = true ;
}
}
}
error = - V_117 ;
if ( V_114 && V_113 == V_114 && ! V_112 )
goto V_13;
error = 0 ;
if ( ! V_115 ) {
if ( V_100 -> V_8 == V_6 ) {
if ( V_100 -> V_3 & V_103 )
error = - V_104 ;
goto V_13;
}
if ( ! V_101 ) {
error = - V_117 ;
goto V_13;
}
F_28 ( V_101 , V_100 ) ;
F_74 ( V_101 , & V_2 -> V_22 ) ;
V_2 = V_101 ;
V_101 = NULL ;
}
if ( V_114 ) {
if ( V_113 == V_114 ) {
V_113 = V_112 ;
V_112 = NULL ;
F_28 ( V_113 , V_114 ) ;
F_74 ( V_113 , & V_2 -> V_22 ) ;
}
V_114 -> V_35 = V_100 -> V_36 + 1 ;
F_72 ( V_114 ) ;
}
if ( V_113 ) {
V_113 -> V_36 = V_100 -> V_35 - 1 ;
F_72 ( V_113 ) ;
}
V_13:
F_66 ( & V_20 -> V_16 ) ;
if ( V_101 )
F_19 ( V_101 ) ;
if ( V_112 )
F_19 ( V_112 ) ;
F_23 ( & V_32 ) ;
return error ;
}
int F_95 ( struct V_47 * V_48 , struct V_1 * V_2 ,
struct V_1 * V_110 )
{
return F_93 ( F_35 ( V_48 ) , V_2 , V_110 ) ;
}
int F_96 ( struct V_47 * V_48 , struct V_1 * V_2 )
{
int error ;
F_97 () ;
for (; ; ) {
error = F_95 ( V_48 , V_2 , NULL ) ;
if ( error != V_109 )
break;
error = F_98 ( V_2 -> V_24 , ! V_2 -> V_89 ) ;
if ( ! error )
continue;
F_64 ( V_2 ) ;
break;
}
return error ;
}
int F_99 ( struct V_47 * V_47 )
{
int V_118 ;
struct V_10 * V_10 = F_35 ( V_47 ) ;
struct V_9 * V_20 ;
struct V_1 * V_2 ;
V_20 = V_10 -> V_12 ;
if ( ! V_20 || F_85 ( & V_20 -> V_18 ) )
return 0 ;
F_65 ( & V_20 -> V_16 ) ;
V_118 = 0 ;
F_86 (fl, &ctx->flc_posix, fl_list) {
if ( V_2 -> V_30 != V_50 -> V_64 &&
V_2 -> V_30 != V_47 ) {
V_118 = - V_107 ;
break;
}
}
F_66 ( & V_20 -> V_16 ) ;
return V_118 ;
}
int F_100 ( int V_119 , struct V_10 * V_10 ,
struct V_47 * V_48 , T_1 V_120 ,
T_2 V_121 )
{
struct V_1 V_2 ;
int error ;
bool V_122 = false ;
F_26 ( & V_2 ) ;
V_2 . V_33 = V_50 -> V_51 ;
V_2 . V_34 = V_48 ;
V_2 . V_3 = V_65 | V_105 ;
if ( V_48 && ! ( V_48 -> V_123 & V_124 ) )
V_122 = true ;
V_2 . V_8 = ( V_119 == V_125 ) ? V_44 : V_7 ;
V_2 . V_35 = V_120 ;
V_2 . V_36 = V_120 + V_121 - 1 ;
for (; ; ) {
if ( V_48 ) {
V_2 . V_30 = V_48 ;
V_2 . V_3 &= ~ V_108 ;
error = F_93 ( V_10 , & V_2 , NULL ) ;
if ( ! error )
break;
}
if ( V_122 )
V_2 . V_3 |= V_108 ;
V_2 . V_30 = V_50 -> V_64 ;
error = F_93 ( V_10 , & V_2 , NULL ) ;
if ( error != V_109 )
break;
error = F_98 ( V_2 . V_24 , ! V_2 . V_89 ) ;
if ( ! error ) {
if ( F_101 ( V_10 ) )
continue;
}
F_64 ( & V_2 ) ;
break;
}
return error ;
}
static void F_102 ( struct V_1 * V_2 , int V_126 )
{
switch ( V_126 ) {
case V_6 :
V_2 -> V_3 &= ~ V_4 ;
case V_7 :
V_2 -> V_3 &= ~ V_5 ;
}
}
int F_103 ( struct V_1 * V_2 , int V_126 , struct V_31 * V_32 )
{
int error = F_32 ( V_2 , V_126 ) ;
if ( error )
return error ;
F_102 ( V_2 , V_126 ) ;
F_72 ( V_2 ) ;
if ( V_126 == V_6 ) {
struct V_47 * V_48 = V_2 -> V_34 ;
F_104 ( V_48 ) ;
V_48 -> V_127 . V_128 = 0 ;
F_105 ( 0 , V_2 -> V_34 , 0 , & V_2 -> V_69 ) ;
if ( V_2 -> V_69 != NULL ) {
F_106 ( V_129 L_1 , V_2 -> V_69 ) ;
V_2 -> V_69 = NULL ;
}
F_79 ( V_2 , V_32 ) ;
}
return 0 ;
}
static bool F_107 ( unsigned long V_130 )
{
if ( ! V_130 )
return false ;
return F_108 ( V_131 , V_130 ) ;
}
static void F_109 ( struct V_10 * V_10 , struct V_31 * V_32 )
{
struct V_9 * V_20 = V_10 -> V_12 ;
struct V_1 * V_2 , * V_111 ;
F_59 ( & V_20 -> V_16 ) ;
F_110 (fl, tmp, &ctx->flc_lease, fl_list) {
F_111 ( V_10 , V_2 ) ;
if ( F_107 ( V_2 -> V_132 ) )
F_103 ( V_2 , V_7 , V_32 ) ;
if ( F_107 ( V_2 -> V_133 ) )
F_103 ( V_2 , V_6 , V_32 ) ;
}
}
static bool F_112 ( struct V_1 * V_134 , struct V_1 * V_135 )
{
if ( ( V_135 -> V_3 & V_136 ) != ( V_134 -> V_3 & V_136 ) )
return false ;
if ( ( V_135 -> V_3 & V_137 ) && ( V_134 -> V_3 & V_77 ) )
return false ;
return F_81 ( V_135 , V_134 ) ;
}
static bool
F_113 ( struct V_10 * V_10 , struct V_1 * V_135 )
{
struct V_9 * V_20 = V_10 -> V_12 ;
struct V_1 * V_2 ;
F_59 ( & V_20 -> V_16 ) ;
F_86 (fl, &ctx->flc_lease, fl_list) {
if ( F_112 ( V_2 , V_135 ) )
return true ;
}
return false ;
}
int F_114 ( struct V_10 * V_10 , unsigned int V_138 , unsigned int type )
{
int error = 0 ;
struct V_9 * V_20 = V_10 -> V_12 ;
struct V_1 * V_101 , * V_2 , * V_111 ;
unsigned long V_139 ;
int V_140 = ( V_138 & V_141 ) != V_142 ;
F_92 ( V_32 ) ;
V_101 = F_44 ( NULL , V_140 ? V_44 : V_7 ) ;
if ( F_115 ( V_101 ) )
return F_116 ( V_101 ) ;
V_101 -> V_3 = type ;
if ( ! V_20 ) {
F_11 ( 1 ) ;
return error ;
}
F_65 ( & V_20 -> V_16 ) ;
F_109 ( V_10 , & V_32 ) ;
if ( ! F_113 ( V_10 , V_101 ) )
goto V_13;
V_139 = 0 ;
if ( V_143 > 0 ) {
V_139 = V_131 + V_143 * V_144 ;
if ( V_139 == 0 )
V_139 ++ ;
}
F_110 (fl, tmp, &ctx->flc_lease, fl_list) {
if ( ! F_112 ( V_2 , V_101 ) )
continue;
if ( V_140 ) {
if ( V_2 -> V_3 & V_4 )
continue;
V_2 -> V_3 |= V_4 ;
V_2 -> V_133 = V_139 ;
} else {
if ( F_1 ( V_2 ) )
continue;
V_2 -> V_3 |= V_5 ;
V_2 -> V_132 = V_139 ;
}
if ( V_2 -> V_28 -> V_145 ( V_2 ) )
F_79 ( V_2 , & V_32 ) ;
}
if ( F_12 ( & V_20 -> V_19 ) )
goto V_13;
if ( V_138 & V_124 ) {
F_117 ( V_10 , V_101 ) ;
error = - V_146 ;
goto V_13;
}
V_147:
V_2 = F_24 ( & V_20 -> V_19 , struct V_1 , V_22 ) ;
V_139 = V_2 -> V_133 ;
if ( V_139 != 0 )
V_139 -= V_131 ;
if ( V_139 == 0 )
V_139 ++ ;
F_71 ( V_2 , V_101 ) ;
F_118 ( V_10 , V_101 ) ;
F_66 ( & V_20 -> V_16 ) ;
F_23 ( & V_32 ) ;
error = F_119 ( V_101 -> V_24 ,
! V_101 -> V_89 , V_139 ) ;
F_65 ( & V_20 -> V_16 ) ;
F_120 ( V_10 , V_101 ) ;
F_64 ( V_101 ) ;
if ( error >= 0 ) {
if ( error == 0 )
F_109 ( V_10 , & V_32 ) ;
if ( F_113 ( V_10 , V_101 ) )
goto V_147;
error = 0 ;
}
V_13:
F_66 ( & V_20 -> V_16 ) ;
F_23 ( & V_32 ) ;
F_19 ( V_101 ) ;
return error ;
}
void F_121 ( struct V_10 * V_10 , struct V_148 * time )
{
bool V_149 = false ;
struct V_9 * V_20 = V_10 -> V_12 ;
struct V_1 * V_2 ;
if ( V_20 && ! F_85 ( & V_20 -> V_19 ) ) {
F_65 ( & V_20 -> V_16 ) ;
if ( ! F_12 ( & V_20 -> V_19 ) ) {
V_2 = F_24 ( & V_20 -> V_19 ,
struct V_1 , V_22 ) ;
if ( V_2 -> V_8 == V_44 )
V_149 = true ;
}
F_66 ( & V_20 -> V_16 ) ;
}
if ( V_149 )
* time = F_122 ( V_10 -> V_150 ) ;
else
* time = V_10 -> V_151 ;
}
int F_123 ( struct V_47 * V_48 )
{
struct V_1 * V_2 ;
struct V_10 * V_10 = F_35 ( V_48 ) ;
struct V_9 * V_20 = V_10 -> V_12 ;
int type = V_6 ;
F_92 ( V_32 ) ;
if ( V_20 && ! F_85 ( & V_20 -> V_19 ) ) {
F_65 ( & V_20 -> V_16 ) ;
F_109 ( F_35 ( V_48 ) , & V_32 ) ;
F_86 (fl, &ctx->flc_lease, fl_list) {
if ( V_2 -> V_34 != V_48 )
continue;
type = F_2 ( V_2 ) ;
break;
}
F_66 ( & V_20 -> V_16 ) ;
F_23 ( & V_32 ) ;
}
return type ;
}
static int
F_124 ( const struct V_152 * V_152 , const long V_126 , int V_153 )
{
int V_118 = 0 ;
struct V_10 * V_10 = V_152 -> V_154 ;
if ( V_153 & V_136 )
return 0 ;
if ( ( V_126 == V_7 ) && ( F_125 ( & V_10 -> V_155 ) > 0 ) )
return - V_107 ;
if ( ( V_126 == V_44 ) && ( ( F_126 ( V_152 ) > 1 ) ||
( F_125 ( & V_10 -> V_156 ) > 1 ) ) )
V_118 = - V_107 ;
return V_118 ;
}
static int
F_127 ( struct V_47 * V_48 , long V_126 , struct V_1 * * V_157 , void * * V_72 )
{
struct V_1 * V_2 , * V_158 = NULL , * V_134 ;
struct V_152 * V_152 = V_48 -> V_159 . V_152 ;
struct V_10 * V_10 = V_152 -> V_154 ;
struct V_9 * V_20 ;
bool V_160 = ( * V_157 ) -> V_3 & V_137 ;
int error ;
F_92 ( V_32 ) ;
V_134 = * V_157 ;
F_128 ( V_10 , V_134 ) ;
V_20 = F_3 ( V_10 , V_126 ) ;
if ( ! V_20 )
return - V_49 ;
if ( V_160 && ! F_129 ( & V_10 -> V_161 ) )
return - V_107 ;
if ( V_160 && V_126 == V_44 ) {
F_130 ( & V_10 -> V_161 ) ;
F_11 ( 1 ) ;
return - V_46 ;
}
F_65 ( & V_20 -> V_16 ) ;
F_109 ( V_10 , & V_32 ) ;
error = F_124 ( V_152 , V_126 , V_134 -> V_3 ) ;
if ( error )
goto V_13;
error = - V_107 ;
F_86 (fl, &ctx->flc_lease, fl_list) {
if ( V_2 -> V_34 == V_48 &&
V_2 -> V_30 == V_134 -> V_30 ) {
V_158 = V_2 ;
continue;
}
if ( V_126 == V_44 )
goto V_13;
if ( V_2 -> V_3 & V_4 )
goto V_13;
}
if ( V_158 != NULL ) {
V_134 = V_158 ;
error = V_134 -> V_28 -> V_162 ( V_134 , V_126 , & V_32 ) ;
if ( error )
goto V_13;
goto V_163;
}
error = - V_46 ;
if ( ! V_164 )
goto V_13;
F_74 ( V_134 , & V_20 -> V_19 ) ;
F_131 () ;
error = F_124 ( V_152 , V_126 , V_134 -> V_3 ) ;
if ( error ) {
F_77 ( V_134 ) ;
goto V_13;
}
V_163:
if ( V_134 -> V_28 -> V_165 )
V_134 -> V_28 -> V_165 ( V_134 , V_72 ) ;
V_13:
F_66 ( & V_20 -> V_16 ) ;
F_23 ( & V_32 ) ;
if ( V_160 )
F_130 ( & V_10 -> V_161 ) ;
if ( ! error && ! V_158 )
* V_157 = NULL ;
return error ;
}
static int F_132 ( struct V_47 * V_48 , void * V_166 )
{
int error = - V_107 ;
struct V_1 * V_2 , * V_167 = NULL ;
struct V_152 * V_152 = V_48 -> V_159 . V_152 ;
struct V_10 * V_10 = V_152 -> V_154 ;
struct V_9 * V_20 = V_10 -> V_12 ;
F_92 ( V_32 ) ;
if ( ! V_20 ) {
F_133 ( V_10 , NULL ) ;
return error ;
}
F_65 ( & V_20 -> V_16 ) ;
F_86 (fl, &ctx->flc_lease, fl_list) {
if ( V_2 -> V_34 == V_48 &&
V_2 -> V_30 == V_166 ) {
V_167 = V_2 ;
break;
}
}
F_133 ( V_10 , V_167 ) ;
if ( V_167 )
error = V_2 -> V_28 -> V_162 ( V_167 , V_6 , & V_32 ) ;
F_66 ( & V_20 -> V_16 ) ;
F_23 ( & V_32 ) ;
return error ;
}
int F_134 ( struct V_47 * V_48 , long V_126 , struct V_1 * * V_157 ,
void * * V_72 )
{
struct V_152 * V_152 = V_48 -> V_159 . V_152 ;
struct V_10 * V_10 = V_152 -> V_154 ;
int error ;
if ( ( ! F_135 ( F_136 () , V_10 -> V_168 ) ) && ! F_137 ( V_169 ) )
return - V_170 ;
if ( ! F_138 ( V_10 -> V_171 ) )
return - V_46 ;
error = F_139 ( V_48 , V_126 ) ;
if ( error )
return error ;
switch ( V_126 ) {
case V_6 :
return F_132 ( V_48 , * V_72 ) ;
case V_7 :
case V_44 :
if ( ! ( * V_157 ) -> V_28 -> V_145 ) {
F_11 ( 1 ) ;
return - V_117 ;
}
return F_127 ( V_48 , V_126 , V_157 , V_72 ) ;
default:
return - V_46 ;
}
}
int
F_140 ( struct V_47 * V_48 , long V_126 , struct V_1 * * V_134 , void * * V_72 )
{
if ( V_48 -> V_172 -> V_173 )
return V_48 -> V_172 -> V_173 ( V_48 , V_126 , V_134 , V_72 ) ;
else
return F_134 ( V_48 , V_126 , V_134 , V_72 ) ;
}
static int F_141 ( unsigned int V_174 , struct V_47 * V_48 , long V_126 )
{
struct V_1 * V_2 ;
struct V_73 * V_11 ;
int error ;
V_2 = F_44 ( V_48 , V_126 ) ;
if ( F_115 ( V_2 ) )
return F_116 ( V_2 ) ;
V_11 = F_142 () ;
if ( ! V_11 ) {
F_19 ( V_2 ) ;
return - V_49 ;
}
V_11 -> V_75 = V_174 ;
error = F_140 ( V_48 , V_126 , & V_2 , ( void * * ) & V_11 ) ;
if ( V_2 )
F_19 ( V_2 ) ;
if ( V_11 )
F_143 ( V_11 ) ;
return error ;
}
int F_144 ( unsigned int V_174 , struct V_47 * V_48 , long V_126 )
{
if ( V_126 == V_6 )
return F_140 ( V_48 , V_6 , NULL , ( void * * ) & V_48 ) ;
return F_141 ( V_174 , V_48 , V_126 ) ;
}
int F_145 ( struct V_47 * V_48 , struct V_1 * V_2 )
{
int error ;
F_97 () ;
for (; ; ) {
error = F_91 ( V_48 , V_2 ) ;
if ( error != V_109 )
break;
error = F_98 ( V_2 -> V_24 , ! V_2 -> V_89 ) ;
if ( ! error )
continue;
F_64 ( V_2 ) ;
break;
}
return error ;
}
int F_146 ( struct V_47 * V_48 , struct V_1 * V_2 )
{
if ( V_48 -> V_172 -> V_175 )
return V_48 -> V_172 -> V_175 ( V_48 , V_176 , V_2 ) ;
F_84 ( V_48 , V_2 ) ;
return 0 ;
}
static int F_147 ( struct V_67 * V_67 , struct V_1 * V_2 )
{
V_67 -> V_177 = F_70 ( V_2 ) ? - 1 : V_2 -> V_33 ;
#if V_178 == 32
if ( V_2 -> V_35 > V_179 )
return - V_62 ;
if ( V_2 -> V_36 != V_53 && V_2 -> V_36 > V_179 )
return - V_62 ;
#endif
V_67 -> V_61 = V_2 -> V_35 ;
V_67 -> V_63 = V_2 -> V_36 == V_53 ? 0 :
V_2 -> V_36 - V_2 -> V_35 + 1 ;
V_67 -> V_56 = 0 ;
V_67 -> V_66 = V_2 -> V_8 ;
return 0 ;
}
static void F_148 ( struct V_54 * V_67 , struct V_1 * V_2 )
{
V_67 -> V_177 = F_70 ( V_2 ) ? - 1 : V_2 -> V_33 ;
V_67 -> V_61 = V_2 -> V_35 ;
V_67 -> V_63 = V_2 -> V_36 == V_53 ? 0 :
V_2 -> V_36 - V_2 -> V_35 + 1 ;
V_67 -> V_56 = 0 ;
V_67 -> V_66 = V_2 -> V_8 ;
}
int F_149 ( struct V_47 * V_48 , unsigned int V_39 , struct V_67 T_3 * V_55 )
{
struct V_1 V_1 ;
struct V_67 V_67 ;
int error ;
error = - V_180 ;
if ( F_150 ( & V_67 , V_55 , sizeof( V_67 ) ) )
goto V_13;
error = - V_46 ;
if ( ( V_67 . V_66 != V_7 ) && ( V_67 . V_66 != V_44 ) )
goto V_13;
error = F_36 ( V_48 , & V_1 , & V_67 ) ;
if ( error )
goto V_13;
if ( V_39 == V_181 ) {
error = - V_46 ;
if ( V_67 . V_177 != 0 )
goto V_13;
V_39 = V_176 ;
V_1 . V_3 |= V_182 ;
V_1 . V_30 = V_48 ;
}
error = F_146 ( V_48 , & V_1 ) ;
if ( error )
goto V_13;
V_67 . V_66 = V_1 . V_8 ;
if ( V_1 . V_8 != V_6 ) {
error = F_147 ( & V_67 , & V_1 ) ;
if ( error )
goto V_183;
}
error = - V_180 ;
if ( ! F_151 ( V_55 , & V_67 , sizeof( V_67 ) ) )
error = 0 ;
V_183:
F_18 ( & V_1 ) ;
V_13:
return error ;
}
int F_152 ( struct V_47 * V_48 , unsigned int V_39 , struct V_1 * V_2 , struct V_1 * V_184 )
{
if ( V_48 -> V_172 -> V_175 )
return V_48 -> V_172 -> V_175 ( V_48 , V_39 , V_2 ) ;
else
return F_95 ( V_48 , V_2 , V_184 ) ;
}
static int F_153 ( struct V_47 * V_48 , unsigned int V_39 ,
struct V_1 * V_2 )
{
int error ;
error = F_139 ( V_48 , V_2 -> V_8 ) ;
if ( error )
return error ;
for (; ; ) {
error = F_152 ( V_48 , V_39 , V_2 , NULL ) ;
if ( error != V_109 )
break;
error = F_98 ( V_2 -> V_24 , ! V_2 -> V_89 ) ;
if ( ! error )
continue;
F_64 ( V_2 ) ;
break;
}
return error ;
}
static int
F_154 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_8 ) {
case V_7 :
if ( ! ( V_2 -> V_34 -> V_185 & V_186 ) )
return - V_187 ;
break;
case V_44 :
if ( ! ( V_2 -> V_34 -> V_185 & V_188 ) )
return - V_187 ;
}
return 0 ;
}
int F_155 ( unsigned int V_174 , struct V_47 * V_48 , unsigned int V_39 ,
struct V_67 T_3 * V_55 )
{
struct V_1 * V_1 = F_16 () ;
struct V_67 V_67 ;
struct V_10 * V_10 ;
struct V_47 * V_189 ;
int error ;
if ( V_1 == NULL )
return - V_117 ;
error = - V_180 ;
if ( F_150 ( & V_67 , V_55 , sizeof( V_67 ) ) )
goto V_13;
V_10 = F_35 ( V_48 ) ;
if ( F_156 ( V_10 ) && F_157 ( V_48 -> V_190 ) ) {
error = - V_107 ;
goto V_13;
}
V_191:
error = F_36 ( V_48 , V_1 , & V_67 ) ;
if ( error )
goto V_13;
error = F_154 ( V_1 ) ;
if ( error )
goto V_13;
switch ( V_39 ) {
case V_192 :
error = - V_46 ;
if ( V_67 . V_177 != 0 )
goto V_13;
V_39 = V_193 ;
V_1 -> V_3 |= V_182 ;
V_1 -> V_30 = V_48 ;
break;
case V_194 :
error = - V_46 ;
if ( V_67 . V_177 != 0 )
goto V_13;
V_39 = V_195 ;
V_1 -> V_3 |= V_182 ;
V_1 -> V_30 = V_48 ;
case V_195 :
V_1 -> V_3 |= V_108 ;
}
error = F_153 ( V_48 , V_39 , V_1 ) ;
F_65 ( & V_50 -> V_64 -> V_1 ) ;
V_189 = F_158 ( V_174 ) ;
F_66 ( & V_50 -> V_64 -> V_1 ) ;
if ( ! error && V_189 != V_48 && V_67 . V_66 != V_6 ) {
V_67 . V_66 = V_6 ;
goto V_191;
}
V_13:
F_19 ( V_1 ) ;
return error ;
}
int F_159 ( struct V_47 * V_48 , unsigned int V_39 , struct V_54 T_3 * V_55 )
{
struct V_1 V_1 ;
struct V_54 V_67 ;
int error ;
error = - V_180 ;
if ( F_150 ( & V_67 , V_55 , sizeof( V_67 ) ) )
goto V_13;
error = - V_46 ;
if ( ( V_67 . V_66 != V_7 ) && ( V_67 . V_66 != V_44 ) )
goto V_13;
error = F_33 ( V_48 , & V_1 , & V_67 ) ;
if ( error )
goto V_13;
if ( V_39 == V_181 ) {
error = - V_46 ;
if ( V_67 . V_177 != 0 )
goto V_13;
V_39 = V_196 ;
V_1 . V_3 |= V_182 ;
V_1 . V_30 = V_48 ;
}
error = F_146 ( V_48 , & V_1 ) ;
if ( error )
goto V_13;
V_67 . V_66 = V_1 . V_8 ;
if ( V_1 . V_8 != V_6 )
F_148 ( & V_67 , & V_1 ) ;
error = - V_180 ;
if ( ! F_151 ( V_55 , & V_67 , sizeof( V_67 ) ) )
error = 0 ;
F_18 ( & V_1 ) ;
V_13:
return error ;
}
int F_160 ( unsigned int V_174 , struct V_47 * V_48 , unsigned int V_39 ,
struct V_54 T_3 * V_55 )
{
struct V_1 * V_1 = F_16 () ;
struct V_54 V_67 ;
struct V_10 * V_10 ;
struct V_47 * V_189 ;
int error ;
if ( V_1 == NULL )
return - V_117 ;
error = - V_180 ;
if ( F_150 ( & V_67 , V_55 , sizeof( V_67 ) ) )
goto V_13;
V_10 = F_35 ( V_48 ) ;
if ( F_156 ( V_10 ) && F_157 ( V_48 -> V_190 ) ) {
error = - V_107 ;
goto V_13;
}
V_191:
error = F_33 ( V_48 , V_1 , & V_67 ) ;
if ( error )
goto V_13;
error = F_154 ( V_1 ) ;
if ( error )
goto V_13;
switch ( V_39 ) {
case V_192 :
error = - V_46 ;
if ( V_67 . V_177 != 0 )
goto V_13;
V_39 = V_197 ;
V_1 -> V_3 |= V_182 ;
V_1 -> V_30 = V_48 ;
break;
case V_194 :
error = - V_46 ;
if ( V_67 . V_177 != 0 )
goto V_13;
V_39 = V_198 ;
V_1 -> V_3 |= V_182 ;
V_1 -> V_30 = V_48 ;
case V_198 :
V_1 -> V_3 |= V_108 ;
}
error = F_153 ( V_48 , V_39 , V_1 ) ;
F_65 ( & V_50 -> V_64 -> V_1 ) ;
V_189 = F_158 ( V_174 ) ;
F_66 ( & V_50 -> V_64 -> V_1 ) ;
if ( ! error && V_189 != V_48 && V_67 . V_66 != V_6 ) {
V_67 . V_66 = V_6 ;
goto V_191;
}
V_13:
F_19 ( V_1 ) ;
return error ;
}
void F_161 ( struct V_47 * V_48 , T_4 V_166 )
{
struct V_1 V_175 ;
struct V_9 * V_20 = F_35 ( V_48 ) -> V_12 ;
if ( ! V_20 || F_12 ( & V_20 -> V_18 ) )
return;
V_175 . V_8 = V_6 ;
V_175 . V_3 = V_65 | V_199 ;
V_175 . V_35 = 0 ;
V_175 . V_36 = V_53 ;
V_175 . V_30 = V_166 ;
V_175 . V_33 = V_50 -> V_51 ;
V_175 . V_34 = V_48 ;
V_175 . V_26 = NULL ;
V_175 . V_28 = NULL ;
F_152 ( V_48 , V_193 , & V_175 , NULL ) ;
if ( V_175 . V_26 && V_175 . V_26 -> V_27 )
V_175 . V_26 -> V_27 ( & V_175 ) ;
}
static void
F_162 ( struct V_47 * V_48 )
{
struct V_1 V_2 = {
. V_30 = V_48 ,
. V_33 = V_50 -> V_51 ,
. V_34 = V_48 ,
. V_3 = V_52 ,
. V_8 = V_6 ,
. V_36 = V_53 ,
} ;
struct V_9 * V_200 = F_35 ( V_48 ) -> V_12 ;
if ( F_12 ( & V_200 -> V_17 ) )
return;
if ( V_48 -> V_172 -> V_67 )
V_48 -> V_172 -> V_67 ( V_48 , V_195 , & V_2 ) ;
else
F_91 ( V_48 , & V_2 ) ;
if ( V_2 . V_26 && V_2 . V_26 -> V_27 )
V_2 . V_26 -> V_27 ( & V_2 ) ;
}
static void
F_163 ( struct V_47 * V_48 )
{
struct V_10 * V_10 = F_35 ( V_48 ) ;
struct V_9 * V_20 = V_10 -> V_12 ;
struct V_1 * V_2 , * V_111 ;
F_92 ( V_32 ) ;
if ( F_12 ( & V_20 -> V_19 ) )
return;
F_65 ( & V_20 -> V_16 ) ;
F_110 (fl, tmp, &ctx->flc_lease, fl_list)
if ( V_48 == V_2 -> V_34 )
F_103 ( V_2 , V_6 , & V_32 ) ;
F_66 ( & V_20 -> V_16 ) ;
F_23 ( & V_32 ) ;
}
void F_164 ( struct V_47 * V_48 )
{
if ( ! F_35 ( V_48 ) -> V_12 )
return;
F_161 ( V_48 , V_48 ) ;
F_162 ( V_48 ) ;
F_163 ( V_48 ) ;
}
int
F_165 ( struct V_1 * V_86 )
{
int V_201 = 0 ;
F_65 ( & V_87 ) ;
if ( V_86 -> V_89 )
F_63 ( V_86 ) ;
else
V_201 = - V_104 ;
F_66 ( & V_87 ) ;
return V_201 ;
}
int F_166 ( struct V_47 * V_48 , struct V_1 * V_2 )
{
if ( V_48 -> V_172 -> V_175 )
return V_48 -> V_172 -> V_175 ( V_48 , V_202 , V_2 ) ;
return 0 ;
}
static void F_167 ( struct V_203 * V_189 , struct V_1 * V_2 ,
T_1 V_204 , char * V_205 )
{
struct V_10 * V_10 = NULL ;
unsigned int V_33 ;
if ( V_2 -> V_93 )
V_33 = F_87 ( V_2 -> V_93 ) ;
else
V_33 = V_2 -> V_33 ;
if ( V_2 -> V_34 != NULL )
V_10 = F_35 ( V_2 -> V_34 ) ;
F_168 ( V_189 , L_2 , V_204 , V_205 ) ;
if ( F_69 ( V_2 ) ) {
if ( V_2 -> V_3 & V_105 )
F_169 ( V_189 , L_3 ) ;
else if ( F_70 ( V_2 ) )
F_169 ( V_189 , L_4 ) ;
else
F_169 ( V_189 , L_5 ) ;
F_168 ( V_189 , L_6 ,
( V_10 == NULL ) ? L_7 :
F_156 ( V_10 ) ? L_8 : L_9 ) ;
} else if ( F_170 ( V_2 ) ) {
if ( V_2 -> V_8 & V_40 ) {
F_169 ( V_189 , L_10 ) ;
} else {
F_169 ( V_189 , L_11 ) ;
}
} else if ( F_171 ( V_2 ) ) {
if ( V_2 -> V_3 & V_137 )
F_169 ( V_189 , L_12 ) ;
else
F_169 ( V_189 , L_13 ) ;
if ( F_1 ( V_2 ) )
F_169 ( V_189 , L_14 ) ;
else if ( V_2 -> V_34 )
F_169 ( V_189 , L_15 ) ;
else
F_169 ( V_189 , L_16 ) ;
} else {
F_169 ( V_189 , L_17 ) ;
}
if ( V_2 -> V_8 & V_40 ) {
F_168 ( V_189 , L_18 ,
( V_2 -> V_8 & V_206 )
? ( V_2 -> V_8 & V_207 ) ? L_19 : L_20
: ( V_2 -> V_8 & V_207 ) ? L_21 : L_22 ) ;
} else {
F_168 ( V_189 , L_18 ,
( F_1 ( V_2 ) )
? ( V_2 -> V_8 == V_6 ) ? L_23 : L_20
: ( V_2 -> V_8 == V_44 ) ? L_21 : L_20 ) ;
}
if ( V_10 ) {
F_168 ( V_189 , L_24 , V_33 ,
F_172 ( V_10 -> V_150 -> V_208 ) ,
F_173 ( V_10 -> V_150 -> V_208 ) , V_10 -> V_209 ) ;
} else {
F_168 ( V_189 , L_25 , V_33 ) ;
}
if ( F_69 ( V_2 ) ) {
if ( V_2 -> V_36 == V_53 )
F_168 ( V_189 , L_26 , V_2 -> V_35 ) ;
else
F_168 ( V_189 , L_27 , V_2 -> V_35 , V_2 -> V_36 ) ;
} else {
F_169 ( V_189 , L_28 ) ;
}
}
static int F_174 ( struct V_203 * V_189 , void * V_210 )
{
struct V_211 * V_212 = V_189 -> V_213 ;
struct V_1 * V_2 , * V_214 ;
V_2 = F_175 ( V_210 , struct V_1 , V_21 ) ;
F_167 ( V_189 , V_2 , V_212 -> V_215 , L_29 ) ;
F_86 (bfl, &fl->fl_block, fl_block)
F_167 ( V_189 , V_214 , V_212 -> V_215 , L_30 ) ;
return 0 ;
}
static void F_176 ( struct V_203 * V_189 ,
struct V_31 * V_216 , int * V_204 ,
struct V_47 * V_48 , struct V_217 * V_64 )
{
struct V_1 * V_2 ;
F_86 (fl, head, fl_list) {
if ( V_48 != V_2 -> V_34 )
continue;
if ( V_2 -> V_30 != V_64 &&
V_2 -> V_30 != V_48 )
continue;
( * V_204 ) ++ ;
F_169 ( V_189 , L_31 ) ;
F_167 ( V_189 , V_2 , * V_204 , L_29 ) ;
}
}
void F_177 ( struct V_203 * V_189 ,
struct V_47 * V_48 , struct V_217 * V_64 )
{
struct V_10 * V_10 = F_35 ( V_48 ) ;
struct V_9 * V_20 ;
int V_204 = 0 ;
V_20 = V_10 -> V_12 ;
if ( ! V_20 )
return;
F_65 ( & V_20 -> V_16 ) ;
F_176 ( V_189 , & V_20 -> V_17 , & V_204 , V_48 , V_64 ) ;
F_176 ( V_189 , & V_20 -> V_18 , & V_204 , V_48 , V_64 ) ;
F_176 ( V_189 , & V_20 -> V_19 , & V_204 , V_48 , V_64 ) ;
F_66 ( & V_20 -> V_16 ) ;
}
static void * F_178 ( struct V_203 * V_189 , T_1 * V_218 )
__acquires( &blocked_lock_lock
static void * F_179 ( struct V_203 * V_189 , void * V_210 , T_1 * V_218 )
{
struct V_211 * V_212 = V_189 -> V_213 ;
++ V_212 -> V_215 ;
return F_180 ( V_210 , & V_84 , & V_212 -> V_219 , V_218 ) ;
}
static void F_181 ( struct V_203 * V_189 , void * V_210 )
__releases( &blocked_lock_lock
static int F_182 ( struct V_10 * V_10 , struct V_47 * V_48 )
{
return F_183 ( V_48 , & V_220 ,
sizeof( struct V_211 ) ) ;
}
static int T_5 F_184 ( void )
{
F_185 ( L_32 , 0 , NULL , & V_221 ) ;
return 0 ;
}
static int T_5 F_186 ( void )
{
int V_98 ;
V_14 = F_187 ( L_33 ,
sizeof( struct V_9 ) , 0 , V_222 , NULL ) ;
V_25 = F_187 ( L_34 ,
sizeof( struct V_1 ) , 0 , V_222 , NULL ) ;
F_188 ( & V_82 , L_35 ) ;
F_189 (i)
F_190 ( F_191 ( & V_84 , V_98 ) ) ;
return 0 ;
}
