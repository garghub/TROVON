static T_1 F_1 ( T_1 V_1 )
{
return ( V_1 == 7 ? 4 : ( V_1 == 4 ? 3 : V_1 ) ) ;
}
static void F_2 ( struct V_2 * V_3 ,
T_1 V_4 )
{
V_3 -> V_5 = V_4 ;
V_3 -> V_6 = V_3 -> V_7 [ V_4 ] . V_8 ;
V_3 -> V_9 = V_3 -> V_7 [ V_4 ] . V_10 ;
V_3 -> V_11 = V_3 -> V_7 [ V_4 ] . V_12 ;
}
static int F_3 ( struct V_13 * V_14 , T_1 V_1 ,
enum V_15 V_16 )
{
int V_17 ;
struct V_18 V_19 ;
if ( ( V_16 == V_20 ||
V_16 == V_21 ) &&
V_1 > 4 )
return - V_22 ;
V_19 . V_23 = V_24 ;
V_19 . V_1 = V_1 ;
V_19 . V_16 = V_16 ;
V_17 = F_4 ( V_14 , V_25 ,
& V_19 , sizeof( struct V_18 ) ) ;
return V_17 ;
}
static int F_5 ( struct V_13 * V_14 )
{
int V_17 ;
struct V_18 V_19 ;
do {
V_17 = F_6 ( V_14 , V_25 ,
& V_19 , sizeof( struct V_18 ) ) ;
if ( V_17 )
return V_17 ;
if ( V_19 . V_1 == V_26 )
return 0 ;
if ( V_19 . V_1 == V_27 ) {
F_7 ( 500 ) ;
continue;
}
if ( V_19 . V_1 == V_28 )
return - V_22 ;
F_8 ( V_14 , L_1
L_2 , V_19 . V_1 ) ;
return - V_22 ;
} while ( 1 );
}
static int F_9 ( struct V_13 * V_14 , T_1 V_23 ,
void const * V_29 , T_1 V_30 )
{
int V_17 ;
V_17 = F_4 ( V_14 , V_23 , V_29 , V_30 ) ;
if ( V_17 )
return V_17 ;
F_7 ( 100 ) ;
return F_5 ( V_14 ) ;
}
static int F_10 ( struct V_13 * V_14 , T_1 V_31 ,
enum V_15 V_16 )
{
return F_3 ( V_14 , V_31 , V_16 ) ;
}
static int F_11 ( struct V_13 * V_14 ,
struct V_32 * V_29 )
{
return F_6 ( V_14 , V_33 ,
V_29 , sizeof( struct V_32 ) ) ;
}
static int F_12 ( struct V_13 * V_14 ,
struct V_34 * V_29 , T_1 V_31 )
{
int V_17 ;
V_17 = F_10 ( V_14 , V_31 ,
V_20 ) ;
if ( V_17 )
return V_17 ;
return F_6 ( V_14 , V_35 ,
V_29 , sizeof( struct V_34 ) ) ;
}
static int F_13 ( struct V_13 * V_14 ,
struct V_34 const * V_36 )
{
return F_9 ( V_14 , V_35 ,
V_36 , sizeof( struct V_34 ) ) ;
}
static int F_14 ( struct V_13 * V_14 ,
struct V_37 * V_29 , int V_31 )
{
int V_17 ;
V_17 = F_10 ( V_14 , V_31 ,
V_21 ) ;
if ( V_17 )
return V_17 ;
return F_6 ( V_14 , V_38 ,
V_29 , sizeof( struct V_37 ) ) ;
}
static int F_15 ( struct V_13 * V_14 ,
struct V_37 const * V_39 )
{
return F_9 ( V_14 , V_38 ,
V_39 , sizeof( struct V_37 ) ) ;
}
static int F_16 ( struct V_13 * V_14 )
{
struct V_40 V_29 ;
int V_17 ;
V_17 = F_6 ( V_14 , V_41 ,
& V_29 , sizeof( struct V_40 ) ) ;
return V_17 ? V_17 : V_29 . V_5 ;
}
static int F_17 ( struct V_13 * V_14 ,
int V_42 )
{
struct V_40 V_29 ;
V_29 . V_23 = V_43 ;
V_29 . V_30 = sizeof( struct V_40 ) ;
V_29 . V_5 = V_42 ;
return F_9 ( V_14 , V_41 ,
& V_29 , sizeof( struct V_40 ) ) ;
}
static T_2 F_18 ( struct V_44 * V_45 ,
struct V_46 * V_47 , struct V_48 * V_49 , char * V_29 ,
T_3 V_50 , T_4 V_51 )
{
struct V_52 * V_53 =
F_19 ( V_47 , struct V_52 , V_47 ) -> V_54 -> V_54 ;
struct V_2 * V_3 = F_20 ( F_21 ( V_53 ) ) ;
if ( V_50 >= sizeof( struct V_34 ) )
return 0 ;
if ( V_50 + V_51 > sizeof( struct V_34 ) )
V_51 = sizeof( struct V_34 ) - V_50 ;
F_22 ( & V_3 -> V_55 ) ;
memcpy ( V_29 , ( ( char const * ) & V_3 -> V_7 [ * ( T_1 * ) ( V_49 -> V_56 ) ] ) + V_50 ,
V_51 ) ;
F_23 ( & V_3 -> V_55 ) ;
return V_51 ;
}
static T_2 F_24 ( struct V_44 * V_45 ,
struct V_46 * V_47 , struct V_48 * V_49 , char * V_29 ,
T_3 V_50 , T_4 V_51 )
{
struct V_52 * V_53 =
F_19 ( V_47 , struct V_52 , V_47 ) -> V_54 -> V_54 ;
struct V_2 * V_3 = F_20 ( F_21 ( V_53 ) ) ;
struct V_13 * V_14 = F_25 ( F_26 ( V_53 ) ) ;
int V_17 = 0 ;
int V_57 ;
int V_58 ;
struct V_34 * V_7 ;
if ( V_50 != 0 || V_51 != sizeof( struct V_34 ) )
return - V_22 ;
V_58 = ( (struct V_34 const * ) V_29 ) -> V_58 ;
V_7 = & V_3 -> V_7 [ V_58 ] ;
F_22 ( & V_3 -> V_55 ) ;
V_57 = memcmp ( V_29 , V_7 ,
sizeof( struct V_34 ) ) ;
if ( V_57 ) {
V_17 = F_13 ( V_14 ,
(struct V_34 const * ) V_29 ) ;
if ( ! V_17 )
memcpy ( V_7 , V_29 ,
sizeof( struct V_34 ) ) ;
}
F_23 ( & V_3 -> V_55 ) ;
if ( V_17 )
return V_17 ;
return sizeof( struct V_34 ) ;
}
static T_2 F_27 ( struct V_44 * V_45 ,
struct V_46 * V_47 , struct V_48 * V_49 , char * V_29 ,
T_3 V_50 , T_4 V_51 )
{
struct V_52 * V_53 =
F_19 ( V_47 , struct V_52 , V_47 ) -> V_54 -> V_54 ;
struct V_2 * V_3 = F_20 ( F_21 ( V_53 ) ) ;
if ( V_50 >= sizeof( struct V_37 ) )
return 0 ;
if ( V_50 + V_51 > sizeof( struct V_37 ) )
V_51 = sizeof( struct V_37 ) - V_50 ;
F_22 ( & V_3 -> V_55 ) ;
memcpy ( V_29 , ( ( char const * ) & V_3 -> V_59 [ * ( T_1 * ) ( V_49 -> V_56 ) ] ) + V_50 ,
V_51 ) ;
F_23 ( & V_3 -> V_55 ) ;
return V_51 ;
}
static T_2 F_28 ( struct V_44 * V_45 ,
struct V_46 * V_47 , struct V_48 * V_49 , char * V_29 ,
T_3 V_50 , T_4 V_51 )
{
struct V_52 * V_53 =
F_19 ( V_47 , struct V_52 , V_47 ) -> V_54 -> V_54 ;
struct V_2 * V_3 = F_20 ( F_21 ( V_53 ) ) ;
struct V_13 * V_14 = F_25 ( F_26 ( V_53 ) ) ;
int V_17 = 0 ;
int V_57 ;
T_1 V_58 ;
struct V_37 * V_59 ;
if ( V_50 != 0 || V_51 != sizeof( struct V_37 ) )
return - V_22 ;
V_58 = ( (struct V_37 const * ) V_29 ) -> V_58 ;
V_59 = & V_3 -> V_59 [ V_58 ] ;
F_22 ( & V_3 -> V_55 ) ;
V_57 = memcmp ( V_29 , V_59 ,
sizeof( struct V_37 ) ) ;
if ( V_57 ) {
V_17 = F_15 ( V_14 ,
(struct V_37 const * ) V_29 ) ;
if ( ! V_17 )
memcpy ( V_59 , V_29 ,
sizeof( struct V_37 ) ) ;
}
F_23 ( & V_3 -> V_55 ) ;
if ( V_17 )
return V_17 ;
return sizeof( struct V_37 ) ;
}
static T_2 F_29 ( struct V_52 * V_53 ,
struct V_60 * V_49 , char * V_29 )
{
struct V_2 * V_3 =
F_20 ( F_21 ( V_53 -> V_54 -> V_54 ) ) ;
return snprintf ( V_29 , V_61 , L_3 , V_3 -> V_5 ) ;
}
static T_2 F_30 ( struct V_52 * V_53 ,
struct V_60 * V_49 , char const * V_29 , T_4 V_30 )
{
struct V_2 * V_3 ;
struct V_13 * V_14 ;
unsigned long V_62 ;
int V_17 ;
V_53 = V_53 -> V_54 -> V_54 ;
V_3 = F_20 ( F_21 ( V_53 ) ) ;
V_14 = F_25 ( F_26 ( V_53 ) ) ;
V_17 = F_31 ( V_29 , 10 , & V_62 ) ;
if ( V_17 )
return V_17 ;
if ( V_62 >= 5 )
return - V_22 ;
F_22 ( & V_3 -> V_55 ) ;
V_17 = F_17 ( V_14 , V_62 ) ;
V_3 -> V_5 = V_62 ;
F_23 ( & V_3 -> V_55 ) ;
if ( V_17 )
return V_17 ;
return V_30 ;
}
static T_2 F_32 ( struct V_52 * V_53 ,
struct V_60 * V_49 , char * V_29 )
{
struct V_2 * V_3 =
F_20 ( F_21 ( V_53 -> V_54 -> V_54 ) ) ;
return snprintf ( V_29 , V_61 , L_3 , V_3 -> V_6 ) ;
}
static T_2 F_33 ( struct V_52 * V_53 ,
struct V_60 * V_49 , char * V_29 )
{
struct V_2 * V_3 =
F_20 ( F_21 ( V_53 -> V_54 -> V_54 ) ) ;
return snprintf ( V_29 , V_61 , L_3 , V_3 -> V_9 ) ;
}
static T_2 F_34 ( struct V_52 * V_53 ,
struct V_60 * V_49 , char * V_29 )
{
struct V_2 * V_3 =
F_20 ( F_21 ( V_53 -> V_54 -> V_54 ) ) ;
return snprintf ( V_29 , V_61 , L_3 , V_3 -> V_11 ) ;
}
static T_2 F_35 ( struct V_52 * V_53 ,
struct V_60 * V_49 , char * V_29 )
{
struct V_2 * V_3 =
F_20 ( F_21 ( V_53 -> V_54 -> V_54 ) ) ;
return snprintf ( V_29 , V_61 , L_3 , V_3 -> V_63 . V_64 ) ;
}
static int F_36 ( struct V_13 * V_14 ,
struct V_2 * V_3 )
{
int V_17 , V_65 ;
static T_1 V_66 = 70 ;
F_37 ( & V_3 -> V_55 ) ;
V_17 = F_11 ( V_14 , & V_3 -> V_63 ) ;
if ( V_17 )
return V_17 ;
for ( V_65 = 0 ; V_65 < 5 ; ++ V_65 ) {
F_7 ( V_66 ) ;
V_17 = F_12 ( V_14 ,
& V_3 -> V_7 [ V_65 ] , V_65 ) ;
if ( V_17 )
return V_17 ;
F_7 ( V_66 ) ;
V_17 = F_14 ( V_14 ,
& V_3 -> V_59 [ V_65 ] , V_65 ) ;
if ( V_17 )
return V_17 ;
}
F_7 ( V_66 ) ;
V_17 = F_16 ( V_14 ) ;
if ( V_17 < 0 )
return V_17 ;
F_2 ( V_3 , V_17 ) ;
return 0 ;
}
static int F_38 ( struct V_67 * V_68 )
{
struct V_69 * V_70 = F_26 ( V_68 -> V_53 . V_54 ) ;
struct V_13 * V_14 = F_25 ( V_70 ) ;
struct V_2 * V_3 ;
int V_17 ;
if ( V_70 -> V_71 -> V_72 . V_73
== V_74 ) {
V_3 = F_39 ( sizeof( * V_3 ) , V_75 ) ;
if ( ! V_3 ) {
F_8 ( V_68 , L_4 ) ;
return - V_76 ;
}
F_40 ( V_68 , V_3 ) ;
V_17 = F_36 ( V_14 , V_3 ) ;
if ( V_17 ) {
F_8 ( V_68 , L_5 ) ;
goto V_77;
}
V_17 = F_41 ( V_78 , V_68 ,
sizeof( struct V_79 ) ) ;
if ( V_17 < 0 ) {
F_8 ( V_68 , L_6 ) ;
} else {
V_3 -> V_80 = V_17 ;
V_3 -> V_81 = 1 ;
}
} else {
F_40 ( V_68 , NULL ) ;
}
return 0 ;
V_77:
F_42 ( V_3 ) ;
return V_17 ;
}
static void F_43 ( struct V_67 * V_68 )
{
struct V_69 * V_70 = F_26 ( V_68 -> V_53 . V_54 ) ;
struct V_2 * V_3 ;
if ( V_70 -> V_71 -> V_72 . V_73
== V_74 ) {
V_3 = F_20 ( V_68 ) ;
if ( V_3 -> V_81 )
F_44 ( V_3 -> V_80 ) ;
F_42 ( V_3 ) ;
}
}
static int F_45 ( struct V_67 * V_68 ,
const struct V_82 * V_83 )
{
int V_17 ;
V_17 = F_46 ( V_68 ) ;
if ( V_17 ) {
F_8 ( V_68 , L_7 ) ;
goto exit;
}
V_17 = F_47 ( V_68 , V_84 ) ;
if ( V_17 ) {
F_8 ( V_68 , L_8 ) ;
goto exit;
}
V_17 = F_38 ( V_68 ) ;
if ( V_17 ) {
F_8 ( V_68 , L_9 ) ;
goto V_85;
}
return 0 ;
V_85:
F_48 ( V_68 ) ;
exit:
return V_17 ;
}
static void F_49 ( struct V_67 * V_68 )
{
F_43 ( V_68 ) ;
F_48 ( V_68 ) ;
}
static void F_50 ( struct V_2 * V_3 ,
T_5 const * V_86 )
{
struct V_87 const * V_88 ;
if ( V_86 [ 0 ] != V_89 )
return;
V_88 = (struct V_87 const * ) V_86 ;
switch ( V_88 -> type ) {
case V_90 :
F_2 ( V_3 , V_88 -> V_91 - 1 ) ;
break;
case V_92 :
V_3 -> V_6 = F_1 ( V_88 -> V_91 ) ;
case V_93 :
V_3 -> V_9 = V_88 -> V_91 ;
V_3 -> V_11 = V_88 -> V_94 ;
}
}
static void F_51 ( struct V_2 const * V_3 ,
T_5 const * V_86 )
{
struct V_79 V_95 ;
struct V_87 const * V_88 ;
if ( V_86 [ 0 ] != V_89 )
return;
V_88 = (struct V_87 const * ) V_86 ;
if ( V_88 -> type == V_96 )
return;
V_95 . type = V_88 -> type ;
V_95 . V_62 = V_3 -> V_5 + 1 ;
if ( V_95 . type == V_97 ||
V_95 . type == V_98 ||
V_95 . type == V_99 ||
V_95 . type == V_100 )
V_95 . V_101 = V_88 -> V_91 ;
else
V_95 . V_101 = 0 ;
if ( V_95 . type == V_92 )
V_95 . V_91 = F_1 ( V_88 -> V_91 ) ;
else
V_95 . V_91 = V_88 -> V_91 ;
V_95 . V_94 = V_88 -> V_94 ;
F_52 ( V_3 -> V_80 ,
( V_102 const * ) & V_95 ) ;
}
static int F_53 ( struct V_67 * V_68 ,
struct V_103 * V_104 , T_5 * V_86 , int V_30 )
{
struct V_69 * V_70 = F_26 ( V_68 -> V_53 . V_54 ) ;
struct V_2 * V_3 = F_20 ( V_68 ) ;
if ( V_70 -> V_71 -> V_72 . V_73
!= V_74 )
return 0 ;
F_50 ( V_3 , V_86 ) ;
if ( V_3 -> V_81 )
F_51 ( V_3 , V_86 ) ;
return 0 ;
}
static int T_6 F_54 ( void )
{
int V_17 ;
V_78 = F_55 ( V_105 , L_10 ) ;
if ( F_56 ( V_78 ) )
return F_57 ( V_78 ) ;
V_78 -> V_106 = V_107 ;
V_78 -> V_108 = V_109 ;
V_17 = F_58 ( & V_110 ) ;
if ( V_17 )
F_59 ( V_78 ) ;
return V_17 ;
}
static void T_7 F_60 ( void )
{
F_61 ( & V_110 ) ;
F_59 ( V_78 ) ;
}
