void
F_1 ( void * V_1 , T_1 V_2 , char * * V_3 )
{
unsigned long * V_4 = V_1 ;
T_1 V_5 ;
for ( V_5 = 0 ; ( V_5 * sizeof( * V_4 ) ) < V_2 ; V_5 ++ ) {
if ( V_3 && ! V_3 [ V_5 ] )
V_3 = NULL ;
F_2 ( L_1 ,
V_6 ,
( unsigned ) ( V_5 * sizeof( * V_4 ) ) , V_4 [ V_5 ] ,
V_3 ? V_3 [ V_5 ] : L_2 ) ;
}
}
void
F_3 ( struct V_7 * V_8 )
{
F_2 ( L_3
L_4
L_5
L_6
L_7
L_8
L_9
L_10 ,
V_6 ,
V_8 -> V_9 , V_8 -> V_9 ,
V_8 -> V_10 ? L_11 : L_2 ,
V_8 -> V_11 ? L_12 : L_2 ,
V_8 -> V_12 ,
V_8 -> V_13 ,
V_8 -> V_14 ,
V_8 -> V_15 ) ;
F_1 ( ( void * )
( ( unsigned long ) V_8 + V_8 -> V_14 ) ,
V_8 -> V_15 - V_8 -> V_14 ,
NULL ) ;
F_2 ( L_13 , V_6 ) ;
F_1 ( ( void * )
( ( unsigned long ) V_8 + V_8 -> V_15 ) ,
V_8 -> V_9 - V_8 -> V_15 ,
NULL ) ;
F_2 ( L_14 , V_6 ) ;
}
static struct V_16 *
F_4 ( struct V_16 * V_17 )
{
union V_18 V_19 ;
char * V_20 = L_15 ;
int V_21 = 0 ;
int V_2 = 0 ;
if ( V_17 -> V_22 != V_23 ) {
F_2 ( L_16 ,
V_6 ,
V_17 -> V_22 , V_17 -> type ) ;
return NULL ;
}
switch( V_17 -> type ) {
case V_24 :
V_20 = L_17 ;
V_2 = V_17 -> V_25 . V_26 . V_27 ;
V_21 =
V_17 -> V_25 . V_26 . V_28 ;
V_19 . V_29 = 0 ;
break;
case V_30 :
V_20 = L_18 ;
V_2 = V_17 -> V_25 . V_31 . V_27 ;
V_21 =
V_17 -> V_25 . V_31 . V_28 ;
V_19 = V_17 -> V_25 . V_31 . V_19 ;
break;
case V_32 :
V_20 = L_19 ;
V_2 = V_17 -> V_25 . V_33 . V_27 ;
V_21 =
V_17 -> V_25 . V_33 . V_28 ;
V_19 = V_17 -> V_25 . V_33 . V_19 ;
break;
case V_34 :
V_20 = L_20 ;
V_2 = V_17 -> V_25 . V_35 . V_27 ;
V_21 = 1 ;
V_19 . V_29 = 0 ;
break;
default:
F_2 ( L_21 ,
V_6 ,
V_17 -> V_22 , V_17 -> type ) ;
return NULL ;
}
F_2 ( L_22
L_23 ,
V_6 ,
V_20 ,
V_17 -> V_22 , V_17 -> type ) ;
F_5 ( & V_19 ) ;
F_6 ( V_17 , V_21 ) ;
V_17 = (struct V_16 * )
( ( unsigned long ) V_17 + V_17 -> V_2 + V_2 ) ;
return V_17 ;
}
static struct V_16 *
F_7 ( struct V_16 * V_17 )
{
struct V_16 * V_36 = NULL ;
struct V_37 * V_38 = V_39 ;
for (; V_38 && V_38 -> V_22 != V_17 -> V_22 ; V_38 = V_38 -> V_36 ) ;
if ( V_38 ) V_36 = V_38 -> V_40 ( V_17 ) ;
return V_36 ;
}
void
F_5 ( union V_18 * V_19 )
{
if ( V_19 -> V_29 )
F_2 ( L_24 ,
V_6 ,
V_19 -> V_41 . V_42 , V_19 -> V_41 . V_43 ,
V_19 -> V_41 . V_44 , V_19 -> V_41 . V_45 ,
V_19 -> V_41 . V_46 , V_19 -> V_41 . V_47 ) ;
}
void
F_6 ( struct V_16 * V_17 , int V_21 )
{
struct V_16 * V_48 ;
int V_5 ;
V_48 = (struct V_16 * )
( ( unsigned long ) V_17 + V_17 -> V_2 ) ;
for ( V_5 = 0 ; V_48 && V_5 < V_21 ; V_5 ++ ) {
F_2 ( L_25 , V_6 , V_5 ) ;
V_48 = F_8 ( V_48 ) ;
}
}
struct V_16 *
F_8 ( struct V_16 * V_17 )
{
struct V_16 * V_36 = NULL ;
switch( V_17 -> V_22 ) {
case V_49 :
break;
case V_23 :
V_36 = F_4 ( V_17 ) ;
break;
default:
if ( NULL == ( V_36 = F_7 ( V_17 ) ) ) {
F_2 ( L_26
L_27 ,
V_6 ,
V_17 -> V_22 , V_17 -> type ) ;
}
break;
}
return V_36 ;
}
void
F_9 ( struct V_16 * V_17 )
{
struct V_50 * V_51 ;
char * * V_3 = NULL ;
for ( V_51 = V_52 ; V_51 ; V_51 = V_51 -> V_36 ) {
if ( V_51 -> V_22 == V_17 -> V_22 &&
V_51 -> type == V_17 -> type &&
V_51 -> V_53 == V_17 -> V_53 ) {
V_3 = V_51 -> V_3 ;
F_2 ( L_28 , V_6 , V_51 -> V_54 ) ;
break;
}
}
F_1 ( V_17 , V_17 -> V_2 , V_3 ) ;
}
static void T_2
F_10 ( int V_55 , struct V_56 * V_57 )
{
struct V_16 * V_17 = (struct V_16 * )
( V_58 | V_57 -> V_59 ) ;
int V_60 ;
F_2 ( L_29
L_30 ,
V_6 , V_55 ) ;
for ( V_60 = 0 ; V_17 && ( V_17 -> V_22 != V_49 ) ; V_60 ++ )
V_17 = F_8 ( V_17 ) ;
V_57 -> V_59 = 0 ;
F_2 ( L_31
L_32 ,
V_6 , V_60 , V_55 ) ;
}
void T_2
F_11 ( void )
{
struct V_56 * V_57 ;
unsigned long V_55 ;
for ( V_55 = 0 ; V_55 < V_61 -> V_62 ; V_55 ++ ) {
V_57 = (struct V_56 * )
( ( unsigned long ) V_61 + V_61 -> V_63
+ V_55 * V_61 -> V_64 ) ;
if ( V_57 -> V_59 )
F_10 ( V_55 , V_57 ) ;
}
}
int T_2
F_12 ( struct V_50 * V_65 )
{
struct V_50 * V_51 = V_52 ;
if ( V_51 == NULL ) V_52 = V_65 ;
else {
for (; V_51 -> V_36 != NULL ; V_51 = V_51 -> V_36 ) {
if ( ( V_51 -> V_22 == V_65 -> V_22 && V_51 -> type == V_65 -> type ) ||
V_51 == V_65 ) {
F_2 ( L_33
L_34 ) ;
return - V_66 ;
}
}
V_51 -> V_36 = V_65 ;
}
V_65 -> V_36 = NULL ;
return 0 ;
}
int T_2
F_13 ( struct V_37 * V_65 )
{
struct V_37 * V_38 = V_39 ;
if ( V_38 == NULL ) V_39 = V_65 ;
else {
for (; V_38 -> V_36 != NULL ; V_38 = V_38 -> V_36 ) {
if ( V_38 -> V_22 == V_65 -> V_22 || V_38 == V_65 ) {
F_2 ( L_33
L_35 ) ;
return - V_66 ;
}
}
V_38 -> V_36 = V_65 ;
}
V_65 -> V_36 = NULL ;
return 0 ;
}
