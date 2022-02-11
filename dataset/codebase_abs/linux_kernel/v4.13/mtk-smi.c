static int F_1 ( const struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_2 ( V_2 -> V_4 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_3 ( V_2 -> V_5 ) ;
if ( V_3 )
goto V_6;
V_3 = F_3 ( V_2 -> V_7 ) ;
if ( V_3 )
goto V_8;
return 0 ;
V_8:
F_4 ( V_2 -> V_5 ) ;
V_6:
F_5 ( V_2 -> V_4 ) ;
return V_3 ;
}
static void F_6 ( const struct V_1 * V_2 )
{
F_4 ( V_2 -> V_7 ) ;
F_4 ( V_2 -> V_5 ) ;
F_5 ( V_2 -> V_4 ) ;
}
int F_7 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = F_8 ( V_10 ) ;
const struct V_13 * V_14 = V_12 -> V_14 ;
struct V_1 * V_15 = F_8 ( V_12 -> V_16 ) ;
int V_3 ;
V_3 = F_1 ( V_15 ) ;
if ( V_3 )
return V_3 ;
V_3 = F_1 ( & V_12 -> V_2 ) ;
if ( V_3 ) {
F_6 ( V_15 ) ;
return V_3 ;
}
V_14 -> V_17 ( V_10 ) ;
return 0 ;
}
void F_9 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = F_8 ( V_10 ) ;
struct V_1 * V_15 = F_8 ( V_12 -> V_16 ) ;
F_6 ( & V_12 -> V_2 ) ;
F_6 ( V_15 ) ;
}
static int
F_10 ( struct V_9 * V_4 , struct V_9 * V_18 , void * V_19 )
{
struct V_11 * V_12 = F_8 ( V_4 ) ;
struct V_20 * V_21 = V_19 ;
unsigned int V_22 ;
for ( V_22 = 0 ; V_22 < V_21 -> V_23 ; V_22 ++ ) {
if ( V_4 == V_21 -> V_24 [ V_22 ] . V_4 ) {
V_12 -> V_25 = & V_21 -> V_24 [ V_22 ] . V_25 ;
return 0 ;
}
}
return - V_26 ;
}
static void F_11 ( struct V_9 * V_4 )
{
struct V_11 * V_12 = F_8 ( V_4 ) ;
F_12 ( * V_12 -> V_25 , V_12 -> V_27 + V_28 ) ;
}
static void F_13 ( struct V_9 * V_4 )
{
struct V_11 * V_12 = F_8 ( V_4 ) ;
const struct V_13 * V_14 = V_12 -> V_14 ;
struct V_1 * V_15 = F_8 ( V_12 -> V_16 ) ;
int V_22 , V_29 , V_30 ;
T_1 V_31 , V_32 ;
V_29 = V_14 -> V_33 [ V_12 -> V_34 ] ;
V_30 = V_14 -> V_33 [ V_12 -> V_34 + 1 ]
- V_14 -> V_33 [ V_12 -> V_34 ] ;
for ( V_22 = 0 ; V_22 < V_30 ; V_22 ++ , V_29 ++ ) {
if ( * V_12 -> V_25 & F_14 ( V_22 ) ) {
V_31 = F_15 ( V_29 ) ;
} else {
continue;
}
V_32 = F_16 ( V_15 -> V_35
+ F_17 ( V_29 ) ) ;
V_32 &= F_18 ( V_29 ) ;
V_32 |= V_31 ;
V_32 |= F_19 ( V_29 ) ;
F_12 ( V_32 ,
V_15 -> V_35
+ F_17 ( V_29 ) ) ;
}
}
static void
F_20 ( struct V_9 * V_4 , struct V_9 * V_18 , void * V_19 )
{
}
static int F_21 ( struct V_36 * V_37 )
{
struct V_11 * V_12 ;
struct V_38 * V_39 ;
struct V_9 * V_4 = & V_37 -> V_4 ;
struct V_40 * V_41 ;
struct V_36 * V_42 ;
const struct V_43 * V_44 ;
if ( ! V_4 -> V_45 )
return - V_46 ;
V_44 = F_22 ( V_47 , V_37 -> V_4 . V_48 ) ;
if ( ! V_44 )
return - V_49 ;
V_12 = F_23 ( V_4 , sizeof( * V_12 ) , V_50 ) ;
if ( ! V_12 )
return - V_51 ;
V_12 -> V_14 = V_44 -> V_19 ;
V_39 = F_24 ( V_37 , V_52 , 0 ) ;
V_12 -> V_27 = F_25 ( V_4 , V_39 ) ;
if ( F_26 ( V_12 -> V_27 ) )
return F_27 ( V_12 -> V_27 ) ;
V_12 -> V_2 . V_5 = F_28 ( V_4 , L_1 ) ;
if ( F_26 ( V_12 -> V_2 . V_5 ) )
return F_27 ( V_12 -> V_2 . V_5 ) ;
V_12 -> V_2 . V_7 = F_28 ( V_4 , L_2 ) ;
if ( F_26 ( V_12 -> V_2 . V_7 ) )
return F_27 ( V_12 -> V_2 . V_7 ) ;
V_12 -> V_2 . V_4 = V_4 ;
V_41 = F_29 ( V_4 -> V_48 , L_3 , 0 ) ;
if ( ! V_41 )
return - V_49 ;
V_42 = F_30 ( V_41 ) ;
F_31 ( V_41 ) ;
if ( V_42 ) {
V_12 -> V_16 = & V_42 -> V_4 ;
} else {
F_32 ( V_4 , L_4 ) ;
return - V_49 ;
}
F_33 ( V_4 ) ;
F_34 ( V_37 , V_12 ) ;
return F_35 ( V_4 , & V_53 ) ;
}
static int F_36 ( struct V_36 * V_37 )
{
F_37 ( & V_37 -> V_4 ) ;
F_38 ( & V_37 -> V_4 , & V_53 ) ;
return 0 ;
}
static int F_39 ( struct V_36 * V_37 )
{
struct V_9 * V_4 = & V_37 -> V_4 ;
struct V_1 * V_15 ;
struct V_38 * V_39 ;
const struct V_43 * V_44 ;
enum V_54 V_55 ;
if ( ! V_4 -> V_45 )
return - V_46 ;
V_15 = F_23 ( V_4 , sizeof( * V_15 ) , V_50 ) ;
if ( ! V_15 )
return - V_51 ;
V_15 -> V_4 = V_4 ;
V_15 -> V_5 = F_28 ( V_4 , L_1 ) ;
if ( F_26 ( V_15 -> V_5 ) )
return F_27 ( V_15 -> V_5 ) ;
V_15 -> V_7 = F_28 ( V_4 , L_2 ) ;
if ( F_26 ( V_15 -> V_7 ) )
return F_27 ( V_15 -> V_7 ) ;
V_44 = F_22 ( V_56 , V_37 -> V_4 . V_48 ) ;
if ( ! V_44 )
return - V_49 ;
V_55 = (enum V_54 ) V_44 -> V_19 ;
if ( V_55 == V_57 ) {
V_39 = F_24 ( V_37 , V_52 , 0 ) ;
V_15 -> V_35 = F_25 ( V_4 , V_39 ) ;
if ( F_26 ( V_15 -> V_35 ) )
return F_27 ( V_15 -> V_35 ) ;
V_15 -> V_58 = F_28 ( V_4 , L_5 ) ;
if ( F_26 ( V_15 -> V_58 ) )
return F_27 ( V_15 -> V_58 ) ;
F_3 ( V_15 -> V_58 ) ;
}
F_33 ( V_4 ) ;
F_34 ( V_37 , V_15 ) ;
return 0 ;
}
static int F_40 ( struct V_36 * V_37 )
{
F_37 ( & V_37 -> V_4 ) ;
return 0 ;
}
static int T_2 F_41 ( void )
{
int V_3 ;
V_3 = F_42 ( & V_59 ) ;
if ( V_3 != 0 ) {
F_43 ( L_6 ) ;
return V_3 ;
}
V_3 = F_42 ( & V_60 ) ;
if ( V_3 != 0 ) {
F_43 ( L_7 ) ;
goto V_61;
}
return V_3 ;
V_61:
F_44 ( & V_59 ) ;
return V_3 ;
}
