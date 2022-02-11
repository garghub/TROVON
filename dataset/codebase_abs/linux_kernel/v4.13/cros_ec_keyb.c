static bool F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
int V_4 , V_5 , V_6 , V_7 ;
struct V_8 * V_9 = V_2 -> V_9 ;
T_1 * V_10 = V_2 -> V_10 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_11 ; V_4 ++ ) {
V_6 = V_3 [ V_4 ] & V_10 [ V_4 ] ;
for ( V_5 = V_4 + 1 ; V_5 < V_2 -> V_11 ; V_5 ++ ) {
V_7 = V_3 [ V_5 ] & V_10 [ V_5 ] ;
if ( F_2 ( V_6 & V_7 ) > 1 ) {
F_3 ( V_9 , L_1 ,
V_4 , V_6 , V_5 , V_7 ) ;
return true ;
}
}
}
return false ;
}
static void F_4 ( struct V_1 * V_2 ,
T_1 * V_12 , int V_13 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
int V_16 , V_17 ;
int V_18 ;
int V_19 ;
int V_20 ;
V_20 = V_13 ;
if ( V_2 -> V_21 && F_1 ( V_2 , V_12 ) ) {
F_3 ( V_2 -> V_9 , L_2 ) ;
return;
}
for ( V_16 = 0 ; V_16 < V_2 -> V_11 ; V_16 ++ ) {
for ( V_17 = 0 ; V_17 < V_2 -> V_22 ; V_17 ++ ) {
int V_23 = F_5 ( V_17 , V_16 , V_2 -> V_24 ) ;
const unsigned short * V_25 = V_15 -> V_26 ;
V_18 = V_12 [ V_16 ] & ( 1 << V_17 ) ;
V_19 = V_2 -> V_27 [ V_16 ] & ( 1 << V_17 ) ;
if ( V_18 != V_19 ) {
F_3 ( V_2 -> V_9 ,
L_3 ,
V_17 , V_16 , V_18 ) ;
F_6 ( V_15 , V_25 [ V_23 ] ,
V_18 ) ;
}
}
V_2 -> V_27 [ V_16 ] = V_12 [ V_16 ] ;
}
F_7 ( V_2 -> V_15 ) ;
}
static void F_8 ( struct V_1 * V_2 ,
unsigned int V_28 , T_2 V_29 )
{
struct V_14 * V_15 = V_2 -> V_30 ;
int V_31 ;
for ( V_31 = 0 ; V_31 < F_9 ( V_32 ) ; V_31 ++ ) {
const struct V_33 * V_34 = & V_32 [ V_31 ] ;
if ( V_34 -> V_28 != V_28 )
continue;
F_10 ( V_15 , V_28 , V_34 -> V_35 ,
! ! ( V_29 & F_11 ( V_34 -> V_36 ) ) ^ V_34 -> V_37 ) ;
}
F_7 ( V_15 ) ;
}
static int F_12 ( struct V_38 * V_39 ,
unsigned long V_40 , void * V_41 )
{
struct V_1 * V_2 = F_13 ( V_39 , struct V_1 ,
V_42 ) ;
T_2 V_43 ;
unsigned int V_28 ;
switch ( V_2 -> V_44 -> V_45 . V_46 ) {
case V_47 :
if ( V_40 )
return V_48 ;
if ( V_2 -> V_44 -> V_49 != V_2 -> V_11 ) {
F_14 ( V_2 -> V_9 ,
L_4 ) ;
return V_48 ;
}
F_4 ( V_2 ,
V_2 -> V_44 -> V_45 . V_50 . V_51 ,
V_2 -> V_44 -> V_49 ) ;
break;
case V_52 :
V_43 = F_15 ( & V_2 -> V_44 -> V_45 . V_50 . V_53 ) ;
F_3 ( V_2 -> V_9 , L_5 , V_43 ) ;
F_16 ( V_43 ) ;
break;
case V_54 :
case V_55 :
if ( V_40 )
return V_48 ;
if ( V_2 -> V_44 -> V_45 . V_46 == V_54 ) {
V_43 = F_15 (
& V_2 -> V_44 -> V_45 . V_50 . V_56 ) ;
V_28 = V_57 ;
} else {
V_43 = F_15 (
& V_2 -> V_44 -> V_45 . V_50 . V_58 ) ;
V_28 = V_59 ;
}
F_8 ( V_2 , V_28 , V_43 ) ;
break;
default:
return V_60 ;
}
return V_48 ;
}
static void F_17 ( struct V_1 * V_2 )
{
int V_17 , V_16 ;
int V_24 = V_2 -> V_24 ;
unsigned short * V_61 = V_2 -> V_15 -> V_26 ;
unsigned short V_35 ;
F_18 ( V_2 -> V_15 -> V_62 != sizeof( * V_61 ) ) ;
for ( V_16 = 0 ; V_16 < V_2 -> V_11 ; V_16 ++ ) {
for ( V_17 = 0 ; V_17 < V_2 -> V_22 ; V_17 ++ ) {
V_35 = V_61 [ F_5 ( V_17 , V_16 , V_24 ) ] ;
if ( V_35 && ( V_35 != V_63 ) )
V_2 -> V_10 [ V_16 ] |= 1 << V_17 ;
}
F_3 ( V_2 -> V_9 , L_6 ,
V_16 , V_2 -> V_10 [ V_16 ] ) ;
}
}
static int F_19 ( struct V_64 * V_65 ,
enum V_66 V_67 ,
enum V_68 V_46 ,
union V_69 * V_70 ,
T_3 V_71 )
{
struct V_72 * V_73 ;
struct V_74 * V_75 ;
int V_76 ;
V_75 = F_20 ( sizeof( * V_75 ) + F_21 ( T_3 , V_71 ,
sizeof( * V_73 ) ) , V_77 ) ;
if ( ! V_75 )
return - V_78 ;
V_75 -> V_79 = V_80 ;
V_75 -> V_81 = 1 ;
V_75 -> V_82 = sizeof( * V_73 ) ;
V_75 -> V_83 = V_71 ;
V_73 = (struct V_72 * ) V_75 -> V_50 ;
V_73 -> V_67 = V_67 ;
V_73 -> V_46 = V_46 ;
V_76 = F_22 ( V_65 , V_75 ) ;
if ( V_76 < 0 ) {
F_23 ( V_65 -> V_9 , L_7 ,
( int ) V_67 , ( int ) V_46 , V_76 ) ;
} else if ( V_75 -> V_70 == V_84 ) {
memset ( V_70 , 0 , V_71 ) ;
V_76 = 0 ;
} else if ( V_75 -> V_70 != V_85 ) {
F_23 ( V_65 -> V_9 , L_8 ,
( int ) V_67 , ( int ) V_46 , V_75 -> V_70 ) ;
V_76 = - V_86 ;
} else if ( V_76 != V_71 ) {
F_23 ( V_65 -> V_9 , L_9 ,
( int ) V_67 , ( int ) V_46 ,
V_76 , V_71 ) ;
V_76 = - V_86 ;
} else {
memcpy ( V_70 , V_75 -> V_50 , V_71 ) ;
V_76 = 0 ;
}
F_24 ( V_75 ) ;
return V_76 ;
}
static int F_25 ( struct V_1 * V_2 )
{
struct V_64 * V_65 = V_2 -> V_44 ;
union V_69 V_45 = {} ;
int V_76 ;
V_76 = F_19 ( V_65 , V_87 ,
V_55 , & V_45 ,
sizeof( V_45 . V_58 ) ) ;
if ( V_76 )
return V_76 ;
F_8 ( V_2 , V_59 ,
F_15 ( & V_45 . V_58 ) ) ;
return 0 ;
}
static T_4 int F_26 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_27 ( V_9 ) ;
if ( V_2 -> V_30 )
return F_25 ( V_2 ) ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 )
{
struct V_64 * V_65 = V_2 -> V_44 ;
struct V_8 * V_9 = V_2 -> V_9 ;
struct V_14 * V_15 ;
union V_69 V_45 = {} ;
const char * V_88 ;
T_2 V_56 ;
T_2 V_58 ;
int V_76 ;
int V_31 ;
V_76 = F_19 ( V_65 , V_89 ,
V_54 , & V_45 ,
sizeof( V_45 . V_56 ) ) ;
if ( V_76 )
return V_76 ;
V_56 = F_15 ( & V_45 . V_56 ) ;
V_76 = F_19 ( V_65 , V_89 ,
V_55 , & V_45 ,
sizeof( V_45 . V_58 ) ) ;
if ( V_76 )
return V_76 ;
V_58 = F_15 ( & V_45 . V_58 ) ;
if ( ! V_56 && ! V_58 )
return 0 ;
V_88 = F_29 ( V_9 , V_77 , L_10 , V_65 -> V_90 ) ;
if ( ! V_88 )
return - V_78 ;
V_15 = F_30 ( V_9 ) ;
if ( ! V_15 )
return - V_78 ;
V_15 -> V_91 = L_11 ;
V_15 -> V_88 = V_88 ;
F_31 ( V_92 , V_15 -> V_93 ) ;
V_15 -> V_94 . V_95 = V_96 ;
V_15 -> V_94 . V_81 = 1 ;
V_15 -> V_94 . V_97 = 0 ;
V_15 -> V_9 . V_98 = V_9 ;
F_32 ( V_15 , V_2 ) ;
V_2 -> V_30 = V_15 ;
for ( V_31 = 0 ; V_31 < F_9 ( V_32 ) ; V_31 ++ ) {
const struct V_33 * V_34 = & V_32 [ V_31 ] ;
if ( V_56 & F_11 ( V_34 -> V_36 ) )
F_33 ( V_15 , V_34 -> V_28 , V_34 -> V_35 ) ;
}
V_76 = F_25 ( V_2 ) ;
if ( V_76 ) {
F_14 ( V_9 , L_12 ) ;
return V_76 ;
}
V_76 = F_34 ( V_2 -> V_30 ) ;
if ( V_76 ) {
F_14 ( V_9 , L_13 ) ;
return V_76 ;
}
return 0 ;
}
static int F_35 ( struct V_1 * V_2 )
{
struct V_64 * V_65 = V_2 -> V_44 ;
struct V_8 * V_9 = V_2 -> V_9 ;
struct V_14 * V_15 ;
const char * V_88 ;
int V_99 ;
V_99 = F_36 ( V_9 , & V_2 -> V_22 , & V_2 -> V_11 ) ;
if ( V_99 )
return V_99 ;
V_2 -> V_10 = F_37 ( V_9 , V_2 -> V_11 , V_77 ) ;
if ( ! V_2 -> V_10 )
return - V_78 ;
V_2 -> V_27 = F_37 ( V_9 , V_2 -> V_11 , V_77 ) ;
if ( ! V_2 -> V_27 )
return - V_78 ;
V_88 = F_29 ( V_9 , V_77 , L_14 , V_65 -> V_90 ) ;
if ( ! V_88 )
return - V_78 ;
V_15 = F_30 ( V_9 ) ;
if ( ! V_15 )
return - V_78 ;
V_15 -> V_91 = V_100 ;
V_15 -> V_88 = V_88 ;
F_31 ( V_92 , V_15 -> V_93 ) ;
V_15 -> V_94 . V_95 = V_96 ;
V_15 -> V_94 . V_81 = 1 ;
V_15 -> V_94 . V_97 = 0 ;
V_15 -> V_9 . V_98 = V_9 ;
V_2 -> V_21 = F_38 ( V_9 -> V_101 ,
L_15 ) ;
V_99 = F_39 ( NULL , NULL , V_2 -> V_22 , V_2 -> V_11 ,
NULL , V_15 ) ;
if ( V_99 ) {
F_14 ( V_9 , L_16 ) ;
return V_99 ;
}
V_2 -> V_24 = F_40 ( V_2 -> V_11 ) ;
F_33 ( V_15 , V_102 , V_103 ) ;
F_32 ( V_15 , V_2 ) ;
V_2 -> V_15 = V_15 ;
F_17 ( V_2 ) ;
V_99 = F_34 ( V_2 -> V_15 ) ;
if ( V_99 ) {
F_14 ( V_9 , L_13 ) ;
return V_99 ;
}
return 0 ;
}
static int F_41 ( struct V_104 * V_105 )
{
struct V_64 * V_44 = F_27 ( V_105 -> V_9 . V_98 ) ;
struct V_8 * V_9 = & V_105 -> V_9 ;
struct V_1 * V_2 ;
int V_99 ;
if ( ! V_9 -> V_101 )
return - V_106 ;
V_2 = F_37 ( V_9 , sizeof( * V_2 ) , V_77 ) ;
if ( ! V_2 )
return - V_78 ;
V_2 -> V_44 = V_44 ;
V_2 -> V_9 = V_9 ;
F_42 ( V_9 , V_2 ) ;
V_99 = F_35 ( V_2 ) ;
if ( V_99 ) {
F_14 ( V_9 , L_17 , V_99 ) ;
return V_99 ;
}
V_99 = F_28 ( V_2 ) ;
if ( V_99 ) {
F_14 ( V_9 , L_18 , V_99 ) ;
return V_99 ;
}
V_2 -> V_42 . V_107 = F_12 ;
V_99 = F_43 ( & V_2 -> V_44 -> V_108 ,
& V_2 -> V_42 ) ;
if ( V_99 ) {
F_14 ( V_9 , L_19 , V_99 ) ;
return V_99 ;
}
return 0 ;
}
static int F_44 ( struct V_104 * V_105 )
{
struct V_1 * V_2 = F_27 ( & V_105 -> V_9 ) ;
F_45 ( & V_2 -> V_44 -> V_108 ,
& V_2 -> V_42 ) ;
return 0 ;
}
