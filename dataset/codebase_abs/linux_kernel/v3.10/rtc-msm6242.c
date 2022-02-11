static inline unsigned int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
return F_2 ( & V_2 -> V_4 [ V_3 ] ) & 0xf ;
}
static inline void F_3 ( struct V_1 * V_2 , unsigned int V_5 ,
unsigned int V_3 )
{
F_4 ( V_5 , & V_2 -> V_4 [ V_3 ] ) ;
}
static inline void F_5 ( struct V_1 * V_2 , unsigned int V_5 ,
unsigned int V_3 )
{
F_3 ( V_2 , F_1 ( V_2 , V_3 ) | V_5 , V_3 ) ;
}
static inline void F_6 ( struct V_1 * V_2 , unsigned int V_5 ,
unsigned int V_3 )
{
F_3 ( V_2 , F_1 ( V_2 , V_3 ) & ~ V_5 , V_3 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
int V_6 = 5 ;
F_5 ( V_2 , V_7 , V_8 ) ;
while ( ( F_1 ( V_2 , V_8 ) & V_9 ) && V_6 ) {
F_6 ( V_2 , V_7 , V_8 ) ;
F_8 ( 70 ) ;
F_5 ( V_2 , V_7 , V_8 ) ;
V_6 -- ;
}
if ( ! V_6 )
F_9 ( L_1 ,
F_1 ( V_2 , V_8 ) ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
F_6 ( V_2 , V_7 , V_8 ) ;
}
static int F_11 ( struct V_10 * V_11 , struct V_12 * V_13 )
{
struct V_1 * V_2 = F_12 ( V_11 ) ;
F_7 ( V_2 ) ;
V_13 -> V_14 = F_1 ( V_2 , V_15 ) * 10 +
F_1 ( V_2 , V_16 ) ;
V_13 -> V_17 = F_1 ( V_2 , V_18 ) * 10 +
F_1 ( V_2 , V_19 ) ;
V_13 -> V_20 = ( F_1 ( V_2 , V_21 & 3 ) ) * 10 +
F_1 ( V_2 , V_22 ) ;
V_13 -> V_23 = F_1 ( V_2 , V_24 ) * 10 +
F_1 ( V_2 , V_25 ) ;
V_13 -> V_26 = F_1 ( V_2 , V_27 ) ;
V_13 -> V_28 = F_1 ( V_2 , V_29 ) * 10 +
F_1 ( V_2 , V_30 ) - 1 ;
V_13 -> V_31 = F_1 ( V_2 , V_32 ) * 10 +
F_1 ( V_2 , V_33 ) ;
if ( V_13 -> V_31 <= 69 )
V_13 -> V_31 += 100 ;
if ( ! ( F_1 ( V_2 , V_34 ) & V_35 ) ) {
unsigned int V_36 = F_1 ( V_2 , V_21 ) &
V_37 ;
if ( ! V_36 && V_13 -> V_20 == 12 )
V_13 -> V_20 = 0 ;
else if ( V_36 && V_13 -> V_20 != 12 )
V_13 -> V_20 += 12 ;
}
F_10 ( V_2 ) ;
return F_13 ( V_13 ) ;
}
static int F_14 ( struct V_10 * V_11 , struct V_12 * V_13 )
{
struct V_1 * V_2 = F_12 ( V_11 ) ;
F_7 ( V_2 ) ;
F_3 ( V_2 , V_13 -> V_14 / 10 , V_15 ) ;
F_3 ( V_2 , V_13 -> V_14 % 10 , V_16 ) ;
F_3 ( V_2 , V_13 -> V_17 / 10 , V_18 ) ;
F_3 ( V_2 , V_13 -> V_17 % 10 , V_19 ) ;
if ( F_1 ( V_2 , V_34 ) & V_35 )
F_3 ( V_2 , V_13 -> V_20 / 10 , V_21 ) ;
else if ( V_13 -> V_20 >= 12 )
F_3 ( V_2 , V_37 + ( V_13 -> V_20 - 12 ) / 10 ,
V_21 ) ;
else
F_3 ( V_2 , V_13 -> V_20 / 10 , V_21 ) ;
F_3 ( V_2 , V_13 -> V_20 % 10 , V_22 ) ;
F_3 ( V_2 , V_13 -> V_23 / 10 , V_24 ) ;
F_3 ( V_2 , V_13 -> V_23 % 10 , V_25 ) ;
if ( V_13 -> V_26 != - 1 )
F_3 ( V_2 , V_13 -> V_26 , V_27 ) ;
F_3 ( V_2 , ( V_13 -> V_28 + 1 ) / 10 , V_29 ) ;
F_3 ( V_2 , ( V_13 -> V_28 + 1 ) % 10 , V_30 ) ;
if ( V_13 -> V_31 >= 100 )
V_13 -> V_31 -= 100 ;
F_3 ( V_2 , V_13 -> V_31 / 10 , V_32 ) ;
F_3 ( V_2 , V_13 -> V_31 % 10 , V_33 ) ;
F_10 ( V_2 ) ;
return 0 ;
}
static int T_1 F_15 ( struct V_38 * V_39 )
{
struct V_40 * V_41 ;
struct V_1 * V_2 ;
struct V_42 * V_43 ;
int error ;
V_41 = F_16 ( V_39 , V_44 , 0 ) ;
if ( ! V_41 )
return - V_45 ;
V_2 = F_17 ( & V_39 -> V_11 , sizeof( * V_2 ) , V_46 ) ;
if ( ! V_2 )
return - V_47 ;
V_2 -> V_4 = F_18 ( & V_39 -> V_11 , V_41 -> V_48 , F_19 ( V_41 ) ) ;
if ( ! V_2 -> V_4 )
return - V_47 ;
F_20 ( V_39 , V_2 ) ;
V_43 = F_21 ( & V_39 -> V_11 , L_2 ,
& V_49 , V_50 ) ;
if ( F_22 ( V_43 ) ) {
error = F_23 ( V_43 ) ;
goto V_51;
}
V_2 -> V_43 = V_43 ;
return 0 ;
V_51:
F_20 ( V_39 , NULL ) ;
return error ;
}
static int T_2 F_24 ( struct V_38 * V_39 )
{
return 0 ;
}
