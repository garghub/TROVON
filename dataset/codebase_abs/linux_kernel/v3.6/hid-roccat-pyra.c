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
static int F_4 ( struct V_8 * V_9 ,
struct V_20 * V_21 , int V_22 )
{
int V_23 ;
V_23 = F_2 ( V_9 , V_22 ,
V_15 ) ;
if ( V_23 )
return V_23 ;
return F_5 ( V_9 , V_24 ,
V_21 , sizeof( struct V_20 ) ) ;
}
static int F_6 ( struct V_8 * V_9 ,
struct V_25 * V_21 , int V_22 )
{
int V_23 ;
V_23 = F_2 ( V_9 , V_22 ,
V_16 ) ;
if ( V_23 )
return V_23 ;
return F_5 ( V_9 , V_26 ,
V_21 , sizeof( struct V_25 ) ) ;
}
static int F_7 ( struct V_8 * V_9 ,
struct V_27 * V_21 )
{
return F_5 ( V_9 , V_28 ,
V_21 , sizeof( struct V_27 ) ) ;
}
static int F_8 ( struct V_8 * V_9 , struct V_29 * V_21 )
{
return F_5 ( V_9 , V_30 ,
V_21 , sizeof( struct V_29 ) ) ;
}
static int F_9 ( struct V_8 * V_9 ,
struct V_20 const * V_31 )
{
return F_10 ( V_9 ,
V_24 , V_31 ,
sizeof( struct V_20 ) ) ;
}
static int F_11 ( struct V_8 * V_9 ,
struct V_25 const * V_32 )
{
return F_10 ( V_9 ,
V_26 , V_32 ,
sizeof( struct V_25 ) ) ;
}
static int F_12 ( struct V_8 * V_9 ,
struct V_27 const * V_31 )
{
return F_10 ( V_9 ,
V_28 , V_31 ,
sizeof( struct V_27 ) ) ;
}
static T_1 F_13 ( struct V_33 * V_34 ,
struct V_35 * V_36 , struct V_37 * V_38 , char * V_21 ,
T_2 V_39 , T_3 V_40 )
{
struct V_41 * V_42 =
F_14 ( V_36 , struct V_41 , V_36 ) -> V_43 -> V_43 ;
struct V_1 * V_2 = F_15 ( F_16 ( V_42 ) ) ;
if ( V_39 >= sizeof( struct V_20 ) )
return 0 ;
if ( V_39 + V_40 > sizeof( struct V_20 ) )
V_40 = sizeof( struct V_20 ) - V_39 ;
F_17 ( & V_2 -> V_44 ) ;
memcpy ( V_21 , ( ( char const * ) & V_2 -> V_6 [ * ( V_45 * ) ( V_38 -> V_46 ) ] ) + V_39 ,
V_40 ) ;
F_18 ( & V_2 -> V_44 ) ;
return V_40 ;
}
static T_1 F_19 ( struct V_33 * V_34 ,
struct V_35 * V_36 , struct V_37 * V_38 , char * V_21 ,
T_2 V_39 , T_3 V_40 )
{
struct V_41 * V_42 =
F_14 ( V_36 , struct V_41 , V_36 ) -> V_43 -> V_43 ;
struct V_1 * V_2 = F_15 ( F_16 ( V_42 ) ) ;
if ( V_39 >= sizeof( struct V_25 ) )
return 0 ;
if ( V_39 + V_40 > sizeof( struct V_25 ) )
V_40 = sizeof( struct V_25 ) - V_39 ;
F_17 ( & V_2 -> V_44 ) ;
memcpy ( V_21 , ( ( char const * ) & V_2 -> V_47 [ * ( V_45 * ) ( V_38 -> V_46 ) ] ) + V_39 ,
V_40 ) ;
F_18 ( & V_2 -> V_44 ) ;
return V_40 ;
}
static T_1 F_20 ( struct V_33 * V_34 ,
struct V_35 * V_36 , struct V_37 * V_38 , char * V_21 ,
T_2 V_39 , T_3 V_40 )
{
struct V_41 * V_42 =
F_14 ( V_36 , struct V_41 , V_36 ) -> V_43 -> V_43 ;
struct V_1 * V_2 = F_15 ( F_16 ( V_42 ) ) ;
struct V_8 * V_9 = F_21 ( F_22 ( V_42 ) ) ;
int V_23 = 0 ;
int V_48 ;
int V_49 ;
struct V_20 * V_6 ;
if ( V_39 != 0 || V_40 != sizeof( struct V_20 ) )
return - V_17 ;
V_49 = ( (struct V_20 const * ) V_21 ) -> V_22 ;
V_6 = & V_2 -> V_6 [ V_49 ] ;
F_17 ( & V_2 -> V_44 ) ;
V_48 = memcmp ( V_21 , V_6 ,
sizeof( struct V_20 ) ) ;
if ( V_48 ) {
V_23 = F_9 ( V_9 ,
(struct V_20 const * ) V_21 ) ;
if ( ! V_23 )
memcpy ( V_6 , V_21 ,
sizeof( struct V_20 ) ) ;
}
F_18 ( & V_2 -> V_44 ) ;
if ( V_23 )
return V_23 ;
return sizeof( struct V_20 ) ;
}
static T_1 F_23 ( struct V_33 * V_34 ,
struct V_35 * V_36 , struct V_37 * V_38 , char * V_21 ,
T_2 V_39 , T_3 V_40 )
{
struct V_41 * V_42 =
F_14 ( V_36 , struct V_41 , V_36 ) -> V_43 -> V_43 ;
struct V_1 * V_2 = F_15 ( F_16 ( V_42 ) ) ;
struct V_8 * V_9 = F_21 ( F_22 ( V_42 ) ) ;
int V_23 = 0 ;
int V_48 ;
int V_49 ;
struct V_25 * V_47 ;
if ( V_39 != 0 || V_40 != sizeof( struct V_25 ) )
return - V_17 ;
V_49 = ( (struct V_25 const * ) V_21 ) -> V_22 ;
V_47 = & V_2 -> V_47 [ V_49 ] ;
F_17 ( & V_2 -> V_44 ) ;
V_48 = memcmp ( V_21 , V_47 ,
sizeof( struct V_25 ) ) ;
if ( V_48 ) {
V_23 = F_11 ( V_9 ,
(struct V_25 const * ) V_21 ) ;
if ( ! V_23 )
memcpy ( V_47 , V_21 ,
sizeof( struct V_25 ) ) ;
}
F_18 ( & V_2 -> V_44 ) ;
if ( V_23 )
return V_23 ;
return sizeof( struct V_25 ) ;
}
static T_1 F_24 ( struct V_33 * V_34 ,
struct V_35 * V_36 , struct V_37 * V_38 , char * V_21 ,
T_2 V_39 , T_3 V_40 )
{
struct V_41 * V_42 =
F_14 ( V_36 , struct V_41 , V_36 ) -> V_43 -> V_43 ;
struct V_1 * V_2 = F_15 ( F_16 ( V_42 ) ) ;
if ( V_39 >= sizeof( struct V_27 ) )
return 0 ;
if ( V_39 + V_40 > sizeof( struct V_27 ) )
V_40 = sizeof( struct V_27 ) - V_39 ;
F_17 ( & V_2 -> V_44 ) ;
memcpy ( V_21 , ( ( char const * ) & V_2 -> V_31 ) + V_39 , V_40 ) ;
F_18 ( & V_2 -> V_44 ) ;
return V_40 ;
}
static T_1 F_25 ( struct V_33 * V_34 ,
struct V_35 * V_36 , struct V_37 * V_38 , char * V_21 ,
T_2 V_39 , T_3 V_40 )
{
struct V_41 * V_42 =
F_14 ( V_36 , struct V_41 , V_36 ) -> V_43 -> V_43 ;
struct V_1 * V_2 = F_15 ( F_16 ( V_42 ) ) ;
struct V_8 * V_9 = F_21 ( F_22 ( V_42 ) ) ;
int V_23 = 0 ;
int V_48 ;
struct V_50 V_51 ;
if ( V_39 != 0 || V_40 != sizeof( struct V_27 ) )
return - V_17 ;
F_17 ( & V_2 -> V_44 ) ;
V_48 = memcmp ( V_21 , & V_2 -> V_31 , sizeof( struct V_27 ) ) ;
if ( V_48 ) {
V_23 = F_12 ( V_9 ,
(struct V_27 const * ) V_21 ) ;
if ( V_23 ) {
F_18 ( & V_2 -> V_44 ) ;
return V_23 ;
}
memcpy ( & V_2 -> V_31 , V_21 ,
sizeof( struct V_27 ) ) ;
F_1 ( V_2 , V_2 -> V_31 . V_52 ) ;
V_51 . type = V_53 ;
V_51 . V_10 = V_2 -> V_31 . V_52 + 1 ;
V_51 . V_54 = 0 ;
F_26 ( V_2 -> V_55 ,
( V_56 const * ) & V_51 ) ;
}
F_18 ( & V_2 -> V_44 ) ;
return sizeof( struct V_27 ) ;
}
static T_1 F_27 ( struct V_41 * V_42 ,
struct V_57 * V_38 , char * V_21 )
{
struct V_1 * V_2 =
F_15 ( F_16 ( V_42 -> V_43 -> V_43 ) ) ;
return snprintf ( V_21 , V_58 , L_1 , V_2 -> V_5 ) ;
}
static T_1 F_28 ( struct V_41 * V_42 ,
struct V_57 * V_38 , char * V_21 )
{
struct V_1 * V_2 =
F_15 ( F_16 ( V_42 -> V_43 -> V_43 ) ) ;
return snprintf ( V_21 , V_58 , L_1 , V_2 -> V_4 ) ;
}
static T_1 F_29 ( struct V_41 * V_42 ,
struct V_57 * V_38 , char * V_21 )
{
struct V_1 * V_2 =
F_15 ( F_16 ( V_42 -> V_43 -> V_43 ) ) ;
return snprintf ( V_21 , V_58 , L_1 , V_2 -> V_59 ) ;
}
static T_1 F_30 ( struct V_41 * V_42 ,
struct V_57 * V_38 , char * V_21 )
{
struct V_1 * V_2 =
F_15 ( F_16 ( V_42 -> V_43 -> V_43 ) ) ;
return snprintf ( V_21 , V_58 , L_1 , V_2 -> V_31 . V_52 ) ;
}
static int F_31 ( struct V_8 * V_9 ,
struct V_1 * V_2 )
{
struct V_29 V_60 ;
int V_23 , V_61 ;
F_32 ( & V_2 -> V_44 ) ;
V_23 = F_8 ( V_9 , & V_60 ) ;
if ( V_23 )
return V_23 ;
V_2 -> V_59 = V_60 . V_59 ;
V_23 = F_7 ( V_9 , & V_2 -> V_31 ) ;
if ( V_23 )
return V_23 ;
for ( V_61 = 0 ; V_61 < 5 ; ++ V_61 ) {
V_23 = F_4 ( V_9 ,
& V_2 -> V_6 [ V_61 ] , V_61 ) ;
if ( V_23 )
return V_23 ;
V_23 = F_6 ( V_9 ,
& V_2 -> V_47 [ V_61 ] , V_61 ) ;
if ( V_23 )
return V_23 ;
}
F_1 ( V_2 , V_2 -> V_31 . V_52 ) ;
return 0 ;
}
static int F_33 ( struct V_62 * V_63 )
{
struct V_64 * V_65 = F_22 ( V_63 -> V_42 . V_43 ) ;
struct V_8 * V_9 = F_21 ( V_65 ) ;
struct V_1 * V_2 ;
int V_23 ;
if ( V_65 -> V_66 -> V_67 . V_68
== V_69 ) {
V_2 = F_34 ( sizeof( * V_2 ) , V_70 ) ;
if ( ! V_2 ) {
F_35 ( V_63 , L_2 ) ;
return - V_71 ;
}
F_36 ( V_63 , V_2 ) ;
V_23 = F_31 ( V_9 , V_2 ) ;
if ( V_23 ) {
F_35 ( V_63 , L_3 ) ;
goto V_72;
}
V_23 = F_37 ( V_73 , V_63 ,
sizeof( struct V_50 ) ) ;
if ( V_23 < 0 ) {
F_35 ( V_63 , L_4 ) ;
} else {
V_2 -> V_55 = V_23 ;
V_2 -> V_74 = 1 ;
}
} else {
F_36 ( V_63 , NULL ) ;
}
return 0 ;
V_72:
F_38 ( V_2 ) ;
return V_23 ;
}
static void F_39 ( struct V_62 * V_63 )
{
struct V_64 * V_65 = F_22 ( V_63 -> V_42 . V_43 ) ;
struct V_1 * V_2 ;
if ( V_65 -> V_66 -> V_67 . V_68
== V_69 ) {
V_2 = F_15 ( V_63 ) ;
if ( V_2 -> V_74 )
F_40 ( V_2 -> V_55 ) ;
F_38 ( F_15 ( V_63 ) ) ;
}
}
static int F_41 ( struct V_62 * V_63 , const struct V_75 * V_76 )
{
int V_23 ;
V_23 = F_42 ( V_63 ) ;
if ( V_23 ) {
F_35 ( V_63 , L_5 ) ;
goto exit;
}
V_23 = F_43 ( V_63 , V_77 ) ;
if ( V_23 ) {
F_35 ( V_63 , L_6 ) ;
goto exit;
}
V_23 = F_33 ( V_63 ) ;
if ( V_23 ) {
F_35 ( V_63 , L_7 ) ;
goto V_78;
}
return 0 ;
V_78:
F_44 ( V_63 ) ;
exit:
return V_23 ;
}
static void F_45 ( struct V_62 * V_63 )
{
F_39 ( V_63 ) ;
F_44 ( V_63 ) ;
}
static void F_46 ( struct V_1 * V_2 ,
T_4 const * V_79 )
{
struct V_80 const * V_81 ;
switch ( V_79 [ 0 ] ) {
case V_82 :
V_81 = (struct V_80 const * ) V_79 ;
switch ( V_81 -> type ) {
case V_53 :
F_1 ( V_2 , V_81 -> V_83 - 1 ) ;
break;
case V_84 :
V_2 -> V_5 = V_81 -> V_83 ;
break;
}
break;
}
}
static void F_47 ( struct V_1 const * V_2 ,
T_4 const * V_79 )
{
struct V_50 V_51 ;
struct V_80 const * V_81 ;
if ( V_79 [ 0 ] != V_82 )
return;
V_81 = (struct V_80 const * ) V_79 ;
switch ( V_81 -> type ) {
case V_53 :
case V_84 :
V_51 . type = V_81 -> type ;
V_51 . V_10 = V_81 -> V_83 ;
V_51 . V_54 = 0 ;
F_26 ( V_2 -> V_55 ,
( V_56 const * ) & V_51 ) ;
break;
case V_85 :
case V_86 :
case V_87 :
if ( V_81 -> V_88 == V_89 ) {
V_51 . type = V_81 -> type ;
V_51 . V_54 = V_81 -> V_83 ;
V_51 . V_10 = V_2 -> V_4 + 1 ;
F_26 ( V_2 -> V_55 ,
( V_56 const * ) & V_51 ) ;
}
break;
}
}
static int F_48 ( struct V_62 * V_63 , struct V_90 * V_91 ,
T_4 * V_79 , int V_92 )
{
struct V_64 * V_65 = F_22 ( V_63 -> V_42 . V_43 ) ;
struct V_1 * V_2 = F_15 ( V_63 ) ;
if ( V_65 -> V_66 -> V_67 . V_68
!= V_69 )
return 0 ;
if ( V_2 == NULL )
return 0 ;
F_46 ( V_2 , V_79 ) ;
if ( V_2 -> V_74 )
F_47 ( V_2 , V_79 ) ;
return 0 ;
}
static int T_5 F_49 ( void )
{
int V_23 ;
V_73 = F_50 ( V_93 , L_8 ) ;
if ( F_51 ( V_73 ) )
return F_52 ( V_73 ) ;
V_73 -> V_94 = V_95 ;
V_73 -> V_96 = V_97 ;
V_23 = F_53 ( & V_98 ) ;
if ( V_23 )
F_54 ( V_73 ) ;
return V_23 ;
}
static void T_6 F_55 ( void )
{
F_56 ( & V_98 ) ;
F_54 ( V_73 ) ;
}
