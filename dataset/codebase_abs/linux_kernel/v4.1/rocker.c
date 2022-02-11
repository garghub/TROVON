static bool F_1 ( T_1 V_1 )
{
T_2 V_2 = V_3 ;
T_2 V_4 = 0xffe ;
T_2 V_5 = F_2 ( V_1 ) ;
return ( V_5 >= V_2 && V_5 <= V_4 ) ;
}
static T_1 F_3 ( struct V_6 * V_6 ,
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
static T_2 F_5 ( struct V_6 * V_6 ,
T_1 V_1 )
{
if ( F_1 ( V_1 ) )
return 0 ;
return F_2 ( V_1 ) ;
}
static bool F_6 ( struct V_6 * V_6 )
{
return ! ! V_6 -> V_10 ;
}
static void F_7 ( struct V_11 * V_12 )
{
V_12 -> V_13 = false ;
V_12 -> V_14 = false ;
}
static void F_8 ( struct V_11 * V_12 )
{
F_9 ( & V_12 -> V_12 ) ;
F_7 ( V_12 ) ;
}
static struct V_11 * F_10 ( T_3 V_15 )
{
struct V_11 * V_12 ;
V_12 = F_11 ( sizeof( * V_12 ) , V_15 ) ;
if ( ! V_12 )
return NULL ;
F_8 ( V_12 ) ;
return V_12 ;
}
static void F_12 ( struct V_11 * V_16 )
{
F_13 ( V_16 ) ;
}
static bool F_14 ( struct V_11 * V_12 ,
unsigned long V_17 )
{
F_15 ( V_12 -> V_12 , V_12 -> V_13 , V_18 / 10 ) ;
if ( ! V_12 -> V_13 )
return false ;
return true ;
}
static void F_16 ( struct V_11 * V_12 )
{
V_12 -> V_13 = true ;
F_17 ( & V_12 -> V_12 ) ;
}
static T_4 F_18 ( struct V_19 * V_19 , unsigned int V_20 )
{
return V_19 -> V_21 [ V_20 ] . V_20 ;
}
static T_4 F_19 ( struct V_6 * V_6 )
{
return F_18 ( V_6 -> V_19 ,
F_20 ( V_6 -> V_22 ) ) ;
}
static T_4 F_21 ( struct V_6 * V_6 )
{
return F_18 ( V_6 -> V_19 ,
F_22 ( V_6 -> V_22 ) ) ;
}
static int F_23 ( struct V_19 * V_19 )
{
struct V_23 * V_24 = V_19 -> V_24 ;
T_5 V_25 ;
T_5 V_26 ;
V_26 = F_24 () ;
V_26 >>= 1 ;
F_25 ( V_19 , V_27 , V_26 ) ;
V_25 = F_26 ( V_19 , V_27 ) ;
if ( V_25 != V_26 * 2 ) {
F_27 ( & V_24 -> V_28 , L_1 ,
V_25 , V_26 * 2 ) ;
return - V_29 ;
}
V_26 = F_24 () ;
V_26 <<= 31 ;
V_26 |= F_24 () ;
F_28 ( V_19 , V_30 , V_26 ) ;
V_25 = F_29 ( V_19 , V_30 ) ;
if ( V_25 != V_26 * 2 ) {
F_27 ( & V_24 -> V_28 , L_2 ,
V_25 , V_26 * 2 ) ;
return - V_29 ;
}
return 0 ;
}
static int F_30 ( struct V_19 * V_19 , struct V_11 * V_12 ,
T_4 V_31 , T_6 V_32 ,
unsigned char * V_33 , unsigned char * V_34 ,
T_7 V_35 )
{
struct V_23 * V_24 = V_19 -> V_24 ;
int V_36 ;
F_7 ( V_12 ) ;
F_25 ( V_19 , V_37 , V_31 ) ;
if ( ! F_14 ( V_12 , V_18 / 10 ) ) {
F_27 ( & V_24 -> V_28 , L_3 ) ;
return - V_29 ;
}
for ( V_36 = 0 ; V_36 < V_35 ; V_36 ++ ) {
if ( V_33 [ V_36 ] != V_34 [ V_36 ] ) {
F_27 ( & V_24 -> V_28 , L_4 ,
V_33 [ V_36 ] , V_36 , V_34 [ V_36 ] ) ;
return - V_29 ;
}
}
return 0 ;
}
static int F_31 ( struct V_19 * V_19 ,
struct V_11 * V_12 , int V_38 )
{
struct V_23 * V_24 = V_19 -> V_24 ;
unsigned char * V_39 ;
unsigned char * V_33 ;
unsigned char * V_34 ;
T_6 V_32 ;
int V_36 ;
int V_40 ;
V_39 = F_32 ( V_41 * 2 + V_38 ,
V_42 | V_43 ) ;
if ( ! V_39 )
return - V_44 ;
V_33 = V_39 + V_38 ;
V_34 = V_33 + V_41 ;
V_32 = F_33 ( V_24 , V_33 , V_41 ,
V_45 ) ;
if ( F_34 ( V_24 , V_32 ) ) {
V_40 = - V_29 ;
goto V_46;
}
F_28 ( V_19 , V_47 , V_32 ) ;
F_25 ( V_19 , V_48 , V_41 ) ;
memset ( V_34 , V_49 , V_41 ) ;
V_40 = F_30 ( V_19 , V_12 , V_50 ,
V_32 , V_33 , V_34 ,
V_41 ) ;
if ( V_40 )
goto V_51;
memset ( V_34 , 0 , V_41 ) ;
V_40 = F_30 ( V_19 , V_12 , V_52 ,
V_32 , V_33 , V_34 ,
V_41 ) ;
if ( V_40 )
goto V_51;
F_35 ( V_33 , V_41 ) ;
for ( V_36 = 0 ; V_36 < V_41 ; V_36 ++ )
V_34 [ V_36 ] = ~ V_33 [ V_36 ] ;
V_40 = F_30 ( V_19 , V_12 , V_53 ,
V_32 , V_33 , V_34 ,
V_41 ) ;
if ( V_40 )
goto V_51;
V_51:
F_36 ( V_24 , V_32 , V_41 ,
V_45 ) ;
V_46:
F_13 ( V_39 ) ;
return V_40 ;
}
static int F_37 ( struct V_19 * V_19 , struct V_11 * V_12 )
{
int V_36 ;
int V_40 ;
for ( V_36 = 0 ; V_36 < 8 ; V_36 ++ ) {
V_40 = F_31 ( V_19 , V_12 , V_36 ) ;
if ( V_40 )
return V_40 ;
}
return 0 ;
}
static T_8 F_38 ( int V_54 , void * V_55 )
{
struct V_11 * V_12 = V_55 ;
F_16 ( V_12 ) ;
return V_56 ;
}
static int F_39 ( struct V_19 * V_19 )
{
struct V_23 * V_24 = V_19 -> V_24 ;
struct V_11 V_12 ;
int V_40 ;
V_40 = F_23 ( V_19 ) ;
if ( V_40 ) {
F_27 ( & V_24 -> V_28 , L_5 ) ;
return V_40 ;
}
V_40 = F_40 ( F_18 ( V_19 , V_57 ) ,
F_38 , 0 ,
V_58 , & V_12 ) ;
if ( V_40 ) {
F_27 ( & V_24 -> V_28 , L_6 ) ;
return V_40 ;
}
F_8 ( & V_12 ) ;
F_25 ( V_19 , V_59 , V_57 ) ;
if ( ! F_14 ( & V_12 , V_18 / 10 ) ) {
F_27 ( & V_24 -> V_28 , L_3 ) ;
V_40 = - V_29 ;
goto V_60;
}
V_40 = F_37 ( V_19 , & V_12 ) ;
if ( V_40 )
F_27 ( & V_24 -> V_28 , L_7 ) ;
V_60:
V_60 ( F_18 ( V_19 , V_57 ) , & V_12 ) ;
return V_40 ;
}
static struct V_61 * F_41 ( const struct V_61 * V_62 ,
int * V_63 )
{
int V_64 = F_42 ( V_62 -> V_65 ) ;
* V_63 -= V_64 ;
return (struct V_61 * ) ( ( char * ) V_62 + V_64 ) ;
}
static int F_43 ( const struct V_61 * V_62 , int V_63 )
{
return V_63 >= ( int ) V_66 &&
V_62 -> V_65 >= V_66 &&
V_62 -> V_65 <= V_63 ;
}
static int F_44 ( int V_67 )
{
return V_66 + V_67 ;
}
static int F_45 ( int V_67 )
{
return F_42 ( F_44 ( V_67 ) ) ;
}
static int F_46 ( int V_67 )
{
return F_45 ( V_67 ) - F_44 ( V_67 ) ;
}
static int F_47 ( const struct V_61 * V_62 )
{
return V_62 -> type ;
}
static void * F_48 ( const struct V_61 * V_62 )
{
return ( char * ) V_62 + V_66 ;
}
static int F_49 ( const struct V_61 * V_62 )
{
return V_62 -> V_65 - V_66 ;
}
static T_9 F_50 ( const struct V_61 * V_62 )
{
return * ( T_9 * ) F_48 ( V_62 ) ;
}
static T_2 F_51 ( const struct V_61 * V_62 )
{
return * ( T_2 * ) F_48 ( V_62 ) ;
}
static T_1 F_52 ( const struct V_61 * V_62 )
{
return * ( T_1 * ) F_48 ( V_62 ) ;
}
static T_4 F_53 ( const struct V_61 * V_62 )
{
return * ( T_4 * ) F_48 ( V_62 ) ;
}
static T_5 F_54 ( const struct V_61 * V_62 )
{
return * ( T_5 * ) F_48 ( V_62 ) ;
}
static void F_55 ( struct V_61 * * V_68 , int V_69 ,
const char * V_33 , int V_70 )
{
const struct V_61 * V_62 ;
const struct V_61 * V_71 = ( const struct V_61 * ) V_33 ;
int V_72 ;
memset ( V_68 , 0 , sizeof( struct V_61 * ) * ( V_69 + 1 ) ) ;
F_56 (tlv, head, buf_len, rem) {
T_4 type = F_47 ( V_62 ) ;
if ( type > 0 && type <= V_69 )
V_68 [ type ] = (struct V_61 * ) V_62 ;
}
}
static void F_57 ( struct V_61 * * V_68 , int V_69 ,
const struct V_61 * V_62 )
{
F_55 ( V_68 , V_69 , F_48 ( V_62 ) ,
F_49 ( V_62 ) ) ;
}
static void F_58 ( struct V_61 * * V_68 , int V_69 ,
struct V_73 * V_74 )
{
F_55 ( V_68 , V_69 , V_74 -> V_75 ,
V_74 -> V_76 -> V_77 ) ;
}
static struct V_61 * F_59 ( struct V_73 * V_74 )
{
return (struct V_61 * ) ( ( char * ) V_74 -> V_75 +
V_74 -> V_77 ) ;
}
static int F_60 ( struct V_73 * V_74 ,
int V_78 , int V_79 , const void * V_75 )
{
int V_80 = V_74 -> V_81 - V_74 -> V_77 ;
int V_82 = F_45 ( V_79 ) ;
struct V_61 * V_62 ;
if ( F_61 ( V_80 < V_82 ) )
return - V_83 ;
V_62 = F_59 ( V_74 ) ;
V_74 -> V_77 += V_82 ;
V_62 -> type = V_78 ;
V_62 -> V_65 = F_44 ( V_79 ) ;
memcpy ( F_48 ( V_62 ) , V_75 , V_79 ) ;
memset ( ( char * ) V_62 + V_62 -> V_65 , 0 , F_46 ( V_79 ) ) ;
return 0 ;
}
static int F_62 ( struct V_73 * V_74 ,
int V_78 , T_9 V_84 )
{
return F_60 ( V_74 , V_78 , sizeof( T_9 ) , & V_84 ) ;
}
static int F_63 ( struct V_73 * V_74 ,
int V_78 , T_2 V_84 )
{
return F_60 ( V_74 , V_78 , sizeof( T_2 ) , & V_84 ) ;
}
static int F_64 ( struct V_73 * V_74 ,
int V_78 , T_1 V_84 )
{
return F_60 ( V_74 , V_78 , sizeof( T_1 ) , & V_84 ) ;
}
static int F_65 ( struct V_73 * V_74 ,
int V_78 , T_4 V_84 )
{
return F_60 ( V_74 , V_78 , sizeof( T_4 ) , & V_84 ) ;
}
static int F_66 ( struct V_73 * V_74 ,
int V_78 , T_10 V_84 )
{
return F_60 ( V_74 , V_78 , sizeof( T_10 ) , & V_84 ) ;
}
static int F_67 ( struct V_73 * V_74 ,
int V_78 , T_5 V_84 )
{
return F_60 ( V_74 , V_78 , sizeof( T_5 ) , & V_84 ) ;
}
static struct V_61 *
F_68 ( struct V_73 * V_74 , int V_78 )
{
struct V_61 * V_2 = F_59 ( V_74 ) ;
if ( F_60 ( V_74 , V_78 , 0 , NULL ) < 0 )
return NULL ;
return V_2 ;
}
static void F_69 ( struct V_73 * V_74 ,
struct V_61 * V_2 )
{
V_2 -> V_65 = ( char * ) F_59 ( V_74 ) - ( char * ) V_2 ;
}
static void F_70 ( struct V_73 * V_74 ,
struct V_61 * V_2 )
{
V_74 -> V_77 = ( char * ) V_2 - V_74 -> V_75 ;
}
static T_4 F_71 ( T_4 V_85 , T_7 V_86 )
{
return ++ V_85 == V_86 ? 0 : V_85 ;
}
static int F_72 ( struct V_73 * V_74 )
{
int V_40 = V_74 -> V_76 -> V_87 & ~ V_88 ;
switch ( V_40 ) {
case V_89 :
return 0 ;
case - V_90 :
return - V_91 ;
case - V_92 :
return - V_93 ;
case - V_94 :
return - V_44 ;
case - V_95 :
return - V_96 ;
case - V_97 :
return - V_98 ;
case - V_99 :
return - V_83 ;
case - V_100 :
return - V_101 ;
case - V_102 :
return - V_103 ;
}
return - V_98 ;
}
static void F_73 ( struct V_73 * V_74 )
{
V_74 -> V_76 -> V_87 &= ~ V_88 ;
}
static bool F_74 ( struct V_73 * V_74 )
{
T_4 V_87 = V_74 -> V_76 -> V_87 ;
return V_87 & V_88 ? true : false ;
}
static void * F_75 ( struct V_73 * V_74 )
{
return ( void * ) ( V_104 ) V_74 -> V_76 -> V_105 ;
}
static void F_76 ( struct V_73 * V_74 ,
void * V_106 )
{
V_74 -> V_76 -> V_105 = ( V_104 ) V_106 ;
}
static struct V_73 *
F_77 ( struct V_107 * V_108 )
{
static struct V_73 * V_74 ;
T_4 V_71 = F_71 ( V_108 -> V_71 , V_108 -> V_35 ) ;
V_74 = & V_108 -> V_74 [ V_108 -> V_71 ] ;
if ( V_71 == V_108 -> V_109 )
return NULL ;
V_74 -> V_77 = 0 ;
return V_74 ;
}
static void F_78 ( struct V_73 * V_74 )
{
V_74 -> V_76 -> V_110 = V_74 -> V_81 ;
V_74 -> V_76 -> V_77 = V_74 -> V_77 ;
}
static void F_79 ( struct V_19 * V_19 ,
struct V_107 * V_108 ,
struct V_73 * V_74 )
{
T_4 V_71 = F_71 ( V_108 -> V_71 , V_108 -> V_35 ) ;
F_80 ( V_71 == V_108 -> V_109 ) ;
F_78 ( V_74 ) ;
V_108 -> V_71 = V_71 ;
F_25 ( V_19 , F_81 ( V_108 -> type ) , V_71 ) ;
}
static struct V_73 *
F_82 ( struct V_107 * V_108 )
{
static struct V_73 * V_74 ;
if ( V_108 -> V_109 == V_108 -> V_71 )
return NULL ;
V_74 = & V_108 -> V_74 [ V_108 -> V_109 ] ;
if ( ! F_74 ( V_74 ) )
return NULL ;
V_108 -> V_109 = F_71 ( V_108 -> V_109 , V_108 -> V_35 ) ;
V_74 -> V_77 = V_74 -> V_76 -> V_77 ;
return V_74 ;
}
static void F_83 ( struct V_19 * V_19 ,
struct V_107 * V_108 ,
T_4 V_111 )
{
if ( V_111 )
F_25 ( V_19 , F_84 ( V_108 -> type ) , V_111 ) ;
}
static unsigned long F_85 ( T_7 V_35 )
{
return F_86 ( V_112 ,
F_87 ( F_88 ( V_35 ) , V_113 ) ) ;
}
static int F_89 ( struct V_19 * V_19 ,
unsigned int type ,
T_7 V_35 ,
struct V_107 * V_108 )
{
int V_36 ;
F_80 ( V_35 != F_85 ( V_35 ) ) ;
V_108 -> V_35 = V_35 ;
V_108 -> type = type ;
V_108 -> V_71 = 0 ;
V_108 -> V_109 = 0 ;
V_108 -> V_74 = F_90 ( V_108 -> V_35 , sizeof( * V_108 -> V_74 ) ,
V_42 ) ;
if ( ! V_108 -> V_74 )
return - V_44 ;
V_108 -> V_76 = F_91 ( V_19 -> V_24 ,
V_108 -> V_35 * sizeof( * V_108 -> V_76 ) ,
& V_108 -> V_114 ) ;
if ( ! V_108 -> V_76 ) {
F_13 ( V_108 -> V_74 ) ;
return - V_44 ;
}
for ( V_36 = 0 ; V_36 < V_108 -> V_35 ; V_36 ++ )
V_108 -> V_74 [ V_36 ] . V_76 = & V_108 -> V_76 [ V_36 ] ;
F_25 ( V_19 , F_92 ( V_108 -> type ) ,
V_115 ) ;
F_28 ( V_19 , F_93 ( V_108 -> type ) , V_108 -> V_114 ) ;
F_25 ( V_19 , F_94 ( V_108 -> type ) , V_108 -> V_35 ) ;
return 0 ;
}
static void F_95 ( struct V_19 * V_19 ,
struct V_107 * V_108 )
{
F_28 ( V_19 , F_93 ( V_108 -> type ) , 0 ) ;
F_96 ( V_19 -> V_24 ,
V_108 -> V_35 * sizeof( struct V_116 ) ,
V_108 -> V_76 , V_108 -> V_114 ) ;
F_13 ( V_108 -> V_74 ) ;
}
static void F_97 ( struct V_19 * V_19 ,
struct V_107 * V_108 )
{
int V_36 ;
F_80 ( V_108 -> V_71 || V_108 -> V_109 ) ;
for ( V_36 = 0 ; V_36 < V_108 -> V_35 - 1 ; V_36 ++ )
F_79 ( V_19 , V_108 , & V_108 -> V_74 [ V_36 ] ) ;
F_78 ( & V_108 -> V_74 [ V_36 ] ) ;
}
static int F_98 ( struct V_19 * V_19 ,
struct V_107 * V_108 ,
int V_117 , T_7 V_110 )
{
struct V_23 * V_24 = V_19 -> V_24 ;
int V_36 ;
int V_40 ;
for ( V_36 = 0 ; V_36 < V_108 -> V_35 ; V_36 ++ ) {
struct V_73 * V_74 = & V_108 -> V_74 [ V_36 ] ;
struct V_116 * V_76 = & V_108 -> V_76 [ V_36 ] ;
T_6 V_32 ;
char * V_33 ;
V_33 = F_32 ( V_110 , V_42 | V_43 ) ;
if ( ! V_33 ) {
V_40 = - V_44 ;
goto V_118;
}
V_32 = F_33 ( V_24 , V_33 , V_110 , V_117 ) ;
if ( F_34 ( V_24 , V_32 ) ) {
F_13 ( V_33 ) ;
V_40 = - V_29 ;
goto V_118;
}
V_74 -> V_75 = V_33 ;
V_74 -> V_81 = V_110 ;
F_99 ( V_74 , V_114 , V_32 ) ;
V_76 -> V_119 = V_32 ;
V_76 -> V_110 = V_110 ;
}
return 0 ;
V_118:
for ( V_36 -- ; V_36 >= 0 ; V_36 -- ) {
struct V_73 * V_74 = & V_108 -> V_74 [ V_36 ] ;
F_36 ( V_24 , F_100 ( V_74 , V_114 ) ,
V_74 -> V_81 , V_117 ) ;
F_13 ( V_74 -> V_75 ) ;
}
return V_40 ;
}
static void F_101 ( struct V_19 * V_19 ,
struct V_107 * V_108 ,
int V_117 )
{
struct V_23 * V_24 = V_19 -> V_24 ;
int V_36 ;
for ( V_36 = 0 ; V_36 < V_108 -> V_35 ; V_36 ++ ) {
struct V_73 * V_74 = & V_108 -> V_74 [ V_36 ] ;
struct V_116 * V_76 = & V_108 -> V_76 [ V_36 ] ;
V_76 -> V_119 = 0 ;
V_76 -> V_110 = 0 ;
F_36 ( V_24 , F_100 ( V_74 , V_114 ) ,
V_74 -> V_81 , V_117 ) ;
F_13 ( V_74 -> V_75 ) ;
}
}
static int F_102 ( struct V_19 * V_19 )
{
struct V_23 * V_24 = V_19 -> V_24 ;
int V_40 ;
V_40 = F_89 ( V_19 , V_120 ,
V_121 ,
& V_19 -> V_122 ) ;
if ( V_40 ) {
F_27 ( & V_24 -> V_28 , L_8 ) ;
return V_40 ;
}
F_103 ( & V_19 -> V_123 ) ;
V_40 = F_98 ( V_19 , & V_19 -> V_122 ,
V_45 , V_124 ) ;
if ( V_40 ) {
F_27 ( & V_24 -> V_28 , L_9 ) ;
goto V_125;
}
V_40 = F_89 ( V_19 , V_126 ,
V_127 ,
& V_19 -> V_128 ) ;
if ( V_40 ) {
F_27 ( & V_24 -> V_28 , L_10 ) ;
goto V_129;
}
V_40 = F_98 ( V_19 , & V_19 -> V_128 ,
V_130 , V_124 ) ;
if ( V_40 ) {
F_27 ( & V_24 -> V_28 , L_11 ) ;
goto V_131;
}
F_97 ( V_19 , & V_19 -> V_128 ) ;
return 0 ;
V_131:
F_95 ( V_19 , & V_19 -> V_128 ) ;
V_129:
F_101 ( V_19 , & V_19 -> V_122 ,
V_45 ) ;
V_125:
F_95 ( V_19 , & V_19 -> V_122 ) ;
return V_40 ;
}
static void F_104 ( struct V_19 * V_19 )
{
F_101 ( V_19 , & V_19 -> V_128 ,
V_45 ) ;
F_95 ( V_19 , & V_19 -> V_128 ) ;
F_101 ( V_19 , & V_19 -> V_122 ,
V_45 ) ;
F_95 ( V_19 , & V_19 -> V_122 ) ;
}
static int F_105 ( struct V_19 * V_19 ,
struct V_6 * V_6 ,
struct V_73 * V_74 ,
struct V_132 * V_133 , T_7 V_70 )
{
struct V_23 * V_24 = V_19 -> V_24 ;
T_6 V_32 ;
V_32 = F_33 ( V_24 , V_133 -> V_75 , V_70 ,
V_130 ) ;
if ( F_34 ( V_24 , V_32 ) )
return - V_29 ;
if ( F_67 ( V_74 , V_134 , V_32 ) )
goto V_135;
if ( F_63 ( V_74 , V_136 , V_70 ) )
goto V_135;
return 0 ;
V_135:
F_36 ( V_24 , V_32 , V_70 , V_130 ) ;
V_74 -> V_77 = 0 ;
return - V_83 ;
}
static T_7 F_106 ( struct V_6 * V_6 )
{
return V_6 -> V_28 -> V_137 + V_138 + V_139 + V_140 ;
}
static int F_107 ( struct V_19 * V_19 ,
struct V_6 * V_6 ,
struct V_73 * V_74 )
{
struct V_141 * V_28 = V_6 -> V_28 ;
struct V_132 * V_133 ;
T_7 V_70 = F_106 ( V_6 ) ;
int V_40 ;
F_76 ( V_74 , NULL ) ;
V_74 -> V_77 = 0 ;
V_133 = F_108 ( V_28 , V_70 ) ;
if ( ! V_133 )
return - V_44 ;
V_40 = F_105 ( V_19 , V_6 , V_74 ,
V_133 , V_70 ) ;
if ( V_40 ) {
F_109 ( V_133 ) ;
return V_40 ;
}
F_76 ( V_74 , V_133 ) ;
return 0 ;
}
static void F_110 ( struct V_19 * V_19 ,
struct V_61 * * V_142 )
{
struct V_23 * V_24 = V_19 -> V_24 ;
T_6 V_32 ;
T_7 V_65 ;
if ( ! V_142 [ V_134 ] ||
! V_142 [ V_136 ] )
return;
V_32 = F_54 ( V_142 [ V_134 ] ) ;
V_65 = F_51 ( V_142 [ V_136 ] ) ;
F_36 ( V_24 , V_32 , V_65 , V_130 ) ;
}
static void F_111 ( struct V_19 * V_19 ,
struct V_73 * V_74 )
{
struct V_61 * V_142 [ V_143 + 1 ] ;
struct V_132 * V_133 = F_75 ( V_74 ) ;
if ( ! V_133 )
return;
F_58 ( V_142 , V_143 , V_74 ) ;
F_110 ( V_19 , V_142 ) ;
F_109 ( V_133 ) ;
}
static int F_112 ( struct V_19 * V_19 ,
struct V_6 * V_6 )
{
struct V_107 * V_144 = & V_6 -> V_144 ;
int V_36 ;
int V_40 ;
for ( V_36 = 0 ; V_36 < V_144 -> V_35 ; V_36 ++ ) {
V_40 = F_107 ( V_19 , V_6 ,
& V_144 -> V_74 [ V_36 ] ) ;
if ( V_40 )
goto V_118;
}
return 0 ;
V_118:
for ( V_36 -- ; V_36 >= 0 ; V_36 -- )
F_111 ( V_19 , & V_144 -> V_74 [ V_36 ] ) ;
return V_40 ;
}
static void F_113 ( struct V_19 * V_19 ,
struct V_6 * V_6 )
{
struct V_107 * V_144 = & V_6 -> V_144 ;
int V_36 ;
for ( V_36 = 0 ; V_36 < V_144 -> V_35 ; V_36 ++ )
F_111 ( V_19 , & V_144 -> V_74 [ V_36 ] ) ;
}
static int F_114 ( struct V_6 * V_6 )
{
struct V_19 * V_19 = V_6 -> V_19 ;
int V_40 ;
V_40 = F_89 ( V_19 ,
F_115 ( V_6 -> V_22 ) ,
V_145 ,
& V_6 -> V_146 ) ;
if ( V_40 ) {
F_116 ( V_6 -> V_28 , L_12 ) ;
return V_40 ;
}
V_40 = F_98 ( V_19 , & V_6 -> V_146 ,
V_147 ,
V_148 ) ;
if ( V_40 ) {
F_116 ( V_6 -> V_28 , L_13 ) ;
goto V_149;
}
V_40 = F_89 ( V_19 ,
F_117 ( V_6 -> V_22 ) ,
V_150 ,
& V_6 -> V_144 ) ;
if ( V_40 ) {
F_116 ( V_6 -> V_28 , L_14 ) ;
goto V_151;
}
V_40 = F_98 ( V_19 , & V_6 -> V_144 ,
V_45 ,
V_152 ) ;
if ( V_40 ) {
F_116 ( V_6 -> V_28 , L_15 ) ;
goto V_153;
}
V_40 = F_112 ( V_19 , V_6 ) ;
if ( V_40 ) {
F_116 ( V_6 -> V_28 , L_16 ) ;
goto V_154;
}
F_97 ( V_19 , & V_6 -> V_144 ) ;
return 0 ;
V_154:
F_101 ( V_19 , & V_6 -> V_144 ,
V_45 ) ;
V_153:
F_95 ( V_19 , & V_6 -> V_144 ) ;
V_151:
F_101 ( V_19 , & V_6 -> V_146 ,
V_147 ) ;
V_149:
F_95 ( V_19 , & V_6 -> V_146 ) ;
return V_40 ;
}
static void F_118 ( struct V_6 * V_6 )
{
struct V_19 * V_19 = V_6 -> V_19 ;
F_113 ( V_19 , V_6 ) ;
F_101 ( V_19 , & V_6 -> V_144 ,
V_45 ) ;
F_95 ( V_19 , & V_6 -> V_144 ) ;
F_101 ( V_19 , & V_6 -> V_146 ,
V_147 ) ;
F_95 ( V_19 , & V_6 -> V_146 ) ;
}
static void F_119 ( struct V_6 * V_6 , bool V_155 )
{
T_5 V_156 = F_29 ( V_6 -> V_19 , V_157 ) ;
if ( V_155 )
V_156 |= 1ULL << V_6 -> V_158 ;
else
V_156 &= ~ ( 1ULL << V_6 -> V_158 ) ;
F_28 ( V_6 -> V_19 , V_157 , V_156 ) ;
}
static T_8 F_120 ( int V_54 , void * V_55 )
{
struct V_19 * V_19 = V_55 ;
struct V_73 * V_74 ;
struct V_11 * V_12 ;
T_4 V_111 = 0 ;
F_121 ( & V_19 -> V_123 ) ;
while ( ( V_74 = F_82 ( & V_19 -> V_122 ) ) ) {
V_12 = F_75 ( V_74 ) ;
if ( V_12 -> V_14 ) {
F_73 ( V_74 ) ;
F_12 ( V_12 ) ;
} else {
F_16 ( V_12 ) ;
}
V_111 ++ ;
}
F_122 ( & V_19 -> V_123 ) ;
F_83 ( V_19 , & V_19 -> V_122 , V_111 ) ;
return V_56 ;
}
static void F_123 ( struct V_6 * V_6 )
{
F_124 ( V_6 -> V_28 ) ;
F_125 ( V_6 -> V_28 , L_17 ) ;
}
static void F_126 ( struct V_6 * V_6 )
{
F_127 ( V_6 -> V_28 ) ;
F_125 ( V_6 -> V_28 , L_18 ) ;
}
static int F_128 ( struct V_19 * V_19 ,
const struct V_61 * V_108 )
{
struct V_61 * V_142 [ V_159 + 1 ] ;
unsigned int V_22 ;
bool V_160 ;
struct V_6 * V_6 ;
F_57 ( V_142 , V_159 , V_108 ) ;
if ( ! V_142 [ V_161 ] ||
! V_142 [ V_162 ] )
return - V_29 ;
V_22 =
F_53 ( V_142 [ V_161 ] ) - 1 ;
V_160 = F_50 ( V_142 [ V_162 ] ) ;
if ( V_22 >= V_19 -> V_163 )
return - V_98 ;
V_6 = V_19 -> V_164 [ V_22 ] ;
if ( F_129 ( V_6 -> V_28 ) != V_160 ) {
if ( V_160 )
F_123 ( V_6 ) ;
else
F_126 ( V_6 ) ;
}
return 0 ;
}
static int F_130 ( struct V_19 * V_19 ,
const struct V_61 * V_108 )
{
struct V_61 * V_142 [ V_165 + 1 ] ;
unsigned int V_22 ;
struct V_6 * V_6 ;
unsigned char * V_166 ;
int V_167 = V_168 | V_169 ;
T_1 V_1 ;
F_57 ( V_142 , V_165 , V_108 ) ;
if ( ! V_142 [ V_170 ] ||
! V_142 [ V_171 ] ||
! V_142 [ V_172 ] )
return - V_29 ;
V_22 =
F_53 ( V_142 [ V_170 ] ) - 1 ;
V_166 = F_48 ( V_142 [ V_171 ] ) ;
V_1 = F_52 ( V_142 [ V_172 ] ) ;
if ( V_22 >= V_19 -> V_163 )
return - V_98 ;
V_6 = V_19 -> V_164 [ V_22 ] ;
if ( V_6 -> V_173 != V_174 &&
V_6 -> V_173 != V_175 )
return 0 ;
return F_131 ( V_6 , V_166 , V_1 , V_167 ) ;
}
static int F_132 ( struct V_19 * V_19 ,
struct V_73 * V_74 )
{
struct V_61 * V_142 [ V_176 + 1 ] ;
struct V_61 * V_108 ;
T_2 type ;
F_58 ( V_142 , V_176 , V_74 ) ;
if ( ! V_142 [ V_177 ] ||
! V_142 [ V_178 ] )
return - V_29 ;
type = F_51 ( V_142 [ V_177 ] ) ;
V_108 = V_142 [ V_178 ] ;
switch ( type ) {
case V_179 :
return F_128 ( V_19 , V_108 ) ;
case V_180 :
return F_130 ( V_19 , V_108 ) ;
}
return - V_101 ;
}
static T_8 F_133 ( int V_54 , void * V_55 )
{
struct V_19 * V_19 = V_55 ;
struct V_23 * V_24 = V_19 -> V_24 ;
struct V_73 * V_74 ;
T_4 V_111 = 0 ;
int V_40 ;
while ( ( V_74 = F_82 ( & V_19 -> V_128 ) ) ) {
V_40 = F_72 ( V_74 ) ;
if ( V_40 ) {
F_27 ( & V_24 -> V_28 , L_19 ,
V_40 ) ;
} else {
V_40 = F_132 ( V_19 , V_74 ) ;
if ( V_40 )
F_27 ( & V_24 -> V_28 , L_20 ,
V_40 ) ;
}
F_73 ( V_74 ) ;
F_79 ( V_19 , & V_19 -> V_128 , V_74 ) ;
V_111 ++ ;
}
F_83 ( V_19 , & V_19 -> V_128 , V_111 ) ;
return V_56 ;
}
static T_8 F_134 ( int V_54 , void * V_55 )
{
struct V_6 * V_6 = V_55 ;
F_135 ( & V_6 -> V_181 ) ;
return V_56 ;
}
static T_8 F_136 ( int V_54 , void * V_55 )
{
struct V_6 * V_6 = V_55 ;
F_135 ( & V_6 -> V_182 ) ;
return V_56 ;
}
static int F_137 ( struct V_19 * V_19 ,
struct V_6 * V_6 ,
T_11 V_183 , void * V_184 ,
T_11 V_185 , void * V_186 ,
bool V_14 )
{
struct V_73 * V_74 ;
struct V_11 * V_12 ;
unsigned long V_167 ;
int V_40 ;
V_12 = F_10 ( V_14 ? V_187 : V_42 ) ;
if ( ! V_12 )
return - V_44 ;
V_12 -> V_14 = V_14 ;
F_138 ( & V_19 -> V_123 , V_167 ) ;
V_74 = F_77 ( & V_19 -> V_122 ) ;
if ( ! V_74 ) {
F_139 ( & V_19 -> V_123 , V_167 ) ;
V_40 = - V_188 ;
goto V_189;
}
V_40 = V_183 ( V_19 , V_6 , V_74 , V_184 ) ;
if ( V_40 ) {
F_139 ( & V_19 -> V_123 , V_167 ) ;
goto V_189;
}
F_76 ( V_74 , V_12 ) ;
F_79 ( V_19 , & V_19 -> V_122 , V_74 ) ;
F_139 ( & V_19 -> V_123 , V_167 ) ;
if ( V_14 )
return 0 ;
if ( ! F_14 ( V_12 , V_18 / 10 ) )
return - V_29 ;
V_40 = F_72 ( V_74 ) ;
if ( V_40 )
return V_40 ;
if ( V_185 )
V_40 = V_185 ( V_19 , V_6 , V_74 , V_186 ) ;
F_73 ( V_74 ) ;
V_189:
F_12 ( V_12 ) ;
return V_40 ;
}
static int
F_140 ( struct V_19 * V_19 ,
struct V_6 * V_6 ,
struct V_73 * V_74 ,
void * V_190 )
{
struct V_61 * V_191 ;
if ( F_63 ( V_74 , V_192 ,
V_193 ) )
return - V_83 ;
V_191 = F_68 ( V_74 , V_194 ) ;
if ( ! V_191 )
return - V_83 ;
if ( F_65 ( V_74 , V_195 ,
V_6 -> V_158 ) )
return - V_83 ;
F_69 ( V_74 , V_191 ) ;
return 0 ;
}
static int
F_141 ( struct V_19 * V_19 ,
struct V_6 * V_6 ,
struct V_73 * V_74 ,
void * V_190 )
{
struct V_196 * V_197 = V_190 ;
struct V_61 * V_142 [ V_198 + 1 ] ;
struct V_61 * V_199 [ V_200 + 1 ] ;
T_4 V_201 ;
T_9 V_202 ;
T_9 V_203 ;
F_58 ( V_142 , V_198 , V_74 ) ;
if ( ! V_142 [ V_194 ] )
return - V_29 ;
F_57 ( V_199 , V_200 ,
V_142 [ V_194 ] ) ;
if ( ! V_199 [ V_204 ] ||
! V_199 [ V_205 ] ||
! V_199 [ V_206 ] )
return - V_29 ;
V_201 = F_53 ( V_199 [ V_204 ] ) ;
V_202 = F_50 ( V_199 [ V_205 ] ) ;
V_203 = F_50 ( V_199 [ V_206 ] ) ;
V_197 -> V_207 = V_208 ;
V_197 -> V_209 = V_210 ;
V_197 -> V_211 = 0xff ;
V_197 -> V_212 = V_213 ;
F_142 ( V_197 , V_201 ) ;
V_197 -> V_202 = V_202 ? V_214 : V_215 ;
V_197 -> V_203 = V_203 ? V_216 : V_217 ;
return 0 ;
}
static int
F_143 ( struct V_19 * V_19 ,
struct V_6 * V_6 ,
struct V_73 * V_74 ,
void * V_190 )
{
unsigned char * V_218 = V_190 ;
struct V_61 * V_142 [ V_198 + 1 ] ;
struct V_61 * V_199 [ V_200 + 1 ] ;
struct V_61 * V_219 ;
F_58 ( V_142 , V_198 , V_74 ) ;
if ( ! V_142 [ V_194 ] )
return - V_29 ;
F_57 ( V_199 , V_200 ,
V_142 [ V_194 ] ) ;
V_219 = V_199 [ V_220 ] ;
if ( ! V_219 )
return - V_29 ;
if ( F_49 ( V_219 ) != V_221 )
return - V_98 ;
F_144 ( V_218 , F_48 ( V_219 ) ) ;
return 0 ;
}
static int
F_145 ( struct V_19 * V_19 ,
struct V_6 * V_6 ,
struct V_73 * V_74 ,
void * V_190 )
{
struct V_61 * V_199 [ V_200 + 1 ] ;
struct V_61 * V_142 [ V_198 + 1 ] ;
struct V_222 * V_223 = V_190 ;
struct V_61 * V_219 ;
T_7 V_36 , V_224 , V_65 ;
char * V_225 ;
F_58 ( V_142 , V_198 , V_74 ) ;
if ( ! V_142 [ V_194 ] )
return - V_29 ;
F_57 ( V_199 , V_200 ,
V_142 [ V_194 ] ) ;
V_219 = V_199 [ V_226 ] ;
if ( ! V_219 )
return - V_29 ;
V_65 = F_146 ( T_7 , F_49 ( V_219 ) , V_223 -> V_65 ) ;
V_225 = F_48 ( V_219 ) ;
for ( V_36 = V_224 = 0 ; V_36 < V_65 ; ++ V_36 ) {
if ( isalnum ( V_225 [ V_36 ] ) ) {
V_223 -> V_33 [ V_224 ] = V_225 [ V_36 ] ;
V_224 ++ ;
}
}
if ( V_224 == 0 )
return - V_29 ;
V_223 -> V_33 [ V_224 ] = '\0' ;
return 0 ;
}
static int
F_147 ( struct V_19 * V_19 ,
struct V_6 * V_6 ,
struct V_73 * V_74 ,
void * V_190 )
{
struct V_196 * V_197 = V_190 ;
struct V_61 * V_191 ;
if ( F_63 ( V_74 , V_192 ,
V_227 ) )
return - V_83 ;
V_191 = F_68 ( V_74 , V_194 ) ;
if ( ! V_191 )
return - V_83 ;
if ( F_65 ( V_74 , V_195 ,
V_6 -> V_158 ) )
return - V_83 ;
if ( F_65 ( V_74 , V_204 ,
F_148 ( V_197 ) ) )
return - V_83 ;
if ( F_62 ( V_74 , V_205 ,
V_197 -> V_202 ) )
return - V_83 ;
if ( F_62 ( V_74 , V_206 ,
V_197 -> V_203 ) )
return - V_83 ;
F_69 ( V_74 , V_191 ) ;
return 0 ;
}
static int
F_149 ( struct V_19 * V_19 ,
struct V_6 * V_6 ,
struct V_73 * V_74 ,
void * V_190 )
{
unsigned char * V_218 = V_190 ;
struct V_61 * V_191 ;
if ( F_63 ( V_74 , V_192 ,
V_227 ) )
return - V_83 ;
V_191 = F_68 ( V_74 , V_194 ) ;
if ( ! V_191 )
return - V_83 ;
if ( F_65 ( V_74 , V_195 ,
V_6 -> V_158 ) )
return - V_83 ;
if ( F_60 ( V_74 , V_220 ,
V_221 , V_218 ) )
return - V_83 ;
F_69 ( V_74 , V_191 ) ;
return 0 ;
}
static int
F_150 ( struct V_19 * V_19 ,
struct V_6 * V_6 ,
struct V_73 * V_74 ,
void * V_190 )
{
struct V_61 * V_191 ;
if ( F_63 ( V_74 , V_192 ,
V_227 ) )
return - V_83 ;
V_191 = F_68 ( V_74 , V_194 ) ;
if ( ! V_191 )
return - V_83 ;
if ( F_65 ( V_74 , V_195 ,
V_6 -> V_158 ) )
return - V_83 ;
if ( F_62 ( V_74 , V_228 ,
! ! ( V_6 -> V_229 & V_230 ) ) )
return - V_83 ;
F_69 ( V_74 , V_191 ) ;
return 0 ;
}
static int F_151 ( struct V_6 * V_6 ,
struct V_196 * V_197 )
{
return F_137 ( V_6 -> V_19 , V_6 ,
F_140 , NULL ,
F_141 ,
V_197 , false ) ;
}
static int F_152 ( struct V_6 * V_6 ,
unsigned char * V_218 )
{
return F_137 ( V_6 -> V_19 , V_6 ,
F_140 , NULL ,
F_143 ,
V_218 , false ) ;
}
static int F_153 ( struct V_6 * V_6 ,
struct V_196 * V_197 )
{
return F_137 ( V_6 -> V_19 , V_6 ,
F_147 ,
V_197 , NULL , NULL , false ) ;
}
static int F_154 ( struct V_6 * V_6 ,
unsigned char * V_218 )
{
return F_137 ( V_6 -> V_19 , V_6 ,
F_149 ,
V_218 , NULL , NULL , false ) ;
}
static int F_155 ( struct V_6 * V_6 )
{
return F_137 ( V_6 -> V_19 , V_6 ,
F_150 ,
NULL , NULL , NULL , false ) ;
}
static int F_156 ( struct V_73 * V_74 ,
struct V_231 * V_232 )
{
if ( F_65 ( V_74 , V_233 ,
V_232 -> V_234 . V_235 . V_236 ) )
return - V_83 ;
if ( F_65 ( V_74 , V_237 ,
V_232 -> V_234 . V_235 . V_238 ) )
return - V_83 ;
if ( F_63 ( V_74 , V_239 ,
V_232 -> V_234 . V_235 . V_240 ) )
return - V_83 ;
return 0 ;
}
static int F_157 ( struct V_73 * V_74 ,
struct V_231 * V_232 )
{
if ( F_65 ( V_74 , V_233 ,
V_232 -> V_234 . V_241 . V_236 ) )
return - V_83 ;
if ( F_64 ( V_74 , V_242 ,
V_232 -> V_234 . V_241 . V_1 ) )
return - V_83 ;
if ( F_64 ( V_74 , V_243 ,
V_232 -> V_234 . V_241 . V_244 ) )
return - V_83 ;
if ( F_63 ( V_74 , V_239 ,
V_232 -> V_234 . V_241 . V_240 ) )
return - V_83 ;
if ( V_232 -> V_234 . V_241 . V_245 &&
F_64 ( V_74 , V_246 ,
V_232 -> V_234 . V_241 . V_247 ) )
return - V_83 ;
return 0 ;
}
static int F_158 ( struct V_73 * V_74 ,
struct V_231 * V_232 )
{
if ( F_65 ( V_74 , V_233 ,
V_232 -> V_234 . V_248 . V_236 ) )
return - V_83 ;
if ( F_65 ( V_74 , V_237 ,
V_232 -> V_234 . V_248 . V_238 ) )
return - V_83 ;
if ( F_64 ( V_74 , V_249 ,
V_232 -> V_234 . V_248 . V_250 ) )
return - V_83 ;
if ( F_60 ( V_74 , V_251 ,
V_221 , V_232 -> V_234 . V_248 . V_252 ) )
return - V_83 ;
if ( F_60 ( V_74 , V_253 ,
V_221 , V_232 -> V_234 . V_248 . V_254 ) )
return - V_83 ;
if ( F_64 ( V_74 , V_242 ,
V_232 -> V_234 . V_248 . V_1 ) )
return - V_83 ;
if ( F_64 ( V_74 , V_243 ,
V_232 -> V_234 . V_248 . V_244 ) )
return - V_83 ;
if ( F_63 ( V_74 , V_239 ,
V_232 -> V_234 . V_248 . V_240 ) )
return - V_83 ;
if ( V_232 -> V_234 . V_248 . V_255 &&
F_62 ( V_74 , V_256 ,
V_232 -> V_234 . V_248 . V_255 ) )
return - V_83 ;
return 0 ;
}
static int
F_159 ( struct V_73 * V_74 ,
struct V_231 * V_232 )
{
if ( F_64 ( V_74 , V_249 ,
V_232 -> V_234 . V_257 . V_250 ) )
return - V_83 ;
if ( F_66 ( V_74 , V_258 ,
V_232 -> V_234 . V_257 . V_259 ) )
return - V_83 ;
if ( F_66 ( V_74 , V_260 ,
V_232 -> V_234 . V_257 . V_261 ) )
return - V_83 ;
if ( F_63 ( V_74 , V_239 ,
V_232 -> V_234 . V_257 . V_240 ) )
return - V_83 ;
if ( F_65 ( V_74 , V_262 ,
V_232 -> V_234 . V_257 . V_263 ) )
return - V_83 ;
return 0 ;
}
static int F_160 ( struct V_73 * V_74 ,
struct V_231 * V_232 )
{
if ( V_232 -> V_234 . V_264 . V_265 &&
F_60 ( V_74 , V_251 ,
V_221 , V_232 -> V_234 . V_264 . V_252 ) )
return - V_83 ;
if ( V_232 -> V_234 . V_264 . V_266 &&
F_60 ( V_74 , V_253 ,
V_221 , V_232 -> V_234 . V_264 . V_254 ) )
return - V_83 ;
if ( V_232 -> V_234 . V_264 . V_1 &&
F_64 ( V_74 , V_242 ,
V_232 -> V_234 . V_264 . V_1 ) )
return - V_83 ;
if ( V_232 -> V_234 . V_264 . V_267 &&
F_65 ( V_74 , V_268 ,
V_232 -> V_234 . V_264 . V_267 ) )
return - V_83 ;
if ( F_63 ( V_74 , V_239 ,
V_232 -> V_234 . V_264 . V_240 ) )
return - V_83 ;
if ( F_65 ( V_74 , V_262 ,
V_232 -> V_234 . V_264 . V_263 ) )
return - V_83 ;
if ( V_232 -> V_234 . V_264 . V_255 &&
F_62 ( V_74 , V_256 ,
V_232 -> V_234 . V_264 . V_255 ) )
return - V_83 ;
return 0 ;
}
static int F_161 ( struct V_73 * V_74 ,
struct V_231 * V_232 )
{
if ( F_65 ( V_74 , V_233 ,
V_232 -> V_234 . V_269 . V_236 ) )
return - V_83 ;
if ( F_65 ( V_74 , V_237 ,
V_232 -> V_234 . V_269 . V_238 ) )
return - V_83 ;
if ( F_60 ( V_74 , V_270 ,
V_221 , V_232 -> V_234 . V_269 . V_271 ) )
return - V_83 ;
if ( F_60 ( V_74 , V_272 ,
V_221 , V_232 -> V_234 . V_269 . V_273 ) )
return - V_83 ;
if ( F_60 ( V_74 , V_251 ,
V_221 , V_232 -> V_234 . V_269 . V_252 ) )
return - V_83 ;
if ( F_60 ( V_74 , V_253 ,
V_221 , V_232 -> V_234 . V_269 . V_254 ) )
return - V_83 ;
if ( F_64 ( V_74 , V_249 ,
V_232 -> V_234 . V_269 . V_250 ) )
return - V_83 ;
if ( F_64 ( V_74 , V_242 ,
V_232 -> V_234 . V_269 . V_1 ) )
return - V_83 ;
if ( F_64 ( V_74 , V_243 ,
V_232 -> V_234 . V_269 . V_244 ) )
return - V_83 ;
switch ( F_2 ( V_232 -> V_234 . V_269 . V_250 ) ) {
case V_274 :
case V_275 :
if ( F_62 ( V_74 , V_276 ,
V_232 -> V_234 . V_269 . V_277 ) )
return - V_83 ;
if ( F_62 ( V_74 ,
V_278 ,
V_232 -> V_234 . V_269 . V_279 ) )
return - V_83 ;
if ( F_62 ( V_74 , V_280 ,
V_232 -> V_234 . V_269 . V_281 & 0x3f ) )
return - V_83 ;
if ( F_62 ( V_74 ,
V_282 ,
V_232 -> V_234 . V_269 . V_283 & 0x3f ) )
return - V_83 ;
if ( F_62 ( V_74 , V_284 ,
( V_232 -> V_234 . V_269 . V_281 & 0xc0 ) >> 6 ) )
return - V_83 ;
if ( F_62 ( V_74 ,
V_285 ,
( V_232 -> V_234 . V_269 . V_283 & 0xc0 ) >> 6 ) )
return - V_83 ;
break;
}
if ( V_232 -> V_234 . V_269 . V_263 != V_286 &&
F_65 ( V_74 , V_262 ,
V_232 -> V_234 . V_269 . V_263 ) )
return - V_83 ;
return 0 ;
}
static int F_162 ( struct V_19 * V_19 ,
struct V_6 * V_6 ,
struct V_73 * V_74 ,
void * V_190 )
{
struct V_231 * V_232 = V_190 ;
struct V_61 * V_191 ;
int V_40 = 0 ;
if ( F_63 ( V_74 , V_192 , V_232 -> V_287 ) )
return - V_83 ;
V_191 = F_68 ( V_74 , V_194 ) ;
if ( ! V_191 )
return - V_83 ;
if ( F_63 ( V_74 , V_288 ,
V_232 -> V_234 . V_289 ) )
return - V_83 ;
if ( F_65 ( V_74 , V_290 ,
V_232 -> V_234 . V_291 ) )
return - V_83 ;
if ( F_65 ( V_74 , V_292 , 0 ) )
return - V_83 ;
if ( F_67 ( V_74 , V_293 ,
V_232 -> V_105 ) )
return - V_83 ;
switch ( V_232 -> V_234 . V_289 ) {
case V_294 :
V_40 = F_156 ( V_74 , V_232 ) ;
break;
case V_295 :
V_40 = F_157 ( V_74 , V_232 ) ;
break;
case V_296 :
V_40 = F_158 ( V_74 , V_232 ) ;
break;
case V_297 :
V_40 = F_159 ( V_74 , V_232 ) ;
break;
case V_298 :
V_40 = F_160 ( V_74 , V_232 ) ;
break;
case V_299 :
V_40 = F_161 ( V_74 , V_232 ) ;
break;
default:
V_40 = - V_300 ;
break;
}
if ( V_40 )
return V_40 ;
F_69 ( V_74 , V_191 ) ;
return 0 ;
}
static int F_163 ( struct V_19 * V_19 ,
struct V_6 * V_6 ,
struct V_73 * V_74 ,
void * V_190 )
{
const struct V_231 * V_232 = V_190 ;
struct V_61 * V_191 ;
if ( F_63 ( V_74 , V_192 , V_232 -> V_287 ) )
return - V_83 ;
V_191 = F_68 ( V_74 , V_194 ) ;
if ( ! V_191 )
return - V_83 ;
if ( F_67 ( V_74 , V_293 ,
V_232 -> V_105 ) )
return - V_83 ;
F_69 ( V_74 , V_191 ) ;
return 0 ;
}
static int
F_164 ( struct V_73 * V_74 ,
struct V_301 * V_232 )
{
if ( F_65 ( V_74 , V_302 ,
F_165 ( V_232 -> V_263 ) ) )
return - V_83 ;
if ( F_62 ( V_74 , V_303 ,
V_232 -> V_304 . V_8 ) )
return - V_83 ;
return 0 ;
}
static int
F_166 ( struct V_73 * V_74 ,
struct V_301 * V_232 )
{
if ( F_65 ( V_74 , V_305 ,
V_232 -> V_306 . V_263 ) )
return - V_83 ;
if ( ! F_167 ( V_232 -> V_306 . V_271 ) &&
F_60 ( V_74 , V_270 ,
V_221 , V_232 -> V_306 . V_271 ) )
return - V_83 ;
if ( ! F_167 ( V_232 -> V_306 . V_252 ) &&
F_60 ( V_74 , V_251 ,
V_221 , V_232 -> V_306 . V_252 ) )
return - V_83 ;
if ( V_232 -> V_306 . V_1 &&
F_64 ( V_74 , V_242 ,
V_232 -> V_306 . V_1 ) )
return - V_83 ;
return 0 ;
}
static int
F_168 ( struct V_73 * V_74 ,
struct V_301 * V_232 )
{
int V_36 ;
struct V_61 * V_307 ;
if ( F_63 ( V_74 , V_308 ,
V_232 -> V_309 ) )
return - V_83 ;
V_307 = F_68 ( V_74 ,
V_310 ) ;
if ( ! V_307 )
return - V_83 ;
for ( V_36 = 0 ; V_36 < V_232 -> V_309 ; V_36 ++ )
if ( F_65 ( V_74 , V_36 + 1 , V_232 -> V_307 [ V_36 ] ) )
return - V_83 ;
F_69 ( V_74 , V_307 ) ;
return 0 ;
}
static int
F_169 ( struct V_73 * V_74 ,
struct V_301 * V_232 )
{
if ( ! F_167 ( V_232 -> V_311 . V_271 ) &&
F_60 ( V_74 , V_270 ,
V_221 , V_232 -> V_311 . V_271 ) )
return - V_83 ;
if ( ! F_167 ( V_232 -> V_311 . V_252 ) &&
F_60 ( V_74 , V_251 ,
V_221 , V_232 -> V_311 . V_252 ) )
return - V_83 ;
if ( V_232 -> V_311 . V_1 &&
F_64 ( V_74 , V_242 ,
V_232 -> V_311 . V_1 ) )
return - V_83 ;
if ( F_62 ( V_74 , V_312 ,
V_232 -> V_311 . V_313 ) )
return - V_83 ;
if ( F_65 ( V_74 , V_305 ,
V_232 -> V_311 . V_263 ) )
return - V_83 ;
return 0 ;
}
static int F_170 ( struct V_19 * V_19 ,
struct V_6 * V_6 ,
struct V_73 * V_74 ,
void * V_190 )
{
struct V_301 * V_232 = V_190 ;
struct V_61 * V_191 ;
int V_40 = 0 ;
if ( F_63 ( V_74 , V_192 , V_232 -> V_287 ) )
return - V_83 ;
V_191 = F_68 ( V_74 , V_194 ) ;
if ( ! V_191 )
return - V_83 ;
if ( F_65 ( V_74 , V_262 ,
V_232 -> V_263 ) )
return - V_83 ;
switch ( F_171 ( V_232 -> V_263 ) ) {
case V_314 :
V_40 = F_164 ( V_74 , V_232 ) ;
break;
case V_315 :
V_40 = F_166 ( V_74 , V_232 ) ;
break;
case V_316 :
case V_317 :
V_40 = F_168 ( V_74 , V_232 ) ;
break;
case V_318 :
V_40 = F_169 ( V_74 , V_232 ) ;
break;
default:
V_40 = - V_300 ;
break;
}
if ( V_40 )
return V_40 ;
F_69 ( V_74 , V_191 ) ;
return 0 ;
}
static int F_172 ( struct V_19 * V_19 ,
struct V_6 * V_6 ,
struct V_73 * V_74 ,
void * V_190 )
{
const struct V_301 * V_232 = V_190 ;
struct V_61 * V_191 ;
if ( F_63 ( V_74 , V_192 , V_232 -> V_287 ) )
return - V_83 ;
V_191 = F_68 ( V_74 , V_194 ) ;
if ( ! V_191 )
return - V_83 ;
if ( F_65 ( V_74 , V_262 ,
V_232 -> V_263 ) )
return - V_83 ;
F_69 ( V_74 , V_191 ) ;
return 0 ;
}
static int F_173 ( struct V_19 * V_19 )
{
F_174 ( V_19 -> V_319 ) ;
F_103 ( & V_19 -> V_320 ) ;
F_174 ( V_19 -> V_321 ) ;
F_103 ( & V_19 -> V_322 ) ;
F_174 ( V_19 -> V_323 ) ;
F_103 ( & V_19 -> V_324 ) ;
F_174 ( V_19 -> V_325 ) ;
F_103 ( & V_19 -> V_326 ) ;
F_174 ( V_19 -> V_327 ) ;
F_103 ( & V_19 -> V_328 ) ;
return 0 ;
}
static void F_175 ( struct V_19 * V_19 )
{
unsigned long V_167 ;
struct V_231 * V_329 ;
struct V_301 * V_330 ;
struct V_331 * V_332 ;
struct V_333 * V_334 ;
struct V_335 * V_336 ;
struct V_337 * V_338 ;
int V_339 ;
F_138 ( & V_19 -> V_320 , V_167 ) ;
F_176 (rocker->flow_tbl, bkt, tmp, flow_entry, entry)
F_177 ( & V_329 -> V_232 ) ;
F_139 ( & V_19 -> V_320 , V_167 ) ;
F_138 ( & V_19 -> V_322 , V_167 ) ;
F_176 (rocker->group_tbl, bkt, tmp, group_entry, entry)
F_177 ( & V_330 -> V_232 ) ;
F_139 ( & V_19 -> V_322 , V_167 ) ;
F_138 ( & V_19 -> V_324 , V_167 ) ;
F_176 (rocker->fdb_tbl, bkt, tmp, fdb_entry, entry)
F_177 ( & V_332 -> V_232 ) ;
F_139 ( & V_19 -> V_324 , V_167 ) ;
F_138 ( & V_19 -> V_326 , V_167 ) ;
F_176 (rocker->internal_vlan_tbl, bkt,
tmp, internal_vlan_entry, entry)
F_177 ( & V_334 -> V_232 ) ;
F_139 ( & V_19 -> V_326 , V_167 ) ;
F_138 ( & V_19 -> V_328 , V_167 ) ;
F_176 (rocker->neigh_tbl, bkt, tmp, neigh_entry, entry)
F_177 ( & V_336 -> V_232 ) ;
F_139 ( & V_19 -> V_328 , V_167 ) ;
}
static struct V_231 *
F_178 ( struct V_19 * V_19 , struct V_231 * V_340 )
{
struct V_231 * V_341 ;
T_7 V_342 = V_340 -> V_342 ? V_340 -> V_342 : sizeof( V_341 -> V_234 ) ;
F_179 (rocker->flow_tbl, found,
entry, match->key_crc32) {
if ( memcmp ( & V_341 -> V_234 , & V_340 -> V_234 , V_342 ) == 0 )
return V_341 ;
}
return NULL ;
}
static int F_180 ( struct V_6 * V_6 ,
struct V_231 * V_340 ,
bool V_14 )
{
struct V_19 * V_19 = V_6 -> V_19 ;
struct V_231 * V_341 ;
T_7 V_342 = V_340 -> V_342 ? V_340 -> V_342 : sizeof( V_341 -> V_234 ) ;
unsigned long V_167 ;
V_340 -> V_343 = F_181 ( ~ 0 , & V_340 -> V_234 , V_342 ) ;
F_138 ( & V_19 -> V_320 , V_167 ) ;
V_341 = F_178 ( V_19 , V_340 ) ;
if ( V_341 ) {
V_340 -> V_105 = V_341 -> V_105 ;
F_177 ( & V_341 -> V_232 ) ;
F_13 ( V_341 ) ;
V_341 = V_340 ;
V_341 -> V_287 = V_344 ;
} else {
V_341 = V_340 ;
V_341 -> V_105 = V_19 -> V_345 ++ ;
V_341 -> V_287 = V_346 ;
}
F_182 ( V_19 -> V_319 , & V_341 -> V_232 , V_341 -> V_343 ) ;
F_139 ( & V_19 -> V_320 , V_167 ) ;
return F_137 ( V_19 , V_6 ,
F_162 ,
V_341 , NULL , NULL , V_14 ) ;
}
static int F_183 ( struct V_6 * V_6 ,
struct V_231 * V_340 ,
bool V_14 )
{
struct V_19 * V_19 = V_6 -> V_19 ;
struct V_231 * V_341 ;
T_7 V_342 = V_340 -> V_342 ? V_340 -> V_342 : sizeof( V_341 -> V_234 ) ;
unsigned long V_167 ;
int V_40 = 0 ;
V_340 -> V_343 = F_181 ( ~ 0 , & V_340 -> V_234 , V_342 ) ;
F_138 ( & V_19 -> V_320 , V_167 ) ;
V_341 = F_178 ( V_19 , V_340 ) ;
if ( V_341 ) {
F_177 ( & V_341 -> V_232 ) ;
V_341 -> V_287 = V_347 ;
}
F_139 ( & V_19 -> V_320 , V_167 ) ;
F_13 ( V_340 ) ;
if ( V_341 ) {
V_40 = F_137 ( V_19 , V_6 ,
F_163 ,
V_341 , NULL , NULL , V_14 ) ;
F_13 ( V_341 ) ;
}
return V_40 ;
}
static T_3 F_184 ( int V_167 )
{
return V_167 & V_168 ? V_187 : V_42 ;
}
static int F_185 ( struct V_6 * V_6 ,
int V_167 , struct V_231 * V_232 )
{
bool V_14 = V_167 & V_168 ;
if ( V_167 & V_348 )
return F_183 ( V_6 , V_232 , V_14 ) ;
else
return F_180 ( V_6 , V_232 , V_14 ) ;
}
static int F_186 ( struct V_6 * V_6 ,
int V_167 , T_4 V_236 , T_4 V_238 ,
enum V_349 V_240 )
{
struct V_231 * V_232 ;
V_232 = F_32 ( sizeof( * V_232 ) , F_184 ( V_167 ) ) ;
if ( ! V_232 )
return - V_44 ;
V_232 -> V_234 . V_291 = V_350 ;
V_232 -> V_234 . V_289 = V_294 ;
V_232 -> V_234 . V_235 . V_236 = V_236 ;
V_232 -> V_234 . V_235 . V_238 = V_238 ;
V_232 -> V_234 . V_235 . V_240 = V_240 ;
return F_185 ( V_6 , V_167 , V_232 ) ;
}
static int F_187 ( struct V_6 * V_6 ,
int V_167 , T_4 V_236 ,
T_1 V_1 , T_1 V_244 ,
enum V_349 V_240 ,
bool V_245 , T_1 V_247 )
{
struct V_231 * V_232 ;
V_232 = F_32 ( sizeof( * V_232 ) , F_184 ( V_167 ) ) ;
if ( ! V_232 )
return - V_44 ;
V_232 -> V_234 . V_291 = V_351 ;
V_232 -> V_234 . V_289 = V_295 ;
V_232 -> V_234 . V_241 . V_236 = V_236 ;
V_232 -> V_234 . V_241 . V_1 = V_1 ;
V_232 -> V_234 . V_241 . V_244 = V_244 ;
V_232 -> V_234 . V_241 . V_240 = V_240 ;
V_232 -> V_234 . V_241 . V_245 = V_245 ;
V_232 -> V_234 . V_241 . V_247 = V_247 ;
return F_185 ( V_6 , V_167 , V_232 ) ;
}
static int F_188 ( struct V_6 * V_6 ,
T_4 V_236 , T_4 V_238 ,
T_1 V_250 , const T_9 * V_252 ,
const T_9 * V_254 , T_1 V_1 ,
T_1 V_244 , bool V_255 ,
int V_167 )
{
struct V_231 * V_232 ;
V_232 = F_32 ( sizeof( * V_232 ) , F_184 ( V_167 ) ) ;
if ( ! V_232 )
return - V_44 ;
if ( F_189 ( V_252 ) ) {
V_232 -> V_234 . V_291 = V_352 ;
V_232 -> V_234 . V_248 . V_240 =
V_353 ;
} else {
V_232 -> V_234 . V_291 = V_354 ;
V_232 -> V_234 . V_248 . V_240 =
V_297 ;
}
V_232 -> V_234 . V_289 = V_296 ;
V_232 -> V_234 . V_248 . V_236 = V_236 ;
V_232 -> V_234 . V_248 . V_238 = V_238 ;
V_232 -> V_234 . V_248 . V_250 = V_250 ;
F_144 ( V_232 -> V_234 . V_248 . V_252 , V_252 ) ;
F_144 ( V_232 -> V_234 . V_248 . V_254 , V_254 ) ;
V_232 -> V_234 . V_248 . V_1 = V_1 ;
V_232 -> V_234 . V_248 . V_244 = V_244 ;
V_232 -> V_234 . V_248 . V_255 = V_255 ;
return F_185 ( V_6 , V_167 , V_232 ) ;
}
static int F_190 ( struct V_6 * V_6 ,
int V_167 ,
const T_9 * V_252 , const T_9 * V_254 ,
T_1 V_1 , T_4 V_267 ,
enum V_349 V_240 ,
T_4 V_263 , bool V_255 )
{
struct V_231 * V_232 ;
T_4 V_291 ;
bool V_355 = ! ! V_1 ;
bool V_356 = ! V_252 || ( V_252 && V_254 ) ;
bool V_357 = false ;
V_232 = F_32 ( sizeof( * V_232 ) , F_184 ( V_167 ) ) ;
if ( ! V_232 )
return - V_44 ;
V_232 -> V_234 . V_289 = V_298 ;
if ( V_252 ) {
V_232 -> V_234 . V_264 . V_265 = 1 ;
F_144 ( V_232 -> V_234 . V_264 . V_252 , V_252 ) ;
}
if ( V_254 ) {
V_232 -> V_234 . V_264 . V_266 = 1 ;
F_144 ( V_232 -> V_234 . V_264 . V_254 , V_254 ) ;
if ( memcmp ( V_254 , V_358 , V_221 ) )
V_357 = true ;
}
V_291 = V_359 ;
if ( V_355 && V_356 && V_357 )
V_291 = V_360 ;
else if ( V_355 && V_356 && ! V_357 )
V_291 = V_361 ;
else if ( V_355 && ! V_356 )
V_291 = V_362 ;
else if ( ! V_355 && V_356 && V_357 )
V_291 = V_363 ;
else if ( ! V_355 && V_356 && ! V_357 )
V_291 = V_364 ;
else if ( ! V_355 && ! V_356 )
V_291 = V_365 ;
V_232 -> V_234 . V_291 = V_291 ;
V_232 -> V_234 . V_264 . V_1 = V_1 ;
V_232 -> V_234 . V_264 . V_267 = V_267 ;
V_232 -> V_234 . V_264 . V_240 = V_240 ;
V_232 -> V_234 . V_264 . V_263 = V_263 ;
V_232 -> V_234 . V_264 . V_255 = V_255 ;
return F_185 ( V_6 , V_167 , V_232 ) ;
}
static int F_191 ( struct V_6 * V_6 ,
T_1 V_250 , T_10 V_366 ,
T_10 V_367 , T_4 V_291 ,
enum V_349 V_240 ,
T_4 V_263 , int V_167 )
{
struct V_231 * V_232 ;
V_232 = F_32 ( sizeof( * V_232 ) , F_184 ( V_167 ) ) ;
if ( ! V_232 )
return - V_44 ;
V_232 -> V_234 . V_289 = V_297 ;
V_232 -> V_234 . V_291 = V_291 ;
V_232 -> V_234 . V_257 . V_250 = V_250 ;
V_232 -> V_234 . V_257 . V_259 = V_366 ;
V_232 -> V_234 . V_257 . V_261 = V_367 ;
V_232 -> V_234 . V_257 . V_240 = V_240 ;
V_232 -> V_234 . V_257 . V_263 = V_263 ;
V_232 -> V_342 = F_192 ( struct V_368 ,
V_257 . V_263 ) ;
return F_185 ( V_6 , V_167 , V_232 ) ;
}
static int F_193 ( struct V_6 * V_6 ,
int V_167 , T_4 V_236 ,
T_4 V_238 ,
const T_9 * V_271 , const T_9 * V_273 ,
const T_9 * V_252 , const T_9 * V_254 ,
T_1 V_250 ,
T_1 V_1 , T_1 V_244 ,
T_9 V_277 , T_9 V_279 ,
T_9 V_281 , T_9 V_283 ,
T_4 V_263 )
{
T_4 V_291 ;
struct V_231 * V_232 ;
V_232 = F_32 ( sizeof( * V_232 ) , F_184 ( V_167 ) ) ;
if ( ! V_232 )
return - V_44 ;
V_291 = V_369 ;
if ( V_252 && V_254 ) {
if ( memcmp ( V_254 , V_370 , V_221 ) == 0 )
V_291 = V_371 ;
else if ( F_194 ( V_252 ) )
V_291 = V_372 ;
}
V_232 -> V_234 . V_291 = V_291 ;
V_232 -> V_234 . V_289 = V_299 ;
V_232 -> V_234 . V_269 . V_236 = V_236 ;
V_232 -> V_234 . V_269 . V_238 = V_238 ;
if ( V_271 )
F_144 ( V_232 -> V_234 . V_269 . V_271 , V_271 ) ;
if ( V_273 )
F_144 ( V_232 -> V_234 . V_269 . V_273 , V_273 ) ;
if ( V_252 )
F_144 ( V_232 -> V_234 . V_269 . V_252 , V_252 ) ;
if ( V_254 )
F_144 ( V_232 -> V_234 . V_269 . V_254 , V_254 ) ;
V_232 -> V_234 . V_269 . V_250 = V_250 ;
V_232 -> V_234 . V_269 . V_1 = V_1 ;
V_232 -> V_234 . V_269 . V_244 = V_244 ;
V_232 -> V_234 . V_269 . V_277 = V_277 ;
V_232 -> V_234 . V_269 . V_279 = V_279 ;
V_232 -> V_234 . V_269 . V_281 = V_281 ;
V_232 -> V_234 . V_269 . V_283 = V_283 ;
V_232 -> V_234 . V_269 . V_263 = V_263 ;
return F_185 ( V_6 , V_167 , V_232 ) ;
}
static struct V_301 *
F_195 ( struct V_19 * V_19 ,
struct V_301 * V_340 )
{
struct V_301 * V_341 ;
F_179 (rocker->group_tbl, found,
entry, match->group_id) {
if ( V_341 -> V_263 == V_340 -> V_263 )
return V_341 ;
}
return NULL ;
}
static void F_196 ( struct V_301 * V_232 )
{
switch ( F_171 ( V_232 -> V_263 ) ) {
case V_316 :
case V_317 :
F_13 ( V_232 -> V_307 ) ;
break;
default:
break;
}
F_13 ( V_232 ) ;
}
static int F_197 ( struct V_6 * V_6 ,
struct V_301 * V_340 ,
bool V_14 )
{
struct V_19 * V_19 = V_6 -> V_19 ;
struct V_301 * V_341 ;
unsigned long V_167 ;
F_138 ( & V_19 -> V_322 , V_167 ) ;
V_341 = F_195 ( V_19 , V_340 ) ;
if ( V_341 ) {
F_177 ( & V_341 -> V_232 ) ;
F_196 ( V_341 ) ;
V_341 = V_340 ;
V_341 -> V_287 = V_373 ;
} else {
V_341 = V_340 ;
V_341 -> V_287 = V_374 ;
}
F_182 ( V_19 -> V_321 , & V_341 -> V_232 , V_341 -> V_263 ) ;
F_139 ( & V_19 -> V_322 , V_167 ) ;
return F_137 ( V_19 , V_6 ,
F_170 ,
V_341 , NULL , NULL , V_14 ) ;
}
static int F_198 ( struct V_6 * V_6 ,
struct V_301 * V_340 ,
bool V_14 )
{
struct V_19 * V_19 = V_6 -> V_19 ;
struct V_301 * V_341 ;
unsigned long V_167 ;
int V_40 = 0 ;
F_138 ( & V_19 -> V_322 , V_167 ) ;
V_341 = F_195 ( V_19 , V_340 ) ;
if ( V_341 ) {
F_177 ( & V_341 -> V_232 ) ;
V_341 -> V_287 = V_375 ;
}
F_139 ( & V_19 -> V_322 , V_167 ) ;
F_196 ( V_340 ) ;
if ( V_341 ) {
V_40 = F_137 ( V_19 , V_6 ,
F_172 ,
V_341 , NULL , NULL , V_14 ) ;
F_196 ( V_341 ) ;
}
return V_40 ;
}
static int F_199 ( struct V_6 * V_6 ,
int V_167 , struct V_301 * V_232 )
{
bool V_14 = V_167 & V_168 ;
if ( V_167 & V_348 )
return F_198 ( V_6 , V_232 , V_14 ) ;
else
return F_197 ( V_6 , V_232 , V_14 ) ;
}
static int F_200 ( struct V_6 * V_6 ,
int V_167 , T_1 V_1 ,
T_4 V_376 , int V_8 )
{
struct V_301 * V_232 ;
V_232 = F_32 ( sizeof( * V_232 ) , F_184 ( V_167 ) ) ;
if ( ! V_232 )
return - V_44 ;
V_232 -> V_263 = F_201 ( V_1 , V_376 ) ;
V_232 -> V_304 . V_8 = V_8 ;
return F_199 ( V_6 , V_167 , V_232 ) ;
}
static int F_202 ( struct V_6 * V_6 ,
int V_167 , T_9 V_309 ,
T_4 * V_307 , T_4 V_263 )
{
struct V_301 * V_232 ;
V_232 = F_32 ( sizeof( * V_232 ) , F_184 ( V_167 ) ) ;
if ( ! V_232 )
return - V_44 ;
V_232 -> V_263 = V_263 ;
V_232 -> V_309 = V_309 ;
V_232 -> V_307 = F_90 ( V_309 , sizeof( T_4 ) ,
F_184 ( V_167 ) ) ;
if ( ! V_232 -> V_307 ) {
F_13 ( V_232 ) ;
return - V_44 ;
}
memcpy ( V_232 -> V_307 , V_307 , V_309 * sizeof( T_4 ) ) ;
return F_199 ( V_6 , V_167 , V_232 ) ;
}
static int F_203 ( struct V_6 * V_6 ,
int V_167 , T_1 V_1 ,
T_9 V_309 , T_4 * V_307 ,
T_4 V_263 )
{
return F_202 ( V_6 , V_167 ,
V_309 , V_307 ,
V_263 ) ;
}
static int F_204 ( struct V_6 * V_6 ,
int V_167 , T_4 V_377 , T_9 * V_378 ,
T_9 * V_379 , T_1 V_1 ,
bool V_313 , T_4 V_158 )
{
struct V_301 * V_232 ;
V_232 = F_32 ( sizeof( * V_232 ) , F_184 ( V_167 ) ) ;
if ( ! V_232 )
return - V_44 ;
V_232 -> V_263 = F_205 ( V_377 ) ;
if ( V_378 )
F_144 ( V_232 -> V_311 . V_271 , V_378 ) ;
if ( V_379 )
F_144 ( V_232 -> V_311 . V_252 , V_379 ) ;
V_232 -> V_311 . V_1 = V_1 ;
V_232 -> V_311 . V_313 = V_313 ;
V_232 -> V_311 . V_263 = F_201 ( V_1 , V_158 ) ;
return F_199 ( V_6 , V_167 , V_232 ) ;
}
static struct V_335 *
F_206 ( struct V_19 * V_19 , T_10 V_380 )
{
struct V_335 * V_341 ;
F_179 (rocker->neigh_tbl, found,
entry, be32_to_cpu(ip_addr))
if ( V_341 -> V_380 == V_380 )
return V_341 ;
return NULL ;
}
static void F_207 ( struct V_19 * V_19 ,
struct V_335 * V_232 )
{
V_232 -> V_377 = V_19 -> V_381 ++ ;
V_232 -> V_382 ++ ;
F_182 ( V_19 -> V_327 , & V_232 -> V_232 ,
F_208 ( V_232 -> V_380 ) ) ;
}
static void F_209 ( struct V_19 * V_19 ,
struct V_335 * V_232 )
{
if ( -- V_232 -> V_382 == 0 ) {
F_177 ( & V_232 -> V_232 ) ;
F_13 ( V_232 ) ;
}
}
static void F_210 ( struct V_19 * V_19 ,
struct V_335 * V_232 ,
T_9 * V_252 , bool V_313 )
{
if ( V_252 ) {
F_144 ( V_232 -> V_252 , V_252 ) ;
V_232 -> V_313 = V_313 ;
} else {
V_232 -> V_382 ++ ;
}
}
static int F_211 ( struct V_6 * V_6 ,
int V_167 , T_10 V_380 , T_9 * V_252 )
{
struct V_19 * V_19 = V_6 -> V_19 ;
struct V_335 * V_232 ;
struct V_335 * V_341 ;
unsigned long V_383 ;
T_1 V_250 = F_4 ( V_274 ) ;
enum V_349 V_240 =
V_299 ;
T_4 V_263 ;
T_4 V_291 = 0 ;
bool V_384 = ! ( V_167 & V_348 ) ;
bool V_385 ;
bool V_386 ;
int V_40 = 0 ;
V_232 = F_32 ( sizeof( * V_232 ) , F_184 ( V_167 ) ) ;
if ( ! V_232 )
return - V_44 ;
F_138 ( & V_19 -> V_328 , V_383 ) ;
V_341 = F_206 ( V_19 , V_380 ) ;
V_385 = V_341 && V_384 ;
V_386 = V_341 && ! V_384 ;
V_384 = ! V_341 && V_384 ;
if ( V_384 ) {
V_232 -> V_380 = V_380 ;
V_232 -> V_28 = V_6 -> V_28 ;
F_144 ( V_232 -> V_252 , V_252 ) ;
V_232 -> V_313 = true ;
F_207 ( V_19 , V_232 ) ;
} else if ( V_386 ) {
memcpy ( V_232 , V_341 , sizeof( * V_232 ) ) ;
F_209 ( V_19 , V_341 ) ;
} else if ( V_385 ) {
F_210 ( V_19 , V_341 , V_252 , true ) ;
memcpy ( V_232 , V_341 , sizeof( * V_232 ) ) ;
} else {
V_40 = - V_91 ;
}
F_139 ( & V_19 -> V_328 , V_383 ) ;
if ( V_40 )
goto V_387;
V_40 = F_204 ( V_6 , V_167 ,
V_232 -> V_377 ,
V_6 -> V_28 -> V_388 ,
V_232 -> V_252 ,
V_6 -> V_9 ,
V_232 -> V_313 ,
V_6 -> V_158 ) ;
if ( V_40 ) {
F_116 ( V_6 -> V_28 ,
L_21 ,
V_40 , V_232 -> V_377 ) ;
goto V_387;
}
if ( V_384 || V_386 ) {
V_263 = F_205 ( V_232 -> V_377 ) ;
V_40 = F_191 ( V_6 ,
V_250 , V_380 ,
F_212 ( 32 ) ,
V_291 , V_240 ,
V_263 , V_167 ) ;
if ( V_40 )
F_116 ( V_6 -> V_28 ,
L_22 ,
V_40 , & V_232 -> V_380 , V_263 ) ;
}
V_387:
if ( ! V_384 )
F_13 ( V_232 ) ;
return V_40 ;
}
static int F_213 ( struct V_6 * V_6 ,
T_10 V_380 )
{
struct V_141 * V_28 = V_6 -> V_28 ;
struct V_389 * V_390 = F_214 ( V_28 , ( V_391 T_4 ) V_380 ) ;
int V_40 = 0 ;
if ( ! V_390 ) {
V_390 = F_215 ( & V_392 , & V_380 , V_28 ) ;
if ( F_216 ( V_390 ) )
return F_216 ( V_390 ) ;
}
if ( V_390 -> V_393 & V_394 )
V_40 = F_211 ( V_6 , 0 , V_380 , V_390 -> V_395 ) ;
else
F_217 ( V_390 , NULL ) ;
F_218 ( V_390 ) ;
return V_40 ;
}
static int F_219 ( struct V_6 * V_6 , int V_167 ,
T_10 V_380 , T_4 * V_377 )
{
struct V_19 * V_19 = V_6 -> V_19 ;
struct V_335 * V_232 ;
struct V_335 * V_341 ;
unsigned long V_383 ;
bool V_384 = ! ( V_167 & V_348 ) ;
bool V_385 ;
bool V_386 ;
bool V_396 = true ;
int V_40 = 0 ;
V_232 = F_32 ( sizeof( * V_232 ) , F_184 ( V_167 ) ) ;
if ( ! V_232 )
return - V_44 ;
F_138 ( & V_19 -> V_328 , V_383 ) ;
V_341 = F_206 ( V_19 , V_380 ) ;
if ( V_341 )
* V_377 = V_341 -> V_377 ;
V_385 = V_341 && V_384 ;
V_386 = V_341 && ! V_384 ;
V_384 = ! V_341 && V_384 ;
if ( V_384 ) {
V_232 -> V_380 = V_380 ;
V_232 -> V_28 = V_6 -> V_28 ;
F_207 ( V_19 , V_232 ) ;
* V_377 = V_232 -> V_377 ;
V_396 = false ;
} else if ( V_386 ) {
F_209 ( V_19 , V_341 ) ;
} else if ( V_385 ) {
F_210 ( V_19 , V_341 , NULL , false ) ;
V_396 = ! F_167 ( V_341 -> V_252 ) ;
} else {
V_40 = - V_91 ;
}
F_139 ( & V_19 -> V_328 , V_383 ) ;
if ( ! V_384 )
F_13 ( V_232 ) ;
if ( V_40 )
return V_40 ;
if ( ! V_396 )
V_40 = F_213 ( V_6 , V_380 ) ;
return V_40 ;
}
static int F_220 ( struct V_6 * V_6 ,
int V_167 , T_1 V_1 )
{
struct V_6 * V_397 ;
struct V_19 * V_19 = V_6 -> V_19 ;
T_4 V_263 = F_221 ( V_1 , 0 ) ;
T_4 * V_307 ;
T_9 V_309 = 0 ;
int V_40 = 0 ;
int V_36 ;
V_307 = F_90 ( V_19 -> V_163 , sizeof( T_4 ) ,
F_184 ( V_167 ) ) ;
if ( ! V_307 )
return - V_44 ;
for ( V_36 = 0 ; V_36 < V_19 -> V_163 ; V_36 ++ ) {
V_397 = V_19 -> V_164 [ V_36 ] ;
if ( ! F_6 ( V_397 ) )
continue;
if ( F_222 ( F_2 ( V_1 ) , V_397 -> V_398 ) ) {
V_307 [ V_309 ++ ] =
F_201 ( V_1 , V_397 -> V_158 ) ;
}
}
if ( V_309 == 0 )
goto V_399;
V_40 = F_203 ( V_6 , V_167 , V_1 ,
V_309 , V_307 ,
V_263 ) ;
if ( V_40 )
F_116 ( V_6 -> V_28 ,
L_23 , V_40 ) ;
V_399:
F_13 ( V_307 ) ;
return V_40 ;
}
static int F_223 ( struct V_6 * V_6 ,
int V_167 , T_1 V_1 ,
bool V_8 )
{
struct V_19 * V_19 = V_6 -> V_19 ;
struct V_6 * V_397 ;
bool V_384 = ! ( V_167 & V_348 ) ;
T_4 V_376 ;
int V_400 = 0 ;
int V_40 ;
int V_36 ;
if ( V_6 -> V_173 == V_174 ||
V_6 -> V_173 == V_175 ) {
V_376 = V_6 -> V_158 ;
V_40 = F_200 ( V_6 , V_167 ,
V_1 , V_376 ,
V_8 ) ;
if ( V_40 ) {
F_116 ( V_6 -> V_28 ,
L_24 ,
V_40 , V_376 ) ;
return V_40 ;
}
}
for ( V_36 = 0 ; V_36 < V_19 -> V_163 ; V_36 ++ ) {
V_397 = V_19 -> V_164 [ V_36 ] ;
if ( F_222 ( F_2 ( V_1 ) , V_397 -> V_398 ) )
V_400 ++ ;
}
if ( ( ! V_384 || V_400 != 1 ) && ( V_384 || V_400 != 0 ) )
return 0 ;
V_376 = 0 ;
V_40 = F_200 ( V_6 , V_167 ,
V_1 , V_376 ,
V_8 ) ;
if ( V_40 ) {
F_116 ( V_6 -> V_28 ,
L_25 , V_40 ) ;
return V_40 ;
}
return 0 ;
}
static int F_224 ( struct V_6 * V_6 ,
int V_167 , struct V_401 * V_402 ,
T_1 V_1 )
{
T_4 V_236 = V_6 -> V_158 ;
T_4 V_238 = 0xffffffff ;
T_4 V_376 = 0 ;
T_9 * V_271 = NULL ;
T_9 * V_273 = NULL ;
T_1 V_244 = F_4 ( 0xffff ) ;
T_9 V_277 = 0 ;
T_9 V_279 = 0 ;
T_9 V_281 = 0 ;
T_9 V_283 = 0 ;
T_4 V_263 = F_201 ( V_1 , V_376 ) ;
int V_40 ;
V_40 = F_193 ( V_6 , V_167 ,
V_236 , V_238 ,
V_271 , V_273 ,
V_402 -> V_252 , V_402 -> V_254 ,
V_402 -> V_250 ,
V_1 , V_244 ,
V_277 , V_279 ,
V_281 , V_283 ,
V_263 ) ;
if ( V_40 )
F_116 ( V_6 -> V_28 , L_26 , V_40 ) ;
return V_40 ;
}
static int F_225 ( struct V_6 * V_6 ,
int V_167 , struct V_401 * V_402 ,
T_1 V_1 )
{
enum V_349 V_240 =
V_299 ;
T_4 V_263 = F_221 ( V_1 , 0 ) ;
T_4 V_267 = 0 ;
int V_40 ;
if ( ! F_6 ( V_6 ) )
return 0 ;
V_40 = F_190 ( V_6 , V_167 ,
V_402 -> V_252 , V_402 -> V_254 ,
V_1 , V_267 ,
V_240 , V_263 , V_402 -> V_255 ) ;
if ( V_40 )
F_116 ( V_6 -> V_28 , L_27 , V_40 ) ;
return V_40 ;
}
static int F_226 ( struct V_6 * V_6 ,
int V_167 , struct V_401 * V_402 ,
T_1 V_1 )
{
T_4 V_238 = 0xffffffff ;
T_1 V_244 = F_4 ( 0xffff ) ;
int V_40 ;
if ( F_2 ( V_1 ) == 0 )
V_1 = V_6 -> V_9 ;
V_40 = F_188 ( V_6 ,
V_6 -> V_158 , V_238 ,
V_402 -> V_250 , V_402 -> V_252 ,
V_402 -> V_254 , V_1 ,
V_244 , V_402 -> V_255 ,
V_167 ) ;
if ( V_40 )
F_116 ( V_6 -> V_28 , L_28 , V_40 ) ;
return V_40 ;
}
static int F_227 ( struct V_6 * V_6 , int V_167 ,
struct V_401 * V_402 , T_1 V_1 )
{
if ( V_402 -> V_269 )
return F_224 ( V_6 , V_167 ,
V_402 , V_1 ) ;
if ( V_402 -> V_264 )
return F_225 ( V_6 , V_167 ,
V_402 , V_1 ) ;
if ( V_402 -> V_403 )
return F_226 ( V_6 , V_167 ,
V_402 , V_1 ) ;
return - V_101 ;
}
static int F_228 ( struct V_6 * V_6 ,
int V_167 , T_1 V_1 )
{
int V_40 = 0 ;
int V_36 ;
for ( V_36 = 0 ; V_36 < V_404 ; V_36 ++ ) {
if ( V_6 -> V_405 [ V_36 ] ) {
V_40 = F_227 ( V_6 , V_167 ,
& V_406 [ V_36 ] , V_1 ) ;
if ( V_40 )
return V_40 ;
}
}
return V_40 ;
}
static int F_229 ( struct V_6 * V_6 , int V_167 ,
struct V_401 * V_402 )
{
T_2 V_7 ;
int V_40 = 0 ;
for ( V_7 = 1 ; V_7 < V_407 ; V_7 ++ ) {
if ( ! F_222 ( V_7 , V_6 -> V_398 ) )
continue;
V_40 = F_227 ( V_6 , V_167 ,
V_402 , F_4 ( V_7 ) ) ;
if ( V_40 )
break;
}
return V_40 ;
}
static int F_230 ( struct V_6 * V_6 , int V_167 ,
T_2 V_7 )
{
enum V_349 V_240 =
V_296 ;
T_4 V_236 = V_6 -> V_158 ;
T_1 V_1 = F_4 ( V_7 ) ;
T_1 V_244 = F_4 ( 0xffff ) ;
T_1 V_9 ;
bool V_245 ;
bool V_384 = ! ( V_167 & V_348 ) ;
int V_40 ;
V_9 = F_3 ( V_6 , V_7 , & V_245 ) ;
if ( V_384 && F_231 ( F_2 ( V_9 ) ,
V_6 -> V_398 ) )
return 0 ;
else if ( ! V_384 && ! F_232 ( F_2 ( V_9 ) ,
V_6 -> V_398 ) )
return 0 ;
if ( V_384 ) {
V_40 = F_228 ( V_6 , V_167 ,
V_9 ) ;
if ( V_40 ) {
F_116 ( V_6 -> V_28 ,
L_29 , V_40 ) ;
return V_40 ;
}
}
V_40 = F_223 ( V_6 , V_167 ,
V_9 , V_245 ) ;
if ( V_40 ) {
F_116 ( V_6 -> V_28 ,
L_30 , V_40 ) ;
return V_40 ;
}
V_40 = F_220 ( V_6 , V_167 ,
V_9 ) ;
if ( V_40 ) {
F_116 ( V_6 -> V_28 ,
L_23 , V_40 ) ;
return V_40 ;
}
V_40 = F_187 ( V_6 , V_167 ,
V_236 , V_1 , V_244 ,
V_240 , V_245 , V_9 ) ;
if ( V_40 )
F_116 ( V_6 -> V_28 ,
L_31 , V_40 ) ;
return V_40 ;
}
static int F_233 ( struct V_6 * V_6 , int V_167 )
{
enum V_349 V_240 ;
T_4 V_236 ;
T_4 V_238 ;
int V_40 ;
V_236 = 0 ;
V_238 = 0xffff0000 ;
V_240 = V_295 ;
V_40 = F_186 ( V_6 , V_167 ,
V_236 , V_238 ,
V_240 ) ;
if ( V_40 )
F_116 ( V_6 -> V_28 ,
L_32 , V_40 ) ;
return V_40 ;
}
static void F_234 ( struct V_408 * V_16 )
{
struct V_409 * V_410 =
F_235 ( V_16 , struct V_409 , V_16 ) ;
bool V_386 = ( V_410 -> V_167 & V_348 ) ;
bool V_411 = ( V_410 -> V_167 & V_169 ) ;
struct V_412 V_108 ;
V_108 . V_166 = V_410 -> V_166 ;
V_108 . V_7 = V_410 -> V_7 ;
if ( V_411 && V_386 )
F_236 ( V_413 ,
V_410 -> V_28 , & V_108 . V_108 ) ;
else if ( V_411 && ! V_386 )
F_236 ( V_414 ,
V_410 -> V_28 , & V_108 . V_108 ) ;
F_13 ( V_16 ) ;
}
static int F_237 ( struct V_6 * V_6 ,
int V_167 , const T_9 * V_166 , T_1 V_1 )
{
struct V_409 * V_410 ;
enum V_349 V_240 =
V_299 ;
T_4 V_376 = V_6 -> V_158 ;
T_4 V_267 = 0 ;
T_4 V_263 = V_286 ;
bool V_415 = ! ! ( V_6 -> V_229 & V_416 ) ;
bool V_255 = false ;
int V_40 ;
if ( F_6 ( V_6 ) )
V_263 = F_201 ( V_1 , V_376 ) ;
if ( ! ( V_167 & V_417 ) ) {
V_40 = F_190 ( V_6 , V_167 , V_166 , NULL ,
V_1 , V_267 , V_240 ,
V_263 , V_255 ) ;
if ( V_40 )
return V_40 ;
}
if ( ! V_415 )
return 0 ;
if ( ! F_6 ( V_6 ) )
return 0 ;
V_410 = F_11 ( sizeof( * V_410 ) , F_184 ( V_167 ) ) ;
if ( ! V_410 )
return - V_44 ;
F_238 ( & V_410 -> V_16 , F_234 ) ;
V_410 -> V_28 = V_6 -> V_28 ;
V_410 -> V_167 = V_167 ;
F_144 ( V_410 -> V_166 , V_166 ) ;
V_410 -> V_7 = F_5 ( V_6 , V_1 ) ;
F_239 ( & V_410 -> V_16 ) ;
return 0 ;
}
static struct V_331 *
F_240 ( struct V_19 * V_19 , struct V_331 * V_340 )
{
struct V_331 * V_341 ;
F_179 (rocker->fdb_tbl, found, entry, match->key_crc32)
if ( memcmp ( & V_341 -> V_234 , & V_340 -> V_234 , sizeof( V_341 -> V_234 ) ) == 0 )
return V_341 ;
return NULL ;
}
static int F_131 ( struct V_6 * V_6 ,
const unsigned char * V_166 ,
T_1 V_1 , int V_167 )
{
struct V_19 * V_19 = V_6 -> V_19 ;
struct V_331 * V_418 ;
struct V_331 * V_341 ;
bool V_386 = ( V_167 & V_348 ) ;
unsigned long V_383 ;
V_418 = F_32 ( sizeof( * V_418 ) , F_184 ( V_167 ) ) ;
if ( ! V_418 )
return - V_44 ;
V_418 -> V_411 = ( V_167 & V_169 ) ;
V_418 -> V_234 . V_158 = V_6 -> V_158 ;
F_144 ( V_418 -> V_234 . V_166 , V_166 ) ;
V_418 -> V_234 . V_1 = V_1 ;
V_418 -> V_343 = F_181 ( ~ 0 , & V_418 -> V_234 , sizeof( V_418 -> V_234 ) ) ;
F_138 ( & V_19 -> V_324 , V_383 ) ;
V_341 = F_240 ( V_19 , V_418 ) ;
if ( V_386 && V_341 ) {
F_13 ( V_418 ) ;
F_177 ( & V_341 -> V_232 ) ;
} else if ( ! V_386 && ! V_341 ) {
F_182 ( V_19 -> V_323 , & V_418 -> V_232 , V_418 -> V_343 ) ;
}
F_139 ( & V_19 -> V_324 , V_383 ) ;
if ( ! V_341 != ! V_386 ) {
F_13 ( V_418 ) ;
if ( ! V_341 && V_386 )
return 0 ;
V_167 |= V_417 ;
}
return F_237 ( V_6 , V_167 , V_166 , V_1 ) ;
}
static int F_241 ( struct V_6 * V_6 )
{
struct V_19 * V_19 = V_6 -> V_19 ;
struct V_331 * V_341 ;
unsigned long V_383 ;
int V_167 = V_168 | V_348 ;
struct V_337 * V_338 ;
int V_339 ;
int V_40 = 0 ;
if ( V_6 -> V_173 == V_174 ||
V_6 -> V_173 == V_175 )
return 0 ;
F_138 ( & V_19 -> V_324 , V_383 ) ;
F_176 (rocker->fdb_tbl, bkt, tmp, found, entry) {
if ( V_341 -> V_234 . V_158 != V_6 -> V_158 )
continue;
if ( ! V_341 -> V_411 )
continue;
V_40 = F_237 ( V_6 , V_167 ,
V_341 -> V_234 . V_166 ,
V_341 -> V_234 . V_1 ) ;
if ( V_40 )
goto V_387;
F_177 ( & V_341 -> V_232 ) ;
}
V_387:
F_139 ( & V_19 -> V_324 , V_383 ) ;
return V_40 ;
}
static int F_242 ( struct V_6 * V_6 ,
int V_167 , T_1 V_1 )
{
T_4 V_238 = 0xffffffff ;
T_1 V_250 ;
const T_9 * V_419 = V_358 ;
T_1 V_244 = F_4 ( 0xffff ) ;
bool V_255 = false ;
int V_40 ;
if ( F_2 ( V_1 ) == 0 )
V_1 = V_6 -> V_9 ;
V_250 = F_4 ( V_274 ) ;
V_40 = F_188 ( V_6 ,
V_6 -> V_158 , V_238 ,
V_250 , V_6 -> V_28 -> V_388 ,
V_419 , V_1 , V_244 ,
V_255 , V_167 ) ;
if ( V_40 )
return V_40 ;
V_250 = F_4 ( V_275 ) ;
V_40 = F_188 ( V_6 ,
V_6 -> V_158 , V_238 ,
V_250 , V_6 -> V_28 -> V_388 ,
V_419 , V_1 , V_244 ,
V_255 , V_167 ) ;
return V_40 ;
}
static int F_243 ( struct V_6 * V_6 )
{
bool V_8 ;
T_4 V_376 ;
T_1 V_1 ;
T_2 V_7 ;
int V_167 = V_168 ;
int V_40 ;
if ( V_6 -> V_173 != V_174 &&
V_6 -> V_173 != V_175 )
V_167 |= V_348 ;
V_376 = V_6 -> V_158 ;
for ( V_7 = 1 ; V_7 < V_407 ; V_7 ++ ) {
if ( ! F_222 ( V_7 , V_6 -> V_398 ) )
continue;
V_1 = F_4 ( V_7 ) ;
V_8 = F_1 ( V_1 ) ;
V_40 = F_200 ( V_6 , V_167 ,
V_1 , V_376 ,
V_8 ) ;
if ( V_40 ) {
F_116 ( V_6 -> V_28 ,
L_24 ,
V_40 , V_376 ) ;
return V_40 ;
}
}
return 0 ;
}
static int F_244 ( struct V_6 * V_6 , T_9 V_420 )
{
bool V_421 [ V_404 ] = { 0 , } ;
int V_167 ;
int V_40 ;
int V_36 ;
if ( V_6 -> V_173 == V_420 )
return 0 ;
V_6 -> V_173 = V_420 ;
switch ( V_420 ) {
case V_422 :
break;
case V_423 :
case V_424 :
V_421 [ V_425 ] = true ;
break;
case V_174 :
case V_175 :
V_421 [ V_425 ] = true ;
V_421 [ V_426 ] = true ;
V_421 [ V_427 ] = true ;
if ( F_6 ( V_6 ) )
V_421 [ V_428 ] = true ;
else
V_421 [ V_429 ] = true ;
break;
}
for ( V_36 = 0 ; V_36 < V_404 ; V_36 ++ ) {
if ( V_421 [ V_36 ] != V_6 -> V_405 [ V_36 ] ) {
V_167 = V_168 |
( V_421 [ V_36 ] ? 0 : V_348 ) ;
V_40 = F_229 ( V_6 , V_167 ,
& V_406 [ V_36 ] ) ;
if ( V_40 )
return V_40 ;
V_6 -> V_405 [ V_36 ] = V_421 [ V_36 ] ;
}
}
V_40 = F_241 ( V_6 ) ;
if ( V_40 )
return V_40 ;
return F_243 ( V_6 ) ;
}
static int F_245 ( struct V_6 * V_6 )
{
if ( F_6 ( V_6 ) )
return 0 ;
return F_244 ( V_6 , V_175 ) ;
}
static int F_246 ( struct V_6 * V_6 )
{
if ( F_6 ( V_6 ) )
return 0 ;
return F_244 ( V_6 , V_422 ) ;
}
static struct V_333 *
F_247 ( struct V_19 * V_19 , int V_430 )
{
struct V_333 * V_341 ;
F_179 (rocker->internal_vlan_tbl, found,
entry, ifindex) {
if ( V_341 -> V_430 == V_430 )
return V_341 ;
}
return NULL ;
}
static T_1 F_248 ( struct V_6 * V_6 ,
int V_430 )
{
struct V_19 * V_19 = V_6 -> V_19 ;
struct V_333 * V_232 ;
struct V_333 * V_341 ;
unsigned long V_383 ;
int V_36 ;
V_232 = F_32 ( sizeof( * V_232 ) , V_42 ) ;
if ( ! V_232 )
return 0 ;
V_232 -> V_430 = V_430 ;
F_138 ( & V_19 -> V_326 , V_383 ) ;
V_341 = F_247 ( V_19 , V_430 ) ;
if ( V_341 ) {
F_13 ( V_232 ) ;
goto V_341;
}
V_341 = V_232 ;
F_182 ( V_19 -> V_325 , & V_341 -> V_232 , V_341 -> V_430 ) ;
for ( V_36 = 0 ; V_36 < V_431 ; V_36 ++ ) {
if ( F_231 ( V_36 , V_19 -> V_432 ) )
continue;
V_341 -> V_1 = F_4 ( V_3 + V_36 ) ;
goto V_341;
}
F_116 ( V_6 -> V_28 , L_33 ) ;
V_341:
V_341 -> V_382 ++ ;
F_139 ( & V_19 -> V_326 , V_383 ) ;
return V_341 -> V_1 ;
}
static void F_249 ( struct V_6 * V_6 ,
int V_430 )
{
struct V_19 * V_19 = V_6 -> V_19 ;
struct V_333 * V_341 ;
unsigned long V_383 ;
unsigned long V_433 ;
F_138 ( & V_19 -> V_326 , V_383 ) ;
V_341 = F_247 ( V_19 , V_430 ) ;
if ( ! V_341 ) {
F_116 ( V_6 -> V_28 ,
L_34 ,
V_430 ) ;
goto V_434;
}
if ( -- V_341 -> V_382 <= 0 ) {
V_433 = F_2 ( V_341 -> V_1 ) - V_3 ;
F_250 ( V_433 , V_19 -> V_432 ) ;
F_177 ( & V_341 -> V_232 ) ;
F_13 ( V_341 ) ;
}
V_434:
F_139 ( & V_19 -> V_326 , V_383 ) ;
}
static int F_251 ( struct V_6 * V_6 , T_10 V_366 ,
int V_435 , struct V_436 * V_437 , T_4 V_438 ,
int V_167 )
{
struct V_439 * V_440 ;
T_1 V_250 = F_4 ( V_274 ) ;
T_10 V_367 = F_212 ( V_435 ) ;
T_1 V_9 = V_6 -> V_9 ;
T_4 V_291 = V_437 -> V_441 ;
enum V_349 V_240 =
V_299 ;
T_4 V_263 ;
bool V_442 ;
bool V_443 ;
T_4 V_377 ;
int V_40 ;
V_440 = V_437 -> V_439 ;
V_442 = ( V_437 -> V_444 == V_6 -> V_28 ) ;
V_443 = ! ! V_440 -> V_445 ;
if ( V_443 && V_442 ) {
V_40 = F_219 ( V_6 , V_167 ,
V_440 -> V_445 , & V_377 ) ;
if ( V_40 )
return V_40 ;
V_263 = F_205 ( V_377 ) ;
} else {
V_263 = F_201 ( V_9 , 0 ) ;
}
V_40 = F_191 ( V_6 , V_250 , V_366 ,
V_367 , V_291 , V_240 ,
V_263 , V_167 ) ;
if ( V_40 )
F_116 ( V_6 -> V_28 , L_35 ,
V_40 , & V_366 ) ;
return V_40 ;
}
static int F_252 ( struct V_141 * V_28 )
{
struct V_6 * V_6 = F_253 ( V_28 ) ;
int V_40 ;
V_40 = F_114 ( V_6 ) ;
if ( V_40 )
return V_40 ;
V_40 = F_40 ( F_19 ( V_6 ) ,
F_134 , 0 ,
V_58 , V_6 ) ;
if ( V_40 ) {
F_116 ( V_6 -> V_28 , L_36 ) ;
goto V_446;
}
V_40 = F_40 ( F_21 ( V_6 ) ,
F_136 , 0 ,
V_58 , V_6 ) ;
if ( V_40 ) {
F_116 ( V_6 -> V_28 , L_37 ) ;
goto V_447;
}
V_40 = F_245 ( V_6 ) ;
if ( V_40 )
goto V_448;
F_254 ( & V_6 -> V_181 ) ;
F_254 ( & V_6 -> V_182 ) ;
F_119 ( V_6 , true ) ;
F_255 ( V_28 ) ;
return 0 ;
V_448:
V_60 ( F_21 ( V_6 ) , V_6 ) ;
V_447:
V_60 ( F_19 ( V_6 ) , V_6 ) ;
V_446:
F_118 ( V_6 ) ;
return V_40 ;
}
static int F_256 ( struct V_141 * V_28 )
{
struct V_6 * V_6 = F_253 ( V_28 ) ;
F_257 ( V_28 ) ;
F_119 ( V_6 , false ) ;
F_258 ( & V_6 -> V_182 ) ;
F_258 ( & V_6 -> V_181 ) ;
F_246 ( V_6 ) ;
V_60 ( F_21 ( V_6 ) , V_6 ) ;
V_60 ( F_19 ( V_6 ) , V_6 ) ;
F_118 ( V_6 ) ;
return 0 ;
}
static void F_259 ( struct V_6 * V_6 ,
struct V_73 * V_74 )
{
struct V_19 * V_19 = V_6 -> V_19 ;
struct V_23 * V_24 = V_19 -> V_24 ;
struct V_61 * V_142 [ V_449 + 1 ] ;
struct V_61 * V_219 ;
int V_72 ;
F_58 ( V_142 , V_449 , V_74 ) ;
if ( ! V_142 [ V_450 ] )
return;
F_260 (attr, attrs[ROCKER_TLV_TX_FRAGS], rem) {
struct V_61 * V_451 [ V_452 + 1 ] ;
T_6 V_32 ;
T_7 V_65 ;
if ( F_47 ( V_219 ) != V_453 )
continue;
F_57 ( V_451 , V_452 ,
V_219 ) ;
if ( ! V_451 [ V_454 ] ||
! V_451 [ V_455 ] )
continue;
V_32 = F_54 ( V_451 [ V_454 ] ) ;
V_65 = F_51 ( V_451 [ V_455 ] ) ;
F_36 ( V_24 , V_32 , V_65 , V_456 ) ;
}
}
static int F_261 ( struct V_6 * V_6 ,
struct V_73 * V_74 ,
char * V_33 , T_7 V_70 )
{
struct V_19 * V_19 = V_6 -> V_19 ;
struct V_23 * V_24 = V_19 -> V_24 ;
T_6 V_32 ;
struct V_61 * V_457 ;
V_32 = F_33 ( V_24 , V_33 , V_70 , V_456 ) ;
if ( F_61 ( F_34 ( V_24 , V_32 ) ) ) {
if ( F_262 () )
F_116 ( V_6 -> V_28 , L_38 ) ;
return - V_29 ;
}
V_457 = F_68 ( V_74 , V_453 ) ;
if ( ! V_457 )
goto V_458;
if ( F_67 ( V_74 , V_454 ,
V_32 ) )
goto V_459;
if ( F_63 ( V_74 , V_455 ,
V_70 ) )
goto V_459;
F_69 ( V_74 , V_457 ) ;
return 0 ;
V_459:
F_70 ( V_74 , V_457 ) ;
V_458:
F_36 ( V_24 , V_32 , V_70 , V_456 ) ;
return - V_83 ;
}
static T_12 F_263 ( struct V_132 * V_133 , struct V_141 * V_28 )
{
struct V_6 * V_6 = F_253 ( V_28 ) ;
struct V_19 * V_19 = V_6 -> V_19 ;
struct V_73 * V_74 ;
struct V_61 * V_460 ;
int V_36 ;
int V_40 ;
V_74 = F_77 ( & V_6 -> V_146 ) ;
if ( F_61 ( ! V_74 ) ) {
if ( F_262 () )
F_116 ( V_28 , L_39 ) ;
return V_461 ;
}
F_76 ( V_74 , V_133 ) ;
V_460 = F_68 ( V_74 , V_450 ) ;
if ( ! V_460 )
goto V_189;
V_40 = F_261 ( V_6 , V_74 ,
V_133 -> V_75 , F_264 ( V_133 ) ) ;
if ( V_40 )
goto V_459;
if ( F_265 ( V_133 ) -> V_462 > V_463 )
goto V_459;
for ( V_36 = 0 ; V_36 < F_265 ( V_133 ) -> V_462 ; V_36 ++ ) {
const T_13 * V_457 = & F_265 ( V_133 ) -> V_460 [ V_36 ] ;
V_40 = F_261 ( V_6 , V_74 ,
F_266 ( V_457 ) ,
F_267 ( V_457 ) ) ;
if ( V_40 )
goto V_464;
}
F_69 ( V_74 , V_460 ) ;
F_73 ( V_74 ) ;
F_79 ( V_19 , & V_6 -> V_146 , V_74 ) ;
V_74 = F_77 ( & V_6 -> V_146 ) ;
if ( ! V_74 )
F_257 ( V_28 ) ;
return V_465 ;
V_464:
F_259 ( V_6 , V_74 ) ;
V_459:
F_70 ( V_74 , V_460 ) ;
V_189:
F_268 ( V_133 ) ;
V_28 -> V_466 . V_467 ++ ;
return V_465 ;
}
static int F_269 ( struct V_141 * V_28 , void * V_397 )
{
struct V_468 * V_166 = V_397 ;
struct V_6 * V_6 = F_253 ( V_28 ) ;
int V_40 ;
if ( ! F_270 ( V_166 -> V_469 ) )
return - V_470 ;
V_40 = F_154 ( V_6 , V_166 -> V_469 ) ;
if ( V_40 )
return V_40 ;
memcpy ( V_28 -> V_388 , V_166 -> V_469 , V_28 -> V_471 ) ;
return 0 ;
}
static int F_271 ( struct V_141 * V_28 ,
T_1 V_472 , T_2 V_7 )
{
struct V_6 * V_6 = F_253 ( V_28 ) ;
int V_40 ;
V_40 = F_230 ( V_6 , 0 , V_7 ) ;
if ( V_40 )
return V_40 ;
return F_242 ( V_6 , 0 , F_4 ( V_7 ) ) ;
}
static int F_272 ( struct V_141 * V_28 ,
T_1 V_472 , T_2 V_7 )
{
struct V_6 * V_6 = F_253 ( V_28 ) ;
int V_40 ;
V_40 = F_242 ( V_6 , V_348 ,
F_4 ( V_7 ) ) ;
if ( V_40 )
return V_40 ;
return F_230 ( V_6 , V_348 , V_7 ) ;
}
static int F_273 ( struct V_473 * V_474 , struct V_475 * V_68 [] ,
struct V_141 * V_28 ,
const unsigned char * V_166 , T_2 V_7 ,
T_2 V_476 )
{
struct V_6 * V_6 = F_253 ( V_28 ) ;
T_1 V_1 = F_3 ( V_6 , V_7 , NULL ) ;
int V_167 = 0 ;
if ( ! F_6 ( V_6 ) )
return - V_98 ;
return F_131 ( V_6 , V_166 , V_1 , V_167 ) ;
}
static int F_274 ( struct V_473 * V_474 , struct V_475 * V_68 [] ,
struct V_141 * V_28 ,
const unsigned char * V_166 , T_2 V_7 )
{
struct V_6 * V_6 = F_253 ( V_28 ) ;
T_1 V_1 = F_3 ( V_6 , V_7 , NULL ) ;
int V_167 = V_348 ;
if ( ! F_6 ( V_6 ) )
return - V_98 ;
return F_131 ( V_6 , V_166 , V_1 , V_167 ) ;
}
static int F_275 ( struct V_132 * V_133 ,
struct V_6 * V_6 ,
const unsigned char * V_166 , T_2 V_7 ,
T_4 V_477 , T_4 V_478 , int type ,
unsigned int V_167 )
{
struct V_479 * V_480 ;
struct V_473 * V_474 ;
V_480 = F_276 ( V_133 , V_477 , V_478 , type , sizeof( * V_474 ) , V_167 ) ;
if ( ! V_480 )
return - V_83 ;
V_474 = F_277 ( V_480 ) ;
V_474 -> V_481 = V_482 ;
V_474 -> V_483 = 0 ;
V_474 -> V_484 = 0 ;
V_474 -> V_485 = V_486 ;
V_474 -> V_487 = 0 ;
V_474 -> V_488 = V_6 -> V_28 -> V_430 ;
V_474 -> V_489 = V_490 ;
if ( F_278 ( V_133 , V_491 , V_221 , V_166 ) )
goto V_492;
if ( V_7 && F_279 ( V_133 , V_493 , V_7 ) )
goto V_492;
F_280 ( V_133 , V_480 ) ;
return 0 ;
V_492:
F_281 ( V_133 , V_480 ) ;
return - V_83 ;
}
static int F_282 ( struct V_132 * V_133 ,
struct V_494 * V_495 ,
struct V_141 * V_28 ,
struct V_141 * V_496 ,
int V_497 )
{
struct V_6 * V_6 = F_253 ( V_28 ) ;
struct V_19 * V_19 = V_6 -> V_19 ;
struct V_331 * V_341 ;
struct V_337 * V_338 ;
int V_339 ;
unsigned long V_383 ;
const unsigned char * V_166 ;
T_2 V_7 ;
int V_40 ;
F_138 ( & V_19 -> V_324 , V_383 ) ;
F_176 (rocker->fdb_tbl, bkt, tmp, found, entry) {
if ( V_341 -> V_234 . V_158 != V_6 -> V_158 )
continue;
if ( V_497 < V_495 -> args [ 0 ] )
goto V_498;
V_166 = V_341 -> V_234 . V_166 ;
V_7 = F_5 ( V_6 , V_341 -> V_234 . V_1 ) ;
V_40 = F_275 ( V_133 , V_6 , V_166 , V_7 ,
F_283 ( V_495 -> V_133 ) . V_477 ,
V_495 -> V_480 -> V_499 ,
V_500 , V_501 ) ;
if ( V_40 < 0 )
break;
V_498:
++ V_497 ;
}
F_139 ( & V_19 -> V_324 , V_383 ) ;
return V_497 ;
}
static int F_284 ( struct V_141 * V_28 ,
struct V_479 * V_480 , T_2 V_167 )
{
struct V_6 * V_6 = F_253 ( V_28 ) ;
struct V_475 * V_502 ;
struct V_475 * V_219 ;
int V_40 ;
V_502 = F_285 ( V_480 , sizeof( struct V_503 ) ,
V_504 ) ;
if ( V_502 ) {
V_219 = F_286 ( V_502 , V_505 ) ;
if ( V_219 ) {
if ( F_287 ( V_219 ) < sizeof( T_9 ) )
return - V_98 ;
if ( F_288 ( V_219 ) )
V_6 -> V_229 |= V_230 ;
else
V_6 -> V_229 &= ~ V_230 ;
V_40 = F_155 ( V_6 ) ;
if ( V_40 )
return V_40 ;
}
V_219 = F_286 ( V_502 , V_506 ) ;
if ( V_219 ) {
if ( F_287 ( V_219 ) < sizeof( T_9 ) )
return - V_98 ;
if ( F_288 ( V_219 ) )
V_6 -> V_229 |= V_416 ;
else
V_6 -> V_229 &= ~ V_416 ;
}
}
return 0 ;
}
static int F_289 ( struct V_132 * V_133 , T_4 V_507 , T_4 V_478 ,
struct V_141 * V_28 ,
T_4 V_508 , int V_509 )
{
struct V_6 * V_6 = F_253 ( V_28 ) ;
T_2 V_510 = V_511 ;
T_4 V_512 = V_230 | V_416 ;
return F_290 ( V_133 , V_507 , V_478 , V_28 , V_510 ,
V_6 -> V_229 , V_512 ,
V_509 ) ;
}
static int F_291 ( struct V_141 * V_28 ,
char * V_33 , T_7 V_65 )
{
struct V_6 * V_6 = F_253 ( V_28 ) ;
struct V_222 V_223 = { . V_33 = V_33 , . V_65 = V_65 } ;
int V_40 ;
V_40 = F_137 ( V_6 -> V_19 , V_6 ,
F_140 , NULL ,
F_145 ,
& V_223 , false ) ;
return V_40 ? - V_101 : 0 ;
}
static int F_292 ( struct V_141 * V_28 ,
struct V_513 * V_514 )
{
struct V_6 * V_6 = F_253 ( V_28 ) ;
struct V_19 * V_19 = V_6 -> V_19 ;
V_514 -> V_515 = sizeof( V_19 -> V_516 . V_517 ) ;
memcpy ( & V_514 -> V_517 , & V_19 -> V_516 . V_517 , V_514 -> V_515 ) ;
return 0 ;
}
static int F_293 ( struct V_141 * V_28 , T_9 V_420 )
{
struct V_6 * V_6 = F_253 ( V_28 ) ;
return F_244 ( V_6 , V_420 ) ;
}
static int F_294 ( struct V_141 * V_28 ,
T_10 V_366 , int V_435 ,
struct V_436 * V_437 ,
T_9 V_518 , T_9 type ,
T_4 V_509 , T_4 V_438 )
{
struct V_6 * V_6 = F_253 ( V_28 ) ;
int V_167 = 0 ;
return F_251 ( V_6 , V_366 , V_435 ,
V_437 , V_438 , V_167 ) ;
}
static int F_295 ( struct V_141 * V_28 ,
T_10 V_366 , int V_435 ,
struct V_436 * V_437 ,
T_9 V_518 , T_9 type , T_4 V_438 )
{
struct V_6 * V_6 = F_253 ( V_28 ) ;
int V_167 = V_348 ;
return F_251 ( V_6 , V_366 , V_435 ,
V_437 , V_438 , V_167 ) ;
}
static int F_296 ( struct V_141 * V_28 ,
struct V_196 * V_197 )
{
struct V_6 * V_6 = F_253 ( V_28 ) ;
return F_151 ( V_6 , V_197 ) ;
}
static int F_297 ( struct V_141 * V_28 ,
struct V_196 * V_197 )
{
struct V_6 * V_6 = F_253 ( V_28 ) ;
return F_153 ( V_6 , V_197 ) ;
}
static void F_298 ( struct V_141 * V_28 ,
struct V_519 * V_520 )
{
F_299 ( V_520 -> V_521 , V_58 , sizeof( V_520 -> V_521 ) ) ;
F_299 ( V_520 -> V_522 , V_523 , sizeof( V_520 -> V_522 ) ) ;
}
static void F_300 ( struct V_141 * V_524 , T_4 V_525 ,
T_9 * V_75 )
{
T_9 * V_397 = V_75 ;
int V_36 ;
switch ( V_525 ) {
case V_526 :
for ( V_36 = 0 ; V_36 < F_301 ( V_527 ) ; V_36 ++ ) {
memcpy ( V_397 , V_527 [ V_36 ] . V_225 , V_528 ) ;
V_397 += V_528 ;
}
break;
}
}
static int
F_302 ( struct V_19 * V_19 ,
struct V_6 * V_6 ,
struct V_73 * V_74 ,
void * V_190 )
{
struct V_61 * V_529 ;
if ( F_63 ( V_74 , V_192 ,
V_530 ) )
return - V_83 ;
V_529 = F_68 ( V_74 , V_194 ) ;
if ( ! V_529 )
return - V_83 ;
if ( F_65 ( V_74 , V_531 ,
V_6 -> V_158 ) )
return - V_83 ;
F_69 ( V_74 , V_529 ) ;
return 0 ;
}
static int
F_303 ( struct V_19 * V_19 ,
struct V_6 * V_6 ,
struct V_73 * V_74 ,
void * V_190 )
{
struct V_61 * V_142 [ V_198 + 1 ] ;
struct V_61 * V_532 [ V_533 + 1 ] ;
struct V_61 * V_534 ;
T_4 V_158 ;
T_5 * V_75 = V_190 ;
int V_36 ;
F_58 ( V_142 , V_198 , V_74 ) ;
if ( ! V_142 [ V_194 ] )
return - V_29 ;
F_57 ( V_532 , V_533 ,
V_142 [ V_194 ] ) ;
if ( ! V_532 [ V_531 ] )
return - V_29 ;
V_158 = F_53 ( V_532 [ V_531 ] ) ;
if ( V_158 != V_6 -> V_158 )
return - V_29 ;
for ( V_36 = 0 ; V_36 < F_301 ( V_527 ) ; V_36 ++ ) {
V_534 = V_532 [ V_527 [ V_36 ] . type ] ;
if ( ! V_534 )
continue;
V_75 [ V_36 ] = F_54 ( V_534 ) ;
}
return 0 ;
}
static int F_304 ( struct V_6 * V_6 ,
void * V_190 )
{
return F_137 ( V_6 -> V_19 , V_6 ,
F_302 , NULL ,
F_303 ,
V_190 , false ) ;
}
static void F_305 ( struct V_141 * V_28 ,
struct V_535 * V_466 , T_5 * V_75 )
{
struct V_6 * V_6 = F_253 ( V_28 ) ;
if ( F_304 ( V_6 , V_75 ) != 0 ) {
int V_36 ;
for ( V_36 = 0 ; V_36 < F_301 ( V_527 ) ; ++ V_36 )
V_75 [ V_36 ] = 0 ;
}
return;
}
static int F_306 ( struct V_141 * V_524 , int V_536 )
{
switch ( V_536 ) {
case V_526 :
return V_537 ;
default:
return - V_101 ;
}
}
static struct V_6 * F_307 ( struct V_538 * V_539 )
{
return F_235 ( V_539 , struct V_6 , V_181 ) ;
}
static int F_308 ( struct V_538 * V_539 , int V_540 )
{
struct V_6 * V_6 = F_307 ( V_539 ) ;
struct V_19 * V_19 = V_6 -> V_19 ;
struct V_73 * V_74 ;
T_4 V_111 = 0 ;
int V_40 ;
while ( ( V_74 = F_82 ( & V_6 -> V_146 ) ) ) {
struct V_132 * V_133 ;
V_40 = F_72 ( V_74 ) ;
if ( V_40 && F_262 () )
F_116 ( V_6 -> V_28 , L_40 ,
V_40 ) ;
F_259 ( V_6 , V_74 ) ;
V_133 = F_75 ( V_74 ) ;
if ( V_40 == 0 ) {
V_6 -> V_28 -> V_466 . V_541 ++ ;
V_6 -> V_28 -> V_466 . V_542 += V_133 -> V_65 ;
} else
V_6 -> V_28 -> V_466 . V_543 ++ ;
F_109 ( V_133 ) ;
V_111 ++ ;
}
if ( V_111 && F_309 ( V_6 -> V_28 ) )
F_310 ( V_6 -> V_28 ) ;
F_311 ( V_539 ) ;
F_83 ( V_19 , & V_6 -> V_146 , V_111 ) ;
return 0 ;
}
static int F_312 ( struct V_19 * V_19 ,
struct V_6 * V_6 ,
struct V_73 * V_74 )
{
struct V_61 * V_142 [ V_143 + 1 ] ;
struct V_132 * V_133 = F_75 ( V_74 ) ;
T_7 V_544 ;
if ( ! V_133 )
return - V_91 ;
F_58 ( V_142 , V_143 , V_74 ) ;
if ( ! V_142 [ V_545 ] )
return - V_98 ;
F_110 ( V_19 , V_142 ) ;
V_544 = F_51 ( V_142 [ V_545 ] ) ;
F_313 ( V_133 , V_544 ) ;
V_133 -> V_546 = F_314 ( V_133 , V_6 -> V_28 ) ;
V_6 -> V_28 -> V_466 . V_547 ++ ;
V_6 -> V_28 -> V_466 . V_548 += V_133 -> V_65 ;
F_315 ( V_133 ) ;
return F_107 ( V_19 , V_6 , V_74 ) ;
}
static struct V_6 * F_316 ( struct V_538 * V_539 )
{
return F_235 ( V_539 , struct V_6 , V_182 ) ;
}
static int F_317 ( struct V_538 * V_539 , int V_540 )
{
struct V_6 * V_6 = F_316 ( V_539 ) ;
struct V_19 * V_19 = V_6 -> V_19 ;
struct V_73 * V_74 ;
T_4 V_111 = 0 ;
int V_40 ;
while ( V_111 < V_540 &&
( V_74 = F_82 ( & V_6 -> V_144 ) ) ) {
V_40 = F_72 ( V_74 ) ;
if ( V_40 ) {
if ( F_262 () )
F_116 ( V_6 -> V_28 , L_41 ,
V_40 ) ;
} else {
V_40 = F_312 ( V_19 , V_6 ,
V_74 ) ;
if ( V_40 && F_262 () )
F_116 ( V_6 -> V_28 , L_42 ,
V_40 ) ;
}
if ( V_40 )
V_6 -> V_28 -> V_466 . V_549 ++ ;
F_73 ( V_74 ) ;
F_79 ( V_19 , & V_6 -> V_144 , V_74 ) ;
V_111 ++ ;
}
if ( V_111 < V_540 )
F_311 ( V_539 ) ;
F_83 ( V_19 , & V_6 -> V_144 , V_111 ) ;
return V_111 ;
}
static void F_318 ( struct V_6 * V_6 )
{
struct V_19 * V_19 = V_6 -> V_19 ;
T_5 V_550 = F_29 ( V_19 , V_551 ) ;
bool V_160 ;
V_160 = V_550 & ( 1 << V_6 -> V_158 ) ;
if ( V_160 )
F_124 ( V_6 -> V_28 ) ;
else
F_127 ( V_6 -> V_28 ) ;
}
static void F_319 ( struct V_19 * V_19 )
{
struct V_6 * V_6 ;
int V_36 ;
for ( V_36 = 0 ; V_36 < V_19 -> V_163 ; V_36 ++ ) {
V_6 = V_19 -> V_164 [ V_36 ] ;
F_233 ( V_6 , V_348 ) ;
F_320 ( V_6 -> V_28 ) ;
}
F_13 ( V_19 -> V_164 ) ;
}
static void F_321 ( struct V_19 * V_19 ,
struct V_6 * V_6 )
{
struct V_23 * V_24 = V_19 -> V_24 ;
int V_40 ;
V_40 = F_152 ( V_6 ,
V_6 -> V_28 -> V_388 ) ;
if ( V_40 ) {
F_322 ( & V_24 -> V_28 , L_43 ) ;
F_323 ( V_6 -> V_28 ) ;
}
}
static int F_324 ( struct V_19 * V_19 , unsigned int V_22 )
{
struct V_23 * V_24 = V_19 -> V_24 ;
struct V_6 * V_6 ;
struct V_141 * V_28 ;
int V_40 ;
V_28 = F_325 ( sizeof( struct V_6 ) ) ;
if ( ! V_28 )
return - V_44 ;
V_6 = F_253 ( V_28 ) ;
V_6 -> V_28 = V_28 ;
V_6 -> V_19 = V_19 ;
V_6 -> V_22 = V_22 ;
V_6 -> V_158 = V_22 + 1 ;
V_6 -> V_229 = V_230 | V_416 ;
F_321 ( V_19 , V_6 ) ;
V_28 -> V_552 = & V_553 ;
V_28 -> V_554 = & V_555 ;
V_28 -> V_556 = & V_557 ;
F_326 ( V_28 , & V_6 -> V_181 , F_308 ,
V_558 ) ;
F_326 ( V_28 , & V_6 -> V_182 , F_317 ,
V_558 ) ;
F_318 ( V_6 ) ;
V_28 -> V_559 |= V_560 |
V_561 |
V_562 ;
V_40 = F_327 ( V_28 ) ;
if ( V_40 ) {
F_27 ( & V_24 -> V_28 , L_44 ) ;
goto V_563;
}
V_19 -> V_164 [ V_22 ] = V_6 ;
F_155 ( V_6 ) ;
V_6 -> V_9 =
F_248 ( V_6 , V_28 -> V_430 ) ;
V_40 = F_233 ( V_6 , 0 ) ;
if ( V_40 ) {
F_27 ( & V_24 -> V_28 , L_45 ) ;
goto V_564;
}
return 0 ;
V_564:
F_320 ( V_28 ) ;
V_563:
F_328 ( V_28 ) ;
return V_40 ;
}
static int F_329 ( struct V_19 * V_19 )
{
int V_36 ;
T_7 V_565 ;
int V_40 ;
V_565 = sizeof( struct V_6 * ) * V_19 -> V_163 ;
V_19 -> V_164 = F_11 ( V_565 , V_42 ) ;
if ( ! V_19 -> V_164 )
return - V_44 ;
for ( V_36 = 0 ; V_36 < V_19 -> V_163 ; V_36 ++ ) {
V_40 = F_324 ( V_19 , V_36 ) ;
if ( V_40 )
goto V_566;
}
return 0 ;
V_566:
F_319 ( V_19 ) ;
return V_40 ;
}
static int F_330 ( struct V_19 * V_19 )
{
struct V_23 * V_24 = V_19 -> V_24 ;
int V_21 ;
int V_36 ;
int V_40 ;
V_21 = F_331 ( V_24 ) ;
if ( V_21 < 0 )
return V_21 ;
if ( V_21 != F_332 ( V_19 -> V_163 ) )
return - V_98 ;
V_19 -> V_21 = F_333 ( V_21 ,
sizeof( struct V_567 ) ,
V_42 ) ;
if ( ! V_19 -> V_21 )
return - V_44 ;
for ( V_36 = 0 ; V_36 < V_21 ; V_36 ++ )
V_19 -> V_21 [ V_36 ] . V_232 = V_36 ;
V_40 = F_334 ( V_24 , V_19 -> V_21 , V_21 ) ;
if ( V_40 < 0 )
goto V_568;
return 0 ;
V_568:
F_13 ( V_19 -> V_21 ) ;
return V_40 ;
}
static void F_335 ( struct V_19 * V_19 )
{
F_336 ( V_19 -> V_24 ) ;
F_13 ( V_19 -> V_21 ) ;
}
static int F_337 ( struct V_23 * V_24 , const struct V_569 * V_517 )
{
struct V_19 * V_19 ;
int V_40 ;
V_19 = F_32 ( sizeof( * V_19 ) , V_42 ) ;
if ( ! V_19 )
return - V_44 ;
V_40 = F_338 ( V_24 ) ;
if ( V_40 ) {
F_27 ( & V_24 -> V_28 , L_46 ) ;
goto V_570;
}
V_40 = F_339 ( V_24 , V_58 ) ;
if ( V_40 ) {
F_27 ( & V_24 -> V_28 , L_47 ) ;
goto V_571;
}
V_40 = F_340 ( V_24 , F_341 ( 64 ) ) ;
if ( ! V_40 ) {
V_40 = F_342 ( V_24 , F_341 ( 64 ) ) ;
if ( V_40 ) {
F_27 ( & V_24 -> V_28 , L_48 ) ;
goto V_572;
}
} else {
V_40 = F_340 ( V_24 , F_341 ( 32 ) ) ;
if ( V_40 ) {
F_27 ( & V_24 -> V_28 , L_49 ) ;
goto V_572;
}
}
if ( F_343 ( V_24 , 0 ) < V_573 ) {
F_27 ( & V_24 -> V_28 , L_50 ) ;
V_40 = - V_98 ;
goto V_574;
}
V_19 -> V_575 = F_344 ( F_345 ( V_24 , 0 ) ,
F_343 ( V_24 , 0 ) ) ;
if ( ! V_19 -> V_575 ) {
F_27 ( & V_24 -> V_28 , L_51 ) ;
V_40 = - V_29 ;
goto V_576;
}
F_346 ( V_24 ) ;
V_19 -> V_24 = V_24 ;
F_347 ( V_24 , V_19 ) ;
V_19 -> V_163 = F_26 ( V_19 , V_577 ) ;
V_40 = F_330 ( V_19 ) ;
if ( V_40 ) {
F_27 ( & V_24 -> V_28 , L_52 ) ;
goto V_578;
}
V_40 = F_39 ( V_19 ) ;
if ( V_40 ) {
F_27 ( & V_24 -> V_28 , L_53 ) ;
goto V_579;
}
F_25 ( V_19 , V_580 , V_581 ) ;
V_40 = F_102 ( V_19 ) ;
if ( V_40 )
goto V_582;
V_40 = F_40 ( F_18 ( V_19 , V_583 ) ,
F_120 , 0 ,
V_58 , V_19 ) ;
if ( V_40 ) {
F_27 ( & V_24 -> V_28 , L_54 ) ;
goto V_584;
}
V_40 = F_40 ( F_18 ( V_19 , V_585 ) ,
F_133 , 0 ,
V_58 , V_19 ) ;
if ( V_40 ) {
F_27 ( & V_24 -> V_28 , L_55 ) ;
goto V_586;
}
V_19 -> V_516 . V_517 = F_29 ( V_19 , V_587 ) ;
V_40 = F_173 ( V_19 ) ;
if ( V_40 ) {
F_27 ( & V_24 -> V_28 , L_56 ) ;
goto V_588;
}
V_40 = F_329 ( V_19 ) ;
if ( V_40 ) {
F_27 ( & V_24 -> V_28 , L_57 ) ;
goto V_589;
}
F_348 ( & V_24 -> V_28 , L_58 , V_19 -> V_516 . V_517 ) ;
return 0 ;
V_589:
F_175 ( V_19 ) ;
V_588:
V_60 ( F_18 ( V_19 , V_585 ) , V_19 ) ;
V_586:
V_60 ( F_18 ( V_19 , V_583 ) , V_19 ) ;
V_584:
F_104 ( V_19 ) ;
V_582:
V_579:
F_335 ( V_19 ) ;
V_578:
F_349 ( V_19 -> V_575 ) ;
V_576:
V_574:
V_572:
F_350 ( V_24 ) ;
V_571:
F_351 ( V_24 ) ;
V_570:
F_13 ( V_19 ) ;
return V_40 ;
}
static void F_352 ( struct V_23 * V_24 )
{
struct V_19 * V_19 = F_353 ( V_24 ) ;
F_175 ( V_19 ) ;
F_25 ( V_19 , V_580 , V_581 ) ;
F_319 ( V_19 ) ;
V_60 ( F_18 ( V_19 , V_585 ) , V_19 ) ;
V_60 ( F_18 ( V_19 , V_583 ) , V_19 ) ;
F_104 ( V_19 ) ;
F_335 ( V_19 ) ;
F_349 ( V_19 -> V_575 ) ;
F_350 ( V_19 -> V_24 ) ;
F_351 ( V_19 -> V_24 ) ;
F_13 ( V_19 ) ;
}
static bool F_354 ( struct V_141 * V_28 )
{
return V_28 -> V_552 == & V_553 ;
}
static int F_355 ( struct V_6 * V_6 ,
struct V_141 * V_264 )
{
int V_40 ;
F_249 ( V_6 ,
V_6 -> V_28 -> V_430 ) ;
V_6 -> V_10 = V_264 ;
V_40 = F_230 ( V_6 , V_348 , 0 ) ;
if ( V_40 )
return V_40 ;
V_6 -> V_9 =
F_248 ( V_6 ,
V_264 -> V_430 ) ;
return F_230 ( V_6 , 0 , 0 ) ;
}
static int F_356 ( struct V_6 * V_6 )
{
int V_40 ;
F_249 ( V_6 ,
V_6 -> V_10 -> V_430 ) ;
V_6 -> V_10 = NULL ;
V_40 = F_230 ( V_6 , V_348 , 0 ) ;
if ( V_40 )
return V_40 ;
V_6 -> V_9 =
F_248 ( V_6 ,
V_6 -> V_28 -> V_430 ) ;
V_40 = F_230 ( V_6 , 0 , 0 ) ;
if ( V_40 )
return V_40 ;
if ( V_6 -> V_28 -> V_167 & V_590 )
V_40 = F_245 ( V_6 ) ;
return V_40 ;
}
static int F_357 ( struct V_141 * V_28 )
{
struct V_6 * V_6 = F_253 ( V_28 ) ;
struct V_141 * V_591 = F_358 ( V_28 ) ;
int V_40 = 0 ;
if ( V_591 && V_591 -> V_592 &&
! strcmp ( V_591 -> V_592 -> V_593 , L_59 ) )
V_40 = F_355 ( V_6 , V_591 ) ;
else if ( F_6 ( V_6 ) )
V_40 = F_356 ( V_6 ) ;
return V_40 ;
}
static int F_359 ( struct V_594 * V_595 ,
unsigned long V_596 , void * V_106 )
{
struct V_141 * V_28 ;
int V_40 ;
switch ( V_596 ) {
case V_597 :
V_28 = F_360 ( V_106 ) ;
if ( ! F_354 ( V_28 ) )
return V_598 ;
V_40 = F_357 ( V_28 ) ;
if ( V_40 )
F_361 ( V_28 ,
L_60 ,
V_40 ) ;
break;
}
return V_598 ;
}
static int F_362 ( struct V_141 * V_28 , struct V_389 * V_390 )
{
struct V_6 * V_6 = F_253 ( V_28 ) ;
int V_167 = ( V_390 -> V_393 & V_394 ) ? 0 : V_348 ;
T_10 V_380 = * ( T_10 * ) V_390 -> V_599 ;
return F_211 ( V_6 , V_167 , V_380 , V_390 -> V_395 ) ;
}
static int F_363 ( struct V_594 * V_595 ,
unsigned long V_596 , void * V_106 )
{
struct V_141 * V_28 ;
struct V_389 * V_390 = V_106 ;
int V_40 ;
switch ( V_596 ) {
case V_600 :
if ( V_390 -> V_601 != & V_392 )
return V_598 ;
V_28 = V_390 -> V_28 ;
if ( ! F_354 ( V_28 ) )
return V_598 ;
V_40 = F_362 ( V_28 , V_390 ) ;
if ( V_40 )
F_361 ( V_28 ,
L_61 ,
V_40 ) ;
break;
}
return V_598 ;
}
static int T_14 F_364 ( void )
{
int V_40 ;
F_365 ( & V_602 ) ;
F_366 ( & V_603 ) ;
V_40 = F_367 ( & V_604 ) ;
if ( V_40 )
goto V_605;
return 0 ;
V_605:
F_368 ( & V_603 ) ;
F_368 ( & V_602 ) ;
return V_40 ;
}
static void T_15 F_369 ( void )
{
F_370 ( & V_603 ) ;
F_368 ( & V_602 ) ;
F_371 ( & V_604 ) ;
}
