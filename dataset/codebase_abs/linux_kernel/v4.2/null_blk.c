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
F_43 ( V_23 -> V_27 ) ;
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
static struct V_16 * F_45 ( struct V_53 * V_53 )
{
int V_54 = 0 ;
if ( V_53 -> V_55 != 1 )
V_54 = F_46 () / ( ( V_56 + V_53 -> V_55 - 1 ) / V_53 -> V_55 ) ;
return & V_53 -> V_57 [ V_54 ] ;
}
static void F_47 ( struct V_40 * V_41 , struct V_30 * V_30 )
{
struct V_53 * V_53 = V_41 -> V_58 ;
struct V_16 * V_17 = F_45 ( V_53 ) ;
struct V_22 * V_23 ;
V_23 = F_14 ( V_17 , 1 ) ;
V_23 -> V_30 = V_30 ;
F_42 ( V_23 ) ;
}
static int F_48 ( struct V_40 * V_41 , struct V_50 * V_59 )
{
struct V_53 * V_53 = V_41 -> V_58 ;
struct V_16 * V_17 = F_45 ( V_53 ) ;
struct V_22 * V_23 ;
V_23 = F_14 ( V_17 , 0 ) ;
if ( V_23 ) {
V_23 -> V_27 = V_59 ;
V_59 -> V_51 = V_23 ;
return V_60 ;
}
F_49 ( V_41 ) ;
return V_61 ;
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
static int F_54 ( struct V_62 * V_63 ,
const struct V_64 * V_65 )
{
struct V_22 * V_23 = F_41 ( V_65 -> V_27 ) ;
V_23 -> V_27 = V_65 -> V_27 ;
V_23 -> V_17 = V_63 -> V_66 ;
F_55 ( V_65 -> V_27 ) ;
F_42 ( V_23 ) ;
return V_67 ;
}
static void F_56 ( struct V_53 * V_53 , struct V_16 * V_17 )
{
F_57 ( ! V_53 ) ;
F_57 ( ! V_17 ) ;
F_58 ( & V_17 -> V_20 ) ;
V_17 -> V_21 = V_53 -> V_21 ;
}
static int F_59 ( struct V_62 * V_63 , void * V_68 ,
unsigned int V_54 )
{
struct V_53 * V_53 = V_68 ;
struct V_16 * V_17 = & V_53 -> V_57 [ V_54 ] ;
V_63 -> V_66 = V_17 ;
F_56 ( V_53 , V_17 ) ;
V_53 -> V_55 ++ ;
return 0 ;
}
static void F_60 ( struct V_53 * V_53 )
{
F_61 ( & V_53 -> V_39 ) ;
F_62 ( V_53 -> V_69 ) ;
F_63 ( V_53 -> V_41 ) ;
if ( V_10 == V_12 )
F_64 ( & V_53 -> V_70 ) ;
F_65 ( V_53 -> V_69 ) ;
F_66 ( V_53 ) ;
}
static int F_67 ( struct V_71 * V_72 , T_2 V_73 )
{
return 0 ;
}
static void F_68 ( struct V_74 * V_69 , T_2 V_73 )
{
}
static int F_69 ( struct V_16 * V_17 )
{
struct V_22 * V_23 ;
int V_75 , V_76 ;
V_17 -> V_24 = F_70 ( V_17 -> V_21 * sizeof( * V_23 ) , V_77 ) ;
if ( ! V_17 -> V_24 )
return - V_78 ;
V_76 = F_71 ( V_17 -> V_21 , V_79 ) / V_79 ;
V_17 -> V_19 = F_70 ( V_76 * sizeof( unsigned long ) , V_77 ) ;
if ( ! V_17 -> V_19 ) {
F_66 ( V_17 -> V_24 ) ;
return - V_78 ;
}
for ( V_75 = 0 ; V_75 < V_17 -> V_21 ; V_75 ++ ) {
V_23 = & V_17 -> V_24 [ V_75 ] ;
F_21 ( & V_23 -> V_39 ) ;
V_23 -> V_42 . V_43 = NULL ;
V_23 -> V_18 = - 1U ;
}
return 0 ;
}
static void F_72 ( struct V_16 * V_17 )
{
F_66 ( V_17 -> V_19 ) ;
F_66 ( V_17 -> V_24 ) ;
}
static void F_73 ( struct V_53 * V_53 )
{
int V_75 ;
for ( V_75 = 0 ; V_75 < V_53 -> V_55 ; V_75 ++ )
F_72 ( & V_53 -> V_57 [ V_75 ] ) ;
F_66 ( V_53 -> V_57 ) ;
}
static int F_74 ( struct V_53 * V_53 )
{
V_53 -> V_57 = F_70 ( V_80 * sizeof( struct V_16 ) ,
V_77 ) ;
if ( ! V_53 -> V_57 )
return - V_78 ;
V_53 -> V_55 = 0 ;
V_53 -> V_21 = V_81 ;
return 0 ;
}
static int F_75 ( struct V_53 * V_53 )
{
struct V_16 * V_17 ;
int V_75 , V_5 = 0 ;
for ( V_75 = 0 ; V_75 < V_80 ; V_75 ++ ) {
V_17 = & V_53 -> V_57 [ V_75 ] ;
F_56 ( V_53 , V_17 ) ;
V_5 = F_69 ( V_17 ) ;
if ( V_5 )
return V_5 ;
V_53 -> V_55 ++ ;
}
return 0 ;
}
static int F_76 ( void )
{
struct V_74 * V_69 ;
struct V_53 * V_53 ;
T_3 V_82 ;
int V_83 ;
V_53 = F_77 ( sizeof( * V_53 ) , V_77 , V_84 ) ;
if ( ! V_53 ) {
V_83 = - V_78 ;
goto V_85;
}
F_78 ( & V_53 -> V_86 ) ;
if ( V_10 == V_12 && V_87 )
V_80 = V_88 ;
V_83 = F_74 ( V_53 ) ;
if ( V_83 )
goto V_89;
if ( V_10 == V_12 ) {
V_53 -> V_70 . V_90 = & V_91 ;
V_53 -> V_70 . V_92 = V_80 ;
V_53 -> V_70 . V_21 = V_81 ;
V_53 -> V_70 . V_93 = V_84 ;
V_53 -> V_70 . V_94 = sizeof( struct V_22 ) ;
V_53 -> V_70 . V_95 = V_96 ;
V_53 -> V_70 . V_66 = V_53 ;
V_83 = F_79 ( & V_53 -> V_70 ) ;
if ( V_83 )
goto V_97;
V_53 -> V_41 = F_80 ( & V_53 -> V_70 ) ;
if ( F_81 ( V_53 -> V_41 ) ) {
V_83 = - V_78 ;
goto V_98;
}
} else if ( V_10 == V_11 ) {
V_53 -> V_41 = F_82 ( V_77 , V_84 ) ;
if ( ! V_53 -> V_41 ) {
V_83 = - V_78 ;
goto V_97;
}
F_83 ( V_53 -> V_41 , F_47 ) ;
V_83 = F_75 ( V_53 ) ;
if ( V_83 )
goto V_99;
} else {
V_53 -> V_41 = F_84 ( F_50 , & V_53 -> V_86 , V_84 ) ;
if ( ! V_53 -> V_41 ) {
V_83 = - V_78 ;
goto V_97;
}
F_85 ( V_53 -> V_41 , F_48 ) ;
F_86 ( V_53 -> V_41 , F_40 ) ;
V_83 = F_75 ( V_53 ) ;
if ( V_83 )
goto V_99;
}
V_53 -> V_41 -> V_58 = V_53 ;
F_87 ( V_100 , V_53 -> V_41 ) ;
F_88 ( V_101 , V_53 -> V_41 ) ;
V_69 = V_53 -> V_69 = F_89 ( 1 , V_84 ) ;
if ( ! V_69 ) {
V_83 = - V_78 ;
goto V_99;
}
F_90 ( & V_86 ) ;
F_91 ( & V_53 -> V_39 , & V_102 ) ;
V_53 -> V_54 = V_103 ++ ;
F_92 ( & V_86 ) ;
F_93 ( V_53 -> V_41 , V_104 ) ;
F_94 ( V_53 -> V_41 , V_104 ) ;
V_82 = V_105 * 1024 * 1024 * 1024ULL ;
F_95 ( V_82 , V_104 ) ;
F_96 ( V_69 , V_82 ) ;
V_69 -> V_95 |= V_106 | V_107 ;
V_69 -> V_108 = V_109 ;
V_69 -> V_110 = V_53 -> V_54 ;
V_69 -> V_111 = & V_112 ;
V_69 -> V_113 = V_53 ;
V_69 -> V_114 = V_53 -> V_41 ;
sprintf ( V_69 -> V_115 , L_1 , V_53 -> V_54 ) ;
F_97 ( V_69 ) ;
return 0 ;
V_99:
F_63 ( V_53 -> V_41 ) ;
V_98:
if ( V_10 == V_12 )
F_64 ( & V_53 -> V_70 ) ;
V_97:
F_73 ( V_53 ) ;
V_89:
F_66 ( V_53 ) ;
V_85:
return V_83 ;
}
static int T_4 F_98 ( void )
{
unsigned int V_75 ;
if ( V_104 > V_116 ) {
F_99 ( L_2 ) ;
F_99 ( L_3 , V_116 ) ;
V_104 = V_116 ;
}
if ( V_10 == V_12 && V_87 ) {
if ( V_80 < V_88 ) {
F_99 ( L_4 ,
V_88 ) ;
V_80 = V_88 ;
}
} else if ( V_80 > V_56 )
V_80 = V_56 ;
else if ( ! V_80 )
V_80 = 1 ;
F_100 ( & V_86 ) ;
F_101 (i) {
struct V_34 * V_35 = & F_25 ( V_38 , V_75 ) ;
F_102 ( & V_35 -> V_39 ) ;
if ( V_13 != V_15 )
continue;
F_103 ( & V_35 -> V_33 , V_117 , V_118 ) ;
V_35 -> V_33 . V_119 = F_24 ;
}
V_109 = F_104 ( 0 , L_5 ) ;
if ( V_109 < 0 )
return V_109 ;
for ( V_75 = 0 ; V_75 < V_120 ; V_75 ++ ) {
if ( F_76 () ) {
F_105 ( V_109 , L_5 ) ;
return - V_7 ;
}
}
F_106 ( L_6 ) ;
return 0 ;
}
static void T_5 F_107 ( void )
{
struct V_53 * V_53 ;
F_105 ( V_109 , L_5 ) ;
F_90 ( & V_86 ) ;
while ( ! F_108 ( & V_102 ) ) {
V_53 = F_109 ( V_102 . V_43 , struct V_53 , V_39 ) ;
F_60 ( V_53 ) ;
}
F_92 ( & V_86 ) ;
}
