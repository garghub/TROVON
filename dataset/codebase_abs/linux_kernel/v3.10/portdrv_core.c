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
if ( ! V_8 )
return - V_23 ;
if ( V_8 > V_24 )
V_8 = V_24 ;
V_14 = F_8 ( sizeof( * V_14 ) * V_8 , V_25 ) ;
if ( ! V_14 )
return - V_26 ;
for ( V_19 = 0 ; V_19 < V_8 ; V_19 ++ )
V_14 [ V_19 ] . V_10 = V_19 ;
V_17 = F_9 ( V_4 , V_14 , V_8 ) ;
if ( V_17 )
goto Exit;
for ( V_19 = 0 ; V_19 < V_16 ; V_19 ++ )
V_15 [ V_19 ] = - 1 ;
V_17 = - V_27 ;
V_20 = 0 ;
if ( V_13 & ( V_28 | V_29 ) ) {
int V_10 ;
F_10 ( V_4 , V_30 , & V_21 ) ;
V_10 = ( V_21 & V_31 ) >> 9 ;
if ( V_10 >= V_8 )
goto Error;
V_19 = F_5 ( V_14 , V_10 , V_20 ) ;
if ( V_19 == V_20 )
V_20 ++ ;
V_15 [ V_32 ] = V_19 ;
V_15 [ V_33 ] = V_19 ;
}
if ( V_13 & V_34 ) {
int V_10 ;
V_18 = F_11 ( V_4 , V_35 ) ;
F_12 ( V_4 , V_18 + V_36 , & V_22 ) ;
V_10 = V_22 >> 27 ;
if ( V_10 >= V_8 )
goto Error;
V_19 = F_5 ( V_14 , V_10 , V_20 ) ;
if ( V_19 == V_20 )
V_20 ++ ;
V_15 [ V_37 ] = V_19 ;
}
if ( V_20 == V_8 ) {
V_17 = 0 ;
} else {
F_13 ( V_4 ) ;
V_17 = F_9 ( V_4 , V_14 , V_20 ) ;
if ( V_17 )
goto Exit;
}
for ( V_19 = 0 ; V_19 < V_16 ; V_19 ++ )
V_12 [ V_19 ] = V_15 [ V_19 ] >= 0 ? V_14 [ V_15 [ V_19 ] ] . V_38 : - 1 ;
Exit:
F_3 ( V_14 ) ;
return V_17 ;
Error:
F_13 ( V_4 ) ;
goto Exit;
}
static int F_14 ( struct V_11 * V_4 , int * V_39 , int V_13 )
{
int V_19 , V_40 = - 1 ;
if ( ( ( V_13 & V_28 ) && F_15 () ) ||
( ( V_13 & V_29 ) && F_16 () ) ) {
if ( V_4 -> V_40 )
V_40 = V_4 -> V_40 ;
goto V_41;
}
if ( ! F_6 ( V_4 , V_39 , V_13 ) )
return 0 ;
if ( ! F_17 ( V_4 ) || V_4 -> V_40 )
V_40 = V_4 -> V_40 ;
V_41:
for ( V_19 = 0 ; V_19 < V_16 ; V_19 ++ )
V_39 [ V_19 ] = V_40 ;
V_39 [ V_42 ] = - 1 ;
if ( V_40 < 0 )
return - V_43 ;
return 0 ;
}
static void F_18 ( struct V_11 * V_4 )
{
if ( V_4 -> V_44 )
F_13 ( V_4 ) ;
else if ( V_4 -> V_45 )
F_19 ( V_4 ) ;
}
static int F_20 ( struct V_11 * V_4 )
{
int V_46 = 0 ;
T_3 V_22 ;
int V_47 = 0 ;
int V_48 ;
if ( V_49 )
return 0 ;
V_48 = F_21 ( V_4 , & V_47 ) ;
if ( ! V_50 ) {
V_47 = V_28 | V_29
| V_51 ;
if ( F_22 () )
V_47 |= V_34 ;
} else if ( V_48 ) {
return 0 ;
}
if ( ( V_47 & V_29 ) &&
F_23 ( V_4 ) & V_52 ) {
F_24 ( V_4 , V_53 , & V_22 ) ;
if ( V_22 & V_54 ) {
V_46 |= V_29 ;
F_25 ( V_4 , V_55 ,
V_56 | V_57 ) ;
}
}
if ( ( V_47 & V_34 )
&& F_11 ( V_4 , V_35 ) ) {
V_46 |= V_34 ;
F_26 ( V_4 ) ;
}
if ( F_11 ( V_4 , V_58 ) )
V_46 |= V_51 ;
if ( ( V_47 & V_28 )
&& F_27 ( V_4 ) == V_59 ) {
V_46 |= V_28 ;
F_28 ( V_4 , false ) ;
}
return V_46 ;
}
static int F_29 ( struct V_11 * V_60 , int V_61 , int V_40 )
{
int V_62 ;
struct V_63 * V_64 ;
struct V_3 * V_3 ;
V_64 = F_8 ( sizeof( * V_64 ) , V_25 ) ;
if ( ! V_64 )
return - V_26 ;
V_64 -> V_65 = V_60 ;
V_64 -> V_40 = V_40 ;
V_64 -> V_61 = V_61 ;
V_3 = & V_64 -> V_3 ;
V_3 -> V_66 = & V_67 ;
V_3 -> V_68 = F_2 ;
F_30 ( V_3 , L_2 ,
F_31 ( V_60 ) ,
F_32 ( F_27 ( V_60 ) , V_61 ) ) ;
V_3 -> V_69 = & V_60 -> V_4 ;
F_33 ( V_3 ) ;
V_62 = F_34 ( V_3 ) ;
if ( V_62 )
F_3 ( V_64 ) ;
else
F_35 ( V_3 ) ;
return V_62 ;
}
int F_36 ( struct V_11 * V_4 )
{
int V_17 , V_70 , V_19 , V_71 ;
int V_39 [ V_16 ] ;
V_17 = F_37 ( V_4 ) ;
if ( V_17 )
return V_17 ;
V_70 = F_20 ( V_4 ) ;
if ( ! V_70 )
return 0 ;
F_38 ( V_4 ) ;
V_17 = F_14 ( V_4 , V_39 , V_70 ) ;
if ( V_17 ) {
V_70 &= V_51 ;
if ( ! V_70 )
goto V_72;
}
V_17 = - V_43 ;
V_71 = 0 ;
for ( V_19 = 0 ; V_19 < V_16 ; V_19 ++ ) {
int V_61 = 1 << V_19 ;
if ( ! ( V_70 & V_61 ) )
continue;
if ( ! F_29 ( V_4 , V_61 , V_39 [ V_19 ] ) )
V_71 ++ ;
}
if ( ! V_71 )
goto V_73;
return 0 ;
V_73:
F_18 ( V_4 ) ;
V_72:
F_39 ( V_4 ) ;
return V_17 ;
}
static int F_40 ( struct V_3 * V_4 , void * V_74 )
{
struct V_75 * V_76 ;
if ( ( V_4 -> V_66 == & V_67 ) && V_4 -> V_77 ) {
V_76 = F_41 ( V_4 -> V_77 ) ;
if ( V_76 -> V_78 )
V_76 -> V_78 ( F_4 ( V_4 ) ) ;
}
return 0 ;
}
int F_42 ( struct V_3 * V_4 )
{
return F_43 ( V_4 , NULL , F_40 ) ;
}
static int F_44 ( struct V_3 * V_4 , void * V_74 )
{
struct V_75 * V_76 ;
if ( ( V_4 -> V_66 == & V_67 ) &&
( V_4 -> V_77 ) ) {
V_76 = F_41 ( V_4 -> V_77 ) ;
if ( V_76 -> V_79 )
V_76 -> V_79 ( F_4 ( V_4 ) ) ;
}
return 0 ;
}
int F_45 ( struct V_3 * V_4 )
{
return F_43 ( V_4 , NULL , F_44 ) ;
}
static int F_46 ( struct V_3 * V_4 , void * V_74 )
{
if ( V_4 -> V_66 == & V_67 ) {
F_47 ( V_4 ) ;
F_48 ( V_4 ) ;
}
return 0 ;
}
void F_49 ( struct V_11 * V_4 )
{
F_43 ( & V_4 -> V_4 , NULL , F_46 ) ;
F_18 ( V_4 ) ;
F_39 ( V_4 ) ;
}
static int F_50 ( struct V_3 * V_4 )
{
struct V_63 * V_80 ;
struct V_75 * V_77 ;
int V_17 ;
if ( ! V_4 || ! V_4 -> V_77 )
return - V_43 ;
V_77 = F_41 ( V_4 -> V_77 ) ;
if ( ! V_77 || ! V_77 -> V_81 )
return - V_43 ;
V_80 = F_4 ( V_4 ) ;
V_17 = V_77 -> V_81 ( V_80 ) ;
if ( ! V_17 ) {
F_51 ( V_82 , V_4 , L_3 ,
V_77 -> V_83 ) ;
F_35 ( V_4 ) ;
}
return V_17 ;
}
static int F_52 ( struct V_3 * V_4 )
{
struct V_63 * V_80 ;
struct V_75 * V_77 ;
if ( ! V_4 || ! V_4 -> V_77 )
return 0 ;
V_80 = F_4 ( V_4 ) ;
V_77 = F_41 ( V_4 -> V_77 ) ;
if ( V_77 && V_77 -> remove ) {
F_51 ( V_82 , V_4 , L_4 ,
V_77 -> V_83 ) ;
V_77 -> remove ( V_80 ) ;
F_47 ( V_4 ) ;
}
return 0 ;
}
static void F_53 ( struct V_3 * V_4 ) {}
int F_54 ( struct V_75 * V_84 )
{
if ( V_49 )
return - V_43 ;
V_84 -> V_77 . V_83 = ( char * ) V_84 -> V_83 ;
V_84 -> V_77 . V_66 = & V_67 ;
V_84 -> V_77 . V_81 = F_50 ;
V_84 -> V_77 . remove = F_52 ;
V_84 -> V_77 . V_85 = F_53 ;
return F_55 ( & V_84 -> V_77 ) ;
}
void F_56 ( struct V_75 * V_86 )
{
F_57 ( & V_86 -> V_77 ) ;
}
