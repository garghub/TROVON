int T_1 F_1 ( struct V_1 * V_2 ,
T_2 V_3 ,
T_3 V_4 ,
struct V_5 * V_6 ,
T_3 V_7 , struct V_8 * * V_9 )
{
int error ;
struct V_8 * V_10 ;
void T_4 * V_11 ;
struct V_12 * V_13 ;
V_10 = F_2 ( V_2 , sizeof( * V_10 ) , V_14 ) ;
if ( ! V_10 )
return - V_15 ;
V_10 -> V_2 = V_2 ;
V_10 -> V_7 = V_7 ;
V_10 -> V_16 = V_3 ;
V_10 -> V_17 = V_4 ;
if ( V_7 & V_18 )
F_3 ( & V_10 -> V_19 ) ;
else
F_4 ( & V_10 -> V_20 ) ;
V_13 = F_5 ( V_2 ,
V_3 ,
V_4 ,
L_1 ) ;
if ( ! V_13 ) {
F_6 ( V_2 ,
L_2 ,
V_3 ) ;
return - V_21 ;
}
V_11 = F_7 ( V_2 ,
V_3 ,
V_4 ) ;
if ( ! V_11 ) {
F_6 ( V_2 ,
L_3 ,
V_3 ) ;
return - V_22 ;
}
V_10 -> V_23 = V_11 ;
if ( V_6 ) {
error = F_8 ( V_10 , V_6 ) ;
if ( error < 0 )
goto V_24;
}
* V_9 = V_10 ;
return 0 ;
V_24:
F_9 ( V_10 ) ;
return error ;
}
void F_9 ( struct V_8 * V_10 )
{
struct V_5 * V_6 = V_10 -> V_6 ;
if ( V_6 )
F_10 ( V_10 ) ;
F_11 ( V_10 -> V_2 , V_10 -> V_23 ) ;
F_12 ( V_10 -> V_2 ,
V_10 -> V_16 ,
V_10 -> V_17 ) ;
V_10 -> V_23 = NULL ;
F_13 ( V_10 -> V_2 , V_10 ) ;
}
int F_8 ( struct V_8 * V_10 ,
struct V_5 * V_6 )
{
int error ;
if ( F_14 ( ! V_6 ) )
return - V_25 ;
if ( F_14 ( V_10 -> V_6 ) )
return - V_25 ;
if ( F_14 ( V_6 -> V_10 ) )
return - V_25 ;
error = F_15 ( V_10 ,
0 ,
V_6 -> V_26 . V_27 ,
& V_6 -> V_28 ) ;
if ( error < 0 )
return error ;
V_10 -> V_6 = V_6 ;
V_6 -> V_10 = V_10 ;
return 0 ;
}
void F_10 ( struct V_8 * V_10 )
{
int error ;
struct V_5 * V_6 = V_10 -> V_6 ;
if ( F_14 ( ! V_6 ) )
return;
if ( F_14 ( V_6 -> V_10 != V_10 ) )
return;
error = F_16 ( V_10 ,
0 ,
V_6 -> V_28 ) ;
if ( error < 0 ) {
F_6 ( & V_6 -> V_2 , L_4 ,
error ) ;
}
V_10 -> V_6 = NULL ;
V_6 -> V_10 = NULL ;
}
static int F_17 ( enum V_29 V_30 )
{
static const int V_31 [] = {
[ V_32 ] = 0 ,
[ V_33 ] = - V_34 ,
[ V_35 ] = - V_36 ,
[ V_37 ] = - V_38 ,
[ V_39 ] = - V_22 ,
[ V_40 ] = - V_41 ,
[ V_42 ] = - V_43 ,
[ V_44 ] = - V_15 ,
[ V_45 ] = - V_21 ,
[ V_46 ] = - V_47 ,
[ V_48 ] = - V_49 ,
} ;
if ( F_14 ( ( T_3 ) V_30 >= F_18 ( V_31 ) ) )
return - V_25 ;
return V_31 [ V_30 ] ;
}
static const char * F_19 ( enum V_29 V_30 )
{
static const char * const V_50 [] = {
[ V_32 ] = L_5 ,
[ V_51 ] = L_6 ,
[ V_33 ] = L_7 ,
[ V_35 ] = L_8 ,
[ V_37 ] = L_9 ,
[ V_39 ] = L_10 ,
[ V_40 ] = L_11 ,
[ V_42 ] = L_12 ,
[ V_44 ] = L_13 ,
[ V_45 ] = L_14 ,
[ V_46 ] = L_15 ,
[ V_48 ] = L_16
} ;
if ( ( unsigned int ) V_30 >= F_18 ( V_50 ) )
return L_17 ;
return V_50 [ V_30 ] ;
}
static inline void F_20 ( struct V_52 T_4 * V_53 ,
struct V_52 * V_54 )
{
int V_55 ;
for ( V_55 = 0 ; V_55 < V_56 ; V_55 ++ )
F_21 ( V_54 -> V_57 [ V_55 ] , & V_53 -> V_57 [ V_55 ] ) ;
F_21 ( V_54 -> V_58 , & V_53 -> V_58 ) ;
}
static inline enum V_29 F_22 ( struct V_52 T_4 *
V_53 ,
struct V_52 * V_59 )
{
int V_55 ;
enum V_29 V_30 ;
V_59 -> V_58 = F_23 ( & V_53 -> V_58 ) ;
V_30 = F_24 ( V_59 -> V_58 ) ;
if ( V_30 != V_32 )
return V_30 ;
for ( V_55 = 0 ; V_55 < V_56 ; V_55 ++ )
V_59 -> V_57 [ V_55 ] = F_23 ( & V_53 -> V_57 [ V_55 ] ) ;
return V_30 ;
}
static int F_25 ( struct V_8 * V_10 ,
struct V_52 * V_54 ,
enum V_29 * V_60 )
{
enum V_29 V_30 ;
unsigned long V_61 =
V_62 + F_26 ( V_63 ) ;
for (; ; ) {
V_30 = F_22 ( V_10 -> V_23 , V_54 ) ;
if ( V_30 != V_51 )
break;
F_27 ( V_64 ,
V_65 ) ;
if ( F_28 ( V_62 , V_61 ) ) {
F_29 ( V_10 -> V_2 ,
L_18 ,
V_10 -> V_16 ,
( unsigned int )
F_30 ( V_54 -> V_58 ) ,
( unsigned int )
F_31 ( V_54 -> V_58 ) ) ;
return - V_41 ;
}
}
* V_60 = V_30 ;
return 0 ;
}
static int F_32 ( struct V_8 * V_10 ,
struct V_52 * V_54 ,
enum V_29 * V_60 )
{
enum V_29 V_30 ;
unsigned long V_66 = V_63 * 1000 ;
F_33 ( ( V_63 * 1000 ) %
V_65 != 0 ) ;
for (; ; ) {
V_30 = F_22 ( V_10 -> V_23 , V_54 ) ;
if ( V_30 != V_51 )
break;
F_34 ( V_65 ) ;
V_66 -= V_65 ;
if ( V_66 == 0 ) {
F_29 ( V_10 -> V_2 ,
L_18 ,
V_10 -> V_16 ,
( unsigned int )
F_30 ( V_54 -> V_58 ) ,
( unsigned int )
F_31 ( V_54 -> V_58 ) ) ;
return - V_41 ;
}
}
* V_60 = V_30 ;
return 0 ;
}
int F_35 ( struct V_8 * V_10 , struct V_52 * V_54 )
{
int error ;
enum V_29 V_30 ;
unsigned long V_67 = 0 ;
if ( F_14 ( F_36 () &&
! ( V_10 -> V_7 & V_18 ) ) )
return - V_25 ;
if ( V_10 -> V_7 & V_18 )
F_37 ( & V_10 -> V_19 , V_67 ) ;
else
F_38 ( & V_10 -> V_20 ) ;
F_20 ( V_10 -> V_23 , V_54 ) ;
if ( ! ( V_10 -> V_7 & V_18 ) )
error = F_25 ( V_10 , V_54 , & V_30 ) ;
else
error = F_32 ( V_10 , V_54 , & V_30 ) ;
if ( error < 0 )
goto V_68;
if ( V_30 != V_32 ) {
F_29 ( V_10 -> V_2 ,
L_19 ,
V_10 -> V_16 ,
( unsigned int ) F_30 ( V_54 -> V_58 ) ,
( unsigned int ) F_31 ( V_54 -> V_58 ) ,
F_19 ( V_30 ) ,
( unsigned int ) V_30 ) ;
error = F_17 ( V_30 ) ;
goto V_68;
}
error = 0 ;
V_68:
if ( V_10 -> V_7 & V_18 )
F_39 ( & V_10 -> V_19 , V_67 ) ;
else
F_40 ( & V_10 -> V_20 ) ;
return error ;
}
