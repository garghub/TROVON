static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_5 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_7 ; V_6 ++ ) {
if ( V_2 -> V_8 [ V_6 ] . V_9 == V_4 ) {
V_2 -> V_8 [ V_6 ] . V_10 = V_5 ;
return;
}
}
}
struct V_3 * F_2 ( struct V_1 * V_2 , int V_11 )
{
struct V_3 * V_4 = NULL ;
int V_12 = 0 , V_6 ;
for ( V_6 = 0 ; V_6 < V_7 ; V_6 ++ ) {
if ( ! ( V_4 = V_2 -> V_8 [ V_6 ] . V_9 ) )
break;
if ( V_12 == V_11 )
goto V_13;
V_4 = NULL ;
V_12 ++ ;
}
V_13:
if ( V_12 == V_11 )
return V_4 ;
return NULL ;
}
struct V_14 * F_3 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_14 * V_15 ;
const T_1 * V_16 ;
V_15 = F_4 ( sizeof( * V_15 ) , V_17 ) ;
if ( ! V_15 )
return NULL ;
V_15 -> V_2 = V_2 ;
V_15 -> V_4 = V_4 ;
V_16 = F_5 ( V_4 -> V_18 . V_19 , L_1 , NULL ) ;
if ( ! V_16 ) {
F_6 ( V_15 ) ;
return NULL ;
}
V_15 -> V_20 = V_16 [ 0 ] ;
V_15 -> V_21 = V_16 [ 1 ] ;
F_7 ( V_2 , V_4 ) ;
return V_15 ;
}
void F_8 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_2 ;
struct V_3 * V_4 = V_15 -> V_4 ;
F_9 ( V_2 , V_4 ) ;
F_6 ( V_15 ) ;
}
static int F_10 ( struct V_1 * V_2 , T_2 * V_22 )
{
F_11 ( V_23 , V_24 ) ;
int V_25 = 32 ;
int V_26 = 1 ;
V_2 -> V_27 = 1 ;
F_12 ( & V_2 -> V_28 , & V_23 ) ;
while ( V_25 -- > 0 ) {
long V_5 ;
V_5 = F_13 (
V_2 -> V_28 ,
( ( ( * V_22 = F_14 ( V_2 -> V_29 + 0 ) )
& V_30 ) == 0 ) ,
F_15 ( 250 ) ) ;
if ( V_5 > 0 ) {
V_26 = 0 ;
break;
}
}
F_16 ( & V_2 -> V_28 , & V_23 ) ;
V_2 -> V_27 = 0 ;
return V_26 ;
}
int F_17 ( struct V_14 * V_15 , unsigned char V_5 , int V_31 )
{
struct V_1 * V_2 = V_15 -> V_2 ;
int V_21 = V_15 -> V_21 ;
T_2 V_22 ;
int V_26 = - 1 ;
if ( V_2 -> V_32 != NULL )
F_18 ( V_15 -> V_20 , V_2 -> V_32 ) ;
F_18 ( V_21 , V_2 -> V_29 + 0x1 ) ;
F_18 ( V_33 , V_2 -> V_29 + 0x0 ) ;
if ( F_10 ( V_2 , & V_22 ) )
goto V_13;
F_18 ( V_31 , V_2 -> V_29 + 0x1 ) ;
if ( F_10 ( V_2 , & V_22 ) ||
( V_22 & V_34 ) != 0 )
goto V_13;
F_18 ( V_5 , V_2 -> V_29 + 0x1 ) ;
if ( F_10 ( V_2 , & V_22 ) )
goto V_13;
V_26 = 0 ;
V_13:
F_18 ( V_35 , V_2 -> V_29 + 0x0 ) ;
return V_26 ;
}
int F_19 ( struct V_14 * V_15 , unsigned char * V_36 , int V_31 )
{
struct V_1 * V_2 = V_15 -> V_2 ;
unsigned char V_21 = V_15 -> V_21 , V_22 ;
int V_26 = - 1 ;
if ( V_2 -> V_32 != NULL )
F_18 ( V_15 -> V_20 , V_2 -> V_32 ) ;
F_18 ( V_21 , V_2 -> V_29 + 0x1 ) ;
F_18 ( V_33 , V_2 -> V_29 + 0x0 ) ;
if ( F_10 ( V_2 , & V_22 ) )
goto V_13;
F_18 ( V_31 , V_2 -> V_29 + 0x1 ) ;
if ( F_10 ( V_2 , & V_22 ) ||
( V_22 & V_34 ) != 0 )
goto V_13;
F_18 ( V_35 , V_2 -> V_29 + 0x0 ) ;
V_21 |= 0x1 ;
F_18 ( V_21 , V_2 -> V_29 + 0x1 ) ;
F_18 ( V_33 , V_2 -> V_29 + 0x0 ) ;
if ( F_10 ( V_2 , & V_22 ) )
goto V_13;
( void ) F_14 ( V_2 -> V_29 + 0x1 ) ;
if ( F_10 ( V_2 , & V_22 ) )
goto V_13;
F_18 ( V_37 | V_38 , V_2 -> V_29 + 0x0 ) ;
* V_36 = F_14 ( V_2 -> V_29 + 0x1 ) ;
if ( F_10 ( V_2 , & V_22 ) )
goto V_13;
V_26 = 0 ;
V_13:
F_18 ( V_35 , V_2 -> V_29 + 0x0 ) ;
( void ) F_14 ( V_2 -> V_29 + 0x1 ) ;
return V_26 ;
}
int F_20 ( struct V_14 * V_15 ,
char * V_39 , int V_40 , int V_31 )
{
int V_26 = 0 ;
while ( V_40 > 0 ) {
int V_41 = F_17 ( V_15 , * V_39 , V_31 ) ;
if ( V_41 < 0 ) {
V_26 = V_41 ;
break;
}
V_40 -- ;
V_39 ++ ;
V_31 ++ ;
}
return V_26 ;
}
int F_21 ( struct V_14 * V_15 ,
char * V_39 , int V_40 , int V_31 )
{
int V_26 = 0 ;
while ( V_40 > 0 ) {
int V_41 = F_19 ( V_15 , V_39 , V_31 ) ;
if ( V_41 < 0 ) {
V_26 = V_41 ;
break;
}
V_40 -- ;
V_39 ++ ;
V_31 ++ ;
}
return V_26 ;
}
static T_3 F_22 ( int V_42 , void * V_43 )
{
struct V_1 * V_2 = V_43 ;
if ( V_2 -> V_27 &&
! ( F_14 ( V_2 -> V_29 + 0x0 ) & V_30 ) )
F_23 ( & V_2 -> V_28 ) ;
return V_44 ;
}
static void T_4 F_24 ( struct V_1 * V_2 )
{
F_18 ( V_30 , V_2 -> V_29 + 0x0 ) ;
F_18 ( V_2 -> V_45 , V_2 -> V_29 + 0x1 ) ;
F_18 ( V_30 | V_46 , V_2 -> V_29 + 0x0 ) ;
F_18 ( V_2 -> clock , V_2 -> V_29 + 0x1 ) ;
F_18 ( V_47 , V_2 -> V_29 + 0x0 ) ;
}
static struct V_1 * T_4 F_25 ( struct V_3 * V_4 , int V_11 )
{
struct V_1 * V_2 ;
struct V_48 * V_49 ;
int V_50 ;
V_2 = F_4 ( sizeof( * V_2 ) , V_17 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_29 = F_26 ( & V_4 -> V_51 [ 0 ] , 0 , 0x2 , L_2 ) ;
if ( ! V_2 -> V_29 )
goto V_52;
V_2 -> V_32 = F_26 ( & V_4 -> V_51 [ 1 ] , 0 , 0x1 , L_3 ) ;
if ( ! V_2 -> V_32 )
goto V_52;
V_2 -> V_27 = 0 ;
F_27 ( & V_2 -> V_28 ) ;
if ( F_28 ( V_4 -> V_53 . V_54 [ 0 ] , F_22 ,
V_55 , L_4 , V_2 ) )
goto V_52;
V_2 -> V_11 = V_11 ;
V_2 -> V_4 = V_4 ;
F_29 ( & V_2 -> V_56 ) ;
V_50 = 0 ;
for ( V_49 = V_4 -> V_18 . V_19 -> V_57 ;
V_49 && V_50 < 8 ;
V_49 = V_49 -> V_58 , V_50 ++ ) {
struct V_3 * V_59 ;
V_59 = F_30 ( V_49 ) ;
V_2 -> V_8 [ V_50 ] . V_9 = V_59 ;
V_2 -> V_8 [ V_50 ] . V_10 = 0 ;
}
F_18 ( V_30 , V_2 -> V_29 + 0x0 ) ;
V_2 -> V_45 = F_14 ( V_2 -> V_29 + 0x01 ) ;
F_18 ( V_30 | V_46 , V_2 -> V_29 + 0x0 ) ;
V_2 -> clock = F_14 ( V_2 -> V_29 + 0x01 ) ;
F_31 ( V_60 L_5 ,
V_2 -> V_11 , V_2 -> V_29 , V_50 , V_2 -> V_45 , V_2 -> clock ) ;
F_24 ( V_2 ) ;
return V_2 ;
V_52:
if ( V_2 -> V_32 )
F_32 ( & V_4 -> V_51 [ 1 ] , V_2 -> V_32 , 1 ) ;
if ( V_2 -> V_29 )
F_32 ( & V_4 -> V_51 [ 0 ] , V_2 -> V_29 , 2 ) ;
F_6 ( V_2 ) ;
return NULL ;
}
static int T_5 F_33 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
int V_41 , V_11 = 0 ;
V_2 = F_25 ( V_4 , V_11 ) ;
if ( ! V_2 )
return - V_61 ;
V_41 = F_34 ( V_2 ) ;
if ( V_41 ) {
F_35 ( V_4 -> V_53 . V_54 [ 0 ] , V_2 ) ;
if ( V_2 -> V_32 )
F_32 ( & V_4 -> V_51 [ 0 ] , V_2 -> V_32 , 1 ) ;
if ( V_2 -> V_29 )
F_32 ( & V_4 -> V_51 [ 1 ] , V_2 -> V_29 , 2 ) ;
F_6 ( V_2 ) ;
} else {
F_36 ( & V_4 -> V_18 , V_2 ) ;
}
return V_41 ;
}
static int T_6 F_37 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_38 ( & V_4 -> V_18 ) ;
F_39 ( V_2 ) ;
F_35 ( V_4 -> V_53 . V_54 [ 0 ] , V_2 ) ;
if ( V_2 -> V_32 )
F_32 ( & V_4 -> V_51 [ 0 ] , V_2 -> V_32 , 1 ) ;
if ( V_2 -> V_29 )
F_32 ( & V_4 -> V_51 [ 1 ] , V_2 -> V_29 , 2 ) ;
F_6 ( V_2 ) ;
return 0 ;
}
static int T_4 F_40 ( void )
{
return F_41 ( & V_62 ) ;
}
static void T_7 F_42 ( void )
{
F_43 ( & V_62 ) ;
}
