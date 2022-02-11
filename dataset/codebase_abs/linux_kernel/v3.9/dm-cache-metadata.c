static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
V_7 -> V_8 = F_3 ( F_4 ( V_4 ) ) ;
V_7 -> V_9 = F_5 ( F_6 ( & V_7 -> V_10 ,
V_5 - sizeof( V_11 ) ,
V_12 ) ) ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
V_11 V_13 ;
if ( F_4 ( V_4 ) != F_8 ( V_7 -> V_8 ) ) {
F_9 ( L_1 ,
F_8 ( V_7 -> V_8 ) ,
( unsigned long long ) F_4 ( V_4 ) ) ;
return - V_14 ;
}
if ( F_8 ( V_7 -> V_15 ) != V_16 ) {
F_9 ( L_2 ,
F_8 ( V_7 -> V_15 ) ,
( unsigned long long ) V_16 ) ;
return - V_17 ;
}
V_13 = F_5 ( F_6 ( & V_7 -> V_10 ,
V_5 - sizeof( V_11 ) ,
V_12 ) ) ;
if ( V_13 != V_7 -> V_9 ) {
F_9 ( L_3 ,
F_10 ( V_13 ) , F_10 ( V_7 -> V_9 ) ) ;
return - V_17 ;
}
return 0 ;
}
static int F_11 ( struct V_18 * V_19 ,
struct V_3 * * V_20 )
{
return F_12 ( V_19 -> V_21 , V_22 ,
& V_23 , V_20 ) ;
}
static int F_13 ( struct V_18 * V_19 ,
struct V_3 * * V_20 )
{
return F_14 ( V_19 -> V_21 , V_22 ,
& V_23 , V_20 ) ;
}
static int F_15 ( struct V_18 * V_19 ,
struct V_3 * * V_20 )
{
return F_16 ( V_19 -> V_21 , V_22 ,
& V_23 , V_20 ) ;
}
static int F_17 ( struct V_24 * V_21 , int * V_25 )
{
int V_26 ;
unsigned V_27 ;
struct V_3 * V_4 ;
T_2 * V_28 , V_29 = F_3 ( 0 ) ;
unsigned V_5 = F_18 ( V_21 ) / sizeof( T_2 ) ;
V_26 = F_12 ( V_21 , V_22 , NULL , & V_4 ) ;
if ( V_26 )
return V_26 ;
V_28 = F_2 ( V_4 ) ;
* V_25 = 1 ;
for ( V_27 = 0 ; V_27 < V_5 ; V_27 ++ ) {
if ( V_28 [ V_27 ] != V_29 ) {
* V_25 = 0 ;
break;
}
}
return F_19 ( V_4 ) ;
}
static void F_20 ( struct V_18 * V_19 )
{
struct V_30 V_31 ;
V_31 . V_32 = NULL ;
V_31 . V_33 = sizeof( T_2 ) ;
V_31 . V_34 = NULL ;
V_31 . V_35 = NULL ;
V_31 . V_36 = NULL ;
F_21 ( & V_19 -> V_37 , V_19 -> V_38 , & V_31 ) ;
if ( V_19 -> V_39 ) {
V_31 . V_33 = sizeof( V_11 ) ;
F_21 ( & V_19 -> V_40 , V_19 -> V_38 , & V_31 ) ;
}
}
static int F_22 ( struct V_18 * V_19 )
{
int V_26 ;
struct V_3 * V_20 ;
T_1 V_41 ;
struct V_6 * V_7 ;
T_3 V_42 = F_23 ( V_19 -> V_43 -> V_44 ) >> V_45 ;
if ( V_42 > V_46 )
V_42 = V_46 ;
V_26 = F_24 ( V_19 -> V_47 , & V_41 ) ;
if ( V_26 < 0 )
return V_26 ;
V_26 = F_25 ( V_19 -> V_38 ) ;
if ( V_26 < 0 )
return V_26 ;
V_26 = F_13 ( V_19 , & V_20 ) ;
if ( V_26 )
return V_26 ;
V_7 = F_2 ( V_20 ) ;
V_7 -> V_10 = 0 ;
memset ( V_7 -> V_48 , 0 , sizeof( V_7 -> V_48 ) ) ;
V_7 -> V_15 = F_3 ( V_16 ) ;
V_7 -> V_49 = F_5 ( V_50 ) ;
memset ( V_7 -> V_51 , 0 , sizeof( V_7 -> V_51 ) ) ;
memset ( V_7 -> V_52 , 0 , sizeof( V_7 -> V_52 ) ) ;
V_7 -> V_39 = 0 ;
V_26 = F_26 ( V_19 -> V_47 , & V_7 -> V_53 ,
V_41 ) ;
if ( V_26 < 0 )
goto V_54;
V_7 -> V_55 = F_3 ( V_19 -> V_56 ) ;
V_7 -> V_57 = F_3 ( V_19 -> V_57 ) ;
V_7 -> V_58 = F_3 ( V_19 -> V_58 ) ;
V_7 -> V_59 = F_3 ( V_19 -> V_59 ) ;
V_7 -> V_60 = F_3 ( F_27 ( V_19 -> V_60 ) ) ;
V_7 -> V_61 = F_5 ( V_62 >> V_45 ) ;
V_7 -> V_63 = F_5 ( V_19 -> V_63 ) ;
V_7 -> V_64 = F_5 ( 0 ) ;
V_7 -> V_65 = F_5 ( 0 ) ;
V_7 -> V_66 = F_5 ( 0 ) ;
V_7 -> V_67 = F_5 ( 0 ) ;
V_7 -> V_68 = F_5 ( 0 ) ;
return F_28 ( V_19 -> V_38 , V_20 ) ;
V_54:
F_19 ( V_20 ) ;
return V_26 ;
}
static int F_29 ( struct V_18 * V_19 )
{
int V_26 ;
V_26 = F_30 ( V_19 -> V_21 , V_22 ,
& V_19 -> V_38 , & V_19 -> V_47 ) ;
if ( V_26 < 0 ) {
F_9 ( L_4 ) ;
return V_26 ;
}
F_20 ( V_19 ) ;
V_26 = F_31 ( & V_19 -> V_37 , & V_19 -> V_56 ) ;
if ( V_26 < 0 )
goto V_69;
F_32 ( V_19 -> V_38 , & V_19 -> V_70 ) ;
V_26 = F_33 ( & V_19 -> V_70 , & V_19 -> V_58 ) ;
if ( V_26 < 0 )
goto V_69;
V_19 -> V_59 = 0 ;
V_19 -> V_60 = 0 ;
V_26 = F_22 ( V_19 ) ;
if ( V_26 )
goto V_69;
V_19 -> V_71 = true ;
return 0 ;
V_69:
F_34 ( V_19 -> V_38 ) ;
F_35 ( V_19 -> V_47 ) ;
return V_26 ;
}
static int F_36 ( struct V_6 * V_7 ,
struct V_18 * V_19 )
{
T_4 V_72 ;
V_72 = F_10 ( V_7 -> V_73 ) & ~ V_74 ;
if ( V_72 ) {
F_9 ( L_5 ,
( unsigned long ) V_72 ) ;
return - V_75 ;
}
if ( F_37 ( V_19 -> V_43 -> V_76 ) )
return 0 ;
V_72 = F_10 ( V_7 -> V_77 ) & ~ V_78 ;
if ( V_72 ) {
F_9 ( L_6 ,
( unsigned long ) V_72 ) ;
return - V_75 ;
}
return 0 ;
}
static int F_38 ( struct V_18 * V_19 )
{
int V_26 ;
struct V_3 * V_20 ;
struct V_6 * V_7 ;
unsigned long V_79 ;
V_26 = F_11 ( V_19 , & V_20 ) ;
if ( V_26 < 0 ) {
F_9 ( L_7 ) ;
return V_26 ;
}
V_7 = F_2 ( V_20 ) ;
V_26 = F_36 ( V_7 , V_19 ) ;
if ( V_26 < 0 )
goto V_69;
V_26 = F_39 ( V_19 -> V_21 , V_22 ,
V_7 -> V_53 ,
sizeof( V_7 -> V_53 ) ,
& V_19 -> V_38 , & V_19 -> V_47 ) ;
if ( V_26 < 0 ) {
F_9 ( L_8 ) ;
goto V_69;
}
F_20 ( V_19 ) ;
F_32 ( V_19 -> V_38 , & V_19 -> V_70 ) ;
V_79 = F_10 ( V_7 -> V_10 ) ;
V_19 -> V_71 = F_40 ( V_80 , & V_79 ) ;
return F_19 ( V_20 ) ;
V_69:
F_19 ( V_20 ) ;
return V_26 ;
}
static int F_41 ( struct V_18 * V_19 ,
bool V_81 )
{
int V_26 , V_82 ;
V_26 = F_17 ( V_19 -> V_21 , & V_82 ) ;
if ( V_26 )
return V_26 ;
if ( V_82 )
return V_81 ? F_29 ( V_19 ) : - V_83 ;
return F_38 ( V_19 ) ;
}
static int F_42 ( struct V_18 * V_19 ,
bool V_84 )
{
int V_26 ;
V_19 -> V_21 = F_43 ( V_19 -> V_43 , V_62 ,
V_85 ,
V_86 ) ;
if ( F_44 ( V_19 -> V_21 ) ) {
F_9 ( L_9 ) ;
return F_45 ( V_19 -> V_21 ) ;
}
V_26 = F_41 ( V_19 , V_84 ) ;
if ( V_26 )
F_46 ( V_19 -> V_21 ) ;
return V_26 ;
}
static void F_47 ( struct V_18 * V_19 )
{
F_35 ( V_19 -> V_47 ) ;
F_34 ( V_19 -> V_38 ) ;
F_46 ( V_19 -> V_21 ) ;
}
static void F_48 ( struct V_6 * V_7 ,
T_5 V_87 )
{
T_4 V_79 = V_87 ( F_10 ( V_7 -> V_10 ) ) ;
V_7 -> V_10 = F_5 ( V_79 ) ;
}
static unsigned long F_49 ( unsigned long V_10 )
{
F_50 ( V_80 , & V_10 ) ;
return V_10 ;
}
static unsigned long F_51 ( unsigned long V_10 )
{
F_52 ( V_80 , & V_10 ) ;
return V_10 ;
}
static void F_53 ( struct V_18 * V_19 ,
struct V_6 * V_7 )
{
V_19 -> V_56 = F_8 ( V_7 -> V_55 ) ;
V_19 -> V_57 = F_8 ( V_7 -> V_57 ) ;
V_19 -> V_58 = F_8 ( V_7 -> V_58 ) ;
V_19 -> V_59 = F_8 ( V_7 -> V_59 ) ;
V_19 -> V_60 = F_54 ( F_8 ( V_7 -> V_60 ) ) ;
V_19 -> V_63 = F_10 ( V_7 -> V_63 ) ;
V_19 -> V_64 = F_55 ( F_10 ( V_7 -> V_64 ) ) ;
strncpy ( V_19 -> V_51 , V_7 -> V_51 , sizeof( V_19 -> V_51 ) ) ;
V_19 -> V_52 [ 0 ] = F_10 ( V_7 -> V_52 [ 0 ] ) ;
V_19 -> V_52 [ 1 ] = F_10 ( V_7 -> V_52 [ 1 ] ) ;
V_19 -> V_52 [ 2 ] = F_10 ( V_7 -> V_52 [ 2 ] ) ;
V_19 -> V_39 = F_10 ( V_7 -> V_39 ) ;
V_19 -> V_88 . V_65 = F_10 ( V_7 -> V_65 ) ;
V_19 -> V_88 . V_66 = F_10 ( V_7 -> V_66 ) ;
V_19 -> V_88 . V_67 = F_10 ( V_7 -> V_67 ) ;
V_19 -> V_88 . V_68 = F_10 ( V_7 -> V_68 ) ;
V_19 -> V_89 = false ;
}
static int F_56 ( struct V_18 * V_19 ,
T_5 V_87 )
{
int V_26 ;
struct V_6 * V_7 ;
struct V_3 * V_20 ;
V_26 = F_15 ( V_19 , & V_20 ) ;
if ( V_26 )
return V_26 ;
V_7 = F_2 ( V_20 ) ;
F_48 ( V_7 , V_87 ) ;
F_53 ( V_19 , V_7 ) ;
return F_57 ( V_19 -> V_21 , V_20 ) ;
}
static int F_58 ( struct V_18 * V_19 )
{
int V_26 ;
struct V_6 * V_7 ;
struct V_3 * V_20 ;
V_26 = F_11 ( V_19 , & V_20 ) ;
if ( V_26 )
return V_26 ;
V_7 = F_2 ( V_20 ) ;
F_53 ( V_19 , V_7 ) ;
F_19 ( V_20 ) ;
return 0 ;
}
static int F_59 ( struct V_18 * V_19 ,
T_5 V_87 )
{
int V_26 ;
T_1 V_41 ;
struct V_6 * V_7 ;
struct V_3 * V_20 ;
F_60 ( sizeof( struct V_6 ) > 512 ) ;
V_26 = F_61 ( & V_19 -> V_70 , V_19 -> V_58 ,
& V_19 -> V_58 ) ;
if ( V_26 )
return V_26 ;
V_26 = F_25 ( V_19 -> V_38 ) ;
if ( V_26 < 0 )
return V_26 ;
V_26 = F_24 ( V_19 -> V_47 , & V_41 ) ;
if ( V_26 < 0 )
return V_26 ;
V_26 = F_15 ( V_19 , & V_20 ) ;
if ( V_26 )
return V_26 ;
V_7 = F_2 ( V_20 ) ;
if ( V_87 )
F_48 ( V_7 , V_87 ) ;
V_7 -> V_55 = F_3 ( V_19 -> V_56 ) ;
V_7 -> V_57 = F_3 ( V_19 -> V_57 ) ;
V_7 -> V_58 = F_3 ( V_19 -> V_58 ) ;
V_7 -> V_59 = F_3 ( V_19 -> V_59 ) ;
V_7 -> V_60 = F_3 ( F_27 ( V_19 -> V_60 ) ) ;
V_7 -> V_64 = F_5 ( F_62 ( V_19 -> V_64 ) ) ;
strncpy ( V_7 -> V_51 , V_19 -> V_51 , sizeof( V_7 -> V_51 ) ) ;
V_7 -> V_52 [ 0 ] = F_5 ( V_19 -> V_52 [ 0 ] ) ;
V_7 -> V_52 [ 1 ] = F_5 ( V_19 -> V_52 [ 1 ] ) ;
V_7 -> V_52 [ 2 ] = F_5 ( V_19 -> V_52 [ 2 ] ) ;
V_7 -> V_65 = F_5 ( V_19 -> V_88 . V_65 ) ;
V_7 -> V_66 = F_5 ( V_19 -> V_88 . V_66 ) ;
V_7 -> V_67 = F_5 ( V_19 -> V_88 . V_67 ) ;
V_7 -> V_68 = F_5 ( V_19 -> V_88 . V_68 ) ;
V_26 = F_26 ( V_19 -> V_47 , & V_7 -> V_53 ,
V_41 ) ;
if ( V_26 < 0 ) {
F_19 ( V_20 ) ;
return V_26 ;
}
return F_28 ( V_19 -> V_38 , V_20 ) ;
}
static T_2 F_63 ( T_6 V_90 , unsigned V_10 )
{
T_7 V_91 = F_64 ( V_90 ) ;
V_91 <<= 16 ;
V_91 = V_91 | ( V_10 & V_92 ) ;
return F_3 ( V_91 ) ;
}
static void F_65 ( T_2 V_93 , T_6 * V_90 , unsigned * V_10 )
{
T_7 V_91 = F_8 ( V_93 ) ;
T_7 V_4 = V_91 >> 16 ;
* V_90 = F_66 ( V_4 ) ;
* V_10 = V_91 & V_92 ;
}
struct V_18 * F_67 ( struct V_94 * V_43 ,
T_3 V_63 ,
bool V_84 ,
T_1 V_39 )
{
int V_26 ;
struct V_18 * V_19 ;
V_19 = F_68 ( sizeof( * V_19 ) , V_95 ) ;
if ( ! V_19 ) {
F_9 ( L_10 ) ;
return NULL ;
}
F_69 ( & V_19 -> V_96 ) ;
V_19 -> V_43 = V_43 ;
V_19 -> V_63 = V_63 ;
V_19 -> V_64 = 0 ;
V_19 -> V_39 = V_39 ;
V_19 -> V_89 = true ;
V_26 = F_42 ( V_19 , V_84 ) ;
if ( V_26 ) {
F_70 ( V_19 ) ;
return F_71 ( V_26 ) ;
}
V_26 = F_56 ( V_19 , F_51 ) ;
if ( V_26 < 0 ) {
F_72 ( V_19 ) ;
return F_71 ( V_26 ) ;
}
return V_19 ;
}
void F_72 ( struct V_18 * V_19 )
{
F_47 ( V_19 ) ;
F_70 ( V_19 ) ;
}
int F_73 ( struct V_18 * V_19 , T_8 V_97 )
{
int V_26 ;
T_2 V_98 = F_63 ( 0 , 0 ) ;
F_74 ( & V_19 -> V_96 ) ;
F_75 ( & V_98 ) ;
V_26 = F_76 ( & V_19 -> V_37 , V_19 -> V_56 , F_62 ( V_19 -> V_64 ) ,
F_62 ( V_97 ) ,
& V_98 , & V_19 -> V_56 ) ;
if ( ! V_26 )
V_19 -> V_64 = V_97 ;
V_19 -> V_89 = true ;
F_77 ( & V_19 -> V_96 ) ;
return V_26 ;
}
int F_78 ( struct V_18 * V_19 ,
T_3 V_59 ,
T_9 V_99 )
{
int V_26 ;
F_74 ( & V_19 -> V_96 ) ;
V_26 = F_79 ( & V_19 -> V_70 ,
V_19 -> V_58 ,
F_27 ( V_19 -> V_60 ) ,
F_27 ( V_99 ) ,
false , & V_19 -> V_58 ) ;
if ( ! V_26 ) {
V_19 -> V_59 = V_59 ;
V_19 -> V_60 = V_99 ;
}
V_19 -> V_89 = true ;
F_77 ( & V_19 -> V_96 ) ;
return V_26 ;
}
static int F_80 ( struct V_18 * V_19 , T_9 V_4 )
{
return F_81 ( & V_19 -> V_70 , V_19 -> V_58 ,
F_27 ( V_4 ) , & V_19 -> V_58 ) ;
}
static int F_82 ( struct V_18 * V_19 , T_9 V_4 )
{
return F_83 ( & V_19 -> V_70 , V_19 -> V_58 ,
F_27 ( V_4 ) , & V_19 -> V_58 ) ;
}
static int F_84 ( struct V_18 * V_19 , T_9 V_4 ,
bool * V_100 )
{
return F_85 ( & V_19 -> V_70 , V_19 -> V_58 ,
F_27 ( V_4 ) , & V_19 -> V_58 ,
V_100 ) ;
}
static int F_86 ( struct V_18 * V_19 ,
T_9 V_101 , bool V_102 )
{
int V_26 ;
V_26 = ( V_102 ? F_80 : F_82 ) ( V_19 , V_101 ) ;
if ( V_26 )
return V_26 ;
V_19 -> V_89 = true ;
return 0 ;
}
int F_87 ( struct V_18 * V_19 ,
T_9 V_101 , bool V_102 )
{
int V_26 ;
F_74 ( & V_19 -> V_96 ) ;
V_26 = F_86 ( V_19 , V_101 , V_102 ) ;
F_77 ( & V_19 -> V_96 ) ;
return V_26 ;
}
static int F_88 ( struct V_18 * V_19 ,
T_10 V_103 , void * V_32 )
{
int V_26 = 0 ;
T_11 V_4 ;
bool V_102 ;
for ( V_4 = 0 ; V_4 < F_27 ( V_19 -> V_60 ) ; V_4 ++ ) {
T_9 V_101 = F_54 ( V_4 ) ;
if ( V_19 -> V_71 ) {
V_26 = F_84 ( V_19 , V_101 , & V_102 ) ;
if ( V_26 )
return V_26 ;
} else
V_102 = false ;
V_26 = V_103 ( V_32 , V_19 -> V_59 , V_101 , V_102 ) ;
if ( V_26 )
break;
}
return V_26 ;
}
int F_89 ( struct V_18 * V_19 ,
T_10 V_103 , void * V_32 )
{
int V_26 ;
F_90 ( & V_19 -> V_96 ) ;
V_26 = F_88 ( V_19 , V_103 , V_32 ) ;
F_91 ( & V_19 -> V_96 ) ;
return V_26 ;
}
T_8 F_92 ( struct V_18 * V_19 )
{
T_8 V_26 ;
F_90 ( & V_19 -> V_96 ) ;
V_26 = V_19 -> V_64 ;
F_91 ( & V_19 -> V_96 ) ;
return V_26 ;
}
static int F_93 ( struct V_18 * V_19 , T_8 V_104 )
{
int V_26 ;
T_2 V_91 = F_63 ( 0 , 0 ) ;
F_75 ( & V_91 ) ;
V_26 = F_94 ( & V_19 -> V_37 , V_19 -> V_56 , F_62 ( V_104 ) ,
& V_91 , & V_19 -> V_56 ) ;
if ( V_26 )
return V_26 ;
V_19 -> V_89 = true ;
return 0 ;
}
int F_95 ( struct V_18 * V_19 , T_8 V_104 )
{
int V_26 ;
F_74 ( & V_19 -> V_96 ) ;
V_26 = F_93 ( V_19 , V_104 ) ;
F_77 ( & V_19 -> V_96 ) ;
return V_26 ;
}
static int F_96 ( struct V_18 * V_19 ,
T_8 V_104 , T_6 V_105 )
{
int V_26 ;
T_2 V_91 = F_63 ( V_105 , V_106 ) ;
F_75 ( & V_91 ) ;
V_26 = F_94 ( & V_19 -> V_37 , V_19 -> V_56 , F_62 ( V_104 ) ,
& V_91 , & V_19 -> V_56 ) ;
if ( V_26 )
return V_26 ;
V_19 -> V_89 = true ;
return 0 ;
}
int F_97 ( struct V_18 * V_19 ,
T_8 V_104 , T_6 V_105 )
{
int V_26 ;
F_74 ( & V_19 -> V_96 ) ;
V_26 = F_96 ( V_19 , V_104 , V_105 ) ;
F_77 ( & V_19 -> V_96 ) ;
return V_26 ;
}
static bool F_98 ( struct V_18 * V_19 ,
struct V_107 * V_108 )
{
const char * V_51 = F_99 ( V_108 ) ;
const unsigned * V_52 = F_100 ( V_108 ) ;
T_1 V_39 = F_101 ( V_108 ) ;
if ( strncmp ( V_19 -> V_51 , V_51 , sizeof( V_19 -> V_51 ) ) )
return false ;
if ( V_19 -> V_52 [ 0 ] != V_52 [ 0 ] )
return false ;
if ( V_19 -> V_39 != V_39 )
return false ;
return true ;
}
static bool F_102 ( struct V_18 * V_19 )
{
return V_19 -> V_57 && V_19 -> V_39 ;
}
static bool F_103 ( struct V_18 * V_19 ,
struct V_107 * V_108 )
{
return V_19 -> V_71 && F_98 ( V_19 , V_108 ) &&
F_102 ( V_19 ) ;
}
static int F_104 ( void * V_32 , T_7 V_104 , void * V_109 )
{
int V_26 = 0 ;
bool V_110 ;
T_2 V_91 ;
V_11 V_111 = 0 ;
T_6 V_105 ;
unsigned V_10 ;
struct V_112 * V_112 = V_32 ;
struct V_18 * V_19 = V_112 -> V_19 ;
memcpy ( & V_91 , V_109 , sizeof( V_91 ) ) ;
F_65 ( V_91 , & V_105 , & V_10 ) ;
if ( V_10 & V_106 ) {
if ( V_112 -> V_113 ) {
V_26 = F_105 ( & V_19 -> V_40 , V_19 -> V_57 ,
V_104 , & V_111 ) ;
if ( V_26 && V_26 != - V_114 )
return V_26 ;
}
V_110 = V_112 -> V_115 ? ( V_10 & V_116 ) : true ;
V_26 = V_112 -> V_103 ( V_112 -> V_32 , V_105 , F_55 ( V_104 ) ,
V_110 , F_10 ( V_111 ) , V_112 -> V_113 ) ;
}
return V_26 ;
}
static int F_106 ( struct V_18 * V_19 ,
struct V_107 * V_108 ,
T_12 V_103 , void * V_32 )
{
struct V_112 V_112 ;
V_112 . V_103 = V_103 ;
V_112 . V_32 = V_32 ;
V_112 . V_19 = V_19 ;
V_112 . V_115 = V_19 -> V_71 ;
V_112 . V_113 = F_103 ( V_19 , V_108 ) ;
return F_107 ( & V_19 -> V_37 , V_19 -> V_56 , F_104 , & V_112 ) ;
}
int F_108 ( struct V_18 * V_19 ,
struct V_107 * V_108 ,
T_12 V_103 , void * V_32 )
{
int V_26 ;
F_90 ( & V_19 -> V_96 ) ;
V_26 = F_106 ( V_19 , V_108 , V_103 , V_32 ) ;
F_91 ( & V_19 -> V_96 ) ;
return V_26 ;
}
static int F_109 ( void * V_32 , T_7 V_104 , void * V_109 )
{
int V_26 = 0 ;
T_2 V_91 ;
T_6 V_105 ;
unsigned V_10 ;
memcpy ( & V_91 , V_109 , sizeof( V_91 ) ) ;
F_65 ( V_91 , & V_105 , & V_10 ) ;
return V_26 ;
}
static int F_110 ( struct V_18 * V_19 )
{
return F_107 ( & V_19 -> V_37 , V_19 -> V_56 , F_109 , NULL ) ;
}
void F_111 ( struct V_18 * V_19 )
{
F_90 ( & V_19 -> V_96 ) ;
F_110 ( V_19 ) ;
F_91 ( & V_19 -> V_96 ) ;
}
int F_112 ( struct V_18 * V_19 )
{
int V_26 ;
F_90 ( & V_19 -> V_96 ) ;
V_26 = V_19 -> V_89 ;
F_91 ( & V_19 -> V_96 ) ;
return V_26 ;
}
static int F_113 ( struct V_18 * V_19 , T_8 V_104 , bool V_110 )
{
int V_26 ;
unsigned V_10 ;
T_6 V_105 ;
T_2 V_91 ;
V_26 = F_105 ( & V_19 -> V_37 , V_19 -> V_56 , F_62 ( V_104 ) , & V_91 ) ;
if ( V_26 )
return V_26 ;
F_65 ( V_91 , & V_105 , & V_10 ) ;
if ( ( ( V_10 & V_116 ) && V_110 ) || ( ! ( V_10 & V_116 ) && ! V_110 ) )
return 0 ;
V_91 = F_63 ( V_105 , ( V_10 & ~ V_116 ) | ( V_110 ? V_116 : 0 ) ) ;
F_75 ( & V_91 ) ;
V_26 = F_94 ( & V_19 -> V_37 , V_19 -> V_56 , F_62 ( V_104 ) ,
& V_91 , & V_19 -> V_56 ) ;
if ( V_26 )
return V_26 ;
V_19 -> V_89 = true ;
return 0 ;
}
int F_114 ( struct V_18 * V_19 ,
T_8 V_104 , bool V_110 )
{
int V_26 ;
F_74 ( & V_19 -> V_96 ) ;
V_26 = F_113 ( V_19 , V_104 , V_110 ) ;
F_77 ( & V_19 -> V_96 ) ;
return V_26 ;
}
void F_115 ( struct V_18 * V_19 ,
struct V_117 * V_88 )
{
F_90 ( & V_19 -> V_96 ) ;
memcpy ( V_88 , & V_19 -> V_88 , sizeof( * V_88 ) ) ;
F_91 ( & V_19 -> V_96 ) ;
}
void F_116 ( struct V_18 * V_19 ,
struct V_117 * V_88 )
{
F_74 ( & V_19 -> V_96 ) ;
memcpy ( & V_19 -> V_88 , V_88 , sizeof( * V_88 ) ) ;
F_77 ( & V_19 -> V_96 ) ;
}
int F_117 ( struct V_18 * V_19 , bool V_118 )
{
int V_26 ;
T_5 V_87 = ( V_118 ? F_49 :
F_51 ) ;
F_74 ( & V_19 -> V_96 ) ;
V_26 = F_59 ( V_19 , V_87 ) ;
if ( V_26 )
goto V_119;
V_26 = F_58 ( V_19 ) ;
V_119:
F_77 ( & V_19 -> V_96 ) ;
return V_26 ;
}
int F_118 ( struct V_18 * V_19 ,
T_11 * V_25 )
{
int V_26 = - V_75 ;
F_90 ( & V_19 -> V_96 ) ;
V_26 = F_119 ( V_19 -> V_47 , V_25 ) ;
F_91 ( & V_19 -> V_96 ) ;
return V_26 ;
}
int F_120 ( struct V_18 * V_19 ,
T_11 * V_25 )
{
int V_26 = - V_75 ;
F_90 ( & V_19 -> V_96 ) ;
V_26 = F_121 ( V_19 -> V_47 , V_25 ) ;
F_91 ( & V_19 -> V_96 ) ;
return V_26 ;
}
static int F_122 ( struct V_18 * V_19 , struct V_107 * V_108 )
{
int V_26 ;
V_11 V_91 ;
T_1 V_120 ;
const char * V_51 = F_99 ( V_108 ) ;
const unsigned * V_52 = F_100 ( V_108 ) ;
if ( ! V_51 [ 0 ] ||
( strlen ( V_51 ) > sizeof( V_19 -> V_51 ) - 1 ) )
return - V_75 ;
if ( ! F_98 ( V_19 , V_108 ) ) {
strncpy ( V_19 -> V_51 , V_51 , sizeof( V_19 -> V_51 ) ) ;
memcpy ( V_19 -> V_52 , V_52 , sizeof( V_19 -> V_52 ) ) ;
V_120 = F_101 ( V_108 ) ;
if ( ! V_120 )
return 0 ;
V_19 -> V_39 = V_120 ;
if ( V_19 -> V_57 ) {
V_26 = F_123 ( & V_19 -> V_40 , V_19 -> V_57 ) ;
if ( V_26 )
return V_26 ;
}
V_26 = F_31 ( & V_19 -> V_40 , & V_19 -> V_57 ) ;
if ( V_26 )
return V_26 ;
V_91 = F_5 ( 0 ) ;
F_75 ( & V_91 ) ;
V_26 = F_76 ( & V_19 -> V_40 , V_19 -> V_57 , 0 ,
F_62 ( V_19 -> V_64 ) ,
& V_91 , & V_19 -> V_57 ) ;
if ( V_26 )
return V_26 ;
}
return 0 ;
}
int F_124 ( struct V_18 * V_19 , struct V_107 * V_108 )
{
int V_26 ;
F_74 ( & V_19 -> V_96 ) ;
V_26 = F_122 ( V_19 , V_108 ) ;
F_77 ( & V_19 -> V_96 ) ;
return V_26 ;
}
static int F_125 ( struct V_18 * V_19 , T_8 V_104 ,
T_4 V_121 )
{
int V_26 ;
V_11 V_91 = F_5 ( V_121 ) ;
F_75 ( & V_91 ) ;
V_26 = F_94 ( & V_19 -> V_40 , V_19 -> V_57 ,
F_62 ( V_104 ) , & V_91 , & V_19 -> V_57 ) ;
V_19 -> V_89 = true ;
return V_26 ;
}
int F_126 ( struct V_18 * V_19 , T_8 V_104 ,
T_4 V_121 )
{
int V_26 ;
if ( ! F_102 ( V_19 ) )
return 0 ;
F_74 ( & V_19 -> V_96 ) ;
V_26 = F_125 ( V_19 , V_104 , V_121 ) ;
F_77 ( & V_19 -> V_96 ) ;
return V_26 ;
}
