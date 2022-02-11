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
if ( V_2 -> V_17 ) {
if ( V_2 -> V_17 -> V_18 )
V_2 -> V_17 -> V_18 ( V_2 ) ;
V_2 -> V_17 = NULL ;
}
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
static void F_19 ( struct V_1 * V_19 , struct V_1 * V_2 )
{
if ( V_2 -> V_15 ) {
if ( V_2 -> V_15 -> V_20 )
V_2 -> V_15 -> V_20 ( V_19 , V_2 ) ;
V_19 -> V_15 = V_2 -> V_15 ;
}
if ( V_2 -> V_17 )
V_19 -> V_17 = V_2 -> V_17 ;
}
void F_20 ( struct V_1 * V_19 , const struct V_1 * V_2 )
{
V_19 -> V_21 = V_2 -> V_21 ;
V_19 -> V_22 = V_2 -> V_22 ;
V_19 -> V_23 = NULL ;
V_19 -> V_3 = V_2 -> V_3 ;
V_19 -> V_8 = V_2 -> V_8 ;
V_19 -> V_24 = V_2 -> V_24 ;
V_19 -> V_25 = V_2 -> V_25 ;
V_19 -> V_15 = NULL ;
V_19 -> V_17 = NULL ;
}
void F_21 ( struct V_1 * V_19 , struct V_1 * V_2 )
{
F_12 ( V_19 ) ;
F_20 ( V_19 , V_2 ) ;
V_19 -> V_23 = V_2 -> V_23 ;
V_19 -> V_15 = V_2 -> V_15 ;
V_19 -> V_17 = V_2 -> V_17 ;
F_19 ( V_19 , V_2 ) ;
}
static inline int F_22 ( int V_26 ) {
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
static int F_23 ( struct V_34 * V_35 , struct V_1 * * V_36 ,
unsigned int V_26 )
{
struct V_1 * V_2 ;
int type = F_22 ( V_26 ) ;
if ( type < 0 )
return type ;
V_2 = F_10 () ;
if ( V_2 == NULL )
return - V_37 ;
V_2 -> V_23 = V_35 ;
V_2 -> V_22 = V_38 -> V_39 ;
V_2 -> V_3 = V_40 ;
V_2 -> V_8 = type ;
V_2 -> V_25 = V_41 ;
* V_36 = V_2 ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 , int type )
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
static int F_25 ( struct V_34 * V_35 , struct V_1 * V_2 ,
struct V_42 * V_43 )
{
T_1 V_44 , V_45 ;
switch ( V_43 -> V_46 ) {
case V_47 :
V_44 = 0 ;
break;
case V_48 :
V_44 = V_35 -> V_49 ;
break;
case V_50 :
V_44 = F_26 ( V_35 -> V_51 . V_52 -> V_53 ) ;
break;
default:
return - V_33 ;
}
V_44 += V_43 -> V_54 ;
if ( V_44 < 0 )
return - V_33 ;
V_2 -> V_25 = V_41 ;
if ( V_43 -> V_55 > 0 ) {
V_45 = V_44 + V_43 -> V_55 - 1 ;
V_2 -> V_25 = V_45 ;
} else if ( V_43 -> V_55 < 0 ) {
V_45 = V_44 - 1 ;
V_2 -> V_25 = V_45 ;
V_44 += V_43 -> V_55 ;
if ( V_44 < 0 )
return - V_33 ;
}
V_2 -> V_24 = V_44 ;
if ( V_2 -> V_25 < V_2 -> V_24 )
return - V_56 ;
V_2 -> V_21 = V_38 -> V_57 ;
V_2 -> V_22 = V_38 -> V_39 ;
V_2 -> V_23 = V_35 ;
V_2 -> V_3 = V_58 ;
V_2 -> V_15 = NULL ;
V_2 -> V_17 = NULL ;
return F_24 ( V_2 , V_43 -> V_59 ) ;
}
static int F_27 ( struct V_34 * V_35 , struct V_1 * V_2 ,
struct V_60 * V_43 )
{
T_2 V_44 ;
switch ( V_43 -> V_46 ) {
case V_47 :
V_44 = 0 ;
break;
case V_48 :
V_44 = V_35 -> V_49 ;
break;
case V_50 :
V_44 = F_26 ( V_35 -> V_51 . V_52 -> V_53 ) ;
break;
default:
return - V_33 ;
}
V_44 += V_43 -> V_54 ;
if ( V_44 < 0 )
return - V_33 ;
V_2 -> V_25 = V_41 ;
if ( V_43 -> V_55 > 0 ) {
V_2 -> V_25 = V_44 + V_43 -> V_55 - 1 ;
} else if ( V_43 -> V_55 < 0 ) {
V_2 -> V_25 = V_44 - 1 ;
V_44 += V_43 -> V_55 ;
if ( V_44 < 0 )
return - V_33 ;
}
V_2 -> V_24 = V_44 ;
if ( V_2 -> V_25 < V_2 -> V_24 )
return - V_56 ;
V_2 -> V_21 = V_38 -> V_57 ;
V_2 -> V_22 = V_38 -> V_39 ;
V_2 -> V_23 = V_35 ;
V_2 -> V_3 = V_58 ;
V_2 -> V_15 = NULL ;
V_2 -> V_17 = NULL ;
return F_24 ( V_2 , V_43 -> V_59 ) ;
}
static void F_28 ( struct V_1 * V_2 )
{
F_29 ( & V_2 -> V_61 , V_62 , V_63 ) ;
}
static void F_30 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_23 )
return;
F_31 ( V_2 -> V_23 ) ;
V_2 -> V_23 -> V_64 . V_65 = 0 ;
}
static int F_32 ( struct V_34 * V_35 , int type , struct V_1 * V_2 )
{
if ( F_24 ( V_2 , type ) != 0 )
return - V_33 ;
V_2 -> V_21 = V_38 -> V_57 ;
V_2 -> V_22 = V_38 -> V_39 ;
V_2 -> V_23 = V_35 ;
V_2 -> V_3 = V_66 ;
V_2 -> V_24 = 0 ;
V_2 -> V_25 = V_41 ;
V_2 -> V_15 = NULL ;
V_2 -> V_17 = & V_67 ;
return 0 ;
}
static struct V_1 * F_33 ( struct V_34 * V_35 , int type )
{
struct V_1 * V_2 = F_10 () ;
int error = - V_37 ;
if ( V_2 == NULL )
return F_34 ( error ) ;
error = F_32 ( V_35 , type , V_2 ) ;
if ( error ) {
F_13 ( V_2 ) ;
return F_34 ( error ) ;
}
return V_2 ;
}
static inline int F_35 ( struct V_1 * V_68 , struct V_1 * V_69 )
{
return ( ( V_68 -> V_25 >= V_69 -> V_24 ) &&
( V_69 -> V_25 >= V_68 -> V_24 ) ) ;
}
static int F_36 ( struct V_1 * V_68 , struct V_1 * V_69 )
{
if ( V_68 -> V_17 && V_68 -> V_17 -> V_70 )
return V_69 -> V_17 == V_68 -> V_17 &&
V_68 -> V_17 -> V_70 ( V_68 , V_69 ) ;
return V_68 -> V_21 == V_69 -> V_21 ;
}
static void F_37 ( struct V_1 * V_71 )
{
F_38 ( & V_71 -> V_11 ) ;
F_38 ( & V_71 -> V_10 ) ;
V_71 -> V_72 = NULL ;
}
static void F_39 ( struct V_1 * V_71 )
{
F_3 () ;
F_37 ( V_71 ) ;
F_5 () ;
}
static void F_40 ( struct V_1 * V_73 ,
struct V_1 * V_71 )
{
F_14 ( ! F_16 ( & V_71 -> V_11 ) ) ;
F_41 ( & V_71 -> V_11 , & V_73 -> V_11 ) ;
V_71 -> V_72 = V_73 ;
if ( F_42 ( V_73 ) )
F_43 ( & V_71 -> V_10 , & V_74 ) ;
}
static void F_44 ( struct V_1 * V_73 )
{
while ( ! F_16 ( & V_73 -> V_11 ) ) {
struct V_1 * V_71 ;
V_71 = F_45 ( & V_73 -> V_11 ,
struct V_1 , V_11 ) ;
F_37 ( V_71 ) ;
if ( V_71 -> V_17 && V_71 -> V_17 -> V_75 )
V_71 -> V_17 -> V_75 ( V_71 ) ;
else
F_46 ( & V_71 -> V_12 ) ;
}
}
static void F_47 ( struct V_1 * * V_76 , struct V_1 * V_2 )
{
F_43 ( & V_2 -> V_10 , & V_77 ) ;
V_2 -> V_78 = F_48 ( F_49 ( V_38 ) ) ;
V_2 -> V_72 = * V_76 ;
* V_76 = V_2 ;
}
static void F_50 ( struct V_1 * * V_79 )
{
struct V_1 * V_2 = * V_79 ;
* V_79 = V_2 -> V_72 ;
V_2 -> V_72 = NULL ;
F_38 ( & V_2 -> V_10 ) ;
F_51 ( 0 , V_2 -> V_23 , 0 , & V_2 -> V_61 ) ;
if ( V_2 -> V_61 != NULL ) {
F_52 ( V_80 L_1 , V_2 -> V_61 ) ;
V_2 -> V_61 = NULL ;
}
if ( V_2 -> V_78 ) {
F_53 ( V_2 -> V_78 ) ;
V_2 -> V_78 = NULL ;
}
F_44 ( V_2 ) ;
F_13 ( V_2 ) ;
}
static int F_54 ( struct V_1 * V_81 , struct V_1 * V_82 )
{
if ( V_82 -> V_8 == V_31 )
return 1 ;
if ( V_81 -> V_8 == V_31 )
return 1 ;
return 0 ;
}
static int F_55 ( struct V_1 * V_81 , struct V_1 * V_82 )
{
if ( ! F_42 ( V_82 ) || F_36 ( V_81 , V_82 ) )
return ( 0 ) ;
if ( ! F_35 ( V_81 , V_82 ) )
return 0 ;
return ( F_54 ( V_81 , V_82 ) ) ;
}
static int F_56 ( struct V_1 * V_81 , struct V_1 * V_82 )
{
if ( ! F_57 ( V_82 ) || ( V_81 -> V_23 == V_82 -> V_23 ) )
return ( 0 ) ;
if ( ( V_81 -> V_8 & V_27 ) || ( V_82 -> V_8 & V_27 ) )
return 0 ;
return ( F_54 ( V_81 , V_82 ) ) ;
}
void
F_58 ( struct V_34 * V_35 , struct V_1 * V_2 )
{
struct V_1 * V_83 ;
F_3 () ;
for ( V_83 = V_35 -> V_51 . V_52 -> V_53 -> V_84 ; V_83 ; V_83 = V_83 -> V_72 ) {
if ( ! F_42 ( V_83 ) )
continue;
if ( F_55 ( V_2 , V_83 ) )
break;
}
if ( V_83 ) {
F_20 ( V_2 , V_83 ) ;
if ( V_83 -> V_78 )
V_2 -> V_22 = F_59 ( V_83 -> V_78 ) ;
} else
V_2 -> V_8 = V_6 ;
F_5 () ;
return;
}
static struct V_1 * F_60 ( struct V_1 * V_85 )
{
struct V_1 * V_2 ;
F_61 (fl, &blocked_list, fl_link) {
if ( F_36 ( V_2 , V_85 ) )
return V_2 -> V_72 ;
}
return NULL ;
}
static int F_62 ( struct V_1 * V_81 ,
struct V_1 * V_85 )
{
int V_86 = 0 ;
while ( ( V_85 = F_60 ( V_85 ) ) ) {
if ( V_86 ++ > V_87 )
return 0 ;
if ( F_36 ( V_81 , V_85 ) )
return 1 ;
}
return 0 ;
}
static int F_63 ( struct V_34 * V_35 , struct V_1 * V_88 )
{
struct V_1 * V_89 = NULL ;
struct V_1 * * V_90 ;
struct V_91 * V_91 = V_35 -> V_51 . V_52 -> V_53 ;
int error = 0 ;
int V_92 = 0 ;
if ( ! ( V_88 -> V_3 & V_93 ) && ( V_88 -> V_8 != V_6 ) ) {
V_89 = F_10 () ;
if ( ! V_89 )
return - V_37 ;
}
F_3 () ;
if ( V_88 -> V_3 & V_93 )
goto V_94;
F_64 (inode, before) {
struct V_1 * V_2 = * V_90 ;
if ( F_42 ( V_2 ) )
break;
if ( F_65 ( V_2 ) )
continue;
if ( V_35 != V_2 -> V_23 )
continue;
if ( V_88 -> V_8 == V_2 -> V_8 )
goto V_95;
V_92 = 1 ;
F_50 ( V_90 ) ;
break;
}
if ( V_88 -> V_8 == V_6 ) {
if ( ( V_88 -> V_3 & V_96 ) && ! V_92 )
error = - V_97 ;
goto V_95;
}
if ( V_92 ) {
F_5 () ;
F_66 () ;
F_3 () ;
}
V_94:
F_64 (inode, before) {
struct V_1 * V_2 = * V_90 ;
if ( F_42 ( V_2 ) )
break;
if ( F_65 ( V_2 ) )
continue;
if ( ! F_56 ( V_88 , V_2 ) )
continue;
error = - V_98 ;
if ( ! ( V_88 -> V_3 & V_99 ) )
goto V_95;
error = V_100 ;
F_40 ( V_2 , V_88 ) ;
goto V_95;
}
if ( V_88 -> V_3 & V_93 )
goto V_95;
F_21 ( V_89 , V_88 ) ;
F_47 ( V_90 , V_89 ) ;
V_89 = NULL ;
error = 0 ;
V_95:
F_5 () ;
if ( V_89 )
F_13 ( V_89 ) ;
return error ;
}
static int F_67 ( struct V_91 * V_91 , struct V_1 * V_88 , struct V_1 * V_101 )
{
struct V_1 * V_2 ;
struct V_1 * V_89 = NULL ;
struct V_1 * V_102 = NULL ;
struct V_1 * V_103 = NULL ;
struct V_1 * V_104 = NULL ;
struct V_1 * * V_90 ;
int error , V_105 = 0 ;
if ( ! ( V_88 -> V_3 & V_93 ) &&
( V_88 -> V_8 != V_6 ||
V_88 -> V_24 != 0 || V_88 -> V_25 != V_41 ) ) {
V_89 = F_10 () ;
V_102 = F_10 () ;
}
F_3 () ;
if ( V_88 -> V_8 != V_6 ) {
F_64 (inode, before) {
V_2 = * V_90 ;
if ( ! F_42 ( V_2 ) )
continue;
if ( ! F_55 ( V_88 , V_2 ) )
continue;
if ( V_101 )
F_20 ( V_101 , V_2 ) ;
error = - V_98 ;
if ( ! ( V_88 -> V_3 & V_99 ) )
goto V_95;
error = - V_106 ;
if ( F_62 ( V_88 , V_2 ) )
goto V_95;
error = V_100 ;
F_40 ( V_2 , V_88 ) ;
goto V_95;
}
}
error = 0 ;
if ( V_88 -> V_3 & V_93 )
goto V_95;
V_90 = & V_91 -> V_84 ;
while ( ( V_2 = * V_90 ) && ( ! F_42 ( V_2 ) ||
! F_36 ( V_88 , V_2 ) ) ) {
V_90 = & V_2 -> V_72 ;
}
while ( ( V_2 = * V_90 ) && F_36 ( V_88 , V_2 ) ) {
if ( V_88 -> V_8 == V_2 -> V_8 ) {
if ( V_2 -> V_25 < V_88 -> V_24 - 1 )
goto V_107;
if ( V_2 -> V_24 - 1 > V_88 -> V_25 )
break;
if ( V_2 -> V_24 > V_88 -> V_24 )
V_2 -> V_24 = V_88 -> V_24 ;
else
V_88 -> V_24 = V_2 -> V_24 ;
if ( V_2 -> V_25 < V_88 -> V_25 )
V_2 -> V_25 = V_88 -> V_25 ;
else
V_88 -> V_25 = V_2 -> V_25 ;
if ( V_105 ) {
F_50 ( V_90 ) ;
continue;
}
V_88 = V_2 ;
V_105 = 1 ;
}
else {
if ( V_2 -> V_25 < V_88 -> V_24 )
goto V_107;
if ( V_2 -> V_24 > V_88 -> V_25 )
break;
if ( V_88 -> V_8 == V_6 )
V_105 = 1 ;
if ( V_2 -> V_24 < V_88 -> V_24 )
V_103 = V_2 ;
if ( V_2 -> V_25 > V_88 -> V_25 ) {
V_104 = V_2 ;
break;
}
if ( V_2 -> V_24 >= V_88 -> V_24 ) {
if ( V_105 ) {
F_50 ( V_90 ) ;
continue;
}
F_44 ( V_2 ) ;
V_2 -> V_24 = V_88 -> V_24 ;
V_2 -> V_25 = V_88 -> V_25 ;
V_2 -> V_8 = V_88 -> V_8 ;
F_12 ( V_2 ) ;
F_19 ( V_2 , V_88 ) ;
V_88 = V_2 ;
V_105 = 1 ;
}
}
V_107:
V_90 = & V_2 -> V_72 ;
}
error = - V_108 ;
if ( V_104 && V_103 == V_104 && ! V_102 )
goto V_95;
error = 0 ;
if ( ! V_105 ) {
if ( V_88 -> V_8 == V_6 ) {
if ( V_88 -> V_3 & V_96 )
error = - V_97 ;
goto V_95;
}
if ( ! V_89 ) {
error = - V_108 ;
goto V_95;
}
F_21 ( V_89 , V_88 ) ;
F_47 ( V_90 , V_89 ) ;
V_89 = NULL ;
}
if ( V_104 ) {
if ( V_103 == V_104 ) {
V_103 = V_102 ;
V_102 = NULL ;
F_21 ( V_103 , V_104 ) ;
F_47 ( V_90 , V_103 ) ;
}
V_104 -> V_24 = V_88 -> V_25 + 1 ;
F_44 ( V_104 ) ;
}
if ( V_103 ) {
V_103 -> V_25 = V_88 -> V_24 - 1 ;
F_44 ( V_103 ) ;
}
V_95:
F_5 () ;
if ( V_89 )
F_13 ( V_89 ) ;
if ( V_102 )
F_13 ( V_102 ) ;
return error ;
}
int F_68 ( struct V_34 * V_35 , struct V_1 * V_2 ,
struct V_1 * V_101 )
{
return F_67 ( V_35 -> V_51 . V_52 -> V_53 , V_2 , V_101 ) ;
}
int F_69 ( struct V_34 * V_35 , struct V_1 * V_2 )
{
int error ;
F_70 () ;
for (; ; ) {
error = F_68 ( V_35 , V_2 , NULL ) ;
if ( error != V_100 )
break;
error = F_71 ( V_2 -> V_12 , ! V_2 -> V_72 ) ;
if ( ! error )
continue;
F_39 ( V_2 ) ;
break;
}
return error ;
}
int F_72 ( struct V_91 * V_91 )
{
T_3 V_109 = V_38 -> V_57 ;
struct V_1 * V_2 ;
F_3 () ;
for ( V_2 = V_91 -> V_84 ; V_2 != NULL ; V_2 = V_2 -> V_72 ) {
if ( ! F_42 ( V_2 ) )
continue;
if ( V_2 -> V_21 != V_109 )
break;
}
F_5 () ;
return V_2 ? - V_98 : 0 ;
}
int F_73 ( int V_110 , struct V_91 * V_91 ,
struct V_34 * V_35 , T_2 V_111 ,
T_4 V_112 )
{
struct V_1 V_2 ;
int error ;
F_18 ( & V_2 ) ;
V_2 . V_21 = V_38 -> V_57 ;
V_2 . V_22 = V_38 -> V_39 ;
V_2 . V_23 = V_35 ;
V_2 . V_3 = V_58 | V_93 ;
if ( V_35 && ! ( V_35 -> V_113 & V_114 ) )
V_2 . V_3 |= V_99 ;
V_2 . V_8 = ( V_110 == V_115 ) ? V_31 : V_7 ;
V_2 . V_24 = V_111 ;
V_2 . V_25 = V_111 + V_112 - 1 ;
for (; ; ) {
error = F_67 ( V_91 , & V_2 , NULL ) ;
if ( error != V_100 )
break;
error = F_71 ( V_2 . V_12 , ! V_2 . V_72 ) ;
if ( ! error ) {
if ( F_74 ( V_91 ) )
continue;
}
F_39 ( & V_2 ) ;
break;
}
return error ;
}
static void F_75 ( struct V_1 * V_2 , int V_116 )
{
switch ( V_116 ) {
case V_6 :
V_2 -> V_3 &= ~ V_4 ;
case V_7 :
V_2 -> V_3 &= ~ V_5 ;
}
}
int F_76 ( struct V_1 * * V_90 , int V_116 )
{
struct V_1 * V_2 = * V_90 ;
int error = F_24 ( V_2 , V_116 ) ;
if ( error )
return error ;
F_75 ( V_2 , V_116 ) ;
F_44 ( V_2 ) ;
if ( V_116 == V_6 )
F_50 ( V_90 ) ;
return 0 ;
}
static bool F_77 ( unsigned long V_117 )
{
if ( ! V_117 )
return false ;
return F_78 ( V_118 , V_117 ) ;
}
static void F_79 ( struct V_91 * V_91 )
{
struct V_1 * * V_90 ;
struct V_1 * V_2 ;
V_90 = & V_91 -> V_84 ;
while ( ( V_2 = * V_90 ) && F_65 ( V_2 ) && F_1 ( V_2 ) ) {
if ( F_77 ( V_2 -> V_119 ) )
F_76 ( V_90 , V_7 ) ;
if ( F_77 ( V_2 -> V_120 ) )
F_76 ( V_90 , V_6 ) ;
if ( V_2 == * V_90 )
V_90 = & V_2 -> V_72 ;
}
}
int F_80 ( struct V_91 * V_91 , unsigned int V_121 )
{
int error = 0 ;
struct V_1 * V_89 , * V_42 ;
struct V_1 * V_2 ;
unsigned long V_122 ;
int V_123 = 0 ;
int V_124 = ( V_121 & V_125 ) != V_126 ;
V_89 = F_33 ( NULL , V_124 ? V_31 : V_7 ) ;
if ( F_81 ( V_89 ) )
return F_82 ( V_89 ) ;
F_3 () ;
F_79 ( V_91 ) ;
V_42 = V_91 -> V_84 ;
if ( ( V_42 == NULL ) || ! F_65 ( V_42 ) )
goto V_95;
if ( ! F_54 ( V_42 , V_89 ) )
goto V_95;
for ( V_2 = V_42 ; V_2 && F_65 ( V_2 ) ; V_2 = V_2 -> V_72 )
if ( V_2 -> V_21 == V_38 -> V_57 )
V_123 = 1 ;
V_122 = 0 ;
if ( V_127 > 0 ) {
V_122 = V_118 + V_127 * V_128 ;
if ( V_122 == 0 )
V_122 ++ ;
}
for ( V_2 = V_42 ; V_2 && F_65 ( V_2 ) ; V_2 = V_2 -> V_72 ) {
if ( V_124 ) {
if ( V_2 -> V_3 & V_4 )
continue;
V_2 -> V_3 |= V_4 ;
V_2 -> V_120 = V_122 ;
} else {
if ( F_1 ( V_42 ) )
continue;
V_2 -> V_3 |= V_5 ;
V_2 -> V_119 = V_122 ;
}
V_2 -> V_17 -> V_129 ( V_2 ) ;
}
if ( V_123 || ( V_121 & V_114 ) ) {
error = - V_130 ;
goto V_95;
}
V_131:
V_122 = V_42 -> V_120 ;
if ( V_122 != 0 ) {
V_122 -= V_118 ;
if ( V_122 == 0 )
V_122 ++ ;
}
F_40 ( V_42 , V_89 ) ;
F_5 () ;
error = F_83 ( V_89 -> V_12 ,
! V_89 -> V_72 , V_122 ) ;
F_3 () ;
F_37 ( V_89 ) ;
if ( error >= 0 ) {
if ( error == 0 )
F_79 ( V_91 ) ;
for ( V_42 = V_91 -> V_84 ; V_42 && F_65 ( V_42 ) ;
V_42 = V_42 -> V_72 ) {
if ( F_54 ( V_89 , V_42 ) )
goto V_131;
}
error = 0 ;
}
V_95:
F_5 () ;
F_13 ( V_89 ) ;
return error ;
}
void F_84 ( struct V_91 * V_91 , struct V_132 * time )
{
struct V_1 * V_42 = V_91 -> V_84 ;
if ( V_42 && F_65 ( V_42 ) && ( V_42 -> V_8 & V_31 ) )
* time = F_85 ( V_91 -> V_133 ) ;
else
* time = V_91 -> V_134 ;
}
int F_86 ( struct V_34 * V_35 )
{
struct V_1 * V_2 ;
int type = V_6 ;
F_3 () ;
F_79 ( V_35 -> V_51 . V_52 -> V_53 ) ;
for ( V_2 = V_35 -> V_51 . V_52 -> V_53 -> V_84 ; V_2 && F_65 ( V_2 ) ;
V_2 = V_2 -> V_72 ) {
if ( V_2 -> V_23 == V_35 ) {
type = F_2 ( V_2 ) ;
break;
}
}
F_5 () ;
return type ;
}
int F_87 ( struct V_34 * V_35 , long V_116 , struct V_1 * * V_135 )
{
struct V_1 * V_2 , * * V_90 , * * V_136 = NULL , * V_137 ;
struct V_52 * V_52 = V_35 -> V_51 . V_52 ;
struct V_91 * V_91 = V_52 -> V_53 ;
int error ;
V_137 = * V_135 ;
error = - V_98 ;
if ( ( V_116 == V_7 ) && ( F_88 ( & V_91 -> V_138 ) > 0 ) )
goto V_95;
if ( ( V_116 == V_31 )
&& ( ( V_52 -> V_139 > 1 )
|| ( F_88 ( & V_91 -> V_140 ) > 1 ) ) )
goto V_95;
error = - V_98 ;
for ( V_90 = & V_91 -> V_84 ;
( ( V_2 = * V_90 ) != NULL ) && F_65 ( V_2 ) ;
V_90 = & V_2 -> V_72 ) {
if ( V_2 -> V_23 == V_35 ) {
V_136 = V_90 ;
continue;
}
if ( V_116 == V_31 )
goto V_95;
if ( V_2 -> V_3 & V_4 )
goto V_95;
}
if ( V_136 != NULL ) {
error = V_137 -> V_17 -> V_141 ( V_136 , V_116 ) ;
if ( ! error )
* V_135 = * V_136 ;
goto V_95;
}
error = - V_33 ;
if ( ! V_142 )
goto V_95;
F_47 ( V_90 , V_137 ) ;
return 0 ;
V_95:
return error ;
}
int F_89 ( struct V_34 * V_35 , struct V_1 * * V_135 )
{
struct V_1 * V_2 , * * V_90 ;
struct V_52 * V_52 = V_35 -> V_51 . V_52 ;
struct V_91 * V_91 = V_52 -> V_53 ;
for ( V_90 = & V_91 -> V_84 ;
( ( V_2 = * V_90 ) != NULL ) && F_65 ( V_2 ) ;
V_90 = & V_2 -> V_72 ) {
if ( V_2 -> V_23 != V_35 )
continue;
return ( * V_135 ) -> V_17 -> V_141 ( V_90 , V_6 ) ;
}
return - V_98 ;
}
int F_90 ( struct V_34 * V_35 , long V_116 , struct V_1 * * V_135 )
{
struct V_52 * V_52 = V_35 -> V_51 . V_52 ;
struct V_91 * V_91 = V_52 -> V_53 ;
int error ;
if ( ( F_91 () != V_91 -> V_143 ) && ! F_92 ( V_144 ) )
return - V_145 ;
if ( ! F_93 ( V_91 -> V_146 ) )
return - V_33 ;
error = F_94 ( V_35 , V_116 ) ;
if ( error )
return error ;
F_79 ( V_91 ) ;
F_14 ( ! ( * V_135 ) -> V_17 -> V_129 ) ;
switch ( V_116 ) {
case V_6 :
return F_89 ( V_35 , V_135 ) ;
case V_7 :
case V_31 :
return F_87 ( V_35 , V_116 , V_135 ) ;
default:
F_95 () ;
}
}
static int F_96 ( struct V_34 * V_35 , long V_116 , struct V_1 * * V_137 )
{
if ( V_35 -> V_147 && V_35 -> V_147 -> V_148 )
return V_35 -> V_147 -> V_148 ( V_35 , V_116 , V_137 ) ;
else
return F_90 ( V_35 , V_116 , V_137 ) ;
}
int F_97 ( struct V_34 * V_35 , long V_116 , struct V_1 * * V_137 )
{
int error ;
F_3 () ;
error = F_96 ( V_35 , V_116 , V_137 ) ;
F_5 () ;
return error ;
}
static int F_98 ( struct V_34 * V_35 )
{
struct V_1 V_2 , * V_135 = & V_2 ;
F_32 ( V_35 , V_6 , V_135 ) ;
return F_97 ( V_35 , V_6 , & V_135 ) ;
}
static int F_99 ( unsigned int V_149 , struct V_34 * V_35 , long V_116 )
{
struct V_1 * V_2 , * V_150 ;
struct V_151 * V_19 ;
int error ;
V_2 = F_33 ( V_35 , V_116 ) ;
if ( F_81 ( V_2 ) )
return F_82 ( V_2 ) ;
V_19 = F_100 () ;
if ( ! V_19 ) {
F_13 ( V_2 ) ;
return - V_37 ;
}
V_150 = V_2 ;
F_3 () ;
error = F_96 ( V_35 , V_116 , & V_150 ) ;
if ( error ) {
F_5 () ;
F_13 ( V_2 ) ;
goto V_152;
}
if ( V_150 != V_2 )
F_13 ( V_2 ) ;
if ( ! F_101 ( V_149 , V_35 , & V_150 -> V_61 , V_19 ) )
V_19 = NULL ;
error = F_102 ( V_35 , F_103 ( V_38 ) , V_153 , 0 ) ;
F_5 () ;
V_152:
if ( V_19 )
F_104 ( V_19 ) ;
return error ;
}
int F_105 ( unsigned int V_149 , struct V_34 * V_35 , long V_116 )
{
if ( V_116 == V_6 )
return F_98 ( V_35 ) ;
return F_99 ( V_149 , V_35 , V_116 ) ;
}
int F_106 ( struct V_34 * V_35 , struct V_1 * V_2 )
{
int error ;
F_70 () ;
for (; ; ) {
error = F_63 ( V_35 , V_2 ) ;
if ( error != V_100 )
break;
error = F_71 ( V_2 -> V_12 , ! V_2 -> V_72 ) ;
if ( ! error )
continue;
F_39 ( V_2 ) ;
break;
}
return error ;
}
int F_107 ( struct V_34 * V_35 , struct V_1 * V_2 )
{
if ( V_35 -> V_147 && V_35 -> V_147 -> V_36 )
return V_35 -> V_147 -> V_36 ( V_35 , V_154 , V_2 ) ;
F_58 ( V_35 , V_2 ) ;
return 0 ;
}
static int F_108 ( struct V_42 * V_42 , struct V_1 * V_2 )
{
V_42 -> V_155 = V_2 -> V_22 ;
#if V_156 == 32
if ( V_2 -> V_24 > V_157 )
return - V_56 ;
if ( V_2 -> V_25 != V_41 && V_2 -> V_25 > V_157 )
return - V_56 ;
#endif
V_42 -> V_54 = V_2 -> V_24 ;
V_42 -> V_55 = V_2 -> V_25 == V_41 ? 0 :
V_2 -> V_25 - V_2 -> V_24 + 1 ;
V_42 -> V_46 = 0 ;
V_42 -> V_59 = V_2 -> V_8 ;
return 0 ;
}
static void F_109 ( struct V_60 * V_42 , struct V_1 * V_2 )
{
V_42 -> V_155 = V_2 -> V_22 ;
V_42 -> V_54 = V_2 -> V_24 ;
V_42 -> V_55 = V_2 -> V_25 == V_41 ? 0 :
V_2 -> V_25 - V_2 -> V_24 + 1 ;
V_42 -> V_46 = 0 ;
V_42 -> V_59 = V_2 -> V_8 ;
}
int F_110 ( struct V_34 * V_35 , struct V_42 T_5 * V_43 )
{
struct V_1 V_1 ;
struct V_42 V_42 ;
int error ;
error = - V_158 ;
if ( F_111 ( & V_42 , V_43 , sizeof( V_42 ) ) )
goto V_95;
error = - V_33 ;
if ( ( V_42 . V_59 != V_7 ) && ( V_42 . V_59 != V_31 ) )
goto V_95;
error = F_25 ( V_35 , & V_1 , & V_42 ) ;
if ( error )
goto V_95;
error = F_107 ( V_35 , & V_1 ) ;
if ( error )
goto V_95;
V_42 . V_59 = V_1 . V_8 ;
if ( V_1 . V_8 != V_6 ) {
error = F_108 ( & V_42 , & V_1 ) ;
if ( error )
goto V_95;
}
error = - V_158 ;
if ( ! F_112 ( V_43 , & V_42 , sizeof( V_42 ) ) )
error = 0 ;
V_95:
return error ;
}
int F_113 ( struct V_34 * V_35 , unsigned int V_26 , struct V_1 * V_2 , struct V_1 * V_159 )
{
if ( V_35 -> V_147 && V_35 -> V_147 -> V_36 )
return V_35 -> V_147 -> V_36 ( V_35 , V_26 , V_2 ) ;
else
return F_68 ( V_35 , V_2 , V_159 ) ;
}
static int F_114 ( struct V_34 * V_35 , unsigned int V_26 ,
struct V_1 * V_2 )
{
int error ;
error = F_94 ( V_35 , V_2 -> V_8 ) ;
if ( error )
return error ;
for (; ; ) {
error = F_113 ( V_35 , V_26 , V_2 , NULL ) ;
if ( error != V_100 )
break;
error = F_71 ( V_2 -> V_12 , ! V_2 -> V_72 ) ;
if ( ! error )
continue;
F_39 ( V_2 ) ;
break;
}
return error ;
}
int F_115 ( unsigned int V_149 , struct V_34 * V_35 , unsigned int V_26 ,
struct V_42 T_5 * V_43 )
{
struct V_1 * V_1 = F_10 () ;
struct V_42 V_42 ;
struct V_91 * V_91 ;
struct V_34 * V_160 ;
int error ;
if ( V_1 == NULL )
return - V_108 ;
error = - V_158 ;
if ( F_111 ( & V_42 , V_43 , sizeof( V_42 ) ) )
goto V_95;
V_91 = V_35 -> V_51 . V_52 -> V_53 ;
if ( F_116 ( V_91 ) && F_117 ( V_35 -> V_161 ) ) {
error = - V_98 ;
goto V_95;
}
V_162:
error = F_25 ( V_35 , V_1 , & V_42 ) ;
if ( error )
goto V_95;
if ( V_26 == V_163 ) {
V_1 -> V_3 |= V_99 ;
}
error = - V_164 ;
switch ( V_42 . V_59 ) {
case V_7 :
if ( ! ( V_35 -> V_165 & V_166 ) )
goto V_95;
break;
case V_31 :
if ( ! ( V_35 -> V_165 & V_167 ) )
goto V_95;
break;
case V_6 :
break;
default:
error = - V_33 ;
goto V_95;
}
error = F_114 ( V_35 , V_26 , V_1 ) ;
F_4 ( & V_38 -> V_57 -> V_1 ) ;
V_160 = F_118 ( V_149 ) ;
F_6 ( & V_38 -> V_57 -> V_1 ) ;
if ( ! error && V_160 != V_35 && V_42 . V_59 != V_6 ) {
V_42 . V_59 = V_6 ;
goto V_162;
}
V_95:
F_13 ( V_1 ) ;
return error ;
}
int F_119 ( struct V_34 * V_35 , struct V_60 T_5 * V_43 )
{
struct V_1 V_1 ;
struct V_60 V_42 ;
int error ;
error = - V_158 ;
if ( F_111 ( & V_42 , V_43 , sizeof( V_42 ) ) )
goto V_95;
error = - V_33 ;
if ( ( V_42 . V_59 != V_7 ) && ( V_42 . V_59 != V_31 ) )
goto V_95;
error = F_27 ( V_35 , & V_1 , & V_42 ) ;
if ( error )
goto V_95;
error = F_107 ( V_35 , & V_1 ) ;
if ( error )
goto V_95;
V_42 . V_59 = V_1 . V_8 ;
if ( V_1 . V_8 != V_6 )
F_109 ( & V_42 , & V_1 ) ;
error = - V_158 ;
if ( ! F_112 ( V_43 , & V_42 , sizeof( V_42 ) ) )
error = 0 ;
V_95:
return error ;
}
int F_120 ( unsigned int V_149 , struct V_34 * V_35 , unsigned int V_26 ,
struct V_60 T_5 * V_43 )
{
struct V_1 * V_1 = F_10 () ;
struct V_60 V_42 ;
struct V_91 * V_91 ;
struct V_34 * V_160 ;
int error ;
if ( V_1 == NULL )
return - V_108 ;
error = - V_158 ;
if ( F_111 ( & V_42 , V_43 , sizeof( V_42 ) ) )
goto V_95;
V_91 = V_35 -> V_51 . V_52 -> V_53 ;
if ( F_116 ( V_91 ) && F_117 ( V_35 -> V_161 ) ) {
error = - V_98 ;
goto V_95;
}
V_162:
error = F_27 ( V_35 , V_1 , & V_42 ) ;
if ( error )
goto V_95;
if ( V_26 == V_168 ) {
V_1 -> V_3 |= V_99 ;
}
error = - V_164 ;
switch ( V_42 . V_59 ) {
case V_7 :
if ( ! ( V_35 -> V_165 & V_166 ) )
goto V_95;
break;
case V_31 :
if ( ! ( V_35 -> V_165 & V_167 ) )
goto V_95;
break;
case V_6 :
break;
default:
error = - V_33 ;
goto V_95;
}
error = F_114 ( V_35 , V_26 , V_1 ) ;
F_4 ( & V_38 -> V_57 -> V_1 ) ;
V_160 = F_118 ( V_149 ) ;
F_6 ( & V_38 -> V_57 -> V_1 ) ;
if ( ! error && V_160 != V_35 && V_42 . V_59 != V_6 ) {
V_42 . V_59 = V_6 ;
goto V_162;
}
V_95:
F_13 ( V_1 ) ;
return error ;
}
void F_121 ( struct V_34 * V_35 , T_3 V_109 )
{
struct V_1 V_36 ;
if ( ! V_35 -> V_51 . V_52 -> V_53 -> V_84 )
return;
V_36 . V_8 = V_6 ;
V_36 . V_3 = V_58 | V_169 ;
V_36 . V_24 = 0 ;
V_36 . V_25 = V_41 ;
V_36 . V_21 = V_109 ;
V_36 . V_22 = V_38 -> V_39 ;
V_36 . V_23 = V_35 ;
V_36 . V_15 = NULL ;
V_36 . V_17 = NULL ;
F_113 ( V_35 , V_170 , & V_36 , NULL ) ;
if ( V_36 . V_15 && V_36 . V_15 -> V_16 )
V_36 . V_15 -> V_16 ( & V_36 ) ;
}
void F_122 ( struct V_34 * V_35 )
{
struct V_91 * V_91 = V_35 -> V_51 . V_52 -> V_53 ;
struct V_1 * V_2 ;
struct V_1 * * V_90 ;
if ( ! V_91 -> V_84 )
return;
if ( V_35 -> V_147 && V_35 -> V_147 -> V_42 ) {
struct V_1 V_2 = {
. V_22 = V_38 -> V_39 ,
. V_23 = V_35 ,
. V_3 = V_40 ,
. V_8 = V_6 ,
. V_25 = V_41 ,
} ;
V_35 -> V_147 -> V_42 ( V_35 , V_163 , & V_2 ) ;
if ( V_2 . V_15 && V_2 . V_15 -> V_16 )
V_2 . V_15 -> V_16 ( & V_2 ) ;
}
F_3 () ;
V_90 = & V_91 -> V_84 ;
while ( ( V_2 = * V_90 ) != NULL ) {
if ( V_2 -> V_23 == V_35 ) {
if ( F_57 ( V_2 ) ) {
F_50 ( V_90 ) ;
continue;
}
if ( F_65 ( V_2 ) ) {
F_76 ( V_90 , V_6 ) ;
continue;
}
F_95 () ;
}
V_90 = & V_2 -> V_72 ;
}
F_5 () ;
}
int
F_123 ( struct V_34 * V_35 , struct V_1 * V_71 )
{
int V_171 = 0 ;
F_3 () ;
if ( V_71 -> V_72 )
F_37 ( V_71 ) ;
else
V_171 = - V_97 ;
F_5 () ;
return V_171 ;
}
int F_124 ( struct V_34 * V_35 , struct V_1 * V_2 )
{
if ( V_35 -> V_147 && V_35 -> V_147 -> V_36 )
return V_35 -> V_147 -> V_36 ( V_35 , V_172 , V_2 ) ;
return 0 ;
}
static void F_125 ( struct V_173 * V_160 , struct V_1 * V_2 ,
T_2 V_174 , char * V_175 )
{
struct V_91 * V_91 = NULL ;
unsigned int V_22 ;
if ( V_2 -> V_78 )
V_22 = F_59 ( V_2 -> V_78 ) ;
else
V_22 = V_2 -> V_22 ;
if ( V_2 -> V_23 != NULL )
V_91 = V_2 -> V_23 -> V_51 . V_52 -> V_53 ;
F_126 ( V_160 , L_2 , V_174 , V_175 ) ;
if ( F_42 ( V_2 ) ) {
F_126 ( V_160 , L_3 ,
( V_2 -> V_3 & V_93 ) ? L_4 : L_5 ,
( V_91 == NULL ) ? L_6 :
F_116 ( V_91 ) ? L_7 : L_8 ) ;
} else if ( F_57 ( V_2 ) ) {
if ( V_2 -> V_8 & V_27 ) {
F_126 ( V_160 , L_9 ) ;
} else {
F_126 ( V_160 , L_10 ) ;
}
} else if ( F_65 ( V_2 ) ) {
F_126 ( V_160 , L_11 ) ;
if ( F_1 ( V_2 ) )
F_126 ( V_160 , L_12 ) ;
else if ( V_2 -> V_23 )
F_126 ( V_160 , L_13 ) ;
else
F_126 ( V_160 , L_14 ) ;
} else {
F_126 ( V_160 , L_15 ) ;
}
if ( V_2 -> V_8 & V_27 ) {
F_126 ( V_160 , L_16 ,
( V_2 -> V_8 & V_176 )
? ( V_2 -> V_8 & V_177 ) ? L_17 : L_18
: ( V_2 -> V_8 & V_177 ) ? L_19 : L_20 ) ;
} else {
F_126 ( V_160 , L_16 ,
( F_1 ( V_2 ) )
? ( V_2 -> V_8 & V_6 ) ? L_21 : L_18
: ( V_2 -> V_8 & V_31 ) ? L_19 : L_18 ) ;
}
if ( V_91 ) {
#ifdef F_127
F_126 ( V_160 , L_22 , V_22 ,
V_91 -> V_133 -> V_178 , V_91 -> V_179 ) ;
#else
F_126 ( V_160 , L_23 , V_22 ,
F_128 ( V_91 -> V_133 -> V_180 ) ,
F_129 ( V_91 -> V_133 -> V_180 ) , V_91 -> V_179 ) ;
#endif
} else {
F_126 ( V_160 , L_24 , V_22 ) ;
}
if ( F_42 ( V_2 ) ) {
if ( V_2 -> V_25 == V_41 )
F_126 ( V_160 , L_25 , V_2 -> V_24 ) ;
else
F_126 ( V_160 , L_26 , V_2 -> V_24 , V_2 -> V_25 ) ;
} else {
F_126 ( V_160 , L_27 ) ;
}
}
static int F_130 ( struct V_173 * V_160 , void * V_181 )
{
struct V_1 * V_2 , * V_182 ;
V_2 = F_131 ( V_181 , struct V_1 , V_10 ) ;
F_125 ( V_160 , V_2 , * ( ( T_2 * ) V_160 -> V_183 ) , L_28 ) ;
F_61 (bfl, &fl->fl_block, fl_block)
F_125 ( V_160 , V_182 , * ( ( T_2 * ) V_160 -> V_183 ) , L_29 ) ;
return 0 ;
}
static void * F_132 ( struct V_173 * V_160 , T_2 * V_76 )
{
T_2 * V_184 = V_160 -> V_183 ;
F_3 () ;
* V_184 = ( * V_76 + 1 ) ;
return F_133 ( & V_77 , * V_76 ) ;
}
static void * F_134 ( struct V_173 * V_160 , void * V_181 , T_2 * V_76 )
{
T_2 * V_184 = V_160 -> V_183 ;
++ * V_184 ;
return F_135 ( V_181 , & V_77 , V_76 ) ;
}
static void F_136 ( struct V_173 * V_160 , void * V_181 )
{
F_5 () ;
}
static int F_137 ( struct V_91 * V_91 , struct V_34 * V_35 )
{
return F_138 ( V_35 , & V_185 , sizeof( T_2 ) ) ;
}
static int T_6 F_139 ( void )
{
F_140 ( L_30 , 0 , NULL , & V_186 ) ;
return 0 ;
}
int F_141 ( struct V_91 * V_91 , T_2 V_44 , unsigned long V_187 )
{
struct V_1 * V_2 ;
int V_188 = 1 ;
F_3 () ;
for ( V_2 = V_91 -> V_84 ; V_2 != NULL ; V_2 = V_2 -> V_72 ) {
if ( F_42 ( V_2 ) ) {
if ( V_2 -> V_8 == V_7 )
continue;
if ( ( V_2 -> V_25 < V_44 ) || ( V_2 -> V_24 > ( V_44 + V_187 ) ) )
continue;
} else if ( F_57 ( V_2 ) ) {
if ( ! ( V_2 -> V_8 & V_27 ) )
continue;
if ( V_2 -> V_8 & V_176 )
continue;
} else
continue;
V_188 = 0 ;
break;
}
F_5 () ;
return V_188 ;
}
int F_142 ( struct V_91 * V_91 , T_2 V_44 , unsigned long V_187 )
{
struct V_1 * V_2 ;
int V_188 = 1 ;
F_3 () ;
for ( V_2 = V_91 -> V_84 ; V_2 != NULL ; V_2 = V_2 -> V_72 ) {
if ( F_42 ( V_2 ) ) {
if ( ( V_2 -> V_25 < V_44 ) || ( V_2 -> V_24 > ( V_44 + V_187 ) ) )
continue;
} else if ( F_57 ( V_2 ) ) {
if ( ! ( V_2 -> V_8 & V_27 ) )
continue;
if ( V_2 -> V_8 & V_177 )
continue;
} else
continue;
V_188 = 0 ;
break;
}
F_5 () ;
return V_188 ;
}
static int T_6 F_143 ( void )
{
V_13 = F_144 ( L_31 ,
sizeof( struct V_1 ) , 0 , V_189 , NULL ) ;
return 0 ;
}
