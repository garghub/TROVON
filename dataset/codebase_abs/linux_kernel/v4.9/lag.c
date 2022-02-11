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
if ( V_42 -> V_45 == V_46 ) {
if ( V_42 -> V_47 [ 0 ] . V_48 ) {
* V_43 = 1 ;
* V_44 = 1 ;
} else {
* V_43 = 2 ;
* V_44 = 2 ;
}
} else {
* V_43 = 1 ;
* V_44 = 2 ;
if ( ! V_42 -> V_47 [ 0 ] . V_49 )
* V_43 = 2 ;
else if ( ! V_42 -> V_47 [ 1 ] . V_49 )
* V_44 = 1 ;
}
}
static void F_14 ( struct V_29 * V_32 ,
struct V_41 * V_42 )
{
struct V_1 * V_50 = V_32 -> V_37 [ 0 ] . V_2 ;
int V_51 ;
V_32 -> V_39 |= V_40 ;
F_13 ( V_42 , & V_32 -> V_52 [ 0 ] ,
& V_32 -> V_52 [ 1 ] ) ;
V_51 = F_1 ( V_50 , V_32 -> V_52 [ 0 ] , V_32 -> V_52 [ 1 ] ) ;
if ( V_51 )
F_15 ( V_50 ,
L_1 ,
V_51 ) ;
}
static void F_16 ( struct V_29 * V_32 )
{
struct V_1 * V_50 = V_32 -> V_37 [ 0 ] . V_2 ;
int V_51 ;
V_32 -> V_39 &= ~ V_40 ;
V_51 = F_7 ( V_50 ) ;
if ( V_51 )
F_15 ( V_50 ,
L_2 ,
V_51 ) ;
}
static void F_17 ( struct V_29 * V_32 )
{
struct V_1 * V_50 = V_32 -> V_37 [ 0 ] . V_2 ;
struct V_1 * V_53 = V_32 -> V_37 [ 1 ] . V_2 ;
struct V_41 V_42 ;
T_1 V_54 , V_55 ;
int V_35 , V_51 ;
if ( ! V_50 || ! V_53 )
return;
F_18 ( & V_56 ) ;
V_42 = V_32 -> V_42 ;
F_19 ( & V_56 ) ;
if ( V_42 . V_57 && ! F_12 ( V_32 ) ) {
if ( F_20 ( V_50 ) ||
F_20 ( V_53 ) ) {
F_21 ( V_50 , L_3 ) ;
return;
}
for ( V_35 = 0 ; V_35 < V_36 ; V_35 ++ )
F_22 ( V_32 -> V_37 [ V_35 ] . V_2 ,
V_58 ) ;
F_14 ( V_32 , & V_42 ) ;
F_23 ( V_50 , V_58 ) ;
F_24 ( V_53 ) ;
} else if ( V_42 . V_57 && F_12 ( V_32 ) ) {
F_13 ( & V_42 , & V_54 ,
& V_55 ) ;
if ( ( V_54 != V_32 -> V_52 [ 0 ] ) ||
( V_55 != V_32 -> V_52 [ 1 ] ) ) {
V_32 -> V_52 [ 0 ] = V_54 ;
V_32 -> V_52 [ 1 ] = V_55 ;
V_51 = F_6 ( V_50 , V_54 , V_55 ) ;
if ( V_51 )
F_15 ( V_50 ,
L_4 ,
V_51 ) ;
}
} else if ( ! V_42 . V_57 && F_12 ( V_32 ) ) {
F_22 ( V_50 , V_58 ) ;
F_25 ( V_53 ) ;
F_16 ( V_32 ) ;
for ( V_35 = 0 ; V_35 < V_36 ; V_35 ++ )
if ( V_32 -> V_37 [ V_35 ] . V_2 )
F_23 ( V_32 -> V_37 [ V_35 ] . V_2 ,
V_58 ) ;
}
}
static void F_26 ( struct V_29 * V_32 , unsigned long V_59 )
{
F_27 ( & V_32 -> V_60 , V_59 ) ;
}
static void F_28 ( struct V_61 * V_62 )
{
struct V_63 * V_63 = F_29 ( V_62 ) ;
struct V_29 * V_32 = F_30 ( V_63 , struct V_29 ,
V_60 ) ;
int V_64 ;
V_64 = F_31 () ;
if ( ! V_64 ) {
F_26 ( V_32 , V_65 ) ;
return;
}
F_17 ( V_32 ) ;
F_32 () ;
}
static int F_33 ( struct V_29 * V_32 ,
struct V_41 * V_42 ,
struct V_33 * V_34 ,
struct V_66 * V_67 )
{
struct V_33 * V_68 = V_67 -> V_69 , * V_70 ;
struct V_71 * V_72 ;
bool V_57 ;
int V_73 = 0 ;
int V_74 = 0 ;
int V_75 ;
if ( ! F_34 ( V_68 ) )
return 0 ;
V_72 = V_67 -> V_76 ;
F_35 () ;
F_36 (upper, ndev_tmp) {
V_75 = F_11 ( V_32 , V_70 ) ;
if ( V_75 > - 1 )
V_73 |= ( 1 << V_75 ) ;
V_74 ++ ;
}
F_37 () ;
if ( ! ( V_73 & 0x3 ) )
return 0 ;
if ( V_72 )
V_42 -> V_45 = V_72 -> V_45 ;
V_57 = ( V_74 == V_36 ) &&
( V_73 == 0x3 ) &&
( ( V_42 -> V_45 == V_46 ) ||
( V_42 -> V_45 == V_77 ) ) ;
if ( V_42 -> V_57 != V_57 ) {
V_42 -> V_57 = V_57 ;
return 1 ;
}
return 0 ;
}
static int F_38 ( struct V_29 * V_32 ,
struct V_41 * V_42 ,
struct V_33 * V_34 ,
struct V_78 * V_67 )
{
struct V_79 * V_80 ;
int V_75 ;
if ( ! F_39 ( V_34 ) )
return 0 ;
V_75 = F_11 ( V_32 , V_34 ) ;
if ( V_75 == - 1 )
return 0 ;
V_80 = V_67 -> V_81 ;
if ( ! V_80 )
return 0 ;
V_42 -> V_47 [ V_75 ] = * V_80 ;
return 1 ;
}
static int F_40 ( struct V_82 * V_83 ,
unsigned long V_84 , void * V_85 )
{
struct V_33 * V_34 = F_41 ( V_85 ) ;
struct V_41 V_42 ;
struct V_29 * V_32 ;
int V_86 = 0 ;
if ( ! F_42 ( F_43 ( V_34 ) , & V_87 ) )
return V_88 ;
if ( ( V_84 != V_89 ) && ( V_84 != V_90 ) )
return V_88 ;
V_32 = F_30 ( V_83 , struct V_29 , V_91 ) ;
V_42 = V_32 -> V_42 ;
switch ( V_84 ) {
case V_89 :
V_86 = F_33 ( V_32 , & V_42 , V_34 ,
V_85 ) ;
break;
case V_90 :
V_86 = F_38 ( V_32 , & V_42 ,
V_34 , V_85 ) ;
break;
}
F_18 ( & V_56 ) ;
V_32 -> V_42 = V_42 ;
F_19 ( & V_56 ) ;
if ( V_86 )
F_26 ( V_32 , 0 ) ;
return V_88 ;
}
static struct V_29 * F_44 ( void )
{
struct V_29 * V_32 ;
V_32 = F_45 ( sizeof( * V_32 ) , V_92 ) ;
if ( ! V_32 )
return NULL ;
F_46 ( & V_32 -> V_60 , F_28 ) ;
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
unsigned int V_93 = F_50 ( V_2 -> V_94 -> V_95 ) ;
if ( V_93 >= V_36 )
return;
F_18 ( & V_56 ) ;
V_32 -> V_37 [ V_93 ] . V_2 = V_2 ;
V_32 -> V_37 [ V_93 ] . V_38 = V_38 ;
V_32 -> V_42 . V_47 [ V_93 ] . V_49 = 0 ;
V_32 -> V_42 . V_47 [ V_93 ] . V_48 = 0 ;
V_2 -> V_30 . V_31 = V_32 ;
F_19 ( & V_56 ) ;
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
F_18 ( & V_56 ) ;
memset ( & V_32 -> V_37 [ V_35 ] , 0 , sizeof( * V_32 -> V_37 ) ) ;
V_2 -> V_30 . V_31 = NULL ;
F_19 ( & V_56 ) ;
}
void F_52 ( struct V_1 * V_2 , struct V_33 * V_38 )
{
struct V_29 * V_32 = NULL ;
struct V_1 * V_96 ;
if ( ! F_53 ( V_2 , V_97 ) ||
! F_53 ( V_2 , V_98 ) ||
( F_53 ( V_2 , V_99 ) != V_36 ) )
return;
V_96 = F_54 ( V_2 ) ;
if ( V_96 )
V_32 = V_96 -> V_30 . V_31 ;
if ( ! V_32 ) {
V_32 = F_44 () ;
if ( ! V_32 ) {
F_15 ( V_2 , L_5 ) ;
return;
}
}
F_49 ( V_32 , V_2 , V_38 ) ;
if ( ! V_32 -> V_91 . V_100 ) {
V_32 -> V_91 . V_100 = F_40 ;
if ( F_55 ( & V_32 -> V_91 ) ) {
V_32 -> V_91 . V_100 = NULL ;
F_15 ( V_2 , L_6 ) ;
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
if ( V_32 -> V_91 . V_100 )
F_57 ( & V_32 -> V_91 ) ;
F_58 ( & V_32 -> V_60 ) ;
F_47 ( V_32 ) ;
}
}
bool F_59 ( struct V_1 * V_2 )
{
struct V_29 * V_32 ;
bool V_101 ;
F_18 ( & V_56 ) ;
V_32 = F_10 ( V_2 ) ;
V_101 = V_32 && F_12 ( V_32 ) ;
F_19 ( & V_56 ) ;
return V_101 ;
}
struct V_33 * F_60 ( struct V_1 * V_2 )
{
struct V_33 * V_34 = NULL ;
struct V_29 * V_32 ;
F_18 ( & V_56 ) ;
V_32 = F_10 ( V_2 ) ;
if ( ! ( V_32 && F_12 ( V_32 ) ) )
goto V_102;
if ( V_32 -> V_42 . V_45 == V_46 ) {
V_34 = V_32 -> V_42 . V_47 [ 0 ] . V_48 ?
V_32 -> V_37 [ 0 ] . V_38 : V_32 -> V_37 [ 1 ] . V_38 ;
} else {
V_34 = V_32 -> V_37 [ 0 ] . V_38 ;
}
if ( V_34 )
F_61 ( V_34 ) ;
V_102:
F_19 ( & V_56 ) ;
return V_34 ;
}
bool F_62 ( struct V_103 * V_104 , struct V_105 * V_30 )
{
struct V_1 * V_2 = F_30 ( V_30 , struct V_1 ,
V_30 ) ;
struct V_29 * V_32 ;
if ( V_104 -> V_106 != V_58 )
return true ;
V_32 = F_10 ( V_2 ) ;
if ( ! V_32 || ! F_12 ( V_32 ) || V_32 -> V_37 [ 0 ] . V_2 == V_2 )
return true ;
return false ;
}
