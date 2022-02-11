int F_1 ( void * V_1 , T_1 V_2 , unsigned char V_3 ,
const void * V_4 , T_1 V_5 )
{
struct V_6 * V_7 = V_1 ;
const T_2 * V_8 = V_4 ;
T_1 V_9 = V_5 ;
if ( ! V_4 || ! V_5 )
return - V_10 ;
if ( V_11 ) {
while ( ! * V_8 && V_9 ) {
V_8 ++ ;
V_9 -- ;
}
if ( V_9 != 256 && V_9 != 384 ) {
F_2 ( L_1 ) ;
return - V_10 ;
}
}
V_7 -> V_12 = V_4 ;
V_7 -> V_9 = V_5 ;
return 0 ;
}
int F_3 ( void * V_1 , T_1 V_2 , unsigned char V_3 ,
const void * V_4 , T_1 V_5 )
{
struct V_6 * V_7 = V_1 ;
if ( ! V_4 || ! V_7 -> V_9 || ! V_5 || V_5 > V_7 -> V_9 )
return - V_10 ;
V_7 -> V_13 = V_4 ;
V_7 -> V_14 = V_5 ;
return 0 ;
}
int F_4 ( void * V_1 , T_1 V_2 , unsigned char V_3 ,
const void * V_4 , T_1 V_5 )
{
struct V_6 * V_7 = V_1 ;
if ( ! V_4 || ! V_7 -> V_9 || ! V_5 || V_5 > V_7 -> V_9 )
return - V_10 ;
V_7 -> V_15 = V_4 ;
V_7 -> V_16 = V_5 ;
return 0 ;
}
int F_5 ( void * V_1 , T_1 V_2 , unsigned char V_3 ,
const void * V_4 , T_1 V_5 )
{
struct V_6 * V_7 = V_1 ;
if ( ! V_4 || ! V_5 || V_5 > V_7 -> V_9 )
return - V_10 ;
V_7 -> V_17 = V_4 ;
V_7 -> V_18 = V_5 ;
return 0 ;
}
int F_6 ( void * V_1 , T_1 V_2 , unsigned char V_3 ,
const void * V_4 , T_1 V_5 )
{
struct V_6 * V_7 = V_1 ;
if ( ! V_4 || ! V_5 || V_5 > V_7 -> V_9 )
return - V_10 ;
V_7 -> V_19 = V_4 ;
V_7 -> V_20 = V_5 ;
return 0 ;
}
int F_7 ( void * V_1 , T_1 V_2 , unsigned char V_3 ,
const void * V_4 , T_1 V_5 )
{
struct V_6 * V_7 = V_1 ;
if ( ! V_4 || ! V_5 || V_5 > V_7 -> V_9 )
return - V_10 ;
V_7 -> V_21 = V_4 ;
V_7 -> V_22 = V_5 ;
return 0 ;
}
int F_8 ( void * V_1 , T_1 V_2 , unsigned char V_3 ,
const void * V_4 , T_1 V_5 )
{
struct V_6 * V_7 = V_1 ;
if ( ! V_4 || ! V_5 || V_5 > V_7 -> V_9 )
return - V_10 ;
V_7 -> V_23 = V_4 ;
V_7 -> V_24 = V_5 ;
return 0 ;
}
int F_9 ( void * V_1 , T_1 V_2 , unsigned char V_3 ,
const void * V_4 , T_1 V_5 )
{
struct V_6 * V_7 = V_1 ;
if ( ! V_4 || ! V_5 || V_5 > V_7 -> V_9 )
return - V_10 ;
V_7 -> V_25 = V_4 ;
V_7 -> V_26 = V_5 ;
return 0 ;
}
int F_10 ( struct V_6 * V_6 , const void * V_7 ,
unsigned int V_27 )
{
return F_11 ( & V_28 , V_6 , V_7 , V_27 ) ;
}
int F_12 ( struct V_6 * V_6 , const void * V_7 ,
unsigned int V_27 )
{
return F_11 ( & V_29 , V_6 , V_7 , V_27 ) ;
}
