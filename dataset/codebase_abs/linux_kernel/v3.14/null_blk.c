static void F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
F_2 ( V_3 , V_2 -> V_4 ) ;
if ( F_3 ( & V_2 -> V_5 ) )
F_4 ( & V_2 -> V_5 ) ;
}
static unsigned int F_5 ( struct V_1 * V_2 )
{
unsigned int V_3 ;
do {
V_3 = F_6 ( V_2 -> V_4 , V_2 -> V_6 ) ;
if ( V_3 >= V_2 -> V_6 )
return - 1U ;
} while ( F_7 ( V_3 , V_2 -> V_4 ) );
return V_3 ;
}
static void F_8 ( struct V_7 * V_8 )
{
F_1 ( V_8 -> V_2 , V_8 -> V_3 ) ;
}
static struct V_7 * F_9 ( struct V_1 * V_2 )
{
struct V_7 * V_8 ;
unsigned int V_3 ;
V_3 = F_5 ( V_2 ) ;
if ( V_3 != - 1U ) {
V_8 = & V_2 -> V_9 [ V_3 ] ;
V_8 -> V_3 = V_3 ;
V_8 -> V_2 = V_2 ;
return V_8 ;
}
return NULL ;
}
static struct V_7 * F_10 ( struct V_1 * V_2 , int V_10 )
{
struct V_7 * V_8 ;
F_11 ( V_5 ) ;
V_8 = F_9 ( V_2 ) ;
if ( V_8 || ! V_10 )
return V_8 ;
do {
F_12 ( & V_2 -> V_5 , & V_5 , V_11 ) ;
V_8 = F_9 ( V_2 ) ;
if ( V_8 )
break;
F_13 () ;
} while ( 1 );
F_14 ( & V_2 -> V_5 , & V_5 ) ;
return V_8 ;
}
static void F_15 ( struct V_7 * V_8 )
{
switch ( V_12 ) {
case V_13 :
F_16 ( V_8 -> V_14 , 0 ) ;
return;
case V_15 :
F_17 ( & V_8 -> V_14 -> V_16 ) ;
F_18 ( V_8 -> V_14 , 0 ) ;
break;
case V_17 :
F_19 ( V_8 -> V_18 , 0 ) ;
break;
}
F_8 ( V_8 ) ;
}
static enum V_19 F_20 ( struct V_20 * V_21 )
{
struct V_22 * V_23 ;
struct V_24 * V_25 ;
struct V_7 * V_8 ;
V_23 = & F_21 ( V_26 , F_22 () ) ;
while ( ( V_25 = F_23 ( & V_23 -> V_27 ) ) != NULL ) {
V_25 = F_24 ( V_25 ) ;
do {
V_8 = F_25 ( V_25 , struct V_7 , V_28 ) ;
F_15 ( V_8 ) ;
V_25 = V_25 -> V_29 ;
} while ( V_25 );
}
return V_30 ;
}
static void F_26 ( struct V_7 * V_8 )
{
struct V_22 * V_23 = & F_21 ( V_26 , F_27 () ) ;
V_8 -> V_28 . V_29 = NULL ;
if ( F_28 ( & V_8 -> V_28 , & V_23 -> V_27 ) ) {
T_1 V_31 = F_29 ( 0 , V_32 ) ;
F_30 ( & V_23 -> V_21 , V_31 , V_33 ) ;
}
F_31 () ;
}
static void F_32 ( struct V_34 * V_14 )
{
F_15 ( V_14 -> V_35 ) ;
}
static inline void F_33 ( struct V_7 * V_8 )
{
switch ( V_36 ) {
case V_37 :
switch ( V_12 ) {
case V_13 :
F_34 ( V_8 -> V_14 ) ;
break;
case V_15 :
F_35 ( V_8 -> V_14 ) ;
break;
case V_17 :
F_15 ( V_8 ) ;
break;
}
break;
case V_38 :
F_15 ( V_8 ) ;
break;
case V_39 :
F_26 ( V_8 ) ;
break;
}
}
static struct V_1 * F_36 ( struct V_40 * V_40 )
{
int V_41 = 0 ;
if ( V_40 -> V_42 != 1 )
V_41 = F_37 () / ( ( V_43 + V_40 -> V_42 - 1 ) / V_40 -> V_42 ) ;
return & V_40 -> V_44 [ V_41 ] ;
}
static void F_38 ( struct V_45 * V_46 , struct V_18 * V_18 )
{
struct V_40 * V_40 = V_46 -> V_47 ;
struct V_1 * V_2 = F_36 ( V_40 ) ;
struct V_7 * V_8 ;
V_8 = F_10 ( V_2 , 1 ) ;
V_8 -> V_18 = V_18 ;
F_33 ( V_8 ) ;
}
static int F_39 ( struct V_45 * V_46 , struct V_34 * V_48 )
{
struct V_40 * V_40 = V_46 -> V_47 ;
struct V_1 * V_2 = F_36 ( V_40 ) ;
struct V_7 * V_8 ;
V_8 = F_10 ( V_2 , 0 ) ;
if ( V_8 ) {
V_8 -> V_14 = V_48 ;
V_48 -> V_35 = V_8 ;
return V_49 ;
}
return V_50 ;
}
static void F_40 ( struct V_45 * V_46 )
{
struct V_34 * V_14 ;
while ( ( V_14 = F_41 ( V_46 ) ) != NULL ) {
struct V_7 * V_8 = V_14 -> V_35 ;
F_42 ( V_46 -> V_51 ) ;
F_33 ( V_8 ) ;
F_43 ( V_46 -> V_51 ) ;
}
}
static int F_44 ( struct V_52 * V_53 , struct V_34 * V_14 )
{
struct V_7 * V_8 = V_14 -> V_35 ;
V_8 -> V_14 = V_14 ;
V_8 -> V_2 = V_53 -> V_54 ;
F_33 ( V_8 ) ;
return V_55 ;
}
static struct V_52 * F_45 ( struct V_56 * V_57 , unsigned int V_58 )
{
int V_59 = F_46 ( V_57 -> V_60 , V_61 ) ;
int V_62 = ( V_57 -> V_60 % V_61 ) ;
int V_63 = 0 , V_64 , V_65 ;
for ( V_64 = 0 , V_65 = 1 ; V_64 < V_58 ; V_64 ++ , V_65 ++ ) {
if ( V_65 % V_59 == 0 ) {
V_65 = 0 ;
V_63 ++ ;
V_62 -- ;
if ( ! V_62 )
V_59 = V_57 -> V_60 / V_61 ;
}
}
F_47 (n) {
if ( ! V_63 )
break;
V_63 -- ;
}
return F_48 ( sizeof( struct V_52 ) , V_66 , V_65 ) ;
}
static void F_49 ( struct V_52 * V_53 , unsigned int V_58 )
{
F_50 ( V_53 ) ;
}
static void F_51 ( struct V_40 * V_40 , struct V_1 * V_2 )
{
F_52 ( ! V_40 ) ;
F_52 ( ! V_2 ) ;
F_53 ( & V_2 -> V_5 ) ;
V_2 -> V_6 = V_40 -> V_6 ;
}
static int F_54 ( struct V_52 * V_53 , void * V_67 ,
unsigned int V_41 )
{
struct V_40 * V_40 = V_67 ;
struct V_1 * V_2 = & V_40 -> V_44 [ V_41 ] ;
V_53 -> V_54 = V_2 ;
F_51 ( V_40 , V_2 ) ;
V_40 -> V_42 ++ ;
return 0 ;
}
static void F_55 ( struct V_40 * V_40 )
{
F_56 ( & V_40 -> V_27 ) ;
F_57 ( V_40 -> V_68 ) ;
F_58 ( V_40 -> V_46 ) ;
F_59 ( V_40 -> V_68 ) ;
F_50 ( V_40 ) ;
}
static int F_60 ( struct V_69 * V_70 , T_2 V_71 )
{
return 0 ;
}
static void F_61 ( struct V_72 * V_68 , T_2 V_71 )
{
}
static int F_62 ( struct V_1 * V_2 )
{
struct V_7 * V_8 ;
int V_64 , V_73 ;
V_2 -> V_9 = F_63 ( V_2 -> V_6 * sizeof( * V_8 ) , V_66 ) ;
if ( ! V_2 -> V_9 )
return - V_74 ;
V_73 = F_64 ( V_2 -> V_6 , V_75 ) / V_75 ;
V_2 -> V_4 = F_63 ( V_73 * sizeof( unsigned long ) , V_66 ) ;
if ( ! V_2 -> V_4 ) {
F_50 ( V_2 -> V_9 ) ;
return - V_74 ;
}
for ( V_64 = 0 ; V_64 < V_2 -> V_6 ; V_64 ++ ) {
V_8 = & V_2 -> V_9 [ V_64 ] ;
F_17 ( & V_8 -> V_27 ) ;
V_8 -> V_28 . V_29 = NULL ;
V_8 -> V_3 = - 1U ;
}
return 0 ;
}
static void F_65 ( struct V_1 * V_2 )
{
F_50 ( V_2 -> V_4 ) ;
F_50 ( V_2 -> V_9 ) ;
}
static void F_66 ( struct V_40 * V_40 )
{
int V_64 ;
for ( V_64 = 0 ; V_64 < V_40 -> V_42 ; V_64 ++ )
F_65 ( & V_40 -> V_44 [ V_64 ] ) ;
F_50 ( V_40 -> V_44 ) ;
}
static int F_67 ( struct V_40 * V_40 )
{
V_40 -> V_44 = F_63 ( V_76 * sizeof( struct V_1 ) ,
V_66 ) ;
if ( ! V_40 -> V_44 )
return - V_74 ;
V_40 -> V_42 = 0 ;
V_40 -> V_6 = V_77 ;
return 0 ;
}
static int F_68 ( struct V_40 * V_40 )
{
struct V_1 * V_2 ;
int V_64 , V_78 = 0 ;
for ( V_64 = 0 ; V_64 < V_76 ; V_64 ++ ) {
V_2 = & V_40 -> V_44 [ V_64 ] ;
F_51 ( V_40 , V_2 ) ;
V_78 = F_62 ( V_2 ) ;
if ( V_78 )
goto V_79;
V_40 -> V_42 ++ ;
}
return 0 ;
V_79:
F_66 ( V_40 ) ;
return V_78 ;
}
static int F_69 ( void )
{
struct V_72 * V_68 ;
struct V_40 * V_40 ;
T_3 V_80 ;
V_40 = F_48 ( sizeof( * V_40 ) , V_66 , V_81 ) ;
if ( ! V_40 )
return - V_74 ;
F_70 ( & V_40 -> V_82 ) ;
if ( V_12 == V_13 && V_83 )
V_76 = V_61 ;
if ( F_67 ( V_40 ) )
goto V_84;
if ( V_12 == V_13 ) {
V_85 . V_86 = V_81 ;
V_85 . V_6 = V_77 ;
V_85 . V_60 = V_76 ;
if ( V_83 ) {
V_85 . V_87 -> V_88 = F_45 ;
V_85 . V_87 -> V_89 = F_49 ;
} else {
V_85 . V_87 -> V_88 = V_90 ;
V_85 . V_87 -> V_89 = V_91 ;
}
V_40 -> V_46 = F_71 ( & V_85 , V_40 ) ;
} else if ( V_12 == V_17 ) {
V_40 -> V_46 = F_72 ( V_66 , V_81 ) ;
F_73 ( V_40 -> V_46 , F_38 ) ;
F_68 ( V_40 ) ;
} else {
V_40 -> V_46 = F_74 ( F_40 , & V_40 -> V_82 , V_81 ) ;
F_75 ( V_40 -> V_46 , F_39 ) ;
if ( V_40 -> V_46 )
F_76 ( V_40 -> V_46 , F_32 ) ;
F_68 ( V_40 ) ;
}
if ( ! V_40 -> V_46 )
goto V_92;
V_40 -> V_46 -> V_47 = V_40 ;
F_77 ( V_93 , V_40 -> V_46 ) ;
V_68 = V_40 -> V_68 = F_78 ( 1 , V_81 ) ;
if ( ! V_68 ) {
V_92:
F_58 ( V_40 -> V_46 ) ;
F_66 ( V_40 ) ;
V_84:
F_50 ( V_40 ) ;
return - V_74 ;
}
F_79 ( & V_82 ) ;
F_80 ( & V_40 -> V_27 , & V_94 ) ;
V_40 -> V_41 = V_95 ++ ;
F_81 ( & V_82 ) ;
F_82 ( V_40 -> V_46 , V_96 ) ;
F_83 ( V_40 -> V_46 , V_96 ) ;
V_80 = V_97 * 1024 * 1024 * 1024ULL ;
F_84 ( V_80 , V_96 ) ;
F_85 ( V_68 , V_80 ) ;
V_68 -> V_98 |= V_99 ;
V_68 -> V_100 = V_101 ;
V_68 -> V_102 = V_40 -> V_41 ;
V_68 -> V_103 = & V_104 ;
V_68 -> V_105 = V_40 ;
V_68 -> V_106 = V_40 -> V_46 ;
sprintf ( V_68 -> V_107 , L_1 , V_40 -> V_41 ) ;
F_86 ( V_68 ) ;
return 0 ;
}
static int T_4 F_87 ( void )
{
unsigned int V_64 ;
if ( V_96 > V_108 ) {
F_88 ( L_2 ) ;
F_88 ( L_3 , V_108 ) ;
V_96 = V_108 ;
}
if ( V_12 == V_13 && V_83 ) {
if ( V_76 < V_61 ) {
F_88 ( L_4 ,
V_61 ) ;
V_76 = V_61 ;
}
} else if ( V_76 > V_43 )
V_76 = V_43 ;
else if ( ! V_76 )
V_76 = 1 ;
F_89 ( & V_82 ) ;
F_90 (i) {
struct V_22 * V_23 = & F_21 ( V_26 , V_64 ) ;
F_91 ( & V_23 -> V_27 ) ;
if ( V_36 != V_39 )
continue;
F_92 ( & V_23 -> V_21 , V_109 , V_33 ) ;
V_23 -> V_21 . V_110 = F_20 ;
}
V_101 = F_93 ( 0 , L_5 ) ;
if ( V_101 < 0 )
return V_101 ;
for ( V_64 = 0 ; V_64 < V_111 ; V_64 ++ ) {
if ( F_69 () ) {
F_94 ( V_101 , L_5 ) ;
return - V_112 ;
}
}
F_95 ( L_6 ) ;
return 0 ;
}
static void T_5 F_96 ( void )
{
struct V_40 * V_40 ;
F_94 ( V_101 , L_5 ) ;
F_79 ( & V_82 ) ;
while ( ! F_97 ( & V_94 ) ) {
V_40 = F_98 ( V_94 . V_29 , struct V_40 , V_27 ) ;
F_55 ( V_40 ) ;
}
F_81 ( & V_82 ) ;
}
