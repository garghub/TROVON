static long F_1 ( struct V_1 * V_2 , int V_3 ,
struct V_4 * V_5 , void * * V_6 , int V_7 )
{
long V_8 ;
void * V_9 ;
V_8 = F_2 ( V_2 , ( unsigned long * ) V_5 ,
( sizeof( * V_5 ) + sizeof( long ) - 1 ) &
~ ( sizeof( long ) - 1 ) ,
V_6 , & V_9 ) ;
if ( ! V_8 ) {
unsigned long args [] = { V_3 ,
( unsigned long ) V_9 ,
sizeof( * V_5 ) ,
0 , 0 , 0 } ;
V_8 = F_3 ( V_2 , V_10 , args ,
0 , V_6 , V_7 ) ;
}
return V_8 ;
}
static int F_4 ( void T_1 * V_11 , unsigned long V_12 )
{
int V_13 , V_14 = 0 ;
unsigned long V_15 ;
T_2 * V_16 = & V_17 -> V_18 -> V_19 . V_20 . V_16 ;
if ( ! V_16 -> V_21 )
goto V_22;
if ( V_12 > V_23 * V_24 )
V_12 = V_23 * V_24 ;
V_14 = V_12 ;
F_5 ( & V_16 -> V_25 ) ;
if ( V_16 -> V_21 <= V_26 ) {
V_15 = V_23 * V_26 ;
if ( V_15 > V_12 )
V_15 = V_12 ;
if ( F_6 ( V_11 , V_16 -> V_27 . V_28 , V_15 ) )
V_14 = - V_29 ;
V_12 -= V_15 ;
V_11 += V_15 ;
}
else {
for ( V_13 = 0 ; V_13 < V_16 -> V_21 / V_30 && V_12 ;
V_13 ++ ) {
V_15 = V_31 ;
if ( V_15 > V_12 )
V_15 = V_12 ;
if ( F_6 ( V_11 , V_16 -> V_27 . V_32 [ V_13 ] , V_15 ) ) {
V_14 = - V_29 ;
break;
}
V_12 -= V_15 ;
V_11 += V_15 ;
}
}
F_7 ( & V_16 -> V_25 ) ;
if ( V_12 == 0 || V_14 == - V_29 )
goto V_22;
if ( F_8 ( V_11 , V_12 ) )
V_14 = - V_29 ;
V_22:
return V_14 ;
}
static int F_9 ( void T_1 * V_11 , unsigned long V_12 )
{
int V_14 ;
if ( V_12 > 5 * V_23 )
V_12 = 5 * V_23 ;
V_14 = V_12 ;
if ( F_8 ( V_11 , V_12 ) )
V_14 = - V_29 ;
return V_14 ;
}
static int F_10 ( void T_1 * V_11 , unsigned long V_12 , int V_3 )
{
T_2 * V_16 = & V_17 -> V_18 -> V_19 . V_20 . V_16 ;
struct V_1 * V_2 = & V_17 -> V_18 -> V_19 . V_33 ;
int V_13 , V_14 ;
struct V_4 V_34 ;
struct V_35 V_36 , * V_37 ;
void * V_6 = NULL ;
V_14 = - V_38 ;
if ( V_12 != sizeof( V_34 ) )
goto V_22;
V_14 = - V_29 ;
if ( F_11 ( & V_34 , V_11 , sizeof( V_34 ) ) )
goto V_22;
V_14 = - V_38 ;
if ( V_34 . V_39 >= V_24 )
goto V_22;
if ( V_34 . V_40 == 3 ) {
if ( V_3 == 1 )
goto V_22;
if ( V_34 . V_41 == 0 )
goto V_22;
}
F_5 ( & V_16 -> V_25 ) ;
V_14 = F_1 ( V_2 , V_3 , & V_34 , & V_6 , 1 ) ;
if ( V_14 )
goto V_42;
if ( V_34 . V_39 >= V_16 -> V_21 &&
V_34 . V_39 >= V_26 ) {
for ( V_13 = V_16 -> V_21 / V_30 ;
V_13 * V_30 <= V_34 . V_39 ;
V_13 ++ ) {
if ( V_13 == 0 )
memcpy ( & V_36 , V_16 -> V_27 . V_28 ,
sizeof( V_36 ) ) ;
V_16 -> V_27 . V_32 [ V_13 ] = (struct V_35 * )
F_12 ( V_43 | V_44 ) ;
if ( ! V_16 -> V_27 . V_32 [ V_13 ] ) {
V_14 = - V_45 ;
memset ( & V_34 , 0 , sizeof( V_34 ) ) ;
F_1 ( V_2 , 1 , & V_34 , & V_6 , 1 ) ;
goto V_42;
}
if ( V_13 == 0 ) {
memcpy ( V_16 -> V_27 . V_32 [ 0 ] , & V_36 ,
sizeof( V_36 ) ) ;
memcpy ( V_16 -> V_27 . V_32 [ 0 ] + 1 , V_16 -> V_27 . V_28 + 1 ,
sizeof( V_36 ) * ( V_26 - 1 ) ) ;
}
V_16 -> V_21 = ( V_13 + 1 ) * V_30 ;
}
}
if ( V_16 -> V_21 <= V_34 . V_39 )
V_16 -> V_21 = V_34 . V_39 + 1 ;
if ( V_16 -> V_21 <= V_26 )
V_37 = V_16 -> V_27 . V_28 + V_34 . V_39 ;
else
V_37 = V_16 -> V_27 . V_32 [ V_34 . V_39 / V_30 ] +
V_34 . V_39 % V_30 ;
if ( V_34 . V_46 == 0 && V_34 . V_47 == 0 &&
( V_3 == 1 || F_13 ( & V_34 ) ) ) {
V_37 -> V_48 = 0 ;
V_37 -> V_49 = 0 ;
}
else{
if ( V_3 == 1 )
V_34 . V_50 = 0 ;
V_37 -> V_48 = F_14 ( & V_34 ) ;
V_37 -> V_49 = F_15 ( & V_34 ) ;
}
V_14 = 0 ;
V_42:
F_7 ( & V_16 -> V_25 ) ;
V_22:
return V_14 ;
}
static long F_16 ( int V_3 , void T_1 * V_11 ,
unsigned long V_12 )
{
int V_51 = - V_52 ;
switch ( V_3 ) {
case 0 :
V_51 = F_4 ( V_11 , V_12 ) ;
break;
case 1 :
case 0x11 :
V_51 = F_10 ( V_11 , V_12 , V_3 ) ;
break;
case 2 :
V_51 = F_9 ( V_11 , V_12 ) ;
break;
}
return V_51 ;
}
static void F_17 ( void )
{
long V_51 ;
struct V_35 * V_16 ;
short * V_53 ;
int V_13 , V_15 , V_54 , V_55 ;
F_18 ( & V_56 ) ;
if ( V_57 != NULL ) {
F_19 ( & V_56 ) ;
return;
}
V_57 = V_58 + 1 ;
F_19 ( & V_56 ) ;
for ( V_13 = V_59 - 1 , V_55 = 0 ; V_13 ; V_13 >>= 1 , V_55 ++ )
;
V_16 = (struct V_35 * )
F_20 ( V_43 | V_44 , V_55 ) ;
if ( V_16 == NULL ) {
F_21 ( V_60 L_1
L_2 ) ;
return;
}
V_51 = F_22 ( 0 , V_16 , ( 1 << V_55 ) * V_31 ) ;
if ( V_51 < 0 ) {
F_21 ( V_60 L_3 ) ;
goto V_61;
}
if ( V_51 == 0 ) {
V_57 = V_58 ;
goto V_61;
}
for ( V_13 = 0 , V_15 = 0 ; V_13 < V_51 / V_23 ; V_13 ++ ) {
if ( V_16 [ V_13 ] . V_48 != 0 || V_16 [ V_13 ] . V_49 != 0 )
V_15 ++ ;
}
if ( V_15 < F_23 ( V_58 ) )
V_57 = V_58 ;
else {
V_15 = ( V_15 + 1 ) * sizeof( V_58 [ 0 ] ) ;
V_53 = F_24 ( V_15 , V_43 ) ;
if ( V_53 == NULL ) {
F_21 ( V_60 L_4
L_5 ) ;
goto V_61;
}
V_57 = V_53 ;
}
for ( V_13 = 0 , V_54 = 0 ; V_13 < V_51 / V_23 ; V_13 ++ ) {
if ( V_16 [ V_13 ] . V_48 != 0 || V_16 [ V_13 ] . V_49 != 0 )
V_57 [ V_54 ++ ] = V_13 ;
}
V_57 [ V_54 ] = - 1 ;
V_61:
F_25 ( ( unsigned long ) V_16 , V_55 ) ;
}
long F_26 ( struct V_62 * V_63 , struct V_62 * V_64 )
{
struct V_4 V_5 ;
short * V_65 ;
int V_13 ;
long V_66 , V_14 = 0 ;
void * V_6 = NULL ;
F_27 ( & V_63 -> V_20 . V_16 . V_25 ) ;
if ( ! V_64 ) {
memset ( & V_5 , 0 , sizeof( V_5 ) ) ;
F_17 () ;
for ( V_65 = V_57 ; * V_65 != - 1 ; V_65 ++ ) {
V_5 . V_39 = * V_65 ;
V_14 = F_1 ( & V_63 -> V_33 , 1 , & V_5 ,
& V_6 , * ( V_65 + 1 ) == - 1 ) ;
if ( V_14 )
break;
}
V_63 -> V_20 . V_16 . V_21 = 0 ;
goto V_22;
}
F_5 ( & V_64 -> V_20 . V_16 . V_25 ) ;
if ( V_64 -> V_20 . V_16 . V_21 <= V_26 )
memcpy ( V_63 -> V_20 . V_16 . V_27 . V_28 , V_64 -> V_20 . V_16 . V_27 . V_28 ,
sizeof( V_63 -> V_20 . V_16 . V_27 . V_28 ) ) ;
else {
V_13 = V_64 -> V_20 . V_16 . V_21 / V_30 ;
while ( V_13 -- > 0 ) {
V_66 = F_12 ( V_43 | V_44 ) ;
if ( ! V_66 ) {
V_14 = - V_45 ;
break;
}
V_63 -> V_20 . V_16 . V_27 . V_32 [ V_13 ] =
(struct V_35 * ) V_66 ;
memcpy ( V_63 -> V_20 . V_16 . V_27 . V_32 [ V_13 ] ,
V_64 -> V_20 . V_16 . V_27 . V_32 [ V_13 ] , V_31 ) ;
}
}
V_63 -> V_20 . V_16 . V_21 = V_64 -> V_20 . V_16 . V_21 ;
F_7 ( & V_64 -> V_20 . V_16 . V_25 ) ;
V_22:
return V_14 ;
}
void F_28 ( struct V_62 * V_18 )
{
int V_13 ;
if ( V_18 -> V_20 . V_16 . V_21 > V_26 ) {
V_13 = V_18 -> V_20 . V_16 . V_21 / V_30 ;
while ( V_13 -- > 0 )
F_29 ( ( long ) V_18 -> V_20 . V_16 . V_27 . V_32 [ V_13 ] ) ;
}
V_18 -> V_20 . V_16 . V_21 = 0 ;
}
int F_30 ( int V_3 , void T_1 * V_11 , unsigned long V_12 )
{
return F_16 ( V_3 , V_11 , V_12 ) ;
}
