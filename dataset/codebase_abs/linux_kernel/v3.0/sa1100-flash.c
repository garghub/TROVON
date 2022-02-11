static void F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 , struct V_4 , V_2 ) ;
V_5 -> V_6 -> V_7 ( V_3 ) ;
}
static void F_3 ( struct V_4 * V_5 )
{
if ( V_5 -> V_8 )
F_4 ( V_5 -> V_8 ) ;
if ( V_5 -> V_2 . V_9 )
F_5 ( V_5 -> V_2 . V_9 ) ;
F_6 ( V_5 -> V_2 . V_10 , V_5 -> V_2 . V_11 ) ;
}
static int F_7 ( struct V_4 * V_5 , struct V_12 * V_13 )
{
unsigned long V_10 ;
unsigned int V_11 ;
int V_14 ;
V_10 = V_13 -> V_15 ;
V_11 = V_13 -> V_16 - V_10 + 1 ;
switch ( V_10 ) {
default:
F_8 ( V_17 L_1
L_2 , V_10 ) ;
case V_18 :
V_5 -> V_2 . V_19 = ( V_20 & V_21 ) ? 2 : 4 ;
break;
case V_22 :
V_5 -> V_2 . V_19 = ( ( V_20 >> 16 ) & V_21 ) ? 2 : 4 ;
break;
}
if ( ! F_9 ( V_10 , V_11 , V_5 -> V_23 ) ) {
V_14 = - V_24 ;
goto V_25;
}
if ( V_5 -> V_6 -> V_7 )
V_5 -> V_2 . V_7 = F_1 ;
V_5 -> V_2 . V_10 = V_10 ;
V_5 -> V_2 . V_11 = V_11 ;
V_5 -> V_2 . V_9 = F_10 ( V_10 , V_11 ) ;
if ( ! V_5 -> V_2 . V_9 ) {
V_14 = - V_26 ;
goto V_27;
}
F_11 ( & V_5 -> V_2 ) ;
V_5 -> V_8 = F_12 ( V_5 -> V_6 -> V_28 , & V_5 -> V_2 ) ;
if ( V_5 -> V_8 == NULL ) {
V_14 = - V_29 ;
goto V_27;
}
V_5 -> V_8 -> V_30 = V_31 ;
F_8 ( V_32 L_3 ,
V_10 , ( unsigned ) ( V_5 -> V_8 -> V_11 >> 20 ) ,
V_5 -> V_2 . V_19 * 8 ) ;
return 0 ;
V_27:
F_3 ( V_5 ) ;
V_25:
return V_14 ;
}
static void F_13 ( struct V_33 * V_34 , struct V_35 * V_6 )
{
int V_36 ;
if ( V_34 -> V_8 ) {
F_14 ( V_34 -> V_8 ) ;
if ( V_34 -> V_8 != V_34 -> V_5 [ 0 ] . V_8 )
F_15 ( V_34 -> V_8 ) ;
}
F_16 ( V_34 -> V_37 ) ;
for ( V_36 = V_34 -> V_38 - 1 ; V_36 >= 0 ; V_36 -- )
F_3 ( & V_34 -> V_5 [ V_36 ] ) ;
F_16 ( V_34 ) ;
if ( V_6 -> exit )
V_6 -> exit () ;
}
static struct V_33 * T_1
F_17 ( struct V_39 * V_40 , struct V_35 * V_6 )
{
struct V_33 * V_34 ;
int V_41 , V_11 , V_36 , V_14 = 0 ;
for ( V_41 = 0 ; ; V_41 ++ )
if ( ! F_18 ( V_40 , V_42 , V_41 ) )
break;
if ( V_41 == 0 ) {
V_14 = - V_43 ;
goto V_25;
}
V_11 = sizeof( struct V_33 ) + sizeof( struct V_4 ) * V_41 ;
V_34 = F_19 ( V_11 , V_44 ) ;
if ( ! V_34 ) {
V_14 = - V_26 ;
goto V_25;
}
if ( V_6 -> V_45 ) {
V_14 = V_6 -> V_45 () ;
if ( V_14 )
goto V_27;
}
for ( V_36 = 0 ; V_36 < V_41 ; V_36 ++ ) {
struct V_4 * V_5 = & V_34 -> V_5 [ V_36 ] ;
struct V_12 * V_13 ;
V_13 = F_18 ( V_40 , V_42 , V_36 ) ;
if ( ! V_13 )
break;
V_5 -> V_2 . V_23 = V_5 -> V_23 ;
sprintf ( V_5 -> V_23 , L_4 , V_6 -> V_23 , V_36 ) ;
V_5 -> V_6 = V_6 ;
V_14 = F_7 ( V_5 , V_13 ) ;
if ( V_14 )
break;
}
V_34 -> V_38 = V_36 ;
if ( V_14 != 0 && ! ( V_14 == - V_29 && V_34 -> V_38 > 0 ) )
goto V_27;
if ( V_34 -> V_38 == 1 ) {
strcpy ( V_34 -> V_5 [ 0 ] . V_23 , V_6 -> V_23 ) ;
V_34 -> V_8 = V_34 -> V_5 [ 0 ] . V_8 ;
V_14 = 0 ;
} else if ( V_34 -> V_38 > 1 ) {
struct V_46 * V_47 [ V_41 ] ;
for ( V_36 = 0 ; V_36 < V_34 -> V_38 ; V_36 ++ )
V_47 [ V_36 ] = V_34 -> V_5 [ V_36 ] . V_8 ;
V_34 -> V_8 = F_20 ( V_47 , V_34 -> V_38 ,
V_6 -> V_23 ) ;
if ( V_34 -> V_8 == NULL )
V_14 = - V_29 ;
}
if ( V_14 == 0 )
return V_34 ;
V_27:
F_13 ( V_34 , V_6 ) ;
V_25:
return F_21 ( V_14 ) ;
}
static int T_1 F_22 ( struct V_39 * V_40 )
{
struct V_35 * V_6 = V_40 -> V_48 . V_49 ;
struct V_50 * V_37 ;
const char * V_51 = NULL ;
struct V_33 * V_34 ;
int V_27 , V_52 = 0 ;
if ( ! V_6 )
return - V_43 ;
V_34 = F_17 ( V_40 , V_6 ) ;
if ( F_23 ( V_34 ) ) {
V_27 = F_24 ( V_34 ) ;
goto V_25;
}
V_52 = F_25 ( V_34 -> V_8 , V_53 , & V_37 , 0 ) ;
if ( V_52 > 0 ) {
V_34 -> V_37 = V_37 ;
V_51 = L_5 ;
} else {
V_37 = V_6 -> V_37 ;
V_52 = V_6 -> V_52 ;
V_51 = L_6 ;
}
if ( V_52 == 0 )
F_8 ( V_54 L_7
L_8 ) ;
else
F_8 ( V_54 L_9
L_10 , V_51 ) ;
F_26 ( V_34 -> V_8 , V_37 , V_52 ) ;
V_34 -> V_52 = V_52 ;
F_27 ( V_40 , V_34 ) ;
V_27 = 0 ;
V_25:
return V_27 ;
}
static int T_2 F_28 ( struct V_39 * V_40 )
{
struct V_33 * V_34 = F_29 ( V_40 ) ;
struct V_35 * V_6 = V_40 -> V_48 . V_49 ;
F_27 ( V_40 , NULL ) ;
F_13 ( V_34 , V_6 ) ;
return 0 ;
}
static void F_30 ( struct V_39 * V_48 )
{
struct V_33 * V_34 = F_29 ( V_48 ) ;
if ( V_34 && V_34 -> V_8 -> V_55 ( V_34 -> V_8 ) == 0 )
V_34 -> V_8 -> V_56 ( V_34 -> V_8 ) ;
}
static int T_3 F_31 ( void )
{
return F_32 ( & V_57 ) ;
}
static void T_2 F_33 ( void )
{
F_34 ( & V_57 ) ;
}
