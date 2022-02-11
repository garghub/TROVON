static int T_1 F_1 ( char * V_1 )
{
if ( ! strncmp ( V_1 , L_1 , 5 ) )
V_2 = true ;
return 1 ;
}
static void F_2 ( struct V_3 * V_4 )
{
F_3 ( F_4 ( V_4 ) ) ;
}
static int F_5 ( struct V_5 * V_4 , int * V_6 , int V_7 )
{
int V_8 , V_9 , V_10 = 0 ;
V_8 = F_6 ( V_4 , 1 , V_11 ,
V_12 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( V_7 & ( V_13 | V_14 ) ) {
T_2 V_15 ;
F_7 ( V_4 , V_16 , & V_15 ) ;
V_9 = ( V_15 & V_17 ) >> 9 ;
if ( V_9 >= V_8 )
goto V_18;
V_6 [ V_19 ] = F_8 ( V_4 , V_9 ) ;
V_6 [ V_20 ] = F_8 ( V_4 , V_9 ) ;
V_10 = F_9 ( V_10 , V_9 + 1 ) ;
}
if ( V_7 & V_21 ) {
T_3 V_22 , V_23 ;
V_23 = F_10 ( V_4 , V_24 ) ;
F_11 ( V_4 , V_23 + V_25 , & V_22 ) ;
V_9 = V_22 >> 27 ;
if ( V_9 >= V_8 )
goto V_18;
V_6 [ V_26 ] = F_8 ( V_4 , V_9 ) ;
V_10 = F_9 ( V_10 , V_9 + 1 ) ;
}
if ( V_10 != V_8 ) {
F_12 ( V_4 ) ;
V_8 = F_6 ( V_4 , V_10 , V_10 ,
V_12 ) ;
if ( V_8 < 0 )
return V_8 ;
}
return 0 ;
V_18:
F_12 ( V_4 ) ;
return - V_27 ;
}
static int F_13 ( struct V_5 * V_4 , int * V_6 , int V_7 )
{
unsigned V_28 = V_29 | V_30 ;
int V_31 , V_32 ;
for ( V_32 = 0 ; V_32 < V_33 ; V_32 ++ )
V_6 [ V_32 ] = - 1 ;
if ( ( ( V_7 & V_13 ) && F_14 () ) ||
( ( V_7 & V_14 ) && F_15 () ) ) {
V_28 &= ~ V_30 ;
} else {
if ( ! F_5 ( V_4 , V_6 , V_7 ) )
return 0 ;
}
V_31 = F_6 ( V_4 , 1 , 1 , V_28 ) ;
if ( V_31 < 0 )
return - V_34 ;
for ( V_32 = 0 ; V_32 < V_33 ; V_32 ++ ) {
if ( V_32 != V_35 )
V_6 [ V_32 ] = F_8 ( V_4 , 0 ) ;
}
return 0 ;
}
static int F_16 ( struct V_5 * V_4 )
{
int V_36 = 0 ;
int V_37 = 0 ;
if ( V_38 )
return 0 ;
V_37 = V_13 | V_14
| V_39 | V_40 ;
if ( F_17 () )
V_37 |= V_21 ;
if ( V_41 )
F_18 ( V_4 , & V_37 ) ;
if ( ( V_37 & V_14 ) && V_4 -> V_42 ) {
V_36 |= V_14 ;
F_19 ( V_4 , V_43 ,
V_44 | V_45 ) ;
}
if ( ( V_37 & V_21 )
&& F_10 ( V_4 , V_24 ) ) {
V_36 |= V_21 ;
F_20 ( V_4 ) ;
}
if ( F_10 ( V_4 , V_46 ) )
V_36 |= V_39 ;
if ( ( V_37 & V_13 )
&& F_21 ( V_4 ) == V_47 ) {
V_36 |= V_13 ;
F_22 ( V_4 , false ) ;
}
if ( F_10 ( V_4 , V_48 ) )
V_36 |= V_40 ;
return V_36 ;
}
static int F_23 ( struct V_5 * V_49 , int V_50 , int V_51 )
{
int V_52 ;
struct V_53 * V_54 ;
struct V_3 * V_3 ;
V_54 = F_24 ( sizeof( * V_54 ) , V_55 ) ;
if ( ! V_54 )
return - V_56 ;
V_54 -> V_57 = V_49 ;
V_54 -> V_51 = V_51 ;
V_54 -> V_50 = V_50 ;
V_3 = & V_54 -> V_3 ;
V_3 -> V_58 = & V_59 ;
V_3 -> V_60 = F_2 ;
F_25 ( V_3 , L_2 ,
F_26 ( V_49 ) ,
F_27 ( F_21 ( V_49 ) , V_50 ) ) ;
V_3 -> V_61 = & V_49 -> V_4 ;
F_28 ( V_3 ) ;
V_52 = F_29 ( V_3 ) ;
if ( V_52 ) {
F_30 ( V_3 ) ;
return V_52 ;
}
F_31 ( V_3 ) ;
return 0 ;
}
int F_32 ( struct V_5 * V_4 )
{
int V_62 , V_63 , V_32 , V_64 ;
int V_6 [ V_33 ] ;
V_62 = F_33 ( V_4 ) ;
if ( V_62 )
return V_62 ;
V_63 = F_16 ( V_4 ) ;
if ( ! V_63 )
return 0 ;
F_34 ( V_4 ) ;
V_62 = F_13 ( V_4 , V_6 , V_63 ) ;
if ( V_62 ) {
V_63 &= V_39 | V_14 ;
if ( ! V_63 )
goto V_65;
}
V_62 = - V_34 ;
V_64 = 0 ;
for ( V_32 = 0 ; V_32 < V_33 ; V_32 ++ ) {
int V_50 = 1 << V_32 ;
if ( ! ( V_63 & V_50 ) )
continue;
if ( ! F_23 ( V_4 , V_50 , V_6 [ V_32 ] ) )
V_64 ++ ;
}
if ( ! V_64 )
goto V_66;
return 0 ;
V_66:
F_12 ( V_4 ) ;
V_65:
F_35 ( V_4 ) ;
return V_62 ;
}
static int F_36 ( struct V_3 * V_4 , void * V_67 )
{
struct V_68 * V_69 ;
if ( ( V_4 -> V_58 == & V_59 ) && V_4 -> V_70 ) {
V_69 = F_37 ( V_4 -> V_70 ) ;
if ( V_69 -> V_71 )
V_69 -> V_71 ( F_4 ( V_4 ) ) ;
}
return 0 ;
}
int F_38 ( struct V_3 * V_4 )
{
return F_39 ( V_4 , NULL , F_36 ) ;
}
static int F_40 ( struct V_3 * V_4 , void * V_67 )
{
struct V_68 * V_69 ;
if ( ( V_4 -> V_58 == & V_59 ) &&
( V_4 -> V_70 ) ) {
V_69 = F_37 ( V_4 -> V_70 ) ;
if ( V_69 -> V_72 )
V_69 -> V_72 ( F_4 ( V_4 ) ) ;
}
return 0 ;
}
int F_41 ( struct V_3 * V_4 )
{
return F_39 ( V_4 , NULL , F_40 ) ;
}
static int F_42 ( struct V_3 * V_4 , void * V_67 )
{
if ( V_4 -> V_58 == & V_59 )
F_43 ( V_4 ) ;
return 0 ;
}
void F_44 ( struct V_5 * V_4 )
{
F_39 ( & V_4 -> V_4 , NULL , F_42 ) ;
F_12 ( V_4 ) ;
F_35 ( V_4 ) ;
}
static int F_45 ( struct V_3 * V_4 )
{
struct V_53 * V_73 ;
struct V_68 * V_70 ;
int V_62 ;
if ( ! V_4 || ! V_4 -> V_70 )
return - V_34 ;
V_70 = F_37 ( V_4 -> V_70 ) ;
if ( ! V_70 || ! V_70 -> V_74 )
return - V_34 ;
V_73 = F_4 ( V_4 ) ;
V_62 = V_70 -> V_74 ( V_73 ) ;
if ( V_62 )
return V_62 ;
F_46 ( V_4 ) ;
return 0 ;
}
static int F_47 ( struct V_3 * V_4 )
{
struct V_53 * V_73 ;
struct V_68 * V_70 ;
if ( ! V_4 || ! V_4 -> V_70 )
return 0 ;
V_73 = F_4 ( V_4 ) ;
V_70 = F_37 ( V_4 -> V_70 ) ;
if ( V_70 && V_70 -> remove ) {
V_70 -> remove ( V_73 ) ;
F_30 ( V_4 ) ;
}
return 0 ;
}
static void F_48 ( struct V_3 * V_4 ) {}
int F_49 ( struct V_68 * V_75 )
{
if ( V_38 )
return - V_34 ;
V_75 -> V_70 . V_76 = V_75 -> V_76 ;
V_75 -> V_70 . V_58 = & V_59 ;
V_75 -> V_70 . V_74 = F_45 ;
V_75 -> V_70 . remove = F_47 ;
V_75 -> V_70 . V_77 = F_48 ;
return F_50 ( & V_75 -> V_70 ) ;
}
void F_51 ( struct V_68 * V_78 )
{
F_52 ( & V_78 -> V_70 ) ;
}
