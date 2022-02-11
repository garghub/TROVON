struct V_1 * F_1 ( unsigned int V_2 ,
const char * V_3 )
{
struct V_1 * V_4 ;
void * V_5 = NULL , * V_6 ;
unsigned int V_7 ;
F_2 ( L_1 , V_8 ) ;
V_4 = F_3 ( & V_5 , sizeof( * V_4 ) , 1 ) ;
V_6 = F_3 ( & V_5 , 1 , V_2 ) ;
V_7 = ( ( unsigned long ) V_6 ) + V_2 ;
V_4 = F_4 ( V_7 , V_9 ) ;
if ( V_4 == NULL )
return NULL ;
V_6 = V_2 ? ( ( char * ) V_4 ) + ( ( unsigned long ) V_6 ) : NULL ;
V_4 -> V_10 = V_6 ;
V_4 -> V_11 = V_12 ;
snprintf ( V_4 -> V_13 , strlen ( V_3 ) + 1 , L_2 , V_3 ) ;
return V_4 ;
}
void F_5 ( struct V_1 * V_4 )
{
F_2 ( L_1 , V_8 ) ;
F_6 ( V_4 ) ;
}
static struct V_1 * F_7 ( struct V_14 * V_15 )
{
struct V_1 * V_4 ;
struct V_16 * V_17 ;
F_2 ( L_1 , V_8 ) ;
F_8 (item, &edac_pci_list) {
V_4 = F_9 ( V_17 , struct V_1 , V_18 ) ;
if ( V_4 -> V_15 == V_15 )
return V_4 ;
}
return NULL ;
}
static int F_10 ( struct V_1 * V_4 )
{
struct V_16 * V_17 , * V_19 ;
struct V_1 * V_20 ;
F_2 ( L_1 , V_8 ) ;
V_19 = & V_21 ;
V_20 = F_7 ( V_4 -> V_15 ) ;
if ( F_11 ( V_20 != NULL ) )
goto V_22;
F_8 (item, &edac_pci_list) {
V_20 = F_9 ( V_17 , struct V_1 , V_18 ) ;
if ( V_20 -> V_23 >= V_4 -> V_23 ) {
if ( F_11 ( V_20 -> V_23 == V_4 -> V_23 ) )
goto V_24;
V_19 = V_17 ;
break;
}
}
F_12 ( & V_4 -> V_18 , V_19 ) ;
return 0 ;
V_22:
F_13 ( V_25 , V_26 ,
L_3 ,
F_14 ( V_20 -> V_15 ) , F_15 ( V_20 ) ,
V_20 -> V_27 , V_20 -> V_28 , V_20 -> V_23 ) ;
return 1 ;
V_24:
F_13 ( V_25 , V_26 ,
L_4
L_5 , V_20 -> V_23 ,
V_8 ) ;
return 1 ;
}
static void F_16 ( struct V_1 * V_4 )
{
F_17 ( & V_4 -> V_18 ) ;
F_18 () ;
F_19 ( & V_4 -> V_18 ) ;
}
static void F_20 ( struct V_29 * V_30 )
{
struct V_31 * V_32 = F_21 ( V_30 ) ;
struct V_1 * V_4 = F_22 ( V_32 ) ;
int V_33 ;
unsigned long V_34 ;
F_23 ( L_6 , V_8 ) ;
F_24 ( & V_35 ) ;
if ( V_4 -> V_11 == V_36 ) {
if ( ( V_4 -> V_37 != NULL ) && F_25 () )
V_4 -> V_37 ( V_4 ) ;
V_33 = F_26 () ;
if ( V_33 == 1000 )
V_34 = F_27 ( F_28 ( V_33 ) ) ;
else
V_34 = F_28 ( V_33 ) ;
F_29 ( V_38 , & V_4 -> V_39 , V_34 ) ;
}
F_30 ( & V_35 ) ;
}
static void F_31 ( struct V_1 * V_4 ,
unsigned int V_33 )
{
F_32 ( L_1 , V_8 ) ;
F_33 ( & V_4 -> V_39 , F_20 ) ;
F_29 ( V_38 , & V_4 -> V_39 ,
F_28 ( F_26 () ) ) ;
}
static void F_34 ( struct V_1 * V_4 )
{
int V_40 ;
F_32 ( L_1 , V_8 ) ;
V_40 = F_35 ( & V_4 -> V_39 ) ;
if ( V_40 == 0 )
F_36 ( V_38 ) ;
}
void F_37 ( struct V_1 * V_4 ,
unsigned long V_41 )
{
F_32 ( L_1 , V_8 ) ;
F_34 ( V_4 ) ;
F_24 ( & V_35 ) ;
F_31 ( V_4 , V_41 ) ;
F_30 ( & V_35 ) ;
}
int F_38 ( void )
{
return F_39 ( & V_42 ) - 1 ;
}
int F_40 ( struct V_1 * V_4 , int V_43 )
{
F_32 ( L_1 , V_8 ) ;
V_4 -> V_23 = V_43 ;
V_4 -> V_44 = V_45 ;
F_24 ( & V_35 ) ;
if ( F_10 ( V_4 ) )
goto V_22;
if ( F_41 ( V_4 ) ) {
F_42 ( V_4 , V_25 ,
L_7 ) ;
goto V_24;
}
if ( V_4 -> V_37 != NULL ) {
V_4 -> V_11 = V_36 ;
F_31 ( V_4 , 1000 ) ;
} else {
V_4 -> V_11 = V_46 ;
}
F_42 ( V_4 , V_47 ,
L_8
L_9 ,
V_4 -> V_27 ,
V_4 -> V_28 ,
F_15 ( V_4 ) , F_43 ( V_4 -> V_11 ) ) ;
F_30 ( & V_35 ) ;
return 0 ;
V_24:
F_16 ( V_4 ) ;
V_22:
F_30 ( & V_35 ) ;
return 1 ;
}
struct V_1 * F_44 ( struct V_14 * V_15 )
{
struct V_1 * V_4 ;
F_32 ( L_1 , V_8 ) ;
F_24 ( & V_35 ) ;
V_4 = F_7 ( V_15 ) ;
if ( V_4 == NULL ) {
F_30 ( & V_35 ) ;
return NULL ;
}
V_4 -> V_11 = V_48 ;
F_16 ( V_4 ) ;
F_30 ( & V_35 ) ;
F_34 ( V_4 ) ;
F_13 ( V_47 , V_26 ,
L_10 ,
V_4 -> V_23 , V_4 -> V_27 , V_4 -> V_28 , F_15 ( V_4 ) ) ;
return V_4 ;
}
static void F_45 ( struct V_1 * V_4 )
{
F_46 ( L_1 , V_8 ) ;
F_47 () ;
}
struct V_1 * F_48 ( struct V_14 * V_15 ,
const char * V_27 )
{
struct V_1 * V_4 ;
struct V_49 * V_50 ;
V_4 = F_1 ( sizeof( * V_50 ) , V_51 ) ;
if ( ! V_4 )
return NULL ;
V_50 = V_4 -> V_10 ;
V_4 -> V_15 = V_15 ;
F_49 ( V_4 -> V_15 , V_4 ) ;
V_4 -> F_14 = F_50 ( F_51 ( V_15 ) ) ;
V_4 -> V_27 = V_27 ;
V_4 -> V_28 = V_51 ;
V_4 -> V_37 = F_45 ;
V_50 -> V_43 = V_52 ++ ;
if ( F_40 ( V_4 , V_50 -> V_43 ) > 0 ) {
F_23 ( L_11 , V_8 ) ;
F_5 ( V_4 ) ;
return NULL ;
}
return V_4 ;
}
void F_52 ( struct V_1 * V_4 )
{
F_32 ( L_12 , V_8 , V_4 -> V_27 ) ;
F_44 ( V_4 -> V_15 ) ;
F_5 ( V_4 ) ;
}
