static bool F_1 ( struct V_1 * V_2 ,
unsigned int V_3 , unsigned int V_4 )
{
return F_2 ( V_3 , & V_2 -> V_5 [ V_4 ] . V_6 ) ;
}
static void F_3 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = F_4 ( V_8 ) ;
struct V_9 * V_10 = F_5 ( V_2 -> V_11 ) ;
struct V_7 * V_12 = F_6 ( V_2 -> V_11 ) ;
if ( F_1 ( V_2 , F_7 () , V_8 -> V_4 ) &&
V_10 -> V_13 )
V_10 -> V_13 ( V_12 ) ;
}
static void F_8 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = F_4 ( V_8 ) ;
struct V_9 * V_10 = F_5 ( V_2 -> V_11 ) ;
struct V_7 * V_12 = F_6 ( V_2 -> V_11 ) ;
if ( F_1 ( V_2 , F_7 () , V_8 -> V_4 ) &&
V_10 -> V_14 )
V_10 -> V_14 ( V_12 ) ;
}
static int F_9 ( struct V_7 * V_8 ,
enum V_15 V_16 ,
bool V_17 )
{
struct V_1 * V_2 = F_4 ( V_8 ) ;
struct V_9 * V_10 = F_5 ( V_2 -> V_11 ) ;
struct V_7 * V_12 = F_6 ( V_2 -> V_11 ) ;
if ( F_1 ( V_2 , F_7 () , V_8 -> V_4 ) &&
V_10 -> V_18 )
return V_10 -> V_18 ( V_12 , V_16 , V_17 ) ;
return - V_19 ;
}
static int F_10 ( struct V_7 * V_8 ,
enum V_15 V_16 ,
bool * V_17 )
{
struct V_1 * V_2 = F_4 ( V_8 ) ;
struct V_9 * V_10 = F_5 ( V_2 -> V_11 ) ;
struct V_7 * V_12 = F_6 ( V_2 -> V_11 ) ;
if ( F_1 ( V_2 , F_7 () , V_8 -> V_4 ) &&
V_10 -> V_20 )
return V_10 -> V_20 ( V_12 , V_16 , V_17 ) ;
return - V_19 ;
}
static int F_11 ( struct V_7 * V_8 , unsigned int type )
{
struct V_1 * V_2 = F_4 ( V_8 ) ;
struct V_9 * V_10 = F_5 ( V_2 -> V_11 ) ;
struct V_7 * V_12 = F_6 ( V_2 -> V_11 ) ;
if ( V_10 -> V_21 )
return V_10 -> V_21 ( V_12 , type ) ;
return - V_19 ;
}
static void F_12 ( struct V_7 * V_8 , struct V_22 * V_23 )
{
struct V_1 * V_2 = F_4 ( V_8 ) ;
struct V_9 * V_10 = F_5 ( V_2 -> V_11 ) ;
struct V_7 * V_12 = F_6 ( V_2 -> V_11 ) ;
F_13 ( V_23 , L_1 , V_10 -> V_24 , V_12 -> V_4 ) ;
}
static void F_14 ( struct V_25 * V_26 )
{
struct V_1 * V_2 = F_15 ( V_26 ) ;
struct V_9 * V_10 = F_5 ( V_26 ) ;
int V_3 = F_7 () ;
int V_4 ;
F_16 ( V_10 , V_26 ) ;
F_17 (hwirq, part->bitmap, part->nr_parts) {
if ( F_1 ( V_2 , V_3 , V_4 ) )
break;
}
if ( F_18 ( V_4 == V_2 -> V_27 ) ) {
F_19 ( V_26 ) ;
} else {
unsigned int V_28 ;
V_28 = F_20 ( V_2 -> V_29 , V_4 ) ;
F_21 ( V_28 ) ;
}
F_22 ( V_10 , V_26 ) ;
}
static int F_23 ( struct V_30 * V_29 , unsigned int V_31 ,
unsigned int V_32 , void * V_33 )
{
int V_34 ;
T_1 V_4 ;
unsigned int type ;
struct V_35 * V_36 = V_33 ;
struct V_1 * V_2 ;
F_24 ( V_32 != 1 ) ;
V_34 = V_29 -> V_37 -> V_38 ( V_29 , V_36 , & V_4 , & type ) ;
if ( V_34 )
return V_34 ;
V_2 = V_29 -> V_39 ;
F_25 ( V_4 , V_2 -> V_40 ) ;
F_26 ( F_27 ( V_2 -> V_11 ) ,
F_14 , V_2 ) ;
F_28 ( V_31 , & V_2 -> V_5 [ V_4 ] . V_6 ) ;
F_29 ( V_29 , V_31 , V_4 , & V_41 , V_2 ,
V_42 , NULL , NULL ) ;
F_30 ( V_31 , V_43 ) ;
return 0 ;
}
static void F_31 ( struct V_30 * V_29 , unsigned int V_31 ,
unsigned int V_32 )
{
struct V_7 * V_8 ;
F_24 ( V_32 != 1 ) ;
V_8 = F_32 ( V_29 , V_31 ) ;
F_33 ( V_31 , NULL ) ;
F_34 ( V_8 ) ;
}
int F_35 ( struct V_1 * V_26 , void * V_44 )
{
struct V_45 * V_2 = NULL ;
int V_46 ;
for ( V_46 = 0 ; V_46 < V_26 -> V_27 ; V_46 ++ ) {
if ( V_26 -> V_5 [ V_46 ] . V_44 == V_44 ) {
V_2 = & V_26 -> V_5 [ V_46 ] ;
break;
}
}
if ( F_36 ( ! V_2 ) ) {
F_37 ( L_2 ) ;
return - V_19 ;
}
return V_46 ;
}
struct V_1 * F_38 ( struct V_47 * V_48 ,
struct V_45 * V_5 ,
int V_27 ,
int V_49 ,
const struct V_50 * V_37 )
{
struct V_1 * V_26 ;
struct V_30 * V_8 ;
F_24 ( ! V_37 -> V_51 || ! V_37 -> V_38 ) ;
V_26 = F_39 ( sizeof( * V_26 ) , V_52 ) ;
if ( ! V_26 )
return NULL ;
V_26 -> V_37 = * V_37 ;
V_26 -> V_37 . free = F_31 ;
V_26 -> V_37 . V_53 = F_23 ;
V_8 = F_40 ( V_48 , V_27 , & V_26 -> V_37 , V_26 ) ;
if ( ! V_8 )
goto V_54;
V_26 -> V_29 = V_8 ;
V_26 -> V_40 = F_39 ( sizeof( long ) * F_41 ( V_27 ) ,
V_52 ) ;
if ( F_36 ( ! V_26 -> V_40 ) )
goto V_54;
V_26 -> V_11 = F_42 ( V_49 ) ;
V_26 -> V_27 = V_27 ;
V_26 -> V_5 = V_5 ;
return V_26 ;
V_54:
if ( V_8 )
F_43 ( V_8 ) ;
F_44 ( V_26 ) ;
return NULL ;
}
struct V_30 * F_45 ( struct V_1 * V_55 )
{
if ( V_55 )
return V_55 -> V_29 ;
return NULL ;
}
