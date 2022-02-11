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
V_31 ++ ;
V_29 = 0 ;
F_18 (node, head, list)
V_29 ++ ;
if ( V_29 > V_30 )
V_30 = V_29 ;
}
}
F_19 () ;
return F_20 ( V_28 , V_35 , L_13
L_14 ,
F_21 ( & V_16 . V_19 ) ,
V_31 , V_4 , V_30 ) ;
}
static void F_22 ( struct V_36 * V_37 )
{
struct V_22 * V_32 = F_23 ( V_37 , struct V_22 , V_37 ) ;
F_24 ( V_21 , V_32 ) ;
F_25 ( V_38 ) ;
}
static void F_26 ( struct V_22 * V_32 )
{
F_27 ( & V_32 -> V_39 ) ;
F_28 ( & V_32 -> V_37 , F_22 ) ;
F_29 ( & V_16 . V_19 ) ;
}
static void F_30 ( struct V_22 * V_32 )
{
F_24 ( V_21 , V_32 ) ;
F_25 ( V_38 ) ;
F_29 ( & V_16 . V_19 ) ;
}
static void F_31 ( struct V_22 * V_40 , struct V_22 * V_41 )
{
F_32 ( & V_41 -> V_39 , & V_40 -> V_39 ) ;
F_28 ( & V_41 -> V_37 , F_22 ) ;
F_29 ( & V_16 . V_19 ) ;
}
static inline int F_33 ( void )
{
struct V_22 * V_32 ;
int V_42 , V_43 , V_44 ;
unsigned long V_45 ;
struct V_33 * V_34 ;
T_4 * V_46 ;
for ( V_43 = 0 , V_44 = 0 ; V_43 < V_4 ; V_43 ++ ) {
V_42 = F_34 ( & V_16 . V_20 ) & ( V_4 - 1 ) ;
V_34 = & V_16 . V_17 [ V_42 ] ;
V_46 = & V_16 . V_18 [ V_42 ] ;
if ( ! F_35 ( V_46 , V_45 ) )
continue;
F_16 () ;
F_36 (node, head, list) {
F_26 ( V_32 ) ;
F_25 ( V_47 ) ;
V_44 ++ ;
if ( V_44 >= V_48 ) {
F_19 () ;
F_37 ( V_46 , V_45 ) ;
goto V_49;
}
}
F_19 () ;
F_37 ( V_46 , V_45 ) ;
}
V_49:
return V_44 ;
}
static struct V_22 * F_38 ( void )
{
struct V_22 * V_32 ;
V_32 = F_39 ( V_21 , V_50 | V_51 ) ;
if ( ! V_32 )
goto V_49;
F_40 ( & V_32 -> V_39 ) ;
F_25 ( V_52 ) ;
if ( F_34 ( & V_16 . V_19 ) > V_53 )
F_33 () ;
V_49:
return V_32 ;
}
static void F_41 ( struct V_22 * V_32 , T_1 V_1 , T_1 V_2 , T_2 V_3 , struct V_54 * V_55 )
{
V_32 -> V_56 . V_1 = V_1 ;
V_32 -> V_56 . V_2 = V_2 ;
V_32 -> V_56 . V_3 = V_3 ;
memcpy ( & V_32 -> V_56 . V_55 , V_55 , sizeof( V_32 -> V_56 . V_55 ) ) ;
}
static inline struct V_22 * F_42 ( T_1 V_1 , T_1 V_2 , T_2 V_3 )
{
struct V_22 * V_32 , * V_57 = NULL ;
int V_42 ;
struct V_33 * V_34 ;
V_42 = F_1 ( V_1 , V_2 , V_3 ) ;
V_34 = & V_16 . V_17 [ V_42 ] ;
F_18 (node, head, list) {
if ( V_1 == V_32 -> V_56 . V_1 &&
V_3 == V_32 -> V_56 . V_3 &&
V_2 == V_32 -> V_56 . V_2 ) {
V_57 = V_32 ;
break;
}
}
return V_57 ;
}
static struct V_22 * F_43 ( T_1 V_1 , T_1 V_2 , T_2 V_3 )
{
struct V_22 * V_32 ;
F_25 ( V_58 ) ;
V_32 = F_42 ( V_1 , V_2 , V_3 ) ;
if ( V_32 )
return V_32 ;
F_25 ( V_59 ) ;
return NULL ;
}
static int F_44 ( int V_60 , int V_61 )
{
int V_57 = 0 ;
static F_45 ( V_62 ) ;
unsigned long V_63 ;
F_46 ( & V_62 , V_63 ) ;
if ( V_61 ) {
if ( V_60 < V_16 . V_64 ) {
F_47 ( V_65 L_15 ,
V_60 , V_16 . V_64 ) ;
V_57 = - V_66 ;
}
} else {
if ( V_60 > V_16 . V_64 )
V_16 . V_64 = V_60 ;
}
F_37 ( & V_62 , V_63 ) ;
return V_57 ;
}
static struct V_22 * F_48 ( T_1 V_1 , T_1 V_2 , T_2 V_3 , struct V_54 * V_55 )
{
struct V_22 * V_67 , * V_32 = NULL ;
int V_42 ;
unsigned long V_63 ;
if ( F_44 ( V_55 -> V_60 , 1 ) )
goto V_49;
V_32 = F_38 () ;
if ( V_32 ) {
struct V_33 * V_34 ;
T_4 * V_46 ;
V_42 = F_1 ( V_1 , V_2 , V_3 ) ;
F_41 ( V_32 , V_1 , V_2 , V_3 , V_55 ) ;
V_34 = & V_16 . V_17 [ V_42 ] ;
V_46 = & V_16 . V_18 [ V_42 ] ;
F_46 ( V_46 , V_63 ) ;
F_36 (pos, head, list) {
if ( V_67 -> V_56 . V_1 == V_1 &&
V_67 -> V_56 . V_2 == V_2 &&
V_67 -> V_56 . V_3 == V_3 ) {
F_31 ( V_32 , V_67 ) ;
goto V_68;
}
}
F_49 ( & V_32 -> V_39 , V_34 ) ;
V_68:
F_37 ( V_46 , V_63 ) ;
}
V_49:
return V_32 ;
}
static void F_50 ( struct V_5 * V_6 , void * V_69 )
{
struct V_70 * V_71 = V_69 ;
F_3 ( V_6 , L_16 ,
V_71 -> V_72 -> V_73 ? L_17 : L_18 ) ;
F_2 ( V_6 , V_71 -> V_72 -> V_3 ,
V_71 -> V_72 -> V_74 ) ;
F_3 ( V_6 , L_19 ) ;
}
static void F_51 ( struct V_5 * V_6 , void * V_69 )
{
struct V_70 * V_71 = V_69 ;
F_3 ( V_6 , L_20 ) ;
F_4 ( V_6 , V_71 -> V_72 -> V_1 ,
V_71 -> V_72 -> V_2 ,
V_71 -> V_72 -> V_3 ) ;
}
T_5 int F_52 ( T_1 V_1 , T_1 V_2 , T_2 V_3 ,
T_1 V_75 , T_1 V_74 , T_1 V_73 ,
struct V_70 * V_69 ,
unsigned V_45 )
{
struct V_70 V_76 ;
struct V_72 V_77 ;
if ( ! V_69 ) {
V_69 = & V_76 ;
V_69 -> type = V_78 ;
}
if ( ( V_69 -> type == V_79 ) &&
( V_45 & V_80 ) )
return - V_81 ;
V_77 . V_3 = V_3 ;
V_77 . V_75 = V_75 ;
V_77 . V_1 = V_1 ;
V_77 . V_2 = V_2 ;
V_77 . V_74 = V_74 ;
V_77 . V_73 = V_73 ;
V_69 -> V_72 = & V_77 ;
F_53 ( V_69 , F_50 , F_51 ) ;
return 0 ;
}
int T_3 F_54 ( int (* F_55)( T_1 V_82 ) , T_1 V_83 )
{
struct V_84 * V_85 ;
int V_12 = 0 ;
V_85 = F_56 ( sizeof( * V_85 ) , V_26 ) ;
if ( ! V_85 ) {
V_12 = - V_86 ;
goto V_49;
}
V_85 -> F_55 = F_55 ;
V_85 -> V_83 = V_83 ;
V_85 -> V_87 = V_88 ;
V_88 = V_85 ;
V_49:
return V_12 ;
}
static inline int F_57 ( T_1 V_89 , T_1 V_90 )
{
return ( V_89 == V_90 || V_89 == V_91 || V_90 == V_91 ) ;
}
static int F_58 ( T_1 V_82 , T_1 V_8 , T_1 V_1 , T_1 V_2 , T_2 V_3 ,
T_1 V_60 )
{
int V_42 , V_12 = 0 ;
unsigned long V_63 ;
struct V_22 * V_67 , * V_32 , * V_92 = NULL ;
struct V_33 * V_34 ;
T_4 * V_46 ;
V_32 = F_38 () ;
if ( ! V_32 ) {
V_12 = - V_86 ;
goto V_49;
}
V_42 = F_1 ( V_1 , V_2 , V_3 ) ;
V_34 = & V_16 . V_17 [ V_42 ] ;
V_46 = & V_16 . V_18 [ V_42 ] ;
F_46 ( V_46 , V_63 ) ;
F_36 (pos, head, list) {
if ( V_1 == V_67 -> V_56 . V_1 &&
V_2 == V_67 -> V_56 . V_2 &&
V_3 == V_67 -> V_56 . V_3 &&
V_60 == V_67 -> V_56 . V_55 . V_60 ) {
V_92 = V_67 ;
break;
}
}
if ( ! V_92 ) {
V_12 = - V_93 ;
F_30 ( V_32 ) ;
goto V_94;
}
F_41 ( V_32 , V_1 , V_2 , V_3 , & V_92 -> V_56 . V_55 ) ;
switch ( V_82 ) {
case V_95 :
V_32 -> V_56 . V_55 . V_96 |= V_8 ;
break;
case V_97 :
case V_98 :
V_32 -> V_56 . V_55 . V_96 &= ~ V_8 ;
break;
case V_99 :
V_32 -> V_56 . V_55 . V_100 |= V_8 ;
break;
case V_101 :
V_32 -> V_56 . V_55 . V_100 &= ~ V_8 ;
break;
case V_102 :
V_32 -> V_56 . V_55 . V_103 |= V_8 ;
break;
case V_104 :
V_32 -> V_56 . V_55 . V_103 &= ~ V_8 ;
break;
}
F_31 ( V_32 , V_92 ) ;
V_94:
F_37 ( V_46 , V_63 ) ;
V_49:
return V_12 ;
}
static void F_59 ( void )
{
struct V_33 * V_34 ;
struct V_22 * V_32 ;
T_4 * V_46 ;
unsigned long V_63 ;
int V_9 ;
for ( V_9 = 0 ; V_9 < V_4 ; V_9 ++ ) {
V_34 = & V_16 . V_17 [ V_9 ] ;
V_46 = & V_16 . V_18 [ V_9 ] ;
F_46 ( V_46 , V_63 ) ;
F_16 () ;
F_36 (node, head, list)
F_26 ( V_32 ) ;
F_19 () ;
F_37 ( V_46 , V_63 ) ;
}
}
int F_60 ( T_1 V_60 )
{
struct V_84 * V_85 ;
int V_12 = 0 , V_105 ;
F_59 () ;
for ( V_85 = V_88 ; V_85 ; V_85 = V_85 -> V_87 ) {
if ( V_85 -> V_83 & V_106 ) {
V_105 = V_85 -> F_55 ( V_106 ) ;
if ( ! V_12 )
V_12 = V_105 ;
}
}
F_44 ( V_60 , 0 ) ;
return V_12 ;
}
static T_5 int F_61 ( T_1 V_1 , T_1 V_2 ,
T_2 V_3 , T_1 V_75 ,
unsigned V_45 ,
struct V_54 * V_55 )
{
if ( V_45 & V_107 )
return - V_108 ;
if ( V_109 && ! ( V_55 -> V_45 & V_110 ) )
return - V_108 ;
F_58 ( V_95 , V_75 , V_1 ,
V_2 , V_3 , V_55 -> V_60 ) ;
return 0 ;
}
inline int F_62 ( T_1 V_1 , T_1 V_2 ,
T_2 V_3 , T_1 V_75 ,
unsigned V_45 ,
struct V_54 * V_55 )
{
struct V_22 * V_32 ;
int V_12 = 0 ;
T_1 V_73 ;
F_7 ( ! V_75 ) ;
F_16 () ;
V_32 = F_43 ( V_1 , V_2 , V_3 ) ;
if ( F_63 ( ! V_32 ) ) {
V_32 = F_64 ( V_1 , V_2 , V_3 , V_55 ) ;
} else {
memcpy ( V_55 , & V_32 -> V_56 . V_55 , sizeof( * V_55 ) ) ;
V_55 = & V_32 -> V_56 . V_55 ;
}
V_73 = V_75 & ~ ( V_55 -> V_96 ) ;
if ( F_63 ( V_73 ) )
V_12 = F_61 ( V_1 , V_2 , V_3 , V_75 , V_45 , V_55 ) ;
F_19 () ;
return V_12 ;
}
int F_65 ( T_1 V_1 , T_1 V_2 , T_2 V_3 ,
T_1 V_75 , struct V_70 * V_111 )
{
struct V_54 V_55 ;
int V_12 , V_112 ;
V_12 = F_62 ( V_1 , V_2 , V_3 , V_75 , 0 , & V_55 ) ;
V_112 = F_66 ( V_1 , V_2 , V_3 , V_75 , & V_55 , V_12 , V_111 ) ;
if ( V_112 )
return V_112 ;
return V_12 ;
}
T_1 F_67 ( void )
{
return V_16 . V_64 ;
}
void F_68 ( void )
{
if ( V_21 ) {
F_59 () ;
}
}
