static void F_1 ( struct V_1 * V_2 , int V_3 , unsigned long * V_4 )
{
F_2 ( & V_2 -> V_5 . V_6 ) ;
V_2 -> V_7 = V_2 -> V_3 = V_3 ;
V_2 -> V_4 = V_4 ;
F_3 ( & V_2 -> V_5 ) ;
F_4 ( & V_2 -> V_5 . V_6 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_5 . V_6 ) ;
V_2 -> V_7 -= V_2 -> V_3 + 1 ;
F_4 ( & V_2 -> V_5 . V_6 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
F_7 ( V_8 ) ;
F_2 ( & V_2 -> V_5 . V_6 ) ;
if ( V_2 -> V_7 != - 1 ) {
for (; ; ) {
if ( F_8 ( F_9 ( & V_8 . V_9 ) ) )
F_10 ( & V_2 -> V_5 , & V_8 ) ;
F_11 ( V_10 ) ;
if ( V_2 -> V_7 == - 1 )
break;
F_4 ( & V_2 -> V_5 . V_6 ) ;
F_12 () ;
F_2 ( & V_2 -> V_5 . V_6 ) ;
}
F_13 ( & V_2 -> V_5 , & V_8 ) ;
F_14 ( V_11 ) ;
}
V_2 -> V_4 = NULL ;
F_4 ( & V_2 -> V_5 . V_6 ) ;
}
static void F_15 ( struct V_1 * V_2 , int V_12 )
{
int V_13 ;
F_2 ( & V_2 -> V_5 . V_6 ) ;
F_16 ( V_12 , V_2 -> V_4 ) ;
V_13 = ++ V_2 -> V_7 ;
if ( F_17 ( V_13 == 1 ) )
F_18 ( & V_2 -> V_5 ) ;
else if ( F_17 ( V_13 == - 1 ) )
F_3 ( & V_2 -> V_5 ) ;
F_4 ( & V_2 -> V_5 . V_6 ) ;
}
static int F_19 ( struct V_1 * V_2 )
{
long V_14 = V_15 * V_16 ;
F_7 ( V_8 ) ;
do {
long V_17 = V_14 , V_18 ;
if ( F_8 ( F_9 ( & V_8 . V_9 ) ) )
F_20 ( & V_2 -> V_5 , & V_8 ) ;
F_11 ( V_19 ) ;
if ( V_2 -> V_7 > 0 )
break;
if ( V_2 -> V_7 < 0 ) {
if ( V_17 > V_20 * V_16 )
V_17 = V_20 * V_16 ;
}
F_4 ( & V_2 -> V_5 . V_6 ) ;
V_18 = F_21 ( V_17 ) ;
F_2 ( & V_2 -> V_5 . V_6 ) ;
if ( F_17 ( ! V_18 ) && V_17 != V_14 && V_2 -> V_7 < 0 )
V_14 = V_18 ;
else
V_14 = V_18 + ( V_14 - V_17 ) ;
if ( F_17 ( F_22 ( V_21 ) ) )
V_14 = - V_22 ;
} while ( V_14 > 0 );
if ( ! F_9 ( & V_8 . V_9 ) )
F_23 ( & V_8 . V_9 ) ;
else if ( V_14 <= 0 && F_24 ( & V_2 -> V_5 ) )
F_25 ( & V_2 -> V_5 , V_19 , NULL ) ;
F_14 ( V_11 ) ;
if ( F_8 ( V_14 > 0 ) )
return 0 ;
return V_14 < 0 ? - V_22 : - V_23 ;
}
static int F_26 ( struct V_1 * V_2 )
{
int V_24 = 0 ;
F_2 ( & V_2 -> V_5 . V_6 ) ;
if ( F_17 ( V_2 -> V_7 <= 0 ) )
V_24 = F_19 ( V_2 ) ;
if ( F_8 ( ! V_24 ) ) {
V_2 -> V_7 -- ;
V_24 = F_27 ( V_2 -> V_4 , V_2 -> V_3 ) ;
F_28 ( V_24 , V_2 -> V_4 ) ;
}
F_4 ( & V_2 -> V_5 . V_6 ) ;
return V_24 ;
}
static void
F_29 ( struct V_25 * V_26 )
{
int V_27 ;
for ( V_27 = 0 ; V_27 < V_26 -> V_28 ; V_27 ++ )
F_30 ( V_26 -> V_29 [ V_27 ] ) ;
}
static void
F_31 ( struct V_25 * V_26 )
{
F_32 ( V_26 -> V_29 ) ;
F_32 ( V_26 -> V_30 ) ;
F_32 ( V_26 -> V_31 ) ;
F_32 ( V_26 ) ;
}
int F_33 ( void )
{
struct V_25 * V_26 ;
int V_32 = 0 ;
F_2 ( & V_33 ) ;
V_26 = V_34 ;
if ( V_26 )
V_32 = V_26 -> V_35 ;
F_4 ( & V_33 ) ;
return V_32 ;
}
int F_34 ( void )
{
struct V_25 * V_26 ;
int V_36 = 0 ;
F_2 ( & V_33 ) ;
V_26 = V_34 ;
if ( V_26 )
V_36 = V_26 -> V_37 ;
F_4 ( & V_33 ) ;
return V_36 ;
}
int F_35 ( void )
{
return V_34 ? 1 : 0 ;
}
static struct V_25 *
F_36 ( struct V_38 * V_39 )
{
struct V_25 * V_26 ;
V_26 = F_37 ( sizeof( * V_26 ) , V_40 ) ;
if ( ! V_26 )
goto V_41;
V_26 -> V_42 = V_39 -> V_42 ;
V_26 -> V_43 = V_39 -> V_3 ;
V_26 -> V_35 = V_39 -> V_32 ;
V_26 -> V_37 = F_38 ( V_26 -> V_35 ) ;
V_26 -> V_31 =
F_37 ( F_39 ( V_26 -> V_43 , V_44 ) , V_40 ) ;
if ( ! V_26 -> V_31 )
goto V_45;
V_26 -> V_30 =
F_40 ( V_26 -> V_43 , sizeof( struct V_46 ) ,
V_40 ) ;
if ( ! V_26 -> V_30 )
goto V_47;
V_26 -> V_28 = V_26 -> V_42 / V_48 ;
V_26 -> V_29 =
F_40 ( V_26 -> V_28 , sizeof( struct V_49 * ) , V_40 ) ;
if ( ! V_26 -> V_29 )
goto V_50;
return V_26 ;
V_50:
F_32 ( V_26 -> V_30 ) ;
V_47:
F_32 ( V_26 -> V_31 ) ;
V_45:
F_32 ( V_26 ) ;
V_41:
return NULL ;
}
static int
F_41 ( struct V_25 * V_26 ,
struct V_38 * V_39 )
{
int V_51 = V_26 -> V_35 / V_48 ;
int V_52 = 0 , V_53 , V_27 ;
V_53 = F_42 ( ( unsigned long ) V_39 -> V_54 ,
V_26 -> V_28 , 1 , V_26 -> V_29 ) ;
if ( V_53 < 0 )
return V_53 ;
if ( V_53 != V_26 -> V_28 ) {
F_43 ( L_1 ,
V_26 -> V_28 , V_53 ) ;
for ( V_27 = 0 ; V_27 < V_53 ; V_27 ++ ) {
F_44 ( V_26 -> V_29 [ V_27 ] ) ;
F_30 ( V_26 -> V_29 [ V_27 ] ) ;
}
return - V_55 ;
}
for ( V_27 = 0 ; V_27 < V_26 -> V_28 ; V_27 ++ )
F_45 ( V_26 -> V_29 [ V_27 ] ) ;
for ( V_52 = 0 , V_27 = 0 ; V_27 < V_26 -> V_43 ; V_27 ++ ) {
V_26 -> V_30 [ V_27 ] . V_29 = & V_26 -> V_29 [ V_52 ] ;
V_26 -> V_30 [ V_27 ] . V_56 = V_51 ;
V_26 -> V_30 [ V_27 ] . V_57 =
( V_39 -> V_54 + ( V_27 * V_51 * V_48 ) ) ;
V_52 += V_51 ;
}
return 0 ;
}
int F_46 ( struct V_38 * V_39 )
{
struct V_25 * V_26 ;
int V_53 = - V_58 ;
F_47 ( V_59 ,
L_2
L_3 ,
V_39 -> V_54 ,
V_39 -> V_32 ,
V_39 -> V_3 ) ;
if ( V_39 -> V_42 < 0 ||
V_39 -> V_32 < 0 ||
V_39 -> V_3 < 0 )
goto V_41;
if ( F_48 ( ( unsigned long ) V_39 -> V_54 ) !=
( unsigned long ) V_39 -> V_54 ) {
F_43 ( L_4 ,
V_39 -> V_54 ) ;
goto V_41;
}
if ( F_48 ( ( ( unsigned long ) V_39 -> V_54 + V_39 -> V_42 ) )
!= ( unsigned long ) ( V_39 -> V_54 + V_39 -> V_42 ) ) {
F_43 ( L_5 ,
V_39 -> V_54 ,
V_39 -> V_42 ) ;
goto V_41;
}
if ( V_39 -> V_42 != ( V_39 -> V_32 * V_39 -> V_3 ) ) {
F_43 ( L_6 ,
V_39 -> V_42 ,
V_39 -> V_32 ,
V_39 -> V_3 ) ;
goto V_41;
}
if ( ( V_39 -> V_32 % V_48 ) != 0 ) {
F_43 ( L_7 ,
V_39 -> V_32 ) ;
goto V_41;
}
V_53 = - V_55 ;
V_26 = F_36 ( V_39 ) ;
if ( ! V_26 )
goto V_41;
V_53 = F_41 ( V_26 , V_39 ) ;
if ( V_53 )
goto V_45;
F_2 ( & V_33 ) ;
if ( V_34 ) {
F_4 ( & V_33 ) ;
F_43 ( L_8 ) ;
V_53 = - V_58 ;
goto V_60;
}
V_34 = V_26 ;
F_1 ( & V_61 ,
V_26 -> V_43 ,
V_26 -> V_31 ) ;
F_1 ( & V_62 ,
V_63 ,
V_26 -> V_64 ) ;
F_4 ( & V_33 ) ;
F_47 ( V_59 ,
L_9 ) ;
return 0 ;
V_60:
F_29 ( V_26 ) ;
V_45:
F_31 ( V_26 ) ;
V_41:
return V_53 ;
}
void F_49 ( void )
{
struct V_25 * V_26 = V_34 ;
if ( ! V_26 )
return;
F_47 ( V_59 , L_10 ) ;
F_5 ( & V_61 ) ;
F_5 ( & V_62 ) ;
F_47 ( V_59 ,
L_11 ) ;
}
void F_50 ( void )
{
struct V_25 * V_26 = V_34 ;
if ( ! V_26 )
return;
F_6 ( & V_61 ) ;
F_6 ( & V_62 ) ;
F_2 ( & V_33 ) ;
V_34 = NULL ;
F_4 ( & V_33 ) ;
F_29 ( V_26 ) ;
F_31 ( V_26 ) ;
}
int F_51 ( void )
{
return F_26 ( & V_61 ) ;
}
void F_52 ( int V_65 )
{
F_15 ( & V_61 , V_65 ) ;
}
int F_53 ( void )
{
return F_26 ( & V_62 ) ;
}
void F_54 ( int V_65 )
{
F_15 ( & V_62 , V_65 ) ;
}
int F_55 ( struct V_66 * V_67 ,
int V_65 ,
T_1 V_32 )
{
struct V_46 * V_68 ;
int V_27 ;
F_47 ( V_59 ,
L_12 ,
V_69 , V_65 , V_32 ) ;
V_68 = & V_34 -> V_30 [ V_65 ] ;
for ( V_27 = 0 ; V_32 ; V_27 ++ ) {
struct V_49 * V_49 = V_68 -> V_29 [ V_27 ] ;
T_1 V_17 = V_32 ;
if ( V_17 > V_48 )
V_17 = V_48 ;
if ( F_56 ( V_49 , 0 , V_17 , V_67 ) != V_17 )
return - V_70 ;
V_32 -= V_17 ;
}
return 0 ;
}
int F_57 ( struct V_66 * V_67 ,
int V_65 ,
T_1 V_32 )
{
struct V_46 * V_71 ;
int V_27 ;
V_71 = & V_34 -> V_30 [ V_65 ] ;
F_47 ( V_59 ,
L_12 ,
V_69 , V_65 , V_32 ) ;
for ( V_27 = 0 ; V_32 ; V_27 ++ ) {
struct V_49 * V_49 = V_71 -> V_29 [ V_27 ] ;
T_1 V_17 = V_32 ;
if ( V_17 > V_48 )
V_17 = V_48 ;
V_17 = F_58 ( V_49 , 0 , V_17 , V_67 ) ;
if ( ! V_17 )
return - V_70 ;
V_32 -= V_17 ;
}
return 0 ;
}
