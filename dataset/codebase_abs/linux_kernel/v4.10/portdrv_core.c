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
int V_46 = 0 ;
if ( V_47 )
return 0 ;
V_46 = V_27 | V_28
| V_48 | V_49 ;
if ( F_22 () )
V_46 |= V_33 ;
if ( V_50 )
F_23 ( V_4 , & V_46 ) ;
if ( ( V_46 & V_28 ) && V_4 -> V_51 ) {
V_45 |= V_28 ;
F_24 ( V_4 , V_52 ,
V_53 | V_54 ) ;
}
if ( ( V_46 & V_33 )
&& F_12 ( V_4 , V_34 ) ) {
V_45 |= V_33 ;
F_25 ( V_4 ) ;
}
if ( F_12 ( V_4 , V_55 ) )
V_45 |= V_48 ;
if ( ( V_46 & V_27 )
&& F_26 ( V_4 ) == V_56 ) {
V_45 |= V_27 ;
F_27 ( V_4 , false ) ;
}
if ( F_12 ( V_4 , V_57 ) )
V_45 |= V_49 ;
return V_45 ;
}
static int F_28 ( struct V_11 * V_58 , int V_59 , int V_39 )
{
int V_60 ;
struct V_61 * V_62 ;
struct V_3 * V_3 ;
V_62 = F_9 ( sizeof( * V_62 ) , V_24 ) ;
if ( ! V_62 )
return - V_25 ;
V_62 -> V_63 = V_58 ;
V_62 -> V_39 = V_39 ;
V_62 -> V_59 = V_59 ;
V_3 = & V_62 -> V_3 ;
V_3 -> V_64 = & V_65 ;
V_3 -> V_66 = F_2 ;
F_29 ( V_3 , L_2 ,
F_30 ( V_58 ) ,
F_31 ( F_26 ( V_58 ) , V_59 ) ) ;
V_3 -> V_67 = & V_58 -> V_4 ;
F_32 ( V_3 ) ;
V_60 = F_33 ( V_3 ) ;
if ( V_60 ) {
F_34 ( V_3 ) ;
return V_60 ;
}
F_35 ( V_3 ) ;
return 0 ;
}
int F_36 ( struct V_11 * V_4 )
{
int V_17 , V_68 , V_19 , V_69 ;
int V_38 [ V_16 ] ;
V_17 = F_37 ( V_4 ) ;
if ( V_17 )
return V_17 ;
V_68 = F_21 ( V_4 ) ;
if ( ! V_68 )
return 0 ;
F_38 ( V_4 ) ;
V_17 = F_15 ( V_4 , V_38 , V_68 ) ;
if ( V_17 ) {
V_68 &= V_48 | V_28 ;
if ( ! V_68 )
goto V_70;
}
V_17 = - V_42 ;
V_69 = 0 ;
for ( V_19 = 0 ; V_19 < V_16 ; V_19 ++ ) {
int V_59 = 1 << V_19 ;
if ( ! ( V_68 & V_59 ) )
continue;
if ( ! F_28 ( V_4 , V_59 , V_38 [ V_19 ] ) )
V_69 ++ ;
}
if ( ! V_69 )
goto V_71;
return 0 ;
V_71:
F_19 ( V_4 ) ;
V_70:
F_39 ( V_4 ) ;
return V_17 ;
}
static int F_40 ( struct V_3 * V_4 , void * V_72 )
{
struct V_73 * V_74 ;
if ( ( V_4 -> V_64 == & V_65 ) && V_4 -> V_75 ) {
V_74 = F_41 ( V_4 -> V_75 ) ;
if ( V_74 -> V_76 )
V_74 -> V_76 ( F_4 ( V_4 ) ) ;
}
return 0 ;
}
int F_42 ( struct V_3 * V_4 )
{
return F_43 ( V_4 , NULL , F_40 ) ;
}
static int F_44 ( struct V_3 * V_4 , void * V_72 )
{
struct V_73 * V_74 ;
if ( ( V_4 -> V_64 == & V_65 ) &&
( V_4 -> V_75 ) ) {
V_74 = F_41 ( V_4 -> V_75 ) ;
if ( V_74 -> V_77 )
V_74 -> V_77 ( F_4 ( V_4 ) ) ;
}
return 0 ;
}
int F_45 ( struct V_3 * V_4 )
{
return F_43 ( V_4 , NULL , F_44 ) ;
}
static int F_46 ( struct V_3 * V_4 , void * V_72 )
{
if ( V_4 -> V_64 == & V_65 )
F_47 ( V_4 ) ;
return 0 ;
}
void F_48 ( struct V_11 * V_4 )
{
F_43 ( & V_4 -> V_4 , NULL , F_46 ) ;
F_19 ( V_4 ) ;
F_39 ( V_4 ) ;
}
static int F_49 ( struct V_3 * V_4 )
{
struct V_61 * V_78 ;
struct V_73 * V_75 ;
int V_17 ;
if ( ! V_4 || ! V_4 -> V_75 )
return - V_42 ;
V_75 = F_41 ( V_4 -> V_75 ) ;
if ( ! V_75 || ! V_75 -> V_79 )
return - V_42 ;
V_78 = F_4 ( V_4 ) ;
V_17 = V_75 -> V_79 ( V_78 ) ;
if ( V_17 )
return V_17 ;
F_50 ( V_4 ) ;
return 0 ;
}
static int F_51 ( struct V_3 * V_4 )
{
struct V_61 * V_78 ;
struct V_73 * V_75 ;
if ( ! V_4 || ! V_4 -> V_75 )
return 0 ;
V_78 = F_4 ( V_4 ) ;
V_75 = F_41 ( V_4 -> V_75 ) ;
if ( V_75 && V_75 -> remove ) {
V_75 -> remove ( V_78 ) ;
F_34 ( V_4 ) ;
}
return 0 ;
}
static void F_52 ( struct V_3 * V_4 ) {}
int F_53 ( struct V_73 * V_80 )
{
if ( V_47 )
return - V_42 ;
V_80 -> V_75 . V_81 = V_80 -> V_81 ;
V_80 -> V_75 . V_64 = & V_65 ;
V_80 -> V_75 . V_79 = F_49 ;
V_80 -> V_75 . remove = F_51 ;
V_80 -> V_75 . V_82 = F_52 ;
return F_54 ( & V_80 -> V_75 ) ;
}
void F_55 ( struct V_73 * V_83 )
{
F_56 ( & V_83 -> V_75 ) ;
}
