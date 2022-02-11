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
static int F_9 ( struct V_1 * V_2 , T_2 V_5 )
{
int V_15 ;
V_15 = F_7 ( V_2 ) ;
if ( V_15 < 0 ) {
F_6 ( V_2 -> V_10 , L_2 , V_5 ) ;
return V_15 ;
}
F_10 ( V_5 , V_2 -> V_12 + V_16 ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 )
{
int V_15 ;
F_10 ( 0x0000009a , V_2 -> V_12 + V_13 ) ;
F_4 ( 2 ) ;
V_15 = F_9 ( V_2 , 0x587e8000 ) ;
if ( V_15 < 0 )
return V_15 ;
F_9 ( V_2 , 0x58061000 ) ;
F_9 ( V_2 , 0x582a6400 ) ;
F_9 ( V_2 , 0x582ec000 ) ;
F_9 ( V_2 , 0x582e8000 ) ;
F_7 ( V_2 ) ;
F_10 ( 0 , V_2 -> V_17 + V_18 ) ;
F_9 ( V_2 , 0x58069000 ) ;
F_9 ( V_2 , 0x587e8060 ) ;
F_9 ( V_2 , 0x580af30d ) ;
F_9 ( V_2 , 0x580e6302 ) ;
F_9 ( V_2 , 0x587e8040 ) ;
F_9 ( V_2 , 0x58061003 ) ;
F_7 ( V_2 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
int V_15 ;
F_10 ( 0x0000009a , V_2 -> V_12 + V_13 ) ;
F_4 ( 2 ) ;
V_15 = F_9 ( V_2 , 0x587e8000 ) ;
if ( V_15 < 0 )
return V_15 ;
F_9 ( V_2 , 0x582a6400 ) ;
F_9 ( V_2 , 0x587e80e0 ) ;
F_9 ( V_2 , 0x580a009c ) ;
F_9 ( V_2 , 0x587e8040 ) ;
F_9 ( V_2 , 0x580a21d3 ) ;
F_9 ( V_2 , 0x58061003 ) ;
F_7 ( V_2 ) ;
F_10 ( 0 , V_2 -> V_17 + V_18 ) ;
return 0 ;
}
static int F_13 ( struct V_19 * V_19 )
{
struct V_1 * V_2 = F_14 ( V_19 ) ;
int V_15 ;
F_10 ( V_20 , V_2 -> V_17 + V_18 ) ;
switch ( V_2 -> V_21 ) {
case V_22 :
V_15 = F_12 ( V_2 ) ;
break;
case V_23 :
V_15 = F_11 ( V_2 ) ;
break;
default:
F_15 ( 1 ) ;
V_15 = - V_24 ;
}
return V_15 ;
}
static int F_16 ( struct V_25 * V_26 )
{
struct V_27 * V_10 = & V_26 -> V_10 ;
const struct V_28 * V_29 ;
struct V_1 * V_2 ;
struct V_30 * V_31 ;
struct V_32 * V_32 ;
V_2 = F_17 ( V_10 , sizeof( * V_2 ) , V_33 ) ;
if ( ! V_2 )
return - V_34 ;
V_2 -> V_10 = V_10 ;
V_29 = F_18 ( V_35 , V_10 ) ;
if ( ! V_29 )
return - V_36 ;
V_2 -> V_21 = (enum V_37 ) V_29 -> V_38 ;
V_31 = F_19 ( V_26 , V_39 , L_3 ) ;
V_2 -> V_17 = F_20 ( V_10 , V_31 ) ;
if ( F_21 ( V_2 -> V_17 ) ) {
F_6 ( V_10 , L_4 ) ;
return F_22 ( V_2 -> V_17 ) ;
}
V_31 = F_19 ( V_26 , V_39 , L_5 ) ;
V_2 -> V_12 = F_20 ( V_10 , V_31 ) ;
if ( F_21 ( V_2 -> V_12 ) ) {
F_6 ( V_10 , L_6 ) ;
return F_22 ( V_2 -> V_12 ) ;
}
V_2 -> V_19 = F_23 ( V_10 , NULL , & V_40 ) ;
if ( F_21 ( V_2 -> V_19 ) ) {
F_6 ( V_10 , L_7 ) ;
return F_22 ( V_2 -> V_19 ) ;
}
F_24 ( V_2 -> V_19 , V_2 ) ;
F_25 ( V_26 , V_2 ) ;
V_32 = F_26 ( V_10 , V_41 ) ;
if ( ! F_21 ( V_32 ) )
F_27 ( V_10 , L_8 ) ;
return F_28 ( V_32 ) ;
}
