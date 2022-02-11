static void F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
if ( V_3 >= F_2 ( V_2 -> V_4 ) )
return;
V_2 -> V_5 = V_3 ;
V_2 -> V_6 = V_2 -> V_4 [ V_2 -> V_5 ] . V_7 ;
}
static int F_3 ( struct V_8 * V_9 , int V_10 ,
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
return F_4 ( V_9 , V_19 ,
& V_14 , sizeof( struct V_13 ) ) ;
}
static int F_5 ( struct V_8 * V_9 ,
struct V_20 * V_21 , int V_22 )
{
int V_23 ;
V_23 = F_3 ( V_9 , V_22 ,
V_15 ) ;
if ( V_23 )
return V_23 ;
return F_6 ( V_9 , V_24 ,
V_21 , V_25 ) ;
}
static int F_7 ( struct V_8 * V_9 ,
struct V_26 * V_21 )
{
return F_6 ( V_9 , V_27 ,
V_21 , V_28 ) ;
}
static int F_8 ( struct V_8 * V_9 ,
struct V_26 const * V_29 )
{
return F_9 ( V_9 ,
V_27 , V_29 ,
V_28 ) ;
}
static T_1 F_10 ( struct V_30 * V_31 , struct V_32 * V_33 ,
char * V_21 , T_2 V_34 , T_3 V_35 ,
T_3 V_36 , T_4 V_18 )
{
struct V_37 * V_38 = F_11 ( V_33 ) -> V_39 -> V_39 ;
struct V_1 * V_2 = F_12 ( F_13 ( V_38 ) ) ;
struct V_8 * V_9 = F_14 ( F_15 ( V_38 ) ) ;
int V_23 ;
if ( V_34 >= V_36 )
return 0 ;
if ( V_34 != 0 || V_35 != V_36 )
return - V_17 ;
F_16 ( & V_2 -> V_40 ) ;
V_23 = F_6 ( V_9 , V_18 , V_21 , V_36 ) ;
F_17 ( & V_2 -> V_40 ) ;
if ( V_23 )
return V_23 ;
return V_36 ;
}
static T_1 F_18 ( struct V_30 * V_31 , struct V_32 * V_33 ,
void const * V_21 , T_2 V_34 , T_3 V_35 ,
T_3 V_36 , T_4 V_18 )
{
struct V_37 * V_38 = F_11 ( V_33 ) -> V_39 -> V_39 ;
struct V_1 * V_2 = F_12 ( F_13 ( V_38 ) ) ;
struct V_8 * V_9 = F_14 ( F_15 ( V_38 ) ) ;
int V_23 ;
if ( V_34 != 0 || V_35 != V_36 )
return - V_17 ;
F_16 ( & V_2 -> V_40 ) ;
V_23 = F_9 ( V_9 , V_18 , ( void * ) V_21 , V_36 ) ;
F_17 ( & V_2 -> V_40 ) ;
if ( V_23 )
return V_23 ;
return V_36 ;
}
static T_1 F_19 ( struct V_30 * V_31 ,
struct V_32 * V_33 , struct V_41 * V_42 , char * V_21 ,
T_2 V_34 , T_3 V_35 )
{
struct V_37 * V_38 = F_11 ( V_33 ) -> V_39 -> V_39 ;
struct V_8 * V_9 = F_14 ( F_15 ( V_38 ) ) ;
T_1 V_23 ;
V_23 = F_3 ( V_9 , * ( T_4 * ) ( V_42 -> V_43 ) ,
V_15 ) ;
if ( V_23 )
return V_23 ;
return F_10 ( V_31 , V_33 , V_21 , V_34 , V_35 ,
V_25 ,
V_24 ) ;
}
static T_1 F_20 ( struct V_30 * V_31 ,
struct V_32 * V_33 , struct V_41 * V_42 , char * V_21 ,
T_2 V_34 , T_3 V_35 )
{
struct V_37 * V_38 = F_11 ( V_33 ) -> V_39 -> V_39 ;
struct V_8 * V_9 = F_14 ( F_15 ( V_38 ) ) ;
T_1 V_23 ;
V_23 = F_3 ( V_9 , * ( T_4 * ) ( V_42 -> V_43 ) ,
V_16 ) ;
if ( V_23 )
return V_23 ;
return F_10 ( V_31 , V_33 , V_21 , V_34 , V_35 ,
V_44 ,
V_45 ) ;
}
static T_1 F_21 ( struct V_30 * V_31 ,
struct V_32 * V_33 , struct V_41 * V_42 , char * V_21 ,
T_2 V_34 , T_3 V_35 )
{
struct V_37 * V_38 = F_11 ( V_33 ) -> V_39 -> V_39 ;
struct V_1 * V_2 = F_12 ( F_13 ( V_38 ) ) ;
struct V_8 * V_9 = F_14 ( F_15 ( V_38 ) ) ;
int V_23 = 0 ;
struct V_46 V_47 ;
struct V_26 const * V_29 ;
if ( V_34 != 0 || V_35 != V_28 )
return - V_17 ;
V_29 = (struct V_26 const * ) V_21 ;
if ( V_29 -> V_48 >= F_2 ( V_2 -> V_4 ) )
return - V_17 ;
F_16 ( & V_2 -> V_40 ) ;
V_23 = F_8 ( V_9 , V_29 ) ;
if ( V_23 ) {
F_17 ( & V_2 -> V_40 ) ;
return V_23 ;
}
F_1 ( V_2 , V_29 -> V_48 ) ;
V_47 . type = V_49 ;
V_47 . V_10 = V_29 -> V_48 + 1 ;
V_47 . V_50 = 0 ;
F_22 ( V_2 -> V_51 ,
( V_52 const * ) & V_47 ) ;
F_17 ( & V_2 -> V_40 ) ;
return V_28 ;
}
static T_1 F_23 ( struct V_37 * V_38 ,
struct V_53 * V_42 , char * V_21 )
{
struct V_1 * V_2 =
F_12 ( F_13 ( V_38 -> V_39 -> V_39 ) ) ;
return snprintf ( V_21 , V_54 , L_1 , V_2 -> V_6 ) ;
}
static T_1 F_24 ( struct V_37 * V_38 ,
struct V_53 * V_42 , char * V_21 )
{
struct V_1 * V_2 =
F_12 ( F_13 ( V_38 -> V_39 -> V_39 ) ) ;
struct V_8 * V_9 = F_14 ( F_15 ( V_38 ) ) ;
struct V_26 V_29 ;
F_16 ( & V_2 -> V_40 ) ;
F_6 ( V_9 , V_27 ,
& V_29 , V_28 ) ;
F_17 ( & V_2 -> V_40 ) ;
return snprintf ( V_21 , V_54 , L_1 , V_29 . V_48 ) ;
}
static T_1 F_25 ( struct V_37 * V_38 ,
struct V_53 * V_42 , char * V_21 )
{
struct V_1 * V_2 ;
struct V_8 * V_9 ;
struct V_55 V_56 ;
V_38 = V_38 -> V_39 -> V_39 ;
V_2 = F_12 ( F_13 ( V_38 ) ) ;
V_9 = F_14 ( F_15 ( V_38 ) ) ;
F_16 ( & V_2 -> V_40 ) ;
F_6 ( V_9 , V_57 ,
& V_56 , V_58 ) ;
F_17 ( & V_2 -> V_40 ) ;
return snprintf ( V_21 , V_54 , L_1 , V_56 . V_59 ) ;
}
static int F_26 ( struct V_8 * V_9 ,
struct V_1 * V_2 )
{
struct V_26 V_29 ;
int V_23 , V_60 ;
F_27 ( & V_2 -> V_40 ) ;
V_23 = F_7 ( V_9 , & V_29 ) ;
if ( V_23 )
return V_23 ;
for ( V_60 = 0 ; V_60 < 5 ; ++ V_60 ) {
V_23 = F_5 ( V_9 ,
& V_2 -> V_4 [ V_60 ] , V_60 ) ;
if ( V_23 )
return V_23 ;
}
F_1 ( V_2 , V_29 . V_48 ) ;
return 0 ;
}
static int F_28 ( struct V_61 * V_62 )
{
struct V_63 * V_64 = F_15 ( V_62 -> V_38 . V_39 ) ;
struct V_8 * V_9 = F_14 ( V_64 ) ;
struct V_1 * V_2 ;
int V_23 ;
if ( V_64 -> V_65 -> V_66 . V_67
== V_68 ) {
V_2 = F_29 ( sizeof( * V_2 ) , V_69 ) ;
if ( ! V_2 ) {
F_30 ( V_62 , L_2 ) ;
return - V_70 ;
}
F_31 ( V_62 , V_2 ) ;
V_23 = F_26 ( V_9 , V_2 ) ;
if ( V_23 ) {
F_30 ( V_62 , L_3 ) ;
goto V_71;
}
V_23 = F_32 ( V_72 , V_62 ,
sizeof( struct V_46 ) ) ;
if ( V_23 < 0 ) {
F_30 ( V_62 , L_4 ) ;
} else {
V_2 -> V_51 = V_23 ;
V_2 -> V_73 = 1 ;
}
} else {
F_31 ( V_62 , NULL ) ;
}
return 0 ;
V_71:
F_33 ( V_2 ) ;
return V_23 ;
}
static void F_34 ( struct V_61 * V_62 )
{
struct V_63 * V_64 = F_15 ( V_62 -> V_38 . V_39 ) ;
struct V_1 * V_2 ;
if ( V_64 -> V_65 -> V_66 . V_67
== V_68 ) {
V_2 = F_12 ( V_62 ) ;
if ( V_2 -> V_73 )
F_35 ( V_2 -> V_51 ) ;
F_33 ( F_12 ( V_62 ) ) ;
}
}
static int F_36 ( struct V_61 * V_62 , const struct V_74 * V_75 )
{
int V_23 ;
V_23 = F_37 ( V_62 ) ;
if ( V_23 ) {
F_30 ( V_62 , L_5 ) ;
goto exit;
}
V_23 = F_38 ( V_62 , V_76 ) ;
if ( V_23 ) {
F_30 ( V_62 , L_6 ) ;
goto exit;
}
V_23 = F_28 ( V_62 ) ;
if ( V_23 ) {
F_30 ( V_62 , L_7 ) ;
goto V_77;
}
return 0 ;
V_77:
F_39 ( V_62 ) ;
exit:
return V_23 ;
}
static void F_40 ( struct V_61 * V_62 )
{
F_34 ( V_62 ) ;
F_39 ( V_62 ) ;
}
static void F_41 ( struct V_1 * V_2 ,
T_5 const * V_78 )
{
struct V_79 const * V_80 ;
switch ( V_78 [ 0 ] ) {
case V_81 :
V_80 = (struct V_79 const * ) V_78 ;
switch ( V_80 -> type ) {
case V_49 :
F_1 ( V_2 , V_80 -> V_82 - 1 ) ;
break;
case V_83 :
V_2 -> V_6 = V_80 -> V_82 ;
break;
}
break;
}
}
static void F_42 ( struct V_1 const * V_2 ,
T_5 const * V_78 )
{
struct V_46 V_47 ;
struct V_79 const * V_80 ;
if ( V_78 [ 0 ] != V_81 )
return;
V_80 = (struct V_79 const * ) V_78 ;
switch ( V_80 -> type ) {
case V_49 :
case V_83 :
V_47 . type = V_80 -> type ;
V_47 . V_10 = V_80 -> V_82 ;
V_47 . V_50 = 0 ;
F_22 ( V_2 -> V_51 ,
( V_52 const * ) & V_47 ) ;
break;
case V_84 :
case V_85 :
case V_86 :
if ( V_80 -> V_87 == V_88 ) {
V_47 . type = V_80 -> type ;
V_47 . V_50 = V_80 -> V_82 ;
V_47 . V_10 = V_2 -> V_5 + 1 ;
F_22 ( V_2 -> V_51 ,
( V_52 const * ) & V_47 ) ;
}
break;
}
}
static int F_43 ( struct V_61 * V_62 , struct V_89 * V_90 ,
T_5 * V_78 , int V_91 )
{
struct V_63 * V_64 = F_15 ( V_62 -> V_38 . V_39 ) ;
struct V_1 * V_2 = F_12 ( V_62 ) ;
if ( V_64 -> V_65 -> V_66 . V_67
!= V_68 )
return 0 ;
if ( V_2 == NULL )
return 0 ;
F_41 ( V_2 , V_78 ) ;
if ( V_2 -> V_73 )
F_42 ( V_2 , V_78 ) ;
return 0 ;
}
static int T_6 F_44 ( void )
{
int V_23 ;
V_72 = F_45 ( V_92 , L_8 ) ;
if ( F_46 ( V_72 ) )
return F_47 ( V_72 ) ;
V_72 -> V_93 = V_94 ;
V_23 = F_48 ( & V_95 ) ;
if ( V_23 )
F_49 ( V_72 ) ;
return V_23 ;
}
static void T_7 F_50 ( void )
{
F_51 ( & V_95 ) ;
F_49 ( V_72 ) ;
}
