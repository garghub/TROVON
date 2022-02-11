void F_1 ( unsigned int V_1 )
{
T_1 V_2 ;
T_1 V_3 ;
T_1 V_4 ;
void T_2 * V_5 ;
V_5 = V_6 + ( V_1 & V_7 ) ;
V_2 = V_1 & 0x3 ;
V_4 = ( V_1 & V_8 ) >> V_9 ;
F_2 ( & V_10 ) ;
V_3 = F_3 ( V_5 ) ;
V_3 &= ~ ( 0xff << ( V_2 * 8 ) ) ;
V_3 |= V_4 << ( V_2 * 8 ) ;
F_4 ( V_3 , V_5 ) ;
F_5 ( & V_10 ) ;
}
void F_6 ( enum V_11 V_12 , T_1 V_13 )
{
T_1 V_2 , V_3 ;
void T_2 * V_5 ;
V_12 &= V_14 ;
V_5 = V_15 + ( V_12 + 2 ) / 3 * 4 ;
V_2 = ( V_12 + 2 ) % 3 ;
F_7 ( L_1 ,
V_16 , ( V_12 + 2 ) / 3 , V_2 ) ;
F_2 ( & V_10 ) ;
V_3 = F_3 ( V_5 ) ;
V_3 &= ~ ( 0x1ff << ( V_2 * 10 ) ) ;
V_3 |= V_13 << ( V_2 * 10 ) ;
F_4 ( V_3 , V_5 ) ;
F_5 ( & V_10 ) ;
}
int F_8 ( unsigned int V_12 , const char * V_17 )
{
unsigned V_18 = V_12 & V_14 ;
if ( V_18 >= ( V_19 + 1 ) ) {
F_9 ( V_20 L_2 ,
V_18 , V_17 ? V_17 : L_3 ) ;
return - V_21 ;
}
if ( F_10 ( V_18 , V_22 ) ) {
F_9 ( V_20 L_4 ,
V_18 , V_17 ? V_17 : L_3 ) ;
return - V_23 ;
}
F_1 ( V_12 ) ;
return 0 ;
}
int F_11 ( const unsigned int * V_24 , unsigned V_25 ,
const char * V_17 )
{
const unsigned int * V_26 = V_24 ;
int V_27 ;
int V_28 = - V_21 ;
for ( V_27 = 0 ; V_27 < V_25 ; V_27 ++ ) {
V_28 = F_8 ( * V_26 , V_17 ) ;
if ( V_28 )
goto V_29;
V_26 ++ ;
}
return 0 ;
V_29:
F_12 ( V_24 , V_27 ) ;
return V_28 ;
}
void F_13 ( unsigned int V_12 )
{
unsigned V_18 = V_12 & V_14 ;
if ( V_18 < ( V_19 + 1 ) )
F_14 ( V_18 , V_22 ) ;
}
void F_12 ( const unsigned int * V_24 , int V_25 )
{
const unsigned int * V_26 = V_24 ;
int V_27 ;
for ( V_27 = 0 ; V_27 < V_25 ; V_27 ++ ) {
F_13 ( * V_26 ) ;
V_26 ++ ;
}
}
void F_15 ( enum V_30 V_31 , bool V_32 )
{
T_1 V_3 ;
F_2 ( & V_10 ) ;
V_3 = F_3 ( V_33 ) ;
if ( V_32 )
V_3 |= V_31 ;
else
V_3 &= ~ V_31 ;
F_4 ( V_3 , V_33 ) ;
F_5 ( & V_10 ) ;
}
