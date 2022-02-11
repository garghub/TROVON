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
int V_15 ;
const struct V_16 * V_17 = V_18 [ V_4 ] . V_19 ;
const struct V_20 * V_21 = V_17 -> V_22 ;
for ( V_15 = 0 ; V_15 < V_17 -> V_23 ; V_15 ++ ) {
T_1 V_24 ;
V_24 = F_8 ( V_13 -> V_25 + F_9 ( V_21 [ V_15 ] . V_26 ) ) ;
if ( V_14 )
V_24 = V_24 & ~ V_21 [ V_15 ] . V_21 ;
else
V_24 = V_24 | V_21 [ V_15 ] . V_21 ;
F_10 ( V_24 , V_13 -> V_25 + F_9 ( V_21 [ V_15 ] . V_26 ) ) ;
}
if ( V_17 -> V_27 && V_14 ) {
T_1 V_28 ;
V_28 =
F_8 ( V_13 -> V_29 + V_30 ) ;
V_28 =
( V_28 & ~ V_17 -> V_27 ) | ( V_17 ->
V_31 ) ;
F_10 ( V_28 , V_13 -> V_29 + V_30 ) ;
}
}
static int F_11 ( struct V_1 * V_32 , unsigned V_4 ,
unsigned V_26 )
{
struct V_12 * V_13 ;
V_13 = F_12 ( V_32 ) ;
F_7 ( V_13 , V_4 , true ) ;
return 0 ;
}
static void F_13 ( struct V_1 * V_32 , unsigned V_4 ,
unsigned V_26 )
{
struct V_12 * V_13 ;
V_13 = F_12 ( V_32 ) ;
F_7 ( V_13 , V_4 , false ) ;
}
static int F_14 ( struct V_1 * V_32 )
{
return F_2 ( V_18 ) ;
}
static const char * F_15 ( struct V_1 * V_2 ,
unsigned V_4 )
{
return V_18 [ V_4 ] . V_5 ;
}
static int F_16 ( struct V_1 * V_2 , unsigned V_4 ,
const char * const * * V_33 ,
unsigned * const V_34 )
{
* V_33 = V_18 [ V_4 ] . V_33 ;
* V_34 = V_18 [ V_4 ] . V_34 ;
return 0 ;
}
static int F_17 ( struct V_1 * V_32 ,
struct V_35 * V_36 , unsigned V_10 )
{
struct V_12 * V_13 ;
int V_26 = V_36 -> V_37 ;
T_1 V_24 ;
V_13 = F_12 ( V_32 ) ;
V_24 = F_8 ( V_13 -> V_25 + F_9 ( V_26 ) ) ;
V_24 = V_24 | ( 1 << ( V_10 - V_36 -> V_38 ) ) ;
F_10 ( V_24 , V_13 -> V_25 + F_9 ( V_26 ) ) ;
return 0 ;
}
static void T_2 * F_18 ( void )
{
const struct V_39 V_40 [] = {
{ . V_41 = L_2 } ,
{}
} ;
struct V_42 * V_43 ;
V_43 = F_19 ( NULL , V_40 ) ;
if ( ! V_43 )
F_20 ( L_3 ) ;
return F_21 ( V_43 , 0 ) ;
}
static int T_3 F_22 ( struct V_44 * V_45 )
{
int V_46 ;
struct V_12 * V_13 ;
struct V_42 * V_43 = V_45 -> V_47 . V_48 ;
int V_15 ;
V_13 = F_23 ( & V_45 -> V_47 , sizeof( * V_13 ) , V_49 ) ;
if ( ! V_13 )
return - V_50 ;
V_13 -> V_47 = & V_45 -> V_47 ;
F_24 ( V_45 , V_13 ) ;
V_13 -> V_25 = F_21 ( V_43 , 0 ) ;
if ( ! V_13 -> V_25 ) {
V_46 = - V_50 ;
F_25 ( & V_45 -> V_47 , L_4 ) ;
goto V_51;
}
V_13 -> V_29 = F_18 () ;
if ( ! V_13 -> V_29 ) {
V_46 = - V_50 ;
F_25 ( & V_45 -> V_47 , L_5 ) ;
goto V_52;
}
V_13 -> V_53 = F_26 ( & V_54 , & V_45 -> V_47 , V_13 ) ;
if ( ! V_13 -> V_53 ) {
F_25 ( & V_45 -> V_47 , L_6 ) ;
V_46 = - V_55 ;
goto V_56;
}
for ( V_15 = 0 ; V_15 < F_2 ( V_57 ) ; V_15 ++ )
F_27 ( V_13 -> V_53 , & V_57 [ V_15 ] ) ;
F_28 ( & V_45 -> V_47 , L_7 ) ;
return 0 ;
V_56:
F_29 ( V_13 -> V_29 ) ;
V_52:
F_29 ( V_13 -> V_25 ) ;
V_51:
F_24 ( V_45 , NULL ) ;
F_30 ( & V_45 -> V_47 , V_13 ) ;
return V_46 ;
}
static int T_4 F_31 ( void )
{
return F_32 ( & V_58 ) ;
}
