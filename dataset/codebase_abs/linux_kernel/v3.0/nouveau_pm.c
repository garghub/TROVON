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
if ( V_11 -> V_18 . V_19 && V_11 -> V_20 && V_4 -> V_18 ) {
V_16 = V_11 -> V_20 ( V_2 , V_4 -> V_18 ) ;
if ( V_16 ) {
F_5 ( V_2 , L_1 ,
V_4 -> V_18 , V_16 ) ;
}
}
F_1 ( V_2 , V_4 , V_21 , V_4 -> V_22 ) ;
F_1 ( V_2 , V_4 , V_23 , V_4 -> V_24 ) ;
F_1 ( V_2 , V_4 , V_25 , V_4 -> V_26 ) ;
F_1 ( V_2 , V_4 , V_27 , V_4 -> V_28 ) ;
V_11 -> V_17 = V_4 ;
return 0 ;
}
static int
F_6 ( struct V_1 * V_2 , const char * V_29 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_10 * V_11 = & V_8 -> V_12 . V_11 ;
struct V_3 * V_4 = NULL ;
if ( V_30 != 7777 )
return - V_31 ;
if ( ! V_11 -> V_15 )
return - V_32 ;
if ( ! strncmp ( V_29 , L_2 , 4 ) )
V_4 = & V_11 -> V_33 ;
else {
int V_34 = F_7 ( V_29 , NULL , 10 ) ;
int V_35 ;
for ( V_35 = 0 ; V_35 < V_11 -> V_36 ; V_35 ++ ) {
if ( V_11 -> V_4 [ V_35 ] . V_5 == V_34 ) {
V_4 = & V_11 -> V_4 [ V_35 ] ;
break;
}
}
if ( ! V_4 )
return - V_32 ;
}
F_8 ( V_2 , L_3 , V_29 ) ;
return F_4 ( V_2 , V_4 ) ;
}
static int
F_9 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_10 * V_11 = & V_8 -> V_12 . V_11 ;
int V_16 ;
if ( ! V_11 -> V_37 )
return - V_32 ;
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
V_16 = V_11 -> V_37 ( V_2 , V_21 ) ;
if ( V_16 > 0 )
V_4 -> V_22 = V_16 ;
V_16 = V_11 -> V_37 ( V_2 , V_25 ) ;
if ( V_16 > 0 )
V_4 -> V_26 = V_16 ;
V_16 = V_11 -> V_37 ( V_2 , V_23 ) ;
if ( V_16 > 0 )
V_4 -> V_24 = V_16 ;
V_16 = V_11 -> V_37 ( V_2 , V_27 ) ;
if ( V_16 > 0 )
V_4 -> V_28 = V_16 ;
if ( V_11 -> V_18 . V_19 && V_11 -> V_38 ) {
V_16 = V_11 -> V_38 ( V_2 ) ;
if ( V_16 > 0 )
V_4 -> V_18 = V_16 ;
}
return 0 ;
}
static void
F_10 ( struct V_3 * V_4 , char * V_39 , int V_40 )
{
char V_41 [ 16 ] , V_42 [ 16 ] , V_43 [ 16 ] , V_44 [ 16 ] , V_45 [ 16 ] ;
V_41 [ 0 ] = '\0' ;
if ( V_4 -> V_22 )
snprintf ( V_41 , sizeof( V_41 ) , L_4 , V_4 -> V_22 / 1000 ) ;
V_42 [ 0 ] = '\0' ;
if ( V_4 -> V_24 )
snprintf ( V_42 , sizeof( V_42 ) , L_5 , V_4 -> V_24 / 1000 ) ;
V_43 [ 0 ] = '\0' ;
if ( V_4 -> V_18 )
snprintf ( V_43 , sizeof( V_43 ) , L_6 , V_4 -> V_18 * 10 ) ;
V_44 [ 0 ] = '\0' ;
if ( V_4 -> V_46 )
snprintf ( V_44 , sizeof( V_44 ) , L_7 , V_4 -> V_46 ) ;
V_45 [ 0 ] = '\0' ;
if ( V_4 -> V_47 )
snprintf ( V_45 , sizeof( V_45 ) , L_8 , V_4 -> V_47 -> V_5 ) ;
snprintf ( V_39 , V_40 , L_9 , V_4 -> V_26 / 1000 ,
V_41 , V_42 , V_43 , V_44 , V_45 ) ;
}
static T_3
F_11 ( struct V_48 * V_49 ,
struct V_50 * V_51 , char * V_52 )
{
struct V_3 * V_4 = (struct V_3 * ) V_51 ;
char * V_39 = V_52 ;
int V_40 = V_53 ;
snprintf ( V_39 , V_40 , L_10 , V_4 -> V_5 ) ;
V_39 += strlen ( V_52 ) ;
V_40 -= strlen ( V_52 ) ;
F_10 ( V_4 , V_39 , V_40 ) ;
return strlen ( V_52 ) ;
}
static T_3
F_12 ( struct V_48 * V_49 , struct V_50 * V_51 , char * V_52 )
{
struct V_1 * V_2 = F_13 ( F_14 ( V_49 ) ) ;
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_10 * V_11 = & V_8 -> V_12 . V_11 ;
struct V_3 V_17 ;
int V_40 = V_53 , V_16 ;
char * V_39 = V_52 ;
if ( ! V_11 -> V_17 )
snprintf ( V_39 , V_40 , L_11 ) ;
else if ( V_11 -> V_17 == & V_11 -> V_33 )
snprintf ( V_39 , V_40 , L_12 ) ;
else
snprintf ( V_39 , V_40 , L_13 , V_11 -> V_17 -> V_5 ) ;
V_39 += strlen ( V_52 ) ;
V_40 -= strlen ( V_52 ) ;
V_16 = F_9 ( V_2 , & V_17 ) ;
if ( V_16 == 0 )
F_10 ( & V_17 , V_39 , V_40 ) ;
return strlen ( V_52 ) ;
}
static T_3
F_15 ( struct V_48 * V_49 , struct V_50 * V_51 ,
const char * V_52 , T_4 V_54 )
{
struct V_1 * V_2 = F_13 ( F_14 ( V_49 ) ) ;
int V_16 ;
V_16 = F_6 ( V_2 , V_52 ) ;
if ( V_16 )
return V_16 ;
return strlen ( V_52 ) ;
}
static int
F_16 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_10 * V_11 = & V_8 -> V_12 . V_11 ;
struct V_48 * V_49 = & V_2 -> V_55 -> V_2 ;
int V_16 , V_35 ;
V_16 = F_17 ( V_49 , & V_56 ) ;
if ( V_16 )
return V_16 ;
for ( V_35 = 0 ; V_35 < V_11 -> V_36 ; V_35 ++ ) {
struct V_3 * V_4 = & V_11 -> V_4 [ V_35 ] ;
V_4 -> V_57 . V_58 . V_59 = V_4 -> V_59 ;
V_4 -> V_57 . V_58 . V_60 = V_61 ;
V_4 -> V_57 . V_62 = F_11 ;
V_4 -> V_57 . V_63 = NULL ;
F_18 ( & V_4 -> V_57 . V_58 ) ;
V_16 = F_17 ( V_49 , & V_4 -> V_57 ) ;
if ( V_16 ) {
F_5 ( V_2 , L_14 ,
V_4 -> V_5 , V_35 ) ;
V_4 -> V_57 . V_58 . V_59 = NULL ;
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
struct V_48 * V_49 = & V_2 -> V_55 -> V_2 ;
int V_35 ;
F_21 ( V_49 , & V_56 ) ;
for ( V_35 = 0 ; V_35 < V_11 -> V_36 ; V_35 ++ ) {
struct V_3 * V_34 = & V_11 -> V_4 [ V_35 ] ;
if ( ! V_34 -> V_57 . V_58 . V_59 )
break;
F_21 ( V_49 , & V_34 -> V_57 ) ;
}
}
static T_3
F_22 ( struct V_48 * V_49 , struct V_50 * V_51 , char * V_52 )
{
struct V_1 * V_2 = F_23 ( V_49 ) ;
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_10 * V_11 = & V_8 -> V_12 . V_11 ;
return snprintf ( V_52 , V_53 , L_15 , V_11 -> V_64 ( V_2 ) * 1000 ) ;
}
static T_3
F_24 ( struct V_48 * V_49 , struct V_50 * V_51 , char * V_52 )
{
struct V_1 * V_2 = F_23 ( V_49 ) ;
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_10 * V_11 = & V_8 -> V_12 . V_11 ;
struct V_65 * V_66 = & V_11 -> V_67 ;
return snprintf ( V_52 , V_53 , L_15 , V_66 -> V_68 * 1000 ) ;
}
static T_3
F_25 ( struct V_48 * V_49 , struct V_50 * V_51 ,
const char * V_52 , T_4 V_54 )
{
struct V_1 * V_2 = F_23 ( V_49 ) ;
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_10 * V_11 = & V_8 -> V_12 . V_11 ;
struct V_65 * V_66 = & V_11 -> V_67 ;
long V_69 ;
if ( F_26 ( V_52 , 10 , & V_69 ) == - V_32 )
return V_54 ;
V_66 -> V_68 = V_69 / 1000 ;
F_27 ( V_2 ) ;
return V_54 ;
}
static T_3
F_28 ( struct V_48 * V_49 , struct V_50 * V_51 ,
char * V_52 )
{
struct V_1 * V_2 = F_23 ( V_49 ) ;
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_10 * V_11 = & V_8 -> V_12 . V_11 ;
struct V_65 * V_66 = & V_11 -> V_67 ;
return snprintf ( V_52 , V_53 , L_15 , V_66 -> V_70 * 1000 ) ;
}
static T_3
F_29 ( struct V_48 * V_49 , struct V_50 * V_51 ,
const char * V_52 ,
T_4 V_54 )
{
struct V_1 * V_2 = F_23 ( V_49 ) ;
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_10 * V_11 = & V_8 -> V_12 . V_11 ;
struct V_65 * V_66 = & V_11 -> V_67 ;
long V_69 ;
if ( F_26 ( V_52 , 10 , & V_69 ) == - V_32 )
return V_54 ;
V_66 -> V_70 = V_69 / 1000 ;
F_27 ( V_2 ) ;
return V_54 ;
}
static T_3 F_30 ( struct V_48 * V_2 ,
struct V_50 * V_58 ,
char * V_52 )
{
return sprintf ( V_52 , L_16 ) ;
}
static T_3 F_31 ( struct V_48 * V_2 ,
struct V_50 * V_58 ,
char * V_52 )
{
return sprintf ( V_52 , L_17 ) ;
}
static int
F_32 ( struct V_1 * V_2 )
{
#ifdef F_33
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_10 * V_11 = & V_8 -> V_12 . V_11 ;
struct V_48 * V_71 ;
int V_16 ;
if ( ! V_11 -> V_64 )
return - V_72 ;
V_71 = F_34 ( & V_2 -> V_55 -> V_2 ) ;
if ( F_2 ( V_71 ) ) {
V_16 = F_3 ( V_71 ) ;
F_5 ( V_2 ,
L_18 , V_16 ) ;
return V_16 ;
}
F_35 ( V_71 , V_2 ) ;
V_16 = F_36 ( & V_2 -> V_55 -> V_2 . V_73 , & V_74 ) ;
if ( V_16 ) {
F_5 ( V_2 ,
L_19 , V_16 ) ;
F_37 ( V_71 ) ;
return V_16 ;
}
V_11 -> V_75 = V_71 ;
#endif
return 0 ;
}
static void
F_38 ( struct V_1 * V_2 )
{
#ifdef F_33
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_10 * V_11 = & V_8 -> V_12 . V_11 ;
if ( V_11 -> V_75 ) {
F_39 ( & V_2 -> V_55 -> V_2 . V_73 , & V_74 ) ;
F_37 ( V_11 -> V_75 ) ;
}
#endif
}
static int
F_40 ( struct V_76 * V_77 , unsigned long V_78 , void * V_79 )
{
struct V_7 * V_8 =
F_41 ( V_77 , struct V_7 , V_12 . V_11 . V_80 ) ;
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_81 * V_82 = (struct V_81 * ) V_79 ;
if ( strcmp ( V_82 -> V_83 , L_20 ) == 0 ) {
bool V_84 = F_42 () ;
F_43 ( V_2 , L_21 , V_84 ? L_22 : L_23 ) ;
}
return V_85 ;
}
int
F_44 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_10 * V_11 = & V_8 -> V_12 . V_11 ;
char V_86 [ 256 ] ;
int V_16 , V_35 ;
F_45 ( V_2 ) ;
F_46 ( V_2 ) ;
F_47 ( V_2 ) ;
F_48 ( V_2 ) ;
F_8 ( V_2 , L_24 , V_11 -> V_36 ) ;
for ( V_35 = 0 ; V_35 < V_11 -> V_36 ; V_35 ++ ) {
F_10 ( & V_11 -> V_4 [ V_35 ] , V_86 , sizeof( V_86 ) ) ;
F_8 ( V_2 , L_25 , V_11 -> V_4 [ V_35 ] . V_5 , V_86 ) ;
}
V_16 = F_9 ( V_2 , & V_11 -> V_33 ) ;
if ( V_16 == 0 ) {
strncpy ( V_11 -> V_33 . V_59 , L_2 , 4 ) ;
V_11 -> V_17 = & V_11 -> V_33 ;
F_10 ( & V_11 -> V_33 , V_86 , sizeof( V_86 ) ) ;
F_8 ( V_2 , L_26 , V_86 ) ;
}
if ( V_87 != NULL ) {
V_16 = F_6 ( V_2 , V_87 ) ;
if ( V_16 ) {
F_5 ( V_2 , L_27 ,
V_87 , V_16 ) ;
}
}
F_16 ( V_2 ) ;
F_32 ( V_2 ) ;
#if F_49 ( V_88 ) && F_49 ( V_89 )
V_11 -> V_80 . V_90 = F_40 ;
F_50 ( & V_11 -> V_80 ) ;
#endif
return 0 ;
}
void
F_19 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_10 * V_11 = & V_8 -> V_12 . V_11 ;
if ( V_11 -> V_17 != & V_11 -> V_33 )
F_4 ( V_2 , & V_11 -> V_33 ) ;
F_51 ( V_2 ) ;
F_52 ( V_2 ) ;
F_53 ( V_2 ) ;
F_54 ( V_2 ) ;
#if F_49 ( V_88 ) && F_49 ( V_89 )
F_55 ( & V_11 -> V_80 ) ;
#endif
F_38 ( V_2 ) ;
F_20 ( V_2 ) ;
}
void
F_56 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_10 * V_11 = & V_8 -> V_12 . V_11 ;
struct V_3 * V_4 ;
if ( ! V_11 -> V_17 || V_11 -> V_17 == & V_11 -> V_33 )
return;
V_4 = V_11 -> V_17 ;
V_11 -> V_17 = & V_11 -> V_33 ;
F_4 ( V_2 , V_4 ) ;
}
