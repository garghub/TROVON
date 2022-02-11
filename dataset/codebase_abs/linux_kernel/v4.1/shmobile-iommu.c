static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static int F_3 ( struct V_5 * V_6 ,
struct V_7 * V_8 , T_1 V_9 )
{
V_6 -> V_6 = F_4 ( V_8 , V_10 ) ;
if ( ! V_6 -> V_6 )
return - V_11 ;
V_6 -> V_12 = F_5 ( NULL , V_6 -> V_6 , V_9 ,
V_13 ) ;
return 0 ;
}
static void F_6 ( struct V_5 * V_6 ,
struct V_7 * V_8 , T_1 V_9 )
{
F_7 ( NULL , V_6 -> V_12 , V_9 , V_13 ) ;
F_8 ( V_8 , V_6 -> V_6 ) ;
}
static T_2 F_9 ( struct V_5 * V_6 ,
unsigned int V_14 )
{
return V_6 -> V_6 [ V_14 ] ;
}
static void F_10 ( struct V_5 * V_6 ,
unsigned int V_14 , unsigned int V_15 , T_2 V_16 )
{
unsigned int V_17 ;
for ( V_17 = 0 ; V_17 < V_15 ; V_17 ++ )
V_6 -> V_6 [ V_14 + V_17 ] = V_16 ;
F_11 ( NULL , V_6 -> V_12 + V_14 * sizeof( V_16 ) ,
sizeof( V_16 ) * V_15 , V_13 ) ;
}
static struct V_2 * F_12 ( unsigned type )
{
struct V_1 * V_18 ;
int V_17 , V_19 ;
if ( type != V_20 )
return NULL ;
V_18 = F_13 ( sizeof( * V_18 ) , V_21 ) ;
if ( ! V_18 )
return NULL ;
V_19 = F_3 ( & V_18 -> V_22 , V_23 , V_24 ) ;
if ( V_19 < 0 ) {
F_14 ( V_18 ) ;
return NULL ;
}
for ( V_17 = 0 ; V_17 < V_25 ; V_17 ++ )
V_18 -> V_26 [ V_17 ] . V_6 = NULL ;
F_15 ( & V_18 -> V_27 ) ;
F_15 ( & V_18 -> V_28 ) ;
F_16 ( & V_18 -> V_29 ) ;
return & V_18 -> V_4 ;
}
static void F_17 ( struct V_2 * V_4 )
{
struct V_1 * V_18 = F_1 ( V_4 ) ;
int V_17 ;
for ( V_17 = 0 ; V_17 < V_25 ; V_17 ++ ) {
if ( V_18 -> V_26 [ V_17 ] . V_6 )
F_6 ( & V_18 -> V_26 [ V_17 ] , V_30 , V_31 ) ;
}
F_6 ( & V_18 -> V_22 , V_23 , V_24 ) ;
F_14 ( V_18 ) ;
}
static int F_18 ( struct V_2 * V_4 ,
struct V_32 * V_33 )
{
struct V_34 * V_35 = V_33 -> V_35 . V_36 ;
struct V_1 * V_18 = F_1 ( V_4 ) ;
int V_19 = - V_37 ;
if ( ! V_35 )
return - V_38 ;
F_19 ( & V_18 -> V_28 ) ;
F_19 ( & V_35 -> V_39 ) ;
if ( V_35 -> V_40 != V_18 ) {
if ( V_35 -> V_40 )
goto V_41;
F_20 ( V_35 -> V_42 , V_18 -> V_22 . V_12 , V_24 ,
0 ) ;
F_21 ( V_35 -> V_42 ) ;
V_35 -> V_40 = V_18 ;
V_35 -> V_43 = 0 ;
F_22 ( & V_35 -> V_29 , & V_18 -> V_29 ) ;
}
V_35 -> V_43 ++ ;
V_19 = 0 ;
V_41:
F_23 ( & V_35 -> V_39 ) ;
F_23 ( & V_18 -> V_28 ) ;
return V_19 ;
}
static void F_24 ( struct V_2 * V_4 ,
struct V_32 * V_33 )
{
struct V_34 * V_35 = V_33 -> V_35 . V_36 ;
struct V_1 * V_18 = F_1 ( V_4 ) ;
if ( ! V_35 )
return;
F_19 ( & V_18 -> V_28 ) ;
F_19 ( & V_35 -> V_39 ) ;
V_35 -> V_43 -- ;
if ( ! V_35 -> V_43 ) {
F_20 ( V_35 -> V_42 , 0 , 0 , 0 ) ;
F_21 ( V_35 -> V_42 ) ;
V_35 -> V_40 = NULL ;
F_25 ( & V_35 -> V_29 ) ;
}
F_23 ( & V_35 -> V_39 ) ;
F_23 ( & V_18 -> V_28 ) ;
}
static void F_26 ( struct V_1 * V_18 )
{
struct V_34 * V_35 ;
F_19 ( & V_18 -> V_28 ) ;
F_27 (archdata, &sh_domain->attached_list, attached_list)
F_21 ( V_35 -> V_42 ) ;
F_23 ( & V_18 -> V_28 ) ;
}
static int F_28 ( struct V_1 * V_18 ,
unsigned int V_44 )
{
int V_19 ;
if ( ! V_18 -> V_26 [ V_44 ] . V_6 ) {
V_19 = F_3 ( & V_18 -> V_26 [ V_44 ] , V_30 , V_31 ) ;
if ( V_19 < 0 )
return V_19 ;
}
F_10 ( & V_18 -> V_22 , V_44 , 1 ,
V_18 -> V_26 [ V_44 ] . V_12 | 0x1 ) ;
return 0 ;
}
static void F_29 ( struct V_5 * V_26 )
{
if ( V_26 -> V_6 )
F_6 ( V_26 , V_30 , V_31 ) ;
}
static void F_30 ( struct V_1 * V_18 ,
unsigned int V_44 ,
struct V_5 * V_26 )
{
F_10 ( & V_18 -> V_22 , V_44 , 1 , 0 ) ;
if ( V_18 -> V_26 [ V_44 ] . V_6 ) {
* V_26 = V_18 -> V_26 [ V_44 ] ;
V_18 -> V_26 [ V_44 ] . V_6 = NULL ;
}
}
static int F_31 ( struct V_2 * V_4 , unsigned long V_45 ,
T_3 V_46 , T_1 V_9 , int V_47 )
{
struct V_5 V_26 = { . V_6 = NULL } ;
struct V_1 * V_18 = F_1 ( V_4 ) ;
unsigned int V_44 , V_48 ;
int V_19 ;
V_44 = V_45 >> 20 ;
switch ( V_9 ) {
case V_49 :
V_48 = ( V_45 >> 12 ) & 0xff ;
F_19 ( & V_18 -> V_27 ) ;
V_19 = F_28 ( V_18 , V_44 ) ;
if ( ! V_19 )
F_10 ( & V_18 -> V_26 [ V_44 ] , V_48 , 1 ,
V_46 | 0xff2 ) ;
F_23 ( & V_18 -> V_27 ) ;
break;
case V_50 :
V_48 = ( V_45 >> 12 ) & 0xf0 ;
F_19 ( & V_18 -> V_27 ) ;
V_19 = F_28 ( V_18 , V_44 ) ;
if ( ! V_19 )
F_10 ( & V_18 -> V_26 [ V_44 ] , V_48 , 0x10 ,
V_46 | 0xff1 ) ;
F_23 ( & V_18 -> V_27 ) ;
break;
case V_51 :
F_19 ( & V_18 -> V_27 ) ;
F_30 ( V_18 , V_44 , & V_26 ) ;
F_10 ( & V_18 -> V_22 , V_44 , 1 , V_46 | 0xc02 ) ;
F_23 ( & V_18 -> V_27 ) ;
V_19 = 0 ;
break;
default:
V_19 = - V_52 ;
}
if ( ! V_19 )
F_26 ( V_18 ) ;
F_29 ( & V_26 ) ;
return V_19 ;
}
static T_1 F_32 ( struct V_2 * V_4 ,
unsigned long V_45 , T_1 V_9 )
{
struct V_5 V_26 = { . V_6 = NULL } ;
struct V_1 * V_18 = F_1 ( V_4 ) ;
unsigned int V_44 , V_48 ;
T_2 V_53 = 0 ;
T_1 V_19 = 0 ;
V_44 = V_45 >> 20 ;
if ( ! ( V_45 & 0xfffff ) && V_9 >= V_51 ) {
F_19 ( & V_18 -> V_27 ) ;
F_30 ( V_18 , V_44 , & V_26 ) ;
F_23 ( & V_18 -> V_27 ) ;
V_19 = V_51 ;
goto V_54;
}
V_48 = ( V_45 >> 12 ) & 0xff ;
F_19 ( & V_18 -> V_27 ) ;
if ( V_18 -> V_26 [ V_44 ] . V_6 )
V_53 = F_9 ( & V_18 -> V_26 [ V_44 ] , V_48 ) ;
switch ( V_53 & 3 ) {
case 1 :
if ( V_48 & 0xf )
break;
F_10 ( & V_18 -> V_26 [ V_44 ] , V_48 , 0x10 , 0 ) ;
V_19 = V_50 ;
break;
case 2 :
F_10 ( & V_18 -> V_26 [ V_44 ] , V_48 , 1 , 0 ) ;
V_19 = V_49 ;
break;
}
F_23 ( & V_18 -> V_27 ) ;
V_54:
if ( V_19 )
F_26 ( V_18 ) ;
F_29 ( & V_26 ) ;
return V_19 ;
}
static T_3 F_33 ( struct V_2 * V_4 ,
T_4 V_45 )
{
struct V_1 * V_18 = F_1 ( V_4 ) ;
T_2 V_55 = 0 , V_53 = 0 ;
unsigned int V_44 , V_48 ;
V_44 = V_45 >> 20 ;
V_48 = ( V_45 >> 12 ) & 0xff ;
F_19 ( & V_18 -> V_27 ) ;
if ( V_18 -> V_26 [ V_44 ] . V_6 )
V_53 = F_9 ( & V_18 -> V_26 [ V_44 ] , V_48 ) ;
else
V_55 = F_9 ( & V_18 -> V_22 , V_44 ) ;
F_23 ( & V_18 -> V_27 ) ;
switch ( V_53 & 3 ) {
case 1 :
return ( V_53 & ~ 0xffff ) | ( V_45 & 0xffff ) ;
case 2 :
return ( V_53 & ~ 0xfff ) | ( V_45 & 0xfff ) ;
default:
if ( ( V_55 & 3 ) == 2 )
return ( V_55 & ~ 0xfffff ) | ( V_45 & 0xfffff ) ;
return 0 ;
}
}
static int F_34 ( struct V_56 * V_42 , const char * V_57 )
{
unsigned int V_17 , V_58 = V_42 -> V_59 ;
for ( V_17 = 0 ; V_17 < V_58 ; V_17 ++ ) {
if ( strcmp ( V_42 -> V_60 [ V_17 ] , V_57 ) == 0 )
return 1 ;
}
return 0 ;
}
static int F_35 ( struct V_32 * V_33 )
{
struct V_34 * V_35 = V_61 ;
struct V_62 * V_63 ;
if ( ! F_34 ( V_35 -> V_42 , V_57 ( V_33 ) ) )
return 0 ;
V_63 = V_35 -> V_64 ;
if ( ! V_63 ) {
V_63 = F_36 ( & V_65 , 0 ,
V_25 << 20 ) ;
if ( F_37 ( V_63 ) )
return F_38 ( V_63 ) ;
V_35 -> V_64 = V_63 ;
}
V_33 -> V_35 . V_36 = V_35 ;
if ( F_39 ( V_33 , V_63 ) )
F_40 ( L_1 ) ;
return 0 ;
}
int F_41 ( struct V_56 * V_42 )
{
static struct V_34 * V_35 ;
V_23 = F_42 ( L_2 , V_24 ,
V_66 , V_67 , NULL ) ;
if ( ! V_23 )
return - V_11 ;
V_30 = F_42 ( L_3 , V_31 ,
V_68 , V_67 , NULL ) ;
if ( ! V_30 ) {
F_43 ( V_23 ) ;
return - V_11 ;
}
V_35 = F_13 ( sizeof( * V_35 ) , V_21 ) ;
if ( ! V_35 ) {
F_43 ( V_23 ) ;
F_43 ( V_30 ) ;
return - V_11 ;
}
F_15 ( & V_35 -> V_39 ) ;
V_35 -> V_42 = V_42 ;
V_61 = V_35 ;
F_44 ( & V_65 , & V_69 ) ;
return 0 ;
}
