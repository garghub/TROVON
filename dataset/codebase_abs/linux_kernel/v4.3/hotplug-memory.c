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
static struct V_27 * F_18 ( struct V_17 * V_28 )
{
unsigned long V_29 ;
struct V_30 * V_31 ;
struct V_27 * V_32 ;
V_29 = F_19 ( F_20 ( V_28 -> V_24 ) ) ;
V_31 = F_21 ( V_29 ) ;
V_32 = F_22 ( V_31 ) ;
return V_32 ;
}
static int F_23 ( unsigned long V_33 , unsigned int V_3 )
{
unsigned long V_34 , V_35 ;
int V_36 ;
int V_21 , V_37 ;
V_35 = V_33 >> V_38 ;
F_24 () ;
if ( ! F_25 ( V_35 ) )
goto V_39;
V_34 = F_1 () ;
V_36 = V_34 / V_4 ;
V_37 = F_26 ( V_33 ) ;
for ( V_21 = 0 ; V_21 < V_36 ; V_21 ++ ) {
F_27 ( V_37 , V_33 , V_4 ) ;
V_33 += V_4 ;
}
V_39:
F_28 ( V_33 , V_3 ) ;
F_29 () ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 )
{
const char * type ;
const T_3 * V_40 ;
unsigned long V_33 ;
unsigned int V_41 ;
int V_42 = - V_43 ;
type = F_3 ( V_2 , L_6 , NULL ) ;
if ( type == NULL || strcmp ( type , L_7 ) != 0 )
return 0 ;
V_40 = F_3 ( V_2 , L_8 , NULL ) ;
if ( ! V_40 )
return V_42 ;
V_33 = F_17 ( * ( unsigned long * ) V_40 ) ;
V_41 = F_16 ( V_40 [ 3 ] ) ;
F_23 ( V_33 , V_41 ) ;
return 0 ;
}
static bool F_31 ( struct V_17 * V_28 )
{
int V_21 , V_44 ;
int V_45 = 1 ;
unsigned long V_46 , V_34 ;
T_4 V_47 ;
if ( ! ( V_28 -> V_26 & V_48 ) )
return false ;
V_34 = F_32 () ;
V_44 = V_34 / V_4 ;
V_47 = V_28 -> V_24 ;
for ( V_21 = 0 ; V_21 < V_44 ; V_21 ++ ) {
V_46 = F_20 ( V_47 ) ;
if ( ! F_33 ( V_46 ) )
continue;
V_45 &= F_34 ( V_46 , V_49 ) ;
V_47 += V_4 ;
}
return V_45 ? true : false ;
}
static int F_35 ( struct V_17 * V_28 )
{
struct V_27 * V_32 ;
unsigned long V_34 ;
int V_37 , V_45 ;
if ( ! F_31 ( V_28 ) )
return - V_43 ;
V_32 = F_18 ( V_28 ) ;
if ( ! V_32 )
return - V_43 ;
V_45 = F_36 ( & V_32 -> V_50 ) ;
F_37 ( & V_32 -> V_50 ) ;
if ( V_45 )
return V_45 ;
V_34 = F_1 () ;
V_37 = F_26 ( V_28 -> V_24 ) ;
F_27 ( V_37 , V_28 -> V_24 , V_34 ) ;
F_28 ( V_28 -> V_24 , V_34 ) ;
F_38 ( V_28 -> V_25 ) ;
V_28 -> V_26 &= ~ V_48 ;
return 0 ;
}
static int F_39 ( T_2 V_51 ,
struct V_11 * V_12 )
{
struct V_17 * V_18 ;
int V_52 = 0 ;
int V_53 = 0 ;
T_2 V_19 , * V_20 ;
int V_21 , V_45 ;
F_40 ( L_9 , V_51 ) ;
if ( V_51 == 0 )
return - V_43 ;
V_20 = V_12 -> V_14 ;
V_19 = * V_20 ++ ;
V_18 = (struct V_17 * ) V_20 ;
for ( V_21 = 0 ; V_21 < V_19 ; V_21 ++ ) {
if ( V_18 [ V_21 ] . V_26 & V_48 )
V_53 ++ ;
}
if ( V_53 < V_51 )
return - V_43 ;
for ( V_21 = 0 ; V_21 < V_19 && V_52 < V_51 ; V_21 ++ ) {
V_45 = F_35 ( & V_18 [ V_21 ] ) ;
if ( V_45 )
continue;
V_52 ++ ;
V_18 [ V_21 ] . V_54 = 1 ;
}
if ( V_52 != V_51 ) {
F_41 ( L_10 ) ;
for ( V_21 = 0 ; V_21 < V_19 ; V_21 ++ ) {
if ( ! V_18 [ V_21 ] . V_54 )
continue;
V_45 = F_42 ( & V_18 [ V_21 ] ) ;
if ( V_45 )
F_41 ( L_11 ,
V_18 [ V_21 ] . V_25 ) ;
V_18 [ V_21 ] . V_54 = 0 ;
}
V_45 = - V_43 ;
} else {
for ( V_21 = 0 ; V_21 < V_19 ; V_21 ++ ) {
if ( ! V_18 [ V_21 ] . V_54 )
continue;
F_40 ( L_12 ,
V_18 [ V_21 ] . V_24 ) ;
V_18 [ V_21 ] . V_54 = 0 ;
}
V_45 = 0 ;
}
return V_45 ;
}
static int F_43 ( T_2 V_25 , struct V_11 * V_12 )
{
struct V_17 * V_18 ;
T_2 V_19 , * V_20 ;
int V_55 ;
int V_21 , V_45 ;
F_40 ( L_13 , V_25 ) ;
V_20 = V_12 -> V_14 ;
V_19 = * V_20 ++ ;
V_18 = (struct V_17 * ) V_20 ;
V_55 = 0 ;
for ( V_21 = 0 ; V_21 < V_19 ; V_21 ++ ) {
if ( V_18 [ V_21 ] . V_25 == V_25 ) {
V_55 = 1 ;
V_45 = F_35 ( & V_18 [ V_21 ] ) ;
break;
}
}
if ( ! V_55 )
V_45 = - V_43 ;
if ( V_45 )
F_40 ( L_14 ,
V_18 [ V_21 ] . V_24 ) ;
else
F_40 ( L_12 , V_18 [ V_21 ] . V_24 ) ;
return V_45 ;
}
static inline int F_23 ( unsigned long V_33 ,
unsigned int V_3 )
{
return - V_56 ;
}
static inline int F_30 ( struct V_1 * V_2 )
{
return 0 ;
}
static inline int F_44 ( struct V_57 * V_58 )
{
return - V_56 ;
}
static int F_35 ( struct V_17 * V_28 )
{
return - V_56 ;
}
static int F_39 ( T_2 V_51 ,
struct V_11 * V_12 )
{
return - V_56 ;
}
static int F_43 ( T_2 V_25 , struct V_11 * V_12 )
{
return - V_56 ;
}
static int F_42 ( struct V_17 * V_28 )
{
struct V_27 * V_32 ;
unsigned long V_34 ;
int V_37 , V_45 ;
if ( V_28 -> V_26 & V_48 )
return - V_43 ;
V_34 = F_32 () ;
V_45 = F_45 ( V_28 -> V_25 ) ;
if ( V_45 )
return V_45 ;
V_37 = F_26 ( V_28 -> V_24 ) ;
V_45 = F_46 ( V_37 , V_28 -> V_24 , V_34 ) ;
if ( V_45 ) {
F_38 ( V_28 -> V_25 ) ;
return V_45 ;
}
V_45 = F_47 ( V_28 -> V_24 , V_34 ) ;
if ( V_45 ) {
F_27 ( V_37 , V_28 -> V_24 , V_34 ) ;
F_38 ( V_28 -> V_25 ) ;
return V_45 ;
}
V_32 = F_18 ( V_28 ) ;
if ( ! V_32 ) {
F_27 ( V_37 , V_28 -> V_24 , V_34 ) ;
F_38 ( V_28 -> V_25 ) ;
return - V_43 ;
}
V_45 = F_48 ( & V_32 -> V_50 ) ;
F_37 ( & V_32 -> V_50 ) ;
if ( V_45 ) {
F_27 ( V_37 , V_28 -> V_24 , V_34 ) ;
F_38 ( V_28 -> V_25 ) ;
return V_45 ;
}
V_28 -> V_26 |= V_48 ;
return 0 ;
}
static int F_49 ( T_2 V_59 , struct V_11 * V_12 )
{
struct V_17 * V_18 ;
T_2 V_19 , * V_20 ;
int V_53 = 0 ;
int V_60 = 0 ;
int V_21 , V_45 ;
F_40 ( L_15 , V_59 ) ;
if ( V_59 == 0 )
return - V_43 ;
V_20 = V_12 -> V_14 ;
V_19 = * V_20 ++ ;
V_18 = (struct V_17 * ) V_20 ;
for ( V_21 = 0 ; V_21 < V_19 ; V_21 ++ ) {
if ( ! ( V_18 [ V_21 ] . V_26 & V_48 ) )
V_53 ++ ;
}
if ( V_53 < V_59 )
return - V_43 ;
for ( V_21 = 0 ; V_21 < V_19 && V_59 != V_60 ; V_21 ++ ) {
V_45 = F_42 ( & V_18 [ V_21 ] ) ;
if ( V_45 )
continue;
V_60 ++ ;
V_18 [ V_21 ] . V_54 = 1 ;
}
if ( V_60 != V_59 ) {
F_41 ( L_16 ) ;
for ( V_21 = 0 ; V_21 < V_19 ; V_21 ++ ) {
if ( ! V_18 [ V_21 ] . V_54 )
continue;
V_45 = F_35 ( & V_18 [ V_21 ] ) ;
if ( V_45 )
F_41 ( L_17 ,
F_16 ( V_18 [ V_21 ] . V_25 ) ) ;
}
V_45 = - V_43 ;
} else {
for ( V_21 = 0 ; V_21 < V_19 ; V_21 ++ ) {
if ( ! V_18 [ V_21 ] . V_54 )
continue;
F_40 ( L_18 ,
V_18 [ V_21 ] . V_24 , V_18 [ V_21 ] . V_25 ) ;
V_18 [ V_21 ] . V_54 = 0 ;
}
}
return V_45 ;
}
static int F_50 ( T_2 V_25 , struct V_11 * V_12 )
{
struct V_17 * V_18 ;
T_2 V_19 , * V_20 ;
int V_21 , V_55 ;
int V_45 ;
F_40 ( L_19 , V_25 ) ;
V_20 = V_12 -> V_14 ;
V_19 = * V_20 ++ ;
V_18 = (struct V_17 * ) V_20 ;
V_55 = 0 ;
for ( V_21 = 0 ; V_21 < V_19 ; V_21 ++ ) {
if ( V_18 [ V_21 ] . V_25 == V_25 ) {
V_55 = 1 ;
V_45 = F_42 ( & V_18 [ V_21 ] ) ;
break;
}
}
if ( ! V_55 )
V_45 = - V_43 ;
if ( V_45 )
F_40 ( L_20 , V_25 ) ;
else
F_40 ( L_18 ,
V_18 [ V_21 ] . V_24 , V_25 ) ;
return V_45 ;
}
static void F_51 ( struct V_1 * V_15 ,
struct V_11 * V_12 )
{
struct V_17 * V_18 ;
T_2 V_19 , * V_20 ;
int V_21 ;
V_20 = V_12 -> V_14 ;
V_19 = * V_20 ;
* V_20 = F_52 ( * V_20 ) ;
V_20 ++ ;
V_18 = (struct V_17 * ) V_20 ;
for ( V_21 = 0 ; V_21 < V_19 ; V_21 ++ ) {
V_18 [ V_21 ] . V_24 = F_53 ( V_18 [ V_21 ] . V_24 ) ;
V_18 [ V_21 ] . V_25 = F_52 ( V_18 [ V_21 ] . V_25 ) ;
V_18 [ V_21 ] . V_26 = F_52 ( V_18 [ V_21 ] . V_26 ) ;
}
V_61 = true ;
F_54 ( V_15 , V_12 ) ;
V_61 = false ;
}
int F_55 ( struct V_57 * V_58 )
{
struct V_1 * V_15 ;
struct V_11 * V_12 ;
T_2 V_62 , V_25 ;
int V_45 ;
V_62 = V_58 -> V_63 . V_64 ;
V_25 = V_58 -> V_63 . V_25 ;
F_24 () ;
V_15 = F_2 ( L_1 ) ;
if ( ! V_15 ) {
V_45 = - V_43 ;
goto V_65;
}
V_12 = F_11 ( V_15 ) ;
if ( ! V_12 ) {
V_45 = - V_43 ;
goto V_65;
}
switch ( V_58 -> V_66 ) {
case V_67 :
if ( V_58 -> V_68 == V_69 )
V_45 = F_49 ( V_62 , V_12 ) ;
else if ( V_58 -> V_68 == V_70 )
V_45 = F_50 ( V_25 , V_12 ) ;
else
V_45 = - V_43 ;
break;
case V_71 :
if ( V_58 -> V_68 == V_69 )
V_45 = F_39 ( V_62 , V_12 ) ;
else if ( V_58 -> V_68 == V_70 )
V_45 = F_43 ( V_25 , V_12 ) ;
else
V_45 = - V_43 ;
break;
default:
F_41 ( L_21 , V_58 -> V_66 ) ;
V_45 = - V_43 ;
break;
}
if ( V_45 )
F_9 ( V_12 ) ;
else
F_51 ( V_15 , V_12 ) ;
V_65:
F_5 ( V_15 ) ;
F_29 () ;
return V_45 ;
}
static int F_56 ( struct V_1 * V_2 )
{
const char * type ;
const T_3 * V_40 ;
unsigned long V_33 ;
unsigned int V_41 ;
int V_42 = - V_43 ;
type = F_3 ( V_2 , L_6 , NULL ) ;
if ( type == NULL || strcmp ( type , L_7 ) != 0 )
return 0 ;
V_40 = F_3 ( V_2 , L_8 , NULL ) ;
if ( ! V_40 )
return V_42 ;
V_33 = F_17 ( * ( unsigned long * ) V_40 ) ;
V_41 = F_16 ( V_40 [ 3 ] ) ;
V_42 = F_47 ( V_33 , V_41 ) ;
return ( V_42 < 0 ) ? - V_43 : 0 ;
}
static int F_57 ( struct V_72 * V_73 )
{
struct V_17 * V_74 , * V_75 ;
unsigned long V_3 ;
T_2 V_76 ;
T_3 * V_20 ;
int V_21 , V_45 = - V_43 ;
if ( V_61 )
return 0 ;
V_3 = F_1 () ;
if ( ! V_3 )
return - V_43 ;
V_20 = ( T_3 * ) V_73 -> V_77 -> V_14 ;
if ( ! V_20 )
return - V_43 ;
V_76 = F_16 ( * V_20 ++ ) ;
V_75 = (struct V_17 * ) V_20 ;
V_20 = ( T_3 * ) V_73 -> V_12 -> V_14 ;
V_20 ++ ;
V_74 = (struct V_17 * ) V_20 ;
for ( V_21 = 0 ; V_21 < V_76 ; V_21 ++ ) {
if ( ( F_16 ( V_75 [ V_21 ] . V_26 ) & V_48 ) &&
( ! ( F_16 ( V_74 [ V_21 ] . V_26 ) & V_48 ) ) ) {
V_45 = F_23 (
F_17 ( V_75 [ V_21 ] . V_24 ) ,
V_3 ) ;
break;
} else if ( ( ! ( F_16 ( V_75 [ V_21 ] . V_26 ) &
V_48 ) ) &&
( F_16 ( V_74 [ V_21 ] . V_26 ) &
V_48 ) ) {
V_45 = F_47 ( F_17 ( V_75 [ V_21 ] . V_24 ) ,
V_3 ) ;
V_45 = ( V_45 < 0 ) ? - V_43 : 0 ;
break;
}
}
return V_45 ;
}
static int F_58 ( struct V_78 * V_79 ,
unsigned long V_66 , void * V_80 )
{
struct V_72 * V_81 = V_80 ;
int V_82 = 0 ;
switch ( V_66 ) {
case V_83 :
V_82 = F_56 ( V_81 -> V_15 ) ;
break;
case V_84 :
V_82 = F_30 ( V_81 -> V_15 ) ;
break;
case V_85 :
if ( ! strcmp ( V_81 -> V_12 -> V_13 , L_5 ) )
V_82 = F_57 ( V_81 ) ;
break;
}
return F_59 ( V_82 ) ;
}
static int T_5 F_60 ( void )
{
if ( F_61 ( V_86 ) )
F_62 ( & V_87 ) ;
return 0 ;
}
