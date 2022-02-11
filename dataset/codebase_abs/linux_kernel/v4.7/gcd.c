unsigned long F_1 ( unsigned long V_1 , unsigned long V_2 )
{
unsigned long V_3 = V_1 | V_2 ;
if ( ! V_1 || ! V_2 )
return V_3 ;
V_2 >>= F_2 ( V_2 ) ;
if ( V_2 == 1 )
return V_3 & - V_3 ;
for (; ; ) {
V_1 >>= F_2 ( V_1 ) ;
if ( V_1 == 1 )
return V_3 & - V_3 ;
if ( V_1 == V_2 )
return V_1 << F_2 ( V_3 ) ;
if ( V_1 < V_2 )
F_3 ( V_1 , V_2 ) ;
V_1 -= V_2 ;
}
}
unsigned long F_1 ( unsigned long V_1 , unsigned long V_2 )
{
unsigned long V_3 = V_1 | V_2 ;
if ( ! V_1 || ! V_2 )
return V_3 ;
V_3 &= - V_3 ;
while ( ! ( V_2 & V_3 ) )
V_2 >>= 1 ;
if ( V_2 == V_3 )
return V_3 ;
for (; ; ) {
while ( ! ( V_1 & V_3 ) )
V_1 >>= 1 ;
if ( V_1 == V_3 )
return V_3 ;
if ( V_1 == V_2 )
return V_1 ;
if ( V_1 < V_2 )
F_3 ( V_1 , V_2 ) ;
V_1 -= V_2 ;
V_1 >>= 1 ;
if ( V_1 & V_3 )
V_1 += V_2 ;
V_1 >>= 1 ;
}
}
