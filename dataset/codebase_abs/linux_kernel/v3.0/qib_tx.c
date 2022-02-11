void F_1 ( struct V_1 * V_2 , unsigned V_3 , unsigned V_4 )
{
unsigned long V_5 ;
unsigned V_6 ;
unsigned V_7 ;
V_7 = V_3 + V_4 ;
F_2 ( & V_2 -> V_8 , V_5 ) ;
for ( V_6 = V_3 ; V_6 < V_7 ; V_6 ++ ) {
F_3 ( V_6 , V_2 -> V_9 ) ;
V_2 -> V_10 ( V_2 -> V_11 , F_4 ( V_6 ) ) ;
}
F_5 ( & V_2 -> V_8 , V_5 ) ;
}
int F_6 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
unsigned V_6 ;
unsigned V_7 ;
unsigned V_14 = 0 ;
V_7 = V_13 -> V_15 + V_13 -> V_16 ;
if ( V_13 -> V_17 ) {
F_7 ( V_18 , & V_13 -> V_17 [ 0 ] ) ;
for ( V_6 = 1 ; V_6 < V_13 -> V_19 ; V_6 ++ )
F_7 ( V_18 ,
& V_13 -> V_17 [ V_6 ] ) ;
}
F_8 ( & V_2 -> V_8 ) ;
for ( V_6 = V_13 -> V_15 ; V_6 < V_7 ; V_6 ++ ) {
if ( F_9 ( V_6 , V_2 -> V_9 ) ) {
V_14 ++ ;
V_2 -> V_10 ( V_13 -> V_20 , F_4 ( V_6 ) ) ;
}
}
F_10 ( & V_2 -> V_8 ) ;
return 0 ;
}
static struct V_21 * F_11 ( struct V_1 * V_2 , unsigned V_6 )
{
struct V_21 * V_20 ;
unsigned V_22 ;
for ( V_22 = 0 ; V_22 < V_2 -> V_23 ; V_22 ++ ) {
V_20 = V_2 -> V_11 + V_22 ;
if ( V_6 >= V_20 -> V_24 . V_25 &&
V_6 < V_20 -> V_24 . V_26 )
return V_20 ;
}
return NULL ;
}
static int F_12 ( struct V_1 * V_2 , unsigned V_27 )
{
struct V_12 * V_13 ;
unsigned V_28 ;
int V_29 = 0 ;
F_13 ( & V_2 -> V_30 ) ;
for ( V_28 = V_2 -> V_31 ; V_28 < V_2 -> V_32 ; V_28 ++ ) {
V_13 = V_2 -> V_13 [ V_28 ] ;
if ( ! V_13 || V_27 < V_13 -> V_15 ||
V_27 >= V_13 -> V_15 + V_13 -> V_16 )
continue;
if ( V_13 -> V_17 ) {
int V_6 ;
F_14 ( V_18 ,
& V_13 -> V_17 [ 0 ] ) ;
for ( V_6 = 1 ; V_6 < V_13 -> V_19 ; V_6 ++ )
F_14 ( V_18 ,
& V_13 -> V_17 [ V_6 ] ) ;
}
V_29 = 1 ;
break;
}
F_15 ( & V_2 -> V_30 ) ;
return V_29 ;
}
void F_16 ( struct V_1 * V_2 , unsigned long * V_33 ,
unsigned V_4 )
{
struct V_21 * V_20 , * V_34 [ V_35 ] ;
unsigned V_6 ;
unsigned long V_5 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_23 ; V_6 ++ )
V_34 [ V_6 ] = NULL ;
for ( V_6 = 0 ; V_6 < V_4 ; V_6 ++ ) {
int V_36 ;
if ( ! F_17 ( V_6 , V_33 ) )
continue;
V_20 = F_11 ( V_2 , V_6 ) ;
if ( V_20 ) {
V_34 [ V_20 -> V_37 ] = V_20 ;
continue;
}
F_2 ( & V_2 -> V_8 , V_5 ) ;
if ( F_17 ( V_6 , V_2 -> V_38 ) ||
( ! F_17 ( V_6 << 1 , V_2 -> V_39 ) &&
F_12 ( V_2 , V_6 ) ) ) {
F_18 ( V_6 , V_2 -> V_9 ) ;
V_36 = 0 ;
} else {
V_36 = 1 ;
V_2 -> V_10 ( V_2 -> V_11 , F_4 ( V_6 ) ) ;
}
F_5 ( & V_2 -> V_8 , V_5 ) ;
}
for ( V_6 = 0 ; V_6 < V_2 -> V_23 ; V_6 ++ )
if ( V_34 [ V_6 ] )
F_19 ( V_34 [ V_6 ] ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
unsigned long V_5 ;
unsigned V_6 ;
const unsigned V_40 = V_2 -> V_41 ;
if ( ! V_2 -> V_42 )
return;
F_2 ( & V_2 -> V_8 , V_5 ) ;
for ( V_6 = 0 ; V_6 < V_40 ; V_6 ++ ) {
T_1 V_43 , V_44 , V_45 , V_46 ;
V_45 = F_21 ( V_2 -> V_42 [ V_6 ] ) ;
V_44 = V_2 -> V_39 [ V_6 ] &
~ ( V_2 -> V_47 [ V_6 ] ^ V_45 ) ;
V_43 = V_44 << V_48 ;
if ( V_44 && ( V_43 & V_2 -> V_47 [ V_6 ] ) ) {
V_46 = V_2 -> V_47 [ V_6 ] & ~ V_43 ;
V_46 |= V_45 & V_43 ;
V_2 -> V_47 [ V_6 ] = V_46 ;
}
}
F_5 ( & V_2 -> V_8 , V_5 ) ;
}
static T_2 void F_22 ( struct V_1 * V_2 )
{
V_2 -> V_49 = 1 ;
V_50 . V_51 ++ ;
}
T_3 T_4 * F_23 ( struct V_1 * V_2 , T_3 * V_52 ,
T_3 V_3 , T_3 V_7 )
{
unsigned V_6 , V_53 , V_54 = 0 ;
unsigned V_55 ;
unsigned long V_5 ;
unsigned long * V_56 = V_2 -> V_47 ;
T_3 T_4 * V_57 ;
if ( ! ( V_2 -> V_5 & V_58 ) )
return NULL ;
V_55 = V_7 - V_3 + 1 ;
if ( V_2 -> V_49 ) {
F_20 ( V_2 ) ;
V_54 ++ ;
}
V_6 = V_3 ;
V_59:
F_2 ( & V_2 -> V_8 , V_5 ) ;
for ( V_53 = 0 ; V_53 < V_55 ; V_53 ++ , V_6 ++ ) {
if ( V_6 > V_7 )
V_6 = V_3 ;
if ( F_24 ( ( 2 * V_6 ) + 1 , V_56 ) )
continue;
F_25 ( 2 * V_6 , V_56 ) ;
F_18 ( V_6 , V_2 -> V_38 ) ;
break;
}
F_5 ( & V_2 -> V_8 , V_5 ) ;
if ( V_53 == V_55 ) {
if ( ! V_54 ) {
F_20 ( V_2 ) ;
V_54 ++ ;
V_6 = V_3 ;
goto V_59;
}
F_22 ( V_2 ) ;
V_57 = NULL ;
} else {
if ( V_6 < V_2 -> V_60 )
V_57 = ( T_3 T_4 * ) ( V_2 -> V_61 +
V_6 * V_2 -> V_62 ) ;
else if ( V_6 < V_2 -> V_60 + V_2 -> V_63 || ! V_2 -> V_64 )
V_57 = ( T_3 T_4 * ) ( V_2 -> V_65 +
( V_6 - V_2 -> V_60 ) * V_2 -> V_66 ) ;
else
V_57 = ( T_3 T_4 * ) ( V_2 -> V_64 +
( V_6 - ( V_2 -> V_60 + V_2 -> V_63 ) ) *
V_2 -> V_66 ) ;
if ( V_52 )
* V_52 = V_6 ;
V_2 -> V_49 = 0 ;
}
return V_57 ;
}
void F_26 ( struct V_1 * V_2 , unsigned V_14 )
{
unsigned long V_5 ;
F_2 ( & V_2 -> V_8 , V_5 ) ;
F_3 ( V_14 , V_2 -> V_38 ) ;
if ( F_9 ( V_14 , V_2 -> V_9 ) )
V_2 -> V_10 ( V_2 -> V_11 , F_4 ( V_14 ) ) ;
F_5 ( & V_2 -> V_8 , V_5 ) ;
}
void F_27 ( struct V_1 * V_2 , unsigned V_67 ,
unsigned V_68 , T_3 V_69 , struct V_12 * V_13 )
{
unsigned long V_5 ;
unsigned V_70 ;
unsigned V_71 = V_67 ;
V_67 *= 2 ;
V_70 = V_67 + V_68 * 2 ;
F_2 ( & V_2 -> V_8 , V_5 ) ;
while ( V_67 < V_70 ) {
if ( V_69 ) {
unsigned long V_72 ;
int V_6 ;
V_6 = V_67 / V_73 ;
F_3 ( V_48 + V_67 ,
V_2 -> V_47 ) ;
V_72 = ( unsigned long )
F_21 ( V_2 -> V_42 [ V_6 ] ) ;
if ( F_17 ( ( V_74 +
V_67 ) % V_73 , & V_72 ) )
F_18 ( V_74 +
V_67 , V_2 -> V_47 ) ;
else
F_3 ( V_74
+ V_67 , V_2 -> V_47 ) ;
F_18 ( V_67 , V_2 -> V_39 ) ;
} else {
F_18 ( V_67 + V_48 ,
V_2 -> V_47 ) ;
F_3 ( V_67 , V_2 -> V_39 ) ;
}
V_67 += 2 ;
}
F_5 ( & V_2 -> V_8 , V_5 ) ;
V_2 -> V_75 ( V_2 , V_71 , V_68 , V_69 , V_13 ) ;
}
void F_19 ( struct V_21 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_2 ;
struct V_12 * V_13 ;
unsigned long V_5 ;
unsigned V_28 ;
unsigned V_6 ;
unsigned V_7 ;
for ( V_28 = V_2 -> V_31 ; V_28 < V_2 -> V_32 ; V_28 ++ ) {
F_2 ( & V_2 -> V_30 , V_5 ) ;
V_13 = V_2 -> V_13 [ V_28 ] ;
if ( V_13 && V_13 -> V_20 == V_20 ) {
V_7 = V_13 -> V_15 + V_13 -> V_16 ;
if ( V_13 -> V_17 ) {
F_14 ( V_18 ,
& V_13 -> V_17 [ 0 ] ) ;
for ( V_6 = 1 ; V_6 < V_13 -> V_19 ; V_6 ++ )
F_14 ( V_18 ,
& V_13 -> V_17 [ V_6 ] ) ;
}
V_6 = V_13 -> V_15 ;
F_5 ( & V_2 -> V_30 , V_5 ) ;
F_2 ( & V_2 -> V_8 , V_5 ) ;
for (; V_6 < V_7 ; V_6 ++ )
F_18 ( V_6 , V_2 -> V_9 ) ;
F_5 ( & V_2 -> V_8 , V_5 ) ;
} else
F_5 ( & V_2 -> V_30 , V_5 ) ;
}
if ( ! ( V_2 -> V_5 & V_76 ) )
V_2 -> V_10 ( V_20 , V_77 |
V_78 ) ;
}
void F_28 ( struct V_1 * V_2 )
{
V_2 -> V_10 ( V_2 -> V_11 , V_79 ) ;
}
void F_29 ( struct V_21 * V_20 )
{
if ( ! ( V_20 -> V_80 & V_81 ) )
F_19 ( V_20 ) ;
}
void F_30 ( struct V_21 * V_20 )
{
if ( V_20 -> V_82 != V_83 ) {
V_20 -> V_82 = V_83 ;
F_31 ( & V_20 -> V_84 ,
V_85 + F_32 ( V_86 ) ) ;
}
}
void F_33 ( struct V_21 * V_20 )
{
V_20 -> V_82 = V_87 ;
}
void F_34 ( unsigned long V_88 )
{
struct V_21 * V_20 = (struct V_21 * ) V_88 ;
if ( ! ( V_20 -> V_2 -> V_5 & V_89 ) )
return;
if ( V_20 -> V_82 != V_87 ) {
F_29 ( V_20 ) ;
F_31 ( & V_20 -> V_84 ,
V_85 + F_32 ( V_86 ) ) ;
}
}
