static bool F_1 ( char * V_1 , unsigned long * V_2 , struct V_3 * V_4 )
{
unsigned long V_5 ;
int V_6 ;
if ( ! V_4 -> V_7 . V_8 )
return false ;
V_6 = F_2 ( V_1 , 10 , & V_5 ) ;
if ( V_6 )
return false ;
if ( V_5 < V_4 -> V_7 . V_9 || V_5 > V_4 -> V_10 )
return false ;
* V_2 = F_3 ( V_5 , ( unsigned long ) V_4 -> V_7 . V_11 ) ;
return true ;
}
int F_4 ( char * V_1 , struct V_3 * V_4 , struct V_12 * V_13 )
{
unsigned long V_2 ;
if ( V_13 -> V_14 )
return - V_15 ;
if ( ! F_1 ( V_1 , & V_2 , V_4 ) )
return - V_15 ;
V_13 -> V_16 = V_2 ;
V_13 -> V_14 = true ;
return 0 ;
}
static bool F_5 ( char * V_1 , unsigned long * V_2 , struct V_3 * V_4 )
{
unsigned long V_17 , V_18 , V_19 ;
unsigned int V_20 = V_4 -> V_21 . V_20 ;
int V_6 ;
V_6 = F_2 ( V_1 , 16 , & V_19 ) ;
if ( V_6 )
return false ;
if ( V_19 == 0 || V_19 > V_4 -> V_10 )
return false ;
V_17 = F_6 ( & V_19 , V_20 ) ;
V_18 = F_7 ( & V_19 , V_20 , V_17 ) ;
if ( F_8 ( & V_19 , V_20 , V_18 ) < V_20 )
return false ;
if ( ( V_18 - V_17 ) < V_4 -> V_21 . V_22 )
return false ;
* V_2 = V_19 ;
return true ;
}
int F_9 ( char * V_1 , struct V_3 * V_4 , struct V_12 * V_13 )
{
unsigned long V_2 ;
if ( V_13 -> V_14 )
return - V_15 ;
if( ! F_5 ( V_1 , & V_2 , V_4 ) )
return - V_15 ;
V_13 -> V_16 = V_2 ;
V_13 -> V_14 = true ;
return 0 ;
}
static int F_10 ( char * line , struct V_3 * V_4 )
{
char * V_23 = NULL , * V_24 ;
struct V_12 * V_13 ;
unsigned long V_25 ;
V_26:
if ( ! line || line [ 0 ] == '\0' )
return 0 ;
V_23 = F_11 ( & line , L_1 ) ;
V_24 = F_11 ( & V_23 , L_2 ) ;
if ( ! V_23 || F_2 ( V_24 , 10 , & V_25 ) )
return - V_15 ;
V_23 = F_12 ( V_23 ) ;
F_13 (d, &r->domains, list) {
if ( V_13 -> V_24 == V_25 ) {
if ( V_4 -> V_27 ( V_23 , V_4 , V_13 ) )
return - V_15 ;
goto V_26;
}
}
return - V_15 ;
}
static int F_14 ( struct V_3 * V_4 , int V_28 )
{
struct V_29 V_29 ;
T_1 V_30 ;
struct V_12 * V_13 ;
int V_31 ;
if ( ! F_15 ( & V_30 , V_32 ) )
return - V_33 ;
V_29 . V_34 = V_28 ;
V_29 . V_35 = V_29 . V_34 + 1 ;
V_29 . V_36 = V_4 ;
F_13 (d, &r->domains, list) {
if ( V_13 -> V_14 && V_13 -> V_16 != V_13 -> V_37 [ V_28 ] ) {
F_16 ( F_17 ( & V_13 -> V_30 ) , V_30 ) ;
V_13 -> V_37 [ V_28 ] = V_13 -> V_16 ;
}
}
if ( F_18 ( V_30 ) )
goto V_38;
V_31 = F_19 () ;
if ( F_20 ( V_31 , V_30 ) )
F_21 ( & V_29 ) ;
F_22 ( V_30 , F_21 , & V_29 , 1 ) ;
F_23 () ;
V_38:
F_24 ( V_30 ) ;
return 0 ;
}
static int F_25 ( char * V_39 , char * V_40 , int V_28 )
{
struct V_3 * V_4 ;
F_26 (r) {
if ( ! strcmp ( V_39 , V_4 -> V_41 ) && V_28 < V_4 -> V_42 )
return F_10 ( V_40 , V_4 ) ;
}
return - V_15 ;
}
T_2 F_27 ( struct V_43 * V_44 ,
char * V_1 , T_3 V_45 , T_4 V_46 )
{
struct V_47 * V_48 ;
struct V_12 * V_23 ;
struct V_3 * V_4 ;
char * V_40 , * V_39 ;
int V_28 , V_6 = 0 ;
if ( V_45 == 0 || V_1 [ V_45 - 1 ] != '\n' )
return - V_15 ;
V_1 [ V_45 - 1 ] = '\0' ;
V_48 = F_28 ( V_44 -> V_49 ) ;
if ( ! V_48 ) {
F_29 ( V_44 -> V_49 ) ;
return - V_50 ;
}
V_28 = V_48 -> V_28 ;
F_26 (r) {
F_13 (dom, &r->domains, list)
V_23 -> V_14 = false ;
}
while ( ( V_40 = F_11 ( & V_1 , L_3 ) ) != NULL ) {
V_39 = F_12 ( F_11 ( & V_40 , L_4 ) ) ;
if ( ! V_40 ) {
V_6 = - V_15 ;
goto V_51;
}
V_6 = F_25 ( V_39 , V_40 , V_28 ) ;
if ( V_6 )
goto V_51;
}
F_26 (r) {
V_6 = F_14 ( V_4 , V_28 ) ;
if ( V_6 )
goto V_51;
}
V_51:
F_29 ( V_44 -> V_49 ) ;
return V_6 ? : V_45 ;
}
static void F_30 ( struct V_52 * V_53 , struct V_3 * V_4 , int V_28 )
{
struct V_12 * V_23 ;
bool V_54 = false ;
F_31 ( V_53 , L_5 , V_55 , V_4 -> V_41 ) ;
F_13 (dom, &r->domains, list) {
if ( V_54 )
F_32 ( V_53 , L_1 ) ;
F_31 ( V_53 , V_4 -> V_56 , V_23 -> V_24 , V_57 ,
V_23 -> V_37 [ V_28 ] ) ;
V_54 = true ;
}
F_32 ( V_53 , L_3 ) ;
}
int F_33 ( struct V_43 * V_44 ,
struct V_52 * V_53 , void * V_58 )
{
struct V_47 * V_48 ;
struct V_3 * V_4 ;
int V_28 , V_6 = 0 ;
V_48 = F_28 ( V_44 -> V_49 ) ;
if ( V_48 ) {
V_28 = V_48 -> V_28 ;
F_26 (r) {
if ( V_28 < V_4 -> V_42 )
F_30 ( V_53 , V_4 , V_28 ) ;
}
} else {
V_6 = - V_50 ;
}
F_29 ( V_44 -> V_49 ) ;
return V_6 ;
}
