static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
T_1 V_5 ;
V_5 = F_2 ( V_4 -> V_6 + V_7 ) ;
V_5 &= ~ ( V_8 | V_9 ) ;
V_5 |= V_10 ;
F_3 ( V_5 , V_4 -> V_6 + V_7 ) ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_11 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
T_1 V_12 ;
F_5 ( V_11 , V_4 -> V_6 + V_13 ) ;
F_5 ( V_14 , V_4 -> V_6 + V_15 ) ;
F_6 () ;
if ( F_7 ( V_4 -> V_6 +
V_16 ,
V_12 , ! ( V_12 & V_11 ) , 1 ,
V_17 ) ) {
F_8 ( V_2 -> V_18 ,
L_1 ,
V_12 , V_11 ) ;
return - V_19 ;
}
F_5 ( 0 , V_4 -> V_6 + V_15 ) ;
F_5 ( 0 , V_4 -> V_6 + V_13 ) ;
F_6 () ;
return 0 ;
}
static T_2 F_9 ( int V_20 , void * V_21 )
{
struct V_1 * V_2 = V_21 ;
struct V_3 * V_4 = & V_2 -> V_4 ;
T_1 V_12 ;
V_12 = F_2 ( V_4 -> V_6 + V_16 ) ;
V_12 &= V_22 ;
if ( ! V_12 )
return V_23 ;
if ( V_12 & V_24 ) {
int V_25 ;
V_25 = F_10 ( & V_4 -> V_26 ) ;
if ( V_25 == V_27 ) {
F_11 ( & V_2 -> V_28 ) ;
F_12 ( & V_4 -> V_26 , 0 ) ;
}
} else {
F_12 ( & V_4 -> V_26 , 0 ) ;
}
if ( F_4 ( V_2 , V_12 ) ) {
F_13 ( V_2 -> V_18 , L_2 ) ;
F_11 ( & V_2 -> V_28 ) ;
}
return V_23 ;
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
T_1 V_5 ;
V_5 = F_2 ( V_4 -> V_6 + V_29 ) ;
F_3 ( ( ( V_5 & ~ V_30 ) | V_30 ) , V_4 -> V_6 +
V_29 ) ;
F_15 ( 50 ) ;
V_5 = F_2 ( V_4 -> V_6 + V_29 ) ;
F_3 ( ( V_5 & ~ V_30 ) , V_4 -> V_6 + V_29 ) ;
F_15 ( 50 ) ;
}
void F_16 ( struct V_1 * V_2 )
{
int V_31 ;
F_14 ( V_2 ) ;
F_1 ( V_2 ) ;
V_31 = V_2 -> V_4 . V_32 ( V_2 ) ;
if ( V_31 )
F_8 ( V_2 -> V_18 ,
L_3 ,
V_31 ) ;
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_3 * V_33 = & V_2 -> V_4 ;
int V_31 ;
if ( V_33 -> V_20 ) {
V_31 = F_4 ( V_2 , 0xff ) ;
if ( V_31 )
return V_31 ;
F_3 ( 0 , V_33 -> V_6 + V_34 ) ;
V_31 = F_18 ( V_33 -> V_20 , F_9 , 0 ,
L_4 , V_2 ) ;
if ( V_31 ) {
F_8 ( V_2 -> V_18 ,
L_5 ) ;
return V_31 ;
}
}
return 0 ;
}
static int F_19 ( struct V_1 * V_2 )
{
struct V_3 * V_33 = & V_2 -> V_4 ;
F_3 ( 0 , V_33 -> V_6 + V_34 ) ;
F_20 ( V_33 -> V_20 , V_2 ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 )
{
struct V_3 * V_33 = & V_2 -> V_4 ;
int V_31 ;
V_31 = F_4 ( V_2 , 0xff ) ;
if ( V_31 )
return V_31 ;
F_3 ( V_22 , V_33 -> V_6 + V_34 ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_3 * V_33 = & V_2 -> V_4 ;
F_3 ( 0 , V_33 -> V_6 + V_34 ) ;
F_23 ( V_33 -> V_20 ) ;
return 0 ;
}
static int F_24 ( struct V_35 * V_36 , void * V_21 )
{
#ifdef F_25
static const struct V_37 V_38 [] = {
{
. V_39 = L_6 ,
} ,
{}
} ;
const struct V_37 * V_39 = F_26 ( V_38 , V_36 ) ;
T_3 * V_32 = V_21 ;
if ( V_39 ) {
T_4 V_40 = F_27 ( V_36 ) ;
unsigned long long V_41 ;
T_5 V_12 ;
V_12 = F_28 ( V_40 , L_7 , NULL , & V_41 ) ;
if ( V_12 ) {
if ( V_12 == V_42 )
V_41 = 1 ;
else
return 0 ;
}
switch ( V_41 ) {
case 1 :
* V_32 = V_43 ;
return 1 ;
case 2 :
* V_32 = V_44 ;
return 1 ;
}
}
#endif
return 0 ;
}
int F_29 ( struct V_45 * V_46 , struct V_1 * V_2 )
{
struct V_45 * V_47 = NULL ;
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_48 * V_49 ;
int V_31 ;
if ( F_30 ( & V_46 -> V_36 ) ) {
struct V_35 * V_36 ;
V_36 = F_31 ( & V_46 -> V_36 , & V_4 -> V_32 ,
F_24 ) ;
if ( ! V_36 ) {
F_32 ( & V_46 -> V_36 , L_8 ) ;
return - V_50 ;
}
V_47 = F_33 ( V_36 ) ;
} else {
const struct V_51 * V_52 ;
struct V_53 * V_54 ;
V_54 = F_34 ( V_46 -> V_36 . V_55 , L_9 , 0 ) ;
if ( ! V_54 ) {
F_32 ( & V_46 -> V_36 , L_10 ) ;
return - V_50 ;
}
V_47 = F_35 ( V_54 ) ;
if ( ! V_47 ) {
F_32 ( & V_46 -> V_36 , L_11 ) ;
return - V_50 ;
}
V_52 = F_36 ( V_56 , & V_47 -> V_36 ) ;
if ( ! V_52 ) {
F_32 ( & V_46 -> V_36 , L_12 ) ;
V_31 = - V_50 ;
goto V_57;
}
V_4 -> V_32 = ( T_3 ) V_52 -> V_21 ;
}
V_4 -> V_58 = F_17 ;
V_4 -> V_59 = F_19 ;
V_4 -> V_60 = F_21 ;
V_4 -> V_61 = F_22 ;
V_49 = F_37 ( V_47 , V_62 , 0 ) ;
if ( ! V_49 ) {
V_31 = - V_63 ;
goto V_57;
}
V_4 -> V_6 = F_38 ( V_49 -> V_64 , F_39 ( V_49 ) ) ;
if ( ! V_4 -> V_6 ) {
V_31 = - V_65 ;
goto V_57;
}
V_49 = F_37 ( V_47 , V_62 , 1 ) ;
if ( V_49 ) {
V_4 -> V_66 = F_38 ( V_49 -> V_64 , F_39 ( V_49 ) ) ;
if ( ! V_4 -> V_66 ) {
V_31 = - V_65 ;
goto V_67;
}
}
V_31 = V_4 -> V_32 ( V_2 ) ;
if ( V_31 )
goto error;
F_1 ( V_2 ) ;
V_31 = F_40 ( V_47 , 0 ) ;
if ( V_31 > 0 )
V_4 -> V_20 = V_31 ;
F_41 ( & V_47 -> V_36 ) ;
return 0 ;
error:
if ( V_4 -> V_66 )
F_42 ( V_4 -> V_66 ) ;
V_67:
F_42 ( V_4 -> V_6 ) ;
V_57:
F_41 ( & V_47 -> V_36 ) ;
return V_31 ;
}
