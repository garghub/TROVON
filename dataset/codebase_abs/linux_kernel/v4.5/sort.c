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
static char * F_37 ( struct V_11 * V_16 )
{
struct V_60 V_61 ;
struct V_62 * V_63 ;
struct V_64 V_65 = {
. V_66 = V_16 -> V_67 ,
. V_2 = V_16 -> V_68 ,
} ;
V_63 = F_38 ( V_16 -> V_69 ) ;
F_39 ( & V_61 ) ;
if ( V_6 . V_70 ) {
F_40 ( & V_61 , V_16 -> V_67 , V_16 -> V_68 ,
V_63 -> V_71 ) ;
} else {
F_41 ( & V_61 , V_63 -> V_71 , & V_65 ) ;
}
return V_61 . V_72 ;
}
static T_3
F_42 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
struct V_62 * V_63 ;
V_63 = F_38 ( V_12 -> V_69 ) ;
if ( V_63 -> V_73 . type != V_74 )
return 0 ;
if ( V_12 -> V_75 == NULL )
V_12 -> V_75 = F_37 ( V_12 ) ;
if ( V_13 -> V_75 == NULL )
V_13 -> V_75 = F_37 ( V_13 ) ;
F_43 ( V_12 -> V_69 , V_76 , strlen ( V_12 -> V_75 ) ) ;
F_43 ( V_13 -> V_69 , V_76 , strlen ( V_13 -> V_75 ) ) ;
return strcmp ( V_13 -> V_75 , V_12 -> V_75 ) ;
}
static int F_44 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
struct V_62 * V_63 ;
V_63 = F_38 ( V_16 -> V_69 ) ;
if ( V_63 -> V_73 . type != V_74 )
return F_45 ( V_1 , V_2 , L_3 , V_17 , V_17 , L_13 ) ;
if ( V_16 -> V_75 == NULL )
V_16 -> V_75 = F_37 ( V_16 ) ;
return F_1 ( V_1 , V_2 , L_3 , V_17 , V_17 , V_16 -> V_75 ) ;
}
static T_3
F_46 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
if ( ! V_12 -> V_77 || ! V_13 -> V_77 )
return F_2 ( V_12 -> V_77 , V_13 -> V_77 ) ;
return F_12 ( V_12 -> V_77 -> V_78 . V_19 ,
V_13 -> V_77 -> V_78 . V_19 ) ;
}
static int F_47 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
if ( V_16 -> V_77 )
return F_14 ( V_16 -> V_77 -> V_78 . V_19 ,
V_1 , V_2 , V_17 ) ;
else
return F_1 ( V_1 , V_2 , L_3 , V_17 , V_17 , L_13 ) ;
}
static T_3
F_48 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
if ( ! V_12 -> V_77 || ! V_13 -> V_77 )
return F_2 ( V_12 -> V_77 , V_13 -> V_77 ) ;
return F_12 ( V_12 -> V_77 -> V_79 . V_19 ,
V_13 -> V_77 -> V_79 . V_19 ) ;
}
static int F_49 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
if ( V_16 -> V_77 )
return F_14 ( V_16 -> V_77 -> V_79 . V_19 ,
V_1 , V_2 , V_17 ) ;
else
return F_1 ( V_1 , V_2 , L_3 , V_17 , V_17 , L_13 ) ;
}
static T_3
F_50 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
struct V_80 * V_81 = & V_12 -> V_77 -> V_78 ;
struct V_80 * V_82 = & V_13 -> V_77 -> V_78 ;
if ( ! V_12 -> V_77 || ! V_13 -> V_77 )
return F_2 ( V_12 -> V_77 , V_13 -> V_77 ) ;
V_81 = & V_12 -> V_77 -> V_78 ;
V_82 = & V_13 -> V_77 -> V_78 ;
if ( ! V_81 -> V_40 && ! V_82 -> V_40 )
return F_16 ( V_81 -> V_83 , V_82 -> V_83 ) ;
return F_17 ( V_81 -> V_40 , V_82 -> V_40 ) ;
}
static T_3
F_51 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
struct V_80 * V_84 , * V_85 ;
if ( ! V_12 -> V_77 || ! V_13 -> V_77 )
return F_2 ( V_12 -> V_77 , V_13 -> V_77 ) ;
V_84 = & V_12 -> V_77 -> V_79 ;
V_85 = & V_13 -> V_77 -> V_79 ;
if ( ! V_84 -> V_40 && ! V_85 -> V_40 )
return F_16 ( V_84 -> V_83 , V_85 -> V_83 ) ;
return F_17 ( V_84 -> V_40 , V_85 -> V_40 ) ;
}
static int F_52 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
if ( V_16 -> V_77 ) {
struct V_80 * V_78 = & V_16 -> V_77 -> V_78 ;
return F_20 ( V_78 -> V_19 , V_78 -> V_40 , V_78 -> V_83 ,
V_16 -> V_44 , V_1 , V_2 , V_17 ) ;
}
return F_1 ( V_1 , V_2 , L_3 , V_17 , V_17 , L_13 ) ;
}
static int F_53 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
if ( V_16 -> V_77 ) {
struct V_80 * V_79 = & V_16 -> V_77 -> V_79 ;
return F_20 ( V_79 -> V_19 , V_79 -> V_40 , V_79 -> V_83 ,
V_16 -> V_44 , V_1 , V_2 , V_17 ) ;
}
return F_1 ( V_1 , V_2 , L_3 , V_17 , V_17 , L_13 ) ;
}
static T_3
F_54 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
unsigned char V_86 , V_54 ;
if ( ! V_12 -> V_77 || ! V_13 -> V_77 )
return F_2 ( V_12 -> V_77 , V_13 -> V_77 ) ;
V_86 = V_12 -> V_77 -> V_87 . V_88 != V_13 -> V_77 -> V_87 . V_88 ;
V_54 = V_12 -> V_77 -> V_87 . V_89 != V_13 -> V_77 -> V_87 . V_89 ;
return V_86 || V_54 ;
}
static int F_55 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 ) {
static const char * V_90 = L_13 ;
if ( V_16 -> V_77 ) {
if ( V_16 -> V_77 -> V_87 . V_89 )
V_90 = L_14 ;
else if ( V_16 -> V_77 -> V_87 . V_88 )
V_90 = L_15 ;
}
return F_1 ( V_1 , V_2 , L_3 , V_17 , V_17 , V_90 ) ;
}
static T_3
F_56 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
return V_12 -> V_77 -> V_87 . V_91 -
V_13 -> V_77 -> V_87 . V_91 ;
}
static int F_57 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
if ( V_16 -> V_77 -> V_87 . V_91 == 0 )
return F_1 ( V_1 , V_2 , L_9 , V_17 , L_16 ) ;
return F_1 ( V_1 , V_2 , L_17 , V_17 ,
V_16 -> V_77 -> V_87 . V_91 ) ;
}
static T_3
F_58 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
T_5 V_9 = 0 , V_10 = 0 ;
if ( V_12 -> V_92 )
V_9 = V_12 -> V_92 -> V_93 . V_83 ;
if ( V_13 -> V_92 )
V_10 = V_13 -> V_92 -> V_93 . V_83 ;
return ( T_3 ) ( V_10 - V_9 ) ;
}
static int F_59 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
T_5 V_83 = 0 ;
struct V_19 * V_19 = NULL ;
struct V_34 * V_40 = NULL ;
if ( V_16 -> V_92 ) {
V_83 = V_16 -> V_92 -> V_93 . V_83 ;
V_19 = V_16 -> V_92 -> V_93 . V_19 ;
V_40 = V_16 -> V_92 -> V_93 . V_40 ;
}
return F_20 ( V_19 , V_40 , V_83 , V_16 -> V_44 , V_1 , V_2 ,
V_17 ) ;
}
static T_3
F_60 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
T_5 V_9 = 0 , V_10 = 0 ;
if ( V_12 -> V_92 )
V_9 = V_12 -> V_92 -> V_94 . V_83 ;
if ( V_13 -> V_92 )
V_10 = V_13 -> V_92 -> V_94 . V_83 ;
return ( T_3 ) ( V_10 - V_9 ) ;
}
static int F_61 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
T_5 V_83 = 0 ;
struct V_19 * V_19 = NULL ;
struct V_34 * V_40 = NULL ;
if ( V_16 -> V_92 ) {
V_83 = V_16 -> V_92 -> V_94 . V_83 ;
V_19 = V_16 -> V_92 -> V_94 . V_19 ;
V_40 = V_16 -> V_92 -> V_94 . V_40 ;
}
return F_20 ( V_19 , V_40 , V_83 , V_16 -> V_44 , V_1 , V_2 ,
V_17 ) ;
}
static T_3
F_62 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
struct V_19 * V_20 = NULL ;
struct V_19 * V_21 = NULL ;
if ( V_12 -> V_92 )
V_20 = V_12 -> V_92 -> V_93 . V_19 ;
if ( V_13 -> V_92 )
V_21 = V_13 -> V_92 -> V_93 . V_19 ;
return F_12 ( V_20 , V_21 ) ;
}
static int F_63 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
struct V_19 * V_19 = NULL ;
if ( V_16 -> V_92 )
V_19 = V_16 -> V_92 -> V_93 . V_19 ;
return F_14 ( V_19 , V_1 , V_2 , V_17 ) ;
}
static T_3
F_64 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
union V_95 V_96 ;
union V_95 V_97 ;
if ( V_12 -> V_92 )
V_96 = V_12 -> V_92 -> V_98 ;
else
V_96 . V_99 = V_100 ;
if ( V_13 -> V_92 )
V_97 = V_13 -> V_92 -> V_98 ;
else
V_97 . V_99 = V_100 ;
return ( T_3 ) ( V_97 . V_99 - V_96 . V_99 ) ;
}
static int F_65 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
const char * V_90 ;
T_4 V_101 = V_100 ;
if ( V_16 -> V_92 )
V_101 = V_16 -> V_92 -> V_98 . V_99 ;
if ( V_101 & V_100 )
V_90 = L_13 ;
else if ( V_101 & V_102 )
V_90 = L_18 ;
else
V_90 = L_19 ;
return F_1 ( V_1 , V_2 , L_9 , V_17 , V_90 ) ;
}
static T_3
F_66 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
union V_95 V_96 ;
union V_95 V_97 ;
if ( V_12 -> V_92 )
V_96 = V_12 -> V_92 -> V_98 ;
else
V_96 . V_103 = V_104 ;
if ( V_13 -> V_92 )
V_97 = V_13 -> V_92 -> V_98 ;
else
V_97 . V_103 = V_104 ;
return ( T_3 ) ( V_97 . V_103 - V_96 . V_103 ) ;
}
static int F_67 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
char V_90 [ 64 ] ;
T_1 V_105 = sizeof( V_90 ) - 1 ;
T_1 V_9 = 0 , V_106 ;
T_4 V_107 = V_104 ;
T_4 V_108 , V_109 ;
V_90 [ 0 ] = '\0' ;
if ( V_16 -> V_92 )
V_107 = V_16 -> V_92 -> V_98 . V_103 ;
V_108 = V_107 & V_110 ;
V_109 = V_107 & V_111 ;
V_107 &= ~ ( V_110 | V_111 ) ;
for ( V_106 = 0 ; V_107 && V_106 < V_112 ; V_106 ++ , V_107 >>= 1 ) {
if ( ! ( V_107 & 0x1 ) )
continue;
if ( V_9 ) {
strcat ( V_90 , L_20 ) ;
V_9 += 4 ;
}
strncat ( V_90 , V_113 [ V_106 ] , V_105 - V_9 ) ;
V_9 += strlen ( V_113 [ V_106 ] ) ;
}
if ( * V_90 == '\0' )
strcpy ( V_90 , L_13 ) ;
if ( V_108 )
strncat ( V_90 , L_21 , V_105 - V_9 ) ;
if ( V_109 )
strncat ( V_90 , L_22 , V_105 - V_9 ) ;
return F_1 ( V_1 , V_2 , L_9 , V_17 , V_90 ) ;
}
static T_3
F_68 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
union V_95 V_96 ;
union V_95 V_97 ;
if ( V_12 -> V_92 )
V_96 = V_12 -> V_92 -> V_98 ;
else
V_96 . V_114 = V_115 ;
if ( V_13 -> V_92 )
V_97 = V_13 -> V_92 -> V_98 ;
else
V_97 . V_114 = V_115 ;
return ( T_3 ) ( V_97 . V_114 - V_96 . V_114 ) ;
}
static int F_69 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
char V_90 [ 64 ] ;
T_1 V_105 = sizeof( V_90 ) - 1 ;
T_1 V_106 , V_9 = 0 ;
T_4 V_107 = V_115 ;
T_4 V_108 , V_109 ;
if ( V_16 -> V_92 )
V_107 = V_16 -> V_92 -> V_98 . V_114 ;
V_90 [ 0 ] = '\0' ;
V_108 = V_107 & V_116 ;
V_109 = V_107 & V_117 ;
V_107 &= ~ ( V_116 | V_117 ) ;
for ( V_106 = 0 ; V_107 && V_106 < V_118 ; V_106 ++ , V_107 >>= 1 ) {
if ( ! ( V_107 & 0x1 ) )
continue;
if ( V_9 ) {
strcat ( V_90 , L_20 ) ;
V_9 += 4 ;
}
strncat ( V_90 , V_114 [ V_106 ] , V_105 - V_9 ) ;
V_9 += strlen ( V_114 [ V_106 ] ) ;
}
if ( * V_90 == '\0' )
strcpy ( V_90 , L_13 ) ;
if ( V_108 )
strncat ( V_90 , L_21 , V_105 - V_9 ) ;
if ( V_109 )
strncat ( V_90 , L_22 , V_105 - V_9 ) ;
return F_1 ( V_1 , V_2 , L_9 , V_17 , V_90 ) ;
}
static T_3
F_70 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
union V_95 V_96 ;
union V_95 V_97 ;
if ( V_12 -> V_92 )
V_96 = V_12 -> V_92 -> V_98 ;
else
V_96 . V_119 = V_120 ;
if ( V_13 -> V_92 )
V_97 = V_13 -> V_92 -> V_98 ;
else
V_97 . V_119 = V_120 ;
return ( T_3 ) ( V_97 . V_119 - V_96 . V_119 ) ;
}
static int F_71 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
char V_90 [ 64 ] ;
T_1 V_105 = sizeof( V_90 ) - 1 ;
T_1 V_106 , V_9 = 0 ;
T_4 V_107 = V_120 ;
V_90 [ 0 ] = '\0' ;
if ( V_16 -> V_92 )
V_107 = V_16 -> V_92 -> V_98 . V_119 ;
for ( V_106 = 0 ; V_107 && V_106 < V_121 ; V_106 ++ , V_107 >>= 1 ) {
if ( ! ( V_107 & 0x1 ) )
continue;
if ( V_9 ) {
strcat ( V_90 , L_20 ) ;
V_9 += 4 ;
}
strncat ( V_90 , V_122 [ V_106 ] , V_105 - V_9 ) ;
V_9 += strlen ( V_122 [ V_106 ] ) ;
}
if ( * V_90 == '\0' )
strcpy ( V_90 , L_13 ) ;
return F_1 ( V_1 , V_2 , L_9 , V_17 , V_90 ) ;
}
static inline T_4 F_72 ( T_4 V_123 )
{
return ( V_123 & ~ ( V_124 - 1 ) ) ;
}
static T_3
F_73 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
T_4 V_9 , V_10 ;
struct V_19 * V_125 , * V_126 ;
if ( ! V_12 -> V_92 ) return - 1 ;
if ( ! V_13 -> V_92 ) return 1 ;
if ( V_12 -> V_127 > V_13 -> V_127 ) return - 1 ;
if ( V_12 -> V_127 < V_13 -> V_127 ) return 1 ;
V_125 = V_12 -> V_92 -> V_93 . V_19 ;
V_126 = V_13 -> V_92 -> V_93 . V_19 ;
if ( ! V_125 && ! V_126 )
goto V_83;
if ( ! V_125 ) return - 1 ;
if ( ! V_126 ) return 1 ;
if ( V_125 -> V_128 > V_126 -> V_128 ) return - 1 ;
if ( V_125 -> V_128 < V_126 -> V_128 ) return 1 ;
if ( V_125 -> V_129 > V_126 -> V_129 ) return - 1 ;
if ( V_125 -> V_129 < V_126 -> V_129 ) return 1 ;
if ( V_125 -> V_130 > V_126 -> V_130 ) return - 1 ;
if ( V_125 -> V_130 < V_126 -> V_130 ) return 1 ;
if ( V_125 -> V_131 > V_126 -> V_131 ) return - 1 ;
if ( V_125 -> V_131 < V_126 -> V_131 ) return 1 ;
if ( ( V_12 -> V_127 != V_132 ) &&
( ! ( V_125 -> V_87 & V_133 ) ) &&
! V_125 -> V_128 && ! V_125 -> V_129 && ! V_125 -> V_130 &&
! V_125 -> V_131 ) {
if ( V_12 -> V_14 -> V_134 > V_13 -> V_14 -> V_134 ) return - 1 ;
if ( V_12 -> V_14 -> V_134 < V_13 -> V_14 -> V_134 ) return 1 ;
}
V_83:
V_9 = F_72 ( V_12 -> V_92 -> V_93 . V_135 ) ;
V_10 = F_72 ( V_13 -> V_92 -> V_93 . V_135 ) ;
if ( V_9 > V_10 ) return - 1 ;
if ( V_9 < V_10 ) return 1 ;
return 0 ;
}
static int F_74 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
T_5 V_83 = 0 ;
struct V_19 * V_19 = NULL ;
struct V_34 * V_40 = NULL ;
char V_44 = V_16 -> V_44 ;
if ( V_16 -> V_92 ) {
V_83 = F_72 ( V_16 -> V_92 -> V_93 . V_135 ) ;
V_19 = V_16 -> V_92 -> V_93 . V_19 ;
V_40 = V_16 -> V_92 -> V_93 . V_40 ;
if ( ( V_16 -> V_127 != V_132 ) &&
V_19 && ( V_19 -> type == V_47 ) &&
( V_19 -> V_87 & V_133 ) &&
( V_19 -> V_128 || V_19 -> V_129 || V_19 -> V_130 ||
V_19 -> V_131 ) )
V_44 = 's' ;
else if ( ! V_19 )
V_44 = 'X' ;
}
return F_20 ( V_19 , V_40 , V_83 , V_44 , V_1 , V_2 ,
V_17 ) ;
}
static T_4 F_75 ( struct V_11 * V_16 )
{
return V_16 -> V_136 . V_137 ? V_16 -> V_136 . V_138 / V_16 -> V_136 . V_137 : 0 ;
}
static T_3
F_76 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
return F_75 ( V_12 ) - F_75 ( V_13 ) ;
}
static int F_77 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
return F_1 ( V_1 , V_2 , L_23 , V_17 , F_75 ( V_16 ) ) ;
}
static T_3
F_78 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
return V_12 -> V_136 . V_138 - V_13 -> V_136 . V_138 ;
}
static int F_79 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
return F_1 ( V_1 , V_2 , L_23 , V_17 , V_16 -> V_136 . V_138 ) ;
}
static T_3
F_80 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
if ( ! V_12 -> V_77 || ! V_13 -> V_77 )
return F_2 ( V_12 -> V_77 , V_13 -> V_77 ) ;
return V_12 -> V_77 -> V_87 . abort !=
V_13 -> V_77 -> V_87 . abort ;
}
static int F_81 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
static const char * V_90 = L_13 ;
if ( V_16 -> V_77 ) {
if ( V_16 -> V_77 -> V_87 . abort )
V_90 = L_24 ;
else
V_90 = L_25 ;
}
return F_1 ( V_1 , V_2 , L_9 , V_17 , V_90 ) ;
}
static T_3
F_82 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
if ( ! V_12 -> V_77 || ! V_13 -> V_77 )
return F_2 ( V_12 -> V_77 , V_13 -> V_77 ) ;
return V_12 -> V_77 -> V_87 . V_139 !=
V_13 -> V_77 -> V_87 . V_139 ;
}
static int F_83 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
static const char * V_90 = L_13 ;
if ( V_16 -> V_77 ) {
if ( V_16 -> V_77 -> V_87 . V_139 )
V_90 = L_26 ;
else
V_90 = L_25 ;
}
return F_1 ( V_1 , V_2 , L_9 , V_17 , V_90 ) ;
}
static T_3
F_84 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
return V_12 -> V_140 - V_13 -> V_140 ;
}
static inline char * F_85 ( char * V_54 , const char * V_141 )
{
strcpy ( V_54 , V_141 ) ;
return V_54 + strlen ( V_141 ) ;
}
int F_86 ( void )
{
int V_106 ;
int V_49 = 0 ;
for ( V_106 = 0 ; V_142 [ V_106 ] . V_43 ; V_106 ++ ) {
if ( ! V_142 [ V_106 ] . V_143 )
V_49 += strlen ( V_142 [ V_106 ] . V_43 ) ;
}
V_49 += 4 ;
return V_49 ;
}
static int F_87 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
T_4 V_144 = V_16 -> V_140 ;
char V_145 [ 128 ] ;
char * V_54 = V_145 ;
int V_106 ;
V_145 [ 0 ] = 0 ;
for ( V_106 = 0 ; V_142 [ V_106 ] . V_43 ; V_106 ++ )
if ( V_142 [ V_106 ] . V_146 & V_144 )
V_54 = F_85 ( V_54 , V_142 [ V_106 ] . V_43 ) ;
if ( V_144 && ! ( V_144 & ( V_147 | V_148 ) ) )
V_54 = F_85 ( V_54 , L_27 ) ;
if ( V_144 & V_149 ) {
sprintf ( V_54 , L_28 V_150 ,
( V_144 & V_149 ) >>
V_151 ) ;
V_54 += strlen ( V_54 ) ;
}
return F_1 ( V_1 , V_2 , L_9 , V_17 , V_145 ) ;
}
bool F_88 ( struct V_152 * V_153 , struct V_152 * V_154 )
{
struct V_155 * V_156 ;
struct V_155 * V_157 ;
if ( ! F_89 ( V_153 ) || ! F_89 ( V_154 ) )
return false ;
V_156 = F_90 ( V_153 , struct V_155 , V_158 ) ;
V_157 = F_90 ( V_154 , struct V_155 , V_158 ) ;
return V_156 -> V_159 == V_157 -> V_159 ;
}
void F_91 ( struct V_152 * V_3 , struct V_69 * V_69 )
{
struct V_155 * V_160 ;
if ( ! F_89 ( V_3 ) )
return;
V_160 = F_90 ( V_3 , struct V_155 , V_158 ) ;
F_43 ( V_69 , V_160 -> V_159 -> V_161 , strlen ( V_3 -> V_43 ) ) ;
}
static int F_92 ( struct V_152 * V_3 , struct V_162 * V_158 ,
struct V_62 * V_63 )
{
struct V_155 * V_160 ;
T_1 V_49 = V_3 -> V_163 ;
V_160 = F_90 ( V_3 , struct V_155 , V_158 ) ;
if ( ! V_49 )
V_49 = F_93 ( F_94 ( V_63 ) , V_160 -> V_159 -> V_161 ) ;
return F_45 ( V_158 -> V_145 , V_158 -> V_2 , L_3 , V_49 , V_49 , V_3 -> V_43 ) ;
}
static int F_95 ( struct V_152 * V_3 ,
struct V_162 * V_158 V_164 ,
struct V_62 * V_63 )
{
struct V_155 * V_160 ;
T_1 V_49 = V_3 -> V_163 ;
V_160 = F_90 ( V_3 , struct V_155 , V_158 ) ;
if ( ! V_49 )
V_49 = F_93 ( F_94 ( V_63 ) , V_160 -> V_159 -> V_161 ) ;
return V_49 ;
}
static int F_96 ( struct V_152 * V_3 , struct V_162 * V_158 ,
struct V_11 * V_16 )
{
struct V_155 * V_160 ;
T_1 V_49 = V_3 -> V_163 ;
V_160 = F_90 ( V_3 , struct V_155 , V_158 ) ;
if ( ! V_49 )
V_49 = F_93 ( V_16 -> V_69 , V_160 -> V_159 -> V_161 ) ;
return V_160 -> V_159 -> V_165 ( V_16 , V_158 -> V_145 , V_158 -> V_2 , V_49 ) ;
}
static T_3 F_97 ( struct V_152 * V_3 ,
struct V_11 * V_153 , struct V_11 * V_154 )
{
struct V_155 * V_160 ;
V_160 = F_90 ( V_3 , struct V_155 , V_158 ) ;
return V_160 -> V_159 -> V_166 ( V_153 , V_154 ) ;
}
static T_3 F_98 ( struct V_152 * V_3 ,
struct V_11 * V_153 , struct V_11 * V_154 )
{
struct V_155 * V_160 ;
T_3 (* F_99)( struct V_11 * , struct V_11 * );
V_160 = F_90 ( V_3 , struct V_155 , V_158 ) ;
F_99 = V_160 -> V_159 -> V_167 ? : V_160 -> V_159 -> V_166 ;
return F_99 ( V_153 , V_154 ) ;
}
static T_3 F_100 ( struct V_152 * V_3 ,
struct V_11 * V_153 , struct V_11 * V_154 )
{
struct V_155 * V_160 ;
T_3 (* F_101)( struct V_11 * , struct V_11 * );
V_160 = F_90 ( V_3 , struct V_155 , V_158 ) ;
F_101 = V_160 -> V_159 -> V_168 ? : V_160 -> V_159 -> V_166 ;
return F_101 ( V_153 , V_154 ) ;
}
static struct V_155 *
F_102 ( struct V_169 * V_170 )
{
struct V_155 * V_160 ;
V_160 = malloc ( sizeof( * V_160 ) ) ;
if ( V_160 == NULL ) {
F_103 ( L_29 ) ;
return NULL ;
}
V_160 -> V_159 = V_170 -> V_171 ;
V_160 -> V_158 . V_43 = V_170 -> V_171 -> V_172 ;
V_160 -> V_158 . V_173 = F_92 ;
V_160 -> V_158 . V_17 = F_95 ;
V_160 -> V_158 . V_171 = F_96 ;
V_160 -> V_158 . V_174 = NULL ;
V_160 -> V_158 . V_175 = F_97 ;
V_160 -> V_158 . V_176 = F_98 ;
V_160 -> V_158 . V_177 = F_100 ;
F_104 ( & V_160 -> V_158 . V_178 ) ;
F_104 ( & V_160 -> V_158 . V_179 ) ;
V_160 -> V_158 . V_180 = false ;
V_160 -> V_158 . V_49 = 0 ;
V_160 -> V_158 . V_163 = 0 ;
return V_160 ;
}
bool F_89 ( struct V_152 * V_181 )
{
return V_181 -> V_173 == F_92 ;
}
static int F_105 ( struct V_169 * V_170 )
{
struct V_155 * V_160 = F_102 ( V_170 ) ;
if ( V_160 == NULL )
return - 1 ;
F_106 ( & V_160 -> V_158 ) ;
return 0 ;
}
static int F_107 ( struct V_169 * V_170 )
{
struct V_155 * V_160 = F_102 ( V_170 ) ;
if ( V_160 == NULL )
return - 1 ;
F_108 ( & V_160 -> V_158 ) ;
return 0 ;
}
static int F_109 ( struct V_182 * V_183 )
{
if ( ! V_183 -> V_158 . V_49 ) {
int V_49 = V_183 -> V_184 ;
int V_185 = strlen ( V_183 -> V_186 -> V_43 ) ;
int V_187 = V_183 -> V_186 -> V_2 ;
if ( V_185 > V_49 )
V_49 = V_185 ;
if ( ! ( V_183 -> V_186 -> V_87 & V_188 ) ) {
V_187 = V_183 -> V_186 -> V_2 * 2 + 2 ;
}
if ( V_187 > V_49 )
V_49 = V_187 ;
V_183 -> V_158 . V_49 = V_49 ;
}
return V_183 -> V_158 . V_49 ;
}
static void F_110 ( struct V_182 * V_183 ,
struct V_11 * V_16 )
{
char * V_141 , * V_189 ;
struct V_190 * V_186 = V_183 -> V_186 ;
T_1 V_185 ;
bool V_191 = false ;
if ( V_183 -> V_70 )
return;
if ( ! V_16 -> V_75 )
V_16 -> V_75 = F_37 ( V_16 ) ;
V_185 = strlen ( V_186 -> V_43 ) ;
V_141 = V_16 -> V_75 ;
while ( V_141 ) {
V_189 = strchr ( V_141 , ' ' ) ;
if ( V_189 == NULL ) {
V_191 = true ;
V_189 = V_141 + strlen ( V_141 ) ;
}
if ( ! strncmp ( V_141 , V_186 -> V_43 , V_185 ) ) {
T_1 V_49 ;
V_141 += V_185 + 1 ;
V_49 = V_189 - V_141 ;
if ( V_49 > V_183 -> V_184 )
V_183 -> V_184 = V_49 ;
break;
}
if ( V_191 )
V_141 = NULL ;
else
V_141 = V_189 + 1 ;
}
}
static int F_111 ( struct V_152 * V_3 , struct V_162 * V_158 ,
struct V_62 * V_63 V_164 )
{
struct V_182 * V_183 ;
T_1 V_49 = V_3 -> V_163 ;
V_183 = F_90 ( V_3 , struct V_182 , V_158 ) ;
if ( ! V_49 )
V_49 = F_109 ( V_183 ) ;
return F_45 ( V_158 -> V_145 , V_158 -> V_2 , L_30 , V_49 , V_49 , V_183 -> V_186 -> V_43 ) ;
}
static int F_112 ( struct V_152 * V_3 ,
struct V_162 * V_158 V_164 ,
struct V_62 * V_63 V_164 )
{
struct V_182 * V_183 ;
T_1 V_49 = V_3 -> V_163 ;
V_183 = F_90 ( V_3 , struct V_182 , V_158 ) ;
if ( ! V_49 )
V_49 = F_109 ( V_183 ) ;
return V_49 ;
}
bool F_113 ( struct V_152 * V_3 , struct V_69 * V_69 )
{
struct V_182 * V_183 ;
V_183 = F_90 ( V_3 , struct V_182 , V_158 ) ;
return F_38 ( V_69 ) == V_183 -> V_63 ;
}
static int F_114 ( struct V_152 * V_3 , struct V_162 * V_158 ,
struct V_11 * V_16 )
{
struct V_182 * V_183 ;
T_1 V_49 = V_3 -> V_163 ;
char * V_141 , * V_189 ;
struct V_190 * V_186 ;
T_1 V_185 ;
bool V_191 = false ;
int V_39 ;
V_183 = F_90 ( V_3 , struct V_182 , V_158 ) ;
if ( ! V_49 )
V_49 = F_109 ( V_183 ) ;
if ( V_183 -> V_70 )
goto V_192;
V_186 = V_183 -> V_186 ;
V_185 = strlen ( V_186 -> V_43 ) ;
V_141 = V_16 -> V_75 ;
while ( V_141 ) {
V_189 = strchr ( V_141 , ' ' ) ;
if ( V_189 == NULL ) {
V_191 = true ;
V_189 = V_141 + strlen ( V_141 ) ;
}
if ( ! strncmp ( V_141 , V_186 -> V_43 , V_185 ) ) {
V_141 += V_185 + 1 ;
V_141 = F_115 ( V_141 , V_189 - V_141 ) ;
if ( V_141 == NULL )
return F_45 ( V_158 -> V_145 , V_158 -> V_2 ,
L_30 , V_49 , V_49 , L_31 ) ;
break;
}
if ( V_191 )
V_141 = NULL ;
else
V_141 = V_189 + 1 ;
}
if ( V_141 == NULL ) {
struct V_60 V_61 ;
V_192:
F_39 ( & V_61 ) ;
F_116 ( & V_61 , V_16 -> V_67 , V_183 -> V_186 ) ;
V_141 = V_61 . V_72 ;
}
V_39 = F_45 ( V_158 -> V_145 , V_158 -> V_2 , L_30 , V_49 , V_49 , V_141 ) ;
free ( V_141 ) ;
return V_39 ;
}
static T_3 F_117 ( struct V_152 * V_3 ,
struct V_11 * V_153 , struct V_11 * V_154 )
{
struct V_182 * V_183 ;
struct V_190 * V_186 ;
unsigned V_193 , V_2 ;
V_183 = F_90 ( V_3 , struct V_182 , V_158 ) ;
V_186 = V_183 -> V_186 ;
if ( V_186 -> V_87 & V_194 ) {
unsigned long long V_195 ;
F_118 ( V_186 , V_153 -> V_67 , & V_195 ) ;
V_193 = V_195 & 0xffff ;
V_2 = ( V_195 >> 16 ) & 0xffff ;
if ( V_2 > V_183 -> V_184 )
V_183 -> V_184 = V_2 ;
} else {
V_193 = V_186 -> V_193 ;
V_2 = V_186 -> V_2 ;
F_110 ( V_183 , V_153 ) ;
F_110 ( V_183 , V_154 ) ;
}
return memcmp ( V_153 -> V_67 + V_193 , V_154 -> V_67 + V_193 , V_2 ) ;
}
bool F_119 ( struct V_152 * V_3 )
{
return V_3 -> V_175 == F_117 ;
}
static struct V_182 *
F_120 ( struct V_62 * V_63 , struct V_190 * V_186 )
{
struct V_182 * V_183 ;
V_183 = malloc ( sizeof( * V_183 ) ) ;
if ( V_183 == NULL ) {
F_121 ( L_29 ) ;
return NULL ;
}
V_183 -> V_63 = V_63 ;
V_183 -> V_186 = V_186 ;
V_183 -> V_184 = 0 ;
V_183 -> V_158 . V_43 = V_186 -> V_43 ;
V_183 -> V_158 . V_173 = F_111 ;
V_183 -> V_158 . V_17 = F_112 ;
V_183 -> V_158 . V_171 = F_114 ;
V_183 -> V_158 . V_174 = NULL ;
V_183 -> V_158 . V_175 = F_117 ;
V_183 -> V_158 . V_176 = F_117 ;
V_183 -> V_158 . V_177 = F_117 ;
F_104 ( & V_183 -> V_158 . V_178 ) ;
F_104 ( & V_183 -> V_158 . V_179 ) ;
V_183 -> V_158 . V_180 = false ;
V_183 -> V_158 . V_49 = 0 ;
V_183 -> V_158 . V_163 = 0 ;
return V_183 ;
}
static int F_122 ( char * V_141 , char * * V_196 , char * * V_186 , char * * V_197 )
{
char * V_198 , * V_199 , * V_200 ;
V_198 = V_141 ;
V_199 = strchr ( V_141 , '.' ) ;
if ( V_199 ) {
* V_199 ++ = '\0' ;
} else {
V_198 = NULL ;
V_199 = V_141 ;
}
V_200 = strchr ( V_199 , '/' ) ;
if ( V_200 )
* V_200 ++ = '\0' ;
* V_196 = V_198 ;
* V_186 = V_199 ;
* V_197 = V_200 ;
return 0 ;
}
static struct V_62 * F_123 ( struct V_201 * V_202 , char * V_198 )
{
struct V_62 * V_63 = NULL ;
struct V_62 * V_189 ;
bool V_203 ;
if ( V_198 [ 0 ] == '%' ) {
int V_204 = strtol ( V_198 + 1 , NULL , 0 ) ;
if ( V_204 > V_202 -> V_205 )
return NULL ;
V_63 = F_124 ( V_202 ) ;
while ( -- V_204 > 0 )
V_63 = F_125 ( V_63 ) ;
return V_63 ;
}
V_203 = ! ! strchr ( V_198 , ':' ) ;
F_126 (evlist, pos) {
if ( V_203 && ! strcmp ( V_189 -> V_43 , V_198 ) )
return V_189 ;
if ( ! V_203 && strstr ( V_189 -> V_43 , V_198 ) ) {
if ( V_63 ) {
F_121 ( L_32 ,
V_198 , V_63 -> V_43 , V_189 -> V_43 ) ;
return NULL ;
}
V_63 = V_189 ;
}
}
return V_63 ;
}
static int F_127 ( struct V_62 * V_63 ,
struct V_190 * V_186 ,
bool V_70 )
{
struct V_182 * V_183 ;
V_183 = F_120 ( V_63 , V_186 ) ;
if ( V_183 == NULL )
return - V_206 ;
V_183 -> V_70 = V_70 ;
F_106 ( & V_183 -> V_158 ) ;
return 0 ;
}
static int F_128 ( struct V_62 * V_63 , bool V_70 )
{
int V_39 ;
struct V_190 * V_186 ;
V_186 = V_63 -> V_71 -> V_181 . V_207 ;
while ( V_186 ) {
V_39 = F_127 ( V_63 , V_186 , V_70 ) ;
if ( V_39 < 0 )
return V_39 ;
V_186 = V_186 -> V_208 ;
}
return 0 ;
}
static int F_129 ( struct V_201 * V_202 , bool V_70 )
{
int V_39 ;
struct V_62 * V_63 ;
F_126 (evlist, evsel) {
if ( V_63 -> V_73 . type != V_74 )
continue;
V_39 = F_128 ( V_63 , V_70 ) ;
if ( V_39 < 0 )
return V_39 ;
}
return 0 ;
}
static int F_130 ( struct V_201 * V_202 ,
char * V_199 , bool V_70 )
{
int V_39 = - V_209 ;
struct V_62 * V_63 ;
struct V_190 * V_186 ;
F_126 (evlist, evsel) {
if ( V_63 -> V_73 . type != V_74 )
continue;
V_186 = F_131 ( V_63 -> V_71 , V_199 ) ;
if ( V_186 == NULL )
continue;
V_39 = F_127 ( V_63 , V_186 , V_70 ) ;
if ( V_39 < 0 )
break;
}
return V_39 ;
}
static int F_132 ( struct V_201 * V_202 , const char * V_210 )
{
char * V_141 , * V_198 , * V_199 , * V_200 ;
struct V_62 * V_63 ;
struct V_190 * V_186 ;
bool V_70 = V_6 . V_70 ;
int V_39 = 0 ;
if ( V_202 == NULL )
return - V_211 ;
V_141 = F_133 ( V_210 ) ;
if ( V_141 == NULL )
return - V_206 ;
if ( F_122 ( V_141 , & V_198 , & V_199 , & V_200 ) < 0 ) {
V_39 = - V_212 ;
goto V_90;
}
if ( V_200 ) {
if ( strcmp ( V_200 , L_33 ) ) {
F_121 ( L_34 , V_200 ) ;
V_39 = - V_212 ;
goto V_90;
}
V_70 = true ;
}
if ( ! strcmp ( V_199 , L_35 ) ) {
V_39 = F_129 ( V_202 , V_70 ) ;
goto V_90;
}
if ( V_198 == NULL ) {
V_39 = F_130 ( V_202 , V_199 , V_70 ) ;
goto V_90;
}
V_63 = F_123 ( V_202 , V_198 ) ;
if ( V_63 == NULL ) {
F_121 ( L_36 , V_198 ) ;
V_39 = - V_211 ;
goto V_90;
}
if ( V_63 -> V_73 . type != V_74 ) {
F_121 ( L_37 , V_198 ) ;
V_39 = - V_212 ;
goto V_90;
}
if ( ! strcmp ( V_199 , L_38 ) ) {
V_39 = F_128 ( V_63 , V_70 ) ;
} else {
V_186 = F_131 ( V_63 -> V_71 , V_199 ) ;
if ( V_186 == NULL ) {
F_121 ( L_39 ,
V_198 , V_199 ) ;
return - V_211 ;
}
V_39 = F_127 ( V_63 , V_186 , V_70 ) ;
}
V_90:
free ( V_141 ) ;
return V_39 ;
}
static int F_134 ( struct V_169 * V_170 )
{
if ( V_170 -> V_213 )
return 0 ;
if ( F_105 ( V_170 ) < 0 )
return - 1 ;
if ( V_170 -> V_171 -> V_167 )
V_214 = 1 ;
V_170 -> V_213 = 1 ;
return 0 ;
}
static int F_135 ( struct V_215 * V_216 )
{
if ( ! V_216 -> V_213 ) {
V_216 -> V_213 = 1 ;
F_106 ( V_216 -> V_3 ) ;
}
return 0 ;
}
static int F_136 ( struct V_169 * V_170 )
{
if ( V_170 -> V_213 )
return 0 ;
if ( F_107 ( V_170 ) < 0 )
return - 1 ;
V_170 -> V_213 = 1 ;
return 0 ;
}
static int F_137 ( struct V_215 * V_216 )
{
if ( ! V_216 -> V_213 ) {
V_216 -> V_213 = 1 ;
F_108 ( V_216 -> V_3 ) ;
}
return 0 ;
}
int F_138 ( unsigned V_217 )
{
F_139 ( V_217 >= V_218 ) ;
return F_137 ( & V_219 [ V_217 ] ) ;
}
static int F_140 ( const char * V_210 ,
struct V_201 * V_202 V_164 )
{
unsigned int V_106 ;
for ( V_106 = 0 ; V_106 < F_141 ( V_220 ) ; V_106 ++ ) {
struct V_169 * V_170 = & V_220 [ V_106 ] ;
if ( strncasecmp ( V_210 , V_170 -> V_43 , strlen ( V_210 ) ) )
continue;
if ( V_170 -> V_171 == & V_221 ) {
int V_39 = regcomp ( & V_222 , V_223 , V_224 ) ;
if ( V_39 ) {
char V_225 [ V_226 ] ;
regerror ( V_39 , & V_222 , V_225 , sizeof( V_225 ) ) ;
F_103 ( L_40 , V_223 , V_225 ) ;
return - V_212 ;
}
V_227 = 1 ;
} else if ( V_170 -> V_171 == & V_228 ) {
V_229 = 1 ;
if ( V_230 == V_231 )
V_170 -> V_171 -> V_167 = F_19 ;
} else if ( V_170 -> V_171 == & V_232 ) {
V_42 = 1 ;
} else if ( V_170 -> V_171 == & V_233 ) {
V_234 = 1 ;
}
return F_134 ( V_170 ) ;
}
for ( V_106 = 0 ; V_106 < F_141 ( V_219 ) ; V_106 ++ ) {
struct V_215 * V_216 = & V_219 [ V_106 ] ;
if ( strncasecmp ( V_210 , V_216 -> V_43 , strlen ( V_210 ) ) )
continue;
return F_135 ( V_216 ) ;
}
for ( V_106 = 0 ; V_106 < F_141 ( V_235 ) ; V_106 ++ ) {
struct V_169 * V_170 = & V_235 [ V_106 ] ;
if ( strncasecmp ( V_210 , V_170 -> V_43 , strlen ( V_210 ) ) )
continue;
if ( V_230 != V_236 )
return - V_212 ;
if ( V_170 -> V_171 == & V_237 || V_170 -> V_171 == & V_238 )
V_229 = 1 ;
F_134 ( V_170 ) ;
return 0 ;
}
for ( V_106 = 0 ; V_106 < F_141 ( V_239 ) ; V_106 ++ ) {
struct V_169 * V_170 = & V_239 [ V_106 ] ;
if ( strncasecmp ( V_210 , V_170 -> V_43 , strlen ( V_210 ) ) )
continue;
if ( V_230 != V_240 )
return - V_212 ;
if ( V_170 -> V_171 == & V_241 )
V_229 = 1 ;
F_134 ( V_170 ) ;
return 0 ;
}
if ( ! F_132 ( V_202 , V_210 ) )
return 0 ;
return - V_209 ;
}
static const char * F_142 ( struct V_201 * V_202 )
{
const char * V_242 [] = {
V_243 ,
V_244 ,
V_245 ,
V_246 ,
V_247 ,
V_248 ,
} ;
bool V_249 = true ;
struct V_62 * V_63 ;
F_139 ( V_230 >= F_141 ( V_242 ) ) ;
if ( V_202 == NULL )
goto V_250;
F_126 (evlist, evsel) {
if ( V_63 -> V_73 . type != V_74 ) {
V_249 = false ;
break;
}
}
if ( V_249 ) {
V_230 = V_251 ;
if ( V_6 . V_70 )
return L_35 ;
}
V_250:
return V_242 [ V_230 ] ;
}
static int F_143 ( struct V_201 * V_202 )
{
char * V_252 ;
if ( ! V_253 || F_144 ( V_253 ) )
return 0 ;
if ( V_253 [ 1 ] == '\0' ) {
error ( L_41 ) ;
return - V_212 ;
}
if ( F_145 ( & V_252 , L_42 ,
F_142 ( V_202 ) , V_253 + 1 ) < 0 ) {
error ( L_43 ) ;
return - V_206 ;
}
V_253 = V_252 ;
return 0 ;
}
static char * F_146 ( const char * V_254 , char * V_141 )
{
char * V_4 ;
if ( ! V_141 || strstr ( V_141 , V_254 ) )
return V_141 ;
if ( F_145 ( & V_4 , L_42 , V_254 , V_141 ) < 0 )
return NULL ;
free ( V_141 ) ;
return V_4 ;
}
static char * F_147 ( char * V_255 )
{
V_255 = F_146 ( L_44 , V_255 ) ;
if ( V_6 . V_256 )
V_255 = F_146 ( L_45 , V_255 ) ;
return V_255 ;
}
static int F_148 ( struct V_201 * V_202 )
{
char * V_257 , * V_210 , * V_141 ;
const char * V_258 ;
int V_39 = 0 ;
V_39 = F_143 ( V_202 ) ;
if ( V_39 )
return V_39 ;
V_258 = V_253 ;
if ( V_258 == NULL ) {
if ( F_144 ( V_259 ) ) {
return 0 ;
}
V_258 = F_142 ( V_202 ) ;
}
V_141 = F_133 ( V_258 ) ;
if ( V_141 == NULL ) {
error ( L_46 ) ;
return - V_206 ;
}
if ( ! F_144 ( V_259 ) ) {
V_141 = F_147 ( V_141 ) ;
if ( V_141 == NULL ) {
error ( L_47 ) ;
return - V_206 ;
}
}
for ( V_210 = strtok_r ( V_141 , L_48 , & V_257 ) ;
V_210 ; V_210 = strtok_r ( NULL , L_48 , & V_257 ) ) {
V_39 = F_140 ( V_210 , V_202 ) ;
if ( V_39 == - V_212 ) {
error ( L_49 , V_210 ) ;
break;
} else if ( V_39 == - V_209 ) {
error ( L_50 , V_210 ) ;
break;
}
}
free ( V_141 ) ;
return V_39 ;
}
void F_149 ( int V_260 , bool V_180 )
{
struct V_152 * V_3 ;
struct V_155 * V_160 ;
F_150 (fmt) {
if ( ! F_89 ( V_3 ) )
continue;
V_160 = F_90 ( V_3 , struct V_155 , V_158 ) ;
if ( V_160 -> V_159 -> V_161 == V_260 ) {
V_3 -> V_180 = V_180 ;
break;
}
}
}
static bool F_151 ( struct V_261 * V_178 , const char * V_262 , T_6 * V_263 )
{
if ( V_178 && F_152 ( V_178 ) == 1 ) {
if ( V_263 != NULL )
fprintf ( V_263 , L_51 , V_262 ,
F_153 ( V_178 , 0 ) -> V_264 ) ;
return true ;
}
return false ;
}
static bool F_154 ( int V_260 , T_6 * V_265 )
{
switch ( V_260 ) {
case V_266 :
return F_151 ( V_6 . V_267 , L_52 , V_265 ) ;
case V_268 :
return F_151 ( V_6 . V_269 , L_53 , V_265 ) ;
case V_270 :
return F_151 ( V_6 . V_271 , L_54 , V_265 ) ;
default:
break;
}
if ( V_230 != V_236 )
return false ;
switch ( V_260 ) {
case V_272 :
return F_151 ( V_6 . V_273 , L_55 , V_265 ) ;
case V_274 :
return F_151 ( V_6 . V_275 , L_56 , V_265 ) ;
case V_276 :
return F_151 ( V_6 . V_277 , L_57 , V_265 ) ;
case V_278 :
return F_151 ( V_6 . V_279 , L_58 , V_265 ) ;
default:
break;
}
return false ;
}
void F_155 ( T_6 * V_265 )
{
struct V_152 * V_3 ;
struct V_155 * V_160 ;
F_150 (fmt) {
if ( ! F_89 ( V_3 ) )
continue;
V_160 = F_90 ( V_3 , struct V_155 , V_158 ) ;
V_3 -> V_180 = F_154 ( V_160 -> V_159 -> V_161 , V_265 ) ;
}
F_150 (fmt) {
if ( ! F_89 ( V_3 ) )
continue;
if ( ! V_3 -> V_180 )
return;
}
F_150 (fmt) {
if ( ! F_89 ( V_3 ) )
continue;
V_3 -> V_180 = false ;
}
}
static int F_156 ( char * V_210 )
{
unsigned int V_106 ;
for ( V_106 = 0 ; V_106 < F_141 ( V_220 ) ; V_106 ++ ) {
struct V_169 * V_170 = & V_220 [ V_106 ] ;
if ( strncasecmp ( V_210 , V_170 -> V_43 , strlen ( V_210 ) ) )
continue;
return F_136 ( V_170 ) ;
}
for ( V_106 = 0 ; V_106 < F_141 ( V_219 ) ; V_106 ++ ) {
struct V_215 * V_216 = & V_219 [ V_106 ] ;
if ( strncasecmp ( V_210 , V_216 -> V_43 , strlen ( V_210 ) ) )
continue;
return F_137 ( V_216 ) ;
}
for ( V_106 = 0 ; V_106 < F_141 ( V_235 ) ; V_106 ++ ) {
struct V_169 * V_170 = & V_235 [ V_106 ] ;
if ( strncasecmp ( V_210 , V_170 -> V_43 , strlen ( V_210 ) ) )
continue;
return F_136 ( V_170 ) ;
}
for ( V_106 = 0 ; V_106 < F_141 ( V_239 ) ; V_106 ++ ) {
struct V_169 * V_170 = & V_239 [ V_106 ] ;
if ( strncasecmp ( V_210 , V_170 -> V_43 , strlen ( V_210 ) ) )
continue;
return F_136 ( V_170 ) ;
}
return - V_209 ;
}
static void F_157 ( void )
{
unsigned int V_106 ;
for ( V_106 = 0 ; V_106 < F_141 ( V_220 ) ; V_106 ++ )
V_220 [ V_106 ] . V_213 = 0 ;
for ( V_106 = 0 ; V_106 < F_141 ( V_219 ) ; V_106 ++ )
V_219 [ V_106 ] . V_213 = 0 ;
for ( V_106 = 0 ; V_106 < F_141 ( V_235 ) ; V_106 ++ )
V_235 [ V_106 ] . V_213 = 0 ;
for ( V_106 = 0 ; V_106 < F_141 ( V_239 ) ; V_106 ++ )
V_239 [ V_106 ] . V_213 = 0 ;
}
bool F_144 ( const char * V_280 )
{
return V_280 && ( * V_280 != '+' ) ;
}
static int F_158 ( void )
{
char * V_257 , * V_210 , * V_141 , * V_281 ;
int V_39 = - V_212 ;
if ( V_259 == NULL )
return 0 ;
V_281 = V_141 = F_133 ( V_259 ) ;
if ( V_141 == NULL ) {
error ( L_59 ) ;
return - V_206 ;
}
if ( ! F_144 ( V_259 ) )
V_281 ++ ;
if ( ! strlen ( V_281 ) ) {
error ( L_60 ) ;
goto V_90;
}
for ( V_210 = strtok_r ( V_281 , L_48 , & V_257 ) ;
V_210 ; V_210 = strtok_r ( NULL , L_48 , & V_257 ) ) {
V_39 = F_156 ( V_210 ) ;
if ( V_39 == - V_212 ) {
error ( L_61 , V_210 ) ;
break;
} else if ( V_39 == - V_209 ) {
error ( L_62 , V_210 ) ;
break;
}
}
V_90:
free ( V_141 ) ;
return V_39 ;
}
int F_159 ( struct V_201 * V_202 )
{
int V_225 ;
V_225 = F_148 ( V_202 ) ;
if ( V_225 < 0 )
return V_225 ;
if ( V_223 != V_282 ) {
V_225 = F_140 ( L_63 , V_202 ) ;
if ( V_225 < 0 )
return V_225 ;
}
F_157 () ;
if ( V_230 != V_231 )
F_160 () ;
V_225 = F_158 () ;
if ( V_225 < 0 )
return V_225 ;
F_161 () ;
F_162 () ;
return 0 ;
}
void F_163 ( void )
{
V_214 = 0 ;
V_227 = 0 ;
V_229 = 0 ;
V_42 = 0 ;
V_259 = NULL ;
V_253 = NULL ;
F_157 () ;
F_164 () ;
}
