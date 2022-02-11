static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
F_2 ( & V_4 -> V_5 ) ;
F_3 ( V_4 -> V_1 ) ;
return V_6 ;
}
static int F_4 ( struct V_7 * V_8 )
{
struct V_3 * V_4 = F_5 ( V_8 ) ;
struct V_9 * V_10 = V_4 -> V_10 ;
unsigned long V_11 , V_12 ;
T_2 V_13 ;
while ( ! ( F_6 ( V_10 , V_14 ) & V_15 ) ) {
F_7 ( V_4 -> V_1 ) ;
F_8 ( V_4 -> V_5 ,
F_6 ( V_10 , V_14 ) & V_15 ) ;
}
if ( V_4 -> V_16 )
return 0 ;
V_12 = V_17 + F_9 ( V_18 ) ;
do {
V_11 = V_17 ;
V_13 = F_6 ( V_10 , V_19 ) ;
if ( V_13 & V_20 )
return 0 ;
F_10 ( V_21 , V_22 ) ;
} while ( F_11 ( V_11 , V_12 ) );
return 0 ;
}
static int F_12 ( struct V_7 * V_8 )
{
struct V_3 * V_4 = F_5 ( V_8 ) ;
return ! ! ( F_6 ( V_4 -> V_10 , V_14 ) & V_15 ) ;
}
static unsigned long F_13 ( struct V_7 * V_8 ,
unsigned long V_23 )
{
T_2 V_13 ;
struct V_3 * V_4 = F_5 ( V_8 ) ;
struct V_9 * V_10 = V_4 -> V_10 ;
if ( V_4 -> V_16 )
return V_4 -> V_16 ;
V_13 = F_6 ( V_10 , V_19 ) & V_24 ;
V_4 -> V_16 = ( V_13 * V_23 ) / V_25 ;
return V_4 -> V_16 ;
}
static struct V_26 * T_3
F_14 ( struct V_9 * V_10 ,
unsigned int V_1 ,
const char * V_27 ,
const char * V_28 ,
unsigned long V_16 )
{
int V_29 ;
struct V_3 * V_4 ;
struct V_26 * V_26 = NULL ;
struct V_30 V_31 ;
if ( ! V_10 || ! V_1 || ! V_27 )
return F_15 ( - V_32 ) ;
if ( ! V_16 && ! V_28 )
return F_15 ( - V_32 ) ;
V_4 = F_16 ( sizeof( * V_4 ) , V_33 ) ;
if ( ! V_4 )
return F_15 ( - V_34 ) ;
V_31 . V_27 = V_27 ;
V_31 . V_35 = & V_36 ;
V_31 . V_37 = V_28 ? & V_28 : NULL ;
V_31 . V_38 = V_28 ? 1 : 0 ;
V_31 . V_39 = V_28 ? 0 : V_40 ;
V_4 -> V_8 . V_31 = & V_31 ;
V_4 -> V_16 = V_16 ;
V_4 -> V_10 = V_10 ;
V_4 -> V_1 = V_1 ;
F_17 ( & V_4 -> V_5 ) ;
F_18 ( V_4 -> V_1 , V_41 ) ;
V_29 = F_19 ( V_4 -> V_1 , F_1 ,
V_42 , L_1 , V_4 ) ;
if ( V_29 )
return F_15 ( V_29 ) ;
V_26 = F_20 ( NULL , & V_4 -> V_8 ) ;
if ( F_21 ( V_26 ) ) {
F_22 ( V_4 -> V_1 , V_4 ) ;
F_23 ( V_4 ) ;
}
return V_26 ;
}
static void T_3
F_24 ( struct V_43 * V_44 , struct V_9 * V_10 )
{
struct V_26 * V_26 ;
unsigned int V_1 ;
const char * V_28 ;
const char * V_27 = V_44 -> V_27 ;
T_2 V_16 = 0 ;
V_28 = F_25 ( V_44 , 0 ) ;
F_26 ( V_44 , L_2 , & V_27 ) ;
F_27 ( V_44 , L_3 , & V_16 ) ;
V_1 = F_28 ( V_44 , 0 ) ;
if ( ! V_1 )
return;
V_26 = F_14 ( V_10 , V_1 , V_27 , V_28 , V_16 ) ;
if ( F_21 ( V_26 ) )
return;
F_29 ( V_44 , V_45 , V_26 ) ;
}
void T_3 F_30 ( struct V_43 * V_44 ,
struct V_9 * V_10 )
{
F_24 ( V_44 , V_10 ) ;
}
