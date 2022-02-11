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
unsigned int F_33 ( struct V_1 * V_2 , unsigned int V_23 )
{
unsigned int V_25 ;
V_25 = F_26 ( V_2 -> V_25 ) ;
F_27 ( & V_2 -> V_25 ,
( V_25 + V_23 ) & ( V_2 -> V_23 - 1 ) ) ;
return V_25 ;
}
static int F_34 ( struct V_1 * V_2 , unsigned int * V_51 ,
unsigned int V_52 )
{
struct V_14 * V_14 = F_10 ( V_2 , struct V_14 , V_15 ) ;
struct V_53 * line ;
struct V_10 * V_32 ;
struct V_47 * V_41 ;
unsigned int V_36 ;
for ( V_36 = 0 ; V_36 < V_52 ; V_36 ++ ) {
V_32 = & V_2 -> V_21 [ * V_51 ] ;
V_41 = & V_32 -> V_41 ;
F_35 ( V_14 , V_41 -> V_54 , V_41 -> V_50 ,
V_32 -> V_40 ) ;
line = & V_14 -> V_55 [ F_36 ( V_41 -> V_50 ) ] ;
F_37 ( & line -> V_56 , V_57 ) ;
F_25 ( V_41 ) ;
* V_51 = ( * V_51 + 1 ) & ( V_2 -> V_23 - 1 ) ;
}
return 0 ;
}
static int F_38 ( struct V_1 * V_2 , unsigned int V_23 ,
unsigned int V_24 , unsigned int V_26 )
{
unsigned int V_58 , V_59 ;
int V_60 = 0 ;
F_39 ( & V_2 -> V_30 ) ;
V_58 = F_30 ( V_2 , V_24 , V_2 -> V_27 , V_2 -> V_23 ) ;
if ( V_58 > V_23 )
goto V_61;
V_59 = V_23 - V_58 ;
V_60 = F_34 ( V_2 , & V_2 -> V_27 , V_59 ) ;
V_61:
return V_60 ;
}
void F_40 ( struct V_1 * V_2 )
{
unsigned int V_26 ;
unsigned int V_52 ;
F_41 ( & V_2 -> V_30 ) ;
V_26 = F_42 ( & V_2 -> V_26 ) ;
V_52 = F_32 ( V_26 , V_2 -> V_27 , V_2 -> V_23 ) ;
F_34 ( V_2 , & V_2 -> V_27 , V_52 ) ;
F_43 ( & V_2 -> V_30 ) ;
}
static void F_44 ( struct V_1 * V_2 , void * V_39 ,
struct V_47 V_41 ,
struct V_10 * V_32 )
{
memcpy ( V_32 -> V_39 , V_39 , V_2 -> V_22 ) ;
V_32 -> V_41 . V_54 = V_41 . V_54 ;
V_32 -> V_41 . V_50 = V_41 . V_50 ;
}
void F_45 ( struct V_1 * V_2 , void * V_39 ,
struct V_47 V_41 , unsigned int V_62 )
{
struct V_14 * V_14 = F_10 ( V_2 , struct V_14 , V_15 ) ;
struct V_10 * V_32 ;
int V_42 ;
V_32 = & V_2 -> V_21 [ V_62 ] ;
V_42 = F_26 ( V_32 -> V_41 . V_42 ) ;
#ifdef F_18
F_46 ( ! ( V_42 & V_43 ) ) ;
#endif
F_44 ( V_2 , V_39 , V_41 , V_32 ) ;
F_47 ( V_14 , V_41 . V_54 , V_32 -> V_40 ) ;
V_42 = V_41 . V_42 | V_63 ;
F_27 ( & V_32 -> V_41 . V_42 , V_42 ) ;
}
void F_48 ( struct V_1 * V_2 , void * V_39 ,
struct V_47 V_41 , struct V_53 * V_64 ,
unsigned int V_62 )
{
struct V_14 * V_14 = F_10 ( V_2 , struct V_14 , V_15 ) ;
struct V_10 * V_32 ;
int V_42 ;
V_32 = & V_2 -> V_21 [ V_62 ] ;
V_42 = F_26 ( V_32 -> V_41 . V_42 ) ;
#ifdef F_18
F_46 ( ! ( V_42 & V_43 ) ) ;
#endif
F_44 ( V_2 , V_39 , V_41 , V_32 ) ;
if ( ! F_49 ( V_14 , V_41 . V_54 , V_32 -> V_40 , V_64 ) )
V_32 -> V_41 . V_54 = V_65 ;
V_42 = V_41 . V_42 | V_63 ;
F_27 ( & V_32 -> V_41 . V_42 , V_42 ) ;
}
static int F_50 ( struct V_1 * V_2 , struct V_66 * V_66 ,
unsigned int V_67 )
{
struct V_10 * V_32 ;
unsigned int V_25 , V_28 ;
int V_42 ;
V_25 = F_26 ( V_2 -> V_25 ) ;
#ifdef F_18
F_51 ( & V_2 -> V_45 ) ;
#endif
if ( V_67 == V_25 )
return 0 ;
V_28 = ( V_67 == 0 ) ? ( V_2 -> V_23 - 1 ) : ( V_67 - 1 ) ;
V_32 = & V_2 -> V_21 [ V_28 ] ;
V_42 = F_26 ( V_32 -> V_41 . V_42 ) ;
V_42 |= V_68 ;
F_27 ( & V_32 -> V_41 . V_42 , V_42 ) ;
F_27 ( & V_2 -> V_28 , V_28 ) ;
F_52 ( & V_2 -> V_31 ) ;
F_53 ( & V_32 -> V_41 . V_44 , V_66 ) ;
F_54 ( & V_2 -> V_31 ) ;
return 1 ;
}
static int F_55 ( struct V_1 * V_2 , unsigned int V_23 ,
unsigned int * V_67 )
{
unsigned int V_24 ;
unsigned int V_26 ;
V_26 = F_26 ( V_2 -> V_26 ) ;
V_24 = F_26 ( V_2 -> V_24 ) ;
if ( F_30 ( V_2 , V_24 , V_26 , V_2 -> V_23 ) < V_23 )
return 0 ;
if ( F_38 ( V_2 , V_23 , V_24 , V_26 ) )
return 0 ;
* V_67 = V_24 ;
return 1 ;
}
static int F_56 ( struct V_1 * V_2 , unsigned int V_23 ,
unsigned int * V_67 )
{
if ( ! F_55 ( V_2 , V_23 , V_67 ) )
return 0 ;
F_27 ( & V_2 -> V_24 , ( * V_67 + V_23 ) & ( V_2 -> V_23 - 1 ) ) ;
return 1 ;
}
static int F_57 ( struct V_1 * V_2 , unsigned int V_23 ,
unsigned int * V_67 , struct V_66 * V_66 ,
int * V_69 )
{
unsigned int V_24 ;
if ( ! F_55 ( V_2 , V_23 , V_67 ) )
return 0 ;
V_24 = ( * V_67 + V_23 ) & ( V_2 -> V_23 - 1 ) ;
* V_69 = V_70 ;
if ( V_66 -> V_71 & V_72 ) {
struct V_14 * V_14 = F_10 ( V_2 , struct V_14 , V_15 ) ;
#ifdef F_18
F_58 ( & V_14 -> V_73 ) ;
#endif
if ( F_50 ( & V_14 -> V_15 , V_66 , V_24 ) )
* V_69 = V_74 ;
}
F_27 ( & V_2 -> V_24 , V_24 ) ;
return 1 ;
}
int F_59 ( struct V_1 * V_2 , struct V_66 * V_66 ,
unsigned int V_23 , unsigned int * V_67 )
{
struct V_14 * V_14 = F_10 ( V_2 , struct V_14 , V_15 ) ;
int V_75 ;
F_41 ( & V_2 -> V_30 ) ;
if ( ! F_60 ( & V_14 -> V_46 , V_23 ) ) {
F_43 ( & V_2 -> V_30 ) ;
return V_76 ;
}
if ( ! F_57 ( V_2 , V_23 , V_67 , V_66 , & V_75 ) ) {
F_43 ( & V_2 -> V_30 ) ;
return V_76 ;
}
F_61 ( & V_14 -> V_46 , V_23 ) ;
F_43 ( & V_2 -> V_30 ) ;
return V_75 ;
}
int F_62 ( struct V_1 * V_2 , unsigned int V_23 ,
unsigned int * V_67 )
{
struct V_14 * V_14 = F_10 ( V_2 , struct V_14 , V_15 ) ;
F_41 ( & V_2 -> V_30 ) ;
if ( ! F_63 ( & V_14 -> V_46 , V_23 ) ) {
F_43 ( & V_2 -> V_30 ) ;
return 0 ;
}
if ( ! F_56 ( V_2 , V_23 , V_67 ) ) {
F_43 ( & V_2 -> V_30 ) ;
return 0 ;
}
F_64 ( & V_14 -> V_46 , V_23 ) ;
F_43 ( & V_2 -> V_30 ) ;
return 1 ;
}
unsigned int F_65 ( struct V_1 * V_2 , struct V_66 * V_66 ,
struct V_77 * V_9 ,
unsigned int F_22 )
{
struct V_10 * V_32 , * V_78 ;
struct V_79 * V_79 ;
unsigned int V_80 = 0 ;
int V_60 ;
F_3 (entry, tentry, list, index) {
if ( V_80 > F_22 ) {
F_66 ( L_1 ) ;
goto V_61;
}
V_79 = F_67 ( V_32 -> V_39 ) ;
if ( ! V_79 ) {
F_66 ( L_2 ) ;
goto V_61;
}
V_60 = F_68 ( V_66 , V_79 , V_2 -> V_22 , 0 ) ;
if ( V_60 != V_2 -> V_22 ) {
F_66 ( L_3 ) ;
goto V_61;
}
F_6 ( & V_32 -> V_81 ) ;
V_80 ++ ;
}
V_61:
return V_80 ;
}
unsigned int F_69 ( struct V_1 * V_2 , struct V_66 * V_66 ,
struct V_82 * V_83 ,
unsigned int V_67 ,
unsigned int V_23 ,
unsigned int V_59 )
{
struct V_14 * V_14 = F_10 ( V_2 , struct V_14 , V_15 ) ;
struct V_10 * V_32 ;
struct V_79 * V_79 ;
unsigned int V_84 = 0 , V_80 = 0 , V_85 = V_23 ;
unsigned int V_86 = 0 , V_87 = 0 ;
unsigned int V_36 ;
int V_42 ;
int V_60 ;
if ( V_59 < V_23 ) {
V_84 = V_23 - V_59 ;
V_85 = V_59 ;
}
V_83 -> V_88 = V_67 ;
V_83 -> V_89 = V_85 ;
V_83 -> V_90 = V_84 ;
for ( V_36 = 0 ; V_36 < V_85 ; V_36 ++ ) {
V_32 = & V_2 -> V_21 [ V_67 ] ;
V_48:
V_42 = F_26 ( V_32 -> V_41 . V_42 ) ;
if ( ! ( V_42 & V_63 ) )
goto V_48;
if ( V_42 & V_91 )
V_86 ++ ;
else if ( V_42 & V_92 )
V_87 ++ ;
else
F_70 ( 1 , L_4 ) ;
V_79 = F_67 ( V_32 -> V_39 ) ;
if ( ! V_79 ) {
F_66 ( L_2 ) ;
V_42 &= ~ V_63 ;
V_42 |= V_49 ;
F_27 ( & V_32 -> V_41 . V_42 , V_42 ) ;
goto V_61;
}
V_60 = F_68 ( V_66 , V_79 , V_2 -> V_22 , 0 ) ;
if ( V_60 != V_2 -> V_22 ) {
F_66 ( L_3 ) ;
V_42 &= ~ V_63 ;
V_42 |= V_49 ;
F_27 ( & V_32 -> V_41 . V_42 , V_42 ) ;
goto V_61;
}
if ( V_42 & V_68 ) {
unsigned int V_28 ;
V_28 = F_26 ( V_2 -> V_28 ) ;
if ( V_28 == V_67 ) {
F_27 ( & V_2 -> V_28 , V_29 ) ;
}
V_42 &= ~ V_68 ;
#ifdef F_18
F_71 ( & V_2 -> V_45 ) ;
#endif
}
V_42 &= ~ V_63 ;
V_42 |= V_49 ;
F_27 ( & V_32 -> V_41 . V_42 , V_42 ) ;
V_67 = ( V_67 + 1 ) & ( V_2 -> V_23 - 1 ) ;
}
V_80 = V_85 ;
F_72 ( & V_14 -> V_46 , V_86 , V_87 ) ;
#ifdef F_18
F_73 ( V_84 , & ( (struct V_14 * )
( F_10 ( V_2 , struct V_14 , V_15 ) ) ) -> V_93 ) ;
#endif
V_61:
return V_80 ;
}
int F_74 ( struct V_1 * V_2 , struct V_66 * V_66 , T_1 V_54 ,
T_2 V_67 , int V_94 )
{
struct V_10 * V_32 ;
struct V_47 * V_41 ;
void * V_39 ;
int V_42 ;
int V_60 = 1 ;
F_41 ( & V_2 -> V_30 ) ;
#ifdef F_18
F_46 ( V_67 >= V_2 -> V_23 ) ;
#endif
V_32 = & V_2 -> V_21 [ V_67 ] ;
V_41 = & V_32 -> V_41 ;
V_42 = F_26 ( V_41 -> V_42 ) ;
if ( V_41 -> V_54 != V_54 || V_42 & V_43 ) {
V_60 = 0 ;
goto V_61;
}
if ( F_75 ( ! V_66 -> V_95 . V_96 ) )
F_76 ( V_66 , V_94 * V_97 ) ;
V_39 = F_77 ( V_66 ) ;
memcpy ( V_39 , V_32 -> V_39 , V_2 -> V_22 ) ;
V_61:
F_43 ( & V_2 -> V_30 ) ;
return V_60 ;
}
struct V_47 * F_78 ( struct V_1 * V_2 , unsigned int V_67 )
{
unsigned int V_32 = V_67 & ( V_2 -> V_23 - 1 ) ;
return & V_2 -> V_21 [ V_32 ] . V_41 ;
}
unsigned int F_79 ( struct V_1 * V_2 , unsigned long * V_42 )
__acquires( &rb->s_lock
void F_80 ( struct V_1 * V_2 , unsigned long * V_42 )
__releases( &rb->s_lock
unsigned int F_81 ( struct V_1 * V_2 , unsigned int V_23 )
{
unsigned int V_26 ;
unsigned int V_36 ;
F_39 ( & V_2 -> V_31 ) ;
V_26 = F_26 ( V_2 -> V_26 ) ;
for ( V_36 = 0 ; V_36 < V_23 ; V_36 ++ )
V_26 = ( V_26 + 1 ) & ( V_2 -> V_23 - 1 ) ;
F_27 ( & V_2 -> V_26 , V_26 ) ;
return V_26 ;
}
unsigned int F_82 ( struct V_1 * V_2 )
{
unsigned int V_25 , V_28 ;
unsigned int V_59 ;
V_28 = F_42 ( & V_2 -> V_28 ) ;
if ( V_28 == V_29 )
return 0 ;
V_25 = F_26 ( V_2 -> V_25 ) ;
V_59 = F_32 ( V_28 , V_25 , V_2 -> V_23 ) + 1 ;
return V_59 ;
}
struct V_10 * F_83 ( struct V_1 * V_2 ,
struct V_98 * V_50 )
{
unsigned int V_26 , V_25 , V_59 ;
unsigned int V_36 ;
V_26 = F_26 ( V_2 -> V_26 ) ;
V_25 = F_26 ( V_2 -> V_25 ) ;
V_59 = F_32 ( V_25 , V_26 , V_2 -> V_23 ) ;
for ( V_36 = 0 ; V_36 < V_59 ; V_36 ++ )
V_26 = ( V_26 + 1 ) & ( V_2 -> V_23 - 1 ) ;
return NULL ;
}
int F_84 ( struct V_1 * V_2 )
{
struct V_10 * V_32 ;
int V_36 ;
int V_60 = 0 ;
F_41 ( & V_2 -> V_30 ) ;
F_52 ( & V_2 -> V_31 ) ;
if ( ( V_2 -> V_24 == V_2 -> V_25 ) && ( V_2 -> V_25 == V_2 -> V_26 ) &&
( V_2 -> V_26 == V_2 -> V_27 ) &&
( V_2 -> V_28 == V_29 ) ) {
goto V_61;
}
if ( ! V_2 -> V_21 ) {
V_60 = 1 ;
goto V_61;
}
for ( V_36 = 0 ; V_36 < V_2 -> V_23 ; V_36 ++ ) {
V_32 = & V_2 -> V_21 [ V_36 ] ;
if ( ! V_32 -> V_39 ) {
V_60 = 1 ;
goto V_61;
}
}
V_61:
F_43 ( & V_2 -> V_30 ) ;
F_54 ( & V_2 -> V_31 ) ;
return V_60 ;
}
unsigned int F_85 ( struct V_1 * V_2 , unsigned int V_67 )
{
return ( V_67 & ( V_2 -> V_23 - 1 ) ) ;
}
int F_86 ( struct V_1 * V_2 , T_2 V_67 )
{
return ( V_67 >= V_2 -> V_23 ) ;
}
T_3 F_87 ( struct V_1 * V_2 , char * V_99 )
{
struct V_14 * V_14 = F_10 ( V_2 , struct V_14 , V_15 ) ;
struct V_82 * V_100 ;
T_3 V_101 ;
int V_102 = 0 ;
F_52 ( & V_2 -> V_31 ) ;
F_88 (c, &pblk->compl_list, list)
V_102 ++ ;
F_54 ( & V_2 -> V_31 ) ;
if ( V_2 -> V_28 != V_29 )
V_101 = F_89 ( V_99 , V_103 ,
L_5 ,
V_2 -> V_23 ,
V_2 -> V_24 ,
V_2 -> V_25 ,
V_2 -> V_26 ,
V_2 -> V_27 ,
#ifdef F_18
F_90 ( & V_2 -> V_45 ) ,
#else
0 ,
#endif
V_2 -> V_28 ,
F_31 ( V_2 ) ,
F_29 ( V_2 ) ,
F_82 ( V_2 ) ,
V_102 ) ;
else
V_101 = F_89 ( V_99 , V_103 ,
L_6 ,
V_2 -> V_23 ,
V_2 -> V_24 ,
V_2 -> V_25 ,
V_2 -> V_26 ,
V_2 -> V_27 ,
#ifdef F_18
F_90 ( & V_2 -> V_45 ) ,
#else
0 ,
#endif
F_31 ( V_2 ) ,
F_29 ( V_2 ) ,
F_82 ( V_2 ) ,
V_102 ) ;
return V_101 ;
}
