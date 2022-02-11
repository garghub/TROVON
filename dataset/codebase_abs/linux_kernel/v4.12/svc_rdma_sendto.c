static T_1 F_1 ( T_1 V_1 )
{
return ( V_1 & 3 ) ? ( 4 - ( V_1 & 3 ) ) : 0 ;
}
static unsigned int F_2 ( T_2 * V_2 )
{
unsigned int V_3 ;
T_2 * V_4 ;
V_4 = V_2 ;
V_4 += V_5 + 1 ;
while ( * V_4 ++ != V_6 ) {
V_3 = F_3 ( V_4 ++ ) ;
V_4 += V_3 * V_7 ;
}
if ( * V_4 ++ != V_6 ) {
V_3 = F_3 ( V_4 ++ ) ;
V_4 += V_3 * V_7 ;
}
return ( unsigned long ) V_4 - ( unsigned long ) V_2 ;
}
static unsigned int F_4 ( T_2 * V_8 , T_2 * V_9 ,
unsigned int V_10 )
{
unsigned int V_11 , V_3 ;
T_1 V_12 ;
* V_8 ++ = * V_9 ++ ;
V_3 = F_3 ( V_9 ) ;
* V_8 ++ = * V_9 ++ ;
for ( V_11 = V_3 ; V_11 ; V_11 -- ) {
* V_8 ++ = * V_9 ++ ;
V_12 = F_5 ( * V_9 ) ;
if ( V_10 >= V_12 ) {
* V_8 = * V_9 ;
V_10 -= V_12 ;
} else {
* V_8 = F_6 ( V_10 ) ;
V_10 = 0 ;
}
V_8 ++ ; V_9 ++ ;
* V_8 ++ = * V_9 ++ ;
* V_8 ++ = * V_9 ++ ;
}
return V_3 ;
}
static void F_7 ( T_2 * V_2 , T_2 * V_13 ,
unsigned int V_14 )
{
unsigned int V_3 ;
T_2 * V_4 , * V_15 ;
V_4 = V_2 + V_5 + 1 ;
V_15 = V_13 ;
while ( * V_15 != V_6 ) {
V_3 = F_4 ( V_4 , V_15 , V_14 ) ;
V_15 += 2 + V_3 * V_7 ;
V_4 += 2 + V_3 * V_7 ;
V_14 = 0 ;
}
* V_4 ++ = V_6 ;
* V_4 = V_6 ;
}
static void F_8 ( T_2 * V_2 , T_2 * V_16 ,
unsigned int V_14 )
{
T_2 * V_4 ;
V_4 = V_2 + V_5 + 1 ;
while ( * V_4 ++ != V_6 )
V_4 += 1 + F_3 ( V_4 ) * V_7 ;
F_4 ( V_4 , V_16 , V_14 ) ;
}
static void F_9 ( T_2 * V_17 ,
T_2 * * V_18 , T_2 * * V_19 )
{
T_2 * V_4 ;
V_4 = V_17 + V_5 ;
while ( * V_4 ++ != V_6 )
V_4 += 5 ;
if ( * V_4 != V_6 ) {
* V_18 = V_4 ;
while ( * V_4 ++ != V_6 )
V_4 += 1 + F_5 ( * V_4 ) * 4 ;
} else {
* V_18 = NULL ;
V_4 ++ ;
}
if ( * V_4 != V_6 )
* V_19 = V_4 ;
else
* V_19 = NULL ;
}
static T_1 F_10 ( T_2 * V_17 ,
T_2 * V_20 , T_2 * V_16 )
{
T_2 * V_4 ;
V_4 = V_17 + V_5 ;
if ( * V_4 != V_6 )
V_4 += 2 ;
else if ( V_20 && F_3 ( V_20 + 1 ) )
V_4 = V_20 + 2 ;
else if ( V_16 && F_3 ( V_16 + 1 ) )
V_4 = V_16 + 2 ;
else
return 0 ;
return F_3 ( V_4 ) ;
}
static int F_11 ( struct V_21 * V_22 ,
struct V_23 * V_24 ,
unsigned int V_25 ,
unsigned char * V_26 ,
unsigned int V_1 )
{
unsigned long V_27 = ( unsigned long ) V_26 & ~ V_28 ;
struct V_29 * V_30 = V_22 -> V_31 -> V_32 ;
T_3 V_33 ;
V_33 = F_12 ( V_30 , F_13 ( V_26 ) ,
V_27 , V_1 , V_34 ) ;
if ( F_14 ( V_30 , V_33 ) )
return - V_35 ;
V_24 -> V_36 [ V_25 ] . V_37 = V_33 ;
V_24 -> V_36 [ V_25 ] . V_38 = V_1 ;
V_24 -> V_36 [ V_25 ] . V_39 = V_22 -> V_40 -> V_41 ;
F_15 ( V_22 , V_24 ) ;
return 0 ;
}
static int F_16 ( struct V_21 * V_22 ,
struct V_23 * V_24 ,
unsigned int V_25 ,
struct V_42 * V_42 ,
unsigned int V_27 ,
unsigned int V_1 )
{
struct V_29 * V_30 = V_22 -> V_31 -> V_32 ;
T_3 V_33 ;
V_33 = F_12 ( V_30 , V_42 , V_27 , V_1 , V_34 ) ;
if ( F_14 ( V_30 , V_33 ) )
return - V_35 ;
V_24 -> V_36 [ V_25 ] . V_37 = V_33 ;
V_24 -> V_36 [ V_25 ] . V_38 = V_1 ;
V_24 -> V_36 [ V_25 ] . V_39 = V_22 -> V_40 -> V_41 ;
F_15 ( V_22 , V_24 ) ;
return 0 ;
}
int F_17 ( struct V_21 * V_22 ,
struct V_23 * V_24 ,
T_2 * V_2 ,
unsigned int V_1 )
{
V_24 -> V_43 = V_34 ;
V_24 -> V_44 [ 0 ] = F_13 ( V_2 ) ;
V_24 -> V_45 = 1 ;
return F_16 ( V_22 , V_24 , 0 , V_24 -> V_44 [ 0 ] , 0 , V_1 ) ;
}
static int F_18 ( struct V_21 * V_22 ,
struct V_23 * V_24 ,
struct V_46 * V_47 , T_2 * V_20 )
{
unsigned int V_1 , V_25 , V_10 , V_48 ;
struct V_42 * * V_49 ;
unsigned char * V_26 ;
T_1 V_50 ;
int V_51 ;
V_25 = 1 ;
V_51 = F_11 ( V_22 , V_24 , V_25 ++ ,
V_47 -> V_52 [ 0 ] . V_53 ,
V_47 -> V_52 [ 0 ] . V_54 ) ;
if ( V_51 < 0 )
return V_51 ;
if ( V_20 ) {
V_26 = V_47 -> V_55 [ 0 ] . V_53 ;
V_1 = V_47 -> V_55 [ 0 ] . V_54 ;
V_50 = F_1 ( V_47 -> V_56 ) ;
if ( V_1 && V_50 ) {
V_26 += V_50 ;
V_1 -= V_50 ;
}
goto V_55;
}
V_49 = V_47 -> V_44 + ( V_47 -> V_57 >> V_58 ) ;
V_48 = V_47 -> V_57 & ~ V_28 ;
V_10 = V_47 -> V_56 ;
while ( V_10 ) {
V_1 = F_19 ( T_1 , V_59 - V_48 , V_10 ) ;
V_51 = F_16 ( V_22 , V_24 , V_25 ++ ,
* V_49 ++ , V_48 , V_1 ) ;
if ( V_51 < 0 )
return V_51 ;
V_10 -= V_1 ;
V_48 = 0 ;
}
V_26 = V_47 -> V_55 [ 0 ] . V_53 ;
V_1 = V_47 -> V_55 [ 0 ] . V_54 ;
V_55:
if ( V_1 ) {
V_51 = F_11 ( V_22 , V_24 , V_25 ++ , V_26 , V_1 ) ;
if ( V_51 < 0 )
return V_51 ;
}
return V_25 - 1 ;
}
static void F_20 ( struct V_60 * V_61 ,
struct V_23 * V_24 )
{
int V_11 , V_44 = V_61 -> V_62 - V_61 -> V_63 ;
V_24 -> V_45 += V_44 ;
for ( V_11 = 0 ; V_11 < V_44 ; V_11 ++ ) {
V_24 -> V_44 [ V_11 + 1 ] = V_61 -> V_63 [ V_11 ] ;
V_61 -> V_63 [ V_11 ] = NULL ;
}
V_61 -> V_62 = V_61 -> V_63 + 1 ;
}
int F_21 ( struct V_21 * V_22 ,
struct V_23 * V_24 , int V_64 ,
T_1 V_65 )
{
struct V_66 * V_67 = & V_24 -> V_67 ;
F_22 ( L_1 , V_64 ) ;
V_67 -> V_68 = NULL ;
V_24 -> V_69 . V_70 = V_71 ;
V_67 -> V_72 = & V_24 -> V_69 ;
V_67 -> V_73 = V_24 -> V_36 ;
V_67 -> V_64 = V_64 ;
V_67 -> V_74 = V_75 ;
if ( V_65 ) {
V_67 -> V_76 = V_77 ;
V_67 -> V_78 . V_79 = V_65 ;
} else {
V_67 -> V_76 = V_80 ;
}
return F_23 ( V_22 , V_67 ) ;
}
static int F_24 ( struct V_21 * V_22 ,
T_2 * V_17 , T_2 * V_2 ,
struct V_60 * V_61 ,
T_2 * V_20 , T_2 * V_16 )
{
struct V_23 * V_24 ;
T_1 V_65 ;
int V_51 ;
F_22 ( L_2 ,
( V_16 ? L_3 : L_4 ) ,
V_61 -> V_81 . V_52 [ 0 ] . V_54 ,
V_61 -> V_81 . V_56 ,
V_61 -> V_81 . V_55 [ 0 ] . V_54 ) ;
V_24 = F_25 ( V_22 ) ;
V_51 = F_17 ( V_22 , V_24 , V_2 ,
F_2 ( V_2 ) ) ;
if ( V_51 < 0 )
goto V_82;
if ( ! V_16 ) {
V_51 = F_18 ( V_22 , V_24 ,
& V_61 -> V_81 , V_20 ) ;
if ( V_51 < 0 )
goto V_82;
}
F_20 ( V_61 , V_24 ) ;
V_65 = 0 ;
if ( V_22 -> V_83 )
V_65 = F_10 ( V_17 , V_20 , V_16 ) ;
V_51 = F_21 ( V_22 , V_24 , 1 + V_51 , V_65 ) ;
if ( V_51 )
goto V_82;
return 0 ;
V_82:
F_26 ( L_5 , V_51 ) ;
F_27 ( V_24 ) ;
F_28 ( V_24 , 1 ) ;
return V_51 ;
}
static int F_29 ( struct V_21 * V_22 ,
T_2 * V_2 , struct V_60 * V_61 )
{
struct V_23 * V_24 ;
T_2 * V_4 ;
int V_51 ;
V_24 = F_25 ( V_22 ) ;
V_4 = V_2 + 3 ;
* V_4 ++ = V_84 ;
* V_4 = V_85 ;
V_51 = F_17 ( V_22 , V_24 , V_2 , 20 ) ;
if ( V_51 < 0 )
goto V_82;
F_20 ( V_61 , V_24 ) ;
V_51 = F_21 ( V_22 , V_24 , 1 + V_51 , 0 ) ;
if ( V_51 )
goto V_82;
return 0 ;
V_82:
F_26 ( L_5 , V_51 ) ;
F_27 ( V_24 ) ;
F_28 ( V_24 , 1 ) ;
return V_51 ;
}
void F_30 ( struct V_60 * V_61 )
{
}
int F_31 ( struct V_60 * V_61 )
{
struct V_86 * V_87 = V_61 -> V_88 ;
struct V_21 * V_22 =
F_32 ( V_87 , struct V_21 , V_89 ) ;
T_2 * V_4 , * V_17 , * V_2 , * V_20 , * V_16 ;
struct V_46 * V_47 = & V_61 -> V_81 ;
struct V_42 * V_90 ;
int V_51 ;
V_17 = F_33 ( V_61 -> V_91 [ 0 ] ) ;
F_9 ( V_17 , & V_20 , & V_16 ) ;
F_22 ( L_6 ,
F_3 ( V_17 ) ) ;
V_51 = - V_92 ;
V_90 = F_34 ( V_93 ) ;
if ( ! V_90 )
goto V_94;
V_2 = F_33 ( V_90 ) ;
V_4 = V_2 ;
* V_4 ++ = * V_17 ;
* V_4 ++ = * ( V_17 + 1 ) ;
* V_4 ++ = V_22 -> V_95 ;
* V_4 ++ = V_16 ? V_96 : V_97 ;
* V_4 ++ = V_6 ;
* V_4 ++ = V_6 ;
* V_4 = V_6 ;
if ( V_20 ) {
V_51 = F_35 ( V_22 , V_20 , V_47 ) ;
if ( V_51 < 0 )
goto V_98;
F_7 ( V_2 , V_20 , V_51 ) ;
}
if ( V_16 ) {
V_51 = F_36 ( V_22 , V_16 , V_20 , V_47 ) ;
if ( V_51 < 0 )
goto V_98;
F_8 ( V_2 , V_16 , V_51 ) ;
}
V_51 = F_37 ( V_22 , V_93 ) ;
if ( V_51 )
goto V_99;
V_51 = F_24 ( V_22 , V_17 , V_2 , V_61 ,
V_20 , V_16 ) ;
if ( V_51 < 0 )
goto V_94;
return 0 ;
V_98:
if ( V_51 != - V_100 )
goto V_99;
V_51 = F_37 ( V_22 , V_93 ) ;
if ( V_51 )
goto V_99;
V_51 = F_29 ( V_22 , V_2 , V_61 ) ;
if ( V_51 < 0 )
goto V_94;
return 0 ;
V_99:
F_38 ( V_90 ) ;
V_94:
F_26 ( L_7 ,
V_51 ) ;
F_39 ( V_101 , & V_87 -> V_102 ) ;
return - V_103 ;
}
