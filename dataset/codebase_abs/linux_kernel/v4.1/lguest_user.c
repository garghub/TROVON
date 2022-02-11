static int F_1 ( struct V_1 * V_2 , const unsigned long T_1 * V_3 )
{
unsigned long V_4 ;
if ( F_2 ( V_4 , V_3 ) != 0 )
return - V_5 ;
V_2 -> V_6 = F_3 ( V_2 , V_4 , true ) ;
if ( ! V_2 -> V_6 )
return - V_7 ;
return sizeof( unsigned long ) * 2 ;
}
static int F_4 ( struct V_1 * V_2 , const unsigned long T_1 * V_3 )
{
unsigned long V_4 , V_8 , * V_9 ;
if ( F_2 ( V_4 , V_3 ) != 0 )
return - V_5 ;
V_3 ++ ;
if ( F_2 ( V_8 , V_3 ) != 0 )
return - V_5 ;
V_9 = F_3 ( V_2 , V_4 , false ) ;
if ( ! V_9 )
return - V_7 ;
* V_9 = V_8 ;
return sizeof( unsigned long ) * 3 ;
}
static int F_5 ( struct V_1 * V_2 , const unsigned long T_1 * V_3 )
{
unsigned long V_10 ;
if ( F_2 ( V_10 , V_3 ) != 0 )
return - V_5 ;
if ( V_10 >= V_11 )
return - V_12 ;
F_6 ( V_2 , V_10 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , const unsigned long T_1 * V_3 )
{
unsigned long V_13 ;
if ( F_2 ( V_13 , V_3 ) != 0 )
return - V_5 ;
if ( ! F_8 ( V_2 , V_13 ) )
return - V_12 ;
return 0 ;
}
static T_2 F_9 ( struct V_14 * V_14 , char T_1 * V_15 , T_3 V_16 , T_4 * V_17 )
{
struct V_18 * V_19 = V_14 -> V_20 ;
struct V_1 * V_2 ;
unsigned int V_21 = * V_17 ;
if ( ! V_19 )
return - V_12 ;
if ( V_21 >= V_19 -> V_22 )
return - V_12 ;
V_2 = & V_19 -> V_23 [ V_21 ] ;
if ( V_24 != V_2 -> V_25 )
return - V_26 ;
if ( V_19 -> V_27 ) {
T_3 V_28 ;
if ( F_10 ( V_19 -> V_27 ) )
return F_11 ( V_19 -> V_27 ) ;
V_28 = F_12 ( V_16 , strlen ( V_19 -> V_27 ) + 1 ) ;
if ( F_13 ( V_15 , V_19 -> V_27 , V_28 ) != 0 )
return - V_5 ;
return V_28 ;
}
if ( V_2 -> V_29 . F_7 )
V_2 -> V_29 . F_7 = 0 ;
return F_14 ( V_2 , ( unsigned long T_1 * ) V_15 ) ;
}
static int F_15 ( struct V_1 * V_2 , unsigned V_30 , unsigned long V_31 )
{
if ( V_30 >= F_16 ( V_2 -> V_19 -> V_23 ) )
return - V_12 ;
V_2 -> V_30 = V_30 ;
V_2 -> V_19 = F_17 ( V_2 , struct V_18 , V_23 [ V_30 ] ) ;
V_2 -> V_19 -> V_22 ++ ;
F_18 ( V_2 ) ;
V_2 -> V_32 = F_19 ( V_33 ) ;
if ( ! V_2 -> V_32 )
return - V_34 ;
V_2 -> V_35 = ( void * ) V_2 -> V_32 + V_36 - sizeof( * V_2 -> V_35 ) ;
F_20 ( V_2 , V_31 ) ;
V_2 -> V_25 = V_24 ;
V_2 -> V_37 = F_21 ( V_2 -> V_25 ) ;
V_2 -> V_38 = NULL ;
return 0 ;
}
static int F_22 ( struct V_14 * V_14 , const unsigned long T_1 * V_3 )
{
struct V_18 * V_19 ;
int V_39 ;
unsigned long args [ 4 ] ;
F_23 ( & V_40 ) ;
if ( V_14 -> V_20 ) {
V_39 = - V_41 ;
goto V_42;
}
if ( F_24 ( args , V_3 , sizeof( args ) ) != 0 ) {
V_39 = - V_5 ;
goto V_42;
}
V_19 = F_25 ( sizeof( * V_19 ) , V_33 ) ;
if ( ! V_19 ) {
V_39 = - V_34 ;
goto V_42;
}
V_19 -> V_43 = ( void T_1 * ) args [ 0 ] ;
V_19 -> V_44 = args [ 1 ] ;
V_19 -> V_45 = args [ 3 ] ;
V_39 = F_15 ( & V_19 -> V_23 [ 0 ] , 0 , args [ 2 ] ) ;
if ( V_39 )
goto V_46;
V_39 = F_26 ( V_19 ) ;
if ( V_39 )
goto V_47;
V_14 -> V_20 = V_19 ;
F_27 ( & V_40 ) ;
return sizeof( args ) ;
V_47:
F_28 ( V_19 -> V_23 [ 0 ] . V_32 ) ;
V_46:
F_29 ( V_19 ) ;
V_42:
F_27 ( & V_40 ) ;
return V_39 ;
}
static T_2 F_30 ( struct V_14 * V_14 , const char T_1 * V_48 ,
T_3 V_16 , T_4 * V_49 )
{
struct V_18 * V_19 = V_14 -> V_20 ;
const unsigned long T_1 * V_3 = ( const unsigned long T_1 * ) V_48 ;
unsigned long V_50 ;
struct V_1 * V_51 ( V_2 ) ;
unsigned int V_21 = * V_49 ;
if ( F_2 ( V_50 , V_3 ) != 0 )
return - V_5 ;
V_3 ++ ;
if ( V_50 != V_52 ) {
if ( ! V_19 || ( V_21 >= V_19 -> V_22 ) )
return - V_12 ;
V_2 = & V_19 -> V_23 [ V_21 ] ;
if ( V_19 -> V_27 )
return - V_7 ;
}
switch ( V_50 ) {
case V_52 :
return F_22 ( V_14 , V_3 ) ;
case V_53 :
return F_5 ( V_2 , V_3 ) ;
case V_54 :
return F_1 ( V_2 , V_3 ) ;
case V_55 :
return F_4 ( V_2 , V_3 ) ;
case V_56 :
return F_7 ( V_2 , V_3 ) ;
default:
return - V_12 ;
}
}
static int F_31 ( struct V_57 * V_57 , struct V_14 * V_14 )
{
V_14 -> V_20 = NULL ;
return 0 ;
}
static int F_32 ( struct V_57 * V_57 , struct V_14 * V_14 )
{
struct V_18 * V_19 = V_14 -> V_20 ;
unsigned int V_58 ;
if ( ! V_19 )
return 0 ;
F_23 ( & V_40 ) ;
F_33 ( V_19 ) ;
for ( V_58 = 0 ; V_58 < V_19 -> V_22 ; V_58 ++ ) {
F_34 ( & V_19 -> V_23 [ V_58 ] . V_59 ) ;
F_28 ( V_19 -> V_23 [ V_58 ] . V_32 ) ;
F_35 ( V_19 -> V_23 [ V_58 ] . V_37 ) ;
}
if ( ! F_10 ( V_19 -> V_27 ) )
F_29 ( V_19 -> V_27 ) ;
F_29 ( V_19 ) ;
F_27 ( & V_40 ) ;
return 0 ;
}
int T_5 F_36 ( void )
{
return F_37 ( & V_60 ) ;
}
void T_6 F_38 ( void )
{
F_39 ( & V_60 ) ;
}
