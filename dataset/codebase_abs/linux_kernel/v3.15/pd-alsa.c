static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = & V_4 -> V_7 ;
struct V_8 * V_9 = V_2 -> V_9 ;
if ( ! V_4 )
return - V_10 ;
V_6 -> V_11 ++ ;
V_6 -> V_12 = 0 ;
V_6 -> V_13 = V_2 ;
V_9 -> V_14 = V_4 ;
V_9 -> V_15 = V_16 ;
F_3 ( V_9 , V_17 ) ;
F_4 ( V_4 -> V_18 ) ;
F_5 ( & V_4 -> V_19 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = & V_4 -> V_7 ;
V_6 -> V_11 -- ;
V_6 -> V_12 = 1 ;
F_7 ( V_4 -> V_18 ) ;
F_8 ( & V_4 -> V_19 , V_20 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_21 * V_22 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
unsigned int V_23 ;
V_23 = F_10 ( V_22 ) ;
if ( V_9 -> V_24 ) {
if ( V_9 -> V_25 > V_23 )
return 0 ;
F_11 ( V_9 -> V_24 ) ;
}
V_9 -> V_24 = F_12 ( V_23 ) ;
if ( ! V_9 -> V_24 )
return - V_26 ;
else
V_9 -> V_25 = V_23 ;
return 0 ;
}
static int F_13 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = & V_4 -> V_7 ;
int V_27 ;
for ( V_27 = 0 ; V_27 < V_28 ; V_27 ++ )
if ( V_6 -> V_29 [ V_27 ] )
F_14 ( V_6 -> V_29 [ V_27 ] ) ;
F_15 ( V_6 -> V_29 , V_28 ) ;
F_16 () ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_16 () ;
F_13 ( V_4 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 )
{
return 0 ;
}
static inline void F_19 ( struct V_30 * V_30 , int * V_31 )
{
struct V_5 * V_6 = V_30 -> V_32 ;
struct V_8 * V_9 = V_6 -> V_13 -> V_9 ;
int V_33 = V_9 -> V_34 >> 3 ;
int V_35 = V_30 -> V_36 / V_33 ;
unsigned char * V_37 = V_30 -> V_38 ;
unsigned int V_39 = V_6 -> V_40 ;
if ( V_30 -> V_36 == V_41 - 4 )
V_35 -= ( V_42 / V_33 ) ;
if ( V_39 + V_35 >= V_9 -> V_43 ) {
unsigned int V_44 = V_9 -> V_43 - V_39 ;
memcpy ( V_9 -> V_24 + V_39 * V_33 , V_37 , V_44 * V_33 ) ;
memcpy ( V_9 -> V_24 , ( V_37 + V_44 * V_33 ) ,
( V_35 * V_33 - V_44 * V_33 ) ) ;
} else
memcpy ( V_9 -> V_24 + V_39 * V_33 , V_37 , V_35 * V_33 ) ;
F_20 ( V_6 -> V_13 ) ;
V_6 -> V_40 += V_35 ;
if ( V_6 -> V_40 >= V_9 -> V_43 )
V_6 -> V_40 -= V_9 -> V_43 ;
V_6 -> V_45 += ( V_35 ) ;
if ( V_6 -> V_45 >= V_9 -> V_46 ) {
V_6 -> V_45 -= V_9 -> V_46 ;
* V_31 = 1 ;
}
F_21 ( V_6 -> V_13 ) ;
}
static void F_22 ( struct V_30 * V_30 )
{
struct V_5 * V_6 = V_30 -> V_32 ;
struct V_1 * V_2 = V_6 -> V_13 ;
int V_31 = 0 ;
int V_47 ;
if ( 1 == V_6 -> V_12 || V_6 -> V_48 != V_49 )
return;
if ( V_30 -> V_50 != 0 ) {
return;
}
if ( V_2 ) {
if ( V_30 -> V_36 ) {
F_19 ( V_30 , & V_31 ) ;
if ( V_31 )
F_23 ( V_2 ) ;
}
}
V_47 = F_24 ( V_30 , V_51 ) ;
if ( V_47 < 0 )
log ( L_1 , V_47 ) ;
return;
}
static int F_25 ( struct V_3 * V_4 )
{
int V_27 , V_47 = 0 ;
struct V_5 * V_6 = & V_4 -> V_7 ;
F_26 ( V_6 -> V_29 , V_28 ,
V_4 -> V_52 , V_53 ,
V_41 , V_51 ,
F_22 , V_6 ) ;
for ( V_27 = 0 ; V_27 < V_28 ; V_27 ++ ) {
V_47 = F_24 ( V_6 -> V_29 [ V_27 ] , V_54 ) ;
if ( V_47 )
log ( L_2 , V_47 ) ;
}
log () ;
return V_47 ;
}
static int F_27 ( struct V_1 * V_2 , int V_55 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = & V_4 -> V_7 ;
if ( V_56 )
log ( L_3 , V_55 , V_6 -> V_48 ) ;
switch ( V_55 ) {
case V_57 :
case V_58 :
if ( V_6 -> V_48 == V_49 )
return 0 ;
V_6 -> V_40 = V_6 -> V_45 = 0 ;
V_6 -> V_48 = V_49 ;
if ( F_28 ( V_4 ) )
return 0 ;
F_25 ( V_4 ) ;
return 0 ;
case V_59 :
V_6 -> V_48 = V_60 ;
return 0 ;
case V_61 :
V_6 -> V_48 = V_62 ;
return 0 ;
default:
return - V_63 ;
}
}
static T_1
F_29 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = & V_4 -> V_7 ;
return V_6 -> V_40 ;
}
static struct V_64 * F_30 ( struct V_1 * V_65 ,
unsigned long V_66 )
{
void * V_67 = V_65 -> V_9 -> V_24 + V_66 ;
return F_31 ( V_67 ) ;
}
int F_32 ( struct V_3 * V_4 )
{
F_16 ( V_4 ) ;
F_13 ( V_4 ) ;
return 0 ;
}
int F_33 ( struct V_3 * V_4 )
{
F_16 ( V_4 ) ;
F_25 ( V_4 ) ;
return 0 ;
}
int F_34 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = & V_4 -> V_7 ;
struct V_68 * V_69 ;
struct V_70 * V_71 ;
int V_47 ;
V_47 = F_35 ( & V_4 -> V_18 -> V_72 , - 1 , L_4 ,
V_73 , 0 , & V_69 ) ;
if ( V_47 != 0 )
return V_47 ;
V_47 = F_36 ( V_69 , L_5 , 0 , 0 , 1 , & V_71 ) ;
if ( V_47 < 0 ) {
F_37 ( V_69 ) ;
return V_47 ;
}
F_38 ( V_71 , V_74 , & V_75 ) ;
V_71 -> V_76 = 0 ;
V_71 -> V_14 = V_4 ;
strcpy ( V_71 -> V_77 , L_6 ) ;
strcpy ( V_69 -> V_78 , L_7 ) ;
strcpy ( V_69 -> V_79 , L_8 ) ;
strcpy ( V_69 -> V_80 , L_9 ) ;
if ( F_39 ( V_69 ) ) {
F_37 ( V_69 ) ;
return - V_26 ;
}
V_6 -> V_69 = V_69 ;
return 0 ;
}
int F_40 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = & V_4 -> V_7 ;
if ( V_6 -> V_69 )
F_37 ( V_6 -> V_69 ) ;
return 0 ;
}
