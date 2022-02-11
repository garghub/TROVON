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
static int F_5 ( void )
{
return sizeof( V_9 ) + sizeof( struct V_10 ) ;
}
static int F_6 ( int V_11 )
{
return F_5 () + V_11 + 16 ;
}
static int F_7 ( struct V_12 * V_13 , void * V_14 ,
int V_15 , int V_16 )
{
struct V_10 * V_17 = V_14 + sizeof( V_9 ) ;
int V_18 ;
int V_19 ;
V_17 -> V_20 = 1 ;
V_17 -> V_21 = F_8 ( V_22 ) ;
V_19 = F_9 ( V_13 , true , V_14 + sizeof( V_9 ) , V_15 - sizeof( V_9 ) ,
V_16 + sizeof( struct V_10 ) ,
& V_18 ) ;
if ( V_19 )
return V_19 ;
F_10 ( & V_14 , V_18 ) ;
return sizeof( V_9 ) + V_18 ;
}
static int F_11 ( struct V_12 * V_13 , void * * V_23 , void * V_24 )
{
struct V_10 * V_17 = * V_23 + sizeof( V_9 ) ;
int V_18 , V_16 ;
int V_19 ;
F_12 ( V_23 , V_24 , V_18 , V_25 ) ;
F_13 ( V_23 , V_24 , V_18 , V_25 ) ;
V_19 = F_9 ( V_13 , false , * V_23 , V_24 - * V_23 , V_18 ,
& V_16 ) ;
if ( V_19 )
return V_19 ;
if ( V_17 -> V_20 != 1 || F_14 ( V_17 -> V_21 ) != V_22 )
return - V_26 ;
* V_23 += V_18 ;
return V_16 - sizeof( struct V_10 ) ;
V_25:
return - V_27 ;
}
static struct V_28 *
F_15 ( struct V_1 * V_2 , int V_29 )
{
struct V_28 * V_30 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_31 * V_32 = NULL , * * V_23 = & V_4 -> V_33 . V_31 ;
while ( * V_23 ) {
V_32 = * V_23 ;
V_30 = F_16 ( V_32 , struct V_28 , V_34 ) ;
if ( V_29 < V_30 -> V_29 )
V_23 = & ( * V_23 ) -> V_35 ;
else if ( V_29 > V_30 -> V_29 )
V_23 = & ( * V_23 ) -> V_36 ;
else
return V_30 ;
}
V_30 = F_17 ( sizeof( * V_30 ) , V_37 ) ;
if ( ! V_30 )
return F_18 ( - V_38 ) ;
V_30 -> V_29 = V_29 ;
F_19 ( & V_30 -> V_34 , V_32 , V_23 ) ;
F_20 ( & V_30 -> V_34 , & V_4 -> V_33 ) ;
return V_30 ;
}
static void F_21 ( struct V_1 * V_2 ,
struct V_28 * V_30 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_3 ( L_3 , V_30 , V_30 -> V_29 ) ;
F_22 ( & V_30 -> V_34 , & V_4 -> V_33 ) ;
F_23 ( & V_30 -> V_39 ) ;
if ( V_30 -> V_40 )
F_24 ( V_30 -> V_40 ) ;
F_25 ( V_30 ) ;
}
static int F_26 ( struct V_1 * V_2 ,
struct V_12 * V_13 ,
void * * V_23 , void * V_24 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int type ;
T_1 V_41 , V_42 ;
struct V_28 * V_30 ;
void * V_43 , * V_44 ;
int V_45 ;
char V_46 ;
struct V_47 V_48 ;
void * V_49 , * V_50 ;
void * * V_51 ;
struct V_12 V_52 = { 0 } ;
struct V_53 * V_54 ;
unsigned long V_55 , V_56 ;
T_2 V_57 ;
int V_19 ;
F_13 ( V_23 , V_24 , sizeof( V_9 ) + 1 , V_58 ) ;
type = F_27 ( V_23 ) ;
F_3 ( L_4 , type , F_28 ( type ) ) ;
V_41 = F_29 ( V_23 ) ;
if ( V_41 != 1 )
goto V_58;
V_30 = F_15 ( V_2 , type ) ;
if ( F_30 ( V_30 ) ) {
V_19 = F_31 ( V_30 ) ;
goto V_59;
}
V_43 = * V_23 + F_5 () ;
V_19 = F_11 ( V_13 , V_23 , V_24 ) ;
if ( V_19 < 0 )
goto V_59;
F_3 ( L_5 , V_19 ) ;
V_44 = V_43 + V_19 ;
V_41 = F_29 ( & V_43 ) ;
if ( V_41 != 1 )
goto V_58;
V_19 = F_32 ( & V_52 , & V_43 , V_44 ) ;
if ( V_19 )
goto V_59;
F_33 ( & V_48 , V_43 ) ;
V_43 += sizeof( struct V_60 ) ;
V_55 = F_34 () + V_48 . V_61 ;
V_56 = V_55 - ( V_48 . V_61 / 4 ) ;
F_3 ( L_6 , V_55 ,
V_56 ) ;
F_35 ( V_23 , V_24 , V_46 , V_58 ) ;
if ( V_46 ) {
V_49 = * V_23 + F_5 () ;
V_19 = F_11 ( & V_30 -> V_39 , V_23 , V_24 ) ;
if ( V_19 < 0 )
goto V_59;
F_3 ( L_7 , V_19 ) ;
V_51 = & V_49 ;
V_50 = V_49 + V_19 ;
} else {
V_51 = V_23 ;
V_50 = V_24 ;
}
F_12 ( V_51 , V_50 , V_45 , V_58 ) ;
F_3 ( L_8 , V_45 ) ;
F_13 ( V_51 , V_50 , 1 + sizeof( T_2 ) , V_58 ) ;
V_42 = F_29 ( V_51 ) ;
if ( V_42 != 1 )
goto V_58;
V_57 = F_36 ( V_51 ) ;
V_19 = F_37 ( & V_54 , V_51 , V_50 ) ;
if ( V_19 )
goto V_59;
F_23 ( & V_30 -> V_39 ) ;
if ( V_30 -> V_40 )
F_24 ( V_30 -> V_40 ) ;
V_30 -> V_39 = V_52 ;
V_30 -> V_40 = V_54 ;
V_30 -> V_62 = V_57 ;
V_30 -> V_63 = V_55 ;
V_30 -> V_64 = V_56 ;
V_30 -> V_65 = true ;
F_3 ( L_9 ,
type , F_28 ( type ) , V_30 -> V_62 ,
( int ) V_30 -> V_40 -> V_66 . V_67 ) ;
V_4 -> V_8 |= V_30 -> V_29 ;
return 0 ;
V_58:
V_19 = - V_27 ;
V_59:
F_23 ( & V_52 ) ;
return V_19 ;
}
static int F_38 ( struct V_1 * V_2 ,
struct V_12 * V_13 ,
void * V_14 , void * V_24 )
{
void * V_23 = V_14 ;
T_1 V_68 ;
V_9 V_69 ;
int V_19 ;
F_35 ( & V_23 , V_24 , V_68 , V_58 ) ;
if ( V_68 != 1 )
return - V_27 ;
F_12 ( & V_23 , V_24 , V_69 , V_58 ) ;
F_3 ( L_10 , V_69 ) ;
while ( V_69 -- ) {
V_19 = F_26 ( V_2 , V_13 , & V_23 , V_24 ) ;
if ( V_19 )
return V_19 ;
}
return 0 ;
V_58:
return - V_27 ;
}
static void F_39 ( struct V_70 * V_71 )
{
F_23 ( & V_71 -> V_39 ) ;
if ( V_71 -> V_14 ) {
F_24 ( V_71 -> V_14 ) ;
V_71 -> V_14 = NULL ;
}
}
static int F_40 ( struct V_1 * V_2 ,
struct V_28 * V_30 ,
struct V_70 * V_71 )
{
int V_72 ;
struct V_73 * V_74 ;
struct V_75 * V_76 ;
void * V_23 , * V_24 ;
int V_19 ;
int V_77 =
( V_30 -> V_40 ? V_30 -> V_40 -> V_66 . V_67 : 0 ) ;
F_3 ( L_11 ,
F_28 ( V_30 -> V_29 ) , V_71 ) ;
F_23 ( & V_71 -> V_39 ) ;
V_19 = F_41 ( & V_71 -> V_39 , & V_30 -> V_39 ) ;
if ( V_19 )
goto V_78;
V_72 = sizeof( * V_74 ) + V_77 +
F_6 ( sizeof( * V_76 ) ) ;
F_3 ( L_12 , V_72 ) ;
if ( V_71 -> V_14 && V_71 -> V_14 -> V_79 < V_72 ) {
F_24 ( V_71 -> V_14 ) ;
V_71 -> V_14 = NULL ;
}
if ( ! V_71 -> V_14 ) {
V_71 -> V_14 = F_42 ( V_72 , V_37 ) ;
if ( ! V_71 -> V_14 ) {
V_19 = - V_38 ;
goto V_78;
}
}
V_71 -> V_29 = V_30 -> V_29 ;
V_71 -> V_62 = V_30 -> V_62 ;
V_74 = V_71 -> V_14 -> V_66 . V_80 ;
V_74 -> V_20 = 1 ;
V_74 -> V_81 = F_8 ( V_2 -> V_81 ) ;
V_74 -> V_82 = F_43 ( V_30 -> V_29 ) ;
V_74 -> V_40 . V_20 = 1 ;
V_74 -> V_40 . V_62 = F_8 ( V_30 -> V_62 ) ;
V_74 -> V_40 . V_83 = F_43 ( V_77 ) ;
if ( V_77 ) {
memcpy ( V_74 -> V_40 . V_84 , V_30 -> V_40 -> V_66 . V_80 ,
V_30 -> V_40 -> V_66 . V_67 ) ;
}
F_3 ( L_13 , V_30 , V_30 -> V_62 ,
F_14 ( V_74 -> V_40 . V_62 ) ) ;
V_23 = V_74 + 1 ;
V_23 += V_77 ;
V_24 = V_71 -> V_14 -> V_66 . V_80 + V_71 -> V_14 -> V_66 . V_67 ;
V_76 = V_23 + F_5 () ;
V_76 -> V_20 = 1 ;
F_44 ( & V_71 -> V_85 , sizeof( V_71 -> V_85 ) ) ;
V_76 -> V_85 = F_8 ( V_71 -> V_85 ) ;
V_19 = F_7 ( & V_71 -> V_39 , V_23 , V_24 - V_23 , sizeof( * V_76 ) ) ;
if ( V_19 < 0 )
goto V_78;
V_23 += V_19 ;
F_45 ( V_23 > V_24 ) ;
V_71 -> V_14 -> V_66 . V_67 = V_23 - V_71 -> V_14 -> V_66 . V_80 ;
F_3 ( L_14 , V_71 -> V_85 ,
( int ) V_71 -> V_14 -> V_66 . V_67 ) ;
return 0 ;
V_78:
F_39 ( V_71 ) ;
return V_19 ;
}
static int F_46 ( struct V_28 * V_30 ,
void * * V_23 , void * V_24 )
{
F_13 ( V_23 , V_24 , 1 + sizeof( T_2 ) , V_58 ) ;
F_47 ( V_23 , 1 ) ;
F_48 ( V_23 , V_30 -> V_62 ) ;
if ( V_30 -> V_40 ) {
const char * V_14 = V_30 -> V_40 -> V_66 . V_80 ;
V_9 V_86 = V_30 -> V_40 -> V_66 . V_67 ;
F_49 ( V_23 , V_24 , V_86 , V_58 ) ;
F_50 ( V_23 , V_24 , V_14 , V_86 , V_58 ) ;
} else {
F_49 ( V_23 , V_24 , 0 , V_58 ) ;
}
return 0 ;
V_58:
return - V_87 ;
}
static bool F_51 ( struct V_28 * V_30 )
{
if ( ! V_30 -> V_65 )
return true ;
return F_34 () >= V_30 -> V_64 ;
}
static bool V_65 ( struct V_28 * V_30 )
{
if ( V_30 -> V_65 ) {
if ( F_34 () >= V_30 -> V_63 )
V_30 -> V_65 = false ;
}
return V_30 -> V_65 ;
}
static void F_2 ( struct V_1 * V_2 , int * V_88 )
{
int V_89 = V_2 -> V_7 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_29 ;
* V_88 = V_2 -> V_7 & ~ ( V_4 -> V_8 ) ;
for ( V_29 = 1 ; V_29 <= V_89 ; V_29 <<= 1 ) {
struct V_28 * V_30 ;
if ( ! ( V_2 -> V_7 & V_29 ) )
continue;
if ( * V_88 & V_29 )
continue;
V_30 = F_15 ( V_2 , V_29 ) ;
if ( F_30 ( V_30 ) ) {
* V_88 |= V_29 ;
continue;
}
if ( F_51 ( V_30 ) )
* V_88 |= V_29 ;
if ( ! V_65 ( V_30 ) )
V_4 -> V_8 &= ~ V_29 ;
}
}
static int F_52 ( struct V_1 * V_2 ,
void * V_14 , void * V_24 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_6 ;
struct V_90 * V_91 = V_14 ;
int V_19 ;
struct V_28 * V_30 =
F_15 ( V_2 , V_92 ) ;
if ( F_30 ( V_30 ) )
return F_31 ( V_30 ) ;
F_2 ( V_2 , & V_6 ) ;
F_3 ( L_15 ,
V_2 -> V_7 , V_4 -> V_8 , V_6 ) ;
if ( V_6 & V_92 ) {
struct V_93 * V_94 = ( void * ) ( V_91 + 1 ) ;
void * V_23 = V_94 + 1 ;
void * V_95 = V_4 -> V_96 . V_95 ;
struct V_97 * V_84 = V_95 +
F_5 () ;
T_2 * V_98 ;
if ( V_23 > V_24 )
return - V_87 ;
F_3 ( L_16 ) ;
V_91 -> V_99 = F_53 ( V_100 ) ;
F_44 ( & V_94 -> V_101 , sizeof( T_2 ) ) ;
V_84 -> V_101 = V_94 -> V_101 ;
V_84 -> V_102 = F_8 ( V_4 -> V_102 ) ;
V_19 = F_7 ( & V_4 -> V_13 , V_95 , V_103 ,
sizeof( * V_84 ) ) ;
if ( V_19 < 0 )
return V_19 ;
V_94 -> V_20 = 1 ;
V_94 -> V_104 = 0 ;
for ( V_98 = ( T_2 * ) V_95 ; V_98 + 1 <= ( T_2 * ) ( V_95 + V_19 ) ; V_98 ++ )
V_94 -> V_104 ^= * ( V_105 * ) V_98 ;
F_3 ( L_17 ,
V_4 -> V_102 , F_14 ( V_94 -> V_101 ) ,
F_14 ( V_94 -> V_104 ) ) ;
V_19 = F_46 ( V_30 , & V_23 , V_24 ) ;
if ( V_19 < 0 )
return V_19 ;
return V_23 - V_14 ;
}
if ( V_6 ) {
void * V_23 = V_91 + 1 ;
struct V_106 * V_107 ;
if ( V_23 > V_24 )
return - V_87 ;
V_91 -> V_99 = F_53 ( V_108 ) ;
V_19 = F_40 ( V_2 , V_30 , & V_4 -> V_96 ) ;
if ( V_19 )
return V_19 ;
F_54 ( & V_23 , V_4 -> V_96 . V_14 -> V_66 . V_80 ,
V_4 -> V_96 . V_14 -> V_66 . V_67 ) ;
V_107 = V_23 ;
V_107 -> V_109 = F_43 ( V_6 ) ;
V_23 += sizeof( * V_107 ) ;
return V_23 - V_14 ;
}
return 0 ;
}
static int F_55 ( struct V_1 * V_2 , int V_110 ,
void * V_14 , void * V_24 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_111 * V_91 = V_14 ;
struct V_28 * V_30 ;
int V_86 = V_24 - V_14 ;
int V_99 ;
int V_19 ;
if ( V_110 )
return V_110 ;
if ( V_4 -> V_112 ) {
struct V_113 * V_114 = V_14 ;
if ( V_86 != sizeof( * V_114 ) )
return - V_27 ;
V_4 -> V_102 = F_14 ( V_114 -> V_102 ) ;
F_3 ( L_18 ,
V_4 -> V_102 ) ;
V_4 -> V_112 = false ;
V_4 -> V_8 &= ~ V_92 ;
return - V_115 ;
}
V_99 = F_56 ( V_91 -> V_99 ) ;
V_110 = F_57 ( V_91 -> V_110 ) ;
F_3 ( L_19 , V_99 , V_110 ) ;
switch ( V_99 ) {
case V_100 :
V_19 = F_38 ( V_2 , & V_4 -> V_13 ,
V_14 + sizeof( * V_91 ) , V_24 ) ;
break;
case V_108 :
V_30 = F_15 ( V_2 , V_92 ) ;
if ( F_30 ( V_30 ) )
return F_31 ( V_30 ) ;
V_19 = F_38 ( V_2 , & V_30 -> V_39 ,
V_14 + sizeof( * V_91 ) , V_24 ) ;
break;
default:
return - V_27 ;
}
if ( V_19 )
return V_19 ;
if ( V_2 -> V_7 == V_4 -> V_8 )
return 0 ;
return - V_115 ;
}
static void F_58 ( struct V_116 * V_117 )
{
struct V_70 * V_71 = ( void * ) V_117 ;
F_39 ( V_71 ) ;
F_25 ( V_71 ) ;
}
static int F_59 (
struct V_1 * V_2 , int V_118 ,
struct V_119 * V_94 )
{
struct V_70 * V_71 ;
struct V_28 * V_30 ;
int V_19 ;
V_30 = F_15 ( V_2 , V_118 ) ;
if ( F_30 ( V_30 ) )
return F_31 ( V_30 ) ;
V_71 = F_17 ( sizeof( * V_71 ) , V_37 ) ;
if ( ! V_71 )
return - V_38 ;
V_71 -> V_120 . V_121 = F_58 ;
V_19 = F_40 ( V_2 , V_30 , V_71 ) ;
if ( V_19 ) {
F_25 ( V_71 ) ;
return V_19 ;
}
V_94 -> V_122 = (struct V_116 * ) V_71 ;
V_94 -> V_123 = V_71 -> V_14 -> V_66 . V_80 ;
V_94 -> V_124 = V_71 -> V_14 -> V_66 . V_67 ;
V_94 -> V_125 = V_71 -> V_95 ;
V_94 -> V_126 = V_103 ;
V_94 -> V_127 = V_2 -> V_128 -> V_127 ;
V_94 -> V_129 = V_2 -> V_128 -> V_129 ;
return 0 ;
}
static int F_60 (
struct V_1 * V_2 , int V_118 ,
struct V_119 * V_94 )
{
struct V_70 * V_71 ;
struct V_28 * V_30 ;
V_30 = F_15 ( V_2 , V_118 ) ;
if ( F_30 ( V_30 ) )
return F_31 ( V_30 ) ;
V_71 = (struct V_70 * ) V_94 -> V_122 ;
if ( V_71 -> V_62 < V_30 -> V_62 ) {
F_3 ( L_20 ,
V_71 -> V_29 , V_71 -> V_62 , V_30 -> V_62 ) ;
return F_40 ( V_2 , V_30 , V_71 ) ;
}
return 0 ;
}
static int F_61 ( struct V_1 * V_2 ,
struct V_116 * V_117 )
{
struct V_70 * V_71 = ( void * ) V_117 ;
void * V_23 = V_71 -> V_95 ;
struct V_130 * V_131 = V_23 + F_5 () ;
int V_19 ;
V_19 = F_11 ( & V_71 -> V_39 , & V_23 , V_23 + V_103 ) ;
if ( V_19 < 0 )
return V_19 ;
if ( V_19 != sizeof( * V_131 ) )
return - V_26 ;
if ( V_71 -> V_85 + 1 != F_14 ( V_131 -> V_132 ) )
V_19 = - V_26 ;
else
V_19 = 0 ;
F_3 ( L_21 ,
V_71 -> V_85 , F_14 ( V_131 -> V_132 ) , V_19 ) ;
return V_19 ;
}
static void F_62 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_3 ( L_22 ) ;
V_4 -> V_112 = true ;
V_4 -> V_102 = 0 ;
}
static void F_63 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_31 * V_23 ;
F_3 ( L_23 , V_2 ) ;
F_23 ( & V_4 -> V_13 ) ;
while ( ( V_23 = F_64 ( & V_4 -> V_33 ) ) != NULL ) {
struct V_28 * V_30 =
F_16 ( V_23 , struct V_28 , V_34 ) ;
F_21 ( V_2 , V_30 ) ;
}
F_39 ( & V_4 -> V_96 ) ;
F_25 ( V_2 -> V_5 ) ;
V_2 -> V_5 = NULL ;
}
static void F_65 ( struct V_1 * V_2 , int V_118 )
{
struct V_28 * V_30 ;
V_30 = F_15 ( V_2 , V_118 ) ;
if ( ! F_30 ( V_30 ) )
V_30 -> V_65 = false ;
}
static void F_66 ( struct V_1 * V_2 ,
int V_118 )
{
F_65 ( V_2 , V_118 ) ;
F_65 ( V_2 , V_92 ) ;
}
static int F_67 ( struct V_70 * V_71 , struct V_133 * V_134 ,
V_105 * V_135 )
{
void * V_95 = V_71 -> V_95 ;
struct {
T_3 V_86 ;
T_3 V_136 ;
T_3 V_137 ;
T_3 V_138 ;
T_3 V_139 ;
} V_140 * V_141 = V_95 + F_5 () ;
int V_19 ;
V_141 -> V_86 = F_43 ( 4 * sizeof( V_9 ) ) ;
V_141 -> V_136 = V_134 -> V_17 . V_142 ;
V_141 -> V_137 = V_134 -> V_143 . V_137 ;
V_141 -> V_138 = V_134 -> V_143 . V_138 ;
V_141 -> V_139 = V_134 -> V_143 . V_139 ;
V_19 = F_7 ( & V_71 -> V_39 , V_95 , V_103 ,
sizeof( * V_141 ) ) ;
if ( V_19 < 0 )
return V_19 ;
* V_135 = * ( V_105 * ) ( V_95 + sizeof( V_9 ) ) ;
return 0 ;
}
static int F_68 ( struct V_119 * V_94 ,
struct V_133 * V_134 )
{
V_105 V_144 ;
int V_19 ;
if ( F_69 ( F_70 ( V_134 -> V_145 -> V_146 ) , V_147 ) )
return 0 ;
V_19 = F_67 ( (struct V_70 * ) V_94 -> V_122 ,
V_134 , & V_144 ) ;
if ( V_19 )
return V_19 ;
V_134 -> V_143 . V_144 = V_144 ;
V_134 -> V_143 . V_148 |= V_149 ;
return 0 ;
}
static int F_71 ( struct V_119 * V_94 ,
struct V_133 * V_134 )
{
V_105 V_150 ;
int V_19 ;
if ( F_69 ( F_70 ( V_134 -> V_145 -> V_146 ) , V_147 ) )
return 0 ;
V_19 = F_67 ( (struct V_70 * ) V_94 -> V_122 ,
V_134 , & V_150 ) ;
if ( V_19 )
return V_19 ;
if ( V_150 == V_134 -> V_143 . V_144 )
return 0 ;
if ( V_134 -> V_143 . V_148 & V_149 )
F_3 ( L_24
L_25 , V_134 , V_134 -> V_143 . V_144 , V_150 ) ;
else
F_3 ( L_26
L_27 , V_134 ) ;
return - V_151 ;
}
int F_72 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_19 ;
F_3 ( L_28 , V_2 ) ;
V_19 = - V_38 ;
V_4 = F_17 ( sizeof( * V_4 ) , V_37 ) ;
if ( ! V_4 )
goto V_59;
V_19 = - V_27 ;
if ( ! V_2 -> V_104 ) {
F_73 ( L_29 ) ;
goto V_152;
}
V_19 = F_41 ( & V_4 -> V_13 , V_2 -> V_104 ) ;
if ( V_19 < 0 ) {
F_73 ( L_30 , V_19 ) ;
goto V_152;
}
V_4 -> V_112 = true ;
V_4 -> V_33 = V_153 ;
V_2 -> V_154 = V_155 ;
V_2 -> V_5 = V_4 ;
V_2 -> V_128 = & V_156 ;
return 0 ;
V_152:
F_25 ( V_4 ) ;
V_59:
return V_19 ;
}
