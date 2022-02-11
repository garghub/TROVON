static T_1 F_1 ( int V_1 , char T_2 * V_2 , T_3 V_3 ,
T_4 * V_4 )
{
T_1 V_5 = 0 ;
if ( V_3 > V_6 [ V_1 ] . V_7 )
V_3 = V_6 [ V_1 ] . V_7 ;
V_5 = F_2 ( V_6 [ V_1 ] . V_8 , V_6 [ V_1 ] . V_9 ,
V_3 , * V_4 ) ;
if ( V_5 < 0 )
return ( int ) V_5 ;
if ( F_3 ( V_2 , V_6 [ V_1 ] . V_9 , ( unsigned long ) V_5 ) )
return - V_10 ;
return V_5 ;
}
static T_1 F_4 ( unsigned int V_1 , const char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
if ( V_3 > V_6 [ V_1 ] . V_7 )
V_3 = V_6 [ V_1 ] . V_7 ;
if ( F_5 ( V_6 [ V_1 ] . V_9 , V_2 , ( unsigned long ) V_3 ) )
return - V_10 ;
return F_6 ( V_6 [ V_1 ] . V_8 , V_6 [ V_1 ] . V_9 ,
V_3 , * V_4 ) ;
}
static T_1 F_7 ( unsigned int V_1 , char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
void * V_11 ;
V_11 = V_6 [ V_1 ] . V_9 + * V_4 ;
if ( F_3 ( V_2 , V_11 , ( unsigned long ) V_3 ) )
return - V_10 ;
return V_3 ;
}
static T_1 F_8 ( unsigned int V_1 , const char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
void * V_11 ;
V_11 = V_6 [ V_1 ] . V_9 + * V_4 ;
if ( F_5 ( V_11 , V_2 , ( unsigned long ) V_3 ) )
return - V_10 ;
return V_3 ;
}
static T_1 F_9 ( struct V_12 * V_12 , char T_2 * V_2 , T_3 V_3 ,
T_4 * V_4 )
{
unsigned int V_1 = F_10 ( F_11 ( V_12 ) -> V_13 ) ;
T_1 V_14 ;
T_3 V_15 ;
if ( V_1 == V_16 )
return 0 ;
F_12 ( & V_6 [ V_1 ] . V_17 ) ;
V_15 = F_13 ( V_6 [ V_1 ] . V_8 ) ;
if ( ( * V_4 < 0 ) || ( * V_4 > ( V_15 - 1 ) ) ) {
F_14 ( & V_6 [ V_1 ] . V_17 ) ;
return 0 ;
}
if ( * V_4 + V_3 > V_15 )
V_3 = V_15 - * V_4 ;
switch ( type [ V_1 ] ) {
case V_18 :
V_14 = F_1 ( V_1 , V_2 , V_3 , V_4 ) ;
break;
case V_19 :
V_14 = F_7 ( V_1 , V_2 , V_3 , V_4 ) ;
break;
default:
V_14 = - V_20 ;
}
F_14 ( & V_6 [ V_1 ] . V_17 ) ;
if ( V_14 > 0 )
* V_4 += V_14 ;
return V_14 ;
}
static T_1 F_15 ( struct V_12 * V_12 , const char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
unsigned int V_1 = F_10 ( F_11 ( V_12 ) -> V_13 ) ;
T_1 V_14 ;
T_3 V_15 ;
if ( V_1 == V_16 )
return 0 ;
F_12 ( & V_6 [ V_1 ] . V_17 ) ;
V_15 = F_13 ( V_6 [ V_1 ] . V_8 ) ;
if ( ( * V_4 < 0 ) || ( * V_4 > ( V_15 - 1 ) ) ) {
F_14 ( & V_6 [ V_1 ] . V_17 ) ;
return 0 ;
}
if ( * V_4 + V_3 > V_15 )
V_3 = V_15 - * V_4 ;
switch ( type [ V_1 ] ) {
case V_18 :
V_14 = F_4 ( V_1 , V_2 , V_3 , V_4 ) ;
break;
case V_19 :
V_14 = F_8 ( V_1 , V_2 , V_3 , V_4 ) ;
break;
default:
V_14 = - V_20 ;
}
F_14 ( & V_6 [ V_1 ] . V_17 ) ;
if ( V_14 > 0 )
* V_4 += V_14 ;
return V_14 ;
}
static T_4 F_16 ( struct V_12 * V_12 , T_4 V_21 , int V_22 )
{
unsigned int V_1 = F_10 ( F_11 ( V_12 ) -> V_13 ) ;
T_3 V_15 ;
T_4 V_23 ;
switch ( type [ V_1 ] ) {
case V_18 :
case V_19 :
F_12 ( & V_6 [ V_1 ] . V_17 ) ;
V_15 = F_13 ( V_6 [ V_1 ] . V_8 ) ;
V_23 = F_17 ( V_12 , V_21 , V_22 , V_15 ) ;
F_14 ( & V_6 [ V_1 ] . V_17 ) ;
return V_23 ;
}
return - V_20 ;
}
static int F_18 ( struct V_24 * V_24 , struct V_12 * V_12 ,
unsigned int V_25 , unsigned long V_26 )
{
struct V_27 V_28 ;
struct V_29 V_30 ;
struct V_31 V_32 ;
unsigned long V_5 ;
unsigned int V_1 = F_10 ( V_24 -> V_13 ) ;
int V_14 ;
T_5 V_33 ;
void T_2 * V_34 = ( void T_2 * ) V_26 ;
switch ( type [ V_1 ] ) {
case V_16 :
switch ( V_25 ) {
case V_35 :
V_5 = F_19 ( & V_32 , V_34 ,
sizeof( V_32 ) ) ;
if ( V_5 ) {
F_20 ( L_1 ) ;
return - V_10 ;
}
return F_21 ( V_36 ,
V_32 . V_37 ,
V_32 . V_38 ) ;
}
break;
case V_18 :
switch ( V_25 ) {
case V_39 :
memset ( & V_28 , 0 , sizeof( V_28 ) ) ;
V_14 = F_22 ( V_6 [ V_1 ] . V_8 ,
& V_28 . V_40 ,
& V_28 . V_41 ,
& V_28 . V_42 , & V_28 . V_43 ,
& V_28 . V_44 , & V_28 . V_45 ) ;
V_5 = F_23 ( V_34 , & V_28 ,
sizeof( V_28 ) ) ;
if ( V_5 ) {
F_20 ( L_2 ) ;
return - V_10 ;
}
return V_14 ;
case V_46 :
if ( V_6 [ V_1 ] . V_47 != 0 ) {
F_20 ( L_3 ) ;
return - V_48 ;
}
V_5 = F_19 ( & V_28 , V_34 , sizeof( V_28 ) ) ;
if ( V_5 ) {
F_20 ( L_1 ) ;
return - V_10 ;
}
return F_24 ( V_6 [ V_1 ] . V_8 ,
V_28 . V_40 , V_28 . V_41 , V_28 . V_42 ,
V_28 . V_43 , V_28 . V_44 , V_28 . V_45 ) ;
break;
}
break;
case V_19 :
switch ( V_25 ) {
case V_49 :
memset ( & V_30 , 0 , sizeof( V_30 ) ) ;
V_14 = F_25 ( V_6 [ V_1 ] . V_8 ,
& V_30 . V_40 , & V_30 . V_41 ,
& V_30 . V_42 , & V_33 ,
& V_30 . V_43 , & V_30 . V_44 ) ;
V_5 = F_23 ( V_34 , & V_30 ,
sizeof( V_30 ) ) ;
if ( V_5 ) {
F_20 ( L_2 ) ;
return - V_10 ;
}
return V_14 ;
case V_50 :
V_5 = F_19 ( & V_30 , V_34 , sizeof( V_30 ) ) ;
if ( V_5 ) {
F_20 ( L_1 ) ;
return - V_10 ;
}
return F_26 ( V_6 [ V_1 ] . V_8 ,
V_30 . V_40 , V_30 . V_41 , V_30 . V_42 ,
V_6 [ V_1 ] . V_51 , V_30 . V_43 ,
V_30 . V_44 ) ;
break;
}
break;
}
return - V_20 ;
}
static long
F_27 ( struct V_12 * V_12 , unsigned int V_25 , unsigned long V_26 )
{
int V_52 ;
struct V_24 * V_24 = F_11 ( V_12 ) ;
unsigned int V_1 = F_10 ( V_24 -> V_13 ) ;
F_12 ( & V_6 [ V_1 ] . V_17 ) ;
V_52 = F_18 ( V_24 , V_12 , V_25 , V_26 ) ;
F_14 ( & V_6 [ V_1 ] . V_17 ) ;
return V_52 ;
}
static void F_28 ( struct V_53 * V_54 )
{
struct V_55 * V_56 = V_54 -> V_57 ;
F_29 ( & V_56 -> V_58 ) ;
}
static void F_30 ( struct V_53 * V_54 )
{
struct V_55 * V_56 = V_54 -> V_57 ;
unsigned int V_1 = V_56 -> V_1 ;
if ( ! F_31 ( & V_56 -> V_58 ) )
return;
F_12 ( & V_6 [ V_1 ] . V_17 ) ;
V_6 [ V_1 ] . V_47 -- ;
F_14 ( & V_6 [ V_1 ] . V_17 ) ;
F_32 ( V_56 ) ;
}
static int F_33 ( unsigned int V_1 , struct V_53 * V_54 )
{
int V_59 ;
struct V_55 * V_56 ;
F_12 ( & V_6 [ V_1 ] . V_17 ) ;
V_59 = F_34 ( V_6 [ V_1 ] . V_8 , V_54 ) ;
if ( V_59 ) {
F_14 ( & V_6 [ V_1 ] . V_17 ) ;
return V_59 ;
}
V_56 = F_35 ( sizeof( * V_56 ) , V_60 ) ;
if ( ! V_56 ) {
F_14 ( & V_6 [ V_1 ] . V_17 ) ;
return - V_61 ;
}
V_56 -> V_1 = V_1 ;
F_36 ( & V_56 -> V_58 , 1 ) ;
V_54 -> V_62 = & V_63 ;
V_54 -> V_57 = V_56 ;
V_6 [ V_1 ] . V_47 ++ ;
F_14 ( & V_6 [ V_1 ] . V_17 ) ;
return 0 ;
}
static int F_37 ( struct V_12 * V_12 , struct V_53 * V_54 )
{
unsigned int V_1 = F_10 ( F_11 ( V_12 ) -> V_13 ) ;
if ( type [ V_1 ] == V_18 )
return F_33 ( V_1 , V_54 ) ;
return - V_64 ;
}
static int F_38 ( struct V_65 * V_66 )
{
int V_67 ;
int V_68 = F_39 ( V_66 ) ;
int V_69 = F_40 ( V_66 ) ;
for ( V_67 = 0 ; V_67 < V_70 ; V_67 ++ )
if ( ( V_68 == V_71 [ V_67 ] ) && ( V_69 == V_66 -> V_72 ) )
return 1 ;
return 0 ;
}
static int F_41 ( struct V_65 * V_66 )
{
int V_67 , V_59 ;
char * V_73 ;
if ( V_36 ) {
F_42 ( & V_66 -> V_74 , L_4 ) ;
V_59 = - V_20 ;
goto V_75;
}
V_36 = V_66 ;
for ( V_67 = 0 ; V_67 < V_76 ; V_67 ++ ) {
V_6 [ V_67 ] . V_9 = NULL ;
V_6 [ V_67 ] . V_51 = 0 ;
F_43 ( & V_6 [ V_67 ] . V_17 ) ;
V_6 [ V_67 ] . V_77 = NULL ;
V_6 [ V_67 ] . V_8 = NULL ;
}
V_59 = F_44 ( F_45 ( V_78 , 0 ) , V_76 ,
V_79 ) ;
if ( V_59 ) {
F_46 ( & V_66 -> V_74 , L_5 ,
V_78 ) ;
goto V_80;
}
V_81 = F_47 () ;
if ( ! V_81 ) {
V_59 = - V_61 ;
goto V_82;
}
V_81 -> V_83 = & V_84 ;
V_81 -> V_85 = V_86 ;
V_59 = F_48 ( V_81 , F_45 ( V_78 , 0 ) , V_76 ) ;
if ( V_59 )
goto V_82;
for ( V_67 = V_19 ; V_67 < ( V_87 + 1 ) ; V_67 ++ ) {
V_6 [ V_67 ] . V_8 = F_49 ( V_36 ,
V_88 , V_89 ) ;
if ( ! V_6 [ V_67 ] . V_8 ) {
F_46 ( & V_66 -> V_74 ,
L_6 ) ;
V_59 = - V_61 ;
goto V_90;
}
V_6 [ V_67 ] . V_7 = V_91 ;
V_6 [ V_67 ] . V_9 = F_50 ( V_6 [ V_67 ] . V_8 ,
V_6 [ V_67 ] . V_7 , & V_6 [ V_67 ] . V_51 ) ;
if ( ! V_6 [ V_67 ] . V_9 ) {
F_46 ( & V_66 -> V_74 ,
L_7 ) ;
V_6 [ V_67 ] . V_51 = 0 ;
F_51 ( V_6 [ V_67 ] . V_8 ) ;
V_59 = - V_61 ;
goto V_90;
}
}
for ( V_67 = V_18 ; V_67 < ( V_92 + 1 ) ; V_67 ++ ) {
V_6 [ V_67 ] . V_8 = F_52 ( V_36 ,
V_93 , V_89 , V_94 ) ;
if ( ! V_6 [ V_67 ] . V_8 ) {
F_46 ( & V_66 -> V_74 ,
L_8 ) ;
V_59 = - V_61 ;
goto V_95;
}
V_6 [ V_67 ] . V_7 = V_91 ;
V_6 [ V_67 ] . V_9 = F_35 ( V_6 [ V_67 ] . V_7 , V_60 ) ;
if ( ! V_6 [ V_67 ] . V_9 ) {
V_59 = - V_61 ;
F_53 ( V_6 [ V_67 ] . V_8 ) ;
goto V_95;
}
}
V_96 = F_54 ( V_86 , V_79 ) ;
if ( F_55 ( V_96 ) ) {
F_42 ( & V_66 -> V_74 , L_9 ) ;
V_59 = F_56 ( V_96 ) ;
goto V_97;
}
for ( V_67 = 0 ; V_67 < V_76 ; V_67 ++ ) {
int V_72 ;
switch ( type [ V_67 ] ) {
case V_18 :
V_73 = L_10 ;
break;
case V_16 :
V_73 = L_11 ;
break;
case V_19 :
V_73 = L_12 ;
break;
default:
V_59 = - V_20 ;
goto V_98;
}
V_72 = ( type [ V_67 ] == V_19 ) ? V_67 - ( V_92 + 1 ) : V_67 ;
V_6 [ V_67 ] . V_77 = F_57 ( V_96 , NULL ,
F_45 ( V_78 , V_67 ) , NULL , V_73 , V_72 ) ;
if ( F_55 ( V_6 [ V_67 ] . V_77 ) ) {
F_58 ( & V_66 -> V_74 , L_13 ) ;
V_59 = F_56 ( V_6 [ V_67 ] . V_77 ) ;
goto V_98;
}
}
return 0 ;
V_98:
while ( V_67 > 0 ) {
V_67 -- ;
F_59 ( V_96 , F_45 ( V_78 , V_67 ) ) ;
}
F_60 ( V_96 ) ;
V_67 = V_92 + 1 ;
V_95:
while ( V_67 > V_18 ) {
V_67 -- ;
F_32 ( V_6 [ V_67 ] . V_9 ) ;
F_53 ( V_6 [ V_67 ] . V_8 ) ;
}
V_67 = V_87 + 1 ;
V_90:
while ( V_67 > V_19 ) {
V_67 -- ;
F_61 ( V_6 [ V_67 ] . V_8 , V_6 [ V_67 ] . V_7 ,
V_6 [ V_67 ] . V_9 , V_6 [ V_67 ] . V_51 ) ;
F_51 ( V_6 [ V_67 ] . V_8 ) ;
}
V_97:
F_62 ( V_81 ) ;
V_82:
F_63 ( F_45 ( V_78 , 0 ) , V_76 ) ;
V_80:
V_75:
return V_59 ;
}
static int F_64 ( struct V_65 * V_74 )
{
int V_67 ;
for ( V_67 = 0 ; V_67 < V_76 ; V_67 ++ ) {
F_65 ( & V_6 [ V_67 ] . V_17 ) ;
F_59 ( V_96 , F_45 ( V_78 , V_67 ) ) ;
}
F_60 ( V_96 ) ;
for ( V_67 = V_18 ; V_67 < ( V_92 + 1 ) ; V_67 ++ ) {
F_32 ( V_6 [ V_67 ] . V_9 ) ;
F_53 ( V_6 [ V_67 ] . V_8 ) ;
}
for ( V_67 = V_19 ; V_67 < ( V_87 + 1 ) ; V_67 ++ ) {
F_26 ( V_6 [ V_67 ] . V_8 , 0 , 0 , 0 , 0 , V_93 , 0 ) ;
F_61 ( V_6 [ V_67 ] . V_8 , V_6 [ V_67 ] . V_7 ,
V_6 [ V_67 ] . V_9 , V_6 [ V_67 ] . V_51 ) ;
F_51 ( V_6 [ V_67 ] . V_8 ) ;
}
F_62 ( V_81 ) ;
F_63 ( F_45 ( V_78 , 0 ) , V_76 ) ;
return 0 ;
}
static int T_6 F_66 ( void )
{
int V_14 = 0 ;
F_67 ( L_14 ) ;
if ( V_70 == 0 ) {
F_68 ( L_15 ) ;
V_14 = - V_64 ;
goto V_99;
}
if ( V_70 > V_100 ) {
F_68 ( L_16 ,
V_100 ) ;
V_70 = V_100 ;
}
V_14 = F_69 ( & V_101 , V_102 ) ;
if ( V_14 )
goto V_103;
return V_14 ;
V_103:
V_99:
return V_14 ;
}
static void T_7 F_70 ( void )
{
F_71 ( & V_101 ) ;
}
