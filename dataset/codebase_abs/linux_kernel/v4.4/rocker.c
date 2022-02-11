static bool F_1 ( T_1 V_1 )
{
T_2 V_2 = V_3 ;
T_2 V_4 = 0xffe ;
T_2 V_5 = F_2 ( V_1 ) ;
return ( V_5 >= V_2 && V_5 <= V_4 ) ;
}
static T_1 F_3 ( const struct V_6 * V_6 ,
T_2 V_7 , bool * V_8 )
{
T_1 V_1 ;
if ( V_8 )
* V_8 = false ;
V_1 = F_4 ( V_7 ) ;
if ( ! V_1 ) {
V_1 = V_6 -> V_9 ;
if ( V_8 )
* V_8 = true ;
}
return V_1 ;
}
static T_2 F_5 ( const struct V_6 * V_6 ,
T_1 V_1 )
{
if ( F_1 ( V_1 ) )
return 0 ;
return F_2 ( V_1 ) ;
}
static bool F_6 ( const struct V_6 * V_6 )
{
return V_6 -> V_10 &&
F_7 ( V_6 -> V_10 ) ;
}
static bool F_8 ( const struct V_6 * V_6 )
{
return V_6 -> V_10 &&
F_9 ( V_6 -> V_10 ) ;
}
static void * F_10 ( struct V_6 * V_6 ,
struct V_11 * V_12 , int V_13 ,
T_3 V_14 )
{
struct V_15 * V_16 = NULL ;
T_4 V_17 = ( V_13 & V_18 ) ?
V_19 : V_20 ;
if ( ! V_12 ) {
V_16 = F_11 ( V_14 + sizeof( * V_16 ) , V_17 ) ;
} else if ( F_12 ( V_12 ) ) {
V_16 = F_11 ( V_14 + sizeof( * V_16 ) , V_17 ) ;
if ( ! V_16 )
return NULL ;
F_13 ( V_12 , V_16 , V_21 , V_16 ) ;
} else {
V_16 = F_14 ( V_12 ) ;
}
return V_16 ? V_16 + 1 : NULL ;
}
static void * F_15 ( struct V_6 * V_6 ,
struct V_11 * V_12 , int V_13 ,
T_3 V_14 )
{
return F_10 ( V_6 , V_12 , V_13 , V_14 ) ;
}
static void * F_16 ( struct V_6 * V_6 ,
struct V_11 * V_12 , int V_13 ,
T_3 V_22 , T_3 V_14 )
{
return F_10 ( V_6 , V_12 , V_13 , V_22 * V_14 ) ;
}
static void F_17 ( struct V_11 * V_12 , const void * V_23 )
{
struct V_15 * V_16 ;
if ( F_12 ( V_12 ) )
return;
V_16 = (struct V_15 * ) V_23 - 1 ;
V_21 ( V_16 ) ;
}
static void F_18 ( struct V_24 * V_25 )
{
V_25 -> V_26 = false ;
V_25 -> V_27 = false ;
}
static void F_19 ( struct V_24 * V_25 )
{
F_20 ( & V_25 -> V_25 ) ;
F_18 ( V_25 ) ;
}
static struct V_24 * F_21 ( struct V_6 * V_6 ,
struct V_11 * V_12 ,
int V_13 )
{
struct V_24 * V_25 ;
V_25 = F_15 ( V_6 , V_12 , V_13 , sizeof( * V_25 ) ) ;
if ( ! V_25 )
return NULL ;
F_19 ( V_25 ) ;
return V_25 ;
}
static void F_22 ( struct V_11 * V_12 ,
struct V_24 * V_25 )
{
F_17 ( V_12 , V_25 ) ;
}
static bool F_23 ( struct V_24 * V_25 ,
unsigned long V_28 )
{
F_24 ( V_25 -> V_25 , V_25 -> V_26 , V_29 / 10 ) ;
if ( ! V_25 -> V_26 )
return false ;
return true ;
}
static void F_25 ( struct V_24 * V_25 )
{
V_25 -> V_26 = true ;
F_26 ( & V_25 -> V_25 ) ;
}
static T_5 F_27 ( const struct V_30 * V_30 , unsigned int V_31 )
{
return V_30 -> V_32 [ V_31 ] . V_31 ;
}
static T_5 F_28 ( const struct V_6 * V_6 )
{
return F_27 ( V_6 -> V_30 ,
F_29 ( V_6 -> V_33 ) ) ;
}
static T_5 F_30 ( const struct V_6 * V_6 )
{
return F_27 ( V_6 -> V_30 ,
F_31 ( V_6 -> V_33 ) ) ;
}
static int F_32 ( const struct V_30 * V_30 )
{
const struct V_34 * V_35 = V_30 -> V_35 ;
T_6 V_36 ;
T_6 V_37 ;
V_37 = F_33 () ;
V_37 >>= 1 ;
F_34 ( V_30 , V_38 , V_37 ) ;
V_36 = F_35 ( V_30 , V_38 ) ;
if ( V_36 != V_37 * 2 ) {
F_36 ( & V_35 -> V_39 , L_1 ,
V_36 , V_37 * 2 ) ;
return - V_40 ;
}
V_37 = F_33 () ;
V_37 <<= 31 ;
V_37 |= F_33 () ;
F_37 ( V_30 , V_41 , V_37 ) ;
V_36 = F_38 ( V_30 , V_41 ) ;
if ( V_36 != V_37 * 2 ) {
F_36 ( & V_35 -> V_39 , L_2 ,
V_36 , V_37 * 2 ) ;
return - V_40 ;
}
return 0 ;
}
static int F_39 ( const struct V_30 * V_30 ,
struct V_24 * V_25 , T_5 V_42 ,
T_7 V_43 , const unsigned char * V_44 ,
const unsigned char * V_45 , T_3 V_14 )
{
const struct V_34 * V_35 = V_30 -> V_35 ;
int V_46 ;
F_18 ( V_25 ) ;
F_34 ( V_30 , V_47 , V_42 ) ;
if ( ! F_23 ( V_25 , V_29 / 10 ) ) {
F_36 ( & V_35 -> V_39 , L_3 ) ;
return - V_40 ;
}
for ( V_46 = 0 ; V_46 < V_14 ; V_46 ++ ) {
if ( V_44 [ V_46 ] != V_45 [ V_46 ] ) {
F_36 ( & V_35 -> V_39 , L_4 ,
V_44 [ V_46 ] , V_46 , V_45 [ V_46 ] ) ;
return - V_40 ;
}
}
return 0 ;
}
static int F_40 ( const struct V_30 * V_30 ,
struct V_24 * V_25 , int V_48 )
{
struct V_34 * V_35 = V_30 -> V_35 ;
unsigned char * V_49 ;
unsigned char * V_44 ;
unsigned char * V_45 ;
T_7 V_43 ;
int V_46 ;
int V_50 ;
V_49 = F_11 ( V_51 * 2 + V_48 ,
V_20 | V_52 ) ;
if ( ! V_49 )
return - V_53 ;
V_44 = V_49 + V_48 ;
V_45 = V_44 + V_51 ;
V_43 = F_41 ( V_35 , V_44 , V_51 ,
V_54 ) ;
if ( F_42 ( V_35 , V_43 ) ) {
V_50 = - V_40 ;
goto V_55;
}
F_37 ( V_30 , V_56 , V_43 ) ;
F_34 ( V_30 , V_57 , V_51 ) ;
memset ( V_45 , V_58 , V_51 ) ;
V_50 = F_39 ( V_30 , V_25 , V_59 ,
V_43 , V_44 , V_45 ,
V_51 ) ;
if ( V_50 )
goto V_60;
memset ( V_45 , 0 , V_51 ) ;
V_50 = F_39 ( V_30 , V_25 , V_61 ,
V_43 , V_44 , V_45 ,
V_51 ) ;
if ( V_50 )
goto V_60;
F_43 ( V_44 , V_51 ) ;
for ( V_46 = 0 ; V_46 < V_51 ; V_46 ++ )
V_45 [ V_46 ] = ~ V_44 [ V_46 ] ;
V_50 = F_39 ( V_30 , V_25 , V_62 ,
V_43 , V_44 , V_45 ,
V_51 ) ;
if ( V_50 )
goto V_60;
V_60:
F_44 ( V_35 , V_43 , V_51 ,
V_54 ) ;
V_55:
V_21 ( V_49 ) ;
return V_50 ;
}
static int F_45 ( const struct V_30 * V_30 ,
struct V_24 * V_25 )
{
int V_46 ;
int V_50 ;
for ( V_46 = 0 ; V_46 < 8 ; V_46 ++ ) {
V_50 = F_40 ( V_30 , V_25 , V_46 ) ;
if ( V_50 )
return V_50 ;
}
return 0 ;
}
static T_8 F_46 ( int V_63 , void * V_64 )
{
struct V_24 * V_25 = V_64 ;
F_25 ( V_25 ) ;
return V_65 ;
}
static int F_47 ( const struct V_30 * V_30 )
{
const struct V_34 * V_35 = V_30 -> V_35 ;
struct V_24 V_25 ;
int V_50 ;
V_50 = F_32 ( V_30 ) ;
if ( V_50 ) {
F_36 ( & V_35 -> V_39 , L_5 ) ;
return V_50 ;
}
V_50 = F_48 ( F_27 ( V_30 , V_66 ) ,
F_46 , 0 ,
V_67 , & V_25 ) ;
if ( V_50 ) {
F_36 ( & V_35 -> V_39 , L_6 ) ;
return V_50 ;
}
F_19 ( & V_25 ) ;
F_34 ( V_30 , V_68 , V_66 ) ;
if ( ! F_23 ( & V_25 , V_29 / 10 ) ) {
F_36 ( & V_35 -> V_39 , L_3 ) ;
V_50 = - V_40 ;
goto V_69;
}
V_50 = F_45 ( V_30 , & V_25 ) ;
if ( V_50 )
F_36 ( & V_35 -> V_39 , L_7 ) ;
V_69:
V_69 ( F_27 ( V_30 , V_66 ) , & V_25 ) ;
return V_50 ;
}
static struct V_70 * F_49 ( const struct V_70 * V_71 ,
int * V_72 )
{
int V_73 = F_50 ( V_71 -> V_74 ) ;
* V_72 -= V_73 ;
return (struct V_70 * ) ( ( char * ) V_71 + V_73 ) ;
}
static int F_51 ( const struct V_70 * V_71 , int V_72 )
{
return V_72 >= ( int ) V_75 &&
V_71 -> V_74 >= V_75 &&
V_71 -> V_74 <= V_72 ;
}
static int F_52 ( int V_76 )
{
return V_75 + V_76 ;
}
static int F_53 ( int V_76 )
{
return F_50 ( F_52 ( V_76 ) ) ;
}
static int F_54 ( int V_76 )
{
return F_53 ( V_76 ) - F_52 ( V_76 ) ;
}
static int F_55 ( const struct V_70 * V_71 )
{
return V_71 -> type ;
}
static void * F_56 ( const struct V_70 * V_71 )
{
return ( char * ) V_71 + V_75 ;
}
static int F_57 ( const struct V_70 * V_71 )
{
return V_71 -> V_74 - V_75 ;
}
static T_9 F_58 ( const struct V_70 * V_71 )
{
return * ( T_9 * ) F_56 ( V_71 ) ;
}
static T_2 F_59 ( const struct V_70 * V_71 )
{
return * ( T_2 * ) F_56 ( V_71 ) ;
}
static T_1 F_60 ( const struct V_70 * V_71 )
{
return * ( T_1 * ) F_56 ( V_71 ) ;
}
static T_5 F_61 ( const struct V_70 * V_71 )
{
return * ( T_5 * ) F_56 ( V_71 ) ;
}
static T_6 F_62 ( const struct V_70 * V_71 )
{
return * ( T_6 * ) F_56 ( V_71 ) ;
}
static void F_63 ( const struct V_70 * * V_77 , int V_78 ,
const char * V_44 , int V_79 )
{
const struct V_70 * V_71 ;
const struct V_70 * V_80 = ( const struct V_70 * ) V_44 ;
int V_81 ;
memset ( V_77 , 0 , sizeof( struct V_70 * ) * ( V_78 + 1 ) ) ;
F_64 (tlv, head, buf_len, rem) {
T_5 type = F_55 ( V_71 ) ;
if ( type > 0 && type <= V_78 )
V_77 [ type ] = V_71 ;
}
}
static void F_65 ( const struct V_70 * * V_77 , int V_78 ,
const struct V_70 * V_71 )
{
F_63 ( V_77 , V_78 , F_56 ( V_71 ) ,
F_57 ( V_71 ) ) ;
}
static void F_66 ( const struct V_70 * * V_77 , int V_78 ,
const struct V_82 * V_83 )
{
F_63 ( V_77 , V_78 , V_83 -> V_84 ,
V_83 -> V_85 -> V_86 ) ;
}
static struct V_70 * F_67 ( struct V_82 * V_83 )
{
return (struct V_70 * ) ( ( char * ) V_83 -> V_84 +
V_83 -> V_86 ) ;
}
static int F_68 ( struct V_82 * V_83 ,
int V_87 , int V_88 , const void * V_84 )
{
int V_89 = V_83 -> V_90 - V_83 -> V_86 ;
int V_91 = F_53 ( V_88 ) ;
struct V_70 * V_71 ;
if ( F_69 ( V_89 < V_91 ) )
return - V_92 ;
V_71 = F_67 ( V_83 ) ;
V_83 -> V_86 += V_91 ;
V_71 -> type = V_87 ;
V_71 -> V_74 = F_52 ( V_88 ) ;
memcpy ( F_56 ( V_71 ) , V_84 , V_88 ) ;
memset ( ( char * ) V_71 + V_71 -> V_74 , 0 , F_54 ( V_88 ) ) ;
return 0 ;
}
static int F_70 ( struct V_82 * V_83 ,
int V_87 , T_9 V_93 )
{
return F_68 ( V_83 , V_87 , sizeof( T_9 ) , & V_93 ) ;
}
static int F_71 ( struct V_82 * V_83 ,
int V_87 , T_2 V_93 )
{
return F_68 ( V_83 , V_87 , sizeof( T_2 ) , & V_93 ) ;
}
static int F_72 ( struct V_82 * V_83 ,
int V_87 , T_1 V_93 )
{
return F_68 ( V_83 , V_87 , sizeof( T_1 ) , & V_93 ) ;
}
static int F_73 ( struct V_82 * V_83 ,
int V_87 , T_5 V_93 )
{
return F_68 ( V_83 , V_87 , sizeof( T_5 ) , & V_93 ) ;
}
static int F_74 ( struct V_82 * V_83 ,
int V_87 , T_10 V_93 )
{
return F_68 ( V_83 , V_87 , sizeof( T_10 ) , & V_93 ) ;
}
static int F_75 ( struct V_82 * V_83 ,
int V_87 , T_6 V_93 )
{
return F_68 ( V_83 , V_87 , sizeof( T_6 ) , & V_93 ) ;
}
static struct V_70 *
F_76 ( struct V_82 * V_83 , int V_87 )
{
struct V_70 * V_2 = F_67 ( V_83 ) ;
if ( F_68 ( V_83 , V_87 , 0 , NULL ) < 0 )
return NULL ;
return V_2 ;
}
static void F_77 ( struct V_82 * V_83 ,
struct V_70 * V_2 )
{
V_2 -> V_74 = ( char * ) F_67 ( V_83 ) - ( char * ) V_2 ;
}
static void F_78 ( struct V_82 * V_83 ,
const struct V_70 * V_2 )
{
V_83 -> V_86 = ( const char * ) V_2 - V_83 -> V_84 ;
}
static T_5 F_79 ( T_5 V_94 , T_3 V_95 )
{
return ++ V_94 == V_95 ? 0 : V_94 ;
}
static int F_80 ( const struct V_82 * V_83 )
{
int V_50 = V_83 -> V_85 -> V_96 & ~ V_97 ;
switch ( V_50 ) {
case V_98 :
return 0 ;
case - V_99 :
return - V_100 ;
case - V_101 :
return - V_102 ;
case - V_103 :
return - V_53 ;
case - V_104 :
return - V_105 ;
case - V_106 :
return - V_107 ;
case - V_108 :
return - V_92 ;
case - V_109 :
return - V_110 ;
case - V_111 :
return - V_112 ;
}
return - V_107 ;
}
static void F_81 ( const struct V_82 * V_83 )
{
V_83 -> V_85 -> V_96 &= ~ V_97 ;
}
static bool F_82 ( const struct V_82 * V_83 )
{
T_5 V_96 = V_83 -> V_85 -> V_96 ;
return V_96 & V_97 ? true : false ;
}
static void * F_83 ( const struct V_82 * V_83 )
{
return ( void * ) ( V_113 ) V_83 -> V_85 -> V_114 ;
}
static void F_84 ( const struct V_82 * V_83 ,
void * V_115 )
{
V_83 -> V_85 -> V_114 = ( V_113 ) V_115 ;
}
static struct V_82 *
F_85 ( const struct V_116 * V_117 )
{
static struct V_82 * V_83 ;
T_5 V_80 = F_79 ( V_117 -> V_80 , V_117 -> V_14 ) ;
V_83 = & V_117 -> V_83 [ V_117 -> V_80 ] ;
if ( V_80 == V_117 -> V_118 )
return NULL ;
V_83 -> V_86 = 0 ;
return V_83 ;
}
static void F_86 ( const struct V_82 * V_83 )
{
V_83 -> V_85 -> V_119 = V_83 -> V_90 ;
V_83 -> V_85 -> V_86 = V_83 -> V_86 ;
}
static void F_87 ( const struct V_30 * V_30 ,
struct V_116 * V_117 ,
const struct V_82 * V_83 )
{
T_5 V_80 = F_79 ( V_117 -> V_80 , V_117 -> V_14 ) ;
F_88 ( V_80 == V_117 -> V_118 ) ;
F_86 ( V_83 ) ;
V_117 -> V_80 = V_80 ;
F_34 ( V_30 , F_89 ( V_117 -> type ) , V_80 ) ;
}
static struct V_82 *
F_90 ( struct V_116 * V_117 )
{
static struct V_82 * V_83 ;
if ( V_117 -> V_118 == V_117 -> V_80 )
return NULL ;
V_83 = & V_117 -> V_83 [ V_117 -> V_118 ] ;
if ( ! F_82 ( V_83 ) )
return NULL ;
V_117 -> V_118 = F_79 ( V_117 -> V_118 , V_117 -> V_14 ) ;
V_83 -> V_86 = V_83 -> V_85 -> V_86 ;
return V_83 ;
}
static void F_91 ( const struct V_30 * V_30 ,
const struct V_116 * V_117 ,
T_5 V_120 )
{
if ( V_120 )
F_34 ( V_30 , F_92 ( V_117 -> type ) , V_120 ) ;
}
static unsigned long F_93 ( T_3 V_14 )
{
return F_94 ( V_121 ,
F_95 ( F_96 ( V_14 ) , V_122 ) ) ;
}
static int F_97 ( const struct V_30 * V_30 ,
unsigned int type ,
T_3 V_14 ,
struct V_116 * V_117 )
{
int V_46 ;
F_88 ( V_14 != F_93 ( V_14 ) ) ;
V_117 -> V_14 = V_14 ;
V_117 -> type = type ;
V_117 -> V_80 = 0 ;
V_117 -> V_118 = 0 ;
V_117 -> V_83 = F_98 ( V_117 -> V_14 , sizeof( * V_117 -> V_83 ) ,
V_20 ) ;
if ( ! V_117 -> V_83 )
return - V_53 ;
V_117 -> V_85 = F_99 ( V_30 -> V_35 ,
V_117 -> V_14 * sizeof( * V_117 -> V_85 ) ,
& V_117 -> V_123 ) ;
if ( ! V_117 -> V_85 ) {
V_21 ( V_117 -> V_83 ) ;
return - V_53 ;
}
for ( V_46 = 0 ; V_46 < V_117 -> V_14 ; V_46 ++ )
V_117 -> V_83 [ V_46 ] . V_85 = & V_117 -> V_85 [ V_46 ] ;
F_34 ( V_30 , F_100 ( V_117 -> type ) ,
V_124 ) ;
F_37 ( V_30 , F_101 ( V_117 -> type ) , V_117 -> V_123 ) ;
F_34 ( V_30 , F_102 ( V_117 -> type ) , V_117 -> V_14 ) ;
return 0 ;
}
static void F_103 ( const struct V_30 * V_30 ,
const struct V_116 * V_117 )
{
F_37 ( V_30 , F_101 ( V_117 -> type ) , 0 ) ;
F_104 ( V_30 -> V_35 ,
V_117 -> V_14 * sizeof( struct V_125 ) ,
V_117 -> V_85 , V_117 -> V_123 ) ;
V_21 ( V_117 -> V_83 ) ;
}
static void F_105 ( const struct V_30 * V_30 ,
struct V_116 * V_117 )
{
int V_46 ;
F_88 ( V_117 -> V_80 || V_117 -> V_118 ) ;
for ( V_46 = 0 ; V_46 < V_117 -> V_14 - 1 ; V_46 ++ )
F_87 ( V_30 , V_117 , & V_117 -> V_83 [ V_46 ] ) ;
F_86 ( & V_117 -> V_83 [ V_46 ] ) ;
}
static int F_106 ( const struct V_30 * V_30 ,
const struct V_116 * V_117 ,
int V_126 , T_3 V_119 )
{
struct V_34 * V_35 = V_30 -> V_35 ;
int V_46 ;
int V_50 ;
for ( V_46 = 0 ; V_46 < V_117 -> V_14 ; V_46 ++ ) {
struct V_82 * V_83 = & V_117 -> V_83 [ V_46 ] ;
struct V_125 * V_85 = & V_117 -> V_85 [ V_46 ] ;
T_7 V_43 ;
char * V_44 ;
V_44 = F_11 ( V_119 , V_20 | V_52 ) ;
if ( ! V_44 ) {
V_50 = - V_53 ;
goto V_127;
}
V_43 = F_41 ( V_35 , V_44 , V_119 , V_126 ) ;
if ( F_42 ( V_35 , V_43 ) ) {
V_21 ( V_44 ) ;
V_50 = - V_40 ;
goto V_127;
}
V_83 -> V_84 = V_44 ;
V_83 -> V_90 = V_119 ;
F_107 ( V_83 , V_123 , V_43 ) ;
V_85 -> V_128 = V_43 ;
V_85 -> V_119 = V_119 ;
}
return 0 ;
V_127:
for ( V_46 -- ; V_46 >= 0 ; V_46 -- ) {
const struct V_82 * V_83 = & V_117 -> V_83 [ V_46 ] ;
F_44 ( V_35 , F_108 ( V_83 , V_123 ) ,
V_83 -> V_90 , V_126 ) ;
V_21 ( V_83 -> V_84 ) ;
}
return V_50 ;
}
static void F_109 ( const struct V_30 * V_30 ,
const struct V_116 * V_117 ,
int V_126 )
{
struct V_34 * V_35 = V_30 -> V_35 ;
int V_46 ;
for ( V_46 = 0 ; V_46 < V_117 -> V_14 ; V_46 ++ ) {
const struct V_82 * V_83 = & V_117 -> V_83 [ V_46 ] ;
struct V_125 * V_85 = & V_117 -> V_85 [ V_46 ] ;
V_85 -> V_128 = 0 ;
V_85 -> V_119 = 0 ;
F_44 ( V_35 , F_108 ( V_83 , V_123 ) ,
V_83 -> V_90 , V_126 ) ;
V_21 ( V_83 -> V_84 ) ;
}
}
static int F_110 ( struct V_30 * V_30 )
{
const struct V_34 * V_35 = V_30 -> V_35 ;
int V_50 ;
V_50 = F_97 ( V_30 , V_129 ,
V_130 ,
& V_30 -> V_131 ) ;
if ( V_50 ) {
F_36 ( & V_35 -> V_39 , L_8 ) ;
return V_50 ;
}
F_111 ( & V_30 -> V_132 ) ;
V_50 = F_106 ( V_30 , & V_30 -> V_131 ,
V_54 , V_133 ) ;
if ( V_50 ) {
F_36 ( & V_35 -> V_39 , L_9 ) ;
goto V_134;
}
V_50 = F_97 ( V_30 , V_135 ,
V_136 ,
& V_30 -> V_137 ) ;
if ( V_50 ) {
F_36 ( & V_35 -> V_39 , L_10 ) ;
goto V_138;
}
V_50 = F_106 ( V_30 , & V_30 -> V_137 ,
V_139 , V_133 ) ;
if ( V_50 ) {
F_36 ( & V_35 -> V_39 , L_11 ) ;
goto V_140;
}
F_105 ( V_30 , & V_30 -> V_137 ) ;
return 0 ;
V_140:
F_103 ( V_30 , & V_30 -> V_137 ) ;
V_138:
F_109 ( V_30 , & V_30 -> V_131 ,
V_54 ) ;
V_134:
F_103 ( V_30 , & V_30 -> V_131 ) ;
return V_50 ;
}
static void F_112 ( struct V_30 * V_30 )
{
F_109 ( V_30 , & V_30 -> V_137 ,
V_54 ) ;
F_103 ( V_30 , & V_30 -> V_137 ) ;
F_109 ( V_30 , & V_30 -> V_131 ,
V_54 ) ;
F_103 ( V_30 , & V_30 -> V_131 ) ;
}
static int F_113 ( const struct V_6 * V_6 ,
struct V_82 * V_83 ,
struct V_141 * V_142 , T_3 V_79 )
{
const struct V_30 * V_30 = V_6 -> V_30 ;
struct V_34 * V_35 = V_30 -> V_35 ;
T_7 V_43 ;
V_43 = F_41 ( V_35 , V_142 -> V_84 , V_79 ,
V_139 ) ;
if ( F_42 ( V_35 , V_43 ) )
return - V_40 ;
if ( F_75 ( V_83 , V_143 , V_43 ) )
goto V_144;
if ( F_71 ( V_83 , V_145 , V_79 ) )
goto V_144;
return 0 ;
V_144:
F_44 ( V_35 , V_43 , V_79 , V_139 ) ;
V_83 -> V_86 = 0 ;
return - V_92 ;
}
static T_3 F_114 ( const struct V_6 * V_6 )
{
return V_6 -> V_39 -> V_146 + V_147 + V_148 + V_149 ;
}
static int F_115 ( const struct V_6 * V_6 ,
struct V_82 * V_83 )
{
struct V_150 * V_39 = V_6 -> V_39 ;
struct V_141 * V_142 ;
T_3 V_79 = F_114 ( V_6 ) ;
int V_50 ;
F_84 ( V_83 , NULL ) ;
V_83 -> V_86 = 0 ;
V_142 = F_116 ( V_39 , V_79 ) ;
if ( ! V_142 )
return - V_53 ;
V_50 = F_113 ( V_6 , V_83 , V_142 , V_79 ) ;
if ( V_50 ) {
F_117 ( V_142 ) ;
return V_50 ;
}
F_84 ( V_83 , V_142 ) ;
return 0 ;
}
static void F_118 ( const struct V_30 * V_30 ,
const struct V_70 * * V_151 )
{
struct V_34 * V_35 = V_30 -> V_35 ;
T_7 V_43 ;
T_3 V_74 ;
if ( ! V_151 [ V_143 ] ||
! V_151 [ V_145 ] )
return;
V_43 = F_62 ( V_151 [ V_143 ] ) ;
V_74 = F_59 ( V_151 [ V_145 ] ) ;
F_44 ( V_35 , V_43 , V_74 , V_139 ) ;
}
static void F_119 ( const struct V_30 * V_30 ,
const struct V_82 * V_83 )
{
const struct V_70 * V_151 [ V_152 + 1 ] ;
struct V_141 * V_142 = F_83 ( V_83 ) ;
if ( ! V_142 )
return;
F_66 ( V_151 , V_152 , V_83 ) ;
F_118 ( V_30 , V_151 ) ;
F_117 ( V_142 ) ;
}
static int F_120 ( const struct V_6 * V_6 )
{
const struct V_116 * V_153 = & V_6 -> V_153 ;
const struct V_30 * V_30 = V_6 -> V_30 ;
int V_46 ;
int V_50 ;
for ( V_46 = 0 ; V_46 < V_153 -> V_14 ; V_46 ++ ) {
V_50 = F_115 ( V_6 ,
& V_153 -> V_83 [ V_46 ] ) ;
if ( V_50 )
goto V_127;
}
return 0 ;
V_127:
for ( V_46 -- ; V_46 >= 0 ; V_46 -- )
F_119 ( V_30 , & V_153 -> V_83 [ V_46 ] ) ;
return V_50 ;
}
static void F_121 ( const struct V_6 * V_6 )
{
const struct V_116 * V_153 = & V_6 -> V_153 ;
const struct V_30 * V_30 = V_6 -> V_30 ;
int V_46 ;
for ( V_46 = 0 ; V_46 < V_153 -> V_14 ; V_46 ++ )
F_119 ( V_30 , & V_153 -> V_83 [ V_46 ] ) ;
}
static int F_122 ( struct V_6 * V_6 )
{
struct V_30 * V_30 = V_6 -> V_30 ;
int V_50 ;
V_50 = F_97 ( V_30 ,
F_123 ( V_6 -> V_33 ) ,
V_154 ,
& V_6 -> V_155 ) ;
if ( V_50 ) {
F_124 ( V_6 -> V_39 , L_12 ) ;
return V_50 ;
}
V_50 = F_106 ( V_30 , & V_6 -> V_155 ,
V_156 ,
V_157 ) ;
if ( V_50 ) {
F_124 ( V_6 -> V_39 , L_13 ) ;
goto V_158;
}
V_50 = F_97 ( V_30 ,
F_125 ( V_6 -> V_33 ) ,
V_159 ,
& V_6 -> V_153 ) ;
if ( V_50 ) {
F_124 ( V_6 -> V_39 , L_14 ) ;
goto V_160;
}
V_50 = F_106 ( V_30 , & V_6 -> V_153 ,
V_54 ,
V_161 ) ;
if ( V_50 ) {
F_124 ( V_6 -> V_39 , L_15 ) ;
goto V_162;
}
V_50 = F_120 ( V_6 ) ;
if ( V_50 ) {
F_124 ( V_6 -> V_39 , L_16 ) ;
goto V_163;
}
F_105 ( V_30 , & V_6 -> V_153 ) ;
return 0 ;
V_163:
F_109 ( V_30 , & V_6 -> V_153 ,
V_54 ) ;
V_162:
F_103 ( V_30 , & V_6 -> V_153 ) ;
V_160:
F_109 ( V_30 , & V_6 -> V_155 ,
V_156 ) ;
V_158:
F_103 ( V_30 , & V_6 -> V_155 ) ;
return V_50 ;
}
static void F_126 ( struct V_6 * V_6 )
{
struct V_30 * V_30 = V_6 -> V_30 ;
F_121 ( V_6 ) ;
F_109 ( V_30 , & V_6 -> V_153 ,
V_54 ) ;
F_103 ( V_30 , & V_6 -> V_153 ) ;
F_109 ( V_30 , & V_6 -> V_155 ,
V_156 ) ;
F_103 ( V_30 , & V_6 -> V_155 ) ;
}
static void F_127 ( const struct V_6 * V_6 ,
bool V_164 )
{
T_6 V_165 = F_38 ( V_6 -> V_30 , V_166 ) ;
if ( V_164 )
V_165 |= 1ULL << V_6 -> V_167 ;
else
V_165 &= ~ ( 1ULL << V_6 -> V_167 ) ;
F_37 ( V_6 -> V_30 , V_166 , V_165 ) ;
}
static T_8 F_128 ( int V_63 , void * V_64 )
{
struct V_30 * V_30 = V_64 ;
const struct V_82 * V_83 ;
struct V_24 * V_25 ;
T_5 V_120 = 0 ;
F_129 ( & V_30 -> V_132 ) ;
while ( ( V_83 = F_90 ( & V_30 -> V_131 ) ) ) {
V_25 = F_83 ( V_83 ) ;
if ( V_25 -> V_27 ) {
F_81 ( V_83 ) ;
F_22 ( NULL , V_25 ) ;
} else {
F_25 ( V_25 ) ;
}
V_120 ++ ;
}
F_130 ( & V_30 -> V_132 ) ;
F_91 ( V_30 , & V_30 -> V_131 , V_120 ) ;
return V_65 ;
}
static void F_131 ( const struct V_6 * V_6 )
{
F_132 ( V_6 -> V_39 ) ;
F_133 ( V_6 -> V_39 , L_17 ) ;
}
static void F_134 ( const struct V_6 * V_6 )
{
F_135 ( V_6 -> V_39 ) ;
F_133 ( V_6 -> V_39 , L_18 ) ;
}
static int F_136 ( const struct V_30 * V_30 ,
const struct V_70 * V_117 )
{
const struct V_70 * V_151 [ V_168 + 1 ] ;
unsigned int V_33 ;
bool V_169 ;
struct V_6 * V_6 ;
F_65 ( V_151 , V_168 , V_117 ) ;
if ( ! V_151 [ V_170 ] ||
! V_151 [ V_171 ] )
return - V_40 ;
V_33 =
F_61 ( V_151 [ V_170 ] ) - 1 ;
V_169 = F_58 ( V_151 [ V_171 ] ) ;
if ( V_33 >= V_30 -> V_172 )
return - V_107 ;
V_6 = V_30 -> V_173 [ V_33 ] ;
if ( F_137 ( V_6 -> V_39 ) != V_169 ) {
if ( V_169 )
F_131 ( V_6 ) ;
else
F_134 ( V_6 ) ;
}
return 0 ;
}
static int F_138 ( const struct V_30 * V_30 ,
const struct V_70 * V_117 )
{
const struct V_70 * V_151 [ V_174 + 1 ] ;
unsigned int V_33 ;
struct V_6 * V_6 ;
const unsigned char * V_175 ;
int V_13 = V_18 | V_176 ;
T_1 V_1 ;
F_65 ( V_151 , V_174 , V_117 ) ;
if ( ! V_151 [ V_177 ] ||
! V_151 [ V_178 ] ||
! V_151 [ V_179 ] )
return - V_40 ;
V_33 =
F_61 ( V_151 [ V_177 ] ) - 1 ;
V_175 = F_56 ( V_151 [ V_178 ] ) ;
V_1 = F_60 ( V_151 [ V_179 ] ) ;
if ( V_33 >= V_30 -> V_172 )
return - V_107 ;
V_6 = V_30 -> V_173 [ V_33 ] ;
if ( V_6 -> V_180 != V_181 &&
V_6 -> V_180 != V_182 )
return 0 ;
return F_139 ( V_6 , NULL , V_175 , V_1 , V_13 ) ;
}
static int F_140 ( const struct V_30 * V_30 ,
const struct V_82 * V_83 )
{
const struct V_70 * V_151 [ V_183 + 1 ] ;
const struct V_70 * V_117 ;
T_2 type ;
F_66 ( V_151 , V_183 , V_83 ) ;
if ( ! V_151 [ V_184 ] ||
! V_151 [ V_185 ] )
return - V_40 ;
type = F_59 ( V_151 [ V_184 ] ) ;
V_117 = V_151 [ V_185 ] ;
switch ( type ) {
case V_186 :
return F_136 ( V_30 , V_117 ) ;
case V_187 :
return F_138 ( V_30 , V_117 ) ;
}
return - V_110 ;
}
static T_8 F_141 ( int V_63 , void * V_64 )
{
struct V_30 * V_30 = V_64 ;
const struct V_34 * V_35 = V_30 -> V_35 ;
const struct V_82 * V_83 ;
T_5 V_120 = 0 ;
int V_50 ;
while ( ( V_83 = F_90 ( & V_30 -> V_137 ) ) ) {
V_50 = F_80 ( V_83 ) ;
if ( V_50 ) {
F_36 ( & V_35 -> V_39 , L_19 ,
V_50 ) ;
} else {
V_50 = F_140 ( V_30 , V_83 ) ;
if ( V_50 )
F_36 ( & V_35 -> V_39 , L_20 ,
V_50 ) ;
}
F_81 ( V_83 ) ;
F_87 ( V_30 , & V_30 -> V_137 , V_83 ) ;
V_120 ++ ;
}
F_91 ( V_30 , & V_30 -> V_137 , V_120 ) ;
return V_65 ;
}
static T_8 F_142 ( int V_63 , void * V_64 )
{
struct V_6 * V_6 = V_64 ;
F_143 ( & V_6 -> V_188 ) ;
return V_65 ;
}
static T_8 F_144 ( int V_63 , void * V_64 )
{
struct V_6 * V_6 = V_64 ;
F_143 ( & V_6 -> V_189 ) ;
return V_65 ;
}
static int F_145 ( struct V_6 * V_6 ,
struct V_11 * V_12 , int V_13 ,
T_11 V_190 , void * V_191 ,
T_12 V_192 , void * V_193 )
{
struct V_30 * V_30 = V_6 -> V_30 ;
struct V_82 * V_83 ;
struct V_24 * V_25 ;
bool V_27 = ! ! ( V_13 & V_18 ) ;
unsigned long V_194 ;
int V_50 ;
V_25 = F_21 ( V_6 , V_12 , V_13 ) ;
if ( ! V_25 )
return - V_53 ;
V_25 -> V_27 = V_27 ;
F_146 ( & V_30 -> V_132 , V_194 ) ;
V_83 = F_85 ( & V_30 -> V_131 ) ;
if ( ! V_83 ) {
F_147 ( & V_30 -> V_132 , V_194 ) ;
V_50 = - V_195 ;
goto V_196;
}
V_50 = V_190 ( V_6 , V_83 , V_191 ) ;
if ( V_50 ) {
F_147 ( & V_30 -> V_132 , V_194 ) ;
goto V_196;
}
F_84 ( V_83 , V_25 ) ;
if ( ! F_12 ( V_12 ) )
F_87 ( V_30 , & V_30 -> V_131 , V_83 ) ;
F_147 ( & V_30 -> V_132 , V_194 ) ;
if ( V_27 )
return 0 ;
if ( ! F_12 ( V_12 ) )
if ( ! F_23 ( V_25 , V_29 / 10 ) )
return - V_40 ;
V_50 = F_80 ( V_83 ) ;
if ( V_50 )
return V_50 ;
if ( V_192 )
V_50 = V_192 ( V_6 , V_83 , V_193 ) ;
F_81 ( V_83 ) ;
V_196:
F_22 ( V_12 , V_25 ) ;
return V_50 ;
}
static int
F_148 ( const struct V_6 * V_6 ,
struct V_82 * V_83 ,
void * V_197 )
{
struct V_70 * V_198 ;
if ( F_71 ( V_83 , V_199 ,
V_200 ) )
return - V_92 ;
V_198 = F_76 ( V_83 , V_201 ) ;
if ( ! V_198 )
return - V_92 ;
if ( F_73 ( V_83 , V_202 ,
V_6 -> V_167 ) )
return - V_92 ;
F_77 ( V_83 , V_198 ) ;
return 0 ;
}
static int
F_149 ( const struct V_6 * V_6 ,
const struct V_82 * V_83 ,
void * V_197 )
{
struct V_203 * V_204 = V_197 ;
const struct V_70 * V_151 [ V_205 + 1 ] ;
const struct V_70 * V_206 [ V_207 + 1 ] ;
T_5 V_208 ;
T_9 V_209 ;
T_9 V_210 ;
F_66 ( V_151 , V_205 , V_83 ) ;
if ( ! V_151 [ V_201 ] )
return - V_40 ;
F_65 ( V_206 , V_207 ,
V_151 [ V_201 ] ) ;
if ( ! V_206 [ V_211 ] ||
! V_206 [ V_212 ] ||
! V_206 [ V_213 ] )
return - V_40 ;
V_208 = F_61 ( V_206 [ V_211 ] ) ;
V_209 = F_58 ( V_206 [ V_212 ] ) ;
V_210 = F_58 ( V_206 [ V_213 ] ) ;
V_204 -> V_214 = V_215 ;
V_204 -> V_216 = V_217 ;
V_204 -> V_218 = 0xff ;
V_204 -> V_219 = V_220 ;
F_150 ( V_204 , V_208 ) ;
V_204 -> V_209 = V_209 ? V_221 : V_222 ;
V_204 -> V_210 = V_210 ? V_223 : V_224 ;
return 0 ;
}
static int
F_151 ( const struct V_6 * V_6 ,
const struct V_82 * V_83 ,
void * V_197 )
{
unsigned char * V_225 = V_197 ;
const struct V_70 * V_151 [ V_205 + 1 ] ;
const struct V_70 * V_206 [ V_207 + 1 ] ;
const struct V_70 * V_226 ;
F_66 ( V_151 , V_205 , V_83 ) ;
if ( ! V_151 [ V_201 ] )
return - V_40 ;
F_65 ( V_206 , V_207 ,
V_151 [ V_201 ] ) ;
V_226 = V_206 [ V_227 ] ;
if ( ! V_226 )
return - V_40 ;
if ( F_57 ( V_226 ) != V_228 )
return - V_107 ;
F_152 ( V_225 , F_56 ( V_226 ) ) ;
return 0 ;
}
static int
F_153 ( const struct V_6 * V_6 ,
const struct V_82 * V_83 ,
void * V_197 )
{
const struct V_70 * V_206 [ V_207 + 1 ] ;
const struct V_70 * V_151 [ V_205 + 1 ] ;
struct V_229 * V_230 = V_197 ;
const struct V_70 * V_226 ;
T_3 V_46 , V_231 , V_74 ;
const char * V_232 ;
F_66 ( V_151 , V_205 , V_83 ) ;
if ( ! V_151 [ V_201 ] )
return - V_40 ;
F_65 ( V_206 , V_207 ,
V_151 [ V_201 ] ) ;
V_226 = V_206 [ V_233 ] ;
if ( ! V_226 )
return - V_40 ;
V_74 = F_154 ( T_3 , F_57 ( V_226 ) , V_230 -> V_74 ) ;
V_232 = F_56 ( V_226 ) ;
for ( V_46 = V_231 = 0 ; V_46 < V_74 ; ++ V_46 ) {
if ( isalnum ( V_232 [ V_46 ] ) ) {
V_230 -> V_44 [ V_231 ] = V_232 [ V_46 ] ;
V_231 ++ ;
}
}
if ( V_231 == 0 )
return - V_40 ;
V_230 -> V_44 [ V_231 ] = '\0' ;
return 0 ;
}
static int
F_155 ( const struct V_6 * V_6 ,
struct V_82 * V_83 ,
void * V_197 )
{
struct V_203 * V_204 = V_197 ;
struct V_70 * V_198 ;
if ( F_71 ( V_83 , V_199 ,
V_234 ) )
return - V_92 ;
V_198 = F_76 ( V_83 , V_201 ) ;
if ( ! V_198 )
return - V_92 ;
if ( F_73 ( V_83 , V_202 ,
V_6 -> V_167 ) )
return - V_92 ;
if ( F_73 ( V_83 , V_211 ,
F_156 ( V_204 ) ) )
return - V_92 ;
if ( F_70 ( V_83 , V_212 ,
V_204 -> V_209 ) )
return - V_92 ;
if ( F_70 ( V_83 , V_213 ,
V_204 -> V_210 ) )
return - V_92 ;
F_77 ( V_83 , V_198 ) ;
return 0 ;
}
static int
F_157 ( const struct V_6 * V_6 ,
struct V_82 * V_83 ,
void * V_197 )
{
const unsigned char * V_225 = V_197 ;
struct V_70 * V_198 ;
if ( F_71 ( V_83 , V_199 ,
V_234 ) )
return - V_92 ;
V_198 = F_76 ( V_83 , V_201 ) ;
if ( ! V_198 )
return - V_92 ;
if ( F_73 ( V_83 , V_202 ,
V_6 -> V_167 ) )
return - V_92 ;
if ( F_68 ( V_83 , V_227 ,
V_228 , V_225 ) )
return - V_92 ;
F_77 ( V_83 , V_198 ) ;
return 0 ;
}
static int
F_158 ( const struct V_6 * V_6 ,
struct V_82 * V_83 ,
void * V_197 )
{
int V_146 = * ( int * ) V_197 ;
struct V_70 * V_198 ;
if ( F_71 ( V_83 , V_199 ,
V_234 ) )
return - V_92 ;
V_198 = F_76 ( V_83 , V_201 ) ;
if ( ! V_198 )
return - V_92 ;
if ( F_73 ( V_83 , V_202 ,
V_6 -> V_167 ) )
return - V_92 ;
if ( F_71 ( V_83 , V_235 ,
V_146 ) )
return - V_92 ;
F_77 ( V_83 , V_198 ) ;
return 0 ;
}
static int
F_159 ( const struct V_6 * V_6 ,
struct V_82 * V_83 ,
void * V_197 )
{
struct V_70 * V_198 ;
if ( F_71 ( V_83 , V_199 ,
V_234 ) )
return - V_92 ;
V_198 = F_76 ( V_83 , V_201 ) ;
if ( ! V_198 )
return - V_92 ;
if ( F_73 ( V_83 , V_202 ,
V_6 -> V_167 ) )
return - V_92 ;
if ( F_70 ( V_83 , V_236 ,
! ! ( V_6 -> V_237 & V_238 ) ) )
return - V_92 ;
F_77 ( V_83 , V_198 ) ;
return 0 ;
}
static int F_160 ( struct V_6 * V_6 ,
struct V_203 * V_204 )
{
return F_145 ( V_6 , NULL , 0 ,
F_148 , NULL ,
F_149 ,
V_204 ) ;
}
static int F_161 ( struct V_6 * V_6 ,
unsigned char * V_225 )
{
return F_145 ( V_6 , NULL , 0 ,
F_148 , NULL ,
F_151 ,
V_225 ) ;
}
static int F_162 ( struct V_6 * V_6 ,
struct V_203 * V_204 )
{
return F_145 ( V_6 , NULL , 0 ,
F_155 ,
V_204 , NULL , NULL ) ;
}
static int F_163 ( struct V_6 * V_6 ,
unsigned char * V_225 )
{
return F_145 ( V_6 , NULL , 0 ,
F_157 ,
V_225 , NULL , NULL ) ;
}
static int F_164 ( struct V_6 * V_6 ,
int V_146 )
{
return F_145 ( V_6 , NULL , 0 ,
F_158 ,
& V_146 , NULL , NULL ) ;
}
static int F_165 ( struct V_6 * V_6 ,
struct V_11 * V_12 )
{
return F_145 ( V_6 , V_12 , 0 ,
F_159 ,
NULL , NULL , NULL ) ;
}
static int
F_166 ( struct V_82 * V_83 ,
const struct V_239 * V_240 )
{
if ( F_73 ( V_83 , V_241 ,
V_240 -> V_242 . V_243 . V_244 ) )
return - V_92 ;
if ( F_73 ( V_83 , V_245 ,
V_240 -> V_242 . V_243 . V_246 ) )
return - V_92 ;
if ( F_71 ( V_83 , V_247 ,
V_240 -> V_242 . V_243 . V_248 ) )
return - V_92 ;
return 0 ;
}
static int
F_167 ( struct V_82 * V_83 ,
const struct V_239 * V_240 )
{
if ( F_73 ( V_83 , V_241 ,
V_240 -> V_242 . V_249 . V_244 ) )
return - V_92 ;
if ( F_72 ( V_83 , V_250 ,
V_240 -> V_242 . V_249 . V_1 ) )
return - V_92 ;
if ( F_72 ( V_83 , V_251 ,
V_240 -> V_242 . V_249 . V_252 ) )
return - V_92 ;
if ( F_71 ( V_83 , V_247 ,
V_240 -> V_242 . V_249 . V_248 ) )
return - V_92 ;
if ( V_240 -> V_242 . V_249 . V_253 &&
F_72 ( V_83 , V_254 ,
V_240 -> V_242 . V_249 . V_255 ) )
return - V_92 ;
return 0 ;
}
static int
F_168 ( struct V_82 * V_83 ,
const struct V_239 * V_240 )
{
if ( F_73 ( V_83 , V_241 ,
V_240 -> V_242 . V_256 . V_244 ) )
return - V_92 ;
if ( F_73 ( V_83 , V_245 ,
V_240 -> V_242 . V_256 . V_246 ) )
return - V_92 ;
if ( F_72 ( V_83 , V_257 ,
V_240 -> V_242 . V_256 . V_258 ) )
return - V_92 ;
if ( F_68 ( V_83 , V_259 ,
V_228 , V_240 -> V_242 . V_256 . V_260 ) )
return - V_92 ;
if ( F_68 ( V_83 , V_261 ,
V_228 , V_240 -> V_242 . V_256 . V_262 ) )
return - V_92 ;
if ( F_72 ( V_83 , V_250 ,
V_240 -> V_242 . V_256 . V_1 ) )
return - V_92 ;
if ( F_72 ( V_83 , V_251 ,
V_240 -> V_242 . V_256 . V_252 ) )
return - V_92 ;
if ( F_71 ( V_83 , V_247 ,
V_240 -> V_242 . V_256 . V_248 ) )
return - V_92 ;
if ( V_240 -> V_242 . V_256 . V_263 &&
F_70 ( V_83 , V_264 ,
V_240 -> V_242 . V_256 . V_263 ) )
return - V_92 ;
return 0 ;
}
static int
F_169 ( struct V_82 * V_83 ,
const struct V_239 * V_240 )
{
if ( F_72 ( V_83 , V_257 ,
V_240 -> V_242 . V_265 . V_258 ) )
return - V_92 ;
if ( F_74 ( V_83 , V_266 ,
V_240 -> V_242 . V_265 . V_267 ) )
return - V_92 ;
if ( F_74 ( V_83 , V_268 ,
V_240 -> V_242 . V_265 . V_269 ) )
return - V_92 ;
if ( F_71 ( V_83 , V_247 ,
V_240 -> V_242 . V_265 . V_248 ) )
return - V_92 ;
if ( F_73 ( V_83 , V_270 ,
V_240 -> V_242 . V_265 . V_271 ) )
return - V_92 ;
return 0 ;
}
static int
F_170 ( struct V_82 * V_83 ,
const struct V_239 * V_240 )
{
if ( V_240 -> V_242 . V_272 . V_273 &&
F_68 ( V_83 , V_259 ,
V_228 , V_240 -> V_242 . V_272 . V_260 ) )
return - V_92 ;
if ( V_240 -> V_242 . V_272 . V_274 &&
F_68 ( V_83 , V_261 ,
V_228 , V_240 -> V_242 . V_272 . V_262 ) )
return - V_92 ;
if ( V_240 -> V_242 . V_272 . V_1 &&
F_72 ( V_83 , V_250 ,
V_240 -> V_242 . V_272 . V_1 ) )
return - V_92 ;
if ( V_240 -> V_242 . V_272 . V_275 &&
F_73 ( V_83 , V_276 ,
V_240 -> V_242 . V_272 . V_275 ) )
return - V_92 ;
if ( F_71 ( V_83 , V_247 ,
V_240 -> V_242 . V_272 . V_248 ) )
return - V_92 ;
if ( F_73 ( V_83 , V_270 ,
V_240 -> V_242 . V_272 . V_271 ) )
return - V_92 ;
if ( V_240 -> V_242 . V_272 . V_263 &&
F_70 ( V_83 , V_264 ,
V_240 -> V_242 . V_272 . V_263 ) )
return - V_92 ;
return 0 ;
}
static int
F_171 ( struct V_82 * V_83 ,
const struct V_239 * V_240 )
{
if ( F_73 ( V_83 , V_241 ,
V_240 -> V_242 . V_277 . V_244 ) )
return - V_92 ;
if ( F_73 ( V_83 , V_245 ,
V_240 -> V_242 . V_277 . V_246 ) )
return - V_92 ;
if ( F_68 ( V_83 , V_278 ,
V_228 , V_240 -> V_242 . V_277 . V_279 ) )
return - V_92 ;
if ( F_68 ( V_83 , V_280 ,
V_228 , V_240 -> V_242 . V_277 . V_281 ) )
return - V_92 ;
if ( F_68 ( V_83 , V_259 ,
V_228 , V_240 -> V_242 . V_277 . V_260 ) )
return - V_92 ;
if ( F_68 ( V_83 , V_261 ,
V_228 , V_240 -> V_242 . V_277 . V_262 ) )
return - V_92 ;
if ( F_72 ( V_83 , V_257 ,
V_240 -> V_242 . V_277 . V_258 ) )
return - V_92 ;
if ( F_72 ( V_83 , V_250 ,
V_240 -> V_242 . V_277 . V_1 ) )
return - V_92 ;
if ( F_72 ( V_83 , V_251 ,
V_240 -> V_242 . V_277 . V_252 ) )
return - V_92 ;
switch ( F_2 ( V_240 -> V_242 . V_277 . V_258 ) ) {
case V_282 :
case V_283 :
if ( F_70 ( V_83 , V_284 ,
V_240 -> V_242 . V_277 . V_285 ) )
return - V_92 ;
if ( F_70 ( V_83 ,
V_286 ,
V_240 -> V_242 . V_277 . V_287 ) )
return - V_92 ;
if ( F_70 ( V_83 , V_288 ,
V_240 -> V_242 . V_277 . V_289 & 0x3f ) )
return - V_92 ;
if ( F_70 ( V_83 ,
V_290 ,
V_240 -> V_242 . V_277 . V_291 & 0x3f ) )
return - V_92 ;
if ( F_70 ( V_83 , V_292 ,
( V_240 -> V_242 . V_277 . V_289 & 0xc0 ) >> 6 ) )
return - V_92 ;
if ( F_70 ( V_83 ,
V_293 ,
( V_240 -> V_242 . V_277 . V_291 & 0xc0 ) >> 6 ) )
return - V_92 ;
break;
}
if ( V_240 -> V_242 . V_277 . V_271 != V_294 &&
F_73 ( V_83 , V_270 ,
V_240 -> V_242 . V_277 . V_271 ) )
return - V_92 ;
return 0 ;
}
static int F_172 ( const struct V_6 * V_6 ,
struct V_82 * V_83 ,
void * V_197 )
{
const struct V_239 * V_240 = V_197 ;
struct V_70 * V_198 ;
int V_50 = 0 ;
if ( F_71 ( V_83 , V_199 , V_240 -> V_295 ) )
return - V_92 ;
V_198 = F_76 ( V_83 , V_201 ) ;
if ( ! V_198 )
return - V_92 ;
if ( F_71 ( V_83 , V_296 ,
V_240 -> V_242 . V_297 ) )
return - V_92 ;
if ( F_73 ( V_83 , V_298 ,
V_240 -> V_242 . V_299 ) )
return - V_92 ;
if ( F_73 ( V_83 , V_300 , 0 ) )
return - V_92 ;
if ( F_75 ( V_83 , V_301 ,
V_240 -> V_114 ) )
return - V_92 ;
switch ( V_240 -> V_242 . V_297 ) {
case V_302 :
V_50 = F_166 ( V_83 , V_240 ) ;
break;
case V_303 :
V_50 = F_167 ( V_83 , V_240 ) ;
break;
case V_304 :
V_50 = F_168 ( V_83 , V_240 ) ;
break;
case V_305 :
V_50 = F_169 ( V_83 , V_240 ) ;
break;
case V_306 :
V_50 = F_170 ( V_83 , V_240 ) ;
break;
case V_307 :
V_50 = F_171 ( V_83 , V_240 ) ;
break;
default:
V_50 = - V_308 ;
break;
}
if ( V_50 )
return V_50 ;
F_77 ( V_83 , V_198 ) ;
return 0 ;
}
static int F_173 ( const struct V_6 * V_6 ,
struct V_82 * V_83 ,
void * V_197 )
{
const struct V_239 * V_240 = V_197 ;
struct V_70 * V_198 ;
if ( F_71 ( V_83 , V_199 , V_240 -> V_295 ) )
return - V_92 ;
V_198 = F_76 ( V_83 , V_201 ) ;
if ( ! V_198 )
return - V_92 ;
if ( F_75 ( V_83 , V_301 ,
V_240 -> V_114 ) )
return - V_92 ;
F_77 ( V_83 , V_198 ) ;
return 0 ;
}
static int
F_174 ( struct V_82 * V_83 ,
struct V_309 * V_240 )
{
if ( F_73 ( V_83 , V_310 ,
F_175 ( V_240 -> V_271 ) ) )
return - V_92 ;
if ( F_70 ( V_83 , V_311 ,
V_240 -> V_312 . V_8 ) )
return - V_92 ;
return 0 ;
}
static int
F_176 ( struct V_82 * V_83 ,
const struct V_309 * V_240 )
{
if ( F_73 ( V_83 , V_313 ,
V_240 -> V_314 . V_271 ) )
return - V_92 ;
if ( ! F_177 ( V_240 -> V_314 . V_279 ) &&
F_68 ( V_83 , V_278 ,
V_228 , V_240 -> V_314 . V_279 ) )
return - V_92 ;
if ( ! F_177 ( V_240 -> V_314 . V_260 ) &&
F_68 ( V_83 , V_259 ,
V_228 , V_240 -> V_314 . V_260 ) )
return - V_92 ;
if ( V_240 -> V_314 . V_1 &&
F_72 ( V_83 , V_250 ,
V_240 -> V_314 . V_1 ) )
return - V_92 ;
return 0 ;
}
static int
F_178 ( struct V_82 * V_83 ,
const struct V_309 * V_240 )
{
int V_46 ;
struct V_70 * V_315 ;
if ( F_71 ( V_83 , V_316 ,
V_240 -> V_317 ) )
return - V_92 ;
V_315 = F_76 ( V_83 ,
V_318 ) ;
if ( ! V_315 )
return - V_92 ;
for ( V_46 = 0 ; V_46 < V_240 -> V_317 ; V_46 ++ )
if ( F_73 ( V_83 , V_46 + 1 , V_240 -> V_315 [ V_46 ] ) )
return - V_92 ;
F_77 ( V_83 , V_315 ) ;
return 0 ;
}
static int
F_179 ( struct V_82 * V_83 ,
const struct V_309 * V_240 )
{
if ( ! F_177 ( V_240 -> V_319 . V_279 ) &&
F_68 ( V_83 , V_278 ,
V_228 , V_240 -> V_319 . V_279 ) )
return - V_92 ;
if ( ! F_177 ( V_240 -> V_319 . V_260 ) &&
F_68 ( V_83 , V_259 ,
V_228 , V_240 -> V_319 . V_260 ) )
return - V_92 ;
if ( V_240 -> V_319 . V_1 &&
F_72 ( V_83 , V_250 ,
V_240 -> V_319 . V_1 ) )
return - V_92 ;
if ( F_70 ( V_83 , V_320 ,
V_240 -> V_319 . V_321 ) )
return - V_92 ;
if ( F_73 ( V_83 , V_313 ,
V_240 -> V_319 . V_271 ) )
return - V_92 ;
return 0 ;
}
static int F_180 ( const struct V_6 * V_6 ,
struct V_82 * V_83 ,
void * V_197 )
{
struct V_309 * V_240 = V_197 ;
struct V_70 * V_198 ;
int V_50 = 0 ;
if ( F_71 ( V_83 , V_199 , V_240 -> V_295 ) )
return - V_92 ;
V_198 = F_76 ( V_83 , V_201 ) ;
if ( ! V_198 )
return - V_92 ;
if ( F_73 ( V_83 , V_270 ,
V_240 -> V_271 ) )
return - V_92 ;
switch ( F_181 ( V_240 -> V_271 ) ) {
case V_322 :
V_50 = F_174 ( V_83 , V_240 ) ;
break;
case V_323 :
V_50 = F_176 ( V_83 , V_240 ) ;
break;
case V_324 :
case V_325 :
V_50 = F_178 ( V_83 , V_240 ) ;
break;
case V_326 :
V_50 = F_179 ( V_83 , V_240 ) ;
break;
default:
V_50 = - V_308 ;
break;
}
if ( V_50 )
return V_50 ;
F_77 ( V_83 , V_198 ) ;
return 0 ;
}
static int F_182 ( const struct V_6 * V_6 ,
struct V_82 * V_83 ,
void * V_197 )
{
const struct V_309 * V_240 = V_197 ;
struct V_70 * V_198 ;
if ( F_71 ( V_83 , V_199 , V_240 -> V_295 ) )
return - V_92 ;
V_198 = F_76 ( V_83 , V_201 ) ;
if ( ! V_198 )
return - V_92 ;
if ( F_73 ( V_83 , V_270 ,
V_240 -> V_271 ) )
return - V_92 ;
F_77 ( V_83 , V_198 ) ;
return 0 ;
}
static int F_183 ( struct V_30 * V_30 )
{
F_184 ( V_30 -> V_327 ) ;
F_111 ( & V_30 -> V_328 ) ;
F_184 ( V_30 -> V_329 ) ;
F_111 ( & V_30 -> V_330 ) ;
F_184 ( V_30 -> V_331 ) ;
F_111 ( & V_30 -> V_332 ) ;
F_184 ( V_30 -> V_333 ) ;
F_111 ( & V_30 -> V_334 ) ;
F_184 ( V_30 -> V_335 ) ;
F_111 ( & V_30 -> V_336 ) ;
return 0 ;
}
static void F_185 ( struct V_30 * V_30 )
{
unsigned long V_13 ;
struct V_239 * V_337 ;
struct V_309 * V_338 ;
struct V_339 * V_340 ;
struct V_341 * V_342 ;
struct V_343 * V_344 ;
struct V_345 * V_346 ;
int V_347 ;
F_146 ( & V_30 -> V_328 , V_13 ) ;
F_186 (rocker->flow_tbl, bkt, tmp, flow_entry, entry)
F_187 ( & V_337 -> V_240 ) ;
F_147 ( & V_30 -> V_328 , V_13 ) ;
F_146 ( & V_30 -> V_330 , V_13 ) ;
F_186 (rocker->group_tbl, bkt, tmp, group_entry, entry)
F_187 ( & V_338 -> V_240 ) ;
F_147 ( & V_30 -> V_330 , V_13 ) ;
F_146 ( & V_30 -> V_332 , V_13 ) ;
F_186 (rocker->fdb_tbl, bkt, tmp, fdb_entry, entry)
F_187 ( & V_340 -> V_240 ) ;
F_147 ( & V_30 -> V_332 , V_13 ) ;
F_146 ( & V_30 -> V_334 , V_13 ) ;
F_186 (rocker->internal_vlan_tbl, bkt,
tmp, internal_vlan_entry, entry)
F_187 ( & V_342 -> V_240 ) ;
F_147 ( & V_30 -> V_334 , V_13 ) ;
F_146 ( & V_30 -> V_336 , V_13 ) ;
F_186 (rocker->neigh_tbl, bkt, tmp, neigh_entry, entry)
F_187 ( & V_344 -> V_240 ) ;
F_147 ( & V_30 -> V_336 , V_13 ) ;
}
static struct V_239 *
F_188 ( const struct V_30 * V_30 ,
const struct V_239 * V_348 )
{
struct V_239 * V_349 ;
T_3 V_350 = V_348 -> V_350 ? V_348 -> V_350 : sizeof( V_349 -> V_242 ) ;
F_189 (rocker->flow_tbl, found,
entry, match->key_crc32) {
if ( memcmp ( & V_349 -> V_242 , & V_348 -> V_242 , V_350 ) == 0 )
return V_349 ;
}
return NULL ;
}
static int F_190 ( struct V_6 * V_6 ,
struct V_11 * V_12 , int V_13 ,
struct V_239 * V_348 )
{
struct V_30 * V_30 = V_6 -> V_30 ;
struct V_239 * V_349 ;
T_3 V_350 = V_348 -> V_350 ? V_348 -> V_350 : sizeof( V_349 -> V_242 ) ;
unsigned long V_194 ;
V_348 -> V_351 = F_191 ( ~ 0 , & V_348 -> V_242 , V_350 ) ;
F_146 ( & V_30 -> V_328 , V_194 ) ;
V_349 = F_188 ( V_30 , V_348 ) ;
if ( V_349 ) {
V_348 -> V_114 = V_349 -> V_114 ;
if ( ! F_12 ( V_12 ) )
F_187 ( & V_349 -> V_240 ) ;
F_17 ( V_12 , V_349 ) ;
V_349 = V_348 ;
V_349 -> V_295 = V_352 ;
} else {
V_349 = V_348 ;
V_349 -> V_114 = V_30 -> V_353 ++ ;
V_349 -> V_295 = V_354 ;
}
if ( ! F_12 ( V_12 ) )
F_192 ( V_30 -> V_327 , & V_349 -> V_240 , V_349 -> V_351 ) ;
F_147 ( & V_30 -> V_328 , V_194 ) ;
return F_145 ( V_6 , V_12 , V_13 ,
F_172 , V_349 , NULL , NULL ) ;
}
static int F_193 ( struct V_6 * V_6 ,
struct V_11 * V_12 , int V_13 ,
struct V_239 * V_348 )
{
struct V_30 * V_30 = V_6 -> V_30 ;
struct V_239 * V_349 ;
T_3 V_350 = V_348 -> V_350 ? V_348 -> V_350 : sizeof( V_349 -> V_242 ) ;
unsigned long V_194 ;
int V_50 = 0 ;
V_348 -> V_351 = F_191 ( ~ 0 , & V_348 -> V_242 , V_350 ) ;
F_146 ( & V_30 -> V_328 , V_194 ) ;
V_349 = F_188 ( V_30 , V_348 ) ;
if ( V_349 ) {
if ( ! F_12 ( V_12 ) )
F_187 ( & V_349 -> V_240 ) ;
V_349 -> V_295 = V_355 ;
}
F_147 ( & V_30 -> V_328 , V_194 ) ;
F_17 ( V_12 , V_348 ) ;
if ( V_349 ) {
V_50 = F_145 ( V_6 , V_12 , V_13 ,
F_173 ,
V_349 , NULL , NULL ) ;
F_17 ( V_12 , V_349 ) ;
}
return V_50 ;
}
static int F_194 ( struct V_6 * V_6 ,
struct V_11 * V_12 , int V_13 ,
struct V_239 * V_240 )
{
if ( V_13 & V_356 )
return F_193 ( V_6 , V_12 , V_13 , V_240 ) ;
else
return F_190 ( V_6 , V_12 , V_13 , V_240 ) ;
}
static int F_195 ( struct V_6 * V_6 ,
struct V_11 * V_12 , int V_13 ,
T_5 V_244 , T_5 V_246 ,
enum V_357 V_248 )
{
struct V_239 * V_240 ;
V_240 = F_15 ( V_6 , V_12 , V_13 , sizeof( * V_240 ) ) ;
if ( ! V_240 )
return - V_53 ;
V_240 -> V_242 . V_299 = V_358 ;
V_240 -> V_242 . V_297 = V_302 ;
V_240 -> V_242 . V_243 . V_244 = V_244 ;
V_240 -> V_242 . V_243 . V_246 = V_246 ;
V_240 -> V_242 . V_243 . V_248 = V_248 ;
return F_194 ( V_6 , V_12 , V_13 , V_240 ) ;
}
static int F_196 ( struct V_6 * V_6 ,
struct V_11 * V_12 , int V_13 ,
T_5 V_244 , T_1 V_1 ,
T_1 V_252 ,
enum V_357 V_248 ,
bool V_253 , T_1 V_255 )
{
struct V_239 * V_240 ;
V_240 = F_15 ( V_6 , V_12 , V_13 , sizeof( * V_240 ) ) ;
if ( ! V_240 )
return - V_53 ;
V_240 -> V_242 . V_299 = V_359 ;
V_240 -> V_242 . V_297 = V_303 ;
V_240 -> V_242 . V_249 . V_244 = V_244 ;
V_240 -> V_242 . V_249 . V_1 = V_1 ;
V_240 -> V_242 . V_249 . V_252 = V_252 ;
V_240 -> V_242 . V_249 . V_248 = V_248 ;
V_240 -> V_242 . V_249 . V_253 = V_253 ;
V_240 -> V_242 . V_249 . V_255 = V_255 ;
return F_194 ( V_6 , V_12 , V_13 , V_240 ) ;
}
static int F_197 ( struct V_6 * V_6 ,
struct V_11 * V_12 ,
T_5 V_244 , T_5 V_246 ,
T_1 V_258 , const T_9 * V_260 ,
const T_9 * V_262 , T_1 V_1 ,
T_1 V_252 , bool V_263 ,
int V_13 )
{
struct V_239 * V_240 ;
V_240 = F_15 ( V_6 , V_12 , V_13 , sizeof( * V_240 ) ) ;
if ( ! V_240 )
return - V_53 ;
if ( F_198 ( V_260 ) ) {
V_240 -> V_242 . V_299 = V_360 ;
V_240 -> V_242 . V_256 . V_248 =
V_361 ;
} else {
V_240 -> V_242 . V_299 = V_362 ;
V_240 -> V_242 . V_256 . V_248 =
V_305 ;
}
V_240 -> V_242 . V_297 = V_304 ;
V_240 -> V_242 . V_256 . V_244 = V_244 ;
V_240 -> V_242 . V_256 . V_246 = V_246 ;
V_240 -> V_242 . V_256 . V_258 = V_258 ;
F_152 ( V_240 -> V_242 . V_256 . V_260 , V_260 ) ;
F_152 ( V_240 -> V_242 . V_256 . V_262 , V_262 ) ;
V_240 -> V_242 . V_256 . V_1 = V_1 ;
V_240 -> V_242 . V_256 . V_252 = V_252 ;
V_240 -> V_242 . V_256 . V_263 = V_263 ;
return F_194 ( V_6 , V_12 , V_13 , V_240 ) ;
}
static int F_199 ( struct V_6 * V_6 ,
struct V_11 * V_12 , int V_13 ,
const T_9 * V_260 , const T_9 * V_262 ,
T_1 V_1 , T_5 V_275 ,
enum V_357 V_248 ,
T_5 V_271 , bool V_263 )
{
struct V_239 * V_240 ;
T_5 V_299 ;
bool V_363 = ! ! V_1 ;
bool V_364 = ! V_260 || ( V_260 && V_262 ) ;
bool V_365 = false ;
V_240 = F_15 ( V_6 , V_12 , V_13 , sizeof( * V_240 ) ) ;
if ( ! V_240 )
return - V_53 ;
V_240 -> V_242 . V_297 = V_306 ;
if ( V_260 ) {
V_240 -> V_242 . V_272 . V_273 = 1 ;
F_152 ( V_240 -> V_242 . V_272 . V_260 , V_260 ) ;
}
if ( V_262 ) {
V_240 -> V_242 . V_272 . V_274 = 1 ;
F_152 ( V_240 -> V_242 . V_272 . V_262 , V_262 ) ;
if ( ! F_200 ( V_262 , V_366 ) )
V_365 = true ;
}
V_299 = V_367 ;
if ( V_363 && V_364 && V_365 )
V_299 = V_368 ;
else if ( V_363 && V_364 && ! V_365 )
V_299 = V_369 ;
else if ( V_363 && ! V_364 )
V_299 = V_370 ;
else if ( ! V_363 && V_364 && V_365 )
V_299 = V_371 ;
else if ( ! V_363 && V_364 && ! V_365 )
V_299 = V_372 ;
else if ( ! V_363 && ! V_364 )
V_299 = V_373 ;
V_240 -> V_242 . V_299 = V_299 ;
V_240 -> V_242 . V_272 . V_1 = V_1 ;
V_240 -> V_242 . V_272 . V_275 = V_275 ;
V_240 -> V_242 . V_272 . V_248 = V_248 ;
V_240 -> V_242 . V_272 . V_271 = V_271 ;
V_240 -> V_242 . V_272 . V_263 = V_263 ;
return F_194 ( V_6 , V_12 , V_13 , V_240 ) ;
}
static int F_201 ( struct V_6 * V_6 ,
struct V_11 * V_12 ,
T_1 V_258 , T_10 V_374 ,
T_10 V_375 , T_5 V_299 ,
enum V_357 V_248 ,
T_5 V_271 , int V_13 )
{
struct V_239 * V_240 ;
V_240 = F_15 ( V_6 , V_12 , V_13 , sizeof( * V_240 ) ) ;
if ( ! V_240 )
return - V_53 ;
V_240 -> V_242 . V_297 = V_305 ;
V_240 -> V_242 . V_299 = V_299 ;
V_240 -> V_242 . V_265 . V_258 = V_258 ;
V_240 -> V_242 . V_265 . V_267 = V_374 ;
V_240 -> V_242 . V_265 . V_269 = V_375 ;
V_240 -> V_242 . V_265 . V_248 = V_248 ;
V_240 -> V_242 . V_265 . V_271 = V_271 ;
V_240 -> V_350 = F_202 ( struct V_376 ,
V_265 . V_271 ) ;
return F_194 ( V_6 , V_12 , V_13 , V_240 ) ;
}
static int F_203 ( struct V_6 * V_6 ,
struct V_11 * V_12 , int V_13 ,
T_5 V_244 , T_5 V_246 ,
const T_9 * V_279 , const T_9 * V_281 ,
const T_9 * V_260 , const T_9 * V_262 ,
T_1 V_258 , T_1 V_1 ,
T_1 V_252 , T_9 V_285 ,
T_9 V_287 , T_9 V_289 , T_9 V_291 ,
T_5 V_271 )
{
T_5 V_299 ;
struct V_239 * V_240 ;
V_240 = F_15 ( V_6 , V_12 , V_13 , sizeof( * V_240 ) ) ;
if ( ! V_240 )
return - V_53 ;
V_299 = V_377 ;
if ( V_260 && V_262 ) {
if ( F_200 ( V_262 , V_378 ) )
V_299 = V_379 ;
else if ( F_204 ( V_260 ) )
V_299 = V_380 ;
}
V_240 -> V_242 . V_299 = V_299 ;
V_240 -> V_242 . V_297 = V_307 ;
V_240 -> V_242 . V_277 . V_244 = V_244 ;
V_240 -> V_242 . V_277 . V_246 = V_246 ;
if ( V_279 )
F_152 ( V_240 -> V_242 . V_277 . V_279 , V_279 ) ;
if ( V_281 )
F_152 ( V_240 -> V_242 . V_277 . V_281 , V_281 ) ;
if ( V_260 )
F_152 ( V_240 -> V_242 . V_277 . V_260 , V_260 ) ;
if ( V_262 )
F_152 ( V_240 -> V_242 . V_277 . V_262 , V_262 ) ;
V_240 -> V_242 . V_277 . V_258 = V_258 ;
V_240 -> V_242 . V_277 . V_1 = V_1 ;
V_240 -> V_242 . V_277 . V_252 = V_252 ;
V_240 -> V_242 . V_277 . V_285 = V_285 ;
V_240 -> V_242 . V_277 . V_287 = V_287 ;
V_240 -> V_242 . V_277 . V_289 = V_289 ;
V_240 -> V_242 . V_277 . V_291 = V_291 ;
V_240 -> V_242 . V_277 . V_271 = V_271 ;
return F_194 ( V_6 , V_12 , V_13 , V_240 ) ;
}
static struct V_309 *
F_205 ( const struct V_30 * V_30 ,
const struct V_309 * V_348 )
{
struct V_309 * V_349 ;
F_189 (rocker->group_tbl, found,
entry, match->group_id) {
if ( V_349 -> V_271 == V_348 -> V_271 )
return V_349 ;
}
return NULL ;
}
static void F_206 ( struct V_11 * V_12 ,
struct V_309 * V_240 )
{
switch ( F_181 ( V_240 -> V_271 ) ) {
case V_324 :
case V_325 :
F_17 ( V_12 , V_240 -> V_315 ) ;
break;
default:
break;
}
F_17 ( V_12 , V_240 ) ;
}
static int F_207 ( struct V_6 * V_6 ,
struct V_11 * V_12 , int V_13 ,
struct V_309 * V_348 )
{
struct V_30 * V_30 = V_6 -> V_30 ;
struct V_309 * V_349 ;
unsigned long V_194 ;
F_146 ( & V_30 -> V_330 , V_194 ) ;
V_349 = F_205 ( V_30 , V_348 ) ;
if ( V_349 ) {
if ( ! F_12 ( V_12 ) )
F_187 ( & V_349 -> V_240 ) ;
F_206 ( V_12 , V_349 ) ;
V_349 = V_348 ;
V_349 -> V_295 = V_381 ;
} else {
V_349 = V_348 ;
V_349 -> V_295 = V_382 ;
}
if ( ! F_12 ( V_12 ) )
F_192 ( V_30 -> V_329 , & V_349 -> V_240 , V_349 -> V_271 ) ;
F_147 ( & V_30 -> V_330 , V_194 ) ;
return F_145 ( V_6 , V_12 , V_13 ,
F_180 , V_349 , NULL , NULL ) ;
}
static int F_208 ( struct V_6 * V_6 ,
struct V_11 * V_12 , int V_13 ,
struct V_309 * V_348 )
{
struct V_30 * V_30 = V_6 -> V_30 ;
struct V_309 * V_349 ;
unsigned long V_194 ;
int V_50 = 0 ;
F_146 ( & V_30 -> V_330 , V_194 ) ;
V_349 = F_205 ( V_30 , V_348 ) ;
if ( V_349 ) {
if ( ! F_12 ( V_12 ) )
F_187 ( & V_349 -> V_240 ) ;
V_349 -> V_295 = V_383 ;
}
F_147 ( & V_30 -> V_330 , V_194 ) ;
F_206 ( V_12 , V_348 ) ;
if ( V_349 ) {
V_50 = F_145 ( V_6 , V_12 , V_13 ,
F_182 ,
V_349 , NULL , NULL ) ;
F_206 ( V_12 , V_349 ) ;
}
return V_50 ;
}
static int F_209 ( struct V_6 * V_6 ,
struct V_11 * V_12 , int V_13 ,
struct V_309 * V_240 )
{
if ( V_13 & V_356 )
return F_208 ( V_6 , V_12 , V_13 , V_240 ) ;
else
return F_207 ( V_6 , V_12 , V_13 , V_240 ) ;
}
static int F_210 ( struct V_6 * V_6 ,
struct V_11 * V_12 , int V_13 ,
T_1 V_1 , T_5 V_384 ,
int V_8 )
{
struct V_309 * V_240 ;
V_240 = F_15 ( V_6 , V_12 , V_13 , sizeof( * V_240 ) ) ;
if ( ! V_240 )
return - V_53 ;
V_240 -> V_271 = F_211 ( V_1 , V_384 ) ;
V_240 -> V_312 . V_8 = V_8 ;
return F_209 ( V_6 , V_12 , V_13 , V_240 ) ;
}
static int F_212 ( struct V_6 * V_6 ,
struct V_11 * V_12 ,
int V_13 , T_9 V_317 ,
const T_5 * V_315 , T_5 V_271 )
{
struct V_309 * V_240 ;
V_240 = F_15 ( V_6 , V_12 , V_13 , sizeof( * V_240 ) ) ;
if ( ! V_240 )
return - V_53 ;
V_240 -> V_271 = V_271 ;
V_240 -> V_317 = V_317 ;
V_240 -> V_315 = F_16 ( V_6 , V_12 , V_13 ,
V_317 , sizeof( T_5 ) ) ;
if ( ! V_240 -> V_315 ) {
F_17 ( V_12 , V_240 ) ;
return - V_53 ;
}
memcpy ( V_240 -> V_315 , V_315 , V_317 * sizeof( T_5 ) ) ;
return F_209 ( V_6 , V_12 , V_13 , V_240 ) ;
}
static int F_213 ( struct V_6 * V_6 ,
struct V_11 * V_12 , int V_13 ,
T_1 V_1 , T_9 V_317 ,
const T_5 * V_315 , T_5 V_271 )
{
return F_212 ( V_6 , V_12 , V_13 ,
V_317 , V_315 ,
V_271 ) ;
}
static int F_214 ( struct V_6 * V_6 ,
struct V_11 * V_12 , int V_13 ,
T_5 V_385 , const T_9 * V_386 , const T_9 * V_387 ,
T_1 V_1 , bool V_321 , T_5 V_167 )
{
struct V_309 * V_240 ;
V_240 = F_15 ( V_6 , V_12 , V_13 , sizeof( * V_240 ) ) ;
if ( ! V_240 )
return - V_53 ;
V_240 -> V_271 = F_215 ( V_385 ) ;
if ( V_386 )
F_152 ( V_240 -> V_319 . V_279 , V_386 ) ;
if ( V_387 )
F_152 ( V_240 -> V_319 . V_260 , V_387 ) ;
V_240 -> V_319 . V_1 = V_1 ;
V_240 -> V_319 . V_321 = V_321 ;
V_240 -> V_319 . V_271 = F_211 ( V_1 , V_167 ) ;
return F_209 ( V_6 , V_12 , V_13 , V_240 ) ;
}
static struct V_343 *
F_216 ( const struct V_30 * V_30 , T_10 V_388 )
{
struct V_343 * V_349 ;
F_189 (rocker->neigh_tbl, found,
entry, be32_to_cpu(ip_addr))
if ( V_349 -> V_388 == V_388 )
return V_349 ;
return NULL ;
}
static void F_217 ( struct V_30 * V_30 ,
struct V_11 * V_12 ,
struct V_343 * V_240 )
{
if ( ! F_218 ( V_12 ) )
V_240 -> V_385 = V_30 -> V_389 ++ ;
if ( F_12 ( V_12 ) )
return;
V_240 -> V_390 ++ ;
F_192 ( V_30 -> V_335 , & V_240 -> V_240 ,
F_219 ( V_240 -> V_388 ) ) ;
}
static void F_220 ( struct V_11 * V_12 ,
struct V_343 * V_240 )
{
if ( F_12 ( V_12 ) )
return;
if ( -- V_240 -> V_390 == 0 ) {
F_187 ( & V_240 -> V_240 ) ;
F_17 ( V_12 , V_240 ) ;
}
}
static void F_221 ( struct V_343 * V_240 ,
struct V_11 * V_12 ,
const T_9 * V_260 , bool V_321 )
{
if ( V_260 ) {
F_152 ( V_240 -> V_260 , V_260 ) ;
V_240 -> V_321 = V_321 ;
} else if ( ! F_12 ( V_12 ) ) {
V_240 -> V_390 ++ ;
}
}
static int F_222 ( struct V_6 * V_6 ,
struct V_11 * V_12 ,
int V_13 , T_10 V_388 , const T_9 * V_260 )
{
struct V_30 * V_30 = V_6 -> V_30 ;
struct V_343 * V_240 ;
struct V_343 * V_349 ;
unsigned long V_194 ;
T_1 V_258 = F_4 ( V_282 ) ;
enum V_357 V_248 =
V_307 ;
T_5 V_271 ;
T_5 V_299 = 0 ;
bool V_391 = ! ( V_13 & V_356 ) ;
bool V_392 ;
bool V_393 ;
int V_50 = 0 ;
V_240 = F_15 ( V_6 , V_12 , V_13 , sizeof( * V_240 ) ) ;
if ( ! V_240 )
return - V_53 ;
F_146 ( & V_30 -> V_336 , V_194 ) ;
V_349 = F_216 ( V_30 , V_388 ) ;
V_392 = V_349 && V_391 ;
V_393 = V_349 && ! V_391 ;
V_391 = ! V_349 && V_391 ;
if ( V_391 ) {
V_240 -> V_388 = V_388 ;
V_240 -> V_39 = V_6 -> V_39 ;
F_152 ( V_240 -> V_260 , V_260 ) ;
V_240 -> V_321 = true ;
F_217 ( V_30 , V_12 , V_240 ) ;
} else if ( V_393 ) {
memcpy ( V_240 , V_349 , sizeof( * V_240 ) ) ;
F_220 ( V_12 , V_349 ) ;
} else if ( V_392 ) {
F_221 ( V_349 , V_12 , V_260 , true ) ;
memcpy ( V_240 , V_349 , sizeof( * V_240 ) ) ;
} else {
V_50 = - V_100 ;
}
F_147 ( & V_30 -> V_336 , V_194 ) ;
if ( V_50 )
goto V_394;
V_50 = F_214 ( V_6 , V_12 , V_13 ,
V_240 -> V_385 ,
V_6 -> V_39 -> V_395 ,
V_240 -> V_260 ,
V_6 -> V_9 ,
V_240 -> V_321 ,
V_6 -> V_167 ) ;
if ( V_50 ) {
F_124 ( V_6 -> V_39 ,
L_21 ,
V_50 , V_240 -> V_385 ) ;
goto V_394;
}
if ( V_391 || V_393 ) {
V_271 = F_215 ( V_240 -> V_385 ) ;
V_50 = F_201 ( V_6 , V_12 ,
V_258 , V_388 ,
F_223 ( 32 ) ,
V_299 , V_248 ,
V_271 , V_13 ) ;
if ( V_50 )
F_124 ( V_6 -> V_39 ,
L_22 ,
V_50 , & V_240 -> V_388 , V_271 ) ;
}
V_394:
if ( ! V_391 )
F_17 ( V_12 , V_240 ) ;
return V_50 ;
}
static int F_224 ( struct V_6 * V_6 ,
struct V_11 * V_12 ,
T_10 V_388 )
{
struct V_150 * V_39 = V_6 -> V_39 ;
struct V_396 * V_22 = F_225 ( V_39 , ( V_397 T_5 ) V_388 ) ;
int V_50 = 0 ;
if ( ! V_22 ) {
V_22 = F_226 ( & V_398 , & V_388 , V_39 ) ;
if ( F_227 ( V_22 ) )
return F_227 ( V_22 ) ;
}
if ( V_22 -> V_399 & V_400 )
V_50 = F_222 ( V_6 , V_12 , 0 ,
V_388 , V_22 -> V_401 ) ;
else
F_228 ( V_22 , NULL ) ;
F_229 ( V_22 ) ;
return V_50 ;
}
static int F_230 ( struct V_6 * V_6 ,
struct V_11 * V_12 , int V_13 ,
T_10 V_388 , T_5 * V_385 )
{
struct V_30 * V_30 = V_6 -> V_30 ;
struct V_343 * V_240 ;
struct V_343 * V_349 ;
unsigned long V_194 ;
bool V_391 = ! ( V_13 & V_356 ) ;
bool V_392 ;
bool V_393 ;
bool V_402 = true ;
int V_50 = 0 ;
V_240 = F_15 ( V_6 , V_12 , V_13 , sizeof( * V_240 ) ) ;
if ( ! V_240 )
return - V_53 ;
F_146 ( & V_30 -> V_336 , V_194 ) ;
V_349 = F_216 ( V_30 , V_388 ) ;
if ( V_349 )
* V_385 = V_349 -> V_385 ;
V_392 = V_349 && V_391 ;
V_393 = V_349 && ! V_391 ;
V_391 = ! V_349 && V_391 ;
if ( V_391 ) {
V_240 -> V_388 = V_388 ;
V_240 -> V_39 = V_6 -> V_39 ;
F_217 ( V_30 , V_12 , V_240 ) ;
* V_385 = V_240 -> V_385 ;
V_402 = false ;
} else if ( V_393 ) {
F_220 ( V_12 , V_349 ) ;
} else if ( V_392 ) {
F_221 ( V_349 , V_12 , NULL , false ) ;
V_402 = ! F_177 ( V_349 -> V_260 ) ;
} else {
V_50 = - V_100 ;
}
F_147 ( & V_30 -> V_336 , V_194 ) ;
if ( ! V_391 )
F_17 ( V_12 , V_240 ) ;
if ( V_50 )
return V_50 ;
if ( ! V_402 )
V_50 = F_224 ( V_6 , V_12 , V_388 ) ;
return V_50 ;
}
static int F_231 ( struct V_6 * V_6 ,
struct V_11 * V_12 ,
int V_13 , T_1 V_1 )
{
struct V_6 * V_403 ;
const struct V_30 * V_30 = V_6 -> V_30 ;
T_5 V_271 = F_232 ( V_1 , 0 ) ;
T_5 * V_315 ;
T_9 V_317 = 0 ;
int V_50 = 0 ;
int V_46 ;
V_315 = F_16 ( V_6 , V_12 , V_13 ,
V_30 -> V_172 , sizeof( T_5 ) ) ;
if ( ! V_315 )
return - V_53 ;
for ( V_46 = 0 ; V_46 < V_30 -> V_172 ; V_46 ++ ) {
V_403 = V_30 -> V_173 [ V_46 ] ;
if ( ! V_403 )
continue;
if ( ! F_6 ( V_403 ) )
continue;
if ( F_233 ( F_2 ( V_1 ) , V_403 -> V_404 ) ) {
V_315 [ V_317 ++ ] =
F_211 ( V_1 , V_403 -> V_167 ) ;
}
}
if ( V_317 == 0 )
goto V_405;
V_50 = F_213 ( V_6 , V_12 , V_13 , V_1 ,
V_317 , V_315 , V_271 ) ;
if ( V_50 )
F_124 ( V_6 -> V_39 ,
L_23 , V_50 ) ;
V_405:
F_17 ( V_12 , V_315 ) ;
return V_50 ;
}
static int F_234 ( struct V_6 * V_6 ,
struct V_11 * V_12 , int V_13 ,
T_1 V_1 , bool V_8 )
{
const struct V_30 * V_30 = V_6 -> V_30 ;
struct V_6 * V_403 ;
bool V_391 = ! ( V_13 & V_356 ) ;
T_5 V_384 ;
int V_406 = 0 ;
int V_50 ;
int V_46 ;
if ( V_6 -> V_180 == V_181 ||
V_6 -> V_180 == V_182 ) {
V_384 = V_6 -> V_167 ;
V_50 = F_210 ( V_6 , V_12 , V_13 ,
V_1 , V_384 , V_8 ) ;
if ( V_50 ) {
F_124 ( V_6 -> V_39 ,
L_24 ,
V_50 , V_384 ) ;
return V_50 ;
}
}
for ( V_46 = 0 ; V_46 < V_30 -> V_172 ; V_46 ++ ) {
V_403 = V_30 -> V_173 [ V_46 ] ;
if ( V_403 && F_233 ( F_2 ( V_1 ) , V_403 -> V_404 ) )
V_406 ++ ;
}
if ( ( ! V_391 || V_406 != 1 ) && ( V_391 || V_406 != 0 ) )
return 0 ;
V_384 = 0 ;
V_50 = F_210 ( V_6 , V_12 , V_13 ,
V_1 , V_384 , V_8 ) ;
if ( V_50 ) {
F_124 ( V_6 -> V_39 ,
L_25 , V_50 ) ;
return V_50 ;
}
return 0 ;
}
static int F_235 ( struct V_6 * V_6 ,
struct V_11 * V_12 , int V_13 ,
const struct V_407 * V_408 , T_1 V_1 )
{
T_5 V_244 = V_6 -> V_167 ;
T_5 V_246 = 0xffffffff ;
T_5 V_384 = 0 ;
const T_9 * V_279 = NULL ;
const T_9 * V_281 = NULL ;
T_1 V_252 = F_4 ( 0xffff ) ;
T_9 V_285 = 0 ;
T_9 V_287 = 0 ;
T_9 V_289 = 0 ;
T_9 V_291 = 0 ;
T_5 V_271 = F_211 ( V_1 , V_384 ) ;
int V_50 ;
V_50 = F_203 ( V_6 , V_12 , V_13 ,
V_244 , V_246 ,
V_279 , V_281 ,
V_408 -> V_260 , V_408 -> V_262 ,
V_408 -> V_258 ,
V_1 , V_252 ,
V_285 , V_287 ,
V_289 , V_291 ,
V_271 ) ;
if ( V_50 )
F_124 ( V_6 -> V_39 , L_26 , V_50 ) ;
return V_50 ;
}
static int F_236 ( struct V_6 * V_6 ,
struct V_11 * V_12 ,
int V_13 ,
const struct V_407 * V_408 ,
T_1 V_1 )
{
enum V_357 V_248 =
V_307 ;
T_5 V_271 = F_232 ( V_1 , 0 ) ;
T_5 V_275 = 0 ;
int V_50 ;
if ( ! F_6 ( V_6 ) )
return 0 ;
V_50 = F_199 ( V_6 , V_12 , V_13 ,
V_408 -> V_260 , V_408 -> V_262 ,
V_1 , V_275 ,
V_248 , V_271 , V_408 -> V_263 ) ;
if ( V_50 )
F_124 ( V_6 -> V_39 , L_27 , V_50 ) ;
return V_50 ;
}
static int F_237 ( struct V_6 * V_6 ,
struct V_11 * V_12 , int V_13 ,
const struct V_407 * V_408 , T_1 V_1 )
{
T_5 V_246 = 0xffffffff ;
T_1 V_252 = F_4 ( 0xffff ) ;
int V_50 ;
if ( F_2 ( V_1 ) == 0 )
V_1 = V_6 -> V_9 ;
V_50 = F_197 ( V_6 , V_12 ,
V_6 -> V_167 , V_246 ,
V_408 -> V_258 , V_408 -> V_260 ,
V_408 -> V_262 , V_1 ,
V_252 , V_408 -> V_263 ,
V_13 ) ;
if ( V_50 )
F_124 ( V_6 -> V_39 , L_28 , V_50 ) ;
return V_50 ;
}
static int F_238 ( struct V_6 * V_6 ,
struct V_11 * V_12 , int V_13 ,
const struct V_407 * V_408 , T_1 V_1 )
{
if ( V_408 -> V_277 )
return F_235 ( V_6 , V_12 , V_13 ,
V_408 , V_1 ) ;
if ( V_408 -> V_272 )
return F_236 ( V_6 , V_12 , V_13 ,
V_408 , V_1 ) ;
if ( V_408 -> V_409 )
return F_237 ( V_6 , V_12 , V_13 ,
V_408 , V_1 ) ;
return - V_110 ;
}
static int F_239 ( struct V_6 * V_6 ,
struct V_11 * V_12 , int V_13 ,
T_1 V_1 )
{
int V_50 = 0 ;
int V_46 ;
for ( V_46 = 0 ; V_46 < V_410 ; V_46 ++ ) {
if ( V_6 -> V_411 [ V_46 ] ) {
V_50 = F_238 ( V_6 , V_12 , V_13 ,
& V_412 [ V_46 ] , V_1 ) ;
if ( V_50 )
return V_50 ;
}
}
return V_50 ;
}
static int F_240 ( struct V_6 * V_6 ,
struct V_11 * V_12 , int V_13 ,
const struct V_407 * V_408 )
{
T_2 V_7 ;
int V_50 = 0 ;
for ( V_7 = 1 ; V_7 < V_413 ; V_7 ++ ) {
if ( ! F_233 ( V_7 , V_6 -> V_404 ) )
continue;
V_50 = F_238 ( V_6 , V_12 , V_13 ,
V_408 , F_4 ( V_7 ) ) ;
if ( V_50 )
break;
}
return V_50 ;
}
static int F_241 ( struct V_6 * V_6 ,
struct V_11 * V_12 , int V_13 , T_2 V_7 )
{
enum V_357 V_248 =
V_304 ;
T_5 V_244 = V_6 -> V_167 ;
T_1 V_1 = F_4 ( V_7 ) ;
T_1 V_252 = F_4 ( 0xffff ) ;
T_1 V_9 ;
bool V_253 ;
bool V_391 = ! ( V_13 & V_356 ) ;
int V_50 ;
V_9 = F_3 ( V_6 , V_7 , & V_253 ) ;
if ( V_391 && F_233 ( F_2 ( V_9 ) ,
V_6 -> V_404 ) )
return 0 ;
else if ( ! V_391 && ! F_233 ( F_2 ( V_9 ) ,
V_6 -> V_404 ) )
return 0 ;
F_242 ( F_2 ( V_9 ) , V_6 -> V_404 ) ;
if ( V_391 ) {
V_50 = F_239 ( V_6 , V_12 , V_13 ,
V_9 ) ;
if ( V_50 ) {
F_124 ( V_6 -> V_39 ,
L_29 , V_50 ) ;
goto V_394;
}
}
V_50 = F_234 ( V_6 , V_12 , V_13 ,
V_9 , V_253 ) ;
if ( V_50 ) {
F_124 ( V_6 -> V_39 ,
L_30 , V_50 ) ;
goto V_394;
}
V_50 = F_231 ( V_6 , V_12 , V_13 ,
V_9 ) ;
if ( V_50 ) {
F_124 ( V_6 -> V_39 ,
L_23 , V_50 ) ;
goto V_394;
}
V_50 = F_196 ( V_6 , V_12 , V_13 ,
V_244 , V_1 , V_252 ,
V_248 , V_253 , V_9 ) ;
if ( V_50 )
F_124 ( V_6 -> V_39 ,
L_31 , V_50 ) ;
V_394:
if ( F_12 ( V_12 ) )
F_242 ( F_2 ( V_9 ) , V_6 -> V_404 ) ;
return V_50 ;
}
static int F_243 ( struct V_6 * V_6 ,
struct V_11 * V_12 , int V_13 )
{
enum V_357 V_248 ;
T_5 V_244 ;
T_5 V_246 ;
int V_50 ;
V_244 = 0 ;
V_246 = 0xffff0000 ;
V_248 = V_303 ;
V_50 = F_195 ( V_6 , V_12 , V_13 ,
V_244 , V_246 ,
V_248 ) ;
if ( V_50 )
F_124 ( V_6 -> V_39 ,
L_32 , V_50 ) ;
return V_50 ;
}
static void F_244 ( struct V_414 * V_415 )
{
const struct V_416 * V_417 =
F_245 ( V_415 , struct V_416 , V_415 ) ;
bool V_393 = ( V_417 -> V_13 & V_356 ) ;
bool V_418 = ( V_417 -> V_13 & V_176 ) ;
struct V_419 V_117 ;
V_117 . V_175 = V_417 -> V_175 ;
V_117 . V_7 = V_417 -> V_7 ;
if ( V_418 && V_393 )
F_246 ( V_420 ,
V_417 -> V_6 -> V_39 , & V_117 . V_117 ) ;
else if ( V_418 && ! V_393 )
F_246 ( V_421 ,
V_417 -> V_6 -> V_39 , & V_117 . V_117 ) ;
F_17 ( V_417 -> V_12 , V_415 ) ;
}
static int F_247 ( struct V_6 * V_6 ,
struct V_11 * V_12 , int V_13 ,
const T_9 * V_175 , T_1 V_1 )
{
struct V_416 * V_417 ;
enum V_357 V_248 =
V_307 ;
T_5 V_384 = V_6 -> V_167 ;
T_5 V_275 = 0 ;
T_5 V_271 = V_294 ;
bool V_422 = ! ! ( V_6 -> V_237 & V_423 ) ;
bool V_263 = false ;
int V_50 ;
if ( F_6 ( V_6 ) )
V_271 = F_211 ( V_1 , V_384 ) ;
if ( ! ( V_13 & V_424 ) ) {
V_50 = F_199 ( V_6 , V_12 , V_13 , V_175 ,
NULL , V_1 , V_275 , V_248 ,
V_271 , V_263 ) ;
if ( V_50 )
return V_50 ;
}
if ( ! V_422 )
return 0 ;
if ( ! F_6 ( V_6 ) )
return 0 ;
V_417 = F_15 ( V_6 , V_12 , V_13 , sizeof( * V_417 ) ) ;
if ( ! V_417 )
return - V_53 ;
F_248 ( & V_417 -> V_415 , F_244 ) ;
V_417 -> V_6 = V_6 ;
V_417 -> V_12 = V_12 ;
V_417 -> V_13 = V_13 ;
F_152 ( V_417 -> V_175 , V_175 ) ;
V_417 -> V_7 = F_5 ( V_6 , V_1 ) ;
if ( F_12 ( V_12 ) )
F_17 ( V_12 , V_417 ) ;
else
F_249 ( & V_417 -> V_415 ) ;
return 0 ;
}
static struct V_339 *
F_250 ( const struct V_30 * V_30 ,
const struct V_339 * V_348 )
{
struct V_339 * V_349 ;
F_189 (rocker->fdb_tbl, found, entry, match->key_crc32)
if ( memcmp ( & V_349 -> V_242 , & V_348 -> V_242 , sizeof( V_349 -> V_242 ) ) == 0 )
return V_349 ;
return NULL ;
}
static int F_139 ( struct V_6 * V_6 ,
struct V_11 * V_12 ,
const unsigned char * V_175 ,
T_1 V_1 , int V_13 )
{
struct V_30 * V_30 = V_6 -> V_30 ;
struct V_339 * V_425 ;
struct V_339 * V_349 ;
bool V_393 = ( V_13 & V_356 ) ;
unsigned long V_194 ;
V_425 = F_15 ( V_6 , V_12 , V_13 , sizeof( * V_425 ) ) ;
if ( ! V_425 )
return - V_53 ;
V_425 -> V_418 = ( V_13 & V_176 ) ;
V_425 -> V_426 = V_427 ;
V_425 -> V_242 . V_6 = V_6 ;
F_152 ( V_425 -> V_242 . V_175 , V_175 ) ;
V_425 -> V_242 . V_1 = V_1 ;
V_425 -> V_351 = F_191 ( ~ 0 , & V_425 -> V_242 , sizeof( V_425 -> V_242 ) ) ;
F_146 ( & V_30 -> V_332 , V_194 ) ;
V_349 = F_250 ( V_30 , V_425 ) ;
if ( V_349 ) {
V_349 -> V_426 = V_427 ;
if ( V_393 ) {
F_17 ( V_12 , V_425 ) ;
if ( ! F_12 ( V_12 ) )
F_187 ( & V_349 -> V_240 ) ;
}
} else if ( ! V_393 ) {
if ( ! F_12 ( V_12 ) )
F_192 ( V_30 -> V_331 , & V_425 -> V_240 ,
V_425 -> V_351 ) ;
}
F_147 ( & V_30 -> V_332 , V_194 ) ;
if ( ! V_349 != ! V_393 ) {
F_17 ( V_12 , V_425 ) ;
if ( ! V_349 && V_393 )
return 0 ;
V_13 |= V_424 ;
}
return F_247 ( V_6 , V_12 , V_13 , V_175 , V_1 ) ;
}
static int F_251 ( struct V_6 * V_6 ,
struct V_11 * V_12 , int V_13 )
{
struct V_30 * V_30 = V_6 -> V_30 ;
struct V_339 * V_349 ;
unsigned long V_194 ;
struct V_345 * V_346 ;
int V_347 ;
int V_50 = 0 ;
if ( V_6 -> V_180 == V_181 ||
V_6 -> V_180 == V_182 )
return 0 ;
V_13 |= V_18 | V_356 ;
F_146 ( & V_30 -> V_332 , V_194 ) ;
F_186 (rocker->fdb_tbl, bkt, tmp, found, entry) {
if ( V_349 -> V_242 . V_6 != V_6 )
continue;
if ( ! V_349 -> V_418 )
continue;
V_50 = F_247 ( V_6 , V_12 , V_13 ,
V_349 -> V_242 . V_175 ,
V_349 -> V_242 . V_1 ) ;
if ( V_50 )
goto V_394;
if ( ! F_12 ( V_12 ) )
F_187 ( & V_349 -> V_240 ) ;
}
V_394:
F_147 ( & V_30 -> V_332 , V_194 ) ;
return V_50 ;
}
static void F_252 ( unsigned long V_84 )
{
struct V_30 * V_30 = (struct V_30 * ) V_84 ;
struct V_6 * V_6 ;
struct V_339 * V_240 ;
struct V_345 * V_346 ;
unsigned long V_428 = V_427 + V_429 ;
unsigned long V_430 ;
unsigned long V_194 ;
int V_13 = V_18 | V_356 |
V_176 ;
int V_347 ;
F_146 ( & V_30 -> V_332 , V_194 ) ;
F_186 (rocker->fdb_tbl, bkt, tmp, entry, entry) {
if ( ! V_240 -> V_418 )
continue;
V_6 = V_240 -> V_242 . V_6 ;
V_430 = V_240 -> V_426 + V_6 -> V_431 ;
if ( F_253 ( V_430 , V_427 ) ) {
F_247 ( V_6 , NULL ,
V_13 , V_240 -> V_242 . V_175 ,
V_240 -> V_242 . V_1 ) ;
F_187 ( & V_240 -> V_240 ) ;
} else if ( F_254 ( V_430 , V_428 ) ) {
V_428 = V_430 ;
}
}
F_147 ( & V_30 -> V_332 , V_194 ) ;
F_255 ( & V_30 -> V_432 , F_256 ( V_428 ) ) ;
}
static int F_257 ( struct V_6 * V_6 ,
struct V_11 * V_12 , int V_13 ,
T_1 V_1 )
{
T_5 V_246 = 0xffffffff ;
T_1 V_258 ;
const T_9 * V_433 = V_366 ;
T_1 V_252 = F_4 ( 0xffff ) ;
bool V_263 = false ;
int V_50 ;
if ( F_2 ( V_1 ) == 0 )
V_1 = V_6 -> V_9 ;
V_258 = F_4 ( V_282 ) ;
V_50 = F_197 ( V_6 , V_12 ,
V_6 -> V_167 , V_246 ,
V_258 , V_6 -> V_39 -> V_395 ,
V_433 , V_1 , V_252 ,
V_263 , V_13 ) ;
if ( V_50 )
return V_50 ;
V_258 = F_4 ( V_283 ) ;
V_50 = F_197 ( V_6 , V_12 ,
V_6 -> V_167 , V_246 ,
V_258 , V_6 -> V_39 -> V_395 ,
V_433 , V_1 , V_252 ,
V_263 , V_13 ) ;
return V_50 ;
}
static int F_258 ( struct V_6 * V_6 ,
struct V_11 * V_12 , int V_13 )
{
bool V_8 ;
T_5 V_384 ;
T_1 V_1 ;
T_2 V_7 ;
int V_50 ;
if ( V_6 -> V_180 != V_181 &&
V_6 -> V_180 != V_182 )
V_13 |= V_356 ;
V_384 = V_6 -> V_167 ;
for ( V_7 = 1 ; V_7 < V_413 ; V_7 ++ ) {
if ( ! F_233 ( V_7 , V_6 -> V_404 ) )
continue;
V_1 = F_4 ( V_7 ) ;
V_8 = F_1 ( V_1 ) ;
V_50 = F_210 ( V_6 , V_12 , V_13 ,
V_1 , V_384 , V_8 ) ;
if ( V_50 ) {
F_124 ( V_6 -> V_39 ,
L_24 ,
V_50 , V_384 ) ;
return V_50 ;
}
}
return 0 ;
}
static int F_259 ( struct V_6 * V_6 ,
struct V_11 * V_12 , int V_13 ,
T_9 V_434 )
{
bool V_435 [ V_410 ] = { 0 , } ;
bool V_436 [ V_410 ] ;
T_9 V_437 ( V_438 ) ;
int V_50 ;
int V_46 ;
if ( F_12 ( V_12 ) ) {
memcpy ( V_436 , V_6 -> V_411 , sizeof( V_436 ) ) ;
V_438 = V_6 -> V_180 ;
}
if ( V_6 -> V_180 == V_434 )
return 0 ;
V_6 -> V_180 = V_434 ;
switch ( V_434 ) {
case V_439 :
break;
case V_440 :
case V_441 :
V_435 [ V_442 ] = true ;
break;
case V_181 :
case V_182 :
if ( ! F_8 ( V_6 ) )
V_435 [ V_442 ] = true ;
V_435 [ V_443 ] = true ;
V_435 [ V_444 ] = true ;
if ( F_6 ( V_6 ) )
V_435 [ V_445 ] = true ;
else if ( F_8 ( V_6 ) )
V_435 [ V_446 ] = true ;
else
V_435 [ V_447 ] = true ;
break;
}
for ( V_46 = 0 ; V_46 < V_410 ; V_46 ++ ) {
if ( V_435 [ V_46 ] != V_6 -> V_411 [ V_46 ] ) {
int V_448 = V_13 |
( V_435 [ V_46 ] ? 0 : V_356 ) ;
V_50 = F_240 ( V_6 , V_12 , V_448 ,
& V_412 [ V_46 ] ) ;
if ( V_50 )
goto V_394;
V_6 -> V_411 [ V_46 ] = V_435 [ V_46 ] ;
}
}
V_50 = F_251 ( V_6 , V_12 , V_13 ) ;
if ( V_50 )
goto V_394;
V_50 = F_258 ( V_6 , V_12 , V_13 ) ;
V_394:
if ( F_12 ( V_12 ) ) {
memcpy ( V_6 -> V_411 , V_436 , sizeof( V_436 ) ) ;
V_6 -> V_180 = V_438 ;
}
return V_50 ;
}
static int F_260 ( struct V_6 * V_6 ,
struct V_11 * V_12 , int V_13 )
{
if ( F_6 ( V_6 ) )
return 0 ;
return F_259 ( V_6 , V_12 , V_13 ,
V_182 ) ;
}
static int F_261 ( struct V_6 * V_6 ,
struct V_11 * V_12 , int V_13 )
{
if ( F_6 ( V_6 ) )
return 0 ;
return F_259 ( V_6 , V_12 , V_13 ,
V_439 ) ;
}
static struct V_341 *
F_262 ( const struct V_30 * V_30 , int V_449 )
{
struct V_341 * V_349 ;
F_189 (rocker->internal_vlan_tbl, found,
entry, ifindex) {
if ( V_349 -> V_449 == V_449 )
return V_349 ;
}
return NULL ;
}
static T_1 F_263 ( struct V_6 * V_6 ,
int V_449 )
{
struct V_30 * V_30 = V_6 -> V_30 ;
struct V_341 * V_240 ;
struct V_341 * V_349 ;
unsigned long V_194 ;
int V_46 ;
V_240 = F_11 ( sizeof( * V_240 ) , V_20 ) ;
if ( ! V_240 )
return 0 ;
V_240 -> V_449 = V_449 ;
F_146 ( & V_30 -> V_334 , V_194 ) ;
V_349 = F_262 ( V_30 , V_449 ) ;
if ( V_349 ) {
V_21 ( V_240 ) ;
goto V_349;
}
V_349 = V_240 ;
F_192 ( V_30 -> V_333 , & V_349 -> V_240 , V_349 -> V_449 ) ;
for ( V_46 = 0 ; V_46 < V_450 ; V_46 ++ ) {
if ( F_264 ( V_46 , V_30 -> V_451 ) )
continue;
V_349 -> V_1 = F_4 ( V_3 + V_46 ) ;
goto V_349;
}
F_124 ( V_6 -> V_39 , L_33 ) ;
V_349:
V_349 -> V_390 ++ ;
F_147 ( & V_30 -> V_334 , V_194 ) ;
return V_349 -> V_1 ;
}
static void
F_265 ( const struct V_6 * V_6 ,
int V_449 )
{
struct V_30 * V_30 = V_6 -> V_30 ;
struct V_341 * V_349 ;
unsigned long V_194 ;
unsigned long V_452 ;
F_146 ( & V_30 -> V_334 , V_194 ) ;
V_349 = F_262 ( V_30 , V_449 ) ;
if ( ! V_349 ) {
F_124 ( V_6 -> V_39 ,
L_34 ,
V_449 ) ;
goto V_453;
}
if ( -- V_349 -> V_390 <= 0 ) {
V_452 = F_2 ( V_349 -> V_1 ) - V_3 ;
F_266 ( V_452 , V_30 -> V_451 ) ;
F_187 ( & V_349 -> V_240 ) ;
V_21 ( V_349 ) ;
}
V_453:
F_147 ( & V_30 -> V_334 , V_194 ) ;
}
static int F_267 ( struct V_6 * V_6 ,
struct V_11 * V_12 , T_10 V_374 ,
int V_454 , const struct V_455 * V_456 ,
T_5 V_457 , int V_13 )
{
const struct V_458 * V_459 ;
T_1 V_258 = F_4 ( V_282 ) ;
T_10 V_375 = F_223 ( V_454 ) ;
T_1 V_9 = V_6 -> V_9 ;
T_5 V_299 = V_456 -> V_460 ;
enum V_357 V_248 =
V_307 ;
T_5 V_271 ;
bool V_461 ;
bool V_462 ;
T_5 V_385 ;
int V_50 ;
V_459 = V_456 -> V_458 ;
V_461 = ( V_456 -> V_463 == V_6 -> V_39 ) ;
V_462 = ! ! V_459 -> V_464 ;
if ( V_462 && V_461 ) {
V_50 = F_230 ( V_6 , V_12 , V_13 ,
V_459 -> V_464 , & V_385 ) ;
if ( V_50 )
return V_50 ;
V_271 = F_215 ( V_385 ) ;
} else {
V_271 = F_211 ( V_9 , 0 ) ;
}
V_50 = F_201 ( V_6 , V_12 , V_258 , V_374 ,
V_375 , V_299 , V_248 ,
V_271 , V_13 ) ;
if ( V_50 )
F_124 ( V_6 -> V_39 , L_35 ,
V_50 , & V_374 ) ;
return V_50 ;
}
static int F_268 ( struct V_150 * V_39 )
{
struct V_6 * V_6 = F_269 ( V_39 ) ;
int V_50 ;
V_50 = F_122 ( V_6 ) ;
if ( V_50 )
return V_50 ;
V_50 = F_48 ( F_28 ( V_6 ) ,
F_142 , 0 ,
V_67 , V_6 ) ;
if ( V_50 ) {
F_124 ( V_6 -> V_39 , L_36 ) ;
goto V_465;
}
V_50 = F_48 ( F_30 ( V_6 ) ,
F_144 , 0 ,
V_67 , V_6 ) ;
if ( V_50 ) {
F_124 ( V_6 -> V_39 , L_37 ) ;
goto V_466;
}
V_50 = F_260 ( V_6 , NULL , 0 ) ;
if ( V_50 )
goto V_467;
F_270 ( & V_6 -> V_188 ) ;
F_270 ( & V_6 -> V_189 ) ;
if ( ! V_39 -> V_468 )
F_127 ( V_6 , true ) ;
F_271 ( V_39 ) ;
return 0 ;
V_467:
V_69 ( F_30 ( V_6 ) , V_6 ) ;
V_466:
V_69 ( F_28 ( V_6 ) , V_6 ) ;
V_465:
F_126 ( V_6 ) ;
return V_50 ;
}
static int F_272 ( struct V_150 * V_39 )
{
struct V_6 * V_6 = F_269 ( V_39 ) ;
F_273 ( V_39 ) ;
F_127 ( V_6 , false ) ;
F_274 ( & V_6 -> V_189 ) ;
F_274 ( & V_6 -> V_188 ) ;
F_261 ( V_6 , NULL ,
V_18 ) ;
V_69 ( F_30 ( V_6 ) , V_6 ) ;
V_69 ( F_28 ( V_6 ) , V_6 ) ;
F_126 ( V_6 ) ;
return 0 ;
}
static void F_275 ( const struct V_6 * V_6 ,
const struct V_82 * V_83 )
{
const struct V_30 * V_30 = V_6 -> V_30 ;
struct V_34 * V_35 = V_30 -> V_35 ;
const struct V_70 * V_151 [ V_469 + 1 ] ;
struct V_70 * V_226 ;
int V_81 ;
F_66 ( V_151 , V_469 , V_83 ) ;
if ( ! V_151 [ V_470 ] )
return;
F_276 (attr, attrs[ROCKER_TLV_TX_FRAGS], rem) {
const struct V_70 * V_471 [ V_472 + 1 ] ;
T_7 V_43 ;
T_3 V_74 ;
if ( F_55 ( V_226 ) != V_473 )
continue;
F_65 ( V_471 , V_472 ,
V_226 ) ;
if ( ! V_471 [ V_474 ] ||
! V_471 [ V_475 ] )
continue;
V_43 = F_62 ( V_471 [ V_474 ] ) ;
V_74 = F_59 ( V_471 [ V_475 ] ) ;
F_44 ( V_35 , V_43 , V_74 , V_476 ) ;
}
}
static int F_277 ( const struct V_6 * V_6 ,
struct V_82 * V_83 ,
char * V_44 , T_3 V_79 )
{
const struct V_30 * V_30 = V_6 -> V_30 ;
struct V_34 * V_35 = V_30 -> V_35 ;
T_7 V_43 ;
struct V_70 * V_477 ;
V_43 = F_41 ( V_35 , V_44 , V_79 , V_476 ) ;
if ( F_69 ( F_42 ( V_35 , V_43 ) ) ) {
if ( F_278 () )
F_124 ( V_6 -> V_39 , L_38 ) ;
return - V_40 ;
}
V_477 = F_76 ( V_83 , V_473 ) ;
if ( ! V_477 )
goto V_478;
if ( F_75 ( V_83 , V_474 ,
V_43 ) )
goto V_479;
if ( F_71 ( V_83 , V_475 ,
V_79 ) )
goto V_479;
F_77 ( V_83 , V_477 ) ;
return 0 ;
V_479:
F_78 ( V_83 , V_477 ) ;
V_478:
F_44 ( V_35 , V_43 , V_79 , V_476 ) ;
return - V_92 ;
}
static T_13 F_279 ( struct V_141 * V_142 , struct V_150 * V_39 )
{
struct V_6 * V_6 = F_269 ( V_39 ) ;
struct V_30 * V_30 = V_6 -> V_30 ;
struct V_82 * V_83 ;
struct V_70 * V_480 ;
int V_46 ;
int V_50 ;
V_83 = F_85 ( & V_6 -> V_155 ) ;
if ( F_69 ( ! V_83 ) ) {
if ( F_278 () )
F_124 ( V_39 , L_39 ) ;
return V_481 ;
}
F_84 ( V_83 , V_142 ) ;
V_480 = F_76 ( V_83 , V_470 ) ;
if ( ! V_480 )
goto V_196;
V_50 = F_277 ( V_6 , V_83 ,
V_142 -> V_84 , F_280 ( V_142 ) ) ;
if ( V_50 )
goto V_479;
if ( F_281 ( V_142 ) -> V_482 > V_483 ) {
V_50 = F_282 ( V_142 ) ;
if ( V_50 )
goto V_484;
}
for ( V_46 = 0 ; V_46 < F_281 ( V_142 ) -> V_482 ; V_46 ++ ) {
const T_14 * V_477 = & F_281 ( V_142 ) -> V_480 [ V_46 ] ;
V_50 = F_277 ( V_6 , V_83 ,
F_283 ( V_477 ) ,
F_284 ( V_477 ) ) ;
if ( V_50 )
goto V_484;
}
F_77 ( V_83 , V_480 ) ;
F_81 ( V_83 ) ;
F_87 ( V_30 , & V_6 -> V_155 , V_83 ) ;
V_83 = F_85 ( & V_6 -> V_155 ) ;
if ( ! V_83 )
F_273 ( V_39 ) ;
return V_485 ;
V_484:
F_275 ( V_6 , V_83 ) ;
V_479:
F_78 ( V_83 , V_480 ) ;
V_196:
F_285 ( V_142 ) ;
V_39 -> V_486 . V_487 ++ ;
return V_485 ;
}
static int F_286 ( struct V_150 * V_39 , void * V_403 )
{
struct V_488 * V_175 = V_403 ;
struct V_6 * V_6 = F_269 ( V_39 ) ;
int V_50 ;
if ( ! F_287 ( V_175 -> V_489 ) )
return - V_490 ;
V_50 = F_163 ( V_6 , V_175 -> V_489 ) ;
if ( V_50 )
return V_50 ;
memcpy ( V_39 -> V_395 , V_175 -> V_489 , V_39 -> V_491 ) ;
return 0 ;
}
static int F_288 ( struct V_150 * V_39 , int V_492 )
{
struct V_6 * V_6 = F_269 ( V_39 ) ;
int V_493 = F_289 ( V_39 ) ;
int V_50 ;
#define F_290 68
#define F_291 9000
if ( V_492 < F_290 || V_492 > F_291 )
return - V_107 ;
if ( V_493 )
F_272 ( V_39 ) ;
F_133 ( V_39 , L_40 , V_39 -> V_146 , V_492 ) ;
V_39 -> V_146 = V_492 ;
V_50 = F_164 ( V_6 , V_492 ) ;
if ( V_50 )
return V_50 ;
if ( V_493 )
V_50 = F_268 ( V_39 ) ;
return V_50 ;
}
static int F_292 ( struct V_150 * V_39 ,
char * V_44 , T_3 V_74 )
{
struct V_6 * V_6 = F_269 ( V_39 ) ;
struct V_229 V_230 = { . V_44 = V_44 , . V_74 = V_74 } ;
int V_50 ;
V_50 = F_145 ( V_6 , NULL , 0 ,
F_148 , NULL ,
F_153 ,
& V_230 ) ;
return V_50 ? - V_110 : 0 ;
}
static int F_293 ( struct V_150 * V_39 ,
bool V_468 )
{
struct V_6 * V_6 = F_269 ( V_39 ) ;
if ( V_6 -> V_39 -> V_13 & V_494 )
F_127 ( V_6 , ! V_468 ) ;
V_6 -> V_39 -> V_468 = V_468 ;
return 0 ;
}
static void F_294 ( struct V_396 * V_22 )
{
struct V_6 * V_6 = F_269 ( V_22 -> V_39 ) ;
int V_13 = V_356 | V_18 ;
T_10 V_388 = * ( T_10 * ) V_22 -> V_495 ;
F_222 ( V_6 , NULL ,
V_13 , V_388 , V_22 -> V_401 ) ;
}
static int F_295 ( struct V_150 * V_39 ,
struct V_496 * V_226 )
{
const struct V_6 * V_6 = F_269 ( V_39 ) ;
const struct V_30 * V_30 = V_6 -> V_30 ;
switch ( V_226 -> V_497 ) {
case V_498 :
V_226 -> V_499 . V_500 . V_501 = sizeof( V_30 -> V_502 . V_497 ) ;
memcpy ( & V_226 -> V_499 . V_500 . V_497 , & V_30 -> V_502 . V_497 , V_226 -> V_499 . V_500 . V_501 ) ;
break;
case V_503 :
V_226 -> V_499 . V_237 = V_6 -> V_237 ;
break;
default:
return - V_110 ;
}
return 0 ;
}
static int F_296 ( struct V_6 * V_6 ,
struct V_11 * V_12 ,
unsigned long V_237 )
{
unsigned long V_504 ;
int V_50 = 0 ;
V_504 = V_6 -> V_237 ;
V_6 -> V_237 = V_237 ;
if ( ( V_504 ^ V_6 -> V_237 ) & V_238 )
V_50 = F_165 ( V_6 , V_12 ) ;
if ( F_12 ( V_12 ) )
V_6 -> V_237 = V_504 ;
return V_50 ;
}
static int F_297 ( struct V_6 * V_6 ,
struct V_11 * V_12 ,
T_5 V_431 )
{
if ( ! F_12 ( V_12 ) ) {
V_6 -> V_431 = F_298 ( V_431 ) ;
F_255 ( & V_6 -> V_30 -> V_432 , V_427 ) ;
}
return 0 ;
}
static int F_299 ( struct V_150 * V_39 ,
const struct V_496 * V_226 ,
struct V_11 * V_12 )
{
struct V_6 * V_6 = F_269 ( V_39 ) ;
int V_50 = 0 ;
switch ( V_226 -> V_497 ) {
case V_505 :
V_50 = F_259 ( V_6 , V_12 , 0 ,
V_226 -> V_499 . V_180 ) ;
break;
case V_503 :
V_50 = F_296 ( V_6 , V_12 ,
V_226 -> V_499 . V_237 ) ;
break;
case V_506 :
V_50 = F_297 ( V_6 , V_12 ,
V_226 -> V_499 . V_431 ) ;
break;
default:
V_50 = - V_110 ;
break;
}
return V_50 ;
}
static int F_300 ( struct V_6 * V_6 ,
struct V_11 * V_12 ,
T_2 V_7 , T_2 V_13 )
{
int V_50 ;
V_50 = F_241 ( V_6 , V_12 , 0 , V_7 ) ;
if ( V_50 )
return V_50 ;
V_50 = F_257 ( V_6 , V_12 , 0 , F_4 ( V_7 ) ) ;
if ( V_50 )
F_241 ( V_6 , V_12 ,
V_356 , V_7 ) ;
return V_50 ;
}
static int F_301 ( struct V_6 * V_6 ,
struct V_11 * V_12 ,
const struct V_507 * V_249 )
{
T_2 V_7 ;
int V_50 ;
for ( V_7 = V_249 -> V_508 ; V_7 <= V_249 -> V_509 ; V_7 ++ ) {
V_50 = F_300 ( V_6 , V_12 ,
V_7 , V_249 -> V_13 ) ;
if ( V_50 )
return V_50 ;
}
return 0 ;
}
static int F_302 ( struct V_6 * V_6 ,
struct V_11 * V_12 ,
const struct V_510 * V_425 )
{
T_1 V_1 = F_3 ( V_6 , V_425 -> V_7 , NULL ) ;
int V_13 = 0 ;
if ( ! F_6 ( V_6 ) )
return - V_107 ;
return F_139 ( V_6 , V_12 , V_425 -> V_175 , V_1 , V_13 ) ;
}
static int F_303 ( struct V_150 * V_39 ,
const struct V_511 * V_512 ,
struct V_11 * V_12 )
{
struct V_6 * V_6 = F_269 ( V_39 ) ;
const struct V_513 * V_514 ;
int V_50 = 0 ;
switch ( V_512 -> V_497 ) {
case V_515 :
V_50 = F_301 ( V_6 , V_12 ,
F_304 ( V_512 ) ) ;
break;
case V_516 :
V_514 = F_305 ( V_512 ) ;
V_50 = F_267 ( V_6 , V_12 ,
F_306 ( V_514 -> V_374 ) , V_514 -> V_454 ,
& V_514 -> V_456 , V_514 -> V_457 , 0 ) ;
break;
case V_517 :
V_50 = F_302 ( V_6 , V_12 ,
F_307 ( V_512 ) ) ;
break;
default:
V_50 = - V_110 ;
break;
}
return V_50 ;
}
static int F_308 ( struct V_6 * V_6 ,
T_2 V_7 , T_2 V_13 )
{
int V_50 ;
V_50 = F_257 ( V_6 , NULL ,
V_356 , F_4 ( V_7 ) ) ;
if ( V_50 )
return V_50 ;
return F_241 ( V_6 , NULL ,
V_356 , V_7 ) ;
}
static int F_309 ( struct V_6 * V_6 ,
const struct V_507 * V_249 )
{
T_2 V_7 ;
int V_50 ;
for ( V_7 = V_249 -> V_508 ; V_7 <= V_249 -> V_509 ; V_7 ++ ) {
V_50 = F_308 ( V_6 , V_7 , V_249 -> V_13 ) ;
if ( V_50 )
return V_50 ;
}
return 0 ;
}
static int F_310 ( struct V_6 * V_6 ,
struct V_11 * V_12 ,
const struct V_510 * V_425 )
{
T_1 V_1 = F_3 ( V_6 , V_425 -> V_7 , NULL ) ;
int V_13 = V_356 ;
if ( ! F_6 ( V_6 ) )
return - V_107 ;
return F_139 ( V_6 , V_12 , V_425 -> V_175 , V_1 , V_13 ) ;
}
static int F_311 ( struct V_150 * V_39 ,
const struct V_511 * V_512 )
{
struct V_6 * V_6 = F_269 ( V_39 ) ;
const struct V_513 * V_514 ;
int V_50 = 0 ;
switch ( V_512 -> V_497 ) {
case V_515 :
V_50 = F_309 ( V_6 ,
F_304 ( V_512 ) ) ;
break;
case V_516 :
V_514 = F_305 ( V_512 ) ;
V_50 = F_267 ( V_6 , NULL ,
F_306 ( V_514 -> V_374 ) , V_514 -> V_454 ,
& V_514 -> V_456 , V_514 -> V_457 ,
V_356 ) ;
break;
case V_517 :
V_50 = F_310 ( V_6 , NULL ,
F_307 ( V_512 ) ) ;
break;
default:
V_50 = - V_110 ;
break;
}
return V_50 ;
}
static int F_312 ( const struct V_6 * V_6 ,
struct V_510 * V_425 ,
T_15 * V_518 )
{
struct V_30 * V_30 = V_6 -> V_30 ;
struct V_339 * V_349 ;
struct V_345 * V_346 ;
unsigned long V_194 ;
int V_347 ;
int V_50 = 0 ;
F_146 ( & V_30 -> V_332 , V_194 ) ;
F_186 (rocker->fdb_tbl, bkt, tmp, found, entry) {
if ( V_349 -> V_242 . V_6 != V_6 )
continue;
F_152 ( V_425 -> V_175 , V_349 -> V_242 . V_175 ) ;
V_425 -> V_519 = V_520 ;
V_425 -> V_7 = F_5 ( V_6 ,
V_349 -> V_242 . V_1 ) ;
V_50 = V_518 ( & V_425 -> V_512 ) ;
if ( V_50 )
break;
}
F_147 ( & V_30 -> V_332 , V_194 ) ;
return V_50 ;
}
static int F_313 ( const struct V_6 * V_6 ,
struct V_507 * V_249 ,
T_15 * V_518 )
{
T_2 V_7 ;
int V_50 = 0 ;
for ( V_7 = 1 ; V_7 < V_413 ; V_7 ++ ) {
if ( ! F_233 ( V_7 , V_6 -> V_404 ) )
continue;
V_249 -> V_13 = 0 ;
if ( F_1 ( F_4 ( V_7 ) ) )
V_249 -> V_13 |= V_521 ;
V_249 -> V_508 = V_249 -> V_509 = V_7 ;
V_50 = V_518 ( & V_249 -> V_512 ) ;
if ( V_50 )
break;
}
return V_50 ;
}
static int F_314 ( struct V_150 * V_39 ,
struct V_511 * V_512 ,
T_15 * V_518 )
{
const struct V_6 * V_6 = F_269 ( V_39 ) ;
int V_50 = 0 ;
switch ( V_512 -> V_497 ) {
case V_517 :
V_50 = F_312 ( V_6 ,
F_307 ( V_512 ) , V_518 ) ;
break;
case V_515 :
V_50 = F_313 ( V_6 ,
F_304 ( V_512 ) , V_518 ) ;
break;
default:
V_50 = - V_110 ;
break;
}
return V_50 ;
}
static int F_315 ( struct V_150 * V_39 ,
struct V_203 * V_204 )
{
struct V_6 * V_6 = F_269 ( V_39 ) ;
return F_160 ( V_6 , V_204 ) ;
}
static int F_316 ( struct V_150 * V_39 ,
struct V_203 * V_204 )
{
struct V_6 * V_6 = F_269 ( V_39 ) ;
return F_162 ( V_6 , V_204 ) ;
}
static void F_317 ( struct V_150 * V_39 ,
struct V_522 * V_523 )
{
F_318 ( V_523 -> V_524 , V_67 , sizeof( V_523 -> V_524 ) ) ;
F_318 ( V_523 -> V_525 , V_526 , sizeof( V_523 -> V_525 ) ) ;
}
static void F_319 ( struct V_150 * V_527 , T_5 V_528 ,
T_9 * V_84 )
{
T_9 * V_403 = V_84 ;
int V_46 ;
switch ( V_528 ) {
case V_529 :
for ( V_46 = 0 ; V_46 < F_320 ( V_530 ) ; V_46 ++ ) {
memcpy ( V_403 , V_530 [ V_46 ] . V_232 , V_531 ) ;
V_403 += V_531 ;
}
break;
}
}
static int
F_321 ( const struct V_6 * V_6 ,
struct V_82 * V_83 ,
void * V_197 )
{
struct V_70 * V_532 ;
if ( F_71 ( V_83 , V_199 ,
V_533 ) )
return - V_92 ;
V_532 = F_76 ( V_83 , V_201 ) ;
if ( ! V_532 )
return - V_92 ;
if ( F_73 ( V_83 , V_534 ,
V_6 -> V_167 ) )
return - V_92 ;
F_77 ( V_83 , V_532 ) ;
return 0 ;
}
static int
F_322 ( const struct V_6 * V_6 ,
const struct V_82 * V_83 ,
void * V_197 )
{
const struct V_70 * V_151 [ V_205 + 1 ] ;
const struct V_70 * V_535 [ V_536 + 1 ] ;
const struct V_70 * V_537 ;
T_5 V_167 ;
T_6 * V_84 = V_197 ;
int V_46 ;
F_66 ( V_151 , V_205 , V_83 ) ;
if ( ! V_151 [ V_201 ] )
return - V_40 ;
F_65 ( V_535 , V_536 ,
V_151 [ V_201 ] ) ;
if ( ! V_535 [ V_534 ] )
return - V_40 ;
V_167 = F_61 ( V_535 [ V_534 ] ) ;
if ( V_167 != V_6 -> V_167 )
return - V_40 ;
for ( V_46 = 0 ; V_46 < F_320 ( V_530 ) ; V_46 ++ ) {
V_537 = V_535 [ V_530 [ V_46 ] . type ] ;
if ( ! V_537 )
continue;
V_84 [ V_46 ] = F_62 ( V_537 ) ;
}
return 0 ;
}
static int F_323 ( struct V_6 * V_6 ,
void * V_197 )
{
return F_145 ( V_6 , NULL , 0 ,
F_321 , NULL ,
F_322 ,
V_197 ) ;
}
static void F_324 ( struct V_150 * V_39 ,
struct V_538 * V_486 , T_6 * V_84 )
{
struct V_6 * V_6 = F_269 ( V_39 ) ;
if ( F_323 ( V_6 , V_84 ) != 0 ) {
int V_46 ;
for ( V_46 = 0 ; V_46 < F_320 ( V_530 ) ; ++ V_46 )
V_84 [ V_46 ] = 0 ;
}
}
static int F_325 ( struct V_150 * V_527 , int V_539 )
{
switch ( V_539 ) {
case V_529 :
return V_540 ;
default:
return - V_110 ;
}
}
static struct V_6 * F_326 ( struct V_541 * V_542 )
{
return F_245 ( V_542 , struct V_6 , V_188 ) ;
}
static int F_327 ( struct V_541 * V_542 , int V_543 )
{
struct V_6 * V_6 = F_326 ( V_542 ) ;
const struct V_30 * V_30 = V_6 -> V_30 ;
const struct V_82 * V_83 ;
T_5 V_120 = 0 ;
int V_50 ;
while ( ( V_83 = F_90 ( & V_6 -> V_155 ) ) ) {
struct V_141 * V_142 ;
V_50 = F_80 ( V_83 ) ;
if ( V_50 && F_278 () )
F_124 ( V_6 -> V_39 , L_41 ,
V_50 ) ;
F_275 ( V_6 , V_83 ) ;
V_142 = F_83 ( V_83 ) ;
if ( V_50 == 0 ) {
V_6 -> V_39 -> V_486 . V_544 ++ ;
V_6 -> V_39 -> V_486 . V_545 += V_142 -> V_74 ;
} else {
V_6 -> V_39 -> V_486 . V_546 ++ ;
}
F_117 ( V_142 ) ;
V_120 ++ ;
}
if ( V_120 && F_328 ( V_6 -> V_39 ) )
F_329 ( V_6 -> V_39 ) ;
F_330 ( V_542 ) ;
F_91 ( V_30 , & V_6 -> V_155 , V_120 ) ;
return 0 ;
}
static int F_331 ( const struct V_30 * V_30 ,
const struct V_6 * V_6 ,
struct V_82 * V_83 )
{
const struct V_70 * V_151 [ V_152 + 1 ] ;
struct V_141 * V_142 = F_83 ( V_83 ) ;
T_3 V_547 ;
T_2 V_548 = 0 ;
if ( ! V_142 )
return - V_100 ;
F_66 ( V_151 , V_152 , V_83 ) ;
if ( ! V_151 [ V_549 ] )
return - V_107 ;
if ( V_151 [ V_550 ] )
V_548 = F_59 ( V_151 [ V_550 ] ) ;
F_118 ( V_30 , V_151 ) ;
V_547 = F_59 ( V_151 [ V_549 ] ) ;
F_332 ( V_142 , V_547 ) ;
V_142 -> V_551 = F_333 ( V_142 , V_6 -> V_39 ) ;
if ( V_548 & V_552 )
V_142 -> V_553 = V_6 -> V_39 -> V_553 ;
V_6 -> V_39 -> V_486 . V_554 ++ ;
V_6 -> V_39 -> V_486 . V_555 += V_142 -> V_74 ;
F_334 ( V_142 ) ;
return F_115 ( V_6 , V_83 ) ;
}
static struct V_6 * F_335 ( struct V_541 * V_542 )
{
return F_245 ( V_542 , struct V_6 , V_189 ) ;
}
static int F_336 ( struct V_541 * V_542 , int V_543 )
{
struct V_6 * V_6 = F_335 ( V_542 ) ;
const struct V_30 * V_30 = V_6 -> V_30 ;
struct V_82 * V_83 ;
T_5 V_120 = 0 ;
int V_50 ;
while ( V_120 < V_543 &&
( V_83 = F_90 ( & V_6 -> V_153 ) ) ) {
V_50 = F_80 ( V_83 ) ;
if ( V_50 ) {
if ( F_278 () )
F_124 ( V_6 -> V_39 , L_42 ,
V_50 ) ;
} else {
V_50 = F_331 ( V_30 , V_6 ,
V_83 ) ;
if ( V_50 && F_278 () )
F_124 ( V_6 -> V_39 , L_43 ,
V_50 ) ;
}
if ( V_50 )
V_6 -> V_39 -> V_486 . V_556 ++ ;
F_81 ( V_83 ) ;
F_87 ( V_30 , & V_6 -> V_153 , V_83 ) ;
V_120 ++ ;
}
if ( V_120 < V_543 )
F_330 ( V_542 ) ;
F_91 ( V_30 , & V_6 -> V_153 , V_120 ) ;
return V_120 ;
}
static void F_337 ( const struct V_6 * V_6 )
{
const struct V_30 * V_30 = V_6 -> V_30 ;
T_6 V_557 = F_38 ( V_30 , V_558 ) ;
bool V_169 ;
V_169 = V_557 & ( 1 << V_6 -> V_167 ) ;
if ( V_169 )
F_132 ( V_6 -> V_39 ) ;
else
F_135 ( V_6 -> V_39 ) ;
}
static void F_338 ( const struct V_30 * V_30 )
{
struct V_6 * V_6 ;
int V_46 ;
for ( V_46 = 0 ; V_46 < V_30 -> V_172 ; V_46 ++ ) {
V_6 = V_30 -> V_173 [ V_46 ] ;
if ( ! V_6 )
continue;
F_243 ( V_6 , NULL , V_356 ) ;
F_339 ( V_6 -> V_39 ) ;
F_340 ( V_6 -> V_39 ) ;
}
V_21 ( V_30 -> V_173 ) ;
}
static void F_341 ( struct V_6 * V_6 )
{
const struct V_30 * V_30 = V_6 -> V_30 ;
const struct V_34 * V_35 = V_30 -> V_35 ;
int V_50 ;
V_50 = F_161 ( V_6 ,
V_6 -> V_39 -> V_395 ) ;
if ( V_50 ) {
F_342 ( & V_35 -> V_39 , L_44 ) ;
F_343 ( V_6 -> V_39 ) ;
}
}
static int F_344 ( struct V_30 * V_30 , unsigned int V_33 )
{
const struct V_34 * V_35 = V_30 -> V_35 ;
struct V_6 * V_6 ;
struct V_150 * V_39 ;
T_2 V_559 = 0 ;
int V_50 ;
V_39 = F_345 ( sizeof( struct V_6 ) ) ;
if ( ! V_39 )
return - V_53 ;
V_6 = F_269 ( V_39 ) ;
V_6 -> V_39 = V_39 ;
V_6 -> V_30 = V_30 ;
V_6 -> V_33 = V_33 ;
V_6 -> V_167 = V_33 + 1 ;
V_6 -> V_237 = V_238 | V_423 ;
V_6 -> V_431 = V_560 ;
F_341 ( V_6 ) ;
V_39 -> V_561 = & V_562 ;
V_39 -> V_563 = & V_564 ;
V_39 -> V_565 = & V_566 ;
F_346 ( V_39 , & V_6 -> V_188 , F_327 ,
V_567 ) ;
F_346 ( V_39 , & V_6 -> V_189 , F_336 ,
V_567 ) ;
F_337 ( V_6 ) ;
V_39 -> V_568 |= V_569 | V_570 ;
V_50 = F_347 ( V_39 ) ;
if ( V_50 ) {
F_36 ( & V_35 -> V_39 , L_45 ) ;
goto V_571;
}
V_30 -> V_173 [ V_33 ] = V_6 ;
F_348 ( V_6 -> V_39 , NULL , false ) ;
F_165 ( V_6 , NULL ) ;
V_50 = F_243 ( V_6 , NULL , 0 ) ;
if ( V_50 ) {
F_124 ( V_6 -> V_39 , L_46 ) ;
goto V_572;
}
V_6 -> V_9 =
F_263 ( V_6 , V_39 -> V_449 ) ;
V_50 = F_300 ( V_6 , NULL , V_559 , 0 ) ;
if ( V_50 ) {
F_124 ( V_6 -> V_39 , L_47 ) ;
goto V_573;
}
return 0 ;
V_573:
F_243 ( V_6 , NULL , V_356 ) ;
V_572:
V_30 -> V_173 [ V_33 ] = NULL ;
F_339 ( V_39 ) ;
V_571:
F_340 ( V_39 ) ;
return V_50 ;
}
static int F_349 ( struct V_30 * V_30 )
{
int V_46 ;
T_3 V_574 ;
int V_50 ;
V_574 = sizeof( struct V_6 * ) * V_30 -> V_172 ;
V_30 -> V_173 = F_11 ( V_574 , V_20 ) ;
if ( ! V_30 -> V_173 )
return - V_53 ;
for ( V_46 = 0 ; V_46 < V_30 -> V_172 ; V_46 ++ ) {
V_50 = F_344 ( V_30 , V_46 ) ;
if ( V_50 )
goto V_575;
}
return 0 ;
V_575:
F_338 ( V_30 ) ;
return V_50 ;
}
static int F_350 ( struct V_30 * V_30 )
{
struct V_34 * V_35 = V_30 -> V_35 ;
int V_32 ;
int V_46 ;
int V_50 ;
V_32 = F_351 ( V_35 ) ;
if ( V_32 < 0 )
return V_32 ;
if ( V_32 != F_352 ( V_30 -> V_172 ) )
return - V_107 ;
V_30 -> V_32 = F_353 ( V_32 ,
sizeof( struct V_576 ) ,
V_20 ) ;
if ( ! V_30 -> V_32 )
return - V_53 ;
for ( V_46 = 0 ; V_46 < V_32 ; V_46 ++ )
V_30 -> V_32 [ V_46 ] . V_240 = V_46 ;
V_50 = F_354 ( V_35 , V_30 -> V_32 , V_32 ) ;
if ( V_50 < 0 )
goto V_577;
return 0 ;
V_577:
V_21 ( V_30 -> V_32 ) ;
return V_50 ;
}
static void F_355 ( const struct V_30 * V_30 )
{
F_356 ( V_30 -> V_35 ) ;
V_21 ( V_30 -> V_32 ) ;
}
static int F_357 ( struct V_34 * V_35 , const struct V_578 * V_497 )
{
struct V_30 * V_30 ;
int V_50 ;
V_30 = F_11 ( sizeof( * V_30 ) , V_20 ) ;
if ( ! V_30 )
return - V_53 ;
V_50 = F_358 ( V_35 ) ;
if ( V_50 ) {
F_36 ( & V_35 -> V_39 , L_48 ) ;
goto V_579;
}
V_50 = F_359 ( V_35 , V_67 ) ;
if ( V_50 ) {
F_36 ( & V_35 -> V_39 , L_49 ) ;
goto V_580;
}
V_50 = F_360 ( V_35 , F_361 ( 64 ) ) ;
if ( ! V_50 ) {
V_50 = F_362 ( V_35 , F_361 ( 64 ) ) ;
if ( V_50 ) {
F_36 ( & V_35 -> V_39 , L_50 ) ;
goto V_581;
}
} else {
V_50 = F_360 ( V_35 , F_361 ( 32 ) ) ;
if ( V_50 ) {
F_36 ( & V_35 -> V_39 , L_51 ) ;
goto V_581;
}
}
if ( F_363 ( V_35 , 0 ) < V_582 ) {
F_36 ( & V_35 -> V_39 , L_52 ) ;
V_50 = - V_107 ;
goto V_583;
}
V_30 -> V_584 = F_364 ( F_365 ( V_35 , 0 ) ,
F_363 ( V_35 , 0 ) ) ;
if ( ! V_30 -> V_584 ) {
F_36 ( & V_35 -> V_39 , L_53 ) ;
V_50 = - V_40 ;
goto V_585;
}
F_366 ( V_35 ) ;
V_30 -> V_35 = V_35 ;
F_367 ( V_35 , V_30 ) ;
V_30 -> V_172 = F_35 ( V_30 , V_586 ) ;
V_50 = F_350 ( V_30 ) ;
if ( V_50 ) {
F_36 ( & V_35 -> V_39 , L_54 ) ;
goto V_587;
}
V_50 = F_47 ( V_30 ) ;
if ( V_50 ) {
F_36 ( & V_35 -> V_39 , L_55 ) ;
goto V_588;
}
F_34 ( V_30 , V_589 , V_590 ) ;
V_50 = F_110 ( V_30 ) ;
if ( V_50 )
goto V_591;
V_50 = F_48 ( F_27 ( V_30 , V_592 ) ,
F_128 , 0 ,
V_67 , V_30 ) ;
if ( V_50 ) {
F_36 ( & V_35 -> V_39 , L_56 ) ;
goto V_593;
}
V_50 = F_48 ( F_27 ( V_30 , V_594 ) ,
F_141 , 0 ,
V_67 , V_30 ) ;
if ( V_50 ) {
F_36 ( & V_35 -> V_39 , L_57 ) ;
goto V_595;
}
V_30 -> V_502 . V_497 = F_38 ( V_30 , V_596 ) ;
V_50 = F_183 ( V_30 ) ;
if ( V_50 ) {
F_36 ( & V_35 -> V_39 , L_58 ) ;
goto V_597;
}
F_368 ( & V_30 -> V_432 , F_252 ,
( unsigned long ) V_30 ) ;
F_255 ( & V_30 -> V_432 , V_427 ) ;
V_50 = F_349 ( V_30 ) ;
if ( V_50 ) {
F_36 ( & V_35 -> V_39 , L_59 ) ;
goto V_598;
}
F_369 ( & V_35 -> V_39 , L_60 ,
( int ) sizeof( V_30 -> V_502 . V_497 ) , & V_30 -> V_502 . V_497 ) ;
return 0 ;
V_598:
F_370 ( & V_30 -> V_432 ) ;
F_185 ( V_30 ) ;
V_597:
V_69 ( F_27 ( V_30 , V_594 ) , V_30 ) ;
V_595:
V_69 ( F_27 ( V_30 , V_592 ) , V_30 ) ;
V_593:
F_112 ( V_30 ) ;
V_591:
V_588:
F_355 ( V_30 ) ;
V_587:
F_371 ( V_30 -> V_584 ) ;
V_585:
V_583:
V_581:
F_372 ( V_35 ) ;
V_580:
F_373 ( V_35 ) ;
V_579:
V_21 ( V_30 ) ;
return V_50 ;
}
static void F_374 ( struct V_34 * V_35 )
{
struct V_30 * V_30 = F_375 ( V_35 ) ;
F_370 ( & V_30 -> V_432 ) ;
F_185 ( V_30 ) ;
F_34 ( V_30 , V_589 , V_590 ) ;
F_338 ( V_30 ) ;
V_69 ( F_27 ( V_30 , V_594 ) , V_30 ) ;
V_69 ( F_27 ( V_30 , V_592 ) , V_30 ) ;
F_112 ( V_30 ) ;
F_355 ( V_30 ) ;
F_371 ( V_30 -> V_584 ) ;
F_372 ( V_30 -> V_35 ) ;
F_373 ( V_30 -> V_35 ) ;
V_21 ( V_30 ) ;
}
static bool F_376 ( const struct V_150 * V_39 )
{
return V_39 -> V_561 == & V_562 ;
}
static int F_377 ( struct V_6 * V_6 ,
struct V_150 * V_272 )
{
T_2 V_559 = 0 ;
int V_50 ;
V_50 = F_308 ( V_6 , V_559 , 0 ) ;
if ( V_50 )
return V_50 ;
F_265 ( V_6 ,
V_6 -> V_39 -> V_449 ) ;
V_6 -> V_9 =
F_263 ( V_6 , V_272 -> V_449 ) ;
V_6 -> V_10 = V_272 ;
F_348 ( V_6 -> V_39 , V_272 , true ) ;
return F_300 ( V_6 , NULL , V_559 , 0 ) ;
}
static int F_378 ( struct V_6 * V_6 )
{
T_2 V_559 = 0 ;
int V_50 ;
V_50 = F_308 ( V_6 , V_559 , 0 ) ;
if ( V_50 )
return V_50 ;
F_265 ( V_6 ,
V_6 -> V_10 -> V_449 ) ;
V_6 -> V_9 =
F_263 ( V_6 ,
V_6 -> V_39 -> V_449 ) ;
F_348 ( V_6 -> V_39 , V_6 -> V_10 ,
false ) ;
V_6 -> V_10 = NULL ;
V_50 = F_300 ( V_6 , NULL , V_559 , 0 ) ;
if ( V_50 )
return V_50 ;
if ( V_6 -> V_39 -> V_13 & V_494 )
V_50 = F_260 ( V_6 , NULL , 0 ) ;
return V_50 ;
}
static int F_379 ( struct V_6 * V_6 ,
struct V_150 * V_599 )
{
int V_50 ;
V_6 -> V_10 = V_599 ;
V_50 = F_261 ( V_6 , NULL , 0 ) ;
if ( V_50 )
return V_50 ;
V_50 = F_260 ( V_6 , NULL , 0 ) ;
return V_50 ;
}
static int F_380 ( struct V_6 * V_6 ,
struct V_150 * V_599 )
{
int V_50 = 0 ;
if ( F_7 ( V_599 ) )
V_50 = F_377 ( V_6 , V_599 ) ;
else if ( F_9 ( V_599 ) )
V_50 = F_379 ( V_6 , V_599 ) ;
return V_50 ;
}
static int F_381 ( struct V_6 * V_6 )
{
int V_50 = 0 ;
if ( F_6 ( V_6 ) )
V_50 = F_378 ( V_6 ) ;
else if ( F_8 ( V_6 ) )
V_50 = F_379 ( V_6 , NULL ) ;
return V_50 ;
}
static int F_382 ( struct V_600 * V_601 ,
unsigned long V_602 , void * V_115 )
{
struct V_150 * V_39 = F_383 ( V_115 ) ;
struct V_603 * V_117 ;
struct V_6 * V_6 ;
int V_50 ;
if ( ! F_376 ( V_39 ) )
return V_604 ;
switch ( V_602 ) {
case V_605 :
V_117 = V_115 ;
if ( ! V_117 -> V_599 )
goto V_196;
V_6 = F_269 ( V_39 ) ;
if ( V_117 -> V_606 ) {
V_50 = F_380 ( V_6 ,
V_117 -> V_607 ) ;
if ( V_50 )
F_384 ( V_39 , L_61 ,
V_50 ) ;
} else {
V_50 = F_381 ( V_6 ) ;
if ( V_50 )
F_384 ( V_39 , L_62 ,
V_50 ) ;
}
break;
}
V_196:
return V_604 ;
}
static int F_385 ( struct V_150 * V_39 , struct V_396 * V_22 )
{
struct V_6 * V_6 = F_269 ( V_39 ) ;
int V_13 = ( V_22 -> V_399 & V_400 ? 0 : V_356 ) |
V_18 ;
T_10 V_388 = * ( T_10 * ) V_22 -> V_495 ;
return F_222 ( V_6 , NULL , V_13 , V_388 , V_22 -> V_401 ) ;
}
static int F_386 ( struct V_600 * V_601 ,
unsigned long V_602 , void * V_115 )
{
struct V_150 * V_39 ;
struct V_396 * V_22 = V_115 ;
int V_50 ;
switch ( V_602 ) {
case V_608 :
if ( V_22 -> V_609 != & V_398 )
return V_604 ;
V_39 = V_22 -> V_39 ;
if ( ! F_376 ( V_39 ) )
return V_604 ;
V_50 = F_385 ( V_39 , V_22 ) ;
if ( V_50 )
F_384 ( V_39 ,
L_63 ,
V_50 ) ;
break;
}
return V_604 ;
}
static int T_16 F_387 ( void )
{
int V_50 ;
F_388 ( & V_610 ) ;
F_389 ( & V_611 ) ;
V_50 = F_390 ( & V_612 ) ;
if ( V_50 )
goto V_613;
return 0 ;
V_613:
F_391 ( & V_611 ) ;
F_392 ( & V_610 ) ;
return V_50 ;
}
static void T_17 F_393 ( void )
{
F_391 ( & V_611 ) ;
F_392 ( & V_610 ) ;
F_394 ( & V_612 ) ;
}
