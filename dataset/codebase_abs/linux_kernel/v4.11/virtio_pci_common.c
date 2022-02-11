void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 ;
if ( V_4 -> V_6 )
F_3 ( V_4 -> V_7 -> V_8 ) ;
for ( V_5 = 0 ; V_5 < V_4 -> V_9 ; ++ V_5 )
F_3 ( F_4 ( V_4 -> V_7 , V_5 ) ) ;
}
bool F_5 ( struct V_10 * V_11 )
{
F_6 ( V_11 -> V_12 , ( void V_13 * ) V_11 -> V_14 ) ;
return true ;
}
static T_1 F_7 ( int V_8 , void * V_15 )
{
struct V_3 * V_4 = V_15 ;
F_8 ( & V_4 -> V_2 ) ;
return V_16 ;
}
static T_1 F_9 ( int V_8 , void * V_15 )
{
struct V_3 * V_4 = V_15 ;
struct V_17 * V_18 ;
T_1 V_19 = V_20 ;
unsigned long V_21 ;
F_10 ( & V_4 -> V_22 , V_21 ) ;
F_11 (info, &vp_dev->virtqueues, node) {
if ( F_12 ( V_8 , V_18 -> V_11 ) == V_16 )
V_19 = V_16 ;
}
F_13 ( & V_4 -> V_22 , V_21 ) ;
return V_19 ;
}
static T_1 F_14 ( int V_8 , void * V_15 )
{
struct V_3 * V_4 = V_15 ;
T_2 V_23 ;
V_23 = F_15 ( V_4 -> V_23 ) ;
if ( ! V_23 )
return V_20 ;
if ( V_23 & V_24 )
F_7 ( V_8 , V_15 ) ;
return F_9 ( V_8 , V_15 ) ;
}
static int F_16 ( struct V_1 * V_2 , int V_25 ,
bool V_26 , struct V_27 * V_28 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const char * V_29 = F_17 ( & V_4 -> V_2 . V_30 ) ;
unsigned V_5 , V_31 ;
int V_32 = - V_33 ;
V_4 -> V_9 = V_25 ;
V_4 -> V_34 = F_18 ( V_25 * sizeof * V_4 -> V_34 ,
V_35 ) ;
if ( ! V_4 -> V_34 )
goto error;
V_4 -> V_36
= F_19 ( V_25 * sizeof * V_4 -> V_36 ,
V_35 ) ;
if ( ! V_4 -> V_36 )
goto error;
for ( V_5 = 0 ; V_5 < V_25 ; ++ V_5 )
if ( ! F_20 ( & V_4 -> V_36 [ V_5 ] ,
V_35 ) )
goto error;
V_32 = F_21 ( V_4 -> V_7 , V_25 ,
V_25 , V_37 |
( V_28 ? V_38 : 0 ) ,
V_28 ) ;
if ( V_32 < 0 )
goto error;
V_4 -> V_39 = 1 ;
V_31 = V_4 -> V_40 ;
snprintf ( V_4 -> V_34 [ V_31 ] , sizeof * V_4 -> V_34 ,
L_1 , V_29 ) ;
V_32 = F_22 ( F_4 ( V_4 -> V_7 , V_31 ) ,
F_7 , 0 , V_4 -> V_34 [ V_31 ] ,
V_4 ) ;
if ( V_32 )
goto error;
++ V_4 -> V_40 ;
V_31 = V_4 -> V_41 ( V_4 , V_31 ) ;
if ( V_31 == V_42 ) {
V_32 = - V_43 ;
goto error;
}
if ( ! V_26 ) {
V_31 = V_4 -> V_40 ;
snprintf ( V_4 -> V_34 [ V_31 ] , sizeof * V_4 -> V_34 ,
L_2 , V_29 ) ;
V_32 = F_22 ( F_4 ( V_4 -> V_7 , V_31 ) ,
F_9 , 0 , V_4 -> V_34 [ V_31 ] ,
V_4 ) ;
if ( V_32 )
goto error;
++ V_4 -> V_40 ;
}
return 0 ;
error:
return V_32 ;
}
static struct V_10 * F_23 ( struct V_1 * V_2 , unsigned V_12 ,
void (* F_24)( struct V_10 * V_11 ) ,
const char * V_29 ,
T_3 V_44 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_17 * V_18 = F_18 ( sizeof *V_18 , V_35 ) ;
struct V_10 * V_11 ;
unsigned long V_21 ;
if ( ! V_18 )
return F_25 ( - V_33 ) ;
V_11 = V_4 -> V_45 ( V_4 , V_18 , V_12 , F_24 , V_29 ,
V_44 ) ;
if ( F_26 ( V_11 ) )
goto V_46;
V_18 -> V_11 = V_11 ;
if ( F_24 ) {
F_10 ( & V_4 -> V_22 , V_21 ) ;
F_27 ( & V_18 -> V_47 , & V_4 -> V_48 ) ;
F_13 ( & V_4 -> V_22 , V_21 ) ;
} else {
F_28 ( & V_18 -> V_47 ) ;
}
V_4 -> V_49 [ V_12 ] = V_18 ;
return V_11 ;
V_46:
F_29 ( V_18 ) ;
return V_11 ;
}
static void F_30 ( struct V_10 * V_11 )
{
struct V_3 * V_4 = F_2 ( V_11 -> V_2 ) ;
struct V_17 * V_18 = V_4 -> V_49 [ V_11 -> V_12 ] ;
unsigned long V_21 ;
F_10 ( & V_4 -> V_22 , V_21 ) ;
F_31 ( & V_18 -> V_47 ) ;
F_13 ( & V_4 -> V_22 , V_21 ) ;
V_4 -> V_50 ( V_18 ) ;
F_29 ( V_18 ) ;
}
void F_32 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_10 * V_11 , * V_51 ;
int V_5 ;
F_33 (vq, n, &vdev->vqs, list) {
if ( V_4 -> V_26 ) {
int V_31 = V_4 -> V_49 [ V_11 -> V_12 ] -> V_52 ;
if ( V_31 != V_42 ) {
int V_8 = F_4 ( V_4 -> V_7 , V_31 ) ;
F_34 ( V_8 , NULL ) ;
F_35 ( V_8 , V_11 ) ;
}
}
F_30 ( V_11 ) ;
}
V_4 -> V_26 = false ;
if ( V_4 -> V_6 ) {
F_35 ( V_4 -> V_7 -> V_8 , V_4 ) ;
V_4 -> V_6 = 0 ;
}
for ( V_5 = 0 ; V_5 < V_4 -> V_40 ; ++ V_5 )
F_35 ( F_4 ( V_4 -> V_7 , V_5 ) , V_4 ) ;
for ( V_5 = 0 ; V_5 < V_4 -> V_9 ; V_5 ++ )
if ( V_4 -> V_36 [ V_5 ] )
F_36 ( V_4 -> V_36 [ V_5 ] ) ;
if ( V_4 -> V_39 ) {
V_4 -> V_41 ( V_4 , V_42 ) ;
F_37 ( V_4 -> V_7 ) ;
V_4 -> V_39 = 0 ;
}
V_4 -> V_9 = 0 ;
V_4 -> V_40 = 0 ;
F_29 ( V_4 -> V_34 ) ;
V_4 -> V_34 = NULL ;
F_29 ( V_4 -> V_36 ) ;
V_4 -> V_36 = NULL ;
F_29 ( V_4 -> V_49 ) ;
V_4 -> V_49 = NULL ;
}
static int F_38 ( struct V_1 * V_2 , unsigned V_53 ,
struct V_10 * V_49 [] , T_4 * V_54 [] ,
const char * const V_55 [] , bool V_26 ,
struct V_27 * V_28 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_3 V_44 ;
int V_5 , V_32 , V_25 , V_56 ;
V_4 -> V_49 = F_39 ( V_53 , sizeof( * V_4 -> V_49 ) , V_35 ) ;
if ( ! V_4 -> V_49 )
return - V_33 ;
if ( V_26 ) {
V_25 = 1 ;
for ( V_5 = 0 ; V_5 < V_53 ; ++ V_5 )
if ( V_54 [ V_5 ] )
++ V_25 ;
} else {
V_25 = 2 ;
}
V_32 = F_16 ( V_2 , V_25 , V_26 ,
V_26 ? V_28 : NULL ) ;
if ( V_32 )
goto V_57;
V_4 -> V_26 = V_26 ;
V_56 = V_4 -> V_40 ;
for ( V_5 = 0 ; V_5 < V_53 ; ++ V_5 ) {
if ( ! V_55 [ V_5 ] ) {
V_49 [ V_5 ] = NULL ;
continue;
}
if ( ! V_54 [ V_5 ] )
V_44 = V_42 ;
else if ( V_4 -> V_26 )
V_44 = V_56 ++ ;
else
V_44 = V_58 ;
V_49 [ V_5 ] = F_23 ( V_2 , V_5 , V_54 [ V_5 ] , V_55 [ V_5 ] ,
V_44 ) ;
if ( F_26 ( V_49 [ V_5 ] ) ) {
V_32 = F_40 ( V_49 [ V_5 ] ) ;
goto V_57;
}
if ( ! V_4 -> V_26 || V_44 == V_42 )
continue;
snprintf ( V_4 -> V_34 [ V_44 ] ,
sizeof * V_4 -> V_34 ,
L_3 ,
F_17 ( & V_4 -> V_2 . V_30 ) , V_55 [ V_5 ] ) ;
V_32 = F_22 ( F_4 ( V_4 -> V_7 , V_44 ) ,
F_12 , 0 ,
V_4 -> V_34 [ V_44 ] ,
V_49 [ V_5 ] ) ;
if ( V_32 )
goto V_57;
}
return 0 ;
V_57:
F_32 ( V_2 ) ;
return V_32 ;
}
static int F_41 ( struct V_1 * V_2 , unsigned V_53 ,
struct V_10 * V_49 [] , T_4 * V_54 [] ,
const char * const V_55 [] )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 , V_32 ;
V_4 -> V_49 = F_39 ( V_53 , sizeof( * V_4 -> V_49 ) , V_35 ) ;
if ( ! V_4 -> V_49 )
return - V_33 ;
V_32 = F_22 ( V_4 -> V_7 -> V_8 , F_14 , V_59 ,
F_17 ( & V_2 -> V_30 ) , V_4 ) ;
if ( V_32 )
goto V_60;
V_4 -> V_6 = 1 ;
V_4 -> V_26 = false ;
for ( V_5 = 0 ; V_5 < V_53 ; ++ V_5 ) {
if ( ! V_55 [ V_5 ] ) {
V_49 [ V_5 ] = NULL ;
continue;
}
V_49 [ V_5 ] = F_23 ( V_2 , V_5 , V_54 [ V_5 ] , V_55 [ V_5 ] ,
V_42 ) ;
if ( F_26 ( V_49 [ V_5 ] ) ) {
V_32 = F_40 ( V_49 [ V_5 ] ) ;
goto V_60;
}
}
return 0 ;
V_60:
F_32 ( V_2 ) ;
return V_32 ;
}
int F_42 ( struct V_1 * V_2 , unsigned V_53 ,
struct V_10 * V_49 [] , T_4 * V_54 [] ,
const char * const V_55 [] , struct V_27 * V_28 )
{
int V_32 ;
V_32 = F_38 ( V_2 , V_53 , V_49 , V_54 , V_55 , true , V_28 ) ;
if ( ! V_32 )
return 0 ;
V_32 = F_38 ( V_2 , V_53 , V_49 , V_54 , V_55 , false , V_28 ) ;
if ( ! V_32 )
return 0 ;
return F_41 ( V_2 , V_53 , V_49 , V_54 , V_55 ) ;
}
const char * F_43 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return F_44 ( V_4 -> V_7 ) ;
}
int F_45 ( struct V_10 * V_11 , int V_61 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_17 * V_18 = V_4 -> V_49 [ V_11 -> V_12 ] ;
struct V_62 * V_63 ;
unsigned int V_8 ;
if ( ! V_11 -> F_24 )
return - V_64 ;
if ( V_4 -> V_39 ) {
V_63 = V_4 -> V_36 [ V_18 -> V_52 ] ;
V_8 = F_4 ( V_4 -> V_7 , V_18 -> V_52 ) ;
if ( V_61 == - 1 )
F_34 ( V_8 , NULL ) ;
else {
F_46 ( V_63 ) ;
F_47 ( V_61 , V_63 ) ;
F_34 ( V_8 , V_63 ) ;
}
}
return 0 ;
}
const struct V_62 * F_48 ( struct V_1 * V_2 , int V_12 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( ! V_4 -> V_26 ||
V_4 -> V_49 [ V_12 ] -> V_52 == V_42 )
return NULL ;
return F_49 ( V_4 -> V_7 ,
V_4 -> V_49 [ V_12 ] -> V_52 ) ;
}
static int F_50 ( struct V_65 * V_30 )
{
struct V_7 * V_7 = F_51 ( V_30 ) ;
struct V_3 * V_4 = F_52 ( V_7 ) ;
int V_19 ;
V_19 = F_53 ( & V_4 -> V_2 ) ;
if ( ! V_19 )
F_54 ( V_7 ) ;
return V_19 ;
}
static int F_55 ( struct V_65 * V_30 )
{
struct V_7 * V_7 = F_51 ( V_30 ) ;
struct V_3 * V_4 = F_52 ( V_7 ) ;
int V_19 ;
V_19 = F_56 ( V_7 ) ;
if ( V_19 )
return V_19 ;
F_57 ( V_7 ) ;
return F_58 ( & V_4 -> V_2 ) ;
}
static void F_59 ( struct V_65 * V_66 )
{
struct V_1 * V_2 = F_60 ( V_66 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_29 ( V_4 ) ;
}
static int F_61 ( struct V_7 * V_7 ,
const struct V_67 * V_68 )
{
struct V_3 * V_4 ;
int V_69 ;
V_4 = F_19 ( sizeof( struct V_3 ) , V_35 ) ;
if ( ! V_4 )
return - V_33 ;
F_62 ( V_7 , V_4 ) ;
V_4 -> V_2 . V_30 . V_70 = & V_7 -> V_30 ;
V_4 -> V_2 . V_30 . V_71 = F_59 ;
V_4 -> V_7 = V_7 ;
F_28 ( & V_4 -> V_48 ) ;
F_63 ( & V_4 -> V_22 ) ;
V_69 = F_56 ( V_7 ) ;
if ( V_69 )
goto V_72;
if ( V_73 ) {
V_69 = F_64 ( V_4 ) ;
if ( V_69 == - V_74 || V_69 == - V_33 )
V_69 = F_65 ( V_4 ) ;
if ( V_69 )
goto V_75;
} else {
V_69 = F_65 ( V_4 ) ;
if ( V_69 == - V_74 )
V_69 = F_64 ( V_4 ) ;
if ( V_69 )
goto V_75;
}
F_57 ( V_7 ) ;
V_69 = F_66 ( & V_4 -> V_2 ) ;
if ( V_69 )
goto V_76;
return 0 ;
V_76:
if ( V_4 -> V_77 )
F_67 ( V_4 ) ;
else
F_68 ( V_4 ) ;
V_75:
F_54 ( V_7 ) ;
V_72:
F_29 ( V_4 ) ;
return V_69 ;
}
static void F_69 ( struct V_7 * V_7 )
{
struct V_3 * V_4 = F_52 ( V_7 ) ;
struct V_65 * V_30 = F_70 ( & V_4 -> V_2 . V_30 ) ;
F_71 ( & V_4 -> V_2 ) ;
if ( V_4 -> V_77 )
F_67 ( V_4 ) ;
else
F_68 ( V_4 ) ;
F_54 ( V_7 ) ;
F_72 ( V_30 ) ;
}
