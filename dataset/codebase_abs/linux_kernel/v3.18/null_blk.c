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
V_25 = V_25 -> V_29 ;
F_15 ( V_8 ) ;
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
if ( V_12 == V_13 )
F_15 ( F_33 ( V_14 ) ) ;
else
F_15 ( V_14 -> V_35 ) ;
}
static inline void F_34 ( struct V_7 * V_8 )
{
switch ( V_36 ) {
case V_37 :
switch ( V_12 ) {
case V_13 :
F_35 ( V_8 -> V_14 ) ;
break;
case V_15 :
F_36 ( V_8 -> V_14 ) ;
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
static struct V_1 * F_37 ( struct V_40 * V_40 )
{
int V_41 = 0 ;
if ( V_40 -> V_42 != 1 )
V_41 = F_38 () / ( ( V_43 + V_40 -> V_42 - 1 ) / V_40 -> V_42 ) ;
return & V_40 -> V_44 [ V_41 ] ;
}
static void F_39 ( struct V_45 * V_46 , struct V_18 * V_18 )
{
struct V_40 * V_40 = V_46 -> V_47 ;
struct V_1 * V_2 = F_37 ( V_40 ) ;
struct V_7 * V_8 ;
V_8 = F_10 ( V_2 , 1 ) ;
V_8 -> V_18 = V_18 ;
F_34 ( V_8 ) ;
}
static int F_40 ( struct V_45 * V_46 , struct V_34 * V_48 )
{
struct V_40 * V_40 = V_46 -> V_47 ;
struct V_1 * V_2 = F_37 ( V_40 ) ;
struct V_7 * V_8 ;
V_8 = F_10 ( V_2 , 0 ) ;
if ( V_8 ) {
V_8 -> V_14 = V_48 ;
V_48 -> V_35 = V_8 ;
return V_49 ;
}
return V_50 ;
}
static void F_41 ( struct V_45 * V_46 )
{
struct V_34 * V_14 ;
while ( ( V_14 = F_42 ( V_46 ) ) != NULL ) {
struct V_7 * V_8 = V_14 -> V_35 ;
F_43 ( V_46 -> V_51 ) ;
F_34 ( V_8 ) ;
F_44 ( V_46 -> V_51 ) ;
}
}
static int F_45 ( struct V_52 * V_53 , struct V_34 * V_14 ,
bool V_54 )
{
struct V_7 * V_8 = F_33 ( V_14 ) ;
V_8 -> V_14 = V_14 ;
V_8 -> V_2 = V_53 -> V_55 ;
F_46 ( V_14 ) ;
F_34 ( V_8 ) ;
return V_56 ;
}
static void F_47 ( struct V_40 * V_40 , struct V_1 * V_2 )
{
F_48 ( ! V_40 ) ;
F_48 ( ! V_2 ) ;
F_49 ( & V_2 -> V_5 ) ;
V_2 -> V_6 = V_40 -> V_6 ;
}
static int F_50 ( struct V_52 * V_53 , void * V_57 ,
unsigned int V_41 )
{
struct V_40 * V_40 = V_57 ;
struct V_1 * V_2 = & V_40 -> V_44 [ V_41 ] ;
V_53 -> V_55 = V_2 ;
F_47 ( V_40 , V_2 ) ;
V_40 -> V_42 ++ ;
return 0 ;
}
static void F_51 ( struct V_40 * V_40 )
{
F_52 ( & V_40 -> V_27 ) ;
F_53 ( V_40 -> V_58 ) ;
F_54 ( V_40 -> V_46 ) ;
if ( V_12 == V_13 )
F_55 ( & V_40 -> V_59 ) ;
F_56 ( V_40 -> V_58 ) ;
F_57 ( V_40 ) ;
}
static int F_58 ( struct V_60 * V_61 , T_2 V_62 )
{
return 0 ;
}
static void F_59 ( struct V_63 * V_58 , T_2 V_62 )
{
}
static int F_60 ( struct V_1 * V_2 )
{
struct V_7 * V_8 ;
int V_64 , V_65 ;
V_2 -> V_9 = F_61 ( V_2 -> V_6 * sizeof( * V_8 ) , V_66 ) ;
if ( ! V_2 -> V_9 )
return - V_67 ;
V_65 = F_62 ( V_2 -> V_6 , V_68 ) / V_68 ;
V_2 -> V_4 = F_61 ( V_65 * sizeof( unsigned long ) , V_66 ) ;
if ( ! V_2 -> V_4 ) {
F_57 ( V_2 -> V_9 ) ;
return - V_67 ;
}
for ( V_64 = 0 ; V_64 < V_2 -> V_6 ; V_64 ++ ) {
V_8 = & V_2 -> V_9 [ V_64 ] ;
F_17 ( & V_8 -> V_27 ) ;
V_8 -> V_28 . V_29 = NULL ;
V_8 -> V_3 = - 1U ;
}
return 0 ;
}
static void F_63 ( struct V_1 * V_2 )
{
F_57 ( V_2 -> V_4 ) ;
F_57 ( V_2 -> V_9 ) ;
}
static void F_64 ( struct V_40 * V_40 )
{
int V_64 ;
for ( V_64 = 0 ; V_64 < V_40 -> V_42 ; V_64 ++ )
F_63 ( & V_40 -> V_44 [ V_64 ] ) ;
F_57 ( V_40 -> V_44 ) ;
}
static int F_65 ( struct V_40 * V_40 )
{
V_40 -> V_44 = F_61 ( V_69 * sizeof( struct V_1 ) ,
V_66 ) ;
if ( ! V_40 -> V_44 )
return - V_67 ;
V_40 -> V_42 = 0 ;
V_40 -> V_6 = V_70 ;
return 0 ;
}
static int F_66 ( struct V_40 * V_40 )
{
struct V_1 * V_2 ;
int V_64 , V_71 = 0 ;
for ( V_64 = 0 ; V_64 < V_69 ; V_64 ++ ) {
V_2 = & V_40 -> V_44 [ V_64 ] ;
F_47 ( V_40 , V_2 ) ;
V_71 = F_60 ( V_2 ) ;
if ( V_71 )
return V_71 ;
V_40 -> V_42 ++ ;
}
return 0 ;
}
static int F_67 ( void )
{
struct V_63 * V_58 ;
struct V_40 * V_40 ;
T_3 V_72 ;
int V_73 ;
V_40 = F_68 ( sizeof( * V_40 ) , V_66 , V_74 ) ;
if ( ! V_40 ) {
V_73 = - V_67 ;
goto V_75;
}
F_69 ( & V_40 -> V_76 ) ;
if ( V_12 == V_13 && V_77 )
V_69 = V_78 ;
V_73 = F_65 ( V_40 ) ;
if ( V_73 )
goto V_79;
if ( V_12 == V_13 ) {
V_40 -> V_59 . V_80 = & V_81 ;
V_40 -> V_59 . V_82 = V_69 ;
V_40 -> V_59 . V_6 = V_70 ;
V_40 -> V_59 . V_83 = V_74 ;
V_40 -> V_59 . V_84 = sizeof( struct V_7 ) ;
V_40 -> V_59 . V_85 = V_86 ;
V_40 -> V_59 . V_55 = V_40 ;
V_73 = F_70 ( & V_40 -> V_59 ) ;
if ( V_73 )
goto V_87;
V_40 -> V_46 = F_71 ( & V_40 -> V_59 ) ;
if ( ! V_40 -> V_46 ) {
V_73 = - V_67 ;
goto V_88;
}
} else if ( V_12 == V_17 ) {
V_40 -> V_46 = F_72 ( V_66 , V_74 ) ;
if ( ! V_40 -> V_46 ) {
V_73 = - V_67 ;
goto V_87;
}
F_73 ( V_40 -> V_46 , F_39 ) ;
V_73 = F_66 ( V_40 ) ;
if ( V_73 )
goto V_89;
} else {
V_40 -> V_46 = F_74 ( F_41 , & V_40 -> V_76 , V_74 ) ;
if ( ! V_40 -> V_46 ) {
V_73 = - V_67 ;
goto V_87;
}
F_75 ( V_40 -> V_46 , F_40 ) ;
F_76 ( V_40 -> V_46 , F_32 ) ;
V_73 = F_66 ( V_40 ) ;
if ( V_73 )
goto V_89;
}
V_40 -> V_46 -> V_47 = V_40 ;
F_77 ( V_90 , V_40 -> V_46 ) ;
F_78 ( V_91 , V_40 -> V_46 ) ;
V_58 = V_40 -> V_58 = F_79 ( 1 , V_74 ) ;
if ( ! V_58 ) {
V_73 = - V_67 ;
goto V_89;
}
F_80 ( & V_76 ) ;
F_81 ( & V_40 -> V_27 , & V_92 ) ;
V_40 -> V_41 = V_93 ++ ;
F_82 ( & V_76 ) ;
F_83 ( V_40 -> V_46 , V_94 ) ;
F_84 ( V_40 -> V_46 , V_94 ) ;
V_72 = V_95 * 1024 * 1024 * 1024ULL ;
F_85 ( V_72 , V_94 ) ;
F_86 ( V_58 , V_72 ) ;
V_58 -> V_85 |= V_96 ;
V_58 -> V_97 = V_98 ;
V_58 -> V_99 = V_40 -> V_41 ;
V_58 -> V_100 = & V_101 ;
V_58 -> V_102 = V_40 ;
V_58 -> V_103 = V_40 -> V_46 ;
sprintf ( V_58 -> V_104 , L_1 , V_40 -> V_41 ) ;
F_87 ( V_58 ) ;
return 0 ;
V_89:
F_54 ( V_40 -> V_46 ) ;
V_88:
if ( V_12 == V_13 )
F_55 ( & V_40 -> V_59 ) ;
V_87:
F_64 ( V_40 ) ;
V_79:
F_57 ( V_40 ) ;
V_75:
return V_73 ;
}
static int T_4 F_88 ( void )
{
unsigned int V_64 ;
if ( V_94 > V_105 ) {
F_89 ( L_2 ) ;
F_89 ( L_3 , V_105 ) ;
V_94 = V_105 ;
}
if ( V_12 == V_13 && V_77 ) {
if ( V_69 < V_78 ) {
F_89 ( L_4 ,
V_78 ) ;
V_69 = V_78 ;
}
} else if ( V_69 > V_43 )
V_69 = V_43 ;
else if ( ! V_69 )
V_69 = 1 ;
F_90 ( & V_76 ) ;
F_91 (i) {
struct V_22 * V_23 = & F_21 ( V_26 , V_64 ) ;
F_92 ( & V_23 -> V_27 ) ;
if ( V_36 != V_39 )
continue;
F_93 ( & V_23 -> V_21 , V_106 , V_33 ) ;
V_23 -> V_21 . V_107 = F_20 ;
}
V_98 = F_94 ( 0 , L_5 ) ;
if ( V_98 < 0 )
return V_98 ;
for ( V_64 = 0 ; V_64 < V_108 ; V_64 ++ ) {
if ( F_67 () ) {
F_95 ( V_98 , L_5 ) ;
return - V_109 ;
}
}
F_96 ( L_6 ) ;
return 0 ;
}
static void T_5 F_97 ( void )
{
struct V_40 * V_40 ;
F_95 ( V_98 , L_5 ) ;
F_80 ( & V_76 ) ;
while ( ! F_98 ( & V_92 ) ) {
V_40 = F_99 ( V_92 . V_29 , struct V_40 , V_27 ) ;
F_51 ( V_40 ) ;
}
F_82 ( & V_76 ) ;
}
