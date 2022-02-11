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
struct V_17 * V_18 ;
V_18 = ( void * ) F_3 ( V_19 ) ;
memset ( V_18 , 0 , V_20 ) ;
V_18 -> V_21 . V_22 = F_4 ( V_7 ) ;
V_18 -> V_21 . V_8 = F_4 ( V_8 ) ;
V_18 -> V_21 . V_9 = F_5 ( V_9 ) ;
V_18 -> V_21 . V_23 = V_10 ;
V_14 = F_6 ( V_24 ,
F_7 ( V_18 ) , V_20 ) ;
if ( V_14 ) {
F_8 ( L_2 , V_14 ) ;
goto V_25;
}
V_16 = 0 ;
for ( V_15 = V_11 ; V_15 < V_11 + V_12 ; V_15 ++ )
V_16 |= V_18 -> V_26 [ V_15 ] << ( V_15 - V_11 ) ;
* V_13 = V_16 ;
V_25:
F_9 ( V_19 ) ;
return V_14 ;
}
static T_5 F_10 ( struct V_27 * V_28 )
{
T_5 V_16 ;
unsigned long V_14 = F_2 ( F_11 ( V_28 ) ,
F_12 ( V_28 ) ,
F_13 ( V_28 ) ,
F_14 ( V_28 ) ,
F_15 ( V_28 ) ,
F_16 ( V_28 ) ,
& V_16 ) ;
if ( V_14 )
return 0 ;
return V_16 ;
}
static void F_17 ( struct V_27 * V_28 )
{
T_7 V_29 ;
T_5 V_30 = F_10 ( V_28 ) ;
V_29 = F_18 ( & V_28 -> V_31 . V_32 , V_30 ) ;
F_19 ( V_30 - V_29 , & V_28 -> V_16 ) ;
}
static void F_20 ( struct V_27 * V_28 , int V_33 )
{
F_21 ( & V_28 -> V_31 . V_32 , F_10 ( V_28 ) ) ;
}
static void F_22 ( struct V_27 * V_28 , int V_33 )
{
F_17 ( V_28 ) ;
}
static int F_23 ( struct V_27 * V_28 , int V_33 )
{
if ( V_33 & V_34 )
F_20 ( V_28 , V_33 ) ;
return 0 ;
}
static int F_24 ( struct V_27 * V_28 )
{
T_5 V_16 ;
T_4 V_12 ;
if ( V_28 -> V_4 . type != V_28 -> V_35 -> type )
return - V_36 ;
if ( V_28 -> V_4 . V_37 ) {
F_8 ( L_3 ) ;
return - V_38 ;
}
if ( V_28 -> V_4 . V_39 ||
V_28 -> V_4 . V_40 ||
V_28 -> V_4 . V_41 ||
V_28 -> V_4 . V_42 ||
V_28 -> V_4 . V_43 ||
V_28 -> V_4 . V_44 )
return - V_38 ;
if ( F_25 ( V_28 ) )
return - V_45 ;
V_12 = F_16 ( V_28 ) ;
if ( V_12 < 1 || V_12 > 8 ) {
F_8 ( L_4 ) ;
return - V_38 ;
}
if ( ( F_15 ( V_28 ) + V_12 ) > V_46 ) {
F_8 ( L_5 ,
( T_6 ) F_15 ( V_28 ) + V_12 ,
V_46 ) ;
return - V_38 ;
}
if ( F_2 ( F_11 ( V_28 ) ,
F_12 ( V_28 ) ,
F_13 ( V_28 ) ,
F_14 ( V_28 ) ,
F_15 ( V_28 ) ,
V_12 ,
& V_16 ) ) {
F_8 ( L_6 ) ;
return - V_38 ;
}
return 0 ;
}
static int F_26 ( void )
{
int V_47 ;
unsigned long V_48 ;
struct V_49 V_50 ;
F_27 () ;
if ( ! F_28 ( V_51 ) ) {
F_29 ( L_7 ) ;
return - V_52 ;
}
V_48 = F_30 ( & V_50 ) ;
if ( V_48 ) {
F_29 ( L_8 ,
V_48 ) ;
return - V_52 ;
}
V_53 . V_54 |= V_55 ;
V_47 = F_31 ( & V_53 , V_53 . V_56 , - 1 ) ;
if ( V_47 )
return V_47 ;
return 0 ;
}
