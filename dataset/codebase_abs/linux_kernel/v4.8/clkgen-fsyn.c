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
static long F_17 ( struct V_1 * V_2 ,
unsigned long V_24 ,
unsigned long * V_33 )
{
struct V_22 V_27 ;
if ( F_16 ( * V_33 , V_24 , & V_27 ) )
return V_24 ;
F_12 ( * V_33 , & V_27 , & V_24 ) ;
F_18 ( L_2 ,
V_28 , F_15 ( V_2 ) ,
V_24 , ( unsigned int ) V_27 . V_15 ) ;
return V_24 ;
}
static int F_19 ( struct V_1 * V_2 , unsigned long V_24 ,
unsigned long V_26 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_22 V_27 ;
long V_34 = 0 ;
unsigned long V_5 = 0 ;
int V_35 ;
if ( ! V_24 || ! V_26 )
return - V_32 ;
V_35 = F_16 ( V_26 , V_24 , & V_27 ) ;
if ( V_35 )
return V_35 ;
F_12 ( V_26 , & V_27 , & V_34 ) ;
F_18 ( L_3 ,
V_28 , F_15 ( V_2 ) ,
V_34 , ( unsigned int ) V_27 . V_15 ) ;
if ( ! V_34 )
return - V_32 ;
V_4 -> V_15 = V_27 . V_15 ;
if ( V_4 -> V_8 )
F_4 ( V_4 -> V_8 , V_5 ) ;
F_5 ( V_4 , V_15 , V_4 -> V_15 ) ;
if ( V_4 -> V_8 )
F_6 ( V_4 -> V_8 , V_5 ) ;
return 0 ;
}
static struct V_36 * T_2 F_20 (
const char * V_37 , const char * V_38 ,
struct V_39 * V_40 , void T_3 * V_41 ,
T_4 * V_8 )
{
struct V_3 * V_4 ;
struct V_36 * V_36 ;
struct V_42 V_43 ;
if ( F_21 ( ! V_37 || ! V_38 ) )
return F_22 ( - V_32 ) ;
V_4 = F_23 ( sizeof( * V_4 ) , V_44 ) ;
if ( ! V_4 )
return F_22 ( - V_45 ) ;
V_43 . V_37 = V_37 ;
V_43 . V_46 = V_40 -> V_47 ;
V_43 . V_5 = V_48 | V_49 ;
V_43 . V_50 = & V_38 ;
V_43 . V_51 = 1 ;
V_4 -> V_9 = V_40 ;
V_4 -> V_52 = V_41 ;
V_4 -> V_8 = V_8 ;
V_4 -> V_2 . V_43 = & V_43 ;
V_36 = F_24 ( NULL , & V_4 -> V_2 ) ;
if ( F_25 ( V_36 ) )
F_26 ( V_4 ) ;
return V_36 ;
}
static void F_27 ( struct V_53 * V_23 )
{
F_5 ( V_23 , V_54 [ V_23 -> V_55 ] , 1 ) ;
F_5 ( V_23 , V_54 [ V_23 -> V_55 ] , 0 ) ;
}
static void F_28 ( struct V_53 * V_23 )
{
unsigned long V_5 = 0 ;
F_5 ( V_23 , V_54 [ V_23 -> V_55 ] , 0 ) ;
F_5 ( V_23 , V_56 [ V_23 -> V_55 ] , V_23 -> V_57 ) ;
F_5 ( V_23 , V_58 [ V_23 -> V_55 ] , V_23 -> V_58 ) ;
F_5 ( V_23 , V_59 [ V_23 -> V_55 ] , V_23 -> V_59 ) ;
if ( V_23 -> V_8 )
F_4 ( V_23 -> V_8 , V_5 ) ;
if ( V_23 -> V_9 -> V_60 )
F_5 ( V_23 , V_61 [ V_23 -> V_55 ] , V_23 -> V_61 ) ;
if ( V_23 -> V_8 )
F_6 ( V_23 -> V_8 , V_5 ) ;
}
static int F_29 ( struct V_1 * V_2 )
{
struct V_53 * V_23 = F_30 ( V_2 ) ;
unsigned long V_5 = 0 ;
F_18 ( L_4 , V_28 , F_15 ( V_2 ) ) ;
F_28 ( V_23 ) ;
if ( V_23 -> V_8 )
F_4 ( V_23 -> V_8 , V_5 ) ;
F_5 ( V_23 , V_62 [ V_23 -> V_55 ] , ! V_23 -> V_9 -> V_63 ) ;
if ( V_23 -> V_9 -> V_64 )
F_5 ( V_23 , V_65 [ V_23 -> V_55 ] , 0 ) ;
if ( V_23 -> V_8 )
F_6 ( V_23 -> V_8 , V_5 ) ;
F_27 ( V_23 ) ;
return 0 ;
}
static void F_31 ( struct V_1 * V_2 )
{
struct V_53 * V_23 = F_30 ( V_2 ) ;
unsigned long V_5 = 0 ;
F_18 ( L_4 , V_28 , F_15 ( V_2 ) ) ;
if ( V_23 -> V_8 )
F_4 ( V_23 -> V_8 , V_5 ) ;
F_5 ( V_23 , V_62 [ V_23 -> V_55 ] , V_23 -> V_9 -> V_63 ) ;
if ( V_23 -> V_8 )
F_6 ( V_23 -> V_8 , V_5 ) ;
}
static int F_32 ( struct V_1 * V_2 )
{
struct V_53 * V_23 = F_30 ( V_2 ) ;
T_1 V_62 = F_7 ( V_23 , V_62 [ V_23 -> V_55 ] ) ;
F_18 ( L_5 ,
V_28 , F_15 ( V_2 ) , V_62 ) ;
return V_23 -> V_9 -> V_63 ? ! V_62 : ! ! V_62 ;
}
static int F_33 ( unsigned long V_21 , const struct V_22 * V_23 ,
unsigned long * V_24 )
{
T_5 V_66 ;
unsigned long V_67 ;
unsigned long V_25 = 8 ;
unsigned long V_68 ;
long V_69 ;
V_69 = V_23 -> V_56 - 32 ;
V_68 = 1 << ( V_23 -> V_59 + 1 ) ;
V_67 = ( V_23 -> V_61 ? 1 : 3 ) ;
V_66 = ( T_5 ) ( V_68 * V_67 * V_70 * ( T_5 ) ( V_69 + 33 ) ) ;
V_66 = V_66 - ( V_68 * V_67 * V_23 -> V_58 ) ;
* V_24 = F_34 ( V_70 * V_25 * V_21 * 32 , V_66 ) ;
return 0 ;
}
static int F_35 ( unsigned long V_21 , const struct V_22 * V_23 ,
unsigned long * V_24 )
{
T_5 V_66 ;
unsigned long V_25 = 16 ;
long V_69 ;
unsigned long V_71 ;
unsigned long V_67 ;
V_69 = V_23 -> V_56 - 32 ;
V_71 = 1 << ( V_23 -> V_59 + 1 ) ;
V_67 = ( V_23 -> V_61 ? 1 : 3 ) ;
V_66 = ( T_5 ) ( V_71 * V_67 * V_70 * ( T_5 ) ( V_69 + 33 ) ) ;
V_66 = V_66 - ( V_71 * V_67 * V_23 -> V_58 ) ;
* V_24 = F_34 ( V_70 * V_25 * V_21 * 32 , V_66 ) ;
return 0 ;
}
static int F_36 ( unsigned long V_21 ,
const struct V_22 * V_23 , unsigned long * V_24 )
{
unsigned long V_68 = ( 1 << V_23 -> V_59 ) ;
unsigned long V_67 ;
T_5 V_66 ;
V_67 = ( V_23 -> V_61 == 1 ) ? 1 : 3 ;
V_66 = ( V_72 * ( 32 + V_23 -> V_56 ) + 32 * V_23 -> V_58 ) * V_68 * V_67 ;
* V_24 = ( unsigned long ) F_34 ( V_21 * V_72 * 32 , V_66 ) ;
return 0 ;
}
static int F_37 ( struct V_53 * V_23 ,
struct V_22 * V_27 )
{
V_27 -> V_56 = F_7 ( V_23 , V_56 [ V_23 -> V_55 ] ) ;
V_27 -> V_58 = F_7 ( V_23 , V_58 [ V_23 -> V_55 ] ) ;
V_27 -> V_59 = F_7 ( V_23 , V_59 [ V_23 -> V_55 ] ) ;
if ( V_23 -> V_9 -> V_60 )
V_27 -> V_61 = F_7 ( V_23 , V_61 [ V_23 -> V_55 ] ) ;
else
V_27 -> V_61 = 1 ;
if ( ! V_27 -> V_56 && ! V_27 -> V_58 && ! V_27 -> V_59 )
return 1 ;
V_23 -> V_57 = V_27 -> V_56 ;
V_23 -> V_58 = V_27 -> V_58 ;
V_23 -> V_59 = V_27 -> V_59 ;
V_23 -> V_61 = V_27 -> V_61 ;
return 0 ;
}
static long F_38 ( struct V_1 * V_2 , unsigned long V_73 ,
unsigned long V_33 , struct V_22 * V_27 )
{
struct V_53 * V_23 = F_30 ( V_2 ) ;
int (* F_39)( unsigned long ,
const struct V_22 * , unsigned long * );
struct V_22 V_74 ;
unsigned long V_75 , V_24 = 0 ;
unsigned long V_76 , V_77 = ~ 0 ;
int V_78 ;
F_39 = V_23 -> V_9 -> V_79 ;
for ( V_78 = 0 ; V_78 < V_23 -> V_9 -> V_80 ; V_78 ++ ) {
V_75 = V_24 ;
* V_27 = V_23 -> V_9 -> V_81 [ V_78 ] ;
V_74 = * V_27 ;
F_39 ( V_33 , & V_23 -> V_9 -> V_81 [ V_78 ] , & V_24 ) ;
V_76 = abs ( V_73 - V_24 ) ;
if ( V_76 > V_77 ) {
V_24 = V_75 ;
* V_27 = V_74 ;
break;
}
V_77 = V_76 ;
if ( V_73 == V_24 )
return V_24 ;
}
if ( V_78 == V_23 -> V_9 -> V_80 )
* V_27 = V_74 ;
return V_24 ;
}
static unsigned long F_40 ( struct V_1 * V_2 ,
unsigned long V_26 )
{
struct V_53 * V_23 = F_30 ( V_2 ) ;
unsigned long V_24 = 0 ;
struct V_22 V_27 ;
int (* F_39)( unsigned long ,
const struct V_22 * , unsigned long * );
F_39 = V_23 -> V_9 -> V_79 ;
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
F_18 ( L_7 ,
V_28 , F_15 ( V_2 ) ,
V_24 , ( unsigned int ) V_27 . V_59 , ( unsigned int ) V_27 . V_56 ,
( unsigned int ) V_27 . V_58 , ( unsigned int ) V_27 . V_61 ) ;
return V_24 ;
}
static void F_42 ( struct V_53 * V_23 ,
struct V_22 * V_27 )
{
V_23 -> V_57 = V_27 -> V_56 ;
V_23 -> V_58 = V_27 -> V_58 ;
V_23 -> V_59 = V_27 -> V_59 ;
V_23 -> V_61 = V_27 -> V_61 ;
F_28 ( V_23 ) ;
F_27 ( V_23 ) ;
}
static int F_43 ( struct V_1 * V_2 , unsigned long V_24 ,
unsigned long V_26 )
{
struct V_53 * V_23 = F_30 ( V_2 ) ;
struct V_22 V_27 ;
long V_34 ;
int V_82 ( V_83 ) ;
if ( ! V_24 || ! V_26 )
return - V_32 ;
memset ( & V_27 , 0 , sizeof( struct V_22 ) ) ;
V_34 = F_38 ( V_2 , V_24 , V_26 , & V_27 ) ;
if ( ! V_34 )
return - V_32 ;
F_42 ( V_23 , & V_27 ) ;
return 0 ;
}
static struct V_36 * T_2 F_44 (
const char * V_37 , const char * V_38 ,
struct V_39 * V_40 , void T_3 * V_41 , T_1 V_55 ,
unsigned long V_5 , T_4 * V_8 )
{
struct V_53 * V_23 ;
struct V_36 * V_36 ;
struct V_42 V_43 ;
if ( F_21 ( ! V_37 || ! V_38 ) )
return F_22 ( - V_32 ) ;
V_23 = F_23 ( sizeof( * V_23 ) , V_44 ) ;
if ( ! V_23 )
return F_22 ( - V_45 ) ;
V_43 . V_37 = V_37 ;
V_43 . V_46 = & V_84 ;
V_43 . V_5 = V_5 | V_49 | V_48 ;
V_43 . V_50 = & V_38 ;
V_43 . V_51 = 1 ;
V_23 -> V_9 = V_40 ;
V_23 -> V_52 = V_41 ;
V_23 -> V_55 = V_55 ;
V_23 -> V_8 = V_8 ;
V_23 -> V_2 . V_43 = & V_43 ;
V_36 = F_24 ( NULL , & V_23 -> V_2 ) ;
if ( F_25 ( V_36 ) )
F_26 ( V_23 ) ;
return V_36 ;
}
static void T_2 F_45 (
struct V_85 * V_86 , const char * V_87 ,
struct V_39 * V_40 , void T_3 * V_41 ,
T_4 * V_8 )
{
struct V_88 * V_89 ;
int V_90 ;
V_89 = F_23 ( sizeof( * V_89 ) , V_44 ) ;
if ( ! V_89 )
return;
V_89 -> V_91 = V_92 ;
V_89 -> V_93 = F_23 ( V_92 * sizeof( struct V_36 * ) ,
V_44 ) ;
if ( ! V_89 -> V_93 ) {
F_26 ( V_89 ) ;
return;
}
for ( V_90 = 0 ; V_90 < V_92 ; V_90 ++ ) {
struct V_36 * V_36 ;
const char * V_94 ;
unsigned long V_5 = 0 ;
if ( F_46 ( V_86 , L_8 ,
V_90 , & V_94 ) ) {
break;
}
if ( * V_94 == '\0' )
continue;
F_47 ( V_86 , V_90 , & V_5 ) ;
V_36 = F_44 ( V_94 , V_87 ,
V_40 , V_41 , V_90 ,
V_5 , V_8 ) ;
if ( ! F_25 ( V_36 ) ) {
V_89 -> V_93 [ V_90 ] = V_36 ;
F_18 ( L_9 ,
F_48 ( V_36 ) ,
F_48 ( F_49 ( V_36 ) ) ,
( unsigned int ) F_50 ( V_36 ) ) ;
}
}
F_51 ( V_86 , V_95 , V_89 ) ;
}
static void T_2 F_52 ( struct V_85 * V_86 )
{
const struct V_96 * V_97 ;
struct V_36 * V_36 ;
const char * V_87 , * V_98 ;
void T_3 * V_41 ;
T_4 * V_8 ;
V_97 = F_53 ( V_99 , V_86 ) ;
if ( F_21 ( ! V_97 ) )
return;
V_41 = F_54 ( V_86 , 0 ) ;
if ( ! V_41 )
return;
V_98 = F_55 ( V_86 , 0 ) ;
if ( ! V_98 )
return;
V_87 = F_56 ( V_44 , L_10 , V_86 -> V_37 ) ;
if ( ! V_87 )
return;
V_8 = F_23 ( sizeof( * V_8 ) , V_44 ) ;
if ( ! V_8 )
goto V_100;
F_57 ( V_8 ) ;
V_36 = F_20 ( V_87 , V_98 ,
(struct V_39 * ) V_97 -> V_9 , V_41 , V_8 ) ;
if ( F_25 ( V_36 ) )
goto V_100;
else
F_18 ( L_9 ,
F_48 ( V_36 ) ,
F_48 ( F_49 ( V_36 ) ) ,
( unsigned int ) F_50 ( V_36 ) ) ;
F_45 ( V_86 , V_87 ,
(struct V_39 * ) V_97 -> V_9 ,
V_41 , V_8 ) ;
V_100:
F_26 ( V_87 ) ;
}
