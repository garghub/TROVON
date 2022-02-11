static void F_1 ( int V_1 )
{
int V_2 , V_3 = F_2 () ;
for ( V_2 = V_3 + 1 ; V_2 < V_3 + V_4 ; V_2 ++ )
while( F_3 ( V_5 , V_2 ) . V_1 < V_1 )
F_4 () ;
F_5 () ;
}
static void F_6 ( T_1 V_6 )
{
T_1 V_7 = F_7 () ;
if ( V_7 & V_8 ) {
T_1 V_9 = F_8 () ;
F_9 ( V_9 , V_10 , V_6 ) ;
}
}
static void F_10 ( void )
{
T_1 V_6 , V_11 ;
int V_2 , V_3 ;
V_11 = V_12 | V_13 ;
V_3 = F_2 () ;
if ( F_11 ( V_3 ) != 0 ) {
while ( F_12 ( V_10 ) & V_11 )
F_13 ( 0 ) ;
F_3 ( V_5 , V_3 ) . V_1 = V_14 ;
return;
}
V_6 = F_12 ( V_10 ) ;
V_6 &= ~ V_15 ;
F_14 ( V_6 ) ;
F_6 ( V_6 ) ;
while ( F_12 ( V_10 ) & V_11 )
F_15 () ;
for ( V_2 = V_3 + 1 ; V_2 < V_3 + V_4 ; V_2 ++ )
F_16 ( V_2 ) ;
F_1 ( V_14 ) ;
}
static void F_17 ( int V_16 )
{
struct { T_1 V_17 ; T_1 V_11 ; } V_18 [ 2 ] = {
{ V_19 , V_12 } ,
{ V_20 , V_13 }
} ;
int V_2 , V_3 ;
T_1 V_6 ;
V_2 = ( V_16 >> 1 ) - 1 ;
F_18 ( V_2 < 0 || V_2 > 1 ) ;
V_3 = F_2 () ;
if ( F_11 ( V_3 ) != 0 ) {
F_19 ( & F_3 ( V_5 , V_3 ) . V_1 ) ;
return;
}
F_1 ( V_21 ) ;
V_6 = F_12 ( V_10 ) ;
V_6 |= V_15 | V_18 [ V_2 ] . V_17 ;
F_14 ( V_6 ) ;
F_6 ( V_6 ) ;
while ( ! ( F_12 ( V_10 ) & V_18 [ V_2 ] . V_11 ) )
F_15 () ;
}
static void F_20 ( int V_16 )
{
if ( V_22 != 1 )
F_10 () ;
if ( V_16 != 1 )
F_17 ( V_16 ) ;
F_5 () ;
F_3 ( V_5 , F_2 () ) . V_1 = V_23 ;
}
bool F_21 ( void )
{
F_22 () ;
if ( ! V_24 )
return false ;
F_20 ( V_24 ) ;
return true ;
}
void F_23 ( void )
{
int V_3 ;
int V_25 = ( 1 << V_26 ) - 1 ;
F_24 (cpu) {
int V_27 = F_11 ( V_3 ) ;
int V_28 = ( V_27 / V_26 ) * V_26 ;
int V_11 = V_25 << V_28 ;
V_29 [ V_3 ] . V_30 = V_11 ;
}
}
static int F_25 ( void * V_31 )
{
int V_3 , V_16 = * ( int * ) V_31 ;
if ( F_26 ( & V_5 ) -> V_32 ) {
V_24 = V_16 ;
F_27 () ;
F_28 ( V_33 , V_34 ,
V_35 ) ;
F_29 (cpu, cpu_offline_mask)
F_16 ( V_3 ) ;
}
F_20 ( V_16 ) ;
if ( F_26 ( & V_5 ) -> V_32 ) {
F_30 (cpu) {
if ( V_3 >= V_36 )
break;
while( F_3 ( V_5 , V_3 ) . V_1 < V_23 )
F_4 () ;
}
V_24 = 0 ;
V_22 = V_16 ;
V_26 = V_4 / V_22 ;
F_23 () ;
F_5 () ;
}
return 0 ;
}
static int F_31 ( int V_16 )
{
struct V_5 * V_37 ;
int V_3 ;
if ( F_32 () ) {
F_33 ( L_1 ) ;
return - V_38 ;
}
F_18 ( V_16 < 1 || V_16 > 4 || V_16 == 3 ) ;
F_30 (cpu) {
V_37 = & F_3 ( V_5 , V_3 ) ;
V_37 -> V_1 = V_39 ;
V_37 -> V_32 = 0 ;
}
F_34 () ;
F_26 ( & V_5 ) -> V_32 = 1 ;
F_5 () ;
F_35 ( F_25 , & V_16 , V_35 ) ;
F_36 () ;
return 0 ;
}
static T_2 T_3 F_37 ( struct V_40 * V_41 ,
struct V_42 * V_43 , const char * V_44 ,
T_4 V_45 )
{
unsigned long V_46 ;
int V_47 ;
V_47 = sscanf ( V_44 , L_2 , & V_46 ) ;
if ( V_47 != 1 )
return - V_48 ;
switch ( V_46 ) {
case 1 :
case 2 :
case 4 :
if ( V_22 == V_46 )
goto V_49;
break;
default:
return - V_48 ;
}
V_47 = F_31 ( V_46 ) ;
if ( V_47 )
return V_47 ;
V_49:
return V_45 ;
}
static T_2 F_38 ( struct V_40 * V_41 ,
struct V_42 * V_43 , char * V_44 )
{
return sprintf ( V_44 , L_3 , V_22 ) ;
}
static int F_39 ( void )
{
if ( ! F_40 ( V_50 ) )
return 0 ;
if ( V_36 % V_4 )
return 0 ;
F_18 ( ! F_41 ( & V_33 , V_51 ) ) ;
F_31 ( 1 ) ;
return F_42 ( V_52 . V_53 ,
& V_54 ) ;
}
