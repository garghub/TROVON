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
V_12 | V_13 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( V_7 & ( V_14 | V_15 ) ) {
T_2 V_16 ;
F_7 ( V_4 , V_17 , & V_16 ) ;
V_9 = ( V_16 & V_18 ) >> 9 ;
if ( V_9 >= V_8 )
goto V_19;
V_6 [ V_20 ] = F_8 ( V_4 , V_9 ) ;
V_6 [ V_21 ] = F_8 ( V_4 , V_9 ) ;
V_10 = F_9 ( V_10 , V_9 + 1 ) ;
}
if ( V_7 & V_22 ) {
T_3 V_23 , V_24 ;
V_24 = F_10 ( V_4 , V_25 ) ;
F_11 ( V_4 , V_24 + V_26 , & V_23 ) ;
V_9 = V_23 >> 27 ;
if ( V_9 >= V_8 )
goto V_19;
V_6 [ V_27 ] = F_8 ( V_4 , V_9 ) ;
V_10 = F_9 ( V_10 , V_9 + 1 ) ;
}
if ( V_7 & V_28 ) {
T_2 V_16 , V_24 ;
V_24 = F_10 ( V_4 , V_29 ) ;
F_12 ( V_4 , V_24 + V_30 , & V_16 ) ;
V_9 = V_16 & 0x1f ;
if ( V_9 >= V_8 )
goto V_19;
V_6 [ V_31 ] = F_8 ( V_4 , V_9 ) ;
V_10 = F_9 ( V_10 , V_9 + 1 ) ;
}
if ( V_10 != V_8 ) {
F_13 ( V_4 ) ;
V_8 = F_6 ( V_4 , V_10 , V_10 ,
V_12 | V_13 ) ;
if ( V_8 < 0 )
return V_8 ;
}
return 0 ;
V_19:
F_13 ( V_4 ) ;
return - V_32 ;
}
static int F_14 ( struct V_5 * V_4 , int * V_6 , int V_7 )
{
int V_33 , V_34 ;
for ( V_34 = 0 ; V_34 < V_35 ; V_34 ++ )
V_6 [ V_34 ] = - 1 ;
if ( ( V_7 & V_14 ) && F_15 () )
goto V_36;
if ( ( V_7 & V_15 ) && F_16 () )
goto V_36;
if ( F_5 ( V_4 , V_6 , V_7 ) == 0 )
return 0 ;
V_36:
V_33 = F_6 ( V_4 , 1 , 1 , V_37 ) ;
if ( V_33 < 0 )
return - V_38 ;
for ( V_34 = 0 ; V_34 < V_35 ; V_34 ++ ) {
if ( V_34 != V_39 )
V_6 [ V_34 ] = F_8 ( V_4 , 0 ) ;
}
return 0 ;
}
static int F_17 ( struct V_5 * V_4 )
{
int V_40 = 0 ;
int V_41 = 0 ;
if ( V_42 )
return 0 ;
V_41 = V_14 | V_15
| V_43 | V_28 ;
if ( F_18 () )
V_41 |= V_22 ;
if ( V_44 )
F_19 ( V_4 , & V_41 ) ;
if ( ( V_41 & V_15 ) && V_4 -> V_45 ) {
V_40 |= V_15 ;
F_20 ( V_4 , V_46 ,
V_47 | V_48 ) ;
}
if ( ( V_41 & V_22 )
&& F_10 ( V_4 , V_25 ) ) {
V_40 |= V_22 ;
F_21 ( V_4 ) ;
}
if ( F_10 ( V_4 , V_49 ) )
V_40 |= V_43 ;
if ( ( V_41 & V_14 )
&& F_22 ( V_4 ) == V_50 ) {
V_40 |= V_14 ;
F_23 ( V_4 , false ) ;
}
if ( F_10 ( V_4 , V_29 ) )
V_40 |= V_28 ;
return V_40 ;
}
static int F_24 ( struct V_5 * V_51 , int V_52 , int V_53 )
{
int V_54 ;
struct V_55 * V_56 ;
struct V_3 * V_3 ;
V_56 = F_25 ( sizeof( * V_56 ) , V_57 ) ;
if ( ! V_56 )
return - V_58 ;
V_56 -> V_59 = V_51 ;
V_56 -> V_53 = V_53 ;
V_56 -> V_52 = V_52 ;
V_3 = & V_56 -> V_3 ;
V_3 -> V_60 = & V_61 ;
V_3 -> V_62 = F_2 ;
F_26 ( V_3 , L_2 ,
F_27 ( V_51 ) ,
F_28 ( F_22 ( V_51 ) , V_52 ) ) ;
V_3 -> V_63 = & V_51 -> V_4 ;
F_29 ( V_3 ) ;
V_54 = F_30 ( V_3 ) ;
if ( V_54 ) {
F_31 ( V_3 ) ;
return V_54 ;
}
F_32 ( V_3 ) ;
return 0 ;
}
int F_33 ( struct V_5 * V_4 )
{
int V_64 , V_65 , V_34 , V_66 ;
int V_6 [ V_35 ] ;
V_64 = F_34 ( V_4 ) ;
if ( V_64 )
return V_64 ;
V_65 = F_17 ( V_4 ) ;
if ( ! V_65 )
return 0 ;
F_35 ( V_4 ) ;
V_64 = F_14 ( V_4 , V_6 , V_65 ) ;
if ( V_64 ) {
V_65 &= V_43 | V_15 ;
if ( ! V_65 )
goto V_67;
}
V_64 = - V_38 ;
V_66 = 0 ;
for ( V_34 = 0 ; V_34 < V_35 ; V_34 ++ ) {
int V_52 = 1 << V_34 ;
if ( ! ( V_65 & V_52 ) )
continue;
if ( ! F_24 ( V_4 , V_52 , V_6 [ V_34 ] ) )
V_66 ++ ;
}
if ( ! V_66 )
goto V_68;
return 0 ;
V_68:
F_13 ( V_4 ) ;
V_67:
F_36 ( V_4 ) ;
return V_64 ;
}
static int F_37 ( struct V_3 * V_4 , void * V_69 )
{
struct V_70 * V_71 ;
if ( ( V_4 -> V_60 == & V_61 ) && V_4 -> V_72 ) {
V_71 = F_38 ( V_4 -> V_72 ) ;
if ( V_71 -> V_73 )
V_71 -> V_73 ( F_4 ( V_4 ) ) ;
}
return 0 ;
}
int F_39 ( struct V_3 * V_4 )
{
return F_40 ( V_4 , NULL , F_37 ) ;
}
static int F_41 ( struct V_3 * V_4 , void * V_69 )
{
struct V_70 * V_71 ;
if ( ( V_4 -> V_60 == & V_61 ) &&
( V_4 -> V_72 ) ) {
V_71 = F_38 ( V_4 -> V_72 ) ;
if ( V_71 -> V_74 )
V_71 -> V_74 ( F_4 ( V_4 ) ) ;
}
return 0 ;
}
int F_42 ( struct V_3 * V_4 )
{
return F_40 ( V_4 , NULL , F_41 ) ;
}
static int F_43 ( struct V_3 * V_4 , void * V_69 )
{
if ( V_4 -> V_60 == & V_61 )
F_44 ( V_4 ) ;
return 0 ;
}
void F_45 ( struct V_5 * V_4 )
{
F_40 ( & V_4 -> V_4 , NULL , F_43 ) ;
F_13 ( V_4 ) ;
F_36 ( V_4 ) ;
}
static int F_46 ( struct V_3 * V_4 )
{
struct V_55 * V_75 ;
struct V_70 * V_72 ;
int V_64 ;
if ( ! V_4 || ! V_4 -> V_72 )
return - V_38 ;
V_72 = F_38 ( V_4 -> V_72 ) ;
if ( ! V_72 || ! V_72 -> V_76 )
return - V_38 ;
V_75 = F_4 ( V_4 ) ;
V_64 = V_72 -> V_76 ( V_75 ) ;
if ( V_64 )
return V_64 ;
F_47 ( V_4 ) ;
return 0 ;
}
static int F_48 ( struct V_3 * V_4 )
{
struct V_55 * V_75 ;
struct V_70 * V_72 ;
if ( ! V_4 || ! V_4 -> V_72 )
return 0 ;
V_75 = F_4 ( V_4 ) ;
V_72 = F_38 ( V_4 -> V_72 ) ;
if ( V_72 && V_72 -> remove ) {
V_72 -> remove ( V_75 ) ;
F_31 ( V_4 ) ;
}
return 0 ;
}
static void F_49 ( struct V_3 * V_4 ) {}
int F_50 ( struct V_70 * V_77 )
{
if ( V_42 )
return - V_38 ;
V_77 -> V_72 . V_78 = V_77 -> V_78 ;
V_77 -> V_72 . V_60 = & V_61 ;
V_77 -> V_72 . V_76 = F_46 ;
V_77 -> V_72 . remove = F_48 ;
V_77 -> V_72 . V_79 = F_49 ;
return F_51 ( & V_77 -> V_72 ) ;
}
void F_52 ( struct V_70 * V_80 )
{
F_53 ( & V_80 -> V_72 ) ;
}
