static T_1 F_1 ( T_1 V_1 )
{
V_1 ^= ( V_1 >> 16 ) ;
V_1 ^= ( V_1 >> 8 ) ;
return V_1 % V_2 ;
}
static int F_2 ( struct V_3 * V_4 , const struct V_5 * V_6 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 = F_3 ( V_6 -> V_11 ) ;
struct V_12 * V_13 ;
int V_14 ;
T_1 V_15 = V_4 -> V_16 ;
if ( V_10 != NULL ) {
V_15 &= V_10 -> V_17 ;
for ( V_13 = F_3 ( V_10 -> V_18 [ F_1 ( V_15 ) ] ) ; V_13 ;
V_13 = F_3 ( V_13 -> V_19 ) ) {
if ( V_13 -> V_15 == V_15 ) {
* V_8 = V_13 -> V_8 ;
#ifdef F_4
if ( ! F_5 ( V_4 , V_13 -> V_20 ) )
continue;
#endif
V_14 = F_6 ( V_4 , & V_13 -> V_21 , V_8 ) ;
if ( V_14 < 0 )
continue;
return V_14 ;
}
}
} else {
if ( V_15 && ( F_7 ( V_15 ) == 0 ||
! ( F_7 ( V_15 ^ V_6 -> V_22 -> V_1 ) ) ) ) {
V_8 -> V_23 = V_15 ;
V_8 -> V_24 = 0 ;
return 0 ;
}
}
return - 1 ;
}
static unsigned long F_8 ( struct V_5 * V_6 , T_1 V_1 )
{
struct V_9 * V_10 = F_9 ( V_6 -> V_11 ) ;
struct V_12 * V_13 ;
if ( V_10 == NULL )
return 0 ;
V_13 = F_9 ( V_10 -> V_18 [ F_1 ( V_1 ) ] ) ;
for (; V_13 ; V_13 = F_9 ( V_13 -> V_19 ) ) {
if ( V_13 -> V_15 == V_1 )
return ( unsigned long ) V_13 ;
}
return 0 ;
}
static int F_10 ( struct V_5 * V_6 )
{
return 0 ;
}
static void F_11 ( struct V_25 * V_10 )
{
struct V_12 * V_13 = F_12 ( V_10 , struct V_12 , V_26 ) ;
F_13 ( & V_13 -> V_21 ) ;
F_14 ( V_13 ) ;
}
static void F_15 ( struct V_5 * V_6 )
{
struct V_9 * V_10 = F_9 ( V_6 -> V_11 ) ;
struct V_12 * V_13 ;
int V_27 ;
if ( V_10 == NULL )
return;
for ( V_27 = 0 ; V_27 < V_2 ; V_27 ++ ) {
while ( ( V_13 = F_9 ( V_10 -> V_18 [ V_27 ] ) ) != NULL ) {
F_16 ( V_10 -> V_18 [ V_27 ] ,
F_9 ( V_13 -> V_19 ) ) ;
F_17 ( V_6 , & V_13 -> V_8 ) ;
F_18 ( & V_13 -> V_26 , F_11 ) ;
}
}
F_16 ( V_6 -> V_11 , NULL ) ;
F_19 ( V_10 , V_26 ) ;
}
static int F_20 ( struct V_5 * V_6 , unsigned long V_28 )
{
struct V_9 * V_10 = F_9 ( V_6 -> V_11 ) ;
struct V_12 * V_13 = (struct V_12 * ) V_28 ;
struct V_12 T_2 * * V_29 ;
struct V_12 * V_30 ;
if ( V_10 == NULL || V_13 == NULL )
goto V_31;
V_29 = & V_10 -> V_18 [ F_1 ( V_13 -> V_15 ) ] ;
for ( V_30 = F_9 ( * V_29 ) ; V_30 ;
V_29 = & V_30 -> V_19 , V_30 = F_9 ( * V_29 ) ) {
if ( V_30 == V_13 ) {
F_16 ( * V_29 , F_9 ( V_13 -> V_19 ) ) ;
F_17 ( V_6 , & V_13 -> V_8 ) ;
F_18 ( & V_13 -> V_26 , F_11 ) ;
return 0 ;
}
}
V_31:
return - V_32 ;
}
static int
F_21 ( struct V_33 * V_33 , struct V_5 * V_6 , struct V_12 * V_13 ,
struct V_34 * * V_35 , struct V_34 * * V_36 , unsigned long V_37 , bool V_38 )
{
struct V_9 * V_10 = F_9 ( V_6 -> V_11 ) ;
struct V_39 V_40 ;
T_1 V_17 ;
int V_41 ;
F_22 ( & V_40 , V_42 , V_43 ) ;
V_41 = F_23 ( V_33 , V_6 , V_35 , V_36 [ V_44 ] , & V_40 , V_38 ) ;
if ( V_41 < 0 )
return V_41 ;
if ( V_35 [ V_45 ] ) {
V_13 -> V_8 . V_23 = F_24 ( V_35 [ V_45 ] ) ;
F_25 ( V_6 , & V_13 -> V_8 , V_37 ) ;
}
#ifdef F_4
if ( V_35 [ V_46 ] ) {
int V_47 ;
V_47 = F_26 ( V_33 , V_35 [ V_46 ] ) ;
if ( V_47 < 0 ) {
V_41 = V_47 ;
goto V_48;
}
V_13 -> V_20 = V_47 ;
}
#endif
V_41 = - V_32 ;
if ( V_35 [ V_49 ] ) {
V_17 = F_24 ( V_35 [ V_49 ] ) ;
if ( V_17 != V_10 -> V_17 )
goto V_48;
} else if ( V_10 -> V_17 != 0xFFFFFFFF )
goto V_48;
F_27 ( V_6 , & V_13 -> V_21 , & V_40 ) ;
return 0 ;
V_48:
F_13 ( & V_40 ) ;
return V_41 ;
}
static int F_28 ( struct V_33 * V_33 , struct V_3 * V_50 ,
struct V_5 * V_6 , unsigned long V_37 ,
T_1 V_1 ,
struct V_34 * * V_36 ,
unsigned long * V_28 , bool V_38 )
{
struct V_9 * V_10 = F_9 ( V_6 -> V_11 ) ;
struct V_12 * V_13 = (struct V_12 * ) * V_28 ;
struct V_34 * V_51 = V_36 [ V_52 ] ;
struct V_34 * V_35 [ V_53 + 1 ] ;
int V_41 ;
if ( ! V_51 )
return V_1 ? - V_32 : 0 ;
V_41 = F_29 ( V_35 , V_53 , V_51 , V_54 ) ;
if ( V_41 < 0 )
return V_41 ;
if ( V_13 ) {
struct V_12 * V_30 , * V_55 ;
struct V_12 T_2 * * V_29 ;
if ( V_13 -> V_15 != V_1 && V_1 )
return - V_32 ;
V_55 = F_30 ( sizeof( struct V_12 ) , V_56 ) ;
if ( ! V_55 )
return - V_57 ;
V_55 -> V_15 = V_13 -> V_15 ;
V_55 -> V_8 = V_13 -> V_8 ;
#ifdef F_4
V_55 -> V_20 = V_13 -> V_20 ;
#endif
V_55 -> V_6 = V_13 -> V_6 ;
F_22 ( & V_55 -> V_21 , V_42 , V_43 ) ;
V_41 = F_21 ( V_33 , V_6 , V_55 , V_35 , V_36 , V_37 , V_38 ) ;
if ( V_41 < 0 ) {
F_14 ( V_55 ) ;
return V_41 ;
}
V_29 = & V_10 -> V_18 [ F_1 ( V_55 -> V_15 ) ] ;
for ( V_30 = F_9 ( * V_29 ) ; V_30 ;
V_29 = & V_30 -> V_19 , V_30 = F_9 ( * V_29 ) )
if ( V_30 == V_13 )
break;
F_16 ( V_55 -> V_19 , F_9 ( V_30 -> V_19 ) ) ;
F_31 ( * V_29 , V_55 ) ;
F_17 ( V_6 , & V_13 -> V_8 ) ;
F_18 ( & V_13 -> V_26 , F_11 ) ;
* V_28 = ( unsigned long ) V_55 ;
return V_41 ;
}
if ( ! V_1 )
return - V_32 ;
if ( V_10 == NULL ) {
T_1 V_17 = 0xFFFFFFFF ;
if ( V_35 [ V_49 ] )
V_17 = F_24 ( V_35 [ V_49 ] ) ;
V_10 = F_30 ( sizeof( struct V_9 ) , V_56 ) ;
if ( V_10 == NULL )
return - V_57 ;
V_10 -> V_17 = V_17 ;
F_31 ( V_6 -> V_11 , V_10 ) ;
}
V_13 = F_30 ( sizeof( struct V_12 ) , V_56 ) ;
if ( V_13 == NULL )
return - V_57 ;
F_22 ( & V_13 -> V_21 , V_42 , V_43 ) ;
V_13 -> V_15 = V_1 ;
V_13 -> V_6 = V_6 ;
V_41 = F_21 ( V_33 , V_6 , V_13 , V_35 , V_36 , V_37 , V_38 ) ;
if ( V_41 < 0 )
goto V_48;
F_16 ( V_13 -> V_19 , V_10 -> V_18 [ F_1 ( V_1 ) ] ) ;
F_31 ( V_10 -> V_18 [ F_1 ( V_1 ) ] , V_13 ) ;
* V_28 = ( unsigned long ) V_13 ;
return 0 ;
V_48:
F_14 ( V_13 ) ;
return V_41 ;
}
static void F_32 ( struct V_5 * V_6 , struct V_58 * V_28 )
{
struct V_9 * V_10 = F_9 ( V_6 -> V_11 ) ;
int V_27 ;
if ( V_10 == NULL )
V_28 -> V_59 = 1 ;
if ( V_28 -> V_59 )
return;
for ( V_27 = 0 ; V_27 < V_2 ; V_27 ++ ) {
struct V_12 * V_13 ;
for ( V_13 = F_9 ( V_10 -> V_18 [ V_27 ] ) ; V_13 ;
V_13 = F_9 ( V_13 -> V_19 ) ) {
if ( V_28 -> V_60 < V_28 -> V_61 ) {
V_28 -> V_60 ++ ;
continue;
}
if ( V_28 -> V_62 ( V_6 , ( unsigned long ) V_13 , V_28 ) < 0 ) {
V_28 -> V_59 = 1 ;
return;
}
V_28 -> V_60 ++ ;
}
}
}
static int F_33 ( struct V_33 * V_33 , struct V_5 * V_6 , unsigned long V_63 ,
struct V_3 * V_4 , struct V_64 * V_65 )
{
struct V_9 * V_10 = F_9 ( V_6 -> V_11 ) ;
struct V_12 * V_13 = (struct V_12 * ) V_63 ;
struct V_34 * V_66 ;
if ( V_13 == NULL )
return V_4 -> V_67 ;
V_65 -> V_68 = V_13 -> V_15 ;
if ( ! V_13 -> V_8 . V_23 && ! F_34 ( & V_13 -> V_21 ) )
return V_4 -> V_67 ;
V_66 = F_35 ( V_4 , V_52 ) ;
if ( V_66 == NULL )
goto V_69;
if ( V_13 -> V_8 . V_23 &&
F_36 ( V_4 , V_45 , V_13 -> V_8 . V_23 ) )
goto V_69;
#ifdef F_4
if ( V_13 -> V_20 ) {
struct V_70 * V_71 ;
V_71 = F_37 ( V_33 , V_13 -> V_20 ) ;
if ( V_71 && F_38 ( V_4 , V_46 , V_71 -> V_72 ) )
goto V_69;
}
#endif
if ( V_10 -> V_17 != 0xFFFFFFFF &&
F_36 ( V_4 , V_49 , V_10 -> V_17 ) )
goto V_69;
if ( F_39 ( V_4 , & V_13 -> V_21 ) < 0 )
goto V_69;
F_40 ( V_4 , V_66 ) ;
if ( F_41 ( V_4 , & V_13 -> V_21 ) < 0 )
goto V_69;
return V_4 -> V_67 ;
V_69:
F_42 ( V_4 , V_66 ) ;
return - 1 ;
}
static int T_3 F_43 ( void )
{
return F_44 ( & V_73 ) ;
}
static void T_4 F_45 ( void )
{
F_46 ( & V_73 ) ;
}
