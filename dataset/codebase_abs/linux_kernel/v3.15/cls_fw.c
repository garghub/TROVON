static T_1 F_1 ( T_1 V_1 )
{
V_1 ^= ( V_1 >> 16 ) ;
V_1 ^= ( V_1 >> 8 ) ;
return V_1 % V_2 ;
}
static int F_2 ( struct V_3 * V_4 , const struct V_5 * V_6 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 = V_6 -> V_11 ;
struct V_12 * V_13 ;
int V_14 ;
T_1 V_15 = V_4 -> V_16 ;
if ( V_10 != NULL ) {
V_15 &= V_10 -> V_17 ;
for ( V_13 = V_10 -> V_18 [ F_1 ( V_15 ) ] ; V_13 ; V_13 = V_13 -> V_19 ) {
if ( V_13 -> V_15 == V_15 ) {
* V_8 = V_13 -> V_8 ;
#ifdef F_3
if ( ! F_4 ( V_4 , V_13 -> V_20 ) )
continue;
#endif
V_14 = F_5 ( V_4 , & V_13 -> V_21 , V_8 ) ;
if ( V_14 < 0 )
continue;
return V_14 ;
}
}
} else {
if ( V_15 && ( F_6 ( V_15 ) == 0 ||
! ( F_6 ( V_15 ^ V_6 -> V_22 -> V_1 ) ) ) ) {
V_8 -> V_23 = V_15 ;
V_8 -> V_24 = 0 ;
return 0 ;
}
}
return - 1 ;
}
static unsigned long F_7 ( struct V_5 * V_6 , T_1 V_1 )
{
struct V_9 * V_10 = V_6 -> V_11 ;
struct V_12 * V_13 ;
if ( V_10 == NULL )
return 0 ;
for ( V_13 = V_10 -> V_18 [ F_1 ( V_1 ) ] ; V_13 ; V_13 = V_13 -> V_19 ) {
if ( V_13 -> V_15 == V_1 )
return ( unsigned long ) V_13 ;
}
return 0 ;
}
static void F_8 ( struct V_5 * V_6 , unsigned long V_13 )
{
}
static int F_9 ( struct V_5 * V_6 )
{
return 0 ;
}
static void F_10 ( struct V_5 * V_6 , struct V_12 * V_13 )
{
F_11 ( V_6 , & V_13 -> V_8 ) ;
F_12 ( V_6 , & V_13 -> V_21 ) ;
F_13 ( V_13 ) ;
}
static void F_14 ( struct V_5 * V_6 )
{
struct V_9 * V_10 = V_6 -> V_11 ;
struct V_12 * V_13 ;
int V_25 ;
if ( V_10 == NULL )
return;
for ( V_25 = 0 ; V_25 < V_2 ; V_25 ++ ) {
while ( ( V_13 = V_10 -> V_18 [ V_25 ] ) != NULL ) {
V_10 -> V_18 [ V_25 ] = V_13 -> V_19 ;
F_10 ( V_6 , V_13 ) ;
}
}
F_13 ( V_10 ) ;
}
static int F_15 ( struct V_5 * V_6 , unsigned long V_26 )
{
struct V_9 * V_10 = V_6 -> V_11 ;
struct V_12 * V_13 = (struct V_12 * ) V_26 ;
struct V_12 * * V_27 ;
if ( V_10 == NULL || V_13 == NULL )
goto V_28;
for ( V_27 = & V_10 -> V_18 [ F_1 ( V_13 -> V_15 ) ] ; * V_27 ; V_27 = & ( * V_27 ) -> V_19 ) {
if ( * V_27 == V_13 ) {
F_16 ( V_6 ) ;
* V_27 = V_13 -> V_19 ;
F_17 ( V_6 ) ;
F_10 ( V_6 , V_13 ) ;
return 0 ;
}
}
V_28:
return - V_29 ;
}
static int
F_18 ( struct V_30 * V_30 , struct V_5 * V_6 , struct V_12 * V_13 ,
struct V_31 * * V_32 , struct V_31 * * V_33 , unsigned long V_34 )
{
struct V_9 * V_10 = V_6 -> V_11 ;
struct V_35 V_36 ;
T_1 V_17 ;
int V_37 ;
F_19 ( & V_36 , V_38 , V_39 ) ;
V_37 = F_20 ( V_30 , V_6 , V_32 , V_33 [ V_40 ] , & V_36 ) ;
if ( V_37 < 0 )
return V_37 ;
if ( V_32 [ V_41 ] ) {
V_13 -> V_8 . V_23 = F_21 ( V_32 [ V_41 ] ) ;
F_22 ( V_6 , & V_13 -> V_8 , V_34 ) ;
}
#ifdef F_3
if ( V_32 [ V_42 ] ) {
int V_43 ;
V_43 = F_23 ( V_30 , V_32 [ V_42 ] ) ;
if ( V_43 < 0 ) {
V_37 = V_43 ;
goto V_44;
}
V_13 -> V_20 = V_43 ;
}
#endif
V_37 = - V_29 ;
if ( V_32 [ V_45 ] ) {
V_17 = F_21 ( V_32 [ V_45 ] ) ;
if ( V_17 != V_10 -> V_17 )
goto V_44;
} else if ( V_10 -> V_17 != 0xFFFFFFFF )
goto V_44;
F_24 ( V_6 , & V_13 -> V_21 , & V_36 ) ;
return 0 ;
V_44:
F_12 ( V_6 , & V_36 ) ;
return V_37 ;
}
static int F_25 ( struct V_30 * V_30 , struct V_3 * V_46 ,
struct V_5 * V_6 , unsigned long V_34 ,
T_1 V_1 ,
struct V_31 * * V_33 ,
unsigned long * V_26 )
{
struct V_9 * V_10 = V_6 -> V_11 ;
struct V_12 * V_13 = (struct V_12 * ) * V_26 ;
struct V_31 * V_47 = V_33 [ V_48 ] ;
struct V_31 * V_32 [ V_49 + 1 ] ;
int V_37 ;
if ( ! V_47 )
return V_1 ? - V_29 : 0 ;
V_37 = F_26 ( V_32 , V_49 , V_47 , V_50 ) ;
if ( V_37 < 0 )
return V_37 ;
if ( V_13 != NULL ) {
if ( V_13 -> V_15 != V_1 && V_1 )
return - V_29 ;
return F_18 ( V_30 , V_6 , V_13 , V_32 , V_33 , V_34 ) ;
}
if ( ! V_1 )
return - V_29 ;
if ( V_10 == NULL ) {
T_1 V_17 = 0xFFFFFFFF ;
if ( V_32 [ V_45 ] )
V_17 = F_21 ( V_32 [ V_45 ] ) ;
V_10 = F_27 ( sizeof( struct V_9 ) , V_51 ) ;
if ( V_10 == NULL )
return - V_52 ;
V_10 -> V_17 = V_17 ;
F_16 ( V_6 ) ;
V_6 -> V_11 = V_10 ;
F_17 ( V_6 ) ;
}
V_13 = F_27 ( sizeof( struct V_12 ) , V_51 ) ;
if ( V_13 == NULL )
return - V_52 ;
F_19 ( & V_13 -> V_21 , V_38 , V_39 ) ;
V_13 -> V_15 = V_1 ;
V_37 = F_18 ( V_30 , V_6 , V_13 , V_32 , V_33 , V_34 ) ;
if ( V_37 < 0 )
goto V_44;
V_13 -> V_19 = V_10 -> V_18 [ F_1 ( V_1 ) ] ;
F_16 ( V_6 ) ;
V_10 -> V_18 [ F_1 ( V_1 ) ] = V_13 ;
F_17 ( V_6 ) ;
* V_26 = ( unsigned long ) V_13 ;
return 0 ;
V_44:
F_13 ( V_13 ) ;
return V_37 ;
}
static void F_28 ( struct V_5 * V_6 , struct V_53 * V_26 )
{
struct V_9 * V_10 = V_6 -> V_11 ;
int V_25 ;
if ( V_10 == NULL )
V_26 -> V_54 = 1 ;
if ( V_26 -> V_54 )
return;
for ( V_25 = 0 ; V_25 < V_2 ; V_25 ++ ) {
struct V_12 * V_13 ;
for ( V_13 = V_10 -> V_18 [ V_25 ] ; V_13 ; V_13 = V_13 -> V_19 ) {
if ( V_26 -> V_55 < V_26 -> V_56 ) {
V_26 -> V_55 ++ ;
continue;
}
if ( V_26 -> V_57 ( V_6 , ( unsigned long ) V_13 , V_26 ) < 0 ) {
V_26 -> V_54 = 1 ;
return;
}
V_26 -> V_55 ++ ;
}
}
}
static int F_29 ( struct V_30 * V_30 , struct V_5 * V_6 , unsigned long V_58 ,
struct V_3 * V_4 , struct V_59 * V_60 )
{
struct V_9 * V_10 = V_6 -> V_11 ;
struct V_12 * V_13 = (struct V_12 * ) V_58 ;
unsigned char * V_61 = F_30 ( V_4 ) ;
struct V_31 * V_62 ;
if ( V_13 == NULL )
return V_4 -> V_63 ;
V_60 -> V_64 = V_13 -> V_15 ;
if ( ! V_13 -> V_8 . V_23 && ! F_31 ( & V_13 -> V_21 ) )
return V_4 -> V_63 ;
V_62 = F_32 ( V_4 , V_48 ) ;
if ( V_62 == NULL )
goto V_65;
if ( V_13 -> V_8 . V_23 &&
F_33 ( V_4 , V_41 , V_13 -> V_8 . V_23 ) )
goto V_65;
#ifdef F_3
if ( V_13 -> V_20 ) {
struct V_66 * V_67 ;
V_67 = F_34 ( V_30 , V_13 -> V_20 ) ;
if ( V_67 && F_35 ( V_4 , V_42 , V_67 -> V_68 ) )
goto V_65;
}
#endif
if ( V_10 -> V_17 != 0xFFFFFFFF &&
F_33 ( V_4 , V_45 , V_10 -> V_17 ) )
goto V_65;
if ( F_36 ( V_4 , & V_13 -> V_21 ) < 0 )
goto V_65;
F_37 ( V_4 , V_62 ) ;
if ( F_38 ( V_4 , & V_13 -> V_21 ) < 0 )
goto V_65;
return V_4 -> V_63 ;
V_65:
F_39 ( V_4 , V_61 ) ;
return - 1 ;
}
static int T_2 F_40 ( void )
{
return F_41 ( & V_69 ) ;
}
static void T_3 F_42 ( void )
{
F_43 ( & V_69 ) ;
}
