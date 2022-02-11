static inline void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_5 ;
if ( V_4 -> V_6 < V_7 ) {
V_5 = F_2 ( V_4 -> V_8 ) ;
if ( ! V_5 )
V_4 -> V_6 = V_9 ;
else
F_3 ( V_2 , L_1 ,
V_10 , V_4 -> V_8 , V_5 ) ;
}
}
static void F_4 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( ! V_4 -> V_8 )
V_4 -> V_8 = F_5 ( V_2 , V_4 -> V_11 ) ;
if ( F_6 ( V_4 -> V_8 ) ) {
V_4 -> V_6 = V_7 ;
} else {
F_7 ( V_4 -> V_8 ) ;
V_4 -> V_6 = V_12 ;
F_8 ( V_2 , L_2 ,
V_4 -> V_8 , V_4 -> V_11 ) ;
}
}
static int F_9 ( struct V_1 * V_2 , const char * V_11 ,
struct V_8 * V_8 )
{
struct V_13 * V_14 = F_10 ( V_2 ) ;
struct V_3 * V_4 ;
if ( ! V_14 )
return - V_15 ;
V_4 = F_11 ( sizeof( * V_4 ) , V_16 ) ;
if ( ! V_4 )
return - V_17 ;
if ( V_11 ) {
V_4 -> V_11 = F_12 ( V_11 , V_16 ) ;
if ( ! V_4 -> V_11 ) {
F_3 ( V_2 ,
L_3 ) ;
F_13 ( V_4 ) ;
return - V_17 ;
}
} else {
if ( F_6 ( V_8 ) ) {
F_13 ( V_4 ) ;
return - V_18 ;
}
V_4 -> V_8 = V_8 ;
}
F_4 ( V_2 , V_4 ) ;
F_14 ( & V_14 -> V_19 ) ;
F_15 ( & V_4 -> V_20 , & V_14 -> V_21 ) ;
F_16 ( & V_14 -> V_19 ) ;
return 0 ;
}
int F_17 ( struct V_1 * V_2 , const char * V_11 )
{
return F_9 ( V_2 , V_11 , NULL ) ;
}
int F_18 ( struct V_1 * V_2 , struct V_8 * V_8 )
{
return F_9 ( V_2 , NULL , V_8 ) ;
}
static void F_19 ( struct V_3 * V_4 )
{
if ( ! V_4 )
return;
if ( V_4 -> V_6 < V_7 ) {
if ( V_4 -> V_6 == V_9 )
F_20 ( V_4 -> V_8 ) ;
if ( V_4 -> V_6 >= V_12 ) {
F_21 ( V_4 -> V_8 ) ;
F_22 ( V_4 -> V_8 ) ;
}
}
F_13 ( V_4 -> V_11 ) ;
F_13 ( V_4 ) ;
}
void F_23 ( struct V_1 * V_2 , const char * V_11 )
{
struct V_13 * V_14 = F_10 ( V_2 ) ;
struct V_3 * V_4 ;
if ( ! V_14 )
return;
F_14 ( & V_14 -> V_19 ) ;
F_24 (ce, &psd->clock_list, node) {
if ( ! V_11 && ! V_4 -> V_11 )
goto remove;
else if ( ! V_11 || ! V_4 -> V_11 )
continue;
else if ( ! strcmp ( V_11 , V_4 -> V_11 ) )
goto remove;
}
F_16 ( & V_14 -> V_19 ) ;
return;
remove:
F_25 ( & V_4 -> V_20 ) ;
F_16 ( & V_14 -> V_19 ) ;
F_19 ( V_4 ) ;
}
void F_26 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = F_10 ( V_2 ) ;
if ( V_14 )
F_27 ( & V_14 -> V_21 ) ;
}
int F_28 ( struct V_1 * V_2 )
{
return F_29 ( V_2 ) ;
}
void F_30 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = F_10 ( V_2 ) ;
struct V_3 * V_4 , * V_22 ;
struct V_23 V_24 ;
if ( ! V_14 )
return;
F_27 ( & V_24 ) ;
F_14 ( & V_14 -> V_19 ) ;
F_31 (ce, c, &psd->clock_list, node)
F_32 ( & V_4 -> V_20 , & V_24 ) ;
F_16 ( & V_14 -> V_19 ) ;
F_33 ( V_2 ) ;
F_31 (ce, c, &list, node) {
F_25 ( & V_4 -> V_20 ) ;
F_19 ( V_4 ) ;
}
}
int F_34 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = F_10 ( V_2 ) ;
struct V_3 * V_4 ;
unsigned long V_25 ;
F_8 ( V_2 , L_4 , V_10 ) ;
if ( ! V_14 )
return 0 ;
F_35 ( & V_14 -> V_19 , V_25 ) ;
F_36 (ce, &psd->clock_list, node) {
if ( V_4 -> V_6 < V_7 ) {
if ( V_4 -> V_6 == V_9 )
F_20 ( V_4 -> V_8 ) ;
V_4 -> V_6 = V_12 ;
}
}
F_37 ( & V_14 -> V_19 , V_25 ) ;
return 0 ;
}
int F_38 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = F_10 ( V_2 ) ;
struct V_3 * V_4 ;
unsigned long V_25 ;
F_8 ( V_2 , L_4 , V_10 ) ;
if ( ! V_14 )
return 0 ;
F_35 ( & V_14 -> V_19 , V_25 ) ;
F_24 (ce, &psd->clock_list, node)
F_1 ( V_2 , V_4 ) ;
F_37 ( & V_14 -> V_19 , V_25 ) ;
return 0 ;
}
static int F_39 ( struct V_26 * V_27 ,
unsigned long V_28 , void * V_29 )
{
struct V_30 * V_31 ;
struct V_1 * V_2 = V_29 ;
char * * V_11 ;
int error ;
F_8 ( V_2 , L_5 , V_10 , V_28 ) ;
V_31 = F_40 ( V_27 , struct V_30 , V_27 ) ;
switch ( V_28 ) {
case V_32 :
if ( V_2 -> V_33 )
break;
error = F_28 ( V_2 ) ;
if ( error )
break;
V_2 -> V_33 = V_31 -> V_33 ;
if ( V_31 -> V_34 [ 0 ] ) {
for ( V_11 = V_31 -> V_34 ; * V_11 ; V_11 ++ )
F_17 ( V_2 , * V_11 ) ;
} else {
F_17 ( V_2 , NULL ) ;
}
break;
case V_35 :
if ( V_2 -> V_33 != V_31 -> V_33 )
break;
V_2 -> V_33 = NULL ;
F_30 ( V_2 ) ;
break;
}
return 0 ;
}
int F_41 ( struct V_1 * V_2 )
{
int V_5 ;
F_8 ( V_2 , L_6 , V_10 ) ;
V_5 = F_42 ( V_2 ) ;
if ( V_5 ) {
F_3 ( V_2 , L_7 ) ;
return V_5 ;
}
V_5 = F_34 ( V_2 ) ;
if ( V_5 ) {
F_3 ( V_2 , L_8 ) ;
F_43 ( V_2 ) ;
return V_5 ;
}
return 0 ;
}
int F_44 ( struct V_1 * V_2 )
{
int V_5 ;
F_8 ( V_2 , L_6 , V_10 ) ;
V_5 = F_38 ( V_2 ) ;
if ( V_5 ) {
F_3 ( V_2 , L_9 ) ;
return V_5 ;
}
return F_43 ( V_2 ) ;
}
static void F_45 ( struct V_1 * V_2 , const char * V_11 )
{
struct V_8 * V_8 ;
V_8 = F_5 ( V_2 , V_11 ) ;
if ( ! F_6 ( V_8 ) ) {
F_46 ( V_8 ) ;
F_22 ( V_8 ) ;
F_47 ( V_2 , L_10 ) ;
}
}
static void F_48 ( struct V_1 * V_2 , const char * V_11 )
{
struct V_8 * V_8 ;
V_8 = F_5 ( V_2 , V_11 ) ;
if ( ! F_6 ( V_8 ) ) {
F_49 ( V_8 ) ;
F_22 ( V_8 ) ;
F_47 ( V_2 , L_11 ) ;
}
}
static int F_39 ( struct V_26 * V_27 ,
unsigned long V_28 , void * V_29 )
{
struct V_30 * V_31 ;
struct V_1 * V_2 = V_29 ;
char * * V_11 ;
F_8 ( V_2 , L_5 , V_10 , V_28 ) ;
V_31 = F_40 ( V_27 , struct V_30 , V_27 ) ;
switch ( V_28 ) {
case V_36 :
if ( V_31 -> V_34 [ 0 ] ) {
for ( V_11 = V_31 -> V_34 ; * V_11 ; V_11 ++ )
F_45 ( V_2 , * V_11 ) ;
} else {
F_45 ( V_2 , NULL ) ;
}
break;
case V_37 :
if ( V_31 -> V_34 [ 0 ] ) {
for ( V_11 = V_31 -> V_34 ; * V_11 ; V_11 ++ )
F_48 ( V_2 , * V_11 ) ;
} else {
F_48 ( V_2 , NULL ) ;
}
break;
}
return 0 ;
}
void F_50 ( struct V_38 * V_39 ,
struct V_30 * V_31 )
{
if ( ! V_39 || ! V_31 )
return;
V_31 -> V_27 . V_40 = F_39 ;
F_51 ( V_39 , & V_31 -> V_27 ) ;
}
