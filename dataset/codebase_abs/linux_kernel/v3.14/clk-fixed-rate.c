static unsigned long F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
return F_2 ( V_2 ) -> V_4 ;
}
static unsigned long F_3 ( struct V_1 * V_2 ,
unsigned long V_5 )
{
return F_2 ( V_2 ) -> V_6 ;
}
struct V_7 * F_4 ( struct V_8 * V_9 ,
const char * V_10 , const char * V_11 , unsigned long V_12 ,
unsigned long V_4 , unsigned long V_6 )
{
struct V_13 * V_14 ;
struct V_7 * V_7 ;
struct V_15 V_16 ;
V_14 = F_5 ( sizeof( struct V_13 ) , V_17 ) ;
if ( ! V_14 ) {
F_6 ( L_1 , V_18 ) ;
return F_7 ( - V_19 ) ;
}
V_16 . V_10 = V_10 ;
V_16 . V_20 = & V_21 ;
V_16 . V_12 = V_12 | V_22 ;
V_16 . V_23 = ( V_11 ? & V_11 : NULL ) ;
V_16 . V_24 = ( V_11 ? 1 : 0 ) ;
V_14 -> V_4 = V_4 ;
V_14 -> V_6 = V_6 ;
V_14 -> V_2 . V_16 = & V_16 ;
V_7 = F_8 ( V_9 , & V_14 -> V_2 ) ;
if ( F_9 ( V_7 ) )
F_10 ( V_14 ) ;
return V_7 ;
}
struct V_7 * F_11 ( struct V_8 * V_9 , const char * V_10 ,
const char * V_11 , unsigned long V_12 ,
unsigned long V_4 )
{
return F_4 ( V_9 , V_10 , V_11 ,
V_12 , V_4 , 0 ) ;
}
void F_12 ( struct V_25 * V_26 )
{
struct V_7 * V_7 ;
const char * V_27 = V_26 -> V_10 ;
T_1 V_28 ;
T_1 V_29 = 0 ;
if ( F_13 ( V_26 , L_2 , & V_28 ) )
return;
F_13 ( V_26 , L_3 , & V_29 ) ;
F_14 ( V_26 , L_4 , & V_27 ) ;
V_7 = F_4 ( NULL , V_27 , NULL ,
V_30 , V_28 ,
V_29 ) ;
if ( ! F_9 ( V_7 ) )
F_15 ( V_26 , V_31 , V_7 ) ;
}
