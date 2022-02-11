static inline void F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 , T_1 V_5 )
{
if ( V_2 -> V_6 -> V_7 [ V_4 ] )
F_2 ( V_5 , V_2 -> V_8 +
V_2 -> V_6 -> V_7 [ V_4 ] ) ;
}
static inline void F_3 ( struct V_1 * V_2 ,
enum V_3 V_4 , T_1 V_5 )
{
T_1 V_9 ;
if ( ! V_2 -> V_6 -> V_7 [ V_4 ] )
return;
do {
F_2 ( V_5 , V_2 -> V_8 +
V_2 -> V_6 -> V_7 [ V_4 ] ) ;
V_9 = F_4 ( V_2 -> V_8 +
V_2 -> V_6 -> V_7 [ V_4 ] ) ;
if ( V_9 == V_5 )
break;
F_5 () ;
} while ( 1 );
}
static inline T_1 F_6 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
return F_4 ( V_2 -> V_8 + V_2 -> V_6 -> V_7 [ V_4 ] ) ;
}
static void F_7 ( struct V_1 * V_2 ,
enum V_10 V_11 )
{
T_1 V_12 ;
T_1 V_13 ;
V_12 = V_2 -> V_6 -> V_12 [ V_11 ] ;
V_13 = F_6 ( V_2 , V_14 ) ;
V_13 &= ~ ( V_15 << V_16 ) ;
V_13 |= V_12 << V_16 ;
V_13 |= V_17 ;
F_3 ( V_2 , V_14 , V_13 ) ;
}
static int F_8 ( unsigned long int V_18 )
{
F_9 ( V_19 ) ;
return - 1 ;
}
static int F_10 ( void )
{
int V_9 ;
struct V_1 * V_2 = F_11 ( V_20 ) ;
F_7 ( V_2 , V_21 ) ;
V_9 = F_12 ( 0 , F_8 ) ;
F_7 ( V_2 , V_22 ) ;
return V_9 ;
}
static int F_13 ( unsigned long V_23 )
{
return F_11 ( V_24 ) [ V_23 ] ( ) ;
}
static int T_2 F_14 ( struct V_25 * V_26 , int V_27 )
{
const struct V_28 * V_29 ;
struct V_25 * V_30 ;
int V_31 ;
int V_32 = 1 ;
T_3 V_33 [ V_34 ] ;
T_3 * V_35 ;
T_4 V_36 ;
bool V_37 = false ;
for ( V_31 = 0 ; ; V_31 ++ ) {
V_30 = F_15 ( V_26 , L_1 , V_31 ) ;
if ( ! V_30 )
break;
if ( ! F_16 ( V_30 ) )
continue;
if ( V_31 == V_34 ) {
F_17 ( L_2 ,
V_38 ) ;
break;
}
V_29 = F_18 ( V_39 , V_30 ) ;
if ( ! V_29 )
return - V_40 ;
V_33 [ V_32 ] = V_29 -> V_41 ;
if ( V_29 -> V_41 == F_10 )
V_37 = true ;
V_32 ++ ;
}
if ( V_32 == 1 )
goto V_42;
V_35 = F_19 ( F_20 ( V_27 ) , V_32 , sizeof( * V_35 ) ,
V_43 ) ;
if ( ! V_35 )
return - V_44 ;
for ( V_31 = 1 ; V_31 < V_32 ; V_31 ++ )
V_35 [ V_31 ] = V_33 [ V_31 ] ;
if ( V_37 ) {
F_21 ( & V_36 ) ;
F_22 ( V_27 , & V_36 ) ;
F_23 ( V_45 , & V_36 ) ;
}
F_24 ( V_24 , V_27 ) = V_35 ;
V_42:
return F_24 ( V_20 , V_27 ) ? 0 : - V_46 ;
}
static struct V_1 * F_25 ( struct V_47 * V_48 ,
int * V_49 )
{
struct V_1 * V_2 = NULL ;
struct V_25 * V_26 , * V_50 ;
int V_27 ;
bool V_51 = 0 ;
F_26 (cpu) {
V_26 = F_27 ( V_27 ) ;
if ( ! V_26 )
continue;
V_50 = F_15 ( V_26 , L_3 , 0 ) ;
V_51 = ( V_50 == V_48 -> V_52 . V_53 ) ;
F_28 ( V_50 ) ;
F_28 ( V_26 ) ;
if ( V_51 )
break;
}
if ( V_51 ) {
V_2 = F_29 ( & V_48 -> V_52 , sizeof( * V_2 ) , V_43 ) ;
if ( V_2 )
* V_49 = V_27 ;
}
return V_2 ;
}
static int F_30 ( struct V_47 * V_48 )
{
struct V_1 * V_2 ;
struct V_54 * V_55 ;
const struct V_28 * V_29 ;
void T_5 * V_56 ;
int V_27 ;
V_2 = F_25 ( V_48 , & V_27 ) ;
if ( ! V_2 )
return - V_57 ;
V_55 = F_31 ( V_48 , V_58 , 0 ) ;
V_2 -> V_8 = F_32 ( & V_48 -> V_52 , V_55 ) ;
if ( F_33 ( V_2 -> V_8 ) )
return F_34 ( V_2 -> V_8 ) ;
V_29 = F_18 ( V_59 , V_48 -> V_52 . V_53 ) ;
if ( ! V_29 )
return - V_40 ;
V_2 -> V_6 = V_29 -> V_41 ;
V_56 = V_2 -> V_8 + V_2 -> V_6 -> V_7 [ V_60 ] ;
F_35 ( V_56 , V_2 -> V_6 -> V_61 ,
F_36 ( V_2 -> V_6 -> V_61 ) / 4 ) ;
F_1 ( V_2 , V_62 , V_2 -> V_6 -> V_63 ) ;
F_1 ( V_2 , V_64 , V_2 -> V_6 -> V_65 ) ;
F_1 ( V_2 , V_66 , V_2 -> V_6 -> V_67 ) ;
F_1 ( V_2 , V_68 ,
V_2 -> V_6 -> V_69 [ 0 ] ) ;
F_1 ( V_2 , V_70 ,
V_2 -> V_6 -> V_69 [ 1 ] ) ;
F_7 ( V_2 , V_22 ) ;
F_24 ( V_20 , V_27 ) = V_2 ;
return 0 ;
}
