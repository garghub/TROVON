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
struct V_14 * V_15 = F_9 ( V_12 ) ;
int V_16 = F_10 ( V_15 , 0 ) ;
static bool V_17 ;
int V_3 ;
if ( V_13 ) {
V_3 = F_6 ( V_18 ) ;
if ( F_11 ( V_12 ) && ! V_17 ) {
F_12 ( V_16 ) ;
V_17 = true ;
}
} else {
V_3 = F_7 ( V_18 ) ;
if ( V_17 ) {
F_13 ( V_16 ) ;
V_17 = false ;
}
}
return V_3 ;
}
static int F_14 ( struct V_11 * V_12 , struct V_19 * V_20 )
{
unsigned char V_21 [ V_22 ] ;
int V_3 ;
T_1 V_23 ;
T_1 V_24 ;
V_3 = F_1 ( & V_23 , V_25 ) ;
if ( V_3 < 0 ) {
F_15 ( V_12 , L_4 , V_26 , V_3 ) ;
return V_3 ;
}
if ( F_16 () ) {
if ( V_23 & V_27 ) {
V_23 &= ~ V_27 ;
V_3 = F_4 ( V_23 , V_25 ) ;
if ( V_3 < 0 ) {
F_15 ( V_12 , L_5 ,
V_26 , V_3 ) ;
return V_3 ;
}
}
}
V_24 = V_23 | V_27 ;
if ( F_16 () )
V_24 |= V_28 ;
V_3 = F_4 ( V_24 , V_25 ) ;
if ( V_3 < 0 ) {
F_15 ( V_12 , L_6 , V_26 , V_3 ) ;
return V_3 ;
}
V_3 = F_17 ( V_4 , V_21 ,
( V_5 [ V_29 ] ) , V_22 ) ;
if ( V_3 < 0 ) {
F_15 ( V_12 , L_7 , V_26 , V_3 ) ;
return V_3 ;
}
if ( F_16 () ) {
V_3 = F_4 ( V_23 , V_25 ) ;
if ( V_3 < 0 ) {
F_15 ( V_12 , L_8 ,
V_26 , V_3 ) ;
return V_3 ;
}
}
V_20 -> V_30 = F_18 ( V_21 [ 0 ] ) ;
V_20 -> V_31 = F_18 ( V_21 [ 1 ] ) ;
V_20 -> V_32 = F_18 ( V_21 [ 2 ] ) ;
V_20 -> V_33 = F_18 ( V_21 [ 3 ] ) ;
V_20 -> V_34 = F_18 ( V_21 [ 4 ] ) - 1 ;
V_20 -> V_35 = F_18 ( V_21 [ 5 ] ) + 100 ;
return V_3 ;
}
static int F_19 ( struct V_11 * V_12 , struct V_19 * V_20 )
{
unsigned char V_23 ;
unsigned char V_21 [ V_22 ] ;
int V_3 ;
V_21 [ 0 ] = F_20 ( V_20 -> V_30 ) ;
V_21 [ 1 ] = F_20 ( V_20 -> V_31 ) ;
V_21 [ 2 ] = F_20 ( V_20 -> V_32 ) ;
V_21 [ 3 ] = F_20 ( V_20 -> V_33 ) ;
V_21 [ 4 ] = F_20 ( V_20 -> V_34 + 1 ) ;
V_21 [ 5 ] = F_20 ( V_20 -> V_35 - 100 ) ;
V_3 = F_1 ( & V_23 , V_25 ) ;
if ( V_3 < 0 )
goto V_36;
V_23 &= ~ V_37 ;
V_3 = F_4 ( V_23 , V_25 ) ;
if ( V_3 < 0 )
goto V_36;
V_3 = F_21 ( V_4 , V_21 ,
( V_5 [ V_29 ] ) , V_22 ) ;
if ( V_3 < 0 ) {
F_15 ( V_12 , L_9 , V_3 ) ;
goto V_36;
}
V_23 |= V_37 ;
V_3 = F_4 ( V_23 , V_25 ) ;
V_36:
return V_3 ;
}
static int F_22 ( struct V_11 * V_12 , struct V_38 * V_39 )
{
unsigned char V_21 [ V_22 ] ;
int V_3 ;
V_3 = F_17 ( V_4 , V_21 ,
( V_5 [ V_40 ] ) , V_22 ) ;
if ( V_3 < 0 ) {
F_15 ( V_12 , L_10 , V_3 ) ;
return V_3 ;
}
V_39 -> time . V_30 = F_18 ( V_21 [ 0 ] ) ;
V_39 -> time . V_31 = F_18 ( V_21 [ 1 ] ) ;
V_39 -> time . V_32 = F_18 ( V_21 [ 2 ] ) ;
V_39 -> time . V_33 = F_18 ( V_21 [ 3 ] ) ;
V_39 -> time . V_34 = F_18 ( V_21 [ 4 ] ) - 1 ;
V_39 -> time . V_35 = F_18 ( V_21 [ 5 ] ) + 100 ;
if ( V_8 & V_18 )
V_39 -> V_13 = 1 ;
return V_3 ;
}
static int F_23 ( struct V_11 * V_12 , struct V_38 * V_39 )
{
unsigned char V_41 [ V_22 ] ;
int V_3 ;
V_3 = F_8 ( V_12 , 0 ) ;
if ( V_3 )
goto V_36;
V_41 [ 0 ] = F_20 ( V_39 -> time . V_30 ) ;
V_41 [ 1 ] = F_20 ( V_39 -> time . V_31 ) ;
V_41 [ 2 ] = F_20 ( V_39 -> time . V_32 ) ;
V_41 [ 3 ] = F_20 ( V_39 -> time . V_33 ) ;
V_41 [ 4 ] = F_20 ( V_39 -> time . V_34 + 1 ) ;
V_41 [ 5 ] = F_20 ( V_39 -> time . V_35 - 100 ) ;
V_3 = F_21 ( V_4 , V_41 ,
( V_5 [ V_40 ] ) , V_22 ) ;
if ( V_3 ) {
F_15 ( V_12 , L_11 , V_3 ) ;
goto V_36;
}
if ( V_39 -> V_13 )
V_3 = F_8 ( V_12 , 1 ) ;
V_36:
return V_3 ;
}
static T_2 F_24 ( int V_16 , void * V_42 )
{
unsigned long V_43 ;
int V_3 = V_44 ;
int V_45 ;
T_1 V_46 ;
V_45 = F_1 ( & V_46 , V_47 ) ;
if ( V_45 )
goto V_36;
if ( V_46 & V_48 )
V_43 = V_49 | V_50 ;
else
V_43 = V_49 | V_51 ;
V_45 = F_4 ( V_48 ,
V_47 ) ;
if ( V_45 )
goto V_36;
if ( F_25 () ) {
V_45 = F_2 ( V_52 ,
& V_46 , V_53 ) ;
if ( V_45 )
goto V_36;
}
F_26 ( V_42 , 1 , V_43 ) ;
V_3 = V_54 ;
V_36:
return V_3 ;
}
static int F_27 ( struct V_14 * V_15 )
{
struct V_55 * V_42 ;
int V_3 = - V_56 ;
int V_16 = F_10 ( V_15 , 0 ) ;
T_1 V_46 ;
if ( V_16 <= 0 )
goto V_57;
if ( F_25 () )
V_5 = ( T_1 * ) V_58 ;
else
V_5 = ( T_1 * ) V_59 ;
V_3 = F_1 ( & V_46 , V_47 ) ;
if ( V_3 < 0 )
goto V_57;
if ( V_46 & V_60 )
F_28 ( & V_15 -> V_12 , L_12 ) ;
if ( V_46 & V_48 )
F_28 ( & V_15 -> V_12 , L_13 ) ;
V_3 = F_4 ( V_46 , V_47 ) ;
if ( V_3 < 0 )
goto V_57;
if ( F_16 () ) {
F_29 ( V_61 ,
V_62 ) ;
F_29 ( V_61 ,
V_63 ) ;
}
F_30 ( & V_15 -> V_12 , L_14 ) ;
V_3 = F_4 ( V_37 , V_25 ) ;
if ( V_3 < 0 )
goto V_57;
V_3 = F_4 ( 0 , V_10 ) ;
if ( V_3 < 0 )
F_28 ( & V_15 -> V_12 , L_15 ) ;
V_3 = F_1 ( & V_8 , V_10 ) ;
if ( V_3 < 0 )
goto V_57;
F_31 ( & V_15 -> V_12 , 1 ) ;
V_42 = F_32 ( V_15 -> V_64 ,
& V_15 -> V_12 , & V_65 , V_66 ) ;
if ( F_33 ( V_42 ) ) {
V_3 = F_34 ( V_42 ) ;
F_15 ( & V_15 -> V_12 , L_16 ,
F_34 ( V_42 ) ) ;
goto V_57;
}
V_3 = F_35 ( V_16 , NULL , F_24 ,
V_67 | V_68 ,
F_36 ( & V_42 -> V_12 ) , V_42 ) ;
if ( V_3 < 0 ) {
F_15 ( & V_15 -> V_12 , L_17 ) ;
goto V_69;
}
F_37 ( V_15 , V_42 ) ;
return 0 ;
V_69:
F_38 ( V_42 ) ;
V_57:
return V_3 ;
}
static int F_39 ( struct V_14 * V_15 )
{
struct V_55 * V_42 = F_40 ( V_15 ) ;
int V_16 = F_10 ( V_15 , 0 ) ;
F_7 ( V_18 ) ;
F_7 ( V_70 ) ;
if ( F_16 () ) {
F_41 ( V_61 ,
V_62 ) ;
F_41 ( V_61 ,
V_63 ) ;
}
F_42 ( V_16 , V_42 ) ;
F_38 ( V_42 ) ;
return 0 ;
}
static void F_43 ( struct V_14 * V_15 )
{
F_7 ( V_70 ) ;
}
static int F_44 ( struct V_11 * V_12 )
{
V_71 = V_8 ;
F_7 ( V_70 ) ;
return 0 ;
}
static int F_45 ( struct V_11 * V_12 )
{
F_6 ( V_71 ) ;
return 0 ;
}
