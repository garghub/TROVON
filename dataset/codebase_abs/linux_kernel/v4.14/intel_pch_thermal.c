static void F_1 ( struct V_1 * V_2 ,
int * V_3 )
{
struct V_4 * V_5 ;
V_2 -> V_6 = - 1 ;
V_5 = F_2 ( & V_2 -> V_7 -> V_8 ) ;
if ( V_5 ) {
unsigned long long V_9 ;
T_1 V_10 ;
V_10 = F_3 ( V_5 -> V_11 , L_1 , NULL ,
& V_9 ) ;
if ( F_4 ( V_10 ) ) {
unsigned long V_12 ;
V_12 = F_5 ( V_9 ) ;
if ( V_12 ) {
V_2 -> V_13 = V_12 ;
V_2 -> V_6 = * V_3 ;
++ ( * V_3 ) ;
}
}
}
}
static void F_1 ( struct V_1 * V_2 ,
int * V_3 )
{
V_2 -> V_6 = - 1 ;
}
static int F_6 ( struct V_1 * V_2 , int * V_3 )
{
T_2 V_14 ;
T_3 V_12 ;
* V_3 = 0 ;
if ( V_15 & F_7 ( V_2 -> V_16 + V_17 ) ) {
V_2 -> V_18 = true ;
goto V_19;
}
V_14 = F_7 ( V_2 -> V_16 + V_17 ) ;
if ( V_14 & V_20 ) {
F_8 ( & V_2 -> V_7 -> V_8 , L_2 ) ;
return - V_21 ;
}
F_9 ( V_14 | V_15 , V_2 -> V_16 + V_17 ) ;
if ( ! ( V_15 & F_7 ( V_2 -> V_16 + V_17 ) ) ) {
F_8 ( & V_2 -> V_7 -> V_8 , L_2 ) ;
return - V_21 ;
}
V_19:
V_2 -> V_22 = - 1 ;
V_12 = F_10 ( V_2 -> V_16 + V_23 ) ;
V_12 &= 0x1FF ;
if ( V_12 ) {
V_2 -> V_24 = V_12 * 1000 / 2 - 50000 ;
V_2 -> V_22 = 0 ;
++ ( * V_3 ) ;
}
V_2 -> V_25 = - 1 ;
V_12 = F_10 ( V_2 -> V_16 + V_26 ) ;
V_12 &= 0x1FF ;
if ( V_12 ) {
V_2 -> V_27 = V_12 * 1000 / 2 - 50000 ;
V_2 -> V_25 = * V_3 ;
++ ( * V_3 ) ;
}
F_1 ( V_2 , V_3 ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 , int * V_28 )
{
T_3 V_29 ;
V_29 = V_30 & F_10 ( V_2 -> V_16 + V_31 ) ;
* V_28 = ( V_29 * 1000 / 2 - 50000 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
T_2 V_14 ;
if ( V_2 -> V_18 )
return 0 ;
V_14 = F_7 ( V_2 -> V_16 + V_17 ) ;
F_9 ( V_14 & 0xFE , V_2 -> V_16 + V_17 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
T_2 V_14 ;
if ( V_2 -> V_18 )
return 0 ;
V_14 = F_7 ( V_2 -> V_16 + V_17 ) ;
F_9 ( V_14 | V_15 , V_2 -> V_16 + V_17 ) ;
return 0 ;
}
static int F_14 ( struct V_32 * V_33 , int * V_28 )
{
struct V_1 * V_2 = V_33 -> V_34 ;
return V_2 -> V_35 -> V_36 ( V_2 , V_28 ) ;
}
static int F_15 ( struct V_32 * V_33 , int V_37 ,
enum V_38 * type )
{
struct V_1 * V_2 = V_33 -> V_34 ;
if ( V_2 -> V_22 == V_37 )
* type = V_39 ;
else if ( V_2 -> V_25 == V_37 )
* type = V_40 ;
else if ( V_2 -> V_6 == V_37 )
* type = V_41 ;
else
return - V_42 ;
return 0 ;
}
static int F_16 ( struct V_32 * V_33 , int V_37 , int * V_28 )
{
struct V_1 * V_2 = V_33 -> V_34 ;
if ( V_2 -> V_22 == V_37 )
* V_28 = V_2 -> V_24 ;
else if ( V_2 -> V_25 == V_37 )
* V_28 = V_2 -> V_27 ;
else if ( V_2 -> V_6 == V_37 )
* V_28 = V_2 -> V_13 ;
else
return - V_42 ;
return 0 ;
}
static int F_17 ( struct V_43 * V_7 ,
const struct V_44 * V_45 )
{
enum V_46 V_47 = V_45 -> V_48 ;
const struct V_49 * V_50 = & V_49 [ V_47 ] ;
struct V_1 * V_2 ;
int V_51 ;
int V_3 ;
V_2 = F_18 ( & V_7 -> V_8 , sizeof( * V_2 ) , V_52 ) ;
if ( ! V_2 )
return - V_53 ;
V_2 -> V_35 = V_50 -> V_35 ;
F_19 ( V_7 , V_2 ) ;
V_2 -> V_7 = V_7 ;
V_51 = F_20 ( V_7 ) ;
if ( V_51 ) {
F_8 ( & V_7 -> V_8 , L_3 ) ;
return V_51 ;
}
V_51 = F_21 ( V_7 , V_54 ) ;
if ( V_51 ) {
F_8 ( & V_7 -> V_8 , L_4 ) ;
goto V_55;
}
V_2 -> V_16 = F_22 ( V_7 , 0 ) ;
if ( ! V_2 -> V_16 ) {
V_51 = - V_53 ;
F_8 ( & V_7 -> V_8 , L_5 ) ;
goto V_56;
}
V_51 = V_2 -> V_35 -> V_57 ( V_2 , & V_3 ) ;
if ( V_51 )
goto V_58;
V_2 -> V_33 = F_23 ( V_50 -> V_59 , V_3 , 0 , V_2 ,
& V_60 , NULL , 0 , 0 ) ;
if ( F_24 ( V_2 -> V_33 ) ) {
F_8 ( & V_7 -> V_8 , L_6 ,
V_50 -> V_59 ) ;
V_51 = F_25 ( V_2 -> V_33 ) ;
goto V_58;
}
return 0 ;
V_58:
F_26 ( V_2 -> V_16 ) ;
V_56:
F_27 ( V_7 ) ;
V_55:
F_28 ( V_7 ) ;
F_8 ( & V_7 -> V_8 , L_7 ) ;
return V_51 ;
}
static void F_29 ( struct V_43 * V_7 )
{
struct V_1 * V_2 = F_30 ( V_7 ) ;
F_31 ( V_2 -> V_33 ) ;
F_26 ( V_2 -> V_16 ) ;
F_19 ( V_7 , NULL ) ;
F_32 ( V_7 , 0 ) ;
F_28 ( V_7 ) ;
}
static int F_33 ( struct V_61 * V_61 )
{
struct V_43 * V_7 = F_34 ( V_61 ) ;
struct V_1 * V_2 = F_30 ( V_7 ) ;
return V_2 -> V_35 -> V_62 ( V_2 ) ;
}
static int F_35 ( struct V_61 * V_61 )
{
struct V_43 * V_7 = F_34 ( V_61 ) ;
struct V_1 * V_2 = F_30 ( V_7 ) ;
return V_2 -> V_35 -> V_63 ( V_2 ) ;
}
