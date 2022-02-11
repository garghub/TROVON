static T_1 F_1 ( struct V_1 * V_2 , T_2 V_3 )
{
T_1 V_4 ;
if ( ! V_2 -> V_5 ) {
V_4 = F_2 ( V_2 , V_3 ) ;
if ( V_4 & V_6 )
F_3 ( V_2 , V_3 , 0 ,
V_7 , 0 ) ;
}
return F_3 ( V_2 , V_3 , 0 ,
V_8 , 0 ) ;
}
struct V_9 *
F_4 ( struct V_1 * V_2 , T_2 V_3 )
{
struct V_9 * V_10 = V_2 -> V_11 . V_12 ;
int V_13 ;
if ( ! V_3 || ! V_10 )
return NULL ;
for ( V_13 = 0 ; V_13 < V_2 -> V_11 . V_14 ; V_13 ++ , V_10 ++ )
if ( V_10 -> V_3 == V_3 )
return V_10 ;
return NULL ;
}
struct V_9 *
F_5 ( struct V_1 * V_2 , unsigned char V_15 )
{
struct V_9 * V_10 = V_2 -> V_11 . V_12 ;
int V_13 ;
if ( ! V_15 || ! V_10 )
return NULL ;
for ( V_13 = 0 ; V_13 < V_2 -> V_11 . V_14 ; V_13 ++ , V_10 ++ )
if ( V_10 -> V_15 == V_15 )
return V_10 ;
return NULL ;
}
struct V_9 *
F_6 ( struct V_1 * V_2 , T_2 V_3 )
{
struct V_9 * V_10 = F_4 ( V_2 , V_3 ) ;
if ( V_10 )
return V_10 ;
F_7 ( & V_2 -> V_11 , sizeof( * V_10 ) , 16 ) ;
V_10 = F_8 ( & V_2 -> V_11 ) ;
if ( ! V_10 )
return NULL ;
V_10 -> V_3 = V_3 ;
V_10 -> V_16 = 1 ;
V_10 -> V_15 = V_2 -> V_11 . V_14 ;
return V_10 ;
}
void F_9 ( struct V_1 * V_2 )
{
#ifdef F_10
if ( ! V_2 -> V_17 -> V_18 && V_2 -> V_11 . V_12 ) {
struct V_9 * V_10 = V_2 -> V_11 . V_12 ;
int V_13 ;
for ( V_13 = 0 ; V_13 < V_2 -> V_11 . V_14 ; V_13 ++ , V_10 ++ ) {
if ( V_10 -> V_10 )
F_11 ( V_2 -> V_17 -> V_19 , V_10 -> V_10 ) ;
}
}
#endif
F_12 ( & V_2 -> V_11 ) ;
}
static void F_13 ( struct V_1 * V_2 ,
struct V_9 * V_10 )
{
if ( V_10 -> V_16 || ! V_10 -> V_20 ) {
V_10 -> V_21 = F_1 ( V_2 , V_10 -> V_3 ) ;
V_10 -> V_16 = 0 ;
}
}
void F_14 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_11 . V_12 ;
int V_13 ;
for ( V_13 = 0 ; V_13 < V_2 -> V_11 . V_14 ; V_13 ++ , V_10 ++ )
if ( V_10 -> V_3 )
V_10 -> V_16 = 1 ;
}
T_1 F_15 ( struct V_1 * V_2 , T_2 V_3 )
{
struct V_9 * V_10 = F_4 ( V_2 , V_3 ) ;
if ( V_10 ) {
F_13 ( V_2 , V_10 ) ;
return V_10 -> V_21 ;
}
return F_1 ( V_2 , V_3 ) ;
}
int F_16 ( struct V_1 * V_2 , T_2 V_3 )
{
T_1 V_22 = F_15 ( V_2 , V_3 ) ;
return F_17 ( V_22 ) ;
}
int F_18 ( struct V_1 * V_2 , T_2 V_3 ,
unsigned char V_23 )
{
struct V_9 * V_10 = F_6 ( V_2 , V_3 ) ;
if ( ! V_10 )
return - V_24 ;
if ( V_10 -> V_20 )
return 0 ;
V_10 -> V_20 = 1 ;
if ( V_23 )
V_10 -> V_23 = V_23 ;
return F_19 ( V_2 , V_3 , 0 ,
V_25 ,
V_26 | V_10 -> V_15 ) ;
}
void F_20 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_11 . V_12 ;
int V_13 , V_27 ;
for ( V_13 = 0 ; V_13 < V_2 -> V_11 . V_14 ; V_13 ++ , V_10 ++ )
if ( V_10 -> V_3 ) {
F_13 ( V_2 , V_10 ) ;
if ( ! V_10 -> V_28 )
continue;
V_27 = F_17 ( V_10 -> V_21 ) ;
F_21 ( V_2 -> V_17 -> V_19 , V_10 -> V_28 , V_27 ) ;
#ifdef F_10
if ( V_10 -> V_10 )
F_22 ( V_10 -> V_10 ,
V_27 ? V_10 -> type : 0 ) ;
#endif
}
}
static int F_23 ( struct V_1 * V_2 , T_2 V_3 )
{
unsigned int V_29 = F_24 ( V_2 , V_3 ) ;
switch ( F_25 ( V_29 ) ) {
case V_30 :
case V_31 :
return V_32 ;
case V_33 :
return V_34 ;
case V_35 :
case V_36 :
return V_37 ;
case V_38 :
return V_39 ;
default:
return V_40 ;
}
}
static void F_26 ( struct V_41 * V_10 )
{
struct V_9 * V_42 = V_10 -> V_43 ;
V_42 -> V_3 = 0 ;
V_42 -> V_10 = NULL ;
}
int F_27 ( struct V_1 * V_2 , T_2 V_3 ,
const char * V_44 , int V_45 )
{
struct V_9 * V_10 ;
struct V_46 * V_28 ;
int V_47 , V_27 ;
V_10 = F_6 ( V_2 , V_3 ) ;
if ( ! V_10 )
return 0 ;
if ( V_10 -> V_28 )
return 0 ;
V_28 = F_28 ( V_44 , V_45 , V_2 ) ;
if ( ! V_28 )
return - V_24 ;
V_47 = F_29 ( V_2 , V_3 , V_28 ) ;
if ( V_47 < 0 )
return V_47 ;
V_10 -> V_28 = V_28 ;
V_27 = F_16 ( V_2 , V_3 ) ;
F_21 ( V_2 -> V_17 -> V_19 , V_28 , V_27 ) ;
#ifdef F_10
V_10 -> type = F_23 ( V_2 , V_3 ) ;
V_47 = F_30 ( V_2 -> V_17 -> V_19 , V_44 , V_10 -> type , & V_10 -> V_10 ) ;
if ( V_47 < 0 )
return V_47 ;
V_10 -> V_10 -> V_43 = V_10 ;
V_10 -> V_10 -> V_48 = F_26 ;
F_22 ( V_10 -> V_10 , V_27 ? V_10 -> type : 0 ) ;
#endif
return 0 ;
}
static int F_31 ( struct V_1 * V_2 , T_2 V_3 ,
const struct V_49 * V_50 ,
char * V_51 , int * V_52 )
{
unsigned int V_29 , V_53 ;
char V_44 [ 44 ] ;
int V_45 , V_47 ;
if ( ! V_3 )
return 0 ;
if ( ! F_32 ( V_2 , V_3 ) )
return 0 ;
V_29 = F_24 ( V_2 , V_3 ) ;
V_53 = F_33 ( V_29 ) ;
if ( V_53 != V_54 )
return 0 ;
F_34 ( V_2 , V_3 , V_50 , V_44 , sizeof( V_44 ) , & V_45 ) ;
if ( ! strcmp ( V_44 , V_51 ) && V_45 == * V_52 )
V_45 ++ ;
strncpy ( V_51 , V_44 , 44 ) ;
* V_52 = V_45 ;
V_47 = F_27 ( V_2 , V_3 , V_44 , V_45 ) ;
if ( V_47 < 0 )
return V_47 ;
return F_18 ( V_2 , V_3 , 0 ) ;
}
int F_35 ( struct V_1 * V_2 ,
const struct V_49 * V_50 )
{
const T_2 * V_55 ;
int V_13 , V_47 , V_52 = 0 ;
char V_51 [ 44 ] = L_1 ;
for ( V_13 = 0 , V_55 = V_50 -> V_56 ; V_13 < V_50 -> V_57 ; V_13 ++ , V_55 ++ ) {
V_47 = F_31 ( V_2 , * V_55 , V_50 , V_51 , & V_52 ) ;
if ( V_47 < 0 )
return V_47 ;
}
for ( V_13 = 0 , V_55 = V_50 -> V_58 ; V_13 < V_50 -> V_59 ; V_13 ++ , V_55 ++ ) {
if ( * V_55 == * V_50 -> V_56 )
break;
V_47 = F_31 ( V_2 , * V_55 , V_50 , V_51 , & V_52 ) ;
if ( V_47 < 0 )
return V_47 ;
}
for ( V_13 = 0 , V_55 = V_50 -> V_60 ; V_13 < V_50 -> V_61 ; V_13 ++ , V_55 ++ ) {
if ( * V_55 == * V_50 -> V_56 )
break;
V_47 = F_31 ( V_2 , * V_55 , V_50 , V_51 , & V_52 ) ;
if ( V_47 < 0 )
return V_47 ;
}
for ( V_13 = 0 ; V_13 < V_50 -> V_62 ; V_13 ++ ) {
V_47 = F_31 ( V_2 , V_50 -> V_63 [ V_13 ] . V_64 , V_50 , V_51 , & V_52 ) ;
if ( V_47 < 0 )
return V_47 ;
}
for ( V_13 = 0 , V_55 = V_50 -> V_65 ; V_13 < V_50 -> V_66 ; V_13 ++ , V_55 ++ ) {
V_47 = F_31 ( V_2 , * V_55 , V_50 , V_51 , & V_52 ) ;
if ( V_47 < 0 )
return V_47 ;
}
V_47 = F_31 ( V_2 , V_50 -> V_67 , V_50 , V_51 , & V_52 ) ;
if ( V_47 < 0 )
return V_47 ;
V_47 = F_31 ( V_2 , V_50 -> V_68 , V_50 , V_51 , & V_52 ) ;
if ( V_47 < 0 )
return V_47 ;
return 0 ;
}
