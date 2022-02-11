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
static struct V_10 * F_6 ( struct V_1 * V_2 , int V_15 )
{
return (struct V_10 * ) ( V_2 -> V_16 + V_15 * V_2 -> V_17 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
int V_15 ;
if ( ! F_2 ( V_2 ) )
goto V_18;
for ( V_15 = 0 ; V_15 < V_2 -> V_3 . V_19 ; V_15 ++ ) {
void T_2 * V_13 ;
V_13 = F_5 ( F_6 ( V_2 , V_15 ) ,
V_2 -> V_3 . V_12 ) ;
F_8 ( V_13 ) ;
}
V_18:
F_9 ( V_2 -> V_16 ) ;
}
static struct V_10 * F_10 ( struct V_1 * V_2 , void * V_14 ,
T_1 V_20 )
{
struct V_21 * V_22 = F_11 ( & V_2 -> V_23 , V_20 ) ;
struct V_10 * V_11 ;
if ( V_22 ) {
V_11 = F_12 ( V_22 , struct V_10 , V_24 ) ;
memcpy ( V_11 -> V_14 , V_14 , V_2 -> V_3 . V_12 ) ;
return V_11 ;
}
return NULL ;
}
static int F_13 ( struct V_1 * V_2 )
{
T_1 V_25 = V_2 -> V_3 . V_19 ;
int V_26 = - V_27 , V_15 ;
if ( ! F_2 ( V_2 ) && ! F_1 ( V_2 ) )
V_25 += F_14 () ;
V_2 -> V_16 = F_15 ( V_2 -> V_17 * V_25 ) ;
if ( ! V_2 -> V_16 )
return - V_27 ;
if ( ! F_2 ( V_2 ) )
goto V_28;
for ( V_15 = 0 ; V_15 < V_25 ; V_15 ++ ) {
T_1 V_29 = F_16 ( V_2 -> V_3 . V_30 , 8 ) ;
void T_2 * V_13 ;
V_13 = F_17 ( V_29 , 8 , V_31 | V_32 ) ;
if ( ! V_13 )
goto V_18;
F_4 ( F_6 ( V_2 , V_15 ) , V_2 -> V_3 . V_12 ,
V_13 ) ;
}
V_28:
if ( F_1 ( V_2 ) )
V_26 = F_18 ( & V_2 -> V_23 ,
V_2 -> V_3 . V_8 & V_33 ,
F_19 ( struct V_10 , V_20 ) -
F_19 ( struct V_10 , V_24 ) ,
V_34 ,
V_2 ) ;
else
V_26 = F_20 ( & V_2 -> V_35 ) ;
if ( V_26 )
goto V_18;
if ( F_1 ( V_2 ) )
F_21 ( & V_2 -> V_23 , V_2 -> V_16 ,
F_19 ( struct V_10 , V_24 ) ,
V_2 -> V_17 , V_25 ) ;
else
F_22 ( & V_2 -> V_35 ,
V_2 -> V_16 + F_19 ( struct V_10 , V_36 ) ,
V_2 -> V_17 , V_25 ) ;
return 0 ;
V_18:
F_7 ( V_2 ) ;
return V_26 ;
}
static void F_23 ( struct V_1 * V_2 )
{
F_7 ( V_2 ) ;
if ( F_1 ( V_2 ) )
F_24 ( & V_2 -> V_23 ) ;
else
F_25 ( & V_2 -> V_35 ) ;
}
static int F_26 ( struct V_1 * V_2 )
{
struct V_10 * T_2 * V_13 , * V_37 ;
struct V_38 * V_11 ;
int V_39 ;
V_13 = F_17 ( sizeof( struct V_10 * ) , 8 ,
V_31 | V_32 ) ;
if ( ! V_13 )
return - V_27 ;
F_27 (cpu) {
V_11 = F_28 ( & V_2 -> V_35 ) ;
V_37 = F_12 ( V_11 , struct V_10 , V_36 ) ;
* F_29 ( V_13 , V_39 ) = V_37 ;
}
V_2 -> V_40 = V_13 ;
return 0 ;
}
static struct V_41 * F_30 ( union V_42 * V_43 )
{
bool V_44 = ( V_43 -> V_4 == V_7 ||
V_43 -> V_4 == V_6 ) ;
bool V_23 = ( V_43 -> V_4 == V_5 ||
V_43 -> V_4 == V_6 ) ;
bool V_45 = ( V_43 -> V_8 & V_33 ) ;
bool V_46 = ! ( V_43 -> V_8 & V_9 ) ;
struct V_1 * V_2 ;
int V_26 , V_15 ;
T_3 V_47 ;
F_31 ( F_19 ( struct V_10 , V_2 ) !=
F_19 ( struct V_10 , V_48 . V_49 ) ) ;
F_31 ( F_19 ( struct V_10 , V_36 . V_50 ) !=
F_19 ( struct V_10 , V_48 . V_49 ) ) ;
if ( V_23 && ! F_32 ( V_51 ) )
return F_33 ( - V_52 ) ;
if ( V_43 -> V_8 & ~ ( V_9 | V_33 ) )
return F_33 ( - V_53 ) ;
if ( ! V_23 && V_45 )
return F_33 ( - V_53 ) ;
if ( V_23 && ! V_46 )
return F_33 ( - V_54 ) ;
V_2 = F_34 ( sizeof( * V_2 ) , V_31 ) ;
if ( ! V_2 )
return F_33 ( - V_27 ) ;
V_2 -> V_3 . V_4 = V_43 -> V_4 ;
V_2 -> V_3 . V_12 = V_43 -> V_12 ;
V_2 -> V_3 . V_30 = V_43 -> V_30 ;
V_2 -> V_3 . V_19 = V_43 -> V_19 ;
V_2 -> V_3 . V_8 = V_43 -> V_8 ;
V_26 = - V_53 ;
if ( V_2 -> V_3 . V_19 == 0 || V_2 -> V_3 . V_12 == 0 ||
V_2 -> V_3 . V_30 == 0 )
goto V_55;
if ( V_45 ) {
V_2 -> V_3 . V_19 = F_35 ( V_43 -> V_19 ,
F_14 () ) ;
if ( V_2 -> V_3 . V_19 < V_43 -> V_19 )
V_2 -> V_3 . V_19 = F_36 ( V_43 -> V_19 ,
F_14 () ) ;
}
V_2 -> V_56 = F_37 ( V_2 -> V_3 . V_19 ) ;
V_26 = - V_57 ;
if ( V_2 -> V_3 . V_12 > V_58 )
goto V_55;
if ( V_2 -> V_3 . V_30 >= V_59 -
V_58 - sizeof( struct V_10 ) )
goto V_55;
if ( V_44 && F_16 ( V_2 -> V_3 . V_30 , 8 ) > V_60 )
goto V_55;
V_2 -> V_17 = sizeof( struct V_10 ) +
F_16 ( V_2 -> V_3 . V_12 , 8 ) ;
if ( V_44 )
V_2 -> V_17 += sizeof( void * ) ;
else
V_2 -> V_17 += F_16 ( V_2 -> V_3 . V_30 , 8 ) ;
if ( V_2 -> V_56 == 0 ||
V_2 -> V_56 > V_61 / sizeof( struct V_62 ) )
goto V_55;
V_47 = ( T_3 ) V_2 -> V_56 * sizeof( struct V_62 ) +
( T_3 ) V_2 -> V_17 * V_2 -> V_3 . V_19 ;
if ( V_44 )
V_47 += ( T_3 ) F_16 ( V_2 -> V_3 . V_30 , 8 ) *
F_14 () * V_2 -> V_3 . V_19 ;
else
V_47 += ( T_3 ) V_2 -> V_17 * F_14 () ;
if ( V_47 >= V_61 - V_63 )
goto V_55;
V_2 -> V_3 . V_64 = F_16 ( V_47 , V_63 ) >> V_65 ;
V_26 = F_38 ( V_2 -> V_3 . V_64 ) ;
if ( V_26 )
goto V_55;
V_26 = - V_27 ;
V_2 -> V_66 = F_15 ( V_2 -> V_56 *
sizeof( struct V_62 ) ) ;
if ( ! V_2 -> V_66 )
goto V_55;
for ( V_15 = 0 ; V_15 < V_2 -> V_56 ; V_15 ++ ) {
F_39 ( & V_2 -> V_66 [ V_15 ] . V_67 , V_15 ) ;
F_40 ( & V_2 -> V_66 [ V_15 ] . V_68 ) ;
}
if ( V_46 ) {
V_26 = F_13 ( V_2 ) ;
if ( V_26 )
goto V_69;
if ( ! V_44 && ! V_23 ) {
V_26 = F_26 ( V_2 ) ;
if ( V_26 )
goto V_70;
}
}
return & V_2 -> V_3 ;
V_70:
F_23 ( V_2 ) ;
V_69:
F_9 ( V_2 -> V_66 ) ;
V_55:
F_41 ( V_2 ) ;
return F_33 ( V_26 ) ;
}
static inline T_1 F_42 ( const void * V_14 , T_1 V_71 )
{
return F_43 ( V_14 , V_71 , 0 ) ;
}
static inline struct V_62 * F_44 ( struct V_1 * V_2 , T_1 V_20 )
{
return & V_2 -> V_66 [ V_20 & ( V_2 -> V_56 - 1 ) ] ;
}
static inline struct V_72 * F_45 ( struct V_1 * V_2 , T_1 V_20 )
{
return & F_44 ( V_2 , V_20 ) -> V_67 ;
}
static struct V_10 * F_46 ( struct V_72 * V_67 , T_1 V_20 ,
void * V_14 , T_1 V_12 )
{
struct V_73 * V_74 ;
struct V_10 * V_11 ;
F_47 (l, n, head, hash_node)
if ( V_11 -> V_20 == V_20 && ! memcmp ( & V_11 -> V_14 , V_14 , V_12 ) )
return V_11 ;
return NULL ;
}
static struct V_10 * F_48 ( struct V_72 * V_67 ,
T_1 V_20 , void * V_14 ,
T_1 V_12 , T_1 V_56 )
{
struct V_73 * V_74 ;
struct V_10 * V_11 ;
V_75:
F_47 (l, n, head, hash_node)
if ( V_11 -> V_20 == V_20 && ! memcmp ( & V_11 -> V_14 , V_14 , V_12 ) )
return V_11 ;
if ( F_49 ( F_50 ( V_74 ) != ( V_20 & ( V_56 - 1 ) ) ) )
goto V_75;
return NULL ;
}
static void * F_51 ( struct V_41 * V_3 , void * V_14 )
{
struct V_1 * V_2 = F_12 ( V_3 , struct V_1 , V_3 ) ;
struct V_72 * V_67 ;
struct V_10 * V_11 ;
T_1 V_20 , V_12 ;
F_52 ( ! F_53 () ) ;
V_12 = V_3 -> V_12 ;
V_20 = F_42 ( V_14 , V_12 ) ;
V_67 = F_45 ( V_2 , V_20 ) ;
V_11 = F_48 ( V_67 , V_20 , V_14 , V_12 , V_2 -> V_56 ) ;
return V_11 ;
}
static void * F_54 ( struct V_41 * V_3 , void * V_14 )
{
struct V_10 * V_11 = F_51 ( V_3 , V_14 ) ;
if ( V_11 )
return V_11 -> V_14 + F_16 ( V_3 -> V_12 , 8 ) ;
return NULL ;
}
static void * F_55 ( struct V_41 * V_3 , void * V_14 )
{
struct V_10 * V_11 = F_51 ( V_3 , V_14 ) ;
if ( V_11 ) {
F_56 ( & V_11 -> V_24 ) ;
return V_11 -> V_14 + F_16 ( V_3 -> V_12 , 8 ) ;
}
return NULL ;
}
static bool V_34 ( void * V_76 , struct V_21 * V_22 )
{
struct V_1 * V_2 = (struct V_1 * ) V_76 ;
struct V_10 * V_11 = NULL , * V_77 ;
struct V_72 * V_67 ;
struct V_73 * V_74 ;
unsigned long V_78 ;
struct V_62 * V_79 ;
V_77 = F_12 ( V_22 , struct V_10 , V_24 ) ;
V_79 = F_44 ( V_2 , V_77 -> V_20 ) ;
V_67 = & V_79 -> V_67 ;
F_57 ( & V_79 -> V_68 , V_78 ) ;
F_47 (l, n, head, hash_node)
if ( V_11 == V_77 ) {
F_58 ( & V_11 -> V_48 ) ;
break;
}
F_59 ( & V_79 -> V_68 , V_78 ) ;
return V_11 == V_77 ;
}
static int F_60 ( struct V_41 * V_3 , void * V_14 , void * V_80 )
{
struct V_1 * V_2 = F_12 ( V_3 , struct V_1 , V_3 ) ;
struct V_72 * V_67 ;
struct V_10 * V_11 , * V_81 ;
T_1 V_20 , V_12 ;
int V_15 ;
F_52 ( ! F_53 () ) ;
V_12 = V_3 -> V_12 ;
V_20 = F_42 ( V_14 , V_12 ) ;
V_67 = F_45 ( V_2 , V_20 ) ;
V_11 = F_48 ( V_67 , V_20 , V_14 , V_12 , V_2 -> V_56 ) ;
if ( ! V_11 ) {
V_15 = 0 ;
goto V_82;
}
V_81 = F_61 ( F_62 ( F_63 ( & V_11 -> V_48 ) ) ,
struct V_10 , V_48 ) ;
if ( V_81 ) {
memcpy ( V_80 , V_81 -> V_14 , V_12 ) ;
return 0 ;
}
V_15 = V_20 & ( V_2 -> V_56 - 1 ) ;
V_15 ++ ;
V_82:
for (; V_15 < V_2 -> V_56 ; V_15 ++ ) {
V_67 = F_45 ( V_2 , V_15 ) ;
V_81 = F_61 ( F_62 ( F_64 ( V_67 ) ) ,
struct V_10 , V_48 ) ;
if ( V_81 ) {
memcpy ( V_80 , V_81 -> V_14 , V_12 ) ;
return 0 ;
}
}
return - V_83 ;
}
static void F_65 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
if ( V_2 -> V_3 . V_4 == V_7 )
F_8 ( F_5 ( V_11 , V_2 -> V_3 . V_12 ) ) ;
F_41 ( V_11 ) ;
}
static void F_66 ( struct V_84 * V_67 )
{
struct V_10 * V_11 = F_12 ( V_67 , struct V_10 , V_85 ) ;
struct V_1 * V_2 = V_11 -> V_2 ;
F_67 () ;
F_68 ( V_86 ) ;
F_65 ( V_2 , V_11 ) ;
F_69 ( V_86 ) ;
F_70 () ;
}
static void F_71 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
if ( F_3 ( V_2 ) ) {
F_72 ( & V_2 -> V_35 , & V_11 -> V_36 ) ;
} else {
F_73 ( & V_2 -> V_87 ) ;
V_11 -> V_2 = V_2 ;
F_74 ( & V_11 -> V_85 , F_66 ) ;
}
}
static void F_75 ( struct V_1 * V_2 , void T_2 * V_13 ,
void * V_88 , bool V_89 )
{
if ( ! V_89 ) {
memcpy ( F_76 ( V_13 ) , V_88 , V_2 -> V_3 . V_30 ) ;
} else {
T_1 V_29 = F_16 ( V_2 -> V_3 . V_30 , 8 ) ;
int V_90 = 0 , V_39 ;
F_27 (cpu) {
F_77 ( F_29 ( V_13 , V_39 ) ,
V_88 + V_90 , V_29 ) ;
V_90 += V_29 ;
}
}
}
static struct V_10 * F_78 ( struct V_1 * V_2 , void * V_14 ,
void * V_88 , T_1 V_12 , T_1 V_20 ,
bool V_44 , bool V_89 ,
struct V_10 * V_91 )
{
T_1 V_29 = V_2 -> V_3 . V_30 ;
bool V_46 = F_3 ( V_2 ) ;
struct V_10 * V_37 , * * V_92 ;
void T_2 * V_13 ;
if ( V_46 ) {
if ( V_91 ) {
V_92 = F_76 ( V_2 -> V_40 ) ;
V_37 = * V_92 ;
* V_92 = V_91 ;
} else {
struct V_38 * V_11 ;
V_11 = F_28 ( & V_2 -> V_35 ) ;
if ( ! V_11 )
return F_33 ( - V_57 ) ;
V_37 = F_12 ( V_11 , struct V_10 , V_36 ) ;
}
} else {
if ( F_79 ( & V_2 -> V_87 ) > V_2 -> V_3 . V_19 )
if ( ! V_91 ) {
F_73 ( & V_2 -> V_87 ) ;
return F_33 ( - V_57 ) ;
}
V_37 = F_80 ( V_2 -> V_17 , V_93 | V_32 ) ;
if ( ! V_37 )
return F_33 ( - V_27 ) ;
}
memcpy ( V_37 -> V_14 , V_14 , V_12 ) ;
if ( V_44 ) {
V_29 = F_16 ( V_29 , 8 ) ;
if ( V_46 ) {
V_13 = F_5 ( V_37 , V_12 ) ;
} else {
V_13 = F_17 ( V_29 , 8 ,
V_93 | V_32 ) ;
if ( ! V_13 ) {
F_41 ( V_37 ) ;
return F_33 ( - V_27 ) ;
}
}
F_75 ( V_2 , V_13 , V_88 , V_89 ) ;
if ( ! V_46 )
F_4 ( V_37 , V_12 , V_13 ) ;
} else {
memcpy ( V_37 -> V_14 + F_16 ( V_12 , 8 ) , V_88 , V_29 ) ;
}
V_37 -> V_20 = V_20 ;
return V_37 ;
}
static int F_81 ( struct V_1 * V_2 , struct V_10 * V_94 ,
T_3 V_8 )
{
if ( V_94 && V_8 == V_95 )
return - V_96 ;
if ( ! V_94 && V_8 == V_97 )
return - V_83 ;
return 0 ;
}
static int F_82 ( struct V_41 * V_3 , void * V_14 , void * V_88 ,
T_3 V_8 )
{
struct V_1 * V_2 = F_12 ( V_3 , struct V_1 , V_3 ) ;
struct V_10 * V_37 = NULL , * V_94 ;
struct V_72 * V_67 ;
unsigned long V_78 ;
struct V_62 * V_79 ;
T_1 V_12 , V_20 ;
int V_98 ;
if ( F_49 ( V_8 > V_97 ) )
return - V_53 ;
F_52 ( ! F_53 () ) ;
V_12 = V_3 -> V_12 ;
V_20 = F_42 ( V_14 , V_12 ) ;
V_79 = F_44 ( V_2 , V_20 ) ;
V_67 = & V_79 -> V_67 ;
F_57 ( & V_79 -> V_68 , V_78 ) ;
V_94 = F_46 ( V_67 , V_20 , V_14 , V_12 ) ;
V_98 = F_81 ( V_2 , V_94 , V_8 ) ;
if ( V_98 )
goto V_26;
V_37 = F_78 ( V_2 , V_14 , V_88 , V_12 , V_20 , false , false ,
V_94 ) ;
if ( F_83 ( V_37 ) ) {
V_98 = F_84 ( V_37 ) ;
goto V_26;
}
F_85 ( & V_37 -> V_48 , V_67 ) ;
if ( V_94 ) {
F_58 ( & V_94 -> V_48 ) ;
if ( ! F_3 ( V_2 ) )
F_71 ( V_2 , V_94 ) ;
}
V_98 = 0 ;
V_26:
F_59 ( & V_79 -> V_68 , V_78 ) ;
return V_98 ;
}
static int F_86 ( struct V_41 * V_3 , void * V_14 , void * V_88 ,
T_3 V_8 )
{
struct V_1 * V_2 = F_12 ( V_3 , struct V_1 , V_3 ) ;
struct V_10 * V_37 , * V_94 = NULL ;
struct V_72 * V_67 ;
unsigned long V_78 ;
struct V_62 * V_79 ;
T_1 V_12 , V_20 ;
int V_98 ;
if ( F_49 ( V_8 > V_97 ) )
return - V_53 ;
F_52 ( ! F_53 () ) ;
V_12 = V_3 -> V_12 ;
V_20 = F_42 ( V_14 , V_12 ) ;
V_79 = F_44 ( V_2 , V_20 ) ;
V_67 = & V_79 -> V_67 ;
V_37 = F_10 ( V_2 , V_14 , V_20 ) ;
if ( ! V_37 )
return - V_27 ;
memcpy ( V_37 -> V_14 + F_16 ( V_3 -> V_12 , 8 ) , V_88 , V_3 -> V_30 ) ;
F_57 ( & V_79 -> V_68 , V_78 ) ;
V_94 = F_46 ( V_67 , V_20 , V_14 , V_12 ) ;
V_98 = F_81 ( V_2 , V_94 , V_8 ) ;
if ( V_98 )
goto V_26;
F_85 ( & V_37 -> V_48 , V_67 ) ;
if ( V_94 ) {
F_56 ( & V_37 -> V_24 ) ;
F_58 ( & V_94 -> V_48 ) ;
}
V_98 = 0 ;
V_26:
F_59 ( & V_79 -> V_68 , V_78 ) ;
if ( V_98 )
F_87 ( & V_2 -> V_23 , & V_37 -> V_24 ) ;
else if ( V_94 )
F_87 ( & V_2 -> V_23 , & V_94 -> V_24 ) ;
return V_98 ;
}
static int F_88 ( struct V_41 * V_3 , void * V_14 ,
void * V_88 , T_3 V_8 ,
bool V_89 )
{
struct V_1 * V_2 = F_12 ( V_3 , struct V_1 , V_3 ) ;
struct V_10 * V_37 = NULL , * V_94 ;
struct V_72 * V_67 ;
unsigned long V_78 ;
struct V_62 * V_79 ;
T_1 V_12 , V_20 ;
int V_98 ;
if ( F_49 ( V_8 > V_97 ) )
return - V_53 ;
F_52 ( ! F_53 () ) ;
V_12 = V_3 -> V_12 ;
V_20 = F_42 ( V_14 , V_12 ) ;
V_79 = F_44 ( V_2 , V_20 ) ;
V_67 = & V_79 -> V_67 ;
F_57 ( & V_79 -> V_68 , V_78 ) ;
V_94 = F_46 ( V_67 , V_20 , V_14 , V_12 ) ;
V_98 = F_81 ( V_2 , V_94 , V_8 ) ;
if ( V_98 )
goto V_26;
if ( V_94 ) {
F_75 ( V_2 , F_5 ( V_94 , V_12 ) ,
V_88 , V_89 ) ;
} else {
V_37 = F_78 ( V_2 , V_14 , V_88 , V_12 ,
V_20 , true , V_89 , NULL ) ;
if ( F_83 ( V_37 ) ) {
V_98 = F_84 ( V_37 ) ;
goto V_26;
}
F_85 ( & V_37 -> V_48 , V_67 ) ;
}
V_98 = 0 ;
V_26:
F_59 ( & V_79 -> V_68 , V_78 ) ;
return V_98 ;
}
static int F_89 ( struct V_41 * V_3 , void * V_14 ,
void * V_88 , T_3 V_8 ,
bool V_89 )
{
struct V_1 * V_2 = F_12 ( V_3 , struct V_1 , V_3 ) ;
struct V_10 * V_37 = NULL , * V_94 ;
struct V_72 * V_67 ;
unsigned long V_78 ;
struct V_62 * V_79 ;
T_1 V_12 , V_20 ;
int V_98 ;
if ( F_49 ( V_8 > V_97 ) )
return - V_53 ;
F_52 ( ! F_53 () ) ;
V_12 = V_3 -> V_12 ;
V_20 = F_42 ( V_14 , V_12 ) ;
V_79 = F_44 ( V_2 , V_20 ) ;
V_67 = & V_79 -> V_67 ;
if ( V_8 != V_97 ) {
V_37 = F_10 ( V_2 , V_14 , V_20 ) ;
if ( ! V_37 )
return - V_27 ;
}
F_57 ( & V_79 -> V_68 , V_78 ) ;
V_94 = F_46 ( V_67 , V_20 , V_14 , V_12 ) ;
V_98 = F_81 ( V_2 , V_94 , V_8 ) ;
if ( V_98 )
goto V_26;
if ( V_94 ) {
F_56 ( & V_94 -> V_24 ) ;
F_75 ( V_2 , F_5 ( V_94 , V_12 ) ,
V_88 , V_89 ) ;
} else {
F_75 ( V_2 , F_5 ( V_37 , V_12 ) ,
V_88 , V_89 ) ;
F_85 ( & V_37 -> V_48 , V_67 ) ;
V_37 = NULL ;
}
V_98 = 0 ;
V_26:
F_59 ( & V_79 -> V_68 , V_78 ) ;
if ( V_37 )
F_87 ( & V_2 -> V_23 , & V_37 -> V_24 ) ;
return V_98 ;
}
static int F_90 ( struct V_41 * V_3 , void * V_14 ,
void * V_88 , T_3 V_8 )
{
return F_88 ( V_3 , V_14 , V_88 , V_8 , false ) ;
}
static int F_91 ( struct V_41 * V_3 , void * V_14 ,
void * V_88 , T_3 V_8 )
{
return F_89 ( V_3 , V_14 , V_88 , V_8 ,
false ) ;
}
static int F_92 ( struct V_41 * V_3 , void * V_14 )
{
struct V_1 * V_2 = F_12 ( V_3 , struct V_1 , V_3 ) ;
struct V_72 * V_67 ;
struct V_62 * V_79 ;
struct V_10 * V_11 ;
unsigned long V_78 ;
T_1 V_20 , V_12 ;
int V_98 = - V_83 ;
F_52 ( ! F_53 () ) ;
V_12 = V_3 -> V_12 ;
V_20 = F_42 ( V_14 , V_12 ) ;
V_79 = F_44 ( V_2 , V_20 ) ;
V_67 = & V_79 -> V_67 ;
F_57 ( & V_79 -> V_68 , V_78 ) ;
V_11 = F_46 ( V_67 , V_20 , V_14 , V_12 ) ;
if ( V_11 ) {
F_58 ( & V_11 -> V_48 ) ;
F_71 ( V_2 , V_11 ) ;
V_98 = 0 ;
}
F_59 ( & V_79 -> V_68 , V_78 ) ;
return V_98 ;
}
static int F_93 ( struct V_41 * V_3 , void * V_14 )
{
struct V_1 * V_2 = F_12 ( V_3 , struct V_1 , V_3 ) ;
struct V_72 * V_67 ;
struct V_62 * V_79 ;
struct V_10 * V_11 ;
unsigned long V_78 ;
T_1 V_20 , V_12 ;
int V_98 = - V_83 ;
F_52 ( ! F_53 () ) ;
V_12 = V_3 -> V_12 ;
V_20 = F_42 ( V_14 , V_12 ) ;
V_79 = F_44 ( V_2 , V_20 ) ;
V_67 = & V_79 -> V_67 ;
F_57 ( & V_79 -> V_68 , V_78 ) ;
V_11 = F_46 ( V_67 , V_20 , V_14 , V_12 ) ;
if ( V_11 ) {
F_58 ( & V_11 -> V_48 ) ;
V_98 = 0 ;
}
F_59 ( & V_79 -> V_68 , V_78 ) ;
if ( V_11 )
F_87 ( & V_2 -> V_23 , & V_11 -> V_24 ) ;
return V_98 ;
}
static void F_94 ( struct V_1 * V_2 )
{
int V_15 ;
for ( V_15 = 0 ; V_15 < V_2 -> V_56 ; V_15 ++ ) {
struct V_72 * V_67 = F_45 ( V_2 , V_15 ) ;
struct V_73 * V_74 ;
struct V_10 * V_11 ;
F_95 (l, n, head, hash_node) {
F_58 ( & V_11 -> V_48 ) ;
F_65 ( V_2 , V_11 ) ;
}
}
}
static void F_96 ( struct V_41 * V_3 )
{
struct V_1 * V_2 = F_12 ( V_3 , struct V_1 , V_3 ) ;
F_97 () ;
F_98 () ;
if ( ! F_3 ( V_2 ) )
F_94 ( V_2 ) ;
else
F_23 ( V_2 ) ;
F_8 ( V_2 -> V_40 ) ;
F_9 ( V_2 -> V_66 ) ;
F_41 ( V_2 ) ;
}
static void * F_99 ( struct V_41 * V_3 , void * V_14 )
{
struct V_10 * V_11 = F_51 ( V_3 , V_14 ) ;
if ( V_11 )
return F_76 ( F_5 ( V_11 , V_3 -> V_12 ) ) ;
else
return NULL ;
}
static void * F_100 ( struct V_41 * V_3 , void * V_14 )
{
struct V_10 * V_11 = F_51 ( V_3 , V_14 ) ;
if ( V_11 ) {
F_56 ( & V_11 -> V_24 ) ;
return F_76 ( F_5 ( V_11 , V_3 -> V_12 ) ) ;
}
return NULL ;
}
int F_101 ( struct V_41 * V_3 , void * V_14 , void * V_88 )
{
struct V_1 * V_2 = F_12 ( V_3 , struct V_1 , V_3 ) ;
struct V_10 * V_11 ;
void T_2 * V_13 ;
int V_98 = - V_83 ;
int V_39 , V_90 = 0 ;
T_1 V_29 ;
V_29 = F_16 ( V_3 -> V_30 , 8 ) ;
F_102 () ;
V_11 = F_51 ( V_3 , V_14 ) ;
if ( ! V_11 )
goto V_99;
if ( F_1 ( V_2 ) )
F_56 ( & V_11 -> V_24 ) ;
V_13 = F_5 ( V_11 , V_3 -> V_12 ) ;
F_27 (cpu) {
F_77 ( V_88 + V_90 ,
F_29 ( V_13 , V_39 ) , V_29 ) ;
V_90 += V_29 ;
}
V_98 = 0 ;
V_99:
F_103 () ;
return V_98 ;
}
int F_104 ( struct V_41 * V_3 , void * V_14 , void * V_88 ,
T_3 V_8 )
{
struct V_1 * V_2 = F_12 ( V_3 , struct V_1 , V_3 ) ;
int V_98 ;
F_102 () ;
if ( F_1 ( V_2 ) )
V_98 = F_89 ( V_3 , V_14 , V_88 ,
V_8 , true ) ;
else
V_98 = F_88 ( V_3 , V_14 , V_88 , V_8 ,
true ) ;
F_103 () ;
return V_98 ;
}
static int T_4 F_105 ( void )
{
F_106 ( & V_100 ) ;
F_106 ( & V_101 ) ;
F_106 ( & V_102 ) ;
F_106 ( & V_103 ) ;
return 0 ;
}
