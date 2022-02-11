static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
V_4 -> V_5 = F_2 ( V_2 , V_4 -> V_6 ) ;
if ( F_3 ( V_4 -> V_5 ) ) {
V_4 -> V_7 = V_8 ;
} else {
V_4 -> V_7 = V_9 ;
F_4 ( V_2 , L_1 , V_4 -> V_6 ) ;
}
}
int F_5 ( struct V_1 * V_2 , const char * V_6 )
{
struct V_10 * V_11 = F_6 ( V_2 ) ;
struct V_3 * V_4 ;
if ( ! V_11 )
return - V_12 ;
V_4 = F_7 ( sizeof( * V_4 ) , V_13 ) ;
if ( ! V_4 ) {
F_8 ( V_2 , L_2 ) ;
return - V_14 ;
}
if ( V_6 ) {
V_4 -> V_6 = F_9 ( V_6 , V_13 ) ;
if ( ! V_4 -> V_6 ) {
F_8 ( V_2 ,
L_3 ) ;
F_10 ( V_4 ) ;
return - V_14 ;
}
}
F_1 ( V_2 , V_4 ) ;
F_11 ( & V_11 -> V_15 ) ;
F_12 ( & V_4 -> V_16 , & V_11 -> V_17 ) ;
F_13 ( & V_11 -> V_15 ) ;
return 0 ;
}
static void F_14 ( struct V_3 * V_4 )
{
if ( ! V_4 )
return;
if ( V_4 -> V_7 < V_8 ) {
if ( V_4 -> V_7 == V_18 )
F_15 ( V_4 -> V_5 ) ;
if ( V_4 -> V_7 >= V_9 )
F_16 ( V_4 -> V_5 ) ;
}
F_10 ( V_4 -> V_6 ) ;
F_10 ( V_4 ) ;
}
void F_17 ( struct V_1 * V_2 , const char * V_6 )
{
struct V_10 * V_11 = F_6 ( V_2 ) ;
struct V_3 * V_4 ;
if ( ! V_11 )
return;
F_11 ( & V_11 -> V_15 ) ;
F_18 (ce, &psd->clock_list, node) {
if ( ! V_6 && ! V_4 -> V_6 )
goto remove;
else if ( ! V_6 || ! V_4 -> V_6 )
continue;
else if ( ! strcmp ( V_6 , V_4 -> V_6 ) )
goto remove;
}
F_13 ( & V_11 -> V_15 ) ;
return;
remove:
F_19 ( & V_4 -> V_16 ) ;
F_13 ( & V_11 -> V_15 ) ;
F_14 ( V_4 ) ;
}
void F_20 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_6 ( V_2 ) ;
if ( V_11 )
F_21 ( & V_11 -> V_17 ) ;
}
int F_22 ( struct V_1 * V_2 )
{
return F_23 ( V_2 ) ;
}
void F_24 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_6 ( V_2 ) ;
struct V_3 * V_4 , * V_19 ;
struct V_20 V_21 ;
if ( ! V_11 )
return;
F_21 ( & V_21 ) ;
F_11 ( & V_11 -> V_15 ) ;
F_25 (ce, c, &psd->clock_list, node)
F_26 ( & V_4 -> V_16 , & V_21 ) ;
F_13 ( & V_11 -> V_15 ) ;
F_27 ( V_2 ) ;
F_25 (ce, c, &list, node) {
F_19 ( & V_4 -> V_16 ) ;
F_14 ( V_4 ) ;
}
}
int F_28 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_6 ( V_2 ) ;
struct V_3 * V_4 ;
unsigned long V_22 ;
F_4 ( V_2 , L_4 , V_23 ) ;
if ( ! V_11 )
return 0 ;
F_29 ( & V_11 -> V_15 , V_22 ) ;
F_30 (ce, &psd->clock_list, node) {
if ( V_4 -> V_7 < V_8 ) {
if ( V_4 -> V_7 == V_18 )
F_31 ( V_4 -> V_5 ) ;
V_4 -> V_7 = V_9 ;
}
}
F_32 ( & V_11 -> V_15 , V_22 ) ;
return 0 ;
}
int F_33 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_6 ( V_2 ) ;
struct V_3 * V_4 ;
unsigned long V_22 ;
F_4 ( V_2 , L_4 , V_23 ) ;
if ( ! V_11 )
return 0 ;
F_29 ( & V_11 -> V_15 , V_22 ) ;
F_18 (ce, &psd->clock_list, node) {
if ( V_4 -> V_7 < V_8 ) {
F_34 ( V_4 -> V_5 ) ;
V_4 -> V_7 = V_18 ;
}
}
F_32 ( & V_11 -> V_15 , V_22 ) ;
return 0 ;
}
static int F_35 ( struct V_24 * V_25 ,
unsigned long V_26 , void * V_27 )
{
struct V_28 * V_29 ;
struct V_1 * V_2 = V_27 ;
char * * V_6 ;
int error ;
F_4 ( V_2 , L_5 , V_23 , V_26 ) ;
V_29 = F_36 ( V_25 , struct V_28 , V_25 ) ;
switch ( V_26 ) {
case V_30 :
if ( V_2 -> V_31 )
break;
error = F_22 ( V_2 ) ;
if ( error )
break;
V_2 -> V_31 = V_29 -> V_31 ;
if ( V_29 -> V_32 [ 0 ] ) {
for ( V_6 = V_29 -> V_32 ; * V_6 ; V_6 ++ )
F_5 ( V_2 , * V_6 ) ;
} else {
F_5 ( V_2 , NULL ) ;
}
break;
case V_33 :
if ( V_2 -> V_31 != V_29 -> V_31 )
break;
V_2 -> V_31 = NULL ;
F_24 ( V_2 ) ;
break;
}
return 0 ;
}
int F_28 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_6 ( V_2 ) ;
struct V_3 * V_4 ;
unsigned long V_22 ;
F_4 ( V_2 , L_4 , V_23 ) ;
if ( ! V_11 || ! V_2 -> V_34 )
return 0 ;
F_29 ( & V_11 -> V_15 , V_22 ) ;
F_30 (ce, &psd->clock_list, node)
F_31 ( V_4 -> V_5 ) ;
F_32 ( & V_11 -> V_15 , V_22 ) ;
return 0 ;
}
int F_33 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_6 ( V_2 ) ;
struct V_3 * V_4 ;
unsigned long V_22 ;
F_4 ( V_2 , L_4 , V_23 ) ;
if ( ! V_11 || ! V_2 -> V_34 )
return 0 ;
F_29 ( & V_11 -> V_15 , V_22 ) ;
F_18 (ce, &psd->clock_list, node)
F_34 ( V_4 -> V_5 ) ;
F_32 ( & V_11 -> V_15 , V_22 ) ;
return 0 ;
}
static void F_37 ( struct V_1 * V_2 , const char * V_6 )
{
struct V_5 * V_5 ;
V_5 = F_2 ( V_2 , V_6 ) ;
if ( ! F_3 ( V_5 ) ) {
F_38 ( V_5 ) ;
F_16 ( V_5 ) ;
F_39 ( V_2 , L_6 ) ;
}
}
static void F_40 ( struct V_1 * V_2 , const char * V_6 )
{
struct V_5 * V_5 ;
V_5 = F_2 ( V_2 , V_6 ) ;
if ( ! F_3 ( V_5 ) ) {
F_15 ( V_5 ) ;
F_16 ( V_5 ) ;
F_39 ( V_2 , L_7 ) ;
}
}
static int F_35 ( struct V_24 * V_25 ,
unsigned long V_26 , void * V_27 )
{
struct V_28 * V_29 ;
struct V_1 * V_2 = V_27 ;
char * * V_6 ;
F_4 ( V_2 , L_5 , V_23 , V_26 ) ;
V_29 = F_36 ( V_25 , struct V_28 , V_25 ) ;
switch ( V_26 ) {
case V_35 :
if ( V_29 -> V_32 [ 0 ] ) {
for ( V_6 = V_29 -> V_32 ; * V_6 ; V_6 ++ )
F_37 ( V_2 , * V_6 ) ;
} else {
F_37 ( V_2 , NULL ) ;
}
break;
case V_36 :
if ( V_29 -> V_32 [ 0 ] ) {
for ( V_6 = V_29 -> V_32 ; * V_6 ; V_6 ++ )
F_40 ( V_2 , * V_6 ) ;
} else {
F_40 ( V_2 , NULL ) ;
}
break;
}
return 0 ;
}
void F_41 ( struct V_37 * V_38 ,
struct V_28 * V_29 )
{
if ( ! V_38 || ! V_29 )
return;
V_29 -> V_25 . V_39 = F_35 ;
F_42 ( V_38 , & V_29 -> V_25 ) ;
}
