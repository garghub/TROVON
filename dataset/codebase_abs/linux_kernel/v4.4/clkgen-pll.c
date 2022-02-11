static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_5 = F_3 ( V_4 , V_6 ) ;
return ! ! V_5 ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_7 = F_3 ( V_4 , V_8 ) ;
return ! V_7 ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
void T_2 * V_9 = V_4 -> V_10 ;
struct V_11 * V_12 = & V_4 -> V_13 -> V_6 ;
int V_14 = 0 ;
T_1 V_15 ;
if ( F_4 ( V_2 ) )
return 0 ;
F_6 ( V_4 , V_16 , 0 ) ;
V_14 = F_7 ( V_9 + V_12 -> V_17 , V_15 ,
! ! ( ( V_15 >> V_12 -> V_18 ) & V_12 -> V_19 ) , 0 , 10000 ) ;
if ( ! V_14 ) {
if ( V_4 -> V_13 -> V_20 )
F_6 ( V_4 , V_21 , 0 ) ;
F_8 ( L_1 , F_9 ( V_2 -> V_22 ) , V_23 ) ;
}
return V_14 ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_24 = 0 ;
int V_14 = 0 ;
if ( V_4 -> V_25 )
F_11 ( V_4 -> V_25 , V_24 ) ;
V_14 = F_5 ( V_2 ) ;
if ( V_4 -> V_25 )
F_12 ( V_4 -> V_25 , V_24 ) ;
return V_14 ;
}
static void F_13 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( ! F_4 ( V_2 ) )
return;
if ( V_4 -> V_13 -> V_20 )
F_6 ( V_4 , V_21 , 1 ) ;
F_6 ( V_4 , V_16 , 1 ) ;
F_8 ( L_2 , F_9 ( V_2 -> V_22 ) , V_23 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_24 = 0 ;
if ( V_4 -> V_25 )
F_11 ( V_4 -> V_25 , V_24 ) ;
F_13 ( V_2 ) ;
if ( V_4 -> V_25 )
F_12 ( V_4 -> V_25 , V_24 ) ;
}
static unsigned long F_15 ( struct V_1 * V_2 ,
unsigned long V_26 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_27 , V_28 , V_29 ;
unsigned long V_30 ;
T_3 V_31 ;
if ( ! F_4 ( V_2 ) || ! F_1 ( V_2 ) )
return 0 ;
V_29 = F_3 ( V_4 , V_29 ) ;
V_27 = F_3 ( V_4 , V_27 ) ;
V_28 = F_3 ( V_4 , V_28 ) ;
if ( ! V_27 )
V_27 ++ ;
V_31 = ( T_3 ) 2 * ( T_3 ) V_26 * ( T_3 ) V_28 ;
V_30 = ( unsigned long ) F_16 ( V_31 , V_27 * ( 1 << V_29 ) ) ;
F_8 ( L_3 , F_17 ( V_2 ) , V_23 , V_30 ) ;
return V_30 ;
}
static unsigned long F_18 ( struct V_1 * V_2 ,
unsigned long V_26 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_27 , V_28 ;
unsigned long V_30 ;
if ( ! F_4 ( V_2 ) || ! F_1 ( V_2 ) )
return 0 ;
V_27 = F_3 ( V_4 , V_27 ) ;
V_28 = F_3 ( V_4 , V_28 ) ;
if ( ! V_27 )
V_27 = 1 ;
V_30 = ( ( 2 * ( V_26 / 1000 ) * V_28 ) / V_27 ) * 1000 ;
F_8 ( L_3 , F_17 ( V_2 ) , V_23 , V_30 ) ;
return V_30 ;
}
static int F_19 ( unsigned long V_32 , unsigned long V_33 ,
struct V_34 * V_4 )
{
unsigned long V_35 , V_36 ;
unsigned long V_37 = ~ 0 ;
unsigned long V_38 ;
long V_39 ;
static const unsigned char V_40 [] = {
48 , 56 , 64 , 72 , 80 , 88 , 96 , 104 , 112 , 120 ,
128 , 136 , 144 , 152 , 160 , 168 , 176 , 184 , 192
} ;
if ( V_33 < 800000000 || V_33 > 1600000000 )
return - V_41 ;
V_32 /= 1000 ;
V_33 /= 1000 ;
for ( V_35 = 1 ; V_35 <= 7 && V_37 ; V_35 ++ ) {
V_36 = V_35 * V_33 / ( 2 * V_32 ) ;
if ( V_36 < 8 )
continue;
if ( V_36 > 200 )
break;
V_38 = ( V_32 * 2 * V_36 ) / V_35 ;
V_39 = abs ( V_38 - V_33 ) ;
if ( ! V_39 || V_39 < V_37 ) {
V_4 -> V_42 = V_35 ;
V_4 -> V_28 = V_36 ;
V_37 = V_39 ;
}
}
if ( V_37 == ~ 0 )
return - V_41 ;
for ( V_4 -> V_43 = 6 ; V_4 -> V_28 > V_40 [ V_4 -> V_43 - 6 ] ; ( V_4 -> V_43 ) ++ )
;
return 0 ;
}
static int F_20 ( unsigned long V_32 , struct V_34 * V_4 ,
unsigned long * V_30 )
{
if ( ! V_4 -> V_42 )
V_4 -> V_42 = 1 ;
* V_30 = ( ( 2 * ( V_32 / 1000 ) * V_4 -> V_28 ) / V_4 -> V_42 ) * 1000 ;
return 0 ;
}
static unsigned long F_21 ( struct V_1 * V_2 ,
unsigned long V_26 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_28 , V_42 ;
unsigned long V_30 = 0 ;
if ( ! F_4 ( V_2 ) || ! F_1 ( V_2 ) )
return 0 ;
V_28 = F_3 ( V_4 , V_28 ) ;
V_42 = F_3 ( V_4 , V_42 ) ;
if ( V_42 )
V_30 = ( ( 2 * ( V_26 / 1000 ) * V_28 ) / V_42 ) * 1000 ;
F_8 ( L_3 , F_17 ( V_2 ) , V_23 , V_30 ) ;
return V_30 ;
}
static long F_22 ( struct V_1 * V_2 , unsigned long V_30 ,
unsigned long * V_44 )
{
struct V_34 V_45 ;
if ( ! F_19 ( * V_44 , V_30 , & V_45 ) )
F_20 ( * V_44 , & V_45 , & V_30 ) ;
else {
F_8 ( L_4 , V_23 ,
F_9 ( V_2 -> V_22 ) , V_30 ) ;
return 0 ;
}
F_8 ( L_5 ,
V_23 , F_9 ( V_2 -> V_22 ) ,
V_30 , ( unsigned int ) V_45 . V_28 ,
( unsigned int ) V_45 . V_42 ) ;
return V_30 ;
}
static int F_23 ( struct V_1 * V_2 , unsigned long V_30 ,
unsigned long V_26 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_34 V_45 ;
long V_46 = 0 ;
unsigned long V_24 = 0 ;
if ( ! V_30 || ! V_26 )
return - V_41 ;
if ( ! F_19 ( V_26 , V_30 , & V_45 ) )
F_20 ( V_26 , & V_45 , & V_46 ) ;
F_8 ( L_6 ,
V_23 , F_9 ( V_2 -> V_22 ) ,
V_46 , ( unsigned int ) V_45 . V_28 ,
( unsigned int ) V_45 . V_42 ) ;
if ( ! V_46 )
return - V_41 ;
V_4 -> V_28 = V_45 . V_28 ;
V_4 -> V_42 = V_45 . V_42 ;
V_4 -> V_43 = V_45 . V_43 ;
F_13 ( V_2 ) ;
if ( V_4 -> V_25 )
F_11 ( V_4 -> V_25 , V_24 ) ;
F_6 ( V_4 , V_28 , V_4 -> V_28 ) ;
F_6 ( V_4 , V_42 , V_4 -> V_42 ) ;
F_6 ( V_4 , V_43 , V_4 -> V_43 ) ;
if ( V_4 -> V_25 )
F_12 ( V_4 -> V_25 , V_24 ) ;
F_5 ( V_2 ) ;
return 0 ;
}
static unsigned long F_24 ( struct V_1 * V_2 ,
unsigned long V_26 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_47 , V_48 , V_42 ;
unsigned long V_30 ;
if ( ! F_4 ( V_2 ) || ! F_1 ( V_2 ) )
return 0 ;
V_47 = F_3 ( V_4 , V_47 [ 0 ] ) ;
V_48 = F_3 ( V_4 , V_48 ) ;
V_42 = F_3 ( V_4 , V_42 ) ;
if ( ! V_42 )
V_42 = 1 ;
if ( ! V_47 )
V_47 = 1 ;
V_30 = ( ( ( V_26 / 1000 ) * V_48 ) / ( V_47 * V_42 ) ) * 1000 ;
F_8 ( L_3 , F_17 ( V_2 ) , V_23 , V_30 ) ;
return V_30 ;
}
static int F_25 ( unsigned long V_32 , unsigned long V_33 ,
struct V_34 * V_4 )
{
unsigned long V_35 , V_49 , V_36 ;
unsigned long V_37 = ~ 0 ;
unsigned long V_38 , V_39 ;
if ( V_33 < 19000000 || V_33 > 3000000000u )
return - V_41 ;
for ( V_35 = 1 ; V_35 <= 7 && V_37 ; V_35 ++ ) {
V_49 = V_32 / V_35 ;
if ( V_49 < 4000000 || V_49 > 50000000 )
continue;
V_36 = V_33 / ( V_49 * 2 ) ;
if ( V_36 < 8 || V_36 > 246 )
continue;
if ( V_36 < 246 )
V_36 ++ ;
for (; V_36 >= 8 && V_37 ; V_36 -- ) {
V_38 = V_49 * 2 * V_36 ;
if ( V_38 < V_33 )
break;
V_39 = V_38 - V_33 ;
if ( ! V_39 || V_39 < V_37 ) {
V_4 -> V_42 = V_35 ;
V_4 -> V_28 = V_36 ;
V_37 = V_39 ;
}
}
}
if ( V_37 == ~ 0 )
return - V_41 ;
return 0 ;
}
static int F_26 ( unsigned long V_32 , struct V_34 * V_4 ,
unsigned long * V_30 )
{
if ( ! V_4 -> V_42 )
V_4 -> V_42 = 1 ;
* V_30 = ( V_32 / V_4 -> V_42 ) * 2 * V_4 -> V_28 ;
return 0 ;
}
static unsigned long F_27 ( struct V_1 * V_2 ,
unsigned long V_26 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_34 V_45 ;
unsigned long V_30 ;
if ( ! F_4 ( V_2 ) || ! F_1 ( V_2 ) )
return 0 ;
V_45 . V_28 = F_3 ( V_4 , V_28 ) ;
V_45 . V_42 = F_3 ( V_4 , V_42 ) ;
F_26 ( V_26 , & V_45 , & V_30 ) ;
F_8 ( L_3 , F_9 ( V_2 -> V_22 ) , V_23 , V_30 ) ;
return V_30 ;
}
static long F_28 ( struct V_1 * V_2 , unsigned long V_30 ,
unsigned long * V_44 )
{
struct V_34 V_45 ;
if ( ! F_25 ( * V_44 , V_30 , & V_45 ) ) {
F_26 ( * V_44 , & V_45 , & V_30 ) ;
} else {
F_8 ( L_4 , V_23 ,
F_9 ( V_2 -> V_22 ) , V_30 ) ;
return 0 ;
}
F_8 ( L_5 ,
V_23 , F_9 ( V_2 -> V_22 ) ,
V_30 , ( unsigned int ) V_45 . V_28 ,
( unsigned int ) V_45 . V_42 ) ;
return V_30 ;
}
static int F_29 ( struct V_1 * V_2 , unsigned long V_30 ,
unsigned long V_26 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_34 V_45 ;
long V_46 ;
unsigned long V_24 = 0 ;
if ( ! V_30 || ! V_26 )
return - V_41 ;
if ( ! F_25 ( V_26 , V_30 , & V_45 ) ) {
F_26 ( V_26 , & V_45 , & V_46 ) ;
} else {
F_8 ( L_4 , V_23 ,
F_9 ( V_2 -> V_22 ) , V_30 ) ;
return - V_41 ;
}
F_8 ( L_6 ,
V_23 , F_9 ( V_2 -> V_22 ) ,
V_46 , ( unsigned int ) V_45 . V_28 ,
( unsigned int ) V_45 . V_42 ) ;
if ( ! V_46 )
return - V_41 ;
V_4 -> V_28 = V_45 . V_28 ;
V_4 -> V_42 = V_45 . V_42 ;
F_13 ( V_2 ) ;
if ( V_4 -> V_25 )
F_11 ( V_4 -> V_25 , V_24 ) ;
F_6 ( V_4 , V_28 , V_4 -> V_28 ) ;
F_6 ( V_4 , V_42 , V_4 -> V_42 ) ;
if ( V_4 -> V_25 )
F_12 ( V_4 -> V_25 , V_24 ) ;
F_5 ( V_2 ) ;
return 0 ;
}
static struct V_22 * T_4 F_30 ( const char * V_50 ,
struct V_51 * V_52 ,
void T_2 * V_15 ,
const char * V_53 , T_5 * V_25 )
{
struct V_3 * V_4 ;
struct V_22 * V_22 ;
struct V_54 V_55 ;
V_4 = F_31 ( sizeof( * V_4 ) , V_56 ) ;
if ( ! V_4 )
return F_32 ( - V_57 ) ;
V_55 . V_58 = V_53 ;
V_55 . V_59 = V_52 -> V_59 ;
V_55 . V_24 = V_60 | V_61 ;
V_55 . V_62 = & V_50 ;
V_55 . V_63 = 1 ;
V_4 -> V_13 = V_52 ;
V_4 -> V_10 = V_15 ;
V_4 -> V_2 . V_55 = & V_55 ;
V_4 -> V_25 = V_25 ;
V_22 = F_33 ( NULL , & V_4 -> V_2 ) ;
if ( F_34 ( V_22 ) ) {
F_35 ( V_4 ) ;
return V_22 ;
}
F_8 ( L_7 ,
F_9 ( V_22 ) ,
F_9 ( F_36 ( V_22 ) ) ,
F_37 ( V_22 ) ) ;
return V_22 ;
}
static struct V_22 * T_4 F_38 ( const char * V_50 ,
const char * V_53 )
{
struct V_22 * V_22 ;
V_22 = F_39 ( NULL , V_53 , V_50 , 0 , 1 , 2 ) ;
if ( F_34 ( V_22 ) )
return V_22 ;
F_8 ( L_7 ,
F_9 ( V_22 ) ,
F_9 ( F_36 ( V_22 ) ) ,
F_37 ( V_22 ) ) ;
return V_22 ;
}
static void T_2 * T_4 F_40 (
struct V_64 * V_65 )
{
struct V_64 * V_66 ;
void T_2 * V_15 = NULL ;
V_66 = F_41 ( V_65 ) ;
if ( ! V_66 )
return NULL ;
V_15 = F_42 ( V_66 , 0 ) ;
F_43 ( V_66 ) ;
return V_15 ;
}
static void T_4 F_44 ( struct V_64 * V_65 )
{
const int V_67 = 3 ;
struct V_68 * V_69 ;
const char * V_50 ;
void T_2 * V_15 ;
const char * V_53 ;
V_50 = F_45 ( V_65 , 0 ) ;
if ( ! V_50 )
return;
V_15 = F_40 ( V_65 ) ;
if ( ! V_15 )
return;
V_69 = F_31 ( sizeof( * V_69 ) , V_56 ) ;
if ( ! V_69 )
return;
V_69 -> V_70 = V_67 ;
V_69 -> V_71 = F_31 ( V_69 -> V_70 * sizeof( struct V_22 * ) ,
V_56 ) ;
if ( ! V_69 -> V_71 )
goto V_72;
if ( F_46 ( V_65 , L_8 ,
0 , & V_53 ) )
goto V_72;
V_69 -> V_71 [ 0 ] = F_30 ( V_50 ,
(struct V_51 * ) & V_73 ,
V_15 + V_74 , V_53 , NULL ) ;
if ( F_34 ( V_69 -> V_71 [ 0 ] ) )
goto V_72;
if ( F_46 ( V_65 , L_8 ,
1 , & V_53 ) )
goto V_72;
V_69 -> V_71 [ 1 ] = F_38 ( F_9
( V_69 -> V_71 [ 0 ] ) ,
V_53 ) ;
if ( F_34 ( V_69 -> V_71 [ 1 ] ) )
goto V_72;
if ( F_46 ( V_65 , L_8 ,
2 , & V_53 ) )
goto V_72;
V_69 -> V_71 [ 2 ] = F_30 ( V_50 ,
(struct V_51 * ) & V_75 ,
V_15 + V_76 , V_53 , NULL ) ;
if ( F_34 ( V_69 -> V_71 [ 2 ] ) )
goto V_72;
F_47 ( V_65 , V_77 , V_69 ) ;
return;
V_72:
F_35 ( V_69 -> V_71 ) ;
F_35 ( V_69 ) ;
}
static struct V_22 * T_4 F_48 ( const char * V_50 ,
void T_2 * V_15 ,
struct V_51 * V_52 ,
int V_47 ,
T_5 * V_78 ,
const char * V_79 )
{
struct V_22 * V_22 ;
unsigned long V_24 ;
struct V_80 * V_81 ;
struct V_82 * div ;
V_24 = V_61 | V_83 ;
V_81 = F_31 ( sizeof( * V_81 ) , V_56 ) ;
if ( ! V_81 )
return F_32 ( - V_57 ) ;
V_81 -> V_24 = V_84 ;
V_81 -> V_15 = V_15 + V_52 -> V_85 [ V_47 ] . V_17 ;
V_81 -> V_86 = V_52 -> V_85 [ V_47 ] . V_18 ;
V_81 -> V_25 = V_78 ;
div = F_31 ( sizeof( * div ) , V_56 ) ;
if ( ! div ) {
F_35 ( V_81 ) ;
return F_32 ( - V_57 ) ;
}
div -> V_24 = V_87 | V_88 ;
div -> V_15 = V_15 + V_52 -> V_47 [ V_47 ] . V_17 ;
div -> V_18 = V_52 -> V_47 [ V_47 ] . V_18 ;
div -> V_89 = F_49 ( V_52 -> V_47 [ V_47 ] . V_19 ) ;
div -> V_25 = V_78 ;
V_22 = F_50 ( NULL , V_79 , & V_50 , 1 ,
NULL , NULL ,
& div -> V_2 , & V_90 ,
& V_81 -> V_2 , & V_91 ,
V_24 ) ;
if ( F_34 ( V_22 ) )
return V_22 ;
F_8 ( L_7 ,
F_9 ( V_22 ) ,
F_9 ( F_36 ( V_22 ) ) ,
F_37 ( V_22 ) ) ;
return V_22 ;
}
static void T_4 F_51 ( struct V_64 * V_65 )
{
const struct V_92 * V_93 ;
struct V_22 * V_22 ;
const char * V_50 , * V_94 ;
void T_2 * V_95 ;
int V_96 , V_47 ;
struct V_68 * V_69 ;
struct V_51 * V_13 ;
V_93 = F_52 ( V_97 , V_65 ) ;
if ( ! V_93 ) {
F_53 ( L_9 , V_23 ) ;
return;
}
V_13 = (struct V_51 * ) V_93 -> V_13 ;
V_50 = F_45 ( V_65 , 0 ) ;
if ( ! V_50 )
return;
V_95 = F_40 ( V_65 ) ;
if ( ! V_95 )
return;
V_22 = F_30 ( V_50 , V_13 , V_95 , V_65 -> V_58 ,
V_13 -> V_25 ) ;
if ( F_34 ( V_22 ) )
return;
V_94 = F_9 ( V_22 ) ;
V_96 = V_13 -> V_96 ;
V_69 = F_31 ( sizeof( * V_69 ) , V_56 ) ;
if ( ! V_69 )
return;
V_69 -> V_70 = V_96 ;
V_69 -> V_71 = F_31 ( V_69 -> V_70 * sizeof( struct V_22 * ) ,
V_56 ) ;
if ( ! V_69 -> V_71 )
goto V_72;
for ( V_47 = 0 ; V_47 < V_96 ; V_47 ++ ) {
struct V_22 * V_22 ;
const char * V_53 ;
if ( F_46 ( V_65 , L_8 ,
V_47 , & V_53 ) )
return;
V_22 = F_48 ( V_94 , V_95 , V_13 ,
V_47 , & V_98 , V_53 ) ;
if ( F_34 ( V_22 ) )
goto V_72;
V_69 -> V_71 [ V_47 ] = V_22 ;
}
F_47 ( V_65 , V_77 , V_69 ) ;
return;
V_72:
F_35 ( V_94 ) ;
F_35 ( V_69 -> V_71 ) ;
F_35 ( V_69 ) ;
}
static void T_4 F_54 ( struct V_64 * V_65 )
{
const struct V_92 * V_93 ;
struct V_22 * V_22 ;
const char * V_50 ;
void T_2 * V_15 ;
const char * V_53 ;
struct V_51 * V_13 ;
V_93 = F_52 ( V_99 , V_65 ) ;
if ( ! V_93 ) {
F_53 ( L_9 , V_23 ) ;
return;
}
V_13 = (struct V_51 * ) V_93 -> V_13 ;
V_50 = F_45 ( V_65 , 0 ) ;
if ( ! V_50 )
return;
V_15 = F_40 ( V_65 ) ;
if ( ! V_15 )
return;
if ( F_46 ( V_65 , L_8 ,
0 , & V_53 ) )
return;
V_22 = F_30 ( V_50 , V_13 , V_15 , V_53 , V_13 -> V_25 ) ;
if ( ! F_34 ( V_22 ) )
F_47 ( V_65 , V_100 , V_22 ) ;
return;
}
