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
goto V_35;
V_24 -> V_36 [ V_25 ] . V_37 = V_33 ;
V_24 -> V_36 [ V_25 ] . V_38 = V_1 ;
V_24 -> V_36 [ V_25 ] . V_39 = V_22 -> V_40 -> V_41 ;
F_15 ( V_22 , V_24 ) ;
return 0 ;
V_35:
F_16 ( L_1 ) ;
return - V_42 ;
}
static int F_17 ( struct V_21 * V_22 ,
struct V_23 * V_24 ,
unsigned int V_25 ,
struct V_43 * V_43 ,
unsigned int V_27 ,
unsigned int V_1 )
{
struct V_29 * V_30 = V_22 -> V_31 -> V_32 ;
T_3 V_33 ;
V_33 = F_12 ( V_30 , V_43 , V_27 , V_1 , V_34 ) ;
if ( F_14 ( V_30 , V_33 ) )
goto V_35;
V_24 -> V_36 [ V_25 ] . V_37 = V_33 ;
V_24 -> V_36 [ V_25 ] . V_38 = V_1 ;
V_24 -> V_36 [ V_25 ] . V_39 = V_22 -> V_40 -> V_41 ;
F_15 ( V_22 , V_24 ) ;
return 0 ;
V_35:
F_16 ( L_2 ) ;
return - V_42 ;
}
int F_18 ( struct V_21 * V_22 ,
struct V_23 * V_24 ,
T_2 * V_2 ,
unsigned int V_1 )
{
V_24 -> V_44 = V_34 ;
V_24 -> V_45 [ 0 ] = F_13 ( V_2 ) ;
V_24 -> V_46 = 1 ;
return F_17 ( V_22 , V_24 , 0 , V_24 -> V_45 [ 0 ] , 0 , V_1 ) ;
}
static int F_19 ( struct V_21 * V_22 ,
struct V_23 * V_24 ,
struct V_47 * V_48 , T_2 * V_20 )
{
unsigned int V_1 , V_25 , V_10 , V_49 ;
struct V_43 * * V_50 ;
unsigned char * V_26 ;
T_1 V_51 ;
int V_52 ;
V_25 = 1 ;
V_52 = F_11 ( V_22 , V_24 , V_25 ++ ,
V_48 -> V_53 [ 0 ] . V_54 ,
V_48 -> V_53 [ 0 ] . V_55 ) ;
if ( V_52 < 0 )
return V_52 ;
if ( V_20 ) {
V_26 = V_48 -> V_56 [ 0 ] . V_54 ;
V_1 = V_48 -> V_56 [ 0 ] . V_55 ;
V_51 = F_1 ( V_48 -> V_57 ) ;
if ( V_1 && V_51 ) {
V_26 += V_51 ;
V_1 -= V_51 ;
}
goto V_56;
}
V_50 = V_48 -> V_45 + ( V_48 -> V_58 >> V_59 ) ;
V_49 = V_48 -> V_58 & ~ V_28 ;
V_10 = V_48 -> V_57 ;
while ( V_10 ) {
V_1 = F_20 ( T_1 , V_60 - V_49 , V_10 ) ;
V_52 = F_17 ( V_22 , V_24 , V_25 ++ ,
* V_50 ++ , V_49 , V_1 ) ;
if ( V_52 < 0 )
return V_52 ;
V_10 -= V_1 ;
V_49 = 0 ;
}
V_26 = V_48 -> V_56 [ 0 ] . V_54 ;
V_1 = V_48 -> V_56 [ 0 ] . V_55 ;
V_56:
if ( V_1 ) {
V_52 = F_11 ( V_22 , V_24 , V_25 ++ , V_26 , V_1 ) ;
if ( V_52 < 0 )
return V_52 ;
}
return V_25 - 1 ;
}
static void F_21 ( struct V_61 * V_62 ,
struct V_23 * V_24 )
{
int V_11 , V_45 = V_62 -> V_63 - V_62 -> V_64 ;
V_24 -> V_46 += V_45 ;
for ( V_11 = 0 ; V_11 < V_45 ; V_11 ++ ) {
V_24 -> V_45 [ V_11 + 1 ] = V_62 -> V_64 [ V_11 ] ;
V_62 -> V_64 [ V_11 ] = NULL ;
}
V_62 -> V_63 = V_62 -> V_64 + 1 ;
}
int F_22 ( struct V_21 * V_22 ,
struct V_23 * V_24 , int V_65 ,
T_1 V_66 )
{
struct V_67 * V_68 = & V_24 -> V_68 ;
F_23 ( L_3 , V_65 ) ;
V_68 -> V_69 = NULL ;
V_24 -> V_70 . V_71 = V_72 ;
V_68 -> V_73 = & V_24 -> V_70 ;
V_68 -> V_74 = V_24 -> V_36 ;
V_68 -> V_65 = V_65 ;
V_68 -> V_75 = V_76 ;
if ( V_66 ) {
V_68 -> V_77 = V_78 ;
V_68 -> V_79 . V_80 = V_66 ;
} else {
V_68 -> V_77 = V_81 ;
}
return F_24 ( V_22 , V_68 ) ;
}
static int F_25 ( struct V_21 * V_22 ,
T_2 * V_17 , T_2 * V_2 ,
struct V_61 * V_62 ,
T_2 * V_20 , T_2 * V_16 )
{
struct V_23 * V_24 ;
T_1 V_66 ;
int V_52 ;
F_23 ( L_4 ,
( V_16 ? L_5 : L_6 ) ,
V_62 -> V_82 . V_53 [ 0 ] . V_55 ,
V_62 -> V_82 . V_57 ,
V_62 -> V_82 . V_56 [ 0 ] . V_55 ) ;
V_24 = F_26 ( V_22 ) ;
V_52 = F_18 ( V_22 , V_24 , V_2 ,
F_2 ( V_2 ) ) ;
if ( V_52 < 0 )
goto V_83;
if ( ! V_16 ) {
V_52 = F_19 ( V_22 , V_24 ,
& V_62 -> V_82 , V_20 ) ;
if ( V_52 < 0 )
goto V_83;
}
F_21 ( V_62 , V_24 ) ;
V_66 = 0 ;
if ( V_22 -> V_84 )
V_66 = F_10 ( V_17 , V_20 , V_16 ) ;
V_52 = F_22 ( V_22 , V_24 , 1 + V_52 , V_66 ) ;
if ( V_52 )
goto V_83;
return 0 ;
V_83:
F_27 ( V_24 ) ;
F_28 ( V_24 , 1 ) ;
return V_52 ;
}
static int F_29 ( struct V_21 * V_22 ,
T_2 * V_2 , struct V_61 * V_62 )
{
struct V_23 * V_24 ;
T_2 * V_4 ;
int V_52 ;
V_24 = F_26 ( V_22 ) ;
V_4 = V_2 + 3 ;
* V_4 ++ = V_85 ;
* V_4 = V_86 ;
V_52 = F_18 ( V_22 , V_24 , V_2 , 20 ) ;
if ( V_52 < 0 )
goto V_83;
F_21 ( V_62 , V_24 ) ;
V_52 = F_22 ( V_22 , V_24 , 1 + V_52 , 0 ) ;
if ( V_52 )
goto V_83;
return 0 ;
V_83:
F_16 ( L_7 , V_52 ) ;
F_27 ( V_24 ) ;
F_28 ( V_24 , 1 ) ;
return V_52 ;
}
void F_30 ( struct V_61 * V_62 )
{
}
int F_31 ( struct V_61 * V_62 )
{
struct V_87 * V_88 = V_62 -> V_89 ;
struct V_21 * V_22 =
F_32 ( V_88 , struct V_21 , V_90 ) ;
T_2 * V_4 , * V_17 , * V_2 , * V_20 , * V_16 ;
struct V_47 * V_48 = & V_62 -> V_82 ;
struct V_43 * V_91 ;
int V_52 ;
V_17 = F_33 ( V_62 -> V_92 [ 0 ] ) ;
F_9 ( V_17 , & V_20 , & V_16 ) ;
F_23 ( L_8 ,
F_3 ( V_17 ) ) ;
V_52 = - V_93 ;
V_91 = F_34 ( V_94 ) ;
if ( ! V_91 )
goto V_95;
V_2 = F_33 ( V_91 ) ;
V_4 = V_2 ;
* V_4 ++ = * V_17 ;
* V_4 ++ = * ( V_17 + 1 ) ;
* V_4 ++ = V_22 -> V_96 ;
* V_4 ++ = V_16 ? V_97 : V_98 ;
* V_4 ++ = V_6 ;
* V_4 ++ = V_6 ;
* V_4 = V_6 ;
if ( V_20 ) {
V_52 = F_35 ( V_22 , V_20 , V_48 ) ;
if ( V_52 < 0 )
goto V_99;
F_7 ( V_2 , V_20 , V_52 ) ;
}
if ( V_16 ) {
V_52 = F_36 ( V_22 , V_16 , V_20 , V_48 ) ;
if ( V_52 < 0 )
goto V_99;
F_8 ( V_2 , V_16 , V_52 ) ;
}
V_52 = F_37 ( V_22 , V_94 ) ;
if ( V_52 )
goto V_100;
V_52 = F_25 ( V_22 , V_17 , V_2 , V_62 ,
V_20 , V_16 ) ;
if ( V_52 < 0 )
goto V_95;
return 0 ;
V_99:
if ( V_52 != - V_101 && V_52 != - V_102 )
goto V_100;
V_52 = F_37 ( V_22 , V_94 ) ;
if ( V_52 )
goto V_100;
V_52 = F_29 ( V_22 , V_2 , V_62 ) ;
if ( V_52 < 0 )
goto V_95;
return 0 ;
V_100:
F_38 ( V_91 ) ;
V_95:
F_16 ( L_9 ,
V_52 ) ;
F_39 ( V_103 , & V_88 -> V_104 ) ;
return - V_105 ;
}
