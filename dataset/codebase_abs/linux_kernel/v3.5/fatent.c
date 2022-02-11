static void F_1 ( struct V_1 * V_2 , int V_3 ,
int * V_4 , T_1 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_8 = V_3 + ( V_3 >> 1 ) ;
F_3 ( V_3 < V_9 || V_7 -> V_10 <= V_3 ) ;
* V_4 = V_8 & ( V_2 -> V_11 - 1 ) ;
* V_5 = V_7 -> V_12 + ( V_8 >> V_2 -> V_13 ) ;
}
static void F_4 ( struct V_1 * V_2 , int V_3 ,
int * V_4 , T_1 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_8 = ( V_3 << V_7 -> V_14 ) ;
F_3 ( V_3 < V_9 || V_7 -> V_10 <= V_3 ) ;
* V_4 = V_8 & ( V_2 -> V_11 - 1 ) ;
* V_5 = V_7 -> V_12 + ( V_8 >> V_2 -> V_13 ) ;
}
static void F_5 ( struct V_15 * V_16 , int V_4 )
{
struct V_17 * * V_18 = V_16 -> V_18 ;
if ( V_16 -> V_19 == 1 ) {
F_3 ( V_4 >= ( V_18 [ 0 ] -> V_20 - 1 ) ) ;
V_16 -> V_21 . V_22 [ 0 ] = V_18 [ 0 ] -> V_23 + V_4 ;
V_16 -> V_21 . V_22 [ 1 ] = V_18 [ 0 ] -> V_23 + ( V_4 + 1 ) ;
} else {
F_3 ( V_4 != ( V_18 [ 0 ] -> V_20 - 1 ) ) ;
V_16 -> V_21 . V_22 [ 0 ] = V_18 [ 0 ] -> V_23 + V_4 ;
V_16 -> V_21 . V_22 [ 1 ] = V_18 [ 1 ] -> V_23 ;
}
}
static void F_6 ( struct V_15 * V_16 , int V_4 )
{
F_3 ( V_4 & ( 2 - 1 ) ) ;
V_16 -> V_21 . V_24 = ( V_25 * ) ( V_16 -> V_18 [ 0 ] -> V_23 + V_4 ) ;
}
static void F_7 ( struct V_15 * V_16 , int V_4 )
{
F_3 ( V_4 & ( 4 - 1 ) ) ;
V_16 -> V_21 . V_26 = ( V_27 * ) ( V_16 -> V_18 [ 0 ] -> V_23 + V_4 ) ;
}
static int F_8 ( struct V_1 * V_2 , struct V_15 * V_16 ,
int V_4 , T_1 V_5 )
{
struct V_17 * * V_18 = V_16 -> V_18 ;
F_3 ( V_5 < F_2 ( V_2 ) -> V_12 ) ;
V_16 -> V_28 = F_2 ( V_2 ) -> V_28 ;
V_18 [ 0 ] = F_9 ( V_2 , V_5 ) ;
if ( ! V_18 [ 0 ] )
goto V_29;
if ( ( V_4 + 1 ) < V_2 -> V_11 )
V_16 -> V_19 = 1 ;
else {
V_5 ++ ;
V_18 [ 1 ] = F_9 ( V_2 , V_5 ) ;
if ( ! V_18 [ 1 ] )
goto V_30;
V_16 -> V_19 = 2 ;
}
F_5 ( V_16 , V_4 ) ;
return 0 ;
V_30:
F_10 ( V_18 [ 0 ] ) ;
V_29:
F_11 ( V_2 , V_31 , L_1 , ( V_32 ) V_5 ) ;
return - V_33 ;
}
static int F_12 ( struct V_1 * V_2 , struct V_15 * V_16 ,
int V_4 , T_1 V_5 )
{
struct V_34 * V_35 = F_2 ( V_2 ) -> V_36 ;
F_3 ( V_5 < F_2 ( V_2 ) -> V_12 ) ;
V_16 -> V_28 = F_2 ( V_2 ) -> V_28 ;
V_16 -> V_18 [ 0 ] = F_9 ( V_2 , V_5 ) ;
if ( ! V_16 -> V_18 [ 0 ] ) {
F_11 ( V_2 , V_31 , L_1 ,
( V_32 ) V_5 ) ;
return - V_33 ;
}
V_16 -> V_19 = 1 ;
V_35 -> V_37 ( V_16 , V_4 ) ;
return 0 ;
}
static int F_13 ( struct V_15 * V_16 )
{
T_2 * * V_22 = V_16 -> V_21 . V_22 ;
int V_38 ;
F_14 ( & V_39 ) ;
if ( V_16 -> V_3 & 1 )
V_38 = ( * V_22 [ 0 ] >> 4 ) | ( * V_22 [ 1 ] << 4 ) ;
else
V_38 = ( * V_22 [ 1 ] << 8 ) | * V_22 [ 0 ] ;
F_15 ( & V_39 ) ;
V_38 &= 0x0fff ;
if ( V_38 >= V_40 )
V_38 = V_41 ;
return V_38 ;
}
static int F_16 ( struct V_15 * V_16 )
{
int V_38 = F_17 ( * V_16 -> V_21 . V_24 ) ;
F_3 ( ( unsigned long ) V_16 -> V_21 . V_24 & ( 2 - 1 ) ) ;
if ( V_38 >= V_42 )
V_38 = V_41 ;
return V_38 ;
}
static int F_18 ( struct V_15 * V_16 )
{
int V_38 = F_19 ( * V_16 -> V_21 . V_26 ) & 0x0fffffff ;
F_3 ( ( unsigned long ) V_16 -> V_21 . V_26 & ( 4 - 1 ) ) ;
if ( V_38 >= V_43 )
V_38 = V_41 ;
return V_38 ;
}
static void F_20 ( struct V_15 * V_16 , int V_44 )
{
T_2 * * V_22 = V_16 -> V_21 . V_22 ;
if ( V_44 == V_41 )
V_44 = V_45 ;
F_14 ( & V_39 ) ;
if ( V_16 -> V_3 & 1 ) {
* V_22 [ 0 ] = ( V_44 << 4 ) | ( * V_22 [ 0 ] & 0x0f ) ;
* V_22 [ 1 ] = V_44 >> 4 ;
} else {
* V_22 [ 0 ] = V_44 & 0xff ;
* V_22 [ 1 ] = ( * V_22 [ 1 ] & 0xf0 ) | ( V_44 >> 8 ) ;
}
F_15 ( & V_39 ) ;
F_21 ( V_16 -> V_18 [ 0 ] , V_16 -> V_28 ) ;
if ( V_16 -> V_19 == 2 )
F_21 ( V_16 -> V_18 [ 1 ] , V_16 -> V_28 ) ;
}
static void F_22 ( struct V_15 * V_16 , int V_44 )
{
if ( V_44 == V_41 )
V_44 = V_46 ;
* V_16 -> V_21 . V_24 = F_23 ( V_44 ) ;
F_21 ( V_16 -> V_18 [ 0 ] , V_16 -> V_28 ) ;
}
static void F_24 ( struct V_15 * V_16 , int V_44 )
{
if ( V_44 == V_41 )
V_44 = V_47 ;
F_3 ( V_44 & 0xf0000000 ) ;
V_44 |= F_19 ( * V_16 -> V_21 . V_26 ) & ~ 0x0fffffff ;
* V_16 -> V_21 . V_26 = F_25 ( V_44 ) ;
F_21 ( V_16 -> V_18 [ 0 ] , V_16 -> V_28 ) ;
}
static int F_26 ( struct V_15 * V_16 )
{
T_2 * * V_22 = V_16 -> V_21 . V_22 ;
struct V_17 * * V_18 = V_16 -> V_18 ;
T_2 * V_48 = V_22 [ 1 ] + 1 + ( V_16 -> V_3 & 1 ) ;
V_16 -> V_3 ++ ;
if ( V_16 -> V_19 == 1 ) {
F_3 ( V_22 [ 0 ] > ( T_2 * ) ( V_18 [ 0 ] -> V_23 + ( V_18 [ 0 ] -> V_20 - 2 ) ) ) ;
F_3 ( V_22 [ 1 ] > ( T_2 * ) ( V_18 [ 0 ] -> V_23 + ( V_18 [ 0 ] -> V_20 - 1 ) ) ) ;
if ( V_48 < ( T_2 * ) ( V_18 [ 0 ] -> V_23 + ( V_18 [ 0 ] -> V_20 - 1 ) ) ) {
V_22 [ 0 ] = V_48 - 1 ;
V_22 [ 1 ] = V_48 ;
return 1 ;
}
} else {
F_3 ( V_22 [ 0 ] != ( T_2 * ) ( V_18 [ 0 ] -> V_23 + ( V_18 [ 0 ] -> V_20 - 1 ) ) ) ;
F_3 ( V_22 [ 1 ] != ( T_2 * ) V_18 [ 1 ] -> V_23 ) ;
V_22 [ 0 ] = V_48 - 1 ;
V_22 [ 1 ] = V_48 ;
F_10 ( V_18 [ 0 ] ) ;
V_18 [ 0 ] = V_18 [ 1 ] ;
V_16 -> V_19 = 1 ;
return 1 ;
}
V_22 [ 0 ] = NULL ;
V_22 [ 1 ] = NULL ;
return 0 ;
}
static int F_27 ( struct V_15 * V_16 )
{
const struct V_17 * V_49 = V_16 -> V_18 [ 0 ] ;
V_16 -> V_3 ++ ;
if ( V_16 -> V_21 . V_24 < ( V_25 * ) ( V_49 -> V_23 + ( V_49 -> V_20 - 2 ) ) ) {
V_16 -> V_21 . V_24 ++ ;
return 1 ;
}
V_16 -> V_21 . V_24 = NULL ;
return 0 ;
}
static int F_28 ( struct V_15 * V_16 )
{
const struct V_17 * V_49 = V_16 -> V_18 [ 0 ] ;
V_16 -> V_3 ++ ;
if ( V_16 -> V_21 . V_26 < ( V_27 * ) ( V_49 -> V_23 + ( V_49 -> V_20 - 4 ) ) ) {
V_16 -> V_21 . V_26 ++ ;
return 1 ;
}
V_16 -> V_21 . V_26 = NULL ;
return 0 ;
}
static inline void F_29 ( struct V_6 * V_7 )
{
F_30 ( & V_7 -> V_50 ) ;
}
static inline void F_31 ( struct V_6 * V_7 )
{
F_32 ( & V_7 -> V_50 ) ;
}
void F_33 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_34 ( & V_7 -> V_50 ) ;
switch ( V_7 -> V_51 ) {
case 32 :
V_7 -> V_14 = 2 ;
V_7 -> V_36 = & V_52 ;
break;
case 16 :
V_7 -> V_14 = 1 ;
V_7 -> V_36 = & V_53 ;
break;
case 12 :
V_7 -> V_14 = - 1 ;
V_7 -> V_36 = & V_54 ;
break;
}
}
static void F_35 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( V_2 -> V_55 & V_56 || V_7 -> V_51 != 32 )
return;
F_36 ( V_7 -> V_57 , V_58 ) ;
}
static inline int F_37 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
int V_4 , T_1 V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_34 * V_35 = V_7 -> V_36 ;
struct V_17 * * V_18 = V_16 -> V_18 ;
if ( ! V_16 -> V_19 || V_18 [ 0 ] -> V_59 != V_5 )
return 0 ;
if ( V_7 -> V_51 == 12 ) {
if ( ( V_4 + 1 ) < V_2 -> V_11 ) {
if ( V_16 -> V_19 == 2 ) {
F_10 ( V_18 [ 1 ] ) ;
V_16 -> V_19 = 1 ;
}
} else {
if ( V_16 -> V_19 != 2 )
return 0 ;
if ( V_18 [ 1 ] -> V_59 != ( V_5 + 1 ) )
return 0 ;
}
}
V_35 -> V_37 ( V_16 , V_4 ) ;
return 1 ;
}
int F_38 ( struct V_60 * V_60 , struct V_15 * V_16 , int V_3 )
{
struct V_1 * V_2 = V_60 -> V_61 ;
struct V_6 * V_7 = F_2 ( V_60 -> V_61 ) ;
struct V_34 * V_35 = V_7 -> V_36 ;
int V_29 , V_4 ;
T_1 V_5 ;
if ( V_3 < V_9 || V_7 -> V_10 <= V_3 ) {
F_39 ( V_16 ) ;
F_40 ( V_2 , L_2 , V_3 ) ;
return - V_33 ;
}
F_41 ( V_16 , V_3 ) ;
V_35 -> V_62 ( V_2 , V_3 , & V_4 , & V_5 ) ;
if ( ! F_37 ( V_2 , V_16 , V_4 , V_5 ) ) {
F_39 ( V_16 ) ;
V_29 = V_35 -> V_63 ( V_2 , V_16 , V_4 , V_5 ) ;
if ( V_29 )
return V_29 ;
}
return V_35 -> V_64 ( V_16 ) ;
}
static int F_42 ( struct V_1 * V_2 , struct V_17 * * V_18 ,
int V_19 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_17 * V_65 ;
int V_29 , V_66 , V_67 ;
V_29 = 0 ;
for ( V_67 = 1 ; V_67 < V_7 -> V_68 ; V_67 ++ ) {
T_1 V_69 = V_7 -> V_70 * V_67 ;
for ( V_66 = 0 ; V_66 < V_19 ; V_66 ++ ) {
V_65 = F_43 ( V_2 , V_69 + V_18 [ V_66 ] -> V_59 ) ;
if ( ! V_65 ) {
V_29 = - V_71 ;
goto error;
}
memcpy ( V_65 -> V_23 , V_18 [ V_66 ] -> V_23 , V_2 -> V_11 ) ;
F_44 ( V_65 ) ;
F_21 ( V_65 , V_7 -> V_28 ) ;
if ( V_2 -> V_55 & V_72 )
V_29 = F_45 ( V_65 ) ;
F_10 ( V_65 ) ;
if ( V_29 )
goto error;
}
}
error:
return V_29 ;
}
int F_46 ( struct V_60 * V_60 , struct V_15 * V_16 ,
int V_44 , int V_73 )
{
struct V_1 * V_2 = V_60 -> V_61 ;
struct V_34 * V_35 = F_2 ( V_2 ) -> V_36 ;
int V_29 ;
V_35 -> V_74 ( V_16 , V_44 ) ;
if ( V_73 ) {
V_29 = F_47 ( V_16 -> V_18 , V_16 -> V_19 ) ;
if ( V_29 )
return V_29 ;
}
return F_42 ( V_2 , V_16 -> V_18 , V_16 -> V_19 ) ;
}
static inline int F_48 ( struct V_6 * V_7 ,
struct V_15 * V_16 )
{
if ( V_7 -> V_36 -> V_75 ( V_16 ) ) {
if ( V_16 -> V_3 < V_7 -> V_10 )
return 1 ;
}
return 0 ;
}
static inline int F_49 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
struct V_34 * V_35 = F_2 ( V_2 ) -> V_36 ;
T_1 V_5 ;
int V_4 ;
F_39 ( V_16 ) ;
V_35 -> V_62 ( V_2 , V_16 -> V_3 , & V_4 , & V_5 ) ;
return V_35 -> V_63 ( V_2 , V_16 , V_4 , V_5 ) ;
}
static void F_50 ( struct V_17 * * V_18 , int * V_19 ,
struct V_15 * V_16 )
{
int V_66 , V_76 ;
for ( V_66 = 0 ; V_66 < V_16 -> V_19 ; V_66 ++ ) {
for ( V_76 = 0 ; V_76 < * V_19 ; V_76 ++ ) {
if ( V_16 -> V_18 [ V_66 ] == V_18 [ V_76 ] )
break;
}
if ( V_76 == * V_19 ) {
F_51 ( V_16 -> V_18 [ V_66 ] ) ;
V_18 [ V_76 ] = V_16 -> V_18 [ V_66 ] ;
( * V_19 ) ++ ;
}
}
}
int F_52 ( struct V_60 * V_60 , int * V_77 , int V_78 )
{
struct V_1 * V_2 = V_60 -> V_61 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_34 * V_35 = V_7 -> V_36 ;
struct V_15 V_16 , V_79 ;
struct V_17 * V_18 [ V_80 ] ;
int V_76 , V_81 , V_29 , V_19 , V_82 ;
F_53 ( V_78 > ( V_80 / 2 ) ) ;
F_29 ( V_7 ) ;
if ( V_7 -> V_83 != - 1 && V_7 -> V_84 &&
V_7 -> V_83 < V_78 ) {
F_31 ( V_7 ) ;
return - V_85 ;
}
V_29 = V_19 = V_82 = 0 ;
V_81 = V_9 ;
F_54 ( & V_79 ) ;
F_54 ( & V_16 ) ;
F_41 ( & V_16 , V_7 -> V_86 + 1 ) ;
while ( V_81 < V_7 -> V_10 ) {
if ( V_16 . V_3 >= V_7 -> V_10 )
V_16 . V_3 = V_9 ;
F_41 ( & V_16 , V_16 . V_3 ) ;
V_29 = F_49 ( V_2 , & V_16 ) ;
if ( V_29 )
goto V_87;
do {
if ( V_35 -> V_64 ( & V_16 ) == V_88 ) {
int V_3 = V_16 . V_3 ;
V_35 -> V_74 ( & V_16 , V_41 ) ;
if ( V_79 . V_19 )
V_35 -> V_74 ( & V_79 , V_3 ) ;
F_50 ( V_18 , & V_19 , & V_16 ) ;
V_7 -> V_86 = V_3 ;
if ( V_7 -> V_83 != - 1 )
V_7 -> V_83 -- ;
V_77 [ V_82 ] = V_3 ;
V_82 ++ ;
if ( V_82 == V_78 )
goto V_87;
V_79 = V_16 ;
}
V_81 ++ ;
if ( V_81 == V_7 -> V_10 )
break;
} while ( F_48 ( V_7 , & V_16 ) );
}
V_7 -> V_83 = 0 ;
V_7 -> V_84 = 1 ;
V_29 = - V_85 ;
V_87:
F_31 ( V_7 ) ;
F_35 ( V_2 ) ;
F_39 ( & V_16 ) ;
if ( ! V_29 ) {
if ( F_55 ( V_60 ) )
V_29 = F_47 ( V_18 , V_19 ) ;
if ( ! V_29 )
V_29 = F_42 ( V_2 , V_18 , V_19 ) ;
}
for ( V_76 = 0 ; V_76 < V_19 ; V_76 ++ )
F_10 ( V_18 [ V_76 ] ) ;
if ( V_29 && V_82 )
F_56 ( V_60 , V_77 [ 0 ] ) ;
return V_29 ;
}
int F_56 ( struct V_60 * V_60 , int V_77 )
{
struct V_1 * V_2 = V_60 -> V_61 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_34 * V_35 = V_7 -> V_36 ;
struct V_15 V_16 ;
struct V_17 * V_18 [ V_80 ] ;
int V_76 , V_29 , V_19 ;
int V_89 = V_77 , V_90 = 0 ;
V_19 = 0 ;
F_54 ( & V_16 ) ;
F_29 ( V_7 ) ;
do {
V_77 = F_38 ( V_60 , & V_16 , V_77 ) ;
if ( V_77 < 0 ) {
V_29 = V_77 ;
goto error;
} else if ( V_77 == V_88 ) {
F_40 ( V_2 , L_3 ,
V_91 ) ;
V_29 = - V_33 ;
goto error;
}
if ( V_7 -> V_92 . V_93 ) {
if ( V_77 != V_16 . V_3 + 1 ) {
int V_94 = V_16 . V_3 - V_89 + 1 ;
F_57 ( V_2 ,
F_58 ( V_7 , V_89 ) ,
V_94 * V_7 -> V_95 ,
V_96 , 0 ) ;
V_89 = V_77 ;
}
}
V_35 -> V_74 ( & V_16 , V_88 ) ;
if ( V_7 -> V_83 != - 1 ) {
V_7 -> V_83 ++ ;
V_90 = 1 ;
}
if ( V_19 + V_16 . V_19 > V_80 ) {
if ( V_2 -> V_55 & V_72 ) {
V_29 = F_47 ( V_18 , V_19 ) ;
if ( V_29 )
goto error;
}
V_29 = F_42 ( V_2 , V_18 , V_19 ) ;
if ( V_29 )
goto error;
for ( V_76 = 0 ; V_76 < V_19 ; V_76 ++ )
F_10 ( V_18 [ V_76 ] ) ;
V_19 = 0 ;
}
F_50 ( V_18 , & V_19 , & V_16 ) ;
} while ( V_77 != V_41 );
if ( V_2 -> V_55 & V_72 ) {
V_29 = F_47 ( V_18 , V_19 ) ;
if ( V_29 )
goto error;
}
V_29 = F_42 ( V_2 , V_18 , V_19 ) ;
error:
F_39 ( & V_16 ) ;
for ( V_76 = 0 ; V_76 < V_19 ; V_76 ++ )
F_10 ( V_18 [ V_76 ] ) ;
F_31 ( V_7 ) ;
if ( V_90 )
F_35 ( V_2 ) ;
return V_29 ;
}
static void F_59 ( struct V_1 * V_2 , struct V_15 * V_16 ,
unsigned long V_97 )
{
struct V_34 * V_35 = F_2 ( V_2 ) -> V_36 ;
T_1 V_5 ;
int V_76 , V_4 ;
V_35 -> V_62 ( V_2 , V_16 -> V_3 , & V_4 , & V_5 ) ;
for ( V_76 = 0 ; V_76 < V_97 ; V_76 ++ )
F_60 ( V_2 , V_5 + V_76 ) ;
}
int F_61 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_34 * V_35 = V_7 -> V_36 ;
struct V_15 V_16 ;
unsigned long V_97 , V_98 , V_99 ;
int V_29 = 0 , free ;
F_29 ( V_7 ) ;
if ( V_7 -> V_83 != - 1 && V_7 -> V_84 )
goto V_87;
V_97 = V_100 >> V_2 -> V_13 ;
V_98 = V_97 - 1 ;
V_99 = 0 ;
free = 0 ;
F_54 ( & V_16 ) ;
F_41 ( & V_16 , V_9 ) ;
while ( V_16 . V_3 < V_7 -> V_10 ) {
if ( ( V_99 & V_98 ) == 0 ) {
unsigned long V_101 = V_7 -> V_70 - V_99 ;
F_59 ( V_2 , & V_16 , F_62 ( V_97 , V_101 ) ) ;
}
V_99 ++ ;
V_29 = F_49 ( V_2 , & V_16 ) ;
if ( V_29 )
goto V_87;
do {
if ( V_35 -> V_64 ( & V_16 ) == V_88 )
free ++ ;
} while ( F_48 ( V_7 , & V_16 ) );
}
V_7 -> V_83 = free ;
V_7 -> V_84 = 1 ;
F_35 ( V_2 ) ;
F_39 ( & V_16 ) ;
V_87:
F_31 ( V_7 ) ;
return V_29 ;
}
