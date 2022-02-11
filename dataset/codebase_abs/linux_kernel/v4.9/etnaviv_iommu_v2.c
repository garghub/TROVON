static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_2 * V_3 , unsigned long V_4 ,
T_1 V_5 , T_2 V_6 , int V_7 )
{
struct V_1 * V_8 =
F_1 ( V_3 ) ;
int V_9 , V_10 ;
T_3 V_11 = ( T_3 ) V_5 | V_12 ;
if ( V_6 != V_13 )
return - V_14 ;
if ( V_7 & V_15 )
V_11 |= V_16 ;
V_9 = ( V_4 & V_17 ) >> V_18 ;
V_10 = ( V_4 & V_19 ) >> V_20 ;
V_8 -> V_21 [ V_9 ] [ V_10 ] = V_11 ;
return 0 ;
}
static T_2 F_4 ( struct V_2 * V_3 ,
unsigned long V_4 , T_2 V_6 )
{
struct V_1 * V_8 =
F_1 ( V_3 ) ;
int V_9 , V_10 ;
if ( V_6 != V_13 )
return - V_14 ;
V_9 = ( V_4 & V_17 ) >> V_18 ;
V_10 = ( V_4 & V_19 ) >> V_20 ;
V_8 -> V_21 [ V_9 ] [ V_10 ] = V_22 ;
return V_13 ;
}
static T_1 F_5 ( struct V_2 * V_3 ,
T_4 V_4 )
{
struct V_1 * V_8 =
F_1 ( V_3 ) ;
int V_9 , V_10 ;
V_9 = ( V_4 & V_17 ) >> V_18 ;
V_10 = ( V_4 & V_19 ) >> V_20 ;
return V_8 -> V_21 [ V_9 ] [ V_10 ] & ~ ( V_13 - 1 ) ;
}
static int F_6 ( struct V_1 * V_8 )
{
T_3 * V_23 ;
int V_24 , V_25 , V_26 ;
V_8 -> V_27 = F_7 ( V_8 -> V_28 ,
V_13 ,
& V_8 -> V_29 ,
V_30 ) ;
if ( ! V_8 -> V_27 ) {
V_24 = - V_31 ;
goto V_32;
}
V_23 = V_8 -> V_27 ;
for ( V_25 = 0 ; V_25 < V_13 / 4 ; V_25 ++ )
* V_23 ++ = 0xdead55aa ;
V_8 -> V_33 = F_7 ( V_8 -> V_28 ,
V_13 ,
& V_8 -> V_34 ,
V_30 ) ;
if ( ! V_8 -> V_33 ) {
V_24 = - V_31 ;
goto V_32;
}
for ( V_25 = 0 ; V_25 < V_35 ; V_25 ++ ) {
V_8 -> V_21 [ V_25 ] =
F_7 ( V_8 -> V_28 ,
V_13 ,
& V_8 -> V_36 [ V_25 ] ,
V_30 ) ;
if ( ! V_8 -> V_21 [ V_25 ] ) {
V_24 = - V_31 ;
goto V_32;
}
V_23 = V_8 -> V_21 [ V_25 ] ;
for ( V_26 = 0 ; V_26 < V_13 / 4 ; V_26 ++ )
* V_23 ++ = V_22 ;
V_8 -> V_33 [ V_25 ] = V_8 -> V_36 [ V_25 ] |
V_12 ;
}
return 0 ;
V_32:
if ( V_8 -> V_27 )
F_8 ( V_8 -> V_28 , V_13 ,
V_8 -> V_27 ,
V_8 -> V_29 ) ;
if ( V_8 -> V_33 )
F_8 ( V_8 -> V_28 , V_13 ,
V_8 -> V_33 ,
V_8 -> V_34 ) ;
for ( V_25 = 0 ; V_25 < V_35 ; V_25 ++ ) {
if ( V_8 -> V_21 [ V_25 ] )
F_8 ( V_8 -> V_28 , V_13 ,
V_8 -> V_21 [ V_25 ] ,
V_8 -> V_36 [ V_25 ] ) ;
}
return V_24 ;
}
static void F_9 ( struct V_2 * V_3 )
{
struct V_1 * V_8 =
F_1 ( V_3 ) ;
int V_25 ;
F_8 ( V_8 -> V_28 , V_13 ,
V_8 -> V_27 ,
V_8 -> V_29 ) ;
F_8 ( V_8 -> V_28 , V_13 ,
V_8 -> V_33 ,
V_8 -> V_34 ) ;
for ( V_25 = 0 ; V_25 < V_35 ; V_25 ++ ) {
if ( V_8 -> V_21 [ V_25 ] )
F_8 ( V_8 -> V_28 , V_13 ,
V_8 -> V_21 [ V_25 ] ,
V_8 -> V_36 [ V_25 ] ) ;
}
F_10 ( V_8 ) ;
}
static T_2 F_11 ( struct V_2 * V_3 )
{
struct V_1 * V_8 =
F_1 ( V_3 ) ;
T_2 V_37 = V_13 ;
int V_25 ;
for ( V_25 = 0 ; V_25 < V_35 ; V_25 ++ )
if ( V_8 -> V_33 [ V_25 ] & V_12 )
V_37 += V_13 ;
return V_37 ;
}
static void F_12 ( struct V_2 * V_3 , void * V_38 )
{
struct V_1 * V_8 =
F_1 ( V_3 ) ;
int V_25 ;
memcpy ( V_38 , V_8 -> V_33 , V_13 ) ;
V_38 += V_13 ;
for ( V_25 = 0 ; V_25 < V_35 ; V_25 ++ , V_38 += V_13 )
if ( V_8 -> V_33 [ V_25 ] & V_12 )
memcpy ( V_38 , V_8 -> V_21 [ V_25 ] , V_13 ) ;
}
void F_13 ( struct V_39 * V_40 )
{
struct V_1 * V_8 =
F_1 ( V_40 -> V_41 -> V_3 ) ;
T_5 V_42 ;
if ( F_14 ( V_40 , V_43 ) & V_44 )
return;
V_42 = F_15 ( V_40 ,
( T_3 ) V_8 -> V_34 ,
( T_3 ) V_8 -> V_29 ) ;
F_16 ( V_40 , V_40 -> V_45 -> V_5 , V_42 ) ;
F_17 ( V_40 , 100 ) ;
F_18 ( V_40 , V_43 , V_44 ) ;
}
struct V_2 * F_19 ( struct V_39 * V_40 )
{
struct V_1 * V_8 ;
int V_24 ;
V_8 = F_20 ( sizeof( * V_8 ) ) ;
if ( ! V_8 )
return NULL ;
V_8 -> V_28 = V_40 -> V_28 ;
V_8 -> V_3 . type = V_46 ;
V_8 -> V_3 . V_47 = & V_48 . V_47 ;
V_8 -> V_3 . V_49 = V_13 ;
V_8 -> V_3 . V_50 . V_51 = 0 ;
V_8 -> V_3 . V_50 . V_52 = ~ 0UL & ~ ( V_13 - 1 ) ;
V_24 = F_6 ( V_8 ) ;
if ( V_24 )
goto V_53;
return & V_8 -> V_3 ;
V_53:
F_10 ( V_8 ) ;
return NULL ;
}
