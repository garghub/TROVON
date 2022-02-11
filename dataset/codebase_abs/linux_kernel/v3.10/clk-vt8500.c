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
T_1 V_17 ;
if ( V_15 == 0 )
return 0 ;
V_17 = * V_16 / V_15 ;
if ( V_15 * V_17 < * V_16 )
V_17 ++ ;
if ( ( V_6 -> V_14 == 0x3F ) && ( V_17 > 31 ) ) {
V_17 = 64 * ( ( V_17 / 64 ) + 1 ) ;
}
return * V_16 / V_17 ;
}
static int F_14 ( struct V_3 * V_4 , unsigned long V_15 ,
unsigned long V_12 )
{
struct V_5 * V_6 = F_5 ( V_4 ) ;
T_1 V_17 ;
unsigned long V_8 = 0 ;
if ( V_15 == 0 )
return 0 ;
V_17 = V_12 / V_15 ;
if ( V_15 * V_17 < V_12 )
V_17 ++ ;
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
F_9 ( V_6 -> V_9 , V_8 ) ;
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
* V_43 = V_51 ;
* V_46 = V_52 ;
* V_47 = V_53 ;
}
static T_1 F_30 ( T_1 V_12 , T_1 V_46 )
{
T_1 V_56 = ( V_12 / 1000000 ) / ( V_46 + 1 ) ;
if ( ( V_56 < 10 ) || ( V_56 > 200 ) )
F_28 ( L_11 ,
V_18 , V_56 ) ;
if ( V_56 >= 166 )
return 7 ;
else if ( V_56 >= 104 )
return 6 ;
else if ( V_56 >= 65 )
return 5 ;
else if ( V_56 >= 42 )
return 4 ;
else if ( V_56 >= 26 )
return 3 ;
else if ( V_56 >= 16 )
return 2 ;
else if ( V_56 >= 10 )
return 1 ;
return 0 ;
}
static void F_31 ( unsigned long V_15 , unsigned long V_12 ,
T_1 * V_57 , T_1 * V_43 , T_1 * V_46 , T_1 * V_47 )
{
T_1 V_48 , V_49 , V_50 ;
T_1 V_51 , V_52 , V_53 ;
unsigned long V_45 , V_54 , V_55 ;
V_55 = ( unsigned long ) - 1 ;
for ( V_49 = 1 ; V_49 >= 0 ; V_49 -- )
for ( V_50 = 7 ; V_50 >= 0 ; V_50 -- )
for ( V_48 = 0 ; V_48 <= 255 ; V_48 ++ ) {
V_45 = V_12 * ( V_48 + 1 ) / ( ( V_49 + 1 ) * ( 1 << V_50 ) ) ;
if ( V_45 > V_15 )
continue;
V_54 = V_15 - V_45 ;
if ( V_54 == 0 ) {
* V_57 = F_30 ( V_12 , V_49 ) ;
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
* V_57 = F_30 ( V_12 , V_52 ) ;
* V_43 = V_51 ;
* V_46 = V_52 ;
* V_47 = V_53 ;
}
static int F_32 ( struct V_3 * V_4 , unsigned long V_15 ,
unsigned long V_12 )
{
struct V_58 * V_59 = F_33 ( V_4 ) ;
T_1 V_57 , V_48 , V_49 , V_50 ;
T_1 V_60 ;
unsigned long V_8 = 0 ;
switch ( V_59 -> type ) {
case V_61 :
F_27 ( V_15 , V_12 , & V_48 , & V_49 ) ;
V_60 = F_34 ( V_48 , V_49 ) ;
break;
case V_62 :
F_29 ( V_15 , V_12 , & V_48 , & V_49 , & V_50 ) ;
V_60 = F_35 ( V_48 , V_49 , V_50 ) ;
break;
case V_63 :
F_31 ( V_15 , V_12 , & V_57 , & V_48 , & V_49 , & V_50 ) ;
V_60 = F_36 ( V_57 , V_48 , V_49 , V_50 ) ;
break;
default:
F_15 ( L_12 , V_18 ) ;
return 0 ;
}
F_6 ( V_59 -> V_9 , V_8 ) ;
F_1 () ;
F_8 ( V_60 , V_59 -> V_64 ) ;
F_1 () ;
F_9 ( V_59 -> V_9 , V_8 ) ;
return 0 ;
}
static long F_37 ( struct V_3 * V_4 , unsigned long V_15 ,
unsigned long * V_16 )
{
struct V_58 * V_59 = F_33 ( V_4 ) ;
T_1 V_57 , V_48 , V_49 , V_50 ;
long V_65 ;
switch ( V_59 -> type ) {
case V_61 :
F_27 ( V_15 , * V_16 , & V_48 , & V_49 ) ;
V_65 = F_38 ( * V_16 , V_48 , V_49 ) ;
break;
case V_62 :
F_29 ( V_15 , * V_16 , & V_48 , & V_49 , & V_50 ) ;
V_65 = F_39 ( * V_16 , V_48 , V_49 , V_50 ) ;
break;
case V_63 :
F_31 ( V_15 , * V_16 , & V_57 , & V_48 , & V_49 , & V_50 ) ;
V_65 = F_40 ( * V_16 , V_48 , V_49 , V_50 ) ;
break;
default:
V_65 = 0 ;
}
return V_65 ;
}
static unsigned long F_41 ( struct V_3 * V_4 ,
unsigned long V_12 )
{
struct V_58 * V_59 = F_33 ( V_4 ) ;
T_1 V_60 = F_2 ( V_59 -> V_64 ) ;
unsigned long V_66 ;
switch ( V_59 -> type ) {
case V_61 :
V_66 = V_12 * F_42 ( V_60 ) ;
V_66 /= F_43 ( V_60 ) ;
break;
case V_62 :
V_66 = V_12 * F_44 ( V_60 ) ;
V_66 /= F_45 ( V_60 ) ;
break;
case V_63 :
V_66 = V_12 * F_46 ( V_60 ) ;
V_66 /= F_47 ( V_60 ) ;
break;
default:
V_66 = 0 ;
}
return V_66 ;
}
static T_2 void F_48 ( struct V_20 * V_21 , int V_67 )
{
T_1 V_64 ;
struct V_22 * V_22 ;
struct V_58 * V_68 ;
const char * V_24 = V_21 -> V_25 ;
const char * V_26 ;
struct V_27 V_28 ;
int V_29 ;
V_29 = F_19 ( V_21 , L_13 , & V_64 ) ;
if ( F_18 ( V_29 ) )
return;
V_68 = F_17 ( sizeof( * V_68 ) , V_31 ) ;
if ( F_18 ( ! V_68 ) )
return;
V_68 -> V_64 = V_1 + V_64 ;
V_68 -> V_9 = & V_32 ;
V_68 -> type = V_67 ;
F_20 ( V_21 , L_7 , & V_24 ) ;
V_28 . V_25 = V_24 ;
V_28 . V_35 = & V_69 ;
V_28 . V_8 = 0 ;
V_26 = F_22 ( V_21 , 0 ) ;
V_28 . V_40 = & V_26 ;
V_28 . V_41 = 1 ;
V_68 -> V_4 . V_28 = & V_28 ;
V_22 = F_23 ( NULL , & V_68 -> V_4 ) ;
if ( F_18 ( F_24 ( V_22 ) ) ) {
F_21 ( V_68 ) ;
return;
}
V_29 = F_25 ( V_21 , V_42 , V_22 ) ;
F_26 ( V_22 , V_24 , NULL ) ;
}
static void T_2 F_49 ( struct V_20 * V_21 )
{
F_48 ( V_21 , V_61 ) ;
}
static void T_2 F_50 ( struct V_20 * V_21 )
{
F_48 ( V_21 , V_62 ) ;
}
static void T_2 F_51 ( struct V_20 * V_21 )
{
F_48 ( V_21 , V_63 ) ;
}
void T_2 F_52 ( void T_3 * V_70 )
{
if ( ! V_70 )
return;
V_1 = V_70 ;
F_53 ( NULL ) ;
}
