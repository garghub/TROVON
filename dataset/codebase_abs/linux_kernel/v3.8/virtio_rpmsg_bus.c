static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , V_8 L_1 , V_7 -> V_9 . V_10 ) ;
}
static inline int F_3 ( const struct V_6 * V_7 ,
const struct V_11 * V_9 )
{
return strncmp ( V_9 -> V_10 , V_7 -> V_9 . V_10 , V_12 ) == 0 ;
}
static int F_4 ( struct V_1 * V_2 , struct V_13 * V_14 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_15 * V_16 = F_5 ( V_14 ) ;
const struct V_11 * V_17 = V_16 -> V_18 ;
unsigned int V_19 ;
for ( V_19 = 0 ; V_17 [ V_19 ] . V_10 [ 0 ] ; V_19 ++ )
if ( F_3 ( V_7 , & V_17 [ V_19 ] ) )
return 1 ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , struct V_20 * V_21 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return F_7 ( V_21 , L_2 V_8 ,
V_7 -> V_9 . V_10 ) ;
}
static void F_8 ( struct V_22 * V_22 )
{
struct V_23 * V_24 = F_9 ( V_22 , struct V_23 ,
V_25 ) ;
F_10 ( V_24 ) ;
}
static struct V_23 * F_11 ( struct V_26 * V_27 ,
struct V_6 * V_7 , T_2 V_28 ,
void * V_29 , T_3 V_30 )
{
int V_31 , V_32 , V_33 ;
struct V_23 * V_24 ;
struct V_1 * V_2 = V_7 ? & V_7 -> V_2 : & V_27 -> V_34 -> V_2 ;
if ( ! F_12 ( & V_27 -> V_35 , V_36 ) )
return NULL ;
V_24 = F_13 ( sizeof( * V_24 ) , V_36 ) ;
if ( ! V_24 ) {
F_14 ( V_2 , L_3 ) ;
return NULL ;
}
F_15 ( & V_24 -> V_25 ) ;
F_16 ( & V_24 -> V_37 ) ;
V_24 -> V_7 = V_7 ;
V_24 -> V_28 = V_28 ;
V_24 -> V_29 = V_29 ;
V_33 = V_30 == V_38 ? V_39 : V_30 ;
F_17 ( & V_27 -> V_40 ) ;
V_31 = F_18 ( & V_27 -> V_35 , V_24 , V_33 , & V_32 ) ;
if ( V_31 ) {
F_14 ( V_2 , L_4 , V_31 ) ;
goto V_41;
}
if ( V_30 != V_38 && V_32 != V_30 ) {
F_14 ( V_2 , L_5 , V_30 ) ;
goto V_42;
}
V_24 -> V_30 = V_32 ;
F_19 ( & V_27 -> V_40 ) ;
return V_24 ;
V_42:
F_20 ( & V_27 -> V_35 , V_33 ) ;
V_41:
F_19 ( & V_27 -> V_40 ) ;
F_21 ( & V_24 -> V_25 , F_8 ) ;
return NULL ;
}
struct V_23 * F_22 ( struct V_6 * V_7 ,
T_2 V_28 , void * V_29 , T_3 V_30 )
{
return F_11 ( V_7 -> V_27 , V_7 , V_28 , V_29 , V_30 ) ;
}
static void
F_23 ( struct V_26 * V_27 , struct V_23 * V_24 )
{
F_17 ( & V_27 -> V_40 ) ;
F_20 ( & V_27 -> V_35 , V_24 -> V_30 ) ;
F_19 ( & V_27 -> V_40 ) ;
F_17 ( & V_24 -> V_37 ) ;
V_24 -> V_28 = NULL ;
F_19 ( & V_24 -> V_37 ) ;
F_21 ( & V_24 -> V_25 , F_8 ) ;
}
void F_24 ( struct V_23 * V_24 )
{
F_23 ( V_24 -> V_7 -> V_27 , V_24 ) ;
}
static int F_25 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_15 * V_16 = F_5 ( V_7 -> V_2 . V_43 ) ;
struct V_26 * V_27 = V_7 -> V_27 ;
struct V_23 * V_24 ;
int V_31 ;
V_24 = F_22 ( V_7 , V_16 -> V_44 , NULL , V_7 -> V_45 ) ;
if ( ! V_24 ) {
F_14 ( V_2 , L_6 ) ;
V_31 = - V_46 ;
goto V_47;
}
V_7 -> V_24 = V_24 ;
V_7 -> V_45 = V_24 -> V_30 ;
V_31 = V_16 -> V_48 ( V_7 ) ;
if ( V_31 ) {
F_14 ( V_2 , L_7 , V_49 , V_31 ) ;
F_24 ( V_24 ) ;
goto V_47;
}
if ( V_7 -> V_50 &&
F_26 ( V_27 -> V_34 , V_51 ) ) {
struct V_52 V_53 ;
strncpy ( V_53 . V_10 , V_7 -> V_9 . V_10 , V_12 ) ;
V_53 . V_30 = V_7 -> V_45 ;
V_53 . V_54 = V_55 ;
V_31 = F_27 ( V_7 , & V_53 , sizeof( V_53 ) , V_56 ) ;
if ( V_31 )
F_14 ( V_2 , L_8 , V_31 ) ;
}
V_47:
return V_31 ;
}
static int F_28 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_15 * V_16 = F_5 ( V_7 -> V_2 . V_43 ) ;
struct V_26 * V_27 = V_7 -> V_27 ;
int V_31 = 0 ;
if ( V_7 -> V_50 &&
F_26 ( V_27 -> V_34 , V_51 ) ) {
struct V_52 V_53 ;
strncpy ( V_53 . V_10 , V_7 -> V_9 . V_10 , V_12 ) ;
V_53 . V_30 = V_7 -> V_45 ;
V_53 . V_54 = V_57 ;
V_31 = F_27 ( V_7 , & V_53 , sizeof( V_53 ) , V_56 ) ;
if ( V_31 )
F_14 ( V_2 , L_8 , V_31 ) ;
}
V_16 -> remove ( V_7 ) ;
F_24 ( V_7 -> V_24 ) ;
return V_31 ;
}
int F_29 ( struct V_15 * V_16 )
{
V_16 -> V_14 . V_58 = & V_59 ;
return F_30 ( & V_16 -> V_14 ) ;
}
void F_31 ( struct V_15 * V_16 )
{
F_32 ( & V_16 -> V_14 ) ;
}
static void F_33 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_10 ( V_7 ) ;
}
static int F_34 ( struct V_1 * V_2 , void * V_60 )
{
struct V_61 * V_62 = V_60 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( V_62 -> V_45 != V_38 && V_62 -> V_45 != V_7 -> V_45 )
return 0 ;
if ( V_62 -> V_63 != V_38 && V_62 -> V_63 != V_7 -> V_63 )
return 0 ;
if ( strncmp ( V_62 -> V_10 , V_7 -> V_9 . V_10 , V_12 ) )
return 0 ;
return 1 ;
}
static struct V_6 * F_35 ( struct V_26 * V_27 ,
struct V_61 * V_62 )
{
struct V_6 * V_7 ;
struct V_1 * V_64 , * V_2 = & V_27 -> V_34 -> V_2 ;
int V_65 ;
V_64 = F_36 ( V_2 , V_62 , F_34 ) ;
if ( V_64 ) {
F_37 ( V_64 ) ;
F_14 ( V_2 , L_9 ,
V_62 -> V_10 , V_62 -> V_45 , V_62 -> V_63 ) ;
return NULL ;
}
V_7 = F_13 ( sizeof( struct V_6 ) , V_36 ) ;
if ( ! V_7 ) {
F_38 ( L_10 ) ;
return NULL ;
}
V_7 -> V_27 = V_27 ;
V_7 -> V_45 = V_62 -> V_45 ;
V_7 -> V_63 = V_62 -> V_63 ;
V_7 -> V_50 = V_7 -> V_45 != V_38 ? true : false ;
strncpy ( V_7 -> V_9 . V_10 , V_62 -> V_10 , V_12 ) ;
F_39 ( & V_7 -> V_2 , L_11 , V_66 ++ ) ;
V_7 -> V_2 . V_67 = & V_27 -> V_34 -> V_2 ;
V_7 -> V_2 . V_58 = & V_59 ;
V_7 -> V_2 . V_68 = F_33 ;
V_65 = F_40 ( & V_7 -> V_2 ) ;
if ( V_65 ) {
F_14 ( V_2 , L_12 , V_65 ) ;
F_37 ( & V_7 -> V_2 ) ;
return NULL ;
}
return V_7 ;
}
static int F_41 ( struct V_26 * V_27 ,
struct V_61 * V_62 )
{
struct V_69 * V_34 = V_27 -> V_34 ;
struct V_1 * V_2 ;
V_2 = F_36 ( & V_34 -> V_2 , V_62 , F_34 ) ;
if ( ! V_2 )
return - V_70 ;
F_42 ( V_2 ) ;
F_37 ( V_2 ) ;
return 0 ;
}
static void * F_43 ( struct V_26 * V_27 )
{
unsigned int V_71 ;
void * V_65 ;
F_17 ( & V_27 -> V_72 ) ;
if ( V_27 -> V_73 < V_74 / 2 )
V_65 = V_27 -> V_75 + V_76 * V_27 -> V_73 ++ ;
else
V_65 = F_44 ( V_27 -> V_77 , & V_71 ) ;
F_19 ( & V_27 -> V_72 ) ;
return V_65 ;
}
static void F_45 ( struct V_26 * V_27 )
{
F_17 ( & V_27 -> V_72 ) ;
if ( F_46 ( & V_27 -> V_78 ) == 1 )
F_47 ( V_27 -> V_77 ) ;
F_19 ( & V_27 -> V_72 ) ;
}
static void F_48 ( struct V_26 * V_27 )
{
F_17 ( & V_27 -> V_72 ) ;
if ( F_49 ( & V_27 -> V_78 ) )
F_50 ( V_27 -> V_77 ) ;
F_19 ( & V_27 -> V_72 ) ;
}
int F_51 ( struct V_6 * V_7 , T_3 V_45 , T_3 V_63 ,
void * V_60 , int V_71 , bool V_79 )
{
struct V_26 * V_27 = V_7 -> V_27 ;
struct V_1 * V_2 = & V_7 -> V_2 ;
struct V_80 V_81 ;
struct V_82 * V_83 ;
int V_31 ;
if ( V_45 == V_38 || V_63 == V_38 ) {
F_14 ( V_2 , L_13 , V_45 , V_63 ) ;
return - V_70 ;
}
if ( V_71 > V_76 - sizeof( struct V_82 ) ) {
F_14 ( V_2 , L_14 , V_71 ) ;
return - V_84 ;
}
V_83 = F_43 ( V_27 ) ;
if ( ! V_83 && ! V_79 )
return - V_46 ;
while ( ! V_83 ) {
F_45 ( V_27 ) ;
V_31 = F_52 ( V_27 -> V_85 ,
( V_83 = F_43 ( V_27 ) ) ,
F_53 ( 15000 ) ) ;
F_48 ( V_27 ) ;
if ( ! V_31 ) {
F_14 ( V_2 , L_15 ) ;
return - V_86 ;
}
}
V_83 -> V_71 = V_71 ;
V_83 -> V_54 = 0 ;
V_83 -> V_45 = V_45 ;
V_83 -> V_63 = V_63 ;
V_83 -> V_87 = 0 ;
memcpy ( V_83 -> V_60 , V_60 , V_71 ) ;
F_54 ( V_2 , L_16 ,
V_83 -> V_45 , V_83 -> V_63 , V_83 -> V_71 ,
V_83 -> V_54 , V_83 -> V_87 ) ;
F_55 ( V_88 , L_17 , V_89 , 16 , 1 ,
V_83 , sizeof( * V_83 ) + V_83 -> V_71 , true ) ;
F_56 ( & V_81 , V_83 , sizeof( * V_83 ) + V_71 ) ;
F_17 ( & V_27 -> V_72 ) ;
V_31 = F_57 ( V_27 -> V_77 , & V_81 , 1 , 0 , V_83 , V_36 ) ;
if ( V_31 ) {
F_14 ( V_2 , L_18 , V_31 ) ;
goto V_47;
}
F_58 ( V_27 -> V_77 ) ;
V_47:
F_19 ( & V_27 -> V_72 ) ;
return V_31 ;
}
static void F_59 ( struct V_90 * V_91 )
{
struct V_82 * V_83 ;
unsigned int V_71 ;
struct V_23 * V_24 ;
struct V_80 V_81 ;
struct V_26 * V_27 = V_91 -> V_34 -> V_29 ;
struct V_1 * V_2 = & V_91 -> V_34 -> V_2 ;
int V_31 ;
V_83 = F_44 ( V_91 , & V_71 ) ;
if ( ! V_83 ) {
F_14 ( V_2 , L_19 ) ;
return;
}
F_54 ( V_2 , L_20 ,
V_83 -> V_45 , V_83 -> V_63 , V_83 -> V_71 ,
V_83 -> V_54 , V_83 -> V_87 ) ;
F_55 ( V_88 , L_21 , V_89 , 16 , 1 ,
V_83 , sizeof( * V_83 ) + V_83 -> V_71 , true ) ;
if ( V_71 > V_76 ||
V_83 -> V_71 > ( V_71 - sizeof( struct V_82 ) ) ) {
F_60 ( V_2 , L_22 , V_71 , V_83 -> V_71 ) ;
return;
}
F_17 ( & V_27 -> V_40 ) ;
V_24 = F_61 ( & V_27 -> V_35 , V_83 -> V_63 ) ;
if ( V_24 )
F_62 ( & V_24 -> V_25 ) ;
F_19 ( & V_27 -> V_40 ) ;
if ( V_24 ) {
F_17 ( & V_24 -> V_37 ) ;
if ( V_24 -> V_28 )
V_24 -> V_28 ( V_24 -> V_7 , V_83 -> V_60 , V_83 -> V_71 , V_24 -> V_29 ,
V_83 -> V_45 ) ;
F_19 ( & V_24 -> V_37 ) ;
F_21 ( & V_24 -> V_25 , F_8 ) ;
} else
F_60 ( V_2 , L_23 ) ;
F_56 ( & V_81 , V_83 , V_76 ) ;
V_31 = F_57 ( V_27 -> V_91 , & V_81 , 0 , 1 , V_83 , V_36 ) ;
if ( V_31 < 0 ) {
F_14 ( V_2 , L_24 , V_31 ) ;
return;
}
F_58 ( V_27 -> V_91 ) ;
}
static void F_63 ( struct V_90 * V_77 )
{
struct V_26 * V_27 = V_77 -> V_34 -> V_29 ;
F_54 ( & V_77 -> V_34 -> V_2 , L_25 , V_49 ) ;
F_64 ( & V_27 -> V_85 ) ;
}
static void F_65 ( struct V_6 * V_7 , void * V_60 , int V_71 ,
void * V_29 , T_3 V_45 )
{
struct V_52 * V_83 = V_60 ;
struct V_6 * V_92 ;
struct V_61 V_62 ;
struct V_26 * V_27 = V_29 ;
struct V_1 * V_2 = & V_27 -> V_34 -> V_2 ;
int V_65 ;
F_55 ( V_88 , L_26 ,
V_89 , 16 , 1 ,
V_60 , V_71 , true ) ;
if ( V_71 != sizeof( * V_83 ) ) {
F_14 ( V_2 , L_27 , V_71 ) ;
return;
}
if ( V_7 ) {
F_14 ( V_2 , L_28 ) ;
return;
}
V_83 -> V_10 [ V_12 - 1 ] = '\0' ;
F_66 ( V_2 , L_29 ,
V_83 -> V_54 & V_57 ? L_30 : L_31 ,
V_83 -> V_10 , V_83 -> V_30 ) ;
strncpy ( V_62 . V_10 , V_83 -> V_10 , sizeof( V_62 . V_10 ) ) ;
V_62 . V_45 = V_38 ;
V_62 . V_63 = V_83 -> V_30 ;
if ( V_83 -> V_54 & V_57 ) {
V_65 = F_41 ( V_27 , & V_62 ) ;
if ( V_65 )
F_14 ( V_2 , L_32 , V_65 ) ;
} else {
V_92 = F_35 ( V_27 , & V_62 ) ;
if ( ! V_92 )
F_14 ( V_2 , L_33 ) ;
}
}
static int F_67 ( struct V_69 * V_34 )
{
T_4 * V_93 [] = { F_59 , F_63 } ;
const char * V_94 [] = { L_34 , L_35 } ;
struct V_90 * V_95 [ 2 ] ;
struct V_26 * V_27 ;
void * V_96 ;
int V_31 = 0 , V_19 ;
V_27 = F_13 ( sizeof( * V_27 ) , V_36 ) ;
if ( ! V_27 )
return - V_46 ;
V_27 -> V_34 = V_34 ;
F_68 ( & V_27 -> V_35 ) ;
F_16 ( & V_27 -> V_40 ) ;
F_16 ( & V_27 -> V_72 ) ;
F_69 ( & V_27 -> V_85 ) ;
V_31 = V_34 -> V_97 -> V_98 ( V_34 , 2 , V_95 , V_93 , V_94 ) ;
if ( V_31 )
goto V_99;
V_27 -> V_91 = V_95 [ 0 ] ;
V_27 -> V_77 = V_95 [ 1 ] ;
V_96 = F_70 ( V_34 -> V_2 . V_67 -> V_67 ,
V_100 ,
& V_27 -> V_101 , V_36 ) ;
if ( ! V_96 )
goto V_102;
F_54 ( & V_34 -> V_2 , L_36 , V_96 ,
( unsigned long long ) V_27 -> V_101 ) ;
V_27 -> V_103 = V_96 ;
V_27 -> V_75 = V_96 + V_100 / 2 ;
for ( V_19 = 0 ; V_19 < V_74 / 2 ; V_19 ++ ) {
struct V_80 V_81 ;
void * V_104 = V_27 -> V_103 + V_19 * V_76 ;
F_56 ( & V_81 , V_104 , V_76 ) ;
V_31 = F_57 ( V_27 -> V_91 , & V_81 , 0 , 1 , V_104 ,
V_36 ) ;
F_71 ( V_31 ) ;
}
F_50 ( V_27 -> V_77 ) ;
V_34 -> V_29 = V_27 ;
if ( F_26 ( V_34 , V_51 ) ) {
V_27 -> V_105 = F_11 ( V_27 , NULL , F_65 ,
V_27 , V_56 ) ;
if ( ! V_27 -> V_105 ) {
F_14 ( & V_34 -> V_2 , L_37 ) ;
V_31 = - V_46 ;
goto V_106;
}
}
F_58 ( V_27 -> V_91 ) ;
F_66 ( & V_34 -> V_2 , L_38 ) ;
return 0 ;
V_106:
F_72 ( V_34 -> V_2 . V_67 -> V_67 , V_100 ,
V_96 , V_27 -> V_101 ) ;
V_102:
V_34 -> V_97 -> V_107 ( V_27 -> V_34 ) ;
V_99:
F_10 ( V_27 ) ;
return V_31 ;
}
static int F_73 ( struct V_1 * V_2 , void * V_60 )
{
F_42 ( V_2 ) ;
return 0 ;
}
static void F_74 ( struct V_69 * V_34 )
{
struct V_26 * V_27 = V_34 -> V_29 ;
int V_65 ;
V_34 -> V_97 -> V_108 ( V_34 ) ;
V_65 = F_75 ( & V_34 -> V_2 , NULL , F_73 ) ;
if ( V_65 )
F_60 ( & V_34 -> V_2 , L_39 , V_65 ) ;
if ( V_27 -> V_105 )
F_23 ( V_27 , V_27 -> V_105 ) ;
F_76 ( & V_27 -> V_35 ) ;
F_77 ( & V_27 -> V_35 ) ;
V_34 -> V_97 -> V_107 ( V_27 -> V_34 ) ;
F_72 ( V_34 -> V_2 . V_67 -> V_67 , V_100 ,
V_27 -> V_103 , V_27 -> V_101 ) ;
F_10 ( V_27 ) ;
}
static int T_5 F_78 ( void )
{
int V_65 ;
V_65 = F_79 ( & V_59 ) ;
if ( V_65 ) {
F_38 ( L_40 , V_65 ) ;
return V_65 ;
}
V_65 = F_80 ( & V_109 ) ;
if ( V_65 ) {
F_38 ( L_41 , V_65 ) ;
F_81 ( & V_59 ) ;
}
return V_65 ;
}
static void T_6 F_82 ( void )
{
F_83 ( & V_109 ) ;
F_81 ( & V_59 ) ;
}
