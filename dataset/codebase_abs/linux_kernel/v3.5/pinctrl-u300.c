static int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_3 ) ;
}
static const char * F_3 ( struct V_1 * V_2 ,
unsigned V_4 )
{
return V_3 [ V_4 ] . V_5 ;
}
static int F_4 ( struct V_1 * V_2 , unsigned V_4 ,
const unsigned * * V_6 ,
unsigned * V_7 )
{
* V_6 = V_3 [ V_4 ] . V_6 ;
* V_7 = V_3 [ V_4 ] . V_7 ;
return 0 ;
}
static void F_5 ( struct V_1 * V_2 , struct V_8 * V_9 ,
unsigned V_10 )
{
F_6 ( V_9 , L_1 V_11 ) ;
}
static void F_7 ( struct V_12 * V_13 , unsigned V_4 ,
bool V_14 )
{
T_1 V_15 , V_16 , V_17 ;
int V_18 ;
const struct V_19 * V_20 ;
V_20 = V_21 [ V_4 ] . V_17 ;
for ( V_18 = 0 ; V_18 < F_2 ( V_22 ) ; V_18 ++ ) {
if ( V_14 )
V_16 = V_20 -> V_23 ;
else
V_16 = 0 ;
V_17 = V_20 -> V_17 ;
if ( V_17 != 0 ) {
V_15 = F_8 ( V_13 -> V_24 + V_22 [ V_18 ] ) ;
V_15 &= ~ V_17 ;
V_15 |= V_16 ;
F_9 ( V_15 , V_13 -> V_24 + V_22 [ V_18 ] ) ;
}
V_20 ++ ;
}
}
static int F_10 ( struct V_1 * V_2 , unsigned V_4 ,
unsigned V_25 )
{
struct V_12 * V_13 ;
if ( V_4 == 0 )
return 0 ;
V_13 = F_11 ( V_2 ) ;
F_7 ( V_13 , V_4 , true ) ;
return 0 ;
}
static void F_12 ( struct V_1 * V_2 , unsigned V_4 ,
unsigned V_25 )
{
struct V_12 * V_13 ;
if ( V_4 == 0 )
return;
V_13 = F_11 ( V_2 ) ;
F_7 ( V_13 , V_4 , false ) ;
}
static int F_13 ( struct V_1 * V_2 )
{
return F_2 ( V_21 ) ;
}
static const char * F_14 ( struct V_1 * V_2 ,
unsigned V_4 )
{
return V_21 [ V_4 ] . V_5 ;
}
static int F_15 ( struct V_1 * V_2 , unsigned V_4 ,
const char * const * * V_26 ,
unsigned * const V_27 )
{
* V_26 = V_21 [ V_4 ] . V_26 ;
* V_27 = V_21 [ V_4 ] . V_27 ;
return 0 ;
}
static struct V_28 * F_16 ( unsigned V_29 )
{
int V_18 ;
for ( V_18 = 0 ; V_18 < F_2 ( V_30 ) ; V_18 ++ ) {
struct V_28 * V_31 ;
V_31 = & V_30 [ V_18 ] ;
if ( V_29 >= V_31 -> V_32 &&
V_29 <= ( V_31 -> V_32 + V_31 -> V_33 - 1 ) )
return V_31 ;
}
return NULL ;
}
int F_17 ( struct V_1 * V_2 ,
unsigned V_29 ,
unsigned long * V_34 )
{
struct V_28 * V_31 = F_16 ( V_29 ) ;
if ( ! V_31 )
return - V_35 ;
return F_18 ( V_31 -> V_36 ,
( V_29 - V_31 -> V_32 + V_31 -> V_37 ) ,
V_34 ) ;
}
int F_19 ( struct V_1 * V_2 ,
unsigned V_29 ,
unsigned long V_34 )
{
struct V_28 * V_31 = F_16 ( V_29 ) ;
int V_38 ;
if ( ! V_31 )
return - V_39 ;
V_38 = F_20 ( V_31 -> V_36 ,
( V_29 - V_31 -> V_32 + V_31 -> V_37 ) ,
F_21 ( V_34 ) ) ;
if ( V_38 )
return V_38 ;
return 0 ;
}
static int T_2 F_22 ( struct V_40 * V_41 )
{
struct V_12 * V_13 ;
struct V_42 * V_43 ;
struct V_44 * V_44 = F_23 ( & V_41 -> V_45 ) ;
int V_38 ;
int V_18 ;
F_24 ( L_2 ) ;
V_13 = F_25 ( & V_41 -> V_45 , sizeof( * V_13 ) , V_46 ) ;
if ( ! V_13 )
return - V_47 ;
V_13 -> V_45 = & V_41 -> V_45 ;
V_43 = F_26 ( V_41 , V_48 , 0 ) ;
if ( ! V_43 ) {
V_38 = - V_49 ;
goto V_50;
}
V_13 -> V_51 = V_43 -> V_52 ;
V_13 -> V_53 = F_27 ( V_43 ) ;
if ( F_28 ( V_13 -> V_51 , V_13 -> V_53 ,
V_11 ) == NULL ) {
V_38 = - V_47 ;
goto V_54;
}
V_13 -> V_24 = F_29 ( V_13 -> V_51 , V_13 -> V_53 ) ;
if ( ! V_13 -> V_24 ) {
V_38 = - V_47 ;
goto V_55;
}
V_13 -> V_56 = F_30 ( & V_57 , & V_41 -> V_45 , V_13 ) ;
if ( ! V_13 -> V_56 ) {
F_31 ( & V_41 -> V_45 , L_3 ) ;
V_38 = - V_39 ;
goto V_58;
}
for ( V_18 = 0 ; V_18 < F_2 ( V_30 ) ; V_18 ++ ) {
V_30 [ V_18 ] . V_36 = V_44 ;
F_32 ( V_13 -> V_56 , & V_30 [ V_18 ] ) ;
}
F_33 ( V_41 , V_13 ) ;
F_34 ( & V_41 -> V_45 , L_4 ) ;
return 0 ;
V_58:
F_35 ( V_13 -> V_24 ) ;
V_55:
F_33 ( V_41 , NULL ) ;
V_54:
F_36 ( V_13 -> V_51 , V_13 -> V_53 ) ;
V_50:
F_37 ( & V_41 -> V_45 , V_13 ) ;
return V_38 ;
}
static int T_3 F_38 ( struct V_40 * V_41 )
{
struct V_12 * V_13 = F_39 ( V_41 ) ;
int V_18 ;
for ( V_18 = 0 ; V_18 < F_2 ( V_30 ) ; V_18 ++ )
F_40 ( V_13 -> V_56 , & V_30 [ V_18 ] ) ;
F_41 ( V_13 -> V_56 ) ;
F_35 ( V_13 -> V_24 ) ;
F_36 ( V_13 -> V_51 , V_13 -> V_53 ) ;
F_33 ( V_41 , NULL ) ;
F_37 ( & V_41 -> V_45 , V_13 ) ;
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
