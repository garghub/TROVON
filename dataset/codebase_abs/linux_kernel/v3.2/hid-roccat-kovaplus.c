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
static int F_5 ( struct V_13 * V_14 )
{
int V_17 ;
struct V_18 V_19 ;
do {
V_17 = F_6 ( V_14 , V_24 ,
& V_19 , sizeof( struct V_18 ) ) ;
if ( V_17 )
return V_17 ;
if ( V_19 . V_1 == V_25 )
return 0 ;
if ( V_19 . V_1 == V_26 ) {
F_7 ( 500 ) ;
continue;
}
if ( V_19 . V_1 == V_27 )
return - V_22 ;
F_8 ( V_14 , L_1
L_2 , V_19 . V_1 ) ;
return - V_22 ;
} while ( 1 );
}
static int F_9 ( struct V_13 * V_14 , T_1 V_23 ,
void const * V_28 , T_1 V_29 )
{
int V_17 ;
V_17 = F_4 ( V_14 , V_23 , V_28 , V_29 ) ;
if ( V_17 )
return V_17 ;
F_7 ( 100 ) ;
return F_5 ( V_14 ) ;
}
static int F_10 ( struct V_13 * V_14 , T_1 V_30 ,
enum V_15 V_16 )
{
return F_3 ( V_14 , V_30 , V_16 ) ;
}
static int F_11 ( struct V_13 * V_14 ,
struct V_31 * V_28 )
{
return F_6 ( V_14 , V_32 ,
V_28 , sizeof( struct V_31 ) ) ;
}
static int F_12 ( struct V_13 * V_14 ,
struct V_33 * V_28 , T_1 V_30 )
{
int V_17 ;
V_17 = F_10 ( V_14 , V_30 ,
V_20 ) ;
if ( V_17 )
return V_17 ;
return F_6 ( V_14 , V_34 ,
V_28 , sizeof( struct V_33 ) ) ;
}
static int F_13 ( struct V_13 * V_14 ,
struct V_33 const * V_35 )
{
return F_9 ( V_14 , V_34 ,
V_35 , sizeof( struct V_33 ) ) ;
}
static int F_14 ( struct V_13 * V_14 ,
struct V_36 * V_28 , int V_30 )
{
int V_17 ;
V_17 = F_10 ( V_14 , V_30 ,
V_21 ) ;
if ( V_17 )
return V_17 ;
return F_6 ( V_14 , V_37 ,
V_28 , sizeof( struct V_36 ) ) ;
}
static int F_15 ( struct V_13 * V_14 ,
struct V_36 const * V_38 )
{
return F_9 ( V_14 , V_37 ,
V_38 , sizeof( struct V_36 ) ) ;
}
static int F_16 ( struct V_13 * V_14 )
{
struct V_39 V_28 ;
int V_17 ;
V_17 = F_6 ( V_14 , V_40 ,
& V_28 , sizeof( struct V_39 ) ) ;
return V_17 ? V_17 : V_28 . V_5 ;
}
static int F_17 ( struct V_13 * V_14 ,
int V_41 )
{
struct V_39 V_28 ;
V_28 . V_23 = V_40 ;
V_28 . V_29 = sizeof( struct V_39 ) ;
V_28 . V_5 = V_41 ;
return F_9 ( V_14 , V_40 ,
& V_28 , sizeof( struct V_39 ) ) ;
}
static T_2 F_18 ( struct V_42 * V_43 ,
struct V_44 * V_45 , struct V_46 * V_47 , char * V_28 ,
T_3 V_48 , T_4 V_49 )
{
struct V_50 * V_51 =
F_19 ( V_45 , struct V_50 , V_45 ) -> V_52 -> V_52 ;
struct V_2 * V_3 = F_20 ( F_21 ( V_51 ) ) ;
if ( V_48 >= sizeof( struct V_33 ) )
return 0 ;
if ( V_48 + V_49 > sizeof( struct V_33 ) )
V_49 = sizeof( struct V_33 ) - V_48 ;
F_22 ( & V_3 -> V_53 ) ;
memcpy ( V_28 , ( ( char const * ) & V_3 -> V_7 [ * ( T_1 * ) ( V_47 -> V_54 ) ] ) + V_48 ,
V_49 ) ;
F_23 ( & V_3 -> V_53 ) ;
return V_49 ;
}
static T_2 F_24 ( struct V_42 * V_43 ,
struct V_44 * V_45 , struct V_46 * V_47 , char * V_28 ,
T_3 V_48 , T_4 V_49 )
{
struct V_50 * V_51 =
F_19 ( V_45 , struct V_50 , V_45 ) -> V_52 -> V_52 ;
struct V_2 * V_3 = F_20 ( F_21 ( V_51 ) ) ;
struct V_13 * V_14 = F_25 ( F_26 ( V_51 ) ) ;
int V_17 = 0 ;
int V_55 ;
int V_56 ;
struct V_33 * V_7 ;
if ( V_48 != 0 || V_49 != sizeof( struct V_33 ) )
return - V_22 ;
V_56 = ( (struct V_33 const * ) V_28 ) -> V_56 ;
V_7 = & V_3 -> V_7 [ V_56 ] ;
F_22 ( & V_3 -> V_53 ) ;
V_55 = memcmp ( V_28 , V_7 ,
sizeof( struct V_33 ) ) ;
if ( V_55 ) {
V_17 = F_13 ( V_14 ,
(struct V_33 const * ) V_28 ) ;
if ( ! V_17 )
memcpy ( V_7 , V_28 ,
sizeof( struct V_33 ) ) ;
}
F_23 ( & V_3 -> V_53 ) ;
if ( V_17 )
return V_17 ;
return sizeof( struct V_33 ) ;
}
static T_2 F_27 ( struct V_42 * V_43 ,
struct V_44 * V_45 , struct V_46 * V_47 , char * V_28 ,
T_3 V_48 , T_4 V_49 )
{
struct V_50 * V_51 =
F_19 ( V_45 , struct V_50 , V_45 ) -> V_52 -> V_52 ;
struct V_2 * V_3 = F_20 ( F_21 ( V_51 ) ) ;
if ( V_48 >= sizeof( struct V_36 ) )
return 0 ;
if ( V_48 + V_49 > sizeof( struct V_36 ) )
V_49 = sizeof( struct V_36 ) - V_48 ;
F_22 ( & V_3 -> V_53 ) ;
memcpy ( V_28 , ( ( char const * ) & V_3 -> V_57 [ * ( T_1 * ) ( V_47 -> V_54 ) ] ) + V_48 ,
V_49 ) ;
F_23 ( & V_3 -> V_53 ) ;
return V_49 ;
}
static T_2 F_28 ( struct V_42 * V_43 ,
struct V_44 * V_45 , struct V_46 * V_47 , char * V_28 ,
T_3 V_48 , T_4 V_49 )
{
struct V_50 * V_51 =
F_19 ( V_45 , struct V_50 , V_45 ) -> V_52 -> V_52 ;
struct V_2 * V_3 = F_20 ( F_21 ( V_51 ) ) ;
struct V_13 * V_14 = F_25 ( F_26 ( V_51 ) ) ;
int V_17 = 0 ;
int V_55 ;
T_1 V_56 ;
struct V_36 * V_57 ;
if ( V_48 != 0 || V_49 != sizeof( struct V_36 ) )
return - V_22 ;
V_56 = ( (struct V_36 const * ) V_28 ) -> V_56 ;
V_57 = & V_3 -> V_57 [ V_56 ] ;
F_22 ( & V_3 -> V_53 ) ;
V_55 = memcmp ( V_28 , V_57 ,
sizeof( struct V_36 ) ) ;
if ( V_55 ) {
V_17 = F_15 ( V_14 ,
(struct V_36 const * ) V_28 ) ;
if ( ! V_17 )
memcpy ( V_57 , V_28 ,
sizeof( struct V_36 ) ) ;
}
F_23 ( & V_3 -> V_53 ) ;
if ( V_17 )
return V_17 ;
return sizeof( struct V_36 ) ;
}
static T_2 F_29 ( struct V_50 * V_51 ,
struct V_58 * V_47 , char * V_28 )
{
struct V_2 * V_3 =
F_20 ( F_21 ( V_51 -> V_52 -> V_52 ) ) ;
return snprintf ( V_28 , V_59 , L_3 , V_3 -> V_5 ) ;
}
static T_2 F_30 ( struct V_50 * V_51 ,
struct V_58 * V_47 , char const * V_28 , T_4 V_29 )
{
struct V_2 * V_3 ;
struct V_13 * V_14 ;
unsigned long V_60 ;
int V_17 ;
struct V_61 V_62 ;
V_51 = V_51 -> V_52 -> V_52 ;
V_3 = F_20 ( F_21 ( V_51 ) ) ;
V_14 = F_25 ( F_26 ( V_51 ) ) ;
V_17 = F_31 ( V_28 , 10 , & V_60 ) ;
if ( V_17 )
return V_17 ;
if ( V_60 >= 5 )
return - V_22 ;
F_22 ( & V_3 -> V_53 ) ;
V_17 = F_17 ( V_14 , V_60 ) ;
if ( V_17 ) {
F_23 ( & V_3 -> V_53 ) ;
return V_17 ;
}
F_2 ( V_3 , V_60 ) ;
V_62 . type = V_63 ;
V_62 . V_60 = V_60 + 1 ;
V_62 . V_64 = 0 ;
V_62 . V_65 = V_60 + 1 ;
V_62 . V_66 = 0 ;
F_32 ( V_3 -> V_67 ,
( V_68 const * ) & V_62 ) ;
F_23 ( & V_3 -> V_53 ) ;
return V_29 ;
}
static T_2 F_33 ( struct V_50 * V_51 ,
struct V_58 * V_47 , char * V_28 )
{
struct V_2 * V_3 =
F_20 ( F_21 ( V_51 -> V_52 -> V_52 ) ) ;
return snprintf ( V_28 , V_59 , L_3 , V_3 -> V_6 ) ;
}
static T_2 F_34 ( struct V_50 * V_51 ,
struct V_58 * V_47 , char * V_28 )
{
struct V_2 * V_3 =
F_20 ( F_21 ( V_51 -> V_52 -> V_52 ) ) ;
return snprintf ( V_28 , V_59 , L_3 , V_3 -> V_9 ) ;
}
static T_2 F_35 ( struct V_50 * V_51 ,
struct V_58 * V_47 , char * V_28 )
{
struct V_2 * V_3 =
F_20 ( F_21 ( V_51 -> V_52 -> V_52 ) ) ;
return snprintf ( V_28 , V_59 , L_3 , V_3 -> V_11 ) ;
}
static T_2 F_36 ( struct V_50 * V_51 ,
struct V_58 * V_47 , char * V_28 )
{
struct V_2 * V_3 =
F_20 ( F_21 ( V_51 -> V_52 -> V_52 ) ) ;
return snprintf ( V_28 , V_59 , L_3 , V_3 -> V_69 . V_70 ) ;
}
static int F_37 ( struct V_13 * V_14 ,
struct V_2 * V_3 )
{
int V_17 , V_71 ;
static T_1 V_72 = 70 ;
F_38 ( & V_3 -> V_53 ) ;
V_17 = F_11 ( V_14 , & V_3 -> V_69 ) ;
if ( V_17 )
return V_17 ;
for ( V_71 = 0 ; V_71 < 5 ; ++ V_71 ) {
F_7 ( V_72 ) ;
V_17 = F_12 ( V_14 ,
& V_3 -> V_7 [ V_71 ] , V_71 ) ;
if ( V_17 )
return V_17 ;
F_7 ( V_72 ) ;
V_17 = F_14 ( V_14 ,
& V_3 -> V_57 [ V_71 ] , V_71 ) ;
if ( V_17 )
return V_17 ;
}
F_7 ( V_72 ) ;
V_17 = F_16 ( V_14 ) ;
if ( V_17 < 0 )
return V_17 ;
F_2 ( V_3 , V_17 ) ;
return 0 ;
}
static int F_39 ( struct V_73 * V_74 )
{
struct V_75 * V_76 = F_26 ( V_74 -> V_51 . V_52 ) ;
struct V_13 * V_14 = F_25 ( V_76 ) ;
struct V_2 * V_3 ;
int V_17 ;
if ( V_76 -> V_77 -> V_78 . V_79
== V_80 ) {
V_3 = F_40 ( sizeof( * V_3 ) , V_81 ) ;
if ( ! V_3 ) {
F_8 ( V_74 , L_4 ) ;
return - V_82 ;
}
F_41 ( V_74 , V_3 ) ;
V_17 = F_37 ( V_14 , V_3 ) ;
if ( V_17 ) {
F_8 ( V_74 , L_5 ) ;
goto V_83;
}
V_17 = F_42 ( V_84 , V_74 ,
sizeof( struct V_61 ) ) ;
if ( V_17 < 0 ) {
F_8 ( V_74 , L_6 ) ;
} else {
V_3 -> V_67 = V_17 ;
V_3 -> V_85 = 1 ;
}
} else {
F_41 ( V_74 , NULL ) ;
}
return 0 ;
V_83:
F_43 ( V_3 ) ;
return V_17 ;
}
static void F_44 ( struct V_73 * V_74 )
{
struct V_75 * V_76 = F_26 ( V_74 -> V_51 . V_52 ) ;
struct V_2 * V_3 ;
if ( V_76 -> V_77 -> V_78 . V_79
== V_80 ) {
V_3 = F_20 ( V_74 ) ;
if ( V_3 -> V_85 )
F_45 ( V_3 -> V_67 ) ;
F_43 ( V_3 ) ;
}
}
static int F_46 ( struct V_73 * V_74 ,
const struct V_86 * V_87 )
{
int V_17 ;
V_17 = F_47 ( V_74 ) ;
if ( V_17 ) {
F_8 ( V_74 , L_7 ) ;
goto exit;
}
V_17 = F_48 ( V_74 , V_88 ) ;
if ( V_17 ) {
F_8 ( V_74 , L_8 ) ;
goto exit;
}
V_17 = F_39 ( V_74 ) ;
if ( V_17 ) {
F_8 ( V_74 , L_9 ) ;
goto V_89;
}
return 0 ;
V_89:
F_49 ( V_74 ) ;
exit:
return V_17 ;
}
static void F_50 ( struct V_73 * V_74 )
{
F_44 ( V_74 ) ;
F_49 ( V_74 ) ;
}
static void F_51 ( struct V_2 * V_3 ,
T_5 const * V_90 )
{
struct V_91 const * V_92 ;
if ( V_90 [ 0 ] != V_93 )
return;
V_92 = (struct V_91 const * ) V_90 ;
switch ( V_92 -> type ) {
case V_63 :
F_2 ( V_3 , V_92 -> V_65 - 1 ) ;
break;
case V_94 :
V_3 -> V_6 = F_1 ( V_92 -> V_65 ) ;
case V_95 :
V_3 -> V_9 = V_92 -> V_65 ;
V_3 -> V_11 = V_92 -> V_66 ;
}
}
static void F_52 ( struct V_2 const * V_3 ,
T_5 const * V_90 )
{
struct V_61 V_62 ;
struct V_91 const * V_92 ;
if ( V_90 [ 0 ] != V_93 )
return;
V_92 = (struct V_91 const * ) V_90 ;
if ( V_92 -> type == V_96 )
return;
V_62 . type = V_92 -> type ;
V_62 . V_60 = V_3 -> V_5 + 1 ;
if ( V_62 . type == V_97 ||
V_62 . type == V_98 ||
V_62 . type == V_99 ||
V_62 . type == V_100 )
V_62 . V_64 = V_92 -> V_65 ;
else
V_62 . V_64 = 0 ;
if ( V_62 . type == V_94 )
V_62 . V_65 = F_1 ( V_92 -> V_65 ) ;
else
V_62 . V_65 = V_92 -> V_65 ;
V_62 . V_66 = V_92 -> V_66 ;
F_32 ( V_3 -> V_67 ,
( V_68 const * ) & V_62 ) ;
}
static int F_53 ( struct V_73 * V_74 ,
struct V_101 * V_102 , T_5 * V_90 , int V_29 )
{
struct V_75 * V_76 = F_26 ( V_74 -> V_51 . V_52 ) ;
struct V_2 * V_3 = F_20 ( V_74 ) ;
if ( V_76 -> V_77 -> V_78 . V_79
!= V_80 )
return 0 ;
if ( V_3 == NULL )
return 0 ;
F_51 ( V_3 , V_90 ) ;
if ( V_3 -> V_85 )
F_52 ( V_3 , V_90 ) ;
return 0 ;
}
static int T_6 F_54 ( void )
{
int V_17 ;
V_84 = F_55 ( V_103 , L_10 ) ;
if ( F_56 ( V_84 ) )
return F_57 ( V_84 ) ;
V_84 -> V_104 = V_105 ;
V_84 -> V_106 = V_107 ;
V_17 = F_58 ( & V_108 ) ;
if ( V_17 )
F_59 ( V_84 ) ;
return V_17 ;
}
static void T_7 F_60 ( void )
{
F_61 ( & V_108 ) ;
F_59 ( V_84 ) ;
}
