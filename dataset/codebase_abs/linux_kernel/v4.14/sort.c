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
T_5 V_9 = 0 , V_10 = 0 ;
if ( V_12 -> V_108 )
V_9 = V_12 -> V_108 -> V_109 . V_135 ;
if ( V_13 -> V_108 )
V_10 = V_13 -> V_108 -> V_109 . V_135 ;
return ( T_3 ) ( V_10 - V_9 ) ;
}
static int F_102 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
T_5 V_99 = 0 ;
T_1 V_43 = 0 ;
T_1 V_53 = V_50 / 4 ;
V_99 = V_16 -> V_108 -> V_109 . V_135 ;
V_43 += F_1 ( V_1 + V_43 , V_2 - V_43 , L_6 , V_16 -> V_48 ) ;
V_43 += F_1 ( V_1 + V_43 , V_2 - V_43 , L_10 , V_53 , V_99 ) ;
V_43 += F_1 ( V_1 + V_43 , V_2 - V_43 , L_18 , V_17 - V_43 , L_2 ) ;
if ( V_43 > V_17 )
V_1 [ V_17 ] = '\0' ;
return V_17 ;
}
static T_3
F_103 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
if ( ! V_12 -> V_57 || ! V_13 -> V_57 )
return F_2 ( V_12 -> V_57 , V_13 -> V_57 ) ;
return V_12 -> V_57 -> V_103 . abort !=
V_13 -> V_57 -> V_103 . abort ;
}
static int F_104 ( struct V_11 * V_16 , char * V_1 ,
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
F_105 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
if ( ! V_12 -> V_57 || ! V_13 -> V_57 )
return F_2 ( V_12 -> V_57 , V_13 -> V_57 ) ;
return V_12 -> V_57 -> V_103 . V_136 !=
V_13 -> V_57 -> V_103 . V_136 ;
}
static int F_106 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
static const char * V_106 = L_15 ;
if ( V_16 -> V_57 ) {
if ( V_16 -> V_57 -> V_103 . V_136 )
V_106 = L_24 ;
else
V_106 = L_23 ;
}
return F_1 ( V_1 , V_2 , L_18 , V_17 , V_106 ) ;
}
static T_3
F_107 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
return V_12 -> V_137 - V_13 -> V_137 ;
}
static inline char * F_108 ( char * V_65 , const char * V_138 )
{
strcpy ( V_65 , V_138 ) ;
return V_65 + strlen ( V_138 ) ;
}
int F_109 ( void )
{
int V_139 ;
int V_53 = 0 ;
for ( V_139 = 0 ; V_140 [ V_139 ] . V_47 ; V_139 ++ ) {
if ( ! V_140 [ V_139 ] . V_141 )
V_53 += strlen ( V_140 [ V_139 ] . V_47 ) ;
}
V_53 += 4 ;
return V_53 ;
}
static int F_110 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
T_4 V_142 = V_16 -> V_137 ;
char V_143 [ 128 ] ;
char * V_65 = V_143 ;
int V_139 ;
V_143 [ 0 ] = 0 ;
for ( V_139 = 0 ; V_140 [ V_139 ] . V_47 ; V_139 ++ )
if ( V_140 [ V_139 ] . V_144 & V_142 )
V_65 = F_108 ( V_65 , V_140 [ V_139 ] . V_47 ) ;
if ( V_142 && ! ( V_142 & ( V_145 | V_146 ) ) )
V_65 = F_108 ( V_65 , L_25 ) ;
if ( V_142 & V_147 ) {
sprintf ( V_65 , L_26 V_148 ,
( V_142 & V_147 ) >>
V_149 ) ;
V_65 += strlen ( V_65 ) ;
}
return F_1 ( V_1 , V_2 , L_18 , V_17 , V_143 ) ;
}
static T_3 F_111 ( struct V_38 * V_39 , struct V_38 * V_40 )
{
T_3 V_150 = V_39 != NULL ? F_112 ( V_39 ) : 0 ;
T_3 V_151 = V_40 != NULL ? F_112 ( V_40 ) : 0 ;
return V_150 < V_151 ? - 1 :
V_150 == V_151 ? 0 : 1 ;
}
static T_3
F_113 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
return F_111 ( V_13 -> V_33 . V_44 , V_12 -> V_33 . V_44 ) ;
}
static int F_114 ( struct V_38 * V_44 , char * V_1 ,
T_1 V_152 , unsigned int V_17 )
{
if ( V_44 )
return F_1 ( V_1 , V_152 , L_27 , V_17 , F_112 ( V_44 ) ) ;
return F_1 ( V_1 , V_152 , L_28 , V_17 , L_29 ) ;
}
static int F_115 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
return F_114 ( V_16 -> V_33 . V_44 , V_1 , V_2 , V_17 ) ;
}
void F_116 ( struct V_153 * V_3 , struct V_46 * V_46 )
{
struct V_154 * V_155 ;
if ( ! F_117 ( V_3 ) )
return;
V_155 = F_118 ( V_3 , struct V_154 , V_156 ) ;
F_119 ( V_46 , V_155 -> V_157 -> V_158 , strlen ( V_3 -> V_47 ) ) ;
}
static int F_120 ( struct V_153 * V_3 , struct V_159 * V_156 ,
struct V_46 * V_46 , int line V_77 ,
int * T_6 V_77 )
{
struct V_154 * V_155 ;
T_1 V_53 = V_3 -> V_160 ;
V_155 = F_118 ( V_3 , struct V_154 , V_156 ) ;
if ( ! V_53 )
V_53 = F_121 ( V_46 , V_155 -> V_157 -> V_158 ) ;
return F_58 ( V_156 -> V_143 , V_156 -> V_2 , L_3 , V_53 , V_53 , V_3 -> V_47 ) ;
}
static int F_122 ( struct V_153 * V_3 ,
struct V_159 * V_156 V_77 ,
struct V_46 * V_46 )
{
struct V_154 * V_155 ;
T_1 V_53 = V_3 -> V_160 ;
V_155 = F_118 ( V_3 , struct V_154 , V_156 ) ;
if ( ! V_53 )
V_53 = F_121 ( V_46 , V_155 -> V_157 -> V_158 ) ;
return V_53 ;
}
static int F_123 ( struct V_153 * V_3 , struct V_159 * V_156 ,
struct V_11 * V_16 )
{
struct V_154 * V_155 ;
T_1 V_53 = V_3 -> V_160 ;
V_155 = F_118 ( V_3 , struct V_154 , V_156 ) ;
if ( ! V_53 )
V_53 = F_121 ( V_16 -> V_46 , V_155 -> V_157 -> V_158 ) ;
return V_155 -> V_157 -> V_161 ( V_16 , V_156 -> V_143 , V_156 -> V_2 , V_53 ) ;
}
static T_3 F_124 ( struct V_153 * V_3 ,
struct V_11 * V_162 , struct V_11 * V_163 )
{
struct V_154 * V_155 ;
V_155 = F_118 ( V_3 , struct V_154 , V_156 ) ;
return V_155 -> V_157 -> V_164 ( V_162 , V_163 ) ;
}
static T_3 F_125 ( struct V_153 * V_3 ,
struct V_11 * V_162 , struct V_11 * V_163 )
{
struct V_154 * V_155 ;
T_3 (* F_126)( struct V_11 * , struct V_11 * );
V_155 = F_118 ( V_3 , struct V_154 , V_156 ) ;
F_126 = V_155 -> V_157 -> V_165 ? : V_155 -> V_157 -> V_164 ;
return F_126 ( V_162 , V_163 ) ;
}
static T_3 F_127 ( struct V_153 * V_3 ,
struct V_11 * V_162 , struct V_11 * V_163 )
{
struct V_154 * V_155 ;
T_3 (* F_128)( struct V_11 * , struct V_11 * );
V_155 = F_118 ( V_3 , struct V_154 , V_156 ) ;
F_128 = V_155 -> V_157 -> V_166 ? : V_155 -> V_157 -> V_164 ;
return F_128 ( V_162 , V_163 ) ;
}
bool F_117 ( struct V_153 * V_167 )
{
return V_167 -> V_168 == F_120 ;
}
static bool F_129 ( struct V_153 * V_162 , struct V_153 * V_163 )
{
struct V_154 * V_169 ;
struct V_154 * V_170 ;
if ( ! F_117 ( V_162 ) || ! F_117 ( V_163 ) )
return false ;
V_169 = F_118 ( V_162 , struct V_154 , V_156 ) ;
V_170 = F_118 ( V_163 , struct V_154 , V_156 ) ;
return V_169 -> V_157 == V_170 -> V_157 ;
}
static void F_130 ( struct V_153 * V_3 )
{
struct V_154 * V_155 ;
V_155 = F_118 ( V_3 , struct V_154 , V_156 ) ;
free ( V_155 ) ;
}
static struct V_154 *
F_131 ( struct V_171 * V_172 , int V_48 )
{
struct V_154 * V_155 ;
V_155 = malloc ( sizeof( * V_155 ) ) ;
if ( V_155 == NULL ) {
F_132 ( L_30 ) ;
return NULL ;
}
V_155 -> V_157 = V_172 -> V_173 ;
V_155 -> V_156 . V_47 = V_172 -> V_173 -> V_174 ;
V_155 -> V_156 . V_168 = F_120 ;
V_155 -> V_156 . V_17 = F_122 ;
V_155 -> V_156 . V_173 = F_123 ;
V_155 -> V_156 . V_175 = NULL ;
V_155 -> V_156 . V_176 = F_124 ;
V_155 -> V_156 . V_177 = F_125 ;
V_155 -> V_156 . V_178 = F_127 ;
V_155 -> V_156 . V_179 = F_129 ;
V_155 -> V_156 . free = F_130 ;
F_133 ( & V_155 -> V_156 . V_180 ) ;
F_133 ( & V_155 -> V_156 . V_181 ) ;
V_155 -> V_156 . V_182 = false ;
V_155 -> V_156 . V_53 = 0 ;
V_155 -> V_156 . V_160 = 0 ;
V_155 -> V_156 . V_48 = V_48 ;
return V_155 ;
}
static void F_134 ( struct V_153 * V_3 )
{
free ( V_3 ) ;
}
static struct V_153 * F_135 ( struct V_183 * V_184 ,
int V_48 )
{
struct V_153 * V_3 ;
V_3 = F_136 ( V_184 -> V_3 , sizeof( * V_3 ) ) ;
if ( V_3 ) {
F_133 ( & V_3 -> V_180 ) ;
F_133 ( & V_3 -> V_181 ) ;
V_3 -> free = F_134 ;
V_3 -> V_48 = V_48 ;
}
return V_3 ;
}
int F_137 ( struct V_11 * V_16 , int type , const void * V_19 )
{
struct V_153 * V_3 ;
struct V_154 * V_155 ;
int V_43 = - 1 ;
int V_10 ;
F_138 (he->hpp_list, fmt) {
if ( ! F_117 ( V_3 ) )
continue;
V_155 = F_118 ( V_3 , struct V_154 , V_156 ) ;
if ( V_155 -> V_157 -> V_185 == NULL )
continue;
V_10 = V_155 -> V_157 -> V_185 ( V_16 , type , V_19 ) ;
if ( V_10 >= 0 ) {
if ( V_43 < 0 )
V_43 = 0 ;
V_43 |= V_10 ;
}
}
return V_43 ;
}
static int F_139 ( struct V_171 * V_172 ,
struct V_186 * V_180 ,
int V_48 )
{
struct V_154 * V_155 = F_131 ( V_172 , V_48 ) ;
if ( V_155 == NULL )
return - 1 ;
F_140 ( V_180 , & V_155 -> V_156 ) ;
return 0 ;
}
static int F_141 ( struct V_171 * V_172 ,
struct V_186 * V_180 )
{
struct V_154 * V_155 = F_131 ( V_172 , 0 ) ;
if ( V_155 == NULL )
return - 1 ;
F_142 ( V_180 , & V_155 -> V_156 ) ;
return 0 ;
}
static int F_143 ( struct V_187 * V_188 )
{
if ( ! V_188 -> V_156 . V_53 ) {
int V_53 = V_188 -> V_189 ;
int V_190 = strlen ( V_188 -> V_191 -> V_47 ) ;
int V_192 = V_188 -> V_191 -> V_2 ;
if ( V_190 > V_53 )
V_53 = V_190 ;
if ( ! ( V_188 -> V_191 -> V_103 & V_193 ) ) {
V_192 = V_188 -> V_191 -> V_2 * 2 + 2 ;
}
if ( V_192 > V_53 )
V_53 = V_192 ;
V_188 -> V_156 . V_53 = V_53 ;
}
return V_188 -> V_156 . V_53 ;
}
static void F_144 ( struct V_187 * V_188 ,
struct V_11 * V_16 )
{
char * V_138 , * V_194 ;
struct V_195 * V_191 = V_188 -> V_191 ;
T_1 V_190 ;
bool V_196 = false ;
if ( V_188 -> V_90 )
return;
if ( ! V_16 -> V_95 )
V_16 -> V_95 = F_51 ( V_16 ) ;
V_190 = strlen ( V_191 -> V_47 ) ;
V_138 = V_16 -> V_95 ;
while ( V_138 ) {
V_194 = strchr ( V_138 , ' ' ) ;
if ( V_194 == NULL ) {
V_196 = true ;
V_194 = V_138 + strlen ( V_138 ) ;
}
if ( ! strncmp ( V_138 , V_191 -> V_47 , V_190 ) ) {
T_1 V_53 ;
V_138 += V_190 + 1 ;
V_53 = V_194 - V_138 ;
if ( V_53 > V_188 -> V_189 )
V_188 -> V_189 = V_53 ;
break;
}
if ( V_196 )
V_138 = NULL ;
else
V_138 = V_194 + 1 ;
}
}
static int F_145 ( struct V_153 * V_3 , struct V_159 * V_156 ,
struct V_46 * V_46 V_77 ,
int line V_77 ,
int * T_6 V_77 )
{
struct V_187 * V_188 ;
T_1 V_53 = V_3 -> V_160 ;
V_188 = F_118 ( V_3 , struct V_187 , V_156 ) ;
if ( ! V_53 )
V_53 = F_143 ( V_188 ) ;
return F_58 ( V_156 -> V_143 , V_156 -> V_2 , L_31 , V_53 , V_53 , V_188 -> V_191 -> V_47 ) ;
}
static int F_146 ( struct V_153 * V_3 ,
struct V_159 * V_156 V_77 ,
struct V_46 * V_46 V_77 )
{
struct V_187 * V_188 ;
T_1 V_53 = V_3 -> V_160 ;
V_188 = F_118 ( V_3 , struct V_187 , V_156 ) ;
if ( ! V_53 )
V_53 = F_143 ( V_188 ) ;
return V_53 ;
}
bool F_147 ( struct V_153 * V_3 , struct V_46 * V_46 )
{
struct V_187 * V_188 ;
V_188 = F_118 ( V_3 , struct V_187 , V_156 ) ;
return F_52 ( V_46 ) == V_188 -> V_84 ;
}
static int F_148 ( struct V_153 * V_3 , struct V_159 * V_156 ,
struct V_11 * V_16 )
{
struct V_187 * V_188 ;
T_1 V_53 = V_3 -> V_160 ;
char * V_138 , * V_194 ;
struct V_195 * V_191 ;
T_1 V_190 ;
bool V_196 = false ;
int V_43 ;
V_188 = F_118 ( V_3 , struct V_187 , V_156 ) ;
if ( ! V_53 )
V_53 = F_143 ( V_188 ) ;
if ( V_188 -> V_90 )
goto V_197;
if ( ! V_16 -> V_95 )
V_16 -> V_95 = F_51 ( V_16 ) ;
V_191 = V_188 -> V_191 ;
V_190 = strlen ( V_191 -> V_47 ) ;
V_138 = V_16 -> V_95 ;
while ( V_138 ) {
V_194 = strchr ( V_138 , ' ' ) ;
if ( V_194 == NULL ) {
V_196 = true ;
V_194 = V_138 + strlen ( V_138 ) ;
}
if ( ! strncmp ( V_138 , V_191 -> V_47 , V_190 ) ) {
V_138 += V_190 + 1 ;
V_138 = F_149 ( V_138 , V_194 - V_138 ) ;
if ( V_138 == NULL )
return F_58 ( V_156 -> V_143 , V_156 -> V_2 ,
L_31 , V_53 , V_53 , L_32 ) ;
break;
}
if ( V_196 )
V_138 = NULL ;
else
V_138 = V_194 + 1 ;
}
if ( V_138 == NULL ) {
struct V_81 V_82 ;
V_197:
F_53 ( & V_82 ) ;
F_150 ( & V_82 , V_16 -> V_88 , V_188 -> V_191 ) ;
V_138 = V_82 . V_92 ;
}
V_43 = F_58 ( V_156 -> V_143 , V_156 -> V_2 , L_31 , V_53 , V_53 , V_138 ) ;
free ( V_138 ) ;
return V_43 ;
}
static T_3 F_151 ( struct V_153 * V_3 ,
struct V_11 * V_162 , struct V_11 * V_163 )
{
struct V_187 * V_188 ;
struct V_195 * V_191 ;
unsigned V_198 , V_2 ;
V_188 = F_118 ( V_3 , struct V_187 , V_156 ) ;
if ( V_163 == NULL ) {
F_144 ( V_188 , V_162 ) ;
return 0 ;
}
V_191 = V_188 -> V_191 ;
if ( V_191 -> V_103 & V_199 ) {
unsigned long long V_200 ;
F_152 ( V_191 , V_162 -> V_88 , & V_200 ) ;
V_198 = V_200 & 0xffff ;
V_2 = ( V_200 >> 16 ) & 0xffff ;
if ( V_2 > V_188 -> V_189 )
V_188 -> V_189 = V_2 ;
} else {
V_198 = V_191 -> V_198 ;
V_2 = V_191 -> V_2 ;
}
return memcmp ( V_162 -> V_88 + V_198 , V_163 -> V_88 + V_198 , V_2 ) ;
}
bool F_153 ( struct V_153 * V_3 )
{
return V_3 -> V_176 == F_151 ;
}
static bool F_154 ( struct V_153 * V_162 , struct V_153 * V_163 )
{
struct V_187 * V_201 ;
struct V_187 * V_202 ;
if ( ! F_153 ( V_162 ) || ! F_153 ( V_163 ) )
return false ;
V_201 = F_118 ( V_162 , struct V_187 , V_156 ) ;
V_202 = F_118 ( V_163 , struct V_187 , V_156 ) ;
return V_201 -> V_191 == V_202 -> V_191 ;
}
static void F_155 ( struct V_153 * V_3 )
{
struct V_187 * V_188 ;
V_188 = F_118 ( V_3 , struct V_187 , V_156 ) ;
free ( V_188 ) ;
}
static struct V_187 *
F_156 ( struct V_83 * V_84 , struct V_195 * V_191 ,
int V_48 )
{
struct V_187 * V_188 ;
V_188 = malloc ( sizeof( * V_188 ) ) ;
if ( V_188 == NULL ) {
F_157 ( L_30 ) ;
return NULL ;
}
V_188 -> V_84 = V_84 ;
V_188 -> V_191 = V_191 ;
V_188 -> V_189 = 0 ;
V_188 -> V_156 . V_47 = V_191 -> V_47 ;
V_188 -> V_156 . V_168 = F_145 ;
V_188 -> V_156 . V_17 = F_146 ;
V_188 -> V_156 . V_173 = F_148 ;
V_188 -> V_156 . V_175 = NULL ;
V_188 -> V_156 . V_176 = F_151 ;
V_188 -> V_156 . V_177 = F_151 ;
V_188 -> V_156 . V_178 = F_151 ;
V_188 -> V_156 . V_179 = F_154 ;
V_188 -> V_156 . free = F_155 ;
F_133 ( & V_188 -> V_156 . V_180 ) ;
F_133 ( & V_188 -> V_156 . V_181 ) ;
V_188 -> V_156 . V_182 = false ;
V_188 -> V_156 . V_53 = 0 ;
V_188 -> V_156 . V_160 = 0 ;
V_188 -> V_156 . V_48 = V_48 ;
return V_188 ;
}
struct V_153 * F_158 ( struct V_153 * V_3 )
{
struct V_153 * V_203 = NULL ;
if ( F_117 ( V_3 ) ) {
struct V_154 * V_155 , * V_204 ;
V_155 = F_118 ( V_3 , struct V_154 , V_156 ) ;
V_204 = F_136 ( V_155 , sizeof( * V_155 ) ) ;
if ( V_204 )
V_203 = & V_204 -> V_156 ;
} else if ( F_153 ( V_3 ) ) {
struct V_187 * V_188 , * V_205 ;
V_188 = F_118 ( V_3 , struct V_187 , V_156 ) ;
V_205 = F_136 ( V_188 , sizeof( * V_188 ) ) ;
if ( V_205 )
V_203 = & V_205 -> V_156 ;
} else {
V_203 = F_136 ( V_3 , sizeof( * V_3 ) ) ;
}
F_133 ( & V_203 -> V_180 ) ;
F_133 ( & V_203 -> V_181 ) ;
return V_203 ;
}
static int F_159 ( char * V_138 , char * * V_206 , char * * V_191 , char * * V_207 )
{
char * V_208 , * V_209 , * V_210 ;
V_208 = V_138 ;
V_209 = strchr ( V_138 , '.' ) ;
if ( V_209 ) {
* V_209 ++ = '\0' ;
} else {
V_208 = NULL ;
V_209 = V_138 ;
}
V_210 = strchr ( V_209 , '/' ) ;
if ( V_210 )
* V_210 ++ = '\0' ;
* V_206 = V_208 ;
* V_191 = V_209 ;
* V_207 = V_210 ;
return 0 ;
}
static struct V_83 * F_160 ( struct V_211 * V_212 , char * V_208 )
{
struct V_83 * V_84 = NULL ;
struct V_83 * V_194 ;
bool V_213 ;
if ( V_208 [ 0 ] == '%' ) {
int V_214 = strtol ( V_208 + 1 , NULL , 0 ) ;
if ( V_214 > V_212 -> V_215 )
return NULL ;
V_84 = F_161 ( V_212 ) ;
while ( -- V_214 > 0 )
V_84 = F_162 ( V_84 ) ;
return V_84 ;
}
V_213 = ! ! strchr ( V_208 , ':' ) ;
F_163 (evlist, pos) {
if ( V_213 && ! strcmp ( V_194 -> V_47 , V_208 ) )
return V_194 ;
if ( ! V_213 && strstr ( V_194 -> V_47 , V_208 ) ) {
if ( V_84 ) {
F_157 ( L_33 ,
V_208 , V_84 -> V_47 , V_194 -> V_47 ) ;
return NULL ;
}
V_84 = V_194 ;
}
}
return V_84 ;
}
static int F_164 ( struct V_83 * V_84 ,
struct V_195 * V_191 ,
bool V_90 , int V_48 )
{
struct V_187 * V_188 ;
V_188 = F_156 ( V_84 , V_191 , V_48 ) ;
if ( V_188 == NULL )
return - V_216 ;
V_188 -> V_90 = V_90 ;
F_165 ( & V_188 -> V_156 ) ;
return 0 ;
}
static int F_166 ( struct V_83 * V_84 , bool V_90 , int V_48 )
{
int V_43 ;
struct V_195 * V_191 ;
V_191 = V_84 -> V_91 -> V_167 . V_217 ;
while ( V_191 ) {
V_43 = F_164 ( V_84 , V_191 , V_90 , V_48 ) ;
if ( V_43 < 0 )
return V_43 ;
V_191 = V_191 -> V_218 ;
}
return 0 ;
}
static int F_167 ( struct V_211 * V_212 , bool V_90 ,
int V_48 )
{
int V_43 ;
struct V_83 * V_84 ;
F_163 (evlist, evsel) {
if ( V_84 -> V_93 . type != V_94 )
continue;
V_43 = F_166 ( V_84 , V_90 , V_48 ) ;
if ( V_43 < 0 )
return V_43 ;
}
return 0 ;
}
static int F_168 ( struct V_211 * V_212 ,
char * V_209 , bool V_90 , int V_48 )
{
int V_43 = - V_219 ;
struct V_83 * V_84 ;
struct V_195 * V_191 ;
F_163 (evlist, evsel) {
if ( V_84 -> V_93 . type != V_94 )
continue;
V_191 = F_169 ( V_84 -> V_91 , V_209 ) ;
if ( V_191 == NULL )
continue;
V_43 = F_164 ( V_84 , V_191 , V_90 , V_48 ) ;
if ( V_43 < 0 )
break;
}
return V_43 ;
}
static int F_170 ( struct V_211 * V_212 , const char * V_220 ,
int V_48 )
{
char * V_138 , * V_208 , * V_209 , * V_210 ;
struct V_83 * V_84 ;
struct V_195 * V_191 ;
bool V_90 = V_6 . V_90 ;
int V_43 = 0 ;
if ( V_212 == NULL )
return - V_221 ;
V_138 = F_171 ( V_220 ) ;
if ( V_138 == NULL )
return - V_216 ;
if ( F_159 ( V_138 , & V_208 , & V_209 , & V_210 ) < 0 ) {
V_43 = - V_222 ;
goto V_106;
}
if ( V_210 ) {
if ( strcmp ( V_210 , L_34 ) ) {
F_157 ( L_35 , V_210 ) ;
V_43 = - V_222 ;
goto V_106;
}
V_90 = true ;
}
if ( ! strcmp ( V_209 , L_36 ) ) {
V_43 = F_167 ( V_212 , V_90 , V_48 ) ;
goto V_106;
}
if ( V_208 == NULL ) {
V_43 = F_168 ( V_212 , V_209 , V_90 , V_48 ) ;
goto V_106;
}
V_84 = F_160 ( V_212 , V_208 ) ;
if ( V_84 == NULL ) {
F_157 ( L_37 , V_208 ) ;
V_43 = - V_221 ;
goto V_106;
}
if ( V_84 -> V_93 . type != V_94 ) {
F_157 ( L_38 , V_208 ) ;
V_43 = - V_222 ;
goto V_106;
}
if ( ! strcmp ( V_209 , L_39 ) ) {
V_43 = F_166 ( V_84 , V_90 , V_48 ) ;
} else {
V_191 = F_169 ( V_84 -> V_91 , V_209 ) ;
if ( V_191 == NULL ) {
F_157 ( L_40 ,
V_208 , V_209 ) ;
return - V_221 ;
}
V_43 = F_164 ( V_84 , V_191 , V_90 , V_48 ) ;
}
V_106:
free ( V_138 ) ;
return V_43 ;
}
static int F_172 ( struct V_171 * V_172 ,
struct V_186 * V_180 ,
int V_48 )
{
if ( V_172 -> V_223 )
return 0 ;
if ( F_139 ( V_172 , V_180 , V_48 ) < 0 )
return - 1 ;
if ( V_172 -> V_173 -> V_165 )
V_180 -> V_224 = 1 ;
V_172 -> V_223 = 1 ;
return 0 ;
}
static int F_173 ( struct V_183 * V_184 ,
struct V_186 * V_180 ,
int V_48 )
{
struct V_153 * V_3 ;
if ( V_184 -> V_223 )
return 0 ;
V_3 = F_135 ( V_184 , V_48 ) ;
if ( ! V_3 )
return - 1 ;
V_184 -> V_223 = 1 ;
F_140 ( V_180 , V_3 ) ;
return 0 ;
}
static int F_174 ( struct V_186 * V_180 ,
struct V_171 * V_172 )
{
if ( V_172 -> V_223 )
return 0 ;
if ( F_141 ( V_172 , V_180 ) < 0 )
return - 1 ;
V_172 -> V_223 = 1 ;
return 0 ;
}
static int F_175 ( struct V_186 * V_180 ,
struct V_183 * V_184 )
{
struct V_153 * V_3 ;
if ( V_184 -> V_223 )
return 0 ;
V_3 = F_135 ( V_184 , 0 ) ;
if ( ! V_3 )
return - 1 ;
V_184 -> V_223 = 1 ;
F_142 ( V_180 , V_3 ) ;
return 0 ;
}
int F_176 ( unsigned V_225 )
{
F_177 ( V_225 >= V_226 ) ;
return F_175 ( & V_186 , & V_227 [ V_225 ] ) ;
}
int F_178 ( struct V_186 * V_180 , const char * V_220 ,
struct V_211 * V_212 ,
int V_48 )
{
unsigned int V_139 ;
for ( V_139 = 0 ; V_139 < F_179 ( V_228 ) ; V_139 ++ ) {
struct V_171 * V_172 = & V_228 [ V_139 ] ;
if ( strncasecmp ( V_220 , V_172 -> V_47 , strlen ( V_220 ) ) )
continue;
if ( V_172 -> V_173 == & V_229 ) {
int V_43 = regcomp ( & V_230 , V_231 , V_232 ) ;
if ( V_43 ) {
char V_233 [ V_234 ] ;
regerror ( V_43 , & V_230 , V_233 , sizeof( V_233 ) ) ;
F_132 ( L_41 , V_231 , V_233 ) ;
return - V_222 ;
}
V_180 -> V_68 = 1 ;
} else if ( V_172 -> V_173 == & V_235 ) {
V_180 -> V_44 = 1 ;
if ( V_236 == V_237 )
V_172 -> V_173 -> V_165 = F_22 ;
} else if ( V_172 -> V_173 == & V_238 ) {
V_180 -> V_25 = 1 ;
} else if ( V_172 -> V_173 == & V_239 ) {
V_180 -> V_78 = 1 ;
} else if ( V_172 -> V_173 == & V_240 ) {
V_180 -> V_14 = 1 ;
} else if ( V_172 -> V_173 == & V_241 ) {
V_180 -> V_18 = 1 ;
}
return F_172 ( V_172 , V_180 , V_48 ) ;
}
for ( V_139 = 0 ; V_139 < F_179 ( V_227 ) ; V_139 ++ ) {
struct V_183 * V_184 = & V_227 [ V_139 ] ;
if ( strncasecmp ( V_220 , V_184 -> V_47 , strlen ( V_220 ) ) )
continue;
return F_173 ( V_184 , V_180 , V_48 ) ;
}
for ( V_139 = 0 ; V_139 < F_179 ( V_242 ) ; V_139 ++ ) {
struct V_171 * V_172 = & V_242 [ V_139 ] ;
if ( strncasecmp ( V_220 , V_172 -> V_47 , strlen ( V_220 ) ) )
continue;
if ( V_236 != V_243 )
return - V_222 ;
if ( V_172 -> V_173 == & V_244 || V_172 -> V_173 == & V_245 )
V_180 -> V_44 = 1 ;
F_172 ( V_172 , V_180 , V_48 ) ;
return 0 ;
}
for ( V_139 = 0 ; V_139 < F_179 ( V_246 ) ; V_139 ++ ) {
struct V_171 * V_172 = & V_246 [ V_139 ] ;
if ( strncasecmp ( V_220 , V_172 -> V_47 , strlen ( V_220 ) ) )
continue;
if ( V_236 != V_247 )
return - V_222 ;
if ( V_172 -> V_173 == & V_248 && V_249 == 0 )
return - V_222 ;
if ( V_172 -> V_173 == & V_250 )
V_180 -> V_44 = 1 ;
F_172 ( V_172 , V_180 , V_48 ) ;
return 0 ;
}
if ( ! F_170 ( V_212 , V_220 , V_48 ) )
return 0 ;
return - V_219 ;
}
static int F_180 ( struct V_186 * V_180 , char * V_138 ,
struct V_211 * V_212 )
{
char * V_251 , * V_220 ;
int V_43 = 0 ;
int V_48 = 0 ;
int V_252 = 1 ;
bool V_253 = false ;
do {
V_220 = V_138 ;
V_251 = strpbrk ( V_138 , L_42 ) ;
if ( V_251 ) {
if ( V_253 )
V_252 = V_48 ;
else
V_252 = V_48 + 1 ;
if ( * V_251 == '{' )
V_253 = true ;
else if ( * V_251 == '}' )
V_253 = false ;
* V_251 = '\0' ;
V_138 = V_251 + 1 ;
}
if ( * V_220 ) {
V_43 = F_178 ( V_180 , V_220 , V_212 , V_48 ) ;
if ( V_43 == - V_222 ) {
if ( ! V_249 && ! strncasecmp ( V_220 , L_43 , strlen ( V_220 ) ) )
F_132 ( L_44 ) ;
else
F_132 ( L_45 , V_220 ) ;
break;
} else if ( V_43 == - V_219 ) {
F_132 ( L_46 , V_220 ) ;
break;
}
}
V_48 = V_252 ;
} while ( V_251 );
return V_43 ;
}
static const char * F_181 ( struct V_211 * V_212 )
{
const char * V_254 [] = {
V_255 ,
V_256 ,
V_257 ,
V_258 ,
V_259 ,
V_260 ,
} ;
bool V_261 = true ;
struct V_83 * V_84 ;
F_177 ( V_236 >= F_179 ( V_254 ) ) ;
if ( V_212 == NULL || F_182 ( V_212 ) )
goto V_262;
F_163 (evlist, evsel) {
if ( V_84 -> V_93 . type != V_94 ) {
V_261 = false ;
break;
}
}
if ( V_261 ) {
V_236 = V_263 ;
if ( V_6 . V_90 )
return L_36 ;
}
V_262:
return V_254 [ V_236 ] ;
}
static int F_183 ( struct V_211 * V_212 )
{
char * V_264 ;
if ( ! V_265 || F_184 ( V_265 ) )
return 0 ;
if ( V_265 [ 1 ] == '\0' ) {
F_132 ( L_47 ) ;
return - V_222 ;
}
if ( F_185 ( & V_264 , L_48 ,
F_181 ( V_212 ) , V_265 + 1 ) < 0 ) {
F_132 ( L_49 ) ;
return - V_216 ;
}
V_265 = V_264 ;
return 0 ;
}
static char * F_186 ( const char * V_266 , char * V_138 )
{
char * V_4 ;
if ( ! V_138 || strstr ( V_138 , V_266 ) )
return V_138 ;
if ( F_185 ( & V_4 , L_48 , V_266 , V_138 ) < 0 )
return NULL ;
free ( V_138 ) ;
return V_4 ;
}
static char * F_187 ( char * V_267 )
{
if ( V_236 == V_237 )
return V_267 ;
V_267 = F_186 ( L_50 , V_267 ) ;
if ( V_6 . V_268 )
V_267 = F_186 ( L_51 , V_267 ) ;
return V_267 ;
}
static int F_188 ( struct V_211 * V_212 )
{
char * V_138 ;
const char * V_269 ;
int V_43 = 0 ;
V_43 = F_183 ( V_212 ) ;
if ( V_43 )
return V_43 ;
V_269 = V_265 ;
if ( V_269 == NULL ) {
if ( F_184 ( V_270 ) ) {
return 0 ;
}
V_269 = F_181 ( V_212 ) ;
}
V_138 = F_171 ( V_269 ) ;
if ( V_138 == NULL ) {
F_132 ( L_52 ) ;
return - V_216 ;
}
if ( ! F_184 ( V_270 ) ) {
V_138 = F_187 ( V_138 ) ;
if ( V_138 == NULL ) {
F_132 ( L_53 ) ;
return - V_216 ;
}
}
V_43 = F_180 ( & V_186 , V_138 , V_212 ) ;
free ( V_138 ) ;
return V_43 ;
}
void F_189 ( int V_271 , bool V_182 )
{
struct V_153 * V_3 ;
struct V_154 * V_155 ;
F_138 (&perf_hpp_list, fmt) {
if ( ! F_117 ( V_3 ) )
continue;
V_155 = F_118 ( V_3 , struct V_154 , V_156 ) ;
if ( V_155 -> V_157 -> V_158 == V_271 ) {
V_3 -> V_182 = V_182 ;
break;
}
}
}
static bool F_190 ( struct V_272 * V_180 , const char * V_273 , T_7 * V_274 )
{
if ( V_180 && F_191 ( V_180 ) == 1 ) {
if ( V_274 != NULL )
fprintf ( V_274 , L_54 , V_273 ,
F_192 ( V_180 , 0 ) -> V_275 ) ;
return true ;
}
return false ;
}
static bool F_193 ( int V_271 , T_7 * V_276 )
{
switch ( V_271 ) {
case V_277 :
return F_190 ( V_6 . V_278 , L_55 , V_276 ) ;
case V_279 :
return F_190 ( V_6 . V_280 , L_56 , V_276 ) ;
case V_281 :
return F_190 ( V_6 . V_282 , L_57 , V_276 ) ;
default:
break;
}
if ( V_236 != V_243 )
return false ;
switch ( V_271 ) {
case V_283 :
return F_190 ( V_6 . V_284 , L_58 , V_276 ) ;
case V_285 :
return F_190 ( V_6 . V_286 , L_59 , V_276 ) ;
case V_287 :
return F_190 ( V_6 . V_288 , L_60 , V_276 ) ;
case V_289 :
return F_190 ( V_6 . V_290 , L_61 , V_276 ) ;
default:
break;
}
return false ;
}
void F_194 ( T_7 * V_276 )
{
struct V_153 * V_3 ;
struct V_154 * V_155 ;
F_138 (&perf_hpp_list, fmt) {
if ( ! F_117 ( V_3 ) )
continue;
V_155 = F_118 ( V_3 , struct V_154 , V_156 ) ;
V_3 -> V_182 = F_193 ( V_155 -> V_157 -> V_158 , V_276 ) ;
}
F_138 (&perf_hpp_list, fmt) {
if ( ! F_117 ( V_3 ) )
continue;
if ( ! V_3 -> V_182 )
return;
}
F_138 (&perf_hpp_list, fmt) {
if ( ! F_117 ( V_3 ) )
continue;
V_3 -> V_182 = false ;
}
}
int F_195 ( struct V_186 * V_180 , char * V_220 )
{
unsigned int V_139 ;
for ( V_139 = 0 ; V_139 < F_179 ( V_228 ) ; V_139 ++ ) {
struct V_171 * V_172 = & V_228 [ V_139 ] ;
if ( strncasecmp ( V_220 , V_172 -> V_47 , strlen ( V_220 ) ) )
continue;
return F_174 ( V_180 , V_172 ) ;
}
for ( V_139 = 0 ; V_139 < F_179 ( V_227 ) ; V_139 ++ ) {
struct V_183 * V_184 = & V_227 [ V_139 ] ;
if ( strncasecmp ( V_220 , V_184 -> V_47 , strlen ( V_220 ) ) )
continue;
return F_175 ( V_180 , V_184 ) ;
}
for ( V_139 = 0 ; V_139 < F_179 ( V_242 ) ; V_139 ++ ) {
struct V_171 * V_172 = & V_242 [ V_139 ] ;
if ( strncasecmp ( V_220 , V_172 -> V_47 , strlen ( V_220 ) ) )
continue;
return F_174 ( V_180 , V_172 ) ;
}
for ( V_139 = 0 ; V_139 < F_179 ( V_246 ) ; V_139 ++ ) {
struct V_171 * V_172 = & V_246 [ V_139 ] ;
if ( strncasecmp ( V_220 , V_172 -> V_47 , strlen ( V_220 ) ) )
continue;
return F_174 ( V_180 , V_172 ) ;
}
return - V_219 ;
}
static int F_196 ( struct V_186 * V_180 , char * V_138 )
{
char * V_251 , * V_220 ;
int V_43 = 0 ;
for ( V_220 = strtok_r ( V_138 , L_62 , & V_251 ) ;
V_220 ; V_220 = strtok_r ( NULL , L_62 , & V_251 ) ) {
V_43 = F_195 ( V_180 , V_220 ) ;
if ( V_43 == - V_222 ) {
F_132 ( L_63 , V_220 ) ;
break;
} else if ( V_43 == - V_219 ) {
F_132 ( L_64 , V_220 ) ;
break;
}
}
return V_43 ;
}
void F_197 ( void )
{
unsigned int V_139 ;
for ( V_139 = 0 ; V_139 < F_179 ( V_228 ) ; V_139 ++ )
V_228 [ V_139 ] . V_223 = 0 ;
for ( V_139 = 0 ; V_139 < F_179 ( V_227 ) ; V_139 ++ )
V_227 [ V_139 ] . V_223 = 0 ;
for ( V_139 = 0 ; V_139 < F_179 ( V_242 ) ; V_139 ++ )
V_242 [ V_139 ] . V_223 = 0 ;
for ( V_139 = 0 ; V_139 < F_179 ( V_246 ) ; V_139 ++ )
V_246 [ V_139 ] . V_223 = 0 ;
}
bool F_184 ( const char * V_291 )
{
return V_291 && ( * V_291 != '+' ) ;
}
static int F_198 ( void )
{
char * V_138 , * V_292 ;
int V_43 = - V_222 ;
if ( V_270 == NULL )
return 0 ;
V_292 = V_138 = F_171 ( V_270 ) ;
if ( V_138 == NULL ) {
F_132 ( L_65 ) ;
return - V_216 ;
}
if ( ! F_184 ( V_270 ) )
V_292 ++ ;
if ( ! strlen ( V_292 ) ) {
F_132 ( L_66 ) ;
goto V_106;
}
V_43 = F_196 ( & V_186 , V_292 ) ;
V_106:
free ( V_138 ) ;
return V_43 ;
}
int F_199 ( struct V_211 * V_212 )
{
int V_233 ;
V_233 = F_188 ( V_212 ) ;
if ( V_233 < 0 )
return V_233 ;
if ( V_231 != V_293 ) {
V_233 = F_178 ( & V_186 , L_67 , V_212 , - 1 ) ;
if ( V_233 < 0 )
return V_233 ;
}
F_197 () ;
if ( V_236 != V_237 )
F_200 () ;
V_233 = F_198 () ;
if ( V_233 < 0 )
return V_233 ;
F_201 ( & V_186 ) ;
F_202 ( & V_186 ) ;
if ( F_203 ( & V_186 , V_212 ) < 0 )
return - 1 ;
return 0 ;
}
void F_204 ( void )
{
V_186 . V_224 = 0 ;
V_186 . V_68 = 0 ;
V_186 . V_44 = 0 ;
V_186 . V_25 = 0 ;
V_270 = NULL ;
V_265 = NULL ;
F_197 () ;
F_205 ( & V_186 ) ;
}
