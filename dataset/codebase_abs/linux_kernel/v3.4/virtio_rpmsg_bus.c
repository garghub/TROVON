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
static struct V_22 * F_8 ( struct V_23 * V_24 ,
struct V_6 * V_7 , T_2 V_25 ,
void * V_26 , T_3 V_27 )
{
int V_28 , V_29 , V_30 ;
struct V_22 * V_31 ;
struct V_1 * V_2 = V_7 ? & V_7 -> V_2 : & V_24 -> V_32 -> V_2 ;
if ( ! F_9 ( & V_24 -> V_33 , V_34 ) )
return NULL ;
V_31 = F_10 ( sizeof( * V_31 ) , V_34 ) ;
if ( ! V_31 ) {
F_11 ( V_2 , L_3 ) ;
return NULL ;
}
V_31 -> V_7 = V_7 ;
V_31 -> V_25 = V_25 ;
V_31 -> V_26 = V_26 ;
V_30 = V_27 == V_35 ? V_36 : V_27 ;
F_12 ( & V_24 -> V_37 ) ;
V_28 = F_13 ( & V_24 -> V_33 , V_31 , V_30 , & V_29 ) ;
if ( V_28 ) {
F_11 ( V_2 , L_4 , V_28 ) ;
goto V_38;
}
if ( V_27 != V_35 && V_29 != V_27 ) {
F_11 ( V_2 , L_5 , V_27 ) ;
goto V_39;
}
V_31 -> V_27 = V_29 ;
F_14 ( & V_24 -> V_37 ) ;
return V_31 ;
V_39:
F_15 ( & V_24 -> V_33 , V_30 ) ;
V_38:
F_14 ( & V_24 -> V_37 ) ;
F_16 ( V_31 ) ;
return NULL ;
}
struct V_22 * F_17 ( struct V_6 * V_7 ,
T_2 V_25 , void * V_26 , T_3 V_27 )
{
return F_8 ( V_7 -> V_24 , V_7 , V_25 , V_26 , V_27 ) ;
}
static void
F_18 ( struct V_23 * V_24 , struct V_22 * V_31 )
{
F_12 ( & V_24 -> V_37 ) ;
F_15 ( & V_24 -> V_33 , V_31 -> V_27 ) ;
F_14 ( & V_24 -> V_37 ) ;
F_16 ( V_31 ) ;
}
void F_19 ( struct V_22 * V_31 )
{
F_18 ( V_31 -> V_7 -> V_24 , V_31 ) ;
}
static int F_20 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_15 * V_16 = F_5 ( V_7 -> V_2 . V_40 ) ;
struct V_23 * V_24 = V_7 -> V_24 ;
struct V_22 * V_31 ;
int V_28 ;
V_31 = F_17 ( V_7 , V_16 -> V_41 , NULL , V_7 -> V_42 ) ;
if ( ! V_31 ) {
F_11 ( V_2 , L_6 ) ;
V_28 = - V_43 ;
goto V_44;
}
V_7 -> V_31 = V_31 ;
V_7 -> V_42 = V_31 -> V_27 ;
V_28 = V_16 -> V_45 ( V_7 ) ;
if ( V_28 ) {
F_11 ( V_2 , L_7 , V_46 , V_28 ) ;
F_19 ( V_31 ) ;
goto V_44;
}
if ( V_7 -> V_47 &&
F_21 ( V_24 -> V_32 , V_48 ) ) {
struct V_49 V_50 ;
strncpy ( V_50 . V_10 , V_7 -> V_9 . V_10 , V_12 ) ;
V_50 . V_27 = V_7 -> V_42 ;
V_50 . V_51 = V_52 ;
V_28 = F_22 ( V_7 , & V_50 , sizeof( V_50 ) , V_53 ) ;
if ( V_28 )
F_11 ( V_2 , L_8 , V_28 ) ;
}
V_44:
return V_28 ;
}
static int F_23 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_15 * V_16 = F_5 ( V_7 -> V_2 . V_40 ) ;
struct V_23 * V_24 = V_7 -> V_24 ;
int V_28 = 0 ;
if ( V_7 -> V_47 &&
F_21 ( V_24 -> V_32 , V_48 ) ) {
struct V_49 V_50 ;
strncpy ( V_50 . V_10 , V_7 -> V_9 . V_10 , V_12 ) ;
V_50 . V_27 = V_7 -> V_42 ;
V_50 . V_51 = V_54 ;
V_28 = F_22 ( V_7 , & V_50 , sizeof( V_50 ) , V_53 ) ;
if ( V_28 )
F_11 ( V_2 , L_8 , V_28 ) ;
}
V_16 -> remove ( V_7 ) ;
F_19 ( V_7 -> V_31 ) ;
return V_28 ;
}
int F_24 ( struct V_15 * V_16 )
{
V_16 -> V_14 . V_55 = & V_56 ;
return F_25 ( & V_16 -> V_14 ) ;
}
void F_26 ( struct V_15 * V_16 )
{
F_27 ( & V_16 -> V_14 ) ;
}
static void F_28 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_16 ( V_7 ) ;
}
static int F_29 ( struct V_1 * V_2 , void * V_57 )
{
struct V_58 * V_59 = V_57 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( V_59 -> V_42 != V_35 && V_59 -> V_42 != V_7 -> V_42 )
return 0 ;
if ( V_59 -> V_60 != V_35 && V_59 -> V_60 != V_7 -> V_60 )
return 0 ;
if ( strncmp ( V_59 -> V_10 , V_7 -> V_9 . V_10 , V_12 ) )
return 0 ;
return 1 ;
}
static struct V_6 * F_30 ( struct V_23 * V_24 ,
struct V_58 * V_59 )
{
struct V_6 * V_7 ;
struct V_1 * V_61 , * V_2 = & V_24 -> V_32 -> V_2 ;
int V_62 ;
V_61 = F_31 ( V_2 , V_59 , F_29 ) ;
if ( V_61 ) {
F_32 ( V_61 ) ;
F_11 ( V_2 , L_9 ,
V_59 -> V_10 , V_59 -> V_42 , V_59 -> V_60 ) ;
return NULL ;
}
V_7 = F_10 ( sizeof( struct V_6 ) , V_34 ) ;
if ( ! V_7 ) {
F_33 ( L_10 ) ;
return NULL ;
}
V_7 -> V_24 = V_24 ;
V_7 -> V_42 = V_59 -> V_42 ;
V_7 -> V_60 = V_59 -> V_60 ;
V_7 -> V_47 = V_7 -> V_42 != V_35 ? true : false ;
strncpy ( V_7 -> V_9 . V_10 , V_59 -> V_10 , V_12 ) ;
F_34 ( & V_7 -> V_2 , L_11 , V_63 ++ ) ;
V_7 -> V_2 . V_64 = & V_24 -> V_32 -> V_2 ;
V_7 -> V_2 . V_55 = & V_56 ;
V_7 -> V_2 . V_65 = F_28 ;
V_62 = F_35 ( & V_7 -> V_2 ) ;
if ( V_62 ) {
F_11 ( V_2 , L_12 , V_62 ) ;
F_32 ( & V_7 -> V_2 ) ;
return NULL ;
}
return V_7 ;
}
static int F_36 ( struct V_23 * V_24 ,
struct V_58 * V_59 )
{
struct V_66 * V_32 = V_24 -> V_32 ;
struct V_1 * V_2 ;
V_2 = F_31 ( & V_32 -> V_2 , V_59 , F_29 ) ;
if ( ! V_2 )
return - V_67 ;
F_37 ( V_2 ) ;
F_32 ( V_2 ) ;
return 0 ;
}
static void * F_38 ( struct V_23 * V_24 )
{
unsigned int V_68 ;
void * V_62 ;
F_12 ( & V_24 -> V_69 ) ;
if ( V_24 -> V_70 < V_71 / 2 )
V_62 = V_24 -> V_72 + V_73 * V_24 -> V_70 ++ ;
else
V_62 = F_39 ( V_24 -> V_74 , & V_68 ) ;
F_14 ( & V_24 -> V_69 ) ;
return V_62 ;
}
static void F_40 ( struct V_23 * V_24 )
{
F_12 ( & V_24 -> V_69 ) ;
if ( F_41 ( & V_24 -> V_75 ) == 1 )
F_42 ( V_24 -> V_74 ) ;
F_14 ( & V_24 -> V_69 ) ;
}
static void F_43 ( struct V_23 * V_24 )
{
F_12 ( & V_24 -> V_69 ) ;
if ( F_44 ( & V_24 -> V_75 ) )
F_45 ( V_24 -> V_74 ) ;
F_14 ( & V_24 -> V_69 ) ;
}
int F_46 ( struct V_6 * V_7 , T_3 V_42 , T_3 V_60 ,
void * V_57 , int V_68 , bool V_76 )
{
struct V_23 * V_24 = V_7 -> V_24 ;
struct V_1 * V_2 = & V_7 -> V_2 ;
struct V_77 V_78 ;
struct V_79 * V_80 ;
int V_28 ;
if ( V_42 == V_35 || V_60 == V_35 ) {
F_11 ( V_2 , L_13 , V_42 , V_60 ) ;
return - V_67 ;
}
if ( V_68 > V_73 - sizeof( struct V_79 ) ) {
F_11 ( V_2 , L_14 , V_68 ) ;
return - V_81 ;
}
V_80 = F_38 ( V_24 ) ;
if ( ! V_80 && ! V_76 )
return - V_43 ;
while ( ! V_80 ) {
F_40 ( V_24 ) ;
V_28 = F_47 ( V_24 -> V_82 ,
( V_80 = F_38 ( V_24 ) ) ,
F_48 ( 15000 ) ) ;
F_43 ( V_24 ) ;
if ( ! V_28 ) {
F_11 ( V_2 , L_15 ) ;
return - V_83 ;
}
}
V_80 -> V_68 = V_68 ;
V_80 -> V_51 = 0 ;
V_80 -> V_42 = V_42 ;
V_80 -> V_60 = V_60 ;
V_80 -> V_84 = 0 ;
memcpy ( V_80 -> V_57 , V_57 , V_68 ) ;
F_49 ( V_2 , L_16 ,
V_80 -> V_42 , V_80 -> V_60 , V_80 -> V_68 ,
V_80 -> V_51 , V_80 -> V_84 ) ;
F_50 ( V_85 , L_17 , V_86 , 16 , 1 ,
V_80 , sizeof( * V_80 ) + V_80 -> V_68 , true ) ;
F_51 ( & V_78 , V_80 , sizeof( * V_80 ) + V_68 ) ;
F_12 ( & V_24 -> V_69 ) ;
V_28 = F_52 ( V_24 -> V_74 , & V_78 , 1 , 0 , V_80 , V_34 ) ;
if ( V_28 < 0 ) {
F_11 ( V_2 , L_18 , V_28 ) ;
goto V_44;
}
F_53 ( V_24 -> V_74 ) ;
V_28 = 0 ;
V_44:
F_14 ( & V_24 -> V_69 ) ;
return V_28 ;
}
static void F_54 ( struct V_87 * V_88 )
{
struct V_79 * V_80 ;
unsigned int V_68 ;
struct V_22 * V_31 ;
struct V_77 V_78 ;
struct V_23 * V_24 = V_88 -> V_32 -> V_26 ;
struct V_1 * V_2 = & V_88 -> V_32 -> V_2 ;
int V_28 ;
V_80 = F_39 ( V_88 , & V_68 ) ;
if ( ! V_80 ) {
F_11 ( V_2 , L_19 ) ;
return;
}
F_49 ( V_2 , L_20 ,
V_80 -> V_42 , V_80 -> V_60 , V_80 -> V_68 ,
V_80 -> V_51 , V_80 -> V_84 ) ;
F_50 ( V_85 , L_21 , V_86 , 16 , 1 ,
V_80 , sizeof( * V_80 ) + V_80 -> V_68 , true ) ;
if ( V_68 > V_73 ||
V_80 -> V_68 > ( V_68 - sizeof( struct V_79 ) ) ) {
F_55 ( V_2 , L_22 , V_68 , V_80 -> V_68 ) ;
return;
}
F_12 ( & V_24 -> V_37 ) ;
V_31 = F_56 ( & V_24 -> V_33 , V_80 -> V_60 ) ;
F_14 ( & V_24 -> V_37 ) ;
if ( V_31 && V_31 -> V_25 )
V_31 -> V_25 ( V_31 -> V_7 , V_80 -> V_57 , V_80 -> V_68 , V_31 -> V_26 , V_80 -> V_42 ) ;
else
F_55 ( V_2 , L_23 ) ;
F_51 ( & V_78 , V_80 , V_73 ) ;
V_28 = F_52 ( V_24 -> V_88 , & V_78 , 0 , 1 , V_80 , V_34 ) ;
if ( V_28 < 0 ) {
F_11 ( V_2 , L_24 , V_28 ) ;
return;
}
F_53 ( V_24 -> V_88 ) ;
}
static void F_57 ( struct V_87 * V_74 )
{
struct V_23 * V_24 = V_74 -> V_32 -> V_26 ;
F_49 ( & V_74 -> V_32 -> V_2 , L_25 , V_46 ) ;
F_58 ( & V_24 -> V_82 ) ;
}
static void F_59 ( struct V_6 * V_7 , void * V_57 , int V_68 ,
void * V_26 , T_3 V_42 )
{
struct V_49 * V_80 = V_57 ;
struct V_6 * V_89 ;
struct V_58 V_59 ;
struct V_23 * V_24 = V_26 ;
struct V_1 * V_2 = & V_24 -> V_32 -> V_2 ;
int V_62 ;
F_50 ( V_85 , L_26 ,
V_86 , 16 , 1 ,
V_57 , V_68 , true ) ;
if ( V_68 != sizeof( * V_80 ) ) {
F_11 ( V_2 , L_27 , V_68 ) ;
return;
}
if ( V_7 ) {
F_11 ( V_2 , L_28 ) ;
return;
}
V_80 -> V_10 [ V_12 - 1 ] = '\0' ;
F_60 ( V_2 , L_29 ,
V_80 -> V_51 & V_54 ? L_30 : L_31 ,
V_80 -> V_10 , V_80 -> V_27 ) ;
strncpy ( V_59 . V_10 , V_80 -> V_10 , sizeof( V_59 . V_10 ) ) ;
V_59 . V_42 = V_35 ;
V_59 . V_60 = V_80 -> V_27 ;
if ( V_80 -> V_51 & V_54 ) {
V_62 = F_36 ( V_24 , & V_59 ) ;
if ( V_62 )
F_11 ( V_2 , L_32 , V_62 ) ;
} else {
V_89 = F_30 ( V_24 , & V_59 ) ;
if ( ! V_89 )
F_11 ( V_2 , L_33 ) ;
}
}
static int F_61 ( struct V_66 * V_32 )
{
T_4 * V_90 [] = { F_54 , F_57 } ;
const char * V_91 [] = { L_34 , L_35 } ;
struct V_87 * V_92 [ 2 ] ;
struct V_23 * V_24 ;
void * V_93 ;
int V_28 = 0 , V_19 ;
V_24 = F_10 ( sizeof( * V_24 ) , V_34 ) ;
if ( ! V_24 )
return - V_43 ;
V_24 -> V_32 = V_32 ;
F_62 ( & V_24 -> V_33 ) ;
F_63 ( & V_24 -> V_37 ) ;
F_63 ( & V_24 -> V_69 ) ;
F_64 ( & V_24 -> V_82 ) ;
V_28 = V_32 -> V_94 -> V_95 ( V_32 , 2 , V_92 , V_90 , V_91 ) ;
if ( V_28 )
goto V_96;
V_24 -> V_88 = V_92 [ 0 ] ;
V_24 -> V_74 = V_92 [ 1 ] ;
V_93 = F_65 ( V_32 -> V_2 . V_64 , V_97 ,
& V_24 -> V_98 , V_34 ) ;
if ( ! V_93 )
goto V_99;
F_49 ( & V_32 -> V_2 , L_36 , V_93 ,
( unsigned long long ) V_24 -> V_98 ) ;
V_24 -> V_100 = V_93 ;
V_24 -> V_72 = V_93 + V_97 / 2 ;
for ( V_19 = 0 ; V_19 < V_71 / 2 ; V_19 ++ ) {
struct V_77 V_78 ;
void * V_101 = V_24 -> V_100 + V_19 * V_73 ;
F_51 ( & V_78 , V_101 , V_73 ) ;
V_28 = F_52 ( V_24 -> V_88 , & V_78 , 0 , 1 , V_101 ,
V_34 ) ;
F_66 ( V_28 < 0 ) ;
}
F_45 ( V_24 -> V_74 ) ;
V_32 -> V_26 = V_24 ;
if ( F_21 ( V_32 , V_48 ) ) {
V_24 -> V_102 = F_8 ( V_24 , NULL , F_59 ,
V_24 , V_53 ) ;
if ( ! V_24 -> V_102 ) {
F_11 ( & V_32 -> V_2 , L_37 ) ;
V_28 = - V_43 ;
goto V_103;
}
}
F_53 ( V_24 -> V_88 ) ;
F_60 ( & V_32 -> V_2 , L_38 ) ;
return 0 ;
V_103:
F_67 ( V_32 -> V_2 . V_64 , V_97 , V_93 ,
V_24 -> V_98 ) ;
V_99:
V_32 -> V_94 -> V_104 ( V_24 -> V_32 ) ;
V_96:
F_16 ( V_24 ) ;
return V_28 ;
}
static int F_68 ( struct V_1 * V_2 , void * V_57 )
{
F_37 ( V_2 ) ;
return 0 ;
}
static void T_5 F_69 ( struct V_66 * V_32 )
{
struct V_23 * V_24 = V_32 -> V_26 ;
int V_62 ;
V_32 -> V_94 -> V_105 ( V_32 ) ;
V_62 = F_70 ( & V_32 -> V_2 , NULL , F_68 ) ;
if ( V_62 )
F_55 ( & V_32 -> V_2 , L_39 , V_62 ) ;
if ( V_24 -> V_102 )
F_18 ( V_24 , V_24 -> V_102 ) ;
F_71 ( & V_24 -> V_33 ) ;
F_72 ( & V_24 -> V_33 ) ;
V_32 -> V_94 -> V_104 ( V_24 -> V_32 ) ;
F_67 ( V_32 -> V_2 . V_64 , V_97 ,
V_24 -> V_100 , V_24 -> V_98 ) ;
F_16 ( V_24 ) ;
}
static int T_6 F_73 ( void )
{
int V_62 ;
V_62 = F_74 ( & V_56 ) ;
if ( V_62 ) {
F_33 ( L_40 , V_62 ) ;
return V_62 ;
}
V_62 = F_75 ( & V_106 ) ;
if ( V_62 ) {
F_33 ( L_41 , V_62 ) ;
F_76 ( & V_56 ) ;
}
return V_62 ;
}
static void T_7 F_77 ( void )
{
F_78 ( & V_106 ) ;
F_76 ( & V_56 ) ;
}
