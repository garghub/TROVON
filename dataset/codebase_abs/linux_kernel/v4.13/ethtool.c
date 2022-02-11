static void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_5 ; V_4 ++ ) {
V_3 = F_2 ( V_2 , V_6 [ V_4 ] . V_7 ) ;
V_6 [ V_4 ] . V_8 += V_3 ;
}
}
static void F_3 ( struct V_9 * V_10 ,
struct V_11 * V_12 )
{
struct V_1 * V_2 = F_4 ( V_10 ) ;
struct V_13 * V_14 = V_2 -> V_14 ;
strcpy ( V_12 -> V_15 , L_1 ) ;
strcpy ( V_12 -> V_16 , V_17 ) ;
snprintf ( V_12 -> V_18 , V_19 , L_2 ) ;
sprintf ( V_12 -> V_20 , L_3 , V_14 -> V_21 ) ;
}
static void F_5 ( struct V_9 * V_10 , T_1 V_22 , T_2 * V_3 )
{
T_2 * V_23 = V_3 ;
int V_4 ;
if ( V_22 != V_24 )
return;
for ( V_4 = 0 ; V_4 < V_25 ; V_4 ++ ) {
memcpy ( V_23 , V_26 [ V_4 ] . V_21 , V_27 ) ;
V_23 += V_27 ;
}
for ( V_4 = 0 ; V_4 < V_5 ; V_4 ++ ) {
memcpy ( V_23 , V_6 [ V_4 ] . V_21 , V_27 ) ;
V_23 += V_27 ;
}
}
static int F_6 ( struct V_9 * V_10 , int V_28 )
{
if ( V_28 != V_24 )
return - V_29 ;
return V_25 + V_5 ;
}
static void F_7 ( struct V_9 * V_10 ,
struct V_30 * V_31 ,
T_3 * V_3 )
{
void * V_2 = F_4 ( V_10 ) ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_25 ; V_4 ++ )
* V_3 ++ = * ( T_3 * ) ( V_2 + V_26 [ V_4 ] . V_32 ) ;
F_1 ( V_2 ) ;
for ( V_4 = 0 ; V_4 < V_5 ; V_4 ++ )
* V_3 ++ = V_6 [ V_4 ] . V_8 ;
}
static int F_8 ( struct V_9 * V_10 ,
struct V_33 * V_34 )
{
struct V_35 * V_36 = V_10 -> V_36 ;
if ( ! V_36 )
return - V_37 ;
F_9 ( V_36 , V_34 ) ;
return 0 ;
}
static int F_10 ( struct V_9 * V_10 ,
const struct V_33 * V_34 )
{
struct V_35 * V_36 = V_10 -> V_36 ;
if ( ! V_36 )
return - V_37 ;
return F_11 ( V_36 , V_34 ) ;
}
void F_12 ( struct V_9 * V_10 )
{
V_10 -> V_38 = & V_39 ;
}
