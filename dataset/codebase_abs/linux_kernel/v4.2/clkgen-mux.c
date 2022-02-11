static const char * * T_1 F_1 ( struct V_1 * V_2 ,
int * V_3 )
{
const char * * V_4 ;
int V_5 , V_6 ;
V_5 = F_2 ( V_2 ) ;
if ( F_3 ( V_5 <= 0 ) )
return F_4 ( - V_7 ) ;
V_4 = F_5 ( V_5 * sizeof( const char * ) , V_8 ) ;
if ( ! V_4 )
return F_4 ( - V_9 ) ;
for ( V_6 = 0 ; V_6 < V_5 ; V_6 ++ )
V_4 [ V_6 ] = F_6 ( V_2 , V_6 ) ;
* V_3 = V_5 ;
return V_4 ;
}
static int F_7 ( struct V_10 * V_11 )
{
T_2 V_12 = F_8 ( V_11 -> V_13 [ V_11 -> V_14 ] ) ;
T_2 V_15 = V_12 & F_9 ( V_11 -> V_16 ) ;
return ! ! V_15 ;
}
static int F_10 ( struct V_17 * V_18 )
{
struct V_10 * V_19 = F_11 ( V_18 ) ;
struct V_17 * V_20 = & V_19 -> V_11 . V_18 ;
unsigned long V_21 ;
int V_22 = 0 ;
F_12 ( V_20 , V_18 ) ;
V_22 = V_23 . V_24 ( V_20 , V_19 -> V_14 ) ;
if ( V_22 )
return V_22 ;
V_21 = V_25 + F_13 ( 10 ) ;
while ( ! F_7 ( V_19 ) ) {
if ( F_14 ( V_25 , V_21 ) )
return - V_26 ;
F_15 () ;
}
return 0 ;
}
static void F_16 ( struct V_17 * V_18 )
{
struct V_10 * V_19 = F_11 ( V_18 ) ;
struct V_17 * V_20 = & V_19 -> V_11 . V_18 ;
F_12 ( V_20 , V_18 ) ;
V_23 . V_24 ( V_20 , V_27 ) ;
}
static int F_17 ( struct V_17 * V_18 )
{
struct V_10 * V_19 = F_11 ( V_18 ) ;
struct V_17 * V_20 = & V_19 -> V_11 . V_18 ;
F_12 ( V_20 , V_18 ) ;
return ( V_28 ) V_23 . V_29 ( V_20 ) > 0 ;
}
static T_3 F_18 ( struct V_17 * V_18 )
{
struct V_10 * V_19 = F_11 ( V_18 ) ;
struct V_17 * V_20 = & V_19 -> V_11 . V_18 ;
F_12 ( V_20 , V_18 ) ;
V_19 -> V_14 = V_23 . V_29 ( V_20 ) ;
if ( ( V_28 ) V_19 -> V_14 < 0 ) {
F_19 ( L_1 ,
V_30 , F_20 ( V_18 -> V_31 ) ) ;
V_19 -> V_14 = 0 ;
}
return V_19 -> V_14 ;
}
static int F_21 ( struct V_17 * V_18 , T_3 V_32 )
{
struct V_10 * V_19 = F_11 ( V_18 ) ;
if ( V_32 >= V_27 )
return - V_7 ;
V_19 -> V_14 = V_32 ;
if ( F_17 ( V_18 ) )
F_10 ( V_18 ) ;
return 0 ;
}
static unsigned long F_22 ( struct V_17 * V_18 ,
unsigned long V_33 )
{
struct V_10 * V_19 = F_11 ( V_18 ) ;
struct V_17 * V_34 = & V_19 -> div [ V_19 -> V_14 ] . V_18 ;
F_12 ( V_34 , V_18 ) ;
return V_35 . V_36 ( V_34 , V_33 ) ;
}
static int F_23 ( struct V_17 * V_18 , unsigned long V_37 ,
unsigned long V_33 )
{
struct V_10 * V_19 = F_11 ( V_18 ) ;
struct V_17 * V_34 = & V_19 -> div [ V_19 -> V_14 ] . V_18 ;
F_12 ( V_34 , V_18 ) ;
return V_35 . V_38 ( V_34 , V_37 , V_33 ) ;
}
static long F_24 ( struct V_17 * V_18 , unsigned long V_37 ,
unsigned long * V_39 )
{
struct V_10 * V_19 = F_11 ( V_18 ) ;
struct V_17 * V_34 = & V_19 -> div [ V_19 -> V_14 ] . V_18 ;
F_12 ( V_34 , V_18 ) ;
return V_35 . V_40 ( V_34 , V_37 , V_39 ) ;
}
static struct V_31 * F_25 ( const char * V_41 ,
const char * * V_42 , T_3 V_3 ,
void T_4 * V_43 ,
const struct V_44 * V_45 ,
T_2 V_46 )
{
const int V_47 = 2 ;
const int V_48 = 5 ;
struct V_10 * V_19 ;
struct V_31 * V_31 ;
struct V_49 V_50 ;
int V_6 ;
V_19 = F_5 ( sizeof( * V_19 ) , V_8 ) ;
if ( ! V_19 )
return F_4 ( - V_9 ) ;
V_50 . V_41 = V_41 ;
V_50 . V_51 = & V_52 ;
V_50 . V_53 = V_54 | V_55 ;
V_50 . V_42 = V_42 ;
V_50 . V_3 = V_3 ;
V_19 -> V_11 . V_56 = & V_57 ;
V_19 -> V_11 . V_58 = F_9 ( V_47 ) - 1 ;
V_19 -> V_11 . V_59 = V_45 -> V_60 + ( V_46 * V_47 ) ;
if ( V_19 -> V_11 . V_59 > 31 ) {
V_19 -> V_11 . V_43 = V_43 + V_45 -> V_61 ;
V_19 -> V_11 . V_59 -= 32 ;
} else {
V_19 -> V_11 . V_43 = V_43 + V_45 -> V_62 ;
}
for ( V_6 = 0 ; V_6 < V_63 ; V_6 ++ ) {
void T_4 * V_64 = V_43 + V_45 -> V_65 [ V_6 ] ;
V_19 -> div [ V_6 ] . V_66 = V_48 ;
V_19 -> div [ V_6 ] . V_43 = V_64 + ( V_46 * sizeof( T_2 ) ) ;
V_19 -> V_13 [ V_6 ] = V_43 + V_45 -> V_67 [ V_6 ] ;
}
V_19 -> V_16 = V_45 -> V_68 + V_46 ;
V_19 -> V_18 . V_50 = & V_50 ;
V_31 = F_26 ( NULL , & V_19 -> V_18 ) ;
if ( F_27 ( V_31 ) ) {
F_28 ( V_19 ) ;
goto V_69;
}
F_19 ( L_2 ,
F_20 ( V_31 ) ,
F_20 ( F_29 ( V_31 ) ) ,
F_30 ( V_31 ) ) ;
V_69:
return V_31 ;
}
static void T_4 * T_1 F_31 (
struct V_1 * V_2 )
{
struct V_1 * V_70 ;
void T_4 * V_43 = NULL ;
V_70 = F_32 ( V_2 ) ;
if ( ! V_70 )
return NULL ;
V_43 = F_33 ( V_70 , 0 ) ;
F_34 ( V_70 ) ;
return V_43 ;
}
static void T_1 F_35 ( struct V_1 * V_2 )
{
const struct V_71 * V_72 ;
const struct V_44 * V_73 ;
struct V_74 * V_75 ;
void T_4 * V_43 ;
const char * * V_4 ;
int V_3 = 0 , V_6 ;
V_72 = F_36 ( V_76 , V_2 ) ;
if ( F_3 ( ! V_72 ) )
return;
V_73 = (struct V_44 * ) V_72 -> V_73 ;
V_43 = F_31 ( V_2 ) ;
if ( ! V_43 )
return;
V_4 = F_1 ( V_2 , & V_3 ) ;
if ( F_27 ( V_4 ) )
return;
V_75 = F_5 ( sizeof( * V_75 ) , V_8 ) ;
if ( ! V_75 )
goto V_69;
V_75 -> V_77 = V_73 -> V_78 ;
V_75 -> V_79 = F_5 ( V_75 -> V_77 * sizeof( struct V_31 * ) ,
V_8 ) ;
if ( ! V_75 -> V_79 )
goto V_69;
for ( V_6 = 0 ; V_6 < V_75 -> V_77 ; V_6 ++ ) {
struct V_31 * V_31 ;
const char * V_80 ;
if ( F_37 ( V_2 , L_3 ,
V_6 , & V_80 ) )
break;
if ( * V_80 == '\0' )
continue;
V_31 = F_25 ( V_80 , V_4 , V_3 ,
V_43 , V_73 , V_6 ) ;
if ( F_27 ( V_31 ) )
goto V_69;
V_75 -> V_79 [ V_6 ] = V_31 ;
}
F_28 ( V_4 ) ;
F_38 ( V_2 , V_81 , V_75 ) ;
return;
V_69:
if ( V_75 )
F_28 ( V_75 -> V_79 ) ;
F_28 ( V_75 ) ;
F_28 ( V_4 ) ;
}
static void T_1 F_39 ( struct V_1 * V_2 )
{
const struct V_71 * V_72 ;
void T_4 * V_43 ;
const char * V_82 , * V_80 ;
struct V_31 * V_31 ;
struct V_83 * V_73 ;
V_72 = F_36 ( V_84 , V_2 ) ;
if ( ! V_72 ) {
F_40 ( L_4 , V_30 ) ;
return;
}
V_73 = (struct V_83 * ) V_72 -> V_73 ;
V_43 = F_31 ( V_2 ) ;
if ( ! V_43 )
return;
V_82 = F_6 ( V_2 , 0 ) ;
if ( ! V_82 )
return;
if ( F_37 ( V_2 , L_3 ,
0 , & V_80 ) )
return;
V_31 = F_41 ( NULL , V_80 , V_82 ,
V_55 ,
V_43 + V_73 -> V_85 , V_73 -> V_59 , 1 ,
0 , V_73 -> V_86 , NULL ) ;
if ( F_27 ( V_31 ) )
return;
F_38 ( V_2 , V_87 , V_31 ) ;
F_19 ( L_5 ,
F_20 ( V_31 ) ,
F_20 ( F_29 ( V_31 ) ) ,
( unsigned int ) F_30 ( V_31 ) ) ;
return;
}
static void T_1 F_42 ( struct V_1 * V_2 )
{
const struct V_71 * V_72 ;
struct V_31 * V_31 ;
void T_4 * V_43 ;
const char * * V_4 ;
int V_3 ;
struct V_88 * V_73 ;
V_72 = F_36 ( V_89 , V_2 ) ;
if ( ! V_72 ) {
F_40 ( L_4 , V_30 ) ;
return;
}
V_73 = (struct V_88 * ) V_72 -> V_73 ;
V_43 = F_33 ( V_2 , 0 ) ;
if ( ! V_43 ) {
F_40 ( L_6 , V_30 ) ;
return;
}
V_4 = F_1 ( V_2 , & V_3 ) ;
if ( F_27 ( V_4 ) ) {
F_40 ( L_7 ,
V_30 , F_43 ( V_4 ) ) ;
return;
}
V_31 = F_44 ( NULL , V_2 -> V_41 , V_4 , V_3 ,
V_73 -> V_90 | V_91 ,
V_43 + V_73 -> V_85 ,
V_73 -> V_59 , V_73 -> V_66 , V_73 -> V_92 ,
V_73 -> V_56 ) ;
if ( F_27 ( V_31 ) )
goto V_69;
F_19 ( L_5 ,
F_20 ( V_31 ) ,
F_20 ( F_29 ( V_31 ) ) ,
( unsigned int ) F_30 ( V_31 ) ) ;
F_38 ( V_2 , V_87 , V_31 ) ;
V_69:
F_28 ( V_4 ) ;
return;
}
static void T_1 F_45 ( struct V_1 * V_2 )
{
const struct V_71 * V_72 ;
void T_4 * V_43 ;
const char * * V_4 ;
int V_3 , V_6 ;
struct V_74 * V_75 ;
struct V_93 * V_73 ;
V_72 = F_36 ( V_94 , V_2 ) ;
if ( F_3 ( ! V_72 ) )
return;
V_73 = (struct V_93 * ) V_72 -> V_73 ;
V_43 = F_33 ( V_2 , 0 ) ;
if ( ! V_43 )
return;
V_4 = F_1 ( V_2 , & V_3 ) ;
if ( F_27 ( V_4 ) )
return;
V_75 = F_5 ( sizeof( * V_75 ) , V_8 ) ;
if ( ! V_75 )
goto V_69;
V_75 -> V_77 = V_95 ;
V_75 -> V_79 = F_5 ( V_75 -> V_77 * sizeof( struct V_31 * ) ,
V_8 ) ;
if ( ! V_75 -> V_79 )
goto V_69;
for ( V_6 = 0 ; V_6 < V_75 -> V_77 ; V_6 ++ ) {
struct V_31 * V_31 ;
const char * V_80 ;
struct V_96 * V_97 ;
struct V_98 * div ;
struct V_99 * V_11 ;
if ( F_37 ( V_2 , L_3 ,
V_6 , & V_80 ) )
break;
if ( * V_80 == '\0' )
continue;
V_97 = F_5 ( sizeof( struct V_96 ) , V_8 ) ;
if ( ! V_97 )
break;
div = F_5 ( sizeof( struct V_98 ) , V_8 ) ;
if ( ! div ) {
F_28 ( V_97 ) ;
break;
}
V_11 = F_5 ( sizeof( struct V_99 ) , V_8 ) ;
if ( ! V_11 ) {
F_28 ( V_97 ) ;
F_28 ( div ) ;
break;
}
V_97 -> V_43 = V_43 + V_100 ;
V_97 -> V_101 = V_6 ;
V_97 -> V_53 = V_102 ;
V_97 -> V_56 = V_73 -> V_56 ;
div -> V_43 = V_43 + V_103 ;
div -> V_59 = 2 * V_6 ;
div -> V_66 = 2 ;
div -> V_53 = V_104 |
V_105 ;
V_11 -> V_43 = V_43 + V_106 ;
V_11 -> V_59 = 2 * V_6 ;
V_11 -> V_58 = 0x3 ;
V_31 = F_46 ( NULL , V_80 , V_4 ,
V_3 ,
& V_11 -> V_18 , & V_23 ,
& div -> V_18 , & V_35 ,
& V_97 -> V_18 , & V_107 ,
V_73 -> V_90 |
V_55 ) ;
if ( F_27 ( V_31 ) ) {
F_28 ( V_97 ) ;
F_28 ( div ) ;
F_28 ( V_11 ) ;
goto V_69;
}
F_19 ( L_5 ,
F_20 ( V_31 ) ,
F_20 ( F_29 ( V_31 ) ) ,
( unsigned int ) F_30 ( V_31 ) ) ;
V_75 -> V_79 [ V_6 ] = V_31 ;
}
F_28 ( V_4 ) ;
F_38 ( V_2 , V_81 , V_75 ) ;
return;
V_69:
for ( V_6 = 0 ; V_6 < V_75 -> V_77 ; V_6 ++ ) {
struct V_108 * V_109 ;
if ( ! V_75 -> V_79 [ V_6 ] )
continue;
V_109 = F_47 ( F_48 ( V_75 -> V_79 [ V_6 ] ) ,
struct V_108 , V_18 ) ;
F_28 ( F_47 ( V_109 -> V_110 , struct V_96 , V_18 ) ) ;
F_28 ( F_47 ( V_109 -> V_111 , struct V_98 , V_18 ) ) ;
F_28 ( F_47 ( V_109 -> V_20 , struct V_99 , V_18 ) ) ;
}
if ( V_75 )
F_28 ( V_75 -> V_79 ) ;
F_28 ( V_75 ) ;
F_28 ( V_4 ) ;
}
