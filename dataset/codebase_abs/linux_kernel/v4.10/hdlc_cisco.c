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
F_9 ( V_6 , L_2 ) ;
return;
}
F_10 ( V_4 , 4 ) ;
F_2 ( V_4 , V_6 , V_14 , NULL , NULL , 0 ) ;
V_11 = (struct V_22 * ) ( V_4 -> V_11 + 4 ) ;
V_11 -> type = F_11 ( type ) ;
V_11 -> V_20 = V_20 ;
V_11 -> V_21 = V_21 ;
V_11 -> V_23 = F_12 ( 0xFFFF ) ;
V_11 -> time = F_11 ( ( V_24 - V_25 ) * ( 1000 / V_26 ) ) ;
F_13 ( V_4 , sizeof( struct V_22 ) ) ;
V_4 -> V_27 = V_28 ;
V_4 -> V_6 = V_6 ;
F_14 ( V_4 ) ;
F_15 ( V_4 ) ;
}
static T_5 F_16 ( struct V_3 * V_4 , struct V_5 * V_6 )
{
struct V_10 * V_11 = (struct V_10 * ) V_4 -> V_11 ;
if ( V_4 -> V_9 < sizeof( struct V_10 ) )
return F_12 ( V_29 ) ;
if ( V_11 -> V_15 != V_16 &&
V_11 -> V_15 != V_17 )
return F_12 ( V_29 ) ;
switch ( V_11 -> V_19 ) {
case F_12 ( V_30 ) :
case F_12 ( V_31 ) :
case F_12 ( V_32 ) :
F_17 ( V_4 , sizeof( struct V_10 ) ) ;
return V_11 -> V_19 ;
default:
return F_12 ( V_29 ) ;
}
}
static int F_18 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_6 ;
T_1 * V_2 = F_19 ( V_6 ) ;
struct V_1 * V_33 = F_1 ( V_2 ) ;
struct V_10 * V_11 = (struct V_10 * ) V_4 -> V_11 ;
struct V_22 * V_34 ;
struct V_35 * V_36 ;
T_4 V_37 , V_38 ;
T_3 V_39 ;
if ( V_4 -> V_9 < sizeof( struct V_10 ) )
goto V_40;
if ( V_11 -> V_15 != V_16 &&
V_11 -> V_15 != V_17 )
goto V_40;
switch ( F_20 ( V_11 -> V_19 ) ) {
case V_41 :
F_21 ( V_4 ) ;
return V_42 ;
case V_14 :
if ( ( V_4 -> V_9 != sizeof( struct V_10 ) +
V_43 ) &&
( V_4 -> V_9 != sizeof( struct V_10 ) +
V_44 ) ) {
F_22 ( V_6 , L_3 ,
V_4 -> V_9 ) ;
goto V_40;
}
V_34 = (struct V_22 * ) ( V_4 -> V_11 + sizeof
( struct V_10 ) ) ;
switch ( F_23 ( V_34 -> type ) ) {
case V_45 :
F_24 () ;
V_36 = F_25 ( V_6 ) ;
V_37 = 0 ;
V_38 = ~ F_26 ( 0 ) ;
if ( V_36 != NULL ) {
struct V_46 * * V_47 = & V_36 -> V_48 ;
while ( * V_47 != NULL ) {
if ( strcmp ( V_6 -> V_13 ,
( * V_47 ) -> V_49 ) == 0 ) {
V_37 = ( * V_47 ) -> V_50 ;
V_38 = ( * V_47 ) -> V_51 ;
break;
}
V_47 = & ( * V_47 ) -> V_52 ;
}
F_7 ( V_6 , V_53 ,
V_37 , V_38 ) ;
}
F_27 () ;
F_21 ( V_4 ) ;
return V_42 ;
case V_53 :
F_22 ( V_6 , L_4 ) ;
goto V_40;
case V_54 :
F_28 ( & V_33 -> V_55 ) ;
V_33 -> V_56 = F_23 ( V_34 -> V_20 ) ;
V_39 = F_23 ( V_34 -> V_21 ) ;
if ( V_39 && ( V_39 == V_33 -> V_57 ||
V_39 == V_33 -> V_57 - 1 ) ) {
V_33 -> V_58 = V_24 ;
if ( ! V_33 -> V_59 ) {
T_3 V_60 , V_61 , V_62 , V_63 ;
V_60 = F_23 ( V_34 -> time ) / 1000 ;
V_61 = V_60 / 60 ; V_60 -= V_61 * 60 ;
V_62 = V_61 / 60 ; V_61 -= V_62 * 60 ;
V_63 = V_62 / 24 ; V_62 -= V_63 * 24 ;
F_22 ( V_6 , L_5 ,
V_63 , V_62 , V_61 , V_60 ) ;
F_29 ( V_6 ) ;
V_33 -> V_59 = 1 ;
}
}
F_30 ( & V_33 -> V_55 ) ;
F_21 ( V_4 ) ;
return V_42 ;
}
}
F_22 ( V_6 , L_6 , F_20 ( V_11 -> V_19 ) ) ;
F_21 ( V_4 ) ;
return V_64 ;
V_40:
V_6 -> V_65 . V_66 ++ ;
F_21 ( V_4 ) ;
return V_64 ;
}
static void F_31 ( unsigned long V_67 )
{
struct V_5 * V_6 = (struct V_5 * ) V_67 ;
T_1 * V_2 = F_19 ( V_6 ) ;
struct V_1 * V_33 = F_1 ( V_2 ) ;
F_28 ( & V_33 -> V_55 ) ;
if ( V_33 -> V_59 &&
F_32 ( V_24 , V_33 -> V_58 + V_33 -> V_68 . V_69 * V_26 ) ) {
V_33 -> V_59 = 0 ;
F_22 ( V_6 , L_7 ) ;
F_33 ( V_6 ) ;
}
F_7 ( V_6 , V_54 , F_11 ( ++ V_33 -> V_57 ) ,
F_11 ( V_33 -> V_56 ) ) ;
F_30 ( & V_33 -> V_55 ) ;
V_33 -> V_70 . V_71 = V_24 + V_33 -> V_68 . V_72 * V_26 ;
V_33 -> V_70 . V_73 = F_31 ;
V_33 -> V_70 . V_11 = V_67 ;
F_34 ( & V_33 -> V_70 ) ;
}
static void F_35 ( struct V_5 * V_6 )
{
T_1 * V_2 = F_19 ( V_6 ) ;
struct V_1 * V_33 = F_1 ( V_2 ) ;
unsigned long V_74 ;
F_36 ( & V_33 -> V_55 , V_74 ) ;
V_33 -> V_59 = V_33 -> V_57 = V_33 -> V_56 = 0 ;
F_37 ( & V_33 -> V_55 , V_74 ) ;
F_38 ( & V_33 -> V_70 ) ;
V_33 -> V_70 . V_71 = V_24 + V_26 ;
V_33 -> V_70 . V_73 = F_31 ;
V_33 -> V_70 . V_11 = ( unsigned long ) V_6 ;
F_34 ( & V_33 -> V_70 ) ;
}
static void F_39 ( struct V_5 * V_6 )
{
T_1 * V_2 = F_19 ( V_6 ) ;
struct V_1 * V_33 = F_1 ( V_2 ) ;
unsigned long V_74 ;
F_40 ( & V_33 -> V_70 ) ;
F_36 ( & V_33 -> V_55 , V_74 ) ;
F_33 ( V_6 ) ;
V_33 -> V_59 = V_33 -> V_57 = 0 ;
F_37 ( & V_33 -> V_55 , V_74 ) ;
}
static int F_41 ( struct V_5 * V_6 , struct V_75 * V_76 )
{
T_6 T_7 * V_77 = V_76 -> V_78 . V_79 . V_80 ;
const T_8 V_81 = sizeof( T_6 ) ;
T_6 V_82 ;
T_1 * V_2 = F_19 ( V_6 ) ;
int V_83 ;
switch ( V_76 -> V_78 . type ) {
case V_84 :
if ( F_19 ( V_6 ) -> V_85 != & V_85 )
return - V_86 ;
V_76 -> V_78 . type = V_87 ;
if ( V_76 -> V_78 . V_81 < V_81 ) {
V_76 -> V_78 . V_81 = V_81 ;
return - V_88 ;
}
if ( F_42 ( V_77 , & F_1 ( V_2 ) -> V_68 , V_81 ) )
return - V_89 ;
return 0 ;
case V_87 :
if ( ! F_43 ( V_90 ) )
return - V_91 ;
if ( V_6 -> V_74 & V_92 )
return - V_93 ;
if ( F_44 ( & V_82 , V_77 , V_81 ) )
return - V_89 ;
if ( V_82 . V_72 < 1 ||
V_82 . V_69 < 2 )
return - V_86 ;
V_83 = V_2 -> V_94 ( V_6 , V_95 , V_96 ) ;
if ( V_83 )
return V_83 ;
V_83 = F_45 ( V_6 , & V_85 ,
sizeof( struct V_1 ) ) ;
if ( V_83 )
return V_83 ;
memcpy ( & F_1 ( V_2 ) -> V_68 , & V_82 , V_81 ) ;
F_46 ( & F_1 ( V_2 ) -> V_55 ) ;
V_6 -> V_97 = & V_98 ;
V_6 -> type = V_99 ;
F_47 ( V_100 , V_6 ) ;
F_33 ( V_6 ) ;
return 0 ;
}
return - V_86 ;
}
static int T_9 F_48 ( void )
{
F_49 ( & V_85 ) ;
return 0 ;
}
static void T_10 F_50 ( void )
{
F_51 ( & V_85 ) ;
}
