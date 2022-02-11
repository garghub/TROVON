static int F_1 ( const char * V_1 , int * V_2 , int V_3 , int V_4 )
{
int V_5 , V_6 ;
V_5 = F_2 ( V_1 , 10 , & V_6 ) ;
if ( V_5 )
return - V_7 ;
if ( V_6 < V_3 || V_6 > V_4 )
return - V_7 ;
* V_2 = V_6 ;
return 0 ;
}
static int F_3 ( const char * V_1 , const struct V_8 * V_9 )
{
return F_1 ( V_1 , & V_10 , V_11 , V_12 ) ;
}
static int F_4 ( const char * V_1 , const struct V_8 * V_9 )
{
return F_1 ( V_1 , & V_13 , V_14 ,
V_15 ) ;
}
static void F_5 ( struct V_16 * V_17 , unsigned int V_18 )
{
F_6 ( V_18 , V_17 -> V_19 ) ;
if ( F_7 ( & V_17 -> V_20 ) )
F_8 ( & V_17 -> V_20 ) ;
}
static unsigned int F_9 ( struct V_16 * V_17 )
{
unsigned int V_18 ;
do {
V_18 = F_10 ( V_17 -> V_19 , V_17 -> V_21 ) ;
if ( V_18 >= V_17 -> V_21 )
return - 1U ;
} while ( F_11 ( V_18 , V_17 -> V_19 ) );
return V_18 ;
}
static void F_12 ( struct V_22 * V_23 )
{
F_5 ( V_23 -> V_17 , V_23 -> V_18 ) ;
}
static struct V_22 * F_13 ( struct V_16 * V_17 )
{
struct V_22 * V_23 ;
unsigned int V_18 ;
V_18 = F_9 ( V_17 ) ;
if ( V_18 != - 1U ) {
V_23 = & V_17 -> V_24 [ V_18 ] ;
V_23 -> V_18 = V_18 ;
V_23 -> V_17 = V_17 ;
return V_23 ;
}
return NULL ;
}
static struct V_22 * F_14 ( struct V_16 * V_17 , int V_25 )
{
struct V_22 * V_23 ;
F_15 ( V_20 ) ;
V_23 = F_13 ( V_17 ) ;
if ( V_23 || ! V_25 )
return V_23 ;
do {
F_16 ( & V_17 -> V_20 , & V_20 , V_26 ) ;
V_23 = F_13 ( V_17 ) ;
if ( V_23 )
break;
F_17 () ;
} while ( 1 );
F_18 ( & V_17 -> V_20 , & V_20 ) ;
return V_23 ;
}
static void F_19 ( struct V_22 * V_23 )
{
switch ( V_10 ) {
case V_12 :
F_20 ( V_23 -> V_27 , 0 ) ;
return;
case V_28 :
F_21 ( & V_23 -> V_27 -> V_29 ) ;
F_22 ( V_23 -> V_27 , 0 ) ;
break;
case V_11 :
F_23 ( V_23 -> V_30 , 0 ) ;
break;
}
F_12 ( V_23 ) ;
}
static enum V_31 F_24 ( struct V_32 * V_33 )
{
struct V_34 * V_35 ;
struct V_36 * V_37 ;
struct V_22 * V_23 ;
V_35 = & F_25 ( V_38 , F_26 () ) ;
while ( ( V_37 = F_27 ( & V_35 -> V_39 ) ) != NULL ) {
V_37 = F_28 ( V_37 ) ;
do {
V_23 = F_29 ( V_37 , struct V_22 , V_40 ) ;
V_37 = V_37 -> V_41 ;
F_19 ( V_23 ) ;
} while ( V_37 );
}
return V_42 ;
}
static void F_30 ( struct V_22 * V_23 )
{
struct V_34 * V_35 = & F_25 ( V_38 , F_31 () ) ;
V_23 -> V_40 . V_41 = NULL ;
if ( F_32 ( & V_23 -> V_40 , & V_35 -> V_39 ) ) {
T_1 V_43 = F_33 ( 0 , V_44 ) ;
F_34 ( & V_35 -> V_33 , V_43 , V_45 ) ;
}
F_35 () ;
}
static void F_36 ( struct V_46 * V_27 )
{
if ( V_10 == V_12 )
F_19 ( F_37 ( V_27 ) ) ;
else
F_19 ( V_27 -> V_47 ) ;
}
static inline void F_38 ( struct V_22 * V_23 )
{
switch ( V_13 ) {
case V_48 :
switch ( V_10 ) {
case V_12 :
F_39 ( V_23 -> V_27 ) ;
break;
case V_28 :
F_40 ( V_23 -> V_27 ) ;
break;
case V_11 :
F_19 ( V_23 ) ;
break;
}
break;
case V_14 :
F_19 ( V_23 ) ;
break;
case V_15 :
F_30 ( V_23 ) ;
break;
}
}
static struct V_16 * F_41 ( struct V_49 * V_49 )
{
int V_50 = 0 ;
if ( V_49 -> V_51 != 1 )
V_50 = F_42 () / ( ( V_52 + V_49 -> V_51 - 1 ) / V_49 -> V_51 ) ;
return & V_49 -> V_53 [ V_50 ] ;
}
static void F_43 ( struct V_54 * V_55 , struct V_30 * V_30 )
{
struct V_49 * V_49 = V_55 -> V_56 ;
struct V_16 * V_17 = F_41 ( V_49 ) ;
struct V_22 * V_23 ;
V_23 = F_14 ( V_17 , 1 ) ;
V_23 -> V_30 = V_30 ;
F_38 ( V_23 ) ;
}
static int F_44 ( struct V_54 * V_55 , struct V_46 * V_57 )
{
struct V_49 * V_49 = V_55 -> V_56 ;
struct V_16 * V_17 = F_41 ( V_49 ) ;
struct V_22 * V_23 ;
V_23 = F_14 ( V_17 , 0 ) ;
if ( V_23 ) {
V_23 -> V_27 = V_57 ;
V_57 -> V_47 = V_23 ;
return V_58 ;
}
return V_59 ;
}
static void F_45 ( struct V_54 * V_55 )
{
struct V_46 * V_27 ;
while ( ( V_27 = F_46 ( V_55 ) ) != NULL ) {
struct V_22 * V_23 = V_27 -> V_47 ;
F_47 ( V_55 -> V_60 ) ;
F_38 ( V_23 ) ;
F_48 ( V_55 -> V_60 ) ;
}
}
static int F_49 ( struct V_61 * V_62 ,
const struct V_63 * V_64 )
{
struct V_22 * V_23 = F_37 ( V_64 -> V_27 ) ;
V_23 -> V_27 = V_64 -> V_27 ;
V_23 -> V_17 = V_62 -> V_65 ;
F_50 ( V_64 -> V_27 ) ;
F_38 ( V_23 ) ;
return V_66 ;
}
static void F_51 ( struct V_49 * V_49 , struct V_16 * V_17 )
{
F_52 ( ! V_49 ) ;
F_52 ( ! V_17 ) ;
F_53 ( & V_17 -> V_20 ) ;
V_17 -> V_21 = V_49 -> V_21 ;
}
static int F_54 ( struct V_61 * V_62 , void * V_67 ,
unsigned int V_50 )
{
struct V_49 * V_49 = V_67 ;
struct V_16 * V_17 = & V_49 -> V_53 [ V_50 ] ;
V_62 -> V_65 = V_17 ;
F_51 ( V_49 , V_17 ) ;
V_49 -> V_51 ++ ;
return 0 ;
}
static void F_55 ( struct V_49 * V_49 )
{
F_56 ( & V_49 -> V_39 ) ;
F_57 ( V_49 -> V_68 ) ;
F_58 ( V_49 -> V_55 ) ;
if ( V_10 == V_12 )
F_59 ( & V_49 -> V_69 ) ;
F_60 ( V_49 -> V_68 ) ;
F_61 ( V_49 ) ;
}
static int F_62 ( struct V_70 * V_71 , T_2 V_72 )
{
return 0 ;
}
static void F_63 ( struct V_73 * V_68 , T_2 V_72 )
{
}
static int F_64 ( struct V_16 * V_17 )
{
struct V_22 * V_23 ;
int V_74 , V_75 ;
V_17 -> V_24 = F_65 ( V_17 -> V_21 * sizeof( * V_23 ) , V_76 ) ;
if ( ! V_17 -> V_24 )
return - V_77 ;
V_75 = F_66 ( V_17 -> V_21 , V_78 ) / V_78 ;
V_17 -> V_19 = F_65 ( V_75 * sizeof( unsigned long ) , V_76 ) ;
if ( ! V_17 -> V_19 ) {
F_61 ( V_17 -> V_24 ) ;
return - V_77 ;
}
for ( V_74 = 0 ; V_74 < V_17 -> V_21 ; V_74 ++ ) {
V_23 = & V_17 -> V_24 [ V_74 ] ;
F_21 ( & V_23 -> V_39 ) ;
V_23 -> V_40 . V_41 = NULL ;
V_23 -> V_18 = - 1U ;
}
return 0 ;
}
static void F_67 ( struct V_16 * V_17 )
{
F_61 ( V_17 -> V_19 ) ;
F_61 ( V_17 -> V_24 ) ;
}
static void F_68 ( struct V_49 * V_49 )
{
int V_74 ;
for ( V_74 = 0 ; V_74 < V_49 -> V_51 ; V_74 ++ )
F_67 ( & V_49 -> V_53 [ V_74 ] ) ;
F_61 ( V_49 -> V_53 ) ;
}
static int F_69 ( struct V_49 * V_49 )
{
V_49 -> V_53 = F_65 ( V_79 * sizeof( struct V_16 ) ,
V_76 ) ;
if ( ! V_49 -> V_53 )
return - V_77 ;
V_49 -> V_51 = 0 ;
V_49 -> V_21 = V_80 ;
return 0 ;
}
static int F_70 ( struct V_49 * V_49 )
{
struct V_16 * V_17 ;
int V_74 , V_5 = 0 ;
for ( V_74 = 0 ; V_74 < V_79 ; V_74 ++ ) {
V_17 = & V_49 -> V_53 [ V_74 ] ;
F_51 ( V_49 , V_17 ) ;
V_5 = F_64 ( V_17 ) ;
if ( V_5 )
return V_5 ;
V_49 -> V_51 ++ ;
}
return 0 ;
}
static int F_71 ( void )
{
struct V_73 * V_68 ;
struct V_49 * V_49 ;
T_3 V_81 ;
int V_82 ;
V_49 = F_72 ( sizeof( * V_49 ) , V_76 , V_83 ) ;
if ( ! V_49 ) {
V_82 = - V_77 ;
goto V_84;
}
F_73 ( & V_49 -> V_85 ) ;
if ( V_10 == V_12 && V_86 )
V_79 = V_87 ;
V_82 = F_69 ( V_49 ) ;
if ( V_82 )
goto V_88;
if ( V_10 == V_12 ) {
V_49 -> V_69 . V_89 = & V_90 ;
V_49 -> V_69 . V_91 = V_79 ;
V_49 -> V_69 . V_21 = V_80 ;
V_49 -> V_69 . V_92 = V_83 ;
V_49 -> V_69 . V_93 = sizeof( struct V_22 ) ;
V_49 -> V_69 . V_94 = V_95 ;
V_49 -> V_69 . V_65 = V_49 ;
V_82 = F_74 ( & V_49 -> V_69 ) ;
if ( V_82 )
goto V_96;
V_49 -> V_55 = F_75 ( & V_49 -> V_69 ) ;
if ( F_76 ( V_49 -> V_55 ) ) {
V_82 = - V_77 ;
goto V_97;
}
} else if ( V_10 == V_11 ) {
V_49 -> V_55 = F_77 ( V_76 , V_83 ) ;
if ( ! V_49 -> V_55 ) {
V_82 = - V_77 ;
goto V_96;
}
F_78 ( V_49 -> V_55 , F_43 ) ;
V_82 = F_70 ( V_49 ) ;
if ( V_82 )
goto V_98;
} else {
V_49 -> V_55 = F_79 ( F_45 , & V_49 -> V_85 , V_83 ) ;
if ( ! V_49 -> V_55 ) {
V_82 = - V_77 ;
goto V_96;
}
F_80 ( V_49 -> V_55 , F_44 ) ;
F_81 ( V_49 -> V_55 , F_36 ) ;
V_82 = F_70 ( V_49 ) ;
if ( V_82 )
goto V_98;
}
V_49 -> V_55 -> V_56 = V_49 ;
F_82 ( V_99 , V_49 -> V_55 ) ;
F_83 ( V_100 , V_49 -> V_55 ) ;
V_68 = V_49 -> V_68 = F_84 ( 1 , V_83 ) ;
if ( ! V_68 ) {
V_82 = - V_77 ;
goto V_98;
}
F_85 ( & V_85 ) ;
F_86 ( & V_49 -> V_39 , & V_101 ) ;
V_49 -> V_50 = V_102 ++ ;
F_87 ( & V_85 ) ;
F_88 ( V_49 -> V_55 , V_103 ) ;
F_89 ( V_49 -> V_55 , V_103 ) ;
V_81 = V_104 * 1024 * 1024 * 1024ULL ;
F_90 ( V_81 , V_103 ) ;
F_91 ( V_68 , V_81 ) ;
V_68 -> V_94 |= V_105 | V_106 ;
V_68 -> V_107 = V_108 ;
V_68 -> V_109 = V_49 -> V_50 ;
V_68 -> V_110 = & V_111 ;
V_68 -> V_112 = V_49 ;
V_68 -> V_113 = V_49 -> V_55 ;
sprintf ( V_68 -> V_114 , L_1 , V_49 -> V_50 ) ;
F_92 ( V_68 ) ;
return 0 ;
V_98:
F_58 ( V_49 -> V_55 ) ;
V_97:
if ( V_10 == V_12 )
F_59 ( & V_49 -> V_69 ) ;
V_96:
F_68 ( V_49 ) ;
V_88:
F_61 ( V_49 ) ;
V_84:
return V_82 ;
}
static int T_4 F_93 ( void )
{
unsigned int V_74 ;
if ( V_103 > V_115 ) {
F_94 ( L_2 ) ;
F_94 ( L_3 , V_115 ) ;
V_103 = V_115 ;
}
if ( V_10 == V_12 && V_86 ) {
if ( V_79 < V_87 ) {
F_94 ( L_4 ,
V_87 ) ;
V_79 = V_87 ;
}
} else if ( V_79 > V_52 )
V_79 = V_52 ;
else if ( ! V_79 )
V_79 = 1 ;
F_95 ( & V_85 ) ;
F_96 (i) {
struct V_34 * V_35 = & F_25 ( V_38 , V_74 ) ;
F_97 ( & V_35 -> V_39 ) ;
if ( V_13 != V_15 )
continue;
F_98 ( & V_35 -> V_33 , V_116 , V_45 ) ;
V_35 -> V_33 . V_117 = F_24 ;
}
V_108 = F_99 ( 0 , L_5 ) ;
if ( V_108 < 0 )
return V_108 ;
for ( V_74 = 0 ; V_74 < V_118 ; V_74 ++ ) {
if ( F_71 () ) {
F_100 ( V_108 , L_5 ) ;
return - V_7 ;
}
}
F_101 ( L_6 ) ;
return 0 ;
}
static void T_5 F_102 ( void )
{
struct V_49 * V_49 ;
F_100 ( V_108 , L_5 ) ;
F_85 ( & V_85 ) ;
while ( ! F_103 ( & V_101 ) ) {
V_49 = F_104 ( V_101 . V_41 , struct V_49 , V_39 ) ;
F_55 ( V_49 ) ;
}
F_87 ( & V_85 ) ;
}
