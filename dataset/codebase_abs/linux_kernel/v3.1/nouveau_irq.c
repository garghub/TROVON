void
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_2 ( V_2 , V_6 , 0 ) ;
F_3 ( & V_4 -> V_7 ) ;
}
int
F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_2 ( V_2 , V_6 , V_8 ) ;
if ( V_4 -> V_9 )
F_5 ( V_2 , 0x00088068 , 0xff ) ;
return 0 ;
}
void
F_6 ( struct V_1 * V_2 )
{
F_2 ( V_2 , V_6 , 0 ) ;
}
T_1
F_7 ( T_2 )
{
struct V_1 * V_2 = (struct V_1 * ) V_10 ;
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned long V_11 ;
T_3 V_12 ;
int V_13 ;
V_12 = F_8 ( V_2 , V_14 ) ;
if ( V_12 == 0 || V_12 == ~ 0 )
return V_15 ;
F_9 ( & V_4 -> V_16 , V_11 ) ;
for ( V_13 = 0 ; V_13 < 32 && V_12 ; V_13 ++ ) {
if ( ! ( V_12 & ( 1 << V_13 ) ) || ! V_4 -> V_17 [ V_13 ] )
continue;
V_4 -> V_17 [ V_13 ] ( V_2 ) ;
V_12 &= ~ ( 1 << V_13 ) ;
}
if ( V_4 -> V_9 )
F_5 ( V_2 , 0x00088068 , 0xff ) ;
F_10 ( & V_4 -> V_16 , V_11 ) ;
if ( V_12 && F_11 () )
F_12 ( V_2 , L_1 , V_12 ) ;
return V_18 ;
}
int
F_13 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_19 ;
if ( V_20 != 0 && V_4 -> V_21 >= V_22 ) {
V_19 = F_14 ( V_2 -> V_23 ) ;
if ( V_19 == 0 ) {
F_15 ( V_2 , L_2 ) ;
V_4 -> V_9 = true ;
}
}
return F_16 ( V_2 ) ;
}
void
F_17 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_18 ( V_2 ) ;
if ( V_4 -> V_9 )
F_19 ( V_2 -> V_23 ) ;
}
void
F_20 ( struct V_1 * V_2 , int V_24 ,
void (* F_21)( struct V_1 * ) )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned long V_11 ;
F_9 ( & V_4 -> V_16 , V_11 ) ;
V_4 -> V_17 [ V_24 ] = F_21 ;
F_10 ( & V_4 -> V_16 , V_11 ) ;
}
void
F_22 ( struct V_1 * V_2 , int V_24 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned long V_11 ;
F_9 ( & V_4 -> V_16 , V_11 ) ;
V_4 -> V_17 [ V_24 ] = NULL ;
F_10 ( & V_4 -> V_16 , V_11 ) ;
}
