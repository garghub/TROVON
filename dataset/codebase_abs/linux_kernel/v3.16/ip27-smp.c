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
F_12 ( V_21 , true ) ;
F_1 ( V_21 , V_18 ) ;
V_20 ++ ;
V_18 ++ ;
}
V_19 = ( T_6 * ) F_13 ( V_7 , ( V_28 * ) V_19 ,
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
int V_29 , V_17 = 0 ;
T_7 * V_30 = V_31 ;
for ( V_29 = 0 ; V_29 < V_32 ; V_29 ++ )
V_33 [ V_29 ] = V_9 ;
for ( V_29 = 0 ; V_29 < V_34 ; V_29 ++ )
V_35 [ V_29 ] = V_36 ;
for ( V_29 = 0 ; V_29 < V_37 ; V_29 ++ )
V_26 [ V_29 ] = V_36 ;
F_16 ( V_38 ) ;
for ( V_29 = 0 ; V_29 < V_32 ; V_29 ++ ) {
T_3 V_4 = V_30 -> V_39 [ V_29 ] ;
if ( V_4 == V_9 )
break;
V_33 [ V_29 ] = V_4 ;
V_35 [ V_4 ] = V_29 ;
F_17 ( F_18 () ) ;
V_17 = F_9 ( V_29 , V_4 , V_17 ) ;
}
F_19 ( L_1 , V_17 + 1 , F_18 () ) ;
}
static T_8 void F_20 ( T_3 V_4 )
{
int V_29 ;
F_21 ( V_4 , V_40 , 0 ) ;
F_21 ( V_4 , V_41 , 0 ) ;
F_21 ( V_4 , V_42 , 0 ) ;
F_21 ( V_4 , V_43 , 0 ) ;
for ( V_29 = 0 ; V_29 < 128 ; V_29 ++ )
F_22 ( V_4 , V_29 ) ;
}
static void F_23 ( int V_44 , unsigned int V_45 )
{
int V_46 ;
switch ( V_45 ) {
case V_47 :
V_46 = V_48 ;
break;
case V_49 :
V_46 = V_50 ;
break;
default:
F_24 ( L_2 ) ;
}
V_46 += F_5 ( V_44 ) ;
F_25 ( F_3 ( F_26 ( V_44 ) ) , V_46 ) ;
}
static void F_27 ( const struct V_51 * V_52 , unsigned int V_45 )
{
unsigned int V_29 ;
F_28 (i, mask)
F_23 ( V_29 , V_45 ) ;
}
static void F_29 ( void )
{
F_30 () ;
}
static void F_31 ( void )
{
extern void V_53 ( void ) ;
V_53 () ;
F_32 () ;
}
static void F_33 ( int V_1 , struct V_54 * V_55 )
{
unsigned long V_56 = ( unsigned long ) F_34 ( V_55 ) ;
unsigned long V_57 = F_35 ( V_55 ) ;
F_36 ( F_4 ( V_1 ) , F_5 ( V_1 ) ,
( V_58 ) F_37 ( V_59 ) ,
0 , ( void * ) V_57 , ( void * ) V_56 ) ;
}
static void T_8 F_38 ( void )
{
T_2 V_16 ;
F_39 (cnode) {
if ( V_16 == 0 )
continue;
F_20 ( F_3 ( V_16 ) ) ;
}
F_40 () ;
F_1 ( 0 , 0 ) ;
}
static void T_8 F_41 ( unsigned int V_60 )
{
}
