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
const char * V_9 , struct V_10 * V_5 ,
unsigned long V_11 )
{
struct V_3 * V_3 = NULL ;
struct V_4 * V_4 = F_8 ( - V_12 ) ;
struct V_13 V_14 = { NULL } ;
unsigned long V_15 ;
int V_16 ;
if ( F_9 ( V_5 ) )
V_15 = V_17 ;
else
V_15 = V_18 ;
if ( V_7 )
V_16 = F_10 ( V_7 , F_11 ( V_5 ) ,
V_15 , V_8 ) ;
else
V_16 = F_12 ( F_11 ( V_5 ) , V_15 , V_8 ) ;
if ( V_16 ) {
F_13 ( L_1 ,
V_19 , V_8 , F_11 ( V_5 ) ) ;
return F_8 ( V_16 ) ;
}
if ( V_7 )
V_3 = F_14 ( V_7 , sizeof( struct V_3 ) ,
V_20 ) ;
else
V_3 = F_15 ( sizeof( struct V_3 ) , V_20 ) ;
if ( ! V_3 ) {
V_4 = F_8 ( - V_21 ) ;
goto V_22;
}
V_14 . V_8 = V_8 ;
V_14 . V_23 = & V_24 ;
V_14 . V_11 = V_11 | V_25 ;
V_14 . V_26 = ( V_9 ? & V_9 : NULL ) ;
V_14 . V_27 = ( V_9 ? 1 : 0 ) ;
V_3 -> V_5 = V_5 ;
V_3 -> V_2 . V_14 = & V_14 ;
V_4 = F_16 ( V_7 , & V_3 -> V_2 ) ;
if ( ! F_17 ( V_4 ) )
return V_4 ;
if ( ! V_7 )
F_18 ( V_3 ) ;
V_22:
F_19 ( V_5 ) ;
return V_4 ;
}
static struct V_4 * F_20 (
struct V_28 * V_29 ,
void * V_30 )
{
struct V_31 * V_32 = V_30 ;
struct V_4 * V_4 ;
const char * V_33 = V_32 -> V_34 -> V_8 ;
const char * V_9 ;
struct V_10 * V_5 ;
int V_35 ;
F_21 ( & V_32 -> V_36 ) ;
if ( V_32 -> V_4 ) {
F_22 ( & V_32 -> V_36 ) ;
return V_32 -> V_4 ;
}
V_35 = F_23 ( V_32 -> V_34 , L_2 , 0 , NULL ) ;
if ( V_35 < 0 ) {
F_22 ( & V_32 -> V_36 ) ;
if ( V_35 != - V_37 )
F_13 ( L_3 ,
V_19 , V_33 ) ;
return F_8 ( V_35 ) ;
}
V_5 = F_24 ( V_35 ) ;
V_9 = F_25 ( V_32 -> V_34 , 0 ) ;
V_4 = F_7 ( NULL , V_33 , V_9 , V_5 , 0 ) ;
if ( F_17 ( V_4 ) ) {
F_22 ( & V_32 -> V_36 ) ;
return V_4 ;
}
V_32 -> V_4 = V_4 ;
F_22 ( & V_32 -> V_36 ) ;
return V_4 ;
}
void T_1 F_26 ( struct V_38 * V_34 )
{
struct V_31 * V_32 ;
V_32 = F_15 ( sizeof( struct V_31 ) ,
V_20 ) ;
if ( ! V_32 )
return;
V_32 -> V_34 = V_34 ;
F_27 ( & V_32 -> V_36 ) ;
F_28 ( V_34 , F_20 , V_32 ) ;
}
