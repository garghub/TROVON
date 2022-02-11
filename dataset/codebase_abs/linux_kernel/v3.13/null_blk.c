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
if ( V_8 -> V_12 ) {
if ( V_13 == V_14 )
F_16 ( V_8 -> V_12 , 0 ) ;
else {
F_17 ( & V_8 -> V_12 -> V_15 ) ;
F_18 ( V_8 -> V_12 , 0 ) ;
}
} else if ( V_8 -> V_16 )
F_19 ( V_8 -> V_16 , 0 ) ;
if ( V_13 != V_14 )
F_8 ( V_8 ) ;
}
static enum V_17 F_20 ( struct V_18 * V_19 )
{
struct V_20 * V_21 ;
struct V_22 * V_23 ;
struct V_7 * V_8 ;
V_21 = & F_21 ( V_24 , F_22 () ) ;
while ( ( V_23 = F_23 ( & V_21 -> V_25 ) ) != NULL ) {
do {
V_8 = F_24 ( V_23 , struct V_7 , V_26 ) ;
F_15 ( V_8 ) ;
V_23 = V_23 -> V_27 ;
} while ( V_23 );
}
return V_28 ;
}
static void F_25 ( struct V_7 * V_8 )
{
struct V_20 * V_21 = & F_21 ( V_24 , F_26 () ) ;
V_8 -> V_26 . V_27 = NULL ;
if ( F_27 ( & V_8 -> V_26 , & V_21 -> V_25 ) ) {
T_1 V_29 = F_28 ( 0 , V_30 ) ;
F_29 ( & V_21 -> V_19 , V_29 , V_31 ) ;
}
F_30 () ;
}
static void F_31 ( struct V_32 * V_12 )
{
F_18 ( V_12 , 0 ) ;
}
static void F_32 ( void * V_33 )
{
struct V_20 * V_21 ;
struct V_22 * V_23 , * V_27 ;
struct V_7 * V_8 ;
V_21 = & F_21 ( V_24 , F_22 () ) ;
V_23 = F_23 ( & V_21 -> V_25 ) ;
while ( V_23 ) {
V_27 = V_23 -> V_27 ;
V_8 = F_33 ( V_23 , struct V_7 , V_26 ) ;
F_15 ( V_8 ) ;
V_23 = V_27 ;
}
}
static void F_34 ( struct V_7 * V_8 )
{
struct V_34 * V_33 = & V_8 -> V_35 ;
int V_36 = F_26 () ;
struct V_20 * V_21 = & F_21 ( V_24 , V_36 ) ;
V_8 -> V_26 . V_27 = NULL ;
if ( F_27 ( & V_8 -> V_26 , & V_21 -> V_25 ) ) {
V_33 -> V_37 = F_32 ;
V_33 -> V_38 = 0 ;
F_35 ( V_36 , V_33 , 0 ) ;
}
F_30 () ;
}
static inline void F_36 ( struct V_7 * V_8 )
{
switch ( V_39 ) {
case V_40 :
F_15 ( V_8 ) ;
break;
case V_41 :
#ifdef F_37
F_34 ( V_8 ) ;
#else
F_15 ( V_8 ) ;
#endif
break;
case V_42 :
F_25 ( V_8 ) ;
break;
}
}
static struct V_1 * F_38 ( struct V_43 * V_43 )
{
int V_44 = 0 ;
if ( V_43 -> V_45 != 1 )
V_44 = F_39 () / ( ( V_46 + V_43 -> V_45 - 1 ) / V_43 -> V_45 ) ;
return & V_43 -> V_47 [ V_44 ] ;
}
static void F_40 ( struct V_48 * V_49 , struct V_16 * V_16 )
{
struct V_43 * V_43 = V_49 -> V_50 ;
struct V_1 * V_2 = F_38 ( V_43 ) ;
struct V_7 * V_8 ;
V_8 = F_10 ( V_2 , 1 ) ;
V_8 -> V_16 = V_16 ;
F_36 ( V_8 ) ;
}
static int F_41 ( struct V_48 * V_49 , struct V_32 * V_51 )
{
struct V_43 * V_43 = V_49 -> V_50 ;
struct V_1 * V_2 = F_38 ( V_43 ) ;
struct V_7 * V_8 ;
V_8 = F_10 ( V_2 , 0 ) ;
if ( V_8 ) {
V_8 -> V_12 = V_51 ;
V_51 -> V_52 = V_8 ;
return V_53 ;
}
return V_54 ;
}
static void F_42 ( struct V_48 * V_49 )
{
struct V_32 * V_12 ;
while ( ( V_12 = F_43 ( V_49 ) ) != NULL ) {
struct V_7 * V_8 = V_12 -> V_52 ;
F_44 ( V_49 -> V_55 ) ;
F_36 ( V_8 ) ;
F_45 ( V_49 -> V_55 ) ;
}
}
static int F_46 ( struct V_56 * V_57 , struct V_32 * V_12 )
{
struct V_7 * V_8 = V_12 -> V_52 ;
V_8 -> V_12 = V_12 ;
V_8 -> V_2 = V_57 -> V_58 ;
F_36 ( V_8 ) ;
return V_59 ;
}
static struct V_56 * F_47 ( struct V_60 * V_61 , unsigned int V_62 )
{
int V_63 = F_48 ( V_61 -> V_64 , V_65 ) ;
int V_66 = ( V_61 -> V_64 % V_65 ) ;
int V_67 = 0 , V_68 , V_69 ;
for ( V_68 = 0 , V_69 = 1 ; V_68 < V_62 ; V_68 ++ , V_69 ++ ) {
if ( V_69 % V_63 == 0 ) {
V_69 = 0 ;
V_67 ++ ;
V_66 -- ;
if ( ! V_66 )
V_63 = V_61 -> V_64 / V_65 ;
}
}
F_49 (n) {
if ( ! V_67 )
break;
V_67 -- ;
}
return F_50 ( sizeof( struct V_56 ) , V_70 , V_69 ) ;
}
static void F_51 ( struct V_56 * V_57 , unsigned int V_62 )
{
F_52 ( V_57 ) ;
}
static void F_53 ( struct V_43 * V_43 , struct V_1 * V_2 )
{
F_54 ( ! V_43 ) ;
F_54 ( ! V_2 ) ;
F_55 ( & V_2 -> V_5 ) ;
V_2 -> V_6 = V_43 -> V_6 ;
}
static int F_56 ( struct V_56 * V_57 , void * V_33 ,
unsigned int V_44 )
{
struct V_43 * V_43 = V_33 ;
struct V_1 * V_2 = & V_43 -> V_47 [ V_44 ] ;
V_57 -> V_58 = V_2 ;
F_53 ( V_43 , V_2 ) ;
V_43 -> V_45 ++ ;
return 0 ;
}
static void F_57 ( struct V_43 * V_43 )
{
F_58 ( & V_43 -> V_25 ) ;
F_59 ( V_43 -> V_71 ) ;
F_60 ( V_43 -> V_49 ) ;
F_61 ( V_43 -> V_71 ) ;
F_52 ( V_43 ) ;
}
static int F_62 ( struct V_72 * V_73 , T_2 V_74 )
{
return 0 ;
}
static void F_63 ( struct V_75 * V_71 , T_2 V_74 )
{
}
static int F_64 ( struct V_1 * V_2 )
{
struct V_7 * V_8 ;
int V_68 , V_76 ;
V_2 -> V_9 = F_65 ( V_2 -> V_6 * sizeof( * V_8 ) , V_70 ) ;
if ( ! V_2 -> V_9 )
return - V_77 ;
V_76 = F_66 ( V_2 -> V_6 , V_78 ) / V_78 ;
V_2 -> V_4 = F_65 ( V_76 * sizeof( unsigned long ) , V_70 ) ;
if ( ! V_2 -> V_4 ) {
F_52 ( V_2 -> V_9 ) ;
return - V_77 ;
}
for ( V_68 = 0 ; V_68 < V_2 -> V_6 ; V_68 ++ ) {
V_8 = & V_2 -> V_9 [ V_68 ] ;
F_17 ( & V_8 -> V_25 ) ;
V_8 -> V_26 . V_27 = NULL ;
V_8 -> V_3 = - 1U ;
}
return 0 ;
}
static void F_67 ( struct V_1 * V_2 )
{
F_52 ( V_2 -> V_4 ) ;
F_52 ( V_2 -> V_9 ) ;
}
static void F_68 ( struct V_43 * V_43 )
{
int V_68 ;
for ( V_68 = 0 ; V_68 < V_43 -> V_45 ; V_68 ++ )
F_67 ( & V_43 -> V_47 [ V_68 ] ) ;
F_52 ( V_43 -> V_47 ) ;
}
static int F_69 ( struct V_43 * V_43 )
{
V_43 -> V_47 = F_65 ( V_79 * sizeof( struct V_1 ) ,
V_70 ) ;
if ( ! V_43 -> V_47 )
return - V_77 ;
V_43 -> V_45 = 0 ;
V_43 -> V_6 = V_80 ;
return 0 ;
}
static int F_70 ( struct V_43 * V_43 )
{
struct V_1 * V_2 ;
int V_68 , V_81 = 0 ;
for ( V_68 = 0 ; V_68 < V_79 ; V_68 ++ ) {
V_2 = & V_43 -> V_47 [ V_68 ] ;
F_53 ( V_43 , V_2 ) ;
V_81 = F_64 ( V_2 ) ;
if ( V_81 )
goto V_82;
V_43 -> V_45 ++ ;
}
return 0 ;
V_82:
F_68 ( V_43 ) ;
return V_81 ;
}
static int F_71 ( void )
{
struct V_75 * V_71 ;
struct V_43 * V_43 ;
T_3 V_83 ;
V_43 = F_50 ( sizeof( * V_43 ) , V_70 , V_84 ) ;
if ( ! V_43 )
return - V_77 ;
F_72 ( & V_43 -> V_85 ) ;
if ( V_13 == V_14 && V_86 )
V_79 = V_65 ;
if ( F_69 ( V_43 ) )
goto V_87;
if ( V_13 == V_14 ) {
V_88 . V_89 = V_84 ;
V_88 . V_6 = V_80 ;
V_88 . V_64 = V_79 ;
if ( V_86 ) {
V_88 . V_90 -> V_91 = F_47 ;
V_88 . V_90 -> V_92 = F_51 ;
} else {
V_88 . V_90 -> V_91 = V_93 ;
V_88 . V_90 -> V_92 = V_94 ;
}
V_43 -> V_49 = F_73 ( & V_88 , V_43 ) ;
} else if ( V_13 == V_95 ) {
V_43 -> V_49 = F_74 ( V_70 , V_84 ) ;
F_75 ( V_43 -> V_49 , F_40 ) ;
F_70 ( V_43 ) ;
} else {
V_43 -> V_49 = F_76 ( F_42 , & V_43 -> V_85 , V_84 ) ;
F_77 ( V_43 -> V_49 , F_41 ) ;
if ( V_43 -> V_49 )
F_78 ( V_43 -> V_49 , F_31 ) ;
F_70 ( V_43 ) ;
}
if ( ! V_43 -> V_49 )
goto V_96;
V_43 -> V_49 -> V_50 = V_43 ;
F_79 ( V_97 , V_43 -> V_49 ) ;
V_71 = V_43 -> V_71 = F_80 ( 1 , V_84 ) ;
if ( ! V_71 ) {
V_96:
F_60 ( V_43 -> V_49 ) ;
F_68 ( V_43 ) ;
V_87:
F_52 ( V_43 ) ;
return - V_77 ;
}
F_81 ( & V_85 ) ;
F_82 ( & V_43 -> V_25 , & V_98 ) ;
V_43 -> V_44 = V_99 ++ ;
F_83 ( & V_85 ) ;
F_84 ( V_43 -> V_49 , V_100 ) ;
F_85 ( V_43 -> V_49 , V_100 ) ;
V_83 = V_101 * 1024 * 1024 * 1024ULL ;
F_86 ( V_83 , V_100 ) ;
F_87 ( V_71 , V_83 ) ;
V_71 -> V_38 |= V_102 ;
V_71 -> V_103 = V_104 ;
V_71 -> V_105 = V_43 -> V_44 ;
V_71 -> V_106 = & V_107 ;
V_71 -> V_108 = V_43 ;
V_71 -> V_109 = V_43 -> V_49 ;
sprintf ( V_71 -> V_110 , L_1 , V_43 -> V_44 ) ;
F_88 ( V_71 ) ;
return 0 ;
}
static int T_4 F_89 ( void )
{
unsigned int V_68 ;
#if ! F_90 ( F_37 )
if ( V_39 == V_41 ) {
F_91 ( L_2 ) ;
F_91 ( L_3 ) ;
V_39 = V_40 ;
}
#endif
if ( V_13 == V_14 && V_86 ) {
if ( V_79 < V_65 ) {
F_91 ( L_4 ,
V_65 ) ;
V_79 = V_65 ;
}
} else if ( V_79 > V_46 )
V_79 = V_46 ;
else if ( ! V_79 )
V_79 = 1 ;
F_92 ( & V_85 ) ;
F_93 (i) {
struct V_20 * V_21 = & F_21 ( V_24 , V_68 ) ;
F_94 ( & V_21 -> V_25 ) ;
if ( V_39 != V_42 )
continue;
F_95 ( & V_21 -> V_19 , V_111 , V_31 ) ;
V_21 -> V_19 . V_112 = F_20 ;
}
V_104 = F_96 ( 0 , L_5 ) ;
if ( V_104 < 0 )
return V_104 ;
for ( V_68 = 0 ; V_68 < V_113 ; V_68 ++ ) {
if ( F_71 () ) {
F_97 ( V_104 , L_5 ) ;
return - V_114 ;
}
}
F_98 ( L_6 ) ;
return 0 ;
}
static void T_5 F_99 ( void )
{
struct V_43 * V_43 ;
F_97 ( V_104 , L_5 ) ;
F_81 ( & V_85 ) ;
while ( ! F_100 ( & V_98 ) ) {
V_43 = F_101 ( V_98 . V_27 , struct V_43 , V_25 ) ;
F_57 ( V_43 ) ;
}
F_83 ( & V_85 ) ;
}
