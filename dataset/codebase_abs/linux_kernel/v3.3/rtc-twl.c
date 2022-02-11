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
unsigned char V_17 [ V_18 + 1 ] ;
int V_3 ;
T_1 V_19 ;
V_3 = F_1 ( & V_19 , V_20 ) ;
if ( V_3 < 0 )
return V_3 ;
V_19 |= V_21 ;
V_3 = F_4 ( V_19 , V_20 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_10 ( V_4 , V_17 ,
( V_5 [ V_22 ] ) , V_18 ) ;
if ( V_3 < 0 ) {
F_11 ( V_12 , L_4 , V_3 ) ;
return V_3 ;
}
V_16 -> V_23 = F_12 ( V_17 [ 0 ] ) ;
V_16 -> V_24 = F_12 ( V_17 [ 1 ] ) ;
V_16 -> V_25 = F_12 ( V_17 [ 2 ] ) ;
V_16 -> V_26 = F_12 ( V_17 [ 3 ] ) ;
V_16 -> V_27 = F_12 ( V_17 [ 4 ] ) - 1 ;
V_16 -> V_28 = F_12 ( V_17 [ 5 ] ) + 100 ;
return V_3 ;
}
static int F_13 ( struct V_11 * V_12 , struct V_15 * V_16 )
{
unsigned char V_19 ;
unsigned char V_17 [ V_18 + 1 ] ;
int V_3 ;
V_17 [ 1 ] = F_14 ( V_16 -> V_23 ) ;
V_17 [ 2 ] = F_14 ( V_16 -> V_24 ) ;
V_17 [ 3 ] = F_14 ( V_16 -> V_25 ) ;
V_17 [ 4 ] = F_14 ( V_16 -> V_26 ) ;
V_17 [ 5 ] = F_14 ( V_16 -> V_27 + 1 ) ;
V_17 [ 6 ] = F_14 ( V_16 -> V_28 - 100 ) ;
V_3 = F_1 ( & V_19 , V_20 ) ;
if ( V_3 < 0 )
goto V_29;
V_19 &= ~ V_30 ;
V_3 = F_4 ( V_19 , V_20 ) ;
if ( V_3 < 0 )
goto V_29;
V_3 = F_15 ( V_4 , V_17 ,
( V_5 [ V_22 ] ) , V_18 ) ;
if ( V_3 < 0 ) {
F_11 ( V_12 , L_5 , V_3 ) ;
goto V_29;
}
V_19 |= V_30 ;
V_3 = F_4 ( V_19 , V_20 ) ;
V_29:
return V_3 ;
}
static int F_16 ( struct V_11 * V_12 , struct V_31 * V_32 )
{
unsigned char V_17 [ V_18 + 1 ] ;
int V_3 ;
V_3 = F_10 ( V_4 , V_17 ,
( V_5 [ V_33 ] ) , V_18 ) ;
if ( V_3 < 0 ) {
F_11 ( V_12 , L_6 , V_3 ) ;
return V_3 ;
}
V_32 -> time . V_23 = F_12 ( V_17 [ 0 ] ) ;
V_32 -> time . V_24 = F_12 ( V_17 [ 1 ] ) ;
V_32 -> time . V_25 = F_12 ( V_17 [ 2 ] ) ;
V_32 -> time . V_26 = F_12 ( V_17 [ 3 ] ) ;
V_32 -> time . V_27 = F_12 ( V_17 [ 4 ] ) - 1 ;
V_32 -> time . V_28 = F_12 ( V_17 [ 5 ] ) + 100 ;
if ( V_8 & V_14 )
V_32 -> V_13 = 1 ;
return V_3 ;
}
static int F_17 ( struct V_11 * V_12 , struct V_31 * V_32 )
{
unsigned char V_34 [ V_18 + 1 ] ;
int V_3 ;
V_3 = F_8 ( V_12 , 0 ) ;
if ( V_3 )
goto V_29;
V_34 [ 1 ] = F_14 ( V_32 -> time . V_23 ) ;
V_34 [ 2 ] = F_14 ( V_32 -> time . V_24 ) ;
V_34 [ 3 ] = F_14 ( V_32 -> time . V_25 ) ;
V_34 [ 4 ] = F_14 ( V_32 -> time . V_26 ) ;
V_34 [ 5 ] = F_14 ( V_32 -> time . V_27 + 1 ) ;
V_34 [ 6 ] = F_14 ( V_32 -> time . V_28 - 100 ) ;
V_3 = F_15 ( V_4 , V_34 ,
( V_5 [ V_33 ] ) , V_18 ) ;
if ( V_3 ) {
F_11 ( V_12 , L_7 , V_3 ) ;
goto V_29;
}
if ( V_32 -> V_13 )
V_3 = F_8 ( V_12 , 1 ) ;
V_29:
return V_3 ;
}
static T_2 F_18 ( int V_35 , void * V_36 )
{
unsigned long V_37 = 0 ;
int V_3 = V_38 ;
int V_39 ;
T_1 V_40 ;
V_39 = F_1 ( & V_40 , V_41 ) ;
if ( V_39 )
goto V_29;
if ( V_40 & V_42 )
V_37 |= V_43 | V_44 ;
else
V_37 |= V_43 | V_45 ;
V_39 = F_4 ( V_40 | V_42 ,
V_41 ) ;
if ( V_39 )
goto V_29;
if ( F_19 () ) {
V_39 = F_2 ( V_46 ,
& V_40 , V_47 ) ;
if ( V_39 )
goto V_29;
}
F_20 ( V_36 , 1 , V_37 ) ;
V_3 = V_48 ;
V_29:
return V_3 ;
}
static int T_3 F_21 ( struct V_49 * V_50 )
{
struct V_51 * V_36 ;
int V_3 = - V_52 ;
int V_35 = F_22 ( V_50 , 0 ) ;
T_1 V_40 ;
if ( V_35 <= 0 )
goto V_53;
V_3 = F_1 ( & V_40 , V_41 ) ;
if ( V_3 < 0 )
goto V_53;
if ( V_40 & V_54 )
F_23 ( & V_50 -> V_12 , L_8 ) ;
if ( V_40 & V_42 )
F_23 ( & V_50 -> V_12 , L_9 ) ;
V_3 = F_4 ( V_40 , V_41 ) ;
if ( V_3 < 0 )
goto V_53;
if ( F_24 () ) {
F_25 ( V_55 ,
V_56 ) ;
F_25 ( V_55 ,
V_57 ) ;
}
V_3 = F_1 ( & V_40 , V_20 ) ;
if ( V_3 < 0 )
goto V_53;
if ( ! ( V_40 & V_30 ) ) {
F_26 ( & V_50 -> V_12 , L_10 ) ;
V_40 = V_30 ;
V_3 = F_4 ( V_40 , V_20 ) ;
if ( V_3 < 0 )
goto V_53;
}
V_3 = F_1 ( & V_8 , V_10 ) ;
if ( V_3 < 0 )
goto V_53;
V_36 = F_27 ( V_50 -> V_58 ,
& V_50 -> V_12 , & V_59 , V_60 ) ;
if ( F_28 ( V_36 ) ) {
V_3 = F_29 ( V_36 ) ;
F_11 ( & V_50 -> V_12 , L_11 ,
F_29 ( V_36 ) ) ;
goto V_53;
}
V_3 = F_30 ( V_35 , NULL , F_18 ,
V_61 ,
F_31 ( & V_36 -> V_12 ) , V_36 ) ;
if ( V_3 < 0 ) {
F_11 ( & V_50 -> V_12 , L_12 ) ;
goto V_62;
}
F_32 ( V_50 , V_36 ) ;
return 0 ;
V_62:
F_33 ( V_36 ) ;
V_53:
return V_3 ;
}
static int T_4 F_34 ( struct V_49 * V_50 )
{
struct V_51 * V_36 = F_35 ( V_50 ) ;
int V_35 = F_22 ( V_50 , 0 ) ;
F_7 ( V_14 ) ;
F_7 ( V_63 ) ;
if ( F_24 () ) {
F_36 ( V_55 ,
V_56 ) ;
F_36 ( V_55 ,
V_57 ) ;
}
F_37 ( V_35 , V_36 ) ;
F_33 ( V_36 ) ;
F_32 ( V_50 , NULL ) ;
return 0 ;
}
static void F_38 ( struct V_49 * V_50 )
{
F_7 ( V_63 ) ;
}
static int F_39 ( struct V_49 * V_50 , T_5 V_64 )
{
V_65 = V_8 ;
F_7 ( V_63 ) ;
return 0 ;
}
static int F_40 ( struct V_49 * V_50 )
{
F_6 ( V_65 ) ;
return 0 ;
}
static int T_6 F_41 ( void )
{
if ( F_19 () )
V_5 = ( T_1 * ) V_66 ;
else
V_5 = ( T_1 * ) V_67 ;
return F_42 ( & V_68 ) ;
}
static void T_7 F_43 ( void )
{
F_44 ( & V_68 ) ;
}
