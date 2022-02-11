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
V_21 = F_23 ( V_7 -> V_20 , V_42 , V_43 ) ;
if ( V_21 < 0 )
goto V_45;
V_20 -> V_41 = V_7 -> V_20 -> V_41 ;
V_45:
F_19 ( & V_32 ) ;
return V_21 ;
}
static inline T_5 F_24 ( unsigned long V_46 )
{
return F_25 ( V_46 , V_47 , V_48 ) |
F_25 ( V_46 , V_49 , V_50 ) |
F_25 ( V_46 , V_51 , V_52 ) ;
}
static int F_26 ( struct V_20 * V_20 , struct V_53 * V_54 )
{
struct V_6 * V_7 = V_20 -> V_29 ;
int V_21 = 0 ;
F_17 ( & V_32 ) ;
if ( F_8 ( ! V_7 -> V_36 ) ) {
V_21 = - V_44 ;
goto V_45;
}
if ( F_8 ( ( V_54 -> V_55 & ~ F_27 ( V_7 -> V_27 ) ) &
F_27 ( V_28 ) ) ) {
V_21 = - V_56 ;
goto V_45;
}
V_54 -> V_55 &= ~ F_24 ( ~ V_7 -> V_27 ) ;
if ( ! V_7 -> V_20 ) {
char * V_24 = V_57 ;
struct V_20 * V_58 ;
if ( V_7 -> V_24 [ V_26 ] != '\0' )
V_24 = V_7 -> V_24 ;
V_58 = F_28 ( V_24 , V_7 -> V_36 , V_54 -> V_55 ) ;
if ( F_8 ( F_29 ( V_58 ) ) ) {
V_21 = F_30 ( V_58 ) ;
goto V_45;
}
V_7 -> V_20 = V_58 ;
}
F_31 ( V_7 -> V_20 ) ;
if ( V_54 -> V_55 & V_59 ) {
V_21 = F_32 ( V_54 ) ;
if ( V_21 ) {
F_20 ( V_7 -> V_20 ) ;
goto V_45;
}
}
if ( V_54 -> V_60 )
F_20 ( V_54 -> V_60 ) ;
V_54 -> V_60 = V_7 -> V_20 ;
V_45:
F_19 ( & V_32 ) ;
return V_21 ;
}
static unsigned long
F_33 ( struct V_61 * V_62 , struct V_63 * V_64 )
{
struct V_1 * V_2 , * V_31 ;
unsigned long V_65 = 0 ;
if ( ! ( V_64 -> V_66 & V_67 ) )
return V_68 ;
F_17 ( & V_32 ) ;
F_18 (range, next, &ashmem_lru_list, lru) {
T_4 V_10 = V_2 -> V_15 * V_69 ;
T_4 V_11 = ( V_2 -> V_16 + 1 ) * V_69 ;
F_34 ( V_2 -> V_7 -> V_20 ,
V_70 | V_71 ,
V_10 , V_11 - V_10 ) ;
V_2 -> V_9 = V_72 ;
F_4 ( V_2 ) ;
V_65 += F_3 ( V_2 ) ;
if ( -- V_64 -> V_73 <= 0 )
break;
}
F_19 ( & V_32 ) ;
return V_65 ;
}
static unsigned long
F_35 ( struct V_61 * V_62 , struct V_63 * V_64 )
{
return V_5 ;
}
static int F_36 ( struct V_6 * V_7 , unsigned long V_46 )
{
int V_21 = 0 ;
F_17 ( & V_32 ) ;
if ( F_8 ( ( V_7 -> V_27 & V_46 ) != V_46 ) ) {
V_21 = - V_44 ;
goto V_45;
}
if ( ( V_46 & V_47 ) && ( V_74 -> V_75 & V_76 ) )
V_46 |= V_51 ;
V_7 -> V_27 = V_46 ;
V_45:
F_19 ( & V_32 ) ;
return V_21 ;
}
static int F_37 ( struct V_6 * V_7 , void T_3 * V_24 )
{
int V_34 ;
int V_21 = 0 ;
char V_77 [ V_78 ] ;
V_34 = F_38 ( V_77 , V_24 , V_78 ) ;
if ( V_34 < 0 )
return V_34 ;
if ( V_34 == V_78 )
V_77 [ V_78 - 1 ] = '\0' ;
F_17 ( & V_32 ) ;
if ( F_8 ( V_7 -> V_20 ) )
V_21 = - V_44 ;
else
strcpy ( V_7 -> V_24 + V_26 , V_77 ) ;
F_19 ( & V_32 ) ;
return V_21 ;
}
static int F_39 ( struct V_6 * V_7 , void T_3 * V_24 )
{
int V_21 = 0 ;
T_1 V_34 ;
char V_77 [ V_78 ] ;
F_17 ( & V_32 ) ;
if ( V_7 -> V_24 [ V_26 ] != '\0' ) {
V_34 = strlen ( V_7 -> V_24 + V_26 ) + 1 ;
memcpy ( V_77 , V_7 -> V_24 + V_26 , V_34 ) ;
} else {
V_34 = sizeof( V_57 ) ;
memcpy ( V_77 , V_57 , V_34 ) ;
}
F_19 ( & V_32 ) ;
if ( F_8 ( F_40 ( V_24 , V_77 , V_34 ) ) )
V_21 = - V_79 ;
return V_21 ;
}
static int F_41 ( struct V_6 * V_7 , T_1 V_15 , T_1 V_16 )
{
struct V_1 * V_2 , * V_31 ;
int V_21 = V_80 ;
F_18 (range, next, &asma->unpinned_list, unpinned) {
if ( F_42 ( V_2 , V_15 ) )
break;
if ( F_43 ( V_2 , V_15 , V_16 ) ) {
V_21 |= V_2 -> V_9 ;
if ( F_44 ( V_2 , V_15 , V_16 ) ) {
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
static int F_45 ( struct V_6 * V_7 , T_1 V_15 , T_1 V_16 )
{
struct V_1 * V_2 , * V_31 ;
unsigned int V_9 = V_80 ;
V_81:
F_18 (range, next, &asma->unpinned_list, unpinned) {
if ( F_42 ( V_2 , V_15 ) )
break;
if ( F_46 ( V_2 , V_15 , V_16 ) )
return 0 ;
if ( F_43 ( V_2 , V_15 , V_16 ) ) {
V_15 = F_47 ( T_1 , V_2 -> V_15 , V_15 ) ,
V_16 = F_48 ( T_1 , V_2 -> V_16 , V_16 ) ;
V_9 |= V_2 -> V_9 ;
F_10 ( V_2 ) ;
goto V_81;
}
}
return F_6 ( V_7 , V_2 , V_9 , V_15 , V_16 ) ;
}
static int F_49 ( struct V_6 * V_7 , T_1 V_15 ,
T_1 V_16 )
{
struct V_1 * V_2 ;
int V_21 = V_82 ;
F_50 (range, &asma->unpinned_list, unpinned) {
if ( F_42 ( V_2 , V_15 ) )
break;
if ( F_43 ( V_2 , V_15 , V_16 ) ) {
V_21 = V_83 ;
break;
}
}
return V_21 ;
}
static int F_51 ( struct V_6 * V_7 , unsigned long V_84 ,
void T_3 * V_85 )
{
struct F_41 V_86 ;
T_1 V_15 , V_16 ;
int V_21 = - V_44 ;
if ( F_8 ( ! V_7 -> V_20 ) )
return - V_44 ;
if ( F_8 ( F_52 ( & V_86 , V_85 , sizeof( V_86 ) ) ) )
return - V_79 ;
if ( ! V_86 . V_34 )
V_86 . V_34 = F_53 ( V_7 -> V_36 ) - V_86 . V_42 ;
if ( F_8 ( ( V_86 . V_42 | V_86 . V_34 ) & ~ V_87 ) )
return - V_44 ;
if ( F_8 ( ( ( V_88 ) - 1 ) - V_86 . V_42 < V_86 . V_34 ) )
return - V_44 ;
if ( F_8 ( F_53 ( V_7 -> V_36 ) < V_86 . V_42 + V_86 . V_34 ) )
return - V_44 ;
V_15 = V_86 . V_42 / V_69 ;
V_16 = V_15 + ( V_86 . V_34 / V_69 ) - 1 ;
F_17 ( & V_32 ) ;
switch ( V_84 ) {
case V_89 :
V_21 = F_41 ( V_7 , V_15 , V_16 ) ;
break;
case V_90 :
V_21 = F_45 ( V_7 , V_15 , V_16 ) ;
break;
case V_91 :
V_21 = F_49 ( V_7 , V_15 , V_16 ) ;
break;
}
F_19 ( & V_32 ) ;
return V_21 ;
}
static long F_54 ( struct V_20 * V_20 , unsigned int V_84 , unsigned long V_92 )
{
struct V_6 * V_7 = V_20 -> V_29 ;
long V_21 = - V_93 ;
switch ( V_84 ) {
case V_94 :
V_21 = F_37 ( V_7 , ( void T_3 * ) V_92 ) ;
break;
case V_95 :
V_21 = F_39 ( V_7 , ( void T_3 * ) V_92 ) ;
break;
case V_96 :
V_21 = - V_44 ;
if ( ! V_7 -> V_20 ) {
V_21 = 0 ;
V_7 -> V_36 = ( T_1 ) V_92 ;
}
break;
case V_97 :
V_21 = V_7 -> V_36 ;
break;
case V_98 :
V_21 = F_36 ( V_7 , V_92 ) ;
break;
case V_99 :
V_21 = V_7 -> V_27 ;
break;
case V_89 :
case V_90 :
case V_91 :
V_21 = F_51 ( V_7 , V_84 , ( void T_3 * ) V_92 ) ;
break;
case V_100 :
V_21 = - V_56 ;
if ( F_55 ( V_101 ) ) {
struct V_63 V_64 = {
. V_66 = V_13 ,
. V_73 = V_102 ,
} ;
V_21 = F_35 ( & V_103 , & V_64 ) ;
F_56 ( V_64 . V_104 ) ;
F_33 ( & V_103 , & V_64 ) ;
}
break;
}
return V_21 ;
}
static long F_57 ( struct V_20 * V_20 , unsigned int V_84 ,
unsigned long V_92 )
{
switch ( V_84 ) {
case V_105 :
V_84 = V_96 ;
break;
case V_106 :
V_84 = V_98 ;
break;
}
return F_54 ( V_20 , V_84 , V_92 ) ;
}
static int T_6 F_58 ( void )
{
int V_21 ;
V_22 = F_59 ( L_1 ,
sizeof( struct V_6 ) ,
0 , 0 , NULL ) ;
if ( F_8 ( ! V_22 ) ) {
F_60 ( L_2 ) ;
return - V_14 ;
}
V_12 = F_59 ( L_3 ,
sizeof( struct V_1 ) ,
0 , 0 , NULL ) ;
if ( F_8 ( ! V_12 ) ) {
F_60 ( L_2 ) ;
return - V_14 ;
}
V_21 = F_61 ( & V_107 ) ;
if ( F_8 ( V_21 ) ) {
F_60 ( L_4 ) ;
return V_21 ;
}
F_62 ( & V_103 ) ;
F_63 ( L_5 ) ;
return 0 ;
}
static void T_7 F_64 ( void )
{
int V_21 ;
F_65 ( & V_103 ) ;
V_21 = F_66 ( & V_107 ) ;
if ( F_8 ( V_21 ) )
F_60 ( L_6 ) ;
F_67 ( V_12 ) ;
F_67 ( V_22 ) ;
F_63 ( L_7 ) ;
}
