static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned short type ,
const void * V_5 , const void * V_6 , unsigned int V_7 )
{
unsigned char * V_8 = F_2 ( V_2 , V_9 + 2 ) ;
if ( V_5 )
memcpy ( V_8 + 7 , V_5 , V_4 -> V_10 ) ;
* V_8 ++ = V_11 | V_12 ;
* V_8 ++ = 0x00 ;
* V_8 ++ = V_13 ;
* V_8 ++ = 0x7F ;
* V_8 ++ = V_14 ;
if ( V_5 != NULL )
return 37 ;
return - 37 ;
}
static int F_3 ( struct V_3 * V_4 , void * V_15 )
{
struct V_16 * V_17 = V_15 ;
int V_18 ;
if ( ! memcmp ( V_4 -> V_19 , V_17 -> V_20 , V_4 -> V_10 ) )
return 0 ;
if ( V_4 -> V_21 & V_22 ) {
V_18 = F_4 ( ( V_23 * ) V_17 -> V_20 ) ;
if ( V_18 )
return V_18 ;
F_5 ( ( V_23 * ) V_4 -> V_19 ) ;
}
memcpy ( V_4 -> V_19 , V_17 -> V_20 , V_4 -> V_10 ) ;
return 0 ;
}
static int F_6 ( struct V_3 * V_4 )
{
int V_18 ;
V_18 = F_4 ( ( V_23 * ) V_4 -> V_19 ) ;
if ( V_18 )
return V_18 ;
F_7 ( V_4 ) ;
return 0 ;
}
static int F_8 ( struct V_3 * V_4 )
{
F_9 ( V_4 ) ;
F_5 ( ( V_23 * ) V_4 -> V_19 ) ;
return 0 ;
}
static T_1 F_10 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_24 * V_25 = & V_4 -> V_25 ;
unsigned int V_7 = V_2 -> V_7 ;
if ( ! F_11 ( V_4 ) ) {
F_12 ( V_26 L_1 ) ;
return V_27 ;
}
if ( ! F_13 ( V_2 , NULL ) ) {
F_14 ( V_2 ) ;
V_25 -> V_28 ++ ;
return V_29 ;
}
V_25 -> V_30 ++ ;
V_25 -> V_31 += V_7 ;
return V_29 ;
}
void F_15 ( struct V_3 * V_4 )
{
V_4 -> V_32 = V_33 - 2 ;
V_4 -> V_34 = & V_35 ;
V_4 -> V_36 = & V_37 ;
V_4 -> V_38 = V_39 + V_40 + V_9 ;
V_4 -> V_10 = V_41 ;
V_4 -> type = V_42 ;
V_4 -> V_21 = V_43 ;
}
