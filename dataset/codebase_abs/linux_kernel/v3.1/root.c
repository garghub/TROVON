static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
return V_2 -> V_4 == V_3 ;
}
static int F_2 ( struct V_1 * V_2 , void * V_3 )
{
int V_5 = F_3 ( V_2 , NULL ) ;
if ( ! V_5 ) {
struct V_6 * V_7 = (struct V_6 * ) V_3 ;
V_2 -> V_4 = F_4 ( V_7 ) ;
}
return V_5 ;
}
static struct V_8 * F_5 ( struct V_9 * V_10 ,
int V_11 , const char * V_12 , void * V_3 )
{
int V_5 ;
struct V_1 * V_2 ;
struct V_6 * V_7 ;
struct V_13 * V_14 ;
if ( V_11 & V_15 )
V_7 = (struct V_6 * ) V_3 ;
else
V_7 = V_16 -> V_17 -> V_18 ;
V_2 = F_6 ( V_10 , F_1 , F_2 , V_7 ) ;
if ( F_7 ( V_2 ) )
return F_8 ( V_2 ) ;
if ( ! V_2 -> V_19 ) {
V_2 -> V_20 = V_11 ;
V_5 = F_9 ( V_2 ) ;
if ( V_5 ) {
F_10 ( V_2 ) ;
return F_11 ( V_5 ) ;
}
V_2 -> V_20 |= V_21 ;
}
V_14 = F_12 ( V_2 -> V_19 -> V_22 ) ;
if ( ! V_14 -> V_23 ) {
F_13 () ;
V_14 -> V_23 = F_14 ( F_15 ( 1 , V_7 ) ) ;
F_16 () ;
}
return F_17 ( V_2 -> V_19 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_6 * V_7 ;
V_7 = (struct V_6 * ) V_2 -> V_4 ;
F_19 ( V_2 ) ;
F_20 ( V_7 ) ;
}
void T_1 F_21 ( void )
{
struct V_24 * V_25 ;
int V_5 ;
F_22 () ;
V_5 = F_23 ( & V_26 ) ;
if ( V_5 )
return;
V_25 = F_24 ( & V_26 , & V_27 ) ;
if ( F_7 ( V_25 ) ) {
F_25 ( & V_26 ) ;
return;
}
V_27 . V_28 = V_25 ;
F_26 ( L_1 , NULL , L_2 ) ;
F_27 () ;
#ifdef F_28
F_29 ( L_3 , NULL ) ;
#endif
F_29 ( L_4 , NULL ) ;
F_29 ( L_5 , NULL ) ;
F_29 ( L_6 , NULL ) ;
#if F_30 ( V_29 ) || F_30 ( V_30 )
F_29 ( L_7 , NULL ) ;
#endif
F_31 () ;
#ifdef F_32
F_33 () ;
#endif
F_29 ( L_8 , NULL ) ;
F_34 () ;
}
static int F_35 ( struct V_24 * V_25 , struct V_8 * V_8 , struct V_31 * V_32
)
{
F_36 ( V_8 -> V_22 , V_32 ) ;
V_32 -> V_33 = V_34 . V_33 + F_37 () ;
return 0 ;
}
static struct V_8 * F_38 ( struct V_35 * V_36 , struct V_8 * V_8 , struct V_37 * V_38 )
{
if ( ! F_39 ( V_36 , V_8 , V_38 ) ) {
return NULL ;
}
return F_40 ( V_36 , V_8 , V_38 ) ;
}
static int F_41 ( struct V_39 * V_40 ,
void * V_41 , T_2 V_42 )
{
unsigned int V_43 = V_40 -> V_44 ;
int V_45 ;
if ( V_43 < V_46 ) {
int error = F_42 ( V_40 , V_41 , V_42 ) ;
if ( error <= 0 )
return error ;
V_40 -> V_44 = V_46 ;
}
V_45 = F_43 ( V_40 , V_41 , V_42 ) ;
return V_45 ;
}
int F_44 ( struct V_6 * V_7 )
{
struct V_24 * V_25 ;
V_25 = F_24 ( & V_26 , V_7 ) ;
if ( F_7 ( V_25 ) )
return F_45 ( V_25 ) ;
V_7 -> V_28 = V_25 ;
return 0 ;
}
void F_46 ( struct V_6 * V_7 )
{
F_47 ( V_7 -> V_28 ) ;
}
