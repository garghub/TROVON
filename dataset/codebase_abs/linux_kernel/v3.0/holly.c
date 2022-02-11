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
T_4 V_33 = 0 ;
struct V_25 * V_34 ;
#ifdef F_11
unsigned int V_35 ;
struct V_25 * V_36 ;
struct V_25 * V_37 = NULL ;
#endif
V_34 = F_8 ( NULL , L_6 ) ;
if ( V_34 ) {
unsigned int V_38 ;
const void * V_39 = F_12 ( V_34 , L_7 , & V_38 ) ;
V_33 = F_13 ( V_34 , V_39 ) ;
}
if ( V_33 == 0 ) {
F_4 ( V_40 L_8 , V_41 ) ;
return;
}
F_14 ( L_9 , V_41 , ( T_2 ) V_33 ) ;
V_32 = F_15 ( V_34 , V_33 ,
V_42 | V_43 | V_44 |
V_45 | V_46 | V_47 ,
24 ,
V_48 - 4 ,
L_10 ) ;
F_16 ( V_32 == NULL ) ;
F_17 ( V_32 , 0 , V_33 + 0x100 ) ;
F_18 ( V_32 ) ;
#ifdef F_11
V_36 = F_8 ( NULL , L_3 ) ;
if ( V_36 == NULL ) {
F_4 ( V_40 L_11 , V_41 ) ;
return;
}
V_37 = F_8 ( NULL , L_12 ) ;
if ( V_37 == NULL ) {
F_4 ( V_40 L_13 , V_41 ) ;
return;
}
V_35 = F_19 ( V_36 , 0 ) ;
F_14 ( L_14 , V_41 , ( T_2 ) V_35 ) ;
F_20 ( V_37 ) ;
F_21 ( V_35 , V_32 ) ;
F_22 ( V_35 , V_49 ) ;
#endif
F_5 ( V_50 + 0x30c , 0 ) ;
F_23 ( V_34 ) ;
}
void F_24 ( struct V_51 * V_52 )
{
F_25 ( V_52 , L_15 ) ;
F_25 ( V_52 , L_16 ) ;
}
void F_26 ( char * V_53 )
{
T_5 T_6 * V_54 = NULL ;
unsigned long V_55 ;
struct V_25 * V_56 = NULL ;
const void * V_39 ;
int V_38 ;
T_4 V_57 = 0xc0000000 ;
F_27 () ;
V_56 = F_8 ( NULL , L_17 ) ;
if ( V_56 ) {
V_39 = F_12 ( V_56 , L_7 , & V_38 ) ;
V_57 = F_13 ( V_56 , V_39 ) ;
}
V_57 += ( V_11 + 0x414 ) ;
V_54 = F_28 ( V_57 , 0x4 ) ;
V_55 = F_29 ( V_54 ) ;
V_55 |= 2 ;
F_30 ( V_55 , V_54 ) ;
F_31 () ;
F_32 ( V_58 , 0xfff00100 ) ;
F_32 ( V_59 , V_60 ) ;
__asm__ __volatile__("rfi" : : : "memory");
for (; ; ) ;
}
void F_33 ( void )
{
F_27 () ;
for (; ; ) ;
}
void F_34 ( void )
{
F_33 () ;
}
static int T_3 F_35 ( void )
{
unsigned long V_61 = F_36 () ;
if ( ! F_37 ( V_61 , L_18 ) )
return 0 ;
return 1 ;
}
static int F_38 ( struct V_62 * V_63 )
{
const struct V_64 * V_65 ;
if ( ( V_65 = F_39 ( V_63 -> V_66 ) ) != NULL ) {
F_40 () ;
V_63 -> V_67 |= V_68 ;
V_63 -> V_66 = V_65 -> V_69 ;
return 1 ;
}
return 0 ;
}
