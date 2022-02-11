static void T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 ;
struct V_4 * V_5 ;
struct V_6 * V_7 ;
const char * V_8 = V_2 -> V_9 ;
T_2 V_10 ;
if ( F_2 ( V_2 , L_1 , & V_10 ) )
return;
V_5 = F_3 ( sizeof( struct V_4 ) , V_11 ) ;
if ( ! V_5 )
return;
V_7 = F_3 ( sizeof( struct V_6 ) , V_11 ) ;
if ( ! V_7 )
goto V_12;
F_4 ( V_2 , L_2 , & V_8 ) ;
V_7 -> V_13 = F_5 ( V_2 , 0 ) ;
V_7 -> V_14 = V_15 ;
V_7 -> V_16 = & V_17 ;
V_5 -> V_18 = V_10 ;
V_3 = F_6 ( NULL , V_8 ,
NULL , 0 ,
NULL , NULL ,
& V_5 -> V_19 , & V_20 ,
& V_7 -> V_19 , & V_21 ,
V_22 ) ;
if ( F_7 ( V_3 ) )
goto V_23;
F_8 ( V_2 , V_24 , V_3 ) ;
F_9 ( V_3 , V_8 , NULL ) ;
return;
V_23:
F_10 ( V_7 ) ;
V_12:
F_10 ( V_5 ) ;
}
static void F_11 ( T_2 * V_25 , T_2 V_26 ,
T_3 * V_27 , T_3 * V_28 , T_3 * V_29 , T_3 * V_30 )
{
T_3 div ;
div = * V_25 / 6000000 ;
* V_25 = 6000000 * div ;
if ( V_27 == NULL )
return;
* V_29 = 0 ;
if ( * V_25 >= 768000000 || * V_25 == 42000000 || * V_25 == 54000000 )
* V_28 = 1 ;
else
* V_28 = 0 ;
if ( div < 10 )
* V_30 = 3 ;
else if ( div < 20 || ( div < 32 && ( div & 1 ) ) )
* V_30 = 2 ;
else if ( div < 40 || ( div < 64 && ( div & 2 ) ) )
* V_30 = 1 ;
else
* V_30 = 0 ;
div <<= * V_30 ;
div /= ( * V_28 + 1 ) ;
* V_27 = div / 4 ;
}
static void F_12 ( T_2 * V_25 , T_2 V_26 ,
T_3 * V_27 , T_3 * V_28 , T_3 * V_29 , T_3 * V_30 )
{
T_2 V_31 = * V_25 / 1000000 ;
T_2 V_32 = V_26 / 1000000 ;
T_2 V_33 = F_13 ( V_31 , 6 ) ;
T_2 V_34 = F_13 ( V_31 , 16 ) ;
if ( V_33 > V_34 )
V_31 = V_33 ;
else
V_31 = V_34 ;
* V_25 = V_31 * 1000000 ;
if ( V_27 == NULL )
return;
if ( ! ( V_31 % 32 ) )
* V_28 = 3 ;
else if ( ! ( V_31 % 9 ) )
* V_28 = 2 ;
else if ( ! ( V_31 % 8 ) )
* V_28 = 1 ;
else
* V_28 = 0 ;
if ( ( V_31 % 6 ) == 2 || ( V_31 % 6 ) == 4 )
* V_29 = 2 ;
else if ( ( V_31 / 6 ) & 1 )
* V_29 = 3 ;
else
* V_29 = 1 ;
* V_27 = V_31 * ( * V_29 + 1 ) / ( ( * V_28 + 1 ) * V_32 ) - 1 ;
if ( ( * V_27 + 1 ) > 31 && ( * V_29 + 1 ) > 1 ) {
* V_27 = ( * V_27 + 1 ) / 2 - 1 ;
* V_29 = ( * V_29 + 1 ) / 2 - 1 ;
}
}
static void F_14 ( T_2 * V_25 , T_2 V_26 ,
T_3 * V_27 , T_3 * V_28 , T_3 * V_29 , T_3 * V_30 )
{
T_3 div ;
div = * V_25 / V_26 ;
* V_25 = V_26 * div ;
if ( V_27 == NULL )
return;
if ( div < 31 )
* V_28 = 0 ;
else if ( div / 2 < 31 )
* V_28 = 1 ;
else if ( div / 3 < 31 )
* V_28 = 2 ;
else
* V_28 = 3 ;
* V_27 = F_15 ( div , ( * V_28 + 1 ) ) ;
}
static void F_16 ( T_2 * V_25 , T_2 V_26 ,
T_3 * V_27 , T_3 * V_28 , T_3 * V_29 , T_3 * V_30 )
{
T_3 div ;
V_26 = V_26 / 2 ;
div = * V_25 / V_26 ;
* V_25 = V_26 * div ;
if ( V_27 == NULL )
return;
* V_28 = div / 32 ;
if ( * V_28 > 3 )
* V_28 = 3 ;
* V_27 = F_15 ( div , ( * V_28 + 1 ) ) ;
}
static void F_17 ( T_2 * V_25 , T_2 V_26 ,
T_3 * V_27 , T_3 * V_28 , T_3 * V_29 , T_3 * V_30 )
{
T_3 V_35 , V_36 ;
if ( V_26 < * V_25 )
* V_25 = V_26 ;
V_26 = F_15 ( V_26 , * V_25 ) ;
if ( V_26 > 32 )
return;
if ( V_26 <= 4 )
V_36 = 0 ;
else if ( V_26 <= 8 )
V_36 = 1 ;
else if ( V_26 <= 16 )
V_36 = 2 ;
else
V_36 = 3 ;
V_35 = ( V_26 >> V_36 ) - 1 ;
* V_25 = ( V_26 >> V_36 ) / ( V_35 + 1 ) ;
if ( V_27 == NULL )
return;
* V_29 = V_35 ;
* V_30 = V_36 ;
}
static void F_18 ( T_2 * V_25 , T_2 V_26 ,
T_3 * V_27 , T_3 * V_28 , T_3 * V_29 , T_3 * V_30 )
{
T_3 div , V_35 , V_36 ;
if ( * V_25 > V_26 )
* V_25 = V_26 ;
div = F_15 ( V_26 , * V_25 ) ;
if ( div < 16 )
V_36 = 0 ;
else if ( div / 2 < 16 )
V_36 = 1 ;
else if ( div / 4 < 16 )
V_36 = 2 ;
else
V_36 = 3 ;
V_35 = F_15 ( div , 1 << V_36 ) ;
* V_25 = ( V_26 >> V_36 ) / V_35 ;
if ( V_27 == NULL )
return;
* V_29 = V_35 - 1 ;
* V_30 = V_36 ;
}
static void F_19 ( T_2 * V_25 , T_2 V_26 ,
T_3 * V_27 , T_3 * V_28 , T_3 * V_29 , T_3 * V_30 )
{
T_3 div , V_35 , V_36 ;
if ( * V_25 > V_26 )
* V_25 = V_26 ;
div = F_15 ( V_26 , * V_25 ) ;
if ( div < 32 )
V_36 = 0 ;
else if ( div / 2 < 32 )
V_36 = 1 ;
else if ( div / 4 < 32 )
V_36 = 2 ;
else
V_36 = 3 ;
V_35 = F_15 ( div , 1 << V_36 ) ;
* V_25 = ( V_26 >> V_36 ) / V_35 ;
if ( V_27 == NULL )
return;
* V_29 = V_35 - 1 ;
* V_30 = V_36 ;
}
static void T_1 F_20 ( struct V_1 * V_2 )
{
struct V_3 * V_3 ;
struct V_37 * V_38 ;
struct V_6 * V_7 ;
const char * V_8 = V_2 -> V_9 ;
const char * V_39 [ V_40 ] ;
void * V_13 ;
if ( F_4 ( V_2 , L_2 , & V_8 ) )
return;
V_38 = F_3 ( sizeof( struct V_37 ) , V_11 ) ;
if ( ! V_38 )
return;
V_7 = F_3 ( sizeof( struct V_6 ) , V_11 ) ;
if ( ! V_7 )
goto V_41;
V_39 [ 0 ] = F_21 ( V_2 , 0 ) ;
V_39 [ 1 ] = F_21 ( V_2 , 1 ) ;
if ( ! V_39 [ 0 ] || ! V_39 [ 1 ] )
goto V_42;
V_13 = F_5 ( V_2 , 0 ) ;
if ( ! V_13 )
goto V_42;
V_7 -> V_13 = V_13 ;
V_7 -> V_14 = V_43 ;
V_7 -> V_16 = & V_17 ;
V_38 -> V_13 = V_13 ;
V_38 -> V_44 = V_45 ;
V_38 -> V_46 = V_47 ;
V_38 -> V_16 = & V_17 ;
V_3 = F_6 ( NULL , V_8 ,
V_39 , V_40 ,
& V_38 -> V_19 , & V_48 ,
NULL , NULL ,
& V_7 -> V_19 , & V_21 ,
0 ) ;
if ( F_7 ( V_3 ) )
goto V_49;
F_8 ( V_2 , V_24 , V_3 ) ;
F_9 ( V_3 , V_8 , NULL ) ;
return;
V_49:
F_22 ( V_13 ) ;
V_42:
F_10 ( V_7 ) ;
V_41:
F_10 ( V_38 ) ;
}
static struct V_3 * T_1 F_23 ( struct V_1 * V_2 ,
const struct V_50 * V_51 )
{
struct V_3 * V_3 ;
struct V_52 * V_53 ;
struct V_6 * V_7 = NULL ;
struct V_37 * V_38 = NULL ;
struct V_54 * V_55 = NULL ;
struct V_54 * V_56 = NULL ;
const char * V_8 = V_2 -> V_9 ;
const char * V_39 [ V_57 ] ;
void * V_13 ;
int V_58 = 0 ;
V_13 = F_5 ( V_2 , 0 ) ;
while ( V_58 < V_57 &&
( V_39 [ V_58 ] = F_21 ( V_2 , V_58 ) ) != NULL )
V_58 ++ ;
if ( V_51 -> V_9 )
V_8 = V_51 -> V_9 ;
else
F_4 ( V_2 , L_2 , & V_8 ) ;
V_53 = F_3 ( sizeof( struct V_52 ) , V_11 ) ;
if ( ! V_53 )
return NULL ;
if ( V_51 -> V_59 ) {
V_7 = F_3 ( sizeof( struct V_6 ) , V_11 ) ;
if ( ! V_7 ) {
F_10 ( V_53 ) ;
return NULL ;
}
V_7 -> V_13 = V_13 ;
V_7 -> V_14 = V_51 -> V_59 ;
V_7 -> V_16 = & V_17 ;
V_55 = & V_7 -> V_19 ;
}
if ( V_51 -> V_38 ) {
V_38 = F_3 ( sizeof( struct V_37 ) , V_11 ) ;
if ( ! V_38 ) {
F_10 ( V_53 ) ;
F_10 ( V_7 ) ;
return NULL ;
}
V_38 -> V_13 = V_13 ;
V_38 -> V_60 = V_51 -> V_38 ;
V_38 -> V_44 = V_61 ;
V_38 -> V_16 = & V_17 ;
V_56 = & V_38 -> V_19 ;
}
V_53 -> V_13 = V_13 ;
V_53 -> V_62 = V_51 -> V_63 ;
V_53 -> V_64 = V_51 -> V_65 ;
V_53 -> V_16 = & V_17 ;
V_3 = F_6 ( NULL , V_8 ,
V_39 , V_58 ,
V_56 , & V_48 ,
& V_53 -> V_19 , & V_66 ,
V_55 , & V_21 , 0 ) ;
if ( ! F_7 ( V_3 ) ) {
F_8 ( V_2 , V_24 , V_3 ) ;
F_9 ( V_3 , V_8 , NULL ) ;
}
return V_3 ;
}
static void T_1 F_24 ( struct V_1 * V_2 ,
struct V_67 * V_51 )
{
struct V_3 * V_3 ;
const char * V_8 = V_2 -> V_9 ;
const char * V_39 [ V_57 ] ;
void * V_13 ;
int V_58 = 0 ;
V_13 = F_5 ( V_2 , 0 ) ;
while ( V_58 < V_57 &&
( V_39 [ V_58 ] = F_21 ( V_2 , V_58 ) ) != NULL )
V_58 ++ ;
F_4 ( V_2 , L_2 , & V_8 ) ;
V_3 = F_25 ( NULL , V_8 , V_39 , V_58 ,
V_68 , V_13 ,
V_51 -> V_60 , V_69 ,
0 , & V_17 ) ;
if ( V_3 ) {
F_8 ( V_2 , V_24 , V_3 ) ;
F_9 ( V_3 , V_8 , NULL ) ;
}
}
static void T_1 F_26 ( struct V_1 * V_2 ,
struct V_70 * V_51 )
{
struct V_3 * V_3 ;
const char * V_8 = V_2 -> V_9 ;
const char * V_71 ;
void * V_13 ;
V_13 = F_5 ( V_2 , 0 ) ;
V_71 = F_21 ( V_2 , 0 ) ;
F_4 ( V_2 , L_2 , & V_8 ) ;
V_3 = F_27 ( NULL , V_8 , V_71 , 0 ,
V_13 , V_51 -> V_60 , V_51 -> V_72 ,
V_51 -> pow ? V_73 : 0 ,
& V_17 ) ;
if ( V_3 ) {
F_8 ( V_2 , V_24 , V_3 ) ;
F_9 ( V_3 , V_8 , NULL ) ;
}
}
static int F_28 ( struct V_74 * V_75 ,
unsigned long V_76 )
{
struct V_77 * V_51 = F_29 ( V_75 ,
struct V_77 ,
V_75 ) ;
unsigned long V_46 ;
T_2 V_13 ;
F_30 ( V_51 -> V_16 , V_46 ) ;
V_13 = F_31 ( V_51 -> V_13 ) ;
F_32 ( V_13 & ~ F_33 ( V_76 ) , V_51 -> V_13 ) ;
F_34 ( V_51 -> V_16 , V_46 ) ;
return 0 ;
}
static int F_35 ( struct V_74 * V_75 ,
unsigned long V_76 )
{
struct V_77 * V_51 = F_29 ( V_75 ,
struct V_77 ,
V_75 ) ;
unsigned long V_46 ;
T_2 V_13 ;
F_30 ( V_51 -> V_16 , V_46 ) ;
V_13 = F_31 ( V_51 -> V_13 ) ;
F_32 ( V_13 | F_33 ( V_76 ) , V_51 -> V_13 ) ;
F_34 ( V_51 -> V_16 , V_46 ) ;
return 0 ;
}
static void T_1 F_36 ( struct V_1 * V_2 ,
struct V_78 * V_51 )
{
struct V_79 * V_80 ;
struct V_77 * V_81 ;
const char * V_71 ;
const char * V_8 ;
void * V_13 ;
int V_82 ;
int V_58 = 0 ;
int V_83 = 0 ;
int V_84 ;
V_13 = F_5 ( V_2 , 0 ) ;
V_71 = F_21 ( V_2 , 0 ) ;
V_82 = F_37 ( V_51 -> V_44 , V_85 ) ;
V_80 = F_38 ( sizeof( struct V_79 ) , V_11 ) ;
if ( ! V_80 )
return;
V_80 -> V_86 = F_3 ( ( V_82 + 1 ) * sizeof( struct V_3 * ) , V_11 ) ;
if ( ! V_80 -> V_86 ) {
F_10 ( V_80 ) ;
return;
}
F_39 (i, data->mask, SUNXI_GATES_MAX_SIZE) {
F_40 ( V_2 , L_2 ,
V_83 , & V_8 ) ;
V_84 = ! strcmp ( L_3 , V_8 ) ? V_87 : 0 ;
V_80 -> V_86 [ V_58 ] = F_41 ( NULL , V_8 ,
V_71 , V_84 ,
V_13 + 4 * ( V_58 / 32 ) , V_58 % 32 ,
0 , & V_17 ) ;
F_42 ( F_7 ( V_80 -> V_86 [ V_58 ] ) ) ;
V_83 ++ ;
}
V_80 -> V_88 = V_58 ;
F_8 ( V_2 , V_89 , V_80 ) ;
if ( V_51 -> V_90 == 0 )
return;
V_81 = F_3 ( sizeof( * V_81 ) , V_11 ) ;
if ( ! V_81 )
return;
V_81 -> V_13 = V_13 ;
V_81 -> V_16 = & V_17 ;
V_81 -> V_75 . V_91 = F_43 ( V_51 -> V_90 ) + 1 ;
V_81 -> V_75 . V_92 = & V_93 ;
V_81 -> V_75 . V_94 = V_2 ;
F_44 ( & V_81 -> V_75 ) ;
}
static void T_1 F_45 ( struct V_1 * V_2 ,
struct V_95 * V_51 )
{
struct V_79 * V_80 ;
const char * V_96 ;
const char * V_8 ;
struct V_3 * * V_86 , * V_97 ;
struct V_54 * V_55 , * V_98 ;
const struct V_99 * V_100 ;
struct V_6 * V_7 = NULL ;
struct V_101 * V_102 ;
struct V_103 * V_104 ;
void * V_13 ;
int V_58 = 0 ;
int V_46 , V_105 ;
V_97 = F_23 ( V_2 , V_51 -> V_53 ) ;
V_96 = F_46 ( V_97 ) ;
V_13 = F_5 ( V_2 , 0 ) ;
V_80 = F_38 ( sizeof( struct V_79 ) , V_11 ) ;
if ( ! V_80 )
return;
V_86 = F_3 ( ( V_106 + 1 ) * sizeof( * V_86 ) , V_11 ) ;
if ( ! V_86 )
goto V_107;
V_80 -> V_86 = V_86 ;
V_105 = ! strcmp ( L_4 , V_96 ) ? 0 : V_108 ;
for ( V_58 = 0 ; V_58 < V_106 ; V_58 ++ ) {
if ( F_40 ( V_2 , L_2 ,
V_58 , & V_8 ) != 0 )
break;
V_55 = NULL ;
V_98 = NULL ;
V_100 = NULL ;
if ( V_51 -> div [ V_58 ] . V_7 ) {
V_7 = F_3 ( sizeof( * V_7 ) , V_11 ) ;
if ( ! V_7 )
goto V_109;
V_7 -> V_13 = V_13 ;
V_7 -> V_14 = V_51 -> div [ V_58 ] . V_7 ;
V_7 -> V_16 = & V_17 ;
V_55 = & V_7 -> V_19 ;
}
if ( V_51 -> div [ V_58 ] . V_5 ) {
V_102 = F_3 ( sizeof( * V_102 ) , V_11 ) ;
if ( ! V_102 )
goto V_42;
V_102 -> V_110 = 1 ;
V_102 -> div = V_51 -> div [ V_58 ] . V_5 ;
V_98 = & V_102 -> V_19 ;
V_100 = & V_111 ;
} else {
V_104 = F_3 ( sizeof( * V_104 ) , V_11 ) ;
if ( ! V_104 )
goto V_42;
V_46 = V_51 -> div [ V_58 ] . pow ? V_73 : 0 ;
V_104 -> V_13 = V_13 ;
V_104 -> V_60 = V_51 -> div [ V_58 ] . V_60 ;
V_104 -> V_72 = V_112 ;
V_104 -> V_46 = V_46 ;
V_104 -> V_16 = & V_17 ;
V_104 -> V_63 = V_51 -> div [ V_58 ] . V_63 ;
V_98 = & V_104 -> V_19 ;
V_100 = & V_113 ;
}
V_86 [ V_58 ] = F_6 ( NULL , V_8 , & V_96 , 1 ,
NULL , NULL ,
V_98 , V_100 ,
V_55 , & V_21 ,
V_105 ) ;
F_42 ( F_7 ( V_80 -> V_86 [ V_58 ] ) ) ;
F_9 ( V_86 [ V_58 ] , V_8 , NULL ) ;
}
V_86 [ V_58 ++ ] = V_97 ;
V_80 -> V_88 = V_58 ;
F_8 ( V_2 , V_89 , V_80 ) ;
return;
V_42:
F_10 ( V_7 ) ;
V_109:
F_10 ( V_86 ) ;
V_107:
F_10 ( V_80 ) ;
}
static void T_1 F_47 ( const struct V_114 * V_115 ,
void * V_116 )
{
struct V_1 * V_117 ;
const struct V_70 * V_51 ;
const struct V_114 * V_118 ;
void (* F_48)( struct V_1 * , const void * ) = V_116 ;
F_49 (np, clk_match) {
V_118 = F_50 ( V_115 , V_117 ) ;
V_51 = V_118 -> V_51 ;
F_48 ( V_117 , V_51 ) ;
}
}
static void T_1 F_51 ( void )
{
struct V_3 * V_3 ;
V_3 = F_52 ( NULL , L_5 ) ;
if ( ! F_7 ( V_3 ) ) {
F_53 ( V_3 ) ;
F_54 ( V_3 ) ;
}
V_3 = F_52 ( NULL , L_6 ) ;
if ( ! F_7 ( V_3 ) ) {
F_53 ( V_3 ) ;
F_54 ( V_3 ) ;
}
}
static void T_1 F_55 ( void )
{
F_47 ( V_119 , F_23 ) ;
F_47 ( V_120 , F_26 ) ;
F_47 ( V_121 , F_45 ) ;
F_47 ( V_122 , F_24 ) ;
F_47 ( V_123 , F_36 ) ;
F_51 () ;
}
