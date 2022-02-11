bool F_1 ( struct V_1 * V_2 )
{
unsigned int V_3 ;
struct V_4 * V_5 ;
F_2 () ;
V_5 = F_3 ( V_2 -> V_6 -> V_7 ) ;
for ( V_3 = 0 ; V_3 < V_5 -> V_8 ; V_3 ++ ) {
if ( V_5 -> V_5 [ V_3 ] . V_9 == V_2 -> V_10 ) {
F_4 ( V_5 -> V_5 [ V_3 ] . V_11 , 1 ) ;
V_2 -> V_10 = 0 ;
break;
}
}
F_5 () ;
return V_2 -> V_10 == 0 ;
}
static int F_6 ( struct V_12 * V_6 , unsigned long V_9 , int V_13 )
{
struct V_4 * V_14 , * V_15 = V_6 -> V_7 ;
if ( ! V_9 )
return - V_16 ;
V_14 = F_7 ( sizeof( * V_14 ) + sizeof( V_14 -> V_5 [ 0 ] ) * ( V_15 -> V_8 + 1 ) ,
V_17 ) ;
if ( ! V_14 )
return - V_18 ;
memcpy ( V_14 -> V_5 , V_15 -> V_5 , sizeof( V_15 -> V_5 [ 0 ] ) * V_15 -> V_8 ) ;
V_14 -> V_8 = V_15 -> V_8 ;
V_14 -> V_5 [ V_14 -> V_8 ] . V_9 = V_9 ;
V_14 -> V_5 [ V_14 -> V_8 ] . V_11 = F_8 ( V_13 ) ;
if ( F_9 ( V_14 -> V_5 [ V_14 -> V_8 ] . V_11 ) ) {
int V_19 = F_10 ( V_14 -> V_5 [ V_14 -> V_8 ] . V_11 ) ;
F_11 ( V_14 ) ;
return V_19 ;
}
V_14 -> V_8 ++ ;
F_12 ( V_6 -> V_7 , V_14 ) ;
F_13 () ;
F_11 ( V_15 ) ;
return 0 ;
}
static int F_14 ( struct V_12 * V_6 , const unsigned long T_1 * V_20 )
{
unsigned long V_9 , V_13 ;
int V_19 ;
if ( F_15 ( V_9 , V_20 ) != 0 )
return - V_21 ;
V_20 ++ ;
if ( F_15 ( V_13 , V_20 ) != 0 )
return - V_21 ;
F_16 ( & V_22 ) ;
V_19 = F_6 ( V_6 , V_9 , V_13 ) ;
F_17 ( & V_22 ) ;
return V_19 ;
}
static int F_18 ( struct V_1 * V_2 , const unsigned long T_1 * V_20 )
{
unsigned long V_23 ;
if ( F_15 ( V_23 , V_20 ) != 0 )
return - V_21 ;
if ( V_23 >= V_24 )
return - V_16 ;
F_19 ( V_2 , V_23 ) ;
return 0 ;
}
static T_2 F_20 ( struct V_25 * V_25 , char T_1 * V_26 , T_3 V_27 , T_4 * V_28 )
{
struct V_12 * V_6 = V_25 -> V_29 ;
struct V_1 * V_2 ;
unsigned int V_30 = * V_28 ;
if ( ! V_6 )
return - V_16 ;
if ( V_30 >= V_6 -> V_31 )
return - V_16 ;
V_2 = & V_6 -> V_32 [ V_30 ] ;
if ( V_33 != V_2 -> V_34 )
return - V_35 ;
if ( V_6 -> V_36 ) {
T_3 V_37 ;
if ( F_9 ( V_6 -> V_36 ) )
return F_10 ( V_6 -> V_36 ) ;
V_37 = F_21 ( V_27 , strlen ( V_6 -> V_36 ) + 1 ) ;
if ( F_22 ( V_26 , V_6 -> V_36 , V_37 ) != 0 )
return - V_21 ;
return V_37 ;
}
if ( V_2 -> V_10 )
V_2 -> V_10 = 0 ;
return F_23 ( V_2 , ( unsigned long T_1 * ) V_26 ) ;
}
static int F_24 ( struct V_1 * V_2 , unsigned V_38 , unsigned long V_39 )
{
if ( V_38 >= F_25 ( V_2 -> V_6 -> V_32 ) )
return - V_16 ;
V_2 -> V_38 = V_38 ;
V_2 -> V_6 = F_26 ( ( V_2 - V_38 ) , struct V_12 , V_32 [ 0 ] ) ;
V_2 -> V_6 -> V_31 ++ ;
F_27 ( V_2 ) ;
V_2 -> V_40 = F_28 ( V_17 ) ;
if ( ! V_2 -> V_40 )
return - V_18 ;
V_2 -> V_41 = ( void * ) V_2 -> V_40 + V_42 - sizeof( * V_2 -> V_41 ) ;
F_29 ( V_2 , V_39 ) ;
V_2 -> V_34 = V_33 ;
V_2 -> V_43 = F_30 ( V_2 -> V_34 ) ;
V_2 -> V_44 = NULL ;
return 0 ;
}
static int F_31 ( struct V_25 * V_25 , const unsigned long T_1 * V_20 )
{
struct V_12 * V_6 ;
int V_19 ;
unsigned long args [ 3 ] ;
F_16 ( & V_22 ) ;
if ( V_25 -> V_29 ) {
V_19 = - V_45 ;
goto V_46;
}
if ( F_32 ( args , V_20 , sizeof( args ) ) != 0 ) {
V_19 = - V_21 ;
goto V_46;
}
V_6 = F_33 ( sizeof( * V_6 ) , V_17 ) ;
if ( ! V_6 ) {
V_19 = - V_18 ;
goto V_46;
}
V_6 -> V_7 = F_7 ( sizeof( * V_6 -> V_7 ) , V_17 ) ;
if ( ! V_6 -> V_7 ) {
V_19 = - V_18 ;
goto V_47;
}
V_6 -> V_7 -> V_8 = 0 ;
V_6 -> V_48 = ( void T_1 * ) args [ 0 ] ;
V_6 -> V_49 = args [ 1 ] ;
V_19 = F_24 ( & V_6 -> V_32 [ 0 ] , 0 , args [ 2 ] ) ;
if ( V_19 )
goto V_50;
V_19 = F_34 ( V_6 ) ;
if ( V_19 )
goto V_51;
V_25 -> V_29 = V_6 ;
F_17 ( & V_22 ) ;
return sizeof( args ) ;
V_51:
F_35 ( V_6 -> V_32 [ 0 ] . V_40 ) ;
V_50:
F_11 ( V_6 -> V_7 ) ;
V_47:
F_11 ( V_6 ) ;
V_46:
F_17 ( & V_22 ) ;
return V_19 ;
}
static T_2 F_36 ( struct V_25 * V_25 , const char T_1 * V_52 ,
T_3 V_27 , T_4 * V_53 )
{
struct V_12 * V_6 = V_25 -> V_29 ;
const unsigned long T_1 * V_20 = ( const unsigned long T_1 * ) V_52 ;
unsigned long V_54 ;
struct V_1 * V_55 ( V_2 ) ;
unsigned int V_30 = * V_53 ;
if ( F_15 ( V_54 , V_20 ) != 0 )
return - V_21 ;
V_20 ++ ;
if ( V_54 != V_56 ) {
if ( ! V_6 || ( V_30 >= V_6 -> V_31 ) )
return - V_16 ;
V_2 = & V_6 -> V_32 [ V_30 ] ;
if ( V_6 -> V_36 )
return - V_57 ;
}
switch ( V_54 ) {
case V_56 :
return F_31 ( V_25 , V_20 ) ;
case V_58 :
return F_18 ( V_2 , V_20 ) ;
case V_59 :
return F_14 ( V_6 , V_20 ) ;
default:
return - V_16 ;
}
}
static int F_37 ( struct V_60 * V_60 , struct V_25 * V_25 )
{
struct V_12 * V_6 = V_25 -> V_29 ;
unsigned int V_3 ;
if ( ! V_6 )
return 0 ;
F_16 ( & V_22 ) ;
F_38 ( V_6 ) ;
for ( V_3 = 0 ; V_3 < V_6 -> V_31 ; V_3 ++ ) {
F_39 ( & V_6 -> V_32 [ V_3 ] . V_61 ) ;
F_35 ( V_6 -> V_32 [ V_3 ] . V_40 ) ;
F_40 ( V_6 -> V_32 [ V_3 ] . V_43 ) ;
}
for ( V_3 = 0 ; V_3 < V_6 -> V_7 -> V_8 ; V_3 ++ )
F_41 ( V_6 -> V_7 -> V_5 [ V_3 ] . V_11 ) ;
F_11 ( V_6 -> V_7 ) ;
if ( ! F_9 ( V_6 -> V_36 ) )
F_11 ( V_6 -> V_36 ) ;
F_11 ( V_6 ) ;
F_17 ( & V_22 ) ;
return 0 ;
}
int T_5 F_42 ( void )
{
return F_43 ( & V_62 ) ;
}
void T_6 F_44 ( void )
{
F_45 ( & V_62 ) ;
}
