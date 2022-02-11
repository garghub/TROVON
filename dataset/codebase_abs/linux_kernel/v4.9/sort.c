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
if ( V_30 ) {
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
const char * V_34 = ! V_30 ? V_22 -> V_25 -> V_32 :
V_22 -> V_25 -> V_31 ;
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
if ( V_30 ) {
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
static char * F_27 ( struct V_11 * V_16 )
{
struct V_22 * V_22 = V_16 -> V_33 . V_22 ;
if ( ! V_22 )
return V_55 ;
return F_28 ( V_22 -> V_25 , F_29 ( V_22 , V_16 -> V_45 ) ,
V_16 -> V_33 . V_44 , true ) ;
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
V_12 -> V_57 -> V_59 . V_44 , true ) ;
}
if ( ! V_13 -> V_57 -> V_58 ) {
struct V_22 * V_22 = V_13 -> V_57 -> V_59 . V_22 ;
if ( ! V_22 )
V_13 -> V_57 -> V_58 = V_55 ;
else
V_13 -> V_57 -> V_58 = F_28 ( V_22 -> V_25 ,
F_29 ( V_22 ,
V_13 -> V_57 -> V_59 . V_60 ) ,
V_13 -> V_57 -> V_59 . V_44 , true ) ;
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
V_12 -> V_57 -> V_59 . V_44 , true ) ;
}
if ( ! V_13 -> V_57 -> V_61 ) {
struct V_22 * V_22 = V_13 -> V_57 -> V_62 . V_22 ;
if ( ! V_22 )
V_13 -> V_57 -> V_61 = V_55 ;
else
V_13 -> V_57 -> V_61 = F_28 ( V_22 -> V_25 ,
F_29 ( V_22 ,
V_13 -> V_57 -> V_62 . V_60 ) ,
V_13 -> V_57 -> V_62 . V_44 , true ) ;
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
V_63 -> V_33 . V_44 , false , true ) ;
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
static T_3
F_44 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
return V_13 -> V_70 - V_12 -> V_70 ;
}
static int F_45 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
return F_1 ( V_1 , V_2 , L_13 , V_17 , V_17 - 3 , V_16 -> V_70 ) ;
}
static int F_46 ( struct V_11 * V_16 , int type , const void * V_19 )
{
int V_71 = * ( const int * ) V_19 ;
if ( type != V_72 )
return - 1 ;
return V_71 >= 0 && V_16 -> V_70 != V_71 ;
}
static char * F_47 ( struct V_11 * V_16 )
{
struct V_73 V_74 ;
struct V_75 * V_76 ;
struct V_77 V_78 = {
. V_79 = V_16 -> V_80 ,
. V_2 = V_16 -> V_81 ,
} ;
V_76 = F_48 ( V_16 -> V_46 ) ;
F_49 ( & V_74 ) ;
if ( V_6 . V_82 ) {
F_50 ( & V_74 , V_16 -> V_80 , V_16 -> V_81 ,
V_76 -> V_83 ) ;
} else {
F_51 ( & V_74 , V_76 -> V_83 , & V_78 ) ;
}
return realloc ( V_74 . V_84 , V_74 . V_53 + 1 ) ;
}
static T_3
F_52 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
struct V_75 * V_76 ;
V_76 = F_48 ( V_12 -> V_46 ) ;
if ( V_76 -> V_85 . type != V_86 )
return 0 ;
if ( V_12 -> V_87 == NULL )
V_12 -> V_87 = F_47 ( V_12 ) ;
if ( V_13 -> V_87 == NULL )
V_13 -> V_87 = F_47 ( V_13 ) ;
return strcmp ( V_13 -> V_87 , V_12 -> V_87 ) ;
}
static int F_53 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
struct V_75 * V_76 ;
V_76 = F_48 ( V_16 -> V_46 ) ;
if ( V_76 -> V_85 . type != V_86 )
return F_54 ( V_1 , V_2 , L_11 , V_17 , L_14 ) ;
if ( V_16 -> V_87 == NULL )
V_16 -> V_87 = F_47 ( V_16 ) ;
return F_1 ( V_1 , V_2 , L_11 , V_17 , V_16 -> V_87 ) ;
}
static T_3
F_55 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
if ( ! V_12 -> V_57 || ! V_13 -> V_57 )
return F_2 ( V_12 -> V_57 , V_13 -> V_57 ) ;
return F_13 ( V_12 -> V_57 -> V_59 . V_22 ,
V_13 -> V_57 -> V_59 . V_22 ) ;
}
static int F_56 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
if ( V_16 -> V_57 )
return F_15 ( V_16 -> V_57 -> V_59 . V_22 ,
V_1 , V_2 , V_17 ) ;
else
return F_1 ( V_1 , V_2 , L_3 , V_17 , V_17 , L_14 ) ;
}
static int F_57 ( struct V_11 * V_16 , int type ,
const void * V_19 )
{
const struct V_25 * V_25 = V_19 ;
if ( type != V_35 )
return - 1 ;
return V_25 && ( ! V_16 -> V_57 || ! V_16 -> V_57 -> V_59 . V_22 ||
V_16 -> V_57 -> V_59 . V_22 -> V_25 != V_25 ) ;
}
static T_3
F_58 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
if ( ! V_12 -> V_57 || ! V_13 -> V_57 )
return F_2 ( V_12 -> V_57 , V_13 -> V_57 ) ;
return F_13 ( V_12 -> V_57 -> V_62 . V_22 ,
V_13 -> V_57 -> V_62 . V_22 ) ;
}
static int F_59 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
if ( V_16 -> V_57 )
return F_15 ( V_16 -> V_57 -> V_62 . V_22 ,
V_1 , V_2 , V_17 ) ;
else
return F_1 ( V_1 , V_2 , L_3 , V_17 , V_17 , L_14 ) ;
}
static int F_60 ( struct V_11 * V_16 , int type ,
const void * V_19 )
{
const struct V_25 * V_25 = V_19 ;
if ( type != V_35 )
return - 1 ;
return V_25 && ( ! V_16 -> V_57 || ! V_16 -> V_57 -> V_62 . V_22 ||
V_16 -> V_57 -> V_62 . V_22 -> V_25 != V_25 ) ;
}
static T_3
F_61 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
struct V_88 * V_89 = & V_12 -> V_57 -> V_59 ;
struct V_88 * V_90 = & V_13 -> V_57 -> V_59 ;
if ( ! V_12 -> V_57 || ! V_13 -> V_57 )
return F_2 ( V_12 -> V_57 , V_13 -> V_57 ) ;
V_89 = & V_12 -> V_57 -> V_59 ;
V_90 = & V_13 -> V_57 -> V_59 ;
if ( ! V_89 -> V_44 && ! V_90 -> V_44 )
return F_18 ( V_89 -> V_91 , V_90 -> V_91 ) ;
return F_19 ( V_89 -> V_44 , V_90 -> V_44 ) ;
}
static T_3
F_62 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
struct V_88 * V_92 , * V_93 ;
if ( ! V_12 -> V_57 || ! V_13 -> V_57 )
return F_2 ( V_12 -> V_57 , V_13 -> V_57 ) ;
V_92 = & V_12 -> V_57 -> V_62 ;
V_93 = & V_13 -> V_57 -> V_62 ;
if ( ! V_92 -> V_44 && ! V_93 -> V_44 )
return F_18 ( V_92 -> V_91 , V_93 -> V_91 ) ;
return F_19 ( V_92 -> V_44 , V_93 -> V_44 ) ;
}
static int F_63 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
if ( V_16 -> V_57 ) {
struct V_88 * V_59 = & V_16 -> V_57 -> V_59 ;
return F_23 ( V_59 -> V_22 , V_59 -> V_44 , V_59 -> V_91 ,
V_16 -> V_48 , V_1 , V_2 , V_17 ) ;
}
return F_1 ( V_1 , V_2 , L_3 , V_17 , V_17 , L_14 ) ;
}
static int F_64 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
if ( V_16 -> V_57 ) {
struct V_88 * V_62 = & V_16 -> V_57 -> V_62 ;
return F_23 ( V_62 -> V_22 , V_62 -> V_44 , V_62 -> V_91 ,
V_16 -> V_48 , V_1 , V_2 , V_17 ) ;
}
return F_1 ( V_1 , V_2 , L_3 , V_17 , V_17 , L_14 ) ;
}
static int F_65 ( struct V_11 * V_16 , int type ,
const void * V_19 )
{
const char * V_44 = V_19 ;
if ( type != V_54 )
return - 1 ;
return V_44 && ! ( V_16 -> V_57 && V_16 -> V_57 -> V_59 . V_44 &&
strstr ( V_16 -> V_57 -> V_59 . V_44 -> V_47 , V_44 ) ) ;
}
static int F_66 ( struct V_11 * V_16 , int type ,
const void * V_19 )
{
const char * V_44 = V_19 ;
if ( type != V_54 )
return - 1 ;
return V_44 && ! ( V_16 -> V_57 && V_16 -> V_57 -> V_62 . V_44 &&
strstr ( V_16 -> V_57 -> V_62 . V_44 -> V_47 , V_44 ) ) ;
}
static T_3
F_67 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
unsigned char V_94 , V_65 ;
if ( ! V_12 -> V_57 || ! V_13 -> V_57 )
return F_2 ( V_12 -> V_57 , V_13 -> V_57 ) ;
V_94 = V_12 -> V_57 -> V_95 . V_96 != V_13 -> V_57 -> V_95 . V_96 ;
V_65 = V_12 -> V_57 -> V_95 . V_97 != V_13 -> V_57 -> V_95 . V_97 ;
return V_94 || V_65 ;
}
static int F_68 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 ) {
static const char * V_98 = L_14 ;
if ( V_16 -> V_57 ) {
if ( V_16 -> V_57 -> V_95 . V_97 )
V_98 = L_15 ;
else if ( V_16 -> V_57 -> V_95 . V_96 )
V_98 = L_16 ;
}
return F_1 ( V_1 , V_2 , L_3 , V_17 , V_17 , V_98 ) ;
}
static T_3
F_69 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
return V_12 -> V_57 -> V_95 . V_99 -
V_13 -> V_57 -> V_95 . V_99 ;
}
static int F_70 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
if ( V_16 -> V_57 -> V_95 . V_99 == 0 )
return F_1 ( V_1 , V_2 , L_17 , V_17 , L_18 ) ;
return F_1 ( V_1 , V_2 , L_19 , V_17 ,
V_16 -> V_57 -> V_95 . V_99 ) ;
}
T_3
F_71 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
T_5 V_9 = 0 , V_10 = 0 ;
if ( V_12 -> V_100 )
V_9 = V_12 -> V_100 -> V_101 . V_91 ;
if ( V_13 -> V_100 )
V_10 = V_13 -> V_100 -> V_101 . V_91 ;
return ( T_3 ) ( V_10 - V_9 ) ;
}
static int F_72 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
T_5 V_91 = 0 ;
struct V_22 * V_22 = NULL ;
struct V_38 * V_44 = NULL ;
if ( V_16 -> V_100 ) {
V_91 = V_16 -> V_100 -> V_101 . V_91 ;
V_22 = V_16 -> V_100 -> V_101 . V_22 ;
V_44 = V_16 -> V_100 -> V_101 . V_44 ;
}
return F_23 ( V_22 , V_44 , V_91 , V_16 -> V_48 , V_1 , V_2 ,
V_17 ) ;
}
T_3
F_73 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
T_5 V_9 = 0 , V_10 = 0 ;
if ( V_12 -> V_100 )
V_9 = V_12 -> V_100 -> V_102 . V_91 ;
if ( V_13 -> V_100 )
V_10 = V_13 -> V_100 -> V_102 . V_91 ;
return ( T_3 ) ( V_10 - V_9 ) ;
}
static int F_74 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
T_5 V_91 = 0 ;
struct V_22 * V_22 = NULL ;
struct V_38 * V_44 = NULL ;
if ( V_16 -> V_100 ) {
V_91 = V_16 -> V_100 -> V_102 . V_91 ;
V_22 = V_16 -> V_100 -> V_102 . V_22 ;
V_44 = V_16 -> V_100 -> V_102 . V_44 ;
}
return F_23 ( V_22 , V_44 , V_91 , V_16 -> V_48 , V_1 , V_2 ,
V_17 ) ;
}
static T_3
F_75 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
struct V_22 * V_23 = NULL ;
struct V_22 * V_24 = NULL ;
if ( V_12 -> V_100 )
V_23 = V_12 -> V_100 -> V_101 . V_22 ;
if ( V_13 -> V_100 )
V_24 = V_13 -> V_100 -> V_101 . V_22 ;
return F_13 ( V_23 , V_24 ) ;
}
static int F_76 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
struct V_22 * V_22 = NULL ;
if ( V_16 -> V_100 )
V_22 = V_16 -> V_100 -> V_101 . V_22 ;
return F_15 ( V_22 , V_1 , V_2 , V_17 ) ;
}
static T_3
F_77 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
union V_103 V_104 ;
union V_103 V_105 ;
if ( V_12 -> V_100 )
V_104 = V_12 -> V_100 -> V_106 ;
else
V_104 . V_107 = V_108 ;
if ( V_13 -> V_100 )
V_105 = V_13 -> V_100 -> V_106 ;
else
V_105 . V_107 = V_108 ;
return ( T_3 ) ( V_105 . V_107 - V_104 . V_107 ) ;
}
static int F_78 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
char V_98 [ 10 ] ;
F_79 ( V_98 , sizeof( V_98 ) , V_16 -> V_100 ) ;
return F_1 ( V_1 , V_2 , L_9 , V_17 , V_98 ) ;
}
static T_3
F_80 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
union V_103 V_104 ;
union V_103 V_105 ;
if ( V_12 -> V_100 )
V_104 = V_12 -> V_100 -> V_106 ;
else
V_104 . V_109 = V_110 ;
if ( V_13 -> V_100 )
V_105 = V_13 -> V_100 -> V_106 ;
else
V_105 . V_109 = V_110 ;
return ( T_3 ) ( V_105 . V_109 - V_104 . V_109 ) ;
}
static int F_81 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
char V_98 [ 64 ] ;
F_82 ( V_98 , sizeof( V_98 ) , V_16 -> V_100 ) ;
return F_1 ( V_1 , V_2 , L_17 , V_17 , V_98 ) ;
}
static T_3
F_83 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
union V_103 V_104 ;
union V_103 V_105 ;
if ( V_12 -> V_100 )
V_104 = V_12 -> V_100 -> V_106 ;
else
V_104 . V_111 = V_112 ;
if ( V_13 -> V_100 )
V_105 = V_13 -> V_100 -> V_106 ;
else
V_105 . V_111 = V_112 ;
return ( T_3 ) ( V_105 . V_111 - V_104 . V_111 ) ;
}
static int F_84 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
char V_98 [ 64 ] ;
F_85 ( V_98 , sizeof( V_98 ) , V_16 -> V_100 ) ;
return F_1 ( V_1 , V_2 , L_17 , V_17 , V_98 ) ;
}
static T_3
F_86 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
union V_103 V_104 ;
union V_103 V_105 ;
if ( V_12 -> V_100 )
V_104 = V_12 -> V_100 -> V_106 ;
else
V_104 . V_113 = V_114 ;
if ( V_13 -> V_100 )
V_105 = V_13 -> V_100 -> V_106 ;
else
V_105 . V_113 = V_114 ;
return ( T_3 ) ( V_105 . V_113 - V_104 . V_113 ) ;
}
static int F_87 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
char V_98 [ 64 ] ;
F_88 ( V_98 , sizeof( V_98 ) , V_16 -> V_100 ) ;
return F_1 ( V_1 , V_2 , L_17 , V_17 , V_98 ) ;
}
T_3
F_89 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
T_4 V_9 , V_10 ;
struct V_22 * V_115 , * V_116 ;
if ( ! V_12 -> V_100 ) return - 1 ;
if ( ! V_13 -> V_100 ) return 1 ;
if ( V_12 -> V_117 > V_13 -> V_117 ) return - 1 ;
if ( V_12 -> V_117 < V_13 -> V_117 ) return 1 ;
V_115 = V_12 -> V_100 -> V_101 . V_22 ;
V_116 = V_13 -> V_100 -> V_101 . V_22 ;
if ( ! V_115 && ! V_116 )
goto V_91;
if ( ! V_115 ) return - 1 ;
if ( ! V_116 ) return 1 ;
if ( V_115 -> V_118 > V_116 -> V_118 ) return - 1 ;
if ( V_115 -> V_118 < V_116 -> V_118 ) return 1 ;
if ( V_115 -> V_119 > V_116 -> V_119 ) return - 1 ;
if ( V_115 -> V_119 < V_116 -> V_119 ) return 1 ;
if ( V_115 -> V_120 > V_116 -> V_120 ) return - 1 ;
if ( V_115 -> V_120 < V_116 -> V_120 ) return 1 ;
if ( V_115 -> V_121 > V_116 -> V_121 ) return - 1 ;
if ( V_115 -> V_121 < V_116 -> V_121 ) return 1 ;
if ( ( V_12 -> V_117 != V_122 ) &&
( ! ( V_115 -> V_95 & V_123 ) ) &&
! V_115 -> V_118 && ! V_115 -> V_119 && ! V_115 -> V_120 &&
! V_115 -> V_121 ) {
if ( V_12 -> V_14 -> V_124 > V_13 -> V_14 -> V_124 ) return - 1 ;
if ( V_12 -> V_14 -> V_124 < V_13 -> V_14 -> V_124 ) return 1 ;
}
V_91:
V_9 = F_90 ( V_12 -> V_100 -> V_101 . V_60 ) ;
V_10 = F_90 ( V_13 -> V_100 -> V_101 . V_60 ) ;
if ( V_9 > V_10 ) return - 1 ;
if ( V_9 < V_10 ) return 1 ;
return 0 ;
}
static int F_91 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
T_5 V_91 = 0 ;
struct V_22 * V_22 = NULL ;
struct V_38 * V_44 = NULL ;
char V_48 = V_16 -> V_48 ;
if ( V_16 -> V_100 ) {
V_91 = F_90 ( V_16 -> V_100 -> V_101 . V_60 ) ;
V_22 = V_16 -> V_100 -> V_101 . V_22 ;
V_44 = V_16 -> V_100 -> V_101 . V_44 ;
if ( ( V_16 -> V_117 != V_122 ) &&
V_22 && ( V_22 -> type == V_51 ) &&
( V_22 -> V_95 & V_123 ) &&
( V_22 -> V_118 || V_22 -> V_119 || V_22 -> V_120 ||
V_22 -> V_121 ) )
V_48 = 's' ;
else if ( ! V_22 )
V_48 = 'X' ;
}
return F_23 ( V_22 , V_44 , V_91 , V_48 , V_1 , V_2 ,
V_17 ) ;
}
static T_4 F_92 ( struct V_11 * V_16 )
{
return V_16 -> V_125 . V_126 ? V_16 -> V_125 . V_127 / V_16 -> V_125 . V_126 : 0 ;
}
static T_3
F_93 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
return F_92 ( V_12 ) - F_92 ( V_13 ) ;
}
static int F_94 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
return F_1 ( V_1 , V_2 , L_20 , V_17 , F_92 ( V_16 ) ) ;
}
static T_3
F_95 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
return V_12 -> V_125 . V_127 - V_13 -> V_125 . V_127 ;
}
static int F_96 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
return F_1 ( V_1 , V_2 , L_20 , V_17 , V_16 -> V_125 . V_127 ) ;
}
static T_3
F_97 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
if ( ! V_12 -> V_57 || ! V_13 -> V_57 )
return F_2 ( V_12 -> V_57 , V_13 -> V_57 ) ;
return V_12 -> V_57 -> V_95 . abort !=
V_13 -> V_57 -> V_95 . abort ;
}
static int F_98 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
static const char * V_98 = L_14 ;
if ( V_16 -> V_57 ) {
if ( V_16 -> V_57 -> V_95 . abort )
V_98 = L_21 ;
else
V_98 = L_22 ;
}
return F_1 ( V_1 , V_2 , L_17 , V_17 , V_98 ) ;
}
static T_3
F_99 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
if ( ! V_12 -> V_57 || ! V_13 -> V_57 )
return F_2 ( V_12 -> V_57 , V_13 -> V_57 ) ;
return V_12 -> V_57 -> V_95 . V_128 !=
V_13 -> V_57 -> V_95 . V_128 ;
}
static int F_100 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
static const char * V_98 = L_14 ;
if ( V_16 -> V_57 ) {
if ( V_16 -> V_57 -> V_95 . V_128 )
V_98 = L_23 ;
else
V_98 = L_22 ;
}
return F_1 ( V_1 , V_2 , L_17 , V_17 , V_98 ) ;
}
static T_3
F_101 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
return V_12 -> V_129 - V_13 -> V_129 ;
}
static inline char * F_102 ( char * V_65 , const char * V_130 )
{
strcpy ( V_65 , V_130 ) ;
return V_65 + strlen ( V_130 ) ;
}
int F_103 ( void )
{
int V_131 ;
int V_53 = 0 ;
for ( V_131 = 0 ; V_132 [ V_131 ] . V_47 ; V_131 ++ ) {
if ( ! V_132 [ V_131 ] . V_133 )
V_53 += strlen ( V_132 [ V_131 ] . V_47 ) ;
}
V_53 += 4 ;
return V_53 ;
}
static int F_104 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
T_4 V_134 = V_16 -> V_129 ;
char V_135 [ 128 ] ;
char * V_65 = V_135 ;
int V_131 ;
V_135 [ 0 ] = 0 ;
for ( V_131 = 0 ; V_132 [ V_131 ] . V_47 ; V_131 ++ )
if ( V_132 [ V_131 ] . V_136 & V_134 )
V_65 = F_102 ( V_65 , V_132 [ V_131 ] . V_47 ) ;
if ( V_134 && ! ( V_134 & ( V_137 | V_138 ) ) )
V_65 = F_102 ( V_65 , L_24 ) ;
if ( V_134 & V_139 ) {
sprintf ( V_65 , L_25 V_140 ,
( V_134 & V_139 ) >>
V_141 ) ;
V_65 += strlen ( V_65 ) ;
}
return F_1 ( V_1 , V_2 , L_17 , V_17 , V_135 ) ;
}
void F_105 ( struct V_142 * V_3 , struct V_46 * V_46 )
{
struct V_143 * V_144 ;
if ( ! F_106 ( V_3 ) )
return;
V_144 = F_107 ( V_3 , struct V_143 , V_145 ) ;
F_108 ( V_46 , V_144 -> V_146 -> V_147 , strlen ( V_3 -> V_47 ) ) ;
}
static int F_109 ( struct V_142 * V_3 , struct V_148 * V_145 ,
struct V_46 * V_46 , int line V_149 ,
int * T_6 V_149 )
{
struct V_143 * V_144 ;
T_1 V_53 = V_3 -> V_150 ;
V_144 = F_107 ( V_3 , struct V_143 , V_145 ) ;
if ( ! V_53 )
V_53 = F_110 ( V_46 , V_144 -> V_146 -> V_147 ) ;
return F_54 ( V_145 -> V_135 , V_145 -> V_2 , L_3 , V_53 , V_53 , V_3 -> V_47 ) ;
}
static int F_111 ( struct V_142 * V_3 ,
struct V_148 * V_145 V_149 ,
struct V_46 * V_46 )
{
struct V_143 * V_144 ;
T_1 V_53 = V_3 -> V_150 ;
V_144 = F_107 ( V_3 , struct V_143 , V_145 ) ;
if ( ! V_53 )
V_53 = F_110 ( V_46 , V_144 -> V_146 -> V_147 ) ;
return V_53 ;
}
static int F_112 ( struct V_142 * V_3 , struct V_148 * V_145 ,
struct V_11 * V_16 )
{
struct V_143 * V_144 ;
T_1 V_53 = V_3 -> V_150 ;
V_144 = F_107 ( V_3 , struct V_143 , V_145 ) ;
if ( ! V_53 )
V_53 = F_110 ( V_16 -> V_46 , V_144 -> V_146 -> V_147 ) ;
return V_144 -> V_146 -> V_151 ( V_16 , V_145 -> V_135 , V_145 -> V_2 , V_53 ) ;
}
static T_3 F_113 ( struct V_142 * V_3 ,
struct V_11 * V_152 , struct V_11 * V_153 )
{
struct V_143 * V_144 ;
V_144 = F_107 ( V_3 , struct V_143 , V_145 ) ;
return V_144 -> V_146 -> V_154 ( V_152 , V_153 ) ;
}
static T_3 F_114 ( struct V_142 * V_3 ,
struct V_11 * V_152 , struct V_11 * V_153 )
{
struct V_143 * V_144 ;
T_3 (* F_115)( struct V_11 * , struct V_11 * );
V_144 = F_107 ( V_3 , struct V_143 , V_145 ) ;
F_115 = V_144 -> V_146 -> V_155 ? : V_144 -> V_146 -> V_154 ;
return F_115 ( V_152 , V_153 ) ;
}
static T_3 F_116 ( struct V_142 * V_3 ,
struct V_11 * V_152 , struct V_11 * V_153 )
{
struct V_143 * V_144 ;
T_3 (* F_117)( struct V_11 * , struct V_11 * );
V_144 = F_107 ( V_3 , struct V_143 , V_145 ) ;
F_117 = V_144 -> V_146 -> V_156 ? : V_144 -> V_146 -> V_154 ;
return F_117 ( V_152 , V_153 ) ;
}
bool F_106 ( struct V_142 * V_157 )
{
return V_157 -> V_158 == F_109 ;
}
static bool F_118 ( struct V_142 * V_152 , struct V_142 * V_153 )
{
struct V_143 * V_159 ;
struct V_143 * V_160 ;
if ( ! F_106 ( V_152 ) || ! F_106 ( V_153 ) )
return false ;
V_159 = F_107 ( V_152 , struct V_143 , V_145 ) ;
V_160 = F_107 ( V_153 , struct V_143 , V_145 ) ;
return V_159 -> V_146 == V_160 -> V_146 ;
}
static void F_119 ( struct V_142 * V_3 )
{
struct V_143 * V_144 ;
V_144 = F_107 ( V_3 , struct V_143 , V_145 ) ;
free ( V_144 ) ;
}
static struct V_143 *
F_120 ( struct V_161 * V_162 , int V_48 )
{
struct V_143 * V_144 ;
V_144 = malloc ( sizeof( * V_144 ) ) ;
if ( V_144 == NULL ) {
F_121 ( L_26 ) ;
return NULL ;
}
V_144 -> V_146 = V_162 -> V_163 ;
V_144 -> V_145 . V_47 = V_162 -> V_163 -> V_164 ;
V_144 -> V_145 . V_158 = F_109 ;
V_144 -> V_145 . V_17 = F_111 ;
V_144 -> V_145 . V_163 = F_112 ;
V_144 -> V_145 . V_165 = NULL ;
V_144 -> V_145 . V_166 = F_113 ;
V_144 -> V_145 . V_167 = F_114 ;
V_144 -> V_145 . V_168 = F_116 ;
V_144 -> V_145 . V_169 = F_118 ;
V_144 -> V_145 . free = F_119 ;
F_122 ( & V_144 -> V_145 . V_170 ) ;
F_122 ( & V_144 -> V_145 . V_171 ) ;
V_144 -> V_145 . V_172 = false ;
V_144 -> V_145 . V_53 = 0 ;
V_144 -> V_145 . V_150 = 0 ;
V_144 -> V_145 . V_48 = V_48 ;
return V_144 ;
}
static void F_123 ( struct V_142 * V_3 )
{
free ( V_3 ) ;
}
static struct V_142 * F_124 ( struct V_173 * V_174 ,
int V_48 )
{
struct V_142 * V_3 ;
V_3 = F_125 ( V_174 -> V_3 , sizeof( * V_3 ) ) ;
if ( V_3 ) {
F_122 ( & V_3 -> V_170 ) ;
F_122 ( & V_3 -> V_171 ) ;
V_3 -> free = F_123 ;
V_3 -> V_48 = V_48 ;
}
return V_3 ;
}
int F_126 ( struct V_11 * V_16 , int type , const void * V_19 )
{
struct V_142 * V_3 ;
struct V_143 * V_144 ;
int V_43 = - 1 ;
int V_10 ;
F_127 (he->hpp_list, fmt) {
if ( ! F_106 ( V_3 ) )
continue;
V_144 = F_107 ( V_3 , struct V_143 , V_145 ) ;
if ( V_144 -> V_146 -> V_175 == NULL )
continue;
V_10 = V_144 -> V_146 -> V_175 ( V_16 , type , V_19 ) ;
if ( V_10 >= 0 ) {
if ( V_43 < 0 )
V_43 = 0 ;
V_43 |= V_10 ;
}
}
return V_43 ;
}
static int F_128 ( struct V_161 * V_162 ,
struct V_176 * V_170 ,
int V_48 )
{
struct V_143 * V_144 = F_120 ( V_162 , V_48 ) ;
if ( V_144 == NULL )
return - 1 ;
F_129 ( V_170 , & V_144 -> V_145 ) ;
return 0 ;
}
static int F_130 ( struct V_161 * V_162 ,
struct V_176 * V_170 )
{
struct V_143 * V_144 = F_120 ( V_162 , 0 ) ;
if ( V_144 == NULL )
return - 1 ;
F_131 ( V_170 , & V_144 -> V_145 ) ;
return 0 ;
}
static int F_132 ( struct V_177 * V_178 )
{
if ( ! V_178 -> V_145 . V_53 ) {
int V_53 = V_178 -> V_179 ;
int V_180 = strlen ( V_178 -> V_181 -> V_47 ) ;
int V_182 = V_178 -> V_181 -> V_2 ;
if ( V_180 > V_53 )
V_53 = V_180 ;
if ( ! ( V_178 -> V_181 -> V_95 & V_183 ) ) {
V_182 = V_178 -> V_181 -> V_2 * 2 + 2 ;
}
if ( V_182 > V_53 )
V_53 = V_182 ;
V_178 -> V_145 . V_53 = V_53 ;
}
return V_178 -> V_145 . V_53 ;
}
static void F_133 ( struct V_177 * V_178 ,
struct V_11 * V_16 )
{
char * V_130 , * V_184 ;
struct V_185 * V_181 = V_178 -> V_181 ;
T_1 V_180 ;
bool V_186 = false ;
if ( V_178 -> V_82 )
return;
if ( ! V_16 -> V_87 )
V_16 -> V_87 = F_47 ( V_16 ) ;
V_180 = strlen ( V_181 -> V_47 ) ;
V_130 = V_16 -> V_87 ;
while ( V_130 ) {
V_184 = strchr ( V_130 , ' ' ) ;
if ( V_184 == NULL ) {
V_186 = true ;
V_184 = V_130 + strlen ( V_130 ) ;
}
if ( ! strncmp ( V_130 , V_181 -> V_47 , V_180 ) ) {
T_1 V_53 ;
V_130 += V_180 + 1 ;
V_53 = V_184 - V_130 ;
if ( V_53 > V_178 -> V_179 )
V_178 -> V_179 = V_53 ;
break;
}
if ( V_186 )
V_130 = NULL ;
else
V_130 = V_184 + 1 ;
}
}
static int F_134 ( struct V_142 * V_3 , struct V_148 * V_145 ,
struct V_46 * V_46 V_149 ,
int line V_149 ,
int * T_6 V_149 )
{
struct V_177 * V_178 ;
T_1 V_53 = V_3 -> V_150 ;
V_178 = F_107 ( V_3 , struct V_177 , V_145 ) ;
if ( ! V_53 )
V_53 = F_132 ( V_178 ) ;
return F_54 ( V_145 -> V_135 , V_145 -> V_2 , L_27 , V_53 , V_53 , V_178 -> V_181 -> V_47 ) ;
}
static int F_135 ( struct V_142 * V_3 ,
struct V_148 * V_145 V_149 ,
struct V_46 * V_46 V_149 )
{
struct V_177 * V_178 ;
T_1 V_53 = V_3 -> V_150 ;
V_178 = F_107 ( V_3 , struct V_177 , V_145 ) ;
if ( ! V_53 )
V_53 = F_132 ( V_178 ) ;
return V_53 ;
}
bool F_136 ( struct V_142 * V_3 , struct V_46 * V_46 )
{
struct V_177 * V_178 ;
V_178 = F_107 ( V_3 , struct V_177 , V_145 ) ;
return F_48 ( V_46 ) == V_178 -> V_76 ;
}
static int F_137 ( struct V_142 * V_3 , struct V_148 * V_145 ,
struct V_11 * V_16 )
{
struct V_177 * V_178 ;
T_1 V_53 = V_3 -> V_150 ;
char * V_130 , * V_184 ;
struct V_185 * V_181 ;
T_1 V_180 ;
bool V_186 = false ;
int V_43 ;
V_178 = F_107 ( V_3 , struct V_177 , V_145 ) ;
if ( ! V_53 )
V_53 = F_132 ( V_178 ) ;
if ( V_178 -> V_82 )
goto V_187;
if ( ! V_16 -> V_87 )
V_16 -> V_87 = F_47 ( V_16 ) ;
V_181 = V_178 -> V_181 ;
V_180 = strlen ( V_181 -> V_47 ) ;
V_130 = V_16 -> V_87 ;
while ( V_130 ) {
V_184 = strchr ( V_130 , ' ' ) ;
if ( V_184 == NULL ) {
V_186 = true ;
V_184 = V_130 + strlen ( V_130 ) ;
}
if ( ! strncmp ( V_130 , V_181 -> V_47 , V_180 ) ) {
V_130 += V_180 + 1 ;
V_130 = F_138 ( V_130 , V_184 - V_130 ) ;
if ( V_130 == NULL )
return F_54 ( V_145 -> V_135 , V_145 -> V_2 ,
L_27 , V_53 , V_53 , L_28 ) ;
break;
}
if ( V_186 )
V_130 = NULL ;
else
V_130 = V_184 + 1 ;
}
if ( V_130 == NULL ) {
struct V_73 V_74 ;
V_187:
F_49 ( & V_74 ) ;
F_139 ( & V_74 , V_16 -> V_80 , V_178 -> V_181 ) ;
V_130 = V_74 . V_84 ;
}
V_43 = F_54 ( V_145 -> V_135 , V_145 -> V_2 , L_27 , V_53 , V_53 , V_130 ) ;
free ( V_130 ) ;
return V_43 ;
}
static T_3 F_140 ( struct V_142 * V_3 ,
struct V_11 * V_152 , struct V_11 * V_153 )
{
struct V_177 * V_178 ;
struct V_185 * V_181 ;
unsigned V_188 , V_2 ;
V_178 = F_107 ( V_3 , struct V_177 , V_145 ) ;
if ( V_153 == NULL ) {
F_133 ( V_178 , V_152 ) ;
return 0 ;
}
V_181 = V_178 -> V_181 ;
if ( V_181 -> V_95 & V_189 ) {
unsigned long long V_190 ;
F_141 ( V_181 , V_152 -> V_80 , & V_190 ) ;
V_188 = V_190 & 0xffff ;
V_2 = ( V_190 >> 16 ) & 0xffff ;
if ( V_2 > V_178 -> V_179 )
V_178 -> V_179 = V_2 ;
} else {
V_188 = V_181 -> V_188 ;
V_2 = V_181 -> V_2 ;
}
return memcmp ( V_152 -> V_80 + V_188 , V_153 -> V_80 + V_188 , V_2 ) ;
}
bool F_142 ( struct V_142 * V_3 )
{
return V_3 -> V_166 == F_140 ;
}
static bool F_143 ( struct V_142 * V_152 , struct V_142 * V_153 )
{
struct V_177 * V_191 ;
struct V_177 * V_192 ;
if ( ! F_142 ( V_152 ) || ! F_142 ( V_153 ) )
return false ;
V_191 = F_107 ( V_152 , struct V_177 , V_145 ) ;
V_192 = F_107 ( V_153 , struct V_177 , V_145 ) ;
return V_191 -> V_181 == V_192 -> V_181 ;
}
static void F_144 ( struct V_142 * V_3 )
{
struct V_177 * V_178 ;
V_178 = F_107 ( V_3 , struct V_177 , V_145 ) ;
free ( V_178 ) ;
}
static struct V_177 *
F_145 ( struct V_75 * V_76 , struct V_185 * V_181 ,
int V_48 )
{
struct V_177 * V_178 ;
V_178 = malloc ( sizeof( * V_178 ) ) ;
if ( V_178 == NULL ) {
F_146 ( L_26 ) ;
return NULL ;
}
V_178 -> V_76 = V_76 ;
V_178 -> V_181 = V_181 ;
V_178 -> V_179 = 0 ;
V_178 -> V_145 . V_47 = V_181 -> V_47 ;
V_178 -> V_145 . V_158 = F_134 ;
V_178 -> V_145 . V_17 = F_135 ;
V_178 -> V_145 . V_163 = F_137 ;
V_178 -> V_145 . V_165 = NULL ;
V_178 -> V_145 . V_166 = F_140 ;
V_178 -> V_145 . V_167 = F_140 ;
V_178 -> V_145 . V_168 = F_140 ;
V_178 -> V_145 . V_169 = F_143 ;
V_178 -> V_145 . free = F_144 ;
F_122 ( & V_178 -> V_145 . V_170 ) ;
F_122 ( & V_178 -> V_145 . V_171 ) ;
V_178 -> V_145 . V_172 = false ;
V_178 -> V_145 . V_53 = 0 ;
V_178 -> V_145 . V_150 = 0 ;
V_178 -> V_145 . V_48 = V_48 ;
return V_178 ;
}
struct V_142 * F_147 ( struct V_142 * V_3 )
{
struct V_142 * V_193 = NULL ;
if ( F_106 ( V_3 ) ) {
struct V_143 * V_144 , * V_194 ;
V_144 = F_107 ( V_3 , struct V_143 , V_145 ) ;
V_194 = F_125 ( V_144 , sizeof( * V_144 ) ) ;
if ( V_194 )
V_193 = & V_194 -> V_145 ;
} else if ( F_142 ( V_3 ) ) {
struct V_177 * V_178 , * V_195 ;
V_178 = F_107 ( V_3 , struct V_177 , V_145 ) ;
V_195 = F_125 ( V_178 , sizeof( * V_178 ) ) ;
if ( V_195 )
V_193 = & V_195 -> V_145 ;
} else {
V_193 = F_125 ( V_3 , sizeof( * V_3 ) ) ;
}
F_122 ( & V_193 -> V_170 ) ;
F_122 ( & V_193 -> V_171 ) ;
return V_193 ;
}
static int F_148 ( char * V_130 , char * * V_196 , char * * V_181 , char * * V_197 )
{
char * V_198 , * V_199 , * V_200 ;
V_198 = V_130 ;
V_199 = strchr ( V_130 , '.' ) ;
if ( V_199 ) {
* V_199 ++ = '\0' ;
} else {
V_198 = NULL ;
V_199 = V_130 ;
}
V_200 = strchr ( V_199 , '/' ) ;
if ( V_200 )
* V_200 ++ = '\0' ;
* V_196 = V_198 ;
* V_181 = V_199 ;
* V_197 = V_200 ;
return 0 ;
}
static struct V_75 * F_149 ( struct V_201 * V_202 , char * V_198 )
{
struct V_75 * V_76 = NULL ;
struct V_75 * V_184 ;
bool V_203 ;
if ( V_198 [ 0 ] == '%' ) {
int V_204 = strtol ( V_198 + 1 , NULL , 0 ) ;
if ( V_204 > V_202 -> V_205 )
return NULL ;
V_76 = F_150 ( V_202 ) ;
while ( -- V_204 > 0 )
V_76 = F_151 ( V_76 ) ;
return V_76 ;
}
V_203 = ! ! strchr ( V_198 , ':' ) ;
F_152 (evlist, pos) {
if ( V_203 && ! strcmp ( V_184 -> V_47 , V_198 ) )
return V_184 ;
if ( ! V_203 && strstr ( V_184 -> V_47 , V_198 ) ) {
if ( V_76 ) {
F_146 ( L_29 ,
V_198 , V_76 -> V_47 , V_184 -> V_47 ) ;
return NULL ;
}
V_76 = V_184 ;
}
}
return V_76 ;
}
static int F_153 ( struct V_75 * V_76 ,
struct V_185 * V_181 ,
bool V_82 , int V_48 )
{
struct V_177 * V_178 ;
V_178 = F_145 ( V_76 , V_181 , V_48 ) ;
if ( V_178 == NULL )
return - V_206 ;
V_178 -> V_82 = V_82 ;
F_154 ( & V_178 -> V_145 ) ;
return 0 ;
}
static int F_155 ( struct V_75 * V_76 , bool V_82 , int V_48 )
{
int V_43 ;
struct V_185 * V_181 ;
V_181 = V_76 -> V_83 -> V_157 . V_207 ;
while ( V_181 ) {
V_43 = F_153 ( V_76 , V_181 , V_82 , V_48 ) ;
if ( V_43 < 0 )
return V_43 ;
V_181 = V_181 -> V_208 ;
}
return 0 ;
}
static int F_156 ( struct V_201 * V_202 , bool V_82 ,
int V_48 )
{
int V_43 ;
struct V_75 * V_76 ;
F_152 (evlist, evsel) {
if ( V_76 -> V_85 . type != V_86 )
continue;
V_43 = F_155 ( V_76 , V_82 , V_48 ) ;
if ( V_43 < 0 )
return V_43 ;
}
return 0 ;
}
static int F_157 ( struct V_201 * V_202 ,
char * V_199 , bool V_82 , int V_48 )
{
int V_43 = - V_209 ;
struct V_75 * V_76 ;
struct V_185 * V_181 ;
F_152 (evlist, evsel) {
if ( V_76 -> V_85 . type != V_86 )
continue;
V_181 = F_158 ( V_76 -> V_83 , V_199 ) ;
if ( V_181 == NULL )
continue;
V_43 = F_153 ( V_76 , V_181 , V_82 , V_48 ) ;
if ( V_43 < 0 )
break;
}
return V_43 ;
}
static int F_159 ( struct V_201 * V_202 , const char * V_210 ,
int V_48 )
{
char * V_130 , * V_198 , * V_199 , * V_200 ;
struct V_75 * V_76 ;
struct V_185 * V_181 ;
bool V_82 = V_6 . V_82 ;
int V_43 = 0 ;
if ( V_202 == NULL )
return - V_211 ;
V_130 = F_160 ( V_210 ) ;
if ( V_130 == NULL )
return - V_206 ;
if ( F_148 ( V_130 , & V_198 , & V_199 , & V_200 ) < 0 ) {
V_43 = - V_212 ;
goto V_98;
}
if ( V_200 ) {
if ( strcmp ( V_200 , L_30 ) ) {
F_146 ( L_31 , V_200 ) ;
V_43 = - V_212 ;
goto V_98;
}
V_82 = true ;
}
if ( ! strcmp ( V_199 , L_32 ) ) {
V_43 = F_156 ( V_202 , V_82 , V_48 ) ;
goto V_98;
}
if ( V_198 == NULL ) {
V_43 = F_157 ( V_202 , V_199 , V_82 , V_48 ) ;
goto V_98;
}
V_76 = F_149 ( V_202 , V_198 ) ;
if ( V_76 == NULL ) {
F_146 ( L_33 , V_198 ) ;
V_43 = - V_211 ;
goto V_98;
}
if ( V_76 -> V_85 . type != V_86 ) {
F_146 ( L_34 , V_198 ) ;
V_43 = - V_212 ;
goto V_98;
}
if ( ! strcmp ( V_199 , L_35 ) ) {
V_43 = F_155 ( V_76 , V_82 , V_48 ) ;
} else {
V_181 = F_158 ( V_76 -> V_83 , V_199 ) ;
if ( V_181 == NULL ) {
F_146 ( L_36 ,
V_198 , V_199 ) ;
return - V_211 ;
}
V_43 = F_153 ( V_76 , V_181 , V_82 , V_48 ) ;
}
V_98:
free ( V_130 ) ;
return V_43 ;
}
static int F_161 ( struct V_161 * V_162 ,
struct V_176 * V_170 ,
int V_48 )
{
if ( V_162 -> V_213 )
return 0 ;
if ( F_128 ( V_162 , V_170 , V_48 ) < 0 )
return - 1 ;
if ( V_162 -> V_163 -> V_155 )
V_170 -> V_214 = 1 ;
V_162 -> V_213 = 1 ;
return 0 ;
}
static int F_162 ( struct V_173 * V_174 ,
struct V_176 * V_170 ,
int V_48 )
{
struct V_142 * V_3 ;
if ( V_174 -> V_213 )
return 0 ;
V_3 = F_124 ( V_174 , V_48 ) ;
if ( ! V_3 )
return - 1 ;
V_174 -> V_213 = 1 ;
F_129 ( V_170 , V_3 ) ;
return 0 ;
}
static int F_163 ( struct V_176 * V_170 ,
struct V_161 * V_162 )
{
if ( V_162 -> V_213 )
return 0 ;
if ( F_130 ( V_162 , V_170 ) < 0 )
return - 1 ;
V_162 -> V_213 = 1 ;
return 0 ;
}
static int F_164 ( struct V_176 * V_170 ,
struct V_173 * V_174 )
{
struct V_142 * V_3 ;
if ( V_174 -> V_213 )
return 0 ;
V_3 = F_124 ( V_174 , 0 ) ;
if ( ! V_3 )
return - 1 ;
V_174 -> V_213 = 1 ;
F_131 ( V_170 , V_3 ) ;
return 0 ;
}
int F_165 ( unsigned V_215 )
{
F_166 ( V_215 >= V_216 ) ;
return F_164 ( & V_176 , & V_217 [ V_215 ] ) ;
}
int F_167 ( struct V_176 * V_170 , const char * V_210 ,
struct V_201 * V_202 ,
int V_48 )
{
unsigned int V_131 ;
for ( V_131 = 0 ; V_131 < F_168 ( V_218 ) ; V_131 ++ ) {
struct V_161 * V_162 = & V_218 [ V_131 ] ;
if ( strncasecmp ( V_210 , V_162 -> V_47 , strlen ( V_210 ) ) )
continue;
if ( V_162 -> V_163 == & V_219 ) {
int V_43 = regcomp ( & V_220 , V_221 , V_222 ) ;
if ( V_43 ) {
char V_223 [ V_224 ] ;
regerror ( V_43 , & V_220 , V_223 , sizeof( V_223 ) ) ;
F_121 ( L_37 , V_221 , V_223 ) ;
return - V_212 ;
}
V_170 -> V_68 = 1 ;
} else if ( V_162 -> V_163 == & V_225 ) {
V_170 -> V_44 = 1 ;
if ( V_226 == V_227 )
V_162 -> V_163 -> V_155 = F_22 ;
} else if ( V_162 -> V_163 == & V_228 ) {
V_170 -> V_25 = 1 ;
} else if ( V_162 -> V_163 == & V_229 ) {
V_170 -> V_70 = 1 ;
} else if ( V_162 -> V_163 == & V_230 ) {
V_170 -> V_14 = 1 ;
} else if ( V_162 -> V_163 == & V_231 ) {
V_170 -> V_18 = 1 ;
}
return F_161 ( V_162 , V_170 , V_48 ) ;
}
for ( V_131 = 0 ; V_131 < F_168 ( V_217 ) ; V_131 ++ ) {
struct V_173 * V_174 = & V_217 [ V_131 ] ;
if ( strncasecmp ( V_210 , V_174 -> V_47 , strlen ( V_210 ) ) )
continue;
return F_162 ( V_174 , V_170 , V_48 ) ;
}
for ( V_131 = 0 ; V_131 < F_168 ( V_232 ) ; V_131 ++ ) {
struct V_161 * V_162 = & V_232 [ V_131 ] ;
if ( strncasecmp ( V_210 , V_162 -> V_47 , strlen ( V_210 ) ) )
continue;
if ( V_226 != V_233 )
return - V_212 ;
if ( V_162 -> V_163 == & V_234 || V_162 -> V_163 == & V_235 )
V_170 -> V_44 = 1 ;
F_161 ( V_162 , V_170 , V_48 ) ;
return 0 ;
}
for ( V_131 = 0 ; V_131 < F_168 ( V_236 ) ; V_131 ++ ) {
struct V_161 * V_162 = & V_236 [ V_131 ] ;
if ( strncasecmp ( V_210 , V_162 -> V_47 , strlen ( V_210 ) ) )
continue;
if ( V_226 != V_237 )
return - V_212 ;
if ( V_162 -> V_163 == & V_238 && V_239 == 0 )
return - V_212 ;
if ( V_162 -> V_163 == & V_240 )
V_170 -> V_44 = 1 ;
F_161 ( V_162 , V_170 , V_48 ) ;
return 0 ;
}
if ( ! F_159 ( V_202 , V_210 , V_48 ) )
return 0 ;
return - V_209 ;
}
static int F_169 ( struct V_176 * V_170 , char * V_130 ,
struct V_201 * V_202 )
{
char * V_241 , * V_210 ;
int V_43 = 0 ;
int V_48 = 0 ;
int V_242 = 1 ;
bool V_243 = false ;
do {
V_210 = V_130 ;
V_241 = strpbrk ( V_130 , L_38 ) ;
if ( V_241 ) {
if ( V_243 )
V_242 = V_48 ;
else
V_242 = V_48 + 1 ;
if ( * V_241 == '{' )
V_243 = true ;
else if ( * V_241 == '}' )
V_243 = false ;
* V_241 = '\0' ;
V_130 = V_241 + 1 ;
}
if ( * V_210 ) {
V_43 = F_167 ( V_170 , V_210 , V_202 , V_48 ) ;
if ( V_43 == - V_212 ) {
if ( ! V_239 && ! strncasecmp ( V_210 , L_39 , strlen ( V_210 ) ) )
error ( L_40 ) ;
else
error ( L_41 , V_210 ) ;
break;
} else if ( V_43 == - V_209 ) {
error ( L_42 , V_210 ) ;
break;
}
}
V_48 = V_242 ;
} while ( V_241 );
return V_43 ;
}
static const char * F_170 ( struct V_201 * V_202 )
{
const char * V_244 [] = {
V_245 ,
V_246 ,
V_247 ,
V_248 ,
V_249 ,
V_250 ,
} ;
bool V_251 = true ;
struct V_75 * V_76 ;
F_166 ( V_226 >= F_168 ( V_244 ) ) ;
if ( V_202 == NULL )
goto V_252;
F_152 (evlist, evsel) {
if ( V_76 -> V_85 . type != V_86 ) {
V_251 = false ;
break;
}
}
if ( V_251 ) {
V_226 = V_253 ;
if ( V_6 . V_82 )
return L_32 ;
}
V_252:
return V_244 [ V_226 ] ;
}
static int F_171 ( struct V_201 * V_202 )
{
char * V_254 ;
if ( ! V_255 || F_172 ( V_255 ) )
return 0 ;
if ( V_255 [ 1 ] == '\0' ) {
error ( L_43 ) ;
return - V_212 ;
}
if ( F_173 ( & V_254 , L_44 ,
F_170 ( V_202 ) , V_255 + 1 ) < 0 ) {
error ( L_45 ) ;
return - V_206 ;
}
V_255 = V_254 ;
return 0 ;
}
static char * F_174 ( const char * V_256 , char * V_130 )
{
char * V_4 ;
if ( ! V_130 || strstr ( V_130 , V_256 ) )
return V_130 ;
if ( F_173 ( & V_4 , L_44 , V_256 , V_130 ) < 0 )
return NULL ;
free ( V_130 ) ;
return V_4 ;
}
static char * F_175 ( char * V_257 )
{
if ( V_226 == V_227 )
return V_257 ;
V_257 = F_174 ( L_46 , V_257 ) ;
if ( V_6 . V_258 )
V_257 = F_174 ( L_47 , V_257 ) ;
return V_257 ;
}
static int F_176 ( struct V_201 * V_202 )
{
char * V_130 ;
const char * V_259 ;
int V_43 = 0 ;
V_43 = F_171 ( V_202 ) ;
if ( V_43 )
return V_43 ;
V_259 = V_255 ;
if ( V_259 == NULL ) {
if ( F_172 ( V_260 ) ) {
return 0 ;
}
V_259 = F_170 ( V_202 ) ;
}
V_130 = F_160 ( V_259 ) ;
if ( V_130 == NULL ) {
error ( L_48 ) ;
return - V_206 ;
}
if ( ! F_172 ( V_260 ) ) {
V_130 = F_175 ( V_130 ) ;
if ( V_130 == NULL ) {
error ( L_49 ) ;
return - V_206 ;
}
}
V_43 = F_169 ( & V_176 , V_130 , V_202 ) ;
free ( V_130 ) ;
return V_43 ;
}
void F_177 ( int V_261 , bool V_172 )
{
struct V_142 * V_3 ;
struct V_143 * V_144 ;
F_127 (&perf_hpp_list, fmt) {
if ( ! F_106 ( V_3 ) )
continue;
V_144 = F_107 ( V_3 , struct V_143 , V_145 ) ;
if ( V_144 -> V_146 -> V_147 == V_261 ) {
V_3 -> V_172 = V_172 ;
break;
}
}
}
static bool F_178 ( struct V_262 * V_170 , const char * V_263 , T_7 * V_264 )
{
if ( V_170 && F_179 ( V_170 ) == 1 ) {
if ( V_264 != NULL )
fprintf ( V_264 , L_50 , V_263 ,
F_180 ( V_170 , 0 ) -> V_265 ) ;
return true ;
}
return false ;
}
static bool F_181 ( int V_261 , T_7 * V_266 )
{
switch ( V_261 ) {
case V_267 :
return F_178 ( V_6 . V_268 , L_51 , V_266 ) ;
case V_269 :
return F_178 ( V_6 . V_270 , L_52 , V_266 ) ;
case V_271 :
return F_178 ( V_6 . V_272 , L_53 , V_266 ) ;
default:
break;
}
if ( V_226 != V_233 )
return false ;
switch ( V_261 ) {
case V_273 :
return F_178 ( V_6 . V_274 , L_54 , V_266 ) ;
case V_275 :
return F_178 ( V_6 . V_276 , L_55 , V_266 ) ;
case V_277 :
return F_178 ( V_6 . V_278 , L_56 , V_266 ) ;
case V_279 :
return F_178 ( V_6 . V_280 , L_57 , V_266 ) ;
default:
break;
}
return false ;
}
void F_182 ( T_7 * V_266 )
{
struct V_142 * V_3 ;
struct V_143 * V_144 ;
F_127 (&perf_hpp_list, fmt) {
if ( ! F_106 ( V_3 ) )
continue;
V_144 = F_107 ( V_3 , struct V_143 , V_145 ) ;
V_3 -> V_172 = F_181 ( V_144 -> V_146 -> V_147 , V_266 ) ;
}
F_127 (&perf_hpp_list, fmt) {
if ( ! F_106 ( V_3 ) )
continue;
if ( ! V_3 -> V_172 )
return;
}
F_127 (&perf_hpp_list, fmt) {
if ( ! F_106 ( V_3 ) )
continue;
V_3 -> V_172 = false ;
}
}
int F_183 ( struct V_176 * V_170 , char * V_210 )
{
unsigned int V_131 ;
for ( V_131 = 0 ; V_131 < F_168 ( V_218 ) ; V_131 ++ ) {
struct V_161 * V_162 = & V_218 [ V_131 ] ;
if ( strncasecmp ( V_210 , V_162 -> V_47 , strlen ( V_210 ) ) )
continue;
return F_163 ( V_170 , V_162 ) ;
}
for ( V_131 = 0 ; V_131 < F_168 ( V_217 ) ; V_131 ++ ) {
struct V_173 * V_174 = & V_217 [ V_131 ] ;
if ( strncasecmp ( V_210 , V_174 -> V_47 , strlen ( V_210 ) ) )
continue;
return F_164 ( V_170 , V_174 ) ;
}
for ( V_131 = 0 ; V_131 < F_168 ( V_232 ) ; V_131 ++ ) {
struct V_161 * V_162 = & V_232 [ V_131 ] ;
if ( strncasecmp ( V_210 , V_162 -> V_47 , strlen ( V_210 ) ) )
continue;
return F_163 ( V_170 , V_162 ) ;
}
for ( V_131 = 0 ; V_131 < F_168 ( V_236 ) ; V_131 ++ ) {
struct V_161 * V_162 = & V_236 [ V_131 ] ;
if ( strncasecmp ( V_210 , V_162 -> V_47 , strlen ( V_210 ) ) )
continue;
return F_163 ( V_170 , V_162 ) ;
}
return - V_209 ;
}
static int F_184 ( struct V_176 * V_170 , char * V_130 )
{
char * V_241 , * V_210 ;
int V_43 = 0 ;
for ( V_210 = strtok_r ( V_130 , L_58 , & V_241 ) ;
V_210 ; V_210 = strtok_r ( NULL , L_58 , & V_241 ) ) {
V_43 = F_183 ( V_170 , V_210 ) ;
if ( V_43 == - V_212 ) {
error ( L_59 , V_210 ) ;
break;
} else if ( V_43 == - V_209 ) {
error ( L_60 , V_210 ) ;
break;
}
}
return V_43 ;
}
void F_185 ( void )
{
unsigned int V_131 ;
for ( V_131 = 0 ; V_131 < F_168 ( V_218 ) ; V_131 ++ )
V_218 [ V_131 ] . V_213 = 0 ;
for ( V_131 = 0 ; V_131 < F_168 ( V_217 ) ; V_131 ++ )
V_217 [ V_131 ] . V_213 = 0 ;
for ( V_131 = 0 ; V_131 < F_168 ( V_232 ) ; V_131 ++ )
V_232 [ V_131 ] . V_213 = 0 ;
for ( V_131 = 0 ; V_131 < F_168 ( V_236 ) ; V_131 ++ )
V_236 [ V_131 ] . V_213 = 0 ;
}
bool F_172 ( const char * V_281 )
{
return V_281 && ( * V_281 != '+' ) ;
}
static int F_186 ( void )
{
char * V_130 , * V_282 ;
int V_43 = - V_212 ;
if ( V_260 == NULL )
return 0 ;
V_282 = V_130 = F_160 ( V_260 ) ;
if ( V_130 == NULL ) {
error ( L_61 ) ;
return - V_206 ;
}
if ( ! F_172 ( V_260 ) )
V_282 ++ ;
if ( ! strlen ( V_282 ) ) {
error ( L_62 ) ;
goto V_98;
}
V_43 = F_184 ( & V_176 , V_282 ) ;
V_98:
free ( V_130 ) ;
return V_43 ;
}
int F_187 ( struct V_201 * V_202 )
{
int V_223 ;
V_223 = F_176 ( V_202 ) ;
if ( V_223 < 0 )
return V_223 ;
if ( V_221 != V_283 ) {
V_223 = F_167 ( & V_176 , L_63 , V_202 , - 1 ) ;
if ( V_223 < 0 )
return V_223 ;
}
F_185 () ;
if ( V_226 != V_227 )
F_188 () ;
V_223 = F_186 () ;
if ( V_223 < 0 )
return V_223 ;
F_189 ( & V_176 ) ;
F_190 ( & V_176 ) ;
if ( F_191 ( & V_176 , V_202 ) < 0 )
return - 1 ;
return 0 ;
}
void F_192 ( void )
{
V_176 . V_214 = 0 ;
V_176 . V_68 = 0 ;
V_176 . V_44 = 0 ;
V_176 . V_25 = 0 ;
V_260 = NULL ;
V_255 = NULL ;
F_185 () ;
F_193 ( & V_176 ) ;
}
