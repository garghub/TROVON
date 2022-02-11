static int F_1 ( struct V_1 * V_2 , T_1 V_3 , struct V_4 * * V_5 ,
T_2 V_6 )
{
struct V_4 * V_7 ;
void * V_8 ;
V_7 = F_2 ( V_6 , V_9 ) ;
if ( ! V_7 )
return - V_10 ;
if ( ! V_2 ) {
int V_11 = F_3 ( V_12 ) - 1 ;
V_8 = F_4 ( V_7 , 0 , V_11 , & V_13 , 0 , V_3 ) ;
} else
V_8 = F_5 ( V_7 , V_2 , & V_13 , 0 , V_3 ) ;
if ( V_8 == NULL ) {
F_6 ( V_7 ) ;
return - V_14 ;
}
* V_5 = V_7 ;
return 0 ;
}
static int F_7 ( struct V_4 * V_7 , struct V_1 * V_2 )
{
struct V_15 * V_16 = F_8 ( F_9 ( V_7 ) ) ;
void * V_8 = F_10 ( V_16 ) ;
int V_17 ;
V_17 = F_11 ( V_7 , V_8 ) ;
if ( V_17 < 0 ) {
F_6 ( V_7 ) ;
return V_17 ;
}
return F_12 ( V_7 , V_2 ) ;
}
static void F_13 ( struct V_4 * V_7 ,
struct V_18 * V_19 )
{
struct V_15 * V_16 = F_8 ( F_9 ( V_7 ) ) ;
struct V_20 * V_21 , * V_22 ;
struct V_4 * V_23 , * V_24 = V_7 ;
void * V_8 = F_10 ( V_16 ) ;
int V_17 , V_25 = 0 ;
V_17 = F_11 ( V_7 , V_8 ) ;
if ( V_17 < 0 ) {
F_6 ( V_7 ) ;
return;
}
V_17 = 0 ;
F_14 ( & V_19 -> V_26 ) ;
F_15 (s, &listeners->list, list) {
V_23 = NULL ;
if ( ! F_16 ( & V_21 -> V_27 , & V_19 -> V_27 ) ) {
V_23 = F_17 ( V_24 , V_9 ) ;
if ( ! V_23 )
break;
}
V_17 = F_18 ( & V_28 , V_24 , V_21 -> V_29 ) ;
if ( V_17 == - V_30 ) {
V_21 -> V_31 = 0 ;
V_25 ++ ;
}
V_24 = V_23 ;
}
F_19 ( & V_19 -> V_26 ) ;
if ( V_24 )
F_6 ( V_24 ) ;
if ( ! V_25 )
return;
F_20 ( & V_19 -> V_26 ) ;
F_21 (s, tmp, &listeners->list, list) {
if ( ! V_21 -> V_31 ) {
F_22 ( & V_21 -> V_27 ) ;
F_23 ( V_21 ) ;
}
}
F_24 ( & V_19 -> V_26 ) ;
}
static void F_25 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
struct V_36 * V_37 , struct V_38 * V_39 )
{
memset ( V_39 , 0 , sizeof( * V_39 ) ) ;
F_26 ( V_39 , V_37 ) ;
V_39 -> V_40 = V_41 ;
V_39 -> V_42 = V_37 -> V_42 ;
V_39 -> V_43 = V_37 -> V_43 ;
F_27 ( V_33 , V_35 , V_39 , V_37 ) ;
F_28 ( V_39 , V_37 ) ;
}
static int F_29 ( T_3 V_29 , struct V_38 * V_39 )
{
struct V_36 * V_37 ;
F_30 () ;
V_37 = F_31 ( V_29 ) ;
if ( V_37 )
F_32 ( V_37 ) ;
F_33 () ;
if ( ! V_37 )
return - V_44 ;
F_25 ( F_34 () , F_35 ( V_45 ) , V_37 , V_39 ) ;
F_36 ( V_37 ) ;
return 0 ;
}
static int F_37 ( T_3 V_46 , struct V_38 * V_39 )
{
struct V_36 * V_37 , * V_47 ;
unsigned long V_48 ;
int V_17 = - V_44 ;
F_30 () ;
V_47 = F_31 ( V_46 ) ;
if ( ! V_47 || ! F_38 ( V_47 , & V_48 ) )
goto V_49;
if ( V_47 -> signal -> V_39 )
memcpy ( V_39 , V_47 -> signal -> V_39 , sizeof( * V_39 ) ) ;
else
memset ( V_39 , 0 , sizeof( * V_39 ) ) ;
V_37 = V_47 ;
do {
if ( V_37 -> V_50 )
continue;
F_26 ( V_39 , V_37 ) ;
V_39 -> V_42 += V_37 -> V_42 ;
V_39 -> V_43 += V_37 -> V_43 ;
} while_each_thread(first, tsk) ;
void F_39 ( struct V_36 * V_37 )
{
unsigned long V_48 ;
F_40 ( & V_37 -> V_51 -> V_52 , V_48 ) ;
if ( ! V_37 -> signal -> V_39 )
goto V_53;
F_26 ( V_37 -> signal -> V_39 , V_37 ) ;
V_53:
F_41 ( & V_37 -> V_51 -> V_52 , V_48 ) ;
return;
}
static int F_42 ( T_3 V_29 , const struct V_54 * V_55 , int V_56 )
{
struct V_18 * V_19 ;
struct V_20 * V_21 , * V_22 , * V_57 ;
unsigned int V_58 ;
int V_53 = 0 ;
if ( ! F_43 ( V_55 , V_59 ) )
return - V_14 ;
if ( F_34 () != & V_60 )
return - V_14 ;
if ( F_35 ( V_45 ) != & V_61 )
return - V_14 ;
if ( V_56 == REGISTER ) {
F_44 (cpu, mask) {
V_21 = F_45 ( sizeof( struct V_20 ) ,
V_9 , F_46 ( V_58 ) ) ;
if ( ! V_21 ) {
V_53 = - V_10 ;
goto V_62;
}
V_21 -> V_29 = V_29 ;
V_21 -> V_31 = 1 ;
V_19 = & F_47 ( V_63 , V_58 ) ;
F_20 ( & V_19 -> V_26 ) ;
F_15 (s2, &listeners->list, list) {
if ( V_57 -> V_29 == V_29 && V_57 -> V_31 )
goto V_64;
}
F_48 ( & V_21 -> V_27 , & V_19 -> V_27 ) ;
V_21 = NULL ;
V_64:
F_24 ( & V_19 -> V_26 ) ;
F_23 ( V_21 ) ;
}
return 0 ;
}
V_62:
F_44 (cpu, mask) {
V_19 = & F_47 ( V_63 , V_58 ) ;
F_20 ( & V_19 -> V_26 ) ;
F_21 (s, tmp, &listeners->list, list) {
if ( V_21 -> V_29 == V_29 ) {
F_22 ( & V_21 -> V_27 ) ;
F_23 ( V_21 ) ;
break;
}
}
F_24 ( & V_19 -> V_26 ) ;
}
return V_53 ;
}
static int F_49 ( struct V_65 * V_66 , struct V_54 * V_55 )
{
char * V_67 ;
int V_68 ;
int V_53 ;
if ( V_66 == NULL )
return 1 ;
V_68 = F_50 ( V_66 ) ;
if ( V_68 > V_69 )
return - V_70 ;
if ( V_68 < 1 )
return - V_14 ;
V_67 = F_51 ( V_68 , V_9 ) ;
if ( ! V_67 )
return - V_10 ;
F_52 ( V_67 , V_66 , V_68 ) ;
V_53 = F_53 ( V_67 , V_55 ) ;
F_23 ( V_67 ) ;
return V_53 ;
}
static struct V_38 * F_54 ( struct V_4 * V_7 , int type , T_4 V_29 )
{
struct V_65 * V_66 , * V_53 ;
int V_71 ;
V_71 = ( type == V_72 )
? V_73
: V_74 ;
#ifdef F_55
if ( F_56 ( V_7 , V_75 , 0 , NULL ) < 0 )
goto V_76;
#endif
V_66 = F_57 ( V_7 , V_71 ) ;
if ( ! V_66 )
goto V_76;
if ( F_56 ( V_7 , type , sizeof( V_29 ) , & V_29 ) < 0 ) {
F_58 ( V_7 , V_66 ) ;
goto V_76;
}
V_53 = F_59 ( V_7 , V_77 , sizeof( struct V_38 ) ) ;
if ( ! V_53 ) {
F_58 ( V_7 , V_66 ) ;
goto V_76;
}
F_60 ( V_7 , V_66 ) ;
return F_61 ( V_53 ) ;
V_76:
return NULL ;
}
static int F_62 ( struct V_4 * V_7 , struct V_1 * V_2 )
{
int V_17 = 0 ;
struct V_4 * V_78 ;
struct V_79 * V_39 ;
struct V_65 * V_66 ;
T_2 V_6 ;
T_4 V_80 ;
struct V_80 V_81 ;
V_66 = V_2 -> V_82 [ V_83 ] ;
if ( ! V_66 )
return - V_14 ;
V_80 = F_63 ( V_2 -> V_82 [ V_83 ] ) ;
V_81 = F_64 ( V_80 ) ;
if ( ! V_81 . V_84 )
return 0 ;
V_6 = F_65 ( sizeof( struct V_79 ) ) ;
V_17 = F_1 ( V_2 , V_85 , & V_78 ,
V_6 ) ;
if ( V_17 < 0 )
goto V_76;
V_66 = F_59 ( V_78 , V_86 ,
sizeof( struct V_79 ) ) ;
if ( V_66 == NULL ) {
F_6 ( V_78 ) ;
V_17 = - V_87 ;
goto V_76;
}
V_39 = F_61 ( V_66 ) ;
memset ( V_39 , 0 , sizeof( * V_39 ) ) ;
V_17 = F_66 ( V_39 , V_81 . V_84 -> V_88 ) ;
if ( V_17 < 0 ) {
F_6 ( V_78 ) ;
goto V_76;
}
V_17 = F_7 ( V_78 , V_2 ) ;
V_76:
F_67 ( V_81 ) ;
return V_17 ;
}
static int F_68 ( struct V_1 * V_2 )
{
T_5 V_55 ;
int V_17 ;
if ( ! F_69 ( & V_55 , V_9 ) )
return - V_10 ;
V_17 = F_49 ( V_2 -> V_82 [ V_89 ] , V_55 ) ;
if ( V_17 < 0 )
goto V_49;
V_17 = F_42 ( V_2 -> V_90 , V_55 , REGISTER ) ;
V_49:
F_70 ( V_55 ) ;
return V_17 ;
}
static int F_71 ( struct V_1 * V_2 )
{
T_5 V_55 ;
int V_17 ;
if ( ! F_69 ( & V_55 , V_9 ) )
return - V_10 ;
V_17 = F_49 ( V_2 -> V_82 [ V_91 ] , V_55 ) ;
if ( V_17 < 0 )
goto V_49;
V_17 = F_42 ( V_2 -> V_90 , V_55 , V_92 ) ;
V_49:
F_70 ( V_55 ) ;
return V_17 ;
}
static T_2 F_72 ( void )
{
T_2 V_6 ;
V_6 = F_65 ( sizeof( T_4 ) ) +
F_65 ( sizeof( struct V_38 ) ) + F_65 ( 0 ) ;
#ifdef F_55
V_6 += F_65 ( 0 ) ;
#endif
return V_6 ;
}
static int F_73 ( struct V_1 * V_2 )
{
struct V_38 * V_39 ;
struct V_4 * V_78 ;
T_2 V_6 ;
T_4 V_29 ;
int V_17 ;
V_6 = F_72 () ;
V_17 = F_1 ( V_2 , V_93 , & V_78 , V_6 ) ;
if ( V_17 < 0 )
return V_17 ;
V_17 = - V_14 ;
V_29 = F_63 ( V_2 -> V_82 [ V_94 ] ) ;
V_39 = F_54 ( V_78 , V_72 , V_29 ) ;
if ( ! V_39 )
goto V_76;
V_17 = F_29 ( V_29 , V_39 ) ;
if ( V_17 < 0 )
goto V_76;
return F_7 ( V_78 , V_2 ) ;
V_76:
F_6 ( V_78 ) ;
return V_17 ;
}
static int F_74 ( struct V_1 * V_2 )
{
struct V_38 * V_39 ;
struct V_4 * V_78 ;
T_2 V_6 ;
T_4 V_46 ;
int V_17 ;
V_6 = F_72 () ;
V_17 = F_1 ( V_2 , V_93 , & V_78 , V_6 ) ;
if ( V_17 < 0 )
return V_17 ;
V_17 = - V_14 ;
V_46 = F_63 ( V_2 -> V_82 [ V_95 ] ) ;
V_39 = F_54 ( V_78 , V_96 , V_46 ) ;
if ( ! V_39 )
goto V_76;
V_17 = F_37 ( V_46 , V_39 ) ;
if ( V_17 < 0 )
goto V_76;
return F_7 ( V_78 , V_2 ) ;
V_76:
F_6 ( V_78 ) ;
return V_17 ;
}
static int F_75 ( struct V_4 * V_7 , struct V_1 * V_2 )
{
if ( V_2 -> V_82 [ V_89 ] )
return F_68 ( V_2 ) ;
else if ( V_2 -> V_82 [ V_91 ] )
return F_71 ( V_2 ) ;
else if ( V_2 -> V_82 [ V_94 ] )
return F_73 ( V_2 ) ;
else if ( V_2 -> V_82 [ V_95 ] )
return F_74 ( V_2 ) ;
else
return - V_14 ;
}
static struct V_38 * F_76 ( struct V_36 * V_37 )
{
struct V_97 * V_98 = V_37 -> signal ;
struct V_38 * V_39 ;
if ( V_98 -> V_39 || F_77 ( V_37 ) )
goto V_53;
V_39 = F_78 ( V_99 , V_9 ) ;
F_79 ( & V_37 -> V_51 -> V_52 ) ;
if ( ! V_98 -> V_39 ) {
V_98 -> V_39 = V_39 ;
V_39 = NULL ;
}
F_80 ( & V_37 -> V_51 -> V_52 ) ;
if ( V_39 )
F_81 ( V_99 , V_39 ) ;
V_53:
return V_98 -> V_39 ;
}
void F_82 ( struct V_36 * V_37 , int V_100 )
{
int V_17 ;
struct V_18 * V_19 ;
struct V_38 * V_39 ;
struct V_4 * V_78 ;
T_2 V_6 ;
int V_101 ;
if ( ! V_102 )
return;
V_6 = F_72 () ;
V_101 = ! ! F_76 ( V_37 ) ;
if ( V_101 ) {
V_6 = 2 * V_6 ;
F_39 ( V_37 ) ;
}
V_19 = F_83 ( & V_63 ) ;
if ( F_84 ( & V_19 -> V_27 ) )
return;
V_17 = F_1 ( NULL , V_93 , & V_78 , V_6 ) ;
if ( V_17 < 0 )
return;
V_39 = F_54 ( V_78 , V_72 ,
F_85 ( V_37 , & V_61 ) ) ;
if ( ! V_39 )
goto V_76;
F_25 ( & V_60 , & V_61 , V_37 , V_39 ) ;
if ( ! V_101 || ! V_100 )
goto V_103;
V_39 = F_54 ( V_78 , V_96 ,
F_86 ( V_37 , & V_61 ) ) ;
if ( ! V_39 )
goto V_76;
memcpy ( V_39 , V_37 -> signal -> V_39 , sizeof( * V_39 ) ) ;
V_103:
F_13 ( V_78 , V_19 ) ;
return;
V_76:
F_6 ( V_78 ) ;
}
void T_6 F_87 ( void )
{
unsigned int V_104 ;
V_99 = F_88 ( V_38 , V_105 ) ;
F_89 (i) {
F_90 ( & ( F_47 ( V_63 , V_104 ) . V_27 ) ) ;
F_91 ( & ( F_47 ( V_63 , V_104 ) . V_26 ) ) ;
}
}
static int T_6 F_92 ( void )
{
int V_17 ;
V_17 = F_93 ( & V_13 , V_106 ) ;
if ( V_17 )
return V_17 ;
V_102 = 1 ;
F_94 ( L_1 , V_107 ) ;
return 0 ;
}
