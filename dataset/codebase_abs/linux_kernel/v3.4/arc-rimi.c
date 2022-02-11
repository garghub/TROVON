static int T_1 F_1 ( struct V_1 * V_2 )
{
F_2 (D_NORMAL) F_3 ( V_3 ) ;
F_2 (D_NORMAL) F_3 ( L_1 ) ;
F_2 (D_NORMAL) F_3 ( L_2 ,
V_2 -> V_4 [ 0 ] , V_2 -> V_5 , V_2 -> V_6 ) ;
if ( V_2 -> V_5 <= 0 || V_2 -> V_6 <= 0 ) {
F_2 (D_NORMAL) F_3 ( L_3
L_4 ) ;
return - V_7 ;
}
if ( V_2 -> V_4 [ 0 ] == 0 ) {
F_2 (D_NORMAL) F_3 ( L_5
L_6 ) ;
return - V_7 ;
}
if ( ! F_4 ( V_2 -> V_5 , V_8 , L_7 ) ) {
F_2 (D_NORMAL) F_3 ( L_8 ) ;
return - V_7 ;
}
return F_5 ( V_2 ) ;
}
static int F_6 ( unsigned long V_9 , T_2 V_10 )
{
void T_3 * V_11 ;
int V_12 = - 1 ;
if ( ! F_4 ( V_9 , V_10 , L_7 ) )
return - 1 ;
V_11 = F_7 ( V_9 , V_10 ) ;
if ( V_11 ) {
if ( F_8 ( V_11 ) == V_13 )
V_12 = 1 ;
else
V_12 = 0 ;
F_9 ( V_11 ) ;
}
F_10 ( V_9 , V_10 ) ;
return V_12 ;
}
static int T_1 F_5 ( struct V_1 * V_2 )
{
struct V_14 * V_15 ;
unsigned long V_16 , V_17 , V_18 ;
void T_3 * V_11 ;
int V_19 ;
int V_20 ;
V_11 = F_7 ( V_2 -> V_5 , V_8 ) ;
if ( ! V_11 ) {
F_10 ( V_2 -> V_5 , V_8 ) ;
F_11 ( V_21 , L_9 ) ;
return - V_7 ;
}
if ( F_12 ( V_2 -> V_6 , V_22 , 0 , L_10 , V_2 ) ) {
F_9 ( V_11 ) ;
F_10 ( V_2 -> V_5 , V_8 ) ;
F_11 ( V_21 , L_11 , V_2 -> V_6 ) ;
return - V_7 ;
}
V_18 = V_2 -> V_5 ;
F_13 ( V_13 , V_11 ) ;
F_13 ( V_2 -> V_4 [ 0 ] , V_11 + 1 ) ;
V_19 = V_8 ;
if ( F_8 ( V_11 ) == V_13 &&
F_6 ( V_18 - V_8 , V_8 ) == 0 &&
F_6 ( V_18 - 2 * V_8 , V_8 ) == 1 )
V_19 = 2 * V_8 ;
V_16 = V_18 - V_19 ;
while ( F_6 ( V_16 , V_19 ) == 1 )
V_16 -= V_19 ;
V_16 += V_19 ;
V_17 = V_18 + V_19 ;
while ( F_6 ( V_17 , V_19 ) == 1 )
V_17 += V_19 ;
V_17 -= V_19 ;
V_2 -> V_5 = V_16 ;
V_2 -> V_23 = V_17 + V_8 - 1 ;
V_15 = F_14 ( V_2 ) ;
V_15 -> V_24 = L_12 ;
V_15 -> V_25 . V_26 = V_27 ;
V_15 -> V_25 . V_28 = V_29 ;
V_15 -> V_25 . V_30 = V_31 ;
V_15 -> V_25 . V_32 = V_33 ;
V_15 -> V_25 . V_34 = V_35 ;
V_15 -> V_25 . V_36 = V_37 ;
V_15 -> V_25 . V_38 = V_39 ;
F_9 ( V_11 ) ;
F_10 ( V_18 , V_8 ) ;
if ( ! F_4 ( V_2 -> V_5 ,
V_2 -> V_23 - V_2 -> V_5 + 1 ,
L_7 ) ) {
F_11 ( V_21 , L_8 ) ;
goto V_40;
}
V_15 -> V_5 = F_7 ( V_2 -> V_5 , V_2 -> V_23 - V_2 -> V_5 + 1 ) ;
if ( ! V_15 -> V_5 ) {
F_11 ( V_21 , L_13 ) ;
goto V_41;
}
V_2 -> V_4 [ 0 ] = F_8 ( V_15 -> V_5 + 1 ) ;
F_11 ( V_21 , L_14
L_15 ,
V_2 -> V_4 [ 0 ] ,
V_2 -> V_6 , V_2 -> V_5 ,
( V_2 -> V_23 - V_2 -> V_5 + 1 ) / V_19 , V_19 ) ;
V_20 = F_15 ( V_2 ) ;
if ( V_20 )
goto V_42;
return 0 ;
V_42:
F_9 ( V_15 -> V_5 ) ;
V_41:
F_10 ( V_2 -> V_5 , V_2 -> V_23 - V_2 -> V_5 + 1 ) ;
V_40:
F_16 ( V_2 -> V_6 , V_2 ) ;
return - V_43 ;
}
static int V_33 ( struct V_1 * V_2 , int V_44 )
{
struct V_14 * V_15 = F_14 ( V_2 ) ;
void T_3 * V_45 = V_15 -> V_5 + 0x800 ;
F_11 ( V_46 , L_16 , V_2 -> V_47 , F_17 () ) ;
if ( V_44 ) {
F_13 ( V_13 , V_45 - 0x800 ) ;
return 0 ;
}
F_18 ( V_48 | V_49 ) ;
F_18 ( V_48 | V_50 ) ;
F_18 ( V_51 | V_52 ) ;
return 0 ;
}
static void V_31 ( struct V_1 * V_2 , int V_53 )
{
struct V_14 * V_15 = F_14 ( V_2 ) ;
void T_3 * V_45 = V_15 -> V_5 + 0x800 ;
F_19 ( V_53 ) ;
}
static int V_29 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = F_14 ( V_2 ) ;
void T_3 * V_45 = V_15 -> V_5 + 0x800 ;
return F_17 () ;
}
static void V_27 ( struct V_1 * V_2 , int V_54 )
{
struct V_14 * V_15 = F_14 ( V_2 ) ;
void T_3 * V_45 = V_15 -> V_5 + 0x800 ;
F_18 ( V_54 ) ;
}
static void V_37 ( struct V_1 * V_2 , int V_55 , int V_56 ,
void * V_57 , int V_58 )
{
struct V_14 * V_15 = F_14 ( V_2 ) ;
void T_3 * V_59 = V_15 -> V_5 + 0x800 + V_55 * 512 + V_56 ;
TIME ( L_17 , V_58 , F_20 ( V_59 , V_57 , V_58 ) ) ;
}
static void V_39 ( struct V_1 * V_2 , int V_55 , int V_56 ,
void * V_57 , int V_58 )
{
struct V_14 * V_15 = F_14 ( V_2 ) ;
void T_3 * V_59 = V_15 -> V_5 + 0x800 + V_55 * 512 + V_56 ;
TIME ( L_18 , V_58 , F_21 ( V_57 , V_59 , V_58 ) ) ;
}
static int T_1 F_22 ( void )
{
struct V_1 * V_2 ;
V_2 = F_23 ( V_60 ) ;
if ( ! V_2 )
return - V_61 ;
if ( V_62 && V_62 != 0xff )
V_2 -> V_4 [ 0 ] = V_62 ;
V_2 -> V_5 = V_63 ;
V_2 -> V_6 = V_6 ;
if ( V_2 -> V_6 == 2 )
V_2 -> V_6 = 9 ;
if ( F_1 ( V_2 ) ) {
F_24 ( V_2 ) ;
return - V_43 ;
}
V_64 = V_2 ;
return 0 ;
}
static void T_4 F_25 ( void )
{
struct V_1 * V_2 = V_64 ;
struct V_14 * V_15 = F_14 ( V_2 ) ;
F_26 ( V_2 ) ;
F_9 ( V_15 -> V_5 ) ;
F_10 ( V_2 -> V_5 , V_2 -> V_23 - V_2 -> V_5 + 1 ) ;
F_16 ( V_2 -> V_6 , V_2 ) ;
F_24 ( V_2 ) ;
}
static int T_1 F_27 ( char * V_65 )
{
int V_66 [ 8 ] ;
V_65 = F_28 ( V_65 , 8 , V_66 ) ;
if ( ! V_66 [ 0 ] )
return 1 ;
switch ( V_66 [ 0 ] ) {
default:
F_3 ( L_19 ) ;
case 3 :
V_62 = V_66 [ 3 ] ;
case 2 :
V_6 = V_66 [ 2 ] ;
case 1 :
V_63 = V_66 [ 1 ] ;
}
if ( * V_65 )
snprintf ( V_60 , sizeof( V_60 ) , L_20 , V_65 ) ;
return 1 ;
}
