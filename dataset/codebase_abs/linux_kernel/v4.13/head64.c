static void T_1 * F_1 ( void * V_1 , unsigned long V_2 )
{
return V_1 - ( void * ) V_3 + ( void * ) V_2 ;
}
void T_1 F_2 ( unsigned long V_2 )
{
unsigned long V_4 , * V_5 ;
T_2 * V_6 ;
T_3 * V_7 ;
T_4 * V_8 ;
T_5 * V_9 , V_10 ;
int V_11 ;
unsigned int * V_12 ;
if ( V_2 >> V_13 )
for (; ; ) ;
V_4 = V_2 - ( unsigned long ) ( V_3 - V_14 ) ;
if ( V_4 & ~ V_15 )
for (; ; ) ;
V_6 = F_1 ( & V_16 , V_2 ) ;
V_6 [ F_3 ( V_14 ) ] += V_4 ;
if ( F_4 ( V_17 ) ) {
V_7 = F_1 ( & V_18 , V_2 ) ;
V_7 [ 511 ] += V_4 ;
}
V_8 = F_1 ( & V_19 , V_2 ) ;
V_8 [ 510 ] += V_4 ;
V_8 [ 511 ] += V_4 ;
V_9 = F_1 ( V_20 , V_2 ) ;
V_9 [ 506 ] += V_4 ;
V_12 = F_1 ( & V_21 , V_2 ) ;
V_8 = F_1 ( V_22 [ ( * V_12 ) ++ ] , V_2 ) ;
V_9 = F_1 ( V_22 [ ( * V_12 ) ++ ] , V_2 ) ;
if ( F_4 ( V_17 ) ) {
V_7 = F_1 ( V_22 [ V_21 ++ ] , V_2 ) ;
V_11 = ( V_2 >> V_23 ) % V_24 ;
V_6 [ V_11 + 0 ] = ( T_2 ) V_7 + V_25 ;
V_6 [ V_11 + 1 ] = ( T_2 ) V_7 + V_25 ;
V_11 = ( V_2 >> V_26 ) % V_27 ;
V_7 [ V_11 + 0 ] = ( T_2 ) V_8 + V_25 ;
V_7 [ V_11 + 1 ] = ( T_2 ) V_8 + V_25 ;
} else {
V_11 = ( V_2 >> V_23 ) % V_24 ;
V_6 [ V_11 + 0 ] = ( T_2 ) V_8 + V_25 ;
V_6 [ V_11 + 1 ] = ( T_2 ) V_8 + V_25 ;
}
V_11 = ( V_2 >> V_28 ) % V_29 ;
V_8 [ V_11 + 0 ] = ( T_4 ) V_9 + V_25 ;
V_8 [ V_11 + 1 ] = ( T_4 ) V_9 + V_25 ;
V_10 = V_30 & ~ V_31 ;
V_10 += V_2 ;
for ( V_11 = 0 ; V_11 < F_5 ( V_32 - V_3 , V_33 ) ; V_11 ++ ) {
int V_34 = V_11 + ( V_2 >> V_35 ) % V_36 ;
V_9 [ V_34 ] = V_10 + V_11 * V_33 ;
}
V_9 = F_1 ( V_37 , V_2 ) ;
for ( V_11 = 0 ; V_11 < V_36 ; V_11 ++ ) {
if ( V_9 [ V_11 ] & V_38 )
V_9 [ V_11 ] += V_4 ;
}
V_5 = F_1 ( & V_39 , V_2 ) ;
* V_5 += V_4 ;
}
static void T_6 F_6 ( void )
{
memset ( V_16 , 0 , sizeof( V_40 ) * ( V_24 - 1 ) ) ;
V_21 = 0 ;
F_7 ( F_8 ( V_16 ) ) ;
}
int T_6 F_9 ( unsigned long V_41 )
{
unsigned long V_2 = V_41 - V_42 ;
T_2 V_6 , * V_43 ;
T_3 V_7 , * V_44 ;
T_4 V_8 , * V_45 ;
T_5 V_9 , * V_46 ;
if ( V_2 >= V_47 || F_10 () != F_8 ( V_16 ) )
return - 1 ;
V_48:
V_43 = & V_16 [ F_3 ( V_41 ) ] . V_6 ;
V_6 = * V_43 ;
if ( ! F_4 ( V_17 ) )
V_44 = V_43 ;
else if ( V_6 )
V_44 = ( T_3 * ) ( ( V_6 & V_49 ) + V_14 - V_39 ) ;
else {
if ( V_21 >= V_50 ) {
F_6 () ;
goto V_48;
}
V_44 = ( T_3 * ) V_22 [ V_21 ++ ] ;
memset ( V_44 , 0 , sizeof( * V_44 ) * V_27 ) ;
* V_43 = ( T_2 ) V_44 - V_14 + V_39 + V_25 ;
}
V_44 += F_11 ( V_41 ) ;
V_7 = * V_44 ;
if ( V_7 )
V_45 = ( T_4 * ) ( ( V_7 & V_49 ) + V_14 - V_39 ) ;
else {
if ( V_21 >= V_50 ) {
F_6 () ;
goto V_48;
}
V_45 = ( T_4 * ) V_22 [ V_21 ++ ] ;
memset ( V_45 , 0 , sizeof( * V_45 ) * V_29 ) ;
* V_44 = ( T_3 ) V_45 - V_14 + V_39 + V_25 ;
}
V_45 += F_12 ( V_41 ) ;
V_8 = * V_45 ;
if ( V_8 )
V_46 = ( T_5 * ) ( ( V_8 & V_49 ) + V_14 - V_39 ) ;
else {
if ( V_21 >= V_50 ) {
F_6 () ;
goto V_48;
}
V_46 = ( T_5 * ) V_22 [ V_21 ++ ] ;
memset ( V_46 , 0 , sizeof( * V_46 ) * V_36 ) ;
* V_45 = ( T_4 ) V_46 - V_14 + V_39 + V_25 ;
}
V_9 = ( V_2 & V_51 ) + V_52 ;
V_46 [ F_13 ( V_41 ) ] = V_9 ;
return 0 ;
}
static void T_6 F_14 ( void )
{
memset ( V_53 , 0 ,
( unsigned long ) V_54 - ( unsigned long ) V_53 ) ;
}
static unsigned long F_15 ( void )
{
unsigned long V_55 = V_56 . V_57 . V_55 ;
V_55 |= ( V_58 ) V_56 . V_59 << 32 ;
return V_55 ;
}
static void T_6 F_16 ( char * V_60 )
{
char * V_61 ;
unsigned long V_55 ;
memcpy ( & V_56 , V_60 , sizeof V_56 ) ;
F_17 ( & V_56 ) ;
V_55 = F_15 () ;
if ( V_55 ) {
V_61 = F_18 ( V_55 ) ;
memcpy ( V_62 , V_61 , V_63 ) ;
}
}
T_7 T_8 void T_6 F_19 ( char * V_60 )
{
int V_11 ;
F_20 ( V_64 < V_14 ) ;
F_20 ( V_64 - V_14 < V_65 ) ;
F_20 ( V_66 + V_65 > 2 * V_67 ) ;
F_20 ( ( V_14 & ~ V_51 ) != 0 ) ;
F_20 ( ( V_64 & ~ V_51 ) != 0 ) ;
F_20 ( ! ( V_64 > V_68 ) ) ;
F_20 ( ! ( ( ( V_69 - 1 ) & V_70 ) ==
( V_68 & V_70 ) ) ) ;
F_20 ( F_21 ( V_71 ) <= V_69 ) ;
F_22 () ;
F_6 () ;
F_14 () ;
F_23 ( V_72 ) ;
F_24 () ;
for ( V_11 = 0 ; V_11 < V_73 ; V_11 ++ )
F_25 ( V_11 , V_74 [ V_11 ] ) ;
F_26 ( ( const struct V_75 * ) & V_76 ) ;
F_16 ( F_18 ( V_60 ) ) ;
F_27 () ;
V_72 [ 511 ] = V_16 [ 511 ] ;
F_28 ( V_60 ) ;
}
void T_6 F_28 ( char * V_60 )
{
if ( ! V_56 . V_57 . V_77 )
F_16 ( F_18 ( V_60 ) ) ;
F_29 () ;
switch ( V_56 . V_57 . V_78 ) {
case V_79 :
F_30 () ;
break;
default:
break;
}
F_31 () ;
}
