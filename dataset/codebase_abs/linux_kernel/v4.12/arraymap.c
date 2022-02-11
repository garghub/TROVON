static void F_1 ( struct V_1 * V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_4 . V_5 ; V_3 ++ )
F_2 ( V_2 -> V_6 [ V_3 ] ) ;
}
static int F_3 ( struct V_1 * V_2 )
{
void T_1 * V_7 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_4 . V_5 ; V_3 ++ ) {
V_7 = F_4 ( V_2 -> V_8 , 8 ,
V_9 | V_10 ) ;
if ( ! V_7 ) {
F_1 ( V_2 ) ;
return - V_11 ;
}
V_2 -> V_6 [ V_3 ] = V_7 ;
}
return 0 ;
}
static struct V_12 * F_5 ( union V_13 * V_14 )
{
bool V_15 = V_14 -> V_16 == V_17 ;
struct V_1 * V_2 ;
T_2 V_18 ;
T_3 V_8 ;
if ( V_14 -> V_5 == 0 || V_14 -> V_19 != 4 ||
V_14 -> V_20 == 0 || V_14 -> V_21 )
return F_6 ( - V_22 ) ;
if ( V_14 -> V_20 > V_23 )
return F_6 ( - V_24 ) ;
V_8 = F_7 ( V_14 -> V_20 , 8 ) ;
V_18 = sizeof( * V_2 ) ;
if ( V_15 )
V_18 += ( T_2 ) V_14 -> V_5 * sizeof( void * ) ;
else
V_18 += ( T_2 ) V_14 -> V_5 * V_8 ;
if ( V_18 >= V_25 - V_26 )
return F_6 ( - V_11 ) ;
V_2 = F_8 ( V_18 ) ;
if ( ! V_2 )
return F_6 ( - V_11 ) ;
V_2 -> V_4 . V_16 = V_14 -> V_16 ;
V_2 -> V_4 . V_19 = V_14 -> V_19 ;
V_2 -> V_4 . V_20 = V_14 -> V_20 ;
V_2 -> V_4 . V_5 = V_14 -> V_5 ;
V_2 -> V_4 . V_21 = V_14 -> V_21 ;
V_2 -> V_8 = V_8 ;
if ( ! V_15 )
goto V_27;
V_18 += ( T_2 ) V_14 -> V_5 * V_8 * F_9 () ;
if ( V_18 >= V_25 - V_26 ||
V_8 > V_28 || F_3 ( V_2 ) ) {
F_10 ( V_2 ) ;
return F_6 ( - V_11 ) ;
}
V_27:
V_2 -> V_4 . V_29 = F_7 ( V_18 , V_26 ) >> V_30 ;
return & V_2 -> V_4 ;
}
static void * F_11 ( struct V_12 * V_4 , void * V_31 )
{
struct V_1 * V_2 = F_12 ( V_4 , struct V_1 , V_4 ) ;
T_3 V_32 = * ( T_3 * ) V_31 ;
if ( F_13 ( V_32 >= V_2 -> V_4 . V_5 ) )
return NULL ;
return V_2 -> V_33 + V_2 -> V_8 * V_32 ;
}
static T_3 F_14 ( struct V_12 * V_4 , struct V_34 * V_35 )
{
struct V_34 * V_36 = V_35 ;
T_3 V_8 = F_7 ( V_4 -> V_20 , 8 ) ;
const int V_37 = V_38 ;
const int V_39 = V_40 ;
const int V_32 = V_41 ;
* V_36 ++ = F_15 ( V_42 , V_39 , F_16 ( struct V_1 , V_33 ) ) ;
* V_36 ++ = F_17 ( V_43 , V_37 , V_32 , 0 ) ;
* V_36 ++ = F_18 ( V_44 , V_37 , V_4 -> V_5 , 3 ) ;
if ( F_19 ( V_8 ) ) {
* V_36 ++ = F_15 ( V_45 , V_37 , F_20 ( V_8 ) ) ;
} else {
* V_36 ++ = F_15 ( V_46 , V_37 , V_8 ) ;
}
* V_36 ++ = F_21 ( V_42 , V_37 , V_39 ) ;
* V_36 ++ = F_18 ( V_47 , 0 , 0 , 1 ) ;
* V_36 ++ = F_22 ( V_37 , 0 ) ;
return V_36 - V_35 ;
}
static void * F_23 ( struct V_12 * V_4 , void * V_31 )
{
struct V_1 * V_2 = F_12 ( V_4 , struct V_1 , V_4 ) ;
T_3 V_32 = * ( T_3 * ) V_31 ;
if ( F_13 ( V_32 >= V_2 -> V_4 . V_5 ) )
return NULL ;
return F_24 ( V_2 -> V_6 [ V_32 ] ) ;
}
int F_25 ( struct V_12 * V_4 , void * V_31 , void * V_33 )
{
struct V_1 * V_2 = F_12 ( V_4 , struct V_1 , V_4 ) ;
T_3 V_32 = * ( T_3 * ) V_31 ;
void T_1 * V_48 ;
int V_49 , V_50 = 0 ;
T_3 V_51 ;
if ( F_13 ( V_32 >= V_2 -> V_4 . V_5 ) )
return - V_52 ;
V_51 = F_7 ( V_4 -> V_20 , 8 ) ;
F_26 () ;
V_48 = V_2 -> V_6 [ V_32 ] ;
F_27 (cpu) {
F_28 ( V_33 + V_50 , F_29 ( V_48 , V_49 ) , V_51 ) ;
V_50 += V_51 ;
}
F_30 () ;
return 0 ;
}
static int F_31 ( struct V_12 * V_4 , void * V_31 , void * V_53 )
{
struct V_1 * V_2 = F_12 ( V_4 , struct V_1 , V_4 ) ;
T_3 V_32 = V_31 ? * ( T_3 * ) V_31 : V_25 ;
T_3 * V_54 = ( T_3 * ) V_53 ;
if ( V_32 >= V_2 -> V_4 . V_5 ) {
* V_54 = 0 ;
return 0 ;
}
if ( V_32 == V_2 -> V_4 . V_5 - 1 )
return - V_52 ;
* V_54 = V_32 + 1 ;
return 0 ;
}
static int F_32 ( struct V_12 * V_4 , void * V_31 , void * V_33 ,
T_2 V_21 )
{
struct V_1 * V_2 = F_12 ( V_4 , struct V_1 , V_4 ) ;
T_3 V_32 = * ( T_3 * ) V_31 ;
if ( F_13 ( V_21 > V_55 ) )
return - V_22 ;
if ( F_13 ( V_32 >= V_2 -> V_4 . V_5 ) )
return - V_24 ;
if ( F_13 ( V_21 == V_56 ) )
return - V_57 ;
if ( V_2 -> V_4 . V_16 == V_17 )
memcpy ( F_24 ( V_2 -> V_6 [ V_32 ] ) ,
V_33 , V_4 -> V_20 ) ;
else
memcpy ( V_2 -> V_33 + V_2 -> V_8 * V_32 ,
V_33 , V_4 -> V_20 ) ;
return 0 ;
}
int F_33 ( struct V_12 * V_4 , void * V_31 , void * V_33 ,
T_2 V_21 )
{
struct V_1 * V_2 = F_12 ( V_4 , struct V_1 , V_4 ) ;
T_3 V_32 = * ( T_3 * ) V_31 ;
void T_1 * V_48 ;
int V_49 , V_50 = 0 ;
T_3 V_51 ;
if ( F_13 ( V_21 > V_55 ) )
return - V_22 ;
if ( F_13 ( V_32 >= V_2 -> V_4 . V_5 ) )
return - V_24 ;
if ( F_13 ( V_21 == V_56 ) )
return - V_57 ;
V_51 = F_7 ( V_4 -> V_20 , 8 ) ;
F_26 () ;
V_48 = V_2 -> V_6 [ V_32 ] ;
F_27 (cpu) {
F_28 ( F_29 ( V_48 , V_49 ) , V_33 + V_50 , V_51 ) ;
V_50 += V_51 ;
}
F_30 () ;
return 0 ;
}
static int F_34 ( struct V_12 * V_4 , void * V_31 )
{
return - V_22 ;
}
static void F_35 ( struct V_12 * V_4 )
{
struct V_1 * V_2 = F_12 ( V_4 , struct V_1 , V_4 ) ;
F_36 () ;
if ( V_2 -> V_4 . V_16 == V_17 )
F_1 ( V_2 ) ;
F_10 ( V_2 ) ;
}
static struct V_12 * F_37 ( union V_13 * V_14 )
{
if ( V_14 -> V_20 != sizeof( T_3 ) )
return F_6 ( - V_22 ) ;
return F_5 ( V_14 ) ;
}
static void F_38 ( struct V_12 * V_4 )
{
struct V_1 * V_2 = F_12 ( V_4 , struct V_1 , V_4 ) ;
int V_3 ;
F_36 () ;
for ( V_3 = 0 ; V_3 < V_2 -> V_4 . V_5 ; V_3 ++ )
F_39 ( V_2 -> V_58 [ V_3 ] != NULL ) ;
F_10 ( V_2 ) ;
}
static void * F_40 ( struct V_12 * V_4 , void * V_31 )
{
return NULL ;
}
int F_41 ( struct V_12 * V_4 , struct V_59 * V_60 ,
void * V_31 , void * V_33 , T_2 V_21 )
{
struct V_1 * V_2 = F_12 ( V_4 , struct V_1 , V_4 ) ;
void * V_61 , * V_62 ;
T_3 V_32 = * ( T_3 * ) V_31 , V_63 ;
if ( V_21 != V_64 )
return - V_22 ;
if ( V_32 >= V_2 -> V_4 . V_5 )
return - V_24 ;
V_63 = * ( T_3 * ) V_33 ;
V_61 = V_4 -> V_65 -> V_66 ( V_4 , V_60 , V_63 ) ;
if ( F_42 ( V_61 ) )
return F_43 ( V_61 ) ;
V_62 = F_44 ( V_2 -> V_58 + V_32 , V_61 ) ;
if ( V_62 )
V_4 -> V_65 -> V_67 ( V_62 ) ;
return 0 ;
}
static int F_45 ( struct V_12 * V_4 , void * V_31 )
{
struct V_1 * V_2 = F_12 ( V_4 , struct V_1 , V_4 ) ;
void * V_62 ;
T_3 V_32 = * ( T_3 * ) V_31 ;
if ( V_32 >= V_2 -> V_4 . V_5 )
return - V_24 ;
V_62 = F_44 ( V_2 -> V_58 + V_32 , NULL ) ;
if ( V_62 ) {
V_4 -> V_65 -> V_67 ( V_62 ) ;
return 0 ;
} else {
return - V_52 ;
}
}
static void * F_46 ( struct V_12 * V_4 ,
struct V_59 * V_60 , int V_68 )
{
struct V_1 * V_2 = F_12 ( V_4 , struct V_1 , V_4 ) ;
struct V_69 * V_70 = F_47 ( V_68 ) ;
if ( F_42 ( V_70 ) )
return V_70 ;
if ( ! F_48 ( V_2 , V_70 ) ) {
F_49 ( V_70 ) ;
return F_6 ( - V_22 ) ;
}
return V_70 ;
}
static void F_50 ( void * V_7 )
{
F_49 ( V_7 ) ;
}
void F_51 ( struct V_12 * V_4 )
{
struct V_1 * V_2 = F_12 ( V_4 , struct V_1 , V_4 ) ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_4 . V_5 ; V_3 ++ )
F_45 ( V_4 , & V_3 ) ;
}
static struct V_71 * F_52 ( struct V_59 * V_72 ,
struct V_59 * V_60 )
{
struct V_71 * V_73 ;
V_73 = F_53 ( sizeof( * V_73 ) , V_74 ) ;
if ( V_73 ) {
V_73 -> V_75 = V_72 -> V_76 ;
V_73 -> V_72 = V_72 ;
V_73 -> V_60 = V_60 ;
}
return V_73 ;
}
static void F_54 ( struct V_77 * V_78 )
{
struct V_71 * V_73 ;
V_73 = F_12 ( V_78 , struct V_71 , V_78 ) ;
F_55 ( V_73 -> V_72 ) ;
F_56 ( V_73 ) ;
}
static void F_57 ( struct V_71 * V_73 )
{
F_58 ( & V_73 -> V_78 , F_54 ) ;
}
static void * F_59 ( struct V_12 * V_4 ,
struct V_59 * V_60 , int V_68 )
{
const struct V_79 * V_14 ;
struct V_71 * V_73 ;
struct V_80 * V_75 ;
struct V_59 * V_72 ;
V_72 = F_60 ( V_68 ) ;
if ( F_42 ( V_72 ) )
return V_72 ;
V_75 = V_72 -> V_76 ;
V_73 = F_6 ( - V_22 ) ;
V_14 = F_61 ( V_75 ) ;
if ( F_42 ( V_14 ) || V_14 -> V_81 )
goto V_82;
switch ( V_14 -> type ) {
case V_83 :
if ( V_14 -> V_84 != V_85 )
goto V_82;
case V_86 :
case V_87 :
V_73 = F_52 ( V_72 , V_60 ) ;
if ( V_73 )
return V_73 ;
V_73 = F_6 ( - V_11 ) ;
default:
break;
}
V_82:
F_55 ( V_72 ) ;
return V_73 ;
}
static void F_62 ( void * V_7 )
{
F_57 ( V_7 ) ;
}
static void F_63 ( struct V_12 * V_4 ,
struct V_59 * V_60 )
{
struct V_1 * V_2 = F_12 ( V_4 , struct V_1 , V_4 ) ;
struct V_71 * V_73 ;
int V_3 ;
F_26 () ;
for ( V_3 = 0 ; V_3 < V_2 -> V_4 . V_5 ; V_3 ++ ) {
V_73 = F_64 ( V_2 -> V_58 [ V_3 ] ) ;
if ( V_73 && V_73 -> V_60 == V_60 )
F_45 ( V_4 , & V_3 ) ;
}
F_30 () ;
}
static void * F_65 ( struct V_12 * V_4 ,
struct V_59 * V_60 ,
int V_68 )
{
return F_66 ( V_68 ) ;
}
static void F_67 ( void * V_7 )
{
F_68 ( V_7 ) ;
}
static void F_69 ( struct V_12 * V_4 )
{
F_51 ( V_4 ) ;
F_38 ( V_4 ) ;
}
static struct V_12 * F_70 ( union V_13 * V_14 )
{
struct V_12 * V_4 , * V_88 ;
V_88 = F_71 ( V_14 -> V_89 ) ;
if ( F_42 ( V_88 ) )
return V_88 ;
V_4 = F_37 ( V_14 ) ;
if ( F_42 ( V_4 ) ) {
F_72 ( V_88 ) ;
return V_4 ;
}
V_4 -> V_88 = V_88 ;
return V_4 ;
}
static void F_73 ( struct V_12 * V_4 )
{
F_72 ( V_4 -> V_88 ) ;
F_51 ( V_4 ) ;
F_38 ( V_4 ) ;
}
static void * F_74 ( struct V_12 * V_4 , void * V_31 )
{
struct V_12 * * V_90 = F_11 ( V_4 , V_31 ) ;
if ( ! V_90 )
return NULL ;
return F_64 ( * V_90 ) ;
}
