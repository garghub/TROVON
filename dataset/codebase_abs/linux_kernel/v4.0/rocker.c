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
return ( void * ) ( V_89 ) V_74 -> V_76 -> V_90 ;
}
static void F_76 ( struct V_73 * V_74 ,
void * V_91 )
{
V_74 -> V_76 -> V_90 = ( V_89 ) V_91 ;
}
static struct V_73 *
F_77 ( struct V_92 * V_93 )
{
static struct V_73 * V_74 ;
T_4 V_71 = F_71 ( V_93 -> V_71 , V_93 -> V_35 ) ;
V_74 = & V_93 -> V_74 [ V_93 -> V_71 ] ;
if ( V_71 == V_93 -> V_94 )
return NULL ;
V_74 -> V_77 = 0 ;
return V_74 ;
}
static void F_78 ( struct V_73 * V_74 )
{
V_74 -> V_76 -> V_95 = V_74 -> V_81 ;
V_74 -> V_76 -> V_77 = V_74 -> V_77 ;
}
static void F_79 ( struct V_19 * V_19 ,
struct V_92 * V_93 ,
struct V_73 * V_74 )
{
T_4 V_71 = F_71 ( V_93 -> V_71 , V_93 -> V_35 ) ;
F_80 ( V_71 == V_93 -> V_94 ) ;
F_78 ( V_74 ) ;
V_93 -> V_71 = V_71 ;
F_25 ( V_19 , F_81 ( V_93 -> type ) , V_71 ) ;
}
static struct V_73 *
F_82 ( struct V_92 * V_93 )
{
static struct V_73 * V_74 ;
if ( V_93 -> V_94 == V_93 -> V_71 )
return NULL ;
V_74 = & V_93 -> V_74 [ V_93 -> V_94 ] ;
if ( ! F_74 ( V_74 ) )
return NULL ;
V_93 -> V_94 = F_71 ( V_93 -> V_94 , V_93 -> V_35 ) ;
V_74 -> V_77 = V_74 -> V_76 -> V_77 ;
return V_74 ;
}
static void F_83 ( struct V_19 * V_19 ,
struct V_92 * V_93 ,
T_4 V_96 )
{
if ( V_96 )
F_25 ( V_19 , F_84 ( V_93 -> type ) , V_96 ) ;
}
static unsigned long F_85 ( T_7 V_35 )
{
return F_86 ( V_97 ,
F_87 ( F_88 ( V_35 ) , V_98 ) ) ;
}
static int F_89 ( struct V_19 * V_19 ,
unsigned int type ,
T_7 V_35 ,
struct V_92 * V_93 )
{
int V_36 ;
F_80 ( V_35 != F_85 ( V_35 ) ) ;
V_93 -> V_35 = V_35 ;
V_93 -> type = type ;
V_93 -> V_71 = 0 ;
V_93 -> V_94 = 0 ;
V_93 -> V_74 = F_90 ( V_93 -> V_35 , sizeof( * V_93 -> V_74 ) ,
V_42 ) ;
if ( ! V_93 -> V_74 )
return - V_44 ;
V_93 -> V_76 = F_91 ( V_19 -> V_24 ,
V_93 -> V_35 * sizeof( * V_93 -> V_76 ) ,
& V_93 -> V_99 ) ;
if ( ! V_93 -> V_76 ) {
F_13 ( V_93 -> V_74 ) ;
return - V_44 ;
}
for ( V_36 = 0 ; V_36 < V_93 -> V_35 ; V_36 ++ )
V_93 -> V_74 [ V_36 ] . V_76 = & V_93 -> V_76 [ V_36 ] ;
F_25 ( V_19 , F_92 ( V_93 -> type ) ,
V_100 ) ;
F_28 ( V_19 , F_93 ( V_93 -> type ) , V_93 -> V_99 ) ;
F_25 ( V_19 , F_94 ( V_93 -> type ) , V_93 -> V_35 ) ;
return 0 ;
}
static void F_95 ( struct V_19 * V_19 ,
struct V_92 * V_93 )
{
F_28 ( V_19 , F_93 ( V_93 -> type ) , 0 ) ;
F_96 ( V_19 -> V_24 ,
V_93 -> V_35 * sizeof( struct V_101 ) ,
V_93 -> V_76 , V_93 -> V_99 ) ;
F_13 ( V_93 -> V_74 ) ;
}
static void F_97 ( struct V_19 * V_19 ,
struct V_92 * V_93 )
{
int V_36 ;
F_80 ( V_93 -> V_71 || V_93 -> V_94 ) ;
for ( V_36 = 0 ; V_36 < V_93 -> V_35 - 1 ; V_36 ++ )
F_79 ( V_19 , V_93 , & V_93 -> V_74 [ V_36 ] ) ;
F_78 ( & V_93 -> V_74 [ V_36 ] ) ;
}
static int F_98 ( struct V_19 * V_19 ,
struct V_92 * V_93 ,
int V_102 , T_7 V_95 )
{
struct V_23 * V_24 = V_19 -> V_24 ;
int V_36 ;
int V_40 ;
for ( V_36 = 0 ; V_36 < V_93 -> V_35 ; V_36 ++ ) {
struct V_73 * V_74 = & V_93 -> V_74 [ V_36 ] ;
struct V_101 * V_76 = & V_93 -> V_76 [ V_36 ] ;
T_6 V_32 ;
char * V_33 ;
V_33 = F_32 ( V_95 , V_42 | V_43 ) ;
if ( ! V_33 ) {
V_40 = - V_44 ;
goto V_103;
}
V_32 = F_33 ( V_24 , V_33 , V_95 , V_102 ) ;
if ( F_34 ( V_24 , V_32 ) ) {
F_13 ( V_33 ) ;
V_40 = - V_29 ;
goto V_103;
}
V_74 -> V_75 = V_33 ;
V_74 -> V_81 = V_95 ;
F_99 ( V_74 , V_99 , V_32 ) ;
V_76 -> V_104 = V_32 ;
V_76 -> V_95 = V_95 ;
}
return 0 ;
V_103:
for ( V_36 -- ; V_36 >= 0 ; V_36 -- ) {
struct V_73 * V_74 = & V_93 -> V_74 [ V_36 ] ;
F_36 ( V_24 , F_100 ( V_74 , V_99 ) ,
V_74 -> V_81 , V_102 ) ;
F_13 ( V_74 -> V_75 ) ;
}
return V_40 ;
}
static void F_101 ( struct V_19 * V_19 ,
struct V_92 * V_93 ,
int V_102 )
{
struct V_23 * V_24 = V_19 -> V_24 ;
int V_36 ;
for ( V_36 = 0 ; V_36 < V_93 -> V_35 ; V_36 ++ ) {
struct V_73 * V_74 = & V_93 -> V_74 [ V_36 ] ;
struct V_101 * V_76 = & V_93 -> V_76 [ V_36 ] ;
V_76 -> V_104 = 0 ;
V_76 -> V_95 = 0 ;
F_36 ( V_24 , F_100 ( V_74 , V_99 ) ,
V_74 -> V_81 , V_102 ) ;
F_13 ( V_74 -> V_75 ) ;
}
}
static int F_102 ( struct V_19 * V_19 )
{
struct V_23 * V_24 = V_19 -> V_24 ;
int V_40 ;
V_40 = F_89 ( V_19 , V_105 ,
V_106 ,
& V_19 -> V_107 ) ;
if ( V_40 ) {
F_27 ( & V_24 -> V_28 , L_8 ) ;
return V_40 ;
}
F_103 ( & V_19 -> V_108 ) ;
V_40 = F_98 ( V_19 , & V_19 -> V_107 ,
V_45 , V_109 ) ;
if ( V_40 ) {
F_27 ( & V_24 -> V_28 , L_9 ) ;
goto V_110;
}
V_40 = F_89 ( V_19 , V_111 ,
V_112 ,
& V_19 -> V_113 ) ;
if ( V_40 ) {
F_27 ( & V_24 -> V_28 , L_10 ) ;
goto V_114;
}
V_40 = F_98 ( V_19 , & V_19 -> V_113 ,
V_115 , V_109 ) ;
if ( V_40 ) {
F_27 ( & V_24 -> V_28 , L_11 ) ;
goto V_116;
}
F_97 ( V_19 , & V_19 -> V_113 ) ;
return 0 ;
V_116:
F_95 ( V_19 , & V_19 -> V_113 ) ;
V_114:
F_101 ( V_19 , & V_19 -> V_107 ,
V_45 ) ;
V_110:
F_95 ( V_19 , & V_19 -> V_107 ) ;
return V_40 ;
}
static void F_104 ( struct V_19 * V_19 )
{
F_101 ( V_19 , & V_19 -> V_113 ,
V_45 ) ;
F_95 ( V_19 , & V_19 -> V_113 ) ;
F_101 ( V_19 , & V_19 -> V_107 ,
V_45 ) ;
F_95 ( V_19 , & V_19 -> V_107 ) ;
}
static int F_105 ( struct V_19 * V_19 ,
struct V_6 * V_6 ,
struct V_73 * V_74 ,
struct V_117 * V_118 , T_7 V_70 )
{
struct V_23 * V_24 = V_19 -> V_24 ;
T_6 V_32 ;
V_32 = F_33 ( V_24 , V_118 -> V_75 , V_70 ,
V_115 ) ;
if ( F_34 ( V_24 , V_32 ) )
return - V_29 ;
if ( F_67 ( V_74 , V_119 , V_32 ) )
goto V_120;
if ( F_63 ( V_74 , V_121 , V_70 ) )
goto V_120;
return 0 ;
V_120:
F_36 ( V_24 , V_32 , V_70 , V_115 ) ;
V_74 -> V_77 = 0 ;
return - V_83 ;
}
static T_7 F_106 ( struct V_6 * V_6 )
{
return V_6 -> V_28 -> V_122 + V_123 + V_124 + V_125 ;
}
static int F_107 ( struct V_19 * V_19 ,
struct V_6 * V_6 ,
struct V_73 * V_74 )
{
struct V_126 * V_28 = V_6 -> V_28 ;
struct V_117 * V_118 ;
T_7 V_70 = F_106 ( V_6 ) ;
int V_40 ;
F_76 ( V_74 , NULL ) ;
V_74 -> V_77 = 0 ;
V_118 = F_108 ( V_28 , V_70 ) ;
if ( ! V_118 )
return - V_44 ;
V_40 = F_105 ( V_19 , V_6 , V_74 ,
V_118 , V_70 ) ;
if ( V_40 ) {
F_109 ( V_118 ) ;
return V_40 ;
}
F_76 ( V_74 , V_118 ) ;
return 0 ;
}
static void F_110 ( struct V_19 * V_19 ,
struct V_61 * * V_127 )
{
struct V_23 * V_24 = V_19 -> V_24 ;
T_6 V_32 ;
T_7 V_65 ;
if ( ! V_127 [ V_119 ] ||
! V_127 [ V_121 ] )
return;
V_32 = F_54 ( V_127 [ V_119 ] ) ;
V_65 = F_51 ( V_127 [ V_121 ] ) ;
F_36 ( V_24 , V_32 , V_65 , V_115 ) ;
}
static void F_111 ( struct V_19 * V_19 ,
struct V_73 * V_74 )
{
struct V_61 * V_127 [ V_128 + 1 ] ;
struct V_117 * V_118 = F_75 ( V_74 ) ;
if ( ! V_118 )
return;
F_58 ( V_127 , V_128 , V_74 ) ;
F_110 ( V_19 , V_127 ) ;
F_109 ( V_118 ) ;
}
static int F_112 ( struct V_19 * V_19 ,
struct V_6 * V_6 )
{
struct V_92 * V_129 = & V_6 -> V_129 ;
int V_36 ;
int V_40 ;
for ( V_36 = 0 ; V_36 < V_129 -> V_35 ; V_36 ++ ) {
V_40 = F_107 ( V_19 , V_6 ,
& V_129 -> V_74 [ V_36 ] ) ;
if ( V_40 )
goto V_103;
}
return 0 ;
V_103:
for ( V_36 -- ; V_36 >= 0 ; V_36 -- )
F_111 ( V_19 , & V_129 -> V_74 [ V_36 ] ) ;
return V_40 ;
}
static void F_113 ( struct V_19 * V_19 ,
struct V_6 * V_6 )
{
struct V_92 * V_129 = & V_6 -> V_129 ;
int V_36 ;
for ( V_36 = 0 ; V_36 < V_129 -> V_35 ; V_36 ++ )
F_111 ( V_19 , & V_129 -> V_74 [ V_36 ] ) ;
}
static int F_114 ( struct V_6 * V_6 )
{
struct V_19 * V_19 = V_6 -> V_19 ;
int V_40 ;
V_40 = F_89 ( V_19 ,
F_115 ( V_6 -> V_22 ) ,
V_130 ,
& V_6 -> V_131 ) ;
if ( V_40 ) {
F_116 ( V_6 -> V_28 , L_12 ) ;
return V_40 ;
}
V_40 = F_98 ( V_19 , & V_6 -> V_131 ,
V_132 ,
V_133 ) ;
if ( V_40 ) {
F_116 ( V_6 -> V_28 , L_13 ) ;
goto V_134;
}
V_40 = F_89 ( V_19 ,
F_117 ( V_6 -> V_22 ) ,
V_135 ,
& V_6 -> V_129 ) ;
if ( V_40 ) {
F_116 ( V_6 -> V_28 , L_14 ) ;
goto V_136;
}
V_40 = F_98 ( V_19 , & V_6 -> V_129 ,
V_45 ,
V_137 ) ;
if ( V_40 ) {
F_116 ( V_6 -> V_28 , L_15 ) ;
goto V_138;
}
V_40 = F_112 ( V_19 , V_6 ) ;
if ( V_40 ) {
F_116 ( V_6 -> V_28 , L_16 ) ;
goto V_139;
}
F_97 ( V_19 , & V_6 -> V_129 ) ;
return 0 ;
V_139:
F_101 ( V_19 , & V_6 -> V_129 ,
V_45 ) ;
V_138:
F_95 ( V_19 , & V_6 -> V_129 ) ;
V_136:
F_101 ( V_19 , & V_6 -> V_131 ,
V_132 ) ;
V_134:
F_95 ( V_19 , & V_6 -> V_131 ) ;
return V_40 ;
}
static void F_118 ( struct V_6 * V_6 )
{
struct V_19 * V_19 = V_6 -> V_19 ;
F_113 ( V_19 , V_6 ) ;
F_101 ( V_19 , & V_6 -> V_129 ,
V_45 ) ;
F_95 ( V_19 , & V_6 -> V_129 ) ;
F_101 ( V_19 , & V_6 -> V_131 ,
V_132 ) ;
F_95 ( V_19 , & V_6 -> V_131 ) ;
}
static void F_119 ( struct V_6 * V_6 , bool V_140 )
{
T_5 V_141 = F_29 ( V_6 -> V_19 , V_142 ) ;
if ( V_140 )
V_141 |= 1ULL << V_6 -> V_143 ;
else
V_141 &= ~ ( 1ULL << V_6 -> V_143 ) ;
F_28 ( V_6 -> V_19 , V_142 , V_141 ) ;
}
static T_8 F_120 ( int V_54 , void * V_55 )
{
struct V_19 * V_19 = V_55 ;
struct V_73 * V_74 ;
struct V_11 * V_12 ;
T_4 V_96 = 0 ;
F_121 ( & V_19 -> V_108 ) ;
while ( ( V_74 = F_82 ( & V_19 -> V_107 ) ) ) {
V_12 = F_75 ( V_74 ) ;
if ( V_12 -> V_14 ) {
F_73 ( V_74 ) ;
F_12 ( V_12 ) ;
} else {
F_16 ( V_12 ) ;
}
V_96 ++ ;
}
F_122 ( & V_19 -> V_108 ) ;
F_83 ( V_19 , & V_19 -> V_107 , V_96 ) ;
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
const struct V_61 * V_93 )
{
struct V_61 * V_127 [ V_144 + 1 ] ;
unsigned int V_22 ;
bool V_145 ;
struct V_6 * V_6 ;
F_57 ( V_127 , V_144 , V_93 ) ;
if ( ! V_127 [ V_146 ] ||
! V_127 [ V_147 ] )
return - V_29 ;
V_22 =
F_53 ( V_127 [ V_146 ] ) - 1 ;
V_145 = F_50 ( V_127 [ V_147 ] ) ;
if ( V_22 >= V_19 -> V_148 )
return - V_149 ;
V_6 = V_19 -> V_150 [ V_22 ] ;
if ( F_129 ( V_6 -> V_28 ) != V_145 ) {
if ( V_145 )
F_123 ( V_6 ) ;
else
F_126 ( V_6 ) ;
}
return 0 ;
}
static int F_130 ( struct V_19 * V_19 ,
const struct V_61 * V_93 )
{
struct V_61 * V_127 [ V_151 + 1 ] ;
unsigned int V_22 ;
struct V_6 * V_6 ;
unsigned char * V_152 ;
int V_153 = V_154 | V_155 ;
T_1 V_1 ;
F_57 ( V_127 , V_151 , V_93 ) ;
if ( ! V_127 [ V_156 ] ||
! V_127 [ V_157 ] ||
! V_127 [ V_158 ] )
return - V_29 ;
V_22 =
F_53 ( V_127 [ V_156 ] ) - 1 ;
V_152 = F_48 ( V_127 [ V_157 ] ) ;
V_1 = F_52 ( V_127 [ V_158 ] ) ;
if ( V_22 >= V_19 -> V_148 )
return - V_149 ;
V_6 = V_19 -> V_150 [ V_22 ] ;
if ( V_6 -> V_159 != V_160 &&
V_6 -> V_159 != V_161 )
return 0 ;
return F_131 ( V_6 , V_152 , V_1 , V_153 ) ;
}
static int F_132 ( struct V_19 * V_19 ,
struct V_73 * V_74 )
{
struct V_61 * V_127 [ V_162 + 1 ] ;
struct V_61 * V_93 ;
T_2 type ;
F_58 ( V_127 , V_162 , V_74 ) ;
if ( ! V_127 [ V_163 ] ||
! V_127 [ V_164 ] )
return - V_29 ;
type = F_51 ( V_127 [ V_163 ] ) ;
V_93 = V_127 [ V_164 ] ;
switch ( type ) {
case V_165 :
return F_128 ( V_19 , V_93 ) ;
case V_166 :
return F_130 ( V_19 , V_93 ) ;
}
return - V_167 ;
}
static T_8 F_133 ( int V_54 , void * V_55 )
{
struct V_19 * V_19 = V_55 ;
struct V_23 * V_24 = V_19 -> V_24 ;
struct V_73 * V_74 ;
T_4 V_96 = 0 ;
int V_40 ;
while ( ( V_74 = F_82 ( & V_19 -> V_113 ) ) ) {
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
F_79 ( V_19 , & V_19 -> V_113 , V_74 ) ;
V_96 ++ ;
}
F_83 ( V_19 , & V_19 -> V_113 , V_96 ) ;
return V_56 ;
}
static T_8 F_134 ( int V_54 , void * V_55 )
{
struct V_6 * V_6 = V_55 ;
F_135 ( & V_6 -> V_168 ) ;
return V_56 ;
}
static T_8 F_136 ( int V_54 , void * V_55 )
{
struct V_6 * V_6 = V_55 ;
F_135 ( & V_6 -> V_169 ) ;
return V_56 ;
}
static int F_137 ( struct V_19 * V_19 ,
struct V_6 * V_6 ,
T_11 V_170 , void * V_171 ,
T_11 V_172 , void * V_173 ,
bool V_14 )
{
struct V_73 * V_74 ;
struct V_11 * V_12 ;
unsigned long V_153 ;
int V_40 ;
V_12 = F_10 ( V_14 ? V_174 : V_42 ) ;
if ( ! V_12 )
return - V_44 ;
V_12 -> V_14 = V_14 ;
F_138 ( & V_19 -> V_108 , V_153 ) ;
V_74 = F_77 ( & V_19 -> V_107 ) ;
if ( ! V_74 ) {
F_139 ( & V_19 -> V_108 , V_153 ) ;
V_40 = - V_175 ;
goto V_176;
}
V_40 = V_170 ( V_19 , V_6 , V_74 , V_171 ) ;
if ( V_40 ) {
F_139 ( & V_19 -> V_108 , V_153 ) ;
goto V_176;
}
F_76 ( V_74 , V_12 ) ;
F_79 ( V_19 , & V_19 -> V_107 , V_74 ) ;
F_139 ( & V_19 -> V_108 , V_153 ) ;
if ( V_14 )
return 0 ;
if ( ! F_14 ( V_12 , V_18 / 10 ) )
return - V_29 ;
V_40 = F_72 ( V_74 ) ;
if ( V_40 )
return V_40 ;
if ( V_172 )
V_40 = V_172 ( V_19 , V_6 , V_74 , V_173 ) ;
F_73 ( V_74 ) ;
V_176:
F_12 ( V_12 ) ;
return V_40 ;
}
static int
F_140 ( struct V_19 * V_19 ,
struct V_6 * V_6 ,
struct V_73 * V_74 ,
void * V_177 )
{
struct V_61 * V_178 ;
if ( F_63 ( V_74 , V_179 ,
V_180 ) )
return - V_83 ;
V_178 = F_68 ( V_74 , V_181 ) ;
if ( ! V_178 )
return - V_83 ;
if ( F_65 ( V_74 , V_182 ,
V_6 -> V_143 ) )
return - V_83 ;
F_69 ( V_74 , V_178 ) ;
return 0 ;
}
static int
F_141 ( struct V_19 * V_19 ,
struct V_6 * V_6 ,
struct V_73 * V_74 ,
void * V_177 )
{
struct V_183 * V_184 = V_177 ;
struct V_61 * V_127 [ V_185 + 1 ] ;
struct V_61 * V_186 [ V_187 + 1 ] ;
T_4 V_188 ;
T_9 V_189 ;
T_9 V_190 ;
F_58 ( V_127 , V_185 , V_74 ) ;
if ( ! V_127 [ V_181 ] )
return - V_29 ;
F_57 ( V_186 , V_187 ,
V_127 [ V_181 ] ) ;
if ( ! V_186 [ V_191 ] ||
! V_186 [ V_192 ] ||
! V_186 [ V_193 ] )
return - V_29 ;
V_188 = F_53 ( V_186 [ V_191 ] ) ;
V_189 = F_50 ( V_186 [ V_192 ] ) ;
V_190 = F_50 ( V_186 [ V_193 ] ) ;
V_184 -> V_194 = V_195 ;
V_184 -> V_196 = V_197 ;
V_184 -> V_198 = 0xff ;
V_184 -> V_199 = V_200 ;
F_142 ( V_184 , V_188 ) ;
V_184 -> V_189 = V_189 ? V_201 : V_202 ;
V_184 -> V_190 = V_190 ? V_203 : V_204 ;
return 0 ;
}
static int
F_143 ( struct V_19 * V_19 ,
struct V_6 * V_6 ,
struct V_73 * V_74 ,
void * V_177 )
{
unsigned char * V_205 = V_177 ;
struct V_61 * V_127 [ V_185 + 1 ] ;
struct V_61 * V_186 [ V_187 + 1 ] ;
struct V_61 * V_206 ;
F_58 ( V_127 , V_185 , V_74 ) ;
if ( ! V_127 [ V_181 ] )
return - V_29 ;
F_57 ( V_186 , V_187 ,
V_127 [ V_181 ] ) ;
V_206 = V_186 [ V_207 ] ;
if ( ! V_206 )
return - V_29 ;
if ( F_49 ( V_206 ) != V_208 )
return - V_149 ;
F_144 ( V_205 , F_48 ( V_206 ) ) ;
return 0 ;
}
static int
F_145 ( struct V_19 * V_19 ,
struct V_6 * V_6 ,
struct V_73 * V_74 ,
void * V_177 )
{
struct V_183 * V_184 = V_177 ;
struct V_61 * V_178 ;
if ( F_63 ( V_74 , V_179 ,
V_209 ) )
return - V_83 ;
V_178 = F_68 ( V_74 , V_181 ) ;
if ( ! V_178 )
return - V_83 ;
if ( F_65 ( V_74 , V_182 ,
V_6 -> V_143 ) )
return - V_83 ;
if ( F_65 ( V_74 , V_191 ,
F_146 ( V_184 ) ) )
return - V_83 ;
if ( F_62 ( V_74 , V_192 ,
V_184 -> V_189 ) )
return - V_83 ;
if ( F_62 ( V_74 , V_193 ,
V_184 -> V_190 ) )
return - V_83 ;
F_69 ( V_74 , V_178 ) ;
return 0 ;
}
static int
F_147 ( struct V_19 * V_19 ,
struct V_6 * V_6 ,
struct V_73 * V_74 ,
void * V_177 )
{
unsigned char * V_205 = V_177 ;
struct V_61 * V_178 ;
if ( F_63 ( V_74 , V_179 ,
V_209 ) )
return - V_83 ;
V_178 = F_68 ( V_74 , V_181 ) ;
if ( ! V_178 )
return - V_83 ;
if ( F_65 ( V_74 , V_182 ,
V_6 -> V_143 ) )
return - V_83 ;
if ( F_60 ( V_74 , V_207 ,
V_208 , V_205 ) )
return - V_83 ;
F_69 ( V_74 , V_178 ) ;
return 0 ;
}
static int
F_148 ( struct V_19 * V_19 ,
struct V_6 * V_6 ,
struct V_73 * V_74 ,
void * V_177 )
{
struct V_61 * V_178 ;
if ( F_63 ( V_74 , V_179 ,
V_209 ) )
return - V_83 ;
V_178 = F_68 ( V_74 , V_181 ) ;
if ( ! V_178 )
return - V_83 ;
if ( F_65 ( V_74 , V_182 ,
V_6 -> V_143 ) )
return - V_83 ;
if ( F_62 ( V_74 , V_210 ,
! ! ( V_6 -> V_211 & V_212 ) ) )
return - V_83 ;
F_69 ( V_74 , V_178 ) ;
return 0 ;
}
static int F_149 ( struct V_6 * V_6 ,
struct V_183 * V_184 )
{
return F_137 ( V_6 -> V_19 , V_6 ,
F_140 , NULL ,
F_141 ,
V_184 , false ) ;
}
static int F_150 ( struct V_6 * V_6 ,
unsigned char * V_205 )
{
return F_137 ( V_6 -> V_19 , V_6 ,
F_140 , NULL ,
F_143 ,
V_205 , false ) ;
}
static int F_151 ( struct V_6 * V_6 ,
struct V_183 * V_184 )
{
return F_137 ( V_6 -> V_19 , V_6 ,
F_145 ,
V_184 , NULL , NULL , false ) ;
}
static int F_152 ( struct V_6 * V_6 ,
unsigned char * V_205 )
{
return F_137 ( V_6 -> V_19 , V_6 ,
F_147 ,
V_205 , NULL , NULL , false ) ;
}
static int F_153 ( struct V_6 * V_6 )
{
return F_137 ( V_6 -> V_19 , V_6 ,
F_148 ,
NULL , NULL , NULL , false ) ;
}
static int F_154 ( struct V_73 * V_74 ,
struct V_213 * V_214 )
{
if ( F_65 ( V_74 , V_215 ,
V_214 -> V_216 . V_217 . V_218 ) )
return - V_83 ;
if ( F_65 ( V_74 , V_219 ,
V_214 -> V_216 . V_217 . V_220 ) )
return - V_83 ;
if ( F_63 ( V_74 , V_221 ,
V_214 -> V_216 . V_217 . V_222 ) )
return - V_83 ;
return 0 ;
}
static int F_155 ( struct V_73 * V_74 ,
struct V_213 * V_214 )
{
if ( F_65 ( V_74 , V_215 ,
V_214 -> V_216 . V_223 . V_218 ) )
return - V_83 ;
if ( F_64 ( V_74 , V_224 ,
V_214 -> V_216 . V_223 . V_1 ) )
return - V_83 ;
if ( F_64 ( V_74 , V_225 ,
V_214 -> V_216 . V_223 . V_226 ) )
return - V_83 ;
if ( F_63 ( V_74 , V_221 ,
V_214 -> V_216 . V_223 . V_222 ) )
return - V_83 ;
if ( V_214 -> V_216 . V_223 . V_227 &&
F_64 ( V_74 , V_228 ,
V_214 -> V_216 . V_223 . V_229 ) )
return - V_83 ;
return 0 ;
}
static int F_156 ( struct V_73 * V_74 ,
struct V_213 * V_214 )
{
if ( F_65 ( V_74 , V_215 ,
V_214 -> V_216 . V_230 . V_218 ) )
return - V_83 ;
if ( F_65 ( V_74 , V_219 ,
V_214 -> V_216 . V_230 . V_220 ) )
return - V_83 ;
if ( F_64 ( V_74 , V_231 ,
V_214 -> V_216 . V_230 . V_232 ) )
return - V_83 ;
if ( F_60 ( V_74 , V_233 ,
V_208 , V_214 -> V_216 . V_230 . V_234 ) )
return - V_83 ;
if ( F_60 ( V_74 , V_235 ,
V_208 , V_214 -> V_216 . V_230 . V_236 ) )
return - V_83 ;
if ( F_64 ( V_74 , V_224 ,
V_214 -> V_216 . V_230 . V_1 ) )
return - V_83 ;
if ( F_64 ( V_74 , V_225 ,
V_214 -> V_216 . V_230 . V_226 ) )
return - V_83 ;
if ( F_63 ( V_74 , V_221 ,
V_214 -> V_216 . V_230 . V_222 ) )
return - V_83 ;
if ( V_214 -> V_216 . V_230 . V_237 &&
F_62 ( V_74 , V_238 ,
V_214 -> V_216 . V_230 . V_237 ) )
return - V_83 ;
return 0 ;
}
static int
F_157 ( struct V_73 * V_74 ,
struct V_213 * V_214 )
{
if ( F_64 ( V_74 , V_231 ,
V_214 -> V_216 . V_239 . V_232 ) )
return - V_83 ;
if ( F_66 ( V_74 , V_240 ,
V_214 -> V_216 . V_239 . V_241 ) )
return - V_83 ;
if ( F_66 ( V_74 , V_242 ,
V_214 -> V_216 . V_239 . V_243 ) )
return - V_83 ;
if ( F_63 ( V_74 , V_221 ,
V_214 -> V_216 . V_239 . V_222 ) )
return - V_83 ;
if ( F_65 ( V_74 , V_244 ,
V_214 -> V_216 . V_239 . V_245 ) )
return - V_83 ;
return 0 ;
}
static int F_158 ( struct V_73 * V_74 ,
struct V_213 * V_214 )
{
if ( V_214 -> V_216 . V_246 . V_247 &&
F_60 ( V_74 , V_233 ,
V_208 , V_214 -> V_216 . V_246 . V_234 ) )
return - V_83 ;
if ( V_214 -> V_216 . V_246 . V_248 &&
F_60 ( V_74 , V_235 ,
V_208 , V_214 -> V_216 . V_246 . V_236 ) )
return - V_83 ;
if ( V_214 -> V_216 . V_246 . V_1 &&
F_64 ( V_74 , V_224 ,
V_214 -> V_216 . V_246 . V_1 ) )
return - V_83 ;
if ( V_214 -> V_216 . V_246 . V_249 &&
F_65 ( V_74 , V_250 ,
V_214 -> V_216 . V_246 . V_249 ) )
return - V_83 ;
if ( F_63 ( V_74 , V_221 ,
V_214 -> V_216 . V_246 . V_222 ) )
return - V_83 ;
if ( F_65 ( V_74 , V_244 ,
V_214 -> V_216 . V_246 . V_245 ) )
return - V_83 ;
if ( V_214 -> V_216 . V_246 . V_237 &&
F_62 ( V_74 , V_238 ,
V_214 -> V_216 . V_246 . V_237 ) )
return - V_83 ;
return 0 ;
}
static int F_159 ( struct V_73 * V_74 ,
struct V_213 * V_214 )
{
if ( F_65 ( V_74 , V_215 ,
V_214 -> V_216 . V_251 . V_218 ) )
return - V_83 ;
if ( F_65 ( V_74 , V_219 ,
V_214 -> V_216 . V_251 . V_220 ) )
return - V_83 ;
if ( F_60 ( V_74 , V_252 ,
V_208 , V_214 -> V_216 . V_251 . V_253 ) )
return - V_83 ;
if ( F_60 ( V_74 , V_254 ,
V_208 , V_214 -> V_216 . V_251 . V_255 ) )
return - V_83 ;
if ( F_60 ( V_74 , V_233 ,
V_208 , V_214 -> V_216 . V_251 . V_234 ) )
return - V_83 ;
if ( F_60 ( V_74 , V_235 ,
V_208 , V_214 -> V_216 . V_251 . V_236 ) )
return - V_83 ;
if ( F_64 ( V_74 , V_231 ,
V_214 -> V_216 . V_251 . V_232 ) )
return - V_83 ;
if ( F_64 ( V_74 , V_224 ,
V_214 -> V_216 . V_251 . V_1 ) )
return - V_83 ;
if ( F_64 ( V_74 , V_225 ,
V_214 -> V_216 . V_251 . V_226 ) )
return - V_83 ;
switch ( F_2 ( V_214 -> V_216 . V_251 . V_232 ) ) {
case V_256 :
case V_257 :
if ( F_62 ( V_74 , V_258 ,
V_214 -> V_216 . V_251 . V_259 ) )
return - V_83 ;
if ( F_62 ( V_74 ,
V_260 ,
V_214 -> V_216 . V_251 . V_261 ) )
return - V_83 ;
if ( F_62 ( V_74 , V_262 ,
V_214 -> V_216 . V_251 . V_263 & 0x3f ) )
return - V_83 ;
if ( F_62 ( V_74 ,
V_264 ,
V_214 -> V_216 . V_251 . V_265 & 0x3f ) )
return - V_83 ;
if ( F_62 ( V_74 , V_266 ,
( V_214 -> V_216 . V_251 . V_263 & 0xc0 ) >> 6 ) )
return - V_83 ;
if ( F_62 ( V_74 ,
V_267 ,
( V_214 -> V_216 . V_251 . V_265 & 0xc0 ) >> 6 ) )
return - V_83 ;
break;
}
if ( V_214 -> V_216 . V_251 . V_245 != V_268 &&
F_65 ( V_74 , V_244 ,
V_214 -> V_216 . V_251 . V_245 ) )
return - V_83 ;
return 0 ;
}
static int F_160 ( struct V_19 * V_19 ,
struct V_6 * V_6 ,
struct V_73 * V_74 ,
void * V_177 )
{
struct V_213 * V_214 = V_177 ;
struct V_61 * V_178 ;
int V_40 = 0 ;
if ( F_63 ( V_74 , V_179 ,
V_269 ) )
return - V_83 ;
V_178 = F_68 ( V_74 , V_181 ) ;
if ( ! V_178 )
return - V_83 ;
if ( F_63 ( V_74 , V_270 ,
V_214 -> V_216 . V_271 ) )
return - V_83 ;
if ( F_65 ( V_74 , V_272 ,
V_214 -> V_216 . V_273 ) )
return - V_83 ;
if ( F_65 ( V_74 , V_274 , 0 ) )
return - V_83 ;
if ( F_67 ( V_74 , V_275 ,
V_214 -> V_90 ) )
return - V_83 ;
switch ( V_214 -> V_216 . V_271 ) {
case V_276 :
V_40 = F_154 ( V_74 , V_214 ) ;
break;
case V_277 :
V_40 = F_155 ( V_74 , V_214 ) ;
break;
case V_278 :
V_40 = F_156 ( V_74 , V_214 ) ;
break;
case V_279 :
V_40 = F_157 ( V_74 , V_214 ) ;
break;
case V_280 :
V_40 = F_158 ( V_74 , V_214 ) ;
break;
case V_281 :
V_40 = F_159 ( V_74 , V_214 ) ;
break;
default:
V_40 = - V_282 ;
break;
}
if ( V_40 )
return V_40 ;
F_69 ( V_74 , V_178 ) ;
return 0 ;
}
static int F_161 ( struct V_19 * V_19 ,
struct V_6 * V_6 ,
struct V_73 * V_74 ,
void * V_177 )
{
const struct V_213 * V_214 = V_177 ;
struct V_61 * V_178 ;
if ( F_63 ( V_74 , V_179 ,
V_283 ) )
return - V_83 ;
V_178 = F_68 ( V_74 , V_181 ) ;
if ( ! V_178 )
return - V_83 ;
if ( F_67 ( V_74 , V_275 ,
V_214 -> V_90 ) )
return - V_83 ;
F_69 ( V_74 , V_178 ) ;
return 0 ;
}
static int
F_162 ( struct V_73 * V_74 ,
struct V_284 * V_214 )
{
if ( F_65 ( V_74 , V_285 ,
F_163 ( V_214 -> V_245 ) ) )
return - V_83 ;
if ( F_62 ( V_74 , V_286 ,
V_214 -> V_287 . V_8 ) )
return - V_83 ;
return 0 ;
}
static int
F_164 ( struct V_73 * V_74 ,
struct V_284 * V_214 )
{
if ( F_65 ( V_74 , V_288 ,
V_214 -> V_289 . V_245 ) )
return - V_83 ;
if ( ! F_165 ( V_214 -> V_289 . V_253 ) &&
F_60 ( V_74 , V_252 ,
V_208 , V_214 -> V_289 . V_253 ) )
return - V_83 ;
if ( ! F_165 ( V_214 -> V_289 . V_234 ) &&
F_60 ( V_74 , V_233 ,
V_208 , V_214 -> V_289 . V_234 ) )
return - V_83 ;
if ( V_214 -> V_289 . V_1 &&
F_64 ( V_74 , V_224 ,
V_214 -> V_289 . V_1 ) )
return - V_83 ;
return 0 ;
}
static int
F_166 ( struct V_73 * V_74 ,
struct V_284 * V_214 )
{
int V_36 ;
struct V_61 * V_290 ;
if ( F_63 ( V_74 , V_291 ,
V_214 -> V_292 ) )
return - V_83 ;
V_290 = F_68 ( V_74 ,
V_293 ) ;
if ( ! V_290 )
return - V_83 ;
for ( V_36 = 0 ; V_36 < V_214 -> V_292 ; V_36 ++ )
if ( F_65 ( V_74 , V_36 + 1 , V_214 -> V_290 [ V_36 ] ) )
return - V_83 ;
F_69 ( V_74 , V_290 ) ;
return 0 ;
}
static int
F_167 ( struct V_73 * V_74 ,
struct V_284 * V_214 )
{
if ( ! F_165 ( V_214 -> V_294 . V_253 ) &&
F_60 ( V_74 , V_252 ,
V_208 , V_214 -> V_294 . V_253 ) )
return - V_83 ;
if ( ! F_165 ( V_214 -> V_294 . V_234 ) &&
F_60 ( V_74 , V_233 ,
V_208 , V_214 -> V_294 . V_234 ) )
return - V_83 ;
if ( V_214 -> V_294 . V_1 &&
F_64 ( V_74 , V_224 ,
V_214 -> V_294 . V_1 ) )
return - V_83 ;
if ( F_62 ( V_74 , V_295 ,
V_214 -> V_294 . V_296 ) )
return - V_83 ;
if ( F_65 ( V_74 , V_288 ,
V_214 -> V_294 . V_245 ) )
return - V_83 ;
return 0 ;
}
static int F_168 ( struct V_19 * V_19 ,
struct V_6 * V_6 ,
struct V_73 * V_74 ,
void * V_177 )
{
struct V_284 * V_214 = V_177 ;
struct V_61 * V_178 ;
int V_40 = 0 ;
if ( F_63 ( V_74 , V_179 , V_214 -> V_297 ) )
return - V_83 ;
V_178 = F_68 ( V_74 , V_181 ) ;
if ( ! V_178 )
return - V_83 ;
if ( F_65 ( V_74 , V_244 ,
V_214 -> V_245 ) )
return - V_83 ;
switch ( F_169 ( V_214 -> V_245 ) ) {
case V_298 :
V_40 = F_162 ( V_74 , V_214 ) ;
break;
case V_299 :
V_40 = F_164 ( V_74 , V_214 ) ;
break;
case V_300 :
case V_301 :
V_40 = F_166 ( V_74 , V_214 ) ;
break;
case V_302 :
V_40 = F_167 ( V_74 , V_214 ) ;
break;
default:
V_40 = - V_282 ;
break;
}
if ( V_40 )
return V_40 ;
F_69 ( V_74 , V_178 ) ;
return 0 ;
}
static int F_170 ( struct V_19 * V_19 ,
struct V_6 * V_6 ,
struct V_73 * V_74 ,
void * V_177 )
{
const struct V_284 * V_214 = V_177 ;
struct V_61 * V_178 ;
if ( F_63 ( V_74 , V_179 , V_214 -> V_297 ) )
return - V_83 ;
V_178 = F_68 ( V_74 , V_181 ) ;
if ( ! V_178 )
return - V_83 ;
if ( F_65 ( V_74 , V_244 ,
V_214 -> V_245 ) )
return - V_83 ;
F_69 ( V_74 , V_178 ) ;
return 0 ;
}
static int F_171 ( struct V_19 * V_19 )
{
F_172 ( V_19 -> V_303 ) ;
F_103 ( & V_19 -> V_304 ) ;
F_172 ( V_19 -> V_305 ) ;
F_103 ( & V_19 -> V_306 ) ;
F_172 ( V_19 -> V_307 ) ;
F_103 ( & V_19 -> V_308 ) ;
F_172 ( V_19 -> V_309 ) ;
F_103 ( & V_19 -> V_310 ) ;
return 0 ;
}
static void F_173 ( struct V_19 * V_19 )
{
unsigned long V_153 ;
struct V_213 * V_311 ;
struct V_284 * V_312 ;
struct V_313 * V_314 ;
struct V_315 * V_316 ;
struct V_317 * V_318 ;
int V_319 ;
F_138 ( & V_19 -> V_304 , V_153 ) ;
F_174 (rocker->flow_tbl, bkt, tmp, flow_entry, entry)
F_175 ( & V_311 -> V_214 ) ;
F_139 ( & V_19 -> V_304 , V_153 ) ;
F_138 ( & V_19 -> V_306 , V_153 ) ;
F_174 (rocker->group_tbl, bkt, tmp, group_entry, entry)
F_175 ( & V_312 -> V_214 ) ;
F_139 ( & V_19 -> V_306 , V_153 ) ;
F_138 ( & V_19 -> V_308 , V_153 ) ;
F_174 (rocker->fdb_tbl, bkt, tmp, fdb_entry, entry)
F_175 ( & V_314 -> V_214 ) ;
F_139 ( & V_19 -> V_308 , V_153 ) ;
F_138 ( & V_19 -> V_310 , V_153 ) ;
F_174 (rocker->internal_vlan_tbl, bkt,
tmp, internal_vlan_entry, entry)
F_175 ( & V_316 -> V_214 ) ;
F_139 ( & V_19 -> V_310 , V_153 ) ;
}
static struct V_213 *
F_176 ( struct V_19 * V_19 , struct V_213 * V_320 )
{
struct V_213 * V_321 ;
F_177 (rocker->flow_tbl, found,
entry, match->key_crc32) {
if ( memcmp ( & V_321 -> V_216 , & V_320 -> V_216 , sizeof( V_321 -> V_216 ) ) == 0 )
return V_321 ;
}
return NULL ;
}
static int F_178 ( struct V_6 * V_6 ,
struct V_213 * V_320 ,
bool V_14 )
{
struct V_19 * V_19 = V_6 -> V_19 ;
struct V_213 * V_321 ;
unsigned long V_153 ;
bool V_322 = false ;
int V_40 = 0 ;
V_320 -> V_323 = F_179 ( ~ 0 , & V_320 -> V_216 , sizeof( V_320 -> V_216 ) ) ;
F_138 ( & V_19 -> V_304 , V_153 ) ;
V_321 = F_176 ( V_19 , V_320 ) ;
if ( V_321 ) {
F_13 ( V_320 ) ;
} else {
V_321 = V_320 ;
V_321 -> V_90 = V_19 -> V_324 ++ ;
F_180 ( V_19 -> V_303 , & V_321 -> V_214 , V_321 -> V_323 ) ;
V_322 = true ;
}
V_321 -> V_325 ++ ;
F_139 ( & V_19 -> V_304 , V_153 ) ;
if ( V_322 ) {
V_40 = F_137 ( V_19 , V_6 ,
F_160 ,
V_321 , NULL , NULL , V_14 ) ;
if ( V_40 ) {
F_138 ( & V_19 -> V_304 , V_153 ) ;
F_175 ( & V_321 -> V_214 ) ;
F_139 ( & V_19 -> V_304 , V_153 ) ;
F_13 ( V_321 ) ;
}
}
return V_40 ;
}
static int F_181 ( struct V_6 * V_6 ,
struct V_213 * V_320 ,
bool V_14 )
{
struct V_19 * V_19 = V_6 -> V_19 ;
struct V_213 * V_321 ;
unsigned long V_153 ;
bool V_326 = false ;
int V_40 = 0 ;
V_320 -> V_323 = F_179 ( ~ 0 , & V_320 -> V_216 , sizeof( V_320 -> V_216 ) ) ;
F_138 ( & V_19 -> V_304 , V_153 ) ;
V_321 = F_176 ( V_19 , V_320 ) ;
if ( V_321 ) {
V_321 -> V_325 -- ;
if ( V_321 -> V_325 == 0 ) {
F_175 ( & V_321 -> V_214 ) ;
V_326 = true ;
}
}
F_139 ( & V_19 -> V_304 , V_153 ) ;
F_13 ( V_320 ) ;
if ( V_326 ) {
V_40 = F_137 ( V_19 , V_6 ,
F_161 ,
V_321 , NULL , NULL , V_14 ) ;
F_13 ( V_321 ) ;
}
return V_40 ;
}
static T_3 F_182 ( int V_153 )
{
return V_153 & V_154 ? V_174 : V_42 ;
}
static int F_183 ( struct V_6 * V_6 ,
int V_153 , struct V_213 * V_214 )
{
bool V_14 = V_153 & V_154 ;
if ( V_153 & V_327 )
return F_181 ( V_6 , V_214 , V_14 ) ;
else
return F_178 ( V_6 , V_214 , V_14 ) ;
}
static int F_184 ( struct V_6 * V_6 ,
int V_153 , T_4 V_218 , T_4 V_220 ,
enum V_328 V_222 )
{
struct V_213 * V_214 ;
V_214 = F_32 ( sizeof( * V_214 ) , F_182 ( V_153 ) ) ;
if ( ! V_214 )
return - V_44 ;
V_214 -> V_216 . V_273 = V_329 ;
V_214 -> V_216 . V_271 = V_276 ;
V_214 -> V_216 . V_217 . V_218 = V_218 ;
V_214 -> V_216 . V_217 . V_220 = V_220 ;
V_214 -> V_216 . V_217 . V_222 = V_222 ;
return F_183 ( V_6 , V_153 , V_214 ) ;
}
static int F_185 ( struct V_6 * V_6 ,
int V_153 , T_4 V_218 ,
T_1 V_1 , T_1 V_226 ,
enum V_328 V_222 ,
bool V_227 , T_1 V_229 )
{
struct V_213 * V_214 ;
V_214 = F_32 ( sizeof( * V_214 ) , F_182 ( V_153 ) ) ;
if ( ! V_214 )
return - V_44 ;
V_214 -> V_216 . V_273 = V_330 ;
V_214 -> V_216 . V_271 = V_277 ;
V_214 -> V_216 . V_223 . V_218 = V_218 ;
V_214 -> V_216 . V_223 . V_1 = V_1 ;
V_214 -> V_216 . V_223 . V_226 = V_226 ;
V_214 -> V_216 . V_223 . V_222 = V_222 ;
V_214 -> V_216 . V_223 . V_227 = V_227 ;
V_214 -> V_216 . V_223 . V_229 = V_229 ;
return F_183 ( V_6 , V_153 , V_214 ) ;
}
static int F_186 ( struct V_6 * V_6 ,
T_4 V_218 , T_4 V_220 ,
T_1 V_232 , const T_9 * V_234 ,
const T_9 * V_236 , T_1 V_1 ,
T_1 V_226 , bool V_237 ,
int V_153 )
{
struct V_213 * V_214 ;
V_214 = F_32 ( sizeof( * V_214 ) , F_182 ( V_153 ) ) ;
if ( ! V_214 )
return - V_44 ;
if ( F_187 ( V_234 ) ) {
V_214 -> V_216 . V_273 = V_331 ;
V_214 -> V_216 . V_230 . V_222 =
V_332 ;
} else {
V_214 -> V_216 . V_273 = V_333 ;
V_214 -> V_216 . V_230 . V_222 =
V_279 ;
}
V_214 -> V_216 . V_271 = V_278 ;
V_214 -> V_216 . V_230 . V_218 = V_218 ;
V_214 -> V_216 . V_230 . V_220 = V_220 ;
V_214 -> V_216 . V_230 . V_232 = V_232 ;
F_144 ( V_214 -> V_216 . V_230 . V_234 , V_234 ) ;
F_144 ( V_214 -> V_216 . V_230 . V_236 , V_236 ) ;
V_214 -> V_216 . V_230 . V_1 = V_1 ;
V_214 -> V_216 . V_230 . V_226 = V_226 ;
V_214 -> V_216 . V_230 . V_237 = V_237 ;
return F_183 ( V_6 , V_153 , V_214 ) ;
}
static int F_188 ( struct V_6 * V_6 ,
int V_153 ,
const T_9 * V_234 , const T_9 * V_236 ,
T_1 V_1 , T_4 V_249 ,
enum V_328 V_222 ,
T_4 V_245 , bool V_237 )
{
struct V_213 * V_214 ;
T_4 V_273 ;
bool V_334 = ! ! V_1 ;
bool V_335 = ! V_234 || ( V_234 && V_236 ) ;
bool V_336 = false ;
V_214 = F_32 ( sizeof( * V_214 ) , F_182 ( V_153 ) ) ;
if ( ! V_214 )
return - V_44 ;
V_214 -> V_216 . V_271 = V_280 ;
if ( V_234 ) {
V_214 -> V_216 . V_246 . V_247 = 1 ;
F_144 ( V_214 -> V_216 . V_246 . V_234 , V_234 ) ;
}
if ( V_236 ) {
V_214 -> V_216 . V_246 . V_248 = 1 ;
F_144 ( V_214 -> V_216 . V_246 . V_236 , V_236 ) ;
if ( memcmp ( V_236 , V_337 , V_208 ) )
V_336 = true ;
}
V_273 = V_338 ;
if ( V_334 && V_335 && V_336 )
V_273 = V_339 ;
else if ( V_334 && V_335 && ! V_336 )
V_273 = V_340 ;
else if ( V_334 && ! V_335 )
V_273 = V_341 ;
else if ( ! V_334 && V_335 && V_336 )
V_273 = V_342 ;
else if ( ! V_334 && V_335 && ! V_336 )
V_273 = V_343 ;
else if ( ! V_334 && ! V_335 )
V_273 = V_344 ;
V_214 -> V_216 . V_273 = V_273 ;
V_214 -> V_216 . V_246 . V_1 = V_1 ;
V_214 -> V_216 . V_246 . V_249 = V_249 ;
V_214 -> V_216 . V_246 . V_222 = V_222 ;
V_214 -> V_216 . V_246 . V_245 = V_245 ;
V_214 -> V_216 . V_246 . V_237 = V_237 ;
return F_183 ( V_6 , V_153 , V_214 ) ;
}
static int F_189 ( struct V_6 * V_6 ,
int V_153 , T_4 V_218 ,
T_4 V_220 ,
const T_9 * V_253 , const T_9 * V_255 ,
const T_9 * V_234 , const T_9 * V_236 ,
T_1 V_232 ,
T_1 V_1 , T_1 V_226 ,
T_9 V_259 , T_9 V_261 ,
T_9 V_263 , T_9 V_265 ,
T_4 V_245 )
{
T_4 V_273 ;
struct V_213 * V_214 ;
V_214 = F_32 ( sizeof( * V_214 ) , F_182 ( V_153 ) ) ;
if ( ! V_214 )
return - V_44 ;
V_273 = V_345 ;
if ( V_234 && V_236 ) {
if ( memcmp ( V_236 , V_346 , V_208 ) == 0 )
V_273 = V_347 ;
else if ( F_190 ( V_234 ) )
V_273 = V_348 ;
}
V_214 -> V_216 . V_273 = V_273 ;
V_214 -> V_216 . V_271 = V_281 ;
V_214 -> V_216 . V_251 . V_218 = V_218 ;
V_214 -> V_216 . V_251 . V_220 = V_220 ;
if ( V_253 )
F_144 ( V_214 -> V_216 . V_251 . V_253 , V_253 ) ;
if ( V_255 )
F_144 ( V_214 -> V_216 . V_251 . V_255 , V_255 ) ;
if ( V_234 )
F_144 ( V_214 -> V_216 . V_251 . V_234 , V_234 ) ;
if ( V_236 )
F_144 ( V_214 -> V_216 . V_251 . V_236 , V_236 ) ;
V_214 -> V_216 . V_251 . V_232 = V_232 ;
V_214 -> V_216 . V_251 . V_1 = V_1 ;
V_214 -> V_216 . V_251 . V_226 = V_226 ;
V_214 -> V_216 . V_251 . V_259 = V_259 ;
V_214 -> V_216 . V_251 . V_261 = V_261 ;
V_214 -> V_216 . V_251 . V_263 = V_263 ;
V_214 -> V_216 . V_251 . V_265 = V_265 ;
V_214 -> V_216 . V_251 . V_245 = V_245 ;
return F_183 ( V_6 , V_153 , V_214 ) ;
}
static struct V_284 *
F_191 ( struct V_19 * V_19 ,
struct V_284 * V_320 )
{
struct V_284 * V_321 ;
F_177 (rocker->group_tbl, found,
entry, match->group_id) {
if ( V_321 -> V_245 == V_320 -> V_245 )
return V_321 ;
}
return NULL ;
}
static void F_192 ( struct V_284 * V_214 )
{
switch ( F_169 ( V_214 -> V_245 ) ) {
case V_300 :
case V_301 :
F_13 ( V_214 -> V_290 ) ;
break;
default:
break;
}
F_13 ( V_214 ) ;
}
static int F_193 ( struct V_6 * V_6 ,
struct V_284 * V_320 ,
bool V_14 )
{
struct V_19 * V_19 = V_6 -> V_19 ;
struct V_284 * V_321 ;
unsigned long V_153 ;
int V_40 = 0 ;
F_138 ( & V_19 -> V_306 , V_153 ) ;
V_321 = F_191 ( V_19 , V_320 ) ;
if ( V_321 ) {
F_175 ( & V_321 -> V_214 ) ;
F_192 ( V_321 ) ;
V_321 = V_320 ;
V_321 -> V_297 = V_349 ;
} else {
V_321 = V_320 ;
V_321 -> V_297 = V_350 ;
}
F_180 ( V_19 -> V_305 , & V_321 -> V_214 , V_321 -> V_245 ) ;
F_139 ( & V_19 -> V_306 , V_153 ) ;
if ( V_321 -> V_297 )
V_40 = F_137 ( V_19 , V_6 ,
F_168 ,
V_321 , NULL , NULL , V_14 ) ;
return V_40 ;
}
static int F_194 ( struct V_6 * V_6 ,
struct V_284 * V_320 ,
bool V_14 )
{
struct V_19 * V_19 = V_6 -> V_19 ;
struct V_284 * V_321 ;
unsigned long V_153 ;
int V_40 = 0 ;
F_138 ( & V_19 -> V_306 , V_153 ) ;
V_321 = F_191 ( V_19 , V_320 ) ;
if ( V_321 ) {
F_175 ( & V_321 -> V_214 ) ;
V_321 -> V_297 = V_351 ;
}
F_139 ( & V_19 -> V_306 , V_153 ) ;
F_192 ( V_320 ) ;
if ( V_321 ) {
V_40 = F_137 ( V_19 , V_6 ,
F_170 ,
V_321 , NULL , NULL , V_14 ) ;
F_192 ( V_321 ) ;
}
return V_40 ;
}
static int F_195 ( struct V_6 * V_6 ,
int V_153 , struct V_284 * V_214 )
{
bool V_14 = V_153 & V_154 ;
if ( V_153 & V_327 )
return F_194 ( V_6 , V_214 , V_14 ) ;
else
return F_193 ( V_6 , V_214 , V_14 ) ;
}
static int F_196 ( struct V_6 * V_6 ,
int V_153 , T_1 V_1 ,
T_4 V_352 , int V_8 )
{
struct V_284 * V_214 ;
V_214 = F_32 ( sizeof( * V_214 ) , F_182 ( V_153 ) ) ;
if ( ! V_214 )
return - V_44 ;
V_214 -> V_245 = F_197 ( V_1 , V_352 ) ;
V_214 -> V_287 . V_8 = V_8 ;
return F_195 ( V_6 , V_153 , V_214 ) ;
}
static int F_198 ( struct V_6 * V_6 ,
int V_153 , T_9 V_292 ,
T_4 * V_290 , T_4 V_245 )
{
struct V_284 * V_214 ;
V_214 = F_32 ( sizeof( * V_214 ) , F_182 ( V_153 ) ) ;
if ( ! V_214 )
return - V_44 ;
V_214 -> V_245 = V_245 ;
V_214 -> V_292 = V_292 ;
V_214 -> V_290 = F_90 ( V_292 , sizeof( T_4 ) ,
F_182 ( V_153 ) ) ;
if ( ! V_214 -> V_290 ) {
F_13 ( V_214 ) ;
return - V_44 ;
}
memcpy ( V_214 -> V_290 , V_290 , V_292 * sizeof( T_4 ) ) ;
return F_195 ( V_6 , V_153 , V_214 ) ;
}
static int F_199 ( struct V_6 * V_6 ,
int V_153 , T_1 V_1 ,
T_9 V_292 , T_4 * V_290 ,
T_4 V_245 )
{
return F_198 ( V_6 , V_153 ,
V_292 , V_290 ,
V_245 ) ;
}
static int F_200 ( struct V_6 * V_6 ,
int V_153 , T_1 V_1 )
{
struct V_6 * V_353 ;
struct V_19 * V_19 = V_6 -> V_19 ;
T_4 V_245 = F_201 ( V_1 , 0 ) ;
T_4 V_290 [ V_19 -> V_148 ] ;
T_9 V_292 = 0 ;
int V_40 ;
int V_36 ;
for ( V_36 = 0 ; V_36 < V_19 -> V_148 ; V_36 ++ ) {
V_353 = V_19 -> V_150 [ V_36 ] ;
if ( ! F_6 ( V_353 ) )
continue;
if ( F_202 ( F_2 ( V_1 ) , V_353 -> V_354 ) ) {
V_290 [ V_292 ++ ] =
F_197 ( V_1 ,
V_353 -> V_143 ) ;
}
}
if ( V_292 == 0 )
return 0 ;
V_40 = F_199 ( V_6 , V_153 , V_1 ,
V_292 , V_290 ,
V_245 ) ;
if ( V_40 )
F_116 ( V_6 -> V_28 ,
L_21 , V_40 ) ;
return V_40 ;
}
static int F_203 ( struct V_6 * V_6 ,
int V_153 , T_1 V_1 ,
bool V_8 )
{
struct V_19 * V_19 = V_6 -> V_19 ;
struct V_6 * V_353 ;
bool V_355 = ! ( V_153 & V_327 ) ;
T_4 V_352 ;
int V_356 = 0 ;
int V_40 ;
int V_36 ;
if ( V_6 -> V_159 == V_160 ||
V_6 -> V_159 == V_161 ) {
V_352 = V_6 -> V_143 ;
V_40 = F_196 ( V_6 , V_153 ,
V_1 , V_352 ,
V_8 ) ;
if ( V_40 ) {
F_116 ( V_6 -> V_28 ,
L_22 ,
V_40 , V_352 ) ;
return V_40 ;
}
}
for ( V_36 = 0 ; V_36 < V_19 -> V_148 ; V_36 ++ ) {
V_353 = V_19 -> V_150 [ V_36 ] ;
if ( F_202 ( F_2 ( V_1 ) , V_353 -> V_354 ) )
V_356 ++ ;
}
if ( ( ! V_355 || V_356 != 1 ) && ( V_355 || V_356 != 0 ) )
return 0 ;
V_352 = 0 ;
V_40 = F_196 ( V_6 , V_153 ,
V_1 , V_352 ,
V_8 ) ;
if ( V_40 ) {
F_116 ( V_6 -> V_28 ,
L_23 , V_40 ) ;
return V_40 ;
}
return 0 ;
}
static int F_204 ( struct V_6 * V_6 ,
int V_153 , struct V_357 * V_358 ,
T_1 V_1 )
{
T_4 V_218 = V_6 -> V_143 ;
T_4 V_220 = 0xffffffff ;
T_4 V_352 = 0 ;
T_9 * V_253 = NULL ;
T_9 * V_255 = NULL ;
T_1 V_226 = F_4 ( 0xffff ) ;
T_9 V_259 = 0 ;
T_9 V_261 = 0 ;
T_9 V_263 = 0 ;
T_9 V_265 = 0 ;
T_4 V_245 = F_197 ( V_1 , V_352 ) ;
int V_40 ;
V_40 = F_189 ( V_6 , V_153 ,
V_218 , V_220 ,
V_253 , V_255 ,
V_358 -> V_234 , V_358 -> V_236 ,
V_358 -> V_232 ,
V_1 , V_226 ,
V_259 , V_261 ,
V_263 , V_265 ,
V_245 ) ;
if ( V_40 )
F_116 ( V_6 -> V_28 , L_24 , V_40 ) ;
return V_40 ;
}
static int F_205 ( struct V_6 * V_6 ,
int V_153 , struct V_357 * V_358 ,
T_1 V_1 )
{
enum V_328 V_222 =
V_281 ;
T_4 V_245 = F_201 ( V_1 , 0 ) ;
T_4 V_249 = 0 ;
int V_40 ;
if ( ! F_6 ( V_6 ) )
return 0 ;
V_40 = F_188 ( V_6 , V_153 ,
V_358 -> V_234 , V_358 -> V_236 ,
V_1 , V_249 ,
V_222 , V_245 , V_358 -> V_237 ) ;
if ( V_40 )
F_116 ( V_6 -> V_28 , L_25 , V_40 ) ;
return V_40 ;
}
static int F_206 ( struct V_6 * V_6 ,
int V_153 , struct V_357 * V_358 ,
T_1 V_1 )
{
T_4 V_220 = 0xffffffff ;
T_1 V_226 = F_4 ( 0xffff ) ;
int V_40 ;
if ( F_2 ( V_1 ) == 0 )
V_1 = V_6 -> V_9 ;
V_40 = F_186 ( V_6 ,
V_6 -> V_143 , V_220 ,
V_358 -> V_232 , V_358 -> V_234 ,
V_358 -> V_236 , V_1 ,
V_226 , V_358 -> V_237 ,
V_153 ) ;
if ( V_40 )
F_116 ( V_6 -> V_28 , L_26 , V_40 ) ;
return V_40 ;
}
static int F_207 ( struct V_6 * V_6 , int V_153 ,
struct V_357 * V_358 , T_1 V_1 )
{
if ( V_358 -> V_251 )
return F_204 ( V_6 , V_153 ,
V_358 , V_1 ) ;
if ( V_358 -> V_246 )
return F_205 ( V_6 , V_153 ,
V_358 , V_1 ) ;
if ( V_358 -> V_359 )
return F_206 ( V_6 , V_153 ,
V_358 , V_1 ) ;
return - V_167 ;
}
static int F_208 ( struct V_6 * V_6 ,
int V_153 , T_1 V_1 )
{
int V_40 = 0 ;
int V_36 ;
for ( V_36 = 0 ; V_36 < V_360 ; V_36 ++ ) {
if ( V_6 -> V_361 [ V_36 ] ) {
V_40 = F_207 ( V_6 , V_153 ,
& V_362 [ V_36 ] , V_1 ) ;
if ( V_40 )
return V_40 ;
}
}
return V_40 ;
}
static int F_209 ( struct V_6 * V_6 , int V_153 ,
struct V_357 * V_358 )
{
T_2 V_7 ;
int V_40 = 0 ;
for ( V_7 = 1 ; V_7 < V_363 ; V_7 ++ ) {
if ( ! F_202 ( V_7 , V_6 -> V_354 ) )
continue;
V_40 = F_207 ( V_6 , V_153 ,
V_358 , F_4 ( V_7 ) ) ;
if ( V_40 )
break;
}
return V_40 ;
}
static int F_210 ( struct V_6 * V_6 , int V_153 ,
T_2 V_7 )
{
enum V_328 V_222 =
V_278 ;
T_4 V_218 = V_6 -> V_143 ;
T_1 V_1 = F_4 ( V_7 ) ;
T_1 V_226 = F_4 ( 0xffff ) ;
T_1 V_9 ;
bool V_227 ;
bool V_355 = ! ( V_153 & V_327 ) ;
int V_40 ;
V_9 = F_3 ( V_6 , V_7 , & V_227 ) ;
if ( V_355 && F_211 ( F_2 ( V_9 ) ,
V_6 -> V_354 ) )
return 0 ;
else if ( ! V_355 && ! F_212 ( F_2 ( V_9 ) ,
V_6 -> V_354 ) )
return 0 ;
if ( V_355 ) {
V_40 = F_208 ( V_6 , V_153 ,
V_9 ) ;
if ( V_40 ) {
F_116 ( V_6 -> V_28 ,
L_27 , V_40 ) ;
return V_40 ;
}
}
V_40 = F_203 ( V_6 , V_153 ,
V_9 , V_227 ) ;
if ( V_40 ) {
F_116 ( V_6 -> V_28 ,
L_28 , V_40 ) ;
return V_40 ;
}
V_40 = F_200 ( V_6 , V_153 ,
V_9 ) ;
if ( V_40 ) {
F_116 ( V_6 -> V_28 ,
L_21 , V_40 ) ;
return V_40 ;
}
V_40 = F_185 ( V_6 , V_153 ,
V_218 , V_1 , V_226 ,
V_222 , V_227 , V_9 ) ;
if ( V_40 )
F_116 ( V_6 -> V_28 ,
L_29 , V_40 ) ;
return V_40 ;
}
static int F_213 ( struct V_6 * V_6 , int V_153 )
{
enum V_328 V_222 ;
T_4 V_218 ;
T_4 V_220 ;
int V_40 ;
V_218 = 0 ;
V_220 = 0xffff0000 ;
V_222 = V_277 ;
V_40 = F_184 ( V_6 , V_153 ,
V_218 , V_220 ,
V_222 ) ;
if ( V_40 )
F_116 ( V_6 -> V_28 ,
L_30 , V_40 ) ;
return V_40 ;
}
static void F_214 ( struct V_364 * V_16 )
{
struct V_365 * V_366 =
F_215 ( V_16 , struct V_365 , V_16 ) ;
bool V_367 = ( V_366 -> V_153 & V_327 ) ;
bool V_368 = ( V_366 -> V_153 & V_155 ) ;
struct V_369 V_93 ;
V_93 . V_152 = V_366 -> V_152 ;
V_93 . V_7 = V_366 -> V_7 ;
if ( V_368 && V_367 )
F_216 ( V_370 ,
V_366 -> V_28 , & V_93 . V_93 ) ;
else if ( V_368 && ! V_367 )
F_216 ( V_371 ,
V_366 -> V_28 , & V_93 . V_93 ) ;
F_13 ( V_16 ) ;
}
static int F_217 ( struct V_6 * V_6 ,
int V_153 , const T_9 * V_152 , T_1 V_1 )
{
struct V_365 * V_366 ;
enum V_328 V_222 =
V_281 ;
T_4 V_352 = V_6 -> V_143 ;
T_4 V_249 = 0 ;
T_4 V_245 = V_268 ;
bool V_372 = ! ! ( V_6 -> V_211 & V_373 ) ;
bool V_237 = false ;
int V_40 ;
if ( F_6 ( V_6 ) )
V_245 = F_197 ( V_1 , V_352 ) ;
if ( ! ( V_153 & V_374 ) ) {
V_40 = F_188 ( V_6 , V_153 , V_152 , NULL ,
V_1 , V_249 , V_222 ,
V_245 , V_237 ) ;
if ( V_40 )
return V_40 ;
}
if ( ! V_372 )
return 0 ;
if ( ! F_6 ( V_6 ) )
return 0 ;
V_366 = F_11 ( sizeof( * V_366 ) , F_182 ( V_153 ) ) ;
if ( ! V_366 )
return - V_44 ;
F_218 ( & V_366 -> V_16 , F_214 ) ;
V_366 -> V_28 = V_6 -> V_28 ;
V_366 -> V_153 = V_153 ;
F_144 ( V_366 -> V_152 , V_152 ) ;
V_366 -> V_7 = F_5 ( V_6 , V_1 ) ;
F_219 ( & V_366 -> V_16 ) ;
return 0 ;
}
static struct V_313 *
F_220 ( struct V_19 * V_19 , struct V_313 * V_320 )
{
struct V_313 * V_321 ;
F_177 (rocker->fdb_tbl, found, entry, match->key_crc32)
if ( memcmp ( & V_321 -> V_216 , & V_320 -> V_216 , sizeof( V_321 -> V_216 ) ) == 0 )
return V_321 ;
return NULL ;
}
static int F_131 ( struct V_6 * V_6 ,
const unsigned char * V_152 ,
T_1 V_1 , int V_153 )
{
struct V_19 * V_19 = V_6 -> V_19 ;
struct V_313 * V_375 ;
struct V_313 * V_321 ;
bool V_367 = ( V_153 & V_327 ) ;
unsigned long V_376 ;
V_375 = F_32 ( sizeof( * V_375 ) , F_182 ( V_153 ) ) ;
if ( ! V_375 )
return - V_44 ;
V_375 -> V_368 = ( V_153 & V_155 ) ;
V_375 -> V_216 . V_143 = V_6 -> V_143 ;
F_144 ( V_375 -> V_216 . V_152 , V_152 ) ;
V_375 -> V_216 . V_1 = V_1 ;
V_375 -> V_323 = F_179 ( ~ 0 , & V_375 -> V_216 , sizeof( V_375 -> V_216 ) ) ;
F_138 ( & V_19 -> V_308 , V_376 ) ;
V_321 = F_220 ( V_19 , V_375 ) ;
if ( V_367 && V_321 ) {
F_13 ( V_375 ) ;
F_175 ( & V_321 -> V_214 ) ;
} else if ( ! V_367 && ! V_321 ) {
F_180 ( V_19 -> V_307 , & V_375 -> V_214 , V_375 -> V_323 ) ;
}
F_139 ( & V_19 -> V_308 , V_376 ) ;
if ( ! V_321 != ! V_367 ) {
F_13 ( V_375 ) ;
if ( ! V_321 && V_367 )
return 0 ;
V_153 |= V_374 ;
}
return F_217 ( V_6 , V_153 , V_152 , V_1 ) ;
}
static int F_221 ( struct V_6 * V_6 )
{
struct V_19 * V_19 = V_6 -> V_19 ;
struct V_313 * V_321 ;
unsigned long V_376 ;
int V_153 = V_154 | V_327 ;
struct V_317 * V_318 ;
int V_319 ;
int V_40 = 0 ;
if ( V_6 -> V_159 == V_160 ||
V_6 -> V_159 == V_161 )
return 0 ;
F_138 ( & V_19 -> V_308 , V_376 ) ;
F_174 (rocker->fdb_tbl, bkt, tmp, found, entry) {
if ( V_321 -> V_216 . V_143 != V_6 -> V_143 )
continue;
if ( ! V_321 -> V_368 )
continue;
V_40 = F_217 ( V_6 , V_153 ,
V_321 -> V_216 . V_152 ,
V_321 -> V_216 . V_1 ) ;
if ( V_40 )
goto V_377;
F_175 ( & V_321 -> V_214 ) ;
}
V_377:
F_139 ( & V_19 -> V_308 , V_376 ) ;
return V_40 ;
}
static int F_222 ( struct V_6 * V_6 ,
int V_153 , T_1 V_1 )
{
T_4 V_220 = 0xffffffff ;
T_1 V_232 ;
const T_9 * V_378 = V_337 ;
T_1 V_226 = F_4 ( 0xffff ) ;
bool V_237 = false ;
int V_40 ;
if ( F_2 ( V_1 ) == 0 )
V_1 = V_6 -> V_9 ;
V_232 = F_4 ( V_256 ) ;
V_40 = F_186 ( V_6 ,
V_6 -> V_143 , V_220 ,
V_232 , V_6 -> V_28 -> V_379 ,
V_378 , V_1 , V_226 ,
V_237 , V_153 ) ;
if ( V_40 )
return V_40 ;
V_232 = F_4 ( V_257 ) ;
V_40 = F_186 ( V_6 ,
V_6 -> V_143 , V_220 ,
V_232 , V_6 -> V_28 -> V_379 ,
V_378 , V_1 , V_226 ,
V_237 , V_153 ) ;
return V_40 ;
}
static int F_223 ( struct V_6 * V_6 )
{
bool V_8 ;
T_4 V_352 ;
T_1 V_1 ;
T_2 V_7 ;
int V_153 = V_154 ;
int V_40 ;
if ( V_6 -> V_159 != V_160 &&
V_6 -> V_159 != V_161 )
V_153 |= V_327 ;
V_352 = V_6 -> V_143 ;
for ( V_7 = 1 ; V_7 < V_363 ; V_7 ++ ) {
if ( ! F_202 ( V_7 , V_6 -> V_354 ) )
continue;
V_1 = F_4 ( V_7 ) ;
V_8 = F_1 ( V_1 ) ;
V_40 = F_196 ( V_6 , V_153 ,
V_1 , V_352 ,
V_8 ) ;
if ( V_40 ) {
F_116 ( V_6 -> V_28 ,
L_22 ,
V_40 , V_352 ) ;
return V_40 ;
}
}
return 0 ;
}
static int F_224 ( struct V_6 * V_6 , T_9 V_380 )
{
bool V_381 [ V_360 ] = { 0 , } ;
int V_153 ;
int V_40 ;
int V_36 ;
if ( V_6 -> V_159 == V_380 )
return 0 ;
V_6 -> V_159 = V_380 ;
switch ( V_380 ) {
case V_382 :
break;
case V_383 :
case V_384 :
V_381 [ V_385 ] = true ;
break;
case V_160 :
case V_161 :
V_381 [ V_385 ] = true ;
V_381 [ V_386 ] = true ;
V_381 [ V_387 ] = true ;
if ( F_6 ( V_6 ) )
V_381 [ V_388 ] = true ;
else
V_381 [ V_389 ] = true ;
break;
}
for ( V_36 = 0 ; V_36 < V_360 ; V_36 ++ ) {
if ( V_381 [ V_36 ] != V_6 -> V_361 [ V_36 ] ) {
V_153 = V_154 |
( V_381 [ V_36 ] ? 0 : V_327 ) ;
V_40 = F_209 ( V_6 , V_153 ,
& V_362 [ V_36 ] ) ;
if ( V_40 )
return V_40 ;
V_6 -> V_361 [ V_36 ] = V_381 [ V_36 ] ;
}
}
V_40 = F_221 ( V_6 ) ;
if ( V_40 )
return V_40 ;
return F_223 ( V_6 ) ;
}
static struct V_315 *
F_225 ( struct V_19 * V_19 , int V_390 )
{
struct V_315 * V_321 ;
F_177 (rocker->internal_vlan_tbl, found,
entry, ifindex) {
if ( V_321 -> V_390 == V_390 )
return V_321 ;
}
return NULL ;
}
static T_1 F_226 ( struct V_6 * V_6 ,
int V_390 )
{
struct V_19 * V_19 = V_6 -> V_19 ;
struct V_315 * V_214 ;
struct V_315 * V_321 ;
unsigned long V_376 ;
int V_36 ;
V_214 = F_32 ( sizeof( * V_214 ) , V_42 ) ;
if ( ! V_214 )
return 0 ;
V_214 -> V_390 = V_390 ;
F_138 ( & V_19 -> V_310 , V_376 ) ;
V_321 = F_225 ( V_19 , V_390 ) ;
if ( V_321 ) {
F_13 ( V_214 ) ;
goto V_321;
}
V_321 = V_214 ;
F_180 ( V_19 -> V_309 , & V_321 -> V_214 , V_321 -> V_390 ) ;
for ( V_36 = 0 ; V_36 < V_391 ; V_36 ++ ) {
if ( F_211 ( V_36 , V_19 -> V_392 ) )
continue;
V_321 -> V_1 = F_4 ( V_3 + V_36 ) ;
goto V_321;
}
F_116 ( V_6 -> V_28 , L_31 ) ;
V_321:
V_321 -> V_325 ++ ;
F_139 ( & V_19 -> V_310 , V_376 ) ;
return V_321 -> V_1 ;
}
static void F_227 ( struct V_6 * V_6 ,
int V_390 )
{
struct V_19 * V_19 = V_6 -> V_19 ;
struct V_315 * V_321 ;
unsigned long V_376 ;
unsigned long V_393 ;
F_138 ( & V_19 -> V_310 , V_376 ) ;
V_321 = F_225 ( V_19 , V_390 ) ;
if ( ! V_321 ) {
F_116 ( V_6 -> V_28 ,
L_32 ,
V_390 ) ;
goto V_394;
}
if ( -- V_321 -> V_325 <= 0 ) {
V_393 = F_2 ( V_321 -> V_1 ) - V_3 ;
F_228 ( V_393 , V_19 -> V_392 ) ;
F_175 ( & V_321 -> V_214 ) ;
F_13 ( V_321 ) ;
}
V_394:
F_139 ( & V_19 -> V_310 , V_376 ) ;
}
static int F_229 ( struct V_126 * V_28 )
{
struct V_6 * V_6 = F_230 ( V_28 ) ;
T_9 V_159 = F_6 ( V_6 ) ?
V_384 : V_161 ;
int V_40 ;
V_40 = F_114 ( V_6 ) ;
if ( V_40 )
return V_40 ;
V_40 = F_40 ( F_19 ( V_6 ) ,
F_134 , 0 ,
V_58 , V_6 ) ;
if ( V_40 ) {
F_116 ( V_6 -> V_28 , L_33 ) ;
goto V_395;
}
V_40 = F_40 ( F_21 ( V_6 ) ,
F_136 , 0 ,
V_58 , V_6 ) ;
if ( V_40 ) {
F_116 ( V_6 -> V_28 , L_34 ) ;
goto V_396;
}
V_40 = F_224 ( V_6 , V_159 ) ;
if ( V_40 )
goto V_397;
F_231 ( & V_6 -> V_168 ) ;
F_231 ( & V_6 -> V_169 ) ;
F_119 ( V_6 , true ) ;
F_232 ( V_28 ) ;
return 0 ;
V_397:
V_60 ( F_21 ( V_6 ) , V_6 ) ;
V_396:
V_60 ( F_19 ( V_6 ) , V_6 ) ;
V_395:
F_118 ( V_6 ) ;
return V_40 ;
}
static int F_233 ( struct V_126 * V_28 )
{
struct V_6 * V_6 = F_230 ( V_28 ) ;
F_234 ( V_28 ) ;
F_119 ( V_6 , false ) ;
F_235 ( & V_6 -> V_169 ) ;
F_235 ( & V_6 -> V_168 ) ;
F_224 ( V_6 , V_382 ) ;
V_60 ( F_21 ( V_6 ) , V_6 ) ;
V_60 ( F_19 ( V_6 ) , V_6 ) ;
F_118 ( V_6 ) ;
return 0 ;
}
static void F_236 ( struct V_6 * V_6 ,
struct V_73 * V_74 )
{
struct V_19 * V_19 = V_6 -> V_19 ;
struct V_23 * V_24 = V_19 -> V_24 ;
struct V_61 * V_127 [ V_398 + 1 ] ;
struct V_61 * V_206 ;
int V_72 ;
F_58 ( V_127 , V_398 , V_74 ) ;
if ( ! V_127 [ V_399 ] )
return;
F_237 (attr, attrs[ROCKER_TLV_TX_FRAGS], rem) {
struct V_61 * V_400 [ V_401 + 1 ] ;
T_6 V_32 ;
T_7 V_65 ;
if ( F_47 ( V_206 ) != V_402 )
continue;
F_57 ( V_400 , V_401 ,
V_206 ) ;
if ( ! V_400 [ V_403 ] ||
! V_400 [ V_404 ] )
continue;
V_32 = F_54 ( V_400 [ V_403 ] ) ;
V_65 = F_51 ( V_400 [ V_404 ] ) ;
F_36 ( V_24 , V_32 , V_65 , V_405 ) ;
}
}
static int F_238 ( struct V_6 * V_6 ,
struct V_73 * V_74 ,
char * V_33 , T_7 V_70 )
{
struct V_19 * V_19 = V_6 -> V_19 ;
struct V_23 * V_24 = V_19 -> V_24 ;
T_6 V_32 ;
struct V_61 * V_406 ;
V_32 = F_33 ( V_24 , V_33 , V_70 , V_405 ) ;
if ( F_61 ( F_34 ( V_24 , V_32 ) ) ) {
if ( F_239 () )
F_116 ( V_6 -> V_28 , L_35 ) ;
return - V_29 ;
}
V_406 = F_68 ( V_74 , V_402 ) ;
if ( ! V_406 )
goto V_407;
if ( F_67 ( V_74 , V_403 ,
V_32 ) )
goto V_408;
if ( F_63 ( V_74 , V_404 ,
V_70 ) )
goto V_408;
F_69 ( V_74 , V_406 ) ;
return 0 ;
V_408:
F_70 ( V_74 , V_406 ) ;
V_407:
F_36 ( V_24 , V_32 , V_70 , V_405 ) ;
return - V_83 ;
}
static T_12 F_240 ( struct V_117 * V_118 , struct V_126 * V_28 )
{
struct V_6 * V_6 = F_230 ( V_28 ) ;
struct V_19 * V_19 = V_6 -> V_19 ;
struct V_73 * V_74 ;
struct V_61 * V_409 ;
int V_36 ;
int V_40 ;
V_74 = F_77 ( & V_6 -> V_131 ) ;
if ( F_61 ( ! V_74 ) ) {
if ( F_239 () )
F_116 ( V_28 , L_36 ) ;
return V_410 ;
}
F_76 ( V_74 , V_118 ) ;
V_409 = F_68 ( V_74 , V_399 ) ;
if ( ! V_409 )
goto V_176;
V_40 = F_238 ( V_6 , V_74 ,
V_118 -> V_75 , F_241 ( V_118 ) ) ;
if ( V_40 )
goto V_408;
if ( F_242 ( V_118 ) -> V_411 > V_412 )
goto V_408;
for ( V_36 = 0 ; V_36 < F_242 ( V_118 ) -> V_411 ; V_36 ++ ) {
const T_13 * V_406 = & F_242 ( V_118 ) -> V_409 [ V_36 ] ;
V_40 = F_238 ( V_6 , V_74 ,
F_243 ( V_406 ) ,
F_244 ( V_406 ) ) ;
if ( V_40 )
goto V_413;
}
F_69 ( V_74 , V_409 ) ;
F_73 ( V_74 ) ;
F_79 ( V_19 , & V_6 -> V_131 , V_74 ) ;
V_74 = F_77 ( & V_6 -> V_131 ) ;
if ( ! V_74 )
F_234 ( V_28 ) ;
return V_414 ;
V_413:
F_236 ( V_6 , V_74 ) ;
V_408:
F_70 ( V_74 , V_409 ) ;
V_176:
F_245 ( V_118 ) ;
V_28 -> V_415 . V_416 ++ ;
return V_414 ;
}
static int F_246 ( struct V_126 * V_28 , void * V_353 )
{
struct V_417 * V_152 = V_353 ;
struct V_6 * V_6 = F_230 ( V_28 ) ;
int V_40 ;
if ( ! F_247 ( V_152 -> V_418 ) )
return - V_419 ;
V_40 = F_152 ( V_6 , V_152 -> V_418 ) ;
if ( V_40 )
return V_40 ;
memcpy ( V_28 -> V_379 , V_152 -> V_418 , V_28 -> V_420 ) ;
return 0 ;
}
static int F_248 ( struct V_126 * V_28 ,
T_1 V_421 , T_2 V_7 )
{
struct V_6 * V_6 = F_230 ( V_28 ) ;
int V_40 ;
V_40 = F_210 ( V_6 , 0 , V_7 ) ;
if ( V_40 )
return V_40 ;
return F_222 ( V_6 , 0 , F_4 ( V_7 ) ) ;
}
static int F_249 ( struct V_126 * V_28 ,
T_1 V_421 , T_2 V_7 )
{
struct V_6 * V_6 = F_230 ( V_28 ) ;
int V_40 ;
V_40 = F_222 ( V_6 , V_327 ,
F_4 ( V_7 ) ) ;
if ( V_40 )
return V_40 ;
return F_210 ( V_6 , V_327 , V_7 ) ;
}
static int F_250 ( struct V_422 * V_423 , struct V_424 * V_68 [] ,
struct V_126 * V_28 ,
const unsigned char * V_152 , T_2 V_7 ,
T_2 V_425 )
{
struct V_6 * V_6 = F_230 ( V_28 ) ;
T_1 V_1 = F_3 ( V_6 , V_7 , NULL ) ;
int V_153 = 0 ;
if ( ! F_6 ( V_6 ) )
return - V_149 ;
return F_131 ( V_6 , V_152 , V_1 , V_153 ) ;
}
static int F_251 ( struct V_422 * V_423 , struct V_424 * V_68 [] ,
struct V_126 * V_28 ,
const unsigned char * V_152 , T_2 V_7 )
{
struct V_6 * V_6 = F_230 ( V_28 ) ;
T_1 V_1 = F_3 ( V_6 , V_7 , NULL ) ;
int V_153 = V_327 ;
if ( ! F_6 ( V_6 ) )
return - V_149 ;
return F_131 ( V_6 , V_152 , V_1 , V_153 ) ;
}
static int F_252 ( struct V_117 * V_118 ,
struct V_6 * V_6 ,
const unsigned char * V_152 , T_2 V_7 ,
T_4 V_426 , T_4 V_427 , int type ,
unsigned int V_153 )
{
struct V_428 * V_429 ;
struct V_422 * V_423 ;
V_429 = F_253 ( V_118 , V_426 , V_427 , type , sizeof( * V_423 ) , V_153 ) ;
if ( ! V_429 )
return - V_83 ;
V_423 = F_254 ( V_429 ) ;
V_423 -> V_430 = V_431 ;
V_423 -> V_432 = 0 ;
V_423 -> V_433 = 0 ;
V_423 -> V_434 = V_435 ;
V_423 -> V_436 = 0 ;
V_423 -> V_437 = V_6 -> V_28 -> V_390 ;
V_423 -> V_438 = V_439 ;
if ( F_255 ( V_118 , V_440 , V_208 , V_152 ) )
goto V_441;
if ( V_7 && F_256 ( V_118 , V_442 , V_7 ) )
goto V_441;
F_257 ( V_118 , V_429 ) ;
return 0 ;
V_441:
F_258 ( V_118 , V_429 ) ;
return - V_83 ;
}
static int F_259 ( struct V_117 * V_118 ,
struct V_443 * V_444 ,
struct V_126 * V_28 ,
struct V_126 * V_445 ,
int V_446 )
{
struct V_6 * V_6 = F_230 ( V_28 ) ;
struct V_19 * V_19 = V_6 -> V_19 ;
struct V_313 * V_321 ;
struct V_317 * V_318 ;
int V_319 ;
unsigned long V_376 ;
const unsigned char * V_152 ;
T_2 V_7 ;
int V_40 ;
F_138 ( & V_19 -> V_308 , V_376 ) ;
F_174 (rocker->fdb_tbl, bkt, tmp, found, entry) {
if ( V_321 -> V_216 . V_143 != V_6 -> V_143 )
continue;
if ( V_446 < V_444 -> args [ 0 ] )
goto V_447;
V_152 = V_321 -> V_216 . V_152 ;
V_7 = F_5 ( V_6 , V_321 -> V_216 . V_1 ) ;
V_40 = F_252 ( V_118 , V_6 , V_152 , V_7 ,
F_260 ( V_444 -> V_118 ) . V_426 ,
V_444 -> V_429 -> V_448 ,
V_449 , V_450 ) ;
if ( V_40 < 0 )
break;
V_447:
++ V_446 ;
}
F_139 ( & V_19 -> V_308 , V_376 ) ;
return V_446 ;
}
static int F_261 ( struct V_126 * V_28 ,
struct V_428 * V_429 , T_2 V_153 )
{
struct V_6 * V_6 = F_230 ( V_28 ) ;
struct V_424 * V_451 ;
struct V_424 * V_206 ;
int V_40 ;
V_451 = F_262 ( V_429 , sizeof( struct V_452 ) ,
V_453 ) ;
if ( V_451 ) {
V_206 = F_263 ( V_451 , V_454 ) ;
if ( V_206 ) {
if ( F_264 ( V_206 ) < sizeof( T_9 ) )
return - V_149 ;
if ( F_265 ( V_206 ) )
V_6 -> V_211 |= V_212 ;
else
V_6 -> V_211 &= ~ V_212 ;
V_40 = F_153 ( V_6 ) ;
if ( V_40 )
return V_40 ;
}
V_206 = F_263 ( V_451 , V_455 ) ;
if ( V_206 ) {
if ( F_264 ( V_206 ) < sizeof( T_9 ) )
return - V_149 ;
if ( F_265 ( V_206 ) )
V_6 -> V_211 |= V_373 ;
else
V_6 -> V_211 &= ~ V_373 ;
}
}
return 0 ;
}
static int F_266 ( struct V_117 * V_118 , T_4 V_456 , T_4 V_427 ,
struct V_126 * V_28 ,
T_4 V_457 )
{
struct V_6 * V_6 = F_230 ( V_28 ) ;
T_2 V_458 = V_459 ;
T_4 V_460 = V_212 | V_373 ;
return F_267 ( V_118 , V_456 , V_427 , V_28 , V_458 ,
V_6 -> V_211 , V_460 ) ;
}
static int F_268 ( struct V_126 * V_28 ,
struct V_461 * V_462 )
{
struct V_6 * V_6 = F_230 ( V_28 ) ;
struct V_19 * V_19 = V_6 -> V_19 ;
V_462 -> V_463 = sizeof( V_19 -> V_464 . V_465 ) ;
memcpy ( & V_462 -> V_465 , & V_19 -> V_464 . V_465 , V_462 -> V_463 ) ;
return 0 ;
}
static int F_269 ( struct V_126 * V_28 , T_9 V_380 )
{
struct V_6 * V_6 = F_230 ( V_28 ) ;
return F_224 ( V_6 , V_380 ) ;
}
static int F_270 ( struct V_126 * V_28 ,
struct V_183 * V_184 )
{
struct V_6 * V_6 = F_230 ( V_28 ) ;
return F_149 ( V_6 , V_184 ) ;
}
static int F_271 ( struct V_126 * V_28 ,
struct V_183 * V_184 )
{
struct V_6 * V_6 = F_230 ( V_28 ) ;
return F_151 ( V_6 , V_184 ) ;
}
static void F_272 ( struct V_126 * V_28 ,
struct V_466 * V_467 )
{
F_273 ( V_467 -> V_468 , V_58 , sizeof( V_467 -> V_468 ) ) ;
F_273 ( V_467 -> V_469 , V_470 , sizeof( V_467 -> V_469 ) ) ;
}
static void F_274 ( struct V_126 * V_471 , T_4 V_472 ,
T_9 * V_75 )
{
T_9 * V_353 = V_75 ;
int V_36 ;
switch ( V_472 ) {
case V_473 :
for ( V_36 = 0 ; V_36 < F_275 ( V_474 ) ; V_36 ++ ) {
memcpy ( V_353 , V_474 [ V_36 ] . V_475 , V_476 ) ;
V_353 += V_476 ;
}
break;
}
}
static int
F_276 ( struct V_19 * V_19 ,
struct V_6 * V_6 ,
struct V_73 * V_74 ,
void * V_177 )
{
struct V_61 * V_477 ;
if ( F_63 ( V_74 , V_179 ,
V_478 ) )
return - V_83 ;
V_477 = F_68 ( V_74 , V_181 ) ;
if ( ! V_477 )
return - V_83 ;
if ( F_65 ( V_74 , V_479 ,
V_6 -> V_143 ) )
return - V_83 ;
F_69 ( V_74 , V_477 ) ;
return 0 ;
}
static int
F_277 ( struct V_19 * V_19 ,
struct V_6 * V_6 ,
struct V_73 * V_74 ,
void * V_177 )
{
struct V_61 * V_127 [ V_185 + 1 ] ;
struct V_61 * V_480 [ V_481 + 1 ] ;
struct V_61 * V_482 ;
T_4 V_143 ;
T_5 * V_75 = V_177 ;
int V_36 ;
F_58 ( V_127 , V_185 , V_74 ) ;
if ( ! V_127 [ V_181 ] )
return - V_29 ;
F_57 ( V_480 , V_481 ,
V_127 [ V_181 ] ) ;
if ( ! V_480 [ V_479 ] )
return - V_29 ;
V_143 = F_53 ( V_480 [ V_479 ] ) ;
if ( V_143 != V_6 -> V_143 )
return - V_29 ;
for ( V_36 = 0 ; V_36 < F_275 ( V_474 ) ; V_36 ++ ) {
V_482 = V_480 [ V_474 [ V_36 ] . type ] ;
if ( ! V_482 )
continue;
V_75 [ V_36 ] = F_54 ( V_482 ) ;
}
return 0 ;
}
static int F_278 ( struct V_6 * V_6 ,
void * V_177 )
{
return F_137 ( V_6 -> V_19 , V_6 ,
F_276 , NULL ,
F_277 ,
V_177 , false ) ;
}
static void F_279 ( struct V_126 * V_28 ,
struct V_483 * V_415 , T_5 * V_75 )
{
struct V_6 * V_6 = F_230 ( V_28 ) ;
if ( F_278 ( V_6 , V_75 ) != 0 ) {
int V_36 ;
for ( V_36 = 0 ; V_36 < F_275 ( V_474 ) ; ++ V_36 )
V_75 [ V_36 ] = 0 ;
}
return;
}
static int F_280 ( struct V_126 * V_471 , int V_484 )
{
switch ( V_484 ) {
case V_473 :
return V_485 ;
default:
return - V_167 ;
}
}
static struct V_6 * F_281 ( struct V_486 * V_487 )
{
return F_215 ( V_487 , struct V_6 , V_168 ) ;
}
static int F_282 ( struct V_486 * V_487 , int V_488 )
{
struct V_6 * V_6 = F_281 ( V_487 ) ;
struct V_19 * V_19 = V_6 -> V_19 ;
struct V_73 * V_74 ;
T_4 V_96 = 0 ;
int V_40 ;
while ( ( V_74 = F_82 ( & V_6 -> V_131 ) ) ) {
struct V_117 * V_118 ;
V_40 = F_72 ( V_74 ) ;
if ( V_40 && F_239 () )
F_116 ( V_6 -> V_28 , L_37 ,
V_40 ) ;
F_236 ( V_6 , V_74 ) ;
V_118 = F_75 ( V_74 ) ;
if ( V_40 == 0 ) {
V_6 -> V_28 -> V_415 . V_489 ++ ;
V_6 -> V_28 -> V_415 . V_490 += V_118 -> V_65 ;
} else
V_6 -> V_28 -> V_415 . V_491 ++ ;
F_109 ( V_118 ) ;
V_96 ++ ;
}
if ( V_96 && F_283 ( V_6 -> V_28 ) )
F_284 ( V_6 -> V_28 ) ;
F_285 ( V_487 ) ;
F_83 ( V_19 , & V_6 -> V_131 , V_96 ) ;
return 0 ;
}
static int F_286 ( struct V_19 * V_19 ,
struct V_6 * V_6 ,
struct V_73 * V_74 )
{
struct V_61 * V_127 [ V_128 + 1 ] ;
struct V_117 * V_118 = F_75 ( V_74 ) ;
T_7 V_492 ;
if ( ! V_118 )
return - V_493 ;
F_58 ( V_127 , V_128 , V_74 ) ;
if ( ! V_127 [ V_494 ] )
return - V_149 ;
F_110 ( V_19 , V_127 ) ;
V_492 = F_51 ( V_127 [ V_494 ] ) ;
F_287 ( V_118 , V_492 ) ;
V_118 -> V_495 = F_288 ( V_118 , V_6 -> V_28 ) ;
V_6 -> V_28 -> V_415 . V_496 ++ ;
V_6 -> V_28 -> V_415 . V_497 += V_118 -> V_65 ;
F_289 ( V_118 ) ;
return F_107 ( V_19 , V_6 , V_74 ) ;
}
static struct V_6 * F_290 ( struct V_486 * V_487 )
{
return F_215 ( V_487 , struct V_6 , V_169 ) ;
}
static int F_291 ( struct V_486 * V_487 , int V_488 )
{
struct V_6 * V_6 = F_290 ( V_487 ) ;
struct V_19 * V_19 = V_6 -> V_19 ;
struct V_73 * V_74 ;
T_4 V_96 = 0 ;
int V_40 ;
while ( V_96 < V_488 &&
( V_74 = F_82 ( & V_6 -> V_129 ) ) ) {
V_40 = F_72 ( V_74 ) ;
if ( V_40 ) {
if ( F_239 () )
F_116 ( V_6 -> V_28 , L_38 ,
V_40 ) ;
} else {
V_40 = F_286 ( V_19 , V_6 ,
V_74 ) ;
if ( V_40 && F_239 () )
F_116 ( V_6 -> V_28 , L_39 ,
V_40 ) ;
}
if ( V_40 )
V_6 -> V_28 -> V_415 . V_498 ++ ;
F_73 ( V_74 ) ;
F_79 ( V_19 , & V_6 -> V_129 , V_74 ) ;
V_96 ++ ;
}
if ( V_96 < V_488 )
F_285 ( V_487 ) ;
F_83 ( V_19 , & V_6 -> V_129 , V_96 ) ;
return V_96 ;
}
static void F_292 ( struct V_6 * V_6 )
{
struct V_19 * V_19 = V_6 -> V_19 ;
T_5 V_499 = F_29 ( V_19 , V_500 ) ;
bool V_145 ;
V_145 = V_499 & ( 1 << V_6 -> V_143 ) ;
if ( V_145 )
F_124 ( V_6 -> V_28 ) ;
else
F_127 ( V_6 -> V_28 ) ;
}
static void F_293 ( struct V_19 * V_19 )
{
struct V_6 * V_6 ;
int V_36 ;
for ( V_36 = 0 ; V_36 < V_19 -> V_148 ; V_36 ++ ) {
V_6 = V_19 -> V_150 [ V_36 ] ;
F_213 ( V_6 , V_327 ) ;
F_294 ( V_6 -> V_28 ) ;
}
F_13 ( V_19 -> V_150 ) ;
}
static void F_295 ( struct V_19 * V_19 ,
struct V_6 * V_6 )
{
struct V_23 * V_24 = V_19 -> V_24 ;
int V_40 ;
V_40 = F_150 ( V_6 ,
V_6 -> V_28 -> V_379 ) ;
if ( V_40 ) {
F_296 ( & V_24 -> V_28 , L_40 ) ;
F_297 ( V_6 -> V_28 ) ;
}
}
static int F_298 ( struct V_19 * V_19 , unsigned int V_22 )
{
struct V_23 * V_24 = V_19 -> V_24 ;
struct V_6 * V_6 ;
struct V_126 * V_28 ;
int V_40 ;
V_28 = F_299 ( sizeof( struct V_6 ) ) ;
if ( ! V_28 )
return - V_44 ;
V_6 = F_230 ( V_28 ) ;
V_6 -> V_28 = V_28 ;
V_6 -> V_19 = V_19 ;
V_6 -> V_22 = V_22 ;
V_6 -> V_143 = V_22 + 1 ;
V_6 -> V_211 = V_212 | V_373 ;
F_295 ( V_19 , V_6 ) ;
V_28 -> V_501 = & V_502 ;
V_28 -> V_503 = & V_504 ;
F_300 ( V_28 , & V_6 -> V_168 , F_282 ,
V_505 ) ;
F_300 ( V_28 , & V_6 -> V_169 , F_291 ,
V_505 ) ;
F_292 ( V_6 ) ;
V_28 -> V_506 |= V_507 |
V_508 ;
V_40 = F_301 ( V_28 ) ;
if ( V_40 ) {
F_27 ( & V_24 -> V_28 , L_41 ) ;
goto V_509;
}
V_19 -> V_150 [ V_22 ] = V_6 ;
F_153 ( V_6 ) ;
V_6 -> V_9 =
F_226 ( V_6 , V_28 -> V_390 ) ;
V_40 = F_213 ( V_6 , 0 ) ;
if ( V_40 ) {
F_27 ( & V_24 -> V_28 , L_42 ) ;
goto V_510;
}
return 0 ;
V_510:
F_294 ( V_28 ) ;
V_509:
F_302 ( V_28 ) ;
return V_40 ;
}
static int F_303 ( struct V_19 * V_19 )
{
int V_36 ;
T_7 V_511 ;
int V_40 ;
V_511 = sizeof( struct V_6 * ) * V_19 -> V_148 ;
V_19 -> V_150 = F_11 ( V_511 , V_42 ) ;
if ( ! V_19 -> V_150 )
return - V_44 ;
for ( V_36 = 0 ; V_36 < V_19 -> V_148 ; V_36 ++ ) {
V_40 = F_298 ( V_19 , V_36 ) ;
if ( V_40 )
goto V_512;
}
return 0 ;
V_512:
F_293 ( V_19 ) ;
return V_40 ;
}
static int F_304 ( struct V_19 * V_19 )
{
struct V_23 * V_24 = V_19 -> V_24 ;
int V_21 ;
int V_36 ;
int V_40 ;
V_21 = F_305 ( V_24 ) ;
if ( V_21 < 0 )
return V_21 ;
if ( V_21 != F_306 ( V_19 -> V_148 ) )
return - V_149 ;
V_19 -> V_21 = F_307 ( V_21 ,
sizeof( struct V_513 ) ,
V_42 ) ;
if ( ! V_19 -> V_21 )
return - V_44 ;
for ( V_36 = 0 ; V_36 < V_21 ; V_36 ++ )
V_19 -> V_21 [ V_36 ] . V_214 = V_36 ;
V_40 = F_308 ( V_24 , V_19 -> V_21 , V_21 ) ;
if ( V_40 < 0 )
goto V_514;
return 0 ;
V_514:
F_13 ( V_19 -> V_21 ) ;
return V_40 ;
}
static void F_309 ( struct V_19 * V_19 )
{
F_310 ( V_19 -> V_24 ) ;
F_13 ( V_19 -> V_21 ) ;
}
static int F_311 ( struct V_23 * V_24 , const struct V_515 * V_465 )
{
struct V_19 * V_19 ;
int V_40 ;
V_19 = F_32 ( sizeof( * V_19 ) , V_42 ) ;
if ( ! V_19 )
return - V_44 ;
V_40 = F_312 ( V_24 ) ;
if ( V_40 ) {
F_27 ( & V_24 -> V_28 , L_43 ) ;
goto V_516;
}
V_40 = F_313 ( V_24 , V_58 ) ;
if ( V_40 ) {
F_27 ( & V_24 -> V_28 , L_44 ) ;
goto V_517;
}
V_40 = F_314 ( V_24 , F_315 ( 64 ) ) ;
if ( ! V_40 ) {
V_40 = F_316 ( V_24 , F_315 ( 64 ) ) ;
if ( V_40 ) {
F_27 ( & V_24 -> V_28 , L_45 ) ;
goto V_518;
}
} else {
V_40 = F_314 ( V_24 , F_315 ( 32 ) ) ;
if ( V_40 ) {
F_27 ( & V_24 -> V_28 , L_46 ) ;
goto V_518;
}
}
if ( F_317 ( V_24 , 0 ) < V_519 ) {
F_27 ( & V_24 -> V_28 , L_47 ) ;
goto V_520;
}
V_19 -> V_521 = F_318 ( F_319 ( V_24 , 0 ) ,
F_317 ( V_24 , 0 ) ) ;
if ( ! V_19 -> V_521 ) {
F_27 ( & V_24 -> V_28 , L_48 ) ;
V_40 = - V_29 ;
goto V_522;
}
F_320 ( V_24 ) ;
V_19 -> V_24 = V_24 ;
F_321 ( V_24 , V_19 ) ;
V_19 -> V_148 = F_26 ( V_19 , V_523 ) ;
V_40 = F_304 ( V_19 ) ;
if ( V_40 ) {
F_27 ( & V_24 -> V_28 , L_49 ) ;
goto V_524;
}
V_40 = F_39 ( V_19 ) ;
if ( V_40 ) {
F_27 ( & V_24 -> V_28 , L_50 ) ;
goto V_525;
}
F_25 ( V_19 , V_526 , V_527 ) ;
V_40 = F_102 ( V_19 ) ;
if ( V_40 )
goto V_528;
V_40 = F_40 ( F_18 ( V_19 , V_529 ) ,
F_120 , 0 ,
V_58 , V_19 ) ;
if ( V_40 ) {
F_27 ( & V_24 -> V_28 , L_51 ) ;
goto V_530;
}
V_40 = F_40 ( F_18 ( V_19 , V_531 ) ,
F_133 , 0 ,
V_58 , V_19 ) ;
if ( V_40 ) {
F_27 ( & V_24 -> V_28 , L_52 ) ;
goto V_532;
}
V_19 -> V_464 . V_465 = F_29 ( V_19 , V_533 ) ;
V_40 = F_171 ( V_19 ) ;
if ( V_40 ) {
F_27 ( & V_24 -> V_28 , L_53 ) ;
goto V_534;
}
V_40 = F_303 ( V_19 ) ;
if ( V_40 ) {
F_27 ( & V_24 -> V_28 , L_54 ) ;
goto V_535;
}
F_322 ( & V_24 -> V_28 , L_55 , V_19 -> V_464 . V_465 ) ;
return 0 ;
V_535:
F_173 ( V_19 ) ;
V_534:
V_60 ( F_18 ( V_19 , V_531 ) , V_19 ) ;
V_532:
V_60 ( F_18 ( V_19 , V_529 ) , V_19 ) ;
V_530:
F_104 ( V_19 ) ;
V_528:
V_525:
F_309 ( V_19 ) ;
V_524:
F_323 ( V_19 -> V_521 ) ;
V_522:
V_520:
V_518:
F_324 ( V_24 ) ;
V_517:
F_325 ( V_24 ) ;
V_516:
F_13 ( V_19 ) ;
return V_40 ;
}
static void F_326 ( struct V_23 * V_24 )
{
struct V_19 * V_19 = F_327 ( V_24 ) ;
F_173 ( V_19 ) ;
F_25 ( V_19 , V_526 , V_527 ) ;
F_293 ( V_19 ) ;
V_60 ( F_18 ( V_19 , V_531 ) , V_19 ) ;
V_60 ( F_18 ( V_19 , V_529 ) , V_19 ) ;
F_104 ( V_19 ) ;
F_309 ( V_19 ) ;
F_323 ( V_19 -> V_521 ) ;
F_324 ( V_19 -> V_24 ) ;
F_325 ( V_19 -> V_24 ) ;
F_13 ( V_19 ) ;
}
static bool F_328 ( struct V_126 * V_28 )
{
return V_28 -> V_501 == & V_502 ;
}
static int F_329 ( struct V_6 * V_6 ,
struct V_126 * V_246 )
{
int V_40 ;
F_227 ( V_6 ,
V_6 -> V_28 -> V_390 ) ;
V_6 -> V_10 = V_246 ;
V_40 = F_210 ( V_6 , V_327 , 0 ) ;
if ( V_40 )
return V_40 ;
V_6 -> V_9 =
F_226 ( V_6 ,
V_246 -> V_390 ) ;
V_40 = F_210 ( V_6 , 0 , 0 ) ;
return V_40 ;
}
static int F_330 ( struct V_6 * V_6 )
{
int V_40 ;
F_227 ( V_6 ,
V_6 -> V_10 -> V_390 ) ;
V_6 -> V_10 = NULL ;
V_40 = F_210 ( V_6 , V_327 , 0 ) ;
if ( V_40 )
return V_40 ;
V_6 -> V_9 =
F_226 ( V_6 ,
V_6 -> V_28 -> V_390 ) ;
V_40 = F_210 ( V_6 , 0 , 0 ) ;
return V_40 ;
}
static int F_331 ( struct V_126 * V_28 )
{
struct V_6 * V_6 = F_230 ( V_28 ) ;
struct V_126 * V_536 = F_332 ( V_28 ) ;
int V_40 = 0 ;
if ( V_536 && V_536 -> V_537 &&
! strcmp ( V_536 -> V_537 -> V_538 , L_56 ) )
V_40 = F_329 ( V_6 , V_536 ) ;
else if ( F_6 ( V_6 ) )
V_40 = F_330 ( V_6 ) ;
return V_40 ;
}
static int F_333 ( struct V_539 * V_540 ,
unsigned long V_541 , void * V_91 )
{
struct V_126 * V_28 ;
int V_40 ;
switch ( V_541 ) {
case V_542 :
V_28 = F_334 ( V_91 ) ;
if ( ! F_328 ( V_28 ) )
return V_543 ;
V_40 = F_331 ( V_28 ) ;
if ( V_40 )
F_335 ( V_28 ,
L_57 ,
V_40 ) ;
break;
}
return V_543 ;
}
static int T_14 F_336 ( void )
{
int V_40 ;
F_337 ( & V_544 ) ;
V_40 = F_338 ( & V_545 ) ;
if ( V_40 )
goto V_546;
return 0 ;
V_546:
F_339 ( & V_544 ) ;
return V_40 ;
}
static void T_15 F_340 ( void )
{
F_339 ( & V_544 ) ;
F_341 ( & V_545 ) ;
}
