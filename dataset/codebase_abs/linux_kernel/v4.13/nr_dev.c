int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = & V_4 -> V_6 ;
if ( ! F_2 ( V_4 ) ) {
V_6 -> V_7 ++ ;
return 0 ;
}
V_6 -> V_8 ++ ;
V_6 -> V_9 += V_2 -> V_10 ;
V_2 -> V_11 = F_3 ( V_12 ) ;
V_2 -> V_4 = V_4 ;
V_2 -> V_13 = V_2 -> V_14 ;
F_4 ( V_2 ) ;
V_2 -> V_15 = V_16 ;
F_5 ( V_2 ) ;
return 1 ;
}
static int F_6 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned short type ,
const void * V_17 , const void * V_18 , unsigned int V_10 )
{
unsigned char * V_19 = F_7 ( V_2 , V_20 + V_21 ) ;
memcpy ( V_19 , ( V_18 != NULL ) ? V_18 : V_4 -> V_22 , V_4 -> V_23 ) ;
V_19 [ 6 ] &= ~ V_24 ;
V_19 [ 6 ] &= ~ V_25 ;
V_19 [ 6 ] |= V_26 ;
V_19 += V_27 ;
if ( V_17 != NULL )
memcpy ( V_19 , V_17 , V_4 -> V_23 ) ;
V_19 [ 6 ] &= ~ V_24 ;
V_19 [ 6 ] |= V_25 ;
V_19 [ 6 ] |= V_26 ;
V_19 += V_27 ;
* V_19 ++ = V_28 ;
* V_19 ++ = V_29 ;
* V_19 ++ = V_29 ;
* V_19 ++ = 0 ;
* V_19 ++ = 0 ;
* V_19 ++ = V_30 ;
if ( V_17 != NULL )
return 37 ;
return - 37 ;
}
static int T_1 F_8 ( struct V_3 * V_4 , void * V_31 )
{
struct V_32 * V_33 = V_31 ;
int V_34 ;
if ( ! memcmp ( V_4 -> V_22 , V_33 -> V_35 , V_4 -> V_23 ) )
return 0 ;
if ( V_4 -> V_36 & V_37 ) {
V_34 = F_9 ( ( V_38 * ) V_33 -> V_35 , NULL ) ;
if ( V_34 )
return V_34 ;
F_10 ( ( V_38 * ) V_4 -> V_22 , NULL ) ;
}
memcpy ( V_4 -> V_22 , V_33 -> V_35 , V_4 -> V_23 ) ;
return 0 ;
}
static int F_11 ( struct V_3 * V_4 )
{
int V_34 ;
V_34 = F_9 ( ( V_38 * ) V_4 -> V_22 , NULL ) ;
if ( V_34 )
return V_34 ;
F_12 ( V_4 ) ;
return 0 ;
}
static int F_13 ( struct V_3 * V_4 )
{
F_10 ( ( V_38 * ) V_4 -> V_22 , NULL ) ;
F_14 ( V_4 ) ;
return 0 ;
}
static T_2 F_15 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = & V_4 -> V_6 ;
unsigned int V_10 = V_2 -> V_10 ;
if ( ! F_16 ( V_2 , NULL ) ) {
F_17 ( V_2 ) ;
V_6 -> V_39 ++ ;
return V_40 ;
}
V_6 -> V_41 ++ ;
V_6 -> V_42 += V_10 ;
return V_40 ;
}
void F_18 ( struct V_3 * V_4 )
{
V_4 -> V_43 = V_44 ;
V_4 -> V_45 = & V_46 ;
V_4 -> V_47 = & V_48 ;
V_4 -> V_49 = V_20 + V_21 ;
V_4 -> V_23 = V_27 ;
V_4 -> type = V_50 ;
V_4 -> V_36 = V_51 ;
}
