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
T_1 V_42 , V_43 ;
switch ( V_41 -> V_44 ) {
case V_45 :
V_42 = 0 ;
break;
case V_46 :
V_42 = V_33 -> V_47 ;
break;
case V_48 :
V_42 = F_24 ( F_25 ( V_33 ) ) ;
break;
default:
return - V_31 ;
}
V_42 += V_41 -> V_49 ;
if ( V_42 < 0 )
return - V_31 ;
V_2 -> V_23 = V_39 ;
if ( V_41 -> V_50 > 0 ) {
V_43 = V_42 + V_41 -> V_50 - 1 ;
V_2 -> V_23 = V_43 ;
} else if ( V_41 -> V_50 < 0 ) {
V_43 = V_42 - 1 ;
V_2 -> V_23 = V_43 ;
V_42 += V_41 -> V_50 ;
if ( V_42 < 0 )
return - V_31 ;
}
V_2 -> V_22 = V_42 ;
if ( V_2 -> V_23 < V_2 -> V_22 )
return - V_51 ;
V_2 -> V_19 = V_36 -> V_52 ;
V_2 -> V_20 = V_36 -> V_37 ;
V_2 -> V_21 = V_33 ;
V_2 -> V_3 = V_53 ;
V_2 -> V_14 = NULL ;
V_2 -> V_16 = NULL ;
return F_22 ( V_2 , V_41 -> V_54 ) ;
}
static int F_26 ( struct V_32 * V_33 , struct V_1 * V_2 ,
struct V_55 * V_41 )
{
T_2 V_42 ;
switch ( V_41 -> V_44 ) {
case V_45 :
V_42 = 0 ;
break;
case V_46 :
V_42 = V_33 -> V_47 ;
break;
case V_48 :
V_42 = F_24 ( F_25 ( V_33 ) ) ;
break;
default:
return - V_31 ;
}
V_42 += V_41 -> V_49 ;
if ( V_42 < 0 )
return - V_31 ;
V_2 -> V_23 = V_39 ;
if ( V_41 -> V_50 > 0 ) {
V_2 -> V_23 = V_42 + V_41 -> V_50 - 1 ;
} else if ( V_41 -> V_50 < 0 ) {
V_2 -> V_23 = V_42 - 1 ;
V_42 += V_41 -> V_50 ;
if ( V_42 < 0 )
return - V_31 ;
}
V_2 -> V_22 = V_42 ;
if ( V_2 -> V_23 < V_2 -> V_22 )
return - V_51 ;
V_2 -> V_19 = V_36 -> V_52 ;
V_2 -> V_20 = V_36 -> V_37 ;
V_2 -> V_21 = V_33 ;
V_2 -> V_3 = V_53 ;
V_2 -> V_14 = NULL ;
V_2 -> V_16 = NULL ;
return F_22 ( V_2 , V_41 -> V_54 ) ;
}
static void F_27 ( struct V_1 * V_2 )
{
F_28 ( & V_2 -> V_56 , V_57 , V_58 ) ;
}
static int F_29 ( struct V_32 * V_33 , long type , struct V_1 * V_2 )
{
if ( F_22 ( V_2 , type ) != 0 )
return - V_31 ;
V_2 -> V_19 = V_36 -> V_52 ;
V_2 -> V_20 = V_36 -> V_37 ;
V_2 -> V_21 = V_33 ;
V_2 -> V_3 = V_59 ;
V_2 -> V_22 = 0 ;
V_2 -> V_23 = V_39 ;
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
static inline void
F_34 ( struct V_1 * V_2 )
{
F_35 ( & V_64 ) ;
V_2 -> V_65 = F_36 () ;
F_37 ( & V_2 -> V_9 , F_38 ( & V_66 ) ) ;
F_39 ( & V_64 ) ;
}
static inline void
F_40 ( struct V_1 * V_2 )
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
static inline void
F_45 ( struct V_1 * V_68 )
{
F_46 ( V_69 , & V_68 -> V_9 , F_44 ( V_68 ) ) ;
}
static inline void
F_47 ( struct V_1 * V_68 )
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
if ( F_56 ( V_72 ) )
F_45 ( V_68 ) ;
}
static void F_57 ( struct V_1 * V_72 ,
struct V_1 * V_68 )
{
F_52 ( & V_71 ) ;
F_54 ( V_72 , V_68 ) ;
F_53 ( & V_71 ) ;
}
static void F_58 ( struct V_1 * V_72 )
{
if ( F_13 ( & V_72 -> V_10 ) )
return;
F_52 ( & V_71 ) ;
while ( ! F_13 ( & V_72 -> V_10 ) ) {
struct V_1 * V_68 ;
V_68 = F_59 ( & V_72 -> V_10 ,
struct V_1 , V_10 ) ;
F_49 ( V_68 ) ;
if ( V_68 -> V_16 && V_68 -> V_16 -> V_73 )
V_68 -> V_16 -> V_73 ( V_68 ) ;
else
F_60 ( & V_68 -> V_11 ) ;
}
F_53 ( & V_71 ) ;
}
static void F_61 ( struct V_1 * * V_74 , struct V_1 * V_2 )
{
V_2 -> V_75 = F_62 ( F_63 ( V_36 ) ) ;
V_2 -> V_70 = * V_74 ;
* V_74 = V_2 ;
F_34 ( V_2 ) ;
}
static void F_64 ( struct V_1 * * V_76 )
{
struct V_1 * V_2 = * V_76 ;
F_40 ( V_2 ) ;
* V_76 = V_2 -> V_70 ;
V_2 -> V_70 = NULL ;
if ( V_2 -> V_75 ) {
F_65 ( V_2 -> V_75 ) ;
V_2 -> V_75 = NULL ;
}
F_58 ( V_2 ) ;
F_10 ( V_2 ) ;
}
static int F_66 ( struct V_1 * V_77 , struct V_1 * V_78 )
{
if ( V_78 -> V_8 == V_29 )
return 1 ;
if ( V_77 -> V_8 == V_29 )
return 1 ;
return 0 ;
}
static int F_67 ( struct V_1 * V_77 , struct V_1 * V_78 )
{
if ( ! F_56 ( V_78 ) || F_33 ( V_77 , V_78 ) )
return ( 0 ) ;
if ( ! F_32 ( V_77 , V_78 ) )
return 0 ;
return ( F_66 ( V_77 , V_78 ) ) ;
}
static int F_68 ( struct V_1 * V_77 , struct V_1 * V_78 )
{
if ( ! F_69 ( V_78 ) || ( V_77 -> V_21 == V_78 -> V_21 ) )
return ( 0 ) ;
if ( ( V_77 -> V_8 & V_25 ) || ( V_78 -> V_8 & V_25 ) )
return 0 ;
return ( F_66 ( V_77 , V_78 ) ) ;
}
void
F_70 ( struct V_32 * V_33 , struct V_1 * V_2 )
{
struct V_1 * V_79 ;
struct V_80 * V_80 = F_25 ( V_33 ) ;
F_52 ( & V_80 -> V_81 ) ;
for ( V_79 = F_25 ( V_33 ) -> V_82 ; V_79 ; V_79 = V_79 -> V_70 ) {
if ( ! F_56 ( V_79 ) )
continue;
if ( F_67 ( V_2 , V_79 ) )
break;
}
if ( V_79 ) {
F_18 ( V_2 , V_79 ) ;
if ( V_79 -> V_75 )
V_2 -> V_20 = F_71 ( V_79 -> V_75 ) ;
} else
V_2 -> V_8 = V_6 ;
F_53 ( & V_80 -> V_81 ) ;
return;
}
static struct V_1 * F_72 ( struct V_1 * V_83 )
{
struct V_1 * V_2 ;
F_73 (blocked_hash, fl, fl_link, posix_owner_key(block_fl)) {
if ( F_33 ( V_2 , V_83 ) )
return V_2 -> V_70 ;
}
return NULL ;
}
static int F_74 ( struct V_1 * V_77 ,
struct V_1 * V_83 )
{
int V_84 = 0 ;
while ( ( V_83 = F_72 ( V_83 ) ) ) {
if ( V_84 ++ > V_85 )
return 0 ;
if ( F_33 ( V_77 , V_83 ) )
return 1 ;
}
return 0 ;
}
static int F_75 ( struct V_32 * V_33 , struct V_1 * V_86 )
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
F_76 (inode, before) {
struct V_1 * V_2 = * V_88 ;
if ( F_56 ( V_2 ) )
break;
if ( F_77 ( V_2 ) )
continue;
if ( V_33 != V_2 -> V_21 )
continue;
if ( V_86 -> V_8 == V_2 -> V_8 )
goto V_92;
V_89 = 1 ;
F_64 ( V_88 ) ;
break;
}
if ( V_86 -> V_8 == V_6 ) {
if ( ( V_86 -> V_3 & V_93 ) && ! V_89 )
error = - V_94 ;
goto V_92;
}
if ( V_89 ) {
F_53 ( & V_80 -> V_81 ) ;
F_78 () ;
F_52 ( & V_80 -> V_81 ) ;
}
V_91:
F_76 (inode, before) {
struct V_1 * V_2 = * V_88 ;
if ( F_56 ( V_2 ) )
break;
if ( F_77 ( V_2 ) )
continue;
if ( ! F_68 ( V_86 , V_2 ) )
continue;
error = - V_95 ;
if ( ! ( V_86 -> V_3 & V_96 ) )
goto V_92;
error = V_97 ;
F_57 ( V_2 , V_86 ) ;
goto V_92;
}
if ( V_86 -> V_3 & V_90 )
goto V_92;
F_19 ( V_87 , V_86 ) ;
F_61 ( V_88 , V_87 ) ;
V_87 = NULL ;
error = 0 ;
V_92:
F_53 ( & V_80 -> V_81 ) ;
if ( V_87 )
F_10 ( V_87 ) ;
return error ;
}
static int F_79 ( struct V_80 * V_80 , struct V_1 * V_86 , struct V_1 * V_98 )
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
V_86 -> V_22 != 0 || V_86 -> V_23 != V_39 ) ) {
V_87 = F_7 () ;
V_99 = F_7 () ;
}
F_52 ( & V_80 -> V_81 ) ;
if ( V_86 -> V_8 != V_6 ) {
F_76 (inode, before) {
V_2 = * V_88 ;
if ( ! F_56 ( V_2 ) )
continue;
if ( ! F_67 ( V_86 , V_2 ) )
continue;
if ( V_98 )
F_18 ( V_98 , V_2 ) ;
error = - V_95 ;
if ( ! ( V_86 -> V_3 & V_96 ) )
goto V_92;
error = - V_103 ;
F_52 ( & V_71 ) ;
if ( F_80 ( ! F_74 ( V_86 , V_2 ) ) ) {
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
F_64 ( V_88 ) ;
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
F_64 ( V_88 ) ;
continue;
}
F_58 ( V_2 ) ;
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
F_61 ( V_88 , V_87 ) ;
V_87 = NULL ;
}
if ( V_101 ) {
if ( V_100 == V_101 ) {
V_100 = V_99 ;
V_99 = NULL ;
F_19 ( V_100 , V_101 ) ;
F_61 ( V_88 , V_100 ) ;
}
V_101 -> V_22 = V_86 -> V_23 + 1 ;
F_58 ( V_101 ) ;
}
if ( V_100 ) {
V_100 -> V_23 = V_86 -> V_22 - 1 ;
F_58 ( V_100 ) ;
}
V_92:
F_53 ( & V_80 -> V_81 ) ;
if ( V_87 )
F_10 ( V_87 ) ;
if ( V_99 )
F_10 ( V_99 ) ;
return error ;
}
int F_81 ( struct V_32 * V_33 , struct V_1 * V_2 ,
struct V_1 * V_98 )
{
return F_79 ( F_25 ( V_33 ) , V_2 , V_98 ) ;
}
int F_82 ( struct V_32 * V_33 , struct V_1 * V_2 )
{
int error ;
F_83 () ;
for (; ; ) {
error = F_81 ( V_33 , V_2 , NULL ) ;
if ( error != V_97 )
break;
error = F_84 ( V_2 -> V_11 , ! V_2 -> V_70 ) ;
if ( ! error )
continue;
F_51 ( V_2 ) ;
break;
}
return error ;
}
int F_85 ( struct V_80 * V_80 )
{
T_3 V_106 = V_36 -> V_52 ;
struct V_1 * V_2 ;
F_52 ( & V_80 -> V_81 ) ;
for ( V_2 = V_80 -> V_82 ; V_2 != NULL ; V_2 = V_2 -> V_70 ) {
if ( ! F_56 ( V_2 ) )
continue;
if ( V_2 -> V_19 != V_106 )
break;
}
F_53 ( & V_80 -> V_81 ) ;
return V_2 ? - V_95 : 0 ;
}
int F_86 ( int V_107 , struct V_80 * V_80 ,
struct V_32 * V_33 , T_2 V_108 ,
T_4 V_109 )
{
struct V_1 V_2 ;
int error ;
F_16 ( & V_2 ) ;
V_2 . V_19 = V_36 -> V_52 ;
V_2 . V_20 = V_36 -> V_37 ;
V_2 . V_21 = V_33 ;
V_2 . V_3 = V_53 | V_90 ;
if ( V_33 && ! ( V_33 -> V_110 & V_111 ) )
V_2 . V_3 |= V_96 ;
V_2 . V_8 = ( V_107 == V_112 ) ? V_29 : V_7 ;
V_2 . V_22 = V_108 ;
V_2 . V_23 = V_108 + V_109 - 1 ;
for (; ; ) {
error = F_79 ( V_80 , & V_2 , NULL ) ;
if ( error != V_97 )
break;
error = F_84 ( V_2 . V_11 , ! V_2 . V_70 ) ;
if ( ! error ) {
if ( F_87 ( V_80 ) )
continue;
}
F_51 ( & V_2 ) ;
break;
}
return error ;
}
static void F_88 ( struct V_1 * V_2 , int V_113 )
{
switch ( V_113 ) {
case V_6 :
V_2 -> V_3 &= ~ V_4 ;
case V_7 :
V_2 -> V_3 &= ~ V_5 ;
}
}
int F_89 ( struct V_1 * * V_88 , int V_113 )
{
struct V_1 * V_2 = * V_88 ;
int error = F_22 ( V_2 , V_113 ) ;
if ( error )
return error ;
F_88 ( V_2 , V_113 ) ;
F_58 ( V_2 ) ;
if ( V_113 == V_6 ) {
struct V_32 * V_33 = V_2 -> V_21 ;
F_90 ( V_33 ) ;
V_33 -> V_114 . V_115 = 0 ;
F_91 ( 0 , V_2 -> V_21 , 0 , & V_2 -> V_56 ) ;
if ( V_2 -> V_56 != NULL ) {
F_92 ( V_116 L_1 , V_2 -> V_56 ) ;
V_2 -> V_56 = NULL ;
}
F_64 ( V_88 ) ;
}
return 0 ;
}
static bool F_93 ( unsigned long V_117 )
{
if ( ! V_117 )
return false ;
return F_94 ( V_118 , V_117 ) ;
}
static void F_95 ( struct V_80 * V_80 )
{
struct V_1 * * V_88 ;
struct V_1 * V_2 ;
V_88 = & V_80 -> V_82 ;
while ( ( V_2 = * V_88 ) && F_77 ( V_2 ) && F_1 ( V_2 ) ) {
if ( F_93 ( V_2 -> V_119 ) )
F_89 ( V_88 , V_7 ) ;
if ( F_93 ( V_2 -> V_120 ) )
F_89 ( V_88 , V_6 ) ;
if ( V_2 == * V_88 )
V_88 = & V_2 -> V_70 ;
}
}
static bool F_96 ( struct V_1 * V_121 , struct V_1 * V_122 )
{
if ( ( V_122 -> V_3 & V_123 ) && ( V_121 -> V_3 & V_59 ) )
return false ;
return F_66 ( V_122 , V_121 ) ;
}
int F_97 ( struct V_80 * V_80 , unsigned int V_124 , unsigned int type )
{
int error = 0 ;
struct V_1 * V_87 , * V_40 ;
struct V_1 * V_2 ;
unsigned long V_125 ;
int V_126 = 0 ;
bool V_127 = false ;
int V_128 = ( V_124 & V_129 ) != V_130 ;
V_87 = F_30 ( NULL , V_128 ? V_29 : V_7 ) ;
if ( F_98 ( V_87 ) )
return F_99 ( V_87 ) ;
V_87 -> V_3 = type ;
F_52 ( & V_80 -> V_81 ) ;
F_95 ( V_80 ) ;
V_40 = V_80 -> V_82 ;
if ( ( V_40 == NULL ) || ! F_77 ( V_40 ) )
goto V_92;
for ( V_2 = V_40 ; V_2 && F_77 ( V_2 ) ; V_2 = V_2 -> V_70 ) {
if ( F_96 ( V_2 , V_87 ) ) {
V_127 = true ;
if ( V_2 -> V_19 == V_36 -> V_52 )
V_126 = 1 ;
}
}
if ( ! V_127 )
goto V_92;
V_125 = 0 ;
if ( V_131 > 0 ) {
V_125 = V_118 + V_131 * V_132 ;
if ( V_125 == 0 )
V_125 ++ ;
}
for ( V_2 = V_40 ; V_2 && F_77 ( V_2 ) ; V_2 = V_2 -> V_70 ) {
if ( ! F_96 ( V_2 , V_87 ) )
continue;
if ( V_128 ) {
if ( V_2 -> V_3 & V_4 )
continue;
V_2 -> V_3 |= V_4 ;
V_2 -> V_120 = V_125 ;
} else {
if ( F_1 ( V_40 ) )
continue;
V_2 -> V_3 |= V_5 ;
V_2 -> V_119 = V_125 ;
}
V_2 -> V_16 -> V_133 ( V_2 ) ;
}
if ( V_126 || ( V_124 & V_111 ) ) {
error = - V_134 ;
goto V_92;
}
V_135:
V_125 = V_40 -> V_120 ;
if ( V_125 != 0 ) {
V_125 -= V_118 ;
if ( V_125 == 0 )
V_125 ++ ;
}
F_57 ( V_40 , V_87 ) ;
F_53 ( & V_80 -> V_81 ) ;
error = F_100 ( V_87 -> V_11 ,
! V_87 -> V_70 , V_125 ) ;
F_52 ( & V_80 -> V_81 ) ;
F_51 ( V_87 ) ;
if ( error >= 0 ) {
if ( error == 0 )
F_95 ( V_80 ) ;
for ( V_40 = V_80 -> V_82 ; V_40 && F_77 ( V_40 ) ;
V_40 = V_40 -> V_70 ) {
if ( F_96 ( V_87 , V_40 ) )
goto V_135;
}
error = 0 ;
}
V_92:
F_53 ( & V_80 -> V_81 ) ;
F_10 ( V_87 ) ;
return error ;
}
void F_101 ( struct V_80 * V_80 , struct V_136 * time )
{
struct V_1 * V_40 = V_80 -> V_82 ;
if ( V_40 && F_77 ( V_40 ) && ( V_40 -> V_8 == V_29 ) )
* time = F_102 ( V_80 -> V_137 ) ;
else
* time = V_80 -> V_138 ;
}
int F_103 ( struct V_32 * V_33 )
{
struct V_1 * V_2 ;
struct V_80 * V_80 = F_25 ( V_33 ) ;
int type = V_6 ;
F_52 ( & V_80 -> V_81 ) ;
F_95 ( F_25 ( V_33 ) ) ;
for ( V_2 = F_25 ( V_33 ) -> V_82 ; V_2 && F_77 ( V_2 ) ;
V_2 = V_2 -> V_70 ) {
if ( V_2 -> V_21 == V_33 ) {
type = F_2 ( V_2 ) ;
break;
}
}
F_53 ( & V_80 -> V_81 ) ;
return type ;
}
static int F_104 ( struct V_32 * V_33 , long V_113 , struct V_1 * * V_139 )
{
struct V_1 * V_2 , * * V_88 , * * V_140 = NULL , * V_121 ;
struct V_141 * V_141 = V_33 -> V_142 . V_141 ;
struct V_80 * V_80 = V_141 -> V_143 ;
bool V_144 = ( * V_139 ) -> V_3 & V_123 ;
int error ;
V_121 = * V_139 ;
if ( V_144 && ! F_105 ( & V_80 -> V_145 ) )
return - V_95 ;
if ( V_144 && V_113 == V_29 ) {
F_106 ( & V_80 -> V_145 ) ;
F_107 ( 1 ) ;
return - V_31 ;
}
error = - V_95 ;
if ( ( V_113 == V_7 ) && ( F_108 ( & V_80 -> V_146 ) > 0 ) )
goto V_92;
if ( ( V_113 == V_29 )
&& ( ( F_109 ( V_141 ) > 1 )
|| ( F_108 ( & V_80 -> V_147 ) > 1 ) ) )
goto V_92;
error = - V_95 ;
for ( V_88 = & V_80 -> V_82 ;
( ( V_2 = * V_88 ) != NULL ) && F_77 ( V_2 ) ;
V_88 = & V_2 -> V_70 ) {
if ( V_2 -> V_21 == V_33 ) {
V_140 = V_88 ;
continue;
}
if ( V_113 == V_29 )
goto V_92;
if ( V_2 -> V_3 & V_4 )
goto V_92;
}
if ( V_140 != NULL ) {
error = V_121 -> V_16 -> V_148 ( V_140 , V_113 ) ;
if ( ! error )
* V_139 = * V_140 ;
goto V_92;
}
error = - V_31 ;
if ( ! V_149 )
goto V_92;
F_61 ( V_88 , V_121 ) ;
error = 0 ;
V_92:
if ( V_144 )
F_106 ( & V_80 -> V_145 ) ;
return error ;
}
static int F_110 ( struct V_32 * V_33 , struct V_1 * * V_139 )
{
struct V_1 * V_2 , * * V_88 ;
struct V_141 * V_141 = V_33 -> V_142 . V_141 ;
struct V_80 * V_80 = V_141 -> V_143 ;
for ( V_88 = & V_80 -> V_82 ;
( ( V_2 = * V_88 ) != NULL ) && F_77 ( V_2 ) ;
V_88 = & V_2 -> V_70 ) {
if ( V_2 -> V_21 != V_33 )
continue;
return ( * V_139 ) -> V_16 -> V_148 ( V_88 , V_6 ) ;
}
return - V_95 ;
}
int F_111 ( struct V_32 * V_33 , long V_113 , struct V_1 * * V_139 )
{
struct V_141 * V_141 = V_33 -> V_142 . V_141 ;
struct V_80 * V_80 = V_141 -> V_143 ;
int error ;
if ( ( ! F_112 ( F_113 () , V_80 -> V_150 ) ) && ! F_114 ( V_151 ) )
return - V_152 ;
if ( ! F_115 ( V_80 -> V_153 ) )
return - V_31 ;
error = F_116 ( V_33 , V_113 ) ;
if ( error )
return error ;
F_95 ( V_80 ) ;
F_11 ( ! ( * V_139 ) -> V_16 -> V_133 ) ;
switch ( V_113 ) {
case V_6 :
return F_110 ( V_33 , V_139 ) ;
case V_7 :
case V_29 :
return F_104 ( V_33 , V_113 , V_139 ) ;
default:
return - V_31 ;
}
}
static int F_117 ( struct V_32 * V_33 , long V_113 , struct V_1 * * V_121 )
{
if ( V_33 -> V_154 -> V_155 )
return V_33 -> V_154 -> V_155 ( V_33 , V_113 , V_121 ) ;
else
return F_111 ( V_33 , V_113 , V_121 ) ;
}
int F_118 ( struct V_32 * V_33 , long V_113 , struct V_1 * * V_121 )
{
struct V_80 * V_80 = F_25 ( V_33 ) ;
int error ;
F_52 ( & V_80 -> V_81 ) ;
error = F_117 ( V_33 , V_113 , V_121 ) ;
F_53 ( & V_80 -> V_81 ) ;
return error ;
}
static int F_119 ( struct V_32 * V_33 )
{
struct V_1 V_2 , * V_139 = & V_2 ;
F_29 ( V_33 , V_6 , V_139 ) ;
return F_118 ( V_33 , V_6 , & V_139 ) ;
}
static int F_120 ( unsigned int V_156 , struct V_32 * V_33 , long V_113 )
{
struct V_1 * V_2 , * V_157 ;
struct V_80 * V_80 = F_25 ( V_33 ) ;
struct V_158 * V_17 ;
int error ;
V_2 = F_30 ( V_33 , V_113 ) ;
if ( F_98 ( V_2 ) )
return F_99 ( V_2 ) ;
V_17 = F_121 () ;
if ( ! V_17 ) {
F_10 ( V_2 ) ;
return - V_35 ;
}
V_157 = V_2 ;
F_52 ( & V_80 -> V_81 ) ;
error = F_117 ( V_33 , V_113 , & V_157 ) ;
if ( error ) {
F_53 ( & V_80 -> V_81 ) ;
F_10 ( V_2 ) ;
goto V_159;
}
if ( V_157 != V_2 )
F_10 ( V_2 ) ;
if ( ! F_122 ( V_156 , V_33 , & V_157 -> V_56 , V_17 ) )
V_17 = NULL ;
error = F_123 ( V_33 , F_124 ( V_36 ) , V_160 , 0 ) ;
F_53 ( & V_80 -> V_81 ) ;
V_159:
if ( V_17 )
F_125 ( V_17 ) ;
return error ;
}
int F_126 ( unsigned int V_156 , struct V_32 * V_33 , long V_113 )
{
if ( V_113 == V_6 )
return F_119 ( V_33 ) ;
return F_120 ( V_156 , V_33 , V_113 ) ;
}
int F_127 ( struct V_32 * V_33 , struct V_1 * V_2 )
{
int error ;
F_83 () ;
for (; ; ) {
error = F_75 ( V_33 , V_2 ) ;
if ( error != V_97 )
break;
error = F_84 ( V_2 -> V_11 , ! V_2 -> V_70 ) ;
if ( ! error )
continue;
F_51 ( V_2 ) ;
break;
}
return error ;
}
int F_128 ( struct V_32 * V_33 , struct V_1 * V_2 )
{
if ( V_33 -> V_154 -> V_34 )
return V_33 -> V_154 -> V_34 ( V_33 , V_161 , V_2 ) ;
F_70 ( V_33 , V_2 ) ;
return 0 ;
}
static int F_129 ( struct V_40 * V_40 , struct V_1 * V_2 )
{
V_40 -> V_162 = V_2 -> V_20 ;
#if V_163 == 32
if ( V_2 -> V_22 > V_164 )
return - V_51 ;
if ( V_2 -> V_23 != V_39 && V_2 -> V_23 > V_164 )
return - V_51 ;
#endif
V_40 -> V_49 = V_2 -> V_22 ;
V_40 -> V_50 = V_2 -> V_23 == V_39 ? 0 :
V_2 -> V_23 - V_2 -> V_22 + 1 ;
V_40 -> V_44 = 0 ;
V_40 -> V_54 = V_2 -> V_8 ;
return 0 ;
}
static void F_130 ( struct V_55 * V_40 , struct V_1 * V_2 )
{
V_40 -> V_162 = V_2 -> V_20 ;
V_40 -> V_49 = V_2 -> V_22 ;
V_40 -> V_50 = V_2 -> V_23 == V_39 ? 0 :
V_2 -> V_23 - V_2 -> V_22 + 1 ;
V_40 -> V_44 = 0 ;
V_40 -> V_54 = V_2 -> V_8 ;
}
int F_131 ( struct V_32 * V_33 , struct V_40 T_5 * V_41 )
{
struct V_1 V_1 ;
struct V_40 V_40 ;
int error ;
error = - V_165 ;
if ( F_132 ( & V_40 , V_41 , sizeof( V_40 ) ) )
goto V_92;
error = - V_31 ;
if ( ( V_40 . V_54 != V_7 ) && ( V_40 . V_54 != V_29 ) )
goto V_92;
error = F_23 ( V_33 , & V_1 , & V_40 ) ;
if ( error )
goto V_92;
error = F_128 ( V_33 , & V_1 ) ;
if ( error )
goto V_92;
V_40 . V_54 = V_1 . V_8 ;
if ( V_1 . V_8 != V_6 ) {
error = F_129 ( & V_40 , & V_1 ) ;
if ( error )
goto V_92;
}
error = - V_165 ;
if ( ! F_133 ( V_41 , & V_40 , sizeof( V_40 ) ) )
error = 0 ;
V_92:
return error ;
}
int F_134 ( struct V_32 * V_33 , unsigned int V_24 , struct V_1 * V_2 , struct V_1 * V_166 )
{
if ( V_33 -> V_154 -> V_34 )
return V_33 -> V_154 -> V_34 ( V_33 , V_24 , V_2 ) ;
else
return F_81 ( V_33 , V_2 , V_166 ) ;
}
static int F_135 ( struct V_32 * V_33 , unsigned int V_24 ,
struct V_1 * V_2 )
{
int error ;
error = F_116 ( V_33 , V_2 -> V_8 ) ;
if ( error )
return error ;
for (; ; ) {
error = F_134 ( V_33 , V_24 , V_2 , NULL ) ;
if ( error != V_97 )
break;
error = F_84 ( V_2 -> V_11 , ! V_2 -> V_70 ) ;
if ( ! error )
continue;
F_51 ( V_2 ) ;
break;
}
return error ;
}
int F_136 ( unsigned int V_156 , struct V_32 * V_33 , unsigned int V_24 ,
struct V_40 T_5 * V_41 )
{
struct V_1 * V_1 = F_7 () ;
struct V_40 V_40 ;
struct V_80 * V_80 ;
struct V_32 * V_167 ;
int error ;
if ( V_1 == NULL )
return - V_105 ;
error = - V_165 ;
if ( F_132 ( & V_40 , V_41 , sizeof( V_40 ) ) )
goto V_92;
V_80 = F_25 ( V_33 ) ;
if ( F_137 ( V_80 ) && F_138 ( V_33 -> V_168 ) ) {
error = - V_95 ;
goto V_92;
}
V_169:
error = F_23 ( V_33 , V_1 , & V_40 ) ;
if ( error )
goto V_92;
if ( V_24 == V_170 ) {
V_1 -> V_3 |= V_96 ;
}
error = - V_171 ;
switch ( V_40 . V_54 ) {
case V_7 :
if ( ! ( V_33 -> V_172 & V_173 ) )
goto V_92;
break;
case V_29 :
if ( ! ( V_33 -> V_172 & V_174 ) )
goto V_92;
break;
case V_6 :
break;
default:
error = - V_31 ;
goto V_92;
}
error = F_135 ( V_33 , V_24 , V_1 ) ;
F_52 ( & V_36 -> V_52 -> V_1 ) ;
V_167 = F_139 ( V_156 ) ;
F_53 ( & V_36 -> V_52 -> V_1 ) ;
if ( ! error && V_167 != V_33 && V_40 . V_54 != V_6 ) {
V_40 . V_54 = V_6 ;
goto V_169;
}
V_92:
F_10 ( V_1 ) ;
return error ;
}
int F_140 ( struct V_32 * V_33 , struct V_55 T_5 * V_41 )
{
struct V_1 V_1 ;
struct V_55 V_40 ;
int error ;
error = - V_165 ;
if ( F_132 ( & V_40 , V_41 , sizeof( V_40 ) ) )
goto V_92;
error = - V_31 ;
if ( ( V_40 . V_54 != V_7 ) && ( V_40 . V_54 != V_29 ) )
goto V_92;
error = F_26 ( V_33 , & V_1 , & V_40 ) ;
if ( error )
goto V_92;
error = F_128 ( V_33 , & V_1 ) ;
if ( error )
goto V_92;
V_40 . V_54 = V_1 . V_8 ;
if ( V_1 . V_8 != V_6 )
F_130 ( & V_40 , & V_1 ) ;
error = - V_165 ;
if ( ! F_133 ( V_41 , & V_40 , sizeof( V_40 ) ) )
error = 0 ;
V_92:
return error ;
}
int F_141 ( unsigned int V_156 , struct V_32 * V_33 , unsigned int V_24 ,
struct V_55 T_5 * V_41 )
{
struct V_1 * V_1 = F_7 () ;
struct V_55 V_40 ;
struct V_80 * V_80 ;
struct V_32 * V_167 ;
int error ;
if ( V_1 == NULL )
return - V_105 ;
error = - V_165 ;
if ( F_132 ( & V_40 , V_41 , sizeof( V_40 ) ) )
goto V_92;
V_80 = F_25 ( V_33 ) ;
if ( F_137 ( V_80 ) && F_138 ( V_33 -> V_168 ) ) {
error = - V_95 ;
goto V_92;
}
V_169:
error = F_26 ( V_33 , V_1 , & V_40 ) ;
if ( error )
goto V_92;
if ( V_24 == V_175 ) {
V_1 -> V_3 |= V_96 ;
}
error = - V_171 ;
switch ( V_40 . V_54 ) {
case V_7 :
if ( ! ( V_33 -> V_172 & V_173 ) )
goto V_92;
break;
case V_29 :
if ( ! ( V_33 -> V_172 & V_174 ) )
goto V_92;
break;
case V_6 :
break;
default:
error = - V_31 ;
goto V_92;
}
error = F_135 ( V_33 , V_24 , V_1 ) ;
F_52 ( & V_36 -> V_52 -> V_1 ) ;
V_167 = F_139 ( V_156 ) ;
F_53 ( & V_36 -> V_52 -> V_1 ) ;
if ( ! error && V_167 != V_33 && V_40 . V_54 != V_6 ) {
V_40 . V_54 = V_6 ;
goto V_169;
}
V_92:
F_10 ( V_1 ) ;
return error ;
}
void F_142 ( struct V_32 * V_33 , T_3 V_106 )
{
struct V_1 V_34 ;
if ( ! F_25 ( V_33 ) -> V_82 )
return;
V_34 . V_8 = V_6 ;
V_34 . V_3 = V_53 | V_176 ;
V_34 . V_22 = 0 ;
V_34 . V_23 = V_39 ;
V_34 . V_19 = V_106 ;
V_34 . V_20 = V_36 -> V_37 ;
V_34 . V_21 = V_33 ;
V_34 . V_14 = NULL ;
V_34 . V_16 = NULL ;
F_134 ( V_33 , V_177 , & V_34 , NULL ) ;
if ( V_34 . V_14 && V_34 . V_14 -> V_15 )
V_34 . V_14 -> V_15 ( & V_34 ) ;
}
void F_143 ( struct V_32 * V_33 )
{
struct V_80 * V_80 = F_25 ( V_33 ) ;
struct V_1 * V_2 ;
struct V_1 * * V_88 ;
if ( ! V_80 -> V_82 )
return;
if ( V_33 -> V_154 -> V_40 ) {
struct V_1 V_2 = {
. V_20 = V_36 -> V_37 ,
. V_21 = V_33 ,
. V_3 = V_38 ,
. V_8 = V_6 ,
. V_23 = V_39 ,
} ;
V_33 -> V_154 -> V_40 ( V_33 , V_170 , & V_2 ) ;
if ( V_2 . V_14 && V_2 . V_14 -> V_15 )
V_2 . V_14 -> V_15 ( & V_2 ) ;
}
F_52 ( & V_80 -> V_81 ) ;
V_88 = & V_80 -> V_82 ;
while ( ( V_2 = * V_88 ) != NULL ) {
if ( V_2 -> V_21 == V_33 ) {
if ( F_69 ( V_2 ) ) {
F_64 ( V_88 ) ;
continue;
}
if ( F_77 ( V_2 ) ) {
F_89 ( V_88 , V_6 ) ;
continue;
}
F_144 () ;
}
V_88 = & V_2 -> V_70 ;
}
F_53 ( & V_80 -> V_81 ) ;
}
int
F_145 ( struct V_1 * V_68 )
{
int V_178 = 0 ;
F_52 ( & V_71 ) ;
if ( V_68 -> V_70 )
F_49 ( V_68 ) ;
else
V_178 = - V_94 ;
F_53 ( & V_71 ) ;
return V_178 ;
}
int F_146 ( struct V_32 * V_33 , struct V_1 * V_2 )
{
if ( V_33 -> V_154 -> V_34 )
return V_33 -> V_154 -> V_34 ( V_33 , V_179 , V_2 ) ;
return 0 ;
}
static void F_147 ( struct V_180 * V_167 , struct V_1 * V_2 ,
T_2 V_181 , char * V_182 )
{
struct V_80 * V_80 = NULL ;
unsigned int V_20 ;
if ( V_2 -> V_75 )
V_20 = F_71 ( V_2 -> V_75 ) ;
else
V_20 = V_2 -> V_20 ;
if ( V_2 -> V_21 != NULL )
V_80 = F_25 ( V_2 -> V_21 ) ;
F_148 ( V_167 , L_2 , V_181 , V_182 ) ;
if ( F_56 ( V_2 ) ) {
F_148 ( V_167 , L_3 ,
( V_2 -> V_3 & V_90 ) ? L_4 : L_5 ,
( V_80 == NULL ) ? L_6 :
F_137 ( V_80 ) ? L_7 : L_8 ) ;
} else if ( F_69 ( V_2 ) ) {
if ( V_2 -> V_8 & V_25 ) {
F_148 ( V_167 , L_9 ) ;
} else {
F_148 ( V_167 , L_10 ) ;
}
} else if ( F_77 ( V_2 ) ) {
F_148 ( V_167 , L_11 ) ;
if ( F_1 ( V_2 ) )
F_148 ( V_167 , L_12 ) ;
else if ( V_2 -> V_21 )
F_148 ( V_167 , L_13 ) ;
else
F_148 ( V_167 , L_14 ) ;
} else {
F_148 ( V_167 , L_15 ) ;
}
if ( V_2 -> V_8 & V_25 ) {
F_148 ( V_167 , L_16 ,
( V_2 -> V_8 & V_183 )
? ( V_2 -> V_8 & V_184 ) ? L_17 : L_18
: ( V_2 -> V_8 & V_184 ) ? L_19 : L_20 ) ;
} else {
F_148 ( V_167 , L_16 ,
( F_1 ( V_2 ) )
? ( V_2 -> V_8 == V_6 ) ? L_21 : L_18
: ( V_2 -> V_8 == V_29 ) ? L_19 : L_18 ) ;
}
if ( V_80 ) {
#ifdef F_149
F_148 ( V_167 , L_22 , V_20 ,
V_80 -> V_137 -> V_185 , V_80 -> V_186 ) ;
#else
F_148 ( V_167 , L_23 , V_20 ,
F_150 ( V_80 -> V_137 -> V_187 ) ,
F_151 ( V_80 -> V_137 -> V_187 ) , V_80 -> V_186 ) ;
#endif
} else {
F_148 ( V_167 , L_24 , V_20 ) ;
}
if ( F_56 ( V_2 ) ) {
if ( V_2 -> V_23 == V_39 )
F_148 ( V_167 , L_25 , V_2 -> V_22 ) ;
else
F_148 ( V_167 , L_26 , V_2 -> V_22 , V_2 -> V_23 ) ;
} else {
F_148 ( V_167 , L_27 ) ;
}
}
static int F_152 ( struct V_180 * V_167 , void * V_188 )
{
struct V_189 * V_190 = V_167 -> V_191 ;
struct V_1 * V_2 , * V_192 ;
V_2 = F_153 ( V_188 , struct V_1 , V_9 ) ;
F_147 ( V_167 , V_2 , V_190 -> V_193 , L_28 ) ;
F_154 (bfl, &fl->fl_block, fl_block)
F_147 ( V_167 , V_192 , V_190 -> V_193 , L_29 ) ;
return 0 ;
}
static void * F_155 ( struct V_180 * V_167 , T_2 * V_74 )
{
struct V_189 * V_190 = V_167 -> V_191 ;
V_190 -> V_193 = * V_74 + 1 ;
F_156 ( & V_64 ) ;
F_52 ( & V_71 ) ;
return F_157 ( & V_66 , & V_190 -> V_194 , * V_74 ) ;
}
static void * F_158 ( struct V_180 * V_167 , void * V_188 , T_2 * V_74 )
{
struct V_189 * V_190 = V_167 -> V_191 ;
++ V_190 -> V_193 ;
return F_159 ( V_188 , & V_66 , & V_190 -> V_194 , V_74 ) ;
}
static void F_160 ( struct V_180 * V_167 , void * V_188 )
{
F_53 ( & V_71 ) ;
F_161 ( & V_64 ) ;
}
static int F_162 ( struct V_80 * V_80 , struct V_32 * V_33 )
{
return F_163 ( V_33 , & V_195 ,
sizeof( struct V_189 ) ) ;
}
static int T_6 F_164 ( void )
{
F_165 ( L_30 , 0 , NULL , & V_196 ) ;
return 0 ;
}
int F_166 ( struct V_80 * V_80 , T_2 V_42 , unsigned long V_197 )
{
struct V_1 * V_2 ;
int V_198 = 1 ;
F_52 ( & V_80 -> V_81 ) ;
for ( V_2 = V_80 -> V_82 ; V_2 != NULL ; V_2 = V_2 -> V_70 ) {
if ( F_56 ( V_2 ) ) {
if ( V_2 -> V_8 == V_7 )
continue;
if ( ( V_2 -> V_23 < V_42 ) || ( V_2 -> V_22 > ( V_42 + V_197 ) ) )
continue;
} else if ( F_69 ( V_2 ) ) {
if ( ! ( V_2 -> V_8 & V_25 ) )
continue;
if ( V_2 -> V_8 & V_183 )
continue;
} else
continue;
V_198 = 0 ;
break;
}
F_53 ( & V_80 -> V_81 ) ;
return V_198 ;
}
int F_167 ( struct V_80 * V_80 , T_2 V_42 , unsigned long V_197 )
{
struct V_1 * V_2 ;
int V_198 = 1 ;
F_52 ( & V_80 -> V_81 ) ;
for ( V_2 = V_80 -> V_82 ; V_2 != NULL ; V_2 = V_2 -> V_70 ) {
if ( F_56 ( V_2 ) ) {
if ( ( V_2 -> V_23 < V_42 ) || ( V_2 -> V_22 > ( V_42 + V_197 ) ) )
continue;
} else if ( F_69 ( V_2 ) ) {
if ( ! ( V_2 -> V_8 & V_25 ) )
continue;
if ( V_2 -> V_8 & V_184 )
continue;
} else
continue;
V_198 = 0 ;
break;
}
F_53 ( & V_80 -> V_81 ) ;
return V_198 ;
}
static int T_6 F_168 ( void )
{
int V_84 ;
V_12 = F_169 ( L_31 ,
sizeof( struct V_1 ) , 0 , V_199 , NULL ) ;
F_170 ( & V_64 , L_32 ) ;
F_171 (i)
F_172 ( F_173 ( & V_66 , V_84 ) ) ;
return 0 ;
}
