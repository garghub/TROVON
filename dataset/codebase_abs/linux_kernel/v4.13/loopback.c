static void F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 > V_4 )
V_2 -> V_3 = V_4 ;
if ( V_2 -> V_5 > V_6 . V_7 )
V_2 -> V_5 = V_6 . V_7 ;
V_2 -> V_8 = 0 ;
V_2 -> V_9 = 0 ;
V_2 -> V_10 = 0 ;
V_2 -> V_11 = 0 ;
V_2 -> error = 0 ;
if ( V_12 < V_2 -> V_13 ) {
F_2 ( V_2 -> V_14 ,
L_1 ,
V_2 -> V_13 , V_12 ) ;
}
F_3 ( & V_2 -> V_15 ) ;
F_3 ( & V_2 -> V_16 ) ;
switch ( V_2 -> type ) {
case V_17 :
case V_18 :
case V_19 :
V_2 -> V_20 = F_4 ( V_2 -> V_21 ) ;
if ( ! V_2 -> V_20 )
V_2 -> V_20 = V_22 ;
else if ( V_2 -> V_20 > V_23 )
V_2 -> V_20 = V_23 ;
F_5 ( V_2 ) ;
F_6 ( & V_2 -> V_24 ) ;
break;
default:
V_2 -> type = 0 ;
break;
}
}
static T_1 F_7 ( T_2 V_25 )
{
F_8 ( V_25 , V_26 ) ;
return V_25 ;
}
static T_2 F_9 ( T_2 V_27 , T_2 V_28 )
{
if ( V_28 > V_27 )
return V_28 - V_27 ;
else
return V_29 - V_28 + V_27 ;
}
static T_2 F_10 ( struct V_30 * V_31 , struct V_30 * V_32 )
{
T_2 V_27 , V_28 ;
V_27 = F_11 ( V_31 ) ;
V_28 = F_11 ( V_32 ) ;
return F_9 ( V_27 , V_28 ) ;
}
static void F_12 ( struct V_1 * V_2 ,
struct V_30 * V_31 , struct V_30 * V_32 )
{
F_13 ( & V_2 -> V_16 , ( unsigned char * ) V_31 , sizeof( * V_31 ) ) ;
F_13 ( & V_2 -> V_16 , ( unsigned char * ) V_32 , sizeof( * V_32 ) ) ;
}
static int F_14 ( struct V_1 * V_2 , int type ,
void * V_33 , int V_34 ,
void * V_35 , int V_36 )
{
struct V_37 * V_38 ;
struct V_30 V_31 , V_32 ;
int V_39 ;
F_15 ( & V_31 ) ;
V_38 = F_16 ( V_2 -> V_40 , type , V_34 ,
V_36 , V_41 ) ;
if ( ! V_38 )
return - V_42 ;
if ( V_34 )
memcpy ( V_38 -> V_33 -> V_43 , V_33 , V_34 ) ;
V_39 = F_17 ( V_38 ) ;
if ( V_39 ) {
F_18 ( & V_2 -> V_40 -> V_44 -> V_14 ,
L_2 , V_39 ) ;
goto V_45;
} else {
if ( V_36 == V_38 -> V_35 -> V_46 ) {
memcpy ( V_35 , V_38 -> V_35 -> V_43 ,
V_36 ) ;
} else {
F_18 ( & V_2 -> V_40 -> V_44 -> V_14 ,
L_3 ,
V_38 -> V_35 -> V_46 ,
V_36 ) ;
V_39 = - V_47 ;
goto V_45;
}
}
F_15 ( & V_32 ) ;
F_12 ( V_2 , & V_31 , & V_32 ) ;
V_2 -> V_25 = F_10 ( & V_31 , & V_32 ) ;
V_45:
F_19 ( V_38 ) ;
return V_39 ;
}
static void F_20 ( struct V_48 * V_48 )
{
struct V_49 * V_50 ;
V_50 = F_21 ( V_48 , struct V_49 , V_48 ) ;
F_22 ( & V_50 -> V_51 ) ;
if ( V_50 -> V_38 )
F_19 ( V_50 -> V_38 ) ;
F_23 ( & V_50 -> V_2 -> V_52 ) ;
F_6 ( & V_50 -> V_2 -> V_53 ) ;
F_24 ( V_50 ) ;
}
static void F_25 ( struct V_49
* V_50 )
{
F_26 ( & V_50 -> V_48 ) ;
}
static void F_27 ( struct V_49
* V_50 )
{
unsigned long V_54 ;
F_28 ( & V_6 . V_55 , V_54 ) ;
F_29 ( & V_50 -> V_48 , F_20 ) ;
F_30 ( & V_6 . V_55 , V_54 ) ;
}
static struct V_49 *
F_31 ( T_3 V_56 )
{
struct V_49 * V_50 ;
bool V_57 = false ;
unsigned long V_54 ;
F_28 ( & V_6 . V_55 , V_54 ) ;
F_32 (op_async, &gb_dev.list_op_async, entry) {
if ( V_50 -> V_38 -> V_56 == V_56 ) {
F_25 ( V_50 ) ;
V_57 = true ;
break;
}
}
F_30 ( & V_6 . V_55 , V_54 ) ;
return V_57 ? V_50 : NULL ;
}
static void F_33 ( struct V_1 * V_2 )
{
F_34 ( V_2 -> V_53 ,
! F_35 ( & V_2 -> V_52 ) ) ;
}
static void F_36 ( struct V_37 * V_38 )
{
struct V_49 * V_50 ;
struct V_1 * V_2 ;
struct V_30 V_32 ;
bool V_58 = false ;
F_15 ( & V_32 ) ;
V_50 = F_31 ( V_38 -> V_56 ) ;
if ( ! V_50 )
return;
V_2 = V_50 -> V_2 ;
F_37 ( & V_2 -> V_59 ) ;
if ( ! V_50 -> V_60 || F_38 ( V_38 ) ) {
V_58 = true ;
} else {
if ( V_50 -> V_61 )
if ( V_50 -> V_61 ( V_50 ) )
V_58 = true ;
}
if ( ! V_58 ) {
F_12 ( V_2 , & V_50 -> V_31 , & V_32 ) ;
V_2 -> V_25 = F_10 ( & V_50 -> V_31 ,
& V_32 ) ;
}
if ( V_50 -> V_60 ) {
if ( V_58 )
V_2 -> error ++ ;
V_2 -> V_10 ++ ;
V_50 -> V_60 = false ;
F_39 ( & V_50 -> V_62 ) ;
F_27 ( V_50 ) ;
F_40 ( V_2 , V_58 ) ;
}
F_41 ( & V_2 -> V_59 ) ;
F_42 ( & V_2 -> V_40 -> V_44 -> V_14 , L_4 ,
V_38 -> V_56 ) ;
F_27 ( V_50 ) ;
}
static void F_43 ( struct V_63 * V_64 )
{
struct V_1 * V_2 ;
struct V_37 * V_38 ;
struct V_49 * V_50 ;
V_50 = F_21 ( V_64 , struct V_49 , V_64 ) ;
V_2 = V_50 -> V_2 ;
V_38 = V_50 -> V_38 ;
F_37 ( & V_2 -> V_59 ) ;
if ( V_50 -> V_60 ) {
V_2 -> V_8 ++ ;
V_2 -> error ++ ;
V_2 -> V_10 ++ ;
V_50 -> V_60 = false ;
F_27 ( V_50 ) ;
F_40 ( V_2 , true ) ;
}
F_41 ( & V_2 -> V_59 ) ;
F_42 ( & V_2 -> V_40 -> V_44 -> V_14 , L_5 ,
V_38 -> V_56 ) ;
F_44 ( V_38 , - V_65 ) ;
F_27 ( V_50 ) ;
}
static void F_45 ( unsigned long V_66 )
{
struct V_49 * V_50 ;
T_3 V_56 = V_66 ;
V_50 = F_31 ( V_56 ) ;
if ( ! V_50 ) {
F_46 ( L_6 , V_56 ) ;
return;
}
F_47 ( & V_50 -> V_64 ) ;
}
static int V_49 ( struct V_1 * V_2 , int type ,
void * V_33 , int V_34 ,
int V_36 ,
void * V_61 )
{
struct V_49 * V_50 ;
struct V_37 * V_38 ;
int V_39 ;
unsigned long V_54 ;
V_50 = F_48 ( sizeof( * V_50 ) , V_41 ) ;
if ( ! V_50 )
return - V_42 ;
F_49 ( & V_50 -> V_64 , F_43 ) ;
F_50 ( & V_50 -> V_48 ) ;
V_38 = F_16 ( V_2 -> V_40 , type , V_34 ,
V_36 , V_41 ) ;
if ( ! V_38 ) {
F_24 ( V_50 ) ;
return - V_42 ;
}
if ( V_34 )
memcpy ( V_38 -> V_33 -> V_43 , V_33 , V_34 ) ;
V_50 -> V_2 = V_2 ;
V_50 -> V_38 = V_38 ;
V_50 -> V_61 = V_61 ;
F_28 ( & V_6 . V_55 , V_54 ) ;
F_51 ( & V_50 -> V_51 , & V_6 . V_67 ) ;
F_30 ( & V_6 . V_55 , V_54 ) ;
F_15 ( & V_50 -> V_31 ) ;
V_50 -> V_60 = true ;
F_52 ( & V_2 -> V_52 ) ;
F_37 ( & V_2 -> V_59 ) ;
V_39 = F_53 ( V_38 ,
F_36 ,
0 ,
V_41 ) ;
if ( V_39 )
goto error;
F_54 ( & V_50 -> V_62 , F_45 ,
( unsigned long ) V_38 -> V_56 ) ;
V_50 -> V_62 . V_68 = V_69 + V_2 -> V_20 ;
F_55 ( & V_50 -> V_62 ) ;
goto V_70;
error:
F_27 ( V_50 ) ;
V_70:
F_41 ( & V_2 -> V_59 ) ;
return V_39 ;
}
static int F_56 ( struct V_1 * V_2 , T_1 V_71 )
{
struct V_72 * V_33 ;
int V_73 ;
V_33 = F_57 ( V_71 + sizeof( * V_33 ) , V_41 ) ;
if ( ! V_33 )
return - V_42 ;
V_33 -> V_71 = F_58 ( V_71 ) ;
V_73 = F_14 ( V_2 , V_19 ,
V_33 , V_71 + sizeof( * V_33 ) ,
NULL , 0 ) ;
F_24 ( V_33 ) ;
return V_73 ;
}
static int F_59 ( struct V_1 * V_2 , T_1 V_71 )
{
struct V_72 * V_33 ;
struct V_74 * V_35 ;
int V_73 ;
V_2 -> V_75 = 0 ;
V_2 -> V_76 = 0 ;
V_33 = F_57 ( V_71 + sizeof( * V_33 ) , V_41 ) ;
if ( ! V_33 )
return - V_42 ;
V_35 = F_57 ( V_71 + sizeof( * V_35 ) , V_41 ) ;
if ( ! V_35 ) {
F_24 ( V_33 ) ;
return - V_42 ;
}
memset ( V_33 -> V_66 , 0x5A , V_71 ) ;
V_33 -> V_71 = F_58 ( V_71 ) ;
V_73 = F_14 ( V_2 , V_18 ,
V_33 , V_71 + sizeof( * V_33 ) ,
V_35 , V_71 + sizeof( * V_35 ) ) ;
if ( V_73 )
goto V_77;
if ( memcmp ( V_33 -> V_66 , V_35 -> V_66 , V_71 ) ) {
F_18 ( & V_2 -> V_40 -> V_44 -> V_14 ,
L_7 ) ;
V_73 = - V_78 ;
}
V_2 -> V_75 = ( T_1 ) F_60 ( V_35 -> V_79 ) ;
V_2 -> V_76 = ( T_1 ) F_60 ( V_35 -> V_80 ) ;
V_77:
F_24 ( V_33 ) ;
F_24 ( V_35 ) ;
return V_73 ;
}
static int F_61 ( struct V_1 * V_2 )
{
return F_14 ( V_2 , V_17 ,
NULL , 0 , NULL , 0 ) ;
}
static int F_62 ( struct V_1 * V_2 , T_1 V_71 )
{
struct V_72 * V_33 ;
int V_73 ;
V_33 = F_57 ( V_71 + sizeof( * V_33 ) , V_41 ) ;
if ( ! V_33 )
return - V_42 ;
V_33 -> V_71 = F_58 ( V_71 ) ;
V_73 = V_49 ( V_2 , V_19 ,
V_33 , V_71 + sizeof( * V_33 ) ,
0 , NULL ) ;
F_24 ( V_33 ) ;
return V_73 ;
}
static int F_63 (
struct V_49 * V_50 )
{
struct V_1 * V_2 ;
struct V_37 * V_38 ;
struct V_72 * V_33 ;
struct V_74 * V_35 ;
T_4 V_71 ;
int V_73 = 0 ;
V_2 = V_50 -> V_2 ;
V_38 = V_50 -> V_38 ;
V_33 = V_38 -> V_33 -> V_43 ;
V_35 = V_38 -> V_35 -> V_43 ;
V_71 = F_64 ( V_33 -> V_71 ) ;
if ( memcmp ( V_33 -> V_66 , V_35 -> V_66 , V_71 ) ) {
F_18 ( & V_2 -> V_40 -> V_44 -> V_14 ,
L_8 ,
V_38 -> V_56 ) ;
V_73 = - V_78 ;
} else {
V_2 -> V_75 =
( T_1 ) F_60 ( V_35 -> V_79 ) ;
V_2 -> V_76 =
( T_1 ) F_60 ( V_35 -> V_80 ) ;
}
return V_73 ;
}
static int F_65 ( struct V_1 * V_2 , T_1 V_71 )
{
struct V_72 * V_33 ;
int V_73 , V_81 ;
V_33 = F_57 ( V_71 + sizeof( * V_33 ) , V_41 ) ;
if ( ! V_33 )
return - V_42 ;
memset ( V_33 -> V_66 , 0x5A , V_71 ) ;
V_33 -> V_71 = F_58 ( V_71 ) ;
V_81 = sizeof( struct V_74 ) ;
V_73 = V_49 ( V_2 , V_18 ,
V_33 , V_71 + sizeof( * V_33 ) ,
V_71 + V_81 ,
F_63 ) ;
if ( V_73 )
goto V_77;
V_77:
F_24 ( V_33 ) ;
return V_73 ;
}
static int F_66 ( struct V_1 * V_2 )
{
return V_49 ( V_2 , V_17 ,
NULL , 0 , 0 , NULL ) ;
}
static int F_67 ( struct V_37 * V_38 )
{
struct V_82 * V_40 = V_38 -> V_40 ;
struct V_72 * V_33 ;
struct V_74 * V_35 ;
struct V_83 * V_14 = & V_40 -> V_44 -> V_14 ;
T_4 V_71 ;
switch ( V_38 -> type ) {
case V_17 :
case V_19 :
return 0 ;
case V_18 :
if ( V_38 -> V_33 -> V_46 < sizeof( * V_33 ) ) {
F_18 ( V_14 , L_9 ,
V_38 -> V_33 -> V_46 ,
sizeof( * V_33 ) ) ;
return - V_47 ;
}
V_33 = V_38 -> V_33 -> V_43 ;
V_71 = F_64 ( V_33 -> V_71 ) ;
if ( V_71 > V_6 . V_7 ) {
F_18 ( V_14 , L_10 ,
V_71 , V_6 . V_7 ) ;
return - V_47 ;
}
if ( ! F_68 ( V_38 ,
V_71 + sizeof( * V_35 ) , V_41 ) ) {
F_18 ( V_14 , L_11 ) ;
return - V_42 ;
}
V_35 = V_38 -> V_35 -> V_43 ;
V_35 -> V_71 = F_58 ( V_71 ) ;
if ( V_71 )
memcpy ( V_35 -> V_66 , V_33 -> V_66 , V_71 ) ;
return 0 ;
default:
F_18 ( V_14 , L_12 , V_38 -> type ) ;
return - V_47 ;
}
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_84 V_85 = {
. V_86 = V_87 ,
} ;
memcpy ( & V_2 -> V_88 , & V_85 ,
sizeof( struct V_84 ) ) ;
memcpy ( & V_2 -> V_89 , & V_85 ,
sizeof( struct V_84 ) ) ;
memcpy ( & V_2 -> V_90 , & V_85 ,
sizeof( struct V_84 ) ) ;
memcpy ( & V_2 -> V_91 , & V_85 ,
sizeof( struct V_84 ) ) ;
memcpy ( & V_2 -> V_92 , & V_85 ,
sizeof( struct V_84 ) ) ;
V_2 -> V_75 = 0 ;
V_2 -> V_76 = 0 ;
memset ( & V_2 -> V_31 , 0 , sizeof( struct V_30 ) ) ;
}
static void F_69 ( struct V_84 * V_93 , T_1 V_94 )
{
if ( V_93 -> V_86 > V_94 )
V_93 -> V_86 = V_94 ;
if ( V_93 -> V_95 < V_94 )
V_93 -> V_95 = V_94 ;
V_93 -> V_96 += V_94 ;
V_93 -> V_97 ++ ;
}
static void F_70 ( struct V_84 * V_93 ,
T_2 V_94 , T_1 V_97 )
{
V_93 -> V_96 += V_94 ;
V_93 -> V_97 += V_97 ;
F_8 ( V_94 , V_97 ) ;
if ( V_93 -> V_86 > V_94 )
V_93 -> V_86 = V_94 ;
if ( V_93 -> V_95 < V_94 )
V_93 -> V_95 = V_94 ;
}
static void F_71 ( struct V_1 * V_2 , T_1 V_88 )
{
T_2 V_98 = V_2 -> V_9 * V_99 ;
F_70 ( & V_2 -> V_90 , V_98 , V_88 ) ;
}
static void F_72 ( struct V_1 * V_2 , T_1 V_88 )
{
T_2 V_100 = sizeof( struct V_101 ) * 2 ;
switch ( V_2 -> type ) {
case V_17 :
break;
case V_19 :
V_100 += sizeof( struct V_72 ) +
V_2 -> V_5 ;
break;
case V_18 :
V_100 += sizeof( struct V_72 ) +
sizeof( struct V_74 ) +
V_2 -> V_5 * 2 ;
break;
default:
return;
}
V_100 *= V_2 -> V_9 ;
V_100 *= V_99 ;
F_70 ( & V_2 -> V_89 , V_100 ,
V_88 ) ;
}
static void F_73 ( struct V_1 * V_2 )
{
T_1 V_102 ;
V_102 = F_7 ( V_2 -> V_25 ) ;
F_69 ( & V_2 -> V_88 , V_102 ) ;
F_13 ( & V_2 -> V_15 , ( unsigned char * ) & V_102 , sizeof( V_102 ) ) ;
F_69 ( & V_2 -> V_91 ,
V_2 -> V_75 ) ;
F_69 ( & V_2 -> V_92 ,
V_2 -> V_76 ) ;
}
static void F_40 ( struct V_1 * V_2 , bool error )
{
T_2 V_103 ;
T_1 V_102 ;
struct V_30 V_32 ;
if ( ! error ) {
V_2 -> V_9 ++ ;
F_73 ( V_2 ) ;
}
F_15 ( & V_32 ) ;
V_103 = F_10 ( & V_2 -> V_31 , & V_32 ) ;
if ( V_103 >= V_104 || V_2 -> V_10 == V_2 -> V_13 ) {
V_102 = F_7 ( V_103 ) ;
F_72 ( V_2 , V_102 ) ;
F_71 ( V_2 , V_102 ) ;
if ( V_2 -> V_10 != V_2 -> V_13 ) {
V_2 -> V_31 = V_32 ;
V_2 -> V_9 = 0 ;
}
}
}
static void F_74 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_105 && V_2 -> V_106 ) )
return;
F_75 ( V_2 -> V_53 ,
( F_35 ( & V_2 -> V_52 ) <
V_2 -> V_106 ) ||
F_76 () ) ;
}
static int F_77 ( void * V_66 )
{
int error = 0 ;
int V_3 = 0 ;
int type ;
int V_39 ;
T_1 V_5 ;
struct V_1 * V_2 = V_66 ;
struct V_107 * V_44 = V_2 -> V_40 -> V_44 ;
V_39 = F_78 ( V_44 ) ;
if ( V_39 )
return V_39 ;
while ( 1 ) {
if ( ! V_2 -> type ) {
F_79 ( V_44 ) ;
F_75 ( V_2 -> V_24 , V_2 -> type ||
F_76 () ) ;
V_39 = F_78 ( V_44 ) ;
if ( V_39 )
return V_39 ;
}
if ( F_76 () )
break;
F_74 ( V_2 ) ;
if ( F_76 () )
break;
F_37 ( & V_2 -> V_59 ) ;
if ( V_2 -> V_11 == V_2 -> V_13 ) {
F_41 ( & V_2 -> V_59 ) ;
F_33 ( V_2 ) ;
F_37 ( & V_2 -> V_59 ) ;
if ( V_2 -> V_10 == V_2 -> V_13 ) {
V_2 -> type = 0 ;
V_2 -> V_11 = 0 ;
F_80 ( & V_2 -> V_14 -> V_108 , NULL ,
L_13 ) ;
F_42 ( & V_44 -> V_14 , L_14 ) ;
} else {
F_42 ( & V_44 -> V_14 ,
L_15 ) ;
}
F_41 ( & V_2 -> V_59 ) ;
continue;
}
V_5 = V_2 -> V_5 ;
V_3 = V_2 -> V_3 ;
type = V_2 -> type ;
if ( V_2 -> V_31 . V_109 == 0 && V_2 -> V_31 . V_110 == 0 )
F_15 ( & V_2 -> V_31 ) ;
F_41 ( & V_2 -> V_59 ) ;
if ( V_2 -> V_105 ) {
if ( type == V_17 )
error = F_66 ( V_2 ) ;
else if ( type == V_18 )
error = F_65 ( V_2 , V_5 ) ;
else if ( type == V_19 )
error = F_62 ( V_2 , V_5 ) ;
if ( error )
V_2 -> error ++ ;
} else {
if ( type == V_17 )
error = F_61 ( V_2 ) ;
else if ( type == V_18 )
error = F_59 ( V_2 , V_5 ) ;
else if ( type == V_19 )
error = F_56 ( V_2 , V_5 ) ;
if ( error )
V_2 -> error ++ ;
V_2 -> V_10 ++ ;
F_40 ( V_2 , ! ! error ) ;
}
V_2 -> V_11 ++ ;
if ( V_3 ) {
if ( V_3 < 20000 )
F_81 ( V_3 , V_3 + 100 ) ;
else
F_82 ( V_3 / 1000 ) ;
}
}
F_79 ( V_44 ) ;
return 0 ;
}
static int F_83 ( struct V_111 * V_112 ,
struct V_113 * V_113 ,
struct V_59 * V_59 )
{
T_1 V_88 ;
int V_73 ;
if ( F_84 ( V_113 ) == 0 ) {
V_73 = - V_114 ;
goto V_70;
}
F_37 ( V_59 ) ;
V_73 = F_85 ( V_113 , & V_88 , sizeof( V_88 ) ) ;
if ( V_73 > 0 ) {
F_86 ( V_112 , L_16 , V_88 ) ;
V_73 = 0 ;
}
F_41 ( V_59 ) ;
V_70:
return V_73 ;
}
static int F_87 ( struct V_111 * V_112 , void * V_115 )
{
struct V_1 * V_2 = V_112 -> V_116 ;
return F_83 ( V_112 , & V_2 -> V_15 ,
& V_2 -> V_59 ) ;
}
static int F_88 ( struct V_117 * V_117 , struct V_118 * V_118 )
{
return F_89 ( V_118 , F_87 ,
V_117 -> V_119 ) ;
}
static int F_90 ( void * V_120 , struct V_121 * V_122 ,
struct V_121 * V_123 )
{
struct V_1 * V_124 = F_91 ( V_122 , struct V_1 , V_51 ) ;
struct V_1 * V_125 = F_91 ( V_123 , struct V_1 , V_51 ) ;
struct V_82 * V_126 = V_124 -> V_40 ;
struct V_82 * V_127 = V_125 -> V_40 ;
if ( V_126 -> V_44 -> V_128 -> V_129 < V_127 -> V_44 -> V_128 -> V_129 )
return - 1 ;
if ( V_127 -> V_44 -> V_128 -> V_129 < V_126 -> V_44 -> V_128 -> V_129 )
return 1 ;
if ( V_126 -> V_44 -> V_56 < V_127 -> V_44 -> V_56 )
return - 1 ;
if ( V_127 -> V_44 -> V_56 < V_126 -> V_44 -> V_56 )
return 1 ;
if ( V_126 -> V_130 < V_127 -> V_130 )
return - 1 ;
else if ( V_127 -> V_130 < V_126 -> V_130 )
return 1 ;
return 0 ;
}
static void F_92 ( struct V_1 * V_2 )
{
struct V_1 * V_131 ;
T_1 V_132 = 0 ;
F_51 ( & V_2 -> V_51 , & V_6 . V_133 ) ;
F_93 ( NULL , & V_6 . V_133 , F_90 ) ;
F_32 (gb_list, &gb_dev.list, entry) {
V_131 -> V_134 = 1 << V_132 ;
V_132 ++ ;
}
}
static int F_94 ( struct V_107 * V_44 ,
const struct V_135 * V_56 )
{
struct V_136 * V_137 ;
struct V_82 * V_40 ;
struct V_1 * V_2 ;
struct V_83 * V_14 ;
int V_73 ;
char V_138 [ V_139 ] ;
unsigned long V_54 ;
if ( V_44 -> V_140 != 1 )
return - V_141 ;
V_137 = & V_44 -> V_137 [ 0 ] ;
if ( V_137 -> V_142 != V_143 )
return - V_141 ;
V_2 = F_48 ( sizeof( * V_2 ) , V_41 ) ;
if ( ! V_2 )
return - V_42 ;
V_40 = F_95 ( V_44 , F_96 ( V_137 -> V_56 ) ,
F_67 ) ;
if ( F_97 ( V_40 ) ) {
V_73 = F_98 ( V_40 ) ;
goto V_144;
}
V_2 -> V_40 = V_40 ;
F_99 ( V_44 , V_2 ) ;
F_100 ( & V_2 -> V_24 ) ;
F_100 ( & V_2 -> V_53 ) ;
F_101 ( & V_2 -> V_52 , 0 ) ;
F_5 ( V_2 ) ;
V_2 -> V_145 = F_102 ( V_22 ) ;
V_2 -> V_146 = F_102 ( V_23 ) ;
if ( ! V_6 . V_97 ) {
V_6 . V_7 = F_103 ( V_40 ) ;
if ( V_6 . V_7 <=
sizeof( struct V_72 ) ) {
V_73 = - V_47 ;
goto V_147;
}
V_6 . V_7 -= sizeof( struct V_72 ) ;
}
snprintf ( V_138 , sizeof( V_138 ) , L_17 ,
F_104 ( & V_40 -> V_44 -> V_14 ) ) ;
V_2 -> V_118 = F_105 ( V_138 , V_148 | 0444 , V_6 . V_149 , V_2 ,
& V_150 ) ;
V_2 -> V_56 = F_106 ( & V_151 , 0 , 0 , V_41 ) ;
if ( V_2 -> V_56 < 0 ) {
V_73 = V_2 -> V_56 ;
goto V_152;
}
V_73 = F_107 ( V_40 ) ;
if ( V_73 )
goto V_153;
V_14 = F_108 ( & V_154 ,
& V_40 -> V_44 -> V_14 ,
F_109 ( 0 , 0 ) , V_2 , V_155 ,
L_18 , V_2 -> V_56 ) ;
if ( F_97 ( V_14 ) ) {
V_73 = F_98 ( V_14 ) ;
goto V_156;
}
V_2 -> V_14 = V_14 ;
if ( F_110 ( & V_2 -> V_15 , V_12 * sizeof( T_1 ) ,
V_41 ) ) {
V_73 = - V_42 ;
goto V_157;
}
if ( F_110 ( & V_2 -> V_16 , V_12 * sizeof( struct V_30 ) * 2 ,
V_41 ) ) {
V_73 = - V_42 ;
goto V_158;
}
F_111 ( & V_2 -> V_59 ) ;
V_2 -> V_159 = F_112 ( F_77 , V_2 , L_19 ) ;
if ( F_97 ( V_2 -> V_159 ) ) {
V_73 = F_98 ( V_2 -> V_159 ) ;
goto V_160;
}
F_28 ( & V_6 . V_55 , V_54 ) ;
F_92 ( V_2 ) ;
V_6 . V_97 ++ ;
F_30 ( & V_6 . V_55 , V_54 ) ;
F_113 ( V_40 ) ;
F_79 ( V_44 ) ;
return 0 ;
V_160:
F_114 ( & V_2 -> V_16 ) ;
V_158:
F_114 ( & V_2 -> V_15 ) ;
V_157:
F_115 ( V_14 ) ;
V_156:
F_116 ( V_40 ) ;
V_153:
F_117 ( & V_151 , V_2 -> V_56 ) ;
V_152:
F_118 ( V_2 -> V_118 ) ;
V_147:
F_119 ( V_40 ) ;
V_144:
F_24 ( V_2 ) ;
return V_73 ;
}
static void F_120 ( struct V_107 * V_44 )
{
struct V_1 * V_2 = F_121 ( V_44 ) ;
unsigned long V_54 ;
int V_39 ;
V_39 = F_78 ( V_44 ) ;
if ( V_39 )
F_122 ( V_44 ) ;
F_116 ( V_2 -> V_40 ) ;
if ( ! F_123 ( V_2 -> V_159 ) )
F_124 ( V_2 -> V_159 ) ;
F_114 ( & V_2 -> V_15 ) ;
F_114 ( & V_2 -> V_16 ) ;
F_125 ( V_2 -> V_40 ) ;
F_118 ( V_2 -> V_118 ) ;
F_33 ( V_2 ) ;
F_28 ( & V_6 . V_55 , V_54 ) ;
V_6 . V_97 -- ;
F_22 ( & V_2 -> V_51 ) ;
F_30 ( & V_6 . V_55 , V_54 ) ;
F_115 ( V_2 -> V_14 ) ;
F_117 ( & V_151 , V_2 -> V_56 ) ;
F_119 ( V_2 -> V_40 ) ;
F_24 ( V_2 ) ;
}
static int F_126 ( void )
{
int V_73 ;
F_127 ( & V_6 . V_133 ) ;
F_127 ( & V_6 . V_67 ) ;
F_128 ( & V_6 . V_55 ) ;
V_6 . V_149 = F_129 ( L_19 , NULL ) ;
V_73 = F_130 ( & V_154 ) ;
if ( V_73 )
goto V_58;
V_73 = F_131 ( & V_161 ) ;
if ( V_73 )
goto V_162;
return 0 ;
V_162:
F_132 ( & V_154 ) ;
V_58:
F_133 ( V_6 . V_149 ) ;
return V_73 ;
}
static void T_5 F_134 ( void )
{
F_133 ( V_6 . V_149 ) ;
F_135 ( & V_161 ) ;
F_132 ( & V_154 ) ;
F_136 ( & V_151 ) ;
}
