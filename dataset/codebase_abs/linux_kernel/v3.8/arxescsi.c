static T_1
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_2 V_5 , T_1 V_6 )
{
return V_7 ;
}
static void F_2 ( unsigned char * V_8 , void T_3 * V_9 )
{
__asm__ __volatile__(
" stmdb sp!, {r0-r12}\n"
" mov r3, %0\n"
" mov r1, %1\n"
" add r2, r1, #512\n"
" mov r4, #256\n"
".loop_1: ldmia r3!, {r6, r8, r10, r12}\n"
" mov r5, r6, lsl #16\n"
" mov r7, r8, lsl #16\n"
".loop_2: ldrb r0, [r1, #1536]\n"
" tst r0, #1\n"
" beq .loop_2\n"
" stmia r2, {r5-r8}\n\t"
" mov r9, r10, lsl #16\n"
" mov r11, r12, lsl #16\n"
".loop_3: ldrb r0, [r1, #1536]\n"
" tst r0, #1\n"
" beq .loop_3\n"
" stmia r2, {r9-r12}\n"
" subs r4, r4, #16\n"
" bne .loop_1\n"
" ldmia sp!, {r0-r12}\n"
:
: "r" (addr), "r" (base));
}
static void
F_3 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_2 V_5 , int V_10 )
{
struct V_11 * V_12 = (struct V_11 * ) V_2 -> V_13 ;
unsigned int V_14 , error = 0 ;
void T_3 * V_9 = V_12 -> V_12 . V_15 . V_16 ;
unsigned char * V_8 ;
V_14 = V_4 -> V_17 ;
V_8 = V_4 -> V_18 ;
if ( V_5 == V_19 ) {
unsigned int V_20 ;
while ( V_14 > 256 ) {
if ( F_4 ( V_9 + 0x80 ) & V_21 ) {
error = 1 ;
break;
}
F_2 ( V_8 , V_9 ) ;
V_8 += 256 ;
V_14 -= 256 ;
}
if ( ! error )
while ( V_14 > 0 ) {
if ( F_4 ( V_9 + 0x80 ) & V_21 )
break;
if ( ! ( F_4 ( V_9 + V_22 ) & V_23 ) )
continue;
V_20 = * V_8 | * ( V_8 + 1 ) << 8 ;
F_5 ( V_20 , V_9 + V_24 ) ;
if ( V_14 > 1 ) {
V_8 += 2 ;
V_14 -= 2 ;
} else {
V_8 += 1 ;
V_14 -= 1 ;
}
}
}
else {
if ( V_10 && ( V_10 & 255 ) ) {
while ( V_14 >= 256 ) {
if ( F_4 ( V_9 + 0x80 ) & V_21 ) {
error = 1 ;
break;
}
if ( ! ( F_4 ( V_9 + V_22 ) & V_23 ) )
continue;
F_6 ( V_9 + V_24 , V_8 , 256 >> 1 ) ;
V_8 += 256 ;
V_14 -= 256 ;
}
}
if ( ! ( error ) )
while ( V_14 > 0 ) {
unsigned long V_20 ;
if ( F_4 ( V_9 + 0x80 ) & V_21 )
break;
if ( ! ( F_4 ( V_9 + V_22 ) & V_23 ) )
continue;
V_20 = F_7 ( V_9 + V_24 ) ;
* V_8 ++ = V_20 ;
if ( -- V_14 > 0 ) {
* V_8 ++ = V_20 >> 8 ;
V_14 -- ;
}
}
}
}
static void F_8 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
}
static const char * V_11 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = (struct V_11 * ) V_2 -> V_13 ;
static char string [ 150 ] ;
sprintf ( string , L_1 ,
V_2 -> V_25 -> V_26 , V_12 -> V_12 . V_15 . type , V_12 -> V_27 -> V_28 ,
V_29 ) ;
return string ;
}
static int
F_9 ( struct V_1 * V_2 , char * V_30 , char * * V_31 , T_4 V_32 , int V_14 ,
int V_33 )
{
struct V_11 * V_12 ;
char * V_34 = V_30 ;
int V_35 ;
V_12 = (struct V_11 * ) V_2 -> V_13 ;
if ( V_33 == 1 )
return - V_36 ;
V_34 += sprintf ( V_34 , L_2 , V_29 ) ;
V_34 += F_10 ( & V_12 -> V_12 , V_34 ) ;
V_34 += F_11 ( & V_12 -> V_12 , V_34 ) ;
V_34 += F_12 ( & V_12 -> V_12 , V_34 ) ;
* V_31 = V_30 + V_32 ;
V_35 = V_34 - V_30 - V_32 ;
if ( V_35 > V_14 )
V_35 = V_14 ;
return V_35 ;
}
static int F_13 ( struct V_37 * V_27 , const struct V_38 * V_39 )
{
struct V_1 * V_2 ;
struct V_11 * V_12 ;
void T_3 * V_9 ;
int V_40 ;
V_40 = F_14 ( V_27 ) ;
if ( V_40 )
goto V_41;
V_9 = F_15 ( V_27 , V_42 , 0 , 0 ) ;
if ( ! V_9 ) {
V_40 = - V_43 ;
goto V_44;
}
V_2 = F_16 ( & V_45 , sizeof( struct V_11 ) ) ;
if ( ! V_2 ) {
V_40 = - V_43 ;
goto V_44;
}
V_12 = (struct V_11 * ) V_2 -> V_13 ;
V_12 -> V_27 = V_27 ;
V_12 -> V_9 = V_9 ;
V_12 -> V_12 . V_15 . V_16 = V_9 + 0x2000 ;
V_12 -> V_12 . V_15 . V_46 = 0 ;
V_12 -> V_12 . V_15 . V_47 = V_48 ;
V_12 -> V_12 . V_15 . V_49 = 5 ;
V_12 -> V_12 . V_50 . V_51 = 24 ;
V_12 -> V_12 . V_50 . V_52 = 255 ;
V_12 -> V_12 . V_50 . V_53 = 200 ;
V_12 -> V_12 . V_50 . V_54 = 0 ;
V_12 -> V_12 . V_50 . V_55 = V_56 | V_57 ;
V_12 -> V_12 . V_50 . V_58 = 0 ;
V_12 -> V_12 . V_50 . V_59 = 0 ;
V_12 -> V_12 . V_50 . V_60 = V_61 ;
V_12 -> V_12 . V_47 . V_62 = F_1 ;
V_12 -> V_12 . V_47 . V_63 = F_3 ;
V_12 -> V_12 . V_47 . V_64 = F_8 ;
V_27 -> V_65 = V_9 ;
V_27 -> V_66 = V_67 ;
V_40 = F_17 ( V_2 ) ;
if ( V_40 )
goto V_68;
V_40 = F_18 ( V_2 , & V_27 -> V_69 ) ;
if ( V_40 == 0 )
goto V_41;
F_19 ( V_2 ) ;
V_68:
F_20 ( V_2 ) ;
V_44:
F_21 ( V_27 ) ;
V_41:
return V_40 ;
}
static void F_22 ( struct V_37 * V_27 )
{
struct V_1 * V_2 = F_23 ( V_27 ) ;
F_24 ( V_27 , NULL ) ;
F_25 ( V_2 ) ;
F_19 ( V_2 ) ;
F_20 ( V_2 ) ;
F_21 ( V_27 ) ;
}
static int T_5 F_26 ( void )
{
return F_27 ( & V_70 ) ;
}
static void T_6 F_28 ( void )
{
F_29 ( & V_70 ) ;
}
