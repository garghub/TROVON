static int F_1 ( struct V_1 * V_2 , void T_1 * V_3 ,
T_2 V_4 , T_2 V_5 , unsigned long V_6 )
{
unsigned long V_7 = V_8 + V_6 ;
T_2 V_9 ;
do {
V_9 = F_2 ( V_3 ) ;
if ( ( V_9 & V_4 ) == V_5 )
return 0 ;
F_3 () ;
F_4 ( 10 ) ;
} while ( ! F_5 ( V_8 , V_7 ) );
F_6 ( V_2 -> V_10 , L_1 , V_3 ) ;
return - V_11 ;
}
static inline int F_7 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , V_2 -> V_12 + V_13 ,
0x0100 , 0x0000 ,
F_8 ( V_14 ) ) ;
}
static int F_9 ( struct V_1 * V_2 , T_3 V_15 ,
T_3 V_5 )
{
T_2 V_16 = 0 ;
int V_17 ;
V_17 = F_7 ( V_2 ) ;
if ( V_17 < 0 ) {
F_6 ( V_2 -> V_10 , L_2 , V_5 ) ;
return V_17 ;
}
V_16 |= 0x58020000 ;
V_16 |= V_15 << 18 ;
V_16 |= V_5 ;
F_10 ( V_16 , V_2 -> V_12 + V_18 ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 )
{
int V_17 ;
F_10 ( 0x0000009a , V_2 -> V_12 + V_13 ) ;
F_4 ( 2 ) ;
V_17 = F_9 ( V_2 , V_19 ,
V_20 ) ;
if ( V_17 < 0 )
return V_17 ;
F_9 ( V_2 , V_21 , 0x1000 ) ;
F_9 ( V_2 , V_22 , 0x6400 ) ;
F_9 ( V_2 , V_23 , 0xc000 ) ;
F_9 ( V_2 , V_23 , 0x8000 ) ;
F_7 ( V_2 ) ;
F_10 ( 0 , V_2 -> V_24 + V_25 ) ;
F_9 ( V_2 , V_21 , 0x9000 ) ;
F_9 ( V_2 , V_19 ,
V_26 ) ;
F_9 ( V_2 , V_27 , 0xf30d ) ;
F_9 ( V_2 , V_28 , 0x6302 ) ;
F_9 ( V_2 , V_19 ,
V_29 ) ;
F_9 ( V_2 , V_30 , 0x1003 ) ;
F_7 ( V_2 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
int V_17 ;
F_10 ( 0x0000009a , V_2 -> V_12 + V_13 ) ;
F_4 ( 2 ) ;
V_17 = F_9 ( V_2 , V_19 ,
V_20 ) ;
if ( V_17 < 0 )
return V_17 ;
F_9 ( V_2 , V_22 , 0x6400 ) ;
F_9 ( V_2 , V_19 , 0x80e0 ) ;
F_9 ( V_2 , 0x02 , 0x009c ) ;
F_9 ( V_2 , V_19 ,
V_29 ) ;
F_9 ( V_2 , 0x02 , 0x21d3 ) ;
F_9 ( V_2 , V_30 , 0x1003 ) ;
F_7 ( V_2 ) ;
F_10 ( 0 , V_2 -> V_24 + V_25 ) ;
return 0 ;
}
static int F_13 ( struct V_31 * V_31 )
{
struct V_1 * V_2 = F_14 ( V_31 ) ;
int V_17 ;
F_10 ( V_32 , V_2 -> V_24 + V_25 ) ;
switch ( V_2 -> V_33 ) {
case V_34 :
V_17 = F_12 ( V_2 ) ;
break;
case V_35 :
V_17 = F_11 ( V_2 ) ;
break;
default:
F_15 ( 1 ) ;
V_17 = - V_36 ;
}
return V_17 ;
}
static int F_16 ( struct V_37 * V_38 )
{
struct V_39 * V_10 = & V_38 -> V_10 ;
const struct V_40 * V_41 ;
struct V_1 * V_2 ;
struct V_42 * V_43 ;
struct V_44 * V_44 ;
V_2 = F_17 ( V_10 , sizeof( * V_2 ) , V_45 ) ;
if ( ! V_2 )
return - V_46 ;
V_2 -> V_10 = V_10 ;
V_41 = F_18 ( V_47 , V_10 ) ;
if ( ! V_41 )
return - V_48 ;
V_2 -> V_33 = (enum V_49 ) V_41 -> V_50 ;
V_43 = F_19 ( V_38 , V_51 , L_3 ) ;
V_2 -> V_24 = F_20 ( V_10 , V_43 ) ;
if ( F_21 ( V_2 -> V_24 ) ) {
F_6 ( V_10 , L_4 ) ;
return F_22 ( V_2 -> V_24 ) ;
}
V_43 = F_19 ( V_38 , V_51 , L_5 ) ;
V_2 -> V_12 = F_20 ( V_10 , V_43 ) ;
if ( F_21 ( V_2 -> V_12 ) ) {
F_6 ( V_10 , L_6 ) ;
return F_22 ( V_2 -> V_12 ) ;
}
V_2 -> V_31 = F_23 ( V_10 , NULL , & V_52 ) ;
if ( F_21 ( V_2 -> V_31 ) ) {
F_6 ( V_10 , L_7 ) ;
return F_22 ( V_2 -> V_31 ) ;
}
F_24 ( V_2 -> V_31 , V_2 ) ;
F_25 ( V_38 , V_2 ) ;
V_44 = F_26 ( V_10 , V_53 ) ;
if ( ! F_21 ( V_44 ) )
F_27 ( V_10 , L_8 ) ;
return F_28 ( V_44 ) ;
}
