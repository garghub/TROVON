static struct V_1 *
F_1 ( struct V_2 * V_3 , struct V_4 * V_5 , struct V_6 * * V_7 )
{
T_1 V_8 = V_3 -> V_9 -> V_10 ;
const char * V_11 = V_5 -> V_12 . V_11 ;
int V_13 = V_5 -> V_12 . V_14 ;
T_2 V_15 = F_2 ( V_3 -> V_16 ) ;
struct V_1 * V_17 = NULL ;
T_2 V_18 = 0 ;
struct V_19 * V_20 = F_3 ( V_3 -> V_9 ) ;
while ( V_18 < V_15 ) {
struct V_6 * V_21 ;
char * V_22 ;
int V_23 = V_18 & ~ V_24 ;
V_21 = F_4 ( V_3 -> V_25 , V_18 >> V_26 ) ;
if ( F_5 ( V_21 ) )
return NULL ;
V_22 = ( char * ) F_6 ( V_21 ) ;
while ( V_23 < V_27 && V_18 < V_15 ) {
struct V_1 * V_28 ;
if ( ( V_18 & ( V_8 - 1 ) ) < 4 ) {
struct V_29 * V_30 =
(struct V_29 * )
( V_22 + ( V_18 & ~ V_24 ) ) ;
int V_31 = F_7 ( V_20 , V_30 ) ;
V_18 += V_31 ;
V_23 += V_31 ;
}
V_28 = (struct V_1 * ) ( V_22 + V_23 ) ;
if ( ! V_28 -> V_32 ) {
V_18 += V_8 - 1 ;
V_18 &= ~ ( V_8 - 1 ) ;
break;
}
V_23 += F_8 ( V_20 , V_28 -> V_32 ) ;
V_18 += F_8 ( V_20 , V_28 -> V_32 ) ;
if ( ! V_28 -> V_33 )
continue;
if ( V_13 != F_8 ( V_20 , V_28 -> V_34 ) )
continue;
if ( ! memcmp ( V_11 , V_28 -> V_12 , V_13 ) ) {
* V_7 = V_21 ;
V_17 = V_28 ;
break;
}
}
if ( ! V_17 )
F_9 ( V_21 ) ;
else
break;
}
return V_17 ;
}
static T_3
F_10 ( struct V_2 * V_35 , struct V_4 * V_5 )
{
struct V_1 * V_28 ;
struct V_6 * V_21 ;
T_3 V_36 = 0 ;
V_28 = F_1 ( V_35 , V_5 , & V_21 ) ;
if ( V_28 ) {
V_36 = F_11 ( F_3 ( V_35 -> V_9 ) , V_28 -> V_33 ) ;
F_12 ( V_21 ) ;
F_13 ( V_21 ) ;
}
return ( V_36 ) ;
}
static struct V_4 *
F_14 ( struct V_2 * V_35 , struct V_4 * V_5 , unsigned int V_37 )
{
struct V_2 * V_3 = NULL ;
T_3 V_36 ;
if ( V_5 -> V_12 . V_14 > V_38 )
return F_15 ( - V_39 ) ;
V_36 = F_10 ( V_35 , V_5 ) ;
if ( V_36 ) {
V_3 = F_16 ( V_35 -> V_9 , V_36 ) ;
if ( F_5 ( V_3 ) )
return F_17 ( V_3 ) ;
}
F_18 ( V_5 , V_3 ) ;
return NULL ;
}
static int
F_19 ( struct V_40 * V_41 , struct V_42 * V_43 )
{
struct V_2 * V_3 = F_20 ( V_41 ) ;
struct V_44 * V_45 = V_3 -> V_9 ;
T_1 V_8 = V_45 -> V_10 ;
T_2 V_18 , V_15 ;
struct V_19 * V_20 = F_3 ( V_45 ) ;
if ( V_43 -> V_18 == 0 ) {
if ( ! F_21 ( V_41 , V_43 ) )
goto V_46;
V_43 -> V_18 ++ ;
}
if ( V_43 -> V_18 == 1 ) {
if ( ! F_22 ( V_43 , L_1 , 2 , F_23 ( V_3 ) -> V_47 , V_48 ) )
goto V_46;
V_43 -> V_18 ++ ;
}
V_15 = F_2 ( V_3 -> V_16 ) ;
if ( V_43 -> V_18 > V_15 )
goto V_46;
V_18 = V_43 -> V_18 & ~ 3L ;
while ( V_18 < V_15 ) {
struct V_6 * V_21 ;
char * V_22 ;
int V_23 = V_18 & ~ V_24 ;
int V_49 = 0 ;
V_21 = F_4 ( V_3 -> V_25 , V_18 >> V_26 ) ;
if ( F_5 ( V_21 ) )
return - V_50 ;
V_22 = ( char * ) F_6 ( V_21 ) ;
while ( V_23 < V_27 && V_18 < V_15 ) {
struct V_1 * V_28 ;
if ( ( V_18 & ( V_8 - 1 ) ) < 4 ) {
struct V_29 * V_30 =
(struct V_29 * )
( V_22 + ( V_18 & ~ V_24 ) ) ;
int V_31 = F_7 ( V_20 , V_30 ) ;
V_18 += V_31 ;
V_23 += V_31 ;
}
V_28 = (struct V_1 * ) ( V_22 + V_23 ) ;
if ( ! V_28 -> V_32 ) {
V_18 += V_8 - 1 ;
V_18 &= ~ ( V_8 - 1 ) ;
break;
}
V_23 += F_8 ( V_20 , V_28 -> V_32 ) ;
V_18 += F_8 ( V_20 , V_28 -> V_32 ) ;
if ( ! V_28 -> V_33 )
continue;
V_49 = F_22 ( V_43 , V_28 -> V_12 ,
F_8 ( V_20 , V_28 -> V_34 ) ,
F_11 ( V_20 , V_28 -> V_33 ) ,
V_51 ) ;
if ( ! V_49 ) {
V_18 -= F_8 ( V_20 , V_28 -> V_32 ) ;
break;
}
}
F_9 ( V_21 ) ;
if ( ! V_49 )
break;
}
V_43 -> V_18 = V_18 | 2 ;
V_46:
return 0 ;
}
