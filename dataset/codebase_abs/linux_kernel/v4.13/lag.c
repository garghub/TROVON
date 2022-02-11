static int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_4 )
{
T_2 V_5 [ F_2 ( V_6 ) ] = { 0 } ;
T_2 V_7 [ F_2 ( V_8 ) ] = { 0 } ;
void * V_9 = F_3 ( V_6 , V_5 , V_10 ) ;
F_4 ( V_6 , V_5 , V_11 , V_12 ) ;
F_4 ( V_13 , V_9 , V_14 , V_3 ) ;
F_4 ( V_13 , V_9 , V_15 , V_4 ) ;
return F_5 ( V_2 , V_5 , sizeof( V_5 ) , V_7 , sizeof( V_7 ) ) ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_4 )
{
T_2 V_5 [ F_2 ( V_16 ) ] = { 0 } ;
T_2 V_7 [ F_2 ( V_17 ) ] = { 0 } ;
void * V_9 = F_3 ( V_16 , V_5 , V_10 ) ;
F_4 ( V_16 , V_5 , V_11 , V_18 ) ;
F_4 ( V_16 , V_5 , V_19 , 0x1 ) ;
F_4 ( V_13 , V_9 , V_14 , V_3 ) ;
F_4 ( V_13 , V_9 , V_15 , V_4 ) ;
return F_5 ( V_2 , V_5 , sizeof( V_5 ) , V_7 , sizeof( V_7 ) ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
T_2 V_5 [ F_2 ( V_20 ) ] = { 0 } ;
T_2 V_7 [ F_2 ( V_21 ) ] = { 0 } ;
F_4 ( V_20 , V_5 , V_11 , V_22 ) ;
return F_5 ( V_2 , V_5 , sizeof( V_5 ) , V_7 , sizeof( V_7 ) ) ;
}
int F_8 ( struct V_1 * V_2 )
{
T_2 V_5 [ F_2 ( V_23 ) ] = { 0 } ;
T_2 V_7 [ F_2 ( V_24 ) ] = { 0 } ;
F_4 ( V_23 , V_5 , V_11 , V_25 ) ;
return F_5 ( V_2 , V_5 , sizeof( V_5 ) , V_7 , sizeof( V_7 ) ) ;
}
int F_9 ( struct V_1 * V_2 )
{
T_2 V_5 [ F_2 ( V_26 ) ] = { 0 } ;
T_2 V_7 [ F_2 ( V_27 ) ] = { 0 } ;
F_4 ( V_26 , V_5 , V_11 , V_28 ) ;
return F_5 ( V_2 , V_5 , sizeof( V_5 ) , V_7 , sizeof( V_7 ) ) ;
}
static struct V_29 * F_10 ( struct V_1 * V_2 )
{
return V_2 -> V_30 . V_31 ;
}
static int F_11 ( struct V_29 * V_32 ,
struct V_33 * V_34 )
{
int V_35 ;
for ( V_35 = 0 ; V_35 < V_36 ; V_35 ++ )
if ( V_32 -> V_37 [ V_35 ] . V_38 == V_34 )
return V_35 ;
return - 1 ;
}
static bool F_12 ( struct V_29 * V_32 )
{
return ! ! ( V_32 -> V_39 & V_40 ) ;
}
static void F_13 ( struct V_41 * V_42 ,
T_1 * V_43 , T_1 * V_44 )
{
* V_43 = 1 ;
* V_44 = 2 ;
if ( ! V_42 -> V_45 [ 0 ] . V_46 ||
! V_42 -> V_45 [ 0 ] . V_47 ) {
* V_43 = 2 ;
return;
}
if ( ! V_42 -> V_45 [ 1 ] . V_46 ||
! V_42 -> V_45 [ 1 ] . V_47 )
* V_44 = 1 ;
}
static void F_14 ( struct V_29 * V_32 ,
struct V_41 * V_42 )
{
struct V_1 * V_48 = V_32 -> V_37 [ 0 ] . V_2 ;
int V_49 ;
V_32 -> V_39 |= V_40 ;
F_13 ( V_42 , & V_32 -> V_50 [ 0 ] ,
& V_32 -> V_50 [ 1 ] ) ;
V_49 = F_1 ( V_48 , V_32 -> V_50 [ 0 ] , V_32 -> V_50 [ 1 ] ) ;
if ( V_49 )
F_15 ( V_48 ,
L_1 ,
V_49 ) ;
}
static void F_16 ( struct V_29 * V_32 )
{
struct V_1 * V_48 = V_32 -> V_37 [ 0 ] . V_2 ;
int V_49 ;
V_32 -> V_39 &= ~ V_40 ;
V_49 = F_7 ( V_48 ) ;
if ( V_49 )
F_15 ( V_48 ,
L_2 ,
V_49 ) ;
}
static void F_17 ( struct V_29 * V_32 )
{
struct V_1 * V_48 = V_32 -> V_37 [ 0 ] . V_2 ;
struct V_1 * V_51 = V_32 -> V_37 [ 1 ] . V_2 ;
struct V_41 V_42 ;
T_1 V_52 , V_53 ;
int V_35 , V_49 ;
bool V_54 ;
if ( ! V_48 || ! V_51 )
return;
F_18 ( & V_55 ) ;
V_42 = V_32 -> V_42 ;
F_19 ( & V_55 ) ;
V_54 = V_42 . V_56 && V_32 -> V_57 ;
if ( V_54 && ! F_12 ( V_32 ) ) {
for ( V_35 = 0 ; V_35 < V_36 ; V_35 ++ )
F_20 ( V_32 -> V_37 [ V_35 ] . V_2 ,
V_58 ) ;
F_14 ( V_32 , & V_42 ) ;
F_21 ( V_48 , V_58 ) ;
F_22 ( V_51 ) ;
} else if ( V_54 && F_12 ( V_32 ) ) {
F_13 ( & V_42 , & V_52 ,
& V_53 ) ;
if ( ( V_52 != V_32 -> V_50 [ 0 ] ) ||
( V_53 != V_32 -> V_50 [ 1 ] ) ) {
V_32 -> V_50 [ 0 ] = V_52 ;
V_32 -> V_50 [ 1 ] = V_53 ;
V_49 = F_6 ( V_48 , V_52 , V_53 ) ;
if ( V_49 )
F_15 ( V_48 ,
L_3 ,
V_49 ) ;
}
} else if ( ! V_54 && F_12 ( V_32 ) ) {
F_20 ( V_48 , V_58 ) ;
F_23 ( V_51 ) ;
F_16 ( V_32 ) ;
for ( V_35 = 0 ; V_35 < V_36 ; V_35 ++ )
if ( V_32 -> V_37 [ V_35 ] . V_2 )
F_21 ( V_32 -> V_37 [ V_35 ] . V_2 ,
V_58 ) ;
}
}
static void F_24 ( struct V_29 * V_32 , unsigned long V_59 )
{
F_25 ( & V_32 -> V_60 , V_59 ) ;
}
static void F_26 ( struct V_61 * V_62 )
{
struct V_63 * V_63 = F_27 ( V_62 ) ;
struct V_29 * V_32 = F_28 ( V_63 , struct V_29 ,
V_60 ) ;
int V_64 ;
V_64 = F_29 () ;
if ( ! V_64 ) {
F_24 ( V_32 , V_65 ) ;
return;
}
F_17 ( V_32 ) ;
F_30 () ;
}
static int F_31 ( struct V_29 * V_32 ,
struct V_41 * V_42 ,
struct V_33 * V_34 ,
struct V_66 * V_67 )
{
struct V_33 * V_68 = V_67 -> V_69 , * V_70 ;
struct V_71 * V_72 = NULL ;
bool V_56 ;
int V_73 = 0 ;
int V_74 = 0 ;
int V_75 ;
if ( ! F_32 ( V_68 ) )
return 0 ;
if ( V_67 -> V_76 )
V_72 = V_67 -> V_77 ;
F_33 () ;
F_34 (upper, ndev_tmp) {
V_75 = F_11 ( V_32 , V_70 ) ;
if ( V_75 > - 1 )
V_73 |= ( 1 << V_75 ) ;
V_74 ++ ;
}
F_35 () ;
if ( ! ( V_73 & 0x3 ) )
return 0 ;
if ( V_72 )
V_42 -> V_78 = V_72 -> V_78 ;
V_56 = ( V_74 == V_36 ) &&
( V_73 == 0x3 ) &&
( ( V_42 -> V_78 == V_79 ) ||
( V_42 -> V_78 == V_80 ) ) ;
if ( V_42 -> V_56 != V_56 ) {
V_42 -> V_56 = V_56 ;
return 1 ;
}
return 0 ;
}
static int F_36 ( struct V_29 * V_32 ,
struct V_41 * V_42 ,
struct V_33 * V_34 ,
struct V_81 * V_67 )
{
struct V_82 * V_83 ;
int V_75 ;
if ( ! F_37 ( V_34 ) )
return 0 ;
V_75 = F_11 ( V_32 , V_34 ) ;
if ( V_75 == - 1 )
return 0 ;
V_83 = V_67 -> V_84 ;
if ( ! V_83 )
return 0 ;
V_42 -> V_45 [ V_75 ] = * V_83 ;
return 1 ;
}
static int F_38 ( struct V_85 * V_86 ,
unsigned long V_87 , void * V_88 )
{
struct V_33 * V_34 = F_39 ( V_88 ) ;
struct V_41 V_42 ;
struct V_29 * V_32 ;
int V_89 = 0 ;
if ( ! F_40 ( F_41 ( V_34 ) , & V_90 ) )
return V_91 ;
if ( ( V_87 != V_92 ) && ( V_87 != V_93 ) )
return V_91 ;
V_32 = F_28 ( V_86 , struct V_29 , V_94 ) ;
V_42 = V_32 -> V_42 ;
switch ( V_87 ) {
case V_92 :
V_89 = F_31 ( V_32 , & V_42 , V_34 ,
V_88 ) ;
break;
case V_93 :
V_89 = F_36 ( V_32 , & V_42 ,
V_34 , V_88 ) ;
break;
}
F_18 ( & V_55 ) ;
V_32 -> V_42 = V_42 ;
F_19 ( & V_55 ) ;
if ( V_89 )
F_24 ( V_32 , 0 ) ;
return V_91 ;
}
static bool F_42 ( struct V_29 * V_32 )
{
if ( ( V_32 -> V_37 [ 0 ] . V_2 && F_43 ( V_32 -> V_37 [ 0 ] . V_2 ) ) ||
( V_32 -> V_37 [ 1 ] . V_2 && F_43 ( V_32 -> V_37 [ 1 ] . V_2 ) ) )
return false ;
else
return true ;
}
static struct V_29 * F_44 ( void )
{
struct V_29 * V_32 ;
V_32 = F_45 ( sizeof( * V_32 ) , V_95 ) ;
if ( ! V_32 )
return NULL ;
F_46 ( & V_32 -> V_60 , F_26 ) ;
V_32 -> V_57 = F_42 ( V_32 ) ;
return V_32 ;
}
static void F_47 ( struct V_29 * V_32 )
{
F_48 ( V_32 ) ;
}
static void F_49 ( struct V_29 * V_32 ,
struct V_1 * V_2 ,
struct V_33 * V_38 )
{
unsigned int V_96 = F_50 ( V_2 -> V_97 -> V_98 ) ;
if ( V_96 >= V_36 )
return;
F_18 ( & V_55 ) ;
V_32 -> V_37 [ V_96 ] . V_2 = V_2 ;
V_32 -> V_37 [ V_96 ] . V_38 = V_38 ;
V_32 -> V_42 . V_45 [ V_96 ] . V_47 = 0 ;
V_32 -> V_42 . V_45 [ V_96 ] . V_46 = 0 ;
V_32 -> V_57 = F_42 ( V_32 ) ;
V_2 -> V_30 . V_31 = V_32 ;
F_19 ( & V_55 ) ;
}
static void F_51 ( struct V_29 * V_32 ,
struct V_1 * V_2 )
{
int V_35 ;
for ( V_35 = 0 ; V_35 < V_36 ; V_35 ++ )
if ( V_32 -> V_37 [ V_35 ] . V_2 == V_2 )
break;
if ( V_35 == V_36 )
return;
F_18 ( & V_55 ) ;
memset ( & V_32 -> V_37 [ V_35 ] , 0 , sizeof( * V_32 -> V_37 ) ) ;
V_2 -> V_30 . V_31 = NULL ;
V_32 -> V_57 = F_42 ( V_32 ) ;
F_19 ( & V_55 ) ;
}
void F_52 ( struct V_1 * V_2 , struct V_33 * V_38 )
{
struct V_29 * V_32 = NULL ;
struct V_1 * V_99 ;
if ( ! F_53 ( V_2 , V_100 ) ||
! F_53 ( V_2 , V_101 ) ||
( F_53 ( V_2 , V_102 ) != V_36 ) )
return;
V_99 = F_54 ( V_2 ) ;
if ( V_99 )
V_32 = V_99 -> V_30 . V_31 ;
if ( ! V_32 ) {
V_32 = F_44 () ;
if ( ! V_32 ) {
F_15 ( V_2 , L_4 ) ;
return;
}
}
F_49 ( V_32 , V_2 , V_38 ) ;
if ( ! V_32 -> V_94 . V_103 ) {
V_32 -> V_94 . V_103 = F_38 ;
if ( F_55 ( & V_32 -> V_94 ) ) {
V_32 -> V_94 . V_103 = NULL ;
F_15 ( V_2 , L_5 ) ;
}
}
}
void F_56 ( struct V_1 * V_2 )
{
struct V_29 * V_32 ;
int V_35 ;
V_32 = F_10 ( V_2 ) ;
if ( ! V_32 )
return;
if ( F_12 ( V_32 ) )
F_16 ( V_32 ) ;
F_51 ( V_32 , V_2 ) ;
for ( V_35 = 0 ; V_35 < V_36 ; V_35 ++ )
if ( V_32 -> V_37 [ V_35 ] . V_2 )
break;
if ( V_35 == V_36 ) {
if ( V_32 -> V_94 . V_103 )
F_57 ( & V_32 -> V_94 ) ;
F_58 ( & V_32 -> V_60 ) ;
F_47 ( V_32 ) ;
}
}
bool F_59 ( struct V_1 * V_2 )
{
struct V_29 * V_32 ;
bool V_104 ;
F_18 ( & V_55 ) ;
V_32 = F_10 ( V_2 ) ;
V_104 = V_32 && F_12 ( V_32 ) ;
F_19 ( & V_55 ) ;
return V_104 ;
}
static int F_60 ( struct V_1 * V_2 , bool V_105 )
{
struct V_29 * V_32 ;
int V_106 = 0 ;
bool V_107 ;
F_61 () ;
V_32 = F_10 ( V_2 ) ;
if ( ! V_32 ) {
V_106 = - V_108 ;
goto V_109;
}
V_107 = F_12 ( V_32 ) ;
if ( ! F_42 ( V_32 ) && V_105 ) {
V_106 = - V_110 ;
goto V_109;
}
if ( V_32 -> V_57 == V_105 )
goto V_109;
V_32 -> V_57 = V_105 ;
if ( ( V_107 && ! V_105 ) || V_105 )
F_17 ( V_32 ) ;
V_109:
F_30 () ;
return V_106 ;
}
int F_62 ( struct V_1 * V_2 )
{
return F_60 ( V_2 , false ) ;
}
int F_63 ( struct V_1 * V_2 )
{
return F_60 ( V_2 , true ) ;
}
struct V_33 * F_64 ( struct V_1 * V_2 )
{
struct V_33 * V_34 = NULL ;
struct V_29 * V_32 ;
F_18 ( & V_55 ) ;
V_32 = F_10 ( V_2 ) ;
if ( ! ( V_32 && F_12 ( V_32 ) ) )
goto V_109;
if ( V_32 -> V_42 . V_78 == V_79 ) {
V_34 = V_32 -> V_42 . V_45 [ 0 ] . V_46 ?
V_32 -> V_37 [ 0 ] . V_38 : V_32 -> V_37 [ 1 ] . V_38 ;
} else {
V_34 = V_32 -> V_37 [ 0 ] . V_38 ;
}
if ( V_34 )
F_65 ( V_34 ) ;
V_109:
F_19 ( & V_55 ) ;
return V_34 ;
}
bool F_66 ( struct V_111 * V_112 , struct V_113 * V_30 )
{
struct V_1 * V_2 = F_28 ( V_30 , struct V_1 ,
V_30 ) ;
struct V_29 * V_32 ;
if ( V_112 -> V_114 != V_58 )
return true ;
V_32 = F_10 ( V_2 ) ;
if ( ! V_32 || ! F_12 ( V_32 ) || V_32 -> V_37 [ 0 ] . V_2 == V_2 )
return true ;
return false ;
}
