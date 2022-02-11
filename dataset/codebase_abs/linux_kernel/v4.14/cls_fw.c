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
static void * F_8 ( struct V_5 * V_6 , T_1 V_1 )
{
struct V_9 * V_10 = F_9 ( V_6 -> V_11 ) ;
struct V_12 * V_13 ;
if ( V_10 == NULL )
return NULL ;
V_13 = F_9 ( V_10 -> V_18 [ F_1 ( V_1 ) ] ) ;
for (; V_13 ; V_13 = F_9 ( V_13 -> V_19 ) ) {
if ( V_13 -> V_15 == V_1 )
return V_13 ;
}
return NULL ;
}
static int F_10 ( struct V_5 * V_6 )
{
return 0 ;
}
static void F_11 ( struct V_12 * V_13 )
{
F_12 ( & V_13 -> V_21 ) ;
F_13 ( & V_13 -> V_21 ) ;
F_14 ( V_13 ) ;
}
static void F_15 ( struct V_25 * V_26 )
{
struct V_12 * V_13 = F_16 ( V_26 , struct V_12 , V_26 ) ;
F_17 () ;
F_11 ( V_13 ) ;
F_18 () ;
}
static void F_19 ( struct V_27 * V_10 )
{
struct V_12 * V_13 = F_16 ( V_10 , struct V_12 , V_28 ) ;
F_20 ( & V_13 -> V_26 , F_15 ) ;
F_21 ( & V_13 -> V_26 ) ;
}
static void F_22 ( struct V_5 * V_6 )
{
struct V_9 * V_10 = F_9 ( V_6 -> V_11 ) ;
struct V_12 * V_13 ;
int V_29 ;
if ( V_10 == NULL )
return;
for ( V_29 = 0 ; V_29 < V_2 ; V_29 ++ ) {
while ( ( V_13 = F_9 ( V_10 -> V_18 [ V_29 ] ) ) != NULL ) {
F_23 ( V_10 -> V_18 [ V_29 ] ,
F_9 ( V_13 -> V_19 ) ) ;
F_24 ( V_6 , & V_13 -> V_8 ) ;
if ( F_25 ( & V_13 -> V_21 ) )
F_26 ( & V_13 -> V_28 , F_19 ) ;
else
F_11 ( V_13 ) ;
}
}
F_27 ( V_10 , V_28 ) ;
}
static int F_28 ( struct V_5 * V_6 , void * V_30 , bool * V_31 )
{
struct V_9 * V_10 = F_9 ( V_6 -> V_11 ) ;
struct V_12 * V_13 = V_30 ;
struct V_12 T_2 * * V_32 ;
struct V_12 * V_33 ;
int V_34 = - V_35 ;
int V_29 ;
if ( V_10 == NULL || V_13 == NULL )
goto V_36;
V_32 = & V_10 -> V_18 [ F_1 ( V_13 -> V_15 ) ] ;
for ( V_33 = F_9 ( * V_32 ) ; V_33 ;
V_32 = & V_33 -> V_19 , V_33 = F_9 ( * V_32 ) ) {
if ( V_33 == V_13 ) {
F_23 ( * V_32 , F_9 ( V_13 -> V_19 ) ) ;
F_24 ( V_6 , & V_13 -> V_8 ) ;
F_25 ( & V_13 -> V_21 ) ;
F_26 ( & V_13 -> V_28 , F_19 ) ;
V_34 = 0 ;
break;
}
}
* V_31 = true ;
for ( V_29 = 0 ; V_29 < V_2 ; V_29 ++ ) {
if ( F_29 ( V_10 -> V_18 [ V_29 ] ) ) {
* V_31 = false ;
break;
}
}
V_36:
return V_34 ;
}
static int F_30 ( struct V_37 * V_37 , struct V_5 * V_6 ,
struct V_12 * V_13 , struct V_38 * * V_39 ,
struct V_38 * * V_40 , unsigned long V_41 , bool V_42 )
{
struct V_9 * V_10 = F_9 ( V_6 -> V_11 ) ;
T_1 V_17 ;
int V_43 ;
V_43 = F_31 ( V_37 , V_6 , V_39 , V_40 [ V_44 ] , & V_13 -> V_21 , V_42 ) ;
if ( V_43 < 0 )
return V_43 ;
if ( V_39 [ V_45 ] ) {
V_13 -> V_8 . V_23 = F_32 ( V_39 [ V_45 ] ) ;
F_33 ( V_6 , & V_13 -> V_8 , V_41 ) ;
}
#ifdef F_4
if ( V_39 [ V_46 ] ) {
int V_34 ;
V_34 = F_34 ( V_37 , V_39 [ V_46 ] ) ;
if ( V_34 < 0 )
return V_34 ;
V_13 -> V_20 = V_34 ;
}
#endif
V_43 = - V_35 ;
if ( V_39 [ V_47 ] ) {
V_17 = F_32 ( V_39 [ V_47 ] ) ;
if ( V_17 != V_10 -> V_17 )
return V_43 ;
} else if ( V_10 -> V_17 != 0xFFFFFFFF )
return V_43 ;
return 0 ;
}
static int F_35 ( struct V_37 * V_37 , struct V_3 * V_48 ,
struct V_5 * V_6 , unsigned long V_41 ,
T_1 V_1 , struct V_38 * * V_40 , void * * V_30 ,
bool V_42 )
{
struct V_9 * V_10 = F_9 ( V_6 -> V_11 ) ;
struct V_12 * V_13 = * V_30 ;
struct V_38 * V_49 = V_40 [ V_50 ] ;
struct V_38 * V_39 [ V_51 + 1 ] ;
int V_43 ;
if ( ! V_49 )
return V_1 ? - V_35 : 0 ;
V_43 = F_36 ( V_39 , V_51 , V_49 , V_52 , NULL ) ;
if ( V_43 < 0 )
return V_43 ;
if ( V_13 ) {
struct V_12 * V_33 , * V_53 ;
struct V_12 T_2 * * V_32 ;
if ( V_13 -> V_15 != V_1 && V_1 )
return - V_35 ;
V_53 = F_37 ( sizeof( struct V_12 ) , V_54 ) ;
if ( ! V_53 )
return - V_55 ;
V_53 -> V_15 = V_13 -> V_15 ;
V_53 -> V_8 = V_13 -> V_8 ;
#ifdef F_4
V_53 -> V_20 = V_13 -> V_20 ;
#endif
V_53 -> V_6 = V_13 -> V_6 ;
V_43 = F_38 ( & V_53 -> V_21 , V_56 , V_57 ) ;
if ( V_43 < 0 ) {
F_14 ( V_53 ) ;
return V_43 ;
}
V_43 = F_30 ( V_37 , V_6 , V_53 , V_39 , V_40 , V_41 , V_42 ) ;
if ( V_43 < 0 ) {
F_12 ( & V_53 -> V_21 ) ;
F_14 ( V_53 ) ;
return V_43 ;
}
V_32 = & V_10 -> V_18 [ F_1 ( V_53 -> V_15 ) ] ;
for ( V_33 = F_9 ( * V_32 ) ; V_33 ;
V_32 = & V_33 -> V_19 , V_33 = F_9 ( * V_32 ) )
if ( V_33 == V_13 )
break;
F_23 ( V_53 -> V_19 , F_9 ( V_33 -> V_19 ) ) ;
F_39 ( * V_32 , V_53 ) ;
F_24 ( V_6 , & V_13 -> V_8 ) ;
F_25 ( & V_13 -> V_21 ) ;
F_26 ( & V_13 -> V_28 , F_19 ) ;
* V_30 = V_53 ;
return V_43 ;
}
if ( ! V_1 )
return - V_35 ;
if ( ! V_10 ) {
T_1 V_17 = 0xFFFFFFFF ;
if ( V_39 [ V_47 ] )
V_17 = F_32 ( V_39 [ V_47 ] ) ;
V_10 = F_37 ( sizeof( * V_10 ) , V_54 ) ;
if ( ! V_10 )
return - V_55 ;
V_10 -> V_17 = V_17 ;
F_39 ( V_6 -> V_11 , V_10 ) ;
}
V_13 = F_37 ( sizeof( struct V_12 ) , V_54 ) ;
if ( V_13 == NULL )
return - V_55 ;
V_43 = F_38 ( & V_13 -> V_21 , V_56 , V_57 ) ;
if ( V_43 < 0 )
goto V_58;
V_13 -> V_15 = V_1 ;
V_13 -> V_6 = V_6 ;
V_43 = F_30 ( V_37 , V_6 , V_13 , V_39 , V_40 , V_41 , V_42 ) ;
if ( V_43 < 0 )
goto V_58;
F_23 ( V_13 -> V_19 , V_10 -> V_18 [ F_1 ( V_1 ) ] ) ;
F_39 ( V_10 -> V_18 [ F_1 ( V_1 ) ] , V_13 ) ;
* V_30 = V_13 ;
return 0 ;
V_58:
F_12 ( & V_13 -> V_21 ) ;
F_14 ( V_13 ) ;
return V_43 ;
}
static void F_40 ( struct V_5 * V_6 , struct V_59 * V_30 )
{
struct V_9 * V_10 = F_9 ( V_6 -> V_11 ) ;
int V_29 ;
if ( V_10 == NULL )
V_30 -> V_60 = 1 ;
if ( V_30 -> V_60 )
return;
for ( V_29 = 0 ; V_29 < V_2 ; V_29 ++ ) {
struct V_12 * V_13 ;
for ( V_13 = F_9 ( V_10 -> V_18 [ V_29 ] ) ; V_13 ;
V_13 = F_9 ( V_13 -> V_19 ) ) {
if ( V_30 -> V_61 < V_30 -> V_62 ) {
V_30 -> V_61 ++ ;
continue;
}
if ( V_30 -> V_63 ( V_6 , V_13 , V_30 ) < 0 ) {
V_30 -> V_60 = 1 ;
return;
}
V_30 -> V_61 ++ ;
}
}
}
static int F_41 ( struct V_37 * V_37 , struct V_5 * V_6 , void * V_64 ,
struct V_3 * V_4 , struct V_65 * V_66 )
{
struct V_9 * V_10 = F_9 ( V_6 -> V_11 ) ;
struct V_12 * V_13 = V_64 ;
struct V_38 * V_67 ;
if ( V_13 == NULL )
return V_4 -> V_68 ;
V_66 -> V_69 = V_13 -> V_15 ;
if ( ! V_13 -> V_8 . V_23 && ! F_42 ( & V_13 -> V_21 ) )
return V_4 -> V_68 ;
V_67 = F_43 ( V_4 , V_50 ) ;
if ( V_67 == NULL )
goto V_70;
if ( V_13 -> V_8 . V_23 &&
F_44 ( V_4 , V_45 , V_13 -> V_8 . V_23 ) )
goto V_70;
#ifdef F_4
if ( V_13 -> V_20 ) {
struct V_71 * V_72 ;
V_72 = F_45 ( V_37 , V_13 -> V_20 ) ;
if ( V_72 && F_46 ( V_4 , V_46 , V_72 -> V_73 ) )
goto V_70;
}
#endif
if ( V_10 -> V_17 != 0xFFFFFFFF &&
F_44 ( V_4 , V_47 , V_10 -> V_17 ) )
goto V_70;
if ( F_47 ( V_4 , & V_13 -> V_21 ) < 0 )
goto V_70;
F_48 ( V_4 , V_67 ) ;
if ( F_49 ( V_4 , & V_13 -> V_21 ) < 0 )
goto V_70;
return V_4 -> V_68 ;
V_70:
F_50 ( V_4 , V_67 ) ;
return - 1 ;
}
static void F_51 ( void * V_64 , T_1 V_23 , unsigned long V_74 )
{
struct V_12 * V_13 = V_64 ;
if ( V_13 && V_13 -> V_8 . V_23 == V_23 )
V_13 -> V_8 . V_24 = V_74 ;
}
static int T_3 F_52 ( void )
{
return F_53 ( & V_75 ) ;
}
static void T_4 F_54 ( void )
{
F_55 ( & V_75 ) ;
}
