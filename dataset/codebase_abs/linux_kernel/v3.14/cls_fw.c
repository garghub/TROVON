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
static int F_2 ( struct V_4 * V_5 , const struct V_6 * V_7 ,
struct V_8 * V_9 )
{
struct V_10 * V_11 = V_7 -> V_12 ;
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
struct V_10 * V_11 = V_7 -> V_12 ;
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
struct V_10 * V_11 = V_7 -> V_12 ;
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
F_18 ( struct V_31 * V_31 , struct V_6 * V_7 , struct V_13 * V_14 ,
struct V_32 * * V_33 , struct V_32 * * V_34 , unsigned long V_35 )
{
struct V_10 * V_11 = V_7 -> V_12 ;
struct V_36 V_37 ;
T_1 V_18 ;
int V_38 ;
F_19 ( & V_37 , V_39 , V_40 ) ;
V_38 = F_20 ( V_31 , V_7 , V_33 , V_34 [ V_41 ] , & V_37 ) ;
if ( V_38 < 0 )
return V_38 ;
if ( V_33 [ V_42 ] ) {
V_14 -> V_9 . V_24 = F_21 ( V_33 [ V_42 ] ) ;
F_22 ( V_7 , & V_14 -> V_9 , V_35 ) ;
}
#ifdef F_3
if ( V_33 [ V_43 ] ) {
int V_44 ;
V_44 = F_23 ( V_31 , V_33 [ V_43 ] ) ;
if ( V_44 < 0 ) {
V_38 = V_44 ;
goto V_45;
}
V_14 -> V_21 = V_44 ;
}
#endif
V_38 = - V_30 ;
if ( V_33 [ V_46 ] ) {
V_18 = F_21 ( V_33 [ V_46 ] ) ;
if ( V_18 != V_11 -> V_18 )
goto V_45;
} else if ( V_11 -> V_18 != 0xFFFFFFFF )
goto V_45;
F_24 ( V_7 , & V_14 -> V_22 , & V_37 ) ;
return 0 ;
V_45:
F_12 ( V_7 , & V_37 ) ;
return V_38 ;
}
static int F_25 ( struct V_31 * V_31 , struct V_4 * V_47 ,
struct V_6 * V_7 , unsigned long V_35 ,
T_1 V_1 ,
struct V_32 * * V_34 ,
unsigned long * V_27 )
{
struct V_10 * V_11 = V_7 -> V_12 ;
struct V_13 * V_14 = (struct V_13 * ) * V_27 ;
struct V_32 * V_48 = V_34 [ V_49 ] ;
struct V_32 * V_33 [ V_50 + 1 ] ;
int V_38 ;
if ( ! V_48 )
return V_1 ? - V_30 : 0 ;
V_38 = F_26 ( V_33 , V_50 , V_48 , V_51 ) ;
if ( V_38 < 0 )
return V_38 ;
if ( V_14 != NULL ) {
if ( V_14 -> V_16 != V_1 && V_1 )
return - V_30 ;
return F_18 ( V_31 , V_7 , V_14 , V_33 , V_34 , V_35 ) ;
}
if ( ! V_1 )
return - V_30 ;
if ( V_11 == NULL ) {
T_1 V_18 = 0xFFFFFFFF ;
if ( V_33 [ V_46 ] )
V_18 = F_21 ( V_33 [ V_46 ] ) ;
V_11 = F_27 ( sizeof( struct V_10 ) , V_52 ) ;
if ( V_11 == NULL )
return - V_53 ;
V_11 -> V_18 = V_18 ;
F_16 ( V_7 ) ;
V_7 -> V_12 = V_11 ;
F_17 ( V_7 ) ;
}
V_14 = F_27 ( sizeof( struct V_13 ) , V_52 ) ;
if ( V_14 == NULL )
return - V_53 ;
F_19 ( & V_14 -> V_22 , V_39 , V_40 ) ;
V_14 -> V_16 = V_1 ;
V_38 = F_18 ( V_31 , V_7 , V_14 , V_33 , V_34 , V_35 ) ;
if ( V_38 < 0 )
goto V_45;
V_14 -> V_20 = V_11 -> V_19 [ F_1 ( V_1 ) ] ;
F_16 ( V_7 ) ;
V_11 -> V_19 [ F_1 ( V_1 ) ] = V_14 ;
F_17 ( V_7 ) ;
* V_27 = ( unsigned long ) V_14 ;
return 0 ;
V_45:
F_13 ( V_14 ) ;
return V_38 ;
}
static void F_28 ( struct V_6 * V_7 , struct V_54 * V_27 )
{
struct V_10 * V_11 = V_7 -> V_12 ;
int V_26 ;
if ( V_11 == NULL )
V_27 -> V_55 = 1 ;
if ( V_27 -> V_55 )
return;
for ( V_26 = 0 ; V_26 < V_2 ; V_26 ++ ) {
struct V_13 * V_14 ;
for ( V_14 = V_11 -> V_19 [ V_26 ] ; V_14 ; V_14 = V_14 -> V_20 ) {
if ( V_27 -> V_56 < V_27 -> V_57 ) {
V_27 -> V_56 ++ ;
continue;
}
if ( V_27 -> V_58 ( V_7 , ( unsigned long ) V_14 , V_27 ) < 0 ) {
V_27 -> V_55 = 1 ;
return;
}
V_27 -> V_56 ++ ;
}
}
}
static int F_29 ( struct V_31 * V_31 , struct V_6 * V_7 , unsigned long V_59 ,
struct V_4 * V_5 , struct V_60 * V_3 )
{
struct V_10 * V_11 = V_7 -> V_12 ;
struct V_13 * V_14 = (struct V_13 * ) V_59 ;
unsigned char * V_61 = F_30 ( V_5 ) ;
struct V_32 * V_62 ;
if ( V_14 == NULL )
return V_5 -> V_63 ;
V_3 -> V_64 = V_14 -> V_16 ;
if ( ! V_14 -> V_9 . V_24 && ! F_31 ( & V_14 -> V_22 ) )
return V_5 -> V_63 ;
V_62 = F_32 ( V_5 , V_49 ) ;
if ( V_62 == NULL )
goto V_65;
if ( V_14 -> V_9 . V_24 &&
F_33 ( V_5 , V_42 , V_14 -> V_9 . V_24 ) )
goto V_65;
#ifdef F_3
if ( V_14 -> V_21 ) {
struct V_66 * V_67 ;
V_67 = F_34 ( V_31 , V_14 -> V_21 ) ;
if ( V_67 && F_35 ( V_5 , V_43 , V_67 -> V_68 ) )
goto V_65;
}
#endif
if ( V_11 -> V_18 != 0xFFFFFFFF &&
F_33 ( V_5 , V_46 , V_11 -> V_18 ) )
goto V_65;
if ( F_36 ( V_5 , & V_14 -> V_22 ) < 0 )
goto V_65;
F_37 ( V_5 , V_62 ) ;
if ( F_38 ( V_5 , & V_14 -> V_22 ) < 0 )
goto V_65;
return V_5 -> V_63 ;
V_65:
F_39 ( V_5 , V_61 ) ;
return - 1 ;
}
static int T_3 F_40 ( void )
{
return F_41 ( & V_69 ) ;
}
static void T_4 F_42 ( void )
{
F_43 ( & V_69 ) ;
}
