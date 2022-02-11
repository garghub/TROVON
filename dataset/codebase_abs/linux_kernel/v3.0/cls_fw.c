static inline int F_1 ( T_1 V_1 )
{
if ( V_2 == 4096 )
return ( ( V_1 >> 24 ) & 0xFFF ) ^
( ( V_1 >> 12 ) & 0xFFF ) ^
( V_1 & 0xFFF ) ;
else if ( V_2 == 2048 )
return ( ( V_1 >> 22 ) & 0x7FF ) ^
( ( V_1 >> 11 ) & 0x7FF ) ^
( V_1 & 0x7FF ) ;
else if ( V_2 == 1024 )
return ( ( V_1 >> 20 ) & 0x3FF ) ^
( ( V_1 >> 10 ) & 0x3FF ) ^
( V_1 & 0x3FF ) ;
else if ( V_2 == 512 )
return ( V_1 >> 27 ) ^
( ( V_1 >> 18 ) & 0x1FF ) ^
( ( V_1 >> 9 ) & 0x1FF ) ^
( V_1 & 0x1FF ) ;
else if ( V_2 == 256 ) {
T_2 * V_3 = ( T_2 * ) & V_1 ;
return V_3 [ 0 ] ^ V_3 [ 1 ] ^ V_3 [ 2 ] ^ V_3 [ 3 ] ;
} else
return V_1 & ( V_2 - 1 ) ;
}
static int F_2 ( struct V_4 * V_5 , struct V_6 * V_7 ,
struct V_8 * V_9 )
{
struct V_10 * V_11 = (struct V_10 * ) V_7 -> V_12 ;
struct V_13 * V_14 ;
int V_15 ;
T_1 V_16 = V_5 -> V_17 ;
if ( V_11 != NULL ) {
V_16 &= V_11 -> V_18 ;
for ( V_14 = V_11 -> V_19 [ F_1 ( V_16 ) ] ; V_14 ; V_14 = V_14 -> V_20 ) {
if ( V_14 -> V_16 == V_16 ) {
* V_9 = V_14 -> V_9 ;
#ifdef F_3
if ( ! F_4 ( V_5 , V_14 -> V_21 ) )
continue;
#endif
V_15 = F_5 ( V_5 , & V_14 -> V_22 , V_9 ) ;
if ( V_15 < 0 )
continue;
return V_15 ;
}
}
} else {
if ( V_16 && ( F_6 ( V_16 ) == 0 ||
! ( F_6 ( V_16 ^ V_7 -> V_23 -> V_1 ) ) ) ) {
V_9 -> V_24 = V_16 ;
V_9 -> V_25 = 0 ;
return 0 ;
}
}
return - 1 ;
}
static unsigned long F_7 ( struct V_6 * V_7 , T_1 V_1 )
{
struct V_10 * V_11 = (struct V_10 * ) V_7 -> V_12 ;
struct V_13 * V_14 ;
if ( V_11 == NULL )
return 0 ;
for ( V_14 = V_11 -> V_19 [ F_1 ( V_1 ) ] ; V_14 ; V_14 = V_14 -> V_20 ) {
if ( V_14 -> V_16 == V_1 )
return ( unsigned long ) V_14 ;
}
return 0 ;
}
static void F_8 ( struct V_6 * V_7 , unsigned long V_14 )
{
}
static int F_9 ( struct V_6 * V_7 )
{
return 0 ;
}
static void F_10 ( struct V_6 * V_7 , struct V_13 * V_14 )
{
F_11 ( V_7 , & V_14 -> V_9 ) ;
F_12 ( V_7 , & V_14 -> V_22 ) ;
F_13 ( V_14 ) ;
}
static void F_14 ( struct V_6 * V_7 )
{
struct V_10 * V_11 = V_7 -> V_12 ;
struct V_13 * V_14 ;
int V_26 ;
if ( V_11 == NULL )
return;
for ( V_26 = 0 ; V_26 < V_2 ; V_26 ++ ) {
while ( ( V_14 = V_11 -> V_19 [ V_26 ] ) != NULL ) {
V_11 -> V_19 [ V_26 ] = V_14 -> V_20 ;
F_10 ( V_7 , V_14 ) ;
}
}
F_13 ( V_11 ) ;
}
static int F_15 ( struct V_6 * V_7 , unsigned long V_27 )
{
struct V_10 * V_11 = (struct V_10 * ) V_7 -> V_12 ;
struct V_13 * V_14 = (struct V_13 * ) V_27 ;
struct V_13 * * V_28 ;
if ( V_11 == NULL || V_14 == NULL )
goto V_29;
for ( V_28 = & V_11 -> V_19 [ F_1 ( V_14 -> V_16 ) ] ; * V_28 ; V_28 = & ( * V_28 ) -> V_20 ) {
if ( * V_28 == V_14 ) {
F_16 ( V_7 ) ;
* V_28 = V_14 -> V_20 ;
F_17 ( V_7 ) ;
F_10 ( V_7 , V_14 ) ;
return 0 ;
}
}
V_29:
return - V_30 ;
}
static int
F_18 ( struct V_6 * V_7 , struct V_13 * V_14 ,
struct V_31 * * V_32 , struct V_31 * * V_33 , unsigned long V_34 )
{
struct V_10 * V_11 = (struct V_10 * ) V_7 -> V_12 ;
struct V_35 V_36 ;
T_1 V_18 ;
int V_37 ;
V_37 = F_19 ( V_7 , V_32 , V_33 [ V_38 ] , & V_36 , & V_39 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = - V_30 ;
if ( V_32 [ V_40 ] ) {
V_14 -> V_9 . V_24 = F_20 ( V_32 [ V_40 ] ) ;
F_21 ( V_7 , & V_14 -> V_9 , V_34 ) ;
}
#ifdef F_3
if ( V_32 [ V_41 ] ) {
V_37 = F_22 ( V_7 , V_14 -> V_21 , V_32 [ V_41 ] ) ;
if ( V_37 < 0 )
goto V_42;
}
#endif
if ( V_32 [ V_43 ] ) {
V_18 = F_20 ( V_32 [ V_43 ] ) ;
if ( V_18 != V_11 -> V_18 )
goto V_42;
} else if ( V_11 -> V_18 != 0xFFFFFFFF )
goto V_42;
F_23 ( V_7 , & V_14 -> V_22 , & V_36 ) ;
return 0 ;
V_42:
F_12 ( V_7 , & V_36 ) ;
return V_37 ;
}
static int F_24 ( struct V_6 * V_7 , unsigned long V_34 ,
T_1 V_1 ,
struct V_31 * * V_33 ,
unsigned long * V_27 )
{
struct V_10 * V_11 = (struct V_10 * ) V_7 -> V_12 ;
struct V_13 * V_14 = (struct V_13 * ) * V_27 ;
struct V_31 * V_44 = V_33 [ V_45 ] ;
struct V_31 * V_32 [ V_46 + 1 ] ;
int V_37 ;
if ( ! V_44 )
return V_1 ? - V_30 : 0 ;
V_37 = F_25 ( V_32 , V_46 , V_44 , V_47 ) ;
if ( V_37 < 0 )
return V_37 ;
if ( V_14 != NULL ) {
if ( V_14 -> V_16 != V_1 && V_1 )
return - V_30 ;
return F_18 ( V_7 , V_14 , V_32 , V_33 , V_34 ) ;
}
if ( ! V_1 )
return - V_30 ;
if ( V_11 == NULL ) {
T_1 V_18 = 0xFFFFFFFF ;
if ( V_32 [ V_43 ] )
V_18 = F_20 ( V_32 [ V_43 ] ) ;
V_11 = F_26 ( sizeof( struct V_10 ) , V_48 ) ;
if ( V_11 == NULL )
return - V_49 ;
V_11 -> V_18 = V_18 ;
F_16 ( V_7 ) ;
V_7 -> V_12 = V_11 ;
F_17 ( V_7 ) ;
}
V_14 = F_26 ( sizeof( struct V_13 ) , V_48 ) ;
if ( V_14 == NULL )
return - V_49 ;
V_14 -> V_16 = V_1 ;
V_37 = F_18 ( V_7 , V_14 , V_32 , V_33 , V_34 ) ;
if ( V_37 < 0 )
goto V_42;
V_14 -> V_20 = V_11 -> V_19 [ F_1 ( V_1 ) ] ;
F_16 ( V_7 ) ;
V_11 -> V_19 [ F_1 ( V_1 ) ] = V_14 ;
F_17 ( V_7 ) ;
* V_27 = ( unsigned long ) V_14 ;
return 0 ;
V_42:
F_13 ( V_14 ) ;
return V_37 ;
}
static void F_27 ( struct V_6 * V_7 , struct V_50 * V_27 )
{
struct V_10 * V_11 = (struct V_10 * ) V_7 -> V_12 ;
int V_26 ;
if ( V_11 == NULL )
V_27 -> V_51 = 1 ;
if ( V_27 -> V_51 )
return;
for ( V_26 = 0 ; V_26 < V_2 ; V_26 ++ ) {
struct V_13 * V_14 ;
for ( V_14 = V_11 -> V_19 [ V_26 ] ; V_14 ; V_14 = V_14 -> V_20 ) {
if ( V_27 -> V_52 < V_27 -> V_53 ) {
V_27 -> V_52 ++ ;
continue;
}
if ( V_27 -> V_54 ( V_7 , ( unsigned long ) V_14 , V_27 ) < 0 ) {
V_27 -> V_51 = 1 ;
return;
}
V_27 -> V_52 ++ ;
}
}
}
static int F_28 ( struct V_6 * V_7 , unsigned long V_55 ,
struct V_4 * V_5 , struct V_56 * V_3 )
{
struct V_10 * V_11 = (struct V_10 * ) V_7 -> V_12 ;
struct V_13 * V_14 = (struct V_13 * ) V_55 ;
unsigned char * V_57 = F_29 ( V_5 ) ;
struct V_31 * V_58 ;
if ( V_14 == NULL )
return V_5 -> V_59 ;
V_3 -> V_60 = V_14 -> V_16 ;
if ( ! V_14 -> V_9 . V_24 && ! F_30 ( & V_14 -> V_22 ) )
return V_5 -> V_59 ;
V_58 = F_31 ( V_5 , V_45 ) ;
if ( V_58 == NULL )
goto V_61;
if ( V_14 -> V_9 . V_24 )
F_32 ( V_5 , V_40 , V_14 -> V_9 . V_24 ) ;
#ifdef F_3
if ( strlen ( V_14 -> V_21 ) )
F_33 ( V_5 , V_41 , V_14 -> V_21 ) ;
#endif
if ( V_11 -> V_18 != 0xFFFFFFFF )
F_32 ( V_5 , V_43 , V_11 -> V_18 ) ;
if ( F_34 ( V_5 , & V_14 -> V_22 , & V_39 ) < 0 )
goto V_61;
F_35 ( V_5 , V_58 ) ;
if ( F_36 ( V_5 , & V_14 -> V_22 , & V_39 ) < 0 )
goto V_61;
return V_5 -> V_59 ;
V_61:
F_37 ( V_5 , V_57 ) ;
return - 1 ;
}
static int T_3 F_38 ( void )
{
return F_39 ( & V_62 ) ;
}
static void T_4 F_40 ( void )
{
F_41 ( & V_62 ) ;
}
