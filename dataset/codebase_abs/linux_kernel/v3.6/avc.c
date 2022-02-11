static inline int F_1 ( T_1 V_1 , T_1 V_2 , T_2 V_3 )
{
return ( V_1 ^ ( V_2 << 2 ) ^ ( V_3 << 4 ) ) & ( V_4 - 1 ) ;
}
static void F_2 ( struct V_5 * V_6 , T_2 V_3 , T_1 V_7 )
{
const char * * V_8 ;
int V_9 , V_10 ;
if ( V_7 == 0 ) {
F_3 ( V_6 , L_1 ) ;
return;
}
V_8 = V_11 [ V_3 - 1 ] . V_8 ;
F_3 ( V_6 , L_2 ) ;
V_9 = 0 ;
V_10 = 1 ;
while ( V_9 < ( sizeof( V_7 ) * 8 ) ) {
if ( ( V_10 & V_7 ) && V_8 [ V_9 ] ) {
F_3 ( V_6 , L_3 , V_8 [ V_9 ] ) ;
V_7 &= ~ V_10 ;
}
V_9 ++ ;
V_10 <<= 1 ;
}
if ( V_7 )
F_3 ( V_6 , L_4 , V_7 ) ;
F_3 ( V_6 , L_5 ) ;
}
static void F_4 ( struct V_5 * V_6 , T_1 V_1 , T_1 V_2 , T_2 V_3 )
{
int V_12 ;
char * V_13 ;
T_1 V_14 ;
V_12 = F_5 ( V_1 , & V_13 , & V_14 ) ;
if ( V_12 )
F_3 ( V_6 , L_6 , V_1 ) ;
else {
F_3 ( V_6 , L_7 , V_13 ) ;
F_6 ( V_13 ) ;
}
V_12 = F_5 ( V_2 , & V_13 , & V_14 ) ;
if ( V_12 )
F_3 ( V_6 , L_8 , V_2 ) ;
else {
F_3 ( V_6 , L_9 , V_13 ) ;
F_6 ( V_13 ) ;
}
F_7 ( V_3 >= F_8 ( V_11 ) ) ;
F_3 ( V_6 , L_10 , V_11 [ V_3 - 1 ] . V_15 ) ;
}
void T_3 F_9 ( void )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < V_4 ; V_9 ++ ) {
F_10 ( & V_16 . V_17 [ V_9 ] ) ;
F_11 ( & V_16 . V_18 [ V_9 ] ) ;
}
F_12 ( & V_16 . V_19 , 0 ) ;
F_12 ( & V_16 . V_20 , 0 ) ;
V_21 = F_13 ( L_11 , sizeof( struct V_22 ) ,
0 , V_23 , NULL ) ;
F_14 ( V_24 -> V_25 , V_26 , V_27 , L_12 ) ;
}
int F_15 ( char * V_28 )
{
int V_9 , V_29 , V_30 , V_31 ;
struct V_22 * V_32 ;
struct V_33 * V_34 ;
F_16 () ;
V_31 = 0 ;
V_30 = 0 ;
for ( V_9 = 0 ; V_9 < V_4 ; V_9 ++ ) {
V_34 = & V_16 . V_17 [ V_9 ] ;
if ( ! F_17 ( V_34 ) ) {
struct V_35 * V_36 ;
V_31 ++ ;
V_29 = 0 ;
F_18 (node, next, head, list)
V_29 ++ ;
if ( V_29 > V_30 )
V_30 = V_29 ;
}
}
F_19 () ;
return F_20 ( V_28 , V_37 , L_13
L_14 ,
F_21 ( & V_16 . V_19 ) ,
V_31 , V_4 , V_30 ) ;
}
static void F_22 ( struct V_38 * V_39 )
{
struct V_22 * V_32 = F_23 ( V_39 , struct V_22 , V_39 ) ;
F_24 ( V_21 , V_32 ) ;
F_25 ( V_40 ) ;
}
static void F_26 ( struct V_22 * V_32 )
{
F_27 ( & V_32 -> V_41 ) ;
F_28 ( & V_32 -> V_39 , F_22 ) ;
F_29 ( & V_16 . V_19 ) ;
}
static void F_30 ( struct V_22 * V_32 )
{
F_24 ( V_21 , V_32 ) ;
F_25 ( V_40 ) ;
F_29 ( & V_16 . V_19 ) ;
}
static void F_31 ( struct V_22 * V_42 , struct V_22 * V_43 )
{
F_32 ( & V_43 -> V_41 , & V_42 -> V_41 ) ;
F_28 ( & V_43 -> V_39 , F_22 ) ;
F_29 ( & V_16 . V_19 ) ;
}
static inline int F_33 ( void )
{
struct V_22 * V_32 ;
int V_44 , V_45 , V_46 ;
unsigned long V_47 ;
struct V_33 * V_34 ;
struct V_35 * V_36 ;
T_4 * V_48 ;
for ( V_45 = 0 , V_46 = 0 ; V_45 < V_4 ; V_45 ++ ) {
V_44 = F_34 ( & V_16 . V_20 ) & ( V_4 - 1 ) ;
V_34 = & V_16 . V_17 [ V_44 ] ;
V_48 = & V_16 . V_18 [ V_44 ] ;
if ( ! F_35 ( V_48 , V_47 ) )
continue;
F_16 () ;
F_36 (node, next, head, list) {
F_26 ( V_32 ) ;
F_25 ( V_49 ) ;
V_46 ++ ;
if ( V_46 >= V_50 ) {
F_19 () ;
F_37 ( V_48 , V_47 ) ;
goto V_51;
}
}
F_19 () ;
F_37 ( V_48 , V_47 ) ;
}
V_51:
return V_46 ;
}
static struct V_22 * F_38 ( void )
{
struct V_22 * V_32 ;
V_32 = F_39 ( V_21 , V_52 | V_53 ) ;
if ( ! V_32 )
goto V_51;
F_40 ( & V_32 -> V_41 ) ;
F_25 ( V_54 ) ;
if ( F_34 ( & V_16 . V_19 ) > V_55 )
F_33 () ;
V_51:
return V_32 ;
}
static void F_41 ( struct V_22 * V_32 , T_1 V_1 , T_1 V_2 , T_2 V_3 , struct V_56 * V_57 )
{
V_32 -> V_58 . V_1 = V_1 ;
V_32 -> V_58 . V_2 = V_2 ;
V_32 -> V_58 . V_3 = V_3 ;
memcpy ( & V_32 -> V_58 . V_57 , V_57 , sizeof( V_32 -> V_58 . V_57 ) ) ;
}
static inline struct V_22 * F_42 ( T_1 V_1 , T_1 V_2 , T_2 V_3 )
{
struct V_22 * V_32 , * V_59 = NULL ;
int V_44 ;
struct V_33 * V_34 ;
struct V_35 * V_36 ;
V_44 = F_1 ( V_1 , V_2 , V_3 ) ;
V_34 = & V_16 . V_17 [ V_44 ] ;
F_18 (node, next, head, list) {
if ( V_1 == V_32 -> V_58 . V_1 &&
V_3 == V_32 -> V_58 . V_3 &&
V_2 == V_32 -> V_58 . V_2 ) {
V_59 = V_32 ;
break;
}
}
return V_59 ;
}
static struct V_22 * F_43 ( T_1 V_1 , T_1 V_2 , T_2 V_3 )
{
struct V_22 * V_32 ;
F_25 ( V_60 ) ;
V_32 = F_42 ( V_1 , V_2 , V_3 ) ;
if ( V_32 )
return V_32 ;
F_25 ( V_61 ) ;
return NULL ;
}
static int F_44 ( int V_62 , int V_63 )
{
int V_59 = 0 ;
static F_45 ( V_64 ) ;
unsigned long V_65 ;
F_46 ( & V_64 , V_65 ) ;
if ( V_63 ) {
if ( V_62 < V_16 . V_66 ) {
F_47 ( V_67 L_15 ,
V_62 , V_16 . V_66 ) ;
V_59 = - V_68 ;
}
} else {
if ( V_62 > V_16 . V_66 )
V_16 . V_66 = V_62 ;
}
F_37 ( & V_64 , V_65 ) ;
return V_59 ;
}
static struct V_22 * F_48 ( T_1 V_1 , T_1 V_2 , T_2 V_3 , struct V_56 * V_57 )
{
struct V_22 * V_69 , * V_32 = NULL ;
int V_44 ;
unsigned long V_65 ;
if ( F_44 ( V_57 -> V_62 , 1 ) )
goto V_51;
V_32 = F_38 () ;
if ( V_32 ) {
struct V_33 * V_34 ;
struct V_35 * V_36 ;
T_4 * V_48 ;
V_44 = F_1 ( V_1 , V_2 , V_3 ) ;
F_41 ( V_32 , V_1 , V_2 , V_3 , V_57 ) ;
V_34 = & V_16 . V_17 [ V_44 ] ;
V_48 = & V_16 . V_18 [ V_44 ] ;
F_46 ( V_48 , V_65 ) ;
F_36 (pos, next, head, list) {
if ( V_69 -> V_58 . V_1 == V_1 &&
V_69 -> V_58 . V_2 == V_2 &&
V_69 -> V_58 . V_3 == V_3 ) {
F_31 ( V_32 , V_69 ) ;
goto V_70;
}
}
F_49 ( & V_32 -> V_41 , V_34 ) ;
V_70:
F_37 ( V_48 , V_65 ) ;
}
V_51:
return V_32 ;
}
static void F_50 ( struct V_5 * V_6 , void * V_71 )
{
struct V_72 * V_73 = V_71 ;
F_3 ( V_6 , L_16 ,
V_73 -> V_74 -> V_75 ? L_17 : L_18 ) ;
F_2 ( V_6 , V_73 -> V_74 -> V_3 ,
V_73 -> V_74 -> V_76 ) ;
F_3 ( V_6 , L_19 ) ;
}
static void F_51 ( struct V_5 * V_6 , void * V_71 )
{
struct V_72 * V_73 = V_71 ;
F_3 ( V_6 , L_20 ) ;
F_4 ( V_6 , V_73 -> V_74 -> V_1 ,
V_73 -> V_74 -> V_2 ,
V_73 -> V_74 -> V_3 ) ;
}
T_5 int F_52 ( T_1 V_1 , T_1 V_2 , T_2 V_3 ,
T_1 V_77 , T_1 V_76 , T_1 V_75 ,
struct V_72 * V_71 ,
unsigned V_47 )
{
struct V_72 V_78 ;
struct V_74 V_79 ;
if ( ! V_71 ) {
V_71 = & V_78 ;
V_71 -> type = V_80 ;
}
if ( ( V_71 -> type == V_81 ) &&
( V_47 & V_82 ) )
return - V_83 ;
V_79 . V_3 = V_3 ;
V_79 . V_77 = V_77 ;
V_79 . V_1 = V_1 ;
V_79 . V_2 = V_2 ;
V_79 . V_76 = V_76 ;
V_79 . V_75 = V_75 ;
V_71 -> V_74 = & V_79 ;
F_53 ( V_71 , F_50 , F_51 ) ;
return 0 ;
}
int T_3 F_54 ( int (* F_55)( T_1 V_84 ) , T_1 V_85 )
{
struct V_86 * V_87 ;
int V_12 = 0 ;
V_87 = F_56 ( sizeof( * V_87 ) , V_26 ) ;
if ( ! V_87 ) {
V_12 = - V_88 ;
goto V_51;
}
V_87 -> F_55 = F_55 ;
V_87 -> V_85 = V_85 ;
V_87 -> V_36 = V_89 ;
V_89 = V_87 ;
V_51:
return V_12 ;
}
static inline int F_57 ( T_1 V_90 , T_1 V_91 )
{
return ( V_90 == V_91 || V_90 == V_92 || V_91 == V_92 ) ;
}
static int F_58 ( T_1 V_84 , T_1 V_8 , T_1 V_1 , T_1 V_2 , T_2 V_3 ,
T_1 V_62 )
{
int V_44 , V_12 = 0 ;
unsigned long V_65 ;
struct V_22 * V_69 , * V_32 , * V_93 = NULL ;
struct V_33 * V_34 ;
struct V_35 * V_36 ;
T_4 * V_48 ;
V_32 = F_38 () ;
if ( ! V_32 ) {
V_12 = - V_88 ;
goto V_51;
}
V_44 = F_1 ( V_1 , V_2 , V_3 ) ;
V_34 = & V_16 . V_17 [ V_44 ] ;
V_48 = & V_16 . V_18 [ V_44 ] ;
F_46 ( V_48 , V_65 ) ;
F_36 (pos, next, head, list) {
if ( V_1 == V_69 -> V_58 . V_1 &&
V_2 == V_69 -> V_58 . V_2 &&
V_3 == V_69 -> V_58 . V_3 &&
V_62 == V_69 -> V_58 . V_57 . V_62 ) {
V_93 = V_69 ;
break;
}
}
if ( ! V_93 ) {
V_12 = - V_94 ;
F_30 ( V_32 ) ;
goto V_95;
}
F_41 ( V_32 , V_1 , V_2 , V_3 , & V_93 -> V_58 . V_57 ) ;
switch ( V_84 ) {
case V_96 :
V_32 -> V_58 . V_57 . V_97 |= V_8 ;
break;
case V_98 :
case V_99 :
V_32 -> V_58 . V_57 . V_97 &= ~ V_8 ;
break;
case V_100 :
V_32 -> V_58 . V_57 . V_101 |= V_8 ;
break;
case V_102 :
V_32 -> V_58 . V_57 . V_101 &= ~ V_8 ;
break;
case V_103 :
V_32 -> V_58 . V_57 . V_104 |= V_8 ;
break;
case V_105 :
V_32 -> V_58 . V_57 . V_104 &= ~ V_8 ;
break;
}
F_31 ( V_32 , V_93 ) ;
V_95:
F_37 ( V_48 , V_65 ) ;
V_51:
return V_12 ;
}
static void F_59 ( void )
{
struct V_33 * V_34 ;
struct V_35 * V_36 ;
struct V_22 * V_32 ;
T_4 * V_48 ;
unsigned long V_65 ;
int V_9 ;
for ( V_9 = 0 ; V_9 < V_4 ; V_9 ++ ) {
V_34 = & V_16 . V_17 [ V_9 ] ;
V_48 = & V_16 . V_18 [ V_9 ] ;
F_46 ( V_48 , V_65 ) ;
F_16 () ;
F_36 (node, next, head, list)
F_26 ( V_32 ) ;
F_19 () ;
F_37 ( V_48 , V_65 ) ;
}
}
int F_60 ( T_1 V_62 )
{
struct V_86 * V_87 ;
int V_12 = 0 , V_106 ;
F_59 () ;
for ( V_87 = V_89 ; V_87 ; V_87 = V_87 -> V_36 ) {
if ( V_87 -> V_85 & V_107 ) {
V_106 = V_87 -> F_55 ( V_107 ) ;
if ( ! V_12 )
V_12 = V_106 ;
}
}
F_44 ( V_62 , 0 ) ;
return V_12 ;
}
static T_5 int F_61 ( T_1 V_1 , T_1 V_2 ,
T_2 V_3 , T_1 V_77 ,
unsigned V_47 ,
struct V_56 * V_57 )
{
if ( V_47 & V_108 )
return - V_109 ;
if ( V_110 && ! ( V_57 -> V_47 & V_111 ) )
return - V_109 ;
F_58 ( V_96 , V_77 , V_1 ,
V_2 , V_3 , V_57 -> V_62 ) ;
return 0 ;
}
inline int F_62 ( T_1 V_1 , T_1 V_2 ,
T_2 V_3 , T_1 V_77 ,
unsigned V_47 ,
struct V_56 * V_57 )
{
struct V_22 * V_32 ;
int V_12 = 0 ;
T_1 V_75 ;
F_7 ( ! V_77 ) ;
F_16 () ;
V_32 = F_43 ( V_1 , V_2 , V_3 ) ;
if ( F_63 ( ! V_32 ) ) {
V_32 = F_64 ( V_1 , V_2 , V_3 , V_57 ) ;
} else {
memcpy ( V_57 , & V_32 -> V_58 . V_57 , sizeof( * V_57 ) ) ;
V_57 = & V_32 -> V_58 . V_57 ;
}
V_75 = V_77 & ~ ( V_57 -> V_97 ) ;
if ( F_63 ( V_75 ) )
V_12 = F_61 ( V_1 , V_2 , V_3 , V_77 , V_47 , V_57 ) ;
F_19 () ;
return V_12 ;
}
int F_65 ( T_1 V_1 , T_1 V_2 , T_2 V_3 ,
T_1 V_77 , struct V_72 * V_112 ,
unsigned V_47 )
{
struct V_56 V_57 ;
int V_12 , V_113 ;
V_12 = F_62 ( V_1 , V_2 , V_3 , V_77 , 0 , & V_57 ) ;
V_113 = F_66 ( V_1 , V_2 , V_3 , V_77 , & V_57 , V_12 , V_112 ,
V_47 ) ;
if ( V_113 )
return V_113 ;
return V_12 ;
}
T_1 F_67 ( void )
{
return V_16 . V_66 ;
}
void F_68 ( void )
{
if ( V_21 ) {
F_59 () ;
}
}
