static enum V_1 F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = (struct V_4 * ) & V_3 -> V_6 ;
return (enum V_1 ) V_5 -> V_7 ;
}
static T_1 F_2 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = (struct V_4 * ) & V_3 -> V_6 ;
T_1 V_8 = F_3 ( V_5 -> V_8 ) ;
return ( V_8 & V_9 ) >> V_10 ;
}
int T_2 F_4 ( struct V_11 * V_12 ,
T_3 V_13 ,
T_4 V_14 ,
struct V_15 * V_16 ,
T_4 V_17 , struct V_18 * * V_19 )
{
int error ;
struct V_18 * V_20 ;
void T_5 * V_21 ;
struct V_22 * V_23 ;
V_20 = F_5 ( V_12 , sizeof( * V_20 ) , V_24 ) ;
if ( ! V_20 )
return - V_25 ;
V_20 -> V_12 = V_12 ;
V_20 -> V_17 = V_17 ;
V_20 -> V_26 = V_13 ;
V_20 -> V_27 = V_14 ;
if ( V_17 & V_28 )
F_6 ( & V_20 -> V_29 ) ;
else
F_7 ( & V_20 -> V_30 ) ;
V_23 = F_8 ( V_12 ,
V_13 ,
V_14 ,
L_1 ) ;
if ( ! V_23 ) {
F_9 ( V_12 ,
L_2 ,
V_13 ) ;
return - V_31 ;
}
V_21 = F_10 ( V_12 ,
V_13 ,
V_14 ) ;
if ( ! V_21 ) {
F_9 ( V_12 ,
L_3 ,
V_13 ) ;
return - V_32 ;
}
V_20 -> V_33 = V_21 ;
if ( V_16 ) {
error = F_11 ( V_20 , V_16 ) ;
if ( error < 0 )
goto V_34;
}
* V_19 = V_20 ;
return 0 ;
V_34:
F_12 ( V_20 ) ;
return error ;
}
void F_12 ( struct V_18 * V_20 )
{
struct V_15 * V_16 = V_20 -> V_16 ;
if ( V_16 )
F_13 ( V_20 ) ;
F_14 ( V_20 -> V_12 , V_20 -> V_33 ) ;
F_15 ( V_20 -> V_12 ,
V_20 -> V_26 ,
V_20 -> V_27 ) ;
V_20 -> V_33 = NULL ;
F_16 ( V_20 -> V_12 , V_20 ) ;
}
int F_11 ( struct V_18 * V_20 ,
struct V_15 * V_16 )
{
int error ;
if ( F_17 ( ! V_16 ) )
return - V_35 ;
if ( F_17 ( V_20 -> V_16 ) )
return - V_35 ;
if ( F_17 ( V_16 -> V_20 ) )
return - V_35 ;
error = F_18 ( V_20 ,
0 ,
V_16 -> V_36 . V_37 ,
& V_16 -> V_38 ) ;
if ( error < 0 )
return error ;
V_20 -> V_16 = V_16 ;
V_16 -> V_20 = V_20 ;
return 0 ;
}
void F_13 ( struct V_18 * V_20 )
{
int error ;
struct V_15 * V_16 = V_20 -> V_16 ;
if ( F_17 ( ! V_16 ) )
return;
if ( F_17 ( V_16 -> V_20 != V_20 ) )
return;
error = F_19 ( V_20 ,
0 ,
V_16 -> V_38 ) ;
if ( error < 0 ) {
F_9 ( & V_16 -> V_12 , L_4 ,
error ) ;
}
V_20 -> V_16 = NULL ;
V_16 -> V_20 = NULL ;
}
static int F_20 ( enum V_1 V_7 )
{
static const int V_39 [] = {
[ V_40 ] = 0 ,
[ V_41 ] = - V_42 ,
[ V_43 ] = - V_44 ,
[ V_45 ] = - V_46 ,
[ V_47 ] = - V_32 ,
[ V_48 ] = - V_49 ,
[ V_50 ] = - V_51 ,
[ V_52 ] = - V_25 ,
[ V_53 ] = - V_31 ,
[ V_54 ] = - V_55 ,
[ V_56 ] = - V_57 ,
} ;
if ( F_17 ( ( T_4 ) V_7 >= F_21 ( V_39 ) ) )
return - V_35 ;
return V_39 [ V_7 ] ;
}
static const char * F_22 ( enum V_1 V_7 )
{
static const char * const V_58 [] = {
[ V_40 ] = L_5 ,
[ V_59 ] = L_6 ,
[ V_41 ] = L_7 ,
[ V_43 ] = L_8 ,
[ V_45 ] = L_9 ,
[ V_47 ] = L_10 ,
[ V_48 ] = L_11 ,
[ V_50 ] = L_12 ,
[ V_52 ] = L_13 ,
[ V_53 ] = L_14 ,
[ V_54 ] = L_15 ,
[ V_56 ] = L_16
} ;
if ( ( unsigned int ) V_7 >= F_21 ( V_58 ) )
return L_17 ;
return V_58 [ V_7 ] ;
}
static inline void F_23 ( struct V_2 T_5 * V_60 ,
struct V_2 * V_3 )
{
int V_61 ;
for ( V_61 = 0 ; V_61 < V_62 ; V_61 ++ )
F_24 ( V_3 -> V_63 [ V_61 ] , & V_60 -> V_63 [ V_61 ] ) ;
F_25 () ;
F_24 ( V_3 -> V_6 , & V_60 -> V_6 ) ;
}
static inline enum V_1 F_26 ( struct V_2 T_5 *
V_60 ,
struct V_2 * V_64 )
{
int V_61 ;
enum V_1 V_7 ;
F_27 () ;
V_64 -> V_6 = F_28 ( & V_60 -> V_6 ) ;
F_27 () ;
V_7 = F_1 ( V_64 ) ;
if ( V_7 != V_40 )
return V_7 ;
for ( V_61 = 0 ; V_61 < V_62 ; V_61 ++ )
V_64 -> V_63 [ V_61 ] = F_28 ( & V_60 -> V_63 [ V_61 ] ) ;
F_27 () ;
return V_7 ;
}
static int F_29 ( struct V_18 * V_20 ,
struct V_2 * V_3 ,
enum V_1 * V_65 )
{
enum V_1 V_7 ;
unsigned long V_66 =
V_67 + F_30 ( V_68 ) ;
for (; ; ) {
V_7 = F_26 ( V_20 -> V_33 , V_3 ) ;
if ( V_7 != V_59 )
break;
F_31 ( V_69 ,
V_70 ) ;
if ( F_32 ( V_67 , V_66 ) ) {
F_33 ( V_20 -> V_12 ,
L_18 ,
V_20 -> V_26 ,
( unsigned int ) F_34 ( V_3 ) ,
( unsigned int ) F_2 ( V_3 ) ) ;
return - V_49 ;
}
}
* V_65 = V_7 ;
return 0 ;
}
static int F_35 ( struct V_18 * V_20 ,
struct V_2 * V_3 ,
enum V_1 * V_65 )
{
enum V_1 V_7 ;
unsigned long V_71 = V_68 * 1000 ;
F_36 ( ( V_68 * 1000 ) %
V_70 != 0 ) ;
for (; ; ) {
V_7 = F_26 ( V_20 -> V_33 , V_3 ) ;
if ( V_7 != V_59 )
break;
F_37 ( V_70 ) ;
V_71 -= V_70 ;
if ( V_71 == 0 ) {
F_33 ( V_20 -> V_12 ,
L_18 ,
V_20 -> V_26 ,
( unsigned int ) F_34 ( V_3 ) ,
( unsigned int ) F_2 ( V_3 ) ) ;
return - V_49 ;
}
}
* V_65 = V_7 ;
return 0 ;
}
int F_38 ( struct V_18 * V_20 , struct V_2 * V_3 )
{
int error ;
enum V_1 V_7 ;
unsigned long V_72 = 0 ;
if ( F_17 ( F_39 () &&
! ( V_20 -> V_17 & V_28 ) ) )
return - V_35 ;
if ( V_20 -> V_17 & V_28 )
F_40 ( & V_20 -> V_29 , V_72 ) ;
else
F_41 ( & V_20 -> V_30 ) ;
F_23 ( V_20 -> V_33 , V_3 ) ;
if ( ! ( V_20 -> V_17 & V_28 ) )
error = F_29 ( V_20 , V_3 , & V_7 ) ;
else
error = F_35 ( V_20 , V_3 , & V_7 ) ;
if ( error < 0 )
goto V_73;
if ( V_7 != V_40 ) {
F_33 ( V_20 -> V_12 ,
L_19 ,
V_20 -> V_26 ,
( unsigned int ) F_34 ( V_3 ) ,
( unsigned int ) F_2 ( V_3 ) ,
F_22 ( V_7 ) ,
( unsigned int ) V_7 ) ;
error = F_20 ( V_7 ) ;
goto V_73;
}
error = 0 ;
V_73:
if ( V_20 -> V_17 & V_28 )
F_42 ( & V_20 -> V_29 , V_72 ) ;
else
F_43 ( & V_20 -> V_30 ) ;
return error ;
}
