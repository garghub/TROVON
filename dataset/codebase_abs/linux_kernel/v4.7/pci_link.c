static T_1 F_1 ( struct V_1 * V_2 ,
void * V_3 )
{
struct V_4 * V_5 = V_3 ;
T_2 V_6 ;
switch ( V_2 -> type ) {
case V_7 :
case V_8 :
return V_9 ;
case V_10 :
{
struct V_11 * V_12 = & V_2 -> V_13 . V_14 ;
if ( ! V_12 || ! V_12 -> V_15 ) {
F_2 ( ( V_16 ,
L_1 ) ) ;
return V_9 ;
}
for ( V_6 = 0 ;
( V_6 < V_12 -> V_15
&& V_6 < V_17 ) ; V_6 ++ ) {
if ( ! V_12 -> V_18 [ V_6 ] ) {
F_3 (KERN_WARNING PREFIX
L_2 ,
p->interrupts[i]) ;
continue;
}
V_5 -> V_14 . V_19 [ V_6 ] = V_12 -> V_18 [ V_6 ] ;
V_5 -> V_14 . V_20 ++ ;
}
V_5 -> V_14 . V_21 = V_12 -> V_21 ;
V_5 -> V_14 . V_22 = V_12 -> V_22 ;
V_5 -> V_14 . V_23 = V_10 ;
break;
}
case V_24 :
{
struct V_25 * V_12 =
& V_2 -> V_13 . V_26 ;
if ( ! V_12 || ! V_12 -> V_15 ) {
F_3 (KERN_WARNING PREFIX
L_3 ) ;
return V_9 ;
}
for ( V_6 = 0 ;
( V_6 < V_12 -> V_15
&& V_6 < V_17 ) ; V_6 ++ ) {
if ( ! V_12 -> V_18 [ V_6 ] ) {
F_3 (KERN_WARNING PREFIX
L_2 ,
p->interrupts[i]) ;
continue;
}
V_5 -> V_14 . V_19 [ V_6 ] = V_12 -> V_18 [ V_6 ] ;
V_5 -> V_14 . V_20 ++ ;
}
V_5 -> V_14 . V_21 = V_12 -> V_21 ;
V_5 -> V_14 . V_22 = V_12 -> V_22 ;
V_5 -> V_14 . V_23 = V_24 ;
break;
}
default:
F_3 (KERN_ERR PREFIX L_4 ,
resource->type) ;
return V_9 ;
}
return V_27 ;
}
static int F_4 ( struct V_4 * V_5 )
{
T_1 V_28 ;
V_28 = F_5 ( V_5 -> V_29 -> V_30 , V_31 ,
F_1 , V_5 ) ;
if ( F_6 ( V_28 ) ) {
F_7 ( ( V_32 , V_28 , L_5 ) ) ;
return - V_33 ;
}
F_2 ( ( V_16 ,
L_6 ,
V_5 -> V_14 . V_20 ) ) ;
return 0 ;
}
static T_1 F_8 ( struct V_1 * V_2 ,
void * V_3 )
{
int * V_14 = V_3 ;
switch ( V_2 -> type ) {
case V_7 :
case V_8 :
return V_9 ;
case V_10 :
{
struct V_11 * V_12 = & V_2 -> V_13 . V_14 ;
if ( ! V_12 || ! V_12 -> V_15 ) {
F_2 ( ( V_16 ,
L_7 ) ) ;
return V_9 ;
}
* V_14 = V_12 -> V_18 [ 0 ] ;
break;
}
case V_24 :
{
struct V_25 * V_12 =
& V_2 -> V_13 . V_26 ;
if ( ! V_12 || ! V_12 -> V_15 ) {
F_3 (KERN_WARNING PREFIX
L_8 ) ;
return V_9 ;
}
* V_14 = V_12 -> V_18 [ 0 ] ;
break;
}
break;
default:
F_3 (KERN_ERR PREFIX L_9 ,
resource->type) ;
return V_9 ;
}
return V_27 ;
}
static int F_9 ( struct V_4 * V_5 )
{
int V_34 = 0 ;
T_1 V_28 ;
int V_14 = 0 ;
V_5 -> V_14 . V_35 = 0 ;
if ( V_36 ) {
V_34 = F_10 ( V_5 -> V_29 ) ;
if ( V_34 ) {
F_3 (KERN_ERR PREFIX L_10 ) ;
goto V_37;
}
if ( ! V_5 -> V_29 -> V_28 . V_38 ) {
F_2 ( ( V_16 , L_11 ) ) ;
return 0 ;
}
}
V_28 = F_5 ( V_5 -> V_29 -> V_30 , V_39 ,
F_8 , & V_14 ) ;
if ( F_6 ( V_28 ) ) {
F_7 ( ( V_32 , V_28 , L_12 ) ) ;
V_34 = - V_33 ;
goto V_37;
}
if ( V_36 && ! V_14 ) {
F_3 (KERN_ERR PREFIX L_13 ) ;
V_34 = - V_33 ;
}
V_5 -> V_14 . V_35 = V_14 ;
F_2 ( ( V_16 , L_14 , V_5 -> V_14 . V_35 ) ) ;
V_37:
return V_34 ;
}
static int F_11 ( struct V_4 * V_5 , int V_14 )
{
int V_34 ;
T_1 V_28 ;
struct {
struct V_1 V_40 ;
struct V_1 V_37 ;
} * V_2 ;
struct V_41 V_42 = { 0 , NULL } ;
if ( ! V_14 )
return - V_43 ;
V_2 = F_12 ( sizeof( * V_2 ) + 1 , F_13 () ? V_44 : V_45 ) ;
if ( ! V_2 )
return - V_46 ;
V_42 . V_47 = sizeof( * V_2 ) + 1 ;
V_42 . V_48 = V_2 ;
switch ( V_5 -> V_14 . V_23 ) {
case V_10 :
V_2 -> V_40 . type = V_10 ;
V_2 -> V_40 . V_47 = sizeof( struct V_1 ) ;
V_2 -> V_40 . V_13 . V_14 . V_21 = V_5 -> V_14 . V_21 ;
V_2 -> V_40 . V_13 . V_14 . V_22 =
V_5 -> V_14 . V_22 ;
if ( V_5 -> V_14 . V_21 == V_49 )
V_2 -> V_40 . V_13 . V_14 . V_50 =
V_51 ;
else
V_2 -> V_40 . V_13 . V_14 . V_50 = V_52 ;
V_2 -> V_40 . V_13 . V_14 . V_15 = 1 ;
V_2 -> V_40 . V_13 . V_14 . V_18 [ 0 ] = V_14 ;
break;
case V_24 :
V_2 -> V_40 . type = V_24 ;
V_2 -> V_40 . V_47 = sizeof( struct V_1 ) ;
V_2 -> V_40 . V_13 . V_26 . V_53 =
V_54 ;
V_2 -> V_40 . V_13 . V_26 . V_21 =
V_5 -> V_14 . V_21 ;
V_2 -> V_40 . V_13 . V_26 . V_22 =
V_5 -> V_14 . V_22 ;
if ( V_5 -> V_14 . V_21 == V_49 )
V_2 -> V_40 . V_13 . V_14 . V_50 =
V_51 ;
else
V_2 -> V_40 . V_13 . V_14 . V_50 = V_52 ;
V_2 -> V_40 . V_13 . V_26 . V_15 = 1 ;
V_2 -> V_40 . V_13 . V_26 . V_18 [ 0 ] = V_14 ;
break;
default:
F_3 (KERN_ERR PREFIX L_15 , link->irq.resource_type) ;
V_34 = - V_43 ;
goto V_37;
}
V_2 -> V_37 . type = V_8 ;
V_2 -> V_37 . V_47 = sizeof( struct V_1 ) ;
V_28 = F_14 ( V_5 -> V_29 -> V_30 , & V_42 ) ;
if ( F_6 ( V_28 ) ) {
F_7 ( ( V_32 , V_28 , L_16 ) ) ;
V_34 = - V_33 ;
goto V_37;
}
V_34 = F_10 ( V_5 -> V_29 ) ;
if ( V_34 ) {
F_3 (KERN_ERR PREFIX L_10 ) ;
goto V_37;
}
if ( ! V_5 -> V_29 -> V_28 . V_38 ) {
F_3 (KERN_WARNING PREFIX
L_17 ,
acpi_device_name(link->device),
acpi_device_bid(link->device)) ;
}
V_34 = F_9 ( V_5 ) ;
if ( V_34 ) {
goto V_37;
}
if ( V_5 -> V_14 . V_35 != V_14 ) {
F_3 (KERN_WARNING PREFIX
L_18 ,
acpi_device_name(link->device),
acpi_device_bid(link->device), link->irq.active, irq) ;
V_5 -> V_14 . V_35 = V_14 ;
}
F_2 ( ( V_16 , L_19 , V_5 -> V_14 . V_35 ) ) ;
V_37:
F_15 ( V_2 ) ;
return V_34 ;
}
static int F_16 ( int V_14 )
{
struct V_4 * V_5 ;
int V_55 = 0 ;
int V_6 ;
F_17 (link, &acpi_link_list, list) {
if ( V_5 -> V_14 . V_35 && V_5 -> V_14 . V_35 == V_14 )
V_55 += V_56 ;
for ( V_6 = 0 ; V_6 < V_5 -> V_14 . V_20 ; V_6 ++ )
if ( V_5 -> V_14 . V_19 [ V_6 ] == V_14 )
V_55 += V_57 /
V_5 -> V_14 . V_20 ;
}
return V_55 ;
}
static int F_18 ( int V_14 )
{
int V_55 = 0 ;
if ( V_14 == V_58 . V_59 ) {
T_2 type = F_19 ( V_14 ) & V_60 ;
if ( type != V_61 )
V_55 += V_62 ;
else
V_55 += V_56 ;
}
if ( V_14 < V_63 )
return V_55 + V_64 [ V_14 ] ;
V_55 += F_16 ( V_14 ) ;
return V_55 ;
}
int T_3 F_20 ( void )
{
struct V_4 * V_5 ;
int V_6 ;
F_17 (link, &acpi_link_list, list) {
if ( V_5 -> V_14 . V_20 ) {
int V_55 =
V_57 /
V_5 -> V_14 . V_20 ;
for ( V_6 = 0 ; V_6 < V_5 -> V_14 . V_20 ; V_6 ++ ) {
if ( V_5 -> V_14 . V_19 [ V_6 ] < V_63 )
V_64 [ V_5 -> V_14 .
V_19 [ V_6 ] ] +=
V_55 ;
}
} else if ( V_5 -> V_14 . V_35 &&
( V_5 -> V_14 . V_35 < V_63 ) ) {
V_64 [ V_5 -> V_14 . V_35 ] +=
V_57 ;
}
}
return 0 ;
}
static int F_21 ( struct V_4 * V_5 )
{
int V_14 ;
int V_6 ;
if ( V_5 -> V_14 . V_65 ) {
if ( V_5 -> V_66 == 0 )
F_11 ( V_5 , V_5 -> V_14 . V_35 ) ;
return 0 ;
}
for ( V_6 = 0 ; V_6 < V_5 -> V_14 . V_20 ; ++ V_6 ) {
if ( V_5 -> V_14 . V_35 == V_5 -> V_14 . V_19 [ V_6 ] )
break;
}
if ( V_6 == V_5 -> V_14 . V_20 ) {
if ( V_36 )
F_3 (KERN_WARNING PREFIX L_20
L_21 , link->irq.active) ;
V_5 -> V_14 . V_35 = 0 ;
}
if ( V_5 -> V_14 . V_35 )
V_14 = V_5 -> V_14 . V_35 ;
else
V_14 = V_5 -> V_14 . V_19 [ V_5 -> V_14 . V_20 - 1 ] ;
if ( V_67 || ! V_5 -> V_14 . V_35 ) {
for ( V_6 = ( V_5 -> V_14 . V_20 - 1 ) ; V_6 >= 0 ; V_6 -- ) {
if ( F_18 ( V_14 ) >
F_18 ( V_5 -> V_14 . V_19 [ V_6 ] ) )
V_14 = V_5 -> V_14 . V_19 [ V_6 ] ;
}
}
if ( F_18 ( V_14 ) >= V_62 ) {
F_3 (KERN_ERR PREFIX L_22
L_23 ,
acpi_device_name(link->device),
acpi_device_bid(link->device)) ;
return - V_33 ;
}
if ( F_11 ( V_5 , V_14 ) ) {
F_3 (KERN_ERR PREFIX L_24
L_23 ,
acpi_device_name(link->device),
acpi_device_bid(link->device)) ;
return - V_33 ;
} else {
F_3 (KERN_WARNING PREFIX L_25 ,
acpi_device_name(link->device),
acpi_device_bid(link->device), link->irq.active) ;
}
V_5 -> V_14 . V_65 = 1 ;
return 0 ;
}
int F_22 ( T_4 V_30 , int V_68 , int * V_21 ,
int * V_22 , char * * V_69 )
{
int V_34 ;
struct V_70 * V_29 ;
struct V_4 * V_5 ;
V_34 = F_23 ( V_30 , & V_29 ) ;
if ( V_34 ) {
F_3 (KERN_ERR PREFIX L_26 ) ;
return - 1 ;
}
V_5 = F_24 ( V_29 ) ;
if ( ! V_5 ) {
F_3 (KERN_ERR PREFIX L_27 ) ;
return - 1 ;
}
if ( V_68 ) {
F_3 (KERN_ERR PREFIX L_28 , index) ;
return - 1 ;
}
F_25 ( & V_71 ) ;
if ( F_21 ( V_5 ) ) {
F_26 ( & V_71 ) ;
return - 1 ;
}
if ( ! V_5 -> V_14 . V_35 ) {
F_26 ( & V_71 ) ;
F_3 (KERN_ERR PREFIX L_29 ) ;
return - 1 ;
}
V_5 -> V_66 ++ ;
F_26 ( & V_71 ) ;
if ( V_21 )
* V_21 = V_5 -> V_14 . V_21 ;
if ( V_22 )
* V_22 = V_5 -> V_14 . V_22 ;
if ( V_69 )
* V_69 = F_27 ( V_5 -> V_29 ) ;
F_2 ( ( V_16 ,
L_30 ,
F_27 ( V_5 -> V_29 ) ) ) ;
return ( V_5 -> V_14 . V_35 ) ;
}
int F_28 ( T_4 V_30 )
{
struct V_70 * V_29 ;
struct V_4 * V_5 ;
T_1 V_34 ;
V_34 = F_23 ( V_30 , & V_29 ) ;
if ( V_34 ) {
F_3 (KERN_ERR PREFIX L_26 ) ;
return - 1 ;
}
V_5 = F_24 ( V_29 ) ;
if ( ! V_5 ) {
F_3 (KERN_ERR PREFIX L_27 ) ;
return - 1 ;
}
F_25 ( & V_71 ) ;
if ( ! V_5 -> V_14 . V_65 ) {
F_26 ( & V_71 ) ;
F_3 (KERN_ERR PREFIX L_31 ) ;
return - 1 ;
}
#ifdef F_29
V_5 -> V_66 -- ;
#endif
F_2 ( ( V_16 ,
L_32 ,
F_27 ( V_5 -> V_29 ) ) ) ;
if ( V_5 -> V_66 == 0 )
F_30 ( V_5 -> V_29 -> V_30 , L_33 , NULL , NULL ) ;
F_26 ( & V_71 ) ;
return ( V_5 -> V_14 . V_35 ) ;
}
static int F_31 ( struct V_70 * V_29 ,
const struct V_72 * V_73 )
{
int V_34 ;
struct V_4 * V_5 ;
int V_6 ;
int V_74 = 0 ;
V_5 = F_12 ( sizeof( struct V_4 ) , V_45 ) ;
if ( ! V_5 )
return - V_46 ;
V_5 -> V_29 = V_29 ;
strcpy ( F_32 ( V_29 ) , V_75 ) ;
strcpy ( F_33 ( V_29 ) , V_76 ) ;
V_29 -> V_77 = V_5 ;
F_25 ( & V_71 ) ;
V_34 = F_4 ( V_5 ) ;
if ( V_34 )
goto V_37;
F_9 ( V_5 ) ;
F_3 (KERN_INFO PREFIX L_34 , acpi_device_name(device),
acpi_device_bid(device)) ;
for ( V_6 = 0 ; V_6 < V_5 -> V_14 . V_20 ; V_6 ++ ) {
if ( V_5 -> V_14 . V_35 == V_5 -> V_14 . V_19 [ V_6 ] ) {
F_3 ( V_78 L_35 , V_5 -> V_14 . V_19 [ V_6 ] ) ;
V_74 = 1 ;
} else
F_3 ( V_78 L_36 , V_5 -> V_14 . V_19 [ V_6 ] ) ;
}
F_3 ( V_78 L_37 ) ;
if ( ! V_74 )
F_3 ( V_78 L_35 , V_5 -> V_14 . V_35 ) ;
if ( ! V_5 -> V_29 -> V_28 . V_38 )
F_3 ( V_78 L_38 ) ;
F_3 ( V_78 L_39 ) ;
F_34 ( & V_5 -> V_79 , & V_80 ) ;
V_37:
F_30 ( V_29 -> V_30 , L_33 , NULL , NULL ) ;
F_26 ( & V_71 ) ;
if ( V_34 )
F_15 ( V_5 ) ;
return V_34 < 0 ? V_34 : 1 ;
}
static int F_35 ( struct V_4 * V_5 )
{
if ( V_5 -> V_66 && V_5 -> V_14 . V_35 && V_5 -> V_14 . V_65 )
return ( F_11 ( V_5 , V_5 -> V_14 . V_35 ) ) ;
return 0 ;
}
static void F_36 ( void )
{
struct V_4 * V_5 ;
F_17 (link, &acpi_link_list, list) {
F_35 ( V_5 ) ;
}
}
static void F_37 ( struct V_70 * V_29 )
{
struct V_4 * V_5 ;
V_5 = F_24 ( V_29 ) ;
F_25 ( & V_71 ) ;
F_38 ( & V_5 -> V_79 ) ;
F_26 ( & V_71 ) ;
F_15 ( V_5 ) ;
}
static int T_3 F_39 ( char * V_81 , int V_82 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < 16 ; V_6 ++ ) {
int V_83 ;
int V_14 ;
int V_84 ;
V_83 = F_40 ( & V_81 , & V_14 ) ;
if ( ! V_83 )
break;
if ( ( V_14 < 0 ) || ( V_14 >= V_63 ) )
continue;
if ( V_82 )
V_84 = F_18 ( V_14 ) +
V_85 ;
else
V_84 = 0 ;
V_64 [ V_14 ] = V_84 ;
if ( V_83 != 2 )
break;
}
return 1 ;
}
void F_41 ( int V_14 , int V_35 )
{
if ( ( V_14 >= 0 ) && ( V_14 < F_42 ( V_64 ) ) )
V_64 [ V_14 ] = F_18 ( V_14 ) +
( V_35 ? V_85 : V_56 ) ;
}
bool F_43 ( int V_14 )
{
return V_14 >= 0 && ( V_14 >= F_42 ( V_64 ) ||
F_18 ( V_14 ) < V_62 ) ;
}
static int T_3 F_44 ( char * V_81 )
{
return F_39 ( V_81 , 1 ) ;
}
static int T_3 F_45 ( char * V_81 )
{
return F_39 ( V_81 , 0 ) ;
}
static int T_3 F_46 ( char * V_81 )
{
V_67 = 0 ;
return 1 ;
}
static int T_3 F_47 ( char * V_81 )
{
V_67 = 1 ;
return 1 ;
}
void T_3 F_48 ( void )
{
if ( V_86 )
return;
if ( V_67 == - 1 ) {
if ( V_87 == V_88 )
V_67 = 1 ;
else
V_67 = 0 ;
}
F_49 ( & V_89 ) ;
F_50 ( & V_90 ) ;
}
