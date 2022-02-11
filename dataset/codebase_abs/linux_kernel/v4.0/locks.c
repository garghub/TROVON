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
F_3 ( struct V_10 * V_10 )
{
struct V_9 * V_11 ;
if ( F_4 ( V_10 -> V_12 ) )
goto V_13;
V_11 = F_5 ( V_14 , V_15 ) ;
if ( ! V_11 )
goto V_13;
F_6 ( & V_11 -> V_16 ) ;
F_7 ( & V_11 -> V_17 ) ;
F_7 ( & V_11 -> V_18 ) ;
F_7 ( & V_11 -> V_19 ) ;
F_8 ( & V_10 -> V_20 ) ;
if ( F_4 ( ! V_10 -> V_12 ) ) {
V_10 -> V_12 = V_11 ;
V_11 = NULL ;
}
F_9 ( & V_10 -> V_20 ) ;
if ( V_11 )
F_10 ( V_14 , V_11 ) ;
V_13:
return V_10 -> V_12 ;
}
void
F_11 ( struct V_9 * V_21 )
{
if ( V_21 ) {
F_12 ( ! F_13 ( & V_21 -> V_17 ) ) ;
F_12 ( ! F_13 ( & V_21 -> V_18 ) ) ;
F_12 ( ! F_13 ( & V_21 -> V_19 ) ) ;
F_10 ( V_14 , V_21 ) ;
}
}
static void F_14 ( struct V_1 * V_2 )
{
F_15 ( & V_2 -> V_22 ) ;
F_7 ( & V_2 -> V_23 ) ;
F_7 ( & V_2 -> V_24 ) ;
F_16 ( & V_2 -> V_25 ) ;
}
struct V_1 * F_17 ( void )
{
struct V_1 * V_2 = F_18 ( V_26 , V_15 ) ;
if ( V_2 )
F_14 ( V_2 ) ;
return V_2 ;
}
void F_19 ( struct V_1 * V_2 )
{
if ( V_2 -> V_27 ) {
if ( V_2 -> V_27 -> V_28 )
V_2 -> V_27 -> V_28 ( V_2 ) ;
V_2 -> V_27 = NULL ;
}
if ( V_2 -> V_29 ) {
if ( V_2 -> V_29 -> V_30 )
V_2 -> V_29 -> V_30 ( V_2 ) ;
V_2 -> V_29 = NULL ;
}
}
void F_20 ( struct V_1 * V_2 )
{
F_21 ( F_22 ( & V_2 -> V_25 ) ) ;
F_21 ( ! F_13 ( & V_2 -> V_23 ) ) ;
F_21 ( ! F_13 ( & V_2 -> V_24 ) ) ;
F_21 ( ! F_23 ( & V_2 -> V_22 ) ) ;
F_19 ( V_2 ) ;
F_10 ( V_26 , V_2 ) ;
}
static void
F_24 ( struct V_31 * V_32 )
{
struct V_1 * V_2 ;
while ( ! F_13 ( V_32 ) ) {
V_2 = F_25 ( V_32 , struct V_1 , V_23 ) ;
F_26 ( & V_2 -> V_23 ) ;
F_20 ( V_2 ) ;
}
}
void F_27 ( struct V_1 * V_2 )
{
memset ( V_2 , 0 , sizeof( struct V_1 ) ) ;
F_14 ( V_2 ) ;
}
void F_28 ( struct V_1 * V_11 , struct V_1 * V_2 )
{
V_11 -> V_33 = V_2 -> V_33 ;
V_11 -> V_34 = V_2 -> V_34 ;
V_11 -> V_35 = NULL ;
V_11 -> V_3 = V_2 -> V_3 ;
V_11 -> V_8 = V_2 -> V_8 ;
V_11 -> V_36 = V_2 -> V_36 ;
V_11 -> V_37 = V_2 -> V_37 ;
V_11 -> V_29 = V_2 -> V_29 ;
V_11 -> V_27 = NULL ;
if ( V_2 -> V_29 ) {
if ( V_2 -> V_29 -> V_38 )
V_2 -> V_29 -> V_38 ( V_11 , V_2 ) ;
}
}
void F_29 ( struct V_1 * V_11 , struct V_1 * V_2 )
{
F_12 ( V_11 -> V_27 ) ;
F_28 ( V_11 , V_2 ) ;
V_11 -> V_35 = V_2 -> V_35 ;
V_11 -> V_27 = V_2 -> V_27 ;
if ( V_2 -> V_27 ) {
if ( V_2 -> V_27 -> V_39 )
V_2 -> V_27 -> V_39 ( V_11 , V_2 ) ;
}
}
static inline int F_30 ( int V_40 ) {
if ( V_40 & V_41 )
return V_40 & ( V_41 | V_42 ) ;
switch ( V_40 ) {
case V_43 :
return V_7 ;
case V_44 :
return V_45 ;
case V_46 :
return V_6 ;
}
return - V_47 ;
}
static struct V_1 *
F_31 ( struct V_48 * V_49 , unsigned int V_40 )
{
struct V_1 * V_2 ;
int type = F_30 ( V_40 ) ;
if ( type < 0 )
return F_32 ( type ) ;
V_2 = F_17 () ;
if ( V_2 == NULL )
return F_32 ( - V_50 ) ;
V_2 -> V_35 = V_49 ;
V_2 -> V_33 = V_49 ;
V_2 -> V_34 = V_51 -> V_52 ;
V_2 -> V_3 = V_53 ;
V_2 -> V_8 = type ;
V_2 -> V_37 = V_54 ;
return V_2 ;
}
static int F_33 ( struct V_1 * V_2 , long type )
{
switch ( type ) {
case V_7 :
case V_45 :
case V_6 :
V_2 -> V_8 = type ;
break;
default:
return - V_47 ;
}
return 0 ;
}
static int F_34 ( struct V_48 * V_49 , struct V_1 * V_2 ,
struct V_55 * V_56 )
{
switch ( V_56 -> V_57 ) {
case V_58 :
V_2 -> V_36 = 0 ;
break;
case V_59 :
V_2 -> V_36 = V_49 -> V_60 ;
break;
case V_61 :
V_2 -> V_36 = F_35 ( F_36 ( V_49 ) ) ;
break;
default:
return - V_47 ;
}
if ( V_56 -> V_62 > V_54 - V_2 -> V_36 )
return - V_63 ;
V_2 -> V_36 += V_56 -> V_62 ;
if ( V_2 -> V_36 < 0 )
return - V_47 ;
if ( V_56 -> V_64 > 0 ) {
if ( V_56 -> V_64 - 1 > V_54 - V_2 -> V_36 )
return - V_63 ;
V_2 -> V_37 = V_2 -> V_36 + V_56 -> V_64 - 1 ;
} else if ( V_56 -> V_64 < 0 ) {
if ( V_2 -> V_36 + V_56 -> V_64 < 0 )
return - V_47 ;
V_2 -> V_37 = V_2 -> V_36 - 1 ;
V_2 -> V_36 += V_56 -> V_64 ;
} else
V_2 -> V_37 = V_54 ;
V_2 -> V_33 = V_51 -> V_65 ;
V_2 -> V_34 = V_51 -> V_52 ;
V_2 -> V_35 = V_49 ;
V_2 -> V_3 = V_66 ;
V_2 -> V_27 = NULL ;
V_2 -> V_29 = NULL ;
return F_33 ( V_2 , V_56 -> V_67 ) ;
}
static int F_37 ( struct V_48 * V_49 , struct V_1 * V_2 ,
struct V_68 * V_56 )
{
struct V_55 V_69 = {
. V_67 = V_56 -> V_67 ,
. V_57 = V_56 -> V_57 ,
. V_62 = V_56 -> V_62 ,
. V_64 = V_56 -> V_64 ,
} ;
return F_34 ( V_49 , V_2 , & V_69 ) ;
}
static bool
F_38 ( struct V_1 * V_2 )
{
F_39 ( & V_2 -> V_70 , V_71 , V_72 ) ;
return false ;
}
static void
F_40 ( struct V_1 * V_2 , void * * V_73 )
{
struct V_48 * V_49 = V_2 -> V_35 ;
struct V_74 * V_75 = * V_73 ;
if ( ! F_41 ( V_75 -> V_76 , V_49 , & V_2 -> V_70 , V_75 ) )
* V_73 = NULL ;
F_42 ( V_49 , F_43 ( V_51 ) , V_77 , 0 ) ;
}
static int F_44 ( struct V_48 * V_49 , long type , struct V_1 * V_2 )
{
if ( F_33 ( V_2 , type ) != 0 )
return - V_47 ;
V_2 -> V_33 = V_49 ;
V_2 -> V_34 = V_51 -> V_52 ;
V_2 -> V_35 = V_49 ;
V_2 -> V_3 = V_78 ;
V_2 -> V_36 = 0 ;
V_2 -> V_37 = V_54 ;
V_2 -> V_27 = NULL ;
V_2 -> V_29 = & V_79 ;
return 0 ;
}
static struct V_1 * F_45 ( struct V_48 * V_49 , long type )
{
struct V_1 * V_2 = F_17 () ;
int error = - V_50 ;
if ( V_2 == NULL )
return F_32 ( error ) ;
error = F_44 ( V_49 , type , V_2 ) ;
if ( error ) {
F_20 ( V_2 ) ;
return F_32 ( error ) ;
}
return V_2 ;
}
static inline int F_46 ( struct V_1 * V_80 , struct V_1 * V_81 )
{
return ( ( V_80 -> V_37 >= V_81 -> V_36 ) &&
( V_81 -> V_37 >= V_80 -> V_36 ) ) ;
}
static int F_47 ( struct V_1 * V_80 , struct V_1 * V_81 )
{
if ( V_80 -> V_29 && V_80 -> V_29 -> V_82 )
return V_81 -> V_29 == V_80 -> V_29 &&
V_80 -> V_29 -> V_82 ( V_80 , V_81 ) ;
return V_80 -> V_33 == V_81 -> V_33 ;
}
static void F_48 ( struct V_1 * V_2 )
{
F_49 ( & V_83 ) ;
V_2 -> V_84 = F_50 () ;
F_51 ( & V_2 -> V_22 , F_52 ( & V_85 ) ) ;
F_53 ( & V_83 ) ;
}
static void F_54 ( struct V_1 * V_2 )
{
if ( F_23 ( & V_2 -> V_22 ) )
return;
F_55 ( & V_83 , V_2 -> V_84 ) ;
F_56 ( & V_2 -> V_22 ) ;
F_57 ( & V_83 , V_2 -> V_84 ) ;
}
static unsigned long
F_58 ( struct V_1 * V_2 )
{
if ( V_2 -> V_29 && V_2 -> V_29 -> V_86 )
return V_2 -> V_29 -> V_86 ( V_2 ) ;
return ( unsigned long ) V_2 -> V_33 ;
}
static void F_59 ( struct V_1 * V_87 )
{
F_60 ( V_88 , & V_87 -> V_22 , F_58 ( V_87 ) ) ;
}
static void F_61 ( struct V_1 * V_87 )
{
F_62 ( & V_87 -> V_22 ) ;
}
static void F_63 ( struct V_1 * V_87 )
{
F_61 ( V_87 ) ;
F_26 ( & V_87 -> V_24 ) ;
V_87 -> V_89 = NULL ;
}
static void F_64 ( struct V_1 * V_87 )
{
F_8 ( & V_90 ) ;
F_63 ( V_87 ) ;
F_9 ( & V_90 ) ;
}
static void F_65 ( struct V_1 * V_91 ,
struct V_1 * V_87 )
{
F_21 ( ! F_13 ( & V_87 -> V_24 ) ) ;
V_87 -> V_89 = V_91 ;
F_66 ( & V_87 -> V_24 , & V_91 -> V_24 ) ;
if ( F_67 ( V_91 ) && ! F_68 ( V_91 ) )
F_59 ( V_87 ) ;
}
static void F_69 ( struct V_1 * V_91 ,
struct V_1 * V_87 )
{
F_8 ( & V_90 ) ;
F_65 ( V_91 , V_87 ) ;
F_9 ( & V_90 ) ;
}
static void F_70 ( struct V_1 * V_91 )
{
if ( F_13 ( & V_91 -> V_24 ) )
return;
F_8 ( & V_90 ) ;
while ( ! F_13 ( & V_91 -> V_24 ) ) {
struct V_1 * V_87 ;
V_87 = F_25 ( & V_91 -> V_24 ,
struct V_1 , V_24 ) ;
F_63 ( V_87 ) ;
if ( V_87 -> V_29 && V_87 -> V_29 -> V_92 )
V_87 -> V_29 -> V_92 ( V_87 ) ;
else
F_71 ( & V_87 -> V_25 ) ;
}
F_9 ( & V_90 ) ;
}
static void
F_72 ( struct V_1 * V_2 , struct V_31 * V_93 )
{
V_2 -> V_94 = F_73 ( F_74 ( V_51 ) ) ;
F_66 ( & V_2 -> V_23 , V_93 ) ;
F_48 ( V_2 ) ;
}
static void
F_75 ( struct V_1 * V_2 )
{
F_54 ( V_2 ) ;
F_26 ( & V_2 -> V_23 ) ;
if ( V_2 -> V_94 ) {
F_76 ( V_2 -> V_94 ) ;
V_2 -> V_94 = NULL ;
}
F_70 ( V_2 ) ;
}
static void
F_77 ( struct V_1 * V_2 , struct V_31 * V_32 )
{
F_75 ( V_2 ) ;
if ( V_32 )
F_78 ( & V_2 -> V_23 , V_32 ) ;
else
F_20 ( V_2 ) ;
}
static int F_79 ( struct V_1 * V_95 , struct V_1 * V_96 )
{
if ( V_96 -> V_8 == V_45 )
return 1 ;
if ( V_95 -> V_8 == V_45 )
return 1 ;
return 0 ;
}
static int F_80 ( struct V_1 * V_95 , struct V_1 * V_96 )
{
if ( ! F_67 ( V_96 ) || F_47 ( V_95 , V_96 ) )
return ( 0 ) ;
if ( ! F_46 ( V_95 , V_96 ) )
return 0 ;
return ( F_79 ( V_95 , V_96 ) ) ;
}
static int F_81 ( struct V_1 * V_95 , struct V_1 * V_96 )
{
if ( ! F_82 ( V_96 ) || ( V_95 -> V_35 == V_96 -> V_35 ) )
return ( 0 ) ;
if ( ( V_95 -> V_8 & V_41 ) || ( V_96 -> V_8 & V_41 ) )
return 0 ;
return ( F_79 ( V_95 , V_96 ) ) ;
}
void
F_83 ( struct V_48 * V_49 , struct V_1 * V_2 )
{
struct V_1 * V_97 ;
struct V_9 * V_21 ;
struct V_10 * V_10 = F_36 ( V_49 ) ;
V_21 = V_10 -> V_12 ;
if ( ! V_21 || F_84 ( & V_21 -> V_18 ) ) {
V_2 -> V_8 = V_6 ;
return;
}
F_8 ( & V_21 -> V_16 ) ;
F_85 (cfl, &ctx->flc_posix, fl_list) {
if ( F_80 ( V_2 , V_97 ) ) {
F_28 ( V_2 , V_97 ) ;
if ( V_97 -> V_94 )
V_2 -> V_34 = F_86 ( V_97 -> V_94 ) ;
goto V_13;
}
}
V_2 -> V_8 = V_6 ;
V_13:
F_9 ( & V_21 -> V_16 ) ;
return;
}
static struct V_1 * F_87 ( struct V_1 * V_98 )
{
struct V_1 * V_2 ;
F_88 (blocked_hash, fl, fl_link, posix_owner_key(block_fl)) {
if ( F_47 ( V_2 , V_98 ) )
return V_2 -> V_89 ;
}
return NULL ;
}
static int F_89 ( struct V_1 * V_95 ,
struct V_1 * V_98 )
{
int V_99 = 0 ;
if ( F_68 ( V_95 ) )
return 0 ;
while ( ( V_98 = F_87 ( V_98 ) ) ) {
if ( V_99 ++ > V_100 )
return 0 ;
if ( F_47 ( V_95 , V_98 ) )
return 1 ;
}
return 0 ;
}
static int F_90 ( struct V_48 * V_49 , struct V_1 * V_101 )
{
struct V_1 * V_102 = NULL ;
struct V_1 * V_2 ;
struct V_9 * V_21 ;
struct V_10 * V_10 = F_36 ( V_49 ) ;
int error = 0 ;
bool V_103 = false ;
F_91 ( V_32 ) ;
V_21 = F_3 ( V_10 ) ;
if ( ! V_21 )
return - V_50 ;
if ( ! ( V_101 -> V_3 & V_104 ) && ( V_101 -> V_8 != V_6 ) ) {
V_102 = F_17 () ;
if ( ! V_102 )
return - V_50 ;
}
F_8 ( & V_21 -> V_16 ) ;
if ( V_101 -> V_3 & V_104 )
goto V_105;
F_85 (fl, &ctx->flc_flock, fl_list) {
if ( V_49 != V_2 -> V_35 )
continue;
if ( V_101 -> V_8 == V_2 -> V_8 )
goto V_13;
V_103 = true ;
F_77 ( V_2 , & V_32 ) ;
break;
}
if ( V_101 -> V_8 == V_6 ) {
if ( ( V_101 -> V_3 & V_106 ) && ! V_103 )
error = - V_107 ;
goto V_13;
}
V_105:
F_85 (fl, &ctx->flc_flock, fl_list) {
if ( ! F_81 ( V_101 , V_2 ) )
continue;
error = - V_108 ;
if ( ! ( V_101 -> V_3 & V_109 ) )
goto V_13;
error = V_110 ;
F_69 ( V_2 , V_101 ) ;
goto V_13;
}
if ( V_101 -> V_3 & V_104 )
goto V_13;
F_29 ( V_102 , V_101 ) ;
F_72 ( V_102 , & V_21 -> V_17 ) ;
V_102 = NULL ;
error = 0 ;
V_13:
F_9 ( & V_21 -> V_16 ) ;
if ( V_102 )
F_20 ( V_102 ) ;
F_24 ( & V_32 ) ;
return error ;
}
static int F_92 ( struct V_10 * V_10 , struct V_1 * V_101 , struct V_1 * V_111 )
{
struct V_1 * V_2 , * V_112 ;
struct V_1 * V_102 = NULL ;
struct V_1 * V_113 = NULL ;
struct V_1 * V_114 = NULL ;
struct V_1 * V_115 = NULL ;
struct V_9 * V_21 ;
int error ;
bool V_116 = false ;
F_91 ( V_32 ) ;
V_21 = F_3 ( V_10 ) ;
if ( ! V_21 )
return - V_50 ;
if ( ! ( V_101 -> V_3 & V_104 ) &&
( V_101 -> V_8 != V_6 ||
V_101 -> V_36 != 0 || V_101 -> V_37 != V_54 ) ) {
V_102 = F_17 () ;
V_113 = F_17 () ;
}
F_8 ( & V_21 -> V_16 ) ;
if ( V_101 -> V_8 != V_6 ) {
F_85 (fl, &ctx->flc_posix, fl_list) {
if ( ! F_67 ( V_2 ) )
continue;
if ( ! F_80 ( V_101 , V_2 ) )
continue;
if ( V_111 )
F_28 ( V_111 , V_2 ) ;
error = - V_108 ;
if ( ! ( V_101 -> V_3 & V_109 ) )
goto V_13;
error = - V_117 ;
F_8 ( & V_90 ) ;
if ( F_4 ( ! F_89 ( V_101 , V_2 ) ) ) {
error = V_110 ;
F_65 ( V_2 , V_101 ) ;
}
F_9 ( & V_90 ) ;
goto V_13;
}
}
error = 0 ;
if ( V_101 -> V_3 & V_104 )
goto V_13;
F_85 (fl, &ctx->flc_posix, fl_list) {
if ( F_47 ( V_101 , V_2 ) )
break;
}
F_93 (fl, tmp, &ctx->flc_posix, fl_list) {
if ( ! F_47 ( V_101 , V_2 ) )
break;
if ( V_101 -> V_8 == V_2 -> V_8 ) {
if ( V_2 -> V_37 < V_101 -> V_36 - 1 )
continue;
if ( V_2 -> V_36 - 1 > V_101 -> V_37 )
break;
if ( V_2 -> V_36 > V_101 -> V_36 )
V_2 -> V_36 = V_101 -> V_36 ;
else
V_101 -> V_36 = V_2 -> V_36 ;
if ( V_2 -> V_37 < V_101 -> V_37 )
V_2 -> V_37 = V_101 -> V_37 ;
else
V_101 -> V_37 = V_2 -> V_37 ;
if ( V_116 ) {
F_77 ( V_2 , & V_32 ) ;
continue;
}
V_101 = V_2 ;
V_116 = true ;
} else {
if ( V_2 -> V_37 < V_101 -> V_36 )
continue;
if ( V_2 -> V_36 > V_101 -> V_37 )
break;
if ( V_101 -> V_8 == V_6 )
V_116 = true ;
if ( V_2 -> V_36 < V_101 -> V_36 )
V_114 = V_2 ;
if ( V_2 -> V_37 > V_101 -> V_37 ) {
V_115 = V_2 ;
break;
}
if ( V_2 -> V_36 >= V_101 -> V_36 ) {
if ( V_116 ) {
F_77 ( V_2 , & V_32 ) ;
continue;
}
error = - V_118 ;
if ( ! V_102 )
goto V_13;
F_29 ( V_102 , V_101 ) ;
V_101 = V_102 ;
V_102 = NULL ;
F_72 ( V_101 , & V_2 -> V_23 ) ;
F_77 ( V_2 , & V_32 ) ;
V_116 = true ;
}
}
}
error = - V_118 ;
if ( V_115 && V_114 == V_115 && ! V_113 )
goto V_13;
error = 0 ;
if ( ! V_116 ) {
if ( V_101 -> V_8 == V_6 ) {
if ( V_101 -> V_3 & V_106 )
error = - V_107 ;
goto V_13;
}
if ( ! V_102 ) {
error = - V_118 ;
goto V_13;
}
F_29 ( V_102 , V_101 ) ;
F_72 ( V_102 , & V_2 -> V_23 ) ;
V_2 = V_102 ;
V_102 = NULL ;
}
if ( V_115 ) {
if ( V_114 == V_115 ) {
V_114 = V_113 ;
V_113 = NULL ;
F_29 ( V_114 , V_115 ) ;
F_72 ( V_114 , & V_2 -> V_23 ) ;
}
V_115 -> V_36 = V_101 -> V_37 + 1 ;
F_70 ( V_115 ) ;
}
if ( V_114 ) {
V_114 -> V_37 = V_101 -> V_36 - 1 ;
F_70 ( V_114 ) ;
}
V_13:
F_9 ( & V_21 -> V_16 ) ;
if ( V_102 )
F_20 ( V_102 ) ;
if ( V_113 )
F_20 ( V_113 ) ;
F_24 ( & V_32 ) ;
return error ;
}
int F_94 ( struct V_48 * V_49 , struct V_1 * V_2 ,
struct V_1 * V_111 )
{
return F_92 ( F_36 ( V_49 ) , V_2 , V_111 ) ;
}
int F_95 ( struct V_48 * V_49 , struct V_1 * V_2 )
{
int error ;
F_96 () ;
for (; ; ) {
error = F_94 ( V_49 , V_2 , NULL ) ;
if ( error != V_110 )
break;
error = F_97 ( V_2 -> V_25 , ! V_2 -> V_89 ) ;
if ( ! error )
continue;
F_64 ( V_2 ) ;
break;
}
return error ;
}
int F_98 ( struct V_48 * V_48 )
{
int V_119 ;
struct V_10 * V_10 = F_36 ( V_48 ) ;
struct V_9 * V_21 ;
struct V_1 * V_2 ;
V_21 = V_10 -> V_12 ;
if ( ! V_21 || F_84 ( & V_21 -> V_18 ) )
return 0 ;
F_8 ( & V_21 -> V_16 ) ;
V_119 = 0 ;
F_85 (fl, &ctx->flc_posix, fl_list) {
if ( V_2 -> V_33 != V_51 -> V_65 &&
V_2 -> V_33 != V_48 ) {
V_119 = - V_108 ;
break;
}
}
F_9 ( & V_21 -> V_16 ) ;
return V_119 ;
}
int F_99 ( int V_120 , struct V_10 * V_10 ,
struct V_48 * V_49 , T_1 V_121 ,
T_2 V_122 )
{
struct V_1 V_2 ;
int error ;
bool V_123 = false ;
F_27 ( & V_2 ) ;
V_2 . V_34 = V_51 -> V_52 ;
V_2 . V_35 = V_49 ;
V_2 . V_3 = V_66 | V_104 ;
if ( V_49 && ! ( V_49 -> V_124 & V_125 ) )
V_123 = true ;
V_2 . V_8 = ( V_120 == V_126 ) ? V_45 : V_7 ;
V_2 . V_36 = V_121 ;
V_2 . V_37 = V_121 + V_122 - 1 ;
for (; ; ) {
if ( V_49 ) {
V_2 . V_33 = V_49 ;
V_2 . V_3 &= ~ V_109 ;
error = F_92 ( V_10 , & V_2 , NULL ) ;
if ( ! error )
break;
}
if ( V_123 )
V_2 . V_3 |= V_109 ;
V_2 . V_33 = V_51 -> V_65 ;
error = F_92 ( V_10 , & V_2 , NULL ) ;
if ( error != V_110 )
break;
error = F_97 ( V_2 . V_25 , ! V_2 . V_89 ) ;
if ( ! error ) {
if ( F_100 ( V_10 ) )
continue;
}
F_64 ( & V_2 ) ;
break;
}
return error ;
}
static void F_101 ( struct V_1 * V_2 , int V_127 )
{
switch ( V_127 ) {
case V_6 :
V_2 -> V_3 &= ~ V_4 ;
case V_7 :
V_2 -> V_3 &= ~ V_5 ;
}
}
int F_102 ( struct V_1 * V_2 , int V_127 , struct V_31 * V_32 )
{
int error = F_33 ( V_2 , V_127 ) ;
if ( error )
return error ;
F_101 ( V_2 , V_127 ) ;
F_70 ( V_2 ) ;
if ( V_127 == V_6 ) {
struct V_48 * V_49 = V_2 -> V_35 ;
F_103 ( V_49 ) ;
V_49 -> V_128 . V_129 = 0 ;
F_104 ( 0 , V_2 -> V_35 , 0 , & V_2 -> V_70 ) ;
if ( V_2 -> V_70 != NULL ) {
F_105 ( V_130 L_1 , V_2 -> V_70 ) ;
V_2 -> V_70 = NULL ;
}
F_77 ( V_2 , V_32 ) ;
}
return 0 ;
}
static bool F_106 ( unsigned long V_131 )
{
if ( ! V_131 )
return false ;
return F_107 ( V_132 , V_131 ) ;
}
static void F_108 ( struct V_10 * V_10 , struct V_31 * V_32 )
{
struct V_9 * V_21 = V_10 -> V_12 ;
struct V_1 * V_2 , * V_112 ;
F_109 ( & V_21 -> V_16 ) ;
F_110 (fl, tmp, &ctx->flc_lease, fl_list) {
F_111 ( V_10 , V_2 ) ;
if ( F_106 ( V_2 -> V_133 ) )
F_102 ( V_2 , V_7 , V_32 ) ;
if ( F_106 ( V_2 -> V_134 ) )
F_102 ( V_2 , V_6 , V_32 ) ;
}
}
static bool F_112 ( struct V_1 * V_135 , struct V_1 * V_136 )
{
if ( ( V_136 -> V_3 & V_137 ) != ( V_135 -> V_3 & V_137 ) )
return false ;
if ( ( V_136 -> V_3 & V_138 ) && ( V_135 -> V_3 & V_78 ) )
return false ;
return F_79 ( V_136 , V_135 ) ;
}
static bool
F_113 ( struct V_10 * V_10 , struct V_1 * V_136 )
{
struct V_9 * V_21 = V_10 -> V_12 ;
struct V_1 * V_2 ;
F_109 ( & V_21 -> V_16 ) ;
F_85 (fl, &ctx->flc_lease, fl_list) {
if ( F_112 ( V_2 , V_136 ) )
return true ;
}
return false ;
}
int F_114 ( struct V_10 * V_10 , unsigned int V_139 , unsigned int type )
{
int error = 0 ;
struct V_9 * V_21 = V_10 -> V_12 ;
struct V_1 * V_102 , * V_2 , * V_112 ;
unsigned long V_140 ;
int V_141 = ( V_139 & V_142 ) != V_143 ;
F_91 ( V_32 ) ;
V_102 = F_45 ( NULL , V_141 ? V_45 : V_7 ) ;
if ( F_115 ( V_102 ) )
return F_116 ( V_102 ) ;
V_102 -> V_3 = type ;
if ( ! V_21 ) {
F_12 ( 1 ) ;
return error ;
}
F_8 ( & V_21 -> V_16 ) ;
F_108 ( V_10 , & V_32 ) ;
if ( ! F_113 ( V_10 , V_102 ) )
goto V_13;
V_140 = 0 ;
if ( V_144 > 0 ) {
V_140 = V_132 + V_144 * V_145 ;
if ( V_140 == 0 )
V_140 ++ ;
}
F_110 (fl, tmp, &ctx->flc_lease, fl_list) {
if ( ! F_112 ( V_2 , V_102 ) )
continue;
if ( V_141 ) {
if ( V_2 -> V_3 & V_4 )
continue;
V_2 -> V_3 |= V_4 ;
V_2 -> V_134 = V_140 ;
} else {
if ( F_1 ( V_2 ) )
continue;
V_2 -> V_3 |= V_5 ;
V_2 -> V_133 = V_140 ;
}
if ( V_2 -> V_29 -> V_146 ( V_2 ) )
F_77 ( V_2 , & V_32 ) ;
}
if ( F_13 ( & V_21 -> V_19 ) )
goto V_13;
if ( V_139 & V_125 ) {
F_117 ( V_10 , V_102 ) ;
error = - V_147 ;
goto V_13;
}
V_148:
V_2 = F_25 ( & V_21 -> V_19 , struct V_1 , V_23 ) ;
V_140 = V_2 -> V_134 ;
if ( V_140 != 0 )
V_140 -= V_132 ;
if ( V_140 == 0 )
V_140 ++ ;
F_69 ( V_2 , V_102 ) ;
F_118 ( V_10 , V_102 ) ;
F_9 ( & V_21 -> V_16 ) ;
F_24 ( & V_32 ) ;
error = F_119 ( V_102 -> V_25 ,
! V_102 -> V_89 , V_140 ) ;
F_8 ( & V_21 -> V_16 ) ;
F_120 ( V_10 , V_102 ) ;
F_64 ( V_102 ) ;
if ( error >= 0 ) {
if ( error == 0 )
F_108 ( V_10 , & V_32 ) ;
if ( F_113 ( V_10 , V_102 ) )
goto V_148;
error = 0 ;
}
V_13:
F_9 ( & V_21 -> V_16 ) ;
F_24 ( & V_32 ) ;
F_20 ( V_102 ) ;
return error ;
}
void F_121 ( struct V_10 * V_10 , struct V_149 * time )
{
bool V_150 = false ;
struct V_9 * V_21 = V_10 -> V_12 ;
struct V_1 * V_2 ;
if ( V_21 && ! F_84 ( & V_21 -> V_19 ) ) {
F_8 ( & V_21 -> V_16 ) ;
if ( ! F_13 ( & V_21 -> V_19 ) ) {
V_2 = F_25 ( & V_21 -> V_19 ,
struct V_1 , V_23 ) ;
if ( V_2 -> V_8 == V_45 )
V_150 = true ;
}
F_9 ( & V_21 -> V_16 ) ;
}
if ( V_150 )
* time = F_122 ( V_10 -> V_151 ) ;
else
* time = V_10 -> V_152 ;
}
int F_123 ( struct V_48 * V_49 )
{
struct V_1 * V_2 ;
struct V_10 * V_10 = F_36 ( V_49 ) ;
struct V_9 * V_21 = V_10 -> V_12 ;
int type = V_6 ;
F_91 ( V_32 ) ;
if ( V_21 && ! F_84 ( & V_21 -> V_19 ) ) {
F_8 ( & V_21 -> V_16 ) ;
F_108 ( F_36 ( V_49 ) , & V_32 ) ;
F_85 (fl, &ctx->flc_lease, fl_list) {
if ( V_2 -> V_35 != V_49 )
continue;
type = F_2 ( V_2 ) ;
break;
}
F_9 ( & V_21 -> V_16 ) ;
F_24 ( & V_32 ) ;
}
return type ;
}
static int
F_124 ( const struct V_153 * V_153 , const long V_127 , int V_154 )
{
int V_119 = 0 ;
struct V_10 * V_10 = V_153 -> V_155 ;
if ( V_154 & V_137 )
return 0 ;
if ( ( V_127 == V_7 ) && ( F_125 ( & V_10 -> V_156 ) > 0 ) )
return - V_108 ;
if ( ( V_127 == V_45 ) && ( ( F_126 ( V_153 ) > 1 ) ||
( F_125 ( & V_10 -> V_157 ) > 1 ) ) )
V_119 = - V_108 ;
return V_119 ;
}
static int
F_127 ( struct V_48 * V_49 , long V_127 , struct V_1 * * V_158 , void * * V_73 )
{
struct V_1 * V_2 , * V_159 = NULL , * V_135 ;
struct V_153 * V_153 = V_49 -> V_160 . V_153 ;
struct V_10 * V_10 = V_153 -> V_155 ;
struct V_9 * V_21 ;
bool V_161 = ( * V_158 ) -> V_3 & V_138 ;
int error ;
F_91 ( V_32 ) ;
V_135 = * V_158 ;
F_128 ( V_10 , V_135 ) ;
V_21 = F_3 ( V_10 ) ;
if ( ! V_21 )
return - V_50 ;
if ( V_161 && ! F_129 ( & V_10 -> V_162 ) )
return - V_108 ;
if ( V_161 && V_127 == V_45 ) {
F_130 ( & V_10 -> V_162 ) ;
F_12 ( 1 ) ;
return - V_47 ;
}
F_8 ( & V_21 -> V_16 ) ;
F_108 ( V_10 , & V_32 ) ;
error = F_124 ( V_153 , V_127 , V_135 -> V_3 ) ;
if ( error )
goto V_13;
error = - V_108 ;
F_85 (fl, &ctx->flc_lease, fl_list) {
if ( V_2 -> V_35 == V_49 &&
V_2 -> V_33 == V_135 -> V_33 ) {
V_159 = V_2 ;
continue;
}
if ( V_127 == V_45 )
goto V_13;
if ( V_2 -> V_3 & V_4 )
goto V_13;
}
if ( V_159 != NULL ) {
V_135 = V_159 ;
error = V_135 -> V_29 -> V_163 ( V_135 , V_127 , & V_32 ) ;
if ( error )
goto V_13;
goto V_164;
}
error = - V_47 ;
if ( ! V_165 )
goto V_13;
F_72 ( V_135 , & V_21 -> V_19 ) ;
F_131 () ;
error = F_124 ( V_153 , V_127 , V_135 -> V_3 ) ;
if ( error ) {
F_75 ( V_135 ) ;
goto V_13;
}
V_164:
if ( V_135 -> V_29 -> V_166 )
V_135 -> V_29 -> V_166 ( V_135 , V_73 ) ;
V_13:
F_9 ( & V_21 -> V_16 ) ;
F_24 ( & V_32 ) ;
if ( V_161 )
F_130 ( & V_10 -> V_162 ) ;
if ( ! error && ! V_159 )
* V_158 = NULL ;
return error ;
}
static int F_132 ( struct V_48 * V_49 , void * V_167 )
{
int error = - V_108 ;
struct V_1 * V_2 , * V_168 = NULL ;
struct V_153 * V_153 = V_49 -> V_160 . V_153 ;
struct V_10 * V_10 = V_153 -> V_155 ;
struct V_9 * V_21 = V_10 -> V_12 ;
F_91 ( V_32 ) ;
if ( ! V_21 ) {
F_133 ( V_10 , NULL ) ;
return error ;
}
F_8 ( & V_21 -> V_16 ) ;
F_85 (fl, &ctx->flc_lease, fl_list) {
if ( V_2 -> V_35 == V_49 &&
V_2 -> V_33 == V_167 ) {
V_168 = V_2 ;
break;
}
}
F_133 ( V_10 , V_168 ) ;
if ( V_168 )
error = V_2 -> V_29 -> V_163 ( V_168 , V_6 , & V_32 ) ;
F_9 ( & V_21 -> V_16 ) ;
F_24 ( & V_32 ) ;
return error ;
}
int F_134 ( struct V_48 * V_49 , long V_127 , struct V_1 * * V_158 ,
void * * V_73 )
{
struct V_153 * V_153 = V_49 -> V_160 . V_153 ;
struct V_10 * V_10 = V_153 -> V_155 ;
int error ;
if ( ( ! F_135 ( F_136 () , V_10 -> V_169 ) ) && ! F_137 ( V_170 ) )
return - V_171 ;
if ( ! F_138 ( V_10 -> V_172 ) )
return - V_47 ;
error = F_139 ( V_49 , V_127 ) ;
if ( error )
return error ;
switch ( V_127 ) {
case V_6 :
return F_132 ( V_49 , * V_73 ) ;
case V_7 :
case V_45 :
if ( ! ( * V_158 ) -> V_29 -> V_146 ) {
F_12 ( 1 ) ;
return - V_118 ;
}
return F_127 ( V_49 , V_127 , V_158 , V_73 ) ;
default:
return - V_47 ;
}
}
int
F_140 ( struct V_48 * V_49 , long V_127 , struct V_1 * * V_135 , void * * V_73 )
{
if ( V_49 -> V_173 -> V_174 )
return V_49 -> V_173 -> V_174 ( V_49 , V_127 , V_135 , V_73 ) ;
else
return F_134 ( V_49 , V_127 , V_135 , V_73 ) ;
}
static int F_141 ( unsigned int V_175 , struct V_48 * V_49 , long V_127 )
{
struct V_1 * V_2 ;
struct V_74 * V_11 ;
int error ;
V_2 = F_45 ( V_49 , V_127 ) ;
if ( F_115 ( V_2 ) )
return F_116 ( V_2 ) ;
V_11 = F_142 () ;
if ( ! V_11 ) {
F_20 ( V_2 ) ;
return - V_50 ;
}
V_11 -> V_76 = V_175 ;
error = F_140 ( V_49 , V_127 , & V_2 , ( void * * ) & V_11 ) ;
if ( V_2 )
F_20 ( V_2 ) ;
if ( V_11 )
F_143 ( V_11 ) ;
return error ;
}
int F_144 ( unsigned int V_175 , struct V_48 * V_49 , long V_127 )
{
if ( V_127 == V_6 )
return F_140 ( V_49 , V_6 , NULL , ( void * * ) & V_49 ) ;
return F_141 ( V_175 , V_49 , V_127 ) ;
}
int F_145 ( struct V_48 * V_49 , struct V_1 * V_2 )
{
int error ;
F_96 () ;
for (; ; ) {
error = F_90 ( V_49 , V_2 ) ;
if ( error != V_110 )
break;
error = F_97 ( V_2 -> V_25 , ! V_2 -> V_89 ) ;
if ( ! error )
continue;
F_64 ( V_2 ) ;
break;
}
return error ;
}
int F_146 ( struct V_48 * V_49 , struct V_1 * V_2 )
{
if ( V_49 -> V_173 -> V_176 )
return V_49 -> V_173 -> V_176 ( V_49 , V_177 , V_2 ) ;
F_83 ( V_49 , V_2 ) ;
return 0 ;
}
static int F_147 ( struct V_68 * V_68 , struct V_1 * V_2 )
{
V_68 -> V_178 = F_68 ( V_2 ) ? - 1 : V_2 -> V_34 ;
#if V_179 == 32
if ( V_2 -> V_36 > V_180 )
return - V_63 ;
if ( V_2 -> V_37 != V_54 && V_2 -> V_37 > V_180 )
return - V_63 ;
#endif
V_68 -> V_62 = V_2 -> V_36 ;
V_68 -> V_64 = V_2 -> V_37 == V_54 ? 0 :
V_2 -> V_37 - V_2 -> V_36 + 1 ;
V_68 -> V_57 = 0 ;
V_68 -> V_67 = V_2 -> V_8 ;
return 0 ;
}
static void F_148 ( struct V_55 * V_68 , struct V_1 * V_2 )
{
V_68 -> V_178 = F_68 ( V_2 ) ? - 1 : V_2 -> V_34 ;
V_68 -> V_62 = V_2 -> V_36 ;
V_68 -> V_64 = V_2 -> V_37 == V_54 ? 0 :
V_2 -> V_37 - V_2 -> V_36 + 1 ;
V_68 -> V_57 = 0 ;
V_68 -> V_67 = V_2 -> V_8 ;
}
int F_149 ( struct V_48 * V_49 , unsigned int V_40 , struct V_68 T_3 * V_56 )
{
struct V_1 V_1 ;
struct V_68 V_68 ;
int error ;
error = - V_181 ;
if ( F_150 ( & V_68 , V_56 , sizeof( V_68 ) ) )
goto V_13;
error = - V_47 ;
if ( ( V_68 . V_67 != V_7 ) && ( V_68 . V_67 != V_45 ) )
goto V_13;
error = F_37 ( V_49 , & V_1 , & V_68 ) ;
if ( error )
goto V_13;
if ( V_40 == V_182 ) {
error = - V_47 ;
if ( V_68 . V_178 != 0 )
goto V_13;
V_40 = V_177 ;
V_1 . V_3 |= V_183 ;
V_1 . V_33 = V_49 ;
}
error = F_146 ( V_49 , & V_1 ) ;
if ( error )
goto V_13;
V_68 . V_67 = V_1 . V_8 ;
if ( V_1 . V_8 != V_6 ) {
error = F_147 ( & V_68 , & V_1 ) ;
if ( error )
goto V_184;
}
error = - V_181 ;
if ( ! F_151 ( V_56 , & V_68 , sizeof( V_68 ) ) )
error = 0 ;
V_184:
F_19 ( & V_1 ) ;
V_13:
return error ;
}
int F_152 ( struct V_48 * V_49 , unsigned int V_40 , struct V_1 * V_2 , struct V_1 * V_185 )
{
if ( V_49 -> V_173 -> V_176 )
return V_49 -> V_173 -> V_176 ( V_49 , V_40 , V_2 ) ;
else
return F_94 ( V_49 , V_2 , V_185 ) ;
}
static int F_153 ( struct V_48 * V_49 , unsigned int V_40 ,
struct V_1 * V_2 )
{
int error ;
error = F_139 ( V_49 , V_2 -> V_8 ) ;
if ( error )
return error ;
for (; ; ) {
error = F_152 ( V_49 , V_40 , V_2 , NULL ) ;
if ( error != V_110 )
break;
error = F_97 ( V_2 -> V_25 , ! V_2 -> V_89 ) ;
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
if ( ! ( V_2 -> V_35 -> V_186 & V_187 ) )
return - V_188 ;
break;
case V_45 :
if ( ! ( V_2 -> V_35 -> V_186 & V_189 ) )
return - V_188 ;
}
return 0 ;
}
int F_155 ( unsigned int V_175 , struct V_48 * V_49 , unsigned int V_40 ,
struct V_68 T_3 * V_56 )
{
struct V_1 * V_1 = F_17 () ;
struct V_68 V_68 ;
struct V_10 * V_10 ;
struct V_48 * V_190 ;
int error ;
if ( V_1 == NULL )
return - V_118 ;
error = - V_181 ;
if ( F_150 ( & V_68 , V_56 , sizeof( V_68 ) ) )
goto V_13;
V_10 = F_36 ( V_49 ) ;
if ( F_156 ( V_10 ) && F_157 ( V_49 -> V_191 ) ) {
error = - V_108 ;
goto V_13;
}
V_192:
error = F_37 ( V_49 , V_1 , & V_68 ) ;
if ( error )
goto V_13;
error = F_154 ( V_1 ) ;
if ( error )
goto V_13;
switch ( V_40 ) {
case V_193 :
error = - V_47 ;
if ( V_68 . V_178 != 0 )
goto V_13;
V_40 = V_194 ;
V_1 -> V_3 |= V_183 ;
V_1 -> V_33 = V_49 ;
break;
case V_195 :
error = - V_47 ;
if ( V_68 . V_178 != 0 )
goto V_13;
V_40 = V_196 ;
V_1 -> V_3 |= V_183 ;
V_1 -> V_33 = V_49 ;
case V_196 :
V_1 -> V_3 |= V_109 ;
}
error = F_153 ( V_49 , V_40 , V_1 ) ;
F_8 ( & V_51 -> V_65 -> V_1 ) ;
V_190 = F_158 ( V_175 ) ;
F_9 ( & V_51 -> V_65 -> V_1 ) ;
if ( ! error && V_190 != V_49 && V_68 . V_67 != V_6 ) {
V_68 . V_67 = V_6 ;
goto V_192;
}
V_13:
F_20 ( V_1 ) ;
return error ;
}
int F_159 ( struct V_48 * V_49 , unsigned int V_40 , struct V_55 T_3 * V_56 )
{
struct V_1 V_1 ;
struct V_55 V_68 ;
int error ;
error = - V_181 ;
if ( F_150 ( & V_68 , V_56 , sizeof( V_68 ) ) )
goto V_13;
error = - V_47 ;
if ( ( V_68 . V_67 != V_7 ) && ( V_68 . V_67 != V_45 ) )
goto V_13;
error = F_34 ( V_49 , & V_1 , & V_68 ) ;
if ( error )
goto V_13;
if ( V_40 == V_182 ) {
error = - V_47 ;
if ( V_68 . V_178 != 0 )
goto V_13;
V_40 = V_197 ;
V_1 . V_3 |= V_183 ;
V_1 . V_33 = V_49 ;
}
error = F_146 ( V_49 , & V_1 ) ;
if ( error )
goto V_13;
V_68 . V_67 = V_1 . V_8 ;
if ( V_1 . V_8 != V_6 )
F_148 ( & V_68 , & V_1 ) ;
error = - V_181 ;
if ( ! F_151 ( V_56 , & V_68 , sizeof( V_68 ) ) )
error = 0 ;
F_19 ( & V_1 ) ;
V_13:
return error ;
}
int F_160 ( unsigned int V_175 , struct V_48 * V_49 , unsigned int V_40 ,
struct V_55 T_3 * V_56 )
{
struct V_1 * V_1 = F_17 () ;
struct V_55 V_68 ;
struct V_10 * V_10 ;
struct V_48 * V_190 ;
int error ;
if ( V_1 == NULL )
return - V_118 ;
error = - V_181 ;
if ( F_150 ( & V_68 , V_56 , sizeof( V_68 ) ) )
goto V_13;
V_10 = F_36 ( V_49 ) ;
if ( F_156 ( V_10 ) && F_157 ( V_49 -> V_191 ) ) {
error = - V_108 ;
goto V_13;
}
V_192:
error = F_34 ( V_49 , V_1 , & V_68 ) ;
if ( error )
goto V_13;
error = F_154 ( V_1 ) ;
if ( error )
goto V_13;
switch ( V_40 ) {
case V_193 :
error = - V_47 ;
if ( V_68 . V_178 != 0 )
goto V_13;
V_40 = V_198 ;
V_1 -> V_3 |= V_183 ;
V_1 -> V_33 = V_49 ;
break;
case V_195 :
error = - V_47 ;
if ( V_68 . V_178 != 0 )
goto V_13;
V_40 = V_199 ;
V_1 -> V_3 |= V_183 ;
V_1 -> V_33 = V_49 ;
case V_199 :
V_1 -> V_3 |= V_109 ;
}
error = F_153 ( V_49 , V_40 , V_1 ) ;
F_8 ( & V_51 -> V_65 -> V_1 ) ;
V_190 = F_158 ( V_175 ) ;
F_9 ( & V_51 -> V_65 -> V_1 ) ;
if ( ! error && V_190 != V_49 && V_68 . V_67 != V_6 ) {
V_68 . V_67 = V_6 ;
goto V_192;
}
V_13:
F_20 ( V_1 ) ;
return error ;
}
void F_161 ( struct V_48 * V_49 , T_4 V_167 )
{
struct V_1 V_176 ;
struct V_9 * V_21 = F_36 ( V_49 ) -> V_12 ;
if ( ! V_21 || F_13 ( & V_21 -> V_18 ) )
return;
V_176 . V_8 = V_6 ;
V_176 . V_3 = V_66 | V_200 ;
V_176 . V_36 = 0 ;
V_176 . V_37 = V_54 ;
V_176 . V_33 = V_167 ;
V_176 . V_34 = V_51 -> V_52 ;
V_176 . V_35 = V_49 ;
V_176 . V_27 = NULL ;
V_176 . V_29 = NULL ;
F_152 ( V_49 , V_194 , & V_176 , NULL ) ;
if ( V_176 . V_27 && V_176 . V_27 -> V_28 )
V_176 . V_27 -> V_28 ( & V_176 ) ;
}
static void
F_162 ( struct V_48 * V_49 )
{
struct V_1 V_2 = {
. V_33 = V_49 ,
. V_34 = V_51 -> V_52 ,
. V_35 = V_49 ,
. V_3 = V_53 ,
. V_8 = V_6 ,
. V_37 = V_54 ,
} ;
struct V_9 * V_201 = F_36 ( V_49 ) -> V_12 ;
if ( F_13 ( & V_201 -> V_17 ) )
return;
if ( V_49 -> V_173 -> V_68 )
V_49 -> V_173 -> V_68 ( V_49 , V_196 , & V_2 ) ;
else
F_90 ( V_49 , & V_2 ) ;
if ( V_2 . V_27 && V_2 . V_27 -> V_28 )
V_2 . V_27 -> V_28 ( & V_2 ) ;
}
static void
F_163 ( struct V_48 * V_49 )
{
struct V_10 * V_10 = F_36 ( V_49 ) ;
struct V_9 * V_21 = V_10 -> V_12 ;
struct V_1 * V_2 , * V_112 ;
F_91 ( V_32 ) ;
if ( F_13 ( & V_21 -> V_19 ) )
return;
F_8 ( & V_21 -> V_16 ) ;
F_110 (fl, tmp, &ctx->flc_lease, fl_list)
if ( V_49 == V_2 -> V_35 )
F_102 ( V_2 , V_6 , & V_32 ) ;
F_9 ( & V_21 -> V_16 ) ;
F_24 ( & V_32 ) ;
}
void F_164 ( struct V_48 * V_49 )
{
if ( ! F_36 ( V_49 ) -> V_12 )
return;
F_161 ( V_49 , V_49 ) ;
F_162 ( V_49 ) ;
F_163 ( V_49 ) ;
}
int
F_165 ( struct V_1 * V_87 )
{
int V_202 = 0 ;
F_8 ( & V_90 ) ;
if ( V_87 -> V_89 )
F_63 ( V_87 ) ;
else
V_202 = - V_107 ;
F_9 ( & V_90 ) ;
return V_202 ;
}
int F_166 ( struct V_48 * V_49 , struct V_1 * V_2 )
{
if ( V_49 -> V_173 -> V_176 )
return V_49 -> V_173 -> V_176 ( V_49 , V_203 , V_2 ) ;
return 0 ;
}
static void F_167 ( struct V_204 * V_190 , struct V_1 * V_2 ,
T_1 V_205 , char * V_206 )
{
struct V_10 * V_10 = NULL ;
unsigned int V_34 ;
if ( V_2 -> V_94 )
V_34 = F_86 ( V_2 -> V_94 ) ;
else
V_34 = V_2 -> V_34 ;
if ( V_2 -> V_35 != NULL )
V_10 = F_36 ( V_2 -> V_35 ) ;
F_168 ( V_190 , L_2 , V_205 , V_206 ) ;
if ( F_67 ( V_2 ) ) {
if ( V_2 -> V_3 & V_104 )
F_169 ( V_190 , L_3 ) ;
else if ( F_68 ( V_2 ) )
F_169 ( V_190 , L_4 ) ;
else
F_169 ( V_190 , L_5 ) ;
F_168 ( V_190 , L_6 ,
( V_10 == NULL ) ? L_7 :
F_156 ( V_10 ) ? L_8 : L_9 ) ;
} else if ( F_82 ( V_2 ) ) {
if ( V_2 -> V_8 & V_41 ) {
F_169 ( V_190 , L_10 ) ;
} else {
F_169 ( V_190 , L_11 ) ;
}
} else if ( F_170 ( V_2 ) ) {
if ( V_2 -> V_3 & V_138 )
F_169 ( V_190 , L_12 ) ;
else
F_169 ( V_190 , L_13 ) ;
if ( F_1 ( V_2 ) )
F_169 ( V_190 , L_14 ) ;
else if ( V_2 -> V_35 )
F_169 ( V_190 , L_15 ) ;
else
F_169 ( V_190 , L_16 ) ;
} else {
F_169 ( V_190 , L_17 ) ;
}
if ( V_2 -> V_8 & V_41 ) {
F_168 ( V_190 , L_18 ,
( V_2 -> V_8 & V_207 )
? ( V_2 -> V_8 & V_208 ) ? L_19 : L_20
: ( V_2 -> V_8 & V_208 ) ? L_21 : L_22 ) ;
} else {
F_168 ( V_190 , L_18 ,
( F_1 ( V_2 ) )
? ( V_2 -> V_8 == V_6 ) ? L_23 : L_20
: ( V_2 -> V_8 == V_45 ) ? L_21 : L_20 ) ;
}
if ( V_10 ) {
#ifdef F_171
F_168 ( V_190 , L_24 , V_34 ,
V_10 -> V_151 -> V_209 , V_10 -> V_210 ) ;
#else
F_168 ( V_190 , L_25 , V_34 ,
F_172 ( V_10 -> V_151 -> V_211 ) ,
F_173 ( V_10 -> V_151 -> V_211 ) , V_10 -> V_210 ) ;
#endif
} else {
F_168 ( V_190 , L_26 , V_34 ) ;
}
if ( F_67 ( V_2 ) ) {
if ( V_2 -> V_37 == V_54 )
F_168 ( V_190 , L_27 , V_2 -> V_36 ) ;
else
F_168 ( V_190 , L_28 , V_2 -> V_36 , V_2 -> V_37 ) ;
} else {
F_169 ( V_190 , L_29 ) ;
}
}
static int F_174 ( struct V_204 * V_190 , void * V_212 )
{
struct V_213 * V_214 = V_190 -> V_215 ;
struct V_1 * V_2 , * V_216 ;
V_2 = F_175 ( V_212 , struct V_1 , V_22 ) ;
F_167 ( V_190 , V_2 , V_214 -> V_217 , L_30 ) ;
F_85 (bfl, &fl->fl_block, fl_block)
F_167 ( V_190 , V_216 , V_214 -> V_217 , L_31 ) ;
return 0 ;
}
static void * F_176 ( struct V_204 * V_190 , T_1 * V_218 )
__acquires( &blocked_lock_lock
static void * F_177 ( struct V_204 * V_190 , void * V_212 , T_1 * V_218 )
{
struct V_213 * V_214 = V_190 -> V_215 ;
++ V_214 -> V_217 ;
return F_178 ( V_212 , & V_85 , & V_214 -> V_219 , V_218 ) ;
}
static void F_179 ( struct V_204 * V_190 , void * V_212 )
__releases( &blocked_lock_lock
static int F_180 ( struct V_10 * V_10 , struct V_48 * V_49 )
{
return F_181 ( V_49 , & V_220 ,
sizeof( struct V_213 ) ) ;
}
static int T_5 F_182 ( void )
{
F_183 ( L_32 , 0 , NULL , & V_221 ) ;
return 0 ;
}
static int T_5 F_184 ( void )
{
int V_99 ;
V_14 = F_185 ( L_33 ,
sizeof( struct V_9 ) , 0 , V_222 , NULL ) ;
V_26 = F_185 ( L_34 ,
sizeof( struct V_1 ) , 0 , V_222 , NULL ) ;
F_186 ( & V_83 , L_35 ) ;
F_187 (i)
F_188 ( F_189 ( & V_85 , V_99 ) ) ;
return 0 ;
}
