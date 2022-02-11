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
void * * V_22 , void * V_23 , void * V_15 , T_1 V_16 )
{
struct V_10 V_17 ;
T_1 V_24 = sizeof( V_17 ) ;
int V_20 , V_21 ;
V_20 = F_11 ( V_22 ) ;
if ( * V_22 + V_20 > V_23 )
return - V_25 ;
F_3 ( L_3 , V_20 ) ;
V_21 = F_12 ( V_13 , & V_17 , & V_24 , V_15 , & V_16 ,
* V_22 , V_20 ) ;
if ( V_21 )
return V_21 ;
if ( V_17 . V_18 != 1 || F_13 ( V_17 . V_19 ) != V_26 )
return - V_27 ;
* V_22 += V_20 ;
return V_16 ;
}
static struct V_28 *
F_14 ( struct V_1 * V_2 , int V_29 )
{
struct V_28 * V_30 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_31 * V_32 = NULL , * * V_22 = & V_4 -> V_33 . V_31 ;
while ( * V_22 ) {
V_32 = * V_22 ;
V_30 = F_15 ( V_32 , struct V_28 , V_34 ) ;
if ( V_29 < V_30 -> V_29 )
V_22 = & ( * V_22 ) -> V_35 ;
else if ( V_29 > V_30 -> V_29 )
V_22 = & ( * V_22 ) -> V_36 ;
else
return V_30 ;
}
V_30 = F_16 ( sizeof( * V_30 ) , V_37 ) ;
if ( ! V_30 )
return F_17 ( - V_38 ) ;
V_30 -> V_29 = V_29 ;
F_18 ( & V_30 -> V_34 , V_32 , V_22 ) ;
F_19 ( & V_30 -> V_34 , & V_4 -> V_33 ) ;
return V_30 ;
}
static void F_20 ( struct V_1 * V_2 ,
struct V_28 * V_30 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_3 ( L_4 , V_30 , V_30 -> V_29 ) ;
F_21 ( & V_30 -> V_34 , & V_4 -> V_33 ) ;
F_22 ( & V_30 -> V_39 ) ;
if ( V_30 -> V_40 )
F_23 ( V_30 -> V_40 ) ;
F_24 ( V_30 ) ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_12 * V_13 ,
void * V_41 , void * V_23 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_42 ;
void * V_22 = V_41 ;
int V_21 ;
char * V_43 ;
char * V_44 ;
T_2 V_45 ;
V_43 = F_26 ( V_46 , V_37 ) ;
if ( ! V_43 )
return - V_38 ;
V_21 = - V_38 ;
V_44 = F_26 ( V_46 , V_37 ) ;
if ( ! V_44 )
goto V_47;
F_27 ( & V_22 , V_23 , 1 + sizeof( V_11 ) , V_48 ) ;
V_45 = F_28 ( & V_22 ) ;
if ( V_45 != 1 )
goto V_48;
V_42 = F_11 ( & V_22 ) ;
F_3 ( L_5 , V_42 ) ;
while ( V_42 -- ) {
int type ;
T_2 V_49 , V_50 ;
struct V_28 * V_30 ;
void * V_51 , * V_52 ;
int V_53 ;
char V_54 ;
struct V_55 V_56 ;
struct V_12 V_57 ;
void * V_58 , * V_59 ;
struct V_60 V_61 ;
struct V_12 V_62 ;
struct V_63 * V_64 ;
unsigned long V_65 , V_66 ;
T_3 V_67 ;
F_27 ( & V_22 , V_23 , sizeof( V_11 ) + 1 , V_48 ) ;
type = F_11 ( & V_22 ) ;
F_3 ( L_6 , type , F_29 ( type ) ) ;
V_49 = F_28 ( & V_22 ) ;
if ( V_49 != 1 )
goto V_48;
V_30 = F_14 ( V_2 , type ) ;
if ( F_30 ( V_30 ) ) {
V_21 = F_31 ( V_30 ) ;
goto V_68;
}
V_53 = F_10 ( V_13 , & V_22 , V_23 , V_43 ,
V_46 ) ;
if ( V_53 <= 0 ) {
V_21 = V_53 ;
goto V_68;
}
F_3 ( L_7 , V_53 ) ;
V_52 = V_43 + V_53 ;
V_51 = V_43 ;
V_49 = F_28 ( & V_51 ) ;
if ( V_49 != 1 )
goto V_48;
memcpy ( & V_57 , & V_30 -> V_39 , sizeof( V_57 ) ) ;
V_21 = F_32 ( & V_62 , & V_51 , V_52 ) ;
if ( V_21 )
goto V_68;
F_33 ( & V_51 , & V_61 , sizeof( V_61 ) ) ;
F_34 ( & V_56 , & V_61 ) ;
V_65 = F_35 () + V_56 . V_69 ;
V_66 = V_65 - ( V_56 . V_69 / 4 ) ;
F_3 ( L_8 , V_65 ,
V_66 ) ;
F_36 ( & V_22 , V_23 , V_54 , V_48 ) ;
V_58 = V_44 ;
if ( V_54 ) {
F_3 ( L_9 ) ;
V_53 = F_10 ( & V_57 , & V_22 , V_23 , V_44 ,
V_46 ) ;
if ( V_53 < 0 ) {
V_21 = V_53 ;
goto V_68;
}
V_53 = F_11 ( & V_58 ) ;
} else {
F_37 ( & V_22 , V_23 , V_53 , V_48 ) ;
F_27 ( & V_22 , V_23 , V_53 , V_48 ) ;
F_33 ( & V_22 , V_44 , V_53 ) ;
}
V_59 = V_58 + V_53 ;
F_3 ( L_10 , V_53 ) ;
F_27 ( & V_58 , V_59 , 1 + sizeof( T_3 ) , V_48 ) ;
V_50 = F_28 ( & V_58 ) ;
V_67 = F_38 ( & V_58 ) ;
V_21 = F_39 ( & V_64 , & V_58 , V_59 ) ;
if ( V_21 )
goto V_68;
F_22 ( & V_30 -> V_39 ) ;
if ( V_30 -> V_40 )
F_23 ( V_30 -> V_40 ) ;
V_30 -> V_39 = V_62 ;
V_30 -> V_40 = V_64 ;
V_30 -> V_56 = V_61 ;
V_30 -> V_70 = V_67 ;
V_30 -> V_71 = V_65 ;
V_30 -> V_72 = V_66 ;
F_3 ( L_11 ,
type , F_29 ( type ) , V_30 -> V_70 ,
( int ) V_30 -> V_40 -> V_73 . V_74 ) ;
V_4 -> V_8 |= V_30 -> V_29 ;
}
V_21 = 0 ;
V_68:
F_24 ( V_44 ) ;
V_47:
F_24 ( V_43 ) ;
return V_21 ;
V_48:
V_21 = - V_25 ;
goto V_68;
}
static int F_40 ( struct V_1 * V_2 ,
struct V_28 * V_30 ,
struct V_75 * V_76 )
{
int V_77 ;
struct V_78 * V_79 ;
struct V_80 V_81 ;
void * V_22 , * V_23 ;
int V_21 ;
int V_82 =
( V_30 -> V_40 ? V_30 -> V_40 -> V_73 . V_74 : 0 ) ;
F_3 ( L_12 ,
F_29 ( V_30 -> V_29 ) , V_76 ) ;
V_77 = sizeof( * V_79 ) + sizeof( V_81 ) +
F_5 ( V_82 ) ;
F_3 ( L_13 , V_77 ) ;
if ( V_76 -> V_41 && V_76 -> V_41 -> V_83 < V_77 ) {
F_23 ( V_76 -> V_41 ) ;
V_76 -> V_41 = NULL ;
}
if ( ! V_76 -> V_41 ) {
V_76 -> V_41 = F_41 ( V_77 , V_37 ) ;
if ( ! V_76 -> V_41 )
return - V_38 ;
}
V_76 -> V_29 = V_30 -> V_29 ;
V_79 = V_76 -> V_41 -> V_73 . V_84 ;
V_79 -> V_18 = 1 ;
V_79 -> V_85 = F_7 ( V_2 -> V_85 ) ;
V_79 -> V_86 = F_42 ( V_30 -> V_29 ) ;
V_79 -> V_40 . V_18 = 1 ;
V_79 -> V_40 . V_70 = F_7 ( V_30 -> V_70 ) ;
V_79 -> V_40 . V_87 = F_42 ( V_82 ) ;
if ( V_82 ) {
memcpy ( V_79 -> V_40 . V_88 , V_30 -> V_40 -> V_73 . V_84 ,
V_30 -> V_40 -> V_73 . V_74 ) ;
}
F_3 ( L_14 , V_30 , V_30 -> V_70 ,
F_13 ( V_79 -> V_40 . V_70 ) ) ;
V_22 = V_79 + 1 ;
V_22 += V_82 ;
V_23 = V_76 -> V_41 -> V_73 . V_84 + V_76 -> V_41 -> V_73 . V_74 ;
F_43 ( & V_76 -> V_89 , sizeof( V_76 -> V_89 ) ) ;
V_81 . V_18 = 1 ;
V_81 . V_89 = F_7 ( V_76 -> V_89 ) ;
V_21 = F_6 ( & V_30 -> V_39 , & V_81 , sizeof( V_81 ) ,
V_22 , V_23 - V_22 ) ;
if ( V_21 < 0 )
goto V_90;
V_22 += V_21 ;
V_76 -> V_41 -> V_73 . V_74 = V_22 - V_76 -> V_41 -> V_73 . V_84 ;
F_3 ( L_15 , V_76 -> V_89 ,
( int ) V_76 -> V_41 -> V_73 . V_74 ) ;
F_44 ( V_76 -> V_41 -> V_73 . V_74 > V_77 ) ;
return 0 ;
V_90:
F_23 ( V_76 -> V_41 ) ;
V_76 -> V_41 = NULL ;
return V_21 ;
}
static int F_45 ( struct V_28 * V_30 ,
void * * V_22 , void * V_23 )
{
F_27 ( V_22 , V_23 , 1 + sizeof( T_3 ) , V_48 ) ;
F_46 ( V_22 , 1 ) ;
F_47 ( V_22 , V_30 -> V_70 ) ;
if ( V_30 -> V_40 ) {
const char * V_41 = V_30 -> V_40 -> V_73 . V_84 ;
V_11 V_20 = V_30 -> V_40 -> V_73 . V_74 ;
F_48 ( V_22 , V_23 , V_20 , V_48 ) ;
F_49 ( V_22 , V_23 , V_41 , V_20 , V_48 ) ;
} else {
F_48 ( V_22 , V_23 , 0 , V_48 ) ;
}
return 0 ;
V_48:
return - V_91 ;
}
static void F_2 ( struct V_1 * V_2 , int * V_92 )
{
int V_93 = V_2 -> V_7 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_29 ;
* V_92 = V_2 -> V_7 & ~ ( V_4 -> V_8 ) ;
for ( V_29 = 1 ; V_29 <= V_93 ; V_29 <<= 1 ) {
struct V_28 * V_30 ;
if ( ! ( V_2 -> V_7 & V_29 ) )
continue;
if ( * V_92 & V_29 )
continue;
V_30 = F_14 ( V_2 , V_29 ) ;
if ( F_30 ( V_30 ) ) {
* V_92 |= V_29 ;
continue;
}
if ( F_35 () >= V_30 -> V_72 )
* V_92 |= V_29 ;
if ( F_35 () >= V_30 -> V_71 )
V_4 -> V_8 &= ~ V_29 ;
}
}
static int F_50 ( struct V_1 * V_2 ,
void * V_41 , void * V_23 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_6 ;
struct V_94 * V_17 = V_41 ;
int V_21 ;
struct V_28 * V_30 =
F_14 ( V_2 , V_95 ) ;
if ( F_30 ( V_30 ) )
return F_31 ( V_30 ) ;
F_2 ( V_2 , & V_6 ) ;
F_3 ( L_16 ,
V_2 -> V_7 , V_4 -> V_8 , V_6 ) ;
if ( V_6 & V_95 ) {
struct V_96 * V_97 = ( void * ) ( V_17 + 1 ) ;
void * V_22 = V_97 + 1 ;
struct V_98 V_99 ;
char V_100 [ 40 ] ;
T_3 * V_101 ;
if ( V_22 > V_23 )
return - V_91 ;
F_3 ( L_17 ) ;
V_17 -> V_102 = F_51 ( V_103 ) ;
F_43 ( & V_97 -> V_104 , sizeof( T_3 ) ) ;
V_99 . V_104 = V_97 -> V_104 ;
V_99 . V_105 = F_7 ( V_4 -> V_105 ) ;
V_21 = F_6 ( & V_4 -> V_13 , & V_99 , sizeof( V_99 ) ,
V_100 , sizeof( V_100 ) ) ;
if ( V_21 < 0 )
return V_21 ;
V_97 -> V_18 = 1 ;
V_97 -> V_106 = 0 ;
for ( V_101 = ( T_3 * ) V_100 ; V_101 + 1 <= ( T_3 * ) ( V_100 + V_21 ) ; V_101 ++ )
V_97 -> V_106 ^= * ( V_107 * ) V_101 ;
F_3 ( L_18 ,
V_4 -> V_105 , F_13 ( V_97 -> V_104 ) ,
F_13 ( V_97 -> V_106 ) ) ;
V_21 = F_45 ( V_30 , & V_22 , V_23 ) ;
if ( V_21 < 0 )
return V_21 ;
return V_22 - V_41 ;
}
if ( V_6 ) {
void * V_22 = V_17 + 1 ;
struct V_108 * V_109 ;
if ( V_22 > V_23 )
return - V_91 ;
V_17 -> V_102 = F_51 ( V_110 ) ;
V_21 = F_40 ( V_2 , V_30 , & V_4 -> V_111 ) ;
if ( V_21 )
return V_21 ;
F_52 ( & V_22 , V_4 -> V_111 . V_41 -> V_73 . V_84 ,
V_4 -> V_111 . V_41 -> V_73 . V_74 ) ;
V_109 = V_22 ;
V_109 -> V_112 = F_42 ( V_6 ) ;
V_22 += sizeof( * V_109 ) ;
return V_22 - V_41 ;
}
return 0 ;
}
static int F_53 ( struct V_1 * V_2 , int V_113 ,
void * V_41 , void * V_23 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_114 * V_17 = V_41 ;
struct V_28 * V_30 ;
int V_20 = V_23 - V_41 ;
int V_102 ;
int V_21 ;
if ( V_113 )
return V_113 ;
if ( V_4 -> V_115 ) {
struct V_116 * V_117 = V_41 ;
if ( V_20 != sizeof( * V_117 ) )
return - V_25 ;
V_4 -> V_105 = F_13 ( V_117 -> V_105 ) ;
F_3 ( L_19 ,
V_4 -> V_105 ) ;
V_4 -> V_115 = false ;
V_4 -> V_8 &= ~ V_95 ;
return - V_118 ;
}
V_102 = F_54 ( V_17 -> V_102 ) ;
V_113 = F_55 ( V_17 -> V_113 ) ;
F_3 ( L_20 , V_102 , V_113 ) ;
switch ( V_102 ) {
case V_103 :
V_21 = F_25 ( V_2 , & V_4 -> V_13 ,
V_41 + sizeof( * V_17 ) , V_23 ) ;
break;
case V_110 :
V_30 = F_14 ( V_2 , V_95 ) ;
if ( F_30 ( V_30 ) )
return F_31 ( V_30 ) ;
V_21 = F_25 ( V_2 , & V_30 -> V_39 ,
V_41 + sizeof( * V_17 ) , V_23 ) ;
break;
default:
return - V_25 ;
}
if ( V_21 )
return V_21 ;
if ( V_2 -> V_7 == V_4 -> V_8 )
return 0 ;
return - V_118 ;
}
static int F_56 (
struct V_1 * V_2 , int V_119 ,
struct V_120 * * V_121 ,
void * * V_41 , T_1 * V_20 ,
void * * V_122 , T_1 * V_123 )
{
struct V_75 * V_76 ;
struct V_28 * V_30 ;
int V_21 ;
V_30 = F_14 ( V_2 , V_119 ) ;
if ( F_30 ( V_30 ) )
return F_31 ( V_30 ) ;
V_76 = F_16 ( sizeof( * V_76 ) , V_37 ) ;
if ( ! V_76 )
return - V_38 ;
V_21 = F_40 ( V_2 , V_30 , V_76 ) ;
if ( V_21 ) {
F_24 ( V_76 ) ;
return V_21 ;
}
* V_121 = (struct V_120 * ) V_76 ;
* V_41 = V_76 -> V_41 -> V_73 . V_84 ;
* V_20 = V_76 -> V_41 -> V_73 . V_74 ;
* V_122 = V_76 -> V_122 ;
* V_123 = sizeof( V_76 -> V_122 ) ;
return 0 ;
}
static int F_57 ( struct V_1 * V_2 ,
struct V_120 * V_121 , T_1 V_20 )
{
struct V_75 * V_76 = ( void * ) V_121 ;
struct V_28 * V_30 ;
int V_21 = 0 ;
struct V_124 V_125 ;
void * V_22 = V_76 -> V_122 ;
void * V_23 = V_22 + sizeof( V_76 -> V_122 ) ;
V_30 = F_14 ( V_2 , V_76 -> V_29 ) ;
if ( F_30 ( V_30 ) )
return F_31 ( V_30 ) ;
V_21 = F_10 ( & V_30 -> V_39 , & V_22 , V_23 , & V_125 , sizeof( V_125 ) ) ;
if ( V_21 < 0 )
return V_21 ;
if ( V_21 != sizeof( V_125 ) )
return - V_27 ;
if ( V_76 -> V_89 + 1 != F_13 ( V_125 . V_126 ) )
V_21 = - V_27 ;
else
V_21 = 0 ;
F_3 ( L_21 ,
V_76 -> V_89 , F_13 ( V_125 . V_126 ) , V_21 ) ;
return V_21 ;
}
static void F_58 ( struct V_1 * V_2 ,
struct V_120 * V_121 )
{
struct V_75 * V_76 = ( void * ) V_121 ;
F_23 ( V_76 -> V_41 ) ;
F_24 ( V_76 ) ;
}
static void F_59 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_3 ( L_22 ) ;
V_4 -> V_115 = true ;
V_4 -> V_105 = 0 ;
}
static void F_60 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_31 * V_22 ;
F_3 ( L_23 , V_2 ) ;
F_22 ( & V_4 -> V_13 ) ;
while ( ( V_22 = F_61 ( & V_4 -> V_33 ) ) != NULL ) {
struct V_28 * V_30 =
F_15 ( V_22 , struct V_28 , V_34 ) ;
F_20 ( V_2 , V_30 ) ;
}
if ( V_4 -> V_111 . V_41 )
F_23 ( V_4 -> V_111 . V_41 ) ;
F_24 ( V_2 -> V_5 ) ;
V_2 -> V_5 = NULL ;
}
static void F_62 ( struct V_1 * V_2 ,
int V_119 )
{
struct V_28 * V_30 ;
V_30 = F_14 ( V_2 , V_119 ) ;
if ( ! F_30 ( V_30 ) )
F_20 ( V_2 , V_30 ) ;
}
int F_63 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_21 ;
F_3 ( L_24 , V_2 ) ;
V_21 = - V_38 ;
V_4 = F_16 ( sizeof( * V_4 ) , V_37 ) ;
if ( ! V_4 )
goto V_68;
V_21 = - V_25 ;
if ( ! V_2 -> V_106 ) {
F_64 ( L_25 ) ;
goto V_127;
}
V_21 = F_65 ( & V_4 -> V_13 , V_2 -> V_106 ) ;
if ( V_21 < 0 ) {
F_64 ( L_26 , V_21 ) ;
goto V_127;
}
V_4 -> V_115 = true ;
V_4 -> V_33 = V_128 ;
V_2 -> V_129 = V_130 ;
V_2 -> V_5 = V_4 ;
V_2 -> V_131 = & V_132 ;
return 0 ;
V_127:
F_24 ( V_4 ) ;
V_68:
return V_21 ;
}
