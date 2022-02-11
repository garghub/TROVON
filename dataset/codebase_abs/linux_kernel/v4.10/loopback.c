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
T_1 V_26 ;
F_8 ( V_25 , V_27 ) ;
V_26 = V_25 ;
return V_26 ;
}
static T_2 F_9 ( T_2 V_28 , T_2 V_29 )
{
if ( V_29 > V_28 )
return V_29 - V_28 ;
else
return V_30 - V_29 + V_28 ;
}
static T_2 F_10 ( struct V_31 * V_32 , struct V_31 * V_33 )
{
T_2 V_28 , V_29 ;
V_28 = F_11 ( V_32 ) ;
V_29 = F_11 ( V_33 ) ;
return F_9 ( V_28 , V_29 ) ;
}
static void F_12 ( struct V_1 * V_2 ,
struct V_31 * V_32 , struct V_31 * V_33 )
{
F_13 ( & V_2 -> V_16 , ( unsigned char * ) V_32 , sizeof( * V_32 ) ) ;
F_13 ( & V_2 -> V_16 , ( unsigned char * ) V_33 , sizeof( * V_33 ) ) ;
}
static int F_14 ( struct V_1 * V_2 , int type ,
void * V_34 , int V_35 ,
void * V_36 , int V_37 )
{
struct V_38 * V_39 ;
struct V_31 V_32 , V_33 ;
int V_40 ;
F_15 ( & V_32 ) ;
V_39 = F_16 ( V_2 -> V_41 , type , V_35 ,
V_37 , V_42 ) ;
if ( ! V_39 )
return - V_43 ;
if ( V_35 )
memcpy ( V_39 -> V_34 -> V_44 , V_34 , V_35 ) ;
V_40 = F_17 ( V_39 ) ;
if ( V_40 ) {
F_18 ( & V_2 -> V_41 -> V_45 -> V_14 ,
L_2 , V_40 ) ;
goto V_46;
} else {
if ( V_37 == V_39 -> V_36 -> V_47 ) {
memcpy ( V_36 , V_39 -> V_36 -> V_44 ,
V_37 ) ;
} else {
F_18 ( & V_2 -> V_41 -> V_45 -> V_14 ,
L_3 ,
V_39 -> V_36 -> V_47 ,
V_37 ) ;
V_40 = - V_48 ;
goto V_46;
}
}
F_15 ( & V_33 ) ;
F_12 ( V_2 , & V_32 , & V_33 ) ;
V_2 -> V_25 = F_10 ( & V_32 , & V_33 ) ;
V_46:
F_19 ( V_39 ) ;
return V_40 ;
}
static void F_20 ( struct V_49 * V_49 )
{
struct V_50 * V_51 ;
V_51 = F_21 ( V_49 , struct V_50 , V_49 ) ;
F_22 ( & V_51 -> V_52 ) ;
if ( V_51 -> V_39 )
F_19 ( V_51 -> V_39 ) ;
F_23 ( & V_51 -> V_2 -> V_53 ) ;
F_6 ( & V_51 -> V_2 -> V_54 ) ;
F_24 ( V_51 ) ;
}
static void F_25 ( struct V_50
* V_51 )
{
F_26 ( & V_51 -> V_49 ) ;
}
static void F_27 ( struct V_50
* V_51 )
{
unsigned long V_55 ;
F_28 ( & V_6 . V_56 , V_55 ) ;
F_29 ( & V_51 -> V_49 , F_20 ) ;
F_30 ( & V_6 . V_56 , V_55 ) ;
}
static struct V_50 *
F_31 ( T_3 V_57 )
{
struct V_50 * V_51 ;
bool V_58 = false ;
unsigned long V_55 ;
F_28 ( & V_6 . V_56 , V_55 ) ;
F_32 (op_async, &gb_dev.list_op_async, entry) {
if ( V_51 -> V_39 -> V_57 == V_57 ) {
F_25 ( V_51 ) ;
V_58 = true ;
break;
}
}
F_30 ( & V_6 . V_56 , V_55 ) ;
return V_58 ? V_51 : NULL ;
}
static void F_33 ( struct V_1 * V_2 )
{
F_34 ( V_2 -> V_54 ,
! F_35 ( & V_2 -> V_53 ) ) ;
}
static void F_36 ( struct V_38 * V_39 )
{
struct V_50 * V_51 ;
struct V_1 * V_2 ;
struct V_31 V_33 ;
bool V_59 = false ;
F_15 ( & V_33 ) ;
V_51 = F_31 ( V_39 -> V_57 ) ;
if ( ! V_51 )
return;
V_2 = V_51 -> V_2 ;
F_37 ( & V_2 -> V_60 ) ;
if ( ! V_51 -> V_61 || F_38 ( V_39 ) ) {
V_59 = true ;
} else {
if ( V_51 -> V_62 )
if ( V_51 -> V_62 ( V_51 ) )
V_59 = true ;
}
if ( ! V_59 ) {
F_12 ( V_2 , & V_51 -> V_32 , & V_33 ) ;
V_2 -> V_25 = F_10 ( & V_51 -> V_32 ,
& V_33 ) ;
}
if ( V_51 -> V_61 ) {
if ( V_59 )
V_2 -> error ++ ;
V_2 -> V_10 ++ ;
V_51 -> V_61 = false ;
F_39 ( & V_51 -> V_63 ) ;
F_27 ( V_51 ) ;
F_40 ( V_2 , V_59 ) ;
}
F_41 ( & V_2 -> V_60 ) ;
F_42 ( & V_2 -> V_41 -> V_45 -> V_14 , L_4 ,
V_39 -> V_57 ) ;
F_27 ( V_51 ) ;
}
static void F_43 ( struct V_64 * V_65 )
{
struct V_1 * V_2 ;
struct V_38 * V_39 ;
struct V_50 * V_51 ;
V_51 = F_21 ( V_65 , struct V_50 , V_65 ) ;
V_2 = V_51 -> V_2 ;
V_39 = V_51 -> V_39 ;
F_37 ( & V_2 -> V_60 ) ;
if ( V_51 -> V_61 ) {
V_2 -> V_8 ++ ;
V_2 -> error ++ ;
V_2 -> V_10 ++ ;
V_51 -> V_61 = false ;
F_27 ( V_51 ) ;
F_40 ( V_2 , true ) ;
}
F_41 ( & V_2 -> V_60 ) ;
F_42 ( & V_2 -> V_41 -> V_45 -> V_14 , L_5 ,
V_39 -> V_57 ) ;
F_44 ( V_39 , - V_66 ) ;
F_27 ( V_51 ) ;
}
static void F_45 ( unsigned long V_67 )
{
struct V_50 * V_51 ;
T_3 V_57 = V_67 ;
V_51 = F_31 ( V_57 ) ;
if ( ! V_51 ) {
F_46 ( L_6 , V_57 ) ;
return;
}
F_47 ( & V_51 -> V_65 ) ;
}
static int V_50 ( struct V_1 * V_2 , int type ,
void * V_34 , int V_35 ,
int V_37 ,
void * V_62 )
{
struct V_50 * V_51 ;
struct V_38 * V_39 ;
int V_40 ;
unsigned long V_55 ;
V_51 = F_48 ( sizeof( * V_51 ) , V_42 ) ;
if ( ! V_51 )
return - V_43 ;
F_49 ( & V_51 -> V_65 , F_43 ) ;
F_50 ( & V_51 -> V_49 ) ;
V_39 = F_16 ( V_2 -> V_41 , type , V_35 ,
V_37 , V_42 ) ;
if ( ! V_39 ) {
F_24 ( V_51 ) ;
return - V_43 ;
}
if ( V_35 )
memcpy ( V_39 -> V_34 -> V_44 , V_34 , V_35 ) ;
V_51 -> V_2 = V_2 ;
V_51 -> V_39 = V_39 ;
V_51 -> V_62 = V_62 ;
F_28 ( & V_6 . V_56 , V_55 ) ;
F_51 ( & V_51 -> V_52 , & V_6 . V_68 ) ;
F_30 ( & V_6 . V_56 , V_55 ) ;
F_15 ( & V_51 -> V_32 ) ;
V_51 -> V_61 = true ;
F_52 ( & V_2 -> V_53 ) ;
F_37 ( & V_2 -> V_60 ) ;
V_40 = F_53 ( V_39 ,
F_36 ,
V_42 ) ;
if ( V_40 )
goto error;
F_54 ( & V_51 -> V_63 , F_45 ,
( unsigned long ) V_39 -> V_57 ) ;
V_51 -> V_63 . V_69 = V_70 + V_2 -> V_20 ;
F_55 ( & V_51 -> V_63 ) ;
goto V_71;
error:
F_27 ( V_51 ) ;
V_71:
F_41 ( & V_2 -> V_60 ) ;
return V_40 ;
}
static int F_56 ( struct V_1 * V_2 , T_1 V_72 )
{
struct V_73 * V_34 ;
int V_74 ;
V_34 = F_57 ( V_72 + sizeof( * V_34 ) , V_42 ) ;
if ( ! V_34 )
return - V_43 ;
V_34 -> V_72 = F_58 ( V_72 ) ;
V_74 = F_14 ( V_2 , V_19 ,
V_34 , V_72 + sizeof( * V_34 ) ,
NULL , 0 ) ;
F_24 ( V_34 ) ;
return V_74 ;
}
static int F_59 ( struct V_1 * V_2 , T_1 V_72 )
{
struct V_73 * V_34 ;
struct V_75 * V_36 ;
int V_74 ;
V_2 -> V_76 = 0 ;
V_2 -> V_77 = 0 ;
V_34 = F_57 ( V_72 + sizeof( * V_34 ) , V_42 ) ;
if ( ! V_34 )
return - V_43 ;
V_36 = F_57 ( V_72 + sizeof( * V_36 ) , V_42 ) ;
if ( ! V_36 ) {
F_24 ( V_34 ) ;
return - V_43 ;
}
memset ( V_34 -> V_67 , 0x5A , V_72 ) ;
V_34 -> V_72 = F_58 ( V_72 ) ;
V_74 = F_14 ( V_2 , V_18 ,
V_34 , V_72 + sizeof( * V_34 ) ,
V_36 , V_72 + sizeof( * V_36 ) ) ;
if ( V_74 )
goto V_78;
if ( memcmp ( V_34 -> V_67 , V_36 -> V_67 , V_72 ) ) {
F_18 ( & V_2 -> V_41 -> V_45 -> V_14 ,
L_7 ) ;
V_74 = - V_79 ;
}
V_2 -> V_76 = ( T_1 ) F_60 ( V_36 -> V_80 ) ;
V_2 -> V_77 = ( T_1 ) F_60 ( V_36 -> V_81 ) ;
V_78:
F_24 ( V_34 ) ;
F_24 ( V_36 ) ;
return V_74 ;
}
static int F_61 ( struct V_1 * V_2 )
{
return F_14 ( V_2 , V_17 ,
NULL , 0 , NULL , 0 ) ;
}
static int F_62 ( struct V_1 * V_2 , T_1 V_72 )
{
struct V_73 * V_34 ;
int V_74 ;
V_34 = F_57 ( V_72 + sizeof( * V_34 ) , V_42 ) ;
if ( ! V_34 )
return - V_43 ;
V_34 -> V_72 = F_58 ( V_72 ) ;
V_74 = V_50 ( V_2 , V_19 ,
V_34 , V_72 + sizeof( * V_34 ) ,
0 , NULL ) ;
F_24 ( V_34 ) ;
return V_74 ;
}
static int F_63 (
struct V_50 * V_51 )
{
struct V_1 * V_2 ;
struct V_38 * V_39 ;
struct V_73 * V_34 ;
struct V_75 * V_36 ;
T_4 V_72 ;
int V_74 = 0 ;
V_2 = V_51 -> V_2 ;
V_39 = V_51 -> V_39 ;
V_34 = V_39 -> V_34 -> V_44 ;
V_36 = V_39 -> V_36 -> V_44 ;
V_72 = F_64 ( V_34 -> V_72 ) ;
if ( memcmp ( V_34 -> V_67 , V_36 -> V_67 , V_72 ) ) {
F_18 ( & V_2 -> V_41 -> V_45 -> V_14 ,
L_8 ,
V_39 -> V_57 ) ;
V_74 = - V_79 ;
} else {
V_2 -> V_76 =
( T_1 ) F_60 ( V_36 -> V_80 ) ;
V_2 -> V_77 =
( T_1 ) F_60 ( V_36 -> V_81 ) ;
}
return V_74 ;
}
static int F_65 ( struct V_1 * V_2 , T_1 V_72 )
{
struct V_73 * V_34 ;
int V_74 , V_82 ;
V_34 = F_57 ( V_72 + sizeof( * V_34 ) , V_42 ) ;
if ( ! V_34 )
return - V_43 ;
memset ( V_34 -> V_67 , 0x5A , V_72 ) ;
V_34 -> V_72 = F_58 ( V_72 ) ;
V_82 = sizeof( struct V_75 ) ;
V_74 = V_50 ( V_2 , V_18 ,
V_34 , V_72 + sizeof( * V_34 ) ,
V_72 + V_82 ,
F_63 ) ;
if ( V_74 )
goto V_78;
V_78:
F_24 ( V_34 ) ;
return V_74 ;
}
static int F_66 ( struct V_1 * V_2 )
{
return V_50 ( V_2 , V_17 ,
NULL , 0 , 0 , NULL ) ;
}
static int F_67 ( struct V_38 * V_39 )
{
struct V_83 * V_41 = V_39 -> V_41 ;
struct V_73 * V_34 ;
struct V_75 * V_36 ;
struct V_84 * V_14 = & V_41 -> V_45 -> V_14 ;
T_4 V_72 ;
switch ( V_39 -> type ) {
case V_17 :
case V_19 :
return 0 ;
case V_18 :
if ( V_39 -> V_34 -> V_47 < sizeof( * V_34 ) ) {
F_18 ( V_14 , L_9 ,
V_39 -> V_34 -> V_47 ,
sizeof( * V_34 ) ) ;
return - V_48 ;
}
V_34 = V_39 -> V_34 -> V_44 ;
V_72 = F_64 ( V_34 -> V_72 ) ;
if ( V_72 > V_6 . V_7 ) {
F_18 ( V_14 , L_10 ,
V_72 , V_6 . V_7 ) ;
return - V_48 ;
}
if ( ! F_68 ( V_39 ,
V_72 + sizeof( * V_36 ) , V_42 ) ) {
F_18 ( V_14 , L_11 ) ;
return - V_43 ;
}
V_36 = V_39 -> V_36 -> V_44 ;
V_36 -> V_72 = F_58 ( V_72 ) ;
if ( V_72 )
memcpy ( V_36 -> V_67 , V_34 -> V_67 , V_72 ) ;
return 0 ;
default:
F_18 ( V_14 , L_12 , V_39 -> type ) ;
return - V_48 ;
}
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_85 V_86 = {
. V_87 = V_88 ,
} ;
memcpy ( & V_2 -> V_89 , & V_86 ,
sizeof( struct V_85 ) ) ;
memcpy ( & V_2 -> V_90 , & V_86 ,
sizeof( struct V_85 ) ) ;
memcpy ( & V_2 -> V_91 , & V_86 ,
sizeof( struct V_85 ) ) ;
memcpy ( & V_2 -> V_92 , & V_86 ,
sizeof( struct V_85 ) ) ;
memcpy ( & V_2 -> V_93 , & V_86 ,
sizeof( struct V_85 ) ) ;
V_2 -> V_76 = 0 ;
V_2 -> V_77 = 0 ;
memset ( & V_2 -> V_32 , 0 , sizeof( struct V_31 ) ) ;
}
static void F_69 ( struct V_85 * V_94 , T_1 V_95 )
{
if ( V_94 -> V_87 > V_95 )
V_94 -> V_87 = V_95 ;
if ( V_94 -> V_96 < V_95 )
V_94 -> V_96 = V_95 ;
V_94 -> V_97 += V_95 ;
V_94 -> V_98 ++ ;
}
static void F_70 ( struct V_85 * V_94 ,
T_2 V_95 , T_1 V_98 )
{
V_94 -> V_97 += V_95 ;
V_94 -> V_98 += V_98 ;
F_8 ( V_95 , V_98 ) ;
if ( V_94 -> V_87 > V_95 )
V_94 -> V_87 = V_95 ;
if ( V_94 -> V_96 < V_95 )
V_94 -> V_96 = V_95 ;
}
static void F_71 ( struct V_1 * V_2 , T_1 V_89 )
{
T_2 V_99 = V_2 -> V_9 * V_100 ;
F_70 ( & V_2 -> V_91 , V_99 , V_89 ) ;
}
static void F_72 ( struct V_1 * V_2 , T_1 V_89 )
{
T_2 V_101 = sizeof( struct V_102 ) * 2 ;
switch ( V_2 -> type ) {
case V_17 :
break;
case V_19 :
V_101 += sizeof( struct V_73 ) +
V_2 -> V_5 ;
break;
case V_18 :
V_101 += sizeof( struct V_73 ) +
sizeof( struct V_75 ) +
V_2 -> V_5 * 2 ;
break;
default:
return;
}
V_101 *= V_2 -> V_9 ;
V_101 *= V_100 ;
F_70 ( & V_2 -> V_90 , V_101 ,
V_89 ) ;
}
static void F_73 ( struct V_1 * V_2 )
{
T_1 V_26 ;
V_26 = F_7 ( V_2 -> V_25 ) ;
F_69 ( & V_2 -> V_89 , V_26 ) ;
F_13 ( & V_2 -> V_15 , ( unsigned char * ) & V_26 , sizeof( V_26 ) ) ;
F_69 ( & V_2 -> V_92 ,
V_2 -> V_76 ) ;
F_69 ( & V_2 -> V_93 ,
V_2 -> V_77 ) ;
}
static void F_40 ( struct V_1 * V_2 , bool error )
{
T_2 V_103 ;
T_1 V_26 ;
struct V_31 V_33 ;
if ( ! error ) {
V_2 -> V_9 ++ ;
F_73 ( V_2 ) ;
}
F_15 ( & V_33 ) ;
V_103 = F_10 ( & V_2 -> V_32 , & V_33 ) ;
if ( V_103 >= V_104 || V_2 -> V_10 == V_2 -> V_13 ) {
V_26 = F_7 ( V_103 ) ;
F_72 ( V_2 , V_26 ) ;
F_71 ( V_2 , V_26 ) ;
if ( V_2 -> V_10 != V_2 -> V_13 ) {
V_2 -> V_32 = V_33 ;
V_2 -> V_9 = 0 ;
}
}
}
static void F_74 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_105 && V_2 -> V_106 ) )
return;
F_75 ( V_2 -> V_54 ,
( F_35 ( & V_2 -> V_53 ) <
V_2 -> V_106 ) ||
F_76 () ) ;
}
static int F_77 ( void * V_67 )
{
int error = 0 ;
int V_3 = 0 ;
int type ;
int V_40 ;
T_1 V_5 ;
struct V_1 * V_2 = V_67 ;
struct V_107 * V_45 = V_2 -> V_41 -> V_45 ;
V_40 = F_78 ( V_45 ) ;
if ( V_40 )
return V_40 ;
while ( 1 ) {
if ( ! V_2 -> type ) {
F_79 ( V_45 ) ;
F_75 ( V_2 -> V_24 , V_2 -> type ||
F_76 () ) ;
V_40 = F_78 ( V_45 ) ;
if ( V_40 )
return V_40 ;
}
if ( F_76 () )
break;
F_74 ( V_2 ) ;
if ( F_76 () )
break;
F_37 ( & V_2 -> V_60 ) ;
if ( V_2 -> V_11 == V_2 -> V_13 ) {
if ( V_2 -> V_10 == V_2 -> V_13 ) {
V_2 -> type = 0 ;
V_2 -> V_11 = 0 ;
F_80 ( & V_2 -> V_14 -> V_108 , NULL ,
L_13 ) ;
}
F_41 ( & V_2 -> V_60 ) ;
continue;
}
V_5 = V_2 -> V_5 ;
V_3 = V_2 -> V_3 ;
type = V_2 -> type ;
if ( V_2 -> V_32 . V_109 == 0 && V_2 -> V_32 . V_110 == 0 )
F_15 ( & V_2 -> V_32 ) ;
F_41 ( & V_2 -> V_60 ) ;
if ( V_2 -> V_105 ) {
if ( type == V_17 ) {
error = F_66 ( V_2 ) ;
} else if ( type == V_18 ) {
error = F_65 ( V_2 , V_5 ) ;
} else if ( type == V_19 ) {
error = F_62 ( V_2 , V_5 ) ;
}
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
if ( V_3 )
F_81 ( V_3 ) ;
}
F_79 ( V_45 ) ;
return 0 ;
}
static int F_82 ( struct V_111 * V_112 ,
struct V_113 * V_113 ,
struct V_60 * V_60 )
{
T_1 V_89 ;
int V_74 ;
if ( F_83 ( V_113 ) == 0 ) {
V_74 = - V_114 ;
goto V_71;
}
F_37 ( V_60 ) ;
V_74 = F_84 ( V_113 , & V_89 , sizeof( V_89 ) ) ;
if ( V_74 > 0 ) {
F_85 ( V_112 , L_14 , V_89 ) ;
V_74 = 0 ;
}
F_41 ( V_60 ) ;
V_71:
return V_74 ;
}
static int F_86 ( struct V_111 * V_112 , void * V_115 )
{
struct V_1 * V_2 = V_112 -> V_116 ;
return F_82 ( V_112 , & V_2 -> V_15 ,
& V_2 -> V_60 ) ;
}
static int F_87 ( struct V_117 * V_117 , struct V_118 * V_118 )
{
return F_88 ( V_118 , F_86 ,
V_117 -> V_119 ) ;
}
static int F_89 ( void * V_120 , struct V_121 * V_122 ,
struct V_121 * V_123 )
{
struct V_1 * V_124 = F_90 ( V_122 , struct V_1 , V_52 ) ;
struct V_1 * V_125 = F_90 ( V_123 , struct V_1 , V_52 ) ;
struct V_83 * V_126 = V_124 -> V_41 ;
struct V_83 * V_127 = V_125 -> V_41 ;
if ( V_126 -> V_45 -> V_128 -> V_129 < V_127 -> V_45 -> V_128 -> V_129 )
return - 1 ;
if ( V_127 -> V_45 -> V_128 -> V_129 < V_126 -> V_45 -> V_128 -> V_129 )
return 1 ;
if ( V_126 -> V_45 -> V_57 < V_127 -> V_45 -> V_57 )
return - 1 ;
if ( V_127 -> V_45 -> V_57 < V_126 -> V_45 -> V_57 )
return 1 ;
if ( V_126 -> V_130 < V_127 -> V_130 )
return - 1 ;
else if ( V_127 -> V_130 < V_126 -> V_130 )
return 1 ;
return 0 ;
}
static void F_91 ( struct V_1 * V_2 )
{
struct V_1 * V_131 ;
T_1 V_132 = 0 ;
F_51 ( & V_2 -> V_52 , & V_6 . V_133 ) ;
F_92 ( NULL , & V_6 . V_133 , F_89 ) ;
F_32 (gb_list, &gb_dev.list, entry) {
V_131 -> V_134 = 1 << V_132 ;
V_132 ++ ;
}
}
static int F_93 ( struct V_107 * V_45 ,
const struct V_135 * V_57 )
{
struct V_136 * V_137 ;
struct V_83 * V_41 ;
struct V_1 * V_2 ;
struct V_84 * V_14 ;
int V_74 ;
char V_138 [ V_139 ] ;
unsigned long V_55 ;
if ( V_45 -> V_140 != 1 )
return - V_141 ;
V_137 = & V_45 -> V_137 [ 0 ] ;
if ( V_137 -> V_142 != V_143 )
return - V_141 ;
V_2 = F_48 ( sizeof( * V_2 ) , V_42 ) ;
if ( ! V_2 )
return - V_43 ;
V_41 = F_94 ( V_45 , F_95 ( V_137 -> V_57 ) ,
F_67 ) ;
if ( F_96 ( V_41 ) ) {
V_74 = F_97 ( V_41 ) ;
goto V_144;
}
V_2 -> V_41 = V_41 ;
F_98 ( V_45 , V_2 ) ;
F_99 ( & V_2 -> V_24 ) ;
F_99 ( & V_2 -> V_54 ) ;
F_100 ( & V_2 -> V_53 , 0 ) ;
F_5 ( V_2 ) ;
V_2 -> V_145 = F_101 ( V_22 ) ;
V_2 -> V_146 = F_101 ( V_23 ) ;
if ( ! V_6 . V_98 ) {
V_6 . V_7 = F_102 ( V_41 ) ;
if ( V_6 . V_7 <=
sizeof( struct V_73 ) ) {
V_74 = - V_48 ;
goto V_147;
}
V_6 . V_7 -= sizeof( struct V_73 ) ;
}
snprintf ( V_138 , sizeof( V_138 ) , L_15 ,
F_103 ( & V_41 -> V_45 -> V_14 ) ) ;
V_2 -> V_118 = F_104 ( V_138 , V_148 | V_149 , V_6 . V_150 , V_2 ,
& V_151 ) ;
V_2 -> V_57 = F_105 ( & V_152 , 0 , 0 , V_42 ) ;
if ( V_2 -> V_57 < 0 ) {
V_74 = V_2 -> V_57 ;
goto V_153;
}
V_74 = F_106 ( V_41 ) ;
if ( V_74 )
goto V_154;
V_14 = F_107 ( & V_155 ,
& V_41 -> V_45 -> V_14 ,
F_108 ( 0 , 0 ) , V_2 , V_156 ,
L_16 , V_2 -> V_57 ) ;
if ( F_96 ( V_14 ) ) {
V_74 = F_97 ( V_14 ) ;
goto V_157;
}
V_2 -> V_14 = V_14 ;
if ( F_109 ( & V_2 -> V_15 , V_12 * sizeof( T_1 ) ,
V_42 ) ) {
V_74 = - V_43 ;
goto V_158;
}
if ( F_109 ( & V_2 -> V_16 , V_12 * sizeof( struct V_31 ) * 2 ,
V_42 ) ) {
V_74 = - V_43 ;
goto V_159;
}
F_110 ( & V_2 -> V_60 ) ;
V_2 -> V_160 = F_111 ( F_77 , V_2 , L_17 ) ;
if ( F_96 ( V_2 -> V_160 ) ) {
V_74 = F_97 ( V_2 -> V_160 ) ;
goto V_161;
}
F_28 ( & V_6 . V_56 , V_55 ) ;
F_91 ( V_2 ) ;
V_6 . V_98 ++ ;
F_30 ( & V_6 . V_56 , V_55 ) ;
F_112 ( V_41 ) ;
F_79 ( V_45 ) ;
return 0 ;
V_161:
F_113 ( & V_2 -> V_16 ) ;
V_159:
F_113 ( & V_2 -> V_15 ) ;
V_158:
F_114 ( V_14 ) ;
V_157:
F_115 ( V_41 ) ;
V_154:
F_116 ( & V_152 , V_2 -> V_57 ) ;
V_153:
F_117 ( V_2 -> V_118 ) ;
V_147:
F_118 ( V_41 ) ;
V_144:
F_24 ( V_2 ) ;
return V_74 ;
}
static void F_119 ( struct V_107 * V_45 )
{
struct V_1 * V_2 = F_120 ( V_45 ) ;
unsigned long V_55 ;
int V_40 ;
V_40 = F_78 ( V_45 ) ;
if ( V_40 )
F_121 ( V_45 ) ;
F_115 ( V_2 -> V_41 ) ;
if ( ! F_122 ( V_2 -> V_160 ) )
F_123 ( V_2 -> V_160 ) ;
F_113 ( & V_2 -> V_15 ) ;
F_113 ( & V_2 -> V_16 ) ;
F_124 ( V_2 -> V_41 ) ;
F_117 ( V_2 -> V_118 ) ;
F_33 ( V_2 ) ;
F_28 ( & V_6 . V_56 , V_55 ) ;
V_6 . V_98 -- ;
F_22 ( & V_2 -> V_52 ) ;
F_30 ( & V_6 . V_56 , V_55 ) ;
F_114 ( V_2 -> V_14 ) ;
F_116 ( & V_152 , V_2 -> V_57 ) ;
F_118 ( V_2 -> V_41 ) ;
F_24 ( V_2 ) ;
}
static int F_125 ( void )
{
int V_74 ;
F_126 ( & V_6 . V_133 ) ;
F_126 ( & V_6 . V_68 ) ;
F_127 ( & V_6 . V_56 ) ;
V_6 . V_150 = F_128 ( L_17 , NULL ) ;
V_74 = F_129 ( & V_155 ) ;
if ( V_74 )
goto V_59;
V_74 = F_130 ( & V_162 ) ;
if ( V_74 )
goto V_163;
return 0 ;
V_163:
F_131 ( & V_155 ) ;
V_59:
F_132 ( V_6 . V_150 ) ;
return V_74 ;
}
static void T_5 F_133 ( void )
{
F_132 ( V_6 . V_150 ) ;
F_134 ( & V_162 ) ;
F_131 ( & V_155 ) ;
F_135 ( & V_152 ) ;
}
