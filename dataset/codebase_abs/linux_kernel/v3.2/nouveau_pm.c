static int
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 V_5 , T_2 V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_10 * V_11 = & V_8 -> V_12 . V_11 ;
void * V_13 ;
if ( V_6 == 0 )
return 0 ;
V_13 = V_11 -> V_14 ( V_2 , V_4 , V_5 , V_6 ) ;
if ( F_2 ( V_13 ) )
return F_3 ( V_13 ) ;
if ( V_13 )
V_11 -> V_15 ( V_2 , V_13 ) ;
return 0 ;
}
static int
F_4 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_10 * V_11 = & V_8 -> V_12 . V_11 ;
int V_16 ;
if ( V_4 == V_11 -> V_17 )
return 0 ;
if ( V_11 -> V_18 . V_19 && V_11 -> V_20 && V_4 -> V_21 ) {
V_16 = V_11 -> V_20 ( V_2 , V_4 -> V_21 ) ;
if ( V_16 ) {
F_5 ( V_2 , L_1 ,
V_4 -> V_21 , V_16 ) ;
}
}
if ( V_11 -> V_22 ) {
void * V_23 = V_11 -> V_22 ( V_2 , V_4 ) ;
if ( F_2 ( V_23 ) )
return F_3 ( V_23 ) ;
V_11 -> V_24 ( V_2 , V_23 ) ;
} else
if ( V_11 -> V_15 ) {
F_1 ( V_2 , V_4 , V_25 , V_4 -> V_26 ) ;
F_1 ( V_2 , V_4 , V_27 , V_4 -> V_28 ) ;
F_1 ( V_2 , V_4 , V_29 , V_4 -> V_30 ) ;
F_1 ( V_2 , V_4 , V_31 , V_4 -> V_32 ) ;
}
V_11 -> V_17 = V_4 ;
return 0 ;
}
static int
F_6 ( struct V_1 * V_2 , const char * V_33 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_10 * V_11 = & V_8 -> V_12 . V_11 ;
struct V_3 * V_4 = NULL ;
if ( V_34 != 7777 )
return - V_35 ;
if ( ! strncmp ( V_33 , L_2 , 4 ) )
V_4 = & V_11 -> V_36 ;
else {
int V_37 = F_7 ( V_33 , NULL , 10 ) ;
int V_38 ;
for ( V_38 = 0 ; V_38 < V_11 -> V_39 ; V_38 ++ ) {
if ( V_11 -> V_4 [ V_38 ] . V_5 == V_37 ) {
V_4 = & V_11 -> V_4 [ V_38 ] ;
break;
}
}
if ( ! V_4 )
return - V_40 ;
}
F_8 ( V_2 , L_3 , V_33 ) ;
return F_4 ( V_2 , V_4 ) ;
}
static int
F_9 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_10 * V_11 = & V_8 -> V_12 . V_11 ;
int V_16 ;
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
if ( V_11 -> V_41 ) {
V_16 = V_11 -> V_41 ( V_2 , V_4 ) ;
if ( V_16 )
return V_16 ;
} else
if ( V_11 -> V_42 ) {
V_16 = V_11 -> V_42 ( V_2 , V_25 ) ;
if ( V_16 > 0 )
V_4 -> V_26 = V_16 ;
V_16 = V_11 -> V_42 ( V_2 , V_29 ) ;
if ( V_16 > 0 )
V_4 -> V_30 = V_16 ;
V_16 = V_11 -> V_42 ( V_2 , V_27 ) ;
if ( V_16 > 0 )
V_4 -> V_28 = V_16 ;
V_16 = V_11 -> V_42 ( V_2 , V_31 ) ;
if ( V_16 > 0 )
V_4 -> V_32 = V_16 ;
}
if ( V_11 -> V_18 . V_19 && V_11 -> V_43 ) {
V_16 = V_11 -> V_43 ( V_2 ) ;
if ( V_16 > 0 ) {
V_4 -> V_21 = V_16 ;
V_4 -> V_44 = V_16 ;
}
}
return 0 ;
}
static void
F_10 ( struct V_3 * V_4 , char * V_45 , int V_46 )
{
char V_47 [ 16 ] , V_48 [ 16 ] , V_49 [ 32 ] , V_50 [ 16 ] , V_51 [ 16 ] , V_52 [ 16 ] ;
V_47 [ 0 ] = '\0' ;
if ( V_4 -> V_26 )
snprintf ( V_47 , sizeof( V_47 ) , L_4 , V_4 -> V_26 / 1000 ) ;
V_48 [ 0 ] = '\0' ;
if ( V_4 -> V_28 )
snprintf ( V_48 , sizeof( V_48 ) , L_5 , V_4 -> V_28 / 1000 ) ;
V_52 [ 0 ] = '\0' ;
if ( V_4 -> V_30 )
snprintf ( V_52 , sizeof( V_52 ) , L_6 , V_4 -> V_30 / 1000 ) ;
V_49 [ 0 ] = '\0' ;
if ( V_4 -> V_21 && V_4 -> V_21 != V_4 -> V_44 ) {
snprintf ( V_49 , sizeof( V_49 ) , L_7 ,
V_4 -> V_21 / 1000 , V_4 -> V_44 / 1000 ) ;
} else
if ( V_4 -> V_21 ) {
snprintf ( V_49 , sizeof( V_49 ) , L_8 ,
V_4 -> V_21 / 1000 ) ;
}
V_50 [ 0 ] = '\0' ;
if ( V_4 -> V_53 )
snprintf ( V_50 , sizeof( V_50 ) , L_9 , V_4 -> V_53 ) ;
V_51 [ 0 ] = '\0' ;
if ( V_4 -> V_54 )
snprintf ( V_51 , sizeof( V_51 ) , L_10 , V_4 -> V_54 -> V_5 ) ;
snprintf ( V_45 , V_46 , L_11 , V_47 , V_48 , V_52 , V_51 , V_49 , V_50 ) ;
}
static T_3
F_11 ( struct V_55 * V_56 ,
struct V_57 * V_58 , char * V_59 )
{
struct V_3 * V_4 = (struct V_3 * ) V_58 ;
char * V_45 = V_59 ;
int V_46 = V_60 ;
snprintf ( V_45 , V_46 , L_12 , V_4 -> V_5 ) ;
V_45 += strlen ( V_59 ) ;
V_46 -= strlen ( V_59 ) ;
F_10 ( V_4 , V_45 , V_46 ) ;
return strlen ( V_59 ) ;
}
static T_3
F_12 ( struct V_55 * V_56 , struct V_57 * V_58 , char * V_59 )
{
struct V_1 * V_2 = F_13 ( F_14 ( V_56 ) ) ;
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_10 * V_11 = & V_8 -> V_12 . V_11 ;
struct V_3 V_17 ;
int V_46 = V_60 , V_16 ;
char * V_45 = V_59 ;
if ( ! V_11 -> V_17 )
snprintf ( V_45 , V_46 , L_13 ) ;
else if ( V_11 -> V_17 == & V_11 -> V_36 )
snprintf ( V_45 , V_46 , L_14 ) ;
else
snprintf ( V_45 , V_46 , L_15 , V_11 -> V_17 -> V_5 ) ;
V_45 += strlen ( V_59 ) ;
V_46 -= strlen ( V_59 ) ;
V_16 = F_9 ( V_2 , & V_17 ) ;
if ( V_16 == 0 )
F_10 ( & V_17 , V_45 , V_46 ) ;
return strlen ( V_59 ) ;
}
static T_3
F_15 ( struct V_55 * V_56 , struct V_57 * V_58 ,
const char * V_59 , T_4 V_61 )
{
struct V_1 * V_2 = F_13 ( F_14 ( V_56 ) ) ;
int V_16 ;
V_16 = F_6 ( V_2 , V_59 ) ;
if ( V_16 )
return V_16 ;
return strlen ( V_59 ) ;
}
static int
F_16 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_10 * V_11 = & V_8 -> V_12 . V_11 ;
struct V_55 * V_56 = & V_2 -> V_62 -> V_2 ;
int V_16 , V_38 ;
V_16 = F_17 ( V_56 , & V_63 ) ;
if ( V_16 )
return V_16 ;
for ( V_38 = 0 ; V_38 < V_11 -> V_39 ; V_38 ++ ) {
struct V_3 * V_4 = & V_11 -> V_4 [ V_38 ] ;
V_4 -> V_64 . V_65 . V_66 = V_4 -> V_66 ;
V_4 -> V_64 . V_65 . V_67 = V_68 ;
V_4 -> V_64 . V_69 = F_11 ;
V_4 -> V_64 . V_70 = NULL ;
F_18 ( & V_4 -> V_64 . V_65 ) ;
V_16 = F_17 ( V_56 , & V_4 -> V_64 ) ;
if ( V_16 ) {
F_5 ( V_2 , L_16 ,
V_4 -> V_5 , V_38 ) ;
V_4 -> V_64 . V_65 . V_66 = NULL ;
F_19 ( V_2 ) ;
return V_16 ;
}
}
return 0 ;
}
static void
F_20 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_10 * V_11 = & V_8 -> V_12 . V_11 ;
struct V_55 * V_56 = & V_2 -> V_62 -> V_2 ;
int V_38 ;
F_21 ( V_56 , & V_63 ) ;
for ( V_38 = 0 ; V_38 < V_11 -> V_39 ; V_38 ++ ) {
struct V_3 * V_37 = & V_11 -> V_4 [ V_38 ] ;
if ( ! V_37 -> V_64 . V_65 . V_66 )
break;
F_21 ( V_56 , & V_37 -> V_64 ) ;
}
}
static T_3
F_22 ( struct V_55 * V_56 , struct V_57 * V_58 , char * V_59 )
{
struct V_1 * V_2 = F_23 ( V_56 ) ;
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_10 * V_11 = & V_8 -> V_12 . V_11 ;
return snprintf ( V_59 , V_60 , L_17 , V_11 -> V_71 ( V_2 ) * 1000 ) ;
}
static T_3
F_24 ( struct V_55 * V_56 , struct V_57 * V_58 , char * V_59 )
{
struct V_1 * V_2 = F_23 ( V_56 ) ;
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_10 * V_11 = & V_8 -> V_12 . V_11 ;
struct V_72 * V_73 = & V_11 -> V_74 ;
return snprintf ( V_59 , V_60 , L_17 , V_73 -> V_75 * 1000 ) ;
}
static T_3
F_25 ( struct V_55 * V_56 , struct V_57 * V_58 ,
const char * V_59 , T_4 V_61 )
{
struct V_1 * V_2 = F_23 ( V_56 ) ;
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_10 * V_11 = & V_8 -> V_12 . V_11 ;
struct V_72 * V_73 = & V_11 -> V_74 ;
long V_76 ;
if ( F_26 ( V_59 , 10 , & V_76 ) == - V_40 )
return V_61 ;
V_73 -> V_75 = V_76 / 1000 ;
F_27 ( V_2 ) ;
return V_61 ;
}
static T_3
F_28 ( struct V_55 * V_56 , struct V_57 * V_58 ,
char * V_59 )
{
struct V_1 * V_2 = F_23 ( V_56 ) ;
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_10 * V_11 = & V_8 -> V_12 . V_11 ;
struct V_72 * V_73 = & V_11 -> V_74 ;
return snprintf ( V_59 , V_60 , L_17 , V_73 -> V_77 * 1000 ) ;
}
static T_3
F_29 ( struct V_55 * V_56 , struct V_57 * V_58 ,
const char * V_59 ,
T_4 V_61 )
{
struct V_1 * V_2 = F_23 ( V_56 ) ;
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_10 * V_11 = & V_8 -> V_12 . V_11 ;
struct V_72 * V_73 = & V_11 -> V_74 ;
long V_76 ;
if ( F_26 ( V_59 , 10 , & V_76 ) == - V_40 )
return V_61 ;
V_73 -> V_77 = V_76 / 1000 ;
F_27 ( V_2 ) ;
return V_61 ;
}
static T_3 F_30 ( struct V_55 * V_2 ,
struct V_57 * V_65 ,
char * V_59 )
{
return sprintf ( V_59 , L_18 ) ;
}
static T_3 F_31 ( struct V_55 * V_2 ,
struct V_57 * V_65 ,
char * V_59 )
{
return sprintf ( V_59 , L_19 ) ;
}
static int
F_32 ( struct V_1 * V_2 )
{
#if F_33 ( V_78 ) || ( F_33 ( V_79 ) && F_33 ( V_80 ) )
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_10 * V_11 = & V_8 -> V_12 . V_11 ;
struct V_55 * V_81 ;
int V_16 ;
if ( ! V_11 -> V_71 )
return - V_82 ;
V_81 = F_34 ( & V_2 -> V_62 -> V_2 ) ;
if ( F_2 ( V_81 ) ) {
V_16 = F_3 ( V_81 ) ;
F_5 ( V_2 ,
L_20 , V_16 ) ;
return V_16 ;
}
F_35 ( V_81 , V_2 ) ;
V_16 = F_36 ( & V_2 -> V_62 -> V_2 . V_83 , & V_84 ) ;
if ( V_16 ) {
F_5 ( V_2 ,
L_21 , V_16 ) ;
F_37 ( V_81 ) ;
return V_16 ;
}
V_11 -> V_85 = V_81 ;
#endif
return 0 ;
}
static void
F_38 ( struct V_1 * V_2 )
{
#if F_33 ( V_78 ) || ( F_33 ( V_79 ) && F_33 ( V_80 ) )
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_10 * V_11 = & V_8 -> V_12 . V_11 ;
if ( V_11 -> V_85 ) {
F_39 ( & V_2 -> V_62 -> V_2 . V_83 , & V_84 ) ;
F_37 ( V_11 -> V_85 ) ;
}
#endif
}
static int
F_40 ( struct V_86 * V_87 , unsigned long V_88 , void * V_89 )
{
struct V_7 * V_8 =
F_41 ( V_87 , struct V_7 , V_12 . V_11 . V_90 ) ;
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_91 * V_92 = (struct V_91 * ) V_89 ;
if ( strcmp ( V_92 -> V_93 , L_22 ) == 0 ) {
bool V_94 = F_42 () ;
F_43 ( V_2 , L_23 , V_94 ? L_24 : L_25 ) ;
}
return V_95 ;
}
int
F_44 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_10 * V_11 = & V_8 -> V_12 . V_11 ;
char V_96 [ 256 ] ;
int V_16 , V_38 ;
F_45 ( V_2 ) ;
F_46 ( V_2 ) ;
F_47 ( V_2 ) ;
F_48 ( V_2 ) ;
F_8 ( V_2 , L_26 , V_11 -> V_39 ) ;
for ( V_38 = 0 ; V_38 < V_11 -> V_39 ; V_38 ++ ) {
F_10 ( & V_11 -> V_4 [ V_38 ] , V_96 , sizeof( V_96 ) ) ;
F_8 ( V_2 , L_27 , V_11 -> V_4 [ V_38 ] . V_5 , V_96 ) ;
}
V_16 = F_9 ( V_2 , & V_11 -> V_36 ) ;
if ( V_16 == 0 ) {
strncpy ( V_11 -> V_36 . V_66 , L_2 , 4 ) ;
V_11 -> V_17 = & V_11 -> V_36 ;
F_10 ( & V_11 -> V_36 , V_96 , sizeof( V_96 ) ) ;
F_8 ( V_2 , L_28 , V_96 ) ;
}
if ( V_97 != NULL ) {
V_16 = F_6 ( V_2 , V_97 ) ;
if ( V_16 ) {
F_5 ( V_2 , L_29 ,
V_97 , V_16 ) ;
}
}
F_16 ( V_2 ) ;
F_32 ( V_2 ) ;
#if F_33 ( V_98 ) && F_33 ( V_99 )
V_11 -> V_90 . V_100 = F_40 ;
F_49 ( & V_11 -> V_90 ) ;
#endif
return 0 ;
}
void
F_19 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_10 * V_11 = & V_8 -> V_12 . V_11 ;
if ( V_11 -> V_17 != & V_11 -> V_36 )
F_4 ( V_2 , & V_11 -> V_36 ) ;
F_50 ( V_2 ) ;
F_51 ( V_2 ) ;
F_52 ( V_2 ) ;
F_53 ( V_2 ) ;
#if F_33 ( V_98 ) && F_33 ( V_99 )
F_54 ( & V_11 -> V_90 ) ;
#endif
F_38 ( V_2 ) ;
F_20 ( V_2 ) ;
}
void
F_55 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_10 * V_11 = & V_8 -> V_12 . V_11 ;
struct V_3 * V_4 ;
if ( ! V_11 -> V_17 || V_11 -> V_17 == & V_11 -> V_36 )
return;
V_4 = V_11 -> V_17 ;
V_11 -> V_17 = & V_11 -> V_36 ;
F_4 ( V_2 , V_4 ) ;
}
