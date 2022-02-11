static bool F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 -> type == V_4 . type ;
}
static bool F_2 ( struct V_1 * V_2 )
{
return V_2 -> V_3 -> type == V_5 . type ;
}
static struct V_6 * F_3 ( struct V_1 * V_2 )
{
if ( F_1 ( V_2 ) && V_7 )
return * F_4 ( V_7 , V_2 -> V_8 ) ;
else if ( F_2 ( V_2 ) && V_9 )
return * F_4 ( V_9 , V_2 -> V_8 ) ;
return NULL ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = & V_2 -> V_12 ;
T_1 V_13 , V_14 ;
T_2 V_15 ;
V_13 = F_6 ( & V_11 -> V_16 ) ;
F_7 ( V_11 -> V_17 , V_14 ) ;
F_8 ( & V_11 -> V_16 , V_14 ) ;
V_15 = ( V_14 << V_18 ) - ( V_13 << V_18 ) ;
V_15 >>= V_18 ;
F_9 ( V_15 , & V_2 -> V_19 ) ;
}
static void F_10 ( struct V_1 * V_2 , int V_20 )
{
struct V_10 * V_11 = & V_2 -> V_12 ;
if ( V_20 & V_21 )
F_11 ( V_11 -> V_22 , ( T_1 ) F_6 ( & V_11 -> V_16 ) ) ;
V_11 -> V_23 = 0 ;
F_11 ( V_11 -> V_24 , ( V_11 -> V_25 | V_26 ) ) ;
F_12 ( V_2 ) ;
}
static void F_13 ( struct V_1 * V_2 , int V_20 )
{
struct V_10 * V_11 = & V_2 -> V_12 ;
F_11 ( V_11 -> V_24 , V_11 -> V_25 ) ;
V_11 -> V_23 |= V_27 ;
if ( ( V_20 & V_28 ) && ! ( V_11 -> V_23 & V_29 ) ) {
F_5 ( V_2 ) ;
V_11 -> V_23 |= V_29 ;
}
}
static int F_14 ( struct V_1 * V_2 , int V_20 )
{
int V_30 ;
struct V_6 * V_31 = F_3 ( V_2 ) ;
struct V_10 * V_11 = & V_2 -> V_12 ;
if ( V_11 -> V_32 != - 1 && V_31 -> V_33 [ V_11 -> V_32 ] == V_2 )
goto V_34;
for ( V_30 = 0 ; V_30 < V_31 -> V_35 ; V_30 ++ ) {
if ( V_31 -> V_33 [ V_30 ] == V_2 ) {
V_11 -> V_32 = V_30 ;
goto V_34;
}
}
V_11 -> V_32 = - 1 ;
for ( V_30 = 0 ; V_30 < V_31 -> V_35 ; V_30 ++ ) {
if ( F_15 ( & V_31 -> V_33 [ V_30 ] , NULL , V_2 ) == NULL ) {
V_11 -> V_32 = V_30 ;
break;
}
}
V_34:
if ( V_11 -> V_32 == - 1 )
return - V_36 ;
V_11 -> V_24 = V_31 -> V_37 + ( 2 * V_11 -> V_32 ) ;
V_11 -> V_22 = V_31 -> V_37 + 1 + ( 2 * V_11 -> V_32 ) ;
V_11 -> V_17 = V_31 -> V_38 + V_11 -> V_32 ;
V_11 -> V_23 = V_29 | V_27 ;
if ( V_20 & V_39 )
F_10 ( V_2 , V_21 ) ;
return 0 ;
}
static void F_16 ( struct V_1 * V_2 , int V_20 )
{
int V_30 ;
struct V_6 * V_31 = F_3 ( V_2 ) ;
struct V_10 * V_11 = & V_2 -> V_12 ;
F_13 ( V_2 , V_28 ) ;
for ( V_30 = 0 ; V_30 < V_31 -> V_35 ; V_30 ++ ) {
if ( F_15 ( & V_31 -> V_33 [ V_30 ] , V_2 , NULL ) == V_2 )
break;
}
V_11 -> V_32 = - 1 ;
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_6 * V_31 ;
struct V_10 * V_11 = & V_2 -> V_12 ;
if ( V_2 -> V_40 . type != V_2 -> V_3 -> type )
return - V_41 ;
if ( F_18 ( V_2 ) || V_2 -> V_42 & V_43 )
return - V_44 ;
if ( V_2 -> V_40 . V_45 || V_2 -> V_40 . V_46 ||
V_2 -> V_40 . V_47 || V_2 -> V_40 . V_48 )
return - V_44 ;
V_11 -> V_25 = V_2 -> V_40 . V_25 & V_49 ;
V_11 -> V_32 = - 1 ;
if ( V_2 -> V_8 < 0 )
return - V_44 ;
V_31 = F_3 ( V_2 ) ;
if ( ! V_31 )
return - V_50 ;
V_2 -> V_8 = V_31 -> V_8 ;
return 0 ;
}
static T_3 F_19 ( struct V_51 * V_52 ,
struct V_53 * V_40 ,
char * V_54 )
{
int V_55 ;
T_4 * V_56 ;
struct V_3 * V_3 = F_20 ( V_52 ) ;
if ( V_3 -> type == V_4 . type )
V_56 = & V_57 ;
else if ( V_3 -> type == V_5 . type )
V_56 = & V_58 ;
else
return 0 ;
V_55 = F_21 ( V_54 , V_59 - 2 , V_56 ) ;
V_54 [ V_55 ++ ] = '\n' ;
V_54 [ V_55 ] = '\0' ;
return V_55 ;
}
static struct V_6 * F_22 ( unsigned int V_8 )
{
return F_23 ( sizeof( struct V_6 ) , V_60 ,
F_24 ( V_8 ) ) ;
}
static void F_25 ( unsigned int V_8 )
{
struct V_6 * V_31 ;
if ( V_7 ) {
V_31 = F_22 ( V_8 ) ;
V_31 -> V_8 = V_8 ;
V_31 -> V_35 = V_61 ;
V_31 -> V_38 = V_62 ;
V_31 -> V_37 = V_63 ;
V_31 -> V_56 = & V_57 ;
V_31 -> V_3 = & V_4 ;
* F_4 ( V_7 , V_8 ) = V_31 ;
}
if ( V_9 ) {
V_31 = F_22 ( V_8 ) ;
V_31 -> V_8 = V_8 ;
V_31 -> V_35 = V_64 ;
V_31 -> V_38 = V_65 ;
V_31 -> V_37 = V_66 ;
V_31 -> V_56 = & V_58 ;
V_31 -> V_3 = & V_5 ;
* F_4 ( V_9 , V_8 ) = V_31 ;
}
}
static struct V_6 *
F_26 ( struct V_6 * V_67 ,
struct V_6 * T_5 * V_68 )
{
unsigned int V_8 ;
struct V_6 * V_69 ;
F_27 (cpu) {
V_69 = * F_4 ( V_68 , V_8 ) ;
if ( ! V_69 )
continue;
if ( V_67 == V_69 )
continue;
if ( V_67 -> V_70 == V_69 -> V_70 ) {
V_69 -> V_71 = V_67 ;
V_67 = V_69 ;
break;
}
}
V_67 -> V_72 ++ ;
return V_67 ;
}
static void F_28 ( unsigned int V_8 )
{
unsigned int V_73 , V_74 , V_75 , V_76 ;
struct V_6 * V_31 ;
if ( V_7 ) {
V_31 = * F_4 ( V_7 , V_8 ) ;
F_29 ( 0x8000001e , & V_73 , & V_74 , & V_75 , & V_76 ) ;
V_31 -> V_70 = V_75 & 0xff ;
V_31 = F_26 ( V_31 , V_7 ) ;
* F_4 ( V_7 , V_8 ) = V_31 ;
}
if ( V_9 ) {
unsigned int V_77 = F_30 ( V_8 ) . V_77 ;
unsigned int V_78 ;
V_31 = * F_4 ( V_9 , V_8 ) ;
F_31 ( 0x8000001d , 2 , & V_73 , & V_74 , & V_75 , & V_76 ) ;
V_78 = ( ( V_73 >> 14 ) & 0xfff ) + 1 ;
V_31 -> V_70 = V_77 - ( V_77 % V_78 ) ;
V_31 = F_26 ( V_31 , V_9 ) ;
* F_4 ( V_9 , V_8 ) = V_31 ;
}
}
static void F_32 ( unsigned int V_8 ,
struct V_6 * T_5 * V_68 )
{
struct V_6 * V_31 = * F_4 ( V_68 , V_8 ) ;
F_33 ( V_31 -> V_71 ) ;
V_31 -> V_71 = NULL ;
if ( V_8 == V_31 -> V_8 )
F_34 ( V_8 , V_31 -> V_56 ) ;
}
static void F_35 ( unsigned int V_8 )
{
if ( V_7 )
F_32 ( V_8 , V_7 ) ;
if ( V_9 )
F_32 ( V_8 , V_9 ) ;
}
static void F_36 ( unsigned int V_8 ,
struct V_6 * T_5 * V_68 )
{
unsigned int V_30 ;
struct V_6 * V_67 = * F_4 ( V_68 , V_8 ) ;
if ( V_67 -> V_8 != V_8 )
return;
F_27 (i) {
struct V_6 * V_69 = * F_4 ( V_68 , V_30 ) ;
if ( V_8 == V_30 )
continue;
if ( V_67 == V_69 ) {
F_37 ( V_67 -> V_3 , V_8 , V_30 ) ;
F_38 ( V_8 , V_69 -> V_56 ) ;
F_34 ( V_30 , V_69 -> V_56 ) ;
V_69 -> V_8 = V_30 ;
break;
}
}
}
static void F_39 ( unsigned int V_8 )
{
if ( V_7 )
F_36 ( V_8 , V_7 ) ;
if ( V_9 )
F_36 ( V_8 , V_9 ) ;
}
static void F_40 ( unsigned int V_8 , struct V_6 * T_5 * V_68 )
{
struct V_6 * V_31 = * F_4 ( V_68 , V_8 ) ;
if ( V_8 == V_31 -> V_8 )
F_38 ( V_8 , V_31 -> V_56 ) ;
if ( ! -- V_31 -> V_72 )
F_33 ( V_31 ) ;
* F_4 ( V_7 , V_8 ) = NULL ;
}
static void F_41 ( unsigned int V_8 )
{
if ( V_7 )
F_40 ( V_8 , V_7 ) ;
if ( V_9 )
F_40 ( V_8 , V_9 ) ;
}
static int
F_42 ( struct V_79 * V_80 , unsigned long V_81 ,
void * V_82 )
{
unsigned int V_8 = ( long ) V_82 ;
switch ( V_81 & ~ V_83 ) {
case V_84 :
F_25 ( V_8 ) ;
break;
case V_85 :
F_28 ( V_8 ) ;
break;
case V_86 :
F_35 ( V_8 ) ;
break;
case V_87 :
F_39 ( V_8 ) ;
break;
case V_88 :
case V_89 :
F_41 ( V_8 ) ;
break;
default:
break;
}
return V_90 ;
}
static void T_6 F_43 ( void * V_91 )
{
unsigned int V_8 = F_44 () ;
F_28 ( V_8 ) ;
F_35 ( V_8 ) ;
}
static int T_6 F_45 ( void )
{
unsigned int V_8 ;
int V_92 = - V_50 ;
if ( V_93 . V_94 != V_95 )
return - V_50 ;
if ( ! V_96 )
return - V_50 ;
if ( V_97 ) {
V_7 = F_46 ( struct V_6 * ) ;
F_47 ( & V_4 , V_4 . V_98 , - 1 ) ;
F_48 ( V_99 L_1 ) ;
V_92 = 0 ;
}
if ( V_100 ) {
V_9 = F_46 ( struct V_6 * ) ;
F_47 ( & V_5 , V_5 . V_98 , - 1 ) ;
F_48 ( V_99 L_2 ) ;
V_92 = 0 ;
}
if ( V_92 )
return - V_50 ;
F_49 () ;
F_27 (cpu) {
F_25 ( V_8 ) ;
F_50 ( V_8 , F_43 , NULL , 1 ) ;
}
F_51 ( & V_101 ) ;
F_52 () ;
return 0 ;
}
