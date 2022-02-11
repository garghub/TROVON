T_1 F_1 ( T_1 * V_1 , int V_2 )
{
T_1 V_3 , V_4 ;
F_2 ( V_5 + 1 ) ;
V_4 = F_3 ( * V_1 ) ;
if ( F_4 ( F_5 ( V_2 == 0 || ( unsigned int ) - V_2 > V_5 ) ,
L_1 , V_2 ) )
return V_4 ;
for (; ; ) {
T_1 V_6 ;
V_6 = ( V_4 & ~ ( V_5 | V_7 ) ) | - V_2 ;
if ( V_4 & V_7 )
V_6 += V_8 ;
if ( V_6 == V_4 ) {
V_3 = V_6 ;
break;
}
V_3 = F_6 ( V_1 , V_4 , V_6 ) ;
if ( F_7 ( V_3 == V_4 || V_3 == V_6 ) )
break;
V_4 = V_3 ;
}
return V_3 ;
}
T_1 F_8 ( T_1 * V_1 )
{
T_1 V_4 = F_3 ( * V_1 ) ;
T_1 V_6 = V_4 ;
if ( V_4 != 0 ) {
V_6 |= V_7 ;
if ( V_4 != V_6 )
F_6 ( V_1 , V_4 , V_6 ) ;
}
return V_6 ;
}
int F_9 ( T_1 * V_1 , T_1 V_9 )
{
T_1 V_3 = F_3 ( * V_1 ) ;
if ( F_7 ( V_3 == V_9 ) )
return 0 ;
return - ( V_3 & V_5 ) ;
}
int F_10 ( T_1 * V_1 , T_1 * V_9 )
{
int V_2 = 0 ;
T_1 V_4 , V_6 ;
V_4 = F_3 ( * V_1 ) ;
if ( V_4 != * V_9 ) {
V_6 = V_4 | V_7 ;
if ( V_6 != V_4 )
F_6 ( V_1 , V_4 , V_6 ) ;
* V_9 = V_6 ;
V_2 = - ( V_6 & V_5 ) ;
}
return V_2 ;
}
