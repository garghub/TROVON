static inline int F_1 ( struct V_1 * V_2 , struct V_3 * V_3 )
{
int V_4 = F_2 ( V_3 ) ;
if ( V_4 )
F_3 ( V_2 , L_1 ,
V_5 , V_3 , V_4 ) ;
return V_4 ;
}
static void F_4 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
V_7 -> V_3 = F_5 ( V_2 , V_7 -> V_8 ) ;
if ( F_6 ( V_7 -> V_3 ) ) {
V_7 -> V_9 = V_10 ;
} else {
F_7 ( V_7 -> V_3 ) ;
V_7 -> V_9 = V_11 ;
F_8 ( V_2 , L_2 , V_7 -> V_8 ) ;
}
}
int F_9 ( struct V_1 * V_2 , const char * V_8 )
{
struct V_12 * V_13 = F_10 ( V_2 ) ;
struct V_6 * V_7 ;
if ( ! V_13 )
return - V_14 ;
V_7 = F_11 ( sizeof( * V_7 ) , V_15 ) ;
if ( ! V_7 ) {
F_3 ( V_2 , L_3 ) ;
return - V_16 ;
}
if ( V_8 ) {
V_7 -> V_8 = F_12 ( V_8 , V_15 ) ;
if ( ! V_7 -> V_8 ) {
F_3 ( V_2 ,
L_4 ) ;
F_13 ( V_7 ) ;
return - V_16 ;
}
}
F_4 ( V_2 , V_7 ) ;
F_14 ( & V_13 -> V_17 ) ;
F_15 ( & V_7 -> V_18 , & V_13 -> V_19 ) ;
F_16 ( & V_13 -> V_17 ) ;
return 0 ;
}
static void F_17 ( struct V_6 * V_7 )
{
if ( ! V_7 )
return;
if ( V_7 -> V_9 < V_10 ) {
if ( V_7 -> V_9 == V_20 )
F_18 ( V_7 -> V_3 ) ;
if ( V_7 -> V_9 >= V_11 ) {
F_19 ( V_7 -> V_3 ) ;
F_20 ( V_7 -> V_3 ) ;
}
}
F_13 ( V_7 -> V_8 ) ;
F_13 ( V_7 ) ;
}
void F_21 ( struct V_1 * V_2 , const char * V_8 )
{
struct V_12 * V_13 = F_10 ( V_2 ) ;
struct V_6 * V_7 ;
if ( ! V_13 )
return;
F_14 ( & V_13 -> V_17 ) ;
F_22 (ce, &psd->clock_list, node) {
if ( ! V_8 && ! V_7 -> V_8 )
goto remove;
else if ( ! V_8 || ! V_7 -> V_8 )
continue;
else if ( ! strcmp ( V_8 , V_7 -> V_8 ) )
goto remove;
}
F_16 ( & V_13 -> V_17 ) ;
return;
remove:
F_23 ( & V_7 -> V_18 ) ;
F_16 ( & V_13 -> V_17 ) ;
F_17 ( V_7 ) ;
}
void F_24 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = F_10 ( V_2 ) ;
if ( V_13 )
F_25 ( & V_13 -> V_19 ) ;
}
int F_26 ( struct V_1 * V_2 )
{
return F_27 ( V_2 ) ;
}
void F_28 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = F_10 ( V_2 ) ;
struct V_6 * V_7 , * V_21 ;
struct V_22 V_23 ;
if ( ! V_13 )
return;
F_25 ( & V_23 ) ;
F_14 ( & V_13 -> V_17 ) ;
F_29 (ce, c, &psd->clock_list, node)
F_30 ( & V_7 -> V_18 , & V_23 ) ;
F_16 ( & V_13 -> V_17 ) ;
F_31 ( V_2 ) ;
F_29 (ce, c, &list, node) {
F_23 ( & V_7 -> V_18 ) ;
F_17 ( V_7 ) ;
}
}
int F_32 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = F_10 ( V_2 ) ;
struct V_6 * V_7 ;
unsigned long V_24 ;
F_8 ( V_2 , L_5 , V_5 ) ;
if ( ! V_13 )
return 0 ;
F_33 ( & V_13 -> V_17 , V_24 ) ;
F_34 (ce, &psd->clock_list, node) {
if ( V_7 -> V_9 < V_10 ) {
if ( V_7 -> V_9 == V_20 )
F_18 ( V_7 -> V_3 ) ;
V_7 -> V_9 = V_11 ;
}
}
F_35 ( & V_13 -> V_17 , V_24 ) ;
return 0 ;
}
int F_36 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = F_10 ( V_2 ) ;
struct V_6 * V_7 ;
unsigned long V_24 ;
int V_4 ;
F_8 ( V_2 , L_5 , V_5 ) ;
if ( ! V_13 )
return 0 ;
F_33 ( & V_13 -> V_17 , V_24 ) ;
F_22 (ce, &psd->clock_list, node) {
if ( V_7 -> V_9 < V_10 ) {
V_4 = F_1 ( V_2 , V_7 -> V_3 ) ;
if ( ! V_4 )
V_7 -> V_9 = V_20 ;
}
}
F_35 ( & V_13 -> V_17 , V_24 ) ;
return 0 ;
}
static int F_37 ( struct V_25 * V_26 ,
unsigned long V_27 , void * V_28 )
{
struct V_29 * V_30 ;
struct V_1 * V_2 = V_28 ;
char * * V_8 ;
int error ;
F_8 ( V_2 , L_6 , V_5 , V_27 ) ;
V_30 = F_38 ( V_26 , struct V_29 , V_26 ) ;
switch ( V_27 ) {
case V_31 :
if ( V_2 -> V_32 )
break;
error = F_26 ( V_2 ) ;
if ( error )
break;
V_2 -> V_32 = V_30 -> V_32 ;
if ( V_30 -> V_33 [ 0 ] ) {
for ( V_8 = V_30 -> V_33 ; * V_8 ; V_8 ++ )
F_9 ( V_2 , * V_8 ) ;
} else {
F_9 ( V_2 , NULL ) ;
}
break;
case V_34 :
if ( V_2 -> V_32 != V_30 -> V_32 )
break;
V_2 -> V_32 = NULL ;
F_28 ( V_2 ) ;
break;
}
return 0 ;
}
int F_32 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = F_10 ( V_2 ) ;
struct V_6 * V_7 ;
unsigned long V_24 ;
F_8 ( V_2 , L_5 , V_5 ) ;
if ( ! V_13 || ! V_2 -> V_35 )
return 0 ;
F_33 ( & V_13 -> V_17 , V_24 ) ;
F_34 (ce, &psd->clock_list, node)
F_18 ( V_7 -> V_3 ) ;
F_35 ( & V_13 -> V_17 , V_24 ) ;
return 0 ;
}
int F_36 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = F_10 ( V_2 ) ;
struct V_6 * V_7 ;
unsigned long V_24 ;
F_8 ( V_2 , L_5 , V_5 ) ;
if ( ! V_13 || ! V_2 -> V_35 )
return 0 ;
F_33 ( & V_13 -> V_17 , V_24 ) ;
F_22 (ce, &psd->clock_list, node)
F_1 ( V_2 , V_7 -> V_3 ) ;
F_35 ( & V_13 -> V_17 , V_24 ) ;
return 0 ;
}
static void F_39 ( struct V_1 * V_2 , const char * V_8 )
{
struct V_3 * V_3 ;
V_3 = F_5 ( V_2 , V_8 ) ;
if ( ! F_6 ( V_3 ) ) {
F_40 ( V_3 ) ;
F_20 ( V_3 ) ;
F_41 ( V_2 , L_7 ) ;
}
}
static void F_42 ( struct V_1 * V_2 , const char * V_8 )
{
struct V_3 * V_3 ;
V_3 = F_5 ( V_2 , V_8 ) ;
if ( ! F_6 ( V_3 ) ) {
F_43 ( V_3 ) ;
F_20 ( V_3 ) ;
F_41 ( V_2 , L_8 ) ;
}
}
static int F_37 ( struct V_25 * V_26 ,
unsigned long V_27 , void * V_28 )
{
struct V_29 * V_30 ;
struct V_1 * V_2 = V_28 ;
char * * V_8 ;
F_8 ( V_2 , L_6 , V_5 , V_27 ) ;
V_30 = F_38 ( V_26 , struct V_29 , V_26 ) ;
switch ( V_27 ) {
case V_36 :
if ( V_30 -> V_33 [ 0 ] ) {
for ( V_8 = V_30 -> V_33 ; * V_8 ; V_8 ++ )
F_39 ( V_2 , * V_8 ) ;
} else {
F_39 ( V_2 , NULL ) ;
}
break;
case V_37 :
if ( V_30 -> V_33 [ 0 ] ) {
for ( V_8 = V_30 -> V_33 ; * V_8 ; V_8 ++ )
F_42 ( V_2 , * V_8 ) ;
} else {
F_42 ( V_2 , NULL ) ;
}
break;
}
return 0 ;
}
void F_44 ( struct V_38 * V_39 ,
struct V_29 * V_30 )
{
if ( ! V_39 || ! V_30 )
return;
V_30 -> V_26 . V_40 = F_37 ;
F_45 ( V_39 , & V_30 -> V_26 ) ;
}
