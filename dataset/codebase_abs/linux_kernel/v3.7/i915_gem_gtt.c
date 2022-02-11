static void F_1 ( struct V_1 * V_2 ,
unsigned V_3 ,
unsigned V_4 )
{
T_1 * V_5 ;
T_1 V_6 ;
unsigned V_7 = V_3 / V_8 ;
unsigned V_9 = V_3 % V_8 ;
unsigned V_10 , V_11 ;
V_6 = F_2 ( V_2 -> V_12 ) ;
V_6 |= V_13 | V_14 ;
while ( V_4 ) {
V_10 = V_9 + V_4 ;
if ( V_10 > V_8 )
V_10 = V_8 ;
V_5 = F_3 ( V_2 -> V_15 [ V_7 ] ) ;
for ( V_11 = V_9 ; V_11 < V_10 ; V_11 ++ )
V_5 [ V_11 ] = V_6 ;
F_4 ( V_5 ) ;
V_4 -= V_10 - V_9 ;
V_9 = 0 ;
V_7 ++ ;
}
}
int F_5 ( struct V_16 * V_17 )
{
struct V_18 * V_19 = V_17 -> V_20 ;
struct V_1 * V_2 ;
unsigned V_21 ;
int V_11 ;
int V_22 = - V_23 ;
V_21 = V_19 -> V_24 . V_25 -> V_26 - V_27 ;
V_2 = F_6 ( sizeof( * V_2 ) , V_28 ) ;
if ( ! V_2 )
return V_22 ;
V_2 -> V_29 = V_27 ;
V_2 -> V_15 = F_6 ( sizeof( struct V_30 * ) * V_2 -> V_29 ,
V_28 ) ;
if ( ! V_2 -> V_15 )
goto V_31;
for ( V_11 = 0 ; V_11 < V_2 -> V_29 ; V_11 ++ ) {
V_2 -> V_15 [ V_11 ] = F_7 ( V_28 ) ;
if ( ! V_2 -> V_15 [ V_11 ] )
goto V_32;
}
if ( V_19 -> V_24 . V_25 -> V_33 ) {
V_2 -> V_34 = F_6 ( sizeof( V_35 )
* V_2 -> V_29 ,
V_28 ) ;
if ( ! V_2 -> V_34 )
goto V_32;
for ( V_11 = 0 ; V_11 < V_2 -> V_29 ; V_11 ++ ) {
V_35 V_36 ;
V_36 = F_8 ( V_17 -> V_37 , V_2 -> V_15 [ V_11 ] ,
0 , 4096 ,
V_38 ) ;
if ( F_9 ( V_17 -> V_37 ,
V_36 ) ) {
V_22 = - V_39 ;
goto V_40;
}
V_2 -> V_34 [ V_11 ] = V_36 ;
}
}
V_2 -> V_12 = V_19 -> V_24 . V_25 -> V_41 ;
F_1 ( V_2 , 0 ,
V_2 -> V_29 * V_8 ) ;
V_2 -> V_42 = ( V_21 ) * sizeof( T_1 ) ;
V_19 -> V_24 . V_43 = V_2 ;
return 0 ;
V_40:
if ( V_2 -> V_34 ) {
for ( V_11 -- ; V_11 >= 0 ; V_11 -- )
F_10 ( V_17 -> V_37 , V_2 -> V_34 [ V_11 ] ,
4096 , V_38 ) ;
}
V_32:
F_11 ( V_2 -> V_34 ) ;
for ( V_11 = 0 ; V_11 < V_2 -> V_29 ; V_11 ++ ) {
if ( V_2 -> V_15 [ V_11 ] )
F_12 ( V_2 -> V_15 [ V_11 ] ) ;
}
F_11 ( V_2 -> V_15 ) ;
V_31:
F_11 ( V_2 ) ;
return V_22 ;
}
void F_13 ( struct V_16 * V_17 )
{
struct V_18 * V_19 = V_17 -> V_20 ;
struct V_1 * V_2 = V_19 -> V_24 . V_43 ;
int V_11 ;
if ( ! V_2 )
return;
if ( V_2 -> V_34 ) {
for ( V_11 = 0 ; V_11 < V_2 -> V_29 ; V_11 ++ )
F_10 ( V_17 -> V_37 , V_2 -> V_34 [ V_11 ] ,
4096 , V_38 ) ;
}
F_11 ( V_2 -> V_34 ) ;
for ( V_11 = 0 ; V_11 < V_2 -> V_29 ; V_11 ++ )
F_12 ( V_2 -> V_15 [ V_11 ] ) ;
F_11 ( V_2 -> V_15 ) ;
F_11 ( V_2 ) ;
}
static void F_14 ( struct V_1 * V_2 ,
const struct V_44 * V_45 ,
unsigned V_3 ,
T_1 V_46 )
{
T_1 * V_5 , V_47 ;
unsigned V_7 = V_3 / V_8 ;
unsigned V_9 = V_3 % V_8 ;
unsigned V_11 , V_48 , V_49 , V_50 ;
V_35 V_51 ;
struct V_52 * V_53 ;
V_53 = V_45 -> V_54 ;
V_11 = 0 ;
V_50 = F_15 ( V_53 ) >> V_55 ;
V_49 = 0 ;
while ( V_11 < V_45 -> V_56 ) {
V_5 = F_3 ( V_2 -> V_15 [ V_7 ] ) ;
for ( V_48 = V_9 ; V_48 < V_8 ; V_48 ++ ) {
V_51 = F_16 ( V_53 ) + ( V_49 << V_55 ) ;
V_47 = F_2 ( V_51 ) ;
V_5 [ V_48 ] = V_47 | V_46 ;
if ( ++ V_49 == V_50 ) {
if ( ++ V_11 == V_45 -> V_56 )
break;
V_53 = F_17 ( V_53 ) ;
V_50 = F_15 ( V_53 ) >> V_55 ;
V_49 = 0 ;
}
}
F_4 ( V_5 ) ;
V_9 = 0 ;
V_7 ++ ;
}
}
void F_18 ( struct V_1 * V_2 ,
struct V_57 * V_58 ,
enum V_59 V_60 )
{
T_1 V_46 = V_13 ;
switch ( V_60 ) {
case V_61 :
V_46 |= V_62 ;
break;
case V_63 :
V_46 |= V_14 ;
break;
case V_64 :
if ( F_19 ( V_58 -> V_65 . V_17 ) )
V_46 |= V_66 ;
else
V_46 |= V_67 ;
break;
default:
F_20 () ;
}
F_14 ( V_2 ,
V_58 -> V_45 ,
V_58 -> V_68 -> V_69 >> V_55 ,
V_46 ) ;
}
void F_21 ( struct V_1 * V_2 ,
struct V_57 * V_58 )
{
F_1 ( V_2 ,
V_58 -> V_68 -> V_69 >> V_55 ,
V_58 -> V_65 . V_70 >> V_55 ) ;
}
static unsigned int F_22 ( struct V_16 * V_17 ,
enum V_59 V_60 )
{
switch ( V_60 ) {
case V_61 :
if ( F_23 ( V_17 ) -> V_71 >= 6 )
return V_72 ;
case V_63 :
return V_73 ;
default:
case V_64 :
return V_74 ;
}
}
static bool F_24 ( struct V_18 * V_19 )
{
bool V_22 = V_19 -> V_24 . V_75 ;
if ( F_25 ( V_19 -> V_24 . V_25 -> V_76 ) ) {
V_19 -> V_24 . V_75 = false ;
if ( F_26 ( V_19 -> V_17 ) ) {
F_27 ( L_1 ) ;
F_28 ( 10 ) ;
}
}
return V_22 ;
}
static void F_29 ( struct V_18 * V_19 , bool V_75 )
{
if ( F_25 ( V_19 -> V_24 . V_25 -> V_76 ) )
V_19 -> V_24 . V_75 = V_75 ;
}
void F_30 ( struct V_16 * V_17 )
{
struct V_18 * V_19 = V_17 -> V_20 ;
struct V_57 * V_58 ;
F_31 ( V_19 -> V_24 . V_77 / V_78 ,
( V_19 -> V_24 . V_79 - V_19 -> V_24 . V_77 ) / V_78 ) ;
F_32 (obj, &dev_priv->mm.bound_list, gtt_list) {
F_33 ( V_58 ) ;
F_34 ( V_58 , V_58 -> V_60 ) ;
}
F_35 () ;
}
int F_36 ( struct V_57 * V_58 )
{
if ( V_58 -> V_80 )
return 0 ;
if ( ! F_37 ( & V_58 -> V_65 . V_17 -> V_37 -> V_17 ,
V_58 -> V_45 -> V_54 , V_58 -> V_45 -> V_56 ,
V_38 ) )
return - V_81 ;
return 0 ;
}
void F_34 ( struct V_57 * V_58 ,
enum V_59 V_60 )
{
struct V_16 * V_17 = V_58 -> V_65 . V_17 ;
unsigned int V_82 = F_22 ( V_17 , V_60 ) ;
F_38 ( V_58 -> V_45 ,
V_58 -> V_68 -> V_69 >> V_55 ,
V_82 ) ;
V_58 -> V_83 = 1 ;
}
void F_39 ( struct V_57 * V_58 )
{
F_31 ( V_58 -> V_68 -> V_69 >> V_55 ,
V_58 -> V_65 . V_70 >> V_55 ) ;
V_58 -> V_83 = 0 ;
}
void F_40 ( struct V_57 * V_58 )
{
struct V_16 * V_17 = V_58 -> V_65 . V_17 ;
struct V_18 * V_19 = V_17 -> V_20 ;
bool V_75 ;
V_75 = F_24 ( V_19 ) ;
if ( ! V_58 -> V_80 )
F_41 ( & V_17 -> V_37 -> V_17 ,
V_58 -> V_45 -> V_54 , V_58 -> V_45 -> V_56 ,
V_38 ) ;
F_29 ( V_19 , V_75 ) ;
}
static void F_42 ( struct V_84 * V_85 ,
unsigned long V_86 ,
unsigned long * V_69 ,
unsigned long * V_87 )
{
if ( V_85 -> V_86 != V_86 )
* V_69 += 4096 ;
if ( ! F_43 ( & V_85 -> V_88 ) ) {
V_85 = F_44 ( V_85 -> V_88 . V_89 ,
struct V_84 ,
V_88 ) ;
if ( V_85 -> V_90 && V_85 -> V_86 != V_86 )
* V_87 -= 4096 ;
}
}
void F_45 ( struct V_16 * V_17 ,
unsigned long V_69 ,
unsigned long V_91 ,
unsigned long V_87 )
{
T_2 * V_19 = V_17 -> V_20 ;
F_46 ( & V_19 -> V_24 . V_68 , V_69 , V_87 - V_69 - V_78 ) ;
if ( ! F_47 ( V_17 ) )
V_19 -> V_24 . V_68 . V_92 = F_42 ;
V_19 -> V_24 . V_77 = V_69 ;
V_19 -> V_24 . V_93 = V_91 ;
V_19 -> V_24 . V_79 = V_87 ;
V_19 -> V_24 . V_94 = V_87 - V_69 ;
V_19 -> V_24 . V_95 = F_48 ( V_87 , V_91 ) - V_69 ;
F_31 ( V_69 / V_78 , ( V_87 - V_69 ) / V_78 ) ;
}
