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
if ( V_42 != 0 || V_43 != sizeof( struct V_29 ) )
return - V_17 ;
F_20 ( & V_2 -> V_47 ) ;
V_50 = memcmp ( V_24 , & V_2 -> V_34 , sizeof( struct V_29 ) ) ;
if ( V_50 ) {
V_20 = F_15 ( V_9 ,
(struct V_29 const * ) V_24 ) ;
if ( ! V_20 )
memcpy ( & V_2 -> V_34 , V_24 ,
sizeof( struct V_29 ) ) ;
}
F_21 ( & V_2 -> V_47 ) ;
if ( V_20 )
return V_20 ;
F_1 ( V_2 , V_2 -> V_34 . V_52 ) ;
return sizeof( struct V_29 ) ;
}
static T_2 F_29 ( struct V_44 * V_45 ,
struct V_53 * V_41 , char * V_24 )
{
struct V_1 * V_2 =
F_18 ( F_19 ( V_45 -> V_46 -> V_46 ) ) ;
return snprintf ( V_24 , V_54 , L_2 , V_2 -> V_5 ) ;
}
static T_2 F_30 ( struct V_44 * V_45 ,
struct V_53 * V_41 , char * V_24 )
{
struct V_1 * V_2 =
F_18 ( F_19 ( V_45 -> V_46 -> V_46 ) ) ;
return snprintf ( V_24 , V_54 , L_2 , V_2 -> V_4 ) ;
}
static T_2 F_31 ( struct V_44 * V_45 ,
struct V_53 * V_41 , char * V_24 )
{
struct V_1 * V_2 =
F_18 ( F_19 ( V_45 -> V_46 -> V_46 ) ) ;
return snprintf ( V_24 , V_54 , L_2 , V_2 -> V_55 ) ;
}
static T_2 F_32 ( struct V_44 * V_45 ,
struct V_53 * V_41 , char * V_24 )
{
struct V_1 * V_2 =
F_18 ( F_19 ( V_45 -> V_46 -> V_46 ) ) ;
return snprintf ( V_24 , V_54 , L_2 , V_2 -> V_34 . V_52 ) ;
}
static int F_33 ( struct V_8 * V_9 ,
struct V_1 * V_2 )
{
struct V_31 V_56 ;
int V_20 , V_57 ;
F_34 ( & V_2 -> V_47 ) ;
V_20 = F_11 ( V_9 , & V_56 ) ;
if ( V_20 )
return V_20 ;
V_2 -> V_55 = V_56 . V_55 ;
V_20 = F_10 ( V_9 , & V_2 -> V_34 ) ;
if ( V_20 )
return V_20 ;
for ( V_57 = 0 ; V_57 < 5 ; ++ V_57 ) {
V_20 = F_8 ( V_9 ,
& V_2 -> V_6 [ V_57 ] , V_57 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_9 ( V_9 ,
& V_2 -> V_49 [ V_57 ] , V_57 ) ;
if ( V_20 )
return V_20 ;
}
F_1 ( V_2 , V_2 -> V_34 . V_52 ) ;
return 0 ;
}
static int F_35 ( struct V_58 * V_59 )
{
struct V_60 * V_61 = F_25 ( V_59 -> V_45 . V_46 ) ;
struct V_8 * V_9 = F_24 ( V_61 ) ;
struct V_1 * V_2 ;
int V_20 ;
if ( V_61 -> V_62 -> V_63 . V_64
== V_65 ) {
V_2 = F_36 ( sizeof( * V_2 ) , V_66 ) ;
if ( ! V_2 ) {
F_7 ( V_59 , L_3 ) ;
return - V_67 ;
}
F_37 ( V_59 , V_2 ) ;
V_20 = F_33 ( V_9 , V_2 ) ;
if ( V_20 ) {
F_7 ( V_59 , L_4 ) ;
goto V_68;
}
V_20 = F_38 ( V_69 , V_59 ,
sizeof( struct V_70 ) ) ;
if ( V_20 < 0 ) {
F_7 ( V_59 , L_5 ) ;
} else {
V_2 -> V_71 = V_20 ;
V_2 -> V_72 = 1 ;
}
} else {
F_37 ( V_59 , NULL ) ;
}
return 0 ;
V_68:
F_39 ( V_2 ) ;
return V_20 ;
}
static void F_40 ( struct V_58 * V_59 )
{
struct V_60 * V_61 = F_25 ( V_59 -> V_45 . V_46 ) ;
struct V_1 * V_2 ;
if ( V_61 -> V_62 -> V_63 . V_64
== V_65 ) {
V_2 = F_18 ( V_59 ) ;
if ( V_2 -> V_72 )
F_41 ( V_2 -> V_71 ) ;
F_39 ( F_18 ( V_59 ) ) ;
}
}
static int F_42 ( struct V_58 * V_59 , const struct V_73 * V_74 )
{
int V_20 ;
V_20 = F_43 ( V_59 ) ;
if ( V_20 ) {
F_7 ( V_59 , L_6 ) ;
goto exit;
}
V_20 = F_44 ( V_59 , V_75 ) ;
if ( V_20 ) {
F_7 ( V_59 , L_7 ) ;
goto exit;
}
V_20 = F_35 ( V_59 ) ;
if ( V_20 ) {
F_7 ( V_59 , L_8 ) ;
goto V_76;
}
return 0 ;
V_76:
F_45 ( V_59 ) ;
exit:
return V_20 ;
}
static void F_46 ( struct V_58 * V_59 )
{
F_40 ( V_59 ) ;
F_45 ( V_59 ) ;
}
static void F_47 ( struct V_1 * V_2 ,
T_5 const * V_77 )
{
struct V_78 const * V_79 ;
switch ( V_77 [ 0 ] ) {
case V_80 :
V_79 = (struct V_78 const * ) V_77 ;
switch ( V_79 -> type ) {
case V_81 :
F_1 ( V_2 , V_79 -> V_82 - 1 ) ;
break;
case V_83 :
V_2 -> V_5 = V_79 -> V_82 ;
break;
}
break;
}
}
static void F_48 ( struct V_1 const * V_2 ,
T_5 const * V_77 )
{
struct V_70 V_84 ;
struct V_78 const * V_79 ;
if ( V_77 [ 0 ] != V_80 )
return;
V_79 = (struct V_78 const * ) V_77 ;
switch ( V_79 -> type ) {
case V_81 :
case V_83 :
V_84 . type = V_79 -> type ;
V_84 . V_10 = V_79 -> V_82 ;
V_84 . V_85 = 0 ;
F_49 ( V_2 -> V_71 ,
( V_86 const * ) & V_84 ) ;
break;
case V_87 :
case V_88 :
case V_89 :
if ( V_79 -> V_90 == V_91 ) {
V_84 . type = V_79 -> type ;
V_84 . V_85 = V_79 -> V_82 ;
V_84 . V_10 = V_2 -> V_4 + 1 ;
F_49 ( V_2 -> V_71 ,
( V_86 const * ) & V_84 ) ;
}
break;
}
}
static int F_50 ( struct V_58 * V_59 , struct V_92 * V_93 ,
T_5 * V_77 , int V_33 )
{
struct V_60 * V_61 = F_25 ( V_59 -> V_45 . V_46 ) ;
struct V_1 * V_2 = F_18 ( V_59 ) ;
if ( V_61 -> V_62 -> V_63 . V_64
!= V_65 )
return 0 ;
if ( V_2 == NULL )
return 0 ;
F_47 ( V_2 , V_77 ) ;
if ( V_2 -> V_72 )
F_48 ( V_2 , V_77 ) ;
return 0 ;
}
static int T_6 F_51 ( void )
{
int V_20 ;
V_69 = F_52 ( V_94 , L_9 ) ;
if ( F_53 ( V_69 ) )
return F_54 ( V_69 ) ;
V_69 -> V_95 = V_96 ;
V_69 -> V_97 = V_98 ;
V_20 = F_55 ( & V_99 ) ;
if ( V_20 )
F_56 ( V_69 ) ;
return V_20 ;
}
static void T_7 F_57 ( void )
{
F_58 ( & V_99 ) ;
F_56 ( V_69 ) ;
}
