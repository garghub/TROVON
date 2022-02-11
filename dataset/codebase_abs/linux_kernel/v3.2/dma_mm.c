void * F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 * V_4 , T_3 V_5 )
{
struct V_6 * V_6 , * * V_7 ;
T_4 V_8 ;
void * V_9 ;
int V_10 , V_11 ;
F_2 ( L_1 , V_3 , V_5 ) ;
V_3 = F_3 ( V_3 ) ;
V_11 = F_4 ( V_3 ) ;
V_6 = F_5 ( V_5 , V_11 ) ;
if ( ! V_6 )
return NULL ;
* V_4 = F_6 ( V_6 ) ;
V_7 = F_7 ( sizeof( struct V_6 * ) << V_11 , V_5 & ~ V_12 ) ;
if ( ! V_7 ) {
F_8 ( V_6 , V_11 ) ;
return NULL ;
}
F_9 ( V_6 , V_11 ) ;
V_11 = 1 << V_11 ;
V_3 >>= V_13 ;
V_7 [ 0 ] = V_6 ;
for ( V_10 = 1 ; V_10 < V_3 ; V_10 ++ )
V_7 [ V_10 ] = V_6 + V_10 ;
for (; V_10 < V_11 ; V_10 ++ )
F_10 ( V_6 + V_10 ) ;
V_8 = F_11 ( V_14 | V_15 | V_16 ) ;
if ( V_17 )
F_12 ( V_8 ) |= V_18 | V_19 ;
else
F_12 ( V_8 ) |= V_20 ;
V_9 = F_13 ( V_7 , V_3 , V_21 , V_8 ) ;
F_14 ( V_7 ) ;
return V_9 ;
}
void F_15 ( struct V_1 * V_2 , T_1 V_3 ,
void * V_9 , T_2 V_4 )
{
F_2 ( L_2 , V_9 , V_4 ) ;
F_16 ( V_9 ) ;
}
void F_17 ( struct V_1 * V_2 , T_2 V_4 ,
T_1 V_3 , enum V_22 V_23 )
{
switch ( V_23 ) {
case V_24 :
F_18 ( V_4 , V_3 ) ;
break;
case V_25 :
F_19 ( V_4 , V_3 ) ;
break;
default:
if ( F_20 () )
F_21 ( L_3 , V_23 ) ;
break;
}
}
void F_22 ( struct V_1 * V_2 , struct V_26 * V_27 , int V_28 ,
enum V_22 V_23 )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < V_28 ; V_27 ++ , V_10 ++ )
F_17 ( V_2 , V_27 -> V_29 , V_27 -> V_30 , V_23 ) ;
}
T_2 F_23 ( struct V_1 * V_2 , void * V_9 , T_1 V_3 ,
enum V_22 V_23 )
{
T_2 V_4 = F_24 ( V_9 ) ;
F_17 ( V_2 , V_4 , V_3 , V_23 ) ;
return V_4 ;
}
T_2 F_25 ( struct V_1 * V_2 , struct V_6 * V_6 ,
unsigned long V_31 , T_1 V_3 ,
enum V_22 V_23 )
{
T_2 V_4 = F_6 ( V_6 ) + V_31 ;
F_17 ( V_2 , V_4 , V_3 , V_23 ) ;
return V_4 ;
}
int F_26 ( struct V_1 * V_2 , struct V_26 * V_27 , int V_28 ,
enum V_22 V_23 )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < V_28 ; V_27 ++ , V_10 ++ ) {
V_27 -> V_29 = F_27 ( V_27 ) ;
F_17 ( V_2 , V_27 -> V_29 , V_27 -> V_30 , V_23 ) ;
}
return V_28 ;
}
