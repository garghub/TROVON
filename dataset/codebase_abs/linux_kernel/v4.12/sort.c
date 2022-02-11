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
V_17 = F_6 ( 7U , V_17 ) - 8 ;
return F_1 ( V_1 , V_2 , L_1 , V_16 -> V_14 -> V_15 ,
V_17 , V_17 , V_18 ? : L_2 ) ;
}
static int F_7 ( struct V_11 * V_16 , int type , const void * V_19 )
{
const struct V_14 * V_20 = V_19 ;
if ( type != V_21 )
return - 1 ;
return V_20 && V_16 -> V_14 != V_20 ;
}
static T_3
F_8 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
return strcmp ( F_9 ( V_13 -> V_18 ) , F_9 ( V_12 -> V_18 ) ) ;
}
static T_3
F_10 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
return strcmp ( F_9 ( V_13 -> V_18 ) , F_9 ( V_12 -> V_18 ) ) ;
}
static T_3
F_11 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
return strcmp ( F_9 ( V_13 -> V_18 ) , F_9 ( V_12 -> V_18 ) ) ;
}
static int F_12 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
return F_1 ( V_1 , V_2 , L_3 , V_17 , V_17 , F_9 ( V_16 -> V_18 ) ) ;
}
static T_3 F_13 ( struct V_22 * V_23 , struct V_22 * V_24 )
{
struct V_25 * V_26 = V_23 ? V_23 -> V_25 : NULL ;
struct V_25 * V_27 = V_24 ? V_24 -> V_25 : NULL ;
const char * V_28 , * V_29 ;
if ( ! V_26 || ! V_27 )
return F_2 ( V_27 , V_26 ) ;
if ( V_30 > 0 ) {
V_28 = V_26 -> V_31 ;
V_29 = V_27 -> V_31 ;
} else {
V_28 = V_26 -> V_32 ;
V_29 = V_27 -> V_32 ;
}
return strcmp ( V_28 , V_29 ) ;
}
static T_3
F_14 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
return F_13 ( V_13 -> V_33 . V_22 , V_12 -> V_33 . V_22 ) ;
}
static int F_15 ( struct V_22 * V_22 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
if ( V_22 && V_22 -> V_25 ) {
const char * V_34 = V_30 > 0 ? V_22 -> V_25 -> V_31 :
V_22 -> V_25 -> V_32 ;
return F_1 ( V_1 , V_2 , L_3 , V_17 , V_17 , V_34 ) ;
}
return F_1 ( V_1 , V_2 , L_3 , V_17 , V_17 , L_4 ) ;
}
static int F_16 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
return F_15 ( V_16 -> V_33 . V_22 , V_1 , V_2 , V_17 ) ;
}
static int F_17 ( struct V_11 * V_16 , int type , const void * V_19 )
{
const struct V_25 * V_25 = V_19 ;
if ( type != V_35 )
return - 1 ;
return V_25 && ( ! V_16 -> V_33 . V_22 || V_16 -> V_33 . V_22 -> V_25 != V_25 ) ;
}
static T_3 F_18 ( T_4 V_36 , T_4 V_37 )
{
return ( T_3 ) ( V_37 - V_36 ) ;
}
static T_3 F_19 ( struct V_38 * V_39 , struct V_38 * V_40 )
{
if ( ! V_39 || ! V_40 )
return F_2 ( V_39 , V_40 ) ;
if ( V_39 == V_40 )
return 0 ;
if ( V_39 -> V_41 != V_40 -> V_41 )
return ( T_3 ) ( V_40 -> V_41 - V_39 -> V_41 ) ;
return ( T_3 ) ( V_40 -> V_42 - V_39 -> V_42 ) ;
}
static T_3
F_20 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
T_3 V_43 ;
if ( ! V_12 -> V_33 . V_44 && ! V_13 -> V_33 . V_44 )
return F_18 ( V_12 -> V_45 , V_13 -> V_45 ) ;
if ( ! F_21 ( V_12 -> V_46 , V_25 ) || F_21 ( V_13 -> V_46 , V_25 ) ) {
V_43 = F_14 ( V_12 , V_13 ) ;
if ( V_43 != 0 )
return V_43 ;
}
return F_19 ( V_12 -> V_33 . V_44 , V_13 -> V_33 . V_44 ) ;
}
static T_3
F_22 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
if ( ! V_12 -> V_33 . V_44 || ! V_13 -> V_33 . V_44 )
return F_2 ( V_12 -> V_33 . V_44 , V_13 -> V_33 . V_44 ) ;
return strcmp ( V_13 -> V_33 . V_44 -> V_47 , V_12 -> V_33 . V_44 -> V_47 ) ;
}
static int F_23 ( struct V_22 * V_22 , struct V_38 * V_44 ,
T_4 V_45 , char V_48 , char * V_1 , T_1 V_2 ,
unsigned int V_17 )
{
T_1 V_43 = 0 ;
if ( V_30 > 0 ) {
char V_49 = V_22 ? F_24 ( V_22 -> V_25 ) : '!' ;
V_43 += F_1 ( V_1 , V_2 , L_5 ,
V_50 / 4 + 2 , V_45 , V_49 ) ;
}
V_43 += F_1 ( V_1 + V_43 , V_2 - V_43 , L_6 , V_48 ) ;
if ( V_44 && V_22 ) {
if ( V_22 -> type == V_51 ) {
V_43 += F_1 ( V_1 + V_43 , V_2 - V_43 , L_7 , V_44 -> V_47 ) ;
V_43 += F_1 ( V_1 + V_43 , V_2 - V_43 , L_8 ,
V_45 - V_22 -> V_52 ( V_22 , V_44 -> V_41 ) ) ;
} else {
V_43 += F_1 ( V_1 + V_43 , V_2 - V_43 , L_9 ,
V_17 - V_43 ,
V_44 -> V_47 ) ;
}
} else {
T_1 V_53 = V_50 / 4 ;
V_43 += F_1 ( V_1 + V_43 , V_2 - V_43 , L_10 ,
V_53 , V_45 ) ;
}
return V_43 ;
}
static int F_25 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
return F_23 ( V_16 -> V_33 . V_22 , V_16 -> V_33 . V_44 , V_16 -> V_45 ,
V_16 -> V_48 , V_1 , V_2 , V_17 ) ;
}
static int F_26 ( struct V_11 * V_16 , int type , const void * V_19 )
{
const char * V_44 = V_19 ;
if ( type != V_54 )
return - 1 ;
return V_44 && ( ! V_16 -> V_33 . V_44 || ! strstr ( V_16 -> V_33 . V_44 -> V_47 , V_44 ) ) ;
}
char * F_27 ( struct V_11 * V_16 )
{
struct V_22 * V_22 = V_16 -> V_33 . V_22 ;
if ( ! V_22 )
return V_55 ;
return F_28 ( V_22 -> V_25 , F_29 ( V_22 , V_16 -> V_45 ) ,
V_16 -> V_33 . V_44 , true , true ) ;
}
static T_3
F_30 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
if ( ! V_12 -> V_56 )
V_12 -> V_56 = F_27 ( V_12 ) ;
if ( ! V_13 -> V_56 )
V_13 -> V_56 = F_27 ( V_13 ) ;
return strcmp ( V_13 -> V_56 , V_12 -> V_56 ) ;
}
static int F_31 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
if ( ! V_16 -> V_56 )
V_16 -> V_56 = F_27 ( V_16 ) ;
return F_1 ( V_1 , V_2 , L_11 , V_17 , V_16 -> V_56 ) ;
}
static T_3
F_32 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
if ( ! V_12 -> V_57 -> V_58 ) {
struct V_22 * V_22 = V_12 -> V_57 -> V_59 . V_22 ;
if ( ! V_22 )
V_12 -> V_57 -> V_58 = V_55 ;
else
V_12 -> V_57 -> V_58 = F_28 ( V_22 -> V_25 ,
F_29 ( V_22 ,
V_12 -> V_57 -> V_59 . V_60 ) ,
V_12 -> V_57 -> V_59 . V_44 ,
true , true ) ;
}
if ( ! V_13 -> V_57 -> V_58 ) {
struct V_22 * V_22 = V_13 -> V_57 -> V_59 . V_22 ;
if ( ! V_22 )
V_13 -> V_57 -> V_58 = V_55 ;
else
V_13 -> V_57 -> V_58 = F_28 ( V_22 -> V_25 ,
F_29 ( V_22 ,
V_13 -> V_57 -> V_59 . V_60 ) ,
V_13 -> V_57 -> V_59 . V_44 ,
true , true ) ;
}
return strcmp ( V_13 -> V_57 -> V_58 , V_12 -> V_57 -> V_58 ) ;
}
static int F_33 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
return F_1 ( V_1 , V_2 , L_3 , V_17 , V_17 , V_16 -> V_57 -> V_58 ) ;
}
static T_3
F_34 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
if ( ! V_12 -> V_57 -> V_61 ) {
struct V_22 * V_22 = V_12 -> V_57 -> V_62 . V_22 ;
if ( ! V_22 )
V_12 -> V_57 -> V_61 = V_55 ;
else
V_12 -> V_57 -> V_61 = F_28 ( V_22 -> V_25 ,
F_29 ( V_22 ,
V_12 -> V_57 -> V_62 . V_60 ) ,
V_12 -> V_57 -> V_59 . V_44 ,
true , true ) ;
}
if ( ! V_13 -> V_57 -> V_61 ) {
struct V_22 * V_22 = V_13 -> V_57 -> V_62 . V_22 ;
if ( ! V_22 )
V_13 -> V_57 -> V_61 = V_55 ;
else
V_13 -> V_57 -> V_61 = F_28 ( V_22 -> V_25 ,
F_29 ( V_22 ,
V_13 -> V_57 -> V_62 . V_60 ) ,
V_13 -> V_57 -> V_62 . V_44 ,
true , true ) ;
}
return strcmp ( V_13 -> V_57 -> V_61 , V_12 -> V_57 -> V_61 ) ;
}
static int F_35 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
return F_1 ( V_1 , V_2 , L_3 , V_17 , V_17 , V_16 -> V_57 -> V_61 ) ;
}
static char * F_36 ( struct V_11 * V_63 )
{
char * V_64 , * V_65 ;
struct V_22 * V_22 = V_63 -> V_33 . V_22 ;
if ( ! V_22 )
return V_66 ;
V_64 = F_37 ( V_22 -> V_25 , F_29 ( V_22 , V_63 -> V_45 ) ,
V_63 -> V_33 . V_44 , false , true , true ) ;
if ( ! strcmp ( V_64 , V_55 ) )
return V_66 ;
V_65 = strchr ( V_64 , ':' ) ;
if ( V_65 && * V_64 ) {
* V_65 = 0 ;
return V_64 ;
}
free ( V_64 ) ;
return V_66 ;
}
static T_3
F_38 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
if ( ! V_12 -> V_67 )
V_12 -> V_67 = F_36 ( V_12 ) ;
if ( ! V_13 -> V_67 )
V_13 -> V_67 = F_36 ( V_13 ) ;
return strcmp ( V_13 -> V_67 , V_12 -> V_67 ) ;
}
static int F_39 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
if ( ! V_16 -> V_67 )
V_16 -> V_67 = F_36 ( V_16 ) ;
return F_1 ( V_1 , V_2 , L_11 , V_17 , V_16 -> V_67 ) ;
}
static T_3
F_40 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
struct V_38 * V_39 = V_12 -> V_68 ;
struct V_38 * V_40 = V_13 -> V_68 ;
if ( ! V_39 || ! V_40 )
return F_2 ( V_39 , V_40 ) ;
return strcmp ( V_40 -> V_47 , V_39 -> V_47 ) ;
}
static int F_41 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
return F_1 ( V_1 , V_2 , L_3 , V_17 , V_17 ,
V_16 -> V_68 ? V_16 -> V_68 -> V_47 : L_12 ) ;
}
static T_3
F_42 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
return V_13 -> V_69 - V_12 -> V_69 ;
}
static int F_43 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
return F_1 ( V_1 , V_2 , L_13 , V_17 , V_17 , V_16 -> V_69 ) ;
}
static T_3 F_44 ( T_4 V_70 , T_4 V_71 )
{
return ( T_3 ) ( V_71 - V_70 ) ;
}
static T_3 F_45 ( T_4 V_72 , T_4 V_73 )
{
return ( T_3 ) ( V_73 - V_72 ) ;
}
static T_3
F_46 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
T_3 V_43 ;
V_43 = F_44 ( V_13 -> V_74 . V_75 , V_12 -> V_74 . V_75 ) ;
if ( V_43 != 0 )
return V_43 ;
return F_45 ( V_13 -> V_74 . V_76 ,
V_12 -> V_74 . V_76 ) ;
}
static int F_47 ( struct V_11 * V_16 ,
char * V_1 , T_1 V_2 ,
unsigned int V_17 V_77 )
{
return F_1 ( V_1 , V_2 , L_14 , V_16 -> V_74 . V_75 ,
V_16 -> V_74 . V_76 ) ;
}
static T_3
F_48 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
return V_13 -> V_78 - V_12 -> V_78 ;
}
static int F_49 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
return F_1 ( V_1 , V_2 , L_13 , V_17 , V_17 - 3 , V_16 -> V_78 ) ;
}
static int F_50 ( struct V_11 * V_16 , int type , const void * V_19 )
{
int V_79 = * ( const int * ) V_19 ;
if ( type != V_80 )
return - 1 ;
return V_79 >= 0 && V_16 -> V_78 != V_79 ;
}
static char * F_51 ( struct V_11 * V_16 )
{
struct V_81 V_82 ;
struct V_83 * V_84 ;
struct V_85 V_86 = {
. V_87 = V_16 -> V_88 ,
. V_2 = V_16 -> V_89 ,
} ;
V_84 = F_52 ( V_16 -> V_46 ) ;
F_53 ( & V_82 ) ;
if ( V_6 . V_90 ) {
F_54 ( & V_82 , V_16 -> V_88 , V_16 -> V_89 ,
V_84 -> V_91 ) ;
} else {
F_55 ( & V_82 , V_84 -> V_91 , & V_86 ) ;
}
return realloc ( V_82 . V_92 , V_82 . V_53 + 1 ) ;
}
static T_3
F_56 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
struct V_83 * V_84 ;
V_84 = F_52 ( V_12 -> V_46 ) ;
if ( V_84 -> V_93 . type != V_94 )
return 0 ;
if ( V_12 -> V_95 == NULL )
V_12 -> V_95 = F_51 ( V_12 ) ;
if ( V_13 -> V_95 == NULL )
V_13 -> V_95 = F_51 ( V_13 ) ;
return strcmp ( V_13 -> V_95 , V_12 -> V_95 ) ;
}
static int F_57 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
struct V_83 * V_84 ;
V_84 = F_52 ( V_16 -> V_46 ) ;
if ( V_84 -> V_93 . type != V_94 )
return F_58 ( V_1 , V_2 , L_11 , V_17 , L_15 ) ;
if ( V_16 -> V_95 == NULL )
V_16 -> V_95 = F_51 ( V_16 ) ;
return F_1 ( V_1 , V_2 , L_11 , V_17 , V_16 -> V_95 ) ;
}
static T_3
F_59 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
if ( ! V_12 -> V_57 || ! V_13 -> V_57 )
return F_2 ( V_12 -> V_57 , V_13 -> V_57 ) ;
return F_13 ( V_12 -> V_57 -> V_59 . V_22 ,
V_13 -> V_57 -> V_59 . V_22 ) ;
}
static int F_60 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
if ( V_16 -> V_57 )
return F_15 ( V_16 -> V_57 -> V_59 . V_22 ,
V_1 , V_2 , V_17 ) ;
else
return F_1 ( V_1 , V_2 , L_3 , V_17 , V_17 , L_15 ) ;
}
static int F_61 ( struct V_11 * V_16 , int type ,
const void * V_19 )
{
const struct V_25 * V_25 = V_19 ;
if ( type != V_35 )
return - 1 ;
return V_25 && ( ! V_16 -> V_57 || ! V_16 -> V_57 -> V_59 . V_22 ||
V_16 -> V_57 -> V_59 . V_22 -> V_25 != V_25 ) ;
}
static T_3
F_62 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
if ( ! V_12 -> V_57 || ! V_13 -> V_57 )
return F_2 ( V_12 -> V_57 , V_13 -> V_57 ) ;
return F_13 ( V_12 -> V_57 -> V_62 . V_22 ,
V_13 -> V_57 -> V_62 . V_22 ) ;
}
static int F_63 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
if ( V_16 -> V_57 )
return F_15 ( V_16 -> V_57 -> V_62 . V_22 ,
V_1 , V_2 , V_17 ) ;
else
return F_1 ( V_1 , V_2 , L_3 , V_17 , V_17 , L_15 ) ;
}
static int F_64 ( struct V_11 * V_16 , int type ,
const void * V_19 )
{
const struct V_25 * V_25 = V_19 ;
if ( type != V_35 )
return - 1 ;
return V_25 && ( ! V_16 -> V_57 || ! V_16 -> V_57 -> V_62 . V_22 ||
V_16 -> V_57 -> V_62 . V_22 -> V_25 != V_25 ) ;
}
static T_3
F_65 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
struct V_96 * V_97 = & V_12 -> V_57 -> V_59 ;
struct V_96 * V_98 = & V_13 -> V_57 -> V_59 ;
if ( ! V_12 -> V_57 || ! V_13 -> V_57 )
return F_2 ( V_12 -> V_57 , V_13 -> V_57 ) ;
V_97 = & V_12 -> V_57 -> V_59 ;
V_98 = & V_13 -> V_57 -> V_59 ;
if ( ! V_97 -> V_44 && ! V_98 -> V_44 )
return F_18 ( V_97 -> V_99 , V_98 -> V_99 ) ;
return F_19 ( V_97 -> V_44 , V_98 -> V_44 ) ;
}
static T_3
F_66 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
struct V_96 * V_100 , * V_101 ;
if ( ! V_12 -> V_57 || ! V_13 -> V_57 )
return F_2 ( V_12 -> V_57 , V_13 -> V_57 ) ;
V_100 = & V_12 -> V_57 -> V_62 ;
V_101 = & V_13 -> V_57 -> V_62 ;
if ( ! V_100 -> V_44 && ! V_101 -> V_44 )
return F_18 ( V_100 -> V_99 , V_101 -> V_99 ) ;
return F_19 ( V_100 -> V_44 , V_101 -> V_44 ) ;
}
static int F_67 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
if ( V_16 -> V_57 ) {
struct V_96 * V_59 = & V_16 -> V_57 -> V_59 ;
return F_23 ( V_59 -> V_22 , V_59 -> V_44 , V_59 -> V_99 ,
V_16 -> V_48 , V_1 , V_2 , V_17 ) ;
}
return F_1 ( V_1 , V_2 , L_3 , V_17 , V_17 , L_15 ) ;
}
static int F_68 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
if ( V_16 -> V_57 ) {
struct V_96 * V_62 = & V_16 -> V_57 -> V_62 ;
return F_23 ( V_62 -> V_22 , V_62 -> V_44 , V_62 -> V_99 ,
V_16 -> V_48 , V_1 , V_2 , V_17 ) ;
}
return F_1 ( V_1 , V_2 , L_3 , V_17 , V_17 , L_15 ) ;
}
static int F_69 ( struct V_11 * V_16 , int type ,
const void * V_19 )
{
const char * V_44 = V_19 ;
if ( type != V_54 )
return - 1 ;
return V_44 && ! ( V_16 -> V_57 && V_16 -> V_57 -> V_59 . V_44 &&
strstr ( V_16 -> V_57 -> V_59 . V_44 -> V_47 , V_44 ) ) ;
}
static int F_70 ( struct V_11 * V_16 , int type ,
const void * V_19 )
{
const char * V_44 = V_19 ;
if ( type != V_54 )
return - 1 ;
return V_44 && ! ( V_16 -> V_57 && V_16 -> V_57 -> V_62 . V_44 &&
strstr ( V_16 -> V_57 -> V_62 . V_44 -> V_47 , V_44 ) ) ;
}
static T_3
F_71 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
unsigned char V_102 , V_65 ;
if ( ! V_12 -> V_57 || ! V_13 -> V_57 )
return F_2 ( V_12 -> V_57 , V_13 -> V_57 ) ;
V_102 = V_12 -> V_57 -> V_103 . V_104 != V_13 -> V_57 -> V_103 . V_104 ;
V_65 = V_12 -> V_57 -> V_103 . V_105 != V_13 -> V_57 -> V_103 . V_105 ;
return V_102 || V_65 ;
}
static int F_72 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 ) {
static const char * V_106 = L_15 ;
if ( V_16 -> V_57 ) {
if ( V_16 -> V_57 -> V_103 . V_105 )
V_106 = L_16 ;
else if ( V_16 -> V_57 -> V_103 . V_104 )
V_106 = L_17 ;
}
return F_1 ( V_1 , V_2 , L_3 , V_17 , V_17 , V_106 ) ;
}
static T_3
F_73 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
if ( ! V_12 -> V_57 || ! V_13 -> V_57 )
return F_2 ( V_12 -> V_57 , V_13 -> V_57 ) ;
return V_12 -> V_57 -> V_103 . V_107 -
V_13 -> V_57 -> V_103 . V_107 ;
}
static int F_74 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
if ( ! V_16 -> V_57 )
return F_58 ( V_1 , V_2 , L_11 , V_17 , L_15 ) ;
if ( V_16 -> V_57 -> V_103 . V_107 == 0 )
return F_1 ( V_1 , V_2 , L_18 , V_17 , L_19 ) ;
return F_1 ( V_1 , V_2 , L_20 , V_17 ,
V_16 -> V_57 -> V_103 . V_107 ) ;
}
T_3
F_75 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
T_5 V_9 = 0 , V_10 = 0 ;
if ( V_12 -> V_108 )
V_9 = V_12 -> V_108 -> V_109 . V_99 ;
if ( V_13 -> V_108 )
V_10 = V_13 -> V_108 -> V_109 . V_99 ;
return ( T_3 ) ( V_10 - V_9 ) ;
}
static int F_76 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
T_5 V_99 = 0 ;
struct V_22 * V_22 = NULL ;
struct V_38 * V_44 = NULL ;
if ( V_16 -> V_108 ) {
V_99 = V_16 -> V_108 -> V_109 . V_99 ;
V_22 = V_16 -> V_108 -> V_109 . V_22 ;
V_44 = V_16 -> V_108 -> V_109 . V_44 ;
}
return F_23 ( V_22 , V_44 , V_99 , V_16 -> V_48 , V_1 , V_2 ,
V_17 ) ;
}
T_3
F_77 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
T_5 V_9 = 0 , V_10 = 0 ;
if ( V_12 -> V_108 )
V_9 = V_12 -> V_108 -> V_110 . V_99 ;
if ( V_13 -> V_108 )
V_10 = V_13 -> V_108 -> V_110 . V_99 ;
return ( T_3 ) ( V_10 - V_9 ) ;
}
static int F_78 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
T_5 V_99 = 0 ;
struct V_22 * V_22 = NULL ;
struct V_38 * V_44 = NULL ;
if ( V_16 -> V_108 ) {
V_99 = V_16 -> V_108 -> V_110 . V_99 ;
V_22 = V_16 -> V_108 -> V_110 . V_22 ;
V_44 = V_16 -> V_108 -> V_110 . V_44 ;
}
return F_23 ( V_22 , V_44 , V_99 , V_16 -> V_48 , V_1 , V_2 ,
V_17 ) ;
}
static T_3
F_79 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
struct V_22 * V_23 = NULL ;
struct V_22 * V_24 = NULL ;
if ( V_12 -> V_108 )
V_23 = V_12 -> V_108 -> V_109 . V_22 ;
if ( V_13 -> V_108 )
V_24 = V_13 -> V_108 -> V_109 . V_22 ;
return F_13 ( V_23 , V_24 ) ;
}
static int F_80 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
struct V_22 * V_22 = NULL ;
if ( V_16 -> V_108 )
V_22 = V_16 -> V_108 -> V_109 . V_22 ;
return F_15 ( V_22 , V_1 , V_2 , V_17 ) ;
}
static T_3
F_81 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
union V_111 V_112 ;
union V_111 V_113 ;
if ( V_12 -> V_108 )
V_112 = V_12 -> V_108 -> V_114 ;
else
V_112 . V_115 = V_116 ;
if ( V_13 -> V_108 )
V_113 = V_13 -> V_108 -> V_114 ;
else
V_113 . V_115 = V_116 ;
return ( T_3 ) ( V_113 . V_115 - V_112 . V_115 ) ;
}
static int F_82 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
char V_106 [ 10 ] ;
F_83 ( V_106 , sizeof( V_106 ) , V_16 -> V_108 ) ;
return F_1 ( V_1 , V_2 , L_9 , V_17 , V_106 ) ;
}
static T_3
F_84 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
union V_111 V_112 ;
union V_111 V_113 ;
if ( V_12 -> V_108 )
V_112 = V_12 -> V_108 -> V_114 ;
else
V_112 . V_117 = V_118 ;
if ( V_13 -> V_108 )
V_113 = V_13 -> V_108 -> V_114 ;
else
V_113 . V_117 = V_118 ;
return ( T_3 ) ( V_113 . V_117 - V_112 . V_117 ) ;
}
static int F_85 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
char V_106 [ 64 ] ;
F_86 ( V_106 , sizeof( V_106 ) , V_16 -> V_108 ) ;
return F_1 ( V_1 , V_2 , L_18 , V_17 , V_106 ) ;
}
static T_3
F_87 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
union V_111 V_112 ;
union V_111 V_113 ;
if ( V_12 -> V_108 )
V_112 = V_12 -> V_108 -> V_114 ;
else
V_112 . V_119 = V_120 ;
if ( V_13 -> V_108 )
V_113 = V_13 -> V_108 -> V_114 ;
else
V_113 . V_119 = V_120 ;
return ( T_3 ) ( V_113 . V_119 - V_112 . V_119 ) ;
}
static int F_88 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
char V_106 [ 64 ] ;
F_89 ( V_106 , sizeof( V_106 ) , V_16 -> V_108 ) ;
return F_1 ( V_1 , V_2 , L_18 , V_17 , V_106 ) ;
}
static T_3
F_90 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
union V_111 V_112 ;
union V_111 V_113 ;
if ( V_12 -> V_108 )
V_112 = V_12 -> V_108 -> V_114 ;
else
V_112 . V_121 = V_122 ;
if ( V_13 -> V_108 )
V_113 = V_13 -> V_108 -> V_114 ;
else
V_113 . V_121 = V_122 ;
return ( T_3 ) ( V_113 . V_121 - V_112 . V_121 ) ;
}
static int F_91 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
char V_106 [ 64 ] ;
F_92 ( V_106 , sizeof( V_106 ) , V_16 -> V_108 ) ;
return F_1 ( V_1 , V_2 , L_18 , V_17 , V_106 ) ;
}
T_3
F_93 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
T_4 V_9 , V_10 ;
struct V_22 * V_123 , * V_124 ;
if ( ! V_12 -> V_108 ) return - 1 ;
if ( ! V_13 -> V_108 ) return 1 ;
if ( V_12 -> V_125 > V_13 -> V_125 ) return - 1 ;
if ( V_12 -> V_125 < V_13 -> V_125 ) return 1 ;
V_123 = V_12 -> V_108 -> V_109 . V_22 ;
V_124 = V_13 -> V_108 -> V_109 . V_22 ;
if ( ! V_123 && ! V_124 )
goto V_99;
if ( ! V_123 ) return - 1 ;
if ( ! V_124 ) return 1 ;
if ( V_123 -> V_126 > V_124 -> V_126 ) return - 1 ;
if ( V_123 -> V_126 < V_124 -> V_126 ) return 1 ;
if ( V_123 -> V_127 > V_124 -> V_127 ) return - 1 ;
if ( V_123 -> V_127 < V_124 -> V_127 ) return 1 ;
if ( V_123 -> V_76 > V_124 -> V_76 ) return - 1 ;
if ( V_123 -> V_76 < V_124 -> V_76 ) return 1 ;
if ( V_123 -> V_128 > V_124 -> V_128 ) return - 1 ;
if ( V_123 -> V_128 < V_124 -> V_128 ) return 1 ;
if ( ( V_12 -> V_125 != V_129 ) &&
( ! ( V_123 -> V_103 & V_130 ) ) &&
! V_123 -> V_126 && ! V_123 -> V_127 && ! V_123 -> V_76 &&
! V_123 -> V_128 ) {
if ( V_12 -> V_14 -> V_131 > V_13 -> V_14 -> V_131 ) return - 1 ;
if ( V_12 -> V_14 -> V_131 < V_13 -> V_14 -> V_131 ) return 1 ;
}
V_99:
V_9 = F_94 ( V_12 -> V_108 -> V_109 . V_60 ) ;
V_10 = F_94 ( V_13 -> V_108 -> V_109 . V_60 ) ;
if ( V_9 > V_10 ) return - 1 ;
if ( V_9 < V_10 ) return 1 ;
return 0 ;
}
static int F_95 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
T_5 V_99 = 0 ;
struct V_22 * V_22 = NULL ;
struct V_38 * V_44 = NULL ;
char V_48 = V_16 -> V_48 ;
if ( V_16 -> V_108 ) {
V_99 = F_94 ( V_16 -> V_108 -> V_109 . V_60 ) ;
V_22 = V_16 -> V_108 -> V_109 . V_22 ;
V_44 = V_16 -> V_108 -> V_109 . V_44 ;
if ( ( V_16 -> V_125 != V_129 ) &&
V_22 && ( V_22 -> type == V_51 ) &&
( V_22 -> V_103 & V_130 ) &&
( V_22 -> V_126 || V_22 -> V_127 || V_22 -> V_76 ||
V_22 -> V_128 ) )
V_48 = 's' ;
else if ( ! V_22 )
V_48 = 'X' ;
}
return F_23 ( V_22 , V_44 , V_99 , V_48 , V_1 , V_2 ,
V_17 ) ;
}
static T_4 F_96 ( struct V_11 * V_16 )
{
return V_16 -> V_132 . V_133 ? V_16 -> V_132 . V_134 / V_16 -> V_132 . V_133 : 0 ;
}
static T_3
F_97 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
return F_96 ( V_12 ) - F_96 ( V_13 ) ;
}
static int F_98 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
return F_1 ( V_1 , V_2 , L_21 , V_17 , F_96 ( V_16 ) ) ;
}
static T_3
F_99 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
return V_12 -> V_132 . V_134 - V_13 -> V_132 . V_134 ;
}
static int F_100 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
return F_1 ( V_1 , V_2 , L_21 , V_17 , V_16 -> V_132 . V_134 ) ;
}
static T_3
F_101 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
if ( ! V_12 -> V_57 || ! V_13 -> V_57 )
return F_2 ( V_12 -> V_57 , V_13 -> V_57 ) ;
return V_12 -> V_57 -> V_103 . abort !=
V_13 -> V_57 -> V_103 . abort ;
}
static int F_102 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
static const char * V_106 = L_15 ;
if ( V_16 -> V_57 ) {
if ( V_16 -> V_57 -> V_103 . abort )
V_106 = L_22 ;
else
V_106 = L_23 ;
}
return F_1 ( V_1 , V_2 , L_18 , V_17 , V_106 ) ;
}
static T_3
F_103 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
if ( ! V_12 -> V_57 || ! V_13 -> V_57 )
return F_2 ( V_12 -> V_57 , V_13 -> V_57 ) ;
return V_12 -> V_57 -> V_103 . V_135 !=
V_13 -> V_57 -> V_103 . V_135 ;
}
static int F_104 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
static const char * V_106 = L_15 ;
if ( V_16 -> V_57 ) {
if ( V_16 -> V_57 -> V_103 . V_135 )
V_106 = L_24 ;
else
V_106 = L_23 ;
}
return F_1 ( V_1 , V_2 , L_18 , V_17 , V_106 ) ;
}
static T_3
F_105 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
return V_12 -> V_136 - V_13 -> V_136 ;
}
static inline char * F_106 ( char * V_65 , const char * V_137 )
{
strcpy ( V_65 , V_137 ) ;
return V_65 + strlen ( V_137 ) ;
}
int F_107 ( void )
{
int V_138 ;
int V_53 = 0 ;
for ( V_138 = 0 ; V_139 [ V_138 ] . V_47 ; V_138 ++ ) {
if ( ! V_139 [ V_138 ] . V_140 )
V_53 += strlen ( V_139 [ V_138 ] . V_47 ) ;
}
V_53 += 4 ;
return V_53 ;
}
static int F_108 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
T_4 V_141 = V_16 -> V_136 ;
char V_142 [ 128 ] ;
char * V_65 = V_142 ;
int V_138 ;
V_142 [ 0 ] = 0 ;
for ( V_138 = 0 ; V_139 [ V_138 ] . V_47 ; V_138 ++ )
if ( V_139 [ V_138 ] . V_143 & V_141 )
V_65 = F_106 ( V_65 , V_139 [ V_138 ] . V_47 ) ;
if ( V_141 && ! ( V_141 & ( V_144 | V_145 ) ) )
V_65 = F_106 ( V_65 , L_25 ) ;
if ( V_141 & V_146 ) {
sprintf ( V_65 , L_26 V_147 ,
( V_141 & V_146 ) >>
V_148 ) ;
V_65 += strlen ( V_65 ) ;
}
return F_1 ( V_1 , V_2 , L_18 , V_17 , V_142 ) ;
}
static T_3 F_109 ( struct V_38 * V_39 , struct V_38 * V_40 )
{
T_3 V_149 = V_39 != NULL ? F_110 ( V_39 ) : 0 ;
T_3 V_150 = V_40 != NULL ? F_110 ( V_40 ) : 0 ;
return V_149 < V_150 ? - 1 :
V_149 == V_150 ? 0 : 1 ;
}
static T_3
F_111 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
return F_109 ( V_13 -> V_33 . V_44 , V_12 -> V_33 . V_44 ) ;
}
static int F_112 ( struct V_38 * V_44 , char * V_1 ,
T_1 V_151 , unsigned int V_17 )
{
if ( V_44 )
return F_1 ( V_1 , V_151 , L_27 , V_17 , F_110 ( V_44 ) ) ;
return F_1 ( V_1 , V_151 , L_28 , V_17 , L_29 ) ;
}
static int F_113 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
return F_112 ( V_16 -> V_33 . V_44 , V_1 , V_2 , V_17 ) ;
}
void F_114 ( struct V_152 * V_3 , struct V_46 * V_46 )
{
struct V_153 * V_154 ;
if ( ! F_115 ( V_3 ) )
return;
V_154 = F_116 ( V_3 , struct V_153 , V_155 ) ;
F_117 ( V_46 , V_154 -> V_156 -> V_157 , strlen ( V_3 -> V_47 ) ) ;
}
static int F_118 ( struct V_152 * V_3 , struct V_158 * V_155 ,
struct V_46 * V_46 , int line V_77 ,
int * T_6 V_77 )
{
struct V_153 * V_154 ;
T_1 V_53 = V_3 -> V_159 ;
V_154 = F_116 ( V_3 , struct V_153 , V_155 ) ;
if ( ! V_53 )
V_53 = F_119 ( V_46 , V_154 -> V_156 -> V_157 ) ;
return F_58 ( V_155 -> V_142 , V_155 -> V_2 , L_3 , V_53 , V_53 , V_3 -> V_47 ) ;
}
static int F_120 ( struct V_152 * V_3 ,
struct V_158 * V_155 V_77 ,
struct V_46 * V_46 )
{
struct V_153 * V_154 ;
T_1 V_53 = V_3 -> V_159 ;
V_154 = F_116 ( V_3 , struct V_153 , V_155 ) ;
if ( ! V_53 )
V_53 = F_119 ( V_46 , V_154 -> V_156 -> V_157 ) ;
return V_53 ;
}
static int F_121 ( struct V_152 * V_3 , struct V_158 * V_155 ,
struct V_11 * V_16 )
{
struct V_153 * V_154 ;
T_1 V_53 = V_3 -> V_159 ;
V_154 = F_116 ( V_3 , struct V_153 , V_155 ) ;
if ( ! V_53 )
V_53 = F_119 ( V_16 -> V_46 , V_154 -> V_156 -> V_157 ) ;
return V_154 -> V_156 -> V_160 ( V_16 , V_155 -> V_142 , V_155 -> V_2 , V_53 ) ;
}
static T_3 F_122 ( struct V_152 * V_3 ,
struct V_11 * V_161 , struct V_11 * V_162 )
{
struct V_153 * V_154 ;
V_154 = F_116 ( V_3 , struct V_153 , V_155 ) ;
return V_154 -> V_156 -> V_163 ( V_161 , V_162 ) ;
}
static T_3 F_123 ( struct V_152 * V_3 ,
struct V_11 * V_161 , struct V_11 * V_162 )
{
struct V_153 * V_154 ;
T_3 (* F_124)( struct V_11 * , struct V_11 * );
V_154 = F_116 ( V_3 , struct V_153 , V_155 ) ;
F_124 = V_154 -> V_156 -> V_164 ? : V_154 -> V_156 -> V_163 ;
return F_124 ( V_161 , V_162 ) ;
}
static T_3 F_125 ( struct V_152 * V_3 ,
struct V_11 * V_161 , struct V_11 * V_162 )
{
struct V_153 * V_154 ;
T_3 (* F_126)( struct V_11 * , struct V_11 * );
V_154 = F_116 ( V_3 , struct V_153 , V_155 ) ;
F_126 = V_154 -> V_156 -> V_165 ? : V_154 -> V_156 -> V_163 ;
return F_126 ( V_161 , V_162 ) ;
}
bool F_115 ( struct V_152 * V_166 )
{
return V_166 -> V_167 == F_118 ;
}
static bool F_127 ( struct V_152 * V_161 , struct V_152 * V_162 )
{
struct V_153 * V_168 ;
struct V_153 * V_169 ;
if ( ! F_115 ( V_161 ) || ! F_115 ( V_162 ) )
return false ;
V_168 = F_116 ( V_161 , struct V_153 , V_155 ) ;
V_169 = F_116 ( V_162 , struct V_153 , V_155 ) ;
return V_168 -> V_156 == V_169 -> V_156 ;
}
static void F_128 ( struct V_152 * V_3 )
{
struct V_153 * V_154 ;
V_154 = F_116 ( V_3 , struct V_153 , V_155 ) ;
free ( V_154 ) ;
}
static struct V_153 *
F_129 ( struct V_170 * V_171 , int V_48 )
{
struct V_153 * V_154 ;
V_154 = malloc ( sizeof( * V_154 ) ) ;
if ( V_154 == NULL ) {
F_130 ( L_30 ) ;
return NULL ;
}
V_154 -> V_156 = V_171 -> V_172 ;
V_154 -> V_155 . V_47 = V_171 -> V_172 -> V_173 ;
V_154 -> V_155 . V_167 = F_118 ;
V_154 -> V_155 . V_17 = F_120 ;
V_154 -> V_155 . V_172 = F_121 ;
V_154 -> V_155 . V_174 = NULL ;
V_154 -> V_155 . V_175 = F_122 ;
V_154 -> V_155 . V_176 = F_123 ;
V_154 -> V_155 . V_177 = F_125 ;
V_154 -> V_155 . V_178 = F_127 ;
V_154 -> V_155 . free = F_128 ;
F_131 ( & V_154 -> V_155 . V_179 ) ;
F_131 ( & V_154 -> V_155 . V_180 ) ;
V_154 -> V_155 . V_181 = false ;
V_154 -> V_155 . V_53 = 0 ;
V_154 -> V_155 . V_159 = 0 ;
V_154 -> V_155 . V_48 = V_48 ;
return V_154 ;
}
static void F_132 ( struct V_152 * V_3 )
{
free ( V_3 ) ;
}
static struct V_152 * F_133 ( struct V_182 * V_183 ,
int V_48 )
{
struct V_152 * V_3 ;
V_3 = F_134 ( V_183 -> V_3 , sizeof( * V_3 ) ) ;
if ( V_3 ) {
F_131 ( & V_3 -> V_179 ) ;
F_131 ( & V_3 -> V_180 ) ;
V_3 -> free = F_132 ;
V_3 -> V_48 = V_48 ;
}
return V_3 ;
}
int F_135 ( struct V_11 * V_16 , int type , const void * V_19 )
{
struct V_152 * V_3 ;
struct V_153 * V_154 ;
int V_43 = - 1 ;
int V_10 ;
F_136 (he->hpp_list, fmt) {
if ( ! F_115 ( V_3 ) )
continue;
V_154 = F_116 ( V_3 , struct V_153 , V_155 ) ;
if ( V_154 -> V_156 -> V_184 == NULL )
continue;
V_10 = V_154 -> V_156 -> V_184 ( V_16 , type , V_19 ) ;
if ( V_10 >= 0 ) {
if ( V_43 < 0 )
V_43 = 0 ;
V_43 |= V_10 ;
}
}
return V_43 ;
}
static int F_137 ( struct V_170 * V_171 ,
struct V_185 * V_179 ,
int V_48 )
{
struct V_153 * V_154 = F_129 ( V_171 , V_48 ) ;
if ( V_154 == NULL )
return - 1 ;
F_138 ( V_179 , & V_154 -> V_155 ) ;
return 0 ;
}
static int F_139 ( struct V_170 * V_171 ,
struct V_185 * V_179 )
{
struct V_153 * V_154 = F_129 ( V_171 , 0 ) ;
if ( V_154 == NULL )
return - 1 ;
F_140 ( V_179 , & V_154 -> V_155 ) ;
return 0 ;
}
static int F_141 ( struct V_186 * V_187 )
{
if ( ! V_187 -> V_155 . V_53 ) {
int V_53 = V_187 -> V_188 ;
int V_189 = strlen ( V_187 -> V_190 -> V_47 ) ;
int V_191 = V_187 -> V_190 -> V_2 ;
if ( V_189 > V_53 )
V_53 = V_189 ;
if ( ! ( V_187 -> V_190 -> V_103 & V_192 ) ) {
V_191 = V_187 -> V_190 -> V_2 * 2 + 2 ;
}
if ( V_191 > V_53 )
V_53 = V_191 ;
V_187 -> V_155 . V_53 = V_53 ;
}
return V_187 -> V_155 . V_53 ;
}
static void F_142 ( struct V_186 * V_187 ,
struct V_11 * V_16 )
{
char * V_137 , * V_193 ;
struct V_194 * V_190 = V_187 -> V_190 ;
T_1 V_189 ;
bool V_195 = false ;
if ( V_187 -> V_90 )
return;
if ( ! V_16 -> V_95 )
V_16 -> V_95 = F_51 ( V_16 ) ;
V_189 = strlen ( V_190 -> V_47 ) ;
V_137 = V_16 -> V_95 ;
while ( V_137 ) {
V_193 = strchr ( V_137 , ' ' ) ;
if ( V_193 == NULL ) {
V_195 = true ;
V_193 = V_137 + strlen ( V_137 ) ;
}
if ( ! strncmp ( V_137 , V_190 -> V_47 , V_189 ) ) {
T_1 V_53 ;
V_137 += V_189 + 1 ;
V_53 = V_193 - V_137 ;
if ( V_53 > V_187 -> V_188 )
V_187 -> V_188 = V_53 ;
break;
}
if ( V_195 )
V_137 = NULL ;
else
V_137 = V_193 + 1 ;
}
}
static int F_143 ( struct V_152 * V_3 , struct V_158 * V_155 ,
struct V_46 * V_46 V_77 ,
int line V_77 ,
int * T_6 V_77 )
{
struct V_186 * V_187 ;
T_1 V_53 = V_3 -> V_159 ;
V_187 = F_116 ( V_3 , struct V_186 , V_155 ) ;
if ( ! V_53 )
V_53 = F_141 ( V_187 ) ;
return F_58 ( V_155 -> V_142 , V_155 -> V_2 , L_31 , V_53 , V_53 , V_187 -> V_190 -> V_47 ) ;
}
static int F_144 ( struct V_152 * V_3 ,
struct V_158 * V_155 V_77 ,
struct V_46 * V_46 V_77 )
{
struct V_186 * V_187 ;
T_1 V_53 = V_3 -> V_159 ;
V_187 = F_116 ( V_3 , struct V_186 , V_155 ) ;
if ( ! V_53 )
V_53 = F_141 ( V_187 ) ;
return V_53 ;
}
bool F_145 ( struct V_152 * V_3 , struct V_46 * V_46 )
{
struct V_186 * V_187 ;
V_187 = F_116 ( V_3 , struct V_186 , V_155 ) ;
return F_52 ( V_46 ) == V_187 -> V_84 ;
}
static int F_146 ( struct V_152 * V_3 , struct V_158 * V_155 ,
struct V_11 * V_16 )
{
struct V_186 * V_187 ;
T_1 V_53 = V_3 -> V_159 ;
char * V_137 , * V_193 ;
struct V_194 * V_190 ;
T_1 V_189 ;
bool V_195 = false ;
int V_43 ;
V_187 = F_116 ( V_3 , struct V_186 , V_155 ) ;
if ( ! V_53 )
V_53 = F_141 ( V_187 ) ;
if ( V_187 -> V_90 )
goto V_196;
if ( ! V_16 -> V_95 )
V_16 -> V_95 = F_51 ( V_16 ) ;
V_190 = V_187 -> V_190 ;
V_189 = strlen ( V_190 -> V_47 ) ;
V_137 = V_16 -> V_95 ;
while ( V_137 ) {
V_193 = strchr ( V_137 , ' ' ) ;
if ( V_193 == NULL ) {
V_195 = true ;
V_193 = V_137 + strlen ( V_137 ) ;
}
if ( ! strncmp ( V_137 , V_190 -> V_47 , V_189 ) ) {
V_137 += V_189 + 1 ;
V_137 = F_147 ( V_137 , V_193 - V_137 ) ;
if ( V_137 == NULL )
return F_58 ( V_155 -> V_142 , V_155 -> V_2 ,
L_31 , V_53 , V_53 , L_32 ) ;
break;
}
if ( V_195 )
V_137 = NULL ;
else
V_137 = V_193 + 1 ;
}
if ( V_137 == NULL ) {
struct V_81 V_82 ;
V_196:
F_53 ( & V_82 ) ;
F_148 ( & V_82 , V_16 -> V_88 , V_187 -> V_190 ) ;
V_137 = V_82 . V_92 ;
}
V_43 = F_58 ( V_155 -> V_142 , V_155 -> V_2 , L_31 , V_53 , V_53 , V_137 ) ;
free ( V_137 ) ;
return V_43 ;
}
static T_3 F_149 ( struct V_152 * V_3 ,
struct V_11 * V_161 , struct V_11 * V_162 )
{
struct V_186 * V_187 ;
struct V_194 * V_190 ;
unsigned V_197 , V_2 ;
V_187 = F_116 ( V_3 , struct V_186 , V_155 ) ;
if ( V_162 == NULL ) {
F_142 ( V_187 , V_161 ) ;
return 0 ;
}
V_190 = V_187 -> V_190 ;
if ( V_190 -> V_103 & V_198 ) {
unsigned long long V_199 ;
F_150 ( V_190 , V_161 -> V_88 , & V_199 ) ;
V_197 = V_199 & 0xffff ;
V_2 = ( V_199 >> 16 ) & 0xffff ;
if ( V_2 > V_187 -> V_188 )
V_187 -> V_188 = V_2 ;
} else {
V_197 = V_190 -> V_197 ;
V_2 = V_190 -> V_2 ;
}
return memcmp ( V_161 -> V_88 + V_197 , V_162 -> V_88 + V_197 , V_2 ) ;
}
bool F_151 ( struct V_152 * V_3 )
{
return V_3 -> V_175 == F_149 ;
}
static bool F_152 ( struct V_152 * V_161 , struct V_152 * V_162 )
{
struct V_186 * V_200 ;
struct V_186 * V_201 ;
if ( ! F_151 ( V_161 ) || ! F_151 ( V_162 ) )
return false ;
V_200 = F_116 ( V_161 , struct V_186 , V_155 ) ;
V_201 = F_116 ( V_162 , struct V_186 , V_155 ) ;
return V_200 -> V_190 == V_201 -> V_190 ;
}
static void F_153 ( struct V_152 * V_3 )
{
struct V_186 * V_187 ;
V_187 = F_116 ( V_3 , struct V_186 , V_155 ) ;
free ( V_187 ) ;
}
static struct V_186 *
F_154 ( struct V_83 * V_84 , struct V_194 * V_190 ,
int V_48 )
{
struct V_186 * V_187 ;
V_187 = malloc ( sizeof( * V_187 ) ) ;
if ( V_187 == NULL ) {
F_155 ( L_30 ) ;
return NULL ;
}
V_187 -> V_84 = V_84 ;
V_187 -> V_190 = V_190 ;
V_187 -> V_188 = 0 ;
V_187 -> V_155 . V_47 = V_190 -> V_47 ;
V_187 -> V_155 . V_167 = F_143 ;
V_187 -> V_155 . V_17 = F_144 ;
V_187 -> V_155 . V_172 = F_146 ;
V_187 -> V_155 . V_174 = NULL ;
V_187 -> V_155 . V_175 = F_149 ;
V_187 -> V_155 . V_176 = F_149 ;
V_187 -> V_155 . V_177 = F_149 ;
V_187 -> V_155 . V_178 = F_152 ;
V_187 -> V_155 . free = F_153 ;
F_131 ( & V_187 -> V_155 . V_179 ) ;
F_131 ( & V_187 -> V_155 . V_180 ) ;
V_187 -> V_155 . V_181 = false ;
V_187 -> V_155 . V_53 = 0 ;
V_187 -> V_155 . V_159 = 0 ;
V_187 -> V_155 . V_48 = V_48 ;
return V_187 ;
}
struct V_152 * F_156 ( struct V_152 * V_3 )
{
struct V_152 * V_202 = NULL ;
if ( F_115 ( V_3 ) ) {
struct V_153 * V_154 , * V_203 ;
V_154 = F_116 ( V_3 , struct V_153 , V_155 ) ;
V_203 = F_134 ( V_154 , sizeof( * V_154 ) ) ;
if ( V_203 )
V_202 = & V_203 -> V_155 ;
} else if ( F_151 ( V_3 ) ) {
struct V_186 * V_187 , * V_204 ;
V_187 = F_116 ( V_3 , struct V_186 , V_155 ) ;
V_204 = F_134 ( V_187 , sizeof( * V_187 ) ) ;
if ( V_204 )
V_202 = & V_204 -> V_155 ;
} else {
V_202 = F_134 ( V_3 , sizeof( * V_3 ) ) ;
}
F_131 ( & V_202 -> V_179 ) ;
F_131 ( & V_202 -> V_180 ) ;
return V_202 ;
}
static int F_157 ( char * V_137 , char * * V_205 , char * * V_190 , char * * V_206 )
{
char * V_207 , * V_208 , * V_209 ;
V_207 = V_137 ;
V_208 = strchr ( V_137 , '.' ) ;
if ( V_208 ) {
* V_208 ++ = '\0' ;
} else {
V_207 = NULL ;
V_208 = V_137 ;
}
V_209 = strchr ( V_208 , '/' ) ;
if ( V_209 )
* V_209 ++ = '\0' ;
* V_205 = V_207 ;
* V_190 = V_208 ;
* V_206 = V_209 ;
return 0 ;
}
static struct V_83 * F_158 ( struct V_210 * V_211 , char * V_207 )
{
struct V_83 * V_84 = NULL ;
struct V_83 * V_193 ;
bool V_212 ;
if ( V_207 [ 0 ] == '%' ) {
int V_213 = strtol ( V_207 + 1 , NULL , 0 ) ;
if ( V_213 > V_211 -> V_214 )
return NULL ;
V_84 = F_159 ( V_211 ) ;
while ( -- V_213 > 0 )
V_84 = F_160 ( V_84 ) ;
return V_84 ;
}
V_212 = ! ! strchr ( V_207 , ':' ) ;
F_161 (evlist, pos) {
if ( V_212 && ! strcmp ( V_193 -> V_47 , V_207 ) )
return V_193 ;
if ( ! V_212 && strstr ( V_193 -> V_47 , V_207 ) ) {
if ( V_84 ) {
F_155 ( L_33 ,
V_207 , V_84 -> V_47 , V_193 -> V_47 ) ;
return NULL ;
}
V_84 = V_193 ;
}
}
return V_84 ;
}
static int F_162 ( struct V_83 * V_84 ,
struct V_194 * V_190 ,
bool V_90 , int V_48 )
{
struct V_186 * V_187 ;
V_187 = F_154 ( V_84 , V_190 , V_48 ) ;
if ( V_187 == NULL )
return - V_215 ;
V_187 -> V_90 = V_90 ;
F_163 ( & V_187 -> V_155 ) ;
return 0 ;
}
static int F_164 ( struct V_83 * V_84 , bool V_90 , int V_48 )
{
int V_43 ;
struct V_194 * V_190 ;
V_190 = V_84 -> V_91 -> V_166 . V_216 ;
while ( V_190 ) {
V_43 = F_162 ( V_84 , V_190 , V_90 , V_48 ) ;
if ( V_43 < 0 )
return V_43 ;
V_190 = V_190 -> V_217 ;
}
return 0 ;
}
static int F_165 ( struct V_210 * V_211 , bool V_90 ,
int V_48 )
{
int V_43 ;
struct V_83 * V_84 ;
F_161 (evlist, evsel) {
if ( V_84 -> V_93 . type != V_94 )
continue;
V_43 = F_164 ( V_84 , V_90 , V_48 ) ;
if ( V_43 < 0 )
return V_43 ;
}
return 0 ;
}
static int F_166 ( struct V_210 * V_211 ,
char * V_208 , bool V_90 , int V_48 )
{
int V_43 = - V_218 ;
struct V_83 * V_84 ;
struct V_194 * V_190 ;
F_161 (evlist, evsel) {
if ( V_84 -> V_93 . type != V_94 )
continue;
V_190 = F_167 ( V_84 -> V_91 , V_208 ) ;
if ( V_190 == NULL )
continue;
V_43 = F_162 ( V_84 , V_190 , V_90 , V_48 ) ;
if ( V_43 < 0 )
break;
}
return V_43 ;
}
static int F_168 ( struct V_210 * V_211 , const char * V_219 ,
int V_48 )
{
char * V_137 , * V_207 , * V_208 , * V_209 ;
struct V_83 * V_84 ;
struct V_194 * V_190 ;
bool V_90 = V_6 . V_90 ;
int V_43 = 0 ;
if ( V_211 == NULL )
return - V_220 ;
V_137 = F_169 ( V_219 ) ;
if ( V_137 == NULL )
return - V_215 ;
if ( F_157 ( V_137 , & V_207 , & V_208 , & V_209 ) < 0 ) {
V_43 = - V_221 ;
goto V_106;
}
if ( V_209 ) {
if ( strcmp ( V_209 , L_34 ) ) {
F_155 ( L_35 , V_209 ) ;
V_43 = - V_221 ;
goto V_106;
}
V_90 = true ;
}
if ( ! strcmp ( V_208 , L_36 ) ) {
V_43 = F_165 ( V_211 , V_90 , V_48 ) ;
goto V_106;
}
if ( V_207 == NULL ) {
V_43 = F_166 ( V_211 , V_208 , V_90 , V_48 ) ;
goto V_106;
}
V_84 = F_158 ( V_211 , V_207 ) ;
if ( V_84 == NULL ) {
F_155 ( L_37 , V_207 ) ;
V_43 = - V_220 ;
goto V_106;
}
if ( V_84 -> V_93 . type != V_94 ) {
F_155 ( L_38 , V_207 ) ;
V_43 = - V_221 ;
goto V_106;
}
if ( ! strcmp ( V_208 , L_39 ) ) {
V_43 = F_164 ( V_84 , V_90 , V_48 ) ;
} else {
V_190 = F_167 ( V_84 -> V_91 , V_208 ) ;
if ( V_190 == NULL ) {
F_155 ( L_40 ,
V_207 , V_208 ) ;
return - V_220 ;
}
V_43 = F_162 ( V_84 , V_190 , V_90 , V_48 ) ;
}
V_106:
free ( V_137 ) ;
return V_43 ;
}
static int F_170 ( struct V_170 * V_171 ,
struct V_185 * V_179 ,
int V_48 )
{
if ( V_171 -> V_222 )
return 0 ;
if ( F_137 ( V_171 , V_179 , V_48 ) < 0 )
return - 1 ;
if ( V_171 -> V_172 -> V_164 )
V_179 -> V_223 = 1 ;
V_171 -> V_222 = 1 ;
return 0 ;
}
static int F_171 ( struct V_182 * V_183 ,
struct V_185 * V_179 ,
int V_48 )
{
struct V_152 * V_3 ;
if ( V_183 -> V_222 )
return 0 ;
V_3 = F_133 ( V_183 , V_48 ) ;
if ( ! V_3 )
return - 1 ;
V_183 -> V_222 = 1 ;
F_138 ( V_179 , V_3 ) ;
return 0 ;
}
static int F_172 ( struct V_185 * V_179 ,
struct V_170 * V_171 )
{
if ( V_171 -> V_222 )
return 0 ;
if ( F_139 ( V_171 , V_179 ) < 0 )
return - 1 ;
V_171 -> V_222 = 1 ;
return 0 ;
}
static int F_173 ( struct V_185 * V_179 ,
struct V_182 * V_183 )
{
struct V_152 * V_3 ;
if ( V_183 -> V_222 )
return 0 ;
V_3 = F_133 ( V_183 , 0 ) ;
if ( ! V_3 )
return - 1 ;
V_183 -> V_222 = 1 ;
F_140 ( V_179 , V_3 ) ;
return 0 ;
}
int F_174 ( unsigned V_224 )
{
F_175 ( V_224 >= V_225 ) ;
return F_173 ( & V_185 , & V_226 [ V_224 ] ) ;
}
int F_176 ( struct V_185 * V_179 , const char * V_219 ,
struct V_210 * V_211 ,
int V_48 )
{
unsigned int V_138 ;
for ( V_138 = 0 ; V_138 < F_177 ( V_227 ) ; V_138 ++ ) {
struct V_170 * V_171 = & V_227 [ V_138 ] ;
if ( strncasecmp ( V_219 , V_171 -> V_47 , strlen ( V_219 ) ) )
continue;
if ( V_171 -> V_172 == & V_228 ) {
int V_43 = regcomp ( & V_229 , V_230 , V_231 ) ;
if ( V_43 ) {
char V_232 [ V_233 ] ;
regerror ( V_43 , & V_229 , V_232 , sizeof( V_232 ) ) ;
F_130 ( L_41 , V_230 , V_232 ) ;
return - V_221 ;
}
V_179 -> V_68 = 1 ;
} else if ( V_171 -> V_172 == & V_234 ) {
V_179 -> V_44 = 1 ;
if ( V_235 == V_236 )
V_171 -> V_172 -> V_164 = F_22 ;
} else if ( V_171 -> V_172 == & V_237 ) {
V_179 -> V_25 = 1 ;
} else if ( V_171 -> V_172 == & V_238 ) {
V_179 -> V_78 = 1 ;
} else if ( V_171 -> V_172 == & V_239 ) {
V_179 -> V_14 = 1 ;
} else if ( V_171 -> V_172 == & V_240 ) {
V_179 -> V_18 = 1 ;
}
return F_170 ( V_171 , V_179 , V_48 ) ;
}
for ( V_138 = 0 ; V_138 < F_177 ( V_226 ) ; V_138 ++ ) {
struct V_182 * V_183 = & V_226 [ V_138 ] ;
if ( strncasecmp ( V_219 , V_183 -> V_47 , strlen ( V_219 ) ) )
continue;
return F_171 ( V_183 , V_179 , V_48 ) ;
}
for ( V_138 = 0 ; V_138 < F_177 ( V_241 ) ; V_138 ++ ) {
struct V_170 * V_171 = & V_241 [ V_138 ] ;
if ( strncasecmp ( V_219 , V_171 -> V_47 , strlen ( V_219 ) ) )
continue;
if ( V_235 != V_242 )
return - V_221 ;
if ( V_171 -> V_172 == & V_243 || V_171 -> V_172 == & V_244 )
V_179 -> V_44 = 1 ;
F_170 ( V_171 , V_179 , V_48 ) ;
return 0 ;
}
for ( V_138 = 0 ; V_138 < F_177 ( V_245 ) ; V_138 ++ ) {
struct V_170 * V_171 = & V_245 [ V_138 ] ;
if ( strncasecmp ( V_219 , V_171 -> V_47 , strlen ( V_219 ) ) )
continue;
if ( V_235 != V_246 )
return - V_221 ;
if ( V_171 -> V_172 == & V_247 && V_248 == 0 )
return - V_221 ;
if ( V_171 -> V_172 == & V_249 )
V_179 -> V_44 = 1 ;
F_170 ( V_171 , V_179 , V_48 ) ;
return 0 ;
}
if ( ! F_168 ( V_211 , V_219 , V_48 ) )
return 0 ;
return - V_218 ;
}
static int F_178 ( struct V_185 * V_179 , char * V_137 ,
struct V_210 * V_211 )
{
char * V_250 , * V_219 ;
int V_43 = 0 ;
int V_48 = 0 ;
int V_251 = 1 ;
bool V_252 = false ;
do {
V_219 = V_137 ;
V_250 = strpbrk ( V_137 , L_42 ) ;
if ( V_250 ) {
if ( V_252 )
V_251 = V_48 ;
else
V_251 = V_48 + 1 ;
if ( * V_250 == '{' )
V_252 = true ;
else if ( * V_250 == '}' )
V_252 = false ;
* V_250 = '\0' ;
V_137 = V_250 + 1 ;
}
if ( * V_219 ) {
V_43 = F_176 ( V_179 , V_219 , V_211 , V_48 ) ;
if ( V_43 == - V_221 ) {
if ( ! V_248 && ! strncasecmp ( V_219 , L_43 , strlen ( V_219 ) ) )
error ( L_44 ) ;
else
error ( L_45 , V_219 ) ;
break;
} else if ( V_43 == - V_218 ) {
error ( L_46 , V_219 ) ;
break;
}
}
V_48 = V_251 ;
} while ( V_250 );
return V_43 ;
}
static const char * F_179 ( struct V_210 * V_211 )
{
const char * V_253 [] = {
V_254 ,
V_255 ,
V_256 ,
V_257 ,
V_258 ,
V_259 ,
} ;
bool V_260 = true ;
struct V_83 * V_84 ;
F_175 ( V_235 >= F_177 ( V_253 ) ) ;
if ( V_211 == NULL )
goto V_261;
F_161 (evlist, evsel) {
if ( V_84 -> V_93 . type != V_94 ) {
V_260 = false ;
break;
}
}
if ( V_260 ) {
V_235 = V_262 ;
if ( V_6 . V_90 )
return L_36 ;
}
V_261:
return V_253 [ V_235 ] ;
}
static int F_180 ( struct V_210 * V_211 )
{
char * V_263 ;
if ( ! V_264 || F_181 ( V_264 ) )
return 0 ;
if ( V_264 [ 1 ] == '\0' ) {
error ( L_47 ) ;
return - V_221 ;
}
if ( F_182 ( & V_263 , L_48 ,
F_179 ( V_211 ) , V_264 + 1 ) < 0 ) {
error ( L_49 ) ;
return - V_215 ;
}
V_264 = V_263 ;
return 0 ;
}
static char * F_183 ( const char * V_265 , char * V_137 )
{
char * V_4 ;
if ( ! V_137 || strstr ( V_137 , V_265 ) )
return V_137 ;
if ( F_182 ( & V_4 , L_48 , V_265 , V_137 ) < 0 )
return NULL ;
free ( V_137 ) ;
return V_4 ;
}
static char * F_184 ( char * V_266 )
{
if ( V_235 == V_236 )
return V_266 ;
V_266 = F_183 ( L_50 , V_266 ) ;
if ( V_6 . V_267 )
V_266 = F_183 ( L_51 , V_266 ) ;
return V_266 ;
}
static int F_185 ( struct V_210 * V_211 )
{
char * V_137 ;
const char * V_268 ;
int V_43 = 0 ;
V_43 = F_180 ( V_211 ) ;
if ( V_43 )
return V_43 ;
V_268 = V_264 ;
if ( V_268 == NULL ) {
if ( F_181 ( V_269 ) ) {
return 0 ;
}
V_268 = F_179 ( V_211 ) ;
}
V_137 = F_169 ( V_268 ) ;
if ( V_137 == NULL ) {
error ( L_52 ) ;
return - V_215 ;
}
if ( ! F_181 ( V_269 ) ) {
V_137 = F_184 ( V_137 ) ;
if ( V_137 == NULL ) {
error ( L_53 ) ;
return - V_215 ;
}
}
V_43 = F_178 ( & V_185 , V_137 , V_211 ) ;
free ( V_137 ) ;
return V_43 ;
}
void F_186 ( int V_270 , bool V_181 )
{
struct V_152 * V_3 ;
struct V_153 * V_154 ;
F_136 (&perf_hpp_list, fmt) {
if ( ! F_115 ( V_3 ) )
continue;
V_154 = F_116 ( V_3 , struct V_153 , V_155 ) ;
if ( V_154 -> V_156 -> V_157 == V_270 ) {
V_3 -> V_181 = V_181 ;
break;
}
}
}
static bool F_187 ( struct V_271 * V_179 , const char * V_272 , T_7 * V_273 )
{
if ( V_179 && F_188 ( V_179 ) == 1 ) {
if ( V_273 != NULL )
fprintf ( V_273 , L_54 , V_272 ,
F_189 ( V_179 , 0 ) -> V_274 ) ;
return true ;
}
return false ;
}
static bool F_190 ( int V_270 , T_7 * V_275 )
{
switch ( V_270 ) {
case V_276 :
return F_187 ( V_6 . V_277 , L_55 , V_275 ) ;
case V_278 :
return F_187 ( V_6 . V_279 , L_56 , V_275 ) ;
case V_280 :
return F_187 ( V_6 . V_281 , L_57 , V_275 ) ;
default:
break;
}
if ( V_235 != V_242 )
return false ;
switch ( V_270 ) {
case V_282 :
return F_187 ( V_6 . V_283 , L_58 , V_275 ) ;
case V_284 :
return F_187 ( V_6 . V_285 , L_59 , V_275 ) ;
case V_286 :
return F_187 ( V_6 . V_287 , L_60 , V_275 ) ;
case V_288 :
return F_187 ( V_6 . V_289 , L_61 , V_275 ) ;
default:
break;
}
return false ;
}
void F_191 ( T_7 * V_275 )
{
struct V_152 * V_3 ;
struct V_153 * V_154 ;
F_136 (&perf_hpp_list, fmt) {
if ( ! F_115 ( V_3 ) )
continue;
V_154 = F_116 ( V_3 , struct V_153 , V_155 ) ;
V_3 -> V_181 = F_190 ( V_154 -> V_156 -> V_157 , V_275 ) ;
}
F_136 (&perf_hpp_list, fmt) {
if ( ! F_115 ( V_3 ) )
continue;
if ( ! V_3 -> V_181 )
return;
}
F_136 (&perf_hpp_list, fmt) {
if ( ! F_115 ( V_3 ) )
continue;
V_3 -> V_181 = false ;
}
}
int F_192 ( struct V_185 * V_179 , char * V_219 )
{
unsigned int V_138 ;
for ( V_138 = 0 ; V_138 < F_177 ( V_227 ) ; V_138 ++ ) {
struct V_170 * V_171 = & V_227 [ V_138 ] ;
if ( strncasecmp ( V_219 , V_171 -> V_47 , strlen ( V_219 ) ) )
continue;
return F_172 ( V_179 , V_171 ) ;
}
for ( V_138 = 0 ; V_138 < F_177 ( V_226 ) ; V_138 ++ ) {
struct V_182 * V_183 = & V_226 [ V_138 ] ;
if ( strncasecmp ( V_219 , V_183 -> V_47 , strlen ( V_219 ) ) )
continue;
return F_173 ( V_179 , V_183 ) ;
}
for ( V_138 = 0 ; V_138 < F_177 ( V_241 ) ; V_138 ++ ) {
struct V_170 * V_171 = & V_241 [ V_138 ] ;
if ( strncasecmp ( V_219 , V_171 -> V_47 , strlen ( V_219 ) ) )
continue;
return F_172 ( V_179 , V_171 ) ;
}
for ( V_138 = 0 ; V_138 < F_177 ( V_245 ) ; V_138 ++ ) {
struct V_170 * V_171 = & V_245 [ V_138 ] ;
if ( strncasecmp ( V_219 , V_171 -> V_47 , strlen ( V_219 ) ) )
continue;
return F_172 ( V_179 , V_171 ) ;
}
return - V_218 ;
}
static int F_193 ( struct V_185 * V_179 , char * V_137 )
{
char * V_250 , * V_219 ;
int V_43 = 0 ;
for ( V_219 = strtok_r ( V_137 , L_62 , & V_250 ) ;
V_219 ; V_219 = strtok_r ( NULL , L_62 , & V_250 ) ) {
V_43 = F_192 ( V_179 , V_219 ) ;
if ( V_43 == - V_221 ) {
error ( L_63 , V_219 ) ;
break;
} else if ( V_43 == - V_218 ) {
error ( L_64 , V_219 ) ;
break;
}
}
return V_43 ;
}
void F_194 ( void )
{
unsigned int V_138 ;
for ( V_138 = 0 ; V_138 < F_177 ( V_227 ) ; V_138 ++ )
V_227 [ V_138 ] . V_222 = 0 ;
for ( V_138 = 0 ; V_138 < F_177 ( V_226 ) ; V_138 ++ )
V_226 [ V_138 ] . V_222 = 0 ;
for ( V_138 = 0 ; V_138 < F_177 ( V_241 ) ; V_138 ++ )
V_241 [ V_138 ] . V_222 = 0 ;
for ( V_138 = 0 ; V_138 < F_177 ( V_245 ) ; V_138 ++ )
V_245 [ V_138 ] . V_222 = 0 ;
}
bool F_181 ( const char * V_290 )
{
return V_290 && ( * V_290 != '+' ) ;
}
static int F_195 ( void )
{
char * V_137 , * V_291 ;
int V_43 = - V_221 ;
if ( V_269 == NULL )
return 0 ;
V_291 = V_137 = F_169 ( V_269 ) ;
if ( V_137 == NULL ) {
error ( L_65 ) ;
return - V_215 ;
}
if ( ! F_181 ( V_269 ) )
V_291 ++ ;
if ( ! strlen ( V_291 ) ) {
error ( L_66 ) ;
goto V_106;
}
V_43 = F_193 ( & V_185 , V_291 ) ;
V_106:
free ( V_137 ) ;
return V_43 ;
}
int F_196 ( struct V_210 * V_211 )
{
int V_232 ;
V_232 = F_185 ( V_211 ) ;
if ( V_232 < 0 )
return V_232 ;
if ( V_230 != V_292 ) {
V_232 = F_176 ( & V_185 , L_67 , V_211 , - 1 ) ;
if ( V_232 < 0 )
return V_232 ;
}
F_194 () ;
if ( V_235 != V_236 )
F_197 () ;
V_232 = F_195 () ;
if ( V_232 < 0 )
return V_232 ;
F_198 ( & V_185 ) ;
F_199 ( & V_185 ) ;
if ( F_200 ( & V_185 , V_211 ) < 0 )
return - 1 ;
return 0 ;
}
void F_201 ( void )
{
V_185 . V_223 = 0 ;
V_185 . V_68 = 0 ;
V_185 . V_44 = 0 ;
V_185 . V_25 = 0 ;
V_269 = NULL ;
V_264 = NULL ;
F_194 () ;
F_202 ( & V_185 ) ;
}
