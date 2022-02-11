static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( 0xaa , V_4 -> V_5 + V_6 ) ;
F_3 ( 0x55 , V_4 -> V_5 + V_6 ) ;
return 0 ;
}
static unsigned int F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_7 ;
V_7 = F_5 ( V_4 -> V_5 + V_8 ) ;
return F_6 ( V_7 , V_4 -> V_9 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_7 ;
V_7 = V_2 -> V_10 * V_4 -> V_9 ;
F_3 ( V_7 , V_4 -> V_5 + V_11 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_12 = 0 ;
if ( V_4 -> V_12 == V_13 )
V_12 = V_14 ;
F_3 ( V_15 | V_12 , V_4 -> V_5 + V_16 ) ;
F_7 ( V_2 ) ;
F_1 ( V_2 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_10 ( V_4 -> V_17 ) ;
F_11 ( V_4 -> V_17 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 , unsigned int V_18 )
{
V_2 -> V_10 = V_18 ;
F_7 ( V_2 ) ;
return 0 ;
}
static void F_13 ( struct V_3 * V_4 )
{
F_3 ( V_15 | V_14 , V_4 -> V_5 + V_16 ) ;
F_3 ( 0xff , V_4 -> V_5 + V_11 ) ;
F_1 ( & V_4 -> V_2 ) ;
F_3 ( 0xff , V_4 -> V_5 + V_6 ) ;
F_14 ( 1000 ) ;
}
static T_2 F_15 ( int V_19 , void * V_20 )
{
struct V_3 * V_4 = V_20 ;
T_1 V_21 ;
V_21 = F_5 ( V_4 -> V_5 + V_16 ) ;
if ( ! ( V_21 & V_22 ) )
return V_23 ;
if ( V_4 -> V_12 == V_24 ) {
F_16 ( V_4 -> V_25 , L_1 ) ;
} else {
F_16 ( V_4 -> V_25 , L_2 ) ;
F_13 ( V_4 ) ;
}
return V_26 ;
}
static int F_17 ( struct V_27 * V_28 ,
unsigned long V_12 , void * V_29 )
{
struct V_3 * V_4 =
F_18 ( V_28 , struct V_3 , V_30 ) ;
F_13 ( V_4 ) ;
return V_31 ;
}
static int F_19 ( struct V_3 * V_4 )
{
int V_32 ;
unsigned long V_33 ;
V_4 -> V_33 = F_20 ( V_4 -> V_25 , L_3 ) ;
if ( F_21 ( V_4 -> V_33 ) ) {
F_22 ( V_4 -> V_25 , L_4 ) ;
return F_23 ( V_4 -> V_33 ) ;
}
V_4 -> V_34 = F_20 ( V_4 -> V_25 , L_5 ) ;
if ( F_21 ( V_4 -> V_34 ) ) {
F_22 ( V_4 -> V_25 , L_6 ) ;
return F_23 ( V_4 -> V_34 ) ;
}
V_32 = F_24 ( V_4 -> V_34 ) ;
if ( V_32 ) {
F_22 ( V_4 -> V_25 , L_7 ) ;
return V_32 ;
}
V_32 = F_25 ( V_4 -> V_33 , V_35 ) ;
if ( V_32 ) {
F_26 ( V_4 -> V_34 ) ;
F_22 ( V_4 -> V_25 , L_8 ) ;
return V_32 ;
}
V_32 = F_24 ( V_4 -> V_33 ) ;
if ( V_32 ) {
F_26 ( V_4 -> V_34 ) ;
F_22 ( V_4 -> V_25 , L_9 ) ;
return V_32 ;
}
V_33 = F_27 ( V_4 -> V_33 ) ;
if ( ! V_33 ) {
F_26 ( V_4 -> V_33 ) ;
F_26 ( V_4 -> V_34 ) ;
F_22 ( V_4 -> V_25 , L_10 ) ;
return - V_36 ;
}
V_4 -> V_9 = V_33 / 2 ;
return 0 ;
}
static void F_28 ( struct V_3 * V_4 )
{
const char * V_37 ;
int V_38 ;
V_4 -> V_12 = V_13 ;
V_38 = F_29 ( V_4 -> V_25 -> V_39 ,
L_11 , & V_37 ) ;
if ( V_38 < 0 )
return;
if ( ! strcmp ( V_37 , L_12 ) )
V_4 -> V_12 = V_13 ;
else if ( ! strcmp ( V_37 , L_13 ) )
V_4 -> V_12 = V_40 ;
else if ( ! strcmp ( V_37 , L_14 ) )
V_4 -> V_12 = V_24 ;
else
F_30 ( V_4 -> V_25 , L_15 ,
V_37 ) ;
}
static int F_31 ( struct V_41 * V_42 )
{
struct V_3 * V_4 ;
struct V_1 * V_2 ;
struct V_43 * V_44 ;
int V_38 ;
const char * const V_45 [] = { L_12 , L_13 , L_14 , } ;
V_4 = F_32 ( & V_42 -> V_25 , sizeof( struct V_3 ) ,
V_46 ) ;
if ( ! V_4 )
return - V_47 ;
V_4 -> V_25 = & V_42 -> V_25 ;
V_44 = F_33 ( V_42 , V_48 , 0 ) ;
V_4 -> V_5 = F_34 ( & V_42 -> V_25 , V_44 ) ;
if ( F_21 ( V_4 -> V_5 ) )
return F_23 ( V_4 -> V_5 ) ;
V_38 = F_19 ( V_4 ) ;
if ( V_38 )
return V_38 ;
V_4 -> V_17 = F_35 ( & V_42 -> V_25 , L_16 ) ;
if ( F_21 ( V_4 -> V_17 ) )
return F_23 ( V_4 -> V_17 ) ;
V_2 = & V_4 -> V_2 ;
V_2 -> V_49 = & V_50 ;
V_2 -> V_51 = & V_52 ;
V_2 -> V_53 = 1 ;
V_2 -> V_54 = F_36 ( V_4 -> V_9 ) ;
V_2 -> V_55 = & V_42 -> V_25 ;
F_37 ( V_2 , V_4 ) ;
V_2 -> V_10 = V_56 ;
F_38 ( V_2 , 0 , & V_42 -> V_25 ) ;
F_28 ( V_4 ) ;
if ( V_4 -> V_12 != V_13 )
V_4 -> V_19 = F_39 ( V_42 , 0 ) ;
if ( V_4 -> V_19 > 0 ) {
V_38 = F_40 ( & V_42 -> V_25 , V_4 -> V_19 ,
F_15 , 0 , V_42 -> V_57 , V_4 ) ;
if ( V_38 < 0 )
F_30 ( & V_42 -> V_25 , L_17 ) ;
}
V_38 = F_41 ( V_2 ) ;
if ( V_38 )
goto V_58;
F_42 ( V_42 , V_4 ) ;
V_4 -> V_30 . V_59 = F_17 ;
V_4 -> V_30 . V_60 = 128 ;
V_38 = F_43 ( & V_4 -> V_30 ) ;
if ( V_38 )
F_30 ( & V_42 -> V_25 , L_18 ) ;
F_16 ( & V_42 -> V_25 , L_19 ,
V_2 -> V_10 , V_45 [ V_4 -> V_12 ] ) ;
return 0 ;
V_58:
F_26 ( V_4 -> V_33 ) ;
F_26 ( V_4 -> V_34 ) ;
return V_38 ;
}
static void F_44 ( struct V_41 * V_42 )
{
struct V_3 * V_4 = F_45 ( V_42 ) ;
F_9 ( & V_4 -> V_2 ) ;
}
static int F_46 ( struct V_41 * V_42 )
{
struct V_3 * V_4 = F_45 ( V_42 ) ;
F_9 ( & V_4 -> V_2 ) ;
F_47 ( & V_4 -> V_30 ) ;
F_48 ( & V_4 -> V_2 ) ;
F_26 ( V_4 -> V_33 ) ;
F_26 ( V_4 -> V_34 ) ;
return 0 ;
}
