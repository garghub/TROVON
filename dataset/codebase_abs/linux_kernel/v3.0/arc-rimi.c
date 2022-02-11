static int T_1 F_1 ( struct V_1 * V_2 )
{
F_2 (D_NORMAL) F_3 ( V_3 ) ;
F_2 (D_NORMAL) F_3 ( L_1 ) ;
F_4 ( V_4 , L_2 ,
V_2 -> V_5 [ 0 ] , V_2 -> V_6 , V_2 -> V_7 ) ;
if ( V_2 -> V_6 <= 0 || V_2 -> V_7 <= 0 ) {
F_4 ( V_4 , L_3
L_4 ) ;
return - V_8 ;
}
if ( V_2 -> V_5 [ 0 ] == 0 ) {
F_4 ( V_4 , L_5
L_6 ) ;
return - V_8 ;
}
if ( ! F_5 ( V_2 -> V_6 , V_9 , L_7 ) ) {
F_4 ( V_4 , L_8 ) ;
return - V_8 ;
}
return F_6 ( V_2 ) ;
}
static int F_7 ( unsigned long V_10 , T_2 V_11 )
{
void T_3 * V_12 ;
int V_13 = - 1 ;
if ( ! F_5 ( V_10 , V_11 , L_7 ) )
return - 1 ;
V_12 = F_8 ( V_10 , V_11 ) ;
if ( V_12 ) {
if ( F_9 ( V_12 ) == V_14 )
V_13 = 1 ;
else
V_13 = 0 ;
F_10 ( V_12 ) ;
}
F_11 ( V_10 , V_11 ) ;
return V_13 ;
}
static int T_1 F_6 ( struct V_1 * V_2 )
{
struct V_15 * V_16 ;
unsigned long V_17 , V_18 , V_19 ;
void T_3 * V_12 ;
int V_20 ;
int V_21 ;
V_12 = F_8 ( V_2 -> V_6 , V_9 ) ;
if ( ! V_12 ) {
F_11 ( V_2 -> V_6 , V_9 ) ;
F_4 ( V_4 , L_9 ) ;
return - V_8 ;
}
if ( F_12 ( V_2 -> V_7 , V_22 , 0 , L_10 , V_2 ) ) {
F_10 ( V_12 ) ;
F_11 ( V_2 -> V_6 , V_9 ) ;
F_4 ( V_4 , L_11 , V_2 -> V_7 ) ;
return - V_8 ;
}
V_19 = V_2 -> V_6 ;
F_13 ( V_14 , V_12 ) ;
F_13 ( V_2 -> V_5 [ 0 ] , V_12 + 1 ) ;
V_20 = V_9 ;
if ( F_9 ( V_12 ) == V_14 &&
F_7 ( V_19 - V_9 , V_9 ) == 0 &&
F_7 ( V_19 - 2 * V_9 , V_9 ) == 1 )
V_20 = 2 * V_9 ;
V_17 = V_19 - V_20 ;
while ( F_7 ( V_17 , V_20 ) == 1 )
V_17 -= V_20 ;
V_17 += V_20 ;
V_18 = V_19 + V_20 ;
while ( F_7 ( V_18 , V_20 ) == 1 )
V_18 += V_20 ;
V_18 -= V_20 ;
V_2 -> V_6 = V_17 ;
V_2 -> V_23 = V_18 + V_9 - 1 ;
V_16 = F_14 ( V_2 ) ;
V_16 -> V_24 = L_12 ;
V_16 -> V_25 . V_26 = V_27 ;
V_16 -> V_25 . V_28 = V_29 ;
V_16 -> V_25 . V_30 = V_31 ;
V_16 -> V_25 . V_32 = V_33 ;
V_16 -> V_25 . V_34 = V_35 ;
V_16 -> V_25 . V_36 = V_37 ;
V_16 -> V_25 . V_38 = V_39 ;
F_10 ( V_12 ) ;
F_11 ( V_19 , V_9 ) ;
if ( ! F_5 ( V_2 -> V_6 ,
V_2 -> V_23 - V_2 -> V_6 + 1 ,
L_7 ) ) {
F_4 ( V_4 , L_8 ) ;
goto V_40;
}
V_16 -> V_6 = F_8 ( V_2 -> V_6 , V_2 -> V_23 - V_2 -> V_6 + 1 ) ;
if ( ! V_16 -> V_6 ) {
F_4 ( V_4 , L_13 ) ;
goto V_41;
}
V_2 -> V_5 [ 0 ] = F_9 ( V_16 -> V_6 + 1 ) ;
F_4 ( V_4 , L_14
L_15 ,
V_2 -> V_5 [ 0 ] ,
V_2 -> V_7 , V_2 -> V_6 ,
( V_2 -> V_23 - V_2 -> V_6 + 1 ) / V_20 , V_20 ) ;
V_21 = F_15 ( V_2 ) ;
if ( V_21 )
goto V_42;
return 0 ;
V_42:
F_10 ( V_16 -> V_6 ) ;
V_41:
F_11 ( V_2 -> V_6 , V_2 -> V_23 - V_2 -> V_6 + 1 ) ;
V_40:
F_16 ( V_2 -> V_7 , V_2 ) ;
return - V_43 ;
}
static int V_33 ( struct V_1 * V_2 , int V_44 )
{
struct V_15 * V_16 = F_14 ( V_2 ) ;
void T_3 * V_45 = V_16 -> V_6 + 0x800 ;
F_4 ( V_46 , L_16 , V_2 -> V_47 , F_17 () ) ;
if ( V_44 ) {
F_13 ( V_14 , V_45 - 0x800 ) ;
return 0 ;
}
F_18 ( V_48 | V_49 ) ;
F_18 ( V_48 | V_50 ) ;
F_18 ( V_51 | V_52 ) ;
return 0 ;
}
static void V_31 ( struct V_1 * V_2 , int V_53 )
{
struct V_15 * V_16 = F_14 ( V_2 ) ;
void T_3 * V_45 = V_16 -> V_6 + 0x800 ;
F_19 ( V_53 ) ;
}
static int V_29 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = F_14 ( V_2 ) ;
void T_3 * V_45 = V_16 -> V_6 + 0x800 ;
return F_17 () ;
}
static void V_27 ( struct V_1 * V_2 , int V_54 )
{
struct V_15 * V_16 = F_14 ( V_2 ) ;
void T_3 * V_45 = V_16 -> V_6 + 0x800 ;
F_18 ( V_54 ) ;
}
static void V_37 ( struct V_1 * V_2 , int V_55 , int V_56 ,
void * V_57 , int V_58 )
{
struct V_15 * V_16 = F_14 ( V_2 ) ;
void T_3 * V_59 = V_16 -> V_6 + 0x800 + V_55 * 512 + V_56 ;
TIME ( L_17 , V_58 , F_20 ( V_59 , V_57 , V_58 ) ) ;
}
static void V_39 ( struct V_1 * V_2 , int V_55 , int V_56 ,
void * V_57 , int V_58 )
{
struct V_15 * V_16 = F_14 ( V_2 ) ;
void T_3 * V_59 = V_16 -> V_6 + 0x800 + V_55 * 512 + V_56 ;
TIME ( L_18 , V_58 , F_21 ( V_57 , V_59 , V_58 ) ) ;
}
static int T_1 F_22 ( void )
{
struct V_1 * V_2 ;
V_2 = F_23 ( V_60 ) ;
if ( ! V_2 )
return - V_61 ;
if ( V_62 && V_62 != 0xff )
V_2 -> V_5 [ 0 ] = V_62 ;
V_2 -> V_6 = V_63 ;
V_2 -> V_7 = V_7 ;
if ( V_2 -> V_7 == 2 )
V_2 -> V_7 = 9 ;
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
struct V_15 * V_16 = F_14 ( V_2 ) ;
F_26 ( V_2 ) ;
F_10 ( V_16 -> V_6 ) ;
F_11 ( V_2 -> V_6 , V_2 -> V_23 - V_2 -> V_6 + 1 ) ;
F_16 ( V_2 -> V_7 , V_2 ) ;
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
V_7 = V_66 [ 2 ] ;
case 1 :
V_63 = V_66 [ 1 ] ;
}
if ( * V_65 )
snprintf ( V_60 , sizeof( V_60 ) , L_20 , V_65 ) ;
return 1 ;
}
