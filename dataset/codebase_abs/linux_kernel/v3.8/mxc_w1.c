static T_1 F_1 ( void * V_1 )
{
T_1 V_2 ;
unsigned int V_3 = 0 ;
struct V_4 * V_5 = V_1 ;
F_2 ( 0x80 , ( V_5 -> V_6 + V_7 ) ) ;
while ( 1 ) {
V_2 = F_3 ( V_5 -> V_6 + V_7 ) ;
if ( ( ( V_2 >> 7 ) & 0x1 ) == 0 ||
V_3 > V_8 )
break;
else
V_3 ++ ;
F_4 ( 100 ) ;
}
return ( V_2 >> 7 ) & 0x1 ;
}
static T_1 F_5 ( void * V_1 , T_1 V_9 )
{
struct V_4 * V_10 = V_1 ;
void T_2 * V_11 = V_10 -> V_6 + V_7 ;
unsigned int V_3 = 400 ;
F_2 ( ( 1 << ( 5 - V_9 ) ) , V_11 ) ;
while ( V_3 -- ) {
if ( ! ( ( F_3 ( V_11 ) >> ( 5 - V_9 ) ) & 0x1 ) )
break;
F_4 ( 1 ) ;
}
return ( ( F_3 ( V_11 ) ) >> 3 ) & 0x1 ;
}
static int F_6 ( struct V_12 * V_13 )
{
struct V_4 * V_10 ;
struct V_14 * V_15 ;
int V_16 = 0 ;
V_15 = F_7 ( V_13 , V_17 , 0 ) ;
if ( ! V_15 )
return - V_18 ;
V_10 = F_8 ( sizeof( struct V_4 ) , V_19 ) ;
if ( ! V_10 )
return - V_20 ;
V_10 -> V_21 = F_9 ( & V_13 -> V_5 , NULL ) ;
if ( F_10 ( V_10 -> V_21 ) ) {
V_16 = F_11 ( V_10 -> V_21 ) ;
goto V_22;
}
V_10 -> V_23 = ( F_12 ( V_10 -> V_21 ) / 1000000 ) - 1 ;
V_15 = F_13 ( V_15 -> V_24 , F_14 ( V_15 ) ,
L_1 ) ;
if ( ! V_15 ) {
V_16 = - V_25 ;
goto V_26;
}
V_10 -> V_6 = F_15 ( V_15 -> V_24 , F_14 ( V_15 ) ) ;
if ( ! V_10 -> V_6 ) {
F_16 ( & V_13 -> V_5 , L_2 ) ;
goto V_27;
}
F_17 ( V_10 -> V_21 ) ;
F_2 ( V_10 -> V_23 , V_10 -> V_6 + V_28 ) ;
V_10 -> V_29 . V_1 = V_10 ;
V_10 -> V_29 . V_30 = F_1 ;
V_10 -> V_29 . V_31 = F_5 ;
V_16 = F_18 ( & V_10 -> V_29 ) ;
if ( V_16 )
goto V_32;
F_19 ( V_13 , V_10 ) ;
return 0 ;
V_32:
F_20 ( V_10 -> V_6 ) ;
V_27:
F_21 ( V_15 -> V_24 , F_14 ( V_15 ) ) ;
V_26:
F_22 ( V_10 -> V_21 ) ;
V_22:
F_23 ( V_10 ) ;
return V_16 ;
}
static int F_24 ( struct V_12 * V_13 )
{
struct V_4 * V_10 = F_25 ( V_13 ) ;
struct V_14 * V_15 ;
V_15 = F_7 ( V_13 , V_17 , 0 ) ;
F_26 ( & V_10 -> V_29 ) ;
F_20 ( V_10 -> V_6 ) ;
F_21 ( V_15 -> V_24 , F_14 ( V_15 ) ) ;
F_27 ( V_10 -> V_21 ) ;
F_22 ( V_10 -> V_21 ) ;
F_19 ( V_13 , NULL ) ;
return 0 ;
}
