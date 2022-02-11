static T_1 void F_1 ( void )
{
struct V_1 * V_2 =
F_2 ( NULL , NULL , L_1 ) ;
if ( V_2 )
V_3 = F_3 ( V_2 , 0 ) ;
else
V_3 = F_4 ( V_4 , 0x1000 ) ;
F_5 ( V_2 ) ;
if ( ! V_3 )
F_6 ( L_2 , V_5 ) ;
}
static void F_7 ( void )
{
while ( F_8 ( V_3 ) & V_6 )
F_9 () ;
}
static int F_10 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = F_11 ( V_8 ) ;
T_2 V_11 ;
unsigned long V_12 = 0 ;
F_12 ( V_10 -> V_13 , V_12 ) ;
V_11 = F_8 ( V_10 -> V_14 ) ;
V_11 |= F_13 ( V_10 -> V_15 ) ;
F_14 ( V_11 , V_10 -> V_14 ) ;
F_15 ( V_10 -> V_13 , V_12 ) ;
return 0 ;
}
static void F_16 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = F_11 ( V_8 ) ;
T_2 V_11 ;
unsigned long V_12 = 0 ;
F_12 ( V_10 -> V_13 , V_12 ) ;
V_11 = F_8 ( V_10 -> V_14 ) ;
V_11 &= ~ F_13 ( V_10 -> V_15 ) ;
F_14 ( V_11 , V_10 -> V_14 ) ;
F_15 ( V_10 -> V_13 , V_12 ) ;
}
static int F_17 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = F_11 ( V_8 ) ;
T_2 V_11 = ( F_8 ( V_10 -> V_14 ) & F_13 ( V_10 -> V_15 ) ) ;
return V_11 ? 1 : 0 ;
}
static unsigned long F_18 ( struct V_7 * V_8 ,
unsigned long V_16 )
{
struct V_9 * V_10 = F_11 ( V_8 ) ;
T_2 div = F_8 ( V_10 -> V_17 ) & V_10 -> V_18 ;
if ( ( V_10 -> V_18 == 0x3F ) && ( div & F_13 ( 5 ) ) )
div = 64 * ( div & 0x1f ) ;
if ( div == 0 )
div = ( V_10 -> V_18 + 1 ) ;
return V_16 / div ;
}
static long F_19 ( struct V_7 * V_8 , unsigned long V_19 ,
unsigned long * V_20 )
{
struct V_9 * V_10 = F_11 ( V_8 ) ;
T_2 V_21 ;
if ( V_19 == 0 )
return 0 ;
V_21 = * V_20 / V_19 ;
if ( V_19 * V_21 < * V_20 )
V_21 ++ ;
if ( ( V_10 -> V_18 == 0x3F ) && ( V_21 > 31 ) ) {
V_21 = 64 * ( ( V_21 / 64 ) + 1 ) ;
}
return * V_20 / V_21 ;
}
static int F_20 ( struct V_7 * V_8 , unsigned long V_19 ,
unsigned long V_16 )
{
struct V_9 * V_10 = F_11 ( V_8 ) ;
T_2 V_21 ;
unsigned long V_12 = 0 ;
if ( V_19 == 0 )
return 0 ;
V_21 = V_16 / V_19 ;
if ( V_21 == V_10 -> V_18 + 1 )
V_21 = 0 ;
if ( ( V_10 -> V_18 == 0x3F ) && ( V_21 > 31 ) ) {
V_21 = 0x20 + ( V_21 / 64 ) ;
}
if ( V_21 > V_10 -> V_18 ) {
F_6 ( L_3 , V_5 ) ;
return - V_22 ;
}
F_12 ( V_10 -> V_13 , V_12 ) ;
F_7 () ;
F_14 ( V_21 , V_10 -> V_17 ) ;
F_7 () ;
F_15 ( V_10 -> V_13 , V_12 ) ;
return 0 ;
}
static T_1 void F_21 ( struct V_1 * V_23 )
{
T_2 V_14 , V_17 ;
struct V_24 * V_24 ;
struct V_9 * V_25 ;
const char * V_26 = V_23 -> V_27 ;
const char * V_28 ;
struct V_29 V_30 ;
int V_31 ;
int V_32 = 0 ;
if ( ! V_3 )
F_1 () ;
V_25 = F_22 ( sizeof( * V_25 ) , V_33 ) ;
if ( F_23 ( ! V_25 ) )
return;
V_25 -> V_13 = & V_34 ;
V_31 = F_24 ( V_23 , L_4 , & V_14 ) ;
if ( ! V_31 ) {
V_25 -> V_14 = V_3 + V_14 ;
V_31 = F_24 ( V_23 , L_5 , & V_25 -> V_15 ) ;
if ( V_31 ) {
F_6 ( L_6 ,
V_5 ) ;
return;
}
V_32 |= V_35 ;
}
V_31 = F_24 ( V_23 , L_7 , & V_17 ) ;
if ( ! V_31 ) {
V_25 -> V_17 = V_3 + V_17 ;
V_25 -> V_18 = 0x1f ;
F_24 ( V_23 , L_8 , & V_25 -> V_18 ) ;
V_32 |= V_36 ;
}
F_25 ( V_23 , L_9 , & V_26 ) ;
switch ( V_32 ) {
case V_35 :
V_30 . V_37 = & V_38 ;
break;
case V_36 :
V_30 . V_37 = & V_39 ;
break;
case V_40 :
V_30 . V_37 = & V_41 ;
break;
default:
F_6 ( L_10 ,
V_5 ) ;
F_26 ( V_25 ) ;
return;
}
V_30 . V_27 = V_26 ;
V_30 . V_12 = 0 ;
V_28 = F_27 ( V_23 , 0 ) ;
V_30 . V_42 = & V_28 ;
V_30 . V_43 = 1 ;
V_25 -> V_8 . V_30 = & V_30 ;
V_24 = F_28 ( NULL , & V_25 -> V_8 ) ;
if ( F_23 ( F_29 ( V_24 ) ) ) {
F_26 ( V_25 ) ;
return;
}
V_31 = F_30 ( V_23 , V_44 , V_24 ) ;
F_31 ( V_24 , V_26 , NULL ) ;
}
static int F_32 ( unsigned long V_19 , unsigned long V_16 ,
T_2 * V_45 , T_2 * V_46 )
{
unsigned long V_47 ;
if ( ( V_19 < V_16 * 4 ) || ( V_19 > V_16 * 62 ) ) {
F_6 ( L_11 , V_5 ) ;
* V_45 = 0 ;
* V_46 = 1 ;
return - V_22 ;
}
if ( V_19 <= V_16 * 31 )
* V_46 = 2 ;
else
* V_46 = 1 ;
* V_45 = V_19 / ( V_16 / * V_46 ) ;
V_47 = ( V_16 / * V_46 ) * * V_45 ;
if ( V_47 != V_19 )
F_33 ( L_12 , V_5 ,
V_19 , V_47 ) ;
return 0 ;
}
static int F_34 ( unsigned long V_19 , unsigned long V_16 ,
T_2 * V_45 , T_2 * V_48 , T_2 * V_49 )
{
T_2 V_50 , V_51 ;
int V_52 ;
T_2 V_53 , V_54 , V_55 ;
unsigned long V_47 , V_56 , V_57 ;
V_57 = ( unsigned long ) - 1 ;
for ( V_51 = 5 ; V_51 >= 3 ; V_51 -- )
for ( V_52 = 3 ; V_52 >= 0 ; V_52 -- )
for ( V_50 = 3 ; V_50 <= 1023 ; V_50 ++ ) {
V_47 = V_16 * V_50 / ( V_51 * ( 1 << V_52 ) ) ;
if ( V_47 > V_19 )
continue;
V_56 = V_19 - V_47 ;
if ( V_56 == 0 ) {
* V_45 = V_50 ;
* V_48 = V_51 ;
* V_49 = V_52 ;
return 0 ;
}
if ( V_56 < V_57 ) {
V_57 = V_56 ;
V_53 = V_50 ;
V_54 = V_51 ;
V_55 = V_52 ;
}
}
if ( V_57 == ( unsigned long ) - 1 ) {
F_33 ( L_13 , V_5 , V_19 ) ;
return - V_22 ;
}
F_33 ( L_12 , V_5 , V_19 ,
V_19 - V_57 ) ;
* V_45 = V_53 ;
* V_48 = V_54 ;
* V_49 = V_55 ;
return 0 ;
}
static T_2 F_35 ( T_2 V_16 , T_2 V_48 )
{
T_2 V_58 = ( V_16 / 1000000 ) / ( V_48 + 1 ) ;
if ( ( V_58 < 10 ) || ( V_58 > 200 ) )
F_33 ( L_14 ,
V_5 , V_58 ) ;
if ( V_58 >= 166 )
return 7 ;
else if ( V_58 >= 104 )
return 6 ;
else if ( V_58 >= 65 )
return 5 ;
else if ( V_58 >= 42 )
return 4 ;
else if ( V_58 >= 26 )
return 3 ;
else if ( V_58 >= 16 )
return 2 ;
else if ( V_58 >= 10 )
return 1 ;
return 0 ;
}
static int F_36 ( unsigned long V_19 , unsigned long V_16 ,
T_2 * V_59 , T_2 * V_45 , T_2 * V_48 , T_2 * V_49 )
{
T_2 V_50 ;
int V_51 , V_52 ;
T_2 V_53 , V_54 , V_55 ;
unsigned long V_47 , V_56 , V_57 ;
V_57 = ( unsigned long ) - 1 ;
for ( V_51 = 1 ; V_51 >= 0 ; V_51 -- )
for ( V_52 = 7 ; V_52 >= 0 ; V_52 -- )
for ( V_50 = 0 ; V_50 <= 255 ; V_50 ++ ) {
V_47 = V_16 * ( V_50 + 1 ) / ( ( V_51 + 1 ) * ( 1 << V_52 ) ) ;
if ( V_47 > V_19 )
continue;
V_56 = V_19 - V_47 ;
if ( V_56 == 0 ) {
* V_59 = F_35 ( V_16 , V_51 ) ;
* V_45 = V_50 ;
* V_48 = V_51 ;
* V_49 = V_52 ;
return 0 ;
}
if ( V_56 < V_57 ) {
V_57 = V_56 ;
V_53 = V_50 ;
V_54 = V_51 ;
V_55 = V_52 ;
}
}
if ( V_57 == ( unsigned long ) - 1 ) {
F_33 ( L_13 , V_5 , V_19 ) ;
return - V_22 ;
}
F_33 ( L_12 , V_5 , V_19 ,
V_19 - V_57 ) ;
* V_59 = F_35 ( V_16 , V_54 ) ;
* V_45 = V_53 ;
* V_48 = V_54 ;
* V_49 = V_55 ;
return 0 ;
}
static int F_37 ( unsigned long V_19 , unsigned long V_16 ,
T_2 * V_45 , T_2 * V_48 , T_2 * V_49 )
{
T_2 V_50 ;
int V_51 , V_52 ;
T_2 V_53 , V_54 , V_55 ;
unsigned long V_47 , V_56 , V_57 ;
V_57 = ( unsigned long ) - 1 ;
for ( V_51 = 1 ; V_51 >= 0 ; V_51 -- )
for ( V_52 = 3 ; V_52 >= 0 ; V_52 -- )
for ( V_50 = 0 ; V_50 <= 127 ; V_50 ++ ) {
V_47 = V_16 * ( ( V_50 + 1 ) * 2 ) /
( ( V_51 + 1 ) * ( 1 << V_52 ) ) ;
if ( V_47 > V_19 )
continue;
V_56 = V_19 - V_47 ;
if ( V_56 == 0 ) {
* V_45 = V_50 ;
* V_48 = V_51 ;
* V_49 = V_52 ;
return 0 ;
}
if ( V_56 < V_57 ) {
V_57 = V_56 ;
V_53 = V_50 ;
V_54 = V_51 ;
V_55 = V_52 ;
}
}
if ( V_57 == ( unsigned long ) - 1 ) {
F_33 ( L_13 , V_5 , V_19 ) ;
return - V_22 ;
}
F_33 ( L_12 , V_5 , V_19 ,
V_19 - V_57 ) ;
* V_45 = V_53 ;
* V_48 = V_54 ;
* V_49 = V_55 ;
return 0 ;
}
static int F_38 ( struct V_7 * V_8 , unsigned long V_19 ,
unsigned long V_16 )
{
struct V_60 * V_61 = F_39 ( V_8 ) ;
T_2 V_59 , V_50 , V_51 , V_52 ;
T_2 V_62 ;
unsigned long V_12 = 0 ;
int V_63 ;
switch ( V_61 -> type ) {
case V_64 :
V_63 = F_32 ( V_19 , V_16 , & V_50 , & V_51 ) ;
if ( ! V_63 )
V_62 = F_40 ( V_50 , V_51 ) ;
break;
case V_65 :
V_63 = F_34 ( V_19 , V_16 , & V_50 , & V_51 , & V_52 ) ;
if ( ! V_63 )
V_62 = F_41 ( V_50 , V_51 , V_52 ) ;
break;
case V_66 :
V_63 = F_36 ( V_19 , V_16 , & V_59 , & V_50 , & V_51 , & V_52 ) ;
if ( ! V_63 )
V_62 = F_42 ( V_59 , V_50 , V_51 , V_52 ) ;
break;
case V_67 :
V_63 = F_37 ( V_19 , V_16 , & V_50 , & V_51 , & V_52 ) ;
if ( ! V_63 )
V_62 = F_43 ( V_50 , V_51 , V_52 ) ;
break;
default:
F_6 ( L_15 , V_5 ) ;
V_63 = - V_22 ;
}
if ( V_63 )
return V_63 ;
F_12 ( V_61 -> V_13 , V_12 ) ;
F_7 () ;
F_14 ( V_62 , V_61 -> V_68 ) ;
F_7 () ;
F_15 ( V_61 -> V_13 , V_12 ) ;
return 0 ;
}
static long F_44 ( struct V_7 * V_8 , unsigned long V_19 ,
unsigned long * V_20 )
{
struct V_60 * V_61 = F_39 ( V_8 ) ;
T_2 V_59 , V_50 , V_51 , V_52 ;
long V_69 ;
int V_63 ;
switch ( V_61 -> type ) {
case V_64 :
V_63 = F_32 ( V_19 , * V_20 , & V_50 , & V_51 ) ;
if ( ! V_63 )
V_69 = F_45 ( * V_20 , V_50 , V_51 ) ;
break;
case V_65 :
V_63 = F_34 ( V_19 , * V_20 , & V_50 , & V_51 , & V_52 ) ;
if ( ! V_63 )
V_69 = F_46 ( * V_20 , V_50 , V_51 , V_52 ) ;
break;
case V_66 :
V_63 = F_36 ( V_19 , * V_20 , & V_59 , & V_50 , & V_51 , & V_52 ) ;
if ( ! V_63 )
V_69 = F_47 ( * V_20 , V_50 , V_51 , V_52 ) ;
break;
case V_67 :
V_63 = F_37 ( V_19 , * V_20 , & V_50 , & V_51 , & V_52 ) ;
if ( ! V_63 )
V_69 = F_48 ( * V_20 , V_50 , V_51 , V_52 ) ;
break;
default:
V_63 = - V_22 ;
}
if ( V_63 )
return V_63 ;
return V_69 ;
}
static unsigned long F_49 ( struct V_7 * V_8 ,
unsigned long V_16 )
{
struct V_60 * V_61 = F_39 ( V_8 ) ;
T_2 V_62 = F_8 ( V_61 -> V_68 ) ;
unsigned long V_70 ;
switch ( V_61 -> type ) {
case V_64 :
V_70 = V_16 * F_50 ( V_62 ) ;
V_70 /= F_51 ( V_62 ) ;
break;
case V_65 :
V_70 = V_16 * F_52 ( V_62 ) ;
V_70 /= F_53 ( V_62 ) ;
break;
case V_66 :
V_70 = V_16 * F_54 ( V_62 ) ;
V_70 /= F_55 ( V_62 ) ;
break;
case V_67 :
V_70 = V_16 * F_56 ( V_62 ) ;
V_70 /= F_57 ( V_62 ) ;
break;
default:
V_70 = 0 ;
}
return V_70 ;
}
static T_1 void F_58 ( struct V_1 * V_23 , int V_71 )
{
T_2 V_68 ;
struct V_24 * V_24 ;
struct V_60 * V_72 ;
const char * V_26 = V_23 -> V_27 ;
const char * V_28 ;
struct V_29 V_30 ;
int V_31 ;
if ( ! V_3 )
F_1 () ;
V_31 = F_24 ( V_23 , L_16 , & V_68 ) ;
if ( F_23 ( V_31 ) )
return;
V_72 = F_22 ( sizeof( * V_72 ) , V_33 ) ;
if ( F_23 ( ! V_72 ) )
return;
V_72 -> V_68 = V_3 + V_68 ;
V_72 -> V_13 = & V_34 ;
V_72 -> type = V_71 ;
F_25 ( V_23 , L_9 , & V_26 ) ;
V_30 . V_27 = V_26 ;
V_30 . V_37 = & V_73 ;
V_30 . V_12 = 0 ;
V_28 = F_27 ( V_23 , 0 ) ;
V_30 . V_42 = & V_28 ;
V_30 . V_43 = 1 ;
V_72 -> V_8 . V_30 = & V_30 ;
V_24 = F_28 ( NULL , & V_72 -> V_8 ) ;
if ( F_23 ( F_29 ( V_24 ) ) ) {
F_26 ( V_72 ) ;
return;
}
V_31 = F_30 ( V_23 , V_44 , V_24 ) ;
F_31 ( V_24 , V_26 , NULL ) ;
}
static void T_1 F_59 ( struct V_1 * V_23 )
{
F_58 ( V_23 , V_64 ) ;
}
static void T_1 F_60 ( struct V_1 * V_23 )
{
F_58 ( V_23 , V_65 ) ;
}
static void T_1 F_61 ( struct V_1 * V_23 )
{
F_58 ( V_23 , V_66 ) ;
}
static void T_1 F_62 ( struct V_1 * V_23 )
{
F_58 ( V_23 , V_67 ) ;
}
