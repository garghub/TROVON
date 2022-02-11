static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 ) ;
F_3 ( V_2 ) ;
F_4 ( V_4 , V_2 -> V_3 + V_5 ) ;
F_4 ( V_6 | V_7 |
V_8 | V_9 |
V_10 ,
V_2 -> V_3 + V_11 ) ;
F_4 ( V_2 -> V_12 , V_2 -> V_3 + V_13 ) ;
F_5 ( V_2 ) ;
F_6 ( V_2 -> V_3 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
bool V_14 = false ;
char * V_15 ;
const T_1 * V_16 ;
T_1 V_17 , V_18 ;
int V_19 ;
V_18 = F_8 ( V_2 -> V_3 + V_20 ) ;
if ( V_18 & V_21 )
V_14 = true ;
V_15 = V_2 -> V_22 ;
V_2 -> V_23 = 0 ;
V_16 = V_24 ;
while ( 1 ) {
for ( V_19 = 0 ; V_19 < V_2 -> V_25 ; V_19 ++ ) {
V_17 = F_8 ( V_2 -> V_3 + V_26 ) ;
if ( V_17 == 0xFFFFFFFF )
return;
if ( V_14 && * V_16 ) {
V_17 = * V_16 ;
V_16 ++ ;
}
memcpy ( V_15 , & V_17 , 4 ) ;
V_15 += 4 ;
V_2 -> V_23 += 4 ;
}
}
}
static void F_9 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 ) ;
F_10 ( V_2 ) ;
if ( V_2 -> V_27 == V_28 )
F_7 ( V_2 ) ;
F_11 ( V_2 ) ;
F_6 ( V_2 -> V_3 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 ) ;
F_3 ( V_2 ) ;
F_4 ( V_29 , V_2 -> V_3 + V_5 ) ;
F_4 ( V_6 | V_7 ,
V_2 -> V_3 + V_11 ) ;
F_4 ( 0x0 , V_2 -> V_3 + V_30 ) ;
F_5 ( V_2 ) ;
F_6 ( V_2 -> V_3 ) ;
}
static void F_13 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 ) ;
F_10 ( V_2 ) ;
F_11 ( V_2 ) ;
F_6 ( V_2 -> V_3 ) ;
}
static int F_14 ( struct V_31 * V_32 )
{
int V_33 = 0 ;
bool V_34 = false ;
char * V_22 = NULL ;
unsigned long V_35 ;
struct V_1 * V_2 = F_15 ( V_32 -> V_36 . V_37 ) ;
F_16 ( & V_2 -> V_38 , V_35 ) ;
if ( ! V_2 -> V_22 ) {
F_17 ( & V_2 -> V_38 , V_35 ) ;
V_22 = F_18 ( V_2 -> V_39 , V_40 ) ;
if ( ! V_22 )
return - V_41 ;
F_16 ( & V_2 -> V_38 , V_35 ) ;
}
if ( V_2 -> V_42 ) {
V_33 = - V_43 ;
goto V_44;
}
if ( V_2 -> V_27 == V_28 )
goto V_44;
if ( V_2 -> V_22 ) {
memset ( V_2 -> V_22 , 0 , V_2 -> V_39 ) ;
} else {
V_34 = true ;
V_2 -> V_22 = V_22 ;
}
V_2 -> V_27 = V_28 ;
F_1 ( V_2 ) ;
V_44:
F_17 ( & V_2 -> V_38 , V_35 ) ;
if ( ! V_34 )
F_19 ( V_22 ) ;
return V_33 ;
}
static int F_20 ( struct V_31 * V_32 )
{
int V_33 = 0 ;
unsigned long V_35 ;
struct V_1 * V_2 = F_15 ( V_32 -> V_36 . V_37 ) ;
F_16 ( & V_2 -> V_38 , V_35 ) ;
if ( V_2 -> V_42 ) {
V_33 = - V_45 ;
goto V_44;
}
if ( V_2 -> V_27 != V_46 ) {
V_33 = - V_45 ;
goto V_44;
}
V_2 -> V_27 = V_47 ;
F_1 ( V_2 ) ;
V_44:
F_17 ( & V_2 -> V_38 , V_35 ) ;
return V_33 ;
}
static int F_21 ( struct V_31 * V_32 , T_1 V_27 )
{
int V_33 ;
struct V_1 * V_2 = F_15 ( V_32 -> V_36 . V_37 ) ;
switch ( V_27 ) {
case V_28 :
V_33 = F_14 ( V_32 ) ;
break;
case V_47 :
V_33 = F_20 ( V_32 ) ;
break;
default:
V_33 = - V_45 ;
break;
}
if ( V_33 )
return V_33 ;
F_22 ( V_2 -> V_36 , L_1 ) ;
return 0 ;
}
static void F_23 ( struct V_31 * V_32 )
{
unsigned long V_35 ;
struct V_1 * V_2 = F_15 ( V_32 -> V_36 . V_37 ) ;
F_16 ( & V_2 -> V_38 , V_35 ) ;
if ( V_2 -> V_42 ) {
F_17 ( & V_2 -> V_38 , V_35 ) ;
return;
}
if ( V_2 -> V_27 != V_46 ) {
F_9 ( V_2 ) ;
V_2 -> V_27 = V_46 ;
}
F_17 ( & V_2 -> V_38 , V_35 ) ;
F_22 ( V_2 -> V_36 , L_2 ) ;
}
static int F_24 ( struct V_31 * V_32 ,
int V_48 , int V_49 )
{
unsigned long V_35 ;
struct V_1 * V_2 = F_15 ( V_32 -> V_36 . V_37 ) ;
F_16 ( & V_2 -> V_38 , V_35 ) ;
if ( V_2 -> V_42 ) {
F_17 ( & V_2 -> V_38 , V_35 ) ;
return - V_43 ;
}
F_12 ( V_2 ) ;
V_2 -> V_27 = V_28 ;
F_17 ( & V_2 -> V_38 , V_35 ) ;
F_22 ( V_2 -> V_36 , L_3 ) ;
return 0 ;
}
static void F_25 ( struct V_31 * V_32 ,
int V_48 , int V_49 )
{
unsigned long V_35 ;
struct V_1 * V_2 = F_15 ( V_32 -> V_36 . V_37 ) ;
F_16 ( & V_2 -> V_38 , V_35 ) ;
if ( V_2 -> V_42 ) {
F_17 ( & V_2 -> V_38 , V_35 ) ;
return;
}
F_13 ( V_2 ) ;
V_2 -> V_27 = V_46 ;
F_17 ( & V_2 -> V_38 , V_35 ) ;
F_22 ( V_2 -> V_36 , L_4 ) ;
}
static void * F_26 ( struct V_31 * V_32 , int V_50 ,
void * * V_51 , int V_52 , bool V_53 )
{
int V_54 ;
struct V_55 * V_22 ;
if ( V_50 == - 1 )
V_50 = F_27 () ;
V_54 = F_28 ( V_50 ) ;
V_22 = F_29 ( sizeof( struct V_55 ) , V_40 , V_54 ) ;
if ( ! V_22 )
return NULL ;
V_22 -> V_56 = V_53 ;
V_22 -> V_52 = V_52 ;
V_22 -> V_57 = V_51 ;
return V_22 ;
}
static void F_30 ( void * V_58 )
{
struct V_55 * V_22 = V_58 ;
F_19 ( V_22 ) ;
}
static int F_31 ( struct V_31 * V_32 ,
struct V_59 * V_60 ,
void * V_61 )
{
int V_33 = 0 ;
unsigned long V_62 ;
struct V_55 * V_22 = V_61 ;
V_62 = V_60 -> V_62 & ( ( V_22 -> V_52 << V_63 ) - 1 ) ;
V_22 -> V_64 = V_62 / V_65 ;
V_22 -> V_66 = V_62 % V_65 ;
F_32 ( & V_22 -> V_67 , 0 ) ;
return V_33 ;
}
static unsigned long F_33 ( struct V_31 * V_32 ,
struct V_59 * V_60 ,
void * V_61 )
{
long V_39 = 0 ;
struct V_55 * V_22 = V_61 ;
if ( V_22 ) {
if ( V_22 -> V_56 )
V_60 -> V_62 = F_34 ( & V_22 -> V_67 ,
V_22 -> V_52 << V_63 ) ;
V_39 = F_34 ( & V_22 -> V_67 , 0 ) ;
}
return V_39 ;
}
static void F_35 ( struct V_31 * V_32 ,
struct V_59 * V_60 ,
void * V_61 )
{
bool V_14 = false ;
int V_19 , V_64 ;
const T_1 * V_16 ;
T_1 * V_68 ;
T_2 V_69 , V_70 ;
T_1 V_18 , V_71 ;
unsigned long V_66 ;
struct V_55 * V_22 = V_61 ;
struct V_1 * V_2 = F_15 ( V_32 -> V_36 . V_37 ) ;
if ( ! V_22 )
return;
if ( F_36 ( V_2 -> V_27 != V_47 ) )
return;
F_2 ( V_2 -> V_3 ) ;
F_10 ( V_2 ) ;
V_69 = F_37 ( V_2 ) ;
V_70 = F_38 ( V_2 ) ;
V_18 = F_8 ( V_2 -> V_3 + V_20 ) ;
if ( V_18 & V_21 ) {
V_14 = true ;
V_71 = V_2 -> V_39 ;
} else {
V_71 = F_39 ( V_70 , V_69 , V_2 -> V_39 ) ;
}
if ( V_71 > V_60 -> V_39 ) {
T_1 V_72 = 0 ;
switch ( V_2 -> V_25 ) {
case V_73 :
case V_74 :
case V_75 :
V_72 = F_40 ( 31 , 5 ) ;
break;
case V_76 :
V_72 = F_40 ( 31 , 6 ) ;
break;
}
V_71 = V_60 -> V_39 & V_72 ;
V_69 = ( V_70 + V_2 -> V_39 ) - V_71 ;
if ( V_69 > ( V_2 -> V_39 - 1 ) )
V_69 -= V_2 -> V_39 ;
F_41 ( V_2 , V_69 ) ;
V_14 = true ;
}
if ( V_14 )
F_42 ( V_60 , V_77 ) ;
V_64 = V_22 -> V_64 ;
V_66 = V_22 -> V_66 ;
V_16 = V_24 ;
for ( V_19 = 0 ; V_19 < V_71 ; V_19 += 4 ) {
V_68 = V_22 -> V_57 [ V_64 ] + V_66 ;
* V_68 = F_8 ( V_2 -> V_3 + V_26 ) ;
if ( V_14 && * V_16 ) {
* V_68 = * V_16 ;
V_16 ++ ;
}
V_66 += 4 ;
if ( V_66 >= V_65 ) {
V_66 = 0 ;
V_64 ++ ;
V_64 &= V_22 -> V_52 - 1 ;
}
}
if ( V_22 -> V_56 )
F_32 ( & V_22 -> V_67 , ( V_64 * V_65 ) + V_66 ) ;
else
F_43 ( V_71 , & V_22 -> V_67 ) ;
F_6 ( V_2 -> V_3 ) ;
}
int F_44 ( struct V_1 * V_2 )
{
enum V_78 V_27 ;
int V_33 = 0 ;
unsigned long V_35 ;
if ( F_36 ( V_2 -> V_79 != V_80 &&
V_2 -> V_79 != V_81 ) )
return - V_45 ;
F_16 ( & V_2 -> V_38 , V_35 ) ;
if ( V_2 -> V_42 ) {
V_33 = - V_43 ;
goto V_44;
}
V_27 = F_8 ( V_2 -> V_3 + V_5 ) ;
if ( V_27 != V_4 ) {
V_33 = - V_45 ;
goto V_44;
}
if ( V_2 -> V_27 == V_47 ) {
V_33 = - V_45 ;
goto V_44;
}
if ( V_2 -> V_22 == NULL ) {
V_33 = - V_45 ;
goto V_44;
}
if ( V_2 -> V_27 == V_28 )
F_9 ( V_2 ) ;
V_2 -> V_42 = true ;
V_44:
F_17 ( & V_2 -> V_38 , V_35 ) ;
return V_33 ;
}
int F_45 ( struct V_1 * V_2 )
{
char * V_22 = NULL ;
enum V_78 V_27 ;
unsigned long V_35 ;
if ( F_36 ( V_2 -> V_79 != V_80 &&
V_2 -> V_79 != V_81 ) )
return - V_45 ;
F_16 ( & V_2 -> V_38 , V_35 ) ;
V_27 = F_8 ( V_2 -> V_3 + V_5 ) ;
if ( V_27 != V_4 ) {
F_17 ( & V_2 -> V_38 , V_35 ) ;
return - V_45 ;
}
if ( V_2 -> V_27 == V_28 ) {
memset ( V_2 -> V_22 , 0 , V_2 -> V_39 ) ;
F_1 ( V_2 ) ;
} else {
V_22 = V_2 -> V_22 ;
V_2 -> V_22 = NULL ;
}
V_2 -> V_42 = false ;
F_17 ( & V_2 -> V_38 , V_35 ) ;
F_19 ( V_22 ) ;
return 0 ;
}
