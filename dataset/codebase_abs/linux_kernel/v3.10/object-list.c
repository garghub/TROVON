void F_1 ( struct V_1 * V_2 )
{
struct V_1 * V_3 ;
struct V_4 * * V_5 = & V_6 . V_4 , * V_7 = NULL ;
F_2 ( & V_8 ) ;
while ( * V_5 ) {
V_7 = * V_5 ;
V_3 = F_3 ( V_7 , struct V_1 , V_9 ) ;
if ( V_2 < V_3 )
V_5 = & ( * V_5 ) -> V_10 ;
else if ( V_2 > V_3 )
V_5 = & ( * V_5 ) -> V_11 ;
else
F_4 () ;
}
F_5 ( & V_2 -> V_9 , V_7 , V_5 ) ;
F_6 ( & V_2 -> V_9 , & V_6 ) ;
F_7 ( & V_8 ) ;
}
void F_8 ( struct V_1 * V_2 )
{
F_2 ( & V_8 ) ;
F_9 ( F_10 ( & V_6 ) ) ;
F_11 ( & V_2 -> V_9 , & V_6 ) ;
F_7 ( & V_8 ) ;
}
static struct V_1 * F_12 ( T_1 * V_12 )
{
struct V_1 * V_13 , * V_2 = NULL , * V_14 = NULL ;
struct V_4 * V_5 ;
unsigned long V_15 ;
if ( * V_12 >= ( unsigned long ) F_13 ( - V_16 ) )
return NULL ;
V_15 = * V_12 ;
if ( V_15 == 0 )
return (struct V_1 * ) ( long ) ++ ( * V_12 ) ;
if ( V_15 < 3 )
return (struct V_1 * ) V_15 ;
V_13 = (struct V_1 * ) V_15 ;
V_5 = V_6 . V_4 ;
while ( V_5 ) {
V_2 = F_3 ( V_5 , struct V_1 , V_9 ) ;
if ( V_13 < V_2 ) {
if ( ! V_14 || V_14 > V_2 )
V_14 = V_2 ;
V_5 = V_5 -> V_10 ;
} else if ( V_13 > V_2 ) {
V_5 = V_5 -> V_11 ;
} else {
V_14 = V_2 ;
break;
}
V_2 = NULL ;
}
if ( ! V_14 )
* V_12 = ( unsigned long ) F_13 ( - V_16 ) ;
else if ( V_14 != V_2 )
* V_12 = ( unsigned long ) V_14 ;
return V_14 ;
}
static void * F_14 ( struct V_17 * V_18 , T_1 * V_12 )
__acquires( &fscache_object_list_lock
static void * F_15 ( struct V_17 * V_18 , void * V_19 , T_1 * V_12 )
{
( * V_12 ) ++ ;
return F_12 ( V_12 ) ;
}
static void F_16 ( struct V_17 * V_18 , void * V_19 )
__releases( &fscache_object_list_lock
static int F_17 ( struct V_17 * V_18 , void * V_19 )
{
struct V_20 * V_21 = V_18 -> V_22 ;
struct V_1 * V_2 = V_19 ;
unsigned long V_23 = V_21 -> V_23 ;
T_2 V_24 , V_25 ;
char V_26 [ 3 ] , * type ;
bool V_27 ;
T_3 * V_28 = V_21 -> V_28 , * V_5 ;
if ( ( unsigned long ) V_19 == 1 ) {
F_18 ( V_18 , L_1
L_2
L_3 ) ;
if ( V_23 & ( V_29 |
V_30 ) )
F_18 ( V_18 , L_4 ) ;
if ( V_23 & V_29 )
F_18 ( V_18 , L_5 ) ;
if ( ( V_23 & ( V_29 |
V_30 ) ) ==
( V_29 | V_30 ) )
F_18 ( V_18 , L_6 ) ;
if ( V_23 & V_30 )
F_18 ( V_18 , L_7 ) ;
F_18 ( V_18 , L_8 ) ;
return 0 ;
}
if ( ( unsigned long ) V_19 == 2 ) {
F_18 ( V_18 , L_9
L_10
L_11 ) ;
if ( V_23 & ( V_29 |
V_30 ) )
F_18 ( V_18 , L_12 ) ;
F_18 ( V_18 , L_8 ) ;
return 0 ;
}
#define F_19 ( T_4 , T_5 , T_6 ) \
do { \
unsigned long yes = FSCACHE_OBJLIST_CONFIG_##_yes; \
unsigned long no = FSCACHE_OBJLIST_CONFIG_##_no; \
if (criterion) { \
if (!(config & yes)) \
return 0; \
} else { \
if (!(config & no)) \
return 0; \
} \
} while(0)
if ( ~ V_23 ) {
F_19 ( V_2 -> V_31 ,
V_32 , V_33 ) ;
F_19 ( V_2 -> V_34 != V_35 ||
V_2 -> V_36 != 0 ||
V_2 -> V_37 != 0 ||
V_2 -> V_38 ||
! F_20 ( & V_2 -> V_39 ) ,
V_40 , V_41 ) ;
F_19 ( F_21 ( V_42 , & V_2 -> V_38 ) ,
V_43 , V_44 ) ;
F_19 ( F_22 ( & V_2 -> V_45 ) ,
V_46 , V_47 ) ;
F_19 ( V_2 -> V_48 & V_2 -> V_49 ,
V_50 , V_51 ) ;
F_19 ( F_23 ( & V_2 -> V_52 ) , V_53 , V_54 ) ;
}
F_24 ( V_18 ,
L_13 ,
V_2 -> V_55 ,
V_2 -> V_7 ? V_2 -> V_7 -> V_55 : - 1 ,
V_56 [ V_2 -> V_34 ] ,
V_2 -> V_57 ,
V_2 -> V_36 ,
V_2 -> V_37 ,
V_2 -> V_58 ,
V_2 -> V_59 ,
F_22 ( & V_2 -> V_45 ) ,
V_2 -> V_49 ,
V_2 -> V_48 ,
V_2 -> V_38 ,
F_23 ( & V_2 -> V_52 ) ) ;
V_27 = true ;
V_24 = V_25 = 0 ;
if ( V_2 -> V_31 ) {
F_25 ( & V_2 -> V_60 ) ;
if ( V_2 -> V_31 ) {
switch ( V_2 -> V_31 -> V_61 -> type ) {
case 0 :
type = L_14 ;
break;
case 1 :
type = L_15 ;
break;
default:
sprintf ( V_26 , L_16 ,
V_2 -> V_31 -> V_61 -> type ) ;
type = V_26 ;
break;
}
F_24 ( V_18 , L_17 ,
V_2 -> V_31 -> V_61 -> V_62 ,
type ,
V_2 -> V_31 -> V_38 ,
V_2 -> V_31 -> V_63 ) ;
if ( V_2 -> V_31 -> V_61 -> V_64 &&
V_23 & V_29 )
V_24 = V_2 -> V_31 -> V_61 -> V_64 (
V_2 -> V_31 -> V_63 ,
V_28 , 400 ) ;
if ( V_2 -> V_31 -> V_61 -> V_65 &&
V_23 & V_30 )
V_25 = V_2 -> V_31 -> V_61 -> V_65 (
V_2 -> V_31 -> V_63 ,
V_28 + V_24 , 512 - V_24 ) ;
V_27 = false ;
}
F_26 ( & V_2 -> V_60 ) ;
if ( ! V_27 && ( V_24 > 0 || V_25 > 0 ) ) {
F_24 ( V_18 , L_18 ) ;
for ( V_5 = V_28 ; V_24 > 0 ; V_24 -- )
F_24 ( V_18 , L_19 , * V_5 ++ ) ;
if ( V_25 > 0 ) {
if ( V_23 & V_29 )
F_24 ( V_18 , L_6 ) ;
for (; V_25 > 0 ; V_25 -- )
F_24 ( V_18 , L_19 , * V_5 ++ ) ;
}
}
}
if ( V_27 )
F_24 ( V_18 , L_20 ) ;
else
F_24 ( V_18 , L_8 ) ;
return 0 ;
}
static void F_27 ( struct V_20 * V_21 )
{
#ifdef F_28
struct V_66 * V_67 ;
unsigned long V_23 ;
struct V_68 * V_68 ;
const char * V_28 ;
int V_69 ;
V_68 = F_29 ( & V_70 , L_21 , NULL ) ;
if ( F_30 ( V_68 ) )
goto V_71;
V_23 = 0 ;
F_31 () ;
V_67 = V_68 -> V_72 . V_21 ;
V_28 = V_67 -> V_21 ;
for ( V_69 = V_67 -> V_73 - 1 ; V_69 >= 0 ; V_69 -- ) {
switch ( V_28 [ V_69 ] ) {
case 'K' : V_23 |= V_29 ; break;
case 'A' : V_23 |= V_30 ; break;
case 'C' : V_23 |= V_74 ; break;
case 'c' : V_23 |= V_75 ; break;
case 'B' : V_23 |= V_76 ; break;
case 'b' : V_23 |= V_77 ; break;
case 'W' : V_23 |= V_78 ; break;
case 'w' : V_23 |= V_79 ; break;
case 'R' : V_23 |= V_80 ; break;
case 'r' : V_23 |= V_81 ; break;
case 'S' : V_23 |= V_82 ; break;
case 's' : V_23 |= V_83 ; break;
}
}
F_32 () ;
F_33 ( V_68 ) ;
if ( ! ( V_23 & ( V_74 | V_75 ) ) )
V_23 |= V_74 | V_75 ;
if ( ! ( V_23 & ( V_76 | V_77 ) ) )
V_23 |= V_76 | V_77 ;
if ( ! ( V_23 & ( V_78 | V_79 ) ) )
V_23 |= V_78 | V_79 ;
if ( ! ( V_23 & ( V_80 | V_81 ) ) )
V_23 |= V_80 | V_81 ;
if ( ! ( V_23 & ( V_84 | V_85 ) ) )
V_23 |= V_84 | V_85 ;
if ( ! ( V_23 & ( V_82 | V_83 ) ) )
V_23 |= V_82 | V_83 ;
V_21 -> V_23 = V_23 ;
return;
V_71:
#endif
V_21 -> V_23 = V_86 ;
}
static int F_34 ( struct V_87 * V_87 , struct V_88 * V_88 )
{
struct V_20 * V_21 ;
struct V_17 * V_18 ;
int V_89 ;
V_89 = F_35 ( V_88 , & V_90 ) ;
if ( V_89 < 0 )
return V_89 ;
V_18 = V_88 -> V_91 ;
V_21 = F_36 ( sizeof( struct V_20 ) , V_92 ) ;
if ( ! V_21 ) {
F_37 ( V_87 , V_88 ) ;
return - V_93 ;
}
F_27 ( V_21 ) ;
V_18 -> V_22 = V_21 ;
return 0 ;
}
static int F_38 ( struct V_87 * V_87 , struct V_88 * V_88 )
{
struct V_17 * V_18 = V_88 -> V_91 ;
F_39 ( V_18 -> V_22 ) ;
V_18 -> V_22 = NULL ;
return F_37 ( V_87 , V_88 ) ;
}
