static T_1 F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
if ( ( V_2 -> V_4 - V_2 -> V_5 ) < 4 ) {
V_2 -> error = 1 ;
return 0 ;
}
V_3 = * ( ( T_1 * ) V_2 -> V_5 ) ;
V_2 -> V_5 += 4 ;
return V_3 ;
}
static const void * F_2 ( struct V_1 * V_2 , int V_6 )
{
const void * V_3 ;
if ( ( V_2 -> V_4 - V_2 -> V_5 ) < V_6 ) {
V_2 -> error = 1 ;
return NULL ;
}
V_3 = V_2 -> V_5 ;
V_2 -> V_5 += V_6 ;
return V_3 ;
}
static int F_3 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
T_2 V_9 = ( T_2 ) F_1 ( V_2 ) ;
int V_10 = ( int ) F_1 ( V_2 ) ;
T_2 V_11 = ( T_2 ) F_1 ( V_2 ) ;
F_4 ( L_1 ,
V_9 , V_10 , V_11 ) ;
F_5 ( V_12 , V_2 , V_8 , V_9 , V_10 , V_11 ) ;
}
static int F_6 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
T_1 V_13 = F_1 ( V_2 ) ;
T_1 V_3 = F_1 ( V_2 ) ;
T_1 V_9 = F_1 ( V_2 ) ;
F_4 ( L_2 ,
V_13 , V_3 , V_9 ) ;
F_5 ( V_14 , V_2 , V_8 , V_13 , V_3 , V_9 ) ;
}
static int F_7 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
T_1 V_13 = F_1 ( V_2 ) ;
F_4 ( L_3 , V_13 ) ;
F_5 ( V_15 , V_2 , V_8 , V_13 ) ;
}
static int F_8 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
T_1 V_13 = F_1 ( V_2 ) ;
T_3 V_3 = ( T_3 ) F_1 ( V_2 ) ;
T_3 V_9 = ( T_3 ) F_1 ( V_2 ) ;
F_4 ( L_4 ,
V_13 , V_3 , V_9 ) ;
F_5 ( V_16 , V_2 , V_8 , V_13 , V_3 , V_9 ) ;
}
static int F_9 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
T_1 V_13 = F_1 ( V_2 ) ;
F_4 ( L_5 , V_13 ) ;
F_5 ( V_17 , V_2 , V_8 , V_13 ) ;
}
static int F_10 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
T_1 V_13 = F_1 ( V_2 ) ;
T_2 V_3 = ( T_3 ) F_1 ( V_2 ) ;
T_2 V_9 = ( T_3 ) F_1 ( V_2 ) ;
F_4 ( L_6 ,
V_13 , V_3 , V_9 ) ;
F_5 ( V_18 , V_2 , V_8 , V_13 , V_3 , V_9 ) ;
}
static int F_11 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
T_1 V_13 = F_1 ( V_2 ) ;
F_4 ( L_7 , V_13 ) ;
F_5 ( V_19 , V_2 , V_8 , V_13 ) ;
}
static int F_12 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
T_1 V_20 = F_1 ( V_2 ) ;
F_4 ( L_8 , V_20 ) ;
F_5 ( V_21 , V_2 , V_8 , V_20 ) ;
}
static int F_13 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
T_1 V_13 = F_1 ( V_2 ) ;
T_1 V_3 = F_1 ( V_2 ) ;
T_1 V_9 = F_1 ( V_2 ) ;
F_4 ( L_9 ,
V_13 , V_3 , V_9 ) ;
F_5 ( V_22 , V_2 , V_8 , V_13 , V_3 , V_9 ) ;
}
static int F_14 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
T_1 V_13 = F_1 ( V_2 ) ;
T_3 V_3 = ( T_3 ) F_1 ( V_2 ) ;
T_3 V_9 = ( T_3 ) F_1 ( V_2 ) ;
F_4 ( L_10 ,
V_13 , V_3 , V_9 ) ;
F_5 ( V_23 , V_2 , V_8 , V_13 , V_3 , V_9 ) ;
}
static int F_15 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
T_1 V_13 = F_1 ( V_2 ) ;
T_2 V_3 = ( T_2 ) F_1 ( V_2 ) ;
T_2 V_9 = ( T_2 ) F_1 ( V_2 ) ;
F_4 ( L_11 ,
V_13 , V_3 , V_9 ) ;
F_5 ( V_24 , V_2 , V_8 , V_13 , V_3 , V_9 ) ;
}
static int F_16 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
T_1 V_25 = F_1 ( V_2 ) ;
F_4 ( L_12 , V_25 ) ;
F_5 ( V_26 , V_2 , V_8 , V_25 ) ;
}
static int F_17 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
T_1 V_25 = F_1 ( V_2 ) ;
const void * V_27 = F_2 ( V_2 , V_25 ) ;
F_4 ( L_13 , V_25 ) ;
F_18 ( L_14 , V_27 , V_25 ) ;
F_5 ( V_28 , V_2 , V_8 , V_25 , V_27 ) ;
}
static int F_19 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
T_1 V_29 = F_1 ( V_2 ) ;
T_1 V_30 = F_1 ( V_2 ) ;
T_1 V_31 = F_1 ( V_2 ) ;
const void * V_32 = F_2 ( V_2 , V_29 ) ;
const void * V_33 = F_2 ( V_2 , V_30 ) ;
F_4 ( L_15
L_16 ,
V_29 , V_30 , V_31 ) ;
F_18 ( L_17 , V_32 , V_29 ) ;
F_18 ( L_18 , V_33 , V_30 ) ;
F_5 ( V_34 , V_2 , V_8 , V_29 , V_30 , V_31 ,
V_32 , V_33 ) ;
}
static int F_20 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
T_1 V_13 = F_1 ( V_2 ) ;
T_1 V_25 = F_1 ( V_2 ) ;
F_4 ( L_19 , V_13 , V_25 ) ;
F_5 ( V_35 , V_2 , V_8 , V_13 , V_25 ) ;
}
static int F_21 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
T_1 V_13 = F_1 ( V_2 ) ;
T_1 V_25 = F_1 ( V_2 ) ;
const void * V_27 = F_2 ( V_2 , V_25 ) ;
F_4 ( L_20 , V_13 , V_25 ) ;
F_18 ( L_14 , V_27 , V_25 ) ;
F_5 ( V_36 , V_2 , V_8 , V_13 , V_25 , V_27 ) ;
}
static int F_22 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
T_1 V_13 = F_1 ( V_2 ) ;
T_1 V_29 = F_1 ( V_2 ) ;
T_1 V_30 = F_1 ( V_2 ) ;
T_1 V_31 = F_1 ( V_2 ) ;
const void * V_32 = F_2 ( V_2 , V_29 ) ;
const void * V_33 = F_2 ( V_2 , V_30 ) ;
F_4 ( L_21
L_22 ,
V_29 , V_30 , V_31 ) ;
F_18 ( L_17 , V_32 , V_29 ) ;
F_18 ( L_18 , V_33 , V_30 ) ;
F_5 ( V_37 , V_2 , V_8 , V_13 , V_29 , V_30 ,
V_31 , V_32 , V_33 ) ;
}
static int F_23 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
T_2 V_38 = ( T_2 ) F_1 ( V_2 ) ;
T_1 V_25 = F_1 ( V_2 ) ;
F_4 ( L_23 ,
V_38 , V_25 ) ;
F_5 ( V_39 , V_2 , V_8 , V_38 , V_25 ) ;
}
static int F_24 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
T_2 V_38 = ( T_2 ) F_1 ( V_2 ) ;
T_1 V_25 = F_1 ( V_2 ) ;
const void * V_27 = F_2 ( V_2 , V_25 ) ;
F_4 ( L_24 ,
V_38 , V_25 ) ;
F_18 ( L_14 , V_27 , V_25 ) ;
F_5 ( V_40 , V_2 , V_8 , V_38 , V_25 , V_27 ) ;
}
static int F_25 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
T_1 V_41 = F_1 ( V_2 ) ;
F_4 ( L_25 , V_41 ) ;
F_5 ( V_42 , V_2 , V_8 , V_41 ) ;
}
static int F_26 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
T_2 V_38 = ( T_2 ) F_1 ( V_2 ) ;
T_1 V_29 = F_1 ( V_2 ) ;
T_1 V_30 = F_1 ( V_2 ) ;
T_1 V_31 = F_1 ( V_2 ) ;
const void * V_32 = F_2 ( V_2 , V_29 ) ;
const void * V_33 = F_2 ( V_2 , V_30 ) ;
F_4 ( L_26
L_27 ,
V_38 , V_29 , V_30 , V_31 ) ;
F_18 ( L_17 , V_32 , V_29 ) ;
F_18 ( L_18 , V_33 , V_30 ) ;
F_5 ( V_43 , V_2 , V_8 , V_38 , V_29 , V_30 ,
V_31 , V_32 , V_33 ) ;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
T_1 V_13 = F_1 ( V_2 ) ;
T_1 V_9 = F_1 ( V_2 ) ;
T_1 V_44 = F_1 ( V_2 ) ;
T_1 V_11 = F_1 ( V_2 ) ;
F_4 ( L_28
L_29 , V_13 , V_9 , V_44 , V_11 ) ;
F_5 ( V_45 , V_2 , V_8 , V_13 , V_9 , V_44 , V_11 ) ;
}
static int F_28 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
T_1 V_13 = F_1 ( V_2 ) ;
T_1 V_9 = F_1 ( V_2 ) ;
T_1 V_44 = F_1 ( V_2 ) ;
T_1 V_11 = F_1 ( V_2 ) ;
F_4 ( L_30
L_29 , V_13 , V_9 , V_44 , V_11 ) ;
F_5 ( V_46 , V_2 , V_8 , V_13 , V_9 , V_44 , V_11 ) ;
}
static int F_29 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
T_1 V_13 = F_1 ( V_2 ) ;
T_1 V_9 = F_1 ( V_2 ) ;
T_1 V_44 = F_1 ( V_2 ) ;
T_1 V_11 = F_1 ( V_2 ) ;
F_4 ( L_31
L_29 , V_13 , V_9 , V_44 , V_11 ) ;
F_5 ( V_47 , V_2 , V_8 , V_13 , V_9 , V_44 , V_11 ) ;
}
static int F_30 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
T_1 V_13 = F_1 ( V_2 ) ;
T_1 V_44 = F_1 ( V_2 ) ;
T_1 V_9 = F_1 ( V_2 ) ;
F_4 ( L_32 ,
V_13 , V_44 , V_9 ) ;
F_5 ( V_48 , V_2 , V_8 , V_13 , V_44 , V_9 ) ;
}
static int F_31 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
T_1 V_13 = F_1 ( V_2 ) ;
T_1 V_44 = F_1 ( V_2 ) ;
T_1 V_9 = F_1 ( V_2 ) ;
F_4 ( L_33 ,
V_13 , V_44 , V_9 ) ;
F_5 ( V_49 , V_2 , V_8 , V_13 , V_44 , V_9 ) ;
}
static int F_32 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
T_1 V_13 = F_1 ( V_2 ) ;
T_1 V_44 = F_1 ( V_2 ) ;
T_1 V_9 = F_1 ( V_2 ) ;
F_4 ( L_34 ,
V_13 , V_44 , V_9 ) ;
F_5 ( V_50 , V_2 , V_8 , V_13 , V_44 , V_9 ) ;
}
static int F_33 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
T_1 V_25 = F_1 ( V_2 ) ;
const void * V_32 = F_2 ( V_2 , V_25 ) ;
const void * V_33 = F_2 ( V_2 , V_25 ) ;
F_4 ( L_35 , V_25 ) ;
F_18 ( L_17 , V_32 , V_25 ) ;
F_18 ( L_18 , V_33 , V_25 ) ;
F_5 ( V_51 , V_2 , V_8 ,
V_25 , V_32 , V_33 ) ;
}
static void F_34 ( struct V_52 * V_52 )
{
struct V_53 * V_54 = F_35 ( V_52 , struct V_53 , V_55 ) ;
F_36 ( V_54 ) ;
}
static inline void F_37 ( struct V_53 * V_54 )
{
F_38 ( & V_54 -> V_55 , F_34 ) ;
}
static inline struct V_53 * F_39 ( struct V_53 * V_54 )
{
F_40 ( & V_54 -> V_55 ) ;
return V_54 ;
}
static inline struct V_53 * F_41 ( struct V_56 * V_57 )
{
struct V_53 * V_54 ;
F_42 (dev, &pmf_devices, link) {
if ( V_54 -> V_58 == V_57 )
return F_39 ( V_54 ) ;
}
return NULL ;
}
static int F_43 ( struct V_59 * V_60 ,
struct V_7 * V_61 ,
void * V_62 , struct V_63 * args )
{
struct V_1 V_2 ;
T_1 V_64 ;
int V_6 , V_65 ;
V_2 . V_5 = V_60 -> V_66 ;
V_2 . V_4 = V_60 -> V_66 + V_60 -> V_67 ;
V_2 . V_60 = V_60 ;
V_2 . V_62 = V_62 ;
V_2 . args = args ;
V_2 . error = 0 ;
F_4 ( L_36 ,
V_60 -> V_68 , V_60 -> V_67 ,
V_61 ? L_37 : L_38 ) ;
V_6 = 1 ;
while( V_6 -- && V_2 . V_5 < V_2 . V_4 ) {
V_64 = F_1 ( & V_2 ) ;
if ( V_64 == 0 ) {
V_6 = F_1 ( & V_2 ) - 1 ;
V_64 = F_1 ( & V_2 ) ;
}
if ( V_2 . error ) {
F_44 ( L_39 ) ;
return - V_69 ;
}
if ( V_64 >= V_70 ) {
F_44 ( L_40 , V_64 ) ;
return - V_69 ;
}
if ( V_71 [ V_64 ] == NULL ) {
F_44 ( L_41 , V_64 ) ;
return - V_69 ;
}
V_65 = V_71 [ V_64 ] ( & V_2 , V_61 ) ;
if ( V_65 != 0 ) {
F_44 ( L_42
L_43 , V_64 , V_65 ) ;
return V_65 ;
}
}
if ( V_61 == NULL )
V_60 -> V_67 = V_2 . V_5 - V_60 -> V_66 ;
return 0 ;
}
static int F_45 ( struct V_53 * V_54 , void * V_72 ,
const char * V_68 , T_1 * V_66 ,
unsigned int V_67 )
{
int V_6 = 0 ;
struct V_59 * V_60 = NULL ;
F_46 ( L_44 , V_68 ) ;
while ( V_67 >= 12 ) {
V_60 = F_47 ( sizeof( struct V_59 ) , V_73 ) ;
if ( V_60 == NULL )
goto V_74;
F_48 ( & V_60 -> V_55 ) ;
F_49 ( & V_60 -> V_75 ) ;
V_60 -> V_58 = V_54 -> V_58 ;
V_60 -> V_76 = V_72 ;
V_60 -> V_68 = V_68 ;
V_60 -> V_77 = V_66 [ 0 ] ;
V_60 -> V_78 = V_66 [ 1 ] ;
V_66 += 2 ;
V_67 -= 8 ;
V_60 -> V_66 = V_66 ;
V_60 -> V_67 = V_67 ;
V_60 -> V_54 = V_54 ;
F_46 ( L_45
L_46 ,
V_6 + 1 , V_60 -> V_78 , V_60 -> V_77 , V_67 ) ;
if ( F_43 ( V_60 , NULL , NULL , NULL ) ) {
F_36 ( V_60 ) ;
goto V_74;
}
V_67 -= V_60 -> V_67 ;
V_66 = ( T_1 * ) ( ( ( T_2 * ) V_66 ) + V_60 -> V_67 ) ;
F_50 ( & V_60 -> V_79 , & V_54 -> V_80 ) ;
F_39 ( V_54 ) ;
V_6 ++ ;
}
V_74:
F_46 ( L_47 , V_6 ) ;
return V_6 ;
}
static int F_51 ( struct V_53 * V_54 , void * V_72 )
{
struct V_81 * V_82 ;
#define F_52 "platform-do-"
const int V_83 = strlen ( F_52 ) ;
int V_6 = 0 ;
for ( V_82 = V_54 -> V_58 -> V_84 ; V_82 != 0 ; V_82 = V_82 -> V_85 ) {
char * V_68 ;
if ( strncmp ( V_82 -> V_68 , F_52 , V_83 ) != 0 )
continue;
V_68 = V_82 -> V_68 + V_83 ;
if ( strlen ( V_68 ) && V_82 -> V_67 >= 12 )
V_6 += F_45 ( V_54 , V_72 , V_68 ,
V_82 -> V_3 , V_82 -> V_67 ) ;
}
return V_6 ;
}
int F_53 ( struct V_56 * V_57 ,
struct V_7 * V_61 ,
void * V_72 )
{
struct V_53 * V_54 ;
unsigned long V_78 ;
int V_65 = 0 ;
if ( V_61 == NULL )
return - V_86 ;
F_46 ( L_48 , V_57 -> V_87 ) ;
F_54 ( & V_88 , V_78 ) ;
V_54 = F_41 ( V_57 ) ;
F_55 ( & V_88 , V_78 ) ;
if ( V_54 != NULL ) {
F_46 ( L_49 ) ;
F_37 ( V_54 ) ;
return - V_89 ;
}
V_54 = F_47 ( sizeof( struct V_53 ) , V_73 ) ;
if ( V_54 == NULL ) {
F_46 ( L_50 ) ;
return - V_90 ;
}
F_48 ( & V_54 -> V_55 ) ;
V_54 -> V_58 = F_56 ( V_57 ) ;
V_54 -> V_61 = V_61 ;
F_49 ( & V_54 -> V_80 ) ;
V_65 = F_51 ( V_54 , V_72 ) ;
if ( V_65 == 0 ) {
F_46 ( L_51 ) ;
F_57 ( V_57 ) ;
F_36 ( V_54 ) ;
return - V_91 ;
}
F_54 ( & V_88 , V_78 ) ;
F_50 ( & V_54 -> V_79 , & V_92 ) ;
F_55 ( & V_88 , V_78 ) ;
return 0 ;
}
struct V_59 * F_58 ( struct V_59 * V_60 )
{
if ( ! F_59 ( V_60 -> V_54 -> V_61 -> V_93 ) )
return NULL ;
F_40 ( & V_60 -> V_55 ) ;
return V_60 ;
}
static void F_60 ( struct V_52 * V_52 )
{
struct V_59 * V_60 =
F_35 ( V_52 , struct V_59 , V_55 ) ;
F_37 ( V_60 -> V_54 ) ;
F_36 ( V_60 ) ;
}
static inline void F_61 ( struct V_59 * V_60 )
{
F_38 ( & V_60 -> V_55 , F_60 ) ;
}
void F_62 ( struct V_59 * V_60 )
{
if ( V_60 == NULL )
return;
F_63 ( V_60 -> V_54 -> V_61 -> V_93 ) ;
F_61 ( V_60 ) ;
}
void F_64 ( struct V_56 * V_57 )
{
struct V_53 * V_54 ;
unsigned long V_78 ;
F_46 ( L_52 , V_57 -> V_87 ) ;
F_54 ( & V_88 , V_78 ) ;
V_54 = F_41 ( V_57 ) ;
if ( V_54 == NULL ) {
F_46 ( L_53 ) ;
F_55 ( & V_88 , V_78 ) ;
return;
}
F_65 ( & V_54 -> V_79 ) ;
while( ! F_66 ( & V_54 -> V_80 ) ) {
struct V_59 * V_60 =
F_67 ( V_54 -> V_80 . V_85 , F_68 ( * V_60 ) , V_79 ) ;
F_65 ( & V_60 -> V_79 ) ;
F_61 ( V_60 ) ;
}
F_37 ( V_54 ) ;
F_55 ( & V_88 , V_78 ) ;
}
struct V_59 * F_69 ( struct V_56 * V_94 ,
const char * V_68 , T_1 V_78 )
{
struct V_56 * V_95 = F_56 ( V_94 ) ;
struct V_53 * V_54 ;
struct V_59 * V_60 , * V_96 = NULL ;
char V_97 [ 64 ] ;
const T_1 * V_98 ;
T_1 V_99 ;
snprintf ( V_97 , 63 , L_54 , V_68 ) ;
V_98 = F_70 ( V_94 , V_97 , NULL ) ;
if ( V_98 == NULL )
goto V_100;
V_99 = * V_98 ;
if ( V_99 == 0 )
goto V_100;
F_57 ( V_95 ) ;
V_95 = F_71 ( V_99 ) ;
if ( V_95 == NULL )
return NULL ;
V_100:
V_54 = F_41 ( V_95 ) ;
if ( V_54 == NULL ) {
V_96 = NULL ;
goto V_101;
}
F_42 (func, &dev->functions, link) {
if ( V_68 && strcmp ( V_68 , V_60 -> V_68 ) )
continue;
if ( V_60 -> V_77 && V_94 -> V_77 != V_60 -> V_77 )
continue;
if ( ( V_60 -> V_78 & V_78 ) == 0 )
continue;
V_96 = V_60 ;
break;
}
F_37 ( V_54 ) ;
V_101:
F_57 ( V_95 ) ;
return V_96 ;
}
int F_72 ( struct V_56 * V_94 ,
const char * V_68 ,
struct V_102 * V_103 )
{
struct V_59 * V_60 ;
unsigned long V_78 ;
F_54 ( & V_88 , V_78 ) ;
V_60 = F_69 ( V_94 , V_68 , V_104 ) ;
if ( V_60 )
V_60 = F_58 ( V_60 ) ;
F_55 ( & V_88 , V_78 ) ;
if ( V_60 == NULL )
return - V_91 ;
F_73 ( & V_105 ) ;
if ( F_66 ( & V_60 -> V_75 ) )
V_60 -> V_54 -> V_61 -> V_106 ( V_60 ) ;
F_54 ( & V_88 , V_78 ) ;
F_50 ( & V_103 -> V_79 , & V_60 -> V_75 ) ;
F_55 ( & V_88 , V_78 ) ;
V_103 -> V_60 = V_60 ;
F_74 ( & V_105 ) ;
return 0 ;
}
void F_75 ( struct V_102 * V_103 )
{
struct V_59 * V_60 = V_103 -> V_60 ;
unsigned long V_78 ;
F_76 ( V_60 == NULL ) ;
F_73 ( & V_105 ) ;
V_103 -> V_60 = NULL ;
F_54 ( & V_88 , V_78 ) ;
F_65 ( & V_103 -> V_79 ) ;
F_55 ( & V_88 , V_78 ) ;
if ( F_66 ( & V_60 -> V_75 ) )
V_60 -> V_54 -> V_61 -> V_107 ( V_60 ) ;
F_74 ( & V_105 ) ;
F_62 ( V_60 ) ;
}
void F_77 ( struct V_59 * V_60 )
{
unsigned long V_78 ;
struct V_102 * V_103 ;
F_54 ( & V_88 , V_78 ) ;
F_42 (client, &func->irq_clients, link) {
if ( ! F_59 ( V_103 -> V_93 ) )
continue;
V_103 -> V_108 ( V_103 -> V_66 ) ;
F_63 ( V_103 -> V_93 ) ;
}
F_55 ( & V_88 , V_78 ) ;
}
int F_78 ( struct V_59 * V_60 , struct V_63 * args )
{
struct V_53 * V_54 = V_60 -> V_54 ;
void * V_62 = NULL ;
int V_65 = 0 ;
F_46 ( L_55 , V_54 -> V_58 -> V_87 , V_60 -> V_68 ) ;
if ( V_54 -> V_61 -> V_109 )
V_62 = V_54 -> V_61 -> V_109 ( V_60 , args ) ;
V_65 = F_43 ( V_60 , V_54 -> V_61 , V_62 , args ) ;
if ( V_54 -> V_61 -> V_110 )
V_54 -> V_61 -> V_110 ( V_60 , V_62 ) ;
return V_65 ;
}
int F_79 ( struct V_56 * V_57 , const char * V_68 ,
T_1 V_77 , T_1 V_111 , struct V_63 * args )
{
struct V_53 * V_54 ;
struct V_59 * V_60 , * V_112 ;
unsigned long V_78 ;
int V_65 = - V_91 ;
F_54 ( & V_88 , V_78 ) ;
V_54 = F_41 ( V_57 ) ;
if ( V_54 == NULL ) {
F_55 ( & V_88 , V_78 ) ;
return - V_91 ;
}
F_80 (func, tmp, &dev->functions, link) {
if ( V_68 && strcmp ( V_68 , V_60 -> V_68 ) )
continue;
if ( V_77 && V_60 -> V_77 && V_77 != V_60 -> V_77 )
continue;
if ( ( V_60 -> V_78 & V_111 ) == 0 )
continue;
if ( F_58 ( V_60 ) == NULL )
continue;
F_55 ( & V_88 , V_78 ) ;
V_65 = F_78 ( V_60 , args ) ;
F_62 ( V_60 ) ;
F_54 ( & V_88 , V_78 ) ;
}
F_37 ( V_54 ) ;
F_55 ( & V_88 , V_78 ) ;
return V_65 ;
}
struct V_59 * F_81 ( struct V_56 * V_94 ,
const char * V_68 )
{
struct V_59 * V_60 ;
unsigned long V_78 ;
F_54 ( & V_88 , V_78 ) ;
V_60 = F_69 ( V_94 , V_68 , V_113 ) ;
if ( V_60 )
V_60 = F_58 ( V_60 ) ;
F_55 ( & V_88 , V_78 ) ;
return V_60 ;
}
int F_82 ( struct V_56 * V_94 , const char * V_68 ,
struct V_63 * args )
{
struct V_59 * V_60 = F_81 ( V_94 , V_68 ) ;
int V_65 ;
if ( V_60 == NULL )
return - V_91 ;
V_65 = F_78 ( V_60 , args ) ;
F_62 ( V_60 ) ;
return V_65 ;
}
