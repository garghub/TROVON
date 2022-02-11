static inline void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_3 = F_2 ( V_2 -> V_4 + V_5 ) ;
V_3 |= V_6 ;
F_3 ( V_3 , V_2 -> V_4 + V_5 ) ;
}
static inline unsigned int F_4 ( struct V_1 * V_2 )
{
return F_2 ( V_2 -> V_4 + V_5 ) & V_6 ;
}
static int F_5 ( struct V_7 * V_8 , int V_9 , int V_3 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
unsigned int V_10 = 1000 ;
T_1 V_11 ;
V_11 = V_12 | ( V_9 << V_13 ) | ( V_3 << V_14 ) ;
F_3 ( V_11 , V_2 -> V_4 + V_5 ) ;
F_1 ( V_2 ) ;
do {
if ( ! F_4 ( V_2 ) )
break;
F_6 ( 1000 , 2000 ) ;
} while ( V_10 -- );
if ( ! V_10 )
return - V_15 ;
V_11 = F_2 ( V_2 -> V_4 + V_5 ) ;
if ( ! ( V_8 -> V_16 & 1 << V_9 ) && ( V_11 & V_17 ) )
return - V_18 ;
return V_11 & 0xffff ;
}
static int F_7 ( struct V_7 * V_8 , int V_9 ,
int V_3 , T_2 V_19 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
unsigned int V_10 = 1000 ;
T_1 V_11 ;
V_11 = V_20 | ( V_9 << V_13 ) |
( V_3 << V_14 ) | ( 0xffff & V_19 ) ;
F_3 ( V_11 , V_2 -> V_4 + V_5 ) ;
F_1 ( V_2 ) ;
do {
if ( ! F_4 ( V_2 ) )
break;
F_6 ( 1000 , 2000 ) ;
} while ( V_10 -- );
if ( ! V_10 )
return - V_15 ;
return 0 ;
}
static int F_8 ( struct V_7 * V_8 )
{
struct V_21 * V_22 = V_8 -> V_23 . V_24 ;
struct V_21 * V_25 ;
T_1 V_26 = 0 ;
int V_27 ;
if ( ! V_22 ) {
V_26 = ~ V_8 -> V_28 ;
} else {
F_9 (np, child) {
V_27 = F_10 ( & V_8 -> V_23 , V_25 ) ;
if ( V_27 < 0 )
continue;
V_26 |= 1 << V_27 ;
}
}
for ( V_27 = 0 ; V_27 < V_29 ; V_27 ++ ) {
if ( V_26 & 1 << V_27 )
F_11 ( V_8 , V_27 , V_30 ) ;
}
return 0 ;
}
static int F_12 ( struct V_31 * V_32 )
{
struct V_1 * V_2 ;
struct V_21 * V_22 ;
struct V_7 * V_8 ;
struct V_33 * V_34 ;
int V_35 ;
V_22 = V_32 -> V_23 . V_24 ;
V_2 = F_13 ( & V_32 -> V_23 , sizeof( * V_2 ) , V_36 ) ;
if ( ! V_2 )
return - V_37 ;
V_34 = F_14 ( V_32 , V_38 , 0 ) ;
V_2 -> V_4 = F_15 ( & V_32 -> V_23 , V_34 -> V_39 , F_16 ( V_34 ) ) ;
if ( ! V_2 -> V_4 ) {
F_17 ( & V_32 -> V_23 , L_1 ) ;
return - V_37 ;
}
V_2 -> V_7 = F_18 () ;
if ( ! V_2 -> V_7 )
return - V_37 ;
V_8 = V_2 -> V_7 ;
V_8 -> V_2 = V_2 ;
V_8 -> V_40 = L_2 ;
V_8 -> V_41 = & V_32 -> V_23 ;
V_8 -> V_42 = F_5 ;
V_8 -> V_43 = F_7 ;
V_8 -> V_44 = F_8 ;
snprintf ( V_8 -> V_45 , V_46 , L_3 , V_32 -> V_40 ) ;
V_8 -> V_47 = F_19 ( V_29 , sizeof( int ) , V_36 ) ;
if ( ! V_8 -> V_47 ) {
V_35 = - V_37 ;
goto V_48;
}
V_35 = F_20 ( V_8 , V_22 ) ;
if ( V_35 ) {
F_17 ( & V_32 -> V_23 , L_4 ) ;
goto V_49;
}
F_21 ( V_32 , V_2 ) ;
F_22 ( & V_32 -> V_23 , L_5 , V_2 -> V_4 ) ;
return 0 ;
V_49:
F_23 ( V_8 -> V_47 ) ;
V_48:
F_24 ( V_8 ) ;
return V_35 ;
}
static int F_25 ( struct V_31 * V_32 )
{
struct V_1 * V_2 = F_26 ( V_32 ) ;
F_27 ( V_2 -> V_7 ) ;
F_23 ( V_2 -> V_7 -> V_47 ) ;
F_24 ( V_2 -> V_7 ) ;
return 0 ;
}
