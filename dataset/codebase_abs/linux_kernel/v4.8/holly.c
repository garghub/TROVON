int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
if ( V_3 == 0 && F_2 ( V_4 ) == 0 )
return V_5 ;
else
return V_6 ;
}
static void F_3 ( void )
{
T_2 V_7 , V_8 ;
int V_9 ;
F_4 ( V_10 L_1 ) ;
V_8 = 0x900 ;
for ( V_9 = 0 ; V_9 < 31 ; V_9 ++ ) {
F_5 ( V_11 + V_8 , 0x00000201 ) ;
V_8 += 4 ;
F_5 ( V_11 + V_8 , 0x0 ) ;
V_8 += 4 ;
}
F_5 ( V_11 + V_8 , 0x00000241 ) ;
V_8 += 4 ;
F_5 ( V_11 + V_8 , 0x0 ) ;
F_5 ( V_12 , 0x0 ) ;
F_5 ( V_13 , 0x1 ) ;
F_5 ( V_14 , 0x0 ) ;
F_5 ( V_15 , 0x7c000000 | 0x01 ) ;
F_5 ( V_16 , 0x0 ) ;
F_5 ( V_17 , 0x0 ) ;
F_5 ( V_18 , 0x0 ) ;
F_5 ( V_19 , 0x0 ) ;
F_5 ( V_20 , 0xc0000000 ) ;
V_8 = 0x500 ;
V_7 = 0x00000002 ;
for ( V_9 = 0 ; V_9 < 32 ; V_9 ++ ) {
F_5 ( V_21 + V_8 , V_7 ) ;
V_8 += 4 ;
F_5 ( V_21 + V_8 , 0x40000000 ) ;
V_8 += 4 ;
V_7 += 0x02000000 ;
}
F_5 ( V_22 , 0x00007900 ) ;
F_5 ( V_23 , 0x0 ) ;
F_5 ( V_24 , 0x0 ) ;
}
static void T_3 F_6 ( void )
{
struct V_25 * V_26 ;
if ( V_27 . V_28 )
V_27 . V_28 ( L_2 , 0 ) ;
V_29 = F_7 () ;
F_3 () ;
V_26 = F_8 ( NULL , L_3 ) ;
if ( V_26 )
F_9 ( V_26 , V_30 , 1 ) ;
V_27 . V_31 = F_1 ;
if ( V_27 . V_28 )
V_27 . V_28 ( L_4 , 0x100 ) ;
F_4 ( V_10 L_5 ) ;
}
static void T_3 F_10 ( void )
{
struct V_32 * V_32 ;
#ifdef F_11
unsigned int V_33 ;
struct V_25 * V_34 ;
struct V_25 * V_35 = NULL ;
#endif
V_32 = F_12 ( NULL , 0 , V_36 |
V_37 | V_38 | V_39 ,
24 , 0 ,
L_6 ) ;
F_13 ( V_32 == NULL ) ;
F_14 ( V_32 , 0 , V_32 -> V_40 + 0x100 ) ;
F_15 ( V_32 ) ;
#ifdef F_11
V_34 = F_8 ( NULL , L_3 ) ;
if ( V_34 == NULL ) {
F_4 ( V_41 L_7 , V_42 ) ;
return;
}
V_35 = F_8 ( NULL , L_8 ) ;
if ( V_35 == NULL ) {
F_4 ( V_41 L_9 , V_42 ) ;
return;
}
V_33 = F_16 ( V_34 , 0 ) ;
F_17 ( L_10 , V_42 , ( T_2 ) V_33 ) ;
F_18 ( V_35 ) ;
F_19 ( V_33 , V_32 ) ;
F_20 ( V_33 , V_43 ) ;
#endif
F_5 ( V_44 + 0x30c , 0 ) ;
}
void F_21 ( struct V_45 * V_46 )
{
F_22 ( V_46 , L_11 ) ;
F_22 ( V_46 , L_12 ) ;
}
void T_4 F_23 ( char * V_47 )
{
T_5 T_6 * V_48 = NULL ;
unsigned long V_49 ;
struct V_25 * V_50 = NULL ;
const void * V_51 ;
int V_52 ;
T_7 V_53 = 0xc0000000 ;
F_24 () ;
V_50 = F_8 ( NULL , L_13 ) ;
if ( V_50 ) {
V_51 = F_25 ( V_50 , L_14 , & V_52 ) ;
V_53 = F_26 ( V_50 , V_51 ) ;
}
V_53 += ( V_11 + 0x414 ) ;
V_48 = F_27 ( V_53 , 0x4 ) ;
V_49 = F_28 ( V_48 ) ;
V_49 |= 2 ;
F_29 ( V_49 , V_48 ) ;
F_30 () ;
F_31 ( V_54 , 0xfff00100 ) ;
F_31 ( V_55 , V_56 ) ;
__asm__ __volatile__("rfi" : : : "memory");
for (; ; ) ;
}
void F_32 ( void )
{
F_24 () ;
for (; ; ) ;
}
void F_33 ( void )
{
F_32 () ;
}
static int T_3 F_34 ( void )
{
if ( ! F_35 ( L_15 ) )
return 0 ;
return 1 ;
}
static int F_36 ( struct V_57 * V_58 )
{
const struct V_59 * V_60 ;
if ( ( V_60 = F_37 ( V_58 -> V_61 ) ) != NULL ) {
F_38 () ;
V_58 -> V_62 |= V_63 ;
V_58 -> V_61 = V_60 -> V_64 ;
return 1 ;
}
return 0 ;
}
