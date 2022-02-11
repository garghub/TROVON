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
V_43 = F_26 ( V_34 -> V_50 . V_51 -> V_52 ) ;
break;
default:
return - V_32 ;
}
V_43 += V_42 -> V_53 ;
if ( V_43 < 0 )
return - V_32 ;
V_2 -> V_24 = V_40 ;
if ( V_42 -> V_54 > 0 ) {
V_44 = V_43 + V_42 -> V_54 - 1 ;
V_2 -> V_24 = V_44 ;
} else if ( V_42 -> V_54 < 0 ) {
V_44 = V_43 - 1 ;
V_2 -> V_24 = V_44 ;
V_43 += V_42 -> V_54 ;
if ( V_43 < 0 )
return - V_32 ;
}
V_2 -> V_23 = V_43 ;
if ( V_2 -> V_24 < V_2 -> V_23 )
return - V_55 ;
V_2 -> V_20 = V_37 -> V_56 ;
V_2 -> V_21 = V_37 -> V_38 ;
V_2 -> V_22 = V_34 ;
V_2 -> V_3 = V_57 ;
V_2 -> V_15 = NULL ;
V_2 -> V_17 = NULL ;
return F_24 ( V_2 , V_42 -> V_58 ) ;
}
static int F_27 ( struct V_33 * V_34 , struct V_1 * V_2 ,
struct V_59 * V_42 )
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
V_43 = F_26 ( V_34 -> V_50 . V_51 -> V_52 ) ;
break;
default:
return - V_32 ;
}
V_43 += V_42 -> V_53 ;
if ( V_43 < 0 )
return - V_32 ;
V_2 -> V_24 = V_40 ;
if ( V_42 -> V_54 > 0 ) {
V_2 -> V_24 = V_43 + V_42 -> V_54 - 1 ;
} else if ( V_42 -> V_54 < 0 ) {
V_2 -> V_24 = V_43 - 1 ;
V_43 += V_42 -> V_54 ;
if ( V_43 < 0 )
return - V_32 ;
}
V_2 -> V_23 = V_43 ;
if ( V_2 -> V_24 < V_2 -> V_23 )
return - V_55 ;
V_2 -> V_20 = V_37 -> V_56 ;
V_2 -> V_21 = V_37 -> V_38 ;
V_2 -> V_22 = V_34 ;
V_2 -> V_3 = V_57 ;
V_2 -> V_15 = NULL ;
V_2 -> V_17 = NULL ;
return F_24 ( V_2 , V_42 -> V_58 ) ;
}
static void F_28 ( struct V_1 * V_2 )
{
F_29 ( & V_2 -> V_60 , V_61 , V_62 ) ;
}
static int F_30 ( struct V_33 * V_34 , long type , struct V_1 * V_2 )
{
if ( F_24 ( V_2 , type ) != 0 )
return - V_32 ;
V_2 -> V_20 = V_37 -> V_56 ;
V_2 -> V_21 = V_37 -> V_38 ;
V_2 -> V_22 = V_34 ;
V_2 -> V_3 = V_63 ;
V_2 -> V_23 = 0 ;
V_2 -> V_24 = V_40 ;
V_2 -> V_15 = NULL ;
V_2 -> V_17 = & V_64 ;
return 0 ;
}
static struct V_1 * F_31 ( struct V_33 * V_34 , long type )
{
struct V_1 * V_2 = F_10 () ;
int error = - V_36 ;
if ( V_2 == NULL )
return F_32 ( error ) ;
error = F_30 ( V_34 , type , V_2 ) ;
if ( error ) {
F_13 ( V_2 ) ;
return F_32 ( error ) ;
}
return V_2 ;
}
static inline int F_33 ( struct V_1 * V_65 , struct V_1 * V_66 )
{
return ( ( V_65 -> V_24 >= V_66 -> V_23 ) &&
( V_66 -> V_24 >= V_65 -> V_23 ) ) ;
}
static int F_34 ( struct V_1 * V_65 , struct V_1 * V_66 )
{
if ( V_65 -> V_17 && V_65 -> V_17 -> V_67 )
return V_66 -> V_17 == V_65 -> V_17 &&
V_65 -> V_17 -> V_67 ( V_65 , V_66 ) ;
return V_65 -> V_20 == V_66 -> V_20 ;
}
static void F_35 ( struct V_1 * V_68 )
{
F_36 ( & V_68 -> V_11 ) ;
F_36 ( & V_68 -> V_10 ) ;
V_68 -> V_69 = NULL ;
}
void F_37 ( struct V_1 * V_68 )
{
F_3 () ;
F_35 ( V_68 ) ;
F_5 () ;
}
static void F_38 ( struct V_1 * V_70 ,
struct V_1 * V_68 )
{
F_14 ( ! F_16 ( & V_68 -> V_11 ) ) ;
F_39 ( & V_68 -> V_11 , & V_70 -> V_11 ) ;
V_68 -> V_69 = V_70 ;
if ( F_40 ( V_70 ) )
F_41 ( & V_68 -> V_10 , & V_71 ) ;
}
static void F_42 ( struct V_1 * V_70 )
{
while ( ! F_16 ( & V_70 -> V_11 ) ) {
struct V_1 * V_68 ;
V_68 = F_43 ( & V_70 -> V_11 ,
struct V_1 , V_11 ) ;
F_35 ( V_68 ) ;
if ( V_68 -> V_17 && V_68 -> V_17 -> V_72 )
V_68 -> V_17 -> V_72 ( V_68 ) ;
else
F_44 ( & V_68 -> V_12 ) ;
}
}
static void F_45 ( struct V_1 * * V_73 , struct V_1 * V_2 )
{
F_41 ( & V_2 -> V_10 , & V_74 ) ;
V_2 -> V_75 = F_46 ( F_47 ( V_37 ) ) ;
V_2 -> V_69 = * V_73 ;
* V_73 = V_2 ;
}
static void F_48 ( struct V_1 * * V_76 )
{
struct V_1 * V_2 = * V_76 ;
* V_76 = V_2 -> V_69 ;
V_2 -> V_69 = NULL ;
F_36 ( & V_2 -> V_10 ) ;
if ( V_2 -> V_75 ) {
F_49 ( V_2 -> V_75 ) ;
V_2 -> V_75 = NULL ;
}
F_42 ( V_2 ) ;
F_13 ( V_2 ) ;
}
static int F_50 ( struct V_1 * V_77 , struct V_1 * V_78 )
{
if ( V_78 -> V_8 == V_30 )
return 1 ;
if ( V_77 -> V_8 == V_30 )
return 1 ;
return 0 ;
}
static int F_51 ( struct V_1 * V_77 , struct V_1 * V_78 )
{
if ( ! F_40 ( V_78 ) || F_34 ( V_77 , V_78 ) )
return ( 0 ) ;
if ( ! F_33 ( V_77 , V_78 ) )
return 0 ;
return ( F_50 ( V_77 , V_78 ) ) ;
}
static int F_52 ( struct V_1 * V_77 , struct V_1 * V_78 )
{
if ( ! F_53 ( V_78 ) || ( V_77 -> V_22 == V_78 -> V_22 ) )
return ( 0 ) ;
if ( ( V_77 -> V_8 & V_26 ) || ( V_78 -> V_8 & V_26 ) )
return 0 ;
return ( F_50 ( V_77 , V_78 ) ) ;
}
void
F_54 ( struct V_33 * V_34 , struct V_1 * V_2 )
{
struct V_1 * V_79 ;
F_3 () ;
for ( V_79 = V_34 -> V_50 . V_51 -> V_52 -> V_80 ; V_79 ; V_79 = V_79 -> V_69 ) {
if ( ! F_40 ( V_79 ) )
continue;
if ( F_51 ( V_2 , V_79 ) )
break;
}
if ( V_79 ) {
F_20 ( V_2 , V_79 ) ;
if ( V_79 -> V_75 )
V_2 -> V_21 = F_55 ( V_79 -> V_75 ) ;
} else
V_2 -> V_8 = V_6 ;
F_5 () ;
return;
}
static struct V_1 * F_56 ( struct V_1 * V_81 )
{
struct V_1 * V_2 ;
F_57 (fl, &blocked_list, fl_link) {
if ( F_34 ( V_2 , V_81 ) )
return V_2 -> V_69 ;
}
return NULL ;
}
static int F_58 ( struct V_1 * V_77 ,
struct V_1 * V_81 )
{
int V_82 = 0 ;
while ( ( V_81 = F_56 ( V_81 ) ) ) {
if ( V_82 ++ > V_83 )
return 0 ;
if ( F_34 ( V_77 , V_81 ) )
return 1 ;
}
return 0 ;
}
static int F_59 ( struct V_33 * V_34 , struct V_1 * V_84 )
{
struct V_1 * V_85 = NULL ;
struct V_1 * * V_86 ;
struct V_87 * V_87 = V_34 -> V_50 . V_51 -> V_52 ;
int error = 0 ;
int V_88 = 0 ;
if ( ! ( V_84 -> V_3 & V_89 ) && ( V_84 -> V_8 != V_6 ) ) {
V_85 = F_10 () ;
if ( ! V_85 )
return - V_36 ;
}
F_3 () ;
if ( V_84 -> V_3 & V_89 )
goto V_90;
F_60 (inode, before) {
struct V_1 * V_2 = * V_86 ;
if ( F_40 ( V_2 ) )
break;
if ( F_61 ( V_2 ) )
continue;
if ( V_34 != V_2 -> V_22 )
continue;
if ( V_84 -> V_8 == V_2 -> V_8 )
goto V_91;
V_88 = 1 ;
F_48 ( V_86 ) ;
break;
}
if ( V_84 -> V_8 == V_6 ) {
if ( ( V_84 -> V_3 & V_92 ) && ! V_88 )
error = - V_93 ;
goto V_91;
}
if ( V_88 ) {
F_5 () ;
F_62 () ;
F_3 () ;
}
V_90:
F_60 (inode, before) {
struct V_1 * V_2 = * V_86 ;
if ( F_40 ( V_2 ) )
break;
if ( F_61 ( V_2 ) )
continue;
if ( ! F_52 ( V_84 , V_2 ) )
continue;
error = - V_94 ;
if ( ! ( V_84 -> V_3 & V_95 ) )
goto V_91;
error = V_96 ;
F_38 ( V_2 , V_84 ) ;
goto V_91;
}
if ( V_84 -> V_3 & V_89 )
goto V_91;
F_21 ( V_85 , V_84 ) ;
F_45 ( V_86 , V_85 ) ;
V_85 = NULL ;
error = 0 ;
V_91:
F_5 () ;
if ( V_85 )
F_13 ( V_85 ) ;
return error ;
}
static int F_63 ( struct V_87 * V_87 , struct V_1 * V_84 , struct V_1 * V_97 )
{
struct V_1 * V_2 ;
struct V_1 * V_85 = NULL ;
struct V_1 * V_98 = NULL ;
struct V_1 * V_99 = NULL ;
struct V_1 * V_100 = NULL ;
struct V_1 * * V_86 ;
int error , V_101 = 0 ;
if ( ! ( V_84 -> V_3 & V_89 ) &&
( V_84 -> V_8 != V_6 ||
V_84 -> V_23 != 0 || V_84 -> V_24 != V_40 ) ) {
V_85 = F_10 () ;
V_98 = F_10 () ;
}
F_3 () ;
if ( V_84 -> V_8 != V_6 ) {
F_60 (inode, before) {
V_2 = * V_86 ;
if ( ! F_40 ( V_2 ) )
continue;
if ( ! F_51 ( V_84 , V_2 ) )
continue;
if ( V_97 )
F_20 ( V_97 , V_2 ) ;
error = - V_94 ;
if ( ! ( V_84 -> V_3 & V_95 ) )
goto V_91;
error = - V_102 ;
if ( F_58 ( V_84 , V_2 ) )
goto V_91;
error = V_96 ;
F_38 ( V_2 , V_84 ) ;
goto V_91;
}
}
error = 0 ;
if ( V_84 -> V_3 & V_89 )
goto V_91;
V_86 = & V_87 -> V_80 ;
while ( ( V_2 = * V_86 ) && ( ! F_40 ( V_2 ) ||
! F_34 ( V_84 , V_2 ) ) ) {
V_86 = & V_2 -> V_69 ;
}
while ( ( V_2 = * V_86 ) && F_34 ( V_84 , V_2 ) ) {
if ( V_84 -> V_8 == V_2 -> V_8 ) {
if ( V_2 -> V_24 < V_84 -> V_23 - 1 )
goto V_103;
if ( V_2 -> V_23 - 1 > V_84 -> V_24 )
break;
if ( V_2 -> V_23 > V_84 -> V_23 )
V_2 -> V_23 = V_84 -> V_23 ;
else
V_84 -> V_23 = V_2 -> V_23 ;
if ( V_2 -> V_24 < V_84 -> V_24 )
V_2 -> V_24 = V_84 -> V_24 ;
else
V_84 -> V_24 = V_2 -> V_24 ;
if ( V_101 ) {
F_48 ( V_86 ) ;
continue;
}
V_84 = V_2 ;
V_101 = 1 ;
}
else {
if ( V_2 -> V_24 < V_84 -> V_23 )
goto V_103;
if ( V_2 -> V_23 > V_84 -> V_24 )
break;
if ( V_84 -> V_8 == V_6 )
V_101 = 1 ;
if ( V_2 -> V_23 < V_84 -> V_23 )
V_99 = V_2 ;
if ( V_2 -> V_24 > V_84 -> V_24 ) {
V_100 = V_2 ;
break;
}
if ( V_2 -> V_23 >= V_84 -> V_23 ) {
if ( V_101 ) {
F_48 ( V_86 ) ;
continue;
}
F_42 ( V_2 ) ;
V_2 -> V_23 = V_84 -> V_23 ;
V_2 -> V_24 = V_84 -> V_24 ;
V_2 -> V_8 = V_84 -> V_8 ;
F_12 ( V_2 ) ;
F_19 ( V_2 , V_84 ) ;
V_84 = V_2 ;
V_101 = 1 ;
}
}
V_103:
V_86 = & V_2 -> V_69 ;
}
error = - V_104 ;
if ( V_100 && V_99 == V_100 && ! V_98 )
goto V_91;
error = 0 ;
if ( ! V_101 ) {
if ( V_84 -> V_8 == V_6 ) {
if ( V_84 -> V_3 & V_92 )
error = - V_93 ;
goto V_91;
}
if ( ! V_85 ) {
error = - V_104 ;
goto V_91;
}
F_21 ( V_85 , V_84 ) ;
F_45 ( V_86 , V_85 ) ;
V_85 = NULL ;
}
if ( V_100 ) {
if ( V_99 == V_100 ) {
V_99 = V_98 ;
V_98 = NULL ;
F_21 ( V_99 , V_100 ) ;
F_45 ( V_86 , V_99 ) ;
}
V_100 -> V_23 = V_84 -> V_24 + 1 ;
F_42 ( V_100 ) ;
}
if ( V_99 ) {
V_99 -> V_24 = V_84 -> V_23 - 1 ;
F_42 ( V_99 ) ;
}
V_91:
F_5 () ;
if ( V_85 )
F_13 ( V_85 ) ;
if ( V_98 )
F_13 ( V_98 ) ;
return error ;
}
int F_64 ( struct V_33 * V_34 , struct V_1 * V_2 ,
struct V_1 * V_97 )
{
return F_63 ( V_34 -> V_50 . V_51 -> V_52 , V_2 , V_97 ) ;
}
int F_65 ( struct V_33 * V_34 , struct V_1 * V_2 )
{
int error ;
F_66 () ;
for (; ; ) {
error = F_64 ( V_34 , V_2 , NULL ) ;
if ( error != V_96 )
break;
error = F_67 ( V_2 -> V_12 , ! V_2 -> V_69 ) ;
if ( ! error )
continue;
F_37 ( V_2 ) ;
break;
}
return error ;
}
int F_68 ( struct V_87 * V_87 )
{
T_3 V_105 = V_37 -> V_56 ;
struct V_1 * V_2 ;
F_3 () ;
for ( V_2 = V_87 -> V_80 ; V_2 != NULL ; V_2 = V_2 -> V_69 ) {
if ( ! F_40 ( V_2 ) )
continue;
if ( V_2 -> V_20 != V_105 )
break;
}
F_5 () ;
return V_2 ? - V_94 : 0 ;
}
int F_69 ( int V_106 , struct V_87 * V_87 ,
struct V_33 * V_34 , T_2 V_107 ,
T_4 V_108 )
{
struct V_1 V_2 ;
int error ;
F_18 ( & V_2 ) ;
V_2 . V_20 = V_37 -> V_56 ;
V_2 . V_21 = V_37 -> V_38 ;
V_2 . V_22 = V_34 ;
V_2 . V_3 = V_57 | V_89 ;
if ( V_34 && ! ( V_34 -> V_109 & V_110 ) )
V_2 . V_3 |= V_95 ;
V_2 . V_8 = ( V_106 == V_111 ) ? V_30 : V_7 ;
V_2 . V_23 = V_107 ;
V_2 . V_24 = V_107 + V_108 - 1 ;
for (; ; ) {
error = F_63 ( V_87 , & V_2 , NULL ) ;
if ( error != V_96 )
break;
error = F_67 ( V_2 . V_12 , ! V_2 . V_69 ) ;
if ( ! error ) {
if ( F_70 ( V_87 ) )
continue;
}
F_37 ( & V_2 ) ;
break;
}
return error ;
}
static void F_71 ( struct V_1 * V_2 , int V_112 )
{
switch ( V_112 ) {
case V_6 :
V_2 -> V_3 &= ~ V_4 ;
case V_7 :
V_2 -> V_3 &= ~ V_5 ;
}
}
int F_72 ( struct V_1 * * V_86 , int V_112 )
{
struct V_1 * V_2 = * V_86 ;
int error = F_24 ( V_2 , V_112 ) ;
if ( error )
return error ;
F_71 ( V_2 , V_112 ) ;
F_42 ( V_2 ) ;
if ( V_112 == V_6 ) {
struct V_33 * V_34 = V_2 -> V_22 ;
F_73 ( V_34 ) ;
V_34 -> V_113 . V_114 = 0 ;
F_74 ( 0 , V_2 -> V_22 , 0 , & V_2 -> V_60 ) ;
if ( V_2 -> V_60 != NULL ) {
F_75 ( V_115 L_1 , V_2 -> V_60 ) ;
V_2 -> V_60 = NULL ;
}
F_48 ( V_86 ) ;
}
return 0 ;
}
static bool F_76 ( unsigned long V_116 )
{
if ( ! V_116 )
return false ;
return F_77 ( V_117 , V_116 ) ;
}
static void F_78 ( struct V_87 * V_87 )
{
struct V_1 * * V_86 ;
struct V_1 * V_2 ;
V_86 = & V_87 -> V_80 ;
while ( ( V_2 = * V_86 ) && F_61 ( V_2 ) && F_1 ( V_2 ) ) {
if ( F_76 ( V_2 -> V_118 ) )
F_72 ( V_86 , V_7 ) ;
if ( F_76 ( V_2 -> V_119 ) )
F_72 ( V_86 , V_6 ) ;
if ( V_2 == * V_86 )
V_86 = & V_2 -> V_69 ;
}
}
int F_79 ( struct V_87 * V_87 , unsigned int V_120 )
{
int error = 0 ;
struct V_1 * V_85 , * V_41 ;
struct V_1 * V_2 ;
unsigned long V_121 ;
int V_122 = 0 ;
int V_123 = ( V_120 & V_124 ) != V_125 ;
V_85 = F_31 ( NULL , V_123 ? V_30 : V_7 ) ;
if ( F_80 ( V_85 ) )
return F_81 ( V_85 ) ;
F_3 () ;
F_78 ( V_87 ) ;
V_41 = V_87 -> V_80 ;
if ( ( V_41 == NULL ) || ! F_61 ( V_41 ) )
goto V_91;
if ( ! F_50 ( V_41 , V_85 ) )
goto V_91;
for ( V_2 = V_41 ; V_2 && F_61 ( V_2 ) ; V_2 = V_2 -> V_69 )
if ( V_2 -> V_20 == V_37 -> V_56 )
V_122 = 1 ;
V_121 = 0 ;
if ( V_126 > 0 ) {
V_121 = V_117 + V_126 * V_127 ;
if ( V_121 == 0 )
V_121 ++ ;
}
for ( V_2 = V_41 ; V_2 && F_61 ( V_2 ) ; V_2 = V_2 -> V_69 ) {
if ( V_123 ) {
if ( V_2 -> V_3 & V_4 )
continue;
V_2 -> V_3 |= V_4 ;
V_2 -> V_119 = V_121 ;
} else {
if ( F_1 ( V_41 ) )
continue;
V_2 -> V_3 |= V_5 ;
V_2 -> V_118 = V_121 ;
}
V_2 -> V_17 -> V_128 ( V_2 ) ;
}
if ( V_122 || ( V_120 & V_110 ) ) {
error = - V_129 ;
goto V_91;
}
V_130:
V_121 = V_41 -> V_119 ;
if ( V_121 != 0 ) {
V_121 -= V_117 ;
if ( V_121 == 0 )
V_121 ++ ;
}
F_38 ( V_41 , V_85 ) ;
F_5 () ;
error = F_82 ( V_85 -> V_12 ,
! V_85 -> V_69 , V_121 ) ;
F_3 () ;
F_35 ( V_85 ) ;
if ( error >= 0 ) {
if ( error == 0 )
F_78 ( V_87 ) ;
for ( V_41 = V_87 -> V_80 ; V_41 && F_61 ( V_41 ) ;
V_41 = V_41 -> V_69 ) {
if ( F_50 ( V_85 , V_41 ) )
goto V_130;
}
error = 0 ;
}
V_91:
F_5 () ;
F_13 ( V_85 ) ;
return error ;
}
void F_83 ( struct V_87 * V_87 , struct V_131 * time )
{
struct V_1 * V_41 = V_87 -> V_80 ;
if ( V_41 && F_61 ( V_41 ) && ( V_41 -> V_8 == V_30 ) )
* time = F_84 ( V_87 -> V_132 ) ;
else
* time = V_87 -> V_133 ;
}
int F_85 ( struct V_33 * V_34 )
{
struct V_1 * V_2 ;
int type = V_6 ;
F_3 () ;
F_78 ( V_34 -> V_50 . V_51 -> V_52 ) ;
for ( V_2 = V_34 -> V_50 . V_51 -> V_52 -> V_80 ; V_2 && F_61 ( V_2 ) ;
V_2 = V_2 -> V_69 ) {
if ( V_2 -> V_22 == V_34 ) {
type = F_2 ( V_2 ) ;
break;
}
}
F_5 () ;
return type ;
}
int F_86 ( struct V_33 * V_34 , long V_112 , struct V_1 * * V_134 )
{
struct V_1 * V_2 , * * V_86 , * * V_135 = NULL , * V_136 ;
struct V_51 * V_51 = V_34 -> V_50 . V_51 ;
struct V_87 * V_87 = V_51 -> V_52 ;
int error ;
V_136 = * V_134 ;
error = - V_94 ;
if ( ( V_112 == V_7 ) && ( F_87 ( & V_87 -> V_137 ) > 0 ) )
goto V_91;
if ( ( V_112 == V_30 )
&& ( ( V_51 -> V_138 > 1 )
|| ( F_87 ( & V_87 -> V_139 ) > 1 ) ) )
goto V_91;
error = - V_94 ;
for ( V_86 = & V_87 -> V_80 ;
( ( V_2 = * V_86 ) != NULL ) && F_61 ( V_2 ) ;
V_86 = & V_2 -> V_69 ) {
if ( V_2 -> V_22 == V_34 ) {
V_135 = V_86 ;
continue;
}
if ( V_112 == V_30 )
goto V_91;
if ( V_2 -> V_3 & V_4 )
goto V_91;
}
if ( V_135 != NULL ) {
error = V_136 -> V_17 -> V_140 ( V_135 , V_112 ) ;
if ( ! error )
* V_134 = * V_135 ;
goto V_91;
}
error = - V_32 ;
if ( ! V_141 )
goto V_91;
F_45 ( V_86 , V_136 ) ;
return 0 ;
V_91:
return error ;
}
int F_88 ( struct V_33 * V_34 , struct V_1 * * V_134 )
{
struct V_1 * V_2 , * * V_86 ;
struct V_51 * V_51 = V_34 -> V_50 . V_51 ;
struct V_87 * V_87 = V_51 -> V_52 ;
for ( V_86 = & V_87 -> V_80 ;
( ( V_2 = * V_86 ) != NULL ) && F_61 ( V_2 ) ;
V_86 = & V_2 -> V_69 ) {
if ( V_2 -> V_22 != V_34 )
continue;
return ( * V_134 ) -> V_17 -> V_140 ( V_86 , V_6 ) ;
}
return - V_94 ;
}
int F_89 ( struct V_33 * V_34 , long V_112 , struct V_1 * * V_134 )
{
struct V_51 * V_51 = V_34 -> V_50 . V_51 ;
struct V_87 * V_87 = V_51 -> V_52 ;
int error ;
if ( ( ! F_90 ( F_91 () , V_87 -> V_142 ) ) && ! F_92 ( V_143 ) )
return - V_144 ;
if ( ! F_93 ( V_87 -> V_145 ) )
return - V_32 ;
error = F_94 ( V_34 , V_112 ) ;
if ( error )
return error ;
F_78 ( V_87 ) ;
F_14 ( ! ( * V_134 ) -> V_17 -> V_128 ) ;
switch ( V_112 ) {
case V_6 :
return F_88 ( V_34 , V_134 ) ;
case V_7 :
case V_30 :
return F_86 ( V_34 , V_112 , V_134 ) ;
default:
return - V_32 ;
}
}
static int F_95 ( struct V_33 * V_34 , long V_112 , struct V_1 * * V_136 )
{
if ( V_34 -> V_146 && V_34 -> V_146 -> V_147 )
return V_34 -> V_146 -> V_147 ( V_34 , V_112 , V_136 ) ;
else
return F_89 ( V_34 , V_112 , V_136 ) ;
}
int F_96 ( struct V_33 * V_34 , long V_112 , struct V_1 * * V_136 )
{
int error ;
F_3 () ;
error = F_95 ( V_34 , V_112 , V_136 ) ;
F_5 () ;
return error ;
}
static int F_97 ( struct V_33 * V_34 )
{
struct V_1 V_2 , * V_134 = & V_2 ;
F_30 ( V_34 , V_6 , V_134 ) ;
return F_96 ( V_34 , V_6 , & V_134 ) ;
}
static int F_98 ( unsigned int V_148 , struct V_33 * V_34 , long V_112 )
{
struct V_1 * V_2 , * V_149 ;
struct V_150 * V_18 ;
int error ;
V_2 = F_31 ( V_34 , V_112 ) ;
if ( F_80 ( V_2 ) )
return F_81 ( V_2 ) ;
V_18 = F_99 () ;
if ( ! V_18 ) {
F_13 ( V_2 ) ;
return - V_36 ;
}
V_149 = V_2 ;
F_3 () ;
error = F_95 ( V_34 , V_112 , & V_149 ) ;
if ( error ) {
F_5 () ;
F_13 ( V_2 ) ;
goto V_151;
}
if ( V_149 != V_2 )
F_13 ( V_2 ) ;
if ( ! F_100 ( V_148 , V_34 , & V_149 -> V_60 , V_18 ) )
V_18 = NULL ;
error = F_101 ( V_34 , F_102 ( V_37 ) , V_152 , 0 ) ;
F_5 () ;
V_151:
if ( V_18 )
F_103 ( V_18 ) ;
return error ;
}
int F_104 ( unsigned int V_148 , struct V_33 * V_34 , long V_112 )
{
if ( V_112 == V_6 )
return F_97 ( V_34 ) ;
return F_98 ( V_148 , V_34 , V_112 ) ;
}
int F_105 ( struct V_33 * V_34 , struct V_1 * V_2 )
{
int error ;
F_66 () ;
for (; ; ) {
error = F_59 ( V_34 , V_2 ) ;
if ( error != V_96 )
break;
error = F_67 ( V_2 -> V_12 , ! V_2 -> V_69 ) ;
if ( ! error )
continue;
F_37 ( V_2 ) ;
break;
}
return error ;
}
int F_106 ( struct V_33 * V_34 , struct V_1 * V_2 )
{
if ( V_34 -> V_146 && V_34 -> V_146 -> V_35 )
return V_34 -> V_146 -> V_35 ( V_34 , V_153 , V_2 ) ;
F_54 ( V_34 , V_2 ) ;
return 0 ;
}
static int F_107 ( struct V_41 * V_41 , struct V_1 * V_2 )
{
V_41 -> V_154 = V_2 -> V_21 ;
#if V_155 == 32
if ( V_2 -> V_23 > V_156 )
return - V_55 ;
if ( V_2 -> V_24 != V_40 && V_2 -> V_24 > V_156 )
return - V_55 ;
#endif
V_41 -> V_53 = V_2 -> V_23 ;
V_41 -> V_54 = V_2 -> V_24 == V_40 ? 0 :
V_2 -> V_24 - V_2 -> V_23 + 1 ;
V_41 -> V_45 = 0 ;
V_41 -> V_58 = V_2 -> V_8 ;
return 0 ;
}
static void F_108 ( struct V_59 * V_41 , struct V_1 * V_2 )
{
V_41 -> V_154 = V_2 -> V_21 ;
V_41 -> V_53 = V_2 -> V_23 ;
V_41 -> V_54 = V_2 -> V_24 == V_40 ? 0 :
V_2 -> V_24 - V_2 -> V_23 + 1 ;
V_41 -> V_45 = 0 ;
V_41 -> V_58 = V_2 -> V_8 ;
}
int F_109 ( struct V_33 * V_34 , struct V_41 T_5 * V_42 )
{
struct V_1 V_1 ;
struct V_41 V_41 ;
int error ;
error = - V_157 ;
if ( F_110 ( & V_41 , V_42 , sizeof( V_41 ) ) )
goto V_91;
error = - V_32 ;
if ( ( V_41 . V_58 != V_7 ) && ( V_41 . V_58 != V_30 ) )
goto V_91;
error = F_25 ( V_34 , & V_1 , & V_41 ) ;
if ( error )
goto V_91;
error = F_106 ( V_34 , & V_1 ) ;
if ( error )
goto V_91;
V_41 . V_58 = V_1 . V_8 ;
if ( V_1 . V_8 != V_6 ) {
error = F_107 ( & V_41 , & V_1 ) ;
if ( error )
goto V_91;
}
error = - V_157 ;
if ( ! F_111 ( V_42 , & V_41 , sizeof( V_41 ) ) )
error = 0 ;
V_91:
return error ;
}
int F_112 ( struct V_33 * V_34 , unsigned int V_25 , struct V_1 * V_2 , struct V_1 * V_158 )
{
if ( V_34 -> V_146 && V_34 -> V_146 -> V_35 )
return V_34 -> V_146 -> V_35 ( V_34 , V_25 , V_2 ) ;
else
return F_64 ( V_34 , V_2 , V_158 ) ;
}
static int F_113 ( struct V_33 * V_34 , unsigned int V_25 ,
struct V_1 * V_2 )
{
int error ;
error = F_94 ( V_34 , V_2 -> V_8 ) ;
if ( error )
return error ;
for (; ; ) {
error = F_112 ( V_34 , V_25 , V_2 , NULL ) ;
if ( error != V_96 )
break;
error = F_67 ( V_2 -> V_12 , ! V_2 -> V_69 ) ;
if ( ! error )
continue;
F_37 ( V_2 ) ;
break;
}
return error ;
}
int F_114 ( unsigned int V_148 , struct V_33 * V_34 , unsigned int V_25 ,
struct V_41 T_5 * V_42 )
{
struct V_1 * V_1 = F_10 () ;
struct V_41 V_41 ;
struct V_87 * V_87 ;
struct V_33 * V_159 ;
int error ;
if ( V_1 == NULL )
return - V_104 ;
error = - V_157 ;
if ( F_110 ( & V_41 , V_42 , sizeof( V_41 ) ) )
goto V_91;
V_87 = V_34 -> V_50 . V_51 -> V_52 ;
if ( F_115 ( V_87 ) && F_116 ( V_34 -> V_160 ) ) {
error = - V_94 ;
goto V_91;
}
V_161:
error = F_25 ( V_34 , V_1 , & V_41 ) ;
if ( error )
goto V_91;
if ( V_25 == V_162 ) {
V_1 -> V_3 |= V_95 ;
}
error = - V_163 ;
switch ( V_41 . V_58 ) {
case V_7 :
if ( ! ( V_34 -> V_164 & V_165 ) )
goto V_91;
break;
case V_30 :
if ( ! ( V_34 -> V_164 & V_166 ) )
goto V_91;
break;
case V_6 :
break;
default:
error = - V_32 ;
goto V_91;
}
error = F_113 ( V_34 , V_25 , V_1 ) ;
F_4 ( & V_37 -> V_56 -> V_1 ) ;
V_159 = F_117 ( V_148 ) ;
F_6 ( & V_37 -> V_56 -> V_1 ) ;
if ( ! error && V_159 != V_34 && V_41 . V_58 != V_6 ) {
V_41 . V_58 = V_6 ;
goto V_161;
}
V_91:
F_13 ( V_1 ) ;
return error ;
}
int F_118 ( struct V_33 * V_34 , struct V_59 T_5 * V_42 )
{
struct V_1 V_1 ;
struct V_59 V_41 ;
int error ;
error = - V_157 ;
if ( F_110 ( & V_41 , V_42 , sizeof( V_41 ) ) )
goto V_91;
error = - V_32 ;
if ( ( V_41 . V_58 != V_7 ) && ( V_41 . V_58 != V_30 ) )
goto V_91;
error = F_27 ( V_34 , & V_1 , & V_41 ) ;
if ( error )
goto V_91;
error = F_106 ( V_34 , & V_1 ) ;
if ( error )
goto V_91;
V_41 . V_58 = V_1 . V_8 ;
if ( V_1 . V_8 != V_6 )
F_108 ( & V_41 , & V_1 ) ;
error = - V_157 ;
if ( ! F_111 ( V_42 , & V_41 , sizeof( V_41 ) ) )
error = 0 ;
V_91:
return error ;
}
int F_119 ( unsigned int V_148 , struct V_33 * V_34 , unsigned int V_25 ,
struct V_59 T_5 * V_42 )
{
struct V_1 * V_1 = F_10 () ;
struct V_59 V_41 ;
struct V_87 * V_87 ;
struct V_33 * V_159 ;
int error ;
if ( V_1 == NULL )
return - V_104 ;
error = - V_157 ;
if ( F_110 ( & V_41 , V_42 , sizeof( V_41 ) ) )
goto V_91;
V_87 = V_34 -> V_50 . V_51 -> V_52 ;
if ( F_115 ( V_87 ) && F_116 ( V_34 -> V_160 ) ) {
error = - V_94 ;
goto V_91;
}
V_161:
error = F_27 ( V_34 , V_1 , & V_41 ) ;
if ( error )
goto V_91;
if ( V_25 == V_167 ) {
V_1 -> V_3 |= V_95 ;
}
error = - V_163 ;
switch ( V_41 . V_58 ) {
case V_7 :
if ( ! ( V_34 -> V_164 & V_165 ) )
goto V_91;
break;
case V_30 :
if ( ! ( V_34 -> V_164 & V_166 ) )
goto V_91;
break;
case V_6 :
break;
default:
error = - V_32 ;
goto V_91;
}
error = F_113 ( V_34 , V_25 , V_1 ) ;
F_4 ( & V_37 -> V_56 -> V_1 ) ;
V_159 = F_117 ( V_148 ) ;
F_6 ( & V_37 -> V_56 -> V_1 ) ;
if ( ! error && V_159 != V_34 && V_41 . V_58 != V_6 ) {
V_41 . V_58 = V_6 ;
goto V_161;
}
V_91:
F_13 ( V_1 ) ;
return error ;
}
void F_120 ( struct V_33 * V_34 , T_3 V_105 )
{
struct V_1 V_35 ;
if ( ! V_34 -> V_50 . V_51 -> V_52 -> V_80 )
return;
V_35 . V_8 = V_6 ;
V_35 . V_3 = V_57 | V_168 ;
V_35 . V_23 = 0 ;
V_35 . V_24 = V_40 ;
V_35 . V_20 = V_105 ;
V_35 . V_21 = V_37 -> V_38 ;
V_35 . V_22 = V_34 ;
V_35 . V_15 = NULL ;
V_35 . V_17 = NULL ;
F_112 ( V_34 , V_169 , & V_35 , NULL ) ;
if ( V_35 . V_15 && V_35 . V_15 -> V_16 )
V_35 . V_15 -> V_16 ( & V_35 ) ;
}
void F_121 ( struct V_33 * V_34 )
{
struct V_87 * V_87 = V_34 -> V_50 . V_51 -> V_52 ;
struct V_1 * V_2 ;
struct V_1 * * V_86 ;
if ( ! V_87 -> V_80 )
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
V_86 = & V_87 -> V_80 ;
while ( ( V_2 = * V_86 ) != NULL ) {
if ( V_2 -> V_22 == V_34 ) {
if ( F_53 ( V_2 ) ) {
F_48 ( V_86 ) ;
continue;
}
if ( F_61 ( V_2 ) ) {
F_72 ( V_86 , V_6 ) ;
continue;
}
F_122 () ;
}
V_86 = & V_2 -> V_69 ;
}
F_5 () ;
}
int
F_123 ( struct V_33 * V_34 , struct V_1 * V_68 )
{
int V_170 = 0 ;
F_3 () ;
if ( V_68 -> V_69 )
F_35 ( V_68 ) ;
else
V_170 = - V_93 ;
F_5 () ;
return V_170 ;
}
int F_124 ( struct V_33 * V_34 , struct V_1 * V_2 )
{
if ( V_34 -> V_146 && V_34 -> V_146 -> V_35 )
return V_34 -> V_146 -> V_35 ( V_34 , V_171 , V_2 ) ;
return 0 ;
}
static void F_125 ( struct V_172 * V_159 , struct V_1 * V_2 ,
T_2 V_173 , char * V_174 )
{
struct V_87 * V_87 = NULL ;
unsigned int V_21 ;
if ( V_2 -> V_75 )
V_21 = F_55 ( V_2 -> V_75 ) ;
else
V_21 = V_2 -> V_21 ;
if ( V_2 -> V_22 != NULL )
V_87 = V_2 -> V_22 -> V_50 . V_51 -> V_52 ;
F_126 ( V_159 , L_2 , V_173 , V_174 ) ;
if ( F_40 ( V_2 ) ) {
F_126 ( V_159 , L_3 ,
( V_2 -> V_3 & V_89 ) ? L_4 : L_5 ,
( V_87 == NULL ) ? L_6 :
F_115 ( V_87 ) ? L_7 : L_8 ) ;
} else if ( F_53 ( V_2 ) ) {
if ( V_2 -> V_8 & V_26 ) {
F_126 ( V_159 , L_9 ) ;
} else {
F_126 ( V_159 , L_10 ) ;
}
} else if ( F_61 ( V_2 ) ) {
F_126 ( V_159 , L_11 ) ;
if ( F_1 ( V_2 ) )
F_126 ( V_159 , L_12 ) ;
else if ( V_2 -> V_22 )
F_126 ( V_159 , L_13 ) ;
else
F_126 ( V_159 , L_14 ) ;
} else {
F_126 ( V_159 , L_15 ) ;
}
if ( V_2 -> V_8 & V_26 ) {
F_126 ( V_159 , L_16 ,
( V_2 -> V_8 & V_175 )
? ( V_2 -> V_8 & V_176 ) ? L_17 : L_18
: ( V_2 -> V_8 & V_176 ) ? L_19 : L_20 ) ;
} else {
F_126 ( V_159 , L_16 ,
( F_1 ( V_2 ) )
? ( V_2 -> V_8 == V_6 ) ? L_21 : L_18
: ( V_2 -> V_8 == V_30 ) ? L_19 : L_18 ) ;
}
if ( V_87 ) {
#ifdef F_127
F_126 ( V_159 , L_22 , V_21 ,
V_87 -> V_132 -> V_177 , V_87 -> V_178 ) ;
#else
F_126 ( V_159 , L_23 , V_21 ,
F_128 ( V_87 -> V_132 -> V_179 ) ,
F_129 ( V_87 -> V_132 -> V_179 ) , V_87 -> V_178 ) ;
#endif
} else {
F_126 ( V_159 , L_24 , V_21 ) ;
}
if ( F_40 ( V_2 ) ) {
if ( V_2 -> V_24 == V_40 )
F_126 ( V_159 , L_25 , V_2 -> V_23 ) ;
else
F_126 ( V_159 , L_26 , V_2 -> V_23 , V_2 -> V_24 ) ;
} else {
F_126 ( V_159 , L_27 ) ;
}
}
static int F_130 ( struct V_172 * V_159 , void * V_180 )
{
struct V_1 * V_2 , * V_181 ;
V_2 = F_131 ( V_180 , struct V_1 , V_10 ) ;
F_125 ( V_159 , V_2 , * ( ( T_2 * ) V_159 -> V_182 ) , L_28 ) ;
F_57 (bfl, &fl->fl_block, fl_block)
F_125 ( V_159 , V_181 , * ( ( T_2 * ) V_159 -> V_182 ) , L_29 ) ;
return 0 ;
}
static void * F_132 ( struct V_172 * V_159 , T_2 * V_73 )
{
T_2 * V_183 = V_159 -> V_182 ;
F_3 () ;
* V_183 = ( * V_73 + 1 ) ;
return F_133 ( & V_74 , * V_73 ) ;
}
static void * F_134 ( struct V_172 * V_159 , void * V_180 , T_2 * V_73 )
{
T_2 * V_183 = V_159 -> V_182 ;
++ * V_183 ;
return F_135 ( V_180 , & V_74 , V_73 ) ;
}
static void F_136 ( struct V_172 * V_159 , void * V_180 )
{
F_5 () ;
}
static int F_137 ( struct V_87 * V_87 , struct V_33 * V_34 )
{
return F_138 ( V_34 , & V_184 , sizeof( T_2 ) ) ;
}
static int T_6 F_139 ( void )
{
F_140 ( L_30 , 0 , NULL , & V_185 ) ;
return 0 ;
}
int F_141 ( struct V_87 * V_87 , T_2 V_43 , unsigned long V_186 )
{
struct V_1 * V_2 ;
int V_187 = 1 ;
F_3 () ;
for ( V_2 = V_87 -> V_80 ; V_2 != NULL ; V_2 = V_2 -> V_69 ) {
if ( F_40 ( V_2 ) ) {
if ( V_2 -> V_8 == V_7 )
continue;
if ( ( V_2 -> V_24 < V_43 ) || ( V_2 -> V_23 > ( V_43 + V_186 ) ) )
continue;
} else if ( F_53 ( V_2 ) ) {
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
int F_142 ( struct V_87 * V_87 , T_2 V_43 , unsigned long V_186 )
{
struct V_1 * V_2 ;
int V_187 = 1 ;
F_3 () ;
for ( V_2 = V_87 -> V_80 ; V_2 != NULL ; V_2 = V_2 -> V_69 ) {
if ( F_40 ( V_2 ) ) {
if ( ( V_2 -> V_24 < V_43 ) || ( V_2 -> V_23 > ( V_43 + V_186 ) ) )
continue;
} else if ( F_53 ( V_2 ) ) {
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
static int T_6 F_143 ( void )
{
V_13 = F_144 ( L_31 ,
sizeof( struct V_1 ) , 0 , V_188 , NULL ) ;
return 0 ;
}
