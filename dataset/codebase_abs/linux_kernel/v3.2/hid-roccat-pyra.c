static void F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
V_2 -> V_4 = V_3 ;
V_2 -> V_5 = V_2 -> V_6 [ V_2 -> V_4 ] . V_7 ;
}
static int F_2 ( struct V_8 * V_9 , int V_10 ,
enum V_11 V_12 )
{
struct V_13 V_14 ;
if ( ( V_12 == V_15 ||
V_12 == V_16 ) &&
( V_10 < 0 || V_10 > 4 ) )
return - V_17 ;
V_14 . V_18 = V_19 ;
V_14 . V_10 = V_10 ;
V_14 . V_12 = V_12 ;
return F_3 ( V_9 , V_19 ,
& V_14 , sizeof( struct V_13 ) ) ;
}
static int F_4 ( struct V_8 * V_9 )
{
int V_20 ;
struct V_13 V_14 ;
do {
F_5 ( 10 ) ;
V_20 = F_6 ( V_9 , V_19 ,
& V_14 , sizeof( struct V_13 ) ) ;
} while ( V_20 == - V_21 );
if ( ! V_20 && V_14 . V_18 == V_19 &&
V_14 . V_12 == V_22 &&
V_14 . V_10 == 1 )
return 0 ;
else {
F_7 ( V_9 , L_1 ,
V_14 . V_12 , V_14 . V_10 ) ;
return V_20 ? V_20 : - V_17 ;
}
}
static int F_8 ( struct V_8 * V_9 ,
struct V_23 * V_24 , int V_25 )
{
int V_20 ;
V_20 = F_2 ( V_9 , V_25 ,
V_15 ) ;
if ( V_20 )
return V_20 ;
return F_6 ( V_9 , V_26 ,
V_24 , sizeof( struct V_23 ) ) ;
}
static int F_9 ( struct V_8 * V_9 ,
struct V_27 * V_24 , int V_25 )
{
int V_20 ;
V_20 = F_2 ( V_9 , V_25 ,
V_16 ) ;
if ( V_20 )
return V_20 ;
return F_6 ( V_9 , V_28 ,
V_24 , sizeof( struct V_27 ) ) ;
}
static int F_10 ( struct V_8 * V_9 ,
struct V_29 * V_24 )
{
return F_6 ( V_9 , V_30 ,
V_24 , sizeof( struct V_29 ) ) ;
}
static int F_11 ( struct V_8 * V_9 , struct V_31 * V_24 )
{
return F_6 ( V_9 , V_32 ,
V_24 , sizeof( struct V_31 ) ) ;
}
static int F_12 ( struct V_8 * V_9 , T_1 V_18 ,
void const * V_24 , T_1 V_33 )
{
int V_20 ;
V_20 = F_3 ( V_9 , V_18 , V_24 , V_33 ) ;
if ( V_20 )
return V_20 ;
return F_4 ( V_9 ) ;
}
static int F_13 ( struct V_8 * V_9 ,
struct V_23 const * V_34 )
{
return F_12 ( V_9 , V_26 , V_34 ,
sizeof( struct V_23 ) ) ;
}
static int F_14 ( struct V_8 * V_9 ,
struct V_27 const * V_35 )
{
return F_12 ( V_9 , V_28 , V_35 ,
sizeof( struct V_27 ) ) ;
}
static int F_15 ( struct V_8 * V_9 ,
struct V_29 const * V_34 )
{
return F_12 ( V_9 , V_30 , V_34 ,
sizeof( struct V_29 ) ) ;
}
static T_2 F_16 ( struct V_36 * V_37 ,
struct V_38 * V_39 , struct V_40 * V_41 , char * V_24 ,
T_3 V_42 , T_4 V_43 )
{
struct V_44 * V_45 =
F_17 ( V_39 , struct V_44 , V_39 ) -> V_46 -> V_46 ;
struct V_1 * V_2 = F_18 ( F_19 ( V_45 ) ) ;
if ( V_42 >= sizeof( struct V_23 ) )
return 0 ;
if ( V_42 + V_43 > sizeof( struct V_23 ) )
V_43 = sizeof( struct V_23 ) - V_42 ;
F_20 ( & V_2 -> V_47 ) ;
memcpy ( V_24 , ( ( char const * ) & V_2 -> V_6 [ * ( T_1 * ) ( V_41 -> V_48 ) ] ) + V_42 ,
V_43 ) ;
F_21 ( & V_2 -> V_47 ) ;
return V_43 ;
}
static T_2 F_22 ( struct V_36 * V_37 ,
struct V_38 * V_39 , struct V_40 * V_41 , char * V_24 ,
T_3 V_42 , T_4 V_43 )
{
struct V_44 * V_45 =
F_17 ( V_39 , struct V_44 , V_39 ) -> V_46 -> V_46 ;
struct V_1 * V_2 = F_18 ( F_19 ( V_45 ) ) ;
if ( V_42 >= sizeof( struct V_27 ) )
return 0 ;
if ( V_42 + V_43 > sizeof( struct V_27 ) )
V_43 = sizeof( struct V_27 ) - V_42 ;
F_20 ( & V_2 -> V_47 ) ;
memcpy ( V_24 , ( ( char const * ) & V_2 -> V_49 [ * ( T_1 * ) ( V_41 -> V_48 ) ] ) + V_42 ,
V_43 ) ;
F_21 ( & V_2 -> V_47 ) ;
return V_43 ;
}
static T_2 F_23 ( struct V_36 * V_37 ,
struct V_38 * V_39 , struct V_40 * V_41 , char * V_24 ,
T_3 V_42 , T_4 V_43 )
{
struct V_44 * V_45 =
F_17 ( V_39 , struct V_44 , V_39 ) -> V_46 -> V_46 ;
struct V_1 * V_2 = F_18 ( F_19 ( V_45 ) ) ;
struct V_8 * V_9 = F_24 ( F_25 ( V_45 ) ) ;
int V_20 = 0 ;
int V_50 ;
int V_51 ;
struct V_23 * V_6 ;
if ( V_42 != 0 || V_43 != sizeof( struct V_23 ) )
return - V_17 ;
V_51 = ( (struct V_23 const * ) V_24 ) -> V_25 ;
V_6 = & V_2 -> V_6 [ V_51 ] ;
F_20 ( & V_2 -> V_47 ) ;
V_50 = memcmp ( V_24 , V_6 ,
sizeof( struct V_23 ) ) ;
if ( V_50 ) {
V_20 = F_13 ( V_9 ,
(struct V_23 const * ) V_24 ) ;
if ( ! V_20 )
memcpy ( V_6 , V_24 ,
sizeof( struct V_23 ) ) ;
}
F_21 ( & V_2 -> V_47 ) ;
if ( V_20 )
return V_20 ;
return sizeof( struct V_23 ) ;
}
static T_2 F_26 ( struct V_36 * V_37 ,
struct V_38 * V_39 , struct V_40 * V_41 , char * V_24 ,
T_3 V_42 , T_4 V_43 )
{
struct V_44 * V_45 =
F_17 ( V_39 , struct V_44 , V_39 ) -> V_46 -> V_46 ;
struct V_1 * V_2 = F_18 ( F_19 ( V_45 ) ) ;
struct V_8 * V_9 = F_24 ( F_25 ( V_45 ) ) ;
int V_20 = 0 ;
int V_50 ;
int V_51 ;
struct V_27 * V_49 ;
if ( V_42 != 0 || V_43 != sizeof( struct V_27 ) )
return - V_17 ;
V_51 = ( (struct V_27 const * ) V_24 ) -> V_25 ;
V_49 = & V_2 -> V_49 [ V_51 ] ;
F_20 ( & V_2 -> V_47 ) ;
V_50 = memcmp ( V_24 , V_49 ,
sizeof( struct V_27 ) ) ;
if ( V_50 ) {
V_20 = F_14 ( V_9 ,
(struct V_27 const * ) V_24 ) ;
if ( ! V_20 )
memcpy ( V_49 , V_24 ,
sizeof( struct V_27 ) ) ;
}
F_21 ( & V_2 -> V_47 ) ;
if ( V_20 )
return V_20 ;
return sizeof( struct V_27 ) ;
}
static T_2 F_27 ( struct V_36 * V_37 ,
struct V_38 * V_39 , struct V_40 * V_41 , char * V_24 ,
T_3 V_42 , T_4 V_43 )
{
struct V_44 * V_45 =
F_17 ( V_39 , struct V_44 , V_39 ) -> V_46 -> V_46 ;
struct V_1 * V_2 = F_18 ( F_19 ( V_45 ) ) ;
if ( V_42 >= sizeof( struct V_29 ) )
return 0 ;
if ( V_42 + V_43 > sizeof( struct V_29 ) )
V_43 = sizeof( struct V_29 ) - V_42 ;
F_20 ( & V_2 -> V_47 ) ;
memcpy ( V_24 , ( ( char const * ) & V_2 -> V_34 ) + V_42 , V_43 ) ;
F_21 ( & V_2 -> V_47 ) ;
return V_43 ;
}
static T_2 F_28 ( struct V_36 * V_37 ,
struct V_38 * V_39 , struct V_40 * V_41 , char * V_24 ,
T_3 V_42 , T_4 V_43 )
{
struct V_44 * V_45 =
F_17 ( V_39 , struct V_44 , V_39 ) -> V_46 -> V_46 ;
struct V_1 * V_2 = F_18 ( F_19 ( V_45 ) ) ;
struct V_8 * V_9 = F_24 ( F_25 ( V_45 ) ) ;
int V_20 = 0 ;
int V_50 ;
struct V_52 V_53 ;
if ( V_42 != 0 || V_43 != sizeof( struct V_29 ) )
return - V_17 ;
F_20 ( & V_2 -> V_47 ) ;
V_50 = memcmp ( V_24 , & V_2 -> V_34 , sizeof( struct V_29 ) ) ;
if ( V_50 ) {
V_20 = F_15 ( V_9 ,
(struct V_29 const * ) V_24 ) ;
if ( V_20 ) {
F_21 ( & V_2 -> V_47 ) ;
return V_20 ;
}
memcpy ( & V_2 -> V_34 , V_24 ,
sizeof( struct V_29 ) ) ;
F_1 ( V_2 , V_2 -> V_34 . V_54 ) ;
V_53 . type = V_55 ;
V_53 . V_10 = V_2 -> V_34 . V_54 + 1 ;
V_53 . V_56 = 0 ;
F_29 ( V_2 -> V_57 ,
( V_58 const * ) & V_53 ) ;
}
F_21 ( & V_2 -> V_47 ) ;
return sizeof( struct V_29 ) ;
}
static T_2 F_30 ( struct V_44 * V_45 ,
struct V_59 * V_41 , char * V_24 )
{
struct V_1 * V_2 =
F_18 ( F_19 ( V_45 -> V_46 -> V_46 ) ) ;
return snprintf ( V_24 , V_60 , L_2 , V_2 -> V_5 ) ;
}
static T_2 F_31 ( struct V_44 * V_45 ,
struct V_59 * V_41 , char * V_24 )
{
struct V_1 * V_2 =
F_18 ( F_19 ( V_45 -> V_46 -> V_46 ) ) ;
return snprintf ( V_24 , V_60 , L_2 , V_2 -> V_4 ) ;
}
static T_2 F_32 ( struct V_44 * V_45 ,
struct V_59 * V_41 , char * V_24 )
{
struct V_1 * V_2 =
F_18 ( F_19 ( V_45 -> V_46 -> V_46 ) ) ;
return snprintf ( V_24 , V_60 , L_2 , V_2 -> V_61 ) ;
}
static T_2 F_33 ( struct V_44 * V_45 ,
struct V_59 * V_41 , char * V_24 )
{
struct V_1 * V_2 =
F_18 ( F_19 ( V_45 -> V_46 -> V_46 ) ) ;
return snprintf ( V_24 , V_60 , L_2 , V_2 -> V_34 . V_54 ) ;
}
static int F_34 ( struct V_8 * V_9 ,
struct V_1 * V_2 )
{
struct V_31 V_62 ;
int V_20 , V_63 ;
F_35 ( & V_2 -> V_47 ) ;
V_20 = F_11 ( V_9 , & V_62 ) ;
if ( V_20 )
return V_20 ;
V_2 -> V_61 = V_62 . V_61 ;
V_20 = F_10 ( V_9 , & V_2 -> V_34 ) ;
if ( V_20 )
return V_20 ;
for ( V_63 = 0 ; V_63 < 5 ; ++ V_63 ) {
V_20 = F_8 ( V_9 ,
& V_2 -> V_6 [ V_63 ] , V_63 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_9 ( V_9 ,
& V_2 -> V_49 [ V_63 ] , V_63 ) ;
if ( V_20 )
return V_20 ;
}
F_1 ( V_2 , V_2 -> V_34 . V_54 ) ;
return 0 ;
}
static int F_36 ( struct V_64 * V_65 )
{
struct V_66 * V_67 = F_25 ( V_65 -> V_45 . V_46 ) ;
struct V_8 * V_9 = F_24 ( V_67 ) ;
struct V_1 * V_2 ;
int V_20 ;
if ( V_67 -> V_68 -> V_69 . V_70
== V_71 ) {
V_2 = F_37 ( sizeof( * V_2 ) , V_72 ) ;
if ( ! V_2 ) {
F_7 ( V_65 , L_3 ) ;
return - V_73 ;
}
F_38 ( V_65 , V_2 ) ;
V_20 = F_34 ( V_9 , V_2 ) ;
if ( V_20 ) {
F_7 ( V_65 , L_4 ) ;
goto V_74;
}
V_20 = F_39 ( V_75 , V_65 ,
sizeof( struct V_52 ) ) ;
if ( V_20 < 0 ) {
F_7 ( V_65 , L_5 ) ;
} else {
V_2 -> V_57 = V_20 ;
V_2 -> V_76 = 1 ;
}
} else {
F_38 ( V_65 , NULL ) ;
}
return 0 ;
V_74:
F_40 ( V_2 ) ;
return V_20 ;
}
static void F_41 ( struct V_64 * V_65 )
{
struct V_66 * V_67 = F_25 ( V_65 -> V_45 . V_46 ) ;
struct V_1 * V_2 ;
if ( V_67 -> V_68 -> V_69 . V_70
== V_71 ) {
V_2 = F_18 ( V_65 ) ;
if ( V_2 -> V_76 )
F_42 ( V_2 -> V_57 ) ;
F_40 ( F_18 ( V_65 ) ) ;
}
}
static int F_43 ( struct V_64 * V_65 , const struct V_77 * V_78 )
{
int V_20 ;
V_20 = F_44 ( V_65 ) ;
if ( V_20 ) {
F_7 ( V_65 , L_6 ) ;
goto exit;
}
V_20 = F_45 ( V_65 , V_79 ) ;
if ( V_20 ) {
F_7 ( V_65 , L_7 ) ;
goto exit;
}
V_20 = F_36 ( V_65 ) ;
if ( V_20 ) {
F_7 ( V_65 , L_8 ) ;
goto V_80;
}
return 0 ;
V_80:
F_46 ( V_65 ) ;
exit:
return V_20 ;
}
static void F_47 ( struct V_64 * V_65 )
{
F_41 ( V_65 ) ;
F_46 ( V_65 ) ;
}
static void F_48 ( struct V_1 * V_2 ,
T_5 const * V_81 )
{
struct V_82 const * V_83 ;
switch ( V_81 [ 0 ] ) {
case V_84 :
V_83 = (struct V_82 const * ) V_81 ;
switch ( V_83 -> type ) {
case V_55 :
F_1 ( V_2 , V_83 -> V_85 - 1 ) ;
break;
case V_86 :
V_2 -> V_5 = V_83 -> V_85 ;
break;
}
break;
}
}
static void F_49 ( struct V_1 const * V_2 ,
T_5 const * V_81 )
{
struct V_52 V_53 ;
struct V_82 const * V_83 ;
if ( V_81 [ 0 ] != V_84 )
return;
V_83 = (struct V_82 const * ) V_81 ;
switch ( V_83 -> type ) {
case V_55 :
case V_86 :
V_53 . type = V_83 -> type ;
V_53 . V_10 = V_83 -> V_85 ;
V_53 . V_56 = 0 ;
F_29 ( V_2 -> V_57 ,
( V_58 const * ) & V_53 ) ;
break;
case V_87 :
case V_88 :
case V_89 :
if ( V_83 -> V_90 == V_91 ) {
V_53 . type = V_83 -> type ;
V_53 . V_56 = V_83 -> V_85 ;
V_53 . V_10 = V_2 -> V_4 + 1 ;
F_29 ( V_2 -> V_57 ,
( V_58 const * ) & V_53 ) ;
}
break;
}
}
static int F_50 ( struct V_64 * V_65 , struct V_92 * V_93 ,
T_5 * V_81 , int V_33 )
{
struct V_66 * V_67 = F_25 ( V_65 -> V_45 . V_46 ) ;
struct V_1 * V_2 = F_18 ( V_65 ) ;
if ( V_67 -> V_68 -> V_69 . V_70
!= V_71 )
return 0 ;
if ( V_2 == NULL )
return 0 ;
F_48 ( V_2 , V_81 ) ;
if ( V_2 -> V_76 )
F_49 ( V_2 , V_81 ) ;
return 0 ;
}
static int T_6 F_51 ( void )
{
int V_20 ;
V_75 = F_52 ( V_94 , L_9 ) ;
if ( F_53 ( V_75 ) )
return F_54 ( V_75 ) ;
V_75 -> V_95 = V_96 ;
V_75 -> V_97 = V_98 ;
V_20 = F_55 ( & V_99 ) ;
if ( V_20 )
F_56 ( V_75 ) ;
return V_20 ;
}
static void T_7 F_57 ( void )
{
F_58 ( & V_99 ) ;
F_56 ( V_75 ) ;
}
