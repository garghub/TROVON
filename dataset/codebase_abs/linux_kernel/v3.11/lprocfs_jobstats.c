static unsigned F_1 ( T_1 * V_1 , const void * V_2 , unsigned V_3 )
{
return F_2 ( V_2 , strlen ( V_2 ) , V_3 ) ;
}
static void * F_3 ( struct V_4 * V_5 )
{
struct V_6 * V_7 ;
V_7 = F_4 ( V_5 , struct V_6 , V_8 ) ;
return V_7 -> V_9 ;
}
static int F_5 ( const void * V_2 , struct V_4 * V_5 )
{
struct V_6 * V_7 ;
V_7 = F_4 ( V_5 , struct V_6 , V_8 ) ;
return ( strlen ( V_7 -> V_9 ) == strlen ( V_2 ) ) &&
! strncmp ( V_7 -> V_9 , V_2 , strlen ( V_2 ) ) ;
}
static void * F_6 ( struct V_4 * V_5 )
{
return F_4 ( V_5 , struct V_6 , V_8 ) ;
}
static void F_7 ( T_1 * V_1 , struct V_4 * V_5 )
{
struct V_6 * V_7 ;
V_7 = F_4 ( V_5 , struct V_6 , V_8 ) ;
F_8 ( & V_7 -> V_10 ) ;
}
static void F_9 ( struct V_6 * V_7 )
{
F_10 ( F_11 ( & V_7 -> V_10 ) == 0 ) ;
F_10 ( V_7 -> V_11 ) ;
F_12 ( & V_7 -> V_11 -> V_12 ) ;
F_13 ( & V_7 -> V_13 ) ;
F_14 ( & V_7 -> V_11 -> V_12 ) ;
F_15 ( & V_7 -> V_14 ) ;
F_16 ( V_7 ) ;
}
static void F_17 ( struct V_6 * V_7 )
{
F_10 ( F_11 ( & V_7 -> V_10 ) > 0 ) ;
if ( F_18 ( & V_7 -> V_10 ) )
F_9 ( V_7 ) ;
}
static void F_19 ( T_1 * V_1 , struct V_4 * V_5 )
{
struct V_6 * V_7 ;
V_7 = F_4 ( V_5 , struct V_6 , V_8 ) ;
F_17 ( V_7 ) ;
}
static void F_20 ( T_1 * V_1 , struct V_4 * V_5 )
{
F_21 ( L_1 ) ;
}
static int F_22 ( T_1 * V_1 , T_2 * V_15 ,
struct V_4 * V_5 , void * V_16 )
{
T_3 V_17 = * ( ( T_3 * ) V_16 ) ;
struct V_6 * V_7 ;
V_7 = F_4 ( V_5 , struct V_6 , V_8 ) ;
if ( ! V_17 || V_7 -> V_18 < V_17 )
F_23 ( V_1 , V_15 , V_5 ) ;
return 0 ;
}
static void F_24 ( struct V_19 * V_20 , bool V_21 )
{
T_3 V_17 , V_22 ;
if ( V_20 -> V_23 == 0 )
return;
V_22 = F_25 () ;
if ( ! V_21 && V_22 < V_20 -> V_24 +
V_20 -> V_23 )
return;
V_17 = V_22 - V_20 -> V_23 ;
F_26 ( V_20 -> V_25 , F_22 ,
& V_17 ) ;
V_20 -> V_24 = F_25 () ;
}
static struct V_6 * F_27 ( char * V_26 , struct V_19 * V_27 )
{
struct V_6 * V_7 ;
F_10 ( V_27 -> V_28 && V_27 -> V_29 ) ;
F_28 ( V_7 ) ;
if ( V_7 == NULL )
return NULL ;
V_7 -> V_14 = F_29 ( V_27 -> V_28 , 0 ) ;
if ( V_7 -> V_14 == NULL ) {
F_16 ( V_7 ) ;
return NULL ;
}
V_27 -> V_29 ( V_7 -> V_14 ) ;
memcpy ( V_7 -> V_9 , V_26 , V_30 ) ;
V_7 -> V_18 = F_25 () ;
V_7 -> V_11 = V_27 ;
F_30 ( & V_7 -> V_8 ) ;
F_31 ( & V_7 -> V_13 ) ;
F_32 ( & V_7 -> V_10 , 1 ) ;
return V_7 ;
}
int F_33 ( struct V_31 * V_32 , char * V_26 ,
int V_33 , long V_34 )
{
struct V_19 * V_20 = & V_32 -> V_35 . V_36 . V_37 ;
struct V_6 * V_7 , * V_38 ;
V_39 ;
F_10 ( V_20 && V_20 -> V_25 ) ;
F_24 ( V_20 , false ) ;
if ( ! V_26 || ! strlen ( V_26 ) )
RETURN ( - V_40 ) ;
if ( strlen ( V_26 ) >= V_30 ) {
F_21 ( L_2 ,
( unsigned long ) strlen ( V_26 ) + 1 , V_30 ) ;
RETURN ( - V_40 ) ;
}
V_7 = F_34 ( V_20 -> V_25 , V_26 ) ;
if ( V_7 )
goto V_41;
V_7 = F_27 ( V_26 , V_20 ) ;
if ( V_7 == NULL )
RETURN ( - V_42 ) ;
V_38 = F_35 ( V_20 -> V_25 , V_7 -> V_9 ,
& V_7 -> V_8 ) ;
if ( V_38 != V_7 ) {
F_17 ( V_7 ) ;
V_7 = V_38 ;
} else {
F_10 ( F_36 ( & V_7 -> V_13 ) ) ;
F_12 ( & V_20 -> V_12 ) ;
F_37 ( & V_7 -> V_13 , & V_20 -> V_43 ) ;
F_14 ( & V_20 -> V_12 ) ;
}
V_41:
F_10 ( V_20 == V_7 -> V_11 ) ;
F_10 ( V_20 -> V_28 > V_33 ) ;
V_7 -> V_18 = F_25 () ;
F_38 ( V_7 -> V_14 , V_33 , V_34 ) ;
F_17 ( V_7 ) ;
RETURN ( 0 ) ;
}
void F_39 ( struct V_31 * V_32 )
{
struct V_19 * V_20 = & V_32 -> V_35 . V_36 . V_37 ;
T_3 V_17 = 0 ;
if ( V_20 -> V_25 == NULL )
return;
F_26 ( V_20 -> V_25 , F_22 , & V_17 ) ;
F_40 ( V_20 -> V_25 ) ;
V_20 -> V_25 = NULL ;
F_10 ( F_36 ( & V_20 -> V_43 ) ) ;
}
static void * F_41 ( struct V_44 * V_45 , T_4 * V_46 )
{
struct V_19 * V_20 = V_45 -> V_47 ;
T_4 V_48 = * V_46 ;
struct V_6 * V_7 ;
F_42 ( & V_20 -> V_12 ) ;
if ( V_48 == 0 )
return V_49 ;
V_48 -- ;
F_43 (job, &stats->ojs_list, js_list) {
if ( ! V_48 -- )
return V_7 ;
}
return NULL ;
}
static void F_44 ( struct V_44 * V_45 , void * V_50 )
{
struct V_19 * V_20 = V_45 -> V_47 ;
F_45 ( & V_20 -> V_12 ) ;
}
static void * F_46 ( struct V_44 * V_45 , void * V_50 , T_4 * V_46 )
{
struct V_19 * V_20 = V_45 -> V_47 ;
struct V_6 * V_7 ;
struct V_51 * V_52 ;
++ * V_46 ;
if ( V_50 == V_49 ) {
V_52 = V_20 -> V_43 . V_52 ;
} else {
V_7 = (struct V_6 * ) V_50 ;
V_52 = V_7 -> V_13 . V_52 ;
}
return V_52 == & V_20 -> V_43 ? NULL :
F_47 ( V_52 , struct V_6 , V_13 ) ;
}
static int inline F_48 ( const char * V_53 , int V_54 )
{
return V_54 - F_49 ( ( int ) strlen ( V_53 ) , 15 ) ;
}
static int F_50 ( struct V_44 * V_45 , void * V_50 )
{
struct V_6 * V_7 = V_50 ;
struct V_55 * V_56 ;
struct V_57 V_58 ;
struct V_57 * V_59 ;
struct V_60 * V_61 ;
int V_62 ;
if ( V_50 == V_49 ) {
F_51 ( V_45 , L_3 ) ;
return 0 ;
}
F_51 ( V_45 , L_4 , L_5 , V_7 -> V_9 ) ;
F_51 ( V_45 , L_6 , L_7 , V_7 -> V_18 ) ;
V_56 = V_7 -> V_14 ;
for ( V_62 = 0 ; V_62 < V_56 -> V_63 ; V_62 ++ ) {
V_59 = F_52 ( V_56 , 0 , V_62 ) ;
V_61 = & V_56 -> V_64 [ V_62 ] ;
F_53 ( V_56 , V_62 , & V_58 ) ;
F_51 ( V_45 , L_8 V_65 L_9 ,
V_61 -> V_66 ,
F_48 ( V_61 -> V_66 , 15 ) , V_67 ,
V_58 . V_68 ) ;
if ( V_61 -> V_69 [ 0 ] != '\0' )
F_51 ( V_45 , L_10 , V_61 -> V_69 ) ;
if ( V_61 -> V_70 & V_71 ) {
F_51 ( V_45 , L_11 V_65 L_12 V_65 L_13
L_14 V_65 L_9 ,
V_58 . V_68 ? V_58 . V_72 : 0 ,
V_58 . V_68 ? V_58 . V_73 : 0 ,
V_58 . V_68 ? V_58 . V_74 : 0 ) ;
}
if ( V_61 -> V_70 & V_75 ) {
F_51 ( V_45 , L_15 V_65 L_9 ,
V_58 . V_68 ? V_58 . V_76 : 0 ) ;
}
F_51 ( V_45 , L_16 ) ;
}
return 0 ;
}
static int F_54 ( struct V_77 * V_77 , struct V_78 * V_78 )
{
struct V_44 * V_79 ;
int V_80 ;
V_80 = F_55 ( V_78 , & V_81 ) ;
if ( V_80 )
return V_80 ;
V_79 = V_78 -> V_82 ;
V_79 -> V_47 = F_56 ( V_77 ) ;
return 0 ;
}
static T_5 F_57 ( struct V_78 * V_78 , const char * V_83 ,
T_6 V_54 , T_4 * V_48 )
{
struct V_44 * V_79 = V_78 -> V_82 ;
struct V_19 * V_20 = V_79 -> V_47 ;
char V_26 [ V_30 ] ;
int V_84 = 0 ;
struct V_6 * V_7 ;
if ( ! memcmp ( V_83 , L_17 , strlen ( L_17 ) ) ) {
V_84 = 1 ;
} else if ( V_54 < V_30 ) {
memset ( V_26 , 0 , V_30 ) ;
if ( V_83 [ V_54 - 1 ] == '\n' )
memcpy ( V_26 , V_83 , V_54 - 1 ) ;
else
memcpy ( V_26 , V_83 , V_54 ) ;
} else {
return - V_40 ;
}
F_10 ( V_20 -> V_25 ) ;
if ( V_84 ) {
T_3 V_17 = 0 ;
F_26 ( V_20 -> V_25 , F_22 ,
& V_17 ) ;
return V_54 ;
}
if ( ! strlen ( V_26 ) )
return - V_40 ;
V_7 = F_34 ( V_20 -> V_25 , V_26 ) ;
if ( ! V_7 )
return - V_40 ;
F_58 ( V_20 -> V_25 , V_26 ) ;
F_17 ( V_7 ) ;
return V_54 ;
}
int F_59 ( struct V_31 * V_32 , int V_85 ,
T_7 V_86 )
{
struct V_87 * V_88 ;
struct V_19 * V_20 ;
V_39 ;
F_10 ( V_32 -> V_89 != NULL ) ;
F_10 ( V_32 -> V_90 -> V_91 ) ;
if ( strcmp ( V_32 -> V_90 -> V_91 , V_92 ) &&
strcmp ( V_32 -> V_90 -> V_91 , V_93 ) ) {
F_21 ( L_18 ) ;
RETURN ( - V_40 ) ;
}
V_20 = & V_32 -> V_35 . V_36 . V_37 ;
F_10 ( V_20 -> V_25 == NULL ) ;
V_20 -> V_25 = F_60 ( L_19 ,
V_94 ,
V_95 ,
V_96 , 0 ,
V_97 ,
V_98 ,
& V_99 ,
V_100 ) ;
if ( V_20 -> V_25 == NULL )
RETURN ( - V_42 ) ;
F_31 ( & V_20 -> V_43 ) ;
F_61 ( & V_20 -> V_12 ) ;
V_20 -> V_28 = V_85 ;
V_20 -> V_29 = V_86 ;
V_20 -> V_23 = 600 ;
V_20 -> V_24 = F_25 () ;
V_88 = F_62 ( L_20 , 0644 , V_32 -> V_89 ,
& V_101 , V_20 ) ;
if ( V_88 )
RETURN ( 0 ) ;
else
RETURN ( - V_42 ) ;
}
int F_63 ( struct V_44 * V_102 , void * V_16 )
{
struct V_31 * V_32 = (struct V_31 * ) V_16 ;
struct V_19 * V_20 ;
F_10 ( V_32 != NULL ) ;
V_20 = & V_32 -> V_35 . V_36 . V_37 ;
return F_51 ( V_102 , L_21 , V_20 -> V_23 ) ;
}
int F_64 ( struct V_78 * V_78 , const char * V_103 ,
unsigned long V_104 , void * V_16 )
{
struct V_31 * V_32 = (struct V_31 * ) V_16 ;
struct V_19 * V_20 ;
int V_105 , V_80 ;
F_10 ( V_32 != NULL ) ;
V_20 = & V_32 -> V_35 . V_36 . V_37 ;
V_80 = F_65 ( V_103 , V_104 , & V_105 ) ;
if ( V_80 )
return V_80 ;
V_20 -> V_23 = V_105 ;
F_24 ( V_20 , true ) ;
return V_104 ;
}
