static inline struct V_1 * F_1 ( T_1 * V_2 )
{
return (struct V_1 * ) V_2 -> F_1 ;
}
static int F_2 ( struct V_3 * V_4 , struct V_5 * V_6 ,
T_2 type , const void * V_7 , const void * V_8 ,
unsigned int V_9 )
{
struct V_10 * V_11 ;
#ifdef F_3
F_4 ( V_12 L_1 , V_6 -> V_13 ) ;
#endif
F_5 ( V_4 , sizeof( struct V_10 ) ) ;
V_11 = (struct V_10 * ) V_4 -> V_11 ;
if ( type == V_14 )
V_11 -> V_15 = V_16 ;
else
V_11 -> V_15 = V_17 ;
V_11 -> V_18 = 0 ;
V_11 -> V_19 = F_6 ( type ) ;
return sizeof( struct V_10 ) ;
}
static void F_7 ( struct V_5 * V_6 , T_3 type ,
T_4 V_20 , T_4 V_21 )
{
struct V_3 * V_4 ;
struct V_22 * V_11 ;
V_4 = F_8 ( sizeof( struct V_10 ) +
sizeof( struct V_22 ) ) ;
if ( ! V_4 ) {
F_4 ( V_23
L_2 ,
V_6 -> V_13 ) ;
return;
}
F_9 ( V_4 , 4 ) ;
F_2 ( V_4 , V_6 , V_14 , NULL , NULL , 0 ) ;
V_11 = (struct V_22 * ) ( V_4 -> V_11 + 4 ) ;
V_11 -> type = F_10 ( type ) ;
V_11 -> V_20 = V_20 ;
V_11 -> V_21 = V_21 ;
V_11 -> V_24 = F_11 ( 0xFFFF ) ;
V_11 -> time = F_10 ( ( V_25 - V_26 ) * ( 1000 / V_27 ) ) ;
F_12 ( V_4 , sizeof( struct V_22 ) ) ;
V_4 -> V_28 = V_29 ;
V_4 -> V_6 = V_6 ;
F_13 ( V_4 ) ;
F_14 ( V_4 ) ;
}
static T_5 F_15 ( struct V_3 * V_4 , struct V_5 * V_6 )
{
struct V_10 * V_11 = (struct V_10 * ) V_4 -> V_11 ;
if ( V_4 -> V_9 < sizeof( struct V_10 ) )
return F_11 ( V_30 ) ;
if ( V_11 -> V_15 != V_16 &&
V_11 -> V_15 != V_17 )
return F_11 ( V_30 ) ;
switch ( V_11 -> V_19 ) {
case F_11 ( V_31 ) :
case F_11 ( V_32 ) :
case F_11 ( V_33 ) :
F_16 ( V_4 , sizeof( struct V_10 ) ) ;
return V_11 -> V_19 ;
default:
return F_11 ( V_30 ) ;
}
}
static int F_17 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_6 ;
T_1 * V_2 = F_18 ( V_6 ) ;
struct V_1 * V_34 = F_1 ( V_2 ) ;
struct V_10 * V_11 = (struct V_10 * ) V_4 -> V_11 ;
struct V_22 * V_35 ;
struct V_36 * V_37 ;
T_4 V_38 , V_39 ;
T_3 V_40 ;
if ( V_4 -> V_9 < sizeof( struct V_10 ) )
goto V_41;
if ( V_11 -> V_15 != V_16 &&
V_11 -> V_15 != V_17 )
goto V_41;
switch ( F_19 ( V_11 -> V_19 ) ) {
case V_42 :
F_20 ( V_4 ) ;
return V_43 ;
case V_14 :
if ( ( V_4 -> V_9 != sizeof( struct V_10 ) +
V_44 ) &&
( V_4 -> V_9 != sizeof( struct V_10 ) +
V_45 ) ) {
F_4 ( V_46 L_3
L_4 , V_6 -> V_13 , V_4 -> V_9 ) ;
goto V_41;
}
V_35 = (struct V_22 * ) ( V_4 -> V_11 + sizeof
( struct V_10 ) ) ;
switch ( F_21 ( V_35 -> type ) ) {
case V_47 :
F_22 () ;
V_37 = F_23 ( V_6 ) ;
V_38 = 0 ;
V_39 = ~ F_24 ( 0 ) ;
if ( V_37 != NULL ) {
struct V_48 * * V_49 = & V_37 -> V_50 ;
while ( * V_49 != NULL ) {
if ( strcmp ( V_6 -> V_13 ,
( * V_49 ) -> V_51 ) == 0 ) {
V_38 = ( * V_49 ) -> V_52 ;
V_39 = ( * V_49 ) -> V_53 ;
break;
}
V_49 = & ( * V_49 ) -> V_54 ;
}
F_7 ( V_6 , V_55 ,
V_38 , V_39 ) ;
}
F_25 () ;
F_20 ( V_4 ) ;
return V_43 ;
case V_55 :
F_4 ( V_46 L_5
L_6 , V_6 -> V_13 ) ;
goto V_41;
case V_56 :
F_26 ( & V_34 -> V_57 ) ;
V_34 -> V_58 = F_21 ( V_35 -> V_20 ) ;
V_40 = F_21 ( V_35 -> V_21 ) ;
if ( V_40 && ( V_40 == V_34 -> V_59 ||
V_40 == V_34 -> V_59 - 1 ) ) {
V_34 -> V_60 = V_25 ;
if ( ! V_34 -> V_61 ) {
T_3 V_62 , V_63 , V_64 , V_65 ;
V_62 = F_21 ( V_35 -> time ) / 1000 ;
V_63 = V_62 / 60 ; V_62 -= V_63 * 60 ;
V_64 = V_63 / 60 ; V_63 -= V_64 * 60 ;
V_65 = V_64 / 24 ; V_64 -= V_65 * 24 ;
F_4 ( V_46 L_7
L_8 ,
V_6 -> V_13 , V_65 , V_64 , V_63 , V_62 ) ;
F_27 ( V_6 ) ;
V_34 -> V_61 = 1 ;
}
}
F_28 ( & V_34 -> V_57 ) ;
F_20 ( V_4 ) ;
return V_43 ;
}
}
F_4 ( V_46 L_9 , V_6 -> V_13 ,
F_19 ( V_11 -> V_19 ) ) ;
F_20 ( V_4 ) ;
return V_66 ;
V_41:
V_6 -> V_67 . V_68 ++ ;
F_20 ( V_4 ) ;
return V_66 ;
}
static void F_29 ( unsigned long V_69 )
{
struct V_5 * V_6 = (struct V_5 * ) V_69 ;
T_1 * V_2 = F_18 ( V_6 ) ;
struct V_1 * V_34 = F_1 ( V_2 ) ;
F_26 ( & V_34 -> V_57 ) ;
if ( V_34 -> V_61 &&
F_30 ( V_25 , V_34 -> V_60 + V_34 -> V_70 . V_71 * V_27 ) ) {
V_34 -> V_61 = 0 ;
F_4 ( V_46 L_10 , V_6 -> V_13 ) ;
F_31 ( V_6 ) ;
}
F_7 ( V_6 , V_56 , F_10 ( ++ V_34 -> V_59 ) ,
F_10 ( V_34 -> V_58 ) ) ;
F_28 ( & V_34 -> V_57 ) ;
V_34 -> V_72 . V_73 = V_25 + V_34 -> V_70 . V_74 * V_27 ;
V_34 -> V_72 . V_75 = F_29 ;
V_34 -> V_72 . V_11 = V_69 ;
F_32 ( & V_34 -> V_72 ) ;
}
static void F_33 ( struct V_5 * V_6 )
{
T_1 * V_2 = F_18 ( V_6 ) ;
struct V_1 * V_34 = F_1 ( V_2 ) ;
unsigned long V_76 ;
F_34 ( & V_34 -> V_57 , V_76 ) ;
V_34 -> V_61 = V_34 -> V_59 = V_34 -> V_58 = 0 ;
F_35 ( & V_34 -> V_57 , V_76 ) ;
F_36 ( & V_34 -> V_72 ) ;
V_34 -> V_72 . V_73 = V_25 + V_27 ;
V_34 -> V_72 . V_75 = F_29 ;
V_34 -> V_72 . V_11 = ( unsigned long ) V_6 ;
F_32 ( & V_34 -> V_72 ) ;
}
static void F_37 ( struct V_5 * V_6 )
{
T_1 * V_2 = F_18 ( V_6 ) ;
struct V_1 * V_34 = F_1 ( V_2 ) ;
unsigned long V_76 ;
F_38 ( & V_34 -> V_72 ) ;
F_34 ( & V_34 -> V_57 , V_76 ) ;
F_31 ( V_6 ) ;
V_34 -> V_61 = V_34 -> V_59 = 0 ;
F_35 ( & V_34 -> V_57 , V_76 ) ;
}
static int F_39 ( struct V_5 * V_6 , struct V_77 * V_78 )
{
T_6 T_7 * V_79 = V_78 -> V_80 . V_81 . V_82 ;
const T_8 V_83 = sizeof( T_6 ) ;
T_6 V_84 ;
T_1 * V_2 = F_18 ( V_6 ) ;
int V_85 ;
switch ( V_78 -> V_80 . type ) {
case V_86 :
if ( F_18 ( V_6 ) -> V_87 != & V_87 )
return - V_88 ;
V_78 -> V_80 . type = V_89 ;
if ( V_78 -> V_80 . V_83 < V_83 ) {
V_78 -> V_80 . V_83 = V_83 ;
return - V_90 ;
}
if ( F_40 ( V_79 , & F_1 ( V_2 ) -> V_70 , V_83 ) )
return - V_91 ;
return 0 ;
case V_89 :
if ( ! F_41 ( V_92 ) )
return - V_93 ;
if ( V_6 -> V_76 & V_94 )
return - V_95 ;
if ( F_42 ( & V_84 , V_79 , V_83 ) )
return - V_91 ;
if ( V_84 . V_74 < 1 ||
V_84 . V_71 < 2 )
return - V_88 ;
V_85 = V_2 -> V_96 ( V_6 , V_97 , V_98 ) ;
if ( V_85 )
return V_85 ;
V_85 = F_43 ( V_6 , & V_87 ,
sizeof( struct V_1 ) ) ;
if ( V_85 )
return V_85 ;
memcpy ( & F_1 ( V_2 ) -> V_70 , & V_84 , V_83 ) ;
F_44 ( & F_1 ( V_2 ) -> V_57 ) ;
V_6 -> V_99 = & V_100 ;
V_6 -> type = V_101 ;
F_31 ( V_6 ) ;
return 0 ;
}
return - V_88 ;
}
static int T_9 F_45 ( void )
{
F_46 ( & V_87 ) ;
return 0 ;
}
static void T_10 F_47 ( void )
{
F_48 ( & V_87 ) ;
}
