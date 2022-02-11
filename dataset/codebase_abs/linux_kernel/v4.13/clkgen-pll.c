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
static int F_15 ( unsigned long V_26 , unsigned long V_27 ,
struct V_28 * V_4 )
{
unsigned long V_29 , V_30 ;
unsigned long V_31 = ~ 0 ;
unsigned long V_32 ;
long V_33 ;
static const unsigned char V_34 [] = {
48 , 56 , 64 , 72 , 80 , 88 , 96 , 104 , 112 , 120 ,
128 , 136 , 144 , 152 , 160 , 168 , 176 , 184 , 192
} ;
if ( V_27 < 800000000 || V_27 > 1600000000 )
return - V_35 ;
V_26 /= 1000 ;
V_27 /= 1000 ;
for ( V_29 = 1 ; V_29 <= 7 && V_31 ; V_29 ++ ) {
V_30 = V_29 * V_27 / ( 2 * V_26 ) ;
if ( V_30 < 8 )
continue;
if ( V_30 > 200 )
break;
V_32 = ( V_26 * 2 * V_30 ) / V_29 ;
V_33 = abs ( V_32 - V_27 ) ;
if ( ! V_33 || V_33 < V_31 ) {
V_4 -> V_36 = V_29 ;
V_4 -> V_37 = V_30 ;
V_31 = V_33 ;
}
}
if ( V_31 == ~ 0 )
return - V_35 ;
for ( V_4 -> V_38 = 6 ; V_4 -> V_37 > V_34 [ V_4 -> V_38 - 6 ] ; ( V_4 -> V_38 ) ++ )
;
return 0 ;
}
static int F_16 ( unsigned long V_26 , struct V_28 * V_4 ,
unsigned long * V_39 )
{
if ( ! V_4 -> V_36 )
V_4 -> V_36 = 1 ;
* V_39 = ( ( 2 * ( V_26 / 1000 ) * V_4 -> V_37 ) / V_4 -> V_36 ) * 1000 ;
return 0 ;
}
static unsigned long F_17 ( struct V_1 * V_2 ,
unsigned long V_40 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_37 , V_36 ;
unsigned long V_39 = 0 ;
if ( ! F_4 ( V_2 ) || ! F_1 ( V_2 ) )
return 0 ;
V_37 = F_3 ( V_4 , V_37 ) ;
V_36 = F_3 ( V_4 , V_36 ) ;
if ( V_36 )
V_39 = ( ( 2 * ( V_40 / 1000 ) * V_37 ) / V_36 ) * 1000 ;
F_8 ( L_3 , F_18 ( V_2 ) , V_23 , V_39 ) ;
return V_39 ;
}
static long F_19 ( struct V_1 * V_2 , unsigned long V_39 ,
unsigned long * V_41 )
{
struct V_28 V_42 ;
if ( ! F_15 ( * V_41 , V_39 , & V_42 ) )
F_16 ( * V_41 , & V_42 , & V_39 ) ;
else {
F_8 ( L_4 , V_23 ,
F_9 ( V_2 -> V_22 ) , V_39 ) ;
return 0 ;
}
F_8 ( L_5 ,
V_23 , F_9 ( V_2 -> V_22 ) ,
V_39 , ( unsigned int ) V_42 . V_37 ,
( unsigned int ) V_42 . V_36 ) ;
return V_39 ;
}
static int F_20 ( struct V_1 * V_2 , unsigned long V_39 ,
unsigned long V_40 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_28 V_42 ;
long V_43 = 0 ;
unsigned long V_24 = 0 ;
if ( ! V_39 || ! V_40 )
return - V_35 ;
if ( ! F_15 ( V_40 , V_39 , & V_42 ) )
F_16 ( V_40 , & V_42 , & V_43 ) ;
F_8 ( L_6 ,
V_23 , F_9 ( V_2 -> V_22 ) ,
V_43 , ( unsigned int ) V_42 . V_37 ,
( unsigned int ) V_42 . V_36 ) ;
if ( ! V_43 )
return - V_35 ;
V_4 -> V_37 = V_42 . V_37 ;
V_4 -> V_36 = V_42 . V_36 ;
V_4 -> V_38 = V_42 . V_38 ;
F_13 ( V_2 ) ;
if ( V_4 -> V_25 )
F_11 ( V_4 -> V_25 , V_24 ) ;
F_6 ( V_4 , V_37 , V_4 -> V_37 ) ;
F_6 ( V_4 , V_36 , V_4 -> V_36 ) ;
F_6 ( V_4 , V_38 , V_4 -> V_38 ) ;
if ( V_4 -> V_25 )
F_12 ( V_4 -> V_25 , V_24 ) ;
F_5 ( V_2 ) ;
return 0 ;
}
static int F_21 ( unsigned long V_26 , unsigned long V_27 ,
struct V_28 * V_4 )
{
unsigned long V_29 , V_44 , V_30 ;
unsigned long V_31 = ~ 0 ;
unsigned long V_32 , V_33 ;
if ( V_27 < 19000000 || V_27 > 3000000000u )
return - V_35 ;
for ( V_29 = 1 ; V_29 <= 7 && V_31 ; V_29 ++ ) {
V_44 = V_26 / V_29 ;
if ( V_44 < 4000000 || V_44 > 50000000 )
continue;
V_30 = V_27 / ( V_44 * 2 ) ;
if ( V_30 < 8 || V_30 > 246 )
continue;
if ( V_30 < 246 )
V_30 ++ ;
for (; V_30 >= 8 && V_31 ; V_30 -- ) {
V_32 = V_44 * 2 * V_30 ;
if ( V_32 < V_27 )
break;
V_33 = V_32 - V_27 ;
if ( ! V_33 || V_33 < V_31 ) {
V_4 -> V_36 = V_29 ;
V_4 -> V_37 = V_30 ;
V_31 = V_33 ;
}
}
}
if ( V_31 == ~ 0 )
return - V_35 ;
return 0 ;
}
static int F_22 ( unsigned long V_26 , struct V_28 * V_4 ,
unsigned long * V_39 )
{
if ( ! V_4 -> V_36 )
V_4 -> V_36 = 1 ;
* V_39 = ( V_26 / V_4 -> V_36 ) * 2 * V_4 -> V_37 ;
return 0 ;
}
static unsigned long F_23 ( struct V_1 * V_2 ,
unsigned long V_40 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_28 V_42 ;
unsigned long V_39 ;
if ( ! F_4 ( V_2 ) || ! F_1 ( V_2 ) )
return 0 ;
V_42 . V_37 = F_3 ( V_4 , V_37 ) ;
V_42 . V_36 = F_3 ( V_4 , V_36 ) ;
F_22 ( V_40 , & V_42 , & V_39 ) ;
F_8 ( L_3 , F_9 ( V_2 -> V_22 ) , V_23 , V_39 ) ;
return V_39 ;
}
static long F_24 ( struct V_1 * V_2 , unsigned long V_39 ,
unsigned long * V_41 )
{
struct V_28 V_42 ;
if ( ! F_21 ( * V_41 , V_39 , & V_42 ) ) {
F_22 ( * V_41 , & V_42 , & V_39 ) ;
} else {
F_8 ( L_4 , V_23 ,
F_9 ( V_2 -> V_22 ) , V_39 ) ;
return 0 ;
}
F_8 ( L_5 ,
V_23 , F_9 ( V_2 -> V_22 ) ,
V_39 , ( unsigned int ) V_42 . V_37 ,
( unsigned int ) V_42 . V_36 ) ;
return V_39 ;
}
static int F_25 ( struct V_1 * V_2 , unsigned long V_39 ,
unsigned long V_40 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_28 V_42 ;
long V_43 ;
unsigned long V_24 = 0 ;
if ( ! V_39 || ! V_40 )
return - V_35 ;
if ( ! F_21 ( V_40 , V_39 , & V_42 ) ) {
F_22 ( V_40 , & V_42 , & V_43 ) ;
} else {
F_8 ( L_4 , V_23 ,
F_9 ( V_2 -> V_22 ) , V_39 ) ;
return - V_35 ;
}
F_8 ( L_6 ,
V_23 , F_9 ( V_2 -> V_22 ) ,
V_43 , ( unsigned int ) V_42 . V_37 ,
( unsigned int ) V_42 . V_36 ) ;
if ( ! V_43 )
return - V_35 ;
V_4 -> V_37 = V_42 . V_37 ;
V_4 -> V_36 = V_42 . V_36 ;
F_13 ( V_2 ) ;
if ( V_4 -> V_25 )
F_11 ( V_4 -> V_25 , V_24 ) ;
F_6 ( V_4 , V_37 , V_4 -> V_37 ) ;
F_6 ( V_4 , V_36 , V_4 -> V_36 ) ;
if ( V_4 -> V_25 )
F_12 ( V_4 -> V_25 , V_24 ) ;
F_5 ( V_2 ) ;
return 0 ;
}
static struct V_22 * T_3 F_26 ( const char * V_45 ,
struct V_46 * V_47 ,
void T_2 * V_15 , unsigned long V_48 ,
const char * V_49 , T_4 * V_25 )
{
struct V_3 * V_4 ;
struct V_22 * V_22 ;
struct V_50 V_51 ;
V_4 = F_27 ( sizeof( * V_4 ) , V_52 ) ;
if ( ! V_4 )
return F_28 ( - V_53 ) ;
V_51 . V_54 = V_49 ;
V_51 . V_55 = V_47 -> V_55 ;
V_51 . V_24 = V_48 | V_56 | V_57 ;
V_51 . V_58 = & V_45 ;
V_51 . V_59 = 1 ;
V_4 -> V_13 = V_47 ;
V_4 -> V_10 = V_15 ;
V_4 -> V_2 . V_51 = & V_51 ;
V_4 -> V_25 = V_25 ;
V_22 = F_29 ( NULL , & V_4 -> V_2 ) ;
if ( F_30 ( V_22 ) ) {
F_31 ( V_4 ) ;
return V_22 ;
}
F_8 ( L_7 ,
F_9 ( V_22 ) ,
F_9 ( F_32 ( V_22 ) ) ,
F_33 ( V_22 ) ) ;
return V_22 ;
}
static void T_2 * T_3 F_34 (
struct V_60 * V_61 )
{
struct V_60 * V_62 ;
void T_2 * V_15 = NULL ;
V_62 = F_35 ( V_61 ) ;
if ( ! V_62 )
return NULL ;
V_15 = F_36 ( V_62 , 0 ) ;
F_37 ( V_62 ) ;
return V_15 ;
}
static struct V_22 * T_3 F_38 ( const char * V_45 ,
void T_2 * V_15 ,
struct V_46 * V_47 ,
unsigned long V_48 , int V_63 ,
T_4 * V_64 ,
const char * V_65 )
{
struct V_22 * V_22 ;
unsigned long V_24 ;
struct V_66 * V_67 ;
struct V_68 * div ;
V_24 = V_48 | V_57 | V_69 ;
V_67 = F_27 ( sizeof( * V_67 ) , V_52 ) ;
if ( ! V_67 )
return F_28 ( - V_53 ) ;
V_67 -> V_24 = V_70 ;
V_67 -> V_15 = V_15 + V_47 -> V_71 [ V_63 ] . V_17 ;
V_67 -> V_72 = V_47 -> V_71 [ V_63 ] . V_18 ;
V_67 -> V_25 = V_64 ;
div = F_27 ( sizeof( * div ) , V_52 ) ;
if ( ! div ) {
F_31 ( V_67 ) ;
return F_28 ( - V_53 ) ;
}
div -> V_24 = V_73 | V_74 ;
div -> V_15 = V_15 + V_47 -> V_63 [ V_63 ] . V_17 ;
div -> V_18 = V_47 -> V_63 [ V_63 ] . V_18 ;
div -> V_75 = F_39 ( V_47 -> V_63 [ V_63 ] . V_19 ) ;
div -> V_25 = V_64 ;
V_22 = F_40 ( NULL , V_65 , & V_45 , 1 ,
NULL , NULL ,
& div -> V_2 , & V_76 ,
& V_67 -> V_2 , & V_77 ,
V_24 ) ;
if ( F_30 ( V_22 ) )
return V_22 ;
F_8 ( L_7 ,
F_9 ( V_22 ) ,
F_9 ( F_32 ( V_22 ) ) ,
F_33 ( V_22 ) ) ;
return V_22 ;
}
static void T_3 F_41 ( struct V_60 * V_61 ,
struct V_46 * V_13 )
{
struct V_22 * V_22 ;
const char * V_45 , * V_78 ;
void T_2 * V_79 ;
int V_80 , V_63 ;
struct V_81 * V_82 ;
unsigned long V_48 = 0 ;
V_45 = F_42 ( V_61 , 0 ) ;
if ( ! V_45 )
return;
V_79 = F_34 ( V_61 ) ;
if ( ! V_79 )
return;
F_43 ( V_61 , 0 , & V_48 ) ;
V_22 = F_26 ( V_45 , V_13 , V_79 , V_48 ,
V_61 -> V_54 , V_13 -> V_25 ) ;
if ( F_30 ( V_22 ) )
return;
V_78 = F_9 ( V_22 ) ;
V_80 = V_13 -> V_80 ;
V_82 = F_27 ( sizeof( * V_82 ) , V_52 ) ;
if ( ! V_82 )
return;
V_82 -> V_83 = V_80 ;
V_82 -> V_84 = F_27 ( V_82 -> V_83 * sizeof( struct V_22 * ) ,
V_52 ) ;
if ( ! V_82 -> V_84 )
goto V_85;
for ( V_63 = 0 ; V_63 < V_80 ; V_63 ++ ) {
struct V_22 * V_22 ;
const char * V_49 ;
unsigned long V_86 = 0 ;
if ( F_44 ( V_61 , L_8 ,
V_63 , & V_49 ) )
return;
F_43 ( V_61 , V_63 , & V_86 ) ;
V_22 = F_38 ( V_78 , V_79 , V_13 , V_86 ,
V_63 , & V_87 , V_49 ) ;
if ( F_30 ( V_22 ) )
goto V_85;
V_82 -> V_84 [ V_63 ] = V_22 ;
}
F_45 ( V_61 , V_88 , V_82 ) ;
return;
V_85:
F_31 ( V_78 ) ;
F_31 ( V_82 -> V_84 ) ;
F_31 ( V_82 ) ;
}
static void T_3 F_46 ( struct V_60 * V_61 )
{
F_41 ( V_61 ,
(struct V_46 * ) & V_89 ) ;
}
static void T_3 F_47 ( struct V_60 * V_61 )
{
F_41 ( V_61 ,
(struct V_46 * ) & V_90 ) ;
}
static void T_3 F_48 ( struct V_60 * V_61 )
{
F_41 ( V_61 ,
(struct V_46 * ) & V_91 ) ;
}
static void T_3 F_49 ( struct V_60 * V_61 )
{
F_41 ( V_61 ,
(struct V_46 * ) & V_92 ) ;
}
