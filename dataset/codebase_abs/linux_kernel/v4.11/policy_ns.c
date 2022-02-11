bool F_1 ( struct V_1 * V_2 , struct V_1 * V_3 , bool V_4 )
{
if ( V_2 == V_3 )
return true ;
if ( ! V_4 )
return false ;
for ( ; V_3 ; V_3 = V_3 -> V_5 ) {
if ( V_3 -> V_5 == V_2 )
return true ;
}
return false ;
}
const char * F_2 ( struct V_1 * V_2 , struct V_1 * V_3 , bool V_4 )
{
if ( V_2 == V_3 )
return L_1 ;
if ( F_1 ( V_2 , V_3 , V_4 ) ) {
return V_3 -> V_6 . V_7 + strlen ( V_2 -> V_6 . V_7 ) + 2 ;
}
return V_8 ;
}
static struct V_1 * F_3 ( const char * V_9 , const char * V_10 )
{
struct V_1 * V_11 ;
V_11 = F_4 ( sizeof( * V_11 ) , V_12 ) ;
F_5 ( L_2 , V_13 , V_11 ) ;
if ( ! V_11 )
return NULL ;
if ( ! F_6 ( & V_11 -> V_6 , V_9 , V_10 , V_12 ) )
goto V_14;
F_7 ( & V_11 -> V_15 ) ;
F_8 ( & V_11 -> V_16 ) ;
V_11 -> V_17 = F_9 ( L_3 , V_12 ) ;
if ( ! V_11 -> V_17 )
goto V_18;
V_11 -> V_17 -> V_19 = V_20 |
V_21 | V_22 ;
V_11 -> V_17 -> V_23 = V_24 ;
V_11 -> V_17 -> V_11 = V_11 ;
F_10 ( & V_11 -> V_25 , 0 ) ;
return V_11 ;
V_18:
F_11 ( V_11 -> V_6 . V_7 ) ;
V_14:
F_11 ( V_11 ) ;
return NULL ;
}
void F_12 ( struct V_1 * V_11 )
{
if ( ! V_11 )
return;
F_13 ( & V_11 -> V_6 ) ;
F_14 ( V_11 -> V_5 ) ;
V_11 -> V_17 -> V_11 = NULL ;
F_15 ( V_11 -> V_17 ) ;
F_11 ( V_11 ) ;
}
struct V_1 * F_16 ( struct V_1 * V_26 , const char * V_10 , T_1 V_27 )
{
struct V_1 * V_11 = NULL ;
F_17 () ;
V_11 = F_18 ( F_19 ( & V_26 -> V_15 , V_10 , V_27 ) ) ;
F_20 () ;
return V_11 ;
}
struct V_1 * F_21 ( struct V_1 * V_26 , const char * V_10 )
{
return F_16 ( V_26 , V_10 , strlen ( V_10 ) ) ;
}
static struct V_1 * F_22 ( struct V_1 * V_5 , const char * V_10 ,
struct V_28 * V_29 )
{
struct V_1 * V_11 ;
int error ;
F_23 ( ! V_5 ) ;
F_23 ( ! V_10 ) ;
F_23 ( ! F_24 ( & V_5 -> V_16 ) ) ;
V_11 = F_3 ( V_5 -> V_6 . V_7 , V_10 ) ;
if ( ! V_11 )
return NULL ;
F_25 ( & V_11 -> V_16 ) ;
error = F_26 ( V_11 , F_27 ( V_5 ) , V_10 ) ;
if ( error ) {
F_28 ( L_4 ,
V_11 -> V_6 . V_10 ) ;
F_29 ( & V_11 -> V_16 ) ;
F_12 ( V_11 ) ;
return F_30 ( error ) ;
}
V_11 -> V_5 = F_18 ( V_5 ) ;
V_11 -> V_30 = V_5 -> V_30 + 1 ;
F_31 ( & V_11 -> V_6 . V_31 , & V_5 -> V_15 ) ;
F_18 ( V_11 ) ;
F_29 ( & V_11 -> V_16 ) ;
return V_11 ;
}
struct V_1 * F_32 ( struct V_1 * V_5 , const char * V_10 ,
struct V_28 * V_29 )
{
struct V_1 * V_11 ;
F_23 ( ! F_24 ( & V_5 -> V_16 ) ) ;
V_11 = F_18 ( F_33 ( & V_5 -> V_15 , V_10 ) ) ;
if ( ! V_11 )
V_11 = F_22 ( V_5 , V_10 , V_29 ) ;
else
V_11 = F_30 ( - V_32 ) ;
return V_11 ;
}
struct V_1 * F_34 ( struct V_1 * V_5 , const char * V_10 )
{
struct V_1 * V_11 ;
F_25 ( & V_5 -> V_16 ) ;
V_11 = F_18 ( F_33 ( & V_5 -> V_15 , V_10 ) ) ;
if ( ! V_11 )
V_11 = F_22 ( V_5 , V_10 , NULL ) ;
F_29 ( & V_5 -> V_16 ) ;
return V_11 ;
}
static void F_35 ( struct V_1 * V_11 )
{
if ( ! V_11 )
return;
F_25 ( & V_11 -> V_16 ) ;
F_36 ( & V_11 -> V_6 . V_33 ) ;
F_37 ( & V_11 -> V_15 ) ;
if ( V_11 -> V_5 )
F_38 ( V_11 -> V_17 , V_11 -> V_5 -> V_17 ) ;
F_39 ( V_11 ) ;
F_29 ( & V_11 -> V_16 ) ;
}
void F_40 ( struct V_1 * V_11 )
{
F_41 ( & V_11 -> V_6 . V_31 ) ;
F_35 ( V_11 ) ;
F_14 ( V_11 ) ;
}
static void F_37 ( struct V_34 * V_35 )
{
struct V_1 * V_11 , * V_36 ;
F_42 (ns, tmp, head, base.list)
F_40 ( V_11 ) ;
}
int T_2 F_43 ( void )
{
V_37 = F_3 ( NULL , L_5 ) ;
if ( ! V_37 )
return - V_38 ;
return 0 ;
}
void T_2 F_44 ( void )
{
struct V_1 * V_11 = V_37 ;
V_37 = NULL ;
F_35 ( V_11 ) ;
F_14 ( V_11 ) ;
}
