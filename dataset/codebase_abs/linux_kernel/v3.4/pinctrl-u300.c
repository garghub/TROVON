static int F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
if ( V_3 >= F_2 ( V_4 ) )
return - V_5 ;
return 0 ;
}
static const char * F_3 ( struct V_1 * V_2 ,
unsigned V_3 )
{
if ( V_3 >= F_2 ( V_4 ) )
return NULL ;
return V_4 [ V_3 ] . V_6 ;
}
static int F_4 ( struct V_1 * V_2 , unsigned V_3 ,
const unsigned * * V_7 ,
unsigned * V_8 )
{
if ( V_3 >= F_2 ( V_4 ) )
return - V_5 ;
* V_7 = V_4 [ V_3 ] . V_7 ;
* V_8 = V_4 [ V_3 ] . V_8 ;
return 0 ;
}
static void F_5 ( struct V_1 * V_2 , struct V_9 * V_10 ,
unsigned V_11 )
{
F_6 ( V_10 , L_1 V_12 ) ;
}
static void F_7 ( struct V_13 * V_14 , unsigned V_3 ,
bool V_15 )
{
T_1 V_16 , V_17 , V_18 ;
int V_19 ;
const struct V_20 * V_21 ;
V_21 = V_22 [ V_3 ] . V_18 ;
for ( V_19 = 0 ; V_19 < F_2 ( V_23 ) ; V_19 ++ ) {
if ( V_15 )
V_17 = V_21 -> V_24 ;
else
V_17 = 0 ;
V_18 = V_21 -> V_18 ;
if ( V_18 != 0 ) {
V_16 = F_8 ( V_14 -> V_25 + V_23 [ V_19 ] ) ;
V_16 &= ~ V_18 ;
V_16 |= V_17 ;
F_9 ( V_16 , V_14 -> V_25 + V_23 [ V_19 ] ) ;
}
V_21 ++ ;
}
}
static int F_10 ( struct V_1 * V_2 , unsigned V_3 ,
unsigned V_26 )
{
struct V_13 * V_14 ;
if ( V_3 == 0 )
return 0 ;
V_14 = F_11 ( V_2 ) ;
F_7 ( V_14 , V_3 , true ) ;
return 0 ;
}
static void F_12 ( struct V_1 * V_2 , unsigned V_3 ,
unsigned V_26 )
{
struct V_13 * V_14 ;
if ( V_3 == 0 )
return;
V_14 = F_11 ( V_2 ) ;
F_7 ( V_14 , V_3 , false ) ;
}
static int F_13 ( struct V_1 * V_2 , unsigned V_3 )
{
if ( V_3 >= F_2 ( V_22 ) )
return - V_5 ;
return 0 ;
}
static const char * F_14 ( struct V_1 * V_2 ,
unsigned V_3 )
{
return V_22 [ V_3 ] . V_6 ;
}
static int F_15 ( struct V_1 * V_2 , unsigned V_3 ,
const char * const * * V_27 ,
unsigned * const V_28 )
{
* V_27 = V_22 [ V_3 ] . V_27 ;
* V_28 = V_22 [ V_3 ] . V_28 ;
return 0 ;
}
static struct V_29 * F_16 ( unsigned V_30 )
{
int V_19 ;
for ( V_19 = 0 ; V_19 < F_2 ( V_31 ) ; V_19 ++ ) {
struct V_29 * V_32 ;
V_32 = & V_31 [ V_19 ] ;
if ( V_30 >= V_32 -> V_33 &&
V_30 <= ( V_32 -> V_33 + V_32 -> V_34 - 1 ) )
return V_32 ;
}
return NULL ;
}
int F_17 ( struct V_1 * V_2 ,
unsigned V_30 ,
unsigned long * V_35 )
{
struct V_29 * V_32 = F_16 ( V_30 ) ;
if ( ! V_32 )
return - V_36 ;
return F_18 ( V_32 -> V_37 ,
( V_30 - V_32 -> V_33 + V_32 -> V_38 ) ,
V_35 ) ;
}
int F_19 ( struct V_1 * V_2 ,
unsigned V_30 ,
unsigned long V_35 )
{
struct V_29 * V_32 = F_16 ( V_30 ) ;
int V_39 ;
if ( ! V_32 )
return - V_5 ;
V_39 = F_20 ( V_32 -> V_37 ,
( V_30 - V_32 -> V_33 + V_32 -> V_38 ) ,
F_21 ( V_35 ) ) ;
if ( V_39 )
return V_39 ;
return 0 ;
}
static int T_2 F_22 ( struct V_40 * V_41 )
{
struct V_13 * V_14 ;
struct V_42 * V_43 ;
struct V_44 * V_44 = F_23 ( & V_41 -> V_45 ) ;
int V_39 ;
int V_19 ;
F_24 ( L_2 ) ;
V_14 = F_25 ( & V_41 -> V_45 , sizeof( * V_14 ) , V_46 ) ;
if ( ! V_14 )
return - V_47 ;
V_14 -> V_45 = & V_41 -> V_45 ;
V_43 = F_26 ( V_41 , V_48 , 0 ) ;
if ( ! V_43 ) {
V_39 = - V_49 ;
goto V_50;
}
V_14 -> V_51 = V_43 -> V_52 ;
V_14 -> V_53 = F_27 ( V_43 ) ;
if ( F_28 ( V_14 -> V_51 , V_14 -> V_53 ,
V_12 ) == NULL ) {
V_39 = - V_47 ;
goto V_54;
}
V_14 -> V_25 = F_29 ( V_14 -> V_51 , V_14 -> V_53 ) ;
if ( ! V_14 -> V_25 ) {
V_39 = - V_47 ;
goto V_55;
}
V_14 -> V_56 = F_30 ( & V_57 , & V_41 -> V_45 , V_14 ) ;
if ( ! V_14 -> V_56 ) {
F_31 ( & V_41 -> V_45 , L_3 ) ;
V_39 = - V_5 ;
goto V_58;
}
for ( V_19 = 0 ; V_19 < F_2 ( V_31 ) ; V_19 ++ ) {
V_31 [ V_19 ] . V_37 = V_44 ;
F_32 ( V_14 -> V_56 , & V_31 [ V_19 ] ) ;
}
F_33 ( V_41 , V_14 ) ;
F_34 ( & V_41 -> V_45 , L_4 ) ;
return 0 ;
V_58:
F_35 ( V_14 -> V_25 ) ;
V_55:
F_33 ( V_41 , NULL ) ;
V_54:
F_36 ( V_14 -> V_51 , V_14 -> V_53 ) ;
V_50:
F_37 ( & V_41 -> V_45 , V_14 ) ;
return V_39 ;
}
static int T_3 F_38 ( struct V_40 * V_41 )
{
struct V_13 * V_14 = F_39 ( V_41 ) ;
int V_19 ;
for ( V_19 = 0 ; V_19 < F_2 ( V_31 ) ; V_19 ++ )
F_40 ( V_14 -> V_56 , & V_31 [ V_19 ] ) ;
F_41 ( V_14 -> V_56 ) ;
F_35 ( V_14 -> V_25 ) ;
F_36 ( V_14 -> V_51 , V_14 -> V_53 ) ;
F_33 ( V_41 , NULL ) ;
F_37 ( & V_41 -> V_45 , V_14 ) ;
return 0 ;
}
static int T_4 F_42 ( void )
{
return F_43 ( & V_59 ) ;
}
static void T_5 F_44 ( void )
{
F_45 ( & V_59 ) ;
}
