static inline struct V_1 * F_1 (
struct V_2 * V_3 )
{
return (struct V_1 * ) V_3 -> V_4 ;
}
static inline T_1 F_2 ( const T_2 * V_5 , const T_2 * V_6 )
{
T_2 V_7 [] = {
~ V_5 [ 0 ] , ~ V_5 [ 1 ] , V_6 [ 0 ] , V_6 [ 1 ] ,
} ;
return F_3 ( V_7 , sizeof( V_7 ) , 0 ) ;
}
static inline T_1 F_4 ( struct V_8 * V_9 , struct V_1 * V_10 )
{
if ( * ( V_11 * ) & V_9 -> V_12 == V_10 -> V_13 )
return V_10 -> V_14 ;
else
return F_2 ( ( T_2 * ) & V_9 -> V_12 ,
( T_2 * ) & V_10 -> V_15 ) ;
}
static void F_5 ( struct V_16 * V_17 , struct V_1 * V_10 )
{
T_1 V_7 ;
struct V_8 * V_9 = F_6 ( V_17 ) ;
T_3 V_18 = sizeof( struct V_8 ) ;
switch ( V_9 -> V_19 ) {
case V_20 :
if ( F_7 ( F_8 ( V_17 , V_18 + sizeof( struct V_21 ) ) ) ) {
struct V_21 * V_22 = (struct V_21 * )
( F_9 ( V_17 ) + V_18 ) ;
V_7 = F_4 ( V_9 , V_10 ) ;
F_10 ( & V_22 -> V_23 , V_17 ,
V_7 , true ) ;
}
break;
case V_24 :
if ( F_7 ( F_8 ( V_17 , V_18 + sizeof( struct V_25 ) ) ) ) {
struct V_25 * V_26 = (struct V_25 * )
( F_9 ( V_17 ) + V_18 ) ;
if ( V_26 -> V_23 || V_17 -> V_27 == V_28 ) {
V_7 = F_4 ( V_9 , V_10 ) ;
F_10 ( & V_26 -> V_23 , V_17 ,
V_7 , true ) ;
if ( ! V_26 -> V_23 )
V_26 -> V_23 = V_29 ;
}
}
break;
case V_30 :
if ( F_7 ( F_8 ( V_17 ,
V_18 + sizeof( struct V_31 ) ) ) ) {
struct V_31 * V_32 = (struct V_31 * )
( F_9 ( V_17 ) + V_18 ) ;
V_7 = F_4 ( V_9 , V_10 ) ;
F_10 ( & V_32 -> V_33 , V_17 ,
V_7 , true ) ;
}
break;
}
* ( V_11 * ) & V_9 -> V_12 = V_10 -> V_15 ;
}
static int F_11 ( struct V_34 * V_35 , struct V_16 * V_17 )
{
struct V_36 * V_37 = F_12 ( V_17 ) ;
if ( V_17 -> V_38 != F_13 ( V_39 ) )
goto V_40;
F_5 ( V_17 , F_1 ( V_37 -> V_41 ) ) ;
return V_37 -> V_41 -> V_42 ( V_35 , V_17 ) ;
V_40:
F_14 ( V_17 ) ;
return - V_43 ;
}
static int F_15 ( struct V_16 * V_17 )
{
struct V_36 * V_37 = F_12 ( V_17 ) ;
if ( V_17 -> V_38 != F_13 ( V_39 ) )
goto V_40;
F_5 ( V_17 , F_1 ( V_37 -> V_41 ) ) ;
return V_37 -> V_41 -> V_44 ( V_17 ) ;
V_40:
F_14 ( V_17 ) ;
return - V_43 ;
}
static int F_16 ( struct V_45 * V_46 , struct V_47 * V_48 ,
unsigned int V_49 , const void * V_50 ,
struct V_2 * * V_51 )
{
struct V_1 * V_10 ;
struct V_47 * V_52 [ V_53 + 1 ] ;
T_3 V_54 = sizeof( * V_10 ) ;
struct V_2 * V_55 ;
const struct V_56 * V_57 = V_50 ;
int V_58 ;
if ( V_49 != V_59 )
return - V_43 ;
V_58 = F_17 ( V_52 , V_53 , V_48 ,
V_60 ) ;
if ( V_58 < 0 )
return V_58 ;
if ( ! V_52 [ V_61 ] )
return - V_43 ;
V_55 = F_18 ( V_54 ) ;
if ( ! V_55 )
return - V_62 ;
V_55 -> V_63 = V_54 ;
V_10 = F_1 ( V_55 ) ;
V_10 -> V_15 = ( V_64 V_11 ) F_19 ( V_52 [ V_61 ] ) ;
if ( V_57 -> V_65 > sizeof( V_11 ) ) {
V_10 -> V_13 = * ( V_11 * ) & V_57 -> V_66 ;
V_10 -> V_14 = F_2 (
( T_2 * ) & V_10 -> V_13 , ( T_2 * ) & V_10 -> V_15 ) ;
}
V_55 -> type = V_67 ;
V_55 -> V_68 |= V_69 |
V_70 ;
* V_51 = V_55 ;
return 0 ;
}
static int F_20 ( struct V_16 * V_17 ,
struct V_2 * V_41 )
{
struct V_1 * V_10 = F_1 ( V_41 ) ;
if ( F_21 ( V_17 , V_61 , ( V_64 V_71 ) V_10 -> V_15 ) )
goto V_72;
return 0 ;
V_72:
return - V_73 ;
}
static int F_22 ( struct V_2 * V_41 )
{
return 0 ;
}
static int F_23 ( struct V_2 * V_74 , struct V_2 * V_75 )
{
struct V_1 * V_76 = F_1 ( V_74 ) ;
struct V_1 * V_77 = F_1 ( V_75 ) ;
return ( V_76 -> V_15 != V_77 -> V_15 ) ;
}
static int T_4 F_24 ( void )
{
return F_25 ( & V_78 , V_67 ) ;
}
static void T_5 F_26 ( void )
{
F_27 ( & V_78 , V_67 ) ;
}
