static int F_1 ( T_1 * V_1 , T_1 V_2 )
{
int V_3 ;
V_3 = F_2 ( V_4 , V_1 , ( V_5 [ V_2 ] ) ) ;
if ( V_3 < 0 )
F_3 ( L_1
L_2 , V_2 , V_3 ) ;
return V_3 ;
}
static int F_4 ( T_1 V_1 , T_1 V_2 )
{
int V_3 ;
V_3 = F_5 ( V_4 , V_1 , ( V_5 [ V_2 ] ) ) ;
if ( V_3 < 0 )
F_3 ( L_3
L_2 , V_2 , V_3 ) ;
return V_3 ;
}
static int F_6 ( unsigned char V_6 )
{
unsigned char V_7 ;
int V_3 ;
if ( V_8 & V_6 )
return 0 ;
V_7 = V_8 | V_6 ;
V_7 &= ~ V_9 ;
V_3 = F_4 ( V_7 , V_10 ) ;
if ( V_3 == 0 )
V_8 = V_7 ;
return V_3 ;
}
static int F_7 ( unsigned char V_6 )
{
unsigned char V_7 ;
int V_3 ;
if ( ! ( V_8 & V_6 ) )
return 0 ;
V_7 = V_8 & ~ V_6 ;
V_3 = F_4 ( V_7 , V_10 ) ;
if ( V_3 == 0 )
V_8 = V_7 ;
return V_3 ;
}
static int F_8 ( struct V_11 * V_12 , unsigned V_13 )
{
int V_3 ;
if ( V_13 )
V_3 = F_6 ( V_14 ) ;
else
V_3 = F_7 ( V_14 ) ;
return V_3 ;
}
static int F_9 ( struct V_11 * V_12 , struct V_15 * V_16 )
{
unsigned char V_17 [ V_18 ] ;
int V_3 ;
T_1 V_19 ;
T_1 V_20 ;
V_3 = F_1 ( & V_19 , V_21 ) ;
if ( V_3 < 0 ) {
F_10 ( V_12 , L_4 , V_22 , V_3 ) ;
return V_3 ;
}
if ( F_11 () ) {
if ( V_19 & V_23 ) {
V_19 &= ~ V_23 ;
V_3 = F_4 ( V_19 , V_21 ) ;
if ( V_3 < 0 ) {
F_10 ( V_12 , L_5 ,
V_22 , V_3 ) ;
return V_3 ;
}
}
}
V_20 = V_19 | V_23 ;
if ( F_11 () )
V_20 |= V_24 ;
V_3 = F_4 ( V_20 , V_21 ) ;
if ( V_3 < 0 ) {
F_10 ( V_12 , L_6 , V_22 , V_3 ) ;
return V_3 ;
}
V_3 = F_12 ( V_4 , V_17 ,
( V_5 [ V_25 ] ) , V_18 ) ;
if ( V_3 < 0 ) {
F_10 ( V_12 , L_7 , V_22 , V_3 ) ;
return V_3 ;
}
if ( F_11 () ) {
V_3 = F_4 ( V_19 , V_21 ) ;
if ( V_3 < 0 ) {
F_10 ( V_12 , L_8 ,
V_22 , V_3 ) ;
return V_3 ;
}
}
V_16 -> V_26 = F_13 ( V_17 [ 0 ] ) ;
V_16 -> V_27 = F_13 ( V_17 [ 1 ] ) ;
V_16 -> V_28 = F_13 ( V_17 [ 2 ] ) ;
V_16 -> V_29 = F_13 ( V_17 [ 3 ] ) ;
V_16 -> V_30 = F_13 ( V_17 [ 4 ] ) - 1 ;
V_16 -> V_31 = F_13 ( V_17 [ 5 ] ) + 100 ;
return V_3 ;
}
static int F_14 ( struct V_11 * V_12 , struct V_15 * V_16 )
{
unsigned char V_19 ;
unsigned char V_17 [ V_18 ] ;
int V_3 ;
V_17 [ 0 ] = F_15 ( V_16 -> V_26 ) ;
V_17 [ 1 ] = F_15 ( V_16 -> V_27 ) ;
V_17 [ 2 ] = F_15 ( V_16 -> V_28 ) ;
V_17 [ 3 ] = F_15 ( V_16 -> V_29 ) ;
V_17 [ 4 ] = F_15 ( V_16 -> V_30 + 1 ) ;
V_17 [ 5 ] = F_15 ( V_16 -> V_31 - 100 ) ;
V_3 = F_1 ( & V_19 , V_21 ) ;
if ( V_3 < 0 )
goto V_32;
V_19 &= ~ V_33 ;
V_3 = F_4 ( V_19 , V_21 ) ;
if ( V_3 < 0 )
goto V_32;
V_3 = F_16 ( V_4 , V_17 ,
( V_5 [ V_25 ] ) , V_18 ) ;
if ( V_3 < 0 ) {
F_10 ( V_12 , L_9 , V_3 ) ;
goto V_32;
}
V_19 |= V_33 ;
V_3 = F_4 ( V_19 , V_21 ) ;
V_32:
return V_3 ;
}
static int F_17 ( struct V_11 * V_12 , struct V_34 * V_35 )
{
unsigned char V_17 [ V_18 ] ;
int V_3 ;
V_3 = F_12 ( V_4 , V_17 ,
( V_5 [ V_36 ] ) , V_18 ) ;
if ( V_3 < 0 ) {
F_10 ( V_12 , L_10 , V_3 ) ;
return V_3 ;
}
V_35 -> time . V_26 = F_13 ( V_17 [ 0 ] ) ;
V_35 -> time . V_27 = F_13 ( V_17 [ 1 ] ) ;
V_35 -> time . V_28 = F_13 ( V_17 [ 2 ] ) ;
V_35 -> time . V_29 = F_13 ( V_17 [ 3 ] ) ;
V_35 -> time . V_30 = F_13 ( V_17 [ 4 ] ) - 1 ;
V_35 -> time . V_31 = F_13 ( V_17 [ 5 ] ) + 100 ;
if ( V_8 & V_14 )
V_35 -> V_13 = 1 ;
return V_3 ;
}
static int F_18 ( struct V_11 * V_12 , struct V_34 * V_35 )
{
unsigned char V_37 [ V_18 ] ;
int V_3 ;
V_3 = F_8 ( V_12 , 0 ) ;
if ( V_3 )
goto V_32;
V_37 [ 0 ] = F_15 ( V_35 -> time . V_26 ) ;
V_37 [ 1 ] = F_15 ( V_35 -> time . V_27 ) ;
V_37 [ 2 ] = F_15 ( V_35 -> time . V_28 ) ;
V_37 [ 3 ] = F_15 ( V_35 -> time . V_29 ) ;
V_37 [ 4 ] = F_15 ( V_35 -> time . V_30 + 1 ) ;
V_37 [ 5 ] = F_15 ( V_35 -> time . V_31 - 100 ) ;
V_3 = F_16 ( V_4 , V_37 ,
( V_5 [ V_36 ] ) , V_18 ) ;
if ( V_3 ) {
F_10 ( V_12 , L_11 , V_3 ) ;
goto V_32;
}
if ( V_35 -> V_13 )
V_3 = F_8 ( V_12 , 1 ) ;
V_32:
return V_3 ;
}
static T_2 F_19 ( int V_38 , void * V_39 )
{
unsigned long V_40 ;
int V_3 = V_41 ;
int V_42 ;
T_1 V_43 ;
V_42 = F_1 ( & V_43 , V_44 ) ;
if ( V_42 )
goto V_32;
if ( V_43 & V_45 )
V_40 = V_46 | V_47 ;
else
V_40 = V_46 | V_48 ;
V_42 = F_4 ( V_45 ,
V_44 ) ;
if ( V_42 )
goto V_32;
if ( F_20 () ) {
V_42 = F_2 ( V_49 ,
& V_43 , V_50 ) ;
if ( V_42 )
goto V_32;
}
F_21 ( V_39 , 1 , V_40 ) ;
V_3 = V_51 ;
V_32:
return V_3 ;
}
static int F_22 ( struct V_52 * V_53 )
{
struct V_54 * V_39 ;
int V_3 = - V_55 ;
int V_38 = F_23 ( V_53 , 0 ) ;
T_1 V_43 ;
if ( V_38 <= 0 )
goto V_56;
V_3 = F_1 ( & V_43 , V_44 ) ;
if ( V_3 < 0 )
goto V_56;
if ( V_43 & V_57 )
F_24 ( & V_53 -> V_12 , L_12 ) ;
if ( V_43 & V_45 )
F_24 ( & V_53 -> V_12 , L_13 ) ;
V_3 = F_4 ( V_43 , V_44 ) ;
if ( V_3 < 0 )
goto V_56;
if ( F_11 () ) {
F_25 ( V_58 ,
V_59 ) ;
F_25 ( V_58 ,
V_60 ) ;
}
F_26 ( & V_53 -> V_12 , L_14 ) ;
V_3 = F_4 ( V_33 , V_21 ) ;
if ( V_3 < 0 )
goto V_56;
V_3 = F_4 ( 0 , V_10 ) ;
if ( V_3 < 0 )
F_24 ( & V_53 -> V_12 , L_15 ) ;
V_3 = F_1 ( & V_8 , V_10 ) ;
if ( V_3 < 0 )
goto V_56;
V_39 = F_27 ( V_53 -> V_61 ,
& V_53 -> V_12 , & V_62 , V_63 ) ;
if ( F_28 ( V_39 ) ) {
V_3 = F_29 ( V_39 ) ;
F_10 ( & V_53 -> V_12 , L_16 ,
F_29 ( V_39 ) ) ;
goto V_56;
}
V_3 = F_30 ( V_38 , NULL , F_19 ,
V_64 | V_65 ,
F_31 ( & V_39 -> V_12 ) , V_39 ) ;
if ( V_3 < 0 ) {
F_10 ( & V_53 -> V_12 , L_17 ) ;
goto V_66;
}
F_32 ( V_53 , V_39 ) ;
return 0 ;
V_66:
F_33 ( V_39 ) ;
V_56:
return V_3 ;
}
static int F_34 ( struct V_52 * V_53 )
{
struct V_54 * V_39 = F_35 ( V_53 ) ;
int V_38 = F_23 ( V_53 , 0 ) ;
F_7 ( V_14 ) ;
F_7 ( V_67 ) ;
if ( F_11 () ) {
F_36 ( V_58 ,
V_59 ) ;
F_36 ( V_58 ,
V_60 ) ;
}
F_37 ( V_38 , V_39 ) ;
F_33 ( V_39 ) ;
F_32 ( V_53 , NULL ) ;
return 0 ;
}
static void F_38 ( struct V_52 * V_53 )
{
F_7 ( V_67 ) ;
}
static int F_39 ( struct V_52 * V_53 , T_3 V_68 )
{
V_69 = V_8 ;
F_7 ( V_67 ) ;
return 0 ;
}
static int F_40 ( struct V_52 * V_53 )
{
F_6 ( V_69 ) ;
return 0 ;
}
static int T_4 F_41 ( void )
{
if ( F_20 () )
V_5 = ( T_1 * ) V_70 ;
else
V_5 = ( T_1 * ) V_71 ;
return F_42 ( & V_72 ) ;
}
static void T_5 F_43 ( void )
{
F_44 ( & V_72 ) ;
}
