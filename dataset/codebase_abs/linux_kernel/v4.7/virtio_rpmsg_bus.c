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
int V_31 , V_32 , V_9 ;
struct V_23 * V_24 ;
struct V_1 * V_2 = V_7 ? & V_7 -> V_2 : & V_27 -> V_33 -> V_2 ;
V_24 = F_12 ( sizeof( * V_24 ) , V_34 ) ;
if ( ! V_24 ) {
F_13 ( V_2 , L_3 ) ;
return NULL ;
}
F_14 ( & V_24 -> V_25 ) ;
F_15 ( & V_24 -> V_35 ) ;
V_24 -> V_7 = V_7 ;
V_24 -> V_28 = V_28 ;
V_24 -> V_29 = V_29 ;
if ( V_30 == V_36 ) {
V_31 = V_37 ;
V_32 = 0 ;
} else {
V_31 = V_30 ;
V_32 = V_30 + 1 ;
}
F_16 ( & V_27 -> V_38 ) ;
V_9 = F_17 ( & V_27 -> V_39 , V_24 , V_31 , V_32 , V_34 ) ;
if ( V_9 < 0 ) {
F_13 ( V_2 , L_4 , V_9 ) ;
goto V_40;
}
V_24 -> V_30 = V_9 ;
F_18 ( & V_27 -> V_38 ) ;
return V_24 ;
V_40:
F_18 ( & V_27 -> V_38 ) ;
F_19 ( & V_24 -> V_25 , F_8 ) ;
return NULL ;
}
struct V_23 * F_20 ( struct V_6 * V_7 ,
T_2 V_28 , void * V_29 , T_3 V_30 )
{
return F_11 ( V_7 -> V_27 , V_7 , V_28 , V_29 , V_30 ) ;
}
static void
F_21 ( struct V_26 * V_27 , struct V_23 * V_24 )
{
F_16 ( & V_27 -> V_38 ) ;
F_22 ( & V_27 -> V_39 , V_24 -> V_30 ) ;
F_18 ( & V_27 -> V_38 ) ;
F_16 ( & V_24 -> V_35 ) ;
V_24 -> V_28 = NULL ;
F_18 ( & V_24 -> V_35 ) ;
F_19 ( & V_24 -> V_25 , F_8 ) ;
}
void F_23 ( struct V_23 * V_24 )
{
F_21 ( V_24 -> V_7 -> V_27 , V_24 ) ;
}
static int F_24 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_15 * V_16 = F_5 ( V_7 -> V_2 . V_41 ) ;
struct V_26 * V_27 = V_7 -> V_27 ;
struct V_23 * V_24 ;
int V_42 ;
V_24 = F_20 ( V_7 , V_16 -> V_43 , NULL , V_7 -> V_44 ) ;
if ( ! V_24 ) {
F_13 ( V_2 , L_5 ) ;
V_42 = - V_45 ;
goto V_46;
}
V_7 -> V_24 = V_24 ;
V_7 -> V_44 = V_24 -> V_30 ;
V_42 = V_16 -> V_47 ( V_7 ) ;
if ( V_42 ) {
F_13 ( V_2 , L_6 , V_48 , V_42 ) ;
F_23 ( V_24 ) ;
goto V_46;
}
if ( V_7 -> V_49 &&
F_25 ( V_27 -> V_33 , V_50 ) ) {
struct V_51 V_52 ;
strncpy ( V_52 . V_10 , V_7 -> V_9 . V_10 , V_12 ) ;
V_52 . V_30 = V_7 -> V_44 ;
V_52 . V_53 = V_54 ;
V_42 = F_26 ( V_7 , & V_52 , sizeof( V_52 ) , V_55 ) ;
if ( V_42 )
F_13 ( V_2 , L_7 , V_42 ) ;
}
V_46:
return V_42 ;
}
static int F_27 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_15 * V_16 = F_5 ( V_7 -> V_2 . V_41 ) ;
struct V_26 * V_27 = V_7 -> V_27 ;
int V_42 = 0 ;
if ( V_7 -> V_49 &&
F_25 ( V_27 -> V_33 , V_50 ) ) {
struct V_51 V_52 ;
strncpy ( V_52 . V_10 , V_7 -> V_9 . V_10 , V_12 ) ;
V_52 . V_30 = V_7 -> V_44 ;
V_52 . V_53 = V_56 ;
V_42 = F_26 ( V_7 , & V_52 , sizeof( V_52 ) , V_55 ) ;
if ( V_42 )
F_13 ( V_2 , L_7 , V_42 ) ;
}
V_16 -> remove ( V_7 ) ;
F_23 ( V_7 -> V_24 ) ;
return V_42 ;
}
int F_28 ( struct V_15 * V_16 , struct V_57 * V_58 )
{
V_16 -> V_14 . V_59 = & V_60 ;
V_16 -> V_14 . V_58 = V_58 ;
return F_29 ( & V_16 -> V_14 ) ;
}
void F_30 ( struct V_15 * V_16 )
{
F_31 ( & V_16 -> V_14 ) ;
}
static void F_32 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_10 ( V_7 ) ;
}
static int F_33 ( struct V_1 * V_2 , void * V_61 )
{
struct V_62 * V_63 = V_61 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( V_63 -> V_44 != V_36 && V_63 -> V_44 != V_7 -> V_44 )
return 0 ;
if ( V_63 -> V_64 != V_36 && V_63 -> V_64 != V_7 -> V_64 )
return 0 ;
if ( strncmp ( V_63 -> V_10 , V_7 -> V_9 . V_10 , V_12 ) )
return 0 ;
return 1 ;
}
static struct V_6 * F_34 ( struct V_26 * V_27 ,
struct V_62 * V_63 )
{
struct V_6 * V_7 ;
struct V_1 * V_65 , * V_2 = & V_27 -> V_33 -> V_2 ;
int V_66 ;
V_65 = F_35 ( V_2 , V_63 , F_33 ) ;
if ( V_65 ) {
F_36 ( V_65 ) ;
F_13 ( V_2 , L_8 ,
V_63 -> V_10 , V_63 -> V_44 , V_63 -> V_64 ) ;
return NULL ;
}
V_7 = F_12 ( sizeof( struct V_6 ) , V_34 ) ;
if ( ! V_7 ) {
F_37 ( L_9 ) ;
return NULL ;
}
V_7 -> V_27 = V_27 ;
V_7 -> V_44 = V_63 -> V_44 ;
V_7 -> V_64 = V_63 -> V_64 ;
V_7 -> V_49 = V_7 -> V_44 != V_36 ? true : false ;
strncpy ( V_7 -> V_9 . V_10 , V_63 -> V_10 , V_12 ) ;
F_38 ( & V_7 -> V_2 , L_10 , V_67 ++ ) ;
V_7 -> V_2 . V_68 = & V_27 -> V_33 -> V_2 ;
V_7 -> V_2 . V_59 = & V_60 ;
V_7 -> V_2 . V_69 = F_32 ;
V_66 = F_39 ( & V_7 -> V_2 ) ;
if ( V_66 ) {
F_13 ( V_2 , L_11 , V_66 ) ;
F_36 ( & V_7 -> V_2 ) ;
return NULL ;
}
return V_7 ;
}
static int F_40 ( struct V_26 * V_27 ,
struct V_62 * V_63 )
{
struct V_70 * V_33 = V_27 -> V_33 ;
struct V_1 * V_2 ;
V_2 = F_35 ( & V_33 -> V_2 , V_63 , F_33 ) ;
if ( ! V_2 )
return - V_71 ;
F_41 ( V_2 ) ;
F_36 ( V_2 ) ;
return 0 ;
}
static void * F_42 ( struct V_26 * V_27 )
{
unsigned int V_72 ;
void * V_66 ;
F_16 ( & V_27 -> V_73 ) ;
if ( V_27 -> V_74 < V_27 -> V_75 / 2 )
V_66 = V_27 -> V_76 + V_77 * V_27 -> V_74 ++ ;
else
V_66 = F_43 ( V_27 -> V_78 , & V_72 ) ;
F_18 ( & V_27 -> V_73 ) ;
return V_66 ;
}
static void F_44 ( struct V_26 * V_27 )
{
F_16 ( & V_27 -> V_73 ) ;
if ( F_45 ( & V_27 -> V_79 ) == 1 )
F_46 ( V_27 -> V_78 ) ;
F_18 ( & V_27 -> V_73 ) ;
}
static void F_47 ( struct V_26 * V_27 )
{
F_16 ( & V_27 -> V_73 ) ;
if ( F_48 ( & V_27 -> V_79 ) )
F_49 ( V_27 -> V_78 ) ;
F_18 ( & V_27 -> V_73 ) ;
}
int F_50 ( struct V_6 * V_7 , T_3 V_44 , T_3 V_64 ,
void * V_61 , int V_72 , bool V_80 )
{
struct V_26 * V_27 = V_7 -> V_27 ;
struct V_1 * V_2 = & V_7 -> V_2 ;
struct V_81 V_82 ;
struct V_83 * V_84 ;
int V_42 ;
if ( V_44 == V_36 || V_64 == V_36 ) {
F_13 ( V_2 , L_12 , V_44 , V_64 ) ;
return - V_71 ;
}
if ( V_72 > V_77 - sizeof( struct V_83 ) ) {
F_13 ( V_2 , L_13 , V_72 ) ;
return - V_85 ;
}
V_84 = F_42 ( V_27 ) ;
if ( ! V_84 && ! V_80 )
return - V_45 ;
while ( ! V_84 ) {
F_44 ( V_27 ) ;
V_42 = F_51 ( V_27 -> V_86 ,
( V_84 = F_42 ( V_27 ) ) ,
F_52 ( 15000 ) ) ;
F_47 ( V_27 ) ;
if ( ! V_42 ) {
F_13 ( V_2 , L_14 ) ;
return - V_87 ;
}
}
V_84 -> V_72 = V_72 ;
V_84 -> V_53 = 0 ;
V_84 -> V_44 = V_44 ;
V_84 -> V_64 = V_64 ;
V_84 -> V_88 = 0 ;
memcpy ( V_84 -> V_61 , V_61 , V_72 ) ;
F_53 ( V_2 , L_15 ,
V_84 -> V_44 , V_84 -> V_64 , V_84 -> V_72 ,
V_84 -> V_53 , V_84 -> V_88 ) ;
F_54 ( V_89 , L_16 , V_90 , 16 , 1 ,
V_84 , sizeof( * V_84 ) + V_84 -> V_72 , true ) ;
F_55 ( & V_82 , V_84 , sizeof( * V_84 ) + V_72 ) ;
F_16 ( & V_27 -> V_73 ) ;
V_42 = F_56 ( V_27 -> V_78 , & V_82 , 1 , V_84 , V_34 ) ;
if ( V_42 ) {
F_13 ( V_2 , L_17 , V_42 ) ;
goto V_46;
}
F_57 ( V_27 -> V_78 ) ;
V_46:
F_18 ( & V_27 -> V_73 ) ;
return V_42 ;
}
static int F_58 ( struct V_26 * V_27 , struct V_1 * V_2 ,
struct V_83 * V_84 , unsigned int V_72 )
{
struct V_23 * V_24 ;
struct V_81 V_82 ;
int V_42 ;
F_53 ( V_2 , L_18 ,
V_84 -> V_44 , V_84 -> V_64 , V_84 -> V_72 ,
V_84 -> V_53 , V_84 -> V_88 ) ;
F_54 ( V_89 , L_19 , V_90 , 16 , 1 ,
V_84 , sizeof( * V_84 ) + V_84 -> V_72 , true ) ;
if ( V_72 > V_77 ||
V_84 -> V_72 > ( V_72 - sizeof( struct V_83 ) ) ) {
F_59 ( V_2 , L_20 , V_72 , V_84 -> V_72 ) ;
return - V_71 ;
}
F_16 ( & V_27 -> V_38 ) ;
V_24 = F_60 ( & V_27 -> V_39 , V_84 -> V_64 ) ;
if ( V_24 )
F_61 ( & V_24 -> V_25 ) ;
F_18 ( & V_27 -> V_38 ) ;
if ( V_24 ) {
F_16 ( & V_24 -> V_35 ) ;
if ( V_24 -> V_28 )
V_24 -> V_28 ( V_24 -> V_7 , V_84 -> V_61 , V_84 -> V_72 , V_24 -> V_29 ,
V_84 -> V_44 ) ;
F_18 ( & V_24 -> V_35 ) ;
F_19 ( & V_24 -> V_25 , F_8 ) ;
} else
F_59 ( V_2 , L_21 ) ;
F_55 ( & V_82 , V_84 , V_77 ) ;
V_42 = F_62 ( V_27 -> V_91 , & V_82 , 1 , V_84 , V_34 ) ;
if ( V_42 < 0 ) {
F_13 ( V_2 , L_22 , V_42 ) ;
return V_42 ;
}
return 0 ;
}
static void F_63 ( struct V_92 * V_91 )
{
struct V_26 * V_27 = V_91 -> V_33 -> V_29 ;
struct V_1 * V_2 = & V_91 -> V_33 -> V_2 ;
struct V_83 * V_84 ;
unsigned int V_72 , V_93 = 0 ;
int V_42 ;
V_84 = F_43 ( V_91 , & V_72 ) ;
if ( ! V_84 ) {
F_13 ( V_2 , L_23 ) ;
return;
}
while ( V_84 ) {
V_42 = F_58 ( V_27 , V_2 , V_84 , V_72 ) ;
if ( V_42 )
break;
V_93 ++ ;
V_84 = F_43 ( V_91 , & V_72 ) ;
} ;
F_53 ( V_2 , L_24 , V_93 ) ;
if ( V_93 )
F_57 ( V_27 -> V_91 ) ;
}
static void F_64 ( struct V_92 * V_78 )
{
struct V_26 * V_27 = V_78 -> V_33 -> V_29 ;
F_53 ( & V_78 -> V_33 -> V_2 , L_25 , V_48 ) ;
F_65 ( & V_27 -> V_86 ) ;
}
static void F_66 ( struct V_6 * V_7 , void * V_61 , int V_72 ,
void * V_29 , T_3 V_44 )
{
struct V_51 * V_84 = V_61 ;
struct V_6 * V_94 ;
struct V_62 V_63 ;
struct V_26 * V_27 = V_29 ;
struct V_1 * V_2 = & V_27 -> V_33 -> V_2 ;
int V_66 ;
F_54 ( V_89 , L_26 ,
V_90 , 16 , 1 ,
V_61 , V_72 , true ) ;
if ( V_72 != sizeof( * V_84 ) ) {
F_13 ( V_2 , L_27 , V_72 ) ;
return;
}
if ( V_7 ) {
F_13 ( V_2 , L_28 ) ;
return;
}
V_84 -> V_10 [ V_12 - 1 ] = '\0' ;
F_67 ( V_2 , L_29 ,
V_84 -> V_53 & V_56 ? L_30 : L_31 ,
V_84 -> V_10 , V_84 -> V_30 ) ;
strncpy ( V_63 . V_10 , V_84 -> V_10 , sizeof( V_63 . V_10 ) ) ;
V_63 . V_44 = V_36 ;
V_63 . V_64 = V_84 -> V_30 ;
if ( V_84 -> V_53 & V_56 ) {
V_66 = F_40 ( V_27 , & V_63 ) ;
if ( V_66 )
F_13 ( V_2 , L_32 , V_66 ) ;
} else {
V_94 = F_34 ( V_27 , & V_63 ) ;
if ( ! V_94 )
F_13 ( V_2 , L_33 ) ;
}
}
static int F_68 ( struct V_70 * V_33 )
{
T_4 * V_95 [] = { F_63 , F_64 } ;
static const char * const V_96 [] = { L_34 , L_35 } ;
struct V_92 * V_97 [ 2 ] ;
struct V_26 * V_27 ;
void * V_98 ;
int V_42 = 0 , V_19 ;
T_5 V_99 ;
bool V_100 ;
V_27 = F_12 ( sizeof( * V_27 ) , V_34 ) ;
if ( ! V_27 )
return - V_45 ;
V_27 -> V_33 = V_33 ;
F_69 ( & V_27 -> V_39 ) ;
F_15 ( & V_27 -> V_38 ) ;
F_15 ( & V_27 -> V_73 ) ;
F_70 ( & V_27 -> V_86 ) ;
V_42 = V_33 -> V_101 -> V_102 ( V_33 , 2 , V_97 , V_95 , V_96 ) ;
if ( V_42 )
goto V_103;
V_27 -> V_91 = V_97 [ 0 ] ;
V_27 -> V_78 = V_97 [ 1 ] ;
F_71 ( F_72 ( V_27 -> V_91 ) !=
F_72 ( V_27 -> V_78 ) ) ;
if ( F_72 ( V_27 -> V_91 ) < V_104 / 2 )
V_27 -> V_75 = F_72 ( V_27 -> V_91 ) * 2 ;
else
V_27 -> V_75 = V_104 ;
V_99 = V_27 -> V_75 * V_77 ;
V_98 = F_73 ( V_33 -> V_2 . V_68 -> V_68 ,
V_99 , & V_27 -> V_105 ,
V_34 ) ;
if ( ! V_98 ) {
V_42 = - V_45 ;
goto V_106;
}
F_53 ( & V_33 -> V_2 , L_36 , V_98 ,
( unsigned long long ) V_27 -> V_105 ) ;
V_27 -> V_107 = V_98 ;
V_27 -> V_76 = V_98 + V_99 / 2 ;
for ( V_19 = 0 ; V_19 < V_27 -> V_75 / 2 ; V_19 ++ ) {
struct V_81 V_82 ;
void * V_108 = V_27 -> V_107 + V_19 * V_77 ;
F_55 ( & V_82 , V_108 , V_77 ) ;
V_42 = F_62 ( V_27 -> V_91 , & V_82 , 1 , V_108 ,
V_34 ) ;
F_71 ( V_42 ) ;
}
F_49 ( V_27 -> V_78 ) ;
V_33 -> V_29 = V_27 ;
if ( F_25 ( V_33 , V_50 ) ) {
V_27 -> V_109 = F_11 ( V_27 , NULL , F_66 ,
V_27 , V_55 ) ;
if ( ! V_27 -> V_109 ) {
F_13 ( & V_33 -> V_2 , L_37 ) ;
V_42 = - V_45 ;
goto V_110;
}
}
V_100 = F_74 ( V_27 -> V_91 ) ;
F_75 ( V_33 ) ;
if ( V_100 )
F_76 ( V_27 -> V_91 ) ;
F_67 ( & V_33 -> V_2 , L_38 ) ;
return 0 ;
V_110:
F_77 ( V_33 -> V_2 . V_68 -> V_68 , V_99 ,
V_98 , V_27 -> V_105 ) ;
V_106:
V_33 -> V_101 -> V_111 ( V_27 -> V_33 ) ;
V_103:
F_10 ( V_27 ) ;
return V_42 ;
}
static int F_78 ( struct V_1 * V_2 , void * V_61 )
{
F_41 ( V_2 ) ;
return 0 ;
}
static void F_79 ( struct V_70 * V_33 )
{
struct V_26 * V_27 = V_33 -> V_29 ;
T_5 V_99 = V_27 -> V_75 * V_77 ;
int V_66 ;
V_33 -> V_101 -> V_112 ( V_33 ) ;
V_66 = F_80 ( & V_33 -> V_2 , NULL , F_78 ) ;
if ( V_66 )
F_59 ( & V_33 -> V_2 , L_39 , V_66 ) ;
if ( V_27 -> V_109 )
F_21 ( V_27 , V_27 -> V_109 ) ;
F_81 ( & V_27 -> V_39 ) ;
V_33 -> V_101 -> V_111 ( V_27 -> V_33 ) ;
F_77 ( V_33 -> V_2 . V_68 -> V_68 , V_99 ,
V_27 -> V_107 , V_27 -> V_105 ) ;
F_10 ( V_27 ) ;
}
static int T_6 F_82 ( void )
{
int V_66 ;
V_66 = F_83 ( & V_60 ) ;
if ( V_66 ) {
F_37 ( L_40 , V_66 ) ;
return V_66 ;
}
V_66 = F_84 ( & V_113 ) ;
if ( V_66 ) {
F_37 ( L_41 , V_66 ) ;
F_85 ( & V_60 ) ;
}
return V_66 ;
}
static void T_7 F_86 ( void )
{
F_87 ( & V_113 ) ;
F_85 ( & V_60 ) ;
}
