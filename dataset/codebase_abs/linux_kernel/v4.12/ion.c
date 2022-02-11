bool F_1 ( struct V_1 * V_2 )
{
return ! ! ( V_2 -> V_3 & V_4 ) ;
}
static void F_2 ( struct V_5 * V_6 ,
struct V_1 * V_2 )
{
struct V_7 * * V_8 = & V_6 -> V_9 . V_7 ;
struct V_7 * V_10 = NULL ;
struct V_1 * V_11 ;
while ( * V_8 ) {
V_10 = * V_8 ;
V_11 = F_3 ( V_10 , struct V_1 , V_12 ) ;
if ( V_2 < V_11 ) {
V_8 = & ( * V_8 ) -> V_13 ;
} else if ( V_2 > V_11 ) {
V_8 = & ( * V_8 ) -> V_14 ;
} else {
F_4 ( L_1 , V_15 ) ;
F_5 () ;
}
}
F_6 ( & V_2 -> V_12 , V_10 , V_8 ) ;
F_7 ( & V_2 -> V_12 , & V_6 -> V_9 ) ;
}
static struct V_1 * F_8 ( struct V_16 * V_17 ,
struct V_5 * V_6 ,
unsigned long V_18 ,
unsigned long V_3 )
{
struct V_1 * V_2 ;
struct V_19 * V_20 ;
int V_21 ;
V_2 = F_9 ( sizeof( * V_2 ) , V_22 ) ;
if ( ! V_2 )
return F_10 ( - V_23 ) ;
V_2 -> V_17 = V_17 ;
V_2 -> V_3 = V_3 ;
V_21 = V_17 -> V_24 -> V_25 ( V_17 , V_2 , V_18 , V_3 ) ;
if ( V_21 ) {
if ( ! ( V_17 -> V_3 & V_26 ) )
goto V_27;
F_11 ( V_17 , 0 ) ;
V_21 = V_17 -> V_24 -> V_25 ( V_17 , V_2 , V_18 , V_3 ) ;
if ( V_21 )
goto V_27;
}
if ( V_2 -> V_19 == NULL ) {
F_12 ( 1 , L_2 ) ;
V_21 = - V_28 ;
goto V_29;
}
V_20 = V_2 -> V_19 ;
V_2 -> V_6 = V_6 ;
V_2 -> V_30 = V_18 ;
V_2 -> V_6 = V_6 ;
V_2 -> V_30 = V_18 ;
F_13 ( & V_2 -> V_31 ) ;
F_13 ( & V_2 -> V_32 ) ;
F_14 ( & V_2 -> V_33 ) ;
F_15 ( & V_6 -> V_34 ) ;
F_2 ( V_6 , V_2 ) ;
F_16 ( & V_6 -> V_34 ) ;
return V_2 ;
V_29:
V_17 -> V_24 -> free ( V_2 ) ;
V_27:
F_17 ( V_2 ) ;
return F_10 ( V_21 ) ;
}
void F_18 ( struct V_1 * V_2 )
{
if ( F_19 ( V_2 -> V_35 > 0 ) )
V_2 -> V_17 -> V_24 -> V_36 ( V_2 -> V_17 , V_2 ) ;
V_2 -> V_17 -> V_24 -> free ( V_2 ) ;
F_20 ( V_2 -> V_37 ) ;
F_17 ( V_2 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = V_2 -> V_17 ;
struct V_5 * V_6 = V_2 -> V_6 ;
F_15 ( & V_6 -> V_34 ) ;
F_22 ( & V_2 -> V_12 , & V_6 -> V_9 ) ;
F_16 ( & V_6 -> V_34 ) ;
if ( V_17 -> V_3 & V_26 )
F_23 ( V_17 , V_2 ) ;
else
F_18 ( V_2 ) ;
}
static void * F_24 ( struct V_1 * V_2 )
{
void * V_38 ;
if ( V_2 -> V_35 ) {
V_2 -> V_35 ++ ;
return V_2 -> V_38 ;
}
V_38 = V_2 -> V_17 -> V_24 -> V_39 ( V_2 -> V_17 , V_2 ) ;
if ( F_12 ( V_38 == NULL ,
L_3 ) )
return F_10 ( - V_28 ) ;
if ( F_25 ( V_38 ) )
return V_38 ;
V_2 -> V_38 = V_38 ;
V_2 -> V_35 ++ ;
return V_38 ;
}
static void F_26 ( struct V_1 * V_2 )
{
V_2 -> V_35 -- ;
if ( ! V_2 -> V_35 ) {
V_2 -> V_17 -> V_24 -> V_36 ( V_2 -> V_17 , V_2 ) ;
V_2 -> V_38 = NULL ;
}
}
static struct V_19 * F_27 ( struct V_19 * V_20 )
{
struct V_19 * V_40 ;
int V_21 , V_41 ;
struct V_42 * V_43 , * V_44 ;
V_40 = F_9 ( sizeof( * V_40 ) , V_22 ) ;
if ( ! V_40 )
return F_10 ( - V_23 ) ;
V_21 = F_28 ( V_40 , V_20 -> V_45 , V_22 ) ;
if ( V_21 ) {
F_17 ( V_40 ) ;
return F_10 ( - V_23 ) ;
}
V_44 = V_40 -> V_46 ;
F_29 (table->sgl, sg, table->nents, i) {
memcpy ( V_44 , V_43 , sizeof( * V_43 ) ) ;
V_43 -> V_47 = 0 ;
V_44 = F_30 ( V_44 ) ;
}
return V_40 ;
}
static void F_31 ( struct V_19 * V_20 )
{
F_32 ( V_20 ) ;
F_17 ( V_20 ) ;
}
static int F_33 ( struct V_48 * V_49 , struct V_50 * V_6 ,
struct V_51 * V_52 )
{
struct V_53 * V_54 ;
struct V_19 * V_20 ;
struct V_1 * V_2 = V_49 -> V_55 ;
V_54 = F_9 ( sizeof( * V_54 ) , V_22 ) ;
if ( ! V_54 )
return - V_23 ;
V_20 = F_27 ( V_2 -> V_19 ) ;
if ( F_25 ( V_20 ) ) {
F_17 ( V_54 ) ;
return - V_23 ;
}
V_54 -> V_20 = V_20 ;
V_54 -> V_6 = V_6 ;
F_13 ( & V_54 -> V_56 ) ;
V_52 -> V_55 = V_54 ;
F_15 ( & V_2 -> V_33 ) ;
F_34 ( & V_54 -> V_56 , & V_2 -> V_32 ) ;
F_16 ( & V_2 -> V_33 ) ;
return 0 ;
}
static void F_35 ( struct V_48 * V_49 ,
struct V_51 * V_52 )
{
struct V_53 * V_54 = V_52 -> V_55 ;
struct V_1 * V_2 = V_49 -> V_55 ;
F_31 ( V_54 -> V_20 ) ;
F_15 ( & V_2 -> V_33 ) ;
F_36 ( & V_54 -> V_56 ) ;
F_16 ( & V_2 -> V_33 ) ;
F_17 ( V_54 ) ;
}
static struct V_19 * F_37 ( struct V_51 * V_52 ,
enum V_57 V_58 )
{
struct V_53 * V_54 = V_52 -> V_55 ;
struct V_19 * V_20 ;
int V_21 ;
V_20 = V_54 -> V_20 ;
if ( ! F_38 ( V_52 -> V_6 , V_20 -> V_46 , V_20 -> V_45 ,
V_58 ) ) {
V_21 = - V_23 ;
goto V_59;
}
return V_20 ;
V_59:
F_31 ( V_20 ) ;
return F_10 ( V_21 ) ;
}
static void F_39 ( struct V_51 * V_52 ,
struct V_19 * V_20 ,
enum V_57 V_58 )
{
F_40 ( V_52 -> V_6 , V_20 -> V_46 , V_20 -> V_45 , V_58 ) ;
}
static int F_41 ( struct V_48 * V_49 , struct V_60 * V_61 )
{
struct V_1 * V_2 = V_49 -> V_55 ;
int V_21 = 0 ;
if ( ! V_2 -> V_17 -> V_24 -> V_62 ) {
F_4 ( L_4 ,
V_15 ) ;
return - V_28 ;
}
if ( ! ( V_2 -> V_3 & V_4 ) )
V_61 -> V_63 = F_42 ( V_61 -> V_63 ) ;
F_15 ( & V_2 -> V_33 ) ;
V_21 = V_2 -> V_17 -> V_24 -> V_62 ( V_2 -> V_17 , V_2 , V_61 ) ;
F_16 ( & V_2 -> V_33 ) ;
if ( V_21 )
F_4 ( L_5 ,
V_15 ) ;
return V_21 ;
}
static void F_43 ( struct V_48 * V_49 )
{
struct V_1 * V_2 = V_49 -> V_55 ;
F_21 ( V_2 ) ;
}
static void * F_44 ( struct V_48 * V_49 , unsigned long V_64 )
{
struct V_1 * V_2 = V_49 -> V_55 ;
return V_2 -> V_38 + V_64 * V_65 ;
}
static void F_45 ( struct V_48 * V_49 , unsigned long V_64 ,
void * V_66 )
{
}
static int F_46 ( struct V_48 * V_49 ,
enum V_57 V_58 )
{
struct V_1 * V_2 = V_49 -> V_55 ;
void * V_38 ;
struct V_53 * V_54 ;
if ( V_2 -> V_17 -> V_24 -> V_39 ) {
F_15 ( & V_2 -> V_33 ) ;
V_38 = F_24 ( V_2 ) ;
F_16 ( & V_2 -> V_33 ) ;
}
F_15 ( & V_2 -> V_33 ) ;
F_47 (a, &buffer->attachments, list) {
F_48 ( V_54 -> V_6 , V_54 -> V_20 -> V_46 , V_54 -> V_20 -> V_45 ,
V_67 ) ;
}
F_16 ( & V_2 -> V_33 ) ;
return 0 ;
}
static int F_49 ( struct V_48 * V_49 ,
enum V_57 V_58 )
{
struct V_1 * V_2 = V_49 -> V_55 ;
struct V_53 * V_54 ;
if ( V_2 -> V_17 -> V_24 -> V_39 ) {
F_15 ( & V_2 -> V_33 ) ;
F_26 ( V_2 ) ;
F_16 ( & V_2 -> V_33 ) ;
}
F_15 ( & V_2 -> V_33 ) ;
F_47 (a, &buffer->attachments, list) {
F_50 ( V_54 -> V_6 , V_54 -> V_20 -> V_46 , V_54 -> V_20 -> V_45 ,
V_67 ) ;
}
F_16 ( & V_2 -> V_33 ) ;
return 0 ;
}
int F_51 ( T_1 V_18 , unsigned int V_68 , unsigned int V_3 )
{
struct V_5 * V_6 = V_69 ;
struct V_1 * V_2 = NULL ;
struct V_16 * V_17 ;
F_52 ( V_70 ) ;
int V_71 ;
struct V_48 * V_49 ;
F_53 ( L_6 , V_15 ,
V_18 , V_68 , V_3 ) ;
V_18 = F_54 ( V_18 ) ;
if ( ! V_18 )
return - V_28 ;
F_55 ( & V_6 -> V_33 ) ;
F_56 (heap, &dev->heaps, node) {
if ( ! ( ( 1 << V_17 -> V_72 ) & V_68 ) )
continue;
V_2 = F_8 ( V_17 , V_6 , V_18 , V_3 ) ;
if ( ! F_25 ( V_2 ) )
break;
}
F_57 ( & V_6 -> V_33 ) ;
if ( V_2 == NULL )
return - V_73 ;
if ( F_25 ( V_2 ) )
return F_58 ( V_2 ) ;
V_70 . V_24 = & V_74 ;
V_70 . V_30 = V_2 -> V_30 ;
V_70 . V_3 = V_75 ;
V_70 . V_55 = V_2 ;
V_49 = F_59 ( & V_70 ) ;
if ( F_25 ( V_49 ) ) {
F_21 ( V_2 ) ;
return F_58 ( V_49 ) ;
}
V_71 = F_60 ( V_49 , V_76 ) ;
if ( V_71 < 0 )
F_61 ( V_49 ) ;
return V_71 ;
}
int F_62 ( struct V_77 * V_78 )
{
struct V_5 * V_6 = V_69 ;
struct V_79 T_2 * V_2 = F_63 ( V_78 -> V_80 ) ;
int V_21 = - V_28 , V_81 = 0 , V_82 ;
struct V_16 * V_17 ;
struct V_79 V_83 ;
memset ( & V_83 , 0 , sizeof( V_83 ) ) ;
F_55 ( & V_6 -> V_33 ) ;
if ( ! V_2 ) {
V_78 -> V_81 = V_6 -> V_84 ;
V_21 = 0 ;
goto V_85;
}
if ( V_78 -> V_81 <= 0 )
goto V_85;
V_82 = V_78 -> V_81 ;
F_56 (heap, &dev->heaps, node) {
strncpy ( V_83 . V_86 , V_17 -> V_86 , V_87 ) ;
V_83 . V_86 [ sizeof( V_83 . V_86 ) - 1 ] = '\0' ;
V_83 . type = V_17 -> type ;
V_83 . V_88 = V_17 -> V_72 ;
if ( F_64 ( & V_2 [ V_81 ] , & V_83 , sizeof( V_83 ) ) ) {
V_21 = - V_89 ;
goto V_85;
}
V_81 ++ ;
if ( V_81 >= V_82 )
break;
}
V_78 -> V_81 = V_81 ;
V_21 = 0 ;
V_85:
F_57 ( & V_6 -> V_33 ) ;
return V_21 ;
}
static int F_65 ( void * V_90 , T_3 V_91 )
{
struct V_16 * V_17 = V_90 ;
struct V_92 V_93 ;
int V_94 ;
V_93 . V_95 = V_96 ;
V_93 . V_97 = V_91 ;
if ( ! V_91 ) {
V_94 = V_17 -> V_98 . V_99 ( & V_17 -> V_98 , & V_93 ) ;
V_93 . V_97 = V_94 ;
}
V_17 -> V_98 . V_100 ( & V_17 -> V_98 , & V_93 ) ;
return 0 ;
}
static int F_66 ( void * V_90 , T_3 * V_91 )
{
struct V_16 * V_17 = V_90 ;
struct V_92 V_93 ;
int V_94 ;
V_93 . V_95 = V_96 ;
V_93 . V_97 = 0 ;
V_94 = V_17 -> V_98 . V_99 ( & V_17 -> V_98 , & V_93 ) ;
* V_91 = V_94 ;
return 0 ;
}
void F_67 ( struct V_16 * V_17 )
{
struct V_101 * V_102 ;
struct V_5 * V_6 = V_69 ;
if ( ! V_17 -> V_24 -> V_25 || ! V_17 -> V_24 -> free )
F_4 ( L_7 ,
V_15 ) ;
F_68 ( & V_17 -> V_103 ) ;
V_17 -> V_104 = 0 ;
if ( V_17 -> V_3 & V_26 )
F_69 ( V_17 ) ;
if ( ( V_17 -> V_3 & V_26 ) || V_17 -> V_24 -> V_105 )
F_70 ( V_17 ) ;
V_17 -> V_6 = V_6 ;
F_71 ( & V_6 -> V_33 ) ;
V_17 -> V_72 = V_88 ++ ;
F_72 ( & V_17 -> V_12 , - V_17 -> V_72 ) ;
F_73 ( & V_17 -> V_12 , & V_6 -> V_80 ) ;
if ( V_17 -> V_98 . V_99 && V_17 -> V_98 . V_100 ) {
char V_106 [ 64 ] ;
snprintf ( V_106 , 64 , L_8 , V_17 -> V_86 ) ;
V_102 = F_74 (
V_106 , 0644 , V_6 -> V_107 , V_17 ,
& V_108 ) ;
if ( ! V_102 ) {
char V_109 [ 256 ] , * V_110 ;
V_110 = F_75 ( V_6 -> V_107 , V_109 , 256 ) ;
F_4 ( L_9 ,
V_110 , V_106 ) ;
}
}
V_6 -> V_84 ++ ;
F_76 ( & V_6 -> V_33 ) ;
}
int F_77 ( void )
{
struct V_5 * V_111 ;
int V_21 ;
V_111 = F_9 ( sizeof( * V_111 ) , V_22 ) ;
if ( ! V_111 )
return - V_23 ;
V_111 -> V_6 . V_112 = V_113 ;
V_111 -> V_6 . V_86 = L_10 ;
V_111 -> V_6 . V_114 = & V_115 ;
V_111 -> V_6 . V_10 = NULL ;
V_21 = F_78 ( & V_111 -> V_6 ) ;
if ( V_21 ) {
F_4 ( L_11 ) ;
F_17 ( V_111 ) ;
return V_21 ;
}
V_111 -> V_107 = F_79 ( L_10 , NULL ) ;
if ( ! V_111 -> V_107 ) {
F_4 ( L_12 ) ;
goto V_116;
}
V_116:
V_111 -> V_9 = V_117 ;
F_14 ( & V_111 -> V_34 ) ;
F_80 ( & V_111 -> V_33 ) ;
F_81 ( & V_111 -> V_80 ) ;
V_69 = V_111 ;
return 0 ;
}
