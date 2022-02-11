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
struct V_26 * V_27 , T_1 V_25 )
{
int V_17 ;
V_17 = F_5 ( V_14 , V_25 ,
V_20 ) ;
if ( V_17 )
return V_17 ;
return F_7 ( V_14 , V_28 ,
V_27 , V_29 ) ;
}
static int F_8 ( struct V_13 * V_14 ,
struct V_30 * V_27 , int V_25 )
{
int V_17 ;
V_17 = F_5 ( V_14 , V_25 ,
V_21 ) ;
if ( V_17 )
return V_17 ;
return F_7 ( V_14 , V_31 ,
V_27 , V_32 ) ;
}
static int F_9 ( struct V_13 * V_14 )
{
struct V_33 V_27 ;
int V_17 ;
V_17 = F_7 ( V_14 , V_34 ,
& V_27 , sizeof( struct V_33 ) ) ;
return V_17 ? V_17 : V_27 . V_5 ;
}
static int F_10 ( struct V_13 * V_14 ,
int V_35 )
{
struct V_33 V_27 ;
V_27 . V_23 = V_34 ;
V_27 . V_36 = sizeof( struct V_33 ) ;
V_27 . V_5 = V_35 ;
return F_11 ( V_14 ,
V_34 ,
& V_27 , sizeof( struct V_33 ) ) ;
}
static T_2 F_12 ( struct V_37 * V_38 , struct V_39 * V_40 ,
char * V_27 , T_3 V_41 , T_4 V_42 ,
T_4 V_43 , T_1 V_23 )
{
struct V_44 * V_45 = F_13 ( V_40 ) -> V_46 -> V_46 ;
struct V_2 * V_3 = F_14 ( F_15 ( V_45 ) ) ;
struct V_13 * V_14 = F_16 ( F_17 ( V_45 ) ) ;
int V_17 ;
if ( V_41 >= V_43 )
return 0 ;
if ( V_41 != 0 || V_42 != V_43 )
return - V_22 ;
F_18 ( & V_3 -> V_47 ) ;
V_17 = F_7 ( V_14 , V_23 , V_27 , V_43 ) ;
F_19 ( & V_3 -> V_47 ) ;
if ( V_17 )
return V_17 ;
return V_43 ;
}
static T_2 F_20 ( struct V_37 * V_38 , struct V_39 * V_40 ,
void const * V_27 , T_3 V_41 , T_4 V_42 ,
T_4 V_43 , T_1 V_23 )
{
struct V_44 * V_45 = F_13 ( V_40 ) -> V_46 -> V_46 ;
struct V_2 * V_3 = F_14 ( F_15 ( V_45 ) ) ;
struct V_13 * V_14 = F_16 ( F_17 ( V_45 ) ) ;
int V_17 ;
if ( V_41 != 0 || V_42 != V_43 )
return - V_22 ;
F_18 ( & V_3 -> V_47 ) ;
V_17 = F_11 ( V_14 , V_23 ,
V_27 , V_43 ) ;
F_19 ( & V_3 -> V_47 ) ;
if ( V_17 )
return V_17 ;
return V_43 ;
}
static T_2 F_21 ( struct V_37 * V_38 ,
struct V_39 * V_40 , struct V_48 * V_49 , char * V_27 ,
T_3 V_41 , T_4 V_42 )
{
struct V_44 * V_45 = F_13 ( V_40 ) -> V_46 -> V_46 ;
struct V_13 * V_14 = F_16 ( F_17 ( V_45 ) ) ;
T_2 V_17 ;
V_17 = F_5 ( V_14 , * ( T_1 * ) ( V_49 -> V_50 ) ,
V_20 ) ;
if ( V_17 )
return V_17 ;
return F_12 ( V_38 , V_40 , V_27 , V_41 , V_42 ,
V_29 ,
V_28 ) ;
}
static T_2 F_22 ( struct V_37 * V_38 ,
struct V_39 * V_40 , struct V_48 * V_49 , char * V_27 ,
T_3 V_41 , T_4 V_42 )
{
struct V_44 * V_45 = F_13 ( V_40 ) -> V_46 -> V_46 ;
struct V_13 * V_14 = F_16 ( F_17 ( V_45 ) ) ;
T_2 V_17 ;
V_17 = F_5 ( V_14 , * ( T_1 * ) ( V_49 -> V_50 ) ,
V_21 ) ;
if ( V_17 )
return V_17 ;
return F_12 ( V_38 , V_40 , V_27 , V_41 , V_42 ,
V_32 ,
V_31 ) ;
}
static T_2 F_23 ( struct V_44 * V_45 ,
struct V_51 * V_49 , char * V_27 )
{
struct V_2 * V_3 =
F_14 ( F_15 ( V_45 -> V_46 -> V_46 ) ) ;
return snprintf ( V_27 , V_52 , L_1 , V_3 -> V_5 ) ;
}
static T_2 F_24 ( struct V_44 * V_45 ,
struct V_51 * V_49 , char const * V_27 , T_4 V_36 )
{
struct V_2 * V_3 ;
struct V_13 * V_14 ;
unsigned long V_53 ;
int V_17 ;
struct V_54 V_55 ;
V_45 = V_45 -> V_46 -> V_46 ;
V_3 = F_14 ( F_15 ( V_45 ) ) ;
V_14 = F_16 ( F_17 ( V_45 ) ) ;
V_17 = F_25 ( V_27 , 10 , & V_53 ) ;
if ( V_17 )
return V_17 ;
if ( V_53 >= 5 )
return - V_22 ;
F_18 ( & V_3 -> V_47 ) ;
V_17 = F_10 ( V_14 , V_53 ) ;
if ( V_17 ) {
F_19 ( & V_3 -> V_47 ) ;
return V_17 ;
}
F_2 ( V_3 , V_53 ) ;
V_55 . type = V_56 ;
V_55 . V_53 = V_53 + 1 ;
V_55 . V_57 = 0 ;
V_55 . V_58 = V_53 + 1 ;
V_55 . V_59 = 0 ;
F_26 ( V_3 -> V_60 ,
( V_61 const * ) & V_55 ) ;
F_19 ( & V_3 -> V_47 ) ;
return V_36 ;
}
static T_2 F_27 ( struct V_44 * V_45 ,
struct V_51 * V_49 , char * V_27 )
{
struct V_2 * V_3 =
F_14 ( F_15 ( V_45 -> V_46 -> V_46 ) ) ;
return snprintf ( V_27 , V_52 , L_1 , V_3 -> V_6 ) ;
}
static T_2 F_28 ( struct V_44 * V_45 ,
struct V_51 * V_49 , char * V_27 )
{
struct V_2 * V_3 =
F_14 ( F_15 ( V_45 -> V_46 -> V_46 ) ) ;
return snprintf ( V_27 , V_52 , L_1 , V_3 -> V_9 ) ;
}
static T_2 F_29 ( struct V_44 * V_45 ,
struct V_51 * V_49 , char * V_27 )
{
struct V_2 * V_3 =
F_14 ( F_15 ( V_45 -> V_46 -> V_46 ) ) ;
return snprintf ( V_27 , V_52 , L_1 , V_3 -> V_11 ) ;
}
static T_2 F_30 ( struct V_44 * V_45 ,
struct V_51 * V_49 , char * V_27 )
{
struct V_2 * V_3 ;
struct V_13 * V_14 ;
struct V_62 V_63 ;
V_45 = V_45 -> V_46 -> V_46 ;
V_3 = F_14 ( F_15 ( V_45 ) ) ;
V_14 = F_16 ( F_17 ( V_45 ) ) ;
F_18 ( & V_3 -> V_47 ) ;
F_7 ( V_14 , V_64 ,
& V_63 , V_65 ) ;
F_19 ( & V_3 -> V_47 ) ;
return snprintf ( V_27 , V_52 , L_1 , V_63 . V_66 ) ;
}
static int F_31 ( struct V_13 * V_14 ,
struct V_2 * V_3 )
{
int V_17 , V_67 ;
static T_1 V_68 = 70 ;
F_32 ( & V_3 -> V_47 ) ;
for ( V_67 = 0 ; V_67 < 5 ; ++ V_67 ) {
F_33 ( V_68 ) ;
V_17 = F_6 ( V_14 ,
& V_3 -> V_7 [ V_67 ] , V_67 ) ;
if ( V_17 )
return V_17 ;
F_33 ( V_68 ) ;
V_17 = F_8 ( V_14 ,
& V_3 -> V_69 [ V_67 ] , V_67 ) ;
if ( V_17 )
return V_17 ;
}
F_33 ( V_68 ) ;
V_17 = F_9 ( V_14 ) ;
if ( V_17 < 0 )
return V_17 ;
F_2 ( V_3 , V_17 ) ;
return 0 ;
}
static int F_34 ( struct V_70 * V_71 )
{
struct V_72 * V_73 = F_17 ( V_71 -> V_45 . V_46 ) ;
struct V_13 * V_14 = F_16 ( V_73 ) ;
struct V_2 * V_3 ;
int V_17 ;
if ( V_73 -> V_74 -> V_75 . V_76
== V_77 ) {
V_3 = F_35 ( sizeof( * V_3 ) , V_78 ) ;
if ( ! V_3 ) {
F_36 ( V_71 , L_2 ) ;
return - V_79 ;
}
F_37 ( V_71 , V_3 ) ;
V_17 = F_31 ( V_14 , V_3 ) ;
if ( V_17 ) {
F_36 ( V_71 , L_3 ) ;
goto V_80;
}
V_17 = F_38 ( V_81 , V_71 ,
sizeof( struct V_54 ) ) ;
if ( V_17 < 0 ) {
F_36 ( V_71 , L_4 ) ;
} else {
V_3 -> V_60 = V_17 ;
V_3 -> V_82 = 1 ;
}
} else {
F_37 ( V_71 , NULL ) ;
}
return 0 ;
V_80:
F_39 ( V_3 ) ;
return V_17 ;
}
static void F_40 ( struct V_70 * V_71 )
{
struct V_72 * V_73 = F_17 ( V_71 -> V_45 . V_46 ) ;
struct V_2 * V_3 ;
if ( V_73 -> V_74 -> V_75 . V_76
== V_77 ) {
V_3 = F_14 ( V_71 ) ;
if ( V_3 -> V_82 )
F_41 ( V_3 -> V_60 ) ;
F_39 ( V_3 ) ;
}
}
static int F_42 ( struct V_70 * V_71 ,
const struct V_83 * V_84 )
{
int V_17 ;
V_17 = F_43 ( V_71 ) ;
if ( V_17 ) {
F_36 ( V_71 , L_5 ) ;
goto exit;
}
V_17 = F_44 ( V_71 , V_85 ) ;
if ( V_17 ) {
F_36 ( V_71 , L_6 ) ;
goto exit;
}
V_17 = F_34 ( V_71 ) ;
if ( V_17 ) {
F_36 ( V_71 , L_7 ) ;
goto V_86;
}
return 0 ;
V_86:
F_45 ( V_71 ) ;
exit:
return V_17 ;
}
static void F_46 ( struct V_70 * V_71 )
{
F_40 ( V_71 ) ;
F_45 ( V_71 ) ;
}
static void F_47 ( struct V_2 * V_3 ,
T_5 const * V_87 )
{
struct V_88 const * V_89 ;
if ( V_87 [ 0 ] != V_90 )
return;
V_89 = (struct V_88 const * ) V_87 ;
switch ( V_89 -> type ) {
case V_56 :
F_2 ( V_3 , V_89 -> V_58 - 1 ) ;
break;
case V_91 :
V_3 -> V_6 = F_1 ( V_89 -> V_58 ) ;
break;
case V_92 :
V_3 -> V_9 = V_89 -> V_58 ;
V_3 -> V_11 = V_89 -> V_59 ;
break;
default:
break;
}
}
static void F_48 ( struct V_2 const * V_3 ,
T_5 const * V_87 )
{
struct V_54 V_55 ;
struct V_88 const * V_89 ;
if ( V_87 [ 0 ] != V_90 )
return;
V_89 = (struct V_88 const * ) V_87 ;
if ( V_89 -> type == V_93 )
return;
V_55 . type = V_89 -> type ;
V_55 . V_53 = V_3 -> V_5 + 1 ;
if ( V_55 . type == V_94 ||
V_55 . type == V_95 ||
V_55 . type == V_96 ||
V_55 . type == V_97 )
V_55 . V_57 = V_89 -> V_58 ;
else
V_55 . V_57 = 0 ;
if ( V_55 . type == V_91 )
V_55 . V_58 = F_1 ( V_89 -> V_58 ) ;
else
V_55 . V_58 = V_89 -> V_58 ;
V_55 . V_59 = V_89 -> V_59 ;
F_26 ( V_3 -> V_60 ,
( V_61 const * ) & V_55 ) ;
}
static int F_49 ( struct V_70 * V_71 ,
struct V_98 * V_99 , T_5 * V_87 , int V_36 )
{
struct V_72 * V_73 = F_17 ( V_71 -> V_45 . V_46 ) ;
struct V_2 * V_3 = F_14 ( V_71 ) ;
if ( V_73 -> V_74 -> V_75 . V_76
!= V_77 )
return 0 ;
if ( V_3 == NULL )
return 0 ;
F_47 ( V_3 , V_87 ) ;
if ( V_3 -> V_82 )
F_48 ( V_3 , V_87 ) ;
return 0 ;
}
static int T_6 F_50 ( void )
{
int V_17 ;
V_81 = F_51 ( V_100 , L_8 ) ;
if ( F_52 ( V_81 ) )
return F_53 ( V_81 ) ;
V_81 -> V_101 = V_102 ;
V_17 = F_54 ( & V_103 ) ;
if ( V_17 )
F_55 ( V_81 ) ;
return V_17 ;
}
static void T_7 F_56 ( void )
{
F_57 ( & V_103 ) ;
F_55 ( V_81 ) ;
}
