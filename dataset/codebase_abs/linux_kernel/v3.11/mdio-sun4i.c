static int F_1 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned long V_8 ;
int V_9 ;
F_2 ( ( V_3 << 8 ) | V_4 , V_6 -> V_10 + V_11 ) ;
F_2 ( 0x1 , V_6 -> V_10 + V_12 ) ;
V_8 = V_13 + V_14 ;
while ( F_3 ( V_6 -> V_10 + V_15 ) & 0x1 ) {
if ( F_4 ( V_8 ) )
return - V_16 ;
F_5 ( 1 ) ;
}
F_2 ( 0x0 , V_6 -> V_10 + V_12 ) ;
V_9 = F_3 ( V_6 -> V_10 + V_17 ) ;
return V_9 ;
}
static int F_6 ( struct V_1 * V_2 , int V_3 , int V_4 ,
T_1 V_9 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned long V_8 ;
F_2 ( ( V_3 << 8 ) | V_4 , V_6 -> V_10 + V_11 ) ;
F_2 ( 0x1 , V_6 -> V_10 + V_12 ) ;
V_8 = V_13 + V_14 ;
while ( F_3 ( V_6 -> V_10 + V_15 ) & 0x1 ) {
if ( F_4 ( V_8 ) )
return - V_16 ;
F_5 ( 1 ) ;
}
F_2 ( 0x0 , V_6 -> V_10 + V_12 ) ;
F_2 ( V_9 , V_6 -> V_10 + V_18 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_8 ( struct V_19 * V_20 )
{
struct V_21 * V_22 = V_20 -> V_23 . V_24 ;
struct V_1 * V_2 ;
struct V_5 * V_6 ;
int V_25 , V_26 ;
V_2 = F_9 ( sizeof( * V_6 ) ) ;
if ( ! V_2 )
return - V_27 ;
V_2 -> V_28 = L_1 ;
V_2 -> V_29 = & F_1 ;
V_2 -> V_30 = & F_6 ;
V_2 -> V_31 = & F_7 ;
snprintf ( V_2 -> V_32 , V_33 , L_2 , F_10 ( & V_20 -> V_23 ) ) ;
V_2 -> V_34 = & V_20 -> V_23 ;
V_2 -> V_35 = F_11 ( sizeof( int ) * V_36 , V_37 ) ;
if ( ! V_2 -> V_35 ) {
V_25 = - V_27 ;
goto V_38;
}
for ( V_26 = 0 ; V_26 < V_36 ; V_26 ++ )
V_2 -> V_35 [ V_26 ] = V_39 ;
V_6 = V_2 -> V_7 ;
V_6 -> V_10 = F_12 ( V_22 , 0 ) ;
if ( ! V_6 -> V_10 ) {
V_25 = - V_27 ;
goto V_40;
}
V_6 -> V_41 = F_13 ( & V_20 -> V_23 , L_3 ) ;
if ( F_14 ( V_6 -> V_41 ) ) {
if ( F_15 ( V_6 -> V_41 ) == - V_42 )
return - V_42 ;
F_16 ( & V_20 -> V_23 , L_4 ) ;
} else {
V_25 = F_17 ( V_6 -> V_41 ) ;
if ( V_25 )
goto V_40;
}
V_25 = F_18 ( V_2 , V_22 ) ;
if ( V_25 < 0 )
goto V_43;
F_19 ( V_20 , V_2 ) ;
return 0 ;
V_43:
F_20 ( V_6 -> V_41 ) ;
V_40:
F_21 ( V_2 -> V_35 ) ;
V_38:
F_22 ( V_2 ) ;
return V_25 ;
}
static int F_23 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = F_24 ( V_20 ) ;
F_25 ( V_2 ) ;
F_21 ( V_2 -> V_35 ) ;
F_22 ( V_2 ) ;
return 0 ;
}
