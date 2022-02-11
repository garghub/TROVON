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
V_32 = F_17 ( V_8 , V_31 , 0 , V_33 ) ;
if ( F_18 ( V_32 ) )
return V_32 ;
V_28 = F_19 ( V_8 ) ;
F_20 ( V_8 , V_31 ) ;
F_21 ( V_8 ) ;
F_22 ( V_8 ) ;
V_27 = F_19 ( V_8 ) ;
F_23 ( V_27 , F_24 ( F_25 ( V_28 ) ) ,
F_26 ( V_28 ) ) ;
V_27 -> V_34 = V_28 -> V_34 ;
V_27 -> V_35 = V_36 ;
V_29 = ( void * ) V_27 + sizeof( * V_27 ) ;
memcpy ( V_29 , V_25 , V_30 ) ;
V_29 -> V_35 = V_37 ;
V_27 -> V_18 = V_29 -> V_38 [ V_29 -> V_39 ] ;
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
struct V_26 * V_27 , * V_40 ;
struct V_24 * V_29 ;
int V_30 , V_32 ;
V_30 = ( V_25 -> V_30 + 1 ) << 3 ;
V_32 = F_17 ( V_8 , V_30 , 0 , V_33 ) ;
if ( F_18 ( V_32 ) )
return V_32 ;
V_40 = F_19 ( V_8 ) ;
F_32 ( V_8 , sizeof( struct V_26 ) ) ;
F_33 ( V_8 , F_34 ( V_8 ) ,
sizeof( struct V_26 ) ) ;
F_20 ( V_8 , sizeof( struct V_26 ) + V_30 ) ;
F_21 ( V_8 ) ;
F_22 ( V_8 ) ;
V_27 = F_19 ( V_8 ) ;
memmove ( V_27 , V_40 , sizeof( * V_27 ) ) ;
V_29 = ( void * ) V_27 + sizeof( * V_27 ) ;
memcpy ( V_29 , V_25 , V_30 ) ;
V_29 -> V_35 = V_27 -> V_35 ;
V_27 -> V_35 = V_36 ;
V_29 -> V_38 [ 0 ] = V_27 -> V_18 ;
V_27 -> V_18 = V_29 -> V_38 [ V_29 -> V_39 ] ;
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
struct V_41 * V_42 = F_16 ( V_8 ) ;
struct V_5 * V_43 ;
int V_32 = 0 ;
V_43 = F_2 ( V_42 -> V_44 ) ;
if ( F_36 ( ! V_8 -> V_45 ) ) {
F_37 ( V_8 ) ;
V_8 -> V_45 = 1 ;
}
switch ( V_43 -> V_46 ) {
#ifdef F_38
case V_47 :
V_32 = F_31 ( V_8 , V_43 -> V_48 ) ;
F_37 ( V_8 ) ;
break;
#endif
case V_49 :
V_32 = F_14 ( V_8 , V_43 -> V_48 ) ;
break;
}
if ( V_32 )
return V_32 ;
F_19 ( V_8 ) -> V_50 = F_39 ( V_8 -> V_12 - sizeof( struct V_26 ) ) ;
F_40 ( V_8 , sizeof( struct V_26 ) ) ;
F_41 ( V_8 , V_8 -> V_51 ) ;
return 0 ;
}
static int F_42 ( struct V_7 * V_8 )
{
int V_32 ;
V_32 = F_35 ( V_8 ) ;
if ( F_18 ( V_32 ) ) {
F_43 ( V_8 ) ;
return V_32 ;
}
F_44 ( V_8 ) ;
F_45 ( V_8 ) ;
return F_46 ( V_8 ) ;
}
static int F_47 ( struct V_14 * V_14 , struct V_52 * V_53 , struct V_7 * V_8 )
{
struct V_41 * V_54 = F_16 ( V_8 ) ;
struct V_41 * V_42 = NULL ;
struct V_1 * V_55 ;
int V_32 = - V_56 ;
V_32 = F_35 ( V_8 ) ;
if ( F_18 ( V_32 ) )
goto V_57;
V_55 = F_1 ( V_54 -> V_44 ) ;
#ifdef F_48
F_49 () ;
V_42 = F_50 ( & V_55 -> V_58 ) ;
F_51 () ;
#endif
if ( F_18 ( ! V_42 ) ) {
struct V_26 * V_27 = F_19 ( V_8 ) ;
struct V_59 V_60 ;
V_60 . V_18 = V_27 -> V_18 ;
V_60 . V_19 = V_27 -> V_19 ;
V_60 . V_61 = F_25 ( V_27 ) ;
V_60 . V_62 = V_8 -> V_63 ;
V_60 . V_64 = V_27 -> V_35 ;
V_42 = F_52 ( V_14 , NULL , & V_60 ) ;
if ( V_42 -> error ) {
V_32 = V_42 -> error ;
F_53 ( V_42 ) ;
goto V_57;
}
#ifdef F_48
F_49 () ;
F_54 ( & V_55 -> V_58 , V_42 , & V_60 . V_19 ) ;
F_51 () ;
#endif
}
F_44 ( V_8 ) ;
F_55 ( V_8 , V_42 ) ;
return F_56 ( V_14 , V_53 , V_8 ) ;
V_57:
F_43 ( V_8 ) ;
return V_32 ;
}
static int F_57 ( struct V_10 * V_11 ,
unsigned int V_65 , const void * V_66 ,
struct V_2 * * V_67 )
{
struct V_10 * V_68 [ V_69 + 1 ] ;
struct V_5 * V_6 ;
struct V_2 * V_70 ;
int V_71 , V_72 ;
struct V_1 * V_55 ;
int V_32 ;
V_32 = F_58 ( V_68 , V_69 , V_11 ,
V_73 ) ;
if ( V_32 < 0 )
return V_32 ;
if ( ! V_68 [ V_74 ] )
return - V_56 ;
V_6 = F_6 ( V_68 [ V_74 ] ) ;
V_71 = F_59 ( V_68 [ V_74 ] ) ;
V_72 = sizeof( * V_6 ) + sizeof( struct V_24 ) +
sizeof( struct V_17 ) ;
if ( V_71 < V_72 )
return - V_56 ;
switch ( V_6 -> V_46 ) {
#ifdef F_38
case V_47 :
break;
#endif
case V_49 :
break;
default:
return - V_56 ;
}
if ( ! F_60 ( V_6 -> V_48 , V_71 - sizeof( * V_6 ) ) )
return - V_56 ;
V_70 = F_61 ( V_71 + sizeof( * V_55 ) ) ;
if ( ! V_70 )
return - V_75 ;
V_55 = F_1 ( V_70 ) ;
#ifdef F_48
V_32 = F_62 ( & V_55 -> V_58 , V_76 ) ;
if ( V_32 ) {
F_63 ( V_70 ) ;
return V_32 ;
}
#endif
memcpy ( & V_55 -> V_6 , V_6 , V_71 ) ;
V_70 -> type = V_77 ;
V_70 -> V_78 |= V_79 |
V_80 ;
V_70 -> V_81 = F_64 ( V_6 ) ;
* V_67 = V_70 ;
return 0 ;
}
static void F_65 ( struct V_2 * V_3 )
{
F_66 ( & F_1 ( V_3 ) -> V_58 ) ;
}
static int F_67 ( struct V_7 * V_8 ,
struct V_2 * V_44 )
{
struct V_5 * V_6 = F_2 ( V_44 ) ;
if ( F_3 ( V_8 , V_74 , V_6 ) )
return - V_13 ;
return 0 ;
}
static int F_68 ( struct V_2 * V_44 )
{
struct V_5 * V_6 = F_2 ( V_44 ) ;
return F_69 ( F_4 ( V_6 ) ) ;
}
static int F_70 ( struct V_2 * V_82 , struct V_2 * V_83 )
{
struct V_5 * V_84 = F_2 ( V_82 ) ;
struct V_5 * V_85 = F_2 ( V_83 ) ;
int V_12 = F_4 ( V_84 ) ;
if ( V_12 != F_4 ( V_85 ) )
return 1 ;
return memcmp ( V_84 , V_85 , V_12 ) ;
}
int T_1 F_71 ( void )
{
return F_72 ( & V_86 , V_77 ) ;
}
void F_73 ( void )
{
F_74 ( & V_86 , V_77 ) ;
}
