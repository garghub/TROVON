static inline int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 )
{
return ( ( ( V_2 ) -> V_5 >= ( V_3 ) ) && ( ( V_2 ) -> V_6 <= ( V_4 ) ) ) ;
}
static inline int F_2 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 )
{
return ( ( ( V_2 ) -> V_5 <= ( V_3 ) ) && ( ( V_2 ) -> V_6 >= ( V_4 ) ) ) ;
}
static inline int F_3 ( struct V_1 * V_2 , T_1 V_7 )
{
return ( ( ( V_2 ) -> V_5 <= ( V_7 ) ) && ( ( V_2 ) -> V_6 >= ( V_7 ) ) ) ;
}
static inline int F_4 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 )
{
return ( F_3 ( V_2 , V_3 ) || F_3 ( V_2 , V_4 ) ||
F_1 ( V_2 , V_3 , V_4 ) ) ;
}
static inline int F_5 ( struct V_1 * V_2 , T_1 V_7 )
{
return ( ( V_2 ) -> V_6 < ( V_7 ) ) ;
}
static inline void F_6 ( struct V_1 * V_2 )
{
F_7 ( & V_2 -> V_8 , & V_9 ) ;
V_10 += F_8 ( V_2 ) ;
}
static inline void F_9 ( struct V_1 * V_2 )
{
F_10 ( & V_2 -> V_8 ) ;
V_10 -= F_8 ( V_2 ) ;
}
static int F_11 ( struct V_11 * V_12 ,
struct V_1 * V_13 , unsigned int V_14 ,
T_1 V_3 , T_1 V_4 )
{
struct V_1 * V_2 ;
V_2 = F_12 ( V_15 , V_16 ) ;
if ( F_13 ( ! V_2 ) )
return - V_17 ;
V_2 -> V_12 = V_12 ;
V_2 -> V_5 = V_3 ;
V_2 -> V_6 = V_4 ;
V_2 -> V_14 = V_14 ;
F_7 ( & V_2 -> V_18 , & V_13 -> V_18 ) ;
if ( F_14 ( V_2 ) )
F_6 ( V_2 ) ;
return 0 ;
}
static void F_15 ( struct V_1 * V_2 )
{
F_10 ( & V_2 -> V_18 ) ;
if ( F_14 ( V_2 ) )
F_9 ( V_2 ) ;
F_16 ( V_15 , V_2 ) ;
}
static inline void F_17 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 )
{
T_1 V_19 = F_8 ( V_2 ) ;
V_2 -> V_5 = V_3 ;
V_2 -> V_6 = V_4 ;
if ( F_14 ( V_2 ) )
V_10 -= V_19 - F_8 ( V_2 ) ;
}
static int F_18 ( struct V_20 * V_20 , struct V_21 * V_21 )
{
struct V_11 * V_12 ;
int V_22 ;
V_22 = F_19 ( V_20 , V_21 ) ;
if ( F_13 ( V_22 ) )
return V_22 ;
V_12 = F_12 ( V_23 , V_16 ) ;
if ( F_13 ( ! V_12 ) )
return - V_17 ;
F_20 ( & V_12 -> V_24 ) ;
memcpy ( V_12 -> V_25 , V_26 , V_27 ) ;
V_12 -> V_28 = V_29 ;
V_21 -> V_30 = V_12 ;
return 0 ;
}
static int F_21 ( struct V_20 * V_31 , struct V_21 * V_21 )
{
struct V_11 * V_12 = V_21 -> V_30 ;
struct V_1 * V_2 , * V_32 ;
F_22 ( & V_33 ) ;
F_23 (range, next, &asma->unpinned_list, unpinned)
F_15 ( V_2 ) ;
F_24 ( & V_33 ) ;
if ( V_12 -> V_21 )
F_25 ( V_12 -> V_21 ) ;
F_16 ( V_23 , V_12 ) ;
return 0 ;
}
static T_2 F_26 ( struct V_21 * V_21 , char T_3 * V_34 ,
T_1 V_35 , T_4 * V_36 )
{
struct V_11 * V_12 = V_21 -> V_30 ;
int V_22 = 0 ;
F_22 ( & V_33 ) ;
if ( V_12 -> V_37 == 0 )
goto V_38;
if ( ! V_12 -> V_21 ) {
V_22 = - V_39 ;
goto V_38;
}
F_24 ( & V_33 ) ;
V_22 = F_27 ( V_12 -> V_21 , V_34 , V_35 , V_36 ) ;
if ( V_22 >= 0 )
V_12 -> V_21 -> V_40 = * V_36 ;
return V_22 ;
V_38:
F_24 ( & V_33 ) ;
return V_22 ;
}
static T_4 F_28 ( struct V_21 * V_21 , T_4 V_41 , int V_42 )
{
struct V_11 * V_12 = V_21 -> V_30 ;
int V_22 ;
F_22 ( & V_33 ) ;
if ( V_12 -> V_37 == 0 ) {
V_22 = - V_43 ;
goto V_44;
}
if ( ! V_12 -> V_21 ) {
V_22 = - V_39 ;
goto V_44;
}
V_22 = F_29 ( V_12 -> V_21 , V_41 , V_42 ) ;
if ( V_22 < 0 )
goto V_44;
V_21 -> V_40 = V_12 -> V_21 -> V_40 ;
V_44:
F_24 ( & V_33 ) ;
return V_22 ;
}
static inline T_5 F_30 ( unsigned long V_45 )
{
return F_31 ( V_45 , V_46 , V_47 ) |
F_31 ( V_45 , V_48 , V_49 ) |
F_31 ( V_45 , V_50 , V_51 ) ;
}
static int F_32 ( struct V_21 * V_21 , struct V_52 * V_53 )
{
struct V_11 * V_12 = V_21 -> V_30 ;
int V_22 = 0 ;
F_22 ( & V_33 ) ;
if ( F_13 ( ! V_12 -> V_37 ) ) {
V_22 = - V_43 ;
goto V_44;
}
if ( F_13 ( ( V_53 -> V_54 & ~ F_33 ( V_12 -> V_28 , 0 ) ) &
F_33 ( V_29 , 0 ) ) ) {
V_22 = - V_55 ;
goto V_44;
}
V_53 -> V_54 &= ~ F_30 ( ~ V_12 -> V_28 ) ;
if ( ! V_12 -> V_21 ) {
char * V_25 = V_56 ;
struct V_21 * V_57 ;
if ( V_12 -> V_25 [ V_27 ] != '\0' )
V_25 = V_12 -> V_25 ;
V_57 = F_34 ( V_25 , V_12 -> V_37 , V_53 -> V_54 ) ;
if ( F_35 ( V_57 ) ) {
V_22 = F_36 ( V_57 ) ;
goto V_44;
}
V_12 -> V_21 = V_57 ;
}
F_37 ( V_12 -> V_21 ) ;
if ( V_53 -> V_54 & V_58 ) {
V_22 = F_38 ( V_53 ) ;
if ( V_22 ) {
F_25 ( V_12 -> V_21 ) ;
goto V_44;
}
}
if ( V_53 -> V_59 )
F_25 ( V_53 -> V_59 ) ;
V_53 -> V_59 = V_12 -> V_21 ;
V_44:
F_24 ( & V_33 ) ;
return V_22 ;
}
static unsigned long
F_39 ( struct V_60 * V_61 , struct V_62 * V_63 )
{
struct V_1 * V_2 , * V_32 ;
unsigned long V_64 = 0 ;
if ( ! ( V_63 -> V_65 & V_66 ) )
return V_67 ;
if ( ! F_40 ( & V_33 ) )
return - 1 ;
F_23 (range, next, &ashmem_lru_list, lru) {
T_4 V_3 = V_2 -> V_5 * V_68 ;
T_4 V_4 = ( V_2 -> V_6 + 1 ) * V_68 ;
F_41 ( V_2 -> V_12 -> V_21 ,
V_69 | V_70 ,
V_3 , V_4 - V_3 ) ;
V_2 -> V_14 = V_71 ;
F_9 ( V_2 ) ;
V_64 += F_8 ( V_2 ) ;
if ( -- V_63 -> V_72 <= 0 )
break;
}
F_24 ( & V_33 ) ;
return V_64 ;
}
static unsigned long
F_42 ( struct V_60 * V_61 , struct V_62 * V_63 )
{
return V_10 ;
}
static int F_43 ( struct V_11 * V_12 , unsigned long V_45 )
{
int V_22 = 0 ;
F_22 ( & V_33 ) ;
if ( F_13 ( ( V_12 -> V_28 & V_45 ) != V_45 ) ) {
V_22 = - V_43 ;
goto V_44;
}
if ( ( V_45 & V_46 ) && ( V_73 -> V_74 & V_75 ) )
V_45 |= V_50 ;
V_12 -> V_28 = V_45 ;
V_44:
F_24 ( & V_33 ) ;
return V_22 ;
}
static int F_44 ( struct V_11 * V_12 , void T_3 * V_25 )
{
int V_35 ;
int V_22 = 0 ;
char V_76 [ V_77 ] ;
V_35 = F_45 ( V_76 , V_25 , V_77 ) ;
if ( V_35 < 0 )
return V_35 ;
if ( V_35 == V_77 )
V_76 [ V_77 - 1 ] = '\0' ;
F_22 ( & V_33 ) ;
if ( F_13 ( V_12 -> V_21 ) )
V_22 = - V_43 ;
else
strcpy ( V_12 -> V_25 + V_27 , V_76 ) ;
F_24 ( & V_33 ) ;
return V_22 ;
}
static int F_46 ( struct V_11 * V_12 , void T_3 * V_25 )
{
int V_22 = 0 ;
T_1 V_35 ;
char V_76 [ V_77 ] ;
F_22 ( & V_33 ) ;
if ( V_12 -> V_25 [ V_27 ] != '\0' ) {
V_35 = strlen ( V_12 -> V_25 + V_27 ) + 1 ;
memcpy ( V_76 , V_12 -> V_25 + V_27 , V_35 ) ;
} else {
V_35 = sizeof( V_56 ) ;
memcpy ( V_76 , V_56 , V_35 ) ;
}
F_24 ( & V_33 ) ;
if ( F_13 ( F_47 ( V_25 , V_76 , V_35 ) ) )
V_22 = - V_78 ;
return V_22 ;
}
static int F_48 ( struct V_11 * V_12 , T_1 V_5 , T_1 V_6 )
{
struct V_1 * V_2 , * V_32 ;
int V_22 = V_79 ;
F_23 (range, next, &asma->unpinned_list, unpinned) {
if ( F_5 ( V_2 , V_5 ) )
break;
if ( F_4 ( V_2 , V_5 , V_6 ) ) {
V_22 |= V_2 -> V_14 ;
if ( F_1 ( V_2 , V_5 , V_6 ) ) {
F_15 ( V_2 ) ;
continue;
}
if ( V_2 -> V_5 >= V_5 ) {
F_17 ( V_2 , V_6 + 1 , V_2 -> V_6 ) ;
continue;
}
if ( V_2 -> V_6 <= V_6 ) {
F_17 ( V_2 , V_2 -> V_5 ,
V_5 - 1 ) ;
continue;
}
F_11 ( V_12 , V_2 , V_2 -> V_14 ,
V_6 + 1 , V_2 -> V_6 ) ;
F_17 ( V_2 , V_2 -> V_5 , V_5 - 1 ) ;
break;
}
}
return V_22 ;
}
static int F_49 ( struct V_11 * V_12 , T_1 V_5 , T_1 V_6 )
{
struct V_1 * V_2 , * V_32 ;
unsigned int V_14 = V_79 ;
V_80:
F_23 (range, next, &asma->unpinned_list, unpinned) {
if ( F_5 ( V_2 , V_5 ) )
break;
if ( F_2 ( V_2 , V_5 , V_6 ) )
return 0 ;
if ( F_4 ( V_2 , V_5 , V_6 ) ) {
V_5 = F_50 ( V_2 -> V_5 , V_5 ) ;
V_6 = F_51 ( V_2 -> V_6 , V_6 ) ;
V_14 |= V_2 -> V_14 ;
F_15 ( V_2 ) ;
goto V_80;
}
}
return F_11 ( V_12 , V_2 , V_14 , V_5 , V_6 ) ;
}
static int F_52 ( struct V_11 * V_12 , T_1 V_5 ,
T_1 V_6 )
{
struct V_1 * V_2 ;
int V_22 = V_81 ;
F_53 (range, &asma->unpinned_list, unpinned) {
if ( F_5 ( V_2 , V_5 ) )
break;
if ( F_4 ( V_2 , V_5 , V_6 ) ) {
V_22 = V_82 ;
break;
}
}
return V_22 ;
}
static int F_54 ( struct V_11 * V_12 , unsigned long V_83 ,
void T_3 * V_84 )
{
struct F_48 V_85 ;
T_1 V_5 , V_6 ;
int V_22 = - V_43 ;
if ( F_13 ( ! V_12 -> V_21 ) )
return - V_43 ;
if ( F_13 ( F_55 ( & V_85 , V_84 , sizeof( V_85 ) ) ) )
return - V_78 ;
if ( ! V_85 . V_35 )
V_85 . V_35 = F_56 ( V_12 -> V_37 ) - V_85 . V_41 ;
if ( F_13 ( ( V_85 . V_41 | V_85 . V_35 ) & ~ V_86 ) )
return - V_43 ;
if ( F_13 ( ( ( V_87 ) - 1 ) - V_85 . V_41 < V_85 . V_35 ) )
return - V_43 ;
if ( F_13 ( F_56 ( V_12 -> V_37 ) < V_85 . V_41 + V_85 . V_35 ) )
return - V_43 ;
V_5 = V_85 . V_41 / V_68 ;
V_6 = V_5 + ( V_85 . V_35 / V_68 ) - 1 ;
F_22 ( & V_33 ) ;
switch ( V_83 ) {
case V_88 :
V_22 = F_48 ( V_12 , V_5 , V_6 ) ;
break;
case V_89 :
V_22 = F_49 ( V_12 , V_5 , V_6 ) ;
break;
case V_90 :
V_22 = F_52 ( V_12 , V_5 , V_6 ) ;
break;
}
F_24 ( & V_33 ) ;
return V_22 ;
}
static long F_57 ( struct V_21 * V_21 , unsigned int V_83 , unsigned long V_91 )
{
struct V_11 * V_12 = V_21 -> V_30 ;
long V_22 = - V_92 ;
switch ( V_83 ) {
case V_93 :
V_22 = F_44 ( V_12 , ( void T_3 * ) V_91 ) ;
break;
case V_94 :
V_22 = F_46 ( V_12 , ( void T_3 * ) V_91 ) ;
break;
case V_95 :
V_22 = - V_43 ;
if ( ! V_12 -> V_21 ) {
V_22 = 0 ;
V_12 -> V_37 = ( T_1 ) V_91 ;
}
break;
case V_96 :
V_22 = V_12 -> V_37 ;
break;
case V_97 :
V_22 = F_43 ( V_12 , V_91 ) ;
break;
case V_98 :
V_22 = V_12 -> V_28 ;
break;
case V_88 :
case V_89 :
case V_90 :
V_22 = F_54 ( V_12 , V_83 , ( void T_3 * ) V_91 ) ;
break;
case V_99 :
V_22 = - V_55 ;
if ( F_58 ( V_100 ) ) {
struct V_62 V_63 = {
. V_65 = V_16 ,
. V_72 = V_101 ,
} ;
V_22 = F_42 ( & V_102 , & V_63 ) ;
F_39 ( & V_102 , & V_63 ) ;
}
break;
}
return V_22 ;
}
static long F_59 ( struct V_21 * V_21 , unsigned int V_83 ,
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
return F_57 ( V_21 , V_83 , V_91 ) ;
}
static int T_6 F_60 ( void )
{
int V_22 = - V_17 ;
V_23 = F_61 ( L_1 ,
sizeof( struct V_11 ) ,
0 , 0 , NULL ) ;
if ( F_13 ( ! V_23 ) ) {
F_62 ( L_2 ) ;
goto V_44;
}
V_15 = F_61 ( L_3 ,
sizeof( struct V_1 ) ,
0 , 0 , NULL ) ;
if ( F_13 ( ! V_15 ) ) {
F_62 ( L_2 ) ;
goto V_105;
}
V_22 = F_63 ( & V_106 ) ;
if ( F_13 ( V_22 ) ) {
F_62 ( L_4 ) ;
goto V_107;
}
F_64 ( & V_102 ) ;
F_65 ( L_5 ) ;
return 0 ;
V_107:
F_66 ( V_15 ) ;
V_105:
F_66 ( V_23 ) ;
V_44:
return V_22 ;
}
