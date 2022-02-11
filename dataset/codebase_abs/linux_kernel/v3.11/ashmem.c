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
V_21 = V_7 -> V_20 -> V_39 -> V_40 ( V_7 -> V_20 , V_33 , V_34 , V_35 ) ;
if ( V_21 < 0 )
goto V_37;
V_7 -> V_20 -> V_41 = * V_35 ;
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
goto V_37;
}
if ( ! V_7 -> V_20 ) {
V_21 = - V_38 ;
goto V_37;
}
V_21 = V_7 -> V_20 -> V_39 -> V_45 ( V_7 -> V_20 , V_42 , V_43 ) ;
if ( V_21 < 0 )
goto V_37;
V_20 -> V_41 = V_7 -> V_20 -> V_41 ;
V_37:
F_19 ( & V_32 ) ;
return V_21 ;
}
static inline T_5 F_23 ( unsigned long V_46 )
{
return F_24 ( V_46 , V_47 , V_48 ) |
F_24 ( V_46 , V_49 , V_50 ) |
F_24 ( V_46 , V_51 , V_52 ) ;
}
static int F_25 ( struct V_20 * V_20 , struct V_53 * V_54 )
{
struct V_6 * V_7 = V_20 -> V_29 ;
int V_21 = 0 ;
F_17 ( & V_32 ) ;
if ( F_8 ( ! V_7 -> V_36 ) ) {
V_21 = - V_44 ;
goto V_37;
}
if ( F_8 ( ( V_54 -> V_55 & ~ F_26 ( V_7 -> V_27 ) ) &
F_26 ( V_28 ) ) ) {
V_21 = - V_56 ;
goto V_37;
}
V_54 -> V_55 &= ~ F_23 ( ~ V_7 -> V_27 ) ;
if ( ! V_7 -> V_20 ) {
char * V_24 = V_57 ;
struct V_20 * V_58 ;
if ( V_7 -> V_24 [ V_26 ] != '\0' )
V_24 = V_7 -> V_24 ;
V_58 = F_27 ( V_24 , V_7 -> V_36 , V_54 -> V_55 ) ;
if ( F_8 ( F_28 ( V_58 ) ) ) {
V_21 = F_29 ( V_58 ) ;
goto V_37;
}
V_7 -> V_20 = V_58 ;
}
F_30 ( V_7 -> V_20 ) ;
if ( V_54 -> V_55 & V_59 ) {
V_21 = F_31 ( V_54 ) ;
if ( V_21 ) {
F_20 ( V_7 -> V_20 ) ;
goto V_37;
}
}
if ( V_54 -> V_60 )
F_20 ( V_54 -> V_60 ) ;
V_54 -> V_60 = V_7 -> V_20 ;
V_37:
F_19 ( & V_32 ) ;
return V_21 ;
}
static int F_32 ( struct V_61 * V_62 , struct V_63 * V_64 )
{
struct V_1 * V_2 , * V_31 ;
if ( V_64 -> V_65 && ! ( V_64 -> V_66 & V_67 ) )
return - 1 ;
if ( ! V_64 -> V_65 )
return V_5 ;
F_17 ( & V_32 ) ;
F_18 (range, next, &ashmem_lru_list, lru) {
T_4 V_10 = V_2 -> V_15 * V_68 ;
T_4 V_11 = ( V_2 -> V_16 + 1 ) * V_68 ;
F_33 ( V_2 -> V_7 -> V_20 ,
V_69 | V_70 ,
V_10 , V_11 - V_10 ) ;
V_2 -> V_9 = V_71 ;
F_4 ( V_2 ) ;
V_64 -> V_65 -= F_3 ( V_2 ) ;
if ( V_64 -> V_65 <= 0 )
break;
}
F_19 ( & V_32 ) ;
return V_5 ;
}
static int F_34 ( struct V_6 * V_7 , unsigned long V_46 )
{
int V_21 = 0 ;
F_17 ( & V_32 ) ;
if ( F_8 ( ( V_7 -> V_27 & V_46 ) != V_46 ) ) {
V_21 = - V_44 ;
goto V_37;
}
if ( ( V_46 & V_47 ) && ( V_72 -> V_73 & V_74 ) )
V_46 |= V_51 ;
V_7 -> V_27 = V_46 ;
V_37:
F_19 ( & V_32 ) ;
return V_21 ;
}
static int F_35 ( struct V_6 * V_7 , void T_3 * V_24 )
{
int V_21 = 0 ;
char V_75 [ V_76 ] ;
if ( F_36 ( V_75 , V_24 , V_76 ) )
return - V_77 ;
F_17 ( & V_32 ) ;
if ( F_8 ( V_7 -> V_20 ) ) {
V_21 = - V_44 ;
goto V_37;
}
memcpy ( V_7 -> V_24 + V_26 ,
V_75 , V_76 ) ;
V_7 -> V_24 [ V_78 - 1 ] = '\0' ;
V_37:
F_19 ( & V_32 ) ;
return V_21 ;
}
static int F_37 ( struct V_6 * V_7 , void T_3 * V_24 )
{
int V_21 = 0 ;
T_1 V_34 ;
char V_75 [ V_76 ] ;
F_17 ( & V_32 ) ;
if ( V_7 -> V_24 [ V_26 ] != '\0' ) {
V_34 = strlen ( V_7 -> V_24 + V_26 ) + 1 ;
memcpy ( V_75 , V_7 -> V_24 + V_26 , V_34 ) ;
} else {
V_34 = sizeof( V_57 ) ;
memcpy ( V_75 , V_57 , V_34 ) ;
}
F_19 ( & V_32 ) ;
if ( F_8 ( F_38 ( V_24 , V_75 , V_34 ) ) )
V_21 = - V_77 ;
return V_21 ;
}
static int F_39 ( struct V_6 * V_7 , T_1 V_15 , T_1 V_16 )
{
struct V_1 * V_2 , * V_31 ;
int V_21 = V_79 ;
F_18 (range, next, &asma->unpinned_list, unpinned) {
if ( F_40 ( V_2 , V_15 ) )
break;
if ( F_41 ( V_2 , V_15 , V_16 ) ) {
V_21 |= V_2 -> V_9 ;
if ( F_42 ( V_2 , V_15 , V_16 ) ) {
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
static int F_43 ( struct V_6 * V_7 , T_1 V_15 , T_1 V_16 )
{
struct V_1 * V_2 , * V_31 ;
unsigned int V_9 = V_79 ;
V_80:
F_18 (range, next, &asma->unpinned_list, unpinned) {
if ( F_40 ( V_2 , V_15 ) )
break;
if ( F_44 ( V_2 , V_15 , V_16 ) )
return 0 ;
if ( F_41 ( V_2 , V_15 , V_16 ) ) {
V_15 = F_45 ( T_1 , V_2 -> V_15 , V_15 ) ,
V_16 = F_46 ( T_1 , V_2 -> V_16 , V_16 ) ;
V_9 |= V_2 -> V_9 ;
F_10 ( V_2 ) ;
goto V_80;
}
}
return F_6 ( V_7 , V_2 , V_9 , V_15 , V_16 ) ;
}
static int F_47 ( struct V_6 * V_7 , T_1 V_15 ,
T_1 V_16 )
{
struct V_1 * V_2 ;
int V_21 = V_81 ;
F_48 (range, &asma->unpinned_list, unpinned) {
if ( F_40 ( V_2 , V_15 ) )
break;
if ( F_41 ( V_2 , V_15 , V_16 ) ) {
V_21 = V_82 ;
break;
}
}
return V_21 ;
}
static int F_49 ( struct V_6 * V_7 , unsigned long V_83 ,
void T_3 * V_84 )
{
struct F_39 V_85 ;
T_1 V_15 , V_16 ;
int V_21 = - V_44 ;
if ( F_8 ( ! V_7 -> V_20 ) )
return - V_44 ;
if ( F_8 ( F_36 ( & V_85 , V_84 , sizeof( V_85 ) ) ) )
return - V_77 ;
if ( ! V_85 . V_34 )
V_85 . V_34 = F_50 ( V_7 -> V_36 ) - V_85 . V_42 ;
if ( F_8 ( ( V_85 . V_42 | V_85 . V_34 ) & ~ V_86 ) )
return - V_44 ;
if ( F_8 ( ( ( V_87 ) - 1 ) - V_85 . V_42 < V_85 . V_34 ) )
return - V_44 ;
if ( F_8 ( F_50 ( V_7 -> V_36 ) < V_85 . V_42 + V_85 . V_34 ) )
return - V_44 ;
V_15 = V_85 . V_42 / V_68 ;
V_16 = V_15 + ( V_85 . V_34 / V_68 ) - 1 ;
F_17 ( & V_32 ) ;
switch ( V_83 ) {
case V_88 :
V_21 = F_39 ( V_7 , V_15 , V_16 ) ;
break;
case V_89 :
V_21 = F_43 ( V_7 , V_15 , V_16 ) ;
break;
case V_90 :
V_21 = F_47 ( V_7 , V_15 , V_16 ) ;
break;
}
F_19 ( & V_32 ) ;
return V_21 ;
}
static long F_51 ( struct V_20 * V_20 , unsigned int V_83 , unsigned long V_91 )
{
struct V_6 * V_7 = V_20 -> V_29 ;
long V_21 = - V_92 ;
switch ( V_83 ) {
case V_93 :
V_21 = F_35 ( V_7 , ( void T_3 * ) V_91 ) ;
break;
case V_94 :
V_21 = F_37 ( V_7 , ( void T_3 * ) V_91 ) ;
break;
case V_95 :
V_21 = - V_44 ;
if ( ! V_7 -> V_20 ) {
V_21 = 0 ;
V_7 -> V_36 = ( T_1 ) V_91 ;
}
break;
case V_96 :
V_21 = V_7 -> V_36 ;
break;
case V_97 :
V_21 = F_34 ( V_7 , V_91 ) ;
break;
case V_98 :
V_21 = V_7 -> V_27 ;
break;
case V_88 :
case V_89 :
case V_90 :
V_21 = F_49 ( V_7 , V_83 , ( void T_3 * ) V_91 ) ;
break;
case V_99 :
V_21 = - V_56 ;
if ( F_52 ( V_100 ) ) {
struct V_63 V_64 = {
. V_66 = V_13 ,
. V_65 = 0 ,
} ;
V_21 = F_32 ( & V_101 , & V_64 ) ;
V_64 . V_65 = V_21 ;
F_32 ( & V_101 , & V_64 ) ;
}
break;
}
return V_21 ;
}
static long F_53 ( struct V_20 * V_20 , unsigned int V_83 ,
unsigned long V_91 )
{
switch ( V_83 ) {
case V_102 :
V_83 = V_95 ;
break;
case V_103 :
V_83 = V_97 ;
break;
}
return F_51 ( V_20 , V_83 , V_91 ) ;
}
static int T_6 F_54 ( void )
{
int V_21 ;
V_22 = F_55 ( L_1 ,
sizeof( struct V_6 ) ,
0 , 0 , NULL ) ;
if ( F_8 ( ! V_22 ) ) {
F_56 ( L_2 ) ;
return - V_14 ;
}
V_12 = F_55 ( L_3 ,
sizeof( struct V_1 ) ,
0 , 0 , NULL ) ;
if ( F_8 ( ! V_12 ) ) {
F_56 ( L_2 ) ;
return - V_14 ;
}
V_21 = F_57 ( & V_104 ) ;
if ( F_8 ( V_21 ) ) {
F_56 ( L_4 ) ;
return V_21 ;
}
F_58 ( & V_101 ) ;
F_59 ( L_5 ) ;
return 0 ;
}
static void T_7 F_60 ( void )
{
int V_21 ;
F_61 ( & V_101 ) ;
V_21 = F_62 ( & V_104 ) ;
if ( F_8 ( V_21 ) )
F_56 ( L_6 ) ;
F_63 ( V_12 ) ;
F_63 ( V_22 ) ;
F_59 ( L_7 ) ;
}
