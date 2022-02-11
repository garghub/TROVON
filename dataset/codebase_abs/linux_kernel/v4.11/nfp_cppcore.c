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
struct V_23 * V_24 , * V_25 ;
F_17 ( ! F_18 ( & V_14 -> V_26 ) ) ;
F_19 (mutex, mtmp, &cpp->mutex_cache, list) {
F_20 ( V_14 -> V_27 . V_28 , L_1 ,
V_24 -> V_29 , ( unsigned long long ) V_24 -> V_30 ,
V_24 -> V_31 , V_24 -> V_32 ) ;
V_24 -> V_31 = 1 ;
F_21 ( V_24 ) ;
V_24 -> V_32 = 1 ;
F_22 ( V_24 ) ;
}
F_19 (cache, ctmp, &cpp->area_cache_list, entry) {
F_23 ( & V_20 -> V_33 ) ;
if ( V_20 -> V_34 )
F_24 ( V_20 -> V_12 ) ;
F_25 ( V_20 -> V_12 ) ;
F_11 ( V_20 ) ;
}
F_17 ( ! F_18 ( & V_14 -> V_35 ) ) ;
F_19 (res, rtmp, &cpp->resource_list, list) {
struct V_11 * V_12 = F_3 ( V_4 ,
struct V_11 ,
V_18 ) ;
F_20 ( V_14 -> V_27 . V_28 , L_2 ,
F_26 ( V_4 -> V_8 ) ,
F_27 ( V_4 -> V_8 ) ,
F_28 ( V_4 -> V_8 ) ,
V_4 -> V_9 , V_4 -> V_36 ,
V_4 -> V_37 ? L_3 : L_4 ,
V_4 -> V_37 ? V_4 -> V_37 : L_4 ) ;
if ( V_12 -> V_14 -> V_15 -> V_38 )
V_12 -> V_14 -> V_15 -> V_38 ( V_12 ) ;
F_7 ( & V_12 -> V_10 ) ;
}
if ( V_14 -> V_15 -> free )
V_14 -> V_15 -> free ( V_14 ) ;
F_11 ( V_14 -> V_39 ) ;
F_11 ( V_14 -> V_40 ) ;
F_29 ( & V_14 -> V_27 ) ;
F_11 ( V_14 ) ;
}
T_1 F_30 ( struct V_13 * V_14 )
{
return V_14 -> V_41 ;
}
T_2 F_31 ( struct V_13 * V_14 )
{
return V_14 -> V_42 ;
}
int F_32 ( struct V_13 * V_14 , const T_3 * * V_43 )
{
* V_43 = & V_14 -> V_43 [ 0 ] ;
return sizeof( V_14 -> V_43 ) ;
}
void * F_33 ( struct V_13 * V_14 )
{
return V_14 -> V_39 ;
}
void F_34 ( struct V_13 * V_14 , void * V_44 )
{
V_14 -> V_39 = V_44 ;
}
void * F_35 ( struct V_13 * V_14 )
{
return V_14 -> V_40 ;
}
void F_36 ( struct V_13 * V_14 , void * V_44 )
{
V_14 -> V_40 = V_44 ;
}
void F_37 ( struct V_13 * V_14 )
{
F_11 ( F_35 ( V_14 ) ) ;
F_36 ( V_14 , NULL ) ;
}
struct V_11 *
F_38 ( struct V_13 * V_14 , T_1 V_45 , const char * V_37 ,
unsigned long long V_30 , unsigned long V_46 )
{
struct V_11 * V_12 ;
T_4 V_47 = V_30 ;
int V_48 , V_49 ;
V_48 = F_39 ( V_45 , V_47 , & V_45 , & V_47 , V_14 -> V_50 ) ;
if ( V_48 < 0 )
return NULL ;
V_30 = V_47 ;
if ( ! V_37 )
V_37 = L_5 ;
V_49 = strlen ( V_37 ) + 1 ;
V_12 = F_40 ( sizeof( * V_12 ) + V_14 -> V_15 -> V_51 + V_49 ,
V_52 ) ;
if ( ! V_12 )
return NULL ;
V_12 -> V_14 = V_14 ;
V_12 -> V_18 . V_37 = ( void * ) V_12 + sizeof( * V_12 ) +
V_14 -> V_15 -> V_51 ;
memcpy ( ( char * ) V_12 -> V_18 . V_37 , V_37 , V_49 ) ;
V_12 -> V_18 . V_8 = V_45 ;
V_12 -> V_18 . V_9 = V_30 ;
V_12 -> V_18 . V_36 = V_12 -> V_18 . V_9 + V_46 - 1 ;
F_41 ( & V_12 -> V_18 . V_7 ) ;
F_42 ( & V_12 -> V_53 , 0 ) ;
F_43 ( & V_12 -> V_10 ) ;
F_44 ( & V_12 -> V_24 ) ;
if ( V_14 -> V_15 -> V_54 ) {
int V_48 ;
V_48 = V_14 -> V_15 -> V_54 ( V_12 , V_45 , V_30 , V_46 ) ;
if ( V_48 < 0 ) {
F_11 ( V_12 ) ;
return NULL ;
}
}
F_9 ( & V_14 -> V_17 ) ;
F_1 ( & V_14 -> V_35 , & V_12 -> V_18 ) ;
F_10 ( & V_14 -> V_17 ) ;
V_12 -> V_55 = V_30 ;
V_12 -> V_46 = V_46 ;
return V_12 ;
}
struct V_11 *
F_45 ( struct V_13 * V_14 , T_1 V_45 ,
unsigned long long V_30 , unsigned long V_46 )
{
return F_38 ( V_14 , V_45 , NULL , V_30 , V_46 ) ;
}
void F_25 ( struct V_11 * V_12 )
{
F_12 ( V_12 ) ;
}
int F_46 ( struct V_11 * V_12 )
{
F_47 ( & V_12 -> V_24 ) ;
if ( F_48 ( & V_12 -> V_53 ) == 1 ) {
int (* F_49)( struct V_11 * );
F_49 = V_12 -> V_14 -> V_15 -> V_56 ;
if ( F_49 ) {
int V_48 ;
F_50 ( V_12 -> V_14 -> V_57 ,
( V_48 = F_49 ( V_12 ) ) != - V_58 ) ;
if ( V_48 < 0 ) {
F_51 ( & V_12 -> V_53 ) ;
F_52 ( & V_12 -> V_24 ) ;
return V_48 ;
}
}
}
F_52 ( & V_12 -> V_24 ) ;
F_14 ( V_12 ) ;
return 0 ;
}
int F_53 ( struct V_11 * V_12 )
{
F_47 ( & V_12 -> V_24 ) ;
if ( F_48 ( & V_12 -> V_53 ) == 1 ) {
if ( V_12 -> V_14 -> V_15 -> V_56 ) {
int V_48 ;
V_48 = V_12 -> V_14 -> V_15 -> V_56 ( V_12 ) ;
if ( V_48 < 0 ) {
F_51 ( & V_12 -> V_53 ) ;
F_52 ( & V_12 -> V_24 ) ;
return V_48 ;
}
}
}
F_52 ( & V_12 -> V_24 ) ;
F_14 ( V_12 ) ;
return 0 ;
}
void F_24 ( struct V_11 * V_12 )
{
F_47 ( & V_12 -> V_24 ) ;
if ( F_54 ( & V_12 -> V_53 ) ) {
if ( V_12 -> V_14 -> V_15 -> V_38 ) {
V_12 -> V_14 -> V_15 -> V_38 ( V_12 ) ;
F_55 ( & V_12 -> V_14 -> V_57 ) ;
}
}
F_52 ( & V_12 -> V_24 ) ;
F_12 ( V_12 ) ;
}
void F_56 ( struct V_11 * V_12 )
{
F_24 ( V_12 ) ;
F_25 ( V_12 ) ;
}
int F_57 ( struct V_11 * V_12 ,
unsigned long V_55 , void * V_59 ,
T_5 V_60 )
{
return V_12 -> V_14 -> V_15 -> V_61 ( V_12 , V_59 , V_55 , V_60 ) ;
}
int F_58 ( struct V_11 * V_12 ,
unsigned long V_55 , const void * V_59 ,
T_5 V_60 )
{
return V_12 -> V_14 -> V_15 -> V_62 ( V_12 , V_59 , V_55 , V_60 ) ;
}
int F_59 ( struct V_11 * V_12 ,
unsigned long long V_55 , unsigned long V_60 )
{
if ( V_55 < V_12 -> V_55 ||
V_55 + V_60 > V_12 -> V_55 + V_12 -> V_46 )
return - V_63 ;
return 0 ;
}
const char * F_60 ( struct V_11 * V_64 )
{
return V_64 -> V_18 . V_37 ;
}
void * F_61 ( struct V_11 * V_64 )
{
return & V_64 [ 1 ] ;
}
struct V_13 * F_8 ( struct V_11 * V_64 )
{
return V_64 -> V_14 ;
}
struct V_18 * F_62 ( struct V_11 * V_12 )
{
struct V_18 * V_4 = NULL ;
if ( V_12 -> V_14 -> V_15 -> V_65 )
V_4 = V_12 -> V_14 -> V_15 -> V_65 ( V_12 ) ;
return V_4 ;
}
T_6 F_63 ( struct V_11 * V_12 )
{
T_6 V_66 = ~ 0 ;
if ( V_12 -> V_14 -> V_15 -> V_67 )
V_66 = V_12 -> V_14 -> V_15 -> V_67 ( V_12 ) ;
return V_66 ;
}
void T_7 * F_64 ( struct V_11 * V_12 )
{
void T_7 * V_68 = NULL ;
if ( V_12 -> V_14 -> V_15 -> V_69 )
V_68 = V_12 -> V_14 -> V_15 -> V_69 ( V_12 ) ;
return V_68 ;
}
int F_65 ( struct V_11 * V_12 ,
unsigned long V_55 , T_1 * V_70 )
{
T_3 V_5 [ 4 ] ;
int V_48 ;
V_48 = F_57 ( V_12 , V_55 , & V_5 , sizeof( V_5 ) ) ;
* V_70 = F_66 ( V_5 ) ;
return V_48 ;
}
int F_67 ( struct V_11 * V_12 ,
unsigned long V_55 , T_1 V_70 )
{
T_3 V_5 [ 4 ] ;
F_68 ( V_70 , V_5 ) ;
return F_58 ( V_12 , V_55 , & V_5 , sizeof( V_5 ) ) ;
}
int F_69 ( struct V_11 * V_12 ,
unsigned long V_55 , T_4 * V_70 )
{
T_3 V_5 [ 8 ] ;
int V_48 ;
V_48 = F_57 ( V_12 , V_55 , & V_5 , sizeof( V_5 ) ) ;
* V_70 = F_70 ( V_5 ) ;
return V_48 ;
}
int F_71 ( struct V_11 * V_12 ,
unsigned long V_55 , T_4 V_70 )
{
T_3 V_5 [ 8 ] ;
F_72 ( V_70 , V_5 ) ;
return F_58 ( V_12 , V_55 , & V_5 , sizeof( V_5 ) ) ;
}
int F_73 ( struct V_11 * V_12 ,
unsigned long V_55 , T_1 V_70 , T_5 V_60 )
{
T_3 V_5 [ 4 ] ;
T_5 V_71 ;
int V_72 ;
F_68 ( V_70 , V_5 ) ;
if ( V_55 % sizeof( V_5 ) || V_60 % sizeof( V_5 ) )
return - V_73 ;
for ( V_71 = 0 ; V_71 < V_60 ; V_71 += sizeof( V_5 ) ) {
V_72 = F_58 ( V_12 , V_55 + V_71 , & V_5 , sizeof( V_5 ) ) ;
if ( V_72 < 0 )
return V_72 ;
}
return V_71 ;
}
int F_74 ( struct V_13 * V_14 , T_5 V_46 )
{
struct V_19 * V_20 ;
struct V_11 * V_12 ;
V_12 = F_45 ( V_14 , F_75 ( 7 , V_74 , 0 ) ,
0 , V_46 ) ;
if ( ! V_12 )
return - V_75 ;
V_20 = F_40 ( sizeof( * V_20 ) , V_52 ) ;
if ( ! V_20 )
return - V_75 ;
V_20 -> V_34 = 0 ;
V_20 -> V_66 = 0 ;
V_20 -> V_46 = V_46 ;
V_20 -> V_12 = V_12 ;
F_47 ( & V_14 -> V_76 ) ;
F_4 ( & V_20 -> V_33 , & V_14 -> V_77 ) ;
F_52 ( & V_14 -> V_76 ) ;
return 0 ;
}
static struct V_19 *
F_76 ( struct V_13 * V_14 , T_1 V_34 ,
T_4 V_66 , unsigned long * V_55 , T_5 V_60 )
{
struct V_19 * V_20 ;
int V_48 ;
if ( V_60 == 0 )
return NULL ;
if ( F_18 ( & V_14 -> V_77 ) || V_34 == 0 )
return NULL ;
V_48 = F_39 ( V_34 , V_66 , & V_34 , & V_66 , V_14 -> V_50 ) ;
if ( V_48 < 0 )
return NULL ;
V_66 += * V_55 ;
F_47 ( & V_14 -> V_76 ) ;
F_77 (cache, &cpp->area_cache_list, entry) {
if ( V_34 == V_20 -> V_34 &&
V_66 >= V_20 -> V_66 &&
V_66 + V_60 <= V_20 -> V_66 + V_20 -> V_46 )
goto exit;
}
V_20 = F_78 ( V_14 -> V_77 . V_78 ,
struct V_19 , V_33 ) ;
if ( F_79 ( V_66 + V_60 - 1 , V_20 -> V_46 ) !=
F_79 ( V_66 , V_20 -> V_46 ) ) {
F_52 ( & V_14 -> V_76 ) ;
return NULL ;
}
if ( V_20 -> V_34 ) {
F_24 ( V_20 -> V_12 ) ;
V_20 -> V_34 = 0 ;
V_20 -> V_66 = 0 ;
}
V_20 -> V_34 = V_34 ;
V_20 -> V_66 = V_66 & ~ ( T_4 ) ( V_20 -> V_46 - 1 ) ;
if ( V_14 -> V_15 -> V_54 ) {
V_48 = V_14 -> V_15 -> V_54 ( V_20 -> V_12 ,
V_34 , V_20 -> V_66 , V_20 -> V_46 ) ;
if ( V_48 < 0 ) {
F_52 ( & V_14 -> V_76 ) ;
return NULL ;
}
}
V_48 = F_46 ( V_20 -> V_12 ) ;
if ( V_48 < 0 ) {
F_52 ( & V_14 -> V_76 ) ;
return NULL ;
}
exit:
* V_55 = V_66 - V_20 -> V_66 ;
return V_20 ;
}
static void
F_80 ( struct V_13 * V_14 , struct V_19 * V_20 )
{
if ( ! V_20 )
return;
F_23 ( & V_20 -> V_33 ) ;
F_81 ( & V_20 -> V_33 , & V_14 -> V_77 ) ;
F_52 ( & V_14 -> V_76 ) ;
}
int F_82 ( struct V_13 * V_14 , T_1 V_79 ,
unsigned long long V_30 , void * V_59 , T_5 V_60 )
{
struct V_19 * V_20 ;
struct V_11 * V_12 ;
unsigned long V_55 = 0 ;
int V_48 ;
V_20 = F_76 ( V_14 , V_79 , V_30 , & V_55 , V_60 ) ;
if ( V_20 ) {
V_12 = V_20 -> V_12 ;
} else {
V_12 = F_45 ( V_14 , V_79 , V_30 , V_60 ) ;
if ( ! V_12 )
return - V_75 ;
V_48 = F_46 ( V_12 ) ;
if ( V_48 )
goto V_80;
}
V_48 = F_57 ( V_12 , V_55 , V_59 , V_60 ) ;
V_80:
if ( V_20 )
F_80 ( V_14 , V_20 ) ;
else
F_56 ( V_12 ) ;
return V_48 ;
}
int F_83 ( struct V_13 * V_14 , T_1 V_79 ,
unsigned long long V_30 ,
const void * V_59 , T_5 V_60 )
{
struct V_19 * V_20 ;
struct V_11 * V_12 ;
unsigned long V_55 = 0 ;
int V_48 ;
V_20 = F_76 ( V_14 , V_79 , V_30 , & V_55 , V_60 ) ;
if ( V_20 ) {
V_12 = V_20 -> V_12 ;
} else {
V_12 = F_45 ( V_14 , V_79 , V_30 , V_60 ) ;
if ( ! V_12 )
return - V_75 ;
V_48 = F_46 ( V_12 ) ;
if ( V_48 )
goto V_80;
}
V_48 = F_58 ( V_12 , V_55 , V_59 , V_60 ) ;
V_80:
if ( V_20 )
F_80 ( V_14 , V_20 ) ;
else
F_56 ( V_12 ) ;
return V_48 ;
}
static T_1 F_84 ( struct V_13 * V_14 , T_1 * V_81 )
{
int V_82 ;
T_1 V_83 ;
V_83 = F_75 ( 14 , V_74 , 0 ) ;
V_82 = ( * V_81 >> 24 ) & 0x3f ;
if ( ! V_82 )
return V_83 ;
if ( V_82 != 1 ) {
* V_81 |= 1 << 30 ;
return V_83 ;
}
* V_81 &= ~ 0x7f000000 ;
if ( * V_81 < 0x60000 ) {
* V_81 |= 1 << 30 ;
} else {
if ( F_85 ( F_31 ( V_14 ) )
!= V_84 )
* V_81 |= 1 << 24 ;
}
return V_83 ;
}
int F_86 ( struct V_13 * V_14 , T_1 V_81 , T_1 * V_70 )
{
T_1 V_85 = F_84 ( V_14 , & V_81 ) ;
return F_87 ( V_14 , V_85 , V_81 , V_70 ) ;
}
int F_88 ( struct V_13 * V_14 , T_1 V_81 , T_1 V_70 )
{
T_1 V_85 = F_84 ( V_14 , & V_81 ) ;
return F_89 ( V_14 , V_85 , V_81 , V_70 ) ;
}
int F_90 ( struct V_13 * V_14 , T_1 V_86 ,
T_1 V_87 , T_1 V_70 )
{
int V_48 ;
T_1 V_5 ;
V_48 = F_86 ( V_14 , V_86 , & V_5 ) ;
if ( V_48 < 0 )
return V_48 ;
V_5 &= ~ V_87 ;
V_5 |= V_87 & V_70 ;
return F_88 ( V_14 , V_86 , V_5 ) ;
}
static void F_91 ( struct V_88 * V_27 )
{
}
struct V_13 *
F_92 ( const struct V_89 * V_90 ,
struct V_88 * V_28 , void * V_91 )
{
const T_1 V_92 = F_75 ( V_93 , V_74 , 0 ) ;
struct V_13 * V_14 ;
T_1 V_87 [ 2 ] ;
T_1 V_94 ;
T_5 V_95 ;
int V_48 ;
V_14 = F_40 ( sizeof( * V_14 ) , V_52 ) ;
if ( ! V_14 ) {
V_48 = - V_75 ;
goto V_96;
}
V_14 -> V_15 = V_90 ;
V_14 -> V_91 = V_91 ;
V_14 -> V_42 = V_90 -> V_97 ( V_28 ) ;
if ( V_90 -> V_98 )
V_90 -> V_98 ( V_28 , V_14 -> V_43 ) ;
F_93 ( & V_14 -> V_17 ) ;
F_94 ( & V_14 -> V_57 ) ;
F_95 ( & V_14 -> V_17 , & V_99 ) ;
F_41 ( & V_14 -> V_26 ) ;
F_41 ( & V_14 -> V_35 ) ;
F_41 ( & V_14 -> V_77 ) ;
F_44 ( & V_14 -> V_76 ) ;
V_14 -> V_27 . V_100 = L_6 ;
V_14 -> V_27 . V_28 = V_28 ;
V_14 -> V_27 . V_101 = F_91 ;
V_48 = F_96 ( & V_14 -> V_27 ) ;
if ( V_48 < 0 ) {
F_97 ( & V_14 -> V_27 ) ;
goto V_102;
}
F_98 ( & V_14 -> V_27 , V_14 ) ;
if ( V_14 -> V_15 -> V_103 ) {
V_48 = V_14 -> V_15 -> V_103 ( V_14 ) ;
if ( V_48 < 0 ) {
F_20 ( V_28 ,
L_7 ) ;
goto V_104;
}
}
V_48 = F_99 ( V_14 , & V_14 -> V_41 ) ;
if ( V_48 < 0 ) {
F_20 ( V_28 , L_8 ) ;
goto V_104;
}
for ( V_95 = 0 ; V_95 < F_100 ( V_14 -> V_50 ) ; V_95 ++ ) {
V_94 = 0x000a0000 + ( V_95 * 4 ) ;
V_48 = F_86 ( V_14 , V_94 ,
& V_14 -> V_50 [ V_95 ] ) ;
if ( V_48 < 0 ) {
F_20 ( V_28 ,
L_9 ) ;
goto V_104;
}
}
F_87 ( V_14 , V_92 , V_105 + V_106 ,
& V_87 [ 0 ] ) ;
F_87 ( V_14 , V_92 , V_105 + V_107 ,
& V_87 [ 1 ] ) ;
F_101 ( V_14 -> V_27 . V_28 , L_10 ,
F_30 ( V_14 ) , V_14 -> V_43 , F_31 ( V_14 ) ) ;
return V_14 ;
V_104:
F_29 ( & V_14 -> V_27 ) ;
V_102:
F_11 ( V_14 ) ;
V_96:
return F_102 ( V_48 ) ;
}
void * F_103 ( struct V_13 * V_14 )
{
return V_14 -> V_91 ;
}
struct V_88 * F_104 ( struct V_13 * V_14 )
{
return & V_14 -> V_27 ;
}
struct V_108 * F_105 ( struct V_13 * V_14 )
{
struct V_108 * V_109 ;
int V_48 ;
V_109 = F_40 ( sizeof( * V_109 ) + V_14 -> V_15 -> V_110 , V_52 ) ;
if ( ! V_109 )
return NULL ;
V_109 -> V_14 = V_14 ;
V_48 = F_106 ( V_111 , V_109 ) ;
if ( V_48 < 0 ) {
F_11 ( V_109 ) ;
return NULL ;
}
return V_109 ;
}
int F_107 ( struct V_108 * V_109 ,
T_1 V_8 , T_3 V_112 , T_3 V_87 )
{
V_109 -> V_113 . V_8 = V_8 ;
V_109 -> V_113 . V_112 = V_112 ;
V_109 -> V_113 . V_114 = V_87 ;
return 0 ;
}
int F_108 ( struct V_108 * V_109 ,
T_3 V_115 , T_2 V_116 )
{
V_109 -> V_113 . V_115 = V_115 ;
V_109 -> V_113 . V_116 = V_116 ;
return 0 ;
}
int F_109 ( struct V_108 * V_109 ,
T_3 V_117 , T_3 V_118 )
{
V_109 -> V_113 . V_117 = V_117 ;
V_109 -> V_113 . V_118 = V_118 ;
return 0 ;
}
int F_110 ( struct V_108 * V_109 , int V_119 ,
T_3 V_120 ,
enum V_121 V_122 ,
T_3 V_123 ,
enum V_121 V_124 )
{
V_109 -> V_113 . V_119 = V_119 ;
V_109 -> V_113 . V_120 = V_120 ;
V_109 -> V_113 . V_123 = V_123 ;
V_109 -> V_113 . V_122 = V_122 ;
V_109 -> V_113 . V_124 = V_124 ;
return 0 ;
}
int F_111 ( struct V_108 * V_109 ,
const void * V_125 , T_5 V_112 )
{
return F_106 ( V_126 , V_109 , V_125 , V_112 ) ;
}
int F_112 ( struct V_108 * V_109 , T_4 V_30 )
{
return F_106 ( V_127 , V_109 , & V_109 -> V_113 , V_30 ) ;
}
int F_113 ( struct V_108 * V_109 , void * V_125 , T_5 V_112 )
{
return F_106 ( V_128 , V_109 , V_125 , V_112 ) ;
}
void F_114 ( struct V_108 * V_109 )
{
F_115 ( V_129 , V_109 ) ;
F_11 ( V_109 ) ;
}
struct V_13 * F_116 ( struct V_108 * V_130 )
{
return V_130 -> V_14 ;
}
void * F_117 ( struct V_108 * V_130 )
{
return & V_130 [ 1 ] ;
}
static T_1 F_118 ( T_2 V_42 )
{
return ( T_1 ) V_42 << 16 | 0x000f ;
}
static T_1 F_119 ( T_2 V_42 )
{
return ( T_1 ) V_42 << 16 | 0x0000 ;
}
static bool F_120 ( T_1 V_44 )
{
return ( V_44 & 0xffff ) == 0x000f ;
}
static bool F_121 ( T_1 V_44 )
{
return ( V_44 & 0xffff ) == 0000 ;
}
static int
F_122 ( T_2 V_42 , int * V_29 , unsigned long long V_30 )
{
if ( F_85 ( V_42 ) ==
V_131 )
return - V_73 ;
if ( V_30 & 7 )
return - V_73 ;
if ( * V_29 != V_132 )
return - V_73 ;
return 0 ;
}
int F_123 ( struct V_13 * V_14 ,
int V_29 , unsigned long long V_30 , T_1 V_133 )
{
const T_1 V_134 = F_75 ( V_29 , 4 , 0 ) ;
T_2 V_42 = F_31 ( V_14 ) ;
int V_48 ;
V_48 = F_122 ( V_42 , & V_29 , V_30 ) ;
if ( V_48 )
return V_48 ;
V_48 = F_89 ( V_14 , V_134 , V_30 + 4 , V_133 ) ;
if ( V_48 )
return V_48 ;
V_48 = F_89 ( V_14 , V_134 , V_30 , F_118 ( V_42 ) ) ;
if ( V_48 )
return V_48 ;
return 0 ;
}
struct V_23 * F_124 ( struct V_13 * V_14 , int V_29 ,
unsigned long long V_30 , T_1 V_133 )
{
const T_1 V_135 = F_75 ( V_29 , 3 , 0 ) ;
T_2 V_42 = F_31 ( V_14 ) ;
struct V_23 * V_24 ;
int V_48 ;
T_1 V_5 ;
V_48 = F_122 ( V_42 , & V_29 , V_30 ) ;
if ( V_48 )
return NULL ;
F_77 (mutex, &cpp->mutex_cache, list) {
if ( V_24 -> V_29 == V_29 && V_24 -> V_30 == V_30 ) {
V_24 -> V_32 ++ ;
return V_24 ;
}
}
V_48 = F_87 ( V_14 , V_135 , V_30 + 4 , & V_5 ) ;
if ( V_48 < 0 )
return NULL ;
if ( V_5 != V_133 )
return NULL ;
V_24 = F_40 ( sizeof( * V_24 ) , V_52 ) ;
if ( ! V_24 )
return NULL ;
V_24 -> V_14 = V_14 ;
V_24 -> V_29 = V_29 ;
V_24 -> V_30 = V_30 ;
V_24 -> V_133 = V_133 ;
V_24 -> V_31 = 0 ;
V_24 -> V_32 = 1 ;
F_81 ( & V_24 -> V_7 , & V_14 -> V_26 ) ;
return V_24 ;
}
void F_22 ( struct V_23 * V_24 )
{
if ( -- V_24 -> V_32 )
return;
F_23 ( & V_24 -> V_7 ) ;
F_11 ( V_24 ) ;
}
int F_125 ( struct V_23 * V_24 )
{
unsigned long V_136 = V_137 + 15 * V_138 ;
unsigned int V_139 = 1 ;
int V_48 ;
for (; ; ) {
V_48 = F_126 ( V_24 ) ;
if ( V_48 != - V_140 )
break;
V_48 = F_127 ( V_139 ) ;
if ( V_48 != 0 )
return - V_141 ;
if ( F_128 ( V_136 ) ) {
V_136 = V_137 + 60 * V_138 ;
F_129 ( V_24 -> V_14 -> V_27 . V_28 ,
L_11 ,
V_24 -> V_32 , V_24 -> V_31 ,
V_24 -> V_29 , V_24 -> V_30 , V_24 -> V_133 ) ;
}
}
return V_48 ;
}
int F_21 ( struct V_23 * V_24 )
{
const T_1 V_134 = F_75 ( V_24 -> V_29 , 4 , 0 ) ;
const T_1 V_135 = F_75 ( V_24 -> V_29 , 3 , 0 ) ;
struct V_13 * V_14 = V_24 -> V_14 ;
T_1 V_133 , V_70 ;
T_2 V_42 ;
int V_48 ;
V_42 = F_31 ( V_14 ) ;
if ( V_24 -> V_31 > 1 ) {
V_24 -> V_31 -- ;
return 0 ;
}
V_48 = F_87 ( V_24 -> V_14 , V_135 , V_24 -> V_30 + 4 , & V_133 ) ;
if ( V_48 < 0 )
return V_48 ;
if ( V_133 != V_24 -> V_133 )
return - V_142 ;
V_48 = F_87 ( V_24 -> V_14 , V_135 , V_24 -> V_30 , & V_70 ) ;
if ( V_48 < 0 )
return V_48 ;
if ( V_70 != F_118 ( V_42 ) )
return - V_143 ;
V_48 = F_89 ( V_14 , V_134 , V_24 -> V_30 ,
F_119 ( V_42 ) ) ;
if ( V_48 < 0 )
return V_48 ;
V_24 -> V_31 = 0 ;
return 0 ;
}
int F_126 ( struct V_23 * V_24 )
{
const T_1 V_134 = F_75 ( V_24 -> V_29 , 4 , 0 ) ;
const T_1 V_144 = F_75 ( V_24 -> V_29 , 5 , 3 ) ;
const T_1 V_135 = F_75 ( V_24 -> V_29 , 3 , 0 ) ;
struct V_13 * V_14 = V_24 -> V_14 ;
T_1 V_133 , V_70 , V_5 ;
int V_48 ;
if ( V_24 -> V_31 > 0 ) {
if ( V_24 -> V_31 == V_145 )
return - V_146 ;
V_24 -> V_31 ++ ;
return 0 ;
}
V_48 = F_87 ( V_14 , V_135 , V_24 -> V_30 + 4 , & V_133 ) ;
if ( V_48 < 0 )
return V_48 ;
if ( V_133 != V_24 -> V_133 )
return - V_142 ;
V_70 = F_118 ( F_31 ( V_14 ) ) ;
V_48 = F_87 ( V_14 , V_144 , V_24 -> V_30 , & V_5 ) ;
if ( V_48 < 0 )
return V_48 ;
if ( F_121 ( V_5 ) ) {
V_48 = F_89 ( V_14 , V_134 , V_24 -> V_30 , V_70 ) ;
if ( V_48 < 0 )
return V_48 ;
V_24 -> V_31 = 1 ;
return 0 ;
}
if ( V_5 == V_70 ) {
V_24 -> V_31 = 1 ;
return 0 ;
}
return F_120 ( V_5 ) ? - V_140 : - V_73 ;
}
