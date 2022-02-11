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
static int F_7 ( struct V_6 * V_7 )
{
T_2 V_13 = F_8 ( V_7 -> V_14 ) ;
if ( V_13 < V_15 || V_13 > V_16 ) {
F_9 ( L_1 ,
V_13 , V_15 , V_16 ) ;
return - V_17 ;
}
return 0 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
V_11 V_18 ;
if ( F_4 ( V_4 ) != F_11 ( V_7 -> V_8 ) ) {
F_9 ( L_2 ,
F_11 ( V_7 -> V_8 ) ,
( unsigned long long ) F_4 ( V_4 ) ) ;
return - V_19 ;
}
if ( F_11 ( V_7 -> V_20 ) != V_21 ) {
F_9 ( L_3 ,
F_11 ( V_7 -> V_20 ) ,
( unsigned long long ) V_21 ) ;
return - V_22 ;
}
V_18 = F_5 ( F_6 ( & V_7 -> V_10 ,
V_5 - sizeof( V_11 ) ,
V_12 ) ) ;
if ( V_18 != V_7 -> V_9 ) {
F_9 ( L_4 ,
F_8 ( V_18 ) , F_8 ( V_7 -> V_9 ) ) ;
return - V_22 ;
}
return F_7 ( V_7 ) ;
}
static int F_12 ( struct V_23 * V_24 ,
struct V_3 * * V_25 )
{
return F_13 ( V_24 -> V_26 , V_27 ,
& V_28 , V_25 ) ;
}
static int F_14 ( struct V_23 * V_24 ,
struct V_3 * * V_25 )
{
return F_15 ( V_24 -> V_26 , V_27 ,
& V_28 , V_25 ) ;
}
static int F_16 ( struct V_23 * V_24 ,
struct V_3 * * V_25 )
{
return F_17 ( V_24 -> V_26 , V_27 ,
& V_28 , V_25 ) ;
}
static int F_18 ( struct V_29 * V_26 , bool * V_30 )
{
int V_31 ;
unsigned V_32 ;
struct V_3 * V_4 ;
T_3 * V_33 , V_34 = F_3 ( 0 ) ;
unsigned V_5 = F_19 ( V_26 ) / sizeof( T_3 ) ;
V_31 = F_13 ( V_26 , V_27 , NULL , & V_4 ) ;
if ( V_31 )
return V_31 ;
V_33 = F_2 ( V_4 ) ;
* V_30 = true ;
for ( V_32 = 0 ; V_32 < V_5 ; V_32 ++ ) {
if ( V_33 [ V_32 ] != V_34 ) {
* V_30 = false ;
break;
}
}
return F_20 ( V_4 ) ;
}
static void F_21 ( struct V_23 * V_24 )
{
struct V_35 V_36 ;
V_36 . V_37 = NULL ;
V_36 . V_38 = sizeof( T_3 ) ;
V_36 . V_39 = NULL ;
V_36 . V_40 = NULL ;
V_36 . V_41 = NULL ;
F_22 ( & V_24 -> V_42 , V_24 -> V_43 , & V_36 ) ;
if ( V_24 -> V_44 ) {
V_36 . V_38 = sizeof( V_11 ) ;
F_22 ( & V_24 -> V_45 , V_24 -> V_43 , & V_36 ) ;
}
}
static int F_23 ( struct V_23 * V_24 )
{
int V_31 ;
struct V_3 * V_25 ;
T_1 V_46 ;
struct V_6 * V_7 ;
T_4 V_47 = F_24 ( V_24 -> V_48 -> V_49 ) >> V_50 ;
if ( V_47 > V_51 )
V_47 = V_51 ;
V_31 = F_25 ( V_24 -> V_52 , & V_46 ) ;
if ( V_31 < 0 )
return V_31 ;
V_31 = F_26 ( V_24 -> V_43 ) ;
if ( V_31 < 0 )
return V_31 ;
V_31 = F_14 ( V_24 , & V_25 ) ;
if ( V_31 )
return V_31 ;
V_7 = F_2 ( V_25 ) ;
V_7 -> V_10 = 0 ;
memset ( V_7 -> V_53 , 0 , sizeof( V_7 -> V_53 ) ) ;
V_7 -> V_20 = F_3 ( V_21 ) ;
V_7 -> V_14 = F_5 ( V_16 ) ;
memset ( V_7 -> V_54 , 0 , sizeof( V_7 -> V_54 ) ) ;
memset ( V_7 -> V_55 , 0 , sizeof( V_7 -> V_55 ) ) ;
V_7 -> V_44 = 0 ;
V_31 = F_27 ( V_24 -> V_52 , & V_7 -> V_56 ,
V_46 ) ;
if ( V_31 < 0 )
goto V_57;
V_7 -> V_58 = F_3 ( V_24 -> V_59 ) ;
V_7 -> V_60 = F_3 ( V_24 -> V_60 ) ;
V_7 -> V_61 = F_3 ( V_24 -> V_61 ) ;
V_7 -> V_62 = F_3 ( V_24 -> V_62 ) ;
V_7 -> V_63 = F_3 ( F_28 ( V_24 -> V_63 ) ) ;
V_7 -> V_64 = F_5 ( V_65 >> V_50 ) ;
V_7 -> V_66 = F_5 ( V_24 -> V_66 ) ;
V_7 -> V_67 = F_5 ( 0 ) ;
V_7 -> V_68 = F_5 ( 0 ) ;
V_7 -> V_69 = F_5 ( 0 ) ;
V_7 -> V_70 = F_5 ( 0 ) ;
V_7 -> V_71 = F_5 ( 0 ) ;
return F_29 ( V_24 -> V_43 , V_25 ) ;
V_57:
F_20 ( V_25 ) ;
return V_31 ;
}
static int F_30 ( struct V_23 * V_24 )
{
int V_31 ;
V_31 = F_31 ( V_24 -> V_26 , V_27 ,
& V_24 -> V_43 , & V_24 -> V_52 ) ;
if ( V_31 < 0 ) {
F_9 ( L_5 ) ;
return V_31 ;
}
F_21 ( V_24 ) ;
V_31 = F_32 ( & V_24 -> V_42 , & V_24 -> V_59 ) ;
if ( V_31 < 0 )
goto V_72;
F_33 ( V_24 -> V_43 , & V_24 -> V_73 ) ;
V_31 = F_34 ( & V_24 -> V_73 , & V_24 -> V_61 ) ;
if ( V_31 < 0 )
goto V_72;
V_24 -> V_62 = 0 ;
V_24 -> V_63 = 0 ;
V_31 = F_23 ( V_24 ) ;
if ( V_31 )
goto V_72;
V_24 -> V_74 = true ;
return 0 ;
V_72:
F_35 ( V_24 -> V_43 ) ;
F_36 ( V_24 -> V_52 ) ;
return V_31 ;
}
static int F_37 ( struct V_6 * V_7 ,
struct V_23 * V_24 )
{
T_2 V_75 ;
V_75 = F_8 ( V_7 -> V_76 ) & ~ V_77 ;
if ( V_75 ) {
F_9 ( L_6 ,
( unsigned long ) V_75 ) ;
return - V_17 ;
}
if ( F_38 ( V_24 -> V_48 -> V_78 ) )
return 0 ;
V_75 = F_8 ( V_7 -> V_79 ) & ~ V_80 ;
if ( V_75 ) {
F_9 ( L_7 ,
( unsigned long ) V_75 ) ;
return - V_17 ;
}
return 0 ;
}
static int F_39 ( struct V_23 * V_24 )
{
int V_31 ;
struct V_3 * V_25 ;
struct V_6 * V_7 ;
unsigned long V_81 ;
V_31 = F_12 ( V_24 , & V_25 ) ;
if ( V_31 < 0 ) {
F_9 ( L_8 ) ;
return V_31 ;
}
V_7 = F_2 ( V_25 ) ;
V_31 = F_37 ( V_7 , V_24 ) ;
if ( V_31 < 0 )
goto V_72;
V_31 = F_40 ( V_24 -> V_26 , V_27 ,
V_7 -> V_56 ,
sizeof( V_7 -> V_56 ) ,
& V_24 -> V_43 , & V_24 -> V_52 ) ;
if ( V_31 < 0 ) {
F_9 ( L_9 ) ;
goto V_72;
}
F_21 ( V_24 ) ;
F_33 ( V_24 -> V_43 , & V_24 -> V_73 ) ;
V_81 = F_8 ( V_7 -> V_10 ) ;
V_24 -> V_74 = F_41 ( V_82 , & V_81 ) ;
return F_20 ( V_25 ) ;
V_72:
F_20 ( V_25 ) ;
return V_31 ;
}
static int F_42 ( struct V_23 * V_24 ,
bool V_83 )
{
int V_31 ;
bool V_84 = false ;
V_31 = F_18 ( V_24 -> V_26 , & V_84 ) ;
if ( V_31 )
return V_31 ;
if ( V_84 )
return V_83 ? F_30 ( V_24 ) : - V_85 ;
return F_39 ( V_24 ) ;
}
static int F_43 ( struct V_23 * V_24 ,
bool V_86 )
{
int V_31 ;
V_24 -> V_26 = F_44 ( V_24 -> V_48 , V_65 ,
V_87 ,
V_88 ) ;
if ( F_45 ( V_24 -> V_26 ) ) {
F_9 ( L_10 ) ;
return F_46 ( V_24 -> V_26 ) ;
}
V_31 = F_42 ( V_24 , V_86 ) ;
if ( V_31 )
F_47 ( V_24 -> V_26 ) ;
return V_31 ;
}
static void F_48 ( struct V_23 * V_24 )
{
F_36 ( V_24 -> V_52 ) ;
F_35 ( V_24 -> V_43 ) ;
F_47 ( V_24 -> V_26 ) ;
}
static void F_49 ( struct V_6 * V_7 ,
T_5 V_89 )
{
T_2 V_81 = V_89 ( F_8 ( V_7 -> V_10 ) ) ;
V_7 -> V_10 = F_5 ( V_81 ) ;
}
static unsigned long F_50 ( unsigned long V_10 )
{
F_51 ( V_82 , & V_10 ) ;
return V_10 ;
}
static unsigned long F_52 ( unsigned long V_10 )
{
F_53 ( V_82 , & V_10 ) ;
return V_10 ;
}
static void F_54 ( struct V_23 * V_24 ,
struct V_6 * V_7 )
{
V_24 -> V_59 = F_11 ( V_7 -> V_58 ) ;
V_24 -> V_60 = F_11 ( V_7 -> V_60 ) ;
V_24 -> V_61 = F_11 ( V_7 -> V_61 ) ;
V_24 -> V_62 = F_11 ( V_7 -> V_62 ) ;
V_24 -> V_63 = F_55 ( F_11 ( V_7 -> V_63 ) ) ;
V_24 -> V_66 = F_8 ( V_7 -> V_66 ) ;
V_24 -> V_67 = F_56 ( F_8 ( V_7 -> V_67 ) ) ;
strncpy ( V_24 -> V_54 , V_7 -> V_54 , sizeof( V_24 -> V_54 ) ) ;
V_24 -> V_55 [ 0 ] = F_8 ( V_7 -> V_55 [ 0 ] ) ;
V_24 -> V_55 [ 1 ] = F_8 ( V_7 -> V_55 [ 1 ] ) ;
V_24 -> V_55 [ 2 ] = F_8 ( V_7 -> V_55 [ 2 ] ) ;
V_24 -> V_44 = F_8 ( V_7 -> V_44 ) ;
V_24 -> V_90 . V_68 = F_8 ( V_7 -> V_68 ) ;
V_24 -> V_90 . V_69 = F_8 ( V_7 -> V_69 ) ;
V_24 -> V_90 . V_70 = F_8 ( V_7 -> V_70 ) ;
V_24 -> V_90 . V_71 = F_8 ( V_7 -> V_71 ) ;
V_24 -> V_91 = false ;
}
static int F_57 ( struct V_23 * V_24 ,
T_5 V_89 )
{
int V_31 ;
struct V_6 * V_7 ;
struct V_3 * V_25 ;
V_31 = F_16 ( V_24 , & V_25 ) ;
if ( V_31 )
return V_31 ;
V_7 = F_2 ( V_25 ) ;
F_49 ( V_7 , V_89 ) ;
F_54 ( V_24 , V_7 ) ;
return F_58 ( V_24 -> V_26 , V_25 ) ;
}
static int F_59 ( struct V_23 * V_24 )
{
int V_31 ;
struct V_6 * V_7 ;
struct V_3 * V_25 ;
V_31 = F_12 ( V_24 , & V_25 ) ;
if ( V_31 )
return V_31 ;
V_7 = F_2 ( V_25 ) ;
F_54 ( V_24 , V_7 ) ;
F_20 ( V_25 ) ;
return 0 ;
}
static int F_60 ( struct V_23 * V_24 ,
T_5 V_89 )
{
int V_31 ;
T_1 V_46 ;
struct V_6 * V_7 ;
struct V_3 * V_25 ;
F_61 ( sizeof( struct V_6 ) > 512 ) ;
V_31 = F_62 ( & V_24 -> V_73 , V_24 -> V_61 ,
& V_24 -> V_61 ) ;
if ( V_31 )
return V_31 ;
V_31 = F_26 ( V_24 -> V_43 ) ;
if ( V_31 < 0 )
return V_31 ;
V_31 = F_25 ( V_24 -> V_52 , & V_46 ) ;
if ( V_31 < 0 )
return V_31 ;
V_31 = F_16 ( V_24 , & V_25 ) ;
if ( V_31 )
return V_31 ;
V_7 = F_2 ( V_25 ) ;
if ( V_89 )
F_49 ( V_7 , V_89 ) ;
V_7 -> V_58 = F_3 ( V_24 -> V_59 ) ;
V_7 -> V_60 = F_3 ( V_24 -> V_60 ) ;
V_7 -> V_61 = F_3 ( V_24 -> V_61 ) ;
V_7 -> V_62 = F_3 ( V_24 -> V_62 ) ;
V_7 -> V_63 = F_3 ( F_28 ( V_24 -> V_63 ) ) ;
V_7 -> V_67 = F_5 ( F_63 ( V_24 -> V_67 ) ) ;
strncpy ( V_7 -> V_54 , V_24 -> V_54 , sizeof( V_7 -> V_54 ) ) ;
V_7 -> V_55 [ 0 ] = F_5 ( V_24 -> V_55 [ 0 ] ) ;
V_7 -> V_55 [ 1 ] = F_5 ( V_24 -> V_55 [ 1 ] ) ;
V_7 -> V_55 [ 2 ] = F_5 ( V_24 -> V_55 [ 2 ] ) ;
V_7 -> V_68 = F_5 ( V_24 -> V_90 . V_68 ) ;
V_7 -> V_69 = F_5 ( V_24 -> V_90 . V_69 ) ;
V_7 -> V_70 = F_5 ( V_24 -> V_90 . V_70 ) ;
V_7 -> V_71 = F_5 ( V_24 -> V_90 . V_71 ) ;
V_31 = F_27 ( V_24 -> V_52 , & V_7 -> V_56 ,
V_46 ) ;
if ( V_31 < 0 ) {
F_20 ( V_25 ) ;
return V_31 ;
}
return F_29 ( V_24 -> V_43 , V_25 ) ;
}
static T_3 F_64 ( T_6 V_92 , unsigned V_10 )
{
T_7 V_93 = F_65 ( V_92 ) ;
V_93 <<= 16 ;
V_93 = V_93 | ( V_10 & V_94 ) ;
return F_3 ( V_93 ) ;
}
static void F_66 ( T_3 V_95 , T_6 * V_92 , unsigned * V_10 )
{
T_7 V_93 = F_11 ( V_95 ) ;
T_7 V_4 = V_93 >> 16 ;
* V_92 = F_67 ( V_4 ) ;
* V_10 = V_93 & V_94 ;
}
struct V_23 * F_68 ( struct V_96 * V_48 ,
T_4 V_66 ,
bool V_86 ,
T_1 V_44 )
{
int V_31 ;
struct V_23 * V_24 ;
V_24 = F_69 ( sizeof( * V_24 ) , V_97 ) ;
if ( ! V_24 ) {
F_9 ( L_11 ) ;
return NULL ;
}
F_70 ( & V_24 -> V_98 ) ;
V_24 -> V_48 = V_48 ;
V_24 -> V_66 = V_66 ;
V_24 -> V_67 = 0 ;
V_24 -> V_44 = V_44 ;
V_24 -> V_91 = true ;
V_31 = F_43 ( V_24 , V_86 ) ;
if ( V_31 ) {
F_71 ( V_24 ) ;
return F_72 ( V_31 ) ;
}
V_31 = F_57 ( V_24 , F_52 ) ;
if ( V_31 < 0 ) {
F_73 ( V_24 ) ;
return F_72 ( V_31 ) ;
}
return V_24 ;
}
void F_73 ( struct V_23 * V_24 )
{
F_48 ( V_24 ) ;
F_71 ( V_24 ) ;
}
static int F_74 ( struct V_23 * V_24 , T_8 V_4 ,
bool * V_30 )
{
int V_31 ;
T_3 V_93 ;
T_6 V_99 ;
unsigned V_10 ;
V_31 = F_75 ( & V_24 -> V_42 , V_24 -> V_59 , F_63 ( V_4 ) , & V_93 ) ;
if ( V_31 ) {
F_9 ( L_12 ) ;
return V_31 ;
}
F_66 ( V_93 , & V_99 , & V_10 ) ;
* V_30 = ! ( ( V_10 & V_100 ) && ( V_10 & V_101 ) ) ;
return 0 ;
}
static int F_76 ( struct V_23 * V_24 ,
T_8 V_102 , T_8 V_103 ,
bool * V_30 )
{
int V_31 ;
* V_30 = true ;
while ( V_102 != V_103 ) {
V_31 = F_74 ( V_24 , V_102 , V_30 ) ;
if ( V_31 )
return V_31 ;
if ( ! * V_30 ) {
F_9 ( L_13 ,
( unsigned long long ) F_63 ( V_102 ) ) ;
return 0 ;
}
V_102 = F_56 ( F_63 ( V_102 ) + 1 ) ;
}
return 0 ;
}
int F_77 ( struct V_23 * V_24 , T_8 V_104 )
{
int V_31 ;
bool V_105 ;
T_3 V_106 = F_64 ( 0 , 0 ) ;
F_78 ( & V_24 -> V_98 ) ;
F_79 ( & V_106 ) ;
if ( F_63 ( V_104 ) < F_63 ( V_24 -> V_67 ) ) {
V_31 = F_76 ( V_24 , V_104 , V_24 -> V_67 , & V_105 ) ;
if ( V_31 ) {
F_80 ( & V_106 ) ;
goto V_107;
}
if ( ! V_105 ) {
F_9 ( L_14 ) ;
V_31 = - V_17 ;
F_80 ( & V_106 ) ;
goto V_107;
}
}
V_31 = F_81 ( & V_24 -> V_42 , V_24 -> V_59 , F_63 ( V_24 -> V_67 ) ,
F_63 ( V_104 ) ,
& V_106 , & V_24 -> V_59 ) ;
if ( ! V_31 )
V_24 -> V_67 = V_104 ;
V_24 -> V_91 = true ;
V_107:
F_82 ( & V_24 -> V_98 ) ;
return V_31 ;
}
int F_83 ( struct V_23 * V_24 ,
T_4 V_62 ,
T_9 V_108 )
{
int V_31 ;
F_78 ( & V_24 -> V_98 ) ;
V_31 = F_84 ( & V_24 -> V_73 ,
V_24 -> V_61 ,
F_28 ( V_24 -> V_63 ) ,
F_28 ( V_108 ) ,
false , & V_24 -> V_61 ) ;
if ( ! V_31 ) {
V_24 -> V_62 = V_62 ;
V_24 -> V_63 = V_108 ;
}
V_24 -> V_91 = true ;
F_82 ( & V_24 -> V_98 ) ;
return V_31 ;
}
static int F_85 ( struct V_23 * V_24 , T_9 V_4 )
{
return F_86 ( & V_24 -> V_73 , V_24 -> V_61 ,
F_28 ( V_4 ) , & V_24 -> V_61 ) ;
}
static int F_87 ( struct V_23 * V_24 , T_9 V_4 )
{
return F_88 ( & V_24 -> V_73 , V_24 -> V_61 ,
F_28 ( V_4 ) , & V_24 -> V_61 ) ;
}
static int F_89 ( struct V_23 * V_24 , T_9 V_4 ,
bool * V_109 )
{
return F_90 ( & V_24 -> V_73 , V_24 -> V_61 ,
F_28 ( V_4 ) , & V_24 -> V_61 ,
V_109 ) ;
}
static int F_91 ( struct V_23 * V_24 ,
T_9 V_110 , bool V_111 )
{
int V_31 ;
V_31 = ( V_111 ? F_85 : F_87 ) ( V_24 , V_110 ) ;
if ( V_31 )
return V_31 ;
V_24 -> V_91 = true ;
return 0 ;
}
int F_92 ( struct V_23 * V_24 ,
T_9 V_110 , bool V_111 )
{
int V_31 ;
F_78 ( & V_24 -> V_98 ) ;
V_31 = F_91 ( V_24 , V_110 , V_111 ) ;
F_82 ( & V_24 -> V_98 ) ;
return V_31 ;
}
static int F_93 ( struct V_23 * V_24 ,
T_10 V_112 , void * V_37 )
{
int V_31 = 0 ;
T_11 V_4 ;
bool V_111 ;
for ( V_4 = 0 ; V_4 < F_28 ( V_24 -> V_63 ) ; V_4 ++ ) {
T_9 V_110 = F_55 ( V_4 ) ;
if ( V_24 -> V_74 ) {
V_31 = F_89 ( V_24 , V_110 , & V_111 ) ;
if ( V_31 )
return V_31 ;
} else
V_111 = false ;
V_31 = V_112 ( V_37 , V_24 -> V_62 , V_110 , V_111 ) ;
if ( V_31 )
break;
}
return V_31 ;
}
int F_94 ( struct V_23 * V_24 ,
T_10 V_112 , void * V_37 )
{
int V_31 ;
F_95 ( & V_24 -> V_98 ) ;
V_31 = F_93 ( V_24 , V_112 , V_37 ) ;
F_96 ( & V_24 -> V_98 ) ;
return V_31 ;
}
T_8 F_97 ( struct V_23 * V_24 )
{
T_8 V_31 ;
F_95 ( & V_24 -> V_98 ) ;
V_31 = V_24 -> V_67 ;
F_96 ( & V_24 -> V_98 ) ;
return V_31 ;
}
static int F_98 ( struct V_23 * V_24 , T_8 V_113 )
{
int V_31 ;
T_3 V_93 = F_64 ( 0 , 0 ) ;
F_79 ( & V_93 ) ;
V_31 = F_99 ( & V_24 -> V_42 , V_24 -> V_59 , F_63 ( V_113 ) ,
& V_93 , & V_24 -> V_59 ) ;
if ( V_31 )
return V_31 ;
V_24 -> V_91 = true ;
return 0 ;
}
int F_100 ( struct V_23 * V_24 , T_8 V_113 )
{
int V_31 ;
F_78 ( & V_24 -> V_98 ) ;
V_31 = F_98 ( V_24 , V_113 ) ;
F_82 ( & V_24 -> V_98 ) ;
return V_31 ;
}
static int F_101 ( struct V_23 * V_24 ,
T_8 V_113 , T_6 V_114 )
{
int V_31 ;
T_3 V_93 = F_64 ( V_114 , V_100 ) ;
F_79 ( & V_93 ) ;
V_31 = F_99 ( & V_24 -> V_42 , V_24 -> V_59 , F_63 ( V_113 ) ,
& V_93 , & V_24 -> V_59 ) ;
if ( V_31 )
return V_31 ;
V_24 -> V_91 = true ;
return 0 ;
}
int F_102 ( struct V_23 * V_24 ,
T_8 V_113 , T_6 V_114 )
{
int V_31 ;
F_78 ( & V_24 -> V_98 ) ;
V_31 = F_101 ( V_24 , V_113 , V_114 ) ;
F_82 ( & V_24 -> V_98 ) ;
return V_31 ;
}
static bool F_103 ( struct V_23 * V_24 ,
struct V_115 * V_116 )
{
const char * V_54 = F_104 ( V_116 ) ;
const unsigned * V_55 = F_105 ( V_116 ) ;
T_1 V_44 = F_106 ( V_116 ) ;
if ( strncmp ( V_24 -> V_54 , V_54 , sizeof( V_24 -> V_54 ) ) )
return false ;
if ( V_24 -> V_55 [ 0 ] != V_55 [ 0 ] )
return false ;
if ( V_24 -> V_44 != V_44 )
return false ;
return true ;
}
static bool F_107 ( struct V_23 * V_24 )
{
return V_24 -> V_60 && V_24 -> V_44 ;
}
static bool F_108 ( struct V_23 * V_24 ,
struct V_115 * V_116 )
{
return V_24 -> V_74 && F_103 ( V_24 , V_116 ) &&
F_107 ( V_24 ) ;
}
static int F_109 ( void * V_37 , T_7 V_113 , void * V_117 )
{
int V_31 = 0 ;
bool V_118 ;
T_3 V_93 ;
V_11 V_119 = 0 ;
T_6 V_114 ;
unsigned V_10 ;
struct V_120 * V_120 = V_37 ;
struct V_23 * V_24 = V_120 -> V_24 ;
memcpy ( & V_93 , V_117 , sizeof( V_93 ) ) ;
F_66 ( V_93 , & V_114 , & V_10 ) ;
if ( V_10 & V_100 ) {
if ( V_120 -> V_121 ) {
V_31 = F_75 ( & V_24 -> V_45 , V_24 -> V_60 ,
V_113 , & V_119 ) ;
if ( V_31 && V_31 != - V_122 )
return V_31 ;
}
V_118 = V_120 -> V_123 ? ( V_10 & V_101 ) : true ;
V_31 = V_120 -> V_112 ( V_120 -> V_37 , V_114 , F_56 ( V_113 ) ,
V_118 , F_8 ( V_119 ) , V_120 -> V_121 ) ;
}
return V_31 ;
}
static int F_110 ( struct V_23 * V_24 ,
struct V_115 * V_116 ,
T_12 V_112 , void * V_37 )
{
struct V_120 V_120 ;
V_120 . V_112 = V_112 ;
V_120 . V_37 = V_37 ;
V_120 . V_24 = V_24 ;
V_120 . V_123 = V_24 -> V_74 ;
V_120 . V_121 = F_108 ( V_24 , V_116 ) ;
return F_111 ( & V_24 -> V_42 , V_24 -> V_59 , F_109 , & V_120 ) ;
}
int F_112 ( struct V_23 * V_24 ,
struct V_115 * V_116 ,
T_12 V_112 , void * V_37 )
{
int V_31 ;
F_95 ( & V_24 -> V_98 ) ;
V_31 = F_110 ( V_24 , V_116 , V_112 , V_37 ) ;
F_96 ( & V_24 -> V_98 ) ;
return V_31 ;
}
static int F_113 ( void * V_37 , T_7 V_113 , void * V_117 )
{
int V_31 = 0 ;
T_3 V_93 ;
T_6 V_114 ;
unsigned V_10 ;
memcpy ( & V_93 , V_117 , sizeof( V_93 ) ) ;
F_66 ( V_93 , & V_114 , & V_10 ) ;
return V_31 ;
}
static int F_114 ( struct V_23 * V_24 )
{
return F_111 ( & V_24 -> V_42 , V_24 -> V_59 , F_113 , NULL ) ;
}
void F_115 ( struct V_23 * V_24 )
{
F_95 ( & V_24 -> V_98 ) ;
F_114 ( V_24 ) ;
F_96 ( & V_24 -> V_98 ) ;
}
int F_116 ( struct V_23 * V_24 )
{
int V_31 ;
F_95 ( & V_24 -> V_98 ) ;
V_31 = V_24 -> V_91 ;
F_96 ( & V_24 -> V_98 ) ;
return V_31 ;
}
static int F_117 ( struct V_23 * V_24 , T_8 V_113 , bool V_118 )
{
int V_31 ;
unsigned V_10 ;
T_6 V_114 ;
T_3 V_93 ;
V_31 = F_75 ( & V_24 -> V_42 , V_24 -> V_59 , F_63 ( V_113 ) , & V_93 ) ;
if ( V_31 )
return V_31 ;
F_66 ( V_93 , & V_114 , & V_10 ) ;
if ( ( ( V_10 & V_101 ) && V_118 ) || ( ! ( V_10 & V_101 ) && ! V_118 ) )
return 0 ;
V_93 = F_64 ( V_114 , ( V_10 & ~ V_101 ) | ( V_118 ? V_101 : 0 ) ) ;
F_79 ( & V_93 ) ;
V_31 = F_99 ( & V_24 -> V_42 , V_24 -> V_59 , F_63 ( V_113 ) ,
& V_93 , & V_24 -> V_59 ) ;
if ( V_31 )
return V_31 ;
V_24 -> V_91 = true ;
return 0 ;
}
int F_118 ( struct V_23 * V_24 ,
T_8 V_113 , bool V_118 )
{
int V_31 ;
F_78 ( & V_24 -> V_98 ) ;
V_31 = F_117 ( V_24 , V_113 , V_118 ) ;
F_82 ( & V_24 -> V_98 ) ;
return V_31 ;
}
void F_119 ( struct V_23 * V_24 ,
struct V_124 * V_90 )
{
F_95 ( & V_24 -> V_98 ) ;
* V_90 = V_24 -> V_90 ;
F_96 ( & V_24 -> V_98 ) ;
}
void F_120 ( struct V_23 * V_24 ,
struct V_124 * V_90 )
{
F_78 ( & V_24 -> V_98 ) ;
V_24 -> V_90 = * V_90 ;
F_82 ( & V_24 -> V_98 ) ;
}
int F_121 ( struct V_23 * V_24 , bool V_125 )
{
int V_31 ;
T_5 V_89 = ( V_125 ? F_50 :
F_52 ) ;
F_78 ( & V_24 -> V_98 ) ;
V_31 = F_60 ( V_24 , V_89 ) ;
if ( V_31 )
goto V_107;
V_31 = F_59 ( V_24 ) ;
V_107:
F_82 ( & V_24 -> V_98 ) ;
return V_31 ;
}
int F_122 ( struct V_23 * V_24 ,
T_11 * V_30 )
{
int V_31 = - V_17 ;
F_95 ( & V_24 -> V_98 ) ;
V_31 = F_123 ( V_24 -> V_52 , V_30 ) ;
F_96 ( & V_24 -> V_98 ) ;
return V_31 ;
}
int F_124 ( struct V_23 * V_24 ,
T_11 * V_30 )
{
int V_31 = - V_17 ;
F_95 ( & V_24 -> V_98 ) ;
V_31 = F_125 ( V_24 -> V_52 , V_30 ) ;
F_96 ( & V_24 -> V_98 ) ;
return V_31 ;
}
static int F_126 ( struct V_23 * V_24 , struct V_115 * V_116 )
{
int V_31 ;
V_11 V_93 ;
T_1 V_126 ;
const char * V_54 = F_104 ( V_116 ) ;
const unsigned * V_55 = F_105 ( V_116 ) ;
if ( ! V_54 [ 0 ] ||
( strlen ( V_54 ) > sizeof( V_24 -> V_54 ) - 1 ) )
return - V_17 ;
if ( ! F_103 ( V_24 , V_116 ) ) {
strncpy ( V_24 -> V_54 , V_54 , sizeof( V_24 -> V_54 ) ) ;
memcpy ( V_24 -> V_55 , V_55 , sizeof( V_24 -> V_55 ) ) ;
V_126 = F_106 ( V_116 ) ;
if ( ! V_126 )
return 0 ;
V_24 -> V_44 = V_126 ;
if ( V_24 -> V_60 ) {
V_31 = F_127 ( & V_24 -> V_45 , V_24 -> V_60 ) ;
if ( V_31 )
return V_31 ;
}
V_31 = F_32 ( & V_24 -> V_45 , & V_24 -> V_60 ) ;
if ( V_31 )
return V_31 ;
V_93 = F_5 ( 0 ) ;
F_79 ( & V_93 ) ;
V_31 = F_81 ( & V_24 -> V_45 , V_24 -> V_60 , 0 ,
F_63 ( V_24 -> V_67 ) ,
& V_93 , & V_24 -> V_60 ) ;
if ( V_31 )
return V_31 ;
}
return 0 ;
}
int F_128 ( struct V_23 * V_24 , struct V_115 * V_116 )
{
int V_31 ;
F_78 ( & V_24 -> V_98 ) ;
V_31 = F_126 ( V_24 , V_116 ) ;
F_82 ( & V_24 -> V_98 ) ;
return V_31 ;
}
static int F_129 ( struct V_23 * V_24 , T_8 V_113 ,
T_2 V_127 )
{
int V_31 ;
V_11 V_93 = F_5 ( V_127 ) ;
F_79 ( & V_93 ) ;
V_31 = F_99 ( & V_24 -> V_45 , V_24 -> V_60 ,
F_63 ( V_113 ) , & V_93 , & V_24 -> V_60 ) ;
V_24 -> V_91 = true ;
return V_31 ;
}
int F_130 ( struct V_23 * V_24 , T_8 V_113 ,
T_2 V_127 )
{
int V_31 ;
if ( ! F_107 ( V_24 ) )
return 0 ;
F_78 ( & V_24 -> V_98 ) ;
V_31 = F_129 ( V_24 , V_113 , V_127 ) ;
F_82 ( & V_24 -> V_98 ) ;
return V_31 ;
}
int F_131 ( struct V_23 * V_24 , bool * V_30 )
{
return F_76 ( V_24 , 0 , V_24 -> V_67 , V_30 ) ;
}
