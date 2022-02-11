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
static void F_3 ( struct V_1 * V_2 )
{
F_4 ( & V_2 -> V_9 ) ;
F_5 ( & V_2 -> V_10 ) ;
F_6 ( & V_2 -> V_11 ) ;
}
struct V_1 * F_7 ( void )
{
struct V_1 * V_2 = F_8 ( V_12 , V_13 ) ;
if ( V_2 )
F_3 ( V_2 ) ;
return V_2 ;
}
void F_9 ( struct V_1 * V_2 )
{
if ( V_2 -> V_14 ) {
if ( V_2 -> V_14 -> V_15 )
V_2 -> V_14 -> V_15 ( V_2 ) ;
V_2 -> V_14 = NULL ;
}
if ( V_2 -> V_16 ) {
if ( V_2 -> V_16 -> V_17 )
V_2 -> V_16 -> V_17 ( V_2 ) ;
V_2 -> V_16 = NULL ;
}
}
void F_10 ( struct V_1 * V_2 )
{
F_11 ( F_12 ( & V_2 -> V_11 ) ) ;
F_11 ( ! F_13 ( & V_2 -> V_10 ) ) ;
F_11 ( ! F_14 ( & V_2 -> V_9 ) ) ;
F_9 ( V_2 ) ;
F_15 ( V_12 , V_2 ) ;
}
static void
F_16 ( struct V_18 * V_19 )
{
struct V_1 * V_2 ;
while ( ! F_13 ( V_19 ) ) {
V_2 = F_17 ( V_19 , struct V_1 , V_10 ) ;
F_18 ( & V_2 -> V_10 ) ;
F_10 ( V_2 ) ;
}
}
void F_19 ( struct V_1 * V_2 )
{
memset ( V_2 , 0 , sizeof( struct V_1 ) ) ;
F_3 ( V_2 ) ;
}
void F_20 ( struct V_1 * V_20 , struct V_1 * V_2 )
{
V_20 -> V_21 = V_2 -> V_21 ;
V_20 -> V_22 = V_2 -> V_22 ;
V_20 -> V_23 = NULL ;
V_20 -> V_3 = V_2 -> V_3 ;
V_20 -> V_8 = V_2 -> V_8 ;
V_20 -> V_24 = V_2 -> V_24 ;
V_20 -> V_25 = V_2 -> V_25 ;
V_20 -> V_16 = V_2 -> V_16 ;
V_20 -> V_14 = NULL ;
if ( V_2 -> V_16 ) {
if ( V_2 -> V_16 -> V_26 )
V_2 -> V_16 -> V_26 ( V_20 , V_2 ) ;
}
}
void F_21 ( struct V_1 * V_20 , struct V_1 * V_2 )
{
F_22 ( V_20 -> V_14 ) ;
F_20 ( V_20 , V_2 ) ;
V_20 -> V_23 = V_2 -> V_23 ;
V_20 -> V_14 = V_2 -> V_14 ;
if ( V_2 -> V_14 ) {
if ( V_2 -> V_14 -> V_27 )
V_2 -> V_14 -> V_27 ( V_20 , V_2 ) ;
}
}
static inline int F_23 ( int V_28 ) {
if ( V_28 & V_29 )
return V_28 & ( V_29 | V_30 ) ;
switch ( V_28 ) {
case V_31 :
return V_7 ;
case V_32 :
return V_33 ;
case V_34 :
return V_6 ;
}
return - V_35 ;
}
static struct V_1 *
F_24 ( struct V_36 * V_37 , unsigned int V_28 )
{
struct V_1 * V_2 ;
int type = F_23 ( V_28 ) ;
if ( type < 0 )
return F_25 ( type ) ;
V_2 = F_7 () ;
if ( V_2 == NULL )
return F_25 ( - V_38 ) ;
V_2 -> V_23 = V_37 ;
V_2 -> V_21 = V_37 ;
V_2 -> V_22 = V_39 -> V_40 ;
V_2 -> V_3 = V_41 ;
V_2 -> V_8 = type ;
V_2 -> V_25 = V_42 ;
return V_2 ;
}
static int F_26 ( struct V_1 * V_2 , long type )
{
switch ( type ) {
case V_7 :
case V_33 :
case V_6 :
V_2 -> V_8 = type ;
break;
default:
return - V_35 ;
}
return 0 ;
}
static int F_27 ( struct V_36 * V_37 , struct V_1 * V_2 ,
struct V_43 * V_44 )
{
switch ( V_44 -> V_45 ) {
case V_46 :
V_2 -> V_24 = 0 ;
break;
case V_47 :
V_2 -> V_24 = V_37 -> V_48 ;
break;
case V_49 :
V_2 -> V_24 = F_28 ( F_29 ( V_37 ) ) ;
break;
default:
return - V_35 ;
}
if ( V_44 -> V_50 > V_42 - V_2 -> V_24 )
return - V_51 ;
V_2 -> V_24 += V_44 -> V_50 ;
if ( V_2 -> V_24 < 0 )
return - V_35 ;
if ( V_44 -> V_52 > 0 ) {
if ( V_44 -> V_52 - 1 > V_42 - V_2 -> V_24 )
return - V_51 ;
V_2 -> V_25 = V_2 -> V_24 + V_44 -> V_52 - 1 ;
} else if ( V_44 -> V_52 < 0 ) {
if ( V_2 -> V_24 + V_44 -> V_52 < 0 )
return - V_35 ;
V_2 -> V_25 = V_2 -> V_24 - 1 ;
V_2 -> V_24 += V_44 -> V_52 ;
} else
V_2 -> V_25 = V_42 ;
V_2 -> V_21 = V_39 -> V_53 ;
V_2 -> V_22 = V_39 -> V_40 ;
V_2 -> V_23 = V_37 ;
V_2 -> V_3 = V_54 ;
V_2 -> V_14 = NULL ;
V_2 -> V_16 = NULL ;
return F_26 ( V_2 , V_44 -> V_55 ) ;
}
static int F_30 ( struct V_36 * V_37 , struct V_1 * V_2 ,
struct V_56 * V_44 )
{
struct V_43 V_57 = {
. V_55 = V_44 -> V_55 ,
. V_45 = V_44 -> V_45 ,
. V_50 = V_44 -> V_50 ,
. V_52 = V_44 -> V_52 ,
} ;
return F_27 ( V_37 , V_2 , & V_57 ) ;
}
static bool
F_31 ( struct V_1 * V_2 )
{
F_32 ( & V_2 -> V_58 , V_59 , V_60 ) ;
return false ;
}
static void
F_33 ( struct V_1 * V_2 , void * * V_61 )
{
struct V_36 * V_37 = V_2 -> V_23 ;
struct V_62 * V_63 = * V_61 ;
if ( ! F_34 ( V_63 -> V_64 , V_37 , & V_2 -> V_58 , V_63 ) )
* V_61 = NULL ;
F_35 ( V_37 , F_36 ( V_39 ) , V_65 , 0 ) ;
}
static int F_37 ( struct V_36 * V_37 , long type , struct V_1 * V_2 )
{
if ( F_26 ( V_2 , type ) != 0 )
return - V_35 ;
V_2 -> V_21 = V_37 ;
V_2 -> V_22 = V_39 -> V_40 ;
V_2 -> V_23 = V_37 ;
V_2 -> V_3 = V_66 ;
V_2 -> V_24 = 0 ;
V_2 -> V_25 = V_42 ;
V_2 -> V_14 = NULL ;
V_2 -> V_16 = & V_67 ;
return 0 ;
}
static struct V_1 * F_38 ( struct V_36 * V_37 , long type )
{
struct V_1 * V_2 = F_7 () ;
int error = - V_38 ;
if ( V_2 == NULL )
return F_25 ( error ) ;
error = F_37 ( V_37 , type , V_2 ) ;
if ( error ) {
F_10 ( V_2 ) ;
return F_25 ( error ) ;
}
return V_2 ;
}
static inline int F_39 ( struct V_1 * V_68 , struct V_1 * V_69 )
{
return ( ( V_68 -> V_25 >= V_69 -> V_24 ) &&
( V_69 -> V_25 >= V_68 -> V_24 ) ) ;
}
static int F_40 ( struct V_1 * V_68 , struct V_1 * V_69 )
{
if ( V_68 -> V_16 && V_68 -> V_16 -> V_70 )
return V_69 -> V_16 == V_68 -> V_16 &&
V_68 -> V_16 -> V_70 ( V_68 , V_69 ) ;
return V_68 -> V_21 == V_69 -> V_21 ;
}
static void F_41 ( struct V_1 * V_2 )
{
F_42 ( & V_71 ) ;
V_2 -> V_72 = F_43 () ;
F_44 ( & V_2 -> V_9 , F_45 ( & V_73 ) ) ;
F_46 ( & V_71 ) ;
}
static void F_47 ( struct V_1 * V_2 )
{
if ( F_14 ( & V_2 -> V_9 ) )
return;
F_48 ( & V_71 , V_2 -> V_72 ) ;
F_49 ( & V_2 -> V_9 ) ;
F_50 ( & V_71 , V_2 -> V_72 ) ;
}
static unsigned long
F_51 ( struct V_1 * V_2 )
{
if ( V_2 -> V_16 && V_2 -> V_16 -> V_74 )
return V_2 -> V_16 -> V_74 ( V_2 ) ;
return ( unsigned long ) V_2 -> V_21 ;
}
static void F_52 ( struct V_1 * V_75 )
{
F_53 ( V_76 , & V_75 -> V_9 , F_51 ( V_75 ) ) ;
}
static void F_54 ( struct V_1 * V_75 )
{
F_55 ( & V_75 -> V_9 ) ;
}
static void F_56 ( struct V_1 * V_75 )
{
F_54 ( V_75 ) ;
F_18 ( & V_75 -> V_10 ) ;
V_75 -> V_77 = NULL ;
}
static void F_57 ( struct V_1 * V_75 )
{
F_58 ( & V_78 ) ;
F_56 ( V_75 ) ;
F_59 ( & V_78 ) ;
}
static void F_60 ( struct V_1 * V_79 ,
struct V_1 * V_75 )
{
F_11 ( ! F_13 ( & V_75 -> V_10 ) ) ;
V_75 -> V_77 = V_79 ;
F_61 ( & V_75 -> V_10 , & V_79 -> V_10 ) ;
if ( F_62 ( V_79 ) && ! F_63 ( V_79 ) )
F_52 ( V_75 ) ;
}
static void F_64 ( struct V_1 * V_79 ,
struct V_1 * V_75 )
{
F_58 ( & V_78 ) ;
F_60 ( V_79 , V_75 ) ;
F_59 ( & V_78 ) ;
}
static void F_65 ( struct V_1 * V_79 )
{
if ( F_13 ( & V_79 -> V_10 ) )
return;
F_58 ( & V_78 ) ;
while ( ! F_13 ( & V_79 -> V_10 ) ) {
struct V_1 * V_75 ;
V_75 = F_17 ( & V_79 -> V_10 ,
struct V_1 , V_10 ) ;
F_56 ( V_75 ) ;
if ( V_75 -> V_16 && V_75 -> V_16 -> V_80 )
V_75 -> V_16 -> V_80 ( V_75 ) ;
else
F_66 ( & V_75 -> V_11 ) ;
}
F_59 ( & V_78 ) ;
}
static void F_67 ( struct V_1 * * V_81 , struct V_1 * V_2 )
{
V_2 -> V_82 = F_68 ( F_69 ( V_39 ) ) ;
V_2 -> V_77 = * V_81 ;
* V_81 = V_2 ;
F_41 ( V_2 ) ;
}
static void F_70 ( struct V_1 * * V_83 )
{
struct V_1 * V_2 = * V_83 ;
F_47 ( V_2 ) ;
* V_83 = V_2 -> V_77 ;
V_2 -> V_77 = NULL ;
if ( V_2 -> V_82 ) {
F_71 ( V_2 -> V_82 ) ;
V_2 -> V_82 = NULL ;
}
F_65 ( V_2 ) ;
}
static void F_72 ( struct V_1 * * V_83 ,
struct V_18 * V_19 )
{
struct V_1 * V_2 = * V_83 ;
F_70 ( V_83 ) ;
if ( V_19 )
F_73 ( & V_2 -> V_10 , V_19 ) ;
else
F_10 ( V_2 ) ;
}
static int F_74 ( struct V_1 * V_84 , struct V_1 * V_85 )
{
if ( V_85 -> V_8 == V_33 )
return 1 ;
if ( V_84 -> V_8 == V_33 )
return 1 ;
return 0 ;
}
static int F_75 ( struct V_1 * V_84 , struct V_1 * V_85 )
{
if ( ! F_62 ( V_85 ) || F_40 ( V_84 , V_85 ) )
return ( 0 ) ;
if ( ! F_39 ( V_84 , V_85 ) )
return 0 ;
return ( F_74 ( V_84 , V_85 ) ) ;
}
static int F_76 ( struct V_1 * V_84 , struct V_1 * V_85 )
{
if ( ! F_77 ( V_85 ) || ( V_84 -> V_23 == V_85 -> V_23 ) )
return ( 0 ) ;
if ( ( V_84 -> V_8 & V_29 ) || ( V_85 -> V_8 & V_29 ) )
return 0 ;
return ( F_74 ( V_84 , V_85 ) ) ;
}
void
F_78 ( struct V_36 * V_37 , struct V_1 * V_2 )
{
struct V_1 * V_86 ;
struct V_87 * V_87 = F_29 ( V_37 ) ;
F_58 ( & V_87 -> V_88 ) ;
for ( V_86 = F_29 ( V_37 ) -> V_89 ; V_86 ; V_86 = V_86 -> V_77 ) {
if ( ! F_62 ( V_86 ) )
continue;
if ( F_75 ( V_2 , V_86 ) )
break;
}
if ( V_86 ) {
F_20 ( V_2 , V_86 ) ;
if ( V_86 -> V_82 )
V_2 -> V_22 = F_79 ( V_86 -> V_82 ) ;
} else
V_2 -> V_8 = V_6 ;
F_59 ( & V_87 -> V_88 ) ;
return;
}
static struct V_1 * F_80 ( struct V_1 * V_90 )
{
struct V_1 * V_2 ;
F_81 (blocked_hash, fl, fl_link, posix_owner_key(block_fl)) {
if ( F_40 ( V_2 , V_90 ) )
return V_2 -> V_77 ;
}
return NULL ;
}
static int F_82 ( struct V_1 * V_84 ,
struct V_1 * V_90 )
{
int V_91 = 0 ;
if ( F_63 ( V_84 ) )
return 0 ;
while ( ( V_90 = F_80 ( V_90 ) ) ) {
if ( V_91 ++ > V_92 )
return 0 ;
if ( F_40 ( V_84 , V_90 ) )
return 1 ;
}
return 0 ;
}
static int F_83 ( struct V_36 * V_37 , struct V_1 * V_93 )
{
struct V_1 * V_94 = NULL ;
struct V_1 * * V_95 ;
struct V_87 * V_87 = F_29 ( V_37 ) ;
int error = 0 ;
int V_96 = 0 ;
F_84 ( V_19 ) ;
if ( ! ( V_93 -> V_3 & V_97 ) && ( V_93 -> V_8 != V_6 ) ) {
V_94 = F_7 () ;
if ( ! V_94 )
return - V_38 ;
}
F_58 ( & V_87 -> V_88 ) ;
if ( V_93 -> V_3 & V_97 )
goto V_98;
F_85 (inode, before) {
struct V_1 * V_2 = * V_95 ;
if ( F_62 ( V_2 ) )
break;
if ( F_86 ( V_2 ) )
continue;
if ( V_37 != V_2 -> V_23 )
continue;
if ( V_93 -> V_8 == V_2 -> V_8 )
goto V_99;
V_96 = 1 ;
F_72 ( V_95 , & V_19 ) ;
break;
}
if ( V_93 -> V_8 == V_6 ) {
if ( ( V_93 -> V_3 & V_100 ) && ! V_96 )
error = - V_101 ;
goto V_99;
}
if ( V_96 ) {
F_59 ( & V_87 -> V_88 ) ;
F_87 () ;
F_58 ( & V_87 -> V_88 ) ;
}
V_98:
F_85 (inode, before) {
struct V_1 * V_2 = * V_95 ;
if ( F_62 ( V_2 ) )
break;
if ( F_86 ( V_2 ) )
continue;
if ( ! F_76 ( V_93 , V_2 ) )
continue;
error = - V_102 ;
if ( ! ( V_93 -> V_3 & V_103 ) )
goto V_99;
error = V_104 ;
F_64 ( V_2 , V_93 ) ;
goto V_99;
}
if ( V_93 -> V_3 & V_97 )
goto V_99;
F_21 ( V_94 , V_93 ) ;
F_67 ( V_95 , V_94 ) ;
V_94 = NULL ;
error = 0 ;
V_99:
F_59 ( & V_87 -> V_88 ) ;
if ( V_94 )
F_10 ( V_94 ) ;
F_16 ( & V_19 ) ;
return error ;
}
static int F_88 ( struct V_87 * V_87 , struct V_1 * V_93 , struct V_1 * V_105 )
{
struct V_1 * V_2 ;
struct V_1 * V_94 = NULL ;
struct V_1 * V_106 = NULL ;
struct V_1 * V_107 = NULL ;
struct V_1 * V_108 = NULL ;
struct V_1 * * V_95 ;
int error ;
bool V_109 = false ;
F_84 ( V_19 ) ;
if ( ! ( V_93 -> V_3 & V_97 ) &&
( V_93 -> V_8 != V_6 ||
V_93 -> V_24 != 0 || V_93 -> V_25 != V_42 ) ) {
V_94 = F_7 () ;
V_106 = F_7 () ;
}
F_58 ( & V_87 -> V_88 ) ;
if ( V_93 -> V_8 != V_6 ) {
F_85 (inode, before) {
V_2 = * V_95 ;
if ( ! F_62 ( V_2 ) )
continue;
if ( ! F_75 ( V_93 , V_2 ) )
continue;
if ( V_105 )
F_20 ( V_105 , V_2 ) ;
error = - V_102 ;
if ( ! ( V_93 -> V_3 & V_103 ) )
goto V_99;
error = - V_110 ;
F_58 ( & V_78 ) ;
if ( F_89 ( ! F_82 ( V_93 , V_2 ) ) ) {
error = V_104 ;
F_60 ( V_2 , V_93 ) ;
}
F_59 ( & V_78 ) ;
goto V_99;
}
}
error = 0 ;
if ( V_93 -> V_3 & V_97 )
goto V_99;
V_95 = & V_87 -> V_89 ;
while ( ( V_2 = * V_95 ) && ( ! F_62 ( V_2 ) ||
! F_40 ( V_93 , V_2 ) ) ) {
V_95 = & V_2 -> V_77 ;
}
while ( ( V_2 = * V_95 ) && F_40 ( V_93 , V_2 ) ) {
if ( V_93 -> V_8 == V_2 -> V_8 ) {
if ( V_2 -> V_25 < V_93 -> V_24 - 1 )
goto V_111;
if ( V_2 -> V_24 - 1 > V_93 -> V_25 )
break;
if ( V_2 -> V_24 > V_93 -> V_24 )
V_2 -> V_24 = V_93 -> V_24 ;
else
V_93 -> V_24 = V_2 -> V_24 ;
if ( V_2 -> V_25 < V_93 -> V_25 )
V_2 -> V_25 = V_93 -> V_25 ;
else
V_93 -> V_25 = V_2 -> V_25 ;
if ( V_109 ) {
F_72 ( V_95 , & V_19 ) ;
continue;
}
V_93 = V_2 ;
V_109 = true ;
}
else {
if ( V_2 -> V_25 < V_93 -> V_24 )
goto V_111;
if ( V_2 -> V_24 > V_93 -> V_25 )
break;
if ( V_93 -> V_8 == V_6 )
V_109 = true ;
if ( V_2 -> V_24 < V_93 -> V_24 )
V_107 = V_2 ;
if ( V_2 -> V_25 > V_93 -> V_25 ) {
V_108 = V_2 ;
break;
}
if ( V_2 -> V_24 >= V_93 -> V_24 ) {
if ( V_109 ) {
F_72 ( V_95 , & V_19 ) ;
continue;
}
error = - V_112 ;
if ( ! V_94 )
goto V_99;
F_21 ( V_94 , V_93 ) ;
V_93 = V_94 ;
V_94 = NULL ;
F_72 ( V_95 , & V_19 ) ;
F_67 ( V_95 , V_93 ) ;
V_109 = true ;
}
}
V_111:
V_95 = & V_2 -> V_77 ;
}
error = - V_112 ;
if ( V_108 && V_107 == V_108 && ! V_106 )
goto V_99;
error = 0 ;
if ( ! V_109 ) {
if ( V_93 -> V_8 == V_6 ) {
if ( V_93 -> V_3 & V_100 )
error = - V_101 ;
goto V_99;
}
if ( ! V_94 ) {
error = - V_112 ;
goto V_99;
}
F_21 ( V_94 , V_93 ) ;
F_67 ( V_95 , V_94 ) ;
V_94 = NULL ;
}
if ( V_108 ) {
if ( V_107 == V_108 ) {
V_107 = V_106 ;
V_106 = NULL ;
F_21 ( V_107 , V_108 ) ;
F_67 ( V_95 , V_107 ) ;
}
V_108 -> V_24 = V_93 -> V_25 + 1 ;
F_65 ( V_108 ) ;
}
if ( V_107 ) {
V_107 -> V_25 = V_93 -> V_24 - 1 ;
F_65 ( V_107 ) ;
}
V_99:
F_59 ( & V_87 -> V_88 ) ;
if ( V_94 )
F_10 ( V_94 ) ;
if ( V_106 )
F_10 ( V_106 ) ;
F_16 ( & V_19 ) ;
return error ;
}
int F_90 ( struct V_36 * V_37 , struct V_1 * V_2 ,
struct V_1 * V_105 )
{
return F_88 ( F_29 ( V_37 ) , V_2 , V_105 ) ;
}
int F_91 ( struct V_36 * V_37 , struct V_1 * V_2 )
{
int error ;
F_92 () ;
for (; ; ) {
error = F_90 ( V_37 , V_2 , NULL ) ;
if ( error != V_104 )
break;
error = F_93 ( V_2 -> V_11 , ! V_2 -> V_77 ) ;
if ( ! error )
continue;
F_57 ( V_2 ) ;
break;
}
return error ;
}
int F_94 ( struct V_36 * V_36 )
{
struct V_87 * V_87 = F_29 ( V_36 ) ;
struct V_1 * V_2 ;
F_58 ( & V_87 -> V_88 ) ;
for ( V_2 = V_87 -> V_89 ; V_2 != NULL ; V_2 = V_2 -> V_77 ) {
if ( ! F_62 ( V_2 ) )
continue;
if ( V_2 -> V_21 != V_39 -> V_53 &&
V_2 -> V_21 != V_36 )
break;
}
F_59 ( & V_87 -> V_88 ) ;
return V_2 ? - V_102 : 0 ;
}
int F_95 ( int V_113 , struct V_87 * V_87 ,
struct V_36 * V_37 , T_1 V_114 ,
T_2 V_115 )
{
struct V_1 V_2 ;
int error ;
bool V_116 = false ;
F_19 ( & V_2 ) ;
V_2 . V_22 = V_39 -> V_40 ;
V_2 . V_23 = V_37 ;
V_2 . V_3 = V_54 | V_97 ;
if ( V_37 && ! ( V_37 -> V_117 & V_118 ) )
V_116 = true ;
V_2 . V_8 = ( V_113 == V_119 ) ? V_33 : V_7 ;
V_2 . V_24 = V_114 ;
V_2 . V_25 = V_114 + V_115 - 1 ;
for (; ; ) {
if ( V_37 ) {
V_2 . V_21 = V_37 ;
V_2 . V_3 &= ~ V_103 ;
error = F_88 ( V_87 , & V_2 , NULL ) ;
if ( ! error )
break;
}
if ( V_116 )
V_2 . V_3 |= V_103 ;
V_2 . V_21 = V_39 -> V_53 ;
error = F_88 ( V_87 , & V_2 , NULL ) ;
if ( error != V_104 )
break;
error = F_93 ( V_2 . V_11 , ! V_2 . V_77 ) ;
if ( ! error ) {
if ( F_96 ( V_87 ) )
continue;
}
F_57 ( & V_2 ) ;
break;
}
return error ;
}
static void F_97 ( struct V_1 * V_2 , int V_120 )
{
switch ( V_120 ) {
case V_6 :
V_2 -> V_3 &= ~ V_4 ;
case V_7 :
V_2 -> V_3 &= ~ V_5 ;
}
}
int F_98 ( struct V_1 * * V_95 , int V_120 , struct V_18 * V_19 )
{
struct V_1 * V_2 = * V_95 ;
int error = F_26 ( V_2 , V_120 ) ;
if ( error )
return error ;
F_97 ( V_2 , V_120 ) ;
F_65 ( V_2 ) ;
if ( V_120 == V_6 ) {
struct V_36 * V_37 = V_2 -> V_23 ;
F_99 ( V_37 ) ;
V_37 -> V_121 . V_122 = 0 ;
F_100 ( 0 , V_2 -> V_23 , 0 , & V_2 -> V_58 ) ;
if ( V_2 -> V_58 != NULL ) {
F_101 ( V_123 L_1 , V_2 -> V_58 ) ;
V_2 -> V_58 = NULL ;
}
F_72 ( V_95 , V_19 ) ;
}
return 0 ;
}
static bool F_102 ( unsigned long V_124 )
{
if ( ! V_124 )
return false ;
return F_103 ( V_125 , V_124 ) ;
}
static void F_104 ( struct V_87 * V_87 , struct V_18 * V_19 )
{
struct V_1 * * V_95 ;
struct V_1 * V_2 ;
F_105 ( & V_87 -> V_88 ) ;
V_95 = & V_87 -> V_89 ;
while ( ( V_2 = * V_95 ) && F_86 ( V_2 ) && F_1 ( V_2 ) ) {
F_106 ( V_87 , V_2 ) ;
if ( F_102 ( V_2 -> V_126 ) )
F_98 ( V_95 , V_7 , V_19 ) ;
if ( F_102 ( V_2 -> V_127 ) )
F_98 ( V_95 , V_6 , V_19 ) ;
if ( V_2 == * V_95 )
V_95 = & V_2 -> V_77 ;
}
}
static bool F_107 ( struct V_1 * V_128 , struct V_1 * V_129 )
{
if ( ( V_129 -> V_3 & V_130 ) && ( V_128 -> V_3 & V_66 ) )
return false ;
return F_74 ( V_129 , V_128 ) ;
}
static bool
F_108 ( struct V_87 * V_87 , struct V_1 * V_129 )
{
struct V_1 * V_2 ;
F_105 ( & V_87 -> V_88 ) ;
for ( V_2 = V_87 -> V_89 ; V_2 && F_86 ( V_2 ) ; V_2 = V_2 -> V_77 ) {
if ( F_107 ( V_2 , V_129 ) )
return true ;
}
return false ;
}
int F_109 ( struct V_87 * V_87 , unsigned int V_131 , unsigned int type )
{
int error = 0 ;
struct V_1 * V_94 ;
struct V_1 * V_2 , * * V_95 ;
unsigned long V_132 ;
int V_133 = ( V_131 & V_134 ) != V_135 ;
F_84 ( V_19 ) ;
V_94 = F_38 ( NULL , V_133 ? V_33 : V_7 ) ;
if ( F_110 ( V_94 ) )
return F_111 ( V_94 ) ;
V_94 -> V_3 = type ;
F_58 ( & V_87 -> V_88 ) ;
F_104 ( V_87 , & V_19 ) ;
if ( ! F_108 ( V_87 , V_94 ) )
goto V_99;
V_132 = 0 ;
if ( V_136 > 0 ) {
V_132 = V_125 + V_136 * V_137 ;
if ( V_132 == 0 )
V_132 ++ ;
}
for ( V_95 = & V_87 -> V_89 ;
( ( V_2 = * V_95 ) != NULL ) && F_86 ( V_2 ) ;
V_95 = & V_2 -> V_77 ) {
if ( ! F_107 ( V_2 , V_94 ) )
continue;
if ( V_133 ) {
if ( V_2 -> V_3 & V_4 )
continue;
V_2 -> V_3 |= V_4 ;
V_2 -> V_127 = V_132 ;
} else {
if ( F_1 ( V_87 -> V_89 ) )
continue;
V_2 -> V_3 |= V_5 ;
V_2 -> V_126 = V_132 ;
}
if ( V_2 -> V_16 -> V_138 ( V_2 ) )
F_72 ( V_95 , & V_19 ) ;
}
V_2 = V_87 -> V_89 ;
if ( ! V_2 || ! F_86 ( V_2 ) )
goto V_99;
if ( V_131 & V_118 ) {
F_112 ( V_87 , V_94 ) ;
error = - V_139 ;
goto V_99;
}
V_140:
V_132 = V_87 -> V_89 -> V_127 ;
if ( V_132 != 0 )
V_132 -= V_125 ;
if ( V_132 == 0 )
V_132 ++ ;
F_64 ( V_87 -> V_89 , V_94 ) ;
F_113 ( V_87 , V_94 ) ;
F_59 ( & V_87 -> V_88 ) ;
F_16 ( & V_19 ) ;
error = F_114 ( V_94 -> V_11 ,
! V_94 -> V_77 , V_132 ) ;
F_58 ( & V_87 -> V_88 ) ;
F_115 ( V_87 , V_94 ) ;
F_57 ( V_94 ) ;
if ( error >= 0 ) {
if ( error == 0 )
F_104 ( V_87 , & V_19 ) ;
if ( F_108 ( V_87 , V_94 ) )
goto V_140;
error = 0 ;
}
V_99:
F_59 ( & V_87 -> V_88 ) ;
F_16 ( & V_19 ) ;
F_10 ( V_94 ) ;
return error ;
}
void F_116 ( struct V_87 * V_87 , struct V_141 * time )
{
bool V_142 = false ;
struct V_1 * V_56 ;
if ( V_87 -> V_89 ) {
F_58 ( & V_87 -> V_88 ) ;
V_56 = V_87 -> V_89 ;
if ( V_56 && F_86 ( V_56 ) && ( V_56 -> V_8 == V_33 ) )
V_142 = true ;
F_59 ( & V_87 -> V_88 ) ;
}
if ( V_142 )
* time = F_117 ( V_87 -> V_143 ) ;
else
* time = V_87 -> V_144 ;
}
int F_118 ( struct V_36 * V_37 )
{
struct V_1 * V_2 ;
struct V_87 * V_87 = F_29 ( V_37 ) ;
int type = V_6 ;
F_84 ( V_19 ) ;
F_58 ( & V_87 -> V_88 ) ;
F_104 ( F_29 ( V_37 ) , & V_19 ) ;
for ( V_2 = F_29 ( V_37 ) -> V_89 ; V_2 && F_86 ( V_2 ) ;
V_2 = V_2 -> V_77 ) {
if ( V_2 -> V_23 == V_37 ) {
type = F_2 ( V_2 ) ;
break;
}
}
F_59 ( & V_87 -> V_88 ) ;
F_16 ( & V_19 ) ;
return type ;
}
static int
F_119 ( const struct V_145 * V_145 , const long V_120 )
{
int V_146 = 0 ;
struct V_87 * V_87 = V_145 -> V_147 ;
if ( ( V_120 == V_7 ) && ( F_120 ( & V_87 -> V_148 ) > 0 ) )
return - V_102 ;
if ( ( V_120 == V_33 ) && ( ( F_121 ( V_145 ) > 1 ) ||
( F_120 ( & V_87 -> V_149 ) > 1 ) ) )
V_146 = - V_102 ;
return V_146 ;
}
static int
F_122 ( struct V_36 * V_37 , long V_120 , struct V_1 * * V_150 , void * * V_61 )
{
struct V_1 * V_2 , * * V_95 , * * V_151 = NULL , * V_128 ;
struct V_145 * V_145 = V_37 -> V_152 . V_145 ;
struct V_87 * V_87 = V_145 -> V_147 ;
bool V_153 = ( * V_150 ) -> V_3 & V_130 ;
int error ;
F_84 ( V_19 ) ;
V_128 = * V_150 ;
F_123 ( V_87 , V_128 ) ;
if ( V_153 && ! F_124 ( & V_87 -> V_154 ) )
return - V_102 ;
if ( V_153 && V_120 == V_33 ) {
F_125 ( & V_87 -> V_154 ) ;
F_22 ( 1 ) ;
return - V_35 ;
}
F_58 ( & V_87 -> V_88 ) ;
F_104 ( V_87 , & V_19 ) ;
error = F_119 ( V_145 , V_120 ) ;
if ( error )
goto V_99;
error = - V_102 ;
for ( V_95 = & V_87 -> V_89 ;
( ( V_2 = * V_95 ) != NULL ) && F_86 ( V_2 ) ;
V_95 = & V_2 -> V_77 ) {
if ( V_2 -> V_23 == V_37 ) {
V_151 = V_95 ;
continue;
}
if ( V_120 == V_33 )
goto V_99;
if ( V_2 -> V_3 & V_4 )
goto V_99;
}
if ( V_151 != NULL ) {
V_128 = * V_151 ;
error = V_128 -> V_16 -> V_155 ( V_151 , V_120 , & V_19 ) ;
if ( error )
goto V_99;
goto V_156;
}
error = - V_35 ;
if ( ! V_157 )
goto V_99;
F_67 ( V_95 , V_128 ) ;
F_126 () ;
error = F_119 ( V_145 , V_120 ) ;
if ( error )
goto V_158;
V_156:
if ( V_128 -> V_16 -> V_159 )
V_128 -> V_16 -> V_159 ( V_128 , V_61 ) ;
V_99:
F_59 ( & V_87 -> V_88 ) ;
F_16 ( & V_19 ) ;
if ( V_153 )
F_125 ( & V_87 -> V_154 ) ;
if ( ! error && ! V_151 )
* V_150 = NULL ;
return error ;
V_158:
F_70 ( V_95 ) ;
goto V_99;
}
static int F_127 ( struct V_36 * V_37 )
{
int error = - V_102 ;
struct V_1 * V_2 , * * V_95 ;
struct V_145 * V_145 = V_37 -> V_152 . V_145 ;
struct V_87 * V_87 = V_145 -> V_147 ;
F_84 ( V_19 ) ;
F_58 ( & V_87 -> V_88 ) ;
F_104 ( V_87 , & V_19 ) ;
for ( V_95 = & V_87 -> V_89 ;
( ( V_2 = * V_95 ) != NULL ) && F_86 ( V_2 ) ;
V_95 = & V_2 -> V_77 ) {
if ( V_2 -> V_23 == V_37 )
break;
}
F_128 ( V_87 , V_2 ) ;
if ( V_2 && F_86 ( V_2 ) )
error = V_2 -> V_16 -> V_155 ( V_95 , V_6 , & V_19 ) ;
F_59 ( & V_87 -> V_88 ) ;
F_16 ( & V_19 ) ;
return error ;
}
int F_129 ( struct V_36 * V_37 , long V_120 , struct V_1 * * V_150 ,
void * * V_61 )
{
struct V_145 * V_145 = V_37 -> V_152 . V_145 ;
struct V_87 * V_87 = V_145 -> V_147 ;
int error ;
if ( ( ! F_130 ( F_131 () , V_87 -> V_160 ) ) && ! F_132 ( V_161 ) )
return - V_162 ;
if ( ! F_133 ( V_87 -> V_163 ) )
return - V_35 ;
error = F_134 ( V_37 , V_120 ) ;
if ( error )
return error ;
switch ( V_120 ) {
case V_6 :
return F_127 ( V_37 ) ;
case V_7 :
case V_33 :
if ( ! ( * V_150 ) -> V_16 -> V_138 ) {
F_22 ( 1 ) ;
return - V_112 ;
}
return F_122 ( V_37 , V_120 , V_150 , V_61 ) ;
default:
return - V_35 ;
}
}
int
F_135 ( struct V_36 * V_37 , long V_120 , struct V_1 * * V_128 , void * * V_61 )
{
if ( V_37 -> V_164 -> V_165 )
return V_37 -> V_164 -> V_165 ( V_37 , V_120 , V_128 , V_61 ) ;
else
return F_129 ( V_37 , V_120 , V_128 , V_61 ) ;
}
static int F_136 ( unsigned int V_166 , struct V_36 * V_37 , long V_120 )
{
struct V_1 * V_2 ;
struct V_62 * V_20 ;
int error ;
V_2 = F_38 ( V_37 , V_120 ) ;
if ( F_110 ( V_2 ) )
return F_111 ( V_2 ) ;
V_20 = F_137 () ;
if ( ! V_20 ) {
F_10 ( V_2 ) ;
return - V_38 ;
}
V_20 -> V_64 = V_166 ;
error = F_135 ( V_37 , V_120 , & V_2 , ( void * * ) & V_20 ) ;
if ( V_2 )
F_10 ( V_2 ) ;
if ( V_20 )
F_138 ( V_20 ) ;
return error ;
}
int F_139 ( unsigned int V_166 , struct V_36 * V_37 , long V_120 )
{
if ( V_120 == V_6 )
return F_135 ( V_37 , V_6 , NULL , NULL ) ;
return F_136 ( V_166 , V_37 , V_120 ) ;
}
int F_140 ( struct V_36 * V_37 , struct V_1 * V_2 )
{
int error ;
F_92 () ;
for (; ; ) {
error = F_83 ( V_37 , V_2 ) ;
if ( error != V_104 )
break;
error = F_93 ( V_2 -> V_11 , ! V_2 -> V_77 ) ;
if ( ! error )
continue;
F_57 ( V_2 ) ;
break;
}
return error ;
}
int F_141 ( struct V_36 * V_37 , struct V_1 * V_2 )
{
if ( V_37 -> V_164 -> V_167 )
return V_37 -> V_164 -> V_167 ( V_37 , V_168 , V_2 ) ;
F_78 ( V_37 , V_2 ) ;
return 0 ;
}
static int F_142 ( struct V_56 * V_56 , struct V_1 * V_2 )
{
V_56 -> V_169 = F_63 ( V_2 ) ? - 1 : V_2 -> V_22 ;
#if V_170 == 32
if ( V_2 -> V_24 > V_171 )
return - V_51 ;
if ( V_2 -> V_25 != V_42 && V_2 -> V_25 > V_171 )
return - V_51 ;
#endif
V_56 -> V_50 = V_2 -> V_24 ;
V_56 -> V_52 = V_2 -> V_25 == V_42 ? 0 :
V_2 -> V_25 - V_2 -> V_24 + 1 ;
V_56 -> V_45 = 0 ;
V_56 -> V_55 = V_2 -> V_8 ;
return 0 ;
}
static void F_143 ( struct V_43 * V_56 , struct V_1 * V_2 )
{
V_56 -> V_169 = F_63 ( V_2 ) ? - 1 : V_2 -> V_22 ;
V_56 -> V_50 = V_2 -> V_24 ;
V_56 -> V_52 = V_2 -> V_25 == V_42 ? 0 :
V_2 -> V_25 - V_2 -> V_24 + 1 ;
V_56 -> V_45 = 0 ;
V_56 -> V_55 = V_2 -> V_8 ;
}
int F_144 ( struct V_36 * V_37 , unsigned int V_28 , struct V_56 T_3 * V_44 )
{
struct V_1 V_1 ;
struct V_56 V_56 ;
int error ;
error = - V_172 ;
if ( F_145 ( & V_56 , V_44 , sizeof( V_56 ) ) )
goto V_99;
error = - V_35 ;
if ( ( V_56 . V_55 != V_7 ) && ( V_56 . V_55 != V_33 ) )
goto V_99;
error = F_30 ( V_37 , & V_1 , & V_56 ) ;
if ( error )
goto V_99;
if ( V_28 == V_173 ) {
error = - V_35 ;
if ( V_56 . V_169 != 0 )
goto V_99;
V_28 = V_168 ;
V_1 . V_3 |= V_174 ;
V_1 . V_21 = V_37 ;
}
error = F_141 ( V_37 , & V_1 ) ;
if ( error )
goto V_99;
V_56 . V_55 = V_1 . V_8 ;
if ( V_1 . V_8 != V_6 ) {
error = F_142 ( & V_56 , & V_1 ) ;
if ( error )
goto V_175;
}
error = - V_172 ;
if ( ! F_146 ( V_44 , & V_56 , sizeof( V_56 ) ) )
error = 0 ;
V_175:
F_9 ( & V_1 ) ;
V_99:
return error ;
}
int F_147 ( struct V_36 * V_37 , unsigned int V_28 , struct V_1 * V_2 , struct V_1 * V_176 )
{
if ( V_37 -> V_164 -> V_167 )
return V_37 -> V_164 -> V_167 ( V_37 , V_28 , V_2 ) ;
else
return F_90 ( V_37 , V_2 , V_176 ) ;
}
static int F_148 ( struct V_36 * V_37 , unsigned int V_28 ,
struct V_1 * V_2 )
{
int error ;
error = F_134 ( V_37 , V_2 -> V_8 ) ;
if ( error )
return error ;
for (; ; ) {
error = F_147 ( V_37 , V_28 , V_2 , NULL ) ;
if ( error != V_104 )
break;
error = F_93 ( V_2 -> V_11 , ! V_2 -> V_77 ) ;
if ( ! error )
continue;
F_57 ( V_2 ) ;
break;
}
return error ;
}
static int
F_149 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_8 ) {
case V_7 :
if ( ! ( V_2 -> V_23 -> V_177 & V_178 ) )
return - V_179 ;
break;
case V_33 :
if ( ! ( V_2 -> V_23 -> V_177 & V_180 ) )
return - V_179 ;
}
return 0 ;
}
int F_150 ( unsigned int V_166 , struct V_36 * V_37 , unsigned int V_28 ,
struct V_56 T_3 * V_44 )
{
struct V_1 * V_1 = F_7 () ;
struct V_56 V_56 ;
struct V_87 * V_87 ;
struct V_36 * V_181 ;
int error ;
if ( V_1 == NULL )
return - V_112 ;
error = - V_172 ;
if ( F_145 ( & V_56 , V_44 , sizeof( V_56 ) ) )
goto V_99;
V_87 = F_29 ( V_37 ) ;
if ( F_151 ( V_87 ) && F_152 ( V_37 -> V_182 ) ) {
error = - V_102 ;
goto V_99;
}
V_183:
error = F_30 ( V_37 , V_1 , & V_56 ) ;
if ( error )
goto V_99;
error = F_149 ( V_1 ) ;
if ( error )
goto V_99;
switch ( V_28 ) {
case V_184 :
error = - V_35 ;
if ( V_56 . V_169 != 0 )
goto V_99;
V_28 = V_185 ;
V_1 -> V_3 |= V_174 ;
V_1 -> V_21 = V_37 ;
break;
case V_186 :
error = - V_35 ;
if ( V_56 . V_169 != 0 )
goto V_99;
V_28 = V_187 ;
V_1 -> V_3 |= V_174 ;
V_1 -> V_21 = V_37 ;
case V_187 :
V_1 -> V_3 |= V_103 ;
}
error = F_148 ( V_37 , V_28 , V_1 ) ;
F_58 ( & V_39 -> V_53 -> V_1 ) ;
V_181 = F_153 ( V_166 ) ;
F_59 ( & V_39 -> V_53 -> V_1 ) ;
if ( ! error && V_181 != V_37 && V_56 . V_55 != V_6 ) {
V_56 . V_55 = V_6 ;
goto V_183;
}
V_99:
F_10 ( V_1 ) ;
return error ;
}
int F_154 ( struct V_36 * V_37 , unsigned int V_28 , struct V_43 T_3 * V_44 )
{
struct V_1 V_1 ;
struct V_43 V_56 ;
int error ;
error = - V_172 ;
if ( F_145 ( & V_56 , V_44 , sizeof( V_56 ) ) )
goto V_99;
error = - V_35 ;
if ( ( V_56 . V_55 != V_7 ) && ( V_56 . V_55 != V_33 ) )
goto V_99;
error = F_27 ( V_37 , & V_1 , & V_56 ) ;
if ( error )
goto V_99;
if ( V_28 == V_173 ) {
error = - V_35 ;
if ( V_56 . V_169 != 0 )
goto V_99;
V_28 = V_188 ;
V_1 . V_3 |= V_174 ;
V_1 . V_21 = V_37 ;
}
error = F_141 ( V_37 , & V_1 ) ;
if ( error )
goto V_99;
V_56 . V_55 = V_1 . V_8 ;
if ( V_1 . V_8 != V_6 )
F_143 ( & V_56 , & V_1 ) ;
error = - V_172 ;
if ( ! F_146 ( V_44 , & V_56 , sizeof( V_56 ) ) )
error = 0 ;
F_9 ( & V_1 ) ;
V_99:
return error ;
}
int F_155 ( unsigned int V_166 , struct V_36 * V_37 , unsigned int V_28 ,
struct V_43 T_3 * V_44 )
{
struct V_1 * V_1 = F_7 () ;
struct V_43 V_56 ;
struct V_87 * V_87 ;
struct V_36 * V_181 ;
int error ;
if ( V_1 == NULL )
return - V_112 ;
error = - V_172 ;
if ( F_145 ( & V_56 , V_44 , sizeof( V_56 ) ) )
goto V_99;
V_87 = F_29 ( V_37 ) ;
if ( F_151 ( V_87 ) && F_152 ( V_37 -> V_182 ) ) {
error = - V_102 ;
goto V_99;
}
V_183:
error = F_27 ( V_37 , V_1 , & V_56 ) ;
if ( error )
goto V_99;
error = F_149 ( V_1 ) ;
if ( error )
goto V_99;
switch ( V_28 ) {
case V_184 :
error = - V_35 ;
if ( V_56 . V_169 != 0 )
goto V_99;
V_28 = V_189 ;
V_1 -> V_3 |= V_174 ;
V_1 -> V_21 = V_37 ;
break;
case V_186 :
error = - V_35 ;
if ( V_56 . V_169 != 0 )
goto V_99;
V_28 = V_190 ;
V_1 -> V_3 |= V_174 ;
V_1 -> V_21 = V_37 ;
case V_190 :
V_1 -> V_3 |= V_103 ;
}
error = F_148 ( V_37 , V_28 , V_1 ) ;
F_58 ( & V_39 -> V_53 -> V_1 ) ;
V_181 = F_153 ( V_166 ) ;
F_59 ( & V_39 -> V_53 -> V_1 ) ;
if ( ! error && V_181 != V_37 && V_56 . V_55 != V_6 ) {
V_56 . V_55 = V_6 ;
goto V_183;
}
V_99:
F_10 ( V_1 ) ;
return error ;
}
void F_156 ( struct V_36 * V_37 , T_4 V_191 )
{
struct V_1 V_167 ;
if ( ! F_29 ( V_37 ) -> V_89 )
return;
V_167 . V_8 = V_6 ;
V_167 . V_3 = V_54 | V_192 ;
V_167 . V_24 = 0 ;
V_167 . V_25 = V_42 ;
V_167 . V_21 = V_191 ;
V_167 . V_22 = V_39 -> V_40 ;
V_167 . V_23 = V_37 ;
V_167 . V_14 = NULL ;
V_167 . V_16 = NULL ;
F_147 ( V_37 , V_185 , & V_167 , NULL ) ;
if ( V_167 . V_14 && V_167 . V_14 -> V_15 )
V_167 . V_14 -> V_15 ( & V_167 ) ;
}
void F_157 ( struct V_36 * V_37 )
{
struct V_87 * V_87 = F_29 ( V_37 ) ;
struct V_1 * V_2 ;
struct V_1 * * V_95 ;
F_84 ( V_19 ) ;
if ( ! V_87 -> V_89 )
return;
F_156 ( V_37 , V_37 ) ;
if ( V_37 -> V_164 -> V_56 ) {
struct V_1 V_2 = {
. V_21 = V_37 ,
. V_22 = V_39 -> V_40 ,
. V_23 = V_37 ,
. V_3 = V_41 ,
. V_8 = V_6 ,
. V_25 = V_42 ,
} ;
V_37 -> V_164 -> V_56 ( V_37 , V_187 , & V_2 ) ;
if ( V_2 . V_14 && V_2 . V_14 -> V_15 )
V_2 . V_14 -> V_15 ( & V_2 ) ;
}
F_58 ( & V_87 -> V_88 ) ;
V_95 = & V_87 -> V_89 ;
while ( ( V_2 = * V_95 ) != NULL ) {
if ( V_2 -> V_23 == V_37 ) {
if ( F_86 ( V_2 ) ) {
F_98 ( V_95 , V_6 , & V_19 ) ;
continue;
}
F_158 ( ! F_77 ( V_2 ) ,
L_2 ,
F_159 ( V_87 -> V_143 -> V_193 ) ,
F_160 ( V_87 -> V_143 -> V_193 ) , V_87 -> V_194 ,
V_2 -> V_8 , V_2 -> V_3 ,
V_2 -> V_24 , V_2 -> V_25 ) ;
F_72 ( V_95 , & V_19 ) ;
continue;
}
V_95 = & V_2 -> V_77 ;
}
F_59 ( & V_87 -> V_88 ) ;
F_16 ( & V_19 ) ;
}
int
F_161 ( struct V_1 * V_75 )
{
int V_195 = 0 ;
F_58 ( & V_78 ) ;
if ( V_75 -> V_77 )
F_56 ( V_75 ) ;
else
V_195 = - V_101 ;
F_59 ( & V_78 ) ;
return V_195 ;
}
int F_162 ( struct V_36 * V_37 , struct V_1 * V_2 )
{
if ( V_37 -> V_164 -> V_167 )
return V_37 -> V_164 -> V_167 ( V_37 , V_196 , V_2 ) ;
return 0 ;
}
static void F_163 ( struct V_197 * V_181 , struct V_1 * V_2 ,
T_1 V_198 , char * V_199 )
{
struct V_87 * V_87 = NULL ;
unsigned int V_22 ;
if ( V_2 -> V_82 )
V_22 = F_79 ( V_2 -> V_82 ) ;
else
V_22 = V_2 -> V_22 ;
if ( V_2 -> V_23 != NULL )
V_87 = F_29 ( V_2 -> V_23 ) ;
F_164 ( V_181 , L_3 , V_198 , V_199 ) ;
if ( F_62 ( V_2 ) ) {
if ( V_2 -> V_3 & V_97 )
F_165 ( V_181 , L_4 ) ;
else if ( F_63 ( V_2 ) )
F_165 ( V_181 , L_5 ) ;
else
F_165 ( V_181 , L_6 ) ;
F_164 ( V_181 , L_7 ,
( V_87 == NULL ) ? L_8 :
F_151 ( V_87 ) ? L_9 : L_10 ) ;
} else if ( F_77 ( V_2 ) ) {
if ( V_2 -> V_8 & V_29 ) {
F_165 ( V_181 , L_11 ) ;
} else {
F_165 ( V_181 , L_12 ) ;
}
} else if ( F_86 ( V_2 ) ) {
if ( V_2 -> V_3 & V_130 )
F_165 ( V_181 , L_13 ) ;
else
F_165 ( V_181 , L_14 ) ;
if ( F_1 ( V_2 ) )
F_165 ( V_181 , L_15 ) ;
else if ( V_2 -> V_23 )
F_165 ( V_181 , L_16 ) ;
else
F_165 ( V_181 , L_17 ) ;
} else {
F_165 ( V_181 , L_18 ) ;
}
if ( V_2 -> V_8 & V_29 ) {
F_164 ( V_181 , L_19 ,
( V_2 -> V_8 & V_200 )
? ( V_2 -> V_8 & V_201 ) ? L_20 : L_21
: ( V_2 -> V_8 & V_201 ) ? L_22 : L_23 ) ;
} else {
F_164 ( V_181 , L_19 ,
( F_1 ( V_2 ) )
? ( V_2 -> V_8 == V_6 ) ? L_24 : L_21
: ( V_2 -> V_8 == V_33 ) ? L_22 : L_21 ) ;
}
if ( V_87 ) {
#ifdef F_166
F_164 ( V_181 , L_25 , V_22 ,
V_87 -> V_143 -> V_202 , V_87 -> V_194 ) ;
#else
F_164 ( V_181 , L_26 , V_22 ,
F_159 ( V_87 -> V_143 -> V_193 ) ,
F_160 ( V_87 -> V_143 -> V_193 ) , V_87 -> V_194 ) ;
#endif
} else {
F_164 ( V_181 , L_27 , V_22 ) ;
}
if ( F_62 ( V_2 ) ) {
if ( V_2 -> V_25 == V_42 )
F_164 ( V_181 , L_28 , V_2 -> V_24 ) ;
else
F_164 ( V_181 , L_29 , V_2 -> V_24 , V_2 -> V_25 ) ;
} else {
F_165 ( V_181 , L_30 ) ;
}
}
static int F_167 ( struct V_197 * V_181 , void * V_203 )
{
struct V_204 * V_205 = V_181 -> V_206 ;
struct V_1 * V_2 , * V_207 ;
V_2 = F_168 ( V_203 , struct V_1 , V_9 ) ;
F_163 ( V_181 , V_2 , V_205 -> V_208 , L_31 ) ;
F_169 (bfl, &fl->fl_block, fl_block)
F_163 ( V_181 , V_207 , V_205 -> V_208 , L_32 ) ;
return 0 ;
}
static void * F_170 ( struct V_197 * V_181 , T_1 * V_81 )
__acquires( &blocked_lock_lock
static void * F_171 ( struct V_197 * V_181 , void * V_203 , T_1 * V_81 )
{
struct V_204 * V_205 = V_181 -> V_206 ;
++ V_205 -> V_208 ;
return F_172 ( V_203 , & V_73 , & V_205 -> V_209 , V_81 ) ;
}
static void F_173 ( struct V_197 * V_181 , void * V_203 )
__releases( &blocked_lock_lock
static int F_174 ( struct V_87 * V_87 , struct V_36 * V_37 )
{
return F_175 ( V_37 , & V_210 ,
sizeof( struct V_204 ) ) ;
}
static int T_5 F_176 ( void )
{
F_177 ( L_33 , 0 , NULL , & V_211 ) ;
return 0 ;
}
static int T_5 F_178 ( void )
{
int V_91 ;
V_12 = F_179 ( L_34 ,
sizeof( struct V_1 ) , 0 , V_212 , NULL ) ;
F_180 ( & V_71 , L_35 ) ;
F_181 (i)
F_182 ( F_183 ( & V_73 , V_91 ) ) ;
return 0 ;
}
