static inline void
F_1 ( struct V_1 * V_2 , int V_3 )
{
if ( V_3 )
V_2 -> V_4 |= V_5 ;
else
V_2 -> V_4 &= ~ V_5 ;
F_2 ( V_2 -> V_4 , V_2 -> V_6 ) ;
}
static inline void
F_3 ( struct V_1 * V_2 , int V_3 )
{
if ( V_3 )
V_2 -> V_4 |= V_7 ;
else
V_2 -> V_4 &= ~ V_7 ;
F_2 ( V_2 -> V_4 , V_2 -> V_6 ) ;
}
static inline int
F_4 ( struct V_1 * V_2 )
{
return F_5 ( V_2 -> V_6 ) & V_8 ;
}
static inline T_1
F_6 ( struct V_1 * V_2 ,
unsigned V_9 , unsigned V_10 , unsigned V_11 ,
T_1 V_12 , T_2 V_13 )
{
T_1 V_14 = 32 - V_13 ;
for (; F_7 ( V_13 ) ; V_13 -- ) {
if ( ( V_11 & V_15 ) == 0 )
F_3 ( V_2 , ( V_12 & 1 ) ) ;
F_8 ( V_9 , V_9 + 1 ) ;
V_12 >>= 1 ;
if ( ( V_11 & V_16 ) == 0 )
V_12 |= ( F_4 ( V_2 ) << 31 ) ;
F_1 ( V_2 , ! V_10 ) ;
F_8 ( V_9 , V_9 + 1 ) ;
F_1 ( V_2 , V_10 ) ;
}
V_12 >>= V_14 ;
return V_12 ;
}
static int
F_9 ( struct V_17 * V_18 ,
struct V_19 * V_20 ,
struct V_21 * V_22 )
{
struct V_1 * V_2 = F_10 ( V_18 ) ;
unsigned V_23 = V_22 -> V_24 ;
const T_2 * V_25 = V_22 -> V_26 ;
T_2 * V_27 = V_22 -> V_28 ;
T_2 V_12 = 0 ;
int V_29 = 0 ;
if ( V_25 ) {
V_2 -> V_4 &= ~ V_30 ;
F_2 ( V_2 -> V_4 , V_2 -> V_6 ) ;
while ( F_7 ( V_23 > 0 ) ) {
V_12 = * V_25 ++ ;
F_6 ( V_2 , 1 , 0 ,
V_16 , V_12 , 8 ) ;
V_23 -- ;
}
} else if ( V_27 ) {
V_2 -> V_4 |= V_30 ;
F_2 ( V_2 -> V_4 , V_2 -> V_6 ) ;
while ( F_7 ( V_23 > 0 ) ) {
V_12 = F_6 ( V_2 , 1 , 0 ,
V_15 , V_12 , 8 ) ;
* V_27 ++ = V_12 ;
V_23 -- ;
}
} else {
V_29 = - V_31 ;
}
F_11 ( V_18 ) ;
return V_29 ;
}
static void
F_12 ( struct V_19 * V_20 , bool V_32 )
{
struct V_1 * V_2 = F_10 ( V_20 -> V_18 ) ;
V_2 -> V_4 = 0 ;
F_2 ( V_2 -> V_4 , V_2 -> V_6 ) ;
if ( V_32 ) {
F_8 ( 4 , 5 ) ;
V_2 -> V_4 |= V_33 ;
F_2 ( V_2 -> V_4 , V_2 -> V_6 ) ;
F_8 ( 4 , 5 ) ;
}
}
static int
F_13 ( struct V_19 * V_20 )
{
if ( ( V_20 -> V_34 & V_35 ) == 0 ) {
F_14 ( & V_20 -> V_36 , L_1 ) ;
return - V_31 ;
}
if ( ( V_20 -> V_34 & V_37 ) == 0 ) {
F_14 ( & V_20 -> V_36 , L_2 ) ;
return - V_31 ;
}
if ( ( V_20 -> V_34 & V_38 ) == 0 ) {
F_14 ( & V_20 -> V_36 , L_3 ) ;
return - V_31 ;
}
return 0 ;
}
static int
F_15 ( struct V_39 * V_40 )
{
int V_29 ;
struct V_17 * V_18 ;
struct V_1 * V_2 ;
void * V_6 ;
V_18 = F_16 ( & V_40 -> V_36 , sizeof( * V_2 ) ) ;
if ( ! V_18 )
return - V_41 ;
F_17 ( V_40 , V_18 ) ;
V_18 -> V_11 = V_42 ;
V_18 -> V_43 = V_35 | V_38 | V_37 ;
V_18 -> V_44 = V_40 -> V_45 ;
V_18 -> V_46 = 1 ;
V_18 -> V_47 = F_13 ;
V_18 -> V_48 = F_12 ;
V_18 -> V_49 = F_9 ;
V_18 -> V_50 = F_18 ( 8 ) ;
#ifdef F_19
V_18 -> V_36 . V_51 = V_40 -> V_36 . V_51 ;
#endif
V_2 = F_10 ( V_18 ) ;
V_6 = F_20 ( V_40 , V_52 , 0 ) ;
V_2 -> V_6 = F_21 ( & V_40 -> V_36 , V_6 ) ;
V_29 = F_22 ( V_2 -> V_6 ) ;
if ( V_29 ) {
F_14 ( & V_40 -> V_36 , L_4 ) ;
goto V_53;
}
V_29 = F_23 ( & V_40 -> V_36 , V_18 ) ;
if ( V_29 ) {
F_14 ( & V_40 -> V_36 , L_5 ) ;
goto V_53;
}
return V_29 ;
V_53:
F_24 ( V_18 ) ;
return V_29 ;
}
