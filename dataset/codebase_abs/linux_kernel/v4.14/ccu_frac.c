bool F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
if ( ! ( V_2 -> V_5 & V_6 ) )
return false ;
return ! ( F_2 ( V_2 -> V_7 + V_2 -> V_8 ) & V_4 -> V_9 ) ;
}
void F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
unsigned long V_10 ;
T_1 V_8 ;
if ( ! ( V_2 -> V_5 & V_6 ) )
return;
F_4 ( V_2 -> V_11 , V_10 ) ;
V_8 = F_2 ( V_2 -> V_7 + V_2 -> V_8 ) ;
F_5 ( V_8 & ~ V_4 -> V_9 , V_2 -> V_7 + V_2 -> V_8 ) ;
F_6 ( V_2 -> V_11 , V_10 ) ;
}
void F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
unsigned long V_10 ;
T_1 V_8 ;
if ( ! ( V_2 -> V_5 & V_6 ) )
return;
F_4 ( V_2 -> V_11 , V_10 ) ;
V_8 = F_2 ( V_2 -> V_7 + V_2 -> V_8 ) ;
F_5 ( V_8 | V_4 -> V_9 , V_2 -> V_7 + V_2 -> V_8 ) ;
F_6 ( V_2 -> V_11 , V_10 ) ;
}
bool F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned long V_12 )
{
if ( ! ( V_2 -> V_5 & V_6 ) )
return false ;
return ( V_4 -> V_13 [ 0 ] == V_12 ) || ( V_4 -> V_13 [ 1 ] == V_12 ) ;
}
unsigned long F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_1 V_8 ;
F_10 ( L_1 , F_11 ( & V_2 -> V_14 ) ) ;
if ( ! ( V_2 -> V_5 & V_6 ) )
return 0 ;
F_10 ( L_2 ,
F_11 ( & V_2 -> V_14 ) , V_4 -> V_13 [ 0 ] , V_4 -> V_13 [ 1 ] ) ;
V_8 = F_2 ( V_2 -> V_7 + V_2 -> V_8 ) ;
F_10 ( L_3 ,
F_11 ( & V_2 -> V_14 ) , V_8 , V_4 -> V_15 ) ;
return ( V_8 & V_4 -> V_15 ) ? V_4 -> V_13 [ 1 ] : V_4 -> V_13 [ 0 ] ;
}
int F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned long V_12 , T_1 V_11 )
{
unsigned long V_10 ;
T_1 V_8 , V_16 ;
if ( ! ( V_2 -> V_5 & V_6 ) )
return - V_17 ;
if ( V_4 -> V_13 [ 0 ] == V_12 )
V_16 = 0 ;
else if ( V_4 -> V_13 [ 1 ] == V_12 )
V_16 = V_4 -> V_15 ;
else
return - V_17 ;
F_4 ( V_2 -> V_11 , V_10 ) ;
V_8 = F_2 ( V_2 -> V_7 + V_2 -> V_8 ) ;
V_8 &= ~ V_4 -> V_15 ;
F_5 ( V_8 | V_16 , V_2 -> V_7 + V_2 -> V_8 ) ;
F_6 ( V_2 -> V_11 , V_10 ) ;
F_13 ( V_2 , V_11 ) ;
return 0 ;
}
