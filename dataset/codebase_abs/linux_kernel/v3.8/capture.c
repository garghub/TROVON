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
void F_13 ( struct V_1 * V_2 )
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
void F_22 ( struct V_1 * V_2 )
{
F_23 ( V_2 -> V_25 ) ;
V_2 -> V_25 = NULL ;
}
static void F_24 ( struct V_8 * V_8 )
{
int V_5 , V_3 , V_22 = 0 , V_52 = 0 ;
unsigned long V_4 ;
struct V_1 * V_2 = (struct V_1 * ) V_8 -> V_27 ;
V_2 -> V_53 = V_8 -> V_54 ;
for ( V_3 = 0 ; V_3 < V_12 ; ++ V_3 )
if ( V_8 == V_2 -> V_16 [ V_3 ] )
break;
#ifdef F_25
for ( V_5 = 0 ; V_5 < V_17 ; ++ V_5 ) {
struct V_18 * V_55 =
& V_8 -> V_20 [ V_5 ] ;
F_26 ( V_2 -> V_13 , 'C' ,
V_8 -> V_24 + V_55 -> V_21 ,
V_55 -> V_22 ) ;
}
#endif
F_2 ( & V_2 -> V_10 , V_4 ) ;
for ( V_5 = 0 ; V_5 < V_17 ; ++ V_5 ) {
char * V_36 ;
int V_37 ;
struct V_18 * V_19 = & V_8 -> V_20 [ V_5 ] ;
if ( V_19 -> V_56 == - V_57 ) {
V_52 = 1 ;
break;
}
V_36 = V_8 -> V_24 + V_19 -> V_21 ;
V_37 = V_19 -> V_58 ;
if ( V_37 > V_2 -> V_23 ) {
F_5 ( V_2 -> V_13 -> V_14 ,
L_5 ,
V_37 , V_2 -> V_23 ) ;
}
V_22 += V_37 ;
V_2 -> V_59 = V_36 ;
V_2 -> V_60 = V_37 ;
#ifdef F_27
if ( ! ( V_2 -> V_4 & V_61 ) )
#endif
if ( F_10 ( V_62 ,
& V_2 -> V_4 ) && ( V_37 > 0 ) )
F_18 ( V_2 , V_36 , V_37 ) ;
}
F_28 ( V_3 , & V_2 -> V_11 ) ;
if ( F_29 ( V_3 , & V_2 -> V_29 ) )
V_52 = 1 ;
F_4 ( & V_2 -> V_10 , V_4 ) ;
if ( ! V_52 ) {
F_1 ( V_2 ) ;
#ifdef F_27
if ( ! ( V_2 -> V_4 & V_61 ) )
#endif
if ( F_10 ( V_62 ,
& V_2 -> V_4 ) )
F_20 ( V_2 , V_22 ) ;
}
}
static int F_30 ( struct V_38 * V_39 )
{
int V_63 ;
struct V_41 * V_42 = V_39 -> V_42 ;
struct V_1 * V_2 = F_31 ( V_39 ) ;
V_63 = F_32 ( V_42 , 0 ,
V_64 ,
( & V_2 ->
V_44 -> V_65 ) ) ;
if ( V_63 < 0 )
return V_63 ;
V_42 -> V_66 = V_2 -> V_44 -> V_67 ;
return 0 ;
}
static int F_33 ( struct V_38 * V_39 )
{
return 0 ;
}
static int F_34 ( struct V_38 * V_39 ,
struct V_68 * V_69 )
{
int V_7 ;
struct V_1 * V_2 = F_31 ( V_39 ) ;
if ( V_2 == NULL ) {
if ( V_39 -> V_70 == NULL )
return - V_71 ;
if ( V_39 -> V_70 -> V_72 == NULL )
return - V_71 ;
V_39 -> V_72 = V_39 -> V_70 -> V_72 ;
V_2 = F_31 ( V_39 ) ;
}
V_7 = F_35 ( V_2 , V_73 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_36 ( V_39 ,
F_37 ( V_69 ) ) ;
if ( V_7 < 0 ) {
F_38 ( V_2 , V_73 ) ;
return V_7 ;
}
V_2 -> V_51 = F_39 ( V_69 ) ;
return 0 ;
}
static int F_40 ( struct V_38 * V_39 )
{
struct V_1 * V_2 = F_31 ( V_39 ) ;
F_38 ( V_2 , V_73 ) ;
return F_41 ( V_39 ) ;
}
int F_42 ( struct V_1 * V_2 , int V_74 )
{
int V_63 ;
switch ( V_74 ) {
case V_75 :
#ifdef F_43
case V_76 :
#endif
V_63 = F_35 ( V_2 ,
V_77 ) ;
if ( V_63 < 0 )
return V_63 ;
break;
case V_78 :
#ifdef F_43
case V_79 :
#endif
V_63 = F_38 ( V_2 ,
V_77 ) ;
if ( V_63 < 0 )
return V_63 ;
break;
default:
return - V_15 ;
}
return 0 ;
}
static T_1
F_44 ( struct V_38 * V_39 )
{
struct V_1 * V_2 = F_31 ( V_39 ) ;
return V_2 -> V_46 ;
}
int F_45 ( struct V_1 * V_2 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_12 ; ++ V_5 ) {
struct V_8 * V_8 ;
V_8 = V_2 -> V_16 [ V_5 ] =
F_46 ( V_17 , V_80 ) ;
if ( V_8 == NULL ) {
F_5 ( V_2 -> V_13 -> V_14 , L_6 ) ;
return - V_71 ;
}
V_8 -> V_81 = V_2 -> V_13 -> V_82 ;
V_8 -> V_83 =
F_47 ( V_2 -> V_13 -> V_82 ,
V_2 -> V_84 &
V_85 ) ;
V_8 -> V_86 = V_87 ;
V_8 -> V_54 = - 1 ;
V_8 -> V_88 = V_17 ;
V_8 -> V_89 = V_90 ;
V_8 -> V_91 = 0 ;
V_8 -> V_92 = F_24 ;
}
return 0 ;
}
