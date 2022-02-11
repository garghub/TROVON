static inline bool F_1 ( struct V_1 * V_2 )
{
return F_2 ( ! ( V_2 -> V_3 . V_4 -> V_5 -> V_6 & V_7 ) ) ;
}
static bool F_3 ( struct V_8 * V_9 )
{
return V_9 -> V_10 & ( V_11 | V_12 ) ;
}
static int F_4 ( struct V_8 * V_9 )
{
if ( V_9 -> V_10 & V_11 )
return V_13 ;
if ( V_9 -> V_10 & V_12 )
return V_14 ;
return V_9 -> V_15 ;
}
static struct V_16 *
F_5 ( struct V_17 * V_17 , int type )
{
struct V_16 * V_18 ;
V_18 = F_6 ( & V_17 -> V_19 ) ;
if ( F_2 ( V_18 ) || type == V_13 )
goto V_20;
V_18 = F_7 ( V_21 , V_22 ) ;
if ( ! V_18 )
goto V_20;
F_8 ( & V_18 -> V_23 ) ;
F_9 ( & V_18 -> V_24 ) ;
F_9 ( & V_18 -> V_25 ) ;
F_9 ( & V_18 -> V_26 ) ;
if ( F_10 ( & V_17 -> V_19 , NULL , V_18 ) ) {
F_11 ( V_21 , V_18 ) ;
V_18 = F_6 ( & V_17 -> V_19 ) ;
}
V_20:
F_12 ( V_17 , type , V_18 ) ;
return V_18 ;
}
static void
F_13 ( struct V_27 * V_28 , char * V_29 )
{
struct V_8 * V_9 ;
F_14 (fl, list, fl_list) {
F_15 ( L_1 , V_29 , V_9 -> V_30 , V_9 -> V_10 , V_9 -> V_15 , V_9 -> V_31 ) ;
}
}
static void
F_16 ( struct V_17 * V_17 )
{
struct V_16 * V_18 = V_17 -> V_19 ;
if ( F_17 ( ! F_18 ( & V_18 -> V_24 ) ||
! F_18 ( & V_18 -> V_25 ) ||
! F_18 ( & V_18 -> V_26 ) ) ) {
F_15 ( L_2 ,
F_19 ( V_17 -> V_32 -> V_33 ) , F_20 ( V_17 -> V_32 -> V_33 ) ,
V_17 -> V_34 ) ;
F_13 ( & V_18 -> V_24 , L_3 ) ;
F_13 ( & V_18 -> V_25 , L_4 ) ;
F_13 ( & V_18 -> V_26 , L_5 ) ;
}
}
void
F_21 ( struct V_17 * V_17 )
{
struct V_16 * V_18 = V_17 -> V_19 ;
if ( F_17 ( V_18 ) ) {
F_16 ( V_17 ) ;
F_11 ( V_21 , V_18 ) ;
}
}
static void F_22 ( struct V_8 * V_9 )
{
F_23 ( & V_9 -> V_35 ) ;
F_9 ( & V_9 -> V_36 ) ;
F_9 ( & V_9 -> V_37 ) ;
F_24 ( & V_9 -> V_38 ) ;
}
struct V_8 * F_25 ( void )
{
struct V_8 * V_9 = F_26 ( V_39 , V_22 ) ;
if ( V_9 )
F_22 ( V_9 ) ;
return V_9 ;
}
void F_27 ( struct V_8 * V_9 )
{
if ( V_9 -> V_40 ) {
if ( V_9 -> V_40 -> V_41 )
V_9 -> V_40 -> V_41 ( V_9 ) ;
V_9 -> V_40 = NULL ;
}
if ( V_9 -> V_42 ) {
if ( V_9 -> V_42 -> V_43 ) {
V_9 -> V_42 -> V_43 ( V_9 -> V_30 ) ;
V_9 -> V_30 = NULL ;
}
V_9 -> V_42 = NULL ;
}
}
void F_28 ( struct V_8 * V_9 )
{
F_29 ( F_30 ( & V_9 -> V_38 ) ) ;
F_29 ( ! F_18 ( & V_9 -> V_36 ) ) ;
F_29 ( ! F_18 ( & V_9 -> V_37 ) ) ;
F_29 ( ! F_31 ( & V_9 -> V_35 ) ) ;
F_27 ( V_9 ) ;
F_11 ( V_39 , V_9 ) ;
}
static void
F_32 ( struct V_27 * V_44 )
{
struct V_8 * V_9 ;
while ( ! F_18 ( V_44 ) ) {
V_9 = F_33 ( V_44 , struct V_8 , V_36 ) ;
F_34 ( & V_9 -> V_36 ) ;
F_28 ( V_9 ) ;
}
}
void F_35 ( struct V_8 * V_9 )
{
memset ( V_9 , 0 , sizeof( struct V_8 ) ) ;
F_22 ( V_9 ) ;
}
void F_36 ( struct V_8 * V_45 , struct V_8 * V_9 )
{
V_45 -> V_30 = V_9 -> V_30 ;
V_45 -> V_31 = V_9 -> V_31 ;
V_45 -> V_46 = NULL ;
V_45 -> V_10 = V_9 -> V_10 ;
V_45 -> V_15 = V_9 -> V_15 ;
V_45 -> V_47 = V_9 -> V_47 ;
V_45 -> V_48 = V_9 -> V_48 ;
V_45 -> V_42 = V_9 -> V_42 ;
V_45 -> V_40 = NULL ;
if ( V_9 -> V_42 ) {
if ( V_9 -> V_42 -> V_49 )
V_9 -> V_42 -> V_49 ( V_9 -> V_30 ) ;
}
}
void F_37 ( struct V_8 * V_45 , struct V_8 * V_9 )
{
F_38 ( V_45 -> V_40 ) ;
F_36 ( V_45 , V_9 ) ;
V_45 -> V_46 = V_9 -> V_46 ;
V_45 -> V_40 = V_9 -> V_40 ;
if ( V_9 -> V_40 ) {
if ( V_9 -> V_40 -> V_50 )
V_9 -> V_40 -> V_50 ( V_45 , V_9 ) ;
}
}
static inline int F_39 ( int V_51 ) {
if ( V_51 & V_52 )
return V_51 & ( V_52 | V_53 ) ;
switch ( V_51 ) {
case V_54 :
return V_14 ;
case V_55 :
return V_56 ;
case V_57 :
return V_13 ;
}
return - V_58 ;
}
static struct V_8 *
F_40 ( struct V_1 * V_2 , unsigned int V_51 )
{
struct V_8 * V_9 ;
int type = F_39 ( V_51 ) ;
if ( type < 0 )
return F_41 ( type ) ;
V_9 = F_25 () ;
if ( V_9 == NULL )
return F_41 ( - V_59 ) ;
V_9 -> V_46 = V_2 ;
V_9 -> V_30 = V_2 ;
V_9 -> V_31 = V_60 -> V_61 ;
V_9 -> V_10 = V_62 ;
V_9 -> V_15 = type ;
V_9 -> V_48 = V_63 ;
return V_9 ;
}
static int F_42 ( struct V_8 * V_9 , long type )
{
switch ( type ) {
case V_14 :
case V_56 :
case V_13 :
V_9 -> V_15 = type ;
break;
default:
return - V_58 ;
}
return 0 ;
}
static int F_43 ( struct V_1 * V_2 , struct V_8 * V_9 ,
struct V_64 * V_65 )
{
switch ( V_65 -> V_66 ) {
case V_67 :
V_9 -> V_47 = 0 ;
break;
case V_68 :
V_9 -> V_47 = V_2 -> V_69 ;
break;
case V_70 :
V_9 -> V_47 = F_44 ( F_45 ( V_2 ) ) ;
break;
default:
return - V_58 ;
}
if ( V_65 -> V_71 > V_63 - V_9 -> V_47 )
return - V_72 ;
V_9 -> V_47 += V_65 -> V_71 ;
if ( V_9 -> V_47 < 0 )
return - V_58 ;
if ( V_65 -> V_73 > 0 ) {
if ( V_65 -> V_73 - 1 > V_63 - V_9 -> V_47 )
return - V_72 ;
V_9 -> V_48 = V_9 -> V_47 + V_65 -> V_73 - 1 ;
} else if ( V_65 -> V_73 < 0 ) {
if ( V_9 -> V_47 + V_65 -> V_73 < 0 )
return - V_58 ;
V_9 -> V_48 = V_9 -> V_47 - 1 ;
V_9 -> V_47 += V_65 -> V_73 ;
} else
V_9 -> V_48 = V_63 ;
V_9 -> V_30 = V_60 -> V_74 ;
V_9 -> V_31 = V_60 -> V_61 ;
V_9 -> V_46 = V_2 ;
V_9 -> V_10 = V_75 ;
V_9 -> V_40 = NULL ;
V_9 -> V_42 = NULL ;
return F_42 ( V_9 , V_65 -> V_76 ) ;
}
static int F_46 ( struct V_1 * V_2 , struct V_8 * V_9 ,
struct V_77 * V_65 )
{
struct V_64 V_78 = {
. V_76 = V_65 -> V_76 ,
. V_66 = V_65 -> V_66 ,
. V_71 = V_65 -> V_71 ,
. V_73 = V_65 -> V_73 ,
} ;
return F_43 ( V_2 , V_9 , & V_78 ) ;
}
static bool
F_47 ( struct V_8 * V_9 )
{
F_48 ( & V_9 -> V_79 , V_80 , V_81 ) ;
return false ;
}
static void
F_49 ( struct V_8 * V_9 , void * * V_82 )
{
struct V_1 * V_2 = V_9 -> V_46 ;
struct V_83 * V_84 = * V_82 ;
if ( ! F_50 ( V_84 -> V_85 , V_2 , & V_9 -> V_79 , V_84 ) )
* V_82 = NULL ;
F_51 ( V_2 , F_52 ( V_60 ) , V_86 , 0 ) ;
}
static int F_53 ( struct V_1 * V_2 , long type , struct V_8 * V_9 )
{
if ( F_42 ( V_9 , type ) != 0 )
return - V_58 ;
V_9 -> V_30 = V_2 ;
V_9 -> V_31 = V_60 -> V_61 ;
V_9 -> V_46 = V_2 ;
V_9 -> V_10 = V_87 ;
V_9 -> V_47 = 0 ;
V_9 -> V_48 = V_63 ;
V_9 -> V_40 = NULL ;
V_9 -> V_42 = & V_88 ;
return 0 ;
}
static struct V_8 * F_54 ( struct V_1 * V_2 , long type )
{
struct V_8 * V_9 = F_25 () ;
int error = - V_59 ;
if ( V_9 == NULL )
return F_41 ( error ) ;
error = F_53 ( V_2 , type , V_9 ) ;
if ( error ) {
F_28 ( V_9 ) ;
return F_41 ( error ) ;
}
return V_9 ;
}
static inline int F_55 ( struct V_8 * V_89 , struct V_8 * V_90 )
{
return ( ( V_89 -> V_48 >= V_90 -> V_47 ) &&
( V_90 -> V_48 >= V_89 -> V_47 ) ) ;
}
static int F_56 ( struct V_8 * V_89 , struct V_8 * V_90 )
{
if ( V_89 -> V_42 && V_89 -> V_42 -> V_91 )
return V_90 -> V_42 == V_89 -> V_42 &&
V_89 -> V_42 -> V_91 ( V_89 , V_90 ) ;
return V_89 -> V_30 == V_90 -> V_30 ;
}
static void F_57 ( struct V_8 * V_9 )
{
struct V_92 * V_93 = F_58 ( & V_94 ) ;
F_59 ( & V_95 ) ;
F_60 ( & V_93 -> V_96 ) ;
V_9 -> V_97 = F_61 () ;
F_62 ( & V_9 -> V_35 , & V_93 -> V_98 ) ;
F_63 ( & V_93 -> V_96 ) ;
}
static void F_64 ( struct V_8 * V_9 )
{
struct V_92 * V_93 ;
F_59 ( & V_95 ) ;
if ( F_31 ( & V_9 -> V_35 ) )
return;
V_93 = F_65 ( & V_94 , V_9 -> V_97 ) ;
F_60 ( & V_93 -> V_96 ) ;
F_66 ( & V_9 -> V_35 ) ;
F_63 ( & V_93 -> V_96 ) ;
}
static unsigned long
F_67 ( struct V_8 * V_9 )
{
if ( V_9 -> V_42 && V_9 -> V_42 -> V_99 )
return V_9 -> V_42 -> V_99 ( V_9 ) ;
return ( unsigned long ) V_9 -> V_30 ;
}
static void F_68 ( struct V_8 * V_100 )
{
F_69 ( & V_101 ) ;
F_70 ( V_102 , & V_100 -> V_35 , F_67 ( V_100 ) ) ;
}
static void F_71 ( struct V_8 * V_100 )
{
F_69 ( & V_101 ) ;
F_72 ( & V_100 -> V_35 ) ;
}
static void F_73 ( struct V_8 * V_100 )
{
F_71 ( V_100 ) ;
F_34 ( & V_100 -> V_37 ) ;
V_100 -> V_103 = NULL ;
}
static void F_74 ( struct V_8 * V_100 )
{
F_60 ( & V_101 ) ;
F_73 ( V_100 ) ;
F_63 ( & V_101 ) ;
}
static void F_75 ( struct V_8 * V_104 ,
struct V_8 * V_100 )
{
F_29 ( ! F_18 ( & V_100 -> V_37 ) ) ;
V_100 -> V_103 = V_104 ;
F_76 ( & V_100 -> V_37 , & V_104 -> V_37 ) ;
if ( F_77 ( V_104 ) && ! F_78 ( V_104 ) )
F_68 ( V_100 ) ;
}
static void F_79 ( struct V_8 * V_104 ,
struct V_8 * V_100 )
{
F_60 ( & V_101 ) ;
F_75 ( V_104 , V_100 ) ;
F_63 ( & V_101 ) ;
}
static void F_80 ( struct V_8 * V_104 )
{
if ( F_18 ( & V_104 -> V_37 ) )
return;
F_60 ( & V_101 ) ;
while ( ! F_18 ( & V_104 -> V_37 ) ) {
struct V_8 * V_100 ;
V_100 = F_33 ( & V_104 -> V_37 ,
struct V_8 , V_37 ) ;
F_73 ( V_100 ) ;
if ( V_100 -> V_42 && V_100 -> V_42 -> V_105 )
V_100 -> V_42 -> V_105 ( V_100 ) ;
else
F_81 ( & V_100 -> V_38 ) ;
}
F_63 ( & V_101 ) ;
}
static void
F_82 ( struct V_8 * V_9 , struct V_27 * V_106 )
{
V_9 -> V_107 = F_83 ( F_84 ( V_60 ) ) ;
F_76 ( & V_9 -> V_36 , V_106 ) ;
F_57 ( V_9 ) ;
}
static void
F_85 ( struct V_8 * V_9 )
{
F_64 ( V_9 ) ;
F_34 ( & V_9 -> V_36 ) ;
if ( V_9 -> V_107 ) {
F_86 ( V_9 -> V_107 ) ;
V_9 -> V_107 = NULL ;
}
F_80 ( V_9 ) ;
}
static void
F_87 ( struct V_8 * V_9 , struct V_27 * V_44 )
{
F_85 ( V_9 ) ;
if ( V_44 )
F_88 ( & V_9 -> V_36 , V_44 ) ;
else
F_28 ( V_9 ) ;
}
static int F_89 ( struct V_8 * V_108 , struct V_8 * V_109 )
{
if ( V_109 -> V_15 == V_56 )
return 1 ;
if ( V_108 -> V_15 == V_56 )
return 1 ;
return 0 ;
}
static int F_90 ( struct V_8 * V_108 , struct V_8 * V_109 )
{
if ( F_56 ( V_108 , V_109 ) )
return ( 0 ) ;
if ( ! F_55 ( V_108 , V_109 ) )
return 0 ;
return ( F_89 ( V_108 , V_109 ) ) ;
}
static int F_91 ( struct V_8 * V_108 , struct V_8 * V_109 )
{
if ( V_108 -> V_46 == V_109 -> V_46 )
return ( 0 ) ;
if ( ( V_108 -> V_15 & V_52 ) || ( V_109 -> V_15 & V_52 ) )
return 0 ;
return ( F_89 ( V_108 , V_109 ) ) ;
}
void
F_92 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
struct V_8 * V_110 ;
struct V_16 * V_18 ;
struct V_17 * V_17 = F_93 ( V_2 ) ;
V_18 = F_6 ( & V_17 -> V_19 ) ;
if ( ! V_18 || F_94 ( & V_18 -> V_25 ) ) {
V_9 -> V_15 = V_13 ;
return;
}
F_60 ( & V_18 -> V_23 ) ;
F_14 (cfl, &ctx->flc_posix, fl_list) {
if ( F_90 ( V_9 , V_110 ) ) {
F_36 ( V_9 , V_110 ) ;
if ( V_110 -> V_107 )
V_9 -> V_31 = F_95 ( V_110 -> V_107 ) ;
goto V_20;
}
}
V_9 -> V_15 = V_13 ;
V_20:
F_63 ( & V_18 -> V_23 ) ;
return;
}
static struct V_8 * F_96 ( struct V_8 * V_111 )
{
struct V_8 * V_9 ;
F_97 (blocked_hash, fl, fl_link, posix_owner_key(block_fl)) {
if ( F_56 ( V_9 , V_111 ) )
return V_9 -> V_103 ;
}
return NULL ;
}
static int F_98 ( struct V_8 * V_108 ,
struct V_8 * V_111 )
{
int V_112 = 0 ;
F_69 ( & V_101 ) ;
if ( F_78 ( V_108 ) )
return 0 ;
while ( ( V_111 = F_96 ( V_111 ) ) ) {
if ( V_112 ++ > V_113 )
return 0 ;
if ( F_56 ( V_108 , V_111 ) )
return 1 ;
}
return 0 ;
}
static int F_99 ( struct V_17 * V_17 , struct V_8 * V_114 )
{
struct V_8 * V_115 = NULL ;
struct V_8 * V_9 ;
struct V_16 * V_18 ;
int error = 0 ;
bool V_116 = false ;
F_100 ( V_44 ) ;
V_18 = F_5 ( V_17 , V_114 -> V_15 ) ;
if ( ! V_18 ) {
if ( V_114 -> V_15 != V_13 )
return - V_59 ;
return ( V_114 -> V_10 & V_117 ) ? - V_118 : 0 ;
}
if ( ! ( V_114 -> V_10 & V_119 ) && ( V_114 -> V_15 != V_13 ) ) {
V_115 = F_25 () ;
if ( ! V_115 )
return - V_59 ;
}
F_101 ( & V_95 ) ;
F_60 ( & V_18 -> V_23 ) ;
if ( V_114 -> V_10 & V_119 )
goto V_120;
F_14 (fl, &ctx->flc_flock, fl_list) {
if ( V_114 -> V_46 != V_9 -> V_46 )
continue;
if ( V_114 -> V_15 == V_9 -> V_15 )
goto V_20;
V_116 = true ;
F_87 ( V_9 , & V_44 ) ;
break;
}
if ( V_114 -> V_15 == V_13 ) {
if ( ( V_114 -> V_10 & V_117 ) && ! V_116 )
error = - V_118 ;
goto V_20;
}
V_120:
F_14 (fl, &ctx->flc_flock, fl_list) {
if ( ! F_91 ( V_114 , V_9 ) )
continue;
error = - V_121 ;
if ( ! ( V_114 -> V_10 & V_122 ) )
goto V_20;
error = V_123 ;
F_79 ( V_9 , V_114 ) ;
goto V_20;
}
if ( V_114 -> V_10 & V_119 )
goto V_20;
F_37 ( V_115 , V_114 ) ;
F_82 ( V_115 , & V_18 -> V_24 ) ;
V_115 = NULL ;
error = 0 ;
V_20:
F_63 ( & V_18 -> V_23 ) ;
F_102 ( & V_95 ) ;
if ( V_115 )
F_28 ( V_115 ) ;
F_32 ( & V_44 ) ;
return error ;
}
static int F_103 ( struct V_17 * V_17 , struct V_8 * V_114 ,
struct V_8 * V_124 )
{
struct V_8 * V_9 , * V_125 ;
struct V_8 * V_115 = NULL ;
struct V_8 * V_126 = NULL ;
struct V_8 * V_127 = NULL ;
struct V_8 * V_128 = NULL ;
struct V_16 * V_18 ;
int error ;
bool V_129 = false ;
F_100 ( V_44 ) ;
V_18 = F_5 ( V_17 , V_114 -> V_15 ) ;
if ( ! V_18 )
return ( V_114 -> V_15 == V_13 ) ? 0 : - V_59 ;
if ( ! ( V_114 -> V_10 & V_119 ) &&
( V_114 -> V_15 != V_13 ||
V_114 -> V_47 != 0 || V_114 -> V_48 != V_63 ) ) {
V_115 = F_25 () ;
V_126 = F_25 () ;
}
F_101 ( & V_95 ) ;
F_60 ( & V_18 -> V_23 ) ;
if ( V_114 -> V_15 != V_13 ) {
F_14 (fl, &ctx->flc_posix, fl_list) {
if ( ! F_90 ( V_114 , V_9 ) )
continue;
if ( V_124 )
F_36 ( V_124 , V_9 ) ;
error = - V_121 ;
if ( ! ( V_114 -> V_10 & V_122 ) )
goto V_20;
error = - V_130 ;
F_60 ( & V_101 ) ;
if ( F_2 ( ! F_98 ( V_114 , V_9 ) ) ) {
error = V_123 ;
F_75 ( V_9 , V_114 ) ;
}
F_63 ( & V_101 ) ;
goto V_20;
}
}
error = 0 ;
if ( V_114 -> V_10 & V_119 )
goto V_20;
F_14 (fl, &ctx->flc_posix, fl_list) {
if ( F_56 ( V_114 , V_9 ) )
break;
}
F_104 (fl, tmp, &ctx->flc_posix, fl_list) {
if ( ! F_56 ( V_114 , V_9 ) )
break;
if ( V_114 -> V_15 == V_9 -> V_15 ) {
if ( V_9 -> V_48 < V_114 -> V_47 - 1 )
continue;
if ( V_9 -> V_47 - 1 > V_114 -> V_48 )
break;
if ( V_9 -> V_47 > V_114 -> V_47 )
V_9 -> V_47 = V_114 -> V_47 ;
else
V_114 -> V_47 = V_9 -> V_47 ;
if ( V_9 -> V_48 < V_114 -> V_48 )
V_9 -> V_48 = V_114 -> V_48 ;
else
V_114 -> V_48 = V_9 -> V_48 ;
if ( V_129 ) {
F_87 ( V_9 , & V_44 ) ;
continue;
}
V_114 = V_9 ;
V_129 = true ;
} else {
if ( V_9 -> V_48 < V_114 -> V_47 )
continue;
if ( V_9 -> V_47 > V_114 -> V_48 )
break;
if ( V_114 -> V_15 == V_13 )
V_129 = true ;
if ( V_9 -> V_47 < V_114 -> V_47 )
V_127 = V_9 ;
if ( V_9 -> V_48 > V_114 -> V_48 ) {
V_128 = V_9 ;
break;
}
if ( V_9 -> V_47 >= V_114 -> V_47 ) {
if ( V_129 ) {
F_87 ( V_9 , & V_44 ) ;
continue;
}
error = - V_131 ;
if ( ! V_115 )
goto V_20;
F_37 ( V_115 , V_114 ) ;
V_114 = V_115 ;
V_115 = NULL ;
F_82 ( V_114 , & V_9 -> V_36 ) ;
F_87 ( V_9 , & V_44 ) ;
V_129 = true ;
}
}
}
error = - V_131 ;
if ( V_128 && V_127 == V_128 && ! V_126 )
goto V_20;
error = 0 ;
if ( ! V_129 ) {
if ( V_114 -> V_15 == V_13 ) {
if ( V_114 -> V_10 & V_117 )
error = - V_118 ;
goto V_20;
}
if ( ! V_115 ) {
error = - V_131 ;
goto V_20;
}
F_37 ( V_115 , V_114 ) ;
F_82 ( V_115 , & V_9 -> V_36 ) ;
V_9 = V_115 ;
V_115 = NULL ;
}
if ( V_128 ) {
if ( V_127 == V_128 ) {
V_127 = V_126 ;
V_126 = NULL ;
F_37 ( V_127 , V_128 ) ;
F_82 ( V_127 , & V_9 -> V_36 ) ;
}
V_128 -> V_47 = V_114 -> V_48 + 1 ;
F_80 ( V_128 ) ;
}
if ( V_127 ) {
V_127 -> V_48 = V_114 -> V_47 - 1 ;
F_80 ( V_127 ) ;
}
V_20:
F_63 ( & V_18 -> V_23 ) ;
F_102 ( & V_95 ) ;
if ( V_115 )
F_28 ( V_115 ) ;
if ( V_126 )
F_28 ( V_126 ) ;
F_32 ( & V_44 ) ;
F_105 ( V_17 , V_114 , error ) ;
return error ;
}
int F_106 ( struct V_1 * V_2 , struct V_8 * V_9 ,
struct V_8 * V_124 )
{
return F_103 ( F_93 ( V_2 ) , V_9 , V_124 ) ;
}
static int F_107 ( struct V_17 * V_17 , struct V_8 * V_9 )
{
int error ;
F_108 () ;
for (; ; ) {
error = F_103 ( V_17 , V_9 , NULL ) ;
if ( error != V_123 )
break;
error = F_109 ( V_9 -> V_38 , ! V_9 -> V_103 ) ;
if ( ! error )
continue;
F_74 ( V_9 ) ;
break;
}
return error ;
}
int F_110 ( struct V_1 * V_1 )
{
int V_132 ;
struct V_17 * V_17 = F_93 ( V_1 ) ;
struct V_16 * V_18 ;
struct V_8 * V_9 ;
V_18 = F_6 ( & V_17 -> V_19 ) ;
if ( ! V_18 || F_94 ( & V_18 -> V_25 ) )
return 0 ;
F_60 ( & V_18 -> V_23 ) ;
V_132 = 0 ;
F_14 (fl, &ctx->flc_posix, fl_list) {
if ( V_9 -> V_30 != V_60 -> V_74 &&
V_9 -> V_30 != V_1 ) {
V_132 = - V_121 ;
break;
}
}
F_63 ( & V_18 -> V_23 ) ;
return V_132 ;
}
int F_111 ( struct V_17 * V_17 , struct V_1 * V_2 , T_1 V_133 ,
T_1 V_134 , unsigned char type )
{
struct V_8 V_9 ;
int error ;
bool V_135 = false ;
F_35 ( & V_9 ) ;
V_9 . V_31 = V_60 -> V_61 ;
V_9 . V_46 = V_2 ;
V_9 . V_10 = V_75 | V_119 ;
if ( V_2 && ! ( V_2 -> V_136 & V_137 ) )
V_135 = true ;
V_9 . V_15 = type ;
V_9 . V_47 = V_133 ;
V_9 . V_48 = V_134 ;
for (; ; ) {
if ( V_2 ) {
V_9 . V_30 = V_2 ;
V_9 . V_10 &= ~ V_122 ;
error = F_103 ( V_17 , & V_9 , NULL ) ;
if ( ! error )
break;
}
if ( V_135 )
V_9 . V_10 |= V_122 ;
V_9 . V_30 = V_60 -> V_74 ;
error = F_103 ( V_17 , & V_9 , NULL ) ;
if ( error != V_123 )
break;
error = F_109 ( V_9 . V_38 , ! V_9 . V_103 ) ;
if ( ! error ) {
if ( F_112 ( V_17 ) )
continue;
}
F_74 ( & V_9 ) ;
break;
}
return error ;
}
static void F_113 ( struct V_8 * V_9 , int V_138 )
{
switch ( V_138 ) {
case V_13 :
V_9 -> V_10 &= ~ V_11 ;
case V_14 :
V_9 -> V_10 &= ~ V_12 ;
}
}
int F_114 ( struct V_8 * V_9 , int V_138 , struct V_27 * V_44 )
{
int error = F_42 ( V_9 , V_138 ) ;
if ( error )
return error ;
F_113 ( V_9 , V_138 ) ;
F_80 ( V_9 ) ;
if ( V_138 == V_13 ) {
struct V_1 * V_2 = V_9 -> V_46 ;
F_115 ( V_2 ) ;
V_2 -> V_139 . V_140 = 0 ;
F_116 ( 0 , V_9 -> V_46 , 0 , & V_9 -> V_79 ) ;
if ( V_9 -> V_79 != NULL ) {
F_117 ( V_141 L_6 , V_9 -> V_79 ) ;
V_9 -> V_79 = NULL ;
}
F_87 ( V_9 , V_44 ) ;
}
return 0 ;
}
static bool F_118 ( unsigned long V_142 )
{
if ( ! V_142 )
return false ;
return F_119 ( V_143 , V_142 ) ;
}
static void F_120 ( struct V_17 * V_17 , struct V_27 * V_44 )
{
struct V_16 * V_18 = V_17 -> V_19 ;
struct V_8 * V_9 , * V_125 ;
F_69 ( & V_18 -> V_23 ) ;
F_121 (fl, tmp, &ctx->flc_lease, fl_list) {
F_122 ( V_17 , V_9 ) ;
if ( F_118 ( V_9 -> V_144 ) )
F_114 ( V_9 , V_14 , V_44 ) ;
if ( F_118 ( V_9 -> V_145 ) )
F_114 ( V_9 , V_13 , V_44 ) ;
}
}
static bool F_123 ( struct V_8 * V_146 , struct V_8 * V_147 )
{
if ( ( V_147 -> V_10 & V_148 ) != ( V_146 -> V_10 & V_148 ) )
return false ;
if ( ( V_147 -> V_10 & V_149 ) && ( V_146 -> V_10 & V_87 ) )
return false ;
return F_89 ( V_147 , V_146 ) ;
}
static bool
F_124 ( struct V_17 * V_17 , struct V_8 * V_147 )
{
struct V_16 * V_18 = V_17 -> V_19 ;
struct V_8 * V_9 ;
F_69 ( & V_18 -> V_23 ) ;
F_14 (fl, &ctx->flc_lease, fl_list) {
if ( F_123 ( V_9 , V_147 ) )
return true ;
}
return false ;
}
int F_125 ( struct V_17 * V_17 , unsigned int V_150 , unsigned int type )
{
int error = 0 ;
struct V_16 * V_18 ;
struct V_8 * V_115 , * V_9 , * V_125 ;
unsigned long V_151 ;
int V_152 = ( V_150 & V_153 ) != V_154 ;
F_100 ( V_44 ) ;
V_115 = F_54 ( NULL , V_152 ? V_56 : V_14 ) ;
if ( F_126 ( V_115 ) )
return F_127 ( V_115 ) ;
V_115 -> V_10 = type ;
V_18 = F_6 ( & V_17 -> V_19 ) ;
if ( ! V_18 ) {
F_38 ( 1 ) ;
return error ;
}
F_101 ( & V_95 ) ;
F_60 ( & V_18 -> V_23 ) ;
F_120 ( V_17 , & V_44 ) ;
if ( ! F_124 ( V_17 , V_115 ) )
goto V_20;
V_151 = 0 ;
if ( V_155 > 0 ) {
V_151 = V_143 + V_155 * V_156 ;
if ( V_151 == 0 )
V_151 ++ ;
}
F_121 (fl, tmp, &ctx->flc_lease, fl_list) {
if ( ! F_123 ( V_9 , V_115 ) )
continue;
if ( V_152 ) {
if ( V_9 -> V_10 & V_11 )
continue;
V_9 -> V_10 |= V_11 ;
V_9 -> V_145 = V_151 ;
} else {
if ( F_3 ( V_9 ) )
continue;
V_9 -> V_10 |= V_12 ;
V_9 -> V_144 = V_151 ;
}
if ( V_9 -> V_42 -> V_157 ( V_9 ) )
F_87 ( V_9 , & V_44 ) ;
}
if ( F_18 ( & V_18 -> V_26 ) )
goto V_20;
if ( V_150 & V_137 ) {
F_128 ( V_17 , V_115 ) ;
error = - V_158 ;
goto V_20;
}
V_159:
V_9 = F_33 ( & V_18 -> V_26 , struct V_8 , V_36 ) ;
V_151 = V_9 -> V_145 ;
if ( V_151 != 0 )
V_151 -= V_143 ;
if ( V_151 == 0 )
V_151 ++ ;
F_79 ( V_9 , V_115 ) ;
F_129 ( V_17 , V_115 ) ;
F_63 ( & V_18 -> V_23 ) ;
F_102 ( & V_95 ) ;
F_32 ( & V_44 ) ;
error = F_130 ( V_115 -> V_38 ,
! V_115 -> V_103 , V_151 ) ;
F_101 ( & V_95 ) ;
F_60 ( & V_18 -> V_23 ) ;
F_131 ( V_17 , V_115 ) ;
F_74 ( V_115 ) ;
if ( error >= 0 ) {
if ( error == 0 )
F_120 ( V_17 , & V_44 ) ;
if ( F_124 ( V_17 , V_115 ) )
goto V_159;
error = 0 ;
}
V_20:
F_63 ( & V_18 -> V_23 ) ;
F_102 ( & V_95 ) ;
F_32 ( & V_44 ) ;
F_28 ( V_115 ) ;
return error ;
}
void F_132 ( struct V_17 * V_17 , struct V_160 * time )
{
bool V_161 = false ;
struct V_16 * V_18 ;
struct V_8 * V_9 ;
V_18 = F_6 ( & V_17 -> V_19 ) ;
if ( V_18 && ! F_94 ( & V_18 -> V_26 ) ) {
F_60 ( & V_18 -> V_23 ) ;
V_9 = F_133 ( & V_18 -> V_26 ,
struct V_8 , V_36 ) ;
if ( V_9 && ( V_9 -> V_15 == V_56 ) )
V_161 = true ;
F_63 ( & V_18 -> V_23 ) ;
}
if ( V_161 )
* time = F_134 ( V_17 ) ;
else
* time = V_17 -> V_162 ;
}
int F_135 ( struct V_1 * V_2 )
{
struct V_8 * V_9 ;
struct V_17 * V_17 = F_93 ( V_2 ) ;
struct V_16 * V_18 ;
int type = V_13 ;
F_100 ( V_44 ) ;
V_18 = F_6 ( & V_17 -> V_19 ) ;
if ( V_18 && ! F_94 ( & V_18 -> V_26 ) ) {
F_101 ( & V_95 ) ;
F_60 ( & V_18 -> V_23 ) ;
F_120 ( V_17 , & V_44 ) ;
F_14 (fl, &ctx->flc_lease, fl_list) {
if ( V_9 -> V_46 != V_2 )
continue;
type = F_4 ( V_9 ) ;
break;
}
F_63 ( & V_18 -> V_23 ) ;
F_102 ( & V_95 ) ;
F_32 ( & V_44 ) ;
}
return type ;
}
static int
F_136 ( const struct V_4 * V_4 , const long V_138 , int V_163 )
{
int V_132 = 0 ;
struct V_17 * V_17 = V_4 -> V_164 ;
if ( V_163 & V_148 )
return 0 ;
if ( ( V_138 == V_14 ) &&
( F_137 ( & F_138 ( V_4 ) -> V_165 ) > 0 ) )
return - V_121 ;
if ( ( V_138 == V_56 ) && ( ( F_139 ( V_4 ) > 1 ) ||
( F_137 ( & V_17 -> V_166 ) > 1 ) ) )
V_132 = - V_121 ;
return V_132 ;
}
static int
F_140 ( struct V_1 * V_2 , long V_138 , struct V_8 * * V_167 , void * * V_82 )
{
struct V_8 * V_9 , * V_168 = NULL , * V_146 ;
struct V_4 * V_4 = V_2 -> V_3 . V_4 ;
struct V_17 * V_17 = V_4 -> V_164 ;
struct V_16 * V_18 ;
bool V_169 = ( * V_167 ) -> V_10 & V_149 ;
int error ;
F_100 ( V_44 ) ;
V_146 = * V_167 ;
F_141 ( V_17 , V_146 ) ;
V_18 = F_5 ( V_17 , V_138 ) ;
if ( ! V_18 )
return - V_59 ;
if ( V_169 && ! F_142 ( V_17 ) )
return - V_121 ;
if ( V_169 && V_138 == V_56 ) {
F_143 ( V_17 ) ;
F_38 ( 1 ) ;
return - V_58 ;
}
F_101 ( & V_95 ) ;
F_60 ( & V_18 -> V_23 ) ;
F_120 ( V_17 , & V_44 ) ;
error = F_136 ( V_4 , V_138 , V_146 -> V_10 ) ;
if ( error )
goto V_20;
error = - V_121 ;
F_14 (fl, &ctx->flc_lease, fl_list) {
if ( V_9 -> V_46 == V_2 &&
V_9 -> V_30 == V_146 -> V_30 ) {
V_168 = V_9 ;
continue;
}
if ( V_138 == V_56 )
goto V_20;
if ( V_9 -> V_10 & V_11 )
goto V_20;
}
if ( V_168 != NULL ) {
V_146 = V_168 ;
error = V_146 -> V_42 -> V_170 ( V_146 , V_138 , & V_44 ) ;
if ( error )
goto V_20;
goto V_171;
}
error = - V_58 ;
if ( ! V_172 )
goto V_20;
F_82 ( V_146 , & V_18 -> V_26 ) ;
F_144 () ;
error = F_136 ( V_4 , V_138 , V_146 -> V_10 ) ;
if ( error ) {
F_85 ( V_146 ) ;
goto V_20;
}
V_171:
if ( V_146 -> V_42 -> V_173 )
V_146 -> V_42 -> V_173 ( V_146 , V_82 ) ;
V_20:
F_63 ( & V_18 -> V_23 ) ;
F_102 ( & V_95 ) ;
F_32 ( & V_44 ) ;
if ( V_169 )
F_143 ( V_17 ) ;
if ( ! error && ! V_168 )
* V_167 = NULL ;
return error ;
}
static int F_145 ( struct V_1 * V_2 , void * V_174 )
{
int error = - V_121 ;
struct V_8 * V_9 , * V_175 = NULL ;
struct V_17 * V_17 = F_93 ( V_2 ) ;
struct V_16 * V_18 ;
F_100 ( V_44 ) ;
V_18 = F_6 ( & V_17 -> V_19 ) ;
if ( ! V_18 ) {
F_146 ( V_17 , NULL ) ;
return error ;
}
F_101 ( & V_95 ) ;
F_60 ( & V_18 -> V_23 ) ;
F_14 (fl, &ctx->flc_lease, fl_list) {
if ( V_9 -> V_46 == V_2 &&
V_9 -> V_30 == V_174 ) {
V_175 = V_9 ;
break;
}
}
F_146 ( V_17 , V_175 ) ;
if ( V_175 )
error = V_9 -> V_42 -> V_170 ( V_175 , V_13 , & V_44 ) ;
F_63 ( & V_18 -> V_23 ) ;
F_102 ( & V_95 ) ;
F_32 ( & V_44 ) ;
return error ;
}
int F_147 ( struct V_1 * V_2 , long V_138 , struct V_8 * * V_167 ,
void * * V_82 )
{
struct V_17 * V_17 = F_93 ( V_2 ) ;
int error ;
if ( ( ! F_148 ( F_149 () , V_17 -> V_176 ) ) && ! F_150 ( V_177 ) )
return - V_178 ;
if ( ! F_151 ( V_17 -> V_179 ) )
return - V_58 ;
error = F_152 ( V_2 , V_138 ) ;
if ( error )
return error ;
switch ( V_138 ) {
case V_13 :
return F_145 ( V_2 , * V_82 ) ;
case V_14 :
case V_56 :
if ( ! ( * V_167 ) -> V_42 -> V_157 ) {
F_38 ( 1 ) ;
return - V_131 ;
}
return F_140 ( V_2 , V_138 , V_167 , V_82 ) ;
default:
return - V_58 ;
}
}
int
F_153 ( struct V_1 * V_2 , long V_138 , struct V_8 * * V_146 , void * * V_82 )
{
if ( V_2 -> V_180 -> V_181 && F_1 ( V_2 ) )
return V_2 -> V_180 -> V_181 ( V_2 , V_138 , V_146 , V_82 ) ;
else
return F_147 ( V_2 , V_138 , V_146 , V_82 ) ;
}
static int F_154 ( unsigned int V_182 , struct V_1 * V_2 , long V_138 )
{
struct V_8 * V_9 ;
struct V_83 * V_45 ;
int error ;
V_9 = F_54 ( V_2 , V_138 ) ;
if ( F_126 ( V_9 ) )
return F_127 ( V_9 ) ;
V_45 = F_155 () ;
if ( ! V_45 ) {
F_28 ( V_9 ) ;
return - V_59 ;
}
V_45 -> V_85 = V_182 ;
error = F_153 ( V_2 , V_138 , & V_9 , ( void * * ) & V_45 ) ;
if ( V_9 )
F_28 ( V_9 ) ;
if ( V_45 )
F_156 ( V_45 ) ;
return error ;
}
int F_157 ( unsigned int V_182 , struct V_1 * V_2 , long V_138 )
{
if ( V_138 == V_13 )
return F_153 ( V_2 , V_13 , NULL , ( void * * ) & V_2 ) ;
return F_154 ( V_182 , V_2 , V_138 ) ;
}
static int F_158 ( struct V_17 * V_17 , struct V_8 * V_9 )
{
int error ;
F_108 () ;
for (; ; ) {
error = F_99 ( V_17 , V_9 ) ;
if ( error != V_123 )
break;
error = F_109 ( V_9 -> V_38 , ! V_9 -> V_103 ) ;
if ( ! error )
continue;
F_74 ( V_9 ) ;
break;
}
return error ;
}
int F_159 ( struct V_17 * V_17 , struct V_8 * V_9 )
{
int V_183 = 0 ;
switch ( V_9 -> V_10 & ( V_75 | V_62 ) ) {
case V_75 :
V_183 = F_107 ( V_17 , V_9 ) ;
break;
case V_62 :
V_183 = F_158 ( V_17 , V_9 ) ;
break;
default:
F_160 () ;
}
return V_183 ;
}
int F_161 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
if ( V_2 -> V_180 -> V_96 && F_1 ( V_2 ) )
return V_2 -> V_180 -> V_96 ( V_2 , V_184 , V_9 ) ;
F_92 ( V_2 , V_9 ) ;
return 0 ;
}
static int F_162 ( struct V_77 * V_77 , struct V_8 * V_9 )
{
V_77 -> V_185 = F_78 ( V_9 ) ? - 1 : V_9 -> V_31 ;
#if V_186 == 32
if ( V_9 -> V_47 > V_187 )
return - V_72 ;
if ( V_9 -> V_48 != V_63 && V_9 -> V_48 > V_187 )
return - V_72 ;
#endif
V_77 -> V_71 = V_9 -> V_47 ;
V_77 -> V_73 = V_9 -> V_48 == V_63 ? 0 :
V_9 -> V_48 - V_9 -> V_47 + 1 ;
V_77 -> V_66 = 0 ;
V_77 -> V_76 = V_9 -> V_15 ;
return 0 ;
}
static void F_163 ( struct V_64 * V_77 , struct V_8 * V_9 )
{
V_77 -> V_185 = F_78 ( V_9 ) ? - 1 : V_9 -> V_31 ;
V_77 -> V_71 = V_9 -> V_47 ;
V_77 -> V_73 = V_9 -> V_48 == V_63 ? 0 :
V_9 -> V_48 - V_9 -> V_47 + 1 ;
V_77 -> V_66 = 0 ;
V_77 -> V_76 = V_9 -> V_15 ;
}
int F_164 ( struct V_1 * V_2 , unsigned int V_51 , struct V_77 T_2 * V_65 )
{
struct V_8 V_8 ;
struct V_77 V_77 ;
int error ;
error = - V_188 ;
if ( F_165 ( & V_77 , V_65 , sizeof( V_77 ) ) )
goto V_20;
error = - V_58 ;
if ( ( V_77 . V_76 != V_14 ) && ( V_77 . V_76 != V_56 ) )
goto V_20;
error = F_46 ( V_2 , & V_8 , & V_77 ) ;
if ( error )
goto V_20;
if ( V_51 == V_189 ) {
error = - V_58 ;
if ( V_77 . V_185 != 0 )
goto V_20;
V_51 = V_184 ;
V_8 . V_10 |= V_190 ;
V_8 . V_30 = V_2 ;
}
error = F_161 ( V_2 , & V_8 ) ;
if ( error )
goto V_20;
V_77 . V_76 = V_8 . V_15 ;
if ( V_8 . V_15 != V_13 ) {
error = F_162 ( & V_77 , & V_8 ) ;
if ( error )
goto V_191;
}
error = - V_188 ;
if ( ! F_166 ( V_65 , & V_77 , sizeof( V_77 ) ) )
error = 0 ;
V_191:
F_27 ( & V_8 ) ;
V_20:
return error ;
}
int F_167 ( struct V_1 * V_2 , unsigned int V_51 , struct V_8 * V_9 , struct V_8 * V_192 )
{
if ( V_2 -> V_180 -> V_96 && F_1 ( V_2 ) )
return V_2 -> V_180 -> V_96 ( V_2 , V_51 , V_9 ) ;
else
return F_106 ( V_2 , V_9 , V_192 ) ;
}
static int F_168 ( struct V_1 * V_2 , unsigned int V_51 ,
struct V_8 * V_9 )
{
int error ;
error = F_152 ( V_2 , V_9 -> V_15 ) ;
if ( error )
return error ;
for (; ; ) {
error = F_167 ( V_2 , V_51 , V_9 , NULL ) ;
if ( error != V_123 )
break;
error = F_109 ( V_9 -> V_38 , ! V_9 -> V_103 ) ;
if ( ! error )
continue;
F_74 ( V_9 ) ;
break;
}
return error ;
}
static int
F_169 ( struct V_8 * V_9 )
{
switch ( V_9 -> V_15 ) {
case V_14 :
if ( ! ( V_9 -> V_46 -> V_193 & V_194 ) )
return - V_195 ;
break;
case V_56 :
if ( ! ( V_9 -> V_46 -> V_193 & V_196 ) )
return - V_195 ;
}
return 0 ;
}
int F_170 ( unsigned int V_182 , struct V_1 * V_2 , unsigned int V_51 ,
struct V_77 T_2 * V_65 )
{
struct V_8 * V_8 = F_25 () ;
struct V_77 V_77 ;
struct V_17 * V_17 ;
struct V_1 * V_197 ;
int error ;
if ( V_8 == NULL )
return - V_131 ;
V_17 = F_93 ( V_2 ) ;
error = - V_188 ;
if ( F_165 ( & V_77 , V_65 , sizeof( V_77 ) ) )
goto V_20;
if ( F_171 ( V_17 ) && F_172 ( V_2 -> V_198 ) ) {
error = - V_121 ;
goto V_20;
}
error = F_46 ( V_2 , V_8 , & V_77 ) ;
if ( error )
goto V_20;
error = F_169 ( V_8 ) ;
if ( error )
goto V_20;
switch ( V_51 ) {
case V_199 :
error = - V_58 ;
if ( V_77 . V_185 != 0 )
goto V_20;
V_51 = V_200 ;
V_8 -> V_10 |= V_190 ;
V_8 -> V_30 = V_2 ;
break;
case V_201 :
error = - V_58 ;
if ( V_77 . V_185 != 0 )
goto V_20;
V_51 = V_202 ;
V_8 -> V_10 |= V_190 ;
V_8 -> V_30 = V_2 ;
case V_202 :
V_8 -> V_10 |= V_122 ;
}
error = F_168 ( V_2 , V_51 , V_8 ) ;
if ( ! error && V_8 -> V_15 != V_13 &&
! ( V_8 -> V_10 & V_190 ) ) {
F_60 ( & V_60 -> V_74 -> V_8 ) ;
V_197 = F_173 ( V_182 ) ;
F_63 ( & V_60 -> V_74 -> V_8 ) ;
if ( V_197 != V_2 ) {
V_8 -> V_15 = V_13 ;
error = F_168 ( V_2 , V_51 , V_8 ) ;
F_38 ( error ) ;
error = - V_195 ;
}
}
V_20:
F_174 ( V_17 , V_8 , error ) ;
F_28 ( V_8 ) ;
return error ;
}
int F_175 ( struct V_1 * V_2 , unsigned int V_51 , struct V_64 T_2 * V_65 )
{
struct V_8 V_8 ;
struct V_64 V_77 ;
int error ;
error = - V_188 ;
if ( F_165 ( & V_77 , V_65 , sizeof( V_77 ) ) )
goto V_20;
error = - V_58 ;
if ( ( V_77 . V_76 != V_14 ) && ( V_77 . V_76 != V_56 ) )
goto V_20;
error = F_43 ( V_2 , & V_8 , & V_77 ) ;
if ( error )
goto V_20;
if ( V_51 == V_189 ) {
error = - V_58 ;
if ( V_77 . V_185 != 0 )
goto V_20;
V_51 = V_203 ;
V_8 . V_10 |= V_190 ;
V_8 . V_30 = V_2 ;
}
error = F_161 ( V_2 , & V_8 ) ;
if ( error )
goto V_20;
V_77 . V_76 = V_8 . V_15 ;
if ( V_8 . V_15 != V_13 )
F_163 ( & V_77 , & V_8 ) ;
error = - V_188 ;
if ( ! F_166 ( V_65 , & V_77 , sizeof( V_77 ) ) )
error = 0 ;
F_27 ( & V_8 ) ;
V_20:
return error ;
}
int F_176 ( unsigned int V_182 , struct V_1 * V_2 , unsigned int V_51 ,
struct V_64 T_2 * V_65 )
{
struct V_8 * V_8 = F_25 () ;
struct V_64 V_77 ;
struct V_17 * V_17 ;
struct V_1 * V_197 ;
int error ;
if ( V_8 == NULL )
return - V_131 ;
error = - V_188 ;
if ( F_165 ( & V_77 , V_65 , sizeof( V_77 ) ) )
goto V_20;
V_17 = F_93 ( V_2 ) ;
if ( F_171 ( V_17 ) && F_172 ( V_2 -> V_198 ) ) {
error = - V_121 ;
goto V_20;
}
error = F_43 ( V_2 , V_8 , & V_77 ) ;
if ( error )
goto V_20;
error = F_169 ( V_8 ) ;
if ( error )
goto V_20;
switch ( V_51 ) {
case V_199 :
error = - V_58 ;
if ( V_77 . V_185 != 0 )
goto V_20;
V_51 = V_204 ;
V_8 -> V_10 |= V_190 ;
V_8 -> V_30 = V_2 ;
break;
case V_201 :
error = - V_58 ;
if ( V_77 . V_185 != 0 )
goto V_20;
V_51 = V_205 ;
V_8 -> V_10 |= V_190 ;
V_8 -> V_30 = V_2 ;
case V_205 :
V_8 -> V_10 |= V_122 ;
}
error = F_168 ( V_2 , V_51 , V_8 ) ;
if ( ! error && V_8 -> V_15 != V_13 &&
! ( V_8 -> V_10 & V_190 ) ) {
F_60 ( & V_60 -> V_74 -> V_8 ) ;
V_197 = F_173 ( V_182 ) ;
F_63 ( & V_60 -> V_74 -> V_8 ) ;
if ( V_197 != V_2 ) {
V_8 -> V_15 = V_13 ;
error = F_168 ( V_2 , V_51 , V_8 ) ;
F_38 ( error ) ;
error = - V_195 ;
}
}
V_20:
F_28 ( V_8 ) ;
return error ;
}
void F_177 ( struct V_1 * V_2 , T_3 V_174 )
{
int error ;
struct V_17 * V_17 = F_93 ( V_2 ) ;
struct V_8 V_96 ;
struct V_16 * V_18 ;
V_18 = F_6 ( & V_17 -> V_19 ) ;
if ( ! V_18 || F_18 ( & V_18 -> V_25 ) )
return;
V_96 . V_15 = V_13 ;
V_96 . V_10 = V_75 | V_206 ;
V_96 . V_47 = 0 ;
V_96 . V_48 = V_63 ;
V_96 . V_30 = V_174 ;
V_96 . V_31 = V_60 -> V_61 ;
V_96 . V_46 = V_2 ;
V_96 . V_40 = NULL ;
V_96 . V_42 = NULL ;
error = F_167 ( V_2 , V_200 , & V_96 , NULL ) ;
if ( V_96 . V_40 && V_96 . V_40 -> V_41 )
V_96 . V_40 -> V_41 ( & V_96 ) ;
F_178 ( V_17 , & V_96 , error ) ;
}
static void
F_179 ( struct V_1 * V_2 , struct V_16 * V_207 )
{
struct V_8 V_9 = {
. V_30 = V_2 ,
. V_31 = V_60 -> V_61 ,
. V_46 = V_2 ,
. V_10 = V_62 | V_206 ,
. V_15 = V_13 ,
. V_48 = V_63 ,
} ;
struct V_17 * V_17 = F_93 ( V_2 ) ;
if ( F_18 ( & V_207 -> V_24 ) )
return;
if ( V_2 -> V_180 -> V_77 && F_1 ( V_2 ) )
V_2 -> V_180 -> V_77 ( V_2 , V_202 , & V_9 ) ;
else
F_99 ( V_17 , & V_9 ) ;
if ( V_9 . V_40 && V_9 . V_40 -> V_41 )
V_9 . V_40 -> V_41 ( & V_9 ) ;
}
static void
F_180 ( struct V_1 * V_2 , struct V_16 * V_18 )
{
struct V_8 * V_9 , * V_125 ;
F_100 ( V_44 ) ;
if ( F_18 ( & V_18 -> V_26 ) )
return;
F_101 ( & V_95 ) ;
F_60 ( & V_18 -> V_23 ) ;
F_121 (fl, tmp, &ctx->flc_lease, fl_list)
if ( V_2 == V_9 -> V_46 )
F_114 ( V_9 , V_13 , & V_44 ) ;
F_63 ( & V_18 -> V_23 ) ;
F_102 ( & V_95 ) ;
F_32 ( & V_44 ) ;
}
void F_181 ( struct V_1 * V_2 )
{
struct V_16 * V_18 ;
V_18 = F_6 ( & F_93 ( V_2 ) -> V_19 ) ;
if ( ! V_18 )
return;
F_177 ( V_2 , V_2 ) ;
F_179 ( V_2 , V_18 ) ;
F_180 ( V_2 , V_18 ) ;
}
int
F_182 ( struct V_8 * V_100 )
{
int V_208 = 0 ;
F_60 ( & V_101 ) ;
if ( V_100 -> V_103 )
F_73 ( V_100 ) ;
else
V_208 = - V_118 ;
F_63 ( & V_101 ) ;
return V_208 ;
}
int F_183 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
if ( V_2 -> V_180 -> V_96 && F_1 ( V_2 ) )
return V_2 -> V_180 -> V_96 ( V_2 , V_209 , V_9 ) ;
return 0 ;
}
static void F_184 ( struct V_210 * V_197 , struct V_8 * V_9 ,
T_1 V_211 , char * V_212 )
{
struct V_17 * V_17 = NULL ;
unsigned int V_31 ;
if ( V_9 -> V_107 ) {
struct V_213 * V_214 = F_45 ( V_197 -> V_1 ) -> V_32 -> V_215 ;
V_31 = F_185 ( V_9 -> V_107 , V_214 ) ;
if ( V_31 == 0 )
return;
} else
V_31 = V_9 -> V_31 ;
if ( V_9 -> V_46 != NULL )
V_17 = F_93 ( V_9 -> V_46 ) ;
F_186 ( V_197 , L_7 , V_211 , V_212 ) ;
if ( F_77 ( V_9 ) ) {
if ( V_9 -> V_10 & V_119 )
F_187 ( V_197 , L_8 ) ;
else if ( F_78 ( V_9 ) )
F_187 ( V_197 , L_9 ) ;
else
F_187 ( V_197 , L_10 ) ;
F_186 ( V_197 , L_11 ,
( V_17 == NULL ) ? L_12 :
F_171 ( V_17 ) ? L_13 : L_14 ) ;
} else if ( F_188 ( V_9 ) ) {
if ( V_9 -> V_15 & V_52 ) {
F_187 ( V_197 , L_15 ) ;
} else {
F_187 ( V_197 , L_16 ) ;
}
} else if ( F_189 ( V_9 ) ) {
if ( V_9 -> V_10 & V_149 )
F_187 ( V_197 , L_17 ) ;
else
F_187 ( V_197 , L_18 ) ;
if ( F_3 ( V_9 ) )
F_187 ( V_197 , L_19 ) ;
else if ( V_9 -> V_46 )
F_187 ( V_197 , L_20 ) ;
else
F_187 ( V_197 , L_21 ) ;
} else {
F_187 ( V_197 , L_22 ) ;
}
if ( V_9 -> V_15 & V_52 ) {
F_186 ( V_197 , L_23 ,
( V_9 -> V_15 & V_216 )
? ( V_9 -> V_15 & V_217 ) ? L_24 : L_25
: ( V_9 -> V_15 & V_217 ) ? L_26 : L_27 ) ;
} else {
F_186 ( V_197 , L_23 ,
( F_3 ( V_9 ) )
? ( V_9 -> V_15 == V_13 ) ? L_28 : L_25
: ( V_9 -> V_15 == V_56 ) ? L_26 : L_25 ) ;
}
if ( V_17 ) {
F_186 ( V_197 , L_29 , V_31 ,
F_19 ( V_17 -> V_32 -> V_33 ) ,
F_20 ( V_17 -> V_32 -> V_33 ) , V_17 -> V_34 ) ;
} else {
F_186 ( V_197 , L_30 , V_31 ) ;
}
if ( F_77 ( V_9 ) ) {
if ( V_9 -> V_48 == V_63 )
F_186 ( V_197 , L_31 , V_9 -> V_47 ) ;
else
F_186 ( V_197 , L_32 , V_9 -> V_47 , V_9 -> V_48 ) ;
} else {
F_187 ( V_197 , L_33 ) ;
}
}
static int F_190 ( struct V_210 * V_197 , void * V_218 )
{
struct V_219 * V_220 = V_197 -> V_221 ;
struct V_8 * V_9 , * V_222 ;
struct V_213 * V_214 = F_45 ( V_197 -> V_1 ) -> V_32 -> V_215 ;
V_9 = F_191 ( V_218 , struct V_8 , V_35 ) ;
if ( V_9 -> V_107 && ! F_185 ( V_9 -> V_107 , V_214 ) )
return 0 ;
F_184 ( V_197 , V_9 , V_220 -> V_223 , L_34 ) ;
F_14 (bfl, &fl->fl_block, fl_block)
F_184 ( V_197 , V_222 , V_220 -> V_223 , L_35 ) ;
return 0 ;
}
static void F_192 ( struct V_210 * V_197 ,
struct V_27 * V_224 , int * V_211 ,
struct V_1 * V_2 , struct V_225 * V_74 )
{
struct V_8 * V_9 ;
F_14 (fl, head, fl_list) {
if ( V_2 != V_9 -> V_46 )
continue;
if ( V_9 -> V_30 != V_74 &&
V_9 -> V_30 != V_2 )
continue;
( * V_211 ) ++ ;
F_187 ( V_197 , L_36 ) ;
F_184 ( V_197 , V_9 , * V_211 , L_34 ) ;
}
}
void F_193 ( struct V_210 * V_197 ,
struct V_1 * V_2 , struct V_225 * V_74 )
{
struct V_17 * V_17 = F_93 ( V_2 ) ;
struct V_16 * V_18 ;
int V_211 = 0 ;
V_18 = F_6 ( & V_17 -> V_19 ) ;
if ( ! V_18 )
return;
F_60 ( & V_18 -> V_23 ) ;
F_192 ( V_197 , & V_18 -> V_24 , & V_211 , V_2 , V_74 ) ;
F_192 ( V_197 , & V_18 -> V_25 , & V_211 , V_2 , V_74 ) ;
F_192 ( V_197 , & V_18 -> V_26 , & V_211 , V_2 , V_74 ) ;
F_63 ( & V_18 -> V_23 ) ;
}
static void * F_194 ( struct V_210 * V_197 , T_1 * V_226 )
__acquires( &blocked_lock_lock
static void * F_195 ( struct V_210 * V_197 , void * V_218 , T_1 * V_226 )
{
struct V_219 * V_220 = V_197 -> V_221 ;
++ V_220 -> V_223 ;
return F_196 ( V_218 , & V_94 . V_98 , & V_220 -> V_227 , V_226 ) ;
}
static void F_197 ( struct V_210 * V_197 , void * V_218 )
__releases( &blocked_lock_lock
static int F_198 ( struct V_17 * V_17 , struct V_1 * V_2 )
{
return F_199 ( V_2 , & V_228 ,
sizeof( struct V_219 ) ) ;
}
static int T_4 F_200 ( void )
{
F_201 ( L_37 , 0 , NULL , & V_229 ) ;
return 0 ;
}
static int T_4 F_202 ( void )
{
int V_112 ;
V_21 = F_203 ( L_38 ,
sizeof( struct V_16 ) , 0 , V_230 , NULL ) ;
V_39 = F_203 ( L_39 ,
sizeof( struct V_8 ) , 0 , V_230 , NULL ) ;
F_204 (i) {
struct V_92 * V_93 = F_65 ( & V_94 , V_112 ) ;
F_8 ( & V_93 -> V_96 ) ;
F_205 ( & V_93 -> V_98 ) ;
}
return 0 ;
}
