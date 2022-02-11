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
V_2 -> V_17 = F_17 ( V_2 -> V_18 * V_26 ,
V_2 -> V_3 . V_29 ) ;
if ( ! V_2 -> V_17 )
return - V_28 ;
if ( ! F_2 ( V_2 ) )
goto V_30;
for ( V_16 = 0 ; V_16 < V_26 ; V_16 ++ ) {
T_1 V_31 = F_18 ( V_2 -> V_3 . V_32 , 8 ) ;
void T_2 * V_13 ;
V_13 = F_19 ( V_31 , 8 , V_33 | V_34 ) ;
if ( ! V_13 )
goto V_19;
F_4 ( F_8 ( V_2 , V_16 ) , V_2 -> V_3 . V_12 ,
V_13 ) ;
}
V_30:
if ( F_1 ( V_2 ) )
V_27 = F_20 ( & V_2 -> V_24 ,
V_2 -> V_3 . V_8 & V_35 ,
F_21 ( struct V_10 , V_21 ) -
F_21 ( struct V_10 , V_25 ) ,
V_36 ,
V_2 ) ;
else
V_27 = F_22 ( & V_2 -> V_37 ) ;
if ( V_27 )
goto V_19;
if ( F_1 ( V_2 ) )
F_23 ( & V_2 -> V_24 , V_2 -> V_17 ,
F_21 ( struct V_10 , V_25 ) ,
V_2 -> V_18 , V_26 ) ;
else
F_24 ( & V_2 -> V_37 ,
V_2 -> V_17 + F_21 ( struct V_10 , V_38 ) ,
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
F_27 ( & V_2 -> V_37 ) ;
}
static int F_28 ( struct V_1 * V_2 )
{
struct V_10 * T_2 * V_13 , * V_39 ;
struct V_40 * V_11 ;
int V_41 ;
V_13 = F_19 ( sizeof( struct V_10 * ) , 8 ,
V_33 | V_34 ) ;
if ( ! V_13 )
return - V_28 ;
F_29 (cpu) {
V_11 = F_30 ( & V_2 -> V_37 ) ;
V_39 = F_14 ( V_11 , struct V_10 , V_38 ) ;
* F_31 ( V_13 , V_41 ) = V_39 ;
}
V_2 -> V_42 = V_13 ;
return 0 ;
}
static struct V_15 * F_32 ( union V_43 * V_44 )
{
bool V_45 = ( V_44 -> V_4 == V_7 ||
V_44 -> V_4 == V_6 ) ;
bool V_24 = ( V_44 -> V_4 == V_5 ||
V_44 -> V_4 == V_6 ) ;
bool V_46 = ( V_44 -> V_8 & V_35 ) ;
bool V_47 = ! ( V_44 -> V_8 & V_9 ) ;
int V_29 = F_33 ( V_44 ) ;
struct V_1 * V_2 ;
int V_27 , V_16 ;
T_3 V_48 ;
F_34 ( F_21 ( struct V_10 , V_2 ) !=
F_21 ( struct V_10 , V_49 . V_50 ) ) ;
F_34 ( F_21 ( struct V_10 , V_38 . V_51 ) !=
F_21 ( struct V_10 , V_49 . V_50 ) ) ;
if ( V_24 && ! F_35 ( V_52 ) )
return F_36 ( - V_53 ) ;
if ( V_44 -> V_8 & ~ V_54 )
return F_36 ( - V_55 ) ;
if ( ! V_24 && V_46 )
return F_36 ( - V_55 ) ;
if ( V_24 && ! V_47 )
return F_36 ( - V_56 ) ;
if ( V_29 != V_57 && ( V_45 || V_46 ) )
return F_36 ( - V_55 ) ;
V_2 = F_37 ( sizeof( * V_2 ) , V_33 ) ;
if ( ! V_2 )
return F_36 ( - V_28 ) ;
V_2 -> V_3 . V_4 = V_44 -> V_4 ;
V_2 -> V_3 . V_12 = V_44 -> V_12 ;
V_2 -> V_3 . V_32 = V_44 -> V_32 ;
V_2 -> V_3 . V_20 = V_44 -> V_20 ;
V_2 -> V_3 . V_8 = V_44 -> V_8 ;
V_2 -> V_3 . V_29 = V_29 ;
V_27 = - V_55 ;
if ( V_2 -> V_3 . V_20 == 0 || V_2 -> V_3 . V_12 == 0 ||
V_2 -> V_3 . V_32 == 0 )
goto V_58;
if ( V_46 ) {
V_2 -> V_3 . V_20 = F_7 ( V_44 -> V_20 ,
F_16 () ) ;
if ( V_2 -> V_3 . V_20 < V_44 -> V_20 )
V_2 -> V_3 . V_20 = F_38 ( V_44 -> V_20 ,
F_16 () ) ;
}
V_2 -> V_59 = F_39 ( V_2 -> V_3 . V_20 ) ;
V_27 = - V_60 ;
if ( V_2 -> V_3 . V_12 > V_61 )
goto V_58;
if ( V_2 -> V_3 . V_32 >= V_62 -
V_61 - sizeof( struct V_10 ) )
goto V_58;
V_2 -> V_18 = sizeof( struct V_10 ) +
F_18 ( V_2 -> V_3 . V_12 , 8 ) ;
if ( V_45 )
V_2 -> V_18 += sizeof( void * ) ;
else
V_2 -> V_18 += F_18 ( V_2 -> V_3 . V_32 , 8 ) ;
if ( V_2 -> V_59 == 0 ||
V_2 -> V_59 > V_63 / sizeof( struct V_64 ) )
goto V_58;
V_48 = ( T_3 ) V_2 -> V_59 * sizeof( struct V_64 ) +
( T_3 ) V_2 -> V_18 * V_2 -> V_3 . V_20 ;
if ( V_45 )
V_48 += ( T_3 ) F_18 ( V_2 -> V_3 . V_32 , 8 ) *
F_16 () * V_2 -> V_3 . V_20 ;
else
V_48 += ( T_3 ) V_2 -> V_18 * F_16 () ;
if ( V_48 >= V_63 - V_65 )
goto V_58;
V_2 -> V_3 . V_66 = F_18 ( V_48 , V_65 ) >> V_67 ;
V_27 = F_40 ( V_2 -> V_3 . V_66 ) ;
if ( V_27 )
goto V_58;
V_27 = - V_28 ;
V_2 -> V_68 = F_17 ( V_2 -> V_59 *
sizeof( struct V_64 ) ,
V_2 -> V_3 . V_29 ) ;
if ( ! V_2 -> V_68 )
goto V_58;
for ( V_16 = 0 ; V_16 < V_2 -> V_59 ; V_16 ++ ) {
F_41 ( & V_2 -> V_68 [ V_16 ] . V_69 , V_16 ) ;
F_42 ( & V_2 -> V_68 [ V_16 ] . V_70 ) ;
}
if ( V_47 ) {
V_27 = F_15 ( V_2 ) ;
if ( V_27 )
goto V_71;
if ( ! V_45 && ! V_24 ) {
V_27 = F_28 ( V_2 ) ;
if ( V_27 )
goto V_72;
}
}
return & V_2 -> V_3 ;
V_72:
F_25 ( V_2 ) ;
V_71:
F_11 ( V_2 -> V_68 ) ;
V_58:
F_43 ( V_2 ) ;
return F_36 ( V_27 ) ;
}
static inline T_1 F_44 ( const void * V_14 , T_1 V_73 )
{
return F_45 ( V_14 , V_73 , 0 ) ;
}
static inline struct V_64 * F_46 ( struct V_1 * V_2 , T_1 V_21 )
{
return & V_2 -> V_68 [ V_21 & ( V_2 -> V_59 - 1 ) ] ;
}
static inline struct V_74 * F_47 ( struct V_1 * V_2 , T_1 V_21 )
{
return & F_46 ( V_2 , V_21 ) -> V_69 ;
}
static struct V_10 * F_48 ( struct V_74 * V_69 , T_1 V_21 ,
void * V_14 , T_1 V_12 )
{
struct V_75 * V_76 ;
struct V_10 * V_11 ;
F_49 (l, n, head, hash_node)
if ( V_11 -> V_21 == V_21 && ! memcmp ( & V_11 -> V_14 , V_14 , V_12 ) )
return V_11 ;
return NULL ;
}
static struct V_10 * F_50 ( struct V_74 * V_69 ,
T_1 V_21 , void * V_14 ,
T_1 V_12 , T_1 V_59 )
{
struct V_75 * V_76 ;
struct V_10 * V_11 ;
V_77:
F_49 (l, n, head, hash_node)
if ( V_11 -> V_21 == V_21 && ! memcmp ( & V_11 -> V_14 , V_14 , V_12 ) )
return V_11 ;
if ( F_51 ( F_52 ( V_76 ) != ( V_21 & ( V_59 - 1 ) ) ) )
goto V_77;
return NULL ;
}
static void * F_53 ( struct V_15 * V_3 , void * V_14 )
{
struct V_1 * V_2 = F_14 ( V_3 , struct V_1 , V_3 ) ;
struct V_74 * V_69 ;
struct V_10 * V_11 ;
T_1 V_21 , V_12 ;
F_54 ( ! F_55 () ) ;
V_12 = V_3 -> V_12 ;
V_21 = F_44 ( V_14 , V_12 ) ;
V_69 = F_47 ( V_2 , V_21 ) ;
V_11 = F_50 ( V_69 , V_21 , V_14 , V_12 , V_2 -> V_59 ) ;
return V_11 ;
}
static void * F_56 ( struct V_15 * V_3 , void * V_14 )
{
struct V_10 * V_11 = F_53 ( V_3 , V_14 ) ;
if ( V_11 )
return V_11 -> V_14 + F_18 ( V_3 -> V_12 , 8 ) ;
return NULL ;
}
static T_1 F_57 ( struct V_15 * V_3 , struct V_78 * V_79 )
{
struct V_78 * V_80 = V_79 ;
const int V_81 = V_82 ;
* V_80 ++ = F_58 ( ( T_3 ( * ) ( T_3 , T_3 , T_3 , T_3 , T_3 ) ) F_53 ) ;
* V_80 ++ = F_59 ( V_83 , V_81 , 0 , 1 ) ;
* V_80 ++ = F_60 ( V_84 , V_81 ,
F_21 ( struct V_10 , V_14 ) +
F_18 ( V_3 -> V_12 , 8 ) ) ;
return V_80 - V_79 ;
}
static void * F_61 ( struct V_15 * V_3 , void * V_14 )
{
struct V_10 * V_11 = F_53 ( V_3 , V_14 ) ;
if ( V_11 ) {
F_62 ( & V_11 -> V_25 ) ;
return V_11 -> V_14 + F_18 ( V_3 -> V_12 , 8 ) ;
}
return NULL ;
}
static T_1 F_63 ( struct V_15 * V_3 ,
struct V_78 * V_79 )
{
struct V_78 * V_80 = V_79 ;
const int V_81 = V_82 ;
const int V_85 = V_86 ;
* V_80 ++ = F_58 ( ( T_3 ( * ) ( T_3 , T_3 , T_3 , T_3 , T_3 ) ) F_53 ) ;
* V_80 ++ = F_59 ( V_83 , V_81 , 0 , 4 ) ;
* V_80 ++ = F_64 ( V_87 , V_85 , V_81 ,
F_21 ( struct V_10 , V_25 ) +
F_21 ( struct V_22 , V_88 ) ) ;
* V_80 ++ = F_59 ( V_89 , V_85 , 0 , 1 ) ;
* V_80 ++ = F_65 ( V_87 , V_81 ,
F_21 ( struct V_10 , V_25 ) +
F_21 ( struct V_22 , V_88 ) ,
1 ) ;
* V_80 ++ = F_60 ( V_84 , V_81 ,
F_21 ( struct V_10 , V_14 ) +
F_18 ( V_3 -> V_12 , 8 ) ) ;
return V_80 - V_79 ;
}
static bool V_36 ( void * V_90 , struct V_22 * V_23 )
{
struct V_1 * V_2 = (struct V_1 * ) V_90 ;
struct V_10 * V_11 = NULL , * V_91 ;
struct V_74 * V_69 ;
struct V_75 * V_76 ;
unsigned long V_92 ;
struct V_64 * V_93 ;
V_91 = F_14 ( V_23 , struct V_10 , V_25 ) ;
V_93 = F_46 ( V_2 , V_91 -> V_21 ) ;
V_69 = & V_93 -> V_69 ;
F_66 ( & V_93 -> V_70 , V_92 ) ;
F_49 (l, n, head, hash_node)
if ( V_11 == V_91 ) {
F_67 ( & V_11 -> V_49 ) ;
break;
}
F_68 ( & V_93 -> V_70 , V_92 ) ;
return V_11 == V_91 ;
}
static int F_69 ( struct V_15 * V_3 , void * V_14 , void * V_94 )
{
struct V_1 * V_2 = F_14 ( V_3 , struct V_1 , V_3 ) ;
struct V_74 * V_69 ;
struct V_10 * V_11 , * V_95 ;
T_1 V_21 , V_12 ;
int V_16 = 0 ;
F_54 ( ! F_55 () ) ;
V_12 = V_3 -> V_12 ;
if ( ! V_14 )
goto V_96;
V_21 = F_44 ( V_14 , V_12 ) ;
V_69 = F_47 ( V_2 , V_21 ) ;
V_11 = F_50 ( V_69 , V_21 , V_14 , V_12 , V_2 -> V_59 ) ;
if ( ! V_11 )
goto V_96;
V_95 = F_70 ( F_71 ( F_72 ( & V_11 -> V_49 ) ) ,
struct V_10 , V_49 ) ;
if ( V_95 ) {
memcpy ( V_94 , V_95 -> V_14 , V_12 ) ;
return 0 ;
}
V_16 = V_21 & ( V_2 -> V_59 - 1 ) ;
V_16 ++ ;
V_96:
for (; V_16 < V_2 -> V_59 ; V_16 ++ ) {
V_69 = F_47 ( V_2 , V_16 ) ;
V_95 = F_70 ( F_71 ( F_73 ( V_69 ) ) ,
struct V_10 , V_49 ) ;
if ( V_95 ) {
memcpy ( V_94 , V_95 -> V_14 , V_12 ) ;
return 0 ;
}
}
return - V_97 ;
}
static void F_74 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
if ( V_2 -> V_3 . V_4 == V_7 )
F_10 ( F_5 ( V_11 , V_2 -> V_3 . V_12 ) ) ;
F_43 ( V_11 ) ;
}
static void F_75 ( struct V_98 * V_69 )
{
struct V_10 * V_11 = F_14 ( V_69 , struct V_10 , V_99 ) ;
struct V_1 * V_2 = V_11 -> V_2 ;
F_76 () ;
F_77 ( V_100 ) ;
F_74 ( V_2 , V_11 ) ;
F_78 ( V_100 ) ;
F_79 () ;
}
static void F_80 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
struct V_15 * V_3 = & V_2 -> V_3 ;
if ( V_3 -> V_101 -> V_102 ) {
void * V_103 = F_6 ( V_3 , V_11 ) ;
V_3 -> V_101 -> V_102 ( V_103 ) ;
}
if ( F_3 ( V_2 ) ) {
F_81 ( & V_2 -> V_37 , & V_11 -> V_38 ) ;
} else {
F_82 ( & V_2 -> V_104 ) ;
V_11 -> V_2 = V_2 ;
F_83 ( & V_11 -> V_99 , F_75 ) ;
}
}
static void F_84 ( struct V_1 * V_2 , void T_2 * V_13 ,
void * V_105 , bool V_106 )
{
if ( ! V_106 ) {
memcpy ( F_85 ( V_13 ) , V_105 , V_2 -> V_3 . V_32 ) ;
} else {
T_1 V_31 = F_18 ( V_2 -> V_3 . V_32 , 8 ) ;
int V_107 = 0 , V_41 ;
F_29 (cpu) {
F_86 ( F_31 ( V_13 , V_41 ) ,
V_105 + V_107 , V_31 ) ;
V_107 += V_31 ;
}
}
}
static bool F_87 ( const struct V_1 * V_2 )
{
return V_2 -> V_3 . V_4 == V_108 &&
V_109 == 64 ;
}
static T_1 F_88 ( const struct V_1 * V_2 , bool V_45 )
{
T_1 V_31 = V_2 -> V_3 . V_32 ;
if ( V_45 || F_87 ( V_2 ) )
V_31 = F_18 ( V_31 , 8 ) ;
return V_31 ;
}
static struct V_10 * F_89 ( struct V_1 * V_2 , void * V_14 ,
void * V_105 , T_1 V_12 , T_1 V_21 ,
bool V_45 , bool V_106 ,
struct V_10 * V_110 )
{
T_1 V_31 = F_88 ( V_2 , V_45 ) ;
bool V_47 = F_3 ( V_2 ) ;
struct V_10 * V_39 , * * V_111 ;
void T_2 * V_13 ;
if ( V_47 ) {
if ( V_110 ) {
V_111 = F_85 ( V_2 -> V_42 ) ;
V_39 = * V_111 ;
* V_111 = V_110 ;
} else {
struct V_40 * V_11 ;
V_11 = F_30 ( & V_2 -> V_37 ) ;
if ( ! V_11 )
return F_36 ( - V_60 ) ;
V_39 = F_14 ( V_11 , struct V_10 , V_38 ) ;
}
} else {
if ( F_90 ( & V_2 -> V_104 ) > V_2 -> V_3 . V_20 )
if ( ! V_110 ) {
F_82 ( & V_2 -> V_104 ) ;
return F_36 ( - V_60 ) ;
}
V_39 = F_91 ( V_2 -> V_18 , V_112 | V_34 ,
V_2 -> V_3 . V_29 ) ;
if ( ! V_39 )
return F_36 ( - V_28 ) ;
}
memcpy ( V_39 -> V_14 , V_14 , V_12 ) ;
if ( V_45 ) {
if ( V_47 ) {
V_13 = F_5 ( V_39 , V_12 ) ;
} else {
V_13 = F_19 ( V_31 , 8 ,
V_112 | V_34 ) ;
if ( ! V_13 ) {
F_43 ( V_39 ) ;
return F_36 ( - V_28 ) ;
}
}
F_84 ( V_2 , V_13 , V_105 , V_106 ) ;
if ( ! V_47 )
F_4 ( V_39 , V_12 , V_13 ) ;
} else {
memcpy ( V_39 -> V_14 + F_18 ( V_12 , 8 ) , V_105 , V_31 ) ;
}
V_39 -> V_21 = V_21 ;
return V_39 ;
}
static int F_92 ( struct V_1 * V_2 , struct V_10 * V_113 ,
T_3 V_8 )
{
if ( V_113 && V_8 == V_114 )
return - V_115 ;
if ( ! V_113 && V_8 == V_116 )
return - V_97 ;
return 0 ;
}
static int F_93 ( struct V_15 * V_3 , void * V_14 , void * V_105 ,
T_3 V_8 )
{
struct V_1 * V_2 = F_14 ( V_3 , struct V_1 , V_3 ) ;
struct V_10 * V_39 = NULL , * V_113 ;
struct V_74 * V_69 ;
unsigned long V_92 ;
struct V_64 * V_93 ;
T_1 V_12 , V_21 ;
int V_81 ;
if ( F_51 ( V_8 > V_116 ) )
return - V_55 ;
F_54 ( ! F_55 () ) ;
V_12 = V_3 -> V_12 ;
V_21 = F_44 ( V_14 , V_12 ) ;
V_93 = F_46 ( V_2 , V_21 ) ;
V_69 = & V_93 -> V_69 ;
F_66 ( & V_93 -> V_70 , V_92 ) ;
V_113 = F_48 ( V_69 , V_21 , V_14 , V_12 ) ;
V_81 = F_92 ( V_2 , V_113 , V_8 ) ;
if ( V_81 )
goto V_27;
V_39 = F_89 ( V_2 , V_14 , V_105 , V_12 , V_21 , false , false ,
V_113 ) ;
if ( F_94 ( V_39 ) ) {
V_81 = F_95 ( V_39 ) ;
goto V_27;
}
F_96 ( & V_39 -> V_49 , V_69 ) ;
if ( V_113 ) {
F_67 ( & V_113 -> V_49 ) ;
if ( ! F_3 ( V_2 ) )
F_80 ( V_2 , V_113 ) ;
}
V_81 = 0 ;
V_27:
F_68 ( & V_93 -> V_70 , V_92 ) ;
return V_81 ;
}
static int F_97 ( struct V_15 * V_3 , void * V_14 , void * V_105 ,
T_3 V_8 )
{
struct V_1 * V_2 = F_14 ( V_3 , struct V_1 , V_3 ) ;
struct V_10 * V_39 , * V_113 = NULL ;
struct V_74 * V_69 ;
unsigned long V_92 ;
struct V_64 * V_93 ;
T_1 V_12 , V_21 ;
int V_81 ;
if ( F_51 ( V_8 > V_116 ) )
return - V_55 ;
F_54 ( ! F_55 () ) ;
V_12 = V_3 -> V_12 ;
V_21 = F_44 ( V_14 , V_12 ) ;
V_93 = F_46 ( V_2 , V_21 ) ;
V_69 = & V_93 -> V_69 ;
V_39 = F_12 ( V_2 , V_14 , V_21 ) ;
if ( ! V_39 )
return - V_28 ;
memcpy ( V_39 -> V_14 + F_18 ( V_3 -> V_12 , 8 ) , V_105 , V_3 -> V_32 ) ;
F_66 ( & V_93 -> V_70 , V_92 ) ;
V_113 = F_48 ( V_69 , V_21 , V_14 , V_12 ) ;
V_81 = F_92 ( V_2 , V_113 , V_8 ) ;
if ( V_81 )
goto V_27;
F_96 ( & V_39 -> V_49 , V_69 ) ;
if ( V_113 ) {
F_62 ( & V_39 -> V_25 ) ;
F_67 ( & V_113 -> V_49 ) ;
}
V_81 = 0 ;
V_27:
F_68 ( & V_93 -> V_70 , V_92 ) ;
if ( V_81 )
F_98 ( & V_2 -> V_24 , & V_39 -> V_25 ) ;
else if ( V_113 )
F_98 ( & V_2 -> V_24 , & V_113 -> V_25 ) ;
return V_81 ;
}
static int F_99 ( struct V_15 * V_3 , void * V_14 ,
void * V_105 , T_3 V_8 ,
bool V_106 )
{
struct V_1 * V_2 = F_14 ( V_3 , struct V_1 , V_3 ) ;
struct V_10 * V_39 = NULL , * V_113 ;
struct V_74 * V_69 ;
unsigned long V_92 ;
struct V_64 * V_93 ;
T_1 V_12 , V_21 ;
int V_81 ;
if ( F_51 ( V_8 > V_116 ) )
return - V_55 ;
F_54 ( ! F_55 () ) ;
V_12 = V_3 -> V_12 ;
V_21 = F_44 ( V_14 , V_12 ) ;
V_93 = F_46 ( V_2 , V_21 ) ;
V_69 = & V_93 -> V_69 ;
F_66 ( & V_93 -> V_70 , V_92 ) ;
V_113 = F_48 ( V_69 , V_21 , V_14 , V_12 ) ;
V_81 = F_92 ( V_2 , V_113 , V_8 ) ;
if ( V_81 )
goto V_27;
if ( V_113 ) {
F_84 ( V_2 , F_5 ( V_113 , V_12 ) ,
V_105 , V_106 ) ;
} else {
V_39 = F_89 ( V_2 , V_14 , V_105 , V_12 ,
V_21 , true , V_106 , NULL ) ;
if ( F_94 ( V_39 ) ) {
V_81 = F_95 ( V_39 ) ;
goto V_27;
}
F_96 ( & V_39 -> V_49 , V_69 ) ;
}
V_81 = 0 ;
V_27:
F_68 ( & V_93 -> V_70 , V_92 ) ;
return V_81 ;
}
static int F_100 ( struct V_15 * V_3 , void * V_14 ,
void * V_105 , T_3 V_8 ,
bool V_106 )
{
struct V_1 * V_2 = F_14 ( V_3 , struct V_1 , V_3 ) ;
struct V_10 * V_39 = NULL , * V_113 ;
struct V_74 * V_69 ;
unsigned long V_92 ;
struct V_64 * V_93 ;
T_1 V_12 , V_21 ;
int V_81 ;
if ( F_51 ( V_8 > V_116 ) )
return - V_55 ;
F_54 ( ! F_55 () ) ;
V_12 = V_3 -> V_12 ;
V_21 = F_44 ( V_14 , V_12 ) ;
V_93 = F_46 ( V_2 , V_21 ) ;
V_69 = & V_93 -> V_69 ;
if ( V_8 != V_116 ) {
V_39 = F_12 ( V_2 , V_14 , V_21 ) ;
if ( ! V_39 )
return - V_28 ;
}
F_66 ( & V_93 -> V_70 , V_92 ) ;
V_113 = F_48 ( V_69 , V_21 , V_14 , V_12 ) ;
V_81 = F_92 ( V_2 , V_113 , V_8 ) ;
if ( V_81 )
goto V_27;
if ( V_113 ) {
F_62 ( & V_113 -> V_25 ) ;
F_84 ( V_2 , F_5 ( V_113 , V_12 ) ,
V_105 , V_106 ) ;
} else {
F_84 ( V_2 , F_5 ( V_39 , V_12 ) ,
V_105 , V_106 ) ;
F_96 ( & V_39 -> V_49 , V_69 ) ;
V_39 = NULL ;
}
V_81 = 0 ;
V_27:
F_68 ( & V_93 -> V_70 , V_92 ) ;
if ( V_39 )
F_98 ( & V_2 -> V_24 , & V_39 -> V_25 ) ;
return V_81 ;
}
static int F_101 ( struct V_15 * V_3 , void * V_14 ,
void * V_105 , T_3 V_8 )
{
return F_99 ( V_3 , V_14 , V_105 , V_8 , false ) ;
}
static int F_102 ( struct V_15 * V_3 , void * V_14 ,
void * V_105 , T_3 V_8 )
{
return F_100 ( V_3 , V_14 , V_105 , V_8 ,
false ) ;
}
static int F_103 ( struct V_15 * V_3 , void * V_14 )
{
struct V_1 * V_2 = F_14 ( V_3 , struct V_1 , V_3 ) ;
struct V_74 * V_69 ;
struct V_64 * V_93 ;
struct V_10 * V_11 ;
unsigned long V_92 ;
T_1 V_21 , V_12 ;
int V_81 = - V_97 ;
F_54 ( ! F_55 () ) ;
V_12 = V_3 -> V_12 ;
V_21 = F_44 ( V_14 , V_12 ) ;
V_93 = F_46 ( V_2 , V_21 ) ;
V_69 = & V_93 -> V_69 ;
F_66 ( & V_93 -> V_70 , V_92 ) ;
V_11 = F_48 ( V_69 , V_21 , V_14 , V_12 ) ;
if ( V_11 ) {
F_67 ( & V_11 -> V_49 ) ;
F_80 ( V_2 , V_11 ) ;
V_81 = 0 ;
}
F_68 ( & V_93 -> V_70 , V_92 ) ;
return V_81 ;
}
static int F_104 ( struct V_15 * V_3 , void * V_14 )
{
struct V_1 * V_2 = F_14 ( V_3 , struct V_1 , V_3 ) ;
struct V_74 * V_69 ;
struct V_64 * V_93 ;
struct V_10 * V_11 ;
unsigned long V_92 ;
T_1 V_21 , V_12 ;
int V_81 = - V_97 ;
F_54 ( ! F_55 () ) ;
V_12 = V_3 -> V_12 ;
V_21 = F_44 ( V_14 , V_12 ) ;
V_93 = F_46 ( V_2 , V_21 ) ;
V_69 = & V_93 -> V_69 ;
F_66 ( & V_93 -> V_70 , V_92 ) ;
V_11 = F_48 ( V_69 , V_21 , V_14 , V_12 ) ;
if ( V_11 ) {
F_67 ( & V_11 -> V_49 ) ;
V_81 = 0 ;
}
F_68 ( & V_93 -> V_70 , V_92 ) ;
if ( V_11 )
F_98 ( & V_2 -> V_24 , & V_11 -> V_25 ) ;
return V_81 ;
}
static void F_105 ( struct V_1 * V_2 )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_59 ; V_16 ++ ) {
struct V_74 * V_69 = F_47 ( V_2 , V_16 ) ;
struct V_75 * V_76 ;
struct V_10 * V_11 ;
F_106 (l, n, head, hash_node) {
F_67 ( & V_11 -> V_49 ) ;
F_74 ( V_2 , V_11 ) ;
}
}
}
static void F_107 ( struct V_15 * V_3 )
{
struct V_1 * V_2 = F_14 ( V_3 , struct V_1 , V_3 ) ;
F_108 () ;
F_109 () ;
if ( ! F_3 ( V_2 ) )
F_105 ( V_2 ) ;
else
F_25 ( V_2 ) ;
F_10 ( V_2 -> V_42 ) ;
F_11 ( V_2 -> V_68 ) ;
F_43 ( V_2 ) ;
}
static void * F_110 ( struct V_15 * V_3 , void * V_14 )
{
struct V_10 * V_11 = F_53 ( V_3 , V_14 ) ;
if ( V_11 )
return F_85 ( F_5 ( V_11 , V_3 -> V_12 ) ) ;
else
return NULL ;
}
static void * F_111 ( struct V_15 * V_3 , void * V_14 )
{
struct V_10 * V_11 = F_53 ( V_3 , V_14 ) ;
if ( V_11 ) {
F_62 ( & V_11 -> V_25 ) ;
return F_85 ( F_5 ( V_11 , V_3 -> V_12 ) ) ;
}
return NULL ;
}
int F_112 ( struct V_15 * V_3 , void * V_14 , void * V_105 )
{
struct V_1 * V_2 = F_14 ( V_3 , struct V_1 , V_3 ) ;
struct V_10 * V_11 ;
void T_2 * V_13 ;
int V_81 = - V_97 ;
int V_41 , V_107 = 0 ;
T_1 V_31 ;
V_31 = F_18 ( V_3 -> V_32 , 8 ) ;
F_113 () ;
V_11 = F_53 ( V_3 , V_14 ) ;
if ( ! V_11 )
goto V_117;
if ( F_1 ( V_2 ) )
F_62 ( & V_11 -> V_25 ) ;
V_13 = F_5 ( V_11 , V_3 -> V_12 ) ;
F_29 (cpu) {
F_86 ( V_105 + V_107 ,
F_31 ( V_13 , V_41 ) , V_31 ) ;
V_107 += V_31 ;
}
V_81 = 0 ;
V_117:
F_114 () ;
return V_81 ;
}
int F_115 ( struct V_15 * V_3 , void * V_14 , void * V_105 ,
T_3 V_8 )
{
struct V_1 * V_2 = F_14 ( V_3 , struct V_1 , V_3 ) ;
int V_81 ;
F_113 () ;
if ( F_1 ( V_2 ) )
V_81 = F_100 ( V_3 , V_14 , V_105 ,
V_8 , true ) ;
else
V_81 = F_99 ( V_3 , V_14 , V_105 , V_8 ,
true ) ;
F_114 () ;
return V_81 ;
}
static struct V_15 * F_116 ( union V_43 * V_44 )
{
if ( V_44 -> V_32 != sizeof( T_1 ) )
return F_36 ( - V_55 ) ;
return F_32 ( V_44 ) ;
}
static void F_117 ( struct V_15 * V_3 )
{
struct V_1 * V_2 = F_14 ( V_3 , struct V_1 , V_3 ) ;
struct V_75 * V_76 ;
struct V_74 * V_69 ;
struct V_10 * V_11 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_59 ; V_16 ++ ) {
V_69 = F_47 ( V_2 , V_16 ) ;
F_106 (l, n, head, hash_node) {
void * V_103 = F_6 ( V_3 , V_11 ) ;
V_3 -> V_101 -> V_102 ( V_103 ) ;
}
}
F_107 ( V_3 ) ;
}
int F_118 ( struct V_15 * V_3 , void * V_14 , T_1 * V_105 )
{
void * * V_103 ;
int V_81 = 0 ;
if ( ! V_3 -> V_101 -> V_118 )
return - V_56 ;
F_113 () ;
V_103 = F_56 ( V_3 , V_14 ) ;
if ( V_103 )
* V_105 = V_3 -> V_101 -> V_118 ( F_119 ( * V_103 ) ) ;
else
V_81 = - V_97 ;
F_114 () ;
return V_81 ;
}
int F_120 ( struct V_15 * V_3 , struct V_119 * V_120 ,
void * V_14 , void * V_105 , T_3 V_8 )
{
void * V_103 ;
int V_81 ;
T_1 V_121 = * ( T_1 * ) V_105 ;
V_103 = V_3 -> V_101 -> V_122 ( V_3 , V_120 , V_121 ) ;
if ( F_94 ( V_103 ) )
return F_95 ( V_103 ) ;
V_81 = F_93 ( V_3 , V_14 , & V_103 , V_8 ) ;
if ( V_81 )
V_3 -> V_101 -> V_102 ( V_103 ) ;
return V_81 ;
}
static struct V_15 * F_121 ( union V_43 * V_44 )
{
struct V_15 * V_3 , * V_123 ;
V_123 = F_122 ( V_44 -> V_124 ) ;
if ( F_94 ( V_123 ) )
return V_123 ;
V_3 = F_116 ( V_44 ) ;
if ( F_94 ( V_3 ) ) {
F_123 ( V_123 ) ;
return V_3 ;
}
V_3 -> V_123 = V_123 ;
return V_3 ;
}
static void * F_124 ( struct V_15 * V_3 , void * V_14 )
{
struct V_15 * * V_125 = F_56 ( V_3 , V_14 ) ;
if ( ! V_125 )
return NULL ;
return F_119 ( * V_125 ) ;
}
static T_1 F_125 ( struct V_15 * V_3 ,
struct V_78 * V_79 )
{
struct V_78 * V_80 = V_79 ;
const int V_81 = V_82 ;
* V_80 ++ = F_58 ( ( T_3 ( * ) ( T_3 , T_3 , T_3 , T_3 , T_3 ) ) F_53 ) ;
* V_80 ++ = F_59 ( V_83 , V_81 , 0 , 2 ) ;
* V_80 ++ = F_60 ( V_84 , V_81 ,
F_21 ( struct V_10 , V_14 ) +
F_18 ( V_3 -> V_12 , 8 ) ) ;
* V_80 ++ = F_64 ( V_126 , V_81 , V_81 , 0 ) ;
return V_80 - V_79 ;
}
static void F_126 ( struct V_15 * V_3 )
{
F_123 ( V_3 -> V_123 ) ;
F_117 ( V_3 ) ;
}
