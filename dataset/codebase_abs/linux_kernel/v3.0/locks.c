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
V_3 -> V_4 = NULL ;
V_3 -> V_5 = NULL ;
V_3 -> V_6 = NULL ;
V_3 -> V_7 = 0 ;
V_3 -> V_8 = NULL ;
V_3 -> V_9 = NULL ;
V_3 -> V_10 = 0 ;
V_3 -> V_11 = 0 ;
V_3 -> V_12 = V_3 -> V_13 = 0 ;
}
struct V_2 * F_6 ( void )
{
struct V_2 * V_3 = F_7 ( V_14 , V_15 ) ;
if ( V_3 )
F_5 ( V_3 ) ;
return V_3 ;
}
void F_8 ( struct V_2 * V_3 )
{
if ( V_3 -> V_16 ) {
if ( V_3 -> V_16 -> V_17 )
V_3 -> V_16 -> V_17 ( V_3 ) ;
V_3 -> V_16 = NULL ;
}
if ( V_3 -> V_18 ) {
if ( V_3 -> V_18 -> V_17 )
V_3 -> V_18 -> V_17 ( V_3 ) ;
V_3 -> V_18 = NULL ;
}
}
void F_9 ( struct V_2 * V_3 )
{
F_10 ( F_11 ( & V_3 -> V_19 ) ) ;
F_10 ( ! F_12 ( & V_3 -> V_20 ) ) ;
F_10 ( ! F_12 ( & V_3 -> V_21 ) ) ;
F_8 ( V_3 ) ;
F_13 ( V_14 , V_3 ) ;
}
void F_14 ( struct V_2 * V_3 )
{
F_15 ( & V_3 -> V_21 ) ;
F_15 ( & V_3 -> V_20 ) ;
F_16 ( & V_3 -> V_19 ) ;
V_3 -> V_16 = NULL ;
V_3 -> V_18 = NULL ;
F_5 ( V_3 ) ;
}
static void F_17 ( void * V_22 )
{
struct V_2 * V_23 = (struct V_2 * ) V_22 ;
F_14 ( V_23 ) ;
}
static void F_18 ( struct V_2 * V_24 , struct V_2 * V_3 )
{
if ( V_3 -> V_16 ) {
if ( V_3 -> V_16 -> V_25 )
V_3 -> V_16 -> V_25 ( V_24 , V_3 ) ;
V_24 -> V_16 = V_3 -> V_16 ;
}
if ( V_3 -> V_18 )
V_24 -> V_18 = V_3 -> V_18 ;
}
void F_19 ( struct V_2 * V_24 , const struct V_2 * V_3 )
{
V_24 -> V_6 = V_3 -> V_6 ;
V_24 -> V_7 = V_3 -> V_7 ;
V_24 -> V_9 = NULL ;
V_24 -> V_10 = V_3 -> V_10 ;
V_24 -> V_11 = V_3 -> V_11 ;
V_24 -> V_12 = V_3 -> V_12 ;
V_24 -> V_13 = V_3 -> V_13 ;
V_24 -> V_16 = NULL ;
V_24 -> V_18 = NULL ;
}
void F_20 ( struct V_2 * V_24 , struct V_2 * V_3 )
{
F_8 ( V_24 ) ;
F_19 ( V_24 , V_3 ) ;
V_24 -> V_9 = V_3 -> V_9 ;
V_24 -> V_16 = V_3 -> V_16 ;
V_24 -> V_18 = V_3 -> V_18 ;
F_18 ( V_24 , V_3 ) ;
}
static inline int F_21 ( int V_26 ) {
if ( V_26 & V_27 )
return V_26 & ( V_27 | V_28 ) ;
switch ( V_26 ) {
case V_29 :
return V_30 ;
case V_31 :
return V_32 ;
case V_33 :
return V_34 ;
}
return - V_35 ;
}
static int F_22 ( struct V_36 * V_37 , struct V_2 * * V_23 ,
unsigned int V_26 )
{
struct V_2 * V_3 ;
int type = F_21 ( V_26 ) ;
if ( type < 0 )
return type ;
V_3 = F_6 () ;
if ( V_3 == NULL )
return - V_38 ;
V_3 -> V_9 = V_37 ;
V_3 -> V_7 = V_39 -> V_40 ;
V_3 -> V_10 = V_41 ;
V_3 -> V_11 = type ;
V_3 -> V_13 = V_42 ;
* V_23 = V_3 ;
return 0 ;
}
static int F_23 ( struct V_2 * V_3 , int type )
{
switch ( type ) {
case V_30 :
case V_32 :
case V_34 :
V_3 -> V_11 = type ;
break;
default:
return - V_35 ;
}
return 0 ;
}
static int F_24 ( struct V_36 * V_37 , struct V_2 * V_3 ,
struct V_43 * V_44 )
{
T_1 V_45 , V_46 ;
switch ( V_44 -> V_47 ) {
case V_48 :
V_45 = 0 ;
break;
case V_49 :
V_45 = V_37 -> V_50 ;
break;
case V_51 :
V_45 = F_25 ( V_37 -> V_52 . V_53 -> V_54 ) ;
break;
default:
return - V_35 ;
}
V_45 += V_44 -> V_55 ;
if ( V_45 < 0 )
return - V_35 ;
V_3 -> V_13 = V_42 ;
if ( V_44 -> V_56 > 0 ) {
V_46 = V_45 + V_44 -> V_56 - 1 ;
V_3 -> V_13 = V_46 ;
} else if ( V_44 -> V_56 < 0 ) {
V_46 = V_45 - 1 ;
V_3 -> V_13 = V_46 ;
V_45 += V_44 -> V_56 ;
if ( V_45 < 0 )
return - V_35 ;
}
V_3 -> V_12 = V_45 ;
if ( V_3 -> V_13 < V_3 -> V_12 )
return - V_57 ;
V_3 -> V_6 = V_39 -> V_58 ;
V_3 -> V_7 = V_39 -> V_40 ;
V_3 -> V_9 = V_37 ;
V_3 -> V_10 = V_59 ;
V_3 -> V_16 = NULL ;
V_3 -> V_18 = NULL ;
return F_23 ( V_3 , V_44 -> V_60 ) ;
}
static int F_26 ( struct V_36 * V_37 , struct V_2 * V_3 ,
struct V_61 * V_44 )
{
T_2 V_45 ;
switch ( V_44 -> V_47 ) {
case V_48 :
V_45 = 0 ;
break;
case V_49 :
V_45 = V_37 -> V_50 ;
break;
case V_51 :
V_45 = F_25 ( V_37 -> V_52 . V_53 -> V_54 ) ;
break;
default:
return - V_35 ;
}
V_45 += V_44 -> V_55 ;
if ( V_45 < 0 )
return - V_35 ;
V_3 -> V_13 = V_42 ;
if ( V_44 -> V_56 > 0 ) {
V_3 -> V_13 = V_45 + V_44 -> V_56 - 1 ;
} else if ( V_44 -> V_56 < 0 ) {
V_3 -> V_13 = V_45 - 1 ;
V_45 += V_44 -> V_56 ;
if ( V_45 < 0 )
return - V_35 ;
}
V_3 -> V_12 = V_45 ;
if ( V_3 -> V_13 < V_3 -> V_12 )
return - V_57 ;
V_3 -> V_6 = V_39 -> V_58 ;
V_3 -> V_7 = V_39 -> V_40 ;
V_3 -> V_9 = V_37 ;
V_3 -> V_10 = V_59 ;
V_3 -> V_16 = NULL ;
V_3 -> V_18 = NULL ;
return F_23 ( V_3 , V_44 -> V_60 ) ;
}
static void F_27 ( struct V_2 * V_3 )
{
F_28 ( & V_3 -> V_5 , V_62 , V_63 ) ;
}
static void F_29 ( struct V_2 * V_3 )
{
if ( ! V_3 -> V_9 )
return;
F_30 ( V_3 -> V_9 ) ;
V_3 -> V_9 -> V_64 . V_65 = 0 ;
}
static int F_31 ( struct V_36 * V_37 , int type , struct V_2 * V_3 )
{
if ( F_23 ( V_3 , type ) != 0 )
return - V_35 ;
V_3 -> V_6 = V_39 -> V_58 ;
V_3 -> V_7 = V_39 -> V_40 ;
V_3 -> V_9 = V_37 ;
V_3 -> V_10 = V_66 ;
V_3 -> V_12 = 0 ;
V_3 -> V_13 = V_42 ;
V_3 -> V_16 = NULL ;
V_3 -> V_18 = & V_67 ;
return 0 ;
}
static struct V_2 * F_32 ( struct V_36 * V_37 , int type )
{
struct V_2 * V_3 = F_6 () ;
int error = - V_38 ;
if ( V_3 == NULL )
return F_33 ( error ) ;
error = F_31 ( V_37 , type , V_3 ) ;
if ( error ) {
F_9 ( V_3 ) ;
return F_33 ( error ) ;
}
return V_3 ;
}
static inline int F_34 ( struct V_2 * V_68 , struct V_2 * V_69 )
{
return ( ( V_68 -> V_13 >= V_69 -> V_12 ) &&
( V_69 -> V_13 >= V_68 -> V_12 ) ) ;
}
static int F_35 ( struct V_2 * V_68 , struct V_2 * V_69 )
{
if ( V_68 -> V_18 && V_68 -> V_18 -> V_70 )
return V_69 -> V_18 == V_68 -> V_18 &&
V_68 -> V_18 -> V_70 ( V_68 , V_69 ) ;
return V_68 -> V_6 == V_69 -> V_6 ;
}
static void F_36 ( struct V_2 * V_71 )
{
F_37 ( & V_71 -> V_20 ) ;
F_37 ( & V_71 -> V_21 ) ;
V_71 -> V_4 = NULL ;
}
static void F_38 ( struct V_2 * V_71 )
{
F_1 () ;
F_36 ( V_71 ) ;
F_3 () ;
}
static void F_39 ( struct V_2 * V_72 ,
struct V_2 * V_71 )
{
F_10 ( ! F_12 ( & V_71 -> V_20 ) ) ;
F_40 ( & V_71 -> V_20 , & V_72 -> V_20 ) ;
V_71 -> V_4 = V_72 ;
if ( F_41 ( V_72 ) )
F_42 ( & V_71 -> V_21 , & V_73 ) ;
}
static void F_43 ( struct V_2 * V_72 )
{
while ( ! F_12 ( & V_72 -> V_20 ) ) {
struct V_2 * V_71 ;
V_71 = F_44 ( & V_72 -> V_20 ,
struct V_2 , V_20 ) ;
F_36 ( V_71 ) ;
if ( V_71 -> V_18 && V_71 -> V_18 -> V_74 )
V_71 -> V_18 -> V_74 ( V_71 ) ;
else
F_45 ( & V_71 -> V_19 ) ;
}
}
static void F_46 ( struct V_2 * * V_75 , struct V_2 * V_3 )
{
F_42 ( & V_3 -> V_21 , & V_76 ) ;
V_3 -> V_8 = F_47 ( F_48 ( V_39 ) ) ;
V_3 -> V_4 = * V_75 ;
* V_75 = V_3 ;
}
static void F_49 ( struct V_2 * * V_77 )
{
struct V_2 * V_3 = * V_77 ;
* V_77 = V_3 -> V_4 ;
V_3 -> V_4 = NULL ;
F_37 ( & V_3 -> V_21 ) ;
F_50 ( 0 , V_3 -> V_9 , 0 , & V_3 -> V_5 ) ;
if ( V_3 -> V_5 != NULL ) {
F_51 ( V_78 L_1 , V_3 -> V_5 ) ;
V_3 -> V_5 = NULL ;
}
if ( V_3 -> V_8 ) {
F_52 ( V_3 -> V_8 ) ;
V_3 -> V_8 = NULL ;
}
F_43 ( V_3 ) ;
F_9 ( V_3 ) ;
}
static int F_53 ( struct V_2 * V_79 , struct V_2 * V_80 )
{
if ( V_80 -> V_11 == V_32 )
return 1 ;
if ( V_79 -> V_11 == V_32 )
return 1 ;
return 0 ;
}
static int F_54 ( struct V_2 * V_79 , struct V_2 * V_80 )
{
if ( ! F_41 ( V_80 ) || F_35 ( V_79 , V_80 ) )
return ( 0 ) ;
if ( ! F_34 ( V_79 , V_80 ) )
return 0 ;
return ( F_53 ( V_79 , V_80 ) ) ;
}
static int F_55 ( struct V_2 * V_79 , struct V_2 * V_80 )
{
if ( ! F_56 ( V_80 ) || ( V_79 -> V_9 == V_80 -> V_9 ) )
return ( 0 ) ;
if ( ( V_79 -> V_11 & V_27 ) || ( V_80 -> V_11 & V_27 ) )
return 0 ;
return ( F_53 ( V_79 , V_80 ) ) ;
}
void
F_57 ( struct V_36 * V_37 , struct V_2 * V_3 )
{
struct V_2 * V_81 ;
F_1 () ;
for ( V_81 = V_37 -> V_52 . V_53 -> V_54 -> V_82 ; V_81 ; V_81 = V_81 -> V_4 ) {
if ( ! F_41 ( V_81 ) )
continue;
if ( F_54 ( V_3 , V_81 ) )
break;
}
if ( V_81 ) {
F_19 ( V_3 , V_81 ) ;
if ( V_81 -> V_8 )
V_3 -> V_7 = F_58 ( V_81 -> V_8 ) ;
} else
V_3 -> V_11 = V_34 ;
F_3 () ;
return;
}
static struct V_2 * F_59 ( struct V_2 * V_83 )
{
struct V_2 * V_3 ;
F_60 (fl, &blocked_list, fl_link) {
if ( F_35 ( V_3 , V_83 ) )
return V_3 -> V_4 ;
}
return NULL ;
}
static int F_61 ( struct V_2 * V_79 ,
struct V_2 * V_83 )
{
int V_84 = 0 ;
while ( ( V_83 = F_59 ( V_83 ) ) ) {
if ( V_84 ++ > V_85 )
return 0 ;
if ( F_35 ( V_79 , V_83 ) )
return 1 ;
}
return 0 ;
}
static int F_62 ( struct V_36 * V_37 , struct V_2 * V_86 )
{
struct V_2 * V_87 = NULL ;
struct V_2 * * V_88 ;
struct V_89 * V_89 = V_37 -> V_52 . V_53 -> V_54 ;
int error = 0 ;
int V_90 = 0 ;
if ( ! ( V_86 -> V_10 & V_91 ) && ( V_86 -> V_11 != V_34 ) ) {
V_87 = F_6 () ;
if ( ! V_87 )
return - V_38 ;
}
F_1 () ;
if ( V_86 -> V_10 & V_91 )
goto V_92;
F_63 (inode, before) {
struct V_2 * V_3 = * V_88 ;
if ( F_41 ( V_3 ) )
break;
if ( F_64 ( V_3 ) )
continue;
if ( V_37 != V_3 -> V_9 )
continue;
if ( V_86 -> V_11 == V_3 -> V_11 )
goto V_93;
V_90 = 1 ;
F_49 ( V_88 ) ;
break;
}
if ( V_86 -> V_11 == V_34 ) {
if ( ( V_86 -> V_10 & V_94 ) && ! V_90 )
error = - V_95 ;
goto V_93;
}
if ( V_90 ) {
F_3 () ;
F_65 () ;
F_1 () ;
}
V_92:
F_63 (inode, before) {
struct V_2 * V_3 = * V_88 ;
if ( F_41 ( V_3 ) )
break;
if ( F_64 ( V_3 ) )
continue;
if ( ! F_55 ( V_86 , V_3 ) )
continue;
error = - V_96 ;
if ( ! ( V_86 -> V_10 & V_97 ) )
goto V_93;
error = V_98 ;
F_39 ( V_3 , V_86 ) ;
goto V_93;
}
if ( V_86 -> V_10 & V_91 )
goto V_93;
F_20 ( V_87 , V_86 ) ;
F_46 ( V_88 , V_87 ) ;
V_87 = NULL ;
error = 0 ;
V_93:
F_3 () ;
if ( V_87 )
F_9 ( V_87 ) ;
return error ;
}
static int F_66 ( struct V_89 * V_89 , struct V_2 * V_86 , struct V_2 * V_99 )
{
struct V_2 * V_3 ;
struct V_2 * V_87 = NULL ;
struct V_2 * V_100 = NULL ;
struct V_2 * V_101 = NULL ;
struct V_2 * V_102 = NULL ;
struct V_2 * * V_88 ;
int error , V_103 = 0 ;
if ( ! ( V_86 -> V_10 & V_91 ) &&
( V_86 -> V_11 != V_34 ||
V_86 -> V_12 != 0 || V_86 -> V_13 != V_42 ) ) {
V_87 = F_6 () ;
V_100 = F_6 () ;
}
F_1 () ;
if ( V_86 -> V_11 != V_34 ) {
F_63 (inode, before) {
V_3 = * V_88 ;
if ( ! F_41 ( V_3 ) )
continue;
if ( ! F_54 ( V_86 , V_3 ) )
continue;
if ( V_99 )
F_19 ( V_99 , V_3 ) ;
error = - V_96 ;
if ( ! ( V_86 -> V_10 & V_97 ) )
goto V_93;
error = - V_104 ;
if ( F_61 ( V_86 , V_3 ) )
goto V_93;
error = V_98 ;
F_39 ( V_3 , V_86 ) ;
goto V_93;
}
}
error = 0 ;
if ( V_86 -> V_10 & V_91 )
goto V_93;
V_88 = & V_89 -> V_82 ;
while ( ( V_3 = * V_88 ) && ( ! F_41 ( V_3 ) ||
! F_35 ( V_86 , V_3 ) ) ) {
V_88 = & V_3 -> V_4 ;
}
while ( ( V_3 = * V_88 ) && F_35 ( V_86 , V_3 ) ) {
if ( V_86 -> V_11 == V_3 -> V_11 ) {
if ( V_3 -> V_13 < V_86 -> V_12 - 1 )
goto V_105;
if ( V_3 -> V_12 - 1 > V_86 -> V_13 )
break;
if ( V_3 -> V_12 > V_86 -> V_12 )
V_3 -> V_12 = V_86 -> V_12 ;
else
V_86 -> V_12 = V_3 -> V_12 ;
if ( V_3 -> V_13 < V_86 -> V_13 )
V_3 -> V_13 = V_86 -> V_13 ;
else
V_86 -> V_13 = V_3 -> V_13 ;
if ( V_103 ) {
F_49 ( V_88 ) ;
continue;
}
V_86 = V_3 ;
V_103 = 1 ;
}
else {
if ( V_3 -> V_13 < V_86 -> V_12 )
goto V_105;
if ( V_3 -> V_12 > V_86 -> V_13 )
break;
if ( V_86 -> V_11 == V_34 )
V_103 = 1 ;
if ( V_3 -> V_12 < V_86 -> V_12 )
V_101 = V_3 ;
if ( V_3 -> V_13 > V_86 -> V_13 ) {
V_102 = V_3 ;
break;
}
if ( V_3 -> V_12 >= V_86 -> V_12 ) {
if ( V_103 ) {
F_49 ( V_88 ) ;
continue;
}
F_43 ( V_3 ) ;
V_3 -> V_12 = V_86 -> V_12 ;
V_3 -> V_13 = V_86 -> V_13 ;
V_3 -> V_11 = V_86 -> V_11 ;
F_8 ( V_3 ) ;
F_18 ( V_3 , V_86 ) ;
V_86 = V_3 ;
V_103 = 1 ;
}
}
V_105:
V_88 = & V_3 -> V_4 ;
}
error = - V_106 ;
if ( V_102 && V_101 == V_102 && ! V_100 )
goto V_93;
error = 0 ;
if ( ! V_103 ) {
if ( V_86 -> V_11 == V_34 ) {
if ( V_86 -> V_10 & V_94 )
error = - V_95 ;
goto V_93;
}
if ( ! V_87 ) {
error = - V_106 ;
goto V_93;
}
F_20 ( V_87 , V_86 ) ;
F_46 ( V_88 , V_87 ) ;
V_87 = NULL ;
}
if ( V_102 ) {
if ( V_101 == V_102 ) {
V_101 = V_100 ;
V_100 = NULL ;
F_20 ( V_101 , V_102 ) ;
F_46 ( V_88 , V_101 ) ;
}
V_102 -> V_12 = V_86 -> V_13 + 1 ;
F_43 ( V_102 ) ;
}
if ( V_101 ) {
V_101 -> V_13 = V_86 -> V_12 - 1 ;
F_43 ( V_101 ) ;
}
V_93:
F_3 () ;
if ( V_87 )
F_9 ( V_87 ) ;
if ( V_100 )
F_9 ( V_100 ) ;
return error ;
}
int F_67 ( struct V_36 * V_37 , struct V_2 * V_3 ,
struct V_2 * V_99 )
{
return F_66 ( V_37 -> V_52 . V_53 -> V_54 , V_3 , V_99 ) ;
}
int F_68 ( struct V_36 * V_37 , struct V_2 * V_3 )
{
int error ;
F_69 () ;
for (; ; ) {
error = F_67 ( V_37 , V_3 , NULL ) ;
if ( error != V_98 )
break;
error = F_70 ( V_3 -> V_19 , ! V_3 -> V_4 ) ;
if ( ! error )
continue;
F_38 ( V_3 ) ;
break;
}
return error ;
}
int F_71 ( struct V_89 * V_89 )
{
T_3 V_107 = V_39 -> V_58 ;
struct V_2 * V_3 ;
F_1 () ;
for ( V_3 = V_89 -> V_82 ; V_3 != NULL ; V_3 = V_3 -> V_4 ) {
if ( ! F_41 ( V_3 ) )
continue;
if ( V_3 -> V_6 != V_107 )
break;
}
F_3 () ;
return V_3 ? - V_96 : 0 ;
}
int F_72 ( int V_108 , struct V_89 * V_89 ,
struct V_36 * V_37 , T_2 V_109 ,
T_4 V_110 )
{
struct V_2 V_3 ;
int error ;
F_14 ( & V_3 ) ;
V_3 . V_6 = V_39 -> V_58 ;
V_3 . V_7 = V_39 -> V_40 ;
V_3 . V_9 = V_37 ;
V_3 . V_10 = V_59 | V_91 ;
if ( V_37 && ! ( V_37 -> V_111 & V_112 ) )
V_3 . V_10 |= V_97 ;
V_3 . V_11 = ( V_108 == V_113 ) ? V_32 : V_30 ;
V_3 . V_12 = V_109 ;
V_3 . V_13 = V_109 + V_110 - 1 ;
for (; ; ) {
error = F_66 ( V_89 , & V_3 , NULL ) ;
if ( error != V_98 )
break;
error = F_70 ( V_3 . V_19 , ! V_3 . V_4 ) ;
if ( ! error ) {
if ( F_73 ( V_89 ) )
continue;
}
F_38 ( & V_3 ) ;
break;
}
return error ;
}
int F_74 ( struct V_2 * * V_88 , int V_114 )
{
struct V_2 * V_3 = * V_88 ;
int error = F_23 ( V_3 , V_114 ) ;
if ( error )
return error ;
F_43 ( V_3 ) ;
if ( V_114 == V_34 )
F_49 ( V_88 ) ;
return 0 ;
}
static void F_75 ( struct V_89 * V_89 )
{
struct V_2 * * V_88 ;
struct V_2 * V_3 ;
V_88 = & V_89 -> V_82 ;
while ( ( V_3 = * V_88 ) && F_64 ( V_3 ) && ( V_3 -> V_11 & V_115 ) ) {
if ( ( V_3 -> V_116 == 0 )
|| F_76 ( V_117 , V_3 -> V_116 ) ) {
V_88 = & V_3 -> V_4 ;
continue;
}
F_74 ( V_88 , V_3 -> V_11 & ~ V_115 ) ;
if ( V_3 == * V_88 )
V_88 = & V_3 -> V_4 ;
}
}
int F_77 ( struct V_89 * V_89 , unsigned int V_118 )
{
int error = 0 , V_119 ;
struct V_2 * V_87 , * V_43 ;
struct V_2 * V_3 ;
unsigned long V_120 ;
int V_121 = 0 ;
int V_122 = ( V_118 & V_123 ) != V_124 ;
V_87 = F_32 ( NULL , V_122 ? V_32 : V_30 ) ;
F_1 () ;
F_75 ( V_89 ) ;
V_43 = V_89 -> V_82 ;
if ( ( V_43 == NULL ) || ! F_64 ( V_43 ) )
goto V_93;
for ( V_3 = V_43 ; V_3 && F_64 ( V_3 ) ; V_3 = V_3 -> V_4 )
if ( V_3 -> V_6 == V_39 -> V_58 )
V_121 = 1 ;
if ( V_122 ) {
V_119 = V_34 | V_115 ;
} else if ( V_43 -> V_11 & V_115 ) {
V_119 = V_43 -> V_11 ;
} else if ( V_43 -> V_11 & V_32 ) {
V_119 = V_30 | V_115 ;
} else {
goto V_93;
}
if ( F_78 ( V_87 ) && ! V_121
&& ( ( V_118 & V_112 ) == 0 ) ) {
error = F_79 ( V_87 ) ;
goto V_93;
}
V_120 = 0 ;
if ( V_125 > 0 ) {
V_120 = V_117 + V_125 * V_126 ;
if ( V_120 == 0 )
V_120 ++ ;
}
for ( V_3 = V_43 ; V_3 && F_64 ( V_3 ) ; V_3 = V_3 -> V_4 ) {
if ( V_3 -> V_11 != V_119 ) {
V_3 -> V_11 = V_119 ;
V_3 -> V_116 = V_120 ;
V_3 -> V_18 -> V_127 ( V_3 ) ;
}
}
if ( V_121 || ( V_118 & V_112 ) ) {
error = - V_128 ;
goto V_93;
}
V_129:
V_120 = V_43 -> V_116 ;
if ( V_120 != 0 ) {
V_120 -= V_117 ;
if ( V_120 == 0 )
V_120 ++ ;
}
F_39 ( V_43 , V_87 ) ;
F_3 () ;
error = F_80 ( V_87 -> V_19 ,
! V_87 -> V_4 , V_120 ) ;
F_1 () ;
F_36 ( V_87 ) ;
if ( error >= 0 ) {
if ( error == 0 )
F_75 ( V_89 ) ;
for ( V_43 = V_89 -> V_82 ; V_43 && F_64 ( V_43 ) ;
V_43 = V_43 -> V_4 ) {
if ( V_43 -> V_11 & V_115 )
goto V_129;
}
error = 0 ;
}
V_93:
F_3 () ;
if ( ! F_78 ( V_87 ) )
F_9 ( V_87 ) ;
return error ;
}
void F_81 ( struct V_89 * V_89 , struct V_130 * time )
{
struct V_2 * V_43 = V_89 -> V_82 ;
if ( V_43 && F_64 ( V_43 ) && ( V_43 -> V_11 & V_32 ) )
* time = F_82 ( V_89 -> V_131 ) ;
else
* time = V_89 -> V_132 ;
}
int F_83 ( struct V_36 * V_37 )
{
struct V_2 * V_3 ;
int type = V_34 ;
F_1 () ;
F_75 ( V_37 -> V_52 . V_53 -> V_54 ) ;
for ( V_3 = V_37 -> V_52 . V_53 -> V_54 -> V_82 ; V_3 && F_64 ( V_3 ) ;
V_3 = V_3 -> V_4 ) {
if ( V_3 -> V_9 == V_37 ) {
type = V_3 -> V_11 & ~ V_115 ;
break;
}
}
F_3 () ;
return type ;
}
int F_84 ( struct V_36 * V_37 , long V_114 , struct V_2 * * V_133 )
{
struct V_2 * V_3 , * * V_88 , * * V_134 = NULL , * V_135 ;
struct V_53 * V_53 = V_37 -> V_52 . V_53 ;
struct V_89 * V_89 = V_53 -> V_54 ;
int error , V_136 = 0 , V_137 = 0 ;
V_135 = * V_133 ;
error = - V_138 ;
if ( ( F_85 () != V_89 -> V_139 ) && ! F_86 ( V_140 ) )
goto V_93;
error = - V_35 ;
if ( ! F_87 ( V_89 -> V_141 ) )
goto V_93;
error = F_88 ( V_37 , V_114 ) ;
if ( error )
goto V_93;
F_75 ( V_89 ) ;
F_10 ( ! ( * V_133 ) -> V_18 -> V_127 ) ;
if ( V_114 != V_34 ) {
error = - V_96 ;
if ( ( V_114 == V_30 ) && ( F_89 ( & V_89 -> V_142 ) > 0 ) )
goto V_93;
if ( ( V_114 == V_32 )
&& ( ( V_53 -> V_143 > 1 )
|| ( F_89 ( & V_89 -> V_144 ) > 1 ) ) )
goto V_93;
}
for ( V_88 = & V_89 -> V_82 ;
( ( V_3 = * V_88 ) != NULL ) && F_64 ( V_3 ) ;
V_88 = & V_3 -> V_4 ) {
if ( V_3 -> V_9 == V_37 )
V_134 = V_88 ;
else if ( V_3 -> V_11 == ( V_115 | V_34 ) )
V_137 ++ ;
else
V_136 ++ ;
}
error = - V_96 ;
if ( ( V_114 == V_30 && ( V_137 > 0 ) ) ||
( V_114 == V_32 && ( ( V_136 + V_137 ) > 0 ) ) )
goto V_93;
if ( V_134 != NULL ) {
error = V_135 -> V_18 -> V_145 ( V_134 , V_114 ) ;
if ( ! error )
* V_133 = * V_134 ;
goto V_93;
}
if ( V_114 == V_34 )
goto V_93;
error = - V_35 ;
if ( ! V_146 )
goto V_93;
F_46 ( V_88 , V_135 ) ;
return 0 ;
V_93:
return error ;
}
static int F_90 ( struct V_36 * V_37 , long V_114 , struct V_2 * * V_135 )
{
if ( V_37 -> V_147 && V_37 -> V_147 -> V_148 )
return V_37 -> V_147 -> V_148 ( V_37 , V_114 , V_135 ) ;
else
return F_84 ( V_37 , V_114 , V_135 ) ;
}
int F_91 ( struct V_36 * V_37 , long V_114 , struct V_2 * * V_135 )
{
int error ;
F_1 () ;
error = F_90 ( V_37 , V_114 , V_135 ) ;
F_3 () ;
return error ;
}
static int F_92 ( struct V_36 * V_37 )
{
struct V_2 V_3 , * V_133 = & V_3 ;
F_31 ( V_37 , V_34 , V_133 ) ;
return F_91 ( V_37 , V_34 , & V_133 ) ;
}
static int F_93 ( unsigned int V_149 , struct V_36 * V_37 , long V_114 )
{
struct V_2 * V_3 , * V_150 ;
struct V_151 * V_24 ;
int error ;
V_3 = F_32 ( V_37 , V_114 ) ;
if ( F_78 ( V_3 ) )
return F_79 ( V_3 ) ;
V_24 = F_94 () ;
if ( ! V_24 ) {
F_9 ( V_3 ) ;
return - V_38 ;
}
V_150 = V_3 ;
F_1 () ;
error = F_90 ( V_37 , V_114 , & V_150 ) ;
if ( error ) {
F_3 () ;
F_9 ( V_3 ) ;
goto V_152;
}
if ( V_150 != V_3 )
F_9 ( V_3 ) ;
if ( ! F_95 ( V_149 , V_37 , & V_150 -> V_5 , V_24 ) )
V_24 = NULL ;
error = F_96 ( V_37 , F_97 ( V_39 ) , V_153 , 0 ) ;
F_3 () ;
V_152:
if ( V_24 )
F_98 ( V_24 ) ;
return error ;
}
int F_99 ( unsigned int V_149 , struct V_36 * V_37 , long V_114 )
{
if ( V_114 == V_34 )
return F_92 ( V_37 ) ;
return F_93 ( V_149 , V_37 , V_114 ) ;
}
int F_100 ( struct V_36 * V_37 , struct V_2 * V_3 )
{
int error ;
F_69 () ;
for (; ; ) {
error = F_62 ( V_37 , V_3 ) ;
if ( error != V_98 )
break;
error = F_70 ( V_3 -> V_19 , ! V_3 -> V_4 ) ;
if ( ! error )
continue;
F_38 ( V_3 ) ;
break;
}
return error ;
}
int F_101 ( struct V_36 * V_37 , struct V_2 * V_3 )
{
if ( V_37 -> V_147 && V_37 -> V_147 -> V_23 )
return V_37 -> V_147 -> V_23 ( V_37 , V_154 , V_3 ) ;
F_57 ( V_37 , V_3 ) ;
return 0 ;
}
static int F_102 ( struct V_43 * V_43 , struct V_2 * V_3 )
{
V_43 -> V_155 = V_3 -> V_7 ;
#if V_156 == 32
if ( V_3 -> V_12 > V_157 )
return - V_57 ;
if ( V_3 -> V_13 != V_42 && V_3 -> V_13 > V_157 )
return - V_57 ;
#endif
V_43 -> V_55 = V_3 -> V_12 ;
V_43 -> V_56 = V_3 -> V_13 == V_42 ? 0 :
V_3 -> V_13 - V_3 -> V_12 + 1 ;
V_43 -> V_47 = 0 ;
V_43 -> V_60 = V_3 -> V_11 ;
return 0 ;
}
static void F_103 ( struct V_61 * V_43 , struct V_2 * V_3 )
{
V_43 -> V_155 = V_3 -> V_7 ;
V_43 -> V_55 = V_3 -> V_12 ;
V_43 -> V_56 = V_3 -> V_13 == V_42 ? 0 :
V_3 -> V_13 - V_3 -> V_12 + 1 ;
V_43 -> V_47 = 0 ;
V_43 -> V_60 = V_3 -> V_11 ;
}
int F_104 ( struct V_36 * V_37 , struct V_43 T_5 * V_44 )
{
struct V_2 V_2 ;
struct V_43 V_43 ;
int error ;
error = - V_158 ;
if ( F_105 ( & V_43 , V_44 , sizeof( V_43 ) ) )
goto V_93;
error = - V_35 ;
if ( ( V_43 . V_60 != V_30 ) && ( V_43 . V_60 != V_32 ) )
goto V_93;
error = F_24 ( V_37 , & V_2 , & V_43 ) ;
if ( error )
goto V_93;
error = F_101 ( V_37 , & V_2 ) ;
if ( error )
goto V_93;
V_43 . V_60 = V_2 . V_11 ;
if ( V_2 . V_11 != V_34 ) {
error = F_102 ( & V_43 , & V_2 ) ;
if ( error )
goto V_93;
}
error = - V_158 ;
if ( ! F_106 ( V_44 , & V_43 , sizeof( V_43 ) ) )
error = 0 ;
V_93:
return error ;
}
int F_107 ( struct V_36 * V_37 , unsigned int V_26 , struct V_2 * V_3 , struct V_2 * V_159 )
{
if ( V_37 -> V_147 && V_37 -> V_147 -> V_23 )
return V_37 -> V_147 -> V_23 ( V_37 , V_26 , V_3 ) ;
else
return F_67 ( V_37 , V_3 , V_159 ) ;
}
static int F_108 ( struct V_36 * V_37 , unsigned int V_26 ,
struct V_2 * V_3 )
{
int error ;
error = F_88 ( V_37 , V_3 -> V_11 ) ;
if ( error )
return error ;
for (; ; ) {
error = F_107 ( V_37 , V_26 , V_3 , NULL ) ;
if ( error != V_98 )
break;
error = F_70 ( V_3 -> V_19 , ! V_3 -> V_4 ) ;
if ( ! error )
continue;
F_38 ( V_3 ) ;
break;
}
return error ;
}
int F_109 ( unsigned int V_149 , struct V_36 * V_37 , unsigned int V_26 ,
struct V_43 T_5 * V_44 )
{
struct V_2 * V_2 = F_6 () ;
struct V_43 V_43 ;
struct V_89 * V_89 ;
struct V_36 * V_160 ;
int error ;
if ( V_2 == NULL )
return - V_106 ;
error = - V_158 ;
if ( F_105 ( & V_43 , V_44 , sizeof( V_43 ) ) )
goto V_93;
V_89 = V_37 -> V_52 . V_53 -> V_54 ;
if ( F_110 ( V_89 ) && F_111 ( V_37 -> V_161 ) ) {
error = - V_96 ;
goto V_93;
}
V_162:
error = F_24 ( V_37 , V_2 , & V_43 ) ;
if ( error )
goto V_93;
if ( V_26 == V_163 ) {
V_2 -> V_10 |= V_97 ;
}
error = - V_164 ;
switch ( V_43 . V_60 ) {
case V_30 :
if ( ! ( V_37 -> V_165 & V_166 ) )
goto V_93;
break;
case V_32 :
if ( ! ( V_37 -> V_165 & V_167 ) )
goto V_93;
break;
case V_34 :
break;
default:
error = - V_35 ;
goto V_93;
}
error = F_108 ( V_37 , V_26 , V_2 ) ;
F_2 ( & V_39 -> V_58 -> V_2 ) ;
V_160 = F_112 ( V_149 ) ;
F_4 ( & V_39 -> V_58 -> V_2 ) ;
if ( ! error && V_160 != V_37 && V_43 . V_60 != V_34 ) {
V_43 . V_60 = V_34 ;
goto V_162;
}
V_93:
F_9 ( V_2 ) ;
return error ;
}
int F_113 ( struct V_36 * V_37 , struct V_61 T_5 * V_44 )
{
struct V_2 V_2 ;
struct V_61 V_43 ;
int error ;
error = - V_158 ;
if ( F_105 ( & V_43 , V_44 , sizeof( V_43 ) ) )
goto V_93;
error = - V_35 ;
if ( ( V_43 . V_60 != V_30 ) && ( V_43 . V_60 != V_32 ) )
goto V_93;
error = F_26 ( V_37 , & V_2 , & V_43 ) ;
if ( error )
goto V_93;
error = F_101 ( V_37 , & V_2 ) ;
if ( error )
goto V_93;
V_43 . V_60 = V_2 . V_11 ;
if ( V_2 . V_11 != V_34 )
F_103 ( & V_43 , & V_2 ) ;
error = - V_158 ;
if ( ! F_106 ( V_44 , & V_43 , sizeof( V_43 ) ) )
error = 0 ;
V_93:
return error ;
}
int F_114 ( unsigned int V_149 , struct V_36 * V_37 , unsigned int V_26 ,
struct V_61 T_5 * V_44 )
{
struct V_2 * V_2 = F_6 () ;
struct V_61 V_43 ;
struct V_89 * V_89 ;
struct V_36 * V_160 ;
int error ;
if ( V_2 == NULL )
return - V_106 ;
error = - V_158 ;
if ( F_105 ( & V_43 , V_44 , sizeof( V_43 ) ) )
goto V_93;
V_89 = V_37 -> V_52 . V_53 -> V_54 ;
if ( F_110 ( V_89 ) && F_111 ( V_37 -> V_161 ) ) {
error = - V_96 ;
goto V_93;
}
V_162:
error = F_26 ( V_37 , V_2 , & V_43 ) ;
if ( error )
goto V_93;
if ( V_26 == V_168 ) {
V_2 -> V_10 |= V_97 ;
}
error = - V_164 ;
switch ( V_43 . V_60 ) {
case V_30 :
if ( ! ( V_37 -> V_165 & V_166 ) )
goto V_93;
break;
case V_32 :
if ( ! ( V_37 -> V_165 & V_167 ) )
goto V_93;
break;
case V_34 :
break;
default:
error = - V_35 ;
goto V_93;
}
error = F_108 ( V_37 , V_26 , V_2 ) ;
F_2 ( & V_39 -> V_58 -> V_2 ) ;
V_160 = F_112 ( V_149 ) ;
F_4 ( & V_39 -> V_58 -> V_2 ) ;
if ( ! error && V_160 != V_37 && V_43 . V_60 != V_34 ) {
V_43 . V_60 = V_34 ;
goto V_162;
}
V_93:
F_9 ( V_2 ) ;
return error ;
}
void F_115 ( struct V_36 * V_37 , T_3 V_107 )
{
struct V_2 V_23 ;
if ( ! V_37 -> V_52 . V_53 -> V_54 -> V_82 )
return;
V_23 . V_11 = V_34 ;
V_23 . V_10 = V_59 | V_169 ;
V_23 . V_12 = 0 ;
V_23 . V_13 = V_42 ;
V_23 . V_6 = V_107 ;
V_23 . V_7 = V_39 -> V_40 ;
V_23 . V_9 = V_37 ;
V_23 . V_16 = NULL ;
V_23 . V_18 = NULL ;
F_107 ( V_37 , V_170 , & V_23 , NULL ) ;
if ( V_23 . V_16 && V_23 . V_16 -> V_17 )
V_23 . V_16 -> V_17 ( & V_23 ) ;
}
void F_116 ( struct V_36 * V_37 )
{
struct V_89 * V_89 = V_37 -> V_52 . V_53 -> V_54 ;
struct V_2 * V_3 ;
struct V_2 * * V_88 ;
if ( ! V_89 -> V_82 )
return;
if ( V_37 -> V_147 && V_37 -> V_147 -> V_43 ) {
struct V_2 V_3 = {
. V_7 = V_39 -> V_40 ,
. V_9 = V_37 ,
. V_10 = V_41 ,
. V_11 = V_34 ,
. V_13 = V_42 ,
} ;
V_37 -> V_147 -> V_43 ( V_37 , V_163 , & V_3 ) ;
if ( V_3 . V_16 && V_3 . V_16 -> V_17 )
V_3 . V_16 -> V_17 ( & V_3 ) ;
}
F_1 () ;
V_88 = & V_89 -> V_82 ;
while ( ( V_3 = * V_88 ) != NULL ) {
if ( V_3 -> V_9 == V_37 ) {
if ( F_56 ( V_3 ) ) {
F_49 ( V_88 ) ;
continue;
}
if ( F_64 ( V_3 ) ) {
F_74 ( V_88 , V_34 ) ;
continue;
}
F_117 () ;
}
V_88 = & V_3 -> V_4 ;
}
F_3 () ;
}
int
F_118 ( struct V_36 * V_37 , struct V_2 * V_71 )
{
int V_171 = 0 ;
F_1 () ;
if ( V_71 -> V_4 )
F_36 ( V_71 ) ;
else
V_171 = - V_95 ;
F_3 () ;
return V_171 ;
}
int F_119 ( struct V_36 * V_37 , struct V_2 * V_3 )
{
if ( V_37 -> V_147 && V_37 -> V_147 -> V_23 )
return V_37 -> V_147 -> V_23 ( V_37 , V_172 , V_3 ) ;
return 0 ;
}
static void F_120 ( struct V_173 * V_160 , struct V_2 * V_3 ,
T_2 V_174 , char * V_175 )
{
struct V_89 * V_89 = NULL ;
unsigned int V_7 ;
if ( V_3 -> V_8 )
V_7 = F_58 ( V_3 -> V_8 ) ;
else
V_7 = V_3 -> V_7 ;
if ( V_3 -> V_9 != NULL )
V_89 = V_3 -> V_9 -> V_52 . V_53 -> V_54 ;
F_121 ( V_160 , L_2 , V_174 , V_175 ) ;
if ( F_41 ( V_3 ) ) {
F_121 ( V_160 , L_3 ,
( V_3 -> V_10 & V_91 ) ? L_4 : L_5 ,
( V_89 == NULL ) ? L_6 :
F_110 ( V_89 ) ? L_7 : L_8 ) ;
} else if ( F_56 ( V_3 ) ) {
if ( V_3 -> V_11 & V_27 ) {
F_121 ( V_160 , L_9 ) ;
} else {
F_121 ( V_160 , L_10 ) ;
}
} else if ( F_64 ( V_3 ) ) {
F_121 ( V_160 , L_11 ) ;
if ( V_3 -> V_11 & V_115 )
F_121 ( V_160 , L_12 ) ;
else if ( V_3 -> V_9 )
F_121 ( V_160 , L_13 ) ;
else
F_121 ( V_160 , L_14 ) ;
} else {
F_121 ( V_160 , L_15 ) ;
}
if ( V_3 -> V_11 & V_27 ) {
F_121 ( V_160 , L_16 ,
( V_3 -> V_11 & V_176 )
? ( V_3 -> V_11 & V_177 ) ? L_17 : L_18
: ( V_3 -> V_11 & V_177 ) ? L_19 : L_20 ) ;
} else {
F_121 ( V_160 , L_16 ,
( V_3 -> V_11 & V_115 )
? ( V_3 -> V_11 & V_34 ) ? L_21 : L_18
: ( V_3 -> V_11 & V_32 ) ? L_19 : L_18 ) ;
}
if ( V_89 ) {
#ifdef F_122
F_121 ( V_160 , L_22 , V_7 ,
V_89 -> V_131 -> V_178 , V_89 -> V_179 ) ;
#else
F_121 ( V_160 , L_23 , V_7 ,
F_123 ( V_89 -> V_131 -> V_180 ) ,
F_124 ( V_89 -> V_131 -> V_180 ) , V_89 -> V_179 ) ;
#endif
} else {
F_121 ( V_160 , L_24 , V_7 ) ;
}
if ( F_41 ( V_3 ) ) {
if ( V_3 -> V_13 == V_42 )
F_121 ( V_160 , L_25 , V_3 -> V_12 ) ;
else
F_121 ( V_160 , L_26 , V_3 -> V_12 , V_3 -> V_13 ) ;
} else {
F_121 ( V_160 , L_27 ) ;
}
}
static int F_125 ( struct V_173 * V_160 , void * V_181 )
{
struct V_2 * V_3 , * V_182 ;
V_3 = F_126 ( V_181 , struct V_2 , V_21 ) ;
F_120 ( V_160 , V_3 , * ( ( T_2 * ) V_160 -> V_183 ) , L_28 ) ;
F_60 (bfl, &fl->fl_block, fl_block)
F_120 ( V_160 , V_182 , * ( ( T_2 * ) V_160 -> V_183 ) , L_29 ) ;
return 0 ;
}
static void * F_127 ( struct V_173 * V_160 , T_2 * V_75 )
{
T_2 * V_184 = V_160 -> V_183 ;
F_1 () ;
* V_184 = ( * V_75 + 1 ) ;
return F_128 ( & V_76 , * V_75 ) ;
}
static void * F_129 ( struct V_173 * V_160 , void * V_181 , T_2 * V_75 )
{
T_2 * V_184 = V_160 -> V_183 ;
++ * V_184 ;
return F_130 ( V_181 , & V_76 , V_75 ) ;
}
static void F_131 ( struct V_173 * V_160 , void * V_181 )
{
F_3 () ;
}
static int F_132 ( struct V_89 * V_89 , struct V_36 * V_37 )
{
return F_133 ( V_37 , & V_185 , sizeof( T_2 ) ) ;
}
static int T_6 F_134 ( void )
{
F_135 ( L_30 , 0 , NULL , & V_186 ) ;
return 0 ;
}
int F_136 ( struct V_89 * V_89 , T_2 V_45 , unsigned long V_187 )
{
struct V_2 * V_3 ;
int V_188 = 1 ;
F_1 () ;
for ( V_3 = V_89 -> V_82 ; V_3 != NULL ; V_3 = V_3 -> V_4 ) {
if ( F_41 ( V_3 ) ) {
if ( V_3 -> V_11 == V_30 )
continue;
if ( ( V_3 -> V_13 < V_45 ) || ( V_3 -> V_12 > ( V_45 + V_187 ) ) )
continue;
} else if ( F_56 ( V_3 ) ) {
if ( ! ( V_3 -> V_11 & V_27 ) )
continue;
if ( V_3 -> V_11 & V_176 )
continue;
} else
continue;
V_188 = 0 ;
break;
}
F_3 () ;
return V_188 ;
}
int F_137 ( struct V_89 * V_89 , T_2 V_45 , unsigned long V_187 )
{
struct V_2 * V_3 ;
int V_188 = 1 ;
F_1 () ;
for ( V_3 = V_89 -> V_82 ; V_3 != NULL ; V_3 = V_3 -> V_4 ) {
if ( F_41 ( V_3 ) ) {
if ( ( V_3 -> V_13 < V_45 ) || ( V_3 -> V_12 > ( V_45 + V_187 ) ) )
continue;
} else if ( F_56 ( V_3 ) ) {
if ( ! ( V_3 -> V_11 & V_27 ) )
continue;
if ( V_3 -> V_11 & V_177 )
continue;
} else
continue;
V_188 = 0 ;
break;
}
F_3 () ;
return V_188 ;
}
static int T_6 F_138 ( void )
{
V_14 = F_139 ( L_31 ,
sizeof( struct V_2 ) , 0 , V_189 ,
F_17 ) ;
return 0 ;
}
