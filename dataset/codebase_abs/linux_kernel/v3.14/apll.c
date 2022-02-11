static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 = 0 , V_6 = 0 ;
struct V_7 * V_8 ;
const char * V_9 ;
T_1 V_10 = 1 ;
T_2 V_11 ;
V_8 = V_4 -> V_7 ;
if ( ! V_8 )
return - V_12 ;
V_9 = F_3 ( V_4 -> V_2 . V_4 ) ;
V_10 <<= F_4 ( V_8 -> V_13 ) ;
V_11 = V_14 -> V_15 ( V_8 -> V_16 ) ;
if ( ( V_11 & V_8 -> V_13 ) == V_10 )
return V_5 ;
V_11 = V_14 -> V_15 ( V_8 -> V_17 ) ;
V_11 &= ~ V_8 -> V_18 ;
V_11 |= V_19 << F_4 ( V_8 -> V_18 ) ;
V_14 -> V_20 ( V_11 , V_8 -> V_17 ) ;
V_10 <<= F_4 ( V_8 -> V_13 ) ;
while ( 1 ) {
V_11 = V_14 -> V_15 ( V_8 -> V_16 ) ;
if ( ( V_11 & V_8 -> V_13 ) == V_10 )
break;
if ( V_6 > V_21 )
break;
V_6 ++ ;
F_5 ( 1 ) ;
}
if ( V_6 == V_21 ) {
F_6 ( L_1 ,
V_9 , ( V_10 ) ? L_2 : L_3 ) ;
} else {
F_7 ( L_4 ,
V_9 , ( V_10 ) ? L_2 : L_3 , V_6 ) ;
V_5 = 0 ;
}
return V_5 ;
}
static void F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_7 * V_8 ;
T_1 V_10 = 1 ;
T_2 V_11 ;
V_8 = V_4 -> V_7 ;
V_10 <<= F_4 ( V_8 -> V_13 ) ;
V_11 = V_14 -> V_15 ( V_8 -> V_17 ) ;
V_11 &= ~ V_8 -> V_18 ;
V_11 |= V_22 << F_4 ( V_8 -> V_18 ) ;
V_14 -> V_20 ( V_11 , V_8 -> V_17 ) ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_7 * V_8 ;
T_2 V_11 ;
V_8 = V_4 -> V_7 ;
V_11 = V_14 -> V_15 ( V_8 -> V_17 ) ;
V_11 &= V_8 -> V_18 ;
V_11 >>= F_4 ( V_8 -> V_18 ) ;
return V_11 == V_22 ? 0 : 1 ;
}
static T_1 F_10 ( struct V_1 * V_2 )
{
return 0 ;
}
static void T_3 F_11 ( struct V_1 * V_2 ,
struct V_23 * V_24 )
{
struct V_3 * V_1 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_1 -> V_7 ;
struct V_4 * V_4 ;
V_8 -> V_25 = F_12 ( V_24 , 0 ) ;
V_8 -> V_26 = F_12 ( V_24 , 1 ) ;
if ( F_13 ( V_8 -> V_25 ) || F_13 ( V_8 -> V_26 ) ) {
F_7 ( L_5 ,
V_24 -> V_27 ) ;
if ( ! F_14 ( V_24 , V_2 , F_11 ) )
return;
goto V_28;
}
V_4 = F_15 ( NULL , & V_1 -> V_2 ) ;
if ( ! F_13 ( V_4 ) ) {
F_16 ( V_24 , V_29 , V_4 ) ;
F_17 ( V_1 -> V_2 . V_30 -> V_31 ) ;
F_17 ( V_1 -> V_2 . V_30 ) ;
return;
}
V_28:
F_17 ( V_1 -> V_7 ) ;
F_17 ( V_1 -> V_2 . V_30 -> V_31 ) ;
F_17 ( V_1 -> V_2 . V_30 ) ;
F_17 ( V_1 ) ;
}
static void T_3 F_18 ( struct V_23 * V_24 )
{
struct V_7 * V_8 = NULL ;
struct V_3 * V_1 = NULL ;
struct V_32 * V_30 = NULL ;
const char * * V_31 = NULL ;
int V_6 ;
V_8 = F_19 ( sizeof( * V_8 ) , V_33 ) ;
V_1 = F_19 ( sizeof( * V_1 ) , V_33 ) ;
V_30 = F_19 ( sizeof( * V_30 ) , V_33 ) ;
if ( ! V_8 || ! V_1 || ! V_30 )
goto V_28;
V_1 -> V_7 = V_8 ;
V_1 -> V_2 . V_30 = V_30 ;
V_1 -> V_34 = V_35 ;
V_30 -> V_27 = V_24 -> V_27 ;
V_30 -> V_36 = & V_37 ;
V_30 -> V_38 = F_20 ( V_24 ) ;
if ( V_30 -> V_38 < 1 ) {
F_21 ( L_6 , V_24 -> V_27 ) ;
goto V_28;
}
V_31 = F_19 ( sizeof( char * ) * V_30 -> V_38 , V_33 ) ;
if ( ! V_31 )
goto V_28;
for ( V_6 = 0 ; V_6 < V_30 -> V_38 ; V_6 ++ )
V_31 [ V_6 ] = F_22 ( V_24 , V_6 ) ;
V_30 -> V_31 = V_31 ;
V_8 -> V_17 = F_23 ( V_24 , 0 ) ;
V_8 -> V_16 = F_23 ( V_24 , 1 ) ;
if ( ! V_8 -> V_17 || ! V_8 -> V_16 )
goto V_28;
V_8 -> V_13 = 0x1 ;
V_8 -> V_18 = 0x3 ;
F_11 ( & V_1 -> V_2 , V_24 ) ;
return;
V_28:
F_17 ( V_31 ) ;
F_17 ( V_8 ) ;
F_17 ( V_1 ) ;
F_17 ( V_30 ) ;
}
