static void F_1 ( int V_1 )
{
int V_2 , V_3 = F_2 () ;
for ( V_2 = V_3 + 1 ; V_2 < V_3 + V_4 ; V_2 ++ )
while( F_3 ( V_5 , V_2 ) . V_1 < V_1 )
F_4 () ;
F_5 () ;
}
static void F_6 ( void )
{
T_1 V_6 , V_7 ;
int V_2 , V_3 ;
V_7 = V_8 | V_9 ;
V_3 = F_2 () ;
if ( F_7 ( V_3 ) != 0 ) {
while ( F_8 ( V_10 ) & V_7 )
F_9 ( 0 ) ;
F_3 ( V_5 , V_3 ) . V_1 = V_11 ;
return;
}
V_6 = F_8 ( V_10 ) ;
V_6 &= ~ V_12 ;
F_10 ( V_10 , V_6 ) ;
while ( F_8 ( V_10 ) & V_7 )
F_11 () ;
for ( V_2 = V_3 + 1 ; V_2 < V_3 + V_4 ; V_2 ++ )
F_12 ( V_2 ) ;
F_1 ( V_11 ) ;
}
static void F_13 ( int V_13 )
{
struct { T_1 V_14 ; T_1 V_7 ; } V_15 [ 2 ] = {
{ V_16 , V_8 } ,
{ V_17 , V_9 }
} ;
int V_2 , V_3 ;
T_1 V_6 ;
V_2 = ( V_13 >> 1 ) - 1 ;
F_14 ( V_2 < 0 || V_2 > 1 ) ;
V_3 = F_2 () ;
if ( F_7 ( V_3 ) != 0 ) {
F_15 ( & F_3 ( V_5 , V_3 ) . V_1 ) ;
return;
}
F_1 ( V_18 ) ;
V_6 = F_8 ( V_10 ) ;
V_6 |= V_12 | V_15 [ V_2 ] . V_14 ;
F_10 ( V_10 , V_6 ) ;
while ( ! ( F_8 ( V_10 ) & V_15 [ V_2 ] . V_7 ) )
F_11 () ;
}
static void F_16 ( int V_13 )
{
if ( V_19 != 1 )
F_6 () ;
if ( V_13 != 1 )
F_13 ( V_13 ) ;
F_5 () ;
F_3 ( V_5 , F_2 () ) . V_1 = V_20 ;
}
bool F_17 ( void )
{
F_18 () ;
if ( ! V_21 )
return false ;
F_16 ( V_21 ) ;
return true ;
}
static int F_19 ( void * V_22 )
{
int V_3 , V_13 = * ( int * ) V_22 ;
if ( F_20 ( & V_5 ) -> V_23 ) {
V_21 = V_13 ;
F_21 () ;
F_22 ( V_24 , V_25 ,
V_26 ) ;
F_23 (cpu, cpu_offline_mask)
F_12 ( V_3 ) ;
}
F_16 ( V_13 ) ;
if ( F_20 ( & V_5 ) -> V_23 ) {
F_24 (cpu) {
if ( V_3 >= V_27 )
break;
while( F_3 ( V_5 , V_3 ) . V_1 < V_20 )
F_4 () ;
}
V_21 = 0 ;
V_19 = V_13 ;
V_28 = V_4 / V_19 ;
F_5 () ;
}
return 0 ;
}
static int F_25 ( int V_13 )
{
struct V_5 * V_29 ;
int V_3 ;
if ( F_26 () ) {
F_27 ( L_1 ) ;
return - V_30 ;
}
F_14 ( V_13 < 1 || V_13 > 4 || V_13 == 3 ) ;
F_24 (cpu) {
V_29 = & F_3 ( V_5 , V_3 ) ;
V_29 -> V_1 = V_31 ;
V_29 -> V_23 = 0 ;
}
F_28 () ;
F_20 ( & V_5 ) -> V_23 = 1 ;
F_5 () ;
F_29 ( F_19 , & V_13 , V_26 ) ;
F_30 () ;
return 0 ;
}
static T_2 T_3 F_31 ( struct V_32 * V_33 ,
struct V_34 * V_35 , const char * V_36 ,
T_4 V_37 )
{
unsigned long V_38 ;
int V_39 ;
V_39 = sscanf ( V_36 , L_2 , & V_38 ) ;
if ( V_39 != 1 )
return - V_40 ;
switch ( V_38 ) {
case 1 :
case 2 :
case 4 :
if ( V_19 == V_38 )
goto V_41;
break;
default:
return - V_40 ;
}
V_39 = F_25 ( V_38 ) ;
if ( V_39 )
return V_39 ;
V_41:
return V_37 ;
}
static T_2 F_32 ( struct V_32 * V_33 ,
struct V_34 * V_35 , char * V_36 )
{
return sprintf ( V_36 , L_3 , V_19 ) ;
}
static int F_33 ( void )
{
if ( ! F_34 ( V_42 ) )
return 0 ;
if ( V_27 % V_4 )
return 0 ;
F_14 ( ! F_35 ( & V_24 , V_43 ) ) ;
F_25 ( 1 ) ;
return F_36 ( V_44 . V_45 ,
& V_46 ) ;
}
