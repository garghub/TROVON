static int F_1 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
T_1 V_8 = 0 ;
unsigned int V_9 = 5 ;
F_2 ( & V_2 -> V_10 , L_1 , V_11 ) ;
V_8 |= V_12 | ( ( V_3 << 16 ) & V_13 ) |
( ( V_4 << 21 ) & V_14 ) ;
F_3 ( V_8 , V_6 -> V_15 + V_16 ) ;
do {
V_8 = F_4 ( V_6 -> V_15 + V_16 ) ;
if ( ! ( V_8 & V_12 ) )
return V_8 & V_17 ;
F_5 ( 10 ) ;
V_9 -- ;
} while ( V_9 > 0 );
F_2 ( & V_2 -> V_10 , L_2 , V_11 ) ;
return - V_18 ;
}
static int F_6 ( struct V_1 * V_2 , int V_3 ,
int V_4 , T_2 V_19 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
T_1 V_8 = 0 ;
unsigned int V_9 = 5 ;
F_2 ( & V_2 -> V_10 , L_1 , V_11 ) ;
V_8 |= V_20 | ( ( V_3 << 16 ) & V_13 ) |
( ( V_4 << 21 ) & V_14 ) ;
V_19 &= V_21 ;
F_3 ( V_19 , V_6 -> V_15 + V_22 ) ;
F_3 ( V_8 , V_6 -> V_15 + V_16 ) ;
do {
V_8 = F_4 ( V_6 -> V_15 + V_16 ) ;
if ( ! ( V_8 & V_20 ) )
return 0 ;
F_5 ( 10 ) ;
V_9 -- ;
} while ( V_9 > 0 );
F_2 ( & V_2 -> V_10 , L_2 , V_11 ) ;
return - V_18 ;
}
static int F_7 ( struct V_1 * V_2 )
{
int V_6 , V_23 ;
for ( V_23 = 0 ; V_23 < V_24 ; V_23 ++ ) {
V_6 = F_1 ( V_2 , V_23 , V_25 ) ;
if ( V_6 < 0 )
continue;
V_6 |= V_26 ;
if ( F_6 ( V_2 , V_23 , V_25 , V_6 ) < 0 )
continue;
}
return 0 ;
}
static int F_8 ( struct V_27 * V_28 )
{
struct V_29 * V_30 = V_28 -> V_10 . V_31 ;
struct V_1 * V_2 ;
struct V_5 * V_6 ;
struct V_32 * V_33 ;
int V_34 , V_23 ;
V_2 = F_9 ( sizeof( * V_6 ) ) ;
if ( ! V_2 )
return - V_35 ;
V_2 -> V_36 = L_3 ;
V_2 -> V_37 = & F_1 ;
V_2 -> V_38 = & F_6 ;
V_2 -> V_39 = & F_7 ;
snprintf ( V_2 -> V_40 , V_41 , L_4 , V_28 -> V_36 , V_28 -> V_40 ) ;
V_2 -> V_42 = & V_28 -> V_10 ;
for ( V_23 = 0 ; V_23 < V_24 ; V_23 ++ )
V_2 -> V_43 [ V_23 ] = V_44 ;
V_6 = V_2 -> V_7 ;
V_33 = F_10 ( V_28 , V_45 , 0 ) ;
V_6 -> V_15 = F_11 ( & V_28 -> V_10 , V_33 ) ;
if ( F_12 ( V_6 -> V_15 ) ) {
V_34 = F_13 ( V_6 -> V_15 ) ;
goto V_46;
}
V_34 = F_14 ( V_2 , V_30 ) ;
if ( V_34 < 0 )
goto V_46;
F_15 ( V_28 , V_2 ) ;
return 0 ;
V_46:
F_16 ( V_2 ) ;
return V_34 ;
}
static int F_17 ( struct V_27 * V_28 )
{
struct V_1 * V_2 = F_18 ( V_28 ) ;
F_19 ( V_2 ) ;
F_16 ( V_2 ) ;
return 0 ;
}
