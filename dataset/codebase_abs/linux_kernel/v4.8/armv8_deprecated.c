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
static int F_11 ( unsigned int V_14 )
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
static void T_1 F_17 ( struct V_1 * V_2 )
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
void T_2 * V_36 , T_3 * V_37 ,
T_4 * V_38 )
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
static void T_1 F_22 ( struct V_33 * V_34 )
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
static int F_24 ( unsigned int V_50 , unsigned int * V_8 ,
unsigned int type )
{
unsigned int V_51 = 0 ;
if ( ( type != V_52 ) && ( V_50 & 0x3 ) ) {
F_25 ( L_6 ) ;
return - V_53 ;
}
while ( 1 ) {
unsigned long V_54 ;
if ( type == V_52 )
F_26 ( * V_8 , V_50 , V_51 , V_54 ) ;
else
F_27 ( * V_8 , V_50 , V_51 , V_54 ) ;
if ( F_28 ( V_51 != - V_55 ) || F_29 ( V_56 ) )
break;
F_30 () ;
}
return V_51 ;
}
static unsigned int T_5 F_31 ( T_6 V_57 , T_6 V_58 )
{
T_6 V_59 = V_57 >> 28 ;
if ( V_59 != V_60 ) {
if ( (* F_32 [ V_59 ])( V_58 ) )
return V_61 ;
else
return V_62 ;
}
return V_63 ;
}
static int F_33 ( struct V_64 * V_65 , T_6 V_66 )
{
T_6 V_67 , V_8 , type , V_50 = 0 ;
int V_68 , V_69 , V_51 = 0 ;
F_34 ( V_70 , 1 , V_65 , V_65 -> V_71 ) ;
type = V_66 & V_52 ;
switch ( F_31 ( V_66 , V_65 -> V_72 ) ) {
case V_61 :
break;
case V_62 :
goto V_22;
case V_63 :
return - V_53 ;
default:
return - V_13 ;
}
V_68 = F_35 ( V_66 , V_73 ) ;
V_69 = F_35 ( V_66 , V_74 ) ;
V_50 = ( T_6 ) V_65 -> V_75 . V_65 [ V_68 ] ;
V_8 = ( T_6 ) V_65 -> V_75 . V_65 [ V_69 ] ;
V_67 = F_35 ( V_66 , V_76 ) ;
F_25 ( L_7 ,
V_68 , V_50 , V_67 ,
F_35 ( V_66 , V_74 ) , V_8 ) ;
if ( ! F_36 ( V_77 , ( V_50 & ~ 3 ) , 4 ) ) {
F_25 ( L_8 ,
V_50 ) ;
goto V_78;
}
V_51 = F_24 ( V_50 , & V_8 , type ) ;
if ( V_51 == - V_53 )
goto V_78;
else if ( V_51 == 0 )
V_65 -> V_75 . V_65 [ V_67 ] = V_8 ;
V_22:
if ( type == V_52 )
F_37 ( L_9 , V_65 -> V_71 ) ;
else
F_37 ( L_10 , V_65 -> V_71 ) ;
F_38 ( L_11 ,
V_56 -> V_79 , ( unsigned long ) V_56 -> V_80 , V_65 -> V_71 ) ;
V_65 -> V_71 += 4 ;
return 0 ;
V_78:
F_25 ( L_12 ) ;
F_39 ( V_65 , V_50 ) ;
return 0 ;
}
static int F_40 ( struct V_64 * V_65 , T_6 V_66 )
{
F_34 ( V_70 , 1 , V_65 , V_65 -> V_71 ) ;
switch ( F_31 ( V_66 , V_65 -> V_72 ) ) {
case V_61 :
break;
case V_62 :
goto V_22;
case V_63 :
return - V_53 ;
default:
return - V_13 ;
}
switch ( F_41 ( V_66 ) ) {
case 10 :
if ( F_42 ( V_66 ) == 5 ) {
F_43 ( V_81 ) ;
F_37 (
L_13 , V_65 -> V_71 ) ;
} else {
F_44 ( V_81 ) ;
F_37 (
L_14 , V_65 -> V_71 ) ;
}
break;
case 5 :
F_37 (
L_15 , V_65 -> V_71 ) ;
break;
}
V_22:
F_38 ( L_16 ,
V_56 -> V_79 , ( unsigned long ) V_56 -> V_80 , V_65 -> V_71 ) ;
V_65 -> V_71 += 4 ;
return 0 ;
}
static int F_45 ( bool V_12 )
{
if ( V_12 )
F_46 ( 0 , V_82 ) ;
else
F_46 ( V_82 , 0 ) ;
return 0 ;
}
static int F_47 ( bool V_12 )
{
if ( ! F_48 () )
return - V_13 ;
if ( V_12 )
F_46 ( V_83 , 0 ) ;
else
F_46 ( 0 , V_83 ) ;
return 0 ;
}
static int F_49 ( struct V_64 * V_65 , T_6 V_84 )
{
char * V_10 ;
F_34 ( V_70 , 1 , V_65 , V_65 -> V_71 ) ;
if ( V_84 ) {
V_10 = L_17 ;
V_65 -> V_72 |= V_85 ;
} else {
V_10 = L_18 ;
V_65 -> V_72 &= ~ V_85 ;
}
F_37 ( V_10 , V_65 -> V_71 ) ;
F_38 ( L_19 ,
V_56 -> V_79 , ( unsigned long ) V_56 -> V_80 , V_65 -> V_71 ) ;
return 0 ;
}
static int F_50 ( struct V_64 * V_65 , T_6 V_66 )
{
int V_15 = F_49 ( V_65 , ( V_66 >> 9 ) & 1 ) ;
V_65 -> V_71 += 4 ;
return V_15 ;
}
static int F_51 ( struct V_64 * V_65 , T_6 V_66 )
{
int V_15 = F_49 ( V_65 , ( V_66 >> 3 ) & 1 ) ;
V_65 -> V_71 += 2 ;
return V_15 ;
}
static int T_1 F_52 ( void )
{
if ( F_53 ( V_86 ) )
F_17 ( & V_87 ) ;
if ( F_53 ( V_88 ) )
F_17 ( & V_89 ) ;
if ( F_53 ( V_90 ) ) {
if( F_54 () )
F_17 ( & V_91 ) ;
else
F_55 ( L_20 ) ;
}
F_56 ( V_92 ,
L_21 ,
F_11 , NULL ) ;
F_22 ( V_93 ) ;
return 0 ;
}
