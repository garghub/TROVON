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
static void F_25 ( struct V_32 * V_33 , struct V_34 * V_35 )
{
memset ( V_35 , 0 , sizeof( * V_35 ) ) ;
F_26 ( V_35 , V_33 ) ;
V_35 -> V_36 = V_37 ;
V_35 -> V_38 = V_33 -> V_38 ;
V_35 -> V_39 = V_33 -> V_39 ;
F_27 ( V_35 , V_33 ) ;
F_28 ( V_35 , V_33 ) ;
}
static int F_29 ( T_3 V_29 , struct V_34 * V_35 )
{
struct V_32 * V_33 ;
F_30 () ;
V_33 = F_31 ( V_29 ) ;
if ( V_33 )
F_32 ( V_33 ) ;
F_33 () ;
if ( ! V_33 )
return - V_40 ;
F_25 ( V_33 , V_35 ) ;
F_34 ( V_33 ) ;
return 0 ;
}
static int F_35 ( T_3 V_41 , struct V_34 * V_35 )
{
struct V_32 * V_33 , * V_42 ;
unsigned long V_43 ;
int V_17 = - V_40 ;
F_30 () ;
V_42 = F_31 ( V_41 ) ;
if ( ! V_42 || ! F_36 ( V_42 , & V_43 ) )
goto V_44;
if ( V_42 -> signal -> V_35 )
memcpy ( V_35 , V_42 -> signal -> V_35 , sizeof( * V_35 ) ) ;
else
memset ( V_35 , 0 , sizeof( * V_35 ) ) ;
V_33 = V_42 ;
do {
if ( V_33 -> V_45 )
continue;
F_26 ( V_35 , V_33 ) ;
V_35 -> V_38 += V_33 -> V_38 ;
V_35 -> V_39 += V_33 -> V_39 ;
} while_each_thread(first, tsk) ;
void F_37 ( struct V_32 * V_33 )
{
unsigned long V_43 ;
F_38 ( & V_33 -> V_46 -> V_47 , V_43 ) ;
if ( ! V_33 -> signal -> V_35 )
goto V_48;
F_26 ( V_33 -> signal -> V_35 , V_33 ) ;
V_48:
F_39 ( & V_33 -> V_46 -> V_47 , V_43 ) ;
return;
}
static int F_40 ( T_3 V_29 , const struct V_49 * V_50 , int V_51 )
{
struct V_18 * V_19 ;
struct V_20 * V_21 , * V_22 , * V_52 ;
unsigned int V_53 ;
if ( ! F_41 ( V_50 , V_54 ) )
return - V_14 ;
if ( V_51 == REGISTER ) {
F_42 (cpu, mask) {
V_21 = F_43 ( sizeof( struct V_20 ) ,
V_9 , F_44 ( V_53 ) ) ;
if ( ! V_21 )
goto V_55;
V_21 -> V_29 = V_29 ;
V_21 -> V_31 = 1 ;
V_19 = & F_45 ( V_56 , V_53 ) ;
F_20 ( & V_19 -> V_26 ) ;
F_15 (s2, &listeners->list, list) {
if ( V_52 -> V_29 == V_29 && V_52 -> V_31 )
goto V_57;
}
F_46 ( & V_21 -> V_27 , & V_19 -> V_27 ) ;
V_21 = NULL ;
V_57:
F_24 ( & V_19 -> V_26 ) ;
F_23 ( V_21 ) ;
}
return 0 ;
}
V_55:
F_42 (cpu, mask) {
V_19 = & F_45 ( V_56 , V_53 ) ;
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
return 0 ;
}
static int F_47 ( struct V_58 * V_59 , struct V_49 * V_50 )
{
char * V_60 ;
int V_61 ;
int V_48 ;
if ( V_59 == NULL )
return 1 ;
V_61 = F_48 ( V_59 ) ;
if ( V_61 > V_62 )
return - V_63 ;
if ( V_61 < 1 )
return - V_14 ;
V_60 = F_49 ( V_61 , V_9 ) ;
if ( ! V_60 )
return - V_10 ;
F_50 ( V_60 , V_59 , V_61 ) ;
V_48 = F_51 ( V_60 , V_50 ) ;
F_23 ( V_60 ) ;
return V_48 ;
}
static struct V_34 * F_52 ( struct V_4 * V_7 , int type , T_4 V_29 )
{
struct V_58 * V_59 , * V_48 ;
int V_64 ;
V_64 = ( type == V_65 )
? V_66
: V_67 ;
#ifdef F_53
if ( F_54 ( V_7 , V_68 , 0 , NULL ) < 0 )
goto V_69;
#endif
V_59 = F_55 ( V_7 , V_64 ) ;
if ( ! V_59 )
goto V_69;
if ( F_54 ( V_7 , type , sizeof( V_29 ) , & V_29 ) < 0 )
goto V_69;
V_48 = F_56 ( V_7 , V_70 , sizeof( struct V_34 ) ) ;
if ( ! V_48 )
goto V_69;
F_57 ( V_7 , V_59 ) ;
return F_58 ( V_48 ) ;
V_69:
return NULL ;
}
static int F_59 ( struct V_4 * V_7 , struct V_1 * V_2 )
{
int V_17 = 0 ;
struct V_4 * V_71 ;
struct V_72 * V_35 ;
struct V_58 * V_59 ;
T_2 V_6 ;
T_4 V_73 ;
struct V_74 * V_74 ;
int V_75 ;
V_59 = V_2 -> V_76 [ V_77 ] ;
if ( ! V_59 )
return - V_14 ;
V_73 = F_60 ( V_2 -> V_76 [ V_77 ] ) ;
V_74 = F_61 ( V_73 , & V_75 ) ;
if ( ! V_74 )
return 0 ;
V_6 = F_62 ( sizeof( struct V_72 ) ) ;
V_17 = F_1 ( V_2 , V_78 , & V_71 ,
V_6 ) ;
if ( V_17 < 0 )
goto V_69;
V_59 = F_56 ( V_71 , V_79 ,
sizeof( struct V_72 ) ) ;
V_35 = F_58 ( V_59 ) ;
memset ( V_35 , 0 , sizeof( * V_35 ) ) ;
V_17 = F_63 ( V_35 , V_74 -> V_80 ) ;
if ( V_17 < 0 ) {
F_6 ( V_71 ) ;
goto V_69;
}
V_17 = F_7 ( V_71 , V_2 ) ;
V_69:
F_64 ( V_74 , V_75 ) ;
return V_17 ;
}
static int F_65 ( struct V_1 * V_2 )
{
T_5 V_50 ;
int V_17 ;
if ( ! F_66 ( & V_50 , V_9 ) )
return - V_10 ;
V_17 = F_47 ( V_2 -> V_76 [ V_81 ] , V_50 ) ;
if ( V_17 < 0 )
goto V_44;
V_17 = F_40 ( V_2 -> V_82 , V_50 , REGISTER ) ;
V_44:
F_67 ( V_50 ) ;
return V_17 ;
}
static int F_68 ( struct V_1 * V_2 )
{
T_5 V_50 ;
int V_17 ;
if ( ! F_66 ( & V_50 , V_9 ) )
return - V_10 ;
V_17 = F_47 ( V_2 -> V_76 [ V_83 ] , V_50 ) ;
if ( V_17 < 0 )
goto V_44;
V_17 = F_40 ( V_2 -> V_82 , V_50 , V_84 ) ;
V_44:
F_67 ( V_50 ) ;
return V_17 ;
}
static T_2 F_69 ( void )
{
T_2 V_6 ;
V_6 = F_62 ( sizeof( T_4 ) ) +
F_62 ( sizeof( struct V_34 ) ) + F_62 ( 0 ) ;
#ifdef F_53
V_6 += F_62 ( 0 ) ;
#endif
return V_6 ;
}
static int F_70 ( struct V_1 * V_2 )
{
struct V_34 * V_35 ;
struct V_4 * V_71 ;
T_2 V_6 ;
T_4 V_29 ;
int V_17 ;
V_6 = F_69 () ;
V_17 = F_1 ( V_2 , V_85 , & V_71 , V_6 ) ;
if ( V_17 < 0 )
return V_17 ;
V_17 = - V_14 ;
V_29 = F_60 ( V_2 -> V_76 [ V_86 ] ) ;
V_35 = F_52 ( V_71 , V_65 , V_29 ) ;
if ( ! V_35 )
goto V_69;
V_17 = F_29 ( V_29 , V_35 ) ;
if ( V_17 < 0 )
goto V_69;
return F_7 ( V_71 , V_2 ) ;
V_69:
F_6 ( V_71 ) ;
return V_17 ;
}
static int F_71 ( struct V_1 * V_2 )
{
struct V_34 * V_35 ;
struct V_4 * V_71 ;
T_2 V_6 ;
T_4 V_41 ;
int V_17 ;
V_6 = F_69 () ;
V_17 = F_1 ( V_2 , V_85 , & V_71 , V_6 ) ;
if ( V_17 < 0 )
return V_17 ;
V_17 = - V_14 ;
V_41 = F_60 ( V_2 -> V_76 [ V_87 ] ) ;
V_35 = F_52 ( V_71 , V_88 , V_41 ) ;
if ( ! V_35 )
goto V_69;
V_17 = F_35 ( V_41 , V_35 ) ;
if ( V_17 < 0 )
goto V_69;
return F_7 ( V_71 , V_2 ) ;
V_69:
F_6 ( V_71 ) ;
return V_17 ;
}
static int F_72 ( struct V_4 * V_7 , struct V_1 * V_2 )
{
if ( V_2 -> V_76 [ V_81 ] )
return F_65 ( V_2 ) ;
else if ( V_2 -> V_76 [ V_83 ] )
return F_68 ( V_2 ) ;
else if ( V_2 -> V_76 [ V_86 ] )
return F_70 ( V_2 ) ;
else if ( V_2 -> V_76 [ V_87 ] )
return F_71 ( V_2 ) ;
else
return - V_14 ;
}
static struct V_34 * F_73 ( struct V_32 * V_33 )
{
struct V_89 * V_90 = V_33 -> signal ;
struct V_34 * V_35 ;
if ( V_90 -> V_35 || F_74 ( V_33 ) )
goto V_48;
V_35 = F_75 ( V_91 , V_9 ) ;
F_76 ( & V_33 -> V_46 -> V_47 ) ;
if ( ! V_90 -> V_35 ) {
V_90 -> V_35 = V_35 ;
V_35 = NULL ;
}
F_77 ( & V_33 -> V_46 -> V_47 ) ;
if ( V_35 )
F_78 ( V_91 , V_35 ) ;
V_48:
return V_90 -> V_35 ;
}
void F_79 ( struct V_32 * V_33 , int V_92 )
{
int V_17 ;
struct V_18 * V_19 ;
struct V_34 * V_35 ;
struct V_4 * V_71 ;
T_2 V_6 ;
int V_93 ;
if ( ! V_94 )
return;
V_6 = F_69 () ;
V_93 = ! ! F_73 ( V_33 ) ;
if ( V_93 ) {
V_6 = 2 * V_6 ;
F_37 ( V_33 ) ;
}
V_19 = F_80 ( & V_56 ) ;
if ( F_81 ( & V_19 -> V_27 ) )
return;
V_17 = F_1 ( NULL , V_85 , & V_71 , V_6 ) ;
if ( V_17 < 0 )
return;
V_35 = F_52 ( V_71 , V_65 , V_33 -> V_29 ) ;
if ( ! V_35 )
goto V_69;
F_25 ( V_33 , V_35 ) ;
if ( ! V_93 || ! V_92 )
goto V_95;
V_35 = F_52 ( V_71 , V_88 , V_33 -> V_41 ) ;
if ( ! V_35 )
goto V_69;
memcpy ( V_35 , V_33 -> signal -> V_35 , sizeof( * V_35 ) ) ;
V_95:
F_13 ( V_71 , V_19 ) ;
return;
V_69:
F_6 ( V_71 ) ;
}
void T_6 F_82 ( void )
{
unsigned int V_96 ;
V_91 = F_83 ( V_34 , V_97 ) ;
F_84 (i) {
F_85 ( & ( F_45 ( V_56 , V_96 ) . V_27 ) ) ;
F_86 ( & ( F_45 ( V_56 , V_96 ) . V_26 ) ) ;
}
}
static int T_6 F_87 ( void )
{
int V_17 ;
V_17 = F_88 ( & V_13 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_89 ( & V_13 , & V_98 ) ;
if ( V_17 < 0 )
goto V_69;
V_17 = F_89 ( & V_13 , & V_99 ) ;
if ( V_17 < 0 )
goto V_100;
V_94 = 1 ;
F_90 ( L_1 , V_101 ) ;
return 0 ;
V_100:
F_91 ( & V_13 , & V_98 ) ;
V_69:
F_92 ( & V_13 ) ;
return V_17 ;
}
