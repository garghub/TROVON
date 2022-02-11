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
static T_3
F_27 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
struct V_34 * V_35 = V_12 -> V_52 ;
struct V_34 * V_36 = V_13 -> V_52 ;
if ( ! V_35 || ! V_36 )
return F_2 ( V_35 , V_36 ) ;
return strcmp ( V_36 -> V_43 , V_35 -> V_43 ) ;
}
static int F_28 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
return F_1 ( V_1 , V_2 , L_3 , V_17 , V_17 ,
V_16 -> V_52 ? V_16 -> V_52 -> V_43 : L_11 ) ;
}
static T_3
F_29 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
return V_13 -> V_53 - V_12 -> V_53 ;
}
static int F_30 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
return F_1 ( V_1 , V_2 , L_12 , V_17 , V_17 , V_16 -> V_53 ) ;
}
static T_3
F_31 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
if ( ! V_12 -> V_54 || ! V_13 -> V_54 )
return F_2 ( V_12 -> V_54 , V_13 -> V_54 ) ;
return F_12 ( V_12 -> V_54 -> V_55 . V_19 ,
V_13 -> V_54 -> V_55 . V_19 ) ;
}
static int F_32 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
if ( V_16 -> V_54 )
return F_14 ( V_16 -> V_54 -> V_55 . V_19 ,
V_1 , V_2 , V_17 ) ;
else
return F_1 ( V_1 , V_2 , L_3 , V_17 , V_17 , L_13 ) ;
}
static T_3
F_33 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
if ( ! V_12 -> V_54 || ! V_13 -> V_54 )
return F_2 ( V_12 -> V_54 , V_13 -> V_54 ) ;
return F_12 ( V_12 -> V_54 -> V_56 . V_19 ,
V_13 -> V_54 -> V_56 . V_19 ) ;
}
static int F_34 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
if ( V_16 -> V_54 )
return F_14 ( V_16 -> V_54 -> V_56 . V_19 ,
V_1 , V_2 , V_17 ) ;
else
return F_1 ( V_1 , V_2 , L_3 , V_17 , V_17 , L_13 ) ;
}
static T_3
F_35 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
struct V_57 * V_58 = & V_12 -> V_54 -> V_55 ;
struct V_57 * V_59 = & V_13 -> V_54 -> V_55 ;
if ( ! V_12 -> V_54 || ! V_13 -> V_54 )
return F_2 ( V_12 -> V_54 , V_13 -> V_54 ) ;
V_58 = & V_12 -> V_54 -> V_55 ;
V_59 = & V_13 -> V_54 -> V_55 ;
if ( ! V_58 -> V_40 && ! V_59 -> V_40 )
return F_16 ( V_58 -> V_60 , V_59 -> V_60 ) ;
return F_17 ( V_58 -> V_40 , V_59 -> V_40 ) ;
}
static T_3
F_36 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
struct V_57 * V_61 , * V_62 ;
if ( ! V_12 -> V_54 || ! V_13 -> V_54 )
return F_2 ( V_12 -> V_54 , V_13 -> V_54 ) ;
V_61 = & V_12 -> V_54 -> V_56 ;
V_62 = & V_13 -> V_54 -> V_56 ;
if ( ! V_61 -> V_40 && ! V_62 -> V_40 )
return F_16 ( V_61 -> V_60 , V_62 -> V_60 ) ;
return F_17 ( V_61 -> V_40 , V_62 -> V_40 ) ;
}
static int F_37 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
if ( V_16 -> V_54 ) {
struct V_57 * V_55 = & V_16 -> V_54 -> V_55 ;
return F_20 ( V_55 -> V_19 , V_55 -> V_40 , V_55 -> V_60 ,
V_16 -> V_44 , V_1 , V_2 , V_17 ) ;
}
return F_1 ( V_1 , V_2 , L_3 , V_17 , V_17 , L_13 ) ;
}
static int F_38 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
if ( V_16 -> V_54 ) {
struct V_57 * V_56 = & V_16 -> V_54 -> V_56 ;
return F_20 ( V_56 -> V_19 , V_56 -> V_40 , V_56 -> V_60 ,
V_16 -> V_44 , V_1 , V_2 , V_17 ) ;
}
return F_1 ( V_1 , V_2 , L_3 , V_17 , V_17 , L_13 ) ;
}
static T_3
F_39 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
unsigned char V_63 , V_64 ;
if ( ! V_12 -> V_54 || ! V_13 -> V_54 )
return F_2 ( V_12 -> V_54 , V_13 -> V_54 ) ;
V_63 = V_12 -> V_54 -> V_65 . V_66 != V_13 -> V_54 -> V_65 . V_66 ;
V_64 = V_12 -> V_54 -> V_65 . V_67 != V_13 -> V_54 -> V_65 . V_67 ;
return V_63 || V_64 ;
}
static int F_40 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 ) {
static const char * V_68 = L_13 ;
if ( V_16 -> V_54 ) {
if ( V_16 -> V_54 -> V_65 . V_67 )
V_68 = L_14 ;
else if ( V_16 -> V_54 -> V_65 . V_66 )
V_68 = L_15 ;
}
return F_1 ( V_1 , V_2 , L_3 , V_17 , V_17 , V_68 ) ;
}
static T_3
F_41 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
T_5 V_9 = 0 , V_10 = 0 ;
if ( V_12 -> V_69 )
V_9 = V_12 -> V_69 -> V_70 . V_60 ;
if ( V_13 -> V_69 )
V_10 = V_13 -> V_69 -> V_70 . V_60 ;
return ( T_3 ) ( V_10 - V_9 ) ;
}
static int F_42 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
T_5 V_60 = 0 ;
struct V_19 * V_19 = NULL ;
struct V_34 * V_40 = NULL ;
if ( V_16 -> V_69 ) {
V_60 = V_16 -> V_69 -> V_70 . V_60 ;
V_19 = V_16 -> V_69 -> V_70 . V_19 ;
V_40 = V_16 -> V_69 -> V_70 . V_40 ;
}
return F_20 ( V_19 , V_40 , V_60 , V_16 -> V_44 , V_1 , V_2 ,
V_17 ) ;
}
static T_3
F_43 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
struct V_19 * V_20 = NULL ;
struct V_19 * V_21 = NULL ;
if ( V_12 -> V_69 )
V_20 = V_12 -> V_69 -> V_70 . V_19 ;
if ( V_13 -> V_69 )
V_21 = V_13 -> V_69 -> V_70 . V_19 ;
return F_12 ( V_20 , V_21 ) ;
}
static int F_44 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
struct V_19 * V_19 = NULL ;
if ( V_16 -> V_69 )
V_19 = V_16 -> V_69 -> V_70 . V_19 ;
return F_14 ( V_19 , V_1 , V_2 , V_17 ) ;
}
static T_3
F_45 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
union V_71 V_72 ;
union V_71 V_73 ;
if ( V_12 -> V_69 )
V_72 = V_12 -> V_69 -> V_74 ;
else
V_72 . V_75 = V_76 ;
if ( V_13 -> V_69 )
V_73 = V_13 -> V_69 -> V_74 ;
else
V_73 . V_75 = V_76 ;
return ( T_3 ) ( V_73 . V_75 - V_72 . V_75 ) ;
}
static int F_46 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
const char * V_68 ;
T_4 V_77 = V_76 ;
if ( V_16 -> V_69 )
V_77 = V_16 -> V_69 -> V_74 . V_75 ;
if ( V_77 & V_76 )
V_68 = L_13 ;
else if ( V_77 & V_78 )
V_68 = L_16 ;
else
V_68 = L_17 ;
return F_1 ( V_1 , V_2 , L_9 , V_17 , V_68 ) ;
}
static T_3
F_47 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
union V_71 V_72 ;
union V_71 V_73 ;
if ( V_12 -> V_69 )
V_72 = V_12 -> V_69 -> V_74 ;
else
V_72 . V_79 = V_80 ;
if ( V_13 -> V_69 )
V_73 = V_13 -> V_69 -> V_74 ;
else
V_73 . V_79 = V_80 ;
return ( T_3 ) ( V_73 . V_79 - V_72 . V_79 ) ;
}
static int F_48 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
char V_68 [ 64 ] ;
T_1 V_81 = sizeof( V_68 ) - 1 ;
T_1 V_9 = 0 , V_82 ;
T_4 V_83 = V_80 ;
T_4 V_84 , V_85 ;
V_68 [ 0 ] = '\0' ;
if ( V_16 -> V_69 )
V_83 = V_16 -> V_69 -> V_74 . V_79 ;
V_84 = V_83 & V_86 ;
V_85 = V_83 & V_87 ;
V_83 &= ~ ( V_86 | V_87 ) ;
for ( V_82 = 0 ; V_83 && V_82 < V_88 ; V_82 ++ , V_83 >>= 1 ) {
if ( ! ( V_83 & 0x1 ) )
continue;
if ( V_9 ) {
strcat ( V_68 , L_18 ) ;
V_9 += 4 ;
}
strncat ( V_68 , V_89 [ V_82 ] , V_81 - V_9 ) ;
V_9 += strlen ( V_89 [ V_82 ] ) ;
}
if ( * V_68 == '\0' )
strcpy ( V_68 , L_13 ) ;
if ( V_84 )
strncat ( V_68 , L_19 , V_81 - V_9 ) ;
if ( V_85 )
strncat ( V_68 , L_20 , V_81 - V_9 ) ;
return F_1 ( V_1 , V_2 , L_9 , V_17 , V_68 ) ;
}
static T_3
F_49 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
union V_71 V_72 ;
union V_71 V_73 ;
if ( V_12 -> V_69 )
V_72 = V_12 -> V_69 -> V_74 ;
else
V_72 . V_90 = V_91 ;
if ( V_13 -> V_69 )
V_73 = V_13 -> V_69 -> V_74 ;
else
V_73 . V_90 = V_91 ;
return ( T_3 ) ( V_73 . V_90 - V_72 . V_90 ) ;
}
static int F_50 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
char V_68 [ 64 ] ;
T_1 V_81 = sizeof( V_68 ) - 1 ;
T_1 V_82 , V_9 = 0 ;
T_4 V_83 = V_91 ;
T_4 V_84 , V_85 ;
if ( V_16 -> V_69 )
V_83 = V_16 -> V_69 -> V_74 . V_90 ;
V_68 [ 0 ] = '\0' ;
V_84 = V_83 & V_92 ;
V_85 = V_83 & V_93 ;
V_83 &= ~ ( V_92 | V_93 ) ;
for ( V_82 = 0 ; V_83 && V_82 < V_94 ; V_82 ++ , V_83 >>= 1 ) {
if ( ! ( V_83 & 0x1 ) )
continue;
if ( V_9 ) {
strcat ( V_68 , L_18 ) ;
V_9 += 4 ;
}
strncat ( V_68 , V_90 [ V_82 ] , V_81 - V_9 ) ;
V_9 += strlen ( V_90 [ V_82 ] ) ;
}
if ( * V_68 == '\0' )
strcpy ( V_68 , L_13 ) ;
if ( V_84 )
strncat ( V_68 , L_19 , V_81 - V_9 ) ;
if ( V_85 )
strncat ( V_68 , L_20 , V_81 - V_9 ) ;
return F_1 ( V_1 , V_2 , L_9 , V_17 , V_68 ) ;
}
static T_3
F_51 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
union V_71 V_72 ;
union V_71 V_73 ;
if ( V_12 -> V_69 )
V_72 = V_12 -> V_69 -> V_74 ;
else
V_72 . V_95 = V_96 ;
if ( V_13 -> V_69 )
V_73 = V_13 -> V_69 -> V_74 ;
else
V_73 . V_95 = V_96 ;
return ( T_3 ) ( V_73 . V_95 - V_72 . V_95 ) ;
}
static int F_52 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
char V_68 [ 64 ] ;
T_1 V_81 = sizeof( V_68 ) - 1 ;
T_1 V_82 , V_9 = 0 ;
T_4 V_83 = V_96 ;
V_68 [ 0 ] = '\0' ;
if ( V_16 -> V_69 )
V_83 = V_16 -> V_69 -> V_74 . V_95 ;
for ( V_82 = 0 ; V_83 && V_82 < V_97 ; V_82 ++ , V_83 >>= 1 ) {
if ( ! ( V_83 & 0x1 ) )
continue;
if ( V_9 ) {
strcat ( V_68 , L_18 ) ;
V_9 += 4 ;
}
strncat ( V_68 , V_98 [ V_82 ] , V_81 - V_9 ) ;
V_9 += strlen ( V_98 [ V_82 ] ) ;
}
if ( * V_68 == '\0' )
strcpy ( V_68 , L_13 ) ;
return F_1 ( V_1 , V_2 , L_9 , V_17 , V_68 ) ;
}
static inline T_4 F_53 ( T_4 V_99 )
{
return ( V_99 & ~ ( V_100 - 1 ) ) ;
}
static T_3
F_54 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
T_4 V_9 , V_10 ;
struct V_19 * V_101 , * V_102 ;
if ( ! V_12 -> V_69 ) return - 1 ;
if ( ! V_13 -> V_69 ) return 1 ;
if ( V_12 -> V_103 > V_13 -> V_103 ) return - 1 ;
if ( V_12 -> V_103 < V_13 -> V_103 ) return 1 ;
V_101 = V_12 -> V_69 -> V_70 . V_19 ;
V_102 = V_13 -> V_69 -> V_70 . V_19 ;
if ( ! V_101 && ! V_102 )
goto V_60;
if ( ! V_101 ) return - 1 ;
if ( ! V_102 ) return 1 ;
if ( V_101 -> V_104 > V_102 -> V_104 ) return - 1 ;
if ( V_101 -> V_104 < V_102 -> V_104 ) return 1 ;
if ( V_101 -> V_105 > V_102 -> V_105 ) return - 1 ;
if ( V_101 -> V_105 < V_102 -> V_105 ) return 1 ;
if ( V_101 -> V_106 > V_102 -> V_106 ) return - 1 ;
if ( V_101 -> V_106 < V_102 -> V_106 ) return 1 ;
if ( V_101 -> V_107 > V_102 -> V_107 ) return - 1 ;
if ( V_101 -> V_107 < V_102 -> V_107 ) return 1 ;
if ( ( V_12 -> V_103 != V_108 ) &&
( ! ( V_101 -> V_65 & V_109 ) ) &&
! V_101 -> V_104 && ! V_101 -> V_105 && ! V_101 -> V_106 &&
! V_101 -> V_107 ) {
if ( V_12 -> V_14 -> V_110 > V_13 -> V_14 -> V_110 ) return - 1 ;
if ( V_12 -> V_14 -> V_110 < V_13 -> V_14 -> V_110 ) return 1 ;
}
V_60:
V_9 = F_53 ( V_12 -> V_69 -> V_70 . V_111 ) ;
V_10 = F_53 ( V_13 -> V_69 -> V_70 . V_111 ) ;
if ( V_9 > V_10 ) return - 1 ;
if ( V_9 < V_10 ) return 1 ;
return 0 ;
}
static int F_55 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
T_5 V_60 = 0 ;
struct V_19 * V_19 = NULL ;
struct V_34 * V_40 = NULL ;
char V_44 = V_16 -> V_44 ;
if ( V_16 -> V_69 ) {
V_60 = F_53 ( V_16 -> V_69 -> V_70 . V_111 ) ;
V_19 = V_16 -> V_69 -> V_70 . V_19 ;
V_40 = V_16 -> V_69 -> V_70 . V_40 ;
if ( ( V_16 -> V_103 != V_108 ) &&
V_19 && ( V_19 -> type == V_47 ) &&
( V_19 -> V_65 & V_109 ) &&
( V_19 -> V_104 || V_19 -> V_105 || V_19 -> V_106 ||
V_19 -> V_107 ) )
V_44 = 's' ;
else if ( ! V_19 )
V_44 = 'X' ;
}
return F_20 ( V_19 , V_40 , V_60 , V_44 , V_1 , V_2 ,
V_17 ) ;
}
static T_4 F_56 ( struct V_11 * V_16 )
{
return V_16 -> V_112 . V_113 ? V_16 -> V_112 . V_114 / V_16 -> V_112 . V_113 : 0 ;
}
static T_3
F_57 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
return F_56 ( V_12 ) - F_56 ( V_13 ) ;
}
static int F_58 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
return F_1 ( V_1 , V_2 , L_21 , V_17 , F_56 ( V_16 ) ) ;
}
static T_3
F_59 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
return V_12 -> V_112 . V_114 - V_13 -> V_112 . V_114 ;
}
static int F_60 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
return F_1 ( V_1 , V_2 , L_21 , V_17 , V_16 -> V_112 . V_114 ) ;
}
static T_3
F_61 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
if ( ! V_12 -> V_54 || ! V_13 -> V_54 )
return F_2 ( V_12 -> V_54 , V_13 -> V_54 ) ;
return V_12 -> V_54 -> V_65 . abort !=
V_13 -> V_54 -> V_65 . abort ;
}
static int F_62 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
static const char * V_68 = L_13 ;
if ( V_16 -> V_54 ) {
if ( V_16 -> V_54 -> V_65 . abort )
V_68 = L_22 ;
else
V_68 = L_23 ;
}
return F_1 ( V_1 , V_2 , L_9 , V_17 , V_68 ) ;
}
static T_3
F_63 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
if ( ! V_12 -> V_54 || ! V_13 -> V_54 )
return F_2 ( V_12 -> V_54 , V_13 -> V_54 ) ;
return V_12 -> V_54 -> V_65 . V_115 !=
V_13 -> V_54 -> V_65 . V_115 ;
}
static int F_64 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
static const char * V_68 = L_13 ;
if ( V_16 -> V_54 ) {
if ( V_16 -> V_54 -> V_65 . V_115 )
V_68 = L_24 ;
else
V_68 = L_23 ;
}
return F_1 ( V_1 , V_2 , L_9 , V_17 , V_68 ) ;
}
static T_3
F_65 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
return V_12 -> V_116 - V_13 -> V_116 ;
}
static inline char * F_66 ( char * V_64 , const char * V_117 )
{
strcpy ( V_64 , V_117 ) ;
return V_64 + strlen ( V_117 ) ;
}
int F_67 ( void )
{
int V_82 ;
int V_49 = 0 ;
for ( V_82 = 0 ; V_118 [ V_82 ] . V_43 ; V_82 ++ ) {
if ( ! V_118 [ V_82 ] . V_119 )
V_49 += strlen ( V_118 [ V_82 ] . V_43 ) ;
}
V_49 += 4 ;
return V_49 ;
}
static int F_68 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
T_4 V_120 = V_16 -> V_116 ;
char V_121 [ 128 ] ;
char * V_64 = V_121 ;
int V_82 ;
V_121 [ 0 ] = 0 ;
for ( V_82 = 0 ; V_118 [ V_82 ] . V_43 ; V_82 ++ )
if ( V_118 [ V_82 ] . V_122 & V_120 )
V_64 = F_66 ( V_64 , V_118 [ V_82 ] . V_43 ) ;
if ( V_120 && ! ( V_120 & ( V_123 | V_124 ) ) )
V_64 = F_66 ( V_64 , L_25 ) ;
if ( V_120 & V_125 ) {
sprintf ( V_64 , L_26 V_126 ,
( V_120 & V_125 ) >>
V_127 ) ;
V_64 += strlen ( V_64 ) ;
}
return F_1 ( V_1 , V_2 , L_9 , V_17 , V_121 ) ;
}
bool F_69 ( struct V_128 * V_129 , struct V_128 * V_130 )
{
struct V_131 * V_132 ;
struct V_131 * V_133 ;
if ( ! F_70 ( V_129 ) || ! F_70 ( V_130 ) )
return false ;
V_132 = F_71 ( V_129 , struct V_131 , V_134 ) ;
V_133 = F_71 ( V_130 , struct V_131 , V_134 ) ;
return V_132 -> V_135 == V_133 -> V_135 ;
}
void F_72 ( struct V_128 * V_3 , struct V_136 * V_136 )
{
struct V_131 * V_137 ;
if ( ! F_70 ( V_3 ) )
return;
V_137 = F_71 ( V_3 , struct V_131 , V_134 ) ;
F_73 ( V_136 , V_137 -> V_135 -> V_138 , strlen ( V_3 -> V_43 ) ) ;
}
static int F_74 ( struct V_128 * V_3 , struct V_139 * V_134 ,
struct V_140 * V_141 )
{
struct V_131 * V_137 ;
T_1 V_49 = V_3 -> V_142 ;
V_137 = F_71 ( V_3 , struct V_131 , V_134 ) ;
if ( ! V_49 )
V_49 = F_75 ( F_76 ( V_141 ) , V_137 -> V_135 -> V_138 ) ;
return F_77 ( V_134 -> V_121 , V_134 -> V_2 , L_3 , V_49 , V_49 , V_3 -> V_43 ) ;
}
static int F_78 ( struct V_128 * V_3 ,
struct V_139 * V_134 V_143 ,
struct V_140 * V_141 )
{
struct V_131 * V_137 ;
T_1 V_49 = V_3 -> V_142 ;
V_137 = F_71 ( V_3 , struct V_131 , V_134 ) ;
if ( ! V_49 )
V_49 = F_75 ( F_76 ( V_141 ) , V_137 -> V_135 -> V_138 ) ;
return V_49 ;
}
static int F_79 ( struct V_128 * V_3 , struct V_139 * V_134 ,
struct V_11 * V_16 )
{
struct V_131 * V_137 ;
T_1 V_49 = V_3 -> V_142 ;
V_137 = F_71 ( V_3 , struct V_131 , V_134 ) ;
if ( ! V_49 )
V_49 = F_75 ( V_16 -> V_136 , V_137 -> V_135 -> V_138 ) ;
return V_137 -> V_135 -> V_144 ( V_16 , V_134 -> V_121 , V_134 -> V_2 , V_49 ) ;
}
static T_3 F_80 ( struct V_128 * V_3 ,
struct V_11 * V_129 , struct V_11 * V_130 )
{
struct V_131 * V_137 ;
V_137 = F_71 ( V_3 , struct V_131 , V_134 ) ;
return V_137 -> V_135 -> V_145 ( V_129 , V_130 ) ;
}
static T_3 F_81 ( struct V_128 * V_3 ,
struct V_11 * V_129 , struct V_11 * V_130 )
{
struct V_131 * V_137 ;
T_3 (* F_82)( struct V_11 * , struct V_11 * );
V_137 = F_71 ( V_3 , struct V_131 , V_134 ) ;
F_82 = V_137 -> V_135 -> V_146 ? : V_137 -> V_135 -> V_145 ;
return F_82 ( V_129 , V_130 ) ;
}
static T_3 F_83 ( struct V_128 * V_3 ,
struct V_11 * V_129 , struct V_11 * V_130 )
{
struct V_131 * V_137 ;
T_3 (* F_84)( struct V_11 * , struct V_11 * );
V_137 = F_71 ( V_3 , struct V_131 , V_134 ) ;
F_84 = V_137 -> V_135 -> V_147 ? : V_137 -> V_135 -> V_145 ;
return F_84 ( V_129 , V_130 ) ;
}
static struct V_131 *
F_85 ( struct V_148 * V_149 )
{
struct V_131 * V_137 ;
V_137 = malloc ( sizeof( * V_137 ) ) ;
if ( V_137 == NULL ) {
F_86 ( L_27 ) ;
return NULL ;
}
V_137 -> V_135 = V_149 -> V_150 ;
V_137 -> V_134 . V_43 = V_149 -> V_150 -> V_151 ;
V_137 -> V_134 . V_152 = F_74 ;
V_137 -> V_134 . V_17 = F_78 ;
V_137 -> V_134 . V_150 = F_79 ;
V_137 -> V_134 . V_153 = NULL ;
V_137 -> V_134 . V_154 = F_80 ;
V_137 -> V_134 . V_155 = F_81 ;
V_137 -> V_134 . V_156 = F_83 ;
F_87 ( & V_137 -> V_134 . V_157 ) ;
F_87 ( & V_137 -> V_134 . V_158 ) ;
V_137 -> V_134 . V_159 = false ;
V_137 -> V_134 . V_49 = 0 ;
V_137 -> V_134 . V_142 = 0 ;
return V_137 ;
}
bool F_70 ( struct V_128 * V_160 )
{
return V_160 -> V_152 == F_74 ;
}
static int F_88 ( struct V_148 * V_149 )
{
struct V_131 * V_137 = F_85 ( V_149 ) ;
if ( V_137 == NULL )
return - 1 ;
F_89 ( & V_137 -> V_134 ) ;
return 0 ;
}
static int F_90 ( struct V_148 * V_149 )
{
struct V_131 * V_137 = F_85 ( V_149 ) ;
if ( V_137 == NULL )
return - 1 ;
F_91 ( & V_137 -> V_134 ) ;
return 0 ;
}
static int F_92 ( struct V_148 * V_149 )
{
if ( V_149 -> V_161 )
return 0 ;
if ( F_88 ( V_149 ) < 0 )
return - 1 ;
if ( V_149 -> V_150 -> V_146 )
V_162 = 1 ;
V_149 -> V_161 = 1 ;
return 0 ;
}
static int F_93 ( struct V_163 * V_164 )
{
if ( ! V_164 -> V_161 ) {
V_164 -> V_161 = 1 ;
F_89 ( V_164 -> V_3 ) ;
}
return 0 ;
}
static int F_94 ( struct V_148 * V_149 )
{
if ( V_149 -> V_161 )
return 0 ;
if ( F_90 ( V_149 ) < 0 )
return - 1 ;
V_149 -> V_161 = 1 ;
return 0 ;
}
static int F_95 ( struct V_163 * V_164 )
{
if ( ! V_164 -> V_161 ) {
V_164 -> V_161 = 1 ;
F_91 ( V_164 -> V_3 ) ;
}
return 0 ;
}
int F_96 ( const char * V_165 )
{
unsigned int V_82 ;
for ( V_82 = 0 ; V_82 < F_97 ( V_166 ) ; V_82 ++ ) {
struct V_148 * V_149 = & V_166 [ V_82 ] ;
if ( strncasecmp ( V_165 , V_149 -> V_43 , strlen ( V_165 ) ) )
continue;
if ( V_149 -> V_150 == & V_167 ) {
int V_39 = regcomp ( & V_168 , V_169 , V_170 ) ;
if ( V_39 ) {
char V_171 [ V_172 ] ;
regerror ( V_39 , & V_168 , V_171 , sizeof( V_171 ) ) ;
F_86 ( L_28 , V_169 , V_171 ) ;
return - V_173 ;
}
V_174 = 1 ;
} else if ( V_149 -> V_150 == & V_175 ) {
V_176 = 1 ;
if ( V_177 == V_178 )
V_149 -> V_150 -> V_146 = F_19 ;
} else if ( V_149 -> V_150 == & V_179 ) {
V_42 = 1 ;
}
return F_92 ( V_149 ) ;
}
for ( V_82 = 0 ; V_82 < F_97 ( V_180 ) ; V_82 ++ ) {
struct V_163 * V_164 = & V_180 [ V_82 ] ;
if ( strncasecmp ( V_165 , V_164 -> V_43 , strlen ( V_165 ) ) )
continue;
return F_93 ( V_164 ) ;
}
for ( V_82 = 0 ; V_82 < F_97 ( V_181 ) ; V_82 ++ ) {
struct V_148 * V_149 = & V_181 [ V_82 ] ;
if ( strncasecmp ( V_165 , V_149 -> V_43 , strlen ( V_165 ) ) )
continue;
if ( V_177 != V_182 )
return - V_173 ;
if ( V_149 -> V_150 == & V_183 || V_149 -> V_150 == & V_184 )
V_176 = 1 ;
F_92 ( V_149 ) ;
return 0 ;
}
for ( V_82 = 0 ; V_82 < F_97 ( V_185 ) ; V_82 ++ ) {
struct V_148 * V_149 = & V_185 [ V_82 ] ;
if ( strncasecmp ( V_165 , V_149 -> V_43 , strlen ( V_165 ) ) )
continue;
if ( V_177 != V_186 )
return - V_173 ;
if ( V_149 -> V_150 == & V_187 )
V_176 = 1 ;
F_92 ( V_149 ) ;
return 0 ;
}
return - V_188 ;
}
static const char * F_98 ( void )
{
const char * V_189 [] = {
V_190 ,
V_191 ,
V_192 ,
V_193 ,
V_194 ,
} ;
F_99 ( V_177 >= F_97 ( V_189 ) ) ;
return V_189 [ V_177 ] ;
}
static int F_100 ( void )
{
char * V_195 ;
if ( ! V_196 || F_101 ( V_196 ) )
return 0 ;
if ( V_196 [ 1 ] == '\0' ) {
error ( L_29 ) ;
return - V_173 ;
}
if ( F_102 ( & V_195 , L_30 ,
F_98 () , V_196 + 1 ) < 0 ) {
error ( L_31 ) ;
return - V_197 ;
}
V_196 = V_195 ;
return 0 ;
}
static int F_103 ( void )
{
char * V_198 , * V_165 , * V_117 ;
const char * V_199 ;
int V_39 = 0 ;
V_39 = F_100 () ;
if ( V_39 )
return V_39 ;
V_199 = V_196 ;
if ( V_199 == NULL ) {
if ( F_101 ( V_200 ) ) {
return 0 ;
}
V_199 = F_98 () ;
}
V_117 = F_104 ( V_199 ) ;
if ( V_117 == NULL ) {
error ( L_32 ) ;
return - V_197 ;
}
for ( V_165 = strtok_r ( V_117 , L_33 , & V_198 ) ;
V_165 ; V_165 = strtok_r ( NULL , L_33 , & V_198 ) ) {
V_39 = F_96 ( V_165 ) ;
if ( V_39 == - V_173 ) {
error ( L_34 , V_165 ) ;
break;
} else if ( V_39 == - V_188 ) {
error ( L_35 , V_165 ) ;
break;
}
}
free ( V_117 ) ;
return V_39 ;
}
void F_105 ( int V_201 , bool V_159 )
{
struct V_128 * V_3 ;
struct V_131 * V_137 ;
F_106 (fmt) {
if ( ! F_70 ( V_3 ) )
continue;
V_137 = F_71 ( V_3 , struct V_131 , V_134 ) ;
if ( V_137 -> V_135 -> V_138 == V_201 ) {
V_3 -> V_159 = V_159 ;
break;
}
}
}
static bool F_107 ( struct V_202 * V_157 , const char * V_203 , T_6 * V_204 )
{
if ( V_157 && F_108 ( V_157 ) == 1 ) {
if ( V_204 != NULL )
fprintf ( V_204 , L_36 , V_203 ,
F_109 ( V_157 , 0 ) -> V_205 ) ;
return true ;
}
return false ;
}
static bool F_110 ( int V_201 , T_6 * V_206 )
{
switch ( V_201 ) {
case V_207 :
return F_107 ( V_6 . V_208 , L_37 , V_206 ) ;
case V_209 :
return F_107 ( V_6 . V_210 , L_38 , V_206 ) ;
case V_211 :
return F_107 ( V_6 . V_212 , L_39 , V_206 ) ;
default:
break;
}
if ( V_177 != V_182 )
return false ;
switch ( V_201 ) {
case V_213 :
return F_107 ( V_6 . V_214 , L_40 , V_206 ) ;
case V_215 :
return F_107 ( V_6 . V_216 , L_41 , V_206 ) ;
case V_217 :
return F_107 ( V_6 . V_218 , L_42 , V_206 ) ;
case V_219 :
return F_107 ( V_6 . V_220 , L_43 , V_206 ) ;
default:
break;
}
return false ;
}
void F_111 ( T_6 * V_206 )
{
struct V_128 * V_3 ;
struct V_131 * V_137 ;
F_106 (fmt) {
if ( ! F_70 ( V_3 ) )
continue;
V_137 = F_71 ( V_3 , struct V_131 , V_134 ) ;
V_3 -> V_159 = F_110 ( V_137 -> V_135 -> V_138 , V_206 ) ;
}
F_106 (fmt) {
if ( ! F_70 ( V_3 ) )
continue;
if ( ! V_3 -> V_159 )
return;
}
F_106 (fmt) {
if ( ! F_70 ( V_3 ) )
continue;
V_3 -> V_159 = false ;
}
}
static int F_112 ( char * V_165 )
{
unsigned int V_82 ;
for ( V_82 = 0 ; V_82 < F_97 ( V_166 ) ; V_82 ++ ) {
struct V_148 * V_149 = & V_166 [ V_82 ] ;
if ( strncasecmp ( V_165 , V_149 -> V_43 , strlen ( V_165 ) ) )
continue;
return F_94 ( V_149 ) ;
}
for ( V_82 = 0 ; V_82 < F_97 ( V_180 ) ; V_82 ++ ) {
struct V_163 * V_164 = & V_180 [ V_82 ] ;
if ( strncasecmp ( V_165 , V_164 -> V_43 , strlen ( V_165 ) ) )
continue;
return F_95 ( V_164 ) ;
}
for ( V_82 = 0 ; V_82 < F_97 ( V_181 ) ; V_82 ++ ) {
struct V_148 * V_149 = & V_181 [ V_82 ] ;
if ( strncasecmp ( V_165 , V_149 -> V_43 , strlen ( V_165 ) ) )
continue;
return F_94 ( V_149 ) ;
}
for ( V_82 = 0 ; V_82 < F_97 ( V_185 ) ; V_82 ++ ) {
struct V_148 * V_149 = & V_185 [ V_82 ] ;
if ( strncasecmp ( V_165 , V_149 -> V_43 , strlen ( V_165 ) ) )
continue;
return F_94 ( V_149 ) ;
}
return - V_188 ;
}
static void F_113 ( void )
{
unsigned int V_82 ;
for ( V_82 = 0 ; V_82 < F_97 ( V_166 ) ; V_82 ++ )
V_166 [ V_82 ] . V_161 = 0 ;
for ( V_82 = 0 ; V_82 < F_97 ( V_180 ) ; V_82 ++ )
V_180 [ V_82 ] . V_161 = 0 ;
for ( V_82 = 0 ; V_82 < F_97 ( V_181 ) ; V_82 ++ )
V_181 [ V_82 ] . V_161 = 0 ;
for ( V_82 = 0 ; V_82 < F_97 ( V_185 ) ; V_82 ++ )
V_185 [ V_82 ] . V_161 = 0 ;
}
bool F_101 ( const char * V_221 )
{
return V_221 && ( * V_221 != '+' ) ;
}
static int F_114 ( void )
{
char * V_198 , * V_165 , * V_117 , * V_222 ;
int V_39 = - V_173 ;
if ( V_200 == NULL )
return 0 ;
F_113 () ;
V_222 = V_117 = F_104 ( V_200 ) ;
if ( V_117 == NULL ) {
error ( L_44 ) ;
return - V_197 ;
}
if ( ! F_101 ( V_200 ) )
V_222 ++ ;
if ( ! strlen ( V_222 ) ) {
error ( L_45 ) ;
goto V_68;
}
for ( V_165 = strtok_r ( V_222 , L_33 , & V_198 ) ;
V_165 ; V_165 = strtok_r ( NULL , L_33 , & V_198 ) ) {
V_39 = F_112 ( V_165 ) ;
if ( V_39 == - V_173 ) {
error ( L_46 , V_165 ) ;
break;
} else if ( V_39 == - V_188 ) {
error ( L_47 , V_165 ) ;
break;
}
}
V_68:
free ( V_117 ) ;
return V_39 ;
}
int F_115 ( void )
{
int V_171 ;
V_171 = F_103 () ;
if ( V_171 < 0 )
return V_171 ;
if ( V_169 != V_223 ) {
V_171 = F_96 ( L_48 ) ;
if ( V_171 < 0 )
return V_171 ;
}
F_113 () ;
if ( V_177 != V_178 )
F_116 () ;
V_171 = F_114 () ;
if ( V_171 < 0 )
return V_171 ;
F_117 () ;
F_118 () ;
return 0 ;
}
void F_119 ( void )
{
V_162 = 0 ;
V_174 = 0 ;
V_176 = 0 ;
V_42 = 0 ;
V_200 = NULL ;
V_196 = NULL ;
F_113 () ;
F_120 () ;
}
