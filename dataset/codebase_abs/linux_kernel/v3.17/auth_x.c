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
struct V_54 V_55 ;
struct V_12 V_56 ;
struct V_57 * V_58 ;
unsigned long V_59 , V_60 ;
T_3 V_61 ;
int V_21 ;
F_27 ( V_22 , V_23 , sizeof( V_11 ) + 1 , V_62 ) ;
type = F_11 ( V_22 ) ;
F_3 ( L_5 , type , F_28 ( type ) ) ;
V_41 = F_29 ( V_22 ) ;
if ( V_41 != 1 )
goto V_62;
V_32 = F_15 ( V_2 , type ) ;
if ( F_30 ( V_32 ) ) {
V_21 = F_31 ( V_32 ) ;
goto V_63;
}
V_46 = F_10 ( V_13 , V_22 , V_23 , & V_43 , 0 ) ;
if ( V_46 <= 0 ) {
V_21 = V_46 ;
goto V_63;
}
F_3 ( L_6 , V_46 ) ;
V_44 = V_43 ;
V_45 = V_44 + V_46 ;
V_41 = F_29 ( & V_44 ) ;
if ( V_41 != 1 )
goto V_62;
memcpy ( & V_50 , & V_32 -> V_39 , sizeof( V_50 ) ) ;
V_21 = F_32 ( & V_56 , & V_44 , V_45 ) ;
if ( V_21 )
goto V_63;
F_33 ( & V_44 , & V_55 , sizeof( V_55 ) ) ;
F_34 ( & V_49 , & V_55 ) ;
V_59 = F_35 () + V_49 . V_64 ;
V_60 = V_59 - ( V_49 . V_64 / 4 ) ;
F_3 ( L_7 , V_59 ,
V_60 ) ;
F_36 ( V_22 , V_23 , V_47 , V_62 ) ;
if ( V_47 ) {
F_3 ( L_8 ) ;
V_46 = F_10 ( & V_50 , V_22 , V_23 , & V_51 , 0 ) ;
if ( V_46 < 0 ) {
V_21 = V_46 ;
goto V_63;
}
V_52 = V_51 ;
V_46 = F_11 ( & V_52 ) ;
} else {
F_37 ( V_22 , V_23 , V_46 , V_62 ) ;
V_51 = F_12 ( V_46 , V_26 ) ;
if ( ! V_51 ) {
V_21 = - V_27 ;
goto V_63;
}
V_52 = V_51 ;
F_27 ( V_22 , V_23 , V_46 , V_62 ) ;
F_33 ( V_22 , V_51 , V_46 ) ;
}
V_53 = V_52 + V_46 ;
F_3 ( L_9 , V_46 ) ;
F_27 ( & V_52 , V_53 , 1 + sizeof( T_3 ) , V_62 ) ;
V_42 = F_29 ( & V_52 ) ;
V_61 = F_38 ( & V_52 ) ;
V_21 = F_39 ( & V_58 , & V_52 , V_53 ) ;
if ( V_21 )
goto V_63;
F_23 ( & V_32 -> V_39 ) ;
if ( V_32 -> V_40 )
F_24 ( V_32 -> V_40 ) ;
V_32 -> V_39 = V_56 ;
V_32 -> V_40 = V_58 ;
V_32 -> V_49 = V_55 ;
V_32 -> V_65 = V_61 ;
V_32 -> V_66 = V_59 ;
V_32 -> V_67 = V_60 ;
F_3 ( L_10 ,
type , F_28 ( type ) , V_32 -> V_65 ,
( int ) V_32 -> V_40 -> V_68 . V_69 ) ;
V_4 -> V_8 |= V_32 -> V_31 ;
V_63:
F_25 ( V_51 ) ;
F_25 ( V_43 ) ;
return V_21 ;
V_62:
V_21 = - V_25 ;
goto V_63;
}
static int F_40 ( struct V_1 * V_2 ,
struct V_12 * V_13 ,
void * V_70 , void * V_23 )
{
void * V_22 = V_70 ;
T_2 V_71 ;
V_11 V_72 ;
int V_21 ;
F_36 ( & V_22 , V_23 , V_71 , V_62 ) ;
if ( V_71 != 1 )
return - V_25 ;
F_37 ( & V_22 , V_23 , V_72 , V_62 ) ;
F_3 ( L_11 , V_72 ) ;
while ( V_72 -- ) {
V_21 = F_26 ( V_2 , V_13 , & V_22 , V_23 ) ;
if ( V_21 )
return V_21 ;
}
return 0 ;
V_62:
return - V_25 ;
}
static int F_41 ( struct V_1 * V_2 ,
struct V_30 * V_32 ,
struct V_73 * V_74 )
{
int V_75 ;
struct V_76 * V_77 ;
struct V_78 V_79 ;
void * V_22 , * V_23 ;
int V_21 ;
int V_80 =
( V_32 -> V_40 ? V_32 -> V_40 -> V_68 . V_69 : 0 ) ;
F_3 ( L_12 ,
F_28 ( V_32 -> V_31 ) , V_74 ) ;
V_75 = sizeof( * V_77 ) + sizeof( V_79 ) +
F_5 ( V_80 ) ;
F_3 ( L_13 , V_75 ) ;
if ( V_74 -> V_70 && V_74 -> V_70 -> V_81 < V_75 ) {
F_24 ( V_74 -> V_70 ) ;
V_74 -> V_70 = NULL ;
}
if ( ! V_74 -> V_70 ) {
V_74 -> V_70 = F_42 ( V_75 , V_26 ) ;
if ( ! V_74 -> V_70 )
return - V_27 ;
}
V_74 -> V_31 = V_32 -> V_31 ;
V_74 -> V_65 = V_32 -> V_65 ;
V_77 = V_74 -> V_70 -> V_68 . V_82 ;
V_77 -> V_18 = 1 ;
V_77 -> V_83 = F_7 ( V_2 -> V_83 ) ;
V_77 -> V_84 = F_43 ( V_32 -> V_31 ) ;
V_77 -> V_40 . V_18 = 1 ;
V_77 -> V_40 . V_65 = F_7 ( V_32 -> V_65 ) ;
V_77 -> V_40 . V_85 = F_43 ( V_80 ) ;
if ( V_80 ) {
memcpy ( V_77 -> V_40 . V_86 , V_32 -> V_40 -> V_68 . V_82 ,
V_32 -> V_40 -> V_68 . V_69 ) ;
}
F_3 ( L_14 , V_32 , V_32 -> V_65 ,
F_14 ( V_77 -> V_40 . V_65 ) ) ;
V_22 = V_77 + 1 ;
V_22 += V_80 ;
V_23 = V_74 -> V_70 -> V_68 . V_82 + V_74 -> V_70 -> V_68 . V_69 ;
F_44 ( & V_74 -> V_87 , sizeof( V_74 -> V_87 ) ) ;
V_79 . V_18 = 1 ;
V_79 . V_87 = F_7 ( V_74 -> V_87 ) ;
V_21 = F_6 ( & V_32 -> V_39 , & V_79 , sizeof( V_79 ) ,
V_22 , V_23 - V_22 ) ;
if ( V_21 < 0 )
goto V_88;
V_22 += V_21 ;
V_74 -> V_70 -> V_68 . V_69 = V_22 - V_74 -> V_70 -> V_68 . V_82 ;
F_3 ( L_15 , V_74 -> V_87 ,
( int ) V_74 -> V_70 -> V_68 . V_69 ) ;
F_45 ( V_74 -> V_70 -> V_68 . V_69 > V_75 ) ;
return 0 ;
V_88:
F_24 ( V_74 -> V_70 ) ;
V_74 -> V_70 = NULL ;
return V_21 ;
}
static int F_46 ( struct V_30 * V_32 ,
void * * V_22 , void * V_23 )
{
F_27 ( V_22 , V_23 , 1 + sizeof( T_3 ) , V_62 ) ;
F_47 ( V_22 , 1 ) ;
F_48 ( V_22 , V_32 -> V_65 ) ;
if ( V_32 -> V_40 ) {
const char * V_70 = V_32 -> V_40 -> V_68 . V_82 ;
V_11 V_20 = V_32 -> V_40 -> V_68 . V_69 ;
F_49 ( V_22 , V_23 , V_20 , V_62 ) ;
F_50 ( V_22 , V_23 , V_70 , V_20 , V_62 ) ;
} else {
F_49 ( V_22 , V_23 , 0 , V_62 ) ;
}
return 0 ;
V_62:
return - V_89 ;
}
static void F_2 ( struct V_1 * V_2 , int * V_90 )
{
int V_91 = V_2 -> V_7 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_31 ;
* V_90 = V_2 -> V_7 & ~ ( V_4 -> V_8 ) ;
for ( V_31 = 1 ; V_31 <= V_91 ; V_31 <<= 1 ) {
struct V_30 * V_32 ;
if ( ! ( V_2 -> V_7 & V_31 ) )
continue;
if ( * V_90 & V_31 )
continue;
V_32 = F_15 ( V_2 , V_31 ) ;
if ( F_30 ( V_32 ) ) {
* V_90 |= V_31 ;
continue;
}
if ( F_35 () >= V_32 -> V_67 )
* V_90 |= V_31 ;
if ( F_35 () >= V_32 -> V_66 )
V_4 -> V_8 &= ~ V_31 ;
}
}
static int F_51 ( struct V_1 * V_2 ,
void * V_70 , void * V_23 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_6 ;
struct V_92 * V_17 = V_70 ;
int V_21 ;
struct V_30 * V_32 =
F_15 ( V_2 , V_93 ) ;
if ( F_30 ( V_32 ) )
return F_31 ( V_32 ) ;
F_2 ( V_2 , & V_6 ) ;
F_3 ( L_16 ,
V_2 -> V_7 , V_4 -> V_8 , V_6 ) ;
if ( V_6 & V_93 ) {
struct V_94 * V_95 = ( void * ) ( V_17 + 1 ) ;
void * V_22 = V_95 + 1 ;
struct V_96 V_97 ;
char V_98 [ 40 ] ;
T_3 * V_99 ;
if ( V_22 > V_23 )
return - V_89 ;
F_3 ( L_17 ) ;
V_17 -> V_100 = F_52 ( V_101 ) ;
F_44 ( & V_95 -> V_102 , sizeof( T_3 ) ) ;
V_97 . V_102 = V_95 -> V_102 ;
V_97 . V_103 = F_7 ( V_4 -> V_103 ) ;
V_21 = F_6 ( & V_4 -> V_13 , & V_97 , sizeof( V_97 ) ,
V_98 , sizeof( V_98 ) ) ;
if ( V_21 < 0 )
return V_21 ;
V_95 -> V_18 = 1 ;
V_95 -> V_104 = 0 ;
for ( V_99 = ( T_3 * ) V_98 ; V_99 + 1 <= ( T_3 * ) ( V_98 + V_21 ) ; V_99 ++ )
V_95 -> V_104 ^= * ( V_105 * ) V_99 ;
F_3 ( L_18 ,
V_4 -> V_103 , F_14 ( V_95 -> V_102 ) ,
F_14 ( V_95 -> V_104 ) ) ;
V_21 = F_46 ( V_32 , & V_22 , V_23 ) ;
if ( V_21 < 0 )
return V_21 ;
return V_22 - V_70 ;
}
if ( V_6 ) {
void * V_22 = V_17 + 1 ;
struct V_106 * V_107 ;
if ( V_22 > V_23 )
return - V_89 ;
V_17 -> V_100 = F_52 ( V_108 ) ;
V_21 = F_41 ( V_2 , V_32 , & V_4 -> V_109 ) ;
if ( V_21 )
return V_21 ;
F_53 ( & V_22 , V_4 -> V_109 . V_70 -> V_68 . V_82 ,
V_4 -> V_109 . V_70 -> V_68 . V_69 ) ;
V_107 = V_22 ;
V_107 -> V_110 = F_43 ( V_6 ) ;
V_22 += sizeof( * V_107 ) ;
return V_22 - V_70 ;
}
return 0 ;
}
static int F_54 ( struct V_1 * V_2 , int V_111 ,
void * V_70 , void * V_23 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_112 * V_17 = V_70 ;
struct V_30 * V_32 ;
int V_20 = V_23 - V_70 ;
int V_100 ;
int V_21 ;
if ( V_111 )
return V_111 ;
if ( V_4 -> V_113 ) {
struct V_114 * V_115 = V_70 ;
if ( V_20 != sizeof( * V_115 ) )
return - V_25 ;
V_4 -> V_103 = F_14 ( V_115 -> V_103 ) ;
F_3 ( L_19 ,
V_4 -> V_103 ) ;
V_4 -> V_113 = false ;
V_4 -> V_8 &= ~ V_93 ;
return - V_116 ;
}
V_100 = F_55 ( V_17 -> V_100 ) ;
V_111 = F_56 ( V_17 -> V_111 ) ;
F_3 ( L_20 , V_100 , V_111 ) ;
switch ( V_100 ) {
case V_101 :
V_21 = F_40 ( V_2 , & V_4 -> V_13 ,
V_70 + sizeof( * V_17 ) , V_23 ) ;
break;
case V_108 :
V_32 = F_15 ( V_2 , V_93 ) ;
if ( F_30 ( V_32 ) )
return F_31 ( V_32 ) ;
V_21 = F_40 ( V_2 , & V_32 -> V_39 ,
V_70 + sizeof( * V_17 ) , V_23 ) ;
break;
default:
return - V_25 ;
}
if ( V_21 )
return V_21 ;
if ( V_2 -> V_7 == V_4 -> V_8 )
return 0 ;
return - V_116 ;
}
static int F_57 (
struct V_1 * V_2 , int V_117 ,
struct V_118 * V_95 )
{
struct V_73 * V_74 ;
struct V_30 * V_32 ;
int V_21 ;
V_32 = F_15 ( V_2 , V_117 ) ;
if ( F_30 ( V_32 ) )
return F_31 ( V_32 ) ;
V_74 = F_17 ( sizeof( * V_74 ) , V_26 ) ;
if ( ! V_74 )
return - V_27 ;
V_21 = F_41 ( V_2 , V_32 , V_74 ) ;
if ( V_21 ) {
F_25 ( V_74 ) ;
return V_21 ;
}
V_95 -> V_119 = (struct V_120 * ) V_74 ;
V_95 -> V_121 = V_74 -> V_70 -> V_68 . V_82 ;
V_95 -> V_122 = V_74 -> V_70 -> V_68 . V_69 ;
V_95 -> V_123 = V_74 -> V_124 ;
V_95 -> V_125 = sizeof ( V_74 -> V_124 ) ;
return 0 ;
}
static int F_58 (
struct V_1 * V_2 , int V_117 ,
struct V_118 * V_95 )
{
struct V_73 * V_74 ;
struct V_30 * V_32 ;
V_32 = F_15 ( V_2 , V_117 ) ;
if ( F_30 ( V_32 ) )
return F_31 ( V_32 ) ;
V_74 = (struct V_73 * ) V_95 -> V_119 ;
if ( V_74 -> V_65 < V_32 -> V_65 ) {
F_3 ( L_21 ,
V_74 -> V_31 , V_74 -> V_65 , V_32 -> V_65 ) ;
return F_41 ( V_2 , V_32 , V_74 ) ;
}
return 0 ;
}
static int F_59 ( struct V_1 * V_2 ,
struct V_120 * V_126 , T_1 V_20 )
{
struct V_73 * V_74 = ( void * ) V_126 ;
struct V_30 * V_32 ;
int V_21 = 0 ;
struct V_127 V_128 ;
void * V_129 = & V_128 ;
void * V_22 = V_74 -> V_124 ;
void * V_23 = V_22 + sizeof( V_74 -> V_124 ) ;
V_32 = F_15 ( V_2 , V_74 -> V_31 ) ;
if ( F_30 ( V_32 ) )
return F_31 ( V_32 ) ;
V_21 = F_10 ( & V_32 -> V_39 , & V_22 , V_23 , & V_129 , sizeof( V_128 ) ) ;
if ( V_21 < 0 )
return V_21 ;
if ( V_21 != sizeof( V_128 ) )
return - V_29 ;
if ( V_74 -> V_87 + 1 != F_14 ( V_128 . V_130 ) )
V_21 = - V_29 ;
else
V_21 = 0 ;
F_3 ( L_22 ,
V_74 -> V_87 , F_14 ( V_128 . V_130 ) , V_21 ) ;
return V_21 ;
}
static void F_60 ( struct V_1 * V_2 ,
struct V_120 * V_126 )
{
struct V_73 * V_74 = ( void * ) V_126 ;
F_24 ( V_74 -> V_70 ) ;
F_25 ( V_74 ) ;
}
static void F_61 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_3 ( L_23 ) ;
V_4 -> V_113 = true ;
V_4 -> V_103 = 0 ;
}
static void F_62 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_33 * V_22 ;
F_3 ( L_24 , V_2 ) ;
F_23 ( & V_4 -> V_13 ) ;
while ( ( V_22 = F_63 ( & V_4 -> V_35 ) ) != NULL ) {
struct V_30 * V_32 =
F_16 ( V_22 , struct V_30 , V_36 ) ;
F_21 ( V_2 , V_32 ) ;
}
if ( V_4 -> V_109 . V_70 )
F_24 ( V_4 -> V_109 . V_70 ) ;
F_25 ( V_2 -> V_5 ) ;
V_2 -> V_5 = NULL ;
}
static void F_64 ( struct V_1 * V_2 ,
int V_117 )
{
struct V_30 * V_32 ;
V_32 = F_15 ( V_2 , V_117 ) ;
if ( ! F_30 ( V_32 ) )
memset ( & V_32 -> V_49 , 0 , sizeof( V_32 -> V_49 ) ) ;
}
int F_65 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_21 ;
F_3 ( L_25 , V_2 ) ;
V_21 = - V_27 ;
V_4 = F_17 ( sizeof( * V_4 ) , V_26 ) ;
if ( ! V_4 )
goto V_63;
V_21 = - V_25 ;
if ( ! V_2 -> V_104 ) {
F_66 ( L_26 ) ;
goto V_131;
}
V_21 = F_67 ( & V_4 -> V_13 , V_2 -> V_104 ) ;
if ( V_21 < 0 ) {
F_66 ( L_27 , V_21 ) ;
goto V_131;
}
V_4 -> V_113 = true ;
V_4 -> V_35 = V_132 ;
V_2 -> V_133 = V_134 ;
V_2 -> V_5 = V_4 ;
V_2 -> V_135 = & V_136 ;
return 0 ;
V_131:
F_25 ( V_4 ) ;
V_63:
return V_21 ;
}
