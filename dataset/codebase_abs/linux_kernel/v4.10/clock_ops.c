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
int F_19 ( struct V_1 * V_2 , const char * V_22 )
{
struct V_8 * V_8 ;
int V_5 ;
if ( ! V_2 || ! V_2 -> V_23 || ! V_22 )
return - V_15 ;
V_8 = F_20 ( V_2 -> V_23 , V_22 ) ;
if ( F_6 ( V_8 ) )
return F_21 ( V_8 ) ;
V_5 = F_18 ( V_2 , V_8 ) ;
if ( V_5 ) {
F_22 ( V_8 ) ;
return V_5 ;
}
return 0 ;
}
int F_23 ( struct V_1 * V_2 )
{
struct V_8 * * V_24 ;
unsigned int V_25 , V_26 ;
int V_5 ;
if ( ! V_2 || ! V_2 -> V_23 )
return - V_15 ;
V_26 = F_24 ( V_2 -> V_23 , L_4 ,
L_5 ) ;
if ( V_26 <= 0 )
return - V_27 ;
V_24 = F_25 ( V_26 , sizeof( * V_24 ) , V_16 ) ;
if ( ! V_24 )
return - V_17 ;
for ( V_25 = 0 ; V_25 < V_26 ; V_25 ++ ) {
V_24 [ V_25 ] = F_26 ( V_2 -> V_23 , V_25 ) ;
if ( F_6 ( V_24 [ V_25 ] ) ) {
V_5 = F_21 ( V_24 [ V_25 ] ) ;
goto error;
}
V_5 = F_18 ( V_2 , V_24 [ V_25 ] ) ;
if ( V_5 ) {
F_22 ( V_24 [ V_25 ] ) ;
goto error;
}
}
F_13 ( V_24 ) ;
return V_25 ;
error:
while ( V_25 -- )
F_27 ( V_2 , V_24 [ V_25 ] ) ;
F_13 ( V_24 ) ;
return V_5 ;
}
static void F_28 ( struct V_3 * V_4 )
{
if ( ! V_4 )
return;
if ( V_4 -> V_6 < V_7 ) {
if ( V_4 -> V_6 == V_9 )
F_29 ( V_4 -> V_8 ) ;
if ( V_4 -> V_6 >= V_12 ) {
F_30 ( V_4 -> V_8 ) ;
F_22 ( V_4 -> V_8 ) ;
}
}
F_13 ( V_4 -> V_11 ) ;
F_13 ( V_4 ) ;
}
void F_31 ( struct V_1 * V_2 , const char * V_11 )
{
struct V_13 * V_14 = F_10 ( V_2 ) ;
struct V_3 * V_4 ;
if ( ! V_14 )
return;
F_14 ( & V_14 -> V_19 ) ;
F_32 (ce, &psd->clock_list, node) {
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
F_33 ( & V_4 -> V_20 ) ;
F_16 ( & V_14 -> V_19 ) ;
F_28 ( V_4 ) ;
}
void F_27 ( struct V_1 * V_2 , struct V_8 * V_8 )
{
struct V_13 * V_14 = F_10 ( V_2 ) ;
struct V_3 * V_4 ;
if ( ! V_14 || ! V_8 )
return;
F_14 ( & V_14 -> V_19 ) ;
F_32 (ce, &psd->clock_list, node) {
if ( V_8 == V_4 -> V_8 )
goto remove;
}
F_16 ( & V_14 -> V_19 ) ;
return;
remove:
F_33 ( & V_4 -> V_20 ) ;
F_16 ( & V_14 -> V_19 ) ;
F_28 ( V_4 ) ;
}
void F_34 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = F_10 ( V_2 ) ;
if ( V_14 )
F_35 ( & V_14 -> V_21 ) ;
}
int F_36 ( struct V_1 * V_2 )
{
return F_37 ( V_2 ) ;
}
void F_38 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = F_10 ( V_2 ) ;
struct V_3 * V_4 , * V_28 ;
struct V_29 V_30 ;
if ( ! V_14 )
return;
F_35 ( & V_30 ) ;
F_14 ( & V_14 -> V_19 ) ;
F_39 (ce, c, &psd->clock_list, node)
F_40 ( & V_4 -> V_20 , & V_30 ) ;
F_16 ( & V_14 -> V_19 ) ;
F_41 ( V_2 ) ;
F_39 (ce, c, &list, node) {
F_33 ( & V_4 -> V_20 ) ;
F_28 ( V_4 ) ;
}
}
int F_42 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = F_10 ( V_2 ) ;
struct V_3 * V_4 ;
unsigned long V_31 ;
F_8 ( V_2 , L_6 , V_10 ) ;
if ( ! V_14 )
return 0 ;
F_43 ( & V_14 -> V_19 , V_31 ) ;
F_44 (ce, &psd->clock_list, node) {
if ( V_4 -> V_6 < V_7 ) {
if ( V_4 -> V_6 == V_9 )
F_29 ( V_4 -> V_8 ) ;
V_4 -> V_6 = V_12 ;
}
}
F_45 ( & V_14 -> V_19 , V_31 ) ;
return 0 ;
}
int F_46 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = F_10 ( V_2 ) ;
struct V_3 * V_4 ;
unsigned long V_31 ;
F_8 ( V_2 , L_6 , V_10 ) ;
if ( ! V_14 )
return 0 ;
F_43 ( & V_14 -> V_19 , V_31 ) ;
F_32 (ce, &psd->clock_list, node)
F_1 ( V_2 , V_4 ) ;
F_45 ( & V_14 -> V_19 , V_31 ) ;
return 0 ;
}
static int F_47 ( struct V_32 * V_33 ,
unsigned long V_34 , void * V_35 )
{
struct V_36 * V_37 ;
struct V_1 * V_2 = V_35 ;
char * * V_11 ;
int error ;
F_8 ( V_2 , L_7 , V_10 , V_34 ) ;
V_37 = F_48 ( V_33 , struct V_36 , V_33 ) ;
switch ( V_34 ) {
case V_38 :
if ( V_2 -> V_39 )
break;
error = F_36 ( V_2 ) ;
if ( error )
break;
F_49 ( V_2 , V_37 -> V_39 ) ;
if ( V_37 -> V_40 [ 0 ] ) {
for ( V_11 = V_37 -> V_40 ; * V_11 ; V_11 ++ )
F_17 ( V_2 , * V_11 ) ;
} else {
F_17 ( V_2 , NULL ) ;
}
break;
case V_41 :
if ( V_2 -> V_39 != V_37 -> V_39 )
break;
F_49 ( V_2 , NULL ) ;
F_38 ( V_2 ) ;
break;
}
return 0 ;
}
int F_50 ( struct V_1 * V_2 )
{
int V_5 ;
F_8 ( V_2 , L_8 , V_10 ) ;
V_5 = F_51 ( V_2 ) ;
if ( V_5 ) {
F_3 ( V_2 , L_9 ) ;
return V_5 ;
}
V_5 = F_42 ( V_2 ) ;
if ( V_5 ) {
F_3 ( V_2 , L_10 ) ;
F_52 ( V_2 ) ;
return V_5 ;
}
return 0 ;
}
int F_53 ( struct V_1 * V_2 )
{
int V_5 ;
F_8 ( V_2 , L_8 , V_10 ) ;
V_5 = F_46 ( V_2 ) ;
if ( V_5 ) {
F_3 ( V_2 , L_11 ) ;
return V_5 ;
}
return F_52 ( V_2 ) ;
}
static void F_54 ( struct V_1 * V_2 , const char * V_11 )
{
struct V_8 * V_8 ;
V_8 = F_5 ( V_2 , V_11 ) ;
if ( ! F_6 ( V_8 ) ) {
F_55 ( V_8 ) ;
F_22 ( V_8 ) ;
F_56 ( V_2 , L_12 ) ;
}
}
static void F_57 ( struct V_1 * V_2 , const char * V_11 )
{
struct V_8 * V_8 ;
V_8 = F_5 ( V_2 , V_11 ) ;
if ( ! F_6 ( V_8 ) ) {
F_58 ( V_8 ) ;
F_22 ( V_8 ) ;
F_56 ( V_2 , L_13 ) ;
}
}
static int F_47 ( struct V_32 * V_33 ,
unsigned long V_34 , void * V_35 )
{
struct V_36 * V_37 ;
struct V_1 * V_2 = V_35 ;
char * * V_11 ;
F_8 ( V_2 , L_7 , V_10 , V_34 ) ;
V_37 = F_48 ( V_33 , struct V_36 , V_33 ) ;
switch ( V_34 ) {
case V_42 :
if ( V_37 -> V_40 [ 0 ] ) {
for ( V_11 = V_37 -> V_40 ; * V_11 ; V_11 ++ )
F_54 ( V_2 , * V_11 ) ;
} else {
F_54 ( V_2 , NULL ) ;
}
break;
case V_43 :
case V_44 :
if ( V_37 -> V_40 [ 0 ] ) {
for ( V_11 = V_37 -> V_40 ; * V_11 ; V_11 ++ )
F_57 ( V_2 , * V_11 ) ;
} else {
F_57 ( V_2 , NULL ) ;
}
break;
}
return 0 ;
}
void F_59 ( struct V_45 * V_46 ,
struct V_36 * V_37 )
{
if ( ! V_46 || ! V_37 )
return;
V_37 -> V_33 . V_47 = F_47 ;
F_60 ( V_46 , & V_37 -> V_33 ) ;
}
