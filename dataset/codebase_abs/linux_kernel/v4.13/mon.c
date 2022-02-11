static void F_1 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
struct V_5 * V_6 ;
int V_7 ;
V_6 = (struct V_5 * ) V_2 -> V_8 ;
V_7 = F_2 ( V_6 -> V_9 ) ;
if ( V_2 -> V_10 < V_7 + V_3 + V_4 )
return;
if ( ! F_3 ( V_6 -> V_9 ) )
return;
V_6 -> V_9 &= ~ F_4 ( V_11 ) ;
memmove ( V_2 -> V_8 + V_3 , V_2 -> V_8 , V_7 ) ;
F_5 ( V_2 , V_3 ) ;
F_6 ( V_2 , V_2 -> V_10 - V_4 ) ;
}
static void F_7 ( struct V_12 * V_13 , const T_1 * V_8 ,
int V_14 , int V_3 , int V_4 )
{
struct V_1 * V_2 ;
V_2 = F_8 ( V_13 , V_14 ) ;
if ( ! V_2 )
return;
F_9 ( V_2 , V_8 , V_14 ) ;
F_1 ( V_2 , V_3 , V_4 ) ;
V_2 -> V_15 = V_16 ;
V_2 -> V_17 = F_10 ( V_2 , V_13 ) ;
F_11 ( V_2 ) ;
}
static void F_12 ( struct V_12 * V_13 , const T_1 * V_8 ,
int V_14 )
{
struct V_1 * V_2 ;
struct V_5 * V_6 ;
int V_7 ;
V_2 = F_8 ( V_13 , V_14 ) ;
if ( ! V_2 )
return;
memcpy ( F_13 ( V_2 , V_14 ) , V_8 , V_14 ) ;
V_6 = (struct V_5 * ) V_2 -> V_8 ;
V_7 = F_2 ( V_6 -> V_9 ) ;
if ( F_3 ( V_6 -> V_9 ) )
V_6 -> V_9 &= ~ F_4 ( V_11 ) ;
V_2 -> V_15 = V_16 ;
V_2 -> V_17 = F_10 ( V_2 , V_13 ) ;
F_11 ( V_2 ) ;
}
static void F_14 ( struct V_12 * V_13 , const T_1 * V_8 ,
int V_14 )
{
if ( F_15 () )
F_16 ( V_13 , L_1 ) ;
}
void F_17 ( struct V_12 * V_13 , struct V_18 * V_19 )
{
struct V_20 * V_21 ;
int V_14 ;
T_1 * V_8 ;
if ( ! V_13 || ! V_19 )
return;
if ( ! F_18 ( V_13 ) )
return;
V_21 = & V_19 -> V_22 ;
V_8 = V_19 -> V_23 -> V_8 ;
V_14 = V_19 -> V_23 -> V_10 ;
if ( V_21 -> V_24 )
F_12 ( V_13 , V_8 , V_14 ) ;
else
F_14 ( V_13 , V_8 , V_14 ) ;
}
void F_19 ( struct V_12 * V_13 , struct V_25 * V_19 ,
T_2 V_26 )
{
struct V_27 * V_21 ;
T_1 * V_8 ;
int V_28 , V_29 ;
if ( ! V_13 || ! V_19 )
return;
if ( ! F_18 ( V_13 ) )
return;
V_21 = & V_19 -> V_22 ;
V_29 = V_30 + V_19 -> V_31 * V_32 ;
V_8 = V_19 -> V_33 + V_29 ;
for ( V_28 = 0 ; V_28 < V_21 -> V_34 - 1 ; V_28 ++ ) {
F_7 ( V_13 , V_8 , V_26 , V_21 -> V_3 , 0 ) ;
V_8 += V_26 ;
V_8 = ( T_1 * ) F_20 ( ( V_35 ) V_8 , 4 ) ;
}
F_7 ( V_13 , V_8 , V_21 -> V_36 , V_21 -> V_3 , 0 ) ;
}
static T_3 F_21 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
F_22 ( V_2 ) ;
return V_37 ;
}
static void F_23 ( struct V_12 * V_13 )
{
V_13 -> V_38 = & V_39 ;
V_13 -> V_40 = true ;
F_24 ( V_13 ) ;
V_13 -> V_41 |= V_42 ;
V_13 -> type = V_43 ;
F_25 ( V_13 -> V_44 ) ;
V_13 -> V_44 [ 0 ] = 0x12 ;
}
struct V_12 * F_26 ( void )
{
struct V_12 * V_13 ;
int V_45 ;
V_13 = F_27 ( 0 , L_2 , V_46 , F_23 ) ;
if ( ! V_13 )
goto V_47;
V_45 = F_28 ( V_13 ) ;
if ( V_45 < 0 )
goto V_48;
return V_13 ;
V_48:
F_29 ( V_13 ) ;
V_47:
return NULL ;
}
void F_30 ( struct V_12 * V_13 )
{
if ( ! V_13 )
return;
F_31 ( V_13 ) ;
}
