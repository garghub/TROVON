int F_1 ( struct V_1 * V_2 )
{
const struct V_3 * V_4 = V_2 -> V_5 -> V_6 ;
if ( ! V_4 -> V_7 && ! V_4 -> V_8 )
return - V_9 ;
if ( ! V_4 -> V_10 && ! V_4 -> V_11 )
return - V_9 ;
return 0 ;
}
int F_2 ( struct V_12 const * V_13 , int V_14 )
{
if ( ! V_13 -> V_15 . V_16 . V_17 ) {
F_3 ( L_1 ,
V_13 -> V_18 , V_14 ) ;
return - V_9 ;
}
if ( V_13 -> V_15 . V_16 . V_19 &&
! V_13 -> V_15 . V_16 . V_16 ) {
F_3 ( L_2 ,
V_13 -> V_18 , V_14 ) ;
return - V_9 ;
}
return 0 ;
}
int F_4 ( struct V_1 * V_2 , unsigned V_20 ,
unsigned long * V_21 )
{
const struct V_3 * V_4 = V_2 -> V_5 -> V_6 ;
if ( ! V_4 || ! V_4 -> V_7 ) {
F_5 ( V_2 -> V_22 , L_3
L_4 ) ;
return - V_9 ;
}
return V_4 -> V_7 ( V_2 , V_20 , V_21 ) ;
}
int V_7 ( const char * V_23 , const char * V_18 ,
unsigned long * V_21 )
{
struct V_1 * V_2 ;
int V_20 ;
F_6 ( & V_24 ) ;
V_2 = F_7 ( V_23 ) ;
if ( ! V_2 ) {
V_20 = - V_9 ;
goto V_25;
}
V_20 = F_8 ( V_2 , V_18 ) ;
if ( V_20 < 0 )
goto V_25;
V_20 = F_4 ( V_2 , V_20 , V_21 ) ;
V_25:
F_9 ( & V_24 ) ;
return V_20 ;
}
static int F_10 ( struct V_1 * V_2 , unsigned V_20 ,
unsigned long V_21 )
{
const struct V_3 * V_4 = V_2 -> V_5 -> V_6 ;
int V_26 ;
if ( ! V_4 || ! V_4 -> V_10 ) {
F_5 ( V_2 -> V_22 , L_5
L_6 ) ;
return - V_9 ;
}
V_26 = V_4 -> V_10 ( V_2 , V_20 , V_21 ) ;
if ( V_26 ) {
F_5 ( V_2 -> V_22 ,
L_7 , V_20 ) ;
return V_26 ;
}
return 0 ;
}
int V_10 ( const char * V_23 , const char * V_18 ,
unsigned long V_21 )
{
struct V_1 * V_2 ;
int V_20 , V_26 ;
F_6 ( & V_24 ) ;
V_2 = F_7 ( V_23 ) ;
if ( ! V_2 ) {
V_26 = - V_9 ;
goto V_25;
}
V_20 = F_8 ( V_2 , V_18 ) ;
if ( V_20 < 0 ) {
V_26 = V_20 ;
goto V_25;
}
V_26 = F_10 ( V_2 , V_20 , V_21 ) ;
V_25:
F_9 ( & V_24 ) ;
return V_26 ;
}
int V_8 ( const char * V_23 , const char * V_27 ,
unsigned long * V_21 )
{
struct V_1 * V_2 ;
const struct V_3 * V_4 ;
int V_28 , V_26 ;
F_6 ( & V_24 ) ;
V_2 = F_7 ( V_23 ) ;
if ( ! V_2 ) {
V_26 = - V_9 ;
goto V_25;
}
V_4 = V_2 -> V_5 -> V_6 ;
if ( ! V_4 || ! V_4 -> V_8 ) {
F_5 ( V_2 -> V_22 , L_8
L_9
L_10 ) ;
V_26 = - V_9 ;
goto V_25;
}
V_28 = F_11 ( V_2 , V_27 ) ;
if ( V_28 < 0 ) {
V_26 = V_28 ;
goto V_25;
}
V_26 = V_4 -> V_8 ( V_2 , V_28 , V_21 ) ;
V_25:
F_9 ( & V_24 ) ;
return V_26 ;
}
int V_11 ( const char * V_23 , const char * V_27 ,
unsigned long V_21 )
{
struct V_1 * V_2 ;
const struct V_3 * V_4 ;
const struct V_29 * V_30 ;
int V_28 ;
const unsigned * V_31 ;
unsigned V_32 ;
int V_26 ;
int V_14 ;
F_6 ( & V_24 ) ;
V_2 = F_7 ( V_23 ) ;
if ( ! V_2 ) {
V_26 = - V_9 ;
goto V_25;
}
V_4 = V_2 -> V_5 -> V_6 ;
V_30 = V_2 -> V_5 -> V_30 ;
if ( ! V_4 || ( ! V_4 -> V_11 && ! V_4 -> V_10 ) ) {
F_5 ( V_2 -> V_22 , L_11
L_6 ) ;
V_26 = - V_9 ;
goto V_25;
}
V_28 = F_11 ( V_2 , V_27 ) ;
if ( V_28 < 0 ) {
V_26 = V_28 ;
goto V_25;
}
V_26 = V_30 -> V_33 ( V_2 , V_28 , & V_31 , & V_32 ) ;
if ( V_26 ) {
F_5 ( V_2 -> V_22 , L_12
L_13 ) ;
goto V_25;
}
if ( V_4 -> V_11 ) {
V_26 = V_4 -> V_11 ( V_2 , V_28 , V_21 ) ;
if ( V_26 != - V_34 )
goto V_25;
}
if ( ! V_4 -> V_10 ) {
V_26 = 0 ;
goto V_25;
}
for ( V_14 = 0 ; V_14 < V_32 ; V_14 ++ ) {
V_26 = V_4 -> V_10 ( V_2 , V_31 [ V_14 ] , V_21 ) ;
if ( V_26 < 0 )
goto V_25;
}
V_26 = 0 ;
V_25:
F_9 ( & V_24 ) ;
return V_26 ;
}
int F_12 ( struct V_12 const * V_13 ,
struct V_35 * V_36 )
{
struct V_1 * V_2 = V_36 -> V_2 ;
int V_20 ;
switch ( V_36 -> type ) {
case V_37 :
V_20 = F_8 ( V_2 ,
V_13 -> V_15 . V_16 . V_17 ) ;
if ( V_20 < 0 ) {
F_5 ( V_2 -> V_22 , L_14 ,
V_13 -> V_15 . V_16 . V_17 ) ;
return V_20 ;
}
V_36 -> V_15 . V_16 . V_17 = V_20 ;
break;
case V_38 :
V_20 = F_11 ( V_2 ,
V_13 -> V_15 . V_16 . V_17 ) ;
if ( V_20 < 0 ) {
F_5 ( V_2 -> V_22 , L_15 ,
V_13 -> V_15 . V_16 . V_17 ) ;
return V_20 ;
}
V_36 -> V_15 . V_16 . V_17 = V_20 ;
break;
default:
return - V_9 ;
}
V_36 -> V_15 . V_16 . V_19 = V_13 -> V_15 . V_16 . V_19 ;
V_36 -> V_15 . V_16 . V_16 = V_13 -> V_15 . V_16 . V_16 ;
return 0 ;
}
void F_13 ( struct V_35 const * V_36 )
{
}
int F_14 ( struct V_35 const * V_36 )
{
struct V_1 * V_2 = V_36 -> V_2 ;
const struct V_3 * V_4 = V_2 -> V_5 -> V_6 ;
int V_14 , V_26 ;
if ( ! V_4 ) {
F_5 ( V_2 -> V_22 , L_16 ) ;
return - V_9 ;
}
switch ( V_36 -> type ) {
case V_37 :
if ( ! V_4 -> V_10 ) {
F_5 ( V_2 -> V_22 , L_17 ) ;
return - V_9 ;
}
for ( V_14 = 0 ; V_14 < V_36 -> V_15 . V_16 . V_19 ; V_14 ++ ) {
V_26 = V_4 -> V_10 ( V_2 ,
V_36 -> V_15 . V_16 . V_17 ,
V_36 -> V_15 . V_16 . V_16 [ V_14 ] ) ;
if ( V_26 < 0 ) {
F_5 ( V_2 -> V_22 ,
L_18 ,
V_36 -> V_15 . V_16 . V_17 ,
V_36 -> V_15 . V_16 . V_16 [ V_14 ] ) ;
return V_26 ;
}
}
break;
case V_38 :
if ( ! V_4 -> V_11 ) {
F_5 ( V_2 -> V_22 ,
L_19 ) ;
return - V_9 ;
}
for ( V_14 = 0 ; V_14 < V_36 -> V_15 . V_16 . V_19 ; V_14 ++ ) {
V_26 = V_4 -> V_11 ( V_2 ,
V_36 -> V_15 . V_16 . V_17 ,
V_36 -> V_15 . V_16 . V_16 [ V_14 ] ) ;
if ( V_26 < 0 ) {
F_5 ( V_2 -> V_22 ,
L_20 ,
V_36 -> V_15 . V_16 . V_17 ,
V_36 -> V_15 . V_16 . V_16 [ V_14 ] ) ;
return V_26 ;
}
}
break;
default:
return - V_9 ;
}
return 0 ;
}
void F_15 ( struct V_39 * V_40 , struct V_12 const * V_13 )
{
int V_14 ;
switch ( V_13 -> type ) {
case V_37 :
F_16 ( V_40 , L_21 ) ;
break;
case V_38 :
F_16 ( V_40 , L_22 ) ;
break;
default:
break;
}
F_16 ( V_40 , L_23 , V_13 -> V_15 . V_16 . V_17 ) ;
for ( V_14 = 0 ; V_14 < V_13 -> V_15 . V_16 . V_19 ; V_14 ++ )
F_16 ( V_40 , L_24 , V_13 -> V_15 . V_16 . V_16 [ V_14 ] ) ;
}
void F_17 ( struct V_39 * V_40 ,
struct V_35 const * V_36 )
{
struct V_1 * V_2 = V_36 -> V_2 ;
const struct V_29 * V_30 = V_2 -> V_5 -> V_30 ;
struct V_41 * V_5 ;
int V_14 ;
switch ( V_36 -> type ) {
case V_37 :
V_5 = F_18 ( V_36 -> V_2 ,
V_36 -> V_15 . V_16 . V_17 ) ;
F_16 ( V_40 , L_25 ,
V_5 -> V_18 ? V_5 -> V_18 : L_26 ,
V_36 -> V_15 . V_16 . V_17 ) ;
break;
case V_38 :
F_16 ( V_40 , L_27 ,
V_30 -> V_42 ( V_2 ,
V_36 -> V_15 . V_16 . V_17 ) ,
V_36 -> V_15 . V_16 . V_17 ) ;
break;
default:
break;
}
for ( V_14 = 0 ; V_14 < V_36 -> V_15 . V_16 . V_19 ; V_14 ++ )
F_16 ( V_40 , L_28 , V_36 -> V_15 . V_16 . V_16 [ V_14 ] ) ;
F_16 ( V_40 , L_29 ) ;
}
static void F_19 ( struct V_1 * V_2 ,
struct V_39 * V_40 , int V_20 )
{
const struct V_3 * V_4 = V_2 -> V_5 -> V_6 ;
F_20 ( V_2 , V_40 , V_20 ) ;
if ( V_4 && V_4 -> V_43 )
V_4 -> V_43 ( V_2 , V_40 , V_20 ) ;
}
static int F_21 ( struct V_39 * V_40 , void * V_44 )
{
struct V_1 * V_2 = V_40 -> V_45 ;
unsigned V_14 , V_20 ;
F_22 ( V_40 , L_30 ) ;
F_22 ( V_40 , L_31 ) ;
F_6 ( & V_24 ) ;
for ( V_14 = 0 ; V_14 < V_2 -> V_5 -> V_46 ; V_14 ++ ) {
struct V_41 * V_5 ;
V_20 = V_2 -> V_5 -> V_31 [ V_14 ] . V_47 ;
V_5 = F_18 ( V_2 , V_20 ) ;
if ( V_5 == NULL )
continue;
F_16 ( V_40 , L_32 , V_20 ,
V_5 -> V_18 ? V_5 -> V_18 : L_26 ) ;
F_19 ( V_2 , V_40 , V_20 ) ;
F_16 ( V_40 , L_29 ) ;
}
F_9 ( & V_24 ) ;
return 0 ;
}
static void F_23 ( struct V_1 * V_2 ,
struct V_39 * V_40 , unsigned V_28 ,
const char * V_48 )
{
const struct V_3 * V_4 = V_2 -> V_5 -> V_6 ;
F_24 ( V_2 , V_40 , V_48 ) ;
if ( V_4 && V_4 -> V_49 )
V_4 -> V_49 ( V_2 , V_40 , V_28 ) ;
}
static int F_25 ( struct V_39 * V_40 , void * V_44 )
{
struct V_1 * V_2 = V_40 -> V_45 ;
const struct V_29 * V_30 = V_2 -> V_5 -> V_30 ;
const struct V_3 * V_4 = V_2 -> V_5 -> V_6 ;
unsigned V_28 = 0 ;
if ( ! V_4 || ! V_4 -> V_8 )
return 0 ;
F_22 ( V_40 , L_33 ) ;
F_22 ( V_40 , L_34 ) ;
F_6 ( & V_24 ) ;
while ( V_30 -> V_50 ( V_2 , V_28 ) >= 0 ) {
const char * V_48 = V_30 -> V_42 ( V_2 , V_28 ) ;
F_16 ( V_40 , L_35 , V_28 , V_48 ) ;
F_23 ( V_2 , V_40 , V_28 , V_48 ) ;
F_16 ( V_40 , L_29 ) ;
V_28 ++ ;
}
F_9 ( & V_24 ) ;
return 0 ;
}
static int F_26 ( struct V_51 * V_51 , struct V_52 * V_52 )
{
return F_27 ( V_52 , F_21 , V_51 -> V_53 ) ;
}
static int F_28 ( struct V_51 * V_51 , struct V_52 * V_52 )
{
return F_27 ( V_52 , F_25 , V_51 -> V_53 ) ;
}
void F_29 ( struct V_54 * V_55 ,
struct V_1 * V_2 )
{
F_30 ( L_36 , V_56 | V_57 ,
V_55 , V_2 , & V_58 ) ;
F_30 ( L_37 , V_56 | V_57 ,
V_55 , V_2 , & V_59 ) ;
}
