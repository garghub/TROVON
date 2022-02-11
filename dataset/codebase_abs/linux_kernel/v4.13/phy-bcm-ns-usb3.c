static int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_4 )
{
return V_2 -> V_5 ( V_2 , V_3 , V_4 ) ;
}
static int F_2 ( struct V_1 * V_2 )
{
int V_6 ;
V_6 = F_1 ( V_2 , V_7 ,
V_8 ) ;
if ( V_6 < 0 )
return V_6 ;
F_1 ( V_2 , V_9 , 0x1000 ) ;
F_1 ( V_2 , V_10 , 0x6400 ) ;
F_1 ( V_2 , V_11 , 0xc000 ) ;
F_1 ( V_2 , V_11 , 0x8000 ) ;
F_3 ( 0 , V_2 -> V_12 + V_13 ) ;
F_1 ( V_2 , V_9 , 0x9000 ) ;
F_1 ( V_2 , V_7 ,
V_14 ) ;
F_1 ( V_2 , V_15 , 0xf30d ) ;
F_1 ( V_2 , V_16 , 0x6302 ) ;
F_1 ( V_2 , V_7 ,
V_17 ) ;
F_1 ( V_2 , V_18 , 0x1003 ) ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 )
{
int V_6 ;
V_6 = F_1 ( V_2 , V_7 ,
V_8 ) ;
if ( V_6 < 0 )
return V_6 ;
F_1 ( V_2 , V_10 , 0x6400 ) ;
F_1 ( V_2 , V_7 , 0x80e0 ) ;
F_1 ( V_2 , 0x02 , 0x009c ) ;
F_1 ( V_2 , V_7 ,
V_17 ) ;
F_1 ( V_2 , 0x02 , 0x21d3 ) ;
F_1 ( V_2 , V_18 , 0x1003 ) ;
F_3 ( 0 , V_2 -> V_12 + V_13 ) ;
return 0 ;
}
static int F_5 ( struct V_19 * V_19 )
{
struct V_1 * V_2 = F_6 ( V_19 ) ;
int V_6 ;
F_3 ( V_20 , V_2 -> V_12 + V_13 ) ;
switch ( V_2 -> V_21 ) {
case V_22 :
V_6 = F_4 ( V_2 ) ;
break;
case V_23 :
V_6 = F_2 ( V_2 ) ;
break;
default:
F_7 ( 1 ) ;
V_6 = - V_24 ;
}
return V_6 ;
}
static int F_8 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_4 )
{
struct V_25 * V_26 = V_2 -> V_26 ;
return F_9 ( V_26 -> V_27 , V_26 -> V_28 , V_3 , V_4 ) ;
}
static int F_10 ( struct V_25 * V_26 )
{
struct V_29 * V_30 = & V_26 -> V_30 ;
const struct V_31 * V_32 ;
struct V_33 * V_33 ;
struct V_34 * V_35 ;
struct V_1 * V_2 ;
struct V_36 V_37 ;
int V_6 ;
V_2 = F_11 ( V_30 , sizeof( * V_2 ) , V_38 ) ;
if ( ! V_2 )
return - V_39 ;
V_2 -> V_30 = V_30 ;
V_2 -> V_26 = V_26 ;
V_32 = F_12 ( V_40 , V_30 ) ;
if ( ! V_32 )
return - V_41 ;
V_2 -> V_21 = (enum V_42 ) V_32 -> V_43 ;
V_35 = F_13 ( V_30 -> V_44 , L_1 , 0 ) ;
V_6 = F_14 ( V_35 , 0 , & V_37 ) ;
F_15 ( V_35 ) ;
if ( V_6 )
return V_6 ;
V_2 -> V_12 = F_16 ( V_30 , & V_37 ) ;
if ( F_17 ( V_2 -> V_12 ) ) {
F_18 ( V_30 , L_2 ) ;
return F_19 ( V_2 -> V_12 ) ;
}
V_2 -> V_5 = F_8 ;
V_2 -> V_19 = F_20 ( V_30 , NULL , & V_45 ) ;
if ( F_17 ( V_2 -> V_19 ) ) {
F_18 ( V_30 , L_3 ) ;
return F_19 ( V_2 -> V_19 ) ;
}
F_21 ( V_2 -> V_19 , V_2 ) ;
V_33 = F_22 ( V_30 , V_46 ) ;
return F_23 ( V_33 ) ;
}
static int F_24 ( struct V_1 * V_2 , void T_2 * V_28 ,
T_3 V_47 , T_3 V_4 , unsigned long V_48 )
{
unsigned long V_49 = V_50 + V_48 ;
T_3 V_51 ;
do {
V_51 = F_25 ( V_28 ) ;
if ( ( V_51 & V_47 ) == V_4 )
return 0 ;
F_26 () ;
F_27 ( 10 ) ;
} while ( ! F_28 ( V_50 , V_49 ) );
F_18 ( V_2 -> V_30 , L_4 , V_28 ) ;
return - V_52 ;
}
static inline int F_29 ( struct V_1 * V_2 )
{
return F_24 ( V_2 , V_2 -> V_53 + V_54 ,
0x0100 , 0x0000 ,
F_30 ( V_55 ) ) ;
}
static int F_31 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_4 )
{
T_3 V_56 = 0 ;
int V_6 ;
V_6 = F_29 ( V_2 ) ;
if ( V_6 < 0 ) {
F_18 ( V_2 -> V_30 , L_5 , V_4 ) ;
return V_6 ;
}
V_56 |= 0x58020000 ;
V_56 |= V_3 << 18 ;
V_56 |= V_4 ;
F_3 ( V_56 , V_2 -> V_53 + V_57 ) ;
return F_29 ( V_2 ) ;
}
static int F_32 ( struct V_58 * V_59 )
{
struct V_29 * V_30 = & V_59 -> V_30 ;
const struct V_31 * V_32 ;
struct V_1 * V_2 ;
struct V_36 * V_37 ;
struct V_33 * V_33 ;
V_2 = F_11 ( V_30 , sizeof( * V_2 ) , V_38 ) ;
if ( ! V_2 )
return - V_39 ;
V_2 -> V_30 = V_30 ;
V_32 = F_12 ( V_40 , V_30 ) ;
if ( ! V_32 )
return - V_41 ;
V_2 -> V_21 = (enum V_42 ) V_32 -> V_43 ;
V_37 = F_33 ( V_59 , V_60 , L_6 ) ;
V_2 -> V_12 = F_16 ( V_30 , V_37 ) ;
if ( F_17 ( V_2 -> V_12 ) ) {
F_18 ( V_30 , L_2 ) ;
return F_19 ( V_2 -> V_12 ) ;
}
V_37 = F_33 ( V_59 , V_60 , L_7 ) ;
V_2 -> V_53 = F_16 ( V_30 , V_37 ) ;
if ( F_17 ( V_2 -> V_53 ) ) {
F_18 ( V_30 , L_8 ) ;
return F_19 ( V_2 -> V_53 ) ;
}
F_3 ( 0x0000009a , V_2 -> V_53 + V_54 ) ;
F_27 ( 2 ) ;
V_2 -> V_5 = F_31 ;
V_2 -> V_19 = F_20 ( V_30 , NULL , & V_45 ) ;
if ( F_17 ( V_2 -> V_19 ) ) {
F_18 ( V_30 , L_3 ) ;
return F_19 ( V_2 -> V_19 ) ;
}
F_21 ( V_2 -> V_19 , V_2 ) ;
F_34 ( V_59 , V_2 ) ;
V_33 = F_22 ( V_30 , V_46 ) ;
if ( ! F_17 ( V_33 ) )
F_35 ( V_30 , L_9 ) ;
return F_23 ( V_33 ) ;
}
static int T_4 F_36 ( void )
{
int V_6 ;
V_6 = F_37 ( & V_61 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_38 ( & V_62 ) ;
if ( V_6 )
F_39 ( & V_61 ) ;
return V_6 ;
}
static void T_5 F_40 ( void )
{
F_41 ( & V_62 ) ;
F_39 ( & V_61 ) ;
}
