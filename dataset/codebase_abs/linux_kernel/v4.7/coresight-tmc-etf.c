void F_1 ( struct V_1 * V_2 )
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
while ( 1 ) {
for ( V_16 = 0 ; V_16 < V_2 -> V_18 ; V_16 ++ ) {
V_15 = F_8 ( V_2 -> V_3 + V_19 ) ;
if ( V_15 == 0xFFFFFFFF )
return;
memcpy ( V_14 , & V_15 , 4 ) ;
V_14 += 4 ;
}
}
}
static void F_9 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 ) ;
F_10 ( V_2 ) ;
if ( F_11 ( & V_2 -> V_20 ) == V_21 )
F_7 ( V_2 ) ;
F_12 ( V_2 ) ;
F_6 ( V_2 -> V_3 ) ;
}
static void F_13 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 ) ;
F_3 ( V_2 ) ;
F_4 ( V_22 , V_2 -> V_3 + V_5 ) ;
F_4 ( V_6 | V_7 ,
V_2 -> V_3 + V_11 ) ;
F_4 ( 0x0 , V_2 -> V_3 + V_23 ) ;
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
static int F_15 ( struct V_24 * V_25 , T_1 V_20 )
{
int V_26 = 0 ;
bool V_27 = false ;
char * V_17 = NULL ;
long V_28 ;
unsigned long V_29 ;
struct V_1 * V_2 = F_16 ( V_25 -> V_30 . V_31 ) ;
if ( F_17 ( V_20 != V_21 ) )
return - V_32 ;
F_18 ( & V_2 -> V_33 , V_29 ) ;
if ( ! V_2 -> V_17 ) {
F_19 ( & V_2 -> V_33 , V_29 ) ;
V_17 = F_20 ( V_2 -> V_34 , V_35 ) ;
if ( ! V_17 )
return - V_36 ;
F_18 ( & V_2 -> V_33 , V_29 ) ;
}
if ( V_2 -> V_37 ) {
V_26 = - V_38 ;
goto V_39;
}
V_28 = F_21 ( & V_2 -> V_20 , V_20 ) ;
if ( V_28 == V_21 )
goto V_39;
if ( V_2 -> V_17 ) {
memset ( V_2 -> V_17 , 0 , V_2 -> V_34 ) ;
} else {
V_27 = true ;
V_2 -> V_17 = V_17 ;
}
F_1 ( V_2 ) ;
V_39:
F_19 ( & V_2 -> V_33 , V_29 ) ;
if ( ! V_27 && V_17 )
F_22 ( V_17 ) ;
if ( ! V_26 )
F_23 ( V_2 -> V_30 , L_1 ) ;
return V_26 ;
}
static int F_24 ( struct V_24 * V_25 , T_1 V_20 )
{
int V_26 = 0 ;
long V_28 ;
unsigned long V_29 ;
struct V_1 * V_2 = F_16 ( V_25 -> V_30 . V_31 ) ;
if ( F_17 ( V_20 != V_40 ) )
return - V_32 ;
F_18 ( & V_2 -> V_33 , V_29 ) ;
if ( V_2 -> V_37 ) {
V_26 = - V_32 ;
goto V_39;
}
V_28 = F_21 ( & V_2 -> V_20 , V_20 ) ;
if ( V_28 != V_41 ) {
V_26 = - V_32 ;
goto V_39;
}
F_1 ( V_2 ) ;
V_39:
F_19 ( & V_2 -> V_33 , V_29 ) ;
return V_26 ;
}
static int F_25 ( struct V_24 * V_25 , T_1 V_20 )
{
switch ( V_20 ) {
case V_21 :
return F_15 ( V_25 , V_20 ) ;
case V_40 :
return F_24 ( V_25 , V_20 ) ;
}
return - V_32 ;
}
static void F_26 ( struct V_24 * V_25 )
{
long V_28 ;
unsigned long V_29 ;
struct V_1 * V_2 = F_16 ( V_25 -> V_30 . V_31 ) ;
F_18 ( & V_2 -> V_33 , V_29 ) ;
if ( V_2 -> V_37 ) {
F_19 ( & V_2 -> V_33 , V_29 ) ;
return;
}
V_28 = F_21 ( & V_2 -> V_20 , V_41 ) ;
if ( V_28 != V_41 )
F_9 ( V_2 ) ;
F_19 ( & V_2 -> V_33 , V_29 ) ;
F_23 ( V_2 -> V_30 , L_2 ) ;
}
static int F_27 ( struct V_24 * V_25 ,
int V_42 , int V_43 )
{
unsigned long V_29 ;
struct V_1 * V_2 = F_16 ( V_25 -> V_30 . V_31 ) ;
F_18 ( & V_2 -> V_33 , V_29 ) ;
if ( V_2 -> V_37 ) {
F_19 ( & V_2 -> V_33 , V_29 ) ;
return - V_38 ;
}
F_13 ( V_2 ) ;
F_28 ( & V_2 -> V_20 , V_21 ) ;
F_19 ( & V_2 -> V_33 , V_29 ) ;
F_23 ( V_2 -> V_30 , L_3 ) ;
return 0 ;
}
static void F_29 ( struct V_24 * V_25 ,
int V_42 , int V_43 )
{
unsigned long V_29 ;
struct V_1 * V_2 = F_16 ( V_25 -> V_30 . V_31 ) ;
F_18 ( & V_2 -> V_33 , V_29 ) ;
if ( V_2 -> V_37 ) {
F_19 ( & V_2 -> V_33 , V_29 ) ;
return;
}
F_14 ( V_2 ) ;
F_28 ( & V_2 -> V_20 , V_41 ) ;
F_19 ( & V_2 -> V_33 , V_29 ) ;
F_23 ( V_2 -> V_30 , L_4 ) ;
}
static void * F_30 ( struct V_24 * V_25 , int V_44 ,
void * * V_45 , int V_46 , bool V_47 )
{
int V_48 ;
struct V_49 * V_17 ;
if ( V_44 == - 1 )
V_44 = F_31 () ;
V_48 = F_32 ( V_44 ) ;
V_17 = F_33 ( sizeof( struct V_49 ) , V_35 , V_48 ) ;
if ( ! V_17 )
return NULL ;
V_17 -> V_50 = V_47 ;
V_17 -> V_46 = V_46 ;
V_17 -> V_51 = V_45 ;
return V_17 ;
}
static void F_34 ( void * V_52 )
{
struct V_49 * V_17 = V_52 ;
F_22 ( V_17 ) ;
}
static int F_35 ( struct V_24 * V_25 ,
struct V_53 * V_54 ,
void * V_55 )
{
int V_26 = 0 ;
unsigned long V_56 ;
struct V_49 * V_17 = V_55 ;
V_56 = V_54 -> V_56 & ( ( V_17 -> V_46 << V_57 ) - 1 ) ;
V_17 -> V_58 = V_56 / V_59 ;
V_17 -> V_60 = V_56 % V_59 ;
F_28 ( & V_17 -> V_61 , 0 ) ;
return V_26 ;
}
static unsigned long F_36 ( struct V_24 * V_25 ,
struct V_53 * V_54 ,
void * V_55 , bool * V_62 )
{
long V_34 = 0 ;
struct V_49 * V_17 = V_55 ;
if ( V_17 ) {
if ( V_17 -> V_50 )
V_54 -> V_56 = F_21 ( & V_17 -> V_61 ,
V_17 -> V_46 << V_57 ) ;
* V_62 = ! ! F_21 ( & V_17 -> V_62 , 0 ) ;
V_34 = F_21 ( & V_17 -> V_61 , 0 ) ;
}
return V_34 ;
}
static void F_37 ( struct V_24 * V_25 ,
struct V_53 * V_54 ,
void * V_55 )
{
int V_16 , V_58 ;
T_1 * V_63 ;
T_1 V_64 , V_65 ;
T_1 V_66 , V_67 ;
unsigned long V_60 ;
struct V_49 * V_17 = V_55 ;
struct V_1 * V_2 = F_16 ( V_25 -> V_30 . V_31 ) ;
if ( ! V_17 )
return;
if ( F_38 ( F_11 ( & V_2 -> V_20 ) != V_40 ) )
return;
F_2 ( V_2 -> V_3 ) ;
F_10 ( V_2 ) ;
V_64 = F_8 ( V_2 -> V_3 + V_68 ) ;
V_65 = F_8 ( V_2 -> V_3 + V_69 ) ;
V_66 = F_8 ( V_2 -> V_3 + V_70 ) ;
if ( V_66 & V_71 ) {
F_39 ( & V_17 -> V_62 ) ;
V_67 = V_2 -> V_34 ;
} else {
V_67 = F_40 ( V_65 , V_64 , V_2 -> V_34 ) ;
}
if ( V_67 > V_54 -> V_34 ) {
T_1 V_72 = 0 ;
switch ( V_2 -> V_18 ) {
case V_73 :
case V_74 :
case V_75 :
V_72 = F_41 ( 31 , 5 ) ;
break;
case V_76 :
V_72 = F_41 ( 31 , 6 ) ;
break;
}
V_67 = V_54 -> V_34 & V_72 ;
V_64 = ( V_65 + V_2 -> V_34 ) - V_67 ;
if ( V_64 > ( V_2 -> V_34 - 1 ) )
V_64 -= V_2 -> V_34 ;
F_4 ( V_64 , V_2 -> V_3 + V_68 ) ;
F_39 ( & V_17 -> V_62 ) ;
}
V_58 = V_17 -> V_58 ;
V_60 = V_17 -> V_60 ;
for ( V_16 = 0 ; V_16 < V_67 ; V_16 += 4 ) {
V_63 = V_17 -> V_51 [ V_58 ] + V_60 ;
* V_63 = F_8 ( V_2 -> V_3 + V_19 ) ;
V_60 += 4 ;
if ( V_60 >= V_59 ) {
V_60 = 0 ;
V_58 ++ ;
V_58 &= V_17 -> V_46 - 1 ;
}
}
if ( V_17 -> V_50 )
F_28 ( & V_17 -> V_61 , ( V_58 * V_59 ) + V_60 ) ;
else
F_42 ( V_67 , & V_17 -> V_61 ) ;
F_6 ( V_2 -> V_3 ) ;
}
int F_43 ( struct V_1 * V_2 )
{
long V_28 ;
enum V_77 V_20 ;
int V_26 = 0 ;
unsigned long V_29 ;
if ( F_38 ( V_2 -> V_78 != V_79 &&
V_2 -> V_78 != V_80 ) )
return - V_32 ;
F_18 ( & V_2 -> V_33 , V_29 ) ;
if ( V_2 -> V_37 ) {
V_26 = - V_38 ;
goto V_39;
}
V_20 = F_8 ( V_2 -> V_3 + V_5 ) ;
if ( V_20 != V_4 ) {
V_26 = - V_32 ;
goto V_39;
}
V_28 = F_11 ( & V_2 -> V_20 ) ;
if ( V_28 == V_40 ) {
V_26 = - V_32 ;
goto V_39;
}
if ( V_2 -> V_17 == NULL ) {
V_26 = - V_32 ;
goto V_39;
}
if ( V_28 == V_21 )
F_9 ( V_2 ) ;
V_2 -> V_37 = true ;
V_39:
F_19 ( & V_2 -> V_33 , V_29 ) ;
return V_26 ;
}
int F_44 ( struct V_1 * V_2 )
{
char * V_17 = NULL ;
enum V_77 V_20 ;
unsigned long V_29 ;
if ( F_38 ( V_2 -> V_78 != V_79 &&
V_2 -> V_78 != V_80 ) )
return - V_32 ;
F_18 ( & V_2 -> V_33 , V_29 ) ;
V_20 = F_8 ( V_2 -> V_3 + V_5 ) ;
if ( V_20 != V_4 ) {
F_19 ( & V_2 -> V_33 , V_29 ) ;
return - V_32 ;
}
if ( F_11 ( & V_2 -> V_20 ) == V_21 ) {
memset ( V_2 -> V_17 , 0 , V_2 -> V_34 ) ;
F_1 ( V_2 ) ;
} else {
V_17 = V_2 -> V_17 ;
V_2 -> V_17 = NULL ;
}
V_2 -> V_37 = false ;
F_19 ( & V_2 -> V_33 , V_29 ) ;
F_22 ( V_17 ) ;
return 0 ;
}
