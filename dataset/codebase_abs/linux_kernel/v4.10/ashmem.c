static inline unsigned long F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 - V_2 -> V_4 + 1 ;
}
static inline bool F_2 ( struct V_1 * V_2 )
{
return V_2 -> V_5 == V_6 ;
}
static inline bool F_3 ( struct V_1 * V_2 ,
T_1 V_7 , T_1 V_8 )
{
return ( V_2 -> V_4 >= V_7 ) && ( V_2 -> V_3 <= V_8 ) ;
}
static inline bool F_4 ( struct V_1 * V_2 ,
T_1 V_7 , T_1 V_8 )
{
return ( V_2 -> V_4 <= V_7 ) && ( V_2 -> V_3 >= V_8 ) ;
}
static inline bool F_5 ( struct V_1 * V_2 , T_1 V_9 )
{
return ( V_2 -> V_4 <= V_9 ) && ( V_2 -> V_3 >= V_9 ) ;
}
static inline bool F_6 ( struct V_1 * V_2 ,
T_1 V_7 , T_1 V_8 )
{
return F_5 ( V_2 , V_7 ) || F_5 ( V_2 , V_8 ) ||
F_3 ( V_2 , V_7 , V_8 ) ;
}
static inline bool F_7 ( struct V_1 * V_2 , T_1 V_9 )
{
return V_2 -> V_3 < V_9 ;
}
static inline void F_8 ( struct V_1 * V_2 )
{
F_9 ( & V_2 -> V_10 , & V_11 ) ;
V_12 += F_1 ( V_2 ) ;
}
static inline void F_10 ( struct V_1 * V_2 )
{
F_11 ( & V_2 -> V_10 ) ;
V_12 -= F_1 ( V_2 ) ;
}
static int F_12 ( struct V_13 * V_14 ,
struct V_1 * V_15 , unsigned int V_5 ,
T_1 V_7 , T_1 V_8 )
{
struct V_1 * V_2 ;
V_2 = F_13 ( V_16 , V_17 ) ;
if ( F_14 ( ! V_2 ) )
return - V_18 ;
V_2 -> V_14 = V_14 ;
V_2 -> V_4 = V_7 ;
V_2 -> V_3 = V_8 ;
V_2 -> V_5 = V_5 ;
F_9 ( & V_2 -> V_19 , & V_15 -> V_19 ) ;
if ( F_2 ( V_2 ) )
F_8 ( V_2 ) ;
return 0 ;
}
static void F_15 ( struct V_1 * V_2 )
{
F_11 ( & V_2 -> V_19 ) ;
if ( F_2 ( V_2 ) )
F_10 ( V_2 ) ;
F_16 ( V_16 , V_2 ) ;
}
static inline void F_17 ( struct V_1 * V_2 ,
T_1 V_7 , T_1 V_8 )
{
T_1 V_20 = F_1 ( V_2 ) ;
V_2 -> V_4 = V_7 ;
V_2 -> V_3 = V_8 ;
if ( F_2 ( V_2 ) )
V_12 -= V_20 - F_1 ( V_2 ) ;
}
static int F_18 ( struct V_21 * V_21 , struct V_22 * V_22 )
{
struct V_13 * V_14 ;
int V_23 ;
V_23 = F_19 ( V_21 , V_22 ) ;
if ( F_14 ( V_23 ) )
return V_23 ;
V_14 = F_13 ( V_24 , V_17 ) ;
if ( F_14 ( ! V_14 ) )
return - V_18 ;
F_20 ( & V_14 -> V_25 ) ;
memcpy ( V_14 -> V_26 , V_27 , V_28 ) ;
V_14 -> V_29 = V_30 ;
V_22 -> V_31 = V_14 ;
return 0 ;
}
static int F_21 ( struct V_21 * V_32 , struct V_22 * V_22 )
{
struct V_13 * V_14 = V_22 -> V_31 ;
struct V_1 * V_2 , * V_33 ;
F_22 ( & V_34 ) ;
F_23 (range, next, &asma->unpinned_list, unpinned)
F_15 ( V_2 ) ;
F_24 ( & V_34 ) ;
if ( V_14 -> V_22 )
F_25 ( V_14 -> V_22 ) ;
F_16 ( V_24 , V_14 ) ;
return 0 ;
}
static T_2 F_26 ( struct V_22 * V_22 , char T_3 * V_35 ,
T_1 V_36 , T_4 * V_37 )
{
struct V_13 * V_14 = V_22 -> V_31 ;
int V_23 = 0 ;
F_22 ( & V_34 ) ;
if ( V_14 -> V_38 == 0 )
goto V_39;
if ( ! V_14 -> V_22 ) {
V_23 = - V_40 ;
goto V_39;
}
F_24 ( & V_34 ) ;
V_23 = F_27 ( V_14 -> V_22 , V_35 , V_36 , V_37 ) ;
if ( V_23 >= 0 )
V_14 -> V_22 -> V_41 = * V_37 ;
return V_23 ;
V_39:
F_24 ( & V_34 ) ;
return V_23 ;
}
static T_4 F_28 ( struct V_22 * V_22 , T_4 V_42 , int V_43 )
{
struct V_13 * V_14 = V_22 -> V_31 ;
int V_23 ;
F_22 ( & V_34 ) ;
if ( V_14 -> V_38 == 0 ) {
V_23 = - V_44 ;
goto V_45;
}
if ( ! V_14 -> V_22 ) {
V_23 = - V_40 ;
goto V_45;
}
V_23 = F_29 ( V_14 -> V_22 , V_42 , V_43 ) ;
if ( V_23 < 0 )
goto V_45;
V_22 -> V_41 = V_14 -> V_22 -> V_41 ;
V_45:
F_24 ( & V_34 ) ;
return V_23 ;
}
static inline T_5 F_30 ( unsigned long V_46 )
{
return F_31 ( V_46 , V_47 , V_48 ) |
F_31 ( V_46 , V_49 , V_50 ) |
F_31 ( V_46 , V_51 , V_52 ) ;
}
static int F_32 ( struct V_22 * V_22 , struct V_53 * V_54 )
{
struct V_13 * V_14 = V_22 -> V_31 ;
int V_23 = 0 ;
F_22 ( & V_34 ) ;
if ( F_14 ( ! V_14 -> V_38 ) ) {
V_23 = - V_44 ;
goto V_45;
}
if ( F_14 ( ( V_54 -> V_55 & ~ F_33 ( V_14 -> V_29 , 0 ) ) &
F_33 ( V_30 , 0 ) ) ) {
V_23 = - V_56 ;
goto V_45;
}
V_54 -> V_55 &= ~ F_30 ( ~ V_14 -> V_29 ) ;
if ( ! V_14 -> V_22 ) {
char * V_26 = V_57 ;
struct V_22 * V_58 ;
if ( V_14 -> V_26 [ V_28 ] != '\0' )
V_26 = V_14 -> V_26 ;
V_58 = F_34 ( V_26 , V_14 -> V_38 , V_54 -> V_55 ) ;
if ( F_35 ( V_58 ) ) {
V_23 = F_36 ( V_58 ) ;
goto V_45;
}
V_14 -> V_22 = V_58 ;
}
F_37 ( V_14 -> V_22 ) ;
if ( V_54 -> V_55 & V_59 ) {
V_23 = F_38 ( V_54 ) ;
if ( V_23 ) {
F_25 ( V_14 -> V_22 ) ;
goto V_45;
}
}
if ( V_54 -> V_60 )
F_25 ( V_54 -> V_60 ) ;
V_54 -> V_60 = V_14 -> V_22 ;
V_45:
F_24 ( & V_34 ) ;
return V_23 ;
}
static unsigned long
F_39 ( struct V_61 * V_62 , struct V_63 * V_64 )
{
struct V_1 * V_2 , * V_33 ;
unsigned long V_65 = 0 ;
if ( ! ( V_64 -> V_66 & V_67 ) )
return V_68 ;
if ( ! F_40 ( & V_34 ) )
return - 1 ;
F_23 (range, next, &ashmem_lru_list, lru) {
T_4 V_7 = V_2 -> V_4 * V_69 ;
T_4 V_8 = ( V_2 -> V_3 + 1 ) * V_69 ;
F_41 ( V_2 -> V_14 -> V_22 ,
V_70 | V_71 ,
V_7 , V_8 - V_7 ) ;
V_2 -> V_5 = V_72 ;
F_10 ( V_2 ) ;
V_65 += F_1 ( V_2 ) ;
if ( -- V_64 -> V_73 <= 0 )
break;
}
F_24 ( & V_34 ) ;
return V_65 ;
}
static unsigned long
F_42 ( struct V_61 * V_62 , struct V_63 * V_64 )
{
return V_12 ;
}
static int F_43 ( struct V_13 * V_14 , unsigned long V_46 )
{
int V_23 = 0 ;
F_22 ( & V_34 ) ;
if ( F_14 ( ( V_14 -> V_29 & V_46 ) != V_46 ) ) {
V_23 = - V_44 ;
goto V_45;
}
if ( ( V_46 & V_47 ) && ( V_74 -> V_75 & V_76 ) )
V_46 |= V_51 ;
V_14 -> V_29 = V_46 ;
V_45:
F_24 ( & V_34 ) ;
return V_23 ;
}
static int F_44 ( struct V_13 * V_14 , void T_3 * V_26 )
{
int V_36 ;
int V_23 = 0 ;
char V_77 [ V_78 ] ;
V_36 = F_45 ( V_77 , V_26 , V_78 ) ;
if ( V_36 < 0 )
return V_36 ;
if ( V_36 == V_78 )
V_77 [ V_78 - 1 ] = '\0' ;
F_22 ( & V_34 ) ;
if ( F_14 ( V_14 -> V_22 ) )
V_23 = - V_44 ;
else
strcpy ( V_14 -> V_26 + V_28 , V_77 ) ;
F_24 ( & V_34 ) ;
return V_23 ;
}
static int F_46 ( struct V_13 * V_14 , void T_3 * V_26 )
{
int V_23 = 0 ;
T_1 V_36 ;
char V_77 [ V_78 ] ;
F_22 ( & V_34 ) ;
if ( V_14 -> V_26 [ V_28 ] != '\0' ) {
V_36 = strlen ( V_14 -> V_26 + V_28 ) + 1 ;
memcpy ( V_77 , V_14 -> V_26 + V_28 , V_36 ) ;
} else {
V_36 = sizeof( V_57 ) ;
memcpy ( V_77 , V_57 , V_36 ) ;
}
F_24 ( & V_34 ) ;
if ( F_14 ( F_47 ( V_26 , V_77 , V_36 ) ) )
V_23 = - V_79 ;
return V_23 ;
}
static int F_48 ( struct V_13 * V_14 , T_1 V_4 , T_1 V_3 )
{
struct V_1 * V_2 , * V_33 ;
int V_23 = V_6 ;
F_23 (range, next, &asma->unpinned_list, unpinned) {
if ( F_7 ( V_2 , V_4 ) )
break;
if ( F_6 ( V_2 , V_4 , V_3 ) ) {
V_23 |= V_2 -> V_5 ;
if ( F_3 ( V_2 , V_4 , V_3 ) ) {
F_15 ( V_2 ) ;
continue;
}
if ( V_2 -> V_4 >= V_4 ) {
F_17 ( V_2 , V_3 + 1 , V_2 -> V_3 ) ;
continue;
}
if ( V_2 -> V_3 <= V_3 ) {
F_17 ( V_2 , V_2 -> V_4 ,
V_4 - 1 ) ;
continue;
}
F_12 ( V_14 , V_2 , V_2 -> V_5 ,
V_3 + 1 , V_2 -> V_3 ) ;
F_17 ( V_2 , V_2 -> V_4 , V_4 - 1 ) ;
break;
}
}
return V_23 ;
}
static int F_49 ( struct V_13 * V_14 , T_1 V_4 , T_1 V_3 )
{
struct V_1 * V_2 , * V_33 ;
unsigned int V_5 = V_6 ;
V_80:
F_23 (range, next, &asma->unpinned_list, unpinned) {
if ( F_7 ( V_2 , V_4 ) )
break;
if ( F_4 ( V_2 , V_4 , V_3 ) )
return 0 ;
if ( F_6 ( V_2 , V_4 , V_3 ) ) {
V_4 = F_50 ( V_2 -> V_4 , V_4 ) ;
V_3 = F_51 ( V_2 -> V_3 , V_3 ) ;
V_5 |= V_2 -> V_5 ;
F_15 ( V_2 ) ;
goto V_80;
}
}
return F_12 ( V_14 , V_2 , V_5 , V_4 , V_3 ) ;
}
static int F_52 ( struct V_13 * V_14 , T_1 V_4 ,
T_1 V_3 )
{
struct V_1 * V_2 ;
int V_23 = V_81 ;
F_53 (range, &asma->unpinned_list, unpinned) {
if ( F_7 ( V_2 , V_4 ) )
break;
if ( F_6 ( V_2 , V_4 , V_3 ) ) {
V_23 = V_82 ;
break;
}
}
return V_23 ;
}
static int F_54 ( struct V_13 * V_14 , unsigned long V_83 ,
void T_3 * V_84 )
{
struct F_48 V_85 ;
T_1 V_4 , V_3 ;
int V_23 = - V_44 ;
if ( F_14 ( ! V_14 -> V_22 ) )
return - V_44 ;
if ( F_14 ( F_55 ( & V_85 , V_84 , sizeof( V_85 ) ) ) )
return - V_79 ;
if ( ! V_85 . V_36 )
V_85 . V_36 = F_56 ( V_14 -> V_38 ) - V_85 . V_42 ;
if ( F_14 ( ( V_85 . V_42 | V_85 . V_36 ) & ~ V_86 ) )
return - V_44 ;
if ( F_14 ( ( ( V_87 ) - 1 ) - V_85 . V_42 < V_85 . V_36 ) )
return - V_44 ;
if ( F_14 ( F_56 ( V_14 -> V_38 ) < V_85 . V_42 + V_85 . V_36 ) )
return - V_44 ;
V_4 = V_85 . V_42 / V_69 ;
V_3 = V_4 + ( V_85 . V_36 / V_69 ) - 1 ;
F_22 ( & V_34 ) ;
switch ( V_83 ) {
case V_88 :
V_23 = F_48 ( V_14 , V_4 , V_3 ) ;
break;
case V_89 :
V_23 = F_49 ( V_14 , V_4 , V_3 ) ;
break;
case V_90 :
V_23 = F_52 ( V_14 , V_4 , V_3 ) ;
break;
}
F_24 ( & V_34 ) ;
return V_23 ;
}
static long F_57 ( struct V_22 * V_22 , unsigned int V_83 , unsigned long V_91 )
{
struct V_13 * V_14 = V_22 -> V_31 ;
long V_23 = - V_92 ;
switch ( V_83 ) {
case V_93 :
V_23 = F_44 ( V_14 , ( void T_3 * ) V_91 ) ;
break;
case V_94 :
V_23 = F_46 ( V_14 , ( void T_3 * ) V_91 ) ;
break;
case V_95 :
V_23 = - V_44 ;
if ( ! V_14 -> V_22 ) {
V_23 = 0 ;
V_14 -> V_38 = ( T_1 ) V_91 ;
}
break;
case V_96 :
V_23 = V_14 -> V_38 ;
break;
case V_97 :
V_23 = F_43 ( V_14 , V_91 ) ;
break;
case V_98 :
V_23 = V_14 -> V_29 ;
break;
case V_88 :
case V_89 :
case V_90 :
V_23 = F_54 ( V_14 , V_83 , ( void T_3 * ) V_91 ) ;
break;
case V_99 :
V_23 = - V_56 ;
if ( F_58 ( V_100 ) ) {
struct V_63 V_64 = {
. V_66 = V_17 ,
. V_73 = V_101 ,
} ;
V_23 = F_42 ( & V_102 , & V_64 ) ;
F_39 ( & V_102 , & V_64 ) ;
}
break;
}
return V_23 ;
}
static long F_59 ( struct V_22 * V_22 , unsigned int V_83 ,
unsigned long V_91 )
{
switch ( V_83 ) {
case V_103 :
V_83 = V_95 ;
break;
case V_104 :
V_83 = V_97 ;
break;
}
return F_57 ( V_22 , V_83 , V_91 ) ;
}
static int T_6 F_60 ( void )
{
int V_23 = - V_18 ;
V_24 = F_61 ( L_1 ,
sizeof( struct V_13 ) ,
0 , 0 , NULL ) ;
if ( F_14 ( ! V_24 ) ) {
F_62 ( L_2 ) ;
goto V_45;
}
V_16 = F_61 ( L_3 ,
sizeof( struct V_1 ) ,
0 , 0 , NULL ) ;
if ( F_14 ( ! V_16 ) ) {
F_62 ( L_2 ) ;
goto V_105;
}
V_23 = F_63 ( & V_106 ) ;
if ( F_14 ( V_23 ) ) {
F_62 ( L_4 ) ;
goto V_107;
}
F_64 ( & V_102 ) ;
F_65 ( L_5 ) ;
return 0 ;
V_107:
F_66 ( V_16 ) ;
V_105:
F_66 ( V_24 ) ;
V_45:
return V_23 ;
}
