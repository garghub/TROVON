int F_1 ( unsigned int V_1 )
{
T_1 V_2 , V_3 , V_4 , V_5 = 0 ;
void T_2 * V_6 ;
V_6 = V_7 + ( V_1 & V_8 ) ;
V_2 = V_1 & 0x3 ;
V_4 = ( V_1 & V_9 ) >> V_10 ;
F_2 ( & V_11 ) ;
V_3 = F_3 ( V_6 ) ;
V_3 &= ~ ( 0xff << ( V_2 * 8 ) ) ;
V_3 |= V_4 << ( V_2 * 8 ) ;
F_4 ( V_3 , V_6 ) ;
F_5 ( & V_11 ) ;
return V_5 ;
}
void F_6 ( enum V_12 V_13 , T_1 V_14 )
{
T_1 V_2 , V_3 ;
void T_2 * V_6 ;
V_13 &= V_15 ;
V_6 = V_16 + ( V_13 + 2 ) / 3 * 4 ;
V_2 = ( V_13 + 2 ) % 3 ;
F_7 ( L_1 ,
V_17 , ( V_13 + 2 ) / 3 , V_2 ) ;
F_2 ( & V_11 ) ;
V_3 = F_3 ( V_6 ) ;
V_3 &= ~ ( 0x1ff << ( V_2 * 10 ) ) ;
V_3 |= V_14 << ( V_2 * 10 ) ;
F_4 ( V_3 , V_6 ) ;
F_5 ( & V_11 ) ;
}
int F_8 ( unsigned int V_13 , const char * V_18 )
{
unsigned V_19 = V_13 & V_15 ;
if ( V_19 >= ( V_20 + 1 ) ) {
F_9 ( V_21 L_2 ,
V_19 , V_18 ? V_18 : L_3 ) ;
return - V_22 ;
}
if ( F_10 ( V_19 , V_23 ) ) {
F_9 ( V_21 L_4 ,
V_19 , V_18 ? V_18 : L_3 ) ;
return - V_24 ;
}
F_1 ( V_13 ) ;
return 0 ;
}
int F_11 ( const unsigned int * V_25 , unsigned V_26 ,
const char * V_18 )
{
const unsigned int * V_27 = V_25 ;
int V_28 ;
int V_5 = - V_22 ;
for ( V_28 = 0 ; V_28 < V_26 ; V_28 ++ ) {
V_5 = F_8 ( * V_27 , V_18 ) ;
if ( V_5 )
goto V_29;
V_27 ++ ;
}
return 0 ;
V_29:
F_12 ( V_25 , V_28 ) ;
return V_5 ;
}
void F_13 ( unsigned int V_13 )
{
unsigned V_19 = V_13 & V_15 ;
if ( V_19 < ( V_20 + 1 ) )
F_14 ( V_19 , V_23 ) ;
}
void F_12 ( const unsigned int * V_25 , int V_26 )
{
const unsigned int * V_27 = V_25 ;
int V_28 ;
for ( V_28 = 0 ; V_28 < V_26 ; V_28 ++ ) {
F_13 ( * V_27 ) ;
V_27 ++ ;
}
}
void F_15 ( enum V_30 V_31 , bool V_32 )
{
T_1 V_3 ;
F_2 ( & V_11 ) ;
V_3 = F_3 ( V_33 ) ;
if ( V_32 )
V_3 |= V_31 ;
else
V_3 &= ~ V_31 ;
F_4 ( V_3 , V_33 ) ;
F_5 ( & V_11 ) ;
}
