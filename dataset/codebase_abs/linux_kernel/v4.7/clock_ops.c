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
int F_19 ( struct V_1 * V_2 )
{
struct V_8 * * V_22 ;
unsigned int V_23 , V_24 ;
int V_5 ;
if ( ! V_2 || ! V_2 -> V_25 )
return - V_15 ;
V_24 = F_20 ( V_2 -> V_25 , L_4 ,
L_5 ) ;
if ( V_24 <= 0 )
return - V_26 ;
V_22 = F_21 ( V_24 , sizeof( * V_22 ) , V_16 ) ;
if ( ! V_22 )
return - V_17 ;
for ( V_23 = 0 ; V_23 < V_24 ; V_23 ++ ) {
V_22 [ V_23 ] = F_22 ( V_2 -> V_25 , V_23 ) ;
if ( F_6 ( V_22 [ V_23 ] ) ) {
V_5 = F_23 ( V_22 [ V_23 ] ) ;
goto error;
}
V_5 = F_18 ( V_2 , V_22 [ V_23 ] ) ;
if ( V_5 ) {
F_24 ( V_22 [ V_23 ] ) ;
goto error;
}
}
F_13 ( V_22 ) ;
return V_23 ;
error:
while ( V_23 -- )
F_25 ( V_2 , V_22 [ V_23 ] ) ;
F_13 ( V_22 ) ;
return V_5 ;
}
static void F_26 ( struct V_3 * V_4 )
{
if ( ! V_4 )
return;
if ( V_4 -> V_6 < V_7 ) {
if ( V_4 -> V_6 == V_9 )
F_27 ( V_4 -> V_8 ) ;
if ( V_4 -> V_6 >= V_12 ) {
F_28 ( V_4 -> V_8 ) ;
F_24 ( V_4 -> V_8 ) ;
}
}
F_13 ( V_4 -> V_11 ) ;
F_13 ( V_4 ) ;
}
void F_29 ( struct V_1 * V_2 , const char * V_11 )
{
struct V_13 * V_14 = F_10 ( V_2 ) ;
struct V_3 * V_4 ;
if ( ! V_14 )
return;
F_14 ( & V_14 -> V_19 ) ;
F_30 (ce, &psd->clock_list, node) {
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
F_31 ( & V_4 -> V_20 ) ;
F_16 ( & V_14 -> V_19 ) ;
F_26 ( V_4 ) ;
}
void F_25 ( struct V_1 * V_2 , struct V_8 * V_8 )
{
struct V_13 * V_14 = F_10 ( V_2 ) ;
struct V_3 * V_4 ;
if ( ! V_14 || ! V_8 )
return;
F_14 ( & V_14 -> V_19 ) ;
F_30 (ce, &psd->clock_list, node) {
if ( V_8 == V_4 -> V_8 )
goto remove;
}
F_16 ( & V_14 -> V_19 ) ;
return;
remove:
F_31 ( & V_4 -> V_20 ) ;
F_16 ( & V_14 -> V_19 ) ;
F_26 ( V_4 ) ;
}
void F_32 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = F_10 ( V_2 ) ;
if ( V_14 )
F_33 ( & V_14 -> V_21 ) ;
}
int F_34 ( struct V_1 * V_2 )
{
return F_35 ( V_2 ) ;
}
void F_36 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = F_10 ( V_2 ) ;
struct V_3 * V_4 , * V_27 ;
struct V_28 V_29 ;
if ( ! V_14 )
return;
F_33 ( & V_29 ) ;
F_14 ( & V_14 -> V_19 ) ;
F_37 (ce, c, &psd->clock_list, node)
F_38 ( & V_4 -> V_20 , & V_29 ) ;
F_16 ( & V_14 -> V_19 ) ;
F_39 ( V_2 ) ;
F_37 (ce, c, &list, node) {
F_31 ( & V_4 -> V_20 ) ;
F_26 ( V_4 ) ;
}
}
int F_40 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = F_10 ( V_2 ) ;
struct V_3 * V_4 ;
unsigned long V_30 ;
F_8 ( V_2 , L_6 , V_10 ) ;
if ( ! V_14 )
return 0 ;
F_41 ( & V_14 -> V_19 , V_30 ) ;
F_42 (ce, &psd->clock_list, node) {
if ( V_4 -> V_6 < V_7 ) {
if ( V_4 -> V_6 == V_9 )
F_27 ( V_4 -> V_8 ) ;
V_4 -> V_6 = V_12 ;
}
}
F_43 ( & V_14 -> V_19 , V_30 ) ;
return 0 ;
}
int F_44 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = F_10 ( V_2 ) ;
struct V_3 * V_4 ;
unsigned long V_30 ;
F_8 ( V_2 , L_6 , V_10 ) ;
if ( ! V_14 )
return 0 ;
F_41 ( & V_14 -> V_19 , V_30 ) ;
F_30 (ce, &psd->clock_list, node)
F_1 ( V_2 , V_4 ) ;
F_43 ( & V_14 -> V_19 , V_30 ) ;
return 0 ;
}
static int F_45 ( struct V_31 * V_32 ,
unsigned long V_33 , void * V_34 )
{
struct V_35 * V_36 ;
struct V_1 * V_2 = V_34 ;
char * * V_11 ;
int error ;
F_8 ( V_2 , L_7 , V_10 , V_33 ) ;
V_36 = F_46 ( V_32 , struct V_35 , V_32 ) ;
switch ( V_33 ) {
case V_37 :
if ( V_2 -> V_38 )
break;
error = F_34 ( V_2 ) ;
if ( error )
break;
F_47 ( V_2 , V_36 -> V_38 ) ;
if ( V_36 -> V_39 [ 0 ] ) {
for ( V_11 = V_36 -> V_39 ; * V_11 ; V_11 ++ )
F_17 ( V_2 , * V_11 ) ;
} else {
F_17 ( V_2 , NULL ) ;
}
break;
case V_40 :
if ( V_2 -> V_38 != V_36 -> V_38 )
break;
F_47 ( V_2 , NULL ) ;
F_36 ( V_2 ) ;
break;
}
return 0 ;
}
int F_48 ( struct V_1 * V_2 )
{
int V_5 ;
F_8 ( V_2 , L_8 , V_10 ) ;
V_5 = F_49 ( V_2 ) ;
if ( V_5 ) {
F_3 ( V_2 , L_9 ) ;
return V_5 ;
}
V_5 = F_40 ( V_2 ) ;
if ( V_5 ) {
F_3 ( V_2 , L_10 ) ;
F_50 ( V_2 ) ;
return V_5 ;
}
return 0 ;
}
int F_51 ( struct V_1 * V_2 )
{
int V_5 ;
F_8 ( V_2 , L_8 , V_10 ) ;
V_5 = F_44 ( V_2 ) ;
if ( V_5 ) {
F_3 ( V_2 , L_11 ) ;
return V_5 ;
}
return F_50 ( V_2 ) ;
}
static void F_52 ( struct V_1 * V_2 , const char * V_11 )
{
struct V_8 * V_8 ;
V_8 = F_5 ( V_2 , V_11 ) ;
if ( ! F_6 ( V_8 ) ) {
F_53 ( V_8 ) ;
F_24 ( V_8 ) ;
F_54 ( V_2 , L_12 ) ;
}
}
static void F_55 ( struct V_1 * V_2 , const char * V_11 )
{
struct V_8 * V_8 ;
V_8 = F_5 ( V_2 , V_11 ) ;
if ( ! F_6 ( V_8 ) ) {
F_56 ( V_8 ) ;
F_24 ( V_8 ) ;
F_54 ( V_2 , L_13 ) ;
}
}
static int F_45 ( struct V_31 * V_32 ,
unsigned long V_33 , void * V_34 )
{
struct V_35 * V_36 ;
struct V_1 * V_2 = V_34 ;
char * * V_11 ;
F_8 ( V_2 , L_7 , V_10 , V_33 ) ;
V_36 = F_46 ( V_32 , struct V_35 , V_32 ) ;
switch ( V_33 ) {
case V_41 :
if ( V_36 -> V_39 [ 0 ] ) {
for ( V_11 = V_36 -> V_39 ; * V_11 ; V_11 ++ )
F_52 ( V_2 , * V_11 ) ;
} else {
F_52 ( V_2 , NULL ) ;
}
break;
case V_42 :
case V_43 :
if ( V_36 -> V_39 [ 0 ] ) {
for ( V_11 = V_36 -> V_39 ; * V_11 ; V_11 ++ )
F_55 ( V_2 , * V_11 ) ;
} else {
F_55 ( V_2 , NULL ) ;
}
break;
}
return 0 ;
}
void F_57 ( struct V_44 * V_45 ,
struct V_35 * V_36 )
{
if ( ! V_45 || ! V_36 )
return;
V_36 -> V_32 . V_46 = F_45 ;
F_58 ( V_45 , & V_36 -> V_32 ) ;
}
