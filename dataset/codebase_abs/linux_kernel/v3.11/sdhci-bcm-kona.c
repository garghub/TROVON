static int F_1 ( struct V_1 * V_2 )
{
unsigned int V_3 ;
unsigned long V_4 ;
V_4 = V_5 + F_2 ( 100 ) ;
V_3 = F_3 ( V_2 , V_6 ) ;
V_3 |= V_7 ;
F_4 ( V_2 , V_3 , V_6 ) ;
while ( ! ( F_3 ( V_2 , V_6 ) & V_7 ) ) {
if ( F_5 ( V_4 ) ) {
F_6 ( L_1 ) ;
return - V_8 ;
}
}
V_3 = F_3 ( V_2 , V_6 ) ;
V_3 &= ~ V_7 ;
F_7 ( 1000 , 5000 ) ;
F_4 ( V_2 , V_3 , V_6 ) ;
return 0 ;
}
static void F_8 ( struct V_1 * V_2 )
{
unsigned int V_3 ;
V_3 = F_3 ( V_2 , V_9 ) ;
V_3 |= V_10 ;
F_4 ( V_2 , V_3 , V_9 ) ;
V_3 = F_3 ( V_2 , V_6 ) ;
V_3 |= V_11 ;
F_7 ( 1000 , 5000 ) ;
F_4 ( V_2 , V_3 , V_6 ) ;
}
static int F_9 ( struct V_1 * V_2 , int V_12 )
{
struct V_13 * V_14 = F_10 ( V_2 ) ;
struct V_15 * V_16 = F_11 ( V_14 ) ;
T_1 V_3 ;
F_12 ( & V_16 -> V_17 ) ;
F_13 ( 20 ) ;
V_3 = F_3 ( V_2 , V_18 ) ;
if ( V_12 ) {
int V_19 ;
V_19 = F_14 ( V_2 -> V_20 ) ;
if ( V_19 >= 0 )
V_3 = ( V_3 & ~ V_21 ) |
( ( V_19 ) ? V_21 : 0 ) ;
V_3 |= V_22 ;
F_4 ( V_2 , V_3 , V_18 ) ;
} else {
V_3 &= ~ V_22 ;
F_4 ( V_2 , V_3 , V_18 ) ;
}
F_15 ( & V_16 -> V_17 ) ;
return 0 ;
}
void F_16 ( struct V_1 * V_2 )
{
if ( F_17 ( V_2 -> V_20 ) > 0 ) {
F_18 ( F_19 ( V_2 -> V_20 ) ,
L_2 ) ;
F_9 ( V_2 , 1 ) ;
} else {
F_18 ( F_19 ( V_2 -> V_20 ) ,
L_3 ) ;
F_9 ( V_2 , 0 ) ;
}
}
static unsigned int F_20 ( struct V_1 * V_2 )
{
struct V_15 * V_16 ;
struct V_13 * V_14 = F_10 ( V_2 ) ;
V_16 = F_11 ( V_14 ) ;
return V_2 -> V_20 -> V_23 ;
}
static unsigned int F_21 ( struct V_1 * V_2 )
{
return F_20 ( V_2 ) ;
}
static void F_22 ( struct V_1 * V_2 ,
T_2 V_24 )
{
if ( V_24 != V_25 )
F_13 ( 740 ) ;
}
static int T_3 F_23 ( struct V_26 * V_27 )
{
struct V_15 * V_16 = NULL ;
struct V_13 * V_14 ;
struct V_28 * V_29 = & V_27 -> V_29 ;
struct V_1 * V_2 ;
int V_19 ;
V_19 = 0 ;
V_2 = F_24 ( V_27 , & V_30 ,
sizeof( * V_16 ) ) ;
if ( F_25 ( V_2 ) )
return F_26 ( V_2 ) ;
F_18 ( V_29 , L_4 , V_31 , V_2 -> V_32 ) ;
V_14 = F_10 ( V_2 ) ;
V_16 = F_11 ( V_14 ) ;
F_27 ( & V_16 -> V_17 ) ;
F_28 ( V_2 -> V_20 ) ;
if ( ! V_2 -> V_20 -> V_23 ) {
F_29 ( & V_27 -> V_29 , L_5 ) ;
V_19 = - V_33 ;
goto V_34;
}
F_18 ( V_29 , L_6 ,
( V_2 -> V_20 -> V_35 & V_36 ) ? 'Y' : 'N' ) ;
F_18 ( V_29 , L_7 ,
( F_17 ( V_2 -> V_20 ) != - V_37 ) ? 'Y' : 'N' ,
( F_14 ( V_2 -> V_20 ) != - V_37 ) ? 'Y' : 'N' ) ;
if ( V_2 -> V_20 -> V_35 | V_36 )
V_2 -> V_38 |= V_39 ;
F_18 ( V_29 , L_8 ,
( V_2 -> V_20 -> V_35 | V_40 ) ? 'Y' : 'N' ) ;
V_19 = F_1 ( V_2 ) ;
if ( V_19 )
goto V_34;
F_8 ( V_2 ) ;
V_19 = F_30 ( V_2 ) ;
if ( V_19 ) {
F_29 ( V_29 , L_9 ) ;
goto V_41;
}
if ( V_2 -> V_20 -> V_35 | V_36 ) {
V_19 = F_9 ( V_2 , 1 ) ;
if ( V_19 ) {
F_29 ( V_29 ,
L_10 ) ;
goto V_42;
}
}
if ( F_17 ( V_2 -> V_20 ) > 0 )
F_9 ( V_2 , 1 ) ;
F_18 ( V_29 , L_11 ) ;
return 0 ;
V_42:
F_31 ( V_2 , 0 ) ;
V_41:
F_1 ( V_2 ) ;
V_34:
F_32 ( V_27 ) ;
F_29 ( V_29 , L_12 , V_19 ) ;
return V_19 ;
}
static int T_4 F_33 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_34 ( V_27 ) ;
int V_43 ;
T_1 V_44 ;
V_43 = 0 ;
V_44 = F_35 ( V_2 -> V_32 + V_45 ) ;
if ( V_44 == ( T_1 ) - 1 )
V_43 = 1 ;
F_31 ( V_2 , V_43 ) ;
F_36 ( V_2 ) ;
return 0 ;
}
