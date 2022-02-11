unsigned long F_1 ( void )
{
struct V_1 * V_2 ;
unsigned int V_3 = V_4 ;
struct V_5 V_6 ;
V_2 = F_2 ( L_1 ) ;
if ( V_2 ) {
const T_1 * V_7 ;
V_7 = F_3 ( V_2 , L_2 , NULL ) ;
if ( V_7 )
V_3 = F_4 ( V_7 ) ;
F_5 ( V_2 ) ;
} else if ( F_6 ( V_8 ) ) {
unsigned int V_9 = 0 ;
V_2 = F_2 ( L_3 ) ;
if ( V_2 ) {
if ( ! F_7 ( V_2 , 0 , & V_6 ) )
V_9 = F_8 ( & V_6 ) ;
F_5 ( V_2 ) ;
}
if ( V_9 ) {
char V_10 [ 64 ] ;
sprintf ( V_10 , L_4 , V_9 ) ;
V_2 = F_2 ( V_10 ) ;
if ( V_2 ) {
if ( ! F_7 ( V_2 , 0 , & V_6 ) )
V_3 = F_8 ( & V_6 ) ;
F_5 ( V_2 ) ;
}
}
}
return V_3 ;
}
static void F_9 ( struct V_11 * V_12 )
{
F_10 ( V_12 -> V_13 ) ;
F_10 ( V_12 -> V_14 ) ;
F_10 ( V_12 ) ;
}
static struct V_11 * F_11 ( struct V_11 * V_12 ,
T_2 V_15 )
{
struct V_11 * V_16 ;
V_16 = F_12 ( sizeof( * V_16 ) , V_17 ) ;
if ( ! V_16 )
return NULL ;
V_16 -> V_13 = F_13 ( V_12 -> V_13 , V_17 ) ;
V_16 -> V_14 = F_12 ( V_15 , V_17 ) ;
if ( ! V_16 -> V_13 || ! V_16 -> V_14 ) {
F_9 ( V_16 ) ;
return NULL ;
}
memcpy ( V_16 -> V_14 , V_12 -> V_14 , V_12 -> V_18 ) ;
V_16 -> V_18 = V_15 ;
F_14 ( V_16 , V_19 ) ;
return V_16 ;
}
static struct V_11 * F_15 ( struct V_1 * V_20 )
{
struct V_11 * V_12 , * V_16 ;
struct V_21 * V_22 ;
T_2 V_23 , * V_24 ;
int V_25 ;
V_12 = F_16 ( V_20 , L_5 , NULL ) ;
if ( ! V_12 )
return NULL ;
V_16 = F_11 ( V_12 , V_12 -> V_18 ) ;
if ( ! V_16 )
return NULL ;
V_24 = V_16 -> V_14 ;
* V_24 = F_17 ( * V_24 ) ;
V_23 = * V_24 ++ ;
V_22 = (struct V_21 * ) V_24 ;
for ( V_25 = 0 ; V_25 < V_23 ; V_25 ++ ) {
V_22 [ V_25 ] . V_26 = F_18 ( V_22 [ V_25 ] . V_26 ) ;
V_22 [ V_25 ] . V_27 = F_17 ( V_22 [ V_25 ] . V_27 ) ;
V_22 [ V_25 ] . V_28 = F_17 ( V_22 [ V_25 ] . V_28 ) ;
V_22 [ V_25 ] . V_29 = F_17 ( V_22 [ V_25 ] . V_29 ) ;
}
return V_16 ;
}
static void F_19 ( struct V_1 * V_20 ,
struct V_11 * V_12 )
{
struct V_21 * V_22 ;
T_2 V_23 , * V_24 ;
int V_25 ;
V_24 = V_12 -> V_14 ;
V_23 = * V_24 ;
* V_24 = F_20 ( * V_24 ) ;
V_24 ++ ;
V_22 = (struct V_21 * ) V_24 ;
for ( V_25 = 0 ; V_25 < V_23 ; V_25 ++ ) {
V_22 [ V_25 ] . V_26 = F_21 ( V_22 [ V_25 ] . V_26 ) ;
V_22 [ V_25 ] . V_27 = F_20 ( V_22 [ V_25 ] . V_27 ) ;
V_22 [ V_25 ] . V_28 = F_20 ( V_22 [ V_25 ] . V_28 ) ;
V_22 [ V_25 ] . V_29 = F_20 ( V_22 [ V_25 ] . V_29 ) ;
}
V_30 = true ;
F_22 ( V_20 , V_12 ) ;
V_30 = false ;
}
static int F_23 ( struct V_21 * V_31 )
{
struct V_1 * V_20 ;
struct V_11 * V_12 ;
struct V_21 * V_22 ;
T_2 * V_24 , V_23 ;
int V_25 ;
V_20 = F_2 ( L_1 ) ;
if ( ! V_20 )
return - V_32 ;
V_12 = F_15 ( V_20 ) ;
if ( ! V_12 ) {
F_5 ( V_20 ) ;
return - V_32 ;
}
V_24 = V_12 -> V_14 ;
V_23 = * V_24 ++ ;
V_22 = (struct V_21 * ) V_24 ;
for ( V_25 = 0 ; V_25 < V_23 ; V_25 ++ ) {
if ( V_22 [ V_25 ] . V_27 == V_31 -> V_27 ) {
V_22 [ V_25 ] . V_29 = V_31 -> V_29 ;
V_22 [ V_25 ] . V_28 = V_31 -> V_28 ;
F_19 ( V_20 , V_12 ) ;
break;
}
}
F_5 ( V_20 ) ;
return 0 ;
}
static T_2 F_24 ( struct V_1 * V_33 ,
struct V_11 * V_34 , const T_2 * V_35 )
{
T_2 * V_36 ;
T_2 V_28 ;
int V_37 , V_38 , V_39 ;
int V_25 , V_40 ;
V_36 = V_34 -> V_14 ;
V_37 = F_17 ( V_36 [ 0 ] ) ;
V_38 = F_17 ( V_36 [ 1 ] ) ;
V_39 = V_38 * sizeof( T_2 ) ;
V_28 = - 1 ;
for ( V_25 = 0 ; V_25 < V_37 ; V_25 ++ ) {
V_40 = ( V_25 * V_38 ) + 2 ;
if ( memcmp ( & V_36 [ V_40 ] , & V_35 [ 1 ] , V_39 ) )
continue;
V_28 = V_25 ;
break;
}
if ( V_28 == - 1 ) {
struct V_11 * V_16 ;
T_2 V_41 ;
V_41 = V_34 -> V_18 + V_39 ;
V_16 = F_11 ( V_34 , V_41 ) ;
if ( ! V_16 )
return - 1 ;
V_36 = V_16 -> V_14 ;
V_36 [ 0 ] = F_20 ( V_37 + 1 ) ;
V_40 = V_37 * V_38 + 2 ;
memcpy ( & V_36 [ V_40 ] , & V_35 [ 1 ] , V_39 ) ;
F_22 ( V_33 , V_16 ) ;
V_28 = F_17 ( V_36 [ 0 ] ) - 1 ;
}
return V_28 ;
}
static T_2 F_25 ( struct V_21 * V_31 )
{
struct V_1 * V_42 , * V_43 , * V_33 ;
struct V_11 * V_34 ;
const T_2 * V_35 ;
T_2 V_28 ;
V_42 = F_2 ( L_6 ) ;
if ( ! V_42 )
return - V_32 ;
V_43 = F_26 ( F_20 ( V_31 -> V_27 ) ,
V_42 ) ;
F_5 ( V_42 ) ;
if ( ! V_43 )
return - V_44 ;
V_35 = F_3 ( V_43 , L_7 , NULL ) ;
if ( ! V_35 ) {
F_27 ( V_43 ) ;
return - V_32 ;
}
V_33 = F_2 ( L_1 ) ;
if ( ! V_33 ) {
F_27 ( V_43 ) ;
return - V_32 ;
}
V_34 = F_16 ( V_33 , L_8 ,
NULL ) ;
if ( ! V_34 ) {
F_5 ( V_33 ) ;
F_27 ( V_43 ) ;
return - V_32 ;
}
V_28 = F_24 ( V_33 , V_34 , V_35 ) ;
F_27 ( V_43 ) ;
return V_28 ;
}
static int F_28 ( struct V_21 * V_31 )
{
int V_28 ;
V_31 -> V_29 |= V_45 ;
V_28 = F_25 ( V_31 ) ;
if ( V_28 < 0 ) {
F_29 ( L_9 ,
V_31 -> V_27 ) ;
return V_28 ;
}
V_31 -> V_28 = V_28 ;
return F_23 ( V_31 ) ;
}
static int F_30 ( struct V_21 * V_31 )
{
V_31 -> V_29 &= ~ V_45 ;
V_31 -> V_28 = 0xffffffff ;
return F_23 ( V_31 ) ;
}
static struct V_46 * F_31 ( struct V_21 * V_31 )
{
unsigned long V_47 ;
struct V_48 * V_49 ;
struct V_46 * V_50 ;
V_47 = F_32 ( F_33 ( V_31 -> V_26 ) ) ;
V_49 = F_34 ( V_47 ) ;
V_50 = F_35 ( V_49 ) ;
return V_50 ;
}
static int F_36 ( struct V_21 * V_31 , bool V_51 )
{
struct V_46 * V_50 ;
int V_52 ;
V_50 = F_31 ( V_31 ) ;
if ( ! V_50 )
return - V_44 ;
if ( V_51 && V_50 -> V_53 . V_54 )
V_52 = F_37 ( & V_50 -> V_53 ) ;
else if ( ! V_51 && ! V_50 -> V_53 . V_54 )
V_52 = F_38 ( & V_50 -> V_53 ) ;
else
V_52 = 0 ;
F_39 ( & V_50 -> V_53 ) ;
return V_52 ;
}
static int F_40 ( struct V_21 * V_31 )
{
return F_36 ( V_31 , true ) ;
}
static int F_41 ( struct V_21 * V_31 )
{
return F_36 ( V_31 , false ) ;
}
static int F_42 ( unsigned long V_55 , unsigned int V_3 )
{
unsigned long V_56 , V_57 ;
int V_58 ;
int V_25 , V_59 ;
V_57 = V_55 >> V_60 ;
F_43 () ;
if ( ! F_44 ( V_57 ) )
goto V_61;
V_56 = F_1 () ;
V_58 = V_56 / V_4 ;
V_59 = F_45 ( V_55 ) ;
for ( V_25 = 0 ; V_25 < V_58 ; V_25 ++ ) {
F_46 ( V_59 , V_55 , V_4 ) ;
V_55 += V_4 ;
}
V_61:
F_47 ( V_55 , V_3 ) ;
F_48 () ;
return 0 ;
}
static int F_49 ( struct V_1 * V_2 )
{
const char * type ;
const T_3 * V_62 ;
unsigned long V_55 ;
unsigned int V_63 ;
int V_64 = - V_44 ;
type = F_3 ( V_2 , L_10 , NULL ) ;
if ( type == NULL || strcmp ( type , L_11 ) != 0 )
return 0 ;
V_62 = F_3 ( V_2 , L_12 , NULL ) ;
if ( ! V_62 )
return V_64 ;
V_55 = F_18 ( * ( unsigned long * ) V_62 ) ;
V_63 = F_17 ( V_62 [ 3 ] ) ;
F_42 ( V_55 , V_63 ) ;
return 0 ;
}
static bool F_50 ( struct V_21 * V_31 )
{
int V_25 , V_65 ;
int V_52 = 1 ;
unsigned long V_66 , V_56 ;
T_4 V_67 ;
if ( ! ( V_31 -> V_29 & V_45 ) )
return false ;
V_56 = F_51 () ;
V_65 = V_56 / V_4 ;
V_67 = V_31 -> V_26 ;
#ifdef F_52
if ( F_53 ( V_67 , V_56 ) )
return false ;
#endif
for ( V_25 = 0 ; V_25 < V_65 ; V_25 ++ ) {
V_66 = F_33 ( V_67 ) ;
if ( ! F_54 ( V_66 ) )
continue;
V_52 &= F_55 ( V_66 , V_68 ) ;
V_67 += V_4 ;
}
return V_52 ? true : false ;
}
static int F_56 ( struct V_21 * V_31 )
{
unsigned long V_56 ;
int V_59 , V_52 ;
if ( ! F_50 ( V_31 ) )
return - V_44 ;
V_52 = F_41 ( V_31 ) ;
if ( V_52 )
return V_52 ;
V_56 = F_1 () ;
V_59 = F_45 ( V_31 -> V_26 ) ;
F_46 ( V_59 , V_31 -> V_26 , V_56 ) ;
F_47 ( V_31 -> V_26 , V_56 ) ;
F_30 ( V_31 ) ;
return 0 ;
}
static int F_57 ( T_2 V_69 ,
struct V_11 * V_12 )
{
struct V_21 * V_22 ;
int V_70 = 0 ;
int V_71 = 0 ;
T_2 V_23 , * V_24 ;
int V_25 , V_52 ;
F_58 ( L_13 , V_69 ) ;
if ( V_69 == 0 )
return - V_44 ;
V_24 = V_12 -> V_14 ;
V_23 = * V_24 ++ ;
V_22 = (struct V_21 * ) V_24 ;
for ( V_25 = 0 ; V_25 < V_23 ; V_25 ++ ) {
if ( F_50 ( & V_22 [ V_25 ] ) )
V_71 ++ ;
}
if ( V_71 < V_69 ) {
F_58 ( L_14 ,
V_71 , V_69 ) ;
return - V_44 ;
}
for ( V_25 = 0 ; V_25 < V_23 && V_70 < V_69 ; V_25 ++ ) {
V_52 = F_56 ( & V_22 [ V_25 ] ) ;
if ( V_52 )
continue;
V_70 ++ ;
V_22 [ V_25 ] . V_72 = 1 ;
}
if ( V_70 != V_69 ) {
F_29 ( L_15 ) ;
for ( V_25 = 0 ; V_25 < V_23 ; V_25 ++ ) {
if ( ! V_22 [ V_25 ] . V_72 )
continue;
V_52 = F_59 ( & V_22 [ V_25 ] ) ;
if ( V_52 )
F_29 ( L_16 ,
V_22 [ V_25 ] . V_27 ) ;
V_22 [ V_25 ] . V_72 = 0 ;
}
V_52 = - V_44 ;
} else {
for ( V_25 = 0 ; V_25 < V_23 ; V_25 ++ ) {
if ( ! V_22 [ V_25 ] . V_72 )
continue;
F_60 ( V_22 [ V_25 ] . V_27 ) ;
F_58 ( L_17 ,
V_22 [ V_25 ] . V_26 ) ;
V_22 [ V_25 ] . V_72 = 0 ;
}
V_52 = 0 ;
}
return V_52 ;
}
static int F_61 ( T_2 V_27 , struct V_11 * V_12 )
{
struct V_21 * V_22 ;
T_2 V_23 , * V_24 ;
int V_73 ;
int V_25 , V_52 ;
F_58 ( L_18 , V_27 ) ;
V_24 = V_12 -> V_14 ;
V_23 = * V_24 ++ ;
V_22 = (struct V_21 * ) V_24 ;
V_73 = 0 ;
for ( V_25 = 0 ; V_25 < V_23 ; V_25 ++ ) {
if ( V_22 [ V_25 ] . V_27 == V_27 ) {
V_73 = 1 ;
V_52 = F_56 ( & V_22 [ V_25 ] ) ;
if ( ! V_52 )
F_60 ( V_22 [ V_25 ] . V_27 ) ;
break;
}
}
if ( ! V_73 )
V_52 = - V_44 ;
if ( V_52 )
F_58 ( L_19 ,
V_22 [ V_25 ] . V_26 ) ;
else
F_58 ( L_17 , V_22 [ V_25 ] . V_26 ) ;
return V_52 ;
}
static int F_62 ( T_2 V_27 , struct V_11 * V_12 )
{
struct V_21 * V_22 ;
T_2 V_23 , * V_24 ;
int V_73 ;
int V_25 , V_52 ;
F_58 ( L_20 , V_27 ) ;
V_24 = V_12 -> V_14 ;
V_23 = * V_24 ++ ;
V_22 = (struct V_21 * ) V_24 ;
V_73 = 0 ;
for ( V_25 = 0 ; V_25 < V_23 ; V_25 ++ ) {
if ( V_22 [ V_25 ] . V_27 == V_27 ) {
V_73 = 1 ;
V_52 = F_56 ( & V_22 [ V_25 ] ) ;
if ( ! V_52 ) {
V_52 = F_59 ( & V_22 [ V_25 ] ) ;
if ( V_52 )
F_60 ( V_22 [ V_25 ] . V_27 ) ;
}
break;
}
}
if ( ! V_73 )
V_52 = - V_44 ;
if ( V_52 )
F_58 ( L_21 ,
V_22 [ V_25 ] . V_26 ) ;
else
F_58 ( L_22 , V_22 [ V_25 ] . V_26 ) ;
return V_52 ;
}
static int F_63 ( T_2 V_69 , T_2 V_27 ,
struct V_11 * V_12 )
{
struct V_21 * V_22 ;
T_2 V_23 , * V_24 ;
int V_25 , V_52 , V_74 ;
int V_71 = 0 , V_75 = 0 , V_76 ;
F_58 ( L_23 ,
V_69 , V_27 ) ;
if ( V_69 == 0 )
return - V_44 ;
V_24 = V_12 -> V_14 ;
V_23 = * V_24 ++ ;
V_22 = (struct V_21 * ) V_24 ;
V_74 = 0 ;
while ( V_75 < V_23 ) {
if ( V_22 [ V_75 ] . V_27 == V_27 ) {
V_74 = 1 ;
break;
}
V_75 ++ ;
}
if ( ! V_74 )
return - V_44 ;
V_76 = V_75 + V_69 ;
for ( V_25 = V_75 ; V_25 < V_76 ; V_25 ++ ) {
if ( V_22 [ V_25 ] . V_29 & V_77 )
break;
V_71 ++ ;
}
if ( V_71 < V_69 )
return - V_44 ;
for ( V_25 = V_75 ; V_25 < V_76 ; V_25 ++ ) {
if ( ! ( V_22 [ V_25 ] . V_29 & V_45 ) )
continue;
V_52 = F_56 ( & V_22 [ V_25 ] ) ;
if ( V_52 )
break;
V_22 [ V_25 ] . V_72 = 1 ;
}
if ( V_52 ) {
F_29 ( L_24 ) ;
for ( V_25 = V_75 ; V_25 < V_76 ; V_25 ++ ) {
if ( ! V_22 [ V_25 ] . V_72 )
continue;
V_52 = F_59 ( & V_22 [ V_25 ] ) ;
if ( V_52 )
F_29 ( L_25 ,
F_17 ( V_22 [ V_25 ] . V_27 ) ) ;
V_22 [ V_25 ] . V_72 = 0 ;
}
V_52 = - V_44 ;
} else {
for ( V_25 = V_75 ; V_25 < V_76 ; V_25 ++ ) {
if ( ! V_22 [ V_25 ] . V_72 )
continue;
F_60 ( V_22 [ V_25 ] . V_27 ) ;
F_58 ( L_26 ,
V_22 [ V_25 ] . V_26 , V_22 [ V_25 ] . V_27 ) ;
V_22 [ V_25 ] . V_72 = 0 ;
}
}
return V_52 ;
}
static inline int F_42 ( unsigned long V_55 ,
unsigned int V_3 )
{
return - V_78 ;
}
static inline int F_49 ( struct V_1 * V_2 )
{
return 0 ;
}
static inline int F_64 ( struct V_79 * V_80 )
{
return - V_78 ;
}
static int F_56 ( struct V_21 * V_31 )
{
return - V_78 ;
}
static int F_57 ( T_2 V_69 ,
struct V_11 * V_12 )
{
return - V_78 ;
}
static int F_61 ( T_2 V_27 , struct V_11 * V_12 )
{
return - V_78 ;
}
static int F_62 ( T_2 V_27 , struct V_11 * V_12 )
{
return - V_78 ;
}
static int F_63 ( T_2 V_69 , T_2 V_27 ,
struct V_11 * V_12 )
{
return - V_78 ;
}
static int F_59 ( struct V_21 * V_31 )
{
unsigned long V_56 ;
int V_59 , V_52 ;
if ( V_31 -> V_29 & V_45 )
return - V_44 ;
V_52 = F_28 ( V_31 ) ;
if ( V_52 ) {
F_29 ( L_27 ,
V_31 -> V_27 ) ;
F_60 ( V_31 -> V_27 ) ;
return V_52 ;
}
V_56 = F_51 () ;
V_59 = F_45 ( V_31 -> V_26 ) ;
V_52 = F_65 ( V_59 , V_31 -> V_26 , V_56 ) ;
if ( V_52 ) {
F_30 ( V_31 ) ;
return V_52 ;
}
V_52 = F_40 ( V_31 ) ;
if ( V_52 ) {
F_46 ( V_59 , V_31 -> V_26 , V_56 ) ;
F_30 ( V_31 ) ;
} else {
V_31 -> V_29 |= V_45 ;
}
return V_52 ;
}
static int F_66 ( T_2 V_81 , struct V_11 * V_12 )
{
struct V_21 * V_22 ;
T_2 V_23 , * V_24 ;
int V_71 = 0 ;
int V_82 = 0 ;
int V_25 , V_52 ;
F_58 ( L_28 , V_81 ) ;
if ( V_81 == 0 )
return - V_44 ;
V_24 = V_12 -> V_14 ;
V_23 = * V_24 ++ ;
V_22 = (struct V_21 * ) V_24 ;
for ( V_25 = 0 ; V_25 < V_23 ; V_25 ++ ) {
if ( ! ( V_22 [ V_25 ] . V_29 & V_45 ) )
V_71 ++ ;
}
if ( V_71 < V_81 )
return - V_44 ;
for ( V_25 = 0 ; V_25 < V_23 && V_81 != V_82 ; V_25 ++ ) {
if ( V_22 [ V_25 ] . V_29 & V_45 )
continue;
V_52 = F_67 ( V_22 [ V_25 ] . V_27 ) ;
if ( V_52 )
continue;
V_52 = F_59 ( & V_22 [ V_25 ] ) ;
if ( V_52 ) {
F_60 ( V_22 [ V_25 ] . V_27 ) ;
continue;
}
V_82 ++ ;
V_22 [ V_25 ] . V_72 = 1 ;
}
if ( V_82 != V_81 ) {
F_29 ( L_29 ) ;
for ( V_25 = 0 ; V_25 < V_23 ; V_25 ++ ) {
if ( ! V_22 [ V_25 ] . V_72 )
continue;
V_52 = F_56 ( & V_22 [ V_25 ] ) ;
if ( V_52 )
F_29 ( L_30 ,
F_17 ( V_22 [ V_25 ] . V_27 ) ) ;
else
F_60 ( V_22 [ V_25 ] . V_27 ) ;
}
V_52 = - V_44 ;
} else {
for ( V_25 = 0 ; V_25 < V_23 ; V_25 ++ ) {
if ( ! V_22 [ V_25 ] . V_72 )
continue;
F_58 ( L_31 ,
V_22 [ V_25 ] . V_26 , V_22 [ V_25 ] . V_27 ) ;
V_22 [ V_25 ] . V_72 = 0 ;
}
V_52 = 0 ;
}
return V_52 ;
}
static int F_68 ( T_2 V_27 , struct V_11 * V_12 )
{
struct V_21 * V_22 ;
T_2 V_23 , * V_24 ;
int V_25 , V_73 ;
int V_52 ;
F_58 ( L_32 , V_27 ) ;
V_24 = V_12 -> V_14 ;
V_23 = * V_24 ++ ;
V_22 = (struct V_21 * ) V_24 ;
V_73 = 0 ;
for ( V_25 = 0 ; V_25 < V_23 ; V_25 ++ ) {
if ( V_22 [ V_25 ] . V_27 == V_27 ) {
V_73 = 1 ;
V_52 = F_67 ( V_22 [ V_25 ] . V_27 ) ;
if ( ! V_52 ) {
V_52 = F_59 ( & V_22 [ V_25 ] ) ;
if ( V_52 )
F_60 ( V_22 [ V_25 ] . V_27 ) ;
}
break;
}
}
if ( ! V_73 )
V_52 = - V_44 ;
if ( V_52 )
F_58 ( L_33 , V_27 ) ;
else
F_58 ( L_31 ,
V_22 [ V_25 ] . V_26 , V_27 ) ;
return V_52 ;
}
static int F_69 ( T_2 V_81 , T_2 V_27 ,
struct V_11 * V_12 )
{
struct V_21 * V_22 ;
T_2 V_23 , * V_24 ;
int V_25 , V_52 , V_74 ;
int V_71 = 0 , V_75 = 0 , V_76 ;
F_58 ( L_34 ,
V_81 , V_27 ) ;
if ( V_81 == 0 )
return - V_44 ;
V_24 = V_12 -> V_14 ;
V_23 = * V_24 ++ ;
V_22 = (struct V_21 * ) V_24 ;
V_74 = 0 ;
while ( V_75 < V_23 ) {
if ( V_22 [ V_75 ] . V_27 == V_27 ) {
V_74 = 1 ;
break;
}
V_75 ++ ;
}
if ( ! V_74 )
return - V_44 ;
V_76 = V_75 + V_81 ;
for ( V_25 = V_75 ; V_25 < V_76 ; V_25 ++ ) {
if ( V_22 [ V_25 ] . V_29 & V_77 )
break;
V_71 ++ ;
}
if ( V_71 < V_81 )
return - V_44 ;
for ( V_25 = V_75 ; V_25 < V_76 ; V_25 ++ ) {
if ( V_22 [ V_25 ] . V_29 & V_45 )
continue;
V_52 = F_67 ( V_22 [ V_25 ] . V_27 ) ;
if ( V_52 )
break;
V_52 = F_59 ( & V_22 [ V_25 ] ) ;
if ( V_52 ) {
F_60 ( V_22 [ V_25 ] . V_27 ) ;
break;
}
V_22 [ V_25 ] . V_72 = 1 ;
}
if ( V_52 ) {
F_29 ( L_35 ) ;
for ( V_25 = V_75 ; V_25 < V_76 ; V_25 ++ ) {
if ( ! V_22 [ V_25 ] . V_72 )
continue;
V_52 = F_56 ( & V_22 [ V_25 ] ) ;
if ( V_52 )
F_29 ( L_30 ,
F_17 ( V_22 [ V_25 ] . V_27 ) ) ;
else
F_60 ( V_22 [ V_25 ] . V_27 ) ;
}
V_52 = - V_44 ;
} else {
for ( V_25 = V_75 ; V_25 < V_76 ; V_25 ++ ) {
if ( ! V_22 [ V_25 ] . V_72 )
continue;
F_58 ( L_31 ,
V_22 [ V_25 ] . V_26 , V_22 [ V_25 ] . V_27 ) ;
V_22 [ V_25 ] . V_72 = 0 ;
}
}
return V_52 ;
}
int F_70 ( struct V_79 * V_80 )
{
struct V_1 * V_20 ;
struct V_11 * V_12 ;
T_2 V_83 , V_27 ;
int V_52 ;
F_43 () ;
V_20 = F_2 ( L_1 ) ;
if ( ! V_20 ) {
V_52 = - V_44 ;
goto V_84;
}
V_12 = F_15 ( V_20 ) ;
if ( ! V_12 ) {
V_52 = - V_44 ;
goto V_84;
}
switch ( V_80 -> V_85 ) {
case V_86 :
if ( V_80 -> V_87 == V_88 ) {
V_83 = V_80 -> V_89 . V_90 ;
V_52 = F_66 ( V_83 , V_12 ) ;
} else if ( V_80 -> V_87 == V_91 ) {
V_27 = V_80 -> V_89 . V_27 ;
V_52 = F_68 ( V_27 , V_12 ) ;
} else if ( V_80 -> V_87 == V_92 ) {
V_83 = V_80 -> V_89 . V_93 . V_83 ;
V_27 = V_80 -> V_89 . V_93 . V_40 ;
V_52 = F_69 ( V_83 , V_27 , V_12 ) ;
} else {
V_52 = - V_44 ;
}
break;
case V_94 :
if ( V_80 -> V_87 == V_88 ) {
V_83 = V_80 -> V_89 . V_90 ;
V_52 = F_57 ( V_83 , V_12 ) ;
} else if ( V_80 -> V_87 == V_91 ) {
V_27 = V_80 -> V_89 . V_27 ;
V_52 = F_61 ( V_27 , V_12 ) ;
} else if ( V_80 -> V_87 == V_92 ) {
V_83 = V_80 -> V_89 . V_93 . V_83 ;
V_27 = V_80 -> V_89 . V_93 . V_40 ;
V_52 = F_63 ( V_83 , V_27 , V_12 ) ;
} else {
V_52 = - V_44 ;
}
break;
case V_95 :
V_27 = V_80 -> V_89 . V_27 ;
V_52 = F_62 ( V_27 , V_12 ) ;
break;
default:
F_29 ( L_36 , V_80 -> V_85 ) ;
V_52 = - V_44 ;
break;
}
F_9 ( V_12 ) ;
V_84:
F_5 ( V_20 ) ;
F_48 () ;
return V_52 ;
}
static int F_71 ( struct V_1 * V_2 )
{
const char * type ;
const T_3 * V_62 ;
unsigned long V_55 ;
unsigned int V_63 ;
int V_64 = - V_44 ;
type = F_3 ( V_2 , L_10 , NULL ) ;
if ( type == NULL || strcmp ( type , L_11 ) != 0 )
return 0 ;
V_62 = F_3 ( V_2 , L_12 , NULL ) ;
if ( ! V_62 )
return V_64 ;
V_55 = F_18 ( * ( unsigned long * ) V_62 ) ;
V_63 = F_17 ( V_62 [ 3 ] ) ;
V_64 = F_72 ( V_55 , V_63 ) ;
return ( V_64 < 0 ) ? - V_44 : 0 ;
}
static int F_73 ( struct V_96 * V_97 )
{
struct V_21 * V_98 , * V_99 ;
unsigned long V_3 ;
T_2 V_100 ;
T_3 * V_24 ;
int V_25 , V_52 = - V_44 ;
if ( V_30 )
return 0 ;
V_3 = F_1 () ;
if ( ! V_3 )
return - V_44 ;
V_24 = ( T_3 * ) V_97 -> V_101 -> V_14 ;
if ( ! V_24 )
return - V_44 ;
V_100 = F_17 ( * V_24 ++ ) ;
V_99 = (struct V_21 * ) V_24 ;
V_24 = ( T_3 * ) V_97 -> V_12 -> V_14 ;
V_24 ++ ;
V_98 = (struct V_21 * ) V_24 ;
for ( V_25 = 0 ; V_25 < V_100 ; V_25 ++ ) {
if ( ( F_17 ( V_99 [ V_25 ] . V_29 ) & V_45 ) &&
( ! ( F_17 ( V_98 [ V_25 ] . V_29 ) & V_45 ) ) ) {
V_52 = F_42 (
F_18 ( V_99 [ V_25 ] . V_26 ) ,
V_3 ) ;
break;
} else if ( ( ! ( F_17 ( V_99 [ V_25 ] . V_29 ) &
V_45 ) ) &&
( F_17 ( V_98 [ V_25 ] . V_29 ) &
V_45 ) ) {
V_52 = F_72 ( F_18 ( V_99 [ V_25 ] . V_26 ) ,
V_3 ) ;
V_52 = ( V_52 < 0 ) ? - V_44 : 0 ;
break;
}
}
return V_52 ;
}
static int F_74 ( struct V_102 * V_103 ,
unsigned long V_85 , void * V_104 )
{
struct V_96 * V_105 = V_104 ;
int V_106 = 0 ;
switch ( V_85 ) {
case V_107 :
V_106 = F_71 ( V_105 -> V_20 ) ;
break;
case V_108 :
V_106 = F_49 ( V_105 -> V_20 ) ;
break;
case V_109 :
if ( ! strcmp ( V_105 -> V_12 -> V_13 , L_5 ) )
V_106 = F_73 ( V_105 ) ;
break;
}
return F_75 ( V_106 ) ;
}
static int T_5 F_76 ( void )
{
if ( F_77 ( V_110 ) )
F_78 ( & V_111 ) ;
return 0 ;
}
