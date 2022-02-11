static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_4 * V_5 ,
const struct V_6 * V_7 )
{
struct V_8 V_9 ;
struct V_10 V_11 ;
void * V_12 = & V_9 ;
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
V_9 . V_13 = ( V_7 -> V_14 << 24 ) | V_7 -> V_15 ;
memcpy ( V_12 + 4 , V_7 -> V_16 . V_17 , V_7 -> V_16 . V_18 ) ;
memset ( & V_11 , 0 , sizeof( V_11 ) ) ;
V_11 . V_19 = V_20 ;
V_11 . V_16 . V_17 = & V_9 ;
V_11 . V_16 . V_18 = sizeof( V_9 ) ;
V_11 . V_21 . V_17 = V_7 -> V_21 . V_17 ;
V_11 . V_21 . V_18 = V_7 -> V_21 . V_18 ;
return F_4 ( V_5 , & V_11 ) ;
}
static int F_5 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_6 V_11 ;
memset ( & V_11 , 0 , sizeof( V_11 ) ) ;
V_11 . V_14 = V_22 ;
V_11 . V_15 = V_7 -> V_15 ;
return F_3 ( V_7 -> V_5 , & V_11 ) ;
}
static void F_6 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_6 V_11 ;
int V_23 ;
memset ( & V_11 , 0 , sizeof( V_11 ) ) ;
V_11 . V_14 = V_24 ;
V_11 . V_15 = V_7 -> V_15 ;
V_23 = F_3 ( V_7 -> V_5 , & V_11 ) ;
if ( V_23 < 0 )
F_7 ( V_7 -> V_5 -> V_25 , L_1 ,
F_8 ( V_3 ) , V_23 ) ;
}
static int F_9 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_26 V_27 ;
struct V_6 V_11 ;
int V_23 ;
memset ( & V_11 , 0 , sizeof( V_11 ) ) ;
V_11 . V_14 = V_28 ;
V_11 . V_15 = V_7 -> V_15 ;
V_11 . V_21 . V_17 = & V_27 ;
V_11 . V_21 . V_18 = sizeof( V_27 ) ;
V_23 = F_3 ( V_7 -> V_5 , & V_11 ) ;
if ( V_23 < 0 )
return V_23 ;
return V_27 . V_29 ;
}
static unsigned long F_10 ( struct V_2 * V_3 ,
unsigned long V_30 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_31 V_27 ;
struct V_32 V_9 ;
struct V_6 V_11 ;
int V_23 ;
memset ( & V_11 , 0 , sizeof( V_11 ) ) ;
V_11 . V_14 = V_33 ;
V_11 . V_15 = V_7 -> V_15 ;
V_11 . V_16 . V_17 = & V_9 ;
V_11 . V_16 . V_18 = sizeof( V_9 ) ;
V_11 . V_21 . V_17 = & V_27 ;
V_11 . V_21 . V_18 = sizeof( V_27 ) ;
V_23 = F_3 ( V_7 -> V_5 , & V_11 ) ;
if ( V_23 < 0 )
return V_23 ;
return V_27 . V_34 ;
}
static long F_11 ( struct V_2 * V_3 , unsigned long V_34 ,
unsigned long * V_30 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_35 V_27 ;
struct V_36 V_9 ;
struct V_6 V_11 ;
int V_23 ;
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
V_9 . V_34 = V_34 ;
memset ( & V_11 , 0 , sizeof( V_11 ) ) ;
V_11 . V_14 = V_37 ;
V_11 . V_15 = V_7 -> V_15 ;
V_11 . V_16 . V_17 = & V_9 ;
V_11 . V_16 . V_18 = sizeof( V_9 ) ;
V_11 . V_21 . V_17 = & V_27 ;
V_11 . V_21 . V_18 = sizeof( V_27 ) ;
V_23 = F_3 ( V_7 -> V_5 , & V_11 ) ;
if ( V_23 < 0 )
return V_23 ;
return V_27 . V_34 ;
}
static int F_12 ( struct V_2 * V_3 , T_1 V_38 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_39 V_27 ;
struct V_40 V_9 ;
struct V_6 V_11 ;
int V_23 ;
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
V_9 . V_41 = V_7 -> V_42 [ V_38 ] ;
memset ( & V_11 , 0 , sizeof( V_11 ) ) ;
V_11 . V_14 = V_43 ;
V_11 . V_15 = V_7 -> V_15 ;
V_11 . V_16 . V_17 = & V_9 ;
V_11 . V_16 . V_18 = sizeof( V_9 ) ;
V_11 . V_21 . V_17 = & V_27 ;
V_11 . V_21 . V_18 = sizeof( V_27 ) ;
V_23 = F_3 ( V_7 -> V_5 , & V_11 ) ;
if ( V_23 < 0 )
return V_23 ;
return 0 ;
}
static T_1 F_13 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_44 V_27 ;
struct V_6 V_11 ;
unsigned int V_45 ;
int V_23 ;
memset ( & V_11 , 0 , sizeof( V_11 ) ) ;
V_11 . V_14 = V_46 ;
V_11 . V_15 = V_7 -> V_15 ;
V_11 . V_21 . V_17 = & V_27 ;
V_11 . V_21 . V_18 = sizeof( V_27 ) ;
V_23 = F_3 ( V_7 -> V_5 , & V_11 ) ;
if ( V_23 < 0 ) {
F_7 ( V_7 -> V_5 -> V_25 , L_2 ,
F_8 ( V_3 ) , V_23 ) ;
return V_47 ;
}
for ( V_45 = 0 ; V_45 < V_7 -> V_48 ; V_45 ++ )
if ( V_7 -> V_42 [ V_45 ] == V_27 . V_41 )
return V_45 ;
return V_47 ;
}
static int F_14 ( struct V_2 * V_3 , unsigned long V_34 ,
unsigned long V_30 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_49 V_27 ;
struct V_50 V_9 ;
struct V_6 V_11 ;
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
V_9 . V_34 = V_34 ;
memset ( & V_11 , 0 , sizeof( V_11 ) ) ;
V_11 . V_14 = V_51 ;
V_11 . V_15 = V_7 -> V_15 ;
V_11 . V_16 . V_17 = & V_9 ;
V_11 . V_16 . V_18 = sizeof( V_9 ) ;
V_11 . V_21 . V_17 = & V_27 ;
V_11 . V_21 . V_18 = sizeof( V_27 ) ;
return F_3 ( V_7 -> V_5 , & V_11 ) ;
}
static int F_15 ( struct V_4 * V_5 )
{
struct V_52 V_27 ;
struct V_6 V_11 ;
int V_23 ;
memset ( & V_11 , 0 , sizeof( V_11 ) ) ;
V_11 . V_14 = V_53 ;
V_11 . V_21 . V_17 = & V_27 ;
V_11 . V_21 . V_18 = sizeof( V_27 ) ;
V_23 = F_3 ( V_5 , & V_11 ) ;
if ( V_23 < 0 )
return V_23 ;
if ( V_27 . V_54 > V_55 )
return - V_56 ;
return V_27 . V_54 ;
}
static int F_16 ( struct V_4 * V_5 , unsigned int V_15 ,
struct V_57 * V_58 )
{
struct V_59 V_27 ;
struct V_6 V_11 ;
unsigned int V_45 ;
int V_23 ;
memset ( & V_11 , 0 , sizeof( V_11 ) ) ;
V_11 . V_14 = V_60 ;
V_11 . V_15 = V_15 ;
V_11 . V_21 . V_17 = & V_27 ;
V_11 . V_21 . V_18 = sizeof( V_27 ) ;
V_23 = F_3 ( V_5 , & V_11 ) ;
if ( V_23 < 0 )
return V_23 ;
F_17 ( V_58 -> V_61 , V_27 . V_61 , V_62 ) ;
V_58 -> V_48 = V_27 . V_48 ;
for ( V_45 = 0 ; V_45 < V_58 -> V_48 ; V_45 ++ )
V_58 -> V_42 [ V_45 ] = V_27 . V_42 [ V_45 ] ;
V_58 -> V_63 = V_27 . V_63 ;
return 0 ;
}
static void F_18 ( struct V_4 * V_5 ,
const char * V_64 ,
const struct V_57 * V_58 )
{
const char * V_65 = L_3 ;
struct V_66 V_67 ;
unsigned int V_45 ;
char V_63 [ 64 ] ;
F_19 ( & V_67 , V_63 , sizeof( V_63 ) ) ;
if ( V_58 -> V_63 )
F_20 ( & V_67 , L_4 ) ;
if ( V_58 -> V_63 & V_68 ) {
F_20 ( & V_67 , L_5 , V_65 ) ;
V_65 = L_6 ;
}
if ( ( V_58 -> V_63 & V_69 ) == 0 ) {
F_20 ( & V_67 , L_7 , V_65 ) ;
V_65 = L_6 ;
}
if ( V_58 -> V_63 & V_70 ) {
F_20 ( & V_67 , L_8 , V_65 ) ;
V_65 = L_6 ;
}
if ( V_58 -> V_63 )
F_20 ( & V_67 , L_9 ) ;
F_21 ( V_64 , V_5 -> V_25 , L_10 , V_58 -> V_15 , V_58 -> V_61 ) ;
F_21 ( V_64 , V_5 -> V_25 , L_11 , V_58 -> V_63 , V_63 ) ;
F_21 ( V_64 , V_5 -> V_25 , L_12 , V_58 -> V_48 ) ;
for ( V_45 = 0 ; V_45 < V_58 -> V_48 ; V_45 ++ )
F_21 ( V_64 , V_5 -> V_25 , L_13 , V_58 -> V_42 [ V_45 ] ) ;
}
static int F_22 ( struct V_4 * V_5 ,
struct V_57 * * V_71 )
{
struct V_57 * V_72 ;
unsigned int V_54 , V_15 , V_73 = 0 ;
unsigned int V_74 = 0 ;
int V_23 ;
V_23 = F_15 ( V_5 ) ;
if ( V_23 < 0 )
return V_23 ;
V_54 = V_23 ;
F_23 ( V_5 -> V_25 , L_14 , V_54 ) ;
V_72 = F_24 ( V_54 + 1 , sizeof( * V_72 ) , V_75 ) ;
if ( ! V_72 )
return - V_76 ;
for ( V_15 = 0 ; V_15 <= V_54 ; V_15 ++ ) {
struct V_57 * V_58 = & V_72 [ V_73 ] ;
V_23 = F_16 ( V_5 , V_15 , V_58 ) ;
if ( V_23 < 0 ) {
F_7 ( V_5 -> V_25 , L_15 ,
V_15 , V_23 ) ;
continue;
}
if ( V_58 -> V_48 >= V_47 ) {
F_7 ( V_5 -> V_25 ,
L_16 ,
V_15 , V_58 -> V_48 , V_47 ) ;
continue;
}
if ( V_58 -> V_61 [ 0 ] == '\0' ) {
V_74 ++ ;
continue;
}
V_58 -> V_15 = V_15 ;
V_73 ++ ;
if ( V_77 )
F_18 ( V_5 , V_78 , V_58 ) ;
}
F_23 ( V_5 -> V_25 , L_17 , V_74 ) ;
* V_71 = V_72 ;
return V_73 ;
}
static const struct V_57 *
F_25 ( const struct V_57 * V_72 ,
unsigned int V_79 , unsigned int V_15 )
{
unsigned int V_45 ;
for ( V_45 = 0 ; V_45 < V_79 ; V_45 ++ )
if ( V_72 [ V_45 ] . V_15 == V_15 )
return & V_72 [ V_45 ] ;
return NULL ;
}
static struct V_1 *
F_26 ( struct V_4 * V_5 ,
const struct V_57 * V_58 ,
const struct V_57 * V_72 ,
unsigned int V_79 )
{
struct V_1 * V_7 ;
struct V_80 V_81 ;
const char * * V_42 ;
unsigned int V_45 ;
int V_23 ;
V_7 = F_27 ( V_5 -> V_25 , sizeof( * V_7 ) , V_75 ) ;
if ( ! V_7 )
return F_28 ( - V_76 ) ;
V_7 -> V_15 = V_58 -> V_15 ;
V_7 -> V_5 = V_5 ;
V_7 -> V_42 = F_29 ( V_5 -> V_25 , V_58 -> V_48 ,
sizeof( * V_7 -> V_42 ) , V_75 ) ;
if ( ! V_7 -> V_42 )
return F_28 ( - V_76 ) ;
V_7 -> V_48 = V_58 -> V_48 ;
memset ( & V_81 , 0 , sizeof( V_81 ) ) ;
V_81 . V_61 = V_58 -> V_61 ;
V_7 -> V_3 . V_81 = & V_81 ;
if ( V_58 -> V_63 & V_68 ) {
if ( V_58 -> V_63 & V_69 )
V_81 . V_82 = & V_83 ;
else
V_81 . V_82 = & V_84 ;
} else {
if ( V_58 -> V_63 & V_69 )
V_81 . V_82 = & V_85 ;
else
V_81 . V_82 = & V_86 ;
}
V_81 . V_48 = V_58 -> V_48 ;
V_42 = F_24 ( V_58 -> V_48 , sizeof( * V_42 ) , V_75 ) ;
if ( ! V_42 )
return F_28 ( - V_76 ) ;
for ( V_45 = 0 ; V_45 < V_58 -> V_48 ; V_45 ++ ) {
const struct V_57 * V_87 ;
V_7 -> V_42 [ V_45 ] = V_58 -> V_42 [ V_45 ] ;
V_87 = F_25 ( V_72 , V_79 ,
V_58 -> V_42 [ V_45 ] ) ;
if ( ! V_87 ) {
F_7 ( V_5 -> V_25 , L_18 ,
V_58 -> V_42 [ V_45 ] , V_58 -> V_15 ) ;
continue;
}
V_42 [ V_45 ] = V_87 -> V_61 ;
}
V_81 . V_88 = V_42 ;
V_23 = F_30 ( V_5 -> V_25 , & V_7 -> V_3 ) ;
F_31 ( V_42 ) ;
if ( V_23 < 0 )
return F_28 ( V_23 ) ;
return V_7 ;
}
static int F_32 ( struct V_4 * V_5 ,
struct V_57 * V_89 ,
unsigned int V_73 )
{
struct V_1 * V_7 ;
unsigned int V_45 ;
V_5 -> V_79 = V_73 ;
V_5 -> V_72 = F_29 ( V_5 -> V_25 , V_73 , sizeof( V_7 ) , V_75 ) ;
if ( ! V_5 -> V_72 )
return - V_76 ;
for ( V_45 = 0 ; V_45 < V_73 ; V_45 ++ ) {
struct V_57 * V_58 = & V_89 [ V_45 ] ;
V_7 = F_26 ( V_5 , V_58 , V_89 , V_73 ) ;
if ( F_33 ( V_7 ) ) {
F_7 ( V_5 -> V_25 ,
L_19 ,
V_58 -> V_15 , V_58 -> V_61 , F_34 ( V_7 ) ) ;
continue;
}
V_5 -> V_72 [ V_45 ] = V_7 ;
}
return 0 ;
}
static void F_35 ( struct V_4 * V_5 )
{
unsigned int V_45 ;
for ( V_45 = 0 ; V_45 < V_5 -> V_79 ; V_45 ++ )
F_36 ( & V_5 -> V_72 [ V_45 ] -> V_3 ) ;
}
static struct V_2 * F_37 ( struct V_90 * V_91 ,
void * V_17 )
{
unsigned int V_15 = V_91 -> args [ 0 ] , V_45 ;
struct V_4 * V_5 = V_17 ;
for ( V_45 = 0 ; V_45 < V_5 -> V_79 ; V_45 ++ )
if ( V_5 -> V_72 [ V_45 ] -> V_15 == V_15 )
return & V_5 -> V_72 [ V_45 ] -> V_3 ;
return NULL ;
}
int F_38 ( struct V_4 * V_5 )
{
struct V_57 * V_72 ;
unsigned int V_73 ;
int V_23 ;
V_23 = F_22 ( V_5 , & V_72 ) ;
if ( V_23 < 0 )
return V_23 ;
V_73 = V_23 ;
F_23 ( V_5 -> V_25 , L_20 , V_73 ) ;
V_23 = F_32 ( V_5 , V_72 , V_73 ) ;
if ( V_23 < 0 )
goto free;
V_23 = F_39 ( V_5 -> V_25 -> V_92 ,
F_37 ,
V_5 ) ;
if ( V_23 < 0 ) {
F_35 ( V_5 ) ;
goto free;
}
free:
F_31 ( V_72 ) ;
return V_23 ;
}
