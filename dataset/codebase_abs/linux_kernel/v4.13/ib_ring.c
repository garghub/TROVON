void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
V_2 -> V_4 = V_3 ;
F_2 ( L_1 , V_2 , V_2 -> V_4 ) ;
}
static inline T_1 F_3 ( struct V_1 * V_2 )
{
T_1 V_5 ;
V_5 = V_2 -> V_6 - ( T_1 ) F_4 ( & V_2 -> V_7 ) ;
F_5 ( V_5 > V_2 -> V_4 ) ;
return V_5 ;
}
void F_6 ( struct V_1 * V_2 , T_1 V_3 )
{
F_5 ( F_3 ( V_2 ) ) ;
V_2 -> V_4 = V_3 ;
}
static int F_7 ( struct V_1 * V_2 )
{
return F_3 ( V_2 ) == 0 ;
}
T_1 F_8 ( struct V_1 * V_2 , T_1 V_8 , T_1 * V_9 )
{
T_1 V_10 = 0 , V_11 ;
V_11 = V_2 -> V_4 - F_3 ( V_2 ) ;
F_2 ( L_2 , V_2 , V_8 ,
V_2 -> V_12 , V_11 ) ;
if ( V_8 && V_11 ) {
V_10 = F_9 ( V_8 , V_11 ) ;
* V_9 = V_2 -> V_12 ;
V_2 -> V_12 = ( V_2 -> V_12 + V_10 ) % V_2 -> V_4 ;
V_2 -> V_6 += V_10 ;
}
return V_10 ;
}
void F_10 ( struct V_1 * V_2 , T_1 V_8 )
{
V_2 -> V_13 = ( V_2 -> V_13 + V_8 ) % V_2 -> V_4 ;
F_11 ( V_8 , & V_2 -> V_7 ) ;
if ( F_7 ( V_2 ) &&
F_12 ( & V_14 ) )
F_13 ( & V_14 ) ;
}
void F_14 ( struct V_1 * V_2 , T_1 V_8 )
{
V_2 -> V_12 = ( V_2 -> V_12 - V_8 ) % V_2 -> V_4 ;
V_2 -> V_6 -= V_8 ;
}
int F_15 ( struct V_1 * V_2 )
{
return F_7 ( V_2 ) ;
}
int F_16 ( struct V_1 * V_2 )
{
return F_3 ( V_2 ) <= ( V_2 -> V_4 >> 1 ) ;
}
T_1 F_17 ( struct V_1 * V_2 )
{
return V_2 -> V_13 ;
}
T_1 F_18 ( struct V_1 * V_2 , T_1 V_15 , T_1 V_16 )
{
T_1 V_10 ;
if ( V_16 <= ( unsigned long long ) V_15 )
V_10 = ( unsigned long long ) V_15 - V_16 + 1 ;
else
V_10 = V_2 -> V_4 - V_16 + ( unsigned long long ) V_15 + 1 ;
F_2 ( L_3 , V_2 , V_10 ,
V_15 , V_16 ) ;
return V_10 ;
}
