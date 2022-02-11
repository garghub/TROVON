static const char * * T_1 F_1 ( struct V_1 * V_2 ,
int * V_3 )
{
const char * * V_4 ;
unsigned int V_5 ;
V_5 = F_2 ( V_2 ) ;
if ( F_3 ( ! V_5 ) )
return F_4 ( - V_6 ) ;
V_4 = F_5 ( V_5 , sizeof( const char * ) , V_7 ) ;
if ( ! V_4 )
return F_4 ( - V_8 ) ;
* V_3 = F_6 ( V_2 , V_4 , V_5 ) ;
return V_4 ;
}
static int F_7 ( struct V_9 * V_10 )
{
T_2 V_11 = F_8 ( V_10 -> V_12 [ V_10 -> V_13 ] ) ;
T_2 V_14 = V_11 & F_9 ( V_10 -> V_15 ) ;
return ! ! V_14 ;
}
static int F_10 ( struct V_16 * V_17 )
{
struct V_9 * V_18 = F_11 ( V_17 ) ;
struct V_16 * V_19 = & V_18 -> V_10 . V_17 ;
unsigned long V_20 ;
int V_21 = 0 ;
F_12 ( V_19 , V_17 ) ;
V_21 = V_22 . V_23 ( V_19 , V_18 -> V_13 ) ;
if ( V_21 )
return V_21 ;
V_20 = V_24 + F_13 ( 10 ) ;
while ( ! F_7 ( V_18 ) ) {
if ( F_14 ( V_24 , V_20 ) )
return - V_25 ;
F_15 () ;
}
return 0 ;
}
static void F_16 ( struct V_16 * V_17 )
{
struct V_9 * V_18 = F_11 ( V_17 ) ;
struct V_16 * V_19 = & V_18 -> V_10 . V_17 ;
F_12 ( V_19 , V_17 ) ;
V_22 . V_23 ( V_19 , V_26 ) ;
}
static int F_17 ( struct V_16 * V_17 )
{
struct V_9 * V_18 = F_11 ( V_17 ) ;
struct V_16 * V_19 = & V_18 -> V_10 . V_17 ;
F_12 ( V_19 , V_17 ) ;
return ( V_27 ) V_22 . V_28 ( V_19 ) > 0 ;
}
static T_3 F_18 ( struct V_16 * V_17 )
{
struct V_9 * V_18 = F_11 ( V_17 ) ;
struct V_16 * V_19 = & V_18 -> V_10 . V_17 ;
F_12 ( V_19 , V_17 ) ;
V_18 -> V_13 = V_22 . V_28 ( V_19 ) ;
if ( ( V_27 ) V_18 -> V_13 < 0 ) {
F_19 ( L_1 ,
V_29 , F_20 ( V_17 ) ) ;
V_18 -> V_13 = 0 ;
}
return V_18 -> V_13 ;
}
static int F_21 ( struct V_16 * V_17 , T_3 V_30 )
{
struct V_9 * V_18 = F_11 ( V_17 ) ;
if ( V_30 >= V_26 )
return - V_6 ;
V_18 -> V_13 = V_30 ;
if ( F_17 ( V_17 ) )
F_10 ( V_17 ) ;
return 0 ;
}
static unsigned long F_22 ( struct V_16 * V_17 ,
unsigned long V_31 )
{
struct V_9 * V_18 = F_11 ( V_17 ) ;
struct V_16 * V_32 = & V_18 -> div [ V_18 -> V_13 ] . V_17 ;
F_12 ( V_32 , V_17 ) ;
return V_33 . V_34 ( V_32 , V_31 ) ;
}
static int F_23 ( struct V_16 * V_17 , unsigned long V_35 ,
unsigned long V_31 )
{
struct V_9 * V_18 = F_11 ( V_17 ) ;
struct V_16 * V_32 = & V_18 -> div [ V_18 -> V_13 ] . V_17 ;
F_12 ( V_32 , V_17 ) ;
return V_33 . V_36 ( V_32 , V_35 , V_31 ) ;
}
static long F_24 ( struct V_16 * V_17 , unsigned long V_35 ,
unsigned long * V_37 )
{
struct V_9 * V_18 = F_11 ( V_17 ) ;
struct V_16 * V_32 = & V_18 -> div [ V_18 -> V_13 ] . V_17 ;
F_12 ( V_32 , V_17 ) ;
return V_33 . V_38 ( V_32 , V_35 , V_37 ) ;
}
static struct V_39 * T_1 F_25 ( const char * V_40 ,
const char * * V_41 , T_3 V_3 ,
void T_4 * V_42 ,
const struct V_43 * V_44 ,
T_2 V_45 )
{
const int V_46 = 2 ;
const int V_47 = 5 ;
struct V_9 * V_18 ;
struct V_39 * V_39 ;
struct V_48 V_49 ;
int V_50 ;
V_18 = F_26 ( sizeof( * V_18 ) , V_7 ) ;
if ( ! V_18 )
return F_4 ( - V_8 ) ;
V_49 . V_40 = V_40 ;
V_49 . V_51 = & V_52 ;
V_49 . V_53 = V_54 | V_55 ;
V_49 . V_41 = V_41 ;
V_49 . V_3 = V_3 ;
V_18 -> V_10 . V_56 = & V_57 ;
V_18 -> V_10 . V_58 = F_9 ( V_46 ) - 1 ;
V_18 -> V_10 . V_59 = V_44 -> V_60 + ( V_45 * V_46 ) ;
if ( V_18 -> V_10 . V_59 > 31 ) {
V_18 -> V_10 . V_42 = V_42 + V_44 -> V_61 ;
V_18 -> V_10 . V_59 -= 32 ;
} else {
V_18 -> V_10 . V_42 = V_42 + V_44 -> V_62 ;
}
for ( V_50 = 0 ; V_50 < V_63 ; V_50 ++ ) {
void T_4 * V_64 = V_42 + V_44 -> V_65 [ V_50 ] ;
V_18 -> div [ V_50 ] . V_66 = V_47 ;
V_18 -> div [ V_50 ] . V_42 = V_64 + ( V_45 * sizeof( T_2 ) ) ;
V_18 -> V_12 [ V_50 ] = V_42 + V_44 -> V_67 [ V_50 ] ;
}
V_18 -> V_15 = V_44 -> V_68 + V_45 ;
V_18 -> V_17 . V_49 = & V_49 ;
V_39 = F_27 ( NULL , & V_18 -> V_17 ) ;
if ( F_28 ( V_39 ) ) {
F_29 ( V_18 ) ;
goto V_69;
}
F_19 ( L_2 ,
F_30 ( V_39 ) ,
F_30 ( F_31 ( V_39 ) ) ,
F_32 ( V_39 ) ) ;
V_69:
return V_39 ;
}
static void T_4 * T_1 F_33 ( struct V_1 * V_2 )
{
struct V_1 * V_70 ;
void T_4 * V_42 ;
V_70 = F_34 ( V_2 ) ;
if ( ! V_70 )
return NULL ;
V_42 = F_35 ( V_70 , 0 ) ;
F_36 ( V_70 ) ;
return V_42 ;
}
static void T_1 F_37 ( struct V_1 * V_2 )
{
const struct V_71 * V_72 ;
const struct V_43 * V_73 ;
struct V_74 * V_75 ;
void T_4 * V_42 ;
const char * * V_4 ;
int V_3 = 0 , V_50 ;
V_72 = F_38 ( V_76 , V_2 ) ;
if ( F_3 ( ! V_72 ) )
return;
V_73 = V_72 -> V_73 ;
V_42 = F_33 ( V_2 ) ;
if ( ! V_42 )
return;
V_4 = F_1 ( V_2 , & V_3 ) ;
if ( F_28 ( V_4 ) )
goto V_77;
V_75 = F_26 ( sizeof( * V_75 ) , V_7 ) ;
if ( ! V_75 )
goto V_78;
V_75 -> V_79 = V_73 -> V_80 ;
V_75 -> V_81 = F_5 ( V_75 -> V_79 , sizeof( struct V_39 * ) ,
V_7 ) ;
if ( ! V_75 -> V_81 )
goto V_82;
for ( V_50 = 0 ; V_50 < V_75 -> V_79 ; V_50 ++ ) {
struct V_39 * V_39 ;
const char * V_83 ;
if ( F_39 ( V_2 , L_3 ,
V_50 , & V_83 ) )
break;
if ( * V_83 == '\0' )
continue;
V_39 = F_25 ( V_83 , V_4 , V_3 ,
V_42 , V_73 , V_50 ) ;
if ( F_28 ( V_39 ) )
goto V_69;
V_75 -> V_81 [ V_50 ] = V_39 ;
}
F_29 ( V_4 ) ;
F_40 ( V_2 , V_84 , V_75 ) ;
return;
V_69:
F_29 ( V_75 -> V_81 ) ;
V_82:
F_29 ( V_75 ) ;
V_78:
F_29 ( V_4 ) ;
V_77:
F_41 ( V_42 ) ;
}
static void T_1 F_42 ( struct V_1 * V_2 )
{
const struct V_71 * V_72 ;
void T_4 * V_42 ;
const char * V_85 , * V_83 ;
struct V_39 * V_39 ;
const struct V_86 * V_73 ;
V_72 = F_38 ( V_87 , V_2 ) ;
if ( ! V_72 ) {
F_43 ( L_4 , V_29 ) ;
return;
}
V_73 = V_72 -> V_73 ;
V_42 = F_33 ( V_2 ) ;
if ( ! V_42 )
return;
V_85 = F_44 ( V_2 , 0 ) ;
if ( ! V_85 )
goto V_69;
if ( F_39 ( V_2 , L_3 ,
0 , & V_83 ) )
goto V_69;
V_39 = F_45 ( NULL , V_83 , V_85 ,
V_55 ,
V_42 + V_73 -> V_88 , V_73 -> V_59 , 1 ,
0 , V_73 -> V_89 , NULL ) ;
if ( F_28 ( V_39 ) )
goto V_69;
F_40 ( V_2 , V_90 , V_39 ) ;
F_19 ( L_5 ,
F_30 ( V_39 ) ,
F_30 ( F_31 ( V_39 ) ) ,
( unsigned int ) F_32 ( V_39 ) ) ;
return;
V_69:
F_41 ( V_42 ) ;
}
static void T_1 F_46 ( struct V_1 * V_2 )
{
const struct V_71 * V_72 ;
struct V_39 * V_39 ;
void T_4 * V_42 ;
const char * * V_4 ;
int V_3 ;
const struct V_91 * V_73 ;
V_72 = F_38 ( V_92 , V_2 ) ;
if ( ! V_72 ) {
F_43 ( L_4 , V_29 ) ;
return;
}
V_73 = V_72 -> V_73 ;
V_42 = F_35 ( V_2 , 0 ) ;
if ( ! V_42 ) {
F_43 ( L_6 , V_29 ) ;
return;
}
V_4 = F_1 ( V_2 , & V_3 ) ;
if ( F_28 ( V_4 ) ) {
F_43 ( L_7 ,
V_29 , F_47 ( V_4 ) ) ;
goto V_77;
}
V_39 = F_48 ( NULL , V_2 -> V_40 , V_4 , V_3 ,
V_73 -> V_93 | V_94 ,
V_42 + V_73 -> V_88 ,
V_73 -> V_59 , V_73 -> V_66 , V_73 -> V_95 ,
V_73 -> V_56 ) ;
if ( F_28 ( V_39 ) )
goto V_69;
F_19 ( L_5 ,
F_30 ( V_39 ) ,
F_30 ( F_31 ( V_39 ) ) ,
( unsigned int ) F_32 ( V_39 ) ) ;
F_29 ( V_4 ) ;
F_40 ( V_2 , V_90 , V_39 ) ;
return;
V_69:
F_29 ( V_4 ) ;
V_77:
F_41 ( V_42 ) ;
}
static void T_1 F_49 ( struct V_1 * V_2 )
{
const struct V_71 * V_72 ;
void T_4 * V_42 ;
const char * * V_4 ;
int V_3 , V_50 ;
struct V_74 * V_75 ;
const struct V_96 * V_73 ;
V_72 = F_38 ( V_97 , V_2 ) ;
if ( F_3 ( ! V_72 ) )
return;
V_73 = V_72 -> V_73 ;
V_42 = F_35 ( V_2 , 0 ) ;
if ( ! V_42 )
return;
V_4 = F_1 ( V_2 , & V_3 ) ;
if ( F_28 ( V_4 ) )
goto V_77;
V_75 = F_26 ( sizeof( * V_75 ) , V_7 ) ;
if ( ! V_75 )
goto V_78;
V_75 -> V_79 = V_98 ;
V_75 -> V_81 = F_5 ( V_75 -> V_79 , sizeof( struct V_39 * ) ,
V_7 ) ;
if ( ! V_75 -> V_81 )
goto V_82;
for ( V_50 = 0 ; V_50 < V_75 -> V_79 ; V_50 ++ ) {
struct V_39 * V_39 ;
const char * V_83 ;
struct V_99 * V_100 ;
struct V_101 * div ;
struct V_102 * V_10 ;
if ( F_39 ( V_2 , L_3 ,
V_50 , & V_83 ) )
break;
if ( * V_83 == '\0' )
continue;
V_100 = F_26 ( sizeof( * V_100 ) , V_7 ) ;
if ( ! V_100 )
goto V_69;
div = F_26 ( sizeof( * div ) , V_7 ) ;
if ( ! div ) {
F_29 ( V_100 ) ;
goto V_69;
}
V_10 = F_26 ( sizeof( * V_10 ) , V_7 ) ;
if ( ! V_10 ) {
F_29 ( V_100 ) ;
F_29 ( div ) ;
goto V_69;
}
V_100 -> V_42 = V_42 + V_103 ;
V_100 -> V_104 = V_50 ;
V_100 -> V_53 = V_105 ;
V_100 -> V_56 = V_73 -> V_56 ;
div -> V_42 = V_42 + V_106 ;
div -> V_59 = 2 * V_50 ;
div -> V_66 = 2 ;
div -> V_53 = V_107 |
V_108 ;
V_10 -> V_42 = V_42 + V_109 ;
V_10 -> V_59 = 2 * V_50 ;
V_10 -> V_58 = 0x3 ;
V_39 = F_50 ( NULL , V_83 , V_4 ,
V_3 ,
& V_10 -> V_17 , & V_22 ,
& div -> V_17 , & V_33 ,
& V_100 -> V_17 , & V_110 ,
V_73 -> V_93 |
V_55 ) ;
if ( F_28 ( V_39 ) ) {
F_29 ( V_100 ) ;
F_29 ( div ) ;
F_29 ( V_10 ) ;
goto V_69;
}
F_19 ( L_5 ,
F_30 ( V_39 ) ,
F_30 ( F_31 ( V_39 ) ) ,
( unsigned int ) F_32 ( V_39 ) ) ;
V_75 -> V_81 [ V_50 ] = V_39 ;
}
F_29 ( V_4 ) ;
F_40 ( V_2 , V_84 , V_75 ) ;
return;
V_69:
for ( V_50 = 0 ; V_50 < V_75 -> V_79 ; V_50 ++ ) {
struct V_111 * V_112 ;
if ( ! V_75 -> V_81 [ V_50 ] )
continue;
V_112 = F_51 ( F_52 ( V_75 -> V_81 [ V_50 ] ) ) ;
F_29 ( F_53 ( V_112 -> V_113 ) ) ;
F_29 ( F_54 ( V_112 -> V_114 ) ) ;
F_29 ( F_55 ( V_112 -> V_19 ) ) ;
}
F_29 ( V_75 -> V_81 ) ;
V_82:
F_29 ( V_75 ) ;
V_78:
F_29 ( V_4 ) ;
V_77:
F_41 ( V_42 ) ;
}
