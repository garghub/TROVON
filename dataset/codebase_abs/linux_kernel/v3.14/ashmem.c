static inline void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 , & V_4 ) ;
V_5 += F_3 ( V_2 ) ;
}
static inline void F_4 ( struct V_1 * V_2 )
{
F_5 ( & V_2 -> V_3 ) ;
V_5 -= F_3 ( V_2 ) ;
}
static int F_6 ( struct V_6 * V_7 ,
struct V_1 * V_8 , unsigned int V_9 ,
T_1 V_10 , T_1 V_11 )
{
struct V_1 * V_2 ;
V_2 = F_7 ( V_12 , V_13 ) ;
if ( F_8 ( ! V_2 ) )
return - V_14 ;
V_2 -> V_7 = V_7 ;
V_2 -> V_15 = V_10 ;
V_2 -> V_16 = V_11 ;
V_2 -> V_9 = V_9 ;
F_2 ( & V_2 -> V_17 , & V_8 -> V_17 ) ;
if ( F_9 ( V_2 ) )
F_1 ( V_2 ) ;
return 0 ;
}
static void F_10 ( struct V_1 * V_2 )
{
F_5 ( & V_2 -> V_17 ) ;
if ( F_9 ( V_2 ) )
F_4 ( V_2 ) ;
F_11 ( V_12 , V_2 ) ;
}
static inline void F_12 ( struct V_1 * V_2 ,
T_1 V_10 , T_1 V_11 )
{
T_1 V_18 = F_3 ( V_2 ) ;
V_2 -> V_15 = V_10 ;
V_2 -> V_16 = V_11 ;
if ( F_9 ( V_2 ) )
V_5 -= V_18 - F_3 ( V_2 ) ;
}
static int F_13 ( struct V_19 * V_19 , struct V_20 * V_20 )
{
struct V_6 * V_7 ;
int V_21 ;
V_21 = F_14 ( V_19 , V_20 ) ;
if ( F_8 ( V_21 ) )
return V_21 ;
V_7 = F_7 ( V_22 , V_13 ) ;
if ( F_8 ( ! V_7 ) )
return - V_14 ;
F_15 ( & V_7 -> V_23 ) ;
memcpy ( V_7 -> V_24 , V_25 , V_26 ) ;
V_7 -> V_27 = V_28 ;
V_20 -> V_29 = V_7 ;
return 0 ;
}
static int F_16 ( struct V_19 * V_30 , struct V_20 * V_20 )
{
struct V_6 * V_7 = V_20 -> V_29 ;
struct V_1 * V_2 , * V_31 ;
F_17 ( & V_32 ) ;
F_18 (range, next, &asma->unpinned_list, unpinned)
F_10 ( V_2 ) ;
F_19 ( & V_32 ) ;
if ( V_7 -> V_20 )
F_20 ( V_7 -> V_20 ) ;
F_11 ( V_22 , V_7 ) ;
return 0 ;
}
static T_2 F_21 ( struct V_20 * V_20 , char T_3 * V_33 ,
T_1 V_34 , T_4 * V_35 )
{
struct V_6 * V_7 = V_20 -> V_29 ;
int V_21 = 0 ;
F_17 ( & V_32 ) ;
if ( V_7 -> V_36 == 0 )
goto V_37;
if ( ! V_7 -> V_20 ) {
V_21 = - V_38 ;
goto V_37;
}
F_19 ( & V_32 ) ;
V_21 = V_7 -> V_20 -> V_39 -> V_40 ( V_7 -> V_20 , V_33 , V_34 , V_35 ) ;
if ( V_21 >= 0 ) {
V_7 -> V_20 -> V_41 = * V_35 ;
}
return V_21 ;
V_37:
F_19 ( & V_32 ) ;
return V_21 ;
}
static T_4 F_22 ( struct V_20 * V_20 , T_4 V_42 , int V_43 )
{
struct V_6 * V_7 = V_20 -> V_29 ;
int V_21 ;
F_17 ( & V_32 ) ;
if ( V_7 -> V_36 == 0 ) {
V_21 = - V_44 ;
goto V_45;
}
if ( ! V_7 -> V_20 ) {
V_21 = - V_38 ;
goto V_45;
}
V_21 = V_7 -> V_20 -> V_39 -> V_46 ( V_7 -> V_20 , V_42 , V_43 ) ;
if ( V_21 < 0 )
goto V_45;
V_20 -> V_41 = V_7 -> V_20 -> V_41 ;
V_45:
F_19 ( & V_32 ) ;
return V_21 ;
}
static inline T_5 F_23 ( unsigned long V_47 )
{
return F_24 ( V_47 , V_48 , V_49 ) |
F_24 ( V_47 , V_50 , V_51 ) |
F_24 ( V_47 , V_52 , V_53 ) ;
}
static int F_25 ( struct V_20 * V_20 , struct V_54 * V_55 )
{
struct V_6 * V_7 = V_20 -> V_29 ;
int V_21 = 0 ;
F_17 ( & V_32 ) ;
if ( F_8 ( ! V_7 -> V_36 ) ) {
V_21 = - V_44 ;
goto V_45;
}
if ( F_8 ( ( V_55 -> V_56 & ~ F_26 ( V_7 -> V_27 ) ) &
F_26 ( V_28 ) ) ) {
V_21 = - V_57 ;
goto V_45;
}
V_55 -> V_56 &= ~ F_23 ( ~ V_7 -> V_27 ) ;
if ( ! V_7 -> V_20 ) {
char * V_24 = V_58 ;
struct V_20 * V_59 ;
if ( V_7 -> V_24 [ V_26 ] != '\0' )
V_24 = V_7 -> V_24 ;
V_59 = F_27 ( V_24 , V_7 -> V_36 , V_55 -> V_56 ) ;
if ( F_8 ( F_28 ( V_59 ) ) ) {
V_21 = F_29 ( V_59 ) ;
goto V_45;
}
V_7 -> V_20 = V_59 ;
}
F_30 ( V_7 -> V_20 ) ;
if ( V_55 -> V_56 & V_60 ) {
V_21 = F_31 ( V_55 ) ;
if ( V_21 ) {
F_20 ( V_7 -> V_20 ) ;
goto V_45;
}
}
if ( V_55 -> V_61 )
F_20 ( V_55 -> V_61 ) ;
V_55 -> V_61 = V_7 -> V_20 ;
V_45:
F_19 ( & V_32 ) ;
return V_21 ;
}
static unsigned long
F_32 ( struct V_62 * V_63 , struct V_64 * V_65 )
{
struct V_1 * V_2 , * V_31 ;
unsigned long V_66 = 0 ;
if ( ! ( V_65 -> V_67 & V_68 ) )
return V_69 ;
F_17 ( & V_32 ) ;
F_18 (range, next, &ashmem_lru_list, lru) {
T_4 V_10 = V_2 -> V_15 * V_70 ;
T_4 V_11 = ( V_2 -> V_16 + 1 ) * V_70 ;
F_33 ( V_2 -> V_7 -> V_20 ,
V_71 | V_72 ,
V_10 , V_11 - V_10 ) ;
V_2 -> V_9 = V_73 ;
F_4 ( V_2 ) ;
V_66 += F_3 ( V_2 ) ;
if ( -- V_65 -> V_74 <= 0 )
break;
}
F_19 ( & V_32 ) ;
return V_66 ;
}
static unsigned long
F_34 ( struct V_62 * V_63 , struct V_64 * V_65 )
{
return V_5 ;
}
static int F_35 ( struct V_6 * V_7 , unsigned long V_47 )
{
int V_21 = 0 ;
F_17 ( & V_32 ) ;
if ( F_8 ( ( V_7 -> V_27 & V_47 ) != V_47 ) ) {
V_21 = - V_44 ;
goto V_45;
}
if ( ( V_47 & V_48 ) && ( V_75 -> V_76 & V_77 ) )
V_47 |= V_52 ;
V_7 -> V_27 = V_47 ;
V_45:
F_19 ( & V_32 ) ;
return V_21 ;
}
static int F_36 ( struct V_6 * V_7 , void T_3 * V_24 )
{
int V_34 ;
int V_21 = 0 ;
char V_78 [ V_79 ] ;
V_34 = F_37 ( V_78 , V_24 , V_79 ) ;
if ( V_34 < 0 )
return V_34 ;
if ( V_34 == V_79 )
V_78 [ V_79 - 1 ] = '\0' ;
F_17 ( & V_32 ) ;
if ( F_8 ( V_7 -> V_20 ) )
V_21 = - V_44 ;
else
strcpy ( V_7 -> V_24 + V_26 , V_78 ) ;
F_19 ( & V_32 ) ;
return V_21 ;
}
static int F_38 ( struct V_6 * V_7 , void T_3 * V_24 )
{
int V_21 = 0 ;
T_1 V_34 ;
char V_78 [ V_79 ] ;
F_17 ( & V_32 ) ;
if ( V_7 -> V_24 [ V_26 ] != '\0' ) {
V_34 = strlen ( V_7 -> V_24 + V_26 ) + 1 ;
memcpy ( V_78 , V_7 -> V_24 + V_26 , V_34 ) ;
} else {
V_34 = sizeof( V_58 ) ;
memcpy ( V_78 , V_58 , V_34 ) ;
}
F_19 ( & V_32 ) ;
if ( F_8 ( F_39 ( V_24 , V_78 , V_34 ) ) )
V_21 = - V_80 ;
return V_21 ;
}
static int F_40 ( struct V_6 * V_7 , T_1 V_15 , T_1 V_16 )
{
struct V_1 * V_2 , * V_31 ;
int V_21 = V_81 ;
F_18 (range, next, &asma->unpinned_list, unpinned) {
if ( F_41 ( V_2 , V_15 ) )
break;
if ( F_42 ( V_2 , V_15 , V_16 ) ) {
V_21 |= V_2 -> V_9 ;
if ( F_43 ( V_2 , V_15 , V_16 ) ) {
F_10 ( V_2 ) ;
continue;
}
if ( V_2 -> V_15 >= V_15 ) {
F_12 ( V_2 , V_16 + 1 , V_2 -> V_16 ) ;
continue;
}
if ( V_2 -> V_16 <= V_16 ) {
F_12 ( V_2 , V_2 -> V_15 , V_15 - 1 ) ;
continue;
}
F_6 ( V_7 , V_2 , V_2 -> V_9 ,
V_16 + 1 , V_2 -> V_16 ) ;
F_12 ( V_2 , V_2 -> V_15 , V_15 - 1 ) ;
break;
}
}
return V_21 ;
}
static int F_44 ( struct V_6 * V_7 , T_1 V_15 , T_1 V_16 )
{
struct V_1 * V_2 , * V_31 ;
unsigned int V_9 = V_81 ;
V_82:
F_18 (range, next, &asma->unpinned_list, unpinned) {
if ( F_41 ( V_2 , V_15 ) )
break;
if ( F_45 ( V_2 , V_15 , V_16 ) )
return 0 ;
if ( F_42 ( V_2 , V_15 , V_16 ) ) {
V_15 = F_46 ( T_1 , V_2 -> V_15 , V_15 ) ,
V_16 = F_47 ( T_1 , V_2 -> V_16 , V_16 ) ;
V_9 |= V_2 -> V_9 ;
F_10 ( V_2 ) ;
goto V_82;
}
}
return F_6 ( V_7 , V_2 , V_9 , V_15 , V_16 ) ;
}
static int F_48 ( struct V_6 * V_7 , T_1 V_15 ,
T_1 V_16 )
{
struct V_1 * V_2 ;
int V_21 = V_83 ;
F_49 (range, &asma->unpinned_list, unpinned) {
if ( F_41 ( V_2 , V_15 ) )
break;
if ( F_42 ( V_2 , V_15 , V_16 ) ) {
V_21 = V_84 ;
break;
}
}
return V_21 ;
}
static int F_50 ( struct V_6 * V_7 , unsigned long V_85 ,
void T_3 * V_86 )
{
struct F_40 V_87 ;
T_1 V_15 , V_16 ;
int V_21 = - V_44 ;
if ( F_8 ( ! V_7 -> V_20 ) )
return - V_44 ;
if ( F_8 ( F_51 ( & V_87 , V_86 , sizeof( V_87 ) ) ) )
return - V_80 ;
if ( ! V_87 . V_34 )
V_87 . V_34 = F_52 ( V_7 -> V_36 ) - V_87 . V_42 ;
if ( F_8 ( ( V_87 . V_42 | V_87 . V_34 ) & ~ V_88 ) )
return - V_44 ;
if ( F_8 ( ( ( V_89 ) - 1 ) - V_87 . V_42 < V_87 . V_34 ) )
return - V_44 ;
if ( F_8 ( F_52 ( V_7 -> V_36 ) < V_87 . V_42 + V_87 . V_34 ) )
return - V_44 ;
V_15 = V_87 . V_42 / V_70 ;
V_16 = V_15 + ( V_87 . V_34 / V_70 ) - 1 ;
F_17 ( & V_32 ) ;
switch ( V_85 ) {
case V_90 :
V_21 = F_40 ( V_7 , V_15 , V_16 ) ;
break;
case V_91 :
V_21 = F_44 ( V_7 , V_15 , V_16 ) ;
break;
case V_92 :
V_21 = F_48 ( V_7 , V_15 , V_16 ) ;
break;
}
F_19 ( & V_32 ) ;
return V_21 ;
}
static long F_53 ( struct V_20 * V_20 , unsigned int V_85 , unsigned long V_93 )
{
struct V_6 * V_7 = V_20 -> V_29 ;
long V_21 = - V_94 ;
switch ( V_85 ) {
case V_95 :
V_21 = F_36 ( V_7 , ( void T_3 * ) V_93 ) ;
break;
case V_96 :
V_21 = F_38 ( V_7 , ( void T_3 * ) V_93 ) ;
break;
case V_97 :
V_21 = - V_44 ;
if ( ! V_7 -> V_20 ) {
V_21 = 0 ;
V_7 -> V_36 = ( T_1 ) V_93 ;
}
break;
case V_98 :
V_21 = V_7 -> V_36 ;
break;
case V_99 :
V_21 = F_35 ( V_7 , V_93 ) ;
break;
case V_100 :
V_21 = V_7 -> V_27 ;
break;
case V_90 :
case V_91 :
case V_92 :
V_21 = F_50 ( V_7 , V_85 , ( void T_3 * ) V_93 ) ;
break;
case V_101 :
V_21 = - V_57 ;
if ( F_54 ( V_102 ) ) {
struct V_64 V_65 = {
. V_67 = V_13 ,
. V_74 = V_103 ,
} ;
V_21 = F_34 ( & V_104 , & V_65 ) ;
F_55 ( V_65 . V_105 ) ;
F_32 ( & V_104 , & V_65 ) ;
}
break;
}
return V_21 ;
}
static long F_56 ( struct V_20 * V_20 , unsigned int V_85 ,
unsigned long V_93 )
{
switch ( V_85 ) {
case V_106 :
V_85 = V_97 ;
break;
case V_107 :
V_85 = V_99 ;
break;
}
return F_53 ( V_20 , V_85 , V_93 ) ;
}
static int T_6 F_57 ( void )
{
int V_21 ;
V_22 = F_58 ( L_1 ,
sizeof( struct V_6 ) ,
0 , 0 , NULL ) ;
if ( F_8 ( ! V_22 ) ) {
F_59 ( L_2 ) ;
return - V_14 ;
}
V_12 = F_58 ( L_3 ,
sizeof( struct V_1 ) ,
0 , 0 , NULL ) ;
if ( F_8 ( ! V_12 ) ) {
F_59 ( L_2 ) ;
return - V_14 ;
}
V_21 = F_60 ( & V_108 ) ;
if ( F_8 ( V_21 ) ) {
F_59 ( L_4 ) ;
return V_21 ;
}
F_61 ( & V_104 ) ;
F_62 ( L_5 ) ;
return 0 ;
}
static void T_7 F_63 ( void )
{
int V_21 ;
F_64 ( & V_104 ) ;
V_21 = F_65 ( & V_108 ) ;
if ( F_8 ( V_21 ) )
F_59 ( L_6 ) ;
F_66 ( V_12 ) ;
F_66 ( V_22 ) ;
F_62 ( L_7 ) ;
}
