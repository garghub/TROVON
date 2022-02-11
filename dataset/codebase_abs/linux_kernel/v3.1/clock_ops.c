static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return V_3 ? V_3 -> V_4 . V_5 : NULL ;
}
static void F_2 ( struct V_2 * V_3 , struct V_6 * V_7 )
{
V_7 -> V_8 = F_3 ( V_3 , V_7 -> V_9 ) ;
if ( F_4 ( V_7 -> V_8 ) ) {
V_7 -> V_10 = V_11 ;
} else {
V_7 -> V_10 = V_12 ;
F_5 ( V_3 , L_1 , V_7 -> V_9 ) ;
}
}
int F_6 ( struct V_2 * V_3 , const char * V_9 )
{
struct V_1 * V_13 = F_1 ( V_3 ) ;
struct V_6 * V_7 ;
if ( ! V_13 )
return - V_14 ;
V_7 = F_7 ( sizeof( * V_7 ) , V_15 ) ;
if ( ! V_7 ) {
F_8 ( V_3 , L_2 ) ;
return - V_16 ;
}
if ( V_9 ) {
V_7 -> V_9 = F_9 ( V_9 , V_15 ) ;
if ( ! V_7 -> V_9 ) {
F_8 ( V_3 ,
L_3 ) ;
F_10 ( V_7 ) ;
return - V_16 ;
}
}
F_2 ( V_3 , V_7 ) ;
F_11 ( & V_13 -> V_17 ) ;
F_12 ( & V_7 -> V_18 , & V_13 -> V_19 ) ;
F_13 ( & V_13 -> V_17 ) ;
return 0 ;
}
static void F_14 ( struct V_6 * V_7 )
{
if ( ! V_7 )
return;
if ( V_7 -> V_10 < V_11 ) {
if ( V_7 -> V_10 == V_20 )
F_15 ( V_7 -> V_8 ) ;
if ( V_7 -> V_10 >= V_12 )
F_16 ( V_7 -> V_8 ) ;
}
if ( V_7 -> V_9 )
F_10 ( V_7 -> V_9 ) ;
F_10 ( V_7 ) ;
}
void F_17 ( struct V_2 * V_3 , const char * V_9 )
{
struct V_1 * V_13 = F_1 ( V_3 ) ;
struct V_6 * V_7 ;
if ( ! V_13 )
return;
F_11 ( & V_13 -> V_17 ) ;
F_18 (ce, &pcd->clock_list, node) {
if ( ! V_9 && ! V_7 -> V_9 )
goto remove;
else if ( ! V_9 || ! V_7 -> V_9 )
continue;
else if ( ! strcmp ( V_9 , V_7 -> V_9 ) )
goto remove;
}
F_13 ( & V_13 -> V_17 ) ;
return;
remove:
F_19 ( & V_7 -> V_18 ) ;
F_13 ( & V_13 -> V_17 ) ;
F_14 ( V_7 ) ;
}
int F_20 ( struct V_2 * V_3 )
{
struct V_1 * V_13 ;
V_13 = F_7 ( sizeof( * V_13 ) , V_15 ) ;
if ( ! V_13 ) {
F_8 ( V_3 , L_4 ) ;
return - V_16 ;
}
F_21 ( & V_13 -> V_19 ) ;
F_22 ( & V_13 -> V_17 ) ;
V_3 -> V_4 . V_5 = V_13 ;
return 0 ;
}
void F_23 ( struct V_2 * V_3 )
{
struct V_1 * V_13 = F_1 ( V_3 ) ;
struct V_6 * V_7 , * V_21 ;
struct V_22 V_23 ;
if ( ! V_13 )
return;
V_3 -> V_4 . V_5 = NULL ;
F_21 ( & V_23 ) ;
F_11 ( & V_13 -> V_17 ) ;
F_24 (ce, c, &pcd->clock_list, node)
F_25 ( & V_7 -> V_18 , & V_23 ) ;
F_13 ( & V_13 -> V_17 ) ;
F_10 ( V_13 ) ;
F_24 (ce, c, &list, node) {
F_19 ( & V_7 -> V_18 ) ;
F_14 ( V_7 ) ;
}
}
int F_26 ( struct V_2 * V_3 )
{
struct V_1 * V_13 = F_1 ( V_3 ) ;
struct V_6 * V_7 ;
unsigned long V_24 ;
F_5 ( V_3 , L_5 , V_25 ) ;
if ( ! V_13 )
return 0 ;
F_27 ( & V_13 -> V_17 , V_24 ) ;
F_28 (ce, &pcd->clock_list, node) {
if ( V_7 -> V_10 < V_11 ) {
F_15 ( V_7 -> V_8 ) ;
V_7 -> V_10 = V_12 ;
}
}
F_29 ( & V_13 -> V_17 , V_24 ) ;
return 0 ;
}
int F_30 ( struct V_2 * V_3 )
{
struct V_1 * V_13 = F_1 ( V_3 ) ;
struct V_6 * V_7 ;
unsigned long V_24 ;
F_5 ( V_3 , L_5 , V_25 ) ;
if ( ! V_13 )
return 0 ;
F_27 ( & V_13 -> V_17 , V_24 ) ;
F_18 (ce, &pcd->clock_list, node) {
if ( V_7 -> V_10 < V_11 ) {
F_31 ( V_7 -> V_8 ) ;
V_7 -> V_10 = V_20 ;
}
}
F_29 ( & V_13 -> V_17 , V_24 ) ;
return 0 ;
}
static int F_32 ( struct V_26 * V_27 ,
unsigned long V_28 , void * V_29 )
{
struct V_30 * V_31 ;
struct V_2 * V_3 = V_29 ;
char * * V_9 ;
int error ;
F_5 ( V_3 , L_6 , V_25 , V_28 ) ;
V_31 = F_33 ( V_27 , struct V_30 , V_27 ) ;
switch ( V_28 ) {
case V_32 :
if ( V_3 -> V_33 )
break;
error = F_20 ( V_3 ) ;
if ( error )
break;
V_3 -> V_33 = V_31 -> V_33 ;
if ( V_31 -> V_34 [ 0 ] ) {
for ( V_9 = V_31 -> V_34 ; * V_9 ; V_9 ++ )
F_6 ( V_3 , * V_9 ) ;
} else {
F_6 ( V_3 , NULL ) ;
}
break;
case V_35 :
if ( V_3 -> V_33 != V_31 -> V_33 )
break;
V_3 -> V_33 = NULL ;
F_23 ( V_3 ) ;
break;
}
return 0 ;
}
int F_26 ( struct V_2 * V_3 )
{
struct V_1 * V_13 = F_1 ( V_3 ) ;
struct V_6 * V_7 ;
unsigned long V_24 ;
F_5 ( V_3 , L_5 , V_25 ) ;
if ( ! V_13 || ! V_3 -> V_36 )
return 0 ;
F_27 ( & V_13 -> V_17 , V_24 ) ;
F_28 (ce, &pcd->clock_list, node)
F_15 ( V_7 -> V_8 ) ;
F_29 ( & V_13 -> V_17 , V_24 ) ;
return 0 ;
}
int F_30 ( struct V_2 * V_3 )
{
struct V_1 * V_13 = F_1 ( V_3 ) ;
struct V_6 * V_7 ;
unsigned long V_24 ;
F_5 ( V_3 , L_5 , V_25 ) ;
if ( ! V_13 || ! V_3 -> V_36 )
return 0 ;
F_27 ( & V_13 -> V_17 , V_24 ) ;
F_18 (ce, &pcd->clock_list, node)
F_31 ( V_7 -> V_8 ) ;
F_29 ( & V_13 -> V_17 , V_24 ) ;
return 0 ;
}
static void F_34 ( struct V_2 * V_3 , const char * V_9 )
{
struct V_8 * V_8 ;
V_8 = F_3 ( V_3 , V_9 ) ;
if ( ! F_4 ( V_8 ) ) {
F_31 ( V_8 ) ;
F_16 ( V_8 ) ;
F_35 ( V_3 , L_7 ) ;
}
}
static void F_36 ( struct V_2 * V_3 , const char * V_9 )
{
struct V_8 * V_8 ;
V_8 = F_3 ( V_3 , V_9 ) ;
if ( ! F_4 ( V_8 ) ) {
F_15 ( V_8 ) ;
F_16 ( V_8 ) ;
F_35 ( V_3 , L_8 ) ;
}
}
static int F_32 ( struct V_26 * V_27 ,
unsigned long V_28 , void * V_29 )
{
struct V_30 * V_31 ;
struct V_2 * V_3 = V_29 ;
char * * V_9 ;
F_5 ( V_3 , L_6 , V_25 , V_28 ) ;
V_31 = F_33 ( V_27 , struct V_30 , V_27 ) ;
switch ( V_28 ) {
case V_37 :
if ( V_31 -> V_34 [ 0 ] ) {
for ( V_9 = V_31 -> V_34 ; * V_9 ; V_9 ++ )
F_34 ( V_3 , * V_9 ) ;
} else {
F_34 ( V_3 , NULL ) ;
}
break;
case V_38 :
if ( V_31 -> V_34 [ 0 ] ) {
for ( V_9 = V_31 -> V_34 ; * V_9 ; V_9 ++ )
F_36 ( V_3 , * V_9 ) ;
} else {
F_36 ( V_3 , NULL ) ;
}
break;
}
return 0 ;
}
void F_37 ( struct V_39 * V_40 ,
struct V_30 * V_31 )
{
if ( ! V_40 || ! V_31 )
return;
V_31 -> V_27 . V_41 = F_32 ;
F_38 ( V_40 , & V_31 -> V_27 ) ;
}
