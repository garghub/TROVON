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
static inline int F_35 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
int V_4 , T_1 V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_34 * V_35 = V_7 -> V_36 ;
struct V_17 * * V_18 = V_16 -> V_18 ;
if ( ! V_16 -> V_19 || V_18 [ 0 ] -> V_55 != V_5 )
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
if ( V_18 [ 1 ] -> V_55 != ( V_5 + 1 ) )
return 0 ;
}
}
V_35 -> V_37 ( V_16 , V_4 ) ;
return 1 ;
}
int F_36 ( struct V_56 * V_56 , struct V_15 * V_16 , int V_3 )
{
struct V_1 * V_2 = V_56 -> V_57 ;
struct V_6 * V_7 = F_2 ( V_56 -> V_57 ) ;
struct V_34 * V_35 = V_7 -> V_36 ;
int V_29 , V_4 ;
T_1 V_5 ;
if ( V_3 < V_9 || V_7 -> V_10 <= V_3 ) {
F_37 ( V_16 ) ;
F_38 ( V_2 , L_2 , V_3 ) ;
return - V_33 ;
}
F_39 ( V_16 , V_3 ) ;
V_35 -> V_58 ( V_2 , V_3 , & V_4 , & V_5 ) ;
if ( ! F_35 ( V_2 , V_16 , V_4 , V_5 ) ) {
F_37 ( V_16 ) ;
V_29 = V_35 -> V_59 ( V_2 , V_16 , V_4 , V_5 ) ;
if ( V_29 )
return V_29 ;
}
return V_35 -> V_60 ( V_16 ) ;
}
static int F_40 ( struct V_1 * V_2 , struct V_17 * * V_18 ,
int V_19 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_17 * V_61 ;
int V_29 , V_62 , V_63 ;
V_29 = 0 ;
for ( V_63 = 1 ; V_63 < V_7 -> V_64 ; V_63 ++ ) {
T_1 V_65 = V_7 -> V_66 * V_63 ;
for ( V_62 = 0 ; V_62 < V_19 ; V_62 ++ ) {
V_61 = F_41 ( V_2 , V_65 + V_18 [ V_62 ] -> V_55 ) ;
if ( ! V_61 ) {
V_29 = - V_67 ;
goto error;
}
memcpy ( V_61 -> V_23 , V_18 [ V_62 ] -> V_23 , V_2 -> V_11 ) ;
F_42 ( V_61 ) ;
F_21 ( V_61 , V_7 -> V_28 ) ;
if ( V_2 -> V_68 & V_69 )
V_29 = F_43 ( V_61 ) ;
F_10 ( V_61 ) ;
if ( V_29 )
goto error;
}
}
error:
return V_29 ;
}
int F_44 ( struct V_56 * V_56 , struct V_15 * V_16 ,
int V_44 , int V_70 )
{
struct V_1 * V_2 = V_56 -> V_57 ;
struct V_34 * V_35 = F_2 ( V_2 ) -> V_36 ;
int V_29 ;
V_35 -> V_71 ( V_16 , V_44 ) ;
if ( V_70 ) {
V_29 = F_45 ( V_16 -> V_18 , V_16 -> V_19 ) ;
if ( V_29 )
return V_29 ;
}
return F_40 ( V_2 , V_16 -> V_18 , V_16 -> V_19 ) ;
}
static inline int F_46 ( struct V_6 * V_7 ,
struct V_15 * V_16 )
{
if ( V_7 -> V_36 -> V_72 ( V_16 ) ) {
if ( V_16 -> V_3 < V_7 -> V_10 )
return 1 ;
}
return 0 ;
}
static inline int F_47 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
struct V_34 * V_35 = F_2 ( V_2 ) -> V_36 ;
T_1 V_5 ;
int V_4 ;
F_37 ( V_16 ) ;
V_35 -> V_58 ( V_2 , V_16 -> V_3 , & V_4 , & V_5 ) ;
return V_35 -> V_59 ( V_2 , V_16 , V_4 , V_5 ) ;
}
static void F_48 ( struct V_17 * * V_18 , int * V_19 ,
struct V_15 * V_16 )
{
int V_62 , V_73 ;
for ( V_62 = 0 ; V_62 < V_16 -> V_19 ; V_62 ++ ) {
for ( V_73 = 0 ; V_73 < * V_19 ; V_73 ++ ) {
if ( V_16 -> V_18 [ V_62 ] == V_18 [ V_73 ] )
break;
}
if ( V_73 == * V_19 ) {
F_49 ( V_16 -> V_18 [ V_62 ] ) ;
V_18 [ V_73 ] = V_16 -> V_18 [ V_62 ] ;
( * V_19 ) ++ ;
}
}
}
int F_50 ( struct V_56 * V_56 , int * V_74 , int V_75 )
{
struct V_1 * V_2 = V_56 -> V_57 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_34 * V_35 = V_7 -> V_36 ;
struct V_15 V_16 , V_76 ;
struct V_17 * V_18 [ V_77 ] ;
int V_73 , V_78 , V_29 , V_19 , V_79 ;
F_51 ( V_75 > ( V_77 / 2 ) ) ;
F_29 ( V_7 ) ;
if ( V_7 -> V_80 != - 1 && V_7 -> V_81 &&
V_7 -> V_80 < V_75 ) {
F_31 ( V_7 ) ;
return - V_82 ;
}
V_29 = V_19 = V_79 = 0 ;
V_78 = V_9 ;
F_52 ( & V_76 ) ;
F_52 ( & V_16 ) ;
F_39 ( & V_16 , V_7 -> V_83 + 1 ) ;
while ( V_78 < V_7 -> V_10 ) {
if ( V_16 . V_3 >= V_7 -> V_10 )
V_16 . V_3 = V_9 ;
F_39 ( & V_16 , V_16 . V_3 ) ;
V_29 = F_47 ( V_2 , & V_16 ) ;
if ( V_29 )
goto V_84;
do {
if ( V_35 -> V_60 ( & V_16 ) == V_85 ) {
int V_3 = V_16 . V_3 ;
V_35 -> V_71 ( & V_16 , V_41 ) ;
if ( V_76 . V_19 )
V_35 -> V_71 ( & V_76 , V_3 ) ;
F_48 ( V_18 , & V_19 , & V_16 ) ;
V_7 -> V_83 = V_3 ;
if ( V_7 -> V_80 != - 1 )
V_7 -> V_80 -- ;
V_2 -> V_86 = 1 ;
V_74 [ V_79 ] = V_3 ;
V_79 ++ ;
if ( V_79 == V_75 )
goto V_84;
V_76 = V_16 ;
}
V_78 ++ ;
if ( V_78 == V_7 -> V_10 )
break;
} while ( F_46 ( V_7 , & V_16 ) );
}
V_7 -> V_80 = 0 ;
V_7 -> V_81 = 1 ;
V_2 -> V_86 = 1 ;
V_29 = - V_82 ;
V_84:
F_31 ( V_7 ) ;
F_37 ( & V_16 ) ;
if ( ! V_29 ) {
if ( F_53 ( V_56 ) )
V_29 = F_45 ( V_18 , V_19 ) ;
if ( ! V_29 )
V_29 = F_40 ( V_2 , V_18 , V_19 ) ;
}
for ( V_73 = 0 ; V_73 < V_19 ; V_73 ++ )
F_10 ( V_18 [ V_73 ] ) ;
if ( V_29 && V_79 )
F_54 ( V_56 , V_74 [ 0 ] ) ;
return V_29 ;
}
int F_54 ( struct V_56 * V_56 , int V_74 )
{
struct V_1 * V_2 = V_56 -> V_57 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_34 * V_35 = V_7 -> V_36 ;
struct V_15 V_16 ;
struct V_17 * V_18 [ V_77 ] ;
int V_73 , V_29 , V_19 ;
int V_87 = V_74 ;
V_19 = 0 ;
F_52 ( & V_16 ) ;
F_29 ( V_7 ) ;
do {
V_74 = F_36 ( V_56 , & V_16 , V_74 ) ;
if ( V_74 < 0 ) {
V_29 = V_74 ;
goto error;
} else if ( V_74 == V_85 ) {
F_38 ( V_2 , L_3 ,
V_88 ) ;
V_29 = - V_33 ;
goto error;
}
if ( V_7 -> V_89 . V_90 ) {
if ( V_74 != V_16 . V_3 + 1 ) {
int V_91 = V_16 . V_3 - V_87 + 1 ;
F_55 ( V_2 ,
F_56 ( V_7 , V_87 ) ,
V_91 * V_7 -> V_92 ,
V_93 , 0 ) ;
V_87 = V_74 ;
}
}
V_35 -> V_71 ( & V_16 , V_85 ) ;
if ( V_7 -> V_80 != - 1 ) {
V_7 -> V_80 ++ ;
V_2 -> V_86 = 1 ;
}
if ( V_19 + V_16 . V_19 > V_77 ) {
if ( V_2 -> V_68 & V_69 ) {
V_29 = F_45 ( V_18 , V_19 ) ;
if ( V_29 )
goto error;
}
V_29 = F_40 ( V_2 , V_18 , V_19 ) ;
if ( V_29 )
goto error;
for ( V_73 = 0 ; V_73 < V_19 ; V_73 ++ )
F_10 ( V_18 [ V_73 ] ) ;
V_19 = 0 ;
}
F_48 ( V_18 , & V_19 , & V_16 ) ;
} while ( V_74 != V_41 );
if ( V_2 -> V_68 & V_69 ) {
V_29 = F_45 ( V_18 , V_19 ) ;
if ( V_29 )
goto error;
}
V_29 = F_40 ( V_2 , V_18 , V_19 ) ;
error:
F_37 ( & V_16 ) ;
for ( V_73 = 0 ; V_73 < V_19 ; V_73 ++ )
F_10 ( V_18 [ V_73 ] ) ;
F_31 ( V_7 ) ;
return V_29 ;
}
static void F_57 ( struct V_1 * V_2 , struct V_15 * V_16 ,
unsigned long V_94 )
{
struct V_34 * V_35 = F_2 ( V_2 ) -> V_36 ;
T_1 V_5 ;
int V_73 , V_4 ;
V_35 -> V_58 ( V_2 , V_16 -> V_3 , & V_4 , & V_5 ) ;
for ( V_73 = 0 ; V_73 < V_94 ; V_73 ++ )
F_58 ( V_2 , V_5 + V_73 ) ;
}
int F_59 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_34 * V_35 = V_7 -> V_36 ;
struct V_15 V_16 ;
unsigned long V_94 , V_95 , V_96 ;
int V_29 = 0 , free ;
F_29 ( V_7 ) ;
if ( V_7 -> V_80 != - 1 && V_7 -> V_81 )
goto V_84;
V_94 = V_97 >> V_2 -> V_13 ;
V_95 = V_94 - 1 ;
V_96 = 0 ;
free = 0 ;
F_52 ( & V_16 ) ;
F_39 ( & V_16 , V_9 ) ;
while ( V_16 . V_3 < V_7 -> V_10 ) {
if ( ( V_96 & V_95 ) == 0 ) {
unsigned long V_98 = V_7 -> V_66 - V_96 ;
F_57 ( V_2 , & V_16 , F_60 ( V_94 , V_98 ) ) ;
}
V_96 ++ ;
V_29 = F_47 ( V_2 , & V_16 ) ;
if ( V_29 )
goto V_84;
do {
if ( V_35 -> V_60 ( & V_16 ) == V_85 )
free ++ ;
} while ( F_46 ( V_7 , & V_16 ) );
}
V_7 -> V_80 = free ;
V_7 -> V_81 = 1 ;
V_2 -> V_86 = 1 ;
F_37 ( & V_16 ) ;
V_84:
F_31 ( V_7 ) ;
return V_29 ;
}
