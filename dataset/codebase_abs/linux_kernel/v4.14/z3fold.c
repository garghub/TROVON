static int F_1 ( T_1 V_1 )
{
return ( V_1 + V_2 - 1 ) >> V_3 ;
}
static struct V_4 * F_2 ( struct V_5 * V_5 ,
struct V_6 * V_7 )
{
struct V_4 * V_8 = F_3 ( V_5 ) ;
F_4 ( & V_5 -> V_9 ) ;
F_5 ( V_10 , & V_5 -> V_11 ) ;
F_5 ( V_12 , & V_5 -> V_11 ) ;
F_5 ( V_13 , & V_5 -> V_11 ) ;
F_5 ( V_14 , & V_5 -> V_11 ) ;
F_6 ( & V_8 -> V_15 ) ;
F_7 ( & V_8 -> V_16 ) ;
V_8 -> V_17 = 0 ;
V_8 -> V_18 = 0 ;
V_8 -> V_19 = 0 ;
V_8 -> V_20 = 0 ;
V_8 -> V_21 = 0 ;
V_8 -> V_22 = - 1 ;
V_8 -> V_7 = V_7 ;
F_4 ( & V_8 -> V_23 ) ;
F_8 ( & V_8 -> V_24 , V_25 ) ;
return V_8 ;
}
static void F_9 ( struct V_5 * V_5 )
{
F_10 ( V_5 ) ;
}
static inline void F_11 ( struct V_4 * V_8 )
{
F_12 ( & V_8 -> V_15 ) ;
}
static inline int F_13 ( struct V_4 * V_8 )
{
return F_14 ( & V_8 -> V_15 ) ;
}
static inline void F_15 ( struct V_4 * V_8 )
{
F_16 ( & V_8 -> V_15 ) ;
}
static unsigned long F_17 ( struct V_4 * V_8 , enum V_23 V_26 )
{
unsigned long V_27 ;
V_27 = ( unsigned long ) V_8 ;
if ( V_26 != V_28 )
V_27 += ( V_26 + V_8 -> V_20 ) & V_29 ;
return V_27 ;
}
static struct V_4 * F_18 ( unsigned long V_27 )
{
return (struct V_4 * ) ( V_27 & V_30 ) ;
}
static enum V_23 F_19 ( unsigned long V_27 )
{
struct V_4 * V_8 = F_18 ( V_27 ) ;
return ( V_27 - V_8 -> V_20 ) & V_29 ;
}
static void F_20 ( struct V_4 * V_8 , bool V_31 )
{
struct V_5 * V_5 = F_21 ( V_8 ) ;
struct V_6 * V_7 = V_8 -> V_7 ;
F_22 ( ! F_23 ( & V_8 -> V_23 ) ) ;
F_24 ( V_14 , & V_5 -> V_11 ) ;
F_5 ( V_13 , & V_5 -> V_11 ) ;
F_12 ( & V_7 -> V_32 ) ;
if ( ! F_23 ( & V_5 -> V_9 ) )
F_25 ( & V_5 -> V_9 ) ;
F_16 ( & V_7 -> V_32 ) ;
if ( V_31 )
F_15 ( V_8 ) ;
F_12 ( & V_7 -> V_33 ) ;
F_26 ( & V_8 -> V_23 , & V_7 -> V_34 ) ;
F_27 ( V_7 -> V_35 , & V_7 -> V_24 ) ;
F_16 ( & V_7 -> V_33 ) ;
}
static void F_28 ( struct V_36 * V_37 )
{
struct V_4 * V_8 = F_29 ( V_37 , struct V_4 ,
V_16 ) ;
F_22 ( F_13 ( V_8 ) ) ;
F_20 ( V_8 , true ) ;
}
static void F_30 ( struct V_36 * V_37 )
{
struct V_4 * V_8 = F_29 ( V_37 , struct V_4 ,
V_16 ) ;
F_12 ( & V_8 -> V_7 -> V_32 ) ;
F_31 ( & V_8 -> V_23 ) ;
F_16 ( & V_8 -> V_7 -> V_32 ) ;
F_22 ( F_13 ( V_8 ) ) ;
F_20 ( V_8 , true ) ;
}
static void F_32 ( struct V_38 * V_39 )
{
struct V_6 * V_7 = F_29 ( V_39 , struct V_6 , V_24 ) ;
F_12 ( & V_7 -> V_33 ) ;
while ( ! F_23 ( & V_7 -> V_34 ) ) {
struct V_4 * V_8 = F_33 ( & V_7 -> V_34 ,
struct V_4 , V_23 ) ;
struct V_5 * V_5 = F_21 ( V_8 ) ;
F_25 ( & V_8 -> V_23 ) ;
if ( F_22 ( ! F_34 ( V_14 , & V_5 -> V_11 ) ) )
continue;
F_16 ( & V_7 -> V_33 ) ;
F_35 ( & V_8 -> V_24 ) ;
F_9 ( V_5 ) ;
F_36 () ;
F_12 ( & V_7 -> V_33 ) ;
}
F_16 ( & V_7 -> V_33 ) ;
}
static int F_37 ( struct V_4 * V_8 )
{
int V_40 ;
if ( V_8 -> V_18 != 0 ) {
int V_41 = V_8 -> V_17 ?
0 : V_8 -> V_21 - V_42 ;
int V_43 = V_8 -> V_19 ?
0 : V_44 -
( V_8 -> V_21 + V_8 -> V_18 ) ;
V_40 = F_38 ( V_41 , V_43 ) ;
} else
V_40 = V_45 - V_8 -> V_17 - V_8 -> V_19 ;
return V_40 ;
}
static inline void * F_39 ( struct V_4 * V_8 ,
unsigned short V_46 )
{
void * V_47 = V_8 ;
return memmove ( V_47 + ( V_46 << V_3 ) ,
V_47 + ( V_8 -> V_21 << V_3 ) ,
V_8 -> V_18 << V_3 ) ;
}
static int F_40 ( struct V_4 * V_8 )
{
struct V_5 * V_5 = F_21 ( V_8 ) ;
if ( F_34 ( V_12 , & V_5 -> V_11 ) )
return 0 ;
if ( V_8 -> V_18 == 0 )
return 0 ;
if ( V_8 -> V_17 == 0 && V_8 -> V_19 == 0 ) {
F_39 ( V_8 , V_42 ) ;
V_8 -> V_17 = V_8 -> V_18 ;
V_8 -> V_18 = 0 ;
V_8 -> V_21 = 0 ;
V_8 -> V_20 ++ ;
return 1 ;
}
if ( V_8 -> V_17 != 0 && V_8 -> V_19 == 0 &&
V_8 -> V_21 - ( V_8 -> V_17 + V_42 ) >=
V_48 ) {
F_39 ( V_8 , V_8 -> V_17 + V_42 ) ;
V_8 -> V_21 = V_8 -> V_17 + V_42 ;
return 1 ;
} else if ( V_8 -> V_19 != 0 && V_8 -> V_17 == 0 &&
V_44 - ( V_8 -> V_19 + V_8 -> V_21
+ V_8 -> V_18 ) >=
V_48 ) {
unsigned short V_49 = V_44 - V_8 -> V_19 -
V_8 -> V_18 ;
F_39 ( V_8 , V_49 ) ;
V_8 -> V_21 = V_49 ;
return 1 ;
}
return 0 ;
}
static void F_41 ( struct V_4 * V_8 , bool V_31 )
{
struct V_6 * V_7 = V_8 -> V_7 ;
struct V_5 * V_5 ;
struct V_50 * V_51 ;
int V_52 ;
V_5 = F_21 ( V_8 ) ;
if ( V_31 )
F_22 ( F_13 ( V_8 ) ) ;
else
F_11 ( V_8 ) ;
if ( F_34 ( V_14 , & V_5 -> V_11 ) ||
! F_42 ( V_13 , & V_5 -> V_11 ) ) {
F_15 ( V_8 ) ;
return;
}
F_12 ( & V_7 -> V_32 ) ;
F_31 ( & V_8 -> V_23 ) ;
F_16 ( & V_7 -> V_32 ) ;
F_40 ( V_8 ) ;
V_51 = F_43 ( V_7 -> V_51 ) ;
V_52 = F_37 ( V_8 ) ;
if ( V_52 < V_45 &&
( ! V_8 -> V_17 || ! V_8 -> V_18 ||
! V_8 -> V_19 ) ) {
F_12 ( & V_7 -> V_32 ) ;
F_26 ( & V_8 -> V_23 , & V_51 [ V_52 ] ) ;
F_16 ( & V_7 -> V_32 ) ;
V_8 -> V_22 = F_44 () ;
}
F_45 ( V_7 -> V_51 ) ;
F_15 ( V_8 ) ;
}
static void V_25 ( struct V_38 * V_39 )
{
struct V_4 * V_8 = F_29 ( V_39 , struct V_4 ,
V_24 ) ;
F_41 ( V_8 , false ) ;
}
static struct V_6 * F_46 ( const char * V_53 , T_2 V_54 ,
const struct V_55 * V_56 )
{
struct V_6 * V_7 = NULL ;
int V_57 , V_22 ;
V_7 = F_47 ( sizeof( struct V_6 ) , V_54 ) ;
if ( ! V_7 )
goto V_58;
F_6 ( & V_7 -> V_32 ) ;
F_6 ( & V_7 -> V_33 ) ;
V_7 -> V_51 = F_48 ( sizeof( struct V_50 ) * V_45 , 2 ) ;
F_49 (cpu) {
struct V_50 * V_51 =
F_50 ( V_7 -> V_51 , V_22 ) ;
F_51 (i, 0 )
F_4 ( & V_51 [ V_57 ] ) ;
}
F_4 ( & V_7 -> V_9 ) ;
F_4 ( & V_7 -> V_34 ) ;
F_52 ( & V_7 -> V_59 , 0 ) ;
V_7 -> V_53 = V_53 ;
V_7 -> V_60 = F_53 ( V_7 -> V_53 ) ;
if ( ! V_7 -> V_60 )
goto V_58;
V_7 -> V_35 = F_53 ( V_7 -> V_53 ) ;
if ( ! V_7 -> V_35 )
goto V_61;
F_8 ( & V_7 -> V_24 , F_32 ) ;
V_7 -> V_56 = V_56 ;
return V_7 ;
V_61:
F_54 ( V_7 -> V_60 ) ;
V_58:
F_55 ( V_7 ) ;
return NULL ;
}
static void F_56 ( struct V_6 * V_7 )
{
F_54 ( V_7 -> V_35 ) ;
F_54 ( V_7 -> V_60 ) ;
F_55 ( V_7 ) ;
}
static int F_57 ( struct V_6 * V_7 , T_1 V_1 , T_2 V_54 ,
unsigned long * V_27 )
{
int V_62 = 0 , V_57 , V_63 ;
struct V_4 * V_8 = NULL ;
struct V_5 * V_5 = NULL ;
enum V_23 V_26 ;
bool V_64 = ( V_54 & V_65 ) == V_65 ;
if ( ! V_1 || ( V_54 & V_66 ) )
return - V_67 ;
if ( V_1 > V_68 )
return - V_69 ;
if ( V_1 > V_68 - V_70 - V_2 )
V_26 = V_28 ;
else {
struct V_50 * V_51 ;
V_62 = F_1 ( V_1 ) ;
V_71:
V_51 = F_43 ( V_7 -> V_51 ) ;
F_51 (i, chunks) {
struct V_50 * V_72 = & V_51 [ V_57 ] ;
V_8 = F_58 ( F_59 ( V_72 ) ,
struct V_4 , V_23 ) ;
if ( ! V_8 )
continue;
F_12 ( & V_7 -> V_32 ) ;
V_72 = & V_51 [ V_57 ] ;
if ( F_60 ( V_8 != F_33 ( F_59 ( V_72 ) ,
struct V_4 , V_23 ) ) ||
! F_13 ( V_8 ) ) {
F_16 ( & V_7 -> V_32 ) ;
F_45 ( V_7 -> V_51 ) ;
goto V_71;
}
F_31 ( & V_8 -> V_23 ) ;
V_8 -> V_22 = - 1 ;
F_16 ( & V_7 -> V_32 ) ;
V_5 = F_21 ( V_8 ) ;
if ( F_34 ( V_13 , & V_5 -> V_11 ) ) {
F_15 ( V_8 ) ;
V_8 = NULL ;
F_45 ( V_7 -> V_51 ) ;
if ( V_64 )
F_36 () ;
goto V_71;
}
F_61 ( & V_8 -> V_16 ) ;
break;
}
F_45 ( V_7 -> V_51 ) ;
if ( V_8 ) {
if ( V_8 -> V_17 == 0 ) {
if ( V_8 -> V_18 != 0 &&
V_62 >= V_8 -> V_21 )
V_26 = V_73 ;
else
V_26 = V_74 ;
} else if ( V_8 -> V_19 == 0 )
V_26 = V_73 ;
else if ( V_8 -> V_18 == 0 )
V_26 = V_75 ;
else {
if ( F_62 ( & V_8 -> V_16 ,
F_28 ) )
F_63 ( & V_7 -> V_59 ) ;
else
F_15 ( V_8 ) ;
F_64 ( L_1 ) ;
F_22 ( 1 ) ;
goto V_71;
}
goto V_76;
}
V_26 = V_74 ;
}
F_12 ( & V_7 -> V_33 ) ;
V_8 = F_58 ( & V_7 -> V_34 ,
struct V_4 , V_23 ) ;
if ( V_8 && ( V_64 || ! F_65 ( & V_8 -> V_24 ) ) ) {
F_25 ( & V_8 -> V_23 ) ;
F_16 ( & V_7 -> V_33 ) ;
if ( V_64 )
F_35 ( & V_8 -> V_24 ) ;
V_5 = F_21 ( V_8 ) ;
} else {
F_16 ( & V_7 -> V_33 ) ;
V_5 = F_66 ( V_54 ) ;
}
if ( ! V_5 )
return - V_77 ;
F_67 ( & V_7 -> V_59 ) ;
V_8 = F_2 ( V_5 , V_7 ) ;
if ( V_26 == V_28 ) {
F_24 ( V_10 , & V_5 -> V_11 ) ;
goto V_78;
}
F_11 ( V_8 ) ;
V_76:
if ( V_26 == V_74 )
V_8 -> V_17 = V_62 ;
else if ( V_26 == V_73 )
V_8 -> V_19 = V_62 ;
else {
V_8 -> V_18 = V_62 ;
V_8 -> V_21 = V_8 -> V_17 + V_42 ;
}
if ( V_8 -> V_17 == 0 || V_8 -> V_19 == 0 ||
V_8 -> V_18 == 0 ) {
struct V_50 * V_51 = F_43 ( V_7 -> V_51 ) ;
V_63 = F_37 ( V_8 ) ;
F_12 ( & V_7 -> V_32 ) ;
F_26 ( & V_8 -> V_23 , & V_51 [ V_63 ] ) ;
F_16 ( & V_7 -> V_32 ) ;
V_8 -> V_22 = F_44 () ;
F_45 ( V_7 -> V_51 ) ;
}
V_78:
F_12 ( & V_7 -> V_32 ) ;
if ( ! F_23 ( & V_5 -> V_9 ) )
F_25 ( & V_5 -> V_9 ) ;
F_26 ( & V_5 -> V_9 , & V_7 -> V_9 ) ;
* V_27 = F_17 ( V_8 , V_26 ) ;
F_16 ( & V_7 -> V_32 ) ;
if ( V_26 != V_28 )
F_15 ( V_8 ) ;
return 0 ;
}
static void F_68 ( struct V_6 * V_7 , unsigned long V_27 )
{
struct V_4 * V_8 ;
struct V_5 * V_5 ;
enum V_23 V_26 ;
V_8 = F_18 ( V_27 ) ;
V_5 = F_21 ( V_8 ) ;
if ( F_34 ( V_10 , & V_5 -> V_11 ) ) {
V_26 = V_28 ;
} else {
F_11 ( V_8 ) ;
V_26 = F_19 ( V_27 ) ;
switch ( V_26 ) {
case V_74 :
V_8 -> V_17 = 0 ;
break;
case V_75 :
V_8 -> V_18 = 0 ;
V_8 -> V_21 = 0 ;
break;
case V_73 :
V_8 -> V_19 = 0 ;
break;
default:
F_64 ( L_2 , V_79 , V_26 ) ;
F_22 ( 1 ) ;
F_15 ( V_8 ) ;
return;
}
}
if ( V_26 == V_28 ) {
F_12 ( & V_7 -> V_32 ) ;
F_25 ( & V_5 -> V_9 ) ;
F_16 ( & V_7 -> V_32 ) ;
F_9 ( V_5 ) ;
F_63 ( & V_7 -> V_59 ) ;
return;
}
if ( F_62 ( & V_8 -> V_16 , F_30 ) ) {
F_63 ( & V_7 -> V_59 ) ;
return;
}
if ( F_69 ( V_13 , & V_5 -> V_11 ) ) {
F_15 ( V_8 ) ;
return;
}
if ( V_8 -> V_22 < 0 || ! F_70 ( V_8 -> V_22 ) ) {
F_12 ( & V_7 -> V_32 ) ;
F_31 ( & V_8 -> V_23 ) ;
F_16 ( & V_7 -> V_32 ) ;
V_8 -> V_22 = - 1 ;
F_41 ( V_8 , true ) ;
return;
}
F_71 ( V_8 -> V_22 , V_7 -> V_60 , & V_8 -> V_24 ) ;
F_15 ( V_8 ) ;
}
static int F_72 ( struct V_6 * V_7 , unsigned int V_80 )
{
int V_57 , V_81 = 0 ;
struct V_4 * V_8 = NULL ;
struct V_5 * V_5 = NULL ;
struct V_50 * V_82 ;
unsigned long V_83 = 0 , V_84 = 0 , V_85 = 0 ;
F_12 ( & V_7 -> V_32 ) ;
if ( ! V_7 -> V_56 || ! V_7 -> V_56 -> V_86 || V_80 == 0 ) {
F_16 ( & V_7 -> V_32 ) ;
return - V_67 ;
}
for ( V_57 = 0 ; V_57 < V_80 ; V_57 ++ ) {
if ( F_23 ( & V_7 -> V_9 ) ) {
F_16 ( & V_7 -> V_32 ) ;
return - V_67 ;
}
F_73 (pos, &pool->lru) {
V_5 = F_74 ( V_82 , struct V_5 , V_9 ) ;
if ( F_34 ( V_10 , & V_5 -> V_11 ) )
break;
V_8 = F_3 ( V_5 ) ;
if ( ! F_13 ( V_8 ) )
continue;
F_61 ( & V_8 -> V_16 ) ;
F_31 ( & V_8 -> V_23 ) ;
V_8 -> V_22 = - 1 ;
}
F_31 ( & V_5 -> V_9 ) ;
F_16 ( & V_7 -> V_32 ) ;
if ( ! F_34 ( V_10 , & V_5 -> V_11 ) ) {
V_83 = 0 ;
V_85 = 0 ;
V_84 = 0 ;
if ( V_8 -> V_17 )
V_83 = F_17 ( V_8 , V_74 ) ;
if ( V_8 -> V_18 )
V_84 = F_17 ( V_8 , V_75 ) ;
if ( V_8 -> V_19 )
V_85 = F_17 ( V_8 , V_73 ) ;
F_15 ( V_8 ) ;
} else {
V_83 = F_17 ( V_8 , V_28 ) ;
V_85 = V_84 = 0 ;
}
if ( V_84 ) {
V_81 = V_7 -> V_56 -> V_86 ( V_7 , V_84 ) ;
if ( V_81 )
goto V_87;
}
if ( V_83 ) {
V_81 = V_7 -> V_56 -> V_86 ( V_7 , V_83 ) ;
if ( V_81 )
goto V_87;
}
if ( V_85 ) {
V_81 = V_7 -> V_56 -> V_86 ( V_7 , V_85 ) ;
if ( V_81 )
goto V_87;
}
V_87:
F_12 ( & V_7 -> V_32 ) ;
if ( F_34 ( V_10 , & V_5 -> V_11 ) ) {
if ( V_81 == 0 ) {
F_16 ( & V_7 -> V_32 ) ;
F_9 ( V_5 ) ;
return 0 ;
}
} else if ( F_62 ( & V_8 -> V_16 , V_88 ) ) {
F_63 ( & V_7 -> V_59 ) ;
F_16 ( & V_7 -> V_32 ) ;
return 0 ;
}
F_26 ( & V_5 -> V_9 , & V_7 -> V_9 ) ;
}
F_16 ( & V_7 -> V_32 ) ;
return - V_89 ;
}
static void * F_75 ( struct V_6 * V_7 , unsigned long V_27 )
{
struct V_4 * V_8 ;
struct V_5 * V_5 ;
void * V_90 ;
enum V_23 V_23 ;
V_8 = F_18 ( V_27 ) ;
V_90 = V_8 ;
V_5 = F_21 ( V_8 ) ;
if ( F_34 ( V_10 , & V_5 -> V_11 ) )
goto V_58;
F_11 ( V_8 ) ;
V_23 = F_19 ( V_27 ) ;
switch ( V_23 ) {
case V_74 :
V_90 += V_70 ;
break;
case V_75 :
V_90 += V_8 -> V_21 << V_3 ;
F_24 ( V_12 , & V_5 -> V_11 ) ;
break;
case V_73 :
V_90 += V_68 - ( V_8 -> V_19 << V_3 ) ;
break;
default:
F_64 ( L_3 , V_23 ) ;
F_22 ( 1 ) ;
V_90 = NULL ;
break;
}
F_15 ( V_8 ) ;
V_58:
return V_90 ;
}
static void F_76 ( struct V_6 * V_7 , unsigned long V_27 )
{
struct V_4 * V_8 ;
struct V_5 * V_5 ;
enum V_23 V_23 ;
V_8 = F_18 ( V_27 ) ;
V_5 = F_21 ( V_8 ) ;
if ( F_34 ( V_10 , & V_5 -> V_11 ) )
return;
F_11 ( V_8 ) ;
V_23 = F_19 ( V_27 ) ;
if ( V_23 == V_75 )
F_5 ( V_12 , & V_5 -> V_11 ) ;
F_15 ( V_8 ) ;
}
static T_3 F_77 ( struct V_6 * V_7 )
{
return F_78 ( & V_7 -> V_59 ) ;
}
static int F_79 ( struct V_6 * V_7 , unsigned long V_27 )
{
if ( V_7 -> V_91 && V_7 -> V_92 && V_7 -> V_92 -> V_86 )
return V_7 -> V_92 -> V_86 ( V_7 -> V_91 , V_27 ) ;
else
return - V_93 ;
}
static void * F_80 ( const char * V_53 , T_2 V_54 ,
const struct V_92 * V_92 ,
struct V_91 * V_91 )
{
struct V_6 * V_7 ;
V_7 = F_46 ( V_53 , V_54 ,
V_92 ? & V_94 : NULL ) ;
if ( V_7 ) {
V_7 -> V_91 = V_91 ;
V_7 -> V_92 = V_92 ;
}
return V_7 ;
}
static void F_81 ( void * V_7 )
{
F_56 ( V_7 ) ;
}
static int F_82 ( void * V_7 , T_1 V_1 , T_2 V_54 ,
unsigned long * V_27 )
{
return F_57 ( V_7 , V_1 , V_54 , V_27 ) ;
}
static void F_83 ( void * V_7 , unsigned long V_27 )
{
F_68 ( V_7 , V_27 ) ;
}
static int F_84 ( void * V_7 , unsigned int V_95 ,
unsigned int * V_96 )
{
unsigned int V_97 = 0 ;
int V_81 = - V_67 ;
while ( V_97 < V_95 ) {
V_81 = F_72 ( V_7 , 8 ) ;
if ( V_81 < 0 )
break;
V_97 ++ ;
}
if ( V_96 )
* V_96 = V_97 ;
return V_81 ;
}
static void * F_85 ( void * V_7 , unsigned long V_27 ,
enum V_98 V_99 )
{
return F_75 ( V_7 , V_27 ) ;
}
static void F_86 ( void * V_7 , unsigned long V_27 )
{
F_76 ( V_7 , V_27 ) ;
}
static T_3 F_87 ( void * V_7 )
{
return F_77 ( V_7 ) * V_68 ;
}
static int T_4 F_88 ( void )
{
F_89 ( V_70 > V_68 ) ;
F_90 ( & V_100 ) ;
return 0 ;
}
static void T_5 F_91 ( void )
{
F_92 ( & V_100 ) ;
}
