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
int V_18 ;
V_2 = F_27 ( V_44 , struct V_1 , V_44 ) ;
if ( F_3 ( V_2 ) ) {
F_23 ( V_2 ) ;
} else {
V_18 = F_28 ( & V_2 -> V_45 ) ;
if ( ! V_18 ) {
if ( F_16 ( V_2 ) == - V_46 )
F_22 ( V_2 -> V_47 ) ;
}
V_2 -> V_48 ( V_2 ) ;
}
F_8 ( V_2 ) ;
F_29 ( V_2 ) ;
}
static void F_30 ( unsigned long V_49 )
{
struct V_1 * V_2 = ( void * ) V_49 ;
if ( F_14 ( V_2 , - V_46 ) ) {
F_31 ( V_50 , & V_2 -> V_44 ) ;
}
}
static void F_32 ( struct V_36 * V_32 ,
struct V_29 * V_30 , T_1 V_26 ,
T_3 V_51 , T_4 type )
{
struct V_52 * V_53 ;
V_53 = V_30 -> V_54 ;
V_30 -> V_53 = V_53 ;
V_30 -> V_55 = V_51 ? V_53 + 1 : NULL ;
V_30 -> V_51 = V_51 ;
if ( type != V_56 ) {
T_1 V_57 = ( T_1 ) ( sizeof( * V_53 ) + V_51 ) ;
V_53 -> V_58 = F_33 ( V_57 ) ;
V_53 -> V_26 = 0 ;
V_53 -> type = type ;
V_53 -> V_19 = 0 ;
}
}
static struct V_29 *
F_34 ( struct V_36 * V_32 , T_4 type ,
T_3 V_51 , T_2 V_59 )
{
struct V_29 * V_30 ;
struct V_52 * V_53 ;
T_3 V_57 = V_51 + sizeof( * V_53 ) ;
if ( V_57 > V_32 -> V_60 ) {
F_35 ( & V_32 -> V_40 , L_3 ,
V_57 , V_32 -> V_60 ) ;
return NULL ;
}
V_30 = F_36 ( V_61 , V_59 ) ;
if ( ! V_30 )
return NULL ;
V_30 -> V_54 = F_37 ( V_57 , V_59 ) ;
if ( ! V_30 -> V_54 )
goto V_62;
F_32 ( V_32 , V_30 , 0 , V_51 , type ) ;
return V_30 ;
V_62:
F_38 ( V_61 , V_30 ) ;
return NULL ;
}
static void F_39 ( struct V_29 * V_30 )
{
F_40 ( V_30 -> V_54 ) ;
F_38 ( V_61 , V_30 ) ;
}
static int F_41 ( T_4 V_38 )
{
switch ( V_38 ) {
case V_63 :
return 0 ;
case V_64 :
return - V_65 ;
case V_66 :
return - V_46 ;
case V_67 :
return - V_68 ;
case V_69 :
return - V_42 ;
case V_70 :
return - V_71 ;
case V_72 :
return - V_73 ;
case V_74 :
return - V_75 ;
case V_76 :
return - V_77 ;
case V_78 :
return - V_25 ;
case V_79 :
default:
return - V_80 ;
}
}
static T_4 F_42 ( int V_23 )
{
switch ( V_23 ) {
case 0 :
return V_63 ;
case - V_65 :
return V_64 ;
case - V_46 :
return V_66 ;
case - V_68 :
return V_67 ;
case - V_42 :
return V_69 ;
case - V_71 :
return V_70 ;
case - V_73 :
return V_72 ;
case - V_75 :
return V_74 ;
case - V_25 :
return V_78 ;
case - V_77 :
return V_76 ;
case - V_80 :
default:
return V_79 ;
}
}
bool F_43 ( struct V_1 * V_2 ,
T_3 V_81 , T_2 V_31 )
{
struct V_36 * V_32 = V_2 -> V_4 -> V_32 ;
struct V_52 * V_82 ;
struct V_29 * V_83 ;
T_4 type ;
type = V_2 -> type | V_84 ;
V_83 = F_34 ( V_32 , type , V_81 , V_31 ) ;
if ( ! V_83 )
return false ;
V_83 -> V_2 = V_2 ;
V_82 = V_2 -> V_47 -> V_53 ;
V_83 -> V_53 -> V_26 = V_82 -> V_26 ;
V_2 -> V_83 = V_83 ;
return true ;
}
static struct V_1 *
F_44 ( struct V_3 * V_4 , T_4 type ,
T_3 V_85 , T_3 V_81 ,
unsigned long V_86 , T_2 V_59 )
{
struct V_36 * V_32 = V_4 -> V_32 ;
struct V_1 * V_2 ;
V_2 = F_36 ( V_87 , V_59 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_4 = V_4 ;
V_2 -> V_47 = F_34 ( V_32 , type , V_85 ,
V_59 ) ;
if ( ! V_2 -> V_47 )
goto V_88;
V_2 -> V_47 -> V_2 = V_2 ;
if ( ! ( V_86 & V_89 ) ) {
if ( ! F_43 ( V_2 , V_81 ,
V_59 ) ) {
goto V_90;
}
F_45 ( & V_2 -> V_45 , F_30 ,
( unsigned long ) V_2 ) ;
}
V_2 -> V_5 = V_86 ;
V_2 -> type = type ;
V_2 -> V_23 = - V_24 ;
F_46 ( & V_2 -> V_44 , F_26 ) ;
F_47 ( & V_2 -> V_91 ) ;
F_48 ( & V_2 -> V_92 ) ;
F_49 ( & V_2 -> V_16 , 0 ) ;
return V_2 ;
V_90:
F_39 ( V_2 -> V_47 ) ;
V_88:
F_38 ( V_87 , V_2 ) ;
return NULL ;
}
struct V_1 *
F_50 ( struct V_3 * V_4 ,
T_4 type , T_3 V_85 ,
T_3 V_81 , unsigned long V_5 ,
T_2 V_31 )
{
struct V_1 * V_2 ;
if ( F_51 ( type == V_56 ) )
return NULL ;
if ( F_51 ( type & V_84 ) )
type &= ~ V_84 ;
if ( F_51 ( V_5 & ~ V_93 ) )
V_5 &= V_93 ;
V_2 = F_44 ( V_4 , type ,
V_85 , V_81 ,
V_5 , V_31 ) ;
if ( V_2 )
F_52 ( V_2 ) ;
return V_2 ;
}
struct V_1 *
F_53 ( struct V_3 * V_4 ,
T_4 type , T_3 V_85 ,
T_3 V_81 , unsigned long V_5 ,
T_2 V_31 )
{
struct V_1 * V_2 ;
V_5 |= V_94 ;
V_2 = F_44 ( V_4 , type ,
V_85 , V_81 ,
V_5 , V_31 ) ;
if ( V_2 )
F_54 ( V_2 ) ;
return V_2 ;
}
T_3 F_55 ( struct V_3 * V_4 )
{
struct V_36 * V_32 = V_4 -> V_32 ;
return V_32 -> V_60 - sizeof( struct V_52 ) ;
}
static struct V_1 *
F_56 ( struct V_3 * V_4 , T_1 V_28 ,
T_4 type , void * V_95 , T_3 V_58 )
{
struct V_1 * V_2 ;
T_3 V_85 ;
unsigned long V_5 = V_89 ;
V_85 = V_58 - sizeof( struct V_52 ) ;
if ( ! V_28 )
V_5 |= V_96 ;
V_2 = F_44 ( V_4 , type ,
V_85 ,
V_56 ,
V_5 , V_97 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_28 = V_28 ;
memcpy ( V_2 -> V_47 -> V_53 , V_95 , V_58 ) ;
F_57 ( V_2 ) ;
return V_2 ;
}
void F_19 ( struct V_1 * V_2 )
{
F_58 ( & V_2 -> V_92 ) ;
}
static void F_59 ( struct V_92 * V_92 )
{
struct V_1 * V_2 ;
V_2 = F_27 ( V_92 , struct V_1 , V_92 ) ;
F_60 ( V_2 ) ;
if ( V_2 -> V_83 )
F_39 ( V_2 -> V_83 ) ;
F_39 ( V_2 -> V_47 ) ;
F_38 ( V_87 , V_2 ) ;
}
void F_29 ( struct V_1 * V_2 )
{
if ( F_15 ( ! V_2 ) )
return;
F_61 ( & V_2 -> V_92 , F_59 ) ;
}
static void F_62 ( struct V_1 * V_2 )
{
F_63 ( & V_2 -> V_91 ) ;
}
int F_64 ( struct V_1 * V_2 ,
T_5 V_48 ,
unsigned int V_98 ,
T_2 V_31 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_52 * V_53 ;
unsigned int V_99 ;
int V_18 ;
if ( F_65 ( V_4 ) )
return - V_100 ;
if ( ! V_48 )
return - V_73 ;
V_2 -> V_48 = V_48 ;
if ( F_66 ( V_2 ) ) {
V_2 -> V_28 = 0 ;
} else {
V_99 = ( unsigned int ) F_67 ( & V_4 -> V_101 ) ;
V_2 -> V_28 = ( T_1 ) ( V_99 % V_102 + 1 ) ;
}
V_53 = V_2 -> V_47 -> V_53 ;
V_53 -> V_26 = F_33 ( V_2 -> V_28 ) ;
F_14 ( V_2 , - V_21 ) ;
F_19 ( V_2 ) ;
V_18 = F_1 ( V_2 ) ;
if ( V_18 )
goto V_103;
V_18 = F_20 ( V_2 -> V_47 , V_31 ) ;
if ( V_18 )
goto V_104;
if ( V_98 ) {
V_2 -> V_45 . V_105 = V_106 + F_68 ( V_98 ) ;
F_69 ( & V_2 -> V_45 ) ;
}
return 0 ;
V_104:
F_8 ( V_2 ) ;
V_103:
F_29 ( V_2 ) ;
return V_18 ;
}
int F_70 ( struct V_1 * V_2 ,
unsigned int V_98 )
{
int V_18 ;
V_18 = F_64 ( V_2 , F_62 ,
V_98 , V_107 ) ;
if ( V_18 )
return V_18 ;
V_18 = F_71 ( & V_2 -> V_91 ) ;
if ( V_18 < 0 ) {
F_72 ( V_2 , - V_108 ) ;
}
return F_16 ( V_2 ) ;
}
static int F_25 ( struct V_1 * V_2 ,
int V_23 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_18 ;
if ( ! V_2 -> V_83 &&
! F_66 ( V_2 ) ) {
if ( ! F_43 ( V_2 , 0 , V_107 ) )
return - V_68 ;
}
if ( ! F_14 ( V_2 , V_23 ) ) {
F_24 ( & V_4 -> V_32 -> V_40 , L_4 ) ;
return - V_80 ;
}
if ( F_66 ( V_2 ) )
return 0 ;
F_19 ( V_2 ) ;
V_18 = F_1 ( V_2 ) ;
if ( V_18 )
goto V_103;
V_2 -> V_83 -> V_53 -> V_19 = F_42 ( V_23 ) ;
V_18 = F_20 ( V_2 -> V_83 , V_107 ) ;
if ( V_18 )
goto V_104;
return 0 ;
V_104:
F_8 ( V_2 ) ;
V_103:
F_29 ( V_2 ) ;
return V_18 ;
}
void F_73 ( struct V_36 * V_32 ,
struct V_29 * V_30 , int V_38 )
{
struct V_1 * V_2 = V_30 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_30 == V_2 -> V_83 ) {
if ( V_38 ) {
F_24 ( & V_4 -> V_32 -> V_40 ,
L_5 ,
V_4 -> V_41 , V_2 -> type , V_38 ) ;
}
F_8 ( V_2 ) ;
F_29 ( V_2 ) ;
} else if ( V_38 || F_66 ( V_2 ) ) {
if ( F_14 ( V_2 , V_38 ) ) {
F_31 ( V_50 ,
& V_2 -> V_44 ) ;
}
}
}
static void F_74 ( struct V_3 * V_4 ,
const struct V_52 * V_53 ,
void * V_95 , T_3 V_58 )
{
struct V_1 * V_2 ;
T_1 V_26 ;
T_4 type ;
int V_18 ;
V_26 = F_75 ( V_53 -> V_26 ) ;
type = V_53 -> type ;
V_2 = F_56 ( V_4 , V_26 ,
type , V_95 , V_58 ) ;
if ( ! V_2 ) {
F_24 ( & V_4 -> V_32 -> V_40 ,
L_6 ,
V_4 -> V_41 ) ;
return;
}
V_18 = F_1 ( V_2 ) ;
if ( V_18 ) {
F_29 ( V_2 ) ;
return;
}
F_76 ( V_2 -> V_47 ) ;
if ( F_14 ( V_2 , - V_21 ) )
F_31 ( V_4 -> V_109 , & V_2 -> V_44 ) ;
}
static void F_77 ( struct V_3 * V_4 ,
const struct V_52 * V_53 ,
void * V_95 , T_3 V_58 )
{
struct V_1 * V_2 ;
struct V_29 * V_30 ;
T_3 V_57 ;
T_1 V_26 ;
int V_23 ;
V_26 = F_75 ( V_53 -> V_26 ) ;
if ( ! V_26 ) {
F_78 ( & V_4 -> V_32 -> V_40 ,
L_7 ,
V_4 -> V_41 ) ;
return;
}
V_2 = F_17 ( V_4 , V_26 ) ;
if ( ! V_2 ) {
F_78 ( & V_4 -> V_32 -> V_40 ,
L_8 ,
V_4 -> V_41 , V_26 ) ;
return;
}
V_23 = F_41 ( V_53 -> V_19 ) ;
V_30 = V_2 -> V_83 ;
V_57 = sizeof( * V_53 ) + V_30 -> V_51 ;
if ( ! V_23 && V_58 > V_57 ) {
F_78 ( & V_4 -> V_32 -> V_40 ,
L_9 ,
V_4 -> V_41 , V_53 -> type ,
V_58 , V_57 ) ;
V_23 = - V_71 ;
} else if ( ! V_23 && V_58 < V_57 ) {
if ( F_79 ( V_2 ) ) {
V_30 -> V_51 = V_58 - sizeof( * V_53 ) ;
} else {
F_78 ( & V_4 -> V_32 -> V_40 ,
L_10 ,
V_4 -> V_41 , V_53 -> type ,
V_58 , V_57 ) ;
V_23 = - V_71 ;
}
}
if ( V_23 )
V_58 = sizeof( * V_53 ) ;
if ( F_14 ( V_2 , V_23 ) ) {
memcpy ( V_30 -> V_54 , V_95 , V_58 ) ;
F_80 ( V_30 ) ;
F_31 ( V_50 , & V_2 -> V_44 ) ;
}
F_29 ( V_2 ) ;
}
void F_81 ( struct V_3 * V_4 ,
void * V_95 , T_3 V_58 )
{
struct V_52 V_53 ;
struct V_110 * V_40 = & V_4 -> V_32 -> V_40 ;
T_3 V_111 ;
if ( V_4 -> V_7 == V_112 ||
F_65 ( V_4 ) ) {
F_82 ( V_40 , L_11 ,
V_4 -> V_41 , V_58 ) ;
return;
}
if ( V_58 < sizeof( V_53 ) ) {
F_78 ( V_40 , L_12 ,
V_4 -> V_41 ) ;
return;
}
memcpy ( & V_53 , V_95 , sizeof( V_53 ) ) ;
V_111 = F_75 ( V_53 . V_58 ) ;
if ( V_58 < V_111 ) {
F_78 ( V_40 ,
L_13 ,
V_4 -> V_41 ,
F_75 ( V_53 . V_26 ) ,
V_53 . type , V_58 , V_111 ) ;
return;
}
if ( V_53 . type & V_84 ) {
F_77 ( V_4 , & V_53 , V_95 ,
V_111 ) ;
} else {
F_74 ( V_4 , & V_53 , V_95 ,
V_111 ) ;
}
}
void F_72 ( struct V_1 * V_2 , int V_23 )
{
if ( F_15 ( F_3 ( V_2 ) ) )
return;
if ( F_14 ( V_2 , V_23 ) ) {
F_22 ( V_2 -> V_47 ) ;
F_31 ( V_50 , & V_2 -> V_44 ) ;
}
F_83 ( V_2 -> V_47 ) ;
F_84 ( & V_2 -> V_16 ) ;
F_85 ( V_17 ,
! F_13 ( V_2 ) ) ;
F_86 ( & V_2 -> V_16 ) ;
}
void F_87 ( struct V_1 * V_2 , int V_23 )
{
if ( F_15 ( ! F_3 ( V_2 ) ) )
return;
if ( ! F_66 ( V_2 ) ) {
F_88 ( & V_2 -> V_44 ) ;
if ( ! F_14 ( V_2 , V_23 ) )
F_22 ( V_2 -> V_83 ) ;
}
F_89 ( V_2 -> V_83 ) ;
F_84 ( & V_2 -> V_16 ) ;
F_85 ( V_17 ,
! F_13 ( V_2 ) ) ;
F_86 ( & V_2 -> V_16 ) ;
}
int F_90 ( struct V_3 * V_4 , int type ,
void * V_47 , int V_85 ,
void * V_83 , int V_81 ,
unsigned int V_98 )
{
struct V_1 * V_2 ;
int V_18 ;
if ( ( V_81 && ! V_83 ) ||
( V_85 && ! V_47 ) )
return - V_73 ;
V_2 = F_91 ( V_4 , type ,
V_85 , V_81 ,
V_107 ) ;
if ( ! V_2 )
return - V_68 ;
if ( V_85 )
memcpy ( V_2 -> V_47 -> V_55 , V_47 , V_85 ) ;
V_18 = F_70 ( V_2 , V_98 ) ;
if ( V_18 ) {
F_24 ( & V_4 -> V_32 -> V_40 ,
L_14 ,
V_4 -> V_41 , V_2 -> V_28 , type , V_18 ) ;
} else {
if ( V_81 ) {
memcpy ( V_83 , V_2 -> V_83 -> V_55 ,
V_81 ) ;
}
}
F_29 ( V_2 ) ;
return V_18 ;
}
int F_92 ( struct V_3 * V_4 ,
int type , void * V_47 , int V_85 ,
unsigned int V_98 )
{
struct V_1 * V_2 ;
int V_18 ;
if ( V_85 && ! V_47 )
return - V_73 ;
V_2 = F_50 ( V_4 , type ,
V_85 , 0 ,
V_96 ,
V_107 ) ;
if ( ! V_2 )
return - V_68 ;
if ( V_85 )
memcpy ( V_2 -> V_47 -> V_55 , V_47 , V_85 ) ;
V_18 = F_70 ( V_2 , V_98 ) ;
if ( V_18 ) {
F_24 ( & V_4 -> V_32 -> V_40 ,
L_15 ,
V_4 -> V_41 , type , V_18 ) ;
}
F_29 ( V_2 ) ;
return V_18 ;
}
int T_6 F_93 ( void )
{
V_61 = F_94 ( L_16 ,
sizeof( struct V_29 ) , 0 , 0 , NULL ) ;
if ( ! V_61 )
return - V_68 ;
V_87 = F_94 ( L_17 ,
sizeof( struct V_1 ) , 0 , 0 , NULL ) ;
if ( ! V_87 )
goto V_113;
V_50 = F_95 ( L_18 ,
0 , 0 ) ;
if ( ! V_50 )
goto V_114;
return 0 ;
V_114:
F_96 ( V_87 ) ;
V_87 = NULL ;
V_113:
F_96 ( V_61 ) ;
V_61 = NULL ;
return - V_68 ;
}
void F_97 ( void )
{
F_98 ( V_50 ) ;
V_50 = NULL ;
F_96 ( V_87 ) ;
V_87 = NULL ;
F_96 ( V_61 ) ;
V_61 = NULL ;
}
