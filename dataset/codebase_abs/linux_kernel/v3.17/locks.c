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
static void
F_16 ( struct V_17 * V_18 )
{
struct V_1 * V_2 ;
while ( ! F_13 ( V_18 ) ) {
V_2 = F_17 ( V_18 , struct V_1 , V_10 ) ;
F_18 ( & V_2 -> V_10 ) ;
F_10 ( V_2 ) ;
}
}
void F_19 ( struct V_1 * V_2 )
{
memset ( V_2 , 0 , sizeof( struct V_1 ) ) ;
F_3 ( V_2 ) ;
}
static void F_20 ( struct V_1 * V_19 , struct V_1 * V_2 )
{
if ( V_2 -> V_14 ) {
if ( V_2 -> V_14 -> V_20 )
V_2 -> V_14 -> V_20 ( V_19 , V_2 ) ;
V_19 -> V_14 = V_2 -> V_14 ;
}
if ( V_2 -> V_16 )
V_19 -> V_16 = V_2 -> V_16 ;
}
void F_21 ( struct V_1 * V_19 , const struct V_1 * V_2 )
{
V_19 -> V_21 = V_2 -> V_21 ;
V_19 -> V_22 = V_2 -> V_22 ;
V_19 -> V_23 = NULL ;
V_19 -> V_3 = V_2 -> V_3 ;
V_19 -> V_8 = V_2 -> V_8 ;
V_19 -> V_24 = V_2 -> V_24 ;
V_19 -> V_25 = V_2 -> V_25 ;
V_19 -> V_14 = NULL ;
V_19 -> V_16 = NULL ;
}
void F_22 ( struct V_1 * V_19 , struct V_1 * V_2 )
{
F_23 ( V_19 -> V_14 ) ;
F_21 ( V_19 , V_2 ) ;
V_19 -> V_23 = V_2 -> V_23 ;
V_19 -> V_14 = V_2 -> V_14 ;
V_19 -> V_16 = V_2 -> V_16 ;
F_20 ( V_19 , V_2 ) ;
}
static inline int F_24 ( int V_26 ) {
if ( V_26 & V_27 )
return V_26 & ( V_27 | V_28 ) ;
switch ( V_26 ) {
case V_29 :
return V_7 ;
case V_30 :
return V_31 ;
case V_32 :
return V_6 ;
}
return - V_33 ;
}
static int F_25 ( struct V_34 * V_35 , struct V_1 * * V_36 ,
unsigned int V_26 )
{
struct V_1 * V_2 ;
int type = F_24 ( V_26 ) ;
if ( type < 0 )
return type ;
V_2 = F_7 () ;
if ( V_2 == NULL )
return - V_37 ;
V_2 -> V_23 = V_35 ;
V_2 -> V_21 = V_35 ;
V_2 -> V_22 = V_38 -> V_39 ;
V_2 -> V_3 = V_40 ;
V_2 -> V_8 = type ;
V_2 -> V_25 = V_41 ;
* V_36 = V_2 ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 , long type )
{
switch ( type ) {
case V_7 :
case V_31 :
case V_6 :
V_2 -> V_8 = type ;
break;
default:
return - V_33 ;
}
return 0 ;
}
static int F_27 ( struct V_34 * V_35 , struct V_1 * V_2 ,
struct V_42 * V_43 )
{
switch ( V_43 -> V_44 ) {
case V_45 :
V_2 -> V_24 = 0 ;
break;
case V_46 :
V_2 -> V_24 = V_35 -> V_47 ;
break;
case V_48 :
V_2 -> V_24 = F_28 ( F_29 ( V_35 ) ) ;
break;
default:
return - V_33 ;
}
if ( V_43 -> V_49 > V_41 - V_2 -> V_24 )
return - V_50 ;
V_2 -> V_24 += V_43 -> V_49 ;
if ( V_2 -> V_24 < 0 )
return - V_33 ;
if ( V_43 -> V_51 > 0 ) {
if ( V_43 -> V_51 - 1 > V_41 - V_2 -> V_24 )
return - V_50 ;
V_2 -> V_25 = V_2 -> V_24 + V_43 -> V_51 - 1 ;
} else if ( V_43 -> V_51 < 0 ) {
if ( V_2 -> V_24 + V_43 -> V_51 < 0 )
return - V_33 ;
V_2 -> V_25 = V_2 -> V_24 - 1 ;
V_2 -> V_24 += V_43 -> V_51 ;
} else
V_2 -> V_25 = V_41 ;
V_2 -> V_21 = V_38 -> V_52 ;
V_2 -> V_22 = V_38 -> V_39 ;
V_2 -> V_23 = V_35 ;
V_2 -> V_3 = V_53 ;
V_2 -> V_14 = NULL ;
V_2 -> V_16 = NULL ;
return F_26 ( V_2 , V_43 -> V_54 ) ;
}
static int F_30 ( struct V_34 * V_35 , struct V_1 * V_2 ,
struct V_55 * V_43 )
{
struct V_42 V_56 = {
. V_54 = V_43 -> V_54 ,
. V_44 = V_43 -> V_44 ,
. V_49 = V_43 -> V_49 ,
. V_51 = V_43 -> V_51 ,
} ;
return F_27 ( V_35 , V_2 , & V_56 ) ;
}
static void F_31 ( struct V_1 * V_2 )
{
F_32 ( & V_2 -> V_57 , V_58 , V_59 ) ;
}
static int F_33 ( struct V_34 * V_35 , long type , struct V_1 * V_2 )
{
if ( F_26 ( V_2 , type ) != 0 )
return - V_33 ;
V_2 -> V_21 = V_38 -> V_52 ;
V_2 -> V_22 = V_38 -> V_39 ;
V_2 -> V_23 = V_35 ;
V_2 -> V_3 = V_60 ;
V_2 -> V_24 = 0 ;
V_2 -> V_25 = V_41 ;
V_2 -> V_14 = NULL ;
V_2 -> V_16 = & V_61 ;
return 0 ;
}
static struct V_1 * F_34 ( struct V_34 * V_35 , long type )
{
struct V_1 * V_2 = F_7 () ;
int error = - V_37 ;
if ( V_2 == NULL )
return F_35 ( error ) ;
error = F_33 ( V_35 , type , V_2 ) ;
if ( error ) {
F_10 ( V_2 ) ;
return F_35 ( error ) ;
}
return V_2 ;
}
static inline int F_36 ( struct V_1 * V_62 , struct V_1 * V_63 )
{
return ( ( V_62 -> V_25 >= V_63 -> V_24 ) &&
( V_63 -> V_25 >= V_62 -> V_24 ) ) ;
}
static int F_37 ( struct V_1 * V_62 , struct V_1 * V_63 )
{
if ( V_62 -> V_16 && V_62 -> V_16 -> V_64 )
return V_63 -> V_16 == V_62 -> V_16 &&
V_62 -> V_16 -> V_64 ( V_62 , V_63 ) ;
return V_62 -> V_21 == V_63 -> V_21 ;
}
static void F_38 ( struct V_1 * V_2 )
{
F_39 ( & V_65 ) ;
V_2 -> V_66 = F_40 () ;
F_41 ( & V_2 -> V_9 , F_42 ( & V_67 ) ) ;
F_43 ( & V_65 ) ;
}
static void F_44 ( struct V_1 * V_2 )
{
if ( F_14 ( & V_2 -> V_9 ) )
return;
F_45 ( & V_65 , V_2 -> V_66 ) ;
F_46 ( & V_2 -> V_9 ) ;
F_47 ( & V_65 , V_2 -> V_66 ) ;
}
static unsigned long
F_48 ( struct V_1 * V_2 )
{
if ( V_2 -> V_16 && V_2 -> V_16 -> V_68 )
return V_2 -> V_16 -> V_68 ( V_2 ) ;
return ( unsigned long ) V_2 -> V_21 ;
}
static void F_49 ( struct V_1 * V_69 )
{
F_50 ( V_70 , & V_69 -> V_9 , F_48 ( V_69 ) ) ;
}
static void F_51 ( struct V_1 * V_69 )
{
F_52 ( & V_69 -> V_9 ) ;
}
static void F_53 ( struct V_1 * V_69 )
{
F_51 ( V_69 ) ;
F_18 ( & V_69 -> V_10 ) ;
V_69 -> V_71 = NULL ;
}
static void F_54 ( struct V_1 * V_69 )
{
F_55 ( & V_72 ) ;
F_53 ( V_69 ) ;
F_56 ( & V_72 ) ;
}
static void F_57 ( struct V_1 * V_73 ,
struct V_1 * V_69 )
{
F_11 ( ! F_13 ( & V_69 -> V_10 ) ) ;
V_69 -> V_71 = V_73 ;
F_58 ( & V_69 -> V_10 , & V_73 -> V_10 ) ;
if ( F_59 ( V_73 ) && ! F_60 ( V_73 ) )
F_49 ( V_69 ) ;
}
static void F_61 ( struct V_1 * V_73 ,
struct V_1 * V_69 )
{
F_55 ( & V_72 ) ;
F_57 ( V_73 , V_69 ) ;
F_56 ( & V_72 ) ;
}
static void F_62 ( struct V_1 * V_73 )
{
if ( F_13 ( & V_73 -> V_10 ) )
return;
F_55 ( & V_72 ) ;
while ( ! F_13 ( & V_73 -> V_10 ) ) {
struct V_1 * V_69 ;
V_69 = F_17 ( & V_73 -> V_10 ,
struct V_1 , V_10 ) ;
F_53 ( V_69 ) ;
if ( V_69 -> V_16 && V_69 -> V_16 -> V_74 )
V_69 -> V_16 -> V_74 ( V_69 ) ;
else
F_63 ( & V_69 -> V_11 ) ;
}
F_56 ( & V_72 ) ;
}
static void F_64 ( struct V_1 * * V_75 , struct V_1 * V_2 )
{
V_2 -> V_76 = F_65 ( F_66 ( V_38 ) ) ;
V_2 -> V_71 = * V_75 ;
* V_75 = V_2 ;
F_38 ( V_2 ) ;
}
static void F_67 ( struct V_1 * * V_77 )
{
struct V_1 * V_2 = * V_77 ;
F_44 ( V_2 ) ;
* V_77 = V_2 -> V_71 ;
V_2 -> V_71 = NULL ;
if ( V_2 -> V_76 ) {
F_68 ( V_2 -> V_76 ) ;
V_2 -> V_76 = NULL ;
}
F_62 ( V_2 ) ;
}
static void F_69 ( struct V_1 * * V_77 ,
struct V_17 * V_18 )
{
struct V_1 * V_2 = * V_77 ;
F_67 ( V_77 ) ;
if ( V_18 )
F_70 ( & V_2 -> V_10 , V_18 ) ;
else
F_10 ( V_2 ) ;
}
static int F_71 ( struct V_1 * V_78 , struct V_1 * V_79 )
{
if ( V_79 -> V_8 == V_31 )
return 1 ;
if ( V_78 -> V_8 == V_31 )
return 1 ;
return 0 ;
}
static int F_72 ( struct V_1 * V_78 , struct V_1 * V_79 )
{
if ( ! F_59 ( V_79 ) || F_37 ( V_78 , V_79 ) )
return ( 0 ) ;
if ( ! F_36 ( V_78 , V_79 ) )
return 0 ;
return ( F_71 ( V_78 , V_79 ) ) ;
}
static int F_73 ( struct V_1 * V_78 , struct V_1 * V_79 )
{
if ( ! F_74 ( V_79 ) || ( V_78 -> V_23 == V_79 -> V_23 ) )
return ( 0 ) ;
if ( ( V_78 -> V_8 & V_27 ) || ( V_79 -> V_8 & V_27 ) )
return 0 ;
return ( F_71 ( V_78 , V_79 ) ) ;
}
void
F_75 ( struct V_34 * V_35 , struct V_1 * V_2 )
{
struct V_1 * V_80 ;
struct V_81 * V_81 = F_29 ( V_35 ) ;
F_55 ( & V_81 -> V_82 ) ;
for ( V_80 = F_29 ( V_35 ) -> V_83 ; V_80 ; V_80 = V_80 -> V_71 ) {
if ( ! F_59 ( V_80 ) )
continue;
if ( F_72 ( V_2 , V_80 ) )
break;
}
if ( V_80 ) {
F_21 ( V_2 , V_80 ) ;
if ( V_80 -> V_76 )
V_2 -> V_22 = F_76 ( V_80 -> V_76 ) ;
} else
V_2 -> V_8 = V_6 ;
F_56 ( & V_81 -> V_82 ) ;
return;
}
static struct V_1 * F_77 ( struct V_1 * V_84 )
{
struct V_1 * V_2 ;
F_78 (blocked_hash, fl, fl_link, posix_owner_key(block_fl)) {
if ( F_37 ( V_2 , V_84 ) )
return V_2 -> V_71 ;
}
return NULL ;
}
static int F_79 ( struct V_1 * V_78 ,
struct V_1 * V_84 )
{
int V_85 = 0 ;
if ( F_60 ( V_78 ) )
return 0 ;
while ( ( V_84 = F_77 ( V_84 ) ) ) {
if ( V_85 ++ > V_86 )
return 0 ;
if ( F_37 ( V_78 , V_84 ) )
return 1 ;
}
return 0 ;
}
static int F_80 ( struct V_34 * V_35 , struct V_1 * V_87 )
{
struct V_1 * V_88 = NULL ;
struct V_1 * * V_89 ;
struct V_81 * V_81 = F_29 ( V_35 ) ;
int error = 0 ;
int V_90 = 0 ;
F_81 ( V_18 ) ;
if ( ! ( V_87 -> V_3 & V_91 ) && ( V_87 -> V_8 != V_6 ) ) {
V_88 = F_7 () ;
if ( ! V_88 )
return - V_37 ;
}
F_55 ( & V_81 -> V_82 ) ;
if ( V_87 -> V_3 & V_91 )
goto V_92;
F_82 (inode, before) {
struct V_1 * V_2 = * V_89 ;
if ( F_59 ( V_2 ) )
break;
if ( F_83 ( V_2 ) )
continue;
if ( V_35 != V_2 -> V_23 )
continue;
if ( V_87 -> V_8 == V_2 -> V_8 )
goto V_93;
V_90 = 1 ;
F_69 ( V_89 , & V_18 ) ;
break;
}
if ( V_87 -> V_8 == V_6 ) {
if ( ( V_87 -> V_3 & V_94 ) && ! V_90 )
error = - V_95 ;
goto V_93;
}
if ( V_90 ) {
F_56 ( & V_81 -> V_82 ) ;
F_84 () ;
F_55 ( & V_81 -> V_82 ) ;
}
V_92:
F_82 (inode, before) {
struct V_1 * V_2 = * V_89 ;
if ( F_59 ( V_2 ) )
break;
if ( F_83 ( V_2 ) )
continue;
if ( ! F_73 ( V_87 , V_2 ) )
continue;
error = - V_96 ;
if ( ! ( V_87 -> V_3 & V_97 ) )
goto V_93;
error = V_98 ;
F_61 ( V_2 , V_87 ) ;
goto V_93;
}
if ( V_87 -> V_3 & V_91 )
goto V_93;
F_22 ( V_88 , V_87 ) ;
F_64 ( V_89 , V_88 ) ;
V_88 = NULL ;
error = 0 ;
V_93:
F_56 ( & V_81 -> V_82 ) ;
if ( V_88 )
F_10 ( V_88 ) ;
F_16 ( & V_18 ) ;
return error ;
}
static int F_85 ( struct V_81 * V_81 , struct V_1 * V_87 , struct V_1 * V_99 )
{
struct V_1 * V_2 ;
struct V_1 * V_88 = NULL ;
struct V_1 * V_100 = NULL ;
struct V_1 * V_101 = NULL ;
struct V_1 * V_102 = NULL ;
struct V_1 * * V_89 ;
int error ;
bool V_103 = false ;
F_81 ( V_18 ) ;
if ( ! ( V_87 -> V_3 & V_91 ) &&
( V_87 -> V_8 != V_6 ||
V_87 -> V_24 != 0 || V_87 -> V_25 != V_41 ) ) {
V_88 = F_7 () ;
V_100 = F_7 () ;
}
F_55 ( & V_81 -> V_82 ) ;
if ( V_87 -> V_8 != V_6 ) {
F_82 (inode, before) {
V_2 = * V_89 ;
if ( ! F_59 ( V_2 ) )
continue;
if ( ! F_72 ( V_87 , V_2 ) )
continue;
if ( V_99 )
F_21 ( V_99 , V_2 ) ;
error = - V_96 ;
if ( ! ( V_87 -> V_3 & V_97 ) )
goto V_93;
error = - V_104 ;
F_55 ( & V_72 ) ;
if ( F_86 ( ! F_79 ( V_87 , V_2 ) ) ) {
error = V_98 ;
F_57 ( V_2 , V_87 ) ;
}
F_56 ( & V_72 ) ;
goto V_93;
}
}
error = 0 ;
if ( V_87 -> V_3 & V_91 )
goto V_93;
V_89 = & V_81 -> V_83 ;
while ( ( V_2 = * V_89 ) && ( ! F_59 ( V_2 ) ||
! F_37 ( V_87 , V_2 ) ) ) {
V_89 = & V_2 -> V_71 ;
}
while ( ( V_2 = * V_89 ) && F_37 ( V_87 , V_2 ) ) {
if ( V_87 -> V_8 == V_2 -> V_8 ) {
if ( V_2 -> V_25 < V_87 -> V_24 - 1 )
goto V_105;
if ( V_2 -> V_24 - 1 > V_87 -> V_25 )
break;
if ( V_2 -> V_24 > V_87 -> V_24 )
V_2 -> V_24 = V_87 -> V_24 ;
else
V_87 -> V_24 = V_2 -> V_24 ;
if ( V_2 -> V_25 < V_87 -> V_25 )
V_2 -> V_25 = V_87 -> V_25 ;
else
V_87 -> V_25 = V_2 -> V_25 ;
if ( V_103 ) {
F_69 ( V_89 , & V_18 ) ;
continue;
}
V_87 = V_2 ;
V_103 = true ;
}
else {
if ( V_2 -> V_25 < V_87 -> V_24 )
goto V_105;
if ( V_2 -> V_24 > V_87 -> V_25 )
break;
if ( V_87 -> V_8 == V_6 )
V_103 = true ;
if ( V_2 -> V_24 < V_87 -> V_24 )
V_101 = V_2 ;
if ( V_2 -> V_25 > V_87 -> V_25 ) {
V_102 = V_2 ;
break;
}
if ( V_2 -> V_24 >= V_87 -> V_24 ) {
if ( V_103 ) {
F_69 ( V_89 , & V_18 ) ;
continue;
}
error = - V_106 ;
if ( ! V_88 )
goto V_93;
F_22 ( V_88 , V_87 ) ;
V_87 = V_88 ;
V_88 = NULL ;
F_69 ( V_89 , & V_18 ) ;
F_64 ( V_89 , V_87 ) ;
V_103 = true ;
}
}
V_105:
V_89 = & V_2 -> V_71 ;
}
error = - V_106 ;
if ( V_102 && V_101 == V_102 && ! V_100 )
goto V_93;
error = 0 ;
if ( ! V_103 ) {
if ( V_87 -> V_8 == V_6 ) {
if ( V_87 -> V_3 & V_94 )
error = - V_95 ;
goto V_93;
}
if ( ! V_88 ) {
error = - V_106 ;
goto V_93;
}
F_22 ( V_88 , V_87 ) ;
F_64 ( V_89 , V_88 ) ;
V_88 = NULL ;
}
if ( V_102 ) {
if ( V_101 == V_102 ) {
V_101 = V_100 ;
V_100 = NULL ;
F_22 ( V_101 , V_102 ) ;
F_64 ( V_89 , V_101 ) ;
}
V_102 -> V_24 = V_87 -> V_25 + 1 ;
F_62 ( V_102 ) ;
}
if ( V_101 ) {
V_101 -> V_25 = V_87 -> V_24 - 1 ;
F_62 ( V_101 ) ;
}
V_93:
F_56 ( & V_81 -> V_82 ) ;
if ( V_88 )
F_10 ( V_88 ) ;
if ( V_100 )
F_10 ( V_100 ) ;
F_16 ( & V_18 ) ;
return error ;
}
int F_87 ( struct V_34 * V_35 , struct V_1 * V_2 ,
struct V_1 * V_99 )
{
return F_85 ( F_29 ( V_35 ) , V_2 , V_99 ) ;
}
int F_88 ( struct V_34 * V_35 , struct V_1 * V_2 )
{
int error ;
F_89 () ;
for (; ; ) {
error = F_87 ( V_35 , V_2 , NULL ) ;
if ( error != V_98 )
break;
error = F_90 ( V_2 -> V_11 , ! V_2 -> V_71 ) ;
if ( ! error )
continue;
F_54 ( V_2 ) ;
break;
}
return error ;
}
int F_91 ( struct V_34 * V_34 )
{
struct V_81 * V_81 = F_29 ( V_34 ) ;
struct V_1 * V_2 ;
F_55 ( & V_81 -> V_82 ) ;
for ( V_2 = V_81 -> V_83 ; V_2 != NULL ; V_2 = V_2 -> V_71 ) {
if ( ! F_59 ( V_2 ) )
continue;
if ( V_2 -> V_21 != V_38 -> V_52 &&
V_2 -> V_21 != V_34 )
break;
}
F_56 ( & V_81 -> V_82 ) ;
return V_2 ? - V_96 : 0 ;
}
int F_92 ( int V_107 , struct V_81 * V_81 ,
struct V_34 * V_35 , T_1 V_108 ,
T_2 V_109 )
{
struct V_1 V_2 ;
int error ;
bool V_110 = false ;
F_19 ( & V_2 ) ;
V_2 . V_22 = V_38 -> V_39 ;
V_2 . V_23 = V_35 ;
V_2 . V_3 = V_53 | V_91 ;
if ( V_35 && ! ( V_35 -> V_111 & V_112 ) )
V_110 = true ;
V_2 . V_8 = ( V_107 == V_113 ) ? V_31 : V_7 ;
V_2 . V_24 = V_108 ;
V_2 . V_25 = V_108 + V_109 - 1 ;
for (; ; ) {
if ( V_35 ) {
V_2 . V_21 = V_35 ;
V_2 . V_3 &= ~ V_97 ;
error = F_85 ( V_81 , & V_2 , NULL ) ;
if ( ! error )
break;
}
if ( V_110 )
V_2 . V_3 |= V_97 ;
V_2 . V_21 = V_38 -> V_52 ;
error = F_85 ( V_81 , & V_2 , NULL ) ;
if ( error != V_98 )
break;
error = F_90 ( V_2 . V_11 , ! V_2 . V_71 ) ;
if ( ! error ) {
if ( F_93 ( V_81 ) )
continue;
}
F_54 ( & V_2 ) ;
break;
}
return error ;
}
static void F_94 ( struct V_1 * V_2 , int V_114 )
{
switch ( V_114 ) {
case V_6 :
V_2 -> V_3 &= ~ V_4 ;
case V_7 :
V_2 -> V_3 &= ~ V_5 ;
}
}
int F_95 ( struct V_1 * * V_89 , int V_114 )
{
struct V_1 * V_2 = * V_89 ;
int error = F_26 ( V_2 , V_114 ) ;
if ( error )
return error ;
F_94 ( V_2 , V_114 ) ;
F_62 ( V_2 ) ;
if ( V_114 == V_6 ) {
struct V_34 * V_35 = V_2 -> V_23 ;
F_96 ( V_35 ) ;
V_35 -> V_115 . V_116 = 0 ;
F_97 ( 0 , V_2 -> V_23 , 0 , & V_2 -> V_57 ) ;
if ( V_2 -> V_57 != NULL ) {
F_98 ( V_117 L_1 , V_2 -> V_57 ) ;
V_2 -> V_57 = NULL ;
}
F_69 ( V_89 , NULL ) ;
}
return 0 ;
}
static bool F_99 ( unsigned long V_118 )
{
if ( ! V_118 )
return false ;
return F_100 ( V_119 , V_118 ) ;
}
static void F_101 ( struct V_81 * V_81 )
{
struct V_1 * * V_89 ;
struct V_1 * V_2 ;
V_89 = & V_81 -> V_83 ;
while ( ( V_2 = * V_89 ) && F_83 ( V_2 ) && F_1 ( V_2 ) ) {
F_102 ( V_81 , V_2 ) ;
if ( F_99 ( V_2 -> V_120 ) )
F_95 ( V_89 , V_7 ) ;
if ( F_99 ( V_2 -> V_121 ) )
F_95 ( V_89 , V_6 ) ;
if ( V_2 == * V_89 )
V_89 = & V_2 -> V_71 ;
}
}
static bool F_103 ( struct V_1 * V_122 , struct V_1 * V_123 )
{
if ( ( V_123 -> V_3 & V_124 ) && ( V_122 -> V_3 & V_60 ) )
return false ;
return F_71 ( V_123 , V_122 ) ;
}
int F_104 ( struct V_81 * V_81 , unsigned int V_125 , unsigned int type )
{
int error = 0 ;
struct V_1 * V_88 , * V_55 ;
struct V_1 * V_2 ;
unsigned long V_126 ;
int V_127 = 0 ;
bool V_128 = false ;
int V_129 = ( V_125 & V_130 ) != V_131 ;
V_88 = F_34 ( NULL , V_129 ? V_31 : V_7 ) ;
if ( F_105 ( V_88 ) )
return F_106 ( V_88 ) ;
V_88 -> V_3 = type ;
F_55 ( & V_81 -> V_82 ) ;
F_101 ( V_81 ) ;
V_55 = V_81 -> V_83 ;
if ( ( V_55 == NULL ) || ! F_83 ( V_55 ) )
goto V_93;
for ( V_2 = V_55 ; V_2 && F_83 ( V_2 ) ; V_2 = V_2 -> V_71 ) {
if ( F_103 ( V_2 , V_88 ) ) {
V_128 = true ;
if ( V_2 -> V_21 == V_38 -> V_52 )
V_127 = 1 ;
}
}
if ( ! V_128 )
goto V_93;
V_126 = 0 ;
if ( V_132 > 0 ) {
V_126 = V_119 + V_132 * V_133 ;
if ( V_126 == 0 )
V_126 ++ ;
}
for ( V_2 = V_55 ; V_2 && F_83 ( V_2 ) ; V_2 = V_2 -> V_71 ) {
if ( ! F_103 ( V_2 , V_88 ) )
continue;
if ( V_129 ) {
if ( V_2 -> V_3 & V_4 )
continue;
V_2 -> V_3 |= V_4 ;
V_2 -> V_121 = V_126 ;
} else {
if ( F_1 ( V_55 ) )
continue;
V_2 -> V_3 |= V_5 ;
V_2 -> V_120 = V_126 ;
}
V_2 -> V_16 -> V_134 ( V_2 ) ;
}
if ( V_127 || ( V_125 & V_112 ) ) {
F_107 ( V_81 , V_88 ) ;
error = - V_135 ;
goto V_93;
}
V_136:
V_126 = V_55 -> V_121 ;
if ( V_126 != 0 )
V_126 -= V_119 ;
if ( V_126 == 0 )
V_126 ++ ;
F_61 ( V_55 , V_88 ) ;
F_108 ( V_81 , V_88 ) ;
F_56 ( & V_81 -> V_82 ) ;
error = F_109 ( V_88 -> V_11 ,
! V_88 -> V_71 , V_126 ) ;
F_55 ( & V_81 -> V_82 ) ;
F_110 ( V_81 , V_88 ) ;
F_54 ( V_88 ) ;
if ( error >= 0 ) {
if ( error == 0 )
F_101 ( V_81 ) ;
for ( V_55 = V_81 -> V_83 ; V_55 && F_83 ( V_55 ) ;
V_55 = V_55 -> V_71 ) {
if ( F_103 ( V_88 , V_55 ) )
goto V_136;
}
error = 0 ;
}
V_93:
F_56 ( & V_81 -> V_82 ) ;
F_10 ( V_88 ) ;
return error ;
}
void F_111 ( struct V_81 * V_81 , struct V_137 * time )
{
struct V_1 * V_55 = V_81 -> V_83 ;
if ( V_55 && F_83 ( V_55 ) && ( V_55 -> V_8 == V_31 ) )
* time = F_112 ( V_81 -> V_138 ) ;
else
* time = V_81 -> V_139 ;
}
int F_113 ( struct V_34 * V_35 )
{
struct V_1 * V_2 ;
struct V_81 * V_81 = F_29 ( V_35 ) ;
int type = V_6 ;
F_55 ( & V_81 -> V_82 ) ;
F_101 ( F_29 ( V_35 ) ) ;
for ( V_2 = F_29 ( V_35 ) -> V_83 ; V_2 && F_83 ( V_2 ) ;
V_2 = V_2 -> V_71 ) {
if ( V_2 -> V_23 == V_35 ) {
type = F_2 ( V_2 ) ;
break;
}
}
F_56 ( & V_81 -> V_82 ) ;
return type ;
}
static int
F_114 ( const struct V_140 * V_140 , const long V_114 )
{
int V_141 = 0 ;
struct V_81 * V_81 = V_140 -> V_142 ;
if ( ( V_114 == V_7 ) && ( F_115 ( & V_81 -> V_143 ) > 0 ) )
return - V_96 ;
if ( ( V_114 == V_31 ) && ( ( F_116 ( V_140 ) > 1 ) ||
( F_115 ( & V_81 -> V_144 ) > 1 ) ) )
V_141 = - V_96 ;
return V_141 ;
}
static int F_117 ( struct V_34 * V_35 , long V_114 , struct V_1 * * V_145 )
{
struct V_1 * V_2 , * * V_89 , * * V_146 = NULL , * V_122 ;
struct V_140 * V_140 = V_35 -> V_147 . V_140 ;
struct V_81 * V_81 = V_140 -> V_142 ;
bool V_148 = ( * V_145 ) -> V_3 & V_124 ;
int error ;
V_122 = * V_145 ;
F_118 ( V_81 , V_122 ) ;
if ( V_148 && ! F_119 ( & V_81 -> V_149 ) )
return - V_96 ;
if ( V_148 && V_114 == V_31 ) {
F_120 ( & V_81 -> V_149 ) ;
F_23 ( 1 ) ;
return - V_33 ;
}
error = F_114 ( V_140 , V_114 ) ;
if ( error )
goto V_93;
error = - V_96 ;
for ( V_89 = & V_81 -> V_83 ;
( ( V_2 = * V_89 ) != NULL ) && F_83 ( V_2 ) ;
V_89 = & V_2 -> V_71 ) {
if ( V_2 -> V_23 == V_35 ) {
V_146 = V_89 ;
continue;
}
if ( V_114 == V_31 )
goto V_93;
if ( V_2 -> V_3 & V_4 )
goto V_93;
}
if ( V_146 != NULL ) {
error = V_122 -> V_16 -> V_150 ( V_146 , V_114 ) ;
if ( ! error )
* V_145 = * V_146 ;
goto V_93;
}
error = - V_33 ;
if ( ! V_151 )
goto V_93;
F_64 ( V_89 , V_122 ) ;
F_121 () ;
error = F_114 ( V_140 , V_114 ) ;
if ( error )
F_67 ( V_89 ) ;
V_93:
if ( V_148 )
F_120 ( & V_81 -> V_149 ) ;
return error ;
}
static int F_122 ( struct V_34 * V_35 , struct V_1 * * V_145 )
{
struct V_1 * V_2 , * * V_89 ;
struct V_140 * V_140 = V_35 -> V_147 . V_140 ;
struct V_81 * V_81 = V_140 -> V_142 ;
F_123 ( V_81 , * V_145 ) ;
for ( V_89 = & V_81 -> V_83 ;
( ( V_2 = * V_89 ) != NULL ) && F_83 ( V_2 ) ;
V_89 = & V_2 -> V_71 ) {
if ( V_2 -> V_23 != V_35 )
continue;
return ( * V_145 ) -> V_16 -> V_150 ( V_89 , V_6 ) ;
}
return - V_96 ;
}
int F_124 ( struct V_34 * V_35 , long V_114 , struct V_1 * * V_145 )
{
struct V_140 * V_140 = V_35 -> V_147 . V_140 ;
struct V_81 * V_81 = V_140 -> V_142 ;
int error ;
if ( ( ! F_125 ( F_126 () , V_81 -> V_152 ) ) && ! F_127 ( V_153 ) )
return - V_154 ;
if ( ! F_128 ( V_81 -> V_155 ) )
return - V_33 ;
error = F_129 ( V_35 , V_114 ) ;
if ( error )
return error ;
F_101 ( V_81 ) ;
F_11 ( ! ( * V_145 ) -> V_16 -> V_134 ) ;
switch ( V_114 ) {
case V_6 :
return F_122 ( V_35 , V_145 ) ;
case V_7 :
case V_31 :
return F_117 ( V_35 , V_114 , V_145 ) ;
default:
return - V_33 ;
}
}
static int F_130 ( struct V_34 * V_35 , long V_114 , struct V_1 * * V_122 )
{
if ( V_35 -> V_156 -> V_157 )
return V_35 -> V_156 -> V_157 ( V_35 , V_114 , V_122 ) ;
else
return F_124 ( V_35 , V_114 , V_122 ) ;
}
int F_131 ( struct V_34 * V_35 , long V_114 , struct V_1 * * V_122 )
{
struct V_81 * V_81 = F_29 ( V_35 ) ;
int error ;
F_55 ( & V_81 -> V_82 ) ;
error = F_130 ( V_35 , V_114 , V_122 ) ;
F_56 ( & V_81 -> V_82 ) ;
return error ;
}
static int F_132 ( struct V_34 * V_35 )
{
struct V_1 V_2 , * V_145 = & V_2 ;
F_33 ( V_35 , V_6 , V_145 ) ;
return F_131 ( V_35 , V_6 , & V_145 ) ;
}
static int F_133 ( unsigned int V_158 , struct V_34 * V_35 , long V_114 )
{
struct V_1 * V_2 , * V_141 ;
struct V_81 * V_81 = F_29 ( V_35 ) ;
struct V_159 * V_19 ;
int error ;
V_2 = F_34 ( V_35 , V_114 ) ;
if ( F_105 ( V_2 ) )
return F_106 ( V_2 ) ;
V_19 = F_134 () ;
if ( ! V_19 ) {
F_10 ( V_2 ) ;
return - V_37 ;
}
V_141 = V_2 ;
F_55 ( & V_81 -> V_82 ) ;
error = F_130 ( V_35 , V_114 , & V_141 ) ;
if ( error )
goto V_160;
if ( V_141 == V_2 )
V_2 = NULL ;
if ( ! F_135 ( V_158 , V_35 , & V_141 -> V_57 , V_19 ) )
V_19 = NULL ;
error = F_136 ( V_35 , F_137 ( V_38 ) , V_161 , 0 ) ;
V_160:
F_56 ( & V_81 -> V_82 ) ;
if ( V_2 )
F_10 ( V_2 ) ;
if ( V_19 )
F_138 ( V_19 ) ;
return error ;
}
int F_139 ( unsigned int V_158 , struct V_34 * V_35 , long V_114 )
{
if ( V_114 == V_6 )
return F_132 ( V_35 ) ;
return F_133 ( V_158 , V_35 , V_114 ) ;
}
int F_140 ( struct V_34 * V_35 , struct V_1 * V_2 )
{
int error ;
F_89 () ;
for (; ; ) {
error = F_80 ( V_35 , V_2 ) ;
if ( error != V_98 )
break;
error = F_90 ( V_2 -> V_11 , ! V_2 -> V_71 ) ;
if ( ! error )
continue;
F_54 ( V_2 ) ;
break;
}
return error ;
}
int F_141 ( struct V_34 * V_35 , struct V_1 * V_2 )
{
if ( V_35 -> V_156 -> V_36 )
return V_35 -> V_156 -> V_36 ( V_35 , V_162 , V_2 ) ;
F_75 ( V_35 , V_2 ) ;
return 0 ;
}
static int F_142 ( struct V_55 * V_55 , struct V_1 * V_2 )
{
V_55 -> V_163 = F_60 ( V_2 ) ? - 1 : V_2 -> V_22 ;
#if V_164 == 32
if ( V_2 -> V_24 > V_165 )
return - V_50 ;
if ( V_2 -> V_25 != V_41 && V_2 -> V_25 > V_165 )
return - V_50 ;
#endif
V_55 -> V_49 = V_2 -> V_24 ;
V_55 -> V_51 = V_2 -> V_25 == V_41 ? 0 :
V_2 -> V_25 - V_2 -> V_24 + 1 ;
V_55 -> V_44 = 0 ;
V_55 -> V_54 = V_2 -> V_8 ;
return 0 ;
}
static void F_143 ( struct V_42 * V_55 , struct V_1 * V_2 )
{
V_55 -> V_163 = F_60 ( V_2 ) ? - 1 : V_2 -> V_22 ;
V_55 -> V_49 = V_2 -> V_24 ;
V_55 -> V_51 = V_2 -> V_25 == V_41 ? 0 :
V_2 -> V_25 - V_2 -> V_24 + 1 ;
V_55 -> V_44 = 0 ;
V_55 -> V_54 = V_2 -> V_8 ;
}
int F_144 ( struct V_34 * V_35 , unsigned int V_26 , struct V_55 T_3 * V_43 )
{
struct V_1 V_1 ;
struct V_55 V_55 ;
int error ;
error = - V_166 ;
if ( F_145 ( & V_55 , V_43 , sizeof( V_55 ) ) )
goto V_93;
error = - V_33 ;
if ( ( V_55 . V_54 != V_7 ) && ( V_55 . V_54 != V_31 ) )
goto V_93;
error = F_30 ( V_35 , & V_1 , & V_55 ) ;
if ( error )
goto V_93;
if ( V_26 == V_167 ) {
error = - V_33 ;
if ( V_55 . V_163 != 0 )
goto V_93;
V_26 = V_162 ;
V_1 . V_3 |= V_168 ;
V_1 . V_21 = V_35 ;
}
error = F_141 ( V_35 , & V_1 ) ;
if ( error )
goto V_93;
V_55 . V_54 = V_1 . V_8 ;
if ( V_1 . V_8 != V_6 ) {
error = F_142 ( & V_55 , & V_1 ) ;
if ( error )
goto V_93;
}
error = - V_166 ;
if ( ! F_146 ( V_43 , & V_55 , sizeof( V_55 ) ) )
error = 0 ;
V_93:
return error ;
}
int F_147 ( struct V_34 * V_35 , unsigned int V_26 , struct V_1 * V_2 , struct V_1 * V_169 )
{
if ( V_35 -> V_156 -> V_36 )
return V_35 -> V_156 -> V_36 ( V_35 , V_26 , V_2 ) ;
else
return F_87 ( V_35 , V_2 , V_169 ) ;
}
static int F_148 ( struct V_34 * V_35 , unsigned int V_26 ,
struct V_1 * V_2 )
{
int error ;
error = F_129 ( V_35 , V_2 -> V_8 ) ;
if ( error )
return error ;
for (; ; ) {
error = F_147 ( V_35 , V_26 , V_2 , NULL ) ;
if ( error != V_98 )
break;
error = F_90 ( V_2 -> V_11 , ! V_2 -> V_71 ) ;
if ( ! error )
continue;
F_54 ( V_2 ) ;
break;
}
return error ;
}
static int
F_149 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_8 ) {
case V_7 :
if ( ! ( V_2 -> V_23 -> V_170 & V_171 ) )
return - V_172 ;
break;
case V_31 :
if ( ! ( V_2 -> V_23 -> V_170 & V_173 ) )
return - V_172 ;
}
return 0 ;
}
int F_150 ( unsigned int V_158 , struct V_34 * V_35 , unsigned int V_26 ,
struct V_55 T_3 * V_43 )
{
struct V_1 * V_1 = F_7 () ;
struct V_55 V_55 ;
struct V_81 * V_81 ;
struct V_34 * V_174 ;
int error ;
if ( V_1 == NULL )
return - V_106 ;
error = - V_166 ;
if ( F_145 ( & V_55 , V_43 , sizeof( V_55 ) ) )
goto V_93;
V_81 = F_29 ( V_35 ) ;
if ( F_151 ( V_81 ) && F_152 ( V_35 -> V_175 ) ) {
error = - V_96 ;
goto V_93;
}
V_176:
error = F_30 ( V_35 , V_1 , & V_55 ) ;
if ( error )
goto V_93;
error = F_149 ( V_1 ) ;
if ( error )
goto V_93;
switch ( V_26 ) {
case V_177 :
error = - V_33 ;
if ( V_55 . V_163 != 0 )
goto V_93;
V_26 = V_178 ;
V_1 -> V_3 |= V_168 ;
V_1 -> V_21 = V_35 ;
break;
case V_179 :
error = - V_33 ;
if ( V_55 . V_163 != 0 )
goto V_93;
V_26 = V_180 ;
V_1 -> V_3 |= V_168 ;
V_1 -> V_21 = V_35 ;
case V_180 :
V_1 -> V_3 |= V_97 ;
}
error = F_148 ( V_35 , V_26 , V_1 ) ;
F_55 ( & V_38 -> V_52 -> V_1 ) ;
V_174 = F_153 ( V_158 ) ;
F_56 ( & V_38 -> V_52 -> V_1 ) ;
if ( ! error && V_174 != V_35 && V_55 . V_54 != V_6 ) {
V_55 . V_54 = V_6 ;
goto V_176;
}
V_93:
F_10 ( V_1 ) ;
return error ;
}
int F_154 ( struct V_34 * V_35 , unsigned int V_26 , struct V_42 T_3 * V_43 )
{
struct V_1 V_1 ;
struct V_42 V_55 ;
int error ;
error = - V_166 ;
if ( F_145 ( & V_55 , V_43 , sizeof( V_55 ) ) )
goto V_93;
error = - V_33 ;
if ( ( V_55 . V_54 != V_7 ) && ( V_55 . V_54 != V_31 ) )
goto V_93;
error = F_27 ( V_35 , & V_1 , & V_55 ) ;
if ( error )
goto V_93;
if ( V_26 == V_167 ) {
error = - V_33 ;
if ( V_55 . V_163 != 0 )
goto V_93;
V_26 = V_181 ;
V_1 . V_3 |= V_168 ;
V_1 . V_21 = V_35 ;
}
error = F_141 ( V_35 , & V_1 ) ;
if ( error )
goto V_93;
V_55 . V_54 = V_1 . V_8 ;
if ( V_1 . V_8 != V_6 )
F_143 ( & V_55 , & V_1 ) ;
error = - V_166 ;
if ( ! F_146 ( V_43 , & V_55 , sizeof( V_55 ) ) )
error = 0 ;
V_93:
return error ;
}
int F_155 ( unsigned int V_158 , struct V_34 * V_35 , unsigned int V_26 ,
struct V_42 T_3 * V_43 )
{
struct V_1 * V_1 = F_7 () ;
struct V_42 V_55 ;
struct V_81 * V_81 ;
struct V_34 * V_174 ;
int error ;
if ( V_1 == NULL )
return - V_106 ;
error = - V_166 ;
if ( F_145 ( & V_55 , V_43 , sizeof( V_55 ) ) )
goto V_93;
V_81 = F_29 ( V_35 ) ;
if ( F_151 ( V_81 ) && F_152 ( V_35 -> V_175 ) ) {
error = - V_96 ;
goto V_93;
}
V_176:
error = F_27 ( V_35 , V_1 , & V_55 ) ;
if ( error )
goto V_93;
error = F_149 ( V_1 ) ;
if ( error )
goto V_93;
switch ( V_26 ) {
case V_177 :
error = - V_33 ;
if ( V_55 . V_163 != 0 )
goto V_93;
V_26 = V_182 ;
V_1 -> V_3 |= V_168 ;
V_1 -> V_21 = V_35 ;
break;
case V_179 :
error = - V_33 ;
if ( V_55 . V_163 != 0 )
goto V_93;
V_26 = V_183 ;
V_1 -> V_3 |= V_168 ;
V_1 -> V_21 = V_35 ;
case V_183 :
V_1 -> V_3 |= V_97 ;
}
error = F_148 ( V_35 , V_26 , V_1 ) ;
F_55 ( & V_38 -> V_52 -> V_1 ) ;
V_174 = F_153 ( V_158 ) ;
F_56 ( & V_38 -> V_52 -> V_1 ) ;
if ( ! error && V_174 != V_35 && V_55 . V_54 != V_6 ) {
V_55 . V_54 = V_6 ;
goto V_176;
}
V_93:
F_10 ( V_1 ) ;
return error ;
}
void F_156 ( struct V_34 * V_35 , T_4 V_184 )
{
struct V_1 V_36 ;
if ( ! F_29 ( V_35 ) -> V_83 )
return;
V_36 . V_8 = V_6 ;
V_36 . V_3 = V_53 | V_185 ;
V_36 . V_24 = 0 ;
V_36 . V_25 = V_41 ;
V_36 . V_21 = V_184 ;
V_36 . V_22 = V_38 -> V_39 ;
V_36 . V_23 = V_35 ;
V_36 . V_14 = NULL ;
V_36 . V_16 = NULL ;
F_147 ( V_35 , V_178 , & V_36 , NULL ) ;
if ( V_36 . V_14 && V_36 . V_14 -> V_15 )
V_36 . V_14 -> V_15 ( & V_36 ) ;
}
void F_157 ( struct V_34 * V_35 )
{
struct V_81 * V_81 = F_29 ( V_35 ) ;
struct V_1 * V_2 ;
struct V_1 * * V_89 ;
F_81 ( V_18 ) ;
if ( ! V_81 -> V_83 )
return;
F_156 ( V_35 , V_35 ) ;
if ( V_35 -> V_156 -> V_55 ) {
struct V_1 V_2 = {
. V_21 = V_35 ,
. V_22 = V_38 -> V_39 ,
. V_23 = V_35 ,
. V_3 = V_40 ,
. V_8 = V_6 ,
. V_25 = V_41 ,
} ;
V_35 -> V_156 -> V_55 ( V_35 , V_180 , & V_2 ) ;
if ( V_2 . V_14 && V_2 . V_14 -> V_15 )
V_2 . V_14 -> V_15 ( & V_2 ) ;
}
F_55 ( & V_81 -> V_82 ) ;
V_89 = & V_81 -> V_83 ;
while ( ( V_2 = * V_89 ) != NULL ) {
if ( V_2 -> V_23 == V_35 ) {
if ( F_83 ( V_2 ) ) {
F_95 ( V_89 , V_6 ) ;
continue;
}
F_158 ( ! F_74 ( V_2 ) ,
L_2 ,
F_159 ( V_81 -> V_138 -> V_186 ) ,
F_160 ( V_81 -> V_138 -> V_186 ) , V_81 -> V_187 ,
V_2 -> V_8 , V_2 -> V_3 ,
V_2 -> V_24 , V_2 -> V_25 ) ;
F_69 ( V_89 , & V_18 ) ;
continue;
}
V_89 = & V_2 -> V_71 ;
}
F_56 ( & V_81 -> V_82 ) ;
F_16 ( & V_18 ) ;
}
int
F_161 ( struct V_1 * V_69 )
{
int V_188 = 0 ;
F_55 ( & V_72 ) ;
if ( V_69 -> V_71 )
F_53 ( V_69 ) ;
else
V_188 = - V_95 ;
F_56 ( & V_72 ) ;
return V_188 ;
}
int F_162 ( struct V_34 * V_35 , struct V_1 * V_2 )
{
if ( V_35 -> V_156 -> V_36 )
return V_35 -> V_156 -> V_36 ( V_35 , V_189 , V_2 ) ;
return 0 ;
}
static void F_163 ( struct V_190 * V_174 , struct V_1 * V_2 ,
T_1 V_191 , char * V_192 )
{
struct V_81 * V_81 = NULL ;
unsigned int V_22 ;
if ( V_2 -> V_76 )
V_22 = F_76 ( V_2 -> V_76 ) ;
else
V_22 = V_2 -> V_22 ;
if ( V_2 -> V_23 != NULL )
V_81 = F_29 ( V_2 -> V_23 ) ;
F_164 ( V_174 , L_3 , V_191 , V_192 ) ;
if ( F_59 ( V_2 ) ) {
if ( V_2 -> V_3 & V_91 )
F_165 ( V_174 , L_4 ) ;
else if ( F_60 ( V_2 ) )
F_165 ( V_174 , L_5 ) ;
else
F_165 ( V_174 , L_6 ) ;
F_164 ( V_174 , L_7 ,
( V_81 == NULL ) ? L_8 :
F_151 ( V_81 ) ? L_9 : L_10 ) ;
} else if ( F_74 ( V_2 ) ) {
if ( V_2 -> V_8 & V_27 ) {
F_165 ( V_174 , L_11 ) ;
} else {
F_165 ( V_174 , L_12 ) ;
}
} else if ( F_83 ( V_2 ) ) {
if ( V_2 -> V_3 & V_124 )
F_165 ( V_174 , L_13 ) ;
else
F_165 ( V_174 , L_14 ) ;
if ( F_1 ( V_2 ) )
F_165 ( V_174 , L_15 ) ;
else if ( V_2 -> V_23 )
F_165 ( V_174 , L_16 ) ;
else
F_165 ( V_174 , L_17 ) ;
} else {
F_165 ( V_174 , L_18 ) ;
}
if ( V_2 -> V_8 & V_27 ) {
F_164 ( V_174 , L_19 ,
( V_2 -> V_8 & V_193 )
? ( V_2 -> V_8 & V_194 ) ? L_20 : L_21
: ( V_2 -> V_8 & V_194 ) ? L_22 : L_23 ) ;
} else {
F_164 ( V_174 , L_19 ,
( F_1 ( V_2 ) )
? ( V_2 -> V_8 == V_6 ) ? L_24 : L_21
: ( V_2 -> V_8 == V_31 ) ? L_22 : L_21 ) ;
}
if ( V_81 ) {
#ifdef F_166
F_164 ( V_174 , L_25 , V_22 ,
V_81 -> V_138 -> V_195 , V_81 -> V_187 ) ;
#else
F_164 ( V_174 , L_26 , V_22 ,
F_159 ( V_81 -> V_138 -> V_186 ) ,
F_160 ( V_81 -> V_138 -> V_186 ) , V_81 -> V_187 ) ;
#endif
} else {
F_164 ( V_174 , L_27 , V_22 ) ;
}
if ( F_59 ( V_2 ) ) {
if ( V_2 -> V_25 == V_41 )
F_164 ( V_174 , L_28 , V_2 -> V_24 ) ;
else
F_164 ( V_174 , L_29 , V_2 -> V_24 , V_2 -> V_25 ) ;
} else {
F_165 ( V_174 , L_30 ) ;
}
}
static int F_167 ( struct V_190 * V_174 , void * V_196 )
{
struct V_197 * V_198 = V_174 -> V_199 ;
struct V_1 * V_2 , * V_200 ;
V_2 = F_168 ( V_196 , struct V_1 , V_9 ) ;
F_163 ( V_174 , V_2 , V_198 -> V_201 , L_31 ) ;
F_169 (bfl, &fl->fl_block, fl_block)
F_163 ( V_174 , V_200 , V_198 -> V_201 , L_32 ) ;
return 0 ;
}
static void * F_170 ( struct V_190 * V_174 , T_1 * V_75 )
__acquires( &blocked_lock_lock
static void * F_171 ( struct V_190 * V_174 , void * V_196 , T_1 * V_75 )
{
struct V_197 * V_198 = V_174 -> V_199 ;
++ V_198 -> V_201 ;
return F_172 ( V_196 , & V_67 , & V_198 -> V_202 , V_75 ) ;
}
static void F_173 ( struct V_190 * V_174 , void * V_196 )
__releases( &blocked_lock_lock
static int F_174 ( struct V_81 * V_81 , struct V_34 * V_35 )
{
return F_175 ( V_35 , & V_203 ,
sizeof( struct V_197 ) ) ;
}
static int T_5 F_176 ( void )
{
F_177 ( L_33 , 0 , NULL , & V_204 ) ;
return 0 ;
}
int F_178 ( struct V_81 * V_81 , T_1 V_205 , unsigned long V_206 )
{
struct V_1 * V_2 ;
int V_207 = 1 ;
F_55 ( & V_81 -> V_82 ) ;
for ( V_2 = V_81 -> V_83 ; V_2 != NULL ; V_2 = V_2 -> V_71 ) {
if ( F_59 ( V_2 ) ) {
if ( V_2 -> V_8 == V_7 )
continue;
if ( ( V_2 -> V_25 < V_205 ) || ( V_2 -> V_24 > ( V_205 + V_206 ) ) )
continue;
} else if ( F_74 ( V_2 ) ) {
if ( ! ( V_2 -> V_8 & V_27 ) )
continue;
if ( V_2 -> V_8 & V_193 )
continue;
} else
continue;
V_207 = 0 ;
break;
}
F_56 ( & V_81 -> V_82 ) ;
return V_207 ;
}
int F_179 ( struct V_81 * V_81 , T_1 V_205 , unsigned long V_206 )
{
struct V_1 * V_2 ;
int V_207 = 1 ;
F_55 ( & V_81 -> V_82 ) ;
for ( V_2 = V_81 -> V_83 ; V_2 != NULL ; V_2 = V_2 -> V_71 ) {
if ( F_59 ( V_2 ) ) {
if ( ( V_2 -> V_25 < V_205 ) || ( V_2 -> V_24 > ( V_205 + V_206 ) ) )
continue;
} else if ( F_74 ( V_2 ) ) {
if ( ! ( V_2 -> V_8 & V_27 ) )
continue;
if ( V_2 -> V_8 & V_194 )
continue;
} else
continue;
V_207 = 0 ;
break;
}
F_56 ( & V_81 -> V_82 ) ;
return V_207 ;
}
static int T_5 F_180 ( void )
{
int V_85 ;
V_12 = F_181 ( L_34 ,
sizeof( struct V_1 ) , 0 , V_208 , NULL ) ;
F_182 ( & V_65 , L_35 ) ;
F_183 (i)
F_184 ( F_185 ( & V_67 , V_85 ) ) ;
return 0 ;
}
