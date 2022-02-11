static void T_1 F_1 ( void )
{
int V_1 ;
F_2 ( L_1 , V_2 -> V_3 , V_2 -> V_4 ) ;
for ( V_1 = 0 ; V_1 < V_5 ; V_1 ++ ) {
struct V_6 * V_7 = & V_2 -> V_8 [ V_1 ] ;
F_2 ( L_2 ,
V_7 -> V_9 , V_7 -> V_10 , V_7 -> V_11 ) ;
F_2 ( L_3 ,
V_7 -> V_12 , V_7 -> V_13 ) ;
F_2 ( L_4 ,
V_7 -> V_14 , V_7 -> V_15 ) ;
F_2 ( L_5 , V_7 -> V_16 ) ;
F_2 ( L_6 , V_7 -> V_17 ) ;
}
}
static int F_3 ( struct V_18 * V_19 )
{
if ( V_19 -> V_3 != V_20 ) {
F_4 ( L_7 , V_19 , V_19 -> V_3 ) ;
return - V_21 ;
}
V_2 = V_19 ;
return 0 ;
}
void F_5 ( int V_22 )
{
int V_1 ;
V_23 = 0 ;
V_2 = NULL ;
for ( V_1 = 0 ; V_1 < V_5 ; V_1 ++ )
F_6 ( & V_24 [ V_1 ] . V_25 ) ;
}
void F_7 ( int V_22 )
{
int V_1 ;
V_23 = 1 ;
for ( V_1 = 0 ; V_1 < V_5 ; V_1 ++ )
F_6 ( & V_24 [ V_1 ] . V_25 ) ;
}
int F_8 ( int V_26 , int V_27 )
{
struct V_18 * * V_28 ;
struct V_6 * V_7 ;
enum V_29 V_4 ;
int V_30 = 0 ;
if ( V_26 >= V_5 ) {
F_9 ( V_31 L_8 ) ;
return - V_32 ;
}
if ( F_10 ( & V_24 [ V_26 ] . V_33 ) > 1 ) {
F_9 ( V_31 L_9 , V_26 ) ;
V_30 = - V_34 ;
goto V_35;
}
if ( V_2 == NULL ) {
V_28 = F_11 ( F_12 () ) ;
if ( V_28 == NULL ) {
if ( V_27 ) {
V_30 = F_13 (
V_24 [ V_26 ] . V_25 ,
( V_28 = F_11 ( F_12 () ) ) ) ;
if ( V_30 )
goto V_35;
} else {
F_9 ( L_10 ) ;
V_30 = - V_32 ;
goto V_35;
}
}
F_14 () ;
if ( * V_28 == NULL ) {
if ( V_27 ) {
F_15 ( V_36 ) ;
for (; ; ) {
F_16 (
& V_24 [ V_26 ] . V_25 ,
& V_36 , V_37 ) ;
F_14 () ;
if ( * V_28 != NULL )
break;
if ( ! F_17 ( V_38 ) ) {
F_18 () ;
continue;
}
V_30 = - V_39 ;
goto V_35;
}
F_19 ( & V_24 [ V_26 ] . V_25 ,
& V_36 ) ;
} else {
F_4 ( L_11 ) ;
V_30 = - V_32 ;
goto V_35;
}
}
if ( ( unsigned int ) * V_28 < V_40 ) {
F_20 ( L_12 ,
( int ) * V_28 ) ;
V_30 = - V_32 ;
goto V_35;
}
V_30 = F_3 ( * V_28 ) ;
if ( V_30 < 0 )
goto V_41;
}
V_7 = & V_2 -> V_8 [ V_26 ] ;
V_4 = F_21 ( & V_7 -> V_10 , V_42 ) ;
if ( V_4 == V_42 ) {
V_30 = - V_34 ;
goto V_35;
}
V_35:
F_22 () ;
F_23 ( & V_24 [ V_26 ] . V_33 ) ;
F_22 () ;
V_41:
return V_30 ;
}
int F_24 ( int V_26 )
{
if ( V_2 == NULL ) {
F_4 ( L_13 ) ;
return 0 ;
}
V_2 -> V_8 [ V_26 ] . V_10 = V_43 ;
return 0 ;
}
unsigned int F_25 ( int V_26 , int V_27 )
{
struct V_6 * V_7 ;
if ( V_2 == NULL )
return 0 ;
V_7 = & V_2 -> V_8 [ V_26 ] ;
if ( V_7 -> V_14 == V_7 -> V_15 ) {
if ( V_27 ) {
int V_30 = F_13 (
V_24 [ V_26 ] . V_25 ,
( V_7 -> V_14 != V_7 -> V_15 ) ||
V_23 ) ;
if ( V_30 )
return V_30 ;
if ( V_23 )
return 0 ;
} else
return 0 ;
}
return ( V_7 -> V_15 + V_7 -> V_11 - V_7 -> V_14 )
% V_7 -> V_11 ;
}
static inline int F_26 ( int V_44 , int V_45 , int V_46 )
{
if ( V_44 == V_45 ) {
return V_46 - 1 ;
}
return ( ( V_44 + V_46 - V_45 ) % V_46 ) - 1 ;
}
unsigned int F_27 ( int V_26 )
{
struct V_6 * V_7 = & V_2 -> V_8 [ V_26 ] ;
return F_26 ( V_7 -> V_12 , V_7 -> V_13 ,
V_7 -> V_11 ) ;
}
T_2 F_28 ( int V_26 , void T_3 * V_47 , T_4 V_48 )
{
T_4 V_15 , V_49 = 0L ;
struct V_6 * V_50 ;
unsigned long V_51 ;
if ( V_2 == NULL )
return - V_32 ;
V_50 = & V_2 -> V_8 [ V_26 ] ;
F_29 ( & V_24 [ V_26 ] . V_52 ) ;
F_14 () ;
V_15 = V_50 -> V_15 ;
V_48 = F_30 ( V_48 ,
( T_4 ) ( V_15 + V_50 -> V_11 - V_50 -> V_14 )
% V_50 -> V_11 ) ;
V_49 = F_30 ( V_48 , ( T_4 ) V_50 -> V_11 - V_50 -> V_14 ) ;
V_51 = F_31 ( V_47 , V_50 -> V_17 + V_50 -> V_14 , V_49 ) ;
if ( V_51 )
goto V_53;
if ( V_48 - V_49 )
V_51 = F_31 ( V_47 + V_49 , V_50 -> V_17 , V_48 - V_49 ) ;
V_53:
V_48 -= V_51 ;
F_32 () ;
V_50 -> V_14 = ( V_50 -> V_14 + V_48 ) % V_50 -> V_11 ;
F_32 () ;
F_33 ( & V_24 [ V_26 ] . V_52 ) ;
return V_48 ;
}
T_2 F_34 ( int V_26 , const void T_3 * V_54 , T_4 V_48 )
{
struct V_6 * V_55 ;
unsigned long V_51 ;
T_4 V_12 ;
T_4 V_49 ;
if ( V_2 == NULL )
return - V_32 ;
V_55 = & V_2 -> V_8 [ V_26 ] ;
F_29 ( & V_24 [ V_26 ] . V_52 ) ;
F_14 () ;
V_12 = V_55 -> V_12 ;
V_48 = F_35 ( T_4 , V_48 , F_26 ( V_12 , V_55 -> V_13 ,
V_55 -> V_11 ) ) ;
V_49 = F_30 ( V_48 , ( T_4 ) V_55 -> V_11 - V_55 -> V_13 ) ;
V_51 = F_36 ( V_55 -> V_16 + V_55 -> V_13 , V_54 , V_49 ) ;
if ( V_51 )
goto V_53;
if ( V_48 - V_49 )
V_51 = F_36 ( V_55 -> V_16 , V_54 + V_49 , V_48 - V_49 ) ;
V_53:
V_48 -= V_51 ;
F_32 () ;
V_55 -> V_13 = ( V_55 -> V_13 + V_48 ) % V_55 -> V_11 ;
F_32 () ;
F_33 ( & V_24 [ V_26 ] . V_52 ) ;
F_37 () ;
return V_48 ;
}
static int F_38 ( struct V_56 * V_56 , struct V_57 * V_58 )
{
return F_8 ( F_39 ( V_56 ) , ( V_58 -> V_59 & V_60 ) ? 0 : 1 ) ;
}
static int F_40 ( struct V_56 * V_56 , struct V_57 * V_58 )
{
return F_24 ( F_39 ( V_56 ) ) ;
}
static unsigned int F_41 ( struct V_57 * V_57 , T_5 * V_36 )
{
int V_61 = F_39 ( F_42 ( V_57 ) ) ;
unsigned int V_62 = 0 ;
F_43 ( V_57 , & V_24 [ V_61 ] . V_63 , V_36 ) ;
F_43 ( V_57 , & V_24 [ V_61 ] . V_25 , V_36 ) ;
if ( V_2 == NULL )
return 0 ;
if ( F_25 ( V_61 , 0 ) )
V_62 |= V_64 | V_65 ;
if ( F_27 ( V_61 ) )
V_62 |= V_66 | V_67 ;
return V_62 ;
}
static T_2 F_44 ( struct V_57 * V_57 , char T_3 * V_54 , T_4 V_48 ,
T_6 * V_68 )
{
int V_61 = F_39 ( F_42 ( V_57 ) ) ;
if ( ! F_25 ( V_61 , ( V_57 -> V_59 & V_60 ) ? 0 : 1 ) )
return 0 ;
return F_28 ( V_61 , V_54 , V_48 ) ;
}
static T_2 F_45 ( struct V_57 * V_57 , const char T_3 * V_54 ,
T_4 V_48 , T_6 * V_68 )
{
int V_61 = F_39 ( F_42 ( V_57 ) ) ;
if ( ! F_27 ( V_61 ) ) {
int V_30 ;
if ( V_57 -> V_59 & V_60 )
return - V_69 ;
V_30 = F_13 ( V_24 [ V_61 ] . V_63 ,
F_27 ( V_61 ) ) ;
if ( V_30 )
return V_30 ;
}
return F_34 ( V_61 , V_54 , V_48 ) ;
}
