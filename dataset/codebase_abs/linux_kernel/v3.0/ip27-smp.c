static void F_1 ( T_1 V_1 , int V_2 )
{
T_2 V_3 = F_2 ( V_1 ) ;
T_3 V_4 = F_3 ( V_3 ) ;
F_4 ( V_2 ) = V_4 ;
V_5 [ V_2 ] . V_6 = V_3 ;
F_5 ( V_2 ) = F_6 ( V_1 ) ;
}
static T_3 F_7 ( T_4 * V_7 )
{
T_5 * V_8 ;
if ( ! V_7 )
return V_9 ;
V_8 = ( T_5 * ) F_8 ( V_7 , V_10 ) ;
if ( ! V_8 )
return V_9 ;
if ( ! ( V_8 -> V_11 . V_12 & V_13 ) )
return V_8 -> V_11 . V_14 ;
else
return V_7 -> V_15 ;
}
static int F_9 ( T_2 V_16 , T_3 V_4 , int V_17 )
{
static int V_18 = 0 ;
T_4 * V_7 ;
T_6 * V_19 ;
int V_20 = 0 ;
T_1 V_21 ;
V_7 = F_10 ( ( T_4 * ) F_11 ( V_4 ) , V_22 ) ;
do {
V_19 = ( T_6 * ) F_8 ( V_7 , V_23 ) ;
while ( V_19 ) {
V_21 = V_19 -> V_24 . V_25 ;
if ( F_7 ( V_7 ) == V_7 -> V_15 )
V_26 [ V_21 ] = V_16 ;
if ( V_21 > V_17 )
V_17 = V_21 ;
if ( ( V_19 -> V_24 . V_12 & V_13 ) &&
( V_18 != V_27 ) ) {
F_12 ( V_21 , V_28 ) ;
F_1 ( V_21 , V_18 ) ;
V_20 ++ ;
V_18 ++ ;
}
V_19 = ( T_6 * ) F_13 ( V_7 , ( V_29 * ) V_19 ,
V_23 ) ;
}
V_7 = F_14 ( V_7 ) ;
if ( ! V_7 )
break;
V_7 = F_10 ( V_7 , V_22 ) ;
} while ( V_7 );
return V_17 ;
}
void F_15 ( void )
{
int V_30 , V_17 = 0 ;
T_7 * V_31 = V_32 ;
for ( V_30 = 0 ; V_30 < V_33 ; V_30 ++ )
V_34 [ V_30 ] = V_9 ;
for ( V_30 = 0 ; V_30 < V_35 ; V_30 ++ )
V_36 [ V_30 ] = V_37 ;
for ( V_30 = 0 ; V_30 < V_38 ; V_30 ++ )
V_26 [ V_30 ] = V_37 ;
F_16 ( V_39 ) ;
for ( V_30 = 0 ; V_30 < V_33 ; V_30 ++ ) {
T_3 V_4 = V_31 -> V_40 [ V_30 ] ;
if ( V_4 == V_9 )
break;
V_34 [ V_30 ] = V_4 ;
V_36 [ V_4 ] = V_30 ;
F_17 ( F_18 () ) ;
V_17 = F_9 ( V_30 , V_4 , V_17 ) ;
}
F_19 ( L_1 , V_17 + 1 , F_18 () ) ;
}
static T_8 void F_20 ( T_3 V_4 )
{
int V_30 ;
F_21 ( V_4 , V_41 , 0 ) ;
F_21 ( V_4 , V_42 , 0 ) ;
F_21 ( V_4 , V_43 , 0 ) ;
F_21 ( V_4 , V_44 , 0 ) ;
for ( V_30 = 0 ; V_30 < 128 ; V_30 ++ )
F_22 ( V_4 , V_30 ) ;
}
static void F_23 ( int V_45 , unsigned int V_46 )
{
int V_47 ;
switch ( V_46 ) {
case V_48 :
V_47 = V_49 ;
break;
case V_50 :
V_47 = V_51 ;
break;
default:
F_24 ( L_2 ) ;
}
V_47 += F_5 ( V_45 ) ;
F_25 ( F_3 ( F_26 ( V_45 ) ) , V_47 ) ;
}
static void F_27 ( const struct V_52 * V_53 , unsigned int V_46 )
{
unsigned int V_30 ;
F_28 (i, mask)
F_23 ( V_30 , V_46 ) ;
}
static void T_9 F_29 ( void )
{
F_30 () ;
}
static void T_9 F_31 ( void )
{
extern void V_54 ( void ) ;
V_54 () ;
F_32 () ;
}
static void T_8 F_33 ( void )
{
}
static void T_9 F_34 ( int V_1 , struct V_55 * V_56 )
{
unsigned long V_57 = ( unsigned long ) F_35 ( V_56 ) ;
unsigned long V_58 = F_36 ( V_56 ) ;
F_37 ( F_4 ( V_1 ) , F_5 ( V_1 ) ,
( V_59 ) F_38 ( V_60 ) ,
0 , ( void * ) V_58 , ( void * ) V_57 ) ;
}
static void T_8 F_39 ( void )
{
T_2 V_16 ;
F_40 (cnode) {
if ( V_16 == 0 )
continue;
F_20 ( F_3 ( V_16 ) ) ;
}
F_41 () ;
F_1 ( 0 , 0 ) ;
}
static void T_8 F_42 ( unsigned int V_61 )
{
}
