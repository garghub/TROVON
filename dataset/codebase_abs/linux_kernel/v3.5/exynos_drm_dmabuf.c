static struct V_1 * F_1 ( struct V_2 * * V_3 , int V_4 ,
unsigned int V_5 )
{
struct V_1 * V_6 = NULL ;
struct V_7 * V_8 ;
int V_9 , V_10 ;
V_6 = F_2 ( sizeof( * V_6 ) , V_11 ) ;
if ( ! V_6 )
goto V_12;
V_10 = F_3 ( V_6 , V_4 , V_11 ) ;
if ( V_10 )
goto V_13;
if ( V_5 < V_14 )
V_5 = V_14 ;
F_4 (sgt->sgl, sgl, nr_pages, i)
F_5 ( V_8 , V_3 [ V_9 ] , V_5 , 0 ) ;
return V_6 ;
V_13:
F_6 ( V_6 ) ;
V_6 = NULL ;
V_12:
return NULL ;
}
static struct V_1 *
F_7 ( struct V_15 * V_16 ,
enum V_17 V_18 )
{
struct V_19 * V_20 = V_16 -> V_21 -> V_22 ;
struct V_23 * V_24 = V_20 -> V_25 . V_24 ;
struct V_26 * V_27 ;
struct V_1 * V_6 = NULL ;
unsigned int V_28 ;
int V_29 ;
F_8 ( L_1 , __FILE__ ) ;
F_9 ( & V_24 -> V_30 ) ;
V_27 = V_20 -> V_31 ;
if ( ! V_27 -> V_3 ) {
F_10 ( L_2 ) ;
goto V_32;
}
V_28 = V_27 -> V_33 / V_27 -> V_5 ;
V_6 = F_1 ( V_27 -> V_3 , V_28 , V_27 -> V_5 ) ;
V_29 = F_11 ( V_16 -> V_24 , V_6 -> V_8 , V_6 -> V_29 , V_18 ) ;
F_8 ( L_3 ,
V_28 , V_27 -> V_33 , V_27 -> V_5 ) ;
V_32:
F_12 ( & V_24 -> V_30 ) ;
return V_6 ;
}
static void F_13 ( struct V_15 * V_16 ,
struct V_1 * V_6 ,
enum V_17 V_18 )
{
F_14 ( V_16 -> V_24 , V_6 -> V_8 , V_6 -> V_29 , V_18 ) ;
F_15 ( V_6 ) ;
F_6 ( V_6 ) ;
V_6 = NULL ;
}
static void F_16 ( struct V_34 * V_21 )
{
struct V_19 * V_35 = V_21 -> V_22 ;
F_8 ( L_1 , __FILE__ ) ;
if ( V_35 -> V_25 . V_36 == V_21 ) {
V_35 -> V_25 . V_36 = NULL ;
F_17 ( & V_35 -> V_25 ) ;
}
}
static void * F_18 ( struct V_34 * V_34 ,
unsigned long V_37 )
{
return NULL ;
}
static void F_19 ( struct V_34 * V_34 ,
unsigned long V_37 ,
void * V_38 )
{
}
static void * F_20 ( struct V_34 * V_34 ,
unsigned long V_37 )
{
return NULL ;
}
static void F_21 ( struct V_34 * V_34 ,
unsigned long V_37 , void * V_38 )
{
}
struct V_34 * F_22 ( struct V_23 * V_39 ,
struct V_40 * V_41 , int V_42 )
{
struct V_19 * V_35 = F_23 ( V_41 ) ;
return F_24 ( V_35 , & V_43 ,
V_35 -> V_25 . V_33 , 0600 ) ;
}
struct V_40 * F_25 ( struct V_23 * V_39 ,
struct V_34 * V_34 )
{
struct V_15 * V_16 ;
struct V_1 * V_6 ;
struct V_7 * V_8 ;
struct V_19 * V_35 ;
struct V_26 * V_31 ;
struct V_2 * V_2 ;
int V_10 , V_9 = 0 ;
F_8 ( L_1 , __FILE__ ) ;
if ( V_34 -> V_44 == & V_43 ) {
struct V_40 * V_41 ;
V_35 = V_34 -> V_22 ;
V_41 = & V_35 -> V_25 ;
if ( V_41 -> V_24 == V_39 ) {
F_26 ( V_41 ) ;
return V_41 ;
}
}
V_16 = F_27 ( V_34 , V_39 -> V_24 ) ;
if ( F_28 ( V_16 ) )
return F_29 ( - V_45 ) ;
V_6 = F_30 ( V_16 , V_46 ) ;
if ( F_28 ( V_6 ) ) {
V_10 = F_31 ( V_6 ) ;
goto V_47;
}
V_31 = F_2 ( sizeof( * V_31 ) , V_11 ) ;
if ( ! V_31 ) {
F_10 ( L_4 ) ;
V_10 = - V_48 ;
goto V_49;
}
V_31 -> V_3 = F_2 ( sizeof( * V_2 ) * V_6 -> V_29 , V_11 ) ;
if ( ! V_31 -> V_3 ) {
F_10 ( L_5 ) ;
V_10 = - V_48 ;
goto V_50;
}
V_35 = F_32 ( V_39 , V_34 -> V_33 ) ;
if ( ! V_35 ) {
V_10 = - V_48 ;
goto V_51;
}
V_8 = V_6 -> V_8 ;
V_31 -> V_52 = F_33 ( V_8 ) ;
while ( V_9 < V_6 -> V_29 ) {
V_31 -> V_3 [ V_9 ] = F_34 ( V_8 ) ;
V_31 -> V_33 += F_35 ( V_8 ) ;
V_8 = F_36 ( V_8 ) ;
V_9 ++ ;
}
V_35 -> V_31 = V_31 ;
V_31 -> V_6 = V_6 ;
V_35 -> V_25 . V_53 = V_16 ;
F_8 ( L_6 , V_31 -> V_52 ,
V_31 -> V_33 ) ;
return & V_35 -> V_25 ;
V_51:
F_6 ( V_31 -> V_3 ) ;
V_31 -> V_3 = NULL ;
V_50:
F_6 ( V_31 ) ;
V_31 = NULL ;
V_49:
F_37 ( V_16 , V_6 , V_46 ) ;
V_47:
F_38 ( V_34 , V_16 ) ;
return F_29 ( V_10 ) ;
}
