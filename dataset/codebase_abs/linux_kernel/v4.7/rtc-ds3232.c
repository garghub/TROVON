static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
int V_4 = 0 ;
int V_5 , V_6 ;
V_4 = F_3 ( V_3 -> V_7 , V_8 , & V_6 ) ;
if ( V_4 )
return V_4 ;
if ( V_6 & V_9 )
F_4 ( V_2 ,
L_1
L_2 ) ;
V_6 &= ~ ( V_9 | V_10 | V_11 ) ;
V_4 = F_5 ( V_3 -> V_7 , V_8 , V_6 ) ;
if ( V_4 )
return V_4 ;
V_4 = F_3 ( V_3 -> V_7 , V_12 , & V_5 ) ;
if ( V_4 )
return V_4 ;
V_5 &= ~ ( V_13 | V_14 ) ;
V_5 |= V_15 ;
return F_5 ( V_3 -> V_7 , V_12 , V_5 ) ;
}
static int F_6 ( struct V_1 * V_2 , struct V_16 * time )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
int V_4 ;
T_1 V_17 [ 7 ] ;
unsigned int V_18 , V_19 , V_20 , V_21 , V_22 , V_23 ;
unsigned int V_24 , V_25 , V_26 ;
unsigned int V_27 , V_28 = 0 ;
V_4 = F_7 ( V_3 -> V_7 , V_29 , V_17 , 7 ) ;
if ( V_4 )
return V_4 ;
V_23 = V_17 [ 0 ] ;
V_22 = V_17 [ 1 ] ;
V_21 = V_17 [ 2 ] ;
V_24 = V_17 [ 3 ] ;
V_20 = V_17 [ 4 ] ;
V_19 = V_17 [ 5 ] ;
V_18 = V_17 [ 6 ] ;
V_25 = V_21 & 0x40 ;
V_26 = V_21 & 0x20 ;
V_27 = V_19 & 0x80 ;
time -> V_30 = F_8 ( V_23 ) ;
time -> V_31 = F_8 ( V_22 ) ;
if ( V_25 ) {
if ( V_26 )
time -> V_32 = F_8 ( V_21 & 0x1F ) + 12 ;
else
time -> V_32 = F_8 ( V_21 & 0x1F ) ;
} else {
time -> V_32 = F_8 ( V_21 ) ;
}
time -> V_33 = F_8 ( V_24 ) - 1 ;
time -> V_34 = F_8 ( V_20 ) ;
time -> V_35 = F_8 ( V_19 & 0x7F ) - 1 ;
if ( V_27 )
V_28 = 100 ;
time -> V_36 = F_8 ( V_18 ) + V_28 ;
return F_9 ( time ) ;
}
static int F_10 ( struct V_1 * V_2 , struct V_16 * time )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
T_1 V_17 [ 7 ] ;
V_17 [ 0 ] = F_11 ( time -> V_30 ) ;
V_17 [ 1 ] = F_11 ( time -> V_31 ) ;
V_17 [ 2 ] = F_11 ( time -> V_32 ) ;
V_17 [ 3 ] = F_11 ( time -> V_33 + 1 ) ;
V_17 [ 4 ] = F_11 ( time -> V_34 ) ;
V_17 [ 5 ] = F_11 ( time -> V_35 + 1 ) ;
if ( time -> V_36 >= 100 ) {
V_17 [ 5 ] |= 0x80 ;
V_17 [ 6 ] = F_11 ( time -> V_36 - 100 ) ;
} else {
V_17 [ 6 ] = F_11 ( time -> V_36 ) ;
}
return F_12 ( V_3 -> V_7 , V_29 , V_17 , 7 ) ;
}
static int F_13 ( struct V_1 * V_2 , struct V_37 * V_38 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
int V_5 , V_6 ;
int V_4 ;
T_1 V_17 [ 4 ] ;
V_4 = F_3 ( V_3 -> V_7 , V_8 , & V_6 ) ;
if ( V_4 )
goto V_39;
V_4 = F_3 ( V_3 -> V_7 , V_12 , & V_5 ) ;
if ( V_4 )
goto V_39;
V_4 = F_7 ( V_3 -> V_7 , V_40 , V_17 , 4 ) ;
if ( V_4 )
goto V_39;
V_38 -> time . V_30 = F_8 ( V_17 [ 0 ] & 0x7F ) ;
V_38 -> time . V_31 = F_8 ( V_17 [ 1 ] & 0x7F ) ;
V_38 -> time . V_32 = F_8 ( V_17 [ 2 ] & 0x7F ) ;
V_38 -> time . V_34 = F_8 ( V_17 [ 3 ] & 0x7F ) ;
V_38 -> time . V_35 = - 1 ;
V_38 -> time . V_36 = - 1 ;
V_38 -> time . V_33 = - 1 ;
V_38 -> time . V_41 = - 1 ;
V_38 -> time . V_42 = - 1 ;
V_38 -> V_43 = ! ! ( V_5 & V_13 ) ;
V_38 -> V_44 = ! ! ( V_6 & V_10 ) ;
V_4 = 0 ;
V_39:
return V_4 ;
}
static int F_14 ( struct V_1 * V_2 , struct V_37 * V_38 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
int V_5 , V_6 ;
int V_4 ;
T_1 V_17 [ 4 ] ;
if ( V_3 -> V_45 <= 0 )
return - V_46 ;
V_17 [ 0 ] = F_11 ( V_38 -> time . V_30 ) ;
V_17 [ 1 ] = F_11 ( V_38 -> time . V_31 ) ;
V_17 [ 2 ] = F_11 ( V_38 -> time . V_32 ) ;
V_17 [ 3 ] = F_11 ( V_38 -> time . V_34 ) ;
V_4 = F_3 ( V_3 -> V_7 , V_12 , & V_5 ) ;
if ( V_4 )
goto V_39;
V_5 &= ~ ( V_13 | V_14 ) ;
V_4 = F_5 ( V_3 -> V_7 , V_12 , V_5 ) ;
if ( V_4 )
goto V_39;
V_4 = F_3 ( V_3 -> V_7 , V_8 , & V_6 ) ;
if ( V_4 )
goto V_39;
V_6 &= ~ ( V_10 | V_11 ) ;
V_4 = F_5 ( V_3 -> V_7 , V_8 , V_6 ) ;
if ( V_4 )
goto V_39;
V_4 = F_12 ( V_3 -> V_7 , V_40 , V_17 , 4 ) ;
if ( V_4 )
goto V_39;
if ( V_38 -> V_43 ) {
V_5 |= V_13 ;
V_4 = F_5 ( V_3 -> V_7 , V_12 , V_5 ) ;
}
V_39:
return V_4 ;
}
static int F_15 ( struct V_1 * V_2 , unsigned int V_43 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
int V_5 ;
int V_4 ;
V_4 = F_3 ( V_3 -> V_7 , V_12 , & V_5 ) ;
if ( V_4 )
return V_4 ;
if ( V_43 )
V_5 |= V_13 ;
else
V_5 &= ~ ( V_13 ) ;
V_4 = F_5 ( V_3 -> V_7 , V_12 , V_5 ) ;
return V_4 ;
}
static int F_16 ( struct V_1 * V_2 , unsigned int V_43 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
if ( V_3 -> V_45 <= 0 )
return - V_46 ;
return F_15 ( V_2 , V_43 ) ;
}
static T_2 F_17 ( int V_45 , void * V_47 )
{
struct V_1 * V_2 = V_47 ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_48 * V_49 = & V_3 -> V_50 -> V_51 ;
int V_4 ;
int V_6 , V_5 ;
F_18 ( V_49 ) ;
V_4 = F_3 ( V_3 -> V_7 , V_8 , & V_6 ) ;
if ( V_4 )
goto V_52;
if ( V_6 & V_10 ) {
V_4 = F_3 ( V_3 -> V_7 , V_12 , & V_5 ) ;
if ( V_4 ) {
F_4 ( V_3 -> V_2 ,
L_3 , V_4 ) ;
} else {
V_5 &= ~ ( V_13 ) ;
V_4 = F_5 ( V_3 -> V_7 , V_12 ,
V_5 ) ;
if ( V_4 ) {
F_4 ( V_3 -> V_2 ,
L_4 ,
V_4 ) ;
goto V_52;
}
V_6 &= ~ V_10 ;
V_4 = F_5 ( V_3 -> V_7 , V_8 , V_6 ) ;
if ( V_4 ) {
F_4 ( V_3 -> V_2 ,
L_5 ,
V_4 ) ;
goto V_52;
}
F_19 ( V_3 -> V_50 , 1 , V_53 | V_54 ) ;
}
}
V_52:
F_20 ( V_49 ) ;
return V_55 ;
}
static int F_21 ( struct V_1 * V_2 , struct V_7 * V_7 , int V_45 ,
const char * V_56 )
{
struct V_3 * V_3 ;
int V_4 ;
V_3 = F_22 ( V_2 , sizeof( * V_3 ) , V_57 ) ;
if ( ! V_3 )
return - V_58 ;
V_3 -> V_7 = V_7 ;
V_3 -> V_45 = V_45 ;
V_3 -> V_2 = V_2 ;
F_23 ( V_2 , V_3 ) ;
V_4 = F_1 ( V_2 ) ;
if ( V_4 )
return V_4 ;
V_3 -> V_50 = F_24 ( V_2 , V_56 , & V_59 ,
V_60 ) ;
if ( F_25 ( V_3 -> V_50 ) )
return F_26 ( V_3 -> V_50 ) ;
if ( V_3 -> V_45 > 0 ) {
V_4 = F_27 ( V_2 , V_3 -> V_45 , NULL ,
F_17 ,
V_61 | V_62 ,
V_56 , V_2 ) ;
if ( V_4 ) {
V_3 -> V_45 = 0 ;
F_28 ( V_2 , L_6 ) ;
} else
F_29 ( V_2 , 1 ) ;
}
return 0 ;
}
static int F_30 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
if ( F_31 ( V_2 ) ) {
if ( F_32 ( V_3 -> V_45 ) )
F_33 ( V_2 , L_7 ) ;
}
return 0 ;
}
static int F_34 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
if ( F_31 ( V_2 ) )
F_35 ( V_3 -> V_45 ) ;
return 0 ;
}
static int F_36 ( struct V_63 * V_64 ,
const struct V_65 * V_66 )
{
struct V_7 * V_7 ;
static const struct V_67 V_68 = {
. V_69 = 8 ,
. V_70 = 8 ,
} ;
V_7 = F_37 ( V_64 , & V_68 ) ;
if ( F_25 ( V_7 ) ) {
F_28 ( & V_64 -> V_2 , L_8 ,
V_71 , F_26 ( V_7 ) ) ;
return F_26 ( V_7 ) ;
}
return F_21 ( & V_64 -> V_2 , V_7 , V_64 -> V_45 , V_64 -> V_56 ) ;
}
static int F_38 ( void )
{
return F_39 ( & V_72 ) ;
}
static void F_40 ( void )
{
F_41 ( & V_72 ) ;
}
static int F_38 ( void )
{
return 0 ;
}
static void F_40 ( void )
{
}
static int F_42 ( struct V_73 * V_74 )
{
int V_75 ;
unsigned int V_76 ;
static const struct V_67 V_68 = {
. V_69 = 8 ,
. V_70 = 8 ,
. V_77 = 0x80 ,
} ;
struct V_7 * V_7 ;
V_7 = F_43 ( V_74 , & V_68 ) ;
if ( F_25 ( V_7 ) ) {
F_28 ( & V_74 -> V_2 , L_8 ,
V_71 , F_26 ( V_7 ) ) ;
return F_26 ( V_7 ) ;
}
V_74 -> V_78 = V_79 ;
V_74 -> V_80 = 8 ;
F_44 ( V_74 ) ;
V_75 = F_3 ( V_7 , V_29 , & V_76 ) ;
if ( V_75 )
return V_75 ;
V_75 = F_3 ( V_7 , V_12 , & V_76 ) ;
if ( V_75 )
return V_75 ;
V_75 = F_5 ( V_7 , V_12 , V_76 & 0x1c ) ;
if ( V_75 )
return V_75 ;
V_75 = F_3 ( V_7 , V_8 , & V_76 ) ;
if ( V_75 )
return V_75 ;
V_75 = F_5 ( V_7 , V_8 , V_76 & 0x88 ) ;
if ( V_75 )
return V_75 ;
V_75 = F_3 ( V_7 , V_12 , & V_76 ) ;
if ( V_75 )
return V_75 ;
F_45 ( & V_74 -> V_2 , L_9 , V_76 ) ;
V_75 = F_3 ( V_7 , V_8 , & V_76 ) ;
if ( V_75 )
return V_75 ;
F_45 ( & V_74 -> V_2 , L_10 , V_76 ) ;
return F_21 ( & V_74 -> V_2 , V_7 , V_74 -> V_45 , L_11 ) ;
}
static int F_46 ( void )
{
return F_47 ( & V_81 ) ;
}
static void F_48 ( void )
{
F_49 ( & V_81 ) ;
}
static int F_46 ( void )
{
return 0 ;
}
static void F_48 ( void )
{
}
static int T_3 F_50 ( void )
{
int V_4 ;
V_4 = F_38 () ;
if ( V_4 ) {
F_51 ( L_12 , V_4 ) ;
return V_4 ;
}
V_4 = F_46 () ;
if ( V_4 ) {
F_51 ( L_13 , V_4 ) ;
F_40 () ;
}
return V_4 ;
}
static void T_4 F_52 ( void )
{
F_48 () ;
F_40 () ;
}
