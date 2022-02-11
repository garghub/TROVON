static struct V_1 * F_1 ( struct V_2 * V_3 ,
const char * V_4 )
{
struct V_1 * V_5 ;
V_5 = F_2 ( sizeof( * V_5 ) , V_6 ) ;
if ( ! V_5 )
return F_3 ( - V_7 ) ;
F_4 ( & V_5 -> V_8 ) ;
F_4 ( & V_5 -> V_9 ) ;
V_5 -> V_3 = V_3 ;
V_5 -> V_4 = F_5 ( V_4 , V_6 ) ;
F_6 ( & V_5 -> V_10 ) ;
F_6 ( & V_5 -> V_11 ) ;
F_7 ( & V_5 -> V_12 ) ;
F_8 ( & V_5 -> V_13 , V_14 ) ;
F_9 ( & V_5 -> V_15 ) ;
F_9 ( & V_5 -> V_16 ) ;
F_10 ( & V_5 -> V_17 ) ;
return V_5 ;
}
static void F_11 ( struct V_18 * V_19 )
{
struct V_1 * V_5 = F_12 ( V_19 , struct V_1 ,
V_17 ) ;
unsigned long V_20 ;
F_13 ( & V_5 -> V_9 , V_20 ) ;
F_14 ( & V_5 -> V_15 ) ;
F_14 ( & V_5 -> V_16 ) ;
F_15 ( & V_5 -> V_9 , V_20 ) ;
F_16 ( V_5 -> V_4 ) ;
F_16 ( V_5 ) ;
}
static T_1 F_17 ( struct V_2 * V_3 )
{
return V_3 -> V_21 -> V_22 ( V_3 -> V_21 ) ;
}
static void F_18 ( struct V_2 * V_3 ,
void * V_23 , unsigned int V_24 , T_1 V_25 )
{
V_3 -> V_21 -> V_26 ( V_3 -> V_21 , V_23 , V_24 , V_25 ) ;
}
static void F_19 ( struct V_2 * V_3 , T_1 V_25 )
{
V_3 -> V_21 -> V_27 ( V_3 -> V_21 , V_25 ) ;
}
static T_1 F_20 ( struct V_2 * V_3 )
{
return V_3 -> V_28 -> V_22 ( V_3 -> V_28 ) ;
}
static void F_21 ( struct V_2 * V_3 ,
const void * V_29 , T_1 V_30 ,
const void * V_23 , T_1 V_31 )
{
V_3 -> V_28 -> V_32 ( V_3 -> V_28 , V_29 , V_30 , V_23 , V_31 ) ;
}
static int F_22 ( struct V_2 * V_3 ,
const void * V_29 , T_1 V_30 ,
const void * V_23 , T_1 V_31 , bool V_33 )
{
unsigned int V_34 = V_30 + V_31 ;
int V_35 ;
if ( V_34 >= V_3 -> V_28 -> V_36 )
return - V_37 ;
V_35 = F_23 ( & V_3 -> V_38 ) ;
if ( V_35 )
return V_35 ;
while ( F_20 ( V_3 ) < V_34 ) {
if ( ! V_33 ) {
V_35 = - V_39 ;
goto V_40;
}
F_24 ( 10000 , 15000 ) ;
}
F_21 ( V_3 , V_29 , V_30 , V_23 , V_31 ) ;
F_25 ( V_3 -> V_41 , NULL ) ;
F_26 ( V_3 -> V_41 , 0 ) ;
V_40:
F_27 ( & V_3 -> V_38 ) ;
return V_35 ;
}
static int F_28 ( struct V_2 * V_3 )
{
struct V_42 V_43 ;
V_43 . V_44 = F_29 ( V_45 ) ;
V_43 . V_46 = F_29 ( V_47 ) ;
V_43 . V_48 = F_30 ( V_3 -> V_49 ) ;
return F_22 ( V_3 , & V_43 , sizeof( V_43 ) , NULL , 0 , true ) ;
}
static void F_31 ( struct V_2 * V_3 )
{
struct V_42 V_43 ;
V_43 . V_44 = F_29 ( V_50 ) ;
V_43 . V_46 = F_29 ( V_47 ) ;
V_43 . V_48 = F_30 ( V_3 -> V_49 ) ;
F_22 ( V_3 , & V_43 , sizeof( V_43 ) , NULL , 0 , true ) ;
}
static void F_32 ( struct V_2 * V_3 ,
struct V_1 * V_5 )
{
struct V_42 V_43 ;
V_43 . V_44 = F_29 ( V_51 ) ;
V_43 . V_46 = F_29 ( V_5 -> V_52 ) ;
V_43 . V_48 = F_30 ( 0 ) ;
F_22 ( V_3 , & V_43 , sizeof( V_43 ) , NULL , 0 , true ) ;
}
static void F_33 ( struct V_2 * V_3 ,
unsigned int V_53 , bool V_54 )
{
struct V_1 * V_5 ;
unsigned long V_20 ;
F_13 ( & V_3 -> V_55 , V_20 ) ;
V_5 = F_34 ( & V_3 -> V_56 , V_53 ) ;
F_15 ( & V_3 -> V_55 , V_20 ) ;
if ( ! V_5 ) {
F_35 ( V_3 -> V_57 , L_1 ) ;
return;
}
V_5 -> V_58 = V_54 ;
F_36 ( & V_5 -> V_59 ) ;
}
static int F_37 ( struct V_2 * V_3 ,
struct V_1 * V_5 )
{
struct {
struct V_42 V_43 ;
T_2 V_4 [ V_60 ] ;
} V_61 V_62 ;
int V_63 = strlen ( V_5 -> V_4 ) + 1 ;
int V_64 = F_38 ( sizeof( V_62 . V_43 ) + V_63 , 8 ) ;
int V_35 ;
unsigned long V_20 ;
F_39 ( & V_5 -> V_17 ) ;
F_13 ( & V_3 -> V_55 , V_20 ) ;
V_35 = F_40 ( & V_3 -> V_65 , V_5 ,
V_66 , V_67 ,
V_68 ) ;
F_15 ( & V_3 -> V_55 , V_20 ) ;
if ( V_35 < 0 )
return V_35 ;
V_5 -> V_69 = V_35 ;
V_62 . V_43 . V_44 = F_29 ( V_70 ) ;
V_62 . V_43 . V_46 = F_29 ( V_5 -> V_69 ) ;
V_62 . V_43 . V_48 = F_30 ( V_63 ) ;
strcpy ( V_62 . V_4 , V_5 -> V_4 ) ;
V_35 = F_22 ( V_3 , & V_62 , V_64 , NULL , 0 , true ) ;
if ( V_35 )
goto V_71;
return 0 ;
V_71:
F_13 ( & V_3 -> V_55 , V_20 ) ;
F_41 ( & V_3 -> V_65 , V_5 -> V_69 ) ;
V_5 -> V_69 = 0 ;
F_15 ( & V_3 -> V_55 , V_20 ) ;
return V_35 ;
}
static void F_42 ( struct V_2 * V_3 ,
struct V_1 * V_5 )
{
struct V_42 V_62 ;
V_62 . V_44 = F_29 ( V_72 ) ;
V_62 . V_46 = F_29 ( V_5 -> V_69 ) ;
V_62 . V_48 = 0 ;
F_22 ( V_3 , & V_62 , sizeof( V_62 ) , NULL , 0 , true ) ;
}
static void F_43 ( struct V_2 * V_3 ,
unsigned int V_52 )
{
struct V_42 V_62 ;
V_62 . V_44 = F_29 ( V_73 ) ;
V_62 . V_46 = F_29 ( V_52 ) ;
V_62 . V_48 = 0 ;
F_22 ( V_3 , & V_62 , sizeof( V_62 ) , NULL , 0 , true ) ;
}
static void V_14 ( struct V_74 * V_75 )
{
struct V_1 * V_5 = F_12 ( V_75 , struct V_1 ,
V_13 ) ;
struct V_2 * V_3 = V_5 -> V_3 ;
struct V_76 * V_77 , * V_78 ;
struct {
T_3 V_79 ;
T_3 V_69 ;
T_4 V_80 ;
} V_61 V_44 ;
unsigned int V_53 = V_5 -> V_69 ;
unsigned int V_81 ;
bool V_82 ;
unsigned long V_20 ;
F_13 ( & V_5 -> V_9 , V_20 ) ;
F_44 (intent, tmp, &channel->done_intents, node) {
F_45 ( & V_77 -> V_83 ) ;
F_15 ( & V_5 -> V_9 , V_20 ) ;
V_81 = V_77 -> V_79 ;
V_82 = V_77 -> V_82 ;
V_44 . V_79 = V_82 ? V_84 : V_85 ;
V_44 . V_69 = V_53 ;
V_44 . V_80 = V_81 ;
F_22 ( V_3 , & V_44 , sizeof( V_44 ) , NULL , 0 , true ) ;
if ( ! V_82 ) {
F_16 ( V_77 -> V_23 ) ;
F_16 ( V_77 ) ;
}
F_13 ( & V_5 -> V_9 , V_20 ) ;
}
F_15 ( & V_5 -> V_9 , V_20 ) ;
}
static void F_46 ( struct V_2 * V_3 ,
struct V_1 * V_5 ,
struct V_76 * V_77 )
{
if ( V_3 -> V_86 ) {
F_16 ( V_77 -> V_23 ) ;
F_16 ( V_77 ) ;
return;
}
if ( ! V_77 -> V_82 ) {
F_47 ( & V_5 -> V_9 ) ;
F_41 ( & V_5 -> V_15 , V_77 -> V_79 ) ;
F_48 ( & V_5 -> V_9 ) ;
}
F_47 ( & V_5 -> V_9 ) ;
F_49 ( & V_77 -> V_83 , & V_5 -> V_12 ) ;
F_48 ( & V_5 -> V_9 ) ;
F_50 ( & V_5 -> V_13 ) ;
}
static void F_51 ( struct V_2 * V_3 ,
T_4 V_87 ,
T_4 V_49 )
{
switch ( V_87 ) {
case 0 :
break;
case V_47 :
V_3 -> V_49 &= V_49 ;
default:
F_31 ( V_3 ) ;
break;
}
}
static void F_52 ( struct V_2 * V_3 ,
T_4 V_87 ,
T_4 V_49 )
{
switch ( V_87 ) {
case 0 :
break;
case V_47 :
if ( V_49 == V_3 -> V_49 )
break;
V_3 -> V_49 &= V_49 ;
default:
F_28 ( V_3 ) ;
break;
}
}
static int F_53 ( struct V_2 * V_3 ,
struct V_1 * V_5 ,
bool V_54 )
{
struct V_42 V_43 ;
V_43 . V_44 = F_29 ( V_88 ) ;
V_43 . V_46 = F_29 ( V_5 -> V_69 ) ;
V_43 . V_48 = F_30 ( V_54 ) ;
F_22 ( V_3 , & V_43 , sizeof( V_43 ) , NULL , 0 , true ) ;
return 0 ;
}
static int F_54 ( struct V_2 * V_3 ,
struct V_1 * V_5 ,
struct V_76 * V_77 )
{
struct V_89 {
T_3 V_79 ;
T_3 V_69 ;
T_4 V_25 ;
T_4 V_90 ;
T_4 V_80 ;
} V_61 ;
struct V_89 V_44 ;
V_44 . V_79 = F_29 ( V_91 ) ;
V_44 . V_69 = F_29 ( V_5 -> V_69 ) ;
V_44 . V_25 = F_30 ( 1 ) ;
V_44 . V_90 = F_30 ( V_77 -> V_90 ) ;
V_44 . V_80 = F_30 ( V_77 -> V_79 ) ;
F_22 ( V_3 , & V_44 , sizeof( V_44 ) , NULL , 0 , true ) ;
return 0 ;
}
static struct V_76 *
F_55 ( struct V_2 * V_3 ,
struct V_1 * V_5 ,
T_1 V_90 ,
bool V_92 )
{
struct V_76 * V_77 ;
int V_35 ;
unsigned long V_20 ;
V_77 = F_2 ( sizeof( * V_77 ) , V_6 ) ;
if ( ! V_77 )
return NULL ;
V_77 -> V_23 = F_2 ( V_90 , V_6 ) ;
if ( ! V_77 -> V_23 )
goto V_93;
F_13 ( & V_5 -> V_9 , V_20 ) ;
V_35 = F_40 ( & V_5 -> V_15 , V_77 , 1 , - 1 , V_68 ) ;
if ( V_35 < 0 ) {
F_15 ( & V_5 -> V_9 , V_20 ) ;
goto V_94;
}
F_15 ( & V_5 -> V_9 , V_20 ) ;
V_77 -> V_79 = V_35 ;
V_77 -> V_90 = V_90 ;
V_77 -> V_82 = V_92 ;
return V_77 ;
V_94:
F_16 ( V_77 -> V_23 ) ;
V_93:
F_16 ( V_77 ) ;
return NULL ;
}
static void F_56 ( struct V_2 * V_3 ,
T_4 V_53 , T_5 V_81 ,
bool V_82 )
{
struct V_76 * V_77 ;
struct V_1 * V_5 ;
unsigned long V_20 ;
F_13 ( & V_3 -> V_55 , V_20 ) ;
V_5 = F_34 ( & V_3 -> V_56 , V_53 ) ;
F_15 ( & V_3 -> V_55 , V_20 ) ;
if ( ! V_5 ) {
F_35 ( V_3 -> V_57 , L_2 ) ;
return;
}
F_13 ( & V_5 -> V_9 , V_20 ) ;
V_77 = F_34 ( & V_5 -> V_16 , V_81 ) ;
if ( ! V_77 ) {
F_15 ( & V_5 -> V_9 , V_20 ) ;
F_35 ( V_3 -> V_57 , L_3 ) ;
return;
}
V_77 -> V_95 = false ;
if ( ! V_82 ) {
F_41 ( & V_5 -> V_16 , V_77 -> V_79 ) ;
F_16 ( V_77 ) ;
}
F_15 ( & V_5 -> V_9 , V_20 ) ;
}
static void F_57 ( struct V_2 * V_3 ,
T_4 V_53 , T_1 V_90 )
{
struct V_76 * V_77 ;
struct V_1 * V_5 ;
unsigned long V_20 ;
F_13 ( & V_3 -> V_55 , V_20 ) ;
V_5 = F_34 ( & V_3 -> V_56 , V_53 ) ;
F_15 ( & V_3 -> V_55 , V_20 ) ;
if ( ! V_5 ) {
F_58 ( L_4 , V_96 , V_53 ) ;
return;
}
V_77 = F_55 ( V_3 , V_5 , V_90 , false ) ;
if ( V_77 )
F_54 ( V_3 , V_5 , V_77 ) ;
F_53 ( V_3 , V_5 , ! ! V_77 ) ;
}
static int F_59 ( struct V_2 * V_3 , T_1 V_97 )
{
struct V_98 * V_99 ;
V_97 = F_38 ( V_97 , 8 ) ;
if ( F_17 ( V_3 ) < sizeof( struct V_42 ) + V_97 ) {
F_60 ( V_3 -> V_57 , L_5 ) ;
return - V_100 ;
}
V_99 = F_2 ( sizeof( * V_99 ) + V_97 , V_68 ) ;
if ( ! V_99 )
return - V_7 ;
F_7 ( & V_99 -> V_83 ) ;
F_18 ( V_3 , & V_99 -> V_43 , 0 , sizeof( V_99 -> V_43 ) + V_97 ) ;
F_47 ( & V_3 -> V_101 ) ;
F_49 ( & V_99 -> V_83 , & V_3 -> V_102 ) ;
F_48 ( & V_3 -> V_101 ) ;
F_50 ( & V_3 -> V_103 ) ;
F_19 ( V_3 , sizeof( V_99 -> V_43 ) + V_97 ) ;
return 0 ;
}
static int F_61 ( struct V_2 * V_3 , T_1 V_22 )
{
struct V_76 * V_77 ;
struct V_1 * V_5 ;
struct {
struct V_42 V_43 ;
T_6 V_104 ;
T_6 V_105 ;
} V_61 V_29 ;
unsigned int V_104 ;
unsigned int V_105 ;
unsigned int V_52 ;
unsigned int V_80 ;
int V_35 = 0 ;
unsigned long V_20 ;
if ( V_22 < sizeof( V_29 ) ) {
F_60 ( V_3 -> V_57 , L_6 ) ;
return - V_39 ;
}
F_18 ( V_3 , & V_29 , 0 , sizeof( V_29 ) ) ;
V_104 = F_62 ( V_29 . V_104 ) ;
V_105 = F_62 ( V_29 . V_105 ) ;
if ( V_22 < sizeof( V_29 ) + V_104 ) {
F_60 ( V_3 -> V_57 , L_7 ) ;
return - V_39 ;
}
if ( F_63 ( V_104 % 4 , L_8 ) )
return - V_37 ;
V_52 = F_64 ( V_29 . V_43 . V_46 ) ;
F_13 ( & V_3 -> V_55 , V_20 ) ;
V_5 = F_34 ( & V_3 -> V_56 , V_52 ) ;
F_15 ( & V_3 -> V_55 , V_20 ) ;
if ( ! V_5 ) {
F_60 ( V_3 -> V_57 , L_9 ) ;
goto V_106;
}
if ( V_3 -> V_86 ) {
if ( ! V_5 -> V_107 ) {
V_77 = F_2 ( sizeof( * V_77 ) , V_68 ) ;
if ( ! V_77 )
return - V_7 ;
V_77 -> V_23 = F_65 ( V_104 + V_105 ,
V_68 ) ;
if ( ! V_77 -> V_23 ) {
F_16 ( V_77 ) ;
return - V_7 ;
}
V_77 -> V_79 = 0xbabababa ;
V_77 -> V_90 = V_104 + V_105 ;
V_77 -> V_24 = 0 ;
V_5 -> V_107 = V_77 ;
} else {
V_77 = V_5 -> V_107 ;
}
} else {
V_80 = F_62 ( V_29 . V_43 . V_48 ) ;
F_13 ( & V_5 -> V_9 , V_20 ) ;
V_77 = F_34 ( & V_5 -> V_15 , V_80 ) ;
F_15 ( & V_5 -> V_9 , V_20 ) ;
if ( ! V_77 ) {
F_35 ( V_3 -> V_57 ,
L_10 ,
V_5 -> V_4 , V_80 ) ;
goto V_106;
}
}
if ( V_77 -> V_90 - V_77 -> V_24 < V_104 ) {
F_35 ( V_3 -> V_57 , L_11 ) ;
goto V_106;
}
F_18 ( V_3 , V_77 -> V_23 + V_77 -> V_24 ,
sizeof( V_29 ) , V_104 ) ;
V_77 -> V_24 += V_104 ;
if ( ! V_105 ) {
F_47 ( & V_5 -> V_8 ) ;
if ( V_5 -> V_108 . V_109 ) {
V_5 -> V_108 . V_109 ( V_5 -> V_108 . V_110 ,
V_77 -> V_23 ,
V_77 -> V_24 ,
V_5 -> V_108 . V_111 ,
V_112 ) ;
}
F_48 ( & V_5 -> V_8 ) ;
V_77 -> V_24 = 0 ;
V_5 -> V_107 = NULL ;
F_46 ( V_3 , V_5 , V_77 ) ;
}
V_106:
F_19 ( V_3 , F_38 ( sizeof( V_29 ) + V_104 , 8 ) ) ;
return V_35 ;
}
static void F_66 ( struct V_2 * V_3 ,
unsigned int V_53 ,
unsigned int V_25 ,
T_1 V_22 )
{
struct V_76 * V_77 ;
struct V_1 * V_5 ;
struct V_113 {
T_6 V_90 ;
T_6 V_81 ;
};
struct {
struct V_42 V_43 ;
struct V_113 V_114 [] ;
} V_61 * V_43 ;
const T_1 V_115 = sizeof( * V_43 ) + sizeof( struct V_113 ) * V_25 ;
int V_35 ;
int V_116 ;
unsigned long V_20 ;
if ( V_22 < V_115 ) {
F_60 ( V_3 -> V_57 , L_6 ) ;
return;
}
F_13 ( & V_3 -> V_55 , V_20 ) ;
V_5 = F_34 ( & V_3 -> V_56 , V_53 ) ;
F_15 ( & V_3 -> V_55 , V_20 ) ;
if ( ! V_5 ) {
F_35 ( V_3 -> V_57 , L_12 ) ;
return;
}
V_43 = F_65 ( V_115 , V_68 ) ;
if ( ! V_43 )
return;
F_18 ( V_3 , V_43 , 0 , V_115 ) ;
for ( V_116 = 0 ; V_116 < V_25 ; ++ V_116 ) {
V_77 = F_2 ( sizeof( * V_77 ) , V_68 ) ;
if ( ! V_77 )
break;
V_77 -> V_79 = F_62 ( V_43 -> V_114 [ V_116 ] . V_81 ) ;
V_77 -> V_90 = F_62 ( V_43 -> V_114 [ V_116 ] . V_90 ) ;
F_13 ( & V_5 -> V_9 , V_20 ) ;
V_35 = F_67 ( & V_5 -> V_16 , V_77 ,
V_77 -> V_79 , V_77 -> V_79 + 1 , V_68 ) ;
F_15 ( & V_5 -> V_9 , V_20 ) ;
if ( V_35 < 0 )
F_35 ( V_3 -> V_57 , L_13 ) ;
}
F_16 ( V_43 ) ;
F_19 ( V_3 , F_38 ( V_115 , 8 ) ) ;
}
static int F_68 ( struct V_2 * V_3 , unsigned int V_69 )
{
struct V_1 * V_5 ;
F_47 ( & V_3 -> V_55 ) ;
V_5 = F_34 ( & V_3 -> V_65 , V_69 ) ;
F_48 ( & V_3 -> V_55 ) ;
if ( ! V_5 ) {
F_35 ( V_3 -> V_57 , L_14 ) ;
return - V_37 ;
}
F_36 ( & V_5 -> V_11 ) ;
return 0 ;
}
static T_7 F_69 ( int V_117 , void * V_23 )
{
struct V_2 * V_3 = V_23 ;
struct V_42 V_43 ;
unsigned int V_46 ;
unsigned int V_48 ;
unsigned int V_22 ;
unsigned int V_44 ;
int V_35 = 0 ;
for (; ; ) {
V_22 = F_17 ( V_3 ) ;
if ( V_22 < sizeof( V_43 ) )
break;
F_18 ( V_3 , & V_43 , 0 , sizeof( V_43 ) ) ;
V_44 = F_64 ( V_43 . V_44 ) ;
V_46 = F_64 ( V_43 . V_46 ) ;
V_48 = F_62 ( V_43 . V_48 ) ;
switch ( V_44 ) {
case V_45 :
case V_50 :
case V_72 :
case V_73 :
case V_118 :
V_35 = F_59 ( V_3 , 0 ) ;
break;
case V_51 :
V_35 = F_68 ( V_3 , V_46 ) ;
F_19 ( V_3 , F_38 ( sizeof( V_43 ) , 8 ) ) ;
break;
case V_70 :
V_35 = F_59 ( V_3 , V_48 ) ;
break;
case V_119 :
case V_120 :
V_35 = F_61 ( V_3 , V_22 ) ;
break;
case V_121 :
F_19 ( V_3 , F_38 ( sizeof( V_43 ) , 8 ) ) ;
F_25 ( V_3 -> V_41 , NULL ) ;
F_26 ( V_3 -> V_41 , 0 ) ;
break;
case V_91 :
F_66 ( V_3 , V_46 , V_48 , V_22 ) ;
break;
case V_85 :
F_56 ( V_3 , V_46 , V_48 , false ) ;
F_19 ( V_3 , F_38 ( sizeof( V_43 ) , 8 ) ) ;
break;
case V_84 :
F_56 ( V_3 , V_46 , V_48 , true ) ;
F_19 ( V_3 , F_38 ( sizeof( V_43 ) , 8 ) ) ;
break;
case V_88 :
F_33 ( V_3 , V_46 , V_48 ) ;
F_19 ( V_3 , F_38 ( sizeof( V_43 ) , 8 ) ) ;
break;
default:
F_35 ( V_3 -> V_57 , L_15 , V_44 ) ;
V_35 = - V_37 ;
break;
}
if ( V_35 )
break;
}
return V_122 ;
}
static struct V_1 * F_70 ( struct V_2 * V_3 ,
const char * V_4 )
{
struct V_1 * V_5 ;
int V_35 ;
unsigned long V_20 ;
V_5 = F_1 ( V_3 , V_4 ) ;
if ( F_71 ( V_5 ) )
return F_72 ( V_5 ) ;
V_35 = F_37 ( V_3 , V_5 ) ;
if ( V_35 )
goto V_123;
V_35 = F_73 ( & V_5 -> V_11 , 5 * V_124 ) ;
if ( ! V_35 )
goto V_125;
V_35 = F_73 ( & V_5 -> V_10 , 5 * V_124 ) ;
if ( ! V_35 )
goto V_125;
F_32 ( V_3 , V_5 ) ;
return V_5 ;
V_125:
F_13 ( & V_3 -> V_55 , V_20 ) ;
F_41 ( & V_3 -> V_65 , V_5 -> V_69 ) ;
F_15 ( & V_3 -> V_55 , V_20 ) ;
V_123:
F_74 ( & V_5 -> V_17 , F_11 ) ;
F_74 ( & V_5 -> V_17 , F_11 ) ;
return F_3 ( - V_126 ) ;
}
static int F_75 ( struct V_2 * V_3 ,
struct V_1 * V_5 )
{
int V_35 ;
F_32 ( V_3 , V_5 ) ;
V_35 = F_37 ( V_3 , V_5 ) ;
if ( V_35 )
goto V_127;
V_35 = F_73 ( & V_5 -> V_11 , 5 * V_124 ) ;
if ( ! V_35 ) {
V_35 = - V_126 ;
goto V_127;
}
return 0 ;
V_127:
F_42 ( V_3 , V_5 ) ;
F_74 ( & V_5 -> V_17 , F_11 ) ;
return V_35 ;
}
static struct V_128 * F_76 ( struct V_129 * V_110 ,
T_8 V_109 ,
void * V_111 ,
struct V_130
V_131 )
{
struct V_1 * V_132 = F_77 ( V_110 -> V_108 ) ;
struct V_1 * V_5 ;
struct V_2 * V_3 = V_132 -> V_3 ;
struct V_128 * V_108 ;
const char * V_4 = V_131 . V_4 ;
int V_53 ;
int V_35 ;
unsigned long V_20 ;
F_13 ( & V_3 -> V_55 , V_20 ) ;
F_78 (&glink->rcids, channel, cid) {
if ( ! strcmp ( V_5 -> V_4 , V_4 ) )
break;
}
F_15 ( & V_3 -> V_55 , V_20 ) ;
if ( ! V_5 ) {
V_5 = F_70 ( V_3 , V_4 ) ;
if ( F_71 ( V_5 ) )
return NULL ;
} else {
V_35 = F_75 ( V_3 , V_5 ) ;
if ( V_35 )
return NULL ;
}
V_108 = & V_5 -> V_108 ;
V_108 -> V_110 = V_110 ;
V_108 -> V_109 = V_109 ;
V_108 -> V_111 = V_111 ;
V_108 -> V_133 = & V_134 ;
return V_108 ;
}
static int F_79 ( struct V_129 * V_110 )
{
struct V_1 * V_5 = F_77 ( V_110 -> V_108 ) ;
struct V_76 * V_77 ;
struct V_2 * V_3 = V_5 -> V_3 ;
int V_135 = V_3 -> V_86 ? 0 : 5 ;
while ( V_135 -- ) {
V_77 = F_55 ( V_3 , V_5 , V_136 , true ) ;
if ( ! V_77 )
break;
F_54 ( V_3 , V_5 , V_77 ) ;
}
return 0 ;
}
static void F_80 ( struct V_128 * V_108 )
{
struct V_1 * V_5 = F_77 ( V_108 ) ;
struct V_2 * V_3 = V_5 -> V_3 ;
unsigned long V_20 ;
F_13 ( & V_5 -> V_8 , V_20 ) ;
V_5 -> V_108 . V_109 = NULL ;
F_15 ( & V_5 -> V_8 , V_20 ) ;
V_5 -> V_110 = NULL ;
F_42 ( V_3 , V_5 ) ;
}
static int F_81 ( struct V_2 * V_3 ,
struct V_1 * V_5 ,
T_1 V_90 )
{
struct {
T_3 V_79 ;
T_3 V_53 ;
T_4 V_90 ;
} V_61 V_44 ;
int V_35 ;
F_82 ( & V_5 -> V_137 ) ;
F_83 ( & V_5 -> V_59 ) ;
V_44 . V_79 = V_118 ;
V_44 . V_53 = V_5 -> V_69 ;
V_44 . V_90 = V_90 ;
V_35 = F_22 ( V_3 , & V_44 , sizeof( V_44 ) , NULL , 0 , true ) ;
if ( V_35 )
goto V_138;
V_35 = F_73 ( & V_5 -> V_59 , 10 * V_124 ) ;
if ( ! V_35 ) {
F_35 ( V_3 -> V_57 , L_16 ) ;
V_35 = - V_126 ;
} else {
V_35 = V_5 -> V_58 ? 0 : - V_139 ;
}
V_138:
F_27 ( & V_5 -> V_137 ) ;
return V_35 ;
}
static int F_84 ( struct V_1 * V_5 ,
void * V_23 , int V_140 , bool V_33 )
{
struct V_2 * V_3 = V_5 -> V_3 ;
struct V_76 * V_77 = NULL ;
struct V_76 * V_78 ;
int V_81 = 0 ;
struct {
struct V_42 V_43 ;
T_6 V_104 ;
T_6 V_105 ;
} V_61 V_62 ;
int V_35 ;
unsigned long V_20 ;
if ( ! V_3 -> V_86 ) {
while ( ! V_77 ) {
F_13 ( & V_5 -> V_9 , V_20 ) ;
F_78 (&channel->riids, tmp, iid) {
if ( V_78 -> V_90 >= V_140 && ! V_78 -> V_95 ) {
V_78 -> V_95 = true ;
V_77 = V_78 ;
break;
}
}
F_15 ( & V_5 -> V_9 , V_20 ) ;
if ( V_77 )
break;
if ( ! V_33 )
return - V_141 ;
V_35 = F_81 ( V_3 , V_5 , V_140 ) ;
if ( V_35 < 0 )
return V_35 ;
}
V_81 = V_77 -> V_79 ;
}
V_62 . V_43 . V_44 = F_29 ( V_119 ) ;
V_62 . V_43 . V_46 = F_29 ( V_5 -> V_69 ) ;
V_62 . V_43 . V_48 = F_30 ( V_81 ) ;
V_62 . V_104 = F_30 ( V_140 ) ;
V_62 . V_105 = F_30 ( 0 ) ;
V_35 = F_22 ( V_3 , & V_62 , sizeof( V_62 ) , V_23 , V_140 , V_33 ) ;
if ( V_35 && V_77 )
V_77 -> V_95 = false ;
return V_35 ;
}
static int F_85 ( struct V_128 * V_108 , void * V_23 , int V_140 )
{
struct V_1 * V_5 = F_77 ( V_108 ) ;
return F_84 ( V_5 , V_23 , V_140 , true ) ;
}
static int F_86 ( struct V_128 * V_108 , void * V_23 , int V_140 )
{
struct V_1 * V_5 = F_77 ( V_108 ) ;
return F_84 ( V_5 , V_23 , V_140 , false ) ;
}
static struct V_142 * F_87 ( struct V_142 * V_83 ,
const char * V_5 )
{
struct V_142 * V_143 ;
const char * V_4 ;
const char * V_144 ;
int V_35 ;
F_88 (node, child) {
V_144 = L_17 ;
V_35 = F_89 ( V_143 , V_144 , & V_4 ) ;
if ( V_35 )
continue;
if ( strcmp ( V_4 , V_5 ) == 0 )
return V_143 ;
}
return NULL ;
}
static void F_90 ( struct V_145 * V_57 )
{
struct V_129 * V_110 = F_91 ( V_57 ) ;
struct V_1 * V_5 = F_77 ( V_110 -> V_108 ) ;
V_5 -> V_110 = NULL ;
F_16 ( V_110 ) ;
}
static int F_92 ( struct V_2 * V_3 , unsigned int V_52 ,
char * V_4 )
{
struct V_1 * V_5 ;
struct V_129 * V_110 ;
bool V_146 = false ;
struct V_142 * V_83 ;
int V_69 ;
int V_35 ;
unsigned long V_20 ;
F_13 ( & V_3 -> V_55 , V_20 ) ;
F_78 (&glink->lcids, channel, lcid) {
if ( ! strcmp ( V_5 -> V_4 , V_4 ) )
break;
}
F_15 ( & V_3 -> V_55 , V_20 ) ;
if ( ! V_5 ) {
V_5 = F_1 ( V_3 , V_4 ) ;
if ( F_71 ( V_5 ) )
return F_93 ( V_5 ) ;
V_146 = true ;
}
F_13 ( & V_3 -> V_55 , V_20 ) ;
V_35 = F_67 ( & V_3 -> V_56 , V_5 , V_52 , V_52 + 1 , V_68 ) ;
if ( V_35 < 0 ) {
F_35 ( V_3 -> V_57 , L_18 ) ;
F_15 ( & V_3 -> V_55 , V_20 ) ;
goto V_147;
}
V_5 -> V_52 = V_35 ;
F_15 ( & V_3 -> V_55 , V_20 ) ;
F_36 ( & V_5 -> V_10 ) ;
if ( V_146 ) {
V_110 = F_2 ( sizeof( * V_110 ) , V_6 ) ;
if ( ! V_110 ) {
V_35 = - V_7 ;
goto V_148;
}
V_110 -> V_108 = & V_5 -> V_108 ;
strncpy ( V_110 -> V_79 . V_4 , V_4 , V_149 ) ;
V_110 -> V_150 = V_112 ;
V_110 -> V_151 = V_112 ;
V_110 -> V_133 = & V_152 ;
V_83 = F_87 ( V_3 -> V_57 -> V_153 , V_4 ) ;
V_110 -> V_57 . V_153 = V_83 ;
V_110 -> V_57 . V_132 = V_3 -> V_57 ;
V_110 -> V_57 . V_154 = F_90 ;
V_35 = F_94 ( V_110 ) ;
if ( V_35 )
goto V_155;
V_5 -> V_110 = V_110 ;
}
return 0 ;
V_155:
F_16 ( V_110 ) ;
V_148:
F_13 ( & V_3 -> V_55 , V_20 ) ;
F_41 ( & V_3 -> V_56 , V_5 -> V_52 ) ;
V_5 -> V_52 = 0 ;
F_15 ( & V_3 -> V_55 , V_20 ) ;
V_147:
if ( V_146 )
F_74 ( & V_5 -> V_17 , F_11 ) ;
return V_35 ;
}
static void F_95 ( struct V_2 * V_3 , unsigned int V_52 )
{
struct V_130 V_131 ;
struct V_1 * V_5 ;
unsigned long V_20 ;
F_13 ( & V_3 -> V_55 , V_20 ) ;
V_5 = F_34 ( & V_3 -> V_56 , V_52 ) ;
F_15 ( & V_3 -> V_55 , V_20 ) ;
if ( F_63 ( ! V_5 , L_19 ) )
return;
F_96 ( & V_5 -> V_13 ) ;
if ( V_5 -> V_110 ) {
strncpy ( V_131 . V_4 , V_5 -> V_4 , sizeof( V_131 . V_4 ) ) ;
V_131 . V_150 = V_112 ;
V_131 . V_151 = V_112 ;
F_97 ( V_3 -> V_57 , & V_131 ) ;
}
F_43 ( V_3 , V_5 -> V_52 ) ;
F_13 ( & V_3 -> V_55 , V_20 ) ;
F_41 ( & V_3 -> V_56 , V_5 -> V_52 ) ;
V_5 -> V_52 = 0 ;
F_15 ( & V_3 -> V_55 , V_20 ) ;
F_74 ( & V_5 -> V_17 , F_11 ) ;
}
static void F_98 ( struct V_2 * V_3 , unsigned int V_69 )
{
struct V_1 * V_5 ;
unsigned long V_20 ;
F_13 ( & V_3 -> V_55 , V_20 ) ;
V_5 = F_34 ( & V_3 -> V_65 , V_69 ) ;
if ( F_63 ( ! V_5 , L_20 ) ) {
F_15 ( & V_3 -> V_55 , V_20 ) ;
return;
}
F_41 ( & V_3 -> V_65 , V_5 -> V_69 ) ;
V_5 -> V_69 = 0 ;
F_15 ( & V_3 -> V_55 , V_20 ) ;
F_74 ( & V_5 -> V_17 , F_11 ) ;
}
static void F_99 ( struct V_74 * V_75 )
{
struct V_2 * V_3 = F_12 ( V_75 , struct V_2 ,
V_103 ) ;
struct V_98 * V_99 ;
struct V_42 * V_43 ;
unsigned long V_20 ;
unsigned int V_46 ;
unsigned int V_48 ;
unsigned int V_44 ;
for (; ; ) {
F_13 ( & V_3 -> V_101 , V_20 ) ;
if ( F_100 ( & V_3 -> V_102 ) ) {
F_15 ( & V_3 -> V_101 , V_20 ) ;
break;
}
V_99 = F_101 ( & V_3 -> V_102 ,
struct V_98 , V_83 ) ;
F_45 ( & V_99 -> V_83 ) ;
F_15 ( & V_3 -> V_101 , V_20 ) ;
V_43 = & V_99 -> V_43 ;
V_44 = F_64 ( V_43 -> V_44 ) ;
V_46 = F_64 ( V_43 -> V_46 ) ;
V_48 = F_62 ( V_43 -> V_48 ) ;
switch ( V_44 ) {
case V_45 :
F_51 ( V_3 , V_46 , V_48 ) ;
break;
case V_50 :
F_52 ( V_3 , V_46 , V_48 ) ;
break;
case V_70 :
F_92 ( V_3 , V_46 , V_43 -> V_23 ) ;
break;
case V_72 :
F_95 ( V_3 , V_46 ) ;
break;
case V_73 :
F_98 ( V_3 , V_46 ) ;
break;
case V_118 :
F_57 ( V_3 , V_46 , V_48 ) ;
break;
default:
F_63 ( 1 , L_21 , V_44 ) ;
break;
}
F_16 ( V_99 ) ;
}
}
struct V_2 * F_102 ( struct V_145 * V_57 ,
unsigned long V_49 ,
struct V_156 * V_157 ,
struct V_156 * V_158 ,
bool V_86 )
{
int V_117 ;
int V_35 ;
struct V_2 * V_3 ;
V_3 = F_103 ( V_57 , sizeof( * V_3 ) , V_6 ) ;
if ( ! V_3 )
return F_3 ( - V_7 ) ;
V_3 -> V_57 = V_57 ;
V_3 -> V_28 = V_158 ;
V_3 -> V_21 = V_157 ;
V_3 -> V_49 = V_49 ;
V_3 -> V_86 = V_86 ;
F_104 ( & V_3 -> V_38 ) ;
F_4 ( & V_3 -> V_101 ) ;
F_7 ( & V_3 -> V_102 ) ;
F_8 ( & V_3 -> V_103 , F_99 ) ;
F_4 ( & V_3 -> V_55 ) ;
F_9 ( & V_3 -> V_65 ) ;
F_9 ( & V_3 -> V_56 ) ;
V_3 -> V_159 . V_57 = V_57 ;
V_3 -> V_41 = F_105 ( & V_3 -> V_159 , 0 ) ;
if ( F_71 ( V_3 -> V_41 ) ) {
if ( F_93 ( V_3 -> V_41 ) != - V_160 )
F_35 ( V_57 , L_22 ) ;
return F_72 ( V_3 -> V_41 ) ;
}
V_117 = F_106 ( V_57 -> V_153 , 0 ) ;
V_35 = F_107 ( V_57 , V_117 ,
F_69 ,
V_161 | V_162 ,
L_23 , V_3 ) ;
if ( V_35 ) {
F_35 ( V_57 , L_24 ) ;
return F_3 ( V_35 ) ;
}
V_3 -> V_117 = V_117 ;
V_35 = F_28 ( V_3 ) ;
if ( V_35 )
return F_3 ( V_35 ) ;
return V_3 ;
}
static int F_108 ( struct V_145 * V_57 , void * V_23 )
{
F_109 ( V_57 ) ;
return 0 ;
}
void F_110 ( struct V_2 * V_3 )
{
struct V_1 * V_5 ;
int V_53 ;
int V_35 ;
unsigned long V_20 ;
F_111 ( V_3 -> V_117 ) ;
F_96 ( & V_3 -> V_103 ) ;
V_35 = F_112 ( V_3 -> V_57 , NULL , F_108 ) ;
if ( V_35 )
F_113 ( V_3 -> V_57 , L_25 , V_35 ) ;
F_13 ( & V_3 -> V_55 , V_20 ) ;
F_78 (&glink->lcids, channel, cid)
F_74 ( & V_5 -> V_17 , F_11 ) ;
F_14 ( & V_3 -> V_65 ) ;
F_14 ( & V_3 -> V_56 ) ;
F_15 ( & V_3 -> V_55 , V_20 ) ;
F_114 ( V_3 -> V_41 ) ;
}
void F_115 ( struct V_2 * V_3 )
{
F_109 ( V_3 -> V_57 ) ;
}
