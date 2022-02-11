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
static int F_45 ( struct V_52 * V_53 , struct V_34 * V_14 )
{
struct V_7 * V_8 = F_33 ( V_14 ) ;
V_8 -> V_14 = V_14 ;
V_8 -> V_2 = V_53 -> V_54 ;
F_34 ( V_8 ) ;
return V_55 ;
}
static void F_46 ( struct V_40 * V_40 , struct V_1 * V_2 )
{
F_47 ( ! V_40 ) ;
F_47 ( ! V_2 ) ;
F_48 ( & V_2 -> V_5 ) ;
V_2 -> V_6 = V_40 -> V_6 ;
}
static int F_49 ( struct V_52 * V_53 , void * V_56 ,
unsigned int V_41 )
{
struct V_40 * V_40 = V_56 ;
struct V_1 * V_2 = & V_40 -> V_44 [ V_41 ] ;
V_53 -> V_54 = V_2 ;
F_46 ( V_40 , V_2 ) ;
V_40 -> V_42 ++ ;
return 0 ;
}
static void F_50 ( struct V_40 * V_40 )
{
F_51 ( & V_40 -> V_27 ) ;
F_52 ( V_40 -> V_57 ) ;
F_53 ( V_40 -> V_46 ) ;
if ( V_12 == V_13 )
F_54 ( & V_40 -> V_58 ) ;
F_55 ( V_40 -> V_57 ) ;
F_56 ( V_40 ) ;
}
static int F_57 ( struct V_59 * V_60 , T_2 V_61 )
{
return 0 ;
}
static void F_58 ( struct V_62 * V_57 , T_2 V_61 )
{
}
static int F_59 ( struct V_1 * V_2 )
{
struct V_7 * V_8 ;
int V_63 , V_64 ;
V_2 -> V_9 = F_60 ( V_2 -> V_6 * sizeof( * V_8 ) , V_65 ) ;
if ( ! V_2 -> V_9 )
return - V_66 ;
V_64 = F_61 ( V_2 -> V_6 , V_67 ) / V_67 ;
V_2 -> V_4 = F_60 ( V_64 * sizeof( unsigned long ) , V_65 ) ;
if ( ! V_2 -> V_4 ) {
F_56 ( V_2 -> V_9 ) ;
return - V_66 ;
}
for ( V_63 = 0 ; V_63 < V_2 -> V_6 ; V_63 ++ ) {
V_8 = & V_2 -> V_9 [ V_63 ] ;
F_17 ( & V_8 -> V_27 ) ;
V_8 -> V_28 . V_29 = NULL ;
V_8 -> V_3 = - 1U ;
}
return 0 ;
}
static void F_62 ( struct V_1 * V_2 )
{
F_56 ( V_2 -> V_4 ) ;
F_56 ( V_2 -> V_9 ) ;
}
static void F_63 ( struct V_40 * V_40 )
{
int V_63 ;
for ( V_63 = 0 ; V_63 < V_40 -> V_42 ; V_63 ++ )
F_62 ( & V_40 -> V_44 [ V_63 ] ) ;
F_56 ( V_40 -> V_44 ) ;
}
static int F_64 ( struct V_40 * V_40 )
{
V_40 -> V_44 = F_60 ( V_68 * sizeof( struct V_1 ) ,
V_65 ) ;
if ( ! V_40 -> V_44 )
return - V_66 ;
V_40 -> V_42 = 0 ;
V_40 -> V_6 = V_69 ;
return 0 ;
}
static int F_65 ( struct V_40 * V_40 )
{
struct V_1 * V_2 ;
int V_63 , V_70 = 0 ;
for ( V_63 = 0 ; V_63 < V_68 ; V_63 ++ ) {
V_2 = & V_40 -> V_44 [ V_63 ] ;
F_46 ( V_40 , V_2 ) ;
V_70 = F_59 ( V_2 ) ;
if ( V_70 )
goto V_71;
V_40 -> V_42 ++ ;
}
return 0 ;
V_71:
F_63 ( V_40 ) ;
return V_70 ;
}
static int F_66 ( void )
{
struct V_62 * V_57 ;
struct V_40 * V_40 ;
T_3 V_72 ;
V_40 = F_67 ( sizeof( * V_40 ) , V_65 , V_73 ) ;
if ( ! V_40 )
goto V_74;
F_68 ( & V_40 -> V_75 ) ;
if ( V_12 == V_13 && V_76 )
V_68 = V_77 ;
if ( F_64 ( V_40 ) )
goto V_78;
if ( V_12 == V_13 ) {
V_40 -> V_58 . V_79 = & V_80 ;
V_40 -> V_58 . V_81 = V_68 ;
V_40 -> V_58 . V_6 = V_69 ;
V_40 -> V_58 . V_82 = V_73 ;
V_40 -> V_58 . V_83 = sizeof( struct V_7 ) ;
V_40 -> V_58 . V_84 = V_85 ;
V_40 -> V_58 . V_54 = V_40 ;
if ( F_69 ( & V_40 -> V_58 ) )
goto V_86;
V_40 -> V_46 = F_70 ( & V_40 -> V_58 ) ;
if ( ! V_40 -> V_46 )
goto V_87;
} else if ( V_12 == V_17 ) {
V_40 -> V_46 = F_71 ( V_65 , V_73 ) ;
if ( ! V_40 -> V_46 )
goto V_86;
F_72 ( V_40 -> V_46 , F_39 ) ;
F_65 ( V_40 ) ;
} else {
V_40 -> V_46 = F_73 ( F_41 , & V_40 -> V_75 , V_73 ) ;
if ( ! V_40 -> V_46 )
goto V_86;
F_74 ( V_40 -> V_46 , F_40 ) ;
F_75 ( V_40 -> V_46 , F_32 ) ;
F_65 ( V_40 ) ;
}
V_40 -> V_46 -> V_47 = V_40 ;
F_76 ( V_88 , V_40 -> V_46 ) ;
V_57 = V_40 -> V_57 = F_77 ( 1 , V_73 ) ;
if ( ! V_57 )
goto V_89;
F_78 ( & V_75 ) ;
F_79 ( & V_40 -> V_27 , & V_90 ) ;
V_40 -> V_41 = V_91 ++ ;
F_80 ( & V_75 ) ;
F_81 ( V_40 -> V_46 , V_92 ) ;
F_82 ( V_40 -> V_46 , V_92 ) ;
V_72 = V_93 * 1024 * 1024 * 1024ULL ;
F_83 ( V_72 , V_92 ) ;
F_84 ( V_57 , V_72 ) ;
V_57 -> V_84 |= V_94 ;
V_57 -> V_95 = V_96 ;
V_57 -> V_97 = V_40 -> V_41 ;
V_57 -> V_98 = & V_99 ;
V_57 -> V_100 = V_40 ;
V_57 -> V_101 = V_40 -> V_46 ;
sprintf ( V_57 -> V_102 , L_1 , V_40 -> V_41 ) ;
F_85 ( V_57 ) ;
return 0 ;
V_89:
F_53 ( V_40 -> V_46 ) ;
V_87:
if ( V_12 == V_13 )
F_54 ( & V_40 -> V_58 ) ;
V_86:
F_63 ( V_40 ) ;
V_78:
F_56 ( V_40 ) ;
V_74:
return - V_66 ;
}
static int T_4 F_86 ( void )
{
unsigned int V_63 ;
if ( V_92 > V_103 ) {
F_87 ( L_2 ) ;
F_87 ( L_3 , V_103 ) ;
V_92 = V_103 ;
}
if ( V_12 == V_13 && V_76 ) {
if ( V_68 < V_77 ) {
F_87 ( L_4 ,
V_77 ) ;
V_68 = V_77 ;
}
} else if ( V_68 > V_43 )
V_68 = V_43 ;
else if ( ! V_68 )
V_68 = 1 ;
F_88 ( & V_75 ) ;
F_89 (i) {
struct V_22 * V_23 = & F_21 ( V_26 , V_63 ) ;
F_90 ( & V_23 -> V_27 ) ;
if ( V_36 != V_39 )
continue;
F_91 ( & V_23 -> V_21 , V_104 , V_33 ) ;
V_23 -> V_21 . V_105 = F_20 ;
}
V_96 = F_92 ( 0 , L_5 ) ;
if ( V_96 < 0 )
return V_96 ;
for ( V_63 = 0 ; V_63 < V_106 ; V_63 ++ ) {
if ( F_66 () ) {
F_93 ( V_96 , L_5 ) ;
return - V_107 ;
}
}
F_94 ( L_6 ) ;
return 0 ;
}
static void T_5 F_95 ( void )
{
struct V_40 * V_40 ;
F_93 ( V_96 , L_5 ) ;
F_78 ( & V_75 ) ;
while ( ! F_96 ( & V_90 ) ) {
V_40 = F_97 ( V_90 . V_29 , struct V_40 , V_27 ) ;
F_50 ( V_40 ) ;
}
F_80 ( & V_75 ) ;
}
