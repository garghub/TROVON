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
F_11 ( V_7 , V_8 ) ;
return F_12 ( V_7 , V_2 ) ;
}
static void F_13 ( struct V_4 * V_7 ,
struct V_17 * V_18 )
{
struct V_15 * V_16 = F_8 ( F_9 ( V_7 ) ) ;
struct V_19 * V_20 , * V_21 ;
struct V_4 * V_22 , * V_23 = V_7 ;
void * V_8 = F_10 ( V_16 ) ;
int V_24 , V_25 = 0 ;
F_11 ( V_7 , V_8 ) ;
V_24 = 0 ;
F_14 ( & V_18 -> V_26 ) ;
F_15 (s, &listeners->list, list) {
V_22 = NULL ;
if ( ! F_16 ( & V_20 -> V_27 , & V_18 -> V_27 ) ) {
V_22 = F_17 ( V_23 , V_9 ) ;
if ( ! V_22 )
break;
}
V_24 = F_18 ( & V_28 , V_23 , V_20 -> V_29 ) ;
if ( V_24 == - V_30 ) {
V_20 -> V_31 = 0 ;
V_25 ++ ;
}
V_23 = V_22 ;
}
F_19 ( & V_18 -> V_26 ) ;
if ( V_23 )
F_6 ( V_23 ) ;
if ( ! V_25 )
return;
F_20 ( & V_18 -> V_26 ) ;
F_21 (s, tmp, &listeners->list, list) {
if ( ! V_20 -> V_31 ) {
F_22 ( & V_20 -> V_27 ) ;
F_23 ( V_20 ) ;
}
}
F_24 ( & V_18 -> V_26 ) ;
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
int V_24 = - V_44 ;
T_4 V_49 , V_50 , V_51 ;
T_4 V_52 ;
F_30 () ;
V_47 = F_31 ( V_46 ) ;
if ( ! V_47 || ! F_38 ( V_47 , & V_48 ) )
goto V_53;
if ( V_47 -> signal -> V_39 )
memcpy ( V_39 , V_47 -> signal -> V_39 , sizeof( * V_39 ) ) ;
else
memset ( V_39 , 0 , sizeof( * V_39 ) ) ;
V_37 = V_47 ;
V_52 = F_39 () ;
do {
if ( V_37 -> V_54 )
continue;
F_26 ( V_39 , V_37 ) ;
V_49 = V_52 - V_37 -> V_52 ;
F_40 ( V_49 , V_55 ) ;
V_39 -> V_56 += V_49 ;
F_41 ( V_37 , & V_50 , & V_51 ) ;
V_39 -> V_57 += F_42 ( V_50 , V_55 ) ;
V_39 -> V_58 += F_42 ( V_51 , V_55 ) ;
V_39 -> V_42 += V_37 -> V_42 ;
V_39 -> V_43 += V_37 -> V_43 ;
} while_each_thread(first, tsk) ;
void F_43 ( struct V_36 * V_37 )
{
unsigned long V_48 ;
F_44 ( & V_37 -> V_59 -> V_60 , V_48 ) ;
if ( ! V_37 -> signal -> V_39 )
goto V_61;
F_26 ( V_37 -> signal -> V_39 , V_37 ) ;
V_61:
F_45 ( & V_37 -> V_59 -> V_60 , V_48 ) ;
return;
}
static int F_46 ( T_3 V_29 , const struct V_62 * V_63 , int V_64 )
{
struct V_17 * V_18 ;
struct V_19 * V_20 , * V_21 , * V_65 ;
unsigned int V_66 ;
int V_61 = 0 ;
if ( ! F_47 ( V_63 , V_67 ) )
return - V_14 ;
if ( F_34 () != & V_68 )
return - V_14 ;
if ( F_35 ( V_45 ) != & V_69 )
return - V_14 ;
if ( V_64 == REGISTER ) {
F_48 (cpu, mask) {
V_20 = F_49 ( sizeof( struct V_19 ) ,
V_9 , F_50 ( V_66 ) ) ;
if ( ! V_20 ) {
V_61 = - V_10 ;
goto V_70;
}
V_20 -> V_29 = V_29 ;
V_20 -> V_31 = 1 ;
V_18 = & F_51 ( V_71 , V_66 ) ;
F_20 ( & V_18 -> V_26 ) ;
F_15 (s2, &listeners->list, list) {
if ( V_65 -> V_29 == V_29 && V_65 -> V_31 )
goto V_72;
}
F_52 ( & V_20 -> V_27 , & V_18 -> V_27 ) ;
V_20 = NULL ;
V_72:
F_24 ( & V_18 -> V_26 ) ;
F_23 ( V_20 ) ;
}
return 0 ;
}
V_70:
F_48 (cpu, mask) {
V_18 = & F_51 ( V_71 , V_66 ) ;
F_20 ( & V_18 -> V_26 ) ;
F_21 (s, tmp, &listeners->list, list) {
if ( V_20 -> V_29 == V_29 ) {
F_22 ( & V_20 -> V_27 ) ;
F_23 ( V_20 ) ;
break;
}
}
F_24 ( & V_18 -> V_26 ) ;
}
return V_61 ;
}
static int F_53 ( struct V_73 * V_74 , struct V_62 * V_63 )
{
char * V_75 ;
int V_76 ;
int V_61 ;
if ( V_74 == NULL )
return 1 ;
V_76 = F_54 ( V_74 ) ;
if ( V_76 > V_77 )
return - V_78 ;
if ( V_76 < 1 )
return - V_14 ;
V_75 = F_55 ( V_76 , V_9 ) ;
if ( ! V_75 )
return - V_10 ;
F_56 ( V_75 , V_74 , V_76 ) ;
V_61 = F_57 ( V_75 , V_63 ) ;
F_23 ( V_75 ) ;
return V_61 ;
}
static struct V_38 * F_58 ( struct V_4 * V_7 , int type , T_5 V_29 )
{
struct V_73 * V_74 , * V_61 ;
int V_79 ;
V_79 = ( type == V_80 )
? V_81
: V_82 ;
V_74 = F_59 ( V_7 , V_79 ) ;
if ( ! V_74 )
goto V_83;
if ( F_60 ( V_7 , type , sizeof( V_29 ) , & V_29 ) < 0 ) {
F_61 ( V_7 , V_74 ) ;
goto V_83;
}
V_61 = F_62 ( V_7 , V_84 ,
sizeof( struct V_38 ) , V_85 ) ;
if ( ! V_61 ) {
F_61 ( V_7 , V_74 ) ;
goto V_83;
}
F_63 ( V_7 , V_74 ) ;
return F_64 ( V_61 ) ;
V_83:
return NULL ;
}
static int F_65 ( struct V_4 * V_7 , struct V_1 * V_2 )
{
int V_24 = 0 ;
struct V_4 * V_86 ;
struct V_87 * V_39 ;
struct V_73 * V_74 ;
T_2 V_6 ;
T_5 V_88 ;
struct V_88 V_89 ;
V_74 = V_2 -> V_90 [ V_91 ] ;
if ( ! V_74 )
return - V_14 ;
V_88 = F_66 ( V_2 -> V_90 [ V_91 ] ) ;
V_89 = F_67 ( V_88 ) ;
if ( ! V_89 . V_92 )
return 0 ;
V_6 = F_68 ( sizeof( struct V_87 ) ) ;
V_24 = F_1 ( V_2 , V_93 , & V_86 ,
V_6 ) ;
if ( V_24 < 0 )
goto V_83;
V_74 = F_69 ( V_86 , V_94 ,
sizeof( struct V_87 ) ) ;
if ( V_74 == NULL ) {
F_6 ( V_86 ) ;
V_24 = - V_95 ;
goto V_83;
}
V_39 = F_64 ( V_74 ) ;
memset ( V_39 , 0 , sizeof( * V_39 ) ) ;
V_24 = F_70 ( V_39 , V_89 . V_92 -> V_96 . V_97 ) ;
if ( V_24 < 0 ) {
F_6 ( V_86 ) ;
goto V_83;
}
V_24 = F_7 ( V_86 , V_2 ) ;
V_83:
F_71 ( V_89 ) ;
return V_24 ;
}
static int F_72 ( struct V_1 * V_2 )
{
T_6 V_63 ;
int V_24 ;
if ( ! F_73 ( & V_63 , V_9 ) )
return - V_10 ;
V_24 = F_53 ( V_2 -> V_90 [ V_98 ] , V_63 ) ;
if ( V_24 < 0 )
goto V_53;
V_24 = F_46 ( V_2 -> V_99 , V_63 , REGISTER ) ;
V_53:
F_74 ( V_63 ) ;
return V_24 ;
}
static int F_75 ( struct V_1 * V_2 )
{
T_6 V_63 ;
int V_24 ;
if ( ! F_73 ( & V_63 , V_9 ) )
return - V_10 ;
V_24 = F_53 ( V_2 -> V_90 [ V_100 ] , V_63 ) ;
if ( V_24 < 0 )
goto V_53;
V_24 = F_46 ( V_2 -> V_99 , V_63 , V_101 ) ;
V_53:
F_74 ( V_63 ) ;
return V_24 ;
}
static T_2 F_76 ( void )
{
T_2 V_6 ;
V_6 = F_68 ( sizeof( T_5 ) ) +
F_77 ( sizeof( struct V_38 ) ) +
F_68 ( 0 ) ;
return V_6 ;
}
static int F_78 ( struct V_1 * V_2 )
{
struct V_38 * V_39 ;
struct V_4 * V_86 ;
T_2 V_6 ;
T_5 V_29 ;
int V_24 ;
V_6 = F_76 () ;
V_24 = F_1 ( V_2 , V_102 , & V_86 , V_6 ) ;
if ( V_24 < 0 )
return V_24 ;
V_24 = - V_14 ;
V_29 = F_66 ( V_2 -> V_90 [ V_103 ] ) ;
V_39 = F_58 ( V_86 , V_80 , V_29 ) ;
if ( ! V_39 )
goto V_83;
V_24 = F_29 ( V_29 , V_39 ) ;
if ( V_24 < 0 )
goto V_83;
return F_7 ( V_86 , V_2 ) ;
V_83:
F_6 ( V_86 ) ;
return V_24 ;
}
static int F_79 ( struct V_1 * V_2 )
{
struct V_38 * V_39 ;
struct V_4 * V_86 ;
T_2 V_6 ;
T_5 V_46 ;
int V_24 ;
V_6 = F_76 () ;
V_24 = F_1 ( V_2 , V_102 , & V_86 , V_6 ) ;
if ( V_24 < 0 )
return V_24 ;
V_24 = - V_14 ;
V_46 = F_66 ( V_2 -> V_90 [ V_104 ] ) ;
V_39 = F_58 ( V_86 , V_105 , V_46 ) ;
if ( ! V_39 )
goto V_83;
V_24 = F_37 ( V_46 , V_39 ) ;
if ( V_24 < 0 )
goto V_83;
return F_7 ( V_86 , V_2 ) ;
V_83:
F_6 ( V_86 ) ;
return V_24 ;
}
static int F_80 ( struct V_4 * V_7 , struct V_1 * V_2 )
{
if ( V_2 -> V_90 [ V_98 ] )
return F_72 ( V_2 ) ;
else if ( V_2 -> V_90 [ V_100 ] )
return F_75 ( V_2 ) ;
else if ( V_2 -> V_90 [ V_103 ] )
return F_78 ( V_2 ) ;
else if ( V_2 -> V_90 [ V_104 ] )
return F_79 ( V_2 ) ;
else
return - V_14 ;
}
static struct V_38 * F_81 ( struct V_36 * V_37 )
{
struct V_106 * V_107 = V_37 -> signal ;
struct V_38 * V_39 ;
if ( V_107 -> V_39 || F_82 ( V_37 ) )
goto V_61;
V_39 = F_83 ( V_108 , V_9 ) ;
F_84 ( & V_37 -> V_59 -> V_60 ) ;
if ( ! V_107 -> V_39 ) {
V_107 -> V_39 = V_39 ;
V_39 = NULL ;
}
F_85 ( & V_37 -> V_59 -> V_60 ) ;
if ( V_39 )
F_86 ( V_108 , V_39 ) ;
V_61:
return V_107 -> V_39 ;
}
void F_87 ( struct V_36 * V_37 , int V_109 )
{
int V_24 ;
struct V_17 * V_18 ;
struct V_38 * V_39 ;
struct V_4 * V_86 ;
T_2 V_6 ;
int V_110 ;
if ( ! V_111 )
return;
V_6 = F_76 () ;
V_110 = ! ! F_81 ( V_37 ) ;
if ( V_110 ) {
V_6 = 2 * V_6 ;
F_43 ( V_37 ) ;
}
V_18 = F_88 ( & V_71 ) ;
if ( F_89 ( & V_18 -> V_27 ) )
return;
V_24 = F_1 ( NULL , V_102 , & V_86 , V_6 ) ;
if ( V_24 < 0 )
return;
V_39 = F_58 ( V_86 , V_80 ,
F_90 ( V_37 , & V_69 ) ) ;
if ( ! V_39 )
goto V_83;
F_25 ( & V_68 , & V_69 , V_37 , V_39 ) ;
if ( ! V_110 || ! V_109 )
goto V_112;
V_39 = F_58 ( V_86 , V_105 ,
F_91 ( V_37 , & V_69 ) ) ;
if ( ! V_39 )
goto V_83;
memcpy ( V_39 , V_37 -> signal -> V_39 , sizeof( * V_39 ) ) ;
V_112:
F_13 ( V_86 , V_18 ) ;
return;
V_83:
F_6 ( V_86 ) ;
}
void T_7 F_92 ( void )
{
unsigned int V_113 ;
V_108 = F_93 ( V_38 , V_114 ) ;
F_94 (i) {
F_95 ( & ( F_51 ( V_71 , V_113 ) . V_27 ) ) ;
F_96 ( & ( F_51 ( V_71 , V_113 ) . V_26 ) ) ;
}
}
static int T_7 F_97 ( void )
{
int V_24 ;
V_24 = F_98 ( & V_13 ) ;
if ( V_24 )
return V_24 ;
V_111 = 1 ;
F_99 ( L_1 , V_115 ) ;
return 0 ;
}
