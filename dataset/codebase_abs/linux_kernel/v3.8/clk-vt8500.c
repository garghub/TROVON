static void F_1 ( void )
{
while ( F_2 ( V_1 ) & V_2 )
F_3 () ;
}
static int F_4 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_5 ( V_4 ) ;
T_1 V_7 ;
unsigned long V_8 = 0 ;
F_6 ( V_6 -> V_9 , V_8 ) ;
V_7 = F_2 ( V_6 -> V_10 ) ;
V_7 |= F_7 ( V_6 -> V_11 ) ;
F_8 ( V_7 , V_6 -> V_10 ) ;
F_9 ( V_6 -> V_9 , V_8 ) ;
return 0 ;
}
static void F_10 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_5 ( V_4 ) ;
T_1 V_7 ;
unsigned long V_8 = 0 ;
F_6 ( V_6 -> V_9 , V_8 ) ;
V_7 = F_2 ( V_6 -> V_10 ) ;
V_7 &= ~ F_7 ( V_6 -> V_11 ) ;
F_8 ( V_7 , V_6 -> V_10 ) ;
F_9 ( V_6 -> V_9 , V_8 ) ;
}
static int F_11 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_5 ( V_4 ) ;
T_1 V_7 = ( F_2 ( V_6 -> V_10 ) & F_7 ( V_6 -> V_11 ) ) ;
return V_7 ? 1 : 0 ;
}
static unsigned long F_12 ( struct V_3 * V_4 ,
unsigned long V_12 )
{
struct V_5 * V_6 = F_5 ( V_4 ) ;
T_1 div = F_2 ( V_6 -> V_13 ) & V_6 -> V_14 ;
if ( ( V_6 -> V_14 == 0x3F ) && ( div & F_7 ( 5 ) ) )
div = 64 * ( div & 0x1f ) ;
if ( div == 0 )
div = ( V_6 -> V_14 + 1 ) ;
return V_12 / div ;
}
static long F_13 ( struct V_3 * V_4 , unsigned long V_15 ,
unsigned long * V_16 )
{
struct V_5 * V_6 = F_5 ( V_4 ) ;
T_1 V_17 = * V_16 / V_15 ;
if ( ( V_6 -> V_14 == 0x3F ) && ( V_17 > 31 ) ) {
V_17 = 64 * ( ( V_17 / 64 ) + 1 ) ;
}
return * V_16 / V_17 ;
}
static int F_14 ( struct V_3 * V_4 , unsigned long V_15 ,
unsigned long V_12 )
{
struct V_5 * V_6 = F_5 ( V_4 ) ;
T_1 V_17 = V_12 / V_15 ;
unsigned long V_8 = 0 ;
if ( V_17 == V_6 -> V_14 + 1 )
V_17 = 0 ;
if ( ( V_6 -> V_14 == 0x3F ) && ( V_17 > 31 ) ) {
V_17 = 0x20 + ( V_17 / 64 ) ;
}
if ( V_17 > V_6 -> V_14 ) {
F_15 ( L_1 , V_18 ) ;
return - V_19 ;
}
F_6 ( V_6 -> V_9 , V_8 ) ;
F_1 () ;
F_8 ( V_17 , V_6 -> V_13 ) ;
F_1 () ;
F_6 ( V_6 -> V_9 , V_8 ) ;
return 0 ;
}
static T_2 void F_16 ( struct V_20 * V_21 )
{
T_1 V_10 , V_13 ;
struct V_22 * V_22 ;
struct V_5 * V_23 ;
const char * V_24 = V_21 -> V_25 ;
const char * V_26 ;
struct V_27 V_28 ;
int V_29 ;
int V_30 = 0 ;
V_23 = F_17 ( sizeof( * V_23 ) , V_31 ) ;
if ( F_18 ( ! V_23 ) )
return;
V_23 -> V_9 = & V_32 ;
V_29 = F_19 ( V_21 , L_2 , & V_10 ) ;
if ( ! V_29 ) {
V_23 -> V_10 = V_1 + V_10 ;
V_29 = F_19 ( V_21 , L_3 , & V_23 -> V_11 ) ;
if ( V_29 ) {
F_15 ( L_4 ,
V_18 ) ;
return;
}
V_30 |= V_33 ;
}
V_29 = F_19 ( V_21 , L_5 , & V_13 ) ;
if ( ! V_29 ) {
V_23 -> V_13 = V_1 + V_13 ;
V_23 -> V_14 = 0x1f ;
F_19 ( V_21 , L_6 , & V_23 -> V_14 ) ;
V_30 |= V_34 ;
}
F_20 ( V_21 , L_7 , & V_24 ) ;
switch ( V_30 ) {
case V_33 :
V_28 . V_35 = & V_36 ;
break;
case V_34 :
V_28 . V_35 = & V_37 ;
break;
case V_38 :
V_28 . V_35 = & V_39 ;
break;
default:
F_15 ( L_8 ,
V_18 ) ;
F_21 ( V_23 ) ;
return;
}
V_28 . V_25 = V_24 ;
V_28 . V_8 = 0 ;
V_26 = F_22 ( V_21 , 0 ) ;
V_28 . V_40 = & V_26 ;
V_28 . V_41 = 1 ;
V_23 -> V_4 . V_28 = & V_28 ;
V_22 = F_23 ( NULL , & V_23 -> V_4 ) ;
if ( F_18 ( F_24 ( V_22 ) ) ) {
F_21 ( V_23 ) ;
return;
}
V_29 = F_25 ( V_21 , V_42 , V_22 ) ;
F_26 ( V_22 , V_24 , NULL ) ;
}
static void F_27 ( unsigned long V_15 , unsigned long V_12 ,
T_1 * V_43 , T_1 * V_44 )
{
unsigned long V_45 ;
if ( ( V_15 < V_12 * 4 ) || ( V_15 > V_12 * 62 ) ) {
F_15 ( L_9 , V_18 ) ;
* V_43 = 0 ;
* V_44 = 1 ;
return;
}
if ( V_15 <= V_12 * 31 )
* V_44 = 2 ;
else
* V_44 = 1 ;
* V_43 = V_15 / ( V_12 / * V_44 ) ;
V_45 = ( V_12 / * V_44 ) * * V_43 ;
if ( V_45 != V_15 )
F_28 ( L_10 , V_18 ,
V_15 , V_45 ) ;
}
static void F_29 ( unsigned long V_15 , unsigned long V_12 ,
T_1 * V_43 , T_1 * V_46 , T_1 * V_47 )
{
T_1 V_48 , V_49 , V_50 ;
T_1 V_51 , V_52 , V_53 ;
unsigned long V_45 , V_54 , V_55 ;
V_55 = ( unsigned long ) - 1 ;
for ( V_49 = 5 ; V_49 >= 3 ; V_49 -- )
for ( V_50 = 3 ; V_50 >= 0 ; V_50 -- )
for ( V_48 = 3 ; V_48 <= 1023 ; V_48 ++ ) {
V_45 = V_12 * V_48 / ( V_49 * ( 1 << V_50 ) ) ;
if ( V_45 > V_15 )
continue;
V_54 = V_15 - V_45 ;
if ( V_54 == 0 ) {
* V_43 = V_48 ;
* V_46 = V_49 ;
* V_47 = V_50 ;
return;
}
if ( V_54 < V_55 ) {
V_55 = V_54 ;
V_51 = V_48 ;
V_52 = V_49 ;
V_53 = V_50 ;
}
}
F_28 ( L_10 , V_18 , V_15 ,
V_15 - V_55 ) ;
* V_43 = V_48 ;
* V_46 = V_49 ;
* V_47 = V_50 ;
}
static int F_30 ( struct V_3 * V_4 , unsigned long V_15 ,
unsigned long V_12 )
{
struct V_56 * V_57 = F_31 ( V_4 ) ;
T_1 V_48 , V_49 , V_50 ;
T_1 V_58 ;
unsigned long V_8 = 0 ;
switch ( V_57 -> type ) {
case V_59 :
F_27 ( V_15 , V_12 , & V_48 , & V_49 ) ;
V_58 = F_32 ( V_48 , V_49 ) ;
break;
case V_60 :
F_29 ( V_15 , V_12 , & V_48 , & V_49 , & V_50 ) ;
V_58 = F_33 ( V_48 , V_49 , V_50 ) ;
break;
default:
F_15 ( L_11 , V_18 ) ;
return 0 ;
}
F_6 ( V_57 -> V_9 , V_8 ) ;
F_1 () ;
F_8 ( V_58 , V_57 -> V_61 ) ;
F_1 () ;
F_9 ( V_57 -> V_9 , V_8 ) ;
return 0 ;
}
static long F_34 ( struct V_3 * V_4 , unsigned long V_15 ,
unsigned long * V_16 )
{
struct V_56 * V_57 = F_31 ( V_4 ) ;
T_1 V_48 , V_49 , V_50 ;
long V_62 ;
switch ( V_57 -> type ) {
case V_59 :
F_27 ( V_15 , * V_16 , & V_48 , & V_49 ) ;
V_62 = F_35 ( * V_16 , V_48 , V_49 ) ;
break;
case V_60 :
F_29 ( V_15 , * V_16 , & V_48 , & V_49 , & V_50 ) ;
V_62 = F_36 ( * V_16 , V_48 , V_49 , V_50 ) ;
break;
default:
V_62 = 0 ;
}
return V_62 ;
}
static unsigned long F_37 ( struct V_3 * V_4 ,
unsigned long V_12 )
{
struct V_56 * V_57 = F_31 ( V_4 ) ;
T_1 V_58 = F_2 ( V_57 -> V_61 ) ;
unsigned long V_63 ;
switch ( V_57 -> type ) {
case V_59 :
V_63 = V_12 * F_38 ( V_58 ) ;
V_63 /= F_39 ( V_58 ) ;
break;
case V_60 :
V_63 = V_12 * F_40 ( V_58 ) ;
V_63 /= F_41 ( V_58 ) ;
break;
default:
V_63 = 0 ;
}
return V_63 ;
}
static T_2 void F_42 ( struct V_20 * V_21 , int V_64 )
{
T_1 V_61 ;
struct V_22 * V_22 ;
struct V_56 * V_65 ;
const char * V_24 = V_21 -> V_25 ;
const char * V_26 ;
struct V_27 V_28 ;
int V_29 ;
V_29 = F_19 ( V_21 , L_12 , & V_61 ) ;
if ( F_18 ( V_29 ) )
return;
V_65 = F_17 ( sizeof( * V_65 ) , V_31 ) ;
if ( F_18 ( ! V_65 ) )
return;
V_65 -> V_61 = V_1 + V_61 ;
V_65 -> V_9 = & V_32 ;
V_65 -> type = V_64 ;
F_20 ( V_21 , L_7 , & V_24 ) ;
V_28 . V_25 = V_24 ;
V_28 . V_35 = & V_66 ;
V_28 . V_8 = 0 ;
V_26 = F_22 ( V_21 , 0 ) ;
V_28 . V_40 = & V_26 ;
V_28 . V_41 = 1 ;
V_65 -> V_4 . V_28 = & V_28 ;
V_22 = F_23 ( NULL , & V_65 -> V_4 ) ;
if ( F_18 ( F_24 ( V_22 ) ) ) {
F_21 ( V_65 ) ;
return;
}
V_29 = F_25 ( V_21 , V_42 , V_22 ) ;
F_26 ( V_22 , V_24 , NULL ) ;
}
static void T_2 F_43 ( struct V_20 * V_21 )
{
F_42 ( V_21 , V_59 ) ;
}
static void T_2 F_44 ( struct V_20 * V_21 )
{
F_42 ( V_21 , V_60 ) ;
}
void T_2 F_45 ( void T_3 * V_67 )
{
if ( ! V_67 )
return;
V_1 = V_67 ;
F_46 ( V_68 ) ;
}
