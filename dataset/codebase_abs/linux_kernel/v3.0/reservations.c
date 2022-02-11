int F_1 ( struct V_1 * V_2 )
{
return ( V_2 -> V_3 && V_2 -> V_4 ) ;
}
static unsigned int F_2 ( struct V_5 * V_6 ,
struct V_7 * V_8 )
{
struct V_1 * V_2 = V_6 -> V_9 ;
unsigned int V_10 ;
if ( ! ( V_8 -> V_11 & V_12 ) ) {
V_10 = 4 << V_2 -> V_3 ;
} else {
V_10 = 4 << V_2 -> V_4 ;
}
return V_10 ;
}
static inline unsigned int F_3 ( struct V_7 * V_8 )
{
if ( V_8 -> V_13 )
return V_8 -> V_14 + V_8 -> V_13 - 1 ;
return V_8 -> V_14 ;
}
static inline int F_4 ( struct V_7 * V_8 )
{
return ! ! ( V_8 -> V_13 == 0 ) ;
}
static inline int F_5 ( struct V_5 * V_6 )
{
if ( V_6 -> V_9 -> V_3 == 0 )
return 1 ;
return 0 ;
}
static void F_6 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_9 ;
struct V_15 * V_16 ;
struct V_7 * V_8 ;
int V_17 = 0 ;
F_7 ( V_18 , L_1 ,
V_2 -> V_19 , V_6 -> V_20 ) ;
V_16 = F_8 ( & V_6 -> V_21 ) ;
while ( V_16 ) {
V_8 = F_9 ( V_16 , struct V_7 , V_22 ) ;
F_7 ( V_18 , L_2
L_3 , V_8 -> V_14 ,
F_3 ( V_8 ) , V_8 -> V_13 , V_8 -> V_23 ,
V_8 -> V_24 ) ;
V_16 = F_10 ( V_16 ) ;
V_17 ++ ;
}
F_7 ( V_18 , L_4 , V_17 ) ;
V_17 = 0 ;
F_11 (resv, &resmap->m_lru, r_lru) {
F_7 ( V_18 , L_5
L_6 , V_17 , V_8 -> V_14 ,
F_3 ( V_8 ) , V_8 -> V_13 , V_8 -> V_23 ,
V_8 -> V_24 ) ;
V_17 ++ ;
}
}
static int F_12 ( struct V_5 * V_6 ,
int V_17 ,
struct V_7 * V_8 )
{
char * V_25 = V_6 -> V_26 ;
unsigned int V_27 = V_8 -> V_14 ;
unsigned int V_28 = F_3 ( V_8 ) ;
while ( V_27 <= V_28 ) {
if ( F_13 ( V_27 , V_25 ) ) {
F_7 ( V_29 ,
L_7
L_8 , V_17 , V_27 ) ;
return 1 ;
}
V_27 ++ ;
}
return 0 ;
}
static void F_14 ( struct V_5 * V_6 )
{
unsigned int V_30 = 0 ;
int V_17 = 0 ;
struct V_15 * V_16 ;
struct V_7 * V_8 ;
V_16 = F_8 ( & V_6 -> V_21 ) ;
while ( V_16 ) {
V_8 = F_9 ( V_16 , struct V_7 , V_22 ) ;
if ( V_17 > 0 && V_8 -> V_14 <= V_30 ) {
F_7 ( V_29 , L_9 ,
V_17 ) ;
goto V_31;
}
if ( V_8 -> V_13 == 0 ) {
F_7 ( V_29 , L_10 ,
V_17 ) ;
goto V_31;
}
if ( V_8 -> V_14 > F_3 ( V_8 ) ) {
F_7 ( V_29 , L_11 ,
V_17 ) ;
goto V_31;
}
if ( F_3 ( V_8 ) >= V_6 -> V_20 ) {
F_7 ( V_29 , L_12 ,
V_17 ) ;
goto V_31;
}
if ( F_12 ( V_6 , V_17 , V_8 ) )
goto V_31;
V_30 = F_3 ( V_8 ) ;
V_16 = F_10 ( V_16 ) ;
V_17 ++ ;
}
return;
V_31:
F_6 ( V_6 ) ;
F_15 () ;
}
static inline void F_14 ( struct V_5 * V_6 )
{
}
void F_16 ( struct V_7 * V_8 )
{
memset ( V_8 , 0 , sizeof( * V_8 ) ) ;
F_17 ( & V_8 -> V_32 ) ;
}
void F_18 ( struct V_7 * V_8 ,
unsigned int V_33 )
{
F_19 ( V_33 & ~ V_34 ) ;
V_8 -> V_11 |= V_33 ;
}
int F_20 ( struct V_1 * V_2 ,
struct V_5 * V_6 )
{
memset ( V_6 , 0 , sizeof( * V_6 ) ) ;
V_6 -> V_9 = V_2 ;
V_6 -> V_21 = V_35 ;
F_17 ( & V_6 -> V_36 ) ;
return 0 ;
}
static void F_21 ( struct V_5 * V_6 ,
struct V_7 * V_8 )
{
F_22 ( & V_37 ) ;
if ( ! F_23 ( & V_8 -> V_32 ) )
F_24 ( & V_8 -> V_32 ) ;
F_25 ( & V_8 -> V_32 , & V_6 -> V_36 ) ;
}
static void F_26 ( struct V_7 * V_8 )
{
V_8 -> V_13 = 0 ;
V_8 -> V_14 = 0 ;
}
static void F_27 ( struct V_5 * V_6 ,
struct V_7 * V_8 )
{
if ( V_8 -> V_11 & V_38 ) {
F_24 ( & V_8 -> V_32 ) ;
F_28 ( & V_8 -> V_22 , & V_6 -> V_21 ) ;
V_8 -> V_11 &= ~ V_38 ;
}
}
static void F_29 ( struct V_5 * V_6 ,
struct V_7 * V_8 )
{
F_22 ( & V_37 ) ;
F_26 ( V_8 ) ;
V_8 -> V_24 = V_8 -> V_23 = 0 ;
F_27 ( V_6 , V_8 ) ;
}
void F_30 ( struct V_5 * V_6 ,
struct V_7 * V_8 )
{
if ( V_8 ) {
F_31 ( & V_37 ) ;
F_29 ( V_6 , V_8 ) ;
F_32 ( & V_37 ) ;
}
}
static void F_33 ( struct V_5 * V_6 )
{
struct V_15 * V_16 ;
struct V_7 * V_8 ;
F_22 ( & V_37 ) ;
while ( ( V_16 = F_34 ( & V_6 -> V_21 ) ) != NULL ) {
V_8 = F_9 ( V_16 , struct V_7 , V_22 ) ;
F_29 ( V_6 , V_8 ) ;
}
}
void F_35 ( struct V_5 * V_6 ,
unsigned int V_39 , char * V_25 )
{
if ( F_5 ( V_6 ) )
return;
F_31 ( & V_37 ) ;
F_33 ( V_6 ) ;
V_6 -> V_20 = V_39 ;
V_6 -> V_26 = V_25 ;
F_32 ( & V_37 ) ;
}
void F_36 ( struct V_5 * V_6 )
{
}
static void F_37 ( struct V_5 * V_6 ,
struct V_7 * V_40 )
{
struct V_41 * V_42 = & V_6 -> V_21 ;
struct V_15 * V_43 = NULL ;
struct V_15 * * V_44 = & V_42 -> V_15 ;
struct V_7 * V_45 ;
F_22 ( & V_37 ) ;
F_38 ( V_40 -> V_14 , V_40 -> V_13 ) ;
while ( * V_44 ) {
V_43 = * V_44 ;
V_45 = F_9 ( V_43 , struct V_7 , V_22 ) ;
if ( V_40 -> V_14 < V_45 -> V_14 ) {
V_44 = & ( * V_44 ) -> V_46 ;
F_19 ( F_3 ( V_40 ) >= V_45 -> V_14 ) ;
} else if ( V_40 -> V_14 > F_3 ( V_45 ) ) {
V_44 = & ( * V_44 ) -> V_47 ;
} else {
F_7 ( V_29 , L_13 ) ;
F_15 () ;
}
}
F_39 ( & V_40 -> V_22 , V_43 , V_44 ) ;
F_40 ( & V_40 -> V_22 , V_42 ) ;
V_40 -> V_11 |= V_38 ;
F_21 ( V_6 , V_40 ) ;
F_14 ( V_6 ) ;
}
static struct V_7 *
F_41 ( struct V_5 * V_6 , unsigned int V_48 )
{
struct V_7 * V_8 = NULL ;
struct V_7 * V_49 = NULL ;
struct V_15 * V_16 = V_6 -> V_21 . V_15 ;
F_22 ( & V_37 ) ;
if ( ! V_16 )
return NULL ;
V_16 = F_8 ( & V_6 -> V_21 ) ;
while ( V_16 ) {
V_8 = F_9 ( V_16 , struct V_7 , V_22 ) ;
if ( V_8 -> V_14 <= V_48 && F_3 ( V_8 ) >= V_48 )
break;
if ( V_8 -> V_14 > V_48 ) {
V_8 = V_49 ;
break;
}
V_49 = V_8 ;
V_16 = F_10 ( V_16 ) ;
}
return V_8 ;
}
static int F_42 ( struct V_5 * V_6 ,
unsigned int V_50 ,
unsigned int V_51 ,
unsigned int V_52 ,
unsigned int * V_53 ,
unsigned int * V_54 )
{
void * V_55 = V_6 -> V_26 ;
unsigned int V_56 , V_57 = 0 ;
int V_58 , V_27 , V_59 ;
F_43 ( V_51 , V_52 ,
V_50 , V_6 -> V_20 ) ;
V_59 = V_56 = V_57 = 0 ;
V_27 = V_51 ;
while ( ( V_58 = F_44 ( V_55 , V_6 -> V_20 ,
V_27 ) ) != - 1 ) {
if ( V_58 >= ( V_51 + V_52 ) )
break;
if ( V_58 == V_27 ) {
V_59 ++ ;
V_27 ++ ;
} else {
V_59 = 1 ;
V_27 = V_58 + 1 ;
}
if ( V_59 > V_57 ) {
V_57 = V_59 ;
V_56 = V_27 - V_59 ;
}
if ( V_59 >= V_50 )
break;
}
if ( V_57 == 0 )
return 0 ;
if ( V_57 >= V_50 )
V_57 = V_50 ;
* V_54 = V_57 ;
* V_53 = V_56 ;
F_45 ( V_56 , V_57 ) ;
return * V_54 ;
}
static void F_46 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
unsigned int V_48 , unsigned int V_50 )
{
struct V_41 * V_42 = & V_6 -> V_21 ;
unsigned int V_60 , V_61 , V_62 ;
struct V_7 * V_49 , * V_63 ;
struct V_15 * V_64 , * V_65 ;
unsigned int V_66 , V_39 ;
unsigned int V_56 = 0 , V_57 = 0 ;
F_47 ( V_8 -> V_14 , F_3 ( V_8 ) ,
V_48 , V_50 , F_48 ( V_42 ) ) ;
F_22 ( & V_37 ) ;
if ( F_48 ( V_42 ) ) {
V_39 = F_42 ( V_6 , V_50 , V_48 ,
V_6 -> V_20 - V_48 ,
& V_66 , & V_39 ) ;
F_19 ( V_48 == 0 && V_39 == 0 ) ;
if ( V_39 == 0 )
return;
V_8 -> V_14 = V_66 ;
V_8 -> V_13 = V_39 ;
F_37 ( V_6 , V_8 ) ;
return;
}
V_49 = F_41 ( V_6 , V_48 ) ;
if ( V_49 == NULL ) {
V_65 = F_8 ( V_42 ) ;
V_63 = F_9 ( V_65 , struct V_7 ,
V_22 ) ;
if ( V_63 -> V_14 <= V_48 ) {
F_7 ( V_29 , L_14 ,
V_48 , V_63 -> V_14 , V_63 -> V_13 ) ;
F_6 ( V_6 ) ;
F_15 () ;
}
V_39 = F_42 ( V_6 , V_50 , V_48 ,
V_63 -> V_14 - V_48 ,
& V_66 , & V_39 ) ;
if ( V_39 ) {
V_57 = V_39 ;
V_56 = V_66 ;
if ( V_57 == V_50 )
goto V_67;
}
V_49 = V_63 ;
V_63 = NULL ;
}
F_49 ( V_49 -> V_14 ,
F_3 ( V_49 ) ) ;
V_64 = & V_49 -> V_22 ;
while ( 1 ) {
V_65 = F_10 ( V_64 ) ;
if ( V_65 ) {
V_63 = F_9 ( V_65 ,
struct V_7 ,
V_22 ) ;
V_60 = F_3 ( V_49 ) + 1 ;
V_61 = V_63 -> V_14 - 1 ;
V_62 = V_61 - V_60 + 1 ;
} else {
V_60 = F_3 ( V_49 ) + 1 ;
V_62 = V_6 -> V_20 - V_60 ;
V_61 = V_6 -> V_20 - 1 ;
}
F_50 ( V_65 ? V_63 -> V_14 : - 1 ,
V_65 ? F_3 ( V_63 ) : - 1 ) ;
if ( V_62 <= V_57 )
goto V_63;
V_39 = F_42 ( V_6 , V_50 , V_60 ,
V_62 , & V_66 , & V_39 ) ;
if ( V_39 == V_50 ) {
V_57 = V_39 ;
V_56 = V_66 ;
goto V_67;
} else if ( V_39 > V_57 ) {
V_57 = V_39 ;
V_56 = V_66 ;
}
V_63:
if ( ! V_65 )
break;
V_64 = V_65 ;
V_49 = F_9 ( V_64 , struct V_7 ,
V_22 ) ;
}
V_67:
if ( V_57 ) {
V_8 -> V_14 = V_56 ;
V_8 -> V_13 = V_57 ;
F_37 ( V_6 , V_8 ) ;
}
}
static void F_51 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
unsigned int V_50 )
{
struct V_7 * V_68 ;
int V_69 = ! ! ( V_8 -> V_11 & V_70 ) ;
unsigned int V_71 ;
if ( ! V_69 )
V_71 = F_2 ( V_6 , V_8 ) >> 1 ;
else
V_71 = V_50 ;
V_68 = F_52 ( & V_6 -> V_36 ,
struct V_7 , V_32 ) ;
F_53 ( V_68 -> V_14 ,
V_68 -> V_13 ,
F_3 ( V_68 ) ) ;
if ( V_68 -> V_13 <= V_71 ) {
V_8 -> V_14 = V_68 -> V_14 ;
V_8 -> V_13 = V_68 -> V_13 ;
F_29 ( V_6 , V_68 ) ;
} else {
unsigned int V_72 ;
if ( V_69 )
V_72 = V_71 ;
else
V_72 = V_68 -> V_13 / 2 ;
V_68 -> V_13 -= V_72 ;
V_8 -> V_14 = F_3 ( V_68 ) + 1 ;
V_8 -> V_13 = V_72 ;
}
F_54 ( V_8 -> V_14 , F_3 ( V_8 ) ,
V_8 -> V_13 , V_8 -> V_23 ,
V_8 -> V_24 ) ;
F_37 ( V_6 , V_8 ) ;
}
static void F_55 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
unsigned int V_50 )
{
unsigned int V_48 = 0 ;
F_19 ( ! F_4 ( V_8 ) ) ;
if ( V_8 -> V_24 ) {
V_48 = V_8 -> V_23 + V_8 -> V_24 ;
if ( V_48 >= V_6 -> V_20 )
V_48 = 0 ;
}
F_46 ( V_6 , V_8 , V_48 , V_50 ) ;
if ( F_4 ( V_8 ) && V_48 != 0 )
F_46 ( V_6 , V_8 , 0 , V_50 ) ;
if ( F_4 ( V_8 ) ) {
F_51 ( V_6 , V_8 , V_50 ) ;
}
F_19 ( F_4 ( V_8 ) ) ;
}
int F_56 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
int * V_66 , int * V_39 )
{
if ( V_8 == NULL || F_5 ( V_6 ) )
return - V_73 ;
F_31 ( & V_37 ) ;
if ( F_4 ( V_8 ) ) {
unsigned int V_50 = F_2 ( V_6 , V_8 ) ;
if ( ( V_8 -> V_11 & V_70 ) || V_50 < * V_39 )
V_50 = * V_39 ;
F_55 ( V_6 , V_8 , V_50 ) ;
F_57 ( V_8 -> V_14 , V_8 -> V_13 ) ;
}
F_19 ( F_4 ( V_8 ) ) ;
* V_66 = V_8 -> V_14 ;
* V_39 = V_8 -> V_13 ;
F_32 ( & V_37 ) ;
return 0 ;
}
static void
F_58 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
unsigned int V_27 , unsigned int V_28 )
{
unsigned int V_74 = 0 ;
unsigned int V_75 = F_3 ( V_8 ) ;
F_19 ( V_27 != V_8 -> V_14 || V_75 < V_28 ) ;
if ( V_75 == V_28 ) {
F_29 ( V_6 , V_8 ) ;
return;
}
V_74 = V_75 - V_28 ;
F_19 ( V_74 == 0 ) ;
V_8 -> V_14 = V_28 + 1 ;
V_8 -> V_13 = V_75 - V_8 -> V_14 + 1 ;
}
void F_59 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
T_1 V_66 , T_1 V_39 )
{
unsigned int V_76 = V_66 + V_39 - 1 ;
if ( V_6 == NULL || F_5 ( V_6 ) )
return;
if ( V_8 == NULL )
return;
F_19 ( V_66 != V_8 -> V_14 ) ;
F_31 ( & V_37 ) ;
F_60 ( V_66 , V_76 , V_39 , V_8 -> V_14 ,
F_3 ( V_8 ) , V_8 -> V_13 ,
V_8 -> V_23 ,
V_8 -> V_24 ) ;
F_19 ( V_66 < V_8 -> V_14 ) ;
F_19 ( V_66 > F_3 ( V_8 ) ) ;
F_19 ( V_76 > F_3 ( V_8 ) ) ;
F_58 ( V_6 , V_8 , V_66 , V_76 ) ;
V_8 -> V_23 = V_66 ;
V_8 -> V_24 = V_39 ;
if ( ! F_4 ( V_8 ) )
F_21 ( V_6 , V_8 ) ;
F_61 ( V_8 -> V_14 , F_3 ( V_8 ) ,
V_8 -> V_13 , V_8 -> V_23 ,
V_8 -> V_24 ) ;
F_14 ( V_6 ) ;
F_32 ( & V_37 ) ;
}
