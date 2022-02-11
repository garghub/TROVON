static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned short type ,
const void * V_5 , const void * V_6 , unsigned int V_7 )
{
unsigned char * V_8 = F_2 ( V_2 , V_9 + 2 ) ;
* V_8 ++ = V_10 | V_11 ;
* V_8 ++ = 0x00 ;
* V_8 ++ = V_12 ;
* V_8 ++ = 0x7F ;
* V_8 ++ = V_13 ;
if ( V_5 != NULL )
return 37 ;
return - 37 ;
}
static int F_3 ( struct V_1 * V_2 )
{
#ifdef F_4
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_14 * V_15 = & V_4 -> V_15 ;
unsigned char * V_16 = ( unsigned char * ) V_2 -> V_17 ;
struct V_1 * V_18 ;
unsigned int V_7 ;
if ( F_5 ( V_16 + 7 , V_2 ) ) {
return 1 ;
}
if ( ( V_18 = F_6 ( V_2 , V_19 ) ) == NULL ) {
F_7 ( V_2 ) ;
return 1 ;
}
if ( V_2 -> V_20 != NULL )
F_8 ( V_18 , V_2 -> V_20 ) ;
F_7 ( V_2 ) ;
V_7 = V_18 -> V_7 ;
if ( ! F_9 ( V_18 , NULL ) ) {
F_7 ( V_18 ) ;
V_15 -> V_21 ++ ;
return 1 ;
}
V_15 -> V_22 ++ ;
V_15 -> V_23 += V_7 ;
#endif
return 1 ;
}
static int F_10 ( struct V_3 * V_4 , void * V_24 )
{
struct V_25 * V_26 = V_24 ;
int V_27 ;
if ( ! memcmp ( V_4 -> V_28 , V_26 -> V_29 , V_4 -> V_30 ) )
return 0 ;
if ( V_4 -> V_31 & V_32 ) {
V_27 = F_11 ( ( V_33 * ) V_26 -> V_29 ) ;
if ( V_27 )
return V_27 ;
F_12 ( ( V_33 * ) V_4 -> V_28 ) ;
}
memcpy ( V_4 -> V_28 , V_26 -> V_29 , V_4 -> V_30 ) ;
return 0 ;
}
static int F_13 ( struct V_3 * V_4 )
{
int V_27 ;
V_27 = F_11 ( ( V_33 * ) V_4 -> V_28 ) ;
if ( V_27 )
return V_27 ;
F_14 ( V_4 ) ;
return 0 ;
}
static int F_15 ( struct V_3 * V_4 )
{
F_16 ( V_4 ) ;
F_12 ( ( V_33 * ) V_4 -> V_28 ) ;
return 0 ;
}
static T_1 F_17 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_14 * V_15 = & V_4 -> V_15 ;
if ( ! F_18 ( V_4 ) ) {
F_19 ( V_34 L_1 ) ;
return V_35 ;
}
F_20 ( V_2 ) ;
V_15 -> V_21 ++ ;
return V_36 ;
}
void F_21 ( struct V_3 * V_4 )
{
V_4 -> V_37 = V_38 - 2 ;
V_4 -> V_39 = & V_40 ;
V_4 -> V_41 = & V_42 ;
V_4 -> V_43 = V_44 + V_45 + V_9 ;
V_4 -> V_30 = V_46 ;
V_4 -> type = V_47 ;
V_4 -> V_31 = V_48 ;
}
