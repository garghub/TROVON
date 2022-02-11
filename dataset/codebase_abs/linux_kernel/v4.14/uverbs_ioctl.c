static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 ,
T_1 V_7 ,
const struct V_8 * V_9 ,
struct V_10 * V_11 ,
struct V_5 T_2 * V_12 )
{
const struct V_13 * V_14 ;
struct V_15 * V_16 ;
const struct V_17 * V_18 ;
struct V_19 * V_20 ;
struct V_15 * V_21 = V_11 -> V_22 ;
if ( V_6 -> V_23 )
return - V_24 ;
if ( V_7 >= V_9 -> V_25 ) {
if ( V_6 -> V_26 & V_27 )
return - V_24 ;
else
return 0 ;
}
V_14 = & V_9 -> V_22 [ V_7 ] ;
V_16 = & V_21 [ V_7 ] ;
V_16 -> V_6 = V_12 ;
switch ( V_14 -> type ) {
case V_28 :
case V_29 :
if ( V_6 -> V_30 < V_14 -> V_30 ||
( ! ( V_14 -> V_26 & V_31 ) &&
V_6 -> V_30 > V_14 -> V_30 ) )
return - V_24 ;
V_16 -> V_32 . V_33 = V_6 -> V_33 ;
V_16 -> V_32 . V_30 = V_6 -> V_30 ;
V_16 -> V_32 . V_26 = V_6 -> V_26 ;
break;
case V_34 :
if ( V_6 -> V_33 >> 32 )
return - V_24 ;
case V_35 :
if ( V_6 -> V_30 != 0 || ! V_4 || V_6 -> V_33 > V_36 )
return - V_24 ;
V_20 = & V_16 -> V_37 ;
V_18 = F_2 ( V_2 , V_14 -> V_38 . V_39 ) ;
if ( ! V_18 )
return - V_24 ;
V_20 -> type = V_18 -> V_40 ;
V_20 -> V_41 = ( int ) V_6 -> V_33 ;
V_20 -> V_42 = F_3 (
V_20 -> type ,
V_4 ,
V_14 -> V_38 . V_43 ,
V_20 -> V_41 ) ;
if ( F_4 ( V_20 -> V_42 ) )
return F_5 ( V_20 -> V_42 ) ;
if ( V_14 -> V_38 . V_43 == V_44 ) {
T_3 V_41 = V_20 -> V_42 -> V_41 ;
if ( F_6 ( V_41 , & V_16 -> V_6 -> V_33 ) ) {
F_7 ( V_20 -> V_42 ,
V_44 ,
false ) ;
return - V_45 ;
}
}
break;
default:
return - V_46 ;
}
F_8 ( V_7 , V_11 -> V_47 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_48 ,
T_4 V_49 ,
const struct V_50 * V_51 ,
struct V_52 * V_53 ,
struct V_5 T_2 * V_12 )
{
T_4 V_54 ;
int V_55 = 0 ;
int V_56 = 0 ;
for ( V_54 = 0 ; V_54 < V_49 ; V_54 ++ ) {
const struct V_5 * V_6 = & V_48 [ V_54 ] ;
T_1 V_7 = V_6 -> V_7 ;
struct V_8 * V_9 ;
V_55 = F_10 ( & V_7 , V_51 -> V_57 ) ;
if ( V_55 < 0 ) {
if ( V_6 -> V_26 & V_27 ) {
F_11 ( V_53 ,
V_51 -> V_58 ,
V_56 ,
false ) ;
return V_55 ;
}
continue;
}
if ( V_55 >= V_56 )
V_56 = V_55 + 1 ;
V_9 = V_51 -> V_58 [ V_55 ] ;
V_55 = F_1 ( V_2 , V_4 , V_6 , V_7 ,
V_9 , & V_53 -> V_59 [ V_55 ] ,
V_12 ++ ) ;
if ( V_55 ) {
F_11 ( V_53 ,
V_51 -> V_58 ,
V_56 ,
false ) ;
return V_55 ;
}
}
return V_56 ;
}
static int F_12 ( const struct V_50 * V_60 ,
struct V_52 * V_53 )
{
unsigned int V_54 ;
for ( V_54 = 0 ; V_54 < V_53 -> V_57 ; V_54 ++ ) {
struct V_8 * V_9 =
V_60 -> V_58 [ V_54 ] ;
if ( ! F_13 ( V_9 -> V_61 ,
V_53 -> V_59 [ V_54 ] . V_47 ,
V_9 -> V_25 ) )
return - V_24 ;
}
return 0 ;
}
static int F_14 ( struct V_5 T_2 * V_12 ,
const struct V_5 * V_48 ,
T_4 V_49 ,
struct V_1 * V_2 ,
struct V_62 * V_63 ,
const struct V_50 * V_60 ,
struct V_52 * V_53 )
{
int V_55 ;
int V_64 ;
int V_56 ;
V_56 = F_9 ( V_2 , V_63 -> V_4 , V_48 ,
V_49 , V_60 ,
V_53 , V_12 ) ;
if ( V_56 <= 0 )
return - V_24 ;
V_53 -> V_57 = V_56 ;
V_55 = F_12 ( V_60 , V_53 ) ;
if ( V_55 )
goto V_65;
V_55 = V_60 -> V_66 ( V_2 , V_63 , V_53 ) ;
V_65:
V_64 = F_11 ( V_53 ,
V_60 -> V_58 ,
V_53 -> V_57 ,
! V_55 ) ;
return V_55 ? V_55 : V_64 ;
}
static long F_15 ( struct V_1 * V_67 ,
struct V_62 * V_68 ,
struct V_69 * V_70 ,
void T_2 * V_71 )
{
const struct V_17 * V_72 ;
const struct V_50 * V_60 ;
long V_73 = 0 ;
unsigned int V_54 ;
struct {
struct V_5 * V_48 ;
struct V_52 * V_52 ;
} * V_74 = NULL ;
struct V_15 * V_75 ;
unsigned long * V_76 ;
T_4 V_77 ;
#ifdef F_16
T_5 V_33 [ F_16 / sizeof( T_5 ) ] ;
#endif
if ( V_70 -> V_23 )
return - V_24 ;
V_72 = F_2 ( V_67 , V_70 -> V_78 ) ;
if ( ! V_72 )
return - V_46 ;
V_60 = F_17 ( V_72 , V_70 -> V_79 ) ;
if ( ! V_60 )
return - V_46 ;
if ( ( V_60 -> V_26 & V_80 ) ^ ! V_68 -> V_4 )
return - V_24 ;
V_77 = sizeof( * V_74 ) +
sizeof( struct V_52 ) +
sizeof( struct V_10 ) * V_60 -> V_57 +
sizeof( * V_74 -> V_48 ) * V_70 -> V_25 +
sizeof( * V_74 -> V_52 -> V_59 [ 0 ] . V_22 ) *
V_60 -> V_81 +
sizeof( * V_74 -> V_52 -> V_59 [ 0 ] . V_47 ) *
( V_60 -> V_81 / V_82 +
V_60 -> V_57 ) ;
#ifdef F_16
if ( V_77 <= F_16 )
V_74 = ( void * ) V_33 ;
if ( ! V_74 )
#endif
V_74 = F_18 ( V_77 , V_83 ) ;
if ( ! V_74 )
return - V_84 ;
V_74 -> V_52 = ( void * ) V_74 + sizeof( * V_74 ) ;
V_74 -> V_48 = ( void * ) ( V_74 -> V_52 + 1 ) +
( sizeof( V_74 -> V_52 -> V_59 [ 0 ] ) *
V_60 -> V_57 ) ;
V_75 = ( void * ) ( V_74 -> V_48 + V_70 -> V_25 ) ;
V_76 = ( void * ) ( V_75 + V_60 -> V_81 ) ;
for ( V_54 = 0 ; V_54 < V_60 -> V_57 ; V_54 ++ ) {
unsigned int V_85 = V_60 -> V_58 [ V_54 ] -> V_25 ;
V_74 -> V_52 -> V_59 [ V_54 ] . V_22 = V_75 ;
V_75 += V_85 ;
V_74 -> V_52 -> V_59 [ V_54 ] . V_25 = V_85 ;
V_74 -> V_52 -> V_59 [ V_54 ] . V_47 = V_76 ;
F_19 ( V_76 , V_85 ) ;
V_76 += F_20 ( V_85 ) ;
}
V_73 = F_21 ( V_74 -> V_48 , V_71 ,
sizeof( * V_74 -> V_48 ) * V_70 -> V_25 ) ;
if ( V_73 ) {
V_73 = - V_45 ;
goto V_86;
}
V_73 = F_14 ( V_71 , V_74 -> V_48 , V_70 -> V_25 , V_67 ,
V_68 , V_60 , V_74 -> V_52 ) ;
V_86:
#ifdef F_16
if ( V_77 > F_16 )
#endif
F_22 ( V_74 ) ;
return V_73 ;
}
long F_23 ( struct V_68 * V_87 , unsigned int V_88 , unsigned long V_89 )
{
struct V_62 * V_68 = V_87 -> V_90 ;
struct V_69 T_2 * V_91 =
(struct V_69 T_2 * ) V_89 ;
struct V_69 V_70 ;
struct V_1 * V_67 ;
int V_92 ;
long V_73 ;
V_92 = F_24 ( & V_68 -> V_93 -> V_94 ) ;
V_67 = F_25 ( V_68 -> V_93 -> V_67 ,
& V_68 -> V_93 -> V_94 ) ;
if ( ! V_67 ) {
V_73 = - V_95 ;
goto V_86;
}
if ( V_88 == V_96 ) {
V_73 = F_21 ( & V_70 , V_91 , sizeof( V_70 ) ) ;
if ( V_73 || V_70 . V_97 > V_98 ||
V_70 . V_97 != sizeof( V_70 ) + V_70 . V_25 * sizeof( struct V_5 ) ) {
V_73 = - V_24 ;
goto V_86;
}
if ( V_70 . V_23 ) {
V_73 = - V_46 ;
goto V_86;
}
V_73 = F_15 ( V_67 , V_68 , & V_70 ,
( T_2 void * ) V_89 + sizeof( V_70 ) ) ;
} else {
V_73 = - V_99 ;
}
V_86:
F_26 ( & V_68 -> V_93 -> V_94 , V_92 ) ;
return V_73 ;
}
