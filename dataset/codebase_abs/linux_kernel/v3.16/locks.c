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
V_2 -> V_16 = NULL ;
}
void F_10 ( struct V_1 * V_2 )
{
F_11 ( F_12 ( & V_2 -> V_11 ) ) ;
F_11 ( ! F_13 ( & V_2 -> V_10 ) ) ;
F_11 ( ! F_14 ( & V_2 -> V_9 ) ) ;
F_9 ( V_2 ) ;
F_15 ( V_12 , V_2 ) ;
}
void F_16 ( struct V_1 * V_2 )
{
memset ( V_2 , 0 , sizeof( struct V_1 ) ) ;
F_3 ( V_2 ) ;
}
static void F_17 ( struct V_1 * V_17 , struct V_1 * V_2 )
{
if ( V_2 -> V_14 ) {
if ( V_2 -> V_14 -> V_18 )
V_2 -> V_14 -> V_18 ( V_17 , V_2 ) ;
V_17 -> V_14 = V_2 -> V_14 ;
}
if ( V_2 -> V_16 )
V_17 -> V_16 = V_2 -> V_16 ;
}
void F_18 ( struct V_1 * V_17 , const struct V_1 * V_2 )
{
V_17 -> V_19 = V_2 -> V_19 ;
V_17 -> V_20 = V_2 -> V_20 ;
V_17 -> V_21 = NULL ;
V_17 -> V_3 = V_2 -> V_3 ;
V_17 -> V_8 = V_2 -> V_8 ;
V_17 -> V_22 = V_2 -> V_22 ;
V_17 -> V_23 = V_2 -> V_23 ;
V_17 -> V_14 = NULL ;
V_17 -> V_16 = NULL ;
}
void F_19 ( struct V_1 * V_17 , struct V_1 * V_2 )
{
F_9 ( V_17 ) ;
F_18 ( V_17 , V_2 ) ;
V_17 -> V_21 = V_2 -> V_21 ;
V_17 -> V_14 = V_2 -> V_14 ;
V_17 -> V_16 = V_2 -> V_16 ;
F_17 ( V_17 , V_2 ) ;
}
static inline int F_20 ( int V_24 ) {
if ( V_24 & V_25 )
return V_24 & ( V_25 | V_26 ) ;
switch ( V_24 ) {
case V_27 :
return V_7 ;
case V_28 :
return V_29 ;
case V_30 :
return V_6 ;
}
return - V_31 ;
}
static int F_21 ( struct V_32 * V_33 , struct V_1 * * V_34 ,
unsigned int V_24 )
{
struct V_1 * V_2 ;
int type = F_20 ( V_24 ) ;
if ( type < 0 )
return type ;
V_2 = F_7 () ;
if ( V_2 == NULL )
return - V_35 ;
V_2 -> V_21 = V_33 ;
V_2 -> V_19 = ( V_36 ) V_33 ;
V_2 -> V_20 = V_37 -> V_38 ;
V_2 -> V_3 = V_39 ;
V_2 -> V_8 = type ;
V_2 -> V_23 = V_40 ;
* V_34 = V_2 ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 , long type )
{
switch ( type ) {
case V_7 :
case V_29 :
case V_6 :
V_2 -> V_8 = type ;
break;
default:
return - V_31 ;
}
return 0 ;
}
static int F_23 ( struct V_32 * V_33 , struct V_1 * V_2 ,
struct V_41 * V_42 )
{
switch ( V_42 -> V_43 ) {
case V_44 :
V_2 -> V_22 = 0 ;
break;
case V_45 :
V_2 -> V_22 = V_33 -> V_46 ;
break;
case V_47 :
V_2 -> V_22 = F_24 ( F_25 ( V_33 ) ) ;
break;
default:
return - V_31 ;
}
if ( V_42 -> V_48 > V_40 - V_2 -> V_22 )
return - V_49 ;
V_2 -> V_22 += V_42 -> V_48 ;
if ( V_2 -> V_22 < 0 )
return - V_31 ;
if ( V_42 -> V_50 > 0 ) {
if ( V_42 -> V_50 - 1 > V_40 - V_2 -> V_22 )
return - V_49 ;
V_2 -> V_23 = V_2 -> V_22 + V_42 -> V_50 - 1 ;
} else if ( V_42 -> V_50 < 0 ) {
if ( V_2 -> V_22 + V_42 -> V_50 < 0 )
return - V_31 ;
V_2 -> V_23 = V_2 -> V_22 - 1 ;
V_2 -> V_22 += V_42 -> V_50 ;
} else
V_2 -> V_23 = V_40 ;
V_2 -> V_19 = V_37 -> V_51 ;
V_2 -> V_20 = V_37 -> V_38 ;
V_2 -> V_21 = V_33 ;
V_2 -> V_3 = V_52 ;
V_2 -> V_14 = NULL ;
V_2 -> V_16 = NULL ;
return F_22 ( V_2 , V_42 -> V_53 ) ;
}
static int F_26 ( struct V_32 * V_33 , struct V_1 * V_2 ,
struct V_54 * V_42 )
{
struct V_41 V_55 = {
. V_53 = V_42 -> V_53 ,
. V_43 = V_42 -> V_43 ,
. V_48 = V_42 -> V_48 ,
. V_50 = V_42 -> V_50 ,
} ;
return F_23 ( V_33 , V_2 , & V_55 ) ;
}
static void F_27 ( struct V_1 * V_2 )
{
F_28 ( & V_2 -> V_56 , V_57 , V_58 ) ;
}
static int F_29 ( struct V_32 * V_33 , long type , struct V_1 * V_2 )
{
if ( F_22 ( V_2 , type ) != 0 )
return - V_31 ;
V_2 -> V_19 = ( V_36 ) V_37 -> V_51 ;
V_2 -> V_20 = V_37 -> V_38 ;
V_2 -> V_21 = V_33 ;
V_2 -> V_3 = V_59 ;
V_2 -> V_22 = 0 ;
V_2 -> V_23 = V_40 ;
V_2 -> V_14 = NULL ;
V_2 -> V_16 = & V_60 ;
return 0 ;
}
static struct V_1 * F_30 ( struct V_32 * V_33 , long type )
{
struct V_1 * V_2 = F_7 () ;
int error = - V_35 ;
if ( V_2 == NULL )
return F_31 ( error ) ;
error = F_29 ( V_33 , type , V_2 ) ;
if ( error ) {
F_10 ( V_2 ) ;
return F_31 ( error ) ;
}
return V_2 ;
}
static inline int F_32 ( struct V_1 * V_61 , struct V_1 * V_62 )
{
return ( ( V_61 -> V_23 >= V_62 -> V_22 ) &&
( V_62 -> V_23 >= V_61 -> V_22 ) ) ;
}
static int F_33 ( struct V_1 * V_61 , struct V_1 * V_62 )
{
if ( V_61 -> V_16 && V_61 -> V_16 -> V_63 )
return V_62 -> V_16 == V_61 -> V_16 &&
V_61 -> V_16 -> V_63 ( V_61 , V_62 ) ;
return V_61 -> V_19 == V_62 -> V_19 ;
}
static void F_34 ( struct V_1 * V_2 )
{
F_35 ( & V_64 ) ;
V_2 -> V_65 = F_36 () ;
F_37 ( & V_2 -> V_9 , F_38 ( & V_66 ) ) ;
F_39 ( & V_64 ) ;
}
static void F_40 ( struct V_1 * V_2 )
{
if ( F_14 ( & V_2 -> V_9 ) )
return;
F_41 ( & V_64 , V_2 -> V_65 ) ;
F_42 ( & V_2 -> V_9 ) ;
F_43 ( & V_64 , V_2 -> V_65 ) ;
}
static unsigned long
F_44 ( struct V_1 * V_2 )
{
if ( V_2 -> V_16 && V_2 -> V_16 -> V_67 )
return V_2 -> V_16 -> V_67 ( V_2 ) ;
return ( unsigned long ) V_2 -> V_19 ;
}
static void F_45 ( struct V_1 * V_68 )
{
F_46 ( V_69 , & V_68 -> V_9 , F_44 ( V_68 ) ) ;
}
static void F_47 ( struct V_1 * V_68 )
{
F_48 ( & V_68 -> V_9 ) ;
}
static void F_49 ( struct V_1 * V_68 )
{
F_47 ( V_68 ) ;
F_50 ( & V_68 -> V_10 ) ;
V_68 -> V_70 = NULL ;
}
static void F_51 ( struct V_1 * V_68 )
{
F_52 ( & V_71 ) ;
F_49 ( V_68 ) ;
F_53 ( & V_71 ) ;
}
static void F_54 ( struct V_1 * V_72 ,
struct V_1 * V_68 )
{
F_11 ( ! F_13 ( & V_68 -> V_10 ) ) ;
V_68 -> V_70 = V_72 ;
F_55 ( & V_68 -> V_10 , & V_72 -> V_10 ) ;
if ( F_56 ( V_72 ) && ! F_57 ( V_72 ) )
F_45 ( V_68 ) ;
}
static void F_58 ( struct V_1 * V_72 ,
struct V_1 * V_68 )
{
F_52 ( & V_71 ) ;
F_54 ( V_72 , V_68 ) ;
F_53 ( & V_71 ) ;
}
static void F_59 ( struct V_1 * V_72 )
{
if ( F_13 ( & V_72 -> V_10 ) )
return;
F_52 ( & V_71 ) ;
while ( ! F_13 ( & V_72 -> V_10 ) ) {
struct V_1 * V_68 ;
V_68 = F_60 ( & V_72 -> V_10 ,
struct V_1 , V_10 ) ;
F_49 ( V_68 ) ;
if ( V_68 -> V_16 && V_68 -> V_16 -> V_73 )
V_68 -> V_16 -> V_73 ( V_68 ) ;
else
F_61 ( & V_68 -> V_11 ) ;
}
F_53 ( & V_71 ) ;
}
static void F_62 ( struct V_1 * * V_74 , struct V_1 * V_2 )
{
V_2 -> V_75 = F_63 ( F_64 ( V_37 ) ) ;
V_2 -> V_70 = * V_74 ;
* V_74 = V_2 ;
F_34 ( V_2 ) ;
}
static void F_65 ( struct V_1 * * V_76 )
{
struct V_1 * V_2 = * V_76 ;
F_40 ( V_2 ) ;
* V_76 = V_2 -> V_70 ;
V_2 -> V_70 = NULL ;
if ( V_2 -> V_75 ) {
F_66 ( V_2 -> V_75 ) ;
V_2 -> V_75 = NULL ;
}
F_59 ( V_2 ) ;
}
static void F_67 ( struct V_1 * * V_76 )
{
struct V_1 * V_2 = * V_76 ;
F_65 ( V_76 ) ;
F_10 ( V_2 ) ;
}
static int F_68 ( struct V_1 * V_77 , struct V_1 * V_78 )
{
if ( V_78 -> V_8 == V_29 )
return 1 ;
if ( V_77 -> V_8 == V_29 )
return 1 ;
return 0 ;
}
static int F_69 ( struct V_1 * V_77 , struct V_1 * V_78 )
{
if ( ! F_56 ( V_78 ) || F_33 ( V_77 , V_78 ) )
return ( 0 ) ;
if ( ! F_32 ( V_77 , V_78 ) )
return 0 ;
return ( F_68 ( V_77 , V_78 ) ) ;
}
static int F_70 ( struct V_1 * V_77 , struct V_1 * V_78 )
{
if ( ! F_71 ( V_78 ) || ( V_77 -> V_21 == V_78 -> V_21 ) )
return ( 0 ) ;
if ( ( V_77 -> V_8 & V_25 ) || ( V_78 -> V_8 & V_25 ) )
return 0 ;
return ( F_68 ( V_77 , V_78 ) ) ;
}
void
F_72 ( struct V_32 * V_33 , struct V_1 * V_2 )
{
struct V_1 * V_79 ;
struct V_80 * V_80 = F_25 ( V_33 ) ;
F_52 ( & V_80 -> V_81 ) ;
for ( V_79 = F_25 ( V_33 ) -> V_82 ; V_79 ; V_79 = V_79 -> V_70 ) {
if ( ! F_56 ( V_79 ) )
continue;
if ( F_69 ( V_2 , V_79 ) )
break;
}
if ( V_79 ) {
F_18 ( V_2 , V_79 ) ;
if ( V_79 -> V_75 )
V_2 -> V_20 = F_73 ( V_79 -> V_75 ) ;
} else
V_2 -> V_8 = V_6 ;
F_53 ( & V_80 -> V_81 ) ;
return;
}
static struct V_1 * F_74 ( struct V_1 * V_83 )
{
struct V_1 * V_2 ;
F_75 (blocked_hash, fl, fl_link, posix_owner_key(block_fl)) {
if ( F_33 ( V_2 , V_83 ) )
return V_2 -> V_70 ;
}
return NULL ;
}
static int F_76 ( struct V_1 * V_77 ,
struct V_1 * V_83 )
{
int V_84 = 0 ;
if ( F_57 ( V_77 ) )
return 0 ;
while ( ( V_83 = F_74 ( V_83 ) ) ) {
if ( V_84 ++ > V_85 )
return 0 ;
if ( F_33 ( V_77 , V_83 ) )
return 1 ;
}
return 0 ;
}
static int F_77 ( struct V_32 * V_33 , struct V_1 * V_86 )
{
struct V_1 * V_87 = NULL ;
struct V_1 * * V_88 ;
struct V_80 * V_80 = F_25 ( V_33 ) ;
int error = 0 ;
int V_89 = 0 ;
if ( ! ( V_86 -> V_3 & V_90 ) && ( V_86 -> V_8 != V_6 ) ) {
V_87 = F_7 () ;
if ( ! V_87 )
return - V_35 ;
}
F_52 ( & V_80 -> V_81 ) ;
if ( V_86 -> V_3 & V_90 )
goto V_91;
F_78 (inode, before) {
struct V_1 * V_2 = * V_88 ;
if ( F_56 ( V_2 ) )
break;
if ( F_79 ( V_2 ) )
continue;
if ( V_33 != V_2 -> V_21 )
continue;
if ( V_86 -> V_8 == V_2 -> V_8 )
goto V_92;
V_89 = 1 ;
F_67 ( V_88 ) ;
break;
}
if ( V_86 -> V_8 == V_6 ) {
if ( ( V_86 -> V_3 & V_93 ) && ! V_89 )
error = - V_94 ;
goto V_92;
}
if ( V_89 ) {
F_53 ( & V_80 -> V_81 ) ;
F_80 () ;
F_52 ( & V_80 -> V_81 ) ;
}
V_91:
F_78 (inode, before) {
struct V_1 * V_2 = * V_88 ;
if ( F_56 ( V_2 ) )
break;
if ( F_79 ( V_2 ) )
continue;
if ( ! F_70 ( V_86 , V_2 ) )
continue;
error = - V_95 ;
if ( ! ( V_86 -> V_3 & V_96 ) )
goto V_92;
error = V_97 ;
F_58 ( V_2 , V_86 ) ;
goto V_92;
}
if ( V_86 -> V_3 & V_90 )
goto V_92;
F_19 ( V_87 , V_86 ) ;
F_62 ( V_88 , V_87 ) ;
V_87 = NULL ;
error = 0 ;
V_92:
F_53 ( & V_80 -> V_81 ) ;
if ( V_87 )
F_10 ( V_87 ) ;
return error ;
}
static int F_81 ( struct V_80 * V_80 , struct V_1 * V_86 , struct V_1 * V_98 )
{
struct V_1 * V_2 ;
struct V_1 * V_87 = NULL ;
struct V_1 * V_99 = NULL ;
struct V_1 * V_100 = NULL ;
struct V_1 * V_101 = NULL ;
struct V_1 * * V_88 ;
int error ;
bool V_102 = false ;
if ( ! ( V_86 -> V_3 & V_90 ) &&
( V_86 -> V_8 != V_6 ||
V_86 -> V_22 != 0 || V_86 -> V_23 != V_40 ) ) {
V_87 = F_7 () ;
V_99 = F_7 () ;
}
F_52 ( & V_80 -> V_81 ) ;
if ( V_86 -> V_8 != V_6 ) {
F_78 (inode, before) {
V_2 = * V_88 ;
if ( ! F_56 ( V_2 ) )
continue;
if ( ! F_69 ( V_86 , V_2 ) )
continue;
if ( V_98 )
F_18 ( V_98 , V_2 ) ;
error = - V_95 ;
if ( ! ( V_86 -> V_3 & V_96 ) )
goto V_92;
error = - V_103 ;
F_52 ( & V_71 ) ;
if ( F_82 ( ! F_76 ( V_86 , V_2 ) ) ) {
error = V_97 ;
F_54 ( V_2 , V_86 ) ;
}
F_53 ( & V_71 ) ;
goto V_92;
}
}
error = 0 ;
if ( V_86 -> V_3 & V_90 )
goto V_92;
V_88 = & V_80 -> V_82 ;
while ( ( V_2 = * V_88 ) && ( ! F_56 ( V_2 ) ||
! F_33 ( V_86 , V_2 ) ) ) {
V_88 = & V_2 -> V_70 ;
}
while ( ( V_2 = * V_88 ) && F_33 ( V_86 , V_2 ) ) {
if ( V_86 -> V_8 == V_2 -> V_8 ) {
if ( V_2 -> V_23 < V_86 -> V_22 - 1 )
goto V_104;
if ( V_2 -> V_22 - 1 > V_86 -> V_23 )
break;
if ( V_2 -> V_22 > V_86 -> V_22 )
V_2 -> V_22 = V_86 -> V_22 ;
else
V_86 -> V_22 = V_2 -> V_22 ;
if ( V_2 -> V_23 < V_86 -> V_23 )
V_2 -> V_23 = V_86 -> V_23 ;
else
V_86 -> V_23 = V_2 -> V_23 ;
if ( V_102 ) {
F_67 ( V_88 ) ;
continue;
}
V_86 = V_2 ;
V_102 = true ;
}
else {
if ( V_2 -> V_23 < V_86 -> V_22 )
goto V_104;
if ( V_2 -> V_22 > V_86 -> V_23 )
break;
if ( V_86 -> V_8 == V_6 )
V_102 = true ;
if ( V_2 -> V_22 < V_86 -> V_22 )
V_100 = V_2 ;
if ( V_2 -> V_23 > V_86 -> V_23 ) {
V_101 = V_2 ;
break;
}
if ( V_2 -> V_22 >= V_86 -> V_22 ) {
if ( V_102 ) {
F_67 ( V_88 ) ;
continue;
}
F_59 ( V_2 ) ;
V_2 -> V_22 = V_86 -> V_22 ;
V_2 -> V_23 = V_86 -> V_23 ;
V_2 -> V_8 = V_86 -> V_8 ;
F_9 ( V_2 ) ;
F_17 ( V_2 , V_86 ) ;
V_86 = V_2 ;
V_102 = true ;
}
}
V_104:
V_88 = & V_2 -> V_70 ;
}
error = - V_105 ;
if ( V_101 && V_100 == V_101 && ! V_99 )
goto V_92;
error = 0 ;
if ( ! V_102 ) {
if ( V_86 -> V_8 == V_6 ) {
if ( V_86 -> V_3 & V_93 )
error = - V_94 ;
goto V_92;
}
if ( ! V_87 ) {
error = - V_105 ;
goto V_92;
}
F_19 ( V_87 , V_86 ) ;
F_62 ( V_88 , V_87 ) ;
V_87 = NULL ;
}
if ( V_101 ) {
if ( V_100 == V_101 ) {
V_100 = V_99 ;
V_99 = NULL ;
F_19 ( V_100 , V_101 ) ;
F_62 ( V_88 , V_100 ) ;
}
V_101 -> V_22 = V_86 -> V_23 + 1 ;
F_59 ( V_101 ) ;
}
if ( V_100 ) {
V_100 -> V_23 = V_86 -> V_22 - 1 ;
F_59 ( V_100 ) ;
}
V_92:
F_53 ( & V_80 -> V_81 ) ;
if ( V_87 )
F_10 ( V_87 ) ;
if ( V_99 )
F_10 ( V_99 ) ;
return error ;
}
int F_83 ( struct V_32 * V_33 , struct V_1 * V_2 ,
struct V_1 * V_98 )
{
return F_81 ( F_25 ( V_33 ) , V_2 , V_98 ) ;
}
int F_84 ( struct V_32 * V_33 , struct V_1 * V_2 )
{
int error ;
F_85 () ;
for (; ; ) {
error = F_83 ( V_33 , V_2 , NULL ) ;
if ( error != V_97 )
break;
error = F_86 ( V_2 -> V_11 , ! V_2 -> V_70 ) ;
if ( ! error )
continue;
F_51 ( V_2 ) ;
break;
}
return error ;
}
int F_87 ( struct V_32 * V_32 )
{
struct V_80 * V_80 = F_25 ( V_32 ) ;
V_36 V_106 = V_37 -> V_51 ;
struct V_1 * V_2 ;
F_52 ( & V_80 -> V_81 ) ;
for ( V_2 = V_80 -> V_82 ; V_2 != NULL ; V_2 = V_2 -> V_70 ) {
if ( ! F_56 ( V_2 ) )
continue;
if ( V_2 -> V_19 != V_106 && V_2 -> V_19 != ( V_36 ) V_32 )
break;
}
F_53 ( & V_80 -> V_81 ) ;
return V_2 ? - V_95 : 0 ;
}
int F_88 ( int V_107 , struct V_80 * V_80 ,
struct V_32 * V_33 , T_1 V_108 ,
T_2 V_109 )
{
struct V_1 V_2 ;
int error ;
bool V_110 = false ;
F_16 ( & V_2 ) ;
V_2 . V_20 = V_37 -> V_38 ;
V_2 . V_21 = V_33 ;
V_2 . V_3 = V_52 | V_90 ;
if ( V_33 && ! ( V_33 -> V_111 & V_112 ) )
V_110 = true ;
V_2 . V_8 = ( V_107 == V_113 ) ? V_29 : V_7 ;
V_2 . V_22 = V_108 ;
V_2 . V_23 = V_108 + V_109 - 1 ;
for (; ; ) {
if ( V_33 ) {
V_2 . V_19 = ( V_36 ) V_33 ;
V_2 . V_3 &= ~ V_96 ;
error = F_81 ( V_80 , & V_2 , NULL ) ;
if ( ! error )
break;
}
if ( V_110 )
V_2 . V_3 |= V_96 ;
V_2 . V_19 = V_37 -> V_51 ;
error = F_81 ( V_80 , & V_2 , NULL ) ;
if ( error != V_97 )
break;
error = F_86 ( V_2 . V_11 , ! V_2 . V_70 ) ;
if ( ! error ) {
if ( F_89 ( V_80 ) )
continue;
}
F_51 ( & V_2 ) ;
break;
}
return error ;
}
static void F_90 ( struct V_1 * V_2 , int V_114 )
{
switch ( V_114 ) {
case V_6 :
V_2 -> V_3 &= ~ V_4 ;
case V_7 :
V_2 -> V_3 &= ~ V_5 ;
}
}
int F_91 ( struct V_1 * * V_88 , int V_114 )
{
struct V_1 * V_2 = * V_88 ;
int error = F_22 ( V_2 , V_114 ) ;
if ( error )
return error ;
F_90 ( V_2 , V_114 ) ;
F_59 ( V_2 ) ;
if ( V_114 == V_6 ) {
struct V_32 * V_33 = V_2 -> V_21 ;
F_92 ( V_33 ) ;
V_33 -> V_115 . V_116 = 0 ;
F_93 ( 0 , V_2 -> V_21 , 0 , & V_2 -> V_56 ) ;
if ( V_2 -> V_56 != NULL ) {
F_94 ( V_117 L_1 , V_2 -> V_56 ) ;
V_2 -> V_56 = NULL ;
}
F_67 ( V_88 ) ;
}
return 0 ;
}
static bool F_95 ( unsigned long V_118 )
{
if ( ! V_118 )
return false ;
return F_96 ( V_119 , V_118 ) ;
}
static void F_97 ( struct V_80 * V_80 )
{
struct V_1 * * V_88 ;
struct V_1 * V_2 ;
V_88 = & V_80 -> V_82 ;
while ( ( V_2 = * V_88 ) && F_79 ( V_2 ) && F_1 ( V_2 ) ) {
F_98 ( V_80 , V_2 ) ;
if ( F_95 ( V_2 -> V_120 ) )
F_91 ( V_88 , V_7 ) ;
if ( F_95 ( V_2 -> V_121 ) )
F_91 ( V_88 , V_6 ) ;
if ( V_2 == * V_88 )
V_88 = & V_2 -> V_70 ;
}
}
static bool F_99 ( struct V_1 * V_122 , struct V_1 * V_123 )
{
if ( ( V_123 -> V_3 & V_124 ) && ( V_122 -> V_3 & V_59 ) )
return false ;
return F_68 ( V_123 , V_122 ) ;
}
int F_100 ( struct V_80 * V_80 , unsigned int V_125 , unsigned int type )
{
int error = 0 ;
struct V_1 * V_87 , * V_54 ;
struct V_1 * V_2 ;
unsigned long V_126 ;
int V_127 = 0 ;
bool V_128 = false ;
int V_129 = ( V_125 & V_130 ) != V_131 ;
V_87 = F_30 ( NULL , V_129 ? V_29 : V_7 ) ;
if ( F_101 ( V_87 ) )
return F_102 ( V_87 ) ;
V_87 -> V_3 = type ;
F_52 ( & V_80 -> V_81 ) ;
F_97 ( V_80 ) ;
V_54 = V_80 -> V_82 ;
if ( ( V_54 == NULL ) || ! F_79 ( V_54 ) )
goto V_92;
for ( V_2 = V_54 ; V_2 && F_79 ( V_2 ) ; V_2 = V_2 -> V_70 ) {
if ( F_99 ( V_2 , V_87 ) ) {
V_128 = true ;
if ( V_2 -> V_19 == V_37 -> V_51 )
V_127 = 1 ;
}
}
if ( ! V_128 )
goto V_92;
V_126 = 0 ;
if ( V_132 > 0 ) {
V_126 = V_119 + V_132 * V_133 ;
if ( V_126 == 0 )
V_126 ++ ;
}
for ( V_2 = V_54 ; V_2 && F_79 ( V_2 ) ; V_2 = V_2 -> V_70 ) {
if ( ! F_99 ( V_2 , V_87 ) )
continue;
if ( V_129 ) {
if ( V_2 -> V_3 & V_4 )
continue;
V_2 -> V_3 |= V_4 ;
V_2 -> V_121 = V_126 ;
} else {
if ( F_1 ( V_54 ) )
continue;
V_2 -> V_3 |= V_5 ;
V_2 -> V_120 = V_126 ;
}
V_2 -> V_16 -> V_134 ( V_2 ) ;
}
if ( V_127 || ( V_125 & V_112 ) ) {
F_103 ( V_80 , V_87 ) ;
error = - V_135 ;
goto V_92;
}
V_136:
V_126 = V_54 -> V_121 ;
if ( V_126 != 0 )
V_126 -= V_119 ;
if ( V_126 == 0 )
V_126 ++ ;
F_58 ( V_54 , V_87 ) ;
F_104 ( V_80 , V_87 ) ;
F_53 ( & V_80 -> V_81 ) ;
error = F_105 ( V_87 -> V_11 ,
! V_87 -> V_70 , V_126 ) ;
F_52 ( & V_80 -> V_81 ) ;
F_106 ( V_80 , V_87 ) ;
F_51 ( V_87 ) ;
if ( error >= 0 ) {
if ( error == 0 )
F_97 ( V_80 ) ;
for ( V_54 = V_80 -> V_82 ; V_54 && F_79 ( V_54 ) ;
V_54 = V_54 -> V_70 ) {
if ( F_99 ( V_87 , V_54 ) )
goto V_136;
}
error = 0 ;
}
V_92:
F_53 ( & V_80 -> V_81 ) ;
F_10 ( V_87 ) ;
return error ;
}
void F_107 ( struct V_80 * V_80 , struct V_137 * time )
{
struct V_1 * V_54 = V_80 -> V_82 ;
if ( V_54 && F_79 ( V_54 ) && ( V_54 -> V_8 == V_29 ) )
* time = F_108 ( V_80 -> V_138 ) ;
else
* time = V_80 -> V_139 ;
}
int F_109 ( struct V_32 * V_33 )
{
struct V_1 * V_2 ;
struct V_80 * V_80 = F_25 ( V_33 ) ;
int type = V_6 ;
F_52 ( & V_80 -> V_81 ) ;
F_97 ( F_25 ( V_33 ) ) ;
for ( V_2 = F_25 ( V_33 ) -> V_82 ; V_2 && F_79 ( V_2 ) ;
V_2 = V_2 -> V_70 ) {
if ( V_2 -> V_21 == V_33 ) {
type = F_2 ( V_2 ) ;
break;
}
}
F_53 ( & V_80 -> V_81 ) ;
return type ;
}
static int
F_110 ( const struct V_140 * V_140 , const long V_114 )
{
int V_141 = 0 ;
struct V_80 * V_80 = V_140 -> V_142 ;
if ( ( V_114 == V_7 ) && ( F_111 ( & V_80 -> V_143 ) > 0 ) )
return - V_95 ;
if ( ( V_114 == V_29 ) && ( ( F_112 ( V_140 ) > 1 ) ||
( F_111 ( & V_80 -> V_144 ) > 1 ) ) )
V_141 = - V_95 ;
return V_141 ;
}
static int F_113 ( struct V_32 * V_33 , long V_114 , struct V_1 * * V_145 )
{
struct V_1 * V_2 , * * V_88 , * * V_146 = NULL , * V_122 ;
struct V_140 * V_140 = V_33 -> V_147 . V_140 ;
struct V_80 * V_80 = V_140 -> V_142 ;
bool V_148 = ( * V_145 ) -> V_3 & V_124 ;
int error ;
V_122 = * V_145 ;
F_114 ( V_80 , V_122 ) ;
if ( V_148 && ! F_115 ( & V_80 -> V_149 ) )
return - V_95 ;
if ( V_148 && V_114 == V_29 ) {
F_116 ( & V_80 -> V_149 ) ;
F_117 ( 1 ) ;
return - V_31 ;
}
error = F_110 ( V_140 , V_114 ) ;
if ( error )
goto V_92;
error = - V_95 ;
for ( V_88 = & V_80 -> V_82 ;
( ( V_2 = * V_88 ) != NULL ) && F_79 ( V_2 ) ;
V_88 = & V_2 -> V_70 ) {
if ( V_2 -> V_21 == V_33 ) {
V_146 = V_88 ;
continue;
}
if ( V_114 == V_29 )
goto V_92;
if ( V_2 -> V_3 & V_4 )
goto V_92;
}
if ( V_146 != NULL ) {
error = V_122 -> V_16 -> V_150 ( V_146 , V_114 ) ;
if ( ! error )
* V_145 = * V_146 ;
goto V_92;
}
error = - V_31 ;
if ( ! V_151 )
goto V_92;
F_62 ( V_88 , V_122 ) ;
F_118 () ;
error = F_110 ( V_140 , V_114 ) ;
if ( error )
F_65 ( V_145 ) ;
V_92:
if ( V_148 )
F_116 ( & V_80 -> V_149 ) ;
return error ;
}
static int F_119 ( struct V_32 * V_33 , struct V_1 * * V_145 )
{
struct V_1 * V_2 , * * V_88 ;
struct V_140 * V_140 = V_33 -> V_147 . V_140 ;
struct V_80 * V_80 = V_140 -> V_142 ;
F_120 ( V_80 , * V_145 ) ;
for ( V_88 = & V_80 -> V_82 ;
( ( V_2 = * V_88 ) != NULL ) && F_79 ( V_2 ) ;
V_88 = & V_2 -> V_70 ) {
if ( V_2 -> V_21 != V_33 )
continue;
return ( * V_145 ) -> V_16 -> V_150 ( V_88 , V_6 ) ;
}
return - V_95 ;
}
int F_121 ( struct V_32 * V_33 , long V_114 , struct V_1 * * V_145 )
{
struct V_140 * V_140 = V_33 -> V_147 . V_140 ;
struct V_80 * V_80 = V_140 -> V_142 ;
int error ;
if ( ( ! F_122 ( F_123 () , V_80 -> V_152 ) ) && ! F_124 ( V_153 ) )
return - V_154 ;
if ( ! F_125 ( V_80 -> V_155 ) )
return - V_31 ;
error = F_126 ( V_33 , V_114 ) ;
if ( error )
return error ;
F_97 ( V_80 ) ;
F_11 ( ! ( * V_145 ) -> V_16 -> V_134 ) ;
switch ( V_114 ) {
case V_6 :
return F_119 ( V_33 , V_145 ) ;
case V_7 :
case V_29 :
return F_113 ( V_33 , V_114 , V_145 ) ;
default:
return - V_31 ;
}
}
static int F_127 ( struct V_32 * V_33 , long V_114 , struct V_1 * * V_122 )
{
if ( V_33 -> V_156 -> V_157 )
return V_33 -> V_156 -> V_157 ( V_33 , V_114 , V_122 ) ;
else
return F_121 ( V_33 , V_114 , V_122 ) ;
}
int F_128 ( struct V_32 * V_33 , long V_114 , struct V_1 * * V_122 )
{
struct V_80 * V_80 = F_25 ( V_33 ) ;
int error ;
F_52 ( & V_80 -> V_81 ) ;
error = F_127 ( V_33 , V_114 , V_122 ) ;
F_53 ( & V_80 -> V_81 ) ;
return error ;
}
static int F_129 ( struct V_32 * V_33 )
{
struct V_1 V_2 , * V_145 = & V_2 ;
F_29 ( V_33 , V_6 , V_145 ) ;
return F_128 ( V_33 , V_6 , & V_145 ) ;
}
static int F_130 ( unsigned int V_158 , struct V_32 * V_33 , long V_114 )
{
struct V_1 * V_2 , * V_141 ;
struct V_80 * V_80 = F_25 ( V_33 ) ;
struct V_159 * V_17 ;
int error ;
V_2 = F_30 ( V_33 , V_114 ) ;
if ( F_101 ( V_2 ) )
return F_102 ( V_2 ) ;
V_17 = F_131 () ;
if ( ! V_17 ) {
F_10 ( V_2 ) ;
return - V_35 ;
}
V_141 = V_2 ;
F_52 ( & V_80 -> V_81 ) ;
error = F_127 ( V_33 , V_114 , & V_141 ) ;
if ( error ) {
F_53 ( & V_80 -> V_81 ) ;
F_10 ( V_2 ) ;
goto V_160;
}
if ( V_141 != V_2 )
F_10 ( V_2 ) ;
if ( ! F_132 ( V_158 , V_33 , & V_141 -> V_56 , V_17 ) )
V_17 = NULL ;
error = F_133 ( V_33 , F_134 ( V_37 ) , V_161 , 0 ) ;
F_53 ( & V_80 -> V_81 ) ;
V_160:
if ( V_17 )
F_135 ( V_17 ) ;
return error ;
}
int F_136 ( unsigned int V_158 , struct V_32 * V_33 , long V_114 )
{
if ( V_114 == V_6 )
return F_129 ( V_33 ) ;
return F_130 ( V_158 , V_33 , V_114 ) ;
}
int F_137 ( struct V_32 * V_33 , struct V_1 * V_2 )
{
int error ;
F_85 () ;
for (; ; ) {
error = F_77 ( V_33 , V_2 ) ;
if ( error != V_97 )
break;
error = F_86 ( V_2 -> V_11 , ! V_2 -> V_70 ) ;
if ( ! error )
continue;
F_51 ( V_2 ) ;
break;
}
return error ;
}
int F_138 ( struct V_32 * V_33 , struct V_1 * V_2 )
{
if ( V_33 -> V_156 -> V_34 )
return V_33 -> V_156 -> V_34 ( V_33 , V_162 , V_2 ) ;
F_72 ( V_33 , V_2 ) ;
return 0 ;
}
static int F_139 ( struct V_54 * V_54 , struct V_1 * V_2 )
{
V_54 -> V_163 = F_57 ( V_2 ) ? - 1 : V_2 -> V_20 ;
#if V_164 == 32
if ( V_2 -> V_22 > V_165 )
return - V_49 ;
if ( V_2 -> V_23 != V_40 && V_2 -> V_23 > V_165 )
return - V_49 ;
#endif
V_54 -> V_48 = V_2 -> V_22 ;
V_54 -> V_50 = V_2 -> V_23 == V_40 ? 0 :
V_2 -> V_23 - V_2 -> V_22 + 1 ;
V_54 -> V_43 = 0 ;
V_54 -> V_53 = V_2 -> V_8 ;
return 0 ;
}
static void F_140 ( struct V_41 * V_54 , struct V_1 * V_2 )
{
V_54 -> V_163 = F_57 ( V_2 ) ? - 1 : V_2 -> V_20 ;
V_54 -> V_48 = V_2 -> V_22 ;
V_54 -> V_50 = V_2 -> V_23 == V_40 ? 0 :
V_2 -> V_23 - V_2 -> V_22 + 1 ;
V_54 -> V_43 = 0 ;
V_54 -> V_53 = V_2 -> V_8 ;
}
int F_141 ( struct V_32 * V_33 , unsigned int V_24 , struct V_54 T_3 * V_42 )
{
struct V_1 V_1 ;
struct V_54 V_54 ;
int error ;
error = - V_166 ;
if ( F_142 ( & V_54 , V_42 , sizeof( V_54 ) ) )
goto V_92;
error = - V_31 ;
if ( ( V_54 . V_53 != V_7 ) && ( V_54 . V_53 != V_29 ) )
goto V_92;
error = F_26 ( V_33 , & V_1 , & V_54 ) ;
if ( error )
goto V_92;
if ( V_24 == V_167 ) {
error = - V_31 ;
if ( V_54 . V_163 != 0 )
goto V_92;
V_24 = V_162 ;
V_1 . V_3 |= V_168 ;
V_1 . V_19 = ( V_36 ) V_33 ;
}
error = F_138 ( V_33 , & V_1 ) ;
if ( error )
goto V_92;
V_54 . V_53 = V_1 . V_8 ;
if ( V_1 . V_8 != V_6 ) {
error = F_139 ( & V_54 , & V_1 ) ;
if ( error )
goto V_92;
}
error = - V_166 ;
if ( ! F_143 ( V_42 , & V_54 , sizeof( V_54 ) ) )
error = 0 ;
V_92:
return error ;
}
int F_144 ( struct V_32 * V_33 , unsigned int V_24 , struct V_1 * V_2 , struct V_1 * V_169 )
{
if ( V_33 -> V_156 -> V_34 )
return V_33 -> V_156 -> V_34 ( V_33 , V_24 , V_2 ) ;
else
return F_83 ( V_33 , V_2 , V_169 ) ;
}
static int F_145 ( struct V_32 * V_33 , unsigned int V_24 ,
struct V_1 * V_2 )
{
int error ;
error = F_126 ( V_33 , V_2 -> V_8 ) ;
if ( error )
return error ;
for (; ; ) {
error = F_144 ( V_33 , V_24 , V_2 , NULL ) ;
if ( error != V_97 )
break;
error = F_86 ( V_2 -> V_11 , ! V_2 -> V_70 ) ;
if ( ! error )
continue;
F_51 ( V_2 ) ;
break;
}
return error ;
}
static int
F_146 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_8 ) {
case V_7 :
if ( ! ( V_2 -> V_21 -> V_170 & V_171 ) )
return - V_172 ;
break;
case V_29 :
if ( ! ( V_2 -> V_21 -> V_170 & V_173 ) )
return - V_172 ;
}
return 0 ;
}
int F_147 ( unsigned int V_158 , struct V_32 * V_33 , unsigned int V_24 ,
struct V_54 T_3 * V_42 )
{
struct V_1 * V_1 = F_7 () ;
struct V_54 V_54 ;
struct V_80 * V_80 ;
struct V_32 * V_174 ;
int error ;
if ( V_1 == NULL )
return - V_105 ;
error = - V_166 ;
if ( F_142 ( & V_54 , V_42 , sizeof( V_54 ) ) )
goto V_92;
V_80 = F_25 ( V_33 ) ;
if ( F_148 ( V_80 ) && F_149 ( V_33 -> V_175 ) ) {
error = - V_95 ;
goto V_92;
}
V_176:
error = F_26 ( V_33 , V_1 , & V_54 ) ;
if ( error )
goto V_92;
error = F_146 ( V_1 ) ;
if ( error )
goto V_92;
switch ( V_24 ) {
case V_177 :
error = - V_31 ;
if ( V_54 . V_163 != 0 )
goto V_92;
V_24 = V_178 ;
V_1 -> V_3 |= V_168 ;
V_1 -> V_19 = ( V_36 ) V_33 ;
break;
case V_179 :
error = - V_31 ;
if ( V_54 . V_163 != 0 )
goto V_92;
V_24 = V_180 ;
V_1 -> V_3 |= V_168 ;
V_1 -> V_19 = ( V_36 ) V_33 ;
case V_180 :
V_1 -> V_3 |= V_96 ;
}
error = F_145 ( V_33 , V_24 , V_1 ) ;
F_52 ( & V_37 -> V_51 -> V_1 ) ;
V_174 = F_150 ( V_158 ) ;
F_53 ( & V_37 -> V_51 -> V_1 ) ;
if ( ! error && V_174 != V_33 && V_54 . V_53 != V_6 ) {
V_54 . V_53 = V_6 ;
goto V_176;
}
V_92:
F_10 ( V_1 ) ;
return error ;
}
int F_151 ( struct V_32 * V_33 , unsigned int V_24 , struct V_41 T_3 * V_42 )
{
struct V_1 V_1 ;
struct V_41 V_54 ;
int error ;
error = - V_166 ;
if ( F_142 ( & V_54 , V_42 , sizeof( V_54 ) ) )
goto V_92;
error = - V_31 ;
if ( ( V_54 . V_53 != V_7 ) && ( V_54 . V_53 != V_29 ) )
goto V_92;
error = F_23 ( V_33 , & V_1 , & V_54 ) ;
if ( error )
goto V_92;
if ( V_24 == V_167 ) {
error = - V_31 ;
if ( V_54 . V_163 != 0 )
goto V_92;
V_24 = V_181 ;
V_1 . V_3 |= V_168 ;
V_1 . V_19 = ( V_36 ) V_33 ;
}
error = F_138 ( V_33 , & V_1 ) ;
if ( error )
goto V_92;
V_54 . V_53 = V_1 . V_8 ;
if ( V_1 . V_8 != V_6 )
F_140 ( & V_54 , & V_1 ) ;
error = - V_166 ;
if ( ! F_143 ( V_42 , & V_54 , sizeof( V_54 ) ) )
error = 0 ;
V_92:
return error ;
}
int F_152 ( unsigned int V_158 , struct V_32 * V_33 , unsigned int V_24 ,
struct V_41 T_3 * V_42 )
{
struct V_1 * V_1 = F_7 () ;
struct V_41 V_54 ;
struct V_80 * V_80 ;
struct V_32 * V_174 ;
int error ;
if ( V_1 == NULL )
return - V_105 ;
error = - V_166 ;
if ( F_142 ( & V_54 , V_42 , sizeof( V_54 ) ) )
goto V_92;
V_80 = F_25 ( V_33 ) ;
if ( F_148 ( V_80 ) && F_149 ( V_33 -> V_175 ) ) {
error = - V_95 ;
goto V_92;
}
V_176:
error = F_23 ( V_33 , V_1 , & V_54 ) ;
if ( error )
goto V_92;
error = F_146 ( V_1 ) ;
if ( error )
goto V_92;
switch ( V_24 ) {
case V_177 :
error = - V_31 ;
if ( V_54 . V_163 != 0 )
goto V_92;
V_24 = V_182 ;
V_1 -> V_3 |= V_168 ;
V_1 -> V_19 = ( V_36 ) V_33 ;
break;
case V_179 :
error = - V_31 ;
if ( V_54 . V_163 != 0 )
goto V_92;
V_24 = V_183 ;
V_1 -> V_3 |= V_168 ;
V_1 -> V_19 = ( V_36 ) V_33 ;
case V_183 :
V_1 -> V_3 |= V_96 ;
}
error = F_145 ( V_33 , V_24 , V_1 ) ;
F_52 ( & V_37 -> V_51 -> V_1 ) ;
V_174 = F_150 ( V_158 ) ;
F_53 ( & V_37 -> V_51 -> V_1 ) ;
if ( ! error && V_174 != V_33 && V_54 . V_53 != V_6 ) {
V_54 . V_53 = V_6 ;
goto V_176;
}
V_92:
F_10 ( V_1 ) ;
return error ;
}
void F_153 ( struct V_32 * V_33 , V_36 V_106 )
{
struct V_1 V_34 ;
if ( ! F_25 ( V_33 ) -> V_82 )
return;
V_34 . V_8 = V_6 ;
V_34 . V_3 = V_52 | V_184 ;
V_34 . V_22 = 0 ;
V_34 . V_23 = V_40 ;
V_34 . V_19 = V_106 ;
V_34 . V_20 = V_37 -> V_38 ;
V_34 . V_21 = V_33 ;
V_34 . V_14 = NULL ;
V_34 . V_16 = NULL ;
F_144 ( V_33 , V_178 , & V_34 , NULL ) ;
if ( V_34 . V_14 && V_34 . V_14 -> V_15 )
V_34 . V_14 -> V_15 ( & V_34 ) ;
}
void F_154 ( struct V_32 * V_33 )
{
struct V_80 * V_80 = F_25 ( V_33 ) ;
struct V_1 * V_2 ;
struct V_1 * * V_88 ;
if ( ! V_80 -> V_82 )
return;
F_153 ( V_33 , ( V_36 ) V_33 ) ;
if ( V_33 -> V_156 -> V_54 ) {
struct V_1 V_2 = {
. V_19 = ( V_36 ) V_33 ,
. V_20 = V_37 -> V_38 ,
. V_21 = V_33 ,
. V_3 = V_39 ,
. V_8 = V_6 ,
. V_23 = V_40 ,
} ;
V_33 -> V_156 -> V_54 ( V_33 , V_180 , & V_2 ) ;
if ( V_2 . V_14 && V_2 . V_14 -> V_15 )
V_2 . V_14 -> V_15 ( & V_2 ) ;
}
F_52 ( & V_80 -> V_81 ) ;
V_88 = & V_80 -> V_82 ;
while ( ( V_2 = * V_88 ) != NULL ) {
if ( V_2 -> V_21 == V_33 ) {
if ( F_79 ( V_2 ) ) {
F_91 ( V_88 , V_6 ) ;
continue;
}
F_155 ( ! F_71 ( V_2 ) ,
L_2 ,
F_156 ( V_80 -> V_138 -> V_185 ) ,
F_157 ( V_80 -> V_138 -> V_185 ) , V_80 -> V_186 ,
V_2 -> V_8 , V_2 -> V_3 ,
V_2 -> V_22 , V_2 -> V_23 ) ;
F_67 ( V_88 ) ;
continue;
}
V_88 = & V_2 -> V_70 ;
}
F_53 ( & V_80 -> V_81 ) ;
}
int
F_158 ( struct V_1 * V_68 )
{
int V_187 = 0 ;
F_52 ( & V_71 ) ;
if ( V_68 -> V_70 )
F_49 ( V_68 ) ;
else
V_187 = - V_94 ;
F_53 ( & V_71 ) ;
return V_187 ;
}
int F_159 ( struct V_32 * V_33 , struct V_1 * V_2 )
{
if ( V_33 -> V_156 -> V_34 )
return V_33 -> V_156 -> V_34 ( V_33 , V_188 , V_2 ) ;
return 0 ;
}
static void F_160 ( struct V_189 * V_174 , struct V_1 * V_2 ,
T_1 V_190 , char * V_191 )
{
struct V_80 * V_80 = NULL ;
unsigned int V_20 ;
if ( V_2 -> V_75 )
V_20 = F_73 ( V_2 -> V_75 ) ;
else
V_20 = V_2 -> V_20 ;
if ( V_2 -> V_21 != NULL )
V_80 = F_25 ( V_2 -> V_21 ) ;
F_161 ( V_174 , L_3 , V_190 , V_191 ) ;
if ( F_56 ( V_2 ) ) {
if ( V_2 -> V_3 & V_90 )
F_162 ( V_174 , L_4 ) ;
else if ( F_57 ( V_2 ) )
F_162 ( V_174 , L_5 ) ;
else
F_162 ( V_174 , L_6 ) ;
F_161 ( V_174 , L_7 ,
( V_80 == NULL ) ? L_8 :
F_148 ( V_80 ) ? L_9 : L_10 ) ;
} else if ( F_71 ( V_2 ) ) {
if ( V_2 -> V_8 & V_25 ) {
F_162 ( V_174 , L_11 ) ;
} else {
F_162 ( V_174 , L_12 ) ;
}
} else if ( F_79 ( V_2 ) ) {
F_162 ( V_174 , L_13 ) ;
if ( F_1 ( V_2 ) )
F_162 ( V_174 , L_14 ) ;
else if ( V_2 -> V_21 )
F_162 ( V_174 , L_15 ) ;
else
F_162 ( V_174 , L_16 ) ;
} else {
F_162 ( V_174 , L_17 ) ;
}
if ( V_2 -> V_8 & V_25 ) {
F_161 ( V_174 , L_18 ,
( V_2 -> V_8 & V_192 )
? ( V_2 -> V_8 & V_193 ) ? L_19 : L_20
: ( V_2 -> V_8 & V_193 ) ? L_21 : L_22 ) ;
} else {
F_161 ( V_174 , L_18 ,
( F_1 ( V_2 ) )
? ( V_2 -> V_8 == V_6 ) ? L_23 : L_20
: ( V_2 -> V_8 == V_29 ) ? L_21 : L_20 ) ;
}
if ( V_80 ) {
#ifdef F_163
F_161 ( V_174 , L_24 , V_20 ,
V_80 -> V_138 -> V_194 , V_80 -> V_186 ) ;
#else
F_161 ( V_174 , L_25 , V_20 ,
F_156 ( V_80 -> V_138 -> V_185 ) ,
F_157 ( V_80 -> V_138 -> V_185 ) , V_80 -> V_186 ) ;
#endif
} else {
F_161 ( V_174 , L_26 , V_20 ) ;
}
if ( F_56 ( V_2 ) ) {
if ( V_2 -> V_23 == V_40 )
F_161 ( V_174 , L_27 , V_2 -> V_22 ) ;
else
F_161 ( V_174 , L_28 , V_2 -> V_22 , V_2 -> V_23 ) ;
} else {
F_162 ( V_174 , L_29 ) ;
}
}
static int F_164 ( struct V_189 * V_174 , void * V_195 )
{
struct V_196 * V_197 = V_174 -> V_198 ;
struct V_1 * V_2 , * V_199 ;
V_2 = F_165 ( V_195 , struct V_1 , V_9 ) ;
F_160 ( V_174 , V_2 , V_197 -> V_200 , L_30 ) ;
F_166 (bfl, &fl->fl_block, fl_block)
F_160 ( V_174 , V_199 , V_197 -> V_200 , L_31 ) ;
return 0 ;
}
static void * F_167 ( struct V_189 * V_174 , T_1 * V_74 )
__acquires( &blocked_lock_lock
static void * F_168 ( struct V_189 * V_174 , void * V_195 , T_1 * V_74 )
{
struct V_196 * V_197 = V_174 -> V_198 ;
++ V_197 -> V_200 ;
return F_169 ( V_195 , & V_66 , & V_197 -> V_201 , V_74 ) ;
}
static void F_170 ( struct V_189 * V_174 , void * V_195 )
__releases( &blocked_lock_lock
static int F_171 ( struct V_80 * V_80 , struct V_32 * V_33 )
{
return F_172 ( V_33 , & V_202 ,
sizeof( struct V_196 ) ) ;
}
static int T_4 F_173 ( void )
{
F_174 ( L_32 , 0 , NULL , & V_203 ) ;
return 0 ;
}
int F_175 ( struct V_80 * V_80 , T_1 V_204 , unsigned long V_205 )
{
struct V_1 * V_2 ;
int V_206 = 1 ;
F_52 ( & V_80 -> V_81 ) ;
for ( V_2 = V_80 -> V_82 ; V_2 != NULL ; V_2 = V_2 -> V_70 ) {
if ( F_56 ( V_2 ) ) {
if ( V_2 -> V_8 == V_7 )
continue;
if ( ( V_2 -> V_23 < V_204 ) || ( V_2 -> V_22 > ( V_204 + V_205 ) ) )
continue;
} else if ( F_71 ( V_2 ) ) {
if ( ! ( V_2 -> V_8 & V_25 ) )
continue;
if ( V_2 -> V_8 & V_192 )
continue;
} else
continue;
V_206 = 0 ;
break;
}
F_53 ( & V_80 -> V_81 ) ;
return V_206 ;
}
int F_176 ( struct V_80 * V_80 , T_1 V_204 , unsigned long V_205 )
{
struct V_1 * V_2 ;
int V_206 = 1 ;
F_52 ( & V_80 -> V_81 ) ;
for ( V_2 = V_80 -> V_82 ; V_2 != NULL ; V_2 = V_2 -> V_70 ) {
if ( F_56 ( V_2 ) ) {
if ( ( V_2 -> V_23 < V_204 ) || ( V_2 -> V_22 > ( V_204 + V_205 ) ) )
continue;
} else if ( F_71 ( V_2 ) ) {
if ( ! ( V_2 -> V_8 & V_25 ) )
continue;
if ( V_2 -> V_8 & V_193 )
continue;
} else
continue;
V_206 = 0 ;
break;
}
F_53 ( & V_80 -> V_81 ) ;
return V_206 ;
}
static int T_4 F_177 ( void )
{
int V_84 ;
V_12 = F_178 ( L_33 ,
sizeof( struct V_1 ) , 0 , V_207 , NULL ) ;
F_179 ( & V_64 , L_34 ) ;
F_180 (i)
F_181 ( F_182 ( & V_66 , V_84 ) ) ;
return 0 ;
}
