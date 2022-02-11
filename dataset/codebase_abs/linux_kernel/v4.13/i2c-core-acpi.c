static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_3 ;
struct V_6 * V_7 = V_5 -> V_7 ;
struct V_8 * V_9 ;
T_1 V_10 ;
if ( V_7 -> V_11 || V_2 -> type != V_12 )
return 1 ;
V_9 = & V_2 -> V_3 . V_13 ;
if ( V_9 -> type != V_14 )
return 1 ;
if ( V_5 -> V_15 != - 1 && V_5 -> V_16 ++ != V_5 -> V_15 )
return 1 ;
V_10 = F_2 ( V_5 -> V_17 ,
V_9 -> V_18 . V_19 ,
& V_5 -> V_20 ) ;
if ( ! F_3 ( V_10 ) )
return 1 ;
V_7 -> V_11 = V_9 -> V_21 ;
V_5 -> V_22 = V_9 -> V_23 ;
if ( V_9 -> V_24 == V_25 )
V_7 -> V_26 |= V_27 ;
return 1 ;
}
static int F_4 ( struct V_28 * V_29 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 = V_5 -> V_7 ;
struct V_30 V_31 ;
int V_32 ;
if ( F_5 ( V_29 ) || ! V_29 -> V_10 . V_33 ||
F_6 ( V_29 ) )
return - V_34 ;
if ( F_7 ( V_29 , V_35 ) == 0 )
return - V_36 ;
memset ( V_7 , 0 , sizeof( * V_7 ) ) ;
V_5 -> V_17 = F_8 ( V_29 ) ;
F_9 ( & V_31 ) ;
V_32 = F_10 ( V_29 , & V_31 ,
F_1 , V_5 ) ;
F_11 ( & V_31 ) ;
if ( V_32 < 0 || ! V_7 -> V_11 )
return - V_34 ;
return 0 ;
}
static int F_12 ( struct V_28 * V_29 ,
struct V_6 * V_7 ,
struct V_37 * V_38 ,
T_2 * V_20 )
{
struct V_30 V_31 ;
struct V_39 * V_40 ;
struct V_4 V_5 ;
int V_32 ;
memset ( & V_5 , 0 , sizeof( V_5 ) ) ;
V_5 . V_7 = V_7 ;
V_5 . V_15 = - 1 ;
V_32 = F_4 ( V_29 , & V_5 ) ;
if ( V_32 )
return V_32 ;
if ( V_38 ) {
if ( F_13 ( & V_38 -> V_41 ) != V_5 . V_20 )
return - V_36 ;
} else {
struct V_28 * V_42 ;
if ( F_14 ( V_5 . V_20 , & V_42 ) )
return - V_36 ;
if ( F_5 ( V_42 ) ||
! V_42 -> V_10 . V_33 )
return - V_36 ;
}
V_7 -> V_43 = F_15 ( V_29 ) ;
if ( V_20 )
* V_20 = V_5 . V_20 ;
F_9 ( & V_31 ) ;
V_32 = F_10 ( V_29 , & V_31 , NULL , NULL ) ;
if ( V_32 < 0 )
return - V_34 ;
F_16 (entry, &resource_list) {
if ( F_17 ( V_40 -> V_44 ) == V_45 ) {
V_7 -> V_46 = V_40 -> V_44 -> V_47 ;
break;
}
}
F_11 ( & V_31 ) ;
F_18 ( V_29 , F_19 ( & V_29 -> V_41 ) , V_7 -> type ,
sizeof( V_7 -> type ) ) ;
return 0 ;
}
static void F_20 ( struct V_37 * V_38 ,
struct V_28 * V_29 ,
struct V_6 * V_7 )
{
V_29 -> V_48 . V_26 . V_49 = true ;
F_21 ( V_29 ) ;
if ( ! F_22 ( V_38 , V_7 ) ) {
V_29 -> V_48 . V_26 . V_49 = false ;
F_23 ( & V_38 -> V_41 ,
L_1 ,
F_19 ( & V_29 -> V_41 ) ) ;
}
}
static T_1 F_24 ( T_2 V_50 , T_3 V_51 ,
void * V_3 , void * * V_52 )
{
struct V_37 * V_38 = V_3 ;
struct V_28 * V_29 ;
struct V_6 V_7 ;
if ( F_14 ( V_50 , & V_29 ) )
return V_53 ;
if ( F_12 ( V_29 , & V_7 , V_38 , NULL ) )
return V_53 ;
F_20 ( V_38 , V_29 , & V_7 ) ;
return V_53 ;
}
void F_25 ( struct V_37 * V_54 )
{
T_1 V_10 ;
if ( ! F_26 ( & V_54 -> V_41 ) )
return;
V_10 = F_27 ( V_55 , V_56 ,
V_57 ,
F_24 , NULL ,
V_54 , NULL ) ;
if ( F_28 ( V_10 ) )
F_29 ( & V_54 -> V_41 , L_2 ) ;
}
const struct V_58 *
F_30 ( const struct V_58 * V_59 ,
struct V_60 * V_61 )
{
if ( ! ( V_61 && V_59 ) )
return NULL ;
return F_31 ( V_59 , & V_61 -> V_41 ) ;
}
static T_1 F_32 ( T_2 V_50 , T_3 V_51 ,
void * V_3 , void * * V_52 )
{
struct V_4 * V_5 = V_3 ;
struct V_28 * V_29 ;
if ( F_14 ( V_50 , & V_29 ) )
return V_53 ;
if ( F_4 ( V_29 , V_5 ) )
return V_53 ;
if ( V_5 -> V_62 != V_5 -> V_20 )
return V_53 ;
if ( V_5 -> V_22 <= V_5 -> V_63 )
V_5 -> V_63 = V_5 -> V_22 ;
return V_53 ;
}
T_3 F_33 ( struct V_64 * V_41 )
{
struct V_4 V_5 ;
struct V_6 V_65 ;
T_1 V_10 ;
if ( ! F_26 ( V_41 ) )
return 0 ;
memset ( & V_5 , 0 , sizeof( V_5 ) ) ;
V_5 . V_62 = F_13 ( V_41 ) ;
V_5 . V_63 = V_66 ;
V_5 . V_7 = & V_65 ;
V_5 . V_15 = - 1 ;
V_10 = F_27 ( V_55 , V_56 ,
V_57 ,
F_32 , NULL ,
& V_5 , NULL ) ;
if ( F_28 ( V_10 ) ) {
F_29 ( V_41 , L_3 ) ;
return 0 ;
}
return V_5 . V_63 != V_66 ? V_5 . V_63 : 0 ;
}
static int F_34 ( struct V_64 * V_41 , void * V_3 )
{
struct V_37 * V_38 = F_35 ( V_41 ) ;
if ( ! V_38 )
return 0 ;
return F_13 ( V_41 ) == ( T_2 ) V_3 ;
}
static int F_36 ( struct V_64 * V_41 , void * V_3 )
{
return F_37 ( V_41 ) == V_3 ;
}
static struct V_37 * F_38 ( T_2 V_50 )
{
struct V_64 * V_41 ;
V_41 = F_39 ( & V_67 , NULL , V_50 ,
F_34 ) ;
return V_41 ? F_35 ( V_41 ) : NULL ;
}
static struct V_60 * F_40 ( struct V_28 * V_29 )
{
struct V_64 * V_41 ;
V_41 = F_39 ( & V_67 , NULL , V_29 ,
F_36 ) ;
return V_41 ? F_41 ( V_41 ) : NULL ;
}
static int F_42 ( struct V_68 * V_69 , unsigned long V_70 ,
void * V_71 )
{
struct V_28 * V_29 = V_71 ;
struct V_6 V_7 ;
T_2 V_20 ;
struct V_37 * V_38 ;
struct V_60 * V_61 ;
switch ( V_70 ) {
case V_72 :
if ( F_12 ( V_29 , & V_7 , NULL , & V_20 ) )
break;
V_38 = F_38 ( V_20 ) ;
if ( ! V_38 )
break;
F_20 ( V_38 , V_29 , & V_7 ) ;
break;
case V_73 :
if ( ! F_6 ( V_29 ) )
break;
V_61 = F_40 ( V_29 ) ;
if ( ! V_61 )
break;
F_43 ( V_61 ) ;
F_44 ( & V_61 -> V_41 ) ;
break;
}
return V_74 ;
}
struct V_60 * F_45 ( struct V_64 * V_41 , int V_15 ,
struct V_6 * V_7 )
{
struct V_4 V_5 ;
struct V_37 * V_38 ;
struct V_28 * V_29 ;
F_46 ( V_31 ) ;
int V_32 ;
V_29 = F_37 ( V_41 ) ;
if ( ! V_29 )
return NULL ;
memset ( & V_5 , 0 , sizeof( V_5 ) ) ;
V_5 . V_7 = V_7 ;
V_5 . V_17 = F_8 ( V_29 ) ;
V_5 . V_15 = V_15 ;
V_32 = F_10 ( V_29 , & V_31 ,
F_1 , & V_5 ) ;
F_11 ( & V_31 ) ;
if ( V_32 < 0 || ! V_7 -> V_11 )
return NULL ;
V_38 = F_38 ( V_5 . V_20 ) ;
if ( ! V_38 )
return NULL ;
return F_22 ( V_38 , V_7 ) ;
}
static int F_47 ( struct V_60 * V_61 ,
T_4 V_75 , T_4 * V_3 , T_4 V_76 )
{
struct V_77 V_78 [ 2 ] ;
int V_32 ;
T_4 * V_79 ;
V_79 = F_48 ( V_76 , V_80 ) ;
if ( ! V_79 )
return V_81 ;
V_78 [ 0 ] . V_11 = V_61 -> V_11 ;
V_78 [ 0 ] . V_26 = V_61 -> V_26 ;
V_78 [ 0 ] . V_82 = 1 ;
V_78 [ 0 ] . V_83 = & V_75 ;
V_78 [ 1 ] . V_11 = V_61 -> V_11 ;
V_78 [ 1 ] . V_26 = V_61 -> V_26 | V_84 ;
V_78 [ 1 ] . V_82 = V_76 ;
V_78 [ 1 ] . V_83 = V_79 ;
V_32 = F_49 ( V_61 -> V_38 , V_78 , F_50 ( V_78 ) ) ;
if ( V_32 < 0 )
F_23 ( & V_61 -> V_38 -> V_41 , L_4 ) ;
else
memcpy ( V_3 , V_79 , V_76 ) ;
F_51 ( V_79 ) ;
return V_32 ;
}
static int F_52 ( struct V_60 * V_61 ,
T_4 V_75 , T_4 * V_3 , T_4 V_76 )
{
struct V_77 V_78 [ 1 ] ;
T_4 * V_79 ;
int V_32 = V_53 ;
V_79 = F_48 ( V_76 + 1 , V_80 ) ;
if ( ! V_79 )
return V_81 ;
V_79 [ 0 ] = V_75 ;
memcpy ( V_79 + 1 , V_3 , V_76 ) ;
V_78 [ 0 ] . V_11 = V_61 -> V_11 ;
V_78 [ 0 ] . V_26 = V_61 -> V_26 ;
V_78 [ 0 ] . V_82 = V_76 + 1 ;
V_78 [ 0 ] . V_83 = V_79 ;
V_32 = F_49 ( V_61 -> V_38 , V_78 , F_50 ( V_78 ) ) ;
if ( V_32 < 0 )
F_23 ( & V_61 -> V_38 -> V_41 , L_5 ) ;
F_51 ( V_79 ) ;
return V_32 ;
}
static T_1
F_53 ( T_3 V_85 , T_5 V_86 ,
T_3 V_87 , T_6 * V_88 ,
void * V_89 , void * V_90 )
{
struct V_91 * V_92 = (struct V_91 * ) V_88 ;
struct V_93 * V_3 = V_89 ;
struct V_94 * V_7 = & V_3 -> V_7 ;
struct V_8 * V_9 ;
struct V_37 * V_38 = V_3 -> V_38 ;
struct V_60 * V_61 ;
struct V_1 * V_2 ;
T_3 V_95 = V_85 >> 16 ;
T_4 V_96 = V_85 & V_97 ;
T_1 V_32 ;
int V_10 ;
V_32 = F_54 ( V_7 -> V_98 , V_7 -> V_99 , & V_2 ) ;
if ( F_28 ( V_32 ) )
return V_32 ;
V_61 = F_48 ( sizeof( * V_61 ) , V_80 ) ;
if ( ! V_61 ) {
V_32 = V_81 ;
goto V_100;
}
if ( ! V_88 || V_2 -> type != V_12 ) {
V_32 = V_101 ;
goto V_100;
}
V_9 = & V_2 -> V_3 . V_13 ;
if ( V_9 -> type != V_14 ) {
V_32 = V_101 ;
goto V_100;
}
V_61 -> V_38 = V_38 ;
V_61 -> V_11 = V_9 -> V_21 ;
if ( V_9 -> V_24 == V_25 )
V_61 -> V_26 |= V_27 ;
switch ( V_95 ) {
case V_102 :
if ( V_96 == V_103 ) {
V_10 = F_55 ( V_61 ) ;
if ( V_10 >= 0 ) {
V_92 -> V_104 = V_10 ;
V_10 = 0 ;
}
} else {
V_10 = F_56 ( V_61 , V_92 -> V_104 ) ;
}
break;
case V_105 :
if ( V_96 == V_103 ) {
V_10 = F_57 ( V_61 , V_86 ) ;
if ( V_10 >= 0 ) {
V_92 -> V_104 = V_10 ;
V_10 = 0 ;
}
} else {
V_10 = F_58 ( V_61 , V_86 ,
V_92 -> V_104 ) ;
}
break;
case V_106 :
if ( V_96 == V_103 ) {
V_10 = F_59 ( V_61 , V_86 ) ;
if ( V_10 >= 0 ) {
V_92 -> V_107 = V_10 ;
V_10 = 0 ;
}
} else {
V_10 = F_60 ( V_61 , V_86 ,
V_92 -> V_107 ) ;
}
break;
case V_108 :
if ( V_96 == V_103 ) {
V_10 = F_61 ( V_61 , V_86 ,
V_92 -> V_3 ) ;
if ( V_10 >= 0 ) {
V_92 -> V_82 = V_10 ;
V_10 = 0 ;
}
} else {
V_10 = F_62 ( V_61 , V_86 ,
V_92 -> V_82 , V_92 -> V_3 ) ;
}
break;
case V_109 :
if ( V_96 == V_103 ) {
V_10 = F_47 ( V_61 , V_86 ,
V_92 -> V_3 , V_7 -> V_110 ) ;
if ( V_10 > 0 )
V_10 = 0 ;
} else {
V_10 = F_52 ( V_61 , V_86 ,
V_92 -> V_3 , V_7 -> V_110 ) ;
}
break;
default:
F_29 ( & V_38 -> V_41 , L_6 ,
V_95 , V_61 -> V_11 ) ;
V_32 = V_101 ;
goto V_100;
}
V_92 -> V_10 = V_10 ;
V_100:
F_51 ( V_61 ) ;
F_63 ( V_2 ) ;
return V_32 ;
}
int F_64 ( struct V_37 * V_38 )
{
T_2 V_50 ;
struct V_93 * V_3 ;
T_1 V_10 ;
if ( ! V_38 -> V_41 . V_111 )
return - V_36 ;
V_50 = F_13 ( V_38 -> V_41 . V_111 ) ;
if ( ! V_50 )
return - V_36 ;
V_3 = F_48 ( sizeof( struct V_93 ) ,
V_80 ) ;
if ( ! V_3 )
return - V_112 ;
V_3 -> V_38 = V_38 ;
V_10 = F_65 ( V_50 , ( void * ) V_3 ) ;
if ( F_28 ( V_10 ) ) {
F_51 ( V_3 ) ;
return - V_112 ;
}
V_10 = F_66 ( V_50 ,
V_113 ,
& F_53 ,
NULL ,
V_3 ) ;
if ( F_28 ( V_10 ) ) {
F_23 ( & V_38 -> V_41 , L_7 ) ;
F_67 ( V_50 ) ;
F_51 ( V_3 ) ;
return - V_112 ;
}
F_68 ( V_50 ) ;
return 0 ;
}
void F_69 ( struct V_37 * V_38 )
{
T_2 V_50 ;
struct V_93 * V_3 ;
T_1 V_10 ;
if ( ! V_38 -> V_41 . V_111 )
return;
V_50 = F_13 ( V_38 -> V_41 . V_111 ) ;
if ( ! V_50 )
return;
F_70 ( V_50 ,
V_113 ,
& F_53 ) ;
V_10 = F_71 ( V_50 , ( void * * ) & V_3 ) ;
if ( F_3 ( V_10 ) )
F_51 ( V_3 ) ;
F_67 ( V_50 ) ;
}
