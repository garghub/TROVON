static int F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
int V_4 ;
F_2 ( & V_5 , V_3 ) ;
for ( V_4 = V_6 ; V_4 < V_7 ; V_4 ++ ) {
if ( ! V_8 [ V_4 ] ) {
V_8 [ V_4 ] = V_2 ;
break;
}
}
F_3 ( & V_5 , V_3 ) ;
if ( V_4 < V_7 )
return V_4 ;
else
return - 1 ;
}
static void F_4 ( unsigned long V_9 )
{
unsigned long V_3 ;
if ( F_5 ( V_9 >= V_7 ) )
return;
F_2 ( & V_5 , V_3 ) ;
V_8 [ V_9 ] = NULL ;
F_3 ( & V_5 , V_3 ) ;
}
static struct V_1 * F_6 ( unsigned long V_9 , bool V_10 )
{
struct V_1 * V_2 ;
unsigned long V_3 ;
V_11:
F_2 ( & V_5 , V_3 ) ;
V_2 = V_8 [ V_9 ] ;
if ( ! V_2 ) {
F_3 ( & V_5 , V_3 ) ;
return NULL ;
}
if ( ! V_10 ) {
if ( V_2 -> V_12 ) {
F_3 ( & V_5 , V_3 ) ;
F_7 ( V_13 ) ;
goto V_11;
}
V_2 -> V_14 ++ ;
F_3 ( & V_5 , V_3 ) ;
return V_2 ;
}
if ( V_2 -> V_14 ) {
F_3 ( & V_5 , V_3 ) ;
F_7 ( V_13 / 2 ) ;
goto V_11;
}
V_2 -> V_14 ++ ;
V_2 -> V_12 = true ;
F_3 ( & V_5 , V_3 ) ;
return V_2 ;
}
static void F_8 ( struct V_1 * V_2 , bool V_10 )
{
unsigned long V_3 ;
if ( ! V_2 )
return;
F_2 ( & V_5 , V_3 ) ;
if ( F_5 ( ( V_10 && ! V_2 -> V_12 ) ||
( ! V_10 && V_2 -> V_12 ) ) )
goto V_15;
V_2 -> V_14 -- ;
if ( V_10 )
V_2 -> V_12 = false ;
V_15:
F_3 ( & V_5 , V_3 ) ;
}
static struct V_1 * F_9 ( unsigned long V_9 )
{
struct V_1 * V_2 ;
V_2 = F_6 ( V_9 , false ) ;
if ( V_2 && V_2 -> V_16 ) {
F_8 ( V_2 , false ) ;
return NULL ;
}
return V_2 ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = & V_2 -> V_18 ;
F_11 ( & V_2 -> V_19 ) ;
if ( ! F_12 ( & V_2 -> V_20 ) && ! V_2 -> V_16 ) {
F_13 ( V_18 -> V_21 -> V_22 ) ;
V_2 -> V_20 . V_23 = ( V_24 + 1 ) ;
F_14 ( & V_2 -> V_20 ) ;
}
}
static void F_15 ( struct V_1 * V_2 )
{
F_11 ( & V_2 -> V_19 ) ;
if ( ! F_12 ( & V_2 -> V_25 ) && ! V_2 -> V_16 ) {
V_2 -> V_25 . V_23 = ( V_24 + 1 ) ;
F_14 ( & V_2 -> V_25 ) ;
}
}
static int F_16 ( struct V_26 * V_27 , int V_28 )
{
if ( F_5 ( ! V_27 || ! V_27 -> V_2 ) )
return 1 ;
if ( F_17 ( V_29 , & V_27 -> V_3 ) ||
( F_18 ( V_27 -> V_2 , V_30 ) < V_30 ) )
return 0 ;
return 1 ;
}
static int F_19 ( struct V_26 * V_27 , char * V_31 , int V_28 )
{
int V_32 = 0 ;
if ( F_5 ( ! V_27 || ! V_27 -> V_2 ) )
return V_32 ;
V_32 = F_20 ( V_27 -> V_2 , V_31 , V_28 ) ;
if ( V_32 )
F_21 ( V_27 -> V_2 ) ;
return V_32 ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = & V_2 -> V_18 ;
struct V_26 * V_27 ;
struct V_33 V_34 ;
int V_35 = 0 ;
V_27 = V_2 -> V_27 ;
if ( ! V_27 ) {
V_35 = F_23 ( V_18 -> V_36 ) ;
F_24 ( L_1 , V_35 ) ;
goto V_15;
}
while ( 1 ) {
if ( ! F_16 ( V_27 , V_37 ) ) {
F_10 ( V_2 ) ;
break;
}
F_25 ( V_18 -> V_36 ) ;
V_35 = F_26 ( V_18 -> V_36 , & V_34 , sizeof( V_34 ) ) ;
if ( V_35 <= 0 )
break;
F_24 ( L_2 , V_35 ) ;
F_24 ( L_3 ,
V_34 . V_38 . type , V_34 . V_38 . V_39 ,
V_34 . V_38 . V_40 , V_34 . V_38 . V_41 ) ;
if ( V_34 . V_38 . type == V_42 ) {
F_27 ( V_34 ) ;
F_19 ( V_27 , V_34 . V_43 , V_34 . V_38 . V_39 ) ;
} else {
F_28 ( L_4 ,
V_34 . V_38 . type , V_34 . V_38 . V_39 ,
V_34 . V_38 . V_40 , V_34 . V_38 . V_41 ) ;
V_35 = - V_44 ;
break;
}
F_5 ( V_35 != V_45 ) ;
}
V_15:
return V_35 ;
}
static void F_29 ( unsigned long V_9 )
{
struct V_17 * V_18 ;
struct V_1 * V_2 ;
unsigned long V_3 ;
int V_35 ;
V_2 = F_9 ( V_9 ) ;
if ( ! V_2 )
return;
F_2 ( & V_2 -> V_19 , V_3 ) ;
V_2 -> V_20 . V_23 = 0 ;
V_18 = & V_2 -> V_18 ;
F_30 ( V_18 -> V_21 -> V_22 ) ;
if ( ! V_2 -> V_27 || V_2 -> V_16 )
goto V_15;
V_35 = F_22 ( V_2 ) ;
if ( V_35 == - V_44 )
F_31 ( V_18 ) ;
V_15:
F_3 ( & V_2 -> V_19 , V_3 ) ;
F_8 ( V_2 , false ) ;
}
static void F_32 ( unsigned long V_9 )
{
struct V_1 * V_2 ;
struct V_33 * V_34 ;
unsigned long V_3 ;
int V_46 = 0 ;
int V_35 ;
V_2 = F_9 ( V_9 ) ;
if ( ! V_2 )
return;
F_2 ( & V_2 -> V_19 , V_3 ) ;
V_2 -> V_25 . V_23 = 0 ;
if ( ! V_2 -> V_27 || V_2 -> V_16 )
goto V_15;
V_46 = F_33 ( V_30 , V_2 -> V_47 ) ;
if ( ! V_46 )
goto V_15;
V_34 = & V_2 -> V_48 ;
V_34 -> V_38 . type = V_42 ;
V_34 -> V_38 . V_39 = V_46 ;
F_25 ( V_2 -> V_18 . V_36 ) ;
V_35 = F_34 ( V_2 -> V_18 . V_36 , V_34 , ( V_49 + V_46 ) ) ;
F_5 ( ! V_35 ) ;
if ( V_35 < 0 ) {
F_24 ( L_5 , V_35 ) ;
F_15 ( V_2 ) ;
} else {
struct V_26 * V_27 = V_2 -> V_27 ;
V_2 -> V_47 = 0 ;
if ( V_27 )
F_35 ( V_27 ) ;
}
V_15:
F_3 ( & V_2 -> V_19 , V_3 ) ;
F_8 ( V_2 , false ) ;
}
static void F_36 ( void * V_50 , int V_51 )
{
struct V_17 * V_18 ;
struct V_1 * V_2 ;
unsigned long V_3 ;
int V_35 ;
V_2 = V_50 ;
V_18 = & V_2 -> V_18 ;
F_2 ( & V_2 -> V_19 , V_3 ) ;
switch ( V_51 ) {
case V_52 :
case V_53 :
F_37 ( V_18 , V_51 ) ;
break;
case V_54 :
V_35 = F_22 ( V_2 ) ;
if ( V_35 == - V_44 )
F_31 ( V_18 ) ;
break;
default:
F_28 ( L_6 , V_51 ) ;
}
F_3 ( & V_2 -> V_19 , V_3 ) ;
}
static T_1 F_38 ( struct V_55 * V_56 ,
struct V_57 * V_58 ,
char * V_31 )
{
struct V_1 * V_2 ;
int V_35 ;
V_2 = F_39 ( V_56 ) ;
if ( ! V_2 )
return - V_59 ;
V_35 = F_40 ( V_31 , V_60 , L_7 , V_2 -> V_61 ) ;
return V_35 ;
}
static int F_41 ( struct V_1 * V_2 , int V_62 )
{
struct V_33 V_34 ;
int V_35 ;
V_34 . V_38 . type = V_63 ;
V_34 . V_38 . V_41 = V_62 ;
V_34 . V_38 . V_39 = 0 ;
V_35 = F_34 ( V_2 -> V_18 . V_36 , & V_34 , sizeof( V_34 . V_38 ) ) ;
F_5 ( ! V_35 ) ;
F_24 ( L_8 , sizeof( V_34 . V_38 ) , V_35 ) ;
return V_35 ;
}
static T_1 F_42 ( struct V_55 * V_56 ,
struct V_57 * V_58 ,
const char * V_31 , T_2 V_64 )
{
struct V_1 * V_2 ;
unsigned long V_3 ;
int V_35 = V_64 ;
int V_65 ;
V_2 = F_39 ( V_56 ) ;
if ( ! V_2 )
return - V_59 ;
F_2 ( & V_2 -> V_19 , V_3 ) ;
if ( sscanf ( V_31 , L_9 , & V_65 ) != 1 || V_65 != 1 )
V_35 = - V_66 ;
else if ( F_41 ( V_2 , V_67 ) < 0 )
F_15 ( V_2 ) ;
F_3 ( & V_2 -> V_19 , V_3 ) ;
return V_35 ;
}
static int F_43 ( struct V_68 * V_21 , const struct V_69 * V_70 )
{
struct V_71 * V_72 ;
struct V_1 * V_2 ;
struct V_55 * V_56 ;
const char * V_61 ;
char * V_73 ;
T_3 V_74 ;
int V_35 ;
F_24 ( L_10 , F_44 ( & V_21 -> V_56 ) ) ;
if ( ! V_75 ) {
F_28 ( L_11 ) ;
return - V_59 ;
}
V_2 = F_45 ( sizeof( struct V_1 ) , V_76 ) ;
if ( ! V_2 )
return - V_77 ;
V_73 = F_46 ( F_44 ( & V_21 -> V_56 ) , V_76 ) ;
V_35 = F_47 ( & V_2 -> V_18 , V_21 , V_78 , V_79 ,
F_48 ( V_79 ) , NULL , V_73 ) ;
if ( V_35 )
goto V_80;
V_2 -> V_18 . V_81 = V_82 ;
V_83 . V_81 = V_84 ;
V_35 = F_49 ( & V_2 -> V_18 , & V_83 , V_2 ) ;
if ( V_35 )
goto V_80;
F_50 ( & V_2 -> V_19 ) ;
V_2 -> V_9 = F_1 ( V_2 ) ;
if ( V_2 -> V_9 == - 1 ) {
F_28 ( L_12 ) ;
goto V_85;
}
V_56 = F_51 ( V_75 , V_2 -> V_9 , & V_21 -> V_56 ) ;
if ( F_52 ( V_56 ) ) {
V_35 = F_53 ( V_56 ) ;
goto V_86;
}
V_72 = F_54 () ;
V_74 = F_55 ( V_72 , V_21 ) ;
if ( V_74 == V_87 ) {
V_35 = - V_88 ;
F_56 ( V_72 ) ;
goto V_89;
}
V_61 = F_57 ( V_72 , V_74 , L_13 , NULL ) ;
if ( ! V_61 ) {
V_35 = - V_88 ;
F_56 ( V_72 ) ;
goto V_89;
}
V_2 -> V_61 = F_46 ( V_61 , V_76 ) ;
F_56 ( V_72 ) ;
V_35 = F_58 ( & V_21 -> V_56 . V_90 , & V_91 ) ;
if ( V_35 )
goto V_92;
F_59 ( & V_2 -> V_20 ) ;
V_2 -> V_20 . V_93 = F_29 ;
V_2 -> V_20 . V_43 = V_2 -> V_9 ;
F_59 ( & V_2 -> V_25 ) ;
V_2 -> V_25 . V_93 = F_32 ;
V_2 -> V_25 . V_43 = V_2 -> V_9 ;
F_60 ( & V_21 -> V_56 , V_2 ) ;
F_13 ( V_21 -> V_22 ) ;
F_61 ( & V_2 -> V_18 ) ;
F_30 ( V_21 -> V_22 ) ;
return 0 ;
V_92:
F_62 ( V_2 -> V_61 ) ;
V_89:
F_63 ( V_75 , V_2 -> V_9 ) ;
V_86:
F_4 ( V_2 -> V_9 ) ;
V_85:
F_64 ( & V_2 -> V_18 ) ;
V_80:
F_62 ( V_73 ) ;
F_62 ( V_2 ) ;
return V_35 ;
}
static int F_65 ( struct V_68 * V_21 )
{
struct V_1 * V_2 = F_39 ( & V_21 -> V_56 ) ;
if ( ! V_2 )
return - V_59 ;
F_66 ( & V_2 -> V_20 ) ;
F_66 ( & V_2 -> V_25 ) ;
if ( V_2 -> V_27 )
F_67 ( V_2 -> V_27 ) ;
V_2 = F_6 ( V_2 -> V_9 , true ) ;
if ( F_5 ( ! V_2 ) )
return - V_59 ;
F_63 ( V_75 , V_2 -> V_9 ) ;
F_66 ( & V_2 -> V_18 . V_94 ) ;
F_64 ( & V_2 -> V_18 ) ;
F_68 ( & V_21 -> V_56 . V_90 , & V_91 ) ;
F_60 ( & V_21 -> V_56 , NULL ) ;
if ( V_2 -> V_27 ) {
V_2 -> V_16 = true ;
F_8 ( V_2 , true ) ;
} else {
F_4 ( V_2 -> V_9 ) ;
F_62 ( V_2 -> V_18 . V_73 ) ;
F_62 ( V_2 -> V_61 ) ;
F_62 ( V_2 ) ;
}
return 0 ;
}
static int F_69 ( struct V_26 * V_27 , struct V_95 * V_96 )
{
struct V_1 * V_2 ;
if ( F_70 ( ! V_27 ) ) {
F_28 ( L_14 ) ;
return - V_88 ;
}
if ( V_27 -> V_64 > 1 )
return - V_97 ;
V_2 = F_9 ( V_27 -> V_9 ) ;
if ( F_70 ( ! V_2 ) ) {
F_28 ( L_15 ) ;
return - V_59 ;
}
if ( F_70 ( ! V_2 -> V_18 . V_36 ) ) {
F_28 ( L_16 ) ;
F_8 ( V_2 , false ) ;
return - V_98 ;
}
F_25 ( V_2 -> V_18 . V_36 ) ;
F_8 ( V_2 , false ) ;
if ( F_70 ( ! V_27 -> V_2 ) ) {
F_28 ( L_17 ) ;
return - V_88 ;
}
if ( F_70 ( ! V_27 -> V_2 -> V_99 ) ) {
F_28 ( L_18 ) ;
return - V_88 ;
}
return F_71 ( V_27 -> V_2 , V_27 , V_96 ) ;
}
static void F_72 ( struct V_26 * V_27 , struct V_95 * V_96 )
{
if ( F_70 ( ! V_27 ) ) {
F_28 ( L_19 ) ;
return;
}
if ( F_70 ( V_27 -> V_64 > 1 ) )
return;
if ( F_70 ( ! V_27 -> V_2 ) ) {
F_28 ( L_20 ) ;
return;
}
F_73 ( V_27 -> V_2 , V_27 , V_96 ) ;
}
static void F_74 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
F_2 ( & V_2 -> V_19 , V_3 ) ;
if ( F_41 ( V_2 , V_100 ) < 0 )
F_15 ( V_2 ) ;
F_3 ( & V_2 -> V_19 , V_3 ) ;
}
static void F_75 ( struct V_26 * V_27 )
{
struct V_1 * V_2 ;
if ( F_70 ( ! V_27 ) ) {
F_28 ( L_21 ) ;
return;
}
V_2 = F_9 ( V_27 -> V_9 ) ;
if ( F_70 ( ! V_2 ) ) {
F_28 ( L_22 ) ;
return;
}
if ( F_70 ( ! V_27 -> V_2 ) ) {
F_28 ( L_23 ) ;
F_8 ( V_2 , false ) ;
return;
}
F_74 ( V_2 ) ;
F_8 ( V_2 , false ) ;
F_76 ( V_27 -> V_2 ) ;
}
static int F_77 ( struct V_26 * V_27 , const unsigned char * V_31 ,
int V_64 )
{
struct V_1 * V_2 ;
struct V_33 * V_34 ;
unsigned long V_3 ;
int V_101 = 0 ;
int V_46 = 0 ;
int V_35 = - V_66 ;
if ( F_70 ( ! V_27 ) ) {
F_28 ( L_24 ) ;
return - V_88 ;
}
V_2 = F_9 ( V_27 -> V_9 ) ;
if ( F_70 ( ! V_2 ) ) {
F_28 ( L_25 ) ;
return - V_59 ;
}
F_2 ( & V_2 -> V_19 , V_3 ) ;
V_34 = & V_2 -> V_48 ;
V_34 -> V_38 . type = V_42 ;
while ( V_64 > 0 ) {
V_46 = F_33 ( V_64 , ( V_30 - V_2 -> V_47 ) ) ;
if ( ! V_46 )
break;
memcpy ( & V_34 -> V_43 [ V_2 -> V_47 ] , & V_31 [ V_101 ] ,
V_46 ) ;
V_2 -> V_47 += V_46 ;
V_34 -> V_38 . V_39 = V_46 ;
F_24 ( L_3 , V_34 -> V_38 . type ,
V_34 -> V_38 . V_39 , V_34 -> V_38 . V_40 , V_34 -> V_38 . V_41 ) ;
F_24 ( L_26 , V_34 -> V_43 ) ;
F_25 ( V_2 -> V_18 . V_36 ) ;
V_35 = F_34 ( V_2 -> V_18 . V_36 , V_34 , ( V_49 + V_46 ) ) ;
F_24 ( L_27 ,
( V_49 + V_46 ) , V_35 ) ;
V_101 += V_46 ;
V_64 -= V_46 ;
if ( V_35 < 0 ) {
F_15 ( V_2 ) ;
break;
}
V_2 -> V_47 = 0 ;
}
F_3 ( & V_2 -> V_19 , V_3 ) ;
F_8 ( V_2 , false ) ;
F_24 ( L_28 , V_101 , V_35 ) ;
return V_101 ? V_101 : V_35 ;
}
static int F_78 ( struct V_26 * V_27 )
{
struct V_1 * V_2 ;
T_3 V_102 ;
if ( F_70 ( ! V_27 ) ) {
F_28 ( L_29 ) ;
return - V_88 ;
}
V_2 = F_9 ( V_27 -> V_9 ) ;
if ( F_70 ( ! V_2 ) ) {
F_28 ( L_30 ) ;
return - V_59 ;
}
V_102 = V_30 - V_2 -> V_47 ;
F_8 ( V_2 , false ) ;
return V_102 ;
}
static int F_79 ( struct V_26 * V_27 )
{
struct V_1 * V_2 ;
T_3 V_102 ;
if ( F_70 ( ! V_27 ) ) {
F_28 ( L_31 ) ;
return - V_88 ;
}
V_2 = F_9 ( V_27 -> V_9 ) ;
if ( F_70 ( ! V_2 ) ) {
F_28 ( L_32 ) ;
return - V_59 ;
}
V_102 = V_2 -> V_47 ;
F_8 ( V_2 , false ) ;
return V_102 ;
}
static int F_80 ( struct V_26 * V_27 , int V_103 )
{
struct V_1 * V_2 ;
unsigned long V_3 ;
if ( F_70 ( ! V_27 ) ) {
F_28 ( L_33 ) ;
return - V_88 ;
}
V_2 = F_9 ( V_27 -> V_9 ) ;
if ( F_70 ( ! V_2 ) ) {
F_28 ( L_34 ) ;
return - V_59 ;
}
if ( V_103 == 0 ) {
F_8 ( V_2 , false ) ;
return 0 ;
}
F_2 ( & V_2 -> V_19 , V_3 ) ;
if ( F_41 ( V_2 , V_67 ) < 0 )
F_15 ( V_2 ) ;
F_3 ( & V_2 -> V_19 , V_3 ) ;
F_8 ( V_2 , false ) ;
return 0 ;
}
static int F_81 ( struct V_104 * V_105 , struct V_26 * V_27 )
{
struct V_1 * V_106 ;
struct V_107 * V_108 ;
int V_109 ;
if ( F_70 ( ! V_27 ) ) {
F_28 ( L_35 ) ;
return - V_88 ;
}
if ( V_27 -> V_9 >= V_7 )
return - V_66 ;
V_109 = F_82 ( V_105 , V_27 ) ;
if ( V_109 )
return V_109 ;
V_108 = F_45 ( sizeof( struct V_107 ) , V_76 ) ;
if ( ! V_108 )
return - V_77 ;
V_106 = F_6 ( V_27 -> V_9 , true ) ;
if ( ! V_106 ) {
F_28 ( L_36 ) ;
V_27 -> V_2 = NULL ;
F_62 ( V_108 ) ;
return - V_59 ;
}
F_83 ( V_108 ) ;
V_108 -> V_99 = & V_110 ;
V_27 -> V_2 = V_108 ;
V_106 -> V_27 = V_27 ;
F_8 ( V_106 , true ) ;
return 0 ;
}
static void F_84 ( struct V_26 * V_27 )
{
struct V_1 * V_2 ;
if ( F_70 ( ! V_27 ) ) {
F_28 ( L_37 ) ;
return;
}
V_2 = F_6 ( V_27 -> V_9 , true ) ;
if ( V_2 ) {
V_2 -> V_27 = NULL ;
if ( V_2 -> V_16 ) {
F_4 ( V_27 -> V_9 ) ;
F_62 ( V_2 -> V_18 . V_73 ) ;
F_62 ( V_2 -> V_61 ) ;
F_62 ( V_2 ) ;
} else {
F_8 ( V_2 , true ) ;
}
}
F_85 ( V_27 -> V_2 ) ;
F_62 ( V_27 -> V_2 ) ;
V_27 -> V_2 = NULL ;
}
static int F_86 ( void )
{
int V_35 ;
F_87 ( L_38 , V_111 ) ;
V_75 = F_88 ( V_7 , V_112 ) ;
if ( F_52 ( V_75 ) ) {
F_28 ( L_39 ) ;
return F_53 ( V_75 ) ;
}
V_75 -> V_113 = V_114 ;
V_75 -> V_73 = V_115 ;
V_75 -> V_116 = V_6 ;
V_75 -> type = V_117 ;
V_75 -> V_118 = V_119 ;
F_89 ( V_75 , & V_120 ) ;
V_35 = F_90 ( V_75 ) ;
if ( V_35 ) {
F_28 ( L_40 ) ;
F_91 ( V_75 ) ;
V_75 = NULL ;
return V_35 ;
}
F_24 ( L_41 ) ;
return 0 ;
}
static void F_92 ( void )
{
F_93 ( V_75 ) ;
F_91 ( V_75 ) ;
F_24 ( L_42 ) ;
V_75 = NULL ;
}
static int T_4 F_94 ( void )
{
int V_35 ;
V_35 = F_86 () ;
if ( V_35 ) {
F_28 ( L_43 ) ;
return V_35 ;
}
V_35 = F_95 ( & V_121 ) ;
if ( V_35 ) {
F_28 ( L_44 ) ;
F_92 () ;
} else {
F_24 ( L_45 ) ;
}
return V_35 ;
}
static void T_5 F_96 ( void )
{
F_97 ( & V_121 ) ;
F_24 ( L_46 ) ;
F_92 () ;
F_24 ( L_42 ) ;
}
