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
V_2 -> V_20 = V_36 -> V_37 ;
V_2 -> V_3 = V_38 ;
V_2 -> V_8 = type ;
V_2 -> V_23 = V_39 ;
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
struct V_40 * V_41 )
{
switch ( V_41 -> V_42 ) {
case V_43 :
V_2 -> V_22 = 0 ;
break;
case V_44 :
V_2 -> V_22 = V_33 -> V_45 ;
break;
case V_46 :
V_2 -> V_22 = F_24 ( F_25 ( V_33 ) ) ;
break;
default:
return - V_31 ;
}
if ( V_41 -> V_47 > V_39 - V_2 -> V_22 )
return - V_48 ;
V_2 -> V_22 += V_41 -> V_47 ;
if ( V_2 -> V_22 < 0 )
return - V_31 ;
if ( V_41 -> V_49 > 0 ) {
if ( V_41 -> V_49 - 1 > V_39 - V_2 -> V_22 )
return - V_48 ;
V_2 -> V_23 = V_2 -> V_22 + V_41 -> V_49 - 1 ;
} else if ( V_41 -> V_49 < 0 ) {
if ( V_2 -> V_22 + V_41 -> V_49 < 0 )
return - V_31 ;
V_2 -> V_23 = V_2 -> V_22 - 1 ;
V_2 -> V_22 += V_41 -> V_49 ;
} else
V_2 -> V_23 = V_39 ;
V_2 -> V_19 = V_36 -> V_50 ;
V_2 -> V_20 = V_36 -> V_37 ;
V_2 -> V_21 = V_33 ;
V_2 -> V_3 = V_51 ;
V_2 -> V_14 = NULL ;
V_2 -> V_16 = NULL ;
return F_22 ( V_2 , V_41 -> V_52 ) ;
}
static int F_26 ( struct V_32 * V_33 , struct V_1 * V_2 ,
struct V_53 * V_41 )
{
struct V_40 V_54 = {
. V_52 = V_41 -> V_52 ,
. V_42 = V_41 -> V_42 ,
. V_47 = V_41 -> V_47 ,
. V_49 = V_41 -> V_49 ,
} ;
return F_23 ( V_33 , V_2 , & V_54 ) ;
}
static void F_27 ( struct V_1 * V_2 )
{
F_28 ( & V_2 -> V_55 , V_56 , V_57 ) ;
}
static int F_29 ( struct V_32 * V_33 , long type , struct V_1 * V_2 )
{
if ( F_22 ( V_2 , type ) != 0 )
return - V_31 ;
V_2 -> V_19 = V_36 -> V_50 ;
V_2 -> V_20 = V_36 -> V_37 ;
V_2 -> V_21 = V_33 ;
V_2 -> V_3 = V_58 ;
V_2 -> V_22 = 0 ;
V_2 -> V_23 = V_39 ;
V_2 -> V_14 = NULL ;
V_2 -> V_16 = & V_59 ;
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
static inline int F_32 ( struct V_1 * V_60 , struct V_1 * V_61 )
{
return ( ( V_60 -> V_23 >= V_61 -> V_22 ) &&
( V_61 -> V_23 >= V_60 -> V_22 ) ) ;
}
static int F_33 ( struct V_1 * V_60 , struct V_1 * V_61 )
{
if ( V_60 -> V_16 && V_60 -> V_16 -> V_62 )
return V_61 -> V_16 == V_60 -> V_16 &&
V_60 -> V_16 -> V_62 ( V_60 , V_61 ) ;
return V_60 -> V_19 == V_61 -> V_19 ;
}
static void F_34 ( struct V_1 * V_2 )
{
F_35 ( & V_63 ) ;
V_2 -> V_64 = F_36 () ;
F_37 ( & V_2 -> V_9 , F_38 ( & V_65 ) ) ;
F_39 ( & V_63 ) ;
}
static void F_40 ( struct V_1 * V_2 )
{
if ( F_14 ( & V_2 -> V_9 ) )
return;
F_41 ( & V_63 , V_2 -> V_64 ) ;
F_42 ( & V_2 -> V_9 ) ;
F_43 ( & V_63 , V_2 -> V_64 ) ;
}
static unsigned long
F_44 ( struct V_1 * V_2 )
{
if ( V_2 -> V_16 && V_2 -> V_16 -> V_66 )
return V_2 -> V_16 -> V_66 ( V_2 ) ;
return ( unsigned long ) V_2 -> V_19 ;
}
static void F_45 ( struct V_1 * V_67 )
{
F_46 ( V_68 , & V_67 -> V_9 , F_44 ( V_67 ) ) ;
}
static void F_47 ( struct V_1 * V_67 )
{
F_48 ( & V_67 -> V_9 ) ;
}
static void F_49 ( struct V_1 * V_67 )
{
F_47 ( V_67 ) ;
F_50 ( & V_67 -> V_10 ) ;
V_67 -> V_69 = NULL ;
}
static void F_51 ( struct V_1 * V_67 )
{
F_52 ( & V_70 ) ;
F_49 ( V_67 ) ;
F_53 ( & V_70 ) ;
}
static void F_54 ( struct V_1 * V_71 ,
struct V_1 * V_67 )
{
F_11 ( ! F_13 ( & V_67 -> V_10 ) ) ;
V_67 -> V_69 = V_71 ;
F_55 ( & V_67 -> V_10 , & V_71 -> V_10 ) ;
if ( F_56 ( V_71 ) && ! F_57 ( V_71 ) )
F_45 ( V_67 ) ;
}
static void F_58 ( struct V_1 * V_71 ,
struct V_1 * V_67 )
{
F_52 ( & V_70 ) ;
F_54 ( V_71 , V_67 ) ;
F_53 ( & V_70 ) ;
}
static void F_59 ( struct V_1 * V_71 )
{
if ( F_13 ( & V_71 -> V_10 ) )
return;
F_52 ( & V_70 ) ;
while ( ! F_13 ( & V_71 -> V_10 ) ) {
struct V_1 * V_67 ;
V_67 = F_60 ( & V_71 -> V_10 ,
struct V_1 , V_10 ) ;
F_49 ( V_67 ) ;
if ( V_67 -> V_16 && V_67 -> V_16 -> V_72 )
V_67 -> V_16 -> V_72 ( V_67 ) ;
else
F_61 ( & V_67 -> V_11 ) ;
}
F_53 ( & V_70 ) ;
}
static void F_62 ( struct V_1 * * V_73 , struct V_1 * V_2 )
{
V_2 -> V_74 = F_63 ( F_64 ( V_36 ) ) ;
V_2 -> V_69 = * V_73 ;
* V_73 = V_2 ;
F_34 ( V_2 ) ;
}
static void F_65 ( struct V_1 * * V_75 )
{
struct V_1 * V_2 = * V_75 ;
F_40 ( V_2 ) ;
* V_75 = V_2 -> V_69 ;
V_2 -> V_69 = NULL ;
if ( V_2 -> V_74 ) {
F_66 ( V_2 -> V_74 ) ;
V_2 -> V_74 = NULL ;
}
F_59 ( V_2 ) ;
}
static void F_67 ( struct V_1 * * V_75 )
{
struct V_1 * V_2 = * V_75 ;
F_65 ( V_75 ) ;
F_10 ( V_2 ) ;
}
static int F_68 ( struct V_1 * V_76 , struct V_1 * V_77 )
{
if ( V_77 -> V_8 == V_29 )
return 1 ;
if ( V_76 -> V_8 == V_29 )
return 1 ;
return 0 ;
}
static int F_69 ( struct V_1 * V_76 , struct V_1 * V_77 )
{
if ( ! F_56 ( V_77 ) || F_33 ( V_76 , V_77 ) )
return ( 0 ) ;
if ( ! F_32 ( V_76 , V_77 ) )
return 0 ;
return ( F_68 ( V_76 , V_77 ) ) ;
}
static int F_70 ( struct V_1 * V_76 , struct V_1 * V_77 )
{
if ( ! F_71 ( V_77 ) || ( V_76 -> V_21 == V_77 -> V_21 ) )
return ( 0 ) ;
if ( ( V_76 -> V_8 & V_25 ) || ( V_77 -> V_8 & V_25 ) )
return 0 ;
return ( F_68 ( V_76 , V_77 ) ) ;
}
void
F_72 ( struct V_32 * V_33 , struct V_1 * V_2 )
{
struct V_1 * V_78 ;
struct V_79 * V_79 = F_25 ( V_33 ) ;
F_52 ( & V_79 -> V_80 ) ;
for ( V_78 = F_25 ( V_33 ) -> V_81 ; V_78 ; V_78 = V_78 -> V_69 ) {
if ( ! F_56 ( V_78 ) )
continue;
if ( F_69 ( V_2 , V_78 ) )
break;
}
if ( V_78 ) {
F_18 ( V_2 , V_78 ) ;
if ( V_78 -> V_74 )
V_2 -> V_20 = F_73 ( V_78 -> V_74 ) ;
} else
V_2 -> V_8 = V_6 ;
F_53 ( & V_79 -> V_80 ) ;
return;
}
static struct V_1 * F_74 ( struct V_1 * V_82 )
{
struct V_1 * V_2 ;
F_75 (blocked_hash, fl, fl_link, posix_owner_key(block_fl)) {
if ( F_33 ( V_2 , V_82 ) )
return V_2 -> V_69 ;
}
return NULL ;
}
static int F_76 ( struct V_1 * V_76 ,
struct V_1 * V_82 )
{
int V_83 = 0 ;
if ( F_57 ( V_76 ) )
return 0 ;
while ( ( V_82 = F_74 ( V_82 ) ) ) {
if ( V_83 ++ > V_84 )
return 0 ;
if ( F_33 ( V_76 , V_82 ) )
return 1 ;
}
return 0 ;
}
static int F_77 ( struct V_32 * V_33 , struct V_1 * V_85 )
{
struct V_1 * V_86 = NULL ;
struct V_1 * * V_87 ;
struct V_79 * V_79 = F_25 ( V_33 ) ;
int error = 0 ;
int V_88 = 0 ;
if ( ! ( V_85 -> V_3 & V_89 ) && ( V_85 -> V_8 != V_6 ) ) {
V_86 = F_7 () ;
if ( ! V_86 )
return - V_35 ;
}
F_52 ( & V_79 -> V_80 ) ;
if ( V_85 -> V_3 & V_89 )
goto V_90;
F_78 (inode, before) {
struct V_1 * V_2 = * V_87 ;
if ( F_56 ( V_2 ) )
break;
if ( F_79 ( V_2 ) )
continue;
if ( V_33 != V_2 -> V_21 )
continue;
if ( V_85 -> V_8 == V_2 -> V_8 )
goto V_91;
V_88 = 1 ;
F_67 ( V_87 ) ;
break;
}
if ( V_85 -> V_8 == V_6 ) {
if ( ( V_85 -> V_3 & V_92 ) && ! V_88 )
error = - V_93 ;
goto V_91;
}
if ( V_88 ) {
F_53 ( & V_79 -> V_80 ) ;
F_80 () ;
F_52 ( & V_79 -> V_80 ) ;
}
V_90:
F_78 (inode, before) {
struct V_1 * V_2 = * V_87 ;
if ( F_56 ( V_2 ) )
break;
if ( F_79 ( V_2 ) )
continue;
if ( ! F_70 ( V_85 , V_2 ) )
continue;
error = - V_94 ;
if ( ! ( V_85 -> V_3 & V_95 ) )
goto V_91;
error = V_96 ;
F_58 ( V_2 , V_85 ) ;
goto V_91;
}
if ( V_85 -> V_3 & V_89 )
goto V_91;
F_19 ( V_86 , V_85 ) ;
F_62 ( V_87 , V_86 ) ;
V_86 = NULL ;
error = 0 ;
V_91:
F_53 ( & V_79 -> V_80 ) ;
if ( V_86 )
F_10 ( V_86 ) ;
return error ;
}
static int F_81 ( struct V_79 * V_79 , struct V_1 * V_85 , struct V_1 * V_97 )
{
struct V_1 * V_2 ;
struct V_1 * V_86 = NULL ;
struct V_1 * V_98 = NULL ;
struct V_1 * V_99 = NULL ;
struct V_1 * V_100 = NULL ;
struct V_1 * * V_87 ;
int error ;
bool V_101 = false ;
if ( ! ( V_85 -> V_3 & V_89 ) &&
( V_85 -> V_8 != V_6 ||
V_85 -> V_22 != 0 || V_85 -> V_23 != V_39 ) ) {
V_86 = F_7 () ;
V_98 = F_7 () ;
}
F_52 ( & V_79 -> V_80 ) ;
if ( V_85 -> V_8 != V_6 ) {
F_78 (inode, before) {
V_2 = * V_87 ;
if ( ! F_56 ( V_2 ) )
continue;
if ( ! F_69 ( V_85 , V_2 ) )
continue;
if ( V_97 )
F_18 ( V_97 , V_2 ) ;
error = - V_94 ;
if ( ! ( V_85 -> V_3 & V_95 ) )
goto V_91;
error = - V_102 ;
F_52 ( & V_70 ) ;
if ( F_82 ( ! F_76 ( V_85 , V_2 ) ) ) {
error = V_96 ;
F_54 ( V_2 , V_85 ) ;
}
F_53 ( & V_70 ) ;
goto V_91;
}
}
error = 0 ;
if ( V_85 -> V_3 & V_89 )
goto V_91;
V_87 = & V_79 -> V_81 ;
while ( ( V_2 = * V_87 ) && ( ! F_56 ( V_2 ) ||
! F_33 ( V_85 , V_2 ) ) ) {
V_87 = & V_2 -> V_69 ;
}
while ( ( V_2 = * V_87 ) && F_33 ( V_85 , V_2 ) ) {
if ( V_85 -> V_8 == V_2 -> V_8 ) {
if ( V_2 -> V_23 < V_85 -> V_22 - 1 )
goto V_103;
if ( V_2 -> V_22 - 1 > V_85 -> V_23 )
break;
if ( V_2 -> V_22 > V_85 -> V_22 )
V_2 -> V_22 = V_85 -> V_22 ;
else
V_85 -> V_22 = V_2 -> V_22 ;
if ( V_2 -> V_23 < V_85 -> V_23 )
V_2 -> V_23 = V_85 -> V_23 ;
else
V_85 -> V_23 = V_2 -> V_23 ;
if ( V_101 ) {
F_67 ( V_87 ) ;
continue;
}
V_85 = V_2 ;
V_101 = true ;
}
else {
if ( V_2 -> V_23 < V_85 -> V_22 )
goto V_103;
if ( V_2 -> V_22 > V_85 -> V_23 )
break;
if ( V_85 -> V_8 == V_6 )
V_101 = true ;
if ( V_2 -> V_22 < V_85 -> V_22 )
V_99 = V_2 ;
if ( V_2 -> V_23 > V_85 -> V_23 ) {
V_100 = V_2 ;
break;
}
if ( V_2 -> V_22 >= V_85 -> V_22 ) {
if ( V_101 ) {
F_67 ( V_87 ) ;
continue;
}
F_59 ( V_2 ) ;
V_2 -> V_22 = V_85 -> V_22 ;
V_2 -> V_23 = V_85 -> V_23 ;
V_2 -> V_8 = V_85 -> V_8 ;
F_9 ( V_2 ) ;
F_17 ( V_2 , V_85 ) ;
V_85 = V_2 ;
V_101 = true ;
}
}
V_103:
V_87 = & V_2 -> V_69 ;
}
error = - V_104 ;
if ( V_100 && V_99 == V_100 && ! V_98 )
goto V_91;
error = 0 ;
if ( ! V_101 ) {
if ( V_85 -> V_8 == V_6 ) {
if ( V_85 -> V_3 & V_92 )
error = - V_93 ;
goto V_91;
}
if ( ! V_86 ) {
error = - V_104 ;
goto V_91;
}
F_19 ( V_86 , V_85 ) ;
F_62 ( V_87 , V_86 ) ;
V_86 = NULL ;
}
if ( V_100 ) {
if ( V_99 == V_100 ) {
V_99 = V_98 ;
V_98 = NULL ;
F_19 ( V_99 , V_100 ) ;
F_62 ( V_87 , V_99 ) ;
}
V_100 -> V_22 = V_85 -> V_23 + 1 ;
F_59 ( V_100 ) ;
}
if ( V_99 ) {
V_99 -> V_23 = V_85 -> V_22 - 1 ;
F_59 ( V_99 ) ;
}
V_91:
F_53 ( & V_79 -> V_80 ) ;
if ( V_86 )
F_10 ( V_86 ) ;
if ( V_98 )
F_10 ( V_98 ) ;
return error ;
}
int F_83 ( struct V_32 * V_33 , struct V_1 * V_2 ,
struct V_1 * V_97 )
{
return F_81 ( F_25 ( V_33 ) , V_2 , V_97 ) ;
}
int F_84 ( struct V_32 * V_33 , struct V_1 * V_2 )
{
int error ;
F_85 () ;
for (; ; ) {
error = F_83 ( V_33 , V_2 , NULL ) ;
if ( error != V_96 )
break;
error = F_86 ( V_2 -> V_11 , ! V_2 -> V_69 ) ;
if ( ! error )
continue;
F_51 ( V_2 ) ;
break;
}
return error ;
}
int F_87 ( struct V_32 * V_32 )
{
struct V_79 * V_79 = F_25 ( V_32 ) ;
T_1 V_105 = V_36 -> V_50 ;
struct V_1 * V_2 ;
F_52 ( & V_79 -> V_80 ) ;
for ( V_2 = V_79 -> V_81 ; V_2 != NULL ; V_2 = V_2 -> V_69 ) {
if ( ! F_56 ( V_2 ) )
continue;
if ( V_2 -> V_19 != V_105 && V_2 -> V_19 != ( T_1 ) V_32 )
break;
}
F_53 ( & V_79 -> V_80 ) ;
return V_2 ? - V_94 : 0 ;
}
int F_88 ( int V_106 , struct V_79 * V_79 ,
struct V_32 * V_33 , T_2 V_107 ,
T_3 V_108 )
{
struct V_1 V_2 ;
int error ;
bool V_109 = false ;
F_16 ( & V_2 ) ;
V_2 . V_20 = V_36 -> V_37 ;
V_2 . V_21 = V_33 ;
V_2 . V_3 = V_51 | V_89 ;
if ( V_33 && ! ( V_33 -> V_110 & V_111 ) )
V_109 = true ;
V_2 . V_8 = ( V_106 == V_112 ) ? V_29 : V_7 ;
V_2 . V_22 = V_107 ;
V_2 . V_23 = V_107 + V_108 - 1 ;
for (; ; ) {
if ( V_33 ) {
V_2 . V_19 = ( T_1 ) V_33 ;
V_2 . V_3 &= ~ V_95 ;
error = F_81 ( V_79 , & V_2 , NULL ) ;
if ( ! error )
break;
}
if ( V_109 )
V_2 . V_3 |= V_95 ;
V_2 . V_19 = V_36 -> V_50 ;
error = F_81 ( V_79 , & V_2 , NULL ) ;
if ( error != V_96 )
break;
error = F_86 ( V_2 . V_11 , ! V_2 . V_69 ) ;
if ( ! error ) {
if ( F_89 ( V_79 ) )
continue;
}
F_51 ( & V_2 ) ;
break;
}
return error ;
}
static void F_90 ( struct V_1 * V_2 , int V_113 )
{
switch ( V_113 ) {
case V_6 :
V_2 -> V_3 &= ~ V_4 ;
case V_7 :
V_2 -> V_3 &= ~ V_5 ;
}
}
int F_91 ( struct V_1 * * V_87 , int V_113 )
{
struct V_1 * V_2 = * V_87 ;
int error = F_22 ( V_2 , V_113 ) ;
if ( error )
return error ;
F_90 ( V_2 , V_113 ) ;
F_59 ( V_2 ) ;
if ( V_113 == V_6 ) {
struct V_32 * V_33 = V_2 -> V_21 ;
F_92 ( V_33 ) ;
V_33 -> V_114 . V_115 = 0 ;
F_93 ( 0 , V_2 -> V_21 , 0 , & V_2 -> V_55 ) ;
if ( V_2 -> V_55 != NULL ) {
F_94 ( V_116 L_1 , V_2 -> V_55 ) ;
V_2 -> V_55 = NULL ;
}
F_67 ( V_87 ) ;
}
return 0 ;
}
static bool F_95 ( unsigned long V_117 )
{
if ( ! V_117 )
return false ;
return F_96 ( V_118 , V_117 ) ;
}
static void F_97 ( struct V_79 * V_79 )
{
struct V_1 * * V_87 ;
struct V_1 * V_2 ;
V_87 = & V_79 -> V_81 ;
while ( ( V_2 = * V_87 ) && F_79 ( V_2 ) && F_1 ( V_2 ) ) {
if ( F_95 ( V_2 -> V_119 ) )
F_91 ( V_87 , V_7 ) ;
if ( F_95 ( V_2 -> V_120 ) )
F_91 ( V_87 , V_6 ) ;
if ( V_2 == * V_87 )
V_87 = & V_2 -> V_69 ;
}
}
static bool F_98 ( struct V_1 * V_121 , struct V_1 * V_122 )
{
if ( ( V_122 -> V_3 & V_123 ) && ( V_121 -> V_3 & V_58 ) )
return false ;
return F_68 ( V_122 , V_121 ) ;
}
int F_99 ( struct V_79 * V_79 , unsigned int V_124 , unsigned int type )
{
int error = 0 ;
struct V_1 * V_86 , * V_53 ;
struct V_1 * V_2 ;
unsigned long V_125 ;
int V_126 = 0 ;
bool V_127 = false ;
int V_128 = ( V_124 & V_129 ) != V_130 ;
V_86 = F_30 ( NULL , V_128 ? V_29 : V_7 ) ;
if ( F_100 ( V_86 ) )
return F_101 ( V_86 ) ;
V_86 -> V_3 = type ;
F_52 ( & V_79 -> V_80 ) ;
F_97 ( V_79 ) ;
V_53 = V_79 -> V_81 ;
if ( ( V_53 == NULL ) || ! F_79 ( V_53 ) )
goto V_91;
for ( V_2 = V_53 ; V_2 && F_79 ( V_2 ) ; V_2 = V_2 -> V_69 ) {
if ( F_98 ( V_2 , V_86 ) ) {
V_127 = true ;
if ( V_2 -> V_19 == V_36 -> V_50 )
V_126 = 1 ;
}
}
if ( ! V_127 )
goto V_91;
V_125 = 0 ;
if ( V_131 > 0 ) {
V_125 = V_118 + V_131 * V_132 ;
if ( V_125 == 0 )
V_125 ++ ;
}
for ( V_2 = V_53 ; V_2 && F_79 ( V_2 ) ; V_2 = V_2 -> V_69 ) {
if ( ! F_98 ( V_2 , V_86 ) )
continue;
if ( V_128 ) {
if ( V_2 -> V_3 & V_4 )
continue;
V_2 -> V_3 |= V_4 ;
V_2 -> V_120 = V_125 ;
} else {
if ( F_1 ( V_53 ) )
continue;
V_2 -> V_3 |= V_5 ;
V_2 -> V_119 = V_125 ;
}
V_2 -> V_16 -> V_133 ( V_2 ) ;
}
if ( V_126 || ( V_124 & V_111 ) ) {
error = - V_134 ;
goto V_91;
}
V_135:
V_125 = V_53 -> V_120 ;
if ( V_125 != 0 )
V_125 -= V_118 ;
if ( V_125 == 0 )
V_125 ++ ;
F_58 ( V_53 , V_86 ) ;
F_53 ( & V_79 -> V_80 ) ;
error = F_102 ( V_86 -> V_11 ,
! V_86 -> V_69 , V_125 ) ;
F_52 ( & V_79 -> V_80 ) ;
F_51 ( V_86 ) ;
if ( error >= 0 ) {
if ( error == 0 )
F_97 ( V_79 ) ;
for ( V_53 = V_79 -> V_81 ; V_53 && F_79 ( V_53 ) ;
V_53 = V_53 -> V_69 ) {
if ( F_98 ( V_86 , V_53 ) )
goto V_135;
}
error = 0 ;
}
V_91:
F_53 ( & V_79 -> V_80 ) ;
F_10 ( V_86 ) ;
return error ;
}
void F_103 ( struct V_79 * V_79 , struct V_136 * time )
{
struct V_1 * V_53 = V_79 -> V_81 ;
if ( V_53 && F_79 ( V_53 ) && ( V_53 -> V_8 == V_29 ) )
* time = F_104 ( V_79 -> V_137 ) ;
else
* time = V_79 -> V_138 ;
}
int F_105 ( struct V_32 * V_33 )
{
struct V_1 * V_2 ;
struct V_79 * V_79 = F_25 ( V_33 ) ;
int type = V_6 ;
F_52 ( & V_79 -> V_80 ) ;
F_97 ( F_25 ( V_33 ) ) ;
for ( V_2 = F_25 ( V_33 ) -> V_81 ; V_2 && F_79 ( V_2 ) ;
V_2 = V_2 -> V_69 ) {
if ( V_2 -> V_21 == V_33 ) {
type = F_2 ( V_2 ) ;
break;
}
}
F_53 ( & V_79 -> V_80 ) ;
return type ;
}
static int
F_106 ( const struct V_139 * V_139 , const long V_113 )
{
int V_140 = 0 ;
struct V_79 * V_79 = V_139 -> V_141 ;
if ( ( V_113 == V_7 ) && ( F_107 ( & V_79 -> V_142 ) > 0 ) )
return - V_94 ;
if ( ( V_113 == V_29 ) && ( ( F_108 ( V_139 ) > 1 ) ||
( F_107 ( & V_79 -> V_143 ) > 1 ) ) )
V_140 = - V_94 ;
return V_140 ;
}
static int F_109 ( struct V_32 * V_33 , long V_113 , struct V_1 * * V_144 )
{
struct V_1 * V_2 , * * V_87 , * * V_145 = NULL , * V_121 ;
struct V_139 * V_139 = V_33 -> V_146 . V_139 ;
struct V_79 * V_79 = V_139 -> V_141 ;
bool V_147 = ( * V_144 ) -> V_3 & V_123 ;
int error ;
V_121 = * V_144 ;
if ( V_147 && ! F_110 ( & V_79 -> V_148 ) )
return - V_94 ;
if ( V_147 && V_113 == V_29 ) {
F_111 ( & V_79 -> V_148 ) ;
F_112 ( 1 ) ;
return - V_31 ;
}
error = F_106 ( V_139 , V_113 ) ;
if ( error )
goto V_91;
error = - V_94 ;
for ( V_87 = & V_79 -> V_81 ;
( ( V_2 = * V_87 ) != NULL ) && F_79 ( V_2 ) ;
V_87 = & V_2 -> V_69 ) {
if ( V_2 -> V_21 == V_33 ) {
V_145 = V_87 ;
continue;
}
if ( V_113 == V_29 )
goto V_91;
if ( V_2 -> V_3 & V_4 )
goto V_91;
}
if ( V_145 != NULL ) {
error = V_121 -> V_16 -> V_149 ( V_145 , V_113 ) ;
if ( ! error )
* V_144 = * V_145 ;
goto V_91;
}
error = - V_31 ;
if ( ! V_150 )
goto V_91;
F_62 ( V_87 , V_121 ) ;
F_113 () ;
error = F_106 ( V_139 , V_113 ) ;
if ( error )
F_65 ( V_144 ) ;
V_91:
if ( V_147 )
F_111 ( & V_79 -> V_148 ) ;
return error ;
}
static int F_114 ( struct V_32 * V_33 , struct V_1 * * V_144 )
{
struct V_1 * V_2 , * * V_87 ;
struct V_139 * V_139 = V_33 -> V_146 . V_139 ;
struct V_79 * V_79 = V_139 -> V_141 ;
for ( V_87 = & V_79 -> V_81 ;
( ( V_2 = * V_87 ) != NULL ) && F_79 ( V_2 ) ;
V_87 = & V_2 -> V_69 ) {
if ( V_2 -> V_21 != V_33 )
continue;
return ( * V_144 ) -> V_16 -> V_149 ( V_87 , V_6 ) ;
}
return - V_94 ;
}
int F_115 ( struct V_32 * V_33 , long V_113 , struct V_1 * * V_144 )
{
struct V_139 * V_139 = V_33 -> V_146 . V_139 ;
struct V_79 * V_79 = V_139 -> V_141 ;
int error ;
if ( ( ! F_116 ( F_117 () , V_79 -> V_151 ) ) && ! F_118 ( V_152 ) )
return - V_153 ;
if ( ! F_119 ( V_79 -> V_154 ) )
return - V_31 ;
error = F_120 ( V_33 , V_113 ) ;
if ( error )
return error ;
F_97 ( V_79 ) ;
F_11 ( ! ( * V_144 ) -> V_16 -> V_133 ) ;
switch ( V_113 ) {
case V_6 :
return F_114 ( V_33 , V_144 ) ;
case V_7 :
case V_29 :
return F_109 ( V_33 , V_113 , V_144 ) ;
default:
return - V_31 ;
}
}
static int F_121 ( struct V_32 * V_33 , long V_113 , struct V_1 * * V_121 )
{
if ( V_33 -> V_155 -> V_156 )
return V_33 -> V_155 -> V_156 ( V_33 , V_113 , V_121 ) ;
else
return F_115 ( V_33 , V_113 , V_121 ) ;
}
int F_122 ( struct V_32 * V_33 , long V_113 , struct V_1 * * V_121 )
{
struct V_79 * V_79 = F_25 ( V_33 ) ;
int error ;
F_52 ( & V_79 -> V_80 ) ;
error = F_121 ( V_33 , V_113 , V_121 ) ;
F_53 ( & V_79 -> V_80 ) ;
return error ;
}
static int F_123 ( struct V_32 * V_33 )
{
struct V_1 V_2 , * V_144 = & V_2 ;
F_29 ( V_33 , V_6 , V_144 ) ;
return F_122 ( V_33 , V_6 , & V_144 ) ;
}
static int F_124 ( unsigned int V_157 , struct V_32 * V_33 , long V_113 )
{
struct V_1 * V_2 , * V_140 ;
struct V_79 * V_79 = F_25 ( V_33 ) ;
struct V_158 * V_17 ;
int error ;
V_2 = F_30 ( V_33 , V_113 ) ;
if ( F_100 ( V_2 ) )
return F_101 ( V_2 ) ;
V_17 = F_125 () ;
if ( ! V_17 ) {
F_10 ( V_2 ) ;
return - V_35 ;
}
V_140 = V_2 ;
F_52 ( & V_79 -> V_80 ) ;
error = F_121 ( V_33 , V_113 , & V_140 ) ;
if ( error ) {
F_53 ( & V_79 -> V_80 ) ;
F_10 ( V_2 ) ;
goto V_159;
}
if ( V_140 != V_2 )
F_10 ( V_2 ) ;
if ( ! F_126 ( V_157 , V_33 , & V_140 -> V_55 , V_17 ) )
V_17 = NULL ;
error = F_127 ( V_33 , F_128 ( V_36 ) , V_160 , 0 ) ;
F_53 ( & V_79 -> V_80 ) ;
V_159:
if ( V_17 )
F_129 ( V_17 ) ;
return error ;
}
int F_130 ( unsigned int V_157 , struct V_32 * V_33 , long V_113 )
{
if ( V_113 == V_6 )
return F_123 ( V_33 ) ;
return F_124 ( V_157 , V_33 , V_113 ) ;
}
int F_131 ( struct V_32 * V_33 , struct V_1 * V_2 )
{
int error ;
F_85 () ;
for (; ; ) {
error = F_77 ( V_33 , V_2 ) ;
if ( error != V_96 )
break;
error = F_86 ( V_2 -> V_11 , ! V_2 -> V_69 ) ;
if ( ! error )
continue;
F_51 ( V_2 ) ;
break;
}
return error ;
}
int F_132 ( struct V_32 * V_33 , struct V_1 * V_2 )
{
if ( V_33 -> V_155 -> V_34 )
return V_33 -> V_155 -> V_34 ( V_33 , V_161 , V_2 ) ;
F_72 ( V_33 , V_2 ) ;
return 0 ;
}
static int F_133 ( struct V_53 * V_53 , struct V_1 * V_2 )
{
V_53 -> V_162 = F_57 ( V_2 ) ? - 1 : V_2 -> V_20 ;
#if V_163 == 32
if ( V_2 -> V_22 > V_164 )
return - V_48 ;
if ( V_2 -> V_23 != V_39 && V_2 -> V_23 > V_164 )
return - V_48 ;
#endif
V_53 -> V_47 = V_2 -> V_22 ;
V_53 -> V_49 = V_2 -> V_23 == V_39 ? 0 :
V_2 -> V_23 - V_2 -> V_22 + 1 ;
V_53 -> V_42 = 0 ;
V_53 -> V_52 = V_2 -> V_8 ;
return 0 ;
}
static void F_134 ( struct V_40 * V_53 , struct V_1 * V_2 )
{
V_53 -> V_162 = F_57 ( V_2 ) ? - 1 : V_2 -> V_20 ;
V_53 -> V_47 = V_2 -> V_22 ;
V_53 -> V_49 = V_2 -> V_23 == V_39 ? 0 :
V_2 -> V_23 - V_2 -> V_22 + 1 ;
V_53 -> V_42 = 0 ;
V_53 -> V_52 = V_2 -> V_8 ;
}
int F_135 ( struct V_32 * V_33 , unsigned int V_24 , struct V_53 T_4 * V_41 )
{
struct V_1 V_1 ;
struct V_53 V_53 ;
int error ;
error = - V_165 ;
if ( F_136 ( & V_53 , V_41 , sizeof( V_53 ) ) )
goto V_91;
error = - V_31 ;
if ( ( V_53 . V_52 != V_7 ) && ( V_53 . V_52 != V_29 ) )
goto V_91;
error = F_26 ( V_33 , & V_1 , & V_53 ) ;
if ( error )
goto V_91;
if ( V_24 == V_166 ) {
error = - V_31 ;
if ( V_53 . V_162 != 0 )
goto V_91;
V_24 = V_161 ;
V_1 . V_3 |= V_167 ;
V_1 . V_19 = ( T_1 ) V_33 ;
}
error = F_132 ( V_33 , & V_1 ) ;
if ( error )
goto V_91;
V_53 . V_52 = V_1 . V_8 ;
if ( V_1 . V_8 != V_6 ) {
error = F_133 ( & V_53 , & V_1 ) ;
if ( error )
goto V_91;
}
error = - V_165 ;
if ( ! F_137 ( V_41 , & V_53 , sizeof( V_53 ) ) )
error = 0 ;
V_91:
return error ;
}
int F_138 ( struct V_32 * V_33 , unsigned int V_24 , struct V_1 * V_2 , struct V_1 * V_168 )
{
if ( V_33 -> V_155 -> V_34 )
return V_33 -> V_155 -> V_34 ( V_33 , V_24 , V_2 ) ;
else
return F_83 ( V_33 , V_2 , V_168 ) ;
}
static int F_139 ( struct V_32 * V_33 , unsigned int V_24 ,
struct V_1 * V_2 )
{
int error ;
error = F_120 ( V_33 , V_2 -> V_8 ) ;
if ( error )
return error ;
for (; ; ) {
error = F_138 ( V_33 , V_24 , V_2 , NULL ) ;
if ( error != V_96 )
break;
error = F_86 ( V_2 -> V_11 , ! V_2 -> V_69 ) ;
if ( ! error )
continue;
F_51 ( V_2 ) ;
break;
}
return error ;
}
static int
F_140 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_8 ) {
case V_7 :
if ( ! ( V_2 -> V_21 -> V_169 & V_170 ) )
return - V_171 ;
break;
case V_29 :
if ( ! ( V_2 -> V_21 -> V_169 & V_172 ) )
return - V_171 ;
}
return 0 ;
}
int F_141 ( unsigned int V_157 , struct V_32 * V_33 , unsigned int V_24 ,
struct V_53 T_4 * V_41 )
{
struct V_1 * V_1 = F_7 () ;
struct V_53 V_53 ;
struct V_79 * V_79 ;
struct V_32 * V_173 ;
int error ;
if ( V_1 == NULL )
return - V_104 ;
error = - V_165 ;
if ( F_136 ( & V_53 , V_41 , sizeof( V_53 ) ) )
goto V_91;
V_79 = F_25 ( V_33 ) ;
if ( F_142 ( V_79 ) && F_143 ( V_33 -> V_174 ) ) {
error = - V_94 ;
goto V_91;
}
V_175:
error = F_26 ( V_33 , V_1 , & V_53 ) ;
if ( error )
goto V_91;
error = F_140 ( V_1 ) ;
if ( error )
goto V_91;
switch ( V_24 ) {
case V_176 :
error = - V_31 ;
if ( V_53 . V_162 != 0 )
goto V_91;
V_24 = V_177 ;
V_1 -> V_3 |= V_167 ;
V_1 -> V_19 = ( T_1 ) V_33 ;
break;
case V_178 :
error = - V_31 ;
if ( V_53 . V_162 != 0 )
goto V_91;
V_24 = V_179 ;
V_1 -> V_3 |= V_167 ;
V_1 -> V_19 = ( T_1 ) V_33 ;
case V_179 :
V_1 -> V_3 |= V_95 ;
}
error = F_139 ( V_33 , V_24 , V_1 ) ;
F_52 ( & V_36 -> V_50 -> V_1 ) ;
V_173 = F_144 ( V_157 ) ;
F_53 ( & V_36 -> V_50 -> V_1 ) ;
if ( ! error && V_173 != V_33 && V_53 . V_52 != V_6 ) {
V_53 . V_52 = V_6 ;
goto V_175;
}
V_91:
F_10 ( V_1 ) ;
return error ;
}
int F_145 ( struct V_32 * V_33 , unsigned int V_24 , struct V_40 T_4 * V_41 )
{
struct V_1 V_1 ;
struct V_40 V_53 ;
int error ;
error = - V_165 ;
if ( F_136 ( & V_53 , V_41 , sizeof( V_53 ) ) )
goto V_91;
error = - V_31 ;
if ( ( V_53 . V_52 != V_7 ) && ( V_53 . V_52 != V_29 ) )
goto V_91;
error = F_23 ( V_33 , & V_1 , & V_53 ) ;
if ( error )
goto V_91;
if ( V_24 == V_166 ) {
error = - V_31 ;
if ( V_53 . V_162 != 0 )
goto V_91;
V_24 = V_180 ;
V_1 . V_3 |= V_167 ;
V_1 . V_19 = ( T_1 ) V_33 ;
}
error = F_132 ( V_33 , & V_1 ) ;
if ( error )
goto V_91;
V_53 . V_52 = V_1 . V_8 ;
if ( V_1 . V_8 != V_6 )
F_134 ( & V_53 , & V_1 ) ;
error = - V_165 ;
if ( ! F_137 ( V_41 , & V_53 , sizeof( V_53 ) ) )
error = 0 ;
V_91:
return error ;
}
int F_146 ( unsigned int V_157 , struct V_32 * V_33 , unsigned int V_24 ,
struct V_40 T_4 * V_41 )
{
struct V_1 * V_1 = F_7 () ;
struct V_40 V_53 ;
struct V_79 * V_79 ;
struct V_32 * V_173 ;
int error ;
if ( V_1 == NULL )
return - V_104 ;
error = - V_165 ;
if ( F_136 ( & V_53 , V_41 , sizeof( V_53 ) ) )
goto V_91;
V_79 = F_25 ( V_33 ) ;
if ( F_142 ( V_79 ) && F_143 ( V_33 -> V_174 ) ) {
error = - V_94 ;
goto V_91;
}
V_175:
error = F_23 ( V_33 , V_1 , & V_53 ) ;
if ( error )
goto V_91;
error = F_140 ( V_1 ) ;
if ( error )
goto V_91;
switch ( V_24 ) {
case V_176 :
error = - V_31 ;
if ( V_53 . V_162 != 0 )
goto V_91;
V_24 = V_181 ;
V_1 -> V_3 |= V_167 ;
V_1 -> V_19 = ( T_1 ) V_33 ;
break;
case V_178 :
error = - V_31 ;
if ( V_53 . V_162 != 0 )
goto V_91;
V_24 = V_182 ;
V_1 -> V_3 |= V_167 ;
V_1 -> V_19 = ( T_1 ) V_33 ;
case V_182 :
V_1 -> V_3 |= V_95 ;
}
error = F_139 ( V_33 , V_24 , V_1 ) ;
F_52 ( & V_36 -> V_50 -> V_1 ) ;
V_173 = F_144 ( V_157 ) ;
F_53 ( & V_36 -> V_50 -> V_1 ) ;
if ( ! error && V_173 != V_33 && V_53 . V_52 != V_6 ) {
V_53 . V_52 = V_6 ;
goto V_175;
}
V_91:
F_10 ( V_1 ) ;
return error ;
}
void F_147 ( struct V_32 * V_33 , T_1 V_105 )
{
struct V_1 V_34 ;
if ( ! F_25 ( V_33 ) -> V_81 )
return;
V_34 . V_8 = V_6 ;
V_34 . V_3 = V_51 | V_183 ;
V_34 . V_22 = 0 ;
V_34 . V_23 = V_39 ;
V_34 . V_19 = V_105 ;
V_34 . V_20 = V_36 -> V_37 ;
V_34 . V_21 = V_33 ;
V_34 . V_14 = NULL ;
V_34 . V_16 = NULL ;
F_138 ( V_33 , V_177 , & V_34 , NULL ) ;
if ( V_34 . V_14 && V_34 . V_14 -> V_15 )
V_34 . V_14 -> V_15 ( & V_34 ) ;
}
void F_148 ( struct V_32 * V_33 )
{
struct V_79 * V_79 = F_25 ( V_33 ) ;
struct V_1 * V_2 ;
struct V_1 * * V_87 ;
if ( ! V_79 -> V_81 )
return;
F_147 ( V_33 , ( T_1 ) V_33 ) ;
if ( V_33 -> V_155 -> V_53 ) {
struct V_1 V_2 = {
. V_20 = V_36 -> V_37 ,
. V_21 = V_33 ,
. V_3 = V_38 ,
. V_8 = V_6 ,
. V_23 = V_39 ,
} ;
V_33 -> V_155 -> V_53 ( V_33 , V_179 , & V_2 ) ;
if ( V_2 . V_14 && V_2 . V_14 -> V_15 )
V_2 . V_14 -> V_15 ( & V_2 ) ;
}
F_52 ( & V_79 -> V_80 ) ;
V_87 = & V_79 -> V_81 ;
while ( ( V_2 = * V_87 ) != NULL ) {
if ( V_2 -> V_21 == V_33 ) {
if ( F_79 ( V_2 ) ) {
F_91 ( V_87 , V_6 ) ;
continue;
}
F_149 ( ! F_71 ( V_2 ) ,
L_2 ,
F_150 ( V_79 -> V_137 -> V_184 ) ,
F_151 ( V_79 -> V_137 -> V_184 ) , V_79 -> V_185 ,
V_2 -> V_8 , V_2 -> V_3 ,
V_2 -> V_22 , V_2 -> V_23 ) ;
F_67 ( V_87 ) ;
continue;
}
V_87 = & V_2 -> V_69 ;
}
F_53 ( & V_79 -> V_80 ) ;
}
int
F_152 ( struct V_1 * V_67 )
{
int V_186 = 0 ;
F_52 ( & V_70 ) ;
if ( V_67 -> V_69 )
F_49 ( V_67 ) ;
else
V_186 = - V_93 ;
F_53 ( & V_70 ) ;
return V_186 ;
}
int F_153 ( struct V_32 * V_33 , struct V_1 * V_2 )
{
if ( V_33 -> V_155 -> V_34 )
return V_33 -> V_155 -> V_34 ( V_33 , V_187 , V_2 ) ;
return 0 ;
}
static void F_154 ( struct V_188 * V_173 , struct V_1 * V_2 ,
T_2 V_189 , char * V_190 )
{
struct V_79 * V_79 = NULL ;
unsigned int V_20 ;
if ( V_2 -> V_74 )
V_20 = F_73 ( V_2 -> V_74 ) ;
else
V_20 = V_2 -> V_20 ;
if ( V_2 -> V_21 != NULL )
V_79 = F_25 ( V_2 -> V_21 ) ;
F_155 ( V_173 , L_3 , V_189 , V_190 ) ;
if ( F_56 ( V_2 ) ) {
if ( V_2 -> V_3 & V_89 )
F_155 ( V_173 , L_4 ) ;
else if ( F_57 ( V_2 ) )
F_155 ( V_173 , L_5 ) ;
else
F_155 ( V_173 , L_6 ) ;
F_155 ( V_173 , L_7 ,
( V_79 == NULL ) ? L_8 :
F_142 ( V_79 ) ? L_9 : L_10 ) ;
} else if ( F_71 ( V_2 ) ) {
if ( V_2 -> V_8 & V_25 ) {
F_155 ( V_173 , L_11 ) ;
} else {
F_155 ( V_173 , L_12 ) ;
}
} else if ( F_79 ( V_2 ) ) {
F_155 ( V_173 , L_13 ) ;
if ( F_1 ( V_2 ) )
F_155 ( V_173 , L_14 ) ;
else if ( V_2 -> V_21 )
F_155 ( V_173 , L_15 ) ;
else
F_155 ( V_173 , L_16 ) ;
} else {
F_155 ( V_173 , L_17 ) ;
}
if ( V_2 -> V_8 & V_25 ) {
F_155 ( V_173 , L_18 ,
( V_2 -> V_8 & V_191 )
? ( V_2 -> V_8 & V_192 ) ? L_19 : L_20
: ( V_2 -> V_8 & V_192 ) ? L_21 : L_22 ) ;
} else {
F_155 ( V_173 , L_18 ,
( F_1 ( V_2 ) )
? ( V_2 -> V_8 == V_6 ) ? L_23 : L_20
: ( V_2 -> V_8 == V_29 ) ? L_21 : L_20 ) ;
}
if ( V_79 ) {
#ifdef F_156
F_155 ( V_173 , L_24 , V_20 ,
V_79 -> V_137 -> V_193 , V_79 -> V_185 ) ;
#else
F_155 ( V_173 , L_25 , V_20 ,
F_150 ( V_79 -> V_137 -> V_184 ) ,
F_151 ( V_79 -> V_137 -> V_184 ) , V_79 -> V_185 ) ;
#endif
} else {
F_155 ( V_173 , L_26 , V_20 ) ;
}
if ( F_56 ( V_2 ) ) {
if ( V_2 -> V_23 == V_39 )
F_155 ( V_173 , L_27 , V_2 -> V_22 ) ;
else
F_155 ( V_173 , L_28 , V_2 -> V_22 , V_2 -> V_23 ) ;
} else {
F_155 ( V_173 , L_29 ) ;
}
}
static int F_157 ( struct V_188 * V_173 , void * V_194 )
{
struct V_195 * V_196 = V_173 -> V_197 ;
struct V_1 * V_2 , * V_198 ;
V_2 = F_158 ( V_194 , struct V_1 , V_9 ) ;
F_154 ( V_173 , V_2 , V_196 -> V_199 , L_30 ) ;
F_159 (bfl, &fl->fl_block, fl_block)
F_154 ( V_173 , V_198 , V_196 -> V_199 , L_31 ) ;
return 0 ;
}
static void * F_160 ( struct V_188 * V_173 , T_2 * V_73 )
__acquires( &blocked_lock_lock
static void * F_161 ( struct V_188 * V_173 , void * V_194 , T_2 * V_73 )
{
struct V_195 * V_196 = V_173 -> V_197 ;
++ V_196 -> V_199 ;
return F_162 ( V_194 , & V_65 , & V_196 -> V_200 , V_73 ) ;
}
static void F_163 ( struct V_188 * V_173 , void * V_194 )
__releases( &blocked_lock_lock
static int F_164 ( struct V_79 * V_79 , struct V_32 * V_33 )
{
return F_165 ( V_33 , & V_201 ,
sizeof( struct V_195 ) ) ;
}
static int T_5 F_166 ( void )
{
F_167 ( L_32 , 0 , NULL , & V_202 ) ;
return 0 ;
}
int F_168 ( struct V_79 * V_79 , T_2 V_203 , unsigned long V_204 )
{
struct V_1 * V_2 ;
int V_205 = 1 ;
F_52 ( & V_79 -> V_80 ) ;
for ( V_2 = V_79 -> V_81 ; V_2 != NULL ; V_2 = V_2 -> V_69 ) {
if ( F_56 ( V_2 ) ) {
if ( V_2 -> V_8 == V_7 )
continue;
if ( ( V_2 -> V_23 < V_203 ) || ( V_2 -> V_22 > ( V_203 + V_204 ) ) )
continue;
} else if ( F_71 ( V_2 ) ) {
if ( ! ( V_2 -> V_8 & V_25 ) )
continue;
if ( V_2 -> V_8 & V_191 )
continue;
} else
continue;
V_205 = 0 ;
break;
}
F_53 ( & V_79 -> V_80 ) ;
return V_205 ;
}
int F_169 ( struct V_79 * V_79 , T_2 V_203 , unsigned long V_204 )
{
struct V_1 * V_2 ;
int V_205 = 1 ;
F_52 ( & V_79 -> V_80 ) ;
for ( V_2 = V_79 -> V_81 ; V_2 != NULL ; V_2 = V_2 -> V_69 ) {
if ( F_56 ( V_2 ) ) {
if ( ( V_2 -> V_23 < V_203 ) || ( V_2 -> V_22 > ( V_203 + V_204 ) ) )
continue;
} else if ( F_71 ( V_2 ) ) {
if ( ! ( V_2 -> V_8 & V_25 ) )
continue;
if ( V_2 -> V_8 & V_192 )
continue;
} else
continue;
V_205 = 0 ;
break;
}
F_53 ( & V_79 -> V_80 ) ;
return V_205 ;
}
static int T_5 F_170 ( void )
{
int V_83 ;
V_12 = F_171 ( L_33 ,
sizeof( struct V_1 ) , 0 , V_206 , NULL ) ;
F_172 ( & V_63 , L_34 ) ;
F_173 (i)
F_174 ( F_175 ( & V_65 , V_83 ) ) ;
return 0 ;
}
