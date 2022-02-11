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
if ( ! V_2 -> V_19 ) {
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
F_14 ( & V_2 -> V_32 ) ;
F_15 ( & V_6 -> V_33 ) ;
F_2 ( V_6 , V_2 ) ;
F_16 ( & V_6 -> V_33 ) ;
return V_2 ;
V_29:
V_17 -> V_24 -> free ( V_2 ) ;
V_27:
F_17 ( V_2 ) ;
return F_10 ( V_21 ) ;
}
void F_18 ( struct V_1 * V_2 )
{
if ( F_19 ( V_2 -> V_34 > 0 ) )
V_2 -> V_17 -> V_24 -> V_35 ( V_2 -> V_17 , V_2 ) ;
V_2 -> V_17 -> V_24 -> free ( V_2 ) ;
F_17 ( V_2 ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = V_2 -> V_17 ;
struct V_5 * V_6 = V_2 -> V_6 ;
F_15 ( & V_6 -> V_33 ) ;
F_21 ( & V_2 -> V_12 , & V_6 -> V_9 ) ;
F_16 ( & V_6 -> V_33 ) ;
if ( V_17 -> V_3 & V_26 )
F_22 ( V_17 , V_2 ) ;
else
F_18 ( V_2 ) ;
}
static void * F_23 ( struct V_1 * V_2 )
{
void * V_36 ;
if ( V_2 -> V_34 ) {
V_2 -> V_34 ++ ;
return V_2 -> V_36 ;
}
V_36 = V_2 -> V_17 -> V_24 -> V_37 ( V_2 -> V_17 , V_2 ) ;
if ( F_12 ( ! V_36 ,
L_3 ) )
return F_10 ( - V_28 ) ;
if ( F_24 ( V_36 ) )
return V_36 ;
V_2 -> V_36 = V_36 ;
V_2 -> V_34 ++ ;
return V_36 ;
}
static void F_25 ( struct V_1 * V_2 )
{
V_2 -> V_34 -- ;
if ( ! V_2 -> V_34 ) {
V_2 -> V_17 -> V_24 -> V_35 ( V_2 -> V_17 , V_2 ) ;
V_2 -> V_36 = NULL ;
}
}
static struct V_19 * F_26 ( struct V_19 * V_20 )
{
struct V_19 * V_38 ;
int V_21 , V_39 ;
struct V_40 * V_41 , * V_42 ;
V_38 = F_9 ( sizeof( * V_38 ) , V_22 ) ;
if ( ! V_38 )
return F_10 ( - V_23 ) ;
V_21 = F_27 ( V_38 , V_20 -> V_43 , V_22 ) ;
if ( V_21 ) {
F_17 ( V_38 ) ;
return F_10 ( - V_23 ) ;
}
V_42 = V_38 -> V_44 ;
F_28 (table->sgl, sg, table->nents, i) {
memcpy ( V_42 , V_41 , sizeof( * V_41 ) ) ;
V_41 -> V_45 = 0 ;
V_42 = F_29 ( V_42 ) ;
}
return V_38 ;
}
static void F_30 ( struct V_19 * V_20 )
{
F_31 ( V_20 ) ;
F_17 ( V_20 ) ;
}
static int F_32 ( struct V_46 * V_47 , struct V_48 * V_6 ,
struct V_49 * V_50 )
{
struct V_51 * V_52 ;
struct V_19 * V_20 ;
struct V_1 * V_2 = V_47 -> V_53 ;
V_52 = F_9 ( sizeof( * V_52 ) , V_22 ) ;
if ( ! V_52 )
return - V_23 ;
V_20 = F_26 ( V_2 -> V_19 ) ;
if ( F_24 ( V_20 ) ) {
F_17 ( V_52 ) ;
return - V_23 ;
}
V_52 -> V_20 = V_20 ;
V_52 -> V_6 = V_6 ;
F_13 ( & V_52 -> V_54 ) ;
V_50 -> V_53 = V_52 ;
F_15 ( & V_2 -> V_32 ) ;
F_33 ( & V_52 -> V_54 , & V_2 -> V_31 ) ;
F_16 ( & V_2 -> V_32 ) ;
return 0 ;
}
static void F_34 ( struct V_46 * V_47 ,
struct V_49 * V_50 )
{
struct V_51 * V_52 = V_50 -> V_53 ;
struct V_1 * V_2 = V_47 -> V_53 ;
F_30 ( V_52 -> V_20 ) ;
F_15 ( & V_2 -> V_32 ) ;
F_35 ( & V_52 -> V_54 ) ;
F_16 ( & V_2 -> V_32 ) ;
F_17 ( V_52 ) ;
}
static struct V_19 * F_36 ( struct V_49 * V_50 ,
enum V_55 V_56 )
{
struct V_51 * V_52 = V_50 -> V_53 ;
struct V_19 * V_20 ;
V_20 = V_52 -> V_20 ;
if ( ! F_37 ( V_50 -> V_6 , V_20 -> V_44 , V_20 -> V_43 ,
V_56 ) )
return F_10 ( - V_23 ) ;
return V_20 ;
}
static void F_38 ( struct V_49 * V_50 ,
struct V_19 * V_20 ,
enum V_55 V_56 )
{
F_39 ( V_50 -> V_6 , V_20 -> V_44 , V_20 -> V_43 , V_56 ) ;
}
static int F_40 ( struct V_46 * V_47 , struct V_57 * V_58 )
{
struct V_1 * V_2 = V_47 -> V_53 ;
int V_21 = 0 ;
if ( ! V_2 -> V_17 -> V_24 -> V_59 ) {
F_4 ( L_4 ,
V_15 ) ;
return - V_28 ;
}
if ( ! ( V_2 -> V_3 & V_4 ) )
V_58 -> V_60 = F_41 ( V_58 -> V_60 ) ;
F_15 ( & V_2 -> V_32 ) ;
V_21 = V_2 -> V_17 -> V_24 -> V_59 ( V_2 -> V_17 , V_2 , V_58 ) ;
F_16 ( & V_2 -> V_32 ) ;
if ( V_21 )
F_4 ( L_5 ,
V_15 ) ;
return V_21 ;
}
static void F_42 ( struct V_46 * V_47 )
{
struct V_1 * V_2 = V_47 -> V_53 ;
F_20 ( V_2 ) ;
}
static void * F_43 ( struct V_46 * V_47 , unsigned long V_61 )
{
struct V_1 * V_2 = V_47 -> V_53 ;
return V_2 -> V_36 + V_61 * V_62 ;
}
static void F_44 ( struct V_46 * V_47 , unsigned long V_61 ,
void * V_63 )
{
}
static int F_45 ( struct V_46 * V_47 ,
enum V_55 V_56 )
{
struct V_1 * V_2 = V_47 -> V_53 ;
void * V_36 ;
struct V_51 * V_52 ;
if ( V_2 -> V_17 -> V_24 -> V_37 ) {
F_15 ( & V_2 -> V_32 ) ;
V_36 = F_23 ( V_2 ) ;
F_16 ( & V_2 -> V_32 ) ;
}
F_15 ( & V_2 -> V_32 ) ;
F_46 (a, &buffer->attachments, list) {
F_47 ( V_52 -> V_6 , V_52 -> V_20 -> V_44 , V_52 -> V_20 -> V_43 ,
V_64 ) ;
}
F_16 ( & V_2 -> V_32 ) ;
return 0 ;
}
static int F_48 ( struct V_46 * V_47 ,
enum V_55 V_56 )
{
struct V_1 * V_2 = V_47 -> V_53 ;
struct V_51 * V_52 ;
if ( V_2 -> V_17 -> V_24 -> V_37 ) {
F_15 ( & V_2 -> V_32 ) ;
F_25 ( V_2 ) ;
F_16 ( & V_2 -> V_32 ) ;
}
F_15 ( & V_2 -> V_32 ) ;
F_46 (a, &buffer->attachments, list) {
F_49 ( V_52 -> V_6 , V_52 -> V_20 -> V_44 , V_52 -> V_20 -> V_43 ,
V_64 ) ;
}
F_16 ( & V_2 -> V_32 ) ;
return 0 ;
}
int F_50 ( T_1 V_18 , unsigned int V_65 , unsigned int V_3 )
{
struct V_5 * V_6 = V_66 ;
struct V_1 * V_2 = NULL ;
struct V_16 * V_17 ;
F_51 ( V_67 ) ;
int V_68 ;
struct V_46 * V_47 ;
F_52 ( L_6 , V_15 ,
V_18 , V_65 , V_3 ) ;
V_18 = F_53 ( V_18 ) ;
if ( ! V_18 )
return - V_28 ;
F_54 ( & V_6 -> V_32 ) ;
F_55 (heap, &dev->heaps, node) {
if ( ! ( ( 1 << V_17 -> V_69 ) & V_65 ) )
continue;
V_2 = F_8 ( V_17 , V_6 , V_18 , V_3 ) ;
if ( ! F_24 ( V_2 ) )
break;
}
F_56 ( & V_6 -> V_32 ) ;
if ( ! V_2 )
return - V_70 ;
if ( F_24 ( V_2 ) )
return F_57 ( V_2 ) ;
V_67 . V_24 = & V_71 ;
V_67 . V_30 = V_2 -> V_30 ;
V_67 . V_3 = V_72 ;
V_67 . V_53 = V_2 ;
V_47 = F_58 ( & V_67 ) ;
if ( F_24 ( V_47 ) ) {
F_20 ( V_2 ) ;
return F_57 ( V_47 ) ;
}
V_68 = F_59 ( V_47 , V_73 ) ;
if ( V_68 < 0 )
F_60 ( V_47 ) ;
return V_68 ;
}
int F_61 ( struct V_74 * V_75 )
{
struct V_5 * V_6 = V_66 ;
struct V_76 T_2 * V_2 = F_62 ( V_75 -> V_77 ) ;
int V_21 = - V_28 , V_78 = 0 , V_79 ;
struct V_16 * V_17 ;
struct V_76 V_80 ;
memset ( & V_80 , 0 , sizeof( V_80 ) ) ;
F_54 ( & V_6 -> V_32 ) ;
if ( ! V_2 ) {
V_75 -> V_78 = V_6 -> V_81 ;
V_21 = 0 ;
goto V_82;
}
if ( V_75 -> V_78 <= 0 )
goto V_82;
V_79 = V_75 -> V_78 ;
F_55 (heap, &dev->heaps, node) {
strncpy ( V_80 . V_83 , V_17 -> V_83 , V_84 ) ;
V_80 . V_83 [ sizeof( V_80 . V_83 ) - 1 ] = '\0' ;
V_80 . type = V_17 -> type ;
V_80 . V_85 = V_17 -> V_69 ;
if ( F_63 ( & V_2 [ V_78 ] , & V_80 , sizeof( V_80 ) ) ) {
V_21 = - V_86 ;
goto V_82;
}
V_78 ++ ;
if ( V_78 >= V_79 )
break;
}
V_75 -> V_78 = V_78 ;
V_21 = 0 ;
V_82:
F_56 ( & V_6 -> V_32 ) ;
return V_21 ;
}
static int F_64 ( void * V_87 , T_3 V_88 )
{
struct V_16 * V_17 = V_87 ;
struct V_89 V_90 ;
int V_91 ;
V_90 . V_92 = V_93 ;
V_90 . V_94 = V_88 ;
if ( ! V_88 ) {
V_91 = V_17 -> V_95 . V_96 ( & V_17 -> V_95 , & V_90 ) ;
V_90 . V_94 = V_91 ;
}
V_17 -> V_95 . V_97 ( & V_17 -> V_95 , & V_90 ) ;
return 0 ;
}
static int F_65 ( void * V_87 , T_3 * V_88 )
{
struct V_16 * V_17 = V_87 ;
struct V_89 V_90 ;
int V_91 ;
V_90 . V_92 = V_93 ;
V_90 . V_94 = 0 ;
V_91 = V_17 -> V_95 . V_96 ( & V_17 -> V_95 , & V_90 ) ;
* V_88 = V_91 ;
return 0 ;
}
void F_66 ( struct V_16 * V_17 )
{
struct V_98 * V_99 ;
struct V_5 * V_6 = V_66 ;
if ( ! V_17 -> V_24 -> V_25 || ! V_17 -> V_24 -> free )
F_4 ( L_7 ,
V_15 ) ;
F_67 ( & V_17 -> V_100 ) ;
V_17 -> V_101 = 0 ;
if ( V_17 -> V_3 & V_26 )
F_68 ( V_17 ) ;
if ( ( V_17 -> V_3 & V_26 ) || V_17 -> V_24 -> V_102 )
F_69 ( V_17 ) ;
V_17 -> V_6 = V_6 ;
F_70 ( & V_6 -> V_32 ) ;
V_17 -> V_69 = V_85 ++ ;
F_71 ( & V_17 -> V_12 , - V_17 -> V_69 ) ;
F_72 ( & V_17 -> V_12 , & V_6 -> V_77 ) ;
if ( V_17 -> V_95 . V_96 && V_17 -> V_95 . V_97 ) {
char V_103 [ 64 ] ;
snprintf ( V_103 , 64 , L_8 , V_17 -> V_83 ) ;
V_99 = F_73 (
V_103 , 0644 , V_6 -> V_104 , V_17 ,
& V_105 ) ;
if ( ! V_99 ) {
char V_106 [ 256 ] , * V_107 ;
V_107 = F_74 ( V_6 -> V_104 , V_106 , 256 ) ;
F_4 ( L_9 ,
V_107 , V_103 ) ;
}
}
V_6 -> V_81 ++ ;
F_75 ( & V_6 -> V_32 ) ;
}
static int F_76 ( void )
{
struct V_5 * V_108 ;
int V_21 ;
V_108 = F_9 ( sizeof( * V_108 ) , V_22 ) ;
if ( ! V_108 )
return - V_23 ;
V_108 -> V_6 . V_109 = V_110 ;
V_108 -> V_6 . V_83 = L_10 ;
V_108 -> V_6 . V_111 = & V_112 ;
V_108 -> V_6 . V_10 = NULL ;
V_21 = F_77 ( & V_108 -> V_6 ) ;
if ( V_21 ) {
F_4 ( L_11 ) ;
F_17 ( V_108 ) ;
return V_21 ;
}
V_108 -> V_104 = F_78 ( L_10 , NULL ) ;
if ( ! V_108 -> V_104 ) {
F_4 ( L_12 ) ;
goto V_113;
}
V_113:
V_108 -> V_9 = V_114 ;
F_14 ( & V_108 -> V_33 ) ;
F_79 ( & V_108 -> V_32 ) ;
F_80 ( & V_108 -> V_77 ) ;
V_66 = V_108 ;
return 0 ;
}
