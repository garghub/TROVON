static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_2 * V_3 , T_1 V_4 ,
unsigned V_5 , int V_6 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_1 V_7 = V_5 % 8 ;
int V_8 ;
V_4 = V_4 + ( V_5 / 8 ) ;
V_8 = F_4 ( V_1 -> V_9 ,
V_10 , V_4 , 1 << V_7 , V_6 << V_7 ) ;
if ( V_8 < 0 )
F_5 ( V_1 -> V_9 , L_1 , V_11 ) ;
return V_8 ;
}
static int F_6 ( struct V_2 * V_3 , unsigned V_5 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_1 V_12 = 1 << ( V_5 % 8 ) ;
T_1 V_4 = V_13 + ( V_5 / 8 ) ;
int V_8 ;
T_1 V_14 ;
V_8 = F_7 ( V_1 -> V_9 , V_10 ,
V_4 , & V_14 ) ;
if ( V_8 < 0 ) {
F_5 ( V_1 -> V_9 , L_2 , V_11 ) ;
return V_8 ;
}
return ( V_14 & V_12 ) >> ( V_5 % 8 ) ;
}
static void F_8 ( struct V_2 * V_3 , unsigned V_5 , int V_6 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
int V_8 ;
V_8 = F_3 ( V_3 , V_13 , V_5 , 1 ) ;
if ( V_8 < 0 )
F_5 ( V_1 -> V_9 , L_1 , V_11 ) ;
}
static int F_9 ( struct V_2 * V_3 , unsigned V_5 ,
int V_6 )
{
int V_8 ;
V_8 = F_3 ( V_3 , V_15 , V_5 , 1 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_3 ( V_3 , V_16 , V_5 , 1 ) ;
if ( V_8 < 0 )
return V_8 ;
return F_3 ( V_3 , V_13 , V_5 , V_6 ) ;
}
static int F_10 ( struct V_2 * V_3 , unsigned V_5 )
{
return F_3 ( V_3 , V_15 , V_5 , 0 ) ;
}
static int F_11 ( struct V_2 * V_3 , unsigned V_5 )
{
static struct V_17 {
int V_18 ;
int V_19 ;
} V_20 [] = {
{ . V_18 = 6 , . V_19 = 13 } ,
{ . V_18 = 24 , . V_19 = 25 } ,
{ . V_18 = 36 , . V_19 = 41 } ,
} ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
int V_21 = V_1 -> V_22 ;
int V_23 ;
for ( V_23 = 0 ; V_23 < F_12 ( V_20 ) ; V_23 ++ ) {
struct V_17 * V_24 = & V_20 [ V_23 ] ;
if ( V_5 >= V_24 -> V_18 && V_5 <= V_24 -> V_19 )
return V_21 + V_5 - V_24 -> V_18 ;
V_21 += V_24 -> V_19 - V_24 -> V_18 + 1 ;
}
return - V_25 ;
}
static unsigned int F_13 ( unsigned int V_26 )
{
struct V_1 * V_1 = F_14 ( V_26 ) ;
int V_5 = V_26 - V_1 -> V_22 ;
int V_27 = V_5 + V_28
+ V_1 -> V_29 -> V_22 ;
return V_27 ;
}
static unsigned int F_15 ( unsigned int V_26 )
{
struct V_1 * V_1 = F_14 ( V_26 ) ;
int V_5 = V_26 - V_1 -> V_22 ;
int V_27 = V_5 + V_30
+ V_1 -> V_29 -> V_22 ;
return V_27 ;
}
static unsigned int F_16 ( unsigned int V_26 , void * V_9 )
{
struct V_1 * V_1 = V_9 ;
int V_5 = V_26 - V_28
- V_1 -> V_29 -> V_22 ;
int V_27 = V_5 + V_1 -> V_22 ;
return V_27 ;
}
static unsigned int F_17 ( unsigned int V_26 , void * V_9 )
{
struct V_1 * V_1 = V_9 ;
int V_5 = V_26 - V_30
- V_1 -> V_29 -> V_22 ;
int V_27 = V_5 + V_1 -> V_22 ;
return V_27 ;
}
static T_2 F_18 ( int V_26 , void * V_9 )
{
F_19 ( F_16 ( V_26 , V_9 ) ) ;
return V_31 ;
}
static T_2 F_20 ( int V_26 , void * V_9 )
{
F_19 ( F_17 ( V_26 , V_9 ) ) ;
return V_31 ;
}
static void F_21 ( unsigned int V_26 )
{
struct V_1 * V_1 = F_14 ( V_26 ) ;
F_22 ( & V_1 -> V_32 ) ;
}
static void F_23 ( unsigned int V_26 )
{
struct V_1 * V_1 = F_14 ( V_26 ) ;
int V_5 = V_26 - V_1 -> V_22 ;
bool V_33 = V_1 -> V_33 & F_24 ( V_5 ) ;
bool V_34 = V_1 -> V_34 & F_24 ( V_5 ) ;
int V_8 ;
switch ( V_1 -> V_35 ) {
case V_36 :
if ( V_33 )
V_8 = F_25 ( F_13 ( V_26 ) ,
NULL , F_18 ,
V_37 ,
L_3 , V_1 ) ;
if ( V_34 )
V_8 = F_25 ( F_15 ( V_26 ) ,
NULL , F_20 ,
V_38 ,
L_4 , V_1 ) ;
break;
case V_39 :
if ( V_33 )
F_26 ( F_13 ( V_26 ) , V_1 ) ;
if ( V_34 )
F_26 ( F_15 ( V_26 ) , V_1 ) ;
break;
case V_40 :
if ( V_33 )
F_27 ( F_13 ( V_26 ) ) ;
if ( V_34 )
F_27 ( F_15 ( V_26 ) ) ;
break;
case V_41 :
if ( V_33 )
F_28 ( F_13 ( V_26 ) ) ;
if ( V_34 )
F_28 ( F_15 ( V_26 ) ) ;
break;
case V_42 :
break;
}
V_1 -> V_35 = V_42 ;
V_1 -> V_33 &= ~ ( F_24 ( V_5 ) ) ;
V_1 -> V_34 &= ~ ( F_24 ( V_5 ) ) ;
F_29 ( & V_1 -> V_32 ) ;
}
static void F_30 ( unsigned int V_26 )
{
struct V_1 * V_1 = F_14 ( V_26 ) ;
V_1 -> V_35 = V_40 ;
}
static void F_31 ( unsigned int V_26 )
{
struct V_1 * V_1 = F_14 ( V_26 ) ;
V_1 -> V_35 = V_41 ;
}
static int F_32 ( unsigned int V_26 , unsigned int type )
{
struct V_1 * V_1 = F_14 ( V_26 ) ;
int V_5 = V_26 - V_1 -> V_22 ;
if ( type == V_43 ) {
V_1 -> V_33 = F_24 ( V_5 ) ;
V_1 -> V_34 = F_24 ( V_5 ) ;
} else if ( type == V_44 ) {
V_1 -> V_33 = F_24 ( V_5 ) ;
} else {
V_1 -> V_34 = F_24 ( V_5 ) ;
}
return 0 ;
}
unsigned int F_33 ( unsigned int V_26 )
{
struct V_1 * V_1 = F_14 ( V_26 ) ;
V_1 -> V_35 = V_36 ;
return 0 ;
}
void F_34 ( unsigned int V_26 )
{
struct V_1 * V_1 = F_14 ( V_26 ) ;
V_1 -> V_35 = V_39 ;
}
static int F_35 ( struct V_1 * V_1 )
{
T_3 V_21 = V_1 -> V_22 ;
int V_26 ;
for ( V_26 = V_21 ; V_26 < V_21 + V_45 ; V_26 ++ ) {
F_36 ( V_26 , V_1 ) ;
F_37 ( V_26 , & V_46 ,
V_47 ) ;
F_38 ( V_26 , 1 ) ;
#ifdef F_39
F_40 ( V_26 , V_48 ) ;
#else
F_41 ( V_26 ) ;
#endif
}
return 0 ;
}
static void F_42 ( struct V_1 * V_1 )
{
int V_21 = V_1 -> V_22 ;
int V_26 ;
for ( V_26 = V_21 ; V_26 < V_21 + V_45 ; V_26 ++ ) {
#ifdef F_39
F_40 ( V_26 , 0 ) ;
#endif
F_37 ( V_26 , NULL , NULL ) ;
F_36 ( V_26 , NULL ) ;
}
}
static int T_4 F_43 ( struct V_49 * V_50 )
{
struct V_51 * V_52 =
F_44 ( V_50 -> V_9 . V_29 ) ;
struct V_53 * V_54 ;
struct V_1 * V_1 ;
int V_8 ;
int V_23 ;
V_54 = V_52 -> V_55 ;
if ( ! V_54 ) {
F_5 ( & V_50 -> V_9 , L_5 ) ;
return - V_56 ;
}
V_1 = F_45 ( sizeof( struct V_1 ) , V_57 ) ;
if ( V_1 == NULL ) {
F_5 ( & V_50 -> V_9 , L_6 ) ;
return - V_58 ;
}
V_1 -> V_9 = & V_50 -> V_9 ;
V_1 -> V_29 = F_46 ( V_50 -> V_9 . V_29 ) ;
V_1 -> V_3 = V_59 ;
V_1 -> V_3 . V_60 = V_61 ;
V_1 -> V_3 . V_9 = & V_50 -> V_9 ;
V_1 -> V_3 . V_21 = V_54 -> V_62 ;
V_1 -> V_22 = V_54 -> V_22 ;
F_47 ( & V_1 -> V_32 ) ;
for ( V_23 = V_63 ; V_23 <= V_64 ; V_23 ++ ) {
V_8 = F_48 ( V_1 -> V_9 ,
V_10 , V_23 ,
V_54 -> V_65 [ V_23 ] ) ;
if ( V_8 < 0 )
goto V_66;
}
V_8 = F_48 ( V_1 -> V_9 , V_10 ,
V_67 ,
V_54 -> V_65 [ V_68 ] ) ;
if ( V_8 < 0 )
goto V_66;
V_8 = F_35 ( V_1 ) ;
if ( V_8 )
goto V_66;
V_8 = F_49 ( & V_1 -> V_3 ) ;
if ( V_8 ) {
F_5 ( & V_50 -> V_9 , L_7 ,
V_8 ) ;
goto V_69;
}
F_50 ( V_50 , V_1 ) ;
return 0 ;
V_69:
F_42 ( V_1 ) ;
V_66:
F_51 ( & V_1 -> V_32 ) ;
F_52 ( V_1 ) ;
return V_8 ;
}
static int T_5 F_53 ( struct V_49 * V_50 )
{
struct V_1 * V_1 = F_54 ( V_50 ) ;
int V_8 ;
V_8 = F_55 ( & V_1 -> V_3 ) ;
if ( V_8 < 0 ) {
F_5 ( V_1 -> V_9 , L_8 ,
V_8 ) ;
return V_8 ;
}
F_50 ( V_50 , NULL ) ;
F_51 ( & V_1 -> V_32 ) ;
F_52 ( V_1 ) ;
return 0 ;
}
static int T_6 F_56 ( void )
{
return F_57 ( & V_70 ) ;
}
static void T_7 F_58 ( void )
{
F_59 ( & V_70 ) ;
}
