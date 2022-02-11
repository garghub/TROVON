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
if ( V_71 -> V_72 -> V_73 ) {
F_3 ( V_6 , L_21 ,
V_71 -> V_72 -> V_75 ? 0 : 1 ) ;
}
}
T_5 int F_52 ( T_1 V_1 , T_1 V_2 , T_2 V_3 ,
T_1 V_76 , T_1 V_74 , T_1 V_73 , int V_75 ,
struct V_70 * V_69 ,
unsigned V_45 )
{
struct V_70 V_77 ;
struct V_72 V_78 ;
if ( ! V_69 ) {
V_69 = & V_77 ;
V_69 -> type = V_79 ;
}
if ( ( V_69 -> type == V_80 ) &&
( V_45 & V_81 ) )
return - V_82 ;
V_78 . V_3 = V_3 ;
V_78 . V_76 = V_76 ;
V_78 . V_1 = V_1 ;
V_78 . V_2 = V_2 ;
V_78 . V_74 = V_74 ;
V_78 . V_73 = V_73 ;
V_78 . V_75 = V_75 ;
V_69 -> V_72 = & V_78 ;
F_53 ( V_69 , F_50 , F_51 ) ;
return 0 ;
}
int T_3 F_54 ( int (* F_55)( T_1 V_83 ) , T_1 V_84 )
{
struct V_85 * V_86 ;
int V_12 = 0 ;
V_86 = F_56 ( sizeof( * V_86 ) , V_26 ) ;
if ( ! V_86 ) {
V_12 = - V_87 ;
goto V_49;
}
V_86 -> F_55 = F_55 ;
V_86 -> V_84 = V_84 ;
V_86 -> V_88 = V_89 ;
V_89 = V_86 ;
V_49:
return V_12 ;
}
static int F_57 ( T_1 V_83 , T_1 V_8 , T_1 V_1 , T_1 V_2 , T_2 V_3 ,
T_1 V_60 )
{
int V_42 , V_12 = 0 ;
unsigned long V_63 ;
struct V_22 * V_67 , * V_32 , * V_90 = NULL ;
struct V_33 * V_34 ;
T_4 * V_46 ;
V_32 = F_38 () ;
if ( ! V_32 ) {
V_12 = - V_87 ;
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
V_90 = V_67 ;
break;
}
}
if ( ! V_90 ) {
V_12 = - V_91 ;
F_30 ( V_32 ) ;
goto V_92;
}
F_41 ( V_32 , V_1 , V_2 , V_3 , & V_90 -> V_56 . V_55 ) ;
switch ( V_83 ) {
case V_93 :
V_32 -> V_56 . V_55 . V_94 |= V_8 ;
break;
case V_95 :
case V_96 :
V_32 -> V_56 . V_55 . V_94 &= ~ V_8 ;
break;
case V_97 :
V_32 -> V_56 . V_55 . V_98 |= V_8 ;
break;
case V_99 :
V_32 -> V_56 . V_55 . V_98 &= ~ V_8 ;
break;
case V_100 :
V_32 -> V_56 . V_55 . V_101 |= V_8 ;
break;
case V_102 :
V_32 -> V_56 . V_55 . V_101 &= ~ V_8 ;
break;
}
F_31 ( V_32 , V_90 ) ;
V_92:
F_37 ( V_46 , V_63 ) ;
V_49:
return V_12 ;
}
static void F_58 ( void )
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
int F_59 ( T_1 V_60 )
{
struct V_85 * V_86 ;
int V_12 = 0 , V_103 ;
F_58 () ;
for ( V_86 = V_89 ; V_86 ; V_86 = V_86 -> V_88 ) {
if ( V_86 -> V_84 & V_104 ) {
V_103 = V_86 -> F_55 ( V_104 ) ;
if ( ! V_12 )
V_12 = V_103 ;
}
}
F_44 ( V_60 , 0 ) ;
return V_12 ;
}
static T_5 int F_60 ( T_1 V_1 , T_1 V_2 ,
T_2 V_3 , T_1 V_76 ,
unsigned V_45 ,
struct V_54 * V_55 )
{
if ( V_45 & V_105 )
return - V_106 ;
if ( V_107 && ! ( V_55 -> V_45 & V_108 ) )
return - V_106 ;
F_57 ( V_93 , V_76 , V_1 ,
V_2 , V_3 , V_55 -> V_60 ) ;
return 0 ;
}
inline int F_61 ( T_1 V_1 , T_1 V_2 ,
T_2 V_3 , T_1 V_76 ,
unsigned V_45 ,
struct V_54 * V_55 )
{
struct V_22 * V_32 ;
int V_12 = 0 ;
T_1 V_73 ;
F_7 ( ! V_76 ) ;
F_16 () ;
V_32 = F_43 ( V_1 , V_2 , V_3 ) ;
if ( F_62 ( ! V_32 ) ) {
V_32 = F_63 ( V_1 , V_2 , V_3 , V_55 ) ;
} else {
memcpy ( V_55 , & V_32 -> V_56 . V_55 , sizeof( * V_55 ) ) ;
V_55 = & V_32 -> V_56 . V_55 ;
}
V_73 = V_76 & ~ ( V_55 -> V_94 ) ;
if ( F_62 ( V_73 ) )
V_12 = F_60 ( V_1 , V_2 , V_3 , V_76 , V_45 , V_55 ) ;
F_19 () ;
return V_12 ;
}
int F_64 ( T_1 V_1 , T_1 V_2 , T_2 V_3 ,
T_1 V_76 , struct V_70 * V_109 )
{
struct V_54 V_55 ;
int V_12 , V_110 ;
V_12 = F_61 ( V_1 , V_2 , V_3 , V_76 , 0 , & V_55 ) ;
V_110 = F_65 ( V_1 , V_2 , V_3 , V_76 , & V_55 , V_12 , V_109 ) ;
if ( V_110 )
return V_110 ;
return V_12 ;
}
T_1 F_66 ( void )
{
return V_16 . V_64 ;
}
void F_67 ( void )
{
if ( V_21 ) {
F_58 () ;
}
}
