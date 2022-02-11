bool F_1 ( struct V_1 * V_2 )
{
return ( V_2 -> V_3 & V_4 ) &&
! ( V_2 -> V_3 & V_5 ) ;
}
bool F_2 ( struct V_1 * V_2 )
{
return ! ! ( V_2 -> V_3 & V_4 ) ;
}
static inline struct V_6 * F_3 ( struct V_6 * V_6 )
{
return (struct V_6 * ) ( ( unsigned long ) V_6 & ~ ( 1UL ) ) ;
}
static inline bool F_4 ( struct V_6 * V_6 )
{
return ! ! ( ( unsigned long ) V_6 & 1UL ) ;
}
static inline void F_5 ( struct V_6 * * V_6 )
{
* V_6 = (struct V_6 * ) ( ( unsigned long ) ( * V_6 ) | 1UL ) ;
}
static inline void F_6 ( struct V_6 * * V_6 )
{
* V_6 = (struct V_6 * ) ( ( unsigned long ) ( * V_6 ) & ~ ( 1UL ) ) ;
}
static void F_7 ( struct V_7 * V_8 ,
struct V_1 * V_2 )
{
struct V_9 * * V_10 = & V_8 -> V_11 . V_9 ;
struct V_9 * V_12 = NULL ;
struct V_1 * V_13 ;
while ( * V_10 ) {
V_12 = * V_10 ;
V_13 = F_8 ( V_12 , struct V_1 , V_14 ) ;
if ( V_2 < V_13 ) {
V_10 = & ( * V_10 ) -> V_15 ;
} else if ( V_2 > V_13 ) {
V_10 = & ( * V_10 ) -> V_16 ;
} else {
F_9 ( L_1 , V_17 ) ;
F_10 () ;
}
}
F_11 ( & V_2 -> V_14 , V_12 , V_10 ) ;
F_12 ( & V_2 -> V_14 , & V_8 -> V_11 ) ;
}
static struct V_1 * F_13 ( struct V_18 * V_19 ,
struct V_7 * V_8 ,
unsigned long V_20 ,
unsigned long V_21 ,
unsigned long V_3 )
{
struct V_1 * V_2 ;
struct V_22 * V_23 ;
struct V_24 * V_25 ;
int V_26 , V_27 ;
V_2 = F_14 ( sizeof( * V_2 ) , V_28 ) ;
if ( ! V_2 )
return F_15 ( - V_29 ) ;
V_2 -> V_19 = V_19 ;
V_2 -> V_3 = V_3 ;
F_16 ( & V_2 -> V_30 ) ;
V_27 = V_19 -> V_31 -> V_32 ( V_19 , V_2 , V_20 , V_21 , V_3 ) ;
if ( V_27 ) {
if ( ! ( V_19 -> V_3 & V_33 ) )
goto V_34;
F_17 ( V_19 , 0 ) ;
V_27 = V_19 -> V_31 -> V_32 ( V_19 , V_2 , V_20 , V_21 ,
V_3 ) ;
if ( V_27 )
goto V_34;
}
if ( V_2 -> V_22 == NULL ) {
F_18 ( 1 , L_2 ) ;
V_27 = - V_35 ;
goto V_36;
}
V_23 = V_2 -> V_22 ;
V_2 -> V_8 = V_8 ;
V_2 -> V_37 = V_20 ;
if ( F_1 ( V_2 ) ) {
int V_38 = F_19 ( V_2 -> V_37 ) / V_39 ;
struct V_24 * V_25 ;
int V_26 , V_40 , V_41 = 0 ;
V_2 -> V_42 = F_20 ( sizeof( struct V_6 * ) * V_38 ) ;
if ( ! V_2 -> V_42 ) {
V_27 = - V_29 ;
goto V_36;
}
F_21 (table->sgl, sg, table->nents, i) {
struct V_6 * V_6 = F_22 ( V_25 ) ;
for ( V_40 = 0 ; V_40 < V_25 -> V_43 / V_39 ; V_40 ++ )
V_2 -> V_42 [ V_41 ++ ] = V_6 ++ ;
}
}
V_2 -> V_8 = V_8 ;
V_2 -> V_37 = V_20 ;
F_23 ( & V_2 -> V_44 ) ;
F_24 ( & V_2 -> V_45 ) ;
F_21 (buffer->sg_table->sgl, sg, buffer->sg_table->nents, i) {
F_25 ( V_25 ) = F_26 ( V_25 ) ;
F_27 ( V_25 ) = V_25 -> V_43 ;
}
F_28 ( & V_8 -> V_46 ) ;
F_7 ( V_8 , V_2 ) ;
F_29 ( & V_8 -> V_46 ) ;
return V_2 ;
V_36:
V_19 -> V_31 -> free ( V_2 ) ;
V_34:
F_30 ( V_2 ) ;
return F_15 ( V_27 ) ;
}
void F_31 ( struct V_1 * V_2 )
{
if ( F_32 ( V_2 -> V_47 > 0 ) )
V_2 -> V_19 -> V_31 -> V_48 ( V_2 -> V_19 , V_2 ) ;
V_2 -> V_19 -> V_31 -> free ( V_2 ) ;
F_33 ( V_2 -> V_42 ) ;
F_30 ( V_2 ) ;
}
static void F_34 ( struct V_49 * V_49 )
{
struct V_1 * V_2 = F_35 ( V_49 , struct V_1 , V_30 ) ;
struct V_18 * V_19 = V_2 -> V_19 ;
struct V_7 * V_8 = V_2 -> V_8 ;
F_28 ( & V_8 -> V_46 ) ;
F_36 ( & V_2 -> V_14 , & V_8 -> V_11 ) ;
F_29 ( & V_8 -> V_46 ) ;
if ( V_19 -> V_3 & V_33 )
F_37 ( V_19 , V_2 ) ;
else
F_31 ( V_2 ) ;
}
static void F_38 ( struct V_1 * V_2 )
{
F_39 ( & V_2 -> V_30 ) ;
}
static int F_40 ( struct V_1 * V_2 )
{
return F_41 ( & V_2 -> V_30 , F_34 ) ;
}
static void F_42 ( struct V_1 * V_2 )
{
F_28 ( & V_2 -> V_45 ) ;
V_2 -> V_50 ++ ;
F_29 ( & V_2 -> V_45 ) ;
}
static void F_43 ( struct V_1 * V_2 )
{
F_28 ( & V_2 -> V_45 ) ;
V_2 -> V_50 -- ;
F_44 ( V_2 -> V_50 < 0 ) ;
if ( ! V_2 -> V_50 ) {
struct V_51 * V_52 ;
V_52 = V_53 -> V_54 ;
F_45 ( V_2 -> V_55 , V_52 ) ;
V_2 -> V_56 = F_46 ( V_52 ) ;
}
F_29 ( & V_2 -> V_45 ) ;
}
static struct V_57 * F_47 ( struct V_58 * V_59 ,
struct V_1 * V_2 )
{
struct V_57 * V_60 ;
V_60 = F_14 ( sizeof( * V_60 ) , V_28 ) ;
if ( ! V_60 )
return F_15 ( - V_29 ) ;
F_16 ( & V_60 -> V_30 ) ;
F_48 ( & V_60 -> V_14 ) ;
V_60 -> V_59 = V_59 ;
F_38 ( V_2 ) ;
F_42 ( V_2 ) ;
V_60 -> V_2 = V_2 ;
return V_60 ;
}
static void F_49 ( struct V_49 * V_49 )
{
struct V_57 * V_60 = F_35 ( V_49 , struct V_57 , V_30 ) ;
struct V_58 * V_59 = V_60 -> V_59 ;
struct V_1 * V_2 = V_60 -> V_2 ;
F_28 ( & V_2 -> V_45 ) ;
while ( V_60 -> V_47 )
F_50 ( V_60 ) ;
F_29 ( & V_2 -> V_45 ) ;
F_51 ( & V_59 -> V_61 , V_60 -> V_62 ) ;
if ( ! F_52 ( & V_60 -> V_14 ) )
F_36 ( & V_60 -> V_14 , & V_59 -> V_63 ) ;
F_43 ( V_2 ) ;
F_40 ( V_2 ) ;
F_30 ( V_60 ) ;
}
static void F_53 ( struct V_57 * V_60 )
{
F_39 ( & V_60 -> V_30 ) ;
}
int F_54 ( struct V_57 * V_60 )
{
return F_41 ( & V_60 -> V_30 , F_49 ) ;
}
int F_55 ( struct V_57 * V_60 )
{
struct V_58 * V_59 = V_60 -> V_59 ;
int V_27 ;
F_28 ( & V_59 -> V_45 ) ;
V_27 = F_54 ( V_60 ) ;
F_29 ( & V_59 -> V_45 ) ;
return V_27 ;
}
static struct V_57 * F_56 ( struct V_58 * V_59 ,
struct V_1 * V_2 )
{
struct V_9 * V_64 = V_59 -> V_63 . V_9 ;
while ( V_64 ) {
struct V_57 * V_13 = F_8 ( V_64 , struct V_57 , V_14 ) ;
if ( V_2 < V_13 -> V_2 )
V_64 = V_64 -> V_15 ;
else if ( V_2 > V_13 -> V_2 )
V_64 = V_64 -> V_16 ;
else
return V_13 ;
}
return F_15 ( - V_35 ) ;
}
struct V_57 * F_57 ( struct V_58 * V_59 ,
int V_62 )
{
struct V_57 * V_60 ;
V_60 = F_58 ( & V_59 -> V_61 , V_62 ) ;
if ( V_60 )
F_53 ( V_60 ) ;
return V_60 ? V_60 : F_15 ( - V_35 ) ;
}
struct V_57 * F_59 ( struct V_58 * V_59 ,
int V_62 )
{
struct V_57 * V_60 ;
F_28 ( & V_59 -> V_45 ) ;
V_60 = F_57 ( V_59 , V_62 ) ;
F_29 ( & V_59 -> V_45 ) ;
return V_60 ;
}
static bool F_60 ( struct V_58 * V_59 ,
struct V_57 * V_60 )
{
F_32 ( ! F_61 ( & V_59 -> V_45 ) ) ;
return F_58 ( & V_59 -> V_61 , V_60 -> V_62 ) == V_60 ;
}
static int F_62 ( struct V_58 * V_59 , struct V_57 * V_60 )
{
int V_62 ;
struct V_9 * * V_10 = & V_59 -> V_63 . V_9 ;
struct V_9 * V_12 = NULL ;
struct V_57 * V_13 ;
V_62 = F_63 ( & V_59 -> V_61 , V_60 , 1 , 0 , V_28 ) ;
if ( V_62 < 0 )
return V_62 ;
V_60 -> V_62 = V_62 ;
while ( * V_10 ) {
V_12 = * V_10 ;
V_13 = F_8 ( V_12 , struct V_57 , V_14 ) ;
if ( V_60 -> V_2 < V_13 -> V_2 )
V_10 = & ( * V_10 ) -> V_15 ;
else if ( V_60 -> V_2 > V_13 -> V_2 )
V_10 = & ( * V_10 ) -> V_16 ;
else
F_64 ( 1 , L_1 , V_17 ) ;
}
F_11 ( & V_60 -> V_14 , V_12 , V_10 ) ;
F_12 ( & V_60 -> V_14 , & V_59 -> V_63 ) ;
return 0 ;
}
struct V_57 * F_65 ( struct V_58 * V_59 , T_1 V_20 ,
T_1 V_21 , unsigned int V_65 ,
unsigned int V_3 )
{
struct V_57 * V_60 ;
struct V_7 * V_8 = V_59 -> V_8 ;
struct V_1 * V_2 = NULL ;
struct V_18 * V_19 ;
int V_27 ;
F_66 ( L_3 , V_17 ,
V_20 , V_21 , V_65 , V_3 ) ;
V_20 = F_19 ( V_20 ) ;
if ( ! V_20 )
return F_15 ( - V_35 ) ;
F_67 ( & V_8 -> V_45 ) ;
F_68 (heap, &dev->heaps, node) {
if ( ! ( ( 1 << V_19 -> V_62 ) & V_65 ) )
continue;
V_2 = F_13 ( V_19 , V_8 , V_20 , V_21 , V_3 ) ;
if ( ! F_69 ( V_2 ) )
break;
}
F_70 ( & V_8 -> V_45 ) ;
if ( V_2 == NULL )
return F_15 ( - V_66 ) ;
if ( F_69 ( V_2 ) )
return F_71 ( V_2 ) ;
V_60 = F_47 ( V_59 , V_2 ) ;
F_40 ( V_2 ) ;
if ( F_69 ( V_60 ) )
return V_60 ;
F_28 ( & V_59 -> V_45 ) ;
V_27 = F_62 ( V_59 , V_60 ) ;
F_29 ( & V_59 -> V_45 ) ;
if ( V_27 ) {
F_55 ( V_60 ) ;
V_60 = F_15 ( V_27 ) ;
}
return V_60 ;
}
void F_72 ( struct V_58 * V_59 ,
struct V_57 * V_60 )
{
if ( ! F_60 ( V_59 , V_60 ) ) {
F_64 ( 1 , L_4 , V_17 ) ;
return;
}
F_54 ( V_60 ) ;
}
void F_73 ( struct V_58 * V_59 , struct V_57 * V_60 )
{
F_44 ( V_59 != V_60 -> V_59 ) ;
F_28 ( & V_59 -> V_45 ) ;
F_72 ( V_59 , V_60 ) ;
F_29 ( & V_59 -> V_45 ) ;
}
static void * F_74 ( struct V_1 * V_2 )
{
void * V_67 ;
if ( V_2 -> V_47 ) {
V_2 -> V_47 ++ ;
return V_2 -> V_67 ;
}
V_67 = V_2 -> V_19 -> V_31 -> V_68 ( V_2 -> V_19 , V_2 ) ;
if ( F_18 ( V_67 == NULL ,
L_5 ) )
return F_15 ( - V_35 ) ;
if ( F_69 ( V_67 ) )
return V_67 ;
V_2 -> V_67 = V_67 ;
V_2 -> V_47 ++ ;
return V_67 ;
}
static void * F_75 ( struct V_57 * V_60 )
{
struct V_1 * V_2 = V_60 -> V_2 ;
void * V_67 ;
if ( V_60 -> V_47 ) {
V_60 -> V_47 ++ ;
return V_2 -> V_67 ;
}
V_67 = F_74 ( V_2 ) ;
if ( F_69 ( V_67 ) )
return V_67 ;
V_60 -> V_47 ++ ;
return V_67 ;
}
static void F_76 ( struct V_1 * V_2 )
{
V_2 -> V_47 -- ;
if ( ! V_2 -> V_47 ) {
V_2 -> V_19 -> V_31 -> V_48 ( V_2 -> V_19 , V_2 ) ;
V_2 -> V_67 = NULL ;
}
}
static void F_50 ( struct V_57 * V_60 )
{
struct V_1 * V_2 = V_60 -> V_2 ;
if ( ! V_60 -> V_47 ) {
F_64 ( 1 , L_6 , V_17 ) ;
return;
}
V_60 -> V_47 -- ;
if ( ! V_60 -> V_47 )
F_76 ( V_2 ) ;
}
void * F_77 ( struct V_58 * V_59 , struct V_57 * V_60 )
{
struct V_1 * V_2 ;
void * V_67 ;
F_28 ( & V_59 -> V_45 ) ;
if ( ! F_60 ( V_59 , V_60 ) ) {
F_9 ( L_7 ,
V_17 ) ;
F_29 ( & V_59 -> V_45 ) ;
return F_15 ( - V_35 ) ;
}
V_2 = V_60 -> V_2 ;
if ( ! V_60 -> V_2 -> V_19 -> V_31 -> V_68 ) {
F_9 ( L_8 ,
V_17 ) ;
F_29 ( & V_59 -> V_45 ) ;
return F_15 ( - V_66 ) ;
}
F_28 ( & V_2 -> V_45 ) ;
V_67 = F_75 ( V_60 ) ;
F_29 ( & V_2 -> V_45 ) ;
F_29 ( & V_59 -> V_45 ) ;
return V_67 ;
}
void F_78 ( struct V_58 * V_59 , struct V_57 * V_60 )
{
struct V_1 * V_2 ;
F_28 ( & V_59 -> V_45 ) ;
V_2 = V_60 -> V_2 ;
F_28 ( & V_2 -> V_45 ) ;
F_50 ( V_60 ) ;
F_29 ( & V_2 -> V_45 ) ;
F_29 ( & V_59 -> V_45 ) ;
}
static int F_79 ( struct V_58 * V_59 )
{
struct V_9 * V_14 ;
struct V_58 * V_69 ;
struct V_7 * V_8 ;
V_14 = V_70 -> V_9 ;
V_8 = F_35 ( V_70 , struct V_7 , V_71 ) ;
F_67 ( & V_8 -> V_45 ) ;
while ( V_14 ) {
V_69 = F_8 ( V_14 , struct V_58 , V_14 ) ;
if ( V_59 < V_69 ) {
V_14 = V_14 -> V_15 ;
} else if ( V_59 > V_69 ) {
V_14 = V_14 -> V_16 ;
} else {
F_70 ( & V_8 -> V_45 ) ;
return 1 ;
}
}
F_70 ( & V_8 -> V_45 ) ;
return 0 ;
}
static int F_80 ( struct V_72 * V_73 , void * V_74 )
{
struct V_58 * V_59 = V_73 -> V_75 ;
struct V_9 * V_64 ;
T_1 V_76 [ V_77 ] = { 0 } ;
const char * V_78 [ V_77 ] = { NULL } ;
int V_26 ;
F_28 ( & V_79 ) ;
if ( ! F_79 ( V_59 ) ) {
F_81 ( V_73 , L_9 ,
V_59 ) ;
F_29 ( & V_79 ) ;
return 0 ;
}
F_28 ( & V_59 -> V_45 ) ;
for ( V_64 = F_82 ( & V_59 -> V_63 ) ; V_64 ; V_64 = F_83 ( V_64 ) ) {
struct V_57 * V_60 = F_8 ( V_64 , struct V_57 ,
V_14 ) ;
unsigned int V_62 = V_60 -> V_2 -> V_19 -> V_62 ;
if ( ! V_78 [ V_62 ] )
V_78 [ V_62 ] = V_60 -> V_2 -> V_19 -> V_80 ;
V_76 [ V_62 ] += V_60 -> V_2 -> V_37 ;
}
F_29 ( & V_59 -> V_45 ) ;
F_29 ( & V_79 ) ;
F_81 ( V_73 , L_10 , L_11 , L_12 ) ;
for ( V_26 = 0 ; V_26 < V_77 ; V_26 ++ ) {
if ( ! V_78 [ V_26 ] )
continue;
F_81 ( V_73 , L_13 , V_78 [ V_26 ] , V_76 [ V_26 ] ) ;
}
return 0 ;
}
static int F_84 ( struct V_81 * V_81 , struct V_82 * V_82 )
{
return F_85 ( V_82 , F_80 , V_81 -> V_83 ) ;
}
static int F_86 ( const struct V_84 * V_85 ,
const unsigned char * V_80 )
{
int V_86 = - 1 ;
struct V_9 * V_14 ;
for ( V_14 = F_82 ( V_85 ) ; V_14 ; V_14 = F_83 ( V_14 ) ) {
struct V_58 * V_59 = F_8 ( V_14 , struct V_58 ,
V_14 ) ;
if ( strcmp ( V_59 -> V_80 , V_80 ) )
continue;
V_86 = F_87 ( V_86 , V_59 -> V_87 ) ;
}
return V_86 + 1 ;
}
struct V_58 * F_88 ( struct V_7 * V_8 ,
const char * V_80 )
{
struct V_58 * V_59 ;
struct V_51 * V_52 ;
struct V_9 * * V_10 ;
struct V_9 * V_12 = NULL ;
struct V_58 * V_13 ;
T_2 V_56 ;
if ( ! V_80 ) {
F_9 ( L_14 , V_17 ) ;
return F_15 ( - V_35 ) ;
}
F_89 ( V_53 -> V_54 ) ;
F_90 ( V_53 -> V_54 ) ;
V_56 = F_46 ( V_53 -> V_54 ) ;
if ( V_53 -> V_54 -> V_3 & V_88 ) {
F_91 ( V_53 -> V_54 ) ;
V_52 = NULL ;
} else {
V_52 = V_53 -> V_54 ;
}
F_92 ( V_53 -> V_54 ) ;
V_59 = F_14 ( sizeof( * V_59 ) , V_28 ) ;
if ( ! V_59 )
goto V_89;
V_59 -> V_8 = V_8 ;
V_59 -> V_63 = V_90 ;
F_93 ( & V_59 -> V_61 ) ;
F_24 ( & V_59 -> V_45 ) ;
V_59 -> V_52 = V_52 ;
V_59 -> V_56 = V_56 ;
V_59 -> V_80 = F_94 ( V_80 , V_28 ) ;
if ( ! V_59 -> V_80 )
goto V_91;
F_95 ( & V_8 -> V_45 ) ;
V_59 -> V_87 = F_86 ( & V_8 -> V_71 , V_80 ) ;
V_59 -> V_92 = F_96 (
V_28 , L_15 , V_80 , V_59 -> V_87 ) ;
if ( ! V_59 -> V_92 ) {
F_97 ( & V_8 -> V_45 ) ;
goto V_93;
}
V_10 = & V_8 -> V_71 . V_9 ;
while ( * V_10 ) {
V_12 = * V_10 ;
V_13 = F_8 ( V_12 , struct V_58 , V_14 ) ;
if ( V_59 < V_13 )
V_10 = & ( * V_10 ) -> V_15 ;
else if ( V_59 > V_13 )
V_10 = & ( * V_10 ) -> V_16 ;
}
F_11 ( & V_59 -> V_14 , V_12 , V_10 ) ;
F_12 ( & V_59 -> V_14 , & V_8 -> V_71 ) ;
V_59 -> V_94 = F_98 ( V_59 -> V_92 , 0664 ,
V_8 -> V_95 ,
V_59 , & V_96 ) ;
if ( ! V_59 -> V_94 ) {
char V_97 [ 256 ] , * V_98 ;
V_98 = F_99 ( V_8 -> V_95 , V_97 , 256 ) ;
F_9 ( L_16 ,
V_98 , V_59 -> V_92 ) ;
}
F_97 ( & V_8 -> V_45 ) ;
return V_59 ;
V_93:
F_30 ( V_59 -> V_80 ) ;
V_91:
F_30 ( V_59 ) ;
V_89:
if ( V_52 )
F_91 ( V_53 -> V_54 ) ;
return F_15 ( - V_29 ) ;
}
void F_100 ( struct V_58 * V_59 )
{
struct V_7 * V_8 = V_59 -> V_8 ;
struct V_9 * V_64 ;
F_66 ( L_17 , V_17 , __LINE__ ) ;
F_28 ( & V_79 ) ;
while ( ( V_64 = F_82 ( & V_59 -> V_63 ) ) ) {
struct V_57 * V_60 = F_8 ( V_64 , struct V_57 ,
V_14 ) ;
F_49 ( & V_60 -> V_30 ) ;
}
F_101 ( & V_59 -> V_61 ) ;
F_95 ( & V_8 -> V_45 ) ;
if ( V_59 -> V_52 )
F_91 ( V_59 -> V_52 ) ;
F_36 ( & V_59 -> V_14 , & V_8 -> V_71 ) ;
F_102 ( V_59 -> V_94 ) ;
F_97 ( & V_8 -> V_45 ) ;
F_30 ( V_59 -> V_92 ) ;
F_30 ( V_59 -> V_80 ) ;
F_30 ( V_59 ) ;
F_29 ( & V_79 ) ;
}
static struct V_22 * F_103 ( struct V_99 * V_100 ,
enum V_101 V_102 )
{
struct V_103 * V_104 = V_100 -> V_104 ;
struct V_1 * V_2 = V_104 -> V_105 ;
F_104 ( V_2 , V_100 -> V_8 , V_102 ) ;
return V_2 -> V_22 ;
}
static void F_105 ( struct V_99 * V_100 ,
struct V_22 * V_23 ,
enum V_101 V_102 )
{
}
void F_106 ( struct V_106 * V_8 , struct V_6 * V_6 ,
T_1 V_37 , enum V_101 V_107 )
{
struct V_24 V_25 ;
F_107 ( & V_25 , 1 ) ;
F_108 ( & V_25 , V_6 , V_37 , 0 ) ;
F_25 ( & V_25 ) = F_109 ( V_6 ) ;
F_110 ( V_8 , & V_25 , 1 , V_107 ) ;
}
static void F_104 ( struct V_1 * V_2 ,
struct V_106 * V_8 ,
enum V_101 V_107 )
{
struct V_108 * V_109 ;
int V_42 = F_19 ( V_2 -> V_37 ) / V_39 ;
int V_26 ;
F_66 ( L_18 , V_17 ,
V_8 ? F_111 ( V_8 ) : L_19 ) ;
if ( ! F_1 ( V_2 ) )
return;
F_28 ( & V_2 -> V_45 ) ;
for ( V_26 = 0 ; V_26 < V_42 ; V_26 ++ ) {
struct V_6 * V_6 = V_2 -> V_42 [ V_26 ] ;
if ( F_4 ( V_6 ) )
F_106 ( V_8 , F_3 ( V_6 ) ,
V_39 , V_107 ) ;
F_6 ( V_2 -> V_42 + V_26 ) ;
}
F_112 (vma_list, &buffer->vmas, list) {
struct V_110 * V_111 = V_109 -> V_111 ;
F_113 ( V_111 , V_111 -> V_112 , V_111 -> V_113 - V_111 -> V_112 ,
NULL ) ;
}
F_29 ( & V_2 -> V_45 ) ;
}
static int F_114 ( struct V_110 * V_111 , struct V_114 * V_115 )
{
struct V_1 * V_2 = V_111 -> V_116 ;
unsigned long V_117 ;
int V_27 ;
F_28 ( & V_2 -> V_45 ) ;
F_5 ( V_2 -> V_42 + V_115 -> V_118 ) ;
F_44 ( ! V_2 -> V_42 || ! V_2 -> V_42 [ V_115 -> V_118 ] ) ;
V_117 = F_115 ( F_3 ( V_2 -> V_42 [ V_115 -> V_118 ] ) ) ;
V_27 = F_116 ( V_111 , V_115 -> V_119 , V_117 ) ;
F_29 ( & V_2 -> V_45 ) ;
if ( V_27 )
return V_120 ;
return V_121 ;
}
static void F_117 ( struct V_110 * V_111 )
{
struct V_1 * V_2 = V_111 -> V_116 ;
struct V_108 * V_109 ;
V_109 = F_118 ( sizeof( * V_109 ) , V_28 ) ;
if ( ! V_109 )
return;
V_109 -> V_111 = V_111 ;
F_28 ( & V_2 -> V_45 ) ;
F_119 ( & V_109 -> V_122 , & V_2 -> V_44 ) ;
F_29 ( & V_2 -> V_45 ) ;
F_66 ( L_20 , V_17 , V_111 ) ;
}
static void F_120 ( struct V_110 * V_111 )
{
struct V_1 * V_2 = V_111 -> V_116 ;
struct V_108 * V_109 , * V_69 ;
F_66 ( L_21 , V_17 ) ;
F_28 ( & V_2 -> V_45 ) ;
F_121 (vma_list, tmp, &buffer->vmas, list) {
if ( V_109 -> V_111 != V_111 )
continue;
F_122 ( & V_109 -> V_122 ) ;
F_30 ( V_109 ) ;
F_66 ( L_22 , V_17 , V_111 ) ;
break;
}
F_29 ( & V_2 -> V_45 ) ;
}
static int F_123 ( struct V_103 * V_104 , struct V_110 * V_111 )
{
struct V_1 * V_2 = V_104 -> V_105 ;
int V_27 = 0 ;
if ( ! V_2 -> V_19 -> V_31 -> V_123 ) {
F_9 ( L_23 ,
V_17 ) ;
return - V_35 ;
}
if ( F_1 ( V_2 ) ) {
V_111 -> V_124 |= V_125 | V_126 | V_127 |
V_128 ;
V_111 -> V_116 = V_2 ;
V_111 -> V_129 = & V_130 ;
F_117 ( V_111 ) ;
return 0 ;
}
if ( ! ( V_2 -> V_3 & V_4 ) )
V_111 -> V_131 = F_124 ( V_111 -> V_131 ) ;
F_28 ( & V_2 -> V_45 ) ;
V_27 = V_2 -> V_19 -> V_31 -> V_123 ( V_2 -> V_19 , V_2 , V_111 ) ;
F_29 ( & V_2 -> V_45 ) ;
if ( V_27 )
F_9 ( L_24 ,
V_17 ) ;
return V_27 ;
}
static void F_125 ( struct V_103 * V_104 )
{
struct V_1 * V_2 = V_104 -> V_105 ;
F_40 ( V_2 ) ;
}
static void * F_126 ( struct V_103 * V_104 , unsigned long V_132 )
{
struct V_1 * V_2 = V_104 -> V_105 ;
return V_2 -> V_67 + V_132 * V_39 ;
}
static void F_127 ( struct V_103 * V_104 , unsigned long V_132 ,
void * V_133 )
{
}
static int F_128 ( struct V_103 * V_104 ,
enum V_101 V_102 )
{
struct V_1 * V_2 = V_104 -> V_105 ;
void * V_67 ;
if ( ! V_2 -> V_19 -> V_31 -> V_68 ) {
F_9 ( L_25 ,
V_17 ) ;
return - V_66 ;
}
F_28 ( & V_2 -> V_45 ) ;
V_67 = F_74 ( V_2 ) ;
F_29 ( & V_2 -> V_45 ) ;
return F_129 ( V_67 ) ;
}
static int F_130 ( struct V_103 * V_104 ,
enum V_101 V_102 )
{
struct V_1 * V_2 = V_104 -> V_105 ;
F_28 ( & V_2 -> V_45 ) ;
F_76 ( V_2 ) ;
F_29 ( & V_2 -> V_45 ) ;
return 0 ;
}
struct V_103 * F_131 ( struct V_58 * V_59 ,
struct V_57 * V_60 )
{
F_132 ( V_134 ) ;
struct V_1 * V_2 ;
struct V_103 * V_104 ;
bool V_135 ;
F_28 ( & V_59 -> V_45 ) ;
V_135 = F_60 ( V_59 , V_60 ) ;
if ( ! V_135 ) {
F_64 ( 1 , L_26 , V_17 ) ;
F_29 ( & V_59 -> V_45 ) ;
return F_15 ( - V_35 ) ;
}
V_2 = V_60 -> V_2 ;
F_38 ( V_2 ) ;
F_29 ( & V_59 -> V_45 ) ;
V_134 . V_31 = & V_136 ;
V_134 . V_37 = V_2 -> V_37 ;
V_134 . V_3 = V_137 ;
V_134 . V_105 = V_2 ;
V_104 = F_133 ( & V_134 ) ;
if ( F_69 ( V_104 ) ) {
F_40 ( V_2 ) ;
return V_104 ;
}
return V_104 ;
}
int F_134 ( struct V_58 * V_59 , struct V_57 * V_60 )
{
struct V_103 * V_104 ;
int V_138 ;
V_104 = F_131 ( V_59 , V_60 ) ;
if ( F_69 ( V_104 ) )
return F_135 ( V_104 ) ;
V_138 = F_136 ( V_104 , V_139 ) ;
if ( V_138 < 0 )
F_137 ( V_104 ) ;
return V_138 ;
}
struct V_57 * F_138 ( struct V_58 * V_59 ,
struct V_103 * V_104 )
{
struct V_1 * V_2 ;
struct V_57 * V_60 ;
int V_27 ;
if ( V_104 -> V_31 != & V_136 ) {
F_9 ( L_27 ,
V_17 ) ;
return F_15 ( - V_35 ) ;
}
V_2 = V_104 -> V_105 ;
F_28 ( & V_59 -> V_45 ) ;
V_60 = F_56 ( V_59 , V_2 ) ;
if ( ! F_69 ( V_60 ) ) {
F_53 ( V_60 ) ;
F_29 ( & V_59 -> V_45 ) ;
goto V_140;
}
V_60 = F_47 ( V_59 , V_2 ) ;
if ( F_69 ( V_60 ) ) {
F_29 ( & V_59 -> V_45 ) ;
goto V_140;
}
V_27 = F_62 ( V_59 , V_60 ) ;
F_29 ( & V_59 -> V_45 ) ;
if ( V_27 ) {
F_55 ( V_60 ) ;
V_60 = F_15 ( V_27 ) ;
}
V_140:
return V_60 ;
}
struct V_57 * F_139 ( struct V_58 * V_59 , int V_138 )
{
struct V_103 * V_104 ;
struct V_57 * V_60 ;
V_104 = F_140 ( V_138 ) ;
if ( F_69 ( V_104 ) )
return F_71 ( V_104 ) ;
V_60 = F_138 ( V_59 , V_104 ) ;
F_137 ( V_104 ) ;
return V_60 ;
}
int F_141 ( struct V_58 * V_59 , int V_138 )
{
struct V_103 * V_104 ;
struct V_1 * V_2 ;
V_104 = F_140 ( V_138 ) ;
if ( F_69 ( V_104 ) )
return F_135 ( V_104 ) ;
if ( V_104 -> V_31 != & V_136 ) {
F_9 ( L_28 ,
V_17 ) ;
F_137 ( V_104 ) ;
return - V_35 ;
}
V_2 = V_104 -> V_105 ;
F_110 ( NULL , V_2 -> V_22 -> V_141 ,
V_2 -> V_22 -> V_142 , V_143 ) ;
F_137 ( V_104 ) ;
return 0 ;
}
int F_142 ( struct V_58 * V_59 , struct V_144 * V_145 )
{
struct V_7 * V_8 = V_59 -> V_8 ;
struct V_146 T_3 * V_2 = F_143 ( V_145 -> V_147 ) ;
int V_27 = - V_35 , V_148 = 0 , V_149 ;
struct V_18 * V_19 ;
struct V_146 V_150 ;
memset ( & V_150 , 0 , sizeof( V_150 ) ) ;
F_67 ( & V_8 -> V_45 ) ;
if ( ! V_2 ) {
V_145 -> V_148 = V_8 -> V_151 ;
V_27 = 0 ;
goto V_152;
}
if ( V_145 -> V_148 <= 0 )
goto V_152;
V_149 = V_145 -> V_148 ;
F_68 (heap, &dev->heaps, node) {
strncpy ( V_150 . V_80 , V_19 -> V_80 , V_153 ) ;
V_150 . V_80 [ sizeof( V_150 . V_80 ) - 1 ] = '\0' ;
V_150 . type = V_19 -> type ;
V_150 . V_154 = V_19 -> V_62 ;
if ( F_144 ( & V_2 [ V_148 ] , & V_150 , sizeof( V_150 ) ) ) {
V_27 = - V_155 ;
goto V_152;
}
V_148 ++ ;
if ( V_148 >= V_149 )
break;
}
V_145 -> V_148 = V_148 ;
V_152:
F_70 ( & V_8 -> V_45 ) ;
return V_27 ;
}
static int F_145 ( struct V_81 * V_81 , struct V_82 * V_82 )
{
struct V_58 * V_59 = V_82 -> V_156 ;
F_66 ( L_17 , V_17 , __LINE__ ) ;
F_100 ( V_59 ) ;
return 0 ;
}
static int F_146 ( struct V_81 * V_81 , struct V_82 * V_82 )
{
struct V_157 * V_158 = V_82 -> V_156 ;
struct V_7 * V_8 = F_35 ( V_158 , struct V_7 , V_8 ) ;
struct V_58 * V_59 ;
char V_159 [ 64 ] ;
F_66 ( L_17 , V_17 , __LINE__ ) ;
snprintf ( V_159 , 64 , L_29 , F_46 ( V_53 -> V_54 ) ) ;
V_59 = F_88 ( V_8 , V_159 ) ;
if ( F_69 ( V_59 ) )
return F_135 ( V_59 ) ;
V_82 -> V_156 = V_59 ;
return 0 ;
}
static T_1 F_147 ( struct V_58 * V_59 ,
unsigned int V_62 )
{
T_1 V_37 = 0 ;
struct V_9 * V_64 ;
F_28 ( & V_59 -> V_45 ) ;
for ( V_64 = F_82 ( & V_59 -> V_63 ) ; V_64 ; V_64 = F_83 ( V_64 ) ) {
struct V_57 * V_60 = F_8 ( V_64 ,
struct V_57 ,
V_14 ) ;
if ( V_60 -> V_2 -> V_19 -> V_62 == V_62 )
V_37 += V_60 -> V_2 -> V_37 ;
}
F_29 ( & V_59 -> V_45 ) ;
return V_37 ;
}
static int F_148 ( struct V_72 * V_73 , void * V_74 )
{
struct V_18 * V_19 = V_73 -> V_75 ;
struct V_7 * V_8 = V_19 -> V_8 ;
struct V_9 * V_64 ;
T_1 V_160 = 0 ;
T_1 V_161 = 0 ;
F_81 ( V_73 , L_30 , L_31 , L_32 , L_33 ) ;
F_149 ( V_73 , L_34 ) ;
F_28 ( & V_79 ) ;
for ( V_64 = F_82 ( & V_8 -> V_71 ) ; V_64 ; V_64 = F_83 ( V_64 ) ) {
struct V_58 * V_59 = F_8 ( V_64 , struct V_58 ,
V_14 ) ;
T_1 V_37 = F_147 ( V_59 , V_19 -> V_62 ) ;
if ( ! V_37 )
continue;
if ( V_59 -> V_52 ) {
char V_55 [ V_162 ] ;
F_45 ( V_55 , V_59 -> V_52 ) ;
F_81 ( V_73 , L_35 , V_55 ,
V_59 -> V_56 , V_37 ) ;
} else {
F_81 ( V_73 , L_35 , V_59 -> V_80 ,
V_59 -> V_56 , V_37 ) ;
}
}
F_29 ( & V_79 ) ;
F_149 ( V_73 , L_34 ) ;
F_149 ( V_73 , L_36 ) ;
F_28 ( & V_8 -> V_46 ) ;
for ( V_64 = F_82 ( & V_8 -> V_11 ) ; V_64 ; V_64 = F_83 ( V_64 ) ) {
struct V_1 * V_2 = F_8 ( V_64 , struct V_1 ,
V_14 ) ;
if ( V_2 -> V_19 -> V_62 != V_19 -> V_62 )
continue;
V_160 += V_2 -> V_37 ;
if ( ! V_2 -> V_50 ) {
F_81 ( V_73 , L_37 ,
V_2 -> V_55 , V_2 -> V_56 ,
V_2 -> V_37 , V_2 -> V_47 ,
F_150 ( & V_2 -> V_30 . V_163 ) ) ;
V_161 += V_2 -> V_37 ;
}
}
F_29 ( & V_8 -> V_46 ) ;
F_149 ( V_73 , L_34 ) ;
F_81 ( V_73 , L_38 , L_39 ,
V_161 ) ;
F_81 ( V_73 , L_38 , L_40 , V_160 ) ;
if ( V_19 -> V_3 & V_33 )
F_81 ( V_73 , L_38 , L_41 ,
V_19 -> V_164 ) ;
F_149 ( V_73 , L_34 ) ;
if ( V_19 -> V_165 )
V_19 -> V_165 ( V_19 , V_73 , V_74 ) ;
return 0 ;
}
static int F_151 ( struct V_81 * V_81 , struct V_82 * V_82 )
{
return F_85 ( V_82 , F_148 , V_81 -> V_83 ) ;
}
static int F_152 ( void * V_166 , T_4 V_167 )
{
struct V_18 * V_19 = V_166 ;
struct V_168 V_169 ;
int V_170 ;
V_169 . V_171 = V_172 ;
V_169 . V_173 = V_167 ;
if ( ! V_167 ) {
V_170 = V_19 -> V_174 . V_175 ( & V_19 -> V_174 , & V_169 ) ;
V_169 . V_173 = V_170 ;
}
V_19 -> V_174 . V_176 ( & V_19 -> V_174 , & V_169 ) ;
return 0 ;
}
static int F_153 ( void * V_166 , T_4 * V_167 )
{
struct V_18 * V_19 = V_166 ;
struct V_168 V_169 ;
int V_170 ;
V_169 . V_171 = V_172 ;
V_169 . V_173 = 0 ;
V_170 = V_19 -> V_174 . V_175 ( & V_19 -> V_174 , & V_169 ) ;
* V_167 = V_170 ;
return 0 ;
}
void F_154 ( struct V_7 * V_8 , struct V_18 * V_19 )
{
struct V_177 * V_178 ;
if ( ! V_19 -> V_31 -> V_32 || ! V_19 -> V_31 -> free )
F_9 ( L_42 ,
V_17 ) ;
F_155 ( & V_19 -> V_179 ) ;
V_19 -> V_164 = 0 ;
if ( V_19 -> V_3 & V_33 )
F_156 ( V_19 ) ;
if ( ( V_19 -> V_3 & V_33 ) || V_19 -> V_31 -> V_180 )
F_157 ( V_19 ) ;
V_19 -> V_8 = V_8 ;
F_95 ( & V_8 -> V_45 ) ;
F_158 ( & V_19 -> V_14 , - V_19 -> V_62 ) ;
F_159 ( & V_19 -> V_14 , & V_8 -> V_147 ) ;
V_178 = F_98 ( V_19 -> V_80 , 0664 ,
V_8 -> V_181 , V_19 ,
& V_182 ) ;
if ( ! V_178 ) {
char V_97 [ 256 ] , * V_98 ;
V_98 = F_99 ( V_8 -> V_181 , V_97 , 256 ) ;
F_9 ( L_43 ,
V_98 , V_19 -> V_80 ) ;
}
if ( V_19 -> V_174 . V_175 && V_19 -> V_174 . V_176 ) {
char V_159 [ 64 ] ;
snprintf ( V_159 , 64 , L_44 , V_19 -> V_80 ) ;
V_178 = F_98 (
V_159 , 0644 , V_8 -> V_181 , V_19 ,
& V_183 ) ;
if ( ! V_178 ) {
char V_97 [ 256 ] , * V_98 ;
V_98 = F_99 ( V_8 -> V_181 , V_97 , 256 ) ;
F_9 ( L_45 ,
V_98 , V_159 ) ;
}
}
V_8 -> V_151 ++ ;
F_97 ( & V_8 -> V_45 ) ;
}
struct V_7 * F_160 ( long (* F_161)
( struct V_58 * V_59 ,
unsigned int V_184 ,
unsigned long V_185 ) )
{
struct V_7 * V_186 ;
int V_27 ;
V_186 = F_14 ( sizeof( * V_186 ) , V_28 ) ;
if ( ! V_186 )
return F_15 ( - V_29 ) ;
V_186 -> V_8 . V_187 = V_188 ;
V_186 -> V_8 . V_80 = L_46 ;
V_186 -> V_8 . V_189 = & V_190 ;
V_186 -> V_8 . V_12 = NULL ;
V_27 = F_162 ( & V_186 -> V_8 ) ;
if ( V_27 ) {
F_9 ( L_47 ) ;
F_30 ( V_186 ) ;
return F_15 ( V_27 ) ;
}
V_186 -> V_94 = F_163 ( L_46 , NULL ) ;
if ( ! V_186 -> V_94 ) {
F_9 ( L_48 ) ;
goto V_191;
}
V_186 -> V_181 = F_163 ( L_49 , V_186 -> V_94 ) ;
if ( ! V_186 -> V_181 ) {
F_9 ( L_50 ) ;
goto V_191;
}
V_186 -> V_95 = F_163 ( L_51 ,
V_186 -> V_94 ) ;
if ( ! V_186 -> V_95 )
F_9 ( L_52 ) ;
V_191:
V_186 -> F_161 = F_161 ;
V_186 -> V_11 = V_90 ;
F_24 ( & V_186 -> V_46 ) ;
F_164 ( & V_186 -> V_45 ) ;
F_165 ( & V_186 -> V_147 ) ;
V_186 -> V_71 = V_90 ;
V_70 = & V_186 -> V_71 ;
F_24 ( & V_79 ) ;
return V_186 ;
}
void F_166 ( struct V_7 * V_8 )
{
F_167 ( & V_8 -> V_8 ) ;
F_102 ( V_8 -> V_94 ) ;
F_30 ( V_8 ) ;
}
