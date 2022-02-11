static int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 , unsigned int V_4 )
{
if ( V_2 -> V_5 < V_3 )
return - V_6 ;
if ( V_2 -> V_7 < V_4 )
return - V_8 ;
V_2 -> V_9 += V_3 ;
V_2 -> V_5 -= V_3 ;
V_2 -> V_10 += V_4 ;
V_2 -> V_7 -= V_4 ;
V_2 -> V_11 += V_4 ;
return 0 ;
}
static int F_2 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = F_3 ( V_13 ) ;
V_15 -> V_16 = F_4 ( F_5 () , V_17 ) ;
V_15 -> V_18 = ( V_19 * ) F_6 ( V_17 , V_20 ) ;
V_15 -> V_21 = ( V_19 * ) F_6 ( V_17 , V_20 ) ;
if ( ! V_15 -> V_16 || ! V_15 -> V_18 || ! V_15 -> V_21 ) {
F_7 ( V_15 -> V_16 ) ;
F_8 ( ( unsigned long ) V_15 -> V_18 ) ;
F_8 ( ( unsigned long ) V_15 -> V_21 ) ;
return - V_22 ;
}
return 0 ;
}
static void F_9 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = F_3 ( V_13 ) ;
F_7 ( V_15 -> V_16 ) ;
F_8 ( ( unsigned long ) V_15 -> V_18 ) ;
F_8 ( ( unsigned long ) V_15 -> V_21 ) ;
}
static int F_10 ( struct V_23 * V_24 )
{
int V_25 ;
V_25 = V_23 ( V_24 ) ;
if ( V_25 ) {
F_11 ( L_1 ,
V_25 ) ;
return V_25 ;
}
if ( V_24 -> V_26 > V_27 ) {
V_24 -> V_26 = V_27 ;
F_12 ( L_2 , V_24 -> V_26 ) ;
}
return 0 ;
}
static int F_13 ( struct V_28 * V_29 , V_19 * V_30 )
{
int V_31 = F_14 ( V_29 -> V_32 ) ;
if ( V_31 > F_15 ( V_29 -> V_33 [ 0 ] . V_34 ) ) {
F_16 ( L_3 ) ;
return - V_35 ;
}
memcpy ( V_30 , V_29 , V_31 ) ;
F_17 ( L_4 , V_36 , 16 , 1 , V_30 , V_31 , 0 ) ;
return 0 ;
}
static int F_18 ( struct V_14 * V_15 ,
struct V_1 * V_2 ,
struct V_37 * V_38 ,
struct V_23 * V_24 ,
T_1 * V_39 ,
unsigned int V_40 )
{
unsigned int V_3 = V_2 -> V_5 , V_4 = V_2 -> V_7 , V_41 ;
unsigned int V_42 = V_3 ;
V_19 * V_43 = V_2 -> V_9 , * V_44 = V_2 -> V_10 ;
int V_25 , V_45 = 0 ;
T_2 V_46 ;
if ( V_2 -> V_5 == 0 )
return - V_6 ;
if ( V_2 -> V_7 == 0 || V_40 + V_24 -> V_47 > V_4 )
return - V_8 ;
if ( V_3 % V_24 -> V_48 )
V_42 = F_19 ( V_3 , V_24 -> V_48 ) ;
if ( V_3 < V_24 -> V_47 )
V_42 = V_24 -> V_47 ;
if ( V_3 > V_24 -> V_26 )
V_42 = V_3 = V_24 -> V_26 ;
if ( V_42 > V_3 || ( V_49 ) V_43 % V_24 -> V_50 ) {
V_42 = F_20 ( V_42 , V_27 ) ;
V_3 = F_20 ( V_3 , V_27 ) ;
if ( V_42 > V_3 )
memset ( V_15 -> V_18 + V_3 , 0 , V_42 - V_3 ) ;
memcpy ( V_15 -> V_18 , V_43 , V_3 ) ;
V_43 = V_15 -> V_18 ;
V_3 = V_42 ;
F_21 ( L_5 , V_3 ) ;
}
V_44 += V_40 ;
V_4 -= V_40 ;
if ( ( V_49 ) V_44 % V_24 -> V_50 ) {
V_45 = ( int ) ( F_22 ( V_44 , V_24 -> V_50 ) - V_44 ) ;
V_44 += V_45 ;
V_4 -= V_45 ;
}
if ( V_4 % V_24 -> V_48 )
V_4 = F_23 ( V_4 , V_24 -> V_48 ) ;
if ( V_4 < V_24 -> V_47 ) {
V_51:
V_44 = V_15 -> V_21 ;
V_4 = F_20 ( V_2 -> V_7 , V_27 ) ;
V_4 = F_23 ( V_4 , V_24 -> V_48 ) ;
V_45 = 0 ;
F_21 ( L_6 , V_4 ) ;
}
if ( V_4 > V_24 -> V_26 )
V_4 = V_24 -> V_26 ;
V_41 = V_4 ;
V_46 = F_24 ( F_25 () , V_52 ) ;
do {
V_4 = V_41 ;
V_25 = F_26 ( V_43 , V_3 , V_44 , & V_4 , V_15 -> V_16 ) ;
if ( V_25 == - V_8 && V_44 != V_15 -> V_21 )
goto V_51;
} while ( V_25 == - V_53 && F_27 ( F_25 () , V_46 ) );
if ( V_25 )
return V_25 ;
V_45 += V_40 ;
if ( V_44 == V_15 -> V_21 )
memcpy ( V_2 -> V_10 + V_45 , V_44 , V_4 ) ;
V_38 -> V_34 = F_28 ( V_45 ) ;
V_38 -> V_54 = F_29 ( V_4 ) ;
V_38 -> V_55 = F_29 ( V_3 ) ;
if ( V_2 -> V_5 < V_3 ) {
* V_39 = V_3 - V_2 -> V_5 ;
V_3 = V_2 -> V_5 ;
}
F_21 ( L_7 ,
V_3 , * V_39 , V_4 , V_45 ) ;
return F_1 ( V_2 , V_3 , V_45 + V_4 ) ;
}
static int F_30 ( struct V_12 * V_13 ,
const V_19 * V_43 , unsigned int V_3 ,
V_19 * V_44 , unsigned int * V_4 )
{
struct V_14 * V_15 = F_3 ( V_13 ) ;
struct V_28 * V_29 = & V_15 -> V_56 ;
struct V_1 V_2 ;
struct V_23 V_24 ;
unsigned int V_32 , V_40 , V_57 ;
int V_25 , V_58 ;
bool V_59 ;
T_1 V_39 = 0 ;
V_2 . V_9 = ( V_19 * ) V_43 ;
V_2 . V_5 = V_3 ;
V_2 . V_10 = V_44 ;
V_2 . V_7 = * V_4 ;
V_2 . V_11 = 0 ;
* V_4 = 0 ;
V_25 = F_10 ( & V_24 ) ;
if ( V_25 )
return V_25 ;
V_32 = F_31 (unsigned int, NX842_CRYPTO_GROUP_MAX,
DIV_ROUND_UP(p.iremain, c.maximum)) ;
V_40 = F_14 ( V_32 ) ;
V_59 = ( V_2 . V_5 % V_24 . V_48 ||
V_2 . V_5 < V_24 . V_47 ||
V_2 . V_5 > V_24 . V_26 ||
( V_49 ) V_2 . V_9 % V_24 . V_50 ||
V_2 . V_7 % V_24 . V_48 ||
V_2 . V_7 < V_24 . V_47 ||
V_2 . V_7 > V_24 . V_26 ||
( V_49 ) V_2 . V_10 % V_24 . V_50 ) ;
V_29 -> V_60 = F_28 ( V_61 ) ;
V_29 -> V_32 = 0 ;
V_29 -> V_39 = 0 ;
while ( V_2 . V_5 > 0 ) {
V_58 = V_29 -> V_32 ++ ;
if ( V_29 -> V_32 > V_62 )
return - V_8 ;
V_57 = ! V_58 && V_59 ? V_40 : 0 ;
if ( V_39 )
F_32 ( L_8 , V_39 ) ;
V_25 = F_18 ( V_15 , & V_2 , & V_29 -> V_33 [ V_58 ] , & V_24 , & V_39 , V_57 ) ;
if ( V_25 )
return V_25 ;
}
if ( ! V_59 && V_29 -> V_32 > 1 ) {
F_16 ( L_9 ) ;
return - V_35 ;
}
V_29 -> V_39 = F_28 ( V_39 ) ;
if ( V_39 )
F_21 ( L_10 , V_39 ) ;
if ( V_59 )
V_25 = F_13 ( V_29 , V_44 ) ;
if ( V_25 )
return V_25 ;
* V_4 = V_2 . V_11 ;
F_21 ( L_11 , V_3 , * V_4 ) ;
return 0 ;
}
static int F_33 ( struct V_14 * V_15 ,
struct V_1 * V_2 ,
struct V_37 * V_38 ,
struct V_23 * V_24 ,
T_1 V_39 ,
bool V_63 )
{
unsigned int V_3 = F_34 ( V_38 -> V_54 ) ;
unsigned int V_64 = F_34 ( V_38 -> V_55 ) ;
unsigned int V_4 = V_2 -> V_7 , V_41 ;
unsigned int V_42 = V_3 ;
V_19 * V_43 = V_2 -> V_9 , * V_44 = V_2 -> V_10 ;
T_1 V_34 = F_15 ( V_38 -> V_34 ) ;
int V_25 , V_65 = 0 , V_66 = 0 ;
T_2 V_46 ;
if ( ! V_3 || ! V_64 )
return - V_35 ;
if ( V_2 -> V_5 <= 0 || V_34 + V_3 > V_2 -> V_5 )
return - V_6 ;
if ( V_2 -> V_7 <= 0 || V_64 - V_39 > V_2 -> V_7 )
return - V_8 ;
V_43 += V_34 ;
if ( ! V_63 )
goto V_67;
if ( V_3 % V_24 -> V_48 )
V_42 = F_19 ( V_3 , V_24 -> V_48 ) ;
if ( V_3 < V_24 -> V_47 )
V_42 = V_24 -> V_47 ;
if ( V_3 > V_24 -> V_26 )
goto V_67;
if ( V_3 < V_42 || ( V_49 ) V_43 % V_24 -> V_50 ) {
if ( V_3 < V_42 )
memset ( V_15 -> V_18 + V_3 , 0 , V_42 - V_3 ) ;
memcpy ( V_15 -> V_18 , V_43 , V_3 ) ;
V_43 = V_15 -> V_18 ;
V_65 = V_42 - V_3 ;
V_3 = V_42 ;
F_21 ( L_12 , V_3 ) ;
}
if ( V_4 % V_24 -> V_48 )
V_4 = F_23 ( V_4 , V_24 -> V_48 ) ;
if ( V_4 < V_64 || ( V_49 ) V_44 % V_24 -> V_50 ) {
V_44 = V_15 -> V_21 ;
V_4 = F_20 ( V_64 , V_27 ) ;
F_21 ( L_13 , V_4 ) ;
}
if ( V_4 < V_24 -> V_47 )
goto V_67;
if ( V_4 > V_24 -> V_26 )
V_4 = V_24 -> V_26 ;
V_41 = V_4 ;
V_46 = F_24 ( F_25 () , V_68 ) ;
do {
V_4 = V_41 ;
V_25 = F_35 ( V_43 , V_3 , V_44 , & V_4 , V_15 -> V_16 ) ;
} while ( V_25 == - V_53 && F_27 ( F_25 () , V_46 ) );
if ( V_25 ) {
V_67:
V_43 = V_2 -> V_9 + V_34 ;
V_3 = F_34 ( V_38 -> V_54 ) ;
V_65 = 0 ;
V_44 = V_2 -> V_10 ;
V_4 = V_2 -> V_7 ;
V_66 = 0 ;
if ( V_4 < V_64 ) {
V_44 = V_15 -> V_21 ;
V_4 = V_27 ;
}
F_36 ( L_14 ) ;
V_25 = F_37 ( V_43 , V_3 , V_44 , & V_4 ) ;
}
if ( V_25 )
return V_25 ;
V_3 -= V_65 ;
V_4 -= V_39 ;
if ( V_39 )
F_21 ( L_15 , V_39 ) ;
if ( V_44 == V_15 -> V_21 )
memcpy ( V_2 -> V_10 , V_44 , V_4 ) ;
F_21 ( L_16 ,
V_3 , V_34 , V_4 , V_39 ) ;
return F_1 ( V_2 , V_3 + V_34 , V_4 ) ;
}
static int F_38 ( struct V_12 * V_13 ,
const V_19 * V_43 , unsigned int V_3 ,
V_19 * V_44 , unsigned int * V_4 )
{
struct V_14 * V_15 = F_3 ( V_13 ) ;
struct V_28 * V_29 ;
struct V_1 V_2 ;
struct V_23 V_24 ;
int V_58 , V_25 , V_69 ;
T_1 V_39 = 0 ;
bool V_63 = true ;
V_2 . V_9 = ( V_19 * ) V_43 ;
V_2 . V_5 = V_3 ;
V_2 . V_10 = V_44 ;
V_2 . V_7 = * V_4 ;
V_2 . V_11 = 0 ;
* V_4 = 0 ;
if ( F_10 ( & V_24 ) )
V_63 = false ;
V_29 = (struct V_28 * ) V_43 ;
if ( F_15 ( V_29 -> V_60 ) != V_61 ) {
struct V_37 V_38 = {
. V_34 = 0 ,
. V_54 = F_29 ( V_2 . V_5 ) ,
. V_55 = F_29 ( V_2 . V_7 ) ,
} ;
V_25 = F_33 ( V_15 , & V_2 , & V_38 , & V_24 , 0 , V_63 ) ;
if ( V_25 )
return V_25 ;
* V_4 = V_2 . V_11 ;
return 0 ;
}
if ( ! V_29 -> V_32 ) {
F_16 ( L_17 ) ;
return - V_35 ;
}
if ( V_29 -> V_32 > V_62 ) {
F_16 ( L_18 ,
V_29 -> V_32 , V_62 ) ;
return - V_35 ;
}
V_69 = F_14 ( V_29 -> V_32 ) ;
if ( V_69 > V_3 )
return - V_6 ;
memcpy ( & V_15 -> V_56 , V_43 , V_69 ) ;
V_29 = & V_15 -> V_56 ;
for ( V_58 = 0 ; V_58 < V_29 -> V_32 ; V_58 ++ ) {
if ( V_58 + 1 == V_29 -> V_32 )
V_39 = F_15 ( V_29 -> V_39 ) ;
V_25 = F_33 ( V_15 , & V_2 , & V_29 -> V_33 [ V_58 ] , & V_24 , V_39 , V_63 ) ;
if ( V_25 )
return V_25 ;
}
* V_4 = V_2 . V_11 ;
F_21 ( L_19 , V_3 , * V_4 ) ;
return 0 ;
}
static int T_3 F_39 ( void )
{
return F_40 ( & V_70 ) ;
}
static void T_4 F_41 ( void )
{
F_42 ( & V_70 ) ;
}
