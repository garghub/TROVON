static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_5 )
{
unsigned int V_6 ;
T_1 V_7 , V_8 ;
for ( V_6 = 0 ; V_6 < V_5 ; V_6 ++ ) {
V_7 = ( V_4 [ V_6 ] . V_9 >> 32 ) & 0xffffffff ;
V_8 = ( V_4 [ V_6 ] . V_9 ) & 0xffffffff ;
F_2 ( V_2 , L_1 ,
V_4 [ V_6 ] . V_10 , V_4 [ V_6 ] . V_11 , V_7 , V_8 ) ;
}
}
static int F_3 ( struct V_1 * V_2 , void * V_12 , int V_13 )
{
struct V_14 * V_15 = V_2 -> V_16 ;
int V_5 ;
struct V_3 * V_4 ;
V_5 = F_4 ( V_15 , V_13 ) ;
if ( V_5 < 0 )
return - V_17 ;
if ( V_5 == 0 )
return 0 ;
V_4 = F_5 ( V_5 , sizeof( * V_4 ) , V_18 ) ;
if ( V_4 == NULL )
return - V_19 ;
F_6 ( V_15 ) ;
F_7 ( V_15 , V_13 , V_4 , V_5 ) ;
F_8 ( V_15 ) ;
F_1 ( V_2 , V_4 , V_5 ) ;
F_9 ( V_4 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , void * V_12 )
{
return F_3 ( V_2 , V_12 , 0 ) ;
}
static int F_11 ( struct V_1 * V_2 , void * V_12 )
{
return F_3 ( V_2 , V_12 , 1 ) ;
}
static int F_12 ( struct V_1 * V_2 , void * V_12 )
{
return F_3 ( V_2 , V_12 , 2 ) ;
}
static int F_13 ( struct V_1 * V_2 , void * V_12 , int V_13 )
{
struct V_14 * V_15 = V_2 -> V_16 ;
F_1 ( V_2 , V_15 -> V_20 [ V_13 ] . V_4 , V_15 -> V_20 [ V_13 ] . V_5 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 , void * V_12 )
{
return F_13 ( V_2 , V_12 , 0 ) ;
}
static int F_15 ( struct V_1 * V_2 , void * V_12 )
{
return F_13 ( V_2 , V_12 , 1 ) ;
}
static int F_16 ( struct V_1 * V_2 , void * V_12 )
{
return F_13 ( V_2 , V_12 , 2 ) ;
}
static int F_17 ( struct V_1 * V_2 , void * V_12 )
{
struct V_14 * V_15 = V_2 -> V_16 ;
unsigned int V_6 ;
struct V_3 * V_4 ;
V_4 = F_5 ( V_21 , sizeof( * V_4 ) , V_18 ) ;
if ( V_4 == NULL )
return - V_19 ;
F_6 ( V_15 ) ;
F_18 ( V_15 , V_4 , V_21 , 1 ) ;
F_8 ( V_15 ) ;
for ( V_6 = 0 ; V_6 < V_21 ; V_6 ++ ) {
if ( V_4 [ V_6 ] . V_10 == 0xffffffff )
break;
if ( V_4 [ V_6 ] . V_9 == 0x0ull )
continue;
F_2 ( V_2 , L_2 ,
V_4 [ V_6 ] . V_10 , V_4 [ V_6 ] . V_9 ) ;
}
return 0 ;
}
static int F_19 ( struct V_1 * V_2 , void * V_12 )
{
struct V_14 * V_15 = V_2 -> V_16 ;
unsigned int V_6 ;
struct V_3 * V_4 = V_15 -> V_20 [ V_22 ] . V_4 ;
if ( V_4 == NULL )
return - V_17 ;
for ( V_6 = 0 ; V_6 < V_21 ; V_6 ++ ) {
if ( V_4 [ V_6 ] . V_10 == 0xffffffff )
break;
if ( V_4 [ V_6 ] . V_9 == 0x0ull )
continue;
F_2 ( V_2 , L_2 ,
V_4 [ V_6 ] . V_10 , V_4 [ V_6 ] . V_9 ) ;
}
return 0 ;
}
static int F_20 ( struct V_1 * V_2 , void * V_12 )
{
struct V_14 * V_15 = V_2 -> V_16 ;
unsigned int V_23 ;
T_2 V_24 ;
V_24 = F_21 ( V_15 , V_25 , 0 ) ;
F_2 ( V_2 , L_3 , V_24 ,
V_26 ) ;
for ( V_23 = 0 ; V_23 < V_15 -> V_27 ; V_23 ++ ) {
V_24 = F_21 ( V_15 , V_25 ,
V_23 + 1 ) ;
F_2 ( V_2 , L_4 , V_23 , V_24 ,
V_15 -> V_28 [ V_23 ] ) ;
}
return 0 ;
}
static int F_22 ( struct V_1 * V_2 , void * V_12 )
{
struct V_14 * V_15 = V_2 -> V_16 ;
unsigned int V_23 ;
T_2 V_29 ;
V_29 = F_21 ( V_15 , V_30 , 0 ) ;
F_2 ( V_2 , L_5 , V_29 ) ;
for ( V_23 = 0 ; V_23 < V_15 -> V_27 ; V_23 ++ ) {
V_29 = F_21 ( V_15 , V_30 , V_23 + 1 ) ;
F_2 ( V_2 , L_6 , V_23 , V_29 ) ;
}
return 0 ;
}
static int F_23 ( struct V_1 * V_2 , void * V_12 )
{
struct V_14 * V_15 = V_2 -> V_16 ;
unsigned int V_6 ;
struct V_31 * V_32 ;
struct V_33 * V_34 ;
V_32 = & V_15 -> V_32 ;
F_24 ( V_2 , L_7 ) ;
F_2 ( V_2 , L_8
L_9
L_10
L_11
L_12
L_13
L_14
L_15
L_16 ,
V_32 -> V_35 , ( long long ) V_32 -> V_36 ,
( long long ) V_32 -> V_36 +
( V_32 -> V_35 * V_37 ) ,
( long long ) V_32 -> V_38 , V_32 -> V_39 ,
V_32 -> V_40 , V_32 -> V_41 ,
V_32 -> V_42 , V_32 -> V_43 ,
V_15 -> V_44 ) ;
F_2 ( V_2 , L_17
L_18
L_19
L_20
L_21
L_22
L_23
L_24
L_25 ,
V_32 -> V_45 ,
F_25 ( V_15 , V_32 -> V_45 ) ,
V_32 -> V_46 ,
F_25 ( V_15 , V_32 -> V_46 ) ,
V_32 -> V_47 ,
F_25 ( V_15 , V_32 -> V_47 ) ,
V_32 -> V_48 ,
F_25 ( V_15 , V_32 -> V_48 ) ,
V_32 -> V_49 ,
F_25 ( V_15 , V_32 -> V_49 ) ,
V_32 -> V_50 ,
F_25 ( V_15 , V_32 -> V_50 ) ,
V_32 -> V_51 ,
F_25 ( V_15 , V_32 -> V_51 ) ,
V_32 -> V_52 ,
F_25 ( V_15 , V_32 -> V_52 ) ,
V_32 -> V_53 ,
F_25 ( V_15 , V_32 -> V_53 ) ) ;
F_2 ( V_2 , L_26 ,
V_32 -> V_54 , V_32 -> V_55 ) ;
V_34 = V_32 -> V_38 ;
for ( V_6 = 0 ; V_6 < V_32 -> V_35 ; V_6 ++ ) {
F_2 ( V_2 , L_27 ,
V_6 , F_26 ( V_34 -> V_56 ) ,
F_26 ( V_34 -> V_57 ) ,
V_34 -> V_58 , V_34 -> V_59 ) ;
F_2 ( V_2 , L_28 ,
F_27 ( V_34 -> V_60 ) , V_34 -> V_61 ) ;
V_34 ++ ;
}
return 0 ;
}
static int F_28 ( struct V_1 * V_2 , void * V_12 )
{
struct V_14 * V_15 = V_2 -> V_16 ;
T_3 V_62 , type ;
T_2 V_63 , V_64 , V_65 = - 1 ;
struct V_66 * V_66 = V_15 -> V_66 ;
V_64 = F_25 ( V_15 , V_67 ) ;
V_63 = F_25 ( V_15 , V_68 ) ;
if ( F_29 ( V_15 ) )
V_65 = F_25 ( V_15 , V_69 ) ;
V_62 = ( T_3 ) ( V_64 & 0x0fLLU ) ;
type = ( T_3 ) ( ( V_64 >> 20 ) & 0xffLLU ) ;
F_2 ( V_2 , L_29
L_30
L_31
L_32
L_33
L_34
L_35 ,
V_70 , V_71 , F_30 ( & V_66 -> V_72 ) ,
F_29 ( V_15 ) ?
L_36 : L_37 ,
V_15 -> V_73 , V_64 , V_63 ,
( T_3 ) ( ( V_64 >> 12 ) & 0x0fLLU ) ,
( T_3 ) ( ( V_64 >> 4 ) & 0xffLLU ) ,
( T_3 ) ( ( V_64 >> 16 ) & 0x0fLLU ) + 2010 ,
F_31 ( V_15 ) ,
( T_3 ) ( ( V_64 >> 32 ) & 0xffLLU ) , V_64 >> 40 ,
V_65 ) ;
return 0 ;
}
int F_32 ( struct V_14 * V_15 )
{
struct V_74 * V_75 ;
struct V_74 * V_76 ;
int V_77 ;
char V_78 [ 64 ] ;
char V_79 [ 64 ] ;
unsigned int V_6 ;
sprintf ( V_78 , L_38 , V_70 , V_15 -> V_73 ) ;
V_75 = F_33 ( V_78 , V_15 -> V_80 ) ;
if ( ! V_75 ) {
V_77 = - V_19 ;
goto V_81;
}
V_76 = F_34 ( L_39 , V_82 , V_75 , V_15 ,
& V_83 ) ;
if ( ! V_76 ) {
V_77 = - V_19 ;
goto V_84;
}
V_76 = F_34 ( L_40 , V_82 , V_75 , V_15 ,
& V_85 ) ;
if ( ! V_76 ) {
V_77 = - V_19 ;
goto V_84;
}
V_76 = F_35 ( L_41 , 0666 , V_75 , & V_15 -> V_86 ) ;
if ( ! V_76 ) {
V_77 = - V_19 ;
goto V_84;
}
V_76 = F_36 ( L_42 , 0666 , V_75 ,
& V_15 -> V_87 ) ;
if ( ! V_76 ) {
V_77 = - V_19 ;
goto V_84;
}
V_76 = F_36 ( L_43 , 0666 , V_75 ,
& V_15 -> V_88 ) ;
if ( ! V_76 ) {
V_77 = - V_19 ;
goto V_84;
}
if ( ! F_29 ( V_15 ) ) {
V_15 -> V_89 = V_75 ;
return 0 ;
}
V_76 = F_34 ( L_44 , V_82 , V_75 , V_15 ,
& V_90 ) ;
if ( ! V_76 ) {
V_77 = - V_19 ;
goto V_84;
}
V_76 = F_34 ( L_45 , V_82 , V_75 , V_15 ,
& V_91 ) ;
if ( ! V_76 ) {
V_77 = - V_19 ;
goto V_84;
}
V_76 = F_34 ( L_46 , V_82 , V_75 , V_15 ,
& V_92 ) ;
if ( ! V_76 ) {
V_77 = - V_19 ;
goto V_84;
}
V_76 = F_34 ( L_47 , V_82 , V_75 , V_15 ,
& V_93 ) ;
if ( ! V_76 ) {
V_77 = - V_19 ;
goto V_84;
}
V_76 = F_34 ( L_48 , V_82 , V_75 , V_15 ,
& V_94 ) ;
if ( ! V_76 ) {
V_77 = - V_19 ;
goto V_84;
}
V_76 = F_34 ( L_49 , V_82 , V_75 , V_15 ,
& V_95 ) ;
if ( ! V_76 ) {
V_77 = - V_19 ;
goto V_84;
}
V_76 = F_34 ( L_50 , V_82 , V_75 , V_15 ,
& V_96 ) ;
if ( ! V_76 ) {
V_77 = - V_19 ;
goto V_84;
}
V_76 = F_34 ( L_51 , V_82 , V_75 , V_15 ,
& V_97 ) ;
if ( ! V_76 ) {
V_77 = - V_19 ;
goto V_84;
}
for ( V_6 = 0 ; V_6 < V_98 ; V_6 ++ ) {
sprintf ( V_79 , L_52 , V_6 ) ;
V_76 = F_36 ( V_79 , 0666 , V_75 ,
& V_15 -> V_28 [ V_6 ] ) ;
if ( ! V_76 ) {
V_77 = - V_19 ;
goto V_84;
}
}
V_76 = F_34 ( L_53 , V_82 , V_75 , V_15 ,
& V_99 ) ;
if ( ! V_76 ) {
V_77 = - V_19 ;
goto V_84;
}
V_76 = F_34 ( L_54 , V_82 , V_75 , V_15 ,
& V_100 ) ;
if ( ! V_76 ) {
V_77 = - V_19 ;
goto V_84;
}
V_76 = F_36 ( L_55 , 0666 , V_75 ,
& V_15 -> V_101 ) ;
if ( ! V_76 ) {
V_77 = - V_19 ;
goto V_84;
}
V_76 = F_36 ( L_56 , 0666 , V_75 ,
& V_15 -> V_102 ) ;
if ( ! V_76 ) {
V_77 = - V_19 ;
goto V_84;
}
V_15 -> V_89 = V_75 ;
return 0 ;
V_84:
F_37 ( V_75 ) ;
V_81:
return V_77 ;
}
void F_38 ( struct V_14 * V_15 )
{
F_37 ( V_15 -> V_89 ) ;
}
