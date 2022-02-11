static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_3 * V_5 ;
struct V_1 * V_6 ;
F_2 (pos, head) {
V_5 = F_3 ( V_6 , struct V_3 , V_7 ) ;
if ( V_5 -> V_8 > V_4 -> V_8 )
break;
if ( V_5 -> V_8 == V_4 -> V_8 && V_5 -> V_9 > V_4 -> V_9 )
break;
}
F_4 ( & V_4 -> V_7 , V_6 ) ;
}
static void F_5 ( struct V_3 * V_4 )
{
F_6 ( & V_4 -> V_7 ) ;
}
static void F_7 ( struct V_10 * V_10 )
{
struct V_11 * V_12 =
F_3 ( V_10 , struct V_11 , V_10 ) ;
struct V_13 * V_14 = F_8 ( V_12 ) ;
if ( V_12 -> V_14 -> V_15 -> V_16 )
V_12 -> V_14 -> V_15 -> V_16 ( V_12 ) ;
F_9 ( & V_14 -> V_17 ) ;
F_5 ( & V_12 -> V_18 ) ;
F_10 ( & V_14 -> V_17 ) ;
F_11 ( V_12 ) ;
}
static void F_12 ( struct V_11 * V_12 )
{
F_13 ( & V_12 -> V_10 , F_7 ) ;
}
static struct V_11 * F_14 ( struct V_11 * V_12 )
{
F_15 ( & V_12 -> V_10 ) ;
return V_12 ;
}
void F_16 ( struct V_13 * V_14 )
{
struct V_19 * V_20 , * V_21 ;
struct V_3 * V_4 , * V_22 ;
F_17 (cache, ctmp, &cpp->area_cache_list, entry) {
F_18 ( & V_20 -> V_23 ) ;
if ( V_20 -> V_24 )
F_19 ( V_20 -> V_12 ) ;
F_20 ( V_20 -> V_12 ) ;
F_11 ( V_20 ) ;
}
F_21 ( ! F_22 ( & V_14 -> V_25 ) ) ;
F_17 (res, rtmp, &cpp->resource_list, list) {
struct V_11 * V_12 = F_3 ( V_4 ,
struct V_11 ,
V_18 ) ;
F_23 ( V_14 -> V_26 . V_27 , L_1 ,
F_24 ( V_4 -> V_8 ) ,
F_25 ( V_4 -> V_8 ) ,
F_26 ( V_4 -> V_8 ) ,
V_4 -> V_9 , V_4 -> V_28 ,
V_4 -> V_29 ? L_2 : L_3 ,
V_4 -> V_29 ? V_4 -> V_29 : L_3 ) ;
if ( V_12 -> V_14 -> V_15 -> V_30 )
V_12 -> V_14 -> V_15 -> V_30 ( V_12 ) ;
F_7 ( & V_12 -> V_10 ) ;
}
if ( V_14 -> V_15 -> free )
V_14 -> V_15 -> free ( V_14 ) ;
F_11 ( V_14 -> V_31 ) ;
F_11 ( V_14 -> V_32 ) ;
F_27 ( & V_14 -> V_26 ) ;
F_11 ( V_14 ) ;
}
T_1 F_28 ( struct V_13 * V_14 )
{
return V_14 -> V_33 ;
}
T_2 F_29 ( struct V_13 * V_14 )
{
return V_14 -> V_34 ;
}
int F_30 ( struct V_13 * V_14 , const T_3 * * V_35 )
{
* V_35 = & V_14 -> V_35 [ 0 ] ;
return sizeof( V_14 -> V_35 ) ;
}
void * F_31 ( struct V_13 * V_14 )
{
return V_14 -> V_31 ;
}
void F_32 ( struct V_13 * V_14 , void * V_36 )
{
V_14 -> V_31 = V_36 ;
}
void * F_33 ( struct V_13 * V_14 )
{
return V_14 -> V_32 ;
}
void F_34 ( struct V_13 * V_14 , void * V_36 )
{
V_14 -> V_32 = V_36 ;
}
void F_35 ( struct V_13 * V_14 )
{
F_11 ( F_33 ( V_14 ) ) ;
F_34 ( V_14 , NULL ) ;
}
struct V_11 *
F_36 ( struct V_13 * V_14 , T_1 V_37 , const char * V_29 ,
unsigned long long V_38 , unsigned long V_39 )
{
struct V_11 * V_12 ;
T_4 V_40 = V_38 ;
int V_41 , V_42 ;
V_41 = F_37 ( V_37 , V_40 , & V_37 , & V_40 , V_14 -> V_43 ) ;
if ( V_41 < 0 )
return NULL ;
V_38 = V_40 ;
if ( ! V_29 )
V_29 = L_4 ;
V_42 = strlen ( V_29 ) + 1 ;
V_12 = F_38 ( sizeof( * V_12 ) + V_14 -> V_15 -> V_44 + V_42 ,
V_45 ) ;
if ( ! V_12 )
return NULL ;
V_12 -> V_14 = V_14 ;
V_12 -> V_18 . V_29 = ( void * ) V_12 + sizeof( * V_12 ) +
V_14 -> V_15 -> V_44 ;
memcpy ( ( char * ) V_12 -> V_18 . V_29 , V_29 , V_42 ) ;
V_12 -> V_18 . V_8 = V_37 ;
V_12 -> V_18 . V_9 = V_38 ;
V_12 -> V_18 . V_28 = V_12 -> V_18 . V_9 + V_39 - 1 ;
F_39 ( & V_12 -> V_18 . V_7 ) ;
F_40 ( & V_12 -> V_46 , 0 ) ;
F_41 ( & V_12 -> V_10 ) ;
F_42 ( & V_12 -> V_47 ) ;
if ( V_14 -> V_15 -> V_48 ) {
int V_41 ;
V_41 = V_14 -> V_15 -> V_48 ( V_12 , V_37 , V_38 , V_39 ) ;
if ( V_41 < 0 ) {
F_11 ( V_12 ) ;
return NULL ;
}
}
F_9 ( & V_14 -> V_17 ) ;
F_1 ( & V_14 -> V_25 , & V_12 -> V_18 ) ;
F_10 ( & V_14 -> V_17 ) ;
V_12 -> V_49 = V_38 ;
V_12 -> V_39 = V_39 ;
return V_12 ;
}
struct V_11 *
F_43 ( struct V_13 * V_14 , T_1 V_37 ,
unsigned long long V_38 , unsigned long V_39 )
{
return F_36 ( V_14 , V_37 , NULL , V_38 , V_39 ) ;
}
void F_20 ( struct V_11 * V_12 )
{
if ( F_44 ( & V_12 -> V_46 ) )
F_45 ( V_12 -> V_14 , L_5 ) ;
F_12 ( V_12 ) ;
}
static bool F_46 ( struct V_11 * V_12 , int * V_50 )
{
* V_50 = V_12 -> V_14 -> V_15 -> V_51 ( V_12 ) ;
return * V_50 != - V_52 ;
}
static int F_47 ( struct V_11 * V_12 )
{
int V_41 , V_50 ;
if ( F_48 ( & V_12 -> V_46 ) > 1 )
return 0 ;
if ( ! V_12 -> V_14 -> V_15 -> V_51 )
return 0 ;
V_41 = F_49 ( V_12 -> V_14 -> V_53 ,
F_46 ( V_12 , & V_50 ) ) ;
if ( ! V_41 )
V_41 = V_50 ;
if ( V_41 ) {
F_45 ( V_12 -> V_14 , L_6 , V_41 ) ;
F_50 ( & V_12 -> V_46 ) ;
return V_41 ;
}
F_14 ( V_12 ) ;
return 0 ;
}
int F_51 ( struct V_11 * V_12 )
{
int V_54 ;
F_52 ( & V_12 -> V_47 ) ;
V_54 = F_47 ( V_12 ) ;
F_53 ( & V_12 -> V_47 ) ;
return V_54 ;
}
int F_54 ( struct V_11 * V_12 )
{
F_52 ( & V_12 -> V_47 ) ;
if ( F_48 ( & V_12 -> V_46 ) == 1 ) {
if ( V_12 -> V_14 -> V_15 -> V_51 ) {
int V_41 ;
V_41 = V_12 -> V_14 -> V_15 -> V_51 ( V_12 ) ;
if ( V_41 < 0 ) {
F_50 ( & V_12 -> V_46 ) ;
F_53 ( & V_12 -> V_47 ) ;
return V_41 ;
}
}
}
F_53 ( & V_12 -> V_47 ) ;
F_14 ( V_12 ) ;
return 0 ;
}
void F_19 ( struct V_11 * V_12 )
{
F_52 ( & V_12 -> V_47 ) ;
if ( F_55 ( & V_12 -> V_46 ) ) {
if ( V_12 -> V_14 -> V_15 -> V_30 ) {
V_12 -> V_14 -> V_15 -> V_30 ( V_12 ) ;
F_56 ( & V_12 -> V_14 -> V_53 ) ;
}
}
F_53 ( & V_12 -> V_47 ) ;
F_12 ( V_12 ) ;
}
void F_57 ( struct V_11 * V_12 )
{
F_19 ( V_12 ) ;
F_20 ( V_12 ) ;
}
int F_58 ( struct V_11 * V_12 ,
unsigned long V_49 , void * V_55 ,
T_5 V_56 )
{
return V_12 -> V_14 -> V_15 -> V_57 ( V_12 , V_55 , V_49 , V_56 ) ;
}
int F_59 ( struct V_11 * V_12 ,
unsigned long V_49 , const void * V_55 ,
T_5 V_56 )
{
return V_12 -> V_14 -> V_15 -> V_58 ( V_12 , V_55 , V_49 , V_56 ) ;
}
int F_60 ( struct V_11 * V_12 ,
unsigned long long V_49 , unsigned long V_56 )
{
if ( V_49 < V_12 -> V_49 ||
V_49 + V_56 > V_12 -> V_49 + V_12 -> V_39 )
return - V_59 ;
return 0 ;
}
const char * F_61 ( struct V_11 * V_60 )
{
return V_60 -> V_18 . V_29 ;
}
void * F_62 ( struct V_11 * V_60 )
{
return & V_60 [ 1 ] ;
}
struct V_13 * F_8 ( struct V_11 * V_60 )
{
return V_60 -> V_14 ;
}
struct V_18 * F_63 ( struct V_11 * V_12 )
{
struct V_18 * V_4 = NULL ;
if ( V_12 -> V_14 -> V_15 -> V_61 )
V_4 = V_12 -> V_14 -> V_15 -> V_61 ( V_12 ) ;
return V_4 ;
}
T_6 F_64 ( struct V_11 * V_12 )
{
T_6 V_62 = ~ 0 ;
if ( V_12 -> V_14 -> V_15 -> V_63 )
V_62 = V_12 -> V_14 -> V_15 -> V_63 ( V_12 ) ;
return V_62 ;
}
void T_7 * F_65 ( struct V_11 * V_12 )
{
void T_7 * V_64 = NULL ;
if ( V_12 -> V_14 -> V_15 -> V_65 )
V_64 = V_12 -> V_14 -> V_15 -> V_65 ( V_12 ) ;
return V_64 ;
}
int F_66 ( struct V_11 * V_12 ,
unsigned long V_49 , T_1 * V_66 )
{
T_3 V_5 [ 4 ] ;
int V_41 ;
V_41 = F_58 ( V_12 , V_49 , & V_5 , sizeof( V_5 ) ) ;
* V_66 = F_67 ( V_5 ) ;
return V_41 ;
}
int F_68 ( struct V_11 * V_12 ,
unsigned long V_49 , T_1 V_66 )
{
T_3 V_5 [ 4 ] ;
F_69 ( V_66 , V_5 ) ;
return F_59 ( V_12 , V_49 , & V_5 , sizeof( V_5 ) ) ;
}
int F_70 ( struct V_11 * V_12 ,
unsigned long V_49 , T_4 * V_66 )
{
T_3 V_5 [ 8 ] ;
int V_41 ;
V_41 = F_58 ( V_12 , V_49 , & V_5 , sizeof( V_5 ) ) ;
* V_66 = F_71 ( V_5 ) ;
return V_41 ;
}
int F_72 ( struct V_11 * V_12 ,
unsigned long V_49 , T_4 V_66 )
{
T_3 V_5 [ 8 ] ;
F_73 ( V_66 , V_5 ) ;
return F_59 ( V_12 , V_49 , & V_5 , sizeof( V_5 ) ) ;
}
int F_74 ( struct V_11 * V_12 ,
unsigned long V_49 , T_1 V_66 , T_5 V_56 )
{
T_3 V_5 [ 4 ] ;
T_5 V_67 ;
int V_68 ;
F_69 ( V_66 , V_5 ) ;
if ( V_49 % sizeof( V_5 ) || V_56 % sizeof( V_5 ) )
return - V_69 ;
for ( V_67 = 0 ; V_67 < V_56 ; V_67 += sizeof( V_5 ) ) {
V_68 = F_59 ( V_12 , V_49 + V_67 , & V_5 , sizeof( V_5 ) ) ;
if ( V_68 < 0 )
return V_68 ;
}
return V_67 ;
}
int F_75 ( struct V_13 * V_14 , T_5 V_39 )
{
struct V_19 * V_20 ;
struct V_11 * V_12 ;
V_12 = F_43 ( V_14 , F_76 ( 7 , V_70 , 0 ) ,
0 , V_39 ) ;
if ( ! V_12 )
return - V_71 ;
V_20 = F_38 ( sizeof( * V_20 ) , V_45 ) ;
if ( ! V_20 )
return - V_71 ;
V_20 -> V_24 = 0 ;
V_20 -> V_62 = 0 ;
V_20 -> V_39 = V_39 ;
V_20 -> V_12 = V_12 ;
F_52 ( & V_14 -> V_72 ) ;
F_4 ( & V_20 -> V_23 , & V_14 -> V_73 ) ;
F_53 ( & V_14 -> V_72 ) ;
return 0 ;
}
static struct V_19 *
F_77 ( struct V_13 * V_14 , T_1 V_24 ,
T_4 V_62 , unsigned long * V_49 , T_5 V_56 )
{
struct V_19 * V_20 ;
int V_41 ;
if ( V_56 == 0 || V_24 == 0 )
return NULL ;
V_41 = F_37 ( V_24 , V_62 , & V_24 , & V_62 , V_14 -> V_43 ) ;
if ( V_41 < 0 )
return NULL ;
F_52 ( & V_14 -> V_72 ) ;
if ( F_22 ( & V_14 -> V_73 ) ) {
F_53 ( & V_14 -> V_72 ) ;
return NULL ;
}
V_62 += * V_49 ;
F_78 (cache, &cpp->area_cache_list, entry) {
if ( V_24 == V_20 -> V_24 &&
V_62 >= V_20 -> V_62 &&
V_62 + V_56 <= V_20 -> V_62 + V_20 -> V_39 )
goto exit;
}
V_20 = F_79 ( V_14 -> V_73 . V_74 ,
struct V_19 , V_23 ) ;
if ( F_80 ( V_62 + V_56 - 1 , V_20 -> V_39 ) !=
F_80 ( V_62 , V_20 -> V_39 ) ) {
F_53 ( & V_14 -> V_72 ) ;
return NULL ;
}
if ( V_20 -> V_24 ) {
F_19 ( V_20 -> V_12 ) ;
V_20 -> V_24 = 0 ;
V_20 -> V_62 = 0 ;
}
V_20 -> V_24 = V_24 ;
V_20 -> V_62 = V_62 & ~ ( T_4 ) ( V_20 -> V_39 - 1 ) ;
if ( V_14 -> V_15 -> V_48 ) {
V_41 = V_14 -> V_15 -> V_48 ( V_20 -> V_12 ,
V_24 , V_20 -> V_62 , V_20 -> V_39 ) ;
if ( V_41 < 0 ) {
F_53 ( & V_14 -> V_72 ) ;
return NULL ;
}
}
V_41 = F_51 ( V_20 -> V_12 ) ;
if ( V_41 < 0 ) {
F_53 ( & V_14 -> V_72 ) ;
return NULL ;
}
exit:
* V_49 = V_62 - V_20 -> V_62 ;
return V_20 ;
}
static void
F_81 ( struct V_13 * V_14 , struct V_19 * V_20 )
{
if ( ! V_20 )
return;
F_18 ( & V_20 -> V_23 ) ;
F_82 ( & V_20 -> V_23 , & V_14 -> V_73 ) ;
F_53 ( & V_14 -> V_72 ) ;
}
int F_83 ( struct V_13 * V_14 , T_1 V_75 ,
unsigned long long V_38 , void * V_55 , T_5 V_56 )
{
struct V_19 * V_20 ;
struct V_11 * V_12 ;
unsigned long V_49 = 0 ;
int V_41 ;
V_20 = F_77 ( V_14 , V_75 , V_38 , & V_49 , V_56 ) ;
if ( V_20 ) {
V_12 = V_20 -> V_12 ;
} else {
V_12 = F_43 ( V_14 , V_75 , V_38 , V_56 ) ;
if ( ! V_12 )
return - V_71 ;
V_41 = F_51 ( V_12 ) ;
if ( V_41 ) {
F_20 ( V_12 ) ;
return V_41 ;
}
}
V_41 = F_58 ( V_12 , V_49 , V_55 , V_56 ) ;
if ( V_20 )
F_81 ( V_14 , V_20 ) ;
else
F_57 ( V_12 ) ;
return V_41 ;
}
int F_84 ( struct V_13 * V_14 , T_1 V_75 ,
unsigned long long V_38 ,
const void * V_55 , T_5 V_56 )
{
struct V_19 * V_20 ;
struct V_11 * V_12 ;
unsigned long V_49 = 0 ;
int V_41 ;
V_20 = F_77 ( V_14 , V_75 , V_38 , & V_49 , V_56 ) ;
if ( V_20 ) {
V_12 = V_20 -> V_12 ;
} else {
V_12 = F_43 ( V_14 , V_75 , V_38 , V_56 ) ;
if ( ! V_12 )
return - V_71 ;
V_41 = F_51 ( V_12 ) ;
if ( V_41 ) {
F_20 ( V_12 ) ;
return V_41 ;
}
}
V_41 = F_59 ( V_12 , V_49 , V_55 , V_56 ) ;
if ( V_20 )
F_81 ( V_14 , V_20 ) ;
else
F_57 ( V_12 ) ;
return V_41 ;
}
static T_1 F_85 ( struct V_13 * V_14 , T_1 * V_76 )
{
int V_77 ;
T_1 V_78 ;
V_78 = F_76 ( 14 , V_70 , 0 ) ;
V_77 = ( * V_76 >> 24 ) & 0x3f ;
if ( ! V_77 )
return V_78 ;
if ( V_77 != 1 ) {
* V_76 |= 1 << 30 ;
return V_78 ;
}
* V_76 &= ~ 0x7f000000 ;
if ( * V_76 < 0x60000 ) {
* V_76 |= 1 << 30 ;
} else {
if ( F_86 ( F_29 ( V_14 ) )
!= V_79 )
* V_76 |= 1 << 24 ;
}
return V_78 ;
}
int F_87 ( struct V_13 * V_14 , T_1 V_76 , T_1 * V_66 )
{
T_1 V_80 = F_85 ( V_14 , & V_76 ) ;
return F_88 ( V_14 , V_80 , V_76 , V_66 ) ;
}
int F_89 ( struct V_13 * V_14 , T_1 V_76 , T_1 V_66 )
{
T_1 V_80 = F_85 ( V_14 , & V_76 ) ;
return F_90 ( V_14 , V_80 , V_76 , V_66 ) ;
}
int F_91 ( struct V_13 * V_14 , T_1 V_81 ,
T_1 V_82 , T_1 V_66 )
{
int V_41 ;
T_1 V_5 ;
V_41 = F_87 ( V_14 , V_81 , & V_5 ) ;
if ( V_41 < 0 )
return V_41 ;
V_5 &= ~ V_82 ;
V_5 |= V_82 & V_66 ;
return F_89 ( V_14 , V_81 , V_5 ) ;
}
static void F_92 ( struct V_83 * V_26 )
{
}
struct V_13 *
F_93 ( const struct V_84 * V_85 ,
struct V_83 * V_27 , void * V_86 )
{
const T_1 V_87 = F_76 ( V_88 , V_70 , 0 ) ;
struct V_13 * V_14 ;
T_1 V_82 [ 2 ] ;
T_1 V_89 ;
T_5 V_90 ;
int V_41 ;
V_14 = F_38 ( sizeof( * V_14 ) , V_45 ) ;
if ( ! V_14 ) {
V_41 = - V_71 ;
goto V_91;
}
V_14 -> V_15 = V_85 ;
V_14 -> V_86 = V_86 ;
V_14 -> V_34 = V_85 -> V_92 ( V_27 ) ;
if ( V_85 -> V_93 )
V_85 -> V_93 ( V_27 , V_14 -> V_35 ) ;
F_94 ( & V_14 -> V_17 ) ;
F_95 ( & V_14 -> V_53 ) ;
F_96 ( & V_14 -> V_17 , & V_94 ) ;
F_39 ( & V_14 -> V_25 ) ;
F_39 ( & V_14 -> V_73 ) ;
F_42 ( & V_14 -> V_72 ) ;
V_14 -> V_26 . V_95 = L_7 ;
V_14 -> V_26 . V_27 = V_27 ;
V_14 -> V_26 . V_96 = F_92 ;
V_41 = F_97 ( & V_14 -> V_26 ) ;
if ( V_41 < 0 ) {
F_98 ( & V_14 -> V_26 ) ;
goto V_97;
}
F_99 ( & V_14 -> V_26 , V_14 ) ;
if ( V_14 -> V_15 -> V_98 ) {
V_41 = V_14 -> V_15 -> V_98 ( V_14 ) ;
if ( V_41 < 0 ) {
F_23 ( V_27 ,
L_8 ) ;
goto V_99;
}
}
V_41 = F_100 ( V_14 , & V_14 -> V_33 ) ;
if ( V_41 < 0 ) {
F_23 ( V_27 , L_9 ) ;
goto V_99;
}
for ( V_90 = 0 ; V_90 < F_101 ( V_14 -> V_43 ) ; V_90 ++ ) {
V_89 = 0x000a0000 + ( V_90 * 4 ) ;
V_41 = F_87 ( V_14 , V_89 ,
& V_14 -> V_43 [ V_90 ] ) ;
if ( V_41 < 0 ) {
F_23 ( V_27 ,
L_10 ) ;
goto V_99;
}
}
F_88 ( V_14 , V_87 , V_100 + V_101 ,
& V_82 [ 0 ] ) ;
F_88 ( V_14 , V_87 , V_100 + V_102 ,
& V_82 [ 1 ] ) ;
F_102 ( V_14 -> V_26 . V_27 , L_11 ,
F_28 ( V_14 ) , V_14 -> V_35 , F_29 ( V_14 ) ) ;
return V_14 ;
V_99:
F_27 ( & V_14 -> V_26 ) ;
V_97:
F_11 ( V_14 ) ;
V_91:
return F_103 ( V_41 ) ;
}
void * F_104 ( struct V_13 * V_14 )
{
return V_14 -> V_86 ;
}
struct V_83 * F_105 ( struct V_13 * V_14 )
{
return & V_14 -> V_26 ;
}
struct V_103 * F_106 ( struct V_13 * V_14 )
{
struct V_103 * V_104 ;
int V_41 ;
V_104 = F_38 ( sizeof( * V_104 ) + V_14 -> V_15 -> V_105 , V_45 ) ;
if ( ! V_104 )
return NULL ;
V_104 -> V_14 = V_14 ;
V_41 = F_107 ( V_106 , V_104 ) ;
if ( V_41 < 0 ) {
F_11 ( V_104 ) ;
return NULL ;
}
return V_104 ;
}
int F_108 ( struct V_103 * V_104 ,
T_1 V_8 , T_3 V_107 , T_3 V_82 )
{
V_104 -> V_108 . V_8 = V_8 ;
V_104 -> V_108 . V_107 = V_107 ;
V_104 -> V_108 . V_109 = V_82 ;
return 0 ;
}
int F_109 ( struct V_103 * V_104 ,
T_3 V_110 , T_2 V_111 )
{
V_104 -> V_108 . V_110 = V_110 ;
V_104 -> V_108 . V_111 = V_111 ;
return 0 ;
}
int F_110 ( struct V_103 * V_104 ,
T_3 V_112 , T_3 V_113 )
{
V_104 -> V_108 . V_112 = V_112 ;
V_104 -> V_108 . V_113 = V_113 ;
return 0 ;
}
int F_111 ( struct V_103 * V_104 , int V_114 ,
T_3 V_115 ,
enum V_116 V_117 ,
T_3 V_118 ,
enum V_116 V_119 )
{
V_104 -> V_108 . V_114 = V_114 ;
V_104 -> V_108 . V_115 = V_115 ;
V_104 -> V_108 . V_118 = V_118 ;
V_104 -> V_108 . V_117 = V_117 ;
V_104 -> V_108 . V_119 = V_119 ;
return 0 ;
}
int F_112 ( struct V_103 * V_104 ,
const void * V_120 , T_5 V_107 )
{
return F_107 ( V_121 , V_104 , V_120 , V_107 ) ;
}
int F_113 ( struct V_103 * V_104 , T_4 V_38 )
{
return F_107 ( V_122 , V_104 , & V_104 -> V_108 , V_38 ) ;
}
int F_114 ( struct V_103 * V_104 , void * V_120 , T_5 V_107 )
{
return F_107 ( V_123 , V_104 , V_120 , V_107 ) ;
}
void F_115 ( struct V_103 * V_104 )
{
F_116 ( V_124 , V_104 ) ;
F_11 ( V_104 ) ;
}
struct V_13 * F_117 ( struct V_103 * V_125 )
{
return V_125 -> V_14 ;
}
void * F_118 ( struct V_103 * V_125 )
{
return & V_125 [ 1 ] ;
}
