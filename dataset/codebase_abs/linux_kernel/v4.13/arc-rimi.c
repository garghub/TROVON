static int T_1 F_1 ( struct V_1 * V_2 )
{
if ( F_2 ( V_3 ) ) {
F_3 ( L_1 , L_2 ) ;
F_3 ( L_3 ) ;
F_3 ( L_4 ,
V_2 -> V_4 [ 0 ] , V_2 -> V_5 , V_2 -> V_6 ) ;
}
if ( V_2 -> V_5 <= 0 || V_2 -> V_6 <= 0 ) {
if ( F_2 ( V_3 ) )
F_4 ( L_5 ) ;
return - V_7 ;
}
if ( V_2 -> V_4 [ 0 ] == 0 ) {
if ( F_2 ( V_3 ) )
F_4 ( L_6 ) ;
return - V_7 ;
}
if ( ! F_5 ( V_2 -> V_5 , V_8 , L_7 ) ) {
if ( F_2 ( V_3 ) )
F_6 ( L_8 ) ;
return - V_7 ;
}
return F_7 ( V_2 ) ;
}
static int F_8 ( unsigned long V_9 , T_2 V_10 )
{
void T_3 * V_11 ;
int V_12 = - 1 ;
if ( ! F_5 ( V_9 , V_10 , L_7 ) )
return - 1 ;
V_11 = F_9 ( V_9 , V_10 ) ;
if ( V_11 ) {
if ( F_10 ( V_11 , V_13 ) == V_14 )
V_12 = 1 ;
else
V_12 = 0 ;
F_11 ( V_11 ) ;
}
F_12 ( V_9 , V_10 ) ;
return V_12 ;
}
static int T_1 F_7 ( struct V_1 * V_2 )
{
struct V_15 * V_16 ;
unsigned long V_17 , V_18 , V_19 ;
void T_3 * V_11 ;
int V_20 ;
int V_21 ;
V_11 = F_9 ( V_2 -> V_5 , V_8 ) ;
if ( ! V_11 ) {
F_12 ( V_2 -> V_5 , V_8 ) ;
F_13 ( V_3 , V_2 , L_9 ) ;
return - V_7 ;
}
if ( F_14 ( V_2 -> V_6 , V_22 , 0 , L_10 , V_2 ) ) {
F_11 ( V_11 ) ;
F_12 ( V_2 -> V_5 , V_8 ) ;
F_13 ( V_3 , V_2 , L_11 , V_2 -> V_6 ) ;
return - V_7 ;
}
V_19 = V_2 -> V_5 ;
F_15 ( V_14 , V_11 , V_23 ) ;
F_15 ( V_14 , V_11 , V_24 ) ;
V_20 = V_8 ;
if ( F_10 ( V_11 , V_13 ) == V_14 &&
F_8 ( V_19 - V_8 , V_8 ) == 0 &&
F_8 ( V_19 - 2 * V_8 , V_8 ) == 1 )
V_20 = 2 * V_8 ;
V_17 = V_19 - V_20 ;
while ( F_8 ( V_17 , V_20 ) == 1 )
V_17 -= V_20 ;
V_17 += V_20 ;
V_18 = V_19 + V_20 ;
while ( F_8 ( V_18 , V_20 ) == 1 )
V_18 += V_20 ;
V_18 -= V_20 ;
V_2 -> V_5 = V_17 ;
V_2 -> V_25 = V_18 + V_8 - 1 ;
V_16 = F_16 ( V_2 ) ;
V_16 -> V_26 = L_12 ;
V_16 -> V_27 . V_28 = V_29 ;
V_16 -> V_27 . V_30 = V_31 ;
V_16 -> V_27 . V_32 = V_33 ;
V_16 -> V_27 . V_34 = V_35 ;
V_16 -> V_27 . V_36 = V_37 ;
V_16 -> V_27 . V_38 = V_39 ;
V_16 -> V_27 . V_40 = V_41 ;
F_11 ( V_11 ) ;
F_12 ( V_19 , V_8 ) ;
if ( ! F_5 ( V_2 -> V_5 ,
V_2 -> V_25 - V_2 -> V_5 + 1 ,
L_7 ) ) {
F_13 ( V_3 , V_2 , L_8 ) ;
goto V_42;
}
V_16 -> V_5 = F_9 ( V_2 -> V_5 ,
V_2 -> V_25 - V_2 -> V_5 + 1 ) ;
if ( ! V_16 -> V_5 ) {
F_13 ( V_3 , V_2 , L_13 ) ;
goto V_43;
}
V_2 -> V_4 [ 0 ] = F_10 ( V_16 -> V_5 , V_44 ) ;
F_13 ( V_3 , V_2 , L_14 ,
V_2 -> V_4 [ 0 ] ,
V_2 -> V_6 , V_2 -> V_5 ,
( V_2 -> V_25 - V_2 -> V_5 + 1 ) / V_20 ,
V_20 ) ;
V_21 = F_17 ( V_2 ) ;
if ( V_21 )
goto V_45;
return 0 ;
V_45:
F_11 ( V_16 -> V_5 ) ;
V_43:
F_12 ( V_2 -> V_5 , V_2 -> V_25 - V_2 -> V_5 + 1 ) ;
V_42:
F_18 ( V_2 -> V_6 , V_2 ) ;
return - V_46 ;
}
static int V_35 ( struct V_1 * V_2 , int V_47 )
{
struct V_15 * V_16 = F_16 ( V_2 ) ;
void T_3 * V_48 = V_16 -> V_5 + 0x800 ;
F_13 ( V_49 , V_2 , L_15 ,
V_2 -> V_50 , F_10 ( V_48 , V_13 ) ) ;
if ( V_47 ) {
F_15 ( V_14 , V_48 , - 0x800 ) ;
return 0 ;
}
F_15 ( V_51 | V_52 , V_48 , V_24 ) ;
F_15 ( V_51 | V_53 , V_48 , V_24 ) ;
F_15 ( V_54 | V_55 , V_48 , V_24 ) ;
return 0 ;
}
static void V_33 ( struct V_1 * V_2 , int V_56 )
{
struct V_15 * V_16 = F_16 ( V_2 ) ;
void T_3 * V_48 = V_16 -> V_5 + 0x800 ;
F_15 ( V_56 , V_48 , V_23 ) ;
}
static int V_31 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = F_16 ( V_2 ) ;
void T_3 * V_48 = V_16 -> V_5 + 0x800 ;
return F_10 ( V_48 , V_13 ) ;
}
static void V_29 ( struct V_1 * V_2 , int V_57 )
{
struct V_15 * V_16 = F_16 ( V_2 ) ;
void T_3 * V_48 = V_16 -> V_5 + 0x800 ;
F_15 ( V_57 , V_48 , V_24 ) ;
}
static void V_39 ( struct V_1 * V_2 , int V_58 , int V_59 ,
void * V_60 , int V_61 )
{
struct V_15 * V_16 = F_16 ( V_2 ) ;
void T_3 * V_62 = V_16 -> V_5 + 0x800 + V_58 * 512 + V_59 ;
TIME ( V_2 , L_16 , V_61 , F_19 ( V_62 , V_60 , V_61 ) ) ;
}
static void V_41 ( struct V_1 * V_2 , int V_58 ,
int V_59 , void * V_60 , int V_61 )
{
struct V_15 * V_16 = F_16 ( V_2 ) ;
void T_3 * V_62 = V_16 -> V_5 + 0x800 + V_58 * 512 + V_59 ;
TIME ( V_2 , L_17 , V_61 , F_20 ( V_60 , V_62 , V_61 ) ) ;
}
static int T_1 F_21 ( void )
{
struct V_1 * V_2 ;
V_2 = F_22 ( V_63 ) ;
if ( ! V_2 )
return - V_64 ;
if ( V_65 && V_65 != 0xff )
V_2 -> V_4 [ 0 ] = V_65 ;
V_2 -> V_5 = V_66 ;
V_2 -> V_6 = V_6 ;
if ( V_2 -> V_6 == 2 )
V_2 -> V_6 = 9 ;
if ( F_1 ( V_2 ) ) {
F_23 ( V_2 ) ;
return - V_46 ;
}
V_67 = V_2 ;
return 0 ;
}
static void T_4 F_24 ( void )
{
struct V_1 * V_2 = V_67 ;
struct V_15 * V_16 = F_16 ( V_2 ) ;
F_25 ( V_2 ) ;
F_11 ( V_16 -> V_5 ) ;
F_12 ( V_2 -> V_5 , V_2 -> V_25 - V_2 -> V_5 + 1 ) ;
F_18 ( V_2 -> V_6 , V_2 ) ;
F_23 ( V_2 ) ;
}
static int T_1 F_26 ( char * V_68 )
{
int V_69 [ 8 ] ;
V_68 = F_27 ( V_68 , 8 , V_69 ) ;
if ( ! V_69 [ 0 ] )
return 1 ;
switch ( V_69 [ 0 ] ) {
default:
F_4 ( L_18 ) ;
case 3 :
V_65 = V_69 [ 3 ] ;
case 2 :
V_6 = V_69 [ 2 ] ;
case 1 :
V_66 = V_69 [ 1 ] ;
}
if ( * V_68 )
snprintf ( V_63 , sizeof( V_63 ) , L_19 , V_68 ) ;
return 1 ;
}
