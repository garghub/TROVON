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
int F_14 ( struct V_7 * V_8 , struct V_24 * V_25 , int V_26 )
{
struct V_14 * V_14 = F_15 ( F_16 ( V_8 ) -> V_16 ) ;
struct V_27 * V_28 , * V_29 ;
struct V_24 * V_30 ;
int V_31 , V_32 , V_33 ;
V_31 = ( V_25 -> V_31 + 1 ) << 3 ;
V_32 = V_31 + sizeof( * V_28 ) ;
V_33 = F_17 ( V_8 , V_32 ) ;
if ( F_18 ( V_33 ) )
return V_33 ;
V_29 = F_19 ( V_8 ) ;
F_20 ( V_8 , V_32 ) ;
F_21 ( V_8 ) ;
F_22 ( V_8 ) ;
V_28 = F_19 ( V_8 ) ;
if ( V_8 -> V_34 == F_23 ( V_35 ) ) {
F_24 ( V_28 , F_25 ( F_26 ( V_29 ) ) ,
F_27 ( V_29 ) ) ;
V_28 -> V_36 = V_29 -> V_36 ;
} else {
F_24 ( V_28 , 0 , 0 ) ;
V_28 -> V_36 = F_28 ( F_16 ( V_8 ) ) ;
}
V_28 -> V_37 = V_38 ;
V_30 = ( void * ) V_28 + sizeof( * V_28 ) ;
memcpy ( V_30 , V_25 , V_31 ) ;
V_30 -> V_37 = V_26 ;
V_28 -> V_18 = V_30 -> V_39 [ V_30 -> V_40 ] ;
F_7 ( V_14 , V_8 -> V_16 , & V_28 -> V_18 , & V_28 -> V_19 ) ;
#ifdef F_29
if ( F_30 ( V_30 ) ) {
V_33 = F_31 ( V_14 , & V_28 -> V_19 , V_30 ) ;
if ( F_18 ( V_33 ) )
return V_33 ;
}
#endif
F_32 ( V_8 , V_28 , V_32 ) ;
return 0 ;
}
int F_33 ( struct V_7 * V_8 , struct V_24 * V_25 )
{
struct V_27 * V_28 , * V_41 ;
struct V_24 * V_30 ;
int V_31 , V_33 ;
V_31 = ( V_25 -> V_31 + 1 ) << 3 ;
V_33 = F_17 ( V_8 , V_31 ) ;
if ( F_18 ( V_33 ) )
return V_33 ;
V_41 = F_19 ( V_8 ) ;
F_34 ( V_8 , sizeof( struct V_27 ) ) ;
F_35 ( V_8 , F_36 ( V_8 ) ,
sizeof( struct V_27 ) ) ;
F_20 ( V_8 , sizeof( struct V_27 ) + V_31 ) ;
F_21 ( V_8 ) ;
F_22 ( V_8 ) ;
V_28 = F_19 ( V_8 ) ;
memmove ( V_28 , V_41 , sizeof( * V_28 ) ) ;
V_30 = ( void * ) V_28 + sizeof( * V_28 ) ;
memcpy ( V_30 , V_25 , V_31 ) ;
V_30 -> V_37 = V_28 -> V_37 ;
V_28 -> V_37 = V_38 ;
V_30 -> V_39 [ 0 ] = V_28 -> V_18 ;
V_28 -> V_18 = V_30 -> V_39 [ V_30 -> V_40 ] ;
#ifdef F_29
if ( F_30 ( V_30 ) ) {
struct V_14 * V_14 = F_15 ( F_16 ( V_8 ) -> V_16 ) ;
V_33 = F_31 ( V_14 , & V_28 -> V_19 , V_30 ) ;
if ( F_18 ( V_33 ) )
return V_33 ;
}
#endif
F_32 ( V_8 , V_28 , sizeof( struct V_27 ) + V_31 ) ;
return 0 ;
}
static int F_37 ( struct V_7 * V_8 )
{
struct V_42 * V_43 = F_16 ( V_8 ) ;
struct V_5 * V_44 ;
int V_26 , V_33 = 0 ;
V_44 = F_2 ( V_43 -> V_45 ) ;
if ( F_38 ( ! V_8 -> V_46 ) ) {
F_39 ( V_8 ) ;
V_8 -> V_46 = 1 ;
}
switch ( V_44 -> V_47 ) {
case V_48 :
if ( V_8 -> V_34 != F_23 ( V_35 ) )
return - V_49 ;
V_33 = F_33 ( V_8 , V_44 -> V_50 ) ;
if ( V_33 )
return V_33 ;
F_39 ( V_8 ) ;
break;
case V_51 :
if ( V_8 -> V_34 == F_23 ( V_35 ) )
V_26 = V_52 ;
else if ( V_8 -> V_34 == F_23 ( V_53 ) )
V_26 = V_54 ;
else
return - V_49 ;
V_33 = F_14 ( V_8 , V_44 -> V_50 , V_26 ) ;
if ( V_33 )
return V_33 ;
V_8 -> V_34 = F_23 ( V_35 ) ;
break;
case V_55 :
if ( ! F_40 ( V_8 ) )
return - V_49 ;
if ( F_41 ( V_8 , V_8 -> V_56 , 0 , V_57 ) < 0 )
return - V_58 ;
F_22 ( V_8 ) ;
F_20 ( V_8 , V_8 -> V_56 ) ;
V_33 = F_14 ( V_8 , V_44 -> V_50 , V_59 ) ;
if ( V_33 )
return V_33 ;
V_8 -> V_34 = F_23 ( V_35 ) ;
break;
}
F_19 ( V_8 ) -> V_60 = F_23 ( V_8 -> V_12 - sizeof( struct V_27 ) ) ;
F_42 ( V_8 , sizeof( struct V_27 ) ) ;
F_43 ( V_8 , V_8 -> V_34 ) ;
return 0 ;
}
static int F_44 ( struct V_7 * V_8 )
{
struct V_42 * V_61 = F_16 ( V_8 ) ;
struct V_42 * V_43 = NULL ;
struct V_1 * V_62 ;
int V_33 ;
V_33 = F_37 ( V_8 ) ;
if ( F_18 ( V_33 ) ) {
F_45 ( V_8 ) ;
return V_33 ;
}
V_62 = F_1 ( V_61 -> V_45 ) ;
F_46 () ;
V_43 = F_47 ( & V_62 -> V_63 ) ;
F_48 () ;
F_49 ( V_8 ) ;
if ( ! V_43 ) {
F_50 ( V_8 ) ;
V_43 = F_16 ( V_8 ) ;
if ( ! V_43 -> error ) {
F_46 () ;
F_51 ( & V_62 -> V_63 , V_43 ,
& F_19 ( V_8 ) -> V_19 ) ;
F_48 () ;
}
} else {
F_52 ( V_8 , V_43 ) ;
}
V_33 = F_17 ( V_8 , F_53 ( V_43 -> V_16 ) ) ;
if ( F_18 ( V_33 ) )
return V_33 ;
return F_54 ( V_8 ) ;
}
static int F_55 ( struct V_14 * V_14 , struct V_64 * V_65 , struct V_7 * V_8 )
{
struct V_42 * V_61 = F_16 ( V_8 ) ;
struct V_42 * V_43 = NULL ;
struct V_1 * V_62 ;
int V_33 = - V_49 ;
V_33 = F_37 ( V_8 ) ;
if ( F_18 ( V_33 ) )
goto V_66;
V_62 = F_1 ( V_61 -> V_45 ) ;
F_46 () ;
V_43 = F_47 ( & V_62 -> V_63 ) ;
F_48 () ;
if ( F_18 ( ! V_43 ) ) {
struct V_27 * V_28 = F_19 ( V_8 ) ;
struct V_67 V_68 ;
V_68 . V_18 = V_28 -> V_18 ;
V_68 . V_19 = V_28 -> V_19 ;
V_68 . V_69 = F_26 ( V_28 ) ;
V_68 . V_70 = V_8 -> V_71 ;
V_68 . V_72 = V_28 -> V_37 ;
V_43 = F_56 ( V_14 , NULL , & V_68 ) ;
if ( V_43 -> error ) {
V_33 = V_43 -> error ;
F_57 ( V_43 ) ;
goto V_66;
}
F_46 () ;
F_51 ( & V_62 -> V_63 , V_43 , & V_68 . V_19 ) ;
F_48 () ;
}
F_49 ( V_8 ) ;
F_52 ( V_8 , V_43 ) ;
V_33 = F_17 ( V_8 , F_53 ( V_43 -> V_16 ) ) ;
if ( F_18 ( V_33 ) )
goto V_66;
return F_58 ( V_14 , V_65 , V_8 ) ;
V_66:
F_45 ( V_8 ) ;
return V_33 ;
}
static int F_59 ( struct V_10 * V_11 ,
unsigned int V_73 , const void * V_74 ,
struct V_2 * * V_75 ,
struct V_76 * V_77 )
{
struct V_10 * V_78 [ V_79 + 1 ] ;
struct V_5 * V_6 ;
struct V_2 * V_80 ;
int V_81 , V_82 ;
struct V_1 * V_62 ;
int V_33 ;
if ( V_73 != V_83 && V_73 != V_84 )
return - V_49 ;
V_33 = F_60 ( V_78 , V_79 , V_11 ,
V_85 , V_77 ) ;
if ( V_33 < 0 )
return V_33 ;
if ( ! V_78 [ V_86 ] )
return - V_49 ;
V_6 = F_6 ( V_78 [ V_86 ] ) ;
V_81 = F_61 ( V_78 [ V_86 ] ) ;
V_82 = sizeof( * V_6 ) + sizeof( struct V_24 ) +
sizeof( struct V_17 ) ;
if ( V_81 < V_82 )
return - V_49 ;
switch ( V_6 -> V_47 ) {
case V_48 :
if ( V_73 != V_84 )
return - V_49 ;
break;
case V_51 :
break;
case V_55 :
break;
default:
return - V_49 ;
}
if ( ! F_62 ( V_6 -> V_50 , V_81 - sizeof( * V_6 ) ) )
return - V_49 ;
V_80 = F_63 ( V_81 + sizeof( * V_62 ) ) ;
if ( ! V_80 )
return - V_58 ;
V_62 = F_1 ( V_80 ) ;
V_33 = F_64 ( & V_62 -> V_63 , V_87 ) ;
if ( V_33 ) {
F_65 ( V_80 ) ;
return V_33 ;
}
memcpy ( & V_62 -> V_6 , V_6 , V_81 ) ;
V_80 -> type = V_88 ;
V_80 -> V_89 |= V_90 ;
if ( V_6 -> V_47 != V_55 )
V_80 -> V_89 |= V_91 ;
V_80 -> V_92 = F_66 ( V_6 ) ;
* V_75 = V_80 ;
return 0 ;
}
static void F_67 ( struct V_2 * V_3 )
{
F_68 ( & F_1 ( V_3 ) -> V_63 ) ;
}
static int F_69 ( struct V_7 * V_8 ,
struct V_2 * V_45 )
{
struct V_5 * V_6 = F_2 ( V_45 ) ;
if ( F_3 ( V_8 , V_86 , V_6 ) )
return - V_13 ;
return 0 ;
}
static int F_70 ( struct V_2 * V_45 )
{
struct V_5 * V_6 = F_2 ( V_45 ) ;
return F_71 ( F_4 ( V_6 ) ) ;
}
static int F_72 ( struct V_2 * V_93 , struct V_2 * V_94 )
{
struct V_5 * V_95 = F_2 ( V_93 ) ;
struct V_5 * V_96 = F_2 ( V_94 ) ;
int V_12 = F_4 ( V_95 ) ;
if ( V_12 != F_4 ( V_96 ) )
return 1 ;
return memcmp ( V_95 , V_96 , V_12 ) ;
}
int T_1 F_73 ( void )
{
return F_74 ( & V_97 , V_88 ) ;
}
void F_75 ( void )
{
F_76 ( & V_97 , V_88 ) ;
}
