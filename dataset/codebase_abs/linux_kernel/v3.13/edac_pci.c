struct V_1 * F_1 ( unsigned int V_2 ,
const char * V_3 )
{
struct V_1 * V_4 ;
void * V_5 = NULL , * V_6 ;
unsigned int V_7 ;
F_2 ( 1 , L_1 ) ;
V_4 = F_3 ( & V_5 , sizeof( * V_4 ) , 1 ) ;
V_6 = F_3 ( & V_5 , 1 , V_2 ) ;
V_7 = ( ( unsigned long ) V_6 ) + V_2 ;
V_4 = F_4 ( V_7 , V_8 ) ;
if ( V_4 == NULL )
return NULL ;
V_6 = V_2 ? ( ( char * ) V_4 ) + ( ( unsigned long ) V_6 ) : NULL ;
V_4 -> V_9 = V_6 ;
V_4 -> V_10 = V_11 ;
snprintf ( V_4 -> V_12 , strlen ( V_3 ) + 1 , L_2 , V_3 ) ;
return V_4 ;
}
void F_5 ( struct V_1 * V_4 )
{
F_2 ( 1 , L_1 ) ;
F_6 ( V_4 ) ;
}
static struct V_1 * F_7 ( struct V_13 * V_14 )
{
struct V_1 * V_4 ;
struct V_15 * V_16 ;
F_2 ( 1 , L_1 ) ;
F_8 (item, &edac_pci_list) {
V_4 = F_9 ( V_16 , struct V_1 , V_17 ) ;
if ( V_4 -> V_14 == V_14 )
return V_4 ;
}
return NULL ;
}
static int F_10 ( struct V_1 * V_4 )
{
struct V_15 * V_16 , * V_18 ;
struct V_1 * V_19 ;
F_2 ( 1 , L_1 ) ;
V_18 = & V_20 ;
V_19 = F_7 ( V_4 -> V_14 ) ;
if ( F_11 ( V_19 != NULL ) )
goto V_21;
F_8 (item, &edac_pci_list) {
V_19 = F_9 ( V_16 , struct V_1 , V_17 ) ;
if ( V_19 -> V_22 >= V_4 -> V_22 ) {
if ( F_11 ( V_19 -> V_22 == V_4 -> V_22 ) )
goto V_23;
V_18 = V_16 ;
break;
}
}
F_12 ( & V_4 -> V_17 , V_18 ) ;
return 0 ;
V_21:
F_13 ( V_24 , V_25 ,
L_3 ,
F_14 ( V_19 -> V_14 ) , F_15 ( V_19 ) ,
V_19 -> V_26 , V_19 -> V_27 , V_19 -> V_22 ) ;
return 1 ;
V_23:
F_13 ( V_24 , V_25 ,
L_4
L_5 , V_19 -> V_22 ,
V_28 ) ;
return 1 ;
}
static void F_16 ( struct V_1 * V_4 )
{
F_17 ( & V_4 -> V_17 ) ;
F_18 () ;
F_19 ( & V_4 -> V_17 ) ;
}
static void F_20 ( struct V_29 * V_30 )
{
struct V_31 * V_32 = F_21 ( V_30 ) ;
struct V_1 * V_4 = F_22 ( V_32 ) ;
int V_33 ;
unsigned long V_34 ;
F_2 ( 3 , L_6 ) ;
F_23 ( & V_35 ) ;
if ( V_4 -> V_10 == V_36 ) {
if ( ( V_4 -> V_37 != NULL ) && F_24 () )
V_4 -> V_37 ( V_4 ) ;
V_33 = F_25 () ;
if ( V_33 == 1000 )
V_34 = F_26 ( F_27 ( V_33 ) ) ;
else
V_34 = F_27 ( V_33 ) ;
F_28 ( V_38 , & V_4 -> V_39 , V_34 ) ;
}
F_29 ( & V_35 ) ;
}
static void F_30 ( struct V_1 * V_4 ,
unsigned int V_33 )
{
F_2 ( 0 , L_1 ) ;
F_31 ( & V_4 -> V_39 , F_20 ) ;
F_28 ( V_38 , & V_4 -> V_39 ,
F_27 ( F_25 () ) ) ;
}
static void F_32 ( struct V_1 * V_4 )
{
int V_40 ;
F_2 ( 0 , L_1 ) ;
V_40 = F_33 ( & V_4 -> V_39 ) ;
if ( V_40 == 0 )
F_34 ( V_38 ) ;
}
void F_35 ( struct V_1 * V_4 ,
unsigned long V_41 )
{
F_2 ( 0 , L_1 ) ;
F_32 ( V_4 ) ;
F_23 ( & V_35 ) ;
F_30 ( V_4 , V_41 ) ;
F_29 ( & V_35 ) ;
}
int F_36 ( void )
{
return F_37 ( & V_42 ) - 1 ;
}
int F_38 ( struct V_1 * V_4 , int V_43 )
{
F_2 ( 0 , L_1 ) ;
V_4 -> V_22 = V_43 ;
V_4 -> V_44 = V_45 ;
F_23 ( & V_35 ) ;
if ( F_10 ( V_4 ) )
goto V_21;
if ( F_39 ( V_4 ) ) {
F_40 ( V_4 , V_24 ,
L_7 ) ;
goto V_23;
}
if ( V_4 -> V_37 != NULL ) {
V_4 -> V_10 = V_36 ;
F_30 ( V_4 , 1000 ) ;
} else {
V_4 -> V_10 = V_46 ;
}
F_40 ( V_4 , V_47 ,
L_8 ,
V_4 -> V_26 , V_4 -> V_27 , V_4 -> F_14 ,
F_41 ( V_4 -> V_10 ) ) ;
F_29 ( & V_35 ) ;
return 0 ;
V_23:
F_16 ( V_4 ) ;
V_21:
F_29 ( & V_35 ) ;
return 1 ;
}
struct V_1 * F_42 ( struct V_13 * V_14 )
{
struct V_1 * V_4 ;
F_2 ( 0 , L_1 ) ;
F_23 ( & V_35 ) ;
V_4 = F_7 ( V_14 ) ;
if ( V_4 == NULL ) {
F_29 ( & V_35 ) ;
return NULL ;
}
V_4 -> V_10 = V_48 ;
F_16 ( V_4 ) ;
F_29 ( & V_35 ) ;
F_32 ( V_4 ) ;
F_13 ( V_47 , V_25 ,
L_9 ,
V_4 -> V_22 , V_4 -> V_26 , V_4 -> V_27 , F_15 ( V_4 ) ) ;
return V_4 ;
}
static void F_43 ( struct V_1 * V_4 )
{
F_2 ( 4 , L_1 ) ;
F_44 () ;
}
struct V_1 * F_45 ( struct V_13 * V_14 ,
const char * V_26 )
{
struct V_1 * V_4 ;
struct V_49 * V_50 ;
V_4 = F_1 ( sizeof( * V_50 ) , V_51 ) ;
if ( ! V_4 )
return NULL ;
V_50 = V_4 -> V_9 ;
V_4 -> V_14 = V_14 ;
F_46 ( V_4 -> V_14 , V_4 ) ;
V_4 -> F_14 = F_47 ( F_48 ( V_14 ) ) ;
V_4 -> V_26 = V_26 ;
V_4 -> V_27 = V_51 ;
if ( V_52 == V_53 )
V_4 -> V_37 = F_43 ;
V_50 -> V_43 = V_54 ++ ;
if ( F_38 ( V_4 , V_50 -> V_43 ) > 0 ) {
F_2 ( 3 , L_10 ) ;
F_5 ( V_4 ) ;
return NULL ;
}
return V_4 ;
}
void F_49 ( struct V_1 * V_4 )
{
F_2 ( 0 , L_11 , V_4 -> V_26 ) ;
F_42 ( V_4 -> V_14 ) ;
F_5 ( V_4 ) ;
}
