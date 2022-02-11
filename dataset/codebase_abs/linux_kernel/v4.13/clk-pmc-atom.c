static inline int F_1 ( int V_1 )
{
switch ( V_1 & V_2 ) {
default:
case V_3 :
return 0 ;
case V_4 :
return 1 ;
}
}
static inline int F_2 ( int V_5 )
{
switch ( V_5 ) {
default:
case 0 :
return V_3 ;
case 1 :
return V_4 ;
}
}
static inline int F_3 ( int V_1 )
{
switch ( V_1 & V_6 ) {
case V_7 :
case V_8 :
return 1 ;
case V_9 :
case V_10 :
default:
return 0 ;
}
}
static void F_4 ( struct V_11 * V_12 , T_1 V_13 , T_1 V_14 )
{
T_1 V_15 ;
unsigned long V_16 ;
F_5 ( & V_12 -> V_17 , V_16 ) ;
V_15 = F_6 ( V_12 -> V_1 ) ;
V_15 = ( V_15 & ~ V_13 ) | ( V_14 & V_13 ) ;
F_7 ( V_15 , V_12 -> V_1 ) ;
F_8 ( & V_12 -> V_17 , V_16 ) ;
}
static int F_9 ( struct V_18 * V_19 , T_2 V_5 )
{
struct V_11 * V_12 = F_10 ( V_19 ) ;
F_4 ( V_12 , V_2 , F_2 ( V_5 ) ) ;
return 0 ;
}
static T_2 F_11 ( struct V_18 * V_19 )
{
struct V_11 * V_12 = F_10 ( V_19 ) ;
T_1 V_20 ;
V_20 = F_6 ( V_12 -> V_1 ) ;
return F_1 ( V_20 ) ;
}
static int F_12 ( struct V_18 * V_19 )
{
struct V_11 * V_12 = F_10 ( V_19 ) ;
F_4 ( V_12 , V_6 , V_8 ) ;
return 0 ;
}
static void F_13 ( struct V_18 * V_19 )
{
struct V_11 * V_12 = F_10 ( V_19 ) ;
F_4 ( V_12 , V_6 , V_9 ) ;
}
static int F_14 ( struct V_18 * V_19 )
{
struct V_11 * V_12 = F_10 ( V_19 ) ;
T_1 V_20 ;
V_20 = F_6 ( V_12 -> V_1 ) ;
return F_3 ( V_20 ) ;
}
static struct V_11 * F_15 ( struct V_21 * V_22 , int V_23 ,
void T_3 * V_24 ,
const char * * V_25 ,
int V_26 )
{
struct V_11 * V_27 ;
struct V_28 V_29 ;
int V_30 ;
V_27 = F_16 ( & V_22 -> V_31 , sizeof( * V_27 ) , V_32 ) ;
if ( ! V_27 )
return F_17 ( - V_33 ) ;
V_29 . V_34 = F_18 ( V_32 , L_1 , V_35 , V_23 ) ;
V_29 . V_36 = & V_37 ;
V_29 . V_16 = 0 ;
V_29 . V_25 = V_25 ;
V_29 . V_26 = V_26 ;
V_27 -> V_19 . V_29 = & V_29 ;
V_27 -> V_1 = V_24 + V_38 + V_23 * V_39 ;
F_19 ( & V_27 -> V_17 ) ;
if ( F_14 ( & V_27 -> V_19 ) )
V_29 . V_16 |= V_40 ;
V_30 = F_20 ( & V_22 -> V_31 , & V_27 -> V_19 ) ;
if ( V_30 ) {
V_27 = F_17 ( V_30 ) ;
goto V_41;
}
V_27 -> V_42 = F_21 ( & V_27 -> V_19 , V_29 . V_34 , NULL ) ;
if ( ! V_27 -> V_42 ) {
V_27 = F_17 ( - V_33 ) ;
goto V_41;
}
V_41:
F_22 ( V_29 . V_34 ) ;
return V_27 ;
}
static void F_23 ( struct V_11 * V_27 )
{
F_24 ( V_27 -> V_42 ) ;
}
static struct V_43 * F_25 ( struct V_21 * V_22 ,
const char * V_34 ,
const char * V_44 ,
unsigned long V_45 )
{
struct V_43 * V_27 ;
V_27 = F_16 ( & V_22 -> V_31 , sizeof( * V_27 ) , V_32 ) ;
if ( ! V_27 )
return F_17 ( - V_33 ) ;
V_27 -> V_12 = F_26 ( & V_22 -> V_31 , V_34 , V_44 ,
0 , V_45 ) ;
if ( F_27 ( V_27 -> V_12 ) )
return F_28 ( V_27 -> V_12 ) ;
V_27 -> V_42 = F_21 ( V_27 -> V_12 , V_34 , NULL ) ;
if ( ! V_27 -> V_42 ) {
F_29 ( V_27 -> V_12 ) ;
return F_17 ( - V_33 ) ;
}
return V_27 ;
}
static void F_30 ( struct V_43 * V_27 )
{
F_24 ( V_27 -> V_42 ) ;
F_29 ( V_27 -> V_12 ) ;
}
static void F_31 ( struct V_46 * V_47 ,
unsigned int V_48 )
{
while ( V_48 -- )
F_30 ( V_47 -> V_49 [ V_48 ] ) ;
}
static void F_32 ( const char * * V_25 ,
unsigned int V_48 )
{
while ( V_48 -- )
F_33 ( V_25 [ V_48 ] ) ;
F_22 ( V_25 ) ;
}
static void F_34 ( struct V_46 * V_47 ,
unsigned int V_48 )
{
while ( V_48 -- )
F_23 ( V_47 -> V_50 [ V_48 ] ) ;
}
static const char * * F_35 ( struct V_21 * V_22 ,
struct V_46 * V_47 ,
const struct V_51 * V_50 )
{
const char * * V_25 ;
unsigned int V_48 ;
int V_52 ;
int V_53 = 0 ;
V_47 -> V_53 = 0 ;
while ( V_50 [ V_53 ] . V_34 )
V_53 ++ ;
V_47 -> V_49 = F_36 ( & V_22 -> V_31 , V_53 ,
sizeof( * V_47 -> V_49 ) , V_32 ) ;
if ( ! V_47 -> V_49 )
return F_17 ( - V_33 ) ;
V_25 = F_37 ( V_53 , sizeof( * V_25 ) ,
V_32 ) ;
if ( ! V_25 )
return F_17 ( - V_33 ) ;
for ( V_48 = 0 ; V_48 < V_53 ; V_48 ++ ) {
V_47 -> V_49 [ V_48 ] =
F_25 ( V_22 , V_50 [ V_48 ] . V_34 ,
V_50 [ V_48 ] . V_44 ,
V_50 [ V_48 ] . V_54 ) ;
if ( F_27 ( V_47 -> V_49 [ V_48 ] ) ) {
V_52 = F_38 ( V_47 -> V_49 [ V_48 ] ) ;
goto V_55;
}
V_25 [ V_48 ] = F_39 ( V_50 [ V_48 ] . V_34 , V_32 ) ;
}
V_47 -> V_53 = V_53 ;
return V_25 ;
V_55:
F_31 ( V_47 , V_48 ) ;
F_32 ( V_25 , V_48 ) ;
return F_17 ( V_52 ) ;
}
static void F_40 ( struct V_46 * V_47 )
{
F_31 ( V_47 , V_47 -> V_53 ) ;
}
static int F_41 ( struct V_21 * V_22 )
{
const struct V_56 * V_57 ;
const char * * V_25 ;
struct V_46 * V_47 ;
unsigned int V_48 ;
int V_52 ;
V_57 = F_42 ( & V_22 -> V_31 ) ;
if ( ! V_57 || ! V_57 -> V_50 )
return - V_58 ;
V_47 = F_16 ( & V_22 -> V_31 , sizeof( * V_47 ) , V_32 ) ;
if ( ! V_47 )
return - V_33 ;
V_25 = F_35 ( V_22 , V_47 , V_57 -> V_50 ) ;
if ( F_27 ( V_25 ) )
return F_38 ( V_25 ) ;
for ( V_48 = 0 ; V_48 < V_59 ; V_48 ++ ) {
V_47 -> V_50 [ V_48 ] = F_15 ( V_22 , V_48 , V_57 -> V_24 ,
V_25 , V_47 -> V_53 ) ;
if ( F_27 ( V_47 -> V_50 [ V_48 ] ) ) {
V_52 = F_38 ( V_47 -> V_50 [ V_48 ] ) ;
goto V_60;
}
}
V_47 -> V_61 = F_21 ( & V_47 -> V_50 [ 3 ] -> V_19 , L_2 , NULL ) ;
if ( ! V_47 -> V_61 ) {
V_52 = - V_33 ;
goto V_60;
}
F_32 ( V_25 , V_47 -> V_53 ) ;
F_43 ( V_22 , V_47 ) ;
return 0 ;
V_60:
F_34 ( V_47 , V_48 ) ;
F_40 ( V_47 ) ;
F_32 ( V_25 , V_47 -> V_53 ) ;
return V_52 ;
}
static int F_44 ( struct V_21 * V_22 )
{
struct V_46 * V_47 ;
V_47 = F_45 ( V_22 ) ;
F_24 ( V_47 -> V_61 ) ;
F_34 ( V_47 , V_59 ) ;
F_40 ( V_47 ) ;
return 0 ;
}
