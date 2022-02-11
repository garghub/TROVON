static T_1 F_1 ( void T_2 * V_1 )
{
T_3 V_2 , V_3 ;
do {
V_2 = F_2 ( V_1 + V_4 ) ;
V_2 <<= 32 ;
V_2 |= F_2 ( V_1 + V_5 ) ;
V_3 = F_2 ( V_1 + V_4 ) ;
V_3 <<= 32 ;
V_3 |= F_2 ( V_1 + V_5 ) ;
} while ( V_2 != V_3 );
return ( T_1 ) ( V_2 >> V_6 ) ;
}
static void F_3 ( void T_2 * V_1 )
{
T_1 V_7 , V_8 , V_9 ;
int V_10 ;
for ( V_10 = 0 ; V_10 < 3 ; V_10 ++ ) {
do {
V_7 = F_2 ( V_1 + V_5 ) ;
V_8 = F_2 ( V_1 + V_5 ) ;
} while ( V_7 != V_8 );
do {
do {
V_8 = F_2 ( V_1 + V_5 ) ;
V_9 = F_2 ( V_1 + V_5 ) ;
} while ( V_8 != V_9 );
} while ( V_9 == V_7 );
}
}
static int F_4 ( struct V_11 * V_12 , bool V_13 )
{
unsigned long V_14 ;
int V_15 = 1000 ;
T_1 V_16 ;
F_5 ( & V_12 -> V_17 , V_14 ) ;
V_16 = F_2 ( V_12 -> V_1 + V_18 ) ;
if ( V_13 )
V_16 |= V_19 ;
else
V_16 &= ~ V_19 ;
F_6 ( V_16 , V_12 -> V_1 + V_18 ) ;
F_7 ( & V_12 -> V_17 , V_14 ) ;
while ( -- V_15 ) {
V_16 = F_2 ( V_12 -> V_1 + V_18 ) ;
if ( V_13 ) {
if ( V_16 & V_19 )
break;
} else {
if ( ! ( V_16 & V_19 ) )
break;
}
}
if ( ! V_15 )
return - V_20 ;
return 0 ;
}
static int F_8 ( struct V_21 * V_22 , struct V_23 * V_24 )
{
struct V_11 * V_12 = F_9 ( V_22 ) ;
unsigned long time = F_1 ( V_12 -> V_1 ) ;
F_10 ( time , V_24 ) ;
return 0 ;
}
static int F_11 ( struct V_21 * V_22 , struct V_23 * V_24 )
{
struct V_11 * V_12 = F_9 ( V_22 ) ;
unsigned long time ;
F_12 ( V_24 , & time ) ;
F_4 ( V_12 , false ) ;
F_6 ( time << V_6 , V_12 -> V_1 + V_5 ) ;
F_6 ( time >> ( 32 - V_6 ) , V_12 -> V_1 + V_4 ) ;
F_4 ( V_12 , true ) ;
return 0 ;
}
static int F_13 ( struct V_21 * V_22 , struct V_25 * V_26 )
{
struct V_11 * V_12 = F_9 ( V_22 ) ;
T_1 V_27 , V_28 ;
V_27 = F_2 ( V_12 -> V_1 + V_29 ) ;
F_10 ( V_27 , & V_26 -> time ) ;
V_28 = F_2 ( V_12 -> V_1 + V_30 ) ;
V_26 -> V_31 = ( V_28 & V_32 ) ? 1 : 0 ;
return 0 ;
}
static int F_14 ( struct V_21 * V_22 , unsigned int V_13 )
{
struct V_11 * V_12 = F_9 ( V_22 ) ;
T_1 V_16 ;
unsigned long V_14 ;
F_5 ( & V_12 -> V_17 , V_14 ) ;
V_16 = F_2 ( V_12 -> V_1 + V_18 ) ;
if ( V_13 )
V_16 |= ( V_33 | V_34 ) ;
else
V_16 &= ~ ( V_33 | V_34 ) ;
F_6 ( V_16 , V_12 -> V_1 + V_18 ) ;
F_7 ( & V_12 -> V_17 , V_14 ) ;
F_3 ( V_12 -> V_1 ) ;
return 0 ;
}
static int F_15 ( struct V_21 * V_22 , struct V_25 * V_26 )
{
struct V_11 * V_12 = F_9 ( V_22 ) ;
struct V_23 * V_35 = & V_26 -> time ;
unsigned long time ;
unsigned long V_14 ;
T_1 V_16 ;
F_12 ( V_35 , & time ) ;
F_5 ( & V_12 -> V_17 , V_14 ) ;
V_16 = F_2 ( V_12 -> V_1 + V_18 ) ;
V_16 &= ~ V_33 ;
F_6 ( V_16 , V_12 -> V_1 + V_18 ) ;
F_7 ( & V_12 -> V_17 , V_14 ) ;
F_6 ( time , V_12 -> V_1 + V_29 ) ;
F_6 ( V_32 , V_12 -> V_1 + V_30 ) ;
return F_14 ( V_22 , V_26 -> V_36 ) ;
}
static T_4 F_16 ( int V_37 , void * V_38 )
{
struct V_21 * V_22 = V_38 ;
struct V_11 * V_12 = F_9 ( V_22 ) ;
T_1 V_28 ;
T_1 V_39 = 0 ;
V_28 = F_2 ( V_12 -> V_1 + V_30 ) ;
if ( V_28 & V_32 ) {
V_39 |= ( V_40 | V_41 ) ;
F_14 ( V_22 , 0 ) ;
F_17 ( V_12 -> V_42 , 1 , V_39 ) ;
}
F_6 ( V_28 , V_12 -> V_1 + V_30 ) ;
return V_39 ? V_43 : V_44 ;
}
static int F_18 ( struct V_45 * V_46 )
{
struct V_11 * V_12 ;
struct V_47 * V_48 ;
int V_49 ;
V_12 = F_19 ( & V_46 -> V_22 , sizeof( * V_12 ) , V_50 ) ;
if ( ! V_12 )
return - V_51 ;
V_48 = F_20 ( V_46 , V_52 , 0 ) ;
V_12 -> V_1 = F_21 ( & V_46 -> V_22 , V_48 ) ;
if ( ! V_12 -> V_1 )
return - V_53 ;
V_12 -> V_37 = F_22 ( V_46 , 0 ) ;
if ( V_12 -> V_37 < 0 )
return V_12 -> V_37 ;
F_23 ( V_46 , V_12 ) ;
F_24 ( & V_12 -> V_17 ) ;
F_6 ( V_54 , V_12 -> V_1 + V_55 ) ;
F_6 ( 0xffffffff , V_12 -> V_1 + V_30 ) ;
F_4 ( V_12 , true ) ;
F_25 ( & V_46 -> V_22 , true ) ;
V_49 = F_26 ( & V_46 -> V_22 , V_12 -> V_37 , F_16 ,
V_56 , L_1 , & V_46 -> V_22 ) ;
if ( V_49 ) {
F_27 ( & V_46 -> V_22 , L_2 ,
V_12 -> V_37 , V_49 ) ;
return V_49 ;
}
V_12 -> V_42 = F_28 ( V_46 -> V_57 , & V_46 -> V_22 ,
& V_58 , V_59 ) ;
if ( F_29 ( V_12 -> V_42 ) ) {
V_49 = F_30 ( V_12 -> V_42 ) ;
F_27 ( & V_46 -> V_22 , L_3 , V_49 ) ;
return V_49 ;
}
return 0 ;
}
static int F_31 ( struct V_45 * V_46 )
{
struct V_11 * V_12 = F_32 ( V_46 ) ;
F_33 ( V_12 -> V_42 ) ;
return 0 ;
}
static int F_34 ( struct V_21 * V_22 )
{
struct V_11 * V_12 = F_9 ( V_22 ) ;
if ( F_35 ( V_22 ) )
F_36 ( V_12 -> V_37 ) ;
return 0 ;
}
static int F_37 ( struct V_21 * V_22 )
{
struct V_11 * V_12 = F_9 ( V_22 ) ;
if ( F_35 ( V_22 ) )
F_38 ( V_12 -> V_37 ) ;
return 0 ;
}
