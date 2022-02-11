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
}
V_29 = true ;
F_22 ( V_20 , V_12 ) ;
V_29 = false ;
}
static int F_23 ( struct V_21 * V_30 )
{
struct V_1 * V_20 ;
struct V_11 * V_12 ;
struct V_21 * V_22 ;
T_2 * V_24 , V_23 ;
int V_25 ;
V_20 = F_2 ( L_1 ) ;
if ( ! V_20 )
return - V_31 ;
V_12 = F_15 ( V_20 ) ;
if ( ! V_12 ) {
F_5 ( V_20 ) ;
return - V_31 ;
}
V_24 = V_12 -> V_14 ;
V_23 = * V_24 ++ ;
V_22 = (struct V_21 * ) V_24 ;
for ( V_25 = 0 ; V_25 < V_23 ; V_25 ++ ) {
if ( V_22 [ V_25 ] . V_27 == V_30 -> V_27 ) {
V_22 [ V_25 ] . V_28 = V_30 -> V_28 ;
V_22 [ V_25 ] . V_32 = V_30 -> V_32 ;
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
T_2 V_32 ;
int V_37 , V_38 , V_39 ;
int V_25 , V_40 ;
V_36 = V_34 -> V_14 ;
V_37 = F_17 ( V_36 [ 0 ] ) ;
V_38 = F_17 ( V_36 [ 1 ] ) ;
V_39 = V_38 * sizeof( T_2 ) ;
V_32 = - 1 ;
for ( V_25 = 0 ; V_25 < V_37 ; V_25 ++ ) {
V_40 = ( V_25 * V_38 ) + 2 ;
if ( memcmp ( & V_36 [ V_40 ] , & V_35 [ 1 ] , V_39 ) )
continue;
V_32 = V_25 ;
break;
}
if ( V_32 == - 1 ) {
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
V_32 = F_17 ( V_36 [ 0 ] ) - 1 ;
}
return V_32 ;
}
static T_2 F_25 ( struct V_21 * V_30 )
{
struct V_1 * V_42 , * V_43 , * V_33 ;
struct V_11 * V_34 ;
const T_2 * V_35 ;
T_2 V_32 ;
V_42 = F_2 ( L_6 ) ;
if ( ! V_42 )
return - V_31 ;
V_43 = F_26 ( F_20 ( V_30 -> V_27 ) ,
V_42 ) ;
F_5 ( V_42 ) ;
if ( ! V_43 )
return - V_44 ;
V_35 = F_3 ( V_43 , L_7 , NULL ) ;
if ( ! V_35 ) {
F_27 ( V_43 ) ;
return - V_31 ;
}
V_33 = F_2 ( L_1 ) ;
if ( ! V_33 ) {
F_27 ( V_43 ) ;
return - V_31 ;
}
V_34 = F_16 ( V_33 , L_8 ,
NULL ) ;
if ( ! V_34 ) {
F_5 ( V_33 ) ;
F_27 ( V_43 ) ;
return - V_31 ;
}
V_32 = F_24 ( V_33 , V_34 , V_35 ) ;
F_27 ( V_43 ) ;
return V_32 ;
}
static int F_28 ( struct V_21 * V_30 )
{
int V_32 ;
V_30 -> V_28 |= V_45 ;
V_32 = F_25 ( V_30 ) ;
if ( V_32 < 0 ) {
F_29 ( L_9 ,
V_30 -> V_27 ) ;
return V_32 ;
}
V_30 -> V_32 = V_32 ;
return F_23 ( V_30 ) ;
}
static int F_30 ( struct V_21 * V_30 )
{
V_30 -> V_28 &= ~ V_45 ;
V_30 -> V_32 = 0xffffffff ;
return F_23 ( V_30 ) ;
}
static int F_31 ( unsigned long V_46 , unsigned int V_3 )
{
unsigned long V_47 , V_48 ;
int V_49 ;
int V_25 , V_50 ;
V_48 = V_46 >> V_51 ;
F_32 () ;
if ( ! F_33 ( V_48 ) )
goto V_52;
V_47 = F_1 () ;
V_49 = V_47 / V_4 ;
V_50 = F_34 ( V_46 ) ;
for ( V_25 = 0 ; V_25 < V_49 ; V_25 ++ ) {
F_35 ( V_50 , V_46 , V_4 ) ;
V_46 += V_4 ;
}
V_52:
F_36 ( V_46 , V_3 ) ;
F_37 () ;
return 0 ;
}
static int F_38 ( struct V_1 * V_2 )
{
const char * type ;
const T_3 * V_53 ;
unsigned long V_46 ;
unsigned int V_54 ;
int V_55 = - V_44 ;
type = F_3 ( V_2 , L_10 , NULL ) ;
if ( type == NULL || strcmp ( type , L_11 ) != 0 )
return 0 ;
V_53 = F_3 ( V_2 , L_12 , NULL ) ;
if ( ! V_53 )
return V_55 ;
V_46 = F_18 ( * ( unsigned long * ) V_53 ) ;
V_54 = F_17 ( V_53 [ 3 ] ) ;
F_31 ( V_46 , V_54 ) ;
return 0 ;
}
static bool F_39 ( struct V_21 * V_30 )
{
int V_25 , V_56 ;
int V_57 = 1 ;
unsigned long V_58 , V_47 ;
T_4 V_59 ;
if ( ! ( V_30 -> V_28 & V_45 ) )
return false ;
V_47 = F_40 () ;
V_56 = V_47 / V_4 ;
V_59 = V_30 -> V_26 ;
for ( V_25 = 0 ; V_25 < V_56 ; V_25 ++ ) {
V_58 = F_41 ( V_59 ) ;
if ( ! F_42 ( V_58 ) )
continue;
V_57 &= F_43 ( V_58 , V_60 ) ;
V_59 += V_4 ;
}
return V_57 ? true : false ;
}
static struct V_61 * F_44 ( struct V_21 * V_30 )
{
unsigned long V_62 ;
struct V_63 * V_64 ;
struct V_61 * V_65 ;
V_62 = F_45 ( F_41 ( V_30 -> V_26 ) ) ;
V_64 = F_46 ( V_62 ) ;
V_65 = F_47 ( V_64 ) ;
return V_65 ;
}
static int F_48 ( struct V_21 * V_30 )
{
struct V_61 * V_65 ;
unsigned long V_47 ;
int V_50 , V_57 ;
if ( ! F_39 ( V_30 ) )
return - V_44 ;
V_65 = F_44 ( V_30 ) ;
if ( ! V_65 )
return - V_44 ;
V_57 = F_49 ( & V_65 -> V_66 ) ;
F_50 ( & V_65 -> V_66 ) ;
if ( V_57 )
return V_57 ;
V_47 = F_1 () ;
V_50 = F_34 ( V_30 -> V_26 ) ;
F_35 ( V_50 , V_30 -> V_26 , V_47 ) ;
F_36 ( V_30 -> V_26 , V_47 ) ;
F_51 ( V_30 -> V_27 ) ;
F_30 ( V_30 ) ;
return 0 ;
}
static int F_52 ( T_2 V_67 ,
struct V_11 * V_12 )
{
struct V_21 * V_22 ;
int V_68 = 0 ;
int V_69 = 0 ;
T_2 V_23 , * V_24 ;
int V_25 , V_57 ;
F_53 ( L_13 , V_67 ) ;
if ( V_67 == 0 )
return - V_44 ;
V_24 = V_12 -> V_14 ;
V_23 = * V_24 ++ ;
V_22 = (struct V_21 * ) V_24 ;
for ( V_25 = 0 ; V_25 < V_23 ; V_25 ++ ) {
if ( V_22 [ V_25 ] . V_28 & V_45 )
V_69 ++ ;
}
if ( V_69 < V_67 )
return - V_44 ;
for ( V_25 = 0 ; V_25 < V_23 && V_68 < V_67 ; V_25 ++ ) {
V_57 = F_48 ( & V_22 [ V_25 ] ) ;
if ( V_57 )
continue;
V_68 ++ ;
V_22 [ V_25 ] . V_70 = 1 ;
}
if ( V_68 != V_67 ) {
F_29 ( L_14 ) ;
for ( V_25 = 0 ; V_25 < V_23 ; V_25 ++ ) {
if ( ! V_22 [ V_25 ] . V_70 )
continue;
V_57 = F_54 ( & V_22 [ V_25 ] ) ;
if ( V_57 )
F_29 ( L_15 ,
V_22 [ V_25 ] . V_27 ) ;
V_22 [ V_25 ] . V_70 = 0 ;
}
V_57 = - V_44 ;
} else {
for ( V_25 = 0 ; V_25 < V_23 ; V_25 ++ ) {
if ( ! V_22 [ V_25 ] . V_70 )
continue;
F_53 ( L_16 ,
V_22 [ V_25 ] . V_26 ) ;
V_22 [ V_25 ] . V_70 = 0 ;
}
V_57 = 0 ;
}
return V_57 ;
}
static int F_55 ( T_2 V_27 , struct V_11 * V_12 )
{
struct V_21 * V_22 ;
T_2 V_23 , * V_24 ;
int V_71 ;
int V_25 , V_57 ;
F_53 ( L_17 , V_27 ) ;
V_24 = V_12 -> V_14 ;
V_23 = * V_24 ++ ;
V_22 = (struct V_21 * ) V_24 ;
V_71 = 0 ;
for ( V_25 = 0 ; V_25 < V_23 ; V_25 ++ ) {
if ( V_22 [ V_25 ] . V_27 == V_27 ) {
V_71 = 1 ;
V_57 = F_48 ( & V_22 [ V_25 ] ) ;
break;
}
}
if ( ! V_71 )
V_57 = - V_44 ;
if ( V_57 )
F_53 ( L_18 ,
V_22 [ V_25 ] . V_26 ) ;
else
F_53 ( L_16 , V_22 [ V_25 ] . V_26 ) ;
return V_57 ;
}
static inline int F_31 ( unsigned long V_46 ,
unsigned int V_3 )
{
return - V_72 ;
}
static inline int F_38 ( struct V_1 * V_2 )
{
return 0 ;
}
static inline int F_56 ( struct V_73 * V_74 )
{
return - V_72 ;
}
static int F_48 ( struct V_21 * V_30 )
{
return - V_72 ;
}
static int F_52 ( T_2 V_67 ,
struct V_11 * V_12 )
{
return - V_72 ;
}
static int F_55 ( T_2 V_27 , struct V_11 * V_12 )
{
return - V_72 ;
}
static int F_54 ( struct V_21 * V_30 )
{
unsigned long V_47 ;
int V_50 , V_57 ;
if ( V_30 -> V_28 & V_45 )
return - V_44 ;
V_57 = F_57 ( V_30 -> V_27 ) ;
if ( V_57 )
return V_57 ;
V_57 = F_28 ( V_30 ) ;
if ( V_57 ) {
F_29 ( L_19 ,
V_30 -> V_27 ) ;
F_51 ( V_30 -> V_27 ) ;
return V_57 ;
}
V_47 = F_40 () ;
V_50 = F_34 ( V_30 -> V_26 ) ;
V_57 = F_58 ( V_50 , V_30 -> V_26 , V_47 ) ;
if ( V_57 ) {
F_30 ( V_30 ) ;
F_51 ( V_30 -> V_27 ) ;
} else {
V_30 -> V_28 |= V_45 ;
}
return V_57 ;
}
static int F_59 ( T_2 V_75 , struct V_11 * V_12 )
{
struct V_21 * V_22 ;
T_2 V_23 , * V_24 ;
int V_69 = 0 ;
int V_76 = 0 ;
int V_25 , V_57 ;
F_53 ( L_20 , V_75 ) ;
if ( V_75 == 0 )
return - V_44 ;
V_24 = V_12 -> V_14 ;
V_23 = * V_24 ++ ;
V_22 = (struct V_21 * ) V_24 ;
for ( V_25 = 0 ; V_25 < V_23 ; V_25 ++ ) {
if ( ! ( V_22 [ V_25 ] . V_28 & V_45 ) )
V_69 ++ ;
}
if ( V_69 < V_75 )
return - V_44 ;
for ( V_25 = 0 ; V_25 < V_23 && V_75 != V_76 ; V_25 ++ ) {
V_57 = F_54 ( & V_22 [ V_25 ] ) ;
if ( V_57 )
continue;
V_76 ++ ;
V_22 [ V_25 ] . V_70 = 1 ;
}
if ( V_76 != V_75 ) {
F_29 ( L_21 ) ;
for ( V_25 = 0 ; V_25 < V_23 ; V_25 ++ ) {
if ( ! V_22 [ V_25 ] . V_70 )
continue;
V_57 = F_48 ( & V_22 [ V_25 ] ) ;
if ( V_57 )
F_29 ( L_22 ,
F_17 ( V_22 [ V_25 ] . V_27 ) ) ;
}
V_57 = - V_44 ;
} else {
for ( V_25 = 0 ; V_25 < V_23 ; V_25 ++ ) {
if ( ! V_22 [ V_25 ] . V_70 )
continue;
F_53 ( L_23 ,
V_22 [ V_25 ] . V_26 , V_22 [ V_25 ] . V_27 ) ;
V_22 [ V_25 ] . V_70 = 0 ;
}
}
return V_57 ;
}
static int F_60 ( T_2 V_27 , struct V_11 * V_12 )
{
struct V_21 * V_22 ;
T_2 V_23 , * V_24 ;
int V_25 , V_71 ;
int V_57 ;
F_53 ( L_24 , V_27 ) ;
V_24 = V_12 -> V_14 ;
V_23 = * V_24 ++ ;
V_22 = (struct V_21 * ) V_24 ;
V_71 = 0 ;
for ( V_25 = 0 ; V_25 < V_23 ; V_25 ++ ) {
if ( V_22 [ V_25 ] . V_27 == V_27 ) {
V_71 = 1 ;
V_57 = F_54 ( & V_22 [ V_25 ] ) ;
break;
}
}
if ( ! V_71 )
V_57 = - V_44 ;
if ( V_57 )
F_53 ( L_25 , V_27 ) ;
else
F_53 ( L_23 ,
V_22 [ V_25 ] . V_26 , V_27 ) ;
return V_57 ;
}
int F_61 ( struct V_73 * V_74 )
{
struct V_1 * V_20 ;
struct V_11 * V_12 ;
T_2 V_77 , V_27 ;
int V_57 ;
V_77 = V_74 -> V_78 . V_79 ;
V_27 = V_74 -> V_78 . V_27 ;
F_32 () ;
V_20 = F_2 ( L_1 ) ;
if ( ! V_20 ) {
V_57 = - V_44 ;
goto V_80;
}
V_12 = F_15 ( V_20 ) ;
if ( ! V_12 ) {
V_57 = - V_44 ;
goto V_80;
}
switch ( V_74 -> V_81 ) {
case V_82 :
if ( V_74 -> V_83 == V_84 )
V_57 = F_59 ( V_77 , V_12 ) ;
else if ( V_74 -> V_83 == V_85 )
V_57 = F_60 ( V_27 , V_12 ) ;
else
V_57 = - V_44 ;
break;
case V_86 :
if ( V_74 -> V_83 == V_84 )
V_57 = F_52 ( V_77 , V_12 ) ;
else if ( V_74 -> V_83 == V_85 )
V_57 = F_55 ( V_27 , V_12 ) ;
else
V_57 = - V_44 ;
break;
default:
F_29 ( L_26 , V_74 -> V_81 ) ;
V_57 = - V_44 ;
break;
}
F_9 ( V_12 ) ;
V_80:
F_5 ( V_20 ) ;
F_37 () ;
return V_57 ;
}
static int F_62 ( struct V_1 * V_2 )
{
const char * type ;
const T_3 * V_53 ;
unsigned long V_46 ;
unsigned int V_54 ;
int V_55 = - V_44 ;
type = F_3 ( V_2 , L_10 , NULL ) ;
if ( type == NULL || strcmp ( type , L_11 ) != 0 )
return 0 ;
V_53 = F_3 ( V_2 , L_12 , NULL ) ;
if ( ! V_53 )
return V_55 ;
V_46 = F_18 ( * ( unsigned long * ) V_53 ) ;
V_54 = F_17 ( V_53 [ 3 ] ) ;
V_55 = F_63 ( V_46 , V_54 ) ;
return ( V_55 < 0 ) ? - V_44 : 0 ;
}
static int F_64 ( struct V_87 * V_88 )
{
struct V_21 * V_89 , * V_90 ;
unsigned long V_3 ;
T_2 V_91 ;
T_3 * V_24 ;
int V_25 , V_57 = - V_44 ;
if ( V_29 )
return 0 ;
V_3 = F_1 () ;
if ( ! V_3 )
return - V_44 ;
V_24 = ( T_3 * ) V_88 -> V_92 -> V_14 ;
if ( ! V_24 )
return - V_44 ;
V_91 = F_17 ( * V_24 ++ ) ;
V_90 = (struct V_21 * ) V_24 ;
V_24 = ( T_3 * ) V_88 -> V_12 -> V_14 ;
V_24 ++ ;
V_89 = (struct V_21 * ) V_24 ;
for ( V_25 = 0 ; V_25 < V_91 ; V_25 ++ ) {
if ( ( F_17 ( V_90 [ V_25 ] . V_28 ) & V_45 ) &&
( ! ( F_17 ( V_89 [ V_25 ] . V_28 ) & V_45 ) ) ) {
V_57 = F_31 (
F_18 ( V_90 [ V_25 ] . V_26 ) ,
V_3 ) ;
break;
} else if ( ( ! ( F_17 ( V_90 [ V_25 ] . V_28 ) &
V_45 ) ) &&
( F_17 ( V_89 [ V_25 ] . V_28 ) &
V_45 ) ) {
V_57 = F_63 ( F_18 ( V_90 [ V_25 ] . V_26 ) ,
V_3 ) ;
V_57 = ( V_57 < 0 ) ? - V_44 : 0 ;
break;
}
}
return V_57 ;
}
static int F_65 ( struct V_93 * V_94 ,
unsigned long V_81 , void * V_95 )
{
struct V_87 * V_96 = V_95 ;
int V_97 = 0 ;
switch ( V_81 ) {
case V_98 :
V_97 = F_62 ( V_96 -> V_20 ) ;
break;
case V_99 :
V_97 = F_38 ( V_96 -> V_20 ) ;
break;
case V_100 :
if ( ! strcmp ( V_96 -> V_12 -> V_13 , L_5 ) )
V_97 = F_64 ( V_96 ) ;
break;
}
return F_66 ( V_97 ) ;
}
static int T_5 F_67 ( void )
{
if ( F_68 ( V_101 ) )
F_69 ( & V_102 ) ;
return 0 ;
}
