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
char * V_14 ;
T_1 V_15 ;
int V_16 ;
V_14 = V_2 -> V_17 ;
V_2 -> V_18 = 0 ;
while ( 1 ) {
for ( V_16 = 0 ; V_16 < V_2 -> V_19 ; V_16 ++ ) {
V_15 = F_8 ( V_2 -> V_3 + V_20 ) ;
if ( V_15 == 0xFFFFFFFF )
return;
memcpy ( V_14 , & V_15 , 4 ) ;
V_14 += 4 ;
V_2 -> V_18 += 4 ;
}
}
}
static void F_9 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 ) ;
F_10 ( V_2 ) ;
if ( F_11 ( & V_2 -> V_21 ) == V_22 )
F_7 ( V_2 ) ;
F_12 ( V_2 ) ;
F_6 ( V_2 -> V_3 ) ;
}
static void F_13 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 ) ;
F_3 ( V_2 ) ;
F_4 ( V_23 , V_2 -> V_3 + V_5 ) ;
F_4 ( V_6 | V_7 ,
V_2 -> V_3 + V_11 ) ;
F_4 ( 0x0 , V_2 -> V_3 + V_24 ) ;
F_5 ( V_2 ) ;
F_6 ( V_2 -> V_3 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 ) ;
F_10 ( V_2 ) ;
F_12 ( V_2 ) ;
F_6 ( V_2 -> V_3 ) ;
}
static int F_15 ( struct V_25 * V_26 , T_1 V_21 )
{
int V_27 = 0 ;
bool V_28 = false ;
char * V_17 = NULL ;
long V_29 ;
unsigned long V_30 ;
struct V_1 * V_2 = F_16 ( V_26 -> V_31 . V_32 ) ;
if ( F_17 ( V_21 != V_22 ) )
return - V_33 ;
F_18 ( & V_2 -> V_34 , V_30 ) ;
if ( ! V_2 -> V_17 ) {
F_19 ( & V_2 -> V_34 , V_30 ) ;
V_17 = F_20 ( V_2 -> V_35 , V_36 ) ;
if ( ! V_17 )
return - V_37 ;
F_18 ( & V_2 -> V_34 , V_30 ) ;
}
if ( V_2 -> V_38 ) {
V_27 = - V_39 ;
goto V_40;
}
V_29 = F_21 ( & V_2 -> V_21 , V_21 ) ;
if ( V_29 == V_22 )
goto V_40;
if ( V_2 -> V_17 ) {
memset ( V_2 -> V_17 , 0 , V_2 -> V_35 ) ;
} else {
V_28 = true ;
V_2 -> V_17 = V_17 ;
}
F_1 ( V_2 ) ;
V_40:
F_19 ( & V_2 -> V_34 , V_30 ) ;
if ( ! V_28 )
F_22 ( V_17 ) ;
if ( ! V_27 )
F_23 ( V_2 -> V_31 , L_1 ) ;
return V_27 ;
}
static int F_24 ( struct V_25 * V_26 , T_1 V_21 )
{
int V_27 = 0 ;
long V_29 ;
unsigned long V_30 ;
struct V_1 * V_2 = F_16 ( V_26 -> V_31 . V_32 ) ;
if ( F_17 ( V_21 != V_41 ) )
return - V_33 ;
F_18 ( & V_2 -> V_34 , V_30 ) ;
if ( V_2 -> V_38 ) {
V_27 = - V_33 ;
goto V_40;
}
V_29 = F_21 ( & V_2 -> V_21 , V_21 ) ;
if ( V_29 != V_42 ) {
V_27 = - V_33 ;
goto V_40;
}
F_1 ( V_2 ) ;
V_40:
F_19 ( & V_2 -> V_34 , V_30 ) ;
return V_27 ;
}
static int F_25 ( struct V_25 * V_26 , T_1 V_21 )
{
switch ( V_21 ) {
case V_22 :
return F_15 ( V_26 , V_21 ) ;
case V_41 :
return F_24 ( V_26 , V_21 ) ;
}
return - V_33 ;
}
static void F_26 ( struct V_25 * V_26 )
{
long V_29 ;
unsigned long V_30 ;
struct V_1 * V_2 = F_16 ( V_26 -> V_31 . V_32 ) ;
F_18 ( & V_2 -> V_34 , V_30 ) ;
if ( V_2 -> V_38 ) {
F_19 ( & V_2 -> V_34 , V_30 ) ;
return;
}
V_29 = F_21 ( & V_2 -> V_21 , V_42 ) ;
if ( V_29 != V_42 )
F_9 ( V_2 ) ;
F_19 ( & V_2 -> V_34 , V_30 ) ;
F_23 ( V_2 -> V_31 , L_2 ) ;
}
static int F_27 ( struct V_25 * V_26 ,
int V_43 , int V_44 )
{
unsigned long V_30 ;
struct V_1 * V_2 = F_16 ( V_26 -> V_31 . V_32 ) ;
F_18 ( & V_2 -> V_34 , V_30 ) ;
if ( V_2 -> V_38 ) {
F_19 ( & V_2 -> V_34 , V_30 ) ;
return - V_39 ;
}
F_13 ( V_2 ) ;
F_28 ( & V_2 -> V_21 , V_22 ) ;
F_19 ( & V_2 -> V_34 , V_30 ) ;
F_23 ( V_2 -> V_31 , L_3 ) ;
return 0 ;
}
static void F_29 ( struct V_25 * V_26 ,
int V_43 , int V_44 )
{
unsigned long V_30 ;
struct V_1 * V_2 = F_16 ( V_26 -> V_31 . V_32 ) ;
F_18 ( & V_2 -> V_34 , V_30 ) ;
if ( V_2 -> V_38 ) {
F_19 ( & V_2 -> V_34 , V_30 ) ;
return;
}
F_14 ( V_2 ) ;
F_28 ( & V_2 -> V_21 , V_42 ) ;
F_19 ( & V_2 -> V_34 , V_30 ) ;
F_23 ( V_2 -> V_31 , L_4 ) ;
}
static void * F_30 ( struct V_25 * V_26 , int V_45 ,
void * * V_46 , int V_47 , bool V_48 )
{
int V_49 ;
struct V_50 * V_17 ;
if ( V_45 == - 1 )
V_45 = F_31 () ;
V_49 = F_32 ( V_45 ) ;
V_17 = F_33 ( sizeof( struct V_50 ) , V_36 , V_49 ) ;
if ( ! V_17 )
return NULL ;
V_17 -> V_51 = V_48 ;
V_17 -> V_47 = V_47 ;
V_17 -> V_52 = V_46 ;
return V_17 ;
}
static void F_34 ( void * V_53 )
{
struct V_50 * V_17 = V_53 ;
F_22 ( V_17 ) ;
}
static int F_35 ( struct V_25 * V_26 ,
struct V_54 * V_55 ,
void * V_56 )
{
int V_27 = 0 ;
unsigned long V_57 ;
struct V_50 * V_17 = V_56 ;
V_57 = V_55 -> V_57 & ( ( V_17 -> V_47 << V_58 ) - 1 ) ;
V_17 -> V_59 = V_57 / V_60 ;
V_17 -> V_61 = V_57 % V_60 ;
F_28 ( & V_17 -> V_62 , 0 ) ;
return V_27 ;
}
static unsigned long F_36 ( struct V_25 * V_26 ,
struct V_54 * V_55 ,
void * V_56 , bool * V_63 )
{
long V_35 = 0 ;
struct V_50 * V_17 = V_56 ;
if ( V_17 ) {
if ( V_17 -> V_51 )
V_55 -> V_57 = F_21 ( & V_17 -> V_62 ,
V_17 -> V_47 << V_58 ) ;
* V_63 = ! ! F_21 ( & V_17 -> V_63 , 0 ) ;
V_35 = F_21 ( & V_17 -> V_62 , 0 ) ;
}
return V_35 ;
}
static void F_37 ( struct V_25 * V_26 ,
struct V_54 * V_55 ,
void * V_56 )
{
int V_16 , V_59 ;
T_1 * V_64 ;
T_1 V_65 , V_66 ;
T_1 V_67 , V_68 ;
unsigned long V_61 ;
struct V_50 * V_17 = V_56 ;
struct V_1 * V_2 = F_16 ( V_26 -> V_31 . V_32 ) ;
if ( ! V_17 )
return;
if ( F_38 ( F_11 ( & V_2 -> V_21 ) != V_41 ) )
return;
F_2 ( V_2 -> V_3 ) ;
F_10 ( V_2 ) ;
V_65 = F_8 ( V_2 -> V_3 + V_69 ) ;
V_66 = F_8 ( V_2 -> V_3 + V_70 ) ;
V_67 = F_8 ( V_2 -> V_3 + V_71 ) ;
if ( V_67 & V_72 ) {
F_39 ( & V_17 -> V_63 ) ;
V_68 = V_2 -> V_35 ;
} else {
V_68 = F_40 ( V_66 , V_65 , V_2 -> V_35 ) ;
}
if ( V_68 > V_55 -> V_35 ) {
T_1 V_73 = 0 ;
switch ( V_2 -> V_19 ) {
case V_74 :
case V_75 :
case V_76 :
V_73 = F_41 ( 31 , 5 ) ;
break;
case V_77 :
V_73 = F_41 ( 31 , 6 ) ;
break;
}
V_68 = V_55 -> V_35 & V_73 ;
V_65 = ( V_66 + V_2 -> V_35 ) - V_68 ;
if ( V_65 > ( V_2 -> V_35 - 1 ) )
V_65 -= V_2 -> V_35 ;
F_4 ( V_65 , V_2 -> V_3 + V_69 ) ;
F_39 ( & V_17 -> V_63 ) ;
}
V_59 = V_17 -> V_59 ;
V_61 = V_17 -> V_61 ;
for ( V_16 = 0 ; V_16 < V_68 ; V_16 += 4 ) {
V_64 = V_17 -> V_52 [ V_59 ] + V_61 ;
* V_64 = F_8 ( V_2 -> V_3 + V_20 ) ;
V_61 += 4 ;
if ( V_61 >= V_60 ) {
V_61 = 0 ;
V_59 ++ ;
V_59 &= V_17 -> V_47 - 1 ;
}
}
if ( V_17 -> V_51 )
F_28 ( & V_17 -> V_62 , ( V_59 * V_60 ) + V_61 ) ;
else
F_42 ( V_68 , & V_17 -> V_62 ) ;
F_6 ( V_2 -> V_3 ) ;
}
int F_43 ( struct V_1 * V_2 )
{
long V_29 ;
enum V_78 V_21 ;
int V_27 = 0 ;
unsigned long V_30 ;
if ( F_38 ( V_2 -> V_79 != V_80 &&
V_2 -> V_79 != V_81 ) )
return - V_33 ;
F_18 ( & V_2 -> V_34 , V_30 ) ;
if ( V_2 -> V_38 ) {
V_27 = - V_39 ;
goto V_40;
}
V_21 = F_8 ( V_2 -> V_3 + V_5 ) ;
if ( V_21 != V_4 ) {
V_27 = - V_33 ;
goto V_40;
}
V_29 = F_11 ( & V_2 -> V_21 ) ;
if ( V_29 == V_41 ) {
V_27 = - V_33 ;
goto V_40;
}
if ( V_2 -> V_17 == NULL ) {
V_27 = - V_33 ;
goto V_40;
}
if ( V_29 == V_22 )
F_9 ( V_2 ) ;
V_2 -> V_38 = true ;
V_40:
F_19 ( & V_2 -> V_34 , V_30 ) ;
return V_27 ;
}
int F_44 ( struct V_1 * V_2 )
{
char * V_17 = NULL ;
enum V_78 V_21 ;
unsigned long V_30 ;
if ( F_38 ( V_2 -> V_79 != V_80 &&
V_2 -> V_79 != V_81 ) )
return - V_33 ;
F_18 ( & V_2 -> V_34 , V_30 ) ;
V_21 = F_8 ( V_2 -> V_3 + V_5 ) ;
if ( V_21 != V_4 ) {
F_19 ( & V_2 -> V_34 , V_30 ) ;
return - V_33 ;
}
if ( F_11 ( & V_2 -> V_21 ) == V_22 ) {
memset ( V_2 -> V_17 , 0 , V_2 -> V_35 ) ;
F_1 ( V_2 ) ;
} else {
V_17 = V_2 -> V_17 ;
V_2 -> V_17 = NULL ;
}
V_2 -> V_38 = false ;
F_19 ( & V_2 -> V_34 , V_30 ) ;
F_22 ( V_17 ) ;
return 0 ;
}
