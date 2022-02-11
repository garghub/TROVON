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
return F_8 ( V_13 -> V_18 ) - F_8 ( V_12 -> V_18 ) ;
}
static T_3
F_9 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
return F_8 ( V_13 -> V_18 ) - F_8 ( V_12 -> V_18 ) ;
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
T_4 V_37 , V_38 ;
if ( ! V_35 || ! V_36 )
return F_2 ( V_35 , V_36 ) ;
if ( V_35 == V_36 )
return 0 ;
V_37 = V_35 -> V_39 ;
V_38 = V_36 -> V_39 ;
return ( T_3 ) ( V_38 - V_37 ) ;
}
static T_3
F_18 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
T_3 V_40 ;
if ( ! V_12 -> V_30 . V_41 && ! V_13 -> V_30 . V_41 )
return F_16 ( V_12 -> V_42 , V_13 -> V_42 ) ;
if ( ! V_43 ) {
V_40 = F_13 ( V_12 , V_13 ) ;
if ( V_40 != 0 )
return V_40 ;
}
return F_17 ( V_12 -> V_30 . V_41 , V_13 -> V_30 . V_41 ) ;
}
static T_3
F_19 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
if ( ! V_12 -> V_30 . V_41 || ! V_13 -> V_30 . V_41 )
return F_2 ( V_12 -> V_30 . V_41 , V_13 -> V_30 . V_41 ) ;
return strcmp ( V_13 -> V_30 . V_41 -> V_44 , V_12 -> V_30 . V_41 -> V_44 ) ;
}
static int F_20 ( struct V_19 * V_19 , struct V_34 * V_41 ,
T_4 V_42 , char V_45 , char * V_1 , T_1 V_2 ,
unsigned int V_17 )
{
T_1 V_40 = 0 ;
if ( V_27 ) {
char V_46 = V_19 ? F_21 ( V_19 -> V_22 ) : '!' ;
V_40 += F_1 ( V_1 , V_2 , L_5 ,
V_47 / 4 + 2 , V_42 , V_46 ) ;
}
V_40 += F_1 ( V_1 + V_40 , V_2 - V_40 , L_6 , V_45 ) ;
if ( V_41 && V_19 ) {
if ( V_19 -> type == V_48 ) {
V_40 += F_1 ( V_1 + V_40 , V_2 - V_40 , L_7 , V_41 -> V_44 ) ;
V_40 += F_1 ( V_1 + V_40 , V_2 - V_40 , L_8 ,
V_42 - V_19 -> V_49 ( V_19 , V_41 -> V_39 ) ) ;
V_40 += F_1 ( V_1 + V_40 , V_2 - V_40 , L_9 ,
V_17 - V_40 , L_2 ) ;
} else {
V_40 += F_1 ( V_1 + V_40 , V_2 - V_40 , L_9 ,
V_17 - V_40 ,
V_41 -> V_44 ) ;
}
} else {
T_1 V_50 = V_47 / 4 ;
V_40 += F_1 ( V_1 + V_40 , V_2 - V_40 , L_10 ,
V_50 , V_42 ) ;
V_40 += F_1 ( V_1 + V_40 , V_2 - V_40 , L_9 ,
V_17 - V_40 , L_2 ) ;
}
if ( V_40 > V_17 )
V_1 [ V_17 ] = '\0' ;
return V_17 ;
}
static int F_22 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
return F_20 ( V_16 -> V_30 . V_19 , V_16 -> V_30 . V_41 , V_16 -> V_42 ,
V_16 -> V_45 , V_1 , V_2 , V_17 ) ;
}
static T_3
F_23 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
if ( ! V_12 -> V_51 ) {
if ( ! V_12 -> V_30 . V_19 )
V_12 -> V_51 = V_52 ;
else {
struct V_19 * V_19 = V_12 -> V_30 . V_19 ;
V_12 -> V_51 = F_24 ( V_19 -> V_22 ,
F_25 ( V_19 , V_12 -> V_42 ) ,
V_12 -> V_30 . V_41 , true ) ;
}
}
if ( ! V_13 -> V_51 ) {
if ( ! V_13 -> V_30 . V_19 )
V_13 -> V_51 = V_52 ;
else {
struct V_19 * V_19 = V_13 -> V_30 . V_19 ;
V_13 -> V_51 = F_24 ( V_19 -> V_22 ,
F_25 ( V_19 , V_13 -> V_42 ) ,
V_13 -> V_30 . V_41 , true ) ;
}
}
return strcmp ( V_13 -> V_51 , V_12 -> V_51 ) ;
}
static int F_26 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
return F_1 ( V_1 , V_2 , L_3 , V_17 , V_17 , V_16 -> V_51 ) ;
}
static T_3
F_27 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
struct V_34 * V_35 = V_12 -> V_53 ;
struct V_34 * V_36 = V_13 -> V_53 ;
if ( ! V_35 || ! V_36 )
return F_2 ( V_35 , V_36 ) ;
return strcmp ( V_36 -> V_44 , V_35 -> V_44 ) ;
}
static int F_28 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
return F_1 ( V_1 , V_2 , L_3 , V_17 , V_17 ,
V_16 -> V_53 ? V_16 -> V_53 -> V_44 : L_11 ) ;
}
static T_3
F_29 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
return V_13 -> V_54 - V_12 -> V_54 ;
}
static int F_30 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
return F_1 ( V_1 , V_2 , L_12 , V_17 , V_17 , V_16 -> V_54 ) ;
}
static T_3
F_31 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
if ( ! V_12 -> V_55 || ! V_13 -> V_55 )
return F_2 ( V_12 -> V_55 , V_13 -> V_55 ) ;
return F_12 ( V_12 -> V_55 -> V_56 . V_19 ,
V_13 -> V_55 -> V_56 . V_19 ) ;
}
static int F_32 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
if ( V_16 -> V_55 )
return F_14 ( V_16 -> V_55 -> V_56 . V_19 ,
V_1 , V_2 , V_17 ) ;
else
return F_1 ( V_1 , V_2 , L_3 , V_17 , V_17 , L_13 ) ;
}
static T_3
F_33 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
if ( ! V_12 -> V_55 || ! V_13 -> V_55 )
return F_2 ( V_12 -> V_55 , V_13 -> V_55 ) ;
return F_12 ( V_12 -> V_55 -> V_57 . V_19 ,
V_13 -> V_55 -> V_57 . V_19 ) ;
}
static int F_34 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
if ( V_16 -> V_55 )
return F_14 ( V_16 -> V_55 -> V_57 . V_19 ,
V_1 , V_2 , V_17 ) ;
else
return F_1 ( V_1 , V_2 , L_3 , V_17 , V_17 , L_13 ) ;
}
static T_3
F_35 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
struct V_58 * V_59 = & V_12 -> V_55 -> V_56 ;
struct V_58 * V_60 = & V_13 -> V_55 -> V_56 ;
if ( ! V_12 -> V_55 || ! V_13 -> V_55 )
return F_2 ( V_12 -> V_55 , V_13 -> V_55 ) ;
V_59 = & V_12 -> V_55 -> V_56 ;
V_60 = & V_13 -> V_55 -> V_56 ;
if ( ! V_59 -> V_41 && ! V_60 -> V_41 )
return F_16 ( V_59 -> V_61 , V_60 -> V_61 ) ;
return F_17 ( V_59 -> V_41 , V_60 -> V_41 ) ;
}
static T_3
F_36 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
struct V_58 * V_62 , * V_63 ;
if ( ! V_12 -> V_55 || ! V_13 -> V_55 )
return F_2 ( V_12 -> V_55 , V_13 -> V_55 ) ;
V_62 = & V_12 -> V_55 -> V_57 ;
V_63 = & V_13 -> V_55 -> V_57 ;
if ( ! V_62 -> V_41 && ! V_63 -> V_41 )
return F_16 ( V_62 -> V_61 , V_63 -> V_61 ) ;
return F_17 ( V_62 -> V_41 , V_63 -> V_41 ) ;
}
static int F_37 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
if ( V_16 -> V_55 ) {
struct V_58 * V_56 = & V_16 -> V_55 -> V_56 ;
return F_20 ( V_56 -> V_19 , V_56 -> V_41 , V_56 -> V_61 ,
V_16 -> V_45 , V_1 , V_2 , V_17 ) ;
}
return F_1 ( V_1 , V_2 , L_3 , V_17 , V_17 , L_13 ) ;
}
static int F_38 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
if ( V_16 -> V_55 ) {
struct V_58 * V_57 = & V_16 -> V_55 -> V_57 ;
return F_20 ( V_57 -> V_19 , V_57 -> V_41 , V_57 -> V_61 ,
V_16 -> V_45 , V_1 , V_2 , V_17 ) ;
}
return F_1 ( V_1 , V_2 , L_3 , V_17 , V_17 , L_13 ) ;
}
static T_3
F_39 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
unsigned char V_64 , V_65 ;
if ( ! V_12 -> V_55 || ! V_13 -> V_55 )
return F_2 ( V_12 -> V_55 , V_13 -> V_55 ) ;
V_64 = V_12 -> V_55 -> V_66 . V_67 != V_13 -> V_55 -> V_66 . V_67 ;
V_65 = V_12 -> V_55 -> V_66 . V_68 != V_13 -> V_55 -> V_66 . V_68 ;
return V_64 || V_65 ;
}
static int F_40 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 ) {
static const char * V_69 = L_13 ;
if ( V_16 -> V_55 ) {
if ( V_16 -> V_55 -> V_66 . V_68 )
V_69 = L_14 ;
else if ( V_16 -> V_55 -> V_66 . V_67 )
V_69 = L_15 ;
}
return F_1 ( V_1 , V_2 , L_3 , V_17 , V_17 , V_69 ) ;
}
static T_3
F_41 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
T_5 V_9 = 0 , V_10 = 0 ;
if ( V_12 -> V_70 )
V_9 = V_12 -> V_70 -> V_71 . V_61 ;
if ( V_13 -> V_70 )
V_10 = V_13 -> V_70 -> V_71 . V_61 ;
return ( T_3 ) ( V_10 - V_9 ) ;
}
static int F_42 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
T_5 V_61 = 0 ;
struct V_19 * V_19 = NULL ;
struct V_34 * V_41 = NULL ;
if ( V_16 -> V_70 ) {
V_61 = V_16 -> V_70 -> V_71 . V_61 ;
V_19 = V_16 -> V_70 -> V_71 . V_19 ;
V_41 = V_16 -> V_70 -> V_71 . V_41 ;
}
return F_20 ( V_19 , V_41 , V_61 , V_16 -> V_45 , V_1 , V_2 ,
V_17 ) ;
}
static T_3
F_43 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
struct V_19 * V_20 = NULL ;
struct V_19 * V_21 = NULL ;
if ( V_12 -> V_70 )
V_20 = V_12 -> V_70 -> V_71 . V_19 ;
if ( V_13 -> V_70 )
V_21 = V_13 -> V_70 -> V_71 . V_19 ;
return F_12 ( V_20 , V_21 ) ;
}
static int F_44 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
struct V_19 * V_19 = NULL ;
if ( V_16 -> V_70 )
V_19 = V_16 -> V_70 -> V_71 . V_19 ;
return F_14 ( V_19 , V_1 , V_2 , V_17 ) ;
}
static T_3
F_45 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
union V_72 V_73 ;
union V_72 V_74 ;
if ( V_12 -> V_70 )
V_73 = V_12 -> V_70 -> V_75 ;
else
V_73 . V_76 = V_77 ;
if ( V_13 -> V_70 )
V_74 = V_13 -> V_70 -> V_75 ;
else
V_74 . V_76 = V_77 ;
return ( T_3 ) ( V_74 . V_76 - V_73 . V_76 ) ;
}
static int F_46 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
const char * V_69 ;
T_4 V_78 = V_77 ;
if ( V_16 -> V_70 )
V_78 = V_16 -> V_70 -> V_75 . V_76 ;
if ( V_78 & V_77 )
V_69 = L_13 ;
else if ( V_78 & V_79 )
V_69 = L_16 ;
else
V_69 = L_17 ;
return F_1 ( V_1 , V_2 , L_9 , V_17 , V_69 ) ;
}
static T_3
F_47 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
union V_72 V_73 ;
union V_72 V_74 ;
if ( V_12 -> V_70 )
V_73 = V_12 -> V_70 -> V_75 ;
else
V_73 . V_80 = V_81 ;
if ( V_13 -> V_70 )
V_74 = V_13 -> V_70 -> V_75 ;
else
V_74 . V_80 = V_81 ;
return ( T_3 ) ( V_74 . V_80 - V_73 . V_80 ) ;
}
static int F_48 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
char V_69 [ 64 ] ;
T_1 V_82 = sizeof( V_69 ) - 1 ;
T_1 V_9 = 0 , V_83 ;
T_4 V_84 = V_81 ;
T_4 V_85 , V_86 ;
V_69 [ 0 ] = '\0' ;
if ( V_16 -> V_70 )
V_84 = V_16 -> V_70 -> V_75 . V_80 ;
V_85 = V_84 & V_87 ;
V_86 = V_84 & V_88 ;
V_84 &= ~ ( V_87 | V_88 ) ;
for ( V_83 = 0 ; V_84 && V_83 < V_89 ; V_83 ++ , V_84 >>= 1 ) {
if ( ! ( V_84 & 0x1 ) )
continue;
if ( V_9 ) {
strcat ( V_69 , L_18 ) ;
V_9 += 4 ;
}
strncat ( V_69 , V_90 [ V_83 ] , V_82 - V_9 ) ;
V_9 += strlen ( V_90 [ V_83 ] ) ;
}
if ( * V_69 == '\0' )
strcpy ( V_69 , L_13 ) ;
if ( V_85 )
strncat ( V_69 , L_19 , V_82 - V_9 ) ;
if ( V_86 )
strncat ( V_69 , L_20 , V_82 - V_9 ) ;
return F_1 ( V_1 , V_2 , L_9 , V_17 , V_69 ) ;
}
static T_3
F_49 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
union V_72 V_73 ;
union V_72 V_74 ;
if ( V_12 -> V_70 )
V_73 = V_12 -> V_70 -> V_75 ;
else
V_73 . V_91 = V_92 ;
if ( V_13 -> V_70 )
V_74 = V_13 -> V_70 -> V_75 ;
else
V_74 . V_91 = V_92 ;
return ( T_3 ) ( V_74 . V_91 - V_73 . V_91 ) ;
}
static int F_50 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
char V_69 [ 64 ] ;
T_1 V_82 = sizeof( V_69 ) - 1 ;
T_1 V_83 , V_9 = 0 ;
T_4 V_84 = V_92 ;
T_4 V_85 , V_86 ;
if ( V_16 -> V_70 )
V_84 = V_16 -> V_70 -> V_75 . V_91 ;
V_69 [ 0 ] = '\0' ;
V_85 = V_84 & V_93 ;
V_86 = V_84 & V_94 ;
V_84 &= ~ ( V_93 | V_94 ) ;
for ( V_83 = 0 ; V_84 && V_83 < V_95 ; V_83 ++ , V_84 >>= 1 ) {
if ( ! ( V_84 & 0x1 ) )
continue;
if ( V_9 ) {
strcat ( V_69 , L_18 ) ;
V_9 += 4 ;
}
strncat ( V_69 , V_91 [ V_83 ] , V_82 - V_9 ) ;
V_9 += strlen ( V_91 [ V_83 ] ) ;
}
if ( * V_69 == '\0' )
strcpy ( V_69 , L_13 ) ;
if ( V_85 )
strncat ( V_69 , L_19 , V_82 - V_9 ) ;
if ( V_86 )
strncat ( V_69 , L_20 , V_82 - V_9 ) ;
return F_1 ( V_1 , V_2 , L_9 , V_17 , V_69 ) ;
}
static T_3
F_51 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
union V_72 V_73 ;
union V_72 V_74 ;
if ( V_12 -> V_70 )
V_73 = V_12 -> V_70 -> V_75 ;
else
V_73 . V_96 = V_97 ;
if ( V_13 -> V_70 )
V_74 = V_13 -> V_70 -> V_75 ;
else
V_74 . V_96 = V_97 ;
return ( T_3 ) ( V_74 . V_96 - V_73 . V_96 ) ;
}
static int F_52 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
char V_69 [ 64 ] ;
T_1 V_82 = sizeof( V_69 ) - 1 ;
T_1 V_83 , V_9 = 0 ;
T_4 V_84 = V_97 ;
V_69 [ 0 ] = '\0' ;
if ( V_16 -> V_70 )
V_84 = V_16 -> V_70 -> V_75 . V_96 ;
for ( V_83 = 0 ; V_84 && V_83 < V_98 ; V_83 ++ , V_84 >>= 1 ) {
if ( ! ( V_84 & 0x1 ) )
continue;
if ( V_9 ) {
strcat ( V_69 , L_18 ) ;
V_9 += 4 ;
}
strncat ( V_69 , V_99 [ V_83 ] , V_82 - V_9 ) ;
V_9 += strlen ( V_99 [ V_83 ] ) ;
}
if ( * V_69 == '\0' )
strcpy ( V_69 , L_13 ) ;
return F_1 ( V_1 , V_2 , L_9 , V_17 , V_69 ) ;
}
static inline T_4 F_53 ( T_4 V_100 )
{
return ( V_100 & ~ ( V_101 - 1 ) ) ;
}
static T_3
F_54 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
T_4 V_9 , V_10 ;
struct V_19 * V_102 , * V_103 ;
if ( ! V_12 -> V_70 ) return - 1 ;
if ( ! V_13 -> V_70 ) return 1 ;
if ( V_12 -> V_104 > V_13 -> V_104 ) return - 1 ;
if ( V_12 -> V_104 < V_13 -> V_104 ) return 1 ;
V_102 = V_12 -> V_70 -> V_71 . V_19 ;
V_103 = V_13 -> V_70 -> V_71 . V_19 ;
if ( ! V_102 && ! V_103 )
goto V_61;
if ( ! V_102 ) return - 1 ;
if ( ! V_103 ) return 1 ;
if ( V_102 -> V_105 > V_103 -> V_105 ) return - 1 ;
if ( V_102 -> V_105 < V_103 -> V_105 ) return 1 ;
if ( V_102 -> V_106 > V_103 -> V_106 ) return - 1 ;
if ( V_102 -> V_106 < V_103 -> V_106 ) return 1 ;
if ( V_102 -> V_107 > V_103 -> V_107 ) return - 1 ;
if ( V_102 -> V_107 < V_103 -> V_107 ) return 1 ;
if ( V_102 -> V_108 > V_103 -> V_108 ) return - 1 ;
if ( V_102 -> V_108 < V_103 -> V_108 ) return 1 ;
if ( ( V_12 -> V_104 != V_109 ) &&
( ! ( V_102 -> V_66 & V_110 ) ) &&
! V_102 -> V_105 && ! V_102 -> V_106 && ! V_102 -> V_107 &&
! V_102 -> V_108 ) {
if ( V_12 -> V_14 -> V_111 > V_13 -> V_14 -> V_111 ) return - 1 ;
if ( V_12 -> V_14 -> V_111 < V_13 -> V_14 -> V_111 ) return 1 ;
}
V_61:
V_9 = F_53 ( V_12 -> V_70 -> V_71 . V_112 ) ;
V_10 = F_53 ( V_13 -> V_70 -> V_71 . V_112 ) ;
if ( V_9 > V_10 ) return - 1 ;
if ( V_9 < V_10 ) return 1 ;
return 0 ;
}
static int F_55 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
T_5 V_61 = 0 ;
struct V_19 * V_19 = NULL ;
struct V_34 * V_41 = NULL ;
char V_45 = V_16 -> V_45 ;
if ( V_16 -> V_70 ) {
V_61 = F_53 ( V_16 -> V_70 -> V_71 . V_112 ) ;
V_19 = V_16 -> V_70 -> V_71 . V_19 ;
V_41 = V_16 -> V_70 -> V_71 . V_41 ;
if ( ( V_16 -> V_104 != V_109 ) &&
V_19 && ( V_19 -> type == V_48 ) &&
( V_19 -> V_66 & V_110 ) &&
( V_19 -> V_105 || V_19 -> V_106 || V_19 -> V_107 ||
V_19 -> V_108 ) )
V_45 = 's' ;
else if ( ! V_19 )
V_45 = 'X' ;
}
return F_20 ( V_19 , V_41 , V_61 , V_45 , V_1 , V_2 ,
V_17 ) ;
}
static T_4 F_56 ( struct V_11 * V_16 )
{
return V_16 -> V_113 . V_114 ? V_16 -> V_113 . V_115 / V_16 -> V_113 . V_114 : 0 ;
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
return V_12 -> V_113 . V_115 - V_13 -> V_113 . V_115 ;
}
static int F_60 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
return F_1 ( V_1 , V_2 , L_21 , V_17 , V_16 -> V_113 . V_115 ) ;
}
static T_3
F_61 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
if ( ! V_12 -> V_55 || ! V_13 -> V_55 )
return F_2 ( V_12 -> V_55 , V_13 -> V_55 ) ;
return V_12 -> V_55 -> V_66 . abort !=
V_13 -> V_55 -> V_66 . abort ;
}
static int F_62 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
static const char * V_69 = L_13 ;
if ( V_16 -> V_55 ) {
if ( V_16 -> V_55 -> V_66 . abort )
V_69 = L_22 ;
else
V_69 = L_23 ;
}
return F_1 ( V_1 , V_2 , L_9 , V_17 , V_69 ) ;
}
static T_3
F_63 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
if ( ! V_12 -> V_55 || ! V_13 -> V_55 )
return F_2 ( V_12 -> V_55 , V_13 -> V_55 ) ;
return V_12 -> V_55 -> V_66 . V_116 !=
V_13 -> V_55 -> V_66 . V_116 ;
}
static int F_64 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
static const char * V_69 = L_13 ;
if ( V_16 -> V_55 ) {
if ( V_16 -> V_55 -> V_66 . V_116 )
V_69 = L_24 ;
else
V_69 = L_23 ;
}
return F_1 ( V_1 , V_2 , L_9 , V_17 , V_69 ) ;
}
static T_3
F_65 ( struct V_11 * V_12 , struct V_11 * V_13 )
{
return V_12 -> V_117 - V_13 -> V_117 ;
}
static inline char * F_66 ( char * V_65 , const char * V_118 )
{
strcpy ( V_65 , V_118 ) ;
return V_65 + strlen ( V_118 ) ;
}
int F_67 ( void )
{
int V_83 ;
int V_50 = 0 ;
for ( V_83 = 0 ; V_119 [ V_83 ] . V_44 ; V_83 ++ ) {
if ( ! V_119 [ V_83 ] . V_120 )
V_50 += strlen ( V_119 [ V_83 ] . V_44 ) ;
}
V_50 += 4 ;
return V_50 ;
}
static int F_68 ( struct V_11 * V_16 , char * V_1 ,
T_1 V_2 , unsigned int V_17 )
{
T_4 V_121 = V_16 -> V_117 ;
char V_122 [ 128 ] ;
char * V_65 = V_122 ;
int V_83 ;
V_122 [ 0 ] = 0 ;
for ( V_83 = 0 ; V_119 [ V_83 ] . V_44 ; V_83 ++ )
if ( V_119 [ V_83 ] . V_123 & V_121 )
V_65 = F_66 ( V_65 , V_119 [ V_83 ] . V_44 ) ;
if ( V_121 && ! ( V_121 & ( V_124 | V_125 ) ) )
V_65 = F_66 ( V_65 , L_25 ) ;
if ( V_121 & V_126 ) {
sprintf ( V_65 , L_26 V_127 ,
( V_121 & V_126 ) >>
V_128 ) ;
V_65 += strlen ( V_65 ) ;
}
return F_1 ( V_1 , V_2 , L_9 , V_17 , V_122 ) ;
}
bool F_69 ( struct V_129 * V_130 , struct V_129 * V_131 )
{
struct V_132 * V_133 ;
struct V_132 * V_134 ;
if ( ! F_70 ( V_130 ) || ! F_70 ( V_131 ) )
return false ;
V_133 = F_71 ( V_130 , struct V_132 , V_135 ) ;
V_134 = F_71 ( V_131 , struct V_132 , V_135 ) ;
return V_133 -> V_136 == V_134 -> V_136 ;
}
void F_72 ( struct V_129 * V_3 , struct V_137 * V_137 )
{
struct V_132 * V_138 ;
if ( ! F_70 ( V_3 ) )
return;
V_138 = F_71 ( V_3 , struct V_132 , V_135 ) ;
F_73 ( V_137 , V_138 -> V_136 -> V_139 , strlen ( V_3 -> V_44 ) ) ;
}
static int F_74 ( struct V_129 * V_3 , struct V_140 * V_135 ,
struct V_141 * V_142 )
{
struct V_132 * V_138 ;
T_1 V_50 = V_3 -> V_143 ;
V_138 = F_71 ( V_3 , struct V_132 , V_135 ) ;
if ( ! V_50 )
V_50 = F_75 ( F_76 ( V_142 ) , V_138 -> V_136 -> V_139 ) ;
return F_77 ( V_135 -> V_122 , V_135 -> V_2 , L_3 , V_50 , V_50 , V_3 -> V_44 ) ;
}
static int F_78 ( struct V_129 * V_3 ,
struct V_140 * V_135 V_144 ,
struct V_141 * V_142 )
{
struct V_132 * V_138 ;
T_1 V_50 = V_3 -> V_143 ;
V_138 = F_71 ( V_3 , struct V_132 , V_135 ) ;
if ( ! V_50 )
V_50 = F_75 ( F_76 ( V_142 ) , V_138 -> V_136 -> V_139 ) ;
return V_50 ;
}
static int F_79 ( struct V_129 * V_3 , struct V_140 * V_135 ,
struct V_11 * V_16 )
{
struct V_132 * V_138 ;
T_1 V_50 = V_3 -> V_143 ;
V_138 = F_71 ( V_3 , struct V_132 , V_135 ) ;
if ( ! V_50 )
V_50 = F_75 ( V_16 -> V_137 , V_138 -> V_136 -> V_139 ) ;
return V_138 -> V_136 -> V_145 ( V_16 , V_135 -> V_122 , V_135 -> V_2 , V_50 ) ;
}
static T_3 F_80 ( struct V_129 * V_3 ,
struct V_11 * V_130 , struct V_11 * V_131 )
{
struct V_132 * V_138 ;
V_138 = F_71 ( V_3 , struct V_132 , V_135 ) ;
return V_138 -> V_136 -> V_146 ( V_130 , V_131 ) ;
}
static T_3 F_81 ( struct V_129 * V_3 ,
struct V_11 * V_130 , struct V_11 * V_131 )
{
struct V_132 * V_138 ;
T_3 (* F_82)( struct V_11 * , struct V_11 * );
V_138 = F_71 ( V_3 , struct V_132 , V_135 ) ;
F_82 = V_138 -> V_136 -> V_147 ? : V_138 -> V_136 -> V_146 ;
return F_82 ( V_130 , V_131 ) ;
}
static T_3 F_83 ( struct V_129 * V_3 ,
struct V_11 * V_130 , struct V_11 * V_131 )
{
struct V_132 * V_138 ;
T_3 (* F_84)( struct V_11 * , struct V_11 * );
V_138 = F_71 ( V_3 , struct V_132 , V_135 ) ;
F_84 = V_138 -> V_136 -> V_148 ? : V_138 -> V_136 -> V_146 ;
return F_84 ( V_130 , V_131 ) ;
}
static struct V_132 *
F_85 ( struct V_149 * V_150 )
{
struct V_132 * V_138 ;
V_138 = malloc ( sizeof( * V_138 ) ) ;
if ( V_138 == NULL ) {
F_86 ( L_27 ) ;
return NULL ;
}
V_138 -> V_136 = V_150 -> V_151 ;
V_138 -> V_135 . V_44 = V_150 -> V_151 -> V_152 ;
V_138 -> V_135 . V_153 = F_74 ;
V_138 -> V_135 . V_17 = F_78 ;
V_138 -> V_135 . V_151 = F_79 ;
V_138 -> V_135 . V_154 = NULL ;
V_138 -> V_135 . V_155 = F_80 ;
V_138 -> V_135 . V_156 = F_81 ;
V_138 -> V_135 . V_157 = F_83 ;
F_87 ( & V_138 -> V_135 . V_158 ) ;
F_87 ( & V_138 -> V_135 . V_159 ) ;
V_138 -> V_135 . V_160 = false ;
V_138 -> V_135 . V_50 = 0 ;
V_138 -> V_135 . V_143 = 0 ;
return V_138 ;
}
bool F_70 ( struct V_129 * V_161 )
{
return V_161 -> V_153 == F_74 ;
}
static int F_88 ( struct V_149 * V_150 )
{
struct V_132 * V_138 = F_85 ( V_150 ) ;
if ( V_138 == NULL )
return - 1 ;
F_89 ( & V_138 -> V_135 ) ;
return 0 ;
}
static int F_90 ( struct V_149 * V_150 )
{
struct V_132 * V_138 = F_85 ( V_150 ) ;
if ( V_138 == NULL )
return - 1 ;
F_91 ( & V_138 -> V_135 ) ;
return 0 ;
}
static int F_92 ( struct V_149 * V_150 )
{
if ( V_150 -> V_162 )
return 0 ;
if ( F_88 ( V_150 ) < 0 )
return - 1 ;
if ( V_150 -> V_151 -> V_147 )
V_163 = 1 ;
V_150 -> V_162 = 1 ;
return 0 ;
}
static int F_93 ( struct V_164 * V_165 )
{
if ( ! V_165 -> V_162 ) {
V_165 -> V_162 = 1 ;
F_89 ( V_165 -> V_3 ) ;
}
return 0 ;
}
static int F_94 ( struct V_149 * V_150 )
{
if ( V_150 -> V_162 )
return 0 ;
if ( F_90 ( V_150 ) < 0 )
return - 1 ;
V_150 -> V_162 = 1 ;
return 0 ;
}
static int F_95 ( struct V_164 * V_165 )
{
if ( ! V_165 -> V_162 ) {
V_165 -> V_162 = 1 ;
F_91 ( V_165 -> V_3 ) ;
}
return 0 ;
}
int F_96 ( const char * V_166 )
{
unsigned int V_83 ;
for ( V_83 = 0 ; V_83 < F_97 ( V_167 ) ; V_83 ++ ) {
struct V_149 * V_150 = & V_167 [ V_83 ] ;
if ( strncasecmp ( V_166 , V_150 -> V_44 , strlen ( V_166 ) ) )
continue;
if ( V_150 -> V_151 == & V_168 ) {
int V_40 = regcomp ( & V_169 , V_170 , V_171 ) ;
if ( V_40 ) {
char V_172 [ V_173 ] ;
regerror ( V_40 , & V_169 , V_172 , sizeof( V_172 ) ) ;
F_86 ( L_28 , V_170 , V_172 ) ;
return - V_174 ;
}
V_175 = 1 ;
} else if ( V_150 -> V_151 == & V_176 ) {
V_177 = 1 ;
if ( V_178 == V_179 )
V_150 -> V_151 -> V_147 = F_19 ;
} else if ( V_150 -> V_151 == & V_180 ) {
V_43 = 1 ;
}
return F_92 ( V_150 ) ;
}
for ( V_83 = 0 ; V_83 < F_97 ( V_181 ) ; V_83 ++ ) {
struct V_164 * V_165 = & V_181 [ V_83 ] ;
if ( strncasecmp ( V_166 , V_165 -> V_44 , strlen ( V_166 ) ) )
continue;
return F_93 ( V_165 ) ;
}
for ( V_83 = 0 ; V_83 < F_97 ( V_182 ) ; V_83 ++ ) {
struct V_149 * V_150 = & V_182 [ V_83 ] ;
if ( strncasecmp ( V_166 , V_150 -> V_44 , strlen ( V_166 ) ) )
continue;
if ( V_178 != V_183 )
return - V_174 ;
if ( V_150 -> V_151 == & V_184 || V_150 -> V_151 == & V_185 )
V_177 = 1 ;
F_92 ( V_150 ) ;
return 0 ;
}
for ( V_83 = 0 ; V_83 < F_97 ( V_186 ) ; V_83 ++ ) {
struct V_149 * V_150 = & V_186 [ V_83 ] ;
if ( strncasecmp ( V_166 , V_150 -> V_44 , strlen ( V_166 ) ) )
continue;
if ( V_178 != V_187 )
return - V_174 ;
if ( V_150 -> V_151 == & V_188 )
V_177 = 1 ;
F_92 ( V_150 ) ;
return 0 ;
}
return - V_189 ;
}
static const char * F_98 ( void )
{
const char * V_190 [] = {
V_191 ,
V_192 ,
V_193 ,
V_194 ,
V_195 ,
} ;
F_99 ( V_178 >= F_97 ( V_190 ) ) ;
return V_190 [ V_178 ] ;
}
static int F_100 ( void )
{
char * V_196 ;
if ( ! V_197 || F_101 ( V_197 ) )
return 0 ;
if ( V_197 [ 1 ] == '\0' ) {
error ( L_29 ) ;
return - V_174 ;
}
if ( F_102 ( & V_196 , L_30 ,
F_98 () , V_197 + 1 ) < 0 ) {
error ( L_31 ) ;
return - V_198 ;
}
V_197 = V_196 ;
return 0 ;
}
static int F_103 ( void )
{
char * V_199 , * V_166 , * V_118 ;
const char * V_200 ;
int V_40 = 0 ;
V_40 = F_100 () ;
if ( V_40 )
return V_40 ;
V_200 = V_197 ;
if ( V_200 == NULL ) {
if ( F_101 ( V_201 ) ) {
return 0 ;
}
V_200 = F_98 () ;
}
V_118 = F_104 ( V_200 ) ;
if ( V_118 == NULL ) {
error ( L_32 ) ;
return - V_198 ;
}
for ( V_166 = strtok_r ( V_118 , L_33 , & V_199 ) ;
V_166 ; V_166 = strtok_r ( NULL , L_33 , & V_199 ) ) {
V_40 = F_96 ( V_166 ) ;
if ( V_40 == - V_174 ) {
error ( L_34 , V_166 ) ;
break;
} else if ( V_40 == - V_189 ) {
error ( L_35 , V_166 ) ;
break;
}
}
free ( V_118 ) ;
return V_40 ;
}
void F_105 ( int V_202 , bool V_160 )
{
struct V_129 * V_3 ;
struct V_132 * V_138 ;
F_106 (fmt) {
if ( ! F_70 ( V_3 ) )
continue;
V_138 = F_71 ( V_3 , struct V_132 , V_135 ) ;
if ( V_138 -> V_136 -> V_139 == V_202 ) {
V_3 -> V_160 = V_160 ;
break;
}
}
}
static bool F_107 ( struct V_203 * V_158 , const char * V_204 , T_6 * V_205 )
{
if ( V_158 && F_108 ( V_158 ) == 1 ) {
if ( V_205 != NULL )
fprintf ( V_205 , L_36 , V_204 ,
F_109 ( V_158 , 0 ) -> V_206 ) ;
return true ;
}
return false ;
}
static bool F_110 ( int V_202 , T_6 * V_207 )
{
switch ( V_202 ) {
case V_208 :
return F_107 ( V_6 . V_209 , L_37 , V_207 ) ;
case V_210 :
return F_107 ( V_6 . V_211 , L_38 , V_207 ) ;
case V_212 :
return F_107 ( V_6 . V_213 , L_39 , V_207 ) ;
default:
break;
}
if ( V_178 != V_183 )
return false ;
switch ( V_202 ) {
case V_214 :
return F_107 ( V_6 . V_215 , L_40 , V_207 ) ;
case V_216 :
return F_107 ( V_6 . V_217 , L_41 , V_207 ) ;
case V_218 :
return F_107 ( V_6 . V_219 , L_42 , V_207 ) ;
case V_220 :
return F_107 ( V_6 . V_221 , L_43 , V_207 ) ;
default:
break;
}
return false ;
}
void F_111 ( T_6 * V_207 )
{
struct V_129 * V_3 ;
struct V_132 * V_138 ;
F_106 (fmt) {
if ( ! F_70 ( V_3 ) )
continue;
V_138 = F_71 ( V_3 , struct V_132 , V_135 ) ;
V_3 -> V_160 = F_110 ( V_138 -> V_136 -> V_139 , V_207 ) ;
}
F_106 (fmt) {
if ( ! F_70 ( V_3 ) )
continue;
if ( ! V_3 -> V_160 )
return;
}
F_106 (fmt) {
if ( ! F_70 ( V_3 ) )
continue;
V_3 -> V_160 = false ;
}
}
static int F_112 ( char * V_166 )
{
unsigned int V_83 ;
for ( V_83 = 0 ; V_83 < F_97 ( V_167 ) ; V_83 ++ ) {
struct V_149 * V_150 = & V_167 [ V_83 ] ;
if ( strncasecmp ( V_166 , V_150 -> V_44 , strlen ( V_166 ) ) )
continue;
return F_94 ( V_150 ) ;
}
for ( V_83 = 0 ; V_83 < F_97 ( V_181 ) ; V_83 ++ ) {
struct V_164 * V_165 = & V_181 [ V_83 ] ;
if ( strncasecmp ( V_166 , V_165 -> V_44 , strlen ( V_166 ) ) )
continue;
return F_95 ( V_165 ) ;
}
for ( V_83 = 0 ; V_83 < F_97 ( V_182 ) ; V_83 ++ ) {
struct V_149 * V_150 = & V_182 [ V_83 ] ;
if ( strncasecmp ( V_166 , V_150 -> V_44 , strlen ( V_166 ) ) )
continue;
return F_94 ( V_150 ) ;
}
for ( V_83 = 0 ; V_83 < F_97 ( V_186 ) ; V_83 ++ ) {
struct V_149 * V_150 = & V_186 [ V_83 ] ;
if ( strncasecmp ( V_166 , V_150 -> V_44 , strlen ( V_166 ) ) )
continue;
return F_94 ( V_150 ) ;
}
return - V_189 ;
}
static void F_113 ( void )
{
unsigned int V_83 ;
for ( V_83 = 0 ; V_83 < F_97 ( V_167 ) ; V_83 ++ )
V_167 [ V_83 ] . V_162 = 0 ;
for ( V_83 = 0 ; V_83 < F_97 ( V_181 ) ; V_83 ++ )
V_181 [ V_83 ] . V_162 = 0 ;
for ( V_83 = 0 ; V_83 < F_97 ( V_182 ) ; V_83 ++ )
V_182 [ V_83 ] . V_162 = 0 ;
for ( V_83 = 0 ; V_83 < F_97 ( V_186 ) ; V_83 ++ )
V_186 [ V_83 ] . V_162 = 0 ;
}
bool F_101 ( const char * V_222 )
{
return V_222 && ( * V_222 != '+' ) ;
}
static int F_114 ( void )
{
char * V_199 , * V_166 , * V_118 , * V_223 ;
int V_40 = - V_174 ;
if ( V_201 == NULL )
return 0 ;
F_113 () ;
V_223 = V_118 = F_104 ( V_201 ) ;
if ( V_118 == NULL ) {
error ( L_44 ) ;
return - V_198 ;
}
if ( ! F_101 ( V_201 ) )
V_223 ++ ;
if ( ! strlen ( V_223 ) ) {
error ( L_45 ) ;
goto V_69;
}
for ( V_166 = strtok_r ( V_223 , L_33 , & V_199 ) ;
V_166 ; V_166 = strtok_r ( NULL , L_33 , & V_199 ) ) {
V_40 = F_112 ( V_166 ) ;
if ( V_40 == - V_174 ) {
error ( L_46 , V_166 ) ;
break;
} else if ( V_40 == - V_189 ) {
error ( L_47 , V_166 ) ;
break;
}
}
V_69:
free ( V_118 ) ;
return V_40 ;
}
int F_115 ( void )
{
int V_172 ;
V_172 = F_103 () ;
if ( V_172 < 0 )
return V_172 ;
if ( V_170 != V_224 ) {
V_172 = F_96 ( L_48 ) ;
if ( V_172 < 0 )
return V_172 ;
}
F_113 () ;
if ( V_178 != V_179 )
F_116 () ;
V_172 = F_114 () ;
if ( V_172 < 0 )
return V_172 ;
F_117 () ;
F_118 () ;
return 0 ;
}
void F_119 ( void )
{
V_163 = 0 ;
V_175 = 0 ;
V_177 = 0 ;
V_43 = 0 ;
V_201 = NULL ;
V_197 = NULL ;
F_113 () ;
F_120 () ;
}
