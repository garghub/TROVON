static int F_1 ( struct V_1 * V_1 , T_1 * V_2 , T_1 V_3 )
{
int V_4 ;
V_4 = F_2 ( V_5 , V_2 , ( V_1 -> V_6 [ V_3 ] ) ) ;
if ( V_4 < 0 )
F_3 ( L_1 , V_3 , V_4 ) ;
return V_4 ;
}
static int F_4 ( struct V_1 * V_1 , T_1 V_2 , T_1 V_3 )
{
int V_4 ;
V_4 = F_5 ( V_5 , V_2 , ( V_1 -> V_6 [ V_3 ] ) ) ;
if ( V_4 < 0 )
F_3 ( L_2 ,
V_3 , V_4 ) ;
return V_4 ;
}
static int F_6 ( struct V_1 * V_1 , unsigned char V_7 )
{
unsigned char V_8 ;
int V_4 ;
if ( V_1 -> V_9 & V_7 )
return 0 ;
V_8 = V_1 -> V_9 | V_7 ;
V_8 &= ~ V_10 ;
V_4 = F_4 ( V_1 , V_8 , V_11 ) ;
if ( V_4 == 0 )
V_1 -> V_9 = V_8 ;
return V_4 ;
}
static int F_7 ( struct V_1 * V_1 , unsigned char V_7 )
{
unsigned char V_8 ;
int V_4 ;
if ( ! ( V_1 -> V_9 & V_7 ) )
return 0 ;
V_8 = V_1 -> V_9 & ~ V_7 ;
V_4 = F_4 ( V_1 , V_8 , V_11 ) ;
if ( V_4 == 0 )
V_1 -> V_9 = V_8 ;
return V_4 ;
}
static int F_8 ( struct V_12 * V_13 , unsigned V_14 )
{
struct V_15 * V_16 = F_9 ( V_13 ) ;
struct V_1 * V_1 = F_10 ( V_13 ) ;
int V_17 = F_11 ( V_16 , 0 ) ;
int V_4 ;
if ( V_14 ) {
V_4 = F_6 ( V_1 ,
V_18 ) ;
if ( F_12 ( V_13 ) && ! V_1 -> V_19 ) {
F_13 ( V_17 ) ;
V_1 -> V_19 = true ;
}
} else {
V_4 = F_7 ( V_1 ,
V_18 ) ;
if ( V_1 -> V_19 ) {
F_14 ( V_17 ) ;
V_1 -> V_19 = false ;
}
}
return V_4 ;
}
static int F_15 ( struct V_12 * V_13 , struct V_20 * V_21 )
{
struct V_1 * V_1 = F_10 ( V_13 ) ;
unsigned char V_22 [ V_23 ] ;
int V_4 ;
T_1 V_24 ;
T_1 V_25 ;
V_4 = F_1 ( V_1 , & V_24 , V_26 ) ;
if ( V_4 < 0 ) {
F_16 ( V_13 , L_3 , V_27 , V_4 ) ;
return V_4 ;
}
if ( V_1 -> V_28 == V_29 ) {
if ( V_24 & V_30 ) {
V_24 &= ~ V_30 ;
V_4 = F_4 ( V_1 , V_24 ,
V_26 ) ;
if ( V_4 < 0 ) {
F_16 ( V_13 , L_4 ,
V_27 , V_4 ) ;
return V_4 ;
}
}
}
V_25 = V_24 | V_30 ;
if ( V_1 -> V_28 == V_29 )
V_25 |= V_31 ;
V_4 = F_4 ( V_1 , V_25 , V_26 ) ;
if ( V_4 < 0 ) {
F_16 ( V_13 , L_5 , V_27 , V_4 ) ;
return V_4 ;
}
V_4 = F_17 ( V_5 , V_22 ,
( V_1 -> V_6 [ V_32 ] ) , V_23 ) ;
if ( V_4 < 0 ) {
F_16 ( V_13 , L_6 , V_27 , V_4 ) ;
return V_4 ;
}
if ( V_1 -> V_28 == V_29 ) {
V_4 = F_4 ( V_1 , V_24 , V_26 ) ;
if ( V_4 < 0 ) {
F_16 ( V_13 , L_7 ,
V_27 , V_4 ) ;
return V_4 ;
}
}
V_21 -> V_33 = F_18 ( V_22 [ 0 ] ) ;
V_21 -> V_34 = F_18 ( V_22 [ 1 ] ) ;
V_21 -> V_35 = F_18 ( V_22 [ 2 ] ) ;
V_21 -> V_36 = F_18 ( V_22 [ 3 ] ) ;
V_21 -> V_37 = F_18 ( V_22 [ 4 ] ) - 1 ;
V_21 -> V_38 = F_18 ( V_22 [ 5 ] ) + 100 ;
return V_4 ;
}
static int F_19 ( struct V_12 * V_13 , struct V_20 * V_21 )
{
struct V_1 * V_1 = F_10 ( V_13 ) ;
unsigned char V_24 ;
unsigned char V_22 [ V_23 ] ;
int V_4 ;
V_22 [ 0 ] = F_20 ( V_21 -> V_33 ) ;
V_22 [ 1 ] = F_20 ( V_21 -> V_34 ) ;
V_22 [ 2 ] = F_20 ( V_21 -> V_35 ) ;
V_22 [ 3 ] = F_20 ( V_21 -> V_36 ) ;
V_22 [ 4 ] = F_20 ( V_21 -> V_37 + 1 ) ;
V_22 [ 5 ] = F_20 ( V_21 -> V_38 - 100 ) ;
V_4 = F_1 ( V_1 , & V_24 , V_26 ) ;
if ( V_4 < 0 )
goto V_39;
V_24 &= ~ V_40 ;
V_4 = F_4 ( V_1 , V_24 , V_26 ) ;
if ( V_4 < 0 )
goto V_39;
V_4 = F_21 ( V_5 , V_22 ,
( V_1 -> V_6 [ V_32 ] ) , V_23 ) ;
if ( V_4 < 0 ) {
F_16 ( V_13 , L_8 , V_4 ) ;
goto V_39;
}
V_24 |= V_40 ;
V_4 = F_4 ( V_1 , V_24 , V_26 ) ;
V_39:
return V_4 ;
}
static int F_22 ( struct V_12 * V_13 , struct V_41 * V_42 )
{
struct V_1 * V_1 = F_10 ( V_13 ) ;
unsigned char V_22 [ V_23 ] ;
int V_4 ;
V_4 = F_17 ( V_5 , V_22 ,
V_1 -> V_6 [ V_43 ] , V_23 ) ;
if ( V_4 < 0 ) {
F_16 ( V_13 , L_9 , V_4 ) ;
return V_4 ;
}
V_42 -> time . V_33 = F_18 ( V_22 [ 0 ] ) ;
V_42 -> time . V_34 = F_18 ( V_22 [ 1 ] ) ;
V_42 -> time . V_35 = F_18 ( V_22 [ 2 ] ) ;
V_42 -> time . V_36 = F_18 ( V_22 [ 3 ] ) ;
V_42 -> time . V_37 = F_18 ( V_22 [ 4 ] ) - 1 ;
V_42 -> time . V_38 = F_18 ( V_22 [ 5 ] ) + 100 ;
if ( V_1 -> V_9 & V_18 )
V_42 -> V_14 = 1 ;
return V_4 ;
}
static int F_23 ( struct V_12 * V_13 , struct V_41 * V_42 )
{
struct V_1 * V_1 = F_10 ( V_13 ) ;
unsigned char V_44 [ V_23 ] ;
int V_4 ;
V_4 = F_8 ( V_13 , 0 ) ;
if ( V_4 )
goto V_39;
V_44 [ 0 ] = F_20 ( V_42 -> time . V_33 ) ;
V_44 [ 1 ] = F_20 ( V_42 -> time . V_34 ) ;
V_44 [ 2 ] = F_20 ( V_42 -> time . V_35 ) ;
V_44 [ 3 ] = F_20 ( V_42 -> time . V_36 ) ;
V_44 [ 4 ] = F_20 ( V_42 -> time . V_37 + 1 ) ;
V_44 [ 5 ] = F_20 ( V_42 -> time . V_38 - 100 ) ;
V_4 = F_21 ( V_5 , V_44 ,
V_1 -> V_6 [ V_43 ] , V_23 ) ;
if ( V_4 ) {
F_16 ( V_13 , L_10 , V_4 ) ;
goto V_39;
}
if ( V_42 -> V_14 )
V_4 = F_8 ( V_13 , 1 ) ;
V_39:
return V_4 ;
}
static T_2 F_24 ( int V_17 , void * V_2 )
{
struct V_1 * V_1 = V_2 ;
unsigned long V_45 ;
int V_4 = V_46 ;
int V_47 ;
T_1 V_48 ;
V_47 = F_1 ( V_1 , & V_48 , V_49 ) ;
if ( V_47 )
goto V_39;
if ( V_48 & V_50 )
V_45 = V_51 | V_52 ;
else
V_45 = V_51 | V_53 ;
V_47 = F_4 ( V_1 , V_50 ,
V_49 ) ;
if ( V_47 )
goto V_39;
if ( V_1 -> V_28 == V_54 ) {
V_47 = F_2 ( V_55 ,
& V_48 , V_56 ) ;
if ( V_47 )
goto V_39;
}
F_25 ( V_1 -> V_57 , 1 , V_45 ) ;
V_4 = V_58 ;
V_39:
return V_4 ;
}
static int F_26 ( struct V_15 * V_16 )
{
struct V_1 * V_1 ;
struct V_59 * V_60 = V_16 -> V_13 . V_61 ;
int V_4 = - V_62 ;
int V_17 = F_11 ( V_16 , 0 ) ;
T_1 V_48 ;
if ( ! V_60 ) {
F_16 ( & V_16 -> V_13 , L_11 ) ;
return - V_62 ;
}
if ( V_17 <= 0 )
return V_4 ;
V_1 = F_27 ( & V_16 -> V_13 , sizeof( * V_1 ) , V_63 ) ;
if ( ! V_1 )
return - V_64 ;
if ( F_28 () ) {
V_1 -> V_28 = V_54 ;
V_1 -> V_6 = ( T_1 * ) V_65 ;
} else if ( F_29 () ) {
V_1 -> V_28 = V_29 ;
V_1 -> V_6 = ( T_1 * ) V_66 ;
} else {
F_16 ( & V_16 -> V_13 , L_12 ) ;
return - V_62 ;
}
V_4 = F_1 ( V_1 , & V_48 , V_49 ) ;
if ( V_4 < 0 )
return V_4 ;
if ( V_48 & V_67 )
F_30 ( & V_16 -> V_13 , L_13 ) ;
if ( V_48 & V_50 )
F_30 ( & V_16 -> V_13 , L_14 ) ;
V_4 = F_4 ( V_1 , V_48 , V_49 ) ;
if ( V_4 < 0 )
return V_4 ;
if ( V_1 -> V_28 == V_29 ) {
F_31 ( V_68 ,
V_69 ) ;
F_31 ( V_68 ,
V_70 ) ;
}
F_32 ( & V_16 -> V_13 , L_15 ) ;
V_4 = F_4 ( V_1 , V_40 ,
V_26 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_4 ( V_1 , 0 , V_11 ) ;
if ( V_4 < 0 )
F_30 ( & V_16 -> V_13 , L_16 ) ;
V_4 = F_1 ( V_1 , & V_1 -> V_9 ,
V_11 ) ;
if ( V_4 < 0 )
return V_4 ;
F_33 ( V_16 , V_1 ) ;
F_34 ( & V_16 -> V_13 , 1 ) ;
V_1 -> V_57 = F_35 ( & V_16 -> V_13 , V_16 -> V_71 ,
& V_72 , V_73 ) ;
if ( F_36 ( V_1 -> V_57 ) ) {
F_16 ( & V_16 -> V_13 , L_17 ,
F_37 ( V_1 -> V_57 ) ) ;
return F_37 ( V_1 -> V_57 ) ;
}
V_4 = F_38 ( & V_16 -> V_13 , V_17 , NULL ,
F_24 ,
V_74 | V_75 ,
F_39 ( & V_1 -> V_57 -> V_13 ) , V_1 ) ;
if ( V_4 < 0 ) {
F_16 ( & V_16 -> V_13 , L_18 ) ;
return V_4 ;
}
return 0 ;
}
static int F_40 ( struct V_15 * V_16 )
{
struct V_1 * V_1 = F_41 ( V_16 ) ;
F_7 ( V_1 , V_18 ) ;
F_7 ( V_1 , V_76 ) ;
if ( V_1 -> V_28 == V_29 ) {
F_42 ( V_68 ,
V_69 ) ;
F_42 ( V_68 ,
V_70 ) ;
}
return 0 ;
}
static void F_43 ( struct V_15 * V_16 )
{
struct V_1 * V_1 = F_41 ( V_16 ) ;
F_7 ( V_1 , V_76 ) ;
}
static int F_44 ( struct V_12 * V_13 )
{
struct V_1 * V_1 = F_10 ( V_13 ) ;
V_1 -> V_77 = V_1 -> V_9 ;
F_7 ( V_1 , V_76 ) ;
return 0 ;
}
static int F_45 ( struct V_12 * V_13 )
{
struct V_1 * V_1 = F_10 ( V_13 ) ;
F_6 ( V_1 , V_1 -> V_77 ) ;
return 0 ;
}
