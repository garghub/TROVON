struct V_1 * F_1 ( unsigned int V_2 ,
const char * V_3 )
{
struct V_1 * V_4 ;
void * V_5 ;
unsigned int V_6 ;
F_2 ( L_1 , V_7 ) ;
V_4 = (struct V_1 * ) 0 ;
V_5 = F_3 ( & V_4 [ 1 ] , V_2 ) ;
V_6 = ( ( unsigned long ) V_5 ) + V_2 ;
V_4 = F_4 ( V_6 , V_8 ) ;
if ( V_4 == NULL )
return NULL ;
V_5 = V_2 ? ( ( char * ) V_4 ) + ( ( unsigned long ) V_5 ) : NULL ;
V_4 -> V_9 = V_5 ;
V_4 -> V_10 = V_11 ;
snprintf ( V_4 -> V_12 , strlen ( V_3 ) + 1 , L_2 , V_3 ) ;
return V_4 ;
}
void F_5 ( struct V_1 * V_4 )
{
F_2 ( L_1 , V_7 ) ;
F_6 ( V_4 ) ;
}
static struct V_1 * F_7 ( struct V_13 * V_14 )
{
struct V_1 * V_4 ;
struct V_15 * V_16 ;
F_2 ( L_1 , V_7 ) ;
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
F_2 ( L_1 , V_7 ) ;
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
V_7 ) ;
return 1 ;
}
static void F_16 ( struct V_1 * V_4 )
{
F_17 ( & V_4 -> V_17 ) ;
F_18 () ;
F_19 ( & V_4 -> V_17 ) ;
}
static void F_20 ( struct V_28 * V_29 )
{
struct V_30 * V_31 = F_21 ( V_29 ) ;
struct V_1 * V_4 = F_22 ( V_31 ) ;
int V_32 ;
unsigned long V_33 ;
F_23 ( L_6 , V_7 ) ;
F_24 ( & V_34 ) ;
if ( V_4 -> V_10 == V_35 ) {
if ( ( V_4 -> V_36 != NULL ) && F_25 () )
V_4 -> V_36 ( V_4 ) ;
V_32 = F_26 () ;
if ( V_32 == 1000 )
V_33 = F_27 ( F_28 ( V_32 ) ) ;
else
V_33 = F_28 ( V_32 ) ;
F_29 ( V_37 , & V_4 -> V_38 , V_33 ) ;
}
F_30 ( & V_34 ) ;
}
static void F_31 ( struct V_1 * V_4 ,
unsigned int V_32 )
{
F_32 ( L_1 , V_7 ) ;
F_33 ( & V_4 -> V_38 , F_20 ) ;
F_29 ( V_37 , & V_4 -> V_38 ,
F_28 ( F_26 () ) ) ;
}
static void F_34 ( struct V_1 * V_4 )
{
int V_39 ;
F_32 ( L_1 , V_7 ) ;
V_39 = F_35 ( & V_4 -> V_38 ) ;
if ( V_39 == 0 )
F_36 ( V_37 ) ;
}
void F_37 ( struct V_1 * V_4 ,
unsigned long V_40 )
{
F_32 ( L_1 , V_7 ) ;
F_34 ( V_4 ) ;
F_24 ( & V_34 ) ;
F_31 ( V_4 , V_40 ) ;
F_30 ( & V_34 ) ;
}
int F_38 ( void )
{
return F_39 ( & V_41 ) - 1 ;
}
int F_40 ( struct V_1 * V_4 , int V_42 )
{
F_32 ( L_1 , V_7 ) ;
V_4 -> V_22 = V_42 ;
V_4 -> V_43 = V_44 ;
F_24 ( & V_34 ) ;
if ( F_10 ( V_4 ) )
goto V_21;
if ( F_41 ( V_4 ) ) {
F_42 ( V_4 , V_24 ,
L_7 ) ;
goto V_23;
}
if ( V_4 -> V_36 != NULL ) {
V_4 -> V_10 = V_35 ;
F_31 ( V_4 , 1000 ) ;
} else {
V_4 -> V_10 = V_45 ;
}
F_42 ( V_4 , V_46 ,
L_8
L_9 ,
V_4 -> V_26 ,
V_4 -> V_27 ,
F_15 ( V_4 ) , F_43 ( V_4 -> V_10 ) ) ;
F_30 ( & V_34 ) ;
return 0 ;
V_23:
F_16 ( V_4 ) ;
V_21:
F_30 ( & V_34 ) ;
return 1 ;
}
struct V_1 * F_44 ( struct V_13 * V_14 )
{
struct V_1 * V_4 ;
F_32 ( L_1 , V_7 ) ;
F_24 ( & V_34 ) ;
V_4 = F_7 ( V_14 ) ;
if ( V_4 == NULL ) {
F_30 ( & V_34 ) ;
return NULL ;
}
V_4 -> V_10 = V_47 ;
F_16 ( V_4 ) ;
F_30 ( & V_34 ) ;
F_34 ( V_4 ) ;
F_13 ( V_46 , V_25 ,
L_10 ,
V_4 -> V_22 , V_4 -> V_26 , V_4 -> V_27 , F_15 ( V_4 ) ) ;
return V_4 ;
}
static void F_45 ( struct V_1 * V_4 )
{
F_46 ( L_1 , V_7 ) ;
F_47 () ;
}
struct V_1 * F_48 ( struct V_13 * V_14 ,
const char * V_26 )
{
struct V_1 * V_4 ;
struct V_48 * V_49 ;
V_4 = F_1 ( sizeof( * V_49 ) , V_50 ) ;
if ( ! V_4 )
return NULL ;
V_49 = V_4 -> V_9 ;
V_4 -> V_14 = V_14 ;
F_49 ( V_4 -> V_14 , V_4 ) ;
V_4 -> F_14 = F_50 ( F_51 ( V_14 ) ) ;
V_4 -> V_26 = V_26 ;
V_4 -> V_27 = V_50 ;
V_4 -> V_36 = F_45 ;
V_49 -> V_42 = V_51 ++ ;
if ( F_40 ( V_4 , V_49 -> V_42 ) > 0 ) {
F_23 ( L_11 , V_7 ) ;
F_5 ( V_4 ) ;
return NULL ;
}
return V_4 ;
}
void F_52 ( struct V_1 * V_4 )
{
F_32 ( L_12 , V_7 , V_4 -> V_26 ) ;
F_44 ( V_4 -> V_14 ) ;
F_5 ( V_4 ) ;
}
