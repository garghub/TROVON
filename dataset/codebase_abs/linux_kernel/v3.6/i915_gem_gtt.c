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
struct V_44 * V_45 ,
unsigned V_46 ,
unsigned V_3 ,
T_1 V_47 )
{
T_1 * V_5 , V_48 ;
unsigned V_7 = V_3 / V_8 ;
unsigned V_9 = V_3 % V_8 ;
unsigned V_11 , V_49 , V_50 , V_51 ;
V_35 V_52 ;
struct V_44 * V_53 ;
V_53 = V_45 ;
V_11 = 0 ;
V_51 = F_15 ( V_53 ) >> V_54 ;
V_50 = 0 ;
while ( V_11 < V_46 ) {
V_5 = F_3 ( V_2 -> V_15 [ V_7 ] ) ;
for ( V_49 = V_9 ; V_49 < V_8 ; V_49 ++ ) {
V_52 = F_16 ( V_53 ) + ( V_50 << V_54 ) ;
V_48 = F_2 ( V_52 ) ;
V_5 [ V_49 ] = V_48 | V_47 ;
V_50 ++ ;
if ( V_50 == V_51 ) {
V_53 = F_17 ( V_53 ) ;
V_11 ++ ;
if ( V_11 == V_46 )
break;
V_51 = F_15 ( V_53 ) >> V_54 ;
V_50 = 0 ;
}
}
F_4 ( V_5 ) ;
V_9 = 0 ;
V_7 ++ ;
}
}
static void F_18 ( struct V_1 * V_2 ,
unsigned V_3 , unsigned V_4 ,
struct V_30 * * V_55 , T_1 V_47 )
{
T_1 * V_5 , V_48 ;
unsigned V_7 = V_3 / V_8 ;
unsigned V_9 = V_3 % V_8 ;
unsigned V_10 , V_11 ;
V_35 V_52 ;
while ( V_4 ) {
V_10 = V_9 + V_4 ;
V_10 = F_19 ( unsigned , V_10 , V_8 ) ;
V_5 = F_3 ( V_2 -> V_15 [ V_7 ] ) ;
for ( V_11 = V_9 ; V_11 < V_10 ; V_11 ++ ) {
V_52 = F_20 ( * V_55 ) ;
V_48 = F_2 ( V_52 ) ;
V_5 [ V_11 ] = V_48 | V_47 ;
V_55 ++ ;
}
F_4 ( V_5 ) ;
V_4 -= V_10 - V_9 ;
V_9 = 0 ;
V_7 ++ ;
}
}
void F_21 ( struct V_1 * V_2 ,
struct V_56 * V_57 ,
enum V_58 V_59 )
{
struct V_16 * V_17 = V_57 -> V_60 . V_17 ;
struct V_18 * V_19 = V_17 -> V_20 ;
T_1 V_47 = V_13 ;
switch ( V_59 ) {
case V_61 :
V_47 |= V_62 ;
break;
case V_63 :
V_47 |= V_14 ;
break;
case V_64 :
if ( F_22 ( V_17 ) )
V_47 |= V_65 ;
else
V_47 |= V_66 ;
break;
default:
F_23 () ;
}
if ( V_57 -> V_67 ) {
F_14 ( V_2 ,
V_57 -> V_67 -> V_68 ,
V_57 -> V_67 -> V_69 ,
V_57 -> V_70 -> V_71 >> V_54 ,
V_47 ) ;
} else if ( V_19 -> V_24 . V_25 -> V_33 ) {
F_24 ( ! V_57 -> V_45 ) ;
F_14 ( V_2 ,
V_57 -> V_45 ,
V_57 -> V_72 ,
V_57 -> V_70 -> V_71 >> V_54 ,
V_47 ) ;
} else
F_18 ( V_2 ,
V_57 -> V_70 -> V_71 >> V_54 ,
V_57 -> V_60 . V_73 >> V_54 ,
V_57 -> V_55 ,
V_47 ) ;
}
void F_25 ( struct V_1 * V_2 ,
struct V_56 * V_57 )
{
F_1 ( V_2 ,
V_57 -> V_70 -> V_71 >> V_54 ,
V_57 -> V_60 . V_73 >> V_54 ) ;
}
static unsigned int F_26 ( struct V_16 * V_17 ,
enum V_58 V_59 )
{
switch ( V_59 ) {
case V_61 :
if ( F_27 ( V_17 ) -> V_74 >= 6 )
return V_75 ;
case V_63 :
return V_76 ;
default:
case V_64 :
return V_77 ;
}
}
static bool F_28 ( struct V_18 * V_19 )
{
bool V_22 = V_19 -> V_24 . V_78 ;
if ( F_29 ( V_19 -> V_24 . V_25 -> V_79 ) ) {
V_19 -> V_24 . V_78 = false ;
if ( F_30 ( V_19 -> V_17 ) ) {
F_31 ( L_1 ) ;
F_32 ( 10 ) ;
}
}
return V_22 ;
}
static void F_33 ( struct V_18 * V_19 , bool V_78 )
{
if ( F_29 ( V_19 -> V_24 . V_25 -> V_79 ) )
V_19 -> V_24 . V_78 = V_78 ;
}
void F_34 ( struct V_16 * V_17 )
{
struct V_18 * V_19 = V_17 -> V_20 ;
struct V_56 * V_57 ;
F_35 ( V_19 -> V_24 . V_80 / V_81 ,
( V_19 -> V_24 . V_82 - V_19 -> V_24 . V_80 ) / V_81 ) ;
F_36 (obj, &dev_priv->mm.gtt_list, gtt_list) {
F_37 ( V_57 ) ;
F_38 ( V_57 , V_57 -> V_59 ) ;
}
F_39 () ;
}
int F_40 ( struct V_56 * V_57 )
{
struct V_16 * V_17 = V_57 -> V_60 . V_17 ;
struct V_18 * V_19 = V_17 -> V_20 ;
if ( V_19 -> V_24 . V_25 -> V_33 && ! V_57 -> V_67 )
return F_41 ( V_57 -> V_55 ,
V_57 -> V_60 . V_73 >> V_54 ,
& V_57 -> V_45 ,
& V_57 -> V_72 ) ;
else
return 0 ;
}
void F_38 ( struct V_56 * V_57 ,
enum V_58 V_59 )
{
struct V_16 * V_17 = V_57 -> V_60 . V_17 ;
struct V_18 * V_19 = V_17 -> V_20 ;
unsigned int V_83 = F_26 ( V_17 , V_59 ) ;
if ( V_57 -> V_67 ) {
F_42 ( V_57 -> V_67 -> V_68 ,
V_57 -> V_67 -> V_69 ,
V_57 -> V_70 -> V_71 >> V_54 ,
V_83 ) ;
} else if ( V_19 -> V_24 . V_25 -> V_33 ) {
F_24 ( ! V_57 -> V_45 ) ;
F_42 ( V_57 -> V_45 ,
V_57 -> V_72 ,
V_57 -> V_70 -> V_71 >> V_54 ,
V_83 ) ;
} else
F_43 ( V_57 -> V_70 -> V_71 >> V_54 ,
V_57 -> V_60 . V_73 >> V_54 ,
V_57 -> V_55 ,
V_83 ) ;
V_57 -> V_84 = 1 ;
}
void F_44 ( struct V_56 * V_57 )
{
F_35 ( V_57 -> V_70 -> V_71 >> V_54 ,
V_57 -> V_60 . V_73 >> V_54 ) ;
V_57 -> V_84 = 0 ;
}
void F_45 ( struct V_56 * V_57 )
{
struct V_16 * V_17 = V_57 -> V_60 . V_17 ;
struct V_18 * V_19 = V_17 -> V_20 ;
bool V_78 ;
V_78 = F_28 ( V_19 ) ;
if ( V_57 -> V_45 ) {
F_46 ( V_57 -> V_45 , V_57 -> V_72 ) ;
V_57 -> V_45 = NULL ;
}
F_33 ( V_19 , V_78 ) ;
}
void F_47 ( struct V_16 * V_17 ,
unsigned long V_71 ,
unsigned long V_85 ,
unsigned long V_86 )
{
T_2 * V_19 = V_17 -> V_20 ;
F_48 ( & V_19 -> V_24 . V_70 , V_71 , V_86 - V_71 - V_81 ) ;
V_19 -> V_24 . V_80 = V_71 ;
V_19 -> V_24 . V_87 = V_85 ;
V_19 -> V_24 . V_82 = V_86 ;
V_19 -> V_24 . V_88 = V_86 - V_71 ;
V_19 -> V_24 . V_89 = F_49 ( V_86 , V_85 ) - V_71 ;
F_35 ( V_71 / V_81 , ( V_86 - V_71 ) / V_81 ) ;
}
