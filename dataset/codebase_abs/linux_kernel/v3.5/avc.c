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
V_32 = F_39 ( V_21 , V_52 ) ;
if ( ! V_32 )
goto V_51;
F_40 ( & V_32 -> V_41 ) ;
F_25 ( V_53 ) ;
if ( F_34 ( & V_16 . V_19 ) > V_54 )
F_33 () ;
V_51:
return V_32 ;
}
static void F_41 ( struct V_22 * V_32 , T_1 V_1 , T_1 V_2 , T_2 V_3 , struct V_55 * V_56 )
{
V_32 -> V_57 . V_1 = V_1 ;
V_32 -> V_57 . V_2 = V_2 ;
V_32 -> V_57 . V_3 = V_3 ;
memcpy ( & V_32 -> V_57 . V_56 , V_56 , sizeof( V_32 -> V_57 . V_56 ) ) ;
}
static inline struct V_22 * F_42 ( T_1 V_1 , T_1 V_2 , T_2 V_3 )
{
struct V_22 * V_32 , * V_58 = NULL ;
int V_44 ;
struct V_33 * V_34 ;
struct V_35 * V_36 ;
V_44 = F_1 ( V_1 , V_2 , V_3 ) ;
V_34 = & V_16 . V_17 [ V_44 ] ;
F_18 (node, next, head, list) {
if ( V_1 == V_32 -> V_57 . V_1 &&
V_3 == V_32 -> V_57 . V_3 &&
V_2 == V_32 -> V_57 . V_2 ) {
V_58 = V_32 ;
break;
}
}
return V_58 ;
}
static struct V_22 * F_43 ( T_1 V_1 , T_1 V_2 , T_2 V_3 )
{
struct V_22 * V_32 ;
F_25 ( V_59 ) ;
V_32 = F_42 ( V_1 , V_2 , V_3 ) ;
if ( V_32 )
return V_32 ;
F_25 ( V_60 ) ;
return NULL ;
}
static int F_44 ( int V_61 , int V_62 )
{
int V_58 = 0 ;
static F_45 ( V_63 ) ;
unsigned long V_64 ;
F_46 ( & V_63 , V_64 ) ;
if ( V_62 ) {
if ( V_61 < V_16 . V_65 ) {
F_47 ( V_66 L_15 ,
V_61 , V_16 . V_65 ) ;
V_58 = - V_67 ;
}
} else {
if ( V_61 > V_16 . V_65 )
V_16 . V_65 = V_61 ;
}
F_37 ( & V_63 , V_64 ) ;
return V_58 ;
}
static struct V_22 * F_48 ( T_1 V_1 , T_1 V_2 , T_2 V_3 , struct V_55 * V_56 )
{
struct V_22 * V_68 , * V_32 = NULL ;
int V_44 ;
unsigned long V_64 ;
if ( F_44 ( V_56 -> V_61 , 1 ) )
goto V_51;
V_32 = F_38 () ;
if ( V_32 ) {
struct V_33 * V_34 ;
struct V_35 * V_36 ;
T_4 * V_48 ;
V_44 = F_1 ( V_1 , V_2 , V_3 ) ;
F_41 ( V_32 , V_1 , V_2 , V_3 , V_56 ) ;
V_34 = & V_16 . V_17 [ V_44 ] ;
V_48 = & V_16 . V_18 [ V_44 ] ;
F_46 ( V_48 , V_64 ) ;
F_36 (pos, next, head, list) {
if ( V_68 -> V_57 . V_1 == V_1 &&
V_68 -> V_57 . V_2 == V_2 &&
V_68 -> V_57 . V_3 == V_3 ) {
F_31 ( V_32 , V_68 ) ;
goto V_69;
}
}
F_49 ( & V_32 -> V_41 , V_34 ) ;
V_69:
F_37 ( V_48 , V_64 ) ;
}
V_51:
return V_32 ;
}
static void F_50 ( struct V_5 * V_6 , void * V_70 )
{
struct V_71 * V_72 = V_70 ;
F_3 ( V_6 , L_16 ,
V_72 -> V_73 -> V_74 ? L_17 : L_18 ) ;
F_2 ( V_6 , V_72 -> V_73 -> V_3 ,
V_72 -> V_73 -> V_75 ) ;
F_3 ( V_6 , L_19 ) ;
}
static void F_51 ( struct V_5 * V_6 , void * V_70 )
{
struct V_71 * V_72 = V_70 ;
F_3 ( V_6 , L_20 ) ;
F_4 ( V_6 , V_72 -> V_73 -> V_1 ,
V_72 -> V_73 -> V_2 ,
V_72 -> V_73 -> V_3 ) ;
}
T_5 int F_52 ( T_1 V_1 , T_1 V_2 , T_2 V_3 ,
T_1 V_76 , T_1 V_75 , T_1 V_74 ,
struct V_71 * V_70 ,
unsigned V_47 )
{
struct V_71 V_77 ;
struct V_73 V_78 ;
if ( ! V_70 ) {
V_70 = & V_77 ;
V_70 -> type = V_79 ;
}
if ( ( V_70 -> type == V_80 ) &&
( V_47 & V_81 ) )
return - V_82 ;
V_78 . V_3 = V_3 ;
V_78 . V_76 = V_76 ;
V_78 . V_1 = V_1 ;
V_78 . V_2 = V_2 ;
V_78 . V_75 = V_75 ;
V_78 . V_74 = V_74 ;
V_70 -> V_73 = & V_78 ;
F_53 ( V_70 , F_50 , F_51 ) ;
return 0 ;
}
int T_3 F_54 ( int (* F_55)( T_1 V_83 ) , T_1 V_84 )
{
struct V_85 * V_86 ;
int V_12 = 0 ;
V_86 = F_56 ( sizeof( * V_86 ) , V_26 ) ;
if ( ! V_86 ) {
V_12 = - V_87 ;
goto V_51;
}
V_86 -> F_55 = F_55 ;
V_86 -> V_84 = V_84 ;
V_86 -> V_36 = V_88 ;
V_88 = V_86 ;
V_51:
return V_12 ;
}
static inline int F_57 ( T_1 V_89 , T_1 V_90 )
{
return ( V_89 == V_90 || V_89 == V_91 || V_90 == V_91 ) ;
}
static int F_58 ( T_1 V_83 , T_1 V_8 , T_1 V_1 , T_1 V_2 , T_2 V_3 ,
T_1 V_61 )
{
int V_44 , V_12 = 0 ;
unsigned long V_64 ;
struct V_22 * V_68 , * V_32 , * V_92 = NULL ;
struct V_33 * V_34 ;
struct V_35 * V_36 ;
T_4 * V_48 ;
V_32 = F_38 () ;
if ( ! V_32 ) {
V_12 = - V_87 ;
goto V_51;
}
V_44 = F_1 ( V_1 , V_2 , V_3 ) ;
V_34 = & V_16 . V_17 [ V_44 ] ;
V_48 = & V_16 . V_18 [ V_44 ] ;
F_46 ( V_48 , V_64 ) ;
F_36 (pos, next, head, list) {
if ( V_1 == V_68 -> V_57 . V_1 &&
V_2 == V_68 -> V_57 . V_2 &&
V_3 == V_68 -> V_57 . V_3 &&
V_61 == V_68 -> V_57 . V_56 . V_61 ) {
V_92 = V_68 ;
break;
}
}
if ( ! V_92 ) {
V_12 = - V_93 ;
F_30 ( V_32 ) ;
goto V_94;
}
F_41 ( V_32 , V_1 , V_2 , V_3 , & V_92 -> V_57 . V_56 ) ;
switch ( V_83 ) {
case V_95 :
V_32 -> V_57 . V_56 . V_96 |= V_8 ;
break;
case V_97 :
case V_98 :
V_32 -> V_57 . V_56 . V_96 &= ~ V_8 ;
break;
case V_99 :
V_32 -> V_57 . V_56 . V_100 |= V_8 ;
break;
case V_101 :
V_32 -> V_57 . V_56 . V_100 &= ~ V_8 ;
break;
case V_102 :
V_32 -> V_57 . V_56 . V_103 |= V_8 ;
break;
case V_104 :
V_32 -> V_57 . V_56 . V_103 &= ~ V_8 ;
break;
}
F_31 ( V_32 , V_92 ) ;
V_94:
F_37 ( V_48 , V_64 ) ;
V_51:
return V_12 ;
}
static void F_59 ( void )
{
struct V_33 * V_34 ;
struct V_35 * V_36 ;
struct V_22 * V_32 ;
T_4 * V_48 ;
unsigned long V_64 ;
int V_9 ;
for ( V_9 = 0 ; V_9 < V_4 ; V_9 ++ ) {
V_34 = & V_16 . V_17 [ V_9 ] ;
V_48 = & V_16 . V_18 [ V_9 ] ;
F_46 ( V_48 , V_64 ) ;
F_16 () ;
F_36 (node, next, head, list)
F_26 ( V_32 ) ;
F_19 () ;
F_37 ( V_48 , V_64 ) ;
}
}
int F_60 ( T_1 V_61 )
{
struct V_85 * V_86 ;
int V_12 = 0 , V_105 ;
F_59 () ;
for ( V_86 = V_88 ; V_86 ; V_86 = V_86 -> V_36 ) {
if ( V_86 -> V_84 & V_106 ) {
V_105 = V_86 -> F_55 ( V_106 ) ;
if ( ! V_12 )
V_12 = V_105 ;
}
}
F_44 ( V_61 , 0 ) ;
return V_12 ;
}
static T_5 int F_61 ( T_1 V_1 , T_1 V_2 ,
T_2 V_3 , T_1 V_76 ,
unsigned V_47 ,
struct V_55 * V_56 )
{
if ( V_47 & V_107 )
return - V_108 ;
if ( V_109 && ! ( V_56 -> V_47 & V_110 ) )
return - V_108 ;
F_58 ( V_95 , V_76 , V_1 ,
V_2 , V_3 , V_56 -> V_61 ) ;
return 0 ;
}
inline int F_62 ( T_1 V_1 , T_1 V_2 ,
T_2 V_3 , T_1 V_76 ,
unsigned V_47 ,
struct V_55 * V_56 )
{
struct V_22 * V_32 ;
int V_12 = 0 ;
T_1 V_74 ;
F_7 ( ! V_76 ) ;
F_16 () ;
V_32 = F_43 ( V_1 , V_2 , V_3 ) ;
if ( F_63 ( ! V_32 ) ) {
V_32 = F_64 ( V_1 , V_2 , V_3 , V_56 ) ;
} else {
memcpy ( V_56 , & V_32 -> V_57 . V_56 , sizeof( * V_56 ) ) ;
V_56 = & V_32 -> V_57 . V_56 ;
}
V_74 = V_76 & ~ ( V_56 -> V_96 ) ;
if ( F_63 ( V_74 ) )
V_12 = F_61 ( V_1 , V_2 , V_3 , V_76 , V_47 , V_56 ) ;
F_19 () ;
return V_12 ;
}
int F_65 ( T_1 V_1 , T_1 V_2 , T_2 V_3 ,
T_1 V_76 , struct V_71 * V_111 ,
unsigned V_47 )
{
struct V_55 V_56 ;
int V_12 , V_112 ;
V_12 = F_62 ( V_1 , V_2 , V_3 , V_76 , 0 , & V_56 ) ;
V_112 = F_66 ( V_1 , V_2 , V_3 , V_76 , & V_56 , V_12 , V_111 ,
V_47 ) ;
if ( V_112 )
return V_112 ;
return V_12 ;
}
T_1 F_67 ( void )
{
return V_16 . V_65 ;
}
void F_68 ( void )
{
if ( V_21 ) {
F_59 () ;
}
}
