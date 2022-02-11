void F_1 ( void )
{
F_2 ( & V_1 ) ;
}
void F_3 ( void )
{
F_4 ( & V_1 ) ;
}
static void F_5 ( struct V_2 * V_3 )
{
F_6 ( & V_3 -> V_4 ) ;
F_6 ( & V_3 -> V_5 ) ;
F_7 ( & V_3 -> V_6 ) ;
}
struct V_2 * F_8 ( void )
{
struct V_2 * V_3 = F_9 ( V_7 , V_8 ) ;
if ( V_3 )
F_5 ( V_3 ) ;
return V_3 ;
}
void F_10 ( struct V_2 * V_3 )
{
if ( V_3 -> V_9 ) {
if ( V_3 -> V_9 -> V_10 )
V_3 -> V_9 -> V_10 ( V_3 ) ;
V_3 -> V_9 = NULL ;
}
if ( V_3 -> V_11 ) {
if ( V_3 -> V_11 -> V_12 )
V_3 -> V_11 -> V_12 ( V_3 ) ;
V_3 -> V_11 = NULL ;
}
}
void F_11 ( struct V_2 * V_3 )
{
F_12 ( F_13 ( & V_3 -> V_6 ) ) ;
F_12 ( ! F_14 ( & V_3 -> V_5 ) ) ;
F_12 ( ! F_14 ( & V_3 -> V_4 ) ) ;
F_10 ( V_3 ) ;
F_15 ( V_7 , V_3 ) ;
}
void F_16 ( struct V_2 * V_3 )
{
memset ( V_3 , 0 , sizeof( struct V_2 ) ) ;
F_5 ( V_3 ) ;
}
static void F_17 ( struct V_2 * V_13 , struct V_2 * V_3 )
{
if ( V_3 -> V_9 ) {
if ( V_3 -> V_9 -> V_14 )
V_3 -> V_9 -> V_14 ( V_13 , V_3 ) ;
V_13 -> V_9 = V_3 -> V_9 ;
}
if ( V_3 -> V_11 )
V_13 -> V_11 = V_3 -> V_11 ;
}
void F_18 ( struct V_2 * V_13 , const struct V_2 * V_3 )
{
V_13 -> V_15 = V_3 -> V_15 ;
V_13 -> V_16 = V_3 -> V_16 ;
V_13 -> V_17 = NULL ;
V_13 -> V_18 = V_3 -> V_18 ;
V_13 -> V_19 = V_3 -> V_19 ;
V_13 -> V_20 = V_3 -> V_20 ;
V_13 -> V_21 = V_3 -> V_21 ;
V_13 -> V_9 = NULL ;
V_13 -> V_11 = NULL ;
}
void F_19 ( struct V_2 * V_13 , struct V_2 * V_3 )
{
F_10 ( V_13 ) ;
F_18 ( V_13 , V_3 ) ;
V_13 -> V_17 = V_3 -> V_17 ;
V_13 -> V_9 = V_3 -> V_9 ;
V_13 -> V_11 = V_3 -> V_11 ;
F_17 ( V_13 , V_3 ) ;
}
static inline int F_20 ( int V_22 ) {
if ( V_22 & V_23 )
return V_22 & ( V_23 | V_24 ) ;
switch ( V_22 ) {
case V_25 :
return V_26 ;
case V_27 :
return V_28 ;
case V_29 :
return V_30 ;
}
return - V_31 ;
}
static int F_21 ( struct V_32 * V_33 , struct V_2 * * V_34 ,
unsigned int V_22 )
{
struct V_2 * V_3 ;
int type = F_20 ( V_22 ) ;
if ( type < 0 )
return type ;
V_3 = F_8 () ;
if ( V_3 == NULL )
return - V_35 ;
V_3 -> V_17 = V_33 ;
V_3 -> V_16 = V_36 -> V_37 ;
V_3 -> V_18 = V_38 ;
V_3 -> V_19 = type ;
V_3 -> V_21 = V_39 ;
* V_34 = V_3 ;
return 0 ;
}
static int F_22 ( struct V_2 * V_3 , int type )
{
switch ( type ) {
case V_26 :
case V_28 :
case V_30 :
V_3 -> V_19 = type ;
break;
default:
return - V_31 ;
}
return 0 ;
}
static int F_23 ( struct V_32 * V_33 , struct V_2 * V_3 ,
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
V_42 = F_24 ( V_33 -> V_49 . V_50 -> V_51 ) ;
break;
default:
return - V_31 ;
}
V_42 += V_41 -> V_52 ;
if ( V_42 < 0 )
return - V_31 ;
V_3 -> V_21 = V_39 ;
if ( V_41 -> V_53 > 0 ) {
V_43 = V_42 + V_41 -> V_53 - 1 ;
V_3 -> V_21 = V_43 ;
} else if ( V_41 -> V_53 < 0 ) {
V_43 = V_42 - 1 ;
V_3 -> V_21 = V_43 ;
V_42 += V_41 -> V_53 ;
if ( V_42 < 0 )
return - V_31 ;
}
V_3 -> V_20 = V_42 ;
if ( V_3 -> V_21 < V_3 -> V_20 )
return - V_54 ;
V_3 -> V_15 = V_36 -> V_55 ;
V_3 -> V_16 = V_36 -> V_37 ;
V_3 -> V_17 = V_33 ;
V_3 -> V_18 = V_56 ;
V_3 -> V_9 = NULL ;
V_3 -> V_11 = NULL ;
return F_22 ( V_3 , V_41 -> V_57 ) ;
}
static int F_25 ( struct V_32 * V_33 , struct V_2 * V_3 ,
struct V_58 * V_41 )
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
V_42 = F_24 ( V_33 -> V_49 . V_50 -> V_51 ) ;
break;
default:
return - V_31 ;
}
V_42 += V_41 -> V_52 ;
if ( V_42 < 0 )
return - V_31 ;
V_3 -> V_21 = V_39 ;
if ( V_41 -> V_53 > 0 ) {
V_3 -> V_21 = V_42 + V_41 -> V_53 - 1 ;
} else if ( V_41 -> V_53 < 0 ) {
V_3 -> V_21 = V_42 - 1 ;
V_42 += V_41 -> V_53 ;
if ( V_42 < 0 )
return - V_31 ;
}
V_3 -> V_20 = V_42 ;
if ( V_3 -> V_21 < V_3 -> V_20 )
return - V_54 ;
V_3 -> V_15 = V_36 -> V_55 ;
V_3 -> V_16 = V_36 -> V_37 ;
V_3 -> V_17 = V_33 ;
V_3 -> V_18 = V_56 ;
V_3 -> V_9 = NULL ;
V_3 -> V_11 = NULL ;
return F_22 ( V_3 , V_41 -> V_57 ) ;
}
static void F_26 ( struct V_2 * V_3 )
{
F_27 ( & V_3 -> V_59 , V_60 , V_61 ) ;
}
static void F_28 ( struct V_2 * V_3 )
{
if ( ! V_3 -> V_17 )
return;
F_29 ( V_3 -> V_17 ) ;
V_3 -> V_17 -> V_62 . V_63 = 0 ;
}
static int F_30 ( struct V_32 * V_33 , int type , struct V_2 * V_3 )
{
if ( F_22 ( V_3 , type ) != 0 )
return - V_31 ;
V_3 -> V_15 = V_36 -> V_55 ;
V_3 -> V_16 = V_36 -> V_37 ;
V_3 -> V_17 = V_33 ;
V_3 -> V_18 = V_64 ;
V_3 -> V_20 = 0 ;
V_3 -> V_21 = V_39 ;
V_3 -> V_9 = NULL ;
V_3 -> V_11 = & V_65 ;
return 0 ;
}
static struct V_2 * F_31 ( struct V_32 * V_33 , int type )
{
struct V_2 * V_3 = F_8 () ;
int error = - V_35 ;
if ( V_3 == NULL )
return F_32 ( error ) ;
error = F_30 ( V_33 , type , V_3 ) ;
if ( error ) {
F_11 ( V_3 ) ;
return F_32 ( error ) ;
}
return V_3 ;
}
static inline int F_33 ( struct V_2 * V_66 , struct V_2 * V_67 )
{
return ( ( V_66 -> V_21 >= V_67 -> V_20 ) &&
( V_67 -> V_21 >= V_66 -> V_20 ) ) ;
}
static int F_34 ( struct V_2 * V_66 , struct V_2 * V_67 )
{
if ( V_66 -> V_11 && V_66 -> V_11 -> V_68 )
return V_67 -> V_11 == V_66 -> V_11 &&
V_66 -> V_11 -> V_68 ( V_66 , V_67 ) ;
return V_66 -> V_15 == V_67 -> V_15 ;
}
static void F_35 ( struct V_2 * V_69 )
{
F_36 ( & V_69 -> V_5 ) ;
F_36 ( & V_69 -> V_4 ) ;
V_69 -> V_70 = NULL ;
}
static void F_37 ( struct V_2 * V_69 )
{
F_1 () ;
F_35 ( V_69 ) ;
F_3 () ;
}
static void F_38 ( struct V_2 * V_71 ,
struct V_2 * V_69 )
{
F_12 ( ! F_14 ( & V_69 -> V_5 ) ) ;
F_39 ( & V_69 -> V_5 , & V_71 -> V_5 ) ;
V_69 -> V_70 = V_71 ;
if ( F_40 ( V_71 ) )
F_41 ( & V_69 -> V_4 , & V_72 ) ;
}
static void F_42 ( struct V_2 * V_71 )
{
while ( ! F_14 ( & V_71 -> V_5 ) ) {
struct V_2 * V_69 ;
V_69 = F_43 ( & V_71 -> V_5 ,
struct V_2 , V_5 ) ;
F_35 ( V_69 ) ;
if ( V_69 -> V_11 && V_69 -> V_11 -> V_73 )
V_69 -> V_11 -> V_73 ( V_69 ) ;
else
F_44 ( & V_69 -> V_6 ) ;
}
}
static void F_45 ( struct V_2 * * V_74 , struct V_2 * V_3 )
{
F_41 ( & V_3 -> V_4 , & V_75 ) ;
V_3 -> V_76 = F_46 ( F_47 ( V_36 ) ) ;
V_3 -> V_70 = * V_74 ;
* V_74 = V_3 ;
}
static void F_48 ( struct V_2 * * V_77 )
{
struct V_2 * V_3 = * V_77 ;
* V_77 = V_3 -> V_70 ;
V_3 -> V_70 = NULL ;
F_36 ( & V_3 -> V_4 ) ;
F_49 ( 0 , V_3 -> V_17 , 0 , & V_3 -> V_59 ) ;
if ( V_3 -> V_59 != NULL ) {
F_50 ( V_78 L_1 , V_3 -> V_59 ) ;
V_3 -> V_59 = NULL ;
}
if ( V_3 -> V_76 ) {
F_51 ( V_3 -> V_76 ) ;
V_3 -> V_76 = NULL ;
}
F_42 ( V_3 ) ;
F_11 ( V_3 ) ;
}
static int F_52 ( struct V_2 * V_79 , struct V_2 * V_80 )
{
if ( V_80 -> V_19 == V_28 )
return 1 ;
if ( V_79 -> V_19 == V_28 )
return 1 ;
return 0 ;
}
static int F_53 ( struct V_2 * V_79 , struct V_2 * V_80 )
{
if ( ! F_40 ( V_80 ) || F_34 ( V_79 , V_80 ) )
return ( 0 ) ;
if ( ! F_33 ( V_79 , V_80 ) )
return 0 ;
return ( F_52 ( V_79 , V_80 ) ) ;
}
static int F_54 ( struct V_2 * V_79 , struct V_2 * V_80 )
{
if ( ! F_55 ( V_80 ) || ( V_79 -> V_17 == V_80 -> V_17 ) )
return ( 0 ) ;
if ( ( V_79 -> V_19 & V_23 ) || ( V_80 -> V_19 & V_23 ) )
return 0 ;
return ( F_52 ( V_79 , V_80 ) ) ;
}
void
F_56 ( struct V_32 * V_33 , struct V_2 * V_3 )
{
struct V_2 * V_81 ;
F_1 () ;
for ( V_81 = V_33 -> V_49 . V_50 -> V_51 -> V_82 ; V_81 ; V_81 = V_81 -> V_70 ) {
if ( ! F_40 ( V_81 ) )
continue;
if ( F_53 ( V_3 , V_81 ) )
break;
}
if ( V_81 ) {
F_18 ( V_3 , V_81 ) ;
if ( V_81 -> V_76 )
V_3 -> V_16 = F_57 ( V_81 -> V_76 ) ;
} else
V_3 -> V_19 = V_30 ;
F_3 () ;
return;
}
static struct V_2 * F_58 ( struct V_2 * V_83 )
{
struct V_2 * V_3 ;
F_59 (fl, &blocked_list, fl_link) {
if ( F_34 ( V_3 , V_83 ) )
return V_3 -> V_70 ;
}
return NULL ;
}
static int F_60 ( struct V_2 * V_79 ,
struct V_2 * V_83 )
{
int V_84 = 0 ;
while ( ( V_83 = F_58 ( V_83 ) ) ) {
if ( V_84 ++ > V_85 )
return 0 ;
if ( F_34 ( V_79 , V_83 ) )
return 1 ;
}
return 0 ;
}
static int F_61 ( struct V_32 * V_33 , struct V_2 * V_86 )
{
struct V_2 * V_87 = NULL ;
struct V_2 * * V_88 ;
struct V_89 * V_89 = V_33 -> V_49 . V_50 -> V_51 ;
int error = 0 ;
int V_90 = 0 ;
if ( ! ( V_86 -> V_18 & V_91 ) && ( V_86 -> V_19 != V_30 ) ) {
V_87 = F_8 () ;
if ( ! V_87 )
return - V_35 ;
}
F_1 () ;
if ( V_86 -> V_18 & V_91 )
goto V_92;
F_62 (inode, before) {
struct V_2 * V_3 = * V_88 ;
if ( F_40 ( V_3 ) )
break;
if ( F_63 ( V_3 ) )
continue;
if ( V_33 != V_3 -> V_17 )
continue;
if ( V_86 -> V_19 == V_3 -> V_19 )
goto V_93;
V_90 = 1 ;
F_48 ( V_88 ) ;
break;
}
if ( V_86 -> V_19 == V_30 ) {
if ( ( V_86 -> V_18 & V_94 ) && ! V_90 )
error = - V_95 ;
goto V_93;
}
if ( V_90 ) {
F_3 () ;
F_64 () ;
F_1 () ;
}
V_92:
F_62 (inode, before) {
struct V_2 * V_3 = * V_88 ;
if ( F_40 ( V_3 ) )
break;
if ( F_63 ( V_3 ) )
continue;
if ( ! F_54 ( V_86 , V_3 ) )
continue;
error = - V_96 ;
if ( ! ( V_86 -> V_18 & V_97 ) )
goto V_93;
error = V_98 ;
F_38 ( V_3 , V_86 ) ;
goto V_93;
}
if ( V_86 -> V_18 & V_91 )
goto V_93;
F_19 ( V_87 , V_86 ) ;
F_45 ( V_88 , V_87 ) ;
V_87 = NULL ;
error = 0 ;
V_93:
F_3 () ;
if ( V_87 )
F_11 ( V_87 ) ;
return error ;
}
static int F_65 ( struct V_89 * V_89 , struct V_2 * V_86 , struct V_2 * V_99 )
{
struct V_2 * V_3 ;
struct V_2 * V_87 = NULL ;
struct V_2 * V_100 = NULL ;
struct V_2 * V_101 = NULL ;
struct V_2 * V_102 = NULL ;
struct V_2 * * V_88 ;
int error , V_103 = 0 ;
if ( ! ( V_86 -> V_18 & V_91 ) &&
( V_86 -> V_19 != V_30 ||
V_86 -> V_20 != 0 || V_86 -> V_21 != V_39 ) ) {
V_87 = F_8 () ;
V_100 = F_8 () ;
}
F_1 () ;
if ( V_86 -> V_19 != V_30 ) {
F_62 (inode, before) {
V_3 = * V_88 ;
if ( ! F_40 ( V_3 ) )
continue;
if ( ! F_53 ( V_86 , V_3 ) )
continue;
if ( V_99 )
F_18 ( V_99 , V_3 ) ;
error = - V_96 ;
if ( ! ( V_86 -> V_18 & V_97 ) )
goto V_93;
error = - V_104 ;
if ( F_60 ( V_86 , V_3 ) )
goto V_93;
error = V_98 ;
F_38 ( V_3 , V_86 ) ;
goto V_93;
}
}
error = 0 ;
if ( V_86 -> V_18 & V_91 )
goto V_93;
V_88 = & V_89 -> V_82 ;
while ( ( V_3 = * V_88 ) && ( ! F_40 ( V_3 ) ||
! F_34 ( V_86 , V_3 ) ) ) {
V_88 = & V_3 -> V_70 ;
}
while ( ( V_3 = * V_88 ) && F_34 ( V_86 , V_3 ) ) {
if ( V_86 -> V_19 == V_3 -> V_19 ) {
if ( V_3 -> V_21 < V_86 -> V_20 - 1 )
goto V_105;
if ( V_3 -> V_20 - 1 > V_86 -> V_21 )
break;
if ( V_3 -> V_20 > V_86 -> V_20 )
V_3 -> V_20 = V_86 -> V_20 ;
else
V_86 -> V_20 = V_3 -> V_20 ;
if ( V_3 -> V_21 < V_86 -> V_21 )
V_3 -> V_21 = V_86 -> V_21 ;
else
V_86 -> V_21 = V_3 -> V_21 ;
if ( V_103 ) {
F_48 ( V_88 ) ;
continue;
}
V_86 = V_3 ;
V_103 = 1 ;
}
else {
if ( V_3 -> V_21 < V_86 -> V_20 )
goto V_105;
if ( V_3 -> V_20 > V_86 -> V_21 )
break;
if ( V_86 -> V_19 == V_30 )
V_103 = 1 ;
if ( V_3 -> V_20 < V_86 -> V_20 )
V_101 = V_3 ;
if ( V_3 -> V_21 > V_86 -> V_21 ) {
V_102 = V_3 ;
break;
}
if ( V_3 -> V_20 >= V_86 -> V_20 ) {
if ( V_103 ) {
F_48 ( V_88 ) ;
continue;
}
F_42 ( V_3 ) ;
V_3 -> V_20 = V_86 -> V_20 ;
V_3 -> V_21 = V_86 -> V_21 ;
V_3 -> V_19 = V_86 -> V_19 ;
F_10 ( V_3 ) ;
F_17 ( V_3 , V_86 ) ;
V_86 = V_3 ;
V_103 = 1 ;
}
}
V_105:
V_88 = & V_3 -> V_70 ;
}
error = - V_106 ;
if ( V_102 && V_101 == V_102 && ! V_100 )
goto V_93;
error = 0 ;
if ( ! V_103 ) {
if ( V_86 -> V_19 == V_30 ) {
if ( V_86 -> V_18 & V_94 )
error = - V_95 ;
goto V_93;
}
if ( ! V_87 ) {
error = - V_106 ;
goto V_93;
}
F_19 ( V_87 , V_86 ) ;
F_45 ( V_88 , V_87 ) ;
V_87 = NULL ;
}
if ( V_102 ) {
if ( V_101 == V_102 ) {
V_101 = V_100 ;
V_100 = NULL ;
F_19 ( V_101 , V_102 ) ;
F_45 ( V_88 , V_101 ) ;
}
V_102 -> V_20 = V_86 -> V_21 + 1 ;
F_42 ( V_102 ) ;
}
if ( V_101 ) {
V_101 -> V_21 = V_86 -> V_20 - 1 ;
F_42 ( V_101 ) ;
}
V_93:
F_3 () ;
if ( V_87 )
F_11 ( V_87 ) ;
if ( V_100 )
F_11 ( V_100 ) ;
return error ;
}
int F_66 ( struct V_32 * V_33 , struct V_2 * V_3 ,
struct V_2 * V_99 )
{
return F_65 ( V_33 -> V_49 . V_50 -> V_51 , V_3 , V_99 ) ;
}
int F_67 ( struct V_32 * V_33 , struct V_2 * V_3 )
{
int error ;
F_68 () ;
for (; ; ) {
error = F_66 ( V_33 , V_3 , NULL ) ;
if ( error != V_98 )
break;
error = F_69 ( V_3 -> V_6 , ! V_3 -> V_70 ) ;
if ( ! error )
continue;
F_37 ( V_3 ) ;
break;
}
return error ;
}
int F_70 ( struct V_89 * V_89 )
{
T_3 V_107 = V_36 -> V_55 ;
struct V_2 * V_3 ;
F_1 () ;
for ( V_3 = V_89 -> V_82 ; V_3 != NULL ; V_3 = V_3 -> V_70 ) {
if ( ! F_40 ( V_3 ) )
continue;
if ( V_3 -> V_15 != V_107 )
break;
}
F_3 () ;
return V_3 ? - V_96 : 0 ;
}
int F_71 ( int V_108 , struct V_89 * V_89 ,
struct V_32 * V_33 , T_2 V_109 ,
T_4 V_110 )
{
struct V_2 V_3 ;
int error ;
F_16 ( & V_3 ) ;
V_3 . V_15 = V_36 -> V_55 ;
V_3 . V_16 = V_36 -> V_37 ;
V_3 . V_17 = V_33 ;
V_3 . V_18 = V_56 | V_91 ;
if ( V_33 && ! ( V_33 -> V_111 & V_112 ) )
V_3 . V_18 |= V_97 ;
V_3 . V_19 = ( V_108 == V_113 ) ? V_28 : V_26 ;
V_3 . V_20 = V_109 ;
V_3 . V_21 = V_109 + V_110 - 1 ;
for (; ; ) {
error = F_65 ( V_89 , & V_3 , NULL ) ;
if ( error != V_98 )
break;
error = F_69 ( V_3 . V_6 , ! V_3 . V_70 ) ;
if ( ! error ) {
if ( F_72 ( V_89 ) )
continue;
}
F_37 ( & V_3 ) ;
break;
}
return error ;
}
int F_73 ( struct V_2 * * V_88 , int V_114 )
{
struct V_2 * V_3 = * V_88 ;
int error = F_22 ( V_3 , V_114 ) ;
if ( error )
return error ;
F_42 ( V_3 ) ;
if ( V_114 == V_30 )
F_48 ( V_88 ) ;
return 0 ;
}
static void F_74 ( struct V_89 * V_89 )
{
struct V_2 * * V_88 ;
struct V_2 * V_3 ;
V_88 = & V_89 -> V_82 ;
while ( ( V_3 = * V_88 ) && F_63 ( V_3 ) && ( V_3 -> V_19 & V_115 ) ) {
if ( ( V_3 -> V_116 == 0 )
|| F_75 ( V_117 , V_3 -> V_116 ) ) {
V_88 = & V_3 -> V_70 ;
continue;
}
F_73 ( V_88 , V_3 -> V_19 & ~ V_115 ) ;
if ( V_3 == * V_88 )
V_88 = & V_3 -> V_70 ;
}
}
int F_76 ( struct V_89 * V_89 , unsigned int V_118 )
{
int error = 0 , V_119 ;
struct V_2 * V_87 , * V_40 ;
struct V_2 * V_3 ;
unsigned long V_120 ;
int V_121 = 0 ;
int V_122 = ( V_118 & V_123 ) != V_124 ;
V_87 = F_31 ( NULL , V_122 ? V_28 : V_26 ) ;
F_1 () ;
F_74 ( V_89 ) ;
V_40 = V_89 -> V_82 ;
if ( ( V_40 == NULL ) || ! F_63 ( V_40 ) )
goto V_93;
for ( V_3 = V_40 ; V_3 && F_63 ( V_3 ) ; V_3 = V_3 -> V_70 )
if ( V_3 -> V_15 == V_36 -> V_55 )
V_121 = 1 ;
if ( V_122 ) {
V_119 = V_30 | V_115 ;
} else if ( V_40 -> V_19 & V_115 ) {
V_119 = V_40 -> V_19 ;
} else if ( V_40 -> V_19 & V_28 ) {
V_119 = V_26 | V_115 ;
} else {
goto V_93;
}
if ( F_77 ( V_87 ) && ! V_121
&& ( ( V_118 & V_112 ) == 0 ) ) {
error = F_78 ( V_87 ) ;
goto V_93;
}
V_120 = 0 ;
if ( V_125 > 0 ) {
V_120 = V_117 + V_125 * V_126 ;
if ( V_120 == 0 )
V_120 ++ ;
}
for ( V_3 = V_40 ; V_3 && F_63 ( V_3 ) ; V_3 = V_3 -> V_70 ) {
if ( V_3 -> V_19 != V_119 ) {
V_3 -> V_19 = V_119 ;
V_3 -> V_116 = V_120 ;
V_3 -> V_11 -> V_127 ( V_3 ) ;
}
}
if ( V_121 || ( V_118 & V_112 ) ) {
error = - V_128 ;
goto V_93;
}
V_129:
V_120 = V_40 -> V_116 ;
if ( V_120 != 0 ) {
V_120 -= V_117 ;
if ( V_120 == 0 )
V_120 ++ ;
}
F_38 ( V_40 , V_87 ) ;
F_3 () ;
error = F_79 ( V_87 -> V_6 ,
! V_87 -> V_70 , V_120 ) ;
F_1 () ;
F_35 ( V_87 ) ;
if ( error >= 0 ) {
if ( error == 0 )
F_74 ( V_89 ) ;
for ( V_40 = V_89 -> V_82 ; V_40 && F_63 ( V_40 ) ;
V_40 = V_40 -> V_70 ) {
if ( V_40 -> V_19 & V_115 )
goto V_129;
}
error = 0 ;
}
V_93:
F_3 () ;
if ( ! F_77 ( V_87 ) )
F_11 ( V_87 ) ;
return error ;
}
void F_80 ( struct V_89 * V_89 , struct V_130 * time )
{
struct V_2 * V_40 = V_89 -> V_82 ;
if ( V_40 && F_63 ( V_40 ) && ( V_40 -> V_19 & V_28 ) )
* time = F_81 ( V_89 -> V_131 ) ;
else
* time = V_89 -> V_132 ;
}
int F_82 ( struct V_32 * V_33 )
{
struct V_2 * V_3 ;
int type = V_30 ;
F_1 () ;
F_74 ( V_33 -> V_49 . V_50 -> V_51 ) ;
for ( V_3 = V_33 -> V_49 . V_50 -> V_51 -> V_82 ; V_3 && F_63 ( V_3 ) ;
V_3 = V_3 -> V_70 ) {
if ( V_3 -> V_17 == V_33 ) {
type = V_3 -> V_19 & ~ V_115 ;
break;
}
}
F_3 () ;
return type ;
}
int F_83 ( struct V_32 * V_33 , long V_114 , struct V_2 * * V_133 )
{
struct V_2 * V_3 , * * V_88 , * * V_134 = NULL , * V_135 ;
struct V_50 * V_50 = V_33 -> V_49 . V_50 ;
struct V_89 * V_89 = V_50 -> V_51 ;
int error , V_136 = 0 , V_137 = 0 ;
V_135 = * V_133 ;
error = - V_138 ;
if ( ( F_84 () != V_89 -> V_139 ) && ! F_85 ( V_140 ) )
goto V_93;
error = - V_31 ;
if ( ! F_86 ( V_89 -> V_141 ) )
goto V_93;
error = F_87 ( V_33 , V_114 ) ;
if ( error )
goto V_93;
F_74 ( V_89 ) ;
F_12 ( ! ( * V_133 ) -> V_11 -> V_127 ) ;
if ( V_114 != V_30 ) {
error = - V_96 ;
if ( ( V_114 == V_26 ) && ( F_88 ( & V_89 -> V_142 ) > 0 ) )
goto V_93;
if ( ( V_114 == V_28 )
&& ( ( V_50 -> V_143 > 1 )
|| ( F_88 ( & V_89 -> V_144 ) > 1 ) ) )
goto V_93;
}
for ( V_88 = & V_89 -> V_82 ;
( ( V_3 = * V_88 ) != NULL ) && F_63 ( V_3 ) ;
V_88 = & V_3 -> V_70 ) {
if ( V_3 -> V_17 == V_33 )
V_134 = V_88 ;
else if ( V_3 -> V_19 == ( V_115 | V_30 ) )
V_137 ++ ;
else
V_136 ++ ;
}
error = - V_96 ;
if ( ( V_114 == V_26 && ( V_137 > 0 ) ) ||
( V_114 == V_28 && ( ( V_136 + V_137 ) > 0 ) ) )
goto V_93;
if ( V_134 != NULL ) {
error = V_135 -> V_11 -> V_145 ( V_134 , V_114 ) ;
if ( ! error )
* V_133 = * V_134 ;
goto V_93;
}
if ( V_114 == V_30 )
goto V_93;
error = - V_31 ;
if ( ! V_146 )
goto V_93;
F_45 ( V_88 , V_135 ) ;
return 0 ;
V_93:
return error ;
}
static int F_89 ( struct V_32 * V_33 , long V_114 , struct V_2 * * V_135 )
{
if ( V_33 -> V_147 && V_33 -> V_147 -> V_148 )
return V_33 -> V_147 -> V_148 ( V_33 , V_114 , V_135 ) ;
else
return F_83 ( V_33 , V_114 , V_135 ) ;
}
int F_90 ( struct V_32 * V_33 , long V_114 , struct V_2 * * V_135 )
{
int error ;
F_1 () ;
error = F_89 ( V_33 , V_114 , V_135 ) ;
F_3 () ;
return error ;
}
static int F_91 ( struct V_32 * V_33 )
{
struct V_2 V_3 , * V_133 = & V_3 ;
F_30 ( V_33 , V_30 , V_133 ) ;
return F_90 ( V_33 , V_30 , & V_133 ) ;
}
static int F_92 ( unsigned int V_149 , struct V_32 * V_33 , long V_114 )
{
struct V_2 * V_3 , * V_150 ;
struct V_151 * V_13 ;
int error ;
V_3 = F_31 ( V_33 , V_114 ) ;
if ( F_77 ( V_3 ) )
return F_78 ( V_3 ) ;
V_13 = F_93 () ;
if ( ! V_13 ) {
F_11 ( V_3 ) ;
return - V_35 ;
}
V_150 = V_3 ;
F_1 () ;
error = F_89 ( V_33 , V_114 , & V_150 ) ;
if ( error ) {
F_3 () ;
F_11 ( V_3 ) ;
goto V_152;
}
if ( V_150 != V_3 )
F_11 ( V_3 ) ;
if ( ! F_94 ( V_149 , V_33 , & V_150 -> V_59 , V_13 ) )
V_13 = NULL ;
error = F_95 ( V_33 , F_96 ( V_36 ) , V_153 , 0 ) ;
F_3 () ;
V_152:
if ( V_13 )
F_97 ( V_13 ) ;
return error ;
}
int F_98 ( unsigned int V_149 , struct V_32 * V_33 , long V_114 )
{
if ( V_114 == V_30 )
return F_91 ( V_33 ) ;
return F_92 ( V_149 , V_33 , V_114 ) ;
}
int F_99 ( struct V_32 * V_33 , struct V_2 * V_3 )
{
int error ;
F_68 () ;
for (; ; ) {
error = F_61 ( V_33 , V_3 ) ;
if ( error != V_98 )
break;
error = F_69 ( V_3 -> V_6 , ! V_3 -> V_70 ) ;
if ( ! error )
continue;
F_37 ( V_3 ) ;
break;
}
return error ;
}
int F_100 ( struct V_32 * V_33 , struct V_2 * V_3 )
{
if ( V_33 -> V_147 && V_33 -> V_147 -> V_34 )
return V_33 -> V_147 -> V_34 ( V_33 , V_154 , V_3 ) ;
F_56 ( V_33 , V_3 ) ;
return 0 ;
}
static int F_101 ( struct V_40 * V_40 , struct V_2 * V_3 )
{
V_40 -> V_155 = V_3 -> V_16 ;
#if V_156 == 32
if ( V_3 -> V_20 > V_157 )
return - V_54 ;
if ( V_3 -> V_21 != V_39 && V_3 -> V_21 > V_157 )
return - V_54 ;
#endif
V_40 -> V_52 = V_3 -> V_20 ;
V_40 -> V_53 = V_3 -> V_21 == V_39 ? 0 :
V_3 -> V_21 - V_3 -> V_20 + 1 ;
V_40 -> V_44 = 0 ;
V_40 -> V_57 = V_3 -> V_19 ;
return 0 ;
}
static void F_102 ( struct V_58 * V_40 , struct V_2 * V_3 )
{
V_40 -> V_155 = V_3 -> V_16 ;
V_40 -> V_52 = V_3 -> V_20 ;
V_40 -> V_53 = V_3 -> V_21 == V_39 ? 0 :
V_3 -> V_21 - V_3 -> V_20 + 1 ;
V_40 -> V_44 = 0 ;
V_40 -> V_57 = V_3 -> V_19 ;
}
int F_103 ( struct V_32 * V_33 , struct V_40 T_5 * V_41 )
{
struct V_2 V_2 ;
struct V_40 V_40 ;
int error ;
error = - V_158 ;
if ( F_104 ( & V_40 , V_41 , sizeof( V_40 ) ) )
goto V_93;
error = - V_31 ;
if ( ( V_40 . V_57 != V_26 ) && ( V_40 . V_57 != V_28 ) )
goto V_93;
error = F_23 ( V_33 , & V_2 , & V_40 ) ;
if ( error )
goto V_93;
error = F_100 ( V_33 , & V_2 ) ;
if ( error )
goto V_93;
V_40 . V_57 = V_2 . V_19 ;
if ( V_2 . V_19 != V_30 ) {
error = F_101 ( & V_40 , & V_2 ) ;
if ( error )
goto V_93;
}
error = - V_158 ;
if ( ! F_105 ( V_41 , & V_40 , sizeof( V_40 ) ) )
error = 0 ;
V_93:
return error ;
}
int F_106 ( struct V_32 * V_33 , unsigned int V_22 , struct V_2 * V_3 , struct V_2 * V_159 )
{
if ( V_33 -> V_147 && V_33 -> V_147 -> V_34 )
return V_33 -> V_147 -> V_34 ( V_33 , V_22 , V_3 ) ;
else
return F_66 ( V_33 , V_3 , V_159 ) ;
}
static int F_107 ( struct V_32 * V_33 , unsigned int V_22 ,
struct V_2 * V_3 )
{
int error ;
error = F_87 ( V_33 , V_3 -> V_19 ) ;
if ( error )
return error ;
for (; ; ) {
error = F_106 ( V_33 , V_22 , V_3 , NULL ) ;
if ( error != V_98 )
break;
error = F_69 ( V_3 -> V_6 , ! V_3 -> V_70 ) ;
if ( ! error )
continue;
F_37 ( V_3 ) ;
break;
}
return error ;
}
int F_108 ( unsigned int V_149 , struct V_32 * V_33 , unsigned int V_22 ,
struct V_40 T_5 * V_41 )
{
struct V_2 * V_2 = F_8 () ;
struct V_40 V_40 ;
struct V_89 * V_89 ;
struct V_32 * V_160 ;
int error ;
if ( V_2 == NULL )
return - V_106 ;
error = - V_158 ;
if ( F_104 ( & V_40 , V_41 , sizeof( V_40 ) ) )
goto V_93;
V_89 = V_33 -> V_49 . V_50 -> V_51 ;
if ( F_109 ( V_89 ) && F_110 ( V_33 -> V_161 ) ) {
error = - V_96 ;
goto V_93;
}
V_162:
error = F_23 ( V_33 , V_2 , & V_40 ) ;
if ( error )
goto V_93;
if ( V_22 == V_163 ) {
V_2 -> V_18 |= V_97 ;
}
error = - V_164 ;
switch ( V_40 . V_57 ) {
case V_26 :
if ( ! ( V_33 -> V_165 & V_166 ) )
goto V_93;
break;
case V_28 :
if ( ! ( V_33 -> V_165 & V_167 ) )
goto V_93;
break;
case V_30 :
break;
default:
error = - V_31 ;
goto V_93;
}
error = F_107 ( V_33 , V_22 , V_2 ) ;
F_2 ( & V_36 -> V_55 -> V_2 ) ;
V_160 = F_111 ( V_149 ) ;
F_4 ( & V_36 -> V_55 -> V_2 ) ;
if ( ! error && V_160 != V_33 && V_40 . V_57 != V_30 ) {
V_40 . V_57 = V_30 ;
goto V_162;
}
V_93:
F_11 ( V_2 ) ;
return error ;
}
int F_112 ( struct V_32 * V_33 , struct V_58 T_5 * V_41 )
{
struct V_2 V_2 ;
struct V_58 V_40 ;
int error ;
error = - V_158 ;
if ( F_104 ( & V_40 , V_41 , sizeof( V_40 ) ) )
goto V_93;
error = - V_31 ;
if ( ( V_40 . V_57 != V_26 ) && ( V_40 . V_57 != V_28 ) )
goto V_93;
error = F_25 ( V_33 , & V_2 , & V_40 ) ;
if ( error )
goto V_93;
error = F_100 ( V_33 , & V_2 ) ;
if ( error )
goto V_93;
V_40 . V_57 = V_2 . V_19 ;
if ( V_2 . V_19 != V_30 )
F_102 ( & V_40 , & V_2 ) ;
error = - V_158 ;
if ( ! F_105 ( V_41 , & V_40 , sizeof( V_40 ) ) )
error = 0 ;
V_93:
return error ;
}
int F_113 ( unsigned int V_149 , struct V_32 * V_33 , unsigned int V_22 ,
struct V_58 T_5 * V_41 )
{
struct V_2 * V_2 = F_8 () ;
struct V_58 V_40 ;
struct V_89 * V_89 ;
struct V_32 * V_160 ;
int error ;
if ( V_2 == NULL )
return - V_106 ;
error = - V_158 ;
if ( F_104 ( & V_40 , V_41 , sizeof( V_40 ) ) )
goto V_93;
V_89 = V_33 -> V_49 . V_50 -> V_51 ;
if ( F_109 ( V_89 ) && F_110 ( V_33 -> V_161 ) ) {
error = - V_96 ;
goto V_93;
}
V_162:
error = F_25 ( V_33 , V_2 , & V_40 ) ;
if ( error )
goto V_93;
if ( V_22 == V_168 ) {
V_2 -> V_18 |= V_97 ;
}
error = - V_164 ;
switch ( V_40 . V_57 ) {
case V_26 :
if ( ! ( V_33 -> V_165 & V_166 ) )
goto V_93;
break;
case V_28 :
if ( ! ( V_33 -> V_165 & V_167 ) )
goto V_93;
break;
case V_30 :
break;
default:
error = - V_31 ;
goto V_93;
}
error = F_107 ( V_33 , V_22 , V_2 ) ;
F_2 ( & V_36 -> V_55 -> V_2 ) ;
V_160 = F_111 ( V_149 ) ;
F_4 ( & V_36 -> V_55 -> V_2 ) ;
if ( ! error && V_160 != V_33 && V_40 . V_57 != V_30 ) {
V_40 . V_57 = V_30 ;
goto V_162;
}
V_93:
F_11 ( V_2 ) ;
return error ;
}
void F_114 ( struct V_32 * V_33 , T_3 V_107 )
{
struct V_2 V_34 ;
if ( ! V_33 -> V_49 . V_50 -> V_51 -> V_82 )
return;
V_34 . V_19 = V_30 ;
V_34 . V_18 = V_56 | V_169 ;
V_34 . V_20 = 0 ;
V_34 . V_21 = V_39 ;
V_34 . V_15 = V_107 ;
V_34 . V_16 = V_36 -> V_37 ;
V_34 . V_17 = V_33 ;
V_34 . V_9 = NULL ;
V_34 . V_11 = NULL ;
F_106 ( V_33 , V_170 , & V_34 , NULL ) ;
if ( V_34 . V_9 && V_34 . V_9 -> V_10 )
V_34 . V_9 -> V_10 ( & V_34 ) ;
}
void F_115 ( struct V_32 * V_33 )
{
struct V_89 * V_89 = V_33 -> V_49 . V_50 -> V_51 ;
struct V_2 * V_3 ;
struct V_2 * * V_88 ;
if ( ! V_89 -> V_82 )
return;
if ( V_33 -> V_147 && V_33 -> V_147 -> V_40 ) {
struct V_2 V_3 = {
. V_16 = V_36 -> V_37 ,
. V_17 = V_33 ,
. V_18 = V_38 ,
. V_19 = V_30 ,
. V_21 = V_39 ,
} ;
V_33 -> V_147 -> V_40 ( V_33 , V_163 , & V_3 ) ;
if ( V_3 . V_9 && V_3 . V_9 -> V_10 )
V_3 . V_9 -> V_10 ( & V_3 ) ;
}
F_1 () ;
V_88 = & V_89 -> V_82 ;
while ( ( V_3 = * V_88 ) != NULL ) {
if ( V_3 -> V_17 == V_33 ) {
if ( F_55 ( V_3 ) ) {
F_48 ( V_88 ) ;
continue;
}
if ( F_63 ( V_3 ) ) {
F_73 ( V_88 , V_30 ) ;
continue;
}
F_116 () ;
}
V_88 = & V_3 -> V_70 ;
}
F_3 () ;
}
int
F_117 ( struct V_32 * V_33 , struct V_2 * V_69 )
{
int V_171 = 0 ;
F_1 () ;
if ( V_69 -> V_70 )
F_35 ( V_69 ) ;
else
V_171 = - V_95 ;
F_3 () ;
return V_171 ;
}
int F_118 ( struct V_32 * V_33 , struct V_2 * V_3 )
{
if ( V_33 -> V_147 && V_33 -> V_147 -> V_34 )
return V_33 -> V_147 -> V_34 ( V_33 , V_172 , V_3 ) ;
return 0 ;
}
static void F_119 ( struct V_173 * V_160 , struct V_2 * V_3 ,
T_2 V_174 , char * V_175 )
{
struct V_89 * V_89 = NULL ;
unsigned int V_16 ;
if ( V_3 -> V_76 )
V_16 = F_57 ( V_3 -> V_76 ) ;
else
V_16 = V_3 -> V_16 ;
if ( V_3 -> V_17 != NULL )
V_89 = V_3 -> V_17 -> V_49 . V_50 -> V_51 ;
F_120 ( V_160 , L_2 , V_174 , V_175 ) ;
if ( F_40 ( V_3 ) ) {
F_120 ( V_160 , L_3 ,
( V_3 -> V_18 & V_91 ) ? L_4 : L_5 ,
( V_89 == NULL ) ? L_6 :
F_109 ( V_89 ) ? L_7 : L_8 ) ;
} else if ( F_55 ( V_3 ) ) {
if ( V_3 -> V_19 & V_23 ) {
F_120 ( V_160 , L_9 ) ;
} else {
F_120 ( V_160 , L_10 ) ;
}
} else if ( F_63 ( V_3 ) ) {
F_120 ( V_160 , L_11 ) ;
if ( V_3 -> V_19 & V_115 )
F_120 ( V_160 , L_12 ) ;
else if ( V_3 -> V_17 )
F_120 ( V_160 , L_13 ) ;
else
F_120 ( V_160 , L_14 ) ;
} else {
F_120 ( V_160 , L_15 ) ;
}
if ( V_3 -> V_19 & V_23 ) {
F_120 ( V_160 , L_16 ,
( V_3 -> V_19 & V_176 )
? ( V_3 -> V_19 & V_177 ) ? L_17 : L_18
: ( V_3 -> V_19 & V_177 ) ? L_19 : L_20 ) ;
} else {
F_120 ( V_160 , L_16 ,
( V_3 -> V_19 & V_115 )
? ( V_3 -> V_19 & V_30 ) ? L_21 : L_18
: ( V_3 -> V_19 & V_28 ) ? L_19 : L_18 ) ;
}
if ( V_89 ) {
#ifdef F_121
F_120 ( V_160 , L_22 , V_16 ,
V_89 -> V_131 -> V_178 , V_89 -> V_179 ) ;
#else
F_120 ( V_160 , L_23 , V_16 ,
F_122 ( V_89 -> V_131 -> V_180 ) ,
F_123 ( V_89 -> V_131 -> V_180 ) , V_89 -> V_179 ) ;
#endif
} else {
F_120 ( V_160 , L_24 , V_16 ) ;
}
if ( F_40 ( V_3 ) ) {
if ( V_3 -> V_21 == V_39 )
F_120 ( V_160 , L_25 , V_3 -> V_20 ) ;
else
F_120 ( V_160 , L_26 , V_3 -> V_20 , V_3 -> V_21 ) ;
} else {
F_120 ( V_160 , L_27 ) ;
}
}
static int F_124 ( struct V_173 * V_160 , void * V_181 )
{
struct V_2 * V_3 , * V_182 ;
V_3 = F_125 ( V_181 , struct V_2 , V_4 ) ;
F_119 ( V_160 , V_3 , * ( ( T_2 * ) V_160 -> V_183 ) , L_28 ) ;
F_59 (bfl, &fl->fl_block, fl_block)
F_119 ( V_160 , V_182 , * ( ( T_2 * ) V_160 -> V_183 ) , L_29 ) ;
return 0 ;
}
static void * F_126 ( struct V_173 * V_160 , T_2 * V_74 )
{
T_2 * V_184 = V_160 -> V_183 ;
F_1 () ;
* V_184 = ( * V_74 + 1 ) ;
return F_127 ( & V_75 , * V_74 ) ;
}
static void * F_128 ( struct V_173 * V_160 , void * V_181 , T_2 * V_74 )
{
T_2 * V_184 = V_160 -> V_183 ;
++ * V_184 ;
return F_129 ( V_181 , & V_75 , V_74 ) ;
}
static void F_130 ( struct V_173 * V_160 , void * V_181 )
{
F_3 () ;
}
static int F_131 ( struct V_89 * V_89 , struct V_32 * V_33 )
{
return F_132 ( V_33 , & V_185 , sizeof( T_2 ) ) ;
}
static int T_6 F_133 ( void )
{
F_134 ( L_30 , 0 , NULL , & V_186 ) ;
return 0 ;
}
int F_135 ( struct V_89 * V_89 , T_2 V_42 , unsigned long V_187 )
{
struct V_2 * V_3 ;
int V_188 = 1 ;
F_1 () ;
for ( V_3 = V_89 -> V_82 ; V_3 != NULL ; V_3 = V_3 -> V_70 ) {
if ( F_40 ( V_3 ) ) {
if ( V_3 -> V_19 == V_26 )
continue;
if ( ( V_3 -> V_21 < V_42 ) || ( V_3 -> V_20 > ( V_42 + V_187 ) ) )
continue;
} else if ( F_55 ( V_3 ) ) {
if ( ! ( V_3 -> V_19 & V_23 ) )
continue;
if ( V_3 -> V_19 & V_176 )
continue;
} else
continue;
V_188 = 0 ;
break;
}
F_3 () ;
return V_188 ;
}
int F_136 ( struct V_89 * V_89 , T_2 V_42 , unsigned long V_187 )
{
struct V_2 * V_3 ;
int V_188 = 1 ;
F_1 () ;
for ( V_3 = V_89 -> V_82 ; V_3 != NULL ; V_3 = V_3 -> V_70 ) {
if ( F_40 ( V_3 ) ) {
if ( ( V_3 -> V_21 < V_42 ) || ( V_3 -> V_20 > ( V_42 + V_187 ) ) )
continue;
} else if ( F_55 ( V_3 ) ) {
if ( ! ( V_3 -> V_19 & V_23 ) )
continue;
if ( V_3 -> V_19 & V_177 )
continue;
} else
continue;
V_188 = 0 ;
break;
}
F_3 () ;
return V_188 ;
}
static int T_6 F_137 ( void )
{
V_7 = F_138 ( L_31 ,
sizeof( struct V_2 ) , 0 , V_189 , NULL ) ;
return 0 ;
}
