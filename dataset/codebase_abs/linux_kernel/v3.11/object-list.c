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
struct V_23 * V_24 ;
unsigned long V_25 = V_21 -> V_25 ;
char V_26 [ 3 ] , * type ;
T_2 * V_27 = V_21 -> V_27 , * V_5 ;
if ( ( unsigned long ) V_19 == 1 ) {
F_18 ( V_18 , L_1
L_2
L_3 ) ;
if ( V_25 & ( V_28 |
V_29 ) )
F_18 ( V_18 , L_4 ) ;
if ( V_25 & V_28 )
F_18 ( V_18 , L_5 ) ;
if ( ( V_25 & ( V_28 |
V_29 ) ) ==
( V_28 | V_29 ) )
F_18 ( V_18 , L_6 ) ;
if ( V_25 & V_29 )
F_18 ( V_18 , L_7 ) ;
F_18 ( V_18 , L_8 ) ;
return 0 ;
}
if ( ( unsigned long ) V_19 == 2 ) {
F_18 ( V_18 , L_9
L_10
L_11 ) ;
if ( V_25 & ( V_28 |
V_29 ) )
F_18 ( V_18 , L_12 ) ;
F_18 ( V_18 , L_8 ) ;
return 0 ;
}
#define F_19 ( T_3 , T_4 , T_5 ) \
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
V_24 = V_2 -> V_24 ;
if ( ~ V_25 ) {
F_19 ( V_24 -> V_30 ,
V_31 , V_32 ) ;
F_19 ( F_20 ( V_2 ) ||
V_2 -> V_33 != 0 ||
V_2 -> V_34 != 0 ||
V_2 -> V_35 ||
! F_21 ( & V_2 -> V_36 ) ,
V_37 , V_38 ) ;
F_19 ( F_22 ( V_39 , & V_2 -> V_35 ) ,
V_40 , V_41 ) ;
F_19 ( F_23 ( & V_2 -> V_42 ) ,
V_43 , V_44 ) ;
F_19 ( V_2 -> V_45 & V_2 -> V_46 ,
V_47 , V_48 ) ;
F_19 ( F_24 ( & V_2 -> V_49 ) , V_50 , V_51 ) ;
}
F_25 ( V_18 ,
L_13 ,
V_2 -> V_52 ,
V_2 -> V_7 ? V_2 -> V_7 -> V_52 : - 1 ,
V_2 -> V_53 -> V_54 ,
V_2 -> V_55 ,
V_2 -> V_33 ,
V_2 -> V_34 ,
V_2 -> V_56 ,
V_2 -> V_57 ,
F_23 ( & V_2 -> V_42 ) ,
V_2 -> V_46 ,
V_2 -> V_45 ,
V_2 -> V_35 ,
F_24 ( & V_2 -> V_49 ) ) ;
if ( F_26 ( V_2 ) ) {
T_6 V_58 = 0 , V_59 = 0 ;
switch ( V_24 -> V_30 -> type ) {
case 0 :
type = L_14 ;
break;
case 1 :
type = L_15 ;
break;
default:
sprintf ( V_26 , L_16 , V_24 -> V_30 -> type ) ;
type = V_26 ;
break;
}
F_25 ( V_18 , L_17 ,
V_24 -> V_30 -> V_60 ,
type ,
V_24 -> V_35 ,
V_24 -> V_61 ) ;
if ( V_24 -> V_30 -> V_62 &&
V_25 & V_28 )
V_58 = V_24 -> V_30 -> V_62 ( V_24 -> V_61 ,
V_27 , 400 ) ;
if ( V_24 -> V_30 -> V_63 &&
V_25 & V_29 )
V_59 = V_24 -> V_30 -> V_63 ( V_24 -> V_61 ,
V_27 + V_58 , 512 - V_58 ) ;
F_27 ( V_2 ) ;
if ( V_58 > 0 || V_59 > 0 ) {
F_25 ( V_18 , L_18 ) ;
for ( V_5 = V_27 ; V_58 > 0 ; V_58 -- )
F_25 ( V_18 , L_19 , * V_5 ++ ) ;
if ( V_59 > 0 ) {
if ( V_25 & V_28 )
F_25 ( V_18 , L_6 ) ;
for (; V_59 > 0 ; V_59 -- )
F_25 ( V_18 , L_19 , * V_5 ++ ) ;
}
}
F_25 ( V_18 , L_8 ) ;
} else {
F_25 ( V_18 , L_20 ) ;
}
return 0 ;
}
static void F_28 ( struct V_20 * V_21 )
{
#ifdef F_29
struct V_64 * V_65 ;
unsigned long V_25 ;
struct V_66 * V_66 ;
const char * V_27 ;
int V_67 ;
V_66 = F_30 ( & V_68 , L_21 , NULL ) ;
if ( F_31 ( V_66 ) )
goto V_69;
V_25 = 0 ;
F_32 () ;
V_65 = V_66 -> V_70 . V_21 ;
V_27 = V_65 -> V_21 ;
for ( V_67 = V_65 -> V_71 - 1 ; V_67 >= 0 ; V_67 -- ) {
switch ( V_27 [ V_67 ] ) {
case 'K' : V_25 |= V_28 ; break;
case 'A' : V_25 |= V_29 ; break;
case 'C' : V_25 |= V_72 ; break;
case 'c' : V_25 |= V_73 ; break;
case 'B' : V_25 |= V_74 ; break;
case 'b' : V_25 |= V_75 ; break;
case 'W' : V_25 |= V_76 ; break;
case 'w' : V_25 |= V_77 ; break;
case 'R' : V_25 |= V_78 ; break;
case 'r' : V_25 |= V_79 ; break;
case 'S' : V_25 |= V_80 ; break;
case 's' : V_25 |= V_81 ; break;
}
}
F_33 () ;
F_34 ( V_66 ) ;
if ( ! ( V_25 & ( V_72 | V_73 ) ) )
V_25 |= V_72 | V_73 ;
if ( ! ( V_25 & ( V_74 | V_75 ) ) )
V_25 |= V_74 | V_75 ;
if ( ! ( V_25 & ( V_76 | V_77 ) ) )
V_25 |= V_76 | V_77 ;
if ( ! ( V_25 & ( V_78 | V_79 ) ) )
V_25 |= V_78 | V_79 ;
if ( ! ( V_25 & ( V_82 | V_83 ) ) )
V_25 |= V_82 | V_83 ;
if ( ! ( V_25 & ( V_80 | V_81 ) ) )
V_25 |= V_80 | V_81 ;
V_21 -> V_25 = V_25 ;
return;
V_69:
#endif
V_21 -> V_25 = V_84 ;
}
static int F_35 ( struct V_85 * V_85 , struct V_86 * V_86 )
{
struct V_20 * V_21 ;
struct V_17 * V_18 ;
int V_87 ;
V_87 = F_36 ( V_86 , & V_88 ) ;
if ( V_87 < 0 )
return V_87 ;
V_18 = V_86 -> V_89 ;
V_21 = F_37 ( sizeof( struct V_20 ) , V_90 ) ;
if ( ! V_21 ) {
F_38 ( V_85 , V_86 ) ;
return - V_91 ;
}
F_28 ( V_21 ) ;
V_18 -> V_22 = V_21 ;
return 0 ;
}
static int F_39 ( struct V_85 * V_85 , struct V_86 * V_86 )
{
struct V_17 * V_18 = V_86 -> V_89 ;
F_40 ( V_18 -> V_22 ) ;
V_18 -> V_22 = NULL ;
return F_38 ( V_85 , V_86 ) ;
}
