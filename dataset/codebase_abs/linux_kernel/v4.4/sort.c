static int F_1 ( char * V_1 , T_1 V_2 , const char * V_3 , ... )
{
int V_4 ;
T_2 V_5 ;
va_start ( V_5 , V_3 ) ;
V_4 = vsnprintf ( V_1 , V_2 , V_3 , V_5 ) ;
if ( V_6 . V_7 && V_4 > 0 ) {
char * V_8 = V_1 ;
while ( 1 ) {
V_8 = strchr ( V_8 , * V_6 . V_7 ) ;
if ( V_8 == NULL )
break;
* V_8 = '.' ;
}
}
va_end ( V_5 ) ;
if ( V_4 >= ( int ) V_2 )
return V_2 - 1 ;
return V_4 ;
}
static T_3 F_2 ( const void * V_9 , const void * V_10 )
{
if ( ! V_9 && ! V_10 )
return 0 ;
else if ( ! V_9 )
return - 1 ;
else
return 1 ;
}
static T_3
F_3 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
return V_13 -> V_14 -> V_15 - V_12 -> V_14 -> V_15 ;
}
static int F_4 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
const char * V_18 = F_5 ( V_16 -> V_14 ) ;
V_17 = F_6 ( 7U , V_17 ) - 6 ;
return F_1 ( V_1 , V_2 , L_1 , V_16 -> V_14 -> V_15 ,
V_17 , V_17 , V_18 ? : L_2 ) ;
}
static T_3
F_7 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
return strcmp ( F_8 ( V_13 -> V_18 ) , F_8 ( V_12 -> V_18 ) ) ;
}
static T_3
F_9 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
return strcmp ( F_8 ( V_13 -> V_18 ) , F_8 ( V_12 -> V_18 ) ) ;
}
static T_3
F_10 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
return strcmp ( F_8 ( V_13 -> V_18 ) , F_8 ( V_12 -> V_18 ) ) ;
}
static int F_11 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
return F_1 ( V_1 , V_2 , L_3 , V_17 , V_17 , F_8 ( V_16 -> V_18 ) ) ;
}
static T_3 F_12 ( struct V_19 * V_20 , struct V_19 * V_21 )
{
struct V_22 * V_23 = V_20 ? V_20 -> V_22 : NULL ;
struct V_22 * V_24 = V_21 ? V_21 -> V_22 : NULL ;
const char * V_25 , * V_26 ;
if ( ! V_23 || ! V_24 )
return F_2 ( V_24 , V_23 ) ;
if ( V_27 ) {
V_25 = V_23 -> V_28 ;
V_26 = V_24 -> V_28 ;
} else {
V_25 = V_23 -> V_29 ;
V_26 = V_24 -> V_29 ;
}
return strcmp ( V_25 , V_26 ) ;
}
static T_3
F_13 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
return F_12 ( V_13 -> V_30 . V_19 , V_12 -> V_30 . V_19 ) ;
}
static int F_14 ( struct V_19 * V_19 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
if ( V_19 && V_19 -> V_22 ) {
const char * V_31 = ! V_27 ? V_19 -> V_22 -> V_29 :
V_19 -> V_22 -> V_28 ;
return F_1 ( V_1 , V_2 , L_3 , V_17 , V_17 , V_31 ) ;
}
return F_1 ( V_1 , V_2 , L_3 , V_17 , V_17 , L_4 ) ;
}
static int F_15 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
return F_14 ( V_16 -> V_30 . V_19 , V_1 , V_2 , V_17 ) ;
}
static T_3 F_16 ( T_4 V_32 , T_4 V_33 )
{
return ( T_3 ) ( V_33 - V_32 ) ;
}
static T_3 F_17 ( struct V_34 * V_35 , struct V_34 * V_36 )
{
if ( ! V_35 || ! V_36 )
return F_2 ( V_35 , V_36 ) ;
if ( V_35 == V_36 )
return 0 ;
if ( V_35 -> V_37 != V_36 -> V_37 )
return ( T_3 ) ( V_36 -> V_37 - V_35 -> V_37 ) ;
return ( T_3 ) ( V_36 -> V_38 - V_35 -> V_38 ) ;
}
static T_3
F_18 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
T_3 V_39 ;
if ( ! V_12 -> V_30 . V_40 && ! V_13 -> V_30 . V_40 )
return F_16 ( V_12 -> V_41 , V_13 -> V_41 ) ;
if ( ! V_42 ) {
V_39 = F_13 ( V_12 , V_13 ) ;
if ( V_39 != 0 )
return V_39 ;
}
return F_17 ( V_12 -> V_30 . V_40 , V_13 -> V_30 . V_40 ) ;
}
static T_3
F_19 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
if ( ! V_12 -> V_30 . V_40 || ! V_13 -> V_30 . V_40 )
return F_2 ( V_12 -> V_30 . V_40 , V_13 -> V_30 . V_40 ) ;
return strcmp ( V_13 -> V_30 . V_40 -> V_43 , V_12 -> V_30 . V_40 -> V_43 ) ;
}
static int F_20 ( struct V_19 * V_19 , struct V_34 * V_40 ,
T_4 V_41 , char V_44 , char * V_1 , T_1 V_2 ,
unsigned int V_17 )
{
T_1 V_39 = 0 ;
if ( V_27 ) {
char V_45 = V_19 ? F_21 ( V_19 -> V_22 ) : '!' ;
V_39 += F_1 ( V_1 , V_2 , L_5 ,
V_46 / 4 + 2 , V_41 , V_45 ) ;
}
V_39 += F_1 ( V_1 + V_39 , V_2 - V_39 , L_6 , V_44 ) ;
if ( V_40 && V_19 ) {
if ( V_19 -> type == V_47 ) {
V_39 += F_1 ( V_1 + V_39 , V_2 - V_39 , L_7 , V_40 -> V_43 ) ;
V_39 += F_1 ( V_1 + V_39 , V_2 - V_39 , L_8 ,
V_41 - V_19 -> V_48 ( V_19 , V_40 -> V_37 ) ) ;
V_39 += F_1 ( V_1 + V_39 , V_2 - V_39 , L_9 ,
V_17 - V_39 , L_2 ) ;
} else {
V_39 += F_1 ( V_1 + V_39 , V_2 - V_39 , L_9 ,
V_17 - V_39 ,
V_40 -> V_43 ) ;
}
} else {
T_1 V_49 = V_46 / 4 ;
V_39 += F_1 ( V_1 + V_39 , V_2 - V_39 , L_10 ,
V_49 , V_41 ) ;
V_39 += F_1 ( V_1 + V_39 , V_2 - V_39 , L_9 ,
V_17 - V_39 , L_2 ) ;
}
if ( V_39 > V_17 )
V_1 [ V_17 ] = '\0' ;
return V_17 ;
}
static int F_22 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
return F_20 ( V_16 -> V_30 . V_19 , V_16 -> V_30 . V_40 , V_16 -> V_41 ,
V_16 -> V_44 , V_1 , V_2 , V_17 ) ;
}
static T_3
F_23 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
if ( ! V_12 -> V_50 ) {
if ( ! V_12 -> V_30 . V_19 )
V_12 -> V_50 = V_51 ;
else {
struct V_19 * V_19 = V_12 -> V_30 . V_19 ;
V_12 -> V_50 = F_24 ( V_19 -> V_22 ,
F_25 ( V_19 , V_12 -> V_41 ) ,
V_12 -> V_30 . V_40 , true ) ;
}
}
if ( ! V_13 -> V_50 ) {
if ( ! V_13 -> V_30 . V_19 )
V_13 -> V_50 = V_51 ;
else {
struct V_19 * V_19 = V_13 -> V_30 . V_19 ;
V_13 -> V_50 = F_24 ( V_19 -> V_22 ,
F_25 ( V_19 , V_13 -> V_41 ) ,
V_13 -> V_30 . V_40 , true ) ;
}
}
return strcmp ( V_13 -> V_50 , V_12 -> V_50 ) ;
}
static int F_26 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
return F_1 ( V_1 , V_2 , L_3 , V_17 , V_17 , V_16 -> V_50 ) ;
}
static char * F_27 ( struct V_11 * V_52 )
{
char * V_53 , * V_54 ;
struct V_19 * V_19 = V_52 -> V_30 . V_19 ;
V_53 = F_28 ( V_19 -> V_22 , F_25 ( V_19 , V_52 -> V_41 ) ,
V_52 -> V_30 . V_40 , false , true ) ;
if ( ! strcmp ( V_53 , V_51 ) )
return V_55 ;
V_54 = strchr ( V_53 , ':' ) ;
if ( V_54 && * V_53 ) {
* V_54 = 0 ;
return V_53 ;
}
free ( V_53 ) ;
return V_55 ;
}
static T_3
F_29 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
if ( ! V_12 -> V_56 ) {
if ( ! V_12 -> V_30 . V_19 )
V_12 -> V_56 = V_55 ;
else
V_12 -> V_56 = F_27 ( V_12 ) ;
}
if ( ! V_13 -> V_56 ) {
if ( ! V_13 -> V_30 . V_19 )
V_13 -> V_56 = V_55 ;
else
V_13 -> V_56 = F_27 ( V_13 ) ;
}
return strcmp ( V_13 -> V_56 , V_12 -> V_56 ) ;
}
static int F_30 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
return F_1 ( V_1 , V_2 , L_3 , V_17 , V_17 , V_16 -> V_56 ) ;
}
static T_3
F_31 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
struct V_34 * V_35 = V_12 -> V_57 ;
struct V_34 * V_36 = V_13 -> V_57 ;
if ( ! V_35 || ! V_36 )
return F_2 ( V_35 , V_36 ) ;
return strcmp ( V_36 -> V_43 , V_35 -> V_43 ) ;
}
static int F_32 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
return F_1 ( V_1 , V_2 , L_3 , V_17 , V_17 ,
V_16 -> V_57 ? V_16 -> V_57 -> V_43 : L_11 ) ;
}
static T_3
F_33 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
return V_13 -> V_58 - V_12 -> V_58 ;
}
static int F_34 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
return F_1 ( V_1 , V_2 , L_12 , V_17 , V_17 , V_16 -> V_58 ) ;
}
static T_3
F_35 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
return V_13 -> V_59 - V_12 -> V_59 ;
}
static int F_36 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
return F_1 ( V_1 , V_2 , L_12 , V_17 , V_17 - 3 , V_16 -> V_59 ) ;
}
static T_3
F_37 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
if ( ! V_12 -> V_60 || ! V_13 -> V_60 )
return F_2 ( V_12 -> V_60 , V_13 -> V_60 ) ;
return F_12 ( V_12 -> V_60 -> V_61 . V_19 ,
V_13 -> V_60 -> V_61 . V_19 ) ;
}
static int F_38 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
if ( V_16 -> V_60 )
return F_14 ( V_16 -> V_60 -> V_61 . V_19 ,
V_1 , V_2 , V_17 ) ;
else
return F_1 ( V_1 , V_2 , L_3 , V_17 , V_17 , L_13 ) ;
}
static T_3
F_39 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
if ( ! V_12 -> V_60 || ! V_13 -> V_60 )
return F_2 ( V_12 -> V_60 , V_13 -> V_60 ) ;
return F_12 ( V_12 -> V_60 -> V_62 . V_19 ,
V_13 -> V_60 -> V_62 . V_19 ) ;
}
static int F_40 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
if ( V_16 -> V_60 )
return F_14 ( V_16 -> V_60 -> V_62 . V_19 ,
V_1 , V_2 , V_17 ) ;
else
return F_1 ( V_1 , V_2 , L_3 , V_17 , V_17 , L_13 ) ;
}
static T_3
F_41 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
struct V_63 * V_64 = & V_12 -> V_60 -> V_61 ;
struct V_63 * V_65 = & V_13 -> V_60 -> V_61 ;
if ( ! V_12 -> V_60 || ! V_13 -> V_60 )
return F_2 ( V_12 -> V_60 , V_13 -> V_60 ) ;
V_64 = & V_12 -> V_60 -> V_61 ;
V_65 = & V_13 -> V_60 -> V_61 ;
if ( ! V_64 -> V_40 && ! V_65 -> V_40 )
return F_16 ( V_64 -> V_66 , V_65 -> V_66 ) ;
return F_17 ( V_64 -> V_40 , V_65 -> V_40 ) ;
}
static T_3
F_42 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
struct V_63 * V_67 , * V_68 ;
if ( ! V_12 -> V_60 || ! V_13 -> V_60 )
return F_2 ( V_12 -> V_60 , V_13 -> V_60 ) ;
V_67 = & V_12 -> V_60 -> V_62 ;
V_68 = & V_13 -> V_60 -> V_62 ;
if ( ! V_67 -> V_40 && ! V_68 -> V_40 )
return F_16 ( V_67 -> V_66 , V_68 -> V_66 ) ;
return F_17 ( V_67 -> V_40 , V_68 -> V_40 ) ;
}
static int F_43 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
if ( V_16 -> V_60 ) {
struct V_63 * V_61 = & V_16 -> V_60 -> V_61 ;
return F_20 ( V_61 -> V_19 , V_61 -> V_40 , V_61 -> V_66 ,
V_16 -> V_44 , V_1 , V_2 , V_17 ) ;
}
return F_1 ( V_1 , V_2 , L_3 , V_17 , V_17 , L_13 ) ;
}
static int F_44 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
if ( V_16 -> V_60 ) {
struct V_63 * V_62 = & V_16 -> V_60 -> V_62 ;
return F_20 ( V_62 -> V_19 , V_62 -> V_40 , V_62 -> V_66 ,
V_16 -> V_44 , V_1 , V_2 , V_17 ) ;
}
return F_1 ( V_1 , V_2 , L_3 , V_17 , V_17 , L_13 ) ;
}
static T_3
F_45 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
unsigned char V_69 , V_54 ;
if ( ! V_12 -> V_60 || ! V_13 -> V_60 )
return F_2 ( V_12 -> V_60 , V_13 -> V_60 ) ;
V_69 = V_12 -> V_60 -> V_70 . V_71 != V_13 -> V_60 -> V_70 . V_71 ;
V_54 = V_12 -> V_60 -> V_70 . V_72 != V_13 -> V_60 -> V_70 . V_72 ;
return V_69 || V_54 ;
}
static int F_46 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 ) {
static const char * V_73 = L_13 ;
if ( V_16 -> V_60 ) {
if ( V_16 -> V_60 -> V_70 . V_72 )
V_73 = L_14 ;
else if ( V_16 -> V_60 -> V_70 . V_71 )
V_73 = L_15 ;
}
return F_1 ( V_1 , V_2 , L_3 , V_17 , V_17 , V_73 ) ;
}
static T_3
F_47 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
return V_12 -> V_60 -> V_70 . V_74 -
V_13 -> V_60 -> V_70 . V_74 ;
}
static int F_48 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
if ( V_16 -> V_60 -> V_70 . V_74 == 0 )
return F_1 ( V_1 , V_2 , L_9 , V_17 , L_16 ) ;
return F_1 ( V_1 , V_2 , L_17 , V_17 ,
V_16 -> V_60 -> V_70 . V_74 ) ;
}
static T_3
F_49 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
T_5 V_9 = 0 , V_10 = 0 ;
if ( V_12 -> V_75 )
V_9 = V_12 -> V_75 -> V_76 . V_66 ;
if ( V_13 -> V_75 )
V_10 = V_13 -> V_75 -> V_76 . V_66 ;
return ( T_3 ) ( V_10 - V_9 ) ;
}
static int F_50 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
T_5 V_66 = 0 ;
struct V_19 * V_19 = NULL ;
struct V_34 * V_40 = NULL ;
if ( V_16 -> V_75 ) {
V_66 = V_16 -> V_75 -> V_76 . V_66 ;
V_19 = V_16 -> V_75 -> V_76 . V_19 ;
V_40 = V_16 -> V_75 -> V_76 . V_40 ;
}
return F_20 ( V_19 , V_40 , V_66 , V_16 -> V_44 , V_1 , V_2 ,
V_17 ) ;
}
static T_3
F_51 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
T_5 V_9 = 0 , V_10 = 0 ;
if ( V_12 -> V_75 )
V_9 = V_12 -> V_75 -> V_77 . V_66 ;
if ( V_13 -> V_75 )
V_10 = V_13 -> V_75 -> V_77 . V_66 ;
return ( T_3 ) ( V_10 - V_9 ) ;
}
static int F_52 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
T_5 V_66 = 0 ;
struct V_19 * V_19 = NULL ;
struct V_34 * V_40 = NULL ;
if ( V_16 -> V_75 ) {
V_66 = V_16 -> V_75 -> V_77 . V_66 ;
V_19 = V_16 -> V_75 -> V_77 . V_19 ;
V_40 = V_16 -> V_75 -> V_77 . V_40 ;
}
return F_20 ( V_19 , V_40 , V_66 , V_16 -> V_44 , V_1 , V_2 ,
V_17 ) ;
}
static T_3
F_53 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
struct V_19 * V_20 = NULL ;
struct V_19 * V_21 = NULL ;
if ( V_12 -> V_75 )
V_20 = V_12 -> V_75 -> V_76 . V_19 ;
if ( V_13 -> V_75 )
V_21 = V_13 -> V_75 -> V_76 . V_19 ;
return F_12 ( V_20 , V_21 ) ;
}
static int F_54 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
struct V_19 * V_19 = NULL ;
if ( V_16 -> V_75 )
V_19 = V_16 -> V_75 -> V_76 . V_19 ;
return F_14 ( V_19 , V_1 , V_2 , V_17 ) ;
}
static T_3
F_55 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
union V_78 V_79 ;
union V_78 V_80 ;
if ( V_12 -> V_75 )
V_79 = V_12 -> V_75 -> V_81 ;
else
V_79 . V_82 = V_83 ;
if ( V_13 -> V_75 )
V_80 = V_13 -> V_75 -> V_81 ;
else
V_80 . V_82 = V_83 ;
return ( T_3 ) ( V_80 . V_82 - V_79 . V_82 ) ;
}
static int F_56 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
const char * V_73 ;
T_4 V_84 = V_83 ;
if ( V_16 -> V_75 )
V_84 = V_16 -> V_75 -> V_81 . V_82 ;
if ( V_84 & V_83 )
V_73 = L_13 ;
else if ( V_84 & V_85 )
V_73 = L_18 ;
else
V_73 = L_19 ;
return F_1 ( V_1 , V_2 , L_9 , V_17 , V_73 ) ;
}
static T_3
F_57 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
union V_78 V_79 ;
union V_78 V_80 ;
if ( V_12 -> V_75 )
V_79 = V_12 -> V_75 -> V_81 ;
else
V_79 . V_86 = V_87 ;
if ( V_13 -> V_75 )
V_80 = V_13 -> V_75 -> V_81 ;
else
V_80 . V_86 = V_87 ;
return ( T_3 ) ( V_80 . V_86 - V_79 . V_86 ) ;
}
static int F_58 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
char V_73 [ 64 ] ;
T_1 V_88 = sizeof( V_73 ) - 1 ;
T_1 V_9 = 0 , V_89 ;
T_4 V_90 = V_87 ;
T_4 V_91 , V_92 ;
V_73 [ 0 ] = '\0' ;
if ( V_16 -> V_75 )
V_90 = V_16 -> V_75 -> V_81 . V_86 ;
V_91 = V_90 & V_93 ;
V_92 = V_90 & V_94 ;
V_90 &= ~ ( V_93 | V_94 ) ;
for ( V_89 = 0 ; V_90 && V_89 < V_95 ; V_89 ++ , V_90 >>= 1 ) {
if ( ! ( V_90 & 0x1 ) )
continue;
if ( V_9 ) {
strcat ( V_73 , L_20 ) ;
V_9 += 4 ;
}
strncat ( V_73 , V_96 [ V_89 ] , V_88 - V_9 ) ;
V_9 += strlen ( V_96 [ V_89 ] ) ;
}
if ( * V_73 == '\0' )
strcpy ( V_73 , L_13 ) ;
if ( V_91 )
strncat ( V_73 , L_21 , V_88 - V_9 ) ;
if ( V_92 )
strncat ( V_73 , L_22 , V_88 - V_9 ) ;
return F_1 ( V_1 , V_2 , L_9 , V_17 , V_73 ) ;
}
static T_3
F_59 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
union V_78 V_79 ;
union V_78 V_80 ;
if ( V_12 -> V_75 )
V_79 = V_12 -> V_75 -> V_81 ;
else
V_79 . V_97 = V_98 ;
if ( V_13 -> V_75 )
V_80 = V_13 -> V_75 -> V_81 ;
else
V_80 . V_97 = V_98 ;
return ( T_3 ) ( V_80 . V_97 - V_79 . V_97 ) ;
}
static int F_60 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
char V_73 [ 64 ] ;
T_1 V_88 = sizeof( V_73 ) - 1 ;
T_1 V_89 , V_9 = 0 ;
T_4 V_90 = V_98 ;
T_4 V_91 , V_92 ;
if ( V_16 -> V_75 )
V_90 = V_16 -> V_75 -> V_81 . V_97 ;
V_73 [ 0 ] = '\0' ;
V_91 = V_90 & V_99 ;
V_92 = V_90 & V_100 ;
V_90 &= ~ ( V_99 | V_100 ) ;
for ( V_89 = 0 ; V_90 && V_89 < V_101 ; V_89 ++ , V_90 >>= 1 ) {
if ( ! ( V_90 & 0x1 ) )
continue;
if ( V_9 ) {
strcat ( V_73 , L_20 ) ;
V_9 += 4 ;
}
strncat ( V_73 , V_97 [ V_89 ] , V_88 - V_9 ) ;
V_9 += strlen ( V_97 [ V_89 ] ) ;
}
if ( * V_73 == '\0' )
strcpy ( V_73 , L_13 ) ;
if ( V_91 )
strncat ( V_73 , L_21 , V_88 - V_9 ) ;
if ( V_92 )
strncat ( V_73 , L_22 , V_88 - V_9 ) ;
return F_1 ( V_1 , V_2 , L_9 , V_17 , V_73 ) ;
}
static T_3
F_61 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
union V_78 V_79 ;
union V_78 V_80 ;
if ( V_12 -> V_75 )
V_79 = V_12 -> V_75 -> V_81 ;
else
V_79 . V_102 = V_103 ;
if ( V_13 -> V_75 )
V_80 = V_13 -> V_75 -> V_81 ;
else
V_80 . V_102 = V_103 ;
return ( T_3 ) ( V_80 . V_102 - V_79 . V_102 ) ;
}
static int F_62 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
char V_73 [ 64 ] ;
T_1 V_88 = sizeof( V_73 ) - 1 ;
T_1 V_89 , V_9 = 0 ;
T_4 V_90 = V_103 ;
V_73 [ 0 ] = '\0' ;
if ( V_16 -> V_75 )
V_90 = V_16 -> V_75 -> V_81 . V_102 ;
for ( V_89 = 0 ; V_90 && V_89 < V_104 ; V_89 ++ , V_90 >>= 1 ) {
if ( ! ( V_90 & 0x1 ) )
continue;
if ( V_9 ) {
strcat ( V_73 , L_20 ) ;
V_9 += 4 ;
}
strncat ( V_73 , V_105 [ V_89 ] , V_88 - V_9 ) ;
V_9 += strlen ( V_105 [ V_89 ] ) ;
}
if ( * V_73 == '\0' )
strcpy ( V_73 , L_13 ) ;
return F_1 ( V_1 , V_2 , L_9 , V_17 , V_73 ) ;
}
static inline T_4 F_63 ( T_4 V_106 )
{
return ( V_106 & ~ ( V_107 - 1 ) ) ;
}
static T_3
F_64 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
T_4 V_9 , V_10 ;
struct V_19 * V_108 , * V_109 ;
if ( ! V_12 -> V_75 ) return - 1 ;
if ( ! V_13 -> V_75 ) return 1 ;
if ( V_12 -> V_110 > V_13 -> V_110 ) return - 1 ;
if ( V_12 -> V_110 < V_13 -> V_110 ) return 1 ;
V_108 = V_12 -> V_75 -> V_76 . V_19 ;
V_109 = V_13 -> V_75 -> V_76 . V_19 ;
if ( ! V_108 && ! V_109 )
goto V_66;
if ( ! V_108 ) return - 1 ;
if ( ! V_109 ) return 1 ;
if ( V_108 -> V_111 > V_109 -> V_111 ) return - 1 ;
if ( V_108 -> V_111 < V_109 -> V_111 ) return 1 ;
if ( V_108 -> V_112 > V_109 -> V_112 ) return - 1 ;
if ( V_108 -> V_112 < V_109 -> V_112 ) return 1 ;
if ( V_108 -> V_113 > V_109 -> V_113 ) return - 1 ;
if ( V_108 -> V_113 < V_109 -> V_113 ) return 1 ;
if ( V_108 -> V_114 > V_109 -> V_114 ) return - 1 ;
if ( V_108 -> V_114 < V_109 -> V_114 ) return 1 ;
if ( ( V_12 -> V_110 != V_115 ) &&
( ! ( V_108 -> V_70 & V_116 ) ) &&
! V_108 -> V_111 && ! V_108 -> V_112 && ! V_108 -> V_113 &&
! V_108 -> V_114 ) {
if ( V_12 -> V_14 -> V_117 > V_13 -> V_14 -> V_117 ) return - 1 ;
if ( V_12 -> V_14 -> V_117 < V_13 -> V_14 -> V_117 ) return 1 ;
}
V_66:
V_9 = F_63 ( V_12 -> V_75 -> V_76 . V_118 ) ;
V_10 = F_63 ( V_13 -> V_75 -> V_76 . V_118 ) ;
if ( V_9 > V_10 ) return - 1 ;
if ( V_9 < V_10 ) return 1 ;
return 0 ;
}
static int F_65 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
T_5 V_66 = 0 ;
struct V_19 * V_19 = NULL ;
struct V_34 * V_40 = NULL ;
char V_44 = V_16 -> V_44 ;
if ( V_16 -> V_75 ) {
V_66 = F_63 ( V_16 -> V_75 -> V_76 . V_118 ) ;
V_19 = V_16 -> V_75 -> V_76 . V_19 ;
V_40 = V_16 -> V_75 -> V_76 . V_40 ;
if ( ( V_16 -> V_110 != V_115 ) &&
V_19 && ( V_19 -> type == V_47 ) &&
( V_19 -> V_70 & V_116 ) &&
( V_19 -> V_111 || V_19 -> V_112 || V_19 -> V_113 ||
V_19 -> V_114 ) )
V_44 = 's' ;
else if ( ! V_19 )
V_44 = 'X' ;
}
return F_20 ( V_19 , V_40 , V_66 , V_44 , V_1 , V_2 ,
V_17 ) ;
}
static T_4 F_66 ( struct V_11 * V_16 )
{
return V_16 -> V_119 . V_120 ? V_16 -> V_119 . V_121 / V_16 -> V_119 . V_120 : 0 ;
}
static T_3
F_67 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
return F_66 ( V_12 ) - F_66 ( V_13 ) ;
}
static int F_68 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
return F_1 ( V_1 , V_2 , L_23 , V_17 , F_66 ( V_16 ) ) ;
}
static T_3
F_69 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
return V_12 -> V_119 . V_121 - V_13 -> V_119 . V_121 ;
}
static int F_70 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
return F_1 ( V_1 , V_2 , L_23 , V_17 , V_16 -> V_119 . V_121 ) ;
}
static T_3
F_71 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
if ( ! V_12 -> V_60 || ! V_13 -> V_60 )
return F_2 ( V_12 -> V_60 , V_13 -> V_60 ) ;
return V_12 -> V_60 -> V_70 . abort !=
V_13 -> V_60 -> V_70 . abort ;
}
static int F_72 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
static const char * V_73 = L_13 ;
if ( V_16 -> V_60 ) {
if ( V_16 -> V_60 -> V_70 . abort )
V_73 = L_24 ;
else
V_73 = L_25 ;
}
return F_1 ( V_1 , V_2 , L_9 , V_17 , V_73 ) ;
}
static T_3
F_73 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
if ( ! V_12 -> V_60 || ! V_13 -> V_60 )
return F_2 ( V_12 -> V_60 , V_13 -> V_60 ) ;
return V_12 -> V_60 -> V_70 . V_122 !=
V_13 -> V_60 -> V_70 . V_122 ;
}
static int F_74 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
static const char * V_73 = L_13 ;
if ( V_16 -> V_60 ) {
if ( V_16 -> V_60 -> V_70 . V_122 )
V_73 = L_26 ;
else
V_73 = L_25 ;
}
return F_1 ( V_1 , V_2 , L_9 , V_17 , V_73 ) ;
}
static T_3
F_75 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
return V_12 -> V_123 - V_13 -> V_123 ;
}
static inline char * F_76 ( char * V_54 , const char * V_124 )
{
strcpy ( V_54 , V_124 ) ;
return V_54 + strlen ( V_124 ) ;
}
int F_77 ( void )
{
int V_89 ;
int V_49 = 0 ;
for ( V_89 = 0 ; V_125 [ V_89 ] . V_43 ; V_89 ++ ) {
if ( ! V_125 [ V_89 ] . V_126 )
V_49 += strlen ( V_125 [ V_89 ] . V_43 ) ;
}
V_49 += 4 ;
return V_49 ;
}
static int F_78 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
T_4 V_127 = V_16 -> V_123 ;
char V_128 [ 128 ] ;
char * V_54 = V_128 ;
int V_89 ;
V_128 [ 0 ] = 0 ;
for ( V_89 = 0 ; V_125 [ V_89 ] . V_43 ; V_89 ++ )
if ( V_125 [ V_89 ] . V_129 & V_127 )
V_54 = F_76 ( V_54 , V_125 [ V_89 ] . V_43 ) ;
if ( V_127 && ! ( V_127 & ( V_130 | V_131 ) ) )
V_54 = F_76 ( V_54 , L_27 ) ;
if ( V_127 & V_132 ) {
sprintf ( V_54 , L_28 V_133 ,
( V_127 & V_132 ) >>
V_134 ) ;
V_54 += strlen ( V_54 ) ;
}
return F_1 ( V_1 , V_2 , L_9 , V_17 , V_128 ) ;
}
bool F_79 ( struct V_135 * V_136 , struct V_135 * V_137 )
{
struct V_138 * V_139 ;
struct V_138 * V_140 ;
if ( ! F_80 ( V_136 ) || ! F_80 ( V_137 ) )
return false ;
V_139 = F_81 ( V_136 , struct V_138 , V_141 ) ;
V_140 = F_81 ( V_137 , struct V_138 , V_141 ) ;
return V_139 -> V_142 == V_140 -> V_142 ;
}
void F_82 ( struct V_135 * V_3 , struct V_143 * V_143 )
{
struct V_138 * V_144 ;
if ( ! F_80 ( V_3 ) )
return;
V_144 = F_81 ( V_3 , struct V_138 , V_141 ) ;
F_83 ( V_143 , V_144 -> V_142 -> V_145 , strlen ( V_3 -> V_43 ) ) ;
}
static int F_84 ( struct V_135 * V_3 , struct V_146 * V_141 ,
struct V_147 * V_148 )
{
struct V_138 * V_144 ;
T_1 V_49 = V_3 -> V_149 ;
V_144 = F_81 ( V_3 , struct V_138 , V_141 ) ;
if ( ! V_49 )
V_49 = F_85 ( F_86 ( V_148 ) , V_144 -> V_142 -> V_145 ) ;
return F_87 ( V_141 -> V_128 , V_141 -> V_2 , L_3 , V_49 , V_49 , V_3 -> V_43 ) ;
}
static int F_88 ( struct V_135 * V_3 ,
struct V_146 * V_141 V_150 ,
struct V_147 * V_148 )
{
struct V_138 * V_144 ;
T_1 V_49 = V_3 -> V_149 ;
V_144 = F_81 ( V_3 , struct V_138 , V_141 ) ;
if ( ! V_49 )
V_49 = F_85 ( F_86 ( V_148 ) , V_144 -> V_142 -> V_145 ) ;
return V_49 ;
}
static int F_89 ( struct V_135 * V_3 , struct V_146 * V_141 ,
struct V_11 * V_16 )
{
struct V_138 * V_144 ;
T_1 V_49 = V_3 -> V_149 ;
V_144 = F_81 ( V_3 , struct V_138 , V_141 ) ;
if ( ! V_49 )
V_49 = F_85 ( V_16 -> V_143 , V_144 -> V_142 -> V_145 ) ;
return V_144 -> V_142 -> V_151 ( V_16 , V_141 -> V_128 , V_141 -> V_2 , V_49 ) ;
}
static T_3 F_90 ( struct V_135 * V_3 ,
struct V_11 * V_136 , struct V_11 * V_137 )
{
struct V_138 * V_144 ;
V_144 = F_81 ( V_3 , struct V_138 , V_141 ) ;
return V_144 -> V_142 -> V_152 ( V_136 , V_137 ) ;
}
static T_3 F_91 ( struct V_135 * V_3 ,
struct V_11 * V_136 , struct V_11 * V_137 )
{
struct V_138 * V_144 ;
T_3 (* F_92)( struct V_11 * , struct V_11 * );
V_144 = F_81 ( V_3 , struct V_138 , V_141 ) ;
F_92 = V_144 -> V_142 -> V_153 ? : V_144 -> V_142 -> V_152 ;
return F_92 ( V_136 , V_137 ) ;
}
static T_3 F_93 ( struct V_135 * V_3 ,
struct V_11 * V_136 , struct V_11 * V_137 )
{
struct V_138 * V_144 ;
T_3 (* F_94)( struct V_11 * , struct V_11 * );
V_144 = F_81 ( V_3 , struct V_138 , V_141 ) ;
F_94 = V_144 -> V_142 -> V_154 ? : V_144 -> V_142 -> V_152 ;
return F_94 ( V_136 , V_137 ) ;
}
static struct V_138 *
F_95 ( struct V_155 * V_156 )
{
struct V_138 * V_144 ;
V_144 = malloc ( sizeof( * V_144 ) ) ;
if ( V_144 == NULL ) {
F_96 ( L_29 ) ;
return NULL ;
}
V_144 -> V_142 = V_156 -> V_157 ;
V_144 -> V_141 . V_43 = V_156 -> V_157 -> V_158 ;
V_144 -> V_141 . V_159 = F_84 ;
V_144 -> V_141 . V_17 = F_88 ;
V_144 -> V_141 . V_157 = F_89 ;
V_144 -> V_141 . V_160 = NULL ;
V_144 -> V_141 . V_161 = F_90 ;
V_144 -> V_141 . V_162 = F_91 ;
V_144 -> V_141 . V_163 = F_93 ;
F_97 ( & V_144 -> V_141 . V_164 ) ;
F_97 ( & V_144 -> V_141 . V_165 ) ;
V_144 -> V_141 . V_166 = false ;
V_144 -> V_141 . V_49 = 0 ;
V_144 -> V_141 . V_149 = 0 ;
return V_144 ;
}
bool F_80 ( struct V_135 * V_167 )
{
return V_167 -> V_159 == F_84 ;
}
static int F_98 ( struct V_155 * V_156 )
{
struct V_138 * V_144 = F_95 ( V_156 ) ;
if ( V_144 == NULL )
return - 1 ;
F_99 ( & V_144 -> V_141 ) ;
return 0 ;
}
static int F_100 ( struct V_155 * V_156 )
{
struct V_138 * V_144 = F_95 ( V_156 ) ;
if ( V_144 == NULL )
return - 1 ;
F_101 ( & V_144 -> V_141 ) ;
return 0 ;
}
static int F_102 ( struct V_155 * V_156 )
{
if ( V_156 -> V_168 )
return 0 ;
if ( F_98 ( V_156 ) < 0 )
return - 1 ;
if ( V_156 -> V_157 -> V_153 )
V_169 = 1 ;
V_156 -> V_168 = 1 ;
return 0 ;
}
static int F_103 ( struct V_170 * V_171 )
{
if ( ! V_171 -> V_168 ) {
V_171 -> V_168 = 1 ;
F_99 ( V_171 -> V_3 ) ;
}
return 0 ;
}
static int F_104 ( struct V_155 * V_156 )
{
if ( V_156 -> V_168 )
return 0 ;
if ( F_100 ( V_156 ) < 0 )
return - 1 ;
V_156 -> V_168 = 1 ;
return 0 ;
}
static int F_105 ( struct V_170 * V_171 )
{
if ( ! V_171 -> V_168 ) {
V_171 -> V_168 = 1 ;
F_101 ( V_171 -> V_3 ) ;
}
return 0 ;
}
int F_106 ( unsigned V_172 )
{
F_107 ( V_172 >= V_173 ) ;
return F_105 ( & V_174 [ V_172 ] ) ;
}
int F_108 ( const char * V_175 )
{
unsigned int V_89 ;
for ( V_89 = 0 ; V_89 < F_109 ( V_176 ) ; V_89 ++ ) {
struct V_155 * V_156 = & V_176 [ V_89 ] ;
if ( strncasecmp ( V_175 , V_156 -> V_43 , strlen ( V_175 ) ) )
continue;
if ( V_156 -> V_157 == & V_177 ) {
int V_39 = regcomp ( & V_178 , V_179 , V_180 ) ;
if ( V_39 ) {
char V_181 [ V_182 ] ;
regerror ( V_39 , & V_178 , V_181 , sizeof( V_181 ) ) ;
F_96 ( L_30 , V_179 , V_181 ) ;
return - V_183 ;
}
V_184 = 1 ;
} else if ( V_156 -> V_157 == & V_185 ) {
V_186 = 1 ;
if ( V_187 == V_188 )
V_156 -> V_157 -> V_153 = F_19 ;
} else if ( V_156 -> V_157 == & V_189 ) {
V_42 = 1 ;
} else if ( V_156 -> V_157 == & V_190 ) {
V_191 = 1 ;
}
return F_102 ( V_156 ) ;
}
for ( V_89 = 0 ; V_89 < F_109 ( V_174 ) ; V_89 ++ ) {
struct V_170 * V_171 = & V_174 [ V_89 ] ;
if ( strncasecmp ( V_175 , V_171 -> V_43 , strlen ( V_175 ) ) )
continue;
return F_103 ( V_171 ) ;
}
for ( V_89 = 0 ; V_89 < F_109 ( V_192 ) ; V_89 ++ ) {
struct V_155 * V_156 = & V_192 [ V_89 ] ;
if ( strncasecmp ( V_175 , V_156 -> V_43 , strlen ( V_175 ) ) )
continue;
if ( V_187 != V_193 )
return - V_183 ;
if ( V_156 -> V_157 == & V_194 || V_156 -> V_157 == & V_195 )
V_186 = 1 ;
F_102 ( V_156 ) ;
return 0 ;
}
for ( V_89 = 0 ; V_89 < F_109 ( V_196 ) ; V_89 ++ ) {
struct V_155 * V_156 = & V_196 [ V_89 ] ;
if ( strncasecmp ( V_175 , V_156 -> V_43 , strlen ( V_175 ) ) )
continue;
if ( V_187 != V_197 )
return - V_183 ;
if ( V_156 -> V_157 == & V_198 )
V_186 = 1 ;
F_102 ( V_156 ) ;
return 0 ;
}
return - V_199 ;
}
static const char * F_110 ( void )
{
const char * V_200 [] = {
V_201 ,
V_202 ,
V_203 ,
V_204 ,
V_205 ,
} ;
F_107 ( V_187 >= F_109 ( V_200 ) ) ;
return V_200 [ V_187 ] ;
}
static int F_111 ( void )
{
char * V_206 ;
if ( ! V_207 || F_112 ( V_207 ) )
return 0 ;
if ( V_207 [ 1 ] == '\0' ) {
error ( L_31 ) ;
return - V_183 ;
}
if ( F_113 ( & V_206 , L_32 ,
F_110 () , V_207 + 1 ) < 0 ) {
error ( L_33 ) ;
return - V_208 ;
}
V_207 = V_206 ;
return 0 ;
}
static int F_114 ( void )
{
char * V_209 , * V_175 , * V_124 ;
const char * V_210 ;
int V_39 = 0 ;
V_39 = F_111 () ;
if ( V_39 )
return V_39 ;
V_210 = V_207 ;
if ( V_210 == NULL ) {
if ( F_112 ( V_211 ) ) {
return 0 ;
}
V_210 = F_110 () ;
}
V_124 = F_115 ( V_210 ) ;
if ( V_124 == NULL ) {
error ( L_34 ) ;
return - V_208 ;
}
for ( V_175 = strtok_r ( V_124 , L_35 , & V_209 ) ;
V_175 ; V_175 = strtok_r ( NULL , L_35 , & V_209 ) ) {
V_39 = F_108 ( V_175 ) ;
if ( V_39 == - V_183 ) {
error ( L_36 , V_175 ) ;
break;
} else if ( V_39 == - V_199 ) {
error ( L_37 , V_175 ) ;
break;
}
}
free ( V_124 ) ;
return V_39 ;
}
void F_116 ( int V_212 , bool V_166 )
{
struct V_135 * V_3 ;
struct V_138 * V_144 ;
F_117 (fmt) {
if ( ! F_80 ( V_3 ) )
continue;
V_144 = F_81 ( V_3 , struct V_138 , V_141 ) ;
if ( V_144 -> V_142 -> V_145 == V_212 ) {
V_3 -> V_166 = V_166 ;
break;
}
}
}
static bool F_118 ( struct V_213 * V_164 , const char * V_214 , T_6 * V_215 )
{
if ( V_164 && F_119 ( V_164 ) == 1 ) {
if ( V_215 != NULL )
fprintf ( V_215 , L_38 , V_214 ,
F_120 ( V_164 , 0 ) -> V_216 ) ;
return true ;
}
return false ;
}
static bool F_121 ( int V_212 , T_6 * V_217 )
{
switch ( V_212 ) {
case V_218 :
return F_118 ( V_6 . V_219 , L_39 , V_217 ) ;
case V_220 :
return F_118 ( V_6 . V_221 , L_40 , V_217 ) ;
case V_222 :
return F_118 ( V_6 . V_223 , L_41 , V_217 ) ;
default:
break;
}
if ( V_187 != V_193 )
return false ;
switch ( V_212 ) {
case V_224 :
return F_118 ( V_6 . V_225 , L_42 , V_217 ) ;
case V_226 :
return F_118 ( V_6 . V_227 , L_43 , V_217 ) ;
case V_228 :
return F_118 ( V_6 . V_229 , L_44 , V_217 ) ;
case V_230 :
return F_118 ( V_6 . V_231 , L_45 , V_217 ) ;
default:
break;
}
return false ;
}
void F_122 ( T_6 * V_217 )
{
struct V_135 * V_3 ;
struct V_138 * V_144 ;
F_117 (fmt) {
if ( ! F_80 ( V_3 ) )
continue;
V_144 = F_81 ( V_3 , struct V_138 , V_141 ) ;
V_3 -> V_166 = F_121 ( V_144 -> V_142 -> V_145 , V_217 ) ;
}
F_117 (fmt) {
if ( ! F_80 ( V_3 ) )
continue;
if ( ! V_3 -> V_166 )
return;
}
F_117 (fmt) {
if ( ! F_80 ( V_3 ) )
continue;
V_3 -> V_166 = false ;
}
}
static int F_123 ( char * V_175 )
{
unsigned int V_89 ;
for ( V_89 = 0 ; V_89 < F_109 ( V_176 ) ; V_89 ++ ) {
struct V_155 * V_156 = & V_176 [ V_89 ] ;
if ( strncasecmp ( V_175 , V_156 -> V_43 , strlen ( V_175 ) ) )
continue;
return F_104 ( V_156 ) ;
}
for ( V_89 = 0 ; V_89 < F_109 ( V_174 ) ; V_89 ++ ) {
struct V_170 * V_171 = & V_174 [ V_89 ] ;
if ( strncasecmp ( V_175 , V_171 -> V_43 , strlen ( V_175 ) ) )
continue;
return F_105 ( V_171 ) ;
}
for ( V_89 = 0 ; V_89 < F_109 ( V_192 ) ; V_89 ++ ) {
struct V_155 * V_156 = & V_192 [ V_89 ] ;
if ( strncasecmp ( V_175 , V_156 -> V_43 , strlen ( V_175 ) ) )
continue;
return F_104 ( V_156 ) ;
}
for ( V_89 = 0 ; V_89 < F_109 ( V_196 ) ; V_89 ++ ) {
struct V_155 * V_156 = & V_196 [ V_89 ] ;
if ( strncasecmp ( V_175 , V_156 -> V_43 , strlen ( V_175 ) ) )
continue;
return F_104 ( V_156 ) ;
}
return - V_199 ;
}
static void F_124 ( void )
{
unsigned int V_89 ;
for ( V_89 = 0 ; V_89 < F_109 ( V_176 ) ; V_89 ++ )
V_176 [ V_89 ] . V_168 = 0 ;
for ( V_89 = 0 ; V_89 < F_109 ( V_174 ) ; V_89 ++ )
V_174 [ V_89 ] . V_168 = 0 ;
for ( V_89 = 0 ; V_89 < F_109 ( V_192 ) ; V_89 ++ )
V_192 [ V_89 ] . V_168 = 0 ;
for ( V_89 = 0 ; V_89 < F_109 ( V_196 ) ; V_89 ++ )
V_196 [ V_89 ] . V_168 = 0 ;
}
bool F_112 ( const char * V_232 )
{
return V_232 && ( * V_232 != '+' ) ;
}
static int F_125 ( void )
{
char * V_209 , * V_175 , * V_124 , * V_233 ;
int V_39 = - V_183 ;
if ( V_211 == NULL )
return 0 ;
V_233 = V_124 = F_115 ( V_211 ) ;
if ( V_124 == NULL ) {
error ( L_46 ) ;
return - V_208 ;
}
if ( ! F_112 ( V_211 ) )
V_233 ++ ;
if ( ! strlen ( V_233 ) ) {
error ( L_47 ) ;
goto V_73;
}
for ( V_175 = strtok_r ( V_233 , L_35 , & V_209 ) ;
V_175 ; V_175 = strtok_r ( NULL , L_35 , & V_209 ) ) {
V_39 = F_123 ( V_175 ) ;
if ( V_39 == - V_183 ) {
error ( L_48 , V_175 ) ;
break;
} else if ( V_39 == - V_199 ) {
error ( L_49 , V_175 ) ;
break;
}
}
V_73:
free ( V_124 ) ;
return V_39 ;
}
int F_126 ( void )
{
int V_181 ;
V_181 = F_114 () ;
if ( V_181 < 0 )
return V_181 ;
if ( V_179 != V_234 ) {
V_181 = F_108 ( L_50 ) ;
if ( V_181 < 0 )
return V_181 ;
}
F_124 () ;
if ( V_187 != V_188 )
F_127 () ;
V_181 = F_125 () ;
if ( V_181 < 0 )
return V_181 ;
F_128 () ;
F_129 () ;
return 0 ;
}
void F_130 ( void )
{
V_169 = 0 ;
V_184 = 0 ;
V_186 = 0 ;
V_42 = 0 ;
V_211 = NULL ;
V_207 = NULL ;
F_124 () ;
F_131 () ;
}
