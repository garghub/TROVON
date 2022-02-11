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
V_2 = F_14 ( sizeof( struct V_1 ) , V_28 ) ;
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
V_2 -> V_8 = V_8 ;
V_2 -> V_35 = V_20 ;
V_23 = V_19 -> V_31 -> V_36 ( V_19 , V_2 ) ;
if ( F_18 ( V_23 == NULL ,
L_2 ) )
V_23 = F_15 ( - V_37 ) ;
if ( F_19 ( V_23 ) ) {
V_27 = - V_37 ;
goto V_38;
}
V_2 -> V_22 = V_23 ;
if ( F_1 ( V_2 ) ) {
int V_39 = F_20 ( V_2 -> V_35 ) / V_40 ;
struct V_24 * V_25 ;
int V_26 , V_41 , V_42 = 0 ;
V_2 -> V_43 = F_21 ( sizeof( struct V_6 * ) * V_39 ) ;
if ( ! V_2 -> V_43 ) {
V_27 = - V_29 ;
goto V_44;
}
F_22 (table->sgl, sg, table->nents, i) {
struct V_6 * V_6 = F_23 ( V_25 ) ;
for ( V_41 = 0 ; V_41 < V_25 -> V_45 / V_40 ; V_41 ++ )
V_2 -> V_43 [ V_42 ++ ] = V_6 ++ ;
}
}
V_2 -> V_8 = V_8 ;
V_2 -> V_35 = V_20 ;
F_24 ( & V_2 -> V_46 ) ;
F_25 ( & V_2 -> V_47 ) ;
F_22 (buffer->sg_table->sgl, sg, buffer->sg_table->nents, i) {
F_26 ( V_25 ) = F_27 ( V_25 ) ;
F_28 ( V_25 ) = V_25 -> V_45 ;
}
F_29 ( & V_8 -> V_48 ) ;
F_7 ( V_8 , V_2 ) ;
F_30 ( & V_8 -> V_48 ) ;
return V_2 ;
V_44:
V_19 -> V_31 -> V_49 ( V_19 , V_2 ) ;
V_38:
V_19 -> V_31 -> free ( V_2 ) ;
V_34:
F_31 ( V_2 ) ;
return F_15 ( V_27 ) ;
}
void F_32 ( struct V_1 * V_2 )
{
if ( F_33 ( V_2 -> V_50 > 0 ) )
V_2 -> V_19 -> V_31 -> V_51 ( V_2 -> V_19 , V_2 ) ;
V_2 -> V_19 -> V_31 -> V_49 ( V_2 -> V_19 , V_2 ) ;
V_2 -> V_19 -> V_31 -> free ( V_2 ) ;
F_34 ( V_2 -> V_43 ) ;
F_31 ( V_2 ) ;
}
static void F_35 ( struct V_52 * V_52 )
{
struct V_1 * V_2 = F_36 ( V_52 , struct V_1 , V_30 ) ;
struct V_18 * V_19 = V_2 -> V_19 ;
struct V_7 * V_8 = V_2 -> V_8 ;
F_29 ( & V_8 -> V_48 ) ;
F_37 ( & V_2 -> V_14 , & V_8 -> V_11 ) ;
F_30 ( & V_8 -> V_48 ) ;
if ( V_19 -> V_3 & V_33 )
F_38 ( V_19 , V_2 ) ;
else
F_32 ( V_2 ) ;
}
static void F_39 ( struct V_1 * V_2 )
{
F_40 ( & V_2 -> V_30 ) ;
}
static int F_41 ( struct V_1 * V_2 )
{
return F_42 ( & V_2 -> V_30 , F_35 ) ;
}
static void F_43 ( struct V_1 * V_2 )
{
F_29 ( & V_2 -> V_47 ) ;
V_2 -> V_53 ++ ;
F_30 ( & V_2 -> V_47 ) ;
}
static void F_44 ( struct V_1 * V_2 )
{
F_29 ( & V_2 -> V_47 ) ;
V_2 -> V_53 -- ;
F_45 ( V_2 -> V_53 < 0 ) ;
if ( ! V_2 -> V_53 ) {
struct V_54 * V_55 ;
V_55 = V_56 -> V_57 ;
F_46 ( V_2 -> V_58 , V_55 ) ;
V_2 -> V_59 = F_47 ( V_55 ) ;
}
F_30 ( & V_2 -> V_47 ) ;
}
static struct V_60 * F_48 ( struct V_61 * V_62 ,
struct V_1 * V_2 )
{
struct V_60 * V_63 ;
V_63 = F_14 ( sizeof( struct V_60 ) , V_28 ) ;
if ( ! V_63 )
return F_15 ( - V_29 ) ;
F_16 ( & V_63 -> V_30 ) ;
F_49 ( & V_63 -> V_14 ) ;
V_63 -> V_62 = V_62 ;
F_39 ( V_2 ) ;
F_43 ( V_2 ) ;
V_63 -> V_2 = V_2 ;
return V_63 ;
}
static void F_50 ( struct V_52 * V_52 )
{
struct V_60 * V_63 = F_36 ( V_52 , struct V_60 , V_30 ) ;
struct V_61 * V_62 = V_63 -> V_62 ;
struct V_1 * V_2 = V_63 -> V_2 ;
F_29 ( & V_2 -> V_47 ) ;
while ( V_63 -> V_50 )
F_51 ( V_63 ) ;
F_30 ( & V_2 -> V_47 ) ;
F_52 ( & V_62 -> V_64 , V_63 -> V_65 ) ;
if ( ! F_53 ( & V_63 -> V_14 ) )
F_37 ( & V_63 -> V_14 , & V_62 -> V_66 ) ;
F_44 ( V_2 ) ;
F_41 ( V_2 ) ;
F_31 ( V_63 ) ;
}
struct V_1 * F_54 ( struct V_60 * V_63 )
{
return V_63 -> V_2 ;
}
static void F_55 ( struct V_60 * V_63 )
{
F_40 ( & V_63 -> V_30 ) ;
}
static int F_56 ( struct V_60 * V_63 )
{
int V_27 ;
V_27 = F_42 ( & V_63 -> V_30 , F_50 ) ;
return V_27 ;
}
int F_57 ( struct V_60 * V_63 )
{
struct V_61 * V_62 = V_63 -> V_62 ;
int V_27 ;
F_29 ( & V_62 -> V_47 ) ;
V_27 = F_56 ( V_63 ) ;
F_30 ( & V_62 -> V_47 ) ;
return V_27 ;
}
static struct V_60 * F_58 ( struct V_61 * V_62 ,
struct V_1 * V_2 )
{
struct V_9 * V_67 = V_62 -> V_66 . V_9 ;
while ( V_67 ) {
struct V_60 * V_13 = F_8 ( V_67 , struct V_60 , V_14 ) ;
if ( V_2 < V_13 -> V_2 )
V_67 = V_67 -> V_15 ;
else if ( V_2 > V_13 -> V_2 )
V_67 = V_67 -> V_16 ;
else
return V_13 ;
}
return F_15 ( - V_37 ) ;
}
static struct V_60 * F_59 ( struct V_61 * V_62 ,
int V_65 )
{
struct V_60 * V_63 ;
V_63 = F_60 ( & V_62 -> V_64 , V_65 ) ;
if ( V_63 )
F_55 ( V_63 ) ;
return V_63 ? V_63 : F_15 ( - V_37 ) ;
}
struct V_60 * F_61 ( struct V_61 * V_62 ,
int V_65 )
{
struct V_60 * V_63 ;
F_29 ( & V_62 -> V_47 ) ;
V_63 = F_59 ( V_62 , V_65 ) ;
F_30 ( & V_62 -> V_47 ) ;
return V_63 ;
}
static bool F_62 ( struct V_61 * V_62 ,
struct V_60 * V_63 )
{
F_33 ( ! F_63 ( & V_62 -> V_47 ) ) ;
return F_60 ( & V_62 -> V_64 , V_63 -> V_65 ) == V_63 ;
}
static int F_64 ( struct V_61 * V_62 , struct V_60 * V_63 )
{
int V_65 ;
struct V_9 * * V_10 = & V_62 -> V_66 . V_9 ;
struct V_9 * V_12 = NULL ;
struct V_60 * V_13 ;
V_65 = F_65 ( & V_62 -> V_64 , V_63 , 1 , 0 , V_28 ) ;
if ( V_65 < 0 )
return V_65 ;
V_63 -> V_65 = V_65 ;
while ( * V_10 ) {
V_12 = * V_10 ;
V_13 = F_8 ( V_12 , struct V_60 , V_14 ) ;
if ( V_63 -> V_2 < V_13 -> V_2 )
V_10 = & ( * V_10 ) -> V_15 ;
else if ( V_63 -> V_2 > V_13 -> V_2 )
V_10 = & ( * V_10 ) -> V_16 ;
else
F_66 ( 1 , L_1 , V_17 ) ;
}
F_11 ( & V_63 -> V_14 , V_12 , V_10 ) ;
F_12 ( & V_63 -> V_14 , & V_62 -> V_66 ) ;
return 0 ;
}
struct V_60 * F_67 ( struct V_61 * V_62 , T_1 V_20 ,
T_1 V_21 , unsigned int V_68 ,
unsigned int V_3 )
{
struct V_60 * V_63 ;
struct V_7 * V_8 = V_62 -> V_8 ;
struct V_1 * V_2 = NULL ;
struct V_18 * V_19 ;
int V_27 ;
F_68 ( L_3 , V_17 ,
V_20 , V_21 , V_68 , V_3 ) ;
V_20 = F_20 ( V_20 ) ;
if ( ! V_20 )
return F_15 ( - V_37 ) ;
F_69 ( & V_8 -> V_47 ) ;
F_70 (heap, &dev->heaps, node) {
if ( ! ( ( 1 << V_19 -> V_65 ) & V_68 ) )
continue;
V_2 = F_13 ( V_19 , V_8 , V_20 , V_21 , V_3 ) ;
if ( ! F_19 ( V_2 ) )
break;
}
F_71 ( & V_8 -> V_47 ) ;
if ( V_2 == NULL )
return F_15 ( - V_69 ) ;
if ( F_19 ( V_2 ) )
return F_72 ( V_2 ) ;
V_63 = F_48 ( V_62 , V_2 ) ;
F_41 ( V_2 ) ;
if ( F_19 ( V_63 ) )
return V_63 ;
F_29 ( & V_62 -> V_47 ) ;
V_27 = F_64 ( V_62 , V_63 ) ;
F_30 ( & V_62 -> V_47 ) ;
if ( V_27 ) {
F_57 ( V_63 ) ;
V_63 = F_15 ( V_27 ) ;
}
return V_63 ;
}
static void F_73 ( struct V_61 * V_62 , struct V_60 * V_63 )
{
bool V_70 ;
F_45 ( V_62 != V_63 -> V_62 ) ;
V_70 = F_62 ( V_62 , V_63 ) ;
if ( ! V_70 ) {
F_66 ( 1 , L_4 , V_17 ) ;
return;
}
F_56 ( V_63 ) ;
}
void F_74 ( struct V_61 * V_62 , struct V_60 * V_63 )
{
F_45 ( V_62 != V_63 -> V_62 ) ;
F_29 ( & V_62 -> V_47 ) ;
F_73 ( V_62 , V_63 ) ;
F_30 ( & V_62 -> V_47 ) ;
}
int F_75 ( struct V_61 * V_62 , struct V_60 * V_63 ,
T_2 * V_71 , T_1 * V_20 )
{
struct V_1 * V_2 ;
int V_27 ;
F_29 ( & V_62 -> V_47 ) ;
if ( ! F_62 ( V_62 , V_63 ) ) {
F_30 ( & V_62 -> V_47 ) ;
return - V_37 ;
}
V_2 = V_63 -> V_2 ;
if ( ! V_2 -> V_19 -> V_31 -> V_72 ) {
F_9 ( L_5 ,
V_17 , V_2 -> V_19 -> V_73 , V_2 -> V_19 -> type ) ;
F_30 ( & V_62 -> V_47 ) ;
return - V_69 ;
}
F_30 ( & V_62 -> V_47 ) ;
V_27 = V_2 -> V_19 -> V_31 -> V_72 ( V_2 -> V_19 , V_2 , V_71 , V_20 ) ;
return V_27 ;
}
static void * F_76 ( struct V_1 * V_2 )
{
void * V_74 ;
if ( V_2 -> V_50 ) {
V_2 -> V_50 ++ ;
return V_2 -> V_74 ;
}
V_74 = V_2 -> V_19 -> V_31 -> V_75 ( V_2 -> V_19 , V_2 ) ;
if ( F_18 ( V_74 == NULL ,
L_6 ) )
return F_15 ( - V_37 ) ;
if ( F_19 ( V_74 ) )
return V_74 ;
V_2 -> V_74 = V_74 ;
V_2 -> V_50 ++ ;
return V_74 ;
}
static void * F_77 ( struct V_60 * V_63 )
{
struct V_1 * V_2 = V_63 -> V_2 ;
void * V_74 ;
if ( V_63 -> V_50 ) {
V_63 -> V_50 ++ ;
return V_2 -> V_74 ;
}
V_74 = F_76 ( V_2 ) ;
if ( F_19 ( V_74 ) )
return V_74 ;
V_63 -> V_50 ++ ;
return V_74 ;
}
static void F_78 ( struct V_1 * V_2 )
{
V_2 -> V_50 -- ;
if ( ! V_2 -> V_50 ) {
V_2 -> V_19 -> V_31 -> V_51 ( V_2 -> V_19 , V_2 ) ;
V_2 -> V_74 = NULL ;
}
}
static void F_51 ( struct V_60 * V_63 )
{
struct V_1 * V_2 = V_63 -> V_2 ;
if ( ! V_63 -> V_50 ) {
F_66 ( 1 , L_7 , V_17 ) ;
return;
}
V_63 -> V_50 -- ;
if ( ! V_63 -> V_50 )
F_78 ( V_2 ) ;
}
void * F_79 ( struct V_61 * V_62 , struct V_60 * V_63 )
{
struct V_1 * V_2 ;
void * V_74 ;
F_29 ( & V_62 -> V_47 ) ;
if ( ! F_62 ( V_62 , V_63 ) ) {
F_9 ( L_8 ,
V_17 ) ;
F_30 ( & V_62 -> V_47 ) ;
return F_15 ( - V_37 ) ;
}
V_2 = V_63 -> V_2 ;
if ( ! V_63 -> V_2 -> V_19 -> V_31 -> V_75 ) {
F_9 ( L_9 ,
V_17 ) ;
F_30 ( & V_62 -> V_47 ) ;
return F_15 ( - V_69 ) ;
}
F_29 ( & V_2 -> V_47 ) ;
V_74 = F_77 ( V_63 ) ;
F_30 ( & V_2 -> V_47 ) ;
F_30 ( & V_62 -> V_47 ) ;
return V_74 ;
}
void F_80 ( struct V_61 * V_62 , struct V_60 * V_63 )
{
struct V_1 * V_2 ;
F_29 ( & V_62 -> V_47 ) ;
V_2 = V_63 -> V_2 ;
F_29 ( & V_2 -> V_47 ) ;
F_51 ( V_63 ) ;
F_30 ( & V_2 -> V_47 ) ;
F_30 ( & V_62 -> V_47 ) ;
}
static int F_81 ( struct V_61 * V_62 )
{
struct V_9 * V_14 ;
struct V_61 * V_76 ;
struct V_7 * V_8 ;
V_14 = V_77 -> V_9 ;
V_8 = F_36 ( V_77 , struct V_7 , V_78 ) ;
F_69 ( & V_8 -> V_47 ) ;
while ( V_14 ) {
V_76 = F_8 ( V_14 , struct V_61 , V_14 ) ;
if ( V_62 < V_76 ) {
V_14 = V_14 -> V_15 ;
} else if ( V_62 > V_76 ) {
V_14 = V_14 -> V_16 ;
} else {
F_71 ( & V_8 -> V_47 ) ;
return 1 ;
}
}
F_71 ( & V_8 -> V_47 ) ;
return 0 ;
}
static int F_82 ( struct V_79 * V_80 , void * V_81 )
{
struct V_61 * V_62 = V_80 -> V_82 ;
struct V_9 * V_67 ;
T_1 V_83 [ V_84 ] = { 0 } ;
const char * V_85 [ V_84 ] = { NULL } ;
int V_26 ;
F_29 ( & V_86 ) ;
if ( ! F_81 ( V_62 ) ) {
F_83 ( V_80 , L_10 ,
V_62 ) ;
F_30 ( & V_86 ) ;
return 0 ;
}
F_29 ( & V_62 -> V_47 ) ;
for ( V_67 = F_84 ( & V_62 -> V_66 ) ; V_67 ; V_67 = F_85 ( V_67 ) ) {
struct V_60 * V_63 = F_8 ( V_67 , struct V_60 ,
V_14 ) ;
unsigned int V_65 = V_63 -> V_2 -> V_19 -> V_65 ;
if ( ! V_85 [ V_65 ] )
V_85 [ V_65 ] = V_63 -> V_2 -> V_19 -> V_73 ;
V_83 [ V_65 ] += V_63 -> V_2 -> V_35 ;
}
F_30 ( & V_62 -> V_47 ) ;
F_30 ( & V_86 ) ;
F_83 ( V_80 , L_11 , L_12 , L_13 ) ;
for ( V_26 = 0 ; V_26 < V_84 ; V_26 ++ ) {
if ( ! V_85 [ V_26 ] )
continue;
F_83 ( V_80 , L_14 , V_85 [ V_26 ] , V_83 [ V_26 ] ) ;
}
return 0 ;
}
static int F_86 ( struct V_87 * V_87 , struct V_88 * V_88 )
{
return F_87 ( V_88 , F_82 , V_87 -> V_89 ) ;
}
static int F_88 ( const struct V_90 * V_91 ,
const unsigned char * V_73 )
{
int V_92 = - 1 ;
struct V_9 * V_14 ;
for ( V_14 = F_84 ( V_91 ) ; V_14 ; V_14 = F_85 ( V_14 ) ) {
struct V_61 * V_62 = F_8 ( V_14 , struct V_61 ,
V_14 ) ;
if ( strcmp ( V_62 -> V_73 , V_73 ) )
continue;
V_92 = F_89 ( V_92 , V_62 -> V_93 ) ;
}
return V_92 + 1 ;
}
struct V_61 * F_90 ( struct V_7 * V_8 ,
const char * V_73 )
{
struct V_61 * V_62 ;
struct V_54 * V_55 ;
struct V_9 * * V_10 ;
struct V_9 * V_12 = NULL ;
struct V_61 * V_13 ;
T_3 V_59 ;
if ( ! V_73 ) {
F_9 ( L_15 , V_17 ) ;
return F_15 ( - V_37 ) ;
}
F_91 ( V_56 -> V_57 ) ;
F_92 ( V_56 -> V_57 ) ;
V_59 = F_47 ( V_56 -> V_57 ) ;
if ( V_56 -> V_57 -> V_3 & V_94 ) {
F_93 ( V_56 -> V_57 ) ;
V_55 = NULL ;
} else {
V_55 = V_56 -> V_57 ;
}
F_94 ( V_56 -> V_57 ) ;
V_62 = F_14 ( sizeof( struct V_61 ) , V_28 ) ;
if ( ! V_62 )
goto V_95;
V_62 -> V_8 = V_8 ;
V_62 -> V_66 = V_96 ;
F_95 ( & V_62 -> V_64 ) ;
F_25 ( & V_62 -> V_47 ) ;
V_62 -> V_55 = V_55 ;
V_62 -> V_59 = V_59 ;
V_62 -> V_73 = F_96 ( V_73 , V_28 ) ;
if ( ! V_62 -> V_73 )
goto V_97;
F_97 ( & V_8 -> V_47 ) ;
V_62 -> V_93 = F_88 ( & V_8 -> V_78 , V_73 ) ;
V_62 -> V_98 = F_98 (
V_28 , L_16 , V_73 , V_62 -> V_93 ) ;
if ( ! V_62 -> V_98 ) {
F_99 ( & V_8 -> V_47 ) ;
goto V_99;
}
V_10 = & V_8 -> V_78 . V_9 ;
while ( * V_10 ) {
V_12 = * V_10 ;
V_13 = F_8 ( V_12 , struct V_61 , V_14 ) ;
if ( V_62 < V_13 )
V_10 = & ( * V_10 ) -> V_15 ;
else if ( V_62 > V_13 )
V_10 = & ( * V_10 ) -> V_16 ;
}
F_11 ( & V_62 -> V_14 , V_12 , V_10 ) ;
F_12 ( & V_62 -> V_14 , & V_8 -> V_78 ) ;
V_62 -> V_100 = F_100 ( V_62 -> V_98 , 0664 ,
V_8 -> V_101 ,
V_62 , & V_102 ) ;
if ( ! V_62 -> V_100 ) {
char V_103 [ 256 ] , * V_104 ;
V_104 = F_101 ( V_8 -> V_101 , V_103 , 256 ) ;
F_9 ( L_17 ,
V_104 , V_62 -> V_98 ) ;
}
F_99 ( & V_8 -> V_47 ) ;
return V_62 ;
V_99:
F_31 ( V_62 -> V_73 ) ;
V_97:
F_31 ( V_62 ) ;
V_95:
if ( V_55 )
F_93 ( V_56 -> V_57 ) ;
return F_15 ( - V_29 ) ;
}
void F_102 ( struct V_61 * V_62 )
{
struct V_7 * V_8 = V_62 -> V_8 ;
struct V_9 * V_67 ;
F_68 ( L_18 , V_17 , __LINE__ ) ;
F_29 ( & V_86 ) ;
while ( ( V_67 = F_84 ( & V_62 -> V_66 ) ) ) {
struct V_60 * V_63 = F_8 ( V_67 , struct V_60 ,
V_14 ) ;
F_50 ( & V_63 -> V_30 ) ;
}
F_103 ( & V_62 -> V_64 ) ;
F_97 ( & V_8 -> V_47 ) ;
if ( V_62 -> V_55 )
F_93 ( V_62 -> V_55 ) ;
F_37 ( & V_62 -> V_14 , & V_8 -> V_78 ) ;
F_104 ( V_62 -> V_100 ) ;
F_99 ( & V_8 -> V_47 ) ;
F_31 ( V_62 -> V_98 ) ;
F_31 ( V_62 -> V_73 ) ;
F_31 ( V_62 ) ;
F_30 ( & V_86 ) ;
}
struct V_22 * F_105 ( struct V_61 * V_62 ,
struct V_60 * V_63 )
{
struct V_1 * V_2 ;
struct V_22 * V_23 ;
F_29 ( & V_62 -> V_47 ) ;
if ( ! F_62 ( V_62 , V_63 ) ) {
F_9 ( L_19 ,
V_17 ) ;
F_30 ( & V_62 -> V_47 ) ;
return F_15 ( - V_37 ) ;
}
V_2 = V_63 -> V_2 ;
V_23 = V_2 -> V_22 ;
F_30 ( & V_62 -> V_47 ) ;
return V_23 ;
}
static struct V_22 * F_106 ( struct V_105 * V_106 ,
enum V_107 V_108 )
{
struct V_109 * V_110 = V_106 -> V_110 ;
struct V_1 * V_2 = V_110 -> V_111 ;
F_107 ( V_2 , V_106 -> V_8 , V_108 ) ;
return V_2 -> V_22 ;
}
static void F_108 ( struct V_105 * V_106 ,
struct V_22 * V_23 ,
enum V_107 V_108 )
{
}
void F_109 ( struct V_112 * V_8 , struct V_6 * V_6 ,
T_1 V_35 , enum V_107 V_113 )
{
struct V_24 V_25 ;
F_110 ( & V_25 , 1 ) ;
F_111 ( & V_25 , V_6 , V_35 , 0 ) ;
F_26 ( & V_25 ) = F_112 ( V_6 ) ;
F_113 ( V_8 , & V_25 , 1 , V_113 ) ;
}
static void F_107 ( struct V_1 * V_2 ,
struct V_112 * V_8 ,
enum V_107 V_113 )
{
struct V_114 * V_115 ;
int V_43 = F_20 ( V_2 -> V_35 ) / V_40 ;
int V_26 ;
F_68 ( L_20 , V_17 ,
V_8 ? F_114 ( V_8 ) : L_21 ) ;
if ( ! F_1 ( V_2 ) )
return;
F_29 ( & V_2 -> V_47 ) ;
for ( V_26 = 0 ; V_26 < V_43 ; V_26 ++ ) {
struct V_6 * V_6 = V_2 -> V_43 [ V_26 ] ;
if ( F_4 ( V_6 ) )
F_109 ( V_8 , F_3 ( V_6 ) ,
V_40 , V_113 ) ;
F_6 ( V_2 -> V_43 + V_26 ) ;
}
F_115 (vma_list, &buffer->vmas, list) {
struct V_116 * V_117 = V_115 -> V_117 ;
F_116 ( V_117 , V_117 -> V_118 , V_117 -> V_119 - V_117 -> V_118 ,
NULL ) ;
}
F_30 ( & V_2 -> V_47 ) ;
}
static int F_117 ( struct V_116 * V_117 , struct V_120 * V_121 )
{
struct V_1 * V_2 = V_117 -> V_122 ;
unsigned long V_123 ;
int V_27 ;
F_29 ( & V_2 -> V_47 ) ;
F_5 ( V_2 -> V_43 + V_121 -> V_124 ) ;
F_45 ( ! V_2 -> V_43 || ! V_2 -> V_43 [ V_121 -> V_124 ] ) ;
V_123 = F_118 ( F_3 ( V_2 -> V_43 [ V_121 -> V_124 ] ) ) ;
V_27 = F_119 ( V_117 , ( unsigned long ) V_121 -> V_125 , V_123 ) ;
F_30 ( & V_2 -> V_47 ) ;
if ( V_27 )
return V_126 ;
return V_127 ;
}
static void F_120 ( struct V_116 * V_117 )
{
struct V_1 * V_2 = V_117 -> V_122 ;
struct V_114 * V_115 ;
V_115 = F_121 ( sizeof( struct V_114 ) , V_28 ) ;
if ( ! V_115 )
return;
V_115 -> V_117 = V_117 ;
F_29 ( & V_2 -> V_47 ) ;
F_122 ( & V_115 -> V_128 , & V_2 -> V_46 ) ;
F_30 ( & V_2 -> V_47 ) ;
F_68 ( L_22 , V_17 , V_117 ) ;
}
static void F_123 ( struct V_116 * V_117 )
{
struct V_1 * V_2 = V_117 -> V_122 ;
struct V_114 * V_115 , * V_76 ;
F_68 ( L_23 , V_17 ) ;
F_29 ( & V_2 -> V_47 ) ;
F_124 (vma_list, tmp, &buffer->vmas, list) {
if ( V_115 -> V_117 != V_117 )
continue;
F_125 ( & V_115 -> V_128 ) ;
F_31 ( V_115 ) ;
F_68 ( L_24 , V_17 , V_117 ) ;
break;
}
F_30 ( & V_2 -> V_47 ) ;
}
static int F_126 ( struct V_109 * V_110 , struct V_116 * V_117 )
{
struct V_1 * V_2 = V_110 -> V_111 ;
int V_27 = 0 ;
if ( ! V_2 -> V_19 -> V_31 -> V_129 ) {
F_9 ( L_25 ,
V_17 ) ;
return - V_37 ;
}
if ( F_1 ( V_2 ) ) {
V_117 -> V_130 |= V_131 | V_132 | V_133 |
V_134 ;
V_117 -> V_122 = V_2 ;
V_117 -> V_135 = & V_136 ;
F_120 ( V_117 ) ;
return 0 ;
}
if ( ! ( V_2 -> V_3 & V_4 ) )
V_117 -> V_137 = F_127 ( V_117 -> V_137 ) ;
F_29 ( & V_2 -> V_47 ) ;
V_27 = V_2 -> V_19 -> V_31 -> V_129 ( V_2 -> V_19 , V_2 , V_117 ) ;
F_30 ( & V_2 -> V_47 ) ;
if ( V_27 )
F_9 ( L_26 ,
V_17 ) ;
return V_27 ;
}
static void F_128 ( struct V_109 * V_110 )
{
struct V_1 * V_2 = V_110 -> V_111 ;
F_41 ( V_2 ) ;
}
static void * F_129 ( struct V_109 * V_110 , unsigned long V_138 )
{
struct V_1 * V_2 = V_110 -> V_111 ;
return V_2 -> V_74 + V_138 * V_40 ;
}
static void F_130 ( struct V_109 * V_110 , unsigned long V_138 ,
void * V_139 )
{
}
static int F_131 ( struct V_109 * V_110 ,
enum V_107 V_108 )
{
struct V_1 * V_2 = V_110 -> V_111 ;
void * V_74 ;
if ( ! V_2 -> V_19 -> V_31 -> V_75 ) {
F_9 ( L_27 ,
V_17 ) ;
return - V_69 ;
}
F_29 ( & V_2 -> V_47 ) ;
V_74 = F_76 ( V_2 ) ;
F_30 ( & V_2 -> V_47 ) ;
return F_132 ( V_74 ) ;
}
static int F_133 ( struct V_109 * V_110 ,
enum V_107 V_108 )
{
struct V_1 * V_2 = V_110 -> V_111 ;
F_29 ( & V_2 -> V_47 ) ;
F_78 ( V_2 ) ;
F_30 ( & V_2 -> V_47 ) ;
return 0 ;
}
struct V_109 * F_134 ( struct V_61 * V_62 ,
struct V_60 * V_63 )
{
F_135 ( V_140 ) ;
struct V_1 * V_2 ;
struct V_109 * V_110 ;
bool V_70 ;
F_29 ( & V_62 -> V_47 ) ;
V_70 = F_62 ( V_62 , V_63 ) ;
if ( ! V_70 ) {
F_66 ( 1 , L_28 , V_17 ) ;
F_30 ( & V_62 -> V_47 ) ;
return F_15 ( - V_37 ) ;
}
V_2 = V_63 -> V_2 ;
F_39 ( V_2 ) ;
F_30 ( & V_62 -> V_47 ) ;
V_140 . V_31 = & V_141 ;
V_140 . V_35 = V_2 -> V_35 ;
V_140 . V_3 = V_142 ;
V_140 . V_111 = V_2 ;
V_110 = F_136 ( & V_140 ) ;
if ( F_19 ( V_110 ) ) {
F_41 ( V_2 ) ;
return V_110 ;
}
return V_110 ;
}
int F_137 ( struct V_61 * V_62 , struct V_60 * V_63 )
{
struct V_109 * V_110 ;
int V_143 ;
V_110 = F_134 ( V_62 , V_63 ) ;
if ( F_19 ( V_110 ) )
return F_138 ( V_110 ) ;
V_143 = F_139 ( V_110 , V_144 ) ;
if ( V_143 < 0 )
F_140 ( V_110 ) ;
return V_143 ;
}
struct V_60 * F_141 ( struct V_61 * V_62 ,
struct V_109 * V_110 )
{
struct V_1 * V_2 ;
struct V_60 * V_63 ;
int V_27 ;
if ( V_110 -> V_31 != & V_141 ) {
F_9 ( L_29 ,
V_17 ) ;
return F_15 ( - V_37 ) ;
}
V_2 = V_110 -> V_111 ;
F_29 ( & V_62 -> V_47 ) ;
V_63 = F_58 ( V_62 , V_2 ) ;
if ( ! F_19 ( V_63 ) ) {
F_55 ( V_63 ) ;
F_30 ( & V_62 -> V_47 ) ;
goto V_145;
}
V_63 = F_48 ( V_62 , V_2 ) ;
if ( F_19 ( V_63 ) ) {
F_30 ( & V_62 -> V_47 ) ;
goto V_145;
}
V_27 = F_64 ( V_62 , V_63 ) ;
F_30 ( & V_62 -> V_47 ) ;
if ( V_27 ) {
F_57 ( V_63 ) ;
V_63 = F_15 ( V_27 ) ;
}
V_145:
return V_63 ;
}
struct V_60 * F_142 ( struct V_61 * V_62 , int V_143 )
{
struct V_109 * V_110 ;
struct V_60 * V_63 ;
V_110 = F_143 ( V_143 ) ;
if ( F_19 ( V_110 ) )
return F_72 ( V_110 ) ;
V_63 = F_141 ( V_62 , V_110 ) ;
F_140 ( V_110 ) ;
return V_63 ;
}
static int F_144 ( struct V_61 * V_62 , int V_143 )
{
struct V_109 * V_110 ;
struct V_1 * V_2 ;
V_110 = F_143 ( V_143 ) ;
if ( F_19 ( V_110 ) )
return F_138 ( V_110 ) ;
if ( V_110 -> V_31 != & V_141 ) {
F_9 ( L_30 ,
V_17 ) ;
F_140 ( V_110 ) ;
return - V_37 ;
}
V_2 = V_110 -> V_111 ;
F_113 ( NULL , V_2 -> V_22 -> V_146 ,
V_2 -> V_22 -> V_147 , V_148 ) ;
F_140 ( V_110 ) ;
return 0 ;
}
static unsigned int F_145 ( unsigned int V_149 )
{
switch ( V_149 ) {
case V_150 :
case V_151 :
case V_152 :
return V_153 ;
default:
return F_146 ( V_149 ) ;
}
}
static long F_147 ( struct V_88 * V_154 , unsigned int V_149 , unsigned long V_155 )
{
struct V_61 * V_62 = V_154 -> V_156 ;
struct V_7 * V_8 = V_62 -> V_8 ;
struct V_60 * V_157 = NULL ;
int V_27 = 0 ;
unsigned int V_113 ;
union {
struct V_158 V_143 ;
struct V_159 V_160 ;
struct V_161 V_63 ;
struct V_162 V_163 ;
} V_164 ;
V_113 = F_145 ( V_149 ) ;
if ( F_148 ( V_149 ) > sizeof( V_164 ) )
return - V_37 ;
if ( V_113 & V_153 )
if ( F_149 ( & V_164 , ( void V_165 * ) V_155 , F_148 ( V_149 ) ) )
return - V_166 ;
switch ( V_149 ) {
case V_167 :
{
struct V_60 * V_63 ;
V_63 = F_67 ( V_62 , V_164 . V_160 . V_20 ,
V_164 . V_160 . V_21 ,
V_164 . V_160 . V_68 ,
V_164 . V_160 . V_3 ) ;
if ( F_19 ( V_63 ) )
return F_138 ( V_63 ) ;
V_164 . V_160 . V_63 = V_63 -> V_65 ;
V_157 = V_63 ;
break;
}
case V_151 :
{
struct V_60 * V_63 ;
F_29 ( & V_62 -> V_47 ) ;
V_63 = F_59 ( V_62 , V_164 . V_63 . V_63 ) ;
if ( F_19 ( V_63 ) ) {
F_30 ( & V_62 -> V_47 ) ;
return F_138 ( V_63 ) ;
}
F_73 ( V_62 , V_63 ) ;
F_56 ( V_63 ) ;
F_30 ( & V_62 -> V_47 ) ;
break;
}
case V_168 :
case V_169 :
{
struct V_60 * V_63 ;
V_63 = F_61 ( V_62 , V_164 . V_63 . V_63 ) ;
if ( F_19 ( V_63 ) )
return F_138 ( V_63 ) ;
V_164 . V_143 . V_143 = F_137 ( V_62 , V_63 ) ;
F_57 ( V_63 ) ;
if ( V_164 . V_143 . V_143 < 0 )
V_27 = V_164 . V_143 . V_143 ;
break;
}
case V_170 :
{
struct V_60 * V_63 ;
V_63 = F_142 ( V_62 , V_164 . V_143 . V_143 ) ;
if ( F_19 ( V_63 ) )
V_27 = F_138 ( V_63 ) ;
else
V_164 . V_63 . V_63 = V_63 -> V_65 ;
break;
}
case V_150 :
{
V_27 = F_144 ( V_62 , V_164 . V_143 . V_143 ) ;
break;
}
case V_152 :
{
if ( ! V_8 -> V_171 )
return - V_172 ;
V_27 = V_8 -> V_171 ( V_62 , V_164 . V_163 . V_149 ,
V_164 . V_163 . V_155 ) ;
break;
}
default:
return - V_172 ;
}
if ( V_113 & V_173 ) {
if ( F_150 ( ( void V_165 * ) V_155 , & V_164 , F_148 ( V_149 ) ) ) {
if ( V_157 )
F_74 ( V_62 , V_157 ) ;
return - V_166 ;
}
}
return V_27 ;
}
static int F_151 ( struct V_87 * V_87 , struct V_88 * V_88 )
{
struct V_61 * V_62 = V_88 -> V_156 ;
F_68 ( L_18 , V_17 , __LINE__ ) ;
F_102 ( V_62 ) ;
return 0 ;
}
static int F_152 ( struct V_87 * V_87 , struct V_88 * V_88 )
{
struct V_174 * V_175 = V_88 -> V_156 ;
struct V_7 * V_8 = F_36 ( V_175 , struct V_7 , V_8 ) ;
struct V_61 * V_62 ;
char V_176 [ 64 ] ;
F_68 ( L_18 , V_17 , __LINE__ ) ;
snprintf ( V_176 , 64 , L_31 , F_47 ( V_56 -> V_57 ) ) ;
V_62 = F_90 ( V_8 , V_176 ) ;
if ( F_19 ( V_62 ) )
return F_138 ( V_62 ) ;
V_88 -> V_156 = V_62 ;
return 0 ;
}
static T_1 F_153 ( struct V_61 * V_62 ,
unsigned int V_65 )
{
T_1 V_35 = 0 ;
struct V_9 * V_67 ;
F_29 ( & V_62 -> V_47 ) ;
for ( V_67 = F_84 ( & V_62 -> V_66 ) ; V_67 ; V_67 = F_85 ( V_67 ) ) {
struct V_60 * V_63 = F_8 ( V_67 ,
struct V_60 ,
V_14 ) ;
if ( V_63 -> V_2 -> V_19 -> V_65 == V_65 )
V_35 += V_63 -> V_2 -> V_35 ;
}
F_30 ( & V_62 -> V_47 ) ;
return V_35 ;
}
static int F_154 ( struct V_79 * V_80 , void * V_81 )
{
struct V_18 * V_19 = V_80 -> V_82 ;
struct V_7 * V_8 = V_19 -> V_8 ;
struct V_9 * V_67 ;
T_1 V_177 = 0 ;
T_1 V_178 = 0 ;
F_83 ( V_80 , L_32 , L_33 , L_34 , L_35 ) ;
F_155 ( V_80 , L_36 ) ;
F_29 ( & V_86 ) ;
for ( V_67 = F_84 ( & V_8 -> V_78 ) ; V_67 ; V_67 = F_85 ( V_67 ) ) {
struct V_61 * V_62 = F_8 ( V_67 , struct V_61 ,
V_14 ) ;
T_1 V_35 = F_153 ( V_62 , V_19 -> V_65 ) ;
if ( ! V_35 )
continue;
if ( V_62 -> V_55 ) {
char V_58 [ V_179 ] ;
F_46 ( V_58 , V_62 -> V_55 ) ;
F_83 ( V_80 , L_37 , V_58 ,
V_62 -> V_59 , V_35 ) ;
} else {
F_83 ( V_80 , L_37 , V_62 -> V_73 ,
V_62 -> V_59 , V_35 ) ;
}
}
F_30 ( & V_86 ) ;
F_155 ( V_80 , L_36 ) ;
F_155 ( V_80 , L_38 ) ;
F_29 ( & V_8 -> V_48 ) ;
for ( V_67 = F_84 ( & V_8 -> V_11 ) ; V_67 ; V_67 = F_85 ( V_67 ) ) {
struct V_1 * V_2 = F_8 ( V_67 , struct V_1 ,
V_14 ) ;
if ( V_2 -> V_19 -> V_65 != V_19 -> V_65 )
continue;
V_177 += V_2 -> V_35 ;
if ( ! V_2 -> V_53 ) {
F_83 ( V_80 , L_39 ,
V_2 -> V_58 , V_2 -> V_59 ,
V_2 -> V_35 , V_2 -> V_50 ,
F_156 ( & V_2 -> V_30 . V_180 ) ) ;
V_178 += V_2 -> V_35 ;
}
}
F_30 ( & V_8 -> V_48 ) ;
F_155 ( V_80 , L_36 ) ;
F_83 ( V_80 , L_40 , L_41 ,
V_178 ) ;
F_83 ( V_80 , L_40 , L_42 , V_177 ) ;
if ( V_19 -> V_3 & V_33 )
F_83 ( V_80 , L_40 , L_43 ,
V_19 -> V_181 ) ;
F_155 ( V_80 , L_36 ) ;
if ( V_19 -> V_182 )
V_19 -> V_182 ( V_19 , V_80 , V_81 ) ;
return 0 ;
}
static int F_157 ( struct V_87 * V_87 , struct V_88 * V_88 )
{
return F_87 ( V_88 , F_154 , V_87 -> V_89 ) ;
}
static int F_158 ( void * V_164 , T_4 V_183 )
{
struct V_18 * V_19 = V_164 ;
struct V_184 V_185 ;
int V_186 ;
V_185 . V_187 = V_188 ;
V_185 . V_189 = V_183 ;
if ( ! V_183 ) {
V_186 = V_19 -> V_190 . V_191 ( & V_19 -> V_190 , & V_185 ) ;
V_185 . V_189 = V_186 ;
}
V_19 -> V_190 . V_192 ( & V_19 -> V_190 , & V_185 ) ;
return 0 ;
}
static int F_159 ( void * V_164 , T_4 * V_183 )
{
struct V_18 * V_19 = V_164 ;
struct V_184 V_185 ;
int V_186 ;
V_185 . V_187 = V_188 ;
V_185 . V_189 = 0 ;
V_186 = V_19 -> V_190 . V_191 ( & V_19 -> V_190 , & V_185 ) ;
* V_183 = V_186 ;
return 0 ;
}
void F_160 ( struct V_7 * V_8 , struct V_18 * V_19 )
{
struct V_193 * V_194 ;
if ( ! V_19 -> V_31 -> V_32 || ! V_19 -> V_31 -> free || ! V_19 -> V_31 -> V_36 ||
! V_19 -> V_31 -> V_49 )
F_9 ( L_44 ,
V_17 ) ;
F_161 ( & V_19 -> V_195 ) ;
V_19 -> V_181 = 0 ;
if ( V_19 -> V_3 & V_33 )
F_162 ( V_19 ) ;
if ( ( V_19 -> V_3 & V_33 ) || V_19 -> V_31 -> V_196 )
F_163 ( V_19 ) ;
V_19 -> V_8 = V_8 ;
F_97 ( & V_8 -> V_47 ) ;
F_164 ( & V_19 -> V_14 , - V_19 -> V_65 ) ;
F_165 ( & V_19 -> V_14 , & V_8 -> V_197 ) ;
V_194 = F_100 ( V_19 -> V_73 , 0664 ,
V_8 -> V_198 , V_19 ,
& V_199 ) ;
if ( ! V_194 ) {
char V_103 [ 256 ] , * V_104 ;
V_104 = F_101 ( V_8 -> V_198 , V_103 , 256 ) ;
F_9 ( L_45 ,
V_104 , V_19 -> V_73 ) ;
}
if ( V_19 -> V_190 . V_191 && V_19 -> V_190 . V_192 ) {
char V_176 [ 64 ] ;
snprintf ( V_176 , 64 , L_46 , V_19 -> V_73 ) ;
V_194 = F_100 (
V_176 , 0644 , V_8 -> V_198 , V_19 ,
& V_200 ) ;
if ( ! V_194 ) {
char V_103 [ 256 ] , * V_104 ;
V_104 = F_101 ( V_8 -> V_198 , V_103 , 256 ) ;
F_9 ( L_47 ,
V_104 , V_176 ) ;
}
}
F_99 ( & V_8 -> V_47 ) ;
}
struct V_7 * F_166 ( long (* V_171)
( struct V_61 * V_62 ,
unsigned int V_149 ,
unsigned long V_155 ) )
{
struct V_7 * V_201 ;
int V_27 ;
V_201 = F_14 ( sizeof( struct V_7 ) , V_28 ) ;
if ( ! V_201 )
return F_15 ( - V_29 ) ;
V_201 -> V_8 . V_202 = V_203 ;
V_201 -> V_8 . V_73 = L_48 ;
V_201 -> V_8 . V_204 = & V_205 ;
V_201 -> V_8 . V_12 = NULL ;
V_27 = F_167 ( & V_201 -> V_8 ) ;
if ( V_27 ) {
F_9 ( L_49 ) ;
F_31 ( V_201 ) ;
return F_15 ( V_27 ) ;
}
V_201 -> V_100 = F_168 ( L_48 , NULL ) ;
if ( ! V_201 -> V_100 ) {
F_9 ( L_50 ) ;
goto V_206;
}
V_201 -> V_198 = F_168 ( L_51 , V_201 -> V_100 ) ;
if ( ! V_201 -> V_198 ) {
F_9 ( L_52 ) ;
goto V_206;
}
V_201 -> V_101 = F_168 ( L_53 ,
V_201 -> V_100 ) ;
if ( ! V_201 -> V_101 )
F_9 ( L_54 ) ;
V_206:
V_201 -> V_171 = V_171 ;
V_201 -> V_11 = V_96 ;
F_25 ( & V_201 -> V_48 ) ;
F_169 ( & V_201 -> V_47 ) ;
F_170 ( & V_201 -> V_197 ) ;
V_201 -> V_78 = V_96 ;
V_77 = & V_201 -> V_78 ;
F_25 ( & V_86 ) ;
return V_201 ;
}
void F_171 ( struct V_7 * V_8 )
{
F_172 ( & V_8 -> V_8 ) ;
F_104 ( V_8 -> V_100 ) ;
F_31 ( V_8 ) ;
}
void T_5 F_173 ( struct V_207 * V_164 )
{
int V_26 ;
for ( V_26 = 0 ; V_26 < V_164 -> V_208 ; V_26 ++ ) {
if ( V_164 -> V_197 [ V_26 ] . V_35 == 0 )
continue;
if ( V_164 -> V_197 [ V_26 ] . V_209 == 0 ) {
T_6 V_210 ;
V_210 = F_174 ( V_164 -> V_197 [ V_26 ] . V_35 ,
V_164 -> V_197 [ V_26 ] . V_21 ,
V_211 ) ;
if ( ! V_210 ) {
F_9 ( L_55 ,
V_17 , V_26 ) ;
continue;
}
V_164 -> V_197 [ V_26 ] . V_209 = V_210 ;
} else {
int V_27 = F_175 ( V_164 -> V_197 [ V_26 ] . V_209 ,
V_164 -> V_197 [ V_26 ] . V_35 ) ;
if ( V_27 )
F_9 ( L_56 ,
V_164 -> V_197 [ V_26 ] . V_35 ,
V_164 -> V_197 [ V_26 ] . V_209 ) ;
}
F_176 ( L_57 , V_17 ,
V_164 -> V_197 [ V_26 ] . V_73 ,
V_164 -> V_197 [ V_26 ] . V_209 ,
V_164 -> V_197 [ V_26 ] . V_35 ) ;
}
}
