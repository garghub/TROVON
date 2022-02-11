static inline struct V_1 * F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 ;
}
static struct V_4 * F_2 ( struct V_5 * V_6 ,
unsigned int V_7 ,
unsigned int V_8 ,
unsigned int V_9 )
{
struct V_10 * V_11 ;
struct V_4 * V_12 = NULL ;
struct V_13 * V_14 = V_6 -> V_15 ;
if ( V_7 != 0 || V_8 != 0 )
return NULL ;
if ( F_3 ( V_9 ) < V_16 ) {
F_4 ( & V_14 -> V_17 ) ;
F_5 (entry,
&vpci_dev->dev_list[PCI_SLOT(devfn)],
list) {
if ( F_6 ( V_11 -> V_12 -> V_9 ) == F_6 ( V_9 ) ) {
V_12 = V_11 -> V_12 ;
break;
}
}
F_7 ( & V_14 -> V_17 ) ;
}
return V_12 ;
}
static inline int F_8 ( struct V_4 * V_18 , struct V_4 * V_19 )
{
if ( F_9 ( V_18 -> V_8 ) == F_9 ( V_19 -> V_8 )
&& V_18 -> V_8 == V_19 -> V_8 && F_3 ( V_18 -> V_9 ) == F_3 ( V_19 -> V_9 ) )
return 1 ;
return 0 ;
}
static int F_10 ( struct V_5 * V_6 ,
struct V_4 * V_12 , int V_20 ,
T_1 V_21 )
{
int V_22 = 0 , V_23 , V_24 = - 1 ;
struct V_10 * V_25 , * V_26 ;
struct V_13 * V_14 = V_6 -> V_15 ;
if ( ( V_12 -> V_27 >> 24 ) == V_28 ) {
V_22 = - V_29 ;
F_11 ( V_6 -> V_30 , V_22 ,
L_1 ) ;
goto V_31;
}
V_26 = F_12 ( sizeof( * V_26 ) , V_32 ) ;
if ( ! V_26 ) {
V_22 = - V_33 ;
F_11 ( V_6 -> V_30 , V_22 ,
L_2 ) ;
goto V_31;
}
V_26 -> V_12 = V_12 ;
F_4 ( & V_14 -> V_17 ) ;
for ( V_23 = 0 ; V_23 < V_16 ; V_23 ++ ) {
if ( ! F_13 ( & V_14 -> V_34 [ V_23 ] ) ) {
V_25 = F_14 ( F_1 ( & V_14 -> V_34 [ V_23 ] ) ,
struct V_10 , V_35 ) ;
if ( F_8 ( V_12 , V_25 -> V_12 ) ) {
F_15 ( V_36 L_3
L_4 ,
F_16 ( V_12 ) , V_23 ,
F_6 ( V_12 -> V_9 ) ) ;
F_17 ( & V_26 -> V_35 ,
& V_14 -> V_34 [ V_23 ] ) ;
V_24 = F_6 ( V_12 -> V_9 ) ;
goto V_37;
}
}
}
for ( V_23 = 0 ; V_23 < V_16 ; V_23 ++ ) {
if ( F_13 ( & V_14 -> V_34 [ V_23 ] ) ) {
F_18 (KERN_INFO DRV_NAME
L_5 ,
pci_name(dev), slot) ;
F_17 ( & V_26 -> V_35 ,
& V_14 -> V_34 [ V_23 ] ) ;
V_24 = F_6 ( V_12 -> V_9 ) ;
goto V_37;
}
}
V_22 = - V_33 ;
F_11 ( V_6 -> V_30 , V_22 ,
L_6 ) ;
V_37:
F_7 ( & V_14 -> V_17 ) ;
if ( ! V_22 )
V_22 = V_21 ( V_6 , 0 , 0 , F_19 ( V_23 , V_24 ) , V_20 ) ;
V_31:
return V_22 ;
}
static void F_20 ( struct V_5 * V_6 ,
struct V_4 * V_12 )
{
int V_23 ;
struct V_13 * V_14 = V_6 -> V_15 ;
struct V_4 * V_38 = NULL ;
F_4 ( & V_14 -> V_17 ) ;
for ( V_23 = 0 ; V_23 < V_16 ; V_23 ++ ) {
struct V_10 * V_39 ;
F_5 (e, &vpci_dev->dev_list[slot], list) {
if ( V_39 -> V_12 == V_12 ) {
F_21 ( & V_39 -> V_35 ) ;
V_38 = V_39 -> V_12 ;
F_22 ( V_39 ) ;
goto V_31;
}
}
}
V_31:
F_7 ( & V_14 -> V_17 ) ;
if ( V_38 )
F_23 ( V_38 ) ;
}
static int F_24 ( struct V_5 * V_6 )
{
int V_23 ;
struct V_13 * V_14 ;
V_14 = F_12 ( sizeof( * V_14 ) , V_32 ) ;
if ( ! V_14 )
return - V_33 ;
F_25 ( & V_14 -> V_17 ) ;
for ( V_23 = 0 ; V_23 < V_16 ; V_23 ++ )
F_26 ( & V_14 -> V_34 [ V_23 ] ) ;
V_6 -> V_15 = V_14 ;
return 0 ;
}
static int F_27 ( struct V_5 * V_6 ,
T_2 V_21 )
{
return V_21 ( V_6 , 0 , 0 ) ;
}
static void F_28 ( struct V_5 * V_6 )
{
int V_23 ;
struct V_13 * V_14 = V_6 -> V_15 ;
for ( V_23 = 0 ; V_23 < V_16 ; V_23 ++ ) {
struct V_10 * V_39 , * V_40 ;
F_29 (e, tmp, &vpci_dev->dev_list[slot],
list) {
F_21 ( & V_39 -> V_35 ) ;
F_23 ( V_39 -> V_12 ) ;
F_22 ( V_39 ) ;
}
}
F_22 ( V_14 ) ;
V_6 -> V_15 = NULL ;
}
static int F_30 ( struct V_4 * V_41 ,
struct V_5 * V_6 ,
unsigned int * V_7 , unsigned int * V_8 ,
unsigned int * V_9 )
{
struct V_10 * V_11 ;
struct V_4 * V_12 = NULL ;
struct V_13 * V_14 = V_6 -> V_15 ;
int V_42 = 0 , V_23 ;
F_4 ( & V_14 -> V_17 ) ;
for ( V_23 = 0 ; V_23 < V_16 ; V_23 ++ ) {
F_5 (entry,
&vpci_dev->dev_list[slot],
list) {
V_12 = V_11 -> V_12 ;
if ( V_12 && V_12 -> V_8 -> V_43 == V_41 -> V_8 -> V_43
&& F_9 ( V_12 -> V_8 ) ==
F_9 ( V_41 -> V_8 )
&& V_12 -> V_9 == V_41 -> V_9 ) {
V_42 = 1 ;
* V_7 = 0 ;
* V_8 = 0 ;
* V_9 = F_19 ( V_23 ,
F_6 ( V_41 -> V_9 ) ) ;
}
}
}
F_7 ( & V_14 -> V_17 ) ;
return V_42 ;
}
