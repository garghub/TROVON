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
return V_7 / V_4 -> V_9 ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_7 ;
V_7 = V_2 -> V_10 * V_4 -> V_9 ;
F_3 ( V_7 , V_4 -> V_5 + V_11 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_12 = 0 ;
if ( V_4 -> V_12 == V_13 )
V_12 = V_14 ;
F_3 ( V_15 | V_12 , V_4 -> V_5 + V_16 ) ;
F_6 ( V_2 ) ;
F_1 ( V_2 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_9 ( V_4 -> V_17 ) ;
F_10 ( V_4 -> V_17 ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 , unsigned int V_18 )
{
V_2 -> V_10 = V_18 ;
F_6 ( V_2 ) ;
return 0 ;
}
static void F_12 ( struct V_3 * V_4 )
{
F_3 ( V_15 | V_14 , V_4 -> V_5 + V_16 ) ;
F_3 ( 0xff , V_4 -> V_5 + V_11 ) ;
F_1 ( & V_4 -> V_2 ) ;
F_3 ( 0xff , V_4 -> V_5 + V_6 ) ;
F_13 ( 1000 ) ;
}
static T_2 F_14 ( int V_19 , void * V_20 )
{
struct V_3 * V_4 = V_20 ;
T_1 V_21 ;
V_21 = F_5 ( V_4 -> V_5 + V_16 ) ;
if ( ! ( V_21 & V_22 ) )
return V_23 ;
if ( V_4 -> V_12 == V_24 ) {
F_15 ( V_4 -> V_25 , L_1 ) ;
} else {
F_15 ( V_4 -> V_25 , L_2 ) ;
F_12 ( V_4 ) ;
}
return V_26 ;
}
static int F_16 ( struct V_1 * V_2 , unsigned long V_27 ,
void * V_28 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_12 ( V_4 ) ;
return 0 ;
}
static int F_17 ( struct V_3 * V_4 )
{
int V_29 ;
unsigned long V_30 ;
V_4 -> V_30 = F_18 ( V_4 -> V_25 , L_3 ) ;
if ( F_19 ( V_4 -> V_30 ) ) {
F_20 ( V_4 -> V_25 , L_4 ) ;
return F_21 ( V_4 -> V_30 ) ;
}
V_4 -> V_31 = F_18 ( V_4 -> V_25 , L_5 ) ;
if ( F_19 ( V_4 -> V_31 ) ) {
F_20 ( V_4 -> V_25 , L_6 ) ;
return F_21 ( V_4 -> V_31 ) ;
}
V_29 = F_22 ( V_4 -> V_31 ) ;
if ( V_29 ) {
F_20 ( V_4 -> V_25 , L_7 ) ;
return V_29 ;
}
V_29 = F_23 ( V_4 -> V_30 , V_32 ) ;
if ( V_29 ) {
F_24 ( V_4 -> V_31 ) ;
F_20 ( V_4 -> V_25 , L_8 ) ;
return V_29 ;
}
V_29 = F_22 ( V_4 -> V_30 ) ;
if ( V_29 ) {
F_24 ( V_4 -> V_31 ) ;
F_20 ( V_4 -> V_25 , L_9 ) ;
return V_29 ;
}
V_30 = F_25 ( V_4 -> V_30 ) ;
if ( ! V_30 ) {
F_24 ( V_4 -> V_30 ) ;
F_24 ( V_4 -> V_31 ) ;
F_20 ( V_4 -> V_25 , L_10 ) ;
return - V_33 ;
}
V_4 -> V_9 = V_30 / 2 ;
return 0 ;
}
static void F_26 ( struct V_3 * V_4 )
{
const char * V_34 ;
int V_35 ;
V_4 -> V_12 = V_13 ;
V_35 = F_27 ( V_4 -> V_25 -> V_36 ,
L_11 , & V_34 ) ;
if ( V_35 < 0 )
return;
if ( ! strcmp ( V_34 , L_12 ) )
V_4 -> V_12 = V_13 ;
else if ( ! strcmp ( V_34 , L_13 ) )
V_4 -> V_12 = V_37 ;
else if ( ! strcmp ( V_34 , L_14 ) )
V_4 -> V_12 = V_24 ;
else
F_28 ( V_4 -> V_25 , L_15 ,
V_34 ) ;
}
static int F_29 ( struct V_38 * V_39 )
{
struct V_3 * V_4 ;
struct V_1 * V_2 ;
struct V_40 * V_41 ;
int V_35 ;
const char * const V_42 [] = { L_12 , L_13 , L_14 , } ;
V_4 = F_30 ( & V_39 -> V_25 , sizeof( struct V_3 ) ,
V_43 ) ;
if ( ! V_4 )
return - V_44 ;
V_4 -> V_25 = & V_39 -> V_25 ;
V_41 = F_31 ( V_39 , V_45 , 0 ) ;
V_4 -> V_5 = F_32 ( & V_39 -> V_25 , V_41 ) ;
if ( F_19 ( V_4 -> V_5 ) )
return F_21 ( V_4 -> V_5 ) ;
V_35 = F_17 ( V_4 ) ;
if ( V_35 )
return V_35 ;
V_4 -> V_17 = F_33 ( & V_39 -> V_25 , L_16 ) ;
if ( F_19 ( V_4 -> V_17 ) )
return F_21 ( V_4 -> V_17 ) ;
V_2 = & V_4 -> V_2 ;
V_2 -> V_46 = & V_47 ;
V_2 -> V_48 = & V_49 ;
V_2 -> V_50 = 1 ;
V_2 -> V_51 = F_34 ( V_4 -> V_9 ) ;
V_2 -> V_52 = & V_39 -> V_25 ;
F_35 ( V_2 , V_4 ) ;
V_2 -> V_10 = V_53 ;
F_36 ( V_2 , 0 , & V_39 -> V_25 ) ;
F_26 ( V_4 ) ;
if ( V_4 -> V_12 != V_13 )
V_4 -> V_19 = F_37 ( V_39 , 0 ) ;
if ( V_4 -> V_19 > 0 ) {
V_35 = F_38 ( & V_39 -> V_25 , V_4 -> V_19 ,
F_14 , 0 , V_39 -> V_54 , V_4 ) ;
if ( V_35 < 0 )
F_28 ( & V_39 -> V_25 , L_17 ) ;
}
F_39 ( V_2 , 128 ) ;
V_35 = F_40 ( V_2 ) ;
if ( V_35 )
goto V_55;
F_41 ( V_39 , V_4 ) ;
F_15 ( & V_39 -> V_25 , L_18 ,
V_2 -> V_10 , V_42 [ V_4 -> V_12 ] ) ;
return 0 ;
V_55:
F_24 ( V_4 -> V_30 ) ;
F_24 ( V_4 -> V_31 ) ;
return V_35 ;
}
static void F_42 ( struct V_38 * V_39 )
{
struct V_3 * V_4 = F_43 ( V_39 ) ;
F_8 ( & V_4 -> V_2 ) ;
}
static int F_44 ( struct V_38 * V_39 )
{
struct V_3 * V_4 = F_43 ( V_39 ) ;
F_8 ( & V_4 -> V_2 ) ;
F_45 ( & V_4 -> V_2 ) ;
F_24 ( V_4 -> V_30 ) ;
F_24 ( V_4 -> V_31 ) ;
return 0 ;
}
