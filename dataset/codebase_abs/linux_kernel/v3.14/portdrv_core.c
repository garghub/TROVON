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
static int F_5 (
struct V_5 * V_6 , int V_7 , int V_8 )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < V_8 ; V_9 ++ )
if ( V_6 [ V_9 ] . V_10 == V_7 )
return V_9 ;
V_6 [ V_9 ] . V_10 = V_7 ;
return V_9 ;
}
static int F_6 ( struct V_11 * V_4 , int * V_12 , int V_13 )
{
struct V_5 * V_14 ;
int V_15 [ V_16 ] ;
int V_8 , V_17 , V_18 , V_19 , V_20 ;
T_2 V_21 ;
T_3 V_22 ;
V_8 = F_7 ( V_4 ) ;
if ( V_8 < 0 )
return V_8 ;
F_8 ( ! V_8 ) ;
if ( V_8 > V_23 )
V_8 = V_23 ;
V_14 = F_9 ( sizeof( * V_14 ) * V_8 , V_24 ) ;
if ( ! V_14 )
return - V_25 ;
for ( V_19 = 0 ; V_19 < V_8 ; V_19 ++ )
V_14 [ V_19 ] . V_10 = V_19 ;
V_17 = F_10 ( V_4 , V_14 , V_8 ) ;
if ( V_17 )
goto Exit;
for ( V_19 = 0 ; V_19 < V_16 ; V_19 ++ )
V_15 [ V_19 ] = - 1 ;
V_17 = - V_26 ;
V_20 = 0 ;
if ( V_13 & ( V_27 | V_28 ) ) {
int V_10 ;
F_11 ( V_4 , V_29 , & V_21 ) ;
V_10 = ( V_21 & V_30 ) >> 9 ;
if ( V_10 >= V_8 )
goto Error;
V_19 = F_5 ( V_14 , V_10 , V_20 ) ;
if ( V_19 == V_20 )
V_20 ++ ;
V_15 [ V_31 ] = V_19 ;
V_15 [ V_32 ] = V_19 ;
}
if ( V_13 & V_33 ) {
int V_10 ;
V_18 = F_12 ( V_4 , V_34 ) ;
F_13 ( V_4 , V_18 + V_35 , & V_22 ) ;
V_10 = V_22 >> 27 ;
if ( V_10 >= V_8 )
goto Error;
V_19 = F_5 ( V_14 , V_10 , V_20 ) ;
if ( V_19 == V_20 )
V_20 ++ ;
V_15 [ V_36 ] = V_19 ;
}
if ( V_20 == V_8 ) {
V_17 = 0 ;
} else {
F_14 ( V_4 ) ;
V_17 = F_10 ( V_4 , V_14 , V_20 ) ;
if ( V_17 )
goto Exit;
}
for ( V_19 = 0 ; V_19 < V_16 ; V_19 ++ )
V_12 [ V_19 ] = V_15 [ V_19 ] >= 0 ? V_14 [ V_15 [ V_19 ] ] . V_37 : - 1 ;
Exit:
F_3 ( V_14 ) ;
return V_17 ;
Error:
F_14 ( V_4 ) ;
goto Exit;
}
static int F_15 ( struct V_11 * V_4 , int * V_38 , int V_13 )
{
int V_19 , V_39 = - 1 ;
if ( ( ( V_13 & V_27 ) && F_16 () ) ||
( ( V_13 & V_28 ) && F_17 () ) ) {
if ( V_4 -> V_39 )
V_39 = V_4 -> V_39 ;
goto V_40;
}
if ( ! F_6 ( V_4 , V_38 , V_13 ) )
return 0 ;
if ( ! F_18 ( V_4 ) || V_4 -> V_39 )
V_39 = V_4 -> V_39 ;
V_40:
for ( V_19 = 0 ; V_19 < V_16 ; V_19 ++ )
V_38 [ V_19 ] = V_39 ;
V_38 [ V_41 ] = - 1 ;
if ( V_39 < 0 )
return - V_42 ;
return 0 ;
}
static void F_19 ( struct V_11 * V_4 )
{
if ( V_4 -> V_43 )
F_14 ( V_4 ) ;
else if ( V_4 -> V_44 )
F_20 ( V_4 ) ;
}
static int F_21 ( struct V_11 * V_4 )
{
int V_45 = 0 ;
T_3 V_22 ;
int V_46 = 0 ;
int V_47 ;
if ( V_48 )
return 0 ;
V_46 = V_27 | V_28
| V_49 ;
if ( F_22 () )
V_46 |= V_33 ;
if ( V_50 ) {
V_47 = F_23 ( V_4 , & V_46 ) ;
if ( V_47 )
return 0 ;
}
if ( ( V_46 & V_28 ) &&
F_24 ( V_4 ) & V_51 ) {
F_25 ( V_4 , V_52 , & V_22 ) ;
if ( V_22 & V_53 ) {
V_45 |= V_28 ;
F_26 ( V_4 , V_54 ,
V_55 | V_56 ) ;
}
}
if ( ( V_46 & V_33 )
&& F_12 ( V_4 , V_34 ) ) {
V_45 |= V_33 ;
F_27 ( V_4 ) ;
}
if ( F_12 ( V_4 , V_57 ) )
V_45 |= V_49 ;
if ( ( V_46 & V_27 )
&& F_28 ( V_4 ) == V_58 ) {
V_45 |= V_27 ;
F_29 ( V_4 , false ) ;
}
return V_45 ;
}
static int F_30 ( struct V_11 * V_59 , int V_60 , int V_39 )
{
int V_61 ;
struct V_62 * V_63 ;
struct V_3 * V_3 ;
V_63 = F_9 ( sizeof( * V_63 ) , V_24 ) ;
if ( ! V_63 )
return - V_25 ;
V_63 -> V_64 = V_59 ;
V_63 -> V_39 = V_39 ;
V_63 -> V_60 = V_60 ;
V_3 = & V_63 -> V_3 ;
V_3 -> V_65 = & V_66 ;
V_3 -> V_67 = F_2 ;
F_31 ( V_3 , L_2 ,
F_32 ( V_59 ) ,
F_33 ( F_28 ( V_59 ) , V_60 ) ) ;
V_3 -> V_68 = & V_59 -> V_4 ;
F_34 ( V_3 ) ;
V_61 = F_35 ( V_3 ) ;
if ( V_61 ) {
F_36 ( V_3 ) ;
return V_61 ;
}
return 0 ;
}
int F_37 ( struct V_11 * V_4 )
{
int V_17 , V_69 , V_19 , V_70 ;
int V_38 [ V_16 ] ;
V_17 = F_38 ( V_4 ) ;
if ( V_17 )
return V_17 ;
V_69 = F_21 ( V_4 ) ;
if ( ! V_69 )
return 0 ;
F_39 ( V_4 ) ;
V_17 = F_15 ( V_4 , V_38 , V_69 ) ;
if ( V_17 ) {
V_69 &= V_49 ;
if ( ! V_69 )
goto V_71;
}
V_17 = - V_42 ;
V_70 = 0 ;
for ( V_19 = 0 ; V_19 < V_16 ; V_19 ++ ) {
int V_60 = 1 << V_19 ;
if ( ! ( V_69 & V_60 ) )
continue;
if ( ! F_30 ( V_4 , V_60 , V_38 [ V_19 ] ) )
V_70 ++ ;
}
if ( ! V_70 )
goto V_72;
return 0 ;
V_72:
F_19 ( V_4 ) ;
V_71:
F_40 ( V_4 ) ;
return V_17 ;
}
static int F_41 ( struct V_3 * V_4 , void * V_73 )
{
struct V_74 * V_75 ;
if ( ( V_4 -> V_65 == & V_66 ) && V_4 -> V_76 ) {
V_75 = F_42 ( V_4 -> V_76 ) ;
if ( V_75 -> V_77 )
V_75 -> V_77 ( F_4 ( V_4 ) ) ;
}
return 0 ;
}
int F_43 ( struct V_3 * V_4 )
{
return F_44 ( V_4 , NULL , F_41 ) ;
}
static int F_45 ( struct V_3 * V_4 , void * V_73 )
{
struct V_74 * V_75 ;
if ( ( V_4 -> V_65 == & V_66 ) &&
( V_4 -> V_76 ) ) {
V_75 = F_42 ( V_4 -> V_76 ) ;
if ( V_75 -> V_78 )
V_75 -> V_78 ( F_4 ( V_4 ) ) ;
}
return 0 ;
}
int F_46 ( struct V_3 * V_4 )
{
return F_44 ( V_4 , NULL , F_45 ) ;
}
static int F_47 ( struct V_3 * V_4 , void * V_73 )
{
if ( V_4 -> V_65 == & V_66 )
F_48 ( V_4 ) ;
return 0 ;
}
void F_49 ( struct V_11 * V_4 )
{
F_44 ( & V_4 -> V_4 , NULL , F_47 ) ;
F_19 ( V_4 ) ;
F_40 ( V_4 ) ;
}
static int F_50 ( struct V_3 * V_4 )
{
struct V_62 * V_79 ;
struct V_74 * V_76 ;
int V_17 ;
if ( ! V_4 || ! V_4 -> V_76 )
return - V_42 ;
V_76 = F_42 ( V_4 -> V_76 ) ;
if ( ! V_76 || ! V_76 -> V_80 )
return - V_42 ;
V_79 = F_4 ( V_4 ) ;
V_17 = V_76 -> V_80 ( V_79 ) ;
if ( V_17 )
return V_17 ;
F_51 ( V_81 , V_4 , L_3 , V_76 -> V_82 ) ;
F_52 ( V_4 ) ;
return 0 ;
}
static int F_53 ( struct V_3 * V_4 )
{
struct V_62 * V_79 ;
struct V_74 * V_76 ;
if ( ! V_4 || ! V_4 -> V_76 )
return 0 ;
V_79 = F_4 ( V_4 ) ;
V_76 = F_42 ( V_4 -> V_76 ) ;
if ( V_76 && V_76 -> remove ) {
F_51 ( V_81 , V_4 , L_4 ,
V_76 -> V_82 ) ;
V_76 -> remove ( V_79 ) ;
F_36 ( V_4 ) ;
}
return 0 ;
}
static void F_54 ( struct V_3 * V_4 ) {}
int F_55 ( struct V_74 * V_83 )
{
if ( V_48 )
return - V_42 ;
V_83 -> V_76 . V_82 = V_83 -> V_82 ;
V_83 -> V_76 . V_65 = & V_66 ;
V_83 -> V_76 . V_80 = F_50 ;
V_83 -> V_76 . remove = F_53 ;
V_83 -> V_76 . V_84 = F_54 ;
return F_56 ( & V_83 -> V_76 ) ;
}
void F_57 ( struct V_74 * V_85 )
{
F_58 ( & V_85 -> V_76 ) ;
}
