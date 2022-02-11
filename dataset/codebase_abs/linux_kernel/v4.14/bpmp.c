static inline struct V_1 *
F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 . V_3 ) ;
}
struct V_1 * F_3 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
struct V_1 * V_9 ;
struct V_10 * V_11 ;
V_11 = F_4 ( V_6 -> V_12 , L_1 , 0 ) ;
if ( ! V_11 )
return F_5 ( - V_13 ) ;
V_8 = F_6 ( V_11 ) ;
if ( ! V_8 ) {
V_9 = F_5 ( - V_14 ) ;
goto V_15;
}
V_9 = F_7 ( V_8 ) ;
if ( ! V_9 ) {
V_9 = F_5 ( - V_16 ) ;
F_8 ( & V_8 -> V_6 ) ;
goto V_15;
}
V_15:
F_9 ( V_11 ) ;
return V_9 ;
}
void F_10 ( struct V_1 * V_9 )
{
if ( V_9 )
F_8 ( V_9 -> V_6 ) ;
}
static int F_11 ( struct V_17 * V_18 )
{
return V_18 - V_18 -> V_9 -> V_19 ;
}
static int
F_12 ( struct V_17 * V_18 )
{
struct V_1 * V_9 = V_18 -> V_9 ;
unsigned int V_20 , V_21 ;
int V_22 ;
V_20 = V_9 -> V_23 -> V_19 . V_24 . V_20 ;
V_21 = V_9 -> V_23 -> V_19 . V_24 . V_21 ;
V_22 = F_11 ( V_18 ) ;
if ( V_22 < 0 )
return V_22 ;
if ( V_22 < V_20 || V_22 >= V_20 + V_21 )
return - V_25 ;
return V_22 - V_20 ;
}
static struct V_17 *
F_13 ( struct V_1 * V_9 , unsigned int V_22 )
{
unsigned int V_20 = V_9 -> V_23 -> V_19 . V_24 . V_20 ;
unsigned int V_21 = V_9 -> V_23 -> V_19 . V_24 . V_21 ;
if ( V_22 >= V_21 )
return NULL ;
return & V_9 -> V_19 [ V_20 + V_22 ] ;
}
static struct V_17 *
F_14 ( struct V_1 * V_9 )
{
unsigned int V_20 = V_9 -> V_23 -> V_19 . V_26 . V_20 ;
return & V_9 -> V_19 [ V_20 + F_15 () ] ;
}
static struct V_17 *
F_16 ( struct V_1 * V_9 )
{
unsigned int V_20 = V_9 -> V_23 -> V_19 . V_27 . V_20 ;
return & V_9 -> V_19 [ V_20 ] ;
}
static bool F_17 ( const struct V_28 * V_29 )
{
return ( V_29 -> V_30 . V_31 <= V_32 ) &&
( V_29 -> V_33 . V_31 <= V_32 ) &&
( V_29 -> V_30 . V_31 == 0 || V_29 -> V_30 . V_34 ) &&
( V_29 -> V_33 . V_31 == 0 || V_29 -> V_33 . V_34 ) ;
}
static bool F_18 ( struct V_17 * V_18 )
{
void * V_35 ;
V_35 = F_19 ( V_18 -> V_36 ) ;
if ( F_20 ( V_35 ) ) {
V_18 -> V_37 = NULL ;
return false ;
}
V_18 -> V_37 = V_35 ;
return true ;
}
static int F_21 ( struct V_17 * V_18 )
{
unsigned long V_38 = V_18 -> V_9 -> V_23 -> V_19 . V_26 . V_38 ;
T_1 V_39 ;
V_39 = F_22 ( F_23 () , V_38 ) ;
do {
if ( F_18 ( V_18 ) )
return 0 ;
} while ( F_24 ( F_23 () , V_39 ) );
return - V_40 ;
}
static bool F_25 ( struct V_17 * V_18 )
{
void * V_35 ;
V_35 = F_26 ( V_18 -> V_36 ) ;
if ( F_20 ( V_35 ) ) {
V_18 -> V_41 = NULL ;
return false ;
}
V_18 -> V_41 = V_35 ;
return true ;
}
static int F_27 ( struct V_17 * V_18 )
{
unsigned long V_38 = V_18 -> V_9 -> V_23 -> V_19 . V_26 . V_38 ;
T_1 V_42 , V_43 ;
V_42 = F_28 ( F_29 () ) ;
do {
if ( F_25 ( V_18 ) )
return 0 ;
V_43 = F_28 ( F_29 () ) ;
} while ( F_30 ( V_43 , V_42 ) < V_38 );
return - V_40 ;
}
static T_2 F_31 ( struct V_17 * V_18 ,
void * V_34 , T_3 V_31 )
{
if ( V_34 && V_31 > 0 )
memcpy ( V_34 , V_18 -> V_37 -> V_34 , V_31 ) ;
return F_32 ( V_18 -> V_36 ) ;
}
static T_2 F_33 ( struct V_17 * V_18 ,
void * V_34 , T_3 V_31 )
{
struct V_1 * V_9 = V_18 -> V_9 ;
unsigned long V_44 ;
T_2 V_45 ;
int V_22 ;
V_22 = F_12 ( V_18 ) ;
if ( V_22 < 0 ) {
V_45 = V_22 ;
goto V_46;
}
F_34 ( & V_9 -> V_47 , V_44 ) ;
V_45 = F_31 ( V_18 , V_34 , V_31 ) ;
F_35 ( V_22 , V_9 -> V_48 . V_49 ) ;
F_36 ( & V_9 -> V_47 , V_44 ) ;
V_46:
F_37 ( & V_9 -> V_48 . V_47 ) ;
return V_45 ;
}
static T_2 F_38 ( struct V_17 * V_18 ,
unsigned int V_50 , unsigned long V_44 ,
const void * V_34 , T_3 V_31 )
{
V_18 -> V_41 -> V_51 = V_50 ;
V_18 -> V_41 -> V_44 = V_44 ;
if ( V_34 && V_31 > 0 )
memcpy ( V_18 -> V_41 -> V_34 , V_34 , V_31 ) ;
return F_39 ( V_18 -> V_36 ) ;
}
static struct V_17 *
F_40 ( struct V_1 * V_9 , unsigned int V_50 ,
const void * V_34 , T_3 V_31 )
{
unsigned long V_38 = V_9 -> V_23 -> V_19 . V_24 . V_38 ;
unsigned int V_21 = V_9 -> V_23 -> V_19 . V_24 . V_21 ;
struct V_17 * V_18 ;
unsigned long V_44 ;
unsigned int V_22 ;
int V_45 ;
V_45 = F_41 ( & V_9 -> V_48 . V_47 , F_42 ( V_38 ) ) ;
if ( V_45 < 0 )
return F_5 ( V_45 ) ;
F_34 ( & V_9 -> V_47 , V_44 ) ;
V_22 = F_43 ( V_9 -> V_48 . V_49 , V_21 ) ;
if ( V_22 == V_21 ) {
V_45 = - V_52 ;
goto V_46;
}
V_18 = F_13 ( V_9 , V_22 ) ;
if ( ! V_18 ) {
V_45 = - V_25 ;
goto V_46;
}
if ( ! F_25 ( V_18 ) ) {
V_45 = - V_52 ;
goto V_46;
}
F_44 ( V_22 , V_9 -> V_48 . V_49 ) ;
V_45 = F_38 ( V_18 , V_50 , V_53 | V_54 ,
V_34 , V_31 ) ;
if ( V_45 < 0 )
goto V_55;
F_44 ( V_22 , V_9 -> V_48 . V_56 ) ;
F_36 ( & V_9 -> V_47 , V_44 ) ;
return V_18 ;
V_55:
F_35 ( V_22 , V_9 -> V_48 . V_49 ) ;
V_46:
F_36 ( & V_9 -> V_47 , V_44 ) ;
F_37 ( & V_9 -> V_48 . V_47 ) ;
return F_5 ( V_45 ) ;
}
static T_2 F_45 ( struct V_17 * V_18 ,
unsigned int V_50 , unsigned long V_44 ,
const void * V_34 , T_3 V_31 )
{
int V_45 ;
V_45 = F_27 ( V_18 ) ;
if ( V_45 < 0 )
return V_45 ;
return F_38 ( V_18 , V_50 , V_44 , V_34 , V_31 ) ;
}
int F_46 ( struct V_1 * V_9 ,
struct V_28 * V_29 )
{
struct V_17 * V_18 ;
int V_45 ;
if ( F_47 ( ! F_48 () ) )
return - V_57 ;
if ( ! F_17 ( V_29 ) )
return - V_25 ;
V_18 = F_14 ( V_9 ) ;
V_45 = F_45 ( V_18 , V_29 -> V_50 , V_53 ,
V_29 -> V_30 . V_34 , V_29 -> V_30 . V_31 ) ;
if ( V_45 < 0 )
return V_45 ;
V_45 = F_49 ( V_9 -> V_4 . V_18 , NULL ) ;
if ( V_45 < 0 )
return V_45 ;
F_50 ( V_9 -> V_4 . V_18 , 0 ) ;
V_45 = F_21 ( V_18 ) ;
if ( V_45 < 0 )
return V_45 ;
return F_31 ( V_18 , V_29 -> V_33 . V_34 , V_29 -> V_33 . V_31 ) ;
}
int F_51 ( struct V_1 * V_9 ,
struct V_28 * V_29 )
{
struct V_17 * V_18 ;
unsigned long V_38 ;
int V_45 ;
if ( F_47 ( F_48 () ) )
return - V_57 ;
if ( ! F_17 ( V_29 ) )
return - V_25 ;
V_18 = F_40 ( V_9 , V_29 -> V_50 , V_29 -> V_30 . V_34 ,
V_29 -> V_30 . V_31 ) ;
if ( F_20 ( V_18 ) )
return F_52 ( V_18 ) ;
V_45 = F_49 ( V_9 -> V_4 . V_18 , NULL ) ;
if ( V_45 < 0 )
return V_45 ;
F_50 ( V_9 -> V_4 . V_18 , 0 ) ;
V_38 = F_42 ( V_9 -> V_23 -> V_19 . V_24 . V_38 ) ;
V_45 = F_53 ( & V_18 -> V_58 , V_38 ) ;
if ( V_45 == 0 )
return - V_40 ;
return F_33 ( V_18 , V_29 -> V_33 . V_34 , V_29 -> V_33 . V_31 ) ;
}
static struct V_59 * F_54 ( struct V_1 * V_9 ,
unsigned int V_50 )
{
struct V_59 * V_60 ;
F_55 (entry, &bpmp->mrqs, list)
if ( V_60 -> V_50 == V_50 )
return V_60 ;
return NULL ;
}
static void F_56 ( struct V_17 * V_18 ,
int V_51 , const void * V_34 , T_3 V_31 )
{
unsigned long V_44 = V_18 -> V_37 -> V_44 ;
struct V_1 * V_9 = V_18 -> V_9 ;
struct V_61 * V_35 ;
int V_45 ;
if ( F_47 ( V_31 > V_32 ) )
return;
V_45 = F_32 ( V_18 -> V_36 ) ;
if ( F_47 ( V_45 < 0 ) )
return;
if ( ( V_44 & V_53 ) == 0 )
return;
V_35 = F_26 ( V_18 -> V_36 ) ;
if ( F_47 ( F_20 ( V_35 ) ) )
return;
V_35 -> V_51 = V_51 ;
if ( V_34 && V_31 > 0 )
memcpy ( V_35 -> V_34 , V_34 , V_31 ) ;
V_45 = F_39 ( V_18 -> V_36 ) ;
if ( F_47 ( V_45 < 0 ) )
return;
if ( V_44 & V_54 ) {
V_45 = F_49 ( V_9 -> V_4 . V_18 , NULL ) ;
if ( F_47 ( V_45 < 0 ) )
return;
F_50 ( V_9 -> V_4 . V_18 , 0 ) ;
}
}
static void F_57 ( struct V_1 * V_9 ,
unsigned int V_50 ,
struct V_17 * V_18 )
{
struct V_59 * V_60 ;
T_4 V_62 = 0 ;
F_58 ( & V_9 -> V_47 ) ;
V_60 = F_54 ( V_9 , V_50 ) ;
if ( ! V_60 ) {
F_59 ( & V_9 -> V_47 ) ;
F_56 ( V_18 , - V_25 , & V_62 , sizeof( V_62 ) ) ;
return;
}
V_60 -> V_63 ( V_50 , V_18 , V_60 -> V_34 ) ;
F_59 ( & V_9 -> V_47 ) ;
}
int F_60 ( struct V_1 * V_9 , unsigned int V_50 ,
T_5 V_63 , void * V_34 )
{
struct V_59 * V_60 ;
unsigned long V_44 ;
if ( ! V_63 )
return - V_25 ;
V_60 = F_61 ( V_9 -> V_6 , sizeof( * V_60 ) , V_64 ) ;
if ( ! V_60 )
return - V_65 ;
F_34 ( & V_9 -> V_47 , V_44 ) ;
V_60 -> V_50 = V_50 ;
V_60 -> V_63 = V_63 ;
V_60 -> V_34 = V_34 ;
F_62 ( & V_60 -> V_66 , & V_9 -> V_67 ) ;
F_36 ( & V_9 -> V_47 , V_44 ) ;
return 0 ;
}
void F_63 ( struct V_1 * V_9 , unsigned int V_50 , void * V_34 )
{
struct V_59 * V_60 ;
unsigned long V_44 ;
F_34 ( & V_9 -> V_47 , V_44 ) ;
V_60 = F_54 ( V_9 , V_50 ) ;
if ( ! V_60 )
goto V_46;
F_64 ( & V_60 -> V_66 ) ;
F_65 ( V_9 -> V_6 , V_60 ) ;
V_46:
F_36 ( & V_9 -> V_47 , V_44 ) ;
}
static void F_66 ( unsigned int V_50 ,
struct V_17 * V_18 ,
void * V_34 )
{
struct V_68 * V_69 ;
struct V_70 V_71 ;
V_69 = (struct V_68 * ) V_18 -> V_37 -> V_34 ;
memset ( & V_71 , 0 , sizeof( V_71 ) ) ;
V_71 . V_72 = V_69 -> V_73 << 1 ;
F_56 ( V_18 , 0 , & V_71 , sizeof( V_71 ) ) ;
}
static int F_67 ( struct V_1 * V_9 )
{
struct V_70 V_71 ;
struct V_68 V_69 ;
struct V_28 V_29 ;
unsigned long V_44 ;
T_1 V_42 , V_39 ;
int V_45 ;
memset ( & V_69 , 0 , sizeof( V_69 ) ) ;
V_69 . V_73 = 1 ;
memset ( & V_71 , 0 , sizeof( V_71 ) ) ;
memset ( & V_29 , 0 , sizeof( V_29 ) ) ;
V_29 . V_50 = V_74 ;
V_29 . V_30 . V_34 = & V_69 ;
V_29 . V_30 . V_31 = sizeof( V_69 ) ;
V_29 . V_33 . V_34 = & V_71 ;
V_29 . V_33 . V_31 = sizeof( V_71 ) ;
F_68 ( V_44 ) ;
V_42 = F_23 () ;
V_45 = F_46 ( V_9 , & V_29 ) ;
V_39 = F_23 () ;
F_69 ( V_44 ) ;
if ( ! V_45 )
F_70 ( V_9 -> V_6 ,
L_2 ,
V_69 . V_73 , V_71 . V_72 ,
F_71 ( F_72 ( V_39 , V_42 ) ) ) ;
return V_45 ;
}
static int F_73 ( struct V_1 * V_9 , char * V_75 ,
T_3 V_31 )
{
struct V_76 V_69 ;
struct V_28 V_29 ;
unsigned long V_44 ;
T_6 V_77 ;
void * V_78 ;
int V_45 ;
V_78 = F_74 ( V_9 -> V_6 , V_32 , & V_77 ,
V_64 | V_79 ) ;
if ( ! V_78 )
return - V_65 ;
memset ( & V_69 , 0 , sizeof( V_69 ) ) ;
V_69 . V_80 = V_77 ;
memset ( & V_29 , 0 , sizeof( V_29 ) ) ;
V_29 . V_50 = V_81 ;
V_29 . V_30 . V_34 = & V_69 ;
V_29 . V_30 . V_31 = sizeof( V_69 ) ;
F_68 ( V_44 ) ;
V_45 = F_46 ( V_9 , & V_29 ) ;
F_69 ( V_44 ) ;
if ( V_45 == 0 )
F_75 ( V_75 , V_78 , V_31 ) ;
F_76 ( V_9 -> V_6 , V_32 , V_78 , V_77 ) ;
return V_45 ;
}
static void F_77 ( struct V_17 * V_18 )
{
unsigned long V_44 = V_18 -> V_41 -> V_44 ;
if ( ( V_44 & V_54 ) == 0 )
return;
F_78 ( & V_18 -> V_58 ) ;
}
static void F_79 ( struct V_2 * V_3 , void * V_34 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
struct V_17 * V_18 ;
unsigned int V_82 , V_21 ;
unsigned long * V_56 ;
V_18 = F_16 ( V_9 ) ;
V_21 = V_9 -> V_23 -> V_19 . V_24 . V_21 ;
V_56 = V_9 -> V_48 . V_56 ;
if ( F_18 ( V_18 ) )
F_57 ( V_9 , V_18 -> V_37 -> V_51 , V_18 ) ;
F_58 ( & V_9 -> V_47 ) ;
F_80 (i, busy, count) {
struct V_17 * V_18 ;
V_18 = F_13 ( V_9 , V_82 ) ;
if ( ! V_18 )
continue;
if ( F_18 ( V_18 ) ) {
F_77 ( V_18 ) ;
F_35 ( V_82 , V_56 ) ;
}
}
F_59 ( & V_9 -> V_47 ) ;
}
static void F_81 ( struct V_83 * V_36 , void * V_34 )
{
struct V_1 * V_9 = V_34 ;
int V_45 ;
if ( F_47 ( V_9 -> V_4 . V_18 == NULL ) )
return;
V_45 = F_49 ( V_9 -> V_4 . V_18 , NULL ) ;
if ( V_45 < 0 )
return;
F_50 ( V_9 -> V_4 . V_18 , 0 ) ;
}
static int F_82 ( struct V_17 * V_18 ,
struct V_1 * V_9 ,
unsigned int V_22 )
{
T_3 V_84 , V_85 ;
unsigned int V_20 ;
int V_45 ;
V_18 -> V_36 = F_61 ( V_9 -> V_6 , sizeof( * V_18 -> V_36 ) ,
V_64 ) ;
if ( ! V_18 -> V_36 )
return - V_65 ;
V_84 = F_83 ( V_86 ) ;
V_85 = F_84 ( V_84 ) ;
V_20 = V_85 * V_22 ;
V_45 = F_85 ( V_18 -> V_36 , NULL ,
V_9 -> V_33 . V_78 + V_20 , V_9 -> V_33 . V_77 + V_20 ,
V_9 -> V_30 . V_78 + V_20 , V_9 -> V_30 . V_77 + V_20 ,
1 , V_84 , F_81 ,
V_9 ) ;
if ( V_45 < 0 ) {
F_86 ( V_9 -> V_6 , L_3 ,
V_22 , V_45 ) ;
return V_45 ;
}
F_87 ( & V_18 -> V_58 ) ;
V_18 -> V_9 = V_9 ;
return 0 ;
}
static void F_88 ( struct V_17 * V_18 )
{
F_89 ( V_18 -> V_36 ) ;
while ( F_90 ( V_18 -> V_36 ) )
;
}
static void F_91 ( struct V_17 * V_18 )
{
F_92 ( V_18 -> V_36 ) ;
}
static int F_93 ( struct V_7 * V_8 )
{
struct V_17 * V_18 ;
struct V_1 * V_9 ;
unsigned int V_82 ;
char V_75 [ 32 ] ;
T_3 V_31 ;
int V_45 ;
V_9 = F_61 ( & V_8 -> V_6 , sizeof( * V_9 ) , V_64 ) ;
if ( ! V_9 )
return - V_65 ;
V_9 -> V_23 = F_94 ( & V_8 -> V_6 ) ;
V_9 -> V_6 = & V_8 -> V_6 ;
V_9 -> V_30 . V_87 = F_95 ( V_8 -> V_6 . V_12 , L_4 , 0 ) ;
if ( ! V_9 -> V_30 . V_87 ) {
F_86 ( & V_8 -> V_6 , L_5 ) ;
return - V_65 ;
}
V_9 -> V_30 . V_78 = F_96 ( V_9 -> V_30 . V_87 , 4096 , & V_9 -> V_30 . V_77 ) ;
if ( ! V_9 -> V_30 . V_78 ) {
F_86 ( & V_8 -> V_6 , L_6 ) ;
return - V_65 ;
}
V_9 -> V_33 . V_87 = F_95 ( V_8 -> V_6 . V_12 , L_4 , 1 ) ;
if ( ! V_9 -> V_33 . V_87 ) {
F_86 ( & V_8 -> V_6 , L_7 ) ;
V_45 = - V_65 ;
goto V_88;
}
V_9 -> V_33 . V_78 = F_96 ( V_9 -> V_33 . V_87 , 4096 , & V_9 -> V_33 . V_77 ) ;
if ( ! V_9 -> V_33 . V_87 ) {
F_86 ( & V_8 -> V_6 , L_8 ) ;
V_45 = - V_65 ;
goto V_88;
}
F_97 ( & V_9 -> V_67 ) ;
F_98 ( & V_9 -> V_47 ) ;
V_9 -> V_48 . V_21 = V_9 -> V_23 -> V_19 . V_24 . V_21 ;
F_99 ( & V_9 -> V_48 . V_47 , V_9 -> V_48 . V_21 ) ;
V_31 = F_100 ( V_9 -> V_48 . V_21 ) * sizeof( long ) ;
V_9 -> V_48 . V_49 = F_61 ( & V_8 -> V_6 , V_31 , V_64 ) ;
if ( ! V_9 -> V_48 . V_49 ) {
V_45 = - V_65 ;
goto V_89;
}
V_9 -> V_48 . V_56 = F_61 ( & V_8 -> V_6 , V_31 , V_64 ) ;
if ( ! V_9 -> V_48 . V_56 ) {
V_45 = - V_65 ;
goto V_89;
}
V_9 -> V_90 = V_9 -> V_23 -> V_19 . V_26 . V_21 +
V_9 -> V_23 -> V_19 . V_24 . V_21 +
V_9 -> V_23 -> V_19 . V_27 . V_21 ;
V_9 -> V_19 = F_101 ( & V_8 -> V_6 , V_9 -> V_90 ,
sizeof( * V_18 ) , V_64 ) ;
if ( ! V_9 -> V_19 ) {
V_45 = - V_65 ;
goto V_89;
}
for ( V_82 = 0 ; V_82 < V_9 -> V_90 ; V_82 ++ ) {
struct V_17 * V_18 = & V_9 -> V_19 [ V_82 ] ;
V_45 = F_82 ( V_18 , V_9 , V_82 ) ;
if ( V_45 < 0 )
goto V_91;
}
V_9 -> V_4 . V_3 . V_6 = & V_8 -> V_6 ;
V_9 -> V_4 . V_3 . V_92 = F_79 ;
V_9 -> V_4 . V_3 . V_93 = false ;
V_9 -> V_4 . V_3 . V_94 = false ;
V_9 -> V_4 . V_18 = F_102 ( & V_9 -> V_4 . V_3 , 0 ) ;
if ( F_20 ( V_9 -> V_4 . V_18 ) ) {
V_45 = F_52 ( V_9 -> V_4 . V_18 ) ;
F_86 ( & V_8 -> V_6 , L_9 , V_45 ) ;
goto V_91;
}
for ( V_82 = 0 ; V_82 < V_9 -> V_90 ; V_82 ++ ) {
struct V_17 * V_18 = & V_9 -> V_19 [ V_82 ] ;
F_88 ( V_18 ) ;
}
V_45 = F_60 ( V_9 , V_74 ,
F_66 , V_9 ) ;
if ( V_45 < 0 )
goto V_95;
V_45 = F_67 ( V_9 ) ;
if ( V_45 < 0 ) {
F_86 ( & V_8 -> V_6 , L_10 , V_45 ) ;
goto V_96;
}
V_45 = F_73 ( V_9 , V_75 , sizeof( V_75 ) - 1 ) ;
if ( V_45 < 0 ) {
F_86 ( & V_8 -> V_6 , L_11 , V_45 ) ;
goto V_96;
}
F_103 ( & V_8 -> V_6 , L_12 , V_75 ) ;
F_104 ( V_8 , V_9 ) ;
V_45 = F_105 ( V_8 -> V_6 . V_12 , NULL , & V_8 -> V_6 ) ;
if ( V_45 < 0 )
goto V_96;
V_45 = F_106 ( V_9 ) ;
if ( V_45 < 0 )
goto V_96;
V_45 = F_107 ( V_9 ) ;
if ( V_45 < 0 )
goto V_96;
V_45 = F_108 ( V_9 ) ;
if ( V_45 < 0 )
goto V_96;
return 0 ;
V_96:
F_63 ( V_9 , V_74 , V_9 ) ;
V_95:
F_109 ( V_9 -> V_4 . V_18 ) ;
V_91:
while ( V_82 -- )
F_91 ( & V_9 -> V_19 [ V_82 ] ) ;
V_89:
F_110 ( V_9 -> V_33 . V_87 , ( unsigned long ) V_9 -> V_33 . V_78 , 4096 ) ;
V_88:
F_110 ( V_9 -> V_30 . V_87 , ( unsigned long ) V_9 -> V_30 . V_78 , 4096 ) ;
return V_45 ;
}
static int T_7 F_111 ( void )
{
return F_112 ( & V_97 ) ;
}
