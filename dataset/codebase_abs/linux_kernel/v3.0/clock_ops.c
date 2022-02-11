static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return V_3 ? V_3 -> V_4 . V_5 : NULL ;
}
int F_2 ( struct V_2 * V_3 , const char * V_6 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_8 * V_9 ;
if ( ! V_7 )
return - V_10 ;
V_9 = F_3 ( sizeof( * V_9 ) , V_11 ) ;
if ( ! V_9 ) {
F_4 ( V_3 , L_1 ) ;
return - V_12 ;
}
if ( V_6 ) {
V_9 -> V_6 = F_5 ( V_6 , V_11 ) ;
if ( ! V_9 -> V_6 ) {
F_4 ( V_3 ,
L_2 ) ;
F_6 ( V_9 ) ;
return - V_12 ;
}
}
F_7 ( & V_7 -> V_13 ) ;
F_8 ( & V_9 -> V_14 , & V_7 -> V_15 ) ;
F_9 ( & V_7 -> V_13 ) ;
return 0 ;
}
static void F_10 ( struct V_8 * V_9 )
{
if ( ! V_9 )
return;
F_11 ( & V_9 -> V_14 ) ;
if ( V_9 -> V_16 < V_17 ) {
if ( V_9 -> V_16 == V_18 )
F_12 ( V_9 -> V_19 ) ;
if ( V_9 -> V_16 >= V_20 )
F_13 ( V_9 -> V_19 ) ;
}
if ( V_9 -> V_6 )
F_6 ( V_9 -> V_6 ) ;
F_6 ( V_9 ) ;
}
void F_14 ( struct V_2 * V_3 , const char * V_6 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_8 * V_9 ;
if ( ! V_7 )
return;
F_7 ( & V_7 -> V_13 ) ;
F_15 (ce, &prd->clock_list, node) {
if ( ! V_6 && ! V_9 -> V_6 ) {
F_10 ( V_9 ) ;
break;
} else if ( ! V_6 || ! V_9 -> V_6 ) {
continue;
} else if ( ! strcmp ( V_6 , V_9 -> V_6 ) ) {
F_10 ( V_9 ) ;
break;
}
}
F_9 ( & V_7 -> V_13 ) ;
}
int F_16 ( struct V_2 * V_3 )
{
struct V_1 * V_7 ;
V_7 = F_3 ( sizeof( * V_7 ) , V_11 ) ;
if ( ! V_7 ) {
F_4 ( V_3 , L_3 ) ;
return - V_12 ;
}
F_17 ( & V_7 -> V_15 ) ;
F_18 ( & V_7 -> V_13 ) ;
V_3 -> V_4 . V_5 = V_7 ;
return 0 ;
}
void F_19 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_8 * V_9 , * V_21 ;
if ( ! V_7 )
return;
V_3 -> V_4 . V_5 = NULL ;
F_7 ( & V_7 -> V_13 ) ;
F_20 (ce, c, &prd->clock_list, node)
F_10 ( V_9 ) ;
F_9 ( & V_7 -> V_13 ) ;
F_6 ( V_7 ) ;
}
static void F_21 ( struct V_2 * V_3 ,
struct V_8 * V_9 )
{
V_9 -> V_19 = F_22 ( V_3 , V_9 -> V_6 ) ;
if ( F_23 ( V_9 -> V_19 ) ) {
V_9 -> V_16 = V_17 ;
} else {
V_9 -> V_16 = V_20 ;
F_24 ( V_3 , L_4 , V_9 -> V_6 ) ;
}
}
int F_25 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_8 * V_9 ;
F_24 ( V_3 , L_5 , V_22 ) ;
if ( ! V_7 )
return 0 ;
F_7 ( & V_7 -> V_13 ) ;
F_26 (ce, &prd->clock_list, node) {
if ( V_9 -> V_16 == V_23 )
F_21 ( V_3 , V_9 ) ;
if ( V_9 -> V_16 < V_17 ) {
F_12 ( V_9 -> V_19 ) ;
V_9 -> V_16 = V_20 ;
}
}
F_9 ( & V_7 -> V_13 ) ;
return 0 ;
}
int F_27 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_8 * V_9 ;
F_24 ( V_3 , L_5 , V_22 ) ;
if ( ! V_7 )
return 0 ;
F_7 ( & V_7 -> V_13 ) ;
F_15 (ce, &prd->clock_list, node) {
if ( V_9 -> V_16 == V_23 )
F_21 ( V_3 , V_9 ) ;
if ( V_9 -> V_16 < V_17 ) {
F_28 ( V_9 -> V_19 ) ;
V_9 -> V_16 = V_18 ;
}
}
F_9 ( & V_7 -> V_13 ) ;
return 0 ;
}
static int F_29 ( struct V_24 * V_25 ,
unsigned long V_26 , void * V_27 )
{
struct V_28 * V_29 ;
struct V_2 * V_3 = V_27 ;
char * * V_6 ;
int error ;
F_24 ( V_3 , L_6 , V_22 , V_26 ) ;
V_29 = F_30 ( V_25 , struct V_28 , V_25 ) ;
switch ( V_26 ) {
case V_30 :
if ( V_3 -> V_31 )
break;
error = F_16 ( V_3 ) ;
if ( error )
break;
V_3 -> V_31 = V_29 -> V_31 ;
if ( V_29 -> V_32 [ 0 ] ) {
for ( V_6 = V_29 -> V_32 ; * V_6 ; V_6 ++ )
F_2 ( V_3 , * V_6 ) ;
} else {
F_2 ( V_3 , NULL ) ;
}
break;
case V_33 :
if ( V_3 -> V_31 != V_29 -> V_31 )
break;
V_3 -> V_31 = NULL ;
F_19 ( V_3 ) ;
break;
}
return 0 ;
}
static void F_31 ( struct V_2 * V_3 , const char * V_6 )
{
struct V_19 * V_19 ;
V_19 = F_22 ( V_3 , V_6 ) ;
if ( ! F_23 ( V_19 ) ) {
F_28 ( V_19 ) ;
F_13 ( V_19 ) ;
F_32 ( V_3 , L_7 ) ;
}
}
static void F_33 ( struct V_2 * V_3 , const char * V_6 )
{
struct V_19 * V_19 ;
V_19 = F_22 ( V_3 , V_6 ) ;
if ( ! F_23 ( V_19 ) ) {
F_12 ( V_19 ) ;
F_13 ( V_19 ) ;
F_32 ( V_3 , L_8 ) ;
}
}
static int F_29 ( struct V_24 * V_25 ,
unsigned long V_26 , void * V_27 )
{
struct V_28 * V_29 ;
struct V_2 * V_3 = V_27 ;
char * * V_6 ;
F_24 ( V_3 , L_6 , V_22 , V_26 ) ;
V_29 = F_30 ( V_25 , struct V_28 , V_25 ) ;
switch ( V_26 ) {
case V_34 :
if ( V_29 -> V_32 [ 0 ] ) {
for ( V_6 = V_29 -> V_32 ; * V_6 ; V_6 ++ )
F_31 ( V_3 , * V_6 ) ;
} else {
F_31 ( V_3 , NULL ) ;
}
break;
case V_35 :
if ( V_29 -> V_32 [ 0 ] ) {
for ( V_6 = V_29 -> V_32 ; * V_6 ; V_6 ++ )
F_33 ( V_3 , * V_6 ) ;
} else {
F_33 ( V_3 , NULL ) ;
}
break;
}
return 0 ;
}
void F_34 ( struct V_36 * V_37 ,
struct V_28 * V_29 )
{
if ( ! V_37 || ! V_29 )
return;
V_29 -> V_25 . V_38 = F_29 ;
F_35 ( V_37 , & V_29 -> V_25 ) ;
}
