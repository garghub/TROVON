static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_6 ;
F_2 ( V_2 , & V_6 ) ;
F_3 ( L_1 ,
V_2 -> V_7 , V_6 , V_4 -> V_8 ) ;
return ( V_2 -> V_7 & V_4 -> V_8 ) == V_2 -> V_7 ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_6 ;
F_2 ( V_2 , & V_6 ) ;
F_3 ( L_2 ,
V_2 -> V_7 , V_6 , V_4 -> V_8 ) ;
return V_6 != 0 ;
}
static int F_5 ( int V_9 )
{
return sizeof( struct V_10 ) + V_9 + 16 +
sizeof( V_11 ) ;
}
static int F_6 ( struct V_12 * V_13 ,
void * V_14 , int V_9 , void * V_15 , T_1 V_16 )
{
struct V_10 V_17 = {
. V_18 = 1 ,
. V_19 = F_7 (CEPHX_ENC_MAGIC)
} ;
T_1 V_20 = V_16 - sizeof( V_11 ) ;
int V_21 ;
V_21 = F_8 ( V_13 , V_15 + sizeof( V_11 ) , & V_20 ,
& V_17 , sizeof( V_17 ) , V_14 , V_9 ) ;
if ( V_21 )
return V_21 ;
F_9 ( & V_15 , V_20 ) ;
return V_20 + sizeof( V_11 ) ;
}
static int F_10 ( struct V_12 * V_13 ,
void * * V_22 , void * V_23 , void * * V_15 , T_1 V_16 )
{
struct V_10 V_17 ;
T_1 V_24 = sizeof( V_17 ) ;
int V_20 , V_21 ;
V_20 = F_11 ( V_22 ) ;
if ( * V_22 + V_20 > V_23 )
return - V_25 ;
F_3 ( L_3 , V_20 ) ;
if ( * V_15 == NULL ) {
* V_15 = F_12 ( V_20 , V_26 ) ;
if ( ! * V_15 )
return - V_27 ;
V_16 = V_20 ;
}
V_21 = F_13 ( V_13 , & V_17 , & V_24 , * V_15 , & V_16 , * V_22 , V_20 ) ;
if ( V_21 )
return V_21 ;
if ( V_17 . V_18 != 1 || F_14 ( V_17 . V_19 ) != V_28 )
return - V_29 ;
* V_22 += V_20 ;
return V_16 ;
}
static struct V_30 *
F_15 ( struct V_1 * V_2 , int V_31 )
{
struct V_30 * V_32 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_33 * V_34 = NULL , * * V_22 = & V_4 -> V_35 . V_33 ;
while ( * V_22 ) {
V_34 = * V_22 ;
V_32 = F_16 ( V_34 , struct V_30 , V_36 ) ;
if ( V_31 < V_32 -> V_31 )
V_22 = & ( * V_22 ) -> V_37 ;
else if ( V_31 > V_32 -> V_31 )
V_22 = & ( * V_22 ) -> V_38 ;
else
return V_32 ;
}
V_32 = F_17 ( sizeof( * V_32 ) , V_26 ) ;
if ( ! V_32 )
return F_18 ( - V_27 ) ;
V_32 -> V_31 = V_31 ;
F_19 ( & V_32 -> V_36 , V_34 , V_22 ) ;
F_20 ( & V_32 -> V_36 , & V_4 -> V_35 ) ;
return V_32 ;
}
static void F_21 ( struct V_1 * V_2 ,
struct V_30 * V_32 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_3 ( L_4 , V_32 , V_32 -> V_31 ) ;
F_22 ( & V_32 -> V_36 , & V_4 -> V_35 ) ;
F_23 ( & V_32 -> V_39 ) ;
if ( V_32 -> V_40 )
F_24 ( V_32 -> V_40 ) ;
F_25 ( V_32 ) ;
}
static int F_26 ( struct V_1 * V_2 ,
struct V_12 * V_13 ,
void * * V_22 , void * V_23 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int type ;
T_2 V_41 , V_42 ;
struct V_30 * V_32 ;
void * V_43 = NULL ;
void * V_44 , * V_45 ;
int V_46 ;
char V_47 ;
struct V_48 V_49 ;
struct V_12 V_50 ;
void * V_51 = NULL ;
void * V_52 , * V_53 ;
void * * V_54 ;
struct V_12 V_55 ;
struct V_56 * V_57 ;
unsigned long V_58 , V_59 ;
T_3 V_60 ;
int V_21 ;
F_27 ( V_22 , V_23 , sizeof( V_11 ) + 1 , V_61 ) ;
type = F_11 ( V_22 ) ;
F_3 ( L_5 , type , F_28 ( type ) ) ;
V_41 = F_29 ( V_22 ) ;
if ( V_41 != 1 )
goto V_61;
V_32 = F_15 ( V_2 , type ) ;
if ( F_30 ( V_32 ) ) {
V_21 = F_31 ( V_32 ) ;
goto V_62;
}
V_46 = F_10 ( V_13 , V_22 , V_23 , & V_43 , 0 ) ;
if ( V_46 <= 0 ) {
V_21 = V_46 ;
goto V_62;
}
F_3 ( L_6 , V_46 ) ;
V_44 = V_43 ;
V_45 = V_44 + V_46 ;
V_41 = F_29 ( & V_44 ) ;
if ( V_41 != 1 )
goto V_61;
memcpy ( & V_50 , & V_32 -> V_39 , sizeof( V_50 ) ) ;
V_21 = F_32 ( & V_55 , & V_44 , V_45 ) ;
if ( V_21 )
goto V_62;
F_33 ( & V_49 , V_44 ) ;
V_44 += sizeof( struct V_63 ) ;
V_58 = F_34 () + V_49 . V_64 ;
V_59 = V_58 - ( V_49 . V_64 / 4 ) ;
F_3 ( L_7 , V_58 ,
V_59 ) ;
F_35 ( V_22 , V_23 , V_47 , V_61 ) ;
if ( V_47 ) {
F_3 ( L_8 ) ;
V_46 = F_10 ( & V_50 , V_22 , V_23 , & V_51 , 0 ) ;
if ( V_46 < 0 ) {
V_21 = V_46 ;
goto V_62;
}
V_52 = V_51 ;
V_54 = & V_52 ;
V_53 = * V_54 + V_46 ;
} else {
V_54 = V_22 ;
V_53 = V_23 ;
}
F_36 ( V_54 , V_53 , V_46 , V_61 ) ;
F_3 ( L_9 , V_46 ) ;
F_27 ( V_54 , V_53 , 1 + sizeof( T_3 ) , V_61 ) ;
V_42 = F_29 ( V_54 ) ;
V_60 = F_37 ( V_54 ) ;
V_21 = F_38 ( & V_57 , V_54 , V_53 ) ;
if ( V_21 )
goto V_62;
F_23 ( & V_32 -> V_39 ) ;
if ( V_32 -> V_40 )
F_24 ( V_32 -> V_40 ) ;
V_32 -> V_39 = V_55 ;
V_32 -> V_40 = V_57 ;
V_32 -> V_65 = V_60 ;
V_32 -> V_66 = V_58 ;
V_32 -> V_67 = V_59 ;
V_32 -> V_68 = true ;
F_3 ( L_10 ,
type , F_28 ( type ) , V_32 -> V_65 ,
( int ) V_32 -> V_40 -> V_69 . V_70 ) ;
V_4 -> V_8 |= V_32 -> V_31 ;
V_62:
F_25 ( V_51 ) ;
F_25 ( V_43 ) ;
return V_21 ;
V_61:
V_21 = - V_25 ;
goto V_62;
}
static int F_39 ( struct V_1 * V_2 ,
struct V_12 * V_13 ,
void * V_71 , void * V_23 )
{
void * V_22 = V_71 ;
T_2 V_72 ;
V_11 V_73 ;
int V_21 ;
F_35 ( & V_22 , V_23 , V_72 , V_61 ) ;
if ( V_72 != 1 )
return - V_25 ;
F_36 ( & V_22 , V_23 , V_73 , V_61 ) ;
F_3 ( L_11 , V_73 ) ;
while ( V_73 -- ) {
V_21 = F_26 ( V_2 , V_13 , & V_22 , V_23 ) ;
if ( V_21 )
return V_21 ;
}
return 0 ;
V_61:
return - V_25 ;
}
static void F_40 ( struct V_74 * V_75 )
{
F_23 ( & V_75 -> V_39 ) ;
if ( V_75 -> V_71 ) {
F_24 ( V_75 -> V_71 ) ;
V_75 -> V_71 = NULL ;
}
}
static int F_41 ( struct V_1 * V_2 ,
struct V_30 * V_32 ,
struct V_74 * V_75 )
{
int V_76 ;
struct V_77 * V_78 ;
struct V_79 V_80 ;
void * V_22 , * V_23 ;
int V_21 ;
int V_81 =
( V_32 -> V_40 ? V_32 -> V_40 -> V_69 . V_70 : 0 ) ;
F_3 ( L_12 ,
F_28 ( V_32 -> V_31 ) , V_75 ) ;
F_23 ( & V_75 -> V_39 ) ;
V_21 = F_42 ( & V_75 -> V_39 , & V_32 -> V_39 ) ;
if ( V_21 )
goto V_82;
V_76 = sizeof( * V_78 ) + sizeof( V_80 ) +
F_5 ( V_81 ) ;
F_3 ( L_13 , V_76 ) ;
if ( V_75 -> V_71 && V_75 -> V_71 -> V_83 < V_76 ) {
F_24 ( V_75 -> V_71 ) ;
V_75 -> V_71 = NULL ;
}
if ( ! V_75 -> V_71 ) {
V_75 -> V_71 = F_43 ( V_76 , V_26 ) ;
if ( ! V_75 -> V_71 ) {
V_21 = - V_27 ;
goto V_82;
}
}
V_75 -> V_31 = V_32 -> V_31 ;
V_75 -> V_65 = V_32 -> V_65 ;
V_78 = V_75 -> V_71 -> V_69 . V_84 ;
V_78 -> V_18 = 1 ;
V_78 -> V_85 = F_7 ( V_2 -> V_85 ) ;
V_78 -> V_86 = F_44 ( V_32 -> V_31 ) ;
V_78 -> V_40 . V_18 = 1 ;
V_78 -> V_40 . V_65 = F_7 ( V_32 -> V_65 ) ;
V_78 -> V_40 . V_87 = F_44 ( V_81 ) ;
if ( V_81 ) {
memcpy ( V_78 -> V_40 . V_88 , V_32 -> V_40 -> V_69 . V_84 ,
V_32 -> V_40 -> V_69 . V_70 ) ;
}
F_3 ( L_14 , V_32 , V_32 -> V_65 ,
F_14 ( V_78 -> V_40 . V_65 ) ) ;
V_22 = V_78 + 1 ;
V_22 += V_81 ;
V_23 = V_75 -> V_71 -> V_69 . V_84 + V_75 -> V_71 -> V_69 . V_70 ;
F_45 ( & V_75 -> V_89 , sizeof( V_75 -> V_89 ) ) ;
V_80 . V_18 = 1 ;
V_80 . V_89 = F_7 ( V_75 -> V_89 ) ;
V_21 = F_6 ( & V_75 -> V_39 , & V_80 , sizeof( V_80 ) ,
V_22 , V_23 - V_22 ) ;
if ( V_21 < 0 )
goto V_82;
V_22 += V_21 ;
V_75 -> V_71 -> V_69 . V_70 = V_22 - V_75 -> V_71 -> V_69 . V_84 ;
F_3 ( L_15 , V_75 -> V_89 ,
( int ) V_75 -> V_71 -> V_69 . V_70 ) ;
F_46 ( V_75 -> V_71 -> V_69 . V_70 > V_76 ) ;
return 0 ;
V_82:
F_40 ( V_75 ) ;
return V_21 ;
}
static int F_47 ( struct V_30 * V_32 ,
void * * V_22 , void * V_23 )
{
F_27 ( V_22 , V_23 , 1 + sizeof( T_3 ) , V_61 ) ;
F_48 ( V_22 , 1 ) ;
F_49 ( V_22 , V_32 -> V_65 ) ;
if ( V_32 -> V_40 ) {
const char * V_71 = V_32 -> V_40 -> V_69 . V_84 ;
V_11 V_20 = V_32 -> V_40 -> V_69 . V_70 ;
F_50 ( V_22 , V_23 , V_20 , V_61 ) ;
F_51 ( V_22 , V_23 , V_71 , V_20 , V_61 ) ;
} else {
F_50 ( V_22 , V_23 , 0 , V_61 ) ;
}
return 0 ;
V_61:
return - V_90 ;
}
static bool F_52 ( struct V_30 * V_32 )
{
if ( ! V_32 -> V_68 )
return true ;
return F_34 () >= V_32 -> V_67 ;
}
static bool V_68 ( struct V_30 * V_32 )
{
if ( V_32 -> V_68 ) {
if ( F_34 () >= V_32 -> V_66 )
V_32 -> V_68 = false ;
}
return V_32 -> V_68 ;
}
static void F_2 ( struct V_1 * V_2 , int * V_91 )
{
int V_92 = V_2 -> V_7 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_31 ;
* V_91 = V_2 -> V_7 & ~ ( V_4 -> V_8 ) ;
for ( V_31 = 1 ; V_31 <= V_92 ; V_31 <<= 1 ) {
struct V_30 * V_32 ;
if ( ! ( V_2 -> V_7 & V_31 ) )
continue;
if ( * V_91 & V_31 )
continue;
V_32 = F_15 ( V_2 , V_31 ) ;
if ( F_30 ( V_32 ) ) {
* V_91 |= V_31 ;
continue;
}
if ( F_52 ( V_32 ) )
* V_91 |= V_31 ;
if ( ! V_68 ( V_32 ) )
V_4 -> V_8 &= ~ V_31 ;
}
}
static int F_53 ( struct V_1 * V_2 ,
void * V_71 , void * V_23 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_6 ;
struct V_93 * V_17 = V_71 ;
int V_21 ;
struct V_30 * V_32 =
F_15 ( V_2 , V_94 ) ;
if ( F_30 ( V_32 ) )
return F_31 ( V_32 ) ;
F_2 ( V_2 , & V_6 ) ;
F_3 ( L_16 ,
V_2 -> V_7 , V_4 -> V_8 , V_6 ) ;
if ( V_6 & V_94 ) {
struct V_95 * V_96 = ( void * ) ( V_17 + 1 ) ;
void * V_22 = V_96 + 1 ;
struct V_97 V_98 ;
char V_99 [ 40 ] ;
T_3 * V_100 ;
if ( V_22 > V_23 )
return - V_90 ;
F_3 ( L_17 ) ;
V_17 -> V_101 = F_54 ( V_102 ) ;
F_45 ( & V_96 -> V_103 , sizeof( T_3 ) ) ;
V_98 . V_103 = V_96 -> V_103 ;
V_98 . V_104 = F_7 ( V_4 -> V_104 ) ;
V_21 = F_6 ( & V_4 -> V_13 , & V_98 , sizeof( V_98 ) ,
V_99 , sizeof( V_99 ) ) ;
if ( V_21 < 0 )
return V_21 ;
V_96 -> V_18 = 1 ;
V_96 -> V_105 = 0 ;
for ( V_100 = ( T_3 * ) V_99 ; V_100 + 1 <= ( T_3 * ) ( V_99 + V_21 ) ; V_100 ++ )
V_96 -> V_105 ^= * ( V_106 * ) V_100 ;
F_3 ( L_18 ,
V_4 -> V_104 , F_14 ( V_96 -> V_103 ) ,
F_14 ( V_96 -> V_105 ) ) ;
V_21 = F_47 ( V_32 , & V_22 , V_23 ) ;
if ( V_21 < 0 )
return V_21 ;
return V_22 - V_71 ;
}
if ( V_6 ) {
void * V_22 = V_17 + 1 ;
struct V_107 * V_108 ;
if ( V_22 > V_23 )
return - V_90 ;
V_17 -> V_101 = F_54 ( V_109 ) ;
V_21 = F_41 ( V_2 , V_32 , & V_4 -> V_110 ) ;
if ( V_21 )
return V_21 ;
F_55 ( & V_22 , V_4 -> V_110 . V_71 -> V_69 . V_84 ,
V_4 -> V_110 . V_71 -> V_69 . V_70 ) ;
V_108 = V_22 ;
V_108 -> V_111 = F_44 ( V_6 ) ;
V_22 += sizeof( * V_108 ) ;
return V_22 - V_71 ;
}
return 0 ;
}
static int F_56 ( struct V_1 * V_2 , int V_112 ,
void * V_71 , void * V_23 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_113 * V_17 = V_71 ;
struct V_30 * V_32 ;
int V_20 = V_23 - V_71 ;
int V_101 ;
int V_21 ;
if ( V_112 )
return V_112 ;
if ( V_4 -> V_114 ) {
struct V_115 * V_116 = V_71 ;
if ( V_20 != sizeof( * V_116 ) )
return - V_25 ;
V_4 -> V_104 = F_14 ( V_116 -> V_104 ) ;
F_3 ( L_19 ,
V_4 -> V_104 ) ;
V_4 -> V_114 = false ;
V_4 -> V_8 &= ~ V_94 ;
return - V_117 ;
}
V_101 = F_57 ( V_17 -> V_101 ) ;
V_112 = F_58 ( V_17 -> V_112 ) ;
F_3 ( L_20 , V_101 , V_112 ) ;
switch ( V_101 ) {
case V_102 :
V_21 = F_39 ( V_2 , & V_4 -> V_13 ,
V_71 + sizeof( * V_17 ) , V_23 ) ;
break;
case V_109 :
V_32 = F_15 ( V_2 , V_94 ) ;
if ( F_30 ( V_32 ) )
return F_31 ( V_32 ) ;
V_21 = F_39 ( V_2 , & V_32 -> V_39 ,
V_71 + sizeof( * V_17 ) , V_23 ) ;
break;
default:
return - V_25 ;
}
if ( V_21 )
return V_21 ;
if ( V_2 -> V_7 == V_4 -> V_8 )
return 0 ;
return - V_117 ;
}
static void F_59 ( struct V_118 * V_119 )
{
struct V_74 * V_75 = ( void * ) V_119 ;
F_40 ( V_75 ) ;
F_25 ( V_75 ) ;
}
static int F_60 (
struct V_1 * V_2 , int V_120 ,
struct V_121 * V_96 )
{
struct V_74 * V_75 ;
struct V_30 * V_32 ;
int V_21 ;
V_32 = F_15 ( V_2 , V_120 ) ;
if ( F_30 ( V_32 ) )
return F_31 ( V_32 ) ;
V_75 = F_17 ( sizeof( * V_75 ) , V_26 ) ;
if ( ! V_75 )
return - V_27 ;
V_75 -> V_122 . V_123 = F_59 ;
V_21 = F_41 ( V_2 , V_32 , V_75 ) ;
if ( V_21 ) {
F_25 ( V_75 ) ;
return V_21 ;
}
V_96 -> V_124 = (struct V_118 * ) V_75 ;
V_96 -> V_125 = V_75 -> V_71 -> V_69 . V_84 ;
V_96 -> V_126 = V_75 -> V_71 -> V_69 . V_70 ;
V_96 -> V_127 = V_75 -> V_128 ;
V_96 -> V_129 = sizeof ( V_75 -> V_128 ) ;
V_96 -> V_130 = V_2 -> V_131 -> V_130 ;
V_96 -> V_132 = V_2 -> V_131 -> V_132 ;
return 0 ;
}
static int F_61 (
struct V_1 * V_2 , int V_120 ,
struct V_121 * V_96 )
{
struct V_74 * V_75 ;
struct V_30 * V_32 ;
V_32 = F_15 ( V_2 , V_120 ) ;
if ( F_30 ( V_32 ) )
return F_31 ( V_32 ) ;
V_75 = (struct V_74 * ) V_96 -> V_124 ;
if ( V_75 -> V_65 < V_32 -> V_65 ) {
F_3 ( L_21 ,
V_75 -> V_31 , V_75 -> V_65 , V_32 -> V_65 ) ;
return F_41 ( V_2 , V_32 , V_75 ) ;
}
return 0 ;
}
static int F_62 ( struct V_1 * V_2 ,
struct V_118 * V_119 , T_1 V_20 )
{
struct V_74 * V_75 = ( void * ) V_119 ;
int V_21 = 0 ;
struct V_133 V_134 ;
void * V_135 = & V_134 ;
void * V_22 = V_75 -> V_128 ;
void * V_23 = V_22 + sizeof( V_75 -> V_128 ) ;
V_21 = F_10 ( & V_75 -> V_39 , & V_22 , V_23 , & V_135 , sizeof( V_134 ) ) ;
if ( V_21 < 0 )
return V_21 ;
if ( V_21 != sizeof( V_134 ) )
return - V_29 ;
if ( V_75 -> V_89 + 1 != F_14 ( V_134 . V_136 ) )
V_21 = - V_29 ;
else
V_21 = 0 ;
F_3 ( L_22 ,
V_75 -> V_89 , F_14 ( V_134 . V_136 ) , V_21 ) ;
return V_21 ;
}
static void F_63 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_3 ( L_23 ) ;
V_4 -> V_114 = true ;
V_4 -> V_104 = 0 ;
}
static void F_64 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_33 * V_22 ;
F_3 ( L_24 , V_2 ) ;
F_23 ( & V_4 -> V_13 ) ;
while ( ( V_22 = F_65 ( & V_4 -> V_35 ) ) != NULL ) {
struct V_30 * V_32 =
F_16 ( V_22 , struct V_30 , V_36 ) ;
F_21 ( V_2 , V_32 ) ;
}
F_40 ( & V_4 -> V_110 ) ;
F_25 ( V_2 -> V_5 ) ;
V_2 -> V_5 = NULL ;
}
static void F_66 ( struct V_1 * V_2 , int V_120 )
{
struct V_30 * V_32 ;
V_32 = F_15 ( V_2 , V_120 ) ;
if ( ! F_30 ( V_32 ) )
V_32 -> V_68 = false ;
}
static void F_67 ( struct V_1 * V_2 ,
int V_120 )
{
F_66 ( V_2 , V_120 ) ;
F_66 ( V_2 , V_94 ) ;
}
static int F_68 ( struct V_74 * V_75 ,
struct V_137 * V_138 , V_106 * V_139 )
{
int V_21 ;
char V_99 [ 40 ] ;
T_4 V_98 [ 5 ] = {
F_44 ( 16 ) , V_138 -> V_140 . V_141 , V_138 -> V_142 . V_143 ,
V_138 -> V_142 . V_144 , V_138 -> V_142 . V_145 ,
} ;
V_21 = F_6 ( & V_75 -> V_39 , & V_98 , sizeof( V_98 ) ,
V_99 , sizeof( V_99 ) ) ;
if ( V_21 < 0 )
return V_21 ;
* V_139 = * ( V_106 * ) ( V_99 + 4 ) ;
return 0 ;
}
static int F_69 ( struct V_121 * V_96 ,
struct V_137 * V_138 )
{
int V_21 ;
if ( F_70 ( F_71 ( V_138 -> V_146 -> V_147 ) , V_148 ) )
return 0 ;
V_21 = F_68 ( (struct V_74 * ) V_96 -> V_124 ,
V_138 , & V_138 -> V_142 . V_139 ) ;
if ( V_21 < 0 )
return V_21 ;
V_138 -> V_142 . V_149 |= V_150 ;
return 0 ;
}
static int F_72 ( struct V_121 * V_96 ,
struct V_137 * V_138 )
{
V_106 V_151 ;
int V_21 ;
if ( F_70 ( F_71 ( V_138 -> V_146 -> V_147 ) , V_148 ) )
return 0 ;
V_21 = F_68 ( (struct V_74 * ) V_96 -> V_124 ,
V_138 , & V_151 ) ;
if ( V_21 < 0 )
return V_21 ;
if ( V_151 == V_138 -> V_142 . V_139 )
return 0 ;
if ( V_138 -> V_142 . V_149 & V_150 )
F_3 ( L_25
L_26 , V_138 , V_138 -> V_142 . V_139 , V_151 ) ;
else
F_3 ( L_27
L_28 , V_138 ) ;
return - V_152 ;
}
int F_73 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_21 ;
F_3 ( L_29 , V_2 ) ;
V_21 = - V_27 ;
V_4 = F_17 ( sizeof( * V_4 ) , V_26 ) ;
if ( ! V_4 )
goto V_62;
V_21 = - V_25 ;
if ( ! V_2 -> V_105 ) {
F_74 ( L_30 ) ;
goto V_153;
}
V_21 = F_42 ( & V_4 -> V_13 , V_2 -> V_105 ) ;
if ( V_21 < 0 ) {
F_74 ( L_31 , V_21 ) ;
goto V_153;
}
V_4 -> V_114 = true ;
V_4 -> V_35 = V_154 ;
V_2 -> V_155 = V_156 ;
V_2 -> V_5 = V_4 ;
V_2 -> V_131 = & V_157 ;
return 0 ;
V_153:
F_25 ( V_4 ) ;
V_62:
return V_21 ;
}
