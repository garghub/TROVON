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
int F_28 ( struct V_15 * V_16 )
{
V_16 -> V_14 . V_57 = & V_58 ;
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
static int F_33 ( struct V_1 * V_2 , void * V_59 )
{
struct V_60 * V_61 = V_59 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( V_61 -> V_44 != V_36 && V_61 -> V_44 != V_7 -> V_44 )
return 0 ;
if ( V_61 -> V_62 != V_36 && V_61 -> V_62 != V_7 -> V_62 )
return 0 ;
if ( strncmp ( V_61 -> V_10 , V_7 -> V_9 . V_10 , V_12 ) )
return 0 ;
return 1 ;
}
static struct V_6 * F_34 ( struct V_26 * V_27 ,
struct V_60 * V_61 )
{
struct V_6 * V_7 ;
struct V_1 * V_63 , * V_2 = & V_27 -> V_33 -> V_2 ;
int V_64 ;
V_63 = F_35 ( V_2 , V_61 , F_33 ) ;
if ( V_63 ) {
F_36 ( V_63 ) ;
F_13 ( V_2 , L_8 ,
V_61 -> V_10 , V_61 -> V_44 , V_61 -> V_62 ) ;
return NULL ;
}
V_7 = F_12 ( sizeof( struct V_6 ) , V_34 ) ;
if ( ! V_7 ) {
F_37 ( L_9 ) ;
return NULL ;
}
V_7 -> V_27 = V_27 ;
V_7 -> V_44 = V_61 -> V_44 ;
V_7 -> V_62 = V_61 -> V_62 ;
V_7 -> V_49 = V_7 -> V_44 != V_36 ? true : false ;
strncpy ( V_7 -> V_9 . V_10 , V_61 -> V_10 , V_12 ) ;
F_38 ( & V_7 -> V_2 , L_10 , V_65 ++ ) ;
V_7 -> V_2 . V_66 = & V_27 -> V_33 -> V_2 ;
V_7 -> V_2 . V_57 = & V_58 ;
V_7 -> V_2 . V_67 = F_32 ;
V_64 = F_39 ( & V_7 -> V_2 ) ;
if ( V_64 ) {
F_13 ( V_2 , L_11 , V_64 ) ;
F_36 ( & V_7 -> V_2 ) ;
return NULL ;
}
return V_7 ;
}
static int F_40 ( struct V_26 * V_27 ,
struct V_60 * V_61 )
{
struct V_68 * V_33 = V_27 -> V_33 ;
struct V_1 * V_2 ;
V_2 = F_35 ( & V_33 -> V_2 , V_61 , F_33 ) ;
if ( ! V_2 )
return - V_69 ;
F_41 ( V_2 ) ;
F_36 ( V_2 ) ;
return 0 ;
}
static void * F_42 ( struct V_26 * V_27 )
{
unsigned int V_70 ;
void * V_64 ;
F_16 ( & V_27 -> V_71 ) ;
if ( V_27 -> V_72 < V_73 / 2 )
V_64 = V_27 -> V_74 + V_75 * V_27 -> V_72 ++ ;
else
V_64 = F_43 ( V_27 -> V_76 , & V_70 ) ;
F_18 ( & V_27 -> V_71 ) ;
return V_64 ;
}
static void F_44 ( struct V_26 * V_27 )
{
F_16 ( & V_27 -> V_71 ) ;
if ( F_45 ( & V_27 -> V_77 ) == 1 )
F_46 ( V_27 -> V_76 ) ;
F_18 ( & V_27 -> V_71 ) ;
}
static void F_47 ( struct V_26 * V_27 )
{
F_16 ( & V_27 -> V_71 ) ;
if ( F_48 ( & V_27 -> V_77 ) )
F_49 ( V_27 -> V_76 ) ;
F_18 ( & V_27 -> V_71 ) ;
}
int F_50 ( struct V_6 * V_7 , T_3 V_44 , T_3 V_62 ,
void * V_59 , int V_70 , bool V_78 )
{
struct V_26 * V_27 = V_7 -> V_27 ;
struct V_1 * V_2 = & V_7 -> V_2 ;
struct V_79 V_80 ;
struct V_81 * V_82 ;
int V_42 ;
if ( V_44 == V_36 || V_62 == V_36 ) {
F_13 ( V_2 , L_12 , V_44 , V_62 ) ;
return - V_69 ;
}
if ( V_70 > V_75 - sizeof( struct V_81 ) ) {
F_13 ( V_2 , L_13 , V_70 ) ;
return - V_83 ;
}
V_82 = F_42 ( V_27 ) ;
if ( ! V_82 && ! V_78 )
return - V_45 ;
while ( ! V_82 ) {
F_44 ( V_27 ) ;
V_42 = F_51 ( V_27 -> V_84 ,
( V_82 = F_42 ( V_27 ) ) ,
F_52 ( 15000 ) ) ;
F_47 ( V_27 ) ;
if ( ! V_42 ) {
F_13 ( V_2 , L_14 ) ;
return - V_85 ;
}
}
V_82 -> V_70 = V_70 ;
V_82 -> V_53 = 0 ;
V_82 -> V_44 = V_44 ;
V_82 -> V_62 = V_62 ;
V_82 -> V_86 = 0 ;
memcpy ( V_82 -> V_59 , V_59 , V_70 ) ;
F_53 ( V_2 , L_15 ,
V_82 -> V_44 , V_82 -> V_62 , V_82 -> V_70 ,
V_82 -> V_53 , V_82 -> V_86 ) ;
F_54 ( V_87 , L_16 , V_88 , 16 , 1 ,
V_82 , sizeof( * V_82 ) + V_82 -> V_70 , true ) ;
F_55 ( & V_80 , V_82 , sizeof( * V_82 ) + V_70 ) ;
F_16 ( & V_27 -> V_71 ) ;
V_42 = F_56 ( V_27 -> V_76 , & V_80 , 1 , 0 , V_82 , V_34 ) ;
if ( V_42 ) {
F_13 ( V_2 , L_17 , V_42 ) ;
goto V_46;
}
F_57 ( V_27 -> V_76 ) ;
V_46:
F_18 ( & V_27 -> V_71 ) ;
return V_42 ;
}
static void F_58 ( struct V_89 * V_90 )
{
struct V_81 * V_82 ;
unsigned int V_70 ;
struct V_23 * V_24 ;
struct V_79 V_80 ;
struct V_26 * V_27 = V_90 -> V_33 -> V_29 ;
struct V_1 * V_2 = & V_90 -> V_33 -> V_2 ;
int V_42 ;
V_82 = F_43 ( V_90 , & V_70 ) ;
if ( ! V_82 ) {
F_13 ( V_2 , L_18 ) ;
return;
}
F_53 ( V_2 , L_19 ,
V_82 -> V_44 , V_82 -> V_62 , V_82 -> V_70 ,
V_82 -> V_53 , V_82 -> V_86 ) ;
F_54 ( V_87 , L_20 , V_88 , 16 , 1 ,
V_82 , sizeof( * V_82 ) + V_82 -> V_70 , true ) ;
if ( V_70 > V_75 ||
V_82 -> V_70 > ( V_70 - sizeof( struct V_81 ) ) ) {
F_59 ( V_2 , L_21 , V_70 , V_82 -> V_70 ) ;
return;
}
F_16 ( & V_27 -> V_38 ) ;
V_24 = F_60 ( & V_27 -> V_39 , V_82 -> V_62 ) ;
if ( V_24 )
F_61 ( & V_24 -> V_25 ) ;
F_18 ( & V_27 -> V_38 ) ;
if ( V_24 ) {
F_16 ( & V_24 -> V_35 ) ;
if ( V_24 -> V_28 )
V_24 -> V_28 ( V_24 -> V_7 , V_82 -> V_59 , V_82 -> V_70 , V_24 -> V_29 ,
V_82 -> V_44 ) ;
F_18 ( & V_24 -> V_35 ) ;
F_19 ( & V_24 -> V_25 , F_8 ) ;
} else
F_59 ( V_2 , L_22 ) ;
F_55 ( & V_80 , V_82 , V_75 ) ;
V_42 = F_56 ( V_27 -> V_90 , & V_80 , 0 , 1 , V_82 , V_34 ) ;
if ( V_42 < 0 ) {
F_13 ( V_2 , L_23 , V_42 ) ;
return;
}
F_57 ( V_27 -> V_90 ) ;
}
static void F_62 ( struct V_89 * V_76 )
{
struct V_26 * V_27 = V_76 -> V_33 -> V_29 ;
F_53 ( & V_76 -> V_33 -> V_2 , L_24 , V_48 ) ;
F_63 ( & V_27 -> V_84 ) ;
}
static void F_64 ( struct V_6 * V_7 , void * V_59 , int V_70 ,
void * V_29 , T_3 V_44 )
{
struct V_51 * V_82 = V_59 ;
struct V_6 * V_91 ;
struct V_60 V_61 ;
struct V_26 * V_27 = V_29 ;
struct V_1 * V_2 = & V_27 -> V_33 -> V_2 ;
int V_64 ;
F_54 ( V_87 , L_25 ,
V_88 , 16 , 1 ,
V_59 , V_70 , true ) ;
if ( V_70 != sizeof( * V_82 ) ) {
F_13 ( V_2 , L_26 , V_70 ) ;
return;
}
if ( V_7 ) {
F_13 ( V_2 , L_27 ) ;
return;
}
V_82 -> V_10 [ V_12 - 1 ] = '\0' ;
F_65 ( V_2 , L_28 ,
V_82 -> V_53 & V_56 ? L_29 : L_30 ,
V_82 -> V_10 , V_82 -> V_30 ) ;
strncpy ( V_61 . V_10 , V_82 -> V_10 , sizeof( V_61 . V_10 ) ) ;
V_61 . V_44 = V_36 ;
V_61 . V_62 = V_82 -> V_30 ;
if ( V_82 -> V_53 & V_56 ) {
V_64 = F_40 ( V_27 , & V_61 ) ;
if ( V_64 )
F_13 ( V_2 , L_31 , V_64 ) ;
} else {
V_91 = F_34 ( V_27 , & V_61 ) ;
if ( ! V_91 )
F_13 ( V_2 , L_32 ) ;
}
}
static int F_66 ( struct V_68 * V_33 )
{
T_4 * V_92 [] = { F_58 , F_62 } ;
const char * V_93 [] = { L_33 , L_34 } ;
struct V_89 * V_94 [ 2 ] ;
struct V_26 * V_27 ;
void * V_95 ;
int V_42 = 0 , V_19 ;
V_27 = F_12 ( sizeof( * V_27 ) , V_34 ) ;
if ( ! V_27 )
return - V_45 ;
V_27 -> V_33 = V_33 ;
F_67 ( & V_27 -> V_39 ) ;
F_15 ( & V_27 -> V_38 ) ;
F_15 ( & V_27 -> V_71 ) ;
F_68 ( & V_27 -> V_84 ) ;
V_42 = V_33 -> V_96 -> V_97 ( V_33 , 2 , V_94 , V_92 , V_93 ) ;
if ( V_42 )
goto V_98;
V_27 -> V_90 = V_94 [ 0 ] ;
V_27 -> V_76 = V_94 [ 1 ] ;
V_95 = F_69 ( V_33 -> V_2 . V_66 -> V_66 ,
V_99 ,
& V_27 -> V_100 , V_34 ) ;
if ( ! V_95 )
goto V_101;
F_53 ( & V_33 -> V_2 , L_35 , V_95 ,
( unsigned long long ) V_27 -> V_100 ) ;
V_27 -> V_102 = V_95 ;
V_27 -> V_74 = V_95 + V_99 / 2 ;
for ( V_19 = 0 ; V_19 < V_73 / 2 ; V_19 ++ ) {
struct V_79 V_80 ;
void * V_103 = V_27 -> V_102 + V_19 * V_75 ;
F_55 ( & V_80 , V_103 , V_75 ) ;
V_42 = F_56 ( V_27 -> V_90 , & V_80 , 0 , 1 , V_103 ,
V_34 ) ;
F_70 ( V_42 ) ;
}
F_49 ( V_27 -> V_76 ) ;
V_33 -> V_29 = V_27 ;
if ( F_25 ( V_33 , V_50 ) ) {
V_27 -> V_104 = F_11 ( V_27 , NULL , F_64 ,
V_27 , V_55 ) ;
if ( ! V_27 -> V_104 ) {
F_13 ( & V_33 -> V_2 , L_36 ) ;
V_42 = - V_45 ;
goto V_105;
}
}
F_57 ( V_27 -> V_90 ) ;
F_65 ( & V_33 -> V_2 , L_37 ) ;
return 0 ;
V_105:
F_71 ( V_33 -> V_2 . V_66 -> V_66 , V_99 ,
V_95 , V_27 -> V_100 ) ;
V_101:
V_33 -> V_96 -> V_106 ( V_27 -> V_33 ) ;
V_98:
F_10 ( V_27 ) ;
return V_42 ;
}
static int F_72 ( struct V_1 * V_2 , void * V_59 )
{
F_41 ( V_2 ) ;
return 0 ;
}
static void F_73 ( struct V_68 * V_33 )
{
struct V_26 * V_27 = V_33 -> V_29 ;
int V_64 ;
V_33 -> V_96 -> V_107 ( V_33 ) ;
V_64 = F_74 ( & V_33 -> V_2 , NULL , F_72 ) ;
if ( V_64 )
F_59 ( & V_33 -> V_2 , L_38 , V_64 ) ;
if ( V_27 -> V_104 )
F_21 ( V_27 , V_27 -> V_104 ) ;
F_75 ( & V_27 -> V_39 ) ;
V_33 -> V_96 -> V_106 ( V_27 -> V_33 ) ;
F_71 ( V_33 -> V_2 . V_66 -> V_66 , V_99 ,
V_27 -> V_102 , V_27 -> V_100 ) ;
F_10 ( V_27 ) ;
}
static int T_5 F_76 ( void )
{
int V_64 ;
V_64 = F_77 ( & V_58 ) ;
if ( V_64 ) {
F_37 ( L_39 , V_64 ) ;
return V_64 ;
}
V_64 = F_78 ( & V_108 ) ;
if ( V_64 ) {
F_37 ( L_40 , V_64 ) ;
F_79 ( & V_58 ) ;
}
return V_64 ;
}
static void T_6 F_80 ( void )
{
F_81 ( & V_108 ) ;
F_79 ( & V_58 ) ;
}
