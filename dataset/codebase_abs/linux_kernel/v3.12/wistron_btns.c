static void F_1 ( struct V_1 * V_1 )
{
unsigned long V_2 ;
F_2 () ;
F_3 ( V_2 ) ;
asm volatile ("pushl %%ebp;"
"movl %7, %%ebp;"
"call *%6;"
"popl %%ebp"
: "=a" (regs->eax), "=b" (regs->ebx), "=c" (regs->ecx)
: "0" (regs->eax), "1" (regs->ebx), "2" (regs->ecx),
"m" (bios_entry_point), "m" (bios_data_map_base)
: "edx", "edi", "esi", "memory");
F_4 ( V_2 ) ;
F_5 () ;
}
static T_1 T_2 F_6 ( void T_3 * V_3 )
{
static unsigned char T_4 V_4 [] =
{ 0x42 , 0x21 , 0x55 , 0x30 } ;
T_1 V_5 ;
for ( V_5 = 0 ; V_5 < 0x10000 ; V_5 += 0x10 ) {
if ( F_7 ( V_3 + V_5 , V_4 ,
sizeof( V_4 ) ) != 0 )
return V_5 ;
}
return - 1 ;
}
static int T_2 F_8 ( void )
{
void T_3 * V_3 ;
T_1 V_5 ;
T_5 V_6 ;
V_3 = F_9 ( 0xF0000 , 0x10000 ) ;
V_5 = F_6 ( V_3 ) ;
if ( V_5 < 0 ) {
F_10 ( V_7 L_1 ) ;
F_11 ( V_3 ) ;
return - V_8 ;
}
V_6 = F_12 ( V_3 + V_5 + 5 ) ;
F_10 ( V_9
L_2 ,
V_3 + V_5 , V_6 ) ;
if ( V_6 >= 0xF0000 ) {
V_10 = V_3 ;
V_11 = V_10 + ( V_6 & 0xFFFF ) ;
} else {
F_11 ( V_3 ) ;
V_10 = F_9 ( V_6 & ~ 0x3FFF , 0x4000 ) ;
if ( V_10 == NULL ) {
F_10 ( V_7
L_3 ,
V_6 & ~ 0x3FFF ) ;
goto V_12;
}
V_11 = V_10 + ( V_6 & 0x3FFF ) ;
}
V_13 = F_9 ( 0x400 , 0xc00 ) ;
if ( V_13 == NULL ) {
F_10 ( V_7 L_4 ) ;
goto V_14;
}
return 0 ;
V_14:
F_11 ( V_10 ) ;
V_12:
return - V_15 ;
}
static inline void F_13 ( void )
{
F_11 ( V_10 ) ;
F_11 ( V_13 ) ;
}
static T_6 F_14 ( void )
{
struct V_1 V_1 ;
memset ( & V_1 , 0 , sizeof ( V_1 ) ) ;
V_1 . V_16 = 0x9610 ;
V_1 . V_17 = 0x061C ;
V_1 . V_18 = 0x0000 ;
F_1 ( & V_1 ) ;
return V_1 . V_16 ;
}
static void F_15 ( void )
{
struct V_1 V_1 ;
memset ( & V_1 , 0 , sizeof ( V_1 ) ) ;
V_1 . V_16 = 0x9610 ;
V_1 . V_17 = 0x012E ;
F_1 ( & V_1 ) ;
}
static void F_16 ( void )
{
struct V_1 V_1 ;
memset ( & V_1 , 0 , sizeof ( V_1 ) ) ;
V_1 . V_16 = 0x9610 ;
V_1 . V_17 = 0x002E ;
F_1 ( & V_1 ) ;
}
static T_7 F_17 ( void )
{
struct V_1 V_1 ;
memset ( & V_1 , 0 , sizeof ( V_1 ) ) ;
V_1 . V_16 = 0x9610 ;
V_1 . V_17 = 0x051C ;
F_1 ( & V_1 ) ;
return V_1 . V_18 ;
}
static T_6 F_18 ( T_7 V_19 )
{
struct V_1 V_1 ;
memset ( & V_1 , 0 , sizeof ( V_1 ) ) ;
V_1 . V_16 = 0x9610 ;
V_1 . V_17 = 0x0200 | V_19 ;
F_1 ( & V_1 ) ;
return V_1 . V_16 ;
}
static void F_19 ( T_7 V_19 , int V_20 )
{
struct V_1 V_1 ;
memset ( & V_1 , 0 , sizeof ( V_1 ) ) ;
V_1 . V_16 = 0x9610 ;
V_1 . V_17 = ( V_20 ? 0x0100 : 0x0000 ) | V_19 ;
F_1 ( & V_1 ) ;
}
static int T_2 F_20 ( const struct V_21 * V_22 )
{
const struct V_23 * V_24 ;
V_25 = V_22 -> V_26 ;
for ( V_24 = V_25 ; V_24 -> type != V_27 ; V_24 ++ ) {
if ( V_24 -> type == V_28 )
V_29 = true ;
else if ( V_24 -> type == V_30 )
V_31 = true ;
}
V_32 = V_24 -> V_33 & ( V_34 | V_35 ) ;
return 1 ;
}
static int T_2 F_21 ( void )
{
const struct V_23 * V_24 ;
struct V_23 * V_36 ;
unsigned int V_37 = 1 ;
for ( V_24 = V_25 ; V_24 -> type != V_27 ; V_24 ++ )
V_37 ++ ;
V_36 = F_22 ( V_25 , V_37 * sizeof( struct V_23 ) ,
V_38 ) ;
if ( ! V_36 )
return - V_15 ;
V_25 = V_36 ;
return 0 ;
}
static int T_2 F_23 ( void )
{
F_24 ( V_39 ) ;
if ( V_40 != NULL ) {
if ( strcmp ( V_40 , L_5 ) == 0 )
V_25 = V_41 ;
else if ( strcmp ( V_40 , L_6 ) == 0 )
V_25 = V_42 ;
else if ( strcmp ( V_40 , L_7 ) == 0 )
V_25 = V_43 ;
else if ( strcmp ( V_40 , L_8 ) == 0 )
V_25 = V_44 ;
else {
F_10 ( V_7 L_9 ) ;
return - V_45 ;
}
}
if ( V_25 == NULL ) {
if ( ! V_46 ) {
F_10 ( V_7 L_10 ) ;
return - V_8 ;
}
V_25 = V_47 ;
}
return F_21 () ;
}
static void F_25 ( struct V_48 * V_49 ,
enum V_50 V_51 )
{
F_19 ( V_52 , ( V_51 != V_53 ) ? 1 : 0 ) ;
}
static void F_26 ( struct V_48 * V_49 ,
enum V_50 V_51 )
{
F_19 ( V_54 , ( V_51 != V_53 ) ? 1 : 0 ) ;
}
static void F_27 ( struct V_55 * V_56 )
{
if ( V_32 & V_35 ) {
T_6 V_57 = F_18 ( V_54 ) ;
if ( V_57 & 1 ) {
V_58 . V_59 = ( V_57 & 2 ) ? V_60 : V_53 ;
if ( F_28 ( V_56 , & V_58 ) )
V_32 &= ~ V_35 ;
else
F_19 ( V_54 , V_58 . V_59 ) ;
} else
V_32 &= ~ V_35 ;
}
if ( V_32 & V_34 ) {
V_61 . V_59 = V_53 ;
if ( F_28 ( V_56 , & V_61 ) )
V_32 &= ~ V_34 ;
else
F_19 ( V_52 , V_61 . V_59 ) ;
}
}
static void F_29 ( void )
{
if ( V_32 & V_34 )
F_30 ( & V_61 ) ;
if ( V_32 & V_35 )
F_30 ( & V_58 ) ;
}
static inline void F_31 ( void )
{
if ( V_32 & V_34 )
F_32 ( & V_61 ) ;
if ( V_32 & V_35 )
F_32 ( & V_58 ) ;
}
static inline void F_33 ( void )
{
if ( V_32 & V_34 )
F_34 ( & V_61 ) ;
if ( V_32 & V_35 )
F_34 ( & V_58 ) ;
}
static void F_35 ( T_7 V_33 )
{
const struct V_23 * V_24 =
F_36 ( V_62 -> V_63 , V_33 ) ;
if ( V_24 ) {
switch ( V_24 -> type ) {
case V_28 :
if ( V_29 ) {
V_64 = ! V_64 ;
F_19 ( V_54 , V_64 ) ;
}
break;
case V_30 :
if ( V_31 ) {
V_65 = ! V_65 ;
F_19 ( V_66 , V_65 ) ;
}
break;
default:
F_37 ( V_62 -> V_63 ,
V_24 , 1 , true ) ;
break;
}
V_67 = V_68 ;
} else
F_10 ( V_69
L_11 , V_33 ) ;
}
static void F_38 ( bool V_70 )
{
T_7 V_71 ;
T_6 V_72 ;
for (; ; ) {
V_71 = F_39 ( V_73 ) ;
if ( V_71 == 0 )
break;
V_72 = F_14 () ;
if ( V_72 != 0 && ! V_70 )
F_35 ( ( T_7 ) V_72 ) ;
}
}
static void F_40 ( struct V_74 * V_75 )
{
F_38 ( true ) ;
}
static void F_41 ( struct V_74 * V_75 )
{
F_38 ( false ) ;
if ( F_42 ( V_68 , V_67 + 2 * V_76 ) )
V_75 -> V_77 = V_78 ;
else
V_75 -> V_77 = V_79 ;
}
static int F_43 ( struct V_80 * V_75 ,
struct V_23 * V_81 )
{
switch ( V_81 -> type ) {
case V_28 :
if ( ! V_29 ) {
V_81 -> type = V_82 ;
V_81 -> V_83 = V_84 ;
}
break;
case V_30 :
if ( ! V_31 ) {
V_81 -> type = V_82 ;
V_81 -> V_83 = V_85 ;
}
break;
case V_27 :
if ( V_81 -> V_33 & V_86 )
F_10 ( V_87 L_12
L_13
L_14 ) ;
break;
}
return 0 ;
}
static int F_44 ( void )
{
struct V_80 * V_80 ;
int error ;
V_62 = F_45 () ;
if ( ! V_62 )
return - V_15 ;
V_62 -> V_88 = F_40 ;
V_62 -> V_89 = F_41 ;
V_62 -> V_77 = V_79 ;
V_80 = V_62 -> V_63 ;
V_80 -> V_90 = L_15 ;
V_80 -> V_91 = L_16 ;
V_80 -> V_92 . V_93 = V_94 ;
V_80 -> V_75 . V_56 = & V_95 -> V_75 ;
error = F_46 ( V_80 , V_25 , F_43 ) ;
if ( error )
goto V_96;
error = F_47 ( V_62 ) ;
if ( error )
goto V_97;
return 0 ;
V_97:
F_48 ( V_80 ) ;
V_96:
F_49 ( V_62 ) ;
return error ;
}
static int F_50 ( struct V_98 * V_75 )
{
int V_12 ;
F_15 () ;
V_73 = F_17 () ;
if ( V_29 ) {
T_6 V_57 = F_18 ( V_54 ) ;
if ( V_57 & 1 )
V_64 = V_57 & 2 ;
else
V_29 = 0 ;
if ( V_29 )
F_19 ( V_54 , V_64 ) ;
}
if ( V_31 ) {
T_6 V_99 = F_18 ( V_66 ) ;
if ( V_99 & 1 )
V_65 = V_99 & 2 ;
else
V_31 = false ;
if ( V_31 )
F_19 ( V_66 , V_65 ) ;
}
F_27 ( & V_75 -> V_75 ) ;
V_12 = F_44 () ;
if ( V_12 ) {
F_16 () ;
return V_12 ;
}
return 0 ;
}
static int F_51 ( struct V_98 * V_75 )
{
F_29 () ;
F_52 ( V_62 ) ;
F_48 ( V_62 -> V_63 ) ;
F_49 ( V_62 ) ;
F_16 () ;
return 0 ;
}
static int F_53 ( struct V_55 * V_75 )
{
if ( V_29 )
F_19 ( V_54 , 0 ) ;
if ( V_31 )
F_19 ( V_66 , 0 ) ;
F_31 () ;
return 0 ;
}
static int F_54 ( struct V_55 * V_75 )
{
if ( V_29 )
F_19 ( V_54 , V_64 ) ;
if ( V_31 )
F_19 ( V_66 , V_65 ) ;
F_33 () ;
F_38 ( true ) ;
return 0 ;
}
static int T_2 F_55 ( void )
{
int V_12 ;
V_12 = F_23 () ;
if ( V_12 )
return V_12 ;
V_12 = F_8 () ;
if ( V_12 )
goto V_97;
V_12 = F_56 ( & V_100 ) ;
if ( V_12 )
goto V_101;
V_95 = F_57 ( L_17 , - 1 ) ;
if ( ! V_95 ) {
V_12 = - V_15 ;
goto V_102;
}
V_12 = F_58 ( V_95 ) ;
if ( V_12 )
goto V_103;
return 0 ;
V_103:
F_59 ( V_95 ) ;
V_102:
F_60 ( & V_100 ) ;
V_101:
F_13 () ;
V_97:
F_61 ( V_25 ) ;
return V_12 ;
}
static void T_8 F_62 ( void )
{
F_63 ( V_95 ) ;
F_60 ( & V_100 ) ;
F_13 () ;
F_61 ( V_25 ) ;
}
