static long F_1 ( struct V_1 * V_2 , int V_3 ,
struct V_4 * V_5 , void * * V_6 , int V_7 )
{
long V_8 ;
if ( V_9 ) {
if ( ! V_10 -> V_11 || V_10 -> V_11 == & V_12 ||
V_2 != & V_10 -> V_11 -> V_13 . V_14 )
F_2 ( V_2 ) ;
}
if ( V_15 ) {
struct V_15 V_16 = (struct V_15 ) {
. V_3 = V_3 ,
. V_17 = V_5 ,
. V_18 = sizeof( * V_5 ) } ;
T_1 V_19 ;
int V_20 ;
if ( ! V_9 )
V_20 = V_2 -> V_21 . V_20 ;
else {
V_19 = F_3 () ;
V_20 = V_22 [ V_19 ] ;
}
V_8 = F_4 ( V_20 , 0 , ( unsigned long ) & V_16 ) ;
if ( V_9 )
F_5 () ;
}
else {
void * V_23 ;
V_8 = F_6 ( V_2 , ( unsigned long * ) V_5 ,
( sizeof( * V_5 ) + sizeof( long ) - 1 ) &
~ ( sizeof( long ) - 1 ) ,
V_6 , & V_23 ) ;
if ( ! V_8 ) {
unsigned long args [] = { V_3 ,
( unsigned long ) V_23 ,
sizeof( * V_5 ) ,
0 , 0 , 0 } ;
V_8 = F_7 ( V_2 , V_24 , args ,
0 , V_6 , V_7 ) ;
}
}
if ( V_9 ) {
if ( V_10 -> V_11 && V_10 -> V_11 != & V_12 &&
V_2 != & V_10 -> V_11 -> V_13 . V_14 )
F_2 ( & V_10 -> V_11 -> V_13 . V_14 ) ;
}
return V_8 ;
}
static long F_8 ( void T_2 * V_17 , unsigned long V_18 )
{
int V_8 , V_25 ;
struct V_15 V_15 = (struct V_15 ) {
. V_3 = 0 ,
. V_18 = V_18 ,
. V_17 = F_9 (bytecount, GFP_KERNEL) } ;
T_1 V_19 ;
if ( V_15 . V_17 == NULL )
return - V_26 ;
V_19 = F_3 () ;
V_8 = F_4 ( V_22 [ V_19 ] , 0 , ( unsigned long ) & V_15 ) ;
F_5 () ;
if ( V_8 < 0 )
goto V_27;
V_25 = F_10 ( V_17 , V_15 . V_17 , V_8 ) ;
if ( V_25 != 0 )
V_8 = - V_28 ;
V_27:
F_11 ( V_15 . V_17 ) ;
return V_8 ;
}
static int F_12 ( void T_2 * V_17 , unsigned long V_18 )
{
int V_29 , V_30 = 0 ;
unsigned long V_31 ;
T_3 * V_32 = & V_10 -> V_33 -> V_13 . V_34 . V_32 ;
if ( ! V_32 -> V_35 )
goto V_27;
if ( V_18 > V_36 * V_37 )
V_18 = V_36 * V_37 ;
V_30 = V_18 ;
if ( V_15 )
return F_8 ( V_17 , V_18 ) ;
F_13 ( & V_32 -> V_38 ) ;
if ( V_32 -> V_35 <= V_39 ) {
V_31 = V_36 * V_39 ;
if ( V_31 > V_18 )
V_31 = V_18 ;
if ( F_10 ( V_17 , V_32 -> V_21 . V_40 , V_31 ) )
V_30 = - V_28 ;
V_18 -= V_31 ;
V_17 += V_31 ;
}
else {
for ( V_29 = 0 ; V_29 < V_32 -> V_35 / V_41 && V_18 ;
V_29 ++ ) {
V_31 = V_42 ;
if ( V_31 > V_18 )
V_31 = V_18 ;
if ( F_10 ( V_17 , V_32 -> V_21 . V_43 [ V_29 ] , V_31 ) ) {
V_30 = - V_28 ;
break;
}
V_18 -= V_31 ;
V_17 += V_31 ;
}
}
F_14 ( & V_32 -> V_38 ) ;
if ( V_18 == 0 || V_30 == - V_28 )
goto V_27;
if ( F_15 ( V_17 , V_18 ) )
V_30 = - V_28 ;
V_27:
return V_30 ;
}
static int F_16 ( void T_2 * V_17 , unsigned long V_18 )
{
int V_30 ;
if ( V_18 > 5 * V_36 )
V_18 = 5 * V_36 ;
V_30 = V_18 ;
if ( F_15 ( V_17 , V_18 ) )
V_30 = - V_28 ;
return V_30 ;
}
static int F_17 ( void T_2 * V_17 , unsigned long V_18 , int V_3 )
{
T_3 * V_32 = & V_10 -> V_33 -> V_13 . V_34 . V_32 ;
struct V_1 * V_2 = & V_10 -> V_33 -> V_13 . V_14 ;
int V_29 , V_30 ;
struct V_4 V_44 ;
struct V_45 V_46 , * V_47 ;
void * V_6 = NULL ;
V_30 = - V_48 ;
if ( V_18 != sizeof( V_44 ) )
goto V_27;
V_30 = - V_28 ;
if ( F_18 ( & V_44 , V_17 , sizeof( V_44 ) ) )
goto V_27;
V_30 = - V_48 ;
if ( V_44 . V_49 >= V_37 )
goto V_27;
if ( V_44 . V_50 == 3 ) {
if ( V_3 == 1 )
goto V_27;
if ( V_44 . V_51 == 0 )
goto V_27;
}
if ( ! V_15 )
F_13 ( & V_32 -> V_38 ) ;
V_30 = F_1 ( V_2 , V_3 , & V_44 , & V_6 , 1 ) ;
if ( V_30 )
goto V_52;
else if ( V_15 ) {
V_32 -> V_35 = 1 ;
goto V_27;
}
if ( V_44 . V_49 >= V_32 -> V_35 &&
V_44 . V_49 >= V_39 ) {
for ( V_29 = V_32 -> V_35 / V_41 ;
V_29 * V_41 <= V_44 . V_49 ;
V_29 ++ ) {
if ( V_29 == 0 )
memcpy ( & V_46 , V_32 -> V_21 . V_40 ,
sizeof( V_46 ) ) ;
V_32 -> V_21 . V_43 [ V_29 ] = (struct V_45 * )
F_19 ( V_53 | V_54 ) ;
if ( ! V_32 -> V_21 . V_43 [ V_29 ] ) {
V_30 = - V_26 ;
memset ( & V_44 , 0 , sizeof( V_44 ) ) ;
F_1 ( V_2 , 1 , & V_44 , & V_6 , 1 ) ;
goto V_52;
}
if ( V_29 == 0 ) {
memcpy ( V_32 -> V_21 . V_43 [ 0 ] , & V_46 ,
sizeof( V_46 ) ) ;
memcpy ( V_32 -> V_21 . V_43 [ 0 ] + 1 , V_32 -> V_21 . V_40 + 1 ,
sizeof( V_46 ) * ( V_39 - 1 ) ) ;
}
V_32 -> V_35 = ( V_29 + 1 ) * V_41 ;
}
}
if ( V_32 -> V_35 <= V_44 . V_49 )
V_32 -> V_35 = V_44 . V_49 + 1 ;
if ( V_32 -> V_35 <= V_39 )
V_47 = V_32 -> V_21 . V_40 + V_44 . V_49 ;
else
V_47 = V_32 -> V_21 . V_43 [ V_44 . V_49 / V_41 ] +
V_44 . V_49 % V_41 ;
if ( V_44 . V_55 == 0 && V_44 . V_56 == 0 &&
( V_3 == 1 || F_20 ( & V_44 ) ) ) {
V_47 -> V_57 = 0 ;
V_47 -> V_58 = 0 ;
}
else{
if ( V_3 == 1 )
V_44 . V_59 = 0 ;
V_47 -> V_57 = F_21 ( & V_44 ) ;
V_47 -> V_58 = F_22 ( & V_44 ) ;
}
V_30 = 0 ;
V_52:
F_14 ( & V_32 -> V_38 ) ;
V_27:
return V_30 ;
}
static long F_23 ( int V_3 , void T_2 * V_17 ,
unsigned long V_18 )
{
int V_60 = - V_61 ;
switch ( V_3 ) {
case 0 :
V_60 = F_12 ( V_17 , V_18 ) ;
break;
case 1 :
case 0x11 :
V_60 = F_17 ( V_17 , V_18 , V_3 ) ;
break;
case 2 :
V_60 = F_16 ( V_17 , V_18 ) ;
break;
}
return V_60 ;
}
static void F_24 ( void )
{
long V_60 ;
struct V_45 * V_32 ;
short * V_62 ;
int V_29 , V_31 , V_63 , V_64 ;
F_25 ( & V_65 ) ;
if ( V_66 != NULL ) {
F_26 ( & V_65 ) ;
return;
}
V_66 = V_67 + 1 ;
F_26 ( & V_65 ) ;
for ( V_29 = V_68 - 1 , V_64 = 0 ; V_29 ; V_29 >>= 1 , V_64 ++ )
;
V_32 = (struct V_45 * )
F_27 ( V_53 | V_54 , V_64 ) ;
if ( V_32 == NULL ) {
F_28 ( V_69 L_1
L_2 ) ;
return;
}
V_60 = F_29 ( 0 , V_32 , ( 1 << V_64 ) * V_42 ) ;
if ( V_60 < 0 ) {
F_28 ( V_69 L_3 ) ;
goto V_70;
}
if ( V_60 == 0 ) {
V_66 = V_67 ;
goto V_70;
}
for ( V_29 = 0 , V_31 = 0 ; V_29 < V_60 / V_36 ; V_29 ++ ) {
if ( V_32 [ V_29 ] . V_57 != 0 || V_32 [ V_29 ] . V_58 != 0 )
V_31 ++ ;
}
if ( V_31 < F_30 ( V_67 ) )
V_66 = V_67 ;
else {
V_31 = ( V_31 + 1 ) * sizeof( V_67 [ 0 ] ) ;
V_62 = F_9 ( V_31 , V_53 ) ;
if ( V_62 == NULL ) {
F_28 ( V_69 L_4
L_5 ) ;
goto V_70;
}
V_66 = V_62 ;
}
for ( V_29 = 0 , V_63 = 0 ; V_29 < V_60 / V_36 ; V_29 ++ ) {
if ( V_32 [ V_29 ] . V_57 != 0 || V_32 [ V_29 ] . V_58 != 0 )
V_66 [ V_63 ++ ] = V_29 ;
}
V_66 [ V_63 ] = - 1 ;
V_70:
F_31 ( ( unsigned long ) V_32 , V_64 ) ;
}
long F_32 ( struct V_71 * V_72 , struct V_71 * V_73 )
{
struct V_4 V_5 ;
short * V_74 ;
int V_29 ;
long V_75 , V_30 = 0 ;
void * V_6 = NULL ;
struct V_76 V_77 ;
if ( ! V_15 )
F_33 ( & V_72 -> V_34 . V_32 . V_38 ) ;
if ( ! V_73 ) {
memset ( & V_5 , 0 , sizeof( V_5 ) ) ;
if ( V_9 ) {
V_30 = F_1 ( & V_72 -> V_14 , 1 , & V_5 , & V_6 , 1 ) ;
}
else{
F_24 () ;
for ( V_74 = V_66 ; * V_74 != - 1 ; V_74 ++ ) {
V_5 . V_49 = * V_74 ;
V_30 = F_1 ( & V_72 -> V_14 , 1 , & V_5 ,
& V_6 , * ( V_74 + 1 ) == - 1 ) ;
if ( V_30 )
break;
}
}
V_72 -> V_34 . V_32 . V_35 = 0 ;
goto V_27;
}
if ( V_9 ) {
V_77 = ( (struct V_76 ) { . V_78 = V_79 ,
. V_21 =
{ . V_80 =
V_73 -> V_14 . V_21 . V_81 } } ) ;
V_29 = F_34 ( V_72 -> V_14 . V_21 . V_81 , & V_77 , sizeof( V_77 ) ) ;
if ( V_29 != sizeof( V_77 ) )
F_28 ( V_69 L_6
L_7 , - V_29 ) ;
}
if ( ! V_15 ) {
F_13 ( & V_73 -> V_34 . V_32 . V_38 ) ;
if ( V_73 -> V_34 . V_32 . V_35 <= V_39 )
memcpy ( V_72 -> V_34 . V_32 . V_21 . V_40 , V_73 -> V_34 . V_32 . V_21 . V_40 ,
sizeof( V_72 -> V_34 . V_32 . V_21 . V_40 ) ) ;
else {
V_29 = V_73 -> V_34 . V_32 . V_35 / V_41 ;
while ( V_29 -- > 0 ) {
V_75 = F_19 ( V_53 | V_54 ) ;
if ( ! V_75 ) {
V_30 = - V_26 ;
break;
}
V_72 -> V_34 . V_32 . V_21 . V_43 [ V_29 ] =
(struct V_45 * ) V_75 ;
memcpy ( V_72 -> V_34 . V_32 . V_21 . V_43 [ V_29 ] ,
V_73 -> V_34 . V_32 . V_21 . V_43 [ V_29 ] , V_42 ) ;
}
}
V_72 -> V_34 . V_32 . V_35 = V_73 -> V_34 . V_32 . V_35 ;
F_14 ( & V_73 -> V_34 . V_32 . V_38 ) ;
}
V_27:
return V_30 ;
}
void F_35 ( struct V_71 * V_33 )
{
int V_29 ;
if ( ! V_15 && V_33 -> V_34 . V_32 . V_35 > V_39 ) {
V_29 = V_33 -> V_34 . V_32 . V_35 / V_41 ;
while ( V_29 -- > 0 )
F_36 ( ( long ) V_33 -> V_34 . V_32 . V_21 . V_43 [ V_29 ] ) ;
}
V_33 -> V_34 . V_32 . V_35 = 0 ;
}
int F_37 ( int V_3 , void T_2 * V_17 , unsigned long V_18 )
{
return F_23 ( V_3 , V_17 , V_18 ) ;
}
