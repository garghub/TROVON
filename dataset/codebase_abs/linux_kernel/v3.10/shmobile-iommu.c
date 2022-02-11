static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_1 V_5 )
{
V_2 -> V_2 = F_2 ( V_4 , V_6 ) ;
if ( ! V_2 -> V_2 )
return - V_7 ;
V_2 -> V_8 = F_3 ( NULL , V_2 -> V_2 , V_5 ,
V_9 ) ;
return 0 ;
}
static void F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_1 V_5 )
{
F_5 ( NULL , V_2 -> V_8 , V_5 , V_9 ) ;
F_6 ( V_4 , V_2 -> V_2 ) ;
}
static T_2 F_7 ( struct V_1 * V_2 ,
unsigned int V_10 )
{
return V_2 -> V_2 [ V_10 ] ;
}
static void F_8 ( struct V_1 * V_2 ,
unsigned int V_10 , unsigned int V_11 , T_2 V_12 )
{
unsigned int V_13 ;
for ( V_13 = 0 ; V_13 < V_11 ; V_13 ++ )
V_2 -> V_2 [ V_10 + V_13 ] = V_12 ;
F_9 ( NULL , V_2 -> V_8 + V_10 * sizeof( V_12 ) ,
sizeof( V_12 ) * V_11 , V_9 ) ;
}
static int F_10 ( struct V_14 * V_15 )
{
struct V_16 * V_17 ;
int V_13 , V_18 ;
V_17 = F_11 ( sizeof( * V_17 ) , V_19 ) ;
if ( ! V_17 )
return - V_7 ;
V_18 = F_1 ( & V_17 -> V_20 , V_21 , V_22 ) ;
if ( V_18 < 0 ) {
F_12 ( V_17 ) ;
return V_18 ;
}
for ( V_13 = 0 ; V_13 < V_23 ; V_13 ++ )
V_17 -> V_24 [ V_13 ] . V_2 = NULL ;
F_13 ( & V_17 -> V_25 ) ;
F_13 ( & V_17 -> V_26 ) ;
F_14 ( & V_17 -> V_27 ) ;
V_15 -> V_28 = V_17 ;
return 0 ;
}
static void F_15 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = V_15 -> V_28 ;
int V_13 ;
for ( V_13 = 0 ; V_13 < V_23 ; V_13 ++ ) {
if ( V_17 -> V_24 [ V_13 ] . V_2 )
F_4 ( & V_17 -> V_24 [ V_13 ] , V_29 , V_30 ) ;
}
F_4 ( & V_17 -> V_20 , V_21 , V_22 ) ;
F_12 ( V_17 ) ;
V_15 -> V_28 = NULL ;
}
static int F_16 ( struct V_14 * V_15 ,
struct V_31 * V_32 )
{
struct V_33 * V_34 = V_32 -> V_34 . V_35 ;
struct V_16 * V_17 = V_15 -> V_28 ;
int V_18 = - V_36 ;
if ( ! V_34 )
return - V_37 ;
F_17 ( & V_17 -> V_26 ) ;
F_17 ( & V_34 -> V_38 ) ;
if ( V_34 -> V_39 != V_17 ) {
if ( V_34 -> V_39 )
goto V_40;
F_18 ( V_34 -> V_41 , V_17 -> V_20 . V_8 , V_22 ,
0 ) ;
F_19 ( V_34 -> V_41 ) ;
V_34 -> V_39 = V_17 ;
V_34 -> V_42 = 0 ;
F_20 ( & V_34 -> V_27 , & V_17 -> V_27 ) ;
}
V_34 -> V_42 ++ ;
V_18 = 0 ;
V_40:
F_21 ( & V_34 -> V_38 ) ;
F_21 ( & V_17 -> V_26 ) ;
return V_18 ;
}
static void F_22 ( struct V_14 * V_15 ,
struct V_31 * V_32 )
{
struct V_33 * V_34 = V_32 -> V_34 . V_35 ;
struct V_16 * V_17 = V_15 -> V_28 ;
if ( ! V_34 )
return;
F_17 ( & V_17 -> V_26 ) ;
F_17 ( & V_34 -> V_38 ) ;
V_34 -> V_42 -- ;
if ( ! V_34 -> V_42 ) {
F_18 ( V_34 -> V_41 , 0 , 0 , 0 ) ;
F_19 ( V_34 -> V_41 ) ;
V_34 -> V_39 = NULL ;
F_23 ( & V_34 -> V_27 ) ;
}
F_21 ( & V_34 -> V_38 ) ;
F_21 ( & V_17 -> V_26 ) ;
}
static void F_24 ( struct V_16 * V_17 )
{
struct V_33 * V_34 ;
F_17 ( & V_17 -> V_26 ) ;
F_25 (archdata, &sh_domain->attached_list, attached_list)
F_19 ( V_34 -> V_41 ) ;
F_21 ( & V_17 -> V_26 ) ;
}
static int F_26 ( struct V_16 * V_17 ,
unsigned int V_43 )
{
int V_18 ;
if ( ! V_17 -> V_24 [ V_43 ] . V_2 ) {
V_18 = F_1 ( & V_17 -> V_24 [ V_43 ] , V_29 , V_30 ) ;
if ( V_18 < 0 )
return V_18 ;
}
F_8 ( & V_17 -> V_20 , V_43 , 1 ,
V_17 -> V_24 [ V_43 ] . V_8 | 0x1 ) ;
return 0 ;
}
static void F_27 ( struct V_1 * V_24 )
{
if ( V_24 -> V_2 )
F_4 ( V_24 , V_29 , V_30 ) ;
}
static void F_28 ( struct V_16 * V_17 ,
unsigned int V_43 ,
struct V_1 * V_24 )
{
F_8 ( & V_17 -> V_20 , V_43 , 1 , 0 ) ;
if ( V_17 -> V_24 [ V_43 ] . V_2 ) {
* V_24 = V_17 -> V_24 [ V_43 ] ;
V_17 -> V_24 [ V_43 ] . V_2 = NULL ;
}
}
static int F_29 ( struct V_14 * V_15 , unsigned long V_44 ,
T_3 V_45 , T_1 V_5 , int V_46 )
{
struct V_1 V_24 = { . V_2 = NULL } ;
struct V_16 * V_17 = V_15 -> V_28 ;
unsigned int V_43 , V_47 ;
int V_18 ;
V_43 = V_44 >> 20 ;
switch ( V_5 ) {
case V_48 :
V_47 = ( V_44 >> 12 ) & 0xff ;
F_17 ( & V_17 -> V_25 ) ;
V_18 = F_26 ( V_17 , V_43 ) ;
if ( ! V_18 )
F_8 ( & V_17 -> V_24 [ V_43 ] , V_47 , 1 ,
V_45 | 0xff2 ) ;
F_21 ( & V_17 -> V_25 ) ;
break;
case V_49 :
V_47 = ( V_44 >> 12 ) & 0xf0 ;
F_17 ( & V_17 -> V_25 ) ;
V_18 = F_26 ( V_17 , V_43 ) ;
if ( ! V_18 )
F_8 ( & V_17 -> V_24 [ V_43 ] , V_47 , 0x10 ,
V_45 | 0xff1 ) ;
F_21 ( & V_17 -> V_25 ) ;
break;
case V_50 :
F_17 ( & V_17 -> V_25 ) ;
F_28 ( V_17 , V_43 , & V_24 ) ;
F_8 ( & V_17 -> V_20 , V_43 , 1 , V_45 | 0xc02 ) ;
F_21 ( & V_17 -> V_25 ) ;
V_18 = 0 ;
break;
default:
V_18 = - V_51 ;
}
if ( ! V_18 )
F_24 ( V_17 ) ;
F_27 ( & V_24 ) ;
return V_18 ;
}
static T_1 F_30 ( struct V_14 * V_15 ,
unsigned long V_44 , T_1 V_5 )
{
struct V_1 V_24 = { . V_2 = NULL } ;
struct V_16 * V_17 = V_15 -> V_28 ;
unsigned int V_43 , V_47 ;
T_2 V_52 = 0 ;
T_1 V_18 = 0 ;
V_43 = V_44 >> 20 ;
if ( ! ( V_44 & 0xfffff ) && V_5 >= V_50 ) {
F_17 ( & V_17 -> V_25 ) ;
F_28 ( V_17 , V_43 , & V_24 ) ;
F_21 ( & V_17 -> V_25 ) ;
V_18 = V_50 ;
goto V_53;
}
V_47 = ( V_44 >> 12 ) & 0xff ;
F_17 ( & V_17 -> V_25 ) ;
if ( V_17 -> V_24 [ V_43 ] . V_2 )
V_52 = F_7 ( & V_17 -> V_24 [ V_43 ] , V_47 ) ;
switch ( V_52 & 3 ) {
case 1 :
if ( V_47 & 0xf )
break;
F_8 ( & V_17 -> V_24 [ V_43 ] , V_47 , 0x10 , 0 ) ;
V_18 = V_49 ;
break;
case 2 :
F_8 ( & V_17 -> V_24 [ V_43 ] , V_47 , 1 , 0 ) ;
V_18 = V_48 ;
break;
}
F_21 ( & V_17 -> V_25 ) ;
V_53:
if ( V_18 )
F_24 ( V_17 ) ;
F_27 ( & V_24 ) ;
return V_18 ;
}
static T_3 F_31 ( struct V_14 * V_15 ,
T_4 V_44 )
{
struct V_16 * V_17 = V_15 -> V_28 ;
T_2 V_54 = 0 , V_52 = 0 ;
unsigned int V_43 , V_47 ;
V_43 = V_44 >> 20 ;
V_47 = ( V_44 >> 12 ) & 0xff ;
F_17 ( & V_17 -> V_25 ) ;
if ( V_17 -> V_24 [ V_43 ] . V_2 )
V_52 = F_7 ( & V_17 -> V_24 [ V_43 ] , V_47 ) ;
else
V_54 = F_7 ( & V_17 -> V_20 , V_43 ) ;
F_21 ( & V_17 -> V_25 ) ;
switch ( V_52 & 3 ) {
case 1 :
return ( V_52 & ~ 0xffff ) | ( V_44 & 0xffff ) ;
case 2 :
return ( V_52 & ~ 0xfff ) | ( V_44 & 0xfff ) ;
default:
if ( ( V_54 & 3 ) == 2 )
return ( V_54 & ~ 0xfffff ) | ( V_44 & 0xfffff ) ;
return 0 ;
}
}
static int F_32 ( struct V_55 * V_41 , const char * V_56 )
{
unsigned int V_13 , V_57 = V_41 -> V_58 ;
for ( V_13 = 0 ; V_13 < V_57 ; V_13 ++ ) {
if ( strcmp ( V_41 -> V_59 [ V_13 ] , V_56 ) == 0 )
return 1 ;
}
return 0 ;
}
static int F_33 ( struct V_31 * V_32 )
{
struct V_33 * V_34 = V_60 ;
struct V_61 * V_62 ;
if ( ! F_32 ( V_34 -> V_41 , V_56 ( V_32 ) ) )
return 0 ;
V_62 = V_34 -> V_63 ;
if ( ! V_62 ) {
V_62 = F_34 ( & V_64 , 0 ,
V_23 << 20 , 0 ) ;
if ( F_35 ( V_62 ) )
return F_36 ( V_62 ) ;
V_34 -> V_63 = V_62 ;
}
V_32 -> V_34 . V_35 = V_34 ;
if ( F_37 ( V_32 , V_62 ) )
F_38 ( L_1 ) ;
return 0 ;
}
int F_39 ( struct V_55 * V_41 )
{
static struct V_33 * V_34 ;
V_21 = F_40 ( L_2 , V_22 ,
V_65 , V_66 , NULL ) ;
if ( ! V_21 )
return - V_7 ;
V_29 = F_40 ( L_3 , V_30 ,
V_67 , V_66 , NULL ) ;
if ( ! V_29 ) {
F_41 ( V_21 ) ;
return - V_7 ;
}
V_34 = F_11 ( sizeof( * V_34 ) , V_19 ) ;
if ( ! V_34 ) {
F_41 ( V_21 ) ;
F_41 ( V_29 ) ;
return - V_7 ;
}
F_13 ( & V_34 -> V_38 ) ;
V_34 -> V_39 = NULL ;
V_34 -> V_41 = V_41 ;
V_60 = V_34 ;
F_42 ( & V_64 , & V_68 ) ;
return 0 ;
}
