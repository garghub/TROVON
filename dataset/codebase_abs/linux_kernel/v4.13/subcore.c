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
F_13 ( V_14 ) ;
F_3 ( V_5 , V_3 ) . V_1 = V_15 ;
return;
}
V_6 = F_12 ( V_10 ) ;
V_6 &= ~ V_16 ;
F_14 ( V_6 ) ;
F_6 ( V_6 ) ;
while ( F_12 ( V_10 ) & V_11 )
F_15 () ;
for ( V_2 = V_3 + 1 ; V_2 < V_3 + V_4 ; V_2 ++ )
F_16 ( V_2 ) ;
F_1 ( V_15 ) ;
}
static void F_17 ( int V_17 )
{
struct { T_1 V_18 ; T_1 V_11 ; } V_19 [ 2 ] = {
{ V_20 , V_12 } ,
{ V_21 , V_13 }
} ;
int V_2 , V_3 ;
T_1 V_6 ;
V_2 = ( V_17 >> 1 ) - 1 ;
F_18 ( V_2 < 0 || V_2 > 1 ) ;
V_3 = F_2 () ;
if ( F_11 ( V_3 ) != 0 ) {
F_19 ( & F_3 ( V_5 , V_3 ) . V_1 ) ;
return;
}
F_1 ( V_22 ) ;
V_6 = F_12 ( V_10 ) ;
V_6 |= V_16 | V_19 [ V_2 ] . V_18 ;
F_14 ( V_6 ) ;
F_6 ( V_6 ) ;
while ( ! ( F_12 ( V_10 ) & V_19 [ V_2 ] . V_11 ) )
F_15 () ;
}
static void F_20 ( int V_17 )
{
if ( V_23 != 1 )
F_10 () ;
if ( V_17 != 1 )
F_17 ( V_17 ) ;
F_5 () ;
F_3 ( V_5 , F_2 () ) . V_1 = V_24 ;
}
bool F_21 ( void )
{
F_22 () ;
if ( ! V_25 )
return false ;
F_20 ( V_25 ) ;
return true ;
}
void F_23 ( void )
{
int V_3 ;
int V_26 = ( 1 << V_27 ) - 1 ;
F_24 (cpu) {
int V_28 = F_11 ( V_3 ) ;
int V_29 = ( V_28 / V_27 ) * V_27 ;
int V_11 = V_26 << V_29 ;
V_30 [ V_3 ] . V_31 = V_11 ;
}
}
static int F_25 ( void * V_32 )
{
int V_3 , V_17 = * ( int * ) V_32 ;
if ( F_26 ( & V_5 ) -> V_33 ) {
V_25 = V_17 ;
F_27 () ;
F_28 ( V_34 , V_35 ,
V_36 ) ;
F_29 (cpu, cpu_offline_mask)
F_16 ( V_3 ) ;
}
F_20 ( V_17 ) ;
if ( F_26 ( & V_5 ) -> V_33 ) {
F_30 (cpu) {
if ( V_3 >= V_37 )
break;
while( F_3 ( V_5 , V_3 ) . V_1 < V_24 )
F_4 () ;
}
V_25 = 0 ;
V_23 = V_17 ;
V_27 = V_4 / V_23 ;
F_23 () ;
F_5 () ;
}
return 0 ;
}
static int F_31 ( int V_17 )
{
struct V_5 * V_38 ;
int V_3 ;
if ( F_32 () ) {
F_33 ( L_1 ) ;
return - V_39 ;
}
F_18 ( V_17 < 1 || V_17 > 4 || V_17 == 3 ) ;
F_30 (cpu) {
V_38 = & F_3 ( V_5 , V_3 ) ;
V_38 -> V_1 = V_40 ;
V_38 -> V_33 = 0 ;
}
F_34 () ;
F_26 ( & V_5 ) -> V_33 = 1 ;
F_5 () ;
F_35 ( F_25 , & V_17 ,
V_36 ) ;
F_36 () ;
return 0 ;
}
static T_2 T_3 F_37 ( struct V_41 * V_42 ,
struct V_43 * V_44 , const char * V_45 ,
T_4 V_46 )
{
unsigned long V_47 ;
int V_48 ;
V_48 = sscanf ( V_45 , L_2 , & V_47 ) ;
if ( V_48 != 1 )
return - V_49 ;
switch ( V_47 ) {
case 1 :
case 2 :
case 4 :
if ( V_23 == V_47 )
goto V_50;
break;
default:
return - V_49 ;
}
V_48 = F_31 ( V_47 ) ;
if ( V_48 )
return V_48 ;
V_50:
return V_46 ;
}
static T_2 F_38 ( struct V_41 * V_42 ,
struct V_43 * V_44 , char * V_45 )
{
return sprintf ( V_45 , L_3 , V_23 ) ;
}
static int F_39 ( void )
{
unsigned V_51 ;
V_51 = F_40 ( F_12 ( V_52 ) ) ;
if ( V_51 != V_53 &&
V_51 != V_54 &&
V_51 != V_55 )
return 0 ;
if ( V_37 % V_4 )
return 0 ;
F_18 ( ! F_41 ( & V_34 , V_56 ) ) ;
F_31 ( 1 ) ;
return F_42 ( V_57 . V_58 ,
& V_59 ) ;
}
