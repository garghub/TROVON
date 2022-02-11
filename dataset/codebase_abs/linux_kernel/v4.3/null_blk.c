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
F_23 ( V_23 -> V_30 ) ;
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
struct V_40 * V_41 = NULL ;
V_23 = F_29 ( V_37 , struct V_22 , V_42 ) ;
V_37 = V_37 -> V_43 ;
if ( V_23 -> V_27 )
V_41 = V_23 -> V_27 -> V_41 ;
F_19 ( V_23 ) ;
if ( V_41 && ! V_41 -> V_44 && F_30 ( V_41 ) ) {
F_31 ( V_41 -> V_45 ) ;
if ( F_30 ( V_41 ) )
F_32 ( V_41 ) ;
F_33 ( V_41 -> V_45 ) ;
}
} while ( V_37 );
}
return V_46 ;
}
static void F_34 ( struct V_22 * V_23 )
{
struct V_34 * V_35 = & F_25 ( V_38 , F_35 () ) ;
V_23 -> V_42 . V_43 = NULL ;
if ( F_36 ( & V_23 -> V_42 , & V_35 -> V_39 ) ) {
T_1 V_47 = F_37 ( 0 , V_48 ) ;
F_38 ( & V_35 -> V_33 , V_47 , V_49 ) ;
}
F_39 () ;
}
static void F_40 ( struct V_50 * V_27 )
{
if ( V_10 == V_12 )
F_19 ( F_41 ( V_27 ) ) ;
else
F_19 ( V_27 -> V_51 ) ;
}
static inline void F_42 ( struct V_22 * V_23 )
{
switch ( V_13 ) {
case V_52 :
switch ( V_10 ) {
case V_12 :
F_43 ( V_23 -> V_27 , V_23 -> V_27 -> V_53 ) ;
break;
case V_28 :
F_44 ( V_23 -> V_27 ) ;
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
F_34 ( V_23 ) ;
break;
}
}
static struct V_16 * F_45 ( struct V_54 * V_54 )
{
int V_55 = 0 ;
if ( V_54 -> V_56 != 1 )
V_55 = F_46 () / ( ( V_57 + V_54 -> V_56 - 1 ) / V_54 -> V_56 ) ;
return & V_54 -> V_58 [ V_55 ] ;
}
static void F_47 ( struct V_40 * V_41 , struct V_30 * V_30 )
{
struct V_54 * V_54 = V_41 -> V_59 ;
struct V_16 * V_17 = F_45 ( V_54 ) ;
struct V_22 * V_23 ;
V_23 = F_14 ( V_17 , 1 ) ;
V_23 -> V_30 = V_30 ;
F_42 ( V_23 ) ;
}
static int F_48 ( struct V_40 * V_41 , struct V_50 * V_60 )
{
struct V_54 * V_54 = V_41 -> V_59 ;
struct V_16 * V_17 = F_45 ( V_54 ) ;
struct V_22 * V_23 ;
V_23 = F_14 ( V_17 , 0 ) ;
if ( V_23 ) {
V_23 -> V_27 = V_60 ;
V_60 -> V_51 = V_23 ;
return V_61 ;
}
F_49 ( V_41 ) ;
return V_62 ;
}
static void F_50 ( struct V_40 * V_41 )
{
struct V_50 * V_27 ;
while ( ( V_27 = F_51 ( V_41 ) ) != NULL ) {
struct V_22 * V_23 = V_27 -> V_51 ;
F_52 ( V_41 -> V_45 ) ;
F_42 ( V_23 ) ;
F_53 ( V_41 -> V_45 ) ;
}
}
static int F_54 ( struct V_63 * V_64 ,
const struct V_65 * V_66 )
{
struct V_22 * V_23 = F_41 ( V_66 -> V_27 ) ;
V_23 -> V_27 = V_66 -> V_27 ;
V_23 -> V_17 = V_64 -> V_67 ;
F_55 ( V_66 -> V_27 ) ;
F_42 ( V_23 ) ;
return V_68 ;
}
static void F_56 ( struct V_54 * V_54 , struct V_16 * V_17 )
{
F_57 ( ! V_54 ) ;
F_57 ( ! V_17 ) ;
F_58 ( & V_17 -> V_20 ) ;
V_17 -> V_21 = V_54 -> V_21 ;
}
static int F_59 ( struct V_63 * V_64 , void * V_69 ,
unsigned int V_55 )
{
struct V_54 * V_54 = V_69 ;
struct V_16 * V_17 = & V_54 -> V_58 [ V_55 ] ;
V_64 -> V_67 = V_17 ;
F_56 ( V_54 , V_17 ) ;
V_54 -> V_56 ++ ;
return 0 ;
}
static void F_60 ( struct V_16 * V_17 )
{
F_61 ( V_17 -> V_19 ) ;
F_61 ( V_17 -> V_24 ) ;
}
static void F_62 ( struct V_54 * V_54 )
{
int V_70 ;
for ( V_70 = 0 ; V_70 < V_54 -> V_56 ; V_70 ++ )
F_60 ( & V_54 -> V_58 [ V_70 ] ) ;
F_61 ( V_54 -> V_58 ) ;
}
static void F_63 ( struct V_54 * V_54 )
{
F_64 ( & V_54 -> V_39 ) ;
F_65 ( V_54 -> V_71 ) ;
F_66 ( V_54 -> V_41 ) ;
if ( V_10 == V_12 )
F_67 ( & V_54 -> V_72 ) ;
F_68 ( V_54 -> V_71 ) ;
F_62 ( V_54 ) ;
F_61 ( V_54 ) ;
}
static int F_69 ( struct V_73 * V_74 , T_2 V_75 )
{
return 0 ;
}
static void F_70 ( struct V_76 * V_71 , T_2 V_75 )
{
}
static int F_71 ( struct V_16 * V_17 )
{
struct V_22 * V_23 ;
int V_70 , V_77 ;
V_17 -> V_24 = F_72 ( V_17 -> V_21 * sizeof( * V_23 ) , V_78 ) ;
if ( ! V_17 -> V_24 )
return - V_79 ;
V_77 = F_73 ( V_17 -> V_21 , V_80 ) / V_80 ;
V_17 -> V_19 = F_72 ( V_77 * sizeof( unsigned long ) , V_78 ) ;
if ( ! V_17 -> V_19 ) {
F_61 ( V_17 -> V_24 ) ;
return - V_79 ;
}
for ( V_70 = 0 ; V_70 < V_17 -> V_21 ; V_70 ++ ) {
V_23 = & V_17 -> V_24 [ V_70 ] ;
F_21 ( & V_23 -> V_39 ) ;
V_23 -> V_42 . V_43 = NULL ;
V_23 -> V_18 = - 1U ;
}
return 0 ;
}
static int F_74 ( struct V_54 * V_54 )
{
V_54 -> V_58 = F_72 ( V_81 * sizeof( struct V_16 ) ,
V_78 ) ;
if ( ! V_54 -> V_58 )
return - V_79 ;
V_54 -> V_56 = 0 ;
V_54 -> V_21 = V_82 ;
return 0 ;
}
static int F_75 ( struct V_54 * V_54 )
{
struct V_16 * V_17 ;
int V_70 , V_5 = 0 ;
for ( V_70 = 0 ; V_70 < V_81 ; V_70 ++ ) {
V_17 = & V_54 -> V_58 [ V_70 ] ;
F_56 ( V_54 , V_17 ) ;
V_5 = F_71 ( V_17 ) ;
if ( V_5 )
return V_5 ;
V_54 -> V_56 ++ ;
}
return 0 ;
}
static int F_76 ( void )
{
struct V_76 * V_71 ;
struct V_54 * V_54 ;
T_3 V_83 ;
int V_84 ;
V_54 = F_77 ( sizeof( * V_54 ) , V_78 , V_85 ) ;
if ( ! V_54 ) {
V_84 = - V_79 ;
goto V_86;
}
F_78 ( & V_54 -> V_87 ) ;
if ( V_10 == V_12 && V_88 )
V_81 = V_89 ;
V_84 = F_74 ( V_54 ) ;
if ( V_84 )
goto V_90;
if ( V_10 == V_12 ) {
V_54 -> V_72 . V_91 = & V_92 ;
V_54 -> V_72 . V_93 = V_81 ;
V_54 -> V_72 . V_21 = V_82 ;
V_54 -> V_72 . V_94 = V_85 ;
V_54 -> V_72 . V_95 = sizeof( struct V_22 ) ;
V_54 -> V_72 . V_96 = V_97 ;
V_54 -> V_72 . V_67 = V_54 ;
V_84 = F_79 ( & V_54 -> V_72 ) ;
if ( V_84 )
goto V_98;
V_54 -> V_41 = F_80 ( & V_54 -> V_72 ) ;
if ( F_81 ( V_54 -> V_41 ) ) {
V_84 = - V_79 ;
goto V_99;
}
} else if ( V_10 == V_11 ) {
V_54 -> V_41 = F_82 ( V_78 , V_85 ) ;
if ( ! V_54 -> V_41 ) {
V_84 = - V_79 ;
goto V_98;
}
F_83 ( V_54 -> V_41 , F_47 ) ;
V_84 = F_75 ( V_54 ) ;
if ( V_84 )
goto V_100;
} else {
V_54 -> V_41 = F_84 ( F_50 , & V_54 -> V_87 , V_85 ) ;
if ( ! V_54 -> V_41 ) {
V_84 = - V_79 ;
goto V_98;
}
F_85 ( V_54 -> V_41 , F_48 ) ;
F_86 ( V_54 -> V_41 , F_40 ) ;
V_84 = F_75 ( V_54 ) ;
if ( V_84 )
goto V_100;
}
V_54 -> V_41 -> V_59 = V_54 ;
F_87 ( V_101 , V_54 -> V_41 ) ;
F_88 ( V_102 , V_54 -> V_41 ) ;
V_71 = V_54 -> V_71 = F_89 ( 1 , V_85 ) ;
if ( ! V_71 ) {
V_84 = - V_79 ;
goto V_100;
}
F_90 ( & V_87 ) ;
F_91 ( & V_54 -> V_39 , & V_103 ) ;
V_54 -> V_55 = V_104 ++ ;
F_92 ( & V_87 ) ;
F_93 ( V_54 -> V_41 , V_105 ) ;
F_94 ( V_54 -> V_41 , V_105 ) ;
V_83 = V_106 * 1024 * 1024 * 1024ULL ;
F_95 ( V_71 , V_83 >> 9 ) ;
V_71 -> V_96 |= V_107 | V_108 ;
V_71 -> V_109 = V_110 ;
V_71 -> V_111 = V_54 -> V_55 ;
V_71 -> V_112 = & V_113 ;
V_71 -> V_114 = V_54 ;
V_71 -> V_115 = V_54 -> V_41 ;
sprintf ( V_71 -> V_116 , L_1 , V_54 -> V_55 ) ;
F_96 ( V_71 ) ;
return 0 ;
V_100:
F_66 ( V_54 -> V_41 ) ;
V_99:
if ( V_10 == V_12 )
F_67 ( & V_54 -> V_72 ) ;
V_98:
F_62 ( V_54 ) ;
V_90:
F_61 ( V_54 ) ;
V_86:
return V_84 ;
}
static int T_4 F_97 ( void )
{
unsigned int V_70 ;
if ( V_105 > V_117 ) {
F_98 ( L_2 ) ;
F_98 ( L_3 , V_117 ) ;
V_105 = V_117 ;
}
if ( V_10 == V_12 && V_88 ) {
if ( V_81 < V_89 ) {
F_98 ( L_4 ,
V_89 ) ;
V_81 = V_89 ;
}
} else if ( V_81 > V_57 )
V_81 = V_57 ;
else if ( ! V_81 )
V_81 = 1 ;
F_99 ( & V_87 ) ;
F_100 (i) {
struct V_34 * V_35 = & F_25 ( V_38 , V_70 ) ;
F_101 ( & V_35 -> V_39 ) ;
if ( V_13 != V_15 )
continue;
F_102 ( & V_35 -> V_33 , V_118 , V_119 ) ;
V_35 -> V_33 . V_120 = F_24 ;
}
V_110 = F_103 ( 0 , L_5 ) ;
if ( V_110 < 0 )
return V_110 ;
for ( V_70 = 0 ; V_70 < V_121 ; V_70 ++ ) {
if ( F_76 () ) {
F_104 ( V_110 , L_5 ) ;
return - V_7 ;
}
}
F_105 ( L_6 ) ;
return 0 ;
}
static void T_5 F_106 ( void )
{
struct V_54 * V_54 ;
F_104 ( V_110 , L_5 ) ;
F_90 ( & V_87 ) ;
while ( ! F_107 ( & V_103 ) ) {
V_54 = F_108 ( V_103 . V_43 , struct V_54 , V_39 ) ;
F_63 ( V_54 ) ;
}
F_92 ( & V_87 ) ;
}
