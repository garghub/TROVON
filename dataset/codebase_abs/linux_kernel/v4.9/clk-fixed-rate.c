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
struct V_1 * F_4 ( struct V_7 * V_8 ,
const char * V_9 , const char * V_10 , unsigned long V_11 ,
unsigned long V_4 , unsigned long V_6 )
{
struct V_12 * V_13 ;
struct V_1 * V_2 ;
struct V_14 V_15 ;
int V_16 ;
V_13 = F_5 ( sizeof( * V_13 ) , V_17 ) ;
if ( ! V_13 )
return F_6 ( - V_18 ) ;
V_15 . V_9 = V_9 ;
V_15 . V_19 = & V_20 ;
V_15 . V_11 = V_11 | V_21 ;
V_15 . V_22 = ( V_10 ? & V_10 : NULL ) ;
V_15 . V_23 = ( V_10 ? 1 : 0 ) ;
V_13 -> V_4 = V_4 ;
V_13 -> V_6 = V_6 ;
V_13 -> V_2 . V_15 = & V_15 ;
V_2 = & V_13 -> V_2 ;
V_16 = F_7 ( V_8 , V_2 ) ;
if ( V_16 ) {
F_8 ( V_13 ) ;
V_2 = F_6 ( V_16 ) ;
}
return V_2 ;
}
struct V_24 * F_9 ( struct V_7 * V_8 ,
const char * V_9 , const char * V_10 , unsigned long V_11 ,
unsigned long V_4 , unsigned long V_6 )
{
struct V_1 * V_2 ;
V_2 = F_4 ( V_8 , V_9 , V_10 ,
V_11 , V_4 , V_6 ) ;
if ( F_10 ( V_2 ) )
return F_11 ( V_2 ) ;
return V_2 -> V_24 ;
}
struct V_1 * F_12 ( struct V_7 * V_8 , const char * V_9 ,
const char * V_10 , unsigned long V_11 ,
unsigned long V_4 )
{
return F_4 ( V_8 , V_9 , V_10 ,
V_11 , V_4 , 0 ) ;
}
struct V_24 * F_13 ( struct V_7 * V_8 , const char * V_9 ,
const char * V_10 , unsigned long V_11 ,
unsigned long V_4 )
{
return F_9 ( V_8 , V_9 , V_10 ,
V_11 , V_4 , 0 ) ;
}
void F_14 ( struct V_24 * V_24 )
{
struct V_1 * V_2 ;
V_2 = F_15 ( V_24 ) ;
if ( ! V_2 )
return;
F_16 ( V_24 ) ;
F_8 ( F_2 ( V_2 ) ) ;
}
void F_17 ( struct V_1 * V_2 )
{
struct V_12 * V_13 ;
V_13 = F_2 ( V_2 ) ;
F_18 ( V_2 ) ;
F_8 ( V_13 ) ;
}
static struct V_24 * F_19 ( struct V_25 * V_26 )
{
struct V_24 * V_24 ;
const char * V_27 = V_26 -> V_9 ;
T_1 V_28 ;
T_1 V_29 = 0 ;
int V_16 ;
if ( F_20 ( V_26 , L_1 , & V_28 ) )
return F_6 ( - V_30 ) ;
F_20 ( V_26 , L_2 , & V_29 ) ;
F_21 ( V_26 , L_3 , & V_27 ) ;
V_24 = F_9 ( NULL , V_27 , NULL ,
0 , V_28 , V_29 ) ;
if ( F_10 ( V_24 ) )
return V_24 ;
V_16 = F_22 ( V_26 , V_31 , V_24 ) ;
if ( V_16 ) {
F_16 ( V_24 ) ;
return F_6 ( V_16 ) ;
}
return V_24 ;
}
void T_2 F_23 ( struct V_25 * V_26 )
{
F_19 ( V_26 ) ;
}
static int F_24 ( struct V_32 * V_33 )
{
struct V_24 * V_24 = F_25 ( V_33 ) ;
F_14 ( V_24 ) ;
return 0 ;
}
static int F_26 ( struct V_32 * V_33 )
{
struct V_24 * V_24 ;
V_24 = F_19 ( V_33 -> V_8 . V_34 ) ;
if ( F_10 ( V_24 ) )
return F_27 ( V_24 ) ;
F_28 ( V_33 , V_24 ) ;
return 0 ;
}
