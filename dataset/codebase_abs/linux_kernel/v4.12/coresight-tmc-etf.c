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
if ( V_2 -> V_21 == V_22 )
F_7 ( V_2 ) ;
F_11 ( V_2 ) ;
F_6 ( V_2 -> V_3 ) ;
}
static void F_12 ( struct V_1 * V_2 )
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
static void F_13 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 ) ;
F_10 ( V_2 ) ;
F_11 ( V_2 ) ;
F_6 ( V_2 -> V_3 ) ;
}
static int F_14 ( struct V_25 * V_26 )
{
int V_27 = 0 ;
bool V_28 = false ;
char * V_17 = NULL ;
unsigned long V_29 ;
struct V_1 * V_2 = F_15 ( V_26 -> V_30 . V_31 ) ;
F_16 ( & V_2 -> V_32 , V_29 ) ;
if ( ! V_2 -> V_17 ) {
F_17 ( & V_2 -> V_32 , V_29 ) ;
V_17 = F_18 ( V_2 -> V_33 , V_34 ) ;
if ( ! V_17 )
return - V_35 ;
F_16 ( & V_2 -> V_32 , V_29 ) ;
}
if ( V_2 -> V_36 ) {
V_27 = - V_37 ;
goto V_38;
}
if ( V_2 -> V_21 == V_22 )
goto V_38;
if ( V_2 -> V_17 ) {
memset ( V_2 -> V_17 , 0 , V_2 -> V_33 ) ;
} else {
V_28 = true ;
V_2 -> V_17 = V_17 ;
}
V_2 -> V_21 = V_22 ;
F_1 ( V_2 ) ;
V_38:
F_17 ( & V_2 -> V_32 , V_29 ) ;
if ( ! V_28 )
F_19 ( V_17 ) ;
if ( ! V_27 )
F_20 ( V_2 -> V_30 , L_1 ) ;
return V_27 ;
}
static int F_21 ( struct V_25 * V_26 )
{
int V_27 = 0 ;
unsigned long V_29 ;
struct V_1 * V_2 = F_15 ( V_26 -> V_30 . V_31 ) ;
F_16 ( & V_2 -> V_32 , V_29 ) ;
if ( V_2 -> V_36 ) {
V_27 = - V_39 ;
goto V_38;
}
if ( V_2 -> V_21 != V_40 ) {
V_27 = - V_39 ;
goto V_38;
}
V_2 -> V_21 = V_41 ;
F_1 ( V_2 ) ;
V_38:
F_17 ( & V_2 -> V_32 , V_29 ) ;
return V_27 ;
}
static int F_22 ( struct V_25 * V_26 , T_1 V_21 )
{
switch ( V_21 ) {
case V_22 :
return F_14 ( V_26 ) ;
case V_41 :
return F_21 ( V_26 ) ;
}
return - V_39 ;
}
static void F_23 ( struct V_25 * V_26 )
{
unsigned long V_29 ;
struct V_1 * V_2 = F_15 ( V_26 -> V_30 . V_31 ) ;
F_16 ( & V_2 -> V_32 , V_29 ) ;
if ( V_2 -> V_36 ) {
F_17 ( & V_2 -> V_32 , V_29 ) ;
return;
}
if ( V_2 -> V_21 != V_40 ) {
F_9 ( V_2 ) ;
V_2 -> V_21 = V_40 ;
}
F_17 ( & V_2 -> V_32 , V_29 ) ;
F_20 ( V_2 -> V_30 , L_2 ) ;
}
static int F_24 ( struct V_25 * V_26 ,
int V_42 , int V_43 )
{
unsigned long V_29 ;
struct V_1 * V_2 = F_15 ( V_26 -> V_30 . V_31 ) ;
F_16 ( & V_2 -> V_32 , V_29 ) ;
if ( V_2 -> V_36 ) {
F_17 ( & V_2 -> V_32 , V_29 ) ;
return - V_37 ;
}
F_12 ( V_2 ) ;
V_2 -> V_21 = V_22 ;
F_17 ( & V_2 -> V_32 , V_29 ) ;
F_20 ( V_2 -> V_30 , L_3 ) ;
return 0 ;
}
static void F_25 ( struct V_25 * V_26 ,
int V_42 , int V_43 )
{
unsigned long V_29 ;
struct V_1 * V_2 = F_15 ( V_26 -> V_30 . V_31 ) ;
F_16 ( & V_2 -> V_32 , V_29 ) ;
if ( V_2 -> V_36 ) {
F_17 ( & V_2 -> V_32 , V_29 ) ;
return;
}
F_13 ( V_2 ) ;
V_2 -> V_21 = V_40 ;
F_17 ( & V_2 -> V_32 , V_29 ) ;
F_20 ( V_2 -> V_30 , L_4 ) ;
}
static void * F_26 ( struct V_25 * V_26 , int V_44 ,
void * * V_45 , int V_46 , bool V_47 )
{
int V_48 ;
struct V_49 * V_17 ;
if ( V_44 == - 1 )
V_44 = F_27 () ;
V_48 = F_28 ( V_44 ) ;
V_17 = F_29 ( sizeof( struct V_49 ) , V_34 , V_48 ) ;
if ( ! V_17 )
return NULL ;
V_17 -> V_50 = V_47 ;
V_17 -> V_46 = V_46 ;
V_17 -> V_51 = V_45 ;
return V_17 ;
}
static void F_30 ( void * V_52 )
{
struct V_49 * V_17 = V_52 ;
F_19 ( V_17 ) ;
}
static int F_31 ( struct V_25 * V_26 ,
struct V_53 * V_54 ,
void * V_55 )
{
int V_27 = 0 ;
unsigned long V_56 ;
struct V_49 * V_17 = V_55 ;
V_56 = V_54 -> V_56 & ( ( V_17 -> V_46 << V_57 ) - 1 ) ;
V_17 -> V_58 = V_56 / V_59 ;
V_17 -> V_60 = V_56 % V_59 ;
F_32 ( & V_17 -> V_61 , 0 ) ;
return V_27 ;
}
static unsigned long F_33 ( struct V_25 * V_26 ,
struct V_53 * V_54 ,
void * V_55 )
{
long V_33 = 0 ;
struct V_49 * V_17 = V_55 ;
if ( V_17 ) {
if ( V_17 -> V_50 )
V_54 -> V_56 = F_34 ( & V_17 -> V_61 ,
V_17 -> V_46 << V_57 ) ;
V_33 = F_34 ( & V_17 -> V_61 , 0 ) ;
}
return V_33 ;
}
static void F_35 ( struct V_25 * V_26 ,
struct V_53 * V_54 ,
void * V_55 )
{
int V_16 , V_58 ;
T_1 * V_62 ;
T_1 V_63 , V_64 ;
T_1 V_65 , V_66 ;
unsigned long V_60 ;
struct V_49 * V_17 = V_55 ;
struct V_1 * V_2 = F_15 ( V_26 -> V_30 . V_31 ) ;
if ( ! V_17 )
return;
if ( F_36 ( V_2 -> V_21 != V_41 ) )
return;
F_2 ( V_2 -> V_3 ) ;
F_10 ( V_2 ) ;
V_63 = F_8 ( V_2 -> V_3 + V_67 ) ;
V_64 = F_8 ( V_2 -> V_3 + V_68 ) ;
V_65 = F_8 ( V_2 -> V_3 + V_69 ) ;
if ( V_65 & V_70 ) {
F_37 ( V_54 , V_71 ) ;
V_66 = V_2 -> V_33 ;
} else {
V_66 = F_38 ( V_64 , V_63 , V_2 -> V_33 ) ;
}
if ( V_66 > V_54 -> V_33 ) {
T_1 V_72 = 0 ;
switch ( V_2 -> V_19 ) {
case V_73 :
case V_74 :
case V_75 :
V_72 = F_39 ( 31 , 5 ) ;
break;
case V_76 :
V_72 = F_39 ( 31 , 6 ) ;
break;
}
V_66 = V_54 -> V_33 & V_72 ;
V_63 = ( V_64 + V_2 -> V_33 ) - V_66 ;
if ( V_63 > ( V_2 -> V_33 - 1 ) )
V_63 -= V_2 -> V_33 ;
F_4 ( V_63 , V_2 -> V_3 + V_67 ) ;
F_37 ( V_54 , V_71 ) ;
}
V_58 = V_17 -> V_58 ;
V_60 = V_17 -> V_60 ;
for ( V_16 = 0 ; V_16 < V_66 ; V_16 += 4 ) {
V_62 = V_17 -> V_51 [ V_58 ] + V_60 ;
* V_62 = F_8 ( V_2 -> V_3 + V_20 ) ;
V_60 += 4 ;
if ( V_60 >= V_59 ) {
V_60 = 0 ;
V_58 ++ ;
V_58 &= V_17 -> V_46 - 1 ;
}
}
if ( V_17 -> V_50 )
F_32 ( & V_17 -> V_61 , ( V_58 * V_59 ) + V_60 ) ;
else
F_40 ( V_66 , & V_17 -> V_61 ) ;
F_6 ( V_2 -> V_3 ) ;
}
int F_41 ( struct V_1 * V_2 )
{
enum V_77 V_21 ;
int V_27 = 0 ;
unsigned long V_29 ;
if ( F_36 ( V_2 -> V_78 != V_79 &&
V_2 -> V_78 != V_80 ) )
return - V_39 ;
F_16 ( & V_2 -> V_32 , V_29 ) ;
if ( V_2 -> V_36 ) {
V_27 = - V_37 ;
goto V_38;
}
V_21 = F_8 ( V_2 -> V_3 + V_5 ) ;
if ( V_21 != V_4 ) {
V_27 = - V_39 ;
goto V_38;
}
if ( V_2 -> V_21 == V_41 ) {
V_27 = - V_39 ;
goto V_38;
}
if ( V_2 -> V_17 == NULL ) {
V_27 = - V_39 ;
goto V_38;
}
if ( V_2 -> V_21 == V_22 )
F_9 ( V_2 ) ;
V_2 -> V_36 = true ;
V_38:
F_17 ( & V_2 -> V_32 , V_29 ) ;
return V_27 ;
}
int F_42 ( struct V_1 * V_2 )
{
char * V_17 = NULL ;
enum V_77 V_21 ;
unsigned long V_29 ;
if ( F_36 ( V_2 -> V_78 != V_79 &&
V_2 -> V_78 != V_80 ) )
return - V_39 ;
F_16 ( & V_2 -> V_32 , V_29 ) ;
V_21 = F_8 ( V_2 -> V_3 + V_5 ) ;
if ( V_21 != V_4 ) {
F_17 ( & V_2 -> V_32 , V_29 ) ;
return - V_39 ;
}
if ( V_2 -> V_21 == V_22 ) {
memset ( V_2 -> V_17 , 0 , V_2 -> V_33 ) ;
F_1 ( V_2 ) ;
} else {
V_17 = V_2 -> V_17 ;
V_2 -> V_17 = NULL ;
}
V_2 -> V_36 = false ;
F_17 ( & V_2 -> V_32 , V_29 ) ;
F_19 ( V_17 ) ;
return 0 ;
}
