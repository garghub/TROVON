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
F_9 ( L_8 ) ;
return - V_31 ;
}
if ( F_10 ( & V_24 [ V_26 ] . V_32 ) > 1 ) {
F_9 ( L_9 , V_26 ) ;
V_30 = - V_33 ;
goto V_34;
}
if ( V_2 == NULL ) {
V_28 = F_11 ( F_12 () ) ;
if ( V_28 == NULL ) {
if ( V_27 ) {
V_30 = F_13 (
V_24 [ V_26 ] . V_25 ,
( V_28 = F_11 ( F_12 () ) ) ) ;
if ( V_30 )
goto V_34;
} else {
F_9 ( L_10 ) ;
V_30 = - V_31 ;
goto V_34;
}
}
F_14 () ;
if ( * V_28 == NULL ) {
if ( V_27 ) {
F_15 ( V_35 ) ;
for (; ; ) {
F_16 (
& V_24 [ V_26 ] . V_25 ,
& V_35 , V_36 ) ;
F_14 () ;
if ( * V_28 != NULL )
break;
if ( ! F_17 ( V_37 ) ) {
F_18 () ;
continue;
}
V_30 = - V_38 ;
goto V_34;
}
F_19 ( & V_24 [ V_26 ] . V_25 ,
& V_35 ) ;
} else {
F_4 ( L_11 ) ;
V_30 = - V_31 ;
goto V_34;
}
}
if ( ( unsigned int ) * V_28 < V_39 ) {
F_20 ( L_12 ,
( int ) * V_28 ) ;
V_30 = - V_31 ;
goto V_34;
}
V_30 = F_3 ( * V_28 ) ;
if ( V_30 < 0 )
goto V_40;
}
V_7 = & V_2 -> V_8 [ V_26 ] ;
V_4 = F_21 ( & V_7 -> V_10 , V_41 ) ;
if ( V_4 == V_41 ) {
V_30 = - V_33 ;
goto V_34;
}
V_34:
F_22 () ;
F_23 ( & V_24 [ V_26 ] . V_32 ) ;
F_22 () ;
V_40:
return V_30 ;
}
int F_24 ( int V_26 )
{
if ( V_2 == NULL ) {
F_4 ( L_13 ) ;
return 0 ;
}
V_2 -> V_8 [ V_26 ] . V_10 = V_42 ;
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
static inline int F_26 ( int V_43 , int V_44 , int V_45 )
{
if ( V_43 == V_44 ) {
return V_45 - 1 ;
}
return ( ( V_43 + V_45 - V_44 ) % V_45 ) - 1 ;
}
unsigned int F_27 ( int V_26 )
{
struct V_6 * V_7 = & V_2 -> V_8 [ V_26 ] ;
return F_26 ( V_7 -> V_12 , V_7 -> V_13 ,
V_7 -> V_11 ) ;
}
T_2 F_28 ( int V_26 , void T_3 * V_46 , T_4 V_47 )
{
T_4 V_15 , V_48 = 0L ;
struct V_6 * V_49 ;
unsigned long V_50 ;
if ( V_2 == NULL )
return - V_31 ;
V_49 = & V_2 -> V_8 [ V_26 ] ;
F_29 ( & V_24 [ V_26 ] . V_51 ) ;
F_14 () ;
V_15 = V_49 -> V_15 ;
V_47 = F_30 ( V_47 ,
( T_4 ) ( V_15 + V_49 -> V_11 - V_49 -> V_14 )
% V_49 -> V_11 ) ;
V_48 = F_30 ( V_47 , ( T_4 ) V_49 -> V_11 - V_49 -> V_14 ) ;
V_50 = F_31 ( V_46 , V_49 -> V_17 + V_49 -> V_14 , V_48 ) ;
if ( V_50 )
goto V_52;
if ( V_47 - V_48 )
V_50 = F_31 ( V_46 + V_48 , V_49 -> V_17 , V_47 - V_48 ) ;
V_52:
V_47 -= V_50 ;
F_32 () ;
V_49 -> V_14 = ( V_49 -> V_14 + V_47 ) % V_49 -> V_11 ;
F_32 () ;
F_33 ( & V_24 [ V_26 ] . V_51 ) ;
return V_47 ;
}
T_2 F_34 ( int V_26 , const void T_3 * V_53 , T_4 V_47 )
{
struct V_6 * V_54 ;
unsigned long V_50 ;
T_4 V_12 ;
T_4 V_48 ;
if ( V_2 == NULL )
return - V_31 ;
V_54 = & V_2 -> V_8 [ V_26 ] ;
F_29 ( & V_24 [ V_26 ] . V_51 ) ;
F_14 () ;
V_12 = V_54 -> V_12 ;
V_47 = F_35 ( T_4 , V_47 , F_26 ( V_12 , V_54 -> V_13 ,
V_54 -> V_11 ) ) ;
V_48 = F_30 ( V_47 , ( T_4 ) V_54 -> V_11 - V_54 -> V_13 ) ;
V_50 = F_36 ( V_54 -> V_16 + V_54 -> V_13 , V_53 , V_48 ) ;
if ( V_50 )
goto V_52;
if ( V_47 - V_48 )
V_50 = F_36 ( V_54 -> V_16 , V_53 + V_48 , V_47 - V_48 ) ;
V_52:
V_47 -= V_50 ;
F_32 () ;
V_54 -> V_13 = ( V_54 -> V_13 + V_47 ) % V_54 -> V_11 ;
F_32 () ;
F_33 ( & V_24 [ V_26 ] . V_51 ) ;
F_37 () ;
return V_47 ;
}
static int F_38 ( struct V_55 * V_55 , struct V_56 * V_57 )
{
return F_8 ( F_39 ( V_55 ) , ( V_57 -> V_58 & V_59 ) ? 0 : 1 ) ;
}
static int F_40 ( struct V_55 * V_55 , struct V_56 * V_57 )
{
return F_24 ( F_39 ( V_55 ) ) ;
}
static unsigned int F_41 ( struct V_56 * V_56 , T_5 * V_35 )
{
int V_60 = F_39 ( F_42 ( V_56 ) ) ;
unsigned int V_61 = 0 ;
F_43 ( V_56 , & V_24 [ V_60 ] . V_62 , V_35 ) ;
F_43 ( V_56 , & V_24 [ V_60 ] . V_25 , V_35 ) ;
if ( V_2 == NULL )
return 0 ;
if ( F_25 ( V_60 , 0 ) )
V_61 |= V_63 | V_64 ;
if ( F_27 ( V_60 ) )
V_61 |= V_65 | V_66 ;
return V_61 ;
}
static T_2 F_44 ( struct V_56 * V_56 , char T_3 * V_53 , T_4 V_47 ,
T_6 * V_67 )
{
int V_60 = F_39 ( F_42 ( V_56 ) ) ;
if ( ! F_25 ( V_60 , ( V_56 -> V_58 & V_59 ) ? 0 : 1 ) )
return 0 ;
return F_28 ( V_60 , V_53 , V_47 ) ;
}
static T_2 F_45 ( struct V_56 * V_56 , const char T_3 * V_53 ,
T_4 V_47 , T_6 * V_67 )
{
int V_60 = F_39 ( F_42 ( V_56 ) ) ;
if ( ! F_27 ( V_60 ) ) {
int V_30 ;
if ( V_56 -> V_58 & V_59 )
return - V_68 ;
V_30 = F_13 ( V_24 [ V_60 ] . V_62 ,
F_27 ( V_60 ) ) ;
if ( V_30 )
return V_30 ;
}
return F_34 ( V_60 , V_53 , V_47 ) ;
}
