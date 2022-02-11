static bool F_1 ( const struct V_1 * V_2 )
{
return V_2 -> V_3 . V_4 == V_5 ||
V_2 -> V_3 . V_4 == V_6 ;
}
static bool F_2 ( const struct V_1 * V_2 )
{
return V_2 -> V_3 . V_4 == V_7 ||
V_2 -> V_3 . V_4 == V_6 ;
}
static bool F_3 ( const struct V_1 * V_2 )
{
return ! ( V_2 -> V_3 . V_8 & V_9 ) ;
}
static inline void F_4 ( struct V_10 * V_11 , T_1 V_12 ,
void T_2 * V_13 )
{
* ( void T_2 * * ) ( V_11 -> V_14 + V_12 ) = V_13 ;
}
static inline void T_2 * F_5 ( struct V_10 * V_11 , T_1 V_12 )
{
return * ( void T_2 * * ) ( V_11 -> V_14 + V_12 ) ;
}
static void * F_6 ( const struct V_15 * V_3 , struct V_10 * V_11 )
{
return * ( void * * ) ( V_11 -> V_14 + F_7 ( V_3 -> V_12 , 8 ) ) ;
}
static struct V_10 * F_8 ( struct V_1 * V_2 , int V_16 )
{
return (struct V_10 * ) ( V_2 -> V_17 + V_16 * V_2 -> V_18 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
int V_16 ;
if ( ! F_2 ( V_2 ) )
goto V_19;
for ( V_16 = 0 ; V_16 < V_2 -> V_3 . V_20 ; V_16 ++ ) {
void T_2 * V_13 ;
V_13 = F_5 ( F_8 ( V_2 , V_16 ) ,
V_2 -> V_3 . V_12 ) ;
F_10 ( V_13 ) ;
}
V_19:
F_11 ( V_2 -> V_17 ) ;
}
static struct V_10 * F_12 ( struct V_1 * V_2 , void * V_14 ,
T_1 V_21 )
{
struct V_22 * V_23 = F_13 ( & V_2 -> V_24 , V_21 ) ;
struct V_10 * V_11 ;
if ( V_23 ) {
V_11 = F_14 ( V_23 , struct V_10 , V_25 ) ;
memcpy ( V_11 -> V_14 , V_14 , V_2 -> V_3 . V_12 ) ;
return V_11 ;
}
return NULL ;
}
static int F_15 ( struct V_1 * V_2 )
{
T_1 V_26 = V_2 -> V_3 . V_20 ;
int V_27 = - V_28 , V_16 ;
if ( ! F_2 ( V_2 ) && ! F_1 ( V_2 ) )
V_26 += F_16 () ;
V_2 -> V_17 = F_17 ( V_2 -> V_18 * V_26 ) ;
if ( ! V_2 -> V_17 )
return - V_28 ;
if ( ! F_2 ( V_2 ) )
goto V_29;
for ( V_16 = 0 ; V_16 < V_26 ; V_16 ++ ) {
T_1 V_30 = F_18 ( V_2 -> V_3 . V_31 , 8 ) ;
void T_2 * V_13 ;
V_13 = F_19 ( V_30 , 8 , V_32 | V_33 ) ;
if ( ! V_13 )
goto V_19;
F_4 ( F_8 ( V_2 , V_16 ) , V_2 -> V_3 . V_12 ,
V_13 ) ;
}
V_29:
if ( F_1 ( V_2 ) )
V_27 = F_20 ( & V_2 -> V_24 ,
V_2 -> V_3 . V_8 & V_34 ,
F_21 ( struct V_10 , V_21 ) -
F_21 ( struct V_10 , V_25 ) ,
V_35 ,
V_2 ) ;
else
V_27 = F_22 ( & V_2 -> V_36 ) ;
if ( V_27 )
goto V_19;
if ( F_1 ( V_2 ) )
F_23 ( & V_2 -> V_24 , V_2 -> V_17 ,
F_21 ( struct V_10 , V_25 ) ,
V_2 -> V_18 , V_26 ) ;
else
F_24 ( & V_2 -> V_36 ,
V_2 -> V_17 + F_21 ( struct V_10 , V_37 ) ,
V_2 -> V_18 , V_26 ) ;
return 0 ;
V_19:
F_9 ( V_2 ) ;
return V_27 ;
}
static void F_25 ( struct V_1 * V_2 )
{
F_9 ( V_2 ) ;
if ( F_1 ( V_2 ) )
F_26 ( & V_2 -> V_24 ) ;
else
F_27 ( & V_2 -> V_36 ) ;
}
static int F_28 ( struct V_1 * V_2 )
{
struct V_10 * T_2 * V_13 , * V_38 ;
struct V_39 * V_11 ;
int V_40 ;
V_13 = F_19 ( sizeof( struct V_10 * ) , 8 ,
V_32 | V_33 ) ;
if ( ! V_13 )
return - V_28 ;
F_29 (cpu) {
V_11 = F_30 ( & V_2 -> V_36 ) ;
V_38 = F_14 ( V_11 , struct V_10 , V_37 ) ;
* F_31 ( V_13 , V_40 ) = V_38 ;
}
V_2 -> V_41 = V_13 ;
return 0 ;
}
static struct V_15 * F_32 ( union V_42 * V_43 )
{
bool V_44 = ( V_43 -> V_4 == V_7 ||
V_43 -> V_4 == V_6 ) ;
bool V_24 = ( V_43 -> V_4 == V_5 ||
V_43 -> V_4 == V_6 ) ;
bool V_45 = ( V_43 -> V_8 & V_34 ) ;
bool V_46 = ! ( V_43 -> V_8 & V_9 ) ;
struct V_1 * V_2 ;
int V_27 , V_16 ;
T_3 V_47 ;
F_33 ( F_21 ( struct V_10 , V_2 ) !=
F_21 ( struct V_10 , V_48 . V_49 ) ) ;
F_33 ( F_21 ( struct V_10 , V_37 . V_50 ) !=
F_21 ( struct V_10 , V_48 . V_49 ) ) ;
if ( V_24 && ! F_34 ( V_51 ) )
return F_35 ( - V_52 ) ;
if ( V_43 -> V_8 & ~ ( V_9 | V_34 ) )
return F_35 ( - V_53 ) ;
if ( ! V_24 && V_45 )
return F_35 ( - V_53 ) ;
if ( V_24 && ! V_46 )
return F_35 ( - V_54 ) ;
V_2 = F_36 ( sizeof( * V_2 ) , V_32 ) ;
if ( ! V_2 )
return F_35 ( - V_28 ) ;
V_2 -> V_3 . V_4 = V_43 -> V_4 ;
V_2 -> V_3 . V_12 = V_43 -> V_12 ;
V_2 -> V_3 . V_31 = V_43 -> V_31 ;
V_2 -> V_3 . V_20 = V_43 -> V_20 ;
V_2 -> V_3 . V_8 = V_43 -> V_8 ;
V_27 = - V_53 ;
if ( V_2 -> V_3 . V_20 == 0 || V_2 -> V_3 . V_12 == 0 ||
V_2 -> V_3 . V_31 == 0 )
goto V_55;
if ( V_45 ) {
V_2 -> V_3 . V_20 = F_7 ( V_43 -> V_20 ,
F_16 () ) ;
if ( V_2 -> V_3 . V_20 < V_43 -> V_20 )
V_2 -> V_3 . V_20 = F_37 ( V_43 -> V_20 ,
F_16 () ) ;
}
V_2 -> V_56 = F_38 ( V_2 -> V_3 . V_20 ) ;
V_27 = - V_57 ;
if ( V_2 -> V_3 . V_12 > V_58 )
goto V_55;
if ( V_2 -> V_3 . V_31 >= V_59 -
V_58 - sizeof( struct V_10 ) )
goto V_55;
if ( V_44 && F_18 ( V_2 -> V_3 . V_31 , 8 ) > V_60 )
goto V_55;
V_2 -> V_18 = sizeof( struct V_10 ) +
F_18 ( V_2 -> V_3 . V_12 , 8 ) ;
if ( V_44 )
V_2 -> V_18 += sizeof( void * ) ;
else
V_2 -> V_18 += F_18 ( V_2 -> V_3 . V_31 , 8 ) ;
if ( V_2 -> V_56 == 0 ||
V_2 -> V_56 > V_61 / sizeof( struct V_62 ) )
goto V_55;
V_47 = ( T_3 ) V_2 -> V_56 * sizeof( struct V_62 ) +
( T_3 ) V_2 -> V_18 * V_2 -> V_3 . V_20 ;
if ( V_44 )
V_47 += ( T_3 ) F_18 ( V_2 -> V_3 . V_31 , 8 ) *
F_16 () * V_2 -> V_3 . V_20 ;
else
V_47 += ( T_3 ) V_2 -> V_18 * F_16 () ;
if ( V_47 >= V_61 - V_63 )
goto V_55;
V_2 -> V_3 . V_64 = F_18 ( V_47 , V_63 ) >> V_65 ;
V_27 = F_39 ( V_2 -> V_3 . V_64 ) ;
if ( V_27 )
goto V_55;
V_27 = - V_28 ;
V_2 -> V_66 = F_17 ( V_2 -> V_56 *
sizeof( struct V_62 ) ) ;
if ( ! V_2 -> V_66 )
goto V_55;
for ( V_16 = 0 ; V_16 < V_2 -> V_56 ; V_16 ++ ) {
F_40 ( & V_2 -> V_66 [ V_16 ] . V_67 , V_16 ) ;
F_41 ( & V_2 -> V_66 [ V_16 ] . V_68 ) ;
}
if ( V_46 ) {
V_27 = F_15 ( V_2 ) ;
if ( V_27 )
goto V_69;
if ( ! V_44 && ! V_24 ) {
V_27 = F_28 ( V_2 ) ;
if ( V_27 )
goto V_70;
}
}
return & V_2 -> V_3 ;
V_70:
F_25 ( V_2 ) ;
V_69:
F_11 ( V_2 -> V_66 ) ;
V_55:
F_42 ( V_2 ) ;
return F_35 ( V_27 ) ;
}
static inline T_1 F_43 ( const void * V_14 , T_1 V_71 )
{
return F_44 ( V_14 , V_71 , 0 ) ;
}
static inline struct V_62 * F_45 ( struct V_1 * V_2 , T_1 V_21 )
{
return & V_2 -> V_66 [ V_21 & ( V_2 -> V_56 - 1 ) ] ;
}
static inline struct V_72 * F_46 ( struct V_1 * V_2 , T_1 V_21 )
{
return & F_45 ( V_2 , V_21 ) -> V_67 ;
}
static struct V_10 * F_47 ( struct V_72 * V_67 , T_1 V_21 ,
void * V_14 , T_1 V_12 )
{
struct V_73 * V_74 ;
struct V_10 * V_11 ;
F_48 (l, n, head, hash_node)
if ( V_11 -> V_21 == V_21 && ! memcmp ( & V_11 -> V_14 , V_14 , V_12 ) )
return V_11 ;
return NULL ;
}
static struct V_10 * F_49 ( struct V_72 * V_67 ,
T_1 V_21 , void * V_14 ,
T_1 V_12 , T_1 V_56 )
{
struct V_73 * V_74 ;
struct V_10 * V_11 ;
V_75:
F_48 (l, n, head, hash_node)
if ( V_11 -> V_21 == V_21 && ! memcmp ( & V_11 -> V_14 , V_14 , V_12 ) )
return V_11 ;
if ( F_50 ( F_51 ( V_74 ) != ( V_21 & ( V_56 - 1 ) ) ) )
goto V_75;
return NULL ;
}
static void * F_52 ( struct V_15 * V_3 , void * V_14 )
{
struct V_1 * V_2 = F_14 ( V_3 , struct V_1 , V_3 ) ;
struct V_72 * V_67 ;
struct V_10 * V_11 ;
T_1 V_21 , V_12 ;
F_53 ( ! F_54 () ) ;
V_12 = V_3 -> V_12 ;
V_21 = F_43 ( V_14 , V_12 ) ;
V_67 = F_46 ( V_2 , V_21 ) ;
V_11 = F_49 ( V_67 , V_21 , V_14 , V_12 , V_2 -> V_56 ) ;
return V_11 ;
}
static void * F_55 ( struct V_15 * V_3 , void * V_14 )
{
struct V_10 * V_11 = F_52 ( V_3 , V_14 ) ;
if ( V_11 )
return V_11 -> V_14 + F_18 ( V_3 -> V_12 , 8 ) ;
return NULL ;
}
static T_1 F_56 ( struct V_15 * V_3 , struct V_76 * V_77 )
{
struct V_76 * V_78 = V_77 ;
const int V_79 = V_80 ;
* V_78 ++ = F_57 ( ( T_3 ( * ) ( T_3 , T_3 , T_3 , T_3 , T_3 ) ) F_52 ) ;
* V_78 ++ = F_58 ( V_81 , V_79 , 0 , 1 ) ;
* V_78 ++ = F_59 ( V_82 , V_79 ,
F_21 ( struct V_10 , V_14 ) +
F_18 ( V_3 -> V_12 , 8 ) ) ;
return V_78 - V_77 ;
}
static void * F_60 ( struct V_15 * V_3 , void * V_14 )
{
struct V_10 * V_11 = F_52 ( V_3 , V_14 ) ;
if ( V_11 ) {
F_61 ( & V_11 -> V_25 ) ;
return V_11 -> V_14 + F_18 ( V_3 -> V_12 , 8 ) ;
}
return NULL ;
}
static bool V_35 ( void * V_83 , struct V_22 * V_23 )
{
struct V_1 * V_2 = (struct V_1 * ) V_83 ;
struct V_10 * V_11 = NULL , * V_84 ;
struct V_72 * V_67 ;
struct V_73 * V_74 ;
unsigned long V_85 ;
struct V_62 * V_86 ;
V_84 = F_14 ( V_23 , struct V_10 , V_25 ) ;
V_86 = F_45 ( V_2 , V_84 -> V_21 ) ;
V_67 = & V_86 -> V_67 ;
F_62 ( & V_86 -> V_68 , V_85 ) ;
F_48 (l, n, head, hash_node)
if ( V_11 == V_84 ) {
F_63 ( & V_11 -> V_48 ) ;
break;
}
F_64 ( & V_86 -> V_68 , V_85 ) ;
return V_11 == V_84 ;
}
static int F_65 ( struct V_15 * V_3 , void * V_14 , void * V_87 )
{
struct V_1 * V_2 = F_14 ( V_3 , struct V_1 , V_3 ) ;
struct V_72 * V_67 ;
struct V_10 * V_11 , * V_88 ;
T_1 V_21 , V_12 ;
int V_16 = 0 ;
F_53 ( ! F_54 () ) ;
V_12 = V_3 -> V_12 ;
if ( ! V_14 )
goto V_89;
V_21 = F_43 ( V_14 , V_12 ) ;
V_67 = F_46 ( V_2 , V_21 ) ;
V_11 = F_49 ( V_67 , V_21 , V_14 , V_12 , V_2 -> V_56 ) ;
if ( ! V_11 )
goto V_89;
V_88 = F_66 ( F_67 ( F_68 ( & V_11 -> V_48 ) ) ,
struct V_10 , V_48 ) ;
if ( V_88 ) {
memcpy ( V_87 , V_88 -> V_14 , V_12 ) ;
return 0 ;
}
V_16 = V_21 & ( V_2 -> V_56 - 1 ) ;
V_16 ++ ;
V_89:
for (; V_16 < V_2 -> V_56 ; V_16 ++ ) {
V_67 = F_46 ( V_2 , V_16 ) ;
V_88 = F_66 ( F_67 ( F_69 ( V_67 ) ) ,
struct V_10 , V_48 ) ;
if ( V_88 ) {
memcpy ( V_87 , V_88 -> V_14 , V_12 ) ;
return 0 ;
}
}
return - V_90 ;
}
static void F_70 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
if ( V_2 -> V_3 . V_4 == V_7 )
F_10 ( F_5 ( V_11 , V_2 -> V_3 . V_12 ) ) ;
F_42 ( V_11 ) ;
}
static void F_71 ( struct V_91 * V_67 )
{
struct V_10 * V_11 = F_14 ( V_67 , struct V_10 , V_92 ) ;
struct V_1 * V_2 = V_11 -> V_2 ;
F_72 () ;
F_73 ( V_93 ) ;
F_70 ( V_2 , V_11 ) ;
F_74 ( V_93 ) ;
F_75 () ;
}
static void F_76 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
struct V_15 * V_3 = & V_2 -> V_3 ;
if ( V_3 -> V_94 -> V_95 ) {
void * V_96 = F_6 ( V_3 , V_11 ) ;
V_3 -> V_94 -> V_95 ( V_96 ) ;
}
if ( F_3 ( V_2 ) ) {
F_77 ( & V_2 -> V_36 , & V_11 -> V_37 ) ;
} else {
F_78 ( & V_2 -> V_97 ) ;
V_11 -> V_2 = V_2 ;
F_79 ( & V_11 -> V_92 , F_71 ) ;
}
}
static void F_80 ( struct V_1 * V_2 , void T_2 * V_13 ,
void * V_98 , bool V_99 )
{
if ( ! V_99 ) {
memcpy ( F_81 ( V_13 ) , V_98 , V_2 -> V_3 . V_31 ) ;
} else {
T_1 V_30 = F_18 ( V_2 -> V_3 . V_31 , 8 ) ;
int V_100 = 0 , V_40 ;
F_29 (cpu) {
F_82 ( F_31 ( V_13 , V_40 ) ,
V_98 + V_100 , V_30 ) ;
V_100 += V_30 ;
}
}
}
static bool F_83 ( const struct V_1 * V_2 )
{
return V_2 -> V_3 . V_4 == V_101 &&
V_102 == 64 ;
}
static T_1 F_84 ( const struct V_1 * V_2 , bool V_44 )
{
T_1 V_30 = V_2 -> V_3 . V_31 ;
if ( V_44 || F_83 ( V_2 ) )
V_30 = F_18 ( V_30 , 8 ) ;
return V_30 ;
}
static struct V_10 * F_85 ( struct V_1 * V_2 , void * V_14 ,
void * V_98 , T_1 V_12 , T_1 V_21 ,
bool V_44 , bool V_99 ,
struct V_10 * V_103 )
{
T_1 V_30 = F_84 ( V_2 , V_44 ) ;
bool V_46 = F_3 ( V_2 ) ;
struct V_10 * V_38 , * * V_104 ;
void T_2 * V_13 ;
if ( V_46 ) {
if ( V_103 ) {
V_104 = F_81 ( V_2 -> V_41 ) ;
V_38 = * V_104 ;
* V_104 = V_103 ;
} else {
struct V_39 * V_11 ;
V_11 = F_30 ( & V_2 -> V_36 ) ;
if ( ! V_11 )
return F_35 ( - V_57 ) ;
V_38 = F_14 ( V_11 , struct V_10 , V_37 ) ;
}
} else {
if ( F_86 ( & V_2 -> V_97 ) > V_2 -> V_3 . V_20 )
if ( ! V_103 ) {
F_78 ( & V_2 -> V_97 ) ;
return F_35 ( - V_57 ) ;
}
V_38 = F_87 ( V_2 -> V_18 , V_105 | V_33 ) ;
if ( ! V_38 )
return F_35 ( - V_28 ) ;
}
memcpy ( V_38 -> V_14 , V_14 , V_12 ) ;
if ( V_44 ) {
if ( V_46 ) {
V_13 = F_5 ( V_38 , V_12 ) ;
} else {
V_13 = F_19 ( V_30 , 8 ,
V_105 | V_33 ) ;
if ( ! V_13 ) {
F_42 ( V_38 ) ;
return F_35 ( - V_28 ) ;
}
}
F_80 ( V_2 , V_13 , V_98 , V_99 ) ;
if ( ! V_46 )
F_4 ( V_38 , V_12 , V_13 ) ;
} else {
memcpy ( V_38 -> V_14 + F_18 ( V_12 , 8 ) , V_98 , V_30 ) ;
}
V_38 -> V_21 = V_21 ;
return V_38 ;
}
static int F_88 ( struct V_1 * V_2 , struct V_10 * V_106 ,
T_3 V_8 )
{
if ( V_106 && V_8 == V_107 )
return - V_108 ;
if ( ! V_106 && V_8 == V_109 )
return - V_90 ;
return 0 ;
}
static int F_89 ( struct V_15 * V_3 , void * V_14 , void * V_98 ,
T_3 V_8 )
{
struct V_1 * V_2 = F_14 ( V_3 , struct V_1 , V_3 ) ;
struct V_10 * V_38 = NULL , * V_106 ;
struct V_72 * V_67 ;
unsigned long V_85 ;
struct V_62 * V_86 ;
T_1 V_12 , V_21 ;
int V_79 ;
if ( F_50 ( V_8 > V_109 ) )
return - V_53 ;
F_53 ( ! F_54 () ) ;
V_12 = V_3 -> V_12 ;
V_21 = F_43 ( V_14 , V_12 ) ;
V_86 = F_45 ( V_2 , V_21 ) ;
V_67 = & V_86 -> V_67 ;
F_62 ( & V_86 -> V_68 , V_85 ) ;
V_106 = F_47 ( V_67 , V_21 , V_14 , V_12 ) ;
V_79 = F_88 ( V_2 , V_106 , V_8 ) ;
if ( V_79 )
goto V_27;
V_38 = F_85 ( V_2 , V_14 , V_98 , V_12 , V_21 , false , false ,
V_106 ) ;
if ( F_90 ( V_38 ) ) {
V_79 = F_91 ( V_38 ) ;
goto V_27;
}
F_92 ( & V_38 -> V_48 , V_67 ) ;
if ( V_106 ) {
F_63 ( & V_106 -> V_48 ) ;
if ( ! F_3 ( V_2 ) )
F_76 ( V_2 , V_106 ) ;
}
V_79 = 0 ;
V_27:
F_64 ( & V_86 -> V_68 , V_85 ) ;
return V_79 ;
}
static int F_93 ( struct V_15 * V_3 , void * V_14 , void * V_98 ,
T_3 V_8 )
{
struct V_1 * V_2 = F_14 ( V_3 , struct V_1 , V_3 ) ;
struct V_10 * V_38 , * V_106 = NULL ;
struct V_72 * V_67 ;
unsigned long V_85 ;
struct V_62 * V_86 ;
T_1 V_12 , V_21 ;
int V_79 ;
if ( F_50 ( V_8 > V_109 ) )
return - V_53 ;
F_53 ( ! F_54 () ) ;
V_12 = V_3 -> V_12 ;
V_21 = F_43 ( V_14 , V_12 ) ;
V_86 = F_45 ( V_2 , V_21 ) ;
V_67 = & V_86 -> V_67 ;
V_38 = F_12 ( V_2 , V_14 , V_21 ) ;
if ( ! V_38 )
return - V_28 ;
memcpy ( V_38 -> V_14 + F_18 ( V_3 -> V_12 , 8 ) , V_98 , V_3 -> V_31 ) ;
F_62 ( & V_86 -> V_68 , V_85 ) ;
V_106 = F_47 ( V_67 , V_21 , V_14 , V_12 ) ;
V_79 = F_88 ( V_2 , V_106 , V_8 ) ;
if ( V_79 )
goto V_27;
F_92 ( & V_38 -> V_48 , V_67 ) ;
if ( V_106 ) {
F_61 ( & V_38 -> V_25 ) ;
F_63 ( & V_106 -> V_48 ) ;
}
V_79 = 0 ;
V_27:
F_64 ( & V_86 -> V_68 , V_85 ) ;
if ( V_79 )
F_94 ( & V_2 -> V_24 , & V_38 -> V_25 ) ;
else if ( V_106 )
F_94 ( & V_2 -> V_24 , & V_106 -> V_25 ) ;
return V_79 ;
}
static int F_95 ( struct V_15 * V_3 , void * V_14 ,
void * V_98 , T_3 V_8 ,
bool V_99 )
{
struct V_1 * V_2 = F_14 ( V_3 , struct V_1 , V_3 ) ;
struct V_10 * V_38 = NULL , * V_106 ;
struct V_72 * V_67 ;
unsigned long V_85 ;
struct V_62 * V_86 ;
T_1 V_12 , V_21 ;
int V_79 ;
if ( F_50 ( V_8 > V_109 ) )
return - V_53 ;
F_53 ( ! F_54 () ) ;
V_12 = V_3 -> V_12 ;
V_21 = F_43 ( V_14 , V_12 ) ;
V_86 = F_45 ( V_2 , V_21 ) ;
V_67 = & V_86 -> V_67 ;
F_62 ( & V_86 -> V_68 , V_85 ) ;
V_106 = F_47 ( V_67 , V_21 , V_14 , V_12 ) ;
V_79 = F_88 ( V_2 , V_106 , V_8 ) ;
if ( V_79 )
goto V_27;
if ( V_106 ) {
F_80 ( V_2 , F_5 ( V_106 , V_12 ) ,
V_98 , V_99 ) ;
} else {
V_38 = F_85 ( V_2 , V_14 , V_98 , V_12 ,
V_21 , true , V_99 , NULL ) ;
if ( F_90 ( V_38 ) ) {
V_79 = F_91 ( V_38 ) ;
goto V_27;
}
F_92 ( & V_38 -> V_48 , V_67 ) ;
}
V_79 = 0 ;
V_27:
F_64 ( & V_86 -> V_68 , V_85 ) ;
return V_79 ;
}
static int F_96 ( struct V_15 * V_3 , void * V_14 ,
void * V_98 , T_3 V_8 ,
bool V_99 )
{
struct V_1 * V_2 = F_14 ( V_3 , struct V_1 , V_3 ) ;
struct V_10 * V_38 = NULL , * V_106 ;
struct V_72 * V_67 ;
unsigned long V_85 ;
struct V_62 * V_86 ;
T_1 V_12 , V_21 ;
int V_79 ;
if ( F_50 ( V_8 > V_109 ) )
return - V_53 ;
F_53 ( ! F_54 () ) ;
V_12 = V_3 -> V_12 ;
V_21 = F_43 ( V_14 , V_12 ) ;
V_86 = F_45 ( V_2 , V_21 ) ;
V_67 = & V_86 -> V_67 ;
if ( V_8 != V_109 ) {
V_38 = F_12 ( V_2 , V_14 , V_21 ) ;
if ( ! V_38 )
return - V_28 ;
}
F_62 ( & V_86 -> V_68 , V_85 ) ;
V_106 = F_47 ( V_67 , V_21 , V_14 , V_12 ) ;
V_79 = F_88 ( V_2 , V_106 , V_8 ) ;
if ( V_79 )
goto V_27;
if ( V_106 ) {
F_61 ( & V_106 -> V_25 ) ;
F_80 ( V_2 , F_5 ( V_106 , V_12 ) ,
V_98 , V_99 ) ;
} else {
F_80 ( V_2 , F_5 ( V_38 , V_12 ) ,
V_98 , V_99 ) ;
F_92 ( & V_38 -> V_48 , V_67 ) ;
V_38 = NULL ;
}
V_79 = 0 ;
V_27:
F_64 ( & V_86 -> V_68 , V_85 ) ;
if ( V_38 )
F_94 ( & V_2 -> V_24 , & V_38 -> V_25 ) ;
return V_79 ;
}
static int F_97 ( struct V_15 * V_3 , void * V_14 ,
void * V_98 , T_3 V_8 )
{
return F_95 ( V_3 , V_14 , V_98 , V_8 , false ) ;
}
static int F_98 ( struct V_15 * V_3 , void * V_14 ,
void * V_98 , T_3 V_8 )
{
return F_96 ( V_3 , V_14 , V_98 , V_8 ,
false ) ;
}
static int F_99 ( struct V_15 * V_3 , void * V_14 )
{
struct V_1 * V_2 = F_14 ( V_3 , struct V_1 , V_3 ) ;
struct V_72 * V_67 ;
struct V_62 * V_86 ;
struct V_10 * V_11 ;
unsigned long V_85 ;
T_1 V_21 , V_12 ;
int V_79 = - V_90 ;
F_53 ( ! F_54 () ) ;
V_12 = V_3 -> V_12 ;
V_21 = F_43 ( V_14 , V_12 ) ;
V_86 = F_45 ( V_2 , V_21 ) ;
V_67 = & V_86 -> V_67 ;
F_62 ( & V_86 -> V_68 , V_85 ) ;
V_11 = F_47 ( V_67 , V_21 , V_14 , V_12 ) ;
if ( V_11 ) {
F_63 ( & V_11 -> V_48 ) ;
F_76 ( V_2 , V_11 ) ;
V_79 = 0 ;
}
F_64 ( & V_86 -> V_68 , V_85 ) ;
return V_79 ;
}
static int F_100 ( struct V_15 * V_3 , void * V_14 )
{
struct V_1 * V_2 = F_14 ( V_3 , struct V_1 , V_3 ) ;
struct V_72 * V_67 ;
struct V_62 * V_86 ;
struct V_10 * V_11 ;
unsigned long V_85 ;
T_1 V_21 , V_12 ;
int V_79 = - V_90 ;
F_53 ( ! F_54 () ) ;
V_12 = V_3 -> V_12 ;
V_21 = F_43 ( V_14 , V_12 ) ;
V_86 = F_45 ( V_2 , V_21 ) ;
V_67 = & V_86 -> V_67 ;
F_62 ( & V_86 -> V_68 , V_85 ) ;
V_11 = F_47 ( V_67 , V_21 , V_14 , V_12 ) ;
if ( V_11 ) {
F_63 ( & V_11 -> V_48 ) ;
V_79 = 0 ;
}
F_64 ( & V_86 -> V_68 , V_85 ) ;
if ( V_11 )
F_94 ( & V_2 -> V_24 , & V_11 -> V_25 ) ;
return V_79 ;
}
static void F_101 ( struct V_1 * V_2 )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_56 ; V_16 ++ ) {
struct V_72 * V_67 = F_46 ( V_2 , V_16 ) ;
struct V_73 * V_74 ;
struct V_10 * V_11 ;
F_102 (l, n, head, hash_node) {
F_63 ( & V_11 -> V_48 ) ;
F_70 ( V_2 , V_11 ) ;
}
}
}
static void F_103 ( struct V_15 * V_3 )
{
struct V_1 * V_2 = F_14 ( V_3 , struct V_1 , V_3 ) ;
F_104 () ;
F_105 () ;
if ( ! F_3 ( V_2 ) )
F_101 ( V_2 ) ;
else
F_25 ( V_2 ) ;
F_10 ( V_2 -> V_41 ) ;
F_11 ( V_2 -> V_66 ) ;
F_42 ( V_2 ) ;
}
static void * F_106 ( struct V_15 * V_3 , void * V_14 )
{
struct V_10 * V_11 = F_52 ( V_3 , V_14 ) ;
if ( V_11 )
return F_81 ( F_5 ( V_11 , V_3 -> V_12 ) ) ;
else
return NULL ;
}
static void * F_107 ( struct V_15 * V_3 , void * V_14 )
{
struct V_10 * V_11 = F_52 ( V_3 , V_14 ) ;
if ( V_11 ) {
F_61 ( & V_11 -> V_25 ) ;
return F_81 ( F_5 ( V_11 , V_3 -> V_12 ) ) ;
}
return NULL ;
}
int F_108 ( struct V_15 * V_3 , void * V_14 , void * V_98 )
{
struct V_1 * V_2 = F_14 ( V_3 , struct V_1 , V_3 ) ;
struct V_10 * V_11 ;
void T_2 * V_13 ;
int V_79 = - V_90 ;
int V_40 , V_100 = 0 ;
T_1 V_30 ;
V_30 = F_18 ( V_3 -> V_31 , 8 ) ;
F_109 () ;
V_11 = F_52 ( V_3 , V_14 ) ;
if ( ! V_11 )
goto V_110;
if ( F_1 ( V_2 ) )
F_61 ( & V_11 -> V_25 ) ;
V_13 = F_5 ( V_11 , V_3 -> V_12 ) ;
F_29 (cpu) {
F_82 ( V_98 + V_100 ,
F_31 ( V_13 , V_40 ) , V_30 ) ;
V_100 += V_30 ;
}
V_79 = 0 ;
V_110:
F_110 () ;
return V_79 ;
}
int F_111 ( struct V_15 * V_3 , void * V_14 , void * V_98 ,
T_3 V_8 )
{
struct V_1 * V_2 = F_14 ( V_3 , struct V_1 , V_3 ) ;
int V_79 ;
F_109 () ;
if ( F_1 ( V_2 ) )
V_79 = F_96 ( V_3 , V_14 , V_98 ,
V_8 , true ) ;
else
V_79 = F_95 ( V_3 , V_14 , V_98 , V_8 ,
true ) ;
F_110 () ;
return V_79 ;
}
static struct V_15 * F_112 ( union V_42 * V_43 )
{
if ( V_43 -> V_31 != sizeof( T_1 ) )
return F_35 ( - V_53 ) ;
return F_32 ( V_43 ) ;
}
static void F_113 ( struct V_15 * V_3 )
{
struct V_1 * V_2 = F_14 ( V_3 , struct V_1 , V_3 ) ;
struct V_73 * V_74 ;
struct V_72 * V_67 ;
struct V_10 * V_11 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_56 ; V_16 ++ ) {
V_67 = F_46 ( V_2 , V_16 ) ;
F_102 (l, n, head, hash_node) {
void * V_96 = F_6 ( V_3 , V_11 ) ;
V_3 -> V_94 -> V_95 ( V_96 ) ;
}
}
F_103 ( V_3 ) ;
}
int F_114 ( struct V_15 * V_3 , void * V_14 , T_1 * V_98 )
{
void * * V_96 ;
int V_79 = 0 ;
if ( ! V_3 -> V_94 -> V_111 )
return - V_54 ;
F_109 () ;
V_96 = F_55 ( V_3 , V_14 ) ;
if ( V_96 )
* V_98 = V_3 -> V_94 -> V_111 ( F_115 ( * V_96 ) ) ;
else
V_79 = - V_90 ;
F_110 () ;
return V_79 ;
}
int F_116 ( struct V_15 * V_3 , struct V_112 * V_113 ,
void * V_14 , void * V_98 , T_3 V_8 )
{
void * V_96 ;
int V_79 ;
T_1 V_114 = * ( T_1 * ) V_98 ;
V_96 = V_3 -> V_94 -> V_115 ( V_3 , V_113 , V_114 ) ;
if ( F_90 ( V_96 ) )
return F_91 ( V_96 ) ;
V_79 = F_89 ( V_3 , V_14 , & V_96 , V_8 ) ;
if ( V_79 )
V_3 -> V_94 -> V_95 ( V_96 ) ;
return V_79 ;
}
static struct V_15 * F_117 ( union V_42 * V_43 )
{
struct V_15 * V_3 , * V_116 ;
V_116 = F_118 ( V_43 -> V_117 ) ;
if ( F_90 ( V_116 ) )
return V_116 ;
V_3 = F_112 ( V_43 ) ;
if ( F_90 ( V_3 ) ) {
F_119 ( V_116 ) ;
return V_3 ;
}
V_3 -> V_116 = V_116 ;
return V_3 ;
}
static void * F_120 ( struct V_15 * V_3 , void * V_14 )
{
struct V_15 * * V_118 = F_55 ( V_3 , V_14 ) ;
if ( ! V_118 )
return NULL ;
return F_115 ( * V_118 ) ;
}
static void F_121 ( struct V_15 * V_3 )
{
F_119 ( V_3 -> V_116 ) ;
F_113 ( V_3 ) ;
}
