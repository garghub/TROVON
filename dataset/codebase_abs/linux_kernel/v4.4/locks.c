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
V_11 = F_4 ( & V_10 -> V_12 ) ;
if ( F_5 ( V_11 ) || type == V_6 )
goto V_13;
V_11 = F_6 ( V_14 , V_15 ) ;
if ( ! V_11 )
goto V_13;
F_7 ( & V_11 -> V_16 ) ;
F_8 ( & V_11 -> V_17 ) ;
F_8 ( & V_11 -> V_18 ) ;
F_8 ( & V_11 -> V_19 ) ;
if ( F_9 ( & V_10 -> V_12 , NULL , V_11 ) ) {
F_10 ( V_14 , V_11 ) ;
V_11 = F_4 ( & V_10 -> V_12 ) ;
}
V_13:
return V_11 ;
}
void
F_11 ( struct V_9 * V_11 )
{
if ( V_11 ) {
F_12 ( ! F_13 ( & V_11 -> V_17 ) ) ;
F_12 ( ! F_13 ( & V_11 -> V_18 ) ) ;
F_12 ( ! F_13 ( & V_11 -> V_19 ) ) ;
F_10 ( V_14 , V_11 ) ;
}
}
static void F_14 ( struct V_1 * V_2 )
{
F_15 ( & V_2 -> V_20 ) ;
F_8 ( & V_2 -> V_21 ) ;
F_8 ( & V_2 -> V_22 ) ;
F_16 ( & V_2 -> V_23 ) ;
}
struct V_1 * F_17 ( void )
{
struct V_1 * V_2 = F_18 ( V_24 , V_15 ) ;
if ( V_2 )
F_14 ( V_2 ) ;
return V_2 ;
}
void F_19 ( struct V_1 * V_2 )
{
if ( V_2 -> V_25 ) {
if ( V_2 -> V_25 -> V_26 )
V_2 -> V_25 -> V_26 ( V_2 ) ;
V_2 -> V_25 = NULL ;
}
if ( V_2 -> V_27 ) {
if ( V_2 -> V_27 -> V_28 ) {
V_2 -> V_27 -> V_28 ( V_2 -> V_29 ) ;
V_2 -> V_29 = NULL ;
}
V_2 -> V_27 = NULL ;
}
}
void F_20 ( struct V_1 * V_2 )
{
F_21 ( F_22 ( & V_2 -> V_23 ) ) ;
F_21 ( ! F_13 ( & V_2 -> V_21 ) ) ;
F_21 ( ! F_13 ( & V_2 -> V_22 ) ) ;
F_21 ( ! F_23 ( & V_2 -> V_20 ) ) ;
F_19 ( V_2 ) ;
F_10 ( V_24 , V_2 ) ;
}
static void
F_24 ( struct V_30 * V_31 )
{
struct V_1 * V_2 ;
while ( ! F_13 ( V_31 ) ) {
V_2 = F_25 ( V_31 , struct V_1 , V_21 ) ;
F_26 ( & V_2 -> V_21 ) ;
F_20 ( V_2 ) ;
}
}
void F_27 ( struct V_1 * V_2 )
{
memset ( V_2 , 0 , sizeof( struct V_1 ) ) ;
F_14 ( V_2 ) ;
}
void F_28 ( struct V_1 * V_32 , struct V_1 * V_2 )
{
V_32 -> V_29 = V_2 -> V_29 ;
V_32 -> V_33 = V_2 -> V_33 ;
V_32 -> V_34 = NULL ;
V_32 -> V_3 = V_2 -> V_3 ;
V_32 -> V_8 = V_2 -> V_8 ;
V_32 -> V_35 = V_2 -> V_35 ;
V_32 -> V_36 = V_2 -> V_36 ;
V_32 -> V_27 = V_2 -> V_27 ;
V_32 -> V_25 = NULL ;
if ( V_2 -> V_27 ) {
if ( V_2 -> V_27 -> V_37 )
V_2 -> V_27 -> V_37 ( V_2 -> V_29 ) ;
}
}
void F_29 ( struct V_1 * V_32 , struct V_1 * V_2 )
{
F_12 ( V_32 -> V_25 ) ;
F_28 ( V_32 , V_2 ) ;
V_32 -> V_34 = V_2 -> V_34 ;
V_32 -> V_25 = V_2 -> V_25 ;
if ( V_2 -> V_25 ) {
if ( V_2 -> V_25 -> V_38 )
V_2 -> V_25 -> V_38 ( V_32 , V_2 ) ;
}
}
static inline int F_30 ( int V_39 ) {
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
F_31 ( struct V_47 * V_48 , unsigned int V_39 )
{
struct V_1 * V_2 ;
int type = F_30 ( V_39 ) ;
if ( type < 0 )
return F_32 ( type ) ;
V_2 = F_17 () ;
if ( V_2 == NULL )
return F_32 ( - V_49 ) ;
V_2 -> V_34 = V_48 ;
V_2 -> V_29 = V_48 ;
V_2 -> V_33 = V_50 -> V_51 ;
V_2 -> V_3 = V_52 ;
V_2 -> V_8 = type ;
V_2 -> V_36 = V_53 ;
return V_2 ;
}
static int F_33 ( struct V_1 * V_2 , long type )
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
static int F_34 ( struct V_47 * V_48 , struct V_1 * V_2 ,
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
V_2 -> V_35 = F_35 ( F_36 ( V_48 ) ) ;
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
V_2 -> V_29 = V_50 -> V_64 ;
V_2 -> V_33 = V_50 -> V_51 ;
V_2 -> V_34 = V_48 ;
V_2 -> V_3 = V_65 ;
V_2 -> V_25 = NULL ;
V_2 -> V_27 = NULL ;
return F_33 ( V_2 , V_55 -> V_66 ) ;
}
static int F_37 ( struct V_47 * V_48 , struct V_1 * V_2 ,
struct V_67 * V_55 )
{
struct V_54 V_68 = {
. V_66 = V_55 -> V_66 ,
. V_56 = V_55 -> V_56 ,
. V_61 = V_55 -> V_61 ,
. V_63 = V_55 -> V_63 ,
} ;
return F_34 ( V_48 , V_2 , & V_68 ) ;
}
static bool
F_38 ( struct V_1 * V_2 )
{
F_39 ( & V_2 -> V_69 , V_70 , V_71 ) ;
return false ;
}
static void
F_40 ( struct V_1 * V_2 , void * * V_72 )
{
struct V_47 * V_48 = V_2 -> V_34 ;
struct V_73 * V_74 = * V_72 ;
if ( ! F_41 ( V_74 -> V_75 , V_48 , & V_2 -> V_69 , V_74 ) )
* V_72 = NULL ;
F_42 ( V_48 , F_43 ( V_50 ) , V_76 , 0 ) ;
}
static int F_44 ( struct V_47 * V_48 , long type , struct V_1 * V_2 )
{
if ( F_33 ( V_2 , type ) != 0 )
return - V_46 ;
V_2 -> V_29 = V_48 ;
V_2 -> V_33 = V_50 -> V_51 ;
V_2 -> V_34 = V_48 ;
V_2 -> V_3 = V_77 ;
V_2 -> V_35 = 0 ;
V_2 -> V_36 = V_53 ;
V_2 -> V_25 = NULL ;
V_2 -> V_27 = & V_78 ;
return 0 ;
}
static struct V_1 * F_45 ( struct V_47 * V_48 , long type )
{
struct V_1 * V_2 = F_17 () ;
int error = - V_49 ;
if ( V_2 == NULL )
return F_32 ( error ) ;
error = F_44 ( V_48 , type , V_2 ) ;
if ( error ) {
F_20 ( V_2 ) ;
return F_32 ( error ) ;
}
return V_2 ;
}
static inline int F_46 ( struct V_1 * V_79 , struct V_1 * V_80 )
{
return ( ( V_79 -> V_36 >= V_80 -> V_35 ) &&
( V_80 -> V_36 >= V_79 -> V_35 ) ) ;
}
static int F_47 ( struct V_1 * V_79 , struct V_1 * V_80 )
{
if ( V_79 -> V_27 && V_79 -> V_27 -> V_81 )
return V_80 -> V_27 == V_79 -> V_27 &&
V_79 -> V_27 -> V_81 ( V_79 , V_80 ) ;
return V_79 -> V_29 == V_80 -> V_29 ;
}
static void F_48 ( struct V_1 * V_2 )
{
F_49 ( & V_82 ) ;
V_2 -> V_83 = F_50 () ;
F_51 ( & V_2 -> V_20 , F_52 ( & V_84 ) ) ;
F_53 ( & V_82 ) ;
}
static void F_54 ( struct V_1 * V_2 )
{
if ( F_23 ( & V_2 -> V_20 ) )
return;
F_55 ( & V_82 , V_2 -> V_83 ) ;
F_56 ( & V_2 -> V_20 ) ;
F_57 ( & V_82 , V_2 -> V_83 ) ;
}
static unsigned long
F_58 ( struct V_1 * V_2 )
{
if ( V_2 -> V_27 && V_2 -> V_27 -> V_85 )
return V_2 -> V_27 -> V_85 ( V_2 ) ;
return ( unsigned long ) V_2 -> V_29 ;
}
static void F_59 ( struct V_1 * V_86 )
{
F_60 ( & V_87 ) ;
F_61 ( V_88 , & V_86 -> V_20 , F_58 ( V_86 ) ) ;
}
static void F_62 ( struct V_1 * V_86 )
{
F_60 ( & V_87 ) ;
F_63 ( & V_86 -> V_20 ) ;
}
static void F_64 ( struct V_1 * V_86 )
{
F_62 ( V_86 ) ;
F_26 ( & V_86 -> V_22 ) ;
V_86 -> V_89 = NULL ;
}
static void F_65 ( struct V_1 * V_86 )
{
F_66 ( & V_87 ) ;
F_64 ( V_86 ) ;
F_67 ( & V_87 ) ;
}
static void F_68 ( struct V_1 * V_90 ,
struct V_1 * V_86 )
{
F_21 ( ! F_13 ( & V_86 -> V_22 ) ) ;
V_86 -> V_89 = V_90 ;
F_69 ( & V_86 -> V_22 , & V_90 -> V_22 ) ;
if ( F_70 ( V_90 ) && ! F_71 ( V_90 ) )
F_59 ( V_86 ) ;
}
static void F_72 ( struct V_1 * V_90 ,
struct V_1 * V_86 )
{
F_66 ( & V_87 ) ;
F_68 ( V_90 , V_86 ) ;
F_67 ( & V_87 ) ;
}
static void F_73 ( struct V_1 * V_90 )
{
if ( F_13 ( & V_90 -> V_22 ) )
return;
F_66 ( & V_87 ) ;
while ( ! F_13 ( & V_90 -> V_22 ) ) {
struct V_1 * V_86 ;
V_86 = F_25 ( & V_90 -> V_22 ,
struct V_1 , V_22 ) ;
F_64 ( V_86 ) ;
if ( V_86 -> V_27 && V_86 -> V_27 -> V_91 )
V_86 -> V_27 -> V_91 ( V_86 ) ;
else
F_74 ( & V_86 -> V_23 ) ;
}
F_67 ( & V_87 ) ;
}
static void
F_75 ( struct V_1 * V_2 , struct V_30 * V_92 )
{
V_2 -> V_93 = F_76 ( F_77 ( V_50 ) ) ;
F_69 ( & V_2 -> V_21 , V_92 ) ;
F_48 ( V_2 ) ;
}
static void
F_78 ( struct V_1 * V_2 )
{
F_54 ( V_2 ) ;
F_26 ( & V_2 -> V_21 ) ;
if ( V_2 -> V_93 ) {
F_79 ( V_2 -> V_93 ) ;
V_2 -> V_93 = NULL ;
}
F_73 ( V_2 ) ;
}
static void
F_80 ( struct V_1 * V_2 , struct V_30 * V_31 )
{
F_78 ( V_2 ) ;
if ( V_31 )
F_81 ( & V_2 -> V_21 , V_31 ) ;
else
F_20 ( V_2 ) ;
}
static int F_82 ( struct V_1 * V_94 , struct V_1 * V_95 )
{
if ( V_95 -> V_8 == V_44 )
return 1 ;
if ( V_94 -> V_8 == V_44 )
return 1 ;
return 0 ;
}
static int F_83 ( struct V_1 * V_94 , struct V_1 * V_95 )
{
if ( F_47 ( V_94 , V_95 ) )
return ( 0 ) ;
if ( ! F_46 ( V_94 , V_95 ) )
return 0 ;
return ( F_82 ( V_94 , V_95 ) ) ;
}
static int F_84 ( struct V_1 * V_94 , struct V_1 * V_95 )
{
if ( V_94 -> V_34 == V_95 -> V_34 )
return ( 0 ) ;
if ( ( V_94 -> V_8 & V_40 ) || ( V_95 -> V_8 & V_40 ) )
return 0 ;
return ( F_82 ( V_94 , V_95 ) ) ;
}
void
F_85 ( struct V_47 * V_48 , struct V_1 * V_2 )
{
struct V_1 * V_96 ;
struct V_9 * V_11 ;
struct V_10 * V_10 = F_36 ( V_48 ) ;
V_11 = F_4 ( & V_10 -> V_12 ) ;
if ( ! V_11 || F_86 ( & V_11 -> V_18 ) ) {
V_2 -> V_8 = V_6 ;
return;
}
F_66 ( & V_11 -> V_16 ) ;
F_87 (cfl, &ctx->flc_posix, fl_list) {
if ( F_83 ( V_2 , V_96 ) ) {
F_28 ( V_2 , V_96 ) ;
if ( V_96 -> V_93 )
V_2 -> V_33 = F_88 ( V_96 -> V_93 ) ;
goto V_13;
}
}
V_2 -> V_8 = V_6 ;
V_13:
F_67 ( & V_11 -> V_16 ) ;
return;
}
static struct V_1 * F_89 ( struct V_1 * V_97 )
{
struct V_1 * V_2 ;
F_90 (blocked_hash, fl, fl_link, posix_owner_key(block_fl)) {
if ( F_47 ( V_2 , V_97 ) )
return V_2 -> V_89 ;
}
return NULL ;
}
static int F_91 ( struct V_1 * V_94 ,
struct V_1 * V_97 )
{
int V_98 = 0 ;
F_60 ( & V_87 ) ;
if ( F_71 ( V_94 ) )
return 0 ;
while ( ( V_97 = F_89 ( V_97 ) ) ) {
if ( V_98 ++ > V_99 )
return 0 ;
if ( F_47 ( V_94 , V_97 ) )
return 1 ;
}
return 0 ;
}
static int F_92 ( struct V_10 * V_10 , struct V_1 * V_100 )
{
struct V_1 * V_101 = NULL ;
struct V_1 * V_2 ;
struct V_9 * V_11 ;
int error = 0 ;
bool V_102 = false ;
F_93 ( V_31 ) ;
V_11 = F_3 ( V_10 , V_100 -> V_8 ) ;
if ( ! V_11 ) {
if ( V_100 -> V_8 != V_6 )
return - V_49 ;
return ( V_100 -> V_3 & V_103 ) ? - V_104 : 0 ;
}
if ( ! ( V_100 -> V_3 & V_105 ) && ( V_100 -> V_8 != V_6 ) ) {
V_101 = F_17 () ;
if ( ! V_101 )
return - V_49 ;
}
F_66 ( & V_11 -> V_16 ) ;
if ( V_100 -> V_3 & V_105 )
goto V_106;
F_87 (fl, &ctx->flc_flock, fl_list) {
if ( V_100 -> V_34 != V_2 -> V_34 )
continue;
if ( V_100 -> V_8 == V_2 -> V_8 )
goto V_13;
V_102 = true ;
F_80 ( V_2 , & V_31 ) ;
break;
}
if ( V_100 -> V_8 == V_6 ) {
if ( ( V_100 -> V_3 & V_103 ) && ! V_102 )
error = - V_104 ;
goto V_13;
}
V_106:
F_87 (fl, &ctx->flc_flock, fl_list) {
if ( ! F_84 ( V_100 , V_2 ) )
continue;
error = - V_107 ;
if ( ! ( V_100 -> V_3 & V_108 ) )
goto V_13;
error = V_109 ;
F_72 ( V_2 , V_100 ) ;
goto V_13;
}
if ( V_100 -> V_3 & V_105 )
goto V_13;
F_29 ( V_101 , V_100 ) ;
F_75 ( V_101 , & V_11 -> V_17 ) ;
V_101 = NULL ;
error = 0 ;
V_13:
F_67 ( & V_11 -> V_16 ) ;
if ( V_101 )
F_20 ( V_101 ) ;
F_24 ( & V_31 ) ;
return error ;
}
static int F_94 ( struct V_10 * V_10 , struct V_1 * V_100 , struct V_1 * V_110 )
{
struct V_1 * V_2 , * V_111 ;
struct V_1 * V_101 = NULL ;
struct V_1 * V_112 = NULL ;
struct V_1 * V_113 = NULL ;
struct V_1 * V_114 = NULL ;
struct V_9 * V_11 ;
int error ;
bool V_115 = false ;
F_93 ( V_31 ) ;
V_11 = F_3 ( V_10 , V_100 -> V_8 ) ;
if ( ! V_11 )
return ( V_100 -> V_8 == V_6 ) ? 0 : - V_49 ;
if ( ! ( V_100 -> V_3 & V_105 ) &&
( V_100 -> V_8 != V_6 ||
V_100 -> V_35 != 0 || V_100 -> V_36 != V_53 ) ) {
V_101 = F_17 () ;
V_112 = F_17 () ;
}
F_66 ( & V_11 -> V_16 ) ;
if ( V_100 -> V_8 != V_6 ) {
F_87 (fl, &ctx->flc_posix, fl_list) {
if ( ! F_83 ( V_100 , V_2 ) )
continue;
if ( V_110 )
F_28 ( V_110 , V_2 ) ;
error = - V_107 ;
if ( ! ( V_100 -> V_3 & V_108 ) )
goto V_13;
error = - V_116 ;
F_66 ( & V_87 ) ;
if ( F_5 ( ! F_91 ( V_100 , V_2 ) ) ) {
error = V_109 ;
F_68 ( V_2 , V_100 ) ;
}
F_67 ( & V_87 ) ;
goto V_13;
}
}
error = 0 ;
if ( V_100 -> V_3 & V_105 )
goto V_13;
F_87 (fl, &ctx->flc_posix, fl_list) {
if ( F_47 ( V_100 , V_2 ) )
break;
}
F_95 (fl, tmp, &ctx->flc_posix, fl_list) {
if ( ! F_47 ( V_100 , V_2 ) )
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
F_80 ( V_2 , & V_31 ) ;
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
F_80 ( V_2 , & V_31 ) ;
continue;
}
error = - V_117 ;
if ( ! V_101 )
goto V_13;
F_29 ( V_101 , V_100 ) ;
V_100 = V_101 ;
V_101 = NULL ;
F_75 ( V_100 , & V_2 -> V_21 ) ;
F_80 ( V_2 , & V_31 ) ;
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
F_29 ( V_101 , V_100 ) ;
F_75 ( V_101 , & V_2 -> V_21 ) ;
V_2 = V_101 ;
V_101 = NULL ;
}
if ( V_114 ) {
if ( V_113 == V_114 ) {
V_113 = V_112 ;
V_112 = NULL ;
F_29 ( V_113 , V_114 ) ;
F_75 ( V_113 , & V_2 -> V_21 ) ;
}
V_114 -> V_35 = V_100 -> V_36 + 1 ;
F_73 ( V_114 ) ;
}
if ( V_113 ) {
V_113 -> V_36 = V_100 -> V_35 - 1 ;
F_73 ( V_113 ) ;
}
V_13:
F_67 ( & V_11 -> V_16 ) ;
if ( V_101 )
F_20 ( V_101 ) ;
if ( V_112 )
F_20 ( V_112 ) ;
F_24 ( & V_31 ) ;
return error ;
}
int F_96 ( struct V_47 * V_48 , struct V_1 * V_2 ,
struct V_1 * V_110 )
{
return F_94 ( F_36 ( V_48 ) , V_2 , V_110 ) ;
}
static int F_97 ( struct V_10 * V_10 , struct V_1 * V_2 )
{
int error ;
F_98 () ;
for (; ; ) {
error = F_94 ( V_10 , V_2 , NULL ) ;
if ( error != V_109 )
break;
error = F_99 ( V_2 -> V_23 , ! V_2 -> V_89 ) ;
if ( ! error )
continue;
F_65 ( V_2 ) ;
break;
}
return error ;
}
int F_100 ( struct V_47 * V_47 )
{
int V_118 ;
struct V_10 * V_10 = F_36 ( V_47 ) ;
struct V_9 * V_11 ;
struct V_1 * V_2 ;
V_11 = F_4 ( & V_10 -> V_12 ) ;
if ( ! V_11 || F_86 ( & V_11 -> V_18 ) )
return 0 ;
F_66 ( & V_11 -> V_16 ) ;
V_118 = 0 ;
F_87 (fl, &ctx->flc_posix, fl_list) {
if ( V_2 -> V_29 != V_50 -> V_64 &&
V_2 -> V_29 != V_47 ) {
V_118 = - V_107 ;
break;
}
}
F_67 ( & V_11 -> V_16 ) ;
return V_118 ;
}
int F_101 ( int V_119 , struct V_10 * V_10 ,
struct V_47 * V_48 , T_1 V_120 ,
T_2 V_121 )
{
struct V_1 V_2 ;
int error ;
bool V_122 = false ;
F_27 ( & V_2 ) ;
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
V_2 . V_29 = V_48 ;
V_2 . V_3 &= ~ V_108 ;
error = F_94 ( V_10 , & V_2 , NULL ) ;
if ( ! error )
break;
}
if ( V_122 )
V_2 . V_3 |= V_108 ;
V_2 . V_29 = V_50 -> V_64 ;
error = F_94 ( V_10 , & V_2 , NULL ) ;
if ( error != V_109 )
break;
error = F_99 ( V_2 . V_23 , ! V_2 . V_89 ) ;
if ( ! error ) {
if ( F_102 ( V_10 ) )
continue;
}
F_65 ( & V_2 ) ;
break;
}
return error ;
}
static void F_103 ( struct V_1 * V_2 , int V_126 )
{
switch ( V_126 ) {
case V_6 :
V_2 -> V_3 &= ~ V_4 ;
case V_7 :
V_2 -> V_3 &= ~ V_5 ;
}
}
int F_104 ( struct V_1 * V_2 , int V_126 , struct V_30 * V_31 )
{
int error = F_33 ( V_2 , V_126 ) ;
if ( error )
return error ;
F_103 ( V_2 , V_126 ) ;
F_73 ( V_2 ) ;
if ( V_126 == V_6 ) {
struct V_47 * V_48 = V_2 -> V_34 ;
F_105 ( V_48 ) ;
V_48 -> V_127 . V_128 = 0 ;
F_106 ( 0 , V_2 -> V_34 , 0 , & V_2 -> V_69 ) ;
if ( V_2 -> V_69 != NULL ) {
F_107 ( V_129 L_1 , V_2 -> V_69 ) ;
V_2 -> V_69 = NULL ;
}
F_80 ( V_2 , V_31 ) ;
}
return 0 ;
}
static bool F_108 ( unsigned long V_130 )
{
if ( ! V_130 )
return false ;
return F_109 ( V_131 , V_130 ) ;
}
static void F_110 ( struct V_10 * V_10 , struct V_30 * V_31 )
{
struct V_9 * V_11 = V_10 -> V_12 ;
struct V_1 * V_2 , * V_111 ;
F_60 ( & V_11 -> V_16 ) ;
F_111 (fl, tmp, &ctx->flc_lease, fl_list) {
F_112 ( V_10 , V_2 ) ;
if ( F_108 ( V_2 -> V_132 ) )
F_104 ( V_2 , V_7 , V_31 ) ;
if ( F_108 ( V_2 -> V_133 ) )
F_104 ( V_2 , V_6 , V_31 ) ;
}
}
static bool F_113 ( struct V_1 * V_134 , struct V_1 * V_135 )
{
if ( ( V_135 -> V_3 & V_136 ) != ( V_134 -> V_3 & V_136 ) )
return false ;
if ( ( V_135 -> V_3 & V_137 ) && ( V_134 -> V_3 & V_77 ) )
return false ;
return F_82 ( V_135 , V_134 ) ;
}
static bool
F_114 ( struct V_10 * V_10 , struct V_1 * V_135 )
{
struct V_9 * V_11 = V_10 -> V_12 ;
struct V_1 * V_2 ;
F_60 ( & V_11 -> V_16 ) ;
F_87 (fl, &ctx->flc_lease, fl_list) {
if ( F_113 ( V_2 , V_135 ) )
return true ;
}
return false ;
}
int F_115 ( struct V_10 * V_10 , unsigned int V_138 , unsigned int type )
{
int error = 0 ;
struct V_9 * V_11 ;
struct V_1 * V_101 , * V_2 , * V_111 ;
unsigned long V_139 ;
int V_140 = ( V_138 & V_141 ) != V_142 ;
F_93 ( V_31 ) ;
V_101 = F_45 ( NULL , V_140 ? V_44 : V_7 ) ;
if ( F_116 ( V_101 ) )
return F_117 ( V_101 ) ;
V_101 -> V_3 = type ;
V_11 = F_4 ( & V_10 -> V_12 ) ;
if ( ! V_11 ) {
F_12 ( 1 ) ;
return error ;
}
F_66 ( & V_11 -> V_16 ) ;
F_110 ( V_10 , & V_31 ) ;
if ( ! F_114 ( V_10 , V_101 ) )
goto V_13;
V_139 = 0 ;
if ( V_143 > 0 ) {
V_139 = V_131 + V_143 * V_144 ;
if ( V_139 == 0 )
V_139 ++ ;
}
F_111 (fl, tmp, &ctx->flc_lease, fl_list) {
if ( ! F_113 ( V_2 , V_101 ) )
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
if ( V_2 -> V_27 -> V_145 ( V_2 ) )
F_80 ( V_2 , & V_31 ) ;
}
if ( F_13 ( & V_11 -> V_19 ) )
goto V_13;
if ( V_138 & V_124 ) {
F_118 ( V_10 , V_101 ) ;
error = - V_146 ;
goto V_13;
}
V_147:
V_2 = F_25 ( & V_11 -> V_19 , struct V_1 , V_21 ) ;
V_139 = V_2 -> V_133 ;
if ( V_139 != 0 )
V_139 -= V_131 ;
if ( V_139 == 0 )
V_139 ++ ;
F_72 ( V_2 , V_101 ) ;
F_119 ( V_10 , V_101 ) ;
F_67 ( & V_11 -> V_16 ) ;
F_24 ( & V_31 ) ;
error = F_120 ( V_101 -> V_23 ,
! V_101 -> V_89 , V_139 ) ;
F_66 ( & V_11 -> V_16 ) ;
F_121 ( V_10 , V_101 ) ;
F_65 ( V_101 ) ;
if ( error >= 0 ) {
if ( error == 0 )
F_110 ( V_10 , & V_31 ) ;
if ( F_114 ( V_10 , V_101 ) )
goto V_147;
error = 0 ;
}
V_13:
F_67 ( & V_11 -> V_16 ) ;
F_24 ( & V_31 ) ;
F_20 ( V_101 ) ;
return error ;
}
void F_122 ( struct V_10 * V_10 , struct V_148 * time )
{
bool V_149 = false ;
struct V_9 * V_11 ;
struct V_1 * V_2 ;
V_11 = F_4 ( & V_10 -> V_12 ) ;
if ( V_11 && ! F_86 ( & V_11 -> V_19 ) ) {
F_66 ( & V_11 -> V_16 ) ;
if ( ! F_13 ( & V_11 -> V_19 ) ) {
V_2 = F_25 ( & V_11 -> V_19 ,
struct V_1 , V_21 ) ;
if ( V_2 -> V_8 == V_44 )
V_149 = true ;
}
F_67 ( & V_11 -> V_16 ) ;
}
if ( V_149 )
* time = F_123 ( V_10 -> V_150 ) ;
else
* time = V_10 -> V_151 ;
}
int F_124 ( struct V_47 * V_48 )
{
struct V_1 * V_2 ;
struct V_10 * V_10 = F_36 ( V_48 ) ;
struct V_9 * V_11 ;
int type = V_6 ;
F_93 ( V_31 ) ;
V_11 = F_4 ( & V_10 -> V_12 ) ;
if ( V_11 && ! F_86 ( & V_11 -> V_19 ) ) {
F_66 ( & V_11 -> V_16 ) ;
F_110 ( F_36 ( V_48 ) , & V_31 ) ;
F_87 (fl, &ctx->flc_lease, fl_list) {
if ( V_2 -> V_34 != V_48 )
continue;
type = F_2 ( V_2 ) ;
break;
}
F_67 ( & V_11 -> V_16 ) ;
F_24 ( & V_31 ) ;
}
return type ;
}
static int
F_125 ( const struct V_152 * V_152 , const long V_126 , int V_153 )
{
int V_118 = 0 ;
struct V_10 * V_10 = V_152 -> V_154 ;
if ( V_153 & V_136 )
return 0 ;
if ( ( V_126 == V_7 ) && ( F_126 ( & V_10 -> V_155 ) > 0 ) )
return - V_107 ;
if ( ( V_126 == V_44 ) && ( ( F_127 ( V_152 ) > 1 ) ||
( F_126 ( & V_10 -> V_156 ) > 1 ) ) )
V_118 = - V_107 ;
return V_118 ;
}
static int
F_128 ( struct V_47 * V_48 , long V_126 , struct V_1 * * V_157 , void * * V_72 )
{
struct V_1 * V_2 , * V_158 = NULL , * V_134 ;
struct V_152 * V_152 = V_48 -> V_159 . V_152 ;
struct V_10 * V_10 = V_152 -> V_154 ;
struct V_9 * V_11 ;
bool V_160 = ( * V_157 ) -> V_3 & V_137 ;
int error ;
F_93 ( V_31 ) ;
V_134 = * V_157 ;
F_129 ( V_10 , V_134 ) ;
V_11 = F_3 ( V_10 , V_126 ) ;
if ( ! V_11 )
return - V_49 ;
if ( V_160 && ! F_130 ( & V_10 -> V_161 ) )
return - V_107 ;
if ( V_160 && V_126 == V_44 ) {
F_131 ( & V_10 -> V_161 ) ;
F_12 ( 1 ) ;
return - V_46 ;
}
F_66 ( & V_11 -> V_16 ) ;
F_110 ( V_10 , & V_31 ) ;
error = F_125 ( V_152 , V_126 , V_134 -> V_3 ) ;
if ( error )
goto V_13;
error = - V_107 ;
F_87 (fl, &ctx->flc_lease, fl_list) {
if ( V_2 -> V_34 == V_48 &&
V_2 -> V_29 == V_134 -> V_29 ) {
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
error = V_134 -> V_27 -> V_162 ( V_134 , V_126 , & V_31 ) ;
if ( error )
goto V_13;
goto V_163;
}
error = - V_46 ;
if ( ! V_164 )
goto V_13;
F_75 ( V_134 , & V_11 -> V_19 ) ;
F_132 () ;
error = F_125 ( V_152 , V_126 , V_134 -> V_3 ) ;
if ( error ) {
F_78 ( V_134 ) ;
goto V_13;
}
V_163:
if ( V_134 -> V_27 -> V_165 )
V_134 -> V_27 -> V_165 ( V_134 , V_72 ) ;
V_13:
F_67 ( & V_11 -> V_16 ) ;
F_24 ( & V_31 ) ;
if ( V_160 )
F_131 ( & V_10 -> V_161 ) ;
if ( ! error && ! V_158 )
* V_157 = NULL ;
return error ;
}
static int F_133 ( struct V_47 * V_48 , void * V_166 )
{
int error = - V_107 ;
struct V_1 * V_2 , * V_167 = NULL ;
struct V_10 * V_10 = F_36 ( V_48 ) ;
struct V_9 * V_11 ;
F_93 ( V_31 ) ;
V_11 = F_4 ( & V_10 -> V_12 ) ;
if ( ! V_11 ) {
F_134 ( V_10 , NULL ) ;
return error ;
}
F_66 ( & V_11 -> V_16 ) ;
F_87 (fl, &ctx->flc_lease, fl_list) {
if ( V_2 -> V_34 == V_48 &&
V_2 -> V_29 == V_166 ) {
V_167 = V_2 ;
break;
}
}
F_134 ( V_10 , V_167 ) ;
if ( V_167 )
error = V_2 -> V_27 -> V_162 ( V_167 , V_6 , & V_31 ) ;
F_67 ( & V_11 -> V_16 ) ;
F_24 ( & V_31 ) ;
return error ;
}
int F_135 ( struct V_47 * V_48 , long V_126 , struct V_1 * * V_157 ,
void * * V_72 )
{
struct V_10 * V_10 = F_36 ( V_48 ) ;
int error ;
if ( ( ! F_136 ( F_137 () , V_10 -> V_168 ) ) && ! F_138 ( V_169 ) )
return - V_170 ;
if ( ! F_139 ( V_10 -> V_171 ) )
return - V_46 ;
error = F_140 ( V_48 , V_126 ) ;
if ( error )
return error ;
switch ( V_126 ) {
case V_6 :
return F_133 ( V_48 , * V_72 ) ;
case V_7 :
case V_44 :
if ( ! ( * V_157 ) -> V_27 -> V_145 ) {
F_12 ( 1 ) ;
return - V_117 ;
}
return F_128 ( V_48 , V_126 , V_157 , V_72 ) ;
default:
return - V_46 ;
}
}
int
F_141 ( struct V_47 * V_48 , long V_126 , struct V_1 * * V_134 , void * * V_72 )
{
if ( V_48 -> V_172 -> V_173 )
return V_48 -> V_172 -> V_173 ( V_48 , V_126 , V_134 , V_72 ) ;
else
return F_135 ( V_48 , V_126 , V_134 , V_72 ) ;
}
static int F_142 ( unsigned int V_174 , struct V_47 * V_48 , long V_126 )
{
struct V_1 * V_2 ;
struct V_73 * V_32 ;
int error ;
V_2 = F_45 ( V_48 , V_126 ) ;
if ( F_116 ( V_2 ) )
return F_117 ( V_2 ) ;
V_32 = F_143 () ;
if ( ! V_32 ) {
F_20 ( V_2 ) ;
return - V_49 ;
}
V_32 -> V_75 = V_174 ;
error = F_141 ( V_48 , V_126 , & V_2 , ( void * * ) & V_32 ) ;
if ( V_2 )
F_20 ( V_2 ) ;
if ( V_32 )
F_144 ( V_32 ) ;
return error ;
}
int F_145 ( unsigned int V_174 , struct V_47 * V_48 , long V_126 )
{
if ( V_126 == V_6 )
return F_141 ( V_48 , V_6 , NULL , ( void * * ) & V_48 ) ;
return F_142 ( V_174 , V_48 , V_126 ) ;
}
static int F_146 ( struct V_10 * V_10 , struct V_1 * V_2 )
{
int error ;
F_98 () ;
for (; ; ) {
error = F_92 ( V_10 , V_2 ) ;
if ( error != V_109 )
break;
error = F_99 ( V_2 -> V_23 , ! V_2 -> V_89 ) ;
if ( ! error )
continue;
F_65 ( V_2 ) ;
break;
}
return error ;
}
int F_147 ( struct V_10 * V_10 , struct V_1 * V_2 )
{
int V_175 = 0 ;
switch ( V_2 -> V_3 & ( V_65 | V_52 ) ) {
case V_65 :
V_175 = F_97 ( V_10 , V_2 ) ;
break;
case V_52 :
V_175 = F_146 ( V_10 , V_2 ) ;
break;
default:
F_148 () ;
}
return V_175 ;
}
int F_149 ( struct V_47 * V_48 , struct V_1 * V_2 )
{
if ( V_48 -> V_172 -> V_176 )
return V_48 -> V_172 -> V_176 ( V_48 , V_177 , V_2 ) ;
F_85 ( V_48 , V_2 ) ;
return 0 ;
}
static int F_150 ( struct V_67 * V_67 , struct V_1 * V_2 )
{
V_67 -> V_178 = F_71 ( V_2 ) ? - 1 : V_2 -> V_33 ;
#if V_179 == 32
if ( V_2 -> V_35 > V_180 )
return - V_62 ;
if ( V_2 -> V_36 != V_53 && V_2 -> V_36 > V_180 )
return - V_62 ;
#endif
V_67 -> V_61 = V_2 -> V_35 ;
V_67 -> V_63 = V_2 -> V_36 == V_53 ? 0 :
V_2 -> V_36 - V_2 -> V_35 + 1 ;
V_67 -> V_56 = 0 ;
V_67 -> V_66 = V_2 -> V_8 ;
return 0 ;
}
static void F_151 ( struct V_54 * V_67 , struct V_1 * V_2 )
{
V_67 -> V_178 = F_71 ( V_2 ) ? - 1 : V_2 -> V_33 ;
V_67 -> V_61 = V_2 -> V_35 ;
V_67 -> V_63 = V_2 -> V_36 == V_53 ? 0 :
V_2 -> V_36 - V_2 -> V_35 + 1 ;
V_67 -> V_56 = 0 ;
V_67 -> V_66 = V_2 -> V_8 ;
}
int F_152 ( struct V_47 * V_48 , unsigned int V_39 , struct V_67 T_3 * V_55 )
{
struct V_1 V_1 ;
struct V_67 V_67 ;
int error ;
error = - V_181 ;
if ( F_153 ( & V_67 , V_55 , sizeof( V_67 ) ) )
goto V_13;
error = - V_46 ;
if ( ( V_67 . V_66 != V_7 ) && ( V_67 . V_66 != V_44 ) )
goto V_13;
error = F_37 ( V_48 , & V_1 , & V_67 ) ;
if ( error )
goto V_13;
if ( V_39 == V_182 ) {
error = - V_46 ;
if ( V_67 . V_178 != 0 )
goto V_13;
V_39 = V_177 ;
V_1 . V_3 |= V_183 ;
V_1 . V_29 = V_48 ;
}
error = F_149 ( V_48 , & V_1 ) ;
if ( error )
goto V_13;
V_67 . V_66 = V_1 . V_8 ;
if ( V_1 . V_8 != V_6 ) {
error = F_150 ( & V_67 , & V_1 ) ;
if ( error )
goto V_184;
}
error = - V_181 ;
if ( ! F_154 ( V_55 , & V_67 , sizeof( V_67 ) ) )
error = 0 ;
V_184:
F_19 ( & V_1 ) ;
V_13:
return error ;
}
int F_155 ( struct V_47 * V_48 , unsigned int V_39 , struct V_1 * V_2 , struct V_1 * V_185 )
{
if ( V_48 -> V_172 -> V_176 )
return V_48 -> V_172 -> V_176 ( V_48 , V_39 , V_2 ) ;
else
return F_96 ( V_48 , V_2 , V_185 ) ;
}
static int F_156 ( struct V_47 * V_48 , unsigned int V_39 ,
struct V_1 * V_2 )
{
int error ;
error = F_140 ( V_48 , V_2 -> V_8 ) ;
if ( error )
return error ;
for (; ; ) {
error = F_155 ( V_48 , V_39 , V_2 , NULL ) ;
if ( error != V_109 )
break;
error = F_99 ( V_2 -> V_23 , ! V_2 -> V_89 ) ;
if ( ! error )
continue;
F_65 ( V_2 ) ;
break;
}
return error ;
}
static int
F_157 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_8 ) {
case V_7 :
if ( ! ( V_2 -> V_34 -> V_186 & V_187 ) )
return - V_188 ;
break;
case V_44 :
if ( ! ( V_2 -> V_34 -> V_186 & V_189 ) )
return - V_188 ;
}
return 0 ;
}
int F_158 ( unsigned int V_174 , struct V_47 * V_48 , unsigned int V_39 ,
struct V_67 T_3 * V_55 )
{
struct V_1 * V_1 = F_17 () ;
struct V_67 V_67 ;
struct V_10 * V_10 ;
struct V_47 * V_190 ;
int error ;
if ( V_1 == NULL )
return - V_117 ;
error = - V_181 ;
if ( F_153 ( & V_67 , V_55 , sizeof( V_67 ) ) )
goto V_13;
V_10 = F_36 ( V_48 ) ;
if ( F_159 ( V_10 ) && F_160 ( V_48 -> V_191 ) ) {
error = - V_107 ;
goto V_13;
}
V_192:
error = F_37 ( V_48 , V_1 , & V_67 ) ;
if ( error )
goto V_13;
error = F_157 ( V_1 ) ;
if ( error )
goto V_13;
switch ( V_39 ) {
case V_193 :
error = - V_46 ;
if ( V_67 . V_178 != 0 )
goto V_13;
V_39 = V_194 ;
V_1 -> V_3 |= V_183 ;
V_1 -> V_29 = V_48 ;
break;
case V_195 :
error = - V_46 ;
if ( V_67 . V_178 != 0 )
goto V_13;
V_39 = V_196 ;
V_1 -> V_3 |= V_183 ;
V_1 -> V_29 = V_48 ;
case V_196 :
V_1 -> V_3 |= V_108 ;
}
error = F_156 ( V_48 , V_39 , V_1 ) ;
F_66 ( & V_50 -> V_64 -> V_1 ) ;
V_190 = F_161 ( V_174 ) ;
F_67 ( & V_50 -> V_64 -> V_1 ) ;
if ( ! error && V_190 != V_48 && V_67 . V_66 != V_6 ) {
V_67 . V_66 = V_6 ;
goto V_192;
}
V_13:
F_20 ( V_1 ) ;
return error ;
}
int F_162 ( struct V_47 * V_48 , unsigned int V_39 , struct V_54 T_3 * V_55 )
{
struct V_1 V_1 ;
struct V_54 V_67 ;
int error ;
error = - V_181 ;
if ( F_153 ( & V_67 , V_55 , sizeof( V_67 ) ) )
goto V_13;
error = - V_46 ;
if ( ( V_67 . V_66 != V_7 ) && ( V_67 . V_66 != V_44 ) )
goto V_13;
error = F_34 ( V_48 , & V_1 , & V_67 ) ;
if ( error )
goto V_13;
if ( V_39 == V_182 ) {
error = - V_46 ;
if ( V_67 . V_178 != 0 )
goto V_13;
V_39 = V_197 ;
V_1 . V_3 |= V_183 ;
V_1 . V_29 = V_48 ;
}
error = F_149 ( V_48 , & V_1 ) ;
if ( error )
goto V_13;
V_67 . V_66 = V_1 . V_8 ;
if ( V_1 . V_8 != V_6 )
F_151 ( & V_67 , & V_1 ) ;
error = - V_181 ;
if ( ! F_154 ( V_55 , & V_67 , sizeof( V_67 ) ) )
error = 0 ;
F_19 ( & V_1 ) ;
V_13:
return error ;
}
int F_163 ( unsigned int V_174 , struct V_47 * V_48 , unsigned int V_39 ,
struct V_54 T_3 * V_55 )
{
struct V_1 * V_1 = F_17 () ;
struct V_54 V_67 ;
struct V_10 * V_10 ;
struct V_47 * V_190 ;
int error ;
if ( V_1 == NULL )
return - V_117 ;
error = - V_181 ;
if ( F_153 ( & V_67 , V_55 , sizeof( V_67 ) ) )
goto V_13;
V_10 = F_36 ( V_48 ) ;
if ( F_159 ( V_10 ) && F_160 ( V_48 -> V_191 ) ) {
error = - V_107 ;
goto V_13;
}
V_192:
error = F_34 ( V_48 , V_1 , & V_67 ) ;
if ( error )
goto V_13;
error = F_157 ( V_1 ) ;
if ( error )
goto V_13;
switch ( V_39 ) {
case V_193 :
error = - V_46 ;
if ( V_67 . V_178 != 0 )
goto V_13;
V_39 = V_198 ;
V_1 -> V_3 |= V_183 ;
V_1 -> V_29 = V_48 ;
break;
case V_195 :
error = - V_46 ;
if ( V_67 . V_178 != 0 )
goto V_13;
V_39 = V_199 ;
V_1 -> V_3 |= V_183 ;
V_1 -> V_29 = V_48 ;
case V_199 :
V_1 -> V_3 |= V_108 ;
}
error = F_156 ( V_48 , V_39 , V_1 ) ;
F_66 ( & V_50 -> V_64 -> V_1 ) ;
V_190 = F_161 ( V_174 ) ;
F_67 ( & V_50 -> V_64 -> V_1 ) ;
if ( ! error && V_190 != V_48 && V_67 . V_66 != V_6 ) {
V_67 . V_66 = V_6 ;
goto V_192;
}
V_13:
F_20 ( V_1 ) ;
return error ;
}
void F_164 ( struct V_47 * V_48 , T_4 V_166 )
{
struct V_1 V_176 ;
struct V_9 * V_11 ;
V_11 = F_4 ( & F_36 ( V_48 ) -> V_12 ) ;
if ( ! V_11 || F_13 ( & V_11 -> V_18 ) )
return;
V_176 . V_8 = V_6 ;
V_176 . V_3 = V_65 | V_200 ;
V_176 . V_35 = 0 ;
V_176 . V_36 = V_53 ;
V_176 . V_29 = V_166 ;
V_176 . V_33 = V_50 -> V_51 ;
V_176 . V_34 = V_48 ;
V_176 . V_25 = NULL ;
V_176 . V_27 = NULL ;
F_155 ( V_48 , V_194 , & V_176 , NULL ) ;
if ( V_176 . V_25 && V_176 . V_25 -> V_26 )
V_176 . V_25 -> V_26 ( & V_176 ) ;
}
static void
F_165 ( struct V_47 * V_48 , struct V_9 * V_201 )
{
struct V_1 V_2 = {
. V_29 = V_48 ,
. V_33 = V_50 -> V_51 ,
. V_34 = V_48 ,
. V_3 = V_52 ,
. V_8 = V_6 ,
. V_36 = V_53 ,
} ;
struct V_10 * V_10 = F_36 ( V_48 ) ;
if ( F_13 ( & V_201 -> V_17 ) )
return;
if ( V_48 -> V_172 -> V_67 )
V_48 -> V_172 -> V_67 ( V_48 , V_196 , & V_2 ) ;
else
F_92 ( V_10 , & V_2 ) ;
if ( V_2 . V_25 && V_2 . V_25 -> V_26 )
V_2 . V_25 -> V_26 ( & V_2 ) ;
}
static void
F_166 ( struct V_47 * V_48 , struct V_9 * V_11 )
{
struct V_1 * V_2 , * V_111 ;
F_93 ( V_31 ) ;
if ( F_13 ( & V_11 -> V_19 ) )
return;
F_66 ( & V_11 -> V_16 ) ;
F_111 (fl, tmp, &ctx->flc_lease, fl_list)
if ( V_48 == V_2 -> V_34 )
F_104 ( V_2 , V_6 , & V_31 ) ;
F_67 ( & V_11 -> V_16 ) ;
F_24 ( & V_31 ) ;
}
void F_167 ( struct V_47 * V_48 )
{
struct V_9 * V_11 ;
V_11 = F_4 ( & F_36 ( V_48 ) -> V_12 ) ;
if ( ! V_11 )
return;
F_164 ( V_48 , V_48 ) ;
F_165 ( V_48 , V_11 ) ;
F_166 ( V_48 , V_11 ) ;
}
int
F_168 ( struct V_1 * V_86 )
{
int V_202 = 0 ;
F_66 ( & V_87 ) ;
if ( V_86 -> V_89 )
F_64 ( V_86 ) ;
else
V_202 = - V_104 ;
F_67 ( & V_87 ) ;
return V_202 ;
}
int F_169 ( struct V_47 * V_48 , struct V_1 * V_2 )
{
if ( V_48 -> V_172 -> V_176 )
return V_48 -> V_172 -> V_176 ( V_48 , V_203 , V_2 ) ;
return 0 ;
}
static void F_170 ( struct V_204 * V_190 , struct V_1 * V_2 ,
T_1 V_205 , char * V_206 )
{
struct V_10 * V_10 = NULL ;
unsigned int V_33 ;
if ( V_2 -> V_93 )
V_33 = F_88 ( V_2 -> V_93 ) ;
else
V_33 = V_2 -> V_33 ;
if ( V_2 -> V_34 != NULL )
V_10 = F_36 ( V_2 -> V_34 ) ;
F_171 ( V_190 , L_2 , V_205 , V_206 ) ;
if ( F_70 ( V_2 ) ) {
if ( V_2 -> V_3 & V_105 )
F_172 ( V_190 , L_3 ) ;
else if ( F_71 ( V_2 ) )
F_172 ( V_190 , L_4 ) ;
else
F_172 ( V_190 , L_5 ) ;
F_171 ( V_190 , L_6 ,
( V_10 == NULL ) ? L_7 :
F_159 ( V_10 ) ? L_8 : L_9 ) ;
} else if ( F_173 ( V_2 ) ) {
if ( V_2 -> V_8 & V_40 ) {
F_172 ( V_190 , L_10 ) ;
} else {
F_172 ( V_190 , L_11 ) ;
}
} else if ( F_174 ( V_2 ) ) {
if ( V_2 -> V_3 & V_137 )
F_172 ( V_190 , L_12 ) ;
else
F_172 ( V_190 , L_13 ) ;
if ( F_1 ( V_2 ) )
F_172 ( V_190 , L_14 ) ;
else if ( V_2 -> V_34 )
F_172 ( V_190 , L_15 ) ;
else
F_172 ( V_190 , L_16 ) ;
} else {
F_172 ( V_190 , L_17 ) ;
}
if ( V_2 -> V_8 & V_40 ) {
F_171 ( V_190 , L_18 ,
( V_2 -> V_8 & V_207 )
? ( V_2 -> V_8 & V_208 ) ? L_19 : L_20
: ( V_2 -> V_8 & V_208 ) ? L_21 : L_22 ) ;
} else {
F_171 ( V_190 , L_18 ,
( F_1 ( V_2 ) )
? ( V_2 -> V_8 == V_6 ) ? L_23 : L_20
: ( V_2 -> V_8 == V_44 ) ? L_21 : L_20 ) ;
}
if ( V_10 ) {
F_171 ( V_190 , L_24 , V_33 ,
F_175 ( V_10 -> V_150 -> V_209 ) ,
F_176 ( V_10 -> V_150 -> V_209 ) , V_10 -> V_210 ) ;
} else {
F_171 ( V_190 , L_25 , V_33 ) ;
}
if ( F_70 ( V_2 ) ) {
if ( V_2 -> V_36 == V_53 )
F_171 ( V_190 , L_26 , V_2 -> V_35 ) ;
else
F_171 ( V_190 , L_27 , V_2 -> V_35 , V_2 -> V_36 ) ;
} else {
F_172 ( V_190 , L_28 ) ;
}
}
static int F_177 ( struct V_204 * V_190 , void * V_211 )
{
struct V_212 * V_213 = V_190 -> V_214 ;
struct V_1 * V_2 , * V_215 ;
V_2 = F_178 ( V_211 , struct V_1 , V_20 ) ;
F_170 ( V_190 , V_2 , V_213 -> V_216 , L_29 ) ;
F_87 (bfl, &fl->fl_block, fl_block)
F_170 ( V_190 , V_215 , V_213 -> V_216 , L_30 ) ;
return 0 ;
}
static void F_179 ( struct V_204 * V_190 ,
struct V_30 * V_217 , int * V_205 ,
struct V_47 * V_48 , struct V_218 * V_64 )
{
struct V_1 * V_2 ;
F_87 (fl, head, fl_list) {
if ( V_48 != V_2 -> V_34 )
continue;
if ( V_2 -> V_29 != V_64 &&
V_2 -> V_29 != V_48 )
continue;
( * V_205 ) ++ ;
F_172 ( V_190 , L_31 ) ;
F_170 ( V_190 , V_2 , * V_205 , L_29 ) ;
}
}
void F_180 ( struct V_204 * V_190 ,
struct V_47 * V_48 , struct V_218 * V_64 )
{
struct V_10 * V_10 = F_36 ( V_48 ) ;
struct V_9 * V_11 ;
int V_205 = 0 ;
V_11 = F_4 ( & V_10 -> V_12 ) ;
if ( ! V_11 )
return;
F_66 ( & V_11 -> V_16 ) ;
F_179 ( V_190 , & V_11 -> V_17 , & V_205 , V_48 , V_64 ) ;
F_179 ( V_190 , & V_11 -> V_18 , & V_205 , V_48 , V_64 ) ;
F_179 ( V_190 , & V_11 -> V_19 , & V_205 , V_48 , V_64 ) ;
F_67 ( & V_11 -> V_16 ) ;
}
static void * F_181 ( struct V_204 * V_190 , T_1 * V_219 )
__acquires( &blocked_lock_lock
static void * F_182 ( struct V_204 * V_190 , void * V_211 , T_1 * V_219 )
{
struct V_212 * V_213 = V_190 -> V_214 ;
++ V_213 -> V_216 ;
return F_183 ( V_211 , & V_84 , & V_213 -> V_220 , V_219 ) ;
}
static void F_184 ( struct V_204 * V_190 , void * V_211 )
__releases( &blocked_lock_lock
static int F_185 ( struct V_10 * V_10 , struct V_47 * V_48 )
{
return F_186 ( V_48 , & V_221 ,
sizeof( struct V_212 ) ) ;
}
static int T_5 F_187 ( void )
{
F_188 ( L_32 , 0 , NULL , & V_222 ) ;
return 0 ;
}
static int T_5 F_189 ( void )
{
int V_98 ;
V_14 = F_190 ( L_33 ,
sizeof( struct V_9 ) , 0 , V_223 , NULL ) ;
V_24 = F_190 ( L_34 ,
sizeof( struct V_1 ) , 0 , V_223 , NULL ) ;
F_191 ( & V_82 , L_35 ) ;
F_192 (i)
F_193 ( F_194 ( & V_84 , V_98 ) ) ;
return 0 ;
}
