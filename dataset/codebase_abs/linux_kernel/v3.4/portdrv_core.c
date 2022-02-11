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
V_18 = F_10 ( V_4 ) ;
F_11 ( V_4 , V_18 + V_30 , & V_21 ) ;
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
V_18 = F_12 ( V_4 , V_35 ) ;
F_13 ( V_4 , V_18 + V_36 , & V_22 ) ;
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
F_14 ( V_4 ) ;
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
F_14 ( V_4 ) ;
goto Exit;
}
static int F_15 ( struct V_11 * V_4 , int * V_39 , int V_13 )
{
int V_19 , V_40 = - 1 ;
if ( ( ( V_13 & V_28 ) && F_16 () ) ||
( ( V_13 & V_29 ) && F_17 () ) ) {
if ( V_4 -> V_41 )
V_40 = V_4 -> V_40 ;
goto V_42;
}
if ( ! F_6 ( V_4 , V_39 , V_13 ) )
return 0 ;
if ( ! F_18 ( V_4 ) || V_4 -> V_41 )
V_40 = V_4 -> V_40 ;
V_42:
for ( V_19 = 0 ; V_19 < V_16 ; V_19 ++ )
V_39 [ V_19 ] = V_40 ;
V_39 [ V_43 ] = - 1 ;
if ( V_40 < 0 )
return - V_44 ;
return 0 ;
}
static void F_19 ( struct V_11 * V_4 )
{
if ( V_4 -> V_45 )
F_14 ( V_4 ) ;
else if ( V_4 -> V_46 )
F_20 ( V_4 ) ;
}
static int F_21 ( struct V_11 * V_4 )
{
int V_47 = 0 , V_18 ;
T_2 V_21 ;
T_3 V_22 ;
int V_48 ;
int V_49 ;
if ( V_50 )
return 0 ;
V_49 = F_22 ( V_4 , & V_48 ) ;
if ( ! V_51 ) {
V_48 = V_28 | V_29
| V_52 ;
if ( F_23 () )
V_48 |= V_34 ;
} else if ( V_49 ) {
return 0 ;
}
V_18 = F_10 ( V_4 ) ;
F_11 ( V_4 , V_18 + V_30 , & V_21 ) ;
if ( ( V_48 & V_29 ) && ( V_21 & V_53 ) ) {
F_13 ( V_4 , V_18 + V_54 , & V_22 ) ;
if ( V_22 & V_55 ) {
V_47 |= V_29 ;
V_18 += V_56 ;
F_11 ( V_4 , V_18 , & V_21 ) ;
V_21 &= ~ ( V_57 | V_58 ) ;
F_24 ( V_4 , V_18 , V_21 ) ;
}
}
if ( ( V_48 & V_34 )
&& F_12 ( V_4 , V_35 ) ) {
V_47 |= V_34 ;
F_25 ( V_4 ) ;
}
if ( F_12 ( V_4 , V_59 ) )
V_47 |= V_52 ;
if ( ( V_48 & V_28 )
&& V_4 -> V_60 == V_61 ) {
V_47 |= V_28 ;
F_26 ( V_4 , false ) ;
}
return V_47 ;
}
static int F_27 ( struct V_11 * V_62 , int V_63 , int V_40 )
{
int V_64 ;
struct V_65 * V_66 ;
struct V_3 * V_3 ;
V_66 = F_8 ( sizeof( * V_66 ) , V_25 ) ;
if ( ! V_66 )
return - V_26 ;
V_66 -> V_67 = V_62 ;
V_66 -> V_40 = V_40 ;
V_66 -> V_63 = V_63 ;
V_3 = & V_66 -> V_3 ;
V_3 -> V_68 = & V_69 ;
V_3 -> V_70 = F_2 ;
F_28 ( V_3 , L_2 ,
F_29 ( V_62 ) ,
F_30 ( V_62 -> V_60 , V_63 ) ) ;
V_3 -> V_71 = & V_62 -> V_4 ;
F_31 ( V_3 ) ;
V_64 = F_32 ( V_3 ) ;
if ( V_64 )
F_3 ( V_66 ) ;
else
F_33 ( V_3 ) ;
return V_64 ;
}
int F_34 ( struct V_11 * V_4 )
{
int V_17 , V_72 , V_19 , V_73 ;
int V_39 [ V_16 ] ;
V_17 = F_35 ( V_4 ) ;
if ( V_17 )
return V_17 ;
V_72 = F_21 ( V_4 ) ;
if ( ! V_72 )
return 0 ;
F_36 ( V_4 ) ;
V_17 = F_15 ( V_4 , V_39 , V_72 ) ;
if ( V_17 ) {
V_72 &= V_52 ;
if ( ! V_72 )
goto V_74;
}
V_17 = - V_44 ;
V_73 = 0 ;
for ( V_19 = 0 ; V_19 < V_16 ; V_19 ++ ) {
int V_63 = 1 << V_19 ;
if ( ! ( V_72 & V_63 ) )
continue;
if ( ! F_27 ( V_4 , V_63 , V_39 [ V_19 ] ) )
V_73 ++ ;
}
if ( ! V_73 )
goto V_75;
return 0 ;
V_75:
F_19 ( V_4 ) ;
V_74:
F_37 ( V_4 ) ;
return V_17 ;
}
static int F_38 ( struct V_3 * V_4 , void * V_76 )
{
struct V_77 * V_78 ;
if ( ( V_4 -> V_68 == & V_69 ) && V_4 -> V_79 ) {
V_78 = F_39 ( V_4 -> V_79 ) ;
if ( V_78 -> V_80 )
V_78 -> V_80 ( F_4 ( V_4 ) ) ;
}
return 0 ;
}
int F_40 ( struct V_3 * V_4 )
{
return F_41 ( V_4 , NULL , F_38 ) ;
}
static int F_42 ( struct V_3 * V_4 , void * V_76 )
{
struct V_77 * V_78 ;
if ( ( V_4 -> V_68 == & V_69 ) &&
( V_4 -> V_79 ) ) {
V_78 = F_39 ( V_4 -> V_79 ) ;
if ( V_78 -> V_81 )
V_78 -> V_81 ( F_4 ( V_4 ) ) ;
}
return 0 ;
}
int F_43 ( struct V_3 * V_4 )
{
return F_41 ( V_4 , NULL , F_42 ) ;
}
static int F_44 ( struct V_3 * V_4 , void * V_76 )
{
if ( V_4 -> V_68 == & V_69 ) {
F_45 ( V_4 ) ;
F_46 ( V_4 ) ;
}
return 0 ;
}
void F_47 ( struct V_11 * V_4 )
{
F_41 ( & V_4 -> V_4 , NULL , F_44 ) ;
F_19 ( V_4 ) ;
F_37 ( V_4 ) ;
}
static int F_48 ( struct V_3 * V_4 )
{
struct V_65 * V_82 ;
struct V_77 * V_79 ;
int V_17 ;
if ( ! V_4 || ! V_4 -> V_79 )
return - V_44 ;
V_79 = F_39 ( V_4 -> V_79 ) ;
if ( ! V_79 || ! V_79 -> V_83 )
return - V_44 ;
V_82 = F_4 ( V_4 ) ;
V_17 = V_79 -> V_83 ( V_82 ) ;
if ( ! V_17 ) {
F_49 ( V_84 , V_4 , L_3 ,
V_79 -> V_85 ) ;
F_33 ( V_4 ) ;
}
return V_17 ;
}
static int F_50 ( struct V_3 * V_4 )
{
struct V_65 * V_82 ;
struct V_77 * V_79 ;
if ( ! V_4 || ! V_4 -> V_79 )
return 0 ;
V_82 = F_4 ( V_4 ) ;
V_79 = F_39 ( V_4 -> V_79 ) ;
if ( V_79 && V_79 -> remove ) {
F_49 ( V_84 , V_4 , L_4 ,
V_79 -> V_85 ) ;
V_79 -> remove ( V_82 ) ;
F_45 ( V_4 ) ;
}
return 0 ;
}
static void F_51 ( struct V_3 * V_4 ) {}
int F_52 ( struct V_77 * V_86 )
{
if ( V_50 )
return - V_44 ;
V_86 -> V_79 . V_85 = ( char * ) V_86 -> V_85 ;
V_86 -> V_79 . V_68 = & V_69 ;
V_86 -> V_79 . V_83 = F_48 ;
V_86 -> V_79 . remove = F_50 ;
V_86 -> V_79 . V_87 = F_51 ;
return F_53 ( & V_86 -> V_79 ) ;
}
void F_54 ( struct V_77 * V_88 )
{
F_55 ( & V_88 -> V_79 ) ;
}
