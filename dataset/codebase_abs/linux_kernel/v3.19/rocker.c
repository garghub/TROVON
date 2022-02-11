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
return - ( V_74 -> V_76 -> V_87 & ~ V_88 ) ;
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
return ( void * ) V_74 -> V_76 -> V_89 ;
}
static void F_76 ( struct V_73 * V_74 ,
void * V_90 )
{
V_74 -> V_76 -> V_89 = ( long ) V_90 ;
}
static struct V_73 *
F_77 ( struct V_91 * V_92 )
{
static struct V_73 * V_74 ;
T_4 V_71 = F_71 ( V_92 -> V_71 , V_92 -> V_35 ) ;
V_74 = & V_92 -> V_74 [ V_92 -> V_71 ] ;
if ( V_71 == V_92 -> V_93 )
return NULL ;
V_74 -> V_77 = 0 ;
return V_74 ;
}
static void F_78 ( struct V_73 * V_74 )
{
V_74 -> V_76 -> V_94 = V_74 -> V_81 ;
V_74 -> V_76 -> V_77 = V_74 -> V_77 ;
}
static void F_79 ( struct V_19 * V_19 ,
struct V_91 * V_92 ,
struct V_73 * V_74 )
{
T_4 V_71 = F_71 ( V_92 -> V_71 , V_92 -> V_35 ) ;
F_80 ( V_71 == V_92 -> V_93 ) ;
F_78 ( V_74 ) ;
V_92 -> V_71 = V_71 ;
F_25 ( V_19 , F_81 ( V_92 -> type ) , V_71 ) ;
}
static struct V_73 *
F_82 ( struct V_91 * V_92 )
{
static struct V_73 * V_74 ;
if ( V_92 -> V_93 == V_92 -> V_71 )
return NULL ;
V_74 = & V_92 -> V_74 [ V_92 -> V_93 ] ;
if ( ! F_74 ( V_74 ) )
return NULL ;
V_92 -> V_93 = F_71 ( V_92 -> V_93 , V_92 -> V_35 ) ;
V_74 -> V_77 = V_74 -> V_76 -> V_77 ;
return V_74 ;
}
static void F_83 ( struct V_19 * V_19 ,
struct V_91 * V_92 ,
T_4 V_95 )
{
if ( V_95 )
F_25 ( V_19 , F_84 ( V_92 -> type ) , V_95 ) ;
}
static unsigned long F_85 ( T_7 V_35 )
{
return F_86 ( V_96 ,
F_87 ( F_88 ( V_35 ) , V_97 ) ) ;
}
static int F_89 ( struct V_19 * V_19 ,
unsigned int type ,
T_7 V_35 ,
struct V_91 * V_92 )
{
int V_36 ;
F_80 ( V_35 != F_85 ( V_35 ) ) ;
V_92 -> V_35 = V_35 ;
V_92 -> type = type ;
V_92 -> V_71 = 0 ;
V_92 -> V_93 = 0 ;
V_92 -> V_74 = F_90 ( V_92 -> V_35 , sizeof( * V_92 -> V_74 ) ,
V_42 ) ;
if ( ! V_92 -> V_74 )
return - V_44 ;
V_92 -> V_76 = F_91 ( V_19 -> V_24 ,
V_92 -> V_35 * sizeof( * V_92 -> V_76 ) ,
& V_92 -> V_98 ) ;
if ( ! V_92 -> V_76 ) {
F_13 ( V_92 -> V_74 ) ;
return - V_44 ;
}
for ( V_36 = 0 ; V_36 < V_92 -> V_35 ; V_36 ++ )
V_92 -> V_74 [ V_36 ] . V_76 = & V_92 -> V_76 [ V_36 ] ;
F_25 ( V_19 , F_92 ( V_92 -> type ) ,
V_99 ) ;
F_28 ( V_19 , F_93 ( V_92 -> type ) , V_92 -> V_98 ) ;
F_25 ( V_19 , F_94 ( V_92 -> type ) , V_92 -> V_35 ) ;
return 0 ;
}
static void F_95 ( struct V_19 * V_19 ,
struct V_91 * V_92 )
{
F_28 ( V_19 , F_93 ( V_92 -> type ) , 0 ) ;
F_96 ( V_19 -> V_24 ,
V_92 -> V_35 * sizeof( struct V_100 ) ,
V_92 -> V_76 , V_92 -> V_98 ) ;
F_13 ( V_92 -> V_74 ) ;
}
static void F_97 ( struct V_19 * V_19 ,
struct V_91 * V_92 )
{
int V_36 ;
F_80 ( V_92 -> V_71 || V_92 -> V_93 ) ;
for ( V_36 = 0 ; V_36 < V_92 -> V_35 - 1 ; V_36 ++ )
F_79 ( V_19 , V_92 , & V_92 -> V_74 [ V_36 ] ) ;
F_78 ( & V_92 -> V_74 [ V_36 ] ) ;
}
static int F_98 ( struct V_19 * V_19 ,
struct V_91 * V_92 ,
int V_101 , T_7 V_94 )
{
struct V_23 * V_24 = V_19 -> V_24 ;
int V_36 ;
int V_40 ;
for ( V_36 = 0 ; V_36 < V_92 -> V_35 ; V_36 ++ ) {
struct V_73 * V_74 = & V_92 -> V_74 [ V_36 ] ;
struct V_100 * V_76 = & V_92 -> V_76 [ V_36 ] ;
T_6 V_32 ;
char * V_33 ;
V_33 = F_32 ( V_94 , V_42 | V_43 ) ;
if ( ! V_33 ) {
V_40 = - V_44 ;
goto V_102;
}
V_32 = F_33 ( V_24 , V_33 , V_94 , V_101 ) ;
if ( F_34 ( V_24 , V_32 ) ) {
F_13 ( V_33 ) ;
V_40 = - V_29 ;
goto V_102;
}
V_74 -> V_75 = V_33 ;
V_74 -> V_81 = V_94 ;
F_99 ( V_74 , V_98 , V_32 ) ;
V_76 -> V_103 = V_32 ;
V_76 -> V_94 = V_94 ;
}
return 0 ;
V_102:
for ( V_36 -- ; V_36 >= 0 ; V_36 -- ) {
struct V_73 * V_74 = & V_92 -> V_74 [ V_36 ] ;
F_36 ( V_24 , F_100 ( V_74 , V_98 ) ,
V_74 -> V_81 , V_101 ) ;
F_13 ( V_74 -> V_75 ) ;
}
return V_40 ;
}
static void F_101 ( struct V_19 * V_19 ,
struct V_91 * V_92 ,
int V_101 )
{
struct V_23 * V_24 = V_19 -> V_24 ;
int V_36 ;
for ( V_36 = 0 ; V_36 < V_92 -> V_35 ; V_36 ++ ) {
struct V_73 * V_74 = & V_92 -> V_74 [ V_36 ] ;
struct V_100 * V_76 = & V_92 -> V_76 [ V_36 ] ;
V_76 -> V_103 = 0 ;
V_76 -> V_94 = 0 ;
F_36 ( V_24 , F_100 ( V_74 , V_98 ) ,
V_74 -> V_81 , V_101 ) ;
F_13 ( V_74 -> V_75 ) ;
}
}
static int F_102 ( struct V_19 * V_19 )
{
struct V_23 * V_24 = V_19 -> V_24 ;
int V_40 ;
V_40 = F_89 ( V_19 , V_104 ,
V_105 ,
& V_19 -> V_106 ) ;
if ( V_40 ) {
F_27 ( & V_24 -> V_28 , L_8 ) ;
return V_40 ;
}
F_103 ( & V_19 -> V_107 ) ;
V_40 = F_98 ( V_19 , & V_19 -> V_106 ,
V_45 , V_108 ) ;
if ( V_40 ) {
F_27 ( & V_24 -> V_28 , L_9 ) ;
goto V_109;
}
V_40 = F_89 ( V_19 , V_110 ,
V_111 ,
& V_19 -> V_112 ) ;
if ( V_40 ) {
F_27 ( & V_24 -> V_28 , L_10 ) ;
goto V_113;
}
V_40 = F_98 ( V_19 , & V_19 -> V_112 ,
V_114 , V_108 ) ;
if ( V_40 ) {
F_27 ( & V_24 -> V_28 , L_11 ) ;
goto V_115;
}
F_97 ( V_19 , & V_19 -> V_112 ) ;
return 0 ;
V_115:
F_95 ( V_19 , & V_19 -> V_112 ) ;
V_113:
F_101 ( V_19 , & V_19 -> V_106 ,
V_45 ) ;
V_109:
F_95 ( V_19 , & V_19 -> V_106 ) ;
return V_40 ;
}
static void F_104 ( struct V_19 * V_19 )
{
F_101 ( V_19 , & V_19 -> V_112 ,
V_45 ) ;
F_95 ( V_19 , & V_19 -> V_112 ) ;
F_101 ( V_19 , & V_19 -> V_106 ,
V_45 ) ;
F_95 ( V_19 , & V_19 -> V_106 ) ;
}
static int F_105 ( struct V_19 * V_19 ,
struct V_6 * V_6 ,
struct V_73 * V_74 ,
struct V_116 * V_117 , T_7 V_70 )
{
struct V_23 * V_24 = V_19 -> V_24 ;
T_6 V_32 ;
V_32 = F_33 ( V_24 , V_117 -> V_75 , V_70 ,
V_114 ) ;
if ( F_34 ( V_24 , V_32 ) )
return - V_29 ;
if ( F_67 ( V_74 , V_118 , V_32 ) )
goto V_119;
if ( F_63 ( V_74 , V_120 , V_70 ) )
goto V_119;
return 0 ;
V_119:
F_36 ( V_24 , V_32 , V_70 , V_114 ) ;
V_74 -> V_77 = 0 ;
return - V_83 ;
}
static T_7 F_106 ( struct V_6 * V_6 )
{
return V_6 -> V_28 -> V_121 + V_122 + V_123 + V_124 ;
}
static int F_107 ( struct V_19 * V_19 ,
struct V_6 * V_6 ,
struct V_73 * V_74 )
{
struct V_125 * V_28 = V_6 -> V_28 ;
struct V_116 * V_117 ;
T_7 V_70 = F_106 ( V_6 ) ;
int V_40 ;
F_76 ( V_74 , NULL ) ;
V_74 -> V_77 = 0 ;
V_117 = F_108 ( V_28 , V_70 ) ;
if ( ! V_117 )
return - V_44 ;
V_40 = F_105 ( V_19 , V_6 , V_74 ,
V_117 , V_70 ) ;
if ( V_40 ) {
F_109 ( V_117 ) ;
return V_40 ;
}
F_76 ( V_74 , V_117 ) ;
return 0 ;
}
static void F_110 ( struct V_19 * V_19 ,
struct V_61 * * V_126 )
{
struct V_23 * V_24 = V_19 -> V_24 ;
T_6 V_32 ;
T_7 V_65 ;
if ( ! V_126 [ V_118 ] ||
! V_126 [ V_120 ] )
return;
V_32 = F_54 ( V_126 [ V_118 ] ) ;
V_65 = F_51 ( V_126 [ V_120 ] ) ;
F_36 ( V_24 , V_32 , V_65 , V_114 ) ;
}
static void F_111 ( struct V_19 * V_19 ,
struct V_73 * V_74 )
{
struct V_61 * V_126 [ V_127 + 1 ] ;
struct V_116 * V_117 = F_75 ( V_74 ) ;
if ( ! V_117 )
return;
F_58 ( V_126 , V_127 , V_74 ) ;
F_110 ( V_19 , V_126 ) ;
F_109 ( V_117 ) ;
}
static int F_112 ( struct V_19 * V_19 ,
struct V_6 * V_6 )
{
struct V_91 * V_128 = & V_6 -> V_128 ;
int V_36 ;
int V_40 ;
for ( V_36 = 0 ; V_36 < V_128 -> V_35 ; V_36 ++ ) {
V_40 = F_107 ( V_19 , V_6 ,
& V_128 -> V_74 [ V_36 ] ) ;
if ( V_40 )
goto V_102;
}
return 0 ;
V_102:
for ( V_36 -- ; V_36 >= 0 ; V_36 -- )
F_111 ( V_19 , & V_128 -> V_74 [ V_36 ] ) ;
return V_40 ;
}
static void F_113 ( struct V_19 * V_19 ,
struct V_6 * V_6 )
{
struct V_91 * V_128 = & V_6 -> V_128 ;
int V_36 ;
for ( V_36 = 0 ; V_36 < V_128 -> V_35 ; V_36 ++ )
F_111 ( V_19 , & V_128 -> V_74 [ V_36 ] ) ;
}
static int F_114 ( struct V_6 * V_6 )
{
struct V_19 * V_19 = V_6 -> V_19 ;
int V_40 ;
V_40 = F_89 ( V_19 ,
F_115 ( V_6 -> V_22 ) ,
V_129 ,
& V_6 -> V_130 ) ;
if ( V_40 ) {
F_116 ( V_6 -> V_28 , L_12 ) ;
return V_40 ;
}
V_40 = F_98 ( V_19 , & V_6 -> V_130 ,
V_131 ,
V_132 ) ;
if ( V_40 ) {
F_116 ( V_6 -> V_28 , L_13 ) ;
goto V_133;
}
V_40 = F_89 ( V_19 ,
F_117 ( V_6 -> V_22 ) ,
V_134 ,
& V_6 -> V_128 ) ;
if ( V_40 ) {
F_116 ( V_6 -> V_28 , L_14 ) ;
goto V_135;
}
V_40 = F_98 ( V_19 , & V_6 -> V_128 ,
V_45 ,
V_136 ) ;
if ( V_40 ) {
F_116 ( V_6 -> V_28 , L_15 ) ;
goto V_137;
}
V_40 = F_112 ( V_19 , V_6 ) ;
if ( V_40 ) {
F_116 ( V_6 -> V_28 , L_16 ) ;
goto V_138;
}
F_97 ( V_19 , & V_6 -> V_128 ) ;
return 0 ;
V_138:
F_101 ( V_19 , & V_6 -> V_128 ,
V_45 ) ;
V_137:
F_95 ( V_19 , & V_6 -> V_128 ) ;
V_135:
F_101 ( V_19 , & V_6 -> V_130 ,
V_131 ) ;
V_133:
F_95 ( V_19 , & V_6 -> V_130 ) ;
return V_40 ;
}
static void F_118 ( struct V_6 * V_6 )
{
struct V_19 * V_19 = V_6 -> V_19 ;
F_113 ( V_19 , V_6 ) ;
F_101 ( V_19 , & V_6 -> V_128 ,
V_45 ) ;
F_95 ( V_19 , & V_6 -> V_128 ) ;
F_101 ( V_19 , & V_6 -> V_130 ,
V_131 ) ;
F_95 ( V_19 , & V_6 -> V_130 ) ;
}
static void F_119 ( struct V_6 * V_6 , bool V_139 )
{
T_5 V_140 = F_29 ( V_6 -> V_19 , V_141 ) ;
if ( V_139 )
V_140 |= 1 << V_6 -> V_142 ;
else
V_140 &= ~ ( 1 << V_6 -> V_142 ) ;
F_28 ( V_6 -> V_19 , V_141 , V_140 ) ;
}
static T_8 F_120 ( int V_54 , void * V_55 )
{
struct V_19 * V_19 = V_55 ;
struct V_73 * V_74 ;
struct V_11 * V_12 ;
T_4 V_95 = 0 ;
F_121 ( & V_19 -> V_107 ) ;
while ( ( V_74 = F_82 ( & V_19 -> V_106 ) ) ) {
V_12 = F_75 ( V_74 ) ;
if ( V_12 -> V_14 ) {
F_73 ( V_74 ) ;
F_12 ( V_12 ) ;
} else {
F_16 ( V_12 ) ;
}
V_95 ++ ;
}
F_122 ( & V_19 -> V_107 ) ;
F_83 ( V_19 , & V_19 -> V_106 , V_95 ) ;
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
const struct V_61 * V_92 )
{
struct V_61 * V_126 [ V_143 + 1 ] ;
unsigned int V_22 ;
bool V_144 ;
struct V_6 * V_6 ;
F_57 ( V_126 , V_143 , V_92 ) ;
if ( ! V_126 [ V_145 ] ||
! V_126 [ V_146 ] )
return - V_29 ;
V_22 =
F_53 ( V_126 [ V_145 ] ) - 1 ;
V_144 = F_50 ( V_126 [ V_146 ] ) ;
if ( V_22 >= V_19 -> V_147 )
return - V_148 ;
V_6 = V_19 -> V_149 [ V_22 ] ;
if ( F_129 ( V_6 -> V_28 ) != V_144 ) {
if ( V_144 )
F_123 ( V_6 ) ;
else
F_126 ( V_6 ) ;
}
return 0 ;
}
static int F_130 ( struct V_19 * V_19 ,
const struct V_61 * V_92 )
{
struct V_61 * V_126 [ V_150 + 1 ] ;
unsigned int V_22 ;
struct V_6 * V_6 ;
unsigned char * V_151 ;
int V_152 = V_153 | V_154 ;
T_1 V_1 ;
F_57 ( V_126 , V_150 , V_92 ) ;
if ( ! V_126 [ V_155 ] ||
! V_126 [ V_156 ] ||
! V_126 [ V_157 ] )
return - V_29 ;
V_22 =
F_53 ( V_126 [ V_155 ] ) - 1 ;
V_151 = F_48 ( V_126 [ V_156 ] ) ;
V_1 = F_52 ( V_126 [ V_157 ] ) ;
if ( V_22 >= V_19 -> V_147 )
return - V_148 ;
V_6 = V_19 -> V_149 [ V_22 ] ;
if ( V_6 -> V_158 != V_159 &&
V_6 -> V_158 != V_160 )
return 0 ;
return F_131 ( V_6 , V_151 , V_1 , V_152 ) ;
}
static int F_132 ( struct V_19 * V_19 ,
struct V_73 * V_74 )
{
struct V_61 * V_126 [ V_161 + 1 ] ;
struct V_61 * V_92 ;
T_2 type ;
F_58 ( V_126 , V_161 , V_74 ) ;
if ( ! V_126 [ V_162 ] ||
! V_126 [ V_163 ] )
return - V_29 ;
type = F_51 ( V_126 [ V_162 ] ) ;
V_92 = V_126 [ V_163 ] ;
switch ( type ) {
case V_164 :
return F_128 ( V_19 , V_92 ) ;
case V_165 :
return F_130 ( V_19 , V_92 ) ;
}
return - V_166 ;
}
static T_8 F_133 ( int V_54 , void * V_55 )
{
struct V_19 * V_19 = V_55 ;
struct V_23 * V_24 = V_19 -> V_24 ;
struct V_73 * V_74 ;
T_4 V_95 = 0 ;
int V_40 ;
while ( ( V_74 = F_82 ( & V_19 -> V_112 ) ) ) {
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
F_79 ( V_19 , & V_19 -> V_112 , V_74 ) ;
V_95 ++ ;
}
F_83 ( V_19 , & V_19 -> V_112 , V_95 ) ;
return V_56 ;
}
static T_8 F_134 ( int V_54 , void * V_55 )
{
struct V_6 * V_6 = V_55 ;
F_135 ( & V_6 -> V_167 ) ;
return V_56 ;
}
static T_8 F_136 ( int V_54 , void * V_55 )
{
struct V_6 * V_6 = V_55 ;
F_135 ( & V_6 -> V_168 ) ;
return V_56 ;
}
static int F_137 ( struct V_19 * V_19 ,
struct V_6 * V_6 ,
T_11 V_169 , void * V_170 ,
T_11 V_171 , void * V_172 ,
bool V_14 )
{
struct V_73 * V_74 ;
struct V_11 * V_12 ;
unsigned long V_152 ;
int V_40 ;
V_12 = F_10 ( V_14 ? V_173 : V_42 ) ;
if ( ! V_12 )
return - V_44 ;
V_12 -> V_14 = V_14 ;
F_138 ( & V_19 -> V_107 , V_152 ) ;
V_74 = F_77 ( & V_19 -> V_106 ) ;
if ( ! V_74 ) {
F_139 ( & V_19 -> V_107 , V_152 ) ;
V_40 = - V_174 ;
goto V_175;
}
V_40 = V_169 ( V_19 , V_6 , V_74 , V_170 ) ;
if ( V_40 ) {
F_139 ( & V_19 -> V_107 , V_152 ) ;
goto V_175;
}
F_76 ( V_74 , V_12 ) ;
F_79 ( V_19 , & V_19 -> V_106 , V_74 ) ;
F_139 ( & V_19 -> V_107 , V_152 ) ;
if ( V_14 )
return 0 ;
if ( ! F_14 ( V_12 , V_18 / 10 ) )
return - V_29 ;
V_40 = F_72 ( V_74 ) ;
if ( V_40 )
return V_40 ;
if ( V_171 )
V_40 = V_171 ( V_19 , V_6 , V_74 , V_172 ) ;
F_73 ( V_74 ) ;
V_175:
F_12 ( V_12 ) ;
return V_40 ;
}
static int
F_140 ( struct V_19 * V_19 ,
struct V_6 * V_6 ,
struct V_73 * V_74 ,
void * V_176 )
{
struct V_61 * V_177 ;
if ( F_63 ( V_74 , V_178 ,
V_179 ) )
return - V_83 ;
V_177 = F_68 ( V_74 , V_180 ) ;
if ( ! V_177 )
return - V_83 ;
if ( F_65 ( V_74 , V_181 ,
V_6 -> V_142 ) )
return - V_83 ;
F_69 ( V_74 , V_177 ) ;
return 0 ;
}
static int
F_141 ( struct V_19 * V_19 ,
struct V_6 * V_6 ,
struct V_73 * V_74 ,
void * V_176 )
{
struct V_182 * V_183 = V_176 ;
struct V_61 * V_126 [ V_184 + 1 ] ;
struct V_61 * V_185 [ V_186 + 1 ] ;
T_4 V_187 ;
T_9 V_188 ;
T_9 V_189 ;
F_58 ( V_126 , V_184 , V_74 ) ;
if ( ! V_126 [ V_180 ] )
return - V_29 ;
F_57 ( V_185 , V_186 ,
V_126 [ V_180 ] ) ;
if ( ! V_185 [ V_190 ] ||
! V_185 [ V_191 ] ||
! V_185 [ V_192 ] )
return - V_29 ;
V_187 = F_53 ( V_185 [ V_190 ] ) ;
V_188 = F_50 ( V_185 [ V_191 ] ) ;
V_189 = F_50 ( V_185 [ V_192 ] ) ;
V_183 -> V_193 = V_194 ;
V_183 -> V_195 = V_196 ;
V_183 -> V_197 = 0xff ;
V_183 -> V_198 = V_199 ;
F_142 ( V_183 , V_187 ) ;
V_183 -> V_188 = V_188 ? V_200 : V_201 ;
V_183 -> V_189 = V_189 ? V_202 : V_203 ;
return 0 ;
}
static int
F_143 ( struct V_19 * V_19 ,
struct V_6 * V_6 ,
struct V_73 * V_74 ,
void * V_176 )
{
unsigned char * V_204 = V_176 ;
struct V_61 * V_126 [ V_184 + 1 ] ;
struct V_61 * V_185 [ V_186 + 1 ] ;
struct V_61 * V_205 ;
F_58 ( V_126 , V_184 , V_74 ) ;
if ( ! V_126 [ V_180 ] )
return - V_29 ;
F_57 ( V_185 , V_186 ,
V_126 [ V_180 ] ) ;
V_205 = V_185 [ V_206 ] ;
if ( ! V_205 )
return - V_29 ;
if ( F_49 ( V_205 ) != V_207 )
return - V_148 ;
F_144 ( V_204 , F_48 ( V_205 ) ) ;
return 0 ;
}
static int
F_145 ( struct V_19 * V_19 ,
struct V_6 * V_6 ,
struct V_73 * V_74 ,
void * V_176 )
{
struct V_182 * V_183 = V_176 ;
struct V_61 * V_177 ;
if ( F_63 ( V_74 , V_178 ,
V_208 ) )
return - V_83 ;
V_177 = F_68 ( V_74 , V_180 ) ;
if ( ! V_177 )
return - V_83 ;
if ( F_65 ( V_74 , V_181 ,
V_6 -> V_142 ) )
return - V_83 ;
if ( F_65 ( V_74 , V_190 ,
F_146 ( V_183 ) ) )
return - V_83 ;
if ( F_62 ( V_74 , V_191 ,
V_183 -> V_188 ) )
return - V_83 ;
if ( F_62 ( V_74 , V_192 ,
V_183 -> V_189 ) )
return - V_83 ;
F_69 ( V_74 , V_177 ) ;
return 0 ;
}
static int
F_147 ( struct V_19 * V_19 ,
struct V_6 * V_6 ,
struct V_73 * V_74 ,
void * V_176 )
{
unsigned char * V_204 = V_176 ;
struct V_61 * V_177 ;
if ( F_63 ( V_74 , V_178 ,
V_208 ) )
return - V_83 ;
V_177 = F_68 ( V_74 , V_180 ) ;
if ( ! V_177 )
return - V_83 ;
if ( F_65 ( V_74 , V_181 ,
V_6 -> V_142 ) )
return - V_83 ;
if ( F_60 ( V_74 , V_206 ,
V_207 , V_204 ) )
return - V_83 ;
F_69 ( V_74 , V_177 ) ;
return 0 ;
}
static int
F_148 ( struct V_19 * V_19 ,
struct V_6 * V_6 ,
struct V_73 * V_74 ,
void * V_176 )
{
struct V_61 * V_177 ;
if ( F_63 ( V_74 , V_178 ,
V_208 ) )
return - V_83 ;
V_177 = F_68 ( V_74 , V_180 ) ;
if ( ! V_177 )
return - V_83 ;
if ( F_65 ( V_74 , V_181 ,
V_6 -> V_142 ) )
return - V_83 ;
if ( F_62 ( V_74 , V_209 ,
! ! ( V_6 -> V_210 & V_211 ) ) )
return - V_83 ;
F_69 ( V_74 , V_177 ) ;
return 0 ;
}
static int F_149 ( struct V_6 * V_6 ,
struct V_182 * V_183 )
{
return F_137 ( V_6 -> V_19 , V_6 ,
F_140 , NULL ,
F_141 ,
V_183 , false ) ;
}
static int F_150 ( struct V_6 * V_6 ,
unsigned char * V_204 )
{
return F_137 ( V_6 -> V_19 , V_6 ,
F_140 , NULL ,
F_143 ,
V_204 , false ) ;
}
static int F_151 ( struct V_6 * V_6 ,
struct V_182 * V_183 )
{
return F_137 ( V_6 -> V_19 , V_6 ,
F_145 ,
V_183 , NULL , NULL , false ) ;
}
static int F_152 ( struct V_6 * V_6 ,
unsigned char * V_204 )
{
return F_137 ( V_6 -> V_19 , V_6 ,
F_147 ,
V_204 , NULL , NULL , false ) ;
}
static int F_153 ( struct V_6 * V_6 )
{
return F_137 ( V_6 -> V_19 , V_6 ,
F_148 ,
NULL , NULL , NULL , false ) ;
}
static int F_154 ( struct V_73 * V_74 ,
struct V_212 * V_213 )
{
if ( F_65 ( V_74 , V_214 ,
V_213 -> V_215 . V_216 . V_217 ) )
return - V_83 ;
if ( F_65 ( V_74 , V_218 ,
V_213 -> V_215 . V_216 . V_219 ) )
return - V_83 ;
if ( F_63 ( V_74 , V_220 ,
V_213 -> V_215 . V_216 . V_221 ) )
return - V_83 ;
return 0 ;
}
static int F_155 ( struct V_73 * V_74 ,
struct V_212 * V_213 )
{
if ( F_65 ( V_74 , V_214 ,
V_213 -> V_215 . V_222 . V_217 ) )
return - V_83 ;
if ( F_64 ( V_74 , V_223 ,
V_213 -> V_215 . V_222 . V_1 ) )
return - V_83 ;
if ( F_64 ( V_74 , V_224 ,
V_213 -> V_215 . V_222 . V_225 ) )
return - V_83 ;
if ( F_63 ( V_74 , V_220 ,
V_213 -> V_215 . V_222 . V_221 ) )
return - V_83 ;
if ( V_213 -> V_215 . V_222 . V_226 &&
F_64 ( V_74 , V_227 ,
V_213 -> V_215 . V_222 . V_228 ) )
return - V_83 ;
return 0 ;
}
static int F_156 ( struct V_73 * V_74 ,
struct V_212 * V_213 )
{
if ( F_65 ( V_74 , V_214 ,
V_213 -> V_215 . V_229 . V_217 ) )
return - V_83 ;
if ( F_65 ( V_74 , V_218 ,
V_213 -> V_215 . V_229 . V_219 ) )
return - V_83 ;
if ( F_64 ( V_74 , V_230 ,
V_213 -> V_215 . V_229 . V_231 ) )
return - V_83 ;
if ( F_60 ( V_74 , V_232 ,
V_207 , V_213 -> V_215 . V_229 . V_233 ) )
return - V_83 ;
if ( F_60 ( V_74 , V_234 ,
V_207 , V_213 -> V_215 . V_229 . V_235 ) )
return - V_83 ;
if ( F_64 ( V_74 , V_223 ,
V_213 -> V_215 . V_229 . V_1 ) )
return - V_83 ;
if ( F_64 ( V_74 , V_224 ,
V_213 -> V_215 . V_229 . V_225 ) )
return - V_83 ;
if ( F_63 ( V_74 , V_220 ,
V_213 -> V_215 . V_229 . V_221 ) )
return - V_83 ;
if ( V_213 -> V_215 . V_229 . V_236 &&
F_62 ( V_74 , V_237 ,
V_213 -> V_215 . V_229 . V_236 ) )
return - V_83 ;
return 0 ;
}
static int
F_157 ( struct V_73 * V_74 ,
struct V_212 * V_213 )
{
if ( F_64 ( V_74 , V_230 ,
V_213 -> V_215 . V_238 . V_231 ) )
return - V_83 ;
if ( F_66 ( V_74 , V_239 ,
V_213 -> V_215 . V_238 . V_240 ) )
return - V_83 ;
if ( F_66 ( V_74 , V_241 ,
V_213 -> V_215 . V_238 . V_242 ) )
return - V_83 ;
if ( F_63 ( V_74 , V_220 ,
V_213 -> V_215 . V_238 . V_221 ) )
return - V_83 ;
if ( F_65 ( V_74 , V_243 ,
V_213 -> V_215 . V_238 . V_244 ) )
return - V_83 ;
return 0 ;
}
static int F_158 ( struct V_73 * V_74 ,
struct V_212 * V_213 )
{
if ( V_213 -> V_215 . V_245 . V_246 &&
F_60 ( V_74 , V_232 ,
V_207 , V_213 -> V_215 . V_245 . V_233 ) )
return - V_83 ;
if ( V_213 -> V_215 . V_245 . V_247 &&
F_60 ( V_74 , V_234 ,
V_207 , V_213 -> V_215 . V_245 . V_235 ) )
return - V_83 ;
if ( V_213 -> V_215 . V_245 . V_1 &&
F_64 ( V_74 , V_223 ,
V_213 -> V_215 . V_245 . V_1 ) )
return - V_83 ;
if ( V_213 -> V_215 . V_245 . V_248 &&
F_65 ( V_74 , V_249 ,
V_213 -> V_215 . V_245 . V_248 ) )
return - V_83 ;
if ( F_63 ( V_74 , V_220 ,
V_213 -> V_215 . V_245 . V_221 ) )
return - V_83 ;
if ( F_65 ( V_74 , V_243 ,
V_213 -> V_215 . V_245 . V_244 ) )
return - V_83 ;
if ( V_213 -> V_215 . V_245 . V_236 &&
F_62 ( V_74 , V_237 ,
V_213 -> V_215 . V_245 . V_236 ) )
return - V_83 ;
return 0 ;
}
static int F_159 ( struct V_73 * V_74 ,
struct V_212 * V_213 )
{
if ( F_65 ( V_74 , V_214 ,
V_213 -> V_215 . V_250 . V_217 ) )
return - V_83 ;
if ( F_65 ( V_74 , V_218 ,
V_213 -> V_215 . V_250 . V_219 ) )
return - V_83 ;
if ( F_60 ( V_74 , V_251 ,
V_207 , V_213 -> V_215 . V_250 . V_252 ) )
return - V_83 ;
if ( F_60 ( V_74 , V_253 ,
V_207 , V_213 -> V_215 . V_250 . V_254 ) )
return - V_83 ;
if ( F_60 ( V_74 , V_232 ,
V_207 , V_213 -> V_215 . V_250 . V_233 ) )
return - V_83 ;
if ( F_60 ( V_74 , V_234 ,
V_207 , V_213 -> V_215 . V_250 . V_235 ) )
return - V_83 ;
if ( F_64 ( V_74 , V_230 ,
V_213 -> V_215 . V_250 . V_231 ) )
return - V_83 ;
if ( F_64 ( V_74 , V_223 ,
V_213 -> V_215 . V_250 . V_1 ) )
return - V_83 ;
if ( F_64 ( V_74 , V_224 ,
V_213 -> V_215 . V_250 . V_225 ) )
return - V_83 ;
switch ( F_2 ( V_213 -> V_215 . V_250 . V_231 ) ) {
case V_255 :
case V_256 :
if ( F_62 ( V_74 , V_257 ,
V_213 -> V_215 . V_250 . V_258 ) )
return - V_83 ;
if ( F_62 ( V_74 ,
V_259 ,
V_213 -> V_215 . V_250 . V_260 ) )
return - V_83 ;
if ( F_62 ( V_74 , V_261 ,
V_213 -> V_215 . V_250 . V_262 & 0x3f ) )
return - V_83 ;
if ( F_62 ( V_74 ,
V_263 ,
V_213 -> V_215 . V_250 . V_264 & 0x3f ) )
return - V_83 ;
if ( F_62 ( V_74 , V_265 ,
( V_213 -> V_215 . V_250 . V_262 & 0xc0 ) >> 6 ) )
return - V_83 ;
if ( F_62 ( V_74 ,
V_266 ,
( V_213 -> V_215 . V_250 . V_264 & 0xc0 ) >> 6 ) )
return - V_83 ;
break;
}
if ( V_213 -> V_215 . V_250 . V_244 != V_267 &&
F_65 ( V_74 , V_243 ,
V_213 -> V_215 . V_250 . V_244 ) )
return - V_83 ;
return 0 ;
}
static int F_160 ( struct V_19 * V_19 ,
struct V_6 * V_6 ,
struct V_73 * V_74 ,
void * V_176 )
{
struct V_212 * V_213 = V_176 ;
struct V_61 * V_177 ;
int V_40 = 0 ;
if ( F_63 ( V_74 , V_178 ,
V_268 ) )
return - V_83 ;
V_177 = F_68 ( V_74 , V_180 ) ;
if ( ! V_177 )
return - V_83 ;
if ( F_63 ( V_74 , V_269 ,
V_213 -> V_215 . V_270 ) )
return - V_83 ;
if ( F_65 ( V_74 , V_271 ,
V_213 -> V_215 . V_272 ) )
return - V_83 ;
if ( F_65 ( V_74 , V_273 , 0 ) )
return - V_83 ;
if ( F_67 ( V_74 , V_274 ,
V_213 -> V_89 ) )
return - V_83 ;
switch ( V_213 -> V_215 . V_270 ) {
case V_275 :
V_40 = F_154 ( V_74 , V_213 ) ;
break;
case V_276 :
V_40 = F_155 ( V_74 , V_213 ) ;
break;
case V_277 :
V_40 = F_156 ( V_74 , V_213 ) ;
break;
case V_278 :
V_40 = F_157 ( V_74 , V_213 ) ;
break;
case V_279 :
V_40 = F_158 ( V_74 , V_213 ) ;
break;
case V_280 :
V_40 = F_159 ( V_74 , V_213 ) ;
break;
default:
V_40 = - V_281 ;
break;
}
if ( V_40 )
return V_40 ;
F_69 ( V_74 , V_177 ) ;
return 0 ;
}
static int F_161 ( struct V_19 * V_19 ,
struct V_6 * V_6 ,
struct V_73 * V_74 ,
void * V_176 )
{
const struct V_212 * V_213 = V_176 ;
struct V_61 * V_177 ;
if ( F_63 ( V_74 , V_178 ,
V_282 ) )
return - V_83 ;
V_177 = F_68 ( V_74 , V_180 ) ;
if ( ! V_177 )
return - V_83 ;
if ( F_67 ( V_74 , V_274 ,
V_213 -> V_89 ) )
return - V_83 ;
F_69 ( V_74 , V_177 ) ;
return 0 ;
}
static int
F_162 ( struct V_73 * V_74 ,
struct V_283 * V_213 )
{
if ( F_65 ( V_74 , V_284 ,
F_163 ( V_213 -> V_244 ) ) )
return - V_83 ;
if ( F_62 ( V_74 , V_285 ,
V_213 -> V_286 . V_8 ) )
return - V_83 ;
return 0 ;
}
static int
F_164 ( struct V_73 * V_74 ,
struct V_283 * V_213 )
{
if ( F_65 ( V_74 , V_287 ,
V_213 -> V_288 . V_244 ) )
return - V_83 ;
if ( ! F_165 ( V_213 -> V_288 . V_252 ) &&
F_60 ( V_74 , V_251 ,
V_207 , V_213 -> V_288 . V_252 ) )
return - V_83 ;
if ( ! F_165 ( V_213 -> V_288 . V_233 ) &&
F_60 ( V_74 , V_232 ,
V_207 , V_213 -> V_288 . V_233 ) )
return - V_83 ;
if ( V_213 -> V_288 . V_1 &&
F_64 ( V_74 , V_223 ,
V_213 -> V_288 . V_1 ) )
return - V_83 ;
return 0 ;
}
static int
F_166 ( struct V_73 * V_74 ,
struct V_283 * V_213 )
{
int V_36 ;
struct V_61 * V_289 ;
if ( F_63 ( V_74 , V_290 ,
V_213 -> V_291 ) )
return - V_83 ;
V_289 = F_68 ( V_74 ,
V_292 ) ;
if ( ! V_289 )
return - V_83 ;
for ( V_36 = 0 ; V_36 < V_213 -> V_291 ; V_36 ++ )
if ( F_65 ( V_74 , V_36 + 1 , V_213 -> V_289 [ V_36 ] ) )
return - V_83 ;
F_69 ( V_74 , V_289 ) ;
return 0 ;
}
static int
F_167 ( struct V_73 * V_74 ,
struct V_283 * V_213 )
{
if ( ! F_165 ( V_213 -> V_293 . V_252 ) &&
F_60 ( V_74 , V_251 ,
V_207 , V_213 -> V_293 . V_252 ) )
return - V_83 ;
if ( ! F_165 ( V_213 -> V_293 . V_233 ) &&
F_60 ( V_74 , V_232 ,
V_207 , V_213 -> V_293 . V_233 ) )
return - V_83 ;
if ( V_213 -> V_293 . V_1 &&
F_64 ( V_74 , V_223 ,
V_213 -> V_293 . V_1 ) )
return - V_83 ;
if ( F_62 ( V_74 , V_294 ,
V_213 -> V_293 . V_295 ) )
return - V_83 ;
if ( F_65 ( V_74 , V_287 ,
V_213 -> V_293 . V_244 ) )
return - V_83 ;
return 0 ;
}
static int F_168 ( struct V_19 * V_19 ,
struct V_6 * V_6 ,
struct V_73 * V_74 ,
void * V_176 )
{
struct V_283 * V_213 = V_176 ;
struct V_61 * V_177 ;
int V_40 = 0 ;
if ( F_63 ( V_74 , V_178 , V_213 -> V_296 ) )
return - V_83 ;
V_177 = F_68 ( V_74 , V_180 ) ;
if ( ! V_177 )
return - V_83 ;
if ( F_65 ( V_74 , V_243 ,
V_213 -> V_244 ) )
return - V_83 ;
switch ( F_169 ( V_213 -> V_244 ) ) {
case V_297 :
V_40 = F_162 ( V_74 , V_213 ) ;
break;
case V_298 :
V_40 = F_164 ( V_74 , V_213 ) ;
break;
case V_299 :
case V_300 :
V_40 = F_166 ( V_74 , V_213 ) ;
break;
case V_301 :
V_40 = F_167 ( V_74 , V_213 ) ;
break;
default:
V_40 = - V_281 ;
break;
}
if ( V_40 )
return V_40 ;
F_69 ( V_74 , V_177 ) ;
return 0 ;
}
static int F_170 ( struct V_19 * V_19 ,
struct V_6 * V_6 ,
struct V_73 * V_74 ,
void * V_176 )
{
const struct V_283 * V_213 = V_176 ;
struct V_61 * V_177 ;
if ( F_63 ( V_74 , V_178 , V_213 -> V_296 ) )
return - V_83 ;
V_177 = F_68 ( V_74 , V_180 ) ;
if ( ! V_177 )
return - V_83 ;
if ( F_65 ( V_74 , V_243 ,
V_213 -> V_244 ) )
return - V_83 ;
F_69 ( V_74 , V_177 ) ;
return 0 ;
}
static int F_171 ( struct V_19 * V_19 )
{
F_172 ( V_19 -> V_302 ) ;
F_103 ( & V_19 -> V_303 ) ;
F_172 ( V_19 -> V_304 ) ;
F_103 ( & V_19 -> V_305 ) ;
F_172 ( V_19 -> V_306 ) ;
F_103 ( & V_19 -> V_307 ) ;
F_172 ( V_19 -> V_308 ) ;
F_103 ( & V_19 -> V_309 ) ;
return 0 ;
}
static void F_173 ( struct V_19 * V_19 )
{
unsigned long V_152 ;
struct V_212 * V_310 ;
struct V_283 * V_311 ;
struct V_312 * V_313 ;
struct V_314 * V_315 ;
struct V_316 * V_317 ;
int V_318 ;
F_138 ( & V_19 -> V_303 , V_152 ) ;
F_174 (rocker->flow_tbl, bkt, tmp, flow_entry, entry)
F_175 ( & V_310 -> V_213 ) ;
F_139 ( & V_19 -> V_303 , V_152 ) ;
F_138 ( & V_19 -> V_305 , V_152 ) ;
F_174 (rocker->group_tbl, bkt, tmp, group_entry, entry)
F_175 ( & V_311 -> V_213 ) ;
F_139 ( & V_19 -> V_305 , V_152 ) ;
F_138 ( & V_19 -> V_307 , V_152 ) ;
F_174 (rocker->fdb_tbl, bkt, tmp, fdb_entry, entry)
F_175 ( & V_313 -> V_213 ) ;
F_139 ( & V_19 -> V_307 , V_152 ) ;
F_138 ( & V_19 -> V_309 , V_152 ) ;
F_174 (rocker->internal_vlan_tbl, bkt,
tmp, internal_vlan_entry, entry)
F_175 ( & V_315 -> V_213 ) ;
F_139 ( & V_19 -> V_309 , V_152 ) ;
}
static struct V_212 *
F_176 ( struct V_19 * V_19 , struct V_212 * V_319 )
{
struct V_212 * V_320 ;
F_177 (rocker->flow_tbl, found,
entry, match->key_crc32) {
if ( memcmp ( & V_320 -> V_215 , & V_319 -> V_215 , sizeof( V_320 -> V_215 ) ) == 0 )
return V_320 ;
}
return NULL ;
}
static int F_178 ( struct V_6 * V_6 ,
struct V_212 * V_319 ,
bool V_14 )
{
struct V_19 * V_19 = V_6 -> V_19 ;
struct V_212 * V_320 ;
unsigned long V_152 ;
bool V_321 = false ;
int V_40 = 0 ;
V_319 -> V_322 = F_179 ( ~ 0 , & V_319 -> V_215 , sizeof( V_319 -> V_215 ) ) ;
F_138 ( & V_19 -> V_303 , V_152 ) ;
V_320 = F_176 ( V_19 , V_319 ) ;
if ( V_320 ) {
F_13 ( V_319 ) ;
} else {
V_320 = V_319 ;
V_320 -> V_89 = V_19 -> V_323 ++ ;
F_180 ( V_19 -> V_302 , & V_320 -> V_213 , V_320 -> V_322 ) ;
V_321 = true ;
}
V_320 -> V_324 ++ ;
F_139 ( & V_19 -> V_303 , V_152 ) ;
if ( V_321 ) {
V_40 = F_137 ( V_19 , V_6 ,
F_160 ,
V_320 , NULL , NULL , V_14 ) ;
if ( V_40 ) {
F_138 ( & V_19 -> V_303 , V_152 ) ;
F_175 ( & V_320 -> V_213 ) ;
F_139 ( & V_19 -> V_303 , V_152 ) ;
F_13 ( V_320 ) ;
}
}
return V_40 ;
}
static int F_181 ( struct V_6 * V_6 ,
struct V_212 * V_319 ,
bool V_14 )
{
struct V_19 * V_19 = V_6 -> V_19 ;
struct V_212 * V_320 ;
unsigned long V_152 ;
bool V_325 = false ;
int V_40 = 0 ;
V_319 -> V_322 = F_179 ( ~ 0 , & V_319 -> V_215 , sizeof( V_319 -> V_215 ) ) ;
F_138 ( & V_19 -> V_303 , V_152 ) ;
V_320 = F_176 ( V_19 , V_319 ) ;
if ( V_320 ) {
V_320 -> V_324 -- ;
if ( V_320 -> V_324 == 0 ) {
F_175 ( & V_320 -> V_213 ) ;
V_325 = true ;
}
}
F_139 ( & V_19 -> V_303 , V_152 ) ;
F_13 ( V_319 ) ;
if ( V_325 ) {
V_40 = F_137 ( V_19 , V_6 ,
F_161 ,
V_320 , NULL , NULL , V_14 ) ;
F_13 ( V_320 ) ;
}
return V_40 ;
}
static T_3 F_182 ( int V_152 )
{
return V_152 & V_153 ? V_173 : V_42 ;
}
static int F_183 ( struct V_6 * V_6 ,
int V_152 , struct V_212 * V_213 )
{
bool V_14 = V_152 & V_153 ;
if ( V_152 & V_326 )
return F_181 ( V_6 , V_213 , V_14 ) ;
else
return F_178 ( V_6 , V_213 , V_14 ) ;
}
static int F_184 ( struct V_6 * V_6 ,
int V_152 , T_4 V_217 , T_4 V_219 ,
enum V_327 V_221 )
{
struct V_212 * V_213 ;
V_213 = F_32 ( sizeof( * V_213 ) , F_182 ( V_152 ) ) ;
if ( ! V_213 )
return - V_44 ;
V_213 -> V_215 . V_272 = V_328 ;
V_213 -> V_215 . V_270 = V_275 ;
V_213 -> V_215 . V_216 . V_217 = V_217 ;
V_213 -> V_215 . V_216 . V_219 = V_219 ;
V_213 -> V_215 . V_216 . V_221 = V_221 ;
return F_183 ( V_6 , V_152 , V_213 ) ;
}
static int F_185 ( struct V_6 * V_6 ,
int V_152 , T_4 V_217 ,
T_1 V_1 , T_1 V_225 ,
enum V_327 V_221 ,
bool V_226 , T_1 V_228 )
{
struct V_212 * V_213 ;
V_213 = F_32 ( sizeof( * V_213 ) , F_182 ( V_152 ) ) ;
if ( ! V_213 )
return - V_44 ;
V_213 -> V_215 . V_272 = V_329 ;
V_213 -> V_215 . V_270 = V_276 ;
V_213 -> V_215 . V_222 . V_217 = V_217 ;
V_213 -> V_215 . V_222 . V_1 = V_1 ;
V_213 -> V_215 . V_222 . V_225 = V_225 ;
V_213 -> V_215 . V_222 . V_221 = V_221 ;
V_213 -> V_215 . V_222 . V_226 = V_226 ;
V_213 -> V_215 . V_222 . V_228 = V_228 ;
return F_183 ( V_6 , V_152 , V_213 ) ;
}
static int F_186 ( struct V_6 * V_6 ,
T_4 V_217 , T_4 V_219 ,
T_1 V_231 , const T_9 * V_233 ,
const T_9 * V_235 , T_1 V_1 ,
T_1 V_225 , bool V_236 ,
int V_152 )
{
struct V_212 * V_213 ;
V_213 = F_32 ( sizeof( * V_213 ) , F_182 ( V_152 ) ) ;
if ( ! V_213 )
return - V_44 ;
if ( F_187 ( V_233 ) ) {
V_213 -> V_215 . V_272 = V_330 ;
V_213 -> V_215 . V_229 . V_221 =
V_331 ;
} else {
V_213 -> V_215 . V_272 = V_332 ;
V_213 -> V_215 . V_229 . V_221 =
V_278 ;
}
V_213 -> V_215 . V_270 = V_277 ;
V_213 -> V_215 . V_229 . V_217 = V_217 ;
V_213 -> V_215 . V_229 . V_219 = V_219 ;
V_213 -> V_215 . V_229 . V_231 = V_231 ;
F_144 ( V_213 -> V_215 . V_229 . V_233 , V_233 ) ;
F_144 ( V_213 -> V_215 . V_229 . V_235 , V_235 ) ;
V_213 -> V_215 . V_229 . V_1 = V_1 ;
V_213 -> V_215 . V_229 . V_225 = V_225 ;
V_213 -> V_215 . V_229 . V_236 = V_236 ;
return F_183 ( V_6 , V_152 , V_213 ) ;
}
static int F_188 ( struct V_6 * V_6 ,
int V_152 ,
const T_9 * V_233 , const T_9 * V_235 ,
T_1 V_1 , T_4 V_248 ,
enum V_327 V_221 ,
T_4 V_244 , bool V_236 )
{
struct V_212 * V_213 ;
T_4 V_272 ;
bool V_333 = ! ! V_1 ;
bool V_334 = ! V_233 || ( V_233 && V_235 ) ;
bool V_335 = false ;
V_213 = F_32 ( sizeof( * V_213 ) , F_182 ( V_152 ) ) ;
if ( ! V_213 )
return - V_44 ;
V_213 -> V_215 . V_270 = V_279 ;
if ( V_233 ) {
V_213 -> V_215 . V_245 . V_246 = 1 ;
F_144 ( V_213 -> V_215 . V_245 . V_233 , V_233 ) ;
}
if ( V_235 ) {
V_213 -> V_215 . V_245 . V_247 = 1 ;
F_144 ( V_213 -> V_215 . V_245 . V_235 , V_235 ) ;
if ( memcmp ( V_235 , V_336 , V_207 ) )
V_335 = true ;
}
V_272 = V_337 ;
if ( V_333 && V_334 && V_335 )
V_272 = V_338 ;
else if ( V_333 && V_334 && ! V_335 )
V_272 = V_339 ;
else if ( V_333 && ! V_334 )
V_272 = V_340 ;
else if ( ! V_333 && V_334 && V_335 )
V_272 = V_341 ;
else if ( ! V_333 && V_334 && ! V_335 )
V_272 = V_342 ;
else if ( ! V_333 && ! V_334 )
V_272 = V_343 ;
V_213 -> V_215 . V_272 = V_272 ;
V_213 -> V_215 . V_245 . V_1 = V_1 ;
V_213 -> V_215 . V_245 . V_248 = V_248 ;
V_213 -> V_215 . V_245 . V_221 = V_221 ;
V_213 -> V_215 . V_245 . V_244 = V_244 ;
V_213 -> V_215 . V_245 . V_236 = V_236 ;
return F_183 ( V_6 , V_152 , V_213 ) ;
}
static int F_189 ( struct V_6 * V_6 ,
int V_152 , T_4 V_217 ,
T_4 V_219 ,
const T_9 * V_252 , const T_9 * V_254 ,
const T_9 * V_233 , const T_9 * V_235 ,
T_1 V_231 ,
T_1 V_1 , T_1 V_225 ,
T_9 V_258 , T_9 V_260 ,
T_9 V_262 , T_9 V_264 ,
T_4 V_244 )
{
T_4 V_272 ;
struct V_212 * V_213 ;
V_213 = F_32 ( sizeof( * V_213 ) , F_182 ( V_152 ) ) ;
if ( ! V_213 )
return - V_44 ;
V_272 = V_344 ;
if ( V_233 && V_235 ) {
if ( memcmp ( V_235 , V_345 , V_207 ) == 0 )
V_272 = V_346 ;
else if ( F_190 ( V_233 ) )
V_272 = V_347 ;
}
V_213 -> V_215 . V_272 = V_272 ;
V_213 -> V_215 . V_270 = V_280 ;
V_213 -> V_215 . V_250 . V_217 = V_217 ;
V_213 -> V_215 . V_250 . V_219 = V_219 ;
if ( V_252 )
F_144 ( V_213 -> V_215 . V_250 . V_252 , V_252 ) ;
if ( V_254 )
F_144 ( V_213 -> V_215 . V_250 . V_254 , V_254 ) ;
if ( V_233 )
F_144 ( V_213 -> V_215 . V_250 . V_233 , V_233 ) ;
if ( V_235 )
F_144 ( V_213 -> V_215 . V_250 . V_235 , V_235 ) ;
V_213 -> V_215 . V_250 . V_231 = V_231 ;
V_213 -> V_215 . V_250 . V_1 = V_1 ;
V_213 -> V_215 . V_250 . V_225 = V_225 ;
V_213 -> V_215 . V_250 . V_258 = V_258 ;
V_213 -> V_215 . V_250 . V_260 = V_260 ;
V_213 -> V_215 . V_250 . V_262 = V_262 ;
V_213 -> V_215 . V_250 . V_264 = V_264 ;
V_213 -> V_215 . V_250 . V_244 = V_244 ;
return F_183 ( V_6 , V_152 , V_213 ) ;
}
static struct V_283 *
F_191 ( struct V_19 * V_19 ,
struct V_283 * V_319 )
{
struct V_283 * V_320 ;
F_177 (rocker->group_tbl, found,
entry, match->group_id) {
if ( V_320 -> V_244 == V_319 -> V_244 )
return V_320 ;
}
return NULL ;
}
static void F_192 ( struct V_283 * V_213 )
{
switch ( F_169 ( V_213 -> V_244 ) ) {
case V_299 :
case V_300 :
F_13 ( V_213 -> V_289 ) ;
break;
default:
break;
}
F_13 ( V_213 ) ;
}
static int F_193 ( struct V_6 * V_6 ,
struct V_283 * V_319 ,
bool V_14 )
{
struct V_19 * V_19 = V_6 -> V_19 ;
struct V_283 * V_320 ;
unsigned long V_152 ;
int V_40 = 0 ;
F_138 ( & V_19 -> V_305 , V_152 ) ;
V_320 = F_191 ( V_19 , V_319 ) ;
if ( V_320 ) {
F_175 ( & V_320 -> V_213 ) ;
F_192 ( V_320 ) ;
V_320 = V_319 ;
V_320 -> V_296 = V_348 ;
} else {
V_320 = V_319 ;
V_320 -> V_296 = V_349 ;
}
F_180 ( V_19 -> V_304 , & V_320 -> V_213 , V_320 -> V_244 ) ;
F_139 ( & V_19 -> V_305 , V_152 ) ;
if ( V_320 -> V_296 )
V_40 = F_137 ( V_19 , V_6 ,
F_168 ,
V_320 , NULL , NULL , V_14 ) ;
return V_40 ;
}
static int F_194 ( struct V_6 * V_6 ,
struct V_283 * V_319 ,
bool V_14 )
{
struct V_19 * V_19 = V_6 -> V_19 ;
struct V_283 * V_320 ;
unsigned long V_152 ;
int V_40 = 0 ;
F_138 ( & V_19 -> V_305 , V_152 ) ;
V_320 = F_191 ( V_19 , V_319 ) ;
if ( V_320 ) {
F_175 ( & V_320 -> V_213 ) ;
V_320 -> V_296 = V_350 ;
}
F_139 ( & V_19 -> V_305 , V_152 ) ;
F_192 ( V_319 ) ;
if ( V_320 ) {
V_40 = F_137 ( V_19 , V_6 ,
F_170 ,
V_320 , NULL , NULL , V_14 ) ;
F_192 ( V_320 ) ;
}
return V_40 ;
}
static int F_195 ( struct V_6 * V_6 ,
int V_152 , struct V_283 * V_213 )
{
bool V_14 = V_152 & V_153 ;
if ( V_152 & V_326 )
return F_194 ( V_6 , V_213 , V_14 ) ;
else
return F_193 ( V_6 , V_213 , V_14 ) ;
}
static int F_196 ( struct V_6 * V_6 ,
int V_152 , T_1 V_1 ,
T_4 V_351 , int V_8 )
{
struct V_283 * V_213 ;
V_213 = F_32 ( sizeof( * V_213 ) , F_182 ( V_152 ) ) ;
if ( ! V_213 )
return - V_44 ;
V_213 -> V_244 = F_197 ( V_1 , V_351 ) ;
V_213 -> V_286 . V_8 = V_8 ;
return F_195 ( V_6 , V_152 , V_213 ) ;
}
static int F_198 ( struct V_6 * V_6 ,
int V_152 , T_9 V_291 ,
T_4 * V_289 , T_4 V_244 )
{
struct V_283 * V_213 ;
V_213 = F_32 ( sizeof( * V_213 ) , F_182 ( V_152 ) ) ;
if ( ! V_213 )
return - V_44 ;
V_213 -> V_244 = V_244 ;
V_213 -> V_291 = V_291 ;
V_213 -> V_289 = F_90 ( V_291 , sizeof( T_4 ) ,
F_182 ( V_152 ) ) ;
if ( ! V_213 -> V_289 ) {
F_13 ( V_213 ) ;
return - V_44 ;
}
memcpy ( V_213 -> V_289 , V_289 , V_291 * sizeof( T_4 ) ) ;
return F_195 ( V_6 , V_152 , V_213 ) ;
}
static int F_199 ( struct V_6 * V_6 ,
int V_152 , T_1 V_1 ,
T_9 V_291 , T_4 * V_289 ,
T_4 V_244 )
{
return F_198 ( V_6 , V_152 ,
V_291 , V_289 ,
V_244 ) ;
}
static int F_200 ( struct V_6 * V_6 ,
int V_152 , T_1 V_1 )
{
struct V_6 * V_352 ;
struct V_19 * V_19 = V_6 -> V_19 ;
T_4 V_244 = F_201 ( V_1 , 0 ) ;
T_4 V_289 [ V_19 -> V_147 ] ;
T_9 V_291 = 0 ;
int V_40 ;
int V_36 ;
for ( V_36 = 0 ; V_36 < V_19 -> V_147 ; V_36 ++ ) {
V_352 = V_19 -> V_149 [ V_36 ] ;
if ( ! F_6 ( V_352 ) )
continue;
if ( F_202 ( F_2 ( V_1 ) , V_352 -> V_353 ) ) {
V_289 [ V_291 ++ ] =
F_197 ( V_1 ,
V_352 -> V_142 ) ;
}
}
if ( V_291 == 0 )
return 0 ;
V_40 = F_199 ( V_6 , V_152 , V_1 ,
V_291 , V_289 ,
V_244 ) ;
if ( V_40 )
F_116 ( V_6 -> V_28 ,
L_21 , V_40 ) ;
return V_40 ;
}
static int F_203 ( struct V_6 * V_6 ,
int V_152 , T_1 V_1 ,
bool V_8 )
{
struct V_19 * V_19 = V_6 -> V_19 ;
struct V_6 * V_352 ;
bool V_354 = ! ( V_152 & V_326 ) ;
T_4 V_351 ;
int V_355 = 0 ;
int V_40 ;
int V_36 ;
if ( V_6 -> V_158 == V_159 ||
V_6 -> V_158 == V_160 ) {
V_351 = V_6 -> V_142 ;
V_40 = F_196 ( V_6 , V_152 ,
V_1 , V_351 ,
V_8 ) ;
if ( V_40 ) {
F_116 ( V_6 -> V_28 ,
L_22 ,
V_40 , V_351 ) ;
return V_40 ;
}
}
for ( V_36 = 0 ; V_36 < V_19 -> V_147 ; V_36 ++ ) {
V_352 = V_19 -> V_149 [ V_36 ] ;
if ( F_202 ( F_2 ( V_1 ) , V_352 -> V_353 ) )
V_355 ++ ;
}
if ( ( ! V_354 || V_355 != 1 ) && ( V_354 || V_355 != 0 ) )
return 0 ;
V_351 = 0 ;
V_40 = F_196 ( V_6 , V_152 ,
V_1 , V_351 ,
V_8 ) ;
if ( V_40 ) {
F_116 ( V_6 -> V_28 ,
L_23 , V_40 ) ;
return V_40 ;
}
return 0 ;
}
static int F_204 ( struct V_6 * V_6 ,
int V_152 , struct V_356 * V_357 ,
T_1 V_1 )
{
T_4 V_217 = V_6 -> V_142 ;
T_4 V_219 = 0xffffffff ;
T_4 V_351 = 0 ;
T_9 * V_252 = NULL ;
T_9 * V_254 = NULL ;
T_1 V_225 = F_4 ( 0xffff ) ;
T_9 V_258 = 0 ;
T_9 V_260 = 0 ;
T_9 V_262 = 0 ;
T_9 V_264 = 0 ;
T_4 V_244 = F_197 ( V_1 , V_351 ) ;
int V_40 ;
V_40 = F_189 ( V_6 , V_152 ,
V_217 , V_219 ,
V_252 , V_254 ,
V_357 -> V_233 , V_357 -> V_235 ,
V_357 -> V_231 ,
V_1 , V_225 ,
V_258 , V_260 ,
V_262 , V_264 ,
V_244 ) ;
if ( V_40 )
F_116 ( V_6 -> V_28 , L_24 , V_40 ) ;
return V_40 ;
}
static int F_205 ( struct V_6 * V_6 ,
int V_152 , struct V_356 * V_357 ,
T_1 V_1 )
{
enum V_327 V_221 =
V_280 ;
T_4 V_244 = F_201 ( V_1 , 0 ) ;
T_4 V_248 = 0 ;
int V_40 ;
if ( ! F_6 ( V_6 ) )
return 0 ;
V_40 = F_188 ( V_6 , V_152 ,
V_357 -> V_233 , V_357 -> V_235 ,
V_1 , V_248 ,
V_221 , V_244 , V_357 -> V_236 ) ;
if ( V_40 )
F_116 ( V_6 -> V_28 , L_25 , V_40 ) ;
return V_40 ;
}
static int F_206 ( struct V_6 * V_6 ,
int V_152 , struct V_356 * V_357 ,
T_1 V_1 )
{
T_4 V_219 = 0xffffffff ;
T_1 V_225 = F_4 ( 0xffff ) ;
int V_40 ;
if ( F_2 ( V_1 ) == 0 )
V_1 = V_6 -> V_9 ;
V_40 = F_186 ( V_6 ,
V_6 -> V_142 , V_219 ,
V_357 -> V_231 , V_357 -> V_233 ,
V_357 -> V_235 , V_1 ,
V_225 , V_357 -> V_236 ,
V_152 ) ;
if ( V_40 )
F_116 ( V_6 -> V_28 , L_26 , V_40 ) ;
return V_40 ;
}
static int F_207 ( struct V_6 * V_6 , int V_152 ,
struct V_356 * V_357 , T_1 V_1 )
{
if ( V_357 -> V_250 )
return F_204 ( V_6 , V_152 ,
V_357 , V_1 ) ;
if ( V_357 -> V_245 )
return F_205 ( V_6 , V_152 ,
V_357 , V_1 ) ;
if ( V_357 -> V_358 )
return F_206 ( V_6 , V_152 ,
V_357 , V_1 ) ;
return - V_166 ;
}
static int F_208 ( struct V_6 * V_6 ,
int V_152 , T_1 V_1 )
{
int V_40 = 0 ;
int V_36 ;
for ( V_36 = 0 ; V_36 < V_359 ; V_36 ++ ) {
if ( V_6 -> V_360 [ V_36 ] ) {
V_40 = F_207 ( V_6 , V_152 ,
& V_361 [ V_36 ] , V_1 ) ;
if ( V_40 )
return V_40 ;
}
}
return V_40 ;
}
static int F_209 ( struct V_6 * V_6 , int V_152 ,
struct V_356 * V_357 )
{
T_2 V_7 ;
int V_40 = 0 ;
for ( V_7 = 1 ; V_7 < V_362 ; V_7 ++ ) {
if ( ! F_202 ( V_7 , V_6 -> V_353 ) )
continue;
V_40 = F_207 ( V_6 , V_152 ,
V_357 , F_4 ( V_7 ) ) ;
if ( V_40 )
break;
}
return V_40 ;
}
static int F_210 ( struct V_6 * V_6 , int V_152 ,
T_2 V_7 )
{
enum V_327 V_221 =
V_277 ;
T_4 V_217 = V_6 -> V_142 ;
T_1 V_1 = F_4 ( V_7 ) ;
T_1 V_225 = F_4 ( 0xffff ) ;
T_1 V_9 ;
bool V_226 ;
bool V_354 = ! ( V_152 & V_326 ) ;
int V_40 ;
V_9 = F_3 ( V_6 , V_7 , & V_226 ) ;
if ( V_354 && F_211 ( F_2 ( V_9 ) ,
V_6 -> V_353 ) )
return 0 ;
else if ( ! V_354 && ! F_212 ( F_2 ( V_9 ) ,
V_6 -> V_353 ) )
return 0 ;
if ( V_354 ) {
V_40 = F_208 ( V_6 , V_152 ,
V_9 ) ;
if ( V_40 ) {
F_116 ( V_6 -> V_28 ,
L_27 , V_40 ) ;
return V_40 ;
}
}
V_40 = F_203 ( V_6 , V_152 ,
V_9 , V_226 ) ;
if ( V_40 ) {
F_116 ( V_6 -> V_28 ,
L_28 , V_40 ) ;
return V_40 ;
}
V_40 = F_200 ( V_6 , V_152 ,
V_9 ) ;
if ( V_40 ) {
F_116 ( V_6 -> V_28 ,
L_21 , V_40 ) ;
return V_40 ;
}
V_40 = F_185 ( V_6 , V_152 ,
V_217 , V_1 , V_225 ,
V_221 , V_226 , V_9 ) ;
if ( V_40 )
F_116 ( V_6 -> V_28 ,
L_29 , V_40 ) ;
return V_40 ;
}
static int F_213 ( struct V_6 * V_6 , int V_152 )
{
enum V_327 V_221 ;
T_4 V_217 ;
T_4 V_219 ;
int V_40 ;
V_217 = 0 ;
V_219 = 0xffff0000 ;
V_221 = V_276 ;
V_40 = F_184 ( V_6 , V_152 ,
V_217 , V_219 ,
V_221 ) ;
if ( V_40 )
F_116 ( V_6 -> V_28 ,
L_30 , V_40 ) ;
return V_40 ;
}
static void F_214 ( struct V_363 * V_16 )
{
struct V_364 * V_365 =
F_215 ( V_16 , struct V_364 , V_16 ) ;
bool V_366 = ( V_365 -> V_152 & V_326 ) ;
bool V_367 = ( V_365 -> V_152 & V_154 ) ;
if ( V_367 && V_366 )
F_216 ( V_365 -> V_28 , V_365 -> V_151 , V_365 -> V_7 ) ;
else if ( V_367 && ! V_366 )
F_217 ( V_365 -> V_28 , V_365 -> V_151 , V_365 -> V_7 ) ;
F_13 ( V_16 ) ;
}
static int F_218 ( struct V_6 * V_6 ,
int V_152 , const T_9 * V_151 , T_1 V_1 )
{
struct V_364 * V_365 ;
enum V_327 V_221 =
V_280 ;
T_4 V_351 = V_6 -> V_142 ;
T_4 V_248 = 0 ;
T_4 V_244 = V_267 ;
bool V_368 = ! ! ( V_6 -> V_210 & V_369 ) ;
bool V_236 = false ;
int V_40 ;
if ( F_6 ( V_6 ) )
V_244 = F_197 ( V_1 , V_351 ) ;
if ( ! ( V_152 & V_370 ) ) {
V_40 = F_188 ( V_6 , V_152 , V_151 , NULL ,
V_1 , V_248 , V_221 ,
V_244 , V_236 ) ;
if ( V_40 )
return V_40 ;
}
if ( ! V_368 )
return 0 ;
if ( ! F_6 ( V_6 ) )
return 0 ;
V_365 = F_11 ( sizeof( * V_365 ) , F_182 ( V_152 ) ) ;
if ( ! V_365 )
return - V_44 ;
F_219 ( & V_365 -> V_16 , F_214 ) ;
V_365 -> V_28 = V_6 -> V_28 ;
V_365 -> V_152 = V_152 ;
F_144 ( V_365 -> V_151 , V_151 ) ;
V_365 -> V_7 = F_5 ( V_6 , V_1 ) ;
F_220 ( & V_365 -> V_16 ) ;
return 0 ;
}
static struct V_312 *
F_221 ( struct V_19 * V_19 , struct V_312 * V_319 )
{
struct V_312 * V_320 ;
F_177 (rocker->fdb_tbl, found, entry, match->key_crc32)
if ( memcmp ( & V_320 -> V_215 , & V_319 -> V_215 , sizeof( V_320 -> V_215 ) ) == 0 )
return V_320 ;
return NULL ;
}
static int F_131 ( struct V_6 * V_6 ,
const unsigned char * V_151 ,
T_1 V_1 , int V_152 )
{
struct V_19 * V_19 = V_6 -> V_19 ;
struct V_312 * V_371 ;
struct V_312 * V_320 ;
bool V_366 = ( V_152 & V_326 ) ;
unsigned long V_372 ;
V_371 = F_32 ( sizeof( * V_371 ) , F_182 ( V_152 ) ) ;
if ( ! V_371 )
return - V_44 ;
V_371 -> V_367 = ( V_152 & V_154 ) ;
V_371 -> V_215 . V_142 = V_6 -> V_142 ;
F_144 ( V_371 -> V_215 . V_151 , V_151 ) ;
V_371 -> V_215 . V_1 = V_1 ;
V_371 -> V_322 = F_179 ( ~ 0 , & V_371 -> V_215 , sizeof( V_371 -> V_215 ) ) ;
F_138 ( & V_19 -> V_307 , V_372 ) ;
V_320 = F_221 ( V_19 , V_371 ) ;
if ( V_366 && V_320 ) {
F_13 ( V_371 ) ;
F_175 ( & V_320 -> V_213 ) ;
} else if ( ! V_366 && ! V_320 ) {
F_180 ( V_19 -> V_306 , & V_371 -> V_213 , V_371 -> V_322 ) ;
}
F_139 ( & V_19 -> V_307 , V_372 ) ;
if ( ! V_320 != ! V_366 ) {
F_13 ( V_371 ) ;
if ( ! V_320 && V_366 )
return 0 ;
V_152 |= V_370 ;
}
return F_218 ( V_6 , V_152 , V_151 , V_1 ) ;
}
static int F_222 ( struct V_6 * V_6 )
{
struct V_19 * V_19 = V_6 -> V_19 ;
struct V_312 * V_320 ;
unsigned long V_372 ;
int V_152 = V_153 | V_326 ;
struct V_316 * V_317 ;
int V_318 ;
int V_40 = 0 ;
if ( V_6 -> V_158 == V_159 ||
V_6 -> V_158 == V_160 )
return 0 ;
F_138 ( & V_19 -> V_307 , V_372 ) ;
F_174 (rocker->fdb_tbl, bkt, tmp, found, entry) {
if ( V_320 -> V_215 . V_142 != V_6 -> V_142 )
continue;
if ( ! V_320 -> V_367 )
continue;
V_40 = F_218 ( V_6 , V_152 ,
V_320 -> V_215 . V_151 ,
V_320 -> V_215 . V_1 ) ;
if ( V_40 )
goto V_373;
F_175 ( & V_320 -> V_213 ) ;
}
V_373:
F_139 ( & V_19 -> V_307 , V_372 ) ;
return V_40 ;
}
static int F_223 ( struct V_6 * V_6 ,
int V_152 , T_1 V_1 )
{
T_4 V_219 = 0xffffffff ;
T_1 V_231 ;
const T_9 * V_374 = V_336 ;
T_1 V_225 = F_4 ( 0xffff ) ;
bool V_236 = false ;
int V_40 ;
if ( F_2 ( V_1 ) == 0 )
V_1 = V_6 -> V_9 ;
V_231 = F_4 ( V_255 ) ;
V_40 = F_186 ( V_6 ,
V_6 -> V_142 , V_219 ,
V_231 , V_6 -> V_28 -> V_375 ,
V_374 , V_1 , V_225 ,
V_236 , V_152 ) ;
if ( V_40 )
return V_40 ;
V_231 = F_4 ( V_256 ) ;
V_40 = F_186 ( V_6 ,
V_6 -> V_142 , V_219 ,
V_231 , V_6 -> V_28 -> V_375 ,
V_374 , V_1 , V_225 ,
V_236 , V_152 ) ;
return V_40 ;
}
static int F_224 ( struct V_6 * V_6 )
{
bool V_8 ;
T_4 V_351 ;
T_1 V_1 ;
T_2 V_7 ;
int V_152 = V_153 ;
int V_40 ;
if ( V_6 -> V_158 != V_159 &&
V_6 -> V_158 != V_160 )
V_152 |= V_326 ;
V_351 = V_6 -> V_142 ;
for ( V_7 = 1 ; V_7 < V_362 ; V_7 ++ ) {
if ( ! F_202 ( V_7 , V_6 -> V_353 ) )
continue;
V_1 = F_4 ( V_7 ) ;
V_8 = F_1 ( V_1 ) ;
V_40 = F_196 ( V_6 , V_152 ,
V_1 , V_351 ,
V_8 ) ;
if ( V_40 ) {
F_116 ( V_6 -> V_28 ,
L_22 ,
V_40 , V_351 ) ;
return V_40 ;
}
}
return 0 ;
}
static int F_225 ( struct V_6 * V_6 , T_9 V_376 )
{
bool V_377 [ V_359 ] = { 0 , } ;
int V_152 ;
int V_40 ;
int V_36 ;
if ( V_6 -> V_158 == V_376 )
return 0 ;
V_6 -> V_158 = V_376 ;
switch ( V_376 ) {
case V_378 :
break;
case V_379 :
case V_380 :
V_377 [ V_381 ] = true ;
break;
case V_159 :
case V_160 :
V_377 [ V_381 ] = true ;
V_377 [ V_382 ] = true ;
V_377 [ V_383 ] = true ;
if ( F_6 ( V_6 ) )
V_377 [ V_384 ] = true ;
else
V_377 [ V_385 ] = true ;
break;
}
for ( V_36 = 0 ; V_36 < V_359 ; V_36 ++ ) {
if ( V_377 [ V_36 ] != V_6 -> V_360 [ V_36 ] ) {
V_152 = V_153 |
( V_377 [ V_36 ] ? 0 : V_326 ) ;
V_40 = F_209 ( V_6 , V_152 ,
& V_361 [ V_36 ] ) ;
if ( V_40 )
return V_40 ;
V_6 -> V_360 [ V_36 ] = V_377 [ V_36 ] ;
}
}
V_40 = F_222 ( V_6 ) ;
if ( V_40 )
return V_40 ;
return F_224 ( V_6 ) ;
}
static struct V_314 *
F_226 ( struct V_19 * V_19 , int V_386 )
{
struct V_314 * V_320 ;
F_177 (rocker->internal_vlan_tbl, found,
entry, ifindex) {
if ( V_320 -> V_386 == V_386 )
return V_320 ;
}
return NULL ;
}
static T_1 F_227 ( struct V_6 * V_6 ,
int V_386 )
{
struct V_19 * V_19 = V_6 -> V_19 ;
struct V_314 * V_213 ;
struct V_314 * V_320 ;
unsigned long V_372 ;
int V_36 ;
V_213 = F_32 ( sizeof( * V_213 ) , V_42 ) ;
if ( ! V_213 )
return 0 ;
V_213 -> V_386 = V_386 ;
F_138 ( & V_19 -> V_309 , V_372 ) ;
V_320 = F_226 ( V_19 , V_386 ) ;
if ( V_320 ) {
F_13 ( V_213 ) ;
goto V_320;
}
V_320 = V_213 ;
F_180 ( V_19 -> V_308 , & V_320 -> V_213 , V_320 -> V_386 ) ;
for ( V_36 = 0 ; V_36 < V_387 ; V_36 ++ ) {
if ( F_211 ( V_36 , V_19 -> V_388 ) )
continue;
V_320 -> V_1 = F_4 ( V_3 + V_36 ) ;
goto V_320;
}
F_116 ( V_6 -> V_28 , L_31 ) ;
V_320:
V_320 -> V_324 ++ ;
F_139 ( & V_19 -> V_309 , V_372 ) ;
return V_320 -> V_1 ;
}
static void F_228 ( struct V_6 * V_6 ,
int V_386 )
{
struct V_19 * V_19 = V_6 -> V_19 ;
struct V_314 * V_320 ;
unsigned long V_372 ;
unsigned long V_389 ;
F_138 ( & V_19 -> V_309 , V_372 ) ;
V_320 = F_226 ( V_19 , V_386 ) ;
if ( ! V_320 ) {
F_116 ( V_6 -> V_28 ,
L_32 ,
V_386 ) ;
goto V_390;
}
if ( -- V_320 -> V_324 <= 0 ) {
V_389 = F_2 ( V_320 -> V_1 ) - V_3 ;
F_229 ( V_389 , V_19 -> V_388 ) ;
F_175 ( & V_320 -> V_213 ) ;
F_13 ( V_320 ) ;
}
V_390:
F_139 ( & V_19 -> V_309 , V_372 ) ;
}
static int F_230 ( struct V_125 * V_28 )
{
struct V_6 * V_6 = F_231 ( V_28 ) ;
T_9 V_158 = F_6 ( V_6 ) ?
V_380 : V_160 ;
int V_40 ;
V_40 = F_114 ( V_6 ) ;
if ( V_40 )
return V_40 ;
V_40 = F_40 ( F_19 ( V_6 ) ,
F_134 , 0 ,
V_58 , V_6 ) ;
if ( V_40 ) {
F_116 ( V_6 -> V_28 , L_33 ) ;
goto V_391;
}
V_40 = F_40 ( F_21 ( V_6 ) ,
F_136 , 0 ,
V_58 , V_6 ) ;
if ( V_40 ) {
F_116 ( V_6 -> V_28 , L_34 ) ;
goto V_392;
}
V_40 = F_225 ( V_6 , V_158 ) ;
if ( V_40 )
goto V_393;
F_232 ( & V_6 -> V_167 ) ;
F_232 ( & V_6 -> V_168 ) ;
F_119 ( V_6 , true ) ;
F_233 ( V_28 ) ;
return 0 ;
V_393:
V_60 ( F_21 ( V_6 ) , V_6 ) ;
V_392:
V_60 ( F_19 ( V_6 ) , V_6 ) ;
V_391:
F_118 ( V_6 ) ;
return V_40 ;
}
static int F_234 ( struct V_125 * V_28 )
{
struct V_6 * V_6 = F_231 ( V_28 ) ;
F_235 ( V_28 ) ;
F_119 ( V_6 , false ) ;
F_236 ( & V_6 -> V_168 ) ;
F_236 ( & V_6 -> V_167 ) ;
F_225 ( V_6 , V_378 ) ;
V_60 ( F_21 ( V_6 ) , V_6 ) ;
V_60 ( F_19 ( V_6 ) , V_6 ) ;
F_118 ( V_6 ) ;
return 0 ;
}
static void F_237 ( struct V_6 * V_6 ,
struct V_73 * V_74 )
{
struct V_19 * V_19 = V_6 -> V_19 ;
struct V_23 * V_24 = V_19 -> V_24 ;
struct V_61 * V_126 [ V_394 + 1 ] ;
struct V_61 * V_205 ;
int V_72 ;
F_58 ( V_126 , V_394 , V_74 ) ;
if ( ! V_126 [ V_395 ] )
return;
F_238 (attr, attrs[ROCKER_TLV_TX_FRAGS], rem) {
struct V_61 * V_396 [ V_397 + 1 ] ;
T_6 V_32 ;
T_7 V_65 ;
if ( F_47 ( V_205 ) != V_398 )
continue;
F_57 ( V_396 , V_397 ,
V_205 ) ;
if ( ! V_396 [ V_399 ] ||
! V_396 [ V_400 ] )
continue;
V_32 = F_54 ( V_396 [ V_399 ] ) ;
V_65 = F_51 ( V_396 [ V_400 ] ) ;
F_36 ( V_24 , V_32 , V_65 , V_401 ) ;
}
}
static int F_239 ( struct V_6 * V_6 ,
struct V_73 * V_74 ,
char * V_33 , T_7 V_70 )
{
struct V_19 * V_19 = V_6 -> V_19 ;
struct V_23 * V_24 = V_19 -> V_24 ;
T_6 V_32 ;
struct V_61 * V_402 ;
V_32 = F_33 ( V_24 , V_33 , V_70 , V_401 ) ;
if ( F_61 ( F_34 ( V_24 , V_32 ) ) ) {
if ( F_240 () )
F_116 ( V_6 -> V_28 , L_35 ) ;
return - V_29 ;
}
V_402 = F_68 ( V_74 , V_398 ) ;
if ( ! V_402 )
goto V_403;
if ( F_67 ( V_74 , V_399 ,
V_32 ) )
goto V_404;
if ( F_63 ( V_74 , V_400 ,
V_70 ) )
goto V_404;
F_69 ( V_74 , V_402 ) ;
return 0 ;
V_404:
F_70 ( V_74 , V_402 ) ;
V_403:
F_36 ( V_24 , V_32 , V_70 , V_401 ) ;
return - V_83 ;
}
static T_12 F_241 ( struct V_116 * V_117 , struct V_125 * V_28 )
{
struct V_6 * V_6 = F_231 ( V_28 ) ;
struct V_19 * V_19 = V_6 -> V_19 ;
struct V_73 * V_74 ;
struct V_61 * V_405 ;
int V_36 ;
int V_40 ;
V_74 = F_77 ( & V_6 -> V_130 ) ;
if ( F_61 ( ! V_74 ) ) {
if ( F_240 () )
F_116 ( V_28 , L_36 ) ;
return V_406 ;
}
F_76 ( V_74 , V_117 ) ;
V_405 = F_68 ( V_74 , V_395 ) ;
if ( ! V_405 )
goto V_175;
V_40 = F_239 ( V_6 , V_74 ,
V_117 -> V_75 , F_242 ( V_117 ) ) ;
if ( V_40 )
goto V_404;
if ( F_243 ( V_117 ) -> V_407 > V_408 )
goto V_404;
for ( V_36 = 0 ; V_36 < F_243 ( V_117 ) -> V_407 ; V_36 ++ ) {
const T_13 * V_402 = & F_243 ( V_117 ) -> V_405 [ V_36 ] ;
V_40 = F_239 ( V_6 , V_74 ,
F_244 ( V_402 ) ,
F_245 ( V_402 ) ) ;
if ( V_40 )
goto V_409;
}
F_69 ( V_74 , V_405 ) ;
F_73 ( V_74 ) ;
F_79 ( V_19 , & V_6 -> V_130 , V_74 ) ;
V_74 = F_77 ( & V_6 -> V_130 ) ;
if ( ! V_74 )
F_235 ( V_28 ) ;
return V_410 ;
V_409:
F_237 ( V_6 , V_74 ) ;
V_404:
F_70 ( V_74 , V_405 ) ;
V_175:
F_246 ( V_117 ) ;
return V_410 ;
}
static int F_247 ( struct V_125 * V_28 , void * V_352 )
{
struct V_411 * V_151 = V_352 ;
struct V_6 * V_6 = F_231 ( V_28 ) ;
int V_40 ;
if ( ! F_248 ( V_151 -> V_412 ) )
return - V_413 ;
V_40 = F_152 ( V_6 , V_151 -> V_412 ) ;
if ( V_40 )
return V_40 ;
memcpy ( V_28 -> V_375 , V_151 -> V_412 , V_28 -> V_414 ) ;
return 0 ;
}
static int F_249 ( struct V_125 * V_28 ,
T_1 V_415 , T_2 V_7 )
{
struct V_6 * V_6 = F_231 ( V_28 ) ;
int V_40 ;
V_40 = F_210 ( V_6 , 0 , V_7 ) ;
if ( V_40 )
return V_40 ;
return F_223 ( V_6 , 0 , F_4 ( V_7 ) ) ;
}
static int F_250 ( struct V_125 * V_28 ,
T_1 V_415 , T_2 V_7 )
{
struct V_6 * V_6 = F_231 ( V_28 ) ;
int V_40 ;
V_40 = F_223 ( V_6 , V_326 ,
F_4 ( V_7 ) ) ;
if ( V_40 )
return V_40 ;
return F_210 ( V_6 , V_326 , V_7 ) ;
}
static int F_251 ( struct V_416 * V_417 , struct V_418 * V_68 [] ,
struct V_125 * V_28 ,
const unsigned char * V_151 , T_2 V_7 ,
T_2 V_419 )
{
struct V_6 * V_6 = F_231 ( V_28 ) ;
T_1 V_1 = F_3 ( V_6 , V_7 , NULL ) ;
int V_152 = 0 ;
if ( ! F_6 ( V_6 ) )
return - V_148 ;
return F_131 ( V_6 , V_151 , V_1 , V_152 ) ;
}
static int F_252 ( struct V_416 * V_417 , struct V_418 * V_68 [] ,
struct V_125 * V_28 ,
const unsigned char * V_151 , T_2 V_7 )
{
struct V_6 * V_6 = F_231 ( V_28 ) ;
T_1 V_1 = F_3 ( V_6 , V_7 , NULL ) ;
int V_152 = V_326 ;
if ( ! F_6 ( V_6 ) )
return - V_148 ;
return F_131 ( V_6 , V_151 , V_1 , V_152 ) ;
}
static int F_253 ( struct V_116 * V_117 ,
struct V_6 * V_6 ,
const unsigned char * V_151 , T_2 V_7 ,
T_4 V_420 , T_4 V_421 , int type ,
unsigned int V_152 )
{
struct V_422 * V_423 ;
struct V_416 * V_417 ;
V_423 = F_254 ( V_117 , V_420 , V_421 , type , sizeof( * V_417 ) , V_152 ) ;
if ( ! V_423 )
return - V_83 ;
V_417 = F_255 ( V_423 ) ;
V_417 -> V_424 = V_425 ;
V_417 -> V_426 = 0 ;
V_417 -> V_427 = 0 ;
V_417 -> V_428 = V_429 ;
V_417 -> V_430 = 0 ;
V_417 -> V_431 = V_6 -> V_28 -> V_386 ;
V_417 -> V_432 = V_433 ;
if ( F_256 ( V_117 , V_434 , V_207 , V_151 ) )
goto V_435;
if ( V_7 && F_257 ( V_117 , V_436 , V_7 ) )
goto V_435;
return F_258 ( V_117 , V_423 ) ;
V_435:
F_259 ( V_117 , V_423 ) ;
return - V_83 ;
}
static int F_260 ( struct V_116 * V_117 ,
struct V_437 * V_438 ,
struct V_125 * V_28 ,
struct V_125 * V_439 ,
int V_440 )
{
struct V_6 * V_6 = F_231 ( V_28 ) ;
struct V_19 * V_19 = V_6 -> V_19 ;
struct V_312 * V_320 ;
struct V_316 * V_317 ;
int V_318 ;
unsigned long V_372 ;
const unsigned char * V_151 ;
T_2 V_7 ;
int V_40 ;
F_138 ( & V_19 -> V_307 , V_372 ) ;
F_174 (rocker->fdb_tbl, bkt, tmp, found, entry) {
if ( V_320 -> V_215 . V_142 != V_6 -> V_142 )
continue;
if ( V_440 < V_438 -> args [ 0 ] )
goto V_441;
V_151 = V_320 -> V_215 . V_151 ;
V_7 = F_5 ( V_6 , V_320 -> V_215 . V_1 ) ;
V_40 = F_253 ( V_117 , V_6 , V_151 , V_7 ,
F_261 ( V_438 -> V_117 ) . V_420 ,
V_438 -> V_423 -> V_442 ,
V_443 , V_444 ) ;
if ( V_40 < 0 )
break;
V_441:
++ V_440 ;
}
F_139 ( & V_19 -> V_307 , V_372 ) ;
return V_440 ;
}
static int F_262 ( struct V_125 * V_28 ,
struct V_422 * V_423 )
{
struct V_6 * V_6 = F_231 ( V_28 ) ;
struct V_418 * V_445 ;
struct V_418 * V_205 ;
int V_40 ;
V_445 = F_263 ( V_423 , sizeof( struct V_446 ) ,
V_447 ) ;
if ( V_445 ) {
V_205 = F_264 ( V_445 , V_448 ) ;
if ( V_205 ) {
if ( F_265 ( V_205 ) < sizeof( T_9 ) )
return - V_148 ;
if ( F_266 ( V_205 ) )
V_6 -> V_210 |= V_211 ;
else
V_6 -> V_210 &= ~ V_211 ;
V_40 = F_153 ( V_6 ) ;
if ( V_40 )
return V_40 ;
}
V_205 = F_264 ( V_445 , V_449 ) ;
if ( V_205 ) {
if ( F_265 ( V_205 ) < sizeof( T_9 ) )
return - V_148 ;
if ( F_266 ( V_205 ) )
V_6 -> V_210 |= V_369 ;
else
V_6 -> V_210 &= ~ V_369 ;
}
}
return 0 ;
}
static int F_267 ( struct V_116 * V_117 , T_4 V_450 , T_4 V_421 ,
struct V_125 * V_28 ,
T_4 V_451 )
{
struct V_6 * V_6 = F_231 ( V_28 ) ;
T_2 V_452 = V_453 ;
T_4 V_454 = V_211 | V_369 ;
return F_268 ( V_117 , V_450 , V_421 , V_28 , V_452 ,
V_6 -> V_210 , V_454 ) ;
}
static int F_269 ( struct V_125 * V_28 ,
struct V_455 * V_456 )
{
struct V_6 * V_6 = F_231 ( V_28 ) ;
struct V_19 * V_19 = V_6 -> V_19 ;
V_456 -> V_457 = sizeof( V_19 -> V_458 . V_459 ) ;
memcpy ( & V_456 -> V_459 , & V_19 -> V_458 . V_459 , V_456 -> V_457 ) ;
return 0 ;
}
static int F_270 ( struct V_125 * V_28 , T_9 V_376 )
{
struct V_6 * V_6 = F_231 ( V_28 ) ;
return F_225 ( V_6 , V_376 ) ;
}
static int F_271 ( struct V_125 * V_28 ,
struct V_182 * V_183 )
{
struct V_6 * V_6 = F_231 ( V_28 ) ;
return F_149 ( V_6 , V_183 ) ;
}
static int F_272 ( struct V_125 * V_28 ,
struct V_182 * V_183 )
{
struct V_6 * V_6 = F_231 ( V_28 ) ;
return F_151 ( V_6 , V_183 ) ;
}
static void F_273 ( struct V_125 * V_28 ,
struct V_460 * V_461 )
{
F_274 ( V_461 -> V_462 , V_58 , sizeof( V_461 -> V_462 ) ) ;
F_274 ( V_461 -> V_463 , V_464 , sizeof( V_461 -> V_463 ) ) ;
}
static struct V_6 * F_275 ( struct V_465 * V_466 )
{
return F_215 ( V_466 , struct V_6 , V_167 ) ;
}
static int F_276 ( struct V_465 * V_466 , int V_467 )
{
struct V_6 * V_6 = F_275 ( V_466 ) ;
struct V_19 * V_19 = V_6 -> V_19 ;
struct V_73 * V_74 ;
T_4 V_95 = 0 ;
int V_40 ;
while ( ( V_74 = F_82 ( & V_6 -> V_130 ) ) ) {
V_40 = F_72 ( V_74 ) ;
if ( V_40 && F_240 () )
F_116 ( V_6 -> V_28 , L_37 ,
V_40 ) ;
F_237 ( V_6 , V_74 ) ;
F_109 ( F_75 ( V_74 ) ) ;
V_95 ++ ;
}
if ( V_95 && F_277 ( V_6 -> V_28 ) )
F_278 ( V_6 -> V_28 ) ;
F_279 ( V_466 ) ;
F_83 ( V_19 , & V_6 -> V_130 , V_95 ) ;
return 0 ;
}
static int F_280 ( struct V_19 * V_19 ,
struct V_6 * V_6 ,
struct V_73 * V_74 )
{
struct V_61 * V_126 [ V_127 + 1 ] ;
struct V_116 * V_117 = F_75 ( V_74 ) ;
T_7 V_468 ;
if ( ! V_117 )
return - V_469 ;
F_58 ( V_126 , V_127 , V_74 ) ;
if ( ! V_126 [ V_470 ] )
return - V_148 ;
F_110 ( V_19 , V_126 ) ;
V_468 = F_51 ( V_126 [ V_470 ] ) ;
F_281 ( V_117 , V_468 ) ;
V_117 -> V_471 = F_282 ( V_117 , V_6 -> V_28 ) ;
F_283 ( V_117 ) ;
return F_107 ( V_19 , V_6 , V_74 ) ;
}
static struct V_6 * F_284 ( struct V_465 * V_466 )
{
return F_215 ( V_466 , struct V_6 , V_168 ) ;
}
static int F_285 ( struct V_465 * V_466 , int V_467 )
{
struct V_6 * V_6 = F_284 ( V_466 ) ;
struct V_19 * V_19 = V_6 -> V_19 ;
struct V_73 * V_74 ;
T_4 V_95 = 0 ;
int V_40 ;
while ( V_95 < V_467 &&
( V_74 = F_82 ( & V_6 -> V_128 ) ) ) {
V_40 = F_72 ( V_74 ) ;
if ( V_40 ) {
if ( F_240 () )
F_116 ( V_6 -> V_28 , L_38 ,
V_40 ) ;
} else {
V_40 = F_280 ( V_19 , V_6 ,
V_74 ) ;
if ( V_40 && F_240 () )
F_116 ( V_6 -> V_28 , L_39 ,
V_40 ) ;
}
F_73 ( V_74 ) ;
F_79 ( V_19 , & V_6 -> V_128 , V_74 ) ;
V_95 ++ ;
}
if ( V_95 < V_467 )
F_279 ( V_466 ) ;
F_83 ( V_19 , & V_6 -> V_128 , V_95 ) ;
return V_95 ;
}
static void F_286 ( struct V_6 * V_6 )
{
struct V_19 * V_19 = V_6 -> V_19 ;
T_5 V_472 = F_29 ( V_19 , V_473 ) ;
bool V_144 ;
V_144 = V_472 & ( 1 << V_6 -> V_142 ) ;
if ( V_144 )
F_124 ( V_6 -> V_28 ) ;
else
F_127 ( V_6 -> V_28 ) ;
}
static void F_287 ( struct V_19 * V_19 )
{
struct V_6 * V_6 ;
int V_36 ;
for ( V_36 = 0 ; V_36 < V_19 -> V_147 ; V_36 ++ ) {
V_6 = V_19 -> V_149 [ V_36 ] ;
F_213 ( V_6 , V_326 ) ;
F_288 ( V_6 -> V_28 ) ;
}
F_13 ( V_19 -> V_149 ) ;
}
static void F_289 ( struct V_19 * V_19 ,
struct V_6 * V_6 )
{
struct V_23 * V_24 = V_19 -> V_24 ;
int V_40 ;
V_40 = F_150 ( V_6 ,
V_6 -> V_28 -> V_375 ) ;
if ( V_40 ) {
F_290 ( & V_24 -> V_28 , L_40 ) ;
F_291 ( V_6 -> V_28 ) ;
}
}
static int F_292 ( struct V_19 * V_19 , unsigned int V_22 )
{
struct V_23 * V_24 = V_19 -> V_24 ;
struct V_6 * V_6 ;
struct V_125 * V_28 ;
int V_40 ;
V_28 = F_293 ( sizeof( struct V_6 ) ) ;
if ( ! V_28 )
return - V_44 ;
V_6 = F_231 ( V_28 ) ;
V_6 -> V_28 = V_28 ;
V_6 -> V_19 = V_19 ;
V_6 -> V_22 = V_22 ;
V_6 -> V_142 = V_22 + 1 ;
V_6 -> V_210 = V_211 | V_369 ;
F_289 ( V_19 , V_6 ) ;
V_28 -> V_474 = & V_475 ;
V_28 -> V_476 = & V_477 ;
F_294 ( V_28 , & V_6 -> V_167 , F_276 ,
V_478 ) ;
F_294 ( V_28 , & V_6 -> V_168 , F_285 ,
V_478 ) ;
F_286 ( V_6 ) ;
V_28 -> V_479 |= V_480 ;
V_40 = F_295 ( V_28 ) ;
if ( V_40 ) {
F_27 ( & V_24 -> V_28 , L_41 ) ;
goto V_481;
}
V_19 -> V_149 [ V_22 ] = V_6 ;
F_153 ( V_6 ) ;
V_6 -> V_9 =
F_227 ( V_6 , V_28 -> V_386 ) ;
V_40 = F_213 ( V_6 , 0 ) ;
if ( V_40 ) {
F_27 ( & V_24 -> V_28 , L_42 ) ;
goto V_482;
}
return 0 ;
V_482:
F_288 ( V_28 ) ;
V_481:
F_296 ( V_28 ) ;
return V_40 ;
}
static int F_297 ( struct V_19 * V_19 )
{
int V_36 ;
T_7 V_483 ;
int V_40 ;
V_483 = sizeof( struct V_6 * ) * V_19 -> V_147 ;
V_19 -> V_149 = F_11 ( V_483 , V_42 ) ;
for ( V_36 = 0 ; V_36 < V_19 -> V_147 ; V_36 ++ ) {
V_40 = F_292 ( V_19 , V_36 ) ;
if ( V_40 )
goto V_484;
}
return 0 ;
V_484:
F_287 ( V_19 ) ;
return V_40 ;
}
static int F_298 ( struct V_19 * V_19 )
{
struct V_23 * V_24 = V_19 -> V_24 ;
int V_21 ;
int V_36 ;
int V_40 ;
V_21 = F_299 ( V_24 ) ;
if ( V_21 < 0 )
return V_21 ;
if ( V_21 != F_300 ( V_19 -> V_147 ) )
return - V_148 ;
V_19 -> V_21 = F_301 ( V_21 ,
sizeof( struct V_485 ) ,
V_42 ) ;
if ( ! V_19 -> V_21 )
return - V_44 ;
for ( V_36 = 0 ; V_36 < V_21 ; V_36 ++ )
V_19 -> V_21 [ V_36 ] . V_213 = V_36 ;
V_40 = F_302 ( V_24 , V_19 -> V_21 , V_21 ) ;
if ( V_40 < 0 )
goto V_486;
return 0 ;
V_486:
F_13 ( V_19 -> V_21 ) ;
return V_40 ;
}
static void F_303 ( struct V_19 * V_19 )
{
F_304 ( V_19 -> V_24 ) ;
F_13 ( V_19 -> V_21 ) ;
}
static int F_305 ( struct V_23 * V_24 , const struct V_487 * V_459 )
{
struct V_19 * V_19 ;
int V_40 ;
V_19 = F_32 ( sizeof( * V_19 ) , V_42 ) ;
if ( ! V_19 )
return - V_44 ;
V_40 = F_306 ( V_24 ) ;
if ( V_40 ) {
F_27 ( & V_24 -> V_28 , L_43 ) ;
goto V_488;
}
V_40 = F_307 ( V_24 , V_58 ) ;
if ( V_40 ) {
F_27 ( & V_24 -> V_28 , L_44 ) ;
goto V_489;
}
V_40 = F_308 ( V_24 , F_309 ( 64 ) ) ;
if ( ! V_40 ) {
V_40 = F_310 ( V_24 , F_309 ( 64 ) ) ;
if ( V_40 ) {
F_27 ( & V_24 -> V_28 , L_45 ) ;
goto V_490;
}
} else {
V_40 = F_308 ( V_24 , F_309 ( 32 ) ) ;
if ( V_40 ) {
F_27 ( & V_24 -> V_28 , L_46 ) ;
goto V_490;
}
}
if ( F_311 ( V_24 , 0 ) < V_491 ) {
F_27 ( & V_24 -> V_28 , L_47 ) ;
goto V_492;
}
V_19 -> V_493 = F_312 ( F_313 ( V_24 , 0 ) ,
F_311 ( V_24 , 0 ) ) ;
if ( ! V_19 -> V_493 ) {
F_27 ( & V_24 -> V_28 , L_48 ) ;
V_40 = - V_29 ;
goto V_494;
}
F_314 ( V_24 ) ;
V_19 -> V_24 = V_24 ;
F_315 ( V_24 , V_19 ) ;
V_19 -> V_147 = F_26 ( V_19 , V_495 ) ;
V_40 = F_298 ( V_19 ) ;
if ( V_40 ) {
F_27 ( & V_24 -> V_28 , L_49 ) ;
goto V_496;
}
V_40 = F_39 ( V_19 ) ;
if ( V_40 ) {
F_27 ( & V_24 -> V_28 , L_50 ) ;
goto V_497;
}
F_25 ( V_19 , V_498 , V_499 ) ;
V_40 = F_102 ( V_19 ) ;
if ( V_40 )
goto V_500;
V_40 = F_40 ( F_18 ( V_19 , V_501 ) ,
F_120 , 0 ,
V_58 , V_19 ) ;
if ( V_40 ) {
F_27 ( & V_24 -> V_28 , L_51 ) ;
goto V_502;
}
V_40 = F_40 ( F_18 ( V_19 , V_503 ) ,
F_133 , 0 ,
V_58 , V_19 ) ;
if ( V_40 ) {
F_27 ( & V_24 -> V_28 , L_52 ) ;
goto V_504;
}
V_19 -> V_458 . V_459 = F_29 ( V_19 , V_505 ) ;
V_40 = F_171 ( V_19 ) ;
if ( V_40 ) {
F_27 ( & V_24 -> V_28 , L_53 ) ;
goto V_506;
}
V_40 = F_297 ( V_19 ) ;
if ( V_40 ) {
F_27 ( & V_24 -> V_28 , L_54 ) ;
goto V_507;
}
F_316 ( & V_24 -> V_28 , L_55 , V_19 -> V_458 . V_459 ) ;
return 0 ;
V_507:
F_173 ( V_19 ) ;
V_506:
V_60 ( F_18 ( V_19 , V_503 ) , V_19 ) ;
V_504:
V_60 ( F_18 ( V_19 , V_501 ) , V_19 ) ;
V_502:
F_104 ( V_19 ) ;
V_500:
V_497:
F_303 ( V_19 ) ;
V_496:
F_317 ( V_19 -> V_493 ) ;
V_494:
V_492:
V_490:
F_318 ( V_24 ) ;
V_489:
F_319 ( V_24 ) ;
V_488:
F_13 ( V_19 ) ;
return V_40 ;
}
static void F_320 ( struct V_23 * V_24 )
{
struct V_19 * V_19 = F_321 ( V_24 ) ;
F_173 ( V_19 ) ;
F_25 ( V_19 , V_498 , V_499 ) ;
F_287 ( V_19 ) ;
V_60 ( F_18 ( V_19 , V_503 ) , V_19 ) ;
V_60 ( F_18 ( V_19 , V_501 ) , V_19 ) ;
F_104 ( V_19 ) ;
F_303 ( V_19 ) ;
F_317 ( V_19 -> V_493 ) ;
F_318 ( V_19 -> V_24 ) ;
F_319 ( V_19 -> V_24 ) ;
F_13 ( V_19 ) ;
}
static bool F_322 ( struct V_125 * V_28 )
{
return V_28 -> V_474 == & V_475 ;
}
static int F_323 ( struct V_6 * V_6 ,
struct V_125 * V_245 )
{
int V_40 ;
F_228 ( V_6 ,
V_6 -> V_28 -> V_386 ) ;
V_6 -> V_10 = V_245 ;
V_40 = F_210 ( V_6 , V_326 , 0 ) ;
if ( V_40 )
return V_40 ;
V_6 -> V_9 =
F_227 ( V_6 ,
V_245 -> V_386 ) ;
V_40 = F_210 ( V_6 , 0 , 0 ) ;
return V_40 ;
}
static int F_324 ( struct V_6 * V_6 )
{
int V_40 ;
F_228 ( V_6 ,
V_6 -> V_10 -> V_386 ) ;
V_6 -> V_10 = NULL ;
V_40 = F_210 ( V_6 , V_326 , 0 ) ;
if ( V_40 )
return V_40 ;
V_6 -> V_9 =
F_227 ( V_6 ,
V_6 -> V_28 -> V_386 ) ;
V_40 = F_210 ( V_6 , 0 , 0 ) ;
return V_40 ;
}
static int F_325 ( struct V_125 * V_28 )
{
struct V_6 * V_6 = F_231 ( V_28 ) ;
struct V_125 * V_508 = F_326 ( V_28 ) ;
int V_40 = 0 ;
if ( V_508 && V_508 -> V_509 &&
! strcmp ( V_508 -> V_509 -> V_510 , L_56 ) )
V_40 = F_323 ( V_6 , V_508 ) ;
else
V_40 = F_324 ( V_6 ) ;
return V_40 ;
}
static int F_327 ( struct V_511 * V_512 ,
unsigned long V_513 , void * V_90 )
{
struct V_125 * V_28 ;
int V_40 ;
switch ( V_513 ) {
case V_514 :
V_28 = F_328 ( V_90 ) ;
if ( ! F_322 ( V_28 ) )
return V_515 ;
V_40 = F_325 ( V_28 ) ;
if ( V_40 )
F_329 ( V_28 ,
L_57 ,
V_40 ) ;
break;
}
return V_515 ;
}
static int T_14 F_330 ( void )
{
int V_40 ;
F_331 ( & V_516 ) ;
V_40 = F_332 ( & V_517 ) ;
if ( V_40 )
goto V_518;
return 0 ;
V_518:
F_333 ( & V_516 ) ;
return V_40 ;
}
static void T_15 F_334 ( void )
{
F_333 ( & V_516 ) ;
F_335 ( & V_517 ) ;
}
