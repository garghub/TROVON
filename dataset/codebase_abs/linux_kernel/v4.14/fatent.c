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
const struct V_34 * V_35 = F_2 ( V_2 ) -> V_36 ;
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
F_3 ( V_44 & 0xf0000000 ) ;
V_44 |= F_19 ( * V_16 -> V_21 . V_26 ) & ~ 0x0fffffff ;
* V_16 -> V_21 . V_26 = F_25 ( V_44 ) ;
F_21 ( V_16 -> V_18 [ 0 ] , V_16 -> V_28 ) ;
}
static int F_26 ( struct V_15 * V_16 )
{
T_2 * * V_22 = V_16 -> V_21 . V_22 ;
struct V_17 * * V_18 = V_16 -> V_18 ;
T_2 * V_47 = V_22 [ 1 ] + 1 + ( V_16 -> V_3 & 1 ) ;
V_16 -> V_3 ++ ;
if ( V_16 -> V_19 == 1 ) {
F_3 ( V_22 [ 0 ] > ( T_2 * ) ( V_18 [ 0 ] -> V_23 +
( V_18 [ 0 ] -> V_20 - 2 ) ) ) ;
F_3 ( V_22 [ 1 ] > ( T_2 * ) ( V_18 [ 0 ] -> V_23 +
( V_18 [ 0 ] -> V_20 - 1 ) ) ) ;
if ( V_47 < ( T_2 * ) ( V_18 [ 0 ] -> V_23 + ( V_18 [ 0 ] -> V_20 - 1 ) ) ) {
V_22 [ 0 ] = V_47 - 1 ;
V_22 [ 1 ] = V_47 ;
return 1 ;
}
} else {
F_3 ( V_22 [ 0 ] != ( T_2 * ) ( V_18 [ 0 ] -> V_23 +
( V_18 [ 0 ] -> V_20 - 1 ) ) ) ;
F_3 ( V_22 [ 1 ] != ( T_2 * ) V_18 [ 1 ] -> V_23 ) ;
V_22 [ 0 ] = V_47 - 1 ;
V_22 [ 1 ] = V_47 ;
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
const struct V_17 * V_48 = V_16 -> V_18 [ 0 ] ;
V_16 -> V_3 ++ ;
if ( V_16 -> V_21 . V_24 < ( V_25 * ) ( V_48 -> V_23 + ( V_48 -> V_20 - 2 ) ) ) {
V_16 -> V_21 . V_24 ++ ;
return 1 ;
}
V_16 -> V_21 . V_24 = NULL ;
return 0 ;
}
static int F_28 ( struct V_15 * V_16 )
{
const struct V_17 * V_48 = V_16 -> V_18 [ 0 ] ;
V_16 -> V_3 ++ ;
if ( V_16 -> V_21 . V_26 < ( V_27 * ) ( V_48 -> V_23 + ( V_48 -> V_20 - 4 ) ) ) {
V_16 -> V_21 . V_26 ++ ;
return 1 ;
}
V_16 -> V_21 . V_26 = NULL ;
return 0 ;
}
static inline void F_29 ( struct V_6 * V_7 )
{
F_30 ( & V_7 -> V_49 ) ;
}
static inline void F_31 ( struct V_6 * V_7 )
{
F_32 ( & V_7 -> V_49 ) ;
}
void F_33 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_34 ( & V_7 -> V_49 ) ;
switch ( V_7 -> V_50 ) {
case 32 :
V_7 -> V_14 = 2 ;
V_7 -> V_36 = & V_51 ;
break;
case 16 :
V_7 -> V_14 = 1 ;
V_7 -> V_36 = & V_52 ;
break;
case 12 :
V_7 -> V_14 = - 1 ;
V_7 -> V_36 = & V_53 ;
break;
}
}
static void F_35 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( F_36 ( V_2 ) || V_7 -> V_50 != 32 )
return;
F_37 ( V_7 -> V_54 , V_55 ) ;
}
static inline int F_38 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
int V_4 , T_1 V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
const struct V_34 * V_35 = V_7 -> V_36 ;
struct V_17 * * V_18 = V_16 -> V_18 ;
if ( ! V_16 -> V_19 || V_18 [ 0 ] -> V_56 != V_5 )
return 0 ;
if ( V_7 -> V_50 == 12 ) {
if ( ( V_4 + 1 ) < V_2 -> V_11 ) {
if ( V_16 -> V_19 == 2 ) {
F_10 ( V_18 [ 1 ] ) ;
V_16 -> V_19 = 1 ;
}
} else {
if ( V_16 -> V_19 != 2 )
return 0 ;
if ( V_18 [ 1 ] -> V_56 != ( V_5 + 1 ) )
return 0 ;
}
}
V_35 -> V_37 ( V_16 , V_4 ) ;
return 1 ;
}
int F_39 ( struct V_57 * V_57 , struct V_15 * V_16 , int V_3 )
{
struct V_1 * V_2 = V_57 -> V_58 ;
struct V_6 * V_7 = F_2 ( V_57 -> V_58 ) ;
const struct V_34 * V_35 = V_7 -> V_36 ;
int V_29 , V_4 ;
T_1 V_5 ;
if ( V_3 < V_9 || V_7 -> V_10 <= V_3 ) {
F_40 ( V_16 ) ;
F_41 ( V_2 , L_2 , V_3 ) ;
return - V_33 ;
}
F_42 ( V_16 , V_3 ) ;
V_35 -> V_59 ( V_2 , V_3 , & V_4 , & V_5 ) ;
if ( ! F_38 ( V_2 , V_16 , V_4 , V_5 ) ) {
F_40 ( V_16 ) ;
V_29 = V_35 -> V_60 ( V_2 , V_16 , V_4 , V_5 ) ;
if ( V_29 )
return V_29 ;
}
return V_35 -> V_61 ( V_16 ) ;
}
static int F_43 ( struct V_1 * V_2 , struct V_17 * * V_18 ,
int V_19 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_17 * V_62 ;
int V_29 , V_63 , V_64 ;
V_29 = 0 ;
for ( V_64 = 1 ; V_64 < V_7 -> V_65 ; V_64 ++ ) {
T_1 V_66 = V_7 -> V_67 * V_64 ;
for ( V_63 = 0 ; V_63 < V_19 ; V_63 ++ ) {
V_62 = F_44 ( V_2 , V_66 + V_18 [ V_63 ] -> V_56 ) ;
if ( ! V_62 ) {
V_29 = - V_68 ;
goto error;
}
memcpy ( V_62 -> V_23 , V_18 [ V_63 ] -> V_23 , V_2 -> V_11 ) ;
F_45 ( V_62 ) ;
F_21 ( V_62 , V_7 -> V_28 ) ;
if ( V_2 -> V_69 & V_70 )
V_29 = F_46 ( V_62 ) ;
F_10 ( V_62 ) ;
if ( V_29 )
goto error;
}
}
error:
return V_29 ;
}
int F_47 ( struct V_57 * V_57 , struct V_15 * V_16 ,
int V_44 , int V_71 )
{
struct V_1 * V_2 = V_57 -> V_58 ;
const struct V_34 * V_35 = F_2 ( V_2 ) -> V_36 ;
int V_29 ;
V_35 -> V_72 ( V_16 , V_44 ) ;
if ( V_71 ) {
V_29 = F_48 ( V_16 -> V_18 , V_16 -> V_19 ) ;
if ( V_29 )
return V_29 ;
}
return F_43 ( V_2 , V_16 -> V_18 , V_16 -> V_19 ) ;
}
static inline int F_49 ( struct V_6 * V_7 ,
struct V_15 * V_16 )
{
if ( V_7 -> V_36 -> V_73 ( V_16 ) ) {
if ( V_16 -> V_3 < V_7 -> V_10 )
return 1 ;
}
return 0 ;
}
static inline int F_50 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
const struct V_34 * V_35 = F_2 ( V_2 ) -> V_36 ;
T_1 V_5 ;
int V_4 ;
F_40 ( V_16 ) ;
V_35 -> V_59 ( V_2 , V_16 -> V_3 , & V_4 , & V_5 ) ;
return V_35 -> V_60 ( V_2 , V_16 , V_4 , V_5 ) ;
}
static void F_51 ( struct V_17 * * V_18 , int * V_19 ,
struct V_15 * V_16 )
{
int V_63 , V_74 ;
for ( V_63 = 0 ; V_63 < V_16 -> V_19 ; V_63 ++ ) {
for ( V_74 = 0 ; V_74 < * V_19 ; V_74 ++ ) {
if ( V_16 -> V_18 [ V_63 ] == V_18 [ V_74 ] )
break;
}
if ( V_74 == * V_19 ) {
F_52 ( V_16 -> V_18 [ V_63 ] ) ;
V_18 [ V_74 ] = V_16 -> V_18 [ V_63 ] ;
( * V_19 ) ++ ;
}
}
}
int F_53 ( struct V_57 * V_57 , int * V_75 , int V_76 )
{
struct V_1 * V_2 = V_57 -> V_58 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
const struct V_34 * V_35 = V_7 -> V_36 ;
struct V_15 V_16 , V_77 ;
struct V_17 * V_18 [ V_78 ] ;
int V_74 , V_79 , V_29 , V_19 , V_80 ;
F_54 ( V_76 > ( V_78 / 2 ) ) ;
F_29 ( V_7 ) ;
if ( V_7 -> V_81 != - 1 && V_7 -> V_82 &&
V_7 -> V_81 < V_76 ) {
F_31 ( V_7 ) ;
return - V_83 ;
}
V_29 = V_19 = V_80 = 0 ;
V_79 = V_9 ;
F_55 ( & V_77 ) ;
F_55 ( & V_16 ) ;
F_42 ( & V_16 , V_7 -> V_84 + 1 ) ;
while ( V_79 < V_7 -> V_10 ) {
if ( V_16 . V_3 >= V_7 -> V_10 )
V_16 . V_3 = V_9 ;
F_42 ( & V_16 , V_16 . V_3 ) ;
V_29 = F_50 ( V_2 , & V_16 ) ;
if ( V_29 )
goto V_85;
do {
if ( V_35 -> V_61 ( & V_16 ) == V_86 ) {
int V_3 = V_16 . V_3 ;
V_35 -> V_72 ( & V_16 , V_41 ) ;
if ( V_77 . V_19 )
V_35 -> V_72 ( & V_77 , V_3 ) ;
F_51 ( V_18 , & V_19 , & V_16 ) ;
V_7 -> V_84 = V_3 ;
if ( V_7 -> V_81 != - 1 )
V_7 -> V_81 -- ;
V_75 [ V_80 ] = V_3 ;
V_80 ++ ;
if ( V_80 == V_76 )
goto V_85;
V_77 = V_16 ;
}
V_79 ++ ;
if ( V_79 == V_7 -> V_10 )
break;
} while ( F_49 ( V_7 , & V_16 ) );
}
V_7 -> V_81 = 0 ;
V_7 -> V_82 = 1 ;
V_29 = - V_83 ;
V_85:
F_31 ( V_7 ) ;
F_35 ( V_2 ) ;
F_40 ( & V_16 ) ;
if ( ! V_29 ) {
if ( F_56 ( V_57 ) )
V_29 = F_48 ( V_18 , V_19 ) ;
if ( ! V_29 )
V_29 = F_43 ( V_2 , V_18 , V_19 ) ;
}
for ( V_74 = 0 ; V_74 < V_19 ; V_74 ++ )
F_10 ( V_18 [ V_74 ] ) ;
if ( V_29 && V_80 )
F_57 ( V_57 , V_75 [ 0 ] ) ;
return V_29 ;
}
int F_57 ( struct V_57 * V_57 , int V_75 )
{
struct V_1 * V_2 = V_57 -> V_58 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
const struct V_34 * V_35 = V_7 -> V_36 ;
struct V_15 V_16 ;
struct V_17 * V_18 [ V_78 ] ;
int V_74 , V_29 , V_19 ;
int V_87 = V_75 , V_88 = 0 ;
V_19 = 0 ;
F_55 ( & V_16 ) ;
F_29 ( V_7 ) ;
do {
V_75 = F_39 ( V_57 , & V_16 , V_75 ) ;
if ( V_75 < 0 ) {
V_29 = V_75 ;
goto error;
} else if ( V_75 == V_86 ) {
F_41 ( V_2 , L_3 ,
V_89 ) ;
V_29 = - V_33 ;
goto error;
}
if ( V_7 -> V_90 . V_91 ) {
if ( V_75 != V_16 . V_3 + 1 ) {
int V_92 = V_16 . V_3 - V_87 + 1 ;
F_58 ( V_2 ,
F_59 ( V_7 , V_87 ) ,
V_92 * V_7 -> V_93 ,
V_94 , 0 ) ;
V_87 = V_75 ;
}
}
V_35 -> V_72 ( & V_16 , V_86 ) ;
if ( V_7 -> V_81 != - 1 ) {
V_7 -> V_81 ++ ;
V_88 = 1 ;
}
if ( V_19 + V_16 . V_19 > V_78 ) {
if ( V_2 -> V_69 & V_70 ) {
V_29 = F_48 ( V_18 , V_19 ) ;
if ( V_29 )
goto error;
}
V_29 = F_43 ( V_2 , V_18 , V_19 ) ;
if ( V_29 )
goto error;
for ( V_74 = 0 ; V_74 < V_19 ; V_74 ++ )
F_10 ( V_18 [ V_74 ] ) ;
V_19 = 0 ;
}
F_51 ( V_18 , & V_19 , & V_16 ) ;
} while ( V_75 != V_41 );
if ( V_2 -> V_69 & V_70 ) {
V_29 = F_48 ( V_18 , V_19 ) ;
if ( V_29 )
goto error;
}
V_29 = F_43 ( V_2 , V_18 , V_19 ) ;
error:
F_40 ( & V_16 ) ;
for ( V_74 = 0 ; V_74 < V_19 ; V_74 ++ )
F_10 ( V_18 [ V_74 ] ) ;
F_31 ( V_7 ) ;
if ( V_88 )
F_35 ( V_2 ) ;
return V_29 ;
}
static void F_60 ( struct V_1 * V_2 , struct V_15 * V_16 ,
unsigned long V_95 )
{
const struct V_34 * V_35 = F_2 ( V_2 ) -> V_36 ;
T_1 V_5 ;
int V_74 , V_4 ;
V_35 -> V_59 ( V_2 , V_16 -> V_3 , & V_4 , & V_5 ) ;
for ( V_74 = 0 ; V_74 < V_95 ; V_74 ++ )
F_61 ( V_2 , V_5 + V_74 ) ;
}
int F_62 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
const struct V_34 * V_35 = V_7 -> V_36 ;
struct V_15 V_16 ;
unsigned long V_95 , V_96 , V_97 ;
int V_29 = 0 , free ;
F_29 ( V_7 ) ;
if ( V_7 -> V_81 != - 1 && V_7 -> V_82 )
goto V_85;
V_95 = V_98 >> V_2 -> V_13 ;
V_96 = V_95 - 1 ;
V_97 = 0 ;
free = 0 ;
F_55 ( & V_16 ) ;
F_42 ( & V_16 , V_9 ) ;
while ( V_16 . V_3 < V_7 -> V_10 ) {
if ( ( V_97 & V_96 ) == 0 ) {
unsigned long V_99 = V_7 -> V_67 - V_97 ;
F_60 ( V_2 , & V_16 , F_63 ( V_95 , V_99 ) ) ;
}
V_97 ++ ;
V_29 = F_50 ( V_2 , & V_16 ) ;
if ( V_29 )
goto V_85;
do {
if ( V_35 -> V_61 ( & V_16 ) == V_86 )
free ++ ;
} while ( F_49 ( V_7 , & V_16 ) );
}
V_7 -> V_81 = free ;
V_7 -> V_82 = 1 ;
F_35 ( V_2 ) ;
F_40 ( & V_16 ) ;
V_85:
F_31 ( V_7 ) ;
return V_29 ;
}
