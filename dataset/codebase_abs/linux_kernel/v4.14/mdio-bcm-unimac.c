static inline T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
if ( F_2 ( V_4 ) && F_2 ( V_5 ) )
return F_3 ( V_2 -> V_6 + V_3 ) ;
else
return F_4 ( V_2 -> V_6 + V_3 ) ;
}
static inline void F_5 ( struct V_1 * V_2 , T_1 V_7 ,
T_1 V_3 )
{
if ( F_2 ( V_4 ) && F_2 ( V_5 ) )
F_6 ( V_7 , V_2 -> V_6 + V_3 ) ;
else
F_7 ( V_7 , V_2 -> V_6 + V_3 ) ;
}
static inline void F_8 ( struct V_1 * V_2 )
{
T_1 V_8 ;
V_8 = F_1 ( V_2 , V_9 ) ;
V_8 |= V_10 ;
F_5 ( V_2 , V_8 , V_9 ) ;
}
static inline unsigned int F_9 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , V_9 ) & V_10 ;
}
static int F_10 ( void * V_11 )
{
struct V_1 * V_2 = V_11 ;
unsigned int V_12 = 1000 ;
do {
if ( ! F_9 ( V_2 ) )
return 0 ;
F_11 ( 1000 , 2000 ) ;
} while ( -- V_12 );
if ( ! V_12 )
return - V_13 ;
return 0 ;
}
static int F_12 ( struct V_14 * V_15 , int V_16 , int V_8 )
{
struct V_1 * V_2 = V_15 -> V_2 ;
int V_17 ;
T_1 V_18 ;
V_18 = V_19 | ( V_16 << V_20 ) | ( V_8 << V_21 ) ;
F_5 ( V_2 , V_18 , V_9 ) ;
F_8 ( V_2 ) ;
V_17 = V_2 -> V_22 ( V_2 -> V_11 ) ;
if ( V_17 )
return V_17 ;
V_18 = F_1 ( V_2 , V_9 ) ;
if ( ! ( V_15 -> V_23 & 1 << V_16 ) && ( V_18 & V_24 ) )
return - V_25 ;
return V_18 & 0xffff ;
}
static int F_13 ( struct V_14 * V_15 , int V_16 ,
int V_8 , T_2 V_7 )
{
struct V_1 * V_2 = V_15 -> V_2 ;
T_1 V_18 ;
V_18 = V_26 | ( V_16 << V_20 ) |
( V_8 << V_21 ) | ( 0xffff & V_7 ) ;
F_5 ( V_2 , V_18 , V_9 ) ;
F_8 ( V_2 ) ;
return V_2 -> V_22 ( V_2 -> V_11 ) ;
}
static int F_14 ( struct V_14 * V_15 )
{
struct V_27 * V_28 = V_15 -> V_29 . V_30 ;
struct V_27 * V_31 ;
T_1 V_32 = 0 ;
int V_33 ;
if ( ! V_28 ) {
V_32 = ~ V_15 -> V_34 ;
} else {
F_15 (np, child) {
V_33 = F_16 ( & V_15 -> V_29 , V_31 ) ;
if ( V_33 < 0 )
continue;
V_32 |= 1 << V_33 ;
}
}
for ( V_33 = 0 ; V_33 < V_35 ; V_33 ++ ) {
if ( V_32 & 1 << V_33 ) {
F_17 ( & V_15 -> V_29 , L_1 , V_33 ) ;
F_18 ( V_15 , V_33 , V_36 ) ;
}
}
return 0 ;
}
static int F_19 ( struct V_37 * V_38 )
{
struct V_39 * V_40 = V_38 -> V_29 . V_41 ;
struct V_1 * V_2 ;
struct V_27 * V_28 ;
struct V_14 * V_15 ;
struct V_42 * V_43 ;
int V_17 ;
V_28 = V_38 -> V_29 . V_30 ;
V_2 = F_20 ( & V_38 -> V_29 , sizeof( * V_2 ) , V_44 ) ;
if ( ! V_2 )
return - V_45 ;
V_43 = F_21 ( V_38 , V_46 , 0 ) ;
V_2 -> V_6 = F_22 ( & V_38 -> V_29 , V_43 -> V_47 , F_23 ( V_43 ) ) ;
if ( ! V_2 -> V_6 ) {
F_24 ( & V_38 -> V_29 , L_2 ) ;
return - V_45 ;
}
V_2 -> V_14 = F_25 () ;
if ( ! V_2 -> V_14 )
return - V_45 ;
V_15 = V_2 -> V_14 ;
V_15 -> V_2 = V_2 ;
if ( V_40 ) {
V_15 -> V_48 = V_40 -> V_49 ;
V_2 -> V_22 = V_40 -> V_22 ;
V_2 -> V_11 = V_40 -> V_11 ;
V_15 -> V_34 = ~ V_40 -> V_34 ;
} else {
V_15 -> V_48 = L_3 ;
V_2 -> V_11 = V_2 ;
V_2 -> V_22 = F_10 ;
}
V_15 -> V_50 = & V_38 -> V_29 ;
V_15 -> V_51 = F_12 ;
V_15 -> V_52 = F_13 ;
V_15 -> V_53 = F_14 ;
snprintf ( V_15 -> V_54 , V_55 , L_4 , V_38 -> V_48 , V_38 -> V_54 ) ;
V_17 = F_26 ( V_15 , V_28 ) ;
if ( V_17 ) {
F_24 ( & V_38 -> V_29 , L_5 ) ;
goto V_56;
}
F_27 ( V_38 , V_2 ) ;
F_28 ( & V_38 -> V_29 , L_6 , V_2 -> V_6 ) ;
return 0 ;
V_56:
F_29 ( V_15 ) ;
return V_17 ;
}
static int F_30 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = F_31 ( V_38 ) ;
F_32 ( V_2 -> V_14 ) ;
F_29 ( V_2 -> V_14 ) ;
return 0 ;
}
