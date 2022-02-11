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
if ( V_12 -> V_14 -> V_23 ) {
V_12 -> V_24 = & V_21 -> V_25 [ V_12 -> V_26 ] . V_24 ;
return 0 ;
}
for ( V_22 = 0 ; V_22 < V_21 -> V_27 ; V_22 ++ ) {
if ( V_4 == V_21 -> V_25 [ V_22 ] . V_4 ) {
V_12 -> V_24 = & V_21 -> V_25 [ V_22 ] . V_24 ;
return 0 ;
}
}
return - V_28 ;
}
static void F_11 ( struct V_9 * V_4 )
{
struct V_11 * V_12 = F_8 ( V_4 ) ;
T_1 V_29 ;
int V_22 ;
if ( V_12 -> V_26 == 8 || V_12 -> V_26 == 9 )
return;
F_12 (i, (unsigned long *)larb->mmu, 32 ) {
V_29 = F_13 ( V_12 -> V_30 + F_14 ( V_22 ) ) ;
V_29 |= V_31 ;
F_15 ( V_29 , V_12 -> V_30 + F_14 ( V_22 ) ) ;
}
}
static void F_16 ( struct V_9 * V_4 )
{
struct V_11 * V_12 = F_8 ( V_4 ) ;
F_15 ( * V_12 -> V_24 , V_12 -> V_30 + V_32 ) ;
}
static void F_17 ( struct V_9 * V_4 )
{
struct V_11 * V_12 = F_8 ( V_4 ) ;
const struct V_13 * V_14 = V_12 -> V_14 ;
struct V_1 * V_15 = F_8 ( V_12 -> V_16 ) ;
int V_22 , V_33 , V_34 ;
T_1 V_35 , V_36 ;
V_33 = V_14 -> V_37 [ V_12 -> V_26 ] ;
V_34 = V_14 -> V_37 [ V_12 -> V_26 + 1 ]
- V_14 -> V_37 [ V_12 -> V_26 ] ;
for ( V_22 = 0 ; V_22 < V_34 ; V_22 ++ , V_33 ++ ) {
if ( * V_12 -> V_24 & F_18 ( V_22 ) ) {
V_35 = F_19 ( V_33 ) ;
} else {
continue;
}
V_36 = F_20 ( V_15 -> V_38
+ F_21 ( V_33 ) ) ;
V_36 &= F_22 ( V_33 ) ;
V_36 |= V_35 ;
V_36 |= F_23 ( V_33 ) ;
F_15 ( V_36 ,
V_15 -> V_38
+ F_21 ( V_33 ) ) ;
}
}
static void
F_24 ( struct V_9 * V_4 , struct V_9 * V_18 , void * V_19 )
{
}
static int F_25 ( struct V_39 * V_40 )
{
struct V_11 * V_12 ;
struct V_41 * V_42 ;
struct V_9 * V_4 = & V_40 -> V_4 ;
struct V_43 * V_44 ;
struct V_39 * V_45 ;
int V_46 ;
V_12 = F_26 ( V_4 , sizeof( * V_12 ) , V_47 ) ;
if ( ! V_12 )
return - V_48 ;
V_12 -> V_14 = F_27 ( V_4 ) ;
V_42 = F_28 ( V_40 , V_49 , 0 ) ;
V_12 -> V_30 = F_29 ( V_4 , V_42 ) ;
if ( F_30 ( V_12 -> V_30 ) )
return F_31 ( V_12 -> V_30 ) ;
V_12 -> V_2 . V_5 = F_32 ( V_4 , L_1 ) ;
if ( F_30 ( V_12 -> V_2 . V_5 ) )
return F_31 ( V_12 -> V_2 . V_5 ) ;
V_12 -> V_2 . V_7 = F_32 ( V_4 , L_2 ) ;
if ( F_30 ( V_12 -> V_2 . V_7 ) )
return F_31 ( V_12 -> V_2 . V_7 ) ;
V_12 -> V_2 . V_4 = V_4 ;
if ( V_12 -> V_14 -> V_23 ) {
V_46 = F_33 ( V_4 -> V_50 , L_3 ,
& V_12 -> V_26 ) ;
if ( V_46 ) {
F_34 ( V_4 , L_4 ) ;
return V_46 ;
}
}
V_44 = F_35 ( V_4 -> V_50 , L_5 , 0 ) ;
if ( ! V_44 )
return - V_51 ;
V_45 = F_36 ( V_44 ) ;
F_37 ( V_44 ) ;
if ( V_45 ) {
if ( ! F_38 ( V_45 ) )
return - V_52 ;
V_12 -> V_16 = & V_45 -> V_4 ;
} else {
F_34 ( V_4 , L_6 ) ;
return - V_51 ;
}
F_39 ( V_4 ) ;
F_40 ( V_40 , V_12 ) ;
return F_41 ( V_4 , & V_53 ) ;
}
static int F_42 ( struct V_39 * V_40 )
{
F_43 ( & V_40 -> V_4 ) ;
F_44 ( & V_40 -> V_4 , & V_53 ) ;
return 0 ;
}
static int F_45 ( struct V_39 * V_40 )
{
struct V_9 * V_4 = & V_40 -> V_4 ;
struct V_1 * V_15 ;
struct V_41 * V_42 ;
enum V_54 V_55 ;
int V_3 ;
V_15 = F_26 ( V_4 , sizeof( * V_15 ) , V_47 ) ;
if ( ! V_15 )
return - V_48 ;
V_15 -> V_4 = V_4 ;
V_15 -> V_5 = F_32 ( V_4 , L_1 ) ;
if ( F_30 ( V_15 -> V_5 ) )
return F_31 ( V_15 -> V_5 ) ;
V_15 -> V_7 = F_32 ( V_4 , L_2 ) ;
if ( F_30 ( V_15 -> V_7 ) )
return F_31 ( V_15 -> V_7 ) ;
V_55 = (enum V_54 ) F_27 ( V_4 ) ;
if ( V_55 == V_56 ) {
V_42 = F_28 ( V_40 , V_49 , 0 ) ;
V_15 -> V_38 = F_29 ( V_4 , V_42 ) ;
if ( F_30 ( V_15 -> V_38 ) )
return F_31 ( V_15 -> V_38 ) ;
V_15 -> V_57 = F_32 ( V_4 , L_7 ) ;
if ( F_30 ( V_15 -> V_57 ) )
return F_31 ( V_15 -> V_57 ) ;
V_3 = F_3 ( V_15 -> V_57 ) ;
if ( V_3 )
return V_3 ;
}
F_39 ( V_4 ) ;
F_40 ( V_40 , V_15 ) ;
return 0 ;
}
static int F_46 ( struct V_39 * V_40 )
{
F_43 ( & V_40 -> V_4 ) ;
return 0 ;
}
static int T_2 F_47 ( void )
{
int V_3 ;
V_3 = F_48 ( & V_58 ) ;
if ( V_3 != 0 ) {
F_49 ( L_8 ) ;
return V_3 ;
}
V_3 = F_48 ( & V_59 ) ;
if ( V_3 != 0 ) {
F_49 ( L_9 ) ;
goto V_60;
}
return V_3 ;
V_60:
F_50 ( & V_58 ) ;
return V_3 ;
}
