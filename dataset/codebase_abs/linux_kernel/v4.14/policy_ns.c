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
V_11 -> V_19 -> V_29 . V_30 = F_11 ( V_31 ) ;
V_11 -> V_19 -> V_32 . V_30 = F_11 ( V_31 ) ;
V_11 -> V_19 -> V_11 = V_11 ;
F_12 ( & V_11 -> V_33 , 0 ) ;
F_13 ( & V_11 -> V_34 ) ;
return V_11 ;
V_20:
F_14 ( V_11 -> V_6 . V_7 ) ;
V_14:
F_14 ( V_11 ) ;
return NULL ;
}
void F_15 ( struct V_1 * V_11 )
{
if ( ! V_11 )
return;
F_16 ( & V_11 -> V_6 ) ;
F_17 ( & V_11 -> V_34 ) ;
F_18 ( V_11 -> V_5 ) ;
V_11 -> V_19 -> V_11 = NULL ;
F_19 ( V_11 -> V_19 ) ;
F_14 ( V_11 ) ;
}
struct V_1 * F_20 ( struct V_1 * V_35 , const char * V_10 , T_1 V_36 )
{
struct V_1 * V_11 = NULL ;
F_21 () ;
V_11 = F_22 ( F_23 ( & V_35 -> V_15 , V_10 , V_36 ) ) ;
F_24 () ;
return V_11 ;
}
struct V_1 * F_25 ( struct V_1 * V_35 , const char * V_10 )
{
return F_20 ( V_35 , V_10 , strlen ( V_10 ) ) ;
}
struct V_1 * F_26 ( struct V_1 * V_3 , const char * V_7 , T_1 V_36 )
{
struct V_1 * V_11 = V_3 ;
const char * V_37 ;
for ( V_37 = F_27 ( V_7 , L_4 , V_36 ) ; V_37 ;
V_37 = F_27 ( V_7 , L_4 , V_36 ) ) {
V_11 = F_23 ( & V_11 -> V_15 , V_7 , V_37 - V_7 ) ;
if ( ! V_11 )
return NULL ;
V_36 -= V_37 + 2 - V_7 ;
V_7 = V_37 + 2 ;
}
if ( V_36 )
return F_23 ( & V_11 -> V_15 , V_7 , V_36 ) ;
return NULL ;
}
struct V_1 * F_28 ( struct V_1 * V_3 , const char * V_10 , T_1 V_36 )
{
struct V_1 * V_11 = NULL ;
F_21 () ;
V_11 = F_22 ( F_26 ( V_3 , V_10 , V_36 ) ) ;
F_24 () ;
return V_11 ;
}
static struct V_1 * F_29 ( struct V_1 * V_5 , const char * V_10 ,
struct V_38 * V_39 )
{
struct V_1 * V_11 ;
int error ;
F_30 ( ! V_5 ) ;
F_30 ( ! V_10 ) ;
F_30 ( ! F_31 ( & V_5 -> V_17 ) ) ;
V_11 = F_3 ( V_5 -> V_6 . V_7 , V_10 ) ;
if ( ! V_11 )
return NULL ;
F_32 ( & V_11 -> V_17 ) ;
error = F_33 ( V_11 , F_34 ( V_5 ) , V_10 , V_39 ) ;
if ( error ) {
F_35 ( L_5 ,
V_11 -> V_6 . V_10 ) ;
F_36 ( & V_11 -> V_17 ) ;
F_15 ( V_11 ) ;
return F_37 ( error ) ;
}
V_11 -> V_5 = F_22 ( V_5 ) ;
V_11 -> V_40 = V_5 -> V_40 + 1 ;
F_38 ( & V_11 -> V_6 . V_41 , & V_5 -> V_15 ) ;
F_22 ( V_11 ) ;
F_36 ( & V_11 -> V_17 ) ;
return V_11 ;
}
struct V_1 * F_39 ( struct V_1 * V_5 , const char * V_10 ,
struct V_38 * V_39 )
{
struct V_1 * V_11 ;
F_30 ( ! F_31 ( & V_5 -> V_17 ) ) ;
V_11 = F_22 ( F_40 ( & V_5 -> V_15 , V_10 ) ) ;
if ( ! V_11 )
V_11 = F_29 ( V_5 , V_10 , V_39 ) ;
else
V_11 = F_37 ( - V_42 ) ;
return V_11 ;
}
struct V_1 * F_41 ( struct V_1 * V_5 , const char * V_10 )
{
struct V_1 * V_11 ;
F_32 ( & V_5 -> V_17 ) ;
V_11 = F_22 ( F_40 ( & V_5 -> V_15 , V_10 ) ) ;
if ( ! V_11 )
V_11 = F_29 ( V_5 , V_10 , NULL ) ;
F_36 ( & V_5 -> V_17 ) ;
return V_11 ;
}
static void F_42 ( struct V_1 * V_11 )
{
if ( ! V_11 )
return;
F_32 ( & V_11 -> V_17 ) ;
F_43 ( & V_11 -> V_6 . V_43 ) ;
F_44 ( & V_11 -> V_15 ) ;
if ( V_11 -> V_5 ) {
unsigned long V_22 ;
F_45 ( & V_11 -> V_34 . V_17 , V_22 ) ;
F_46 ( F_47 ( V_11 ) ,
F_47 ( V_11 -> V_5 ) ) ;
F_48 ( & V_11 -> V_34 . V_17 , V_22 ) ;
}
F_49 ( V_11 ) ;
F_36 ( & V_11 -> V_17 ) ;
}
void F_50 ( struct V_1 * V_11 )
{
F_51 ( & V_11 -> V_6 . V_41 ) ;
F_42 ( V_11 ) ;
F_18 ( V_11 ) ;
}
static void F_44 ( struct V_44 * V_45 )
{
struct V_1 * V_11 , * V_46 ;
F_52 (ns, tmp, head, base.list)
F_50 ( V_11 ) ;
}
int T_2 F_53 ( void )
{
V_47 = F_3 ( NULL , L_6 ) ;
if ( ! V_47 )
return - V_48 ;
return 0 ;
}
void T_2 F_54 ( void )
{
struct V_1 * V_11 = V_47 ;
V_47 = NULL ;
F_42 ( V_11 ) ;
F_18 ( V_11 ) ;
}
