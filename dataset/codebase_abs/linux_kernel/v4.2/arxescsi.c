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
F_9 ( struct V_30 * V_31 , struct V_1 * V_2 )
{
struct V_11 * V_12 ;
V_12 = (struct V_11 * ) V_2 -> V_13 ;
F_10 ( V_31 , L_2 , V_29 ) ;
F_11 ( & V_12 -> V_12 , V_31 ) ;
F_12 ( & V_12 -> V_12 , V_31 ) ;
F_13 ( & V_12 -> V_12 , V_31 ) ;
return 0 ;
}
static int F_14 ( struct V_32 * V_27 , const struct V_33 * V_34 )
{
struct V_1 * V_2 ;
struct V_11 * V_12 ;
void T_3 * V_9 ;
int V_35 ;
V_35 = F_15 ( V_27 ) ;
if ( V_35 )
goto V_36;
V_9 = F_16 ( V_27 , V_37 , 0 , 0 ) ;
if ( ! V_9 ) {
V_35 = - V_38 ;
goto V_39;
}
V_2 = F_17 ( & V_40 , sizeof( struct V_11 ) ) ;
if ( ! V_2 ) {
V_35 = - V_38 ;
goto V_39;
}
V_12 = (struct V_11 * ) V_2 -> V_13 ;
V_12 -> V_27 = V_27 ;
V_12 -> V_9 = V_9 ;
V_12 -> V_12 . V_15 . V_16 = V_9 + 0x2000 ;
V_12 -> V_12 . V_15 . V_41 = 0 ;
V_12 -> V_12 . V_15 . V_42 = V_43 ;
V_12 -> V_12 . V_15 . V_44 = 5 ;
V_12 -> V_12 . V_45 . V_46 = 24 ;
V_12 -> V_12 . V_45 . V_47 = 255 ;
V_12 -> V_12 . V_45 . V_48 = 200 ;
V_12 -> V_12 . V_45 . V_49 = 0 ;
V_12 -> V_12 . V_45 . V_50 = V_51 | V_52 ;
V_12 -> V_12 . V_45 . V_53 = 0 ;
V_12 -> V_12 . V_45 . V_54 = 0 ;
V_12 -> V_12 . V_45 . V_55 = V_56 ;
V_12 -> V_12 . V_42 . V_57 = F_1 ;
V_12 -> V_12 . V_42 . V_58 = F_3 ;
V_12 -> V_12 . V_42 . V_59 = F_8 ;
V_27 -> V_60 = V_9 ;
V_27 -> V_61 = V_62 ;
V_35 = F_18 ( V_2 ) ;
if ( V_35 )
goto V_63;
V_35 = F_19 ( V_2 , & V_27 -> V_64 ) ;
if ( V_35 == 0 )
goto V_36;
F_20 ( V_2 ) ;
V_63:
F_21 ( V_2 ) ;
V_39:
F_22 ( V_27 ) ;
V_36:
return V_35 ;
}
static void F_23 ( struct V_32 * V_27 )
{
struct V_1 * V_2 = F_24 ( V_27 ) ;
F_25 ( V_27 , NULL ) ;
F_26 ( V_2 ) ;
F_20 ( V_2 ) ;
F_21 ( V_2 ) ;
F_22 ( V_27 ) ;
}
static int T_4 F_27 ( void )
{
return F_28 ( & V_65 ) ;
}
static void T_5 F_29 ( void )
{
F_30 ( & V_65 ) ;
}
