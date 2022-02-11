static bool F_1 ( unsigned long V_1 , struct V_2 * V_3 )
{
unsigned long V_4 , V_5 ;
if ( V_1 == 0 || V_1 > V_3 -> V_6 )
return false ;
V_4 = F_2 ( & V_1 , V_3 -> V_7 ) ;
V_5 = F_3 ( & V_1 , V_3 -> V_7 , V_4 ) ;
if ( F_4 ( & V_1 , V_3 -> V_7 , V_5 ) < V_3 -> V_7 )
return false ;
if ( ( V_5 - V_4 ) < V_3 -> V_8 )
return false ;
return true ;
}
static int F_5 ( char * V_9 , struct V_2 * V_3 )
{
unsigned long V_10 ;
int V_11 ;
V_11 = F_6 ( V_9 , 16 , & V_10 ) ;
if ( V_11 )
return V_11 ;
if ( ! F_1 ( V_10 , V_3 ) )
return - V_12 ;
V_3 -> V_13 [ V_3 -> V_14 ++ ] = V_10 ;
return 0 ;
}
static int F_7 ( char * line , struct V_2 * V_3 )
{
char * V_15 = NULL , * V_16 ;
struct V_17 * V_18 ;
unsigned long V_19 ;
F_8 (d, &r->domains, list) {
V_15 = F_9 ( & line , L_1 ) ;
if ( ! V_15 )
return - V_12 ;
V_16 = F_9 ( & V_15 , L_2 ) ;
if ( F_6 ( V_16 , 10 , & V_19 ) || V_19 != V_18 -> V_16 )
return - V_12 ;
if ( F_5 ( V_15 , V_3 ) )
return - V_12 ;
}
if ( line && line [ 0 ] )
return - V_12 ;
return 0 ;
}
static int F_10 ( struct V_2 * V_3 , int V_20 )
{
struct V_21 V_21 ;
T_1 V_22 ;
struct V_17 * V_18 ;
int V_23 , V_24 = 0 ;
if ( ! F_11 ( & V_22 , V_25 ) )
return - V_26 ;
V_21 . V_27 = V_20 ;
V_21 . V_28 = V_21 . V_27 + 1 ;
V_21 . V_29 = V_3 ;
F_8 (d, &r->domains, list) {
F_12 ( F_13 ( & V_18 -> V_22 ) , V_22 ) ;
V_18 -> V_30 [ V_21 . V_27 ] = V_3 -> V_13 [ V_24 ++ ] ;
}
V_23 = F_14 () ;
if ( F_15 ( V_23 , V_22 ) )
F_16 ( & V_21 ) ;
F_17 ( V_22 , F_16 , & V_21 , 1 ) ;
F_18 () ;
F_19 ( V_22 ) ;
return 0 ;
}
T_2 F_20 ( struct V_31 * V_32 ,
char * V_9 , T_3 V_33 , T_4 V_34 )
{
struct V_35 * V_36 ;
struct V_2 * V_3 ;
char * V_37 , * V_38 ;
int V_20 , V_11 = 0 ;
T_5 * V_39 = NULL ;
if ( V_33 == 0 || V_9 [ V_33 - 1 ] != '\n' )
return - V_12 ;
V_9 [ V_33 - 1 ] = '\0' ;
V_36 = F_21 ( V_32 -> V_40 ) ;
if ( ! V_36 ) {
F_22 ( V_32 -> V_40 ) ;
return - V_41 ;
}
V_20 = V_36 -> V_20 ;
F_23 (r) {
V_3 -> V_13 = F_24 ( V_3 -> V_42 , sizeof( * V_39 ) ,
V_25 ) ;
if ( ! V_3 -> V_13 ) {
V_11 = - V_26 ;
goto V_43;
}
V_3 -> V_14 = 0 ;
}
while ( ( V_37 = F_9 ( & V_9 , L_3 ) ) != NULL ) {
V_38 = F_9 ( & V_37 , L_4 ) ;
if ( ! V_37 ) {
V_11 = - V_12 ;
goto V_43;
}
F_23 (r) {
if ( ! strcmp ( V_38 , V_3 -> V_44 ) &&
V_20 < V_3 -> V_45 ) {
V_11 = F_7 ( V_37 , V_3 ) ;
if ( V_11 )
goto V_43;
break;
}
}
if ( ! V_3 -> V_44 ) {
V_11 = - V_12 ;
goto V_43;
}
}
F_23 (r) {
if ( V_3 -> V_14 != V_3 -> V_42 ) {
V_11 = - V_12 ;
goto V_43;
}
}
F_23 (r) {
V_11 = F_10 ( V_3 , V_20 ) ;
if ( V_11 )
goto V_43;
}
V_43:
F_23 (r) {
F_25 ( V_3 -> V_13 ) ;
V_3 -> V_13 = NULL ;
}
F_22 ( V_32 -> V_40 ) ;
return V_11 ? : V_33 ;
}
static void F_26 ( struct V_46 * V_47 , struct V_2 * V_3 , int V_20 )
{
struct V_17 * V_15 ;
bool V_48 = false ;
F_27 ( V_47 , L_5 , V_3 -> V_44 ) ;
F_8 (dom, &r->domains, list) {
if ( V_48 )
F_28 ( V_47 , L_1 ) ;
F_27 ( V_47 , L_6 , V_15 -> V_16 , V_15 -> V_30 [ V_20 ] ) ;
V_48 = true ;
}
F_28 ( V_47 , L_3 ) ;
}
int F_29 ( struct V_31 * V_32 ,
struct V_46 * V_47 , void * V_49 )
{
struct V_35 * V_36 ;
struct V_2 * V_3 ;
int V_20 , V_11 = 0 ;
V_36 = F_21 ( V_32 -> V_40 ) ;
if ( V_36 ) {
V_20 = V_36 -> V_20 ;
F_23 (r) {
if ( V_20 < V_3 -> V_45 )
F_26 ( V_47 , V_3 , V_20 ) ;
}
} else {
V_11 = - V_41 ;
}
F_22 ( V_32 -> V_40 ) ;
return V_11 ;
}
