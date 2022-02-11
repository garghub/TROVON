void
F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 , V_3 , 0 ) ;
}
int
F_3 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
F_2 ( V_2 , V_3 , V_7 ) ;
if ( V_5 -> V_8 )
F_4 ( V_2 , 0x00088068 , 0xff ) ;
return 0 ;
}
void
F_5 ( struct V_1 * V_2 )
{
F_2 ( V_2 , V_3 , 0 ) ;
}
T_1
F_6 ( T_2 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long V_10 ;
T_3 V_11 ;
int V_12 ;
V_11 = F_7 ( V_2 , V_13 ) ;
if ( V_11 == 0 || V_11 == ~ 0 )
return V_14 ;
F_8 ( & V_5 -> V_15 , V_10 ) ;
for ( V_12 = 0 ; V_12 < 32 && V_11 ; V_12 ++ ) {
if ( ! ( V_11 & ( 1 << V_12 ) ) || ! V_5 -> V_16 [ V_12 ] )
continue;
V_5 -> V_16 [ V_12 ] ( V_2 ) ;
V_11 &= ~ ( 1 << V_12 ) ;
}
if ( V_5 -> V_8 )
F_4 ( V_2 , 0x00088068 , 0xff ) ;
F_9 ( & V_5 -> V_15 , V_10 ) ;
if ( V_11 && F_10 () )
F_11 ( V_2 , L_1 , V_11 ) ;
return V_17 ;
}
int
F_12 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_18 ;
if ( V_19 != 0 && V_5 -> V_20 >= V_21 ) {
V_18 = F_13 ( V_2 -> V_22 ) ;
if ( V_18 == 0 ) {
F_14 ( V_2 , L_2 ) ;
V_5 -> V_8 = true ;
}
}
return F_15 ( V_2 ) ;
}
void
F_16 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
F_17 ( V_2 ) ;
if ( V_5 -> V_8 )
F_18 ( V_2 -> V_22 ) ;
}
void
F_19 ( struct V_1 * V_2 , int V_23 ,
void (* F_20)( struct V_1 * ) )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long V_10 ;
F_8 ( & V_5 -> V_15 , V_10 ) ;
V_5 -> V_16 [ V_23 ] = F_20 ;
F_9 ( & V_5 -> V_15 , V_10 ) ;
}
void
F_21 ( struct V_1 * V_2 , int V_23 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long V_10 ;
F_8 ( & V_5 -> V_15 , V_10 ) ;
V_5 -> V_16 [ V_23 ] = NULL ;
F_9 ( & V_5 -> V_15 , V_10 ) ;
}
