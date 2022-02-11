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
memcpy ( F_9 ( V_2 , V_14 ) , V_8 , V_14 ) ;
F_1 ( V_2 , V_3 , V_4 ) ;
V_2 -> V_15 = V_16 ;
V_2 -> V_17 = F_10 ( V_2 , V_13 ) ;
F_11 ( V_2 ) ;
}
static void F_12 ( struct V_12 * V_13 , const T_1 * V_8 ,
int V_14 )
{
if ( F_13 () )
F_14 ( V_13 , L_1 ) ;
}
void F_15 ( struct V_12 * V_13 , struct V_18 * V_19 )
{
struct V_20 * V_21 ;
int V_3 , V_4 ;
int V_14 ;
T_1 * V_8 ;
if ( ! V_13 || ! V_19 )
return;
if ( ! F_16 ( V_13 ) )
return;
V_21 = & V_19 -> V_22 ;
V_8 = V_19 -> V_23 ;
V_14 = V_19 -> V_10 ;
F_17 ( V_3 , V_4 , V_21 -> V_24 ) ;
if ( V_21 -> V_25 )
F_7 ( V_13 , V_8 , V_14 , V_3 , V_4 ) ;
else
F_12 ( V_13 , V_8 , V_14 ) ;
}
void F_18 ( struct V_12 * V_13 , struct V_26 * V_19 ,
T_2 V_27 )
{
struct V_28 * V_21 ;
T_1 * V_8 ;
int V_29 , V_30 ;
if ( ! V_13 || ! V_19 )
return;
if ( ! F_16 ( V_13 ) )
return;
V_21 = & V_19 -> V_22 ;
V_30 = V_31 + V_19 -> V_32 * V_33 ;
V_8 = V_19 -> V_34 + V_30 ;
for ( V_29 = 0 ; V_29 < V_21 -> V_35 - 1 ; V_29 ++ ) {
F_7 ( V_13 , V_8 , V_27 , V_21 -> V_3 , 0 ) ;
V_8 += V_27 ;
V_8 = ( T_1 * ) F_19 ( ( V_36 ) V_8 , 4 ) ;
}
F_7 ( V_13 , V_8 , V_21 -> V_37 , V_21 -> V_3 , 0 ) ;
}
static T_3 F_20 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
F_21 ( V_2 ) ;
return V_38 ;
}
static void F_22 ( struct V_12 * V_13 )
{
V_13 -> V_39 = & V_40 ;
V_13 -> V_41 = V_42 ;
F_23 ( V_13 ) ;
V_13 -> V_43 |= V_44 ;
V_13 -> type = V_45 ;
F_24 ( V_13 -> V_46 ) ;
V_13 -> V_46 [ 0 ] = 0x12 ;
}
struct V_12 * F_25 ( void )
{
struct V_12 * V_13 ;
int V_47 ;
V_13 = F_26 ( 0 , L_2 , V_48 , F_22 ) ;
if ( ! V_13 )
goto V_49;
V_47 = F_27 ( V_13 ) ;
if ( V_47 < 0 )
goto V_50;
return V_13 ;
V_50:
V_42 ( V_13 ) ;
V_49:
return NULL ;
}
void F_28 ( struct V_12 * V_13 )
{
if ( ! V_13 )
return;
F_29 ( V_13 ) ;
}
