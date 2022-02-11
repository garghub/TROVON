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
bool V_26 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const char * V_27 = F_17 ( & V_4 -> V_2 . V_28 ) ;
unsigned V_5 , V_29 ;
int V_30 = - V_31 ;
V_4 -> V_9 = V_25 ;
V_4 -> V_32 = F_18 ( V_25 * sizeof * V_4 -> V_32 ,
V_33 ) ;
if ( ! V_4 -> V_32 )
goto error;
V_4 -> V_34
= F_19 ( V_25 * sizeof * V_4 -> V_34 ,
V_33 ) ;
if ( ! V_4 -> V_34 )
goto error;
for ( V_5 = 0 ; V_5 < V_25 ; ++ V_5 )
if ( ! F_20 ( & V_4 -> V_34 [ V_5 ] ,
V_33 ) )
goto error;
V_30 = F_21 ( V_4 -> V_7 , V_25 , V_25 ,
V_35 ) ;
if ( V_30 < 0 )
goto error;
V_4 -> V_36 = 1 ;
V_29 = V_4 -> V_37 ;
snprintf ( V_4 -> V_32 [ V_29 ] , sizeof * V_4 -> V_32 ,
L_1 , V_27 ) ;
V_30 = F_22 ( F_4 ( V_4 -> V_7 , V_29 ) ,
F_7 , 0 , V_4 -> V_32 [ V_29 ] ,
V_4 ) ;
if ( V_30 )
goto error;
++ V_4 -> V_37 ;
V_29 = V_4 -> V_38 ( V_4 , V_29 ) ;
if ( V_29 == V_39 ) {
V_30 = - V_40 ;
goto error;
}
if ( ! V_26 ) {
V_29 = V_4 -> V_37 ;
snprintf ( V_4 -> V_32 [ V_29 ] , sizeof * V_4 -> V_32 ,
L_2 , V_27 ) ;
V_30 = F_22 ( F_4 ( V_4 -> V_7 , V_29 ) ,
F_9 , 0 , V_4 -> V_32 [ V_29 ] ,
V_4 ) ;
if ( V_30 )
goto error;
++ V_4 -> V_37 ;
}
return 0 ;
error:
return V_30 ;
}
static struct V_10 * F_23 ( struct V_1 * V_2 , unsigned V_12 ,
void (* F_24)( struct V_10 * V_11 ) ,
const char * V_27 ,
T_3 V_41 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_17 * V_18 = F_18 ( sizeof *V_18 , V_33 ) ;
struct V_10 * V_11 ;
unsigned long V_21 ;
if ( ! V_18 )
return F_25 ( - V_31 ) ;
V_11 = V_4 -> V_42 ( V_4 , V_18 , V_12 , F_24 , V_27 , V_41 ) ;
if ( F_26 ( V_11 ) )
goto V_43;
V_18 -> V_11 = V_11 ;
if ( F_24 ) {
F_10 ( & V_4 -> V_22 , V_21 ) ;
F_27 ( & V_18 -> V_44 , & V_4 -> V_45 ) ;
F_13 ( & V_4 -> V_22 , V_21 ) ;
} else {
F_28 ( & V_18 -> V_44 ) ;
}
V_4 -> V_46 [ V_12 ] = V_18 ;
return V_11 ;
V_43:
F_29 ( V_18 ) ;
return V_11 ;
}
static void F_30 ( struct V_10 * V_11 )
{
struct V_3 * V_4 = F_2 ( V_11 -> V_2 ) ;
struct V_17 * V_18 = V_4 -> V_46 [ V_11 -> V_12 ] ;
unsigned long V_21 ;
F_10 ( & V_4 -> V_22 , V_21 ) ;
F_31 ( & V_18 -> V_44 ) ;
F_13 ( & V_4 -> V_22 , V_21 ) ;
V_4 -> V_47 ( V_18 ) ;
F_29 ( V_18 ) ;
}
void F_32 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_10 * V_11 , * V_48 ;
int V_5 ;
F_33 (vq, n, &vdev->vqs, list) {
if ( V_4 -> V_26 ) {
int V_29 = V_4 -> V_46 [ V_11 -> V_12 ] -> V_49 ;
if ( V_29 != V_39 )
F_34 ( F_4 ( V_4 -> V_7 , V_29 ) ,
V_11 ) ;
}
F_30 ( V_11 ) ;
}
V_4 -> V_26 = false ;
if ( V_4 -> V_6 ) {
F_34 ( V_4 -> V_7 -> V_8 , V_4 ) ;
V_4 -> V_6 = 0 ;
}
for ( V_5 = 0 ; V_5 < V_4 -> V_37 ; ++ V_5 )
F_34 ( F_4 ( V_4 -> V_7 , V_5 ) , V_4 ) ;
for ( V_5 = 0 ; V_5 < V_4 -> V_9 ; V_5 ++ )
if ( V_4 -> V_34 [ V_5 ] )
F_35 ( V_4 -> V_34 [ V_5 ] ) ;
if ( V_4 -> V_36 ) {
V_4 -> V_38 ( V_4 , V_39 ) ;
F_36 ( V_4 -> V_7 ) ;
V_4 -> V_36 = 0 ;
}
V_4 -> V_9 = 0 ;
V_4 -> V_37 = 0 ;
F_29 ( V_4 -> V_32 ) ;
V_4 -> V_32 = NULL ;
F_29 ( V_4 -> V_34 ) ;
V_4 -> V_34 = NULL ;
F_29 ( V_4 -> V_46 ) ;
V_4 -> V_46 = NULL ;
}
static int F_37 ( struct V_1 * V_2 , unsigned V_50 ,
struct V_10 * V_46 [] ,
T_4 * V_51 [] ,
const char * const V_52 [] ,
bool V_26 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_3 V_41 ;
int V_5 , V_30 , V_25 , V_53 ;
V_4 -> V_46 = F_38 ( V_50 , sizeof( * V_4 -> V_46 ) , V_33 ) ;
if ( ! V_4 -> V_46 )
return - V_31 ;
if ( V_26 ) {
V_25 = 1 ;
for ( V_5 = 0 ; V_5 < V_50 ; ++ V_5 )
if ( V_51 [ V_5 ] )
++ V_25 ;
} else {
V_25 = 2 ;
}
V_30 = F_16 ( V_2 , V_25 , V_26 ) ;
if ( V_30 )
goto V_54;
V_4 -> V_26 = V_26 ;
V_53 = V_4 -> V_37 ;
for ( V_5 = 0 ; V_5 < V_50 ; ++ V_5 ) {
if ( ! V_52 [ V_5 ] ) {
V_46 [ V_5 ] = NULL ;
continue;
}
if ( ! V_51 [ V_5 ] )
V_41 = V_39 ;
else if ( V_4 -> V_26 )
V_41 = V_53 ++ ;
else
V_41 = V_55 ;
V_46 [ V_5 ] = F_23 ( V_2 , V_5 , V_51 [ V_5 ] , V_52 [ V_5 ] , V_41 ) ;
if ( F_26 ( V_46 [ V_5 ] ) ) {
V_30 = F_39 ( V_46 [ V_5 ] ) ;
goto V_54;
}
if ( ! V_4 -> V_26 || V_41 == V_39 )
continue;
snprintf ( V_4 -> V_32 [ V_41 ] ,
sizeof * V_4 -> V_32 ,
L_3 ,
F_17 ( & V_4 -> V_2 . V_28 ) , V_52 [ V_5 ] ) ;
V_30 = F_22 ( F_4 ( V_4 -> V_7 , V_41 ) ,
F_12 , 0 ,
V_4 -> V_32 [ V_41 ] ,
V_46 [ V_5 ] ) ;
if ( V_30 )
goto V_54;
}
return 0 ;
V_54:
F_32 ( V_2 ) ;
return V_30 ;
}
static int F_40 ( struct V_1 * V_2 , unsigned V_50 ,
struct V_10 * V_46 [] , T_4 * V_51 [] ,
const char * const V_52 [] )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 , V_30 ;
V_4 -> V_46 = F_38 ( V_50 , sizeof( * V_4 -> V_46 ) , V_33 ) ;
if ( ! V_4 -> V_46 )
return - V_31 ;
V_30 = F_22 ( V_4 -> V_7 -> V_8 , F_14 , V_56 ,
F_17 ( & V_2 -> V_28 ) , V_4 ) ;
if ( V_30 )
goto V_57;
V_4 -> V_6 = 1 ;
V_4 -> V_26 = false ;
for ( V_5 = 0 ; V_5 < V_50 ; ++ V_5 ) {
if ( ! V_52 [ V_5 ] ) {
V_46 [ V_5 ] = NULL ;
continue;
}
V_46 [ V_5 ] = F_23 ( V_2 , V_5 , V_51 [ V_5 ] , V_52 [ V_5 ] ,
V_39 ) ;
if ( F_26 ( V_46 [ V_5 ] ) ) {
V_30 = F_39 ( V_46 [ V_5 ] ) ;
goto V_57;
}
}
return 0 ;
V_57:
F_32 ( V_2 ) ;
return V_30 ;
}
int F_41 ( struct V_1 * V_2 , unsigned V_50 ,
struct V_10 * V_46 [] ,
T_4 * V_51 [] ,
const char * const V_52 [] )
{
int V_30 ;
V_30 = F_37 ( V_2 , V_50 , V_46 , V_51 , V_52 , true ) ;
if ( ! V_30 )
return 0 ;
V_30 = F_37 ( V_2 , V_50 , V_46 , V_51 , V_52 , false ) ;
if ( ! V_30 )
return 0 ;
return F_40 ( V_2 , V_50 , V_46 , V_51 , V_52 ) ;
}
const char * F_42 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return F_43 ( V_4 -> V_7 ) ;
}
int F_44 ( struct V_10 * V_11 , int V_58 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_17 * V_18 = V_4 -> V_46 [ V_11 -> V_12 ] ;
struct V_59 * V_60 ;
unsigned int V_8 ;
if ( ! V_11 -> F_24 )
return - V_61 ;
if ( V_4 -> V_36 ) {
V_60 = V_4 -> V_34 [ V_18 -> V_49 ] ;
V_8 = F_4 ( V_4 -> V_7 , V_18 -> V_49 ) ;
if ( V_58 == - 1 )
F_45 ( V_8 , NULL ) ;
else {
F_46 ( V_60 ) ;
F_47 ( V_58 , V_60 ) ;
F_45 ( V_8 , V_60 ) ;
}
}
return 0 ;
}
static int F_48 ( struct V_62 * V_28 )
{
struct V_7 * V_7 = F_49 ( V_28 ) ;
struct V_3 * V_4 = F_50 ( V_7 ) ;
int V_19 ;
V_19 = F_51 ( & V_4 -> V_2 ) ;
if ( ! V_19 )
F_52 ( V_7 ) ;
return V_19 ;
}
static int F_53 ( struct V_62 * V_28 )
{
struct V_7 * V_7 = F_49 ( V_28 ) ;
struct V_3 * V_4 = F_50 ( V_7 ) ;
int V_19 ;
V_19 = F_54 ( V_7 ) ;
if ( V_19 )
return V_19 ;
F_55 ( V_7 ) ;
return F_56 ( & V_4 -> V_2 ) ;
}
static void F_57 ( struct V_62 * V_63 )
{
struct V_1 * V_2 = F_58 ( V_63 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_29 ( V_4 ) ;
}
static int F_59 ( struct V_7 * V_7 ,
const struct V_64 * V_65 )
{
struct V_3 * V_4 ;
int V_66 ;
V_4 = F_19 ( sizeof( struct V_3 ) , V_33 ) ;
if ( ! V_4 )
return - V_31 ;
F_60 ( V_7 , V_4 ) ;
V_4 -> V_2 . V_28 . V_67 = & V_7 -> V_28 ;
V_4 -> V_2 . V_28 . V_68 = F_57 ;
V_4 -> V_7 = V_7 ;
F_28 ( & V_4 -> V_45 ) ;
F_61 ( & V_4 -> V_22 ) ;
V_66 = F_54 ( V_7 ) ;
if ( V_66 )
goto V_69;
if ( V_70 ) {
V_66 = F_62 ( V_4 ) ;
if ( V_66 == - V_71 || V_66 == - V_31 )
V_66 = F_63 ( V_4 ) ;
if ( V_66 )
goto V_72;
} else {
V_66 = F_63 ( V_4 ) ;
if ( V_66 == - V_71 )
V_66 = F_62 ( V_4 ) ;
if ( V_66 )
goto V_72;
}
F_55 ( V_7 ) ;
V_66 = F_64 ( & V_4 -> V_2 ) ;
if ( V_66 )
goto V_73;
return 0 ;
V_73:
if ( V_4 -> V_74 )
F_65 ( V_4 ) ;
else
F_66 ( V_4 ) ;
V_72:
F_52 ( V_7 ) ;
V_69:
F_29 ( V_4 ) ;
return V_66 ;
}
static void F_67 ( struct V_7 * V_7 )
{
struct V_3 * V_4 = F_50 ( V_7 ) ;
struct V_62 * V_28 = F_68 ( & V_4 -> V_2 . V_28 ) ;
F_69 ( & V_4 -> V_2 ) ;
if ( V_4 -> V_74 )
F_65 ( V_4 ) ;
else
F_66 ( V_4 ) ;
F_52 ( V_7 ) ;
F_70 ( V_28 ) ;
}
