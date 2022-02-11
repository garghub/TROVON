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
static int F_4 ( enum V_1 V_7 )
{
static const int V_11 [] = {
[ V_12 ] = 0 ,
[ V_13 ] = - V_14 ,
[ V_15 ] = - V_16 ,
[ V_17 ] = - V_18 ,
[ V_19 ] = - V_20 ,
[ V_21 ] = - V_22 ,
[ V_23 ] = - V_24 ,
[ V_25 ] = - V_26 ,
[ V_27 ] = - V_28 ,
[ V_29 ] = - V_30 ,
[ V_31 ] = - V_32 ,
} ;
if ( F_5 ( ( V_33 ) V_7 >= F_6 ( V_11 ) ) )
return - V_34 ;
return V_11 [ V_7 ] ;
}
static const char * F_7 ( enum V_1 V_7 )
{
static const char * const V_35 [] = {
[ V_12 ] = L_1 ,
[ V_36 ] = L_2 ,
[ V_13 ] = L_3 ,
[ V_15 ] = L_4 ,
[ V_17 ] = L_5 ,
[ V_19 ] = L_6 ,
[ V_21 ] = L_7 ,
[ V_23 ] = L_8 ,
[ V_25 ] = L_9 ,
[ V_27 ] = L_10 ,
[ V_29 ] = L_11 ,
[ V_31 ] = L_12
} ;
if ( ( unsigned int ) V_7 >= F_6 ( V_35 ) )
return L_13 ;
return V_35 [ V_7 ] ;
}
static inline void F_8 ( struct V_2 T_2 * V_37 ,
struct V_2 * V_3 )
{
int V_38 ;
for ( V_38 = 0 ; V_38 < V_39 ; V_38 ++ )
F_9 ( V_3 -> V_40 [ V_38 ] , & V_37 -> V_40 [ V_38 ] ) ;
F_10 () ;
F_9 ( V_3 -> V_6 , & V_37 -> V_6 ) ;
}
static inline enum V_1 F_11 ( struct V_2 T_2 *
V_37 ,
struct V_2 * V_41 )
{
int V_38 ;
enum V_1 V_7 ;
F_12 () ;
V_41 -> V_6 = F_13 ( & V_37 -> V_6 ) ;
F_12 () ;
V_7 = F_1 ( V_41 ) ;
if ( V_7 != V_12 )
return V_7 ;
for ( V_38 = 0 ; V_38 < V_39 ; V_38 ++ )
V_41 -> V_40 [ V_38 ] = F_13 ( & V_37 -> V_40 [ V_38 ] ) ;
F_12 () ;
return V_7 ;
}
static int F_14 ( struct V_42 * V_43 ,
struct V_2 * V_3 ,
enum V_1 * V_44 )
{
enum V_1 V_7 ;
unsigned long V_45 =
V_46 + F_15 ( V_47 ) ;
for (; ; ) {
V_7 = F_11 ( V_43 -> V_48 , V_3 ) ;
if ( V_7 != V_36 )
break;
F_16 ( V_49 ,
V_50 ) ;
if ( F_17 ( V_46 , V_45 ) ) {
F_18 ( V_43 -> V_51 ,
L_14 ,
V_43 -> V_52 ,
( unsigned int ) F_19 ( V_3 ) ,
( unsigned int ) F_2 ( V_3 ) ) ;
return - V_22 ;
}
}
* V_44 = V_7 ;
return 0 ;
}
static int F_20 ( struct V_42 * V_43 ,
struct V_2 * V_3 ,
enum V_1 * V_44 )
{
enum V_1 V_7 ;
unsigned long V_53 = V_47 * 1000 ;
F_21 ( ( V_47 * 1000 ) %
V_50 != 0 ) ;
for (; ; ) {
V_7 = F_11 ( V_43 -> V_48 , V_3 ) ;
if ( V_7 != V_36 )
break;
F_22 ( V_50 ) ;
V_53 -= V_50 ;
if ( V_53 == 0 ) {
F_18 ( V_43 -> V_51 ,
L_14 ,
V_43 -> V_52 ,
( unsigned int ) F_19 ( V_3 ) ,
( unsigned int ) F_2 ( V_3 ) ) ;
return - V_22 ;
}
}
* V_44 = V_7 ;
return 0 ;
}
int F_23 ( struct V_42 * V_43 , struct V_2 * V_3 )
{
int error ;
enum V_1 V_7 ;
unsigned long V_54 = 0 ;
if ( F_5 ( F_24 () &&
! ( V_43 -> V_55 & V_56 ) ) )
return - V_34 ;
if ( V_43 -> V_55 & V_56 )
F_25 ( & V_43 -> V_57 , V_54 ) ;
else
F_26 ( & V_43 -> V_58 ) ;
F_8 ( V_43 -> V_48 , V_3 ) ;
if ( ! ( V_43 -> V_55 & V_56 ) )
error = F_14 ( V_43 , V_3 , & V_7 ) ;
else
error = F_20 ( V_43 , V_3 , & V_7 ) ;
if ( error < 0 )
goto V_59;
if ( V_7 != V_12 ) {
F_18 ( V_43 -> V_51 ,
L_15 ,
V_43 -> V_52 ,
( unsigned int ) F_19 ( V_3 ) ,
( unsigned int ) F_2 ( V_3 ) ,
F_7 ( V_7 ) ,
( unsigned int ) V_7 ) ;
error = F_4 ( V_7 ) ;
goto V_59;
}
error = 0 ;
V_59:
if ( V_43 -> V_55 & V_56 )
F_27 ( & V_43 -> V_57 , V_54 ) ;
else
F_28 ( & V_43 -> V_58 ) ;
return error ;
}
