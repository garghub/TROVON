static int F_1 ( struct V_1 * V_1 , int * V_2 )
{
int V_3 ;
F_2 ( & V_4 ) ;
V_3 = F_3 ( V_1 , NULL , 0 , 0 , V_5 ) ;
F_4 ( & V_4 ) ;
if ( F_5 ( V_3 < 0 ) )
return V_3 ;
* V_2 = V_3 ;
return 0 ;
}
static void F_6 ( struct V_1 * V_1 , int V_2 )
{
F_2 ( & V_4 ) ;
F_7 ( V_1 , V_2 ) ;
F_4 ( & V_4 ) ;
}
static unsigned long F_8 ( struct V_6 * V_7 ,
unsigned int V_8 )
{
unsigned long V_9 ;
for ( V_9 = 0 ; V_9 <= V_7 -> V_10 ; V_9 ++ ) {
if ( V_8 == V_7 -> V_11 [ V_9 ] )
return V_9 ;
if ( V_8 > V_7 -> V_11 [ V_9 ] )
break;
}
return V_12 ;
}
unsigned long F_9 ( unsigned int V_13 , unsigned int V_8 )
{
struct V_6 * V_7 ;
F_2 ( & V_4 ) ;
F_10 (cpufreq_dev, &cpufreq_dev_list, node) {
if ( F_11 ( V_13 , & V_7 -> V_14 ) ) {
F_4 ( & V_4 ) ;
return F_8 ( V_7 , V_8 ) ;
}
}
F_4 ( & V_4 ) ;
F_12 ( L_1 , V_15 , V_13 ) ;
return V_12 ;
}
static int F_13 ( struct V_16 * V_17 ,
unsigned long V_18 , void * V_19 )
{
struct V_20 * V_21 = V_19 ;
unsigned long V_22 = 0 ;
struct V_6 * V_7 ;
if ( V_18 != V_23 )
return 0 ;
F_2 ( & V_4 ) ;
F_10 (cpufreq_dev, &cpufreq_dev_list, node) {
if ( ! F_11 ( V_21 -> V_13 ,
& V_7 -> V_14 ) )
continue;
V_22 = V_7 -> V_24 ;
if ( V_21 -> V_25 != V_22 )
F_14 ( V_21 , 0 , V_22 ) ;
}
F_4 ( & V_4 ) ;
return 0 ;
}
static int F_15 ( struct V_26 * V_27 ,
unsigned long * V_28 )
{
struct V_6 * V_29 = V_27 -> V_30 ;
* V_28 = V_29 -> V_10 ;
return 0 ;
}
static int F_16 ( struct V_26 * V_27 ,
unsigned long * V_28 )
{
struct V_6 * V_29 = V_27 -> V_30 ;
* V_28 = V_29 -> V_31 ;
return 0 ;
}
static int F_17 ( struct V_26 * V_27 ,
unsigned long V_28 )
{
struct V_6 * V_29 = V_27 -> V_30 ;
unsigned int V_13 = F_18 ( & V_29 -> V_14 ) ;
unsigned int V_32 ;
if ( F_19 ( V_28 > V_29 -> V_10 ) )
return - V_33 ;
if ( V_29 -> V_31 == V_28 )
return 0 ;
V_32 = V_29 -> V_11 [ V_28 ] ;
V_29 -> V_31 = V_28 ;
V_29 -> V_24 = V_32 ;
F_20 ( V_13 ) ;
return 0 ;
}
static unsigned int F_21 ( struct V_34 * V_35 ,
unsigned int V_36 )
{
struct V_34 * V_37 ;
unsigned int V_25 = 0 ;
F_22 (pos, table) {
if ( V_37 -> V_38 > V_25 && V_37 -> V_38 < V_36 )
V_25 = V_37 -> V_38 ;
}
return V_25 ;
}
static struct V_26 *
F_23 ( struct V_39 * V_40 ,
const struct V_41 * V_42 )
{
struct V_26 * V_43 ;
struct V_6 * V_7 ;
char V_44 [ V_45 ] ;
struct V_34 * V_37 , * V_35 ;
unsigned int V_8 , V_46 ;
int V_3 ;
V_35 = F_24 ( F_25 ( V_42 ) ) ;
if ( ! V_35 ) {
F_26 ( L_2 , V_15 ) ;
return F_27 ( - V_47 ) ;
}
V_7 = F_28 ( sizeof( * V_7 ) , V_5 ) ;
if ( ! V_7 )
return F_27 ( - V_48 ) ;
F_22 (pos, table)
V_7 -> V_10 ++ ;
V_7 -> V_11 = F_29 ( sizeof( * V_7 -> V_11 ) *
V_7 -> V_10 , V_5 ) ;
if ( ! V_7 -> V_11 ) {
V_43 = F_27 ( - V_48 ) ;
goto V_49;
}
V_7 -> V_10 -- ;
F_30 ( & V_7 -> V_14 , V_42 ) ;
V_3 = F_1 ( & V_50 , & V_7 -> V_2 ) ;
if ( V_3 ) {
V_43 = F_27 ( V_3 ) ;
goto V_51;
}
snprintf ( V_44 , sizeof( V_44 ) , L_3 ,
V_7 -> V_2 ) ;
V_43 = F_31 ( V_40 , V_44 , V_7 ,
& V_52 ) ;
if ( F_32 ( V_43 ) )
goto V_53;
for ( V_46 = 0 , V_8 = - 1 ; V_46 <= V_7 -> V_10 ; V_46 ++ ) {
V_8 = F_21 ( V_35 , V_8 ) ;
V_7 -> V_11 [ V_46 ] = V_8 ;
if ( ! V_8 )
F_33 ( L_4 , V_15 ) ;
else
F_26 ( L_5 , V_15 , V_8 ) ;
}
V_7 -> V_24 = V_7 -> V_11 [ 0 ] ;
V_7 -> V_43 = V_43 ;
F_2 ( & V_4 ) ;
if ( F_34 ( & V_54 ) )
F_35 ( & V_55 ,
V_56 ) ;
F_36 ( & V_7 -> V_57 , & V_54 ) ;
F_4 ( & V_4 ) ;
return V_43 ;
V_53:
F_6 ( & V_50 , V_7 -> V_2 ) ;
V_51:
F_37 ( V_7 -> V_11 ) ;
V_49:
F_37 ( V_7 ) ;
return V_43 ;
}
struct V_26 *
F_38 ( const struct V_41 * V_42 )
{
return F_23 ( NULL , V_42 ) ;
}
struct V_26 *
F_39 ( struct V_39 * V_40 ,
const struct V_41 * V_42 )
{
if ( ! V_40 )
return F_27 ( - V_33 ) ;
return F_23 ( V_40 , V_42 ) ;
}
void F_40 ( struct V_26 * V_27 )
{
struct V_6 * V_7 ;
if ( ! V_27 )
return;
V_7 = V_27 -> V_30 ;
F_2 ( & V_4 ) ;
F_41 ( & V_7 -> V_57 ) ;
if ( F_34 ( & V_54 ) )
F_42 ( & V_55 ,
V_56 ) ;
F_4 ( & V_4 ) ;
F_43 ( V_7 -> V_43 ) ;
F_6 ( & V_50 , V_7 -> V_2 ) ;
F_37 ( V_7 -> V_11 ) ;
F_37 ( V_7 ) ;
}
