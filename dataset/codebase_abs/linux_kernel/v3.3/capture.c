static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
unsigned long V_4 ;
int V_5 , V_6 ;
int V_7 ;
struct V_8 * V_9 ;
F_2 ( & V_2 -> V_10 , V_4 ) ;
V_3 =
F_3 ( & V_2 -> V_11 , V_12 ) ;
if ( V_3 < 0 || V_3 >= V_12 ) {
F_4 ( & V_2 -> V_10 , V_4 ) ;
F_5 ( V_2 -> V_13 -> V_14 , L_1 ) ;
return - V_15 ;
}
V_9 = V_2 -> V_16 [ V_3 ] ;
V_6 = 0 ;
for ( V_5 = 0 ; V_5 < V_17 ; ++ V_5 ) {
struct V_18 * V_19 =
& V_9 -> V_20 [ V_5 ] ;
V_19 -> V_21 = V_6 ;
V_19 -> V_22 = V_2 -> V_23 ;
V_6 += V_2 -> V_23 ;
}
V_9 -> V_24 =
V_2 -> V_25 +
V_3 * V_17 * V_2 -> V_23 ;
V_9 -> V_26 = V_6 ;
V_9 -> V_27 = V_2 ;
V_7 = F_6 ( V_9 , V_28 ) ;
if ( V_7 == 0 )
F_7 ( V_3 , & V_2 -> V_11 ) ;
else
F_5 ( V_2 -> V_13 -> V_14 ,
L_2 , V_3 , V_7 ) ;
F_4 ( & V_2 -> V_10 , V_4 ) ;
return 0 ;
}
int F_8 ( struct V_1 * V_2 )
{
int V_7 , V_5 ;
for ( V_5 = 0 ; V_5 < V_12 ; ++ V_5 ) {
V_7 = F_1 ( V_2 ) ;
if ( V_7 < 0 )
return V_7 ;
}
return 0 ;
}
void F_9 ( struct V_1 * V_2 )
{
unsigned int V_5 ;
for ( V_5 = V_12 ; V_5 -- ; ) {
if ( F_10 ( V_5 , & V_2 -> V_11 ) ) {
if ( ! F_11 ( V_5 , & V_2 -> V_29 ) ) {
struct V_8 * V_30 = V_2 -> V_16 [ V_5 ] ;
F_12 ( V_30 ) ;
}
}
}
}
static void F_13 ( struct V_1 * V_2 )
{
int V_31 = V_32 ;
unsigned int V_5 ;
int V_33 ;
do {
V_33 = 0 ;
for ( V_5 = V_12 ; V_5 -- ; ) {
if ( F_10 ( V_5 , & V_2 -> V_11 ) )
V_33 ++ ;
}
if ( ! V_33 )
break;
F_14 ( V_34 ) ;
F_15 ( 1 ) ;
} while ( -- V_31 > 0 );
if ( V_33 )
F_16 ( V_35 L_3 , V_33 ) ;
}
void F_17 ( struct V_1 * V_2 )
{
F_9 ( V_2 ) ;
F_13 ( V_2 ) ;
}
void F_18 ( struct V_1 * V_2 , char * V_36 , int V_37 )
{
struct V_38 * V_39 =
F_19 ( V_2 , V_40 ) ;
struct V_41 * V_42 = V_39 -> V_42 ;
const int V_43 = V_2 -> V_44 -> V_43 ;
int V_45 = V_37 / V_43 ;
if ( V_42 == NULL )
return;
if ( V_2 -> V_46 + V_45 > V_42 -> V_47 ) {
int V_48 ;
V_48 = V_42 -> V_47 - V_2 -> V_46 ;
if ( V_48 > 0 ) {
memcpy ( V_42 -> V_49 +
V_2 -> V_46 * V_43 , V_36 ,
V_48 * V_43 ) ;
memcpy ( V_42 -> V_49 , V_36 + V_48 * V_43 ,
( V_45 - V_48 ) * V_43 ) ;
} else {
F_5 ( V_2 -> V_13 -> V_14 ,
L_4 , V_48 ) ;
}
} else {
memcpy ( V_42 -> V_49 +
V_2 -> V_46 * V_43 , V_36 , V_37 ) ;
}
V_2 -> V_46 += V_45 ;
if ( V_2 -> V_46 >= V_42 -> V_47 )
V_2 -> V_46 -= V_42 -> V_47 ;
}
void F_20 ( struct V_1 * V_2 , int V_22 )
{
struct V_38 * V_39 =
F_19 ( V_2 , V_40 ) ;
V_2 -> V_50 += V_22 ;
if ( V_2 -> V_50 >= V_2 -> V_51 ) {
V_2 -> V_50 %= V_2 -> V_51 ;
F_21 ( V_39 ) ;
}
}
int F_22 ( struct V_1 * V_2 )
{
if ( V_2 -> V_25 )
return 0 ;
V_2 -> V_25 =
F_23 ( V_12 * V_17 *
V_2 -> V_23 , V_52 ) ;
if ( ! V_2 -> V_25 ) {
F_5 ( V_2 -> V_13 -> V_14 ,
L_5 ) ;
return - V_53 ;
}
return 0 ;
}
void F_24 ( struct V_1 * V_2 )
{
F_25 ( V_2 -> V_25 ) ;
V_2 -> V_25 = NULL ;
}
static void F_26 ( struct V_8 * V_8 )
{
int V_5 , V_3 , V_22 = 0 , V_54 = 0 ;
unsigned long V_4 ;
struct V_1 * V_2 = (struct V_1 * ) V_8 -> V_27 ;
V_2 -> V_55 = V_8 -> V_56 ;
for ( V_3 = 0 ; V_3 < V_12 ; ++ V_3 )
if ( V_8 == V_2 -> V_16 [ V_3 ] )
break;
#ifdef F_27
for ( V_5 = 0 ; V_5 < V_17 ; ++ V_5 ) {
struct V_18 * V_57 =
& V_8 -> V_20 [ V_5 ] ;
F_28 ( V_2 -> V_13 , 'C' ,
V_8 -> V_24 + V_57 -> V_21 ,
V_57 -> V_22 ) ;
}
#endif
F_2 ( & V_2 -> V_10 , V_4 ) ;
for ( V_5 = 0 ; V_5 < V_17 ; ++ V_5 ) {
char * V_36 ;
int V_37 ;
struct V_18 * V_19 = & V_8 -> V_20 [ V_5 ] ;
if ( V_19 -> V_58 == - V_59 ) {
V_54 = 1 ;
break;
}
V_36 = V_8 -> V_24 + V_19 -> V_21 ;
V_37 = V_19 -> V_60 ;
if ( V_37 > V_2 -> V_23 ) {
F_5 ( V_2 -> V_13 -> V_14 ,
L_6 ,
V_37 , V_2 -> V_23 ) ;
}
V_22 += V_37 ;
V_2 -> V_61 = V_36 ;
V_2 -> V_62 = V_37 ;
#ifdef F_29
if ( ! ( V_2 -> V_4 & V_63 ) )
#endif
if ( F_10 ( V_64 , & V_2 -> V_4 )
&& ( V_37 > 0 ) )
F_18 ( V_2 , V_36 , V_37 ) ;
}
F_30 ( V_3 , & V_2 -> V_11 ) ;
if ( F_31 ( V_3 , & V_2 -> V_29 ) )
V_54 = 1 ;
F_4 ( & V_2 -> V_10 , V_4 ) ;
if ( ! V_54 ) {
F_1 ( V_2 ) ;
#ifdef F_29
if ( ! ( V_2 -> V_4 & V_63 ) )
#endif
if ( F_10 ( V_64 , & V_2 -> V_4 ) )
F_20 ( V_2 , V_22 ) ;
}
}
static int F_32 ( struct V_38 * V_39 )
{
int V_65 ;
struct V_41 * V_42 = V_39 -> V_42 ;
struct V_1 * V_2 = F_33 ( V_39 ) ;
V_65 = F_34 ( V_42 , 0 ,
V_66 ,
( & V_2 ->
V_44 -> V_67 ) ) ;
if ( V_65 < 0 )
return V_65 ;
V_42 -> V_68 = V_2 -> V_44 -> V_69 ;
return 0 ;
}
static int F_35 ( struct V_38 * V_39 )
{
return 0 ;
}
static int F_36 ( struct V_38 * V_39 ,
struct V_70 * V_71 )
{
int V_7 ;
struct V_1 * V_2 = F_33 ( V_39 ) ;
if ( V_2 == NULL ) {
if ( V_39 -> V_72 == NULL )
return - V_53 ;
if ( V_39 -> V_72 -> V_73 == NULL )
return - V_53 ;
V_39 -> V_73 = V_39 -> V_72 -> V_73 ;
V_2 = F_33 ( V_39 ) ;
}
if ( ( V_2 -> V_4 & V_74 ) == 0 ) {
V_7 = F_22 ( V_2 ) ;
if ( V_7 < 0 )
return V_7 ;
}
V_7 = F_37 ( V_39 ,
F_38 ( V_71 ) ) ;
if ( V_7 < 0 )
return V_7 ;
V_2 -> V_51 = F_39 ( V_71 ) ;
return 0 ;
}
static int F_40 ( struct V_38 * V_39 )
{
struct V_1 * V_2 = F_33 ( V_39 ) ;
if ( ( V_2 -> V_4 & V_74 ) == 0 ) {
F_17 ( V_2 ) ;
F_24 ( V_2 ) ;
}
return F_41 ( V_39 ) ;
}
int F_42 ( struct V_1 * V_2 , int V_75 )
{
int V_65 ;
switch ( V_75 ) {
case V_76 :
#ifdef F_43
case V_77 :
#endif
V_65 = F_44 ( V_2 , V_78 ) ;
if ( V_65 < 0 )
return V_65 ;
break;
case V_79 :
#ifdef F_43
case V_80 :
#endif
V_65 = F_45 ( V_2 , V_78 ) ;
if ( V_65 < 0 )
return V_65 ;
break;
default:
return - V_15 ;
}
return 0 ;
}
static T_1
F_46 ( struct V_38 * V_39 )
{
struct V_1 * V_2 = F_33 ( V_39 ) ;
return V_2 -> V_46 ;
}
int F_47 ( struct V_1 * V_2 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_12 ; ++ V_5 ) {
struct V_8 * V_8 ;
V_8 = V_2 -> V_16 [ V_5 ] =
F_48 ( V_17 , V_52 ) ;
if ( V_8 == NULL ) {
F_5 ( V_2 -> V_13 -> V_14 , L_7 ) ;
return - V_53 ;
}
V_8 -> V_81 = V_2 -> V_13 -> V_82 ;
V_8 -> V_83 =
F_49 ( V_2 -> V_13 -> V_82 ,
V_2 -> V_84 &
V_85 ) ;
V_8 -> V_86 = V_87 ;
V_8 -> V_56 = - 1 ;
V_8 -> V_88 = V_17 ;
V_8 -> V_89 = V_90 ;
V_8 -> V_91 = 0 ;
V_8 -> V_92 = F_26 ;
}
return 0 ;
}
