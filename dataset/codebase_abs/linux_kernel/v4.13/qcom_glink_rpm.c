static struct V_1 * F_1 ( struct V_2 * V_3 ,
const char * V_4 )
{
struct V_1 * V_5 ;
V_5 = F_2 ( sizeof( * V_5 ) , V_6 ) ;
if ( ! V_5 )
return F_3 ( - V_7 ) ;
F_4 ( & V_5 -> V_8 ) ;
V_5 -> V_3 = V_3 ;
V_5 -> V_4 = F_5 ( V_4 , V_6 ) ;
F_6 ( & V_5 -> V_9 ) ;
F_6 ( & V_5 -> V_10 ) ;
F_7 ( & V_5 -> V_11 ) ;
return V_5 ;
}
static void F_8 ( struct V_12 * V_13 )
{
struct V_1 * V_5 = F_9 ( V_13 , struct V_1 ,
V_11 ) ;
F_10 ( V_5 -> V_4 ) ;
F_10 ( V_5 ) ;
}
static T_1 F_11 ( struct V_2 * V_3 )
{
struct V_14 * V_15 = & V_3 -> V_16 ;
unsigned int V_17 ;
unsigned int V_18 ;
V_17 = F_12 ( V_15 -> V_17 ) ;
V_18 = F_12 ( V_15 -> V_18 ) ;
if ( V_17 < V_18 )
return V_15 -> V_19 - V_18 + V_17 ;
else
return V_17 - V_18 ;
}
static void F_13 ( struct V_2 * V_3 ,
void * V_20 , T_1 V_21 )
{
struct V_14 * V_15 = & V_3 -> V_16 ;
unsigned int V_18 ;
T_1 V_22 ;
V_18 = F_12 ( V_15 -> V_18 ) ;
V_22 = F_14 ( T_1 , V_21 , V_15 -> V_19 - V_18 ) ;
if ( V_22 ) {
F_15 ( V_20 , V_15 -> V_23 + V_18 ,
V_22 / sizeof( V_24 ) ) ;
}
if ( V_22 != V_21 ) {
F_15 ( V_20 + V_22 , V_15 -> V_23 ,
( V_21 - V_22 ) / sizeof( V_24 ) ) ;
}
}
static void F_16 ( struct V_2 * V_3 ,
T_1 V_21 )
{
struct V_14 * V_15 = & V_3 -> V_16 ;
unsigned int V_18 ;
V_18 = F_12 ( V_15 -> V_18 ) ;
V_18 += V_21 ;
if ( V_18 >= V_15 -> V_19 )
V_18 -= V_15 -> V_19 ;
F_17 ( V_18 , V_15 -> V_18 ) ;
}
static T_1 F_18 ( struct V_2 * V_3 )
{
struct V_14 * V_15 = & V_3 -> V_25 ;
unsigned int V_17 ;
unsigned int V_18 ;
V_17 = F_12 ( V_15 -> V_17 ) ;
V_18 = F_12 ( V_15 -> V_18 ) ;
if ( V_18 <= V_17 )
return V_15 -> V_19 - V_17 + V_18 ;
else
return V_18 - V_17 ;
}
static unsigned int F_19 ( struct V_2 * V_3 ,
unsigned int V_17 ,
const void * V_20 , T_1 V_21 )
{
struct V_14 * V_15 = & V_3 -> V_25 ;
T_1 V_22 ;
V_22 = F_14 ( T_1 , V_21 , V_15 -> V_19 - V_17 ) ;
if ( V_22 ) {
F_20 ( V_15 -> V_23 + V_17 , V_20 ,
V_22 / sizeof( V_24 ) ) ;
}
if ( V_22 != V_21 ) {
F_20 ( V_15 -> V_23 , V_20 + V_22 ,
( V_21 - V_22 ) / sizeof( V_24 ) ) ;
}
V_17 += V_21 ;
if ( V_17 >= V_15 -> V_19 )
V_17 -= V_15 -> V_19 ;
return V_17 ;
}
static int F_21 ( struct V_2 * V_3 ,
const void * V_26 , T_1 V_27 ,
const void * V_20 , T_1 V_28 , bool V_29 )
{
struct V_14 * V_15 = & V_3 -> V_25 ;
unsigned int V_17 ;
unsigned int V_30 = V_27 + V_28 ;
int V_31 ;
if ( V_30 >= V_3 -> V_25 . V_19 )
return - V_32 ;
if ( F_22 ( V_30 % 8 , L_1 ) )
return - V_32 ;
V_31 = F_23 ( & V_3 -> V_33 ) ;
if ( V_31 )
return V_31 ;
while ( F_18 ( V_3 ) < V_30 ) {
if ( ! V_29 ) {
V_31 = - V_7 ;
goto V_34;
}
F_24 ( 10 ) ;
}
V_17 = F_12 ( V_15 -> V_17 ) ;
V_17 = F_19 ( V_3 , V_17 , V_26 , V_27 ) ;
V_17 = F_19 ( V_3 , V_17 , V_20 , V_28 ) ;
F_17 ( V_17 , V_15 -> V_17 ) ;
F_25 ( V_3 -> V_35 , NULL ) ;
F_26 ( V_3 -> V_35 , 0 ) ;
V_34:
F_27 ( & V_3 -> V_33 ) ;
return V_31 ;
}
static int F_28 ( struct V_2 * V_3 )
{
struct V_36 V_37 ;
V_37 . V_38 = F_29 ( V_39 ) ;
V_37 . V_40 = F_29 ( 1 ) ;
V_37 . V_41 = F_30 ( V_42 ) ;
return F_21 ( V_3 , & V_37 , sizeof( V_37 ) , NULL , 0 , true ) ;
}
static void F_31 ( struct V_2 * V_3 )
{
struct V_36 V_37 ;
V_37 . V_38 = F_29 ( V_43 ) ;
V_37 . V_40 = F_29 ( 1 ) ;
V_37 . V_41 = F_30 ( 0 ) ;
F_21 ( V_3 , & V_37 , sizeof( V_37 ) , NULL , 0 , true ) ;
}
static void F_32 ( struct V_2 * V_3 ,
struct V_1 * V_5 )
{
struct V_36 V_37 ;
V_37 . V_38 = F_29 ( V_44 ) ;
V_37 . V_40 = F_29 ( V_5 -> V_45 ) ;
V_37 . V_41 = F_30 ( 0 ) ;
F_21 ( V_3 , & V_37 , sizeof( V_37 ) , NULL , 0 , true ) ;
}
static int F_33 ( struct V_2 * V_3 ,
struct V_1 * V_5 )
{
struct {
struct V_36 V_37 ;
T_2 V_4 [ V_46 ] ;
} V_47 V_48 ;
int V_49 = strlen ( V_5 -> V_4 ) + 1 ;
int V_50 = F_34 ( sizeof( V_48 . V_37 ) + V_49 , 8 ) ;
int V_31 ;
F_35 ( & V_5 -> V_11 ) ;
F_36 ( & V_3 -> V_51 ) ;
V_31 = F_37 ( & V_3 -> V_52 , V_5 ,
V_53 , V_54 , V_6 ) ;
F_27 ( & V_3 -> V_51 ) ;
if ( V_31 < 0 )
return V_31 ;
V_5 -> V_55 = V_31 ;
V_48 . V_37 . V_38 = F_29 ( V_56 ) ;
V_48 . V_37 . V_40 = F_29 ( V_5 -> V_55 ) ;
V_48 . V_37 . V_41 = F_30 ( V_49 ) ;
strcpy ( V_48 . V_4 , V_5 -> V_4 ) ;
V_31 = F_21 ( V_3 , & V_48 , V_50 , NULL , 0 , true ) ;
if ( V_31 )
goto V_57;
return 0 ;
V_57:
F_36 ( & V_3 -> V_51 ) ;
F_38 ( & V_3 -> V_52 , V_5 -> V_55 ) ;
V_5 -> V_55 = 0 ;
F_27 ( & V_3 -> V_51 ) ;
return V_31 ;
}
static void F_39 ( struct V_2 * V_3 ,
struct V_1 * V_5 )
{
struct V_36 V_48 ;
V_48 . V_38 = F_29 ( V_58 ) ;
V_48 . V_40 = F_29 ( V_5 -> V_55 ) ;
V_48 . V_41 = 0 ;
F_21 ( V_3 , & V_48 , sizeof( V_48 ) , NULL , 0 , true ) ;
}
static void F_40 ( struct V_2 * V_3 , unsigned int V_45 )
{
struct V_36 V_48 ;
V_48 . V_38 = F_29 ( V_59 ) ;
V_48 . V_40 = F_29 ( V_45 ) ;
V_48 . V_41 = 0 ;
F_21 ( V_3 , & V_48 , sizeof( V_48 ) , NULL , 0 , true ) ;
}
static int F_41 ( struct V_2 * V_3 , T_1 V_60 )
{
struct V_61 * V_62 ;
V_60 = F_34 ( V_60 , 8 ) ;
if ( F_11 ( V_3 ) < sizeof( struct V_36 ) + V_60 ) {
F_42 ( V_3 -> V_63 , L_2 ) ;
return - V_64 ;
}
V_62 = F_2 ( sizeof( * V_62 ) + V_60 , V_65 ) ;
if ( ! V_62 )
return - V_7 ;
F_43 ( & V_62 -> V_66 ) ;
F_13 ( V_3 , & V_62 -> V_37 , sizeof( V_62 -> V_37 ) + V_60 ) ;
F_44 ( & V_3 -> V_67 ) ;
F_45 ( & V_62 -> V_66 , & V_3 -> V_68 ) ;
F_46 ( & V_3 -> V_67 ) ;
F_47 ( & V_3 -> V_69 ) ;
F_16 ( V_3 , sizeof( V_62 -> V_37 ) + V_60 ) ;
return 0 ;
}
static int F_48 ( struct V_2 * V_3 , T_1 V_70 )
{
struct V_1 * V_5 ;
struct {
struct V_36 V_37 ;
T_3 V_71 ;
T_3 V_72 ;
} V_47 V_26 ;
unsigned int V_71 ;
unsigned int V_72 ;
unsigned int V_45 ;
if ( V_70 < sizeof( V_26 ) ) {
F_42 ( V_3 -> V_63 , L_3 ) ;
return - V_73 ;
}
F_13 ( V_3 , & V_26 , sizeof( V_26 ) ) ;
V_71 = F_49 ( V_26 . V_71 ) ;
V_72 = F_49 ( V_26 . V_72 ) ;
if ( V_70 < sizeof( V_26 ) + V_71 ) {
F_42 ( V_3 -> V_63 , L_4 ) ;
return - V_73 ;
}
if ( F_22 ( V_71 % 4 , L_5 ) )
return - V_32 ;
V_45 = F_50 ( V_26 . V_37 . V_40 ) ;
V_5 = F_51 ( & V_3 -> V_74 , V_45 ) ;
if ( ! V_5 ) {
F_42 ( V_3 -> V_63 , L_6 ) ;
F_16 ( V_3 , F_34 ( sizeof( V_26 ) + V_71 , 8 ) ) ;
return 0 ;
}
if ( ! V_5 -> V_75 ) {
V_5 -> V_75 = F_52 ( V_71 + V_72 , V_65 ) ;
if ( ! V_5 -> V_75 )
return - V_7 ;
V_5 -> V_76 = V_71 + V_72 ;
V_5 -> V_77 = 0 ;
}
F_16 ( V_3 , sizeof( V_26 ) ) ;
if ( V_5 -> V_76 - V_5 -> V_77 < V_71 ) {
F_53 ( V_3 -> V_63 , L_7 ) ;
F_16 ( V_3 , V_71 ) ;
return - V_7 ;
}
F_13 ( V_3 , V_5 -> V_75 + V_5 -> V_77 , V_71 ) ;
V_5 -> V_77 += V_71 ;
if ( ! V_72 ) {
F_44 ( & V_5 -> V_8 ) ;
if ( V_5 -> V_78 . V_79 ) {
V_5 -> V_78 . V_79 ( V_5 -> V_78 . V_80 ,
V_5 -> V_75 ,
V_5 -> V_77 ,
V_5 -> V_78 . V_81 ,
V_82 ) ;
}
F_46 ( & V_5 -> V_8 ) ;
F_10 ( V_5 -> V_75 ) ;
V_5 -> V_75 = NULL ;
V_5 -> V_76 = 0 ;
}
F_16 ( V_3 , F_34 ( V_71 , 8 ) ) ;
return 0 ;
}
static int F_54 ( struct V_2 * V_3 , unsigned int V_55 )
{
struct V_1 * V_5 ;
V_5 = F_51 ( & V_3 -> V_52 , V_55 ) ;
if ( ! V_5 ) {
F_53 ( V_3 -> V_63 , L_8 ) ;
return - V_32 ;
}
F_55 ( & V_5 -> V_10 ) ;
return 0 ;
}
static T_4 F_56 ( int V_83 , void * V_20 )
{
struct V_2 * V_3 = V_20 ;
struct V_36 V_37 ;
unsigned int V_40 ;
unsigned int V_41 ;
unsigned int V_70 ;
unsigned int V_38 ;
int V_31 ;
for (; ; ) {
V_70 = F_11 ( V_3 ) ;
if ( V_70 < sizeof( V_37 ) )
break;
F_13 ( V_3 , & V_37 , sizeof( V_37 ) ) ;
V_38 = F_50 ( V_37 . V_38 ) ;
V_40 = F_50 ( V_37 . V_40 ) ;
V_41 = F_49 ( V_37 . V_41 ) ;
switch ( V_38 ) {
case V_39 :
case V_43 :
case V_58 :
case V_59 :
V_31 = F_41 ( V_3 , 0 ) ;
break;
case V_44 :
V_31 = F_54 ( V_3 , V_40 ) ;
F_16 ( V_3 , F_34 ( sizeof( V_37 ) , 8 ) ) ;
break;
case V_56 :
V_31 = F_41 ( V_3 , V_41 ) ;
break;
case V_84 :
case V_85 :
V_31 = F_48 ( V_3 , V_70 ) ;
break;
case V_86 :
F_16 ( V_3 , F_34 ( sizeof( V_37 ) , 8 ) ) ;
F_25 ( V_3 -> V_35 , NULL ) ;
F_26 ( V_3 -> V_35 , 0 ) ;
V_31 = 0 ;
break;
default:
F_53 ( V_3 -> V_63 , L_9 , V_38 ) ;
V_31 = - V_32 ;
break;
}
if ( V_31 )
break;
}
return V_87 ;
}
static struct V_1 * F_57 ( struct V_2 * V_3 ,
const char * V_4 )
{
struct V_1 * V_5 ;
int V_31 ;
V_5 = F_1 ( V_3 , V_4 ) ;
if ( F_58 ( V_5 ) )
return F_59 ( V_5 ) ;
V_31 = F_33 ( V_3 , V_5 ) ;
if ( V_31 )
goto V_88;
V_31 = F_60 ( & V_5 -> V_10 , 5 * V_89 ) ;
if ( ! V_31 )
goto V_90;
V_31 = F_60 ( & V_5 -> V_9 , 5 * V_89 ) ;
if ( ! V_31 )
goto V_90;
F_32 ( V_3 , V_5 ) ;
return V_5 ;
V_90:
F_36 ( & V_3 -> V_51 ) ;
F_38 ( & V_3 -> V_52 , V_5 -> V_55 ) ;
F_27 ( & V_3 -> V_51 ) ;
V_88:
F_61 ( & V_5 -> V_11 , F_8 ) ;
F_61 ( & V_5 -> V_11 , F_8 ) ;
return F_3 ( - V_91 ) ;
}
static int F_62 ( struct V_2 * V_3 ,
struct V_1 * V_5 )
{
int V_31 ;
F_32 ( V_3 , V_5 ) ;
V_31 = F_33 ( V_3 , V_5 ) ;
if ( V_31 )
goto V_92;
V_31 = F_60 ( & V_5 -> V_10 , 5 * V_89 ) ;
if ( ! V_31 ) {
V_31 = - V_91 ;
goto V_92;
}
return 0 ;
V_92:
F_39 ( V_3 , V_5 ) ;
F_61 ( & V_5 -> V_11 , F_8 ) ;
return V_31 ;
}
static struct V_93 * F_63 ( struct V_94 * V_80 ,
T_5 V_79 , void * V_81 ,
struct V_95 V_96 )
{
struct V_1 * V_97 = F_64 ( V_80 -> V_78 ) ;
struct V_1 * V_5 ;
struct V_2 * V_3 = V_97 -> V_3 ;
struct V_93 * V_78 ;
const char * V_4 = V_96 . V_4 ;
int V_98 ;
int V_31 ;
F_65 (&glink->rcids, channel, cid) {
if ( ! strcmp ( V_5 -> V_4 , V_4 ) )
break;
}
if ( ! V_5 ) {
V_5 = F_57 ( V_3 , V_4 ) ;
if ( F_58 ( V_5 ) )
return NULL ;
} else {
V_31 = F_62 ( V_3 , V_5 ) ;
if ( V_31 )
return NULL ;
}
V_78 = & V_5 -> V_78 ;
V_78 -> V_80 = V_80 ;
V_78 -> V_79 = V_79 ;
V_78 -> V_81 = V_81 ;
V_78 -> V_99 = & V_100 ;
return V_78 ;
}
static void F_66 ( struct V_93 * V_78 )
{
struct V_1 * V_5 = F_64 ( V_78 ) ;
struct V_2 * V_3 = V_5 -> V_3 ;
unsigned long V_101 ;
F_67 ( & V_5 -> V_8 , V_101 ) ;
V_5 -> V_78 . V_79 = NULL ;
F_68 ( & V_5 -> V_8 , V_101 ) ;
V_5 -> V_80 = NULL ;
F_39 ( V_3 , V_5 ) ;
}
static int F_69 ( struct V_1 * V_5 ,
void * V_20 , int V_22 , bool V_29 )
{
struct V_2 * V_3 = V_5 -> V_3 ;
struct {
struct V_36 V_37 ;
T_3 V_71 ;
T_3 V_72 ;
} V_47 V_48 ;
if ( F_22 ( V_22 % 8 , L_10 ) )
return - V_32 ;
V_48 . V_37 . V_38 = F_29 ( V_84 ) ;
V_48 . V_37 . V_40 = F_29 ( V_5 -> V_55 ) ;
V_48 . V_37 . V_41 = F_30 ( V_5 -> V_45 ) ;
V_48 . V_71 = F_30 ( V_22 ) ;
V_48 . V_72 = F_30 ( 0 ) ;
return F_21 ( V_3 , & V_48 , sizeof( V_48 ) , V_20 , V_22 , V_29 ) ;
}
static int F_70 ( struct V_93 * V_78 , void * V_20 , int V_22 )
{
struct V_1 * V_5 = F_64 ( V_78 ) ;
return F_69 ( V_5 , V_20 , V_22 , true ) ;
}
static int F_71 ( struct V_93 * V_78 , void * V_20 , int V_22 )
{
struct V_1 * V_5 = F_64 ( V_78 ) ;
return F_69 ( V_5 , V_20 , V_22 , false ) ;
}
static struct V_102 * F_72 ( struct V_102 * V_66 ,
const char * V_5 )
{
struct V_102 * V_103 ;
const char * V_4 ;
const char * V_104 ;
int V_31 ;
F_73 (node, child) {
V_104 = L_11 ;
V_31 = F_74 ( V_103 , V_104 , & V_4 ) ;
if ( V_31 )
continue;
if ( strcmp ( V_4 , V_5 ) == 0 )
return V_103 ;
}
return NULL ;
}
static void F_75 ( struct V_105 * V_63 )
{
struct V_94 * V_80 = F_76 ( V_63 ) ;
struct V_1 * V_5 = F_64 ( V_80 -> V_78 ) ;
V_5 -> V_80 = NULL ;
F_10 ( V_80 ) ;
}
static int F_77 ( struct V_2 * V_3 , unsigned int V_45 ,
char * V_4 )
{
struct V_1 * V_5 ;
struct V_94 * V_80 ;
bool V_106 = false ;
int V_55 ;
int V_31 ;
F_65 (&glink->lcids, channel, lcid) {
if ( ! strcmp ( V_5 -> V_4 , V_4 ) )
break;
}
if ( ! V_5 ) {
V_5 = F_1 ( V_3 , V_4 ) ;
if ( F_58 ( V_5 ) )
return F_78 ( V_5 ) ;
V_106 = true ;
}
F_36 ( & V_3 -> V_51 ) ;
V_31 = F_79 ( & V_3 -> V_74 , V_5 , V_45 , V_45 + 1 , V_6 ) ;
if ( V_31 < 0 ) {
F_53 ( V_3 -> V_63 , L_12 ) ;
F_27 ( & V_3 -> V_51 ) ;
goto V_107;
}
V_5 -> V_45 = V_31 ;
F_27 ( & V_3 -> V_51 ) ;
F_55 ( & V_5 -> V_9 ) ;
if ( V_106 ) {
V_80 = F_2 ( sizeof( * V_80 ) , V_6 ) ;
if ( ! V_80 ) {
V_31 = - V_7 ;
goto V_108;
}
V_80 -> V_78 = & V_5 -> V_78 ;
strncpy ( V_80 -> V_109 . V_4 , V_4 , V_110 ) ;
V_80 -> V_111 = V_82 ;
V_80 -> V_112 = V_82 ;
V_80 -> V_99 = & V_113 ;
V_80 -> V_63 . V_114 = F_72 ( V_3 -> V_63 -> V_114 , V_4 ) ;
V_80 -> V_63 . V_97 = V_3 -> V_63 ;
V_80 -> V_63 . V_115 = F_75 ;
V_31 = F_80 ( V_80 ) ;
if ( V_31 )
goto V_116;
V_5 -> V_80 = V_80 ;
}
return 0 ;
V_116:
F_10 ( V_80 ) ;
V_108:
F_36 ( & V_3 -> V_51 ) ;
F_38 ( & V_3 -> V_74 , V_5 -> V_45 ) ;
V_5 -> V_45 = 0 ;
F_27 ( & V_3 -> V_51 ) ;
V_107:
if ( V_106 )
F_61 ( & V_5 -> V_11 , F_8 ) ;
return V_31 ;
}
static void F_81 ( struct V_2 * V_3 , unsigned int V_45 )
{
struct V_95 V_96 ;
struct V_1 * V_5 ;
V_5 = F_51 ( & V_3 -> V_74 , V_45 ) ;
if ( F_22 ( ! V_5 , L_13 ) )
return;
if ( V_5 -> V_80 ) {
strncpy ( V_96 . V_4 , V_5 -> V_4 , sizeof( V_96 . V_4 ) ) ;
V_96 . V_111 = V_82 ;
V_96 . V_112 = V_82 ;
F_82 ( V_3 -> V_63 , & V_96 ) ;
}
F_40 ( V_3 , V_5 -> V_45 ) ;
F_36 ( & V_3 -> V_51 ) ;
F_38 ( & V_3 -> V_74 , V_5 -> V_45 ) ;
V_5 -> V_45 = 0 ;
F_27 ( & V_3 -> V_51 ) ;
F_61 ( & V_5 -> V_11 , F_8 ) ;
}
static void F_83 ( struct V_2 * V_3 , unsigned int V_55 )
{
struct V_1 * V_5 ;
V_5 = F_51 ( & V_3 -> V_52 , V_55 ) ;
if ( F_22 ( ! V_5 , L_14 ) )
return;
F_36 ( & V_3 -> V_51 ) ;
F_38 ( & V_3 -> V_52 , V_5 -> V_55 ) ;
V_5 -> V_55 = 0 ;
F_27 ( & V_3 -> V_51 ) ;
F_61 ( & V_5 -> V_11 , F_8 ) ;
}
static void F_84 ( struct V_117 * V_118 )
{
struct V_2 * V_3 = F_9 ( V_118 , struct V_2 , V_69 ) ;
struct V_61 * V_62 ;
struct V_36 * V_37 ;
unsigned long V_101 ;
unsigned int V_40 ;
unsigned int V_41 ;
unsigned int V_38 ;
for (; ; ) {
F_67 ( & V_3 -> V_67 , V_101 ) ;
if ( F_85 ( & V_3 -> V_68 ) ) {
F_68 ( & V_3 -> V_67 , V_101 ) ;
break;
}
V_62 = F_86 ( & V_3 -> V_68 , struct V_61 , V_66 ) ;
F_87 ( & V_62 -> V_66 ) ;
F_68 ( & V_3 -> V_67 , V_101 ) ;
V_37 = & V_62 -> V_37 ;
V_38 = F_50 ( V_37 -> V_38 ) ;
V_40 = F_50 ( V_37 -> V_40 ) ;
V_41 = F_49 ( V_37 -> V_41 ) ;
switch ( V_38 ) {
case V_39 :
F_31 ( V_3 ) ;
break;
case V_43 :
break;
case V_56 :
F_77 ( V_3 , V_40 , V_37 -> V_20 ) ;
break;
case V_58 :
F_81 ( V_3 , V_40 ) ;
break;
case V_59 :
F_83 ( V_3 , V_40 ) ;
break;
default:
F_22 ( 1 , L_15 , V_38 ) ;
break;
}
F_10 ( V_62 ) ;
}
}
static int F_88 ( struct V_105 * V_63 ,
void T_6 * V_119 ,
T_1 V_120 ,
struct V_14 * V_121 ,
struct V_14 * V_122 )
{
struct V_123 * V_124 ;
int V_125 ;
unsigned int V_109 ;
T_1 V_126 ;
T_1 V_127 ;
void * V_75 ;
int V_128 ;
V_75 = F_2 ( V_129 , V_6 ) ;
if ( ! V_75 )
return - V_7 ;
F_15 ( V_75 , V_119 + V_120 - V_129 ,
V_129 / sizeof( V_24 ) ) ;
V_124 = V_75 ;
if ( F_49 ( V_124 -> V_130 ) != V_131 ) {
F_53 ( V_63 , L_16 ) ;
goto V_132;
}
V_125 = F_49 ( V_124 -> V_21 ) ;
if ( V_125 > V_133 ) {
F_53 ( V_63 , L_17 ) ;
goto V_132;
}
for ( V_128 = 0 ; V_128 < V_125 ; V_128 ++ ) {
V_109 = F_49 ( V_124 -> V_134 [ V_128 ] . V_109 ) ;
V_126 = F_49 ( V_124 -> V_134 [ V_128 ] . V_126 ) ;
V_127 = F_49 ( V_124 -> V_134 [ V_128 ] . V_127 ) ;
if ( V_126 > V_120 || V_126 + V_127 > V_120 ) {
F_53 ( V_63 , L_18 ) ;
continue;
}
switch ( V_109 ) {
case V_135 :
V_121 -> V_19 = V_127 ;
V_121 -> V_18 = V_119 + V_126 ;
V_121 -> V_17 = V_119 + V_126 + sizeof( V_24 ) ;
V_121 -> V_23 = V_119 + V_126 + 2 * sizeof( V_24 ) ;
break;
case V_136 :
V_122 -> V_19 = V_127 ;
V_122 -> V_18 = V_119 + V_126 ;
V_122 -> V_17 = V_119 + V_126 + sizeof( V_24 ) ;
V_122 -> V_23 = V_119 + V_126 + 2 * sizeof( V_24 ) ;
break;
}
}
if ( ! V_121 -> V_23 || ! V_122 -> V_23 ) {
F_53 ( V_63 , L_19 ) ;
goto V_132;
}
F_10 ( V_75 ) ;
return 0 ;
V_132:
F_10 ( V_75 ) ;
return - V_32 ;
}
static int F_89 ( struct V_137 * V_138 )
{
struct V_2 * V_3 ;
struct V_102 * V_139 ;
void T_6 * V_119 ;
T_1 V_120 ;
struct V_105 * V_63 = & V_138 -> V_63 ;
struct V_140 V_141 ;
int V_83 ;
int V_31 ;
V_3 = F_90 ( V_63 , sizeof( * V_3 ) , V_6 ) ;
if ( ! V_3 )
return - V_7 ;
V_3 -> V_63 = V_63 ;
F_91 ( & V_3 -> V_33 ) ;
F_4 ( & V_3 -> V_67 ) ;
F_43 ( & V_3 -> V_68 ) ;
F_92 ( & V_3 -> V_69 , F_84 ) ;
F_91 ( & V_3 -> V_51 ) ;
F_93 ( & V_3 -> V_52 ) ;
F_93 ( & V_3 -> V_74 ) ;
V_3 -> V_142 . V_63 = & V_138 -> V_63 ;
V_3 -> V_35 = F_94 ( & V_3 -> V_142 , 0 ) ;
if ( F_58 ( V_3 -> V_35 ) ) {
if ( F_78 ( V_3 -> V_35 ) != - V_143 )
F_53 ( & V_138 -> V_63 , L_20 ) ;
return F_78 ( V_3 -> V_35 ) ;
}
V_139 = F_95 ( V_63 -> V_114 , L_21 , 0 ) ;
V_31 = F_96 ( V_139 , 0 , & V_141 ) ;
F_97 ( V_139 ) ;
if ( V_31 )
return V_31 ;
V_119 = F_98 ( V_63 , V_141 . V_144 , F_99 ( & V_141 ) ) ;
V_120 = F_99 ( & V_141 ) ;
if ( ! V_119 )
return - V_7 ;
V_31 = F_88 ( V_63 , V_119 , V_120 ,
& V_3 -> V_16 , & V_3 -> V_25 ) ;
if ( V_31 )
return V_31 ;
F_17 ( 0 , V_3 -> V_25 . V_17 ) ;
F_17 ( 0 , V_3 -> V_16 . V_18 ) ;
V_83 = F_100 ( V_138 , 0 ) ;
V_31 = F_101 ( V_63 , V_83 ,
F_56 ,
V_145 | V_146 ,
L_22 , V_3 ) ;
if ( V_31 ) {
F_53 ( V_63 , L_23 ) ;
return V_31 ;
}
V_3 -> V_83 = V_83 ;
V_31 = F_28 ( V_3 ) ;
if ( V_31 )
return V_31 ;
F_102 ( V_138 , V_3 ) ;
return 0 ;
}
static int F_103 ( struct V_105 * V_63 , void * V_20 )
{
F_104 ( V_63 ) ;
return 0 ;
}
static int F_105 ( struct V_137 * V_138 )
{
struct V_2 * V_3 = F_106 ( V_138 ) ;
struct V_1 * V_5 ;
int V_98 ;
int V_31 ;
F_107 ( V_3 -> V_83 ) ;
F_108 ( & V_3 -> V_69 ) ;
V_31 = F_109 ( V_3 -> V_63 , NULL , F_103 ) ;
if ( V_31 )
F_110 ( V_3 -> V_63 , L_24 , V_31 ) ;
F_65 (&glink->lcids, channel, cid)
F_61 ( & V_5 -> V_11 , F_8 ) ;
F_111 ( & V_3 -> V_52 ) ;
F_111 ( & V_3 -> V_74 ) ;
return 0 ;
}
static int T_7 F_112 ( void )
{
return F_113 ( & V_147 ) ;
}
static void T_8 F_114 ( void )
{
F_115 ( & V_147 ) ;
}
