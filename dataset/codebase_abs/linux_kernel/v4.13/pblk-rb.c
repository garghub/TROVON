void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 , * V_5 ;
F_2 ( & V_6 ) ;
F_3 (p, t, &rb->pages, list) {
F_4 ( ( unsigned long ) F_5 ( V_4 -> V_7 ) , V_4 -> V_8 ) ;
F_6 ( & V_4 -> V_9 ) ;
F_7 ( V_4 ) ;
}
F_8 ( & V_6 ) ;
}
int F_9 ( struct V_1 * V_2 , struct V_10 * V_11 ,
unsigned int V_12 , unsigned int V_13 )
{
struct V_14 * V_14 = F_10 ( V_2 , struct V_14 , V_15 ) ;
unsigned int V_16 = 0 ;
unsigned int V_17 = V_12 ;
unsigned int V_18 = V_19 - 1 ;
unsigned int V_8 , V_20 ;
F_2 ( & V_6 ) ;
V_2 -> V_21 = V_11 ;
V_2 -> V_22 = ( 1 << V_13 ) ;
V_2 -> V_23 = ( 1 << V_12 ) ;
V_2 -> V_24 = V_2 -> V_25 = V_2 -> V_26 = V_2 -> V_27 = 0 ;
V_2 -> V_28 = V_29 ;
F_11 ( & V_2 -> V_30 ) ;
F_11 ( & V_2 -> V_31 ) ;
F_12 ( & V_2 -> V_7 ) ;
if ( V_17 >= V_18 ) {
V_8 = V_18 ;
V_20 = ( 1 << ( V_17 - V_18 ) ) ;
} else {
V_8 = V_17 ;
V_20 = 1 ;
}
do {
struct V_10 * V_32 ;
struct V_3 * V_33 ;
void * V_34 ;
unsigned long V_35 ;
int V_36 ;
V_33 = F_13 ( sizeof( struct V_3 ) , V_37 ) ;
if ( ! V_33 ) {
F_8 ( & V_6 ) ;
return - V_38 ;
}
V_33 -> V_8 = V_8 ;
V_33 -> V_7 = F_14 ( V_37 , V_8 ) ;
if ( ! V_33 -> V_7 ) {
F_7 ( V_33 ) ;
F_1 ( V_2 ) ;
F_8 ( & V_6 ) ;
return - V_38 ;
}
V_34 = F_5 ( V_33 -> V_7 ) ;
V_32 = & V_2 -> V_21 [ V_16 ] ;
V_32 -> V_39 = V_34 ;
V_32 -> V_40 = F_15 ( V_16 ++ ) ;
V_32 -> V_41 . V_42 = V_43 ;
V_35 = ( 1 << V_8 ) ;
for ( V_36 = 1 ; V_36 < V_35 ; V_36 ++ ) {
V_32 = & V_2 -> V_21 [ V_16 ] ;
V_32 -> V_40 = F_15 ( V_16 ++ ) ;
V_32 -> V_39 = V_34 + ( V_36 * V_2 -> V_22 ) ;
V_32 -> V_41 . V_42 = V_43 ;
F_16 ( & V_32 -> V_41 . V_44 ) ;
}
F_17 ( & V_33 -> V_9 , & V_2 -> V_7 ) ;
V_20 -- ;
} while ( V_20 > 0 );
F_8 ( & V_6 ) ;
#ifdef F_18
F_19 ( & V_2 -> V_45 , 0 ) ;
#endif
F_20 ( & V_14 -> V_46 , V_2 -> V_23 ) ;
return 0 ;
}
unsigned int F_21 ( unsigned int V_23 )
{
return ( 1 << F_22 ( F_23 ( V_23 ) , 7 ) ) ;
}
void * F_24 ( struct V_1 * V_2 )
{
return V_2 -> V_21 ;
}
static void F_25 ( struct V_47 * V_41 )
{
int V_42 ;
V_48:
V_42 = F_26 ( V_41 -> V_42 ) ;
if ( ! ( V_42 & V_49 ) )
goto V_48;
F_27 ( & V_41 -> V_42 , V_43 ) ;
F_28 ( & V_41 -> V_50 ) ;
V_41 -> V_51 = V_52 ;
}
static unsigned int F_29 ( struct V_1 * V_2 )
{
unsigned int V_24 = F_26 ( V_2 -> V_24 ) ;
unsigned int V_26 = F_26 ( V_2 -> V_26 ) ;
return F_30 ( V_2 , V_24 , V_26 , V_2 -> V_23 ) ;
}
unsigned int F_31 ( struct V_1 * V_2 )
{
unsigned int V_24 = F_26 ( V_2 -> V_24 ) ;
unsigned int V_25 = F_26 ( V_2 -> V_25 ) ;
return F_32 ( V_24 , V_25 , V_2 -> V_23 ) ;
}
unsigned int F_33 ( struct V_1 * V_2 )
{
unsigned int V_24 = F_26 ( V_2 -> V_24 ) ;
unsigned int V_26 = F_26 ( V_2 -> V_26 ) ;
return F_32 ( V_24 , V_26 , V_2 -> V_23 ) ;
}
unsigned int F_34 ( struct V_1 * V_2 , unsigned int V_23 )
{
unsigned int V_25 ;
V_25 = F_26 ( V_2 -> V_25 ) ;
F_27 ( & V_2 -> V_25 ,
( V_25 + V_23 ) & ( V_2 -> V_23 - 1 ) ) ;
return V_25 ;
}
static int F_35 ( struct V_1 * V_2 , unsigned int * V_53 ,
unsigned int V_54 )
{
struct V_14 * V_14 = F_10 ( V_2 , struct V_14 , V_15 ) ;
struct V_55 * line ;
struct V_10 * V_32 ;
struct V_47 * V_41 ;
unsigned int V_56 = 0 , V_57 = 0 ;
unsigned int V_36 ;
int V_42 ;
for ( V_36 = 0 ; V_36 < V_54 ; V_36 ++ ) {
V_32 = & V_2 -> V_21 [ * V_53 ] ;
V_41 = & V_32 -> V_41 ;
V_42 = F_26 ( V_32 -> V_41 . V_42 ) ;
if ( V_42 & V_58 )
V_56 ++ ;
else if ( V_42 & V_59 )
V_57 ++ ;
else
F_36 ( 1 , L_1 ) ;
F_37 ( V_14 , V_41 -> V_51 , V_41 -> V_50 ,
V_32 -> V_40 ) ;
line = & V_14 -> V_60 [ F_38 ( V_41 -> V_50 ) ] ;
F_39 ( & line -> V_61 , V_62 ) ;
F_25 ( V_41 ) ;
* V_53 = ( * V_53 + 1 ) & ( V_2 -> V_23 - 1 ) ;
}
F_40 ( & V_14 -> V_46 , V_56 , V_57 ) ;
return 0 ;
}
static int F_41 ( struct V_1 * V_2 , unsigned int V_23 ,
unsigned int V_24 , unsigned int V_26 )
{
unsigned int V_63 , V_64 ;
int V_65 = 0 ;
F_42 ( & V_2 -> V_30 ) ;
V_63 = F_30 ( V_2 , V_24 , V_2 -> V_27 , V_2 -> V_23 ) ;
if ( V_63 > V_23 )
goto V_66;
V_64 = V_23 - V_63 ;
V_65 = F_35 ( V_2 , & V_2 -> V_27 , V_64 ) ;
V_66:
return V_65 ;
}
void F_43 ( struct V_1 * V_2 )
{
unsigned int V_26 ;
unsigned int V_54 ;
F_44 ( & V_2 -> V_30 ) ;
V_26 = F_45 ( & V_2 -> V_26 ) ;
V_54 = F_32 ( V_26 , V_2 -> V_27 , V_2 -> V_23 ) ;
F_35 ( V_2 , & V_2 -> V_27 , V_54 ) ;
F_46 ( & V_2 -> V_30 ) ;
}
static void F_47 ( struct V_1 * V_2 , void * V_39 ,
struct V_47 V_41 ,
struct V_10 * V_32 )
{
memcpy ( V_32 -> V_39 , V_39 , V_2 -> V_22 ) ;
V_32 -> V_41 . V_51 = V_41 . V_51 ;
V_32 -> V_41 . V_50 = V_41 . V_50 ;
}
void F_48 ( struct V_1 * V_2 , void * V_39 ,
struct V_47 V_41 , unsigned int V_67 )
{
struct V_14 * V_14 = F_10 ( V_2 , struct V_14 , V_15 ) ;
struct V_10 * V_32 ;
int V_42 ;
V_32 = & V_2 -> V_21 [ V_67 ] ;
V_42 = F_26 ( V_32 -> V_41 . V_42 ) ;
#ifdef F_18
F_49 ( ! ( V_42 & V_43 ) ) ;
#endif
F_47 ( V_2 , V_39 , V_41 , V_32 ) ;
F_50 ( V_14 , V_41 . V_51 , V_32 -> V_40 ) ;
V_42 = V_41 . V_42 | V_68 ;
F_27 ( & V_32 -> V_41 . V_42 , V_42 ) ;
}
void F_51 ( struct V_1 * V_2 , void * V_39 ,
struct V_47 V_41 , struct V_55 * V_69 ,
unsigned int V_67 )
{
struct V_14 * V_14 = F_10 ( V_2 , struct V_14 , V_15 ) ;
struct V_10 * V_32 ;
int V_42 ;
V_32 = & V_2 -> V_21 [ V_67 ] ;
V_42 = F_26 ( V_32 -> V_41 . V_42 ) ;
#ifdef F_18
F_49 ( ! ( V_42 & V_43 ) ) ;
#endif
F_47 ( V_2 , V_39 , V_41 , V_32 ) ;
if ( ! F_52 ( V_14 , V_41 . V_51 , V_32 -> V_40 , V_69 ) )
V_32 -> V_41 . V_51 = V_52 ;
V_42 = V_41 . V_42 | V_68 ;
F_27 ( & V_32 -> V_41 . V_42 , V_42 ) ;
}
static int F_53 ( struct V_1 * V_2 , struct V_70 * V_70 ,
unsigned int V_71 )
{
struct V_10 * V_32 ;
unsigned int V_25 , V_28 ;
int V_42 ;
V_25 = F_26 ( V_2 -> V_25 ) ;
#ifdef F_18
F_54 ( & V_2 -> V_45 ) ;
#endif
if ( V_71 == V_25 )
return 0 ;
V_28 = ( V_71 == 0 ) ? ( V_2 -> V_23 - 1 ) : ( V_71 - 1 ) ;
V_32 = & V_2 -> V_21 [ V_28 ] ;
V_42 = F_26 ( V_32 -> V_41 . V_42 ) ;
V_42 |= V_72 ;
F_27 ( & V_32 -> V_41 . V_42 , V_42 ) ;
F_27 ( & V_2 -> V_28 , V_28 ) ;
if ( ! V_70 )
return 0 ;
F_55 ( & V_2 -> V_31 ) ;
F_56 ( & V_32 -> V_41 . V_44 , V_70 ) ;
F_57 ( & V_2 -> V_31 ) ;
return 1 ;
}
static int F_58 ( struct V_1 * V_2 , unsigned int V_23 ,
unsigned int * V_71 )
{
unsigned int V_24 ;
unsigned int V_26 ;
V_26 = F_26 ( V_2 -> V_26 ) ;
V_24 = F_26 ( V_2 -> V_24 ) ;
if ( F_30 ( V_2 , V_24 , V_26 , V_2 -> V_23 ) < V_23 )
return 0 ;
if ( F_41 ( V_2 , V_23 , V_24 , V_26 ) )
return 0 ;
* V_71 = V_24 ;
return 1 ;
}
static int F_59 ( struct V_1 * V_2 , unsigned int V_23 ,
unsigned int * V_71 )
{
if ( ! F_58 ( V_2 , V_23 , V_71 ) )
return 0 ;
F_27 ( & V_2 -> V_24 , ( * V_71 + V_23 ) & ( V_2 -> V_23 - 1 ) ) ;
return 1 ;
}
void F_60 ( struct V_1 * V_2 )
{
struct V_14 * V_14 = F_10 ( V_2 , struct V_14 , V_15 ) ;
unsigned int V_24 = F_26 ( V_2 -> V_24 ) ;
if ( F_53 ( V_2 , NULL , V_24 ) )
return;
F_61 ( V_14 ) ;
}
static int F_62 ( struct V_1 * V_2 , unsigned int V_23 ,
unsigned int * V_71 , struct V_70 * V_70 ,
int * V_73 )
{
unsigned int V_24 ;
if ( ! F_58 ( V_2 , V_23 , V_71 ) )
return 0 ;
V_24 = ( * V_71 + V_23 ) & ( V_2 -> V_23 - 1 ) ;
* V_73 = V_74 ;
if ( V_70 -> V_75 & V_76 ) {
struct V_14 * V_14 = F_10 ( V_2 , struct V_14 , V_15 ) ;
#ifdef F_18
F_63 ( & V_14 -> V_77 ) ;
#endif
if ( F_53 ( & V_14 -> V_15 , V_70 , V_24 ) )
* V_73 = V_78 ;
}
F_27 ( & V_2 -> V_24 , V_24 ) ;
return 1 ;
}
int F_64 ( struct V_1 * V_2 , struct V_70 * V_70 ,
unsigned int V_23 , unsigned int * V_71 )
{
struct V_14 * V_14 = F_10 ( V_2 , struct V_14 , V_15 ) ;
int V_73 ;
F_44 ( & V_2 -> V_30 ) ;
V_73 = F_65 ( & V_14 -> V_46 , V_23 ) ;
if ( V_73 ) {
F_46 ( & V_2 -> V_30 ) ;
return V_73 ;
}
if ( ! F_62 ( V_2 , V_23 , V_71 , V_70 , & V_73 ) ) {
F_46 ( & V_2 -> V_30 ) ;
return V_79 ;
}
F_66 ( & V_14 -> V_46 , V_23 ) ;
F_46 ( & V_2 -> V_30 ) ;
return V_73 ;
}
int F_67 ( struct V_1 * V_2 , unsigned int V_23 ,
unsigned int * V_71 )
{
struct V_14 * V_14 = F_10 ( V_2 , struct V_14 , V_15 ) ;
F_44 ( & V_2 -> V_30 ) ;
if ( ! F_68 ( & V_14 -> V_46 , V_23 ) ) {
F_46 ( & V_2 -> V_30 ) ;
return 0 ;
}
if ( ! F_59 ( V_2 , V_23 , V_71 ) ) {
F_46 ( & V_2 -> V_30 ) ;
return 0 ;
}
F_69 ( & V_14 -> V_46 , V_23 ) ;
F_46 ( & V_2 -> V_30 ) ;
return 1 ;
}
unsigned int F_70 ( struct V_1 * V_2 , struct V_70 * V_70 ,
struct V_80 * V_9 ,
unsigned int F_22 )
{
struct V_10 * V_32 , * V_81 ;
struct V_82 * V_82 ;
unsigned int V_83 = 0 ;
int V_65 ;
F_3 (entry, tentry, list, index) {
if ( V_83 > F_22 ) {
F_71 ( L_2 ) ;
goto V_66;
}
V_82 = F_72 ( V_32 -> V_39 ) ;
if ( ! V_82 ) {
F_71 ( L_3 ) ;
goto V_66;
}
V_65 = F_73 ( V_70 , V_82 , V_2 -> V_22 , 0 ) ;
if ( V_65 != V_2 -> V_22 ) {
F_71 ( L_4 ) ;
goto V_66;
}
F_6 ( & V_32 -> V_84 ) ;
V_83 ++ ;
}
V_66:
return V_83 ;
}
unsigned int F_74 ( struct V_1 * V_2 , struct V_85 * V_86 ,
struct V_70 * V_70 , unsigned int V_71 ,
unsigned int V_23 , unsigned int V_64 )
{
struct V_14 * V_14 = F_10 ( V_2 , struct V_14 , V_15 ) ;
struct V_87 * V_88 = V_14 -> V_89 -> V_88 ;
struct V_90 * V_91 = F_75 ( V_86 ) ;
struct V_10 * V_32 ;
struct V_82 * V_82 ;
unsigned int V_92 = 0 , V_93 = V_23 ;
unsigned int V_36 ;
int V_42 ;
if ( V_64 < V_23 ) {
V_92 = V_23 - V_64 ;
V_93 = V_64 ;
}
V_91 -> V_94 = V_71 ;
V_91 -> V_95 = V_93 ;
V_91 -> V_96 = V_92 ;
for ( V_36 = 0 ; V_36 < V_93 ; V_36 ++ ) {
V_32 = & V_2 -> V_21 [ V_71 ] ;
V_48:
V_42 = F_26 ( V_32 -> V_41 . V_42 ) ;
if ( ! ( V_42 & V_68 ) ) {
F_76 () ;
goto V_48;
}
V_82 = F_72 ( V_32 -> V_39 ) ;
if ( ! V_82 ) {
F_71 ( L_3 ) ;
V_42 &= ~ V_68 ;
V_42 |= V_49 ;
F_27 ( & V_32 -> V_41 . V_42 , V_42 ) ;
return V_97 ;
}
if ( F_77 ( V_88 , V_70 , V_82 , V_2 -> V_22 , 0 ) !=
V_2 -> V_22 ) {
F_71 ( L_4 ) ;
V_42 &= ~ V_68 ;
V_42 |= V_49 ;
F_27 ( & V_32 -> V_41 . V_42 , V_42 ) ;
return V_97 ;
}
if ( V_42 & V_72 ) {
unsigned int V_28 ;
V_28 = F_26 ( V_2 -> V_28 ) ;
if ( V_28 == V_71 ) {
F_27 ( & V_2 -> V_28 , V_29 ) ;
}
V_42 &= ~ V_72 ;
#ifdef F_18
F_78 ( & V_2 -> V_45 ) ;
#endif
}
V_42 &= ~ V_68 ;
V_42 |= V_49 ;
F_27 ( & V_32 -> V_41 . V_42 , V_42 ) ;
V_71 = ( V_71 + 1 ) & ( V_2 -> V_23 - 1 ) ;
}
if ( V_92 ) {
if ( F_79 ( V_14 , V_70 , V_37 , V_92 ) ) {
F_71 ( L_5 ) ;
return V_97 ;
}
}
#ifdef F_18
F_80 ( V_92 , & ( (struct V_14 * )
( F_10 ( V_2 , struct V_14 , V_15 ) ) ) -> V_98 ) ;
#endif
return V_78 ;
}
int F_81 ( struct V_1 * V_2 , struct V_70 * V_70 , T_1 V_51 ,
struct V_99 V_50 , int V_100 , bool V_101 )
{
struct V_14 * V_14 = F_10 ( V_2 , struct V_14 , V_15 ) ;
struct V_10 * V_32 ;
struct V_47 * V_41 ;
struct V_99 V_102 ;
T_2 V_71 = F_82 ( V_50 ) ;
void * V_39 ;
int V_42 ;
int V_65 = 1 ;
#ifdef F_18
F_49 ( V_71 >= V_2 -> V_23 ) ;
#endif
V_32 = & V_2 -> V_21 [ V_71 ] ;
V_41 = & V_32 -> V_41 ;
V_42 = F_26 ( V_41 -> V_42 ) ;
F_44 ( & V_2 -> V_30 ) ;
F_44 ( & V_14 -> V_103 ) ;
V_102 = F_83 ( V_14 , V_51 ) ;
F_46 ( & V_14 -> V_103 ) ;
if ( ! F_84 ( V_102 , V_50 ) || V_41 -> V_51 != V_51 ||
V_42 & V_43 ) {
V_65 = 0 ;
goto V_66;
}
if ( F_85 ( ! V_101 ) )
F_86 ( V_70 , V_100 * V_104 ) ;
V_39 = F_87 ( V_70 ) ;
memcpy ( V_39 , V_32 -> V_39 , V_2 -> V_22 ) ;
V_66:
F_46 ( & V_2 -> V_30 ) ;
return V_65 ;
}
struct V_47 * F_88 ( struct V_1 * V_2 , unsigned int V_71 )
{
unsigned int V_32 = V_71 & ( V_2 -> V_23 - 1 ) ;
return & V_2 -> V_21 [ V_32 ] . V_41 ;
}
unsigned int F_89 ( struct V_1 * V_2 , unsigned long * V_42 )
__acquires( &rb->s_lock
void F_90 ( struct V_1 * V_2 , unsigned long * V_42 )
__releases( &rb->s_lock
unsigned int F_91 ( struct V_1 * V_2 , unsigned int V_23 )
{
unsigned int V_26 ;
unsigned int V_36 ;
F_42 ( & V_2 -> V_31 ) ;
V_26 = F_26 ( V_2 -> V_26 ) ;
for ( V_36 = 0 ; V_36 < V_23 ; V_36 ++ )
V_26 = ( V_26 + 1 ) & ( V_2 -> V_23 - 1 ) ;
F_27 ( & V_2 -> V_26 , V_26 ) ;
return V_26 ;
}
unsigned int F_92 ( struct V_1 * V_2 )
{
unsigned int V_25 , V_28 ;
unsigned int V_64 ;
V_28 = F_45 ( & V_2 -> V_28 ) ;
if ( V_28 == V_29 )
return 0 ;
V_25 = F_26 ( V_2 -> V_25 ) ;
V_64 = F_32 ( V_28 , V_25 , V_2 -> V_23 ) + 1 ;
return V_64 ;
}
struct V_10 * F_93 ( struct V_1 * V_2 ,
struct V_99 * V_50 )
{
unsigned int V_26 , V_25 , V_64 ;
unsigned int V_36 ;
V_26 = F_26 ( V_2 -> V_26 ) ;
V_25 = F_26 ( V_2 -> V_25 ) ;
V_64 = F_32 ( V_25 , V_26 , V_2 -> V_23 ) ;
for ( V_36 = 0 ; V_36 < V_64 ; V_36 ++ )
V_26 = ( V_26 + 1 ) & ( V_2 -> V_23 - 1 ) ;
return NULL ;
}
int F_94 ( struct V_1 * V_2 )
{
struct V_10 * V_32 ;
int V_36 ;
int V_65 = 0 ;
F_44 ( & V_2 -> V_30 ) ;
F_55 ( & V_2 -> V_31 ) ;
if ( ( V_2 -> V_24 == V_2 -> V_25 ) && ( V_2 -> V_25 == V_2 -> V_26 ) &&
( V_2 -> V_26 == V_2 -> V_27 ) &&
( V_2 -> V_28 == V_29 ) ) {
goto V_66;
}
if ( ! V_2 -> V_21 ) {
V_65 = 1 ;
goto V_66;
}
for ( V_36 = 0 ; V_36 < V_2 -> V_23 ; V_36 ++ ) {
V_32 = & V_2 -> V_21 [ V_36 ] ;
if ( ! V_32 -> V_39 ) {
V_65 = 1 ;
goto V_66;
}
}
V_66:
F_46 ( & V_2 -> V_30 ) ;
F_57 ( & V_2 -> V_31 ) ;
return V_65 ;
}
unsigned int F_95 ( struct V_1 * V_2 , unsigned int V_71 )
{
return ( V_71 & ( V_2 -> V_23 - 1 ) ) ;
}
int F_96 ( struct V_1 * V_2 , T_2 V_71 )
{
return ( V_71 >= V_2 -> V_23 ) ;
}
T_3 F_97 ( struct V_1 * V_2 , char * V_105 )
{
struct V_14 * V_14 = F_10 ( V_2 , struct V_14 , V_15 ) ;
struct V_90 * V_106 ;
T_3 V_107 ;
int V_108 = 0 ;
F_55 ( & V_2 -> V_31 ) ;
F_98 (c, &pblk->compl_list, list)
V_108 ++ ;
F_57 ( & V_2 -> V_31 ) ;
if ( V_2 -> V_28 != V_29 )
V_107 = F_99 ( V_105 , V_109 ,
L_6 ,
V_2 -> V_23 ,
V_2 -> V_24 ,
V_2 -> V_25 ,
V_2 -> V_26 ,
V_2 -> V_27 ,
#ifdef F_18
F_100 ( & V_2 -> V_45 ) ,
#else
0 ,
#endif
V_2 -> V_28 ,
F_31 ( V_2 ) ,
F_29 ( V_2 ) ,
F_92 ( V_2 ) ,
V_108 ) ;
else
V_107 = F_99 ( V_105 , V_109 ,
L_7 ,
V_2 -> V_23 ,
V_2 -> V_24 ,
V_2 -> V_25 ,
V_2 -> V_26 ,
V_2 -> V_27 ,
#ifdef F_18
F_100 ( & V_2 -> V_45 ) ,
#else
0 ,
#endif
F_31 ( V_2 ) ,
F_29 ( V_2 ) ,
F_92 ( V_2 ) ,
V_108 ) ;
return V_107 ;
}
