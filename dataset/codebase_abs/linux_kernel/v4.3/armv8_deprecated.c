static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
F_2 ( ! V_2 -> V_5 ) ;
for ( V_4 = V_2 -> V_5 ; V_4 -> V_6 ; V_4 ++ )
F_3 ( V_4 ) ;
F_4 ( L_1 , V_2 -> V_7 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
F_2 ( ! V_2 -> V_5 ) ;
for ( V_4 = V_2 -> V_5 ; V_4 -> V_6 ; V_4 ++ )
F_6 ( V_4 ) ;
F_4 ( L_2 , V_2 -> V_7 ) ;
}
static void F_7 ( void * V_8 )
{
struct V_9 * V_10 = (struct V_9 * ) V_8 ;
if ( V_10 -> V_2 -> V_11 )
V_10 -> V_2 -> V_11 ( true ) ;
}
static void F_8 ( void * V_8 )
{
struct V_9 * V_10 = (struct V_9 * ) V_8 ;
if ( V_10 -> V_2 -> V_11 )
V_10 -> V_2 -> V_11 ( false ) ;
}
static int F_9 ( struct V_9 * V_10 , bool V_12 )
{
if ( ! V_10 -> V_2 -> V_11 )
return - V_13 ;
if ( V_12 )
F_10 ( F_7 , ( void * ) V_10 , true ) ;
else
F_10 ( F_8 , ( void * ) V_10 , true ) ;
return 0 ;
}
static int F_11 ( unsigned long V_14 )
{
int V_15 = 0 ;
unsigned long V_16 ;
struct V_9 * V_10 ;
F_12 ( & V_17 , V_16 ) ;
F_13 (insn, &insn_emulation, node) {
bool V_12 = ( V_10 -> V_18 == V_19 ) ;
if ( V_10 -> V_2 -> V_11 && V_10 -> V_2 -> V_11 ( V_12 ) ) {
F_14 ( L_3 ,
V_14 , V_10 -> V_2 -> V_7 ) ;
V_15 = - V_13 ;
}
}
F_15 ( & V_17 , V_16 ) ;
return V_15 ;
}
static int F_16 ( struct V_9 * V_10 ,
enum V_20 V_21 )
{
int V_22 = 0 ;
switch ( V_21 ) {
case V_23 :
break;
case V_24 :
F_5 ( V_10 -> V_2 ) ;
break;
case V_19 :
if ( ! F_9 ( V_10 , false ) )
F_4 ( L_4 , V_10 -> V_2 -> V_7 ) ;
break;
}
switch ( V_10 -> V_18 ) {
case V_23 :
break;
case V_24 :
F_1 ( V_10 -> V_2 ) ;
break;
case V_19 :
V_22 = F_9 ( V_10 , true ) ;
if ( ! V_22 )
F_4 ( L_5 , V_10 -> V_2 -> V_7 ) ;
break;
}
return V_22 ;
}
static void F_17 ( struct V_1 * V_2 )
{
unsigned long V_16 ;
struct V_9 * V_10 ;
V_10 = F_18 ( sizeof( * V_10 ) , V_25 ) ;
V_10 -> V_2 = V_2 ;
V_10 -> V_26 = V_23 ;
switch ( V_2 -> V_27 ) {
case V_28 :
V_10 -> V_18 = V_24 ;
F_9 ( V_10 , false ) ;
V_10 -> V_29 = V_19 ;
break;
case V_30 :
V_10 -> V_18 = V_23 ;
V_10 -> V_29 = V_24 ;
break;
}
F_12 ( & V_17 , V_16 ) ;
F_19 ( & V_10 -> V_31 , & V_9 ) ;
V_32 ++ ;
F_15 ( & V_17 , V_16 ) ;
F_16 ( V_10 , V_23 ) ;
}
static int F_20 ( struct V_33 * V_34 , int V_35 ,
void T_1 * V_36 , T_2 * V_37 ,
T_3 * V_38 )
{
int V_22 = 0 ;
struct V_9 * V_10 = (struct V_9 * ) V_34 -> V_8 ;
enum V_20 V_39 = V_10 -> V_18 ;
V_34 -> V_8 = & V_10 -> V_18 ;
V_22 = F_21 ( V_34 , V_35 , V_36 , V_37 , V_38 ) ;
if ( V_22 || ! V_35 || V_39 == V_10 -> V_18 )
goto V_22;
V_22 = F_16 ( V_10 , V_39 ) ;
if ( V_22 ) {
V_10 -> V_18 = V_39 ;
F_16 ( V_10 , V_23 ) ;
}
V_22:
V_34 -> V_8 = V_10 ;
return V_22 ;
}
static void F_22 ( struct V_33 * V_34 )
{
unsigned long V_16 ;
int V_40 = 0 ;
struct V_9 * V_10 ;
struct V_33 * V_41 , * V_42 ;
V_41 = F_18 ( sizeof( * V_42 ) * ( V_32 + 1 ) ,
V_25 ) ;
F_12 ( & V_17 , V_16 ) ;
F_13 (insn, &insn_emulation, node) {
V_42 = & V_41 [ V_40 ] ;
V_42 -> V_43 = 0644 ;
V_42 -> V_44 = sizeof( int ) ;
V_42 -> V_45 = V_10 -> V_2 -> V_7 ;
V_42 -> V_8 = V_10 ;
V_42 -> V_46 = & V_10 -> V_26 ;
V_42 -> V_47 = & V_10 -> V_29 ;
V_42 -> V_48 = F_20 ;
V_40 ++ ;
}
F_15 ( & V_17 , V_16 ) ;
V_34 -> V_49 = V_41 ;
F_23 ( V_34 ) ;
}
static void F_24 ( struct V_50 * V_51 , unsigned long V_52 )
{
T_4 V_53 ;
F_25 ( & V_54 -> V_55 -> V_56 ) ;
if ( F_26 ( V_54 -> V_55 , V_52 ) == NULL )
V_53 . V_57 = V_58 ;
else
V_53 . V_57 = V_59 ;
F_27 ( & V_54 -> V_55 -> V_56 ) ;
V_53 . V_60 = V_61 ;
V_53 . V_62 = 0 ;
V_53 . V_63 = ( void * ) F_28 ( V_51 ) ;
F_29 ( L_6 ) ;
F_30 ( L_7 , V_51 , & V_53 , 0 ) ;
}
static int F_31 ( unsigned int V_64 , unsigned int * V_8 ,
unsigned int type )
{
unsigned int V_65 = 0 ;
if ( ( type != V_66 ) && ( V_64 & 0x3 ) ) {
F_29 ( L_8 ) ;
return - V_67 ;
}
while ( 1 ) {
unsigned long V_68 ;
if ( type == V_66 )
F_32 ( * V_8 , V_64 , V_65 , V_68 ) ;
else
F_33 ( * V_8 , V_64 , V_65 , V_68 ) ;
if ( F_34 ( V_65 != - V_69 ) || F_35 ( V_54 ) )
break;
F_36 () ;
}
return V_65 ;
}
static int F_37 ( struct V_50 * V_51 , T_5 V_70 )
{
T_5 V_71 , V_8 , type , V_64 = 0 ;
int V_72 , V_73 , V_65 = 0 ;
F_38 ( V_74 , 1 , V_51 , V_51 -> V_75 ) ;
type = V_70 & V_66 ;
switch ( F_39 ( V_70 , V_51 -> V_76 ) ) {
case V_77 :
break;
case V_78 :
goto V_22;
case V_79 :
return - V_67 ;
default:
return - V_13 ;
}
V_72 = F_40 ( V_70 , V_80 ) ;
V_73 = F_40 ( V_70 , V_81 ) ;
V_64 = ( T_5 ) V_51 -> V_82 . V_51 [ V_72 ] ;
V_8 = ( T_5 ) V_51 -> V_82 . V_51 [ V_73 ] ;
V_71 = F_40 ( V_70 , V_83 ) ;
F_29 ( L_9 ,
V_72 , V_64 , V_71 ,
F_40 ( V_70 , V_81 ) , V_8 ) ;
if ( ! F_41 ( V_84 , ( V_64 & ~ 3 ) , 4 ) ) {
F_29 ( L_10 ,
V_64 ) ;
goto V_85;
}
V_65 = F_31 ( V_64 , & V_8 , type ) ;
if ( V_65 == - V_67 )
goto V_85;
else if ( V_65 == 0 )
V_51 -> V_82 . V_51 [ V_71 ] = V_8 ;
V_22:
if ( type == V_66 )
F_42 ( L_11 , V_51 -> V_75 ) ;
else
F_42 ( L_12 , V_51 -> V_75 ) ;
F_43 ( L_13 ,
V_54 -> V_86 , ( unsigned long ) V_54 -> V_87 , V_51 -> V_75 ) ;
V_51 -> V_75 += 4 ;
return 0 ;
V_85:
F_24 ( V_51 , V_64 ) ;
return 0 ;
}
static int F_44 ( struct V_50 * V_51 , T_5 V_70 )
{
F_38 ( V_74 , 1 , V_51 , V_51 -> V_75 ) ;
switch ( F_39 ( V_70 , V_51 -> V_76 ) ) {
case V_77 :
break;
case V_78 :
goto V_22;
case V_79 :
return - V_67 ;
default:
return - V_13 ;
}
switch ( F_45 ( V_70 ) ) {
case 10 :
if ( F_46 ( V_70 ) == 5 ) {
F_47 ( V_88 ) ;
F_42 (
L_14 , V_51 -> V_75 ) ;
} else {
F_48 ( V_88 ) ;
F_42 (
L_15 , V_51 -> V_75 ) ;
}
break;
case 5 :
F_42 (
L_16 , V_51 -> V_75 ) ;
break;
}
V_22:
F_43 ( L_17 ,
V_54 -> V_86 , ( unsigned long ) V_54 -> V_87 , V_51 -> V_75 ) ;
V_51 -> V_75 += 4 ;
return 0 ;
}
static int F_49 ( bool V_12 )
{
if ( V_12 )
F_50 ( 0 , V_89 ) ;
else
F_50 ( V_89 , 0 ) ;
return 0 ;
}
static int F_51 ( bool V_12 )
{
if ( ! F_52 () )
return - V_13 ;
if ( V_12 )
F_50 ( V_90 , 0 ) ;
else
F_50 ( 0 , V_90 ) ;
return 0 ;
}
static int F_53 ( struct V_50 * V_51 , T_5 V_91 )
{
char * V_10 ;
F_38 ( V_74 , 1 , V_51 , V_51 -> V_75 ) ;
if ( V_91 ) {
V_10 = L_18 ;
V_51 -> V_76 |= V_92 ;
} else {
V_10 = L_19 ;
V_51 -> V_76 &= ~ V_92 ;
}
F_42 ( V_10 , V_51 -> V_75 ) ;
F_43 ( L_20 ,
V_54 -> V_86 , ( unsigned long ) V_54 -> V_87 , V_51 -> V_75 ) ;
return 0 ;
}
static int F_54 ( struct V_50 * V_51 , T_5 V_70 )
{
int V_15 = F_53 ( V_51 , ( V_70 >> 9 ) & 1 ) ;
V_51 -> V_75 += 4 ;
return V_15 ;
}
static int F_55 ( struct V_50 * V_51 , T_5 V_70 )
{
int V_15 = F_53 ( V_51 , ( V_70 >> 3 ) & 1 ) ;
V_51 -> V_75 += 2 ;
return V_15 ;
}
static int F_56 ( struct V_93 * V_94 ,
unsigned long V_95 , void * V_96 )
{
int V_15 = 0 ;
if ( ( V_95 & ~ V_97 ) == V_98 )
V_15 = F_11 ( ( unsigned long ) V_96 ) ;
return F_57 ( V_15 ) ;
}
static int T_6 F_58 ( void )
{
if ( F_59 ( V_99 ) )
F_17 ( & V_100 ) ;
if ( F_59 ( V_101 ) )
F_17 ( & V_102 ) ;
if ( F_59 ( V_103 ) ) {
if( F_60 () )
F_17 ( & V_104 ) ;
else
F_61 ( L_21 ) ;
}
F_62 ( & V_105 ) ;
F_22 ( V_106 ) ;
return 0 ;
}
