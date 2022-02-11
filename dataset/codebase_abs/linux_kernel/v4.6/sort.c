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
if ( ! V_46 ) {
V_43 = F_14 ( V_12 , V_13 ) ;
if ( V_43 != 0 )
return V_43 ;
}
return F_19 ( V_12 -> V_33 . V_44 , V_13 -> V_33 . V_44 ) ;
}
static T_3
F_21 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
if ( ! V_12 -> V_33 . V_44 || ! V_13 -> V_33 . V_44 )
return F_2 ( V_12 -> V_33 . V_44 , V_13 -> V_33 . V_44 ) ;
return strcmp ( V_13 -> V_33 . V_44 -> V_47 , V_12 -> V_33 . V_44 -> V_47 ) ;
}
static int F_22 ( struct V_22 * V_22 , struct V_38 * V_44 ,
T_4 V_45 , char V_48 , char * V_1 , T_1 V_2 ,
unsigned int V_17 )
{
T_1 V_43 = 0 ;
if ( V_30 ) {
char V_49 = V_22 ? F_23 ( V_22 -> V_25 ) : '!' ;
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
static int F_24 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
return F_22 ( V_16 -> V_33 . V_22 , V_16 -> V_33 . V_44 , V_16 -> V_45 ,
V_16 -> V_48 , V_1 , V_2 , V_17 ) ;
}
static int F_25 ( struct V_11 * V_16 , int type , const void * V_19 )
{
const char * V_44 = V_19 ;
if ( type != V_54 )
return - 1 ;
return V_44 && ( ! V_16 -> V_33 . V_44 || ! strstr ( V_16 -> V_33 . V_44 -> V_47 , V_44 ) ) ;
}
static char * F_26 ( struct V_11 * V_16 )
{
struct V_22 * V_22 = V_16 -> V_33 . V_22 ;
if ( ! V_22 )
return V_55 ;
return F_27 ( V_22 -> V_25 , F_28 ( V_22 , V_16 -> V_45 ) ,
V_16 -> V_33 . V_44 , true ) ;
}
static T_3
F_29 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
if ( ! V_12 -> V_56 )
V_12 -> V_56 = F_26 ( V_12 ) ;
if ( ! V_13 -> V_56 )
V_13 -> V_56 = F_26 ( V_13 ) ;
return strcmp ( V_13 -> V_56 , V_12 -> V_56 ) ;
}
static int F_30 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
if ( ! V_16 -> V_56 )
V_16 -> V_56 = F_26 ( V_16 ) ;
return F_1 ( V_1 , V_2 , L_11 , V_17 , V_16 -> V_56 ) ;
}
static char * F_31 ( struct V_11 * V_57 )
{
char * V_58 , * V_59 ;
struct V_22 * V_22 = V_57 -> V_33 . V_22 ;
if ( ! V_22 )
return V_60 ;
V_58 = F_32 ( V_22 -> V_25 , F_28 ( V_22 , V_57 -> V_45 ) ,
V_57 -> V_33 . V_44 , false , true ) ;
if ( ! strcmp ( V_58 , V_55 ) )
return V_60 ;
V_59 = strchr ( V_58 , ':' ) ;
if ( V_59 && * V_58 ) {
* V_59 = 0 ;
return V_58 ;
}
free ( V_58 ) ;
return V_60 ;
}
static T_3
F_33 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
if ( ! V_12 -> V_61 )
V_12 -> V_61 = F_31 ( V_12 ) ;
if ( ! V_13 -> V_61 )
V_13 -> V_61 = F_31 ( V_13 ) ;
return strcmp ( V_13 -> V_61 , V_12 -> V_61 ) ;
}
static int F_34 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
if ( ! V_16 -> V_61 )
V_16 -> V_61 = F_31 ( V_16 ) ;
return F_1 ( V_1 , V_2 , L_11 , V_17 , V_16 -> V_61 ) ;
}
static T_3
F_35 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
struct V_38 * V_39 = V_12 -> V_62 ;
struct V_38 * V_40 = V_13 -> V_62 ;
if ( ! V_39 || ! V_40 )
return F_2 ( V_39 , V_40 ) ;
return strcmp ( V_40 -> V_47 , V_39 -> V_47 ) ;
}
static int F_36 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
return F_1 ( V_1 , V_2 , L_3 , V_17 , V_17 ,
V_16 -> V_62 ? V_16 -> V_62 -> V_47 : L_12 ) ;
}
static T_3
F_37 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
return V_13 -> V_63 - V_12 -> V_63 ;
}
static int F_38 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
return F_1 ( V_1 , V_2 , L_13 , V_17 , V_17 , V_16 -> V_63 ) ;
}
static T_3
F_39 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
return V_13 -> V_64 - V_12 -> V_64 ;
}
static int F_40 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
return F_1 ( V_1 , V_2 , L_13 , V_17 , V_17 - 3 , V_16 -> V_64 ) ;
}
static int F_41 ( struct V_11 * V_16 , int type , const void * V_19 )
{
int V_65 = * ( const int * ) V_19 ;
if ( type != V_66 )
return - 1 ;
return V_65 >= 0 && V_16 -> V_64 != V_65 ;
}
static char * F_42 ( struct V_11 * V_16 )
{
struct V_67 V_68 ;
struct V_69 * V_70 ;
struct V_71 V_72 = {
. V_73 = V_16 -> V_74 ,
. V_2 = V_16 -> V_75 ,
} ;
V_70 = F_43 ( V_16 -> V_76 ) ;
F_44 ( & V_68 ) ;
if ( V_6 . V_77 ) {
F_45 ( & V_68 , V_16 -> V_74 , V_16 -> V_75 ,
V_70 -> V_78 ) ;
} else {
F_46 ( & V_68 , V_70 -> V_78 , & V_72 ) ;
}
return V_68 . V_79 ;
}
static T_3
F_47 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
struct V_69 * V_70 ;
V_70 = F_43 ( V_12 -> V_76 ) ;
if ( V_70 -> V_80 . type != V_81 )
return 0 ;
if ( V_12 -> V_82 == NULL )
V_12 -> V_82 = F_42 ( V_12 ) ;
if ( V_13 -> V_82 == NULL )
V_13 -> V_82 = F_42 ( V_13 ) ;
return strcmp ( V_13 -> V_82 , V_12 -> V_82 ) ;
}
static int F_48 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
struct V_69 * V_70 ;
V_70 = F_43 ( V_16 -> V_76 ) ;
if ( V_70 -> V_80 . type != V_81 )
return F_49 ( V_1 , V_2 , L_11 , V_17 , L_14 ) ;
if ( V_16 -> V_82 == NULL )
V_16 -> V_82 = F_42 ( V_16 ) ;
return F_1 ( V_1 , V_2 , L_11 , V_17 , V_16 -> V_82 ) ;
}
static T_3
F_50 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
if ( ! V_12 -> V_83 || ! V_13 -> V_83 )
return F_2 ( V_12 -> V_83 , V_13 -> V_83 ) ;
return F_13 ( V_12 -> V_83 -> V_84 . V_22 ,
V_13 -> V_83 -> V_84 . V_22 ) ;
}
static int F_51 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
if ( V_16 -> V_83 )
return F_15 ( V_16 -> V_83 -> V_84 . V_22 ,
V_1 , V_2 , V_17 ) ;
else
return F_1 ( V_1 , V_2 , L_3 , V_17 , V_17 , L_14 ) ;
}
static int F_52 ( struct V_11 * V_16 , int type ,
const void * V_19 )
{
const struct V_25 * V_25 = V_19 ;
if ( type != V_35 )
return - 1 ;
return V_25 && ( ! V_16 -> V_83 || ! V_16 -> V_83 -> V_84 . V_22 ||
V_16 -> V_83 -> V_84 . V_22 -> V_25 != V_25 ) ;
}
static T_3
F_53 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
if ( ! V_12 -> V_83 || ! V_13 -> V_83 )
return F_2 ( V_12 -> V_83 , V_13 -> V_83 ) ;
return F_13 ( V_12 -> V_83 -> V_85 . V_22 ,
V_13 -> V_83 -> V_85 . V_22 ) ;
}
static int F_54 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
if ( V_16 -> V_83 )
return F_15 ( V_16 -> V_83 -> V_85 . V_22 ,
V_1 , V_2 , V_17 ) ;
else
return F_1 ( V_1 , V_2 , L_3 , V_17 , V_17 , L_14 ) ;
}
static int F_55 ( struct V_11 * V_16 , int type ,
const void * V_19 )
{
const struct V_25 * V_25 = V_19 ;
if ( type != V_35 )
return - 1 ;
return V_25 && ( ! V_16 -> V_83 || ! V_16 -> V_83 -> V_85 . V_22 ||
V_16 -> V_83 -> V_85 . V_22 -> V_25 != V_25 ) ;
}
static T_3
F_56 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
struct V_86 * V_87 = & V_12 -> V_83 -> V_84 ;
struct V_86 * V_88 = & V_13 -> V_83 -> V_84 ;
if ( ! V_12 -> V_83 || ! V_13 -> V_83 )
return F_2 ( V_12 -> V_83 , V_13 -> V_83 ) ;
V_87 = & V_12 -> V_83 -> V_84 ;
V_88 = & V_13 -> V_83 -> V_84 ;
if ( ! V_87 -> V_44 && ! V_88 -> V_44 )
return F_18 ( V_87 -> V_89 , V_88 -> V_89 ) ;
return F_19 ( V_87 -> V_44 , V_88 -> V_44 ) ;
}
static T_3
F_57 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
struct V_86 * V_90 , * V_91 ;
if ( ! V_12 -> V_83 || ! V_13 -> V_83 )
return F_2 ( V_12 -> V_83 , V_13 -> V_83 ) ;
V_90 = & V_12 -> V_83 -> V_85 ;
V_91 = & V_13 -> V_83 -> V_85 ;
if ( ! V_90 -> V_44 && ! V_91 -> V_44 )
return F_18 ( V_90 -> V_89 , V_91 -> V_89 ) ;
return F_19 ( V_90 -> V_44 , V_91 -> V_44 ) ;
}
static int F_58 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
if ( V_16 -> V_83 ) {
struct V_86 * V_84 = & V_16 -> V_83 -> V_84 ;
return F_22 ( V_84 -> V_22 , V_84 -> V_44 , V_84 -> V_89 ,
V_16 -> V_48 , V_1 , V_2 , V_17 ) ;
}
return F_1 ( V_1 , V_2 , L_3 , V_17 , V_17 , L_14 ) ;
}
static int F_59 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
if ( V_16 -> V_83 ) {
struct V_86 * V_85 = & V_16 -> V_83 -> V_85 ;
return F_22 ( V_85 -> V_22 , V_85 -> V_44 , V_85 -> V_89 ,
V_16 -> V_48 , V_1 , V_2 , V_17 ) ;
}
return F_1 ( V_1 , V_2 , L_3 , V_17 , V_17 , L_14 ) ;
}
static int F_60 ( struct V_11 * V_16 , int type ,
const void * V_19 )
{
const char * V_44 = V_19 ;
if ( type != V_54 )
return - 1 ;
return V_44 && ! ( V_16 -> V_83 && V_16 -> V_83 -> V_84 . V_44 &&
strstr ( V_16 -> V_83 -> V_84 . V_44 -> V_47 , V_44 ) ) ;
}
static int F_61 ( struct V_11 * V_16 , int type ,
const void * V_19 )
{
const char * V_44 = V_19 ;
if ( type != V_54 )
return - 1 ;
return V_44 && ! ( V_16 -> V_83 && V_16 -> V_83 -> V_85 . V_44 &&
strstr ( V_16 -> V_83 -> V_85 . V_44 -> V_47 , V_44 ) ) ;
}
static T_3
F_62 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
unsigned char V_92 , V_59 ;
if ( ! V_12 -> V_83 || ! V_13 -> V_83 )
return F_2 ( V_12 -> V_83 , V_13 -> V_83 ) ;
V_92 = V_12 -> V_83 -> V_93 . V_94 != V_13 -> V_83 -> V_93 . V_94 ;
V_59 = V_12 -> V_83 -> V_93 . V_95 != V_13 -> V_83 -> V_93 . V_95 ;
return V_92 || V_59 ;
}
static int F_63 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 ) {
static const char * V_96 = L_14 ;
if ( V_16 -> V_83 ) {
if ( V_16 -> V_83 -> V_93 . V_95 )
V_96 = L_15 ;
else if ( V_16 -> V_83 -> V_93 . V_94 )
V_96 = L_16 ;
}
return F_1 ( V_1 , V_2 , L_3 , V_17 , V_17 , V_96 ) ;
}
static T_3
F_64 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
return V_12 -> V_83 -> V_93 . V_97 -
V_13 -> V_83 -> V_93 . V_97 ;
}
static int F_65 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
if ( V_16 -> V_83 -> V_93 . V_97 == 0 )
return F_1 ( V_1 , V_2 , L_17 , V_17 , L_18 ) ;
return F_1 ( V_1 , V_2 , L_19 , V_17 ,
V_16 -> V_83 -> V_93 . V_97 ) ;
}
static T_3
F_66 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
T_5 V_9 = 0 , V_10 = 0 ;
if ( V_12 -> V_98 )
V_9 = V_12 -> V_98 -> V_99 . V_89 ;
if ( V_13 -> V_98 )
V_10 = V_13 -> V_98 -> V_99 . V_89 ;
return ( T_3 ) ( V_10 - V_9 ) ;
}
static int F_67 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
T_5 V_89 = 0 ;
struct V_22 * V_22 = NULL ;
struct V_38 * V_44 = NULL ;
if ( V_16 -> V_98 ) {
V_89 = V_16 -> V_98 -> V_99 . V_89 ;
V_22 = V_16 -> V_98 -> V_99 . V_22 ;
V_44 = V_16 -> V_98 -> V_99 . V_44 ;
}
return F_22 ( V_22 , V_44 , V_89 , V_16 -> V_48 , V_1 , V_2 ,
V_17 ) ;
}
static T_3
F_68 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
T_5 V_9 = 0 , V_10 = 0 ;
if ( V_12 -> V_98 )
V_9 = V_12 -> V_98 -> V_100 . V_89 ;
if ( V_13 -> V_98 )
V_10 = V_13 -> V_98 -> V_100 . V_89 ;
return ( T_3 ) ( V_10 - V_9 ) ;
}
static int F_69 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
T_5 V_89 = 0 ;
struct V_22 * V_22 = NULL ;
struct V_38 * V_44 = NULL ;
if ( V_16 -> V_98 ) {
V_89 = V_16 -> V_98 -> V_100 . V_89 ;
V_22 = V_16 -> V_98 -> V_100 . V_22 ;
V_44 = V_16 -> V_98 -> V_100 . V_44 ;
}
return F_22 ( V_22 , V_44 , V_89 , V_16 -> V_48 , V_1 , V_2 ,
V_17 ) ;
}
static T_3
F_70 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
struct V_22 * V_23 = NULL ;
struct V_22 * V_24 = NULL ;
if ( V_12 -> V_98 )
V_23 = V_12 -> V_98 -> V_99 . V_22 ;
if ( V_13 -> V_98 )
V_24 = V_13 -> V_98 -> V_99 . V_22 ;
return F_13 ( V_23 , V_24 ) ;
}
static int F_71 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
struct V_22 * V_22 = NULL ;
if ( V_16 -> V_98 )
V_22 = V_16 -> V_98 -> V_99 . V_22 ;
return F_15 ( V_22 , V_1 , V_2 , V_17 ) ;
}
static T_3
F_72 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
union V_101 V_102 ;
union V_101 V_103 ;
if ( V_12 -> V_98 )
V_102 = V_12 -> V_98 -> V_104 ;
else
V_102 . V_105 = V_106 ;
if ( V_13 -> V_98 )
V_103 = V_13 -> V_98 -> V_104 ;
else
V_103 . V_105 = V_106 ;
return ( T_3 ) ( V_103 . V_105 - V_102 . V_105 ) ;
}
static int F_73 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
char V_96 [ 10 ] ;
F_74 ( V_96 , sizeof( V_96 ) , V_16 -> V_98 ) ;
return F_1 ( V_1 , V_2 , L_9 , V_17 , V_96 ) ;
}
static T_3
F_75 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
union V_101 V_102 ;
union V_101 V_103 ;
if ( V_12 -> V_98 )
V_102 = V_12 -> V_98 -> V_104 ;
else
V_102 . V_107 = V_108 ;
if ( V_13 -> V_98 )
V_103 = V_13 -> V_98 -> V_104 ;
else
V_103 . V_107 = V_108 ;
return ( T_3 ) ( V_103 . V_107 - V_102 . V_107 ) ;
}
static int F_76 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
char V_96 [ 64 ] ;
F_77 ( V_96 , sizeof( V_96 ) , V_16 -> V_98 ) ;
return F_1 ( V_1 , V_2 , L_17 , V_17 , V_96 ) ;
}
static T_3
F_78 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
union V_101 V_102 ;
union V_101 V_103 ;
if ( V_12 -> V_98 )
V_102 = V_12 -> V_98 -> V_104 ;
else
V_102 . V_109 = V_110 ;
if ( V_13 -> V_98 )
V_103 = V_13 -> V_98 -> V_104 ;
else
V_103 . V_109 = V_110 ;
return ( T_3 ) ( V_103 . V_109 - V_102 . V_109 ) ;
}
static int F_79 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
char V_96 [ 64 ] ;
F_80 ( V_96 , sizeof( V_96 ) , V_16 -> V_98 ) ;
return F_1 ( V_1 , V_2 , L_17 , V_17 , V_96 ) ;
}
static T_3
F_81 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
union V_101 V_102 ;
union V_101 V_103 ;
if ( V_12 -> V_98 )
V_102 = V_12 -> V_98 -> V_104 ;
else
V_102 . V_111 = V_112 ;
if ( V_13 -> V_98 )
V_103 = V_13 -> V_98 -> V_104 ;
else
V_103 . V_111 = V_112 ;
return ( T_3 ) ( V_103 . V_111 - V_102 . V_111 ) ;
}
static int F_82 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
char V_96 [ 64 ] ;
F_83 ( V_96 , sizeof( V_96 ) , V_16 -> V_98 ) ;
return F_1 ( V_1 , V_2 , L_17 , V_17 , V_96 ) ;
}
static T_3
F_84 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
T_4 V_9 , V_10 ;
struct V_22 * V_113 , * V_114 ;
if ( ! V_12 -> V_98 ) return - 1 ;
if ( ! V_13 -> V_98 ) return 1 ;
if ( V_12 -> V_115 > V_13 -> V_115 ) return - 1 ;
if ( V_12 -> V_115 < V_13 -> V_115 ) return 1 ;
V_113 = V_12 -> V_98 -> V_99 . V_22 ;
V_114 = V_13 -> V_98 -> V_99 . V_22 ;
if ( ! V_113 && ! V_114 )
goto V_89;
if ( ! V_113 ) return - 1 ;
if ( ! V_114 ) return 1 ;
if ( V_113 -> V_116 > V_114 -> V_116 ) return - 1 ;
if ( V_113 -> V_116 < V_114 -> V_116 ) return 1 ;
if ( V_113 -> V_117 > V_114 -> V_117 ) return - 1 ;
if ( V_113 -> V_117 < V_114 -> V_117 ) return 1 ;
if ( V_113 -> V_118 > V_114 -> V_118 ) return - 1 ;
if ( V_113 -> V_118 < V_114 -> V_118 ) return 1 ;
if ( V_113 -> V_119 > V_114 -> V_119 ) return - 1 ;
if ( V_113 -> V_119 < V_114 -> V_119 ) return 1 ;
if ( ( V_12 -> V_115 != V_120 ) &&
( ! ( V_113 -> V_93 & V_121 ) ) &&
! V_113 -> V_116 && ! V_113 -> V_117 && ! V_113 -> V_118 &&
! V_113 -> V_119 ) {
if ( V_12 -> V_14 -> V_122 > V_13 -> V_14 -> V_122 ) return - 1 ;
if ( V_12 -> V_14 -> V_122 < V_13 -> V_14 -> V_122 ) return 1 ;
}
V_89:
V_9 = F_85 ( V_12 -> V_98 -> V_99 . V_123 ) ;
V_10 = F_85 ( V_13 -> V_98 -> V_99 . V_123 ) ;
if ( V_9 > V_10 ) return - 1 ;
if ( V_9 < V_10 ) return 1 ;
return 0 ;
}
static int F_86 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
T_5 V_89 = 0 ;
struct V_22 * V_22 = NULL ;
struct V_38 * V_44 = NULL ;
char V_48 = V_16 -> V_48 ;
if ( V_16 -> V_98 ) {
V_89 = F_85 ( V_16 -> V_98 -> V_99 . V_123 ) ;
V_22 = V_16 -> V_98 -> V_99 . V_22 ;
V_44 = V_16 -> V_98 -> V_99 . V_44 ;
if ( ( V_16 -> V_115 != V_120 ) &&
V_22 && ( V_22 -> type == V_51 ) &&
( V_22 -> V_93 & V_121 ) &&
( V_22 -> V_116 || V_22 -> V_117 || V_22 -> V_118 ||
V_22 -> V_119 ) )
V_48 = 's' ;
else if ( ! V_22 )
V_48 = 'X' ;
}
return F_22 ( V_22 , V_44 , V_89 , V_48 , V_1 , V_2 ,
V_17 ) ;
}
static T_4 F_87 ( struct V_11 * V_16 )
{
return V_16 -> V_124 . V_125 ? V_16 -> V_124 . V_126 / V_16 -> V_124 . V_125 : 0 ;
}
static T_3
F_88 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
return F_87 ( V_12 ) - F_87 ( V_13 ) ;
}
static int F_89 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
return F_1 ( V_1 , V_2 , L_20 , V_17 , F_87 ( V_16 ) ) ;
}
static T_3
F_90 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
return V_12 -> V_124 . V_126 - V_13 -> V_124 . V_126 ;
}
static int F_91 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
return F_1 ( V_1 , V_2 , L_20 , V_17 , V_16 -> V_124 . V_126 ) ;
}
static T_3
F_92 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
if ( ! V_12 -> V_83 || ! V_13 -> V_83 )
return F_2 ( V_12 -> V_83 , V_13 -> V_83 ) ;
return V_12 -> V_83 -> V_93 . abort !=
V_13 -> V_83 -> V_93 . abort ;
}
static int F_93 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
static const char * V_96 = L_14 ;
if ( V_16 -> V_83 ) {
if ( V_16 -> V_83 -> V_93 . abort )
V_96 = L_21 ;
else
V_96 = L_22 ;
}
return F_1 ( V_1 , V_2 , L_17 , V_17 , V_96 ) ;
}
static T_3
F_94 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
if ( ! V_12 -> V_83 || ! V_13 -> V_83 )
return F_2 ( V_12 -> V_83 , V_13 -> V_83 ) ;
return V_12 -> V_83 -> V_93 . V_127 !=
V_13 -> V_83 -> V_93 . V_127 ;
}
static int F_95 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
static const char * V_96 = L_14 ;
if ( V_16 -> V_83 ) {
if ( V_16 -> V_83 -> V_93 . V_127 )
V_96 = L_23 ;
else
V_96 = L_22 ;
}
return F_1 ( V_1 , V_2 , L_17 , V_17 , V_96 ) ;
}
static T_3
F_96 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
return V_12 -> V_128 - V_13 -> V_128 ;
}
static inline char * F_97 ( char * V_59 , const char * V_129 )
{
strcpy ( V_59 , V_129 ) ;
return V_59 + strlen ( V_129 ) ;
}
int F_98 ( void )
{
int V_130 ;
int V_53 = 0 ;
for ( V_130 = 0 ; V_131 [ V_130 ] . V_47 ; V_130 ++ ) {
if ( ! V_131 [ V_130 ] . V_132 )
V_53 += strlen ( V_131 [ V_130 ] . V_47 ) ;
}
V_53 += 4 ;
return V_53 ;
}
static int F_99 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
T_4 V_133 = V_16 -> V_128 ;
char V_134 [ 128 ] ;
char * V_59 = V_134 ;
int V_130 ;
V_134 [ 0 ] = 0 ;
for ( V_130 = 0 ; V_131 [ V_130 ] . V_47 ; V_130 ++ )
if ( V_131 [ V_130 ] . V_135 & V_133 )
V_59 = F_97 ( V_59 , V_131 [ V_130 ] . V_47 ) ;
if ( V_133 && ! ( V_133 & ( V_136 | V_137 ) ) )
V_59 = F_97 ( V_59 , L_24 ) ;
if ( V_133 & V_138 ) {
sprintf ( V_59 , L_25 V_139 ,
( V_133 & V_138 ) >>
V_140 ) ;
V_59 += strlen ( V_59 ) ;
}
return F_1 ( V_1 , V_2 , L_17 , V_17 , V_134 ) ;
}
void F_100 ( struct V_141 * V_3 , struct V_76 * V_76 )
{
struct V_142 * V_143 ;
if ( ! F_101 ( V_3 ) )
return;
V_143 = F_102 ( V_3 , struct V_142 , V_144 ) ;
F_103 ( V_76 , V_143 -> V_145 -> V_146 , strlen ( V_3 -> V_47 ) ) ;
}
static int F_104 ( struct V_141 * V_3 , struct V_147 * V_144 ,
struct V_69 * V_70 )
{
struct V_142 * V_143 ;
T_1 V_53 = V_3 -> V_148 ;
V_143 = F_102 ( V_3 , struct V_142 , V_144 ) ;
if ( ! V_53 )
V_53 = F_105 ( F_106 ( V_70 ) , V_143 -> V_145 -> V_146 ) ;
return F_49 ( V_144 -> V_134 , V_144 -> V_2 , L_3 , V_53 , V_53 , V_3 -> V_47 ) ;
}
static int F_107 ( struct V_141 * V_3 ,
struct V_147 * V_144 V_149 ,
struct V_69 * V_70 )
{
struct V_142 * V_143 ;
T_1 V_53 = V_3 -> V_148 ;
V_143 = F_102 ( V_3 , struct V_142 , V_144 ) ;
if ( ! V_53 )
V_53 = F_105 ( F_106 ( V_70 ) , V_143 -> V_145 -> V_146 ) ;
return V_53 ;
}
static int F_108 ( struct V_141 * V_3 , struct V_147 * V_144 ,
struct V_11 * V_16 )
{
struct V_142 * V_143 ;
T_1 V_53 = V_3 -> V_148 ;
V_143 = F_102 ( V_3 , struct V_142 , V_144 ) ;
if ( ! V_53 )
V_53 = F_105 ( V_16 -> V_76 , V_143 -> V_145 -> V_146 ) ;
return V_143 -> V_145 -> V_150 ( V_16 , V_144 -> V_134 , V_144 -> V_2 , V_53 ) ;
}
static T_3 F_109 ( struct V_141 * V_3 ,
struct V_11 * V_151 , struct V_11 * V_152 )
{
struct V_142 * V_143 ;
V_143 = F_102 ( V_3 , struct V_142 , V_144 ) ;
return V_143 -> V_145 -> V_153 ( V_151 , V_152 ) ;
}
static T_3 F_110 ( struct V_141 * V_3 ,
struct V_11 * V_151 , struct V_11 * V_152 )
{
struct V_142 * V_143 ;
T_3 (* F_111)( struct V_11 * , struct V_11 * );
V_143 = F_102 ( V_3 , struct V_142 , V_144 ) ;
F_111 = V_143 -> V_145 -> V_154 ? : V_143 -> V_145 -> V_153 ;
return F_111 ( V_151 , V_152 ) ;
}
static T_3 F_112 ( struct V_141 * V_3 ,
struct V_11 * V_151 , struct V_11 * V_152 )
{
struct V_142 * V_143 ;
T_3 (* F_113)( struct V_11 * , struct V_11 * );
V_143 = F_102 ( V_3 , struct V_142 , V_144 ) ;
F_113 = V_143 -> V_145 -> V_155 ? : V_143 -> V_145 -> V_153 ;
return F_113 ( V_151 , V_152 ) ;
}
bool F_101 ( struct V_141 * V_156 )
{
return V_156 -> V_157 == F_104 ;
}
static bool F_114 ( struct V_141 * V_151 , struct V_141 * V_152 )
{
struct V_142 * V_158 ;
struct V_142 * V_159 ;
if ( ! F_101 ( V_151 ) || ! F_101 ( V_152 ) )
return false ;
V_158 = F_102 ( V_151 , struct V_142 , V_144 ) ;
V_159 = F_102 ( V_152 , struct V_142 , V_144 ) ;
return V_158 -> V_145 == V_159 -> V_145 ;
}
static void F_115 ( struct V_141 * V_3 )
{
struct V_142 * V_143 ;
V_143 = F_102 ( V_3 , struct V_142 , V_144 ) ;
free ( V_143 ) ;
}
static struct V_142 *
F_116 ( struct V_160 * V_161 , int V_48 )
{
struct V_142 * V_143 ;
V_143 = malloc ( sizeof( * V_143 ) ) ;
if ( V_143 == NULL ) {
F_117 ( L_26 ) ;
return NULL ;
}
V_143 -> V_145 = V_161 -> V_162 ;
V_143 -> V_144 . V_47 = V_161 -> V_162 -> V_163 ;
V_143 -> V_144 . V_157 = F_104 ;
V_143 -> V_144 . V_17 = F_107 ;
V_143 -> V_144 . V_162 = F_108 ;
V_143 -> V_144 . V_164 = NULL ;
V_143 -> V_144 . V_165 = F_109 ;
V_143 -> V_144 . V_166 = F_110 ;
V_143 -> V_144 . V_167 = F_112 ;
V_143 -> V_144 . V_168 = F_114 ;
V_143 -> V_144 . free = F_115 ;
F_118 ( & V_143 -> V_144 . V_169 ) ;
F_118 ( & V_143 -> V_144 . V_170 ) ;
V_143 -> V_144 . V_171 = false ;
V_143 -> V_144 . V_53 = 0 ;
V_143 -> V_144 . V_148 = 0 ;
V_143 -> V_144 . V_48 = V_48 ;
return V_143 ;
}
static void F_119 ( struct V_141 * V_3 )
{
free ( V_3 ) ;
}
static struct V_141 * F_120 ( struct V_172 * V_173 ,
int V_48 )
{
struct V_141 * V_3 ;
V_3 = F_121 ( V_173 -> V_3 , sizeof( * V_3 ) ) ;
if ( V_3 ) {
F_118 ( & V_3 -> V_169 ) ;
F_118 ( & V_3 -> V_170 ) ;
V_3 -> free = F_119 ;
V_3 -> V_48 = V_48 ;
}
return V_3 ;
}
int F_122 ( struct V_11 * V_16 , int type , const void * V_19 )
{
struct V_141 * V_3 ;
struct V_142 * V_143 ;
int V_43 = - 1 ;
int V_10 ;
F_123 (he->hpp_list, fmt) {
if ( ! F_101 ( V_3 ) )
continue;
V_143 = F_102 ( V_3 , struct V_142 , V_144 ) ;
if ( V_143 -> V_145 -> V_174 == NULL )
continue;
V_10 = V_143 -> V_145 -> V_174 ( V_16 , type , V_19 ) ;
if ( V_10 >= 0 ) {
if ( V_43 < 0 )
V_43 = 0 ;
V_43 |= V_10 ;
}
}
return V_43 ;
}
static int F_124 ( struct V_160 * V_161 ,
struct V_175 * V_169 ,
int V_48 )
{
struct V_142 * V_143 = F_116 ( V_161 , V_48 ) ;
if ( V_143 == NULL )
return - 1 ;
F_125 ( V_169 , & V_143 -> V_144 ) ;
return 0 ;
}
static int F_126 ( struct V_160 * V_161 ,
struct V_175 * V_169 )
{
struct V_142 * V_143 = F_116 ( V_161 , 0 ) ;
if ( V_143 == NULL )
return - 1 ;
F_127 ( V_169 , & V_143 -> V_144 ) ;
return 0 ;
}
static int F_128 ( struct V_176 * V_177 )
{
if ( ! V_177 -> V_144 . V_53 ) {
int V_53 = V_177 -> V_178 ;
int V_179 = strlen ( V_177 -> V_180 -> V_47 ) ;
int V_181 = V_177 -> V_180 -> V_2 ;
if ( V_179 > V_53 )
V_53 = V_179 ;
if ( ! ( V_177 -> V_180 -> V_93 & V_182 ) ) {
V_181 = V_177 -> V_180 -> V_2 * 2 + 2 ;
}
if ( V_181 > V_53 )
V_53 = V_181 ;
V_177 -> V_144 . V_53 = V_53 ;
}
return V_177 -> V_144 . V_53 ;
}
static void F_129 ( struct V_176 * V_177 ,
struct V_11 * V_16 )
{
char * V_129 , * V_183 ;
struct V_184 * V_180 = V_177 -> V_180 ;
T_1 V_179 ;
bool V_185 = false ;
if ( V_177 -> V_77 )
return;
if ( ! V_16 -> V_82 )
V_16 -> V_82 = F_42 ( V_16 ) ;
V_179 = strlen ( V_180 -> V_47 ) ;
V_129 = V_16 -> V_82 ;
while ( V_129 ) {
V_183 = strchr ( V_129 , ' ' ) ;
if ( V_183 == NULL ) {
V_185 = true ;
V_183 = V_129 + strlen ( V_129 ) ;
}
if ( ! strncmp ( V_129 , V_180 -> V_47 , V_179 ) ) {
T_1 V_53 ;
V_129 += V_179 + 1 ;
V_53 = V_183 - V_129 ;
if ( V_53 > V_177 -> V_178 )
V_177 -> V_178 = V_53 ;
break;
}
if ( V_185 )
V_129 = NULL ;
else
V_129 = V_183 + 1 ;
}
}
static int F_130 ( struct V_141 * V_3 , struct V_147 * V_144 ,
struct V_69 * V_70 V_149 )
{
struct V_176 * V_177 ;
T_1 V_53 = V_3 -> V_148 ;
V_177 = F_102 ( V_3 , struct V_176 , V_144 ) ;
if ( ! V_53 )
V_53 = F_128 ( V_177 ) ;
return F_49 ( V_144 -> V_134 , V_144 -> V_2 , L_27 , V_53 , V_53 , V_177 -> V_180 -> V_47 ) ;
}
static int F_131 ( struct V_141 * V_3 ,
struct V_147 * V_144 V_149 ,
struct V_69 * V_70 V_149 )
{
struct V_176 * V_177 ;
T_1 V_53 = V_3 -> V_148 ;
V_177 = F_102 ( V_3 , struct V_176 , V_144 ) ;
if ( ! V_53 )
V_53 = F_128 ( V_177 ) ;
return V_53 ;
}
bool F_132 ( struct V_141 * V_3 , struct V_76 * V_76 )
{
struct V_176 * V_177 ;
V_177 = F_102 ( V_3 , struct V_176 , V_144 ) ;
return F_43 ( V_76 ) == V_177 -> V_70 ;
}
static int F_133 ( struct V_141 * V_3 , struct V_147 * V_144 ,
struct V_11 * V_16 )
{
struct V_176 * V_177 ;
T_1 V_53 = V_3 -> V_148 ;
char * V_129 , * V_183 ;
struct V_184 * V_180 ;
T_1 V_179 ;
bool V_185 = false ;
int V_43 ;
V_177 = F_102 ( V_3 , struct V_176 , V_144 ) ;
if ( ! V_53 )
V_53 = F_128 ( V_177 ) ;
if ( V_177 -> V_77 )
goto V_186;
if ( ! V_16 -> V_82 )
V_16 -> V_82 = F_42 ( V_16 ) ;
V_180 = V_177 -> V_180 ;
V_179 = strlen ( V_180 -> V_47 ) ;
V_129 = V_16 -> V_82 ;
while ( V_129 ) {
V_183 = strchr ( V_129 , ' ' ) ;
if ( V_183 == NULL ) {
V_185 = true ;
V_183 = V_129 + strlen ( V_129 ) ;
}
if ( ! strncmp ( V_129 , V_180 -> V_47 , V_179 ) ) {
V_129 += V_179 + 1 ;
V_129 = F_134 ( V_129 , V_183 - V_129 ) ;
if ( V_129 == NULL )
return F_49 ( V_144 -> V_134 , V_144 -> V_2 ,
L_27 , V_53 , V_53 , L_28 ) ;
break;
}
if ( V_185 )
V_129 = NULL ;
else
V_129 = V_183 + 1 ;
}
if ( V_129 == NULL ) {
struct V_67 V_68 ;
V_186:
F_44 ( & V_68 ) ;
F_135 ( & V_68 , V_16 -> V_74 , V_177 -> V_180 ) ;
V_129 = V_68 . V_79 ;
}
V_43 = F_49 ( V_144 -> V_134 , V_144 -> V_2 , L_27 , V_53 , V_53 , V_129 ) ;
free ( V_129 ) ;
return V_43 ;
}
static T_3 F_136 ( struct V_141 * V_3 ,
struct V_11 * V_151 , struct V_11 * V_152 )
{
struct V_176 * V_177 ;
struct V_184 * V_180 ;
unsigned V_187 , V_2 ;
V_177 = F_102 ( V_3 , struct V_176 , V_144 ) ;
if ( V_152 == NULL ) {
F_129 ( V_177 , V_151 ) ;
return 0 ;
}
V_180 = V_177 -> V_180 ;
if ( V_180 -> V_93 & V_188 ) {
unsigned long long V_189 ;
F_137 ( V_180 , V_151 -> V_74 , & V_189 ) ;
V_187 = V_189 & 0xffff ;
V_2 = ( V_189 >> 16 ) & 0xffff ;
if ( V_2 > V_177 -> V_178 )
V_177 -> V_178 = V_2 ;
} else {
V_187 = V_180 -> V_187 ;
V_2 = V_180 -> V_2 ;
}
return memcmp ( V_151 -> V_74 + V_187 , V_152 -> V_74 + V_187 , V_2 ) ;
}
bool F_138 ( struct V_141 * V_3 )
{
return V_3 -> V_165 == F_136 ;
}
static bool F_139 ( struct V_141 * V_151 , struct V_141 * V_152 )
{
struct V_176 * V_190 ;
struct V_176 * V_191 ;
if ( ! F_138 ( V_151 ) || ! F_138 ( V_152 ) )
return false ;
V_190 = F_102 ( V_151 , struct V_176 , V_144 ) ;
V_191 = F_102 ( V_152 , struct V_176 , V_144 ) ;
return V_190 -> V_180 == V_191 -> V_180 ;
}
static void F_140 ( struct V_141 * V_3 )
{
struct V_176 * V_177 ;
V_177 = F_102 ( V_3 , struct V_176 , V_144 ) ;
free ( V_177 ) ;
}
static struct V_176 *
F_141 ( struct V_69 * V_70 , struct V_184 * V_180 ,
int V_48 )
{
struct V_176 * V_177 ;
V_177 = malloc ( sizeof( * V_177 ) ) ;
if ( V_177 == NULL ) {
F_142 ( L_26 ) ;
return NULL ;
}
V_177 -> V_70 = V_70 ;
V_177 -> V_180 = V_180 ;
V_177 -> V_178 = 0 ;
V_177 -> V_144 . V_47 = V_180 -> V_47 ;
V_177 -> V_144 . V_157 = F_130 ;
V_177 -> V_144 . V_17 = F_131 ;
V_177 -> V_144 . V_162 = F_133 ;
V_177 -> V_144 . V_164 = NULL ;
V_177 -> V_144 . V_165 = F_136 ;
V_177 -> V_144 . V_166 = F_136 ;
V_177 -> V_144 . V_167 = F_136 ;
V_177 -> V_144 . V_168 = F_139 ;
V_177 -> V_144 . free = F_140 ;
F_118 ( & V_177 -> V_144 . V_169 ) ;
F_118 ( & V_177 -> V_144 . V_170 ) ;
V_177 -> V_144 . V_171 = false ;
V_177 -> V_144 . V_53 = 0 ;
V_177 -> V_144 . V_148 = 0 ;
V_177 -> V_144 . V_48 = V_48 ;
return V_177 ;
}
struct V_141 * F_143 ( struct V_141 * V_3 )
{
struct V_141 * V_192 = NULL ;
if ( F_101 ( V_3 ) ) {
struct V_142 * V_143 , * V_193 ;
V_143 = F_102 ( V_3 , struct V_142 , V_144 ) ;
V_193 = F_121 ( V_143 , sizeof( * V_143 ) ) ;
if ( V_193 )
V_192 = & V_193 -> V_144 ;
} else if ( F_138 ( V_3 ) ) {
struct V_176 * V_177 , * V_194 ;
V_177 = F_102 ( V_3 , struct V_176 , V_144 ) ;
V_194 = F_121 ( V_177 , sizeof( * V_177 ) ) ;
if ( V_194 )
V_192 = & V_194 -> V_144 ;
} else {
V_192 = F_121 ( V_3 , sizeof( * V_3 ) ) ;
}
F_118 ( & V_192 -> V_169 ) ;
F_118 ( & V_192 -> V_170 ) ;
return V_192 ;
}
static int F_144 ( char * V_129 , char * * V_195 , char * * V_180 , char * * V_196 )
{
char * V_197 , * V_198 , * V_199 ;
V_197 = V_129 ;
V_198 = strchr ( V_129 , '.' ) ;
if ( V_198 ) {
* V_198 ++ = '\0' ;
} else {
V_197 = NULL ;
V_198 = V_129 ;
}
V_199 = strchr ( V_198 , '/' ) ;
if ( V_199 )
* V_199 ++ = '\0' ;
* V_195 = V_197 ;
* V_180 = V_198 ;
* V_196 = V_199 ;
return 0 ;
}
static struct V_69 * F_145 ( struct V_200 * V_201 , char * V_197 )
{
struct V_69 * V_70 = NULL ;
struct V_69 * V_183 ;
bool V_202 ;
if ( V_197 [ 0 ] == '%' ) {
int V_203 = strtol ( V_197 + 1 , NULL , 0 ) ;
if ( V_203 > V_201 -> V_204 )
return NULL ;
V_70 = F_146 ( V_201 ) ;
while ( -- V_203 > 0 )
V_70 = F_147 ( V_70 ) ;
return V_70 ;
}
V_202 = ! ! strchr ( V_197 , ':' ) ;
F_148 (evlist, pos) {
if ( V_202 && ! strcmp ( V_183 -> V_47 , V_197 ) )
return V_183 ;
if ( ! V_202 && strstr ( V_183 -> V_47 , V_197 ) ) {
if ( V_70 ) {
F_142 ( L_29 ,
V_197 , V_70 -> V_47 , V_183 -> V_47 ) ;
return NULL ;
}
V_70 = V_183 ;
}
}
return V_70 ;
}
static int F_149 ( struct V_69 * V_70 ,
struct V_184 * V_180 ,
bool V_77 , int V_48 )
{
struct V_176 * V_177 ;
V_177 = F_141 ( V_70 , V_180 , V_48 ) ;
if ( V_177 == NULL )
return - V_205 ;
V_177 -> V_77 = V_77 ;
F_150 ( & V_177 -> V_144 ) ;
return 0 ;
}
static int F_151 ( struct V_69 * V_70 , bool V_77 , int V_48 )
{
int V_43 ;
struct V_184 * V_180 ;
V_180 = V_70 -> V_78 -> V_156 . V_206 ;
while ( V_180 ) {
V_43 = F_149 ( V_70 , V_180 , V_77 , V_48 ) ;
if ( V_43 < 0 )
return V_43 ;
V_180 = V_180 -> V_207 ;
}
return 0 ;
}
static int F_152 ( struct V_200 * V_201 , bool V_77 ,
int V_48 )
{
int V_43 ;
struct V_69 * V_70 ;
F_148 (evlist, evsel) {
if ( V_70 -> V_80 . type != V_81 )
continue;
V_43 = F_151 ( V_70 , V_77 , V_48 ) ;
if ( V_43 < 0 )
return V_43 ;
}
return 0 ;
}
static int F_153 ( struct V_200 * V_201 ,
char * V_198 , bool V_77 , int V_48 )
{
int V_43 = - V_208 ;
struct V_69 * V_70 ;
struct V_184 * V_180 ;
F_148 (evlist, evsel) {
if ( V_70 -> V_80 . type != V_81 )
continue;
V_180 = F_154 ( V_70 -> V_78 , V_198 ) ;
if ( V_180 == NULL )
continue;
V_43 = F_149 ( V_70 , V_180 , V_77 , V_48 ) ;
if ( V_43 < 0 )
break;
}
return V_43 ;
}
static int F_155 ( struct V_200 * V_201 , const char * V_209 ,
int V_48 )
{
char * V_129 , * V_197 , * V_198 , * V_199 ;
struct V_69 * V_70 ;
struct V_184 * V_180 ;
bool V_77 = V_6 . V_77 ;
int V_43 = 0 ;
if ( V_201 == NULL )
return - V_210 ;
V_129 = F_156 ( V_209 ) ;
if ( V_129 == NULL )
return - V_205 ;
if ( F_144 ( V_129 , & V_197 , & V_198 , & V_199 ) < 0 ) {
V_43 = - V_211 ;
goto V_96;
}
if ( V_199 ) {
if ( strcmp ( V_199 , L_30 ) ) {
F_142 ( L_31 , V_199 ) ;
V_43 = - V_211 ;
goto V_96;
}
V_77 = true ;
}
if ( ! strcmp ( V_198 , L_32 ) ) {
V_43 = F_152 ( V_201 , V_77 , V_48 ) ;
goto V_96;
}
if ( V_197 == NULL ) {
V_43 = F_153 ( V_201 , V_198 , V_77 , V_48 ) ;
goto V_96;
}
V_70 = F_145 ( V_201 , V_197 ) ;
if ( V_70 == NULL ) {
F_142 ( L_33 , V_197 ) ;
V_43 = - V_210 ;
goto V_96;
}
if ( V_70 -> V_80 . type != V_81 ) {
F_142 ( L_34 , V_197 ) ;
V_43 = - V_211 ;
goto V_96;
}
if ( ! strcmp ( V_198 , L_35 ) ) {
V_43 = F_151 ( V_70 , V_77 , V_48 ) ;
} else {
V_180 = F_154 ( V_70 -> V_78 , V_198 ) ;
if ( V_180 == NULL ) {
F_142 ( L_36 ,
V_197 , V_198 ) ;
return - V_210 ;
}
V_43 = F_149 ( V_70 , V_180 , V_77 , V_48 ) ;
}
V_96:
free ( V_129 ) ;
return V_43 ;
}
static int F_157 ( struct V_160 * V_161 ,
struct V_175 * V_169 ,
int V_48 )
{
if ( V_161 -> V_212 )
return 0 ;
if ( F_124 ( V_161 , V_169 , V_48 ) < 0 )
return - 1 ;
if ( V_161 -> V_162 -> V_154 )
V_213 = 1 ;
V_161 -> V_212 = 1 ;
return 0 ;
}
static int F_158 ( struct V_172 * V_173 ,
struct V_175 * V_169 ,
int V_48 )
{
struct V_141 * V_3 ;
if ( V_173 -> V_212 )
return 0 ;
V_3 = F_120 ( V_173 , V_48 ) ;
if ( ! V_3 )
return - 1 ;
V_173 -> V_212 = 1 ;
F_125 ( V_169 , V_3 ) ;
return 0 ;
}
static int F_159 ( struct V_175 * V_169 ,
struct V_160 * V_161 )
{
if ( V_161 -> V_212 )
return 0 ;
if ( F_126 ( V_161 , V_169 ) < 0 )
return - 1 ;
V_161 -> V_212 = 1 ;
return 0 ;
}
static int F_160 ( struct V_175 * V_169 ,
struct V_172 * V_173 )
{
struct V_141 * V_3 ;
if ( V_173 -> V_212 )
return 0 ;
V_3 = F_120 ( V_173 , 0 ) ;
if ( ! V_3 )
return - 1 ;
V_173 -> V_212 = 1 ;
F_127 ( V_169 , V_3 ) ;
return 0 ;
}
int F_161 ( unsigned V_214 )
{
F_162 ( V_214 >= V_215 ) ;
return F_160 ( & V_175 , & V_216 [ V_214 ] ) ;
}
static int F_163 ( struct V_175 * V_169 , const char * V_209 ,
struct V_200 * V_201 ,
int V_48 )
{
unsigned int V_130 ;
for ( V_130 = 0 ; V_130 < F_164 ( V_217 ) ; V_130 ++ ) {
struct V_160 * V_161 = & V_217 [ V_130 ] ;
if ( strncasecmp ( V_209 , V_161 -> V_47 , strlen ( V_209 ) ) )
continue;
if ( V_161 -> V_162 == & V_218 ) {
int V_43 = regcomp ( & V_219 , V_220 , V_221 ) ;
if ( V_43 ) {
char V_222 [ V_223 ] ;
regerror ( V_43 , & V_219 , V_222 , sizeof( V_222 ) ) ;
F_117 ( L_37 , V_220 , V_222 ) ;
return - V_211 ;
}
V_224 = 1 ;
} else if ( V_161 -> V_162 == & V_225 ) {
V_226 = 1 ;
if ( V_227 == V_228 )
V_161 -> V_162 -> V_154 = F_21 ;
} else if ( V_161 -> V_162 == & V_229 ) {
V_46 = 1 ;
} else if ( V_161 -> V_162 == & V_230 ) {
V_231 = 1 ;
} else if ( V_161 -> V_162 == & V_232 ) {
V_233 = 1 ;
} else if ( V_161 -> V_162 == & V_234 ) {
V_235 = 1 ;
}
return F_157 ( V_161 , V_169 , V_48 ) ;
}
for ( V_130 = 0 ; V_130 < F_164 ( V_216 ) ; V_130 ++ ) {
struct V_172 * V_173 = & V_216 [ V_130 ] ;
if ( strncasecmp ( V_209 , V_173 -> V_47 , strlen ( V_209 ) ) )
continue;
return F_158 ( V_173 , V_169 , V_48 ) ;
}
for ( V_130 = 0 ; V_130 < F_164 ( V_236 ) ; V_130 ++ ) {
struct V_160 * V_161 = & V_236 [ V_130 ] ;
if ( strncasecmp ( V_209 , V_161 -> V_47 , strlen ( V_209 ) ) )
continue;
if ( V_227 != V_237 )
return - V_211 ;
if ( V_161 -> V_162 == & V_238 || V_161 -> V_162 == & V_239 )
V_226 = 1 ;
F_157 ( V_161 , V_169 , V_48 ) ;
return 0 ;
}
for ( V_130 = 0 ; V_130 < F_164 ( V_240 ) ; V_130 ++ ) {
struct V_160 * V_161 = & V_240 [ V_130 ] ;
if ( strncasecmp ( V_209 , V_161 -> V_47 , strlen ( V_209 ) ) )
continue;
if ( V_227 != V_241 )
return - V_211 ;
if ( V_161 -> V_162 == & V_242 )
V_226 = 1 ;
F_157 ( V_161 , V_169 , V_48 ) ;
return 0 ;
}
if ( ! F_155 ( V_201 , V_209 , V_48 ) )
return 0 ;
return - V_208 ;
}
static int F_165 ( struct V_175 * V_169 , char * V_129 ,
struct V_200 * V_201 )
{
char * V_243 , * V_209 ;
int V_43 = 0 ;
int V_48 = 0 ;
int V_244 = 1 ;
bool V_245 = false ;
do {
V_209 = V_129 ;
V_243 = strpbrk ( V_129 , L_38 ) ;
if ( V_243 ) {
if ( V_245 )
V_244 = V_48 ;
else
V_244 = V_48 + 1 ;
if ( * V_243 == '{' )
V_245 = true ;
else if ( * V_243 == '}' )
V_245 = false ;
* V_243 = '\0' ;
V_129 = V_243 + 1 ;
}
if ( * V_209 ) {
V_43 = F_163 ( V_169 , V_209 , V_201 , V_48 ) ;
if ( V_43 == - V_211 ) {
error ( L_39 , V_209 ) ;
break;
} else if ( V_43 == - V_208 ) {
error ( L_40 , V_209 ) ;
break;
}
}
V_48 = V_244 ;
} while ( V_243 );
return V_43 ;
}
static const char * F_166 ( struct V_200 * V_201 )
{
const char * V_246 [] = {
V_247 ,
V_248 ,
V_249 ,
V_250 ,
V_251 ,
V_252 ,
} ;
bool V_253 = true ;
struct V_69 * V_70 ;
F_162 ( V_227 >= F_164 ( V_246 ) ) ;
if ( V_201 == NULL )
goto V_254;
F_148 (evlist, evsel) {
if ( V_70 -> V_80 . type != V_81 ) {
V_253 = false ;
break;
}
}
if ( V_253 ) {
V_227 = V_255 ;
if ( V_6 . V_77 )
return L_32 ;
}
V_254:
return V_246 [ V_227 ] ;
}
static int F_167 ( struct V_200 * V_201 )
{
char * V_256 ;
if ( ! V_257 || F_168 ( V_257 ) )
return 0 ;
if ( V_257 [ 1 ] == '\0' ) {
error ( L_41 ) ;
return - V_211 ;
}
if ( F_169 ( & V_256 , L_42 ,
F_166 ( V_201 ) , V_257 + 1 ) < 0 ) {
error ( L_43 ) ;
return - V_205 ;
}
V_257 = V_256 ;
return 0 ;
}
static char * F_170 ( const char * V_258 , char * V_129 )
{
char * V_4 ;
if ( ! V_129 || strstr ( V_129 , V_258 ) )
return V_129 ;
if ( F_169 ( & V_4 , L_42 , V_258 , V_129 ) < 0 )
return NULL ;
free ( V_129 ) ;
return V_4 ;
}
static char * F_171 ( char * V_259 )
{
if ( V_227 == V_228 )
return V_259 ;
V_259 = F_170 ( L_44 , V_259 ) ;
if ( V_6 . V_260 )
V_259 = F_170 ( L_45 , V_259 ) ;
return V_259 ;
}
static int F_172 ( struct V_200 * V_201 )
{
char * V_129 ;
const char * V_261 ;
int V_43 = 0 ;
V_43 = F_167 ( V_201 ) ;
if ( V_43 )
return V_43 ;
V_261 = V_257 ;
if ( V_261 == NULL ) {
if ( F_168 ( V_262 ) ) {
return 0 ;
}
V_261 = F_166 ( V_201 ) ;
}
V_129 = F_156 ( V_261 ) ;
if ( V_129 == NULL ) {
error ( L_46 ) ;
return - V_205 ;
}
if ( ! F_168 ( V_262 ) ) {
V_129 = F_171 ( V_129 ) ;
if ( V_129 == NULL ) {
error ( L_47 ) ;
return - V_205 ;
}
}
V_43 = F_165 ( & V_175 , V_129 , V_201 ) ;
free ( V_129 ) ;
return V_43 ;
}
void F_173 ( int V_263 , bool V_171 )
{
struct V_141 * V_3 ;
struct V_142 * V_143 ;
F_123 (&perf_hpp_list, fmt) {
if ( ! F_101 ( V_3 ) )
continue;
V_143 = F_102 ( V_3 , struct V_142 , V_144 ) ;
if ( V_143 -> V_145 -> V_146 == V_263 ) {
V_3 -> V_171 = V_171 ;
break;
}
}
}
static bool F_174 ( struct V_264 * V_169 , const char * V_265 , T_6 * V_266 )
{
if ( V_169 && F_175 ( V_169 ) == 1 ) {
if ( V_266 != NULL )
fprintf ( V_266 , L_48 , V_265 ,
F_176 ( V_169 , 0 ) -> V_267 ) ;
return true ;
}
return false ;
}
static bool F_177 ( int V_263 , T_6 * V_268 )
{
switch ( V_263 ) {
case V_269 :
return F_174 ( V_6 . V_270 , L_49 , V_268 ) ;
case V_271 :
return F_174 ( V_6 . V_272 , L_50 , V_268 ) ;
case V_273 :
return F_174 ( V_6 . V_274 , L_51 , V_268 ) ;
default:
break;
}
if ( V_227 != V_237 )
return false ;
switch ( V_263 ) {
case V_275 :
return F_174 ( V_6 . V_276 , L_52 , V_268 ) ;
case V_277 :
return F_174 ( V_6 . V_278 , L_53 , V_268 ) ;
case V_279 :
return F_174 ( V_6 . V_280 , L_54 , V_268 ) ;
case V_281 :
return F_174 ( V_6 . V_282 , L_55 , V_268 ) ;
default:
break;
}
return false ;
}
void F_178 ( T_6 * V_268 )
{
struct V_141 * V_3 ;
struct V_142 * V_143 ;
F_123 (&perf_hpp_list, fmt) {
if ( ! F_101 ( V_3 ) )
continue;
V_143 = F_102 ( V_3 , struct V_142 , V_144 ) ;
V_3 -> V_171 = F_177 ( V_143 -> V_145 -> V_146 , V_268 ) ;
}
F_123 (&perf_hpp_list, fmt) {
if ( ! F_101 ( V_3 ) )
continue;
if ( ! V_3 -> V_171 )
return;
}
F_123 (&perf_hpp_list, fmt) {
if ( ! F_101 ( V_3 ) )
continue;
V_3 -> V_171 = false ;
}
}
static int F_179 ( struct V_175 * V_169 , char * V_209 )
{
unsigned int V_130 ;
for ( V_130 = 0 ; V_130 < F_164 ( V_217 ) ; V_130 ++ ) {
struct V_160 * V_161 = & V_217 [ V_130 ] ;
if ( strncasecmp ( V_209 , V_161 -> V_47 , strlen ( V_209 ) ) )
continue;
return F_159 ( V_169 , V_161 ) ;
}
for ( V_130 = 0 ; V_130 < F_164 ( V_216 ) ; V_130 ++ ) {
struct V_172 * V_173 = & V_216 [ V_130 ] ;
if ( strncasecmp ( V_209 , V_173 -> V_47 , strlen ( V_209 ) ) )
continue;
return F_160 ( V_169 , V_173 ) ;
}
for ( V_130 = 0 ; V_130 < F_164 ( V_236 ) ; V_130 ++ ) {
struct V_160 * V_161 = & V_236 [ V_130 ] ;
if ( strncasecmp ( V_209 , V_161 -> V_47 , strlen ( V_209 ) ) )
continue;
return F_159 ( V_169 , V_161 ) ;
}
for ( V_130 = 0 ; V_130 < F_164 ( V_240 ) ; V_130 ++ ) {
struct V_160 * V_161 = & V_240 [ V_130 ] ;
if ( strncasecmp ( V_209 , V_161 -> V_47 , strlen ( V_209 ) ) )
continue;
return F_159 ( V_169 , V_161 ) ;
}
return - V_208 ;
}
static int F_180 ( struct V_175 * V_169 , char * V_129 )
{
char * V_243 , * V_209 ;
int V_43 = 0 ;
for ( V_209 = strtok_r ( V_129 , L_56 , & V_243 ) ;
V_209 ; V_209 = strtok_r ( NULL , L_56 , & V_243 ) ) {
V_43 = F_179 ( V_169 , V_209 ) ;
if ( V_43 == - V_211 ) {
error ( L_57 , V_209 ) ;
break;
} else if ( V_43 == - V_208 ) {
error ( L_58 , V_209 ) ;
break;
}
}
return V_43 ;
}
static void F_181 ( void )
{
unsigned int V_130 ;
for ( V_130 = 0 ; V_130 < F_164 ( V_217 ) ; V_130 ++ )
V_217 [ V_130 ] . V_212 = 0 ;
for ( V_130 = 0 ; V_130 < F_164 ( V_216 ) ; V_130 ++ )
V_216 [ V_130 ] . V_212 = 0 ;
for ( V_130 = 0 ; V_130 < F_164 ( V_236 ) ; V_130 ++ )
V_236 [ V_130 ] . V_212 = 0 ;
for ( V_130 = 0 ; V_130 < F_164 ( V_240 ) ; V_130 ++ )
V_240 [ V_130 ] . V_212 = 0 ;
}
bool F_168 ( const char * V_283 )
{
return V_283 && ( * V_283 != '+' ) ;
}
static int F_182 ( void )
{
char * V_129 , * V_284 ;
int V_43 = - V_211 ;
if ( V_262 == NULL )
return 0 ;
V_284 = V_129 = F_156 ( V_262 ) ;
if ( V_129 == NULL ) {
error ( L_59 ) ;
return - V_205 ;
}
if ( ! F_168 ( V_262 ) )
V_284 ++ ;
if ( ! strlen ( V_284 ) ) {
error ( L_60 ) ;
goto V_96;
}
V_43 = F_180 ( & V_175 , V_284 ) ;
V_96:
free ( V_129 ) ;
return V_43 ;
}
int F_183 ( struct V_200 * V_201 )
{
int V_222 ;
V_222 = F_172 ( V_201 ) ;
if ( V_222 < 0 )
return V_222 ;
if ( V_220 != V_285 ) {
V_222 = F_163 ( & V_175 , L_61 , V_201 , - 1 ) ;
if ( V_222 < 0 )
return V_222 ;
}
F_181 () ;
if ( V_227 != V_228 )
F_184 () ;
V_222 = F_182 () ;
if ( V_222 < 0 )
return V_222 ;
F_185 ( & V_175 ) ;
F_186 ( & V_175 ) ;
if ( F_187 ( & V_175 , V_201 ) < 0 )
return - 1 ;
return 0 ;
}
void F_188 ( void )
{
V_213 = 0 ;
V_224 = 0 ;
V_226 = 0 ;
V_46 = 0 ;
V_262 = NULL ;
V_257 = NULL ;
F_181 () ;
F_189 ( & V_175 ) ;
}
