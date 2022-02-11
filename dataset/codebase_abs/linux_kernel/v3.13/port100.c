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
int V_45 ;
V_25 -> V_47 -> V_39 = V_20 ;
V_25 -> V_47 -> V_48 = sizeof( V_20 ) ;
V_45 = F_23 ( V_25 -> V_47 , V_49 ) ;
return V_45 ;
}
static int F_27 ( struct V_24 * V_25 , struct V_50 * V_51 ,
struct V_50 * V_52 , int V_53 )
{
int V_45 ;
V_25 -> V_47 -> V_39 = V_51 -> V_2 ;
V_25 -> V_47 -> V_48 = V_51 -> V_17 ;
V_25 -> V_38 -> V_39 = V_52 -> V_2 ;
V_25 -> V_38 -> V_48 = V_53 ;
F_20 ( L_9 , V_41 , 16 , 1 ,
V_51 -> V_2 , V_51 -> V_17 , false ) ;
V_45 = F_23 ( V_25 -> V_47 , V_49 ) ;
if ( V_45 )
return V_45 ;
V_45 = F_25 ( V_25 , V_49 ) ;
if ( V_45 )
goto error;
return 0 ;
error:
F_28 ( V_25 -> V_47 ) ;
return V_45 ;
}
static void F_29 ( struct V_24 * V_25 , T_1 V_7 ,
struct V_50 * V_54 )
{
int V_55 = V_54 -> V_17 ;
F_30 ( V_54 , V_56 ) ;
F_31 ( V_54 , V_23 ) ;
F_3 ( V_54 -> V_2 , V_7 ) ;
F_12 ( V_54 -> V_2 , V_55 ) ;
F_8 ( V_54 -> V_2 ) ;
}
static void F_32 ( struct V_24 * V_25 )
{
struct V_30 * V_26 = V_25 -> V_26 ;
int V_32 = V_26 -> V_32 ;
struct V_50 * V_57 = V_26 -> V_57 ;
struct V_50 * V_58 = V_26 -> V_58 ;
F_33 ( V_57 ) ;
V_25 -> V_26 = NULL ;
if ( V_32 < 0 ) {
V_26 -> V_59 ( V_25 , V_26 -> V_60 ,
F_34 ( V_32 ) ) ;
F_33 ( V_58 ) ;
goto V_61;
}
F_31 ( V_58 , F_15 ( V_58 -> V_2 ) ) ;
F_35 ( V_58 , V_56 ) ;
F_36 ( V_58 , V_58 -> V_17 - V_23 ) ;
V_26 -> V_59 ( V_25 , V_26 -> V_60 , V_58 ) ;
V_61:
F_37 ( V_26 ) ;
}
static int F_38 ( struct V_24 * V_25 , T_1 V_7 ,
struct V_50 * V_57 ,
T_4 V_59 ,
void * V_60 )
{
struct V_30 * V_26 ;
struct V_50 * V_58 ;
int V_45 ;
int V_62 = V_56 +
V_63 +
V_23 ;
V_58 = F_39 ( V_62 , V_49 ) ;
if ( ! V_58 )
return - V_64 ;
V_26 = F_40 ( sizeof( * V_26 ) , V_49 ) ;
if ( ! V_26 ) {
F_33 ( V_58 ) ;
return - V_64 ;
}
V_26 -> V_27 = V_7 ;
V_26 -> V_57 = V_57 ;
V_26 -> V_58 = V_58 ;
V_26 -> V_62 = V_62 ;
V_26 -> V_59 = V_59 ;
V_26 -> V_60 = V_60 ;
F_29 ( V_25 , V_7 , V_57 ) ;
V_25 -> V_26 = V_26 ;
V_45 = F_27 ( V_25 , V_57 , V_58 , V_62 ) ;
if ( V_45 ) {
F_37 ( V_26 ) ;
F_33 ( V_58 ) ;
V_25 -> V_26 = NULL ;
}
return V_45 ;
}
static void F_41 ( struct V_65 * V_66 )
{
struct V_24 * V_25 = F_42 ( V_66 , struct V_24 ,
V_42 ) ;
F_32 ( V_25 ) ;
}
static void F_43 ( struct V_24 * V_25 , void * V_67 ,
struct V_50 * V_58 )
{
struct V_68 * V_69 = V_67 ;
V_69 -> V_58 = V_58 ;
V_44 ( & V_69 -> V_61 ) ;
}
static struct V_50 * F_44 ( struct V_24 * V_25 , T_1 V_7 ,
struct V_50 * V_57 )
{
int V_45 ;
struct V_68 V_69 ;
F_45 ( & V_69 . V_61 ) ;
V_45 = F_38 ( V_25 , V_7 , V_57 ,
F_43 , & V_69 ) ;
if ( V_45 ) {
F_33 ( V_57 ) ;
return F_34 ( V_45 ) ;
}
F_46 ( & V_69 . V_61 ) ;
return V_69 . V_58 ;
}
static void F_47 ( struct V_28 * V_28 )
{
struct V_24 * V_25 = V_28 -> V_29 ;
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
static void F_48 ( struct V_70 * V_71 )
{
struct V_24 * V_25 = F_49 ( V_71 ) ;
F_26 ( V_25 ) ;
F_50 ( V_25 -> V_38 ) ;
}
static struct V_50 * F_51 ( struct V_24 * V_25 , unsigned int V_72 )
{
struct V_50 * V_54 ;
V_54 = F_39 ( V_25 -> V_73 + V_25 -> V_74 + V_72 ,
V_49 ) ;
if ( V_54 )
F_52 ( V_54 , V_25 -> V_73 ) ;
return V_54 ;
}
static int F_53 ( struct V_24 * V_25 , T_1 V_75 )
{
struct V_50 * V_54 ;
struct V_50 * V_58 ;
int V_45 ;
V_54 = F_51 ( V_25 , 1 ) ;
if ( ! V_54 )
return - V_64 ;
* F_31 ( V_54 , sizeof( T_1 ) ) = V_75 ;
V_58 = F_44 ( V_25 , V_76 , V_54 ) ;
if ( F_54 ( V_58 ) )
return F_55 ( V_58 ) ;
V_45 = V_58 -> V_2 [ 0 ] ;
F_33 ( V_58 ) ;
return V_45 ;
}
static T_5 F_56 ( struct V_24 * V_25 )
{
struct V_50 * V_54 ;
struct V_50 * V_58 ;
T_5 V_77 ;
V_54 = F_51 ( V_25 , 0 ) ;
if ( ! V_54 )
return - V_64 ;
V_58 = F_44 ( V_25 , V_78 , V_54 ) ;
if ( F_54 ( V_58 ) )
return F_55 ( V_58 ) ;
if ( V_58 -> V_17 < 8 )
V_77 = 0 ;
else
V_77 = F_57 ( * ( V_79 * ) V_58 -> V_2 ) ;
F_33 ( V_58 ) ;
return V_77 ;
}
static T_2 F_58 ( struct V_24 * V_25 )
{
struct V_50 * V_54 ;
struct V_50 * V_58 ;
T_2 V_80 ;
V_54 = F_51 ( V_25 , 0 ) ;
if ( ! V_54 )
return 0 ;
V_58 = F_44 ( V_25 , V_81 ,
V_54 ) ;
if ( F_54 ( V_58 ) )
return 0 ;
V_80 = F_9 ( * ( V_82 * ) V_58 -> V_2 ) ;
F_33 ( V_58 ) ;
return V_80 ;
}
static int F_59 ( struct V_70 * V_71 , bool V_83 )
{
struct V_24 * V_25 = F_49 ( V_71 ) ;
struct V_50 * V_54 , * V_58 ;
V_54 = F_51 ( V_25 , 1 ) ;
if ( ! V_54 )
return - V_64 ;
* F_31 ( V_54 , 1 ) = V_83 ? 1 : 0 ;
V_58 = F_44 ( V_25 , V_84 , V_54 ) ;
if ( F_54 ( V_58 ) )
return F_55 ( V_58 ) ;
F_33 ( V_58 ) ;
return 0 ;
}
static int F_60 ( struct V_70 * V_71 , T_1 V_85 )
{
struct V_24 * V_25 = F_49 ( V_71 ) ;
struct V_50 * V_54 ;
struct V_50 * V_58 ;
int V_45 ;
if ( V_85 >= V_86 )
return - V_87 ;
V_54 = F_51 ( V_25 , sizeof( struct V_88 ) ) ;
if ( ! V_54 )
return - V_64 ;
memcpy ( F_31 ( V_54 , sizeof( struct V_88 ) ) ,
& V_89 [ V_85 ] ,
sizeof( struct V_88 ) ) ;
V_58 = F_44 ( V_25 , V_90 , V_54 ) ;
if ( F_54 ( V_58 ) )
return F_55 ( V_58 ) ;
V_45 = V_58 -> V_2 [ 0 ] ;
F_33 ( V_58 ) ;
return V_45 ;
}
static int F_61 ( struct V_70 * V_71 , int V_91 )
{
struct V_24 * V_25 = F_49 ( V_71 ) ;
struct V_92 * V_93 ;
struct V_50 * V_54 ;
struct V_50 * V_58 ;
int V_94 ;
T_6 V_72 ;
int V_45 ;
if ( V_91 >= V_95 )
return - V_87 ;
V_93 = V_96 [ V_91 ] ;
V_94 = 0 ;
while ( V_93 [ V_94 ] . V_97 != V_98 )
V_94 ++ ;
if ( ! V_94 )
return 0 ;
V_72 = sizeof( struct V_92 ) * V_94 ;
V_54 = F_51 ( V_25 , V_72 ) ;
if ( ! V_54 )
return - V_64 ;
memcpy ( F_31 ( V_54 , V_72 ) , V_93 , V_72 ) ;
V_58 = F_44 ( V_25 , V_99 , V_54 ) ;
if ( F_54 ( V_58 ) )
return F_55 ( V_58 ) ;
V_45 = V_58 -> V_2 [ 0 ] ;
F_33 ( V_58 ) ;
return V_45 ;
}
static int F_62 ( struct V_70 * V_71 , int type ,
int V_91 )
{
if ( type == V_100 )
return F_60 ( V_71 , V_91 ) ;
if ( type == V_101 )
return F_61 ( V_71 , V_91 ) ;
return - V_87 ;
}
static void F_63 ( struct V_24 * V_25 , void * V_69 ,
struct V_50 * V_58 )
{
struct V_102 * V_103 = V_69 ;
T_7 V_104 = V_103 -> V_59 ;
T_8 V_32 ;
int V_45 ;
if ( F_54 ( V_58 ) ) {
V_45 = F_55 ( V_58 ) ;
goto exit;
}
if ( V_58 -> V_17 < 4 ) {
F_19 ( & V_25 -> V_35 -> V_25 ,
L_10 ) ;
V_45 = - V_40 ;
goto error;
}
V_32 = F_64 ( * ( V_105 * ) V_58 -> V_2 ) ;
F_35 ( V_58 , sizeof( T_8 ) ) ;
if ( V_32 == V_106 ) {
V_45 = - V_107 ;
goto error;
}
if ( V_32 != V_108 ) {
F_19 ( & V_25 -> V_35 -> V_25 ,
L_11 , V_32 ) ;
V_45 = - V_40 ;
goto error;
}
F_35 ( V_58 , 1 ) ;
goto exit;
error:
F_65 ( V_58 ) ;
V_58 = F_34 ( V_45 ) ;
exit:
V_104 ( V_25 -> V_70 , V_103 -> V_109 , V_58 ) ;
F_37 ( V_103 ) ;
}
static int F_66 ( struct V_70 * V_71 ,
struct V_50 * V_54 , T_2 V_110 ,
T_7 V_104 , void * V_69 )
{
struct V_24 * V_25 = F_49 ( V_71 ) ;
struct V_102 * V_103 ;
V_82 V_111 ;
V_103 = F_40 ( sizeof( struct V_102 ) , V_49 ) ;
if ( ! V_103 )
return - V_64 ;
V_103 -> V_59 = V_104 ;
V_103 -> V_109 = V_69 ;
V_111 = F_7 ( V_110 * 10 ) ;
memcpy ( F_30 ( V_54 , sizeof( V_82 ) ) , & V_111 , sizeof( V_82 ) ) ;
return F_38 ( V_25 , V_112 , V_54 ,
F_63 , V_103 ) ;
}
static int F_67 ( struct V_70 * V_71 , T_1 V_85 )
{
struct V_24 * V_25 = F_49 ( V_71 ) ;
struct V_50 * V_54 ;
struct V_50 * V_58 ;
int V_45 ;
if ( V_85 >= V_86 )
return - V_87 ;
V_54 = F_51 ( V_25 , sizeof( struct V_113 ) ) ;
if ( ! V_54 )
return - V_64 ;
memcpy ( F_31 ( V_54 , sizeof( struct V_113 ) ) ,
& V_114 [ V_85 ] ,
sizeof( struct V_113 ) ) ;
V_58 = F_44 ( V_25 , V_115 , V_54 ) ;
if ( F_54 ( V_58 ) )
return F_55 ( V_58 ) ;
V_45 = V_58 -> V_2 [ 0 ] ;
F_33 ( V_58 ) ;
return V_45 ;
}
static int F_68 ( struct V_70 * V_71 , int V_91 )
{
struct V_24 * V_25 = F_49 ( V_71 ) ;
struct V_92 * V_93 ;
struct V_50 * V_54 ;
struct V_50 * V_58 ;
int V_45 ;
int V_94 ;
T_6 V_72 ;
if ( V_91 >= V_95 )
return - V_87 ;
V_93 = V_116 [ V_91 ] ;
V_94 = 0 ;
while ( V_93 [ V_94 ] . V_97 != V_117 )
V_94 ++ ;
if ( ! V_94 )
return 0 ;
V_72 = sizeof( struct V_92 ) * V_94 ;
V_54 = F_51 ( V_25 , V_72 ) ;
if ( ! V_54 )
return - V_64 ;
memcpy ( F_31 ( V_54 , V_72 ) , V_93 , V_72 ) ;
V_58 = F_44 ( V_25 , V_118 , V_54 ) ;
if ( F_54 ( V_58 ) )
return F_55 ( V_58 ) ;
V_45 = V_58 -> V_2 [ 0 ] ;
F_33 ( V_58 ) ;
return V_45 ;
}
static int F_69 ( struct V_70 * V_71 , int type ,
int V_91 )
{
if ( type == V_100 )
return F_67 ( V_71 , V_91 ) ;
if ( type == V_101 )
return F_68 ( V_71 , V_91 ) ;
return - V_87 ;
}
static bool F_70 ( struct V_24 * V_25 , T_1 V_119 )
{
T_1 V_77 ;
switch ( V_25 -> V_120 ) {
case V_121 :
V_77 = V_122 ;
break;
case V_123 :
V_77 = V_122 |
V_124 ;
break;
default:
F_19 ( & V_25 -> V_35 -> V_25 , L_12 ) ;
return false ;
}
return ( ( V_119 & V_77 ) == V_77 ) ;
}
static void F_71 ( struct V_24 * V_25 , void * V_69 ,
struct V_50 * V_58 )
{
T_8 V_32 ;
struct V_102 * V_103 = V_69 ;
T_7 V_104 = V_103 -> V_59 ;
struct V_125 * V_126 ;
if ( F_54 ( V_58 ) )
goto exit;
V_126 = (struct V_125 * ) V_58 -> V_2 ;
V_32 = F_64 ( V_126 -> V_32 ) ;
if ( V_103 -> V_127 &&
! F_70 ( V_25 , V_126 -> V_128 ) ) {
F_65 ( V_58 ) ;
V_58 = F_34 ( - V_107 ) ;
goto exit;
}
F_35 ( V_58 , sizeof( struct V_125 ) ) ;
if ( V_32 != V_108 ) {
F_65 ( V_58 ) ;
if ( V_32 == V_106 )
V_58 = F_34 ( - V_107 ) ;
else
V_58 = F_34 ( - V_40 ) ;
}
exit:
V_104 ( V_25 -> V_70 , V_103 -> V_109 , V_58 ) ;
F_37 ( V_103 ) ;
}
static int F_72 ( struct V_70 * V_71 ,
struct V_50 * V_54 , T_2 V_111 ,
T_7 V_104 , void * V_69 )
{
struct V_24 * V_25 = F_49 ( V_71 ) ;
struct V_129 * V_126 ;
struct V_102 * V_103 ;
V_103 = F_40 ( sizeof( struct V_102 ) , V_49 ) ;
if ( ! V_103 )
return - V_64 ;
V_103 -> V_59 = V_104 ;
V_103 -> V_109 = V_69 ;
F_30 ( V_54 , sizeof( struct V_129 ) ) ;
V_126 = (struct V_129 * ) V_54 -> V_2 ;
memset ( V_126 , 0 , sizeof( struct V_129 ) ) ;
V_126 -> V_130 = F_7 ( 500 ) ;
V_126 -> V_131 = F_7 ( 0xFFFF ) ;
V_126 -> V_132 = F_7 ( V_111 ) ;
return F_38 ( V_25 , V_133 , V_54 ,
F_71 , V_103 ) ;
}
static int F_73 ( struct V_70 * V_71 ,
struct V_134 * V_135 ,
T_2 V_111 ,
T_7 V_104 , void * V_69 )
{
struct V_24 * V_25 = F_49 ( V_71 ) ;
struct V_129 * V_126 ;
struct V_102 * V_103 ;
struct V_50 * V_54 ;
int V_45 ;
V_45 = F_69 ( V_71 , V_100 ,
V_136 ) ;
if ( V_45 )
return V_45 ;
V_45 = F_69 ( V_71 , V_101 ,
V_137 ) ;
if ( V_45 )
return V_45 ;
V_103 = F_40 ( sizeof( struct V_102 ) , V_49 ) ;
if ( ! V_103 )
return - V_64 ;
V_103 -> V_59 = V_104 ;
V_103 -> V_109 = V_69 ;
V_103 -> V_127 = 1 ;
V_54 = F_51 ( V_25 , 0 ) ;
if ( ! V_54 ) {
F_37 ( V_103 ) ;
return - V_64 ;
}
F_30 ( V_54 , sizeof( struct V_129 ) ) ;
V_126 = (struct V_129 * ) V_54 -> V_2 ;
memset ( V_126 , 0 , sizeof( struct V_129 ) ) ;
V_126 -> V_130 = 0 ;
V_126 -> V_131 = F_7 ( 0xFFFF ) ;
V_126 -> V_127 = 1 ;
V_126 -> V_138 [ 0 ] = ( V_135 -> V_139 >> 8 ) & 0xFF ;
V_126 -> V_138 [ 1 ] = V_135 -> V_139 & 0xFF ;
memcpy ( V_126 -> V_138 + 2 , V_135 -> V_140 , 3 ) ;
V_126 -> V_138 [ 5 ] = V_135 -> V_141 ;
memcpy ( V_126 -> V_142 , V_135 -> V_143 , 8 ) ;
V_126 -> V_142 [ 16 ] = ( V_135 -> V_144 >> 8 ) & 0xFF ;
V_126 -> V_142 [ 17 ] = V_135 -> V_144 & 0xFF ;
V_126 -> V_132 = F_7 ( V_111 ) ;
return F_38 ( V_25 , V_133 , V_54 ,
F_71 , V_103 ) ;
}
static int F_74 ( struct V_70 * V_71 , T_2 V_111 ,
T_7 V_104 , void * V_69 )
{
struct V_24 * V_25 = F_49 ( V_71 ) ;
struct V_50 * V_54 ;
V_54 = F_51 ( V_25 , 0 ) ;
if ( ! V_54 )
return - V_64 ;
return F_72 ( V_71 , V_54 , V_111 , V_104 , V_69 ) ;
}
static int F_75 ( struct V_145 * V_35 ,
const struct V_146 * V_147 )
{
struct V_24 * V_25 ;
int V_45 ;
struct V_148 * V_149 ;
struct V_150 * V_151 ;
int V_152 ;
int V_153 ;
T_2 V_154 ;
T_5 V_155 ;
int V_5 ;
V_25 = F_76 ( & V_35 -> V_25 , sizeof( struct V_24 ) , V_49 ) ;
if ( ! V_25 )
return - V_64 ;
V_25 -> V_156 = F_77 ( F_78 ( V_35 ) ) ;
V_25 -> V_35 = V_35 ;
F_79 ( V_35 , V_25 ) ;
V_152 = V_153 = 0 ;
V_149 = V_35 -> V_157 ;
for ( V_5 = 0 ; V_5 < V_149 -> V_158 . V_159 ; ++ V_5 ) {
V_151 = & V_149 -> V_151 [ V_5 ] . V_158 ;
if ( ! V_152 && F_80 ( V_151 ) )
V_152 = V_151 -> V_160 ;
if ( ! V_153 && F_81 ( V_151 ) )
V_153 = V_151 -> V_160 ;
}
if ( ! V_152 || ! V_153 ) {
F_19 ( & V_35 -> V_25 ,
L_13 ) ;
V_45 = - V_161 ;
goto error;
}
V_25 -> V_38 = F_82 ( 0 , V_49 ) ;
V_25 -> V_47 = F_82 ( 0 , V_49 ) ;
if ( ! V_25 -> V_38 || ! V_25 -> V_47 ) {
F_19 ( & V_35 -> V_25 , L_14 ) ;
V_45 = - V_64 ;
goto error;
}
F_83 ( V_25 -> V_38 , V_25 -> V_156 ,
F_84 ( V_25 -> V_156 , V_152 ) ,
NULL , 0 , NULL , V_25 ) ;
F_83 ( V_25 -> V_47 , V_25 -> V_156 ,
F_85 ( V_25 -> V_156 , V_153 ) ,
NULL , 0 , F_47 , V_25 ) ;
V_25 -> V_73 = V_56 +
V_162 ;
V_25 -> V_74 = V_23 ;
F_86 ( & V_25 -> V_42 , F_41 ) ;
V_155 = F_56 ( V_25 ) ;
if ( ! V_155 ) {
F_19 ( & V_35 -> V_25 ,
L_15 ) ;
V_45 = - V_161 ;
goto error;
}
if ( F_87 ( V_155 , V_123 ) )
V_25 -> V_120 = V_123 ;
else
V_25 -> V_120 = V_121 ;
V_45 = F_53 ( V_25 , V_25 -> V_120 ) ;
if ( V_45 ) {
F_19 ( & V_35 -> V_25 ,
L_16 ,
V_25 -> V_120 ) ;
goto error;
}
V_154 = F_58 ( V_25 ) ;
if ( ! V_154 )
F_19 ( & V_35 -> V_25 ,
L_17 ) ;
F_88 ( & V_35 -> V_25 ,
L_18 ,
( V_154 & 0xFF00 ) >> 8 , V_154 & 0xFF ) ;
V_25 -> V_70 = F_89 ( & V_163 ,
V_164 ,
V_165 ,
V_25 -> V_73 ,
V_25 -> V_74 ) ;
if ( ! V_25 -> V_70 ) {
F_19 ( & V_35 -> V_25 ,
L_19 ) ;
V_45 = - V_64 ;
goto error;
}
F_90 ( V_25 -> V_70 , & V_35 -> V_25 ) ;
F_91 ( V_25 -> V_70 , V_25 ) ;
V_45 = F_92 ( V_25 -> V_70 ) ;
if ( V_45 ) {
F_19 ( & V_35 -> V_25 ,
L_20 ) ;
goto V_166;
}
return 0 ;
V_166:
F_93 ( V_25 -> V_70 ) ;
error:
F_94 ( V_25 -> V_38 ) ;
F_94 ( V_25 -> V_47 ) ;
F_95 ( V_25 -> V_156 ) ;
return V_45 ;
}
static void F_96 ( struct V_145 * V_35 )
{
struct V_24 * V_25 ;
V_25 = F_97 ( V_35 ) ;
F_79 ( V_35 , NULL ) ;
F_98 ( V_25 -> V_70 ) ;
F_93 ( V_25 -> V_70 ) ;
F_50 ( V_25 -> V_38 ) ;
F_50 ( V_25 -> V_47 ) ;
F_94 ( V_25 -> V_38 ) ;
F_94 ( V_25 -> V_47 ) ;
F_37 ( V_25 -> V_26 ) ;
F_88 ( & V_35 -> V_25 , L_21 ) ;
}
