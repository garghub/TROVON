static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return (struct V_1 * ) V_3 -> V_4 ;
}
static inline struct V_5 *
F_2 ( struct V_2 * V_3 )
{
return F_1 ( V_3 ) -> V_6 ;
}
static int F_3 ( struct V_7 * V_8 , int V_9 ,
struct V_5 * V_6 )
{
struct V_5 * V_4 ;
struct V_10 * V_11 ;
int V_12 ;
V_12 = F_4 ( V_6 ) ;
V_11 = F_5 ( V_8 , V_9 , V_12 ) ;
if ( ! V_11 )
return - V_13 ;
V_4 = F_6 ( V_11 ) ;
memcpy ( V_4 , V_6 , V_12 ) ;
return 0 ;
}
static void F_7 ( struct V_14 * V_14 , struct V_15 * V_16 ,
struct V_17 * V_18 , struct V_17 * V_19 )
{
struct V_20 * V_21 = F_8 ( V_14 ) ;
struct V_17 * V_22 ;
F_9 () ;
V_22 = F_10 ( V_21 -> V_22 ) ;
if ( ! F_11 ( V_22 ) ) {
memcpy ( V_19 , V_22 , sizeof( struct V_17 ) ) ;
} else {
F_12 ( V_14 , V_16 , V_18 , V_23 ,
V_19 ) ;
}
F_13 () ;
}
static int F_14 ( struct V_7 * V_8 , struct V_24 * V_25 )
{
struct V_14 * V_14 = F_15 ( F_16 ( V_8 ) -> V_16 ) ;
struct V_26 * V_27 , * V_28 ;
struct V_24 * V_29 ;
int V_30 , V_31 , V_32 ;
V_30 = ( V_25 -> V_30 + 1 ) << 3 ;
V_31 = V_30 + sizeof( * V_27 ) ;
V_32 = F_17 ( V_8 , V_31 ) ;
if ( F_18 ( V_32 ) )
return V_32 ;
V_28 = F_19 ( V_8 ) ;
F_20 ( V_8 , V_31 ) ;
F_21 ( V_8 ) ;
F_22 ( V_8 ) ;
V_27 = F_19 ( V_8 ) ;
F_23 ( V_27 , F_24 ( F_25 ( V_28 ) ) ,
F_26 ( V_28 ) ) ;
V_27 -> V_33 = V_28 -> V_33 ;
V_27 -> V_34 = V_35 ;
V_29 = ( void * ) V_27 + sizeof( * V_27 ) ;
memcpy ( V_29 , V_25 , V_30 ) ;
V_29 -> V_34 = V_36 ;
V_27 -> V_18 = V_29 -> V_37 [ V_29 -> V_38 ] ;
F_7 ( V_14 , V_8 -> V_16 , & V_27 -> V_18 , & V_27 -> V_19 ) ;
#ifdef F_27
if ( F_28 ( V_29 ) ) {
V_32 = F_29 ( V_14 , & V_27 -> V_19 , V_29 ) ;
if ( F_18 ( V_32 ) )
return V_32 ;
}
#endif
F_30 ( V_8 , V_27 , V_31 ) ;
return 0 ;
}
static int F_31 ( struct V_7 * V_8 , struct V_24 * V_25 )
{
struct V_26 * V_27 , * V_39 ;
struct V_24 * V_29 ;
int V_30 , V_32 ;
V_30 = ( V_25 -> V_30 + 1 ) << 3 ;
V_32 = F_17 ( V_8 , V_30 ) ;
if ( F_18 ( V_32 ) )
return V_32 ;
V_39 = F_19 ( V_8 ) ;
F_32 ( V_8 , sizeof( struct V_26 ) ) ;
F_33 ( V_8 , F_34 ( V_8 ) ,
sizeof( struct V_26 ) ) ;
F_20 ( V_8 , sizeof( struct V_26 ) + V_30 ) ;
F_21 ( V_8 ) ;
F_22 ( V_8 ) ;
V_27 = F_19 ( V_8 ) ;
memmove ( V_27 , V_39 , sizeof( * V_27 ) ) ;
V_29 = ( void * ) V_27 + sizeof( * V_27 ) ;
memcpy ( V_29 , V_25 , V_30 ) ;
V_29 -> V_34 = V_27 -> V_34 ;
V_27 -> V_34 = V_35 ;
V_29 -> V_37 [ 0 ] = V_27 -> V_18 ;
V_27 -> V_18 = V_29 -> V_37 [ V_29 -> V_38 ] ;
#ifdef F_27
if ( F_28 ( V_29 ) ) {
struct V_14 * V_14 = F_15 ( F_16 ( V_8 ) -> V_16 ) ;
V_32 = F_29 ( V_14 , & V_27 -> V_19 , V_29 ) ;
if ( F_18 ( V_32 ) )
return V_32 ;
}
#endif
F_30 ( V_8 , V_27 , sizeof( struct V_26 ) + V_30 ) ;
return 0 ;
}
static int F_35 ( struct V_7 * V_8 )
{
struct V_40 * V_41 = F_16 ( V_8 ) ;
struct V_5 * V_42 ;
int V_32 = 0 ;
V_42 = F_2 ( V_41 -> V_43 ) ;
if ( F_36 ( ! V_8 -> V_44 ) ) {
F_37 ( V_8 ) ;
V_8 -> V_44 = 1 ;
}
switch ( V_42 -> V_45 ) {
#ifdef F_38
case V_46 :
V_32 = F_31 ( V_8 , V_42 -> V_47 ) ;
F_37 ( V_8 ) ;
break;
#endif
case V_48 :
V_32 = F_14 ( V_8 , V_42 -> V_47 ) ;
break;
}
if ( V_32 )
return V_32 ;
F_19 ( V_8 ) -> V_49 = F_39 ( V_8 -> V_12 - sizeof( struct V_26 ) ) ;
F_40 ( V_8 , sizeof( struct V_26 ) ) ;
F_41 ( V_8 , V_8 -> V_50 ) ;
return 0 ;
}
static int F_42 ( struct V_7 * V_8 )
{
struct V_40 * V_51 = F_16 ( V_8 ) ;
struct V_40 * V_41 = NULL ;
struct V_1 * V_52 ;
int V_32 ;
V_32 = F_35 ( V_8 ) ;
if ( F_18 ( V_32 ) ) {
F_43 ( V_8 ) ;
return V_32 ;
}
V_52 = F_1 ( V_51 -> V_43 ) ;
F_44 () ;
V_41 = F_45 ( & V_52 -> V_53 ) ;
F_46 () ;
F_47 ( V_8 ) ;
if ( ! V_41 ) {
F_48 ( V_8 ) ;
V_41 = F_16 ( V_8 ) ;
if ( ! V_41 -> error ) {
F_44 () ;
F_49 ( & V_52 -> V_53 , V_41 ,
& F_19 ( V_8 ) -> V_19 ) ;
F_46 () ;
}
} else {
F_50 ( V_8 , V_41 ) ;
}
V_32 = F_17 ( V_8 , F_51 ( V_41 -> V_16 ) ) ;
if ( F_18 ( V_32 ) )
return V_32 ;
return F_52 ( V_8 ) ;
}
static int F_53 ( struct V_14 * V_14 , struct V_54 * V_55 , struct V_7 * V_8 )
{
struct V_40 * V_51 = F_16 ( V_8 ) ;
struct V_40 * V_41 = NULL ;
struct V_1 * V_52 ;
int V_32 = - V_56 ;
V_32 = F_35 ( V_8 ) ;
if ( F_18 ( V_32 ) )
goto V_57;
V_52 = F_1 ( V_51 -> V_43 ) ;
F_44 () ;
V_41 = F_45 ( & V_52 -> V_53 ) ;
F_46 () ;
if ( F_18 ( ! V_41 ) ) {
struct V_26 * V_27 = F_19 ( V_8 ) ;
struct V_58 V_59 ;
V_59 . V_18 = V_27 -> V_18 ;
V_59 . V_19 = V_27 -> V_19 ;
V_59 . V_60 = F_25 ( V_27 ) ;
V_59 . V_61 = V_8 -> V_62 ;
V_59 . V_63 = V_27 -> V_34 ;
V_41 = F_54 ( V_14 , NULL , & V_59 ) ;
if ( V_41 -> error ) {
V_32 = V_41 -> error ;
F_55 ( V_41 ) ;
goto V_57;
}
F_44 () ;
F_49 ( & V_52 -> V_53 , V_41 , & V_59 . V_19 ) ;
F_46 () ;
}
F_47 ( V_8 ) ;
F_50 ( V_8 , V_41 ) ;
V_32 = F_17 ( V_8 , F_51 ( V_41 -> V_16 ) ) ;
if ( F_18 ( V_32 ) )
goto V_57;
return F_56 ( V_14 , V_55 , V_8 ) ;
V_57:
F_43 ( V_8 ) ;
return V_32 ;
}
static int F_57 ( struct V_10 * V_11 ,
unsigned int V_64 , const void * V_65 ,
struct V_2 * * V_66 )
{
struct V_10 * V_67 [ V_68 + 1 ] ;
struct V_5 * V_6 ;
struct V_2 * V_69 ;
int V_70 , V_71 ;
struct V_1 * V_52 ;
int V_32 ;
V_32 = F_58 ( V_67 , V_68 , V_11 ,
V_72 , NULL ) ;
if ( V_32 < 0 )
return V_32 ;
if ( ! V_67 [ V_73 ] )
return - V_56 ;
V_6 = F_6 ( V_67 [ V_73 ] ) ;
V_70 = F_59 ( V_67 [ V_73 ] ) ;
V_71 = sizeof( * V_6 ) + sizeof( struct V_24 ) +
sizeof( struct V_17 ) ;
if ( V_70 < V_71 )
return - V_56 ;
switch ( V_6 -> V_45 ) {
#ifdef F_38
case V_46 :
break;
#endif
case V_48 :
break;
default:
return - V_56 ;
}
if ( ! F_60 ( V_6 -> V_47 , V_70 - sizeof( * V_6 ) ) )
return - V_56 ;
V_69 = F_61 ( V_70 + sizeof( * V_52 ) ) ;
if ( ! V_69 )
return - V_74 ;
V_52 = F_1 ( V_69 ) ;
V_32 = F_62 ( & V_52 -> V_53 , V_75 ) ;
if ( V_32 ) {
F_63 ( V_69 ) ;
return V_32 ;
}
memcpy ( & V_52 -> V_6 , V_6 , V_70 ) ;
V_69 -> type = V_76 ;
V_69 -> V_77 |= V_78 |
V_79 ;
V_69 -> V_80 = F_64 ( V_6 ) ;
* V_66 = V_69 ;
return 0 ;
}
static void F_65 ( struct V_2 * V_3 )
{
F_66 ( & F_1 ( V_3 ) -> V_53 ) ;
}
static int F_67 ( struct V_7 * V_8 ,
struct V_2 * V_43 )
{
struct V_5 * V_6 = F_2 ( V_43 ) ;
if ( F_3 ( V_8 , V_73 , V_6 ) )
return - V_13 ;
return 0 ;
}
static int F_68 ( struct V_2 * V_43 )
{
struct V_5 * V_6 = F_2 ( V_43 ) ;
return F_69 ( F_4 ( V_6 ) ) ;
}
static int F_70 ( struct V_2 * V_81 , struct V_2 * V_82 )
{
struct V_5 * V_83 = F_2 ( V_81 ) ;
struct V_5 * V_84 = F_2 ( V_82 ) ;
int V_12 = F_4 ( V_83 ) ;
if ( V_12 != F_4 ( V_84 ) )
return 1 ;
return memcmp ( V_83 , V_84 , V_12 ) ;
}
int T_1 F_71 ( void )
{
return F_72 ( & V_85 , V_76 ) ;
}
void F_73 ( void )
{
F_74 ( & V_85 , V_76 ) ;
}
