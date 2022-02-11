static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
return sprintf ( V_5 , L_1 , V_6 ) ;
}
static unsigned long F_2 ( T_2 V_7 , T_2 V_8 ,
T_3 V_9 , T_4 V_10 , T_2 V_11 , T_4 V_12 ,
T_5 * V_13 )
{
unsigned long V_14 ;
T_6 V_15 ;
T_5 V_16 ;
struct {
struct V_17 V_18 ;
T_7 V_19 [ V_20 ] ;
} V_21 V_22 ( sizeof( V_23 ) ) V_24 = {
. V_18 = {
. V_25 = F_3 ( V_7 ) ,
. V_8 = F_3 ( V_8 ) ,
. V_9 = F_4 ( V_9 ) ,
. V_26 = V_10 ,
}
} ;
V_14 = F_5 ( V_27 ,
F_6 ( & V_24 ) , sizeof( V_24 ) ) ;
if ( V_14 ) {
F_7 ( L_2 , V_14 ) ;
return V_14 ;
}
V_16 = 0 ;
for ( V_15 = V_11 ; V_15 < V_11 + V_12 ; V_15 ++ )
V_16 |= V_24 . V_19 [ V_15 ] << ( V_15 - V_11 ) ;
* V_13 = V_16 ;
return V_14 ;
}
static T_5 F_8 ( struct V_28 * V_29 )
{
T_5 V_16 ;
unsigned long V_14 = F_2 ( F_9 ( V_29 ) ,
F_10 ( V_29 ) ,
F_11 ( V_29 ) ,
F_12 ( V_29 ) ,
F_13 ( V_29 ) ,
F_14 ( V_29 ) ,
& V_16 ) ;
if ( V_14 )
return 0 ;
return V_16 ;
}
static void F_15 ( struct V_28 * V_29 )
{
T_8 V_30 ;
T_5 V_31 = F_8 ( V_29 ) ;
V_30 = F_16 ( & V_29 -> V_32 . V_33 , V_31 ) ;
F_17 ( V_31 - V_30 , & V_29 -> V_16 ) ;
}
static void F_18 ( struct V_28 * V_29 , int V_34 )
{
F_19 ( & V_29 -> V_32 . V_33 , F_8 ( V_29 ) ) ;
}
static void F_20 ( struct V_28 * V_29 , int V_34 )
{
F_15 ( V_29 ) ;
}
static int F_21 ( struct V_28 * V_29 , int V_34 )
{
if ( V_34 & V_35 )
F_18 ( V_29 , V_34 ) ;
return 0 ;
}
static int F_22 ( struct V_28 * V_29 )
{
T_5 V_16 ;
T_4 V_12 ;
if ( V_29 -> V_4 . type != V_29 -> V_36 -> type )
return - V_37 ;
if ( V_29 -> V_4 . V_38 ) {
F_7 ( L_3 ) ;
return - V_39 ;
}
if ( V_29 -> V_4 . V_40 ||
V_29 -> V_4 . V_41 ||
V_29 -> V_4 . V_42 ||
V_29 -> V_4 . V_43 ||
V_29 -> V_4 . V_44 ||
V_29 -> V_4 . V_45 )
return - V_39 ;
if ( F_23 ( V_29 ) )
return - V_46 ;
V_12 = F_14 ( V_29 ) ;
if ( V_12 < 1 || V_12 > 8 ) {
F_7 ( L_4 ) ;
return - V_39 ;
}
if ( ( F_13 ( V_29 ) + V_12 ) > V_20 ) {
F_7 ( L_5 ,
( T_6 ) F_13 ( V_29 ) + V_12 ,
V_20 ) ;
return - V_39 ;
}
if ( F_2 ( F_9 ( V_29 ) ,
F_10 ( V_29 ) ,
F_11 ( V_29 ) ,
F_12 ( V_29 ) ,
F_13 ( V_29 ) ,
V_12 ,
& V_16 ) ) {
F_7 ( L_6 ) ;
return - V_39 ;
}
return 0 ;
}
static int F_24 ( void )
{
int V_47 ;
unsigned long V_48 ;
struct V_49 V_50 ;
if ( ! F_25 ( V_51 ) ) {
F_26 ( L_7 ) ;
return - V_52 ;
}
V_48 = F_27 ( & V_50 ) ;
if ( V_48 ) {
F_26 ( L_8 ,
V_48 ) ;
return - V_52 ;
}
V_53 . V_54 |= V_55 ;
V_47 = F_28 ( & V_53 , V_53 . V_56 , - 1 ) ;
if ( V_47 )
return V_47 ;
return 0 ;
}
