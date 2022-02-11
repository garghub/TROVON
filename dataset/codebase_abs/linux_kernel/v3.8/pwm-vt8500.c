static inline void F_1 ( void T_1 * V_1 , T_2 V_2 )
{
int V_3 = F_2 ( 10 ) ;
while ( ( F_3 ( V_1 ) & V_2 ) && -- V_3 )
F_4 () ;
if ( F_5 ( ! V_3 ) )
F_6 ( L_1 ,
V_2 ) ;
}
static int F_7 ( struct V_4 * V_5 , struct V_6 * V_7 ,
int V_8 , int V_9 )
{
struct V_10 * V_11 = F_8 ( V_5 ) ;
unsigned long long V_12 ;
unsigned long V_13 , V_14 , V_15 , V_16 ;
int V_17 ;
V_17 = F_9 ( V_11 -> V_18 ) ;
if ( V_17 < 0 ) {
F_10 ( V_5 -> V_19 , L_2 ) ;
return V_17 ;
}
V_12 = F_11 ( V_11 -> V_18 ) ;
V_12 = V_12 * V_9 ;
F_12 ( V_12 , 1000000000 ) ;
V_13 = V_12 ;
if ( V_13 < 1 )
V_13 = 1 ;
V_14 = ( V_13 - 1 ) / 4096 ;
V_15 = V_13 / ( V_14 + 1 ) - 1 ;
if ( V_15 > 4095 )
V_15 = 4095 ;
if ( V_14 > 1023 ) {
F_13 ( V_11 -> V_18 ) ;
return - V_20 ;
}
V_12 = ( unsigned long long ) V_15 * V_8 ;
F_12 ( V_12 , V_9 ) ;
V_16 = V_12 ;
F_1 ( V_11 -> V_21 + 0x40 + V_7 -> V_22 , ( 1 << 1 ) ) ;
F_14 ( V_14 , V_11 -> V_21 + 0x4 + ( V_7 -> V_22 << 4 ) ) ;
F_1 ( V_11 -> V_21 + 0x40 + V_7 -> V_22 , ( 1 << 2 ) ) ;
F_14 ( V_15 , V_11 -> V_21 + 0x8 + ( V_7 -> V_22 << 4 ) ) ;
F_1 ( V_11 -> V_21 + 0x40 + V_7 -> V_22 , ( 1 << 3 ) ) ;
F_14 ( V_16 , V_11 -> V_21 + 0xc + ( V_7 -> V_22 << 4 ) ) ;
F_13 ( V_11 -> V_18 ) ;
return 0 ;
}
static int F_15 ( struct V_4 * V_5 , struct V_6 * V_7 )
{
int V_17 ;
struct V_10 * V_11 = F_8 ( V_5 ) ;
V_17 = F_9 ( V_11 -> V_18 ) ;
if ( V_17 < 0 ) {
F_10 ( V_5 -> V_19 , L_2 ) ;
return V_17 ;
}
F_1 ( V_11 -> V_21 + 0x40 + V_7 -> V_22 , ( 1 << 0 ) ) ;
F_14 ( 5 , V_11 -> V_21 + ( V_7 -> V_22 << 4 ) ) ;
return 0 ;
}
static void F_16 ( struct V_4 * V_5 , struct V_6 * V_7 )
{
struct V_10 * V_11 = F_8 ( V_5 ) ;
F_1 ( V_11 -> V_21 + 0x40 + V_7 -> V_22 , ( 1 << 0 ) ) ;
F_14 ( 0 , V_11 -> V_21 + ( V_7 -> V_22 << 4 ) ) ;
F_13 ( V_11 -> V_18 ) ;
}
static int F_17 ( struct V_23 * V_24 )
{
struct V_10 * V_5 ;
struct V_25 * V_26 ;
struct V_27 * V_28 = V_24 -> V_19 . V_29 ;
int V_30 ;
if ( ! V_28 ) {
F_10 ( & V_24 -> V_19 , L_3 ) ;
return - V_20 ;
}
V_5 = F_18 ( & V_24 -> V_19 , sizeof( * V_5 ) , V_31 ) ;
if ( V_5 == NULL ) {
F_10 ( & V_24 -> V_19 , L_4 ) ;
return - V_32 ;
}
V_5 -> V_5 . V_19 = & V_24 -> V_19 ;
V_5 -> V_5 . V_33 = & V_34 ;
V_5 -> V_5 . V_21 = - 1 ;
V_5 -> V_5 . V_35 = V_36 ;
V_5 -> V_18 = F_19 ( & V_24 -> V_19 , NULL ) ;
if ( F_20 ( V_5 -> V_18 ) ) {
F_10 ( & V_24 -> V_19 , L_5 ) ;
return F_21 ( V_5 -> V_18 ) ;
}
V_26 = F_22 ( V_24 , V_37 , 0 ) ;
if ( V_26 == NULL ) {
F_10 ( & V_24 -> V_19 , L_6 ) ;
return - V_38 ;
}
V_5 -> V_21 = F_23 ( & V_24 -> V_19 , V_26 ) ;
if ( ! V_5 -> V_21 )
return - V_39 ;
V_30 = F_24 ( V_5 -> V_18 ) ;
if ( V_30 < 0 ) {
F_10 ( & V_24 -> V_19 , L_7 ) ;
return V_30 ;
}
V_30 = F_25 ( & V_5 -> V_5 ) ;
if ( V_30 < 0 ) {
F_10 ( & V_24 -> V_19 , L_8 ) ;
return V_30 ;
}
F_26 ( V_24 , V_5 ) ;
return V_30 ;
}
static int F_27 ( struct V_23 * V_24 )
{
struct V_10 * V_5 ;
V_5 = F_28 ( V_24 ) ;
if ( V_5 == NULL )
return - V_38 ;
F_29 ( V_5 -> V_18 ) ;
return F_30 ( & V_5 -> V_5 ) ;
}
