int F_1 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
T_1 V_5 ;
int V_6 ;
if ( V_2 == NULL || V_4 == 0 || V_3 > V_4 )
return - V_7 ;
V_5 = ( V_3 * V_8 ) / V_4 ;
V_6 = F_2 ( V_9 , V_5 , V_10 ) ;
if ( V_6 < 0 ) {
F_3 ( L_1 ,
V_2 -> V_11 , V_6 ) ;
return V_6 ;
}
return 0 ;
}
int F_4 ( struct V_1 * V_2 )
{
T_1 V_12 ;
int V_6 ;
V_6 = F_5 ( V_9 , & V_12 , V_13 ) ;
if ( V_6 < 0 ) {
F_3 ( L_2 , V_2 -> V_11 , V_6 ) ;
return V_6 ;
}
V_12 &= ~ V_14 ;
V_12 |= V_15 ;
V_6 = F_2 ( V_9 , V_12 , V_13 ) ;
if ( V_6 < 0 ) {
F_3 ( L_2 , V_2 -> V_11 , V_6 ) ;
return V_6 ;
}
F_5 ( V_9 , & V_12 , V_13 ) ;
return 0 ;
}
void F_6 ( struct V_1 * V_2 )
{
T_1 V_12 ;
int V_6 ;
V_6 = F_5 ( V_9 , & V_12 , V_13 ) ;
if ( V_6 < 0 ) {
F_3 ( L_3 ,
V_2 -> V_11 , V_6 ) ;
return;
}
V_12 &= ~ V_14 ;
V_12 |= V_16 ;
V_6 = F_2 ( V_9 , V_12 , V_13 ) ;
if ( V_6 < 0 ) {
F_3 ( L_3 ,
V_2 -> V_11 , V_6 ) ;
return;
}
return;
}
struct V_1 * F_7 ( int V_17 , const char * V_11 )
{
T_1 V_12 ;
int V_6 ;
struct V_1 * V_2 ;
V_2 = F_8 ( sizeof( struct V_1 ) , V_18 ) ;
if ( V_2 == NULL ) {
F_3 ( L_4 , V_11 ) ;
return NULL ;
}
V_2 -> V_11 = V_11 ;
V_2 -> V_17 = V_17 ;
V_12 = V_19 | V_20 | V_21 |
V_16 ;
V_6 = F_2 ( V_9 , V_12 , V_13 ) ;
if ( V_6 < 0 ) {
F_3 ( L_1 ,
V_2 -> V_11 , V_6 ) ;
F_9 ( V_2 ) ;
return NULL ;
}
return V_2 ;
}
void F_10 ( struct V_1 * V_2 )
{
F_6 ( V_2 ) ;
F_9 ( V_2 ) ;
}
