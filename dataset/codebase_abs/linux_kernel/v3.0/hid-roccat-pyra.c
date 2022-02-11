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
return F_3 ( V_9 , V_20 ,
& V_14 , sizeof( struct V_13 ) ) ;
}
static int F_4 ( struct V_8 * V_9 )
{
int V_21 ;
struct V_13 V_14 ;
do {
F_5 ( 10 ) ;
V_21 = F_6 ( V_9 , V_20 ,
& V_14 , sizeof( struct V_13 ) ) ;
} while ( V_21 == - V_22 );
if ( ! V_21 && V_14 . V_18 == V_19 &&
V_14 . V_12 == V_23 &&
V_14 . V_10 == 1 )
return 0 ;
else {
F_7 ( V_9 , L_1 ,
V_14 . V_12 , V_14 . V_10 ) ;
return V_21 ? V_21 : - V_17 ;
}
}
static int F_8 ( struct V_8 * V_9 ,
struct V_24 * V_25 , int V_26 )
{
int V_21 ;
V_21 = F_2 ( V_9 , V_26 ,
V_15 ) ;
if ( V_21 )
return V_21 ;
return F_6 ( V_9 , V_27 ,
V_25 , sizeof( struct V_24 ) ) ;
}
static int F_9 ( struct V_8 * V_9 ,
struct V_28 * V_25 , int V_26 )
{
int V_21 ;
V_21 = F_2 ( V_9 , V_26 ,
V_16 ) ;
if ( V_21 )
return V_21 ;
return F_6 ( V_9 , V_29 ,
V_25 , sizeof( struct V_28 ) ) ;
}
static int F_10 ( struct V_8 * V_9 ,
struct V_30 * V_25 )
{
return F_6 ( V_9 , V_31 ,
V_25 , sizeof( struct V_30 ) ) ;
}
static int F_11 ( struct V_8 * V_9 , struct V_32 * V_25 )
{
return F_6 ( V_9 , V_33 ,
V_25 , sizeof( struct V_32 ) ) ;
}
static int F_12 ( struct V_8 * V_9 , T_1 V_18 ,
void const * V_25 , T_1 V_34 )
{
int V_21 ;
V_21 = F_3 ( V_9 , V_18 , V_25 , V_34 ) ;
if ( V_21 )
return V_21 ;
return F_4 ( V_9 ) ;
}
static int F_13 ( struct V_8 * V_9 ,
struct V_24 const * V_35 )
{
return F_12 ( V_9 , V_27 , V_35 ,
sizeof( struct V_24 ) ) ;
}
static int F_14 ( struct V_8 * V_9 ,
struct V_28 const * V_36 )
{
return F_12 ( V_9 , V_29 , V_36 ,
sizeof( struct V_28 ) ) ;
}
static int F_15 ( struct V_8 * V_9 ,
struct V_30 const * V_35 )
{
int V_21 ;
V_21 = F_3 ( V_9 , V_31 , V_35 ,
sizeof( struct V_30 ) ) ;
if ( V_21 )
return V_21 ;
return F_4 ( V_9 ) ;
}
static T_2 F_16 ( struct V_37 * V_38 ,
struct V_39 * V_40 , struct V_41 * V_42 , char * V_25 ,
T_3 V_43 , T_4 V_44 )
{
struct V_45 * V_46 =
F_17 ( V_40 , struct V_45 , V_40 ) -> V_47 -> V_47 ;
struct V_1 * V_2 = F_18 ( F_19 ( V_46 ) ) ;
if ( V_43 >= sizeof( struct V_24 ) )
return 0 ;
if ( V_43 + V_44 > sizeof( struct V_24 ) )
V_44 = sizeof( struct V_24 ) - V_43 ;
F_20 ( & V_2 -> V_48 ) ;
memcpy ( V_25 , ( ( char const * ) & V_2 -> V_6 [ * ( T_1 * ) ( V_42 -> V_49 ) ] ) + V_43 ,
V_44 ) ;
F_21 ( & V_2 -> V_48 ) ;
return V_44 ;
}
static T_2 F_22 ( struct V_37 * V_38 ,
struct V_39 * V_40 , struct V_41 * V_42 , char * V_25 ,
T_3 V_43 , T_4 V_44 )
{
struct V_45 * V_46 =
F_17 ( V_40 , struct V_45 , V_40 ) -> V_47 -> V_47 ;
struct V_1 * V_2 = F_18 ( F_19 ( V_46 ) ) ;
if ( V_43 >= sizeof( struct V_28 ) )
return 0 ;
if ( V_43 + V_44 > sizeof( struct V_28 ) )
V_44 = sizeof( struct V_28 ) - V_43 ;
F_20 ( & V_2 -> V_48 ) ;
memcpy ( V_25 , ( ( char const * ) & V_2 -> V_50 [ * ( T_1 * ) ( V_42 -> V_49 ) ] ) + V_43 ,
V_44 ) ;
F_21 ( & V_2 -> V_48 ) ;
return V_44 ;
}
static T_2 F_23 ( struct V_37 * V_38 ,
struct V_39 * V_40 , struct V_41 * V_42 , char * V_25 ,
T_3 V_43 , T_4 V_44 )
{
struct V_45 * V_46 =
F_17 ( V_40 , struct V_45 , V_40 ) -> V_47 -> V_47 ;
struct V_1 * V_2 = F_18 ( F_19 ( V_46 ) ) ;
struct V_8 * V_9 = F_24 ( F_25 ( V_46 ) ) ;
int V_21 = 0 ;
int V_51 ;
int V_52 ;
struct V_24 * V_6 ;
if ( V_43 != 0 || V_44 != sizeof( struct V_24 ) )
return - V_17 ;
V_52 = ( (struct V_24 const * ) V_25 ) -> V_26 ;
V_6 = & V_2 -> V_6 [ V_52 ] ;
F_20 ( & V_2 -> V_48 ) ;
V_51 = memcmp ( V_25 , V_6 ,
sizeof( struct V_24 ) ) ;
if ( V_51 ) {
V_21 = F_13 ( V_9 ,
(struct V_24 const * ) V_25 ) ;
if ( ! V_21 )
memcpy ( V_6 , V_25 ,
sizeof( struct V_24 ) ) ;
}
F_21 ( & V_2 -> V_48 ) ;
if ( V_21 )
return V_21 ;
return sizeof( struct V_24 ) ;
}
static T_2 F_26 ( struct V_37 * V_38 ,
struct V_39 * V_40 , struct V_41 * V_42 , char * V_25 ,
T_3 V_43 , T_4 V_44 )
{
struct V_45 * V_46 =
F_17 ( V_40 , struct V_45 , V_40 ) -> V_47 -> V_47 ;
struct V_1 * V_2 = F_18 ( F_19 ( V_46 ) ) ;
struct V_8 * V_9 = F_24 ( F_25 ( V_46 ) ) ;
int V_21 = 0 ;
int V_51 ;
int V_52 ;
struct V_28 * V_50 ;
if ( V_43 != 0 || V_44 != sizeof( struct V_28 ) )
return - V_17 ;
V_52 = ( (struct V_28 const * ) V_25 ) -> V_26 ;
V_50 = & V_2 -> V_50 [ V_52 ] ;
F_20 ( & V_2 -> V_48 ) ;
V_51 = memcmp ( V_25 , V_50 ,
sizeof( struct V_28 ) ) ;
if ( V_51 ) {
V_21 = F_14 ( V_9 ,
(struct V_28 const * ) V_25 ) ;
if ( ! V_21 )
memcpy ( V_50 , V_25 ,
sizeof( struct V_28 ) ) ;
}
F_21 ( & V_2 -> V_48 ) ;
if ( V_21 )
return V_21 ;
return sizeof( struct V_28 ) ;
}
static T_2 F_27 ( struct V_37 * V_38 ,
struct V_39 * V_40 , struct V_41 * V_42 , char * V_25 ,
T_3 V_43 , T_4 V_44 )
{
struct V_45 * V_46 =
F_17 ( V_40 , struct V_45 , V_40 ) -> V_47 -> V_47 ;
struct V_1 * V_2 = F_18 ( F_19 ( V_46 ) ) ;
if ( V_43 >= sizeof( struct V_30 ) )
return 0 ;
if ( V_43 + V_44 > sizeof( struct V_30 ) )
V_44 = sizeof( struct V_30 ) - V_43 ;
F_20 ( & V_2 -> V_48 ) ;
memcpy ( V_25 , ( ( char const * ) & V_2 -> V_35 ) + V_43 , V_44 ) ;
F_21 ( & V_2 -> V_48 ) ;
return V_44 ;
}
static T_2 F_28 ( struct V_37 * V_38 ,
struct V_39 * V_40 , struct V_41 * V_42 , char * V_25 ,
T_3 V_43 , T_4 V_44 )
{
struct V_45 * V_46 =
F_17 ( V_40 , struct V_45 , V_40 ) -> V_47 -> V_47 ;
struct V_1 * V_2 = F_18 ( F_19 ( V_46 ) ) ;
struct V_8 * V_9 = F_24 ( F_25 ( V_46 ) ) ;
int V_21 = 0 ;
int V_51 ;
if ( V_43 != 0 || V_44 != sizeof( struct V_30 ) )
return - V_17 ;
F_20 ( & V_2 -> V_48 ) ;
V_51 = memcmp ( V_25 , & V_2 -> V_35 , sizeof( struct V_30 ) ) ;
if ( V_51 ) {
V_21 = F_15 ( V_9 ,
(struct V_30 const * ) V_25 ) ;
if ( ! V_21 )
memcpy ( & V_2 -> V_35 , V_25 ,
sizeof( struct V_30 ) ) ;
}
F_21 ( & V_2 -> V_48 ) ;
if ( V_21 )
return V_21 ;
F_1 ( V_2 , V_2 -> V_35 . V_53 ) ;
return sizeof( struct V_30 ) ;
}
static T_2 F_29 ( struct V_45 * V_46 ,
struct V_54 * V_42 , char * V_25 )
{
struct V_1 * V_2 =
F_18 ( F_19 ( V_46 -> V_47 -> V_47 ) ) ;
return snprintf ( V_25 , V_55 , L_2 , V_2 -> V_5 ) ;
}
static T_2 F_30 ( struct V_45 * V_46 ,
struct V_54 * V_42 , char * V_25 )
{
struct V_1 * V_2 =
F_18 ( F_19 ( V_46 -> V_47 -> V_47 ) ) ;
return snprintf ( V_25 , V_55 , L_2 , V_2 -> V_4 ) ;
}
static T_2 F_31 ( struct V_45 * V_46 ,
struct V_54 * V_42 , char * V_25 )
{
struct V_1 * V_2 =
F_18 ( F_19 ( V_46 -> V_47 -> V_47 ) ) ;
return snprintf ( V_25 , V_55 , L_2 , V_2 -> V_56 ) ;
}
static T_2 F_32 ( struct V_45 * V_46 ,
struct V_54 * V_42 , char * V_25 )
{
struct V_1 * V_2 =
F_18 ( F_19 ( V_46 -> V_47 -> V_47 ) ) ;
return snprintf ( V_25 , V_55 , L_2 , V_2 -> V_35 . V_53 ) ;
}
static int F_33 ( struct V_8 * V_9 ,
struct V_1 * V_2 )
{
struct V_32 V_57 ;
int V_21 , V_58 ;
F_34 ( & V_2 -> V_48 ) ;
V_21 = F_11 ( V_9 , & V_57 ) ;
if ( V_21 )
return V_21 ;
V_2 -> V_56 = V_57 . V_56 ;
V_21 = F_10 ( V_9 , & V_2 -> V_35 ) ;
if ( V_21 )
return V_21 ;
for ( V_58 = 0 ; V_58 < 5 ; ++ V_58 ) {
V_21 = F_8 ( V_9 ,
& V_2 -> V_6 [ V_58 ] , V_58 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_9 ( V_9 ,
& V_2 -> V_50 [ V_58 ] , V_58 ) ;
if ( V_21 )
return V_21 ;
}
F_1 ( V_2 , V_2 -> V_35 . V_53 ) ;
return 0 ;
}
static int F_35 ( struct V_59 * V_60 )
{
struct V_61 * V_62 = F_25 ( V_60 -> V_46 . V_47 ) ;
struct V_8 * V_9 = F_24 ( V_62 ) ;
struct V_1 * V_2 ;
int V_21 ;
if ( V_62 -> V_63 -> V_64 . V_65
== V_66 ) {
V_2 = F_36 ( sizeof( * V_2 ) , V_67 ) ;
if ( ! V_2 ) {
F_7 ( V_60 , L_3 ) ;
return - V_68 ;
}
F_37 ( V_60 , V_2 ) ;
V_21 = F_33 ( V_9 , V_2 ) ;
if ( V_21 ) {
F_7 ( V_60 , L_4 ) ;
goto V_69;
}
V_21 = F_38 ( V_70 , V_60 ,
sizeof( struct V_71 ) ) ;
if ( V_21 < 0 ) {
F_7 ( V_60 , L_5 ) ;
} else {
V_2 -> V_72 = V_21 ;
V_2 -> V_73 = 1 ;
}
} else {
F_37 ( V_60 , NULL ) ;
}
return 0 ;
V_69:
F_39 ( V_2 ) ;
return V_21 ;
}
static void F_40 ( struct V_59 * V_60 )
{
struct V_61 * V_62 = F_25 ( V_60 -> V_46 . V_47 ) ;
struct V_1 * V_2 ;
if ( V_62 -> V_63 -> V_64 . V_65
== V_66 ) {
V_2 = F_18 ( V_60 ) ;
if ( V_2 -> V_73 )
F_41 ( V_2 -> V_72 ) ;
F_39 ( F_18 ( V_60 ) ) ;
}
}
static int F_42 ( struct V_59 * V_60 , const struct V_74 * V_75 )
{
int V_21 ;
V_21 = F_43 ( V_60 ) ;
if ( V_21 ) {
F_7 ( V_60 , L_6 ) ;
goto exit;
}
V_21 = F_44 ( V_60 , V_76 ) ;
if ( V_21 ) {
F_7 ( V_60 , L_7 ) ;
goto exit;
}
V_21 = F_35 ( V_60 ) ;
if ( V_21 ) {
F_7 ( V_60 , L_8 ) ;
goto V_77;
}
return 0 ;
V_77:
F_45 ( V_60 ) ;
exit:
return V_21 ;
}
static void F_46 ( struct V_59 * V_60 )
{
F_40 ( V_60 ) ;
F_45 ( V_60 ) ;
}
static void F_47 ( struct V_1 * V_2 ,
T_5 const * V_78 )
{
struct V_79 const * V_80 ;
switch ( V_78 [ 0 ] ) {
case V_81 :
V_80 = (struct V_79 const * ) V_78 ;
switch ( V_80 -> type ) {
case V_82 :
F_1 ( V_2 , V_80 -> V_83 - 1 ) ;
break;
case V_84 :
V_2 -> V_5 = V_80 -> V_83 ;
break;
}
break;
}
}
static void F_48 ( struct V_1 const * V_2 ,
T_5 const * V_78 )
{
struct V_71 V_85 ;
struct V_79 const * V_80 ;
if ( V_78 [ 0 ] != V_81 )
return;
V_80 = (struct V_79 const * ) V_78 ;
switch ( V_80 -> type ) {
case V_82 :
case V_84 :
V_85 . type = V_80 -> type ;
V_85 . V_10 = V_80 -> V_83 ;
V_85 . V_86 = 0 ;
F_49 ( V_2 -> V_72 ,
( V_87 const * ) & V_85 ) ;
break;
case V_88 :
case V_89 :
case V_90 :
if ( V_80 -> V_91 == V_92 ) {
V_85 . type = V_80 -> type ;
V_85 . V_86 = V_80 -> V_83 ;
V_85 . V_10 = V_2 -> V_4 + 1 ;
F_49 ( V_2 -> V_72 ,
( V_87 const * ) & V_85 ) ;
}
break;
}
}
static int F_50 ( struct V_59 * V_60 , struct V_93 * V_94 ,
T_5 * V_78 , int V_34 )
{
struct V_61 * V_62 = F_25 ( V_60 -> V_46 . V_47 ) ;
struct V_1 * V_2 = F_18 ( V_60 ) ;
if ( V_62 -> V_63 -> V_64 . V_65
!= V_66 )
return 0 ;
F_47 ( V_2 , V_78 ) ;
if ( V_2 -> V_73 )
F_48 ( V_2 , V_78 ) ;
return 0 ;
}
static int T_6 F_51 ( void )
{
int V_21 ;
V_70 = F_52 ( V_95 , L_9 ) ;
if ( F_53 ( V_70 ) )
return F_54 ( V_70 ) ;
V_70 -> V_96 = V_97 ;
V_70 -> V_98 = V_99 ;
V_21 = F_55 ( & V_100 ) ;
if ( V_21 )
F_56 ( V_70 ) ;
return V_21 ;
}
static void T_7 F_57 ( void )
{
F_58 ( & V_100 ) ;
F_56 ( V_70 ) ;
}
