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
void F_3 ( void )
{
F_4 ( & V_9 ) ;
}
void F_5 ( void )
{
F_6 ( & V_9 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
F_8 ( & V_2 -> V_10 ) ;
F_8 ( & V_2 -> V_11 ) ;
F_9 ( & V_2 -> V_12 ) ;
}
struct V_1 * F_10 ( void )
{
struct V_1 * V_2 = F_11 ( V_13 , V_14 ) ;
if ( V_2 )
F_7 ( V_2 ) ;
return V_2 ;
}
void F_12 ( struct V_1 * V_2 )
{
if ( V_2 -> V_15 ) {
if ( V_2 -> V_15 -> V_16 )
V_2 -> V_15 -> V_16 ( V_2 ) ;
V_2 -> V_15 = NULL ;
}
V_2 -> V_17 = NULL ;
}
void F_13 ( struct V_1 * V_2 )
{
F_14 ( F_15 ( & V_2 -> V_12 ) ) ;
F_14 ( ! F_16 ( & V_2 -> V_11 ) ) ;
F_14 ( ! F_16 ( & V_2 -> V_10 ) ) ;
F_12 ( V_2 ) ;
F_17 ( V_13 , V_2 ) ;
}
void F_18 ( struct V_1 * V_2 )
{
memset ( V_2 , 0 , sizeof( struct V_1 ) ) ;
F_7 ( V_2 ) ;
}
static void F_19 ( struct V_1 * V_18 , struct V_1 * V_2 )
{
if ( V_2 -> V_15 ) {
if ( V_2 -> V_15 -> V_19 )
V_2 -> V_15 -> V_19 ( V_18 , V_2 ) ;
V_18 -> V_15 = V_2 -> V_15 ;
}
if ( V_2 -> V_17 )
V_18 -> V_17 = V_2 -> V_17 ;
}
void F_20 ( struct V_1 * V_18 , const struct V_1 * V_2 )
{
V_18 -> V_20 = V_2 -> V_20 ;
V_18 -> V_21 = V_2 -> V_21 ;
V_18 -> V_22 = NULL ;
V_18 -> V_3 = V_2 -> V_3 ;
V_18 -> V_8 = V_2 -> V_8 ;
V_18 -> V_23 = V_2 -> V_23 ;
V_18 -> V_24 = V_2 -> V_24 ;
V_18 -> V_15 = NULL ;
V_18 -> V_17 = NULL ;
}
void F_21 ( struct V_1 * V_18 , struct V_1 * V_2 )
{
F_12 ( V_18 ) ;
F_20 ( V_18 , V_2 ) ;
V_18 -> V_22 = V_2 -> V_22 ;
V_18 -> V_15 = V_2 -> V_15 ;
V_18 -> V_17 = V_2 -> V_17 ;
F_19 ( V_18 , V_2 ) ;
}
static inline int F_22 ( int V_25 ) {
if ( V_25 & V_26 )
return V_25 & ( V_26 | V_27 ) ;
switch ( V_25 ) {
case V_28 :
return V_7 ;
case V_29 :
return V_30 ;
case V_31 :
return V_6 ;
}
return - V_32 ;
}
static int F_23 ( struct V_33 * V_34 , struct V_1 * * V_35 ,
unsigned int V_25 )
{
struct V_1 * V_2 ;
int type = F_22 ( V_25 ) ;
if ( type < 0 )
return type ;
V_2 = F_10 () ;
if ( V_2 == NULL )
return - V_36 ;
V_2 -> V_22 = V_34 ;
V_2 -> V_21 = V_37 -> V_38 ;
V_2 -> V_3 = V_39 ;
V_2 -> V_8 = type ;
V_2 -> V_24 = V_40 ;
* V_35 = V_2 ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 , long type )
{
switch ( type ) {
case V_7 :
case V_30 :
case V_6 :
V_2 -> V_8 = type ;
break;
default:
return - V_32 ;
}
return 0 ;
}
static int F_25 ( struct V_33 * V_34 , struct V_1 * V_2 ,
struct V_41 * V_42 )
{
T_1 V_43 , V_44 ;
switch ( V_42 -> V_45 ) {
case V_46 :
V_43 = 0 ;
break;
case V_47 :
V_43 = V_34 -> V_48 ;
break;
case V_49 :
V_43 = F_26 ( F_27 ( V_34 ) ) ;
break;
default:
return - V_32 ;
}
V_43 += V_42 -> V_50 ;
if ( V_43 < 0 )
return - V_32 ;
V_2 -> V_24 = V_40 ;
if ( V_42 -> V_51 > 0 ) {
V_44 = V_43 + V_42 -> V_51 - 1 ;
V_2 -> V_24 = V_44 ;
} else if ( V_42 -> V_51 < 0 ) {
V_44 = V_43 - 1 ;
V_2 -> V_24 = V_44 ;
V_43 += V_42 -> V_51 ;
if ( V_43 < 0 )
return - V_32 ;
}
V_2 -> V_23 = V_43 ;
if ( V_2 -> V_24 < V_2 -> V_23 )
return - V_52 ;
V_2 -> V_20 = V_37 -> V_53 ;
V_2 -> V_21 = V_37 -> V_38 ;
V_2 -> V_22 = V_34 ;
V_2 -> V_3 = V_54 ;
V_2 -> V_15 = NULL ;
V_2 -> V_17 = NULL ;
return F_24 ( V_2 , V_42 -> V_55 ) ;
}
static int F_28 ( struct V_33 * V_34 , struct V_1 * V_2 ,
struct V_56 * V_42 )
{
T_2 V_43 ;
switch ( V_42 -> V_45 ) {
case V_46 :
V_43 = 0 ;
break;
case V_47 :
V_43 = V_34 -> V_48 ;
break;
case V_49 :
V_43 = F_26 ( F_27 ( V_34 ) ) ;
break;
default:
return - V_32 ;
}
V_43 += V_42 -> V_50 ;
if ( V_43 < 0 )
return - V_32 ;
V_2 -> V_24 = V_40 ;
if ( V_42 -> V_51 > 0 ) {
V_2 -> V_24 = V_43 + V_42 -> V_51 - 1 ;
} else if ( V_42 -> V_51 < 0 ) {
V_2 -> V_24 = V_43 - 1 ;
V_43 += V_42 -> V_51 ;
if ( V_43 < 0 )
return - V_32 ;
}
V_2 -> V_23 = V_43 ;
if ( V_2 -> V_24 < V_2 -> V_23 )
return - V_52 ;
V_2 -> V_20 = V_37 -> V_53 ;
V_2 -> V_21 = V_37 -> V_38 ;
V_2 -> V_22 = V_34 ;
V_2 -> V_3 = V_54 ;
V_2 -> V_15 = NULL ;
V_2 -> V_17 = NULL ;
return F_24 ( V_2 , V_42 -> V_55 ) ;
}
static void F_29 ( struct V_1 * V_2 )
{
F_30 ( & V_2 -> V_57 , V_58 , V_59 ) ;
}
static int F_31 ( struct V_33 * V_34 , long type , struct V_1 * V_2 )
{
if ( F_24 ( V_2 , type ) != 0 )
return - V_32 ;
V_2 -> V_20 = V_37 -> V_53 ;
V_2 -> V_21 = V_37 -> V_38 ;
V_2 -> V_22 = V_34 ;
V_2 -> V_3 = V_60 ;
V_2 -> V_23 = 0 ;
V_2 -> V_24 = V_40 ;
V_2 -> V_15 = NULL ;
V_2 -> V_17 = & V_61 ;
return 0 ;
}
static struct V_1 * F_32 ( struct V_33 * V_34 , long type )
{
struct V_1 * V_2 = F_10 () ;
int error = - V_36 ;
if ( V_2 == NULL )
return F_33 ( error ) ;
error = F_31 ( V_34 , type , V_2 ) ;
if ( error ) {
F_13 ( V_2 ) ;
return F_33 ( error ) ;
}
return V_2 ;
}
static inline int F_34 ( struct V_1 * V_62 , struct V_1 * V_63 )
{
return ( ( V_62 -> V_24 >= V_63 -> V_23 ) &&
( V_63 -> V_24 >= V_62 -> V_23 ) ) ;
}
static int F_35 ( struct V_1 * V_62 , struct V_1 * V_63 )
{
if ( V_62 -> V_17 && V_62 -> V_17 -> V_64 )
return V_63 -> V_17 == V_62 -> V_17 &&
V_62 -> V_17 -> V_64 ( V_62 , V_63 ) ;
return V_62 -> V_20 == V_63 -> V_20 ;
}
static void F_36 ( struct V_1 * V_65 )
{
F_37 ( & V_65 -> V_11 ) ;
F_37 ( & V_65 -> V_10 ) ;
V_65 -> V_66 = NULL ;
}
void F_38 ( struct V_1 * V_65 )
{
F_3 () ;
F_36 ( V_65 ) ;
F_5 () ;
}
static void F_39 ( struct V_1 * V_67 ,
struct V_1 * V_65 )
{
F_14 ( ! F_16 ( & V_65 -> V_11 ) ) ;
F_40 ( & V_65 -> V_11 , & V_67 -> V_11 ) ;
V_65 -> V_66 = V_67 ;
if ( F_41 ( V_67 ) )
F_42 ( & V_65 -> V_10 , & V_68 ) ;
}
static void F_43 ( struct V_1 * V_67 )
{
while ( ! F_16 ( & V_67 -> V_11 ) ) {
struct V_1 * V_65 ;
V_65 = F_44 ( & V_67 -> V_11 ,
struct V_1 , V_11 ) ;
F_36 ( V_65 ) ;
if ( V_65 -> V_17 && V_65 -> V_17 -> V_69 )
V_65 -> V_17 -> V_69 ( V_65 ) ;
else
F_45 ( & V_65 -> V_12 ) ;
}
}
static void F_46 ( struct V_1 * * V_70 , struct V_1 * V_2 )
{
F_42 ( & V_2 -> V_10 , & V_71 ) ;
V_2 -> V_72 = F_47 ( F_48 ( V_37 ) ) ;
V_2 -> V_66 = * V_70 ;
* V_70 = V_2 ;
}
static void F_49 ( struct V_1 * * V_73 )
{
struct V_1 * V_2 = * V_73 ;
* V_73 = V_2 -> V_66 ;
V_2 -> V_66 = NULL ;
F_37 ( & V_2 -> V_10 ) ;
if ( V_2 -> V_72 ) {
F_50 ( V_2 -> V_72 ) ;
V_2 -> V_72 = NULL ;
}
F_43 ( V_2 ) ;
F_13 ( V_2 ) ;
}
static int F_51 ( struct V_1 * V_74 , struct V_1 * V_75 )
{
if ( V_75 -> V_8 == V_30 )
return 1 ;
if ( V_74 -> V_8 == V_30 )
return 1 ;
return 0 ;
}
static int F_52 ( struct V_1 * V_74 , struct V_1 * V_75 )
{
if ( ! F_41 ( V_75 ) || F_35 ( V_74 , V_75 ) )
return ( 0 ) ;
if ( ! F_34 ( V_74 , V_75 ) )
return 0 ;
return ( F_51 ( V_74 , V_75 ) ) ;
}
static int F_53 ( struct V_1 * V_74 , struct V_1 * V_75 )
{
if ( ! F_54 ( V_75 ) || ( V_74 -> V_22 == V_75 -> V_22 ) )
return ( 0 ) ;
if ( ( V_74 -> V_8 & V_26 ) || ( V_75 -> V_8 & V_26 ) )
return 0 ;
return ( F_51 ( V_74 , V_75 ) ) ;
}
void
F_55 ( struct V_33 * V_34 , struct V_1 * V_2 )
{
struct V_1 * V_76 ;
F_3 () ;
for ( V_76 = F_27 ( V_34 ) -> V_77 ; V_76 ; V_76 = V_76 -> V_66 ) {
if ( ! F_41 ( V_76 ) )
continue;
if ( F_52 ( V_2 , V_76 ) )
break;
}
if ( V_76 ) {
F_20 ( V_2 , V_76 ) ;
if ( V_76 -> V_72 )
V_2 -> V_21 = F_56 ( V_76 -> V_72 ) ;
} else
V_2 -> V_8 = V_6 ;
F_5 () ;
return;
}
static struct V_1 * F_57 ( struct V_1 * V_78 )
{
struct V_1 * V_2 ;
F_58 (fl, &blocked_list, fl_link) {
if ( F_35 ( V_2 , V_78 ) )
return V_2 -> V_66 ;
}
return NULL ;
}
static int F_59 ( struct V_1 * V_74 ,
struct V_1 * V_78 )
{
int V_79 = 0 ;
while ( ( V_78 = F_57 ( V_78 ) ) ) {
if ( V_79 ++ > V_80 )
return 0 ;
if ( F_35 ( V_74 , V_78 ) )
return 1 ;
}
return 0 ;
}
static int F_60 ( struct V_33 * V_34 , struct V_1 * V_81 )
{
struct V_1 * V_82 = NULL ;
struct V_1 * * V_83 ;
struct V_84 * V_84 = F_27 ( V_34 ) ;
int error = 0 ;
int V_85 = 0 ;
if ( ! ( V_81 -> V_3 & V_86 ) && ( V_81 -> V_8 != V_6 ) ) {
V_82 = F_10 () ;
if ( ! V_82 )
return - V_36 ;
}
F_3 () ;
if ( V_81 -> V_3 & V_86 )
goto V_87;
F_61 (inode, before) {
struct V_1 * V_2 = * V_83 ;
if ( F_41 ( V_2 ) )
break;
if ( F_62 ( V_2 ) )
continue;
if ( V_34 != V_2 -> V_22 )
continue;
if ( V_81 -> V_8 == V_2 -> V_8 )
goto V_88;
V_85 = 1 ;
F_49 ( V_83 ) ;
break;
}
if ( V_81 -> V_8 == V_6 ) {
if ( ( V_81 -> V_3 & V_89 ) && ! V_85 )
error = - V_90 ;
goto V_88;
}
if ( V_85 ) {
F_5 () ;
F_63 () ;
F_3 () ;
}
V_87:
F_61 (inode, before) {
struct V_1 * V_2 = * V_83 ;
if ( F_41 ( V_2 ) )
break;
if ( F_62 ( V_2 ) )
continue;
if ( ! F_53 ( V_81 , V_2 ) )
continue;
error = - V_91 ;
if ( ! ( V_81 -> V_3 & V_92 ) )
goto V_88;
error = V_93 ;
F_39 ( V_2 , V_81 ) ;
goto V_88;
}
if ( V_81 -> V_3 & V_86 )
goto V_88;
F_21 ( V_82 , V_81 ) ;
F_46 ( V_83 , V_82 ) ;
V_82 = NULL ;
error = 0 ;
V_88:
F_5 () ;
if ( V_82 )
F_13 ( V_82 ) ;
return error ;
}
static int F_64 ( struct V_84 * V_84 , struct V_1 * V_81 , struct V_1 * V_94 )
{
struct V_1 * V_2 ;
struct V_1 * V_82 = NULL ;
struct V_1 * V_95 = NULL ;
struct V_1 * V_96 = NULL ;
struct V_1 * V_97 = NULL ;
struct V_1 * * V_83 ;
int error , V_98 = 0 ;
if ( ! ( V_81 -> V_3 & V_86 ) &&
( V_81 -> V_8 != V_6 ||
V_81 -> V_23 != 0 || V_81 -> V_24 != V_40 ) ) {
V_82 = F_10 () ;
V_95 = F_10 () ;
}
F_3 () ;
if ( V_81 -> V_8 != V_6 ) {
F_61 (inode, before) {
V_2 = * V_83 ;
if ( ! F_41 ( V_2 ) )
continue;
if ( ! F_52 ( V_81 , V_2 ) )
continue;
if ( V_94 )
F_20 ( V_94 , V_2 ) ;
error = - V_91 ;
if ( ! ( V_81 -> V_3 & V_92 ) )
goto V_88;
error = - V_99 ;
if ( F_59 ( V_81 , V_2 ) )
goto V_88;
error = V_93 ;
F_39 ( V_2 , V_81 ) ;
goto V_88;
}
}
error = 0 ;
if ( V_81 -> V_3 & V_86 )
goto V_88;
V_83 = & V_84 -> V_77 ;
while ( ( V_2 = * V_83 ) && ( ! F_41 ( V_2 ) ||
! F_35 ( V_81 , V_2 ) ) ) {
V_83 = & V_2 -> V_66 ;
}
while ( ( V_2 = * V_83 ) && F_35 ( V_81 , V_2 ) ) {
if ( V_81 -> V_8 == V_2 -> V_8 ) {
if ( V_2 -> V_24 < V_81 -> V_23 - 1 )
goto V_100;
if ( V_2 -> V_23 - 1 > V_81 -> V_24 )
break;
if ( V_2 -> V_23 > V_81 -> V_23 )
V_2 -> V_23 = V_81 -> V_23 ;
else
V_81 -> V_23 = V_2 -> V_23 ;
if ( V_2 -> V_24 < V_81 -> V_24 )
V_2 -> V_24 = V_81 -> V_24 ;
else
V_81 -> V_24 = V_2 -> V_24 ;
if ( V_98 ) {
F_49 ( V_83 ) ;
continue;
}
V_81 = V_2 ;
V_98 = 1 ;
}
else {
if ( V_2 -> V_24 < V_81 -> V_23 )
goto V_100;
if ( V_2 -> V_23 > V_81 -> V_24 )
break;
if ( V_81 -> V_8 == V_6 )
V_98 = 1 ;
if ( V_2 -> V_23 < V_81 -> V_23 )
V_96 = V_2 ;
if ( V_2 -> V_24 > V_81 -> V_24 ) {
V_97 = V_2 ;
break;
}
if ( V_2 -> V_23 >= V_81 -> V_23 ) {
if ( V_98 ) {
F_49 ( V_83 ) ;
continue;
}
F_43 ( V_2 ) ;
V_2 -> V_23 = V_81 -> V_23 ;
V_2 -> V_24 = V_81 -> V_24 ;
V_2 -> V_8 = V_81 -> V_8 ;
F_12 ( V_2 ) ;
F_19 ( V_2 , V_81 ) ;
V_81 = V_2 ;
V_98 = 1 ;
}
}
V_100:
V_83 = & V_2 -> V_66 ;
}
error = - V_101 ;
if ( V_97 && V_96 == V_97 && ! V_95 )
goto V_88;
error = 0 ;
if ( ! V_98 ) {
if ( V_81 -> V_8 == V_6 ) {
if ( V_81 -> V_3 & V_89 )
error = - V_90 ;
goto V_88;
}
if ( ! V_82 ) {
error = - V_101 ;
goto V_88;
}
F_21 ( V_82 , V_81 ) ;
F_46 ( V_83 , V_82 ) ;
V_82 = NULL ;
}
if ( V_97 ) {
if ( V_96 == V_97 ) {
V_96 = V_95 ;
V_95 = NULL ;
F_21 ( V_96 , V_97 ) ;
F_46 ( V_83 , V_96 ) ;
}
V_97 -> V_23 = V_81 -> V_24 + 1 ;
F_43 ( V_97 ) ;
}
if ( V_96 ) {
V_96 -> V_24 = V_81 -> V_23 - 1 ;
F_43 ( V_96 ) ;
}
V_88:
F_5 () ;
if ( V_82 )
F_13 ( V_82 ) ;
if ( V_95 )
F_13 ( V_95 ) ;
return error ;
}
int F_65 ( struct V_33 * V_34 , struct V_1 * V_2 ,
struct V_1 * V_94 )
{
return F_64 ( F_27 ( V_34 ) , V_2 , V_94 ) ;
}
int F_66 ( struct V_33 * V_34 , struct V_1 * V_2 )
{
int error ;
F_67 () ;
for (; ; ) {
error = F_65 ( V_34 , V_2 , NULL ) ;
if ( error != V_93 )
break;
error = F_68 ( V_2 -> V_12 , ! V_2 -> V_66 ) ;
if ( ! error )
continue;
F_38 ( V_2 ) ;
break;
}
return error ;
}
int F_69 ( struct V_84 * V_84 )
{
T_3 V_102 = V_37 -> V_53 ;
struct V_1 * V_2 ;
F_3 () ;
for ( V_2 = V_84 -> V_77 ; V_2 != NULL ; V_2 = V_2 -> V_66 ) {
if ( ! F_41 ( V_2 ) )
continue;
if ( V_2 -> V_20 != V_102 )
break;
}
F_5 () ;
return V_2 ? - V_91 : 0 ;
}
int F_70 ( int V_103 , struct V_84 * V_84 ,
struct V_33 * V_34 , T_2 V_104 ,
T_4 V_105 )
{
struct V_1 V_2 ;
int error ;
F_18 ( & V_2 ) ;
V_2 . V_20 = V_37 -> V_53 ;
V_2 . V_21 = V_37 -> V_38 ;
V_2 . V_22 = V_34 ;
V_2 . V_3 = V_54 | V_86 ;
if ( V_34 && ! ( V_34 -> V_106 & V_107 ) )
V_2 . V_3 |= V_92 ;
V_2 . V_8 = ( V_103 == V_108 ) ? V_30 : V_7 ;
V_2 . V_23 = V_104 ;
V_2 . V_24 = V_104 + V_105 - 1 ;
for (; ; ) {
error = F_64 ( V_84 , & V_2 , NULL ) ;
if ( error != V_93 )
break;
error = F_68 ( V_2 . V_12 , ! V_2 . V_66 ) ;
if ( ! error ) {
if ( F_71 ( V_84 ) )
continue;
}
F_38 ( & V_2 ) ;
break;
}
return error ;
}
static void F_72 ( struct V_1 * V_2 , int V_109 )
{
switch ( V_109 ) {
case V_6 :
V_2 -> V_3 &= ~ V_4 ;
case V_7 :
V_2 -> V_3 &= ~ V_5 ;
}
}
int F_73 ( struct V_1 * * V_83 , int V_109 )
{
struct V_1 * V_2 = * V_83 ;
int error = F_24 ( V_2 , V_109 ) ;
if ( error )
return error ;
F_72 ( V_2 , V_109 ) ;
F_43 ( V_2 ) ;
if ( V_109 == V_6 ) {
struct V_33 * V_34 = V_2 -> V_22 ;
F_74 ( V_34 ) ;
V_34 -> V_110 . V_111 = 0 ;
F_75 ( 0 , V_2 -> V_22 , 0 , & V_2 -> V_57 ) ;
if ( V_2 -> V_57 != NULL ) {
F_76 ( V_112 L_1 , V_2 -> V_57 ) ;
V_2 -> V_57 = NULL ;
}
F_49 ( V_83 ) ;
}
return 0 ;
}
static bool F_77 ( unsigned long V_113 )
{
if ( ! V_113 )
return false ;
return F_78 ( V_114 , V_113 ) ;
}
static void F_79 ( struct V_84 * V_84 )
{
struct V_1 * * V_83 ;
struct V_1 * V_2 ;
V_83 = & V_84 -> V_77 ;
while ( ( V_2 = * V_83 ) && F_62 ( V_2 ) && F_1 ( V_2 ) ) {
if ( F_77 ( V_2 -> V_115 ) )
F_73 ( V_83 , V_7 ) ;
if ( F_77 ( V_2 -> V_116 ) )
F_73 ( V_83 , V_6 ) ;
if ( V_2 == * V_83 )
V_83 = & V_2 -> V_66 ;
}
}
int F_80 ( struct V_84 * V_84 , unsigned int V_117 )
{
int error = 0 ;
struct V_1 * V_82 , * V_41 ;
struct V_1 * V_2 ;
unsigned long V_118 ;
int V_119 = 0 ;
int V_120 = ( V_117 & V_121 ) != V_122 ;
V_82 = F_32 ( NULL , V_120 ? V_30 : V_7 ) ;
if ( F_81 ( V_82 ) )
return F_82 ( V_82 ) ;
F_3 () ;
F_79 ( V_84 ) ;
V_41 = V_84 -> V_77 ;
if ( ( V_41 == NULL ) || ! F_62 ( V_41 ) )
goto V_88;
if ( ! F_51 ( V_41 , V_82 ) )
goto V_88;
for ( V_2 = V_41 ; V_2 && F_62 ( V_2 ) ; V_2 = V_2 -> V_66 )
if ( V_2 -> V_20 == V_37 -> V_53 )
V_119 = 1 ;
V_118 = 0 ;
if ( V_123 > 0 ) {
V_118 = V_114 + V_123 * V_124 ;
if ( V_118 == 0 )
V_118 ++ ;
}
for ( V_2 = V_41 ; V_2 && F_62 ( V_2 ) ; V_2 = V_2 -> V_66 ) {
if ( V_120 ) {
if ( V_2 -> V_3 & V_4 )
continue;
V_2 -> V_3 |= V_4 ;
V_2 -> V_116 = V_118 ;
} else {
if ( F_1 ( V_41 ) )
continue;
V_2 -> V_3 |= V_5 ;
V_2 -> V_115 = V_118 ;
}
V_2 -> V_17 -> V_125 ( V_2 ) ;
}
if ( V_119 || ( V_117 & V_107 ) ) {
error = - V_126 ;
goto V_88;
}
V_127:
V_118 = V_41 -> V_116 ;
if ( V_118 != 0 ) {
V_118 -= V_114 ;
if ( V_118 == 0 )
V_118 ++ ;
}
F_39 ( V_41 , V_82 ) ;
F_5 () ;
error = F_83 ( V_82 -> V_12 ,
! V_82 -> V_66 , V_118 ) ;
F_3 () ;
F_36 ( V_82 ) ;
if ( error >= 0 ) {
if ( error == 0 )
F_79 ( V_84 ) ;
for ( V_41 = V_84 -> V_77 ; V_41 && F_62 ( V_41 ) ;
V_41 = V_41 -> V_66 ) {
if ( F_51 ( V_82 , V_41 ) )
goto V_127;
}
error = 0 ;
}
V_88:
F_5 () ;
F_13 ( V_82 ) ;
return error ;
}
void F_84 ( struct V_84 * V_84 , struct V_128 * time )
{
struct V_1 * V_41 = V_84 -> V_77 ;
if ( V_41 && F_62 ( V_41 ) && ( V_41 -> V_8 == V_30 ) )
* time = F_85 ( V_84 -> V_129 ) ;
else
* time = V_84 -> V_130 ;
}
int F_86 ( struct V_33 * V_34 )
{
struct V_1 * V_2 ;
int type = V_6 ;
F_3 () ;
F_79 ( F_27 ( V_34 ) ) ;
for ( V_2 = F_27 ( V_34 ) -> V_77 ; V_2 && F_62 ( V_2 ) ;
V_2 = V_2 -> V_66 ) {
if ( V_2 -> V_22 == V_34 ) {
type = F_2 ( V_2 ) ;
break;
}
}
F_5 () ;
return type ;
}
int F_87 ( struct V_33 * V_34 , long V_109 , struct V_1 * * V_131 )
{
struct V_1 * V_2 , * * V_83 , * * V_132 = NULL , * V_133 ;
struct V_134 * V_134 = V_34 -> V_135 . V_134 ;
struct V_84 * V_84 = V_134 -> V_136 ;
int error ;
V_133 = * V_131 ;
error = - V_91 ;
if ( ( V_109 == V_7 ) && ( F_88 ( & V_84 -> V_137 ) > 0 ) )
goto V_88;
if ( ( V_109 == V_30 )
&& ( ( V_134 -> V_138 > 1 )
|| ( F_88 ( & V_84 -> V_139 ) > 1 ) ) )
goto V_88;
error = - V_91 ;
for ( V_83 = & V_84 -> V_77 ;
( ( V_2 = * V_83 ) != NULL ) && F_62 ( V_2 ) ;
V_83 = & V_2 -> V_66 ) {
if ( V_2 -> V_22 == V_34 ) {
V_132 = V_83 ;
continue;
}
if ( V_109 == V_30 )
goto V_88;
if ( V_2 -> V_3 & V_4 )
goto V_88;
}
if ( V_132 != NULL ) {
error = V_133 -> V_17 -> V_140 ( V_132 , V_109 ) ;
if ( ! error )
* V_131 = * V_132 ;
goto V_88;
}
error = - V_32 ;
if ( ! V_141 )
goto V_88;
F_46 ( V_83 , V_133 ) ;
return 0 ;
V_88:
return error ;
}
int F_89 ( struct V_33 * V_34 , struct V_1 * * V_131 )
{
struct V_1 * V_2 , * * V_83 ;
struct V_134 * V_134 = V_34 -> V_135 . V_134 ;
struct V_84 * V_84 = V_134 -> V_136 ;
for ( V_83 = & V_84 -> V_77 ;
( ( V_2 = * V_83 ) != NULL ) && F_62 ( V_2 ) ;
V_83 = & V_2 -> V_66 ) {
if ( V_2 -> V_22 != V_34 )
continue;
return ( * V_131 ) -> V_17 -> V_140 ( V_83 , V_6 ) ;
}
return - V_91 ;
}
int F_90 ( struct V_33 * V_34 , long V_109 , struct V_1 * * V_131 )
{
struct V_134 * V_134 = V_34 -> V_135 . V_134 ;
struct V_84 * V_84 = V_134 -> V_136 ;
int error ;
if ( ( ! F_91 ( F_92 () , V_84 -> V_142 ) ) && ! F_93 ( V_143 ) )
return - V_144 ;
if ( ! F_94 ( V_84 -> V_145 ) )
return - V_32 ;
error = F_95 ( V_34 , V_109 ) ;
if ( error )
return error ;
F_79 ( V_84 ) ;
F_14 ( ! ( * V_131 ) -> V_17 -> V_125 ) ;
switch ( V_109 ) {
case V_6 :
return F_89 ( V_34 , V_131 ) ;
case V_7 :
case V_30 :
return F_87 ( V_34 , V_109 , V_131 ) ;
default:
return - V_32 ;
}
}
static int F_96 ( struct V_33 * V_34 , long V_109 , struct V_1 * * V_133 )
{
if ( V_34 -> V_146 && V_34 -> V_146 -> V_147 )
return V_34 -> V_146 -> V_147 ( V_34 , V_109 , V_133 ) ;
else
return F_90 ( V_34 , V_109 , V_133 ) ;
}
int F_97 ( struct V_33 * V_34 , long V_109 , struct V_1 * * V_133 )
{
int error ;
F_3 () ;
error = F_96 ( V_34 , V_109 , V_133 ) ;
F_5 () ;
return error ;
}
static int F_98 ( struct V_33 * V_34 )
{
struct V_1 V_2 , * V_131 = & V_2 ;
F_31 ( V_34 , V_6 , V_131 ) ;
return F_97 ( V_34 , V_6 , & V_131 ) ;
}
static int F_99 ( unsigned int V_148 , struct V_33 * V_34 , long V_109 )
{
struct V_1 * V_2 , * V_149 ;
struct V_150 * V_18 ;
int error ;
V_2 = F_32 ( V_34 , V_109 ) ;
if ( F_81 ( V_2 ) )
return F_82 ( V_2 ) ;
V_18 = F_100 () ;
if ( ! V_18 ) {
F_13 ( V_2 ) ;
return - V_36 ;
}
V_149 = V_2 ;
F_3 () ;
error = F_96 ( V_34 , V_109 , & V_149 ) ;
if ( error ) {
F_5 () ;
F_13 ( V_2 ) ;
goto V_151;
}
if ( V_149 != V_2 )
F_13 ( V_2 ) ;
if ( ! F_101 ( V_148 , V_34 , & V_149 -> V_57 , V_18 ) )
V_18 = NULL ;
error = F_102 ( V_34 , F_103 ( V_37 ) , V_152 , 0 ) ;
F_5 () ;
V_151:
if ( V_18 )
F_104 ( V_18 ) ;
return error ;
}
int F_105 ( unsigned int V_148 , struct V_33 * V_34 , long V_109 )
{
if ( V_109 == V_6 )
return F_98 ( V_34 ) ;
return F_99 ( V_148 , V_34 , V_109 ) ;
}
int F_106 ( struct V_33 * V_34 , struct V_1 * V_2 )
{
int error ;
F_67 () ;
for (; ; ) {
error = F_60 ( V_34 , V_2 ) ;
if ( error != V_93 )
break;
error = F_68 ( V_2 -> V_12 , ! V_2 -> V_66 ) ;
if ( ! error )
continue;
F_38 ( V_2 ) ;
break;
}
return error ;
}
int F_107 ( struct V_33 * V_34 , struct V_1 * V_2 )
{
if ( V_34 -> V_146 && V_34 -> V_146 -> V_35 )
return V_34 -> V_146 -> V_35 ( V_34 , V_153 , V_2 ) ;
F_55 ( V_34 , V_2 ) ;
return 0 ;
}
static int F_108 ( struct V_41 * V_41 , struct V_1 * V_2 )
{
V_41 -> V_154 = V_2 -> V_21 ;
#if V_155 == 32
if ( V_2 -> V_23 > V_156 )
return - V_52 ;
if ( V_2 -> V_24 != V_40 && V_2 -> V_24 > V_156 )
return - V_52 ;
#endif
V_41 -> V_50 = V_2 -> V_23 ;
V_41 -> V_51 = V_2 -> V_24 == V_40 ? 0 :
V_2 -> V_24 - V_2 -> V_23 + 1 ;
V_41 -> V_45 = 0 ;
V_41 -> V_55 = V_2 -> V_8 ;
return 0 ;
}
static void F_109 ( struct V_56 * V_41 , struct V_1 * V_2 )
{
V_41 -> V_154 = V_2 -> V_21 ;
V_41 -> V_50 = V_2 -> V_23 ;
V_41 -> V_51 = V_2 -> V_24 == V_40 ? 0 :
V_2 -> V_24 - V_2 -> V_23 + 1 ;
V_41 -> V_45 = 0 ;
V_41 -> V_55 = V_2 -> V_8 ;
}
int F_110 ( struct V_33 * V_34 , struct V_41 T_5 * V_42 )
{
struct V_1 V_1 ;
struct V_41 V_41 ;
int error ;
error = - V_157 ;
if ( F_111 ( & V_41 , V_42 , sizeof( V_41 ) ) )
goto V_88;
error = - V_32 ;
if ( ( V_41 . V_55 != V_7 ) && ( V_41 . V_55 != V_30 ) )
goto V_88;
error = F_25 ( V_34 , & V_1 , & V_41 ) ;
if ( error )
goto V_88;
error = F_107 ( V_34 , & V_1 ) ;
if ( error )
goto V_88;
V_41 . V_55 = V_1 . V_8 ;
if ( V_1 . V_8 != V_6 ) {
error = F_108 ( & V_41 , & V_1 ) ;
if ( error )
goto V_88;
}
error = - V_157 ;
if ( ! F_112 ( V_42 , & V_41 , sizeof( V_41 ) ) )
error = 0 ;
V_88:
return error ;
}
int F_113 ( struct V_33 * V_34 , unsigned int V_25 , struct V_1 * V_2 , struct V_1 * V_158 )
{
if ( V_34 -> V_146 && V_34 -> V_146 -> V_35 )
return V_34 -> V_146 -> V_35 ( V_34 , V_25 , V_2 ) ;
else
return F_65 ( V_34 , V_2 , V_158 ) ;
}
static int F_114 ( struct V_33 * V_34 , unsigned int V_25 ,
struct V_1 * V_2 )
{
int error ;
error = F_95 ( V_34 , V_2 -> V_8 ) ;
if ( error )
return error ;
for (; ; ) {
error = F_113 ( V_34 , V_25 , V_2 , NULL ) ;
if ( error != V_93 )
break;
error = F_68 ( V_2 -> V_12 , ! V_2 -> V_66 ) ;
if ( ! error )
continue;
F_38 ( V_2 ) ;
break;
}
return error ;
}
int F_115 ( unsigned int V_148 , struct V_33 * V_34 , unsigned int V_25 ,
struct V_41 T_5 * V_42 )
{
struct V_1 * V_1 = F_10 () ;
struct V_41 V_41 ;
struct V_84 * V_84 ;
struct V_33 * V_159 ;
int error ;
if ( V_1 == NULL )
return - V_101 ;
error = - V_157 ;
if ( F_111 ( & V_41 , V_42 , sizeof( V_41 ) ) )
goto V_88;
V_84 = F_27 ( V_34 ) ;
if ( F_116 ( V_84 ) && F_117 ( V_34 -> V_160 ) ) {
error = - V_91 ;
goto V_88;
}
V_161:
error = F_25 ( V_34 , V_1 , & V_41 ) ;
if ( error )
goto V_88;
if ( V_25 == V_162 ) {
V_1 -> V_3 |= V_92 ;
}
error = - V_163 ;
switch ( V_41 . V_55 ) {
case V_7 :
if ( ! ( V_34 -> V_164 & V_165 ) )
goto V_88;
break;
case V_30 :
if ( ! ( V_34 -> V_164 & V_166 ) )
goto V_88;
break;
case V_6 :
break;
default:
error = - V_32 ;
goto V_88;
}
error = F_114 ( V_34 , V_25 , V_1 ) ;
F_4 ( & V_37 -> V_53 -> V_1 ) ;
V_159 = F_118 ( V_148 ) ;
F_6 ( & V_37 -> V_53 -> V_1 ) ;
if ( ! error && V_159 != V_34 && V_41 . V_55 != V_6 ) {
V_41 . V_55 = V_6 ;
goto V_161;
}
V_88:
F_13 ( V_1 ) ;
return error ;
}
int F_119 ( struct V_33 * V_34 , struct V_56 T_5 * V_42 )
{
struct V_1 V_1 ;
struct V_56 V_41 ;
int error ;
error = - V_157 ;
if ( F_111 ( & V_41 , V_42 , sizeof( V_41 ) ) )
goto V_88;
error = - V_32 ;
if ( ( V_41 . V_55 != V_7 ) && ( V_41 . V_55 != V_30 ) )
goto V_88;
error = F_28 ( V_34 , & V_1 , & V_41 ) ;
if ( error )
goto V_88;
error = F_107 ( V_34 , & V_1 ) ;
if ( error )
goto V_88;
V_41 . V_55 = V_1 . V_8 ;
if ( V_1 . V_8 != V_6 )
F_109 ( & V_41 , & V_1 ) ;
error = - V_157 ;
if ( ! F_112 ( V_42 , & V_41 , sizeof( V_41 ) ) )
error = 0 ;
V_88:
return error ;
}
int F_120 ( unsigned int V_148 , struct V_33 * V_34 , unsigned int V_25 ,
struct V_56 T_5 * V_42 )
{
struct V_1 * V_1 = F_10 () ;
struct V_56 V_41 ;
struct V_84 * V_84 ;
struct V_33 * V_159 ;
int error ;
if ( V_1 == NULL )
return - V_101 ;
error = - V_157 ;
if ( F_111 ( & V_41 , V_42 , sizeof( V_41 ) ) )
goto V_88;
V_84 = F_27 ( V_34 ) ;
if ( F_116 ( V_84 ) && F_117 ( V_34 -> V_160 ) ) {
error = - V_91 ;
goto V_88;
}
V_161:
error = F_28 ( V_34 , V_1 , & V_41 ) ;
if ( error )
goto V_88;
if ( V_25 == V_167 ) {
V_1 -> V_3 |= V_92 ;
}
error = - V_163 ;
switch ( V_41 . V_55 ) {
case V_7 :
if ( ! ( V_34 -> V_164 & V_165 ) )
goto V_88;
break;
case V_30 :
if ( ! ( V_34 -> V_164 & V_166 ) )
goto V_88;
break;
case V_6 :
break;
default:
error = - V_32 ;
goto V_88;
}
error = F_114 ( V_34 , V_25 , V_1 ) ;
F_4 ( & V_37 -> V_53 -> V_1 ) ;
V_159 = F_118 ( V_148 ) ;
F_6 ( & V_37 -> V_53 -> V_1 ) ;
if ( ! error && V_159 != V_34 && V_41 . V_55 != V_6 ) {
V_41 . V_55 = V_6 ;
goto V_161;
}
V_88:
F_13 ( V_1 ) ;
return error ;
}
void F_121 ( struct V_33 * V_34 , T_3 V_102 )
{
struct V_1 V_35 ;
if ( ! F_27 ( V_34 ) -> V_77 )
return;
V_35 . V_8 = V_6 ;
V_35 . V_3 = V_54 | V_168 ;
V_35 . V_23 = 0 ;
V_35 . V_24 = V_40 ;
V_35 . V_20 = V_102 ;
V_35 . V_21 = V_37 -> V_38 ;
V_35 . V_22 = V_34 ;
V_35 . V_15 = NULL ;
V_35 . V_17 = NULL ;
F_113 ( V_34 , V_169 , & V_35 , NULL ) ;
if ( V_35 . V_15 && V_35 . V_15 -> V_16 )
V_35 . V_15 -> V_16 ( & V_35 ) ;
}
void F_122 ( struct V_33 * V_34 )
{
struct V_84 * V_84 = F_27 ( V_34 ) ;
struct V_1 * V_2 ;
struct V_1 * * V_83 ;
if ( ! V_84 -> V_77 )
return;
if ( V_34 -> V_146 && V_34 -> V_146 -> V_41 ) {
struct V_1 V_2 = {
. V_21 = V_37 -> V_38 ,
. V_22 = V_34 ,
. V_3 = V_39 ,
. V_8 = V_6 ,
. V_24 = V_40 ,
} ;
V_34 -> V_146 -> V_41 ( V_34 , V_162 , & V_2 ) ;
if ( V_2 . V_15 && V_2 . V_15 -> V_16 )
V_2 . V_15 -> V_16 ( & V_2 ) ;
}
F_3 () ;
V_83 = & V_84 -> V_77 ;
while ( ( V_2 = * V_83 ) != NULL ) {
if ( V_2 -> V_22 == V_34 ) {
if ( F_54 ( V_2 ) ) {
F_49 ( V_83 ) ;
continue;
}
if ( F_62 ( V_2 ) ) {
F_73 ( V_83 , V_6 ) ;
continue;
}
F_123 () ;
}
V_83 = & V_2 -> V_66 ;
}
F_5 () ;
}
int
F_124 ( struct V_33 * V_34 , struct V_1 * V_65 )
{
int V_170 = 0 ;
F_3 () ;
if ( V_65 -> V_66 )
F_36 ( V_65 ) ;
else
V_170 = - V_90 ;
F_5 () ;
return V_170 ;
}
int F_125 ( struct V_33 * V_34 , struct V_1 * V_2 )
{
if ( V_34 -> V_146 && V_34 -> V_146 -> V_35 )
return V_34 -> V_146 -> V_35 ( V_34 , V_171 , V_2 ) ;
return 0 ;
}
static void F_126 ( struct V_172 * V_159 , struct V_1 * V_2 ,
T_2 V_173 , char * V_174 )
{
struct V_84 * V_84 = NULL ;
unsigned int V_21 ;
if ( V_2 -> V_72 )
V_21 = F_56 ( V_2 -> V_72 ) ;
else
V_21 = V_2 -> V_21 ;
if ( V_2 -> V_22 != NULL )
V_84 = F_27 ( V_2 -> V_22 ) ;
F_127 ( V_159 , L_2 , V_173 , V_174 ) ;
if ( F_41 ( V_2 ) ) {
F_127 ( V_159 , L_3 ,
( V_2 -> V_3 & V_86 ) ? L_4 : L_5 ,
( V_84 == NULL ) ? L_6 :
F_116 ( V_84 ) ? L_7 : L_8 ) ;
} else if ( F_54 ( V_2 ) ) {
if ( V_2 -> V_8 & V_26 ) {
F_127 ( V_159 , L_9 ) ;
} else {
F_127 ( V_159 , L_10 ) ;
}
} else if ( F_62 ( V_2 ) ) {
F_127 ( V_159 , L_11 ) ;
if ( F_1 ( V_2 ) )
F_127 ( V_159 , L_12 ) ;
else if ( V_2 -> V_22 )
F_127 ( V_159 , L_13 ) ;
else
F_127 ( V_159 , L_14 ) ;
} else {
F_127 ( V_159 , L_15 ) ;
}
if ( V_2 -> V_8 & V_26 ) {
F_127 ( V_159 , L_16 ,
( V_2 -> V_8 & V_175 )
? ( V_2 -> V_8 & V_176 ) ? L_17 : L_18
: ( V_2 -> V_8 & V_176 ) ? L_19 : L_20 ) ;
} else {
F_127 ( V_159 , L_16 ,
( F_1 ( V_2 ) )
? ( V_2 -> V_8 == V_6 ) ? L_21 : L_18
: ( V_2 -> V_8 == V_30 ) ? L_19 : L_18 ) ;
}
if ( V_84 ) {
#ifdef F_128
F_127 ( V_159 , L_22 , V_21 ,
V_84 -> V_129 -> V_177 , V_84 -> V_178 ) ;
#else
F_127 ( V_159 , L_23 , V_21 ,
F_129 ( V_84 -> V_129 -> V_179 ) ,
F_130 ( V_84 -> V_129 -> V_179 ) , V_84 -> V_178 ) ;
#endif
} else {
F_127 ( V_159 , L_24 , V_21 ) ;
}
if ( F_41 ( V_2 ) ) {
if ( V_2 -> V_24 == V_40 )
F_127 ( V_159 , L_25 , V_2 -> V_23 ) ;
else
F_127 ( V_159 , L_26 , V_2 -> V_23 , V_2 -> V_24 ) ;
} else {
F_127 ( V_159 , L_27 ) ;
}
}
static int F_131 ( struct V_172 * V_159 , void * V_180 )
{
struct V_1 * V_2 , * V_181 ;
V_2 = F_132 ( V_180 , struct V_1 , V_10 ) ;
F_126 ( V_159 , V_2 , * ( ( T_2 * ) V_159 -> V_182 ) , L_28 ) ;
F_58 (bfl, &fl->fl_block, fl_block)
F_126 ( V_159 , V_181 , * ( ( T_2 * ) V_159 -> V_182 ) , L_29 ) ;
return 0 ;
}
static void * F_133 ( struct V_172 * V_159 , T_2 * V_70 )
{
T_2 * V_183 = V_159 -> V_182 ;
F_3 () ;
* V_183 = ( * V_70 + 1 ) ;
return F_134 ( & V_71 , * V_70 ) ;
}
static void * F_135 ( struct V_172 * V_159 , void * V_180 , T_2 * V_70 )
{
T_2 * V_183 = V_159 -> V_182 ;
++ * V_183 ;
return F_136 ( V_180 , & V_71 , V_70 ) ;
}
static void F_137 ( struct V_172 * V_159 , void * V_180 )
{
F_5 () ;
}
static int F_138 ( struct V_84 * V_84 , struct V_33 * V_34 )
{
return F_139 ( V_34 , & V_184 , sizeof( T_2 ) ) ;
}
static int T_6 F_140 ( void )
{
F_141 ( L_30 , 0 , NULL , & V_185 ) ;
return 0 ;
}
int F_142 ( struct V_84 * V_84 , T_2 V_43 , unsigned long V_186 )
{
struct V_1 * V_2 ;
int V_187 = 1 ;
F_3 () ;
for ( V_2 = V_84 -> V_77 ; V_2 != NULL ; V_2 = V_2 -> V_66 ) {
if ( F_41 ( V_2 ) ) {
if ( V_2 -> V_8 == V_7 )
continue;
if ( ( V_2 -> V_24 < V_43 ) || ( V_2 -> V_23 > ( V_43 + V_186 ) ) )
continue;
} else if ( F_54 ( V_2 ) ) {
if ( ! ( V_2 -> V_8 & V_26 ) )
continue;
if ( V_2 -> V_8 & V_175 )
continue;
} else
continue;
V_187 = 0 ;
break;
}
F_5 () ;
return V_187 ;
}
int F_143 ( struct V_84 * V_84 , T_2 V_43 , unsigned long V_186 )
{
struct V_1 * V_2 ;
int V_187 = 1 ;
F_3 () ;
for ( V_2 = V_84 -> V_77 ; V_2 != NULL ; V_2 = V_2 -> V_66 ) {
if ( F_41 ( V_2 ) ) {
if ( ( V_2 -> V_24 < V_43 ) || ( V_2 -> V_23 > ( V_43 + V_186 ) ) )
continue;
} else if ( F_54 ( V_2 ) ) {
if ( ! ( V_2 -> V_8 & V_26 ) )
continue;
if ( V_2 -> V_8 & V_176 )
continue;
} else
continue;
V_187 = 0 ;
break;
}
F_5 () ;
return V_187 ;
}
static int T_6 F_144 ( void )
{
V_13 = F_145 ( L_31 ,
sizeof( struct V_1 ) , 0 , V_188 , NULL ) ;
return 0 ;
}
