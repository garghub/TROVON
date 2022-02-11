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
F_7 ( & V_11 -> V_16 ) ;
F_8 ( & V_11 -> V_17 ) ;
F_9 ( & V_11 -> V_18 ) ;
V_11 -> V_19 = F_10 ( L_3 , NULL , V_12 ) ;
if ( ! V_11 -> V_19 )
goto V_20;
V_11 -> V_19 -> V_21 . V_22 |= V_23 |
V_24 | V_25 | V_26 ;
V_11 -> V_19 -> V_27 = V_28 ;
V_11 -> V_19 -> V_11 = V_11 ;
F_11 ( & V_11 -> V_29 , 0 ) ;
F_12 ( & V_11 -> V_30 ) ;
return V_11 ;
V_20:
F_13 ( V_11 -> V_6 . V_7 ) ;
V_14:
F_13 ( V_11 ) ;
return NULL ;
}
void F_14 ( struct V_1 * V_11 )
{
if ( ! V_11 )
return;
F_15 ( & V_11 -> V_6 ) ;
F_16 ( & V_11 -> V_30 ) ;
F_17 ( V_11 -> V_5 ) ;
V_11 -> V_19 -> V_11 = NULL ;
F_18 ( V_11 -> V_19 ) ;
F_13 ( V_11 ) ;
}
struct V_1 * F_19 ( struct V_1 * V_31 , const char * V_10 , T_1 V_32 )
{
struct V_1 * V_11 = NULL ;
F_20 () ;
V_11 = F_21 ( F_22 ( & V_31 -> V_15 , V_10 , V_32 ) ) ;
F_23 () ;
return V_11 ;
}
struct V_1 * F_24 ( struct V_1 * V_31 , const char * V_10 )
{
return F_19 ( V_31 , V_10 , strlen ( V_10 ) ) ;
}
struct V_1 * F_25 ( struct V_1 * V_3 , const char * V_7 , T_1 V_32 )
{
struct V_1 * V_11 = V_3 ;
const char * V_33 ;
for ( V_33 = F_26 ( V_7 , L_4 , V_32 ) ; V_33 ;
V_33 = F_26 ( V_7 , L_4 , V_32 ) ) {
V_11 = F_22 ( & V_11 -> V_15 , V_7 , V_33 - V_7 ) ;
if ( ! V_11 )
return NULL ;
V_32 -= V_33 + 2 - V_7 ;
V_7 = V_33 + 2 ;
}
if ( V_32 )
return F_22 ( & V_11 -> V_15 , V_7 , V_32 ) ;
return NULL ;
}
struct V_1 * F_27 ( struct V_1 * V_3 , const char * V_10 , T_1 V_32 )
{
struct V_1 * V_11 = NULL ;
F_20 () ;
V_11 = F_21 ( F_25 ( V_3 , V_10 , V_32 ) ) ;
F_23 () ;
return V_11 ;
}
static struct V_1 * F_28 ( struct V_1 * V_5 , const char * V_10 ,
struct V_34 * V_35 )
{
struct V_1 * V_11 ;
int error ;
F_29 ( ! V_5 ) ;
F_29 ( ! V_10 ) ;
F_29 ( ! F_30 ( & V_5 -> V_17 ) ) ;
V_11 = F_3 ( V_5 -> V_6 . V_7 , V_10 ) ;
if ( ! V_11 )
return NULL ;
F_31 ( & V_11 -> V_17 ) ;
error = F_32 ( V_11 , F_33 ( V_5 ) , V_10 , V_35 ) ;
if ( error ) {
F_34 ( L_5 ,
V_11 -> V_6 . V_10 ) ;
F_35 ( & V_11 -> V_17 ) ;
F_14 ( V_11 ) ;
return F_36 ( error ) ;
}
V_11 -> V_5 = F_21 ( V_5 ) ;
V_11 -> V_36 = V_5 -> V_36 + 1 ;
F_37 ( & V_11 -> V_6 . V_37 , & V_5 -> V_15 ) ;
F_21 ( V_11 ) ;
F_35 ( & V_11 -> V_17 ) ;
return V_11 ;
}
struct V_1 * F_38 ( struct V_1 * V_5 , const char * V_10 ,
struct V_34 * V_35 )
{
struct V_1 * V_11 ;
F_29 ( ! F_30 ( & V_5 -> V_17 ) ) ;
V_11 = F_21 ( F_39 ( & V_5 -> V_15 , V_10 ) ) ;
if ( ! V_11 )
V_11 = F_28 ( V_5 , V_10 , V_35 ) ;
else
V_11 = F_36 ( - V_38 ) ;
return V_11 ;
}
struct V_1 * F_40 ( struct V_1 * V_5 , const char * V_10 )
{
struct V_1 * V_11 ;
F_31 ( & V_5 -> V_17 ) ;
V_11 = F_21 ( F_39 ( & V_5 -> V_15 , V_10 ) ) ;
if ( ! V_11 )
V_11 = F_28 ( V_5 , V_10 , NULL ) ;
F_35 ( & V_5 -> V_17 ) ;
return V_11 ;
}
static void F_41 ( struct V_1 * V_11 )
{
if ( ! V_11 )
return;
F_31 ( & V_11 -> V_17 ) ;
F_42 ( & V_11 -> V_6 . V_39 ) ;
F_43 ( & V_11 -> V_15 ) ;
if ( V_11 -> V_5 ) {
unsigned long V_22 ;
F_44 ( & V_11 -> V_30 . V_17 , V_22 ) ;
F_45 ( F_46 ( V_11 ) ,
F_46 ( V_11 -> V_5 ) ) ;
F_47 ( & V_11 -> V_30 . V_17 , V_22 ) ;
}
F_48 ( V_11 ) ;
F_35 ( & V_11 -> V_17 ) ;
}
void F_49 ( struct V_1 * V_11 )
{
F_50 ( & V_11 -> V_6 . V_37 ) ;
F_41 ( V_11 ) ;
F_17 ( V_11 ) ;
}
static void F_43 ( struct V_40 * V_41 )
{
struct V_1 * V_11 , * V_42 ;
F_51 (ns, tmp, head, base.list)
F_49 ( V_11 ) ;
}
int T_2 F_52 ( void )
{
V_43 = F_3 ( NULL , L_6 ) ;
if ( ! V_43 )
return - V_44 ;
return 0 ;
}
void T_2 F_53 ( void )
{
struct V_1 * V_11 = V_43 ;
V_43 = NULL ;
F_41 ( V_11 ) ;
F_17 ( V_11 ) ;
}
