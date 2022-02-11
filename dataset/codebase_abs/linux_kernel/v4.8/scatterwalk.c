static inline void F_1 ( void * V_1 , void * V_2 , T_1 V_3 , int V_4 )
{
void * V_5 = V_4 ? V_1 : V_2 ;
void * V_6 = V_4 ? V_2 : V_1 ;
memcpy ( V_6 , V_5 , V_3 ) ;
}
void F_2 ( void * V_1 , struct V_7 * V_8 ,
T_1 V_3 , int V_4 )
{
for (; ; ) {
unsigned int V_9 = F_3 ( V_8 ) ;
T_2 * V_10 ;
if ( V_9 > V_3 )
V_9 = V_3 ;
if ( V_4 != 2 ) {
V_10 = F_4 ( V_8 ) ;
F_1 ( V_1 , V_10 , V_9 , V_4 ) ;
F_5 ( V_10 ) ;
}
F_6 ( V_8 , V_9 ) ;
if ( V_3 == V_9 )
break;
V_1 += V_9 ;
V_3 -= V_9 ;
F_7 ( V_8 , V_4 & 1 , 1 ) ;
}
}
void F_8 ( void * V_1 , struct V_11 * V_12 ,
unsigned int V_13 , unsigned int V_3 , int V_4 )
{
struct V_7 V_8 ;
struct V_11 V_14 [ 2 ] ;
if ( ! V_3 )
return;
V_12 = F_9 ( V_14 , V_12 , V_13 ) ;
if ( F_10 ( V_12 ) == F_11 ( V_1 ) &&
V_12 -> V_15 == F_12 ( V_1 ) )
return;
F_13 ( & V_8 , V_12 ) ;
F_2 ( V_1 , & V_8 , V_3 , V_4 ) ;
F_14 ( & V_8 , V_4 , 0 ) ;
}
struct V_11 * F_9 ( struct V_11 V_6 [ 2 ] ,
struct V_11 * V_5 ,
unsigned int V_16 )
{
for (; ; ) {
if ( ! V_16 )
return V_5 ;
if ( V_5 -> V_17 > V_16 )
break;
V_16 -= V_5 -> V_17 ;
V_5 = F_15 ( V_5 ) ;
}
F_16 ( V_6 , 2 ) ;
F_17 ( V_6 , F_10 ( V_5 ) , V_5 -> V_17 - V_16 , V_5 -> V_15 + V_16 ) ;
F_18 ( V_6 , F_15 ( V_5 ) , 0 , 2 ) ;
return V_6 ;
}
