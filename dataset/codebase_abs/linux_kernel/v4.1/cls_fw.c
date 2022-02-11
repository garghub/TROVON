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
struct V_9 * V_10 ;
V_10 = F_11 ( sizeof( struct V_9 ) , V_25 ) ;
if ( V_10 == NULL )
return - V_26 ;
V_10 -> V_27 = false ;
F_12 ( V_6 -> V_11 , V_10 ) ;
return 0 ;
}
static void F_13 ( struct V_28 * V_10 )
{
struct V_12 * V_13 = F_14 ( V_10 , struct V_12 , V_29 ) ;
F_15 ( & V_13 -> V_21 ) ;
F_16 ( V_13 ) ;
}
static bool F_17 ( struct V_5 * V_6 , bool V_30 )
{
struct V_9 * V_10 = F_9 ( V_6 -> V_11 ) ;
struct V_12 * V_13 ;
int V_31 ;
if ( V_10 == NULL )
return true ;
if ( ! V_30 ) {
for ( V_31 = 0 ; V_31 < V_2 ; V_31 ++ )
if ( F_18 ( V_10 -> V_18 [ V_31 ] ) )
return false ;
}
for ( V_31 = 0 ; V_31 < V_2 ; V_31 ++ ) {
while ( ( V_13 = F_9 ( V_10 -> V_18 [ V_31 ] ) ) != NULL ) {
F_19 ( V_10 -> V_18 [ V_31 ] ,
F_9 ( V_13 -> V_19 ) ) ;
F_20 ( V_6 , & V_13 -> V_8 ) ;
F_21 ( & V_13 -> V_29 , F_13 ) ;
}
}
F_19 ( V_6 -> V_11 , NULL ) ;
F_22 ( V_10 , V_29 ) ;
return true ;
}
static int F_23 ( struct V_5 * V_6 , unsigned long V_32 )
{
struct V_9 * V_10 = F_9 ( V_6 -> V_11 ) ;
struct V_12 * V_13 = (struct V_12 * ) V_32 ;
struct V_12 T_2 * * V_33 ;
struct V_12 * V_34 ;
if ( V_10 == NULL || V_13 == NULL )
goto V_35;
V_33 = & V_10 -> V_18 [ F_1 ( V_13 -> V_15 ) ] ;
for ( V_34 = F_9 ( * V_33 ) ; V_34 ;
V_33 = & V_34 -> V_19 , V_34 = F_9 ( * V_33 ) ) {
if ( V_34 == V_13 ) {
F_19 ( * V_33 , F_9 ( V_13 -> V_19 ) ) ;
F_20 ( V_6 , & V_13 -> V_8 ) ;
F_21 ( & V_13 -> V_29 , F_13 ) ;
return 0 ;
}
}
V_35:
return - V_36 ;
}
static int
F_24 ( struct V_37 * V_37 , struct V_5 * V_6 , struct V_12 * V_13 ,
struct V_38 * * V_39 , struct V_38 * * V_40 , unsigned long V_41 , bool V_42 )
{
struct V_9 * V_10 = F_9 ( V_6 -> V_11 ) ;
struct V_43 V_44 ;
T_1 V_17 ;
int V_45 ;
F_25 ( & V_44 , V_46 , V_47 ) ;
V_45 = F_26 ( V_37 , V_6 , V_39 , V_40 [ V_48 ] , & V_44 , V_42 ) ;
if ( V_45 < 0 )
return V_45 ;
if ( V_39 [ V_49 ] ) {
V_13 -> V_8 . V_23 = F_27 ( V_39 [ V_49 ] ) ;
F_28 ( V_6 , & V_13 -> V_8 , V_41 ) ;
}
#ifdef F_4
if ( V_39 [ V_50 ] ) {
int V_51 ;
V_51 = F_29 ( V_37 , V_39 [ V_50 ] ) ;
if ( V_51 < 0 ) {
V_45 = V_51 ;
goto V_52;
}
V_13 -> V_20 = V_51 ;
}
#endif
V_45 = - V_36 ;
if ( V_39 [ V_53 ] ) {
V_17 = F_27 ( V_39 [ V_53 ] ) ;
if ( V_17 != V_10 -> V_17 )
goto V_52;
} else if ( V_10 -> V_17 != 0xFFFFFFFF )
goto V_52;
F_30 ( V_6 , & V_13 -> V_21 , & V_44 ) ;
return 0 ;
V_52:
F_15 ( & V_44 ) ;
return V_45 ;
}
static int F_31 ( struct V_37 * V_37 , struct V_3 * V_54 ,
struct V_5 * V_6 , unsigned long V_41 ,
T_1 V_1 ,
struct V_38 * * V_40 ,
unsigned long * V_32 , bool V_42 )
{
struct V_9 * V_10 = F_9 ( V_6 -> V_11 ) ;
struct V_12 * V_13 = (struct V_12 * ) * V_32 ;
struct V_38 * V_55 = V_40 [ V_56 ] ;
struct V_38 * V_39 [ V_57 + 1 ] ;
int V_45 ;
if ( ! V_55 )
return V_1 ? - V_36 : 0 ;
V_45 = F_32 ( V_39 , V_57 , V_55 , V_58 ) ;
if ( V_45 < 0 )
return V_45 ;
if ( V_13 ) {
struct V_12 * V_34 , * V_59 ;
struct V_12 T_2 * * V_33 ;
if ( V_13 -> V_15 != V_1 && V_1 )
return - V_36 ;
V_59 = F_11 ( sizeof( struct V_12 ) , V_25 ) ;
if ( ! V_59 )
return - V_26 ;
V_59 -> V_15 = V_13 -> V_15 ;
V_59 -> V_8 = V_13 -> V_8 ;
#ifdef F_4
V_59 -> V_20 = V_13 -> V_20 ;
#endif
V_59 -> V_6 = V_13 -> V_6 ;
F_25 ( & V_59 -> V_21 , V_46 , V_47 ) ;
V_45 = F_24 ( V_37 , V_6 , V_59 , V_39 , V_40 , V_41 , V_42 ) ;
if ( V_45 < 0 ) {
F_16 ( V_59 ) ;
return V_45 ;
}
V_33 = & V_10 -> V_18 [ F_1 ( V_59 -> V_15 ) ] ;
for ( V_34 = F_9 ( * V_33 ) ; V_34 ;
V_33 = & V_34 -> V_19 , V_34 = F_9 ( * V_33 ) )
if ( V_34 == V_13 )
break;
F_19 ( V_59 -> V_19 , F_9 ( V_34 -> V_19 ) ) ;
F_12 ( * V_33 , V_59 ) ;
F_20 ( V_6 , & V_13 -> V_8 ) ;
F_21 ( & V_13 -> V_29 , F_13 ) ;
* V_32 = ( unsigned long ) V_59 ;
return V_45 ;
}
if ( ! V_1 )
return - V_36 ;
if ( ! V_10 -> V_27 ) {
V_10 -> V_17 = 0xFFFFFFFF ;
if ( V_39 [ V_53 ] )
V_10 -> V_17 = F_27 ( V_39 [ V_53 ] ) ;
V_10 -> V_27 = true ;
}
V_13 = F_11 ( sizeof( struct V_12 ) , V_25 ) ;
if ( V_13 == NULL )
return - V_26 ;
F_25 ( & V_13 -> V_21 , V_46 , V_47 ) ;
V_13 -> V_15 = V_1 ;
V_13 -> V_6 = V_6 ;
V_45 = F_24 ( V_37 , V_6 , V_13 , V_39 , V_40 , V_41 , V_42 ) ;
if ( V_45 < 0 )
goto V_52;
F_19 ( V_13 -> V_19 , V_10 -> V_18 [ F_1 ( V_1 ) ] ) ;
F_12 ( V_10 -> V_18 [ F_1 ( V_1 ) ] , V_13 ) ;
* V_32 = ( unsigned long ) V_13 ;
return 0 ;
V_52:
F_16 ( V_13 ) ;
return V_45 ;
}
static void F_33 ( struct V_5 * V_6 , struct V_60 * V_32 )
{
struct V_9 * V_10 = F_9 ( V_6 -> V_11 ) ;
int V_31 ;
if ( V_10 == NULL )
V_32 -> V_61 = 1 ;
if ( V_32 -> V_61 )
return;
for ( V_31 = 0 ; V_31 < V_2 ; V_31 ++ ) {
struct V_12 * V_13 ;
for ( V_13 = F_9 ( V_10 -> V_18 [ V_31 ] ) ; V_13 ;
V_13 = F_9 ( V_13 -> V_19 ) ) {
if ( V_32 -> V_62 < V_32 -> V_63 ) {
V_32 -> V_62 ++ ;
continue;
}
if ( V_32 -> V_64 ( V_6 , ( unsigned long ) V_13 , V_32 ) < 0 ) {
V_32 -> V_61 = 1 ;
return;
}
V_32 -> V_62 ++ ;
}
}
}
static int F_34 ( struct V_37 * V_37 , struct V_5 * V_6 , unsigned long V_65 ,
struct V_3 * V_4 , struct V_66 * V_67 )
{
struct V_9 * V_10 = F_9 ( V_6 -> V_11 ) ;
struct V_12 * V_13 = (struct V_12 * ) V_65 ;
struct V_38 * V_68 ;
if ( V_13 == NULL )
return V_4 -> V_69 ;
V_67 -> V_70 = V_13 -> V_15 ;
if ( ! V_13 -> V_8 . V_23 && ! F_35 ( & V_13 -> V_21 ) )
return V_4 -> V_69 ;
V_68 = F_36 ( V_4 , V_56 ) ;
if ( V_68 == NULL )
goto V_71;
if ( V_13 -> V_8 . V_23 &&
F_37 ( V_4 , V_49 , V_13 -> V_8 . V_23 ) )
goto V_71;
#ifdef F_4
if ( V_13 -> V_20 ) {
struct V_72 * V_73 ;
V_73 = F_38 ( V_37 , V_13 -> V_20 ) ;
if ( V_73 && F_39 ( V_4 , V_50 , V_73 -> V_74 ) )
goto V_71;
}
#endif
if ( V_10 -> V_17 != 0xFFFFFFFF &&
F_37 ( V_4 , V_53 , V_10 -> V_17 ) )
goto V_71;
if ( F_40 ( V_4 , & V_13 -> V_21 ) < 0 )
goto V_71;
F_41 ( V_4 , V_68 ) ;
if ( F_42 ( V_4 , & V_13 -> V_21 ) < 0 )
goto V_71;
return V_4 -> V_69 ;
V_71:
F_43 ( V_4 , V_68 ) ;
return - 1 ;
}
static int T_3 F_44 ( void )
{
return F_45 ( & V_75 ) ;
}
static void T_4 F_46 ( void )
{
F_47 ( & V_75 ) ;
}
