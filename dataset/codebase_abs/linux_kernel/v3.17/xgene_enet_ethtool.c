static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
strcpy ( V_4 -> V_9 , L_1 ) ;
strcpy ( V_4 -> V_10 , V_11 ) ;
snprintf ( V_4 -> V_12 , V_13 , L_2 ) ;
sprintf ( V_4 -> V_14 , L_3 , V_8 -> V_15 ) ;
}
static int F_3 ( struct V_1 * V_2 , struct V_16 * V_17 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_18 * V_19 = V_6 -> V_20 ;
if ( V_19 == NULL )
return - V_21 ;
return F_4 ( V_19 , V_17 ) ;
}
static int F_5 ( struct V_1 * V_2 , struct V_16 * V_17 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_18 * V_19 = V_6 -> V_20 ;
if ( V_19 == NULL )
return - V_21 ;
return F_6 ( V_19 , V_17 ) ;
}
static void F_7 ( struct V_1 * V_2 , T_1 V_22 , T_2 * V_23 )
{
int V_24 ;
T_2 * V_25 = V_23 ;
if ( V_22 != V_26 )
return;
for ( V_24 = 0 ; V_24 < V_27 ; V_24 ++ ) {
memcpy ( V_25 , V_28 [ V_24 ] . V_15 , V_29 ) ;
V_25 += V_29 ;
}
}
static int F_8 ( struct V_1 * V_2 , int V_30 )
{
if ( V_30 != V_26 )
return - V_31 ;
return V_27 ;
}
static void F_9 ( struct V_1 * V_2 ,
struct V_32 * V_33 ,
T_3 * V_23 )
{
void * V_6 = F_2 ( V_2 ) ;
int V_24 ;
for ( V_24 = 0 ; V_24 < V_27 ; V_24 ++ )
* V_23 ++ = * ( T_3 * ) ( V_6 + V_28 [ V_24 ] . V_34 ) ;
}
void F_10 ( struct V_1 * V_2 )
{
V_2 -> V_35 = & V_36 ;
}
