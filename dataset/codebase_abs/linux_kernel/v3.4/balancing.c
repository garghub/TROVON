void F_1 ( unsigned int V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
unsigned long V_4 = V_5 [ V_1 ] ;
unsigned long V_6 ;
if ( F_3 ( V_1 ) || ! V_4 )
return;
V_6 = F_4 ( V_3 , F_5 ( V_4 ) , 0 ) ;
V_7 [ F_6 ( V_4 ) ] ( V_6 , V_4 , 1 ) ;
}
void F_7 ( unsigned int V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
unsigned long V_4 = V_5 [ V_1 ] ;
unsigned long V_6 ;
if ( F_3 ( V_1 ) || ! V_4 )
return;
V_6 = F_4 ( V_3 , F_5 ( V_4 ) , 0 ) ;
V_7 [ F_6 ( V_4 ) ] ( V_6 , V_4 , 0 ) ;
}
static unsigned int F_8 ( struct V_8 * V_9 ,
struct V_2 * V_3 ,
T_1 V_10 )
{
struct V_11 * V_12 = V_9 -> V_13 . V_14 ;
unsigned int V_15 , V_16 , V_17 , V_18 ;
unsigned long V_19 , V_20 ;
for ( V_15 = 0 ; V_12 && V_10 && V_15 < V_9 -> V_13 . V_21 ; V_15 ++ ) {
V_12 = V_9 -> V_13 . V_14 + V_15 ;
if ( ! V_12 -> V_22 )
continue;
for ( V_16 = 0 ; V_16 < F_9 ( V_12 -> V_23 ) ; V_16 ++ ) {
if ( V_12 -> V_23 [ V_16 ] != V_10 )
continue;
V_17 = V_24 ;
V_18 = V_25 ;
V_19 = V_12 -> V_22 ;
V_20 = V_12 -> V_22 ;
V_17 += ( V_12 -> V_26 >> 3 ) - 1 ;
return F_10 ( V_17 , V_18 ,
F_11 ( V_3 , V_19 ) ,
F_11 ( V_3 , V_20 ) ,
1 ,
( V_12 -> V_26 - 1 ) - V_16 ) ;
}
}
return 0 ;
}
void F_12 ( unsigned int V_1 , struct V_8 * V_9 ,
struct V_2 * V_3 , T_1 V_27 )
{
unsigned long V_28 ;
if ( ! V_9 -> V_13 . V_14 )
return;
F_13 ( & V_29 , V_28 ) ;
V_5 [ V_1 ] = F_8 ( V_9 , V_3 , V_27 ) ;
F_14 ( & V_29 , V_28 ) ;
}
