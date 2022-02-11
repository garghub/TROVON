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
static int F_36 ( unsigned long V_51 , unsigned int V_3 )
{
unsigned long V_52 , V_53 ;
int V_54 ;
int V_25 , V_55 ;
V_53 = V_51 >> V_56 ;
F_37 () ;
if ( ! F_38 ( V_53 ) )
goto V_57;
V_52 = F_1 () ;
V_54 = V_52 / V_4 ;
V_55 = F_39 ( V_51 ) ;
for ( V_25 = 0 ; V_25 < V_54 ; V_25 ++ ) {
F_40 ( V_55 , V_51 , V_4 ) ;
V_51 += V_4 ;
}
V_57:
F_41 ( V_51 , V_3 ) ;
F_42 () ;
return 0 ;
}
static int F_43 ( struct V_1 * V_2 )
{
const char * type ;
const T_3 * V_58 ;
unsigned long V_51 ;
unsigned int V_59 ;
int V_60 = - V_44 ;
type = F_3 ( V_2 , L_10 , NULL ) ;
if ( type == NULL || strcmp ( type , L_11 ) != 0 )
return 0 ;
V_58 = F_3 ( V_2 , L_12 , NULL ) ;
if ( ! V_58 )
return V_60 ;
V_51 = F_18 ( * ( unsigned long * ) V_58 ) ;
V_59 = F_17 ( V_58 [ 3 ] ) ;
F_36 ( V_51 , V_59 ) ;
return 0 ;
}
static bool F_44 ( struct V_21 * V_31 )
{
int V_25 , V_61 ;
int V_62 = 1 ;
unsigned long V_63 , V_52 ;
T_4 V_64 ;
if ( ! ( V_31 -> V_29 & V_45 ) )
return false ;
V_52 = F_45 () ;
V_61 = V_52 / V_4 ;
V_64 = V_31 -> V_26 ;
#ifdef F_46
if ( F_47 ( V_64 , V_52 ) )
return false ;
#endif
for ( V_25 = 0 ; V_25 < V_61 ; V_25 ++ ) {
V_63 = F_33 ( V_64 ) ;
if ( ! F_48 ( V_63 ) )
continue;
V_62 &= F_49 ( V_63 , V_65 ) ;
V_64 += V_4 ;
}
return V_62 ? true : false ;
}
static int F_50 ( struct V_21 * V_31 )
{
struct V_46 * V_50 ;
unsigned long V_52 ;
int V_55 , V_62 ;
if ( ! F_44 ( V_31 ) )
return - V_44 ;
V_50 = F_31 ( V_31 ) ;
if ( ! V_50 )
return - V_44 ;
V_62 = F_51 ( & V_50 -> V_66 ) ;
F_52 ( & V_50 -> V_66 ) ;
if ( V_62 )
return V_62 ;
V_52 = F_1 () ;
V_55 = F_39 ( V_31 -> V_26 ) ;
F_40 ( V_55 , V_31 -> V_26 , V_52 ) ;
F_41 ( V_31 -> V_26 , V_52 ) ;
F_30 ( V_31 ) ;
return 0 ;
}
static int F_53 ( T_2 V_67 ,
struct V_11 * V_12 )
{
struct V_21 * V_22 ;
int V_68 = 0 ;
int V_69 = 0 ;
T_2 V_23 , * V_24 ;
int V_25 , V_62 ;
F_54 ( L_13 , V_67 ) ;
if ( V_67 == 0 )
return - V_44 ;
V_24 = V_12 -> V_14 ;
V_23 = * V_24 ++ ;
V_22 = (struct V_21 * ) V_24 ;
for ( V_25 = 0 ; V_25 < V_23 ; V_25 ++ ) {
if ( F_44 ( & V_22 [ V_25 ] ) )
V_69 ++ ;
}
if ( V_69 < V_67 ) {
F_54 ( L_14 ,
V_69 , V_67 ) ;
return - V_44 ;
}
for ( V_25 = 0 ; V_25 < V_23 && V_68 < V_67 ; V_25 ++ ) {
V_62 = F_50 ( & V_22 [ V_25 ] ) ;
if ( V_62 )
continue;
V_68 ++ ;
V_22 [ V_25 ] . V_70 = 1 ;
}
if ( V_68 != V_67 ) {
F_29 ( L_15 ) ;
for ( V_25 = 0 ; V_25 < V_23 ; V_25 ++ ) {
if ( ! V_22 [ V_25 ] . V_70 )
continue;
V_62 = F_55 ( & V_22 [ V_25 ] ) ;
if ( V_62 )
F_29 ( L_16 ,
V_22 [ V_25 ] . V_27 ) ;
V_22 [ V_25 ] . V_70 = 0 ;
}
V_62 = - V_44 ;
} else {
for ( V_25 = 0 ; V_25 < V_23 ; V_25 ++ ) {
if ( ! V_22 [ V_25 ] . V_70 )
continue;
F_56 ( V_22 [ V_25 ] . V_27 ) ;
F_54 ( L_17 ,
V_22 [ V_25 ] . V_26 ) ;
V_22 [ V_25 ] . V_70 = 0 ;
}
V_62 = 0 ;
}
return V_62 ;
}
static int F_57 ( T_2 V_27 , struct V_11 * V_12 )
{
struct V_21 * V_22 ;
T_2 V_23 , * V_24 ;
int V_71 ;
int V_25 , V_62 ;
F_54 ( L_18 , V_27 ) ;
V_24 = V_12 -> V_14 ;
V_23 = * V_24 ++ ;
V_22 = (struct V_21 * ) V_24 ;
V_71 = 0 ;
for ( V_25 = 0 ; V_25 < V_23 ; V_25 ++ ) {
if ( V_22 [ V_25 ] . V_27 == V_27 ) {
V_71 = 1 ;
V_62 = F_50 ( & V_22 [ V_25 ] ) ;
if ( ! V_62 )
F_56 ( V_22 [ V_25 ] . V_27 ) ;
break;
}
}
if ( ! V_71 )
V_62 = - V_44 ;
if ( V_62 )
F_54 ( L_19 ,
V_22 [ V_25 ] . V_26 ) ;
else
F_54 ( L_17 , V_22 [ V_25 ] . V_26 ) ;
return V_62 ;
}
static int F_58 ( T_2 V_27 , struct V_11 * V_12 )
{
struct V_21 * V_22 ;
T_2 V_23 , * V_24 ;
int V_71 ;
int V_25 , V_62 ;
F_54 ( L_20 , V_27 ) ;
V_24 = V_12 -> V_14 ;
V_23 = * V_24 ++ ;
V_22 = (struct V_21 * ) V_24 ;
V_71 = 0 ;
for ( V_25 = 0 ; V_25 < V_23 ; V_25 ++ ) {
if ( V_22 [ V_25 ] . V_27 == V_27 ) {
V_71 = 1 ;
V_62 = F_50 ( & V_22 [ V_25 ] ) ;
if ( ! V_62 ) {
V_62 = F_55 ( & V_22 [ V_25 ] ) ;
if ( V_62 )
F_56 ( V_22 [ V_25 ] . V_27 ) ;
}
break;
}
}
if ( ! V_71 )
V_62 = - V_44 ;
if ( V_62 )
F_54 ( L_21 ,
V_22 [ V_25 ] . V_26 ) ;
else
F_54 ( L_22 , V_22 [ V_25 ] . V_26 ) ;
return V_62 ;
}
static int F_59 ( T_2 V_67 , T_2 V_27 ,
struct V_11 * V_12 )
{
struct V_21 * V_22 ;
T_2 V_23 , * V_24 ;
int V_25 , V_62 , V_72 ;
int V_69 = 0 , V_73 = 0 , V_74 ;
F_54 ( L_23 ,
V_67 , V_27 ) ;
if ( V_67 == 0 )
return - V_44 ;
V_24 = V_12 -> V_14 ;
V_23 = * V_24 ++ ;
V_22 = (struct V_21 * ) V_24 ;
V_72 = 0 ;
while ( V_73 < V_23 ) {
if ( V_22 [ V_73 ] . V_27 == V_27 ) {
V_72 = 1 ;
break;
}
V_73 ++ ;
}
if ( ! V_72 )
return - V_44 ;
V_74 = V_73 + V_67 ;
for ( V_25 = V_73 ; V_25 < V_74 ; V_25 ++ ) {
if ( V_22 [ V_25 ] . V_29 & V_75 )
break;
V_69 ++ ;
}
if ( V_69 < V_67 )
return - V_44 ;
for ( V_25 = V_73 ; V_25 < V_74 ; V_25 ++ ) {
if ( ! ( V_22 [ V_25 ] . V_29 & V_45 ) )
continue;
V_62 = F_50 ( & V_22 [ V_25 ] ) ;
if ( V_62 )
break;
V_22 [ V_25 ] . V_70 = 1 ;
}
if ( V_62 ) {
F_29 ( L_24 ) ;
for ( V_25 = V_73 ; V_25 < V_74 ; V_25 ++ ) {
if ( ! V_22 [ V_25 ] . V_70 )
continue;
V_62 = F_55 ( & V_22 [ V_25 ] ) ;
if ( V_62 )
F_29 ( L_25 ,
F_17 ( V_22 [ V_25 ] . V_27 ) ) ;
V_22 [ V_25 ] . V_70 = 0 ;
}
V_62 = - V_44 ;
} else {
for ( V_25 = V_73 ; V_25 < V_74 ; V_25 ++ ) {
if ( ! V_22 [ V_25 ] . V_70 )
continue;
F_56 ( V_22 [ V_25 ] . V_27 ) ;
F_54 ( L_26 ,
V_22 [ V_25 ] . V_26 , V_22 [ V_25 ] . V_27 ) ;
V_22 [ V_25 ] . V_70 = 0 ;
}
}
return V_62 ;
}
static inline int F_36 ( unsigned long V_51 ,
unsigned int V_3 )
{
return - V_76 ;
}
static inline int F_43 ( struct V_1 * V_2 )
{
return 0 ;
}
static inline int F_60 ( struct V_77 * V_78 )
{
return - V_76 ;
}
static int F_50 ( struct V_21 * V_31 )
{
return - V_76 ;
}
static int F_53 ( T_2 V_67 ,
struct V_11 * V_12 )
{
return - V_76 ;
}
static int F_57 ( T_2 V_27 , struct V_11 * V_12 )
{
return - V_76 ;
}
static int F_58 ( T_2 V_27 , struct V_11 * V_12 )
{
return - V_76 ;
}
static int F_59 ( T_2 V_67 , T_2 V_27 ,
struct V_11 * V_12 )
{
return - V_76 ;
}
static int F_61 ( struct V_21 * V_31 )
{
struct V_46 * V_50 ;
int V_62 ;
V_50 = F_31 ( V_31 ) ;
if ( ! V_50 )
return - V_44 ;
V_62 = F_62 ( & V_50 -> V_66 ) ;
F_52 ( & V_50 -> V_66 ) ;
return V_62 ;
}
static int F_55 ( struct V_21 * V_31 )
{
unsigned long V_52 ;
int V_55 , V_62 ;
if ( V_31 -> V_29 & V_45 )
return - V_44 ;
V_62 = F_28 ( V_31 ) ;
if ( V_62 ) {
F_29 ( L_27 ,
V_31 -> V_27 ) ;
F_56 ( V_31 -> V_27 ) ;
return V_62 ;
}
V_52 = F_45 () ;
V_55 = F_39 ( V_31 -> V_26 ) ;
V_62 = F_63 ( V_55 , V_31 -> V_26 , V_52 ) ;
if ( V_62 ) {
F_30 ( V_31 ) ;
return V_62 ;
}
V_62 = F_61 ( V_31 ) ;
if ( V_62 ) {
F_40 ( V_55 , V_31 -> V_26 , V_52 ) ;
F_30 ( V_31 ) ;
} else {
V_31 -> V_29 |= V_45 ;
}
return V_62 ;
}
static int F_64 ( T_2 V_79 , struct V_11 * V_12 )
{
struct V_21 * V_22 ;
T_2 V_23 , * V_24 ;
int V_69 = 0 ;
int V_80 = 0 ;
int V_25 , V_62 ;
F_54 ( L_28 , V_79 ) ;
if ( V_79 == 0 )
return - V_44 ;
V_24 = V_12 -> V_14 ;
V_23 = * V_24 ++ ;
V_22 = (struct V_21 * ) V_24 ;
for ( V_25 = 0 ; V_25 < V_23 ; V_25 ++ ) {
if ( ! ( V_22 [ V_25 ] . V_29 & V_45 ) )
V_69 ++ ;
}
if ( V_69 < V_79 )
return - V_44 ;
for ( V_25 = 0 ; V_25 < V_23 && V_79 != V_80 ; V_25 ++ ) {
V_62 = F_65 ( V_22 [ V_25 ] . V_27 ) ;
if ( V_62 )
continue;
V_62 = F_55 ( & V_22 [ V_25 ] ) ;
if ( V_62 ) {
F_56 ( V_22 [ V_25 ] . V_27 ) ;
continue;
}
V_80 ++ ;
V_22 [ V_25 ] . V_70 = 1 ;
}
if ( V_80 != V_79 ) {
F_29 ( L_29 ) ;
for ( V_25 = 0 ; V_25 < V_23 ; V_25 ++ ) {
if ( ! V_22 [ V_25 ] . V_70 )
continue;
V_62 = F_50 ( & V_22 [ V_25 ] ) ;
if ( V_62 )
F_29 ( L_30 ,
F_17 ( V_22 [ V_25 ] . V_27 ) ) ;
else
F_56 ( V_22 [ V_25 ] . V_27 ) ;
}
V_62 = - V_44 ;
} else {
for ( V_25 = 0 ; V_25 < V_23 ; V_25 ++ ) {
if ( ! V_22 [ V_25 ] . V_70 )
continue;
F_54 ( L_31 ,
V_22 [ V_25 ] . V_26 , V_22 [ V_25 ] . V_27 ) ;
V_22 [ V_25 ] . V_70 = 0 ;
}
}
return V_62 ;
}
static int F_66 ( T_2 V_27 , struct V_11 * V_12 )
{
struct V_21 * V_22 ;
T_2 V_23 , * V_24 ;
int V_25 , V_71 ;
int V_62 ;
F_54 ( L_32 , V_27 ) ;
V_24 = V_12 -> V_14 ;
V_23 = * V_24 ++ ;
V_22 = (struct V_21 * ) V_24 ;
V_71 = 0 ;
for ( V_25 = 0 ; V_25 < V_23 ; V_25 ++ ) {
if ( V_22 [ V_25 ] . V_27 == V_27 ) {
V_71 = 1 ;
V_62 = F_65 ( V_22 [ V_25 ] . V_27 ) ;
if ( ! V_62 ) {
V_62 = F_55 ( & V_22 [ V_25 ] ) ;
if ( V_62 )
F_56 ( V_22 [ V_25 ] . V_27 ) ;
}
break;
}
}
if ( ! V_71 )
V_62 = - V_44 ;
if ( V_62 )
F_54 ( L_33 , V_27 ) ;
else
F_54 ( L_31 ,
V_22 [ V_25 ] . V_26 , V_27 ) ;
return V_62 ;
}
static int F_67 ( T_2 V_79 , T_2 V_27 ,
struct V_11 * V_12 )
{
struct V_21 * V_22 ;
T_2 V_23 , * V_24 ;
int V_25 , V_62 , V_72 ;
int V_69 = 0 , V_73 = 0 , V_74 ;
F_54 ( L_34 ,
V_79 , V_27 ) ;
if ( V_79 == 0 )
return - V_44 ;
V_24 = V_12 -> V_14 ;
V_23 = * V_24 ++ ;
V_22 = (struct V_21 * ) V_24 ;
V_72 = 0 ;
while ( V_73 < V_23 ) {
if ( V_22 [ V_73 ] . V_27 == V_27 ) {
V_72 = 1 ;
break;
}
V_73 ++ ;
}
if ( ! V_72 )
return - V_44 ;
V_74 = V_73 + V_79 ;
for ( V_25 = V_73 ; V_25 < V_74 ; V_25 ++ ) {
if ( V_22 [ V_25 ] . V_29 & V_75 )
break;
V_69 ++ ;
}
if ( V_69 < V_79 )
return - V_44 ;
for ( V_25 = V_73 ; V_25 < V_74 ; V_25 ++ ) {
if ( V_22 [ V_25 ] . V_29 & V_45 )
continue;
V_62 = F_65 ( V_22 [ V_25 ] . V_27 ) ;
if ( V_62 )
break;
V_62 = F_55 ( & V_22 [ V_25 ] ) ;
if ( V_62 ) {
F_56 ( V_22 [ V_25 ] . V_27 ) ;
break;
}
V_22 [ V_25 ] . V_70 = 1 ;
}
if ( V_62 ) {
F_29 ( L_35 ) ;
for ( V_25 = V_73 ; V_25 < V_74 ; V_25 ++ ) {
if ( ! V_22 [ V_25 ] . V_70 )
continue;
V_62 = F_50 ( & V_22 [ V_25 ] ) ;
if ( V_62 )
F_29 ( L_30 ,
F_17 ( V_22 [ V_25 ] . V_27 ) ) ;
else
F_56 ( V_22 [ V_25 ] . V_27 ) ;
}
V_62 = - V_44 ;
} else {
for ( V_25 = V_73 ; V_25 < V_74 ; V_25 ++ ) {
if ( ! V_22 [ V_25 ] . V_70 )
continue;
F_54 ( L_31 ,
V_22 [ V_25 ] . V_26 , V_22 [ V_25 ] . V_27 ) ;
V_22 [ V_25 ] . V_70 = 0 ;
}
}
return V_62 ;
}
int F_68 ( struct V_77 * V_78 )
{
struct V_1 * V_20 ;
struct V_11 * V_12 ;
T_2 V_81 , V_27 ;
int V_62 ;
F_37 () ;
V_20 = F_2 ( L_1 ) ;
if ( ! V_20 ) {
V_62 = - V_44 ;
goto V_82;
}
V_12 = F_15 ( V_20 ) ;
if ( ! V_12 ) {
V_62 = - V_44 ;
goto V_82;
}
switch ( V_78 -> V_83 ) {
case V_84 :
if ( V_78 -> V_85 == V_86 ) {
V_81 = V_78 -> V_87 . V_88 ;
V_62 = F_64 ( V_81 , V_12 ) ;
} else if ( V_78 -> V_85 == V_89 ) {
V_27 = V_78 -> V_87 . V_27 ;
V_62 = F_66 ( V_27 , V_12 ) ;
} else if ( V_78 -> V_85 == V_90 ) {
V_81 = V_78 -> V_87 . V_91 . V_81 ;
V_27 = V_78 -> V_87 . V_91 . V_40 ;
V_62 = F_67 ( V_81 , V_27 , V_12 ) ;
} else {
V_62 = - V_44 ;
}
break;
case V_92 :
if ( V_78 -> V_85 == V_86 ) {
V_81 = V_78 -> V_87 . V_88 ;
V_62 = F_53 ( V_81 , V_12 ) ;
} else if ( V_78 -> V_85 == V_89 ) {
V_27 = V_78 -> V_87 . V_27 ;
V_62 = F_57 ( V_27 , V_12 ) ;
} else if ( V_78 -> V_85 == V_90 ) {
V_81 = V_78 -> V_87 . V_91 . V_81 ;
V_27 = V_78 -> V_87 . V_91 . V_40 ;
V_62 = F_59 ( V_81 , V_27 , V_12 ) ;
} else {
V_62 = - V_44 ;
}
break;
case V_93 :
V_27 = V_78 -> V_87 . V_27 ;
V_62 = F_58 ( V_27 , V_12 ) ;
break;
default:
F_29 ( L_36 , V_78 -> V_83 ) ;
V_62 = - V_44 ;
break;
}
F_9 ( V_12 ) ;
V_82:
F_5 ( V_20 ) ;
F_42 () ;
return V_62 ;
}
static int F_69 ( struct V_1 * V_2 )
{
const char * type ;
const T_3 * V_58 ;
unsigned long V_51 ;
unsigned int V_59 ;
int V_60 = - V_44 ;
type = F_3 ( V_2 , L_10 , NULL ) ;
if ( type == NULL || strcmp ( type , L_11 ) != 0 )
return 0 ;
V_58 = F_3 ( V_2 , L_12 , NULL ) ;
if ( ! V_58 )
return V_60 ;
V_51 = F_18 ( * ( unsigned long * ) V_58 ) ;
V_59 = F_17 ( V_58 [ 3 ] ) ;
V_60 = F_70 ( V_51 , V_59 ) ;
return ( V_60 < 0 ) ? - V_44 : 0 ;
}
static int F_71 ( struct V_94 * V_95 )
{
struct V_21 * V_96 , * V_97 ;
unsigned long V_3 ;
T_2 V_98 ;
T_3 * V_24 ;
int V_25 , V_62 = - V_44 ;
if ( V_30 )
return 0 ;
V_3 = F_1 () ;
if ( ! V_3 )
return - V_44 ;
V_24 = ( T_3 * ) V_95 -> V_99 -> V_14 ;
if ( ! V_24 )
return - V_44 ;
V_98 = F_17 ( * V_24 ++ ) ;
V_97 = (struct V_21 * ) V_24 ;
V_24 = ( T_3 * ) V_95 -> V_12 -> V_14 ;
V_24 ++ ;
V_96 = (struct V_21 * ) V_24 ;
for ( V_25 = 0 ; V_25 < V_98 ; V_25 ++ ) {
if ( ( F_17 ( V_97 [ V_25 ] . V_29 ) & V_45 ) &&
( ! ( F_17 ( V_96 [ V_25 ] . V_29 ) & V_45 ) ) ) {
V_62 = F_36 (
F_18 ( V_97 [ V_25 ] . V_26 ) ,
V_3 ) ;
break;
} else if ( ( ! ( F_17 ( V_97 [ V_25 ] . V_29 ) &
V_45 ) ) &&
( F_17 ( V_96 [ V_25 ] . V_29 ) &
V_45 ) ) {
V_62 = F_70 ( F_18 ( V_97 [ V_25 ] . V_26 ) ,
V_3 ) ;
V_62 = ( V_62 < 0 ) ? - V_44 : 0 ;
break;
}
}
return V_62 ;
}
static int F_72 ( struct V_100 * V_101 ,
unsigned long V_83 , void * V_102 )
{
struct V_94 * V_103 = V_102 ;
int V_104 = 0 ;
switch ( V_83 ) {
case V_105 :
V_104 = F_69 ( V_103 -> V_20 ) ;
break;
case V_106 :
V_104 = F_43 ( V_103 -> V_20 ) ;
break;
case V_107 :
if ( ! strcmp ( V_103 -> V_12 -> V_13 , L_5 ) )
V_104 = F_71 ( V_103 ) ;
break;
}
return F_73 ( V_104 ) ;
}
static int T_5 F_74 ( void )
{
if ( F_75 ( V_108 ) )
F_76 ( & V_109 ) ;
return 0 ;
}
