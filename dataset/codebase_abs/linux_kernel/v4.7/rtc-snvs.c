static T_1 F_1 ( struct V_1 * V_2 )
{
T_2 V_3 , V_4 ;
T_1 V_5 ;
do {
F_2 ( V_2 -> V_6 , V_2 -> V_7 + V_8 , & V_5 ) ;
V_3 = V_5 ;
V_3 <<= 32 ;
F_2 ( V_2 -> V_6 , V_2 -> V_7 + V_9 , & V_5 ) ;
V_3 |= V_5 ;
F_2 ( V_2 -> V_6 , V_2 -> V_7 + V_8 , & V_5 ) ;
V_4 = V_5 ;
V_4 <<= 32 ;
F_2 ( V_2 -> V_6 , V_2 -> V_7 + V_9 , & V_5 ) ;
V_4 |= V_5 ;
} while ( V_3 != V_4 );
return ( T_1 ) ( V_3 >> V_10 ) ;
}
static void F_3 ( struct V_1 * V_2 )
{
T_1 V_11 , V_12 , V_13 ;
int V_14 ;
for ( V_14 = 0 ; V_14 < 3 ; V_14 ++ ) {
do {
F_2 ( V_2 -> V_6 , V_2 -> V_7 + V_9 , & V_11 ) ;
F_2 ( V_2 -> V_6 , V_2 -> V_7 + V_9 , & V_12 ) ;
} while ( V_11 != V_12 );
do {
do {
F_2 ( V_2 -> V_6 , V_2 -> V_7 + V_9 , & V_12 ) ;
F_2 ( V_2 -> V_6 , V_2 -> V_7 + V_9 , & V_13 ) ;
} while ( V_12 != V_13 );
} while ( V_13 == V_11 );
}
}
static int F_4 ( struct V_1 * V_2 , bool V_15 )
{
int V_16 = 1000 ;
T_1 V_17 ;
F_5 ( V_2 -> V_6 , V_2 -> V_7 + V_18 , V_19 ,
V_15 ? V_19 : 0 ) ;
while ( -- V_16 ) {
F_2 ( V_2 -> V_6 , V_2 -> V_7 + V_18 , & V_17 ) ;
if ( V_15 ) {
if ( V_17 & V_19 )
break;
} else {
if ( ! ( V_17 & V_19 ) )
break;
}
}
if ( ! V_16 )
return - V_20 ;
return 0 ;
}
static int F_6 ( struct V_21 * V_22 , struct V_23 * V_24 )
{
struct V_1 * V_2 = F_7 ( V_22 ) ;
unsigned long time = F_1 ( V_2 ) ;
F_8 ( time , V_24 ) ;
return 0 ;
}
static int F_9 ( struct V_21 * V_22 , struct V_23 * V_24 )
{
struct V_1 * V_2 = F_7 ( V_22 ) ;
unsigned long time ;
F_10 ( V_24 , & time ) ;
F_4 ( V_2 , false ) ;
F_11 ( V_2 -> V_6 , V_2 -> V_7 + V_9 , time << V_10 ) ;
F_11 ( V_2 -> V_6 , V_2 -> V_7 + V_8 , time >> ( 32 - V_10 ) ) ;
F_4 ( V_2 , true ) ;
return 0 ;
}
static int F_12 ( struct V_21 * V_22 , struct V_25 * V_26 )
{
struct V_1 * V_2 = F_7 ( V_22 ) ;
T_1 V_27 , V_28 ;
F_2 ( V_2 -> V_6 , V_2 -> V_7 + V_29 , & V_27 ) ;
F_8 ( V_27 , & V_26 -> time ) ;
F_2 ( V_2 -> V_6 , V_2 -> V_7 + V_30 , & V_28 ) ;
V_26 -> V_31 = ( V_28 & V_32 ) ? 1 : 0 ;
return 0 ;
}
static int F_13 ( struct V_21 * V_22 , unsigned int V_15 )
{
struct V_1 * V_2 = F_7 ( V_22 ) ;
F_5 ( V_2 -> V_6 , V_2 -> V_7 + V_18 ,
( V_33 | V_34 ) ,
V_15 ? ( V_33 | V_34 ) : 0 ) ;
F_3 ( V_2 ) ;
return 0 ;
}
static int F_14 ( struct V_21 * V_22 , struct V_25 * V_26 )
{
struct V_1 * V_2 = F_7 ( V_22 ) ;
struct V_23 * V_35 = & V_26 -> time ;
unsigned long time ;
F_10 ( V_35 , & time ) ;
F_5 ( V_2 -> V_6 , V_2 -> V_7 + V_18 , V_33 , 0 ) ;
F_11 ( V_2 -> V_6 , V_2 -> V_7 + V_29 , time ) ;
F_11 ( V_2 -> V_6 , V_2 -> V_7 + V_30 , V_32 ) ;
return F_13 ( V_22 , V_26 -> V_36 ) ;
}
static T_3 F_15 ( int V_37 , void * V_38 )
{
struct V_21 * V_22 = V_38 ;
struct V_1 * V_2 = F_7 ( V_22 ) ;
T_1 V_28 ;
T_1 V_39 = 0 ;
F_2 ( V_2 -> V_6 , V_2 -> V_7 + V_30 , & V_28 ) ;
if ( V_28 & V_32 ) {
V_39 |= ( V_40 | V_41 ) ;
F_13 ( V_22 , 0 ) ;
F_16 ( V_2 -> V_42 , 1 , V_39 ) ;
}
F_11 ( V_2 -> V_6 , V_2 -> V_7 + V_30 , V_28 ) ;
return V_39 ? V_43 : V_44 ;
}
static int F_17 ( struct V_45 * V_46 )
{
struct V_1 * V_2 ;
struct V_47 * V_48 ;
int V_49 ;
void T_4 * V_50 ;
V_2 = F_18 ( & V_46 -> V_22 , sizeof( * V_2 ) , V_51 ) ;
if ( ! V_2 )
return - V_52 ;
V_2 -> V_6 = F_19 ( V_46 -> V_22 . V_53 , L_1 ) ;
if ( F_20 ( V_2 -> V_6 ) ) {
F_21 ( & V_46 -> V_22 , L_2 ) ;
V_48 = F_22 ( V_46 , V_54 , 0 ) ;
V_50 = F_23 ( & V_46 -> V_22 , V_48 ) ;
if ( F_20 ( V_50 ) )
return F_24 ( V_50 ) ;
V_2 -> V_6 = F_25 ( & V_46 -> V_22 , V_50 , & V_55 ) ;
} else {
V_2 -> V_7 = V_56 ;
F_26 ( V_46 -> V_22 . V_53 , L_3 , & V_2 -> V_7 ) ;
}
if ( ! V_2 -> V_6 ) {
F_27 ( & V_46 -> V_22 , L_4 ) ;
return - V_57 ;
}
V_2 -> V_37 = F_28 ( V_46 , 0 ) ;
if ( V_2 -> V_37 < 0 )
return V_2 -> V_37 ;
V_2 -> V_58 = F_29 ( & V_46 -> V_22 , L_5 ) ;
if ( F_20 ( V_2 -> V_58 ) ) {
V_2 -> V_58 = NULL ;
} else {
V_49 = F_30 ( V_2 -> V_58 ) ;
if ( V_49 ) {
F_27 ( & V_46 -> V_22 ,
L_6 ) ;
return V_49 ;
}
}
F_31 ( V_46 , V_2 ) ;
F_11 ( V_2 -> V_6 , V_2 -> V_7 + V_59 , V_60 ) ;
F_11 ( V_2 -> V_6 , V_2 -> V_7 + V_30 , 0xffffffff ) ;
F_4 ( V_2 , true ) ;
F_32 ( & V_46 -> V_22 , true ) ;
V_49 = F_33 ( & V_46 -> V_22 , V_2 -> V_37 , F_15 ,
V_61 , L_7 , & V_46 -> V_22 ) ;
if ( V_49 ) {
F_27 ( & V_46 -> V_22 , L_8 ,
V_2 -> V_37 , V_49 ) ;
goto V_62;
}
V_2 -> V_42 = F_34 ( & V_46 -> V_22 , V_46 -> V_63 ,
& V_64 , V_65 ) ;
if ( F_20 ( V_2 -> V_42 ) ) {
V_49 = F_24 ( V_2 -> V_42 ) ;
F_27 ( & V_46 -> V_22 , L_9 , V_49 ) ;
goto V_62;
}
return 0 ;
V_62:
if ( V_2 -> V_58 )
F_35 ( V_2 -> V_58 ) ;
return V_49 ;
}
static int F_36 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_7 ( V_22 ) ;
if ( F_37 ( V_22 ) )
return F_38 ( V_2 -> V_37 ) ;
return 0 ;
}
static int F_39 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_7 ( V_22 ) ;
if ( V_2 -> V_58 )
F_35 ( V_2 -> V_58 ) ;
return 0 ;
}
static int F_40 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_7 ( V_22 ) ;
if ( F_37 ( V_22 ) )
return F_41 ( V_2 -> V_37 ) ;
return 0 ;
}
static int F_42 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_7 ( V_22 ) ;
if ( V_2 -> V_58 )
return F_30 ( V_2 -> V_58 ) ;
return 0 ;
}
