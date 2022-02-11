static inline int F_1 ( int V_1 , void * V_2 , unsigned long V_3 )
{
return F_2 ( V_4 , V_1 , V_2 , V_3 ) ;
}
static long F_3 ( struct V_5 * V_6 , int V_1 ,
struct V_7 * V_8 , void * * V_9 , int V_10 )
{
long V_11 ;
void * V_12 ;
V_11 = F_4 ( V_6 , ( unsigned long * ) V_8 ,
( sizeof( * V_8 ) + sizeof( long ) - 1 ) &
~ ( sizeof( long ) - 1 ) ,
V_9 , & V_12 ) ;
if ( ! V_11 ) {
unsigned long args [] = { V_1 ,
( unsigned long ) V_12 ,
sizeof( * V_8 ) ,
0 , 0 , 0 } ;
V_11 = F_5 ( V_6 , V_4 , args ,
0 , V_9 , V_10 ) ;
}
return V_11 ;
}
static int F_6 ( void T_1 * V_2 , unsigned long V_3 )
{
int V_13 , V_14 = 0 ;
unsigned long V_15 ;
T_2 * V_16 = & V_17 -> V_18 -> V_19 . V_20 . V_16 ;
if ( ! V_16 -> V_21 )
goto V_22;
if ( V_3 > V_23 * V_24 )
V_3 = V_23 * V_24 ;
V_14 = V_3 ;
F_7 ( & V_16 -> V_25 ) ;
if ( V_16 -> V_21 <= V_26 ) {
V_15 = V_23 * V_26 ;
if ( V_15 > V_3 )
V_15 = V_3 ;
if ( F_8 ( V_2 , V_16 -> V_27 . V_28 , V_15 ) )
V_14 = - V_29 ;
V_3 -= V_15 ;
V_2 += V_15 ;
}
else {
for ( V_13 = 0 ; V_13 < V_16 -> V_21 / V_30 && V_3 ;
V_13 ++ ) {
V_15 = V_31 ;
if ( V_15 > V_3 )
V_15 = V_3 ;
if ( F_8 ( V_2 , V_16 -> V_27 . V_32 [ V_13 ] , V_15 ) ) {
V_14 = - V_29 ;
break;
}
V_3 -= V_15 ;
V_2 += V_15 ;
}
}
F_9 ( & V_16 -> V_25 ) ;
if ( V_3 == 0 || V_14 == - V_29 )
goto V_22;
if ( F_10 ( V_2 , V_3 ) )
V_14 = - V_29 ;
V_22:
return V_14 ;
}
static int F_11 ( void T_1 * V_2 , unsigned long V_3 )
{
int V_14 ;
if ( V_3 > 5 * V_23 )
V_3 = 5 * V_23 ;
V_14 = V_3 ;
if ( F_10 ( V_2 , V_3 ) )
V_14 = - V_29 ;
return V_14 ;
}
static int F_12 ( void T_1 * V_2 , unsigned long V_3 , int V_1 )
{
T_2 * V_16 = & V_17 -> V_18 -> V_19 . V_20 . V_16 ;
struct V_5 * V_6 = & V_17 -> V_18 -> V_19 . V_33 ;
int V_13 , V_14 ;
struct V_7 V_34 ;
struct V_35 V_36 , * V_37 ;
void * V_9 = NULL ;
V_14 = - V_38 ;
if ( V_3 != sizeof( V_34 ) )
goto V_22;
V_14 = - V_29 ;
if ( F_13 ( & V_34 , V_2 , sizeof( V_34 ) ) )
goto V_22;
V_14 = - V_38 ;
if ( V_34 . V_39 >= V_24 )
goto V_22;
if ( V_34 . V_40 == 3 ) {
if ( V_1 == 1 )
goto V_22;
if ( V_34 . V_41 == 0 )
goto V_22;
}
F_7 ( & V_16 -> V_25 ) ;
V_14 = F_3 ( V_6 , V_1 , & V_34 , & V_9 , 1 ) ;
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
F_14 ( V_43 | V_44 ) ;
if ( ! V_16 -> V_27 . V_32 [ V_13 ] ) {
V_14 = - V_45 ;
memset ( & V_34 , 0 , sizeof( V_34 ) ) ;
F_3 ( V_6 , 1 , & V_34 , & V_9 , 1 ) ;
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
( V_1 == 1 || F_15 ( & V_34 ) ) ) {
V_37 -> V_48 = 0 ;
V_37 -> V_49 = 0 ;
}
else{
if ( V_1 == 1 )
V_34 . V_50 = 0 ;
V_37 -> V_48 = F_16 ( & V_34 ) ;
V_37 -> V_49 = F_17 ( & V_34 ) ;
}
V_14 = 0 ;
V_42:
F_9 ( & V_16 -> V_25 ) ;
V_22:
return V_14 ;
}
static long F_18 ( int V_1 , void T_1 * V_2 ,
unsigned long V_3 )
{
int V_51 = - V_52 ;
switch ( V_1 ) {
case 0 :
V_51 = F_6 ( V_2 , V_3 ) ;
break;
case 1 :
case 0x11 :
V_51 = F_12 ( V_2 , V_3 , V_1 ) ;
break;
case 2 :
V_51 = F_11 ( V_2 , V_3 ) ;
break;
}
return V_51 ;
}
static void F_19 ( void )
{
long V_51 ;
struct V_35 * V_16 ;
short * V_53 ;
int V_13 , V_15 , V_54 , V_55 ;
F_20 ( & V_56 ) ;
if ( V_57 != NULL ) {
F_21 ( & V_56 ) ;
return;
}
V_57 = V_58 + 1 ;
F_21 ( & V_56 ) ;
for ( V_13 = V_59 - 1 , V_55 = 0 ; V_13 ; V_13 >>= 1 , V_55 ++ )
;
V_16 = (struct V_35 * )
F_22 ( V_43 | V_44 , V_55 ) ;
if ( V_16 == NULL ) {
F_23 ( V_60 L_1
L_2 ) ;
return;
}
V_51 = F_1 ( 0 , V_16 , ( 1 << V_55 ) * V_31 ) ;
if ( V_51 < 0 ) {
F_23 ( V_60 L_3 ) ;
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
if ( V_15 < F_24 ( V_58 ) )
V_57 = V_58 ;
else {
V_15 = ( V_15 + 1 ) * sizeof( V_58 [ 0 ] ) ;
V_53 = F_25 ( V_15 , V_43 ) ;
if ( V_53 == NULL ) {
F_23 ( V_60 L_4
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
F_26 ( ( unsigned long ) V_16 , V_55 ) ;
}
long F_27 ( struct V_62 * V_63 , struct V_62 * V_64 )
{
struct V_7 V_8 ;
short * V_65 ;
int V_13 ;
long V_66 , V_14 = 0 ;
void * V_9 = NULL ;
F_28 ( & V_63 -> V_20 . V_16 . V_25 ) ;
if ( ! V_64 ) {
memset ( & V_8 , 0 , sizeof( V_8 ) ) ;
F_19 () ;
for ( V_65 = V_57 ; * V_65 != - 1 ; V_65 ++ ) {
V_8 . V_39 = * V_65 ;
V_14 = F_3 ( & V_63 -> V_33 , 1 , & V_8 ,
& V_9 , * ( V_65 + 1 ) == - 1 ) ;
if ( V_14 )
break;
}
V_63 -> V_20 . V_16 . V_21 = 0 ;
goto V_22;
}
F_7 ( & V_64 -> V_20 . V_16 . V_25 ) ;
if ( V_64 -> V_20 . V_16 . V_21 <= V_26 )
memcpy ( V_63 -> V_20 . V_16 . V_27 . V_28 , V_64 -> V_20 . V_16 . V_27 . V_28 ,
sizeof( V_63 -> V_20 . V_16 . V_27 . V_28 ) ) ;
else {
V_13 = V_64 -> V_20 . V_16 . V_21 / V_30 ;
while ( V_13 -- > 0 ) {
V_66 = F_14 ( V_43 | V_44 ) ;
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
F_9 ( & V_64 -> V_20 . V_16 . V_25 ) ;
V_22:
return V_14 ;
}
void F_29 ( struct V_62 * V_18 )
{
int V_13 ;
if ( V_18 -> V_20 . V_16 . V_21 > V_26 ) {
V_13 = V_18 -> V_20 . V_16 . V_21 / V_30 ;
while ( V_13 -- > 0 )
F_30 ( ( long ) V_18 -> V_20 . V_16 . V_27 . V_32 [ V_13 ] ) ;
}
V_18 -> V_20 . V_16 . V_21 = 0 ;
}
int F_31 ( int V_1 , void T_1 * V_2 , unsigned long V_3 )
{
return F_18 ( V_1 , V_2 , V_3 ) ;
}
