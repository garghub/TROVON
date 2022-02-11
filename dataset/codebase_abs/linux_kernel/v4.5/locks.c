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
F_11 ( V_10 , type , V_11 ) ;
return V_11 ;
}
static void
F_12 ( struct V_20 * V_21 , char * V_22 )
{
struct V_1 * V_2 ;
F_13 (fl, list, fl_list) {
F_14 ( L_1 , V_22 , V_2 -> V_23 , V_2 -> V_3 , V_2 -> V_8 , V_2 -> V_24 ) ;
}
}
static void
F_15 ( struct V_10 * V_10 )
{
struct V_9 * V_11 = V_10 -> V_12 ;
if ( F_16 ( ! F_17 ( & V_11 -> V_17 ) ||
! F_17 ( & V_11 -> V_18 ) ||
! F_17 ( & V_11 -> V_19 ) ) ) {
F_14 ( L_2 ,
F_18 ( V_10 -> V_25 -> V_26 ) , F_19 ( V_10 -> V_25 -> V_26 ) ,
V_10 -> V_27 ) ;
F_12 ( & V_11 -> V_17 , L_3 ) ;
F_12 ( & V_11 -> V_18 , L_4 ) ;
F_12 ( & V_11 -> V_19 , L_5 ) ;
}
}
void
F_20 ( struct V_10 * V_10 )
{
struct V_9 * V_11 = V_10 -> V_12 ;
if ( F_16 ( V_11 ) ) {
F_15 ( V_10 ) ;
F_10 ( V_14 , V_11 ) ;
}
}
static void F_21 ( struct V_1 * V_2 )
{
F_22 ( & V_2 -> V_28 ) ;
F_8 ( & V_2 -> V_29 ) ;
F_8 ( & V_2 -> V_30 ) ;
F_23 ( & V_2 -> V_31 ) ;
}
struct V_1 * F_24 ( void )
{
struct V_1 * V_2 = F_25 ( V_32 , V_15 ) ;
if ( V_2 )
F_21 ( V_2 ) ;
return V_2 ;
}
void F_26 ( struct V_1 * V_2 )
{
if ( V_2 -> V_33 ) {
if ( V_2 -> V_33 -> V_34 )
V_2 -> V_33 -> V_34 ( V_2 ) ;
V_2 -> V_33 = NULL ;
}
if ( V_2 -> V_35 ) {
if ( V_2 -> V_35 -> V_36 ) {
V_2 -> V_35 -> V_36 ( V_2 -> V_23 ) ;
V_2 -> V_23 = NULL ;
}
V_2 -> V_35 = NULL ;
}
}
void F_27 ( struct V_1 * V_2 )
{
F_28 ( F_29 ( & V_2 -> V_31 ) ) ;
F_28 ( ! F_17 ( & V_2 -> V_29 ) ) ;
F_28 ( ! F_17 ( & V_2 -> V_30 ) ) ;
F_28 ( ! F_30 ( & V_2 -> V_28 ) ) ;
F_26 ( V_2 ) ;
F_10 ( V_32 , V_2 ) ;
}
static void
F_31 ( struct V_20 * V_37 )
{
struct V_1 * V_2 ;
while ( ! F_17 ( V_37 ) ) {
V_2 = F_32 ( V_37 , struct V_1 , V_29 ) ;
F_33 ( & V_2 -> V_29 ) ;
F_27 ( V_2 ) ;
}
}
void F_34 ( struct V_1 * V_2 )
{
memset ( V_2 , 0 , sizeof( struct V_1 ) ) ;
F_21 ( V_2 ) ;
}
void F_35 ( struct V_1 * V_38 , struct V_1 * V_2 )
{
V_38 -> V_23 = V_2 -> V_23 ;
V_38 -> V_24 = V_2 -> V_24 ;
V_38 -> V_39 = NULL ;
V_38 -> V_3 = V_2 -> V_3 ;
V_38 -> V_8 = V_2 -> V_8 ;
V_38 -> V_40 = V_2 -> V_40 ;
V_38 -> V_41 = V_2 -> V_41 ;
V_38 -> V_35 = V_2 -> V_35 ;
V_38 -> V_33 = NULL ;
if ( V_2 -> V_35 ) {
if ( V_2 -> V_35 -> V_42 )
V_2 -> V_35 -> V_42 ( V_2 -> V_23 ) ;
}
}
void F_36 ( struct V_1 * V_38 , struct V_1 * V_2 )
{
F_37 ( V_38 -> V_33 ) ;
F_35 ( V_38 , V_2 ) ;
V_38 -> V_39 = V_2 -> V_39 ;
V_38 -> V_33 = V_2 -> V_33 ;
if ( V_2 -> V_33 ) {
if ( V_2 -> V_33 -> V_43 )
V_2 -> V_33 -> V_43 ( V_38 , V_2 ) ;
}
}
static inline int F_38 ( int V_44 ) {
if ( V_44 & V_45 )
return V_44 & ( V_45 | V_46 ) ;
switch ( V_44 ) {
case V_47 :
return V_7 ;
case V_48 :
return V_49 ;
case V_50 :
return V_6 ;
}
return - V_51 ;
}
static struct V_1 *
F_39 ( struct V_52 * V_53 , unsigned int V_44 )
{
struct V_1 * V_2 ;
int type = F_38 ( V_44 ) ;
if ( type < 0 )
return F_40 ( type ) ;
V_2 = F_24 () ;
if ( V_2 == NULL )
return F_40 ( - V_54 ) ;
V_2 -> V_39 = V_53 ;
V_2 -> V_23 = V_53 ;
V_2 -> V_24 = V_55 -> V_56 ;
V_2 -> V_3 = V_57 ;
V_2 -> V_8 = type ;
V_2 -> V_41 = V_58 ;
return V_2 ;
}
static int F_41 ( struct V_1 * V_2 , long type )
{
switch ( type ) {
case V_7 :
case V_49 :
case V_6 :
V_2 -> V_8 = type ;
break;
default:
return - V_51 ;
}
return 0 ;
}
static int F_42 ( struct V_52 * V_53 , struct V_1 * V_2 ,
struct V_59 * V_60 )
{
switch ( V_60 -> V_61 ) {
case V_62 :
V_2 -> V_40 = 0 ;
break;
case V_63 :
V_2 -> V_40 = V_53 -> V_64 ;
break;
case V_65 :
V_2 -> V_40 = F_43 ( F_44 ( V_53 ) ) ;
break;
default:
return - V_51 ;
}
if ( V_60 -> V_66 > V_58 - V_2 -> V_40 )
return - V_67 ;
V_2 -> V_40 += V_60 -> V_66 ;
if ( V_2 -> V_40 < 0 )
return - V_51 ;
if ( V_60 -> V_68 > 0 ) {
if ( V_60 -> V_68 - 1 > V_58 - V_2 -> V_40 )
return - V_67 ;
V_2 -> V_41 = V_2 -> V_40 + V_60 -> V_68 - 1 ;
} else if ( V_60 -> V_68 < 0 ) {
if ( V_2 -> V_40 + V_60 -> V_68 < 0 )
return - V_51 ;
V_2 -> V_41 = V_2 -> V_40 - 1 ;
V_2 -> V_40 += V_60 -> V_68 ;
} else
V_2 -> V_41 = V_58 ;
V_2 -> V_23 = V_55 -> V_69 ;
V_2 -> V_24 = V_55 -> V_56 ;
V_2 -> V_39 = V_53 ;
V_2 -> V_3 = V_70 ;
V_2 -> V_33 = NULL ;
V_2 -> V_35 = NULL ;
return F_41 ( V_2 , V_60 -> V_71 ) ;
}
static int F_45 ( struct V_52 * V_53 , struct V_1 * V_2 ,
struct V_72 * V_60 )
{
struct V_59 V_73 = {
. V_71 = V_60 -> V_71 ,
. V_61 = V_60 -> V_61 ,
. V_66 = V_60 -> V_66 ,
. V_68 = V_60 -> V_68 ,
} ;
return F_42 ( V_53 , V_2 , & V_73 ) ;
}
static bool
F_46 ( struct V_1 * V_2 )
{
F_47 ( & V_2 -> V_74 , V_75 , V_76 ) ;
return false ;
}
static void
F_48 ( struct V_1 * V_2 , void * * V_77 )
{
struct V_52 * V_53 = V_2 -> V_39 ;
struct V_78 * V_79 = * V_77 ;
if ( ! F_49 ( V_79 -> V_80 , V_53 , & V_2 -> V_74 , V_79 ) )
* V_77 = NULL ;
F_50 ( V_53 , F_51 ( V_55 ) , V_81 , 0 ) ;
}
static int F_52 ( struct V_52 * V_53 , long type , struct V_1 * V_2 )
{
if ( F_41 ( V_2 , type ) != 0 )
return - V_51 ;
V_2 -> V_23 = V_53 ;
V_2 -> V_24 = V_55 -> V_56 ;
V_2 -> V_39 = V_53 ;
V_2 -> V_3 = V_82 ;
V_2 -> V_40 = 0 ;
V_2 -> V_41 = V_58 ;
V_2 -> V_33 = NULL ;
V_2 -> V_35 = & V_83 ;
return 0 ;
}
static struct V_1 * F_53 ( struct V_52 * V_53 , long type )
{
struct V_1 * V_2 = F_24 () ;
int error = - V_54 ;
if ( V_2 == NULL )
return F_40 ( error ) ;
error = F_52 ( V_53 , type , V_2 ) ;
if ( error ) {
F_27 ( V_2 ) ;
return F_40 ( error ) ;
}
return V_2 ;
}
static inline int F_54 ( struct V_1 * V_84 , struct V_1 * V_85 )
{
return ( ( V_84 -> V_41 >= V_85 -> V_40 ) &&
( V_85 -> V_41 >= V_84 -> V_40 ) ) ;
}
static int F_55 ( struct V_1 * V_84 , struct V_1 * V_85 )
{
if ( V_84 -> V_35 && V_84 -> V_35 -> V_86 )
return V_85 -> V_35 == V_84 -> V_35 &&
V_84 -> V_35 -> V_86 ( V_84 , V_85 ) ;
return V_84 -> V_23 == V_85 -> V_23 ;
}
static void F_56 ( struct V_1 * V_2 )
{
F_57 ( & V_87 ) ;
V_2 -> V_88 = F_58 () ;
F_59 ( & V_2 -> V_28 , F_60 ( & V_89 ) ) ;
F_61 ( & V_87 ) ;
}
static void F_62 ( struct V_1 * V_2 )
{
if ( F_30 ( & V_2 -> V_28 ) )
return;
F_63 ( & V_87 , V_2 -> V_88 ) ;
F_64 ( & V_2 -> V_28 ) ;
F_65 ( & V_87 , V_2 -> V_88 ) ;
}
static unsigned long
F_66 ( struct V_1 * V_2 )
{
if ( V_2 -> V_35 && V_2 -> V_35 -> V_90 )
return V_2 -> V_35 -> V_90 ( V_2 ) ;
return ( unsigned long ) V_2 -> V_23 ;
}
static void F_67 ( struct V_1 * V_91 )
{
F_68 ( & V_92 ) ;
F_69 ( V_93 , & V_91 -> V_28 , F_66 ( V_91 ) ) ;
}
static void F_70 ( struct V_1 * V_91 )
{
F_68 ( & V_92 ) ;
F_71 ( & V_91 -> V_28 ) ;
}
static void F_72 ( struct V_1 * V_91 )
{
F_70 ( V_91 ) ;
F_33 ( & V_91 -> V_30 ) ;
V_91 -> V_94 = NULL ;
}
static void F_73 ( struct V_1 * V_91 )
{
F_74 ( & V_92 ) ;
F_72 ( V_91 ) ;
F_75 ( & V_92 ) ;
}
static void F_76 ( struct V_1 * V_95 ,
struct V_1 * V_91 )
{
F_28 ( ! F_17 ( & V_91 -> V_30 ) ) ;
V_91 -> V_94 = V_95 ;
F_77 ( & V_91 -> V_30 , & V_95 -> V_30 ) ;
if ( F_78 ( V_95 ) && ! F_79 ( V_95 ) )
F_67 ( V_91 ) ;
}
static void F_80 ( struct V_1 * V_95 ,
struct V_1 * V_91 )
{
F_74 ( & V_92 ) ;
F_76 ( V_95 , V_91 ) ;
F_75 ( & V_92 ) ;
}
static void F_81 ( struct V_1 * V_95 )
{
if ( F_17 ( & V_95 -> V_30 ) )
return;
F_74 ( & V_92 ) ;
while ( ! F_17 ( & V_95 -> V_30 ) ) {
struct V_1 * V_91 ;
V_91 = F_32 ( & V_95 -> V_30 ,
struct V_1 , V_30 ) ;
F_72 ( V_91 ) ;
if ( V_91 -> V_35 && V_91 -> V_35 -> V_96 )
V_91 -> V_35 -> V_96 ( V_91 ) ;
else
F_82 ( & V_91 -> V_31 ) ;
}
F_75 ( & V_92 ) ;
}
static void
F_83 ( struct V_1 * V_2 , struct V_20 * V_97 )
{
V_2 -> V_98 = F_84 ( F_85 ( V_55 ) ) ;
F_77 ( & V_2 -> V_29 , V_97 ) ;
F_56 ( V_2 ) ;
}
static void
F_86 ( struct V_1 * V_2 )
{
F_62 ( V_2 ) ;
F_33 ( & V_2 -> V_29 ) ;
if ( V_2 -> V_98 ) {
F_87 ( V_2 -> V_98 ) ;
V_2 -> V_98 = NULL ;
}
F_81 ( V_2 ) ;
}
static void
F_88 ( struct V_1 * V_2 , struct V_20 * V_37 )
{
F_86 ( V_2 ) ;
if ( V_37 )
F_89 ( & V_2 -> V_29 , V_37 ) ;
else
F_27 ( V_2 ) ;
}
static int F_90 ( struct V_1 * V_99 , struct V_1 * V_100 )
{
if ( V_100 -> V_8 == V_49 )
return 1 ;
if ( V_99 -> V_8 == V_49 )
return 1 ;
return 0 ;
}
static int F_91 ( struct V_1 * V_99 , struct V_1 * V_100 )
{
if ( F_55 ( V_99 , V_100 ) )
return ( 0 ) ;
if ( ! F_54 ( V_99 , V_100 ) )
return 0 ;
return ( F_90 ( V_99 , V_100 ) ) ;
}
static int F_92 ( struct V_1 * V_99 , struct V_1 * V_100 )
{
if ( V_99 -> V_39 == V_100 -> V_39 )
return ( 0 ) ;
if ( ( V_99 -> V_8 & V_45 ) || ( V_100 -> V_8 & V_45 ) )
return 0 ;
return ( F_90 ( V_99 , V_100 ) ) ;
}
void
F_93 ( struct V_52 * V_53 , struct V_1 * V_2 )
{
struct V_1 * V_101 ;
struct V_9 * V_11 ;
struct V_10 * V_10 = F_44 ( V_53 ) ;
V_11 = F_4 ( & V_10 -> V_12 ) ;
if ( ! V_11 || F_94 ( & V_11 -> V_18 ) ) {
V_2 -> V_8 = V_6 ;
return;
}
F_74 ( & V_11 -> V_16 ) ;
F_13 (cfl, &ctx->flc_posix, fl_list) {
if ( F_91 ( V_2 , V_101 ) ) {
F_35 ( V_2 , V_101 ) ;
if ( V_101 -> V_98 )
V_2 -> V_24 = F_95 ( V_101 -> V_98 ) ;
goto V_13;
}
}
V_2 -> V_8 = V_6 ;
V_13:
F_75 ( & V_11 -> V_16 ) ;
return;
}
static struct V_1 * F_96 ( struct V_1 * V_102 )
{
struct V_1 * V_2 ;
F_97 (blocked_hash, fl, fl_link, posix_owner_key(block_fl)) {
if ( F_55 ( V_2 , V_102 ) )
return V_2 -> V_94 ;
}
return NULL ;
}
static int F_98 ( struct V_1 * V_99 ,
struct V_1 * V_102 )
{
int V_103 = 0 ;
F_68 ( & V_92 ) ;
if ( F_79 ( V_99 ) )
return 0 ;
while ( ( V_102 = F_96 ( V_102 ) ) ) {
if ( V_103 ++ > V_104 )
return 0 ;
if ( F_55 ( V_99 , V_102 ) )
return 1 ;
}
return 0 ;
}
static int F_99 ( struct V_10 * V_10 , struct V_1 * V_105 )
{
struct V_1 * V_106 = NULL ;
struct V_1 * V_2 ;
struct V_9 * V_11 ;
int error = 0 ;
bool V_107 = false ;
F_100 ( V_37 ) ;
V_11 = F_3 ( V_10 , V_105 -> V_8 ) ;
if ( ! V_11 ) {
if ( V_105 -> V_8 != V_6 )
return - V_54 ;
return ( V_105 -> V_3 & V_108 ) ? - V_109 : 0 ;
}
if ( ! ( V_105 -> V_3 & V_110 ) && ( V_105 -> V_8 != V_6 ) ) {
V_106 = F_24 () ;
if ( ! V_106 )
return - V_54 ;
}
F_74 ( & V_11 -> V_16 ) ;
if ( V_105 -> V_3 & V_110 )
goto V_111;
F_13 (fl, &ctx->flc_flock, fl_list) {
if ( V_105 -> V_39 != V_2 -> V_39 )
continue;
if ( V_105 -> V_8 == V_2 -> V_8 )
goto V_13;
V_107 = true ;
F_88 ( V_2 , & V_37 ) ;
break;
}
if ( V_105 -> V_8 == V_6 ) {
if ( ( V_105 -> V_3 & V_108 ) && ! V_107 )
error = - V_109 ;
goto V_13;
}
V_111:
F_13 (fl, &ctx->flc_flock, fl_list) {
if ( ! F_92 ( V_105 , V_2 ) )
continue;
error = - V_112 ;
if ( ! ( V_105 -> V_3 & V_113 ) )
goto V_13;
error = V_114 ;
F_80 ( V_2 , V_105 ) ;
goto V_13;
}
if ( V_105 -> V_3 & V_110 )
goto V_13;
F_36 ( V_106 , V_105 ) ;
F_83 ( V_106 , & V_11 -> V_17 ) ;
V_106 = NULL ;
error = 0 ;
V_13:
F_75 ( & V_11 -> V_16 ) ;
if ( V_106 )
F_27 ( V_106 ) ;
F_31 ( & V_37 ) ;
return error ;
}
static int F_101 ( struct V_10 * V_10 , struct V_1 * V_105 ,
struct V_1 * V_115 )
{
struct V_1 * V_2 , * V_116 ;
struct V_1 * V_106 = NULL ;
struct V_1 * V_117 = NULL ;
struct V_1 * V_118 = NULL ;
struct V_1 * V_119 = NULL ;
struct V_9 * V_11 ;
int error ;
bool V_120 = false ;
F_100 ( V_37 ) ;
V_11 = F_3 ( V_10 , V_105 -> V_8 ) ;
if ( ! V_11 )
return ( V_105 -> V_8 == V_6 ) ? 0 : - V_54 ;
if ( ! ( V_105 -> V_3 & V_110 ) &&
( V_105 -> V_8 != V_6 ||
V_105 -> V_40 != 0 || V_105 -> V_41 != V_58 ) ) {
V_106 = F_24 () ;
V_117 = F_24 () ;
}
F_74 ( & V_11 -> V_16 ) ;
if ( V_105 -> V_8 != V_6 ) {
F_13 (fl, &ctx->flc_posix, fl_list) {
if ( ! F_91 ( V_105 , V_2 ) )
continue;
if ( V_115 )
F_35 ( V_115 , V_2 ) ;
error = - V_112 ;
if ( ! ( V_105 -> V_3 & V_113 ) )
goto V_13;
error = - V_121 ;
F_74 ( & V_92 ) ;
if ( F_5 ( ! F_98 ( V_105 , V_2 ) ) ) {
error = V_114 ;
F_76 ( V_2 , V_105 ) ;
}
F_75 ( & V_92 ) ;
goto V_13;
}
}
error = 0 ;
if ( V_105 -> V_3 & V_110 )
goto V_13;
F_13 (fl, &ctx->flc_posix, fl_list) {
if ( F_55 ( V_105 , V_2 ) )
break;
}
F_102 (fl, tmp, &ctx->flc_posix, fl_list) {
if ( ! F_55 ( V_105 , V_2 ) )
break;
if ( V_105 -> V_8 == V_2 -> V_8 ) {
if ( V_2 -> V_41 < V_105 -> V_40 - 1 )
continue;
if ( V_2 -> V_40 - 1 > V_105 -> V_41 )
break;
if ( V_2 -> V_40 > V_105 -> V_40 )
V_2 -> V_40 = V_105 -> V_40 ;
else
V_105 -> V_40 = V_2 -> V_40 ;
if ( V_2 -> V_41 < V_105 -> V_41 )
V_2 -> V_41 = V_105 -> V_41 ;
else
V_105 -> V_41 = V_2 -> V_41 ;
if ( V_120 ) {
F_88 ( V_2 , & V_37 ) ;
continue;
}
V_105 = V_2 ;
V_120 = true ;
} else {
if ( V_2 -> V_41 < V_105 -> V_40 )
continue;
if ( V_2 -> V_40 > V_105 -> V_41 )
break;
if ( V_105 -> V_8 == V_6 )
V_120 = true ;
if ( V_2 -> V_40 < V_105 -> V_40 )
V_118 = V_2 ;
if ( V_2 -> V_41 > V_105 -> V_41 ) {
V_119 = V_2 ;
break;
}
if ( V_2 -> V_40 >= V_105 -> V_40 ) {
if ( V_120 ) {
F_88 ( V_2 , & V_37 ) ;
continue;
}
error = - V_122 ;
if ( ! V_106 )
goto V_13;
F_36 ( V_106 , V_105 ) ;
V_105 = V_106 ;
V_106 = NULL ;
F_83 ( V_105 , & V_2 -> V_29 ) ;
F_88 ( V_2 , & V_37 ) ;
V_120 = true ;
}
}
}
error = - V_122 ;
if ( V_119 && V_118 == V_119 && ! V_117 )
goto V_13;
error = 0 ;
if ( ! V_120 ) {
if ( V_105 -> V_8 == V_6 ) {
if ( V_105 -> V_3 & V_108 )
error = - V_109 ;
goto V_13;
}
if ( ! V_106 ) {
error = - V_122 ;
goto V_13;
}
F_36 ( V_106 , V_105 ) ;
F_83 ( V_106 , & V_2 -> V_29 ) ;
V_2 = V_106 ;
V_106 = NULL ;
}
if ( V_119 ) {
if ( V_118 == V_119 ) {
V_118 = V_117 ;
V_117 = NULL ;
F_36 ( V_118 , V_119 ) ;
F_83 ( V_118 , & V_2 -> V_29 ) ;
}
V_119 -> V_40 = V_105 -> V_41 + 1 ;
F_81 ( V_119 ) ;
}
if ( V_118 ) {
V_118 -> V_41 = V_105 -> V_40 - 1 ;
F_81 ( V_118 ) ;
}
V_13:
F_75 ( & V_11 -> V_16 ) ;
if ( V_106 )
F_27 ( V_106 ) ;
if ( V_117 )
F_27 ( V_117 ) ;
F_31 ( & V_37 ) ;
F_103 ( V_10 , V_105 , error ) ;
return error ;
}
int F_104 ( struct V_52 * V_53 , struct V_1 * V_2 ,
struct V_1 * V_115 )
{
return F_101 ( F_44 ( V_53 ) , V_2 , V_115 ) ;
}
static int F_105 ( struct V_10 * V_10 , struct V_1 * V_2 )
{
int error ;
F_106 () ;
for (; ; ) {
error = F_101 ( V_10 , V_2 , NULL ) ;
if ( error != V_114 )
break;
error = F_107 ( V_2 -> V_31 , ! V_2 -> V_94 ) ;
if ( ! error )
continue;
F_73 ( V_2 ) ;
break;
}
return error ;
}
int F_108 ( struct V_52 * V_52 )
{
int V_123 ;
struct V_10 * V_10 = F_44 ( V_52 ) ;
struct V_9 * V_11 ;
struct V_1 * V_2 ;
V_11 = F_4 ( & V_10 -> V_12 ) ;
if ( ! V_11 || F_94 ( & V_11 -> V_18 ) )
return 0 ;
F_74 ( & V_11 -> V_16 ) ;
V_123 = 0 ;
F_13 (fl, &ctx->flc_posix, fl_list) {
if ( V_2 -> V_23 != V_55 -> V_69 &&
V_2 -> V_23 != V_52 ) {
V_123 = - V_112 ;
break;
}
}
F_75 ( & V_11 -> V_16 ) ;
return V_123 ;
}
int F_109 ( struct V_10 * V_10 , struct V_52 * V_53 , T_1 V_124 ,
T_1 V_125 , unsigned char type )
{
struct V_1 V_2 ;
int error ;
bool V_126 = false ;
F_34 ( & V_2 ) ;
V_2 . V_24 = V_55 -> V_56 ;
V_2 . V_39 = V_53 ;
V_2 . V_3 = V_70 | V_110 ;
if ( V_53 && ! ( V_53 -> V_127 & V_128 ) )
V_126 = true ;
V_2 . V_8 = type ;
V_2 . V_40 = V_124 ;
V_2 . V_41 = V_125 ;
for (; ; ) {
if ( V_53 ) {
V_2 . V_23 = V_53 ;
V_2 . V_3 &= ~ V_113 ;
error = F_101 ( V_10 , & V_2 , NULL ) ;
if ( ! error )
break;
}
if ( V_126 )
V_2 . V_3 |= V_113 ;
V_2 . V_23 = V_55 -> V_69 ;
error = F_101 ( V_10 , & V_2 , NULL ) ;
if ( error != V_114 )
break;
error = F_107 ( V_2 . V_31 , ! V_2 . V_94 ) ;
if ( ! error ) {
if ( F_110 ( V_10 ) )
continue;
}
F_73 ( & V_2 ) ;
break;
}
return error ;
}
static void F_111 ( struct V_1 * V_2 , int V_129 )
{
switch ( V_129 ) {
case V_6 :
V_2 -> V_3 &= ~ V_4 ;
case V_7 :
V_2 -> V_3 &= ~ V_5 ;
}
}
int F_112 ( struct V_1 * V_2 , int V_129 , struct V_20 * V_37 )
{
int error = F_41 ( V_2 , V_129 ) ;
if ( error )
return error ;
F_111 ( V_2 , V_129 ) ;
F_81 ( V_2 ) ;
if ( V_129 == V_6 ) {
struct V_52 * V_53 = V_2 -> V_39 ;
F_113 ( V_53 ) ;
V_53 -> V_130 . V_131 = 0 ;
F_114 ( 0 , V_2 -> V_39 , 0 , & V_2 -> V_74 ) ;
if ( V_2 -> V_74 != NULL ) {
F_115 ( V_132 L_6 , V_2 -> V_74 ) ;
V_2 -> V_74 = NULL ;
}
F_88 ( V_2 , V_37 ) ;
}
return 0 ;
}
static bool F_116 ( unsigned long V_133 )
{
if ( ! V_133 )
return false ;
return F_117 ( V_134 , V_133 ) ;
}
static void F_118 ( struct V_10 * V_10 , struct V_20 * V_37 )
{
struct V_9 * V_11 = V_10 -> V_12 ;
struct V_1 * V_2 , * V_116 ;
F_68 ( & V_11 -> V_16 ) ;
F_119 (fl, tmp, &ctx->flc_lease, fl_list) {
F_120 ( V_10 , V_2 ) ;
if ( F_116 ( V_2 -> V_135 ) )
F_112 ( V_2 , V_7 , V_37 ) ;
if ( F_116 ( V_2 -> V_136 ) )
F_112 ( V_2 , V_6 , V_37 ) ;
}
}
static bool F_121 ( struct V_1 * V_137 , struct V_1 * V_138 )
{
if ( ( V_138 -> V_3 & V_139 ) != ( V_137 -> V_3 & V_139 ) )
return false ;
if ( ( V_138 -> V_3 & V_140 ) && ( V_137 -> V_3 & V_82 ) )
return false ;
return F_90 ( V_138 , V_137 ) ;
}
static bool
F_122 ( struct V_10 * V_10 , struct V_1 * V_138 )
{
struct V_9 * V_11 = V_10 -> V_12 ;
struct V_1 * V_2 ;
F_68 ( & V_11 -> V_16 ) ;
F_13 (fl, &ctx->flc_lease, fl_list) {
if ( F_121 ( V_2 , V_138 ) )
return true ;
}
return false ;
}
int F_123 ( struct V_10 * V_10 , unsigned int V_141 , unsigned int type )
{
int error = 0 ;
struct V_9 * V_11 ;
struct V_1 * V_106 , * V_2 , * V_116 ;
unsigned long V_142 ;
int V_143 = ( V_141 & V_144 ) != V_145 ;
F_100 ( V_37 ) ;
V_106 = F_53 ( NULL , V_143 ? V_49 : V_7 ) ;
if ( F_124 ( V_106 ) )
return F_125 ( V_106 ) ;
V_106 -> V_3 = type ;
V_11 = F_4 ( & V_10 -> V_12 ) ;
if ( ! V_11 ) {
F_37 ( 1 ) ;
return error ;
}
F_74 ( & V_11 -> V_16 ) ;
F_118 ( V_10 , & V_37 ) ;
if ( ! F_122 ( V_10 , V_106 ) )
goto V_13;
V_142 = 0 ;
if ( V_146 > 0 ) {
V_142 = V_134 + V_146 * V_147 ;
if ( V_142 == 0 )
V_142 ++ ;
}
F_119 (fl, tmp, &ctx->flc_lease, fl_list) {
if ( ! F_121 ( V_2 , V_106 ) )
continue;
if ( V_143 ) {
if ( V_2 -> V_3 & V_4 )
continue;
V_2 -> V_3 |= V_4 ;
V_2 -> V_136 = V_142 ;
} else {
if ( F_1 ( V_2 ) )
continue;
V_2 -> V_3 |= V_5 ;
V_2 -> V_135 = V_142 ;
}
if ( V_2 -> V_35 -> V_148 ( V_2 ) )
F_88 ( V_2 , & V_37 ) ;
}
if ( F_17 ( & V_11 -> V_19 ) )
goto V_13;
if ( V_141 & V_128 ) {
F_126 ( V_10 , V_106 ) ;
error = - V_149 ;
goto V_13;
}
V_150:
V_2 = F_32 ( & V_11 -> V_19 , struct V_1 , V_29 ) ;
V_142 = V_2 -> V_136 ;
if ( V_142 != 0 )
V_142 -= V_134 ;
if ( V_142 == 0 )
V_142 ++ ;
F_80 ( V_2 , V_106 ) ;
F_127 ( V_10 , V_106 ) ;
F_75 ( & V_11 -> V_16 ) ;
F_31 ( & V_37 ) ;
error = F_128 ( V_106 -> V_31 ,
! V_106 -> V_94 , V_142 ) ;
F_74 ( & V_11 -> V_16 ) ;
F_129 ( V_10 , V_106 ) ;
F_73 ( V_106 ) ;
if ( error >= 0 ) {
if ( error == 0 )
F_118 ( V_10 , & V_37 ) ;
if ( F_122 ( V_10 , V_106 ) )
goto V_150;
error = 0 ;
}
V_13:
F_75 ( & V_11 -> V_16 ) ;
F_31 ( & V_37 ) ;
F_27 ( V_106 ) ;
return error ;
}
void F_130 ( struct V_10 * V_10 , struct V_151 * time )
{
bool V_152 = false ;
struct V_9 * V_11 ;
struct V_1 * V_2 ;
V_11 = F_4 ( & V_10 -> V_12 ) ;
if ( V_11 && ! F_94 ( & V_11 -> V_19 ) ) {
F_74 ( & V_11 -> V_16 ) ;
V_2 = F_131 ( & V_11 -> V_19 ,
struct V_1 , V_29 ) ;
if ( V_2 && ( V_2 -> V_8 == V_49 ) )
V_152 = true ;
F_75 ( & V_11 -> V_16 ) ;
}
if ( V_152 )
* time = F_132 ( V_10 -> V_25 ) ;
else
* time = V_10 -> V_153 ;
}
int F_133 ( struct V_52 * V_53 )
{
struct V_1 * V_2 ;
struct V_10 * V_10 = F_44 ( V_53 ) ;
struct V_9 * V_11 ;
int type = V_6 ;
F_100 ( V_37 ) ;
V_11 = F_4 ( & V_10 -> V_12 ) ;
if ( V_11 && ! F_94 ( & V_11 -> V_19 ) ) {
F_74 ( & V_11 -> V_16 ) ;
F_118 ( F_44 ( V_53 ) , & V_37 ) ;
F_13 (fl, &ctx->flc_lease, fl_list) {
if ( V_2 -> V_39 != V_53 )
continue;
type = F_2 ( V_2 ) ;
break;
}
F_75 ( & V_11 -> V_16 ) ;
F_31 ( & V_37 ) ;
}
return type ;
}
static int
F_134 ( const struct V_154 * V_154 , const long V_129 , int V_155 )
{
int V_123 = 0 ;
struct V_10 * V_10 = V_154 -> V_156 ;
if ( V_155 & V_139 )
return 0 ;
if ( ( V_129 == V_7 ) && ( F_135 ( & V_10 -> V_157 ) > 0 ) )
return - V_112 ;
if ( ( V_129 == V_49 ) && ( ( F_136 ( V_154 ) > 1 ) ||
( F_135 ( & V_10 -> V_158 ) > 1 ) ) )
V_123 = - V_112 ;
return V_123 ;
}
static int
F_137 ( struct V_52 * V_53 , long V_129 , struct V_1 * * V_159 , void * * V_77 )
{
struct V_1 * V_2 , * V_160 = NULL , * V_137 ;
struct V_154 * V_154 = V_53 -> V_161 . V_154 ;
struct V_10 * V_10 = V_154 -> V_156 ;
struct V_9 * V_11 ;
bool V_162 = ( * V_159 ) -> V_3 & V_140 ;
int error ;
F_100 ( V_37 ) ;
V_137 = * V_159 ;
F_138 ( V_10 , V_137 ) ;
V_11 = F_3 ( V_10 , V_129 ) ;
if ( ! V_11 )
return - V_54 ;
if ( V_162 && ! F_139 ( V_10 ) )
return - V_112 ;
if ( V_162 && V_129 == V_49 ) {
F_140 ( V_10 ) ;
F_37 ( 1 ) ;
return - V_51 ;
}
F_74 ( & V_11 -> V_16 ) ;
F_118 ( V_10 , & V_37 ) ;
error = F_134 ( V_154 , V_129 , V_137 -> V_3 ) ;
if ( error )
goto V_13;
error = - V_112 ;
F_13 (fl, &ctx->flc_lease, fl_list) {
if ( V_2 -> V_39 == V_53 &&
V_2 -> V_23 == V_137 -> V_23 ) {
V_160 = V_2 ;
continue;
}
if ( V_129 == V_49 )
goto V_13;
if ( V_2 -> V_3 & V_4 )
goto V_13;
}
if ( V_160 != NULL ) {
V_137 = V_160 ;
error = V_137 -> V_35 -> V_163 ( V_137 , V_129 , & V_37 ) ;
if ( error )
goto V_13;
goto V_164;
}
error = - V_51 ;
if ( ! V_165 )
goto V_13;
F_83 ( V_137 , & V_11 -> V_19 ) ;
F_141 () ;
error = F_134 ( V_154 , V_129 , V_137 -> V_3 ) ;
if ( error ) {
F_86 ( V_137 ) ;
goto V_13;
}
V_164:
if ( V_137 -> V_35 -> V_166 )
V_137 -> V_35 -> V_166 ( V_137 , V_77 ) ;
V_13:
F_75 ( & V_11 -> V_16 ) ;
F_31 ( & V_37 ) ;
if ( V_162 )
F_140 ( V_10 ) ;
if ( ! error && ! V_160 )
* V_159 = NULL ;
return error ;
}
static int F_142 ( struct V_52 * V_53 , void * V_167 )
{
int error = - V_112 ;
struct V_1 * V_2 , * V_168 = NULL ;
struct V_10 * V_10 = F_44 ( V_53 ) ;
struct V_9 * V_11 ;
F_100 ( V_37 ) ;
V_11 = F_4 ( & V_10 -> V_12 ) ;
if ( ! V_11 ) {
F_143 ( V_10 , NULL ) ;
return error ;
}
F_74 ( & V_11 -> V_16 ) ;
F_13 (fl, &ctx->flc_lease, fl_list) {
if ( V_2 -> V_39 == V_53 &&
V_2 -> V_23 == V_167 ) {
V_168 = V_2 ;
break;
}
}
F_143 ( V_10 , V_168 ) ;
if ( V_168 )
error = V_2 -> V_35 -> V_163 ( V_168 , V_6 , & V_37 ) ;
F_75 ( & V_11 -> V_16 ) ;
F_31 ( & V_37 ) ;
return error ;
}
int F_144 ( struct V_52 * V_53 , long V_129 , struct V_1 * * V_159 ,
void * * V_77 )
{
struct V_10 * V_10 = F_44 ( V_53 ) ;
int error ;
if ( ( ! F_145 ( F_146 () , V_10 -> V_169 ) ) && ! F_147 ( V_170 ) )
return - V_171 ;
if ( ! F_148 ( V_10 -> V_172 ) )
return - V_51 ;
error = F_149 ( V_53 , V_129 ) ;
if ( error )
return error ;
switch ( V_129 ) {
case V_6 :
return F_142 ( V_53 , * V_77 ) ;
case V_7 :
case V_49 :
if ( ! ( * V_159 ) -> V_35 -> V_148 ) {
F_37 ( 1 ) ;
return - V_122 ;
}
return F_137 ( V_53 , V_129 , V_159 , V_77 ) ;
default:
return - V_51 ;
}
}
int
F_150 ( struct V_52 * V_53 , long V_129 , struct V_1 * * V_137 , void * * V_77 )
{
if ( V_53 -> V_173 -> V_174 )
return V_53 -> V_173 -> V_174 ( V_53 , V_129 , V_137 , V_77 ) ;
else
return F_144 ( V_53 , V_129 , V_137 , V_77 ) ;
}
static int F_151 ( unsigned int V_175 , struct V_52 * V_53 , long V_129 )
{
struct V_1 * V_2 ;
struct V_78 * V_38 ;
int error ;
V_2 = F_53 ( V_53 , V_129 ) ;
if ( F_124 ( V_2 ) )
return F_125 ( V_2 ) ;
V_38 = F_152 () ;
if ( ! V_38 ) {
F_27 ( V_2 ) ;
return - V_54 ;
}
V_38 -> V_80 = V_175 ;
error = F_150 ( V_53 , V_129 , & V_2 , ( void * * ) & V_38 ) ;
if ( V_2 )
F_27 ( V_2 ) ;
if ( V_38 )
F_153 ( V_38 ) ;
return error ;
}
int F_154 ( unsigned int V_175 , struct V_52 * V_53 , long V_129 )
{
if ( V_129 == V_6 )
return F_150 ( V_53 , V_6 , NULL , ( void * * ) & V_53 ) ;
return F_151 ( V_175 , V_53 , V_129 ) ;
}
static int F_155 ( struct V_10 * V_10 , struct V_1 * V_2 )
{
int error ;
F_106 () ;
for (; ; ) {
error = F_99 ( V_10 , V_2 ) ;
if ( error != V_114 )
break;
error = F_107 ( V_2 -> V_31 , ! V_2 -> V_94 ) ;
if ( ! error )
continue;
F_73 ( V_2 ) ;
break;
}
return error ;
}
int F_156 ( struct V_10 * V_10 , struct V_1 * V_2 )
{
int V_176 = 0 ;
switch ( V_2 -> V_3 & ( V_70 | V_57 ) ) {
case V_70 :
V_176 = F_105 ( V_10 , V_2 ) ;
break;
case V_57 :
V_176 = F_155 ( V_10 , V_2 ) ;
break;
default:
F_157 () ;
}
return V_176 ;
}
int F_158 ( struct V_52 * V_53 , struct V_1 * V_2 )
{
if ( V_53 -> V_173 -> V_177 )
return V_53 -> V_173 -> V_177 ( V_53 , V_178 , V_2 ) ;
F_93 ( V_53 , V_2 ) ;
return 0 ;
}
static int F_159 ( struct V_72 * V_72 , struct V_1 * V_2 )
{
V_72 -> V_179 = F_79 ( V_2 ) ? - 1 : V_2 -> V_24 ;
#if V_180 == 32
if ( V_2 -> V_40 > V_181 )
return - V_67 ;
if ( V_2 -> V_41 != V_58 && V_2 -> V_41 > V_181 )
return - V_67 ;
#endif
V_72 -> V_66 = V_2 -> V_40 ;
V_72 -> V_68 = V_2 -> V_41 == V_58 ? 0 :
V_2 -> V_41 - V_2 -> V_40 + 1 ;
V_72 -> V_61 = 0 ;
V_72 -> V_71 = V_2 -> V_8 ;
return 0 ;
}
static void F_160 ( struct V_59 * V_72 , struct V_1 * V_2 )
{
V_72 -> V_179 = F_79 ( V_2 ) ? - 1 : V_2 -> V_24 ;
V_72 -> V_66 = V_2 -> V_40 ;
V_72 -> V_68 = V_2 -> V_41 == V_58 ? 0 :
V_2 -> V_41 - V_2 -> V_40 + 1 ;
V_72 -> V_61 = 0 ;
V_72 -> V_71 = V_2 -> V_8 ;
}
int F_161 ( struct V_52 * V_53 , unsigned int V_44 , struct V_72 T_2 * V_60 )
{
struct V_1 V_1 ;
struct V_72 V_72 ;
int error ;
error = - V_182 ;
if ( F_162 ( & V_72 , V_60 , sizeof( V_72 ) ) )
goto V_13;
error = - V_51 ;
if ( ( V_72 . V_71 != V_7 ) && ( V_72 . V_71 != V_49 ) )
goto V_13;
error = F_45 ( V_53 , & V_1 , & V_72 ) ;
if ( error )
goto V_13;
if ( V_44 == V_183 ) {
error = - V_51 ;
if ( V_72 . V_179 != 0 )
goto V_13;
V_44 = V_178 ;
V_1 . V_3 |= V_184 ;
V_1 . V_23 = V_53 ;
}
error = F_158 ( V_53 , & V_1 ) ;
if ( error )
goto V_13;
V_72 . V_71 = V_1 . V_8 ;
if ( V_1 . V_8 != V_6 ) {
error = F_159 ( & V_72 , & V_1 ) ;
if ( error )
goto V_185;
}
error = - V_182 ;
if ( ! F_163 ( V_60 , & V_72 , sizeof( V_72 ) ) )
error = 0 ;
V_185:
F_26 ( & V_1 ) ;
V_13:
return error ;
}
int F_164 ( struct V_52 * V_53 , unsigned int V_44 , struct V_1 * V_2 , struct V_1 * V_186 )
{
if ( V_53 -> V_173 -> V_177 )
return V_53 -> V_173 -> V_177 ( V_53 , V_44 , V_2 ) ;
else
return F_104 ( V_53 , V_2 , V_186 ) ;
}
static int F_165 ( struct V_52 * V_53 , unsigned int V_44 ,
struct V_1 * V_2 )
{
int error ;
error = F_149 ( V_53 , V_2 -> V_8 ) ;
if ( error )
return error ;
for (; ; ) {
error = F_164 ( V_53 , V_44 , V_2 , NULL ) ;
if ( error != V_114 )
break;
error = F_107 ( V_2 -> V_31 , ! V_2 -> V_94 ) ;
if ( ! error )
continue;
F_73 ( V_2 ) ;
break;
}
return error ;
}
static int
F_166 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_8 ) {
case V_7 :
if ( ! ( V_2 -> V_39 -> V_187 & V_188 ) )
return - V_189 ;
break;
case V_49 :
if ( ! ( V_2 -> V_39 -> V_187 & V_190 ) )
return - V_189 ;
}
return 0 ;
}
int F_167 ( unsigned int V_175 , struct V_52 * V_53 , unsigned int V_44 ,
struct V_72 T_2 * V_60 )
{
struct V_1 * V_1 = F_24 () ;
struct V_72 V_72 ;
struct V_10 * V_10 ;
struct V_52 * V_191 ;
int error ;
if ( V_1 == NULL )
return - V_122 ;
V_10 = F_44 ( V_53 ) ;
error = - V_182 ;
if ( F_162 ( & V_72 , V_60 , sizeof( V_72 ) ) )
goto V_13;
if ( F_168 ( V_10 ) && F_169 ( V_53 -> V_192 ) ) {
error = - V_112 ;
goto V_13;
}
error = F_45 ( V_53 , V_1 , & V_72 ) ;
if ( error )
goto V_13;
error = F_166 ( V_1 ) ;
if ( error )
goto V_13;
switch ( V_44 ) {
case V_193 :
error = - V_51 ;
if ( V_72 . V_179 != 0 )
goto V_13;
V_44 = V_194 ;
V_1 -> V_3 |= V_184 ;
V_1 -> V_23 = V_53 ;
break;
case V_195 :
error = - V_51 ;
if ( V_72 . V_179 != 0 )
goto V_13;
V_44 = V_196 ;
V_1 -> V_3 |= V_184 ;
V_1 -> V_23 = V_53 ;
case V_196 :
V_1 -> V_3 |= V_113 ;
}
error = F_165 ( V_53 , V_44 , V_1 ) ;
if ( ! error && V_1 -> V_8 != V_6 &&
! ( V_1 -> V_3 & V_184 ) ) {
F_74 ( & V_55 -> V_69 -> V_1 ) ;
V_191 = F_170 ( V_175 ) ;
F_75 ( & V_55 -> V_69 -> V_1 ) ;
if ( V_191 != V_53 ) {
V_1 -> V_8 = V_6 ;
error = F_165 ( V_53 , V_44 , V_1 ) ;
F_37 ( error ) ;
error = - V_189 ;
}
}
V_13:
F_171 ( V_10 , V_1 , error ) ;
F_27 ( V_1 ) ;
return error ;
}
int F_172 ( struct V_52 * V_53 , unsigned int V_44 , struct V_59 T_2 * V_60 )
{
struct V_1 V_1 ;
struct V_59 V_72 ;
int error ;
error = - V_182 ;
if ( F_162 ( & V_72 , V_60 , sizeof( V_72 ) ) )
goto V_13;
error = - V_51 ;
if ( ( V_72 . V_71 != V_7 ) && ( V_72 . V_71 != V_49 ) )
goto V_13;
error = F_42 ( V_53 , & V_1 , & V_72 ) ;
if ( error )
goto V_13;
if ( V_44 == V_183 ) {
error = - V_51 ;
if ( V_72 . V_179 != 0 )
goto V_13;
V_44 = V_197 ;
V_1 . V_3 |= V_184 ;
V_1 . V_23 = V_53 ;
}
error = F_158 ( V_53 , & V_1 ) ;
if ( error )
goto V_13;
V_72 . V_71 = V_1 . V_8 ;
if ( V_1 . V_8 != V_6 )
F_160 ( & V_72 , & V_1 ) ;
error = - V_182 ;
if ( ! F_163 ( V_60 , & V_72 , sizeof( V_72 ) ) )
error = 0 ;
F_26 ( & V_1 ) ;
V_13:
return error ;
}
int F_173 ( unsigned int V_175 , struct V_52 * V_53 , unsigned int V_44 ,
struct V_59 T_2 * V_60 )
{
struct V_1 * V_1 = F_24 () ;
struct V_59 V_72 ;
struct V_10 * V_10 ;
struct V_52 * V_191 ;
int error ;
if ( V_1 == NULL )
return - V_122 ;
error = - V_182 ;
if ( F_162 ( & V_72 , V_60 , sizeof( V_72 ) ) )
goto V_13;
V_10 = F_44 ( V_53 ) ;
if ( F_168 ( V_10 ) && F_169 ( V_53 -> V_192 ) ) {
error = - V_112 ;
goto V_13;
}
error = F_42 ( V_53 , V_1 , & V_72 ) ;
if ( error )
goto V_13;
error = F_166 ( V_1 ) ;
if ( error )
goto V_13;
switch ( V_44 ) {
case V_193 :
error = - V_51 ;
if ( V_72 . V_179 != 0 )
goto V_13;
V_44 = V_198 ;
V_1 -> V_3 |= V_184 ;
V_1 -> V_23 = V_53 ;
break;
case V_195 :
error = - V_51 ;
if ( V_72 . V_179 != 0 )
goto V_13;
V_44 = V_199 ;
V_1 -> V_3 |= V_184 ;
V_1 -> V_23 = V_53 ;
case V_199 :
V_1 -> V_3 |= V_113 ;
}
error = F_165 ( V_53 , V_44 , V_1 ) ;
if ( ! error && V_1 -> V_8 != V_6 &&
! ( V_1 -> V_3 & V_184 ) ) {
F_74 ( & V_55 -> V_69 -> V_1 ) ;
V_191 = F_170 ( V_175 ) ;
F_75 ( & V_55 -> V_69 -> V_1 ) ;
if ( V_191 != V_53 ) {
V_1 -> V_8 = V_6 ;
error = F_165 ( V_53 , V_44 , V_1 ) ;
F_37 ( error ) ;
error = - V_189 ;
}
}
V_13:
F_27 ( V_1 ) ;
return error ;
}
void F_174 ( struct V_52 * V_53 , T_3 V_167 )
{
int error ;
struct V_1 V_177 ;
struct V_9 * V_11 ;
V_11 = F_4 ( & F_44 ( V_53 ) -> V_12 ) ;
if ( ! V_11 || F_17 ( & V_11 -> V_18 ) )
return;
V_177 . V_8 = V_6 ;
V_177 . V_3 = V_70 | V_200 ;
V_177 . V_40 = 0 ;
V_177 . V_41 = V_58 ;
V_177 . V_23 = V_167 ;
V_177 . V_24 = V_55 -> V_56 ;
V_177 . V_39 = V_53 ;
V_177 . V_33 = NULL ;
V_177 . V_35 = NULL ;
error = F_164 ( V_53 , V_194 , & V_177 , NULL ) ;
if ( V_177 . V_33 && V_177 . V_33 -> V_34 )
V_177 . V_33 -> V_34 ( & V_177 ) ;
F_175 ( F_44 ( V_53 ) , & V_177 , error ) ;
}
static void
F_176 ( struct V_52 * V_53 , struct V_9 * V_201 )
{
struct V_1 V_2 = {
. V_23 = V_53 ,
. V_24 = V_55 -> V_56 ,
. V_39 = V_53 ,
. V_3 = V_57 ,
. V_8 = V_6 ,
. V_41 = V_58 ,
} ;
struct V_10 * V_10 = F_44 ( V_53 ) ;
if ( F_17 ( & V_201 -> V_17 ) )
return;
if ( V_53 -> V_173 -> V_72 )
V_53 -> V_173 -> V_72 ( V_53 , V_196 , & V_2 ) ;
else
F_99 ( V_10 , & V_2 ) ;
if ( V_2 . V_33 && V_2 . V_33 -> V_34 )
V_2 . V_33 -> V_34 ( & V_2 ) ;
}
static void
F_177 ( struct V_52 * V_53 , struct V_9 * V_11 )
{
struct V_1 * V_2 , * V_116 ;
F_100 ( V_37 ) ;
if ( F_17 ( & V_11 -> V_19 ) )
return;
F_74 ( & V_11 -> V_16 ) ;
F_119 (fl, tmp, &ctx->flc_lease, fl_list)
if ( V_53 == V_2 -> V_39 )
F_112 ( V_2 , V_6 , & V_37 ) ;
F_75 ( & V_11 -> V_16 ) ;
F_31 ( & V_37 ) ;
}
void F_178 ( struct V_52 * V_53 )
{
struct V_9 * V_11 ;
V_11 = F_4 ( & F_44 ( V_53 ) -> V_12 ) ;
if ( ! V_11 )
return;
F_174 ( V_53 , V_53 ) ;
F_176 ( V_53 , V_11 ) ;
F_177 ( V_53 , V_11 ) ;
}
int
F_179 ( struct V_1 * V_91 )
{
int V_202 = 0 ;
F_74 ( & V_92 ) ;
if ( V_91 -> V_94 )
F_72 ( V_91 ) ;
else
V_202 = - V_109 ;
F_75 ( & V_92 ) ;
return V_202 ;
}
int F_180 ( struct V_52 * V_53 , struct V_1 * V_2 )
{
if ( V_53 -> V_173 -> V_177 )
return V_53 -> V_173 -> V_177 ( V_53 , V_203 , V_2 ) ;
return 0 ;
}
static void F_181 ( struct V_204 * V_191 , struct V_1 * V_2 ,
T_1 V_205 , char * V_206 )
{
struct V_10 * V_10 = NULL ;
unsigned int V_24 ;
if ( V_2 -> V_98 )
V_24 = F_95 ( V_2 -> V_98 ) ;
else
V_24 = V_2 -> V_24 ;
if ( V_2 -> V_39 != NULL )
V_10 = F_44 ( V_2 -> V_39 ) ;
F_182 ( V_191 , L_7 , V_205 , V_206 ) ;
if ( F_78 ( V_2 ) ) {
if ( V_2 -> V_3 & V_110 )
F_183 ( V_191 , L_8 ) ;
else if ( F_79 ( V_2 ) )
F_183 ( V_191 , L_9 ) ;
else
F_183 ( V_191 , L_10 ) ;
F_182 ( V_191 , L_11 ,
( V_10 == NULL ) ? L_12 :
F_168 ( V_10 ) ? L_13 : L_14 ) ;
} else if ( F_184 ( V_2 ) ) {
if ( V_2 -> V_8 & V_45 ) {
F_183 ( V_191 , L_15 ) ;
} else {
F_183 ( V_191 , L_16 ) ;
}
} else if ( F_185 ( V_2 ) ) {
if ( V_2 -> V_3 & V_140 )
F_183 ( V_191 , L_17 ) ;
else
F_183 ( V_191 , L_18 ) ;
if ( F_1 ( V_2 ) )
F_183 ( V_191 , L_19 ) ;
else if ( V_2 -> V_39 )
F_183 ( V_191 , L_20 ) ;
else
F_183 ( V_191 , L_21 ) ;
} else {
F_183 ( V_191 , L_22 ) ;
}
if ( V_2 -> V_8 & V_45 ) {
F_182 ( V_191 , L_23 ,
( V_2 -> V_8 & V_207 )
? ( V_2 -> V_8 & V_208 ) ? L_24 : L_25
: ( V_2 -> V_8 & V_208 ) ? L_26 : L_27 ) ;
} else {
F_182 ( V_191 , L_23 ,
( F_1 ( V_2 ) )
? ( V_2 -> V_8 == V_6 ) ? L_28 : L_25
: ( V_2 -> V_8 == V_49 ) ? L_26 : L_25 ) ;
}
if ( V_10 ) {
F_182 ( V_191 , L_29 , V_24 ,
F_18 ( V_10 -> V_25 -> V_26 ) ,
F_19 ( V_10 -> V_25 -> V_26 ) , V_10 -> V_27 ) ;
} else {
F_182 ( V_191 , L_30 , V_24 ) ;
}
if ( F_78 ( V_2 ) ) {
if ( V_2 -> V_41 == V_58 )
F_182 ( V_191 , L_31 , V_2 -> V_40 ) ;
else
F_182 ( V_191 , L_32 , V_2 -> V_40 , V_2 -> V_41 ) ;
} else {
F_183 ( V_191 , L_33 ) ;
}
}
static int F_186 ( struct V_204 * V_191 , void * V_209 )
{
struct V_210 * V_211 = V_191 -> V_212 ;
struct V_1 * V_2 , * V_213 ;
V_2 = F_187 ( V_209 , struct V_1 , V_28 ) ;
F_181 ( V_191 , V_2 , V_211 -> V_214 , L_34 ) ;
F_13 (bfl, &fl->fl_block, fl_block)
F_181 ( V_191 , V_213 , V_211 -> V_214 , L_35 ) ;
return 0 ;
}
static void F_188 ( struct V_204 * V_191 ,
struct V_20 * V_215 , int * V_205 ,
struct V_52 * V_53 , struct V_216 * V_69 )
{
struct V_1 * V_2 ;
F_13 (fl, head, fl_list) {
if ( V_53 != V_2 -> V_39 )
continue;
if ( V_2 -> V_23 != V_69 &&
V_2 -> V_23 != V_53 )
continue;
( * V_205 ) ++ ;
F_183 ( V_191 , L_36 ) ;
F_181 ( V_191 , V_2 , * V_205 , L_34 ) ;
}
}
void F_189 ( struct V_204 * V_191 ,
struct V_52 * V_53 , struct V_216 * V_69 )
{
struct V_10 * V_10 = F_44 ( V_53 ) ;
struct V_9 * V_11 ;
int V_205 = 0 ;
V_11 = F_4 ( & V_10 -> V_12 ) ;
if ( ! V_11 )
return;
F_74 ( & V_11 -> V_16 ) ;
F_188 ( V_191 , & V_11 -> V_17 , & V_205 , V_53 , V_69 ) ;
F_188 ( V_191 , & V_11 -> V_18 , & V_205 , V_53 , V_69 ) ;
F_188 ( V_191 , & V_11 -> V_19 , & V_205 , V_53 , V_69 ) ;
F_75 ( & V_11 -> V_16 ) ;
}
static void * F_190 ( struct V_204 * V_191 , T_1 * V_217 )
__acquires( &blocked_lock_lock
static void * F_191 ( struct V_204 * V_191 , void * V_209 , T_1 * V_217 )
{
struct V_210 * V_211 = V_191 -> V_212 ;
++ V_211 -> V_214 ;
return F_192 ( V_209 , & V_89 , & V_211 -> V_218 , V_217 ) ;
}
static void F_193 ( struct V_204 * V_191 , void * V_209 )
__releases( &blocked_lock_lock
static int F_194 ( struct V_10 * V_10 , struct V_52 * V_53 )
{
return F_195 ( V_53 , & V_219 ,
sizeof( struct V_210 ) ) ;
}
static int T_4 F_196 ( void )
{
F_197 ( L_37 , 0 , NULL , & V_220 ) ;
return 0 ;
}
static int T_4 F_198 ( void )
{
int V_103 ;
V_14 = F_199 ( L_38 ,
sizeof( struct V_9 ) , 0 , V_221 , NULL ) ;
V_32 = F_199 ( L_39 ,
sizeof( struct V_1 ) , 0 , V_221 , NULL ) ;
F_200 ( & V_87 , L_40 ) ;
F_201 (i)
F_202 ( F_203 ( & V_89 , V_103 ) ) ;
return 0 ;
}
