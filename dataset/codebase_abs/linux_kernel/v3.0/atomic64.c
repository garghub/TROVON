static inline T_1 * F_1 ( const T_2 * V_1 )
{
unsigned long V_2 = ( unsigned long ) V_1 ;
V_2 >>= V_3 ;
V_2 ^= ( V_2 >> 8 ) ^ ( V_2 >> 16 ) ;
return & V_4 [ V_2 & ( V_5 - 1 ) ] . V_6 ;
}
long long F_2 ( const T_2 * V_1 )
{
unsigned long V_7 ;
T_1 * V_6 = F_1 ( V_1 ) ;
long long V_8 ;
F_3 ( V_6 , V_7 ) ;
V_8 = V_1 -> V_9 ;
F_4 ( V_6 , V_7 ) ;
return V_8 ;
}
void F_5 ( T_2 * V_1 , long long V_10 )
{
unsigned long V_7 ;
T_1 * V_6 = F_1 ( V_1 ) ;
F_3 ( V_6 , V_7 ) ;
V_1 -> V_9 = V_10 ;
F_4 ( V_6 , V_7 ) ;
}
void F_6 ( long long V_11 , T_2 * V_1 )
{
unsigned long V_7 ;
T_1 * V_6 = F_1 ( V_1 ) ;
F_3 ( V_6 , V_7 ) ;
V_1 -> V_9 += V_11 ;
F_4 ( V_6 , V_7 ) ;
}
long long F_7 ( long long V_11 , T_2 * V_1 )
{
unsigned long V_7 ;
T_1 * V_6 = F_1 ( V_1 ) ;
long long V_8 ;
F_3 ( V_6 , V_7 ) ;
V_8 = V_1 -> V_9 += V_11 ;
F_4 ( V_6 , V_7 ) ;
return V_8 ;
}
void F_8 ( long long V_11 , T_2 * V_1 )
{
unsigned long V_7 ;
T_1 * V_6 = F_1 ( V_1 ) ;
F_3 ( V_6 , V_7 ) ;
V_1 -> V_9 -= V_11 ;
F_4 ( V_6 , V_7 ) ;
}
long long F_9 ( long long V_11 , T_2 * V_1 )
{
unsigned long V_7 ;
T_1 * V_6 = F_1 ( V_1 ) ;
long long V_8 ;
F_3 ( V_6 , V_7 ) ;
V_8 = V_1 -> V_9 -= V_11 ;
F_4 ( V_6 , V_7 ) ;
return V_8 ;
}
long long F_10 ( T_2 * V_1 )
{
unsigned long V_7 ;
T_1 * V_6 = F_1 ( V_1 ) ;
long long V_8 ;
F_3 ( V_6 , V_7 ) ;
V_8 = V_1 -> V_9 - 1 ;
if ( V_8 >= 0 )
V_1 -> V_9 = V_8 ;
F_4 ( V_6 , V_7 ) ;
return V_8 ;
}
long long F_11 ( T_2 * V_1 , long long V_12 , long long V_13 )
{
unsigned long V_7 ;
T_1 * V_6 = F_1 ( V_1 ) ;
long long V_8 ;
F_3 ( V_6 , V_7 ) ;
V_8 = V_1 -> V_9 ;
if ( V_8 == V_12 )
V_1 -> V_9 = V_13 ;
F_4 ( V_6 , V_7 ) ;
return V_8 ;
}
long long F_12 ( T_2 * V_1 , long long V_14 )
{
unsigned long V_7 ;
T_1 * V_6 = F_1 ( V_1 ) ;
long long V_8 ;
F_3 ( V_6 , V_7 ) ;
V_8 = V_1 -> V_9 ;
V_1 -> V_9 = V_14 ;
F_4 ( V_6 , V_7 ) ;
return V_8 ;
}
int F_13 ( T_2 * V_1 , long long V_11 , long long V_15 )
{
unsigned long V_7 ;
T_1 * V_6 = F_1 ( V_1 ) ;
int V_16 = 0 ;
F_3 ( V_6 , V_7 ) ;
if ( V_1 -> V_9 != V_15 ) {
V_1 -> V_9 += V_11 ;
V_16 = 1 ;
}
F_4 ( V_6 , V_7 ) ;
return V_16 ;
}
static int F_14 ( void )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < V_5 ; ++ V_10 )
F_15 ( & V_4 [ V_10 ] . V_6 ) ;
return 0 ;
}
