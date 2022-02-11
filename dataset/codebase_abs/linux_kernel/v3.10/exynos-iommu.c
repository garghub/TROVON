static unsigned long * F_1 ( unsigned long * V_1 , unsigned long V_2 )
{
return V_1 + F_2 ( V_2 ) ;
}
static unsigned long * F_3 ( unsigned long * V_3 , unsigned long V_2 )
{
return ( unsigned long * ) F_4 ( F_5 ( V_3 ) ) + F_6 ( V_2 ) ;
}
static bool F_7 ( struct V_4 * V_5 )
{
return ++ V_5 -> V_6 == 1 ;
}
static bool F_8 ( struct V_4 * V_5 )
{
F_9 ( V_5 -> V_6 < 1 ) ;
return -- V_5 -> V_6 == 0 ;
}
static bool F_10 ( struct V_4 * V_5 )
{
return V_5 -> V_6 > 0 ;
}
static void F_11 ( void T_1 * V_7 )
{
F_12 ( V_8 , V_7 + V_9 ) ;
}
static bool F_13 ( void T_1 * V_7 )
{
int V_10 = 120 ;
F_12 ( V_11 , V_7 + V_9 ) ;
while ( ( V_10 > 0 ) && ! ( F_14 ( V_7 + V_12 ) & 1 ) )
-- V_10 ;
if ( ! ( F_14 ( V_7 + V_12 ) & 1 ) ) {
F_11 ( V_7 ) ;
return false ;
}
return true ;
}
static void F_15 ( void T_1 * V_7 )
{
F_12 ( 0x1 , V_7 + V_13 ) ;
}
static void F_16 ( void T_1 * V_7 ,
unsigned long V_2 )
{
F_12 ( ( V_2 & V_14 ) | 1 , V_7 + V_15 ) ;
}
static void F_17 ( void T_1 * V_7 ,
unsigned long V_16 )
{
F_12 ( 0x1 , V_7 + V_17 ) ;
F_12 ( V_16 , V_7 + V_18 ) ;
F_15 ( V_7 ) ;
}
static void F_18 ( void T_1 * V_7 , unsigned long V_19 ,
unsigned long V_20 , int V_21 )
{
F_12 ( V_19 , V_7 + V_22 + V_21 * 8 ) ;
F_12 ( V_20 - 1 + V_19 , V_7 + V_23 + V_21 * 8 ) ;
}
void F_19 ( struct V_24 * V_25 ,
unsigned long V_26 , unsigned long V_27 ,
unsigned long V_28 , unsigned long V_29 )
{
struct V_4 * V_5 = F_20 ( V_25 -> V_30 . V_31 ) ;
unsigned long V_32 ;
int V_10 ;
F_9 ( ( V_26 + V_27 ) <= V_26 ) ;
F_9 ( ( V_29 > 0 ) && ( ( V_28 + V_29 ) <= V_28 ) ) ;
F_21 ( & V_5 -> V_33 , V_32 ) ;
if ( ! F_10 ( V_5 ) )
goto V_34;
for ( V_10 = 0 ; V_10 < V_5 -> V_35 ; V_10 ++ ) {
if ( ( F_22 ( V_5 -> V_36 [ V_10 ] + V_37 ) >> 28 ) == 3 ) {
if ( ! F_13 ( V_5 -> V_36 [ V_10 ] ) )
continue;
if ( V_29 == 0 ) {
if ( V_27 <= V_38 ) {
V_28 = V_26 ;
V_29 = V_27 ;
} else {
V_29 = V_27 -
F_23 ( V_27 / 2 , V_39 ) ;
V_27 = V_27 - V_29 ;
V_28 = V_26 + V_27 ;
}
}
F_18 (
V_5 -> V_36 [ V_10 ] , V_26 , V_27 , 0 ) ;
F_18 (
V_5 -> V_36 [ V_10 ] , V_28 , V_29 , 1 ) ;
F_11 ( V_5 -> V_36 [ V_10 ] ) ;
}
}
V_34:
F_24 ( & V_5 -> V_33 , V_32 ) ;
}
static void F_25 ( struct V_4 * V_5 ,
T_2 V_40 )
{
unsigned long V_32 ;
F_26 ( & V_5 -> V_33 , V_32 ) ;
V_5 -> V_41 = V_40 ;
F_27 ( & V_5 -> V_33 , V_32 ) ;
}
void F_28 ( struct V_24 * V_25 ,
T_2 V_40 )
{
struct V_4 * V_5 = F_20 ( V_25 -> V_30 . V_31 ) ;
F_25 ( V_5 , V_40 ) ;
}
static int F_29 ( enum V_42 V_43 ,
unsigned long V_44 , unsigned long V_45 )
{
unsigned long * V_46 ;
if ( ( V_43 >= V_47 ) || ( V_43 < V_48 ) )
V_43 = V_49 ;
F_30 ( L_1 ,
V_50 [ V_43 ] , V_45 , V_44 ) ;
V_46 = F_1 ( F_4 ( V_44 ) , V_45 ) ;
F_30 ( L_2 , * V_46 ) ;
if ( F_31 ( V_46 ) ) {
V_46 = F_3 ( V_46 , V_45 ) ;
F_30 ( L_3 , * V_46 ) ;
}
F_30 ( L_4 ) ;
F_32 () ;
return 0 ;
}
static T_3 F_33 ( int V_51 , void * V_52 )
{
struct V_4 * V_5 = V_52 ;
struct V_53 * V_54 ;
struct V_55 * V_56 ;
enum V_42 V_43 ;
unsigned long V_57 = - 1 ;
int V_10 , V_58 = - V_59 ;
F_34 ( & V_5 -> V_33 ) ;
F_35 ( ! F_10 ( V_5 ) ) ;
V_56 = F_36 ( V_5 -> V_60 ) ;
for ( V_10 = 0 ; V_10 < ( V_56 -> V_61 / 2 ) ; V_10 ++ ) {
V_54 = F_37 ( V_56 , V_62 , V_10 ) ;
if ( V_54 && ( ( int ) V_54 -> V_63 == V_51 ) )
break;
}
if ( V_10 == V_56 -> V_61 ) {
V_43 = V_49 ;
} else {
V_43 = (enum V_42 )
F_38 ( F_14 ( V_5 -> V_36 [ V_10 ] + V_64 ) ) ;
if ( F_35 ( ! ( ( V_43 >= 0 ) && ( V_43 < V_49 ) ) ) )
V_43 = V_49 ;
else
V_57 = F_14 (
V_5 -> V_36 [ V_10 ] + V_65 [ V_43 ] ) ;
}
if ( V_5 -> V_66 )
V_58 = F_39 ( V_5 -> V_66 , V_5 -> V_25 ,
V_57 , V_43 ) ;
if ( ( V_58 == - V_59 ) && V_5 -> V_41 ) {
unsigned long V_19 = V_5 -> V_1 ;
if ( V_43 != V_49 )
V_19 = F_14 (
V_5 -> V_36 [ V_10 ] + V_18 ) ;
V_58 = V_5 -> V_41 ( V_43 , V_19 , V_57 ) ;
}
if ( ! V_58 && ( V_43 != V_49 ) )
F_12 ( 1 << V_43 , V_5 -> V_36 [ V_10 ] + V_67 ) ;
else
F_40 ( V_5 -> V_60 , L_5 ,
V_5 -> V_68 , V_50 [ V_43 ] ) ;
if ( V_43 != V_49 )
F_11 ( V_5 -> V_36 [ V_10 ] ) ;
F_41 ( & V_5 -> V_33 ) ;
return V_69 ;
}
static bool F_42 ( struct V_4 * V_5 )
{
unsigned long V_32 ;
bool V_70 = false ;
int V_10 ;
F_26 ( & V_5 -> V_33 , V_32 ) ;
if ( ! F_8 ( V_5 ) )
goto V_34;
for ( V_10 = 0 ; V_10 < V_5 -> V_35 ; V_10 ++ )
F_12 ( V_71 , V_5 -> V_36 [ V_10 ] + V_9 ) ;
if ( V_5 -> V_72 [ 1 ] )
F_43 ( V_5 -> V_72 [ 1 ] ) ;
if ( V_5 -> V_72 [ 0 ] )
F_43 ( V_5 -> V_72 [ 0 ] ) ;
V_70 = true ;
V_5 -> V_1 = 0 ;
V_5 -> V_66 = NULL ;
V_34:
F_27 ( & V_5 -> V_33 , V_32 ) ;
if ( V_70 )
F_40 ( V_5 -> V_60 , L_6 , V_5 -> V_68 ) ;
else
F_40 ( V_5 -> V_60 , L_7 ,
V_5 -> V_68 , V_5 -> V_6 ) ;
return V_70 ;
}
static int F_44 ( struct V_4 * V_5 ,
unsigned long V_1 , struct V_73 * V_66 )
{
int V_10 , V_58 = 0 ;
unsigned long V_32 ;
F_26 ( & V_5 -> V_33 , V_32 ) ;
if ( ! F_7 ( V_5 ) ) {
if ( F_35 ( V_1 != V_5 -> V_1 ) ) {
V_58 = - V_74 ;
F_8 ( V_5 ) ;
} else {
V_58 = 1 ;
}
F_40 ( V_5 -> V_60 , L_8 , V_5 -> V_68 ) ;
goto V_34;
}
if ( V_5 -> V_72 [ 0 ] )
F_45 ( V_5 -> V_72 [ 0 ] ) ;
if ( V_5 -> V_72 [ 1 ] )
F_45 ( V_5 -> V_72 [ 1 ] ) ;
V_5 -> V_1 = V_1 ;
for ( V_10 = 0 ; V_10 < V_5 -> V_35 ; V_10 ++ ) {
F_17 ( V_5 -> V_36 [ V_10 ] , V_1 ) ;
if ( ( F_22 ( V_5 -> V_36 [ V_10 ] + V_37 ) >> 28 ) == 3 ) {
F_12 ( ( 1 << 12 ) | ( 2 << 28 ) ,
V_5 -> V_36 [ V_10 ] + V_17 ) ;
F_18 ( V_5 -> V_36 [ V_10 ] , 0 , - 1 , 0 ) ;
F_18 ( V_5 -> V_36 [ V_10 ] , 0 , - 1 , 1 ) ;
}
F_12 ( V_8 , V_5 -> V_36 [ V_10 ] + V_9 ) ;
}
V_5 -> V_66 = V_66 ;
F_40 ( V_5 -> V_60 , L_9 , V_5 -> V_68 ) ;
V_34:
F_27 ( & V_5 -> V_33 , V_32 ) ;
return V_58 ;
}
int F_46 ( struct V_24 * V_25 , unsigned long V_1 )
{
struct V_4 * V_5 = F_20 ( V_25 -> V_30 . V_31 ) ;
int V_58 ;
F_9 ( ! F_47 ( V_1 ) ) ;
V_58 = F_48 ( V_5 -> V_60 ) ;
if ( V_58 < 0 ) {
F_40 ( V_5 -> V_60 , L_10 , V_5 -> V_68 ) ;
return V_58 ;
}
V_58 = F_44 ( V_5 , V_1 , NULL ) ;
if ( F_35 ( V_58 < 0 ) ) {
F_49 ( V_5 -> V_60 ) ;
F_50 ( V_5 -> V_60 ,
L_11 ,
V_5 -> V_68 , V_5 -> V_1 ) ;
} else {
V_5 -> V_25 = V_25 ;
}
return V_58 ;
}
static bool F_51 ( struct V_24 * V_25 )
{
struct V_4 * V_5 = F_20 ( V_25 -> V_30 . V_31 ) ;
bool V_70 ;
V_70 = F_42 ( V_5 ) ;
F_49 ( V_5 -> V_60 ) ;
return V_70 ;
}
static void F_52 ( struct V_24 * V_25 , unsigned long V_2 )
{
unsigned long V_32 ;
struct V_4 * V_5 = F_20 ( V_25 -> V_30 . V_31 ) ;
F_21 ( & V_5 -> V_33 , V_32 ) ;
if ( F_10 ( V_5 ) ) {
int V_10 ;
for ( V_10 = 0 ; V_10 < V_5 -> V_35 ; V_10 ++ ) {
if ( F_13 ( V_5 -> V_36 [ V_10 ] ) ) {
F_16 (
V_5 -> V_36 [ V_10 ] , V_2 ) ;
F_11 ( V_5 -> V_36 [ V_10 ] ) ;
}
}
} else {
F_40 ( V_5 -> V_60 ,
L_12 ,
V_5 -> V_68 ) ;
}
F_24 ( & V_5 -> V_33 , V_32 ) ;
}
void F_53 ( struct V_24 * V_25 )
{
unsigned long V_32 ;
struct V_4 * V_5 = F_20 ( V_25 -> V_30 . V_31 ) ;
F_21 ( & V_5 -> V_33 , V_32 ) ;
if ( F_10 ( V_5 ) ) {
int V_10 ;
for ( V_10 = 0 ; V_10 < V_5 -> V_35 ; V_10 ++ ) {
if ( F_13 ( V_5 -> V_36 [ V_10 ] ) ) {
F_15 ( V_5 -> V_36 [ V_10 ] ) ;
F_11 ( V_5 -> V_36 [ V_10 ] ) ;
}
}
} else {
F_40 ( V_5 -> V_60 ,
L_12 ,
V_5 -> V_68 ) ;
}
F_24 ( & V_5 -> V_33 , V_32 ) ;
}
static int F_54 ( struct V_55 * V_56 )
{
int V_10 , V_58 ;
struct V_24 * V_25 ;
struct V_4 * V_5 ;
V_25 = & V_56 -> V_25 ;
V_5 = F_55 ( sizeof( * V_5 ) , V_75 ) ;
if ( ! V_5 ) {
F_40 ( V_25 , L_13 ) ;
V_58 = - V_76 ;
goto V_77;
}
V_58 = F_56 ( V_25 , V_5 ) ;
if ( V_58 ) {
F_40 ( V_25 , L_14 ) ;
goto V_78;
}
V_5 -> V_35 = V_56 -> V_61 / 2 ;
V_5 -> V_36 = F_57 ( sizeof( * V_5 -> V_36 ) * V_5 -> V_35 ,
V_75 ) ;
if ( V_5 -> V_36 == NULL ) {
F_40 ( V_25 , L_13 ) ;
V_58 = - V_76 ;
goto V_78;
}
for ( V_10 = 0 ; V_10 < V_5 -> V_35 ; V_10 ++ ) {
struct V_53 * V_79 ;
V_79 = F_37 ( V_56 , V_80 , V_10 ) ;
if ( ! V_79 ) {
F_40 ( V_25 , L_15 ) ;
V_58 = - V_81 ;
goto V_82;
}
V_5 -> V_36 [ V_10 ] = F_58 ( V_79 -> V_63 , F_59 ( V_79 ) ) ;
if ( ! V_5 -> V_36 [ V_10 ] ) {
F_40 ( V_25 , L_16 ,
V_79 -> V_63 ) ;
V_58 = - V_81 ;
goto V_82;
}
}
for ( V_10 = 0 ; V_10 < V_5 -> V_35 ; V_10 ++ ) {
V_58 = F_60 ( V_56 , V_10 ) ;
if ( V_58 <= 0 ) {
F_40 ( V_25 , L_17 ) ;
goto V_83;
}
V_58 = F_61 ( V_58 , F_33 , 0 ,
F_62 ( V_25 ) , V_5 ) ;
if ( V_58 ) {
F_40 ( V_25 , L_18 ) ;
goto V_83;
}
}
if ( F_63 ( V_25 ) ) {
char * V_84 , * V_85 ;
struct V_86 * V_87 = F_63 ( V_25 ) ;
V_85 = V_87 -> V_88 ;
for ( V_84 = V_85 ; ( * V_84 != '\0' ) && ( * V_84 != ',' ) ; V_84 ++ )
;
if ( * V_84 == '\0' )
V_84 = NULL ;
else
* V_84 = '\0' ;
V_5 -> V_72 [ 0 ] = F_64 ( V_25 , V_85 ) ;
if ( F_65 ( V_5 -> V_72 [ 0 ] ) ) {
V_5 -> V_72 [ 0 ] = NULL ;
F_40 ( V_25 , L_19 ) ;
}
if ( V_5 -> V_72 [ 0 ] && V_84 ) {
* V_84 = ',' ;
V_5 -> V_72 [ 1 ] = F_64 ( V_25 , V_84 + 1 ) ;
if ( F_65 ( V_5 -> V_72 [ 1 ] ) )
V_5 -> V_72 [ 1 ] = NULL ;
}
V_5 -> V_68 = V_87 -> V_68 ;
}
V_5 -> V_60 = V_25 ;
F_66 ( & V_5 -> V_33 ) ;
F_67 ( & V_5 -> V_89 ) ;
F_25 ( V_5 , & F_29 ) ;
if ( V_25 -> V_90 )
F_68 ( V_25 ) ;
F_40 ( V_25 , L_20 , V_5 -> V_68 ) ;
return 0 ;
V_83:
while ( V_10 -- > 0 ) {
int V_51 ;
V_51 = F_60 ( V_56 , V_10 ) ;
F_69 ( V_51 , V_5 ) ;
}
V_82:
while ( V_5 -> V_35 -- > 0 )
F_70 ( V_5 -> V_36 [ V_5 -> V_35 ] ) ;
F_71 ( V_5 -> V_36 ) ;
V_78:
F_71 ( V_5 ) ;
V_77:
F_50 ( V_25 , L_21 ) ;
return V_58 ;
}
static inline void F_72 ( void * V_91 , void * V_92 )
{
F_73 ( V_91 , V_92 ) ;
F_74 ( F_75 ( V_91 ) ,
F_75 ( V_92 ) ) ;
}
static int F_76 ( struct V_73 * V_66 )
{
struct V_93 * V_94 ;
V_94 = F_55 ( sizeof( * V_94 ) , V_75 ) ;
if ( ! V_94 )
return - V_76 ;
V_94 -> V_1 = ( unsigned long * ) F_77 (
V_75 | V_95 , 2 ) ;
if ( ! V_94 -> V_1 )
goto V_96;
V_94 -> V_97 = ( short * ) F_77 (
V_75 | V_95 , 1 ) ;
if ( ! V_94 -> V_97 )
goto V_98;
F_72 ( V_94 -> V_1 , V_94 -> V_1 + V_99 ) ;
F_78 ( & V_94 -> V_33 ) ;
F_78 ( & V_94 -> V_100 ) ;
F_67 ( & V_94 -> V_101 ) ;
V_66 -> V_102 . V_103 = 0 ;
V_66 -> V_102 . V_104 = ~ 0UL ;
V_66 -> V_102 . V_105 = true ;
V_66 -> V_94 = V_94 ;
return 0 ;
V_98:
F_79 ( ( unsigned long ) V_94 -> V_1 , 2 ) ;
V_96:
F_71 ( V_94 ) ;
return - V_76 ;
}
static void F_80 ( struct V_73 * V_66 )
{
struct V_93 * V_94 = V_66 -> V_94 ;
struct V_4 * V_5 ;
unsigned long V_32 ;
int V_10 ;
F_35 ( ! F_81 ( & V_94 -> V_101 ) ) ;
F_82 ( & V_94 -> V_33 , V_32 ) ;
F_83 (data, &priv->clients, node) {
while ( ! F_51 ( V_5 -> V_25 ) )
;
}
F_84 ( & V_94 -> V_33 , V_32 ) ;
for ( V_10 = 0 ; V_10 < V_99 ; V_10 ++ )
if ( F_31 ( V_94 -> V_1 + V_10 ) )
F_71 ( F_4 ( F_5 ( V_94 -> V_1 + V_10 ) ) ) ;
F_79 ( ( unsigned long ) V_94 -> V_1 , 2 ) ;
F_79 ( ( unsigned long ) V_94 -> V_97 , 1 ) ;
F_71 ( V_66 -> V_94 ) ;
V_66 -> V_94 = NULL ;
}
static int F_85 ( struct V_73 * V_66 ,
struct V_24 * V_25 )
{
struct V_4 * V_5 = F_20 ( V_25 -> V_30 . V_31 ) ;
struct V_93 * V_94 = V_66 -> V_94 ;
unsigned long V_32 ;
int V_58 ;
V_58 = F_48 ( V_5 -> V_60 ) ;
if ( V_58 < 0 )
return V_58 ;
V_58 = 0 ;
F_82 ( & V_94 -> V_33 , V_32 ) ;
V_58 = F_44 ( V_5 , F_86 ( V_94 -> V_1 ) , V_66 ) ;
if ( V_58 == 0 ) {
F_9 ( ! F_81 ( & V_5 -> V_89 ) ) ;
V_5 -> V_25 = V_25 ;
F_87 ( & V_5 -> V_89 , & V_94 -> V_101 ) ;
}
F_84 ( & V_94 -> V_33 , V_32 ) ;
if ( V_58 < 0 ) {
F_50 ( V_25 , L_22 ,
V_106 , F_86 ( V_94 -> V_1 ) ) ;
F_49 ( V_5 -> V_60 ) ;
} else if ( V_58 > 0 ) {
F_40 ( V_25 , L_23 ,
V_106 , F_86 ( V_94 -> V_1 ) ) ;
} else {
F_40 ( V_25 , L_24 ,
V_106 , F_86 ( V_94 -> V_1 ) ) ;
}
return V_58 ;
}
static void F_88 ( struct V_73 * V_66 ,
struct V_24 * V_25 )
{
struct V_4 * V_5 = F_20 ( V_25 -> V_30 . V_31 ) ;
struct V_93 * V_94 = V_66 -> V_94 ;
struct V_107 * V_108 ;
unsigned long V_32 ;
bool V_109 = false ;
F_82 ( & V_94 -> V_33 , V_32 ) ;
F_89 (pos, &priv->clients) {
if ( F_90 ( V_108 , struct V_4 , V_89 ) == V_5 ) {
V_109 = true ;
break;
}
}
if ( ! V_109 )
goto V_34;
if ( F_42 ( V_5 ) ) {
F_40 ( V_25 , L_25 ,
V_106 , F_86 ( V_94 -> V_1 ) ) ;
F_91 ( & V_5 -> V_89 ) ;
} else {
F_40 ( V_25 , L_26 ,
V_106 , F_86 ( V_94 -> V_1 ) ) ;
}
V_34:
F_84 ( & V_94 -> V_33 , V_32 ) ;
if ( V_109 )
F_49 ( V_5 -> V_60 ) ;
}
static unsigned long * F_92 ( unsigned long * V_3 , unsigned long V_2 ,
short * V_110 )
{
if ( F_93 ( V_3 ) ) {
unsigned long * V_111 ;
V_111 = F_55 ( V_112 , V_113 ) ;
F_9 ( ( unsigned long ) V_111 & ( V_112 - 1 ) ) ;
if ( ! V_111 )
return NULL ;
* V_3 = F_94 ( F_86 ( V_111 ) ) ;
* V_110 = V_114 ;
F_72 ( V_111 , V_111 + V_114 ) ;
F_72 ( V_3 , V_3 + 1 ) ;
}
return F_3 ( V_3 , V_2 ) ;
}
static int F_95 ( unsigned long * V_3 , T_4 V_115 , short * V_116 )
{
if ( F_96 ( V_3 ) )
return - V_117 ;
if ( F_31 ( V_3 ) ) {
if ( * V_116 != V_114 )
return - V_117 ;
F_71 ( F_3 ( V_3 , 0 ) ) ;
* V_116 = 0 ;
}
* V_3 = F_97 ( V_115 ) ;
F_72 ( V_3 , V_3 + 1 ) ;
return 0 ;
}
static int F_98 ( unsigned long * V_111 , T_4 V_115 , T_5 V_20 ,
short * V_116 )
{
if ( V_20 == V_118 ) {
if ( ! F_99 ( V_111 ) )
return - V_117 ;
* V_111 = F_100 ( V_115 ) ;
F_72 ( V_111 , V_111 + 1 ) ;
* V_116 -= 1 ;
} else {
int V_10 ;
for ( V_10 = 0 ; V_10 < V_119 ; V_10 ++ , V_111 ++ ) {
if ( ! F_99 ( V_111 ) ) {
memset ( V_111 , 0 , sizeof( * V_111 ) * V_10 ) ;
return - V_117 ;
}
* V_111 = F_101 ( V_115 ) ;
}
F_72 ( V_111 - V_119 , V_111 ) ;
* V_116 -= V_119 ;
}
return 0 ;
}
static int F_102 ( struct V_73 * V_66 , unsigned long V_2 ,
T_4 V_115 , T_5 V_20 , int V_120 )
{
struct V_93 * V_94 = V_66 -> V_94 ;
unsigned long * V_121 ;
unsigned long V_32 ;
int V_58 = - V_76 ;
F_9 ( V_94 -> V_1 == NULL ) ;
F_82 ( & V_94 -> V_100 , V_32 ) ;
V_121 = F_1 ( V_94 -> V_1 , V_2 ) ;
if ( V_20 == V_122 ) {
V_58 = F_95 ( V_121 , V_115 ,
& V_94 -> V_97 [ F_2 ( V_2 ) ] ) ;
} else {
unsigned long * V_111 ;
V_111 = F_92 ( V_121 , V_2 ,
& V_94 -> V_97 [ F_2 ( V_2 ) ] ) ;
if ( ! V_111 )
V_58 = - V_76 ;
else
V_58 = F_98 ( V_111 , V_115 , V_20 ,
& V_94 -> V_97 [ F_2 ( V_2 ) ] ) ;
}
if ( V_58 ) {
F_103 ( L_27 ,
V_106 , V_2 , V_20 ) ;
}
F_84 ( & V_94 -> V_100 , V_32 ) ;
return V_58 ;
}
static T_5 F_104 ( struct V_73 * V_66 ,
unsigned long V_2 , T_5 V_20 )
{
struct V_93 * V_94 = V_66 -> V_94 ;
struct V_4 * V_5 ;
unsigned long V_32 ;
unsigned long * V_46 ;
F_9 ( V_94 -> V_1 == NULL ) ;
F_82 ( & V_94 -> V_100 , V_32 ) ;
V_46 = F_1 ( V_94 -> V_1 , V_2 ) ;
if ( F_96 ( V_46 ) ) {
F_9 ( V_20 < V_122 ) ;
* V_46 = 0 ;
F_72 ( V_46 , V_46 + 1 ) ;
V_20 = V_122 ;
goto V_123;
}
if ( F_105 ( F_93 ( V_46 ) ) ) {
if ( V_20 > V_122 )
V_20 = V_122 ;
goto V_123;
}
V_46 = F_3 ( V_46 , V_2 ) ;
if ( F_105 ( F_99 ( V_46 ) ) ) {
V_20 = V_118 ;
goto V_123;
}
if ( F_106 ( V_46 ) ) {
* V_46 = 0 ;
V_20 = V_118 ;
V_94 -> V_97 [ F_2 ( V_2 ) ] += 1 ;
goto V_123;
}
F_9 ( V_20 < V_124 ) ;
memset ( V_46 , 0 , sizeof( * V_46 ) * V_119 ) ;
V_20 = V_124 ;
V_94 -> V_97 [ F_2 ( V_2 ) ] += V_119 ;
V_123:
F_84 ( & V_94 -> V_100 , V_32 ) ;
F_82 ( & V_94 -> V_33 , V_32 ) ;
F_83 (data, &priv->clients, node)
F_52 ( V_5 -> V_25 , V_2 ) ;
F_84 ( & V_94 -> V_33 , V_32 ) ;
return V_20 ;
}
static T_4 F_107 ( struct V_73 * V_66 ,
T_6 V_2 )
{
struct V_93 * V_94 = V_66 -> V_94 ;
unsigned long * V_121 ;
unsigned long V_32 ;
T_4 V_125 = 0 ;
F_82 ( & V_94 -> V_100 , V_32 ) ;
V_121 = F_1 ( V_94 -> V_1 , V_2 ) ;
if ( F_96 ( V_121 ) ) {
V_125 = F_108 ( V_121 ) + F_109 ( V_2 ) ;
} else if ( F_31 ( V_121 ) ) {
V_121 = F_3 ( V_121 , V_2 ) ;
if ( F_110 ( V_121 ) )
V_125 = F_111 ( V_121 ) + F_112 ( V_2 ) ;
else if ( F_106 ( V_121 ) )
V_125 = F_113 ( V_121 ) + F_114 ( V_2 ) ;
}
F_84 ( & V_94 -> V_100 , V_32 ) ;
return V_125 ;
}
static int T_7 F_115 ( void )
{
int V_58 ;
V_58 = F_116 ( & V_126 ) ;
if ( V_58 == 0 )
F_117 ( & V_127 , & V_128 ) ;
return V_58 ;
}
