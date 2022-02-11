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
F_19 ( V_10 , V_26 ) ;
}
static int F_20 ( struct V_5 * V_6 , unsigned long V_28 , bool * V_29 )
{
struct V_9 * V_10 = F_9 ( V_6 -> V_11 ) ;
struct V_12 * V_13 = (struct V_12 * ) V_28 ;
struct V_12 T_2 * * V_30 ;
struct V_12 * V_31 ;
int V_32 = - V_33 ;
int V_27 ;
if ( V_10 == NULL || V_13 == NULL )
goto V_34;
V_30 = & V_10 -> V_18 [ F_1 ( V_13 -> V_15 ) ] ;
for ( V_31 = F_9 ( * V_30 ) ; V_31 ;
V_30 = & V_31 -> V_19 , V_31 = F_9 ( * V_30 ) ) {
if ( V_31 == V_13 ) {
F_16 ( * V_30 , F_9 ( V_13 -> V_19 ) ) ;
F_17 ( V_6 , & V_13 -> V_8 ) ;
F_18 ( & V_13 -> V_26 , F_11 ) ;
V_32 = 0 ;
break;
}
}
* V_29 = true ;
for ( V_27 = 0 ; V_27 < V_2 ; V_27 ++ ) {
if ( F_21 ( V_10 -> V_18 [ V_27 ] ) ) {
* V_29 = false ;
break;
}
}
V_34:
return V_32 ;
}
static int
F_22 ( struct V_35 * V_35 , struct V_5 * V_6 , struct V_12 * V_13 ,
struct V_36 * * V_37 , struct V_36 * * V_38 , unsigned long V_39 ,
bool V_40 )
{
struct V_9 * V_10 = F_9 ( V_6 -> V_11 ) ;
struct V_41 V_42 ;
T_1 V_17 ;
int V_43 ;
V_43 = F_23 ( & V_42 , V_44 , V_45 ) ;
if ( V_43 < 0 )
return V_43 ;
V_43 = F_24 ( V_35 , V_6 , V_37 , V_38 [ V_46 ] , & V_42 , V_40 ) ;
if ( V_43 < 0 )
goto V_47;
if ( V_37 [ V_48 ] ) {
V_13 -> V_8 . V_23 = F_25 ( V_37 [ V_48 ] ) ;
F_26 ( V_6 , & V_13 -> V_8 , V_39 ) ;
}
#ifdef F_4
if ( V_37 [ V_49 ] ) {
int V_32 ;
V_32 = F_27 ( V_35 , V_37 [ V_49 ] ) ;
if ( V_32 < 0 ) {
V_43 = V_32 ;
goto V_47;
}
V_13 -> V_20 = V_32 ;
}
#endif
V_43 = - V_33 ;
if ( V_37 [ V_50 ] ) {
V_17 = F_25 ( V_37 [ V_50 ] ) ;
if ( V_17 != V_10 -> V_17 )
goto V_47;
} else if ( V_10 -> V_17 != 0xFFFFFFFF )
goto V_47;
F_28 ( V_6 , & V_13 -> V_21 , & V_42 ) ;
return 0 ;
V_47:
F_13 ( & V_42 ) ;
return V_43 ;
}
static int F_29 ( struct V_35 * V_35 , struct V_3 * V_51 ,
struct V_5 * V_6 , unsigned long V_39 ,
T_1 V_1 , struct V_36 * * V_38 , unsigned long * V_28 ,
bool V_40 )
{
struct V_9 * V_10 = F_9 ( V_6 -> V_11 ) ;
struct V_12 * V_13 = (struct V_12 * ) * V_28 ;
struct V_36 * V_52 = V_38 [ V_53 ] ;
struct V_36 * V_37 [ V_54 + 1 ] ;
int V_43 ;
if ( ! V_52 )
return V_1 ? - V_33 : 0 ;
V_43 = F_30 ( V_37 , V_54 , V_52 , V_55 , NULL ) ;
if ( V_43 < 0 )
return V_43 ;
if ( V_13 ) {
struct V_12 * V_31 , * V_56 ;
struct V_12 T_2 * * V_30 ;
if ( V_13 -> V_15 != V_1 && V_1 )
return - V_33 ;
V_56 = F_31 ( sizeof( struct V_12 ) , V_57 ) ;
if ( ! V_56 )
return - V_58 ;
V_56 -> V_15 = V_13 -> V_15 ;
V_56 -> V_8 = V_13 -> V_8 ;
#ifdef F_4
V_56 -> V_20 = V_13 -> V_20 ;
#endif
V_56 -> V_6 = V_13 -> V_6 ;
V_43 = F_23 ( & V_56 -> V_21 , V_44 , V_45 ) ;
if ( V_43 < 0 ) {
F_14 ( V_56 ) ;
return V_43 ;
}
V_43 = F_22 ( V_35 , V_6 , V_56 , V_37 , V_38 , V_39 , V_40 ) ;
if ( V_43 < 0 ) {
F_13 ( & V_56 -> V_21 ) ;
F_14 ( V_56 ) ;
return V_43 ;
}
V_30 = & V_10 -> V_18 [ F_1 ( V_56 -> V_15 ) ] ;
for ( V_31 = F_9 ( * V_30 ) ; V_31 ;
V_30 = & V_31 -> V_19 , V_31 = F_9 ( * V_30 ) )
if ( V_31 == V_13 )
break;
F_16 ( V_56 -> V_19 , F_9 ( V_31 -> V_19 ) ) ;
F_32 ( * V_30 , V_56 ) ;
F_17 ( V_6 , & V_13 -> V_8 ) ;
F_18 ( & V_13 -> V_26 , F_11 ) ;
* V_28 = ( unsigned long ) V_56 ;
return V_43 ;
}
if ( ! V_1 )
return - V_33 ;
if ( ! V_10 ) {
T_1 V_17 = 0xFFFFFFFF ;
if ( V_37 [ V_50 ] )
V_17 = F_25 ( V_37 [ V_50 ] ) ;
V_10 = F_31 ( sizeof( * V_10 ) , V_57 ) ;
if ( ! V_10 )
return - V_58 ;
V_10 -> V_17 = V_17 ;
F_32 ( V_6 -> V_11 , V_10 ) ;
}
V_13 = F_31 ( sizeof( struct V_12 ) , V_57 ) ;
if ( V_13 == NULL )
return - V_58 ;
V_43 = F_23 ( & V_13 -> V_21 , V_44 , V_45 ) ;
if ( V_43 < 0 )
goto V_47;
V_13 -> V_15 = V_1 ;
V_13 -> V_6 = V_6 ;
V_43 = F_22 ( V_35 , V_6 , V_13 , V_37 , V_38 , V_39 , V_40 ) ;
if ( V_43 < 0 )
goto V_47;
F_16 ( V_13 -> V_19 , V_10 -> V_18 [ F_1 ( V_1 ) ] ) ;
F_32 ( V_10 -> V_18 [ F_1 ( V_1 ) ] , V_13 ) ;
* V_28 = ( unsigned long ) V_13 ;
return 0 ;
V_47:
F_13 ( & V_13 -> V_21 ) ;
F_14 ( V_13 ) ;
return V_43 ;
}
static void F_33 ( struct V_5 * V_6 , struct V_59 * V_28 )
{
struct V_9 * V_10 = F_9 ( V_6 -> V_11 ) ;
int V_27 ;
if ( V_10 == NULL )
V_28 -> V_60 = 1 ;
if ( V_28 -> V_60 )
return;
for ( V_27 = 0 ; V_27 < V_2 ; V_27 ++ ) {
struct V_12 * V_13 ;
for ( V_13 = F_9 ( V_10 -> V_18 [ V_27 ] ) ; V_13 ;
V_13 = F_9 ( V_13 -> V_19 ) ) {
if ( V_28 -> V_61 < V_28 -> V_62 ) {
V_28 -> V_61 ++ ;
continue;
}
if ( V_28 -> V_63 ( V_6 , ( unsigned long ) V_13 , V_28 ) < 0 ) {
V_28 -> V_60 = 1 ;
return;
}
V_28 -> V_61 ++ ;
}
}
}
static int F_34 ( struct V_35 * V_35 , struct V_5 * V_6 , unsigned long V_64 ,
struct V_3 * V_4 , struct V_65 * V_66 )
{
struct V_9 * V_10 = F_9 ( V_6 -> V_11 ) ;
struct V_12 * V_13 = (struct V_12 * ) V_64 ;
struct V_36 * V_67 ;
if ( V_13 == NULL )
return V_4 -> V_68 ;
V_66 -> V_69 = V_13 -> V_15 ;
if ( ! V_13 -> V_8 . V_23 && ! F_35 ( & V_13 -> V_21 ) )
return V_4 -> V_68 ;
V_67 = F_36 ( V_4 , V_53 ) ;
if ( V_67 == NULL )
goto V_70;
if ( V_13 -> V_8 . V_23 &&
F_37 ( V_4 , V_48 , V_13 -> V_8 . V_23 ) )
goto V_70;
#ifdef F_4
if ( V_13 -> V_20 ) {
struct V_71 * V_72 ;
V_72 = F_38 ( V_35 , V_13 -> V_20 ) ;
if ( V_72 && F_39 ( V_4 , V_49 , V_72 -> V_73 ) )
goto V_70;
}
#endif
if ( V_10 -> V_17 != 0xFFFFFFFF &&
F_37 ( V_4 , V_50 , V_10 -> V_17 ) )
goto V_70;
if ( F_40 ( V_4 , & V_13 -> V_21 ) < 0 )
goto V_70;
F_41 ( V_4 , V_67 ) ;
if ( F_42 ( V_4 , & V_13 -> V_21 ) < 0 )
goto V_70;
return V_4 -> V_68 ;
V_70:
F_43 ( V_4 , V_67 ) ;
return - 1 ;
}
static int T_3 F_44 ( void )
{
return F_45 ( & V_74 ) ;
}
static void T_4 F_46 ( void )
{
F_47 ( & V_74 ) ;
}
