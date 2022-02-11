static int F_1 ( struct V_1 * V_2 )
{
return ! ( F_2 ( V_2 -> V_3 ) & V_4 ) ;
}
static int F_3 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_7 ;
int V_8 ;
if ( V_2 -> V_9 <= 0 ) {
V_8 = 0 ;
while ( 1 ) {
if ( F_1 ( V_2 ) )
break;
if ( V_8 > 100 ) {
F_4 ( V_6 -> V_10 ,
L_1 ) ;
return - V_11 ;
}
F_5 ( 10 ) ;
V_8 ++ ;
}
} else {
if ( ! F_1 ( V_2 ) ) {
F_6 ( V_2 -> V_12 ,
F_1 ( V_2 ) ,
F_7 ( 100 ) ) ;
if ( ! F_1 ( V_2 ) )
return - V_11 ;
}
}
return 0 ;
}
static int F_8 ( struct V_5 * V_6 , int V_13 ,
int V_14 )
{
struct V_1 * V_2 = V_6 -> V_7 ;
int V_8 ;
T_1 V_15 ;
int V_16 ;
F_9 ( & V_2 -> V_17 ) ;
V_16 = F_3 ( V_6 ) ;
if ( V_16 < 0 ) {
F_10 ( & V_2 -> V_17 ) ;
return V_16 ;
}
F_11 ( ( ( V_13 << V_18 ) |
( V_14 << V_19 ) |
V_20 ) ,
V_2 -> V_3 ) ;
V_8 = 0 ;
while ( 1 ) {
V_15 = F_2 ( V_2 -> V_3 ) ;
if ( V_15 & V_21 )
break;
if ( V_8 > 100 ) {
F_4 ( V_6 -> V_10 , L_2 ) ;
F_10 ( & V_2 -> V_17 ) ;
return - V_11 ;
}
F_5 ( 10 ) ;
V_8 ++ ;
}
F_10 ( & V_2 -> V_17 ) ;
return V_15 & 0xFFFF ;
}
static int F_12 ( struct V_5 * V_6 , int V_13 ,
int V_14 , T_2 V_22 )
{
struct V_1 * V_2 = V_6 -> V_7 ;
int V_16 ;
F_9 ( & V_2 -> V_17 ) ;
V_16 = F_3 ( V_6 ) ;
if ( V_16 < 0 ) {
F_10 ( & V_2 -> V_17 ) ;
return V_16 ;
}
F_11 ( ( ( V_13 << V_18 ) |
( V_14 << V_19 ) |
V_23 |
( V_22 << V_24 ) ) ,
V_2 -> V_3 ) ;
F_10 ( & V_2 -> V_17 ) ;
return 0 ;
}
static int F_13 ( struct V_5 * V_6 )
{
return 0 ;
}
static T_3 F_14 ( int V_25 , void * V_26 )
{
struct V_1 * V_2 = V_26 ;
if ( F_2 ( V_2 -> V_3 + V_27 ) &
V_28 ) {
F_11 ( ~ V_28 ,
V_2 -> V_3 + V_27 ) ;
F_15 ( & V_2 -> V_12 ) ;
return V_29 ;
}
return V_30 ;
}
static int F_16 ( struct V_31 * V_32 )
{
struct V_33 * V_34 ;
struct V_5 * V_6 ;
struct V_1 * V_2 ;
int V_35 , V_16 ;
V_34 = F_17 ( V_32 , V_36 , 0 ) ;
if ( ! V_34 ) {
F_4 ( & V_32 -> V_2 , L_3 ) ;
return - V_37 ;
}
V_6 = F_18 ( sizeof( struct V_1 ) ) ;
if ( ! V_6 ) {
F_4 ( & V_32 -> V_2 , L_4 ) ;
return - V_38 ;
}
V_6 -> V_39 = L_5 ;
V_6 -> V_40 = F_8 ;
V_6 -> V_41 = F_12 ;
V_6 -> V_42 = F_13 ;
snprintf ( V_6 -> V_43 , V_44 , L_6 ,
F_19 ( & V_32 -> V_2 ) ) ;
V_6 -> V_10 = & V_32 -> V_2 ;
V_6 -> V_25 = F_20 ( sizeof( int ) * V_45 , V_46 ) ;
if ( ! V_6 -> V_25 ) {
F_21 ( V_6 ) ;
return - V_38 ;
}
for ( V_35 = 0 ; V_35 < V_45 ; V_35 ++ )
V_6 -> V_25 [ V_35 ] = V_47 ;
V_2 = V_6 -> V_7 ;
V_2 -> V_3 = F_22 ( & V_32 -> V_2 , V_34 -> V_48 , F_23 ( V_34 ) ) ;
if ( ! V_2 -> V_3 ) {
F_4 ( & V_32 -> V_2 , L_7 ) ;
V_16 = - V_37 ;
goto V_49;
}
F_24 ( & V_2 -> V_12 ) ;
V_2 -> V_50 = F_25 ( & V_32 -> V_2 , NULL ) ;
if ( ! F_26 ( V_2 -> V_50 ) )
F_27 ( V_2 -> V_50 ) ;
V_2 -> V_9 = F_28 ( V_32 , 0 ) ;
if ( V_2 -> V_9 != - V_51 ) {
V_16 = F_29 ( & V_32 -> V_2 , V_2 -> V_9 ,
F_14 ,
V_52 , V_32 -> V_39 , V_2 ) ;
if ( V_16 )
goto V_49;
F_11 ( V_28 ,
V_2 -> V_3 + V_53 ) ;
}
F_30 ( & V_2 -> V_17 ) ;
if ( V_32 -> V_2 . V_54 )
V_16 = F_31 ( V_6 , V_32 -> V_2 . V_54 ) ;
else
V_16 = F_32 ( V_6 ) ;
if ( V_16 < 0 ) {
F_4 ( & V_32 -> V_2 , L_8 , V_16 ) ;
goto V_49;
}
F_33 ( V_32 , V_6 ) ;
return 0 ;
V_49:
if ( ! F_26 ( V_2 -> V_50 ) )
F_34 ( V_2 -> V_50 ) ;
F_35 ( V_6 -> V_25 ) ;
F_21 ( V_6 ) ;
return V_16 ;
}
static int F_36 ( struct V_31 * V_32 )
{
struct V_5 * V_6 = F_37 ( V_32 ) ;
struct V_1 * V_2 = V_6 -> V_7 ;
F_11 ( 0 , V_2 -> V_3 + V_53 ) ;
F_38 ( V_6 ) ;
F_35 ( V_6 -> V_25 ) ;
F_21 ( V_6 ) ;
if ( ! F_26 ( V_2 -> V_50 ) )
F_34 ( V_2 -> V_50 ) ;
return 0 ;
}
