static int F_1 ( struct V_1 * V_2 ,
int V_3 ,
void * V_4 ,
unsigned int V_5 )
{
int V_6 = 0 ;
T_1 * V_7 = V_4 ;
if ( F_2 ( V_2 -> V_8 ) )
return - V_9 ;
for ( V_6 = 0 ; V_3 > 0 ; V_6 ++ , V_3 -= 4 ) {
if ( V_10 && V_5 )
F_3 ( V_7 [ V_6 ] , V_2 -> V_11 + F_4 ( V_6 ) ) ;
else
F_5 ( V_7 [ V_6 ] , V_2 -> V_11 + F_4 ( V_6 ) ) ;
}
return 0 ;
}
static int F_6 ( struct V_1 * V_2 ,
int V_3 ,
void * V_4 ,
unsigned int V_5 )
{
int V_6 = 0 ;
T_1 * V_7 = V_4 ;
if ( F_2 ( V_2 -> V_8 ) )
return - V_9 ;
for ( V_6 = 0 ; V_3 > 0 ; V_6 ++ , V_3 -= 4 ) {
if ( V_10 && V_5 )
V_7 [ V_6 ] = F_7 ( V_2 -> V_11 + F_4 ( V_6 ) ) ;
else
V_7 [ V_6 ] = F_8 ( V_2 -> V_11 + F_4 ( V_6 ) ) ;
}
return 0 ;
}
static void F_9 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
int V_14 ;
if ( F_2 ( V_2 -> V_8 ) )
return;
F_5 ( V_13 -> V_15 , V_2 -> V_11 + V_16 ) ;
F_5 ( V_13 -> V_3 , V_2 -> V_11 + V_17 ) ;
if ( V_13 -> V_18 == V_19 ) {
if ( V_13 -> V_4 ) {
V_14 = F_1 ( V_2 , V_13 -> V_3 ,
V_13 -> V_4 , V_13 -> V_5 ) ;
if ( V_14 )
return;
}
}
if ( F_2 ( V_2 -> V_8 ) )
return;
F_5 ( V_13 -> V_18 , V_2 -> V_11 + V_20 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
if ( V_2 -> V_21 . V_22 || F_11 ( & V_2 -> V_21 . V_23 ) )
return;
V_2 -> V_21 . V_22 = 1 ;
V_2 -> V_21 . V_24 = F_12 ( & V_2 -> V_21 . V_23 ,
struct V_12 , V_25 ) ;
F_13 ( & V_2 -> V_21 . V_24 -> V_25 ) ;
V_2 -> V_21 . V_26 -- ;
F_14 ( & V_2 -> V_21 . V_27 ,
V_28 + F_15 ( V_29 ) ) ;
F_9 ( V_2 , V_2 -> V_21 . V_24 ) ;
}
static int F_16 ( struct V_1 * V_2 ,
unsigned int V_18 ,
unsigned int V_15 ,
unsigned int V_3 ,
void * V_4 ,
int V_5 ,
T_2 V_30 ,
void * V_31 )
{
struct V_12 * V_13 ;
if ( F_2 ( V_2 -> V_32 ) )
return - V_33 ;
if ( V_2 -> V_21 . V_34 )
return - V_35 ;
if ( V_3 > V_36 )
return - V_33 ;
V_13 = F_17 ( V_37 , V_38 ) ;
if ( ! V_13 )
return - V_39 ;
F_18 ( & V_13 -> V_25 ) ;
V_13 -> V_18 = V_18 ;
V_13 -> V_15 = V_15 ;
V_13 -> V_3 = V_3 ;
V_13 -> V_4 = V_4 ;
V_13 -> V_5 = V_5 ;
V_13 -> V_40 = V_30 ;
V_13 -> V_31 = V_31 ;
V_13 -> V_41 = 0 ;
F_19 ( & V_2 -> V_21 . V_42 ) ;
F_20 ( & V_13 -> V_25 , & V_2 -> V_21 . V_23 ) ;
V_2 -> V_21 . V_26 ++ ;
F_10 ( V_2 ) ;
F_21 ( & V_2 -> V_21 . V_42 ) ;
return 0 ;
}
static void F_22 ( unsigned long V_7 )
{
struct V_1 * V_2 = (struct V_1 * ) V_7 ;
struct V_12 * V_13 ;
F_23 ( & V_2 -> V_21 . V_42 ) ;
V_13 = V_2 -> V_21 . V_24 ;
V_2 -> V_21 . V_24 = NULL ;
F_24 ( & V_2 -> V_21 . V_42 ) ;
if ( V_13 == NULL ) {
V_2 -> V_21 . V_43 . V_44 ++ ;
F_25 ( F_26 ( V_2 ) ,
L_1 ) ;
return;
}
if ( V_13 -> V_40 )
V_13 -> V_40 ( V_2 , V_13 , - V_45 ) ;
F_27 ( V_37 , V_13 ) ;
F_23 ( & V_2 -> V_21 . V_42 ) ;
V_2 -> V_21 . V_22 = 0 ;
F_10 ( V_2 ) ;
F_24 ( & V_2 -> V_21 . V_42 ) ;
}
static void F_28 ( struct V_46 * V_47 )
{
struct V_1 * V_2 ;
struct V_12 * V_13 ;
int V_14 = 0 ;
V_2 = F_29 ( V_47 , struct V_1 ,
V_21 . V_48 ) ;
if ( F_30 ( & V_2 -> V_21 . V_27 ) == 0 )
V_2 -> V_21 . V_43 . V_49 ++ ;
F_19 ( & V_2 -> V_21 . V_42 ) ;
V_13 = V_2 -> V_21 . V_24 ;
V_2 -> V_21 . V_24 = NULL ;
F_21 ( & V_2 -> V_21 . V_42 ) ;
if ( V_13 == NULL ) {
F_31 ( F_26 ( V_2 ) ,
L_2 ) ;
return;
}
V_2 -> V_21 . V_43 . V_50 = F_8 ( V_2 -> V_11 + V_51 ) ;
V_13 -> V_41 = V_2 -> V_21 . V_43 . V_50 ;
if ( ( V_13 -> V_41 & V_52 ) == 0 ) {
F_31 ( F_26 ( V_2 ) ,
L_3 ) ;
V_14 = - V_9 ;
goto V_53;
} else if ( V_13 -> V_41 & V_54 ) {
V_14 = - V_9 ;
}
if ( ( V_13 -> V_18 == V_55 ) ) {
unsigned int V_3 = F_8 ( V_2 -> V_11 + V_17 ) ;
if ( ! V_13 -> V_4 ) {
F_31 ( F_26 ( V_2 ) ,
L_4 ) ;
V_14 = - V_9 ;
goto V_53;
}
if ( V_3 != V_13 -> V_3 ) {
F_31 ( F_26 ( V_2 ) ,
L_5 ) ;
V_14 = - V_9 ;
goto V_53;
}
V_14 = F_6 ( V_2 , V_3 , V_13 -> V_4 , V_13 -> V_5 ) ;
}
V_53:
if ( V_13 -> V_40 )
V_13 -> V_40 ( V_2 , V_13 , V_14 ) ;
F_27 ( V_37 , V_13 ) ;
F_19 ( & V_2 -> V_21 . V_42 ) ;
V_2 -> V_21 . V_22 = 0 ;
F_10 ( V_2 ) ;
F_21 ( & V_2 -> V_21 . V_42 ) ;
}
static void F_32 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = NULL ;
struct V_12 * V_56 ;
unsigned long V_57 ;
if ( ! F_33 ( & V_2 -> V_21 . V_58 ) )
return;
V_2 -> V_21 . V_34 = 1 ;
F_34 ( & V_2 -> V_59 , V_57 ) ;
F_35 ( V_2 , V_60 | V_61 ) ;
F_36 ( & V_2 -> V_59 , V_57 ) ;
F_25 ( F_26 ( V_2 ) ,
L_6 ) ;
F_19 ( & V_2 -> V_21 . V_42 ) ;
F_37 (cmd, tmp, &card->creg_ctrl.queue, list) {
F_13 ( & V_13 -> V_25 ) ;
V_2 -> V_21 . V_26 -- ;
if ( V_13 -> V_40 )
V_13 -> V_40 ( V_2 , V_13 , - V_62 ) ;
F_27 ( V_37 , V_13 ) ;
}
V_13 = V_2 -> V_21 . V_24 ;
V_2 -> V_21 . V_24 = NULL ;
if ( V_13 ) {
if ( F_38 ( & V_2 -> V_21 . V_27 ) )
F_30 ( & V_2 -> V_21 . V_27 ) ;
if ( V_13 -> V_40 )
V_13 -> V_40 ( V_2 , V_13 , - V_62 ) ;
F_27 ( V_37 , V_13 ) ;
V_2 -> V_21 . V_22 = 0 ;
}
F_21 ( & V_2 -> V_21 . V_42 ) ;
V_2 -> V_21 . V_34 = 0 ;
F_34 ( & V_2 -> V_59 , V_57 ) ;
F_39 ( V_2 , V_60 | V_61 ) ;
F_36 ( & V_2 -> V_59 , V_57 ) ;
F_40 ( & V_2 -> V_21 . V_58 ) ;
}
static void F_41 ( struct V_1 * V_2 ,
struct V_12 * V_13 ,
int V_14 )
{
struct V_63 * V_64 ;
V_64 = V_13 -> V_31 ;
F_42 ( ! V_64 ) ;
V_64 -> V_14 = V_14 ;
V_64 -> V_65 = V_13 -> V_41 ;
F_43 ( V_64 -> V_66 ) ;
}
static int F_44 ( struct V_1 * V_2 ,
unsigned int V_18 ,
unsigned int V_15 ,
unsigned int V_3 ,
void * V_4 ,
int V_5 ,
unsigned int * V_67 )
{
F_45 ( V_66 ) ;
struct V_63 V_68 ;
unsigned long V_69 ;
int V_14 ;
V_68 . V_66 = & V_66 ;
V_68 . V_14 = 0 ;
V_68 . V_65 = 0 ;
V_14 = F_16 ( V_2 , V_18 , V_15 , V_3 , V_4 , V_5 , F_41 ,
& V_68 ) ;
if ( V_14 )
return V_14 ;
V_69 = F_15 ( V_29 *
V_2 -> V_21 . V_26 + 20000 ) ;
V_14 = F_46 ( V_68 . V_66 , V_69 ) ;
if ( V_14 == 0 ) {
F_47 ( F_26 ( V_2 ) ,
L_7 ) ;
F_32 ( V_2 ) ;
return - V_9 ;
}
* V_67 = V_68 . V_65 ;
if ( V_68 . V_14 ) {
F_25 ( F_26 ( V_2 ) ,
L_8 ,
V_68 . V_14 , V_15 ) ;
return V_68 . V_14 ;
}
return 0 ;
}
static int F_48 ( struct V_1 * V_2 ,
T_1 V_15 ,
unsigned int V_70 ,
void * V_7 ,
int V_5 ,
int V_71 )
{
unsigned int V_67 ;
unsigned int V_72 ;
unsigned int V_18 ;
int V_14 ;
V_18 = V_71 ? V_55 : V_19 ;
do {
V_72 = F_49 (unsigned int, size8, MAX_CREG_DATA8) ;
V_14 = F_44 ( V_2 , V_18 , V_15 , V_72 ,
V_7 , V_5 , & V_67 ) ;
if ( V_14 )
return V_14 ;
V_7 = ( char * ) V_7 + V_72 ;
V_15 += V_72 ;
V_70 -= V_72 ;
} while ( V_70 );
return 0 ;
}
int F_50 ( struct V_1 * V_2 ,
T_1 V_15 ,
unsigned int V_70 ,
void * V_7 ,
int V_73 )
{
return F_48 ( V_2 , V_15 , V_70 , V_7 , V_73 , 0 ) ;
}
int F_51 ( struct V_1 * V_2 ,
T_1 V_15 ,
unsigned int V_70 ,
void * V_7 ,
int V_73 )
{
return F_48 ( V_2 , V_15 , V_70 , V_7 , V_73 , 1 ) ;
}
int F_52 ( struct V_1 * V_2 , unsigned int * V_74 )
{
return F_51 ( V_2 , V_75 ,
sizeof( * V_74 ) , V_74 , 0 ) ;
}
int F_53 ( struct V_1 * V_2 , T_3 * V_70 )
{
unsigned int V_76 ;
int V_14 ;
V_14 = F_51 ( V_2 , V_77 ,
sizeof( V_76 ) , & V_76 , 0 ) ;
if ( V_14 )
return V_14 ;
* V_70 = ( T_3 ) V_76 * V_78 ;
return 0 ;
}
int F_54 ( struct V_1 * V_2 ,
unsigned int * V_79 )
{
return F_51 ( V_2 , V_80 ,
sizeof( * V_79 ) , V_79 , 0 ) ;
}
int F_55 ( struct V_1 * V_2 ,
T_1 * V_81 )
{
return F_51 ( V_2 , V_82 ,
sizeof( * V_81 ) , V_81 , 0 ) ;
}
int F_56 ( struct V_1 * V_2 , T_1 V_13 )
{
return F_50 ( V_2 , V_83 ,
sizeof( V_13 ) , & V_13 , 0 ) ;
}
static void F_57 ( struct V_1 * V_2 , const char * V_84 , int V_85 )
{
static char V_86 ;
if ( ( V_85 > 3 ) && ( V_84 [ 0 ] == '<' ) && ( V_84 [ 2 ] == '>' ) ) {
V_86 = V_84 [ 1 ] ;
V_84 += 3 ;
V_85 -= 3 ;
}
switch ( V_86 ) {
case '0' :
F_58 ( F_26 ( V_2 ) , L_9 , V_85 , V_84 ) ;
break;
case '1' :
F_59 ( F_26 ( V_2 ) , L_9 , V_85 , V_84 ) ;
break;
case '2' :
F_47 ( F_26 ( V_2 ) , L_9 , V_85 , V_84 ) ;
break;
case '3' :
F_31 ( F_26 ( V_2 ) , L_9 , V_85 , V_84 ) ;
break;
case '4' :
F_25 ( F_26 ( V_2 ) , L_9 , V_85 , V_84 ) ;
break;
case '5' :
F_60 ( F_26 ( V_2 ) , L_9 , V_85 , V_84 ) ;
break;
case '6' :
F_61 ( F_26 ( V_2 ) , L_9 , V_85 , V_84 ) ;
break;
case '7' :
F_62 ( F_26 ( V_2 ) , L_9 , V_85 , V_84 ) ;
break;
default:
F_61 ( F_26 ( V_2 ) , L_9 , V_85 , V_84 ) ;
break;
}
}
static int F_63 ( char * V_87 , const char * V_88 , int V_89 )
{
int V_90 = V_89 ;
while ( V_89 ) {
V_89 -- ;
* V_87 = * V_88 ;
if ( * V_87 == '\0' )
break;
V_88 ++ ;
V_87 ++ ;
}
return V_90 - V_89 ;
}
static void F_64 ( struct V_1 * V_2 ,
struct V_12 * V_13 ,
int V_14 )
{
char * V_4 ;
char * V_91 ;
int V_92 ;
int V_85 ;
int V_93 ;
V_4 = V_13 -> V_4 ;
V_93 = 0 ;
if ( V_14 )
return;
while ( V_93 < V_13 -> V_3 ) {
V_91 = & V_2 -> log . V_4 [ V_2 -> log . V_94 ] ;
V_92 = F_65 ( V_13 -> V_3 - V_93 , V_95 - V_2 -> log . V_94 ) ;
V_85 = F_63 ( V_91 , & V_4 [ V_93 ] , V_92 ) ;
V_93 += V_85 ;
V_2 -> log . V_94 += V_85 ;
if ( ( V_91 [ V_85 - 1 ] == '\0' ) ||
( V_2 -> log . V_94 == V_95 ) ) {
if ( V_2 -> log . V_94 != 1 )
F_57 ( V_2 , V_2 -> log . V_4 ,
V_2 -> log . V_94 ) ;
V_2 -> log . V_94 = 0 ;
}
}
if ( V_13 -> V_41 & V_96 )
F_66 ( V_2 ) ;
}
int F_66 ( struct V_1 * V_2 )
{
int V_14 ;
V_14 = F_16 ( V_2 , V_55 , V_97 ,
sizeof( V_2 -> log . V_56 ) , V_2 -> log . V_56 ,
1 , F_64 , NULL ) ;
if ( V_14 )
F_31 ( F_26 ( V_2 ) ,
L_10 ) ;
return V_14 ;
}
static int F_67 ( struct V_1 * V_2 ,
struct V_98 * V_13 ,
int V_71 )
{
unsigned int V_18 = V_71 ? V_55 : V_19 ;
return F_44 ( V_2 , V_18 , V_13 -> V_15 , V_13 -> V_92 , V_13 -> V_7 ,
V_13 -> V_5 , & V_13 -> V_50 ) ;
}
int V_98 ( struct V_1 * V_2 ,
struct V_98 T_4 * V_99 ,
int V_71 )
{
struct V_98 V_13 ;
int V_14 ;
V_14 = F_68 ( & V_13 , V_99 , sizeof( V_13 ) ) ;
if ( V_14 )
return - V_100 ;
if ( V_13 . V_92 > V_101 )
return - V_100 ;
V_14 = F_67 ( V_2 , & V_13 , V_71 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_69 ( V_13 . V_50 , & V_99 -> V_50 ) ;
if ( V_14 )
return - V_100 ;
if ( V_71 ) {
V_14 = F_70 ( V_99 -> V_7 , V_13 . V_7 , V_13 . V_92 ) ;
if ( V_14 )
return - V_100 ;
}
return 0 ;
}
void F_71 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = NULL ;
V_13 = V_2 -> V_21 . V_24 ;
V_2 -> V_21 . V_24 = NULL ;
if ( V_13 ) {
F_30 ( & V_2 -> V_21 . V_27 ) ;
F_19 ( & V_2 -> V_21 . V_42 ) ;
F_72 ( & V_13 -> V_25 , & V_2 -> V_21 . V_23 ) ;
V_2 -> V_21 . V_26 ++ ;
V_2 -> V_21 . V_22 = 0 ;
F_21 ( & V_2 -> V_21 . V_42 ) ;
}
}
void F_73 ( struct V_1 * V_2 )
{
F_19 ( & V_2 -> V_21 . V_42 ) ;
if ( ! F_11 ( & V_2 -> V_21 . V_23 ) )
F_10 ( V_2 ) ;
F_21 ( & V_2 -> V_21 . V_42 ) ;
}
int F_74 ( struct V_1 * V_2 )
{
V_2 -> V_21 . V_24 = NULL ;
F_75 ( & V_2 -> V_21 . V_48 , F_28 ) ;
F_76 ( & V_2 -> V_21 . V_58 ) ;
F_18 ( & V_2 -> V_21 . V_23 ) ;
F_77 ( & V_2 -> V_21 . V_42 ) ;
F_78 ( & V_2 -> V_21 . V_27 , F_22 ,
( unsigned long ) V_2 ) ;
return 0 ;
}
void F_79 ( struct V_1 * V_2 )
{
struct V_12 * V_13 ;
struct V_12 * V_56 ;
int V_92 = 0 ;
F_19 ( & V_2 -> V_21 . V_42 ) ;
F_37 (cmd, tmp, &card->creg_ctrl.queue, list) {
F_13 ( & V_13 -> V_25 ) ;
if ( V_13 -> V_40 )
V_13 -> V_40 ( V_2 , V_13 , - V_62 ) ;
F_27 ( V_37 , V_13 ) ;
V_92 ++ ;
}
if ( V_92 )
F_61 ( F_26 ( V_2 ) ,
L_11 , V_92 ) ;
V_13 = V_2 -> V_21 . V_24 ;
V_2 -> V_21 . V_24 = NULL ;
if ( V_13 ) {
if ( F_38 ( & V_2 -> V_21 . V_27 ) )
F_30 ( & V_2 -> V_21 . V_27 ) ;
if ( V_13 -> V_40 )
V_13 -> V_40 ( V_2 , V_13 , - V_62 ) ;
F_61 ( F_26 ( V_2 ) ,
L_12 ) ;
F_27 ( V_37 , V_13 ) ;
}
F_21 ( & V_2 -> V_21 . V_42 ) ;
F_80 ( & V_2 -> V_21 . V_48 ) ;
}
int F_81 ( void )
{
V_37 = F_82 ( V_12 , V_102 ) ;
if ( ! V_37 )
return - V_39 ;
return 0 ;
}
void F_83 ( void )
{
F_84 ( V_37 ) ;
}
