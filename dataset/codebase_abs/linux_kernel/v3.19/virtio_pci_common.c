void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 ;
if ( V_4 -> V_6 )
F_3 ( V_4 -> V_7 -> V_8 ) ;
for ( V_5 = 0 ; V_5 < V_4 -> V_9 ; ++ V_5 )
F_3 ( V_4 -> V_10 [ V_5 ] . V_11 ) ;
}
bool F_4 ( struct V_12 * V_13 )
{
F_5 ( V_13 -> V_14 , ( void V_15 * ) V_13 -> V_16 ) ;
return true ;
}
static T_1 F_6 ( int V_8 , void * V_17 )
{
struct V_3 * V_4 = V_17 ;
F_7 ( & V_4 -> V_2 ) ;
return V_18 ;
}
static T_1 F_8 ( int V_8 , void * V_17 )
{
struct V_3 * V_4 = V_17 ;
struct V_19 * V_20 ;
T_1 V_21 = V_22 ;
unsigned long V_23 ;
F_9 ( & V_4 -> V_24 , V_23 ) ;
F_10 (info, &vp_dev->virtqueues, node) {
if ( F_11 ( V_8 , V_20 -> V_13 ) == V_18 )
V_21 = V_18 ;
}
F_12 ( & V_4 -> V_24 , V_23 ) ;
return V_21 ;
}
static T_1 F_13 ( int V_8 , void * V_17 )
{
struct V_3 * V_4 = V_17 ;
T_2 V_25 ;
V_25 = F_14 ( V_4 -> V_25 ) ;
if ( ! V_25 )
return V_22 ;
if ( V_25 & V_26 )
F_6 ( V_8 , V_17 ) ;
return F_8 ( V_8 , V_17 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 ;
if ( V_4 -> V_6 ) {
F_16 ( V_4 -> V_7 -> V_8 , V_4 ) ;
V_4 -> V_6 = 0 ;
}
for ( V_5 = 0 ; V_5 < V_4 -> V_27 ; ++ V_5 )
F_16 ( V_4 -> V_10 [ V_5 ] . V_11 , V_4 ) ;
for ( V_5 = 0 ; V_5 < V_4 -> V_9 ; V_5 ++ )
if ( V_4 -> V_28 [ V_5 ] )
F_17 ( V_4 -> V_28 [ V_5 ] ) ;
if ( V_4 -> V_29 ) {
V_4 -> V_30 ( V_4 , V_31 ) ;
F_18 ( V_4 -> V_7 ) ;
V_4 -> V_29 = 0 ;
}
V_4 -> V_9 = 0 ;
V_4 -> V_27 = 0 ;
F_19 ( V_4 -> V_32 ) ;
V_4 -> V_32 = NULL ;
F_19 ( V_4 -> V_10 ) ;
V_4 -> V_10 = NULL ;
F_19 ( V_4 -> V_28 ) ;
V_4 -> V_28 = NULL ;
}
static int F_20 ( struct V_1 * V_2 , int V_33 ,
bool V_34 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const char * V_35 = F_21 ( & V_4 -> V_2 . V_36 ) ;
unsigned V_5 , V_37 ;
int V_38 = - V_39 ;
V_4 -> V_9 = V_33 ;
V_4 -> V_10 = F_22 ( V_33 * sizeof * V_4 -> V_10 ,
V_40 ) ;
if ( ! V_4 -> V_10 )
goto error;
V_4 -> V_32 = F_22 ( V_33 * sizeof * V_4 -> V_32 ,
V_40 ) ;
if ( ! V_4 -> V_32 )
goto error;
V_4 -> V_28
= F_23 ( V_33 * sizeof * V_4 -> V_28 ,
V_40 ) ;
if ( ! V_4 -> V_28 )
goto error;
for ( V_5 = 0 ; V_5 < V_33 ; ++ V_5 )
if ( ! F_24 ( & V_4 -> V_28 [ V_5 ] ,
V_40 ) )
goto error;
for ( V_5 = 0 ; V_5 < V_33 ; ++ V_5 )
V_4 -> V_10 [ V_5 ] . V_41 = V_5 ;
V_38 = F_25 ( V_4 -> V_7 ,
V_4 -> V_10 , V_33 ) ;
if ( V_38 )
goto error;
V_4 -> V_29 = 1 ;
V_37 = V_4 -> V_27 ;
snprintf ( V_4 -> V_32 [ V_37 ] , sizeof * V_4 -> V_32 ,
L_1 , V_35 ) ;
V_38 = F_26 ( V_4 -> V_10 [ V_37 ] . V_11 ,
F_6 , 0 , V_4 -> V_32 [ V_37 ] ,
V_4 ) ;
if ( V_38 )
goto error;
++ V_4 -> V_27 ;
V_37 = V_4 -> V_30 ( V_4 , V_37 ) ;
if ( V_37 == V_31 ) {
V_38 = - V_42 ;
goto error;
}
if ( ! V_34 ) {
V_37 = V_4 -> V_27 ;
snprintf ( V_4 -> V_32 [ V_37 ] , sizeof * V_4 -> V_32 ,
L_2 , V_35 ) ;
V_38 = F_26 ( V_4 -> V_10 [ V_37 ] . V_11 ,
F_8 , 0 , V_4 -> V_32 [ V_37 ] ,
V_4 ) ;
if ( V_38 )
goto error;
++ V_4 -> V_27 ;
}
return 0 ;
error:
F_15 ( V_2 ) ;
return V_38 ;
}
static int F_27 ( struct V_1 * V_2 )
{
int V_38 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_38 = F_26 ( V_4 -> V_7 -> V_8 , F_13 ,
V_43 , F_21 ( & V_2 -> V_36 ) , V_4 ) ;
if ( ! V_38 )
V_4 -> V_6 = 1 ;
return V_38 ;
}
static struct V_12 * F_28 ( struct V_1 * V_2 , unsigned V_14 ,
void (* F_29)( struct V_12 * V_13 ) ,
const char * V_35 ,
T_3 V_44 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_19 * V_20 = F_22 ( sizeof *V_20 , V_40 ) ;
struct V_12 * V_13 ;
unsigned long V_23 ;
if ( ! V_20 )
return F_30 ( - V_39 ) ;
V_13 = V_4 -> V_45 ( V_4 , V_20 , V_14 , F_29 , V_35 , V_44 ) ;
if ( F_31 ( V_13 ) )
goto V_46;
V_20 -> V_13 = V_13 ;
if ( F_29 ) {
F_9 ( & V_4 -> V_24 , V_23 ) ;
F_32 ( & V_20 -> V_47 , & V_4 -> V_48 ) ;
F_12 ( & V_4 -> V_24 , V_23 ) ;
} else {
F_33 ( & V_20 -> V_47 ) ;
}
V_4 -> V_49 [ V_14 ] = V_20 ;
return V_13 ;
V_46:
F_19 ( V_20 ) ;
return V_13 ;
}
static void F_34 ( struct V_12 * V_13 )
{
struct V_3 * V_4 = F_2 ( V_13 -> V_2 ) ;
struct V_19 * V_20 = V_4 -> V_49 [ V_13 -> V_14 ] ;
unsigned long V_23 ;
F_9 ( & V_4 -> V_24 , V_23 ) ;
F_35 ( & V_20 -> V_47 ) ;
F_12 ( & V_4 -> V_24 , V_23 ) ;
V_4 -> V_50 ( V_20 ) ;
F_19 ( V_20 ) ;
}
void F_36 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_12 * V_13 , * V_51 ;
struct V_19 * V_20 ;
F_37 (vq, n, &vdev->vqs, list) {
V_20 = V_4 -> V_49 [ V_13 -> V_14 ] ;
if ( V_4 -> V_34 &&
V_20 -> V_52 != V_31 )
F_16 ( V_4 -> V_10 [ V_20 -> V_52 ] . V_11 ,
V_13 ) ;
F_34 ( V_13 ) ;
}
V_4 -> V_34 = false ;
F_15 ( V_2 ) ;
F_19 ( V_4 -> V_49 ) ;
V_4 -> V_49 = NULL ;
}
static int F_38 ( struct V_1 * V_2 , unsigned V_53 ,
struct V_12 * V_49 [] ,
T_4 * V_54 [] ,
const char * V_55 [] ,
bool V_56 ,
bool V_34 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_3 V_44 ;
int V_5 , V_38 , V_33 , V_57 ;
V_4 -> V_49 = F_22 ( V_53 * sizeof * V_4 -> V_49 , V_40 ) ;
if ( ! V_4 -> V_49 )
return - V_39 ;
if ( ! V_56 ) {
V_38 = F_27 ( V_2 ) ;
if ( V_38 )
goto V_58;
} else {
if ( V_34 ) {
V_33 = 1 ;
for ( V_5 = 0 ; V_5 < V_53 ; ++ V_5 )
if ( V_54 [ V_5 ] )
++ V_33 ;
} else {
V_33 = 2 ;
}
V_38 = F_20 ( V_2 , V_33 , V_34 ) ;
if ( V_38 )
goto V_58;
}
V_4 -> V_34 = V_34 ;
V_57 = V_4 -> V_27 ;
for ( V_5 = 0 ; V_5 < V_53 ; ++ V_5 ) {
if ( ! V_55 [ V_5 ] ) {
V_49 [ V_5 ] = NULL ;
continue;
} else if ( ! V_54 [ V_5 ] || ! V_4 -> V_29 )
V_44 = V_31 ;
else if ( V_4 -> V_34 )
V_44 = V_57 ++ ;
else
V_44 = V_59 ;
V_49 [ V_5 ] = F_28 ( V_2 , V_5 , V_54 [ V_5 ] , V_55 [ V_5 ] , V_44 ) ;
if ( F_31 ( V_49 [ V_5 ] ) ) {
V_38 = F_39 ( V_49 [ V_5 ] ) ;
goto V_58;
}
if ( ! V_4 -> V_34 || V_44 == V_31 )
continue;
snprintf ( V_4 -> V_32 [ V_44 ] ,
sizeof * V_4 -> V_32 ,
L_3 ,
F_21 ( & V_4 -> V_2 . V_36 ) , V_55 [ V_5 ] ) ;
V_38 = F_26 ( V_4 -> V_10 [ V_44 ] . V_11 ,
F_11 , 0 ,
V_4 -> V_32 [ V_44 ] ,
V_49 [ V_5 ] ) ;
if ( V_38 ) {
F_34 ( V_49 [ V_5 ] ) ;
goto V_58;
}
}
return 0 ;
V_58:
F_36 ( V_2 ) ;
return V_38 ;
}
int F_40 ( struct V_1 * V_2 , unsigned V_53 ,
struct V_12 * V_49 [] ,
T_4 * V_54 [] ,
const char * V_55 [] )
{
int V_38 ;
V_38 = F_38 ( V_2 , V_53 , V_49 , V_54 , V_55 , true , true ) ;
if ( ! V_38 )
return 0 ;
V_38 = F_38 ( V_2 , V_53 , V_49 , V_54 , V_55 ,
true , false ) ;
if ( ! V_38 )
return 0 ;
return F_38 ( V_2 , V_53 , V_49 , V_54 , V_55 ,
false , false ) ;
}
const char * F_41 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return F_42 ( V_4 -> V_7 ) ;
}
int F_43 ( struct V_12 * V_13 , int V_60 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_19 * V_20 = V_4 -> V_49 [ V_13 -> V_14 ] ;
struct V_61 * V_62 ;
unsigned int V_8 ;
if ( ! V_13 -> F_29 )
return - V_63 ;
if ( V_4 -> V_29 ) {
V_62 = V_4 -> V_28 [ V_20 -> V_52 ] ;
V_8 = V_4 -> V_10 [ V_20 -> V_52 ] . V_11 ;
if ( V_60 == - 1 )
F_44 ( V_8 , NULL ) ;
else {
F_45 ( V_60 , V_62 ) ;
F_44 ( V_8 , V_62 ) ;
}
}
return 0 ;
}
static int F_46 ( struct V_64 * V_36 )
{
struct V_7 * V_7 = F_47 ( V_36 ) ;
struct V_3 * V_4 = F_48 ( V_7 ) ;
int V_21 ;
V_21 = F_49 ( & V_4 -> V_2 ) ;
if ( ! V_21 )
F_50 ( V_7 ) ;
return V_21 ;
}
static int F_51 ( struct V_64 * V_36 )
{
struct V_7 * V_7 = F_47 ( V_36 ) ;
struct V_3 * V_4 = F_48 ( V_7 ) ;
int V_21 ;
V_21 = F_52 ( V_7 ) ;
if ( V_21 )
return V_21 ;
F_53 ( V_7 ) ;
return F_54 ( & V_4 -> V_2 ) ;
}
static int F_55 ( struct V_7 * V_7 ,
const struct V_65 * V_66 )
{
return F_56 ( V_7 , V_66 ) ;
}
static void F_57 ( struct V_7 * V_7 )
{
F_58 ( V_7 ) ;
}
