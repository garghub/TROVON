static void F_1 ( struct V_1 * V_2 )
{
F_2 ( F_3 ( V_2 ) ) ;
}
static int F_4 (
struct V_3 * V_4 , int V_5 , int V_6 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_6 ; V_7 ++ )
if ( V_4 [ V_7 ] . V_8 == V_5 )
return V_7 ;
V_4 [ V_7 ] . V_8 = V_5 ;
return V_7 ;
}
static int F_5 ( struct V_9 * V_2 , int * V_10 , int V_11 )
{
struct V_3 * V_12 ;
int V_13 [ V_14 ] ;
int V_6 , V_15 , V_16 , V_17 , V_18 ;
T_1 V_19 ;
T_2 V_20 ;
V_6 = F_6 ( V_2 ) ;
if ( ! V_6 )
return - V_21 ;
if ( V_6 > V_22 )
V_6 = V_22 ;
V_12 = F_7 ( sizeof( * V_12 ) * V_6 , V_23 ) ;
if ( ! V_12 )
return - V_24 ;
for ( V_17 = 0 ; V_17 < V_6 ; V_17 ++ )
V_12 [ V_17 ] . V_8 = V_17 ;
V_15 = F_8 ( V_2 , V_12 , V_6 ) ;
if ( V_15 )
goto Exit;
for ( V_17 = 0 ; V_17 < V_14 ; V_17 ++ )
V_13 [ V_17 ] = - 1 ;
V_15 = - V_25 ;
V_18 = 0 ;
if ( V_11 & ( V_26 | V_27 ) ) {
int V_8 ;
V_16 = F_9 ( V_2 ) ;
F_10 ( V_2 , V_16 + V_28 , & V_19 ) ;
V_8 = ( V_19 & V_29 ) >> 9 ;
if ( V_8 >= V_6 )
goto Error;
V_17 = F_4 ( V_12 , V_8 , V_18 ) ;
if ( V_17 == V_18 )
V_18 ++ ;
V_13 [ V_30 ] = V_17 ;
V_13 [ V_31 ] = V_17 ;
}
if ( V_11 & V_32 ) {
int V_8 ;
V_16 = F_11 ( V_2 , V_33 ) ;
F_12 ( V_2 , V_16 + V_34 , & V_20 ) ;
V_8 = V_20 >> 27 ;
if ( V_8 >= V_6 )
goto Error;
V_17 = F_4 ( V_12 , V_8 , V_18 ) ;
if ( V_17 == V_18 )
V_18 ++ ;
V_13 [ V_35 ] = V_17 ;
}
if ( V_18 == V_6 ) {
V_15 = 0 ;
} else {
F_13 ( V_2 ) ;
V_15 = F_8 ( V_2 , V_12 , V_18 ) ;
if ( V_15 )
goto Exit;
}
for ( V_17 = 0 ; V_17 < V_14 ; V_17 ++ )
V_10 [ V_17 ] = V_13 [ V_17 ] >= 0 ? V_12 [ V_13 [ V_17 ] ] . V_36 : - 1 ;
Exit:
F_2 ( V_12 ) ;
return V_15 ;
Error:
F_13 ( V_2 ) ;
goto Exit;
}
static int F_14 ( struct V_9 * V_2 , int * V_37 , int V_11 )
{
int V_17 , V_38 = - 1 ;
if ( ( V_11 & V_26 ) && F_15 () ) {
if ( V_2 -> V_39 )
V_38 = V_2 -> V_38 ;
goto V_40;
}
if ( ! F_5 ( V_2 , V_37 , V_11 ) )
return 0 ;
if ( ! F_16 ( V_2 ) || V_2 -> V_39 )
V_38 = V_2 -> V_38 ;
V_40:
for ( V_17 = 0 ; V_17 < V_14 ; V_17 ++ )
V_37 [ V_17 ] = V_38 ;
V_37 [ V_41 ] = - 1 ;
if ( V_38 < 0 )
return - V_42 ;
return 0 ;
}
static void F_17 ( struct V_9 * V_2 )
{
if ( V_2 -> V_43 )
F_13 ( V_2 ) ;
else if ( V_2 -> V_44 )
F_18 ( V_2 ) ;
}
static int F_19 ( struct V_9 * V_2 )
{
int V_45 = 0 , V_16 ;
T_1 V_19 ;
T_2 V_20 ;
int V_46 ;
int V_47 ;
if ( V_48 )
return 0 ;
V_47 = F_20 ( V_2 , & V_46 ) ;
if ( ! V_49 ) {
V_46 = V_26 | V_27
| V_50 ;
if ( F_21 () )
V_46 |= V_32 ;
} else if ( V_47 ) {
return 0 ;
}
V_16 = F_9 ( V_2 ) ;
F_10 ( V_2 , V_16 + V_28 , & V_19 ) ;
if ( ( V_46 & V_27 ) && ( V_19 & V_51 ) ) {
F_12 ( V_2 , V_16 + V_52 , & V_20 ) ;
if ( V_20 & V_53 ) {
V_45 |= V_27 ;
V_16 += V_54 ;
F_10 ( V_2 , V_16 , & V_19 ) ;
V_19 &= ~ ( V_55 | V_56 ) ;
F_22 ( V_2 , V_16 , V_19 ) ;
}
}
if ( ( V_46 & V_32 )
&& F_11 ( V_2 , V_33 ) ) {
V_45 |= V_32 ;
F_23 ( V_2 ) ;
}
if ( F_11 ( V_2 , V_57 ) )
V_45 |= V_50 ;
if ( ( V_46 & V_26 )
&& V_2 -> V_58 == V_59 ) {
V_45 |= V_26 ;
F_24 ( V_2 , false ) ;
}
return V_45 ;
}
static int F_25 ( struct V_9 * V_60 , int V_61 , int V_38 )
{
int V_62 ;
struct V_63 * V_64 ;
struct V_1 * V_1 ;
V_64 = F_7 ( sizeof( * V_64 ) , V_23 ) ;
if ( ! V_64 )
return - V_24 ;
V_64 -> V_65 = V_60 ;
V_64 -> V_38 = V_38 ;
V_64 -> V_61 = V_61 ;
V_1 = & V_64 -> V_1 ;
V_1 -> V_66 = & V_67 ;
V_1 -> V_68 = F_1 ;
F_26 ( V_1 , L_1 ,
F_27 ( V_60 ) ,
F_28 ( V_60 -> V_58 , V_61 ) ) ;
V_1 -> V_69 = & V_60 -> V_2 ;
F_29 ( V_1 ) ;
V_62 = F_30 ( V_1 ) ;
if ( V_62 )
F_2 ( V_64 ) ;
else
F_31 ( V_1 ) ;
return V_62 ;
}
int F_32 ( struct V_9 * V_2 )
{
int V_15 , V_70 , V_17 , V_71 ;
int V_37 [ V_14 ] ;
V_15 = F_33 ( V_2 ) ;
if ( V_15 )
return V_15 ;
V_70 = F_19 ( V_2 ) ;
if ( ! V_70 )
return 0 ;
F_34 ( V_2 ) ;
V_15 = F_14 ( V_2 , V_37 , V_70 ) ;
if ( V_15 ) {
V_70 &= V_50 ;
if ( ! V_70 )
goto V_72;
}
V_15 = - V_42 ;
V_71 = 0 ;
for ( V_17 = 0 ; V_17 < V_14 ; V_17 ++ ) {
int V_61 = 1 << V_17 ;
if ( ! ( V_70 & V_61 ) )
continue;
if ( ! F_25 ( V_2 , V_61 , V_37 [ V_17 ] ) )
V_71 ++ ;
}
if ( ! V_71 )
goto V_73;
return 0 ;
V_73:
F_17 ( V_2 ) ;
V_72:
F_35 ( V_2 ) ;
return V_15 ;
}
static int F_36 ( struct V_1 * V_2 , void * V_74 )
{
struct V_75 * V_76 ;
if ( ( V_2 -> V_66 == & V_67 ) && V_2 -> V_77 ) {
V_76 = F_37 ( V_2 -> V_77 ) ;
if ( V_76 -> V_78 )
V_76 -> V_78 ( F_3 ( V_2 ) ) ;
}
return 0 ;
}
int F_38 ( struct V_1 * V_2 )
{
return F_39 ( V_2 , NULL , F_36 ) ;
}
static int F_40 ( struct V_1 * V_2 , void * V_74 )
{
struct V_75 * V_76 ;
if ( ( V_2 -> V_66 == & V_67 ) &&
( V_2 -> V_77 ) ) {
V_76 = F_37 ( V_2 -> V_77 ) ;
if ( V_76 -> V_79 )
V_76 -> V_79 ( F_3 ( V_2 ) ) ;
}
return 0 ;
}
int F_41 ( struct V_1 * V_2 )
{
return F_39 ( V_2 , NULL , F_40 ) ;
}
static int F_42 ( struct V_1 * V_2 , void * V_74 )
{
if ( V_2 -> V_66 == & V_67 ) {
F_43 ( V_2 ) ;
F_44 ( V_2 ) ;
}
return 0 ;
}
void F_45 ( struct V_9 * V_2 )
{
F_39 ( & V_2 -> V_2 , NULL , F_42 ) ;
F_17 ( V_2 ) ;
F_35 ( V_2 ) ;
}
static int F_46 ( struct V_1 * V_2 )
{
struct V_63 * V_80 ;
struct V_75 * V_77 ;
int V_15 ;
if ( ! V_2 || ! V_2 -> V_77 )
return - V_42 ;
V_77 = F_37 ( V_2 -> V_77 ) ;
if ( ! V_77 || ! V_77 -> V_81 )
return - V_42 ;
V_80 = F_3 ( V_2 ) ;
V_15 = V_77 -> V_81 ( V_80 ) ;
if ( ! V_15 ) {
F_47 ( V_82 , V_2 , L_2 ,
V_77 -> V_83 ) ;
F_31 ( V_2 ) ;
}
return V_15 ;
}
static int F_48 ( struct V_1 * V_2 )
{
struct V_63 * V_80 ;
struct V_75 * V_77 ;
if ( ! V_2 || ! V_2 -> V_77 )
return 0 ;
V_80 = F_3 ( V_2 ) ;
V_77 = F_37 ( V_2 -> V_77 ) ;
if ( V_77 && V_77 -> remove ) {
F_47 ( V_82 , V_2 , L_3 ,
V_77 -> V_83 ) ;
V_77 -> remove ( V_80 ) ;
F_43 ( V_2 ) ;
}
return 0 ;
}
static void F_49 ( struct V_1 * V_2 ) {}
int F_50 ( struct V_75 * V_84 )
{
if ( V_48 )
return - V_42 ;
V_84 -> V_77 . V_83 = ( char * ) V_84 -> V_83 ;
V_84 -> V_77 . V_66 = & V_67 ;
V_84 -> V_77 . V_81 = F_46 ;
V_84 -> V_77 . remove = F_48 ;
V_84 -> V_77 . V_85 = F_49 ;
return F_51 ( & V_84 -> V_77 ) ;
}
void F_52 ( struct V_75 * V_86 )
{
F_53 ( & V_86 -> V_77 ) ;
}
