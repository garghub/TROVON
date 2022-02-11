bool F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
if ( V_2 -> V_4 )
return false ;
if ( ! ( F_2 ( V_2 , V_3 ) & V_5 ) )
return false ;
if ( ! V_2 -> V_6 &&
( F_3 ( F_4 ( V_2 , V_3 ) ) &
V_7 ) )
return false ;
if ( ! ( F_5 ( V_2 , V_3 ) & V_8 ) )
return false ;
return true ;
}
static T_2 F_6 ( struct V_1 * V_2 , T_1 V_3 )
{
T_2 V_9 ;
if ( ! V_2 -> V_10 ) {
V_9 = F_2 ( V_2 , V_3 ) ;
if ( V_9 & V_11 )
F_7 ( V_2 , V_3 , 0 ,
V_12 , 0 ) ;
}
return F_7 ( V_2 , V_3 , 0 ,
V_13 , 0 ) ;
}
struct V_14 *
F_8 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_14 * V_15 = V_2 -> V_16 . V_17 ;
int V_18 ;
if ( ! V_3 || ! V_15 )
return NULL ;
for ( V_18 = 0 ; V_18 < V_2 -> V_16 . V_19 ; V_18 ++ , V_15 ++ )
if ( V_15 -> V_3 == V_3 )
return V_15 ;
return NULL ;
}
struct V_14 *
F_9 ( struct V_1 * V_2 , unsigned char V_20 )
{
struct V_14 * V_15 = V_2 -> V_16 . V_17 ;
int V_18 ;
if ( ! V_20 || ! V_15 )
return NULL ;
for ( V_18 = 0 ; V_18 < V_2 -> V_16 . V_19 ; V_18 ++ , V_15 ++ )
if ( V_15 -> V_20 == V_20 )
return V_15 ;
return NULL ;
}
struct V_14 *
F_10 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_14 * V_15 = F_8 ( V_2 , V_3 ) ;
if ( V_15 )
return V_15 ;
F_11 ( & V_2 -> V_16 , sizeof( * V_15 ) , 16 ) ;
V_15 = F_12 ( & V_2 -> V_16 ) ;
if ( ! V_15 )
return NULL ;
V_15 -> V_3 = V_3 ;
V_15 -> V_21 = 1 ;
V_15 -> V_20 = V_2 -> V_16 . V_19 ;
return V_15 ;
}
void F_13 ( struct V_1 * V_2 )
{
#ifdef F_14
if ( ! V_2 -> V_22 -> V_23 && V_2 -> V_16 . V_17 ) {
struct V_14 * V_15 = V_2 -> V_16 . V_17 ;
int V_18 ;
for ( V_18 = 0 ; V_18 < V_2 -> V_16 . V_19 ; V_18 ++ , V_15 ++ ) {
if ( V_15 -> V_15 )
F_15 ( V_2 -> V_22 -> V_24 , V_15 -> V_15 ) ;
}
}
#endif
F_16 ( & V_2 -> V_16 ) ;
}
static void F_17 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
if ( V_15 -> V_21 || ! V_15 -> V_25 ) {
V_15 -> V_26 = F_6 ( V_2 , V_15 -> V_3 ) ;
V_15 -> V_21 = 0 ;
}
}
void F_18 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = V_2 -> V_16 . V_17 ;
int V_18 ;
for ( V_18 = 0 ; V_18 < V_2 -> V_16 . V_19 ; V_18 ++ , V_15 ++ )
if ( V_15 -> V_3 )
V_15 -> V_21 = 1 ;
}
T_2 F_19 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_14 * V_15 = F_8 ( V_2 , V_3 ) ;
if ( V_15 ) {
F_17 ( V_2 , V_15 ) ;
return V_15 -> V_26 ;
}
return F_6 ( V_2 , V_3 ) ;
}
int F_20 ( struct V_1 * V_2 , T_1 V_3 )
{
T_2 V_27 = F_19 ( V_2 , V_3 ) ;
return F_21 ( V_27 ) ;
}
int F_22 ( struct V_1 * V_2 , T_1 V_3 ,
unsigned char V_28 )
{
struct V_14 * V_15 = F_10 ( V_2 , V_3 ) ;
if ( ! V_15 )
return - V_29 ;
if ( V_15 -> V_25 )
return 0 ;
V_15 -> V_25 = 1 ;
if ( V_28 )
V_15 -> V_28 = V_28 ;
return F_23 ( V_2 , V_3 , 0 ,
V_30 ,
V_31 | V_15 -> V_20 ) ;
}
void F_24 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = V_2 -> V_16 . V_17 ;
int V_18 , V_32 ;
for ( V_18 = 0 ; V_18 < V_2 -> V_16 . V_19 ; V_18 ++ , V_15 ++ )
if ( V_15 -> V_3 ) {
F_17 ( V_2 , V_15 ) ;
if ( ! V_15 -> V_33 )
continue;
V_32 = F_21 ( V_15 -> V_26 ) ;
F_25 ( V_2 -> V_22 -> V_24 , V_15 -> V_33 , V_32 ) ;
#ifdef F_14
if ( V_15 -> V_15 )
F_26 ( V_15 -> V_15 ,
V_32 ? V_15 -> type : 0 ) ;
#endif
}
}
static int F_27 ( struct V_1 * V_2 , T_1 V_3 )
{
unsigned int V_34 = F_4 ( V_2 , V_3 ) ;
switch ( F_28 ( V_34 ) ) {
case V_35 :
case V_36 :
return V_37 ;
case V_38 :
return V_39 ;
case V_40 :
case V_41 :
return V_42 ;
case V_43 :
return V_44 ;
default:
return V_45 ;
}
}
static void F_29 ( struct V_46 * V_15 )
{
struct V_14 * V_47 = V_15 -> V_48 ;
V_47 -> V_3 = 0 ;
V_47 -> V_15 = NULL ;
}
int F_30 ( struct V_1 * V_2 , T_1 V_3 ,
const char * V_49 , int V_50 )
{
struct V_14 * V_15 ;
struct V_51 * V_33 ;
int V_52 , V_32 ;
V_15 = F_10 ( V_2 , V_3 ) ;
if ( ! V_15 )
return 0 ;
if ( V_15 -> V_33 )
return 0 ;
V_33 = F_31 ( V_49 , V_50 , V_2 ) ;
if ( ! V_33 )
return - V_29 ;
V_52 = F_32 ( V_2 , V_3 , V_33 ) ;
if ( V_52 < 0 )
return V_52 ;
V_15 -> V_33 = V_33 ;
V_32 = F_20 ( V_2 , V_3 ) ;
F_25 ( V_2 -> V_22 -> V_24 , V_33 , V_32 ) ;
#ifdef F_14
V_15 -> type = F_27 ( V_2 , V_3 ) ;
V_52 = F_33 ( V_2 -> V_22 -> V_24 , V_49 , V_15 -> type , & V_15 -> V_15 ) ;
if ( V_52 < 0 )
return V_52 ;
V_15 -> V_15 -> V_48 = V_15 ;
V_15 -> V_15 -> V_53 = F_29 ;
F_26 ( V_15 -> V_15 , V_32 ? V_15 -> type : 0 ) ;
#endif
return 0 ;
}
static int F_34 ( struct V_1 * V_2 , T_1 V_3 ,
const struct V_54 * V_55 ,
char * V_56 , int * V_57 )
{
unsigned int V_34 , V_58 ;
char V_49 [ 44 ] ;
int V_50 , V_52 ;
if ( ! V_3 )
return 0 ;
if ( ! F_1 ( V_2 , V_3 ) )
return 0 ;
V_34 = F_4 ( V_2 , V_3 ) ;
V_58 = F_35 ( V_34 ) ;
if ( V_58 != V_59 )
return 0 ;
F_36 ( V_2 , V_3 , V_55 , V_49 , sizeof( V_49 ) , & V_50 ) ;
if ( ! strcmp ( V_49 , V_56 ) && V_50 == * V_57 )
V_50 ++ ;
strncpy ( V_56 , V_49 , 44 ) ;
* V_57 = V_50 ;
V_52 = F_30 ( V_2 , V_3 , V_49 , V_50 ) ;
if ( V_52 < 0 )
return V_52 ;
return F_22 ( V_2 , V_3 , 0 ) ;
}
int F_37 ( struct V_1 * V_2 ,
const struct V_54 * V_55 )
{
const T_1 * V_60 ;
int V_18 , V_52 , V_57 = 0 ;
char V_56 [ 44 ] = L_1 ;
for ( V_18 = 0 , V_60 = V_55 -> V_61 ; V_18 < V_55 -> V_62 ; V_18 ++ , V_60 ++ ) {
V_52 = F_34 ( V_2 , * V_60 , V_55 , V_56 , & V_57 ) ;
if ( V_52 < 0 )
return V_52 ;
}
for ( V_18 = 0 , V_60 = V_55 -> V_63 ; V_18 < V_55 -> V_64 ; V_18 ++ , V_60 ++ ) {
if ( * V_60 == * V_55 -> V_61 )
break;
V_52 = F_34 ( V_2 , * V_60 , V_55 , V_56 , & V_57 ) ;
if ( V_52 < 0 )
return V_52 ;
}
for ( V_18 = 0 , V_60 = V_55 -> V_65 ; V_18 < V_55 -> V_66 ; V_18 ++ , V_60 ++ ) {
if ( * V_60 == * V_55 -> V_61 )
break;
V_52 = F_34 ( V_2 , * V_60 , V_55 , V_56 , & V_57 ) ;
if ( V_52 < 0 )
return V_52 ;
}
for ( V_18 = 0 ; V_18 < V_55 -> V_67 ; V_18 ++ ) {
V_52 = F_34 ( V_2 , V_55 -> V_68 [ V_18 ] . V_69 , V_55 , V_56 , & V_57 ) ;
if ( V_52 < 0 )
return V_52 ;
}
for ( V_18 = 0 , V_60 = V_55 -> V_70 ; V_18 < V_55 -> V_71 ; V_18 ++ , V_60 ++ ) {
V_52 = F_34 ( V_2 , * V_60 , V_55 , V_56 , & V_57 ) ;
if ( V_52 < 0 )
return V_52 ;
}
V_52 = F_34 ( V_2 , V_55 -> V_72 , V_55 , V_56 , & V_57 ) ;
if ( V_52 < 0 )
return V_52 ;
V_52 = F_34 ( V_2 , V_55 -> V_73 , V_55 , V_56 , & V_57 ) ;
if ( V_52 < 0 )
return V_52 ;
return 0 ;
}
