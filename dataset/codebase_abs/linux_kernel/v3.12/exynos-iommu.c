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
static void F_19 ( struct V_4 * V_5 ,
T_2 V_24 )
{
unsigned long V_25 ;
F_20 ( & V_5 -> V_26 , V_25 ) ;
V_5 -> V_27 = V_24 ;
F_21 ( & V_5 -> V_26 , V_25 ) ;
}
void F_22 ( struct V_28 * V_29 ,
T_2 V_24 )
{
struct V_4 * V_5 = F_23 ( V_29 -> V_30 . V_31 ) ;
F_19 ( V_5 , V_24 ) ;
}
static int F_24 ( enum V_32 V_33 ,
unsigned long V_34 , unsigned long V_35 )
{
unsigned long * V_36 ;
if ( ( V_33 >= V_37 ) || ( V_33 < V_38 ) )
V_33 = V_39 ;
F_25 ( L_1 ,
V_40 [ V_33 ] , V_35 , V_34 ) ;
V_36 = F_1 ( F_4 ( V_34 ) , V_35 ) ;
F_25 ( L_2 , * V_36 ) ;
if ( F_26 ( V_36 ) ) {
V_36 = F_3 ( V_36 , V_35 ) ;
F_25 ( L_3 , * V_36 ) ;
}
F_25 ( L_4 ) ;
F_27 () ;
return 0 ;
}
static T_3 F_28 ( int V_41 , void * V_42 )
{
struct V_4 * V_5 = V_42 ;
struct V_43 * V_44 ;
struct V_45 * V_46 ;
enum V_32 V_33 ;
unsigned long V_47 = - 1 ;
int V_10 , V_48 = - V_49 ;
F_29 ( & V_5 -> V_26 ) ;
F_30 ( ! F_10 ( V_5 ) ) ;
V_46 = F_31 ( V_5 -> V_50 ) ;
for ( V_10 = 0 ; V_10 < ( V_46 -> V_51 / 2 ) ; V_10 ++ ) {
V_44 = F_32 ( V_46 , V_52 , V_10 ) ;
if ( V_44 && ( ( int ) V_44 -> V_53 == V_41 ) )
break;
}
if ( V_10 == V_46 -> V_51 ) {
V_33 = V_39 ;
} else {
V_33 = (enum V_32 )
F_33 ( F_14 ( V_5 -> V_54 [ V_10 ] + V_55 ) ) ;
if ( F_30 ( ! ( ( V_33 >= 0 ) && ( V_33 < V_39 ) ) ) )
V_33 = V_39 ;
else
V_47 = F_14 (
V_5 -> V_54 [ V_10 ] + V_56 [ V_33 ] ) ;
}
if ( V_5 -> V_57 )
V_48 = F_34 ( V_5 -> V_57 , V_5 -> V_29 ,
V_47 , V_33 ) ;
if ( ( V_48 == - V_49 ) && V_5 -> V_27 ) {
unsigned long V_19 = V_5 -> V_1 ;
if ( V_33 != V_39 )
V_19 = F_14 (
V_5 -> V_54 [ V_10 ] + V_18 ) ;
V_48 = V_5 -> V_27 ( V_33 , V_19 , V_47 ) ;
}
if ( ! V_48 && ( V_33 != V_39 ) )
F_12 ( 1 << V_33 , V_5 -> V_54 [ V_10 ] + V_58 ) ;
else
F_35 ( V_5 -> V_50 , L_5 ,
V_5 -> V_59 , V_40 [ V_33 ] ) ;
if ( V_33 != V_39 )
F_11 ( V_5 -> V_54 [ V_10 ] ) ;
F_36 ( & V_5 -> V_26 ) ;
return V_60 ;
}
static bool F_37 ( struct V_4 * V_5 )
{
unsigned long V_25 ;
bool V_61 = false ;
int V_10 ;
F_20 ( & V_5 -> V_26 , V_25 ) ;
if ( ! F_8 ( V_5 ) )
goto V_62;
for ( V_10 = 0 ; V_10 < V_5 -> V_63 ; V_10 ++ )
F_12 ( V_64 , V_5 -> V_54 [ V_10 ] + V_9 ) ;
if ( V_5 -> V_65 [ 1 ] )
F_38 ( V_5 -> V_65 [ 1 ] ) ;
if ( V_5 -> V_65 [ 0 ] )
F_38 ( V_5 -> V_65 [ 0 ] ) ;
V_61 = true ;
V_5 -> V_1 = 0 ;
V_5 -> V_57 = NULL ;
V_62:
F_21 ( & V_5 -> V_26 , V_25 ) ;
if ( V_61 )
F_35 ( V_5 -> V_50 , L_6 , V_5 -> V_59 ) ;
else
F_35 ( V_5 -> V_50 , L_7 ,
V_5 -> V_59 , V_5 -> V_6 ) ;
return V_61 ;
}
static int F_39 ( struct V_4 * V_5 ,
unsigned long V_1 , struct V_66 * V_57 )
{
int V_10 , V_48 = 0 ;
unsigned long V_25 ;
F_20 ( & V_5 -> V_26 , V_25 ) ;
if ( ! F_7 ( V_5 ) ) {
if ( F_30 ( V_1 != V_5 -> V_1 ) ) {
V_48 = - V_67 ;
F_8 ( V_5 ) ;
} else {
V_48 = 1 ;
}
F_35 ( V_5 -> V_50 , L_8 , V_5 -> V_59 ) ;
goto V_62;
}
if ( V_5 -> V_65 [ 0 ] )
F_40 ( V_5 -> V_65 [ 0 ] ) ;
if ( V_5 -> V_65 [ 1 ] )
F_40 ( V_5 -> V_65 [ 1 ] ) ;
V_5 -> V_1 = V_1 ;
for ( V_10 = 0 ; V_10 < V_5 -> V_63 ; V_10 ++ ) {
F_17 ( V_5 -> V_54 [ V_10 ] , V_1 ) ;
if ( ( F_41 ( V_5 -> V_54 [ V_10 ] + V_68 ) >> 28 ) == 3 ) {
F_12 ( ( 1 << 12 ) | ( 2 << 28 ) ,
V_5 -> V_54 [ V_10 ] + V_17 ) ;
F_18 ( V_5 -> V_54 [ V_10 ] , 0 , - 1 , 0 ) ;
F_18 ( V_5 -> V_54 [ V_10 ] , 0 , - 1 , 1 ) ;
}
F_12 ( V_8 , V_5 -> V_54 [ V_10 ] + V_9 ) ;
}
V_5 -> V_57 = V_57 ;
F_35 ( V_5 -> V_50 , L_9 , V_5 -> V_59 ) ;
V_62:
F_21 ( & V_5 -> V_26 , V_25 ) ;
return V_48 ;
}
int F_42 ( struct V_28 * V_29 , unsigned long V_1 )
{
struct V_4 * V_5 = F_23 ( V_29 -> V_30 . V_31 ) ;
int V_48 ;
F_9 ( ! F_43 ( V_1 ) ) ;
V_48 = F_44 ( V_5 -> V_50 ) ;
if ( V_48 < 0 ) {
F_35 ( V_5 -> V_50 , L_10 , V_5 -> V_59 ) ;
return V_48 ;
}
V_48 = F_39 ( V_5 , V_1 , NULL ) ;
if ( F_30 ( V_48 < 0 ) ) {
F_45 ( V_5 -> V_50 ) ;
F_46 ( V_5 -> V_50 ,
L_11 ,
V_5 -> V_59 , V_5 -> V_1 ) ;
} else {
V_5 -> V_29 = V_29 ;
}
return V_48 ;
}
static bool F_47 ( struct V_28 * V_29 )
{
struct V_4 * V_5 = F_23 ( V_29 -> V_30 . V_31 ) ;
bool V_61 ;
V_61 = F_37 ( V_5 ) ;
F_45 ( V_5 -> V_50 ) ;
return V_61 ;
}
static void F_48 ( struct V_28 * V_29 , unsigned long V_2 )
{
unsigned long V_25 ;
struct V_4 * V_5 = F_23 ( V_29 -> V_30 . V_31 ) ;
F_49 ( & V_5 -> V_26 , V_25 ) ;
if ( F_10 ( V_5 ) ) {
int V_10 ;
for ( V_10 = 0 ; V_10 < V_5 -> V_63 ; V_10 ++ ) {
if ( F_13 ( V_5 -> V_54 [ V_10 ] ) ) {
F_16 (
V_5 -> V_54 [ V_10 ] , V_2 ) ;
F_11 ( V_5 -> V_54 [ V_10 ] ) ;
}
}
} else {
F_35 ( V_5 -> V_50 ,
L_12 ,
V_5 -> V_59 ) ;
}
F_50 ( & V_5 -> V_26 , V_25 ) ;
}
void F_51 ( struct V_28 * V_29 )
{
unsigned long V_25 ;
struct V_4 * V_5 = F_23 ( V_29 -> V_30 . V_31 ) ;
F_49 ( & V_5 -> V_26 , V_25 ) ;
if ( F_10 ( V_5 ) ) {
int V_10 ;
for ( V_10 = 0 ; V_10 < V_5 -> V_63 ; V_10 ++ ) {
if ( F_13 ( V_5 -> V_54 [ V_10 ] ) ) {
F_15 ( V_5 -> V_54 [ V_10 ] ) ;
F_11 ( V_5 -> V_54 [ V_10 ] ) ;
}
}
} else {
F_35 ( V_5 -> V_50 ,
L_12 ,
V_5 -> V_59 ) ;
}
F_50 ( & V_5 -> V_26 , V_25 ) ;
}
static int F_52 ( struct V_45 * V_46 )
{
int V_10 , V_48 ;
struct V_28 * V_29 ;
struct V_4 * V_5 ;
V_29 = & V_46 -> V_29 ;
V_5 = F_53 ( sizeof( * V_5 ) , V_69 ) ;
if ( ! V_5 ) {
F_35 ( V_29 , L_13 ) ;
V_48 = - V_70 ;
goto V_71;
}
V_48 = F_54 ( V_29 , V_5 ) ;
if ( V_48 ) {
F_35 ( V_29 , L_14 ) ;
goto V_72;
}
V_5 -> V_63 = V_46 -> V_51 / 2 ;
V_5 -> V_54 = F_55 ( sizeof( * V_5 -> V_54 ) * V_5 -> V_63 ,
V_69 ) ;
if ( V_5 -> V_54 == NULL ) {
F_35 ( V_29 , L_13 ) ;
V_48 = - V_70 ;
goto V_72;
}
for ( V_10 = 0 ; V_10 < V_5 -> V_63 ; V_10 ++ ) {
struct V_43 * V_73 ;
V_73 = F_32 ( V_46 , V_74 , V_10 ) ;
if ( ! V_73 ) {
F_35 ( V_29 , L_15 ) ;
V_48 = - V_75 ;
goto V_76;
}
V_5 -> V_54 [ V_10 ] = F_56 ( V_73 -> V_53 , F_57 ( V_73 ) ) ;
if ( ! V_5 -> V_54 [ V_10 ] ) {
F_35 ( V_29 , L_16 ,
V_73 -> V_53 ) ;
V_48 = - V_75 ;
goto V_76;
}
}
for ( V_10 = 0 ; V_10 < V_5 -> V_63 ; V_10 ++ ) {
V_48 = F_58 ( V_46 , V_10 ) ;
if ( V_48 <= 0 ) {
F_35 ( V_29 , L_17 ) ;
goto V_77;
}
V_48 = F_59 ( V_48 , F_28 , 0 ,
F_60 ( V_29 ) , V_5 ) ;
if ( V_48 ) {
F_35 ( V_29 , L_18 ) ;
goto V_77;
}
}
if ( F_61 ( V_29 ) ) {
char * V_78 , * V_79 ;
struct V_80 * V_81 = F_61 ( V_29 ) ;
V_79 = V_81 -> V_82 ;
for ( V_78 = V_79 ; ( * V_78 != '\0' ) && ( * V_78 != ',' ) ; V_78 ++ )
;
if ( * V_78 == '\0' )
V_78 = NULL ;
else
* V_78 = '\0' ;
V_5 -> V_65 [ 0 ] = F_62 ( V_29 , V_79 ) ;
if ( F_63 ( V_5 -> V_65 [ 0 ] ) ) {
V_5 -> V_65 [ 0 ] = NULL ;
F_35 ( V_29 , L_19 ) ;
}
if ( V_5 -> V_65 [ 0 ] && V_78 ) {
* V_78 = ',' ;
V_5 -> V_65 [ 1 ] = F_62 ( V_29 , V_78 + 1 ) ;
if ( F_63 ( V_5 -> V_65 [ 1 ] ) )
V_5 -> V_65 [ 1 ] = NULL ;
}
V_5 -> V_59 = V_81 -> V_59 ;
}
V_5 -> V_50 = V_29 ;
F_64 ( & V_5 -> V_26 ) ;
F_65 ( & V_5 -> V_83 ) ;
F_19 ( V_5 , & F_24 ) ;
if ( V_29 -> V_84 )
F_66 ( V_29 ) ;
F_35 ( V_29 , L_20 , V_5 -> V_59 ) ;
return 0 ;
V_77:
while ( V_10 -- > 0 ) {
int V_41 ;
V_41 = F_58 ( V_46 , V_10 ) ;
F_67 ( V_41 , V_5 ) ;
}
V_76:
while ( V_5 -> V_63 -- > 0 )
F_68 ( V_5 -> V_54 [ V_5 -> V_63 ] ) ;
F_69 ( V_5 -> V_54 ) ;
V_72:
F_69 ( V_5 ) ;
V_71:
F_46 ( V_29 , L_21 ) ;
return V_48 ;
}
static inline void F_70 ( void * V_85 , void * V_86 )
{
F_71 ( V_85 , V_86 ) ;
F_72 ( F_73 ( V_85 ) ,
F_73 ( V_86 ) ) ;
}
static int F_74 ( struct V_66 * V_57 )
{
struct V_87 * V_88 ;
V_88 = F_53 ( sizeof( * V_88 ) , V_69 ) ;
if ( ! V_88 )
return - V_70 ;
V_88 -> V_1 = ( unsigned long * ) F_75 (
V_69 | V_89 , 2 ) ;
if ( ! V_88 -> V_1 )
goto V_90;
V_88 -> V_91 = ( short * ) F_75 (
V_69 | V_89 , 1 ) ;
if ( ! V_88 -> V_91 )
goto V_92;
F_70 ( V_88 -> V_1 , V_88 -> V_1 + V_93 ) ;
F_76 ( & V_88 -> V_26 ) ;
F_76 ( & V_88 -> V_94 ) ;
F_65 ( & V_88 -> V_95 ) ;
V_57 -> V_96 . V_97 = 0 ;
V_57 -> V_96 . V_98 = ~ 0UL ;
V_57 -> V_96 . V_99 = true ;
V_57 -> V_88 = V_88 ;
return 0 ;
V_92:
F_77 ( ( unsigned long ) V_88 -> V_1 , 2 ) ;
V_90:
F_69 ( V_88 ) ;
return - V_70 ;
}
static void F_78 ( struct V_66 * V_57 )
{
struct V_87 * V_88 = V_57 -> V_88 ;
struct V_4 * V_5 ;
unsigned long V_25 ;
int V_10 ;
F_30 ( ! F_79 ( & V_88 -> V_95 ) ) ;
F_80 ( & V_88 -> V_26 , V_25 ) ;
F_81 (data, &priv->clients, node) {
while ( ! F_47 ( V_5 -> V_29 ) )
;
}
F_82 ( & V_88 -> V_26 , V_25 ) ;
for ( V_10 = 0 ; V_10 < V_93 ; V_10 ++ )
if ( F_26 ( V_88 -> V_1 + V_10 ) )
F_69 ( F_4 ( F_5 ( V_88 -> V_1 + V_10 ) ) ) ;
F_77 ( ( unsigned long ) V_88 -> V_1 , 2 ) ;
F_77 ( ( unsigned long ) V_88 -> V_91 , 1 ) ;
F_69 ( V_57 -> V_88 ) ;
V_57 -> V_88 = NULL ;
}
static int F_83 ( struct V_66 * V_57 ,
struct V_28 * V_29 )
{
struct V_4 * V_5 = F_23 ( V_29 -> V_30 . V_31 ) ;
struct V_87 * V_88 = V_57 -> V_88 ;
unsigned long V_25 ;
int V_48 ;
V_48 = F_44 ( V_5 -> V_50 ) ;
if ( V_48 < 0 )
return V_48 ;
V_48 = 0 ;
F_80 ( & V_88 -> V_26 , V_25 ) ;
V_48 = F_39 ( V_5 , F_84 ( V_88 -> V_1 ) , V_57 ) ;
if ( V_48 == 0 ) {
F_9 ( ! F_79 ( & V_5 -> V_83 ) ) ;
V_5 -> V_29 = V_29 ;
F_85 ( & V_5 -> V_83 , & V_88 -> V_95 ) ;
}
F_82 ( & V_88 -> V_26 , V_25 ) ;
if ( V_48 < 0 ) {
F_46 ( V_29 , L_22 ,
V_100 , F_84 ( V_88 -> V_1 ) ) ;
F_45 ( V_5 -> V_50 ) ;
} else if ( V_48 > 0 ) {
F_35 ( V_29 , L_23 ,
V_100 , F_84 ( V_88 -> V_1 ) ) ;
} else {
F_35 ( V_29 , L_24 ,
V_100 , F_84 ( V_88 -> V_1 ) ) ;
}
return V_48 ;
}
static void F_86 ( struct V_66 * V_57 ,
struct V_28 * V_29 )
{
struct V_4 * V_5 = F_23 ( V_29 -> V_30 . V_31 ) ;
struct V_87 * V_88 = V_57 -> V_88 ;
struct V_101 * V_102 ;
unsigned long V_25 ;
bool V_103 = false ;
F_80 ( & V_88 -> V_26 , V_25 ) ;
F_87 (pos, &priv->clients) {
if ( F_88 ( V_102 , struct V_4 , V_83 ) == V_5 ) {
V_103 = true ;
break;
}
}
if ( ! V_103 )
goto V_62;
if ( F_37 ( V_5 ) ) {
F_35 ( V_29 , L_25 ,
V_100 , F_84 ( V_88 -> V_1 ) ) ;
F_89 ( & V_5 -> V_83 ) ;
} else {
F_35 ( V_29 , L_26 ,
V_100 , F_84 ( V_88 -> V_1 ) ) ;
}
V_62:
F_82 ( & V_88 -> V_26 , V_25 ) ;
if ( V_103 )
F_45 ( V_5 -> V_50 ) ;
}
static unsigned long * F_90 ( unsigned long * V_3 , unsigned long V_2 ,
short * V_104 )
{
if ( F_91 ( V_3 ) ) {
unsigned long * V_105 ;
V_105 = F_53 ( V_106 , V_107 ) ;
F_9 ( ( unsigned long ) V_105 & ( V_106 - 1 ) ) ;
if ( ! V_105 )
return NULL ;
* V_3 = F_92 ( F_84 ( V_105 ) ) ;
* V_104 = V_108 ;
F_70 ( V_105 , V_105 + V_108 ) ;
F_70 ( V_3 , V_3 + 1 ) ;
}
return F_3 ( V_3 , V_2 ) ;
}
static int F_93 ( unsigned long * V_3 , T_4 V_109 , short * V_110 )
{
if ( F_94 ( V_3 ) )
return - V_111 ;
if ( F_26 ( V_3 ) ) {
if ( * V_110 != V_108 )
return - V_111 ;
F_69 ( F_3 ( V_3 , 0 ) ) ;
* V_110 = 0 ;
}
* V_3 = F_95 ( V_109 ) ;
F_70 ( V_3 , V_3 + 1 ) ;
return 0 ;
}
static int F_96 ( unsigned long * V_105 , T_4 V_109 , T_5 V_20 ,
short * V_110 )
{
if ( V_20 == V_112 ) {
if ( ! F_97 ( V_105 ) )
return - V_111 ;
* V_105 = F_98 ( V_109 ) ;
F_70 ( V_105 , V_105 + 1 ) ;
* V_110 -= 1 ;
} else {
int V_10 ;
for ( V_10 = 0 ; V_10 < V_113 ; V_10 ++ , V_105 ++ ) {
if ( ! F_97 ( V_105 ) ) {
memset ( V_105 , 0 , sizeof( * V_105 ) * V_10 ) ;
return - V_111 ;
}
* V_105 = F_99 ( V_109 ) ;
}
F_70 ( V_105 - V_113 , V_105 ) ;
* V_110 -= V_113 ;
}
return 0 ;
}
static int F_100 ( struct V_66 * V_57 , unsigned long V_2 ,
T_4 V_109 , T_5 V_20 , int V_114 )
{
struct V_87 * V_88 = V_57 -> V_88 ;
unsigned long * V_115 ;
unsigned long V_25 ;
int V_48 = - V_70 ;
F_9 ( V_88 -> V_1 == NULL ) ;
F_80 ( & V_88 -> V_94 , V_25 ) ;
V_115 = F_1 ( V_88 -> V_1 , V_2 ) ;
if ( V_20 == V_116 ) {
V_48 = F_93 ( V_115 , V_109 ,
& V_88 -> V_91 [ F_2 ( V_2 ) ] ) ;
} else {
unsigned long * V_105 ;
V_105 = F_90 ( V_115 , V_2 ,
& V_88 -> V_91 [ F_2 ( V_2 ) ] ) ;
if ( ! V_105 )
V_48 = - V_70 ;
else
V_48 = F_96 ( V_105 , V_109 , V_20 ,
& V_88 -> V_91 [ F_2 ( V_2 ) ] ) ;
}
if ( V_48 ) {
F_101 ( L_27 ,
V_100 , V_2 , V_20 ) ;
}
F_82 ( & V_88 -> V_94 , V_25 ) ;
return V_48 ;
}
static T_5 F_102 ( struct V_66 * V_57 ,
unsigned long V_2 , T_5 V_20 )
{
struct V_87 * V_88 = V_57 -> V_88 ;
struct V_4 * V_5 ;
unsigned long V_25 ;
unsigned long * V_36 ;
F_9 ( V_88 -> V_1 == NULL ) ;
F_80 ( & V_88 -> V_94 , V_25 ) ;
V_36 = F_1 ( V_88 -> V_1 , V_2 ) ;
if ( F_94 ( V_36 ) ) {
F_9 ( V_20 < V_116 ) ;
* V_36 = 0 ;
F_70 ( V_36 , V_36 + 1 ) ;
V_20 = V_116 ;
goto V_117;
}
if ( F_103 ( F_91 ( V_36 ) ) ) {
if ( V_20 > V_116 )
V_20 = V_116 ;
goto V_117;
}
V_36 = F_3 ( V_36 , V_2 ) ;
if ( F_103 ( F_97 ( V_36 ) ) ) {
V_20 = V_112 ;
goto V_117;
}
if ( F_104 ( V_36 ) ) {
* V_36 = 0 ;
V_20 = V_112 ;
V_88 -> V_91 [ F_2 ( V_2 ) ] += 1 ;
goto V_117;
}
F_9 ( V_20 < V_118 ) ;
memset ( V_36 , 0 , sizeof( * V_36 ) * V_113 ) ;
V_20 = V_118 ;
V_88 -> V_91 [ F_2 ( V_2 ) ] += V_113 ;
V_117:
F_82 ( & V_88 -> V_94 , V_25 ) ;
F_80 ( & V_88 -> V_26 , V_25 ) ;
F_81 (data, &priv->clients, node)
F_48 ( V_5 -> V_29 , V_2 ) ;
F_82 ( & V_88 -> V_26 , V_25 ) ;
return V_20 ;
}
static T_4 F_105 ( struct V_66 * V_57 ,
T_6 V_2 )
{
struct V_87 * V_88 = V_57 -> V_88 ;
unsigned long * V_115 ;
unsigned long V_25 ;
T_4 V_119 = 0 ;
F_80 ( & V_88 -> V_94 , V_25 ) ;
V_115 = F_1 ( V_88 -> V_1 , V_2 ) ;
if ( F_94 ( V_115 ) ) {
V_119 = F_106 ( V_115 ) + F_107 ( V_2 ) ;
} else if ( F_26 ( V_115 ) ) {
V_115 = F_3 ( V_115 , V_2 ) ;
if ( F_108 ( V_115 ) )
V_119 = F_109 ( V_115 ) + F_110 ( V_2 ) ;
else if ( F_104 ( V_115 ) )
V_119 = F_111 ( V_115 ) + F_112 ( V_2 ) ;
}
F_82 ( & V_88 -> V_94 , V_25 ) ;
return V_119 ;
}
static int T_7 F_113 ( void )
{
int V_48 ;
V_48 = F_114 ( & V_120 ) ;
if ( V_48 == 0 )
F_115 ( & V_121 , & V_122 ) ;
return V_48 ;
}
