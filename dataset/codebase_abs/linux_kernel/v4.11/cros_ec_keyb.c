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
case V_53 :
if ( V_40 )
return V_48 ;
if ( V_2 -> V_44 -> V_45 . V_46 == V_52 ) {
V_43 = F_15 (
& V_2 -> V_44 -> V_45 . V_50 . V_54 ) ;
V_28 = V_55 ;
} else {
V_43 = F_15 (
& V_2 -> V_44 -> V_45 . V_50 . V_56 ) ;
V_28 = V_57 ;
}
F_8 ( V_2 , V_28 , V_43 ) ;
break;
default:
return V_58 ;
}
return V_48 ;
}
static void F_16 ( struct V_1 * V_2 )
{
int V_17 , V_16 ;
int V_24 = V_2 -> V_24 ;
unsigned short * V_59 = V_2 -> V_15 -> V_26 ;
unsigned short V_35 ;
F_17 ( V_2 -> V_15 -> V_60 != sizeof( * V_59 ) ) ;
for ( V_16 = 0 ; V_16 < V_2 -> V_11 ; V_16 ++ ) {
for ( V_17 = 0 ; V_17 < V_2 -> V_22 ; V_17 ++ ) {
V_35 = V_59 [ F_5 ( V_17 , V_16 , V_24 ) ] ;
if ( V_35 && ( V_35 != V_61 ) )
V_2 -> V_10 [ V_16 ] |= 1 << V_17 ;
}
F_3 ( V_2 -> V_9 , L_5 ,
V_16 , V_2 -> V_10 [ V_16 ] ) ;
}
}
static int F_18 ( struct V_62 * V_63 ,
enum V_64 V_65 ,
enum V_66 V_46 ,
union V_67 * V_68 ,
T_3 V_69 )
{
struct V_70 * V_71 ;
struct V_72 * V_73 ;
int V_74 ;
V_73 = F_19 ( sizeof( * V_73 ) + F_20 ( T_3 , V_69 ,
sizeof( * V_71 ) ) , V_75 ) ;
if ( ! V_73 )
return - V_76 ;
V_73 -> V_77 = V_78 ;
V_73 -> V_79 = 1 ;
V_73 -> V_80 = sizeof( * V_71 ) ;
V_73 -> V_81 = V_69 ;
V_71 = (struct V_70 * ) V_73 -> V_50 ;
V_71 -> V_65 = V_65 ;
V_71 -> V_46 = V_46 ;
V_74 = F_21 ( V_63 , V_73 ) ;
if ( V_74 < 0 ) {
F_22 ( V_63 -> V_9 , L_6 ,
( int ) V_65 , ( int ) V_46 , V_74 ) ;
} else if ( V_73 -> V_68 == V_82 ) {
memset ( V_68 , 0 , V_69 ) ;
V_74 = 0 ;
} else if ( V_73 -> V_68 != V_83 ) {
F_22 ( V_63 -> V_9 , L_7 ,
( int ) V_65 , ( int ) V_46 , V_73 -> V_68 ) ;
V_74 = - V_84 ;
} else if ( V_74 != V_69 ) {
F_22 ( V_63 -> V_9 , L_8 ,
( int ) V_65 , ( int ) V_46 ,
V_74 , V_69 ) ;
V_74 = - V_84 ;
} else {
memcpy ( V_68 , V_73 -> V_50 , V_69 ) ;
V_74 = 0 ;
}
F_23 ( V_73 ) ;
return V_74 ;
}
static int F_24 ( struct V_1 * V_2 )
{
struct V_62 * V_63 = V_2 -> V_44 ;
union V_67 V_45 = {} ;
int V_74 ;
V_74 = F_18 ( V_63 , V_85 ,
V_53 , & V_45 ,
sizeof( V_45 . V_56 ) ) ;
if ( V_74 )
return V_74 ;
F_8 ( V_2 , V_57 ,
F_15 ( & V_45 . V_56 ) ) ;
return 0 ;
}
static T_4 int F_25 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_26 ( V_9 ) ;
if ( V_2 -> V_30 )
return F_24 ( V_2 ) ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 )
{
struct V_62 * V_63 = V_2 -> V_44 ;
struct V_8 * V_9 = V_2 -> V_9 ;
struct V_14 * V_15 ;
union V_67 V_45 = {} ;
const char * V_86 ;
T_2 V_54 ;
T_2 V_56 ;
int V_74 ;
int V_31 ;
V_74 = F_18 ( V_63 , V_87 ,
V_52 , & V_45 ,
sizeof( V_45 . V_54 ) ) ;
if ( V_74 )
return V_74 ;
V_54 = F_15 ( & V_45 . V_54 ) ;
V_74 = F_18 ( V_63 , V_87 ,
V_53 , & V_45 ,
sizeof( V_45 . V_56 ) ) ;
if ( V_74 )
return V_74 ;
V_56 = F_15 ( & V_45 . V_56 ) ;
if ( ! V_54 && ! V_56 )
return 0 ;
V_86 = F_28 ( V_9 , V_75 , L_9 , V_63 -> V_88 ) ;
if ( ! V_86 )
return - V_76 ;
V_15 = F_29 ( V_9 ) ;
if ( ! V_15 )
return - V_76 ;
V_15 -> V_89 = L_10 ;
V_15 -> V_86 = V_86 ;
F_30 ( V_90 , V_15 -> V_91 ) ;
V_15 -> V_92 . V_93 = V_94 ;
V_15 -> V_92 . V_79 = 1 ;
V_15 -> V_92 . V_95 = 0 ;
V_15 -> V_9 . V_96 = V_9 ;
F_31 ( V_15 , V_2 ) ;
V_2 -> V_30 = V_15 ;
for ( V_31 = 0 ; V_31 < F_9 ( V_32 ) ; V_31 ++ ) {
const struct V_33 * V_34 = & V_32 [ V_31 ] ;
if ( V_54 & F_11 ( V_34 -> V_36 ) )
F_32 ( V_15 , V_34 -> V_28 , V_34 -> V_35 ) ;
}
V_74 = F_24 ( V_2 ) ;
if ( V_74 ) {
F_14 ( V_9 , L_11 ) ;
return V_74 ;
}
V_74 = F_33 ( V_2 -> V_30 ) ;
if ( V_74 ) {
F_14 ( V_9 , L_12 ) ;
return V_74 ;
}
return 0 ;
}
static int F_34 ( struct V_1 * V_2 )
{
struct V_62 * V_63 = V_2 -> V_44 ;
struct V_8 * V_9 = V_2 -> V_9 ;
struct V_14 * V_15 ;
const char * V_86 ;
int V_97 ;
V_97 = F_35 ( V_9 , & V_2 -> V_22 , & V_2 -> V_11 ) ;
if ( V_97 )
return V_97 ;
V_2 -> V_10 = F_36 ( V_9 , V_2 -> V_11 , V_75 ) ;
if ( ! V_2 -> V_10 )
return - V_76 ;
V_2 -> V_27 = F_36 ( V_9 , V_2 -> V_11 , V_75 ) ;
if ( ! V_2 -> V_27 )
return - V_76 ;
V_86 = F_28 ( V_9 , V_75 , L_13 , V_63 -> V_88 ) ;
if ( ! V_86 )
return - V_76 ;
V_15 = F_29 ( V_9 ) ;
if ( ! V_15 )
return - V_76 ;
V_15 -> V_89 = V_98 ;
V_15 -> V_86 = V_86 ;
F_30 ( V_90 , V_15 -> V_91 ) ;
V_15 -> V_92 . V_93 = V_94 ;
V_15 -> V_92 . V_79 = 1 ;
V_15 -> V_92 . V_95 = 0 ;
V_15 -> V_9 . V_96 = V_9 ;
V_2 -> V_21 = F_37 ( V_9 -> V_99 ,
L_14 ) ;
V_97 = F_38 ( NULL , NULL , V_2 -> V_22 , V_2 -> V_11 ,
NULL , V_15 ) ;
if ( V_97 ) {
F_14 ( V_9 , L_15 ) ;
return V_97 ;
}
V_2 -> V_24 = F_39 ( V_2 -> V_11 ) ;
F_32 ( V_15 , V_100 , V_101 ) ;
F_31 ( V_15 , V_2 ) ;
V_2 -> V_15 = V_15 ;
F_16 ( V_2 ) ;
V_97 = F_33 ( V_2 -> V_15 ) ;
if ( V_97 ) {
F_14 ( V_9 , L_12 ) ;
return V_97 ;
}
return 0 ;
}
static int F_40 ( struct V_102 * V_103 )
{
struct V_62 * V_44 = F_26 ( V_103 -> V_9 . V_96 ) ;
struct V_8 * V_9 = & V_103 -> V_9 ;
struct V_1 * V_2 ;
int V_97 ;
if ( ! V_9 -> V_99 )
return - V_104 ;
V_2 = F_36 ( V_9 , sizeof( * V_2 ) , V_75 ) ;
if ( ! V_2 )
return - V_76 ;
V_2 -> V_44 = V_44 ;
V_2 -> V_9 = V_9 ;
F_41 ( V_9 , V_2 ) ;
V_97 = F_34 ( V_2 ) ;
if ( V_97 ) {
F_14 ( V_9 , L_16 , V_97 ) ;
return V_97 ;
}
V_97 = F_27 ( V_2 ) ;
if ( V_97 ) {
F_14 ( V_9 , L_17 , V_97 ) ;
return V_97 ;
}
V_2 -> V_42 . V_105 = F_12 ;
V_97 = F_42 ( & V_2 -> V_44 -> V_106 ,
& V_2 -> V_42 ) ;
if ( V_97 ) {
F_14 ( V_9 , L_18 , V_97 ) ;
return V_97 ;
}
return 0 ;
}
static int F_43 ( struct V_102 * V_103 )
{
struct V_1 * V_2 = F_26 ( & V_103 -> V_9 ) ;
F_44 ( & V_2 -> V_44 -> V_106 ,
& V_2 -> V_42 ) ;
return 0 ;
}
