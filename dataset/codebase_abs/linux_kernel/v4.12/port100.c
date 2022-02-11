static inline T_1 F_1 ( T_2 V_1 )
{
return ~ ( ( ( T_1 * ) & V_1 ) [ 0 ] + ( ( T_1 * ) & V_1 ) [ 1 ] ) + 1 ;
}
static T_1 F_2 ( T_1 * V_2 , int V_3 )
{
T_1 V_4 = 0 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_3 ; V_5 ++ )
V_4 += V_2 [ V_5 ] ;
return F_1 ( V_4 ) ;
}
static void F_3 ( void * V_6 , T_1 V_7 )
{
struct V_8 * V_9 = V_6 ;
V_9 -> V_10 = 0 ;
V_9 -> V_11 = F_4 ( V_12 ) ;
V_9 -> V_13 = F_4 ( V_14 ) ;
F_5 ( V_9 ) = V_15 ;
F_6 ( V_9 ) = V_7 ;
V_9 -> V_3 = F_7 ( 2 ) ;
}
static void F_8 ( void * V_6 )
{
struct V_8 * V_9 = V_6 ;
V_9 -> V_16 = F_1 ( F_9 ( V_9 -> V_3 ) ) ;
F_10 ( V_9 ) =
F_2 ( V_9 -> V_2 , F_9 ( V_9 -> V_3 ) ) ;
F_11 ( V_9 ) = 0 ;
}
static void F_12 ( void * V_6 , int V_17 )
{
struct V_8 * V_9 = V_6 ;
V_9 -> V_3 = F_7 ( F_9 ( V_9 -> V_3 ) + V_17 ) ;
}
static bool F_13 ( void * V_6 )
{
T_1 V_18 ;
struct V_8 * V_9 = V_6 ;
if ( V_9 -> V_11 != F_4 ( V_12 ) ||
V_9 -> V_13 != F_4 ( V_14 ) )
return false ;
V_18 = F_1 ( F_9 ( V_9 -> V_3 ) ) ;
if ( V_18 != V_9 -> V_16 )
return false ;
V_18 = F_2 ( V_9 -> V_2 ,
F_9 ( V_9 -> V_3 ) ) ;
if ( V_18 != F_10 ( V_9 ) )
return false ;
return true ;
}
static bool F_14 ( struct V_19 * V_9 )
{
return ( V_9 -> V_11 == F_4 ( V_12 ) &&
V_9 -> V_20 == F_4 ( V_21 ) ) ;
}
static inline int F_15 ( void * V_9 )
{
struct V_8 * V_22 = V_9 ;
return sizeof( struct V_8 ) + F_9 ( V_22 -> V_3 ) +
V_23 ;
}
static bool F_16 ( struct V_24 * V_25 , void * V_9 )
{
struct V_8 * V_22 = V_9 ;
return ( F_6 ( V_22 ) == F_17 ( V_25 -> V_26 -> V_27 ) ) ;
}
static void F_18 ( struct V_28 * V_28 )
{
struct V_24 * V_25 = V_28 -> V_29 ;
struct V_30 * V_26 = V_25 -> V_26 ;
T_1 * V_31 ;
V_26 -> V_32 = V_28 -> V_32 ;
switch ( V_28 -> V_32 ) {
case 0 :
break;
case - V_33 :
case - V_34 :
F_19 ( & V_25 -> V_35 -> V_25 ,
L_1 , V_28 -> V_32 ) ;
goto V_36;
case - V_37 :
default:
F_19 ( & V_25 -> V_35 -> V_25 , L_2 ,
V_28 -> V_32 ) ;
goto V_36;
}
V_31 = V_25 -> V_38 -> V_39 ;
if ( ! F_13 ( V_31 ) ) {
F_19 ( & V_25 -> V_35 -> V_25 , L_3 ) ;
V_26 -> V_32 = - V_40 ;
goto V_36;
}
F_20 ( L_4 , V_41 , 16 , 1 , V_31 ,
F_15 ( V_31 ) , false ) ;
if ( ! F_16 ( V_25 , V_31 ) ) {
F_19 ( & V_25 -> V_35 -> V_25 ,
L_5 ) ;
V_26 -> V_32 = - V_40 ;
goto V_36;
}
V_36:
F_21 ( & V_25 -> V_42 ) ;
}
static int F_22 ( struct V_24 * V_25 , T_3 V_43 )
{
V_25 -> V_38 -> V_44 = F_18 ;
return F_23 ( V_25 -> V_38 , V_43 ) ;
}
static void F_24 ( struct V_28 * V_28 )
{
struct V_24 * V_25 = V_28 -> V_29 ;
struct V_30 * V_26 = V_25 -> V_26 ;
struct V_19 * V_31 ;
int V_45 ;
V_26 -> V_32 = V_28 -> V_32 ;
switch ( V_28 -> V_32 ) {
case 0 :
break;
case - V_33 :
case - V_34 :
F_19 ( & V_25 -> V_35 -> V_25 ,
L_6 , V_28 -> V_32 ) ;
goto V_36;
case - V_37 :
default:
F_19 ( & V_25 -> V_35 -> V_25 , L_2 ,
V_28 -> V_32 ) ;
goto V_36;
}
V_31 = V_25 -> V_38 -> V_39 ;
if ( ! F_14 ( V_31 ) ) {
F_19 ( & V_25 -> V_35 -> V_25 , L_7 ) ;
V_26 -> V_32 = - V_40 ;
goto V_36;
}
V_45 = F_22 ( V_25 , V_46 ) ;
if ( V_45 ) {
F_19 ( & V_25 -> V_35 -> V_25 ,
L_8 , V_45 ) ;
V_26 -> V_32 = V_45 ;
goto V_36;
}
return;
V_36:
F_21 ( & V_25 -> V_42 ) ;
}
static int F_25 ( struct V_24 * V_25 , T_3 V_43 )
{
V_25 -> V_38 -> V_44 = F_24 ;
return F_23 ( V_25 -> V_38 , V_43 ) ;
}
static int F_26 ( struct V_24 * V_25 )
{
int V_45 = 0 ;
F_27 ( & V_25 -> V_47 ) ;
if ( ! V_25 -> V_48 ) {
F_28 ( & V_25 -> V_49 ) ;
F_29 ( V_25 -> V_50 ) ;
V_25 -> V_50 -> V_39 = V_20 ;
V_25 -> V_50 -> V_51 = sizeof( V_20 ) ;
V_45 = F_23 ( V_25 -> V_50 , V_52 ) ;
V_25 -> V_48 = ! V_45 ;
}
F_30 ( & V_25 -> V_47 ) ;
if ( ! V_45 )
F_31 ( & V_25 -> V_49 ) ;
return V_45 ;
}
static int F_32 ( struct V_24 * V_25 , struct V_53 * V_54 ,
struct V_53 * V_55 , int V_56 )
{
int V_45 ;
F_27 ( & V_25 -> V_47 ) ;
if ( V_25 -> V_48 ) {
V_45 = - V_57 ;
goto exit;
}
V_25 -> V_50 -> V_39 = V_54 -> V_2 ;
V_25 -> V_50 -> V_51 = V_54 -> V_17 ;
V_25 -> V_38 -> V_39 = V_55 -> V_2 ;
V_25 -> V_38 -> V_51 = V_56 ;
F_20 ( L_9 , V_41 , 16 , 1 ,
V_54 -> V_2 , V_54 -> V_17 , false ) ;
V_45 = F_23 ( V_25 -> V_50 , V_52 ) ;
if ( V_45 )
goto exit;
V_45 = F_25 ( V_25 , V_52 ) ;
if ( V_45 )
F_33 ( V_25 -> V_50 ) ;
exit:
F_30 ( & V_25 -> V_47 ) ;
return V_45 ;
}
static void F_34 ( struct V_24 * V_25 , T_1 V_7 ,
struct V_53 * V_58 )
{
int V_59 = V_58 -> V_17 ;
F_35 ( V_58 , V_60 ) ;
F_36 ( V_58 , V_23 ) ;
F_3 ( V_58 -> V_2 , V_7 ) ;
F_12 ( V_58 -> V_2 , V_59 ) ;
F_8 ( V_58 -> V_2 ) ;
}
static void F_37 ( struct V_24 * V_25 )
{
struct V_30 * V_26 = V_25 -> V_26 ;
int V_32 = V_26 -> V_32 ;
struct V_53 * V_61 = V_26 -> V_61 ;
struct V_53 * V_62 = V_26 -> V_62 ;
F_38 ( V_61 ) ;
V_25 -> V_26 = NULL ;
if ( V_32 < 0 ) {
V_26 -> V_63 ( V_25 , V_26 -> V_64 ,
F_39 ( V_32 ) ) ;
F_38 ( V_62 ) ;
goto V_65;
}
F_36 ( V_62 , F_15 ( V_62 -> V_2 ) ) ;
F_40 ( V_62 , V_60 ) ;
F_41 ( V_62 , V_62 -> V_17 - V_23 ) ;
V_26 -> V_63 ( V_25 , V_26 -> V_64 , V_62 ) ;
V_65:
F_42 ( V_26 ) ;
}
static int F_43 ( struct V_24 * V_25 , T_1 V_7 ,
struct V_53 * V_61 ,
T_4 V_63 ,
void * V_64 )
{
struct V_30 * V_26 ;
struct V_53 * V_62 ;
int V_45 ;
int V_66 = V_60 +
V_67 +
V_23 ;
if ( V_25 -> V_26 ) {
F_19 ( & V_25 -> V_35 -> V_25 ,
L_10 ) ;
return - V_68 ;
}
V_62 = F_44 ( V_66 , V_52 ) ;
if ( ! V_62 )
return - V_69 ;
V_26 = F_45 ( sizeof( * V_26 ) , V_52 ) ;
if ( ! V_26 ) {
F_38 ( V_62 ) ;
return - V_69 ;
}
V_26 -> V_27 = V_7 ;
V_26 -> V_61 = V_61 ;
V_26 -> V_62 = V_62 ;
V_26 -> V_66 = V_66 ;
V_26 -> V_63 = V_63 ;
V_26 -> V_64 = V_64 ;
F_34 ( V_25 , V_7 , V_61 ) ;
V_25 -> V_26 = V_26 ;
V_45 = F_32 ( V_25 , V_61 , V_62 , V_66 ) ;
if ( V_45 ) {
F_42 ( V_26 ) ;
F_38 ( V_62 ) ;
V_25 -> V_26 = NULL ;
}
return V_45 ;
}
static void F_46 ( struct V_70 * V_71 )
{
struct V_24 * V_25 = F_47 ( V_71 , struct V_24 ,
V_42 ) ;
F_37 ( V_25 ) ;
}
static void F_48 ( struct V_24 * V_25 , void * V_72 ,
struct V_53 * V_62 )
{
struct V_73 * V_74 = V_72 ;
V_74 -> V_62 = V_62 ;
V_44 ( & V_74 -> V_65 ) ;
}
static struct V_53 * F_49 ( struct V_24 * V_25 , T_1 V_7 ,
struct V_53 * V_61 )
{
int V_45 ;
struct V_73 V_74 ;
F_50 ( & V_74 . V_65 ) ;
V_45 = F_43 ( V_25 , V_7 , V_61 ,
F_48 , & V_74 ) ;
if ( V_45 ) {
F_38 ( V_61 ) ;
return F_39 ( V_45 ) ;
}
F_31 ( & V_74 . V_65 ) ;
return V_74 . V_62 ;
}
static void F_51 ( struct V_28 * V_28 )
{
struct V_24 * V_25 = V_28 -> V_29 ;
if ( V_25 -> V_48 ) {
F_52 ( & V_25 -> V_49 ) ;
V_25 -> V_48 = false ;
}
switch ( V_28 -> V_32 ) {
case 0 :
break;
case - V_33 :
case - V_34 :
F_19 ( & V_25 -> V_35 -> V_25 ,
L_6 , V_28 -> V_32 ) ;
break;
case - V_37 :
default:
F_19 ( & V_25 -> V_35 -> V_25 , L_2 ,
V_28 -> V_32 ) ;
}
}
static void F_53 ( struct V_75 * V_76 )
{
struct V_24 * V_25 = F_54 ( V_76 ) ;
F_26 ( V_25 ) ;
F_29 ( V_25 -> V_38 ) ;
}
static struct V_53 * F_55 ( struct V_24 * V_25 , unsigned int V_77 )
{
struct V_53 * V_58 ;
V_58 = F_44 ( V_25 -> V_78 + V_25 -> V_79 + V_77 ,
V_52 ) ;
if ( V_58 )
F_56 ( V_58 , V_25 -> V_78 ) ;
return V_58 ;
}
static int F_57 ( struct V_24 * V_25 , T_1 V_80 )
{
struct V_53 * V_58 ;
struct V_53 * V_62 ;
int V_45 ;
V_58 = F_55 ( V_25 , 1 ) ;
if ( ! V_58 )
return - V_69 ;
* F_36 ( V_58 , sizeof( T_1 ) ) = V_80 ;
V_62 = F_49 ( V_25 , V_81 , V_58 ) ;
if ( F_58 ( V_62 ) )
return F_59 ( V_62 ) ;
V_45 = V_62 -> V_2 [ 0 ] ;
F_38 ( V_62 ) ;
return V_45 ;
}
static T_5 F_60 ( struct V_24 * V_25 )
{
struct V_53 * V_58 ;
struct V_53 * V_62 ;
T_5 V_82 ;
V_58 = F_55 ( V_25 , 0 ) ;
if ( ! V_58 )
return - V_69 ;
V_62 = F_49 ( V_25 , V_83 , V_58 ) ;
if ( F_58 ( V_62 ) )
return F_59 ( V_62 ) ;
if ( V_62 -> V_17 < 8 )
V_82 = 0 ;
else
V_82 = F_61 ( * ( V_84 * ) V_62 -> V_2 ) ;
F_38 ( V_62 ) ;
return V_82 ;
}
static T_2 F_62 ( struct V_24 * V_25 )
{
struct V_53 * V_58 ;
struct V_53 * V_62 ;
T_2 V_85 ;
V_58 = F_55 ( V_25 , 0 ) ;
if ( ! V_58 )
return 0 ;
V_62 = F_49 ( V_25 , V_86 ,
V_58 ) ;
if ( F_58 ( V_62 ) )
return 0 ;
V_85 = F_9 ( * ( V_87 * ) V_62 -> V_2 ) ;
F_38 ( V_62 ) ;
return V_85 ;
}
static int F_63 ( struct V_75 * V_76 , bool V_88 )
{
struct V_24 * V_25 = F_54 ( V_76 ) ;
struct V_53 * V_58 , * V_62 ;
V_58 = F_55 ( V_25 , 1 ) ;
if ( ! V_58 )
return - V_69 ;
* F_36 ( V_58 , 1 ) = V_88 ? 1 : 0 ;
if ( ! V_88 )
F_53 ( V_76 ) ;
V_62 = F_49 ( V_25 , V_89 , V_58 ) ;
if ( F_58 ( V_62 ) )
return F_59 ( V_62 ) ;
F_38 ( V_62 ) ;
return 0 ;
}
static int F_64 ( struct V_75 * V_76 , T_1 V_90 )
{
struct V_24 * V_25 = F_54 ( V_76 ) ;
struct V_53 * V_58 ;
struct V_53 * V_62 ;
int V_45 ;
if ( V_90 >= V_91 )
return - V_92 ;
V_58 = F_55 ( V_25 , sizeof( struct V_93 ) ) ;
if ( ! V_58 )
return - V_69 ;
memcpy ( F_36 ( V_58 , sizeof( struct V_93 ) ) ,
& V_94 [ V_90 ] ,
sizeof( struct V_93 ) ) ;
V_62 = F_49 ( V_25 , V_95 , V_58 ) ;
if ( F_58 ( V_62 ) )
return F_59 ( V_62 ) ;
V_45 = V_62 -> V_2 [ 0 ] ;
F_38 ( V_62 ) ;
return V_45 ;
}
static int F_65 ( struct V_75 * V_76 , int V_96 )
{
struct V_24 * V_25 = F_54 ( V_76 ) ;
struct V_97 * V_98 ;
struct V_53 * V_58 ;
struct V_53 * V_62 ;
int V_99 ;
T_6 V_77 ;
int V_45 ;
if ( V_96 >= V_100 )
return - V_92 ;
V_98 = V_101 [ V_96 ] ;
V_99 = 0 ;
while ( V_98 [ V_99 ] . V_102 != V_103 )
V_99 ++ ;
if ( ! V_99 )
return 0 ;
V_77 = sizeof( struct V_97 ) * V_99 ;
V_58 = F_55 ( V_25 , V_77 ) ;
if ( ! V_58 )
return - V_69 ;
memcpy ( F_36 ( V_58 , V_77 ) , V_98 , V_77 ) ;
V_62 = F_49 ( V_25 , V_104 , V_58 ) ;
if ( F_58 ( V_62 ) )
return F_59 ( V_62 ) ;
V_45 = V_62 -> V_2 [ 0 ] ;
F_38 ( V_62 ) ;
return V_45 ;
}
static int F_66 ( struct V_75 * V_76 , int type ,
int V_96 )
{
if ( type == V_105 )
return F_64 ( V_76 , V_96 ) ;
if ( type == V_106 )
return F_65 ( V_76 , V_96 ) ;
return - V_92 ;
}
static void F_67 ( struct V_24 * V_25 , void * V_74 ,
struct V_53 * V_62 )
{
struct V_107 * V_108 = V_74 ;
T_7 V_109 = V_108 -> V_63 ;
T_8 V_32 ;
int V_45 ;
if ( F_58 ( V_62 ) ) {
V_45 = F_59 ( V_62 ) ;
goto exit;
}
if ( V_62 -> V_17 < 4 ) {
F_19 ( & V_25 -> V_35 -> V_25 ,
L_11 ) ;
V_45 = - V_40 ;
goto error;
}
V_32 = F_68 ( * ( V_110 * ) V_62 -> V_2 ) ;
F_40 ( V_62 , sizeof( T_8 ) ) ;
if ( V_32 == V_111 ) {
V_45 = - V_112 ;
goto error;
}
if ( V_32 != V_113 ) {
F_19 ( & V_25 -> V_35 -> V_25 ,
L_12 , V_32 ) ;
V_45 = - V_40 ;
goto error;
}
F_40 ( V_62 , 1 ) ;
goto exit;
error:
F_69 ( V_62 ) ;
V_62 = F_39 ( V_45 ) ;
exit:
V_109 ( V_25 -> V_75 , V_108 -> V_114 , V_62 ) ;
F_42 ( V_108 ) ;
}
static int F_70 ( struct V_75 * V_76 ,
struct V_53 * V_58 , T_2 V_115 ,
T_7 V_109 , void * V_74 )
{
struct V_24 * V_25 = F_54 ( V_76 ) ;
struct V_107 * V_108 ;
V_87 V_116 ;
V_108 = F_45 ( sizeof( struct V_107 ) , V_52 ) ;
if ( ! V_108 )
return - V_69 ;
V_108 -> V_63 = V_109 ;
V_108 -> V_114 = V_74 ;
V_116 = F_7 ( V_115 * 10 ) ;
memcpy ( F_35 ( V_58 , sizeof( V_87 ) ) , & V_116 , sizeof( V_87 ) ) ;
return F_43 ( V_25 , V_117 , V_58 ,
F_67 , V_108 ) ;
}
static int F_71 ( struct V_75 * V_76 , T_1 V_90 )
{
struct V_24 * V_25 = F_54 ( V_76 ) ;
struct V_53 * V_58 ;
struct V_53 * V_62 ;
int V_45 ;
if ( V_90 >= V_91 )
return - V_92 ;
V_58 = F_55 ( V_25 , sizeof( struct V_118 ) ) ;
if ( ! V_58 )
return - V_69 ;
memcpy ( F_36 ( V_58 , sizeof( struct V_118 ) ) ,
& V_119 [ V_90 ] ,
sizeof( struct V_118 ) ) ;
V_62 = F_49 ( V_25 , V_120 , V_58 ) ;
if ( F_58 ( V_62 ) )
return F_59 ( V_62 ) ;
V_45 = V_62 -> V_2 [ 0 ] ;
F_38 ( V_62 ) ;
return V_45 ;
}
static int F_72 ( struct V_75 * V_76 , int V_96 )
{
struct V_24 * V_25 = F_54 ( V_76 ) ;
struct V_97 * V_98 ;
struct V_53 * V_58 ;
struct V_53 * V_62 ;
int V_45 ;
int V_99 ;
T_6 V_77 ;
if ( V_96 >= V_100 )
return - V_92 ;
V_98 = V_121 [ V_96 ] ;
V_99 = 0 ;
while ( V_98 [ V_99 ] . V_102 != V_122 )
V_99 ++ ;
if ( ! V_99 )
return 0 ;
V_77 = sizeof( struct V_97 ) * V_99 ;
V_58 = F_55 ( V_25 , V_77 ) ;
if ( ! V_58 )
return - V_69 ;
memcpy ( F_36 ( V_58 , V_77 ) , V_98 , V_77 ) ;
V_62 = F_49 ( V_25 , V_123 , V_58 ) ;
if ( F_58 ( V_62 ) )
return F_59 ( V_62 ) ;
V_45 = V_62 -> V_2 [ 0 ] ;
F_38 ( V_62 ) ;
return V_45 ;
}
static int F_73 ( struct V_75 * V_76 , int type ,
int V_96 )
{
if ( type == V_105 )
return F_71 ( V_76 , V_96 ) ;
if ( type == V_106 )
return F_72 ( V_76 , V_96 ) ;
return - V_92 ;
}
static bool F_74 ( struct V_24 * V_25 , T_1 V_124 )
{
T_1 V_82 ;
switch ( V_25 -> V_125 ) {
case V_126 :
V_82 = V_127 ;
break;
case V_128 :
V_82 = V_127 |
V_129 ;
break;
default:
F_19 ( & V_25 -> V_35 -> V_25 , L_13 ) ;
return false ;
}
return ( ( V_124 & V_82 ) == V_82 ) ;
}
static void F_75 ( struct V_24 * V_25 , void * V_74 ,
struct V_53 * V_62 )
{
T_8 V_32 ;
struct V_107 * V_108 = V_74 ;
T_7 V_109 = V_108 -> V_63 ;
struct V_130 * V_131 ;
if ( F_58 ( V_62 ) )
goto exit;
V_131 = (struct V_130 * ) V_62 -> V_2 ;
V_32 = F_68 ( V_131 -> V_32 ) ;
if ( V_108 -> V_132 &&
! F_74 ( V_25 , V_131 -> V_133 ) ) {
F_69 ( V_62 ) ;
V_62 = F_39 ( - V_112 ) ;
goto exit;
}
F_40 ( V_62 , sizeof( struct V_130 ) ) ;
if ( V_32 != V_113 ) {
F_69 ( V_62 ) ;
if ( V_32 == V_111 )
V_62 = F_39 ( - V_112 ) ;
else
V_62 = F_39 ( - V_40 ) ;
}
exit:
V_109 ( V_25 -> V_75 , V_108 -> V_114 , V_62 ) ;
F_42 ( V_108 ) ;
}
static int F_76 ( struct V_75 * V_76 ,
struct V_53 * V_58 , T_2 V_116 ,
T_7 V_109 , void * V_74 )
{
struct V_24 * V_25 = F_54 ( V_76 ) ;
struct V_134 * V_131 ;
struct V_107 * V_108 ;
V_108 = F_45 ( sizeof( struct V_107 ) , V_52 ) ;
if ( ! V_108 )
return - V_69 ;
V_108 -> V_63 = V_109 ;
V_108 -> V_114 = V_74 ;
F_35 ( V_58 , sizeof( struct V_134 ) ) ;
V_131 = (struct V_134 * ) V_58 -> V_2 ;
memset ( V_131 , 0 , sizeof( struct V_134 ) ) ;
V_131 -> V_135 = F_7 ( 500 ) ;
V_131 -> V_136 = F_7 ( 0xFFFF ) ;
V_131 -> V_137 = F_7 ( V_116 ) ;
return F_43 ( V_25 , V_138 , V_58 ,
F_75 , V_108 ) ;
}
static int F_77 ( struct V_75 * V_76 ,
struct V_139 * V_140 ,
T_2 V_116 ,
T_7 V_109 , void * V_74 )
{
struct V_24 * V_25 = F_54 ( V_76 ) ;
struct V_134 * V_131 ;
struct V_107 * V_108 ;
struct V_53 * V_58 ;
int V_45 ;
V_45 = F_73 ( V_76 , V_105 ,
V_141 ) ;
if ( V_45 )
return V_45 ;
V_45 = F_73 ( V_76 , V_106 ,
V_142 ) ;
if ( V_45 )
return V_45 ;
V_108 = F_45 ( sizeof( struct V_107 ) , V_52 ) ;
if ( ! V_108 )
return - V_69 ;
V_108 -> V_63 = V_109 ;
V_108 -> V_114 = V_74 ;
V_108 -> V_132 = 1 ;
V_58 = F_55 ( V_25 , 0 ) ;
if ( ! V_58 ) {
F_42 ( V_108 ) ;
return - V_69 ;
}
F_35 ( V_58 , sizeof( struct V_134 ) ) ;
V_131 = (struct V_134 * ) V_58 -> V_2 ;
memset ( V_131 , 0 , sizeof( struct V_134 ) ) ;
V_131 -> V_135 = 0 ;
V_131 -> V_136 = F_7 ( 0xFFFF ) ;
V_131 -> V_132 = 1 ;
V_131 -> V_143 [ 0 ] = ( V_140 -> V_144 >> 8 ) & 0xFF ;
V_131 -> V_143 [ 1 ] = V_140 -> V_144 & 0xFF ;
memcpy ( V_131 -> V_143 + 2 , V_140 -> V_145 , 3 ) ;
V_131 -> V_143 [ 5 ] = V_140 -> V_146 ;
memcpy ( V_131 -> V_147 , V_140 -> V_148 , 8 ) ;
V_131 -> V_147 [ 16 ] = ( V_140 -> V_149 >> 8 ) & 0xFF ;
V_131 -> V_147 [ 17 ] = V_140 -> V_149 & 0xFF ;
V_131 -> V_137 = F_7 ( V_116 ) ;
return F_43 ( V_25 , V_138 , V_58 ,
F_75 , V_108 ) ;
}
static int F_78 ( struct V_75 * V_76 , T_2 V_116 ,
T_7 V_109 , void * V_74 )
{
struct V_24 * V_25 = F_54 ( V_76 ) ;
struct V_53 * V_58 ;
V_58 = F_55 ( V_25 , 0 ) ;
if ( ! V_58 )
return - V_69 ;
return F_76 ( V_76 , V_58 , V_116 , V_109 , V_74 ) ;
}
static int F_79 ( struct V_150 * V_35 ,
const struct V_151 * V_152 )
{
struct V_24 * V_25 ;
int V_45 ;
struct V_153 * V_154 ;
struct V_155 * V_156 ;
int V_157 ;
int V_158 ;
T_2 V_159 ;
T_5 V_160 ;
int V_5 ;
V_25 = F_80 ( & V_35 -> V_25 , sizeof( struct V_24 ) , V_52 ) ;
if ( ! V_25 )
return - V_69 ;
F_81 ( & V_25 -> V_47 ) ;
V_25 -> V_161 = F_82 ( F_83 ( V_35 ) ) ;
V_25 -> V_35 = V_35 ;
F_84 ( V_35 , V_25 ) ;
V_157 = V_158 = 0 ;
V_154 = V_35 -> V_162 ;
for ( V_5 = 0 ; V_5 < V_154 -> V_163 . V_164 ; ++ V_5 ) {
V_156 = & V_154 -> V_156 [ V_5 ] . V_163 ;
if ( ! V_157 && F_85 ( V_156 ) )
V_157 = V_156 -> V_165 ;
if ( ! V_158 && F_86 ( V_156 ) )
V_158 = V_156 -> V_165 ;
}
if ( ! V_157 || ! V_158 ) {
F_19 ( & V_35 -> V_25 ,
L_14 ) ;
V_45 = - V_166 ;
goto error;
}
V_25 -> V_38 = F_87 ( 0 , V_52 ) ;
V_25 -> V_50 = F_87 ( 0 , V_52 ) ;
if ( ! V_25 -> V_38 || ! V_25 -> V_50 ) {
F_19 ( & V_35 -> V_25 , L_15 ) ;
V_45 = - V_69 ;
goto error;
}
F_88 ( V_25 -> V_38 , V_25 -> V_161 ,
F_89 ( V_25 -> V_161 , V_157 ) ,
NULL , 0 , NULL , V_25 ) ;
F_88 ( V_25 -> V_50 , V_25 -> V_161 ,
F_90 ( V_25 -> V_161 , V_158 ) ,
NULL , 0 , F_51 , V_25 ) ;
V_25 -> V_50 -> V_167 = V_168 ;
V_25 -> V_78 = V_60 +
V_169 ;
V_25 -> V_79 = V_23 ;
F_50 ( & V_25 -> V_49 ) ;
F_91 ( & V_25 -> V_42 , F_46 ) ;
V_160 = F_60 ( V_25 ) ;
if ( ! V_160 ) {
F_19 ( & V_35 -> V_25 ,
L_16 ) ;
V_45 = - V_166 ;
goto error;
}
if ( F_92 ( V_160 , V_128 ) )
V_25 -> V_125 = V_128 ;
else
V_25 -> V_125 = V_126 ;
V_45 = F_57 ( V_25 , V_25 -> V_125 ) ;
if ( V_45 ) {
F_19 ( & V_35 -> V_25 ,
L_17 ,
V_25 -> V_125 ) ;
goto error;
}
V_159 = F_62 ( V_25 ) ;
if ( ! V_159 )
F_19 ( & V_35 -> V_25 ,
L_18 ) ;
F_93 ( & V_35 -> V_25 ,
L_19 ,
( V_159 & 0xFF00 ) >> 8 , V_159 & 0xFF ) ;
V_25 -> V_75 = F_94 ( & V_170 ,
V_171 ,
V_172 ,
V_25 -> V_78 ,
V_25 -> V_79 ) ;
if ( ! V_25 -> V_75 ) {
F_19 ( & V_35 -> V_25 ,
L_20 ) ;
V_45 = - V_69 ;
goto error;
}
F_95 ( V_25 -> V_75 , & V_35 -> V_25 ) ;
F_96 ( V_25 -> V_75 , V_25 ) ;
V_45 = F_97 ( V_25 -> V_75 ) ;
if ( V_45 ) {
F_19 ( & V_35 -> V_25 ,
L_21 ) ;
goto V_173;
}
return 0 ;
V_173:
F_98 ( V_25 -> V_75 ) ;
error:
F_99 ( V_25 -> V_38 ) ;
F_99 ( V_25 -> V_50 ) ;
F_100 ( V_25 -> V_161 ) ;
return V_45 ;
}
static void F_101 ( struct V_150 * V_35 )
{
struct V_24 * V_25 ;
V_25 = F_102 ( V_35 ) ;
F_84 ( V_35 , NULL ) ;
F_103 ( V_25 -> V_75 ) ;
F_98 ( V_25 -> V_75 ) ;
F_29 ( V_25 -> V_38 ) ;
F_29 ( V_25 -> V_50 ) ;
F_99 ( V_25 -> V_38 ) ;
F_99 ( V_25 -> V_50 ) ;
F_100 ( V_25 -> V_161 ) ;
F_42 ( V_25 -> V_26 ) ;
F_93 ( & V_35 -> V_25 , L_22 ) ;
}
