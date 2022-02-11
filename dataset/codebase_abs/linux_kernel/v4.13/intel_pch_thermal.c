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
V_14 = F_7 ( V_2 -> V_16 + V_20 ) ;
if ( V_14 & V_21 ) {
F_8 ( & V_2 -> V_7 -> V_8 , L_2 ) ;
return - V_22 ;
}
F_9 ( V_14 | V_23 , V_2 -> V_16 + V_20 ) ;
if ( ! ( V_15 & F_7 ( V_2 -> V_16 + V_17 ) ) ) {
F_8 ( & V_2 -> V_7 -> V_8 , L_2 ) ;
return - V_22 ;
}
V_19:
V_2 -> V_24 = - 1 ;
V_12 = F_10 ( V_2 -> V_16 + V_25 ) ;
V_12 &= 0x1FF ;
if ( V_12 ) {
V_2 -> V_26 = V_12 * 1000 / 2 - 50000 ;
V_2 -> V_24 = 0 ;
++ ( * V_3 ) ;
}
V_2 -> V_27 = - 1 ;
V_12 = F_10 ( V_2 -> V_16 + V_28 ) ;
V_12 &= 0x1FF ;
if ( V_12 ) {
V_2 -> V_29 = V_12 * 1000 / 2 - 50000 ;
V_2 -> V_27 = * V_3 ;
++ ( * V_3 ) ;
}
F_1 ( V_2 , V_3 ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 , int * V_30 )
{
T_2 V_31 ;
V_31 = V_32 & F_12 ( V_2 -> V_16 + V_33 ) ;
* V_30 = ( V_31 * 1000 / 2 - 50000 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
T_2 V_14 ;
if ( V_2 -> V_18 )
return 0 ;
V_14 = F_7 ( V_2 -> V_16 + V_20 ) ;
F_9 ( V_14 & 0xFE , V_2 -> V_16 + V_20 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 )
{
T_2 V_14 ;
if ( V_2 -> V_18 )
return 0 ;
V_14 = F_7 ( V_2 -> V_16 + V_20 ) ;
F_9 ( V_14 | V_23 , V_2 -> V_16 + V_20 ) ;
return 0 ;
}
static int F_15 ( struct V_34 * V_35 , int * V_30 )
{
struct V_1 * V_2 = V_35 -> V_36 ;
return V_2 -> V_37 -> V_38 ( V_2 , V_30 ) ;
}
static int F_16 ( struct V_34 * V_35 , int V_39 ,
enum V_40 * type )
{
struct V_1 * V_2 = V_35 -> V_36 ;
if ( V_2 -> V_24 == V_39 )
* type = V_41 ;
else if ( V_2 -> V_27 == V_39 )
* type = V_42 ;
else if ( V_2 -> V_6 == V_39 )
* type = V_43 ;
else
return - V_44 ;
return 0 ;
}
static int F_17 ( struct V_34 * V_35 , int V_39 , int * V_30 )
{
struct V_1 * V_2 = V_35 -> V_36 ;
if ( V_2 -> V_24 == V_39 )
* V_30 = V_2 -> V_26 ;
else if ( V_2 -> V_27 == V_39 )
* V_30 = V_2 -> V_29 ;
else if ( V_2 -> V_6 == V_39 )
* V_30 = V_2 -> V_13 ;
else
return - V_44 ;
return 0 ;
}
static int F_18 ( struct V_45 * V_7 ,
const struct V_46 * V_47 )
{
enum V_48 V_49 = V_47 -> V_50 ;
const struct V_51 * V_52 = & V_51 [ V_49 ] ;
struct V_1 * V_2 ;
int V_53 ;
int V_3 ;
V_2 = F_19 ( & V_7 -> V_8 , sizeof( * V_2 ) , V_54 ) ;
if ( ! V_2 )
return - V_55 ;
V_2 -> V_37 = V_52 -> V_37 ;
F_20 ( V_7 , V_2 ) ;
V_2 -> V_7 = V_7 ;
V_53 = F_21 ( V_7 ) ;
if ( V_53 ) {
F_8 ( & V_7 -> V_8 , L_3 ) ;
return V_53 ;
}
V_53 = F_22 ( V_7 , V_56 ) ;
if ( V_53 ) {
F_8 ( & V_7 -> V_8 , L_4 ) ;
goto V_57;
}
V_2 -> V_16 = F_23 ( V_7 , 0 ) ;
if ( ! V_2 -> V_16 ) {
V_53 = - V_55 ;
F_8 ( & V_7 -> V_8 , L_5 ) ;
goto V_58;
}
V_53 = V_2 -> V_37 -> V_59 ( V_2 , & V_3 ) ;
if ( V_53 )
goto V_60;
V_2 -> V_35 = F_24 ( V_52 -> V_61 , V_3 , 0 , V_2 ,
& V_62 , NULL , 0 , 0 ) ;
if ( F_25 ( V_2 -> V_35 ) ) {
F_8 ( & V_7 -> V_8 , L_6 ,
V_52 -> V_61 ) ;
V_53 = F_26 ( V_2 -> V_35 ) ;
goto V_60;
}
return 0 ;
V_60:
F_27 ( V_2 -> V_16 ) ;
V_58:
F_28 ( V_7 ) ;
V_57:
F_29 ( V_7 ) ;
F_8 ( & V_7 -> V_8 , L_7 ) ;
return V_53 ;
}
static void F_30 ( struct V_45 * V_7 )
{
struct V_1 * V_2 = F_31 ( V_7 ) ;
F_32 ( V_2 -> V_35 ) ;
F_27 ( V_2 -> V_16 ) ;
F_20 ( V_7 , NULL ) ;
F_33 ( V_7 , 0 ) ;
F_29 ( V_7 ) ;
}
static int F_34 ( struct V_63 * V_63 )
{
struct V_45 * V_7 = F_35 ( V_63 ) ;
struct V_1 * V_2 = F_31 ( V_7 ) ;
return V_2 -> V_37 -> V_64 ( V_2 ) ;
}
static int F_36 ( struct V_63 * V_63 )
{
struct V_45 * V_7 = F_35 ( V_63 ) ;
struct V_1 * V_2 = F_31 ( V_7 ) ;
return V_2 -> V_37 -> V_65 ( V_2 ) ;
}
