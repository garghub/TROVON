static int F_1 ( struct V_1 * V_2 )
{
return ! ( F_2 ( V_2 -> V_3 ) & V_4 ) ;
}
static int F_3 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_7 ;
unsigned long V_8 = F_4 ( V_9 ) ;
unsigned long V_10 = V_11 + V_8 ;
int V_12 = 0 ;
while ( 1 ) {
if ( F_1 ( V_2 ) )
return 0 ;
else if ( V_12 )
break;
if ( V_2 -> V_13 <= 0 ) {
F_5 ( V_14 ,
V_15 ) ;
if ( F_6 ( V_10 ) )
++ V_12 ;
} else {
if ( V_8 < 2 )
V_8 = 2 ;
F_7 ( V_2 -> V_16 ,
F_1 ( V_2 ) ,
V_8 ) ;
++ V_12 ;
}
}
F_8 ( V_6 -> V_17 , L_1 ) ;
return - V_18 ;
}
static int F_9 ( struct V_5 * V_6 , int V_19 ,
int V_20 )
{
struct V_1 * V_2 = V_6 -> V_7 ;
T_1 V_21 ;
int V_22 ;
F_10 ( & V_2 -> V_23 ) ;
V_22 = F_3 ( V_6 ) ;
if ( V_22 < 0 )
goto V_24;
F_11 ( ( ( V_19 << V_25 ) |
( V_20 << V_26 ) |
V_27 ) ,
V_2 -> V_3 ) ;
V_22 = F_3 ( V_6 ) ;
if ( V_22 < 0 )
goto V_24;
V_21 = F_2 ( V_2 -> V_3 ) ;
if ( ! ( V_21 & V_28 ) ) {
F_8 ( V_6 -> V_17 , L_2 ) ;
V_22 = - V_29 ;
goto V_24;
}
V_22 = V_21 & 0xFFFF ;
V_24:
F_12 ( & V_2 -> V_23 ) ;
return V_22 ;
}
static int F_13 ( struct V_5 * V_6 , int V_19 ,
int V_20 , T_2 V_30 )
{
struct V_1 * V_2 = V_6 -> V_7 ;
int V_22 ;
F_10 ( & V_2 -> V_23 ) ;
V_22 = F_3 ( V_6 ) ;
if ( V_22 < 0 )
goto V_24;
F_11 ( ( ( V_19 << V_25 ) |
( V_20 << V_26 ) |
V_31 |
( V_30 << V_32 ) ) ,
V_2 -> V_3 ) ;
V_24:
F_12 ( & V_2 -> V_23 ) ;
return V_22 ;
}
static T_3 F_14 ( int V_33 , void * V_34 )
{
struct V_1 * V_2 = V_34 ;
if ( F_2 ( V_2 -> V_3 + V_35 ) &
V_36 ) {
F_11 ( ~ V_36 ,
V_2 -> V_3 + V_35 ) ;
F_15 ( & V_2 -> V_16 ) ;
return V_37 ;
}
return V_38 ;
}
static int F_16 ( struct V_39 * V_40 )
{
struct V_41 * V_42 ;
struct V_5 * V_6 ;
struct V_1 * V_2 ;
int V_43 , V_22 ;
V_42 = F_17 ( V_40 , V_44 , 0 ) ;
if ( ! V_42 ) {
F_8 ( & V_40 -> V_2 , L_3 ) ;
return - V_29 ;
}
V_6 = F_18 ( & V_40 -> V_2 ,
sizeof( struct V_1 ) ) ;
if ( ! V_6 )
return - V_45 ;
V_6 -> V_46 = L_4 ;
V_6 -> V_47 = F_9 ;
V_6 -> V_48 = F_13 ;
snprintf ( V_6 -> V_49 , V_50 , L_5 ,
F_19 ( & V_40 -> V_2 ) ) ;
V_6 -> V_17 = & V_40 -> V_2 ;
V_6 -> V_33 = F_20 ( & V_40 -> V_2 , V_51 , sizeof( int ) ,
V_52 ) ;
if ( ! V_6 -> V_33 )
return - V_45 ;
for ( V_43 = 0 ; V_43 < V_51 ; V_43 ++ )
V_6 -> V_33 [ V_43 ] = V_53 ;
V_2 = V_6 -> V_7 ;
V_2 -> V_3 = F_21 ( & V_40 -> V_2 , V_42 -> V_54 , F_22 ( V_42 ) ) ;
if ( ! V_2 -> V_3 ) {
F_8 ( & V_40 -> V_2 , L_6 ) ;
V_22 = - V_29 ;
goto V_55;
}
F_23 ( & V_2 -> V_16 ) ;
V_2 -> V_56 = F_24 ( & V_40 -> V_2 , NULL ) ;
if ( ! F_25 ( V_2 -> V_56 ) )
F_26 ( V_2 -> V_56 ) ;
V_2 -> V_13 = F_27 ( V_40 , 0 ) ;
if ( V_2 -> V_13 > 0 ) {
V_22 = F_28 ( & V_40 -> V_2 , V_2 -> V_13 ,
F_14 ,
V_57 , V_40 -> V_46 , V_2 ) ;
if ( V_22 )
goto V_55;
F_11 ( V_36 ,
V_2 -> V_3 + V_58 ) ;
} else if ( V_2 -> V_13 == - V_59 ) {
return - V_59 ;
}
F_29 ( & V_2 -> V_23 ) ;
if ( V_40 -> V_2 . V_60 )
V_22 = F_30 ( V_6 , V_40 -> V_2 . V_60 ) ;
else
V_22 = F_31 ( V_6 ) ;
if ( V_22 < 0 ) {
F_8 ( & V_40 -> V_2 , L_7 , V_22 ) ;
goto V_55;
}
F_32 ( V_40 , V_6 ) ;
return 0 ;
V_55:
if ( ! F_25 ( V_2 -> V_56 ) )
F_33 ( V_2 -> V_56 ) ;
return V_22 ;
}
static int F_34 ( struct V_39 * V_40 )
{
struct V_5 * V_6 = F_35 ( V_40 ) ;
struct V_1 * V_2 = V_6 -> V_7 ;
F_11 ( 0 , V_2 -> V_3 + V_58 ) ;
F_36 ( V_6 ) ;
if ( ! F_25 ( V_2 -> V_56 ) )
F_33 ( V_2 -> V_56 ) ;
return 0 ;
}
