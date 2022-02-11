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
static int F_7 ( struct V_8 * V_9 ,
enum V_10 V_11 )
{
int V_12 = 0 ;
switch ( V_11 ) {
case V_13 :
break;
case V_14 :
F_5 ( V_9 -> V_2 ) ;
break;
case V_15 :
if ( V_9 -> V_2 -> V_16 ) {
V_9 -> V_2 -> V_16 ( false ) ;
F_4 ( L_3 , V_9 -> V_2 -> V_7 ) ;
}
break;
}
switch ( V_9 -> V_17 ) {
case V_13 :
break;
case V_14 :
F_1 ( V_9 -> V_2 ) ;
break;
case V_15 :
if ( V_9 -> V_2 -> V_16 && V_9 -> V_2 -> V_16 ( true ) )
F_4 ( L_4 , V_9 -> V_2 -> V_7 ) ;
else
V_12 = - V_18 ;
break;
}
return V_12 ;
}
static void F_8 ( struct V_1 * V_2 )
{
unsigned long V_19 ;
struct V_8 * V_9 ;
V_9 = F_9 ( sizeof( * V_9 ) , V_20 ) ;
V_9 -> V_2 = V_2 ;
V_9 -> V_21 = V_13 ;
switch ( V_2 -> V_22 ) {
case V_23 :
V_9 -> V_17 = V_14 ;
V_9 -> V_24 = V_15 ;
break;
case V_25 :
V_9 -> V_17 = V_13 ;
V_9 -> V_24 = V_14 ;
break;
}
F_10 ( & V_26 , V_19 ) ;
F_11 ( & V_9 -> V_27 , & V_8 ) ;
V_28 ++ ;
F_12 ( & V_26 , V_19 ) ;
F_7 ( V_9 , V_13 ) ;
}
static int F_13 ( struct V_29 * V_30 , int V_31 ,
void T_1 * V_32 , T_2 * V_33 ,
T_3 * V_34 )
{
int V_12 = 0 ;
struct V_8 * V_9 = (struct V_8 * ) V_30 -> V_35 ;
enum V_10 V_36 = V_9 -> V_17 ;
V_30 -> V_35 = & V_9 -> V_17 ;
V_12 = F_14 ( V_30 , V_31 , V_32 , V_33 , V_34 ) ;
if ( V_12 || ! V_31 || V_36 == V_9 -> V_17 )
goto V_12;
V_12 = F_7 ( V_9 , V_36 ) ;
if ( V_12 ) {
V_9 -> V_17 = V_36 ;
F_7 ( V_9 , V_13 ) ;
}
V_12:
V_30 -> V_35 = V_9 ;
return V_12 ;
}
static void F_15 ( struct V_29 * V_30 )
{
unsigned long V_19 ;
int V_37 = 0 ;
struct V_8 * V_9 ;
struct V_29 * V_38 , * V_39 ;
V_38 = F_9 ( sizeof( * V_39 ) * ( V_28 + 1 ) ,
V_20 ) ;
F_10 ( & V_26 , V_19 ) ;
F_16 (insn, &insn_emulation, node) {
V_39 = & V_38 [ V_37 ] ;
V_39 -> V_40 = 0644 ;
V_39 -> V_41 = sizeof( int ) ;
V_39 -> V_42 = V_9 -> V_2 -> V_7 ;
V_39 -> V_35 = V_9 ;
V_39 -> V_43 = & V_9 -> V_21 ;
V_39 -> V_44 = & V_9 -> V_24 ;
V_39 -> V_45 = F_13 ;
V_37 ++ ;
}
F_12 ( & V_26 , V_19 ) ;
V_30 -> V_46 = V_38 ;
F_17 ( V_30 ) ;
}
static void F_18 ( struct V_47 * V_48 , unsigned long V_49 )
{
T_4 V_50 ;
F_19 ( & V_51 -> V_52 -> V_53 ) ;
if ( F_20 ( V_51 -> V_52 , V_49 ) == NULL )
V_50 . V_54 = V_55 ;
else
V_50 . V_54 = V_56 ;
F_21 ( & V_51 -> V_52 -> V_53 ) ;
V_50 . V_57 = V_58 ;
V_50 . V_59 = 0 ;
V_50 . V_60 = ( void * ) F_22 ( V_48 ) ;
F_23 ( L_5 ) ;
F_24 ( L_6 , V_48 , & V_50 , 0 ) ;
}
static int F_25 ( unsigned int V_61 , unsigned int * V_35 ,
unsigned int type )
{
unsigned int V_62 = 0 ;
if ( ( type != V_63 ) && ( V_61 & 0x3 ) ) {
F_23 ( L_7 ) ;
return - V_64 ;
}
while ( 1 ) {
unsigned long V_65 ;
if ( type == V_63 )
F_26 ( * V_35 , V_61 , V_62 , V_65 ) ;
else
F_27 ( * V_35 , V_61 , V_62 , V_65 ) ;
if ( F_28 ( V_62 != - V_66 ) || F_29 ( V_51 ) )
break;
F_30 () ;
}
return V_62 ;
}
static int F_31 ( struct V_47 * V_48 , T_5 V_67 )
{
T_5 V_68 , V_35 , type , V_61 = 0 ;
int V_69 , V_70 , V_62 = 0 ;
F_32 ( V_71 , 1 , V_48 , V_48 -> V_72 ) ;
type = V_67 & V_63 ;
switch ( F_33 ( V_67 , V_48 -> V_73 ) ) {
case V_74 :
break;
case V_75 :
goto V_12;
case V_76 :
return - V_64 ;
default:
return - V_18 ;
}
V_69 = F_34 ( V_67 , V_77 ) ;
V_70 = F_34 ( V_67 , V_78 ) ;
V_61 = ( T_5 ) V_48 -> V_79 . V_48 [ V_69 ] ;
V_35 = ( T_5 ) V_48 -> V_79 . V_48 [ V_70 ] ;
V_68 = F_34 ( V_67 , V_80 ) ;
F_23 ( L_8 ,
V_69 , V_61 , V_68 ,
F_34 ( V_67 , V_78 ) , V_35 ) ;
if ( ! F_35 ( V_81 , ( V_61 & ~ 3 ) , 4 ) ) {
F_23 ( L_9 ,
V_61 ) ;
goto V_82;
}
V_62 = F_25 ( V_61 , & V_35 , type ) ;
if ( V_62 == - V_64 )
goto V_82;
else if ( V_62 == 0 )
V_48 -> V_79 . V_48 [ V_68 ] = V_35 ;
V_12:
if ( type == V_63 )
F_36 ( L_10 , V_48 -> V_72 ) ;
else
F_36 ( L_11 , V_48 -> V_72 ) ;
F_37 ( L_12 ,
V_51 -> V_83 , ( unsigned long ) V_51 -> V_84 , V_48 -> V_72 ) ;
V_48 -> V_72 += 4 ;
return 0 ;
V_82:
F_18 ( V_48 , V_61 ) ;
return 0 ;
}
static int F_38 ( struct V_47 * V_48 , T_5 V_67 )
{
F_32 ( V_71 , 1 , V_48 , V_48 -> V_72 ) ;
switch ( F_33 ( V_67 , V_48 -> V_73 ) ) {
case V_74 :
break;
case V_75 :
goto V_12;
case V_76 :
return - V_64 ;
default:
return - V_18 ;
}
switch ( F_39 ( V_67 ) ) {
case 10 :
if ( F_40 ( V_67 ) == 5 ) {
F_41 ( V_85 ) ;
F_36 (
L_13 , V_48 -> V_72 ) ;
} else {
F_42 ( V_85 ) ;
F_36 (
L_14 , V_48 -> V_72 ) ;
}
break;
case 5 :
F_36 (
L_15 , V_48 -> V_72 ) ;
break;
}
V_12:
F_37 ( L_16 ,
V_51 -> V_83 , ( unsigned long ) V_51 -> V_84 , V_48 -> V_72 ) ;
V_48 -> V_72 += 4 ;
return 0 ;
}
static inline void F_43 ( T_5 V_86 , T_5 V_87 )
{
T_5 V_88 ;
asm volatile("mrs %0, sctlr_el1" : "=r" (val));
V_88 &= ~ V_86 ;
V_88 |= V_87 ;
asm volatile("msr sctlr_el1, %0" : : "r" (val));
}
static void F_44 ( void * V_50 )
{
F_43 ( 0 , V_89 ) ;
}
static void F_45 ( void * V_50 )
{
F_43 ( V_89 , 0 ) ;
}
static int F_46 ( struct V_90 * V_91 ,
unsigned long V_92 , void * V_93 )
{
switch ( V_92 ) {
case V_94 :
case V_95 :
F_44 ( NULL ) ;
return V_96 ;
case V_97 :
case V_98 :
F_45 ( NULL ) ;
return V_96 ;
}
return V_99 ;
}
static int F_47 ( bool V_100 )
{
if ( V_100 ) {
F_48 ( & V_101 ) ;
F_49 ( F_44 , NULL , true ) ;
} else {
F_50 ( & V_101 ) ;
F_49 ( F_45 , NULL , true ) ;
}
return true ;
}
static int T_6 F_51 ( void )
{
if ( F_52 ( V_102 ) )
F_8 ( & V_103 ) ;
if ( F_52 ( V_104 ) )
F_8 ( & V_105 ) ;
F_15 ( V_106 ) ;
return 0 ;
}
