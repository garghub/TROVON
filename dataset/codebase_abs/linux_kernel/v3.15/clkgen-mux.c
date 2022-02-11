static const char * * T_1 F_1 ( struct V_1 * V_2 ,
int * V_3 )
{
const char * * V_4 ;
int V_5 , V_6 ;
V_5 = F_2 ( V_2 , L_1 , L_2 ) ;
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
V_20 -> V_23 = V_18 -> V_23 ;
V_22 = V_24 . V_25 ( V_20 , V_19 -> V_14 ) ;
if ( V_22 )
return V_22 ;
V_21 = V_26 + F_12 ( 10 ) ;
while ( ! F_7 ( V_19 ) ) {
if ( F_13 ( V_26 , V_21 ) )
return - V_27 ;
F_14 () ;
}
return 0 ;
}
static void F_15 ( struct V_17 * V_18 )
{
struct V_10 * V_19 = F_11 ( V_18 ) ;
struct V_17 * V_20 = & V_19 -> V_11 . V_18 ;
V_20 -> V_23 = V_18 -> V_23 ;
V_24 . V_25 ( V_20 , V_28 ) ;
}
static int F_16 ( struct V_17 * V_18 )
{
struct V_10 * V_19 = F_11 ( V_18 ) ;
struct V_17 * V_20 = & V_19 -> V_11 . V_18 ;
V_20 -> V_23 = V_18 -> V_23 ;
return ( V_29 ) V_24 . V_30 ( V_20 ) > 0 ;
}
T_3 F_17 ( struct V_17 * V_18 )
{
struct V_10 * V_19 = F_11 ( V_18 ) ;
struct V_17 * V_20 = & V_19 -> V_11 . V_18 ;
V_20 -> V_23 = V_18 -> V_23 ;
V_19 -> V_14 = V_24 . V_30 ( V_20 ) ;
if ( ( V_29 ) V_19 -> V_14 < 0 ) {
F_18 ( L_3 ,
V_31 , F_19 ( V_18 -> V_23 ) ) ;
V_19 -> V_14 = 0 ;
}
return V_19 -> V_14 ;
}
static int F_20 ( struct V_17 * V_18 , T_3 V_32 )
{
struct V_10 * V_19 = F_11 ( V_18 ) ;
if ( V_32 >= V_28 )
return - V_7 ;
V_19 -> V_14 = V_32 ;
if ( F_16 ( V_18 ) )
F_10 ( V_18 ) ;
return 0 ;
}
unsigned long F_21 ( struct V_17 * V_18 ,
unsigned long V_33 )
{
struct V_10 * V_19 = F_11 ( V_18 ) ;
struct V_17 * V_34 = & V_19 -> div [ V_19 -> V_14 ] . V_18 ;
V_34 -> V_23 = V_18 -> V_23 ;
return V_35 . V_36 ( V_34 , V_33 ) ;
}
static int F_22 ( struct V_17 * V_18 , unsigned long V_37 ,
unsigned long V_33 )
{
struct V_10 * V_19 = F_11 ( V_18 ) ;
struct V_17 * V_34 = & V_19 -> div [ V_19 -> V_14 ] . V_18 ;
V_34 -> V_23 = V_18 -> V_23 ;
return V_35 . V_38 ( V_34 , V_37 , V_33 ) ;
}
static long F_23 ( struct V_17 * V_18 , unsigned long V_37 ,
unsigned long * V_39 )
{
struct V_10 * V_19 = F_11 ( V_18 ) ;
struct V_17 * V_34 = & V_19 -> div [ V_19 -> V_14 ] . V_18 ;
V_34 -> V_23 = V_18 -> V_23 ;
return V_35 . V_40 ( V_34 , V_37 , V_39 ) ;
}
struct V_23 * F_24 ( const char * V_41 ,
const char * * V_42 , T_3 V_3 ,
void T_4 * V_43 ,
const struct V_44 * V_45 ,
T_2 V_46 )
{
const int V_47 = 2 ;
const int V_48 = 5 ;
struct V_10 * V_19 ;
struct V_23 * V_23 ;
struct V_49 V_50 ;
int V_6 ;
V_19 = F_5 ( sizeof( * V_19 ) , V_8 ) ;
if ( ! V_19 )
return F_4 ( - V_9 ) ;
V_50 . V_41 = V_41 ;
V_50 . V_51 = & V_52 ;
V_50 . V_53 = V_54 ;
V_50 . V_42 = V_42 ;
V_50 . V_3 = V_3 ;
V_19 -> V_11 . V_55 = & V_56 ;
V_19 -> V_11 . V_57 = F_9 ( V_47 ) - 1 ;
V_19 -> V_11 . V_58 = V_45 -> V_59 + ( V_46 * V_47 ) ;
if ( V_19 -> V_11 . V_58 > 31 ) {
V_19 -> V_11 . V_43 = V_43 + V_45 -> V_60 ;
V_19 -> V_11 . V_58 -= 32 ;
} else {
V_19 -> V_11 . V_43 = V_43 + V_45 -> V_61 ;
}
for ( V_6 = 0 ; V_6 < V_62 ; V_6 ++ ) {
void T_4 * V_63 = V_43 + V_45 -> V_64 [ V_6 ] ;
V_19 -> div [ V_6 ] . V_65 = V_48 ;
V_19 -> div [ V_6 ] . V_43 = V_63 + ( V_46 * sizeof( T_2 ) ) ;
V_19 -> V_13 [ V_6 ] = V_43 + V_45 -> V_66 [ V_6 ] ;
}
V_19 -> V_16 = V_45 -> V_67 + V_46 ;
V_19 -> V_18 . V_50 = & V_50 ;
V_23 = F_25 ( NULL , & V_19 -> V_18 ) ;
if ( F_26 ( V_23 ) ) {
F_27 ( V_19 ) ;
goto V_68;
}
F_18 ( L_4 ,
F_19 ( V_23 ) ,
F_19 ( F_28 ( V_23 ) ) ,
F_29 ( V_23 ) ) ;
V_68:
return V_23 ;
}
static void T_4 * T_1 F_30 (
struct V_1 * V_2 )
{
struct V_1 * V_69 ;
void T_4 * V_43 = NULL ;
V_69 = F_31 ( V_2 ) ;
if ( ! V_69 )
return NULL ;
V_43 = F_32 ( V_69 , 0 ) ;
F_33 ( V_69 ) ;
return V_43 ;
}
void T_1 F_34 ( struct V_1 * V_2 )
{
const struct V_70 * V_71 ;
const struct V_44 * V_72 ;
struct V_73 * V_74 ;
void T_4 * V_43 ;
const char * * V_4 ;
int V_3 = 0 , V_6 ;
V_71 = F_35 ( V_75 , V_2 ) ;
if ( F_3 ( ! V_71 ) )
return;
V_72 = (struct V_44 * ) V_71 -> V_72 ;
V_43 = F_30 ( V_2 ) ;
if ( ! V_43 )
return;
V_4 = F_1 ( V_2 , & V_3 ) ;
if ( F_26 ( V_4 ) )
return;
V_74 = F_5 ( sizeof( * V_74 ) , V_8 ) ;
if ( ! V_74 )
goto V_68;
V_74 -> V_76 = V_72 -> V_77 ;
V_74 -> V_78 = F_5 ( V_74 -> V_76 * sizeof( struct V_23 * ) ,
V_8 ) ;
if ( ! V_74 -> V_78 )
goto V_68;
for ( V_6 = 0 ; V_6 < V_74 -> V_76 ; V_6 ++ ) {
struct V_23 * V_23 ;
const char * V_79 ;
if ( F_36 ( V_2 , L_5 ,
V_6 , & V_79 ) )
break;
if ( * V_79 == '\0' )
continue;
V_23 = F_24 ( V_79 , V_4 , V_3 ,
V_43 , V_72 , V_6 ) ;
if ( F_26 ( V_23 ) )
goto V_68;
V_74 -> V_78 [ V_6 ] = V_23 ;
}
F_27 ( V_4 ) ;
F_37 ( V_2 , V_80 , V_74 ) ;
return;
V_68:
if ( V_74 )
F_27 ( V_74 -> V_78 ) ;
F_27 ( V_74 ) ;
F_27 ( V_4 ) ;
}
void T_1 F_38 ( struct V_1 * V_2 )
{
const struct V_70 * V_71 ;
void T_4 * V_43 ;
const char * V_81 , * V_79 ;
struct V_23 * V_23 ;
struct V_82 * V_72 ;
V_71 = F_35 ( V_83 , V_2 ) ;
if ( ! V_71 ) {
F_39 ( L_6 , V_31 ) ;
return;
}
V_72 = (struct V_82 * ) V_71 -> V_72 ;
V_43 = F_30 ( V_2 ) ;
if ( ! V_43 )
return;
V_81 = F_6 ( V_2 , 0 ) ;
if ( ! V_81 )
return;
if ( F_36 ( V_2 , L_5 ,
0 , & V_79 ) )
return;
V_23 = F_40 ( NULL , V_79 , V_81 , 0 ,
V_43 + V_72 -> V_84 , V_72 -> V_58 , 1 ,
0 , V_72 -> V_85 , NULL ) ;
if ( F_26 ( V_23 ) )
return;
F_37 ( V_2 , V_86 , V_23 ) ;
F_18 ( L_7 ,
F_19 ( V_23 ) ,
F_19 ( F_28 ( V_23 ) ) ,
( unsigned int ) F_29 ( V_23 ) ) ;
return;
}
void T_1 F_41 ( struct V_1 * V_2 )
{
const struct V_70 * V_71 ;
struct V_23 * V_23 ;
void T_4 * V_43 ;
const char * * V_4 ;
int V_3 ;
struct V_87 * V_72 ;
V_71 = F_35 ( V_88 , V_2 ) ;
if ( ! V_71 ) {
F_39 ( L_6 , V_31 ) ;
return;
}
V_72 = (struct V_87 * ) V_71 -> V_72 ;
V_43 = F_32 ( V_2 , 0 ) ;
if ( ! V_43 ) {
F_39 ( L_8 , V_31 ) ;
return;
}
V_4 = F_1 ( V_2 , & V_3 ) ;
if ( F_26 ( V_4 ) ) {
F_39 ( L_9 ,
V_31 , F_42 ( V_4 ) ) ;
return;
}
V_23 = F_43 ( NULL , V_2 -> V_41 , V_4 , V_3 ,
V_72 -> V_89 | V_90 ,
V_43 + V_72 -> V_84 ,
V_72 -> V_58 , V_72 -> V_65 , V_72 -> V_91 ,
V_72 -> V_55 ) ;
if ( F_26 ( V_23 ) )
goto V_68;
F_18 ( L_7 ,
F_19 ( V_23 ) ,
F_19 ( F_28 ( V_23 ) ) ,
( unsigned int ) F_29 ( V_23 ) ) ;
F_37 ( V_2 , V_86 , V_23 ) ;
V_68:
F_27 ( V_4 ) ;
return;
}
void T_1 F_44 ( struct V_1 * V_2 )
{
const struct V_70 * V_71 ;
void T_4 * V_43 ;
const char * * V_4 ;
int V_3 , V_6 ;
struct V_73 * V_74 ;
struct V_92 * V_72 ;
V_71 = F_35 ( V_93 , V_2 ) ;
if ( F_3 ( ! V_71 ) )
return;
V_72 = (struct V_92 * ) V_71 -> V_72 ;
V_43 = F_32 ( V_2 , 0 ) ;
if ( ! V_43 )
return;
V_4 = F_1 ( V_2 , & V_3 ) ;
if ( F_26 ( V_4 ) )
return;
V_74 = F_5 ( sizeof( * V_74 ) , V_8 ) ;
if ( ! V_74 )
goto V_68;
V_74 -> V_76 = V_94 ;
V_74 -> V_78 = F_5 ( V_74 -> V_76 * sizeof( struct V_23 * ) ,
V_8 ) ;
if ( ! V_74 -> V_78 )
goto V_68;
for ( V_6 = 0 ; V_6 < V_74 -> V_76 ; V_6 ++ ) {
struct V_23 * V_23 ;
const char * V_79 ;
struct V_95 * V_96 ;
struct V_97 * div ;
struct V_98 * V_11 ;
if ( F_36 ( V_2 , L_5 ,
V_6 , & V_79 ) )
break;
if ( * V_79 == '\0' )
continue;
V_96 = F_5 ( sizeof( struct V_95 ) , V_8 ) ;
if ( ! V_96 )
break;
div = F_5 ( sizeof( struct V_97 ) , V_8 ) ;
if ( ! div ) {
F_27 ( V_96 ) ;
break;
}
V_11 = F_5 ( sizeof( struct V_98 ) , V_8 ) ;
if ( ! V_11 ) {
F_27 ( V_96 ) ;
F_27 ( div ) ;
break;
}
V_96 -> V_43 = V_43 + V_99 ;
V_96 -> V_100 = V_6 ;
V_96 -> V_53 = V_101 ;
V_96 -> V_55 = V_72 -> V_55 ;
div -> V_43 = V_43 + V_102 ;
div -> V_58 = 2 * V_6 ;
div -> V_65 = 2 ;
div -> V_53 = V_103 ;
V_11 -> V_43 = V_43 + V_104 ;
V_11 -> V_58 = 2 * V_6 ;
V_11 -> V_57 = 0x3 ;
V_23 = F_45 ( NULL , V_79 , V_4 ,
V_3 ,
& V_11 -> V_18 , & V_24 ,
& div -> V_18 , & V_35 ,
& V_96 -> V_18 , & V_105 ,
V_72 -> V_89 ) ;
if ( F_26 ( V_23 ) ) {
F_27 ( V_96 ) ;
F_27 ( div ) ;
F_27 ( V_11 ) ;
goto V_68;
}
F_18 ( L_7 ,
F_19 ( V_23 ) ,
F_19 ( F_28 ( V_23 ) ) ,
( unsigned int ) F_29 ( V_23 ) ) ;
V_74 -> V_78 [ V_6 ] = V_23 ;
}
F_27 ( V_4 ) ;
F_37 ( V_2 , V_80 , V_74 ) ;
return;
V_68:
for ( V_6 = 0 ; V_6 < V_74 -> V_76 ; V_6 ++ ) {
struct V_106 * V_107 ;
if ( ! V_74 -> V_78 [ V_6 ] )
continue;
V_107 = F_46 ( F_47 ( V_74 -> V_78 [ V_6 ] ) ,
struct V_106 , V_18 ) ;
F_27 ( F_46 ( V_107 -> V_108 , struct V_95 , V_18 ) ) ;
F_27 ( F_46 ( V_107 -> V_109 , struct V_97 , V_18 ) ) ;
F_27 ( F_46 ( V_107 -> V_20 , struct V_98 , V_18 ) ) ;
}
if ( V_74 )
F_27 ( V_74 -> V_78 ) ;
F_27 ( V_74 ) ;
F_27 ( V_4 ) ;
}
