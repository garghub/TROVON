static T_1 F_1 ( void * V_1 )
{
int V_2 ;
T_1 * V_3 , V_4 = 0 ;
V_3 = V_1 ;
for ( V_2 = 0 ; V_2 < 7 ; V_2 ++ )
V_4 ^= V_3 [ V_2 ] ;
return V_4 ;
}
static void F_2 ( struct V_5 * V_6 )
{
enum V_7 V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = V_6 -> V_10 ;
T_2 V_11 , V_12 ;
V_11 = F_3 ( V_8 ) ;
V_12 = F_4 ( V_10 , V_11 ) ;
V_12 = F_5 ( V_12 , V_13 ) ;
V_12 |= F_6 ( V_6 -> V_12 , V_13 ) ;
F_7 ( V_10 , V_11 , V_12 ) ;
}
static T_2 F_8 ( struct V_5 * V_6 )
{
T_2 V_11 , V_3 ;
V_11 = F_9 ( V_6 -> V_8 ) ;
V_3 = F_4 ( V_6 -> V_10 , V_11 ) ;
return F_10 ( V_3 , V_14 ) ;
}
static int F_11 ( struct V_5 * V_6 )
{
struct V_9 * V_10 = V_6 -> V_10 ;
struct V_15 * V_16 = V_10 -> V_16 ;
T_2 V_12 ;
switch ( V_6 -> V_8 ) {
case V_17 :
V_6 -> V_18 = F_8 ( V_6 ) ;
V_12 = V_6 -> V_12 ;
if ( V_6 -> V_18 == F_12 ( V_6 , V_12 + 1 ) ) {
F_13 ( & V_16 -> V_19 , L_1 ,
V_6 -> V_8 ) ;
return - V_20 ;
}
break;
default:
F_13 ( & V_16 -> V_19 , L_2 ) ;
break;
}
return 0 ;
}
static T_1 F_14 ( enum V_7 type )
{
T_1 V_21 = 0 ;
switch ( type ) {
case V_17 :
V_21 = F_15 ( V_22 +
V_23 ,
V_24 ) ;
break;
default:
break;
}
return V_21 ;
}
static void F_16 ( T_3 * V_25 , T_4 V_26 )
{
T_1 V_27 ;
T_3 V_28 ;
V_28 = F_17 ( F_18 ( V_26 ) , V_29 ) |
F_17 ( V_30 , V_31 ) |
F_17 ( V_32 , V_33 ) ;
V_27 = F_1 ( & V_28 ) ;
V_28 |= F_17 ( V_27 , V_34 ) ;
* V_25 = F_19 ( V_28 ) ;
}
static void F_20 ( struct V_5 * V_6 ,
enum V_35 V_36 ,
void * V_37 , T_4 V_38 )
{
struct V_39 * V_40 = V_6 -> V_41 ;
struct V_42 * V_43 ;
struct V_9 * V_10 = V_6 -> V_10 ;
struct V_15 * V_16 = V_10 -> V_16 ;
V_43 = & V_6 -> V_43 [ V_6 -> V_12 ] ;
switch ( V_6 -> V_8 ) {
case V_17 :
V_40 -> V_44 = F_21 ( V_45 , V_46 ) |
F_21 ( V_47 , V_48 ) |
F_21 ( V_49 , V_50 ) ;
break;
default:
F_13 ( & V_16 -> V_19 , L_3 ) ;
return;
}
V_40 -> V_44 |= F_21 ( V_36 , V_51 ) |
F_21 ( F_22 ( V_38 ) , V_52 ) ;
V_40 -> V_44 |= F_21 ( F_1 ( & V_40 -> V_44 ) ,
V_34 ) ;
V_40 -> V_44 = F_19 ( V_40 -> V_44 ) ;
memcpy ( V_43 -> V_53 , V_37 , V_38 ) ;
}
static void F_23 ( struct V_5 * V_6 ,
enum V_35 V_36 ,
void * V_37 , T_4 V_38 )
{
struct V_39 * V_41 = V_6 -> V_41 ;
T_4 V_26 = F_14 ( V_6 -> V_8 ) ;
F_16 ( & V_41 -> V_28 , V_26 ) ;
F_20 ( V_6 , V_36 , V_37 , V_38 ) ;
}
static inline void F_24 ( struct V_5 * V_6 )
{
V_6 -> V_12 = F_12 ( V_6 , V_6 -> V_12 + 1 ) ;
}
static void F_25 ( struct V_5 * V_6 )
{
enum V_7 V_8 ;
struct V_54 * V_55 ;
struct V_9 * V_10 = V_6 -> V_10 ;
struct V_15 * V_16 = V_10 -> V_16 ;
T_3 V_56 ;
T_2 V_57 ;
V_55 = V_6 -> V_55 ;
V_56 = F_26 ( V_55 -> V_58 ) ;
V_57 = F_27 ( V_55 -> V_57 ) ;
if ( F_10 ( V_57 , V_59 ) ) {
F_13 ( & V_16 -> V_19 , L_4 ) ;
return;
}
V_8 = F_28 ( V_56 , V_60 ) ;
if ( V_8 >= V_61 ) {
F_13 ( & V_16 -> V_19 , L_5 , V_8 ) ;
return;
}
V_6 -> V_18 = F_10 ( V_57 , V_14 ) ;
}
static int F_29 ( struct V_5 * V_6 )
{
int V_62 = - V_63 ;
unsigned long V_64 ;
V_64 = V_65 + F_30 ( V_66 ) ;
do {
F_25 ( V_6 ) ;
if ( V_6 -> V_18 == V_6 -> V_12 ) {
V_62 = 0 ;
break;
}
F_31 ( 20 ) ;
} while ( F_32 ( V_65 , V_64 ) );
return V_62 ;
}
static int F_33 ( struct V_5 * V_6 )
{
struct V_9 * V_10 = V_6 -> V_10 ;
struct V_15 * V_16 = V_10 -> V_16 ;
int V_62 ;
switch ( V_6 -> V_8 ) {
case V_17 :
V_62 = F_29 ( V_6 ) ;
if ( V_62 ) {
F_13 ( & V_16 -> V_19 , L_6 ) ;
break;
}
break;
default:
F_13 ( & V_16 -> V_19 , L_7 ) ;
V_62 = - V_67 ;
break;
}
return V_62 ;
}
static int F_34 ( struct V_5 * V_6 ,
enum V_35 V_36 , T_1 * V_37 , T_4 V_38 )
{
struct V_42 * V_68 ;
int V_62 ;
F_35 ( & V_6 -> V_69 ) ;
if ( F_11 ( V_6 ) ) {
F_36 ( & V_6 -> V_69 ) ;
return - V_20 ;
}
F_23 ( V_6 , V_36 , V_37 , V_38 ) ;
F_24 ( V_6 ) ;
F_37 () ;
F_2 ( V_6 ) ;
V_68 = & V_6 -> V_43 [ V_6 -> V_12 ] ;
V_6 -> V_41 = V_68 -> V_70 ;
V_62 = F_33 ( V_6 ) ;
F_36 ( & V_6 -> V_69 ) ;
return V_62 ;
}
int F_38 ( struct V_5 * V_6 ,
enum V_35 V_36 , T_1 * V_37 , T_4 V_71 )
{
if ( V_6 -> V_8 == V_17 )
return F_34 ( V_6 , V_36 , V_37 , V_71 ) ;
return - V_67 ;
}
static int F_39 ( struct V_5 * V_6 )
{
struct V_9 * V_10 = V_6 -> V_10 ;
int V_62 = - V_63 ;
unsigned long V_64 ;
T_2 V_72 , V_3 ;
V_72 = F_40 ( V_6 -> V_8 ) ;
V_3 = F_4 ( V_10 , V_72 ) ;
V_3 = F_41 ( V_3 , V_73 ) ;
V_3 |= F_42 ( 1 , V_73 ) ;
F_7 ( V_10 , V_72 , V_3 ) ;
V_64 = V_65 + F_30 ( V_66 ) ;
do {
V_3 = F_4 ( V_10 , V_72 ) ;
if ( ! F_43 ( V_3 , V_73 ) ) {
V_62 = 0 ;
break;
}
F_31 ( 20 ) ;
} while ( F_32 ( V_65 , V_64 ) );
return V_62 ;
}
static void F_44 ( struct V_5 * V_6 )
{
struct V_9 * V_10 = V_6 -> V_10 ;
T_2 V_11 , V_28 ;
T_4 V_74 ;
V_11 = F_45 ( V_6 -> V_8 ) ;
V_74 = F_46 ( V_6 -> V_74 ) ;
V_28 = F_4 ( V_10 , V_11 ) ;
V_28 = F_47 ( V_28 , V_75 ) &
F_47 ( V_28 , V_76 ) &
F_47 ( V_28 , V_77 ) &
F_47 ( V_28 , V_78 ) &
F_47 ( V_28 , V_79 ) ;
V_28 |= F_48 ( 1 , V_76 ) |
F_48 ( V_80 , V_78 ) |
F_48 ( V_74 , V_79 ) ;
F_7 ( V_10 , V_11 , V_28 ) ;
}
static void F_49 ( struct V_5 * V_6 )
{
struct V_9 * V_10 = V_6 -> V_10 ;
T_2 V_11 , V_3 ;
V_11 = F_50 ( V_6 -> V_8 ) ;
V_3 = F_51 ( V_6 -> V_81 ) ;
F_7 ( V_10 , V_11 , V_3 ) ;
V_11 = F_52 ( V_6 -> V_8 ) ;
V_3 = F_53 ( V_6 -> V_81 ) ;
F_7 ( V_10 , V_11 , V_3 ) ;
}
static void F_54 ( struct V_5 * V_6 )
{
struct V_9 * V_10 = V_6 -> V_10 ;
T_2 V_11 , V_3 ;
V_11 = F_55 ( V_6 -> V_8 ) ;
V_3 = V_6 -> V_82 ;
F_7 ( V_10 , V_11 , V_3 ) ;
}
static void F_56 ( struct V_5 * V_6 )
{
struct V_9 * V_10 = V_6 -> V_10 ;
T_2 V_11 , V_3 ;
V_11 = F_57 ( V_6 -> V_8 ) ;
V_3 = F_51 ( V_6 -> V_83 ) ;
F_7 ( V_10 , V_11 , V_3 ) ;
V_11 = F_58 ( V_6 -> V_8 ) ;
V_3 = F_53 ( V_6 -> V_83 ) ;
F_7 ( V_10 , V_11 , V_3 ) ;
}
static void F_59 ( struct V_5 * V_6 )
{
struct V_9 * V_10 = V_6 -> V_10 ;
T_2 V_11 , V_28 ;
V_11 = F_45 ( V_6 -> V_8 ) ;
V_28 = F_4 ( V_10 , V_11 ) ;
V_28 = F_47 ( V_28 , V_75 ) &
F_47 ( V_28 , V_76 ) &
F_47 ( V_28 , V_77 ) &
F_47 ( V_28 , V_78 ) &
F_47 ( V_28 , V_79 ) ;
F_7 ( V_10 , V_11 , V_28 ) ;
}
static int F_60 ( struct V_5 * V_6 )
{
struct V_9 * V_10 = V_6 -> V_10 ;
struct V_15 * V_16 = V_10 -> V_16 ;
int V_62 ;
F_59 ( V_6 ) ;
F_49 ( V_6 ) ;
V_62 = F_39 ( V_6 ) ;
if ( V_62 ) {
F_13 ( & V_16 -> V_19 , L_8 ) ;
return V_62 ;
}
F_44 ( V_6 ) ;
F_54 ( V_6 ) ;
F_56 ( V_6 ) ;
return 0 ;
}
static void F_61 ( struct V_5 * V_6 , int V_84 )
{
struct V_42 * V_43 ;
struct V_9 * V_10 = V_6 -> V_10 ;
struct V_15 * V_16 = V_10 -> V_16 ;
V_43 = & V_6 -> V_43 [ V_84 ] ;
F_62 ( & V_16 -> V_19 , V_85 ,
V_43 -> V_53 ,
V_43 -> V_86 ) ;
}
static int F_63 ( struct V_5 * V_6 ,
struct V_39 * V_40 , int V_84 )
{
struct V_42 * V_43 ;
struct V_9 * V_10 = V_6 -> V_10 ;
struct V_15 * V_16 = V_10 -> V_16 ;
T_5 V_87 ;
T_1 * V_88 ;
int V_62 = 0 ;
V_88 = F_64 ( & V_16 -> V_19 , V_85 ,
& V_87 , V_89 ) ;
if ( ! V_88 ) {
F_13 ( & V_16 -> V_19 , L_9 ) ;
return - V_90 ;
}
V_43 = & V_6 -> V_43 [ V_84 ] ;
V_43 -> V_53 = V_88 ;
V_43 -> V_86 = V_87 ;
switch ( V_6 -> V_8 ) {
case V_17 :
V_40 -> V_91 . V_92 = F_19 ( V_87 ) ;
break;
default:
F_13 ( & V_16 -> V_19 , L_10 ) ;
F_61 ( V_6 , V_84 ) ;
V_62 = - V_67 ;
break;
}
return V_62 ;
}
static int F_65 ( struct V_5 * V_6 ,
int V_84 ,
struct V_39 * V_93 ,
struct V_39 * * V_94 )
{
struct V_42 * V_43 ;
struct V_9 * V_10 = V_6 -> V_10 ;
struct V_15 * V_16 = V_10 -> V_16 ;
struct V_39 * V_95 ;
T_5 V_96 ;
int V_62 ;
V_95 = F_64 ( & V_16 -> V_19 , V_6 -> V_74 ,
& V_96 , V_89 ) ;
if ( ! V_95 ) {
F_13 ( & V_16 -> V_19 , L_11 ) ;
return - V_90 ;
}
V_95 -> V_97 . V_98 = 0 ;
V_43 = & V_6 -> V_43 [ V_84 ] ;
V_43 -> V_70 = V_95 ;
V_43 -> V_99 = V_96 ;
if ( ! V_93 ) {
V_6 -> V_83 = V_96 ;
V_6 -> V_100 = V_95 ;
} else {
V_93 -> V_101 = F_19 ( V_96 ) ;
}
switch ( V_6 -> V_8 ) {
case V_17 :
V_62 = F_63 ( V_6 , V_95 , V_84 ) ;
if ( V_62 ) {
F_13 ( & V_16 -> V_19 , L_12 ) ;
goto V_102;
}
break;
default:
F_13 ( & V_16 -> V_19 , L_10 ) ;
V_62 = - V_67 ;
goto V_102;
}
* V_94 = V_95 ;
return 0 ;
V_102:
F_62 ( & V_16 -> V_19 , V_6 -> V_74 , V_95 , V_96 ) ;
return V_62 ;
}
static void F_66 ( struct V_5 * V_6 ,
int V_84 )
{
struct V_42 * V_43 ;
struct V_9 * V_10 = V_6 -> V_10 ;
struct V_15 * V_16 = V_10 -> V_16 ;
struct V_39 * V_95 ;
T_5 V_96 ;
T_6 V_103 ;
V_43 = & V_6 -> V_43 [ V_84 ] ;
V_95 = V_43 -> V_70 ;
V_96 = V_43 -> V_99 ;
V_103 = V_6 -> V_74 ;
if ( V_43 -> V_53 ) {
switch ( V_6 -> V_8 ) {
case V_17 :
F_61 ( V_6 , V_84 ) ;
break;
default:
F_13 ( & V_16 -> V_19 , L_10 ) ;
break;
}
F_62 ( & V_16 -> V_19 , V_103 , V_95 ,
V_96 ) ;
}
}
static void F_67 ( struct V_5 * V_6 ,
int V_82 )
{
int V_84 ;
for ( V_84 = 0 ; V_84 < V_82 ; V_84 ++ )
F_66 ( V_6 , V_84 ) ;
}
static int F_68 ( struct V_5 * V_6 )
{
struct V_39 * V_95 = NULL , * V_93 = NULL ;
struct V_9 * V_10 = V_6 -> V_10 ;
struct V_15 * V_16 = V_10 -> V_16 ;
int V_62 , V_84 ;
for ( V_84 = 0 ; V_84 < V_6 -> V_82 ; V_84 ++ ) {
V_62 = F_65 ( V_6 , V_84 , V_93 , & V_95 ) ;
if ( V_62 ) {
F_13 ( & V_16 -> V_19 , L_13 ) ;
goto V_104;
}
V_93 = V_95 ;
}
V_95 -> V_101 = F_19 ( V_6 -> V_83 ) ;
V_6 -> V_41 = V_6 -> V_100 ;
return 0 ;
V_104:
F_67 ( V_6 , V_84 ) ;
return V_62 ;
}
static int F_69 ( struct V_5 * V_6 ,
struct V_105 * V_106 )
{
struct V_9 * V_10 = V_106 -> V_10 ;
struct V_15 * V_16 = V_10 -> V_16 ;
T_6 V_107 ;
V_6 -> V_10 = V_10 ;
V_6 -> V_8 = V_106 -> V_8 ;
V_6 -> V_82 = V_106 -> V_82 ;
V_6 -> V_74 = V_106 -> V_74 ;
V_6 -> V_12 = 0 ;
V_6 -> V_18 = 0 ;
F_70 ( & V_6 -> V_69 , 1 ) ;
V_107 = V_6 -> V_82 * sizeof( * V_6 -> V_43 ) ;
V_6 -> V_43 = F_71 ( & V_16 -> V_19 , V_107 , V_89 ) ;
if ( ! V_6 -> V_43 )
return - V_90 ;
V_6 -> V_55 = F_64 ( & V_16 -> V_19 ,
sizeof( * V_6 -> V_55 ) ,
& V_6 -> V_81 ,
V_89 ) ;
if ( ! V_6 -> V_55 ) {
F_13 ( & V_16 -> V_19 , L_14 ) ;
return - V_90 ;
}
return 0 ;
}
static void F_72 ( struct V_5 * V_6 )
{
struct V_9 * V_10 = V_6 -> V_10 ;
struct V_15 * V_16 = V_10 -> V_16 ;
F_62 ( & V_16 -> V_19 , sizeof( * V_6 -> V_55 ) ,
V_6 -> V_55 , V_6 -> V_81 ) ;
}
static struct V_5 *
F_73 ( struct V_105 * V_106 )
{
struct V_9 * V_10 = V_106 -> V_10 ;
struct V_15 * V_16 = V_10 -> V_16 ;
struct V_5 * V_6 ;
int V_62 ;
if ( V_106 -> V_82 & ( V_106 -> V_82 - 1 ) ) {
F_13 ( & V_16 -> V_19 , L_15 ) ;
return F_74 ( - V_67 ) ;
}
V_6 = F_71 ( & V_16 -> V_19 , sizeof( * V_6 ) , V_89 ) ;
if ( ! V_6 )
return F_74 ( - V_90 ) ;
V_62 = F_69 ( V_6 , V_106 ) ;
if ( V_62 ) {
F_13 ( & V_16 -> V_19 , L_16 ) ;
return F_74 ( V_62 ) ;
}
V_62 = F_68 ( V_6 ) ;
if ( V_62 ) {
F_13 ( & V_16 -> V_19 , L_17 ) ;
goto V_108;
}
V_62 = F_60 ( V_6 ) ;
if ( V_62 ) {
F_13 ( & V_16 -> V_19 , L_18 ) ;
goto V_109;
}
return V_6 ;
V_109:
F_67 ( V_6 , V_6 -> V_82 ) ;
V_108:
F_72 ( V_6 ) ;
return F_74 ( V_62 ) ;
}
static void F_75 ( struct V_5 * V_6 )
{
F_59 ( V_6 ) ;
F_67 ( V_6 , V_6 -> V_82 ) ;
F_72 ( V_6 ) ;
}
int F_76 ( struct V_5 * * V_6 ,
struct V_9 * V_10 )
{
enum V_7 type , V_8 ;
struct V_105 V_106 ;
struct V_15 * V_16 = V_10 -> V_16 ;
T_6 V_110 ;
int V_62 ;
V_110 = sizeof( struct V_39 ) ;
V_106 . V_10 = V_10 ;
V_106 . V_82 = V_111 ;
V_106 . V_74 = F_77 ( V_110 ) ;
V_8 = V_17 ;
for ( ; V_8 < V_61 ; V_8 ++ ) {
V_106 . V_8 = V_8 ;
if ( V_8 != V_17 )
continue;
V_6 [ V_8 ] = F_73 ( & V_106 ) ;
if ( F_78 ( V_6 [ V_8 ] ) ) {
F_13 ( & V_16 -> V_19 , L_19 ,
V_8 ) ;
V_62 = F_79 ( V_6 [ V_8 ] ) ;
goto V_112;
}
}
return 0 ;
V_112:
type = V_17 ;
for ( ; type < V_8 ; type ++ ) {
if ( type != V_17 )
continue;
F_75 ( V_6 [ type ] ) ;
}
return V_62 ;
}
void F_80 ( struct V_5 * * V_6 )
{
enum V_7 V_8 ;
V_8 = V_17 ;
for ( ; V_8 < V_61 ; V_8 ++ ) {
if ( V_8 != V_17 )
continue;
F_75 ( V_6 [ V_8 ] ) ;
}
}
