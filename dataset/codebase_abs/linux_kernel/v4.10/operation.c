static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
unsigned long V_5 ;
F_2 ( & V_4 -> V_6 , V_5 ) ;
switch ( V_4 -> V_7 ) {
case V_8 :
break;
case V_9 :
if ( F_3 ( V_2 ) )
goto V_10;
break;
case V_11 :
if ( ! F_4 ( V_2 ) )
goto V_10;
break;
default:
goto V_10;
}
if ( V_2 -> V_12 ++ == 0 )
F_5 ( & V_2 -> V_13 , & V_4 -> V_14 ) ;
F_6 ( V_2 ) ;
F_7 ( & V_4 -> V_6 , V_5 ) ;
return 0 ;
V_10:
F_7 ( & V_4 -> V_6 , V_5 ) ;
return - V_15 ;
}
static void F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
unsigned long V_5 ;
F_2 ( & V_4 -> V_6 , V_5 ) ;
F_9 ( V_2 ) ;
if ( -- V_2 -> V_12 == 0 ) {
F_10 ( & V_2 -> V_13 ) ;
if ( F_11 ( & V_2 -> V_16 ) )
F_12 ( & V_17 ) ;
}
F_7 ( & V_4 -> V_6 , V_5 ) ;
}
static bool F_13 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
unsigned long V_5 ;
bool V_18 ;
F_2 ( & V_4 -> V_6 , V_5 ) ;
V_18 = V_2 -> V_12 ;
F_7 ( & V_4 -> V_6 , V_5 ) ;
return V_18 ;
}
static bool F_14 ( struct V_1 * V_2 , int V_19 )
{
unsigned long V_5 ;
int V_20 ;
if ( V_19 == - V_21 ) {
F_2 ( & V_22 , V_5 ) ;
V_20 = V_2 -> V_23 ;
if ( V_20 == - V_24 )
V_2 -> V_23 = V_19 ;
else
V_2 -> V_23 = - V_25 ;
F_7 ( & V_22 , V_5 ) ;
F_15 ( V_20 != - V_24 ) ;
return true ;
}
if ( F_15 ( V_19 == - V_24 ) )
V_19 = - V_25 ;
F_2 ( & V_22 , V_5 ) ;
V_20 = V_2 -> V_23 ;
if ( V_20 == - V_21 )
V_2 -> V_23 = V_19 ;
F_7 ( & V_22 , V_5 ) ;
return V_20 == - V_21 ;
}
int F_16 ( struct V_1 * V_2 )
{
int V_19 = V_2 -> V_23 ;
F_15 ( V_19 == - V_24 ) ;
F_15 ( V_19 == - V_21 ) ;
return V_19 ;
}
static struct V_1 *
F_17 ( struct V_3 * V_4 , T_1 V_26 )
{
struct V_1 * V_2 ;
unsigned long V_5 ;
bool V_27 = false ;
F_2 ( & V_4 -> V_6 , V_5 ) ;
F_18 (operation, &connection->operations, links)
if ( V_2 -> V_28 == V_26 &&
! F_3 ( V_2 ) ) {
F_19 ( V_2 ) ;
V_27 = true ;
break;
}
F_7 ( & V_4 -> V_6 , V_5 ) ;
return V_27 ? V_2 : NULL ;
}
static int F_20 ( struct V_29 * V_30 , T_2 V_31 )
{
struct V_3 * V_4 = V_30 -> V_2 -> V_4 ;
F_21 ( V_30 ) ;
return V_4 -> V_32 -> V_33 -> V_34 ( V_4 -> V_32 ,
V_4 -> V_35 ,
V_30 ,
V_31 ) ;
}
static void F_22 ( struct V_29 * V_30 )
{
struct V_36 * V_32 = V_30 -> V_2 -> V_4 -> V_32 ;
V_32 -> V_33 -> V_37 ( V_30 ) ;
}
static void F_23 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_38 ;
int V_18 ;
if ( V_4 -> V_39 ) {
V_38 = V_4 -> V_39 ( V_2 ) ;
} else {
F_24 ( & V_4 -> V_32 -> V_40 ,
L_1 ,
V_4 -> V_41 , V_2 -> type ) ;
V_38 = - V_42 ;
}
V_18 = F_25 ( V_2 , V_38 ) ;
if ( V_18 ) {
F_24 ( & V_4 -> V_32 -> V_40 ,
L_2 ,
V_4 -> V_41 , V_38 , V_2 -> type , V_18 ) ;
return;
}
}
static void F_26 ( struct V_43 * V_44 )
{
struct V_1 * V_2 ;
V_2 = F_27 ( V_44 , struct V_1 , V_44 ) ;
if ( F_3 ( V_2 ) )
F_23 ( V_2 ) ;
else
V_2 -> V_45 ( V_2 ) ;
F_8 ( V_2 ) ;
F_28 ( V_2 ) ;
}
static void F_29 ( struct V_36 * V_32 ,
struct V_29 * V_30 , T_1 V_26 ,
T_3 V_46 , T_4 type )
{
struct V_47 * V_48 ;
V_48 = V_30 -> V_49 ;
V_30 -> V_48 = V_48 ;
V_30 -> V_50 = V_46 ? V_48 + 1 : NULL ;
V_30 -> V_46 = V_46 ;
if ( type != V_51 ) {
T_1 V_52 = ( T_1 ) ( sizeof( * V_48 ) + V_46 ) ;
V_48 -> V_53 = F_30 ( V_52 ) ;
V_48 -> V_26 = 0 ;
V_48 -> type = type ;
V_48 -> V_19 = 0 ;
}
}
static struct V_29 *
F_31 ( struct V_36 * V_32 , T_4 type ,
T_3 V_46 , T_2 V_54 )
{
struct V_29 * V_30 ;
struct V_47 * V_48 ;
T_3 V_52 = V_46 + sizeof( * V_48 ) ;
if ( V_52 > V_32 -> V_55 ) {
F_32 ( & V_32 -> V_40 , L_3 ,
V_52 , V_32 -> V_55 ) ;
return NULL ;
}
V_30 = F_33 ( V_56 , V_54 ) ;
if ( ! V_30 )
return NULL ;
V_30 -> V_49 = F_34 ( V_52 , V_54 ) ;
if ( ! V_30 -> V_49 )
goto V_57;
F_29 ( V_32 , V_30 , 0 , V_46 , type ) ;
return V_30 ;
V_57:
F_35 ( V_56 , V_30 ) ;
return NULL ;
}
static void F_36 ( struct V_29 * V_30 )
{
F_37 ( V_30 -> V_49 ) ;
F_35 ( V_56 , V_30 ) ;
}
static int F_38 ( T_4 V_38 )
{
switch ( V_38 ) {
case V_58 :
return 0 ;
case V_59 :
return - V_60 ;
case V_61 :
return - V_62 ;
case V_63 :
return - V_64 ;
case V_65 :
return - V_42 ;
case V_66 :
return - V_67 ;
case V_68 :
return - V_69 ;
case V_70 :
return - V_71 ;
case V_72 :
return - V_73 ;
case V_74 :
return - V_25 ;
case V_75 :
default:
return - V_76 ;
}
}
static T_4 F_39 ( int V_23 )
{
switch ( V_23 ) {
case 0 :
return V_58 ;
case - V_60 :
return V_59 ;
case - V_62 :
return V_61 ;
case - V_64 :
return V_63 ;
case - V_42 :
return V_65 ;
case - V_67 :
return V_66 ;
case - V_69 :
return V_68 ;
case - V_71 :
return V_70 ;
case - V_25 :
return V_74 ;
case - V_73 :
return V_72 ;
case - V_76 :
default:
return V_75 ;
}
}
bool F_40 ( struct V_1 * V_2 ,
T_3 V_77 , T_2 V_31 )
{
struct V_36 * V_32 = V_2 -> V_4 -> V_32 ;
struct V_47 * V_78 ;
struct V_29 * V_79 ;
T_4 type ;
type = V_2 -> type | V_80 ;
V_79 = F_31 ( V_32 , type , V_77 , V_31 ) ;
if ( ! V_79 )
return false ;
V_79 -> V_2 = V_2 ;
V_78 = V_2 -> V_81 -> V_48 ;
V_79 -> V_48 -> V_26 = V_78 -> V_26 ;
V_2 -> V_79 = V_79 ;
return true ;
}
static struct V_1 *
F_41 ( struct V_3 * V_4 , T_4 type ,
T_3 V_82 , T_3 V_77 ,
unsigned long V_83 , T_2 V_54 )
{
struct V_36 * V_32 = V_4 -> V_32 ;
struct V_1 * V_2 ;
V_2 = F_33 ( V_84 , V_54 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_4 = V_4 ;
V_2 -> V_81 = F_31 ( V_32 , type , V_82 ,
V_54 ) ;
if ( ! V_2 -> V_81 )
goto V_85;
V_2 -> V_81 -> V_2 = V_2 ;
if ( ! ( V_83 & V_86 ) ) {
if ( ! F_40 ( V_2 , V_77 ,
V_54 ) ) {
goto V_87;
}
}
V_2 -> V_5 = V_83 ;
V_2 -> type = type ;
V_2 -> V_23 = - V_24 ;
F_42 ( & V_2 -> V_44 , F_26 ) ;
F_43 ( & V_2 -> V_88 ) ;
F_44 ( & V_2 -> V_89 ) ;
F_45 ( & V_2 -> V_16 , 0 ) ;
return V_2 ;
V_87:
F_36 ( V_2 -> V_81 ) ;
V_85:
F_35 ( V_84 , V_2 ) ;
return NULL ;
}
struct V_1 *
F_46 ( struct V_3 * V_4 ,
T_4 type , T_3 V_82 ,
T_3 V_77 , unsigned long V_5 ,
T_2 V_31 )
{
struct V_1 * V_2 ;
if ( F_47 ( type == V_51 ) )
return NULL ;
if ( F_47 ( type & V_80 ) )
type &= ~ V_80 ;
if ( F_47 ( V_5 & ~ V_90 ) )
V_5 &= V_90 ;
V_2 = F_41 ( V_4 , type ,
V_82 , V_77 ,
V_5 , V_31 ) ;
if ( V_2 )
F_48 ( V_2 ) ;
return V_2 ;
}
struct V_1 *
F_49 ( struct V_3 * V_4 ,
T_4 type , T_3 V_82 ,
T_3 V_77 , unsigned long V_5 ,
T_2 V_31 )
{
struct V_1 * V_2 ;
V_5 |= V_91 ;
V_2 = F_41 ( V_4 , type ,
V_82 , V_77 ,
V_5 , V_31 ) ;
if ( V_2 )
F_50 ( V_2 ) ;
return V_2 ;
}
T_3 F_51 ( struct V_3 * V_4 )
{
struct V_36 * V_32 = V_4 -> V_32 ;
return V_32 -> V_55 - sizeof( struct V_47 ) ;
}
static struct V_1 *
F_52 ( struct V_3 * V_4 , T_1 V_28 ,
T_4 type , void * V_92 , T_3 V_53 )
{
struct V_1 * V_2 ;
T_3 V_82 ;
unsigned long V_5 = V_86 ;
V_82 = V_53 - sizeof( struct V_47 ) ;
if ( ! V_28 )
V_5 |= V_93 ;
V_2 = F_41 ( V_4 , type ,
V_82 ,
V_51 ,
V_5 , V_94 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_28 = V_28 ;
memcpy ( V_2 -> V_81 -> V_48 , V_92 , V_53 ) ;
F_53 ( V_2 ) ;
return V_2 ;
}
void F_19 ( struct V_1 * V_2 )
{
F_54 ( & V_2 -> V_89 ) ;
}
static void F_55 ( struct V_89 * V_89 )
{
struct V_1 * V_2 ;
V_2 = F_27 ( V_89 , struct V_1 , V_89 ) ;
F_56 ( V_2 ) ;
if ( V_2 -> V_79 )
F_36 ( V_2 -> V_79 ) ;
F_36 ( V_2 -> V_81 ) ;
F_35 ( V_84 , V_2 ) ;
}
void F_28 ( struct V_1 * V_2 )
{
if ( F_15 ( ! V_2 ) )
return;
F_57 ( & V_2 -> V_89 , F_55 ) ;
}
static void F_58 ( struct V_1 * V_2 )
{
F_59 ( & V_2 -> V_88 ) ;
}
int F_60 ( struct V_1 * V_2 ,
T_5 V_45 ,
T_2 V_31 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_47 * V_48 ;
unsigned int V_95 ;
int V_18 ;
if ( F_61 ( V_4 ) )
return - V_96 ;
if ( ! V_45 )
return - V_69 ;
V_2 -> V_45 = V_45 ;
if ( F_62 ( V_2 ) ) {
V_2 -> V_28 = 0 ;
} else {
V_95 = ( unsigned int ) F_63 ( & V_4 -> V_97 ) ;
V_2 -> V_28 = ( T_1 ) ( V_95 % V_98 + 1 ) ;
}
V_48 = V_2 -> V_81 -> V_48 ;
V_48 -> V_26 = F_30 ( V_2 -> V_28 ) ;
F_14 ( V_2 , - V_21 ) ;
F_19 ( V_2 ) ;
V_18 = F_1 ( V_2 ) ;
if ( V_18 )
goto V_99;
V_18 = F_20 ( V_2 -> V_81 , V_31 ) ;
if ( V_18 )
goto V_100;
return 0 ;
V_100:
F_8 ( V_2 ) ;
V_99:
F_28 ( V_2 ) ;
return V_18 ;
}
int F_64 ( struct V_1 * V_2 ,
unsigned int V_101 )
{
int V_18 ;
unsigned long V_102 ;
V_18 = F_60 ( V_2 , F_58 ,
V_103 ) ;
if ( V_18 )
return V_18 ;
if ( V_101 )
V_102 = F_65 ( V_101 ) ;
else
V_102 = V_104 ;
V_18 = F_66 ( & V_2 -> V_88 ,
V_102 ) ;
if ( V_18 < 0 ) {
F_67 ( V_2 , - V_105 ) ;
} else if ( V_18 == 0 ) {
F_67 ( V_2 , - V_62 ) ;
}
return F_16 ( V_2 ) ;
}
static int F_25 ( struct V_1 * V_2 ,
int V_23 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_18 ;
if ( ! V_2 -> V_79 &&
! F_62 ( V_2 ) ) {
if ( ! F_40 ( V_2 , 0 , V_103 ) )
return - V_64 ;
}
if ( ! F_14 ( V_2 , V_23 ) ) {
F_24 ( & V_4 -> V_32 -> V_40 , L_4 ) ;
return - V_76 ;
}
if ( F_62 ( V_2 ) )
return 0 ;
F_19 ( V_2 ) ;
V_18 = F_1 ( V_2 ) ;
if ( V_18 )
goto V_99;
V_2 -> V_79 -> V_48 -> V_19 = F_39 ( V_23 ) ;
V_18 = F_20 ( V_2 -> V_79 , V_103 ) ;
if ( V_18 )
goto V_100;
return 0 ;
V_100:
F_8 ( V_2 ) ;
V_99:
F_28 ( V_2 ) ;
return V_18 ;
}
void F_68 ( struct V_36 * V_32 ,
struct V_29 * V_30 , int V_38 )
{
struct V_1 * V_2 = V_30 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_30 == V_2 -> V_79 ) {
if ( V_38 ) {
F_24 ( & V_4 -> V_32 -> V_40 ,
L_5 ,
V_4 -> V_41 , V_2 -> type , V_38 ) ;
}
F_8 ( V_2 ) ;
F_28 ( V_2 ) ;
} else if ( V_38 || F_62 ( V_2 ) ) {
if ( F_14 ( V_2 , V_38 ) ) {
F_69 ( V_106 ,
& V_2 -> V_44 ) ;
}
}
}
static void F_70 ( struct V_3 * V_4 ,
const struct V_47 * V_48 ,
void * V_92 , T_3 V_53 )
{
struct V_1 * V_2 ;
T_1 V_26 ;
T_4 type ;
int V_18 ;
V_26 = F_71 ( V_48 -> V_26 ) ;
type = V_48 -> type ;
V_2 = F_52 ( V_4 , V_26 ,
type , V_92 , V_53 ) ;
if ( ! V_2 ) {
F_24 ( & V_4 -> V_32 -> V_40 ,
L_6 ,
V_4 -> V_41 ) ;
return;
}
V_18 = F_1 ( V_2 ) ;
if ( V_18 ) {
F_28 ( V_2 ) ;
return;
}
F_72 ( V_2 -> V_81 ) ;
if ( F_14 ( V_2 , - V_21 ) )
F_69 ( V_4 -> V_107 , & V_2 -> V_44 ) ;
}
static void F_73 ( struct V_3 * V_4 ,
const struct V_47 * V_48 ,
void * V_92 , T_3 V_53 )
{
struct V_1 * V_2 ;
struct V_29 * V_30 ;
T_3 V_52 ;
T_1 V_26 ;
int V_23 ;
V_26 = F_71 ( V_48 -> V_26 ) ;
if ( ! V_26 ) {
F_74 ( & V_4 -> V_32 -> V_40 ,
L_7 ,
V_4 -> V_41 ) ;
return;
}
V_2 = F_17 ( V_4 , V_26 ) ;
if ( ! V_2 ) {
F_74 ( & V_4 -> V_32 -> V_40 ,
L_8 ,
V_4 -> V_41 , V_26 ) ;
return;
}
V_23 = F_38 ( V_48 -> V_19 ) ;
V_30 = V_2 -> V_79 ;
V_52 = sizeof( * V_48 ) + V_30 -> V_46 ;
if ( ! V_23 && V_53 > V_52 ) {
F_74 ( & V_4 -> V_32 -> V_40 ,
L_9 ,
V_4 -> V_41 , V_48 -> type ,
V_53 , V_52 ) ;
V_23 = - V_67 ;
} else if ( ! V_23 && V_53 < V_52 ) {
if ( F_75 ( V_2 ) ) {
V_30 -> V_46 = V_53 - sizeof( * V_48 ) ;
} else {
F_74 ( & V_4 -> V_32 -> V_40 ,
L_10 ,
V_4 -> V_41 , V_48 -> type ,
V_53 , V_52 ) ;
V_23 = - V_67 ;
}
}
if ( V_23 )
V_53 = sizeof( * V_48 ) ;
if ( F_14 ( V_2 , V_23 ) ) {
memcpy ( V_30 -> V_49 , V_92 , V_53 ) ;
F_76 ( V_30 ) ;
F_69 ( V_106 , & V_2 -> V_44 ) ;
}
F_28 ( V_2 ) ;
}
void F_77 ( struct V_3 * V_4 ,
void * V_92 , T_3 V_53 )
{
struct V_47 V_48 ;
struct V_108 * V_40 = & V_4 -> V_32 -> V_40 ;
T_3 V_109 ;
if ( V_4 -> V_7 == V_110 ||
F_61 ( V_4 ) ) {
F_78 ( V_40 , L_11 ,
V_4 -> V_41 , V_53 ) ;
return;
}
if ( V_53 < sizeof( V_48 ) ) {
F_74 ( V_40 , L_12 ,
V_4 -> V_41 ) ;
return;
}
memcpy ( & V_48 , V_92 , sizeof( V_48 ) ) ;
V_109 = F_71 ( V_48 . V_53 ) ;
if ( V_53 < V_109 ) {
F_74 ( V_40 ,
L_13 ,
V_4 -> V_41 ,
F_71 ( V_48 . V_26 ) ,
V_48 . type , V_53 , V_109 ) ;
return;
}
if ( V_48 . type & V_80 ) {
F_73 ( V_4 , & V_48 , V_92 ,
V_109 ) ;
} else {
F_70 ( V_4 , & V_48 , V_92 ,
V_109 ) ;
}
}
void F_67 ( struct V_1 * V_2 , int V_23 )
{
if ( F_15 ( F_3 ( V_2 ) ) )
return;
if ( F_14 ( V_2 , V_23 ) ) {
F_22 ( V_2 -> V_81 ) ;
F_69 ( V_106 , & V_2 -> V_44 ) ;
}
F_79 ( V_2 -> V_81 ) ;
F_80 ( & V_2 -> V_16 ) ;
F_81 ( V_17 ,
! F_13 ( V_2 ) ) ;
F_82 ( & V_2 -> V_16 ) ;
}
void F_83 ( struct V_1 * V_2 , int V_23 )
{
if ( F_15 ( ! F_3 ( V_2 ) ) )
return;
if ( ! F_62 ( V_2 ) ) {
F_84 ( & V_2 -> V_44 ) ;
if ( ! F_14 ( V_2 , V_23 ) )
F_22 ( V_2 -> V_79 ) ;
}
F_85 ( V_2 -> V_79 ) ;
F_80 ( & V_2 -> V_16 ) ;
F_81 ( V_17 ,
! F_13 ( V_2 ) ) ;
F_82 ( & V_2 -> V_16 ) ;
}
int F_86 ( struct V_3 * V_4 , int type ,
void * V_81 , int V_82 ,
void * V_79 , int V_77 ,
unsigned int V_101 )
{
struct V_1 * V_2 ;
int V_18 ;
if ( ( V_77 && ! V_79 ) ||
( V_82 && ! V_81 ) )
return - V_69 ;
V_2 = F_87 ( V_4 , type ,
V_82 , V_77 ,
V_103 ) ;
if ( ! V_2 )
return - V_64 ;
if ( V_82 )
memcpy ( V_2 -> V_81 -> V_50 , V_81 , V_82 ) ;
V_18 = F_64 ( V_2 , V_101 ) ;
if ( V_18 ) {
F_24 ( & V_4 -> V_32 -> V_40 ,
L_14 ,
V_4 -> V_41 , V_2 -> V_28 , type , V_18 ) ;
} else {
if ( V_77 ) {
memcpy ( V_79 , V_2 -> V_79 -> V_50 ,
V_77 ) ;
}
}
F_28 ( V_2 ) ;
return V_18 ;
}
int F_88 ( struct V_3 * V_4 ,
int type , void * V_81 , int V_82 ,
unsigned int V_101 )
{
struct V_1 * V_2 ;
int V_18 ;
if ( V_82 && ! V_81 )
return - V_69 ;
V_2 = F_46 ( V_4 , type ,
V_82 , 0 ,
V_93 ,
V_103 ) ;
if ( ! V_2 )
return - V_64 ;
if ( V_82 )
memcpy ( V_2 -> V_81 -> V_50 , V_81 , V_82 ) ;
V_18 = F_64 ( V_2 , V_101 ) ;
if ( V_18 ) {
F_24 ( & V_4 -> V_32 -> V_40 ,
L_15 ,
V_4 -> V_41 , type , V_18 ) ;
}
F_28 ( V_2 ) ;
return V_18 ;
}
int T_6 F_89 ( void )
{
V_56 = F_90 ( L_16 ,
sizeof( struct V_29 ) , 0 , 0 , NULL ) ;
if ( ! V_56 )
return - V_64 ;
V_84 = F_90 ( L_17 ,
sizeof( struct V_1 ) , 0 , 0 , NULL ) ;
if ( ! V_84 )
goto V_111;
V_106 = F_91 ( L_18 ,
0 , 0 ) ;
if ( ! V_106 )
goto V_112;
return 0 ;
V_112:
F_92 ( V_84 ) ;
V_84 = NULL ;
V_111:
F_92 ( V_56 ) ;
V_56 = NULL ;
return - V_64 ;
}
void F_93 ( void )
{
F_94 ( V_106 ) ;
V_106 = NULL ;
F_92 ( V_84 ) ;
V_84 = NULL ;
F_92 ( V_56 ) ;
V_56 = NULL ;
}
