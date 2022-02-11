static int F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 )
return F_2 ( & V_2 -> V_4 ) ;
else
return 1 ;
}
static int F_3 ( struct V_1 * V_5 ,
struct V_6 * V_7 , int V_8 )
{
struct V_1 * V_2 ;
unsigned long V_9 ;
F_4 ( & V_7 -> V_10 , V_9 ) ;
F_5 (t, &card->transaction_list, link) {
if ( V_2 == V_5 ) {
if ( ! F_1 ( V_2 ) ) {
F_6 ( & V_7 -> V_10 , V_9 ) ;
goto V_11;
}
F_7 ( & V_2 -> V_12 ) ;
V_7 -> V_13 &= ~ ( 1ULL << V_2 -> V_14 ) ;
break;
}
}
F_6 ( & V_7 -> V_10 , V_9 ) ;
if ( & V_2 -> V_12 != & V_7 -> V_15 ) {
V_2 -> V_16 ( V_7 , V_8 , NULL , 0 , V_2 -> V_17 ) ;
return 0 ;
}
V_11:
return - V_18 ;
}
int F_8 ( struct V_6 * V_7 ,
struct V_1 * V_5 )
{
if ( V_7 -> V_19 -> V_20 ( V_7 , & V_5 -> V_21 ) == 0 )
return 0 ;
return F_3 ( V_5 , V_7 , V_22 ) ;
}
static void F_9 ( unsigned long V_23 )
{
struct V_1 * V_2 = (struct V_1 * ) V_23 ;
struct V_6 * V_7 = V_2 -> V_7 ;
unsigned long V_9 ;
F_4 ( & V_7 -> V_10 , V_9 ) ;
if ( F_10 ( & V_2 -> V_12 ) ) {
F_6 ( & V_7 -> V_10 , V_9 ) ;
return;
}
F_11 ( & V_2 -> V_12 ) ;
V_7 -> V_13 &= ~ ( 1ULL << V_2 -> V_14 ) ;
F_6 ( & V_7 -> V_10 , V_9 ) ;
V_2 -> V_16 ( V_7 , V_22 , NULL , 0 , V_2 -> V_17 ) ;
}
static void F_12 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
unsigned long V_9 ;
F_4 ( & V_7 -> V_10 , V_9 ) ;
if ( F_10 ( & V_2 -> V_12 ) || F_13 ( V_2 -> V_3 ) ) {
F_6 ( & V_7 -> V_10 , V_9 ) ;
return;
}
V_2 -> V_3 = true ;
F_14 ( & V_2 -> V_4 ,
V_24 + V_7 -> V_25 ) ;
F_6 ( & V_7 -> V_10 , V_9 ) ;
}
static void F_15 ( struct V_26 * V_21 ,
struct V_6 * V_7 , int V_27 )
{
struct V_1 * V_2 =
F_16 ( V_21 , struct V_1 , V_21 ) ;
switch ( V_27 ) {
case V_28 :
F_3 ( V_2 , V_7 , V_29 ) ;
break;
case V_30 :
F_12 ( V_2 , V_7 ) ;
break;
case V_31 :
case V_32 :
case V_33 :
F_3 ( V_2 , V_7 , V_34 ) ;
break;
case V_35 :
F_3 ( V_2 , V_7 , V_36 ) ;
break;
case V_37 :
F_3 ( V_2 , V_7 , V_38 ) ;
break;
default:
F_3 ( V_2 , V_7 , V_27 ) ;
break;
}
}
static void F_17 ( struct V_26 * V_21 , int V_39 , int V_14 ,
int V_40 , int V_41 , int V_42 , int V_43 ,
unsigned long long V_44 , void * V_45 , T_1 V_46 )
{
int V_47 ;
if ( V_39 == V_48 ) {
V_21 -> V_49 [ 0 ] =
F_18 ( V_46 ) |
V_40 |
F_19 ( V_48 ) ;
V_21 -> V_50 = 4 ;
V_21 -> V_45 = V_45 ;
V_21 -> V_51 = V_46 ;
goto V_52;
}
if ( V_39 > 0x10 ) {
V_47 = V_39 & ~ 0x10 ;
V_39 = V_53 ;
} else
V_47 = 0 ;
V_21 -> V_49 [ 0 ] =
F_20 ( V_54 ) |
F_21 ( V_14 ) |
F_19 ( V_39 ) |
F_22 ( V_40 ) ;
V_21 -> V_49 [ 1 ] =
F_23 ( V_44 >> 32 ) | F_24 ( V_41 ) ;
V_21 -> V_49 [ 2 ] =
V_44 ;
switch ( V_39 ) {
case V_55 :
V_21 -> V_49 [ 3 ] = * ( V_56 * ) V_45 ;
V_21 -> V_50 = 16 ;
V_21 -> V_51 = 0 ;
break;
case V_53 :
case V_57 :
V_21 -> V_49 [ 3 ] =
F_18 ( V_46 ) |
F_25 ( V_47 ) ;
V_21 -> V_50 = 16 ;
V_21 -> V_45 = V_45 ;
V_21 -> V_51 = V_46 ;
break;
case V_58 :
V_21 -> V_50 = 12 ;
V_21 -> V_51 = 0 ;
break;
case V_59 :
V_21 -> V_49 [ 3 ] =
F_18 ( V_46 ) |
F_25 ( V_47 ) ;
V_21 -> V_50 = 16 ;
V_21 -> V_51 = 0 ;
break;
default:
F_26 ( 1 , L_1 , V_39 ) ;
}
V_52:
V_21 -> V_43 = V_43 ;
V_21 -> V_42 = V_42 ;
V_21 -> V_60 = 0 ;
V_21 -> V_61 = false ;
}
static int F_27 ( struct V_6 * V_7 )
{
int V_14 ;
V_14 = V_7 -> V_62 ;
while ( V_7 -> V_13 & ( 1ULL << V_14 ) ) {
V_14 = ( V_14 + 1 ) & 0x3f ;
if ( V_14 == V_7 -> V_62 )
return - V_63 ;
}
V_7 -> V_62 = ( V_14 + 1 ) & 0x3f ;
V_7 -> V_13 |= 1ULL << V_14 ;
return V_14 ;
}
void F_28 ( struct V_6 * V_7 , struct V_1 * V_2 , int V_39 ,
int V_40 , int V_42 , int V_43 ,
unsigned long long V_44 , void * V_45 , T_1 V_46 ,
T_2 V_16 , void * V_17 )
{
unsigned long V_9 ;
int V_14 ;
F_4 ( & V_7 -> V_10 , V_9 ) ;
V_14 = F_27 ( V_7 ) ;
if ( V_14 < 0 ) {
F_6 ( & V_7 -> V_10 , V_9 ) ;
V_16 ( V_7 , V_64 , NULL , 0 , V_17 ) ;
return;
}
V_2 -> V_65 = V_40 ;
V_2 -> V_14 = V_14 ;
V_2 -> V_7 = V_7 ;
V_2 -> V_3 = false ;
F_29 ( & V_2 -> V_4 ,
F_9 , ( unsigned long ) V_2 ) ;
V_2 -> V_16 = V_16 ;
V_2 -> V_17 = V_17 ;
F_17 ( & V_2 -> V_21 , V_39 , V_2 -> V_14 ,
V_40 , V_7 -> V_65 , V_42 ,
V_43 , V_44 , V_45 , V_46 ) ;
V_2 -> V_21 . V_16 = F_15 ;
F_30 ( & V_2 -> V_12 , & V_7 -> V_15 ) ;
F_6 ( & V_7 -> V_10 , V_9 ) ;
V_7 -> V_19 -> V_66 ( V_7 , & V_2 -> V_21 ) ;
}
static void F_31 ( struct V_6 * V_7 , int V_8 ,
void * V_45 , T_1 V_46 , void * V_23 )
{
struct V_67 * V_68 = V_23 ;
if ( V_8 == V_29 )
memcpy ( V_68 -> V_45 , V_45 , V_46 ) ;
V_68 -> V_8 = V_8 ;
F_32 ( & V_68 -> V_69 ) ;
}
int F_33 ( struct V_6 * V_7 , int V_39 , int V_40 ,
int V_42 , int V_43 , unsigned long long V_44 ,
void * V_45 , T_1 V_46 )
{
struct V_67 V_68 ;
struct V_1 V_2 ;
F_34 ( & V_2 . V_4 ) ;
F_35 ( & V_68 . V_69 ) ;
V_68 . V_45 = V_45 ;
F_28 ( V_7 , & V_2 , V_39 , V_40 , V_42 , V_43 ,
V_44 , V_45 , V_46 , F_31 , & V_68 ) ;
F_36 ( & V_68 . V_69 ) ;
F_37 ( & V_2 . V_4 ) ;
return V_68 . V_8 ;
}
static void F_38 ( struct V_26 * V_21 ,
struct V_6 * V_7 , int V_27 )
{
F_32 ( & V_70 ) ;
}
void F_39 ( struct V_6 * V_7 ,
int V_65 , int V_42 , int V_71 )
{
long V_72 = F_40 ( V_73 , 10 ) ;
V_56 V_23 = F_41 ( V_74 ) ;
if ( V_65 != V_75 )
V_23 |= F_42 ( V_65 ) ;
if ( V_71 == V_76 ) {
V_71 = V_7 -> V_19 -> V_77 ( V_7 , 1 ) ;
if ( V_71 < 0 )
return;
V_71 &= 63 ;
if ( V_71 == 63 )
return;
}
V_23 |= F_43 ( V_71 ) ;
F_44 ( & V_78 ) ;
V_79 . V_49 [ 1 ] = V_23 ;
V_79 . V_49 [ 2 ] = ~ V_23 ;
V_79 . V_42 = V_42 ;
F_45 ( & V_70 ) ;
V_7 -> V_19 -> V_66 ( V_7 , & V_79 ) ;
F_46 ( & V_70 , V_72 ) ;
F_47 ( & V_78 ) ;
}
static struct V_80 * F_48 (
struct V_81 * V_82 , unsigned long long V_44 , T_1 V_46 )
{
struct V_80 * V_83 ;
F_49 (handler, list, link) {
if ( V_83 -> V_44 < V_44 + V_46 &&
V_44 < V_83 -> V_44 + V_83 -> V_46 )
return V_83 ;
}
return NULL ;
}
static bool F_50 ( struct V_80 * V_83 ,
unsigned long long V_44 , T_1 V_46 )
{
return V_83 -> V_44 <= V_44 &&
V_44 + V_46 <= V_83 -> V_44 + V_83 -> V_46 ;
}
static struct V_80 * F_51 (
struct V_81 * V_82 , unsigned long long V_44 , T_1 V_46 )
{
struct V_80 * V_83 ;
F_49 (handler, list, link) {
if ( F_50 ( V_83 , V_44 , V_46 ) )
return V_83 ;
}
return NULL ;
}
static bool F_52 ( T_3 V_44 , T_1 V_46 )
{
return V_44 >= ( V_84 | V_85 ) &&
V_44 + V_46 <= ( V_84 | V_86 ) ;
}
int F_53 ( struct V_80 * V_83 ,
const struct V_87 * V_88 )
{
struct V_80 * V_89 ;
int V_90 = - V_63 ;
if ( V_88 -> V_91 & 0xffff000000000003ULL ||
V_88 -> V_91 >= V_88 -> V_92 ||
V_88 -> V_92 > 0x0001000000000000ULL ||
V_83 -> V_46 & 3 ||
V_83 -> V_46 == 0 )
return - V_93 ;
F_54 ( & V_94 ) ;
V_83 -> V_44 = V_88 -> V_91 ;
while ( V_83 -> V_44 + V_83 -> V_46 <= V_88 -> V_92 ) {
if ( F_52 ( V_83 -> V_44 , V_83 -> V_46 ) )
V_89 = NULL ;
else
V_89 = F_48
( & V_95 ,
V_83 -> V_44 , V_83 -> V_46 ) ;
if ( V_89 != NULL ) {
V_83 -> V_44 += V_89 -> V_46 ;
} else {
F_55 ( & V_83 -> V_12 , & V_95 ) ;
V_90 = 0 ;
break;
}
}
F_56 ( & V_94 ) ;
return V_90 ;
}
void F_57 ( struct V_80 * V_83 )
{
F_54 ( & V_94 ) ;
F_58 ( & V_83 -> V_12 ) ;
F_56 ( & V_94 ) ;
F_59 () ;
}
static void F_60 ( struct V_26 * V_21 ,
struct V_6 * V_7 , int V_27 )
{
struct V_96 * V_97 ;
V_97 = F_16 ( V_21 , struct V_96 , V_98 ) ;
F_61 ( V_97 ) ;
}
int F_62 ( struct V_96 * V_99 )
{
int V_39 , V_47 , V_100 ;
V_39 = F_63 ( V_99 -> V_101 [ 0 ] ) ;
switch ( V_39 ) {
case V_55 :
case V_57 :
return 0 ;
case V_58 :
return 4 ;
case V_59 :
V_100 = F_64 ( V_99 -> V_101 [ 3 ] ) ;
return V_100 ;
case V_53 :
V_47 = F_65 ( V_99 -> V_101 [ 3 ] ) ;
V_100 = F_64 ( V_99 -> V_101 [ 3 ] ) ;
switch ( V_47 ) {
case V_102 :
case V_103 :
return V_100 ;
default:
return V_100 / 2 ;
}
default:
F_26 ( 1 , L_1 , V_39 ) ;
return 0 ;
}
}
void F_66 ( struct V_26 * V_98 , V_56 * V_101 ,
int V_8 , void * V_45 , T_1 V_46 )
{
int V_39 , V_14 , V_104 , V_105 , V_106 ;
V_39 = F_63 ( V_101 [ 0 ] ) ;
V_14 = F_67 ( V_101 [ 0 ] ) ;
V_105 = F_68 ( V_101 [ 0 ] ) ;
V_106 = F_69 ( V_101 [ 1 ] ) ;
V_104 = F_65 ( V_101 [ 3 ] ) ;
V_98 -> V_49 [ 0 ] =
F_20 ( V_107 ) |
F_21 ( V_14 ) |
F_22 ( V_106 ) ;
V_98 -> V_49 [ 1 ] =
F_24 ( V_105 ) |
F_70 ( V_8 ) ;
V_98 -> V_49 [ 2 ] = 0 ;
switch ( V_39 ) {
case V_55 :
case V_57 :
V_98 -> V_49 [ 0 ] |= F_19 ( V_108 ) ;
V_98 -> V_50 = 12 ;
V_98 -> V_51 = 0 ;
break;
case V_58 :
V_98 -> V_49 [ 0 ] |=
F_19 ( V_109 ) ;
if ( V_45 != NULL )
V_98 -> V_49 [ 3 ] = * ( V_56 * ) V_45 ;
else
V_98 -> V_49 [ 3 ] = 0 ;
V_98 -> V_50 = 16 ;
V_98 -> V_51 = 0 ;
break;
case V_59 :
case V_53 :
V_98 -> V_49 [ 0 ] |= F_19 ( V_39 + 2 ) ;
V_98 -> V_49 [ 3 ] =
F_18 ( V_46 ) |
F_25 ( V_104 ) ;
V_98 -> V_50 = 16 ;
V_98 -> V_45 = V_45 ;
V_98 -> V_51 = V_46 ;
break;
default:
F_26 ( 1 , L_1 , V_39 ) ;
}
V_98 -> V_61 = false ;
}
static V_56 F_71 ( struct V_6 * V_7 ,
V_56 V_110 )
{
unsigned int V_111 ;
V_56 V_112 ;
V_111 = V_7 -> V_113 ;
V_111 += V_110 & 0x1fff ;
V_112 = V_110 & ~ 0x1fff ;
V_112 += ( V_111 / 8000 ) << 13 ;
V_112 |= V_111 % 8000 ;
return V_112 ;
}
static struct V_96 * F_72 ( struct V_6 * V_7 ,
struct V_26 * V_114 )
{
struct V_96 * V_97 ;
V_56 * V_23 , V_46 ;
int V_115 ;
V_115 = F_63 ( V_114 -> V_49 [ 0 ] ) ;
switch ( V_115 ) {
case V_55 :
V_23 = & V_114 -> V_49 [ 3 ] ;
V_46 = 4 ;
break;
case V_57 :
case V_53 :
V_23 = V_114 -> V_45 ;
V_46 = F_64 ( V_114 -> V_49 [ 3 ] ) ;
break;
case V_58 :
V_23 = NULL ;
V_46 = 4 ;
break;
case V_59 :
V_23 = NULL ;
V_46 = F_64 ( V_114 -> V_49 [ 3 ] ) ;
break;
default:
F_73 ( V_7 , L_2 ,
V_114 -> V_49 [ 0 ] , V_114 -> V_49 [ 1 ] , V_114 -> V_49 [ 2 ] ) ;
return NULL ;
}
V_97 = F_74 ( sizeof( * V_97 ) + V_46 , V_116 ) ;
if ( V_97 == NULL )
return NULL ;
V_97 -> V_98 . V_43 = V_114 -> V_43 ;
V_97 -> V_98 . V_112 =
F_71 ( V_7 , V_114 -> V_112 ) ;
V_97 -> V_98 . V_42 = V_114 -> V_42 ;
V_97 -> V_98 . V_60 = 0 ;
V_97 -> V_98 . V_16 = F_60 ;
V_97 -> V_60 = V_114 -> V_60 ;
V_97 -> V_46 = V_46 ;
if ( V_23 )
memcpy ( V_97 -> V_23 , V_23 , V_46 ) ;
memcpy ( V_97 -> V_101 , V_114 -> V_49 , sizeof( V_114 -> V_49 ) ) ;
return V_97 ;
}
void F_75 ( struct V_6 * V_7 ,
struct V_96 * V_97 , int V_8 )
{
if ( F_76 ( ! V_97 , L_3 ) )
return;
if ( V_97 -> V_60 != V_30 ||
F_77 ( V_97 -> V_101 [ 0 ] ) ) {
F_61 ( V_97 ) ;
return;
}
if ( V_8 == V_29 )
F_66 ( & V_97 -> V_98 , V_97 -> V_101 ,
V_8 , V_97 -> V_23 ,
F_62 ( V_97 ) ) ;
else
F_66 ( & V_97 -> V_98 , V_97 -> V_101 ,
V_8 , NULL , 0 ) ;
V_7 -> V_19 -> V_117 ( V_7 , & V_97 -> V_98 ) ;
}
int F_78 ( struct V_96 * V_97 )
{
return V_97 -> V_98 . V_43 ;
}
static void F_79 ( struct V_6 * V_7 ,
struct V_26 * V_114 ,
struct V_96 * V_97 ,
unsigned long long V_44 )
{
struct V_80 * V_83 ;
int V_39 , V_106 , V_105 ;
V_106 = F_68 ( V_114 -> V_49 [ 0 ] ) ;
V_105 = F_69 ( V_114 -> V_49 [ 1 ] ) ;
V_39 = F_63 ( V_114 -> V_49 [ 0 ] ) ;
if ( V_39 == V_53 )
V_39 = 0x10 + F_65 ( V_114 -> V_49 [ 3 ] ) ;
F_80 () ;
V_83 = F_51 ( & V_95 ,
V_44 , V_97 -> V_46 ) ;
if ( V_83 )
V_83 -> V_118 ( V_7 , V_97 ,
V_39 , V_106 , V_105 ,
V_114 -> V_42 , V_44 ,
V_97 -> V_23 , V_97 -> V_46 ,
V_83 -> V_17 ) ;
F_81 () ;
if ( ! V_83 )
F_75 ( V_7 , V_97 , V_119 ) ;
}
static void F_82 ( struct V_6 * V_7 ,
struct V_26 * V_114 ,
struct V_96 * V_97 ,
unsigned long long V_44 )
{
struct V_80 * V_83 ;
int V_39 , V_106 , V_105 ;
if ( ( V_44 != ( V_84 | V_85 ) &&
V_44 != ( V_84 | V_120 ) ) ||
V_97 -> V_46 > 0x200 ) {
F_75 ( V_7 , V_97 , V_119 ) ;
return;
}
V_39 = F_63 ( V_114 -> V_49 [ 0 ] ) ;
V_106 = F_68 ( V_114 -> V_49 [ 0 ] ) ;
V_105 = F_69 ( V_114 -> V_49 [ 1 ] ) ;
if ( V_39 != V_55 &&
V_39 != V_57 ) {
F_75 ( V_7 , V_97 , V_38 ) ;
return;
}
F_80 () ;
F_49 (handler, &address_handler_list, link) {
if ( F_50 ( V_83 , V_44 , V_97 -> V_46 ) )
V_83 -> V_118 ( V_7 , NULL , V_39 ,
V_106 , V_105 ,
V_114 -> V_42 , V_44 ,
V_97 -> V_23 ,
V_97 -> V_46 ,
V_83 -> V_17 ) ;
}
F_81 () ;
F_75 ( V_7 , V_97 , V_29 ) ;
}
void F_83 ( struct V_6 * V_7 , struct V_26 * V_114 )
{
struct V_96 * V_97 ;
unsigned long long V_44 ;
if ( V_114 -> V_60 != V_30 && V_114 -> V_60 != V_28 )
return;
if ( F_84 ( F_63 ( V_114 -> V_49 [ 0 ] ) ) ) {
F_85 ( V_7 , V_114 ) ;
return;
}
V_97 = F_72 ( V_7 , V_114 ) ;
if ( V_97 == NULL ) {
return;
}
V_44 = ( ( T_3 ) F_86 ( V_114 -> V_49 [ 1 ] ) << 32 ) |
V_114 -> V_49 [ 2 ] ;
if ( ! F_52 ( V_44 , V_97 -> V_46 ) )
F_79 ( V_7 , V_114 , V_97 , V_44 ) ;
else
F_82 ( V_7 , V_114 , V_97 , V_44 ) ;
}
void F_87 ( struct V_6 * V_7 , struct V_26 * V_114 )
{
struct V_1 * V_2 ;
unsigned long V_9 ;
V_56 * V_23 ;
T_1 V_100 ;
int V_39 , V_14 , V_105 , V_8 ;
V_39 = F_63 ( V_114 -> V_49 [ 0 ] ) ;
V_14 = F_67 ( V_114 -> V_49 [ 0 ] ) ;
V_105 = F_69 ( V_114 -> V_49 [ 1 ] ) ;
V_8 = F_88 ( V_114 -> V_49 [ 1 ] ) ;
F_4 ( & V_7 -> V_10 , V_9 ) ;
F_5 (t, &card->transaction_list, link) {
if ( V_2 -> V_65 == V_105 && V_2 -> V_14 == V_14 ) {
if ( ! F_1 ( V_2 ) ) {
F_6 ( & V_7 -> V_10 , V_9 ) ;
goto V_11;
}
F_7 ( & V_2 -> V_12 ) ;
V_7 -> V_13 &= ~ ( 1ULL << V_2 -> V_14 ) ;
break;
}
}
F_6 ( & V_7 -> V_10 , V_9 ) ;
if ( & V_2 -> V_12 == & V_7 -> V_15 ) {
V_11:
F_73 ( V_7 , L_4 ,
V_105 , V_14 ) ;
return;
}
switch ( V_39 ) {
case V_109 :
V_23 = ( V_56 * ) & V_114 -> V_49 [ 3 ] ;
V_100 = 4 ;
break;
case V_108 :
V_23 = NULL ;
V_100 = 0 ;
break;
case V_121 :
case V_122 :
V_23 = V_114 -> V_45 ;
V_100 = F_64 ( V_114 -> V_49 [ 3 ] ) ;
break;
default:
V_23 = NULL ;
V_100 = 0 ;
break;
}
V_7 -> V_19 -> V_20 ( V_7 , & V_2 -> V_21 ) ;
V_2 -> V_16 ( V_7 , V_8 , V_23 , V_100 , V_2 -> V_17 ) ;
}
const char * F_89 ( int V_8 )
{
static const char * const V_123 [] = {
[ V_29 ] = L_5 ,
[ V_124 ] = L_6 ,
[ V_36 ] = L_7 ,
[ V_38 ] = L_8 ,
[ V_119 ] = L_9 ,
[ V_64 ] = L_10 ,
[ V_22 ] = L_11 ,
[ V_34 ] = L_12 ,
[ V_125 ] = L_13 ,
[ V_126 ] = L_14 ,
} ;
if ( ( unsigned int ) V_8 < F_90 ( V_123 ) && V_123 [ V_8 ] )
return V_123 [ V_8 ] ;
else
return L_15 ;
}
static void F_91 ( struct V_6 * V_7 , struct V_96 * V_97 ,
int V_39 , int V_106 , int V_105 , int V_42 ,
unsigned long long V_44 , void * V_45 , T_1 V_46 ,
void * V_17 )
{
int V_91 ;
if ( ! F_92 ( V_39 ) ) {
F_75 ( V_7 , V_97 , V_38 ) ;
return;
}
if ( ( V_44 & 3 ) > 0 || ( V_46 & 3 ) > 0 ) {
F_75 ( V_7 , V_97 , V_119 ) ;
return;
}
V_91 = ( V_44 - V_127 . V_91 ) / 4 ;
memcpy ( V_45 , & V_7 -> V_128 [ V_91 ] , V_46 ) ;
F_75 ( V_7 , V_97 , V_29 ) ;
}
static void F_93 ( struct V_6 * V_7 )
{
unsigned int V_111 ;
V_111 = V_7 -> V_129 * 8000 + ( V_7 -> V_130 >> 19 ) ;
V_111 = F_94 ( V_111 , 800u , 3u * 8000u ) ;
V_7 -> V_113 = V_111 ;
V_7 -> V_25 = F_40 ( V_111 * V_73 , 8000 ) ;
}
static void F_95 ( struct V_6 * V_7 , struct V_96 * V_97 ,
int V_39 , int V_106 , int V_105 , int V_42 ,
unsigned long long V_44 , void * V_45 , T_1 V_46 ,
void * V_17 )
{
int V_131 = V_44 & ~ V_84 ;
T_4 * V_23 = V_45 ;
int V_8 = V_29 ;
unsigned long V_9 ;
switch ( V_131 ) {
case V_132 :
if ( ! V_7 -> V_133 ) {
V_8 = V_119 ;
break;
}
case V_134 :
case V_135 :
case V_136 :
case V_137 :
case V_138 :
case V_139 :
if ( V_39 == V_58 )
* V_23 = F_96 ( V_7 -> V_19 -> V_140 ( V_7 , V_131 ) ) ;
else if ( V_39 == V_55 )
V_7 -> V_19 -> V_141 ( V_7 , V_131 , F_97 ( * V_23 ) ) ;
else
V_8 = V_38 ;
break;
case V_142 :
if ( V_39 == V_55 )
V_7 -> V_19 -> V_141 ( V_7 , V_135 ,
V_143 ) ;
else
V_8 = V_38 ;
break;
case V_144 :
if ( V_39 == V_58 ) {
* V_23 = F_96 ( V_7 -> V_129 ) ;
} else if ( V_39 == V_55 ) {
F_4 ( & V_7 -> V_10 , V_9 ) ;
V_7 -> V_129 = F_97 ( * V_23 ) & 7 ;
F_93 ( V_7 ) ;
F_6 ( & V_7 -> V_10 , V_9 ) ;
} else {
V_8 = V_38 ;
}
break;
case V_145 :
if ( V_39 == V_58 ) {
* V_23 = F_96 ( V_7 -> V_130 ) ;
} else if ( V_39 == V_55 ) {
F_4 ( & V_7 -> V_10 , V_9 ) ;
V_7 -> V_130 =
F_97 ( * V_23 ) & 0xfff80000 ;
F_93 ( V_7 ) ;
F_6 ( & V_7 -> V_10 , V_9 ) ;
} else {
V_8 = V_38 ;
}
break;
case V_146 :
if ( V_39 == V_58 )
* V_23 = V_7 -> V_147 ;
else if ( V_39 == V_55 )
V_7 -> V_147 = * V_23 ;
else
V_8 = V_38 ;
break;
case V_148 :
if ( V_39 == V_58 )
* V_23 = F_96 ( V_7 -> V_149 ) ;
else if ( V_39 == V_55 )
V_7 -> V_149 =
( F_97 ( * V_23 ) & V_150 ) |
V_151 ;
else
V_8 = V_38 ;
break;
case V_152 :
case V_153 :
case V_154 :
case V_155 :
F_98 () ;
break;
default:
V_8 = V_119 ;
break;
}
F_75 ( V_7 , V_97 , V_8 ) ;
}
static void F_99 ( struct V_6 * V_7 , struct V_96 * V_97 ,
int V_39 , int V_106 , int V_105 , int V_42 ,
unsigned long long V_44 , void * V_45 , T_1 V_46 ,
void * V_17 )
{
F_75 ( V_7 , V_97 , V_38 ) ;
}
static int T_5 F_100 ( void )
{
int V_90 ;
V_156 = F_101 ( L_16 , V_157 , 0 ) ;
if ( ! V_156 )
return - V_158 ;
V_90 = F_102 ( & V_159 ) ;
if ( V_90 < 0 ) {
F_103 ( V_156 ) ;
return V_90 ;
}
V_160 = F_104 ( 0 , L_16 , & V_161 ) ;
if ( V_160 < 0 ) {
F_105 ( & V_159 ) ;
F_103 ( V_156 ) ;
return V_160 ;
}
F_53 ( & V_128 , & V_127 ) ;
F_53 ( & V_162 , & V_163 ) ;
F_53 ( & V_164 , & V_165 ) ;
F_106 ( & V_166 ) ;
F_106 ( & V_167 ) ;
return 0 ;
}
static void T_6 F_107 ( void )
{
F_108 ( V_160 , L_16 ) ;
F_105 ( & V_159 ) ;
F_103 ( V_156 ) ;
F_109 ( & V_168 ) ;
}
