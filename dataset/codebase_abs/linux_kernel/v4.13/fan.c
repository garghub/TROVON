static int F_1 ( struct V_1 * V_2 , unsigned long
* V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 = F_2 ( V_5 ) ;
if ( V_8 -> V_9 )
* V_3 = V_8 -> V_10 - 1 ;
else
* V_3 = 1 ;
return 0 ;
}
static int F_3 ( struct V_4 * V_5 , unsigned long * V_3 )
{
struct V_11 V_12 = { V_13 , NULL } ;
struct V_7 * V_8 = F_2 ( V_5 ) ;
union V_14 * V_15 ;
T_1 V_16 ;
int V_17 , V_18 ;
V_16 = F_4 ( V_5 -> V_19 , L_1 , NULL , & V_12 ) ;
if ( F_5 ( V_16 ) ) {
F_6 ( & V_5 -> V_20 , L_2 ) ;
return V_16 ;
}
V_15 = V_12 . V_21 ;
if ( ! V_15 || V_15 -> type != V_22 ||
V_15 -> V_23 . V_24 != 3 ||
V_15 -> V_23 . V_25 [ 1 ] . type != V_26 ) {
F_6 ( & V_5 -> V_20 , L_3 ) ;
V_16 = - V_27 ;
goto V_28;
}
V_17 = V_15 -> V_23 . V_25 [ 1 ] . integer . V_29 ;
for ( V_18 = 0 ; V_18 < V_8 -> V_10 ; V_18 ++ ) {
if ( V_8 -> V_30 . V_31 && V_17 < V_8 -> V_32 [ V_18 ] . V_17 ) {
V_18 = ( V_18 > 0 ) ? V_18 - 1 : 0 ;
break;
} else if ( V_17 == V_8 -> V_32 [ V_18 ] . V_17 ) {
break;
}
}
if ( V_18 == V_8 -> V_10 ) {
F_7 ( & V_5 -> V_20 , L_4 ) ;
V_16 = - V_27 ;
goto V_28;
}
* V_3 = V_18 ;
V_28:
F_8 ( V_15 ) ;
return V_16 ;
}
static int F_9 ( struct V_4 * V_5 , unsigned long * V_3 )
{
int V_33 ;
int V_34 = V_35 ;
V_33 = F_10 ( V_5 , & V_34 ) ;
if ( V_33 )
return V_33 ;
* V_3 = V_34 == V_36
|| V_34 == V_37 ?
0 : ( V_34 == V_35 ? 1 : - 1 ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 , unsigned long
* V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 = F_2 ( V_5 ) ;
if ( V_8 -> V_9 )
return F_3 ( V_5 , V_3 ) ;
else
return F_9 ( V_5 , V_3 ) ;
}
static int F_12 ( struct V_4 * V_5 , unsigned long V_3 )
{
if ( V_3 != 0 && V_3 != 1 )
return - V_27 ;
return F_13 ( V_5 ,
V_3 ? V_35 : V_36 ) ;
}
static int F_14 ( struct V_4 * V_5 , unsigned long V_3 )
{
struct V_7 * V_8 = F_2 ( V_5 ) ;
T_1 V_16 ;
if ( V_3 >= V_8 -> V_10 )
return - V_27 ;
V_16 = F_15 ( V_5 -> V_19 , L_5 ,
V_8 -> V_32 [ V_3 ] . V_17 ) ;
if ( F_5 ( V_16 ) ) {
F_7 ( & V_5 -> V_20 , L_6 ) ;
return V_16 ;
}
return 0 ;
}
static int
F_16 ( struct V_1 * V_2 , unsigned long V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 = F_2 ( V_5 ) ;
if ( V_8 -> V_9 )
return F_14 ( V_5 , V_3 ) ;
else
return F_12 ( V_5 , V_3 ) ;
}
static bool F_17 ( struct V_4 * V_5 )
{
return F_18 ( V_5 -> V_19 , L_7 ) &&
F_18 ( V_5 -> V_19 , L_8 ) &&
F_18 ( V_5 -> V_19 , L_5 ) &&
F_18 ( V_5 -> V_19 , L_1 ) ;
}
static int F_19 ( struct V_4 * V_5 )
{
struct V_11 V_12 = { V_13 , NULL } ;
struct V_7 * V_8 = F_2 ( V_5 ) ;
struct V_11 V_38 = { sizeof( L_9 ) , L_9 } ;
struct V_11 V_30 = { sizeof( V_8 -> V_30 ) , & V_8 -> V_30 } ;
union V_14 * V_15 ;
T_1 V_16 ;
V_16 = F_4 ( V_5 -> V_19 , L_7 , NULL , & V_12 ) ;
if ( F_5 ( V_16 ) )
return V_16 ;
V_15 = V_12 . V_21 ;
if ( ! V_15 || V_15 -> type != V_22 ) {
F_6 ( & V_5 -> V_20 , L_10 ) ;
V_16 = - V_27 ;
goto V_28;
}
V_16 = F_20 ( V_15 , & V_38 , & V_30 ) ;
if ( F_5 ( V_16 ) ) {
F_6 ( & V_5 -> V_20 , L_11 ) ;
V_16 = - V_27 ;
}
V_28:
F_8 ( V_15 ) ;
return V_16 ;
}
static int F_21 ( const void * V_39 , const void * V_40 )
{
const struct V_41 * V_42 = V_39 ;
const struct V_41 * V_43 = V_40 ;
return V_42 -> V_44 - V_43 -> V_44 ;
}
static int F_22 ( struct V_4 * V_5 )
{
struct V_7 * V_8 = F_2 ( V_5 ) ;
struct V_11 V_12 = { V_13 , NULL } ;
union V_14 * V_15 ;
T_1 V_16 ;
int V_18 ;
V_16 = F_4 ( V_5 -> V_19 , L_8 , NULL , & V_12 ) ;
if ( F_5 ( V_16 ) )
return V_16 ;
V_15 = V_12 . V_21 ;
if ( ! V_15 || V_15 -> type != V_22 || V_15 -> V_23 . V_24 < 2 ) {
F_6 ( & V_5 -> V_20 , L_12 ) ;
V_16 = - V_27 ;
goto V_28;
}
V_8 -> V_10 = V_15 -> V_23 . V_24 - 1 ;
V_8 -> V_32 = F_23 ( & V_5 -> V_20 ,
V_8 -> V_10 * sizeof( struct V_41 ) ,
V_45 ) ;
if ( ! V_8 -> V_32 ) {
F_6 ( & V_5 -> V_20 , L_13 ) ;
V_16 = - V_46 ;
goto V_28;
}
for ( V_18 = 0 ; V_18 < V_8 -> V_10 ; V_18 ++ ) {
struct V_11 V_38 = { sizeof( L_14 ) , L_14 } ;
struct V_11 V_32 = { sizeof( V_8 -> V_32 [ V_18 ] ) , & V_8 -> V_32 [ V_18 ] } ;
V_16 = F_20 ( & V_15 -> V_23 . V_25 [ V_18 + 1 ] ,
& V_38 , & V_32 ) ;
if ( F_5 ( V_16 ) ) {
F_6 ( & V_5 -> V_20 , L_15 ) ;
break;
}
}
F_24 ( V_8 -> V_32 , V_8 -> V_10 , sizeof( * V_8 -> V_32 ) ,
F_21 , NULL ) ;
V_28:
F_8 ( V_15 ) ;
return V_16 ;
}
static int F_25 ( struct V_47 * V_48 )
{
int V_33 = 0 ;
struct V_1 * V_2 ;
struct V_7 * V_8 ;
struct V_4 * V_5 = F_26 ( & V_48 -> V_20 ) ;
char * V_49 ;
V_8 = F_23 ( & V_48 -> V_20 , sizeof( * V_8 ) , V_45 ) ;
if ( ! V_8 ) {
F_6 ( & V_5 -> V_20 , L_16 ) ;
return - V_46 ;
}
V_5 -> V_50 = V_8 ;
F_27 ( V_48 , V_8 ) ;
if ( F_17 ( V_5 ) ) {
if ( F_19 ( V_5 ) || F_22 ( V_5 ) )
goto V_51;
V_8 -> V_9 = true ;
} else {
V_33 = F_10 ( V_5 , NULL ) ;
if ( V_33 ) {
F_6 ( & V_5 -> V_20 , L_17 ) ;
goto V_51;
}
}
if ( ! strncmp ( V_48 -> V_49 , L_18 , strlen ( L_18 ) ) )
V_49 = L_19 ;
else
V_49 = F_28 ( V_5 ) ;
V_2 = F_29 ( V_49 , V_5 ,
& V_52 ) ;
if ( F_30 ( V_2 ) ) {
V_33 = F_31 ( V_2 ) ;
goto V_51;
}
F_7 ( & V_48 -> V_20 , L_20 , V_2 -> V_53 ) ;
V_8 -> V_2 = V_2 ;
V_33 = F_32 ( & V_48 -> V_20 . V_54 ,
& V_2 -> V_5 . V_54 ,
L_21 ) ;
if ( V_33 )
F_6 ( & V_48 -> V_20 , L_22 ) ;
V_33 = F_32 ( & V_2 -> V_5 . V_54 ,
& V_48 -> V_20 . V_54 ,
L_23 ) ;
if ( V_33 )
F_6 ( & V_48 -> V_20 , L_24 ) ;
V_51:
return V_33 ;
}
static int F_33 ( struct V_47 * V_48 )
{
struct V_7 * V_8 = F_34 ( V_48 ) ;
F_35 ( & V_48 -> V_20 . V_54 , L_21 ) ;
F_35 ( & V_8 -> V_2 -> V_5 . V_54 , L_23 ) ;
F_36 ( V_8 -> V_2 ) ;
return 0 ;
}
static int F_37 ( struct V_5 * V_20 )
{
struct V_7 * V_8 = F_38 ( V_20 ) ;
if ( V_8 -> V_9 )
return 0 ;
F_13 ( F_26 ( V_20 ) , V_35 ) ;
return V_55 ;
}
static int F_39 ( struct V_5 * V_20 )
{
int V_33 ;
struct V_7 * V_8 = F_38 ( V_20 ) ;
if ( V_8 -> V_9 )
return 0 ;
V_33 = F_10 ( F_26 ( V_20 ) , NULL ) ;
if ( V_33 )
F_6 ( V_20 , L_25 ) ;
return V_33 ;
}
