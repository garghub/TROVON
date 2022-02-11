static void F_1 ( struct V_1 * V_2 ,
T_1 V_3 )
{
V_2 -> V_4 = V_3 ;
}
static int F_2 ( struct V_5 * V_6 , T_1 V_7 ,
enum V_8 V_9 )
{
struct V_10 V_11 ;
if ( ( V_9 == V_12 ||
V_9 == V_13 ) &&
V_7 > 4 )
return - V_14 ;
V_11 . V_15 = V_16 ;
V_11 . V_7 = V_7 ;
V_11 . V_9 = V_9 ;
return F_3 ( V_6 , V_17 ,
& V_11 , sizeof( struct V_10 ) ) ;
}
static int F_4 ( struct V_5 * V_6 )
{
int V_18 ;
struct V_10 V_11 ;
do {
V_18 = F_5 ( V_6 , V_17 ,
& V_11 , sizeof( struct V_10 ) ) ;
if ( V_18 )
return V_18 ;
if ( V_11 . V_7 == V_19 )
return 0 ;
if ( V_11 . V_7 == V_20 ) {
F_6 ( 500 ) ;
continue;
}
if ( V_11 . V_7 == V_21 )
return - V_14 ;
F_7 ( V_6 , L_1
L_2 , V_11 . V_7 ) ;
return - V_14 ;
} while ( 1 );
}
static int F_8 ( struct V_5 * V_6 , T_1 V_15 ,
void const * V_22 , T_1 V_23 )
{
int V_18 ;
V_18 = F_3 ( V_6 , V_15 , V_22 , V_23 ) ;
if ( V_18 )
return V_18 ;
return F_4 ( V_6 ) ;
}
static int F_9 ( struct V_5 * V_6 , T_1 V_24 ,
enum V_8 V_9 )
{
int V_18 ;
V_18 = F_2 ( V_6 , V_24 , V_9 ) ;
if ( V_18 )
return V_18 ;
F_6 ( 100 ) ;
V_18 = F_4 ( V_6 ) ;
if ( V_18 )
return V_18 ;
return 0 ;
}
static int F_10 ( struct V_5 * V_6 ,
struct V_25 * V_22 )
{
return F_5 ( V_6 , V_26 ,
V_22 , sizeof( struct V_25 ) ) ;
}
static int F_11 ( struct V_5 * V_6 ,
struct V_27 * V_22 , T_1 V_24 )
{
int V_18 ;
V_18 = F_9 ( V_6 , V_24 ,
V_12 ) ;
if ( V_18 )
return V_18 ;
return F_5 ( V_6 , V_28 ,
V_22 , sizeof( struct V_27 ) ) ;
}
static int F_12 ( struct V_5 * V_6 ,
struct V_27 const * V_29 )
{
return F_8 ( V_6 , V_28 ,
V_29 , sizeof( struct V_27 ) ) ;
}
static int F_13 ( struct V_5 * V_6 ,
struct V_30 * V_22 , int V_24 )
{
int V_18 ;
V_18 = F_9 ( V_6 , V_24 ,
V_13 ) ;
if ( V_18 )
return V_18 ;
return F_5 ( V_6 , V_31 ,
V_22 , sizeof( struct V_30 ) ) ;
}
static int F_14 ( struct V_5 * V_6 ,
struct V_30 const * V_32 )
{
return F_8 ( V_6 , V_31 ,
V_32 , sizeof( struct V_30 ) ) ;
}
static int F_15 ( struct V_5 * V_6 )
{
struct V_33 V_22 ;
int V_18 ;
V_18 = F_5 ( V_6 , V_34 ,
& V_22 , sizeof( struct V_33 ) ) ;
return V_18 ? V_18 : V_22 . V_4 ;
}
static int F_16 ( struct V_5 * V_6 ,
int V_3 )
{
struct V_33 V_22 ;
V_22 . V_15 = V_35 ;
V_22 . V_23 = sizeof( struct V_33 ) ;
V_22 . V_4 = V_3 ;
return F_8 ( V_6 , V_34 ,
& V_22 , sizeof( struct V_33 ) ) ;
}
static T_2 F_17 ( struct V_36 * V_37 , struct V_38 * V_39 ,
char * V_22 , T_3 V_40 , T_4 V_41 ,
T_4 V_42 , T_1 V_15 )
{
struct V_43 * V_44 =
F_18 ( V_39 , struct V_43 , V_39 ) -> V_45 -> V_45 ;
struct V_1 * V_2 = F_19 ( F_20 ( V_44 ) ) ;
struct V_5 * V_6 = F_21 ( F_22 ( V_44 ) ) ;
int V_18 ;
if ( V_40 >= V_42 )
return 0 ;
if ( V_40 != 0 || V_41 != V_42 )
return - V_14 ;
F_23 ( & V_2 -> V_46 ) ;
V_18 = F_5 ( V_6 , V_15 , V_22 , V_42 ) ;
F_24 ( & V_2 -> V_46 ) ;
if ( V_18 )
return V_18 ;
return V_42 ;
}
static T_2 F_25 ( struct V_36 * V_37 , struct V_38 * V_39 ,
void const * V_22 , T_3 V_40 , T_4 V_41 ,
T_4 V_42 , T_1 V_15 )
{
struct V_43 * V_44 =
F_18 ( V_39 , struct V_43 , V_39 ) -> V_45 -> V_45 ;
struct V_1 * V_2 = F_19 ( F_20 ( V_44 ) ) ;
struct V_5 * V_6 = F_21 ( F_22 ( V_44 ) ) ;
int V_18 ;
if ( V_40 != 0 || V_41 != V_42 )
return - V_14 ;
F_23 ( & V_2 -> V_46 ) ;
V_18 = F_8 ( V_6 , V_15 , V_22 , V_42 ) ;
F_24 ( & V_2 -> V_46 ) ;
if ( V_18 )
return V_18 ;
return V_42 ;
}
static T_2 F_26 ( struct V_36 * V_37 ,
struct V_38 * V_39 , struct V_47 * V_48 , char * V_22 ,
T_3 V_40 , T_4 V_41 )
{
return F_25 ( V_37 , V_39 , V_22 , V_40 , V_41 ,
sizeof( struct V_49 ) , V_50 ) ;
}
static T_2 F_27 ( struct V_36 * V_37 ,
struct V_38 * V_39 , struct V_47 * V_48 , char * V_22 ,
T_3 V_40 , T_4 V_41 )
{
return F_17 ( V_37 , V_39 , V_22 , V_40 , V_41 ,
sizeof( struct V_51 ) , V_52 ) ;
}
static T_2 F_28 ( struct V_36 * V_37 ,
struct V_38 * V_39 , struct V_47 * V_48 , char * V_22 ,
T_3 V_40 , T_4 V_41 )
{
return F_25 ( V_37 , V_39 , V_22 , V_40 , V_41 ,
sizeof( struct V_51 ) , V_52 ) ;
}
static T_2 F_29 ( struct V_36 * V_37 ,
struct V_38 * V_39 , struct V_47 * V_48 , char * V_22 ,
T_3 V_40 , T_4 V_41 )
{
return F_25 ( V_37 , V_39 , V_22 , V_40 , V_41 ,
sizeof( struct V_53 ) , V_54 ) ;
}
static T_2 F_30 ( struct V_36 * V_37 ,
struct V_38 * V_39 , struct V_47 * V_48 , char * V_22 ,
T_3 V_40 , T_4 V_41 )
{
return F_17 ( V_37 , V_39 , V_22 , V_40 , V_41 ,
sizeof( struct V_55 ) , V_54 ) ;
}
static T_2 F_31 ( struct V_36 * V_37 ,
struct V_38 * V_39 , struct V_47 * V_48 , char * V_22 ,
T_3 V_40 , T_4 V_41 )
{
struct V_43 * V_44 =
F_18 ( V_39 , struct V_43 , V_39 ) -> V_45 -> V_45 ;
struct V_1 * V_2 = F_19 ( F_20 ( V_44 ) ) ;
if ( V_40 >= sizeof( struct V_27 ) )
return 0 ;
if ( V_40 + V_41 > sizeof( struct V_27 ) )
V_41 = sizeof( struct V_27 ) - V_40 ;
F_23 ( & V_2 -> V_46 ) ;
memcpy ( V_22 , ( ( char const * ) & V_2 -> V_56 [ * ( T_1 * ) ( V_48 -> V_57 ) ] ) + V_40 ,
V_41 ) ;
F_24 ( & V_2 -> V_46 ) ;
return V_41 ;
}
static T_2 F_32 ( struct V_36 * V_37 ,
struct V_38 * V_39 , struct V_47 * V_48 , char * V_22 ,
T_3 V_40 , T_4 V_41 )
{
struct V_43 * V_44 =
F_18 ( V_39 , struct V_43 , V_39 ) -> V_45 -> V_45 ;
struct V_1 * V_2 = F_19 ( F_20 ( V_44 ) ) ;
struct V_5 * V_6 = F_21 ( F_22 ( V_44 ) ) ;
int V_18 = 0 ;
int V_58 ;
int V_59 ;
struct V_27 * V_56 ;
if ( V_40 != 0 || V_41 != sizeof( struct V_27 ) )
return - V_14 ;
V_59 = ( (struct V_27 const * ) V_22 ) -> V_24 ;
V_56 = & V_2 -> V_56 [ V_59 ] ;
F_23 ( & V_2 -> V_46 ) ;
V_58 = memcmp ( V_22 , V_56 ,
sizeof( struct V_27 ) ) ;
if ( V_58 ) {
V_18 = F_12 ( V_6 ,
(struct V_27 const * ) V_22 ) ;
if ( ! V_18 )
memcpy ( V_56 , V_22 ,
sizeof( struct V_27 ) ) ;
}
F_24 ( & V_2 -> V_46 ) ;
if ( V_18 )
return V_18 ;
return sizeof( struct V_27 ) ;
}
static T_2 F_33 ( struct V_36 * V_37 ,
struct V_38 * V_39 , struct V_47 * V_48 , char * V_22 ,
T_3 V_40 , T_4 V_41 )
{
struct V_43 * V_44 =
F_18 ( V_39 , struct V_43 , V_39 ) -> V_45 -> V_45 ;
struct V_1 * V_2 = F_19 ( F_20 ( V_44 ) ) ;
if ( V_40 >= sizeof( struct V_30 ) )
return 0 ;
if ( V_40 + V_41 > sizeof( struct V_30 ) )
V_41 = sizeof( struct V_30 ) - V_40 ;
F_23 ( & V_2 -> V_46 ) ;
memcpy ( V_22 , ( ( char const * ) & V_2 -> V_60 [ * ( T_1 * ) ( V_48 -> V_57 ) ] ) + V_40 ,
V_41 ) ;
F_24 ( & V_2 -> V_46 ) ;
return V_41 ;
}
static T_2 F_34 ( struct V_36 * V_37 ,
struct V_38 * V_39 , struct V_47 * V_48 , char * V_22 ,
T_3 V_40 , T_4 V_41 )
{
struct V_43 * V_44 =
F_18 ( V_39 , struct V_43 , V_39 ) -> V_45 -> V_45 ;
struct V_1 * V_2 = F_19 ( F_20 ( V_44 ) ) ;
struct V_5 * V_6 = F_21 ( F_22 ( V_44 ) ) ;
int V_18 = 0 ;
int V_58 ;
T_1 V_59 ;
struct V_30 * V_60 ;
if ( V_40 != 0 || V_41 != sizeof( struct V_30 ) )
return - V_14 ;
V_59 = ( (struct V_30 const * ) V_22 ) -> V_24 ;
V_60 = & V_2 -> V_60 [ V_59 ] ;
F_23 ( & V_2 -> V_46 ) ;
V_58 = memcmp ( V_22 , V_60 ,
sizeof( struct V_30 ) ) ;
if ( V_58 ) {
V_18 = F_14 ( V_6 ,
(struct V_30 const * ) V_22 ) ;
if ( ! V_18 )
memcpy ( V_60 , V_22 ,
sizeof( struct V_30 ) ) ;
}
F_24 ( & V_2 -> V_46 ) ;
if ( V_18 )
return V_18 ;
return sizeof( struct V_30 ) ;
}
static T_2 F_35 ( struct V_43 * V_44 ,
struct V_61 * V_48 , char * V_22 )
{
struct V_1 * V_2 =
F_19 ( F_20 ( V_44 -> V_45 -> V_45 ) ) ;
return snprintf ( V_22 , V_62 , L_3 , V_2 -> V_4 ) ;
}
static T_2 F_36 ( struct V_43 * V_44 ,
struct V_61 * V_48 , char const * V_22 , T_4 V_23 )
{
struct V_1 * V_2 ;
struct V_5 * V_6 ;
unsigned long V_63 ;
int V_18 ;
struct V_64 V_65 ;
V_44 = V_44 -> V_45 -> V_45 ;
V_2 = F_19 ( F_20 ( V_44 ) ) ;
V_6 = F_21 ( F_22 ( V_44 ) ) ;
V_18 = F_37 ( V_22 , 10 , & V_63 ) ;
if ( V_18 )
return V_18 ;
F_23 ( & V_2 -> V_46 ) ;
V_18 = F_16 ( V_6 , V_63 ) ;
if ( V_18 ) {
F_24 ( & V_2 -> V_46 ) ;
return V_18 ;
}
V_2 -> V_4 = V_63 ;
V_65 . type = V_66 ;
V_65 . V_67 = V_63 + 1 ;
V_65 . V_68 = 0 ;
V_65 . V_63 = V_63 + 1 ;
F_38 ( V_2 -> V_69 ,
( V_70 const * ) & V_65 ) ;
F_24 ( & V_2 -> V_46 ) ;
return V_23 ;
}
static T_2 F_39 ( struct V_43 * V_44 ,
struct V_61 * V_48 , char * V_22 )
{
struct V_1 * V_2 =
F_19 ( F_20 ( V_44 -> V_45 -> V_45 ) ) ;
return snprintf ( V_22 , V_62 , L_3 , V_2 -> V_71 . V_72 ) ;
}
static int F_40 ( struct V_5 * V_6 ,
struct V_1 * V_2 )
{
int V_18 , V_73 ;
static T_1 V_74 = 200 ;
F_41 ( & V_2 -> V_46 ) ;
V_18 = F_10 ( V_6 , & V_2 -> V_71 ) ;
if ( V_18 )
return V_18 ;
for ( V_73 = 0 ; V_73 < 5 ; ++ V_73 ) {
F_6 ( V_74 ) ;
V_18 = F_11 ( V_6 ,
& V_2 -> V_56 [ V_73 ] , V_73 ) ;
if ( V_18 )
return V_18 ;
F_6 ( V_74 ) ;
V_18 = F_13 ( V_6 ,
& V_2 -> V_60 [ V_73 ] , V_73 ) ;
if ( V_18 )
return V_18 ;
}
F_6 ( V_74 ) ;
V_18 = F_15 ( V_6 ) ;
if ( V_18 < 0 )
return V_18 ;
F_1 ( V_2 , V_18 ) ;
return 0 ;
}
static int F_42 ( struct V_75 * V_76 )
{
struct V_77 * V_78 = F_22 ( V_76 -> V_44 . V_45 ) ;
struct V_5 * V_6 = F_21 ( V_78 ) ;
struct V_1 * V_2 ;
int V_18 ;
if ( V_78 -> V_79 -> V_80 . V_81
== V_82 ) {
V_2 = F_43 ( sizeof( * V_2 ) , V_83 ) ;
if ( ! V_2 ) {
F_7 ( V_76 , L_4 ) ;
return - V_84 ;
}
F_44 ( V_76 , V_2 ) ;
V_18 = F_40 ( V_6 , V_2 ) ;
if ( V_18 ) {
F_7 ( V_76 , L_5 ) ;
goto V_85;
}
V_18 = F_45 ( V_86 , V_76 ,
sizeof( struct V_64 ) ) ;
if ( V_18 < 0 ) {
F_7 ( V_76 , L_6 ) ;
} else {
V_2 -> V_69 = V_18 ;
V_2 -> V_87 = 1 ;
}
} else {
F_44 ( V_76 , NULL ) ;
}
return 0 ;
V_85:
F_46 ( V_2 ) ;
return V_18 ;
}
static void F_47 ( struct V_75 * V_76 )
{
struct V_77 * V_78 = F_22 ( V_76 -> V_44 . V_45 ) ;
struct V_1 * V_2 ;
if ( V_78 -> V_79 -> V_80 . V_81
== V_82 ) {
V_2 = F_19 ( V_76 ) ;
if ( V_2 -> V_87 )
F_48 ( V_2 -> V_69 ) ;
F_46 ( V_2 ) ;
}
}
static int F_49 ( struct V_75 * V_76 ,
const struct V_88 * V_89 )
{
int V_18 ;
V_18 = F_50 ( V_76 ) ;
if ( V_18 ) {
F_7 ( V_76 , L_7 ) ;
goto exit;
}
V_18 = F_51 ( V_76 , V_90 ) ;
if ( V_18 ) {
F_7 ( V_76 , L_8 ) ;
goto exit;
}
V_18 = F_42 ( V_76 ) ;
if ( V_18 ) {
F_7 ( V_76 , L_9 ) ;
goto V_91;
}
return 0 ;
V_91:
F_52 ( V_76 ) ;
exit:
return V_18 ;
}
static void F_53 ( struct V_75 * V_76 )
{
F_47 ( V_76 ) ;
F_52 ( V_76 ) ;
}
static void F_54 ( struct V_1 * V_2 ,
T_5 const * V_92 )
{
struct V_93 const * V_94 ;
switch ( V_92 [ 0 ] ) {
case V_95 :
V_94 = (struct V_93 const * ) V_92 ;
switch ( V_94 -> type ) {
case V_66 :
F_1 ( V_2 , V_94 -> V_67 - 1 ) ;
break;
}
break;
}
}
static void F_55 ( struct V_1 const * V_2 ,
T_5 const * V_92 )
{
struct V_64 V_65 ;
struct V_93 const * V_94 ;
if ( V_92 [ 0 ] != V_95 )
return;
V_94 = (struct V_93 const * ) V_92 ;
if ( ( V_94 -> type == V_96 ||
V_94 -> type == V_97 ) &&
V_94 -> V_68 != V_98 )
return;
V_65 . type = V_94 -> type ;
V_65 . V_67 = V_94 -> V_67 ;
V_65 . V_68 = V_94 -> V_68 ;
V_65 . V_63 = V_2 -> V_4 + 1 ;
F_38 ( V_2 -> V_69 ,
( V_70 const * ) & V_65 ) ;
}
static int F_56 ( struct V_75 * V_76 ,
struct V_99 * V_100 , T_5 * V_92 , int V_23 )
{
struct V_77 * V_78 = F_22 ( V_76 -> V_44 . V_45 ) ;
struct V_1 * V_2 = F_19 ( V_76 ) ;
if ( V_78 -> V_79 -> V_80 . V_81
!= V_82 )
return 0 ;
F_54 ( V_2 , V_92 ) ;
if ( V_2 -> V_87 )
F_55 ( V_2 , V_92 ) ;
return 0 ;
}
static int T_6 F_57 ( void )
{
int V_18 ;
V_86 = F_58 ( V_101 , L_10 ) ;
if ( F_59 ( V_86 ) )
return F_60 ( V_86 ) ;
V_86 -> V_102 = V_103 ;
V_86 -> V_104 = V_105 ;
V_18 = F_61 ( & V_106 ) ;
if ( V_18 )
F_62 ( V_86 ) ;
return V_18 ;
}
static void T_7 F_63 ( void )
{
F_64 ( & V_106 ) ;
F_62 ( V_86 ) ;
}
