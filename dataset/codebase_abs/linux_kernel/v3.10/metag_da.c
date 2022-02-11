static int F_1 ( int V_1 , int V_2 ,
int V_3 , void * V_4 ,
void * V_5 )
{
register int T_1 V_6 ( L_1 ) = V_1 ;
register int T_2 V_6 ( L_2 ) = V_2 ;
register int T_3 V_6 ( L_3 ) = V_3 ;
register void * T_4 V_6 ( L_4 ) = V_4 ;
register void * T_5 V_6 ( L_5 ) = V_5 ;
register int T_6 V_6 ( L_6 ) = 3 ;
register int T_7 V_6 ( L_7 ) ;
asm volatile (
"MSETL [A0StP++], %6,%4,%2\n\t"
"ADD A0StP, A0StP, #8\n\t"
"SWITCH #0x0C30208\n\t"
"GETD %0, [A0StP+#-8]\n\t"
"SUB A0StP, A0StP, #(4*6)+8\n\t"
: "=d" (result)
: "d" (bios_function),
"d" (channel),
"d" (arg2),
"d" (arg3),
"d" (arg4),
"d" (bios_call)
: "memory");
return T_7 ;
}
static int F_2 ( unsigned int T_2 )
{
struct V_7 * V_8 = & V_9 [ T_2 ] ;
int V_10 = 0 ;
F_3 ( & V_8 -> V_11 ) ;
if ( ! V_8 -> V_12 )
goto V_13;
if ( F_1 ( V_14 , T_2 , V_15 ,
( void * ) V_8 -> V_12 , & V_10 ) == V_16 ) {
if ( V_10 ) {
int V_17 ;
unsigned char * V_18 ;
V_17 = F_4 ( & V_8 -> V_19 , & V_18 ,
V_10 ) ;
if ( V_17 <= 0 )
goto V_13;
memcpy ( V_18 , V_8 -> V_12 , V_17 ) ;
F_5 ( & V_8 -> V_19 ) ;
}
}
V_13:
F_6 ( & V_8 -> V_11 ) ;
return V_10 ;
}
static int F_7 ( void )
{
static int V_20 ;
int V_21 = V_20 ;
int V_22 ;
struct V_7 * V_8 ;
for ( V_22 = V_21 + 1 ; ; ++ V_22 ) {
if ( V_22 >= V_23 )
V_22 = 0 ;
V_8 = & V_9 [ V_22 ] ;
if ( V_8 -> V_12 ) {
V_20 = V_22 ;
return V_22 ;
}
if ( V_22 == V_21 )
break;
}
return - 1 ;
}
static int F_8 ( unsigned int V_22 )
{
struct V_7 * V_8 ;
struct V_24 * V_25 ;
int V_26 ;
unsigned int V_27 = 0 ;
V_8 = & V_9 [ V_22 ] ;
F_9 ( & V_8 -> V_28 ) ;
if ( V_8 -> V_29 ) {
V_27 = F_10 ( ( unsigned int ) ( V_30 - V_8 -> V_31 ) ,
V_8 -> V_29 ) ;
F_1 ( V_32 , V_22 , V_27 ,
V_8 -> V_19 . V_33 + V_8 -> V_31 ,
& V_26 ) ;
V_8 -> V_29 -= V_26 ;
if ( ! V_8 -> V_29 ) {
V_8 -> V_34 = 0 ;
V_8 -> V_31 = 0 ;
F_11 ( & V_8 -> V_35 ) ;
} else {
V_8 -> V_31 += V_26 ;
if ( V_8 -> V_31 >= V_30 )
V_8 -> V_31 -= V_30 ;
}
F_12 ( V_26 , & V_36 ) ;
}
F_13 ( & V_8 -> V_28 ) ;
if ( V_27 && V_26 ) {
V_25 = F_14 ( & V_8 -> V_19 ) ;
if ( V_25 ) {
F_15 ( V_25 ) ;
F_16 ( V_25 ) ;
}
}
return V_27 && ! V_26 ;
}
static int F_17 ( void * V_37 )
{
unsigned int V_22 , V_38 ;
F_18 ( V_39 ) ;
while ( ! F_19 () ) {
V_38 = 0 ;
for ( V_22 = 0 ; V_22 < V_23 ; ++ V_22 )
V_38 += F_8 ( V_22 ) ;
if ( V_38 )
F_20 ( 25 ) ;
F_21 ( V_40 ,
F_22 ( & V_36 ) ) ;
}
return 0 ;
}
static void F_23 ( unsigned long V_41 )
{
int T_2 ;
if ( ! F_22 ( & V_42 ) )
return;
T_2 = F_7 () ;
if ( T_2 >= 0 )
F_2 ( T_2 ) ;
F_24 ( & V_43 , V_44 + V_45 ) ;
}
static void F_25 ( struct V_46 * V_43 )
{
F_26 ( V_43 , F_23 , 0 ) ;
V_43 -> V_47 = V_44 + V_45 ;
F_27 ( V_43 , 0 ) ;
}
static int F_28 ( struct V_48 * V_19 , struct V_24 * V_25 )
{
struct V_7 * V_8 = F_29 ( V_19 , struct V_7 ,
V_19 ) ;
void * V_12 ;
if ( F_30 ( V_19 ) < 0 )
goto V_49;
V_12 = F_31 ( V_15 , V_50 ) ;
if ( ! V_12 )
goto V_51;
F_3 ( & V_8 -> V_11 ) ;
V_8 -> V_12 = V_12 ;
F_6 ( & V_8 -> V_11 ) ;
if ( V_8 != & V_9 [ V_52 ] )
if ( F_32 ( & V_42 ) == 1 )
F_25 ( & V_43 ) ;
return 0 ;
V_51:
F_33 ( V_19 ) ;
V_49:
return - V_53 ;
}
static void F_34 ( struct V_48 * V_19 )
{
struct V_7 * V_8 = F_29 ( V_19 , struct V_7 ,
V_19 ) ;
void * V_12 ;
unsigned int V_27 ;
if ( V_8 != & V_9 [ V_52 ] )
if ( F_35 ( & V_42 ) )
F_36 ( & V_43 ) ;
F_9 ( & V_8 -> V_28 ) ;
V_27 = V_8 -> V_29 ;
F_13 ( & V_8 -> V_28 ) ;
if ( V_27 ) {
F_37 ( & V_54 ) ;
F_38 ( & V_40 ) ;
F_39 ( & V_8 -> V_35 ) ;
}
F_3 ( & V_8 -> V_11 ) ;
V_12 = V_8 -> V_12 ;
V_8 -> V_12 = NULL ;
F_6 ( & V_8 -> V_11 ) ;
F_40 ( V_12 ) ;
F_33 ( V_19 ) ;
}
static int F_41 ( struct V_55 * V_56 , struct V_24 * V_25 )
{
return F_42 ( & V_9 [ V_25 -> V_57 ] . V_19 , V_56 , V_25 ) ;
}
static int F_43 ( struct V_24 * V_25 , struct V_58 * V_59 )
{
return F_44 ( V_25 -> V_19 , V_25 , V_59 ) ;
}
static void F_45 ( struct V_24 * V_25 , struct V_58 * V_59 )
{
return F_46 ( V_25 -> V_19 , V_25 , V_59 ) ;
}
static void F_47 ( struct V_24 * V_25 )
{
int T_2 ;
struct V_7 * V_8 ;
T_2 = V_25 -> V_57 ;
V_8 = & V_9 [ T_2 ] ;
F_9 ( & V_8 -> V_28 ) ;
if ( V_8 -> V_29 ) {
F_12 ( V_8 -> V_29 , & V_36 ) ;
V_8 -> V_29 = 0 ;
V_8 -> V_34 = 0 ;
V_8 -> V_31 = 0 ;
F_11 ( & V_8 -> V_35 ) ;
}
F_13 ( & V_8 -> V_28 ) ;
F_48 ( V_25 -> V_19 ) ;
}
static void F_49 ( unsigned long V_41 )
{
if ( F_22 ( & V_36 ) )
F_38 ( & V_40 ) ;
}
static int F_50 ( struct V_24 * V_25 , const unsigned char * V_60 ,
int V_61 )
{
int T_2 , V_27 , V_62 ;
struct V_7 * V_8 ;
T_2 = V_25 -> V_57 ;
V_8 = & V_9 [ T_2 ] ;
F_9 ( & V_8 -> V_28 ) ;
V_61 = F_10 ( V_61 , ( int ) ( V_30 - V_8 -> V_29 ) ) ;
F_51 ( V_61 , & V_36 ) ;
V_8 -> V_29 += V_61 ;
for ( V_27 = V_61 ; V_27 ; V_27 -= V_62 ) {
V_62 = F_10 ( V_27 , ( int ) ( V_30 - V_8 -> V_34 ) ) ;
memcpy ( V_8 -> V_19 . V_33 + V_8 -> V_34 , V_60 , V_62 ) ;
V_8 -> V_34 += V_62 ;
if ( V_8 -> V_34 >= V_30 )
V_8 -> V_34 -= V_30 ;
V_60 += V_62 ;
}
V_27 = V_8 -> V_29 ;
if ( V_27 )
F_52 ( V_8 -> V_35 ) ;
F_13 ( & V_8 -> V_28 ) ;
if ( V_61 ) {
if ( V_27 == V_30 ) {
F_37 ( & V_54 ) ;
F_38 ( & V_40 ) ;
} else {
F_53 ( & V_54 , V_44 + V_63 ) ;
}
}
return V_61 ;
}
static int F_54 ( struct V_24 * V_25 )
{
struct V_7 * V_8 ;
int T_2 ;
int V_64 ;
T_2 = V_25 -> V_57 ;
V_8 = & V_9 [ T_2 ] ;
F_9 ( & V_8 -> V_28 ) ;
V_64 = V_30 - V_8 -> V_29 ;
F_13 ( & V_8 -> V_28 ) ;
return V_64 ;
}
static int F_55 ( struct V_24 * V_25 )
{
struct V_7 * V_8 ;
int T_2 ;
int V_65 ;
T_2 = V_25 -> V_57 ;
V_8 = & V_9 [ T_2 ] ;
F_9 ( & V_8 -> V_28 ) ;
V_65 = V_8 -> V_29 ;
F_13 ( & V_8 -> V_28 ) ;
return V_65 ;
}
static int T_8 F_56 ( void )
{
int V_66 ;
int V_67 ;
struct V_7 * V_8 ;
if ( ! F_57 () )
return - V_68 ;
V_69 = F_58 ( V_23 ,
V_70 ) ;
if ( F_59 ( V_69 ) )
return F_60 ( V_69 ) ;
V_69 -> V_71 = L_8 ;
V_69 -> V_72 = L_9 ;
V_69 -> V_73 = V_74 ;
V_69 -> V_75 = 0 ;
V_69 -> type = V_76 ;
V_69 -> V_77 = V_78 ;
V_69 -> V_79 = V_80 ;
V_69 -> V_79 . V_81 |= V_82 ;
F_61 ( V_69 , & V_83 ) ;
for ( V_67 = 0 ; V_67 < V_23 ; V_67 ++ ) {
V_8 = & V_9 [ V_67 ] ;
F_62 ( & V_8 -> V_19 ) ;
V_8 -> V_19 . V_84 = & V_85 ;
F_63 ( & V_8 -> V_11 ) ;
F_64 ( & V_8 -> V_28 ) ;
F_65 ( & V_8 -> V_35 ) ;
F_11 ( & V_8 -> V_35 ) ;
}
F_26 ( & V_54 , F_49 , 0 ) ;
F_66 ( & V_40 ) ;
V_86 = F_67 ( F_17 , NULL , L_9 ) ;
if ( F_59 ( V_86 ) ) {
F_68 ( L_10 ) ;
V_66 = F_60 ( V_86 ) ;
goto V_87;
}
F_69 ( V_86 , 0 ) ;
F_70 ( V_86 ) ;
V_66 = F_71 ( V_69 ) ;
if ( V_66 < 0 ) {
F_68 ( L_11 ,
V_66 ) ;
goto V_88;
}
return 0 ;
V_88:
F_72 ( V_86 ) ;
V_87:
for ( V_67 = 0 ; V_67 < V_23 ; V_67 ++ ) {
V_8 = & V_9 [ V_67 ] ;
F_73 ( & V_8 -> V_19 ) ;
}
F_74 ( V_69 ) ;
return V_66 ;
}
static void F_75 ( void )
{
int V_67 ;
struct V_7 * V_8 ;
F_36 ( & V_54 ) ;
F_72 ( V_86 ) ;
F_36 ( & V_43 ) ;
F_76 ( V_69 ) ;
for ( V_67 = 0 ; V_67 < V_23 ; V_67 ++ ) {
V_8 = & V_9 [ V_67 ] ;
F_73 ( & V_8 -> V_19 ) ;
}
F_74 ( V_69 ) ;
}
static void F_77 ( struct V_89 * V_90 , const char * V_91 ,
unsigned int V_27 )
{
int V_92 ;
F_1 ( V_32 , V_52 , V_27 , ( void * ) V_91 , & V_92 ) ;
}
static struct V_55 * F_78 ( struct V_89 * V_93 , int * V_57 )
{
* V_57 = V_93 -> V_57 ;
return V_69 ;
}
