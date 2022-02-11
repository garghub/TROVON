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
V_21 = 512 * 1024 - V_24 ;
V_2 = F_6 ( sizeof( * V_2 ) , V_25 ) ;
if ( ! V_2 )
return V_22 ;
V_2 -> V_26 = V_24 ;
V_2 -> V_15 = F_6 ( sizeof( struct V_27 * ) * V_2 -> V_26 ,
V_25 ) ;
if ( ! V_2 -> V_15 )
goto V_28;
for ( V_11 = 0 ; V_11 < V_2 -> V_26 ; V_11 ++ ) {
V_2 -> V_15 [ V_11 ] = F_7 ( V_25 ) ;
if ( ! V_2 -> V_15 [ V_11 ] )
goto V_29;
}
if ( V_19 -> V_30 . V_31 -> V_32 ) {
V_2 -> V_33 = F_6 ( sizeof( V_34 )
* V_2 -> V_26 ,
V_25 ) ;
if ( ! V_2 -> V_33 )
goto V_29;
}
for ( V_11 = 0 ; V_11 < V_2 -> V_26 ; V_11 ++ ) {
V_34 V_35 ;
if ( V_19 -> V_30 . V_31 -> V_32 ) {
V_35 = F_8 ( V_17 -> V_36 , V_2 -> V_15 [ V_11 ] ,
0 , 4096 ,
V_37 ) ;
if ( F_9 ( V_17 -> V_36 ,
V_35 ) ) {
V_22 = - V_38 ;
goto V_39;
}
V_2 -> V_33 [ V_11 ] = V_35 ;
} else
V_35 = F_10 ( V_2 -> V_15 [ V_11 ] ) ;
}
V_2 -> V_12 = V_19 -> V_30 . V_31 -> V_40 ;
F_1 ( V_2 , 0 ,
V_2 -> V_26 * V_8 ) ;
V_2 -> V_41 = ( V_21 ) * sizeof( T_1 ) ;
V_19 -> V_30 . V_42 = V_2 ;
return 0 ;
V_39:
if ( V_2 -> V_33 ) {
for ( V_11 -- ; V_11 >= 0 ; V_11 -- )
F_11 ( V_17 -> V_36 , V_2 -> V_33 [ V_11 ] ,
4096 , V_37 ) ;
}
V_29:
F_12 ( V_2 -> V_33 ) ;
for ( V_11 = 0 ; V_11 < V_2 -> V_26 ; V_11 ++ ) {
if ( V_2 -> V_15 [ V_11 ] )
F_13 ( V_2 -> V_15 [ V_11 ] ) ;
}
F_12 ( V_2 -> V_15 ) ;
V_28:
F_12 ( V_2 ) ;
return V_22 ;
}
void F_14 ( struct V_16 * V_17 )
{
struct V_18 * V_19 = V_17 -> V_20 ;
struct V_1 * V_2 = V_19 -> V_30 . V_42 ;
int V_11 ;
if ( ! V_2 )
return;
if ( V_2 -> V_33 ) {
for ( V_11 = 0 ; V_11 < V_2 -> V_26 ; V_11 ++ )
F_11 ( V_17 -> V_36 , V_2 -> V_33 [ V_11 ] ,
4096 , V_37 ) ;
}
F_12 ( V_2 -> V_33 ) ;
for ( V_11 = 0 ; V_11 < V_2 -> V_26 ; V_11 ++ )
F_13 ( V_2 -> V_15 [ V_11 ] ) ;
F_12 ( V_2 -> V_15 ) ;
F_12 ( V_2 ) ;
}
static void F_15 ( struct V_1 * V_2 ,
struct V_43 * V_44 ,
unsigned V_45 ,
unsigned V_3 ,
T_1 V_46 )
{
T_1 * V_5 , V_47 ;
unsigned V_7 = V_3 / V_8 ;
unsigned V_9 = V_3 % V_8 ;
unsigned V_11 , V_48 , V_49 , V_50 ;
V_34 V_51 ;
struct V_43 * V_52 ;
V_52 = V_44 ;
V_11 = 0 ;
V_50 = F_16 ( V_52 ) >> V_53 ;
V_49 = 0 ;
while ( V_11 < V_45 ) {
V_5 = F_3 ( V_2 -> V_15 [ V_7 ] ) ;
for ( V_48 = V_9 ; V_48 < V_8 ; V_48 ++ ) {
V_51 = F_17 ( V_52 ) + ( V_49 << V_53 ) ;
V_47 = F_2 ( V_51 ) ;
V_5 [ V_48 ] = V_47 | V_46 ;
V_49 ++ ;
if ( V_49 == V_50 ) {
V_52 = F_18 ( V_52 ) ;
V_11 ++ ;
if ( V_11 == V_45 )
break;
V_50 = F_16 ( V_52 ) >> V_53 ;
V_49 = 0 ;
}
}
F_4 ( V_5 ) ;
V_9 = 0 ;
V_7 ++ ;
}
}
static void F_19 ( struct V_1 * V_2 ,
unsigned V_3 , unsigned V_4 ,
struct V_27 * * V_54 , T_1 V_46 )
{
T_1 * V_5 , V_47 ;
unsigned V_7 = V_3 / V_8 ;
unsigned V_9 = V_3 % V_8 ;
unsigned V_10 , V_11 ;
V_34 V_51 ;
while ( V_4 ) {
V_10 = V_9 + V_4 ;
V_10 = F_20 ( unsigned , V_10 , V_8 ) ;
V_5 = F_3 ( V_2 -> V_15 [ V_7 ] ) ;
for ( V_11 = V_9 ; V_11 < V_10 ; V_11 ++ ) {
V_51 = F_10 ( * V_54 ) ;
V_47 = F_2 ( V_51 ) ;
V_5 [ V_11 ] = V_47 | V_46 ;
V_54 ++ ;
}
F_4 ( V_5 ) ;
V_4 -= V_10 - V_9 ;
V_9 = 0 ;
V_7 ++ ;
}
}
void F_21 ( struct V_1 * V_2 ,
struct V_55 * V_56 ,
enum V_57 V_58 )
{
struct V_16 * V_17 = V_56 -> V_59 . V_17 ;
struct V_18 * V_19 = V_17 -> V_20 ;
T_1 V_46 = V_13 ;
switch ( V_58 ) {
case V_60 :
V_46 |= V_61 ;
break;
case V_62 :
V_46 |= V_14 ;
break;
case V_63 :
V_46 |= V_64 ;
break;
default:
F_22 () ;
}
if ( V_19 -> V_30 . V_31 -> V_32 ) {
F_23 ( ! V_56 -> V_44 ) ;
F_15 ( V_2 ,
V_56 -> V_44 ,
V_56 -> V_65 ,
V_56 -> V_66 -> V_67 >> V_53 ,
V_46 ) ;
} else
F_19 ( V_2 ,
V_56 -> V_66 -> V_67 >> V_53 ,
V_56 -> V_59 . V_68 >> V_53 ,
V_56 -> V_54 ,
V_46 ) ;
}
void F_24 ( struct V_1 * V_2 ,
struct V_55 * V_56 )
{
F_1 ( V_2 ,
V_56 -> V_66 -> V_67 >> V_53 ,
V_56 -> V_59 . V_68 >> V_53 ) ;
}
static unsigned int F_25 ( struct V_16 * V_17 ,
enum V_57 V_58 )
{
switch ( V_58 ) {
case V_60 :
if ( F_26 ( V_17 ) -> V_69 >= 6 )
return V_70 ;
case V_62 :
return V_71 ;
default:
case V_63 :
return V_72 ;
}
}
static bool F_27 ( struct V_18 * V_19 )
{
bool V_22 = V_19 -> V_30 . V_73 ;
if ( F_28 ( V_19 -> V_30 . V_31 -> V_74 ) ) {
V_19 -> V_30 . V_73 = false ;
if ( F_29 ( V_19 -> V_17 , false ) ) {
F_30 ( L_1 ) ;
F_31 ( 10 ) ;
}
}
return V_22 ;
}
static void F_32 ( struct V_18 * V_19 , bool V_73 )
{
if ( F_28 ( V_19 -> V_30 . V_31 -> V_74 ) )
V_19 -> V_30 . V_73 = V_73 ;
}
void F_33 ( struct V_16 * V_17 )
{
struct V_18 * V_19 = V_17 -> V_20 ;
struct V_55 * V_56 ;
F_34 ( V_19 -> V_30 . V_75 / V_76 ,
( V_19 -> V_30 . V_77 - V_19 -> V_30 . V_75 ) / V_76 ) ;
F_35 (obj, &dev_priv->mm.gtt_list, gtt_list) {
F_36 ( V_56 ) ;
F_37 ( V_56 , V_56 -> V_58 ) ;
}
F_38 () ;
}
int F_39 ( struct V_55 * V_56 )
{
struct V_16 * V_17 = V_56 -> V_59 . V_17 ;
struct V_18 * V_19 = V_17 -> V_20 ;
unsigned int V_78 = F_25 ( V_17 , V_56 -> V_58 ) ;
int V_22 ;
if ( V_19 -> V_30 . V_31 -> V_32 ) {
V_22 = F_40 ( V_56 -> V_54 ,
V_56 -> V_59 . V_68 >> V_53 ,
& V_56 -> V_44 ,
& V_56 -> V_65 ) ;
if ( V_22 != 0 )
return V_22 ;
F_41 ( V_56 -> V_44 ,
V_56 -> V_65 ,
V_56 -> V_66 -> V_67 >> V_53 ,
V_78 ) ;
} else
F_42 ( V_56 -> V_66 -> V_67 >> V_53 ,
V_56 -> V_59 . V_68 >> V_53 ,
V_56 -> V_54 ,
V_78 ) ;
return 0 ;
}
void F_37 ( struct V_55 * V_56 ,
enum V_57 V_58 )
{
struct V_16 * V_17 = V_56 -> V_59 . V_17 ;
struct V_18 * V_19 = V_17 -> V_20 ;
unsigned int V_78 = F_25 ( V_17 , V_58 ) ;
if ( V_19 -> V_30 . V_31 -> V_32 ) {
F_23 ( ! V_56 -> V_44 ) ;
F_41 ( V_56 -> V_44 ,
V_56 -> V_65 ,
V_56 -> V_66 -> V_67 >> V_53 ,
V_78 ) ;
} else
F_42 ( V_56 -> V_66 -> V_67 >> V_53 ,
V_56 -> V_59 . V_68 >> V_53 ,
V_56 -> V_54 ,
V_78 ) ;
}
void F_43 ( struct V_55 * V_56 )
{
struct V_16 * V_17 = V_56 -> V_59 . V_17 ;
struct V_18 * V_19 = V_17 -> V_20 ;
bool V_73 ;
V_73 = F_27 ( V_19 ) ;
F_34 ( V_56 -> V_66 -> V_67 >> V_53 ,
V_56 -> V_59 . V_68 >> V_53 ) ;
if ( V_56 -> V_44 ) {
F_44 ( V_56 -> V_44 , V_56 -> V_65 ) ;
V_56 -> V_44 = NULL ;
}
F_32 ( V_19 , V_73 ) ;
}
