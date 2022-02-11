static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 ) ;
}
static int F_3 ( struct V_4 * V_5 ,
unsigned V_6 , T_1 * V_7 )
{
int V_8 ;
V_8 = F_4 ( V_5 , V_7 ) ;
if ( V_8 )
return V_8 ;
return F_5 ( V_5 , * V_7 , 0 , V_6 , false , V_7 ) ;
}
static T_2 F_6 ( unsigned V_6 )
{
return sizeof( unsigned long ) * F_7 ( V_6 , V_9 ) ;
}
static int F_8 ( struct V_1 * V_2 , T_1 V_10 )
{
V_2 -> V_11 . V_6 = V_10 ;
V_2 -> V_11 . V_7 = V_12 ;
V_2 -> V_3 = F_9 ( F_6 ( V_10 ) ) ;
if ( ! V_2 -> V_3 ) {
F_10 ( L_1 , V_13 ) ;
return - V_14 ;
}
return 0 ;
}
static int F_11 ( struct V_4 * V_5 , struct V_1 * V_2 )
{
int V_8 ;
memset ( V_2 -> V_3 , 0 , F_6 ( V_2 -> V_11 . V_6 ) ) ;
V_8 = F_3 ( V_5 , V_2 -> V_11 . V_6 , & V_2 -> V_11 . V_7 ) ;
if ( V_8 ) {
F_10 ( L_2 , V_13 ) ;
return V_8 ;
}
return 0 ;
}
static bool F_12 ( struct V_1 * V_2 , T_1 V_15 )
{
return F_13 ( V_15 , V_2 -> V_3 ) ;
}
static int F_14 ( struct V_4 * V_5 ,
struct V_16 * V_17 , T_1 V_15 ,
bool * V_18 )
{
T_1 V_19 = V_17 -> V_7 ;
int V_8 = F_15 ( V_5 , V_17 -> V_7 , V_15 , & V_17 -> V_7 , V_18 ) ;
if ( V_8 ) {
F_10 ( L_3 , V_13 ) ;
return V_8 ;
}
F_16 ( V_17 -> V_7 != V_19 ) ;
return V_8 ;
}
static int F_17 ( struct V_4 * V_5 ,
struct V_1 * V_2 , T_3 V_15 )
{
int V_8 ;
if ( ! F_18 ( V_15 , V_2 -> V_3 ) ) {
V_8 = F_19 ( V_5 , V_2 -> V_11 . V_7 , V_15 , & V_2 -> V_11 . V_7 ) ;
if ( V_8 ) {
return V_8 ;
}
return 0 ;
}
return 1 ;
}
static void F_20 ( struct V_20 * V_21 ,
struct V_22 * V_23 ,
T_2 V_24 )
{
struct V_25 * V_26 = F_21 ( V_23 ) ;
V_26 -> V_27 = F_22 ( F_23 ( V_23 ) ) ;
V_26 -> V_28 = F_24 ( F_25 ( & V_26 -> V_29 ,
V_24 - sizeof( V_30 ) ,
V_31 ) ) ;
}
static int F_26 ( struct V_25 * V_26 )
{
T_3 V_32 = F_27 ( V_26 -> V_33 ) ;
if ( V_32 < V_34 || V_32 > V_35 ) {
F_10 ( L_4 ,
V_32 , V_34 , V_35 ) ;
return - V_36 ;
}
return 0 ;
}
static int F_28 ( struct V_20 * V_21 ,
struct V_22 * V_23 ,
T_2 V_24 )
{
struct V_25 * V_26 = F_21 ( V_23 ) ;
V_30 V_37 ;
if ( F_23 ( V_23 ) != F_29 ( V_26 -> V_27 ) ) {
F_10 ( L_5 ,
F_29 ( V_26 -> V_27 ) ,
( unsigned long long ) F_23 ( V_23 ) ) ;
return - V_38 ;
}
if ( F_29 ( V_26 -> V_39 ) != V_40 ) {
F_10 ( L_6 ,
F_29 ( V_26 -> V_39 ) ,
( unsigned long long ) V_40 ) ;
return - V_41 ;
}
V_37 = F_24 ( F_25 ( & V_26 -> V_29 ,
V_24 - sizeof( V_30 ) ,
V_31 ) ) ;
if ( V_37 != V_26 -> V_28 ) {
F_10 ( L_7 ,
F_27 ( V_37 ) , F_27 ( V_26 -> V_28 ) ) ;
return - V_41 ;
}
return F_26 ( V_26 ) ;
}
static int F_30 ( struct V_42 * V_11 ,
struct V_22 * * V_43 )
{
return F_31 ( V_11 -> V_44 , V_45 ,
& V_46 , V_43 ) ;
}
static int F_32 ( struct V_42 * V_11 ,
struct V_22 * * V_43 )
{
return F_33 ( V_11 -> V_44 , V_45 ,
& V_46 , V_43 ) ;
}
static int F_34 ( struct V_42 * V_11 ,
struct V_22 * * V_43 )
{
return F_35 ( V_11 -> V_44 , V_45 ,
& V_46 , V_43 ) ;
}
static int F_36 ( struct V_47 * V_44 , bool * V_18 )
{
int V_8 ;
unsigned V_48 ;
struct V_22 * V_23 ;
T_4 * V_49 , V_50 = F_22 ( 0 ) ;
unsigned V_24 = F_37 ( V_44 ) / sizeof( T_4 ) ;
V_8 = F_31 ( V_44 , V_45 , NULL , & V_23 ) ;
if ( V_8 )
return V_8 ;
V_49 = F_21 ( V_23 ) ;
* V_18 = true ;
for ( V_48 = 0 ; V_48 < V_24 ; V_48 ++ ) {
if ( V_49 [ V_48 ] != V_50 ) {
* V_18 = false ;
break;
}
}
F_38 ( V_23 ) ;
return 0 ;
}
static void F_39 ( const struct V_16 * V_51 , struct V_52 * V_26 )
{
V_26 -> V_6 = F_24 ( V_51 -> V_6 ) ;
V_26 -> V_7 = F_22 ( V_51 -> V_7 ) ;
}
static void F_40 ( const struct V_52 * V_26 , struct V_16 * V_51 )
{
V_51 -> V_6 = F_27 ( V_26 -> V_6 ) ;
V_51 -> V_7 = F_29 ( V_26 -> V_7 ) ;
}
static void F_41 ( void * V_53 , const void * V_54 )
{
struct V_42 * V_11 = V_53 ;
struct V_52 V_55 ;
T_1 V_23 ;
memcpy ( & V_55 , V_54 , sizeof( V_55 ) ) ;
V_23 = F_29 ( V_55 . V_7 ) ;
F_42 ( V_11 -> V_56 , V_23 ) ;
}
static void F_43 ( void * V_53 , const void * V_54 )
{
struct V_42 * V_11 = V_53 ;
struct V_52 V_55 ;
T_1 V_23 ;
memcpy ( & V_55 , V_54 , sizeof( V_55 ) ) ;
V_23 = F_29 ( V_55 . V_7 ) ;
F_44 ( & V_11 -> V_57 , V_23 ) ;
}
static int F_45 ( void * V_53 , const void * V_58 , const void * V_59 )
{
return ! memcmp ( V_58 , V_59 , sizeof( struct V_16 ) ) ;
}
static void F_46 ( struct V_42 * V_11 )
{
struct V_60 * V_61 = & V_11 -> V_62 . V_63 ;
V_11 -> V_62 . V_56 = V_11 -> V_56 ;
V_11 -> V_62 . V_64 = 1 ;
V_61 -> V_53 = V_11 ;
V_61 -> V_65 = sizeof( struct V_52 ) ;
V_61 -> V_66 = F_41 ;
V_61 -> V_67 = F_43 ;
V_61 -> V_68 = F_45 ;
}
static void F_47 ( struct V_42 * V_11 )
{
struct V_60 V_61 ;
V_61 . V_53 = NULL ;
V_61 . V_65 = sizeof( V_30 ) ;
V_61 . V_66 = NULL ;
V_61 . V_67 = NULL ;
V_61 . V_68 = NULL ;
F_48 ( & V_11 -> V_69 , V_11 -> V_56 , & V_61 ) ;
}
static void F_49 ( struct V_42 * V_11 )
{
F_50 ( V_11 -> V_56 , & V_11 -> V_57 ) ;
F_46 ( V_11 ) ;
F_47 ( V_11 ) ;
}
static int F_51 ( struct V_42 * V_11 )
{
int V_8 ;
V_8 = F_52 ( V_11 -> V_44 , V_45 ,
& V_11 -> V_56 , & V_11 -> V_70 ) ;
if ( V_8 < 0 ) {
F_10 ( L_8 ) ;
return V_8 ;
}
F_49 ( V_11 ) ;
V_8 = F_53 ( & V_11 -> V_62 , & V_11 -> V_71 ) ;
if ( V_8 ) {
F_10 ( L_9 ) ;
goto V_72;
}
V_8 = F_54 ( & V_11 -> V_69 , & V_11 -> V_73 ) ;
if ( V_8 ) {
F_10 ( L_10 ) ;
goto V_72;
}
return 0 ;
V_72:
F_55 ( V_11 -> V_70 ) ;
F_56 ( V_11 -> V_56 ) ;
return V_8 ;
}
static int F_57 ( struct V_42 * V_11 )
{
int V_8 ;
T_2 V_74 ;
V_8 = F_58 ( V_11 -> V_70 , & V_74 ) ;
if ( V_8 < 0 )
return V_8 ;
return F_59 ( V_11 -> V_70 , & V_11 -> V_75 ,
V_74 ) ;
}
static void F_60 ( struct V_42 * V_11 , struct V_25 * V_26 )
{
memcpy ( & V_26 -> V_75 ,
& V_11 -> V_75 ,
sizeof( V_11 -> V_75 ) ) ;
}
static void F_61 ( struct V_42 * V_11 , struct V_25 * V_26 )
{
V_26 -> V_39 = F_22 ( V_40 ) ;
V_26 -> V_29 = F_24 ( 0ul ) ;
memset ( V_26 -> V_76 , 0 , sizeof( V_26 -> V_76 ) ) ;
V_26 -> V_33 = F_24 ( V_35 ) ;
F_60 ( V_11 , V_26 ) ;
V_26 -> V_77 = F_24 ( V_11 -> V_78 ) ;
V_26 -> V_79 = F_24 ( V_80 >> V_81 ) ;
V_26 -> V_10 = F_24 ( V_11 -> V_10 ) ;
V_26 -> V_82 = F_24 ( V_11 -> V_82 ) ;
F_39 ( & V_11 -> V_83 -> V_11 , & V_26 -> V_83 ) ;
V_26 -> V_71 = F_22 ( V_11 -> V_71 ) ;
V_26 -> V_73 = F_22 ( V_11 -> V_73 ) ;
V_26 -> V_84 = F_22 ( V_11 -> V_84 ) ;
}
static int F_62 ( struct V_42 * V_11 )
{
int V_8 ;
struct V_22 * V_43 ;
struct V_25 * V_26 ;
V_8 = F_57 ( V_11 ) ;
if ( V_8 ) {
F_10 ( L_11 , V_13 ) ;
return V_8 ;
}
V_8 = F_32 ( V_11 , & V_43 ) ;
if ( V_8 )
return V_8 ;
V_26 = F_21 ( V_43 ) ;
F_61 ( V_11 , V_26 ) ;
return F_63 ( V_11 -> V_56 , V_43 ) ;
}
static int F_64 ( struct V_42 * V_11 )
{
int V_8 ;
V_8 = F_51 ( V_11 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_62 ( V_11 ) ;
if ( V_8 ) {
F_55 ( V_11 -> V_70 ) ;
F_56 ( V_11 -> V_56 ) ;
return V_8 ;
}
return 0 ;
}
static int F_65 ( struct V_42 * V_11 )
{
int V_8 ;
struct V_22 * V_43 ;
struct V_25 * V_26 ;
V_8 = F_30 ( V_11 , & V_43 ) ;
if ( V_8 ) {
F_10 ( L_12 ) ;
return V_8 ;
}
V_26 = F_21 ( V_43 ) ;
V_8 = F_66 ( V_11 -> V_44 , V_45 ,
V_26 -> V_75 ,
sizeof( V_26 -> V_75 ) ,
& V_11 -> V_56 , & V_11 -> V_70 ) ;
if ( V_8 ) {
F_10 ( L_13 ) ;
goto V_72;
}
F_49 ( V_11 ) ;
V_11 -> V_78 = F_27 ( V_26 -> V_77 ) ;
V_11 -> V_10 = F_27 ( V_26 -> V_10 ) ;
V_11 -> V_82 = F_27 ( V_26 -> V_82 ) ;
V_11 -> V_71 = F_29 ( V_26 -> V_71 ) ;
V_11 -> V_73 = F_29 ( V_26 -> V_73 ) ;
V_11 -> V_84 = F_29 ( V_26 -> V_84 ) ;
V_11 -> V_85 = true ;
F_38 ( V_43 ) ;
return 0 ;
V_72:
F_38 ( V_43 ) ;
return V_8 ;
}
static int F_67 ( struct V_42 * V_11 ,
bool V_86 )
{
int V_8 ;
bool V_87 = false ;
V_8 = F_36 ( V_11 -> V_44 , & V_87 ) ;
if ( V_8 )
return V_8 ;
if ( V_87 )
return V_86 ? F_64 ( V_11 ) : - V_88 ;
return F_65 ( V_11 ) ;
}
static int F_68 ( struct V_42 * V_11 ,
bool V_86 )
{
int V_8 ;
V_11 -> V_44 = F_69 ( V_11 -> V_89 , V_80 ,
V_90 ) ;
if ( F_70 ( V_11 -> V_44 ) ) {
F_10 ( L_14 ) ;
return F_71 ( V_11 -> V_44 ) ;
}
V_8 = F_67 ( V_11 , V_86 ) ;
if ( V_8 )
F_72 ( V_11 -> V_44 ) ;
return V_8 ;
}
static void F_73 ( struct V_42 * V_11 )
{
F_55 ( V_11 -> V_70 ) ;
F_56 ( V_11 -> V_56 ) ;
F_72 ( V_11 -> V_44 ) ;
}
static void F_74 ( struct V_42 * V_11 , struct V_1 * V_91 )
{
F_75 ( V_11 -> V_83 , V_91 ) ;
F_76 () ;
}
static int F_77 ( struct V_42 * V_11 ,
struct V_92 * V_93 )
{
int V_8 ;
T_5 V_94 = V_93 -> V_95 ;
V_8 = F_78 ( & V_11 -> V_62 , V_11 -> V_71 ,
& V_94 , & V_11 -> V_71 ) ;
if ( V_8 ) {
F_10 ( L_15 , V_13 ) ;
return V_8 ;
}
V_93 -> V_96 = V_97 ;
return 0 ;
}
static int F_79 ( struct V_42 * V_11 ,
struct V_92 * V_93 )
{
int V_8 ;
bool V_98 ;
unsigned V_23 , V_99 = F_80 ( V_93 -> V_100 + V_101 , V_93 -> V_6 ) ;
for ( V_23 = V_93 -> V_100 ; V_23 < V_99 ; V_23 ++ ) {
V_8 = F_14 ( & V_93 -> V_5 , & V_93 -> V_1 , V_23 , & V_98 ) ;
if ( V_8 ) {
F_10 ( L_16 , V_13 ) ;
return V_8 ;
}
if ( ! V_98 )
continue;
F_81 ( & V_93 -> V_54 ) ;
V_8 = F_82 ( & V_11 -> V_69 , V_11 -> V_73 ,
V_23 , & V_93 -> V_54 , & V_11 -> V_73 ) ;
if ( V_8 ) {
F_10 ( L_17 , V_13 ) ;
return V_8 ;
}
}
if ( V_23 == V_93 -> V_6 )
V_93 -> V_96 = F_77 ;
else
V_93 -> V_100 = V_23 ;
return 0 ;
}
static int V_97 ( struct V_42 * V_11 ,
struct V_92 * V_93 )
{
int V_8 ;
T_5 V_94 ;
struct V_52 V_26 ;
V_8 = F_83 ( & V_11 -> V_62 ,
V_11 -> V_71 , & V_94 ) ;
if ( V_8 < 0 )
return V_8 ;
V_93 -> V_95 = V_94 ;
V_8 = F_84 ( & V_11 -> V_62 ,
V_11 -> V_71 , & V_94 , & V_26 ) ;
if ( V_8 ) {
if ( V_8 == - V_102 ) {
V_93 -> V_96 = NULL ;
return 0 ;
}
F_10 ( L_18 , V_13 ) ;
return V_8 ;
}
F_40 ( & V_26 , & V_93 -> V_1 ) ;
V_93 -> V_54 = F_24 ( V_94 ) ;
V_93 -> V_6 = F_80 ( V_93 -> V_1 . V_6 , V_11 -> V_10 ) ;
V_93 -> V_100 = 0 ;
V_93 -> V_96 = F_79 ;
return 0 ;
}
static int F_85 ( struct V_42 * V_11 , struct V_92 * V_93 )
{
if ( V_93 -> V_96 )
return 0 ;
memset ( V_93 , 0 , sizeof( * V_93 ) ) ;
F_50 ( V_11 -> V_56 , & V_93 -> V_5 ) ;
V_93 -> V_96 = V_97 ;
return 0 ;
}
static struct V_42 * F_86 ( struct V_103 * V_89 ,
T_6 V_78 ,
bool V_86 )
{
int V_8 ;
struct V_42 * V_11 = F_87 ( sizeof( * V_11 ) , V_104 ) ;
if ( ! V_11 )
return NULL ;
V_11 -> V_89 = V_89 ;
V_11 -> V_78 = V_78 ;
V_11 -> V_105 [ 0 ] . V_11 . V_7 = V_12 ;
V_11 -> V_105 [ 1 ] . V_11 . V_7 = V_12 ;
V_11 -> V_83 = & V_11 -> V_105 [ 0 ] ;
V_8 = F_68 ( V_11 , V_86 ) ;
if ( V_8 ) {
F_88 ( V_11 ) ;
return F_89 ( V_8 ) ;
}
return V_11 ;
}
static void F_90 ( struct V_42 * V_11 )
{
F_73 ( V_11 ) ;
F_88 ( V_11 ) ;
}
static bool F_91 ( T_1 V_106 )
{
return V_106 < ( 1ull << 31 ) ;
}
static int F_92 ( struct V_42 * V_11 , void * V_107 )
{
int V_8 ;
T_1 * V_108 = V_107 ;
V_30 V_54 ;
if ( ! F_91 ( * V_108 ) ) {
F_10 ( L_19 ,
( unsigned long long ) * V_108 ) ;
return - V_36 ;
}
F_1 ( & V_11 -> V_105 [ 0 ] ) ;
F_1 ( & V_11 -> V_105 [ 1 ] ) ;
V_8 = F_8 ( & V_11 -> V_105 [ 0 ] , * V_108 ) ;
if ( V_8 ) {
F_10 ( L_20 , V_13 ) ;
return V_8 ;
}
V_8 = F_8 ( & V_11 -> V_105 [ 1 ] , * V_108 ) ;
if ( V_8 ) {
F_10 ( L_21 , V_13 ) ;
return V_8 ;
}
V_54 = F_24 ( 0u ) ;
F_81 ( & V_54 ) ;
V_8 = F_93 ( & V_11 -> V_69 , V_11 -> V_73 ,
V_11 -> V_10 , * V_108 ,
& V_54 , & V_11 -> V_73 ) ;
if ( V_8 ) {
F_10 ( L_22 , V_13 ) ;
return V_8 ;
}
V_11 -> V_10 = * V_108 ;
return 0 ;
}
static int F_94 ( struct V_42 * V_11 )
{
int V_8 ;
T_5 V_109 [ 1 ] ;
struct V_52 V_54 ;
V_8 = F_95 ( & V_11 -> V_57 , V_11 -> V_83 -> V_11 . V_7 ,
& V_11 -> V_83 -> V_11 . V_7 ) ;
if ( V_8 ) {
F_10 ( L_23 , V_13 ) ;
return V_8 ;
}
F_39 ( & V_11 -> V_83 -> V_11 , & V_54 ) ;
V_11 -> V_83 -> V_11 . V_7 = V_12 ;
V_109 [ 0 ] = V_11 -> V_82 ;
F_81 ( & V_54 ) ;
V_8 = F_96 ( & V_11 -> V_62 , V_11 -> V_71 ,
V_109 , & V_54 , & V_11 -> V_71 ) ;
if ( V_8 ) {
F_10 ( L_24 , V_13 ) ;
return V_8 ;
}
V_11 -> V_85 = true ;
return 0 ;
}
static struct V_1 * F_97 ( struct V_42 * V_11 )
{
return ( V_11 -> V_83 == & V_11 -> V_105 [ 0 ] ) ?
& V_11 -> V_105 [ 1 ] : & V_11 -> V_105 [ 0 ] ;
}
static int F_98 ( struct V_42 * V_11 )
{
int V_8 ;
struct V_1 * V_91 = F_97 ( V_11 ) ;
V_8 = F_11 ( & V_11 -> V_57 , V_91 ) ;
if ( V_8 ) {
F_10 ( L_25 , V_13 ) ;
return V_8 ;
}
F_74 ( V_11 , V_91 ) ;
V_11 -> V_82 ++ ;
return 0 ;
}
static int F_99 ( struct V_42 * V_11 )
{
int V_8 ;
if ( V_11 -> V_83 -> V_11 . V_7 != V_12 ) {
V_8 = F_94 ( V_11 ) ;
if ( V_8 ) {
F_10 ( L_26 , V_13 ) ;
return V_8 ;
}
}
V_8 = F_98 ( V_11 ) ;
if ( V_8 ) {
F_10 ( L_27 , V_13 ) ;
return V_8 ;
}
return 0 ;
}
static bool F_100 ( struct V_42 * V_11 , T_1 V_15 )
{
bool V_8 ;
struct V_1 * V_2 ;
F_101 () ;
V_2 = F_102 ( V_11 -> V_83 ) ;
V_8 = F_12 ( V_2 , V_15 ) ;
F_103 () ;
return V_8 ;
}
static int F_104 ( struct V_42 * V_11 )
{
int V_8 ;
struct V_22 * V_43 ;
if ( V_11 -> V_83 -> V_11 . V_7 != V_45 ) {
V_8 = F_95 ( & V_11 -> V_57 , V_11 -> V_83 -> V_11 . V_7 ,
& V_11 -> V_83 -> V_11 . V_7 ) ;
if ( V_8 ) {
F_10 ( L_28 , V_13 ) ;
return V_8 ;
}
}
V_8 = F_105 ( V_11 -> V_56 ) ;
if ( V_8 ) {
F_10 ( L_29 , V_13 ) ;
return V_8 ;
}
V_8 = F_57 ( V_11 ) ;
if ( V_8 ) {
F_10 ( L_11 , V_13 ) ;
return V_8 ;
}
V_8 = F_34 ( V_11 , & V_43 ) ;
if ( V_8 ) {
F_10 ( L_30 , V_13 ) ;
return V_8 ;
}
F_61 ( V_11 , F_21 ( V_43 ) ) ;
return F_63 ( V_11 -> V_56 , V_43 ) ;
}
static int F_106 ( struct V_42 * V_11 )
{
return F_99 ( V_11 ) ;
}
static int F_107 ( struct V_42 * V_11 )
{
int V_8 , V_66 ;
struct V_22 * V_110 ;
if ( V_11 -> V_84 != V_45 ) {
F_10 ( L_31 , V_13 ) ;
return - V_36 ;
}
V_8 = F_99 ( V_11 ) ;
if ( V_8 ) {
F_10 ( L_32 , V_13 ) ;
return V_8 ;
}
V_8 = F_104 ( V_11 ) ;
if ( V_8 ) {
F_10 ( L_29 , V_13 ) ;
return V_8 ;
}
V_8 = F_108 ( V_11 -> V_70 , V_45 ) ;
if ( V_8 ) {
F_10 ( L_33 , V_13 ) ;
return V_8 ;
}
V_8 = F_109 ( V_11 -> V_56 , V_45 ,
& V_46 , & V_110 , & V_66 ) ;
if ( V_8 ) {
F_10 ( L_34 , V_13 ) ;
F_110 ( V_11 -> V_70 , V_45 ) ;
return V_8 ;
}
F_16 ( ! V_66 ) ;
V_8 = F_108 ( V_11 -> V_70 , V_11 -> V_71 ) ;
if ( V_8 ) {
F_10 ( L_35 , V_13 ) ;
F_111 ( V_11 -> V_56 , V_110 ) ;
return V_8 ;
}
V_8 = F_108 ( V_11 -> V_70 , V_11 -> V_73 ) ;
if ( V_8 ) {
F_10 ( L_36 , V_13 ) ;
F_110 ( V_11 -> V_70 , V_11 -> V_71 ) ;
F_111 ( V_11 -> V_56 , V_110 ) ;
return V_8 ;
}
V_11 -> V_84 = F_23 ( V_110 ) ;
F_111 ( V_11 -> V_56 , V_110 ) ;
return 0 ;
}
static int F_112 ( struct V_42 * V_11 )
{
int V_8 ;
T_1 V_111 ;
struct V_22 * V_110 ;
struct V_25 * V_26 ;
if ( V_11 -> V_84 == V_45 ) {
F_10 ( L_37 , V_13 ) ;
return - V_36 ;
}
V_8 = F_113 ( V_11 -> V_56 , V_11 -> V_84 , & V_46 , & V_110 ) ;
if ( V_8 ) {
F_10 ( L_38 , V_13 ) ;
return V_8 ;
}
V_11 -> V_84 = V_45 ;
V_26 = F_21 ( V_110 ) ;
V_8 = F_114 ( & V_11 -> V_62 ,
F_29 ( V_26 -> V_71 ) ) ;
if ( V_8 ) {
F_10 ( L_39 , V_13 ) ;
F_111 ( V_11 -> V_56 , V_110 ) ;
return V_8 ;
}
V_8 = F_115 ( & V_11 -> V_69 , F_29 ( V_26 -> V_73 ) ) ;
if ( V_8 ) {
F_10 ( L_40 , V_13 ) ;
F_111 ( V_11 -> V_56 , V_110 ) ;
return V_8 ;
}
V_111 = F_23 ( V_110 ) ;
F_111 ( V_11 -> V_56 , V_110 ) ;
return F_110 ( V_11 -> V_70 , V_111 ) ;
}
static int F_116 ( struct V_42 * V_11 , void * V_112 )
{
int V_8 ;
struct V_113 * V_114 = V_112 ;
T_1 V_115 , V_116 ;
V_8 = F_117 ( V_11 -> V_70 , & V_115 ) ;
if ( V_8 ) {
F_10 ( L_41 , V_8 ) ;
return V_8 ;
}
V_8 = F_118 ( V_11 -> V_70 , & V_116 ) ;
if ( V_8 ) {
F_10 ( L_42 , V_8 ) ;
return V_8 ;
}
V_114 -> V_117 = V_116 - V_115 ;
V_114 -> V_118 = V_116 ;
V_114 -> V_119 = V_11 -> V_84 ;
V_114 -> V_95 = V_11 -> V_82 ;
return 0 ;
}
static bool F_119 ( struct V_95 * V_95 )
{
return V_95 -> V_120 >= 0 ;
}
static T_1 F_120 ( struct V_95 * V_95 , struct V_121 * V_121 )
{
T_6 V_122 = V_121 -> V_123 . V_124 ;
if ( ! F_119 ( V_95 ) )
( void ) F_121 ( V_122 , V_95 -> V_125 ) ;
else
V_122 >>= V_95 -> V_120 ;
return V_122 ;
}
static void F_122 ( struct V_95 * V_95 , struct V_121 * V_121 )
{
V_121 -> V_126 = V_95 -> V_127 -> V_89 ;
}
static void F_123 ( struct V_95 * V_95 )
{
if ( ! F_124 ( & V_95 -> V_128 ) )
F_125 ( V_95 -> V_129 , & V_95 -> V_130 ) ;
}
static void F_126 ( struct V_95 * V_95 )
{
int V_8 ;
if ( ! V_95 -> V_92 . V_96 )
return;
V_8 = V_95 -> V_92 . V_96 ( V_95 -> V_11 , & V_95 -> V_92 ) ;
if ( V_8 < 0 ) {
F_10 ( L_43 , V_13 ) ;
V_95 -> V_92 . V_96 = NULL ;
} else if ( V_95 -> V_92 . V_96 )
F_123 ( V_95 ) ;
}
static void F_127 ( struct V_95 * V_95 )
{
int V_8 ;
struct V_131 V_132 , V_133 ;
struct V_121 * V_121 ;
bool V_134 = false ;
bool V_135 = false ;
F_128 ( & V_132 ) ;
F_128 ( & V_133 ) ;
F_129 ( & V_95 -> V_136 ) ;
F_130 ( & V_132 , & V_95 -> V_132 ) ;
F_128 ( & V_95 -> V_132 ) ;
F_131 ( & V_95 -> V_136 ) ;
while ( ( V_121 = F_132 ( & V_132 ) ) ) {
V_8 = F_17 ( & V_95 -> V_11 -> V_57 ,
V_95 -> V_11 -> V_83 ,
F_120 ( V_95 , V_121 ) ) ;
if ( V_8 < 0 ) {
V_135 = true ;
} else if ( V_8 == 0 )
V_134 = true ;
F_133 ( & V_133 , V_121 ) ;
}
if ( V_134 ) {
V_8 = F_104 ( V_95 -> V_11 ) ;
if ( V_8 )
V_135 = true ;
}
if ( V_135 )
while ( ( V_121 = F_132 ( & V_133 ) ) )
F_134 ( V_121 ) ;
else
while ( ( V_121 = F_132 ( & V_133 ) ) )
F_135 ( V_121 ) ;
}
static void F_136 ( struct V_95 * V_95 )
{
int V_8 ;
bool V_137 = false ;
struct V_138 V_139 ;
struct V_140 * V_140 , * V_141 ;
F_137 ( & V_139 ) ;
F_129 ( & V_95 -> V_142 ) ;
F_138 ( & V_95 -> V_143 , & V_139 ) ;
F_131 ( & V_95 -> V_142 ) ;
F_139 (rpc, tmp, &calls, list) {
V_140 -> V_18 = V_140 -> V_144 ? V_140 -> V_144 ( V_95 -> V_11 ) : V_140 -> V_145 ( V_95 -> V_11 , V_140 -> V_107 ) ;
V_137 = true ;
}
if ( V_137 ) {
V_8 = F_104 ( V_95 -> V_11 ) ;
if ( V_8 )
F_139 (rpc, tmp, &calls, list)
V_140 -> V_18 = V_8 ;
}
F_139 (rpc, tmp, &calls, list)
F_140 ( & V_140 -> F_140 ) ;
}
static void F_141 ( struct V_95 * V_95 )
{
if ( V_95 -> V_11 -> V_85 ) {
V_95 -> V_11 -> V_85 = false ;
F_85 ( V_95 -> V_11 , & V_95 -> V_92 ) ;
}
}
static void F_142 ( struct V_146 * V_2 )
{
struct V_95 * V_95 = F_143 ( V_2 , struct V_95 , V_130 ) ;
F_141 ( V_95 ) ;
F_126 ( V_95 ) ;
F_127 ( V_95 ) ;
F_136 ( V_95 ) ;
}
static void F_144 ( struct V_95 * V_95 , struct V_121 * V_121 )
{
F_129 ( & V_95 -> V_136 ) ;
F_133 ( & V_95 -> V_132 , V_121 ) ;
F_131 ( & V_95 -> V_136 ) ;
F_123 ( V_95 ) ;
}
static int F_145 ( struct V_95 * V_95 , struct V_140 * V_140 )
{
V_140 -> V_18 = 0 ;
F_146 ( & V_140 -> F_140 ) ;
F_129 ( & V_95 -> V_142 ) ;
F_147 ( & V_140 -> V_147 , & V_95 -> V_143 ) ;
F_131 ( & V_95 -> V_142 ) ;
F_123 ( V_95 ) ;
F_148 ( & V_140 -> F_140 ) ;
return V_140 -> V_18 ;
}
static int F_149 ( struct V_95 * V_95 , int (* F_150)( struct V_42 * ) )
{
struct V_140 V_140 ;
V_140 . V_144 = F_150 ;
V_140 . V_145 = NULL ;
return F_145 ( V_95 , & V_140 ) ;
}
static int F_151 ( struct V_95 * V_95 ,
int (* F_150)( struct V_42 * , void * ) , void * V_107 )
{
struct V_140 V_140 ;
V_140 . V_144 = NULL ;
V_140 . V_145 = F_150 ;
V_140 . V_107 = V_107 ;
return F_145 ( V_95 , & V_140 ) ;
}
static void F_152 ( struct V_95 * V_95 )
{
F_153 ( & V_95 -> V_128 , 0 ) ;
}
static void F_154 ( struct V_95 * V_95 )
{
F_153 ( & V_95 -> V_128 , 1 ) ;
F_155 ( V_95 -> V_129 ) ;
}
static int F_156 ( struct V_148 * V_149 , int V_150 )
{
struct V_151 * V_152 = F_157 ( V_149 -> V_89 ) ;
return F_158 ( V_152 -> V_153 , V_150 ) ;
}
static int F_159 ( struct V_154 * V_155 , int V_150 )
{
struct V_95 * V_95 = F_143 ( V_155 , struct V_95 , V_156 ) ;
return F_156 ( V_95 -> V_127 , V_150 ) ;
}
static void F_160 ( struct V_95 * V_95 )
{
if ( V_95 -> V_11 )
F_90 ( V_95 -> V_11 ) ;
if ( V_95 -> V_129 )
F_161 ( V_95 -> V_129 ) ;
if ( V_95 -> V_127 )
F_162 ( V_95 -> V_157 , V_95 -> V_127 ) ;
if ( V_95 -> V_158 )
F_162 ( V_95 -> V_157 , V_95 -> V_158 ) ;
F_88 ( V_95 ) ;
}
static T_1 F_163 ( struct V_95 * V_95 )
{
return F_164 ( V_95 -> V_157 -> V_159 , V_95 -> V_125 ) ;
}
static bool F_165 ( T_1 V_78 )
{
bool V_160 = V_78 > 0 ;
bool V_161 = ( V_78 & ( V_162 - 1 ) ) == 0 ;
return V_160 && V_161 ;
}
static int F_166 ( struct V_163 * V_157 , unsigned V_164 , char * * V_165 )
{
int V_8 ;
char V_166 ;
struct V_95 * V_95 ;
struct V_42 * V_11 ;
if ( V_164 != 3 ) {
V_157 -> error = L_44 ;
return - V_36 ;
}
V_95 = F_87 ( sizeof( * V_95 ) , V_104 ) ;
if ( ! V_95 ) {
V_157 -> error = L_45 ;
return - V_14 ;
}
V_95 -> V_157 = V_157 ;
V_8 = F_167 ( V_157 , V_165 [ 0 ] , V_167 | V_168 , & V_95 -> V_158 ) ;
if ( V_8 ) {
V_157 -> error = L_46 ;
F_160 ( V_95 ) ;
return - V_36 ;
}
V_8 = F_167 ( V_157 , V_165 [ 1 ] , V_167 | V_168 , & V_95 -> V_127 ) ;
if ( V_8 ) {
V_157 -> error = L_47 ;
F_160 ( V_95 ) ;
return - V_36 ;
}
V_8 = sscanf ( V_165 [ 2 ] , L_48 , & V_95 -> V_125 , & V_166 ) ;
if ( V_8 != 1 ) {
V_157 -> error = L_49 ;
F_160 ( V_95 ) ;
return - V_36 ;
}
V_8 = F_168 ( V_157 , V_95 -> V_125 ) ;
if ( V_8 ) {
V_157 -> error = L_50 ;
F_160 ( V_95 ) ;
return - V_36 ;
}
if ( ! F_165 ( V_95 -> V_125 ) ) {
V_157 -> error = L_51 ;
F_160 ( V_95 ) ;
return - V_36 ;
}
if ( V_95 -> V_125 & ( V_95 -> V_125 - 1 ) )
V_95 -> V_120 = - 1 ;
else
V_95 -> V_120 = F_169 ( V_95 -> V_125 ) ;
V_11 = F_86 ( V_95 -> V_158 -> V_89 , V_95 -> V_125 , true ) ;
if ( F_70 ( V_11 ) ) {
V_157 -> error = L_52 ;
F_160 ( V_95 ) ;
return F_71 ( V_11 ) ;
}
V_95 -> V_11 = V_11 ;
V_95 -> V_10 = F_163 ( V_95 ) ;
V_8 = F_92 ( V_95 -> V_11 , & V_95 -> V_10 ) ;
if ( V_8 ) {
V_157 -> error = L_53 ;
F_160 ( V_95 ) ;
return - V_14 ;
}
V_95 -> V_129 = F_170 ( L_54 V_169 , V_170 ) ;
if ( ! V_95 -> V_129 ) {
V_157 -> error = L_55 ;
F_160 ( V_95 ) ;
return - V_14 ;
}
F_171 ( & V_95 -> V_130 , F_142 ) ;
F_172 ( & V_95 -> V_136 ) ;
F_128 ( & V_95 -> V_132 ) ;
F_172 ( & V_95 -> V_142 ) ;
F_137 ( & V_95 -> V_143 ) ;
V_157 -> V_171 = V_95 ;
V_157 -> V_172 = 1 ;
V_157 -> V_173 = true ;
V_157 -> V_174 = 1 ;
V_157 -> V_175 = true ;
V_95 -> V_156 . V_176 = F_159 ;
F_173 ( V_157 -> V_177 , & V_95 -> V_156 ) ;
return 0 ;
}
static void F_174 ( struct V_163 * V_157 )
{
F_160 ( V_157 -> V_171 ) ;
}
static int F_175 ( struct V_163 * V_157 , struct V_121 * V_121 )
{
struct V_95 * V_95 = V_157 -> V_171 ;
T_1 V_15 = F_120 ( V_95 , V_121 ) ;
F_122 ( V_95 , V_121 ) ;
if ( ! ( V_121 -> V_178 & V_179 ) &&
( F_176 ( V_121 ) == V_180 ) &&
! F_100 ( V_95 -> V_11 , V_15 ) ) {
F_144 ( V_95 , V_121 ) ;
return V_181 ;
}
return V_182 ;
}
static void F_177 ( struct V_163 * V_157 )
{
int V_8 ;
struct V_95 * V_95 = V_157 -> V_171 ;
V_8 = F_149 ( V_95 , F_94 ) ;
if ( V_8 ) {
F_10 ( L_56 , V_13 ) ;
}
F_154 ( V_95 ) ;
}
static int F_178 ( struct V_163 * V_157 )
{
int V_8 ;
struct V_95 * V_95 = V_157 -> V_171 ;
T_1 V_108 = F_163 ( V_95 ) ;
if ( V_95 -> V_10 != V_108 ) {
V_8 = F_151 ( V_95 , F_92 , & V_108 ) ;
if ( V_8 )
return V_8 ;
V_95 -> V_10 = V_108 ;
}
F_152 ( V_95 ) ;
V_8 = F_149 ( V_95 , F_98 ) ;
if ( V_8 ) {
F_10 ( L_57 , V_13 ) ;
return V_8 ;
}
return 0 ;
}
static void F_179 ( struct V_163 * V_157 , T_7 type ,
unsigned V_183 , char * V_18 , unsigned V_184 )
{
int V_8 ;
struct V_95 * V_95 = V_157 -> V_171 ;
T_8 V_185 = 0 ;
struct V_113 V_186 ;
char V_187 [ V_188 ] ;
switch ( type ) {
case V_189 :
V_8 = F_151 ( V_95 , F_116 , & V_186 ) ;
if ( V_8 )
goto V_190;
F_180 ( L_58 ,
( unsigned ) ( V_80 >> V_81 ) ,
( unsigned long long ) V_186 . V_117 ,
( unsigned long long ) V_186 . V_118 ,
( unsigned ) V_186 . V_95 ) ;
if ( V_186 . V_119 != V_45 )
F_180 ( L_59 , V_186 . V_119 ) ;
else
F_180 ( L_60 ) ;
break;
case V_191 :
F_181 ( V_187 , V_95 -> V_158 -> V_89 -> V_192 ) ;
F_180 ( L_61 , V_187 ) ;
F_181 ( V_187 , V_95 -> V_127 -> V_89 -> V_192 ) ;
F_180 ( L_62 , V_187 , V_95 -> V_125 ) ;
break;
}
return;
V_190:
F_180 ( L_63 ) ;
}
static int F_182 ( struct V_163 * V_157 , unsigned V_164 , char * * V_165 )
{
struct V_95 * V_95 = V_157 -> V_171 ;
if ( V_164 != 1 ) {
F_10 ( L_64 ) ;
return - V_36 ;
}
if ( ! strcasecmp ( V_165 [ 0 ] , L_65 ) )
return F_149 ( V_95 , F_106 ) ;
if ( ! strcasecmp ( V_165 [ 0 ] , L_66 ) )
return F_149 ( V_95 , F_107 ) ;
if ( ! strcasecmp ( V_165 [ 0 ] , L_67 ) )
return F_149 ( V_95 , F_112 ) ;
F_10 ( L_68 , V_165 [ 0 ] ) ;
return - V_36 ;
}
static T_6 F_183 ( struct V_148 * V_149 )
{
return F_184 ( V_149 -> V_89 -> V_193 ) >> V_81 ;
}
static int F_185 ( struct V_163 * V_157 ,
T_9 F_150 , void * V_194 )
{
struct V_95 * V_95 = V_157 -> V_171 ;
return F_150 ( V_157 , V_95 -> V_127 , 0 , F_183 ( V_95 -> V_127 ) , V_194 ) ;
}
static void F_186 ( struct V_163 * V_157 , struct V_195 * V_196 )
{
struct V_95 * V_95 = V_157 -> V_171 ;
T_5 V_197 = V_196 -> V_198 >> V_81 ;
if ( V_197 < V_95 -> V_125 ||
F_187 ( V_197 , V_95 -> V_125 ) ) {
F_188 ( V_196 , 0 ) ;
F_189 ( V_196 , V_95 -> V_125 << V_81 ) ;
}
}
static int T_10 F_190 ( void )
{
int V_8 ;
V_8 = F_191 ( & V_199 ) ;
if ( V_8 ) {
F_10 ( L_69 , V_8 ) ;
return V_8 ;
}
return 0 ;
}
static void T_11 F_192 ( void )
{
F_193 ( & V_199 ) ;
}
