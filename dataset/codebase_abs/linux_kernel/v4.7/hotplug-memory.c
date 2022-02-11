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
static struct V_11 * F_11 ( struct V_1 * V_15 )
{
struct V_11 * V_12 , * V_16 ;
struct V_17 * V_18 ;
T_2 V_19 , * V_20 ;
int V_21 ;
V_12 = F_12 ( V_15 , L_5 , NULL ) ;
if ( ! V_12 )
return NULL ;
V_16 = F_13 ( sizeof( * V_16 ) , V_22 ) ;
if ( ! V_16 )
return NULL ;
V_16 -> V_13 = F_14 ( V_12 -> V_13 , V_22 ) ;
V_16 -> V_14 = F_15 ( V_12 -> V_14 , V_12 -> V_23 , V_22 ) ;
if ( ! V_16 -> V_13 || ! V_16 -> V_14 ) {
F_9 ( V_16 ) ;
return NULL ;
}
V_16 -> V_23 = V_12 -> V_23 ;
V_20 = V_16 -> V_14 ;
* V_20 = F_16 ( * V_20 ) ;
V_19 = * V_20 ++ ;
V_18 = (struct V_17 * ) V_20 ;
for ( V_21 = 0 ; V_21 < V_19 ; V_21 ++ ) {
V_18 [ V_21 ] . V_24 = F_17 ( V_18 [ V_21 ] . V_24 ) ;
V_18 [ V_21 ] . V_25 = F_16 ( V_18 [ V_21 ] . V_25 ) ;
V_18 [ V_21 ] . V_26 = F_16 ( V_18 [ V_21 ] . V_26 ) ;
}
return V_16 ;
}
static void F_18 ( struct V_1 * V_15 ,
struct V_11 * V_12 )
{
struct V_17 * V_18 ;
T_2 V_19 , * V_20 ;
int V_21 ;
V_20 = V_12 -> V_14 ;
V_19 = * V_20 ;
* V_20 = F_19 ( * V_20 ) ;
V_20 ++ ;
V_18 = (struct V_17 * ) V_20 ;
for ( V_21 = 0 ; V_21 < V_19 ; V_21 ++ ) {
V_18 [ V_21 ] . V_24 = F_20 ( V_18 [ V_21 ] . V_24 ) ;
V_18 [ V_21 ] . V_25 = F_19 ( V_18 [ V_21 ] . V_25 ) ;
V_18 [ V_21 ] . V_26 = F_19 ( V_18 [ V_21 ] . V_26 ) ;
}
V_27 = true ;
F_21 ( V_15 , V_12 ) ;
V_27 = false ;
}
static int F_22 ( struct V_17 * V_28 )
{
struct V_1 * V_15 ;
struct V_11 * V_12 ;
struct V_17 * V_18 ;
T_2 * V_20 , V_19 ;
int V_21 ;
V_15 = F_2 ( L_1 ) ;
if ( ! V_15 )
return - V_29 ;
V_12 = F_11 ( V_15 ) ;
if ( ! V_12 ) {
F_5 ( V_15 ) ;
return - V_29 ;
}
V_20 = V_12 -> V_14 ;
V_19 = * V_20 ++ ;
V_18 = (struct V_17 * ) V_20 ;
for ( V_21 = 0 ; V_21 < V_19 ; V_21 ++ ) {
if ( V_18 [ V_21 ] . V_25 == V_28 -> V_25 ) {
V_18 [ V_21 ] . V_26 = V_28 -> V_26 ;
V_18 [ V_21 ] . V_30 = V_28 -> V_30 ;
F_18 ( V_15 , V_12 ) ;
break;
}
}
F_5 ( V_15 ) ;
return 0 ;
}
static T_2 F_23 ( struct V_17 * V_28 )
{
struct V_1 * V_31 , * V_32 , * V_33 ;
const T_2 * V_34 ;
const T_2 * V_35 ;
T_2 V_30 ;
int V_36 , V_37 , V_38 ;
int V_21 ;
V_31 = F_2 ( L_6 ) ;
if ( ! V_31 )
return - V_29 ;
V_32 = F_24 ( F_19 ( V_28 -> V_25 ) ,
V_31 ) ;
F_5 ( V_31 ) ;
if ( ! V_32 )
return - V_39 ;
V_34 = F_3 ( V_32 , L_7 , NULL ) ;
if ( ! V_34 ) {
F_25 ( V_32 ) ;
return - V_29 ;
}
V_33 = F_2 ( L_1 ) ;
if ( ! V_33 ) {
F_25 ( V_32 ) ;
return - V_29 ;
}
V_35 = F_3 ( V_33 ,
L_8 ,
NULL ) ;
F_5 ( V_33 ) ;
if ( ! V_35 ) {
F_25 ( V_32 ) ;
return - V_29 ;
}
V_36 = F_16 ( V_35 [ 0 ] ) ;
V_37 = F_16 ( V_35 [ 1 ] ) ;
V_38 = V_37 * sizeof( T_2 ) ;
V_30 = - 1 ;
for ( V_21 = 0 ; V_21 < V_36 ; V_21 ++ ) {
int V_40 = ( V_21 * V_37 ) + 2 ;
if ( memcmp ( & V_35 [ V_40 ] , & V_34 [ 1 ] , V_38 ) )
continue;
V_30 = V_21 ;
break;
}
F_25 ( V_32 ) ;
return V_30 ;
}
static int F_26 ( struct V_17 * V_28 )
{
int V_30 ;
V_28 -> V_26 |= V_41 ;
V_30 = F_23 ( V_28 ) ;
if ( V_30 < 0 ) {
F_27 ( L_9 ,
V_28 -> V_25 ) ;
return V_30 ;
}
V_28 -> V_30 = V_30 ;
return F_22 ( V_28 ) ;
}
static int F_28 ( struct V_17 * V_28 )
{
V_28 -> V_26 &= ~ V_41 ;
V_28 -> V_30 = 0xffffffff ;
return F_22 ( V_28 ) ;
}
static struct V_42 * F_29 ( struct V_17 * V_28 )
{
unsigned long V_43 ;
struct V_44 * V_45 ;
struct V_42 * V_46 ;
V_43 = F_30 ( F_31 ( V_28 -> V_24 ) ) ;
V_45 = F_32 ( V_43 ) ;
V_46 = F_33 ( V_45 ) ;
return V_46 ;
}
static int F_34 ( unsigned long V_47 , unsigned int V_3 )
{
unsigned long V_48 , V_49 ;
int V_50 ;
int V_21 , V_51 ;
V_49 = V_47 >> V_52 ;
F_35 () ;
if ( ! F_36 ( V_49 ) )
goto V_53;
V_48 = F_1 () ;
V_50 = V_48 / V_4 ;
V_51 = F_37 ( V_47 ) ;
for ( V_21 = 0 ; V_21 < V_50 ; V_21 ++ ) {
F_38 ( V_51 , V_47 , V_4 ) ;
V_47 += V_4 ;
}
V_53:
F_39 ( V_47 , V_3 ) ;
F_40 () ;
return 0 ;
}
static int F_41 ( struct V_1 * V_2 )
{
const char * type ;
const T_3 * V_54 ;
unsigned long V_47 ;
unsigned int V_55 ;
int V_56 = - V_39 ;
type = F_3 ( V_2 , L_10 , NULL ) ;
if ( type == NULL || strcmp ( type , L_11 ) != 0 )
return 0 ;
V_54 = F_3 ( V_2 , L_12 , NULL ) ;
if ( ! V_54 )
return V_56 ;
V_47 = F_17 ( * ( unsigned long * ) V_54 ) ;
V_55 = F_16 ( V_54 [ 3 ] ) ;
F_34 ( V_47 , V_55 ) ;
return 0 ;
}
static bool F_42 ( struct V_17 * V_28 )
{
int V_21 , V_57 ;
int V_58 = 1 ;
unsigned long V_59 , V_48 ;
T_4 V_60 ;
if ( ! ( V_28 -> V_26 & V_41 ) )
return false ;
V_48 = F_43 () ;
V_57 = V_48 / V_4 ;
V_60 = V_28 -> V_24 ;
for ( V_21 = 0 ; V_21 < V_57 ; V_21 ++ ) {
V_59 = F_31 ( V_60 ) ;
if ( ! F_44 ( V_59 ) )
continue;
V_58 &= F_45 ( V_59 , V_61 ) ;
V_60 += V_4 ;
}
return V_58 ? true : false ;
}
static int F_46 ( struct V_17 * V_28 )
{
struct V_42 * V_46 ;
unsigned long V_48 ;
int V_51 , V_58 ;
if ( ! F_42 ( V_28 ) )
return - V_39 ;
V_46 = F_29 ( V_28 ) ;
if ( ! V_46 )
return - V_39 ;
V_58 = F_47 ( & V_46 -> V_62 ) ;
F_48 ( & V_46 -> V_62 ) ;
if ( V_58 )
return V_58 ;
V_48 = F_1 () ;
V_51 = F_37 ( V_28 -> V_24 ) ;
F_38 ( V_51 , V_28 -> V_24 , V_48 ) ;
F_39 ( V_28 -> V_24 , V_48 ) ;
F_49 ( V_28 -> V_25 ) ;
F_28 ( V_28 ) ;
return 0 ;
}
static int F_50 ( T_2 V_63 ,
struct V_11 * V_12 )
{
struct V_17 * V_18 ;
int V_64 = 0 ;
int V_65 = 0 ;
T_2 V_19 , * V_20 ;
int V_21 , V_58 ;
F_51 ( L_13 , V_63 ) ;
if ( V_63 == 0 )
return - V_39 ;
V_20 = V_12 -> V_14 ;
V_19 = * V_20 ++ ;
V_18 = (struct V_17 * ) V_20 ;
for ( V_21 = 0 ; V_21 < V_19 ; V_21 ++ ) {
if ( V_18 [ V_21 ] . V_26 & V_41 )
V_65 ++ ;
}
if ( V_65 < V_63 )
return - V_39 ;
for ( V_21 = 0 ; V_21 < V_19 && V_64 < V_63 ; V_21 ++ ) {
V_58 = F_46 ( & V_18 [ V_21 ] ) ;
if ( V_58 )
continue;
V_64 ++ ;
V_18 [ V_21 ] . V_66 = 1 ;
}
if ( V_64 != V_63 ) {
F_27 ( L_14 ) ;
for ( V_21 = 0 ; V_21 < V_19 ; V_21 ++ ) {
if ( ! V_18 [ V_21 ] . V_66 )
continue;
V_58 = F_52 ( & V_18 [ V_21 ] ) ;
if ( V_58 )
F_27 ( L_15 ,
V_18 [ V_21 ] . V_25 ) ;
V_18 [ V_21 ] . V_66 = 0 ;
}
V_58 = - V_39 ;
} else {
for ( V_21 = 0 ; V_21 < V_19 ; V_21 ++ ) {
if ( ! V_18 [ V_21 ] . V_66 )
continue;
F_51 ( L_16 ,
V_18 [ V_21 ] . V_24 ) ;
V_18 [ V_21 ] . V_66 = 0 ;
}
V_58 = 0 ;
}
return V_58 ;
}
static int F_53 ( T_2 V_25 , struct V_11 * V_12 )
{
struct V_17 * V_18 ;
T_2 V_19 , * V_20 ;
int V_67 ;
int V_21 , V_58 ;
F_51 ( L_17 , V_25 ) ;
V_20 = V_12 -> V_14 ;
V_19 = * V_20 ++ ;
V_18 = (struct V_17 * ) V_20 ;
V_67 = 0 ;
for ( V_21 = 0 ; V_21 < V_19 ; V_21 ++ ) {
if ( V_18 [ V_21 ] . V_25 == V_25 ) {
V_67 = 1 ;
V_58 = F_46 ( & V_18 [ V_21 ] ) ;
break;
}
}
if ( ! V_67 )
V_58 = - V_39 ;
if ( V_58 )
F_51 ( L_18 ,
V_18 [ V_21 ] . V_24 ) ;
else
F_51 ( L_16 , V_18 [ V_21 ] . V_24 ) ;
return V_58 ;
}
static inline int F_34 ( unsigned long V_47 ,
unsigned int V_3 )
{
return - V_68 ;
}
static inline int F_41 ( struct V_1 * V_2 )
{
return 0 ;
}
static inline int F_54 ( struct V_69 * V_70 )
{
return - V_68 ;
}
static int F_46 ( struct V_17 * V_28 )
{
return - V_68 ;
}
static int F_50 ( T_2 V_63 ,
struct V_11 * V_12 )
{
return - V_68 ;
}
static int F_53 ( T_2 V_25 , struct V_11 * V_12 )
{
return - V_68 ;
}
static int F_55 ( struct V_17 * V_28 )
{
struct V_42 * V_46 ;
unsigned long V_48 ;
int V_51 , V_58 ;
V_48 = F_43 () ;
V_51 = F_37 ( V_28 -> V_24 ) ;
V_58 = F_56 ( V_51 , V_28 -> V_24 , V_48 ) ;
if ( V_58 )
return V_58 ;
V_58 = F_57 ( V_28 -> V_24 , V_48 ) ;
if ( V_58 ) {
F_38 ( V_51 , V_28 -> V_24 , V_48 ) ;
return V_58 ;
}
V_46 = F_29 ( V_28 ) ;
if ( ! V_46 ) {
F_38 ( V_51 , V_28 -> V_24 , V_48 ) ;
return - V_39 ;
}
V_58 = F_58 ( & V_46 -> V_62 ) ;
F_48 ( & V_46 -> V_62 ) ;
if ( V_58 ) {
F_38 ( V_51 , V_28 -> V_24 , V_48 ) ;
return V_58 ;
}
V_28 -> V_26 |= V_41 ;
return 0 ;
}
static int F_52 ( struct V_17 * V_28 )
{
int V_58 ;
if ( V_28 -> V_26 & V_41 )
return - V_39 ;
V_58 = F_59 ( V_28 -> V_25 ) ;
if ( V_58 )
return V_58 ;
V_58 = F_26 ( V_28 ) ;
if ( V_58 ) {
F_27 ( L_19 ,
V_28 -> V_25 ) ;
F_49 ( V_28 -> V_25 ) ;
return V_58 ;
}
V_58 = F_55 ( V_28 ) ;
if ( V_58 ) {
F_28 ( V_28 ) ;
F_49 ( V_28 -> V_25 ) ;
}
return V_58 ;
}
static int F_60 ( T_2 V_71 , struct V_11 * V_12 )
{
struct V_17 * V_18 ;
T_2 V_19 , * V_20 ;
int V_65 = 0 ;
int V_72 = 0 ;
int V_21 , V_58 ;
F_51 ( L_20 , V_71 ) ;
if ( V_71 == 0 )
return - V_39 ;
V_20 = V_12 -> V_14 ;
V_19 = * V_20 ++ ;
V_18 = (struct V_17 * ) V_20 ;
for ( V_21 = 0 ; V_21 < V_19 ; V_21 ++ ) {
if ( ! ( V_18 [ V_21 ] . V_26 & V_41 ) )
V_65 ++ ;
}
if ( V_65 < V_71 )
return - V_39 ;
for ( V_21 = 0 ; V_21 < V_19 && V_71 != V_72 ; V_21 ++ ) {
V_58 = F_52 ( & V_18 [ V_21 ] ) ;
if ( V_58 )
continue;
V_72 ++ ;
V_18 [ V_21 ] . V_66 = 1 ;
}
if ( V_72 != V_71 ) {
F_27 ( L_21 ) ;
for ( V_21 = 0 ; V_21 < V_19 ; V_21 ++ ) {
if ( ! V_18 [ V_21 ] . V_66 )
continue;
V_58 = F_46 ( & V_18 [ V_21 ] ) ;
if ( V_58 )
F_27 ( L_22 ,
F_16 ( V_18 [ V_21 ] . V_25 ) ) ;
}
V_58 = - V_39 ;
} else {
for ( V_21 = 0 ; V_21 < V_19 ; V_21 ++ ) {
if ( ! V_18 [ V_21 ] . V_66 )
continue;
F_51 ( L_23 ,
V_18 [ V_21 ] . V_24 , V_18 [ V_21 ] . V_25 ) ;
V_18 [ V_21 ] . V_66 = 0 ;
}
}
return V_58 ;
}
static int F_61 ( T_2 V_25 , struct V_11 * V_12 )
{
struct V_17 * V_18 ;
T_2 V_19 , * V_20 ;
int V_21 , V_67 ;
int V_58 ;
F_51 ( L_24 , V_25 ) ;
V_20 = V_12 -> V_14 ;
V_19 = * V_20 ++ ;
V_18 = (struct V_17 * ) V_20 ;
V_67 = 0 ;
for ( V_21 = 0 ; V_21 < V_19 ; V_21 ++ ) {
if ( V_18 [ V_21 ] . V_25 == V_25 ) {
V_67 = 1 ;
V_58 = F_52 ( & V_18 [ V_21 ] ) ;
break;
}
}
if ( ! V_67 )
V_58 = - V_39 ;
if ( V_58 )
F_51 ( L_25 , V_25 ) ;
else
F_51 ( L_23 ,
V_18 [ V_21 ] . V_24 , V_25 ) ;
return V_58 ;
}
int F_62 ( struct V_69 * V_70 )
{
struct V_1 * V_15 ;
struct V_11 * V_12 ;
T_2 V_73 , V_25 ;
int V_58 ;
V_73 = V_70 -> V_74 . V_75 ;
V_25 = V_70 -> V_74 . V_25 ;
F_35 () ;
V_15 = F_2 ( L_1 ) ;
if ( ! V_15 ) {
V_58 = - V_39 ;
goto V_76;
}
V_12 = F_11 ( V_15 ) ;
if ( ! V_12 ) {
V_58 = - V_39 ;
goto V_76;
}
switch ( V_70 -> V_77 ) {
case V_78 :
if ( V_70 -> V_79 == V_80 )
V_58 = F_60 ( V_73 , V_12 ) ;
else if ( V_70 -> V_79 == V_81 )
V_58 = F_61 ( V_25 , V_12 ) ;
else
V_58 = - V_39 ;
break;
case V_82 :
if ( V_70 -> V_79 == V_80 )
V_58 = F_50 ( V_73 , V_12 ) ;
else if ( V_70 -> V_79 == V_81 )
V_58 = F_53 ( V_25 , V_12 ) ;
else
V_58 = - V_39 ;
break;
default:
F_27 ( L_26 , V_70 -> V_77 ) ;
V_58 = - V_39 ;
break;
}
F_9 ( V_12 ) ;
V_76:
F_5 ( V_15 ) ;
F_40 () ;
return V_58 ;
}
static int F_63 ( struct V_1 * V_2 )
{
const char * type ;
const T_3 * V_54 ;
unsigned long V_47 ;
unsigned int V_55 ;
int V_56 = - V_39 ;
type = F_3 ( V_2 , L_10 , NULL ) ;
if ( type == NULL || strcmp ( type , L_11 ) != 0 )
return 0 ;
V_54 = F_3 ( V_2 , L_12 , NULL ) ;
if ( ! V_54 )
return V_56 ;
V_47 = F_17 ( * ( unsigned long * ) V_54 ) ;
V_55 = F_16 ( V_54 [ 3 ] ) ;
V_56 = F_57 ( V_47 , V_55 ) ;
return ( V_56 < 0 ) ? - V_39 : 0 ;
}
static int F_64 ( struct V_83 * V_84 )
{
struct V_17 * V_85 , * V_86 ;
unsigned long V_3 ;
T_2 V_87 ;
T_3 * V_20 ;
int V_21 , V_58 = - V_39 ;
if ( V_27 )
return 0 ;
V_3 = F_1 () ;
if ( ! V_3 )
return - V_39 ;
V_20 = ( T_3 * ) V_84 -> V_88 -> V_14 ;
if ( ! V_20 )
return - V_39 ;
V_87 = F_16 ( * V_20 ++ ) ;
V_86 = (struct V_17 * ) V_20 ;
V_20 = ( T_3 * ) V_84 -> V_12 -> V_14 ;
V_20 ++ ;
V_85 = (struct V_17 * ) V_20 ;
for ( V_21 = 0 ; V_21 < V_87 ; V_21 ++ ) {
if ( ( F_16 ( V_86 [ V_21 ] . V_26 ) & V_41 ) &&
( ! ( F_16 ( V_85 [ V_21 ] . V_26 ) & V_41 ) ) ) {
V_58 = F_34 (
F_17 ( V_86 [ V_21 ] . V_24 ) ,
V_3 ) ;
break;
} else if ( ( ! ( F_16 ( V_86 [ V_21 ] . V_26 ) &
V_41 ) ) &&
( F_16 ( V_85 [ V_21 ] . V_26 ) &
V_41 ) ) {
V_58 = F_57 ( F_17 ( V_86 [ V_21 ] . V_24 ) ,
V_3 ) ;
V_58 = ( V_58 < 0 ) ? - V_39 : 0 ;
break;
}
}
return V_58 ;
}
static int F_65 ( struct V_89 * V_90 ,
unsigned long V_77 , void * V_91 )
{
struct V_83 * V_92 = V_91 ;
int V_93 = 0 ;
switch ( V_77 ) {
case V_94 :
V_93 = F_63 ( V_92 -> V_15 ) ;
break;
case V_95 :
V_93 = F_41 ( V_92 -> V_15 ) ;
break;
case V_96 :
if ( ! strcmp ( V_92 -> V_12 -> V_13 , L_5 ) )
V_93 = F_64 ( V_92 ) ;
break;
}
return F_66 ( V_93 ) ;
}
static int T_5 F_67 ( void )
{
if ( F_68 ( V_97 ) )
F_69 ( & V_98 ) ;
return 0 ;
}
