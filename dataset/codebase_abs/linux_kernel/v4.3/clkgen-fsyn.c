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
F_5 ( V_4 , V_16 , ! V_4 -> V_9 -> V_17 ) ;
if ( V_4 -> V_8 )
F_6 ( V_4 -> V_8 , V_5 ) ;
if ( V_4 -> V_9 -> V_18 )
while ( ! F_7 ( V_4 , V_19 ) ) {
if ( F_8 ( V_7 , V_6 ) )
return - V_20 ;
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
F_5 ( V_4 , V_16 , V_4 -> V_9 -> V_17 ) ;
if ( V_4 -> V_9 -> V_10 )
F_5 ( V_4 , V_11 , 0 ) ;
if ( V_4 -> V_8 )
F_6 ( V_4 -> V_8 , V_5 ) ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_16 = F_7 ( V_4 , V_16 ) ;
return V_4 -> V_9 -> V_17 ? ! V_16 : ! ! V_16 ;
}
static int F_12 ( unsigned long V_21 , struct V_22 * V_23 ,
unsigned long * V_24 )
{
unsigned long V_25 = V_23 -> V_15 + 16 ;
* V_24 = V_21 * V_25 ;
return 0 ;
}
static unsigned long F_13 ( struct V_1 * V_2 ,
unsigned long V_26 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_24 = 0 ;
struct V_22 V_27 ;
V_27 . V_15 = F_7 ( V_4 , V_15 ) ;
if ( F_12 ( V_26 , & V_27 , & V_24 ) )
F_14 ( L_1 ,
F_15 ( V_2 ) , V_28 ) ;
V_4 -> V_15 = V_27 . V_15 ;
return V_24 ;
}
static int F_16 ( unsigned long V_21 ,
unsigned long V_29 , struct V_22 * V_23 )
{
unsigned long V_30 = 1 , V_31 ;
if ( V_29 < 384000000 || V_29 > 660000000 )
return - V_32 ;
if ( V_21 > 40000000 )
return - V_32 ;
V_21 /= 1000 ;
V_29 /= 1000 ;
V_31 = V_29 * V_30 / V_21 ;
if ( V_31 < 16 )
V_31 = 16 ;
V_23 -> V_15 = V_31 - 16 ;
return 0 ;
}
static long F_17 ( struct V_1 * V_2 , unsigned long V_24
, unsigned long * V_33 )
{
struct V_22 V_27 ;
if ( ! F_16 ( * V_33 , V_24 , & V_27 ) )
F_12 ( * V_33 , & V_27 , & V_24 ) ;
F_18 ( L_2 ,
V_28 , F_15 ( V_2 ) ,
V_24 , ( unsigned int ) V_27 . V_34 ,
( unsigned int ) V_27 . V_35 ,
( unsigned int ) V_27 . V_36 , ( unsigned int ) V_27 . V_37 ) ;
return V_24 ;
}
static int F_19 ( struct V_1 * V_2 , unsigned long V_24 ,
unsigned long V_26 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_22 V_27 ;
long V_38 = 0 ;
unsigned long V_5 = 0 ;
if ( ! V_24 || ! V_26 )
return - V_32 ;
if ( ! F_16 ( V_26 , V_24 , & V_27 ) )
F_12 ( V_26 , & V_27 , & V_38 ) ;
F_18 ( L_3 ,
V_28 , F_15 ( V_2 ) ,
V_38 , ( unsigned int ) V_27 . V_15 ) ;
if ( ! V_38 )
return - V_32 ;
V_4 -> V_15 = V_27 . V_15 ;
if ( V_4 -> V_8 )
F_4 ( V_4 -> V_8 , V_5 ) ;
F_5 ( V_4 , V_15 , V_4 -> V_15 ) ;
if ( V_4 -> V_8 )
F_6 ( V_4 -> V_8 , V_5 ) ;
return 0 ;
}
static struct V_39 * T_2 F_20 (
const char * V_40 , const char * V_41 ,
struct V_42 * V_43 , void T_3 * V_44 ,
T_4 * V_8 )
{
struct V_3 * V_4 ;
struct V_39 * V_39 ;
struct V_45 V_46 ;
if ( F_21 ( ! V_40 || ! V_41 ) )
return F_22 ( - V_32 ) ;
V_4 = F_23 ( sizeof( * V_4 ) , V_47 ) ;
if ( ! V_4 )
return F_22 ( - V_48 ) ;
V_46 . V_40 = V_40 ;
V_46 . V_49 = V_43 -> V_50 ;
V_46 . V_5 = V_51 | V_52 ;
V_46 . V_53 = & V_41 ;
V_46 . V_54 = 1 ;
V_4 -> V_9 = V_43 ;
V_4 -> V_55 = V_44 ;
V_4 -> V_8 = V_8 ;
V_4 -> V_2 . V_46 = & V_46 ;
V_39 = F_24 ( NULL , & V_4 -> V_2 ) ;
if ( F_25 ( V_39 ) )
F_26 ( V_4 ) ;
return V_39 ;
}
static void F_27 ( struct V_56 * V_23 )
{
F_5 ( V_23 , V_57 [ V_23 -> V_58 ] , 1 ) ;
F_5 ( V_23 , V_57 [ V_23 -> V_58 ] , 0 ) ;
}
static void F_28 ( struct V_56 * V_23 )
{
unsigned long V_5 = 0 ;
F_5 ( V_23 , V_57 [ V_23 -> V_58 ] , 0 ) ;
F_5 ( V_23 , V_35 [ V_23 -> V_58 ] , V_23 -> V_59 ) ;
F_5 ( V_23 , V_36 [ V_23 -> V_58 ] , V_23 -> V_36 ) ;
F_5 ( V_23 , V_34 [ V_23 -> V_58 ] , V_23 -> V_34 ) ;
if ( V_23 -> V_8 )
F_4 ( V_23 -> V_8 , V_5 ) ;
if ( V_23 -> V_9 -> V_60 )
F_5 ( V_23 , V_37 [ V_23 -> V_58 ] , V_23 -> V_37 ) ;
if ( V_23 -> V_8 )
F_6 ( V_23 -> V_8 , V_5 ) ;
}
static int F_29 ( struct V_1 * V_2 )
{
struct V_56 * V_23 = F_30 ( V_2 ) ;
unsigned long V_5 = 0 ;
F_18 ( L_4 , V_28 , F_15 ( V_2 ) ) ;
F_28 ( V_23 ) ;
if ( V_23 -> V_8 )
F_4 ( V_23 -> V_8 , V_5 ) ;
F_5 ( V_23 , V_61 [ V_23 -> V_58 ] , ! V_23 -> V_9 -> V_62 ) ;
if ( V_23 -> V_9 -> V_63 )
F_5 ( V_23 , V_64 [ V_23 -> V_58 ] , 0 ) ;
if ( V_23 -> V_8 )
F_6 ( V_23 -> V_8 , V_5 ) ;
F_27 ( V_23 ) ;
return 0 ;
}
static void F_31 ( struct V_1 * V_2 )
{
struct V_56 * V_23 = F_30 ( V_2 ) ;
unsigned long V_5 = 0 ;
F_18 ( L_4 , V_28 , F_15 ( V_2 ) ) ;
if ( V_23 -> V_8 )
F_4 ( V_23 -> V_8 , V_5 ) ;
F_5 ( V_23 , V_61 [ V_23 -> V_58 ] , V_23 -> V_9 -> V_62 ) ;
if ( V_23 -> V_8 )
F_6 ( V_23 -> V_8 , V_5 ) ;
}
static int F_32 ( struct V_1 * V_2 )
{
struct V_56 * V_23 = F_30 ( V_2 ) ;
T_1 V_61 = F_7 ( V_23 , V_61 [ V_23 -> V_58 ] ) ;
F_18 ( L_5 ,
V_28 , F_15 ( V_2 ) , V_61 ) ;
return V_23 -> V_9 -> V_62 ? ! V_61 : ! ! V_61 ;
}
static int F_33 ( unsigned long V_21 , const struct V_22 * V_23 ,
unsigned long * V_24 )
{
T_5 V_65 ;
unsigned long V_66 ;
unsigned long V_25 = 8 ;
unsigned long V_67 ;
long V_68 ;
V_68 = V_23 -> V_35 - 32 ;
V_67 = 1 << ( V_23 -> V_34 + 1 ) ;
V_66 = ( V_23 -> V_37 ? 1 : 3 ) ;
V_65 = ( T_5 ) ( V_67 * V_66 * V_69 * ( T_5 ) ( V_68 + 33 ) ) ;
V_65 = V_65 - ( V_67 * V_66 * V_23 -> V_36 ) ;
* V_24 = F_34 ( V_69 * V_25 * V_21 * 32 , V_65 ) ;
return 0 ;
}
static int F_35 ( unsigned long V_21 , const struct V_22 * V_23 ,
unsigned long * V_24 )
{
T_5 V_65 ;
unsigned long V_25 = 16 ;
long V_68 ;
unsigned long V_70 ;
unsigned long V_66 ;
V_68 = V_23 -> V_35 - 32 ;
V_70 = 1 << ( V_23 -> V_34 + 1 ) ;
V_66 = ( V_23 -> V_37 ? 1 : 3 ) ;
V_65 = ( T_5 ) ( V_70 * V_66 * V_69 * ( T_5 ) ( V_68 + 33 ) ) ;
V_65 = V_65 - ( V_70 * V_66 * V_23 -> V_36 ) ;
* V_24 = F_34 ( V_69 * V_25 * V_21 * 32 , V_65 ) ;
return 0 ;
}
static int F_36 ( unsigned long V_21 ,
const struct V_22 * V_23 , unsigned long * V_24 )
{
unsigned long V_67 = ( 1 << V_23 -> V_34 ) ;
unsigned long V_66 ;
T_5 V_65 ;
V_66 = ( V_23 -> V_37 == 1 ) ? 1 : 3 ;
V_65 = ( V_71 * ( 32 + V_23 -> V_35 ) + 32 * V_23 -> V_36 ) * V_67 * V_66 ;
* V_24 = ( unsigned long ) F_34 ( V_21 * V_71 * 32 , V_65 ) ;
return 0 ;
}
static int F_37 ( struct V_56 * V_23 ,
struct V_22 * V_27 )
{
V_27 -> V_35 = F_7 ( V_23 , V_35 [ V_23 -> V_58 ] ) ;
V_27 -> V_36 = F_7 ( V_23 , V_36 [ V_23 -> V_58 ] ) ;
V_27 -> V_34 = F_7 ( V_23 , V_34 [ V_23 -> V_58 ] ) ;
if ( V_23 -> V_9 -> V_60 )
V_27 -> V_37 = F_7 ( V_23 , V_37 [ V_23 -> V_58 ] ) ;
else
V_27 -> V_37 = 1 ;
if ( ! V_27 -> V_35 && ! V_27 -> V_36 && ! V_27 -> V_34 )
return 1 ;
V_23 -> V_59 = V_27 -> V_35 ;
V_23 -> V_36 = V_27 -> V_36 ;
V_23 -> V_34 = V_27 -> V_34 ;
V_23 -> V_37 = V_27 -> V_37 ;
return 0 ;
}
static long F_38 ( struct V_1 * V_2 , unsigned long V_72 ,
unsigned long V_33 , struct V_22 * V_27 )
{
struct V_56 * V_23 = F_30 ( V_2 ) ;
int (* F_39)( unsigned long ,
const struct V_22 * , unsigned long * );
struct V_22 V_73 ;
unsigned long V_74 , V_24 = 0 ;
unsigned long V_75 , V_76 = ~ 0 ;
int V_77 ;
F_39 = V_23 -> V_9 -> V_78 ;
for ( V_77 = 0 ; V_77 < V_23 -> V_9 -> V_79 ; V_77 ++ ) {
V_74 = V_24 ;
* V_27 = V_23 -> V_9 -> V_80 [ V_77 ] ;
V_73 = * V_27 ;
F_39 ( V_33 , & V_23 -> V_9 -> V_80 [ V_77 ] , & V_24 ) ;
V_75 = abs ( V_72 - V_24 ) ;
if ( V_75 > V_76 ) {
V_24 = V_74 ;
* V_27 = V_73 ;
break;
}
V_76 = V_75 ;
if ( V_72 == V_24 )
return V_24 ;
}
if ( V_77 == V_23 -> V_9 -> V_79 )
* V_27 = V_73 ;
return V_24 ;
}
static unsigned long F_40 ( struct V_1 * V_2 ,
unsigned long V_26 )
{
struct V_56 * V_23 = F_30 ( V_2 ) ;
unsigned long V_24 = 0 ;
struct V_22 V_27 ;
int (* F_39)( unsigned long ,
const struct V_22 * , unsigned long * );
F_39 = V_23 -> V_9 -> V_78 ;
if ( F_37 ( V_23 , & V_27 ) )
return 0 ;
if ( F_39 ( V_26 , & V_27 , & V_24 ) ) {
F_14 ( L_1 ,
F_15 ( V_2 ) , V_28 ) ;
}
F_18 ( L_6 , F_15 ( V_2 ) , V_28 , V_24 ) ;
return V_24 ;
}
static long F_41 ( struct V_1 * V_2 , unsigned long V_24 ,
unsigned long * V_33 )
{
struct V_22 V_27 ;
V_24 = F_38 ( V_2 , V_24 , * V_33 , & V_27 ) ;
F_18 ( L_2 ,
V_28 , F_15 ( V_2 ) ,
V_24 , ( unsigned int ) V_27 . V_34 , ( unsigned int ) V_27 . V_35 ,
( unsigned int ) V_27 . V_36 , ( unsigned int ) V_27 . V_37 ) ;
return V_24 ;
}
static void F_42 ( struct V_56 * V_23 ,
struct V_22 * V_27 )
{
V_23 -> V_59 = V_27 -> V_35 ;
V_23 -> V_36 = V_27 -> V_36 ;
V_23 -> V_34 = V_27 -> V_34 ;
V_23 -> V_37 = V_27 -> V_37 ;
F_28 ( V_23 ) ;
F_27 ( V_23 ) ;
}
static int F_43 ( struct V_1 * V_2 , unsigned long V_24 ,
unsigned long V_26 )
{
struct V_56 * V_23 = F_30 ( V_2 ) ;
struct V_22 V_27 ;
long V_38 ;
int V_81 ( V_82 ) ;
if ( ! V_24 || ! V_26 )
return - V_32 ;
memset ( & V_27 , 0 , sizeof( struct V_22 ) ) ;
V_38 = F_38 ( V_2 , V_24 , V_26 , & V_27 ) ;
if ( ! V_38 )
return - V_32 ;
F_42 ( V_23 , & V_27 ) ;
return 0 ;
}
static struct V_39 * T_2 F_44 (
const char * V_40 , const char * V_41 ,
struct V_42 * V_43 , void T_3 * V_44 , T_1 V_58 ,
T_4 * V_8 )
{
struct V_56 * V_23 ;
struct V_39 * V_39 ;
struct V_45 V_46 ;
if ( F_21 ( ! V_40 || ! V_41 ) )
return F_22 ( - V_32 ) ;
V_23 = F_23 ( sizeof( * V_23 ) , V_47 ) ;
if ( ! V_23 )
return F_22 ( - V_48 ) ;
V_46 . V_40 = V_40 ;
V_46 . V_49 = & V_83 ;
V_46 . V_5 = V_52 | V_51 ;
V_46 . V_53 = & V_41 ;
V_46 . V_54 = 1 ;
V_23 -> V_9 = V_43 ;
V_23 -> V_55 = V_44 ;
V_23 -> V_58 = V_58 ;
V_23 -> V_8 = V_8 ;
V_23 -> V_2 . V_46 = & V_46 ;
V_39 = F_24 ( NULL , & V_23 -> V_2 ) ;
if ( F_25 ( V_39 ) )
F_26 ( V_23 ) ;
return V_39 ;
}
static void T_2 F_45 (
struct V_84 * V_85 , const char * V_86 ,
struct V_42 * V_43 , void T_3 * V_44 ,
T_4 * V_8 )
{
struct V_87 * V_88 ;
int V_89 ;
V_88 = F_23 ( sizeof( * V_88 ) , V_47 ) ;
if ( ! V_88 )
return;
V_88 -> V_90 = V_91 ;
V_88 -> V_92 = F_23 ( V_91 * sizeof( struct V_39 * ) ,
V_47 ) ;
if ( ! V_88 -> V_92 ) {
F_26 ( V_88 ) ;
return;
}
for ( V_89 = 0 ; V_89 < V_91 ; V_89 ++ ) {
struct V_39 * V_39 ;
const char * V_93 ;
if ( F_46 ( V_85 , L_7 ,
V_89 , & V_93 ) ) {
break;
}
if ( * V_93 == '\0' )
continue;
V_39 = F_44 ( V_93 , V_86 ,
V_43 , V_44 , V_89 , V_8 ) ;
if ( ! F_25 ( V_39 ) ) {
V_88 -> V_92 [ V_89 ] = V_39 ;
F_18 ( L_8 ,
F_47 ( V_39 ) ,
F_47 ( F_48 ( V_39 ) ) ,
( unsigned int ) F_49 ( V_39 ) ) ;
}
}
F_50 ( V_85 , V_94 , V_88 ) ;
}
static void T_2 F_51 ( struct V_84 * V_85 )
{
const struct V_95 * V_96 ;
struct V_39 * V_39 ;
const char * V_86 , * V_97 ;
void T_3 * V_44 ;
T_4 * V_8 ;
V_96 = F_52 ( V_98 , V_85 ) ;
if ( F_21 ( ! V_96 ) )
return;
V_44 = F_53 ( V_85 , 0 ) ;
if ( ! V_44 )
return;
V_97 = F_54 ( V_85 , 0 ) ;
if ( ! V_97 )
return;
V_86 = F_55 ( V_47 , L_9 , V_85 -> V_40 ) ;
if ( ! V_86 )
return;
V_8 = F_23 ( sizeof( * V_8 ) , V_47 ) ;
if ( ! V_8 )
goto V_99;
F_56 ( V_8 ) ;
V_39 = F_20 ( V_86 , V_97 ,
(struct V_42 * ) V_96 -> V_9 , V_44 , V_8 ) ;
if ( F_25 ( V_39 ) )
goto V_99;
else
F_18 ( L_8 ,
F_47 ( V_39 ) ,
F_47 ( F_48 ( V_39 ) ) ,
( unsigned int ) F_49 ( V_39 ) ) ;
F_45 ( V_85 , V_86 ,
(struct V_42 * ) V_96 -> V_9 ,
V_44 , V_8 ) ;
V_99:
F_26 ( V_86 ) ;
}
