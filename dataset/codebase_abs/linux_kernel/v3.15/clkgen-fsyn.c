static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_5 = 0 , V_6 = V_7 + F_3 ( 10 ) ;
if ( V_4 -> V_8 )
F_4 ( V_4 -> V_8 , V_5 ) ;
if ( V_4 -> V_9 -> V_10 )
F_5 ( V_4 , V_11 , 1 ) ;
if ( V_4 -> V_9 -> V_12 )
F_5 ( V_4 , V_13 , V_14 ) ;
F_5 ( V_4 , V_15 , V_4 -> V_15 ) ;
F_5 ( V_4 , V_16 , 1 ) ;
if ( V_4 -> V_8 )
F_6 ( V_4 -> V_8 , V_5 ) ;
if ( V_4 -> V_9 -> V_17 )
while ( ! F_7 ( V_4 , V_18 ) ) {
if ( F_8 ( V_7 , V_6 ) )
return - V_19 ;
F_9 () ;
}
return 0 ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_5 = 0 ;
if ( V_4 -> V_8 )
F_4 ( V_4 -> V_8 , V_5 ) ;
F_5 ( V_4 , V_16 , 0 ) ;
if ( V_4 -> V_9 -> V_10 )
F_5 ( V_4 , V_11 , 0 ) ;
if ( V_4 -> V_8 )
F_6 ( V_4 -> V_8 , V_5 ) ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_16 = F_7 ( V_4 , V_16 ) ;
return ! ! V_16 ;
}
int F_12 ( unsigned long V_20 , struct V_21 * V_22 ,
unsigned long * V_23 )
{
unsigned long V_24 = V_22 -> V_15 + 16 ;
* V_23 = V_20 * V_24 ;
return 0 ;
}
static unsigned long F_13 ( struct V_1 * V_2 ,
unsigned long V_25 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_23 = 0 ;
struct V_21 V_26 ;
V_26 . V_15 = F_7 ( V_4 , V_15 ) ;
if ( F_12 ( V_25 , & V_26 , & V_23 ) )
F_14 ( L_1 ,
F_15 ( V_2 -> V_27 ) , V_28 ) ;
V_4 -> V_15 = V_26 . V_15 ;
return V_23 ;
}
int F_16 ( unsigned long V_20 ,
unsigned long V_29 , struct V_21 * V_22 )
{
unsigned long V_30 = 1 , V_31 ;
if ( V_29 < 384000000 || V_29 > 660000000 )
return - V_32 ;
if ( V_20 > 40000000 )
return - V_32 ;
V_20 /= 1000 ;
V_29 /= 1000 ;
V_31 = V_29 * V_30 / V_20 ;
if ( V_31 < 16 )
V_31 = 16 ;
V_22 -> V_15 = V_31 - 16 ;
return 0 ;
}
static long F_17 ( struct V_1 * V_2 , unsigned long V_23
, unsigned long * V_33 )
{
struct V_21 V_26 ;
if ( ! F_16 ( * V_33 , V_23 , & V_26 ) )
F_12 ( * V_33 , & V_26 , & V_23 ) ;
F_18 ( L_2 ,
V_28 , F_15 ( V_2 -> V_27 ) ,
V_23 , ( unsigned int ) V_26 . V_34 ,
( unsigned int ) V_26 . V_35 ,
( unsigned int ) V_26 . V_36 , ( unsigned int ) V_26 . V_37 ) ;
return V_23 ;
}
static int F_19 ( struct V_1 * V_2 , unsigned long V_23 ,
unsigned long V_25 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_21 V_26 ;
long V_38 = 0 ;
unsigned long V_5 = 0 ;
if ( ! V_23 || ! V_25 )
return - V_32 ;
if ( ! F_16 ( V_25 , V_23 , & V_26 ) )
F_12 ( V_25 , & V_26 , & V_38 ) ;
F_18 ( L_3 ,
V_28 , F_15 ( V_2 -> V_27 ) ,
V_38 , ( unsigned int ) V_26 . V_15 ) ;
if ( ! V_38 )
return - V_32 ;
V_4 -> V_15 = V_26 . V_15 ;
if ( V_4 -> V_8 )
F_4 ( V_4 -> V_8 , V_5 ) ;
F_5 ( V_4 , V_15 , V_4 -> V_15 ) ;
if ( V_4 -> V_8 )
F_6 ( V_4 -> V_8 , V_5 ) ;
return 0 ;
}
static struct V_27 * T_2 F_20 (
const char * V_39 , const char * V_40 ,
struct V_41 * V_42 , void T_3 * V_43 ,
T_4 * V_8 )
{
struct V_3 * V_4 ;
struct V_27 * V_27 ;
struct V_44 V_45 ;
if ( F_21 ( ! V_39 || ! V_40 ) )
return F_22 ( - V_32 ) ;
V_4 = F_23 ( sizeof( * V_4 ) , V_46 ) ;
if ( ! V_4 )
return F_22 ( - V_47 ) ;
V_45 . V_39 = V_39 ;
V_45 . V_48 = V_42 -> V_49 ;
V_45 . V_5 = V_50 ;
V_45 . V_51 = & V_40 ;
V_45 . V_52 = 1 ;
V_4 -> V_9 = V_42 ;
V_4 -> V_53 = V_43 ;
V_4 -> V_8 = V_8 ;
V_4 -> V_2 . V_45 = & V_45 ;
V_27 = F_24 ( NULL , & V_4 -> V_2 ) ;
if ( F_25 ( V_27 ) )
F_26 ( V_4 ) ;
return V_27 ;
}
static void F_27 ( struct V_54 * V_22 )
{
F_5 ( V_22 , V_55 [ V_22 -> V_56 ] , 1 ) ;
F_5 ( V_22 , V_55 [ V_22 -> V_56 ] , 0 ) ;
}
static void F_28 ( struct V_54 * V_22 )
{
unsigned long V_5 = 0 ;
F_5 ( V_22 , V_55 [ V_22 -> V_56 ] , 0 ) ;
F_5 ( V_22 , V_35 [ V_22 -> V_56 ] , V_22 -> V_57 ) ;
F_5 ( V_22 , V_36 [ V_22 -> V_56 ] , V_22 -> V_36 ) ;
F_5 ( V_22 , V_34 [ V_22 -> V_56 ] , V_22 -> V_34 ) ;
if ( V_22 -> V_8 )
F_4 ( V_22 -> V_8 , V_5 ) ;
if ( V_22 -> V_9 -> V_58 )
F_5 ( V_22 , V_37 [ V_22 -> V_56 ] , V_22 -> V_37 ) ;
if ( V_22 -> V_8 )
F_6 ( V_22 -> V_8 , V_5 ) ;
}
static int F_29 ( struct V_1 * V_2 )
{
struct V_54 * V_22 = F_30 ( V_2 ) ;
unsigned long V_5 = 0 ;
F_18 ( L_4 , V_28 , F_15 ( V_2 -> V_27 ) ) ;
F_28 ( V_22 ) ;
if ( V_22 -> V_8 )
F_4 ( V_22 -> V_8 , V_5 ) ;
F_5 ( V_22 , V_59 [ V_22 -> V_56 ] , 1 ) ;
if ( V_22 -> V_8 )
F_6 ( V_22 -> V_8 , V_5 ) ;
F_27 ( V_22 ) ;
return 0 ;
}
static void F_31 ( struct V_1 * V_2 )
{
struct V_54 * V_22 = F_30 ( V_2 ) ;
unsigned long V_5 = 0 ;
F_18 ( L_4 , V_28 , F_15 ( V_2 -> V_27 ) ) ;
if ( V_22 -> V_8 )
F_4 ( V_22 -> V_8 , V_5 ) ;
F_5 ( V_22 , V_59 [ V_22 -> V_56 ] , 0 ) ;
if ( V_22 -> V_8 )
F_6 ( V_22 -> V_8 , V_5 ) ;
}
static int F_32 ( struct V_1 * V_2 )
{
struct V_54 * V_22 = F_30 ( V_2 ) ;
T_1 V_59 = F_7 ( V_22 , V_59 [ V_22 -> V_56 ] ) ;
F_18 ( L_5 ,
V_28 , F_15 ( V_2 -> V_27 ) , V_59 ) ;
return ! ! V_59 ;
}
static int F_33 ( unsigned long V_20 , struct V_21 * V_22 ,
unsigned long * V_23 )
{
T_5 V_60 ;
unsigned long V_61 ;
unsigned long V_24 = 8 ;
unsigned long V_62 ;
long V_63 ;
V_63 = V_22 -> V_35 - 32 ;
V_62 = 1 << ( V_22 -> V_34 + 1 ) ;
V_61 = ( V_22 -> V_37 ? 1 : 3 ) ;
V_60 = ( T_5 ) ( V_62 * V_61 * V_64 * ( T_5 ) ( V_63 + 33 ) ) ;
V_60 = V_60 - ( V_62 * V_61 * V_22 -> V_36 ) ;
* V_23 = F_34 ( V_64 * V_24 * V_20 * 32 , V_60 ) ;
return 0 ;
}
static int F_35 ( unsigned long V_20 , struct V_21 * V_22 ,
unsigned long * V_23 )
{
T_5 V_60 ;
unsigned long V_24 = 16 ;
long V_63 ;
unsigned long V_65 ;
unsigned long V_61 ;
V_63 = V_22 -> V_35 - 32 ;
V_65 = 1 << ( V_22 -> V_34 + 1 ) ;
V_61 = ( V_22 -> V_37 ? 1 : 3 ) ;
V_60 = ( T_5 ) ( V_65 * V_61 * V_64 * ( T_5 ) ( V_63 + 33 ) ) ;
V_60 = V_60 - ( V_65 * V_61 * V_22 -> V_36 ) ;
* V_23 = F_34 ( V_64 * V_24 * V_20 * 32 , V_60 ) ;
return 0 ;
}
static int F_36 ( unsigned long V_20 ,
struct V_21 * V_22 , unsigned long * V_23 )
{
unsigned long V_62 = ( 1 << V_22 -> V_34 ) ;
unsigned long V_61 ;
T_5 V_60 ;
V_61 = ( V_22 -> V_37 == 1 ) ? 1 : 3 ;
V_60 = ( V_66 * ( 32 + V_22 -> V_35 ) + 32 * V_22 -> V_36 ) * V_62 * V_61 ;
* V_23 = ( unsigned long ) F_34 ( V_20 * V_66 * 32 , V_60 ) ;
return 0 ;
}
static int F_37 ( struct V_54 * V_22 ,
struct V_21 * V_26 )
{
V_26 -> V_35 = F_7 ( V_22 , V_35 [ V_22 -> V_56 ] ) ;
V_26 -> V_36 = F_7 ( V_22 , V_36 [ V_22 -> V_56 ] ) ;
V_26 -> V_34 = F_7 ( V_22 , V_34 [ V_22 -> V_56 ] ) ;
if ( V_22 -> V_9 -> V_58 )
V_26 -> V_37 = F_7 ( V_22 , V_37 [ V_22 -> V_56 ] ) ;
else
V_26 -> V_37 = 1 ;
if ( ! V_26 -> V_35 && ! V_26 -> V_36 && ! V_26 -> V_34 )
return 1 ;
V_22 -> V_57 = V_26 -> V_35 ;
V_22 -> V_36 = V_26 -> V_36 ;
V_22 -> V_34 = V_26 -> V_34 ;
V_22 -> V_37 = V_26 -> V_37 ;
return 0 ;
}
static long F_38 ( struct V_1 * V_2 , unsigned long V_67 ,
unsigned long V_33 , struct V_21 * V_26 )
{
struct V_54 * V_22 = F_30 ( V_2 ) ;
int (* F_39)( unsigned long ,
struct V_21 * , unsigned long * );
struct V_21 V_68 ;
unsigned long V_69 , V_23 = 0 ;
unsigned long V_70 , V_71 = ~ 0 ;
int V_72 ;
F_39 = V_22 -> V_9 -> V_73 ;
for ( V_72 = 0 ; V_72 < V_22 -> V_9 -> V_74 ; V_72 ++ ) {
V_69 = V_23 ;
* V_26 = V_22 -> V_9 -> V_75 [ V_72 ] ;
V_68 = * V_26 ;
F_39 ( V_33 , & V_22 -> V_9 -> V_75 [ V_72 ] , & V_23 ) ;
V_70 = abs ( V_67 - V_23 ) ;
if ( V_70 > V_71 ) {
V_23 = V_69 ;
* V_26 = V_68 ;
break;
}
V_71 = V_70 ;
if ( V_67 == V_23 )
return V_23 ;
}
if ( V_72 == V_22 -> V_9 -> V_74 )
* V_26 = V_68 ;
return V_23 ;
}
static unsigned long F_40 ( struct V_1 * V_2 ,
unsigned long V_25 )
{
struct V_54 * V_22 = F_30 ( V_2 ) ;
unsigned long V_23 = 0 ;
struct V_21 V_26 ;
int (* F_39)( unsigned long ,
struct V_21 * , unsigned long * );
F_39 = V_22 -> V_9 -> V_73 ;
if ( F_37 ( V_22 , & V_26 ) )
return 0 ;
if ( F_39 ( V_25 , & V_26 , & V_23 ) ) {
F_14 ( L_1 ,
F_15 ( V_2 -> V_27 ) , V_28 ) ;
}
F_18 ( L_6 , F_15 ( V_2 -> V_27 ) , V_28 , V_23 ) ;
return V_23 ;
}
static long F_41 ( struct V_1 * V_2 , unsigned long V_23 ,
unsigned long * V_33 )
{
struct V_21 V_26 ;
V_23 = F_38 ( V_2 , V_23 , * V_33 , & V_26 ) ;
F_18 ( L_2 ,
V_28 , F_15 ( V_2 -> V_27 ) ,
V_23 , ( unsigned int ) V_26 . V_34 , ( unsigned int ) V_26 . V_35 ,
( unsigned int ) V_26 . V_36 , ( unsigned int ) V_26 . V_37 ) ;
return V_23 ;
}
static void F_42 ( struct V_54 * V_22 ,
struct V_21 * V_26 )
{
V_22 -> V_57 = V_26 -> V_35 ;
V_22 -> V_36 = V_26 -> V_36 ;
V_22 -> V_34 = V_26 -> V_34 ;
V_22 -> V_37 = V_26 -> V_37 ;
F_28 ( V_22 ) ;
F_27 ( V_22 ) ;
}
static int F_43 ( struct V_1 * V_2 , unsigned long V_23 ,
unsigned long V_25 )
{
struct V_54 * V_22 = F_30 ( V_2 ) ;
struct V_21 V_26 ;
long V_38 ;
int V_76 ( V_77 ) ;
if ( ! V_23 || ! V_25 )
return - V_32 ;
memset ( & V_26 , 0 , sizeof( struct V_21 ) ) ;
V_38 = F_38 ( V_2 , V_23 , V_25 , & V_26 ) ;
if ( ! V_38 )
return - V_32 ;
F_42 ( V_22 , & V_26 ) ;
return 0 ;
}
static struct V_27 * T_2 F_44 (
const char * V_39 , const char * V_40 ,
struct V_41 * V_42 , void T_3 * V_43 , T_1 V_56 ,
T_4 * V_8 )
{
struct V_54 * V_22 ;
struct V_27 * V_27 ;
struct V_44 V_45 ;
if ( F_21 ( ! V_39 || ! V_40 ) )
return F_22 ( - V_32 ) ;
V_22 = F_23 ( sizeof( * V_22 ) , V_46 ) ;
if ( ! V_22 )
return F_22 ( - V_47 ) ;
V_45 . V_39 = V_39 ;
V_45 . V_48 = & V_78 ;
V_45 . V_5 = V_79 | V_50 ;
V_45 . V_51 = & V_40 ;
V_45 . V_52 = 1 ;
V_22 -> V_9 = V_42 ;
V_22 -> V_53 = V_43 ;
V_22 -> V_56 = V_56 ;
V_22 -> V_8 = V_8 ;
V_22 -> V_2 . V_45 = & V_45 ;
V_27 = F_24 ( NULL , & V_22 -> V_2 ) ;
if ( F_25 ( V_27 ) )
F_26 ( V_22 ) ;
return V_27 ;
}
static void T_2 F_45 (
struct V_80 * V_81 , const char * V_82 ,
struct V_41 * V_42 , void T_3 * V_43 ,
T_4 * V_8 )
{
struct V_83 * V_84 ;
int V_85 ;
V_84 = F_23 ( sizeof( * V_84 ) , V_46 ) ;
if ( ! V_84 )
return;
V_84 -> V_86 = V_87 ;
V_84 -> V_88 = F_23 ( V_87 * sizeof( struct V_27 * ) ,
V_46 ) ;
if ( ! V_84 -> V_88 ) {
F_26 ( V_84 ) ;
return;
}
for ( V_85 = 0 ; V_85 < V_87 ; V_85 ++ ) {
struct V_27 * V_27 ;
const char * V_89 ;
if ( F_46 ( V_81 , L_7 ,
V_85 , & V_89 ) ) {
break;
}
if ( * V_89 == '\0' )
continue;
V_27 = F_44 ( V_89 , V_82 ,
V_42 , V_43 , V_85 , V_8 ) ;
if ( ! F_25 ( V_27 ) ) {
V_84 -> V_88 [ V_85 ] = V_27 ;
F_18 ( L_8 ,
F_15 ( V_27 ) ,
F_15 ( F_47 ( V_27 ) ) ,
( unsigned int ) F_48 ( V_27 ) ) ;
}
}
F_49 ( V_81 , V_90 , V_84 ) ;
}
static void T_2 F_50 ( struct V_80 * V_81 )
{
const struct V_91 * V_92 ;
struct V_27 * V_27 ;
const char * V_82 , * V_93 ;
void T_3 * V_43 ;
T_4 * V_8 ;
V_92 = F_51 ( V_94 , V_81 ) ;
if ( F_21 ( ! V_92 ) )
return;
V_43 = F_52 ( V_81 , 0 ) ;
if ( ! V_43 )
return;
V_93 = F_53 ( V_81 , 0 ) ;
if ( ! V_93 )
return;
V_82 = F_54 ( V_46 , L_9 , V_81 -> V_39 ) ;
if ( ! V_82 )
return;
V_8 = F_23 ( sizeof( * V_8 ) , V_46 ) ;
if ( ! V_8 )
goto V_95;
F_55 ( V_8 ) ;
V_27 = F_20 ( V_82 , V_93 ,
(struct V_41 * ) V_92 -> V_9 , V_43 , V_8 ) ;
if ( F_25 ( V_27 ) )
goto V_95;
else
F_18 ( L_8 ,
F_15 ( V_27 ) ,
F_15 ( F_47 ( V_27 ) ) ,
( unsigned int ) F_48 ( V_27 ) ) ;
F_45 ( V_81 , V_82 ,
(struct V_41 * ) V_92 -> V_9 ,
V_43 , V_8 ) ;
V_95:
F_26 ( V_82 ) ;
}
