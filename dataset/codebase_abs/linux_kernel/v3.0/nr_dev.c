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
static int F_6 ( struct V_1 * V_2 )
{
unsigned char * V_17 = V_2 -> V_18 ;
if ( F_7 ( V_17 + 7 , V_2 ) )
return 1 ;
V_17 [ 6 ] &= ~ V_19 ;
V_17 [ 6 ] &= ~ V_20 ;
V_17 [ 6 ] |= V_21 ;
V_17 += V_22 ;
V_17 [ 6 ] &= ~ V_19 ;
V_17 [ 6 ] |= V_20 ;
V_17 [ 6 ] |= V_21 ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
return 1 ;
}
static int F_8 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned short type ,
const void * V_23 , const void * V_24 , unsigned V_10 )
{
unsigned char * V_25 = F_9 ( V_2 , V_26 + V_27 ) ;
memcpy ( V_25 , ( V_24 != NULL ) ? V_24 : V_4 -> V_28 , V_4 -> V_29 ) ;
V_25 [ 6 ] &= ~ V_19 ;
V_25 [ 6 ] &= ~ V_20 ;
V_25 [ 6 ] |= V_21 ;
V_25 += V_22 ;
if ( V_23 != NULL )
memcpy ( V_25 , V_23 , V_4 -> V_29 ) ;
V_25 [ 6 ] &= ~ V_19 ;
V_25 [ 6 ] |= V_20 ;
V_25 [ 6 ] |= V_21 ;
V_25 += V_22 ;
* V_25 ++ = V_30 ;
* V_25 ++ = V_31 ;
* V_25 ++ = V_31 ;
* V_25 ++ = 0 ;
* V_25 ++ = 0 ;
* V_25 ++ = V_32 ;
if ( V_23 != NULL )
return 37 ;
return - 37 ;
}
static int T_1 F_10 ( struct V_3 * V_4 , void * V_33 )
{
struct V_34 * V_35 = V_33 ;
int V_36 ;
if ( ! memcmp ( V_4 -> V_28 , V_35 -> V_37 , V_4 -> V_29 ) )
return 0 ;
if ( V_4 -> V_38 & V_39 ) {
V_36 = F_11 ( ( V_40 * ) V_35 -> V_37 , NULL ) ;
if ( V_36 )
return V_36 ;
F_12 ( ( V_40 * ) V_4 -> V_28 , NULL ) ;
}
memcpy ( V_4 -> V_28 , V_35 -> V_37 , V_4 -> V_29 ) ;
return 0 ;
}
static int F_13 ( struct V_3 * V_4 )
{
int V_36 ;
V_36 = F_11 ( ( V_40 * ) V_4 -> V_28 , NULL ) ;
if ( V_36 )
return V_36 ;
F_14 ( V_4 ) ;
return 0 ;
}
static int F_15 ( struct V_3 * V_4 )
{
F_12 ( ( V_40 * ) V_4 -> V_28 , NULL ) ;
F_16 ( V_4 ) ;
return 0 ;
}
static T_2 F_17 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = & V_4 -> V_6 ;
unsigned int V_10 = V_2 -> V_10 ;
if ( ! F_18 ( V_2 , NULL ) ) {
F_19 ( V_2 ) ;
V_6 -> V_41 ++ ;
return V_42 ;
}
V_6 -> V_43 ++ ;
V_6 -> V_44 += V_10 ;
return V_42 ;
}
void F_20 ( struct V_3 * V_4 )
{
V_4 -> V_45 = V_46 ;
V_4 -> V_47 = & V_48 ;
V_4 -> V_49 = & V_50 ;
V_4 -> V_51 = V_26 + V_27 ;
V_4 -> V_29 = V_22 ;
V_4 -> type = V_52 ;
V_4 -> V_38 = V_53 ;
}
