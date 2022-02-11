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
return F_3 ( V_6 ,
V_16 ,
& V_11 , sizeof( struct V_10 ) ) ;
}
static int F_4 ( struct V_5 * V_6 ,
struct V_17 * V_18 )
{
return F_5 ( V_6 , V_19 ,
V_18 , sizeof( struct V_17 ) ) ;
}
static int F_6 ( struct V_5 * V_6 ,
struct V_20 * V_18 , T_1 V_21 )
{
int V_22 ;
V_22 = F_2 ( V_6 , V_21 ,
V_12 ) ;
if ( V_22 )
return V_22 ;
return F_5 ( V_6 , V_23 ,
V_18 , sizeof( struct V_20 ) ) ;
}
static int F_7 ( struct V_5 * V_6 ,
struct V_20 const * V_24 )
{
return F_3 ( V_6 ,
V_23 ,
V_24 , sizeof( struct V_20 ) ) ;
}
static int F_8 ( struct V_5 * V_6 ,
struct V_25 * V_18 , int V_21 )
{
int V_22 ;
V_22 = F_2 ( V_6 , V_21 ,
V_13 ) ;
if ( V_22 )
return V_22 ;
return F_5 ( V_6 , V_26 ,
V_18 , sizeof( struct V_25 ) ) ;
}
static int F_9 ( struct V_5 * V_6 ,
struct V_25 const * V_27 )
{
return F_3 ( V_6 ,
V_26 ,
V_27 , sizeof( struct V_25 ) ) ;
}
static int F_10 ( struct V_5 * V_6 )
{
struct V_28 V_18 ;
int V_22 ;
V_22 = F_5 ( V_6 , V_29 ,
& V_18 , sizeof( struct V_28 ) ) ;
return V_22 ? V_22 : V_18 . V_4 ;
}
static int F_11 ( struct V_5 * V_6 ,
int V_3 )
{
struct V_28 V_18 ;
V_18 . V_15 = V_29 ;
V_18 . V_30 = sizeof( struct V_28 ) ;
V_18 . V_4 = V_3 ;
return F_3 ( V_6 ,
V_29 ,
& V_18 , sizeof( struct V_28 ) ) ;
}
static T_2 F_12 ( struct V_31 * V_32 , struct V_33 * V_34 ,
char * V_18 , T_3 V_35 , T_4 V_36 ,
T_4 V_37 , T_1 V_15 )
{
struct V_38 * V_39 =
F_13 ( V_34 , struct V_38 , V_34 ) -> V_40 -> V_40 ;
struct V_1 * V_2 = F_14 ( F_15 ( V_39 ) ) ;
struct V_5 * V_6 = F_16 ( F_17 ( V_39 ) ) ;
int V_22 ;
if ( V_35 >= V_37 )
return 0 ;
if ( V_35 != 0 || V_36 != V_37 )
return - V_14 ;
F_18 ( & V_2 -> V_41 ) ;
V_22 = F_5 ( V_6 , V_15 , V_18 , V_37 ) ;
F_19 ( & V_2 -> V_41 ) ;
if ( V_22 )
return V_22 ;
return V_37 ;
}
static T_2 F_20 ( struct V_31 * V_32 , struct V_33 * V_34 ,
void const * V_18 , T_3 V_35 , T_4 V_36 ,
T_4 V_37 , T_1 V_15 )
{
struct V_38 * V_39 =
F_13 ( V_34 , struct V_38 , V_34 ) -> V_40 -> V_40 ;
struct V_1 * V_2 = F_14 ( F_15 ( V_39 ) ) ;
struct V_5 * V_6 = F_16 ( F_17 ( V_39 ) ) ;
int V_22 ;
if ( V_35 != 0 || V_36 != V_37 )
return - V_14 ;
F_18 ( & V_2 -> V_41 ) ;
V_22 = F_3 ( V_6 , V_15 ,
V_18 , V_37 ) ;
F_19 ( & V_2 -> V_41 ) ;
if ( V_22 )
return V_22 ;
return V_37 ;
}
static T_2 F_21 ( struct V_31 * V_32 ,
struct V_33 * V_34 , struct V_42 * V_43 , char * V_18 ,
T_3 V_35 , T_4 V_36 )
{
return F_20 ( V_32 , V_34 , V_18 , V_35 , V_36 ,
sizeof( struct V_44 ) , V_45 ) ;
}
static T_2 F_22 ( struct V_31 * V_32 ,
struct V_33 * V_34 , struct V_42 * V_43 , char * V_18 ,
T_3 V_35 , T_4 V_36 )
{
return F_20 ( V_32 , V_34 , V_18 , V_35 , V_36 ,
sizeof( struct V_46 ) , V_47 ) ;
}
static T_2 F_23 ( struct V_31 * V_32 ,
struct V_33 * V_34 , struct V_42 * V_43 , char * V_18 ,
T_3 V_35 , T_4 V_36 )
{
return F_12 ( V_32 , V_34 , V_18 , V_35 , V_36 ,
sizeof( struct V_48 ) , V_49 ) ;
}
static T_2 F_24 ( struct V_31 * V_32 ,
struct V_33 * V_34 , struct V_42 * V_43 , char * V_18 ,
T_3 V_35 , T_4 V_36 )
{
return F_20 ( V_32 , V_34 , V_18 , V_35 , V_36 ,
sizeof( struct V_48 ) , V_49 ) ;
}
static T_2 F_25 ( struct V_31 * V_32 ,
struct V_33 * V_34 , struct V_42 * V_43 , char * V_18 ,
T_3 V_35 , T_4 V_36 )
{
return F_20 ( V_32 , V_34 , V_18 , V_35 , V_36 ,
sizeof( struct V_50 ) , V_51 ) ;
}
static T_2 F_26 ( struct V_31 * V_32 ,
struct V_33 * V_34 , struct V_42 * V_43 , char * V_18 ,
T_3 V_35 , T_4 V_36 )
{
return F_12 ( V_32 , V_34 , V_18 , V_35 , V_36 ,
sizeof( struct V_52 ) , V_51 ) ;
}
static T_2 F_27 ( struct V_31 * V_32 ,
struct V_33 * V_34 , struct V_42 * V_43 , char * V_18 ,
T_3 V_35 , T_4 V_36 )
{
struct V_38 * V_39 =
F_13 ( V_34 , struct V_38 , V_34 ) -> V_40 -> V_40 ;
struct V_1 * V_2 = F_14 ( F_15 ( V_39 ) ) ;
if ( V_35 >= sizeof( struct V_20 ) )
return 0 ;
if ( V_35 + V_36 > sizeof( struct V_20 ) )
V_36 = sizeof( struct V_20 ) - V_35 ;
F_18 ( & V_2 -> V_41 ) ;
memcpy ( V_18 , ( ( char const * ) & V_2 -> V_53 [ * ( T_1 * ) ( V_43 -> V_54 ) ] ) + V_35 ,
V_36 ) ;
F_19 ( & V_2 -> V_41 ) ;
return V_36 ;
}
static T_2 F_28 ( struct V_31 * V_32 ,
struct V_33 * V_34 , struct V_42 * V_43 , char * V_18 ,
T_3 V_35 , T_4 V_36 )
{
struct V_38 * V_39 =
F_13 ( V_34 , struct V_38 , V_34 ) -> V_40 -> V_40 ;
struct V_1 * V_2 = F_14 ( F_15 ( V_39 ) ) ;
struct V_5 * V_6 = F_16 ( F_17 ( V_39 ) ) ;
int V_22 = 0 ;
int V_55 ;
int V_56 ;
struct V_20 * V_53 ;
if ( V_35 != 0 || V_36 != sizeof( struct V_20 ) )
return - V_14 ;
V_56 = ( (struct V_20 const * ) V_18 ) -> V_21 ;
V_53 = & V_2 -> V_53 [ V_56 ] ;
F_18 ( & V_2 -> V_41 ) ;
V_55 = memcmp ( V_18 , V_53 ,
sizeof( struct V_20 ) ) ;
if ( V_55 ) {
V_22 = F_7 ( V_6 ,
(struct V_20 const * ) V_18 ) ;
if ( ! V_22 )
memcpy ( V_53 , V_18 ,
sizeof( struct V_20 ) ) ;
}
F_19 ( & V_2 -> V_41 ) ;
if ( V_22 )
return V_22 ;
return sizeof( struct V_20 ) ;
}
static T_2 F_29 ( struct V_31 * V_32 ,
struct V_33 * V_34 , struct V_42 * V_43 , char * V_18 ,
T_3 V_35 , T_4 V_36 )
{
struct V_38 * V_39 =
F_13 ( V_34 , struct V_38 , V_34 ) -> V_40 -> V_40 ;
struct V_1 * V_2 = F_14 ( F_15 ( V_39 ) ) ;
if ( V_35 >= sizeof( struct V_25 ) )
return 0 ;
if ( V_35 + V_36 > sizeof( struct V_25 ) )
V_36 = sizeof( struct V_25 ) - V_35 ;
F_18 ( & V_2 -> V_41 ) ;
memcpy ( V_18 , ( ( char const * ) & V_2 -> V_57 [ * ( T_1 * ) ( V_43 -> V_54 ) ] ) + V_35 ,
V_36 ) ;
F_19 ( & V_2 -> V_41 ) ;
return V_36 ;
}
static T_2 F_30 ( struct V_31 * V_32 ,
struct V_33 * V_34 , struct V_42 * V_43 , char * V_18 ,
T_3 V_35 , T_4 V_36 )
{
struct V_38 * V_39 =
F_13 ( V_34 , struct V_38 , V_34 ) -> V_40 -> V_40 ;
struct V_1 * V_2 = F_14 ( F_15 ( V_39 ) ) ;
struct V_5 * V_6 = F_16 ( F_17 ( V_39 ) ) ;
int V_22 = 0 ;
int V_55 ;
T_1 V_56 ;
struct V_25 * V_57 ;
if ( V_35 != 0 || V_36 != sizeof( struct V_25 ) )
return - V_14 ;
V_56 = ( (struct V_25 const * ) V_18 ) -> V_21 ;
V_57 = & V_2 -> V_57 [ V_56 ] ;
F_18 ( & V_2 -> V_41 ) ;
V_55 = memcmp ( V_18 , V_57 ,
sizeof( struct V_25 ) ) ;
if ( V_55 ) {
V_22 = F_9 ( V_6 ,
(struct V_25 const * ) V_18 ) ;
if ( ! V_22 )
memcpy ( V_57 , V_18 ,
sizeof( struct V_25 ) ) ;
}
F_19 ( & V_2 -> V_41 ) ;
if ( V_22 )
return V_22 ;
return sizeof( struct V_25 ) ;
}
static T_2 F_31 ( struct V_38 * V_39 ,
struct V_58 * V_43 , char * V_18 )
{
struct V_1 * V_2 =
F_14 ( F_15 ( V_39 -> V_40 -> V_40 ) ) ;
return snprintf ( V_18 , V_59 , L_1 , V_2 -> V_4 ) ;
}
static T_2 F_32 ( struct V_38 * V_39 ,
struct V_58 * V_43 , char const * V_18 , T_4 V_30 )
{
struct V_1 * V_2 ;
struct V_5 * V_6 ;
unsigned long V_60 ;
int V_22 ;
struct V_61 V_62 ;
V_39 = V_39 -> V_40 -> V_40 ;
V_2 = F_14 ( F_15 ( V_39 ) ) ;
V_6 = F_16 ( F_17 ( V_39 ) ) ;
V_22 = F_33 ( V_18 , 10 , & V_60 ) ;
if ( V_22 )
return V_22 ;
if ( V_60 > 4 )
return - V_14 ;
F_18 ( & V_2 -> V_41 ) ;
V_22 = F_11 ( V_6 , V_60 ) ;
if ( V_22 ) {
F_19 ( & V_2 -> V_41 ) ;
return V_22 ;
}
F_1 ( V_2 , V_60 ) ;
V_62 . type = V_63 ;
V_62 . V_64 = V_60 + 1 ;
V_62 . V_65 = 0 ;
V_62 . V_60 = V_60 + 1 ;
F_34 ( V_2 -> V_66 ,
( V_67 const * ) & V_62 ) ;
F_19 ( & V_2 -> V_41 ) ;
return V_30 ;
}
static T_2 F_35 ( struct V_38 * V_39 ,
struct V_58 * V_43 , char * V_18 )
{
struct V_1 * V_2 =
F_14 ( F_15 ( V_39 -> V_40 -> V_40 ) ) ;
return snprintf ( V_18 , V_59 , L_1 , V_2 -> V_68 . V_69 ) ;
}
static int F_36 ( struct V_5 * V_6 ,
struct V_1 * V_2 )
{
int V_22 , V_70 ;
static T_1 V_71 = 200 ;
F_37 ( & V_2 -> V_41 ) ;
V_22 = F_4 ( V_6 , & V_2 -> V_68 ) ;
if ( V_22 )
return V_22 ;
for ( V_70 = 0 ; V_70 < 5 ; ++ V_70 ) {
F_38 ( V_71 ) ;
V_22 = F_6 ( V_6 ,
& V_2 -> V_53 [ V_70 ] , V_70 ) ;
if ( V_22 )
return V_22 ;
F_38 ( V_71 ) ;
V_22 = F_8 ( V_6 ,
& V_2 -> V_57 [ V_70 ] , V_70 ) ;
if ( V_22 )
return V_22 ;
}
F_38 ( V_71 ) ;
V_22 = F_10 ( V_6 ) ;
if ( V_22 < 0 )
return V_22 ;
F_1 ( V_2 , V_22 ) ;
return 0 ;
}
static int F_39 ( struct V_72 * V_73 )
{
struct V_74 * V_75 = F_17 ( V_73 -> V_39 . V_40 ) ;
struct V_5 * V_6 = F_16 ( V_75 ) ;
struct V_1 * V_2 ;
int V_22 ;
if ( V_75 -> V_76 -> V_77 . V_78
== V_79 ) {
V_2 = F_40 ( sizeof( * V_2 ) , V_80 ) ;
if ( ! V_2 ) {
F_41 ( V_73 , L_2 ) ;
return - V_81 ;
}
F_42 ( V_73 , V_2 ) ;
V_22 = F_36 ( V_6 , V_2 ) ;
if ( V_22 ) {
F_41 ( V_73 , L_3 ) ;
goto V_82;
}
V_22 = F_43 ( V_83 , V_73 ,
sizeof( struct V_61 ) ) ;
if ( V_22 < 0 ) {
F_41 ( V_73 , L_4 ) ;
} else {
V_2 -> V_66 = V_22 ;
V_2 -> V_84 = 1 ;
}
} else {
F_42 ( V_73 , NULL ) ;
}
return 0 ;
V_82:
F_44 ( V_2 ) ;
return V_22 ;
}
static void F_45 ( struct V_72 * V_73 )
{
struct V_74 * V_75 = F_17 ( V_73 -> V_39 . V_40 ) ;
struct V_1 * V_2 ;
if ( V_75 -> V_76 -> V_77 . V_78
== V_79 ) {
V_2 = F_14 ( V_73 ) ;
if ( V_2 -> V_84 )
F_46 ( V_2 -> V_66 ) ;
F_44 ( V_2 ) ;
}
}
static int F_47 ( struct V_72 * V_73 ,
const struct V_85 * V_86 )
{
int V_22 ;
V_22 = F_48 ( V_73 ) ;
if ( V_22 ) {
F_41 ( V_73 , L_5 ) ;
goto exit;
}
V_22 = F_49 ( V_73 , V_87 ) ;
if ( V_22 ) {
F_41 ( V_73 , L_6 ) ;
goto exit;
}
V_22 = F_39 ( V_73 ) ;
if ( V_22 ) {
F_41 ( V_73 , L_7 ) ;
goto V_88;
}
return 0 ;
V_88:
F_50 ( V_73 ) ;
exit:
return V_22 ;
}
static void F_51 ( struct V_72 * V_73 )
{
F_45 ( V_73 ) ;
F_50 ( V_73 ) ;
}
static void F_52 ( struct V_1 * V_2 ,
T_5 const * V_89 )
{
struct V_90 const * V_91 ;
switch ( V_89 [ 0 ] ) {
case V_92 :
V_91 = (struct V_90 const * ) V_89 ;
switch ( V_91 -> type ) {
case V_63 :
F_1 ( V_2 , V_91 -> V_64 - 1 ) ;
break;
}
break;
}
}
static void F_53 ( struct V_1 const * V_2 ,
T_5 const * V_89 )
{
struct V_61 V_62 ;
struct V_90 const * V_91 ;
if ( V_89 [ 0 ] != V_92 )
return;
V_91 = (struct V_90 const * ) V_89 ;
if ( ( V_91 -> type == V_93 ||
V_91 -> type == V_94 ) &&
V_91 -> V_65 != V_95 )
return;
V_62 . type = V_91 -> type ;
V_62 . V_64 = V_91 -> V_64 ;
V_62 . V_65 = V_91 -> V_65 ;
V_62 . V_60 = V_2 -> V_4 + 1 ;
F_34 ( V_2 -> V_66 ,
( V_67 const * ) & V_62 ) ;
}
static int F_54 ( struct V_72 * V_73 ,
struct V_96 * V_97 , T_5 * V_89 , int V_30 )
{
struct V_74 * V_75 = F_17 ( V_73 -> V_39 . V_40 ) ;
struct V_1 * V_2 = F_14 ( V_73 ) ;
if ( V_75 -> V_76 -> V_77 . V_78
!= V_79 )
return 0 ;
if ( V_2 == NULL )
return 0 ;
F_52 ( V_2 , V_89 ) ;
if ( V_2 -> V_84 )
F_53 ( V_2 , V_89 ) ;
return 0 ;
}
static int T_6 F_55 ( void )
{
int V_22 ;
V_83 = F_56 ( V_98 , L_8 ) ;
if ( F_57 ( V_83 ) )
return F_58 ( V_83 ) ;
V_83 -> V_99 = V_100 ;
V_83 -> V_101 = V_102 ;
V_22 = F_59 ( & V_103 ) ;
if ( V_22 )
F_60 ( V_83 ) ;
return V_22 ;
}
static void T_7 F_61 ( void )
{
F_62 ( & V_103 ) ;
F_60 ( V_83 ) ;
}
