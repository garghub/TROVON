static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( V_4 -> V_5 , 1 ) ;
return 0 ;
}
static void F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( V_4 -> V_5 , 0 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return F_6 ( V_4 -> V_5 ) ;
}
struct V_4 * F_7 ( struct V_6 * V_7 , const char * V_8 ,
const char * V_9 , unsigned V_10 , bool V_11 ,
unsigned long V_12 )
{
struct V_3 * V_3 = NULL ;
struct V_4 * V_4 = F_8 ( - V_13 ) ;
struct V_14 V_15 = { NULL } ;
unsigned long V_16 ;
int V_17 ;
if ( V_11 )
V_16 = V_18 | V_19 ;
else
V_16 = V_20 ;
if ( V_7 )
V_17 = F_9 ( V_7 , V_10 , V_16 , V_8 ) ;
else
V_17 = F_10 ( V_10 , V_16 , V_8 ) ;
if ( V_17 ) {
F_11 ( L_1 ,
V_21 , V_8 , V_10 ) ;
return F_8 ( V_17 ) ;
}
if ( V_7 )
V_3 = F_12 ( V_7 , sizeof( struct V_3 ) ,
V_22 ) ;
else
V_3 = F_13 ( sizeof( struct V_3 ) , V_22 ) ;
if ( ! V_3 ) {
V_4 = F_8 ( - V_23 ) ;
goto V_24;
}
V_15 . V_8 = V_8 ;
V_15 . V_25 = & V_26 ;
V_15 . V_12 = V_12 | V_27 ;
V_15 . V_28 = ( V_9 ? & V_9 : NULL ) ;
V_15 . V_29 = ( V_9 ? 1 : 0 ) ;
V_3 -> V_5 = F_14 ( V_10 ) ;
V_3 -> V_2 . V_15 = & V_15 ;
V_4 = F_15 ( V_7 , & V_3 -> V_2 ) ;
if ( ! F_16 ( V_4 ) )
return V_4 ;
if ( ! V_7 )
F_17 ( V_3 ) ;
V_24:
if ( ! V_7 )
F_18 ( V_10 ) ;
return V_4 ;
}
static struct V_4 * F_19 (
struct V_30 * V_31 ,
void * V_32 )
{
struct V_33 * V_34 = V_32 ;
struct V_4 * V_4 ;
const char * V_35 = V_34 -> V_36 -> V_8 ;
const char * V_9 ;
int V_10 ;
enum V_37 V_38 ;
F_20 ( & V_34 -> V_39 ) ;
if ( V_34 -> V_4 ) {
F_21 ( & V_34 -> V_39 ) ;
return V_34 -> V_4 ;
}
V_10 = F_22 ( V_34 -> V_36 , L_2 , 0 ,
& V_38 ) ;
if ( V_10 < 0 ) {
F_21 ( & V_34 -> V_39 ) ;
if ( V_10 != - V_40 )
F_11 ( L_3 ,
V_21 , V_35 ) ;
return F_8 ( V_10 ) ;
}
V_9 = F_23 ( V_34 -> V_36 , 0 ) ;
V_4 = F_7 ( NULL , V_35 , V_9 , V_10 ,
V_38 & V_41 , 0 ) ;
if ( F_16 ( V_4 ) ) {
F_21 ( & V_34 -> V_39 ) ;
return V_4 ;
}
V_34 -> V_4 = V_4 ;
F_21 ( & V_34 -> V_39 ) ;
return V_4 ;
}
void T_1 F_24 ( struct V_42 * V_36 )
{
struct V_33 * V_34 ;
V_34 = F_13 ( sizeof( struct V_33 ) ,
V_22 ) ;
if ( ! V_34 )
return;
V_34 -> V_36 = V_36 ;
F_25 ( & V_34 -> V_39 ) ;
F_26 ( V_36 , F_19 , V_34 ) ;
}
