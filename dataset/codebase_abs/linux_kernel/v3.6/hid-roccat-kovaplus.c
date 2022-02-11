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
V_17 = F_4 ( V_14 , V_24 ,
& V_19 , sizeof( struct V_18 ) ) ;
return V_17 ;
}
static int F_5 ( struct V_13 * V_14 , T_1 V_25 ,
enum V_15 V_16 )
{
return F_3 ( V_14 , V_25 , V_16 ) ;
}
static int F_6 ( struct V_13 * V_14 ,
struct V_26 * V_27 )
{
return F_7 ( V_14 , V_28 ,
V_27 , sizeof( struct V_26 ) ) ;
}
static int F_8 ( struct V_13 * V_14 ,
struct V_29 * V_27 , T_1 V_25 )
{
int V_17 ;
V_17 = F_5 ( V_14 , V_25 ,
V_20 ) ;
if ( V_17 )
return V_17 ;
return F_7 ( V_14 , V_30 ,
V_27 , sizeof( struct V_29 ) ) ;
}
static int F_9 ( struct V_13 * V_14 ,
struct V_29 const * V_31 )
{
return F_10 ( V_14 ,
V_30 ,
V_31 , sizeof( struct V_29 ) ) ;
}
static int F_11 ( struct V_13 * V_14 ,
struct V_32 * V_27 , int V_25 )
{
int V_17 ;
V_17 = F_5 ( V_14 , V_25 ,
V_21 ) ;
if ( V_17 )
return V_17 ;
return F_7 ( V_14 , V_33 ,
V_27 , sizeof( struct V_32 ) ) ;
}
static int F_12 ( struct V_13 * V_14 ,
struct V_32 const * V_34 )
{
return F_10 ( V_14 ,
V_33 ,
V_34 , sizeof( struct V_32 ) ) ;
}
static int F_13 ( struct V_13 * V_14 )
{
struct V_35 V_27 ;
int V_17 ;
V_17 = F_7 ( V_14 , V_36 ,
& V_27 , sizeof( struct V_35 ) ) ;
return V_17 ? V_17 : V_27 . V_5 ;
}
static int F_14 ( struct V_13 * V_14 ,
int V_37 )
{
struct V_35 V_27 ;
V_27 . V_23 = V_36 ;
V_27 . V_38 = sizeof( struct V_35 ) ;
V_27 . V_5 = V_37 ;
return F_10 ( V_14 ,
V_36 ,
& V_27 , sizeof( struct V_35 ) ) ;
}
static T_2 F_15 ( struct V_39 * V_40 ,
struct V_41 * V_42 , struct V_43 * V_44 , char * V_27 ,
T_3 V_45 , T_4 V_46 )
{
struct V_47 * V_48 =
F_16 ( V_42 , struct V_47 , V_42 ) -> V_49 -> V_49 ;
struct V_2 * V_3 = F_17 ( F_18 ( V_48 ) ) ;
if ( V_45 >= sizeof( struct V_29 ) )
return 0 ;
if ( V_45 + V_46 > sizeof( struct V_29 ) )
V_46 = sizeof( struct V_29 ) - V_45 ;
F_19 ( & V_3 -> V_50 ) ;
memcpy ( V_27 , ( ( char const * ) & V_3 -> V_7 [ * ( T_1 * ) ( V_44 -> V_51 ) ] ) + V_45 ,
V_46 ) ;
F_20 ( & V_3 -> V_50 ) ;
return V_46 ;
}
static T_2 F_21 ( struct V_39 * V_40 ,
struct V_41 * V_42 , struct V_43 * V_44 , char * V_27 ,
T_3 V_45 , T_4 V_46 )
{
struct V_47 * V_48 =
F_16 ( V_42 , struct V_47 , V_42 ) -> V_49 -> V_49 ;
struct V_2 * V_3 = F_17 ( F_18 ( V_48 ) ) ;
struct V_13 * V_14 = F_22 ( F_23 ( V_48 ) ) ;
int V_17 = 0 ;
int V_52 ;
int V_53 ;
struct V_29 * V_7 ;
if ( V_45 != 0 || V_46 != sizeof( struct V_29 ) )
return - V_22 ;
V_53 = ( (struct V_29 const * ) V_27 ) -> V_53 ;
V_7 = & V_3 -> V_7 [ V_53 ] ;
F_19 ( & V_3 -> V_50 ) ;
V_52 = memcmp ( V_27 , V_7 ,
sizeof( struct V_29 ) ) ;
if ( V_52 ) {
V_17 = F_9 ( V_14 ,
(struct V_29 const * ) V_27 ) ;
if ( ! V_17 )
memcpy ( V_7 , V_27 ,
sizeof( struct V_29 ) ) ;
}
F_20 ( & V_3 -> V_50 ) ;
if ( V_17 )
return V_17 ;
return sizeof( struct V_29 ) ;
}
static T_2 F_24 ( struct V_39 * V_40 ,
struct V_41 * V_42 , struct V_43 * V_44 , char * V_27 ,
T_3 V_45 , T_4 V_46 )
{
struct V_47 * V_48 =
F_16 ( V_42 , struct V_47 , V_42 ) -> V_49 -> V_49 ;
struct V_2 * V_3 = F_17 ( F_18 ( V_48 ) ) ;
if ( V_45 >= sizeof( struct V_32 ) )
return 0 ;
if ( V_45 + V_46 > sizeof( struct V_32 ) )
V_46 = sizeof( struct V_32 ) - V_45 ;
F_19 ( & V_3 -> V_50 ) ;
memcpy ( V_27 , ( ( char const * ) & V_3 -> V_54 [ * ( T_1 * ) ( V_44 -> V_51 ) ] ) + V_45 ,
V_46 ) ;
F_20 ( & V_3 -> V_50 ) ;
return V_46 ;
}
static T_2 F_25 ( struct V_39 * V_40 ,
struct V_41 * V_42 , struct V_43 * V_44 , char * V_27 ,
T_3 V_45 , T_4 V_46 )
{
struct V_47 * V_48 =
F_16 ( V_42 , struct V_47 , V_42 ) -> V_49 -> V_49 ;
struct V_2 * V_3 = F_17 ( F_18 ( V_48 ) ) ;
struct V_13 * V_14 = F_22 ( F_23 ( V_48 ) ) ;
int V_17 = 0 ;
int V_52 ;
T_1 V_53 ;
struct V_32 * V_54 ;
if ( V_45 != 0 || V_46 != sizeof( struct V_32 ) )
return - V_22 ;
V_53 = ( (struct V_32 const * ) V_27 ) -> V_53 ;
V_54 = & V_3 -> V_54 [ V_53 ] ;
F_19 ( & V_3 -> V_50 ) ;
V_52 = memcmp ( V_27 , V_54 ,
sizeof( struct V_32 ) ) ;
if ( V_52 ) {
V_17 = F_12 ( V_14 ,
(struct V_32 const * ) V_27 ) ;
if ( ! V_17 )
memcpy ( V_54 , V_27 ,
sizeof( struct V_32 ) ) ;
}
F_20 ( & V_3 -> V_50 ) ;
if ( V_17 )
return V_17 ;
return sizeof( struct V_32 ) ;
}
static T_2 F_26 ( struct V_47 * V_48 ,
struct V_55 * V_44 , char * V_27 )
{
struct V_2 * V_3 =
F_17 ( F_18 ( V_48 -> V_49 -> V_49 ) ) ;
return snprintf ( V_27 , V_56 , L_1 , V_3 -> V_5 ) ;
}
static T_2 F_27 ( struct V_47 * V_48 ,
struct V_55 * V_44 , char const * V_27 , T_4 V_38 )
{
struct V_2 * V_3 ;
struct V_13 * V_14 ;
unsigned long V_57 ;
int V_17 ;
struct V_58 V_59 ;
V_48 = V_48 -> V_49 -> V_49 ;
V_3 = F_17 ( F_18 ( V_48 ) ) ;
V_14 = F_22 ( F_23 ( V_48 ) ) ;
V_17 = F_28 ( V_27 , 10 , & V_57 ) ;
if ( V_17 )
return V_17 ;
if ( V_57 >= 5 )
return - V_22 ;
F_19 ( & V_3 -> V_50 ) ;
V_17 = F_14 ( V_14 , V_57 ) ;
if ( V_17 ) {
F_20 ( & V_3 -> V_50 ) ;
return V_17 ;
}
F_2 ( V_3 , V_57 ) ;
V_59 . type = V_60 ;
V_59 . V_57 = V_57 + 1 ;
V_59 . V_61 = 0 ;
V_59 . V_62 = V_57 + 1 ;
V_59 . V_63 = 0 ;
F_29 ( V_3 -> V_64 ,
( V_65 const * ) & V_59 ) ;
F_20 ( & V_3 -> V_50 ) ;
return V_38 ;
}
static T_2 F_30 ( struct V_47 * V_48 ,
struct V_55 * V_44 , char * V_27 )
{
struct V_2 * V_3 =
F_17 ( F_18 ( V_48 -> V_49 -> V_49 ) ) ;
return snprintf ( V_27 , V_56 , L_1 , V_3 -> V_6 ) ;
}
static T_2 F_31 ( struct V_47 * V_48 ,
struct V_55 * V_44 , char * V_27 )
{
struct V_2 * V_3 =
F_17 ( F_18 ( V_48 -> V_49 -> V_49 ) ) ;
return snprintf ( V_27 , V_56 , L_1 , V_3 -> V_9 ) ;
}
static T_2 F_32 ( struct V_47 * V_48 ,
struct V_55 * V_44 , char * V_27 )
{
struct V_2 * V_3 =
F_17 ( F_18 ( V_48 -> V_49 -> V_49 ) ) ;
return snprintf ( V_27 , V_56 , L_1 , V_3 -> V_11 ) ;
}
static T_2 F_33 ( struct V_47 * V_48 ,
struct V_55 * V_44 , char * V_27 )
{
struct V_2 * V_3 =
F_17 ( F_18 ( V_48 -> V_49 -> V_49 ) ) ;
return snprintf ( V_27 , V_56 , L_1 , V_3 -> V_66 . V_67 ) ;
}
static int F_34 ( struct V_13 * V_14 ,
struct V_2 * V_3 )
{
int V_17 , V_68 ;
static T_1 V_69 = 70 ;
F_35 ( & V_3 -> V_50 ) ;
V_17 = F_6 ( V_14 , & V_3 -> V_66 ) ;
if ( V_17 )
return V_17 ;
for ( V_68 = 0 ; V_68 < 5 ; ++ V_68 ) {
F_36 ( V_69 ) ;
V_17 = F_8 ( V_14 ,
& V_3 -> V_7 [ V_68 ] , V_68 ) ;
if ( V_17 )
return V_17 ;
F_36 ( V_69 ) ;
V_17 = F_11 ( V_14 ,
& V_3 -> V_54 [ V_68 ] , V_68 ) ;
if ( V_17 )
return V_17 ;
}
F_36 ( V_69 ) ;
V_17 = F_13 ( V_14 ) ;
if ( V_17 < 0 )
return V_17 ;
F_2 ( V_3 , V_17 ) ;
return 0 ;
}
static int F_37 ( struct V_70 * V_71 )
{
struct V_72 * V_73 = F_23 ( V_71 -> V_48 . V_49 ) ;
struct V_13 * V_14 = F_22 ( V_73 ) ;
struct V_2 * V_3 ;
int V_17 ;
if ( V_73 -> V_74 -> V_75 . V_76
== V_77 ) {
V_3 = F_38 ( sizeof( * V_3 ) , V_78 ) ;
if ( ! V_3 ) {
F_39 ( V_71 , L_2 ) ;
return - V_79 ;
}
F_40 ( V_71 , V_3 ) ;
V_17 = F_34 ( V_14 , V_3 ) ;
if ( V_17 ) {
F_39 ( V_71 , L_3 ) ;
goto V_80;
}
V_17 = F_41 ( V_81 , V_71 ,
sizeof( struct V_58 ) ) ;
if ( V_17 < 0 ) {
F_39 ( V_71 , L_4 ) ;
} else {
V_3 -> V_64 = V_17 ;
V_3 -> V_82 = 1 ;
}
} else {
F_40 ( V_71 , NULL ) ;
}
return 0 ;
V_80:
F_42 ( V_3 ) ;
return V_17 ;
}
static void F_43 ( struct V_70 * V_71 )
{
struct V_72 * V_73 = F_23 ( V_71 -> V_48 . V_49 ) ;
struct V_2 * V_3 ;
if ( V_73 -> V_74 -> V_75 . V_76
== V_77 ) {
V_3 = F_17 ( V_71 ) ;
if ( V_3 -> V_82 )
F_44 ( V_3 -> V_64 ) ;
F_42 ( V_3 ) ;
}
}
static int F_45 ( struct V_70 * V_71 ,
const struct V_83 * V_84 )
{
int V_17 ;
V_17 = F_46 ( V_71 ) ;
if ( V_17 ) {
F_39 ( V_71 , L_5 ) ;
goto exit;
}
V_17 = F_47 ( V_71 , V_85 ) ;
if ( V_17 ) {
F_39 ( V_71 , L_6 ) ;
goto exit;
}
V_17 = F_37 ( V_71 ) ;
if ( V_17 ) {
F_39 ( V_71 , L_7 ) ;
goto V_86;
}
return 0 ;
V_86:
F_48 ( V_71 ) ;
exit:
return V_17 ;
}
static void F_49 ( struct V_70 * V_71 )
{
F_43 ( V_71 ) ;
F_48 ( V_71 ) ;
}
static void F_50 ( struct V_2 * V_3 ,
T_5 const * V_87 )
{
struct V_88 const * V_89 ;
if ( V_87 [ 0 ] != V_90 )
return;
V_89 = (struct V_88 const * ) V_87 ;
switch ( V_89 -> type ) {
case V_60 :
F_2 ( V_3 , V_89 -> V_62 - 1 ) ;
break;
case V_91 :
V_3 -> V_6 = F_1 ( V_89 -> V_62 ) ;
case V_92 :
V_3 -> V_9 = V_89 -> V_62 ;
V_3 -> V_11 = V_89 -> V_63 ;
}
}
static void F_51 ( struct V_2 const * V_3 ,
T_5 const * V_87 )
{
struct V_58 V_59 ;
struct V_88 const * V_89 ;
if ( V_87 [ 0 ] != V_90 )
return;
V_89 = (struct V_88 const * ) V_87 ;
if ( V_89 -> type == V_93 )
return;
V_59 . type = V_89 -> type ;
V_59 . V_57 = V_3 -> V_5 + 1 ;
if ( V_59 . type == V_94 ||
V_59 . type == V_95 ||
V_59 . type == V_96 ||
V_59 . type == V_97 )
V_59 . V_61 = V_89 -> V_62 ;
else
V_59 . V_61 = 0 ;
if ( V_59 . type == V_91 )
V_59 . V_62 = F_1 ( V_89 -> V_62 ) ;
else
V_59 . V_62 = V_89 -> V_62 ;
V_59 . V_63 = V_89 -> V_63 ;
F_29 ( V_3 -> V_64 ,
( V_65 const * ) & V_59 ) ;
}
static int F_52 ( struct V_70 * V_71 ,
struct V_98 * V_99 , T_5 * V_87 , int V_38 )
{
struct V_72 * V_73 = F_23 ( V_71 -> V_48 . V_49 ) ;
struct V_2 * V_3 = F_17 ( V_71 ) ;
if ( V_73 -> V_74 -> V_75 . V_76
!= V_77 )
return 0 ;
if ( V_3 == NULL )
return 0 ;
F_50 ( V_3 , V_87 ) ;
if ( V_3 -> V_82 )
F_51 ( V_3 , V_87 ) ;
return 0 ;
}
static int T_6 F_53 ( void )
{
int V_17 ;
V_81 = F_54 ( V_100 , L_8 ) ;
if ( F_55 ( V_81 ) )
return F_56 ( V_81 ) ;
V_81 -> V_101 = V_102 ;
V_81 -> V_103 = V_104 ;
V_17 = F_57 ( & V_105 ) ;
if ( V_17 )
F_58 ( V_81 ) ;
return V_17 ;
}
static void T_7 F_59 ( void )
{
F_60 ( & V_105 ) ;
F_58 ( V_81 ) ;
}
