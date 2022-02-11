static void T_1 * F_1 ( void * V_1 , unsigned long V_2 )
{
return V_1 - ( void * ) V_3 + ( void * ) V_2 ;
}
unsigned long T_1 F_2 ( unsigned long V_2 ,
struct V_4 * V_5 )
{
unsigned long V_6 , * V_7 ;
unsigned long V_8 ;
T_2 * V_9 ;
T_3 * V_10 ;
T_4 * V_11 ;
T_5 * V_12 , V_13 ;
int V_14 ;
unsigned int * V_15 ;
if ( V_2 >> V_16 )
for (; ; ) ;
V_6 = V_2 - ( unsigned long ) ( V_3 - V_17 ) ;
if ( V_6 & ~ V_18 )
for (; ; ) ;
F_3 ( V_5 ) ;
V_6 += F_4 () ;
V_9 = F_1 ( & V_19 , V_2 ) ;
V_9 [ F_5 ( V_17 ) ] += V_6 ;
if ( F_6 ( V_20 ) ) {
V_10 = F_1 ( & V_21 , V_2 ) ;
V_10 [ 511 ] += V_6 ;
}
V_11 = F_1 ( & V_22 , V_2 ) ;
V_11 [ 510 ] += V_6 ;
V_11 [ 511 ] += V_6 ;
V_12 = F_1 ( V_23 , V_2 ) ;
V_12 [ 506 ] += V_6 ;
V_15 = F_1 ( & V_24 , V_2 ) ;
V_11 = F_1 ( V_25 [ ( * V_15 ) ++ ] , V_2 ) ;
V_12 = F_1 ( V_25 [ ( * V_15 ) ++ ] , V_2 ) ;
V_8 = V_26 + F_4 () ;
if ( F_6 ( V_20 ) ) {
V_10 = F_1 ( V_25 [ V_24 ++ ] , V_2 ) ;
V_14 = ( V_2 >> V_27 ) % V_28 ;
V_9 [ V_14 + 0 ] = ( T_2 ) V_10 + V_8 ;
V_9 [ V_14 + 1 ] = ( T_2 ) V_10 + V_8 ;
V_14 = ( V_2 >> V_29 ) % V_30 ;
V_10 [ V_14 + 0 ] = ( T_2 ) V_11 + V_8 ;
V_10 [ V_14 + 1 ] = ( T_2 ) V_11 + V_8 ;
} else {
V_14 = ( V_2 >> V_27 ) % V_28 ;
V_9 [ V_14 + 0 ] = ( T_2 ) V_11 + V_8 ;
V_9 [ V_14 + 1 ] = ( T_2 ) V_11 + V_8 ;
}
V_14 = ( V_2 >> V_31 ) % V_32 ;
V_11 [ V_14 + 0 ] = ( T_4 ) V_12 + V_8 ;
V_11 [ V_14 + 1 ] = ( T_4 ) V_12 + V_8 ;
V_13 = V_33 & ~ V_34 ;
V_13 += F_4 () ;
V_13 += V_2 ;
for ( V_14 = 0 ; V_14 < F_7 ( V_35 - V_3 , V_36 ) ; V_14 ++ ) {
int V_37 = V_14 + ( V_2 >> V_38 ) % V_39 ;
V_12 [ V_37 ] = V_13 + V_14 * V_36 ;
}
V_12 = F_1 ( V_40 , V_2 ) ;
for ( V_14 = 0 ; V_14 < V_39 ; V_14 ++ ) {
if ( V_12 [ V_14 ] & V_41 )
V_12 [ V_14 ] += V_6 ;
}
V_7 = F_1 ( & V_42 , V_2 ) ;
* V_7 += V_6 - F_4 () ;
F_8 () ;
return F_4 () ;
}
unsigned long F_9 ( void )
{
return F_4 () ;
}
static void T_6 F_10 ( void )
{
memset ( V_19 , 0 , sizeof( V_43 ) * ( V_28 - 1 ) ) ;
V_24 = 0 ;
F_11 ( F_12 ( V_19 ) ) ;
}
int T_6 F_13 ( unsigned long V_44 , T_5 V_12 )
{
unsigned long V_2 = V_44 - V_45 ;
T_2 V_9 , * V_46 ;
T_3 V_10 , * V_47 ;
T_4 V_11 , * V_48 ;
T_5 * V_49 ;
if ( V_2 >= V_50 || F_14 () != F_15 ( V_19 ) )
return - 1 ;
V_51:
V_46 = & V_19 [ F_5 ( V_44 ) ] . V_9 ;
V_9 = * V_46 ;
if ( ! F_6 ( V_20 ) )
V_47 = V_46 ;
else if ( V_9 )
V_47 = ( T_3 * ) ( ( V_9 & V_52 ) + V_17 - V_42 ) ;
else {
if ( V_24 >= V_53 ) {
F_10 () ;
goto V_51;
}
V_47 = ( T_3 * ) V_25 [ V_24 ++ ] ;
memset ( V_47 , 0 , sizeof( * V_47 ) * V_30 ) ;
* V_46 = ( T_2 ) V_47 - V_17 + V_42 + V_54 ;
}
V_47 += F_16 ( V_44 ) ;
V_10 = * V_47 ;
if ( V_10 )
V_48 = ( T_4 * ) ( ( V_10 & V_52 ) + V_17 - V_42 ) ;
else {
if ( V_24 >= V_53 ) {
F_10 () ;
goto V_51;
}
V_48 = ( T_4 * ) V_25 [ V_24 ++ ] ;
memset ( V_48 , 0 , sizeof( * V_48 ) * V_32 ) ;
* V_47 = ( T_3 ) V_48 - V_17 + V_42 + V_54 ;
}
V_48 += F_17 ( V_44 ) ;
V_11 = * V_48 ;
if ( V_11 )
V_49 = ( T_5 * ) ( ( V_11 & V_52 ) + V_17 - V_42 ) ;
else {
if ( V_24 >= V_53 ) {
F_10 () ;
goto V_51;
}
V_49 = ( T_5 * ) V_25 [ V_24 ++ ] ;
memset ( V_49 , 0 , sizeof( * V_49 ) * V_39 ) ;
* V_48 = ( T_4 ) V_49 - V_17 + V_42 + V_54 ;
}
V_49 [ F_18 ( V_44 ) ] = V_12 ;
return 0 ;
}
int T_6 F_19 ( unsigned long V_44 )
{
unsigned long V_2 = V_44 - V_45 ;
T_5 V_12 ;
V_12 = ( V_2 & V_55 ) + V_56 ;
return F_13 ( V_44 , V_12 ) ;
}
static void T_6 F_20 ( void )
{
memset ( V_57 , 0 ,
( unsigned long ) V_58 - ( unsigned long ) V_57 ) ;
}
static unsigned long F_21 ( void )
{
unsigned long V_59 = V_4 . V_60 . V_59 ;
V_59 |= ( V_61 ) V_4 . V_62 << 32 ;
return V_59 ;
}
static void T_6 F_22 ( char * V_63 )
{
char * V_64 ;
unsigned long V_59 ;
F_23 ( V_63 ) ;
memcpy ( & V_4 , V_63 , sizeof V_4 ) ;
F_24 ( & V_4 ) ;
V_59 = F_21 () ;
if ( V_59 ) {
V_64 = F_25 ( V_59 ) ;
memcpy ( V_65 , V_64 , V_66 ) ;
}
F_26 ( V_63 ) ;
}
T_7 T_8 void T_6 F_27 ( char * V_63 )
{
F_28 ( V_67 < V_17 ) ;
F_28 ( V_67 - V_17 < V_68 ) ;
F_28 ( V_69 + V_68 > 2 * V_70 ) ;
F_28 ( ( V_17 & ~ V_55 ) != 0 ) ;
F_28 ( ( V_67 & ~ V_55 ) != 0 ) ;
F_28 ( ! ( V_67 > V_71 ) ) ;
F_28 ( ! ( ( ( V_72 - 1 ) & V_73 ) ==
( V_71 & V_73 ) ) ) ;
F_28 ( F_29 ( V_74 ) <= V_72 ) ;
F_30 () ;
F_10 () ;
F_20 () ;
F_31 ( V_75 ) ;
F_32 () ;
F_33 () ;
F_34 () ;
F_22 ( F_25 ( V_63 ) ) ;
F_35 () ;
V_75 [ 511 ] = V_19 [ 511 ] ;
F_36 ( V_63 ) ;
}
void T_6 F_36 ( char * V_63 )
{
if ( ! V_4 . V_60 . V_76 )
F_22 ( F_25 ( V_63 ) ) ;
F_37 () ;
switch ( V_4 . V_60 . V_77 ) {
case V_78 :
F_38 () ;
break;
default:
break;
}
F_39 () ;
}
