static void F_1 ( union V_1 * V_2 , char * V_3 )
{
int V_4 , V_5 ;
for ( V_5 = 0 , V_4 = 0 ; V_4 < 8 ; ++ V_4 ) {
V_5 += sprintf ( V_3 + V_5 , L_1 ,
F_2 ( ( ( V_6 * ) V_2 -> V_7 ) [ V_4 ] ) ) ;
if ( V_4 < 7 )
V_3 [ V_5 ++ ] = ':' ;
}
}
static void * F_3 ( struct V_8 * V_9 , T_1 * V_10 )
{
struct V_11 * V_12 ;
T_1 V_5 = * V_10 ;
V_12 = F_4 ( V_9 -> V_13 ) ;
if ( ! V_12 )
return NULL ;
while ( V_5 -- ) {
if ( F_5 ( V_12 ) ) {
F_6 ( V_12 ) ;
return NULL ;
}
}
return V_12 ;
}
static void * F_7 ( struct V_8 * V_9 , void * V_14 ,
T_1 * V_10 )
{
struct V_11 * V_12 = V_14 ;
( * V_10 ) ++ ;
if ( F_5 ( V_12 ) ) {
F_6 ( V_12 ) ;
return NULL ;
}
return V_12 ;
}
static void F_8 ( struct V_8 * V_9 , void * V_14 )
{
}
static int F_9 ( struct V_8 * V_9 , void * V_14 )
{
struct V_11 * V_12 = V_14 ;
char V_15 [ sizeof "ffff:ffff:ffff:ffff:ffff:ffff:ffff:ffff"];
union V_1 V_16 ;
unsigned long V_17 ;
unsigned int V_18 , V_19 , V_20 ;
if ( ! V_12 )
return 0 ;
F_10 ( V_12 , & V_16 , & V_17 , & V_18 ,
& V_19 , & V_20 ) ;
F_1 ( & V_16 , V_15 ) ;
F_11 ( V_9 ,
L_2
L_3
L_4
L_5
L_6
L_7 ,
V_15 , V_17 , V_18 ,
V_19 ? L_8 : L_9 ,
V_20 ? L_8 : L_9 ) ;
return 0 ;
}
static int F_12 ( struct V_21 * V_21 , struct V_9 * V_9 )
{
struct V_8 * V_22 ;
int V_23 ;
V_23 = F_13 ( V_9 , & V_24 ) ;
if ( V_23 )
return V_23 ;
V_22 = V_9 -> V_25 ;
V_22 -> V_13 = V_21 -> V_26 ;
return 0 ;
}
static void * F_14 ( struct V_8 * V_9 , T_1 * V_10 )
{
struct V_27 * V_12 ;
T_1 V_5 = * V_10 ;
V_12 = F_15 ( V_9 -> V_13 ) ;
if ( ! V_12 )
return NULL ;
while ( V_5 -- ) {
if ( F_16 ( V_12 ) ) {
F_6 ( V_12 ) ;
return NULL ;
}
}
return V_12 ;
}
static void * F_17 ( struct V_8 * V_9 , void * V_14 ,
T_1 * V_10 )
{
struct V_27 * V_12 = V_14 ;
( * V_10 ) ++ ;
if ( F_16 ( V_12 ) ) {
F_6 ( V_12 ) ;
return NULL ;
}
return V_12 ;
}
static void F_18 ( struct V_8 * V_9 , void * V_14 )
{
}
static int F_19 ( struct V_8 * V_9 , void * V_14 )
{
struct V_27 * V_12 = V_14 ;
char V_15 [ sizeof "ffff:ffff:ffff:ffff:ffff:ffff:ffff:ffff"];
struct V_28 V_29 ;
int V_30 ;
if ( ! V_12 )
return 0 ;
F_20 ( V_12 , & V_29 ) ;
F_1 ( & V_29 . V_31 . V_32 , V_15 ) ;
F_11 ( V_9 ,
L_2
L_10 ,
V_15 , V_29 . V_31 . V_33 ? L_8 : L_9 ) ;
if ( V_29 . V_31 . V_33 ) {
V_30 = F_21 ( V_29 . V_31 . V_30 ) ;
F_11 ( V_9 ,
L_11
L_12
L_13 ,
F_2 ( V_29 . V_31 . V_33 ) ,
V_29 . V_31 . V_34 ,
V_30 / 1000 , V_30 % 1000 ) ;
}
F_22 ( V_9 , '\n' ) ;
return 0 ;
}
static int F_23 ( struct V_21 * V_21 , struct V_9 * V_9 )
{
struct V_8 * V_22 ;
int V_23 ;
V_23 = F_13 ( V_9 , & V_35 ) ;
if ( V_23 )
return V_23 ;
V_22 = V_9 -> V_25 ;
V_22 -> V_13 = V_21 -> V_26 ;
return 0 ;
}
void F_24 ( struct V_36 * V_37 )
{
struct V_38 * V_39 = F_25 ( V_37 ) ;
char V_40 [ V_41 + sizeof "_path"];
snprintf ( V_40 , sizeof V_40 , L_14 , V_37 -> V_40 ) ;
V_39 -> V_42 = F_26 ( V_40 , V_43 | V_44 ,
V_45 , V_37 , & V_46 ) ;
if ( ! V_39 -> V_42 )
F_27 ( V_39 , L_15 ) ;
snprintf ( V_40 , sizeof V_40 , L_16 , V_37 -> V_40 ) ;
V_39 -> V_47 = F_26 ( V_40 , V_43 | V_44 ,
V_45 , V_37 , & V_48 ) ;
if ( ! V_39 -> V_47 )
F_27 ( V_39 , L_17 ) ;
}
void F_28 ( struct V_36 * V_37 )
{
struct V_38 * V_39 = F_25 ( V_37 ) ;
if ( V_39 -> V_42 )
F_29 ( V_39 -> V_42 ) ;
if ( V_39 -> V_47 )
F_29 ( V_39 -> V_47 ) ;
}
int F_30 ( void )
{
V_45 = F_31 ( L_18 , NULL ) ;
return V_45 ? 0 : - V_49 ;
}
void F_32 ( void )
{
F_29 ( V_45 ) ;
}
