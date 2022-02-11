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
int V_18 = F_6 ( V_14 ) ;
struct V_1 * V_2 ;
T_2 V_19 ;
T_3 V_8 ;
if ( V_14 -> V_5 == 0 || V_14 -> V_20 != 4 ||
V_14 -> V_21 == 0 || V_14 -> V_22 & ~ V_23 ||
( V_15 && V_18 != V_24 ) )
return F_7 ( - V_25 ) ;
if ( V_14 -> V_21 > V_26 )
return F_7 ( - V_27 ) ;
V_8 = F_8 ( V_14 -> V_21 , 8 ) ;
V_19 = sizeof( * V_2 ) ;
if ( V_15 )
V_19 += ( T_2 ) V_14 -> V_5 * sizeof( void * ) ;
else
V_19 += ( T_2 ) V_14 -> V_5 * V_8 ;
if ( V_19 >= V_28 - V_29 )
return F_7 ( - V_11 ) ;
V_2 = F_9 ( V_19 , V_18 ) ;
if ( ! V_2 )
return F_7 ( - V_11 ) ;
V_2 -> V_4 . V_16 = V_14 -> V_16 ;
V_2 -> V_4 . V_20 = V_14 -> V_20 ;
V_2 -> V_4 . V_21 = V_14 -> V_21 ;
V_2 -> V_4 . V_5 = V_14 -> V_5 ;
V_2 -> V_4 . V_22 = V_14 -> V_22 ;
V_2 -> V_4 . V_18 = V_18 ;
V_2 -> V_8 = V_8 ;
if ( ! V_15 )
goto V_30;
V_19 += ( T_2 ) V_14 -> V_5 * V_8 * F_10 () ;
if ( V_19 >= V_28 - V_29 ||
F_3 ( V_2 ) ) {
F_11 ( V_2 ) ;
return F_7 ( - V_11 ) ;
}
V_30:
V_2 -> V_4 . V_31 = F_8 ( V_19 , V_29 ) >> V_32 ;
return & V_2 -> V_4 ;
}
static void * F_12 ( struct V_12 * V_4 , void * V_33 )
{
struct V_1 * V_2 = F_13 ( V_4 , struct V_1 , V_4 ) ;
T_3 V_34 = * ( T_3 * ) V_33 ;
if ( F_14 ( V_34 >= V_2 -> V_4 . V_5 ) )
return NULL ;
return V_2 -> V_35 + V_2 -> V_8 * V_34 ;
}
static T_3 F_15 ( struct V_12 * V_4 , struct V_36 * V_37 )
{
struct V_36 * V_38 = V_37 ;
T_3 V_8 = F_8 ( V_4 -> V_21 , 8 ) ;
const int V_39 = V_40 ;
const int V_41 = V_42 ;
const int V_34 = V_43 ;
* V_38 ++ = F_16 ( V_44 , V_41 , F_17 ( struct V_1 , V_35 ) ) ;
* V_38 ++ = F_18 ( V_45 , V_39 , V_34 , 0 ) ;
* V_38 ++ = F_19 ( V_46 , V_39 , V_4 -> V_5 , 3 ) ;
if ( F_20 ( V_8 ) ) {
* V_38 ++ = F_16 ( V_47 , V_39 , F_21 ( V_8 ) ) ;
} else {
* V_38 ++ = F_16 ( V_48 , V_39 , V_8 ) ;
}
* V_38 ++ = F_22 ( V_44 , V_39 , V_41 ) ;
* V_38 ++ = F_19 ( V_49 , 0 , 0 , 1 ) ;
* V_38 ++ = F_23 ( V_39 , 0 ) ;
return V_38 - V_37 ;
}
static void * F_24 ( struct V_12 * V_4 , void * V_33 )
{
struct V_1 * V_2 = F_13 ( V_4 , struct V_1 , V_4 ) ;
T_3 V_34 = * ( T_3 * ) V_33 ;
if ( F_14 ( V_34 >= V_2 -> V_4 . V_5 ) )
return NULL ;
return F_25 ( V_2 -> V_6 [ V_34 ] ) ;
}
int F_26 ( struct V_12 * V_4 , void * V_33 , void * V_35 )
{
struct V_1 * V_2 = F_13 ( V_4 , struct V_1 , V_4 ) ;
T_3 V_34 = * ( T_3 * ) V_33 ;
void T_1 * V_50 ;
int V_51 , V_52 = 0 ;
T_3 V_53 ;
if ( F_14 ( V_34 >= V_2 -> V_4 . V_5 ) )
return - V_54 ;
V_53 = F_8 ( V_4 -> V_21 , 8 ) ;
F_27 () ;
V_50 = V_2 -> V_6 [ V_34 ] ;
F_28 (cpu) {
F_29 ( V_35 + V_52 , F_30 ( V_50 , V_51 ) , V_53 ) ;
V_52 += V_53 ;
}
F_31 () ;
return 0 ;
}
static int F_32 ( struct V_12 * V_4 , void * V_33 , void * V_55 )
{
struct V_1 * V_2 = F_13 ( V_4 , struct V_1 , V_4 ) ;
T_3 V_34 = V_33 ? * ( T_3 * ) V_33 : V_28 ;
T_3 * V_56 = ( T_3 * ) V_55 ;
if ( V_34 >= V_2 -> V_4 . V_5 ) {
* V_56 = 0 ;
return 0 ;
}
if ( V_34 == V_2 -> V_4 . V_5 - 1 )
return - V_54 ;
* V_56 = V_34 + 1 ;
return 0 ;
}
static int F_33 ( struct V_12 * V_4 , void * V_33 , void * V_35 ,
T_2 V_22 )
{
struct V_1 * V_2 = F_13 ( V_4 , struct V_1 , V_4 ) ;
T_3 V_34 = * ( T_3 * ) V_33 ;
if ( F_14 ( V_22 > V_57 ) )
return - V_25 ;
if ( F_14 ( V_34 >= V_2 -> V_4 . V_5 ) )
return - V_27 ;
if ( F_14 ( V_22 == V_58 ) )
return - V_59 ;
if ( V_2 -> V_4 . V_16 == V_17 )
memcpy ( F_25 ( V_2 -> V_6 [ V_34 ] ) ,
V_35 , V_4 -> V_21 ) ;
else
memcpy ( V_2 -> V_35 + V_2 -> V_8 * V_34 ,
V_35 , V_4 -> V_21 ) ;
return 0 ;
}
int F_34 ( struct V_12 * V_4 , void * V_33 , void * V_35 ,
T_2 V_22 )
{
struct V_1 * V_2 = F_13 ( V_4 , struct V_1 , V_4 ) ;
T_3 V_34 = * ( T_3 * ) V_33 ;
void T_1 * V_50 ;
int V_51 , V_52 = 0 ;
T_3 V_53 ;
if ( F_14 ( V_22 > V_57 ) )
return - V_25 ;
if ( F_14 ( V_34 >= V_2 -> V_4 . V_5 ) )
return - V_27 ;
if ( F_14 ( V_22 == V_58 ) )
return - V_59 ;
V_53 = F_8 ( V_4 -> V_21 , 8 ) ;
F_27 () ;
V_50 = V_2 -> V_6 [ V_34 ] ;
F_28 (cpu) {
F_29 ( F_30 ( V_50 , V_51 ) , V_35 + V_52 , V_53 ) ;
V_52 += V_53 ;
}
F_31 () ;
return 0 ;
}
static int F_35 ( struct V_12 * V_4 , void * V_33 )
{
return - V_25 ;
}
static void F_36 ( struct V_12 * V_4 )
{
struct V_1 * V_2 = F_13 ( V_4 , struct V_1 , V_4 ) ;
F_37 () ;
if ( V_2 -> V_4 . V_16 == V_17 )
F_1 ( V_2 ) ;
F_11 ( V_2 ) ;
}
static struct V_12 * F_38 ( union V_13 * V_14 )
{
if ( V_14 -> V_21 != sizeof( T_3 ) )
return F_7 ( - V_25 ) ;
return F_5 ( V_14 ) ;
}
static void F_39 ( struct V_12 * V_4 )
{
struct V_1 * V_2 = F_13 ( V_4 , struct V_1 , V_4 ) ;
int V_3 ;
F_37 () ;
for ( V_3 = 0 ; V_3 < V_2 -> V_4 . V_5 ; V_3 ++ )
F_40 ( V_2 -> V_60 [ V_3 ] != NULL ) ;
F_11 ( V_2 ) ;
}
static void * F_41 ( struct V_12 * V_4 , void * V_33 )
{
return NULL ;
}
int F_42 ( struct V_12 * V_4 , void * V_33 , T_3 * V_35 )
{
void * * V_61 , * V_7 ;
int V_39 = 0 ;
if ( ! V_4 -> V_62 -> V_63 )
return - V_64 ;
F_27 () ;
V_61 = F_12 ( V_4 , V_33 ) ;
if ( V_61 && ( V_7 = F_43 ( * V_61 ) ) )
* V_35 = V_4 -> V_62 -> V_63 ( V_7 ) ;
else
V_39 = - V_54 ;
F_31 () ;
return V_39 ;
}
int F_44 ( struct V_12 * V_4 , struct V_65 * V_66 ,
void * V_33 , void * V_35 , T_2 V_22 )
{
struct V_1 * V_2 = F_13 ( V_4 , struct V_1 , V_4 ) ;
void * V_67 , * V_68 ;
T_3 V_34 = * ( T_3 * ) V_33 , V_69 ;
if ( V_22 != V_70 )
return - V_25 ;
if ( V_34 >= V_2 -> V_4 . V_5 )
return - V_27 ;
V_69 = * ( T_3 * ) V_35 ;
V_67 = V_4 -> V_62 -> V_71 ( V_4 , V_66 , V_69 ) ;
if ( F_45 ( V_67 ) )
return F_46 ( V_67 ) ;
V_68 = F_47 ( V_2 -> V_60 + V_34 , V_67 ) ;
if ( V_68 )
V_4 -> V_62 -> V_72 ( V_68 ) ;
return 0 ;
}
static int F_48 ( struct V_12 * V_4 , void * V_33 )
{
struct V_1 * V_2 = F_13 ( V_4 , struct V_1 , V_4 ) ;
void * V_68 ;
T_3 V_34 = * ( T_3 * ) V_33 ;
if ( V_34 >= V_2 -> V_4 . V_5 )
return - V_27 ;
V_68 = F_47 ( V_2 -> V_60 + V_34 , NULL ) ;
if ( V_68 ) {
V_4 -> V_62 -> V_72 ( V_68 ) ;
return 0 ;
} else {
return - V_54 ;
}
}
static void * F_49 ( struct V_12 * V_4 ,
struct V_65 * V_66 , int V_73 )
{
struct V_1 * V_2 = F_13 ( V_4 , struct V_1 , V_4 ) ;
struct V_74 * V_75 = F_50 ( V_73 ) ;
if ( F_45 ( V_75 ) )
return V_75 ;
if ( ! F_51 ( V_2 , V_75 ) ) {
F_52 ( V_75 ) ;
return F_7 ( - V_25 ) ;
}
return V_75 ;
}
static void F_53 ( void * V_7 )
{
F_52 ( V_7 ) ;
}
static T_3 F_54 ( void * V_7 )
{
return ( (struct V_74 * ) V_7 ) -> V_76 -> V_77 ;
}
void F_55 ( struct V_12 * V_4 )
{
struct V_1 * V_2 = F_13 ( V_4 , struct V_1 , V_4 ) ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_4 . V_5 ; V_3 ++ )
F_48 ( V_4 , & V_3 ) ;
}
static struct V_78 * F_56 ( struct V_65 * V_79 ,
struct V_65 * V_66 )
{
struct V_78 * V_80 ;
V_80 = F_57 ( sizeof( * V_80 ) , V_81 ) ;
if ( V_80 ) {
V_80 -> V_82 = V_79 -> V_83 ;
V_80 -> V_79 = V_79 ;
V_80 -> V_66 = V_66 ;
}
return V_80 ;
}
static void F_58 ( struct V_84 * V_85 )
{
struct V_78 * V_80 ;
V_80 = F_13 ( V_85 , struct V_78 , V_85 ) ;
F_59 ( V_80 -> V_79 ) ;
F_60 ( V_80 ) ;
}
static void F_61 ( struct V_78 * V_80 )
{
F_62 ( & V_80 -> V_85 , F_58 ) ;
}
static void * F_63 ( struct V_12 * V_4 ,
struct V_65 * V_66 , int V_73 )
{
struct V_78 * V_80 ;
struct V_86 * V_82 ;
struct V_65 * V_79 ;
T_2 V_35 ;
V_79 = F_64 ( V_73 ) ;
if ( F_45 ( V_79 ) )
return V_79 ;
V_80 = F_7 ( - V_87 ) ;
V_82 = V_79 -> V_83 ;
if ( F_65 ( V_82 , & V_35 ) == - V_87 )
goto V_88;
V_80 = F_56 ( V_79 , V_66 ) ;
if ( V_80 )
return V_80 ;
V_80 = F_7 ( - V_11 ) ;
V_88:
F_59 ( V_79 ) ;
return V_80 ;
}
static void F_66 ( void * V_7 )
{
F_61 ( V_7 ) ;
}
static void F_67 ( struct V_12 * V_4 ,
struct V_65 * V_66 )
{
struct V_1 * V_2 = F_13 ( V_4 , struct V_1 , V_4 ) ;
struct V_78 * V_80 ;
int V_3 ;
F_27 () ;
for ( V_3 = 0 ; V_3 < V_2 -> V_4 . V_5 ; V_3 ++ ) {
V_80 = F_43 ( V_2 -> V_60 [ V_3 ] ) ;
if ( V_80 && V_80 -> V_66 == V_66 )
F_48 ( V_4 , & V_3 ) ;
}
F_31 () ;
}
static void * F_68 ( struct V_12 * V_4 ,
struct V_65 * V_66 ,
int V_73 )
{
return F_69 ( V_73 ) ;
}
static void F_70 ( void * V_7 )
{
F_71 ( V_7 ) ;
}
static void F_72 ( struct V_12 * V_4 )
{
F_55 ( V_4 ) ;
F_39 ( V_4 ) ;
}
static struct V_12 * F_73 ( union V_13 * V_14 )
{
struct V_12 * V_4 , * V_89 ;
V_89 = F_74 ( V_14 -> V_90 ) ;
if ( F_45 ( V_89 ) )
return V_89 ;
V_4 = F_38 ( V_14 ) ;
if ( F_45 ( V_4 ) ) {
F_75 ( V_89 ) ;
return V_4 ;
}
V_4 -> V_89 = V_89 ;
return V_4 ;
}
static void F_76 ( struct V_12 * V_4 )
{
F_75 ( V_4 -> V_89 ) ;
F_55 ( V_4 ) ;
F_39 ( V_4 ) ;
}
static void * F_77 ( struct V_12 * V_4 , void * V_33 )
{
struct V_12 * * V_91 = F_12 ( V_4 , V_33 ) ;
if ( ! V_91 )
return NULL ;
return F_43 ( * V_91 ) ;
}
static T_3 F_78 ( struct V_12 * V_4 ,
struct V_36 * V_37 )
{
T_3 V_8 = F_8 ( V_4 -> V_21 , 8 ) ;
struct V_36 * V_38 = V_37 ;
const int V_39 = V_40 ;
const int V_41 = V_42 ;
const int V_34 = V_43 ;
* V_38 ++ = F_16 ( V_44 , V_41 , F_17 ( struct V_1 , V_35 ) ) ;
* V_38 ++ = F_18 ( V_45 , V_39 , V_34 , 0 ) ;
* V_38 ++ = F_19 ( V_46 , V_39 , V_4 -> V_5 , 5 ) ;
if ( F_20 ( V_8 ) )
* V_38 ++ = F_16 ( V_47 , V_39 , F_21 ( V_8 ) ) ;
else
* V_38 ++ = F_16 ( V_48 , V_39 , V_8 ) ;
* V_38 ++ = F_22 ( V_44 , V_39 , V_41 ) ;
* V_38 ++ = F_18 ( V_92 , V_39 , V_39 , 0 ) ;
* V_38 ++ = F_19 ( V_93 , V_39 , 0 , 1 ) ;
* V_38 ++ = F_19 ( V_49 , 0 , 0 , 1 ) ;
* V_38 ++ = F_23 ( V_39 , 0 ) ;
return V_38 - V_37 ;
}
